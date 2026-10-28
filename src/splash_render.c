// Low-level GSKit splash renderer, frame lifecycle, and draw primitives.
#include <malloc.h>
#include <stdlib.h>
#include <string.h>

#include <dmaKit.h>
#include <gsKit.h>

#include "loader_video.h"
#include "splash_assets.h"
#include "splash_render.h"
#include "splash_screen.h"

u64 Timer(void); // timer.c

#define FONT_W 5
#define FONT_H 7
#define FONT_SCALE 2
#define FONT_ADVANCE ((FONT_W + 1) * FONT_SCALE)
#define TEXT_Z 10
#define TEXT_SHADOW_Z (TEXT_Z - 1)
#define OVERLAY_RECT_Z (TEXT_Z - 2)
#define BG_Z 1
#define FG_Z 2
#define GS_ALPHA_OPAQUE 0x80
#define LOGO_TRANSPARENCY_PERCENT_DEFAULT 0
#define LOGO_TRANSPARENCY_PERCENT_WITH_HOTKEYS 80
#define LOGO_SHIMMER_ENABLED 1
#define LOGO_SHIMMER_WIDTH_PERCENT 12
#define LOGO_SHIMMER_MIN_WIDTH_PX 8
#define LOGO_SHIMMER_SPEED_PX_PER_FRAME 1
#define LOGO_SHIMMER_EDGE_INSET_PERCENT 25
#define LOGO_SHIMMER_EDGE_INSET_MIN_PX 4
#define LOGO_SHIMMER_SLICE_COUNT 18
#define LOGO_SHIMMER_HIGHLIGHT_OPACITY_PERCENT 5
#define LOGO_SHIMMER_HALO_OPACITY_PERCENT 3
#define LOGO_SHIMMER_DISTORT_OPACITY_PERCENT 16
#define LOGO_SHIMMER_DISTORT_MAX_SHIFT_PX 16
#define GLYPH_SHADOW_TRANSPARENCY_PERCENT 40
#define GLYPH_SHADOW_OFFSET_X 1
#define GLYPH_SHADOW_OFFSET_Y 1

// LOGO_DISPLAY = 2 centered logo fine tuning.
#define MODE2_LOGO_X_FROM_CENTER 0
#define MODE2_LOGO_Y_FROM_CENTER 0

// LOGO_DISPLAY = 3 layout:
// - Logo geometrically centered on screen.
// - Hotkeys image left aligned and vertically centered on screen.
// Logo Y and hotkeys Y values are center-relative tuning offsets in pixels.
#define MODE35_HOTKEYS_LEFT_PERCENT 10
#define MODE35_LOGO_X_FROM_CENTER 0
#define MODE35_LOGO_Y_FROM_CENTER 0
#define MODE35_HOTKEYS_X_ADJUST 0
#define MODE35_HOTKEYS_Y_FROM_CENTER 0

typedef struct
{
    char ch;
    unsigned char rows[FONT_H];
} GLYPH;

typedef struct
{
    GSTEXTURE tex;
    int ready;
} SPLASH_LAYER;

enum
{
    LAYER_BG = 0,
    LAYER_LOGO,
    LAYER_HOTKEYS,
    LAYER_COUNT
};

enum {
    SPLASH_CFG_VIDEO_MODE_AUTO = 0,
    SPLASH_CFG_VIDEO_MODE_NTSC,
    SPLASH_CFG_VIDEO_MODE_PAL,
    SPLASH_CFG_VIDEO_MODE_480P,
    SPLASH_CFG_VIDEO_MODE_576P,
    SPLASH_CFG_VIDEO_MODE_720P,
    SPLASH_CFG_VIDEO_MODE_1080I
};

static GSGLOBAL *g_gs = NULL;
static SPLASH_LAYER g_layers[LAYER_COUNT];
static int g_screen_w = 0;
static int g_screen_h = 0;
static int g_logo_x = -1;
static int g_logo_y = -1;
static int g_logo_visible = 0;
static int g_hotkeys_x = -1;
static int g_hotkeys_y = -1;
static int g_hotkeys_visible = 0;
// BIBLE: the splash in RIPPS2's look (LOGO_DISPLAY 2 and up): RIPPS2's sky in place of the picture, the PS2 logo in
// the middle of the screen whatever else shows, and under it the controller's buttons from hotkeys.png at their own
// size (as OPL draws its button hints). BIBLE_GLYPHS 1: the four face buttons; 2: all sixteen in two rows of eight
// (the face buttons, L1 R1 START SELECT; L2 R2 L3 R3, up down left right); 0: the logo alone. Text goes ABOVE the logo:
// the info line nearest it, prompts, status lines and pages above that. The sheet holds each button as an icon 21
// wide at x 6, at the rows below.
#define BIBLE_GLYPH_SRC_X 6
#define BIBLE_GLYPH_SRC_W 21
#define BIBLE_GLYPH_CELL 21 // the sheet's own size
#define BIBLE_GLYPH_GAP 9   // between two buttons of a row
#define BIBLE_GLYPH_ROW_GAP 8
#define BIBLE_GLYPH_BELOW 20 // from the logo to the first row
#define BIBLE_TEXT_PAD 18    // from the logo up to the nearest text
#define BIBLE_TEXT_GAP 12    // from the info line up to a prompt or page above it
#define BIBLE_TEXT_H 7       // one line of the 5x7 font
enum {
    GLY_TRIANGLE = 0, GLY_CIRCLE, GLY_CROSS, GLY_SQUARE, GLY_UP, GLY_DOWN, GLY_LEFT, GLY_RIGHT,
    GLY_L1, GLY_L2, GLY_L3, GLY_R1, GLY_R2, GLY_R3, GLY_SELECT, GLY_START, GLY_COUNT
};
static const unsigned short g_glyph_src[GLY_COUNT][2] = { // each icon's first row in hotkeys.png, and its height
    {22, 20}, {43, 20}, {64, 20}, {85, 20}, {106, 20}, {127, 20}, {148, 20}, {169, 20},
    {191, 17}, {211, 20}, {232, 20}, {254, 17}, {274, 20}, {295, 20}, {319, 16}, {337, 19}};
static const unsigned char g_glyph_rows[2][8] = {
    {GLY_TRIANGLE, GLY_CIRCLE, GLY_CROSS, GLY_SQUARE, GLY_L1, GLY_R1, GLY_START, GLY_SELECT},
    {GLY_L2, GLY_R2, GLY_L3, GLY_R3, GLY_UP, GLY_DOWN, GLY_LEFT, GLY_RIGHT}};
static int g_bible_glyphs = 1;
static int g_glyphs_x = -1;
static int g_glyphs_y = -1;
static int g_glyphs_rows = 0; // the rows drawn: 0, 1 (the face buttons) or 2 (all)
static int g_glyphs_cols = 4; // buttons to a row: 4 (the face buttons) or 8
static int g_bible_layout = 0; // LOGO_DISPLAY 2: the logo in the middle, text above it, the buttons below
// BIBLE: a page (the video mode selector, credits, the launch keys page) dims the logo, puts the buttons away and
// fades its box and text in over BIBLE_PAGE_FADE_MS, so the launch keys plainly rest while it shows
#define BIBLE_PAGE_FADE_MS 350
#define BIBLE_PAGE_LOGO_TRANSPARENCY 80
#define BIBLE_PAGE_BOX_COLOR 0x606060
#define BIBLE_PAGE_BOX_OPACITY 80
static int g_page_on = 0;
static int g_page_sheet = 0; // the launch keys page shows upstream's button sheet
static u64 g_page_t0 = 0;
static int g_glyphs_covered = 0; // this frame put text or a box where the rows sit: the page shows the logo alone
// BIBLE_COLOR: the sky's top, horizon and floor (0xRRGGBB) as RIPPS2's Storage page draws them at rest, the horizon
// 290/480 of the way down. RIPPS2 writes its Color Theme's (or a Color Sweep's first colour's) into the config.
#define BIBLE_SKY_HORIZON(h) ((h) * 290 / 480)
static unsigned int g_sky[3] = {0x010209, 0x0B194C, 0x020410};
static int g_sky_on = 0;
static int g_logo_shimmer_left = 0;
static int g_logo_shimmer_band_width = 0;
static int g_logo_shimmer_visible_left = 0;
static int g_logo_shimmer_visible_right = 0;
static int g_video_cfg_mode = SPLASH_CFG_VIDEO_MODE_AUTO;
static int g_video_native_mode = SPLASH_CFG_VIDEO_MODE_NTSC;
static int g_wide = 0;   // BIBLE: Widescreen in the 4:3 modes, for a TV that stretches the picture to 16:9
static int g_fade = 100; // BIBLE: the logo's, the buttons' and the sheet's opacity (percent), as the hand-off fades them
// BIBLE: the layout's size (g_screen_w by g_screen_h are these once the splash begins) and its scale to the framebuffer
static int g_virt_w = 640;
static int g_virt_h = 448;
static float g_sx = 1.0f;
static float g_sy = 1.0f;

// BIBLE: every primitive is drawn in the layout's pixels and lands in the framebuffer's through these
static void prim_sprite(float x0, float y0, float x1, float y1, int z, u64 color)
{
    gsKit_prim_sprite(g_gs, x0 * g_sx, y0 * g_sy, x1 * g_sx, y1 * g_sy, z, color);
}

static void prim_sprite_texture(GSTEXTURE *tex, float x0, float y0, float u0, float v0, float x1, float y1, float u1,
                                float v1, int z, u64 color)
{
    gsKit_prim_sprite_texture(g_gs, tex, x0 * g_sx, y0 * g_sy, u0, v0, x1 * g_sx, y1 * g_sy, u1, v1, z, color);
}

static void prim_quad_gouraud(float x0, float y0, float x1, float y1, float x2, float y2, float x3, float y3, int z,
                              u64 c0, u64 c1, u64 c2, u64 c3)
{
    gsKit_prim_quad_gouraud(g_gs, x0 * g_sx, y0 * g_sy, x1 * g_sx, y1 * g_sy, x2 * g_sx, y2 * g_sy, x3 * g_sx, y3 * g_sy,
                            z, c0, c1, c2, c3);
}

static int resolve_video_mode_for_splash(void)
{
    if (g_video_cfg_mode == SPLASH_CFG_VIDEO_MODE_AUTO) { // BIBLE: RIPPS2's mode when its settings were read
        int mode = LoaderResolveEffectiveVideoMode(SPLASH_CFG_VIDEO_MODE_AUTO);

        return mode > SPLASH_CFG_VIDEO_MODE_AUTO ? mode : g_video_native_mode;
    }
    return g_video_cfg_mode;
}

// BIBLE: each mode's framebuffer, and the layout's size in it. The splash lays out in its own pixels (g_screen_w by
// g_screen_h) and prim_* scale them by g_sx, g_sy to the framebuffer's. 4:3: 640 wide, 1:1. Widescreen in 480i and
// 576i: 832 wide, the GS spending three clocks on a pixel in place of four, so the same signal carries a third more of
// them and a TV that stretches the picture to 16:9 shows each the shape it has in 4:3: 1:1 again, and crisp. 480p and
// 576p have no such step: 1280 wide under a layout 853 wide. 720p (1280 x 720) and 1080i (960 x 540 a field, as RIPPS2
// draws it) are 16:9 by themselves: a layout of 853 x 448, NTSC's height, so the splash keeps its size on the screen.
// A framebuffer over 832 wide is 16-bit and dithered, as RIPPS2's HD ones are, so two fit in the GS's 4 MB with the
// textures.
static void configure_gskit_video_mode(GSGLOBAL *gs)
{
    int mode;
    int hd;

    if (gs == NULL)
        return;

    mode = resolve_video_mode_for_splash();
    hd = (mode == SPLASH_CFG_VIDEO_MODE_720P || mode == SPLASH_CFG_VIDEO_MODE_1080I);
    switch (mode) {
        case SPLASH_CFG_VIDEO_MODE_PAL:
            gs->Mode = GS_MODE_PAL;
            gs->Interlace = GS_INTERLACED;
            gs->Field = GS_FIELD;
            gs->Width = g_wide ? 832 : 640;
            gs->Height = 512;
            break;
        case SPLASH_CFG_VIDEO_MODE_480P:
        case SPLASH_CFG_VIDEO_MODE_576P:
            gs->Mode = mode == SPLASH_CFG_VIDEO_MODE_480P ? GS_MODE_DTV_480P : GS_MODE_DTV_576P;
            gs->Interlace = GS_NONINTERLACED;
            gs->Field = GS_FRAME;
            gs->Width = g_wide ? 1280 : 640;
            gs->Height = mode == SPLASH_CFG_VIDEO_MODE_480P ? 448 : 512;
            break;
        case SPLASH_CFG_VIDEO_MODE_720P:
            gs->Mode = GS_MODE_DTV_720P;
            gs->Interlace = GS_NONINTERLACED;
            gs->Field = GS_FRAME;
            gs->Width = 1280;
            gs->Height = 720;
            break;
        case SPLASH_CFG_VIDEO_MODE_1080I:
            gs->Mode = GS_MODE_DTV_1080I;
            gs->Interlace = GS_INTERLACED;
            gs->Field = GS_FRAME;
            gs->Width = 960;
            gs->Height = 540;
            break;
        case SPLASH_CFG_VIDEO_MODE_NTSC:
        default:
            gs->Mode = GS_MODE_NTSC;
            gs->Interlace = GS_INTERLACED;
            gs->Field = GS_FIELD;
            gs->Width = g_wide ? 832 : 640;
            gs->Height = 448;
            break;
    }
    g_virt_w = (int)gs->Width > 832 ? 853 : (int)gs->Width;
    g_virt_h = hd ? 448 : (int)gs->Height;
    if ((int)gs->Width > 832) {
        gs->PSM = GS_PSM_CT16S;
        gs->Dithering = GS_SETTING_ON;
    }
}

void SplashRenderSetVideoMode(int cfg_mode, int native_mode)
{
    if (native_mode != SPLASH_CFG_VIDEO_MODE_PAL)
        native_mode = SPLASH_CFG_VIDEO_MODE_NTSC;
    g_video_native_mode = native_mode;

    if (cfg_mode < SPLASH_CFG_VIDEO_MODE_AUTO || cfg_mode > SPLASH_CFG_VIDEO_MODE_1080I)
        cfg_mode = SPLASH_CFG_VIDEO_MODE_AUTO;
    g_video_cfg_mode = cfg_mode;
}

static unsigned char transparency_percent_to_gs_alpha(unsigned int transparency_percent)
{
    unsigned int opacity_percent;

    if (transparency_percent > 100u)
        transparency_percent = 100u;

    opacity_percent = 100u - transparency_percent;
    return (unsigned char)((opacity_percent * GS_ALPHA_OPAQUE + 50u) / 100u);
}

static unsigned char opacity_percent_to_gs_alpha(unsigned int opacity_percent)
{
    if (opacity_percent > 100u)
        opacity_percent = 100u;

    return (unsigned char)((opacity_percent * GS_ALPHA_OPAQUE + 50u) / 100u);
}

static int page_fade(void);

static unsigned char get_logo_base_alpha(void)
{
    unsigned int logo_transparency_percent = g_hotkeys_visible
                                                 ? LOGO_TRANSPARENCY_PERCENT_WITH_HOTKEYS
                                                 : LOGO_TRANSPARENCY_PERCENT_DEFAULT;

    if (g_page_on) // BIBLE: from the splash's own alpha down to the page's dim one
        logo_transparency_percent = LOGO_TRANSPARENCY_PERCENT_DEFAULT +
                                    (BIBLE_PAGE_LOGO_TRANSPARENCY - LOGO_TRANSPARENCY_PERCENT_DEFAULT) * page_fade() / 100;
    return (unsigned char)(transparency_percent_to_gs_alpha(logo_transparency_percent) * g_fade / 100);
}

static int compute_logo_shimmer_band_width(int logo_width)
{
    int band_width;

    if (logo_width <= 0)
        return 0;

    band_width = ((logo_width * LOGO_SHIMMER_WIDTH_PERCENT) + 50) / 100;
    if (band_width < LOGO_SHIMMER_MIN_WIDTH_PX)
        band_width = LOGO_SHIMMER_MIN_WIDTH_PX;
    if (band_width > logo_width)
        band_width = logo_width;

    return band_width;
}

static void compute_logo_visible_bounds_from_image(const SPLASH_IMAGE *logo_image,
                                                   int *visible_left,
                                                   int *visible_right)
{
    int min_x;
    int max_x;
    unsigned int y;
    unsigned int x;

    if (visible_left == NULL || visible_right == NULL)
        return;

    *visible_left = 0;
    *visible_right = 0;
    if (logo_image == NULL || logo_image->pixels_rbga == NULL || logo_image->width == 0 || logo_image->height == 0)
        return;

    min_x = (int)logo_image->width;
    max_x = -1;
    for (y = 0; y < logo_image->height; y++) {
        size_t row_base = ((size_t)y * (size_t)logo_image->width * 4u);
        for (x = 0; x < logo_image->width; x++) {
            size_t pixel_index = row_base + ((size_t)x * 4u);
            if (logo_image->pixels_rbga[pixel_index + 3] == 0)
                continue;

            if ((int)x < min_x)
                min_x = (int)x;
            if ((int)x > max_x)
                max_x = (int)x;
        }
    }

    if (max_x < min_x) {
        *visible_left = 0;
        *visible_right = (int)logo_image->width;
        return;
    }

    *visible_left = min_x;
    *visible_right = max_x + 1;
}

static void get_logo_shimmer_sweep_bounds(const SPLASH_LAYER *logo,
                                          int *shimmer_min_left,
                                          int *shimmer_max_left)
{
    int visible_left;
    int visible_right;
    int logo_width;
    int edge_inset;

    if (shimmer_min_left == NULL || shimmer_max_left == NULL)
        return;

    *shimmer_min_left = 0;
    *shimmer_max_left = 0;
    if (logo == NULL || logo->tex.Width == 0 || g_logo_shimmer_band_width <= 0)
        return;

    logo_width = (int)logo->tex.Width;
    visible_left = g_logo_shimmer_visible_left;
    visible_right = g_logo_shimmer_visible_right;
    if (visible_left < 0)
        visible_left = 0;
    if (visible_right <= visible_left || visible_right > logo_width) {
        visible_left = 0;
        visible_right = logo_width;
    }

    edge_inset = ((g_logo_shimmer_band_width * LOGO_SHIMMER_EDGE_INSET_PERCENT) + 50) / 100;
    if (edge_inset < LOGO_SHIMMER_EDGE_INSET_MIN_PX)
        edge_inset = LOGO_SHIMMER_EDGE_INSET_MIN_PX;
    if (edge_inset > g_logo_shimmer_band_width)
        edge_inset = g_logo_shimmer_band_width;

    *shimmer_min_left = visible_left - g_logo_shimmer_band_width + edge_inset;
    *shimmer_max_left = visible_right + g_logo_shimmer_band_width - edge_inset;
    if (*shimmer_max_left < *shimmer_min_left)
        *shimmer_max_left = *shimmer_min_left;
}

static void reset_logo_shimmer_state(void)
{
    g_logo_shimmer_band_width = 0;
    g_logo_shimmer_left = 0;
    g_logo_shimmer_visible_left = 0;
    g_logo_shimmer_visible_right = 0;
}

static void init_logo_shimmer_state(void)
{
    const SPLASH_LAYER *logo = &g_layers[LAYER_LOGO];
    int shimmer_min_left;
    int shimmer_max_left;

    if (!logo->ready || logo->tex.Width <= 0) {
        reset_logo_shimmer_state();
        return;
    }

    g_logo_shimmer_band_width = compute_logo_shimmer_band_width((int)logo->tex.Width);
    get_logo_shimmer_sweep_bounds(logo, &shimmer_min_left, &shimmer_max_left);
    g_logo_shimmer_left = shimmer_min_left;
    (void)shimmer_max_left;
}

// 5x7 glyphs for splash labels.
static const GLYPH g_font[] = {
    {' ', {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}},
    {'!', {0x04, 0x04, 0x04, 0x04, 0x04, 0x00, 0x04}},
    {'\"', {0x0A, 0x0A, 0x0A, 0x00, 0x00, 0x00, 0x00}},
    {'#', {0x0A, 0x0A, 0x1F, 0x0A, 0x1F, 0x0A, 0x0A}},
    {'$', {0x04, 0x0F, 0x14, 0x0E, 0x05, 0x1E, 0x04}},
    {'%', {0x18, 0x19, 0x02, 0x04, 0x08, 0x13, 0x03}},
    {'&', {0x0C, 0x12, 0x14, 0x08, 0x15, 0x12, 0x0D}},
    {'\'', {0x06, 0x06, 0x04, 0x00, 0x00, 0x00, 0x00}},
    {'(', {0x02, 0x04, 0x08, 0x08, 0x08, 0x04, 0x02}},
    {')', {0x08, 0x04, 0x02, 0x02, 0x02, 0x04, 0x08}},
    {'*', {0x00, 0x04, 0x15, 0x0E, 0x15, 0x04, 0x00}},
    {'+', {0x00, 0x04, 0x04, 0x1F, 0x04, 0x04, 0x00}},
    {',', {0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x04}},
    {'-', {0x00, 0x00, 0x00, 0x1F, 0x00, 0x00, 0x00}},
    {'.', {0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x06}},
    {':', {0x00, 0x06, 0x06, 0x00, 0x06, 0x06, 0x00}},
    {';', {0x00, 0x06, 0x06, 0x00, 0x06, 0x04, 0x08}},
    {'<', {0x01, 0x02, 0x04, 0x08, 0x04, 0x02, 0x01}},
    {'=', {0x00, 0x00, 0x1F, 0x00, 0x1F, 0x00, 0x00}},
    {'>', {0x10, 0x08, 0x04, 0x02, 0x04, 0x08, 0x10}},
    {'?', {0x0E, 0x11, 0x01, 0x02, 0x04, 0x00, 0x04}},
    {'@', {0x0E, 0x11, 0x15, 0x1D, 0x1D, 0x10, 0x0E}},
    {'/', {0x01, 0x02, 0x04, 0x08, 0x10, 0x00, 0x00}},
    {'0', {0x0E, 0x11, 0x13, 0x15, 0x19, 0x11, 0x0E}},
    {'1', {0x04, 0x0C, 0x04, 0x04, 0x04, 0x04, 0x0E}},
    {'2', {0x0E, 0x11, 0x01, 0x02, 0x04, 0x08, 0x1F}},
    {'3', {0x1E, 0x01, 0x01, 0x0E, 0x01, 0x01, 0x1E}},
    {'4', {0x02, 0x06, 0x0A, 0x12, 0x1F, 0x02, 0x02}},
    {'5', {0x1F, 0x10, 0x10, 0x1E, 0x01, 0x01, 0x1E}},
    {'6', {0x0E, 0x10, 0x10, 0x1E, 0x11, 0x11, 0x0E}},
    {'7', {0x1F, 0x01, 0x02, 0x04, 0x08, 0x08, 0x08}},
    {'8', {0x0E, 0x11, 0x11, 0x0E, 0x11, 0x11, 0x0E}},
    {'9', {0x0E, 0x11, 0x11, 0x0F, 0x01, 0x01, 0x0E}},
    {'A', {0x04, 0x0A, 0x11, 0x11, 0x1F, 0x11, 0x11}},
    {'B', {0x1E, 0x11, 0x11, 0x1E, 0x11, 0x11, 0x1E}},
    {'C', {0x0E, 0x11, 0x10, 0x10, 0x10, 0x11, 0x0E}},
    {'D', {0x1C, 0x12, 0x11, 0x11, 0x11, 0x12, 0x1C}},
    {'E', {0x1F, 0x10, 0x10, 0x1E, 0x10, 0x10, 0x1F}},
    {'F', {0x1F, 0x10, 0x10, 0x1E, 0x10, 0x10, 0x10}},
    {'G', {0x0E, 0x11, 0x10, 0x17, 0x11, 0x11, 0x0E}},
    {'H', {0x11, 0x11, 0x11, 0x1F, 0x11, 0x11, 0x11}},
    {'I', {0x0E, 0x04, 0x04, 0x04, 0x04, 0x04, 0x0E}},
    {'J', {0x01, 0x01, 0x01, 0x01, 0x11, 0x11, 0x0E}},
    {'K', {0x11, 0x12, 0x14, 0x18, 0x14, 0x12, 0x11}},
    {'L', {0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x1F}},
    {'M', {0x11, 0x1B, 0x15, 0x15, 0x11, 0x11, 0x11}},
    {'N', {0x11, 0x11, 0x19, 0x15, 0x13, 0x11, 0x11}},
    {'O', {0x0E, 0x11, 0x11, 0x11, 0x11, 0x11, 0x0E}},
    {'P', {0x1E, 0x11, 0x11, 0x1E, 0x10, 0x10, 0x10}},
    {'Q', {0x0E, 0x11, 0x11, 0x11, 0x15, 0x12, 0x0D}},
    {'R', {0x1E, 0x11, 0x11, 0x1E, 0x14, 0x12, 0x11}},
    {'S', {0x0F, 0x10, 0x10, 0x0E, 0x01, 0x01, 0x1E}},
    {'T', {0x1F, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04}},
    {'U', {0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x0E}},
    {'V', {0x11, 0x11, 0x11, 0x11, 0x11, 0x0A, 0x04}},
    {'W', {0x11, 0x11, 0x11, 0x15, 0x15, 0x15, 0x0A}},
    {'X', {0x11, 0x11, 0x0A, 0x04, 0x0A, 0x11, 0x11}},
    {'Y', {0x11, 0x11, 0x0A, 0x04, 0x04, 0x04, 0x04}},
    {'Z', {0x1F, 0x01, 0x02, 0x04, 0x08, 0x10, 0x1F}},
    {'[', {0x0E, 0x08, 0x08, 0x08, 0x08, 0x08, 0x0E}},
    {'\\', {0x10, 0x08, 0x04, 0x02, 0x01, 0x00, 0x00}},
    {']', {0x0E, 0x02, 0x02, 0x02, 0x02, 0x02, 0x0E}},
    {'^', {0x04, 0x0A, 0x11, 0x00, 0x00, 0x00, 0x00}},
    {'_', {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1F}},
    {'`', {0x04, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00}},
    {'{', {0x03, 0x04, 0x04, 0x18, 0x04, 0x04, 0x03}},
    {'|', {0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04}},
    {'}', {0x18, 0x04, 0x04, 0x03, 0x04, 0x04, 0x18}},
    {'~', {0x00, 0x00, 0x09, 0x16, 0x00, 0x00, 0x00}},
};

static const GLYPH *find_glyph(char ch)
{
    int i;
    char uc = ch;

    if (uc >= 'a' && uc <= 'z')
        uc = (char)(uc - ('a' - 'A'));

    for (i = 0; i < (int)(sizeof(g_font) / sizeof(g_font[0])); i++) {
        if (g_font[i].ch == uc)
            return &g_font[i];
    }

    return &g_font[0];
}

static u64 color_to_gs(u32 color)
{
    int r = (color >> 16) & 0xff;
    int g = (color >> 8) & 0xff;
    int b = color & 0xff;
    return GS_SETREG_RGBAQ(r, g, b, GS_ALPHA_OPAQUE, 0x00);
}

static unsigned char png_alpha_to_gs_alpha(unsigned char alpha)
{
    return (unsigned char)(((unsigned int)alpha * 0x80u + 127u) / 255u);
}

static int rbga_to_rgba(const SPLASH_IMAGE *img, unsigned char *dst_rgba, size_t dst_size)
{
    size_t pixels;
    size_t i;

    if (img == NULL || dst_rgba == NULL)
        return -1;

    pixels = (size_t)img->width * (size_t)img->height;
    if (dst_size < (pixels * 4))
        return -1;

    for (i = 0; i < pixels; i++) {
        size_t src = i * 4;
        size_t dst = i * 4;
        unsigned char r = img->pixels_rbga[src + 0];
        unsigned char b = img->pixels_rbga[src + 1];
        unsigned char g = img->pixels_rbga[src + 2];
        unsigned char a = img->pixels_rbga[src + 3];
        dst_rgba[dst + 0] = r;
        dst_rgba[dst + 1] = g;
        dst_rgba[dst + 2] = b;
        dst_rgba[dst + 3] = png_alpha_to_gs_alpha(a);
    }

    return 0;
}

static void destroy_layer(SPLASH_LAYER *layer)
{
    if (layer == NULL)
        return;

    if (layer->tex.Mem != NULL)
        free(layer->tex.Mem);
    if (layer->tex.Clut != NULL)
        free(layer->tex.Clut);

    memset(&layer->tex, 0, sizeof(layer->tex));
    layer->ready = 0;
}

static void destroy_frame_state(void)
{
    int i;

    for (i = 0; i < (int)(sizeof(g_layers) / sizeof(g_layers[0])); i++)
        destroy_layer(&g_layers[i]);

    if (g_gs != NULL) {
        gsKit_deinit_global(g_gs);
        g_gs = NULL;
    }

    g_screen_w = 0;
    g_screen_h = 0;
    g_logo_x = -1;
    g_logo_y = -1;
    g_logo_visible = 0;
    g_hotkeys_x = -1;
    g_glyphs_rows = 0;
    g_bible_layout = 0;
    g_sky_on = 0;
    g_hotkeys_y = -1;
    g_hotkeys_visible = 0;
    reset_logo_shimmer_state();
}

static int upload_layer_texture(SPLASH_LAYER *layer, const SPLASH_IMAGE *img, int filter)
{
    size_t tex_size;

    if (layer == NULL || img == NULL)
        return 0;

    if (img->pixels_rbga == NULL || img->width == 0 || img->height == 0)
        return 0;

    memset(&layer->tex, 0, sizeof(layer->tex));
    layer->tex.Width = img->width;
    layer->tex.Height = img->height;
    layer->tex.PSM = GS_PSM_CT32;
    layer->tex.Filter = filter;

    tex_size = gsKit_texture_size(layer->tex.Width, layer->tex.Height, layer->tex.PSM);

    layer->tex.Mem = memalign(128, tex_size);
    if (layer->tex.Mem == NULL) {
        destroy_layer(layer);
        return 0;
    }

    memset(layer->tex.Mem, 0, tex_size);
    if (rbga_to_rgba(img, (unsigned char *)layer->tex.Mem, tex_size) != 0) {
        destroy_layer(layer);
        return 0;
    }

    layer->tex.Vram = gsKit_vram_alloc(g_gs, tex_size, GSKIT_ALLOC_USERBUFFER);
#ifdef GSKIT_ALLOC_ERROR
    if (layer->tex.Vram == GSKIT_ALLOC_ERROR) {
        destroy_layer(layer);
        return 0;
    }
#endif

    gsKit_texture_upload(g_gs, &layer->tex);
    layer->ready = 1;
    return 1;
}

static void draw_layer(const SPLASH_LAYER *layer, int x, int y, int z, unsigned char alpha)
{
    if (layer == NULL || !layer->ready)
        return;

    prim_sprite_texture((GSTEXTURE *)&layer->tex,
                        (float)x,
                        (float)y,
                        0.0f,
                        0.0f,
                        (float)(x + (int)layer->tex.Width),
                        (float)(y + (int)layer->tex.Height),
                        (float)layer->tex.Width,
                        (float)layer->tex.Height,
                        z,
                        GS_SETREG_RGBAQ(0x80, 0x80, 0x80, alpha, 0x00));
}

// BIBLE: button id (GLY_*) from hotkeys.png in the BIBLE_GLYPH_CELL square at x, y; a shorter icon (L1, R1, SELECT,
// START) in the middle of it
static void draw_glyph(const SPLASH_LAYER *layer, int id, int x, int y, int z, unsigned char alpha)
{
    const int v = g_glyph_src[id][0], h = g_glyph_src[id][1];

    if (layer == NULL || !layer->ready)
        return;

    y += (BIBLE_GLYPH_CELL - h) / 2;
    prim_sprite_texture((GSTEXTURE *)&layer->tex,
                        (float)x,
                        (float)y,
                        (float)BIBLE_GLYPH_SRC_X,
                        (float)v,
                        (float)(x + BIBLE_GLYPH_CELL),
                        (float)(y + h),
                        (float)(BIBLE_GLYPH_SRC_X + BIBLE_GLYPH_SRC_W),
                        (float)(v + h),
                        z,
                        GS_SETREG_RGBAQ(0x80, 0x80, 0x80, alpha, 0x00));
}

// BIBLE: the sky's colour y lines down: top to horizon, then horizon to floor, as RIPPS2 draws its two gradients
static unsigned int sky_at(int y)
{
    int hy = BIBLE_SKY_HORIZON(g_screen_h), a = 0, b = 1, t = y, n = hy, i;
    unsigned int out = 0;

    if (y > hy) {
        a = 1;
        b = 2;
        t = y - hy;
        n = g_screen_h - hy;
    }
    if (n <= 0)
        return g_sky[b];
    if (t < 0)
        t = 0;
    if (t > n)
        t = n;
    for (i = 0; i < 24; i += 8) {
        int ca = (int)((g_sky[a] >> i) & 0xFF), cb = (int)((g_sky[b] >> i) & 0xFF);
        out |= (unsigned int)((ca + (cb - ca) * t / n) & 0xFF) << i;
    }
    return out;
}

static u64 sky_rgbaq(unsigned int c)
{
    return GS_SETREG_RGBAQ((c >> 16) & 0xFF, (c >> 8) & 0xFF, c & 0xFF, GS_ALPHA_OPAQUE, 0x00);
}

// BIBLE: RIPPS2's sky over x0..x1, y0..y1 (the whole screen, or the piece an overlay gives back), split at the horizon
static void draw_sky_rect(int x0, int y0, int x1, int y1, int z)
{
    int hy = BIBLE_SKY_HORIZON(g_screen_h);
    u64 top, bottom;

    if (g_gs == NULL || x0 >= x1 || y0 >= y1)
        return;
    if (y0 < hy && y1 > hy) {
        draw_sky_rect(x0, y0, x1, hy, z);
        draw_sky_rect(x0, hy, x1, y1, z);
        return;
    }
    top = sky_rgbaq(sky_at(y0));
    bottom = sky_rgbaq(sky_at(y1));
    prim_quad_gouraud((float)x0, (float)y0, (float)x1, (float)y0, (float)x0, (float)y1, (float)x1, (float)y1,
                      z, top, top, bottom, bottom);
}

static void draw_layer_stretched(const SPLASH_LAYER *layer, int z)
{
    if (layer == NULL || !layer->ready)
        return;

    prim_sprite_texture((GSTEXTURE *)&layer->tex,
                        0.0f,
                        0.0f,
                        0.0f,
                        0.0f,
                        (float)g_screen_w,
                        (float)g_screen_h,
                        (float)layer->tex.Width,
                        (float)layer->tex.Height,
                        z,
                        GS_SETREG_RGBAQ(0x80, 0x80, 0x80, GS_ALPHA_OPAQUE, 0x00));
}

static void draw_filled_rect(int x0, int y0, int x1, int y1, int z, u64 color)
{
    if (g_gs == NULL)
        return;

    if (x0 >= x1 || y0 >= y1)
        return;

    prim_sprite((float)x0,
                (float)y0,
                (float)x1,
                (float)y1,
                z,
                color);
}

static void draw_logo_subrect(int rel_x,
                              int rel_w,
                              int z,
                              unsigned char alpha,
                              unsigned char rgb)
{
    const SPLASH_LAYER *logo = &g_layers[LAYER_LOGO];

    if (!g_logo_visible || !logo->ready || rel_w <= 0 || alpha == 0)
        return;

    if (rel_x < 0) {
        rel_w += rel_x;
        rel_x = 0;
    }
    if (rel_x >= (int)logo->tex.Width)
        return;
    if (rel_x + rel_w > (int)logo->tex.Width)
        rel_w = (int)logo->tex.Width - rel_x;
    if (rel_w <= 0)
        return;

    prim_sprite_texture((GSTEXTURE *)&logo->tex,
                        (float)(g_logo_x + rel_x),
                        (float)g_logo_y,
                        (float)rel_x,
                        0.0f,
                        (float)(g_logo_x + rel_x + rel_w),
                        (float)(g_logo_y + (int)logo->tex.Height),
                        (float)(rel_x + rel_w),
                        (float)logo->tex.Height,
                        z,
                        GS_SETREG_RGBAQ(rgb, rgb, rgb, alpha, 0x00));
}

static void draw_logo_subrect_shifted(int rel_x,
                                      int rel_w,
                                      int src_shift_x,
                                      int z,
                                      unsigned char alpha,
                                      unsigned char rgb)
{
    const SPLASH_LAYER *logo = &g_layers[LAYER_LOGO];
    int dst_x0;
    int dst_x1;
    int src_x0;
    int src_x1;

    if (!g_logo_visible || !logo->ready || rel_w <= 0 || alpha == 0)
        return;

    dst_x0 = rel_x;
    dst_x1 = rel_x + rel_w;
    if (dst_x1 <= 0 || dst_x0 >= (int)logo->tex.Width)
        return;

    if (dst_x0 < 0)
        dst_x0 = 0;
    if (dst_x1 > (int)logo->tex.Width)
        dst_x1 = (int)logo->tex.Width;
    if (dst_x0 >= dst_x1)
        return;

    src_x0 = dst_x0 + src_shift_x;
    src_x1 = dst_x1 + src_shift_x;

    if (src_x0 < 0) {
        dst_x0 += -src_x0;
        src_x0 = 0;
    }
    if (src_x1 > (int)logo->tex.Width) {
        dst_x1 -= (src_x1 - (int)logo->tex.Width);
        src_x1 = (int)logo->tex.Width;
    }
    if (dst_x0 >= dst_x1 || src_x0 >= src_x1)
        return;

    prim_sprite_texture((GSTEXTURE *)&logo->tex,
                        (float)(g_logo_x + dst_x0),
                        (float)g_logo_y,
                        (float)src_x0,
                        0.0f,
                        (float)(g_logo_x + dst_x1),
                        (float)(g_logo_y + (int)logo->tex.Height),
                        (float)src_x1,
                        (float)logo->tex.Height,
                        z,
                        GS_SETREG_RGBAQ(rgb, rgb, rgb, alpha, 0x00));
}

static void draw_logo_shimmer_band_lens(int band_left,
                                        int band_width,
                                        unsigned char highlight_peak_alpha,
                                        unsigned char halo_peak_alpha,
                                        unsigned char distort_peak_alpha)
{
    int i;

    if (band_width <= 0)
        return;

    for (i = 0; i < LOGO_SHIMMER_SLICE_COUNT; i++) {
        int slice_left = band_left + ((band_width * i) / LOGO_SHIMMER_SLICE_COUNT);
        int slice_right = band_left + ((band_width * (i + 1)) / LOGO_SHIMMER_SLICE_COUNT);
        int slice_width = slice_right - slice_left;
        int center_numer = (2 * i + 1) - LOGO_SHIMMER_SLICE_COUNT;
        int abs_center_numer = abs(center_numer);
        int edge_scale_numer = LOGO_SHIMMER_SLICE_COUNT - abs_center_numer;
        int edge_scale_sq_numer;
        int edge_soft_numer;
        int distort_profile_numer;
        int distort_shift;
        unsigned char highlight_alpha;
        unsigned char halo_alpha;
        unsigned char distort_alpha;

        if (slice_width <= 0 || edge_scale_numer <= 0)
            continue;

        edge_scale_sq_numer = edge_scale_numer * edge_scale_numer;
        edge_soft_numer = (edge_scale_sq_numer * edge_scale_sq_numer);
        highlight_alpha = (unsigned char)((highlight_peak_alpha * edge_soft_numer + 5000) / 10000);
        halo_alpha = (unsigned char)((halo_peak_alpha * edge_scale_sq_numer + 50) / 100);
        distort_profile_numer = 100 - ((abs_center_numer * abs_center_numer * 100) /
                                       (LOGO_SHIMMER_SLICE_COUNT * LOGO_SHIMMER_SLICE_COUNT));
        if (distort_profile_numer < 0)
            distort_profile_numer = 0;
        distort_alpha = (unsigned char)((distort_peak_alpha * edge_scale_numer + (LOGO_SHIMMER_SLICE_COUNT / 2)) /
                                        LOGO_SHIMMER_SLICE_COUNT);
        distort_shift = (center_numer * distort_profile_numer * LOGO_SHIMMER_DISTORT_MAX_SHIFT_PX) /
                        (LOGO_SHIMMER_SLICE_COUNT * 100);

        if (distort_alpha > 0)
            draw_logo_subrect_shifted(slice_left, slice_width, distort_shift, FG_Z + 1, distort_alpha, 0x80);
        if (halo_alpha > 0)
            draw_logo_subrect(slice_left, slice_width, FG_Z + 2, halo_alpha, 0xFF);
        if (highlight_alpha == 0)
            continue;
        draw_logo_subrect(slice_left, slice_width, FG_Z + 3, highlight_alpha, 0xFF);
    }
}

static void draw_logo_shimmer_overlay(void)
{
#if LOGO_SHIMMER_ENABLED
    const SPLASH_LAYER *logo = &g_layers[LAYER_LOGO];
    unsigned char base_logo_alpha;
    unsigned char highlight_peak_alpha;
    unsigned char halo_peak_alpha;
    unsigned char distort_peak_alpha;
    int shimmer_min_left;
    int shimmer_max_left;

    if (!g_logo_visible || !logo->ready || logo->tex.Width == 0)
        return;

    if (g_logo_shimmer_band_width <= 0 || g_logo_shimmer_band_width > (int)logo->tex.Width)
        g_logo_shimmer_band_width = compute_logo_shimmer_band_width((int)logo->tex.Width);
    if (g_logo_shimmer_band_width <= 0)
        return;

    base_logo_alpha = get_logo_base_alpha();
    highlight_peak_alpha = opacity_percent_to_gs_alpha(LOGO_SHIMMER_HIGHLIGHT_OPACITY_PERCENT);
    halo_peak_alpha = opacity_percent_to_gs_alpha(LOGO_SHIMMER_HALO_OPACITY_PERCENT);
    distort_peak_alpha = opacity_percent_to_gs_alpha(LOGO_SHIMMER_DISTORT_OPACITY_PERCENT);
    highlight_peak_alpha = (unsigned char)(((unsigned int)highlight_peak_alpha * (unsigned int)base_logo_alpha + (GS_ALPHA_OPAQUE / 2)) / GS_ALPHA_OPAQUE);
    halo_peak_alpha = (unsigned char)(((unsigned int)halo_peak_alpha * (unsigned int)base_logo_alpha + (GS_ALPHA_OPAQUE / 2)) / GS_ALPHA_OPAQUE);
    distort_peak_alpha = (unsigned char)(((unsigned int)distort_peak_alpha * (unsigned int)base_logo_alpha + (GS_ALPHA_OPAQUE / 2)) / GS_ALPHA_OPAQUE);
    draw_logo_shimmer_band_lens(g_logo_shimmer_left,
                                g_logo_shimmer_band_width,
                                highlight_peak_alpha,
                                halo_peak_alpha,
                                distort_peak_alpha);

    get_logo_shimmer_sweep_bounds(logo, &shimmer_min_left, &shimmer_max_left);
    g_logo_shimmer_left += LOGO_SHIMMER_SPEED_PX_PER_FRAME;
    if (g_logo_shimmer_left > shimmer_max_left)
        g_logo_shimmer_left = shimmer_min_left;
#endif
}

void SplashRenderRestoreBackgroundRect(int x, int y, int w, int h)
{
    int x0;
    int y0;
    int x1;
    int y1;
    float u0;
    float v0;
    float u1;
    float v1;
    const SPLASH_LAYER *bg = &g_layers[LAYER_BG];

    if (g_gs == NULL || (!g_sky_on && !bg->ready) || g_screen_w <= 0 || g_screen_h <= 0 || w <= 0 || h <= 0)
        return;

    x0 = x;
    y0 = y;
    x1 = x + w;
    y1 = y + h;

    if (x0 < 0)
        x0 = 0;
    if (y0 < 0)
        y0 = 0;
    if (x1 > g_screen_w)
        x1 = g_screen_w;
    if (y1 > g_screen_h)
        y1 = g_screen_h;

    if (x0 >= x1 || y0 >= y1)
        return;
    if (g_sky_on) { // BIBLE: the sky is drawn, not a picture
        draw_sky_rect(x0, y0, x1, y1, FG_Z);
        return;
    }

    u0 = ((float)x0 * (float)bg->tex.Width) / (float)g_screen_w;
    v0 = ((float)y0 * (float)bg->tex.Height) / (float)g_screen_h;
    u1 = ((float)x1 * (float)bg->tex.Width) / (float)g_screen_w;
    v1 = ((float)y1 * (float)bg->tex.Height) / (float)g_screen_h;

    prim_sprite_texture((GSTEXTURE *)&bg->tex,
                        (float)x0,
                        (float)y0,
                        u0,
                        v0,
                        (float)x1,
                        (float)y1,
                        u1,
                        v1,
                        FG_Z,
                        GS_SETREG_RGBAQ(0x80, 0x80, 0x80, GS_ALPHA_OPAQUE, 0x00));
}

void SplashRenderSetGlyphs(int mode)
{
    g_bible_glyphs = mode < 0 ? 0 : mode > 2 ? 2 : mode;
}

void SplashRenderSetWide(int on)
{
    g_wide = on != 0;
}

void SplashRenderSetSky(const unsigned int sky[3])
{
    int i;

    for (i = 0; i < 3; i++)
        g_sky[i] = sky[i] & 0xFFFFFF;
}

void SplashRenderSetHotkeysVisible(int visible)
{
    g_hotkeys_visible = (visible != 0);
}

void SplashRenderSetLogoShimmerCountdown(u64 remaining_ms, u64 total_ms)
{
#if LOGO_SHIMMER_ENABLED
    const SPLASH_LAYER *logo = &g_layers[LAYER_LOGO];
    int shimmer_min_left;
    int shimmer_max_left;
    int countdown_max_left;
    int shimmer_travel;
    u64 elapsed_ms;

    if (!g_logo_visible || !logo->ready || logo->tex.Width == 0 || total_ms == 0)
        return;

    if (g_logo_shimmer_band_width <= 0 || g_logo_shimmer_band_width > (int)logo->tex.Width)
        g_logo_shimmer_band_width = compute_logo_shimmer_band_width((int)logo->tex.Width);
    if (g_logo_shimmer_band_width <= 0)
        return;

    if (remaining_ms > total_ms)
        remaining_ms = total_ms;
    elapsed_ms = total_ms - remaining_ms;

    get_logo_shimmer_sweep_bounds(logo, &shimmer_min_left, &shimmer_max_left);
    if (g_logo_shimmer_visible_right > 0 && g_logo_shimmer_visible_right <= (int)logo->tex.Width)
        countdown_max_left = g_logo_shimmer_visible_right - 1;
    else
        countdown_max_left = (int)logo->tex.Width - 1;
    if (countdown_max_left < shimmer_min_left)
        countdown_max_left = shimmer_min_left;
    if (shimmer_max_left > countdown_max_left)
        shimmer_max_left = countdown_max_left;

    shimmer_travel = shimmer_max_left - shimmer_min_left;
    g_logo_shimmer_left = shimmer_min_left + (int)((elapsed_ms * (u64)shimmer_travel + (total_ms / 2)) / total_ms);
    if (g_logo_shimmer_left < shimmer_min_left)
        g_logo_shimmer_left = shimmer_min_left;
    if (g_logo_shimmer_left > shimmer_max_left)
        g_logo_shimmer_left = shimmer_max_left;
#else
    (void)remaining_ms;
    (void)total_ms;
#endif
}

static void draw_static_layers(void)
{
    const unsigned char logo_alpha = get_logo_base_alpha();

    if (g_sky_on)
        draw_sky_rect(0, 0, g_screen_w, g_screen_h, BG_Z);
    else
        draw_layer_stretched(&g_layers[LAYER_BG], BG_Z);
    if (g_logo_visible) {
        draw_layer(&g_layers[LAYER_LOGO], g_logo_x, g_logo_y, FG_Z, logo_alpha);
        if (!g_page_on && g_fade == 100)
            draw_logo_shimmer_overlay();
    }
    if (g_hotkeys_visible && !g_page_on)
        draw_layer(&g_layers[LAYER_HOTKEYS], g_hotkeys_x, g_hotkeys_y, FG_Z,
                   opacity_percent_to_gs_alpha((unsigned int)g_fade));
    else if (g_hotkeys_visible && g_page_sheet) // BIBLE: the launch keys page fades the sheet in
        draw_layer(&g_layers[LAYER_HOTKEYS], g_hotkeys_x, g_hotkeys_y, FG_Z,
                   opacity_percent_to_gs_alpha((unsigned int)page_fade()));
}

// BIBLE: the glyph rows' box, g_glyphs_cols buttons wide, g_glyphs_rows high
static int glyphs_box_w(void)
{
    return g_glyphs_cols * BIBLE_GLYPH_CELL + (g_glyphs_cols - 1) * BIBLE_GLYPH_GAP;
}

static int glyphs_box_h(void)
{
    return g_glyphs_rows * BIBLE_GLYPH_CELL + (g_glyphs_rows - 1) * BIBLE_GLYPH_ROW_GAP;
}

// BIBLE: a page's text or box at x0..x1, y0..y1 over the glyph rows hides them for this frame (credits, the video
// mode selector, prompts and status lines all write under the logo)
static void glyphs_cover(int x0, int y0, int x1, int y1)
{
    if (g_glyphs_rows <= 0)
        return;
    if (x1 > g_glyphs_x && x0 < g_glyphs_x + glyphs_box_w() &&
        y1 > g_glyphs_y && y0 < g_glyphs_y + glyphs_box_h())
        g_glyphs_covered = 1;
}

// BIBLE: the buttons under the logo, four to a row
static void draw_glyph_rows(void)
{
    int r, k;

    if (g_glyphs_rows <= 0 || g_glyphs_covered || g_page_on)
        return;
    for (r = 0; r < g_glyphs_rows; r++)
        for (k = 0; k < g_glyphs_cols; k++)
            draw_glyph(&g_layers[LAYER_HOTKEYS], g_glyph_rows[r][k], g_glyphs_x + k * (BIBLE_GLYPH_CELL + BIBLE_GLYPH_GAP),
                       g_glyphs_y + r * (BIBLE_GLYPH_CELL + BIBLE_GLYPH_ROW_GAP), FG_Z,
                       opacity_percent_to_gs_alpha((unsigned int)g_fade));
}

void SplashRenderBeginFrame(void)
{
    if (g_gs == NULL)
        return;

    gsKit_clear(g_gs, GS_SETREG_RGBAQ(0x00, 0x00, 0x00, 0x80, 0x00));
    draw_static_layers();
    g_glyphs_covered = 0;
}

void SplashRenderPresent(void)
{
    if (g_gs == NULL)
        return;

    draw_glyph_rows();
    gsKit_queue_exec(g_gs);
    gsKit_finish();
    gsKit_sync_flip(g_gs);
}

int SplashRenderBegin(int logo_disp, int is_psx_desr)
{
    const SPLASH_IMAGE *logo;
    int center_x;
    int center_y;
    int pass;
    int filter;

    destroy_frame_state();

    if (logo_disp < 1)
        return 0;

    g_gs = gsKit_init_global();
    if (g_gs == NULL)
        return 0;

    g_gs->DoubleBuffering = GS_SETTING_ON;
    g_gs->ZBuffering = GS_SETTING_OFF;
    g_gs->PrimAlphaEnable = GS_SETTING_ON;
    configure_gskit_video_mode(g_gs);
    gsKit_set_primalpha(g_gs, GS_SETREG_ALPHA(0, 1, 0, 1, 0), 0);
    gsKit_init_screen(g_gs);
    gsKit_display_buffer(g_gs);
    gsKit_mode_switch(g_gs, GS_ONESHOT);
    // BIBLE: the layout's size, its scale to the framebuffer, and a smooth texture filter when that is not 1:1
    g_screen_w = g_virt_w;
    g_screen_h = g_virt_h;
    g_sx = (float)g_gs->Width / (float)g_screen_w;
    g_sy = (float)g_gs->Height / (float)g_screen_h;
    filter = ((int)g_gs->Width == g_screen_w && (int)g_gs->Height == g_screen_h) ? GS_FILTER_NEAREST : GS_FILTER_LINEAR;
    // Prime both framebuffers to opaque black to avoid mode-switch garbage flashes; BIBLE's layouts prime them with the
    // sky, the splash's ground, so nothing dark shows between pages or before the first frame.
    for (pass = 0; pass < 2; pass++) {
        gsKit_clear(g_gs, GS_SETREG_RGBAQ(0x00, 0x00, 0x00, 0x80, 0x00));
        if (logo_disp >= 2)
            draw_sky_rect(0, 0, g_screen_w, g_screen_h, BG_Z);
        gsKit_queue_exec(g_gs);
        gsKit_finish();
        gsKit_sync_flip(g_gs);
    }
    center_x = g_screen_w / 2;
    center_y = g_screen_h / 2;

    if (logo_disp == 1) {
        // LOGO_DISPLAY=1 renders text-only info overlay on black.
        g_logo_visible = 0;
        g_hotkeys_visible = 0;
        SplashRenderBeginFrame();
        SplashRenderPresent();
        return 1;
    }

    g_sky_on = 1; // BIBLE: RIPPS2's sky (BIBLE_COLOR) in place of the background picture

    logo = SplashGetLogoImage(is_psx_desr);
    if (!upload_layer_texture(&g_layers[LAYER_LOGO], logo, filter)) {
        destroy_frame_state();
        return 0;
    }
    compute_logo_visible_bounds_from_image(logo,
                                           &g_logo_shimmer_visible_left,
                                           &g_logo_shimmer_visible_right);

    if (logo_disp == 2) {
        // BIBLE: the logo in the middle whatever shows; BIBLE_GLYPHS' rows under it, the text above it
        int rows = g_bible_glyphs == 2 ? 2 : g_bible_glyphs == 1 ? 1 : 0;

        if (!upload_layer_texture(&g_layers[LAYER_HOTKEYS], SplashGetHotkeysImage(), filter))
            rows = 0;
        g_logo_x = center_x - ((int)logo->width / 2) + MODE2_LOGO_X_FROM_CENTER;
        g_logo_y = center_y - ((int)logo->height / 2) + MODE2_LOGO_Y_FROM_CENTER;
        g_logo_visible = 1;
        g_hotkeys_visible = 0;
        g_bible_layout = 1;
        g_glyphs_rows = rows;
        g_glyphs_cols = rows == 2 ? 8 : 4;
        g_glyphs_x = center_x - glyphs_box_w() / 2;
        g_glyphs_y = g_logo_y + (int)logo->height + BIBLE_GLYPH_BELOW;
        if (g_layers[LAYER_HOTKEYS].ready) { // the launch keys page's sheet, where LOGO_DISPLAY 3 puts it
            g_hotkeys_x = ((g_screen_w * MODE35_HOTKEYS_LEFT_PERCENT) + 50) / 100 + MODE35_HOTKEYS_X_ADJUST;
            g_hotkeys_y = center_y - ((int)SplashGetHotkeysImage()->height / 2) + MODE35_HOTKEYS_Y_FROM_CENTER;
        }
        init_logo_shimmer_state();
        SplashRenderBeginFrame();
        SplashRenderPresent();
        return 1;
    }

    {
        const SPLASH_IMAGE *hotkeys = SplashGetHotkeysImage();
        int logo_x;
        int logo_y;
        int hotkeys_x;
        int hotkeys_y;

        if (!upload_layer_texture(&g_layers[LAYER_HOTKEYS], hotkeys, filter)) {
            destroy_frame_state();
            return 0;
        }

        logo_x = center_x - ((int)logo->width / 2) + MODE35_LOGO_X_FROM_CENTER;
        logo_y = center_y - ((int)logo->height / 2) + MODE35_LOGO_Y_FROM_CENTER;

        hotkeys_x = ((g_screen_w * MODE35_HOTKEYS_LEFT_PERCENT) + 50) / 100 + MODE35_HOTKEYS_X_ADJUST;
        hotkeys_y = center_y - ((int)hotkeys->height / 2) + MODE35_HOTKEYS_Y_FROM_CENTER;
        g_logo_x = logo_x;
        g_logo_y = logo_y;
        g_logo_visible = 1;
        g_hotkeys_x = hotkeys_x;
        g_hotkeys_y = hotkeys_y;
        g_hotkeys_visible = 1;
        init_logo_shimmer_state();

        // For LOGO_DISPLAY=3, defer the first present until the caller draws
        // hotkey text lines so the image/text appear together.
    }

    return 1;
}

void SplashRenderDrawTextPxScaled(int x, int y, u32 color, const char *text, int scale)
{
    int draw_scale;
    int advance;
    int i;
    int cx;
    int shadow_offset_x;
    int shadow_offset_y;
    u64 gs_color;
    u64 shadow_color;

    if (g_gs == NULL || text == NULL)
        return;

    draw_scale = (scale > 0) ? scale : 1;
    glyphs_cover(x, y, x + (int)strlen(text) * (FONT_W + 1) * draw_scale + GLYPH_SHADOW_OFFSET_X,
                 y + FONT_H * draw_scale + GLYPH_SHADOW_OFFSET_Y);
    gs_color = color_to_gs(color);
    shadow_color = GS_SETREG_RGBAQ(0x00,
                                   0x00,
                                   0x00,
                                   transparency_percent_to_gs_alpha(GLYPH_SHADOW_TRANSPARENCY_PERCENT),
                                   0x00);
    if (g_page_on && page_fade() < 100) { // BIBLE: a page's text fades in
        int f = page_fade();

        gs_color = GS_SETREG_RGBAQ((color >> 16) & 0xff, (color >> 8) & 0xff, color & 0xff,
                                   opacity_percent_to_gs_alpha((unsigned int)f), 0x00);
        shadow_color = GS_SETREG_RGBAQ(0x00, 0x00, 0x00,
                                       transparency_percent_to_gs_alpha(GLYPH_SHADOW_TRANSPARENCY_PERCENT) * f / 100,
                                       0x00);
    }
    draw_scale = (scale > 0) ? scale : 1;
    advance = (FONT_W + 1) * draw_scale;
    shadow_offset_x = GLYPH_SHADOW_OFFSET_X;
    shadow_offset_y = GLYPH_SHADOW_OFFSET_Y;

    // Pass 1: draw all shadows so glyph pixels can always render above them.
    cx = x;
    for (i = 0; text[i] != '\0'; i++) {
        int row;
        const GLYPH *glyph = find_glyph(text[i]);
        for (row = 0; row < FONT_H; row++) {
            unsigned char bits = glyph->rows[row];
            int col;
            for (col = 0; col < FONT_W; col++) {
                if (bits & (1u << (FONT_W - 1 - col))) {
                    int px = cx + (col * draw_scale);
                    int py = y + (row * draw_scale);
                    prim_sprite((float)(px + shadow_offset_x),
                                (float)(py + shadow_offset_y),
                                (float)(px + shadow_offset_x + draw_scale),
                                (float)(py + shadow_offset_y + draw_scale),
                                TEXT_SHADOW_Z,
                                shadow_color);
                }
            }
        }
        cx += advance;
    }

    // Pass 2: draw glyph pixels on top of all shadow pixels.
    cx = x;
    for (i = 0; text[i] != '\0'; i++) {
        int row;
        const GLYPH *glyph = find_glyph(text[i]);
        for (row = 0; row < FONT_H; row++) {
            unsigned char bits = glyph->rows[row];
            int col;
            for (col = 0; col < FONT_W; col++) {
                if (bits & (1u << (FONT_W - 1 - col))) {
                    int px = cx + (col * draw_scale);
                    int py = y + (row * draw_scale);
                    prim_sprite((float)px,
                                (float)py,
                                (float)(px + draw_scale),
                                (float)(py + draw_scale),
                                TEXT_Z,
                                gs_color);
                }
            }
        }
        cx += advance;
    }
}

void SplashRenderDrawRoundedRect(int x,
                                 int y,
                                 int w,
                                 int h,
                                 int radius,
                                 u32 color,
                                 unsigned int opacity_percent)
{
    int x0 = x;
    int y0 = y;
    int x1 = x + w;
    int y1 = y + h;
    int r;
    int row;
    int dx_max;
    int cr;
    int cg;
    int cb;
    unsigned char alpha;
    u64 gs_color;

    if (g_gs == NULL || w <= 0 || h <= 0)
        return;

    glyphs_cover(x0, y0, x1, y1);
    if (x0 < 0)
        x0 = 0;
    if (y0 < 0)
        y0 = 0;
    if (x1 > g_screen_w)
        x1 = g_screen_w;
    if (y1 > g_screen_h)
        y1 = g_screen_h;
    if (x0 >= x1 || y0 >= y1)
        return;

    r = radius;
    if (r < 0)
        r = 0;
    if (r > (x1 - x0) / 2)
        r = (x1 - x0) / 2;
    if (r > (y1 - y0) / 2)
        r = (y1 - y0) / 2;

    cr = (color >> 16) & 0xFF;
    cg = (color >> 8) & 0xFF;
    cb = color & 0xFF;
    alpha = opacity_percent_to_gs_alpha(opacity_percent);
    gs_color = GS_SETREG_RGBAQ(cr, cg, cb, alpha, 0x00);

    if (r == 0) {
        draw_filled_rect(x0, y0, x1, y1, OVERLAY_RECT_Z, gs_color);
        return;
    }

    draw_filled_rect(x0 + r, y0, x1 - r, y1, OVERLAY_RECT_Z, gs_color);
    draw_filled_rect(x0, y0 + r, x0 + r, y1 - r, OVERLAY_RECT_Z, gs_color);
    draw_filled_rect(x1 - r, y0 + r, x1, y1 - r, OVERLAY_RECT_Z, gs_color);

    for (row = 0; row < r; row++) {
        dx_max = r;
        while (dx_max > 0 && ((dx_max * dx_max) + (row * row)) > (r * r))
            dx_max--;

        if (dx_max <= 0)
            continue;

        draw_filled_rect(x0 + (r - dx_max), y0 + row, x0 + r, y0 + row + 1, OVERLAY_RECT_Z, gs_color);
        draw_filled_rect(x1 - r, y0 + row, x1 - (r - dx_max), y0 + row + 1, OVERLAY_RECT_Z, gs_color);
        draw_filled_rect(x0 + (r - dx_max), y1 - row - 1, x0 + r, y1 - row, OVERLAY_RECT_Z, gs_color);
        draw_filled_rect(x1 - r, y1 - row - 1, x1 - (r - dx_max), y1 - row, OVERLAY_RECT_Z, gs_color);
    }
}

void SplashRenderDrawTextPx(int x, int y, u32 color, const char *text)
{
    SplashRenderDrawTextPxScaled(x, y, color, text, FONT_SCALE);
}

static int page_fade(void)
{
    u64 t;

    if (!g_page_on)
        return 100;
    t = Timer() - g_page_t0;
    return t >= BIBLE_PAGE_FADE_MS ? 100 : (int)(t * 100 / BIBLE_PAGE_FADE_MS);
}

void SplashRenderPageBegin(void)
{
    if (!g_page_on) {
        g_page_on = 1;
        g_page_t0 = Timer();
    }
}

void SplashRenderPageEnd(void)
{
    g_page_on = 0;
    g_page_sheet = 0;
}

void SplashRenderPageSheet(int on)
{
    g_page_sheet = on != 0;
}

int SplashRenderPageFade(void)
{
    return page_fade();
}

// BIBLE: a page's box, faded in with it
void SplashRenderPageBox(int x, int y, int w, int h)
{
    SplashRenderDrawRoundedRect(x, y, w, h, 0, BIBLE_PAGE_BOX_COLOR,
                                (unsigned int)(BIBLE_PAGE_BOX_OPACITY * page_fade() / 100));
}

// BIBLE: LOGO_DISPLAY 2 puts the info line BIBLE_TEXT_PAD above the logo; -1 for the upstream layouts
int SplashRenderInfoLineY(void)
{
    if (!g_bible_layout || g_logo_y < 0 || g_page_on)
        return -1;
    return g_logo_y - BIBLE_TEXT_PAD - BIBLE_TEXT_H;
}

// BIBLE: the first line's y for text block_h high that sits above the logo (above the info line when it shows), or
// -1 for the upstream layouts, which keep their own places
int SplashRenderTextTopY(int block_h)
{
    int bottom;

    if (!g_bible_layout || g_logo_y < 0)
        return -1;
    bottom = g_logo_y - BIBLE_TEXT_PAD;
    if (SplashRenderInfoOn())
        bottom -= BIBLE_TEXT_H + BIBLE_TEXT_GAP;
    return bottom - block_h < 8 ? 8 : bottom - block_h;
}

int SplashRenderIsActive(void)
{
    return (g_gs != NULL);
}

void SplashRenderEnd(void)
{
    SplashRenderPresent();
    destroy_frame_state();
}

// BIBLE: the hand-off to the program being launched. The logo, the buttons and the sheet fade away over
// BIBLE_HANDOFF_FADE_FRAMES (text goes at once), both framebuffers are left holding the sky alone, and the GS keeps
// showing it: nothing resets the display until the program sets its own. RIPPS2 starts on that same sky in the same
// mode (it reads them from the same settings), so the TV keeps its sync and nothing pops between the two.
// The fade counts frames, not Timer(): an AUTO launch has ended the timer (TimerEnd) before CleanUp, and a fade waiting
// on Timer() never ended (the boot stopped on the splash after opening the ELF). Each present waits for a vsync.
#define BIBLE_HANDOFF_FADE_FRAMES 15 // a quarter of a second at 60 Hz
void SplashRenderHandoff(void)
{
    int frame;
    int pass;

    if (g_gs == NULL)
        return;
    if (!g_sky_on) { // the upstream layouts end as they always have
        SplashRenderEnd();
        return;
    }
    g_page_on = 0;
    g_page_sheet = 0;
    for (frame = 1; frame <= BIBLE_HANDOFF_FADE_FRAMES; frame++) {
        g_fade = 100 - frame * 100 / BIBLE_HANDOFF_FADE_FRAMES;
        SplashRenderBeginFrame();
        SplashRenderPresent();
    }
    g_logo_visible = 0;
    g_hotkeys_visible = 0;
    g_glyphs_rows = 0;
    for (pass = 0; pass < 2; pass++) { // the sky alone in both framebuffers, whichever the GS is left showing
        SplashRenderBeginFrame();
        SplashRenderPresent();
    }
    g_fade = 100;
    destroy_frame_state();
}

int SplashRenderGetScreenWidth(void)
{
    return (g_screen_w > 0) ? g_screen_w : 640;
}

int SplashRenderGetScreenHeight(void)
{
    return (g_screen_h > 0) ? g_screen_h : 480;
}

int SplashRenderGetScreenCenterX(void)
{
    return SplashRenderGetScreenWidth() / 2;
}

int SplashRenderGetScreenCenterY(void)
{
    return SplashRenderGetScreenHeight() / 2;
}

int SplashRenderGetHotkeysX(void)
{
    return g_hotkeys_x;
}

int SplashRenderGetHotkeysY(void)
{
    return g_hotkeys_y;
}

int SplashRenderGetLogoX(void)
{
    return g_logo_x;
}

int SplashRenderGetLogoY(void)
{
    return g_logo_y;
}

int SplashRenderGetLogoWidth(void)
{
    const SPLASH_LAYER *logo = &g_layers[LAYER_LOGO];

    if (!logo->ready)
        return 0;
    return (int)logo->tex.Width;
}

int SplashRenderGetLogoHeight(void)
{
    const SPLASH_LAYER *logo = &g_layers[LAYER_LOGO];

    if (!logo->ready)
        return 0;
    return (int)logo->tex.Height;
}
