// Runtime utilities (ROM detection, cleanup, emergency/rescue mode).
#include "main.h"
#include "loader_path.h"
#include "splash_render.h"
#include "splash_screen.h"

#define ROMVER_MODEL_PREFIX_LEN 5
#define CREDITS_POLL_INTERVAL_MS 50u
#define EMERGENCY_RESCUE_POLL_INTERVAL_MS 100u

extern u8 ROMVER[16];
extern int g_is_psx_desr;
extern int g_native_video_mode;

static const char *const g_psx_desr_rom_prefixes[] = {
    "0180J",
    "0210J",
};

static int ROMVERMatchesAnyPrefix(const u8 romver[16], const char *const *prefixes, size_t prefix_count)
{
    size_t i;

    if (romver == NULL || prefixes == NULL)
        return 0;

    for (i = 0; i < prefix_count; i++) {
        if (!strncmp((const char *)romver, prefixes[i], ROMVER_MODEL_PREFIX_LEN))
            return 1;
    }

    return 0;
}

static int IsPSXDESRROMVER(const u8 romver[16])
{
    return ROMVERMatchesAnyPrefix(romver,
                                  g_psx_desr_rom_prefixes,
                                  sizeof(g_psx_desr_rom_prefixes) / sizeof(g_psx_desr_rom_prefixes[0]));
}

void ReadROMVEROnce(void)
{
    int fd;
    int nread;

    memset(ROMVER, 0, sizeof(ROMVER));
    if ((fd = open("rom0:ROMVER", O_RDONLY)) >= 0) {
        nread = read(fd, ROMVER, sizeof(ROMVER));
        close(fd);
        if (nread != (int)sizeof(ROMVER))
            memset(ROMVER, 0, sizeof(ROMVER));
    }

    g_is_psx_desr = IsPSXDESRROMVER(ROMVER);
}

void LogDetectedPlatform(void)
{
    char rom_prefix[ROMVER_MODEL_PREFIX_LEN + 1];
    const char *platform_name;

#if defined(PSX)
    platform_name = g_is_psx_desr ? "PSX-DESR" : "PS2";
#else
    platform_name = "PS2";
#endif
    (void)platform_name;

    if (ROMVER[0] != '\0') {
        memcpy(rom_prefix, ROMVER, ROMVER_MODEL_PREFIX_LEN);
        rom_prefix[ROMVER_MODEL_PREFIX_LEN] = '\0';
    } else {
        strcpy(rom_prefix, "N/A");
    }

    DPRINTF("Detected platform: %s (ROMVER prefix: %s)\n", platform_name, rom_prefix);
}

void CleanUp(void)
{
    if (SplashRenderIsActive())
        SplashRenderEnd();

    sceCdInit(SCECdEXIT);
    // Keep config_buf alive so argv pointers remain valid during ELF load.
    PadDeinitPads();
}

// BIBLE: the pages' boxes sit over the logo's middle (the screen's when there is none)
#define PAGE_PAD_X 14
#define PAGE_PAD_Y 14

static int PageCenterX(int screen_w)
{
    if (SplashRenderGetLogoX() >= 0 && SplashRenderGetLogoWidth() > 0)
        return SplashRenderGetLogoX() + SplashRenderGetLogoWidth() / 2;
    return screen_w / 2;
}

static int PageCenterY(int screen_h)
{
    if (SplashRenderGetLogoY() >= 0 && SplashRenderGetLogoHeight() > 0)
        return SplashRenderGetLogoY() + SplashRenderGetLogoHeight() / 2;
    return screen_h / 2;
}

static void DrawCreditsSplashFrame(void)
{
    const char *lines[] = {
        "PLAYSTATION2 BASIC BOOTLOADER EXTENDED v"VERSION"."SUBVERSION"."PATCHLEVEL" - "STATUS"",
        "Compiled on "__DATE__" "__TIME__" COMMIT HASH: " COMMIT_HASH "",  
        "BY MATIAS ISRAELSON (EL_ISRA). EXTENDED BY R3Z3N and AI",
        "TUNED UP BY AKILLUMINATI47 WITH CLAUDE",
        "BASED ON SP193 OSD INIT SAMPLES",
        "THANKS: FJTRUJY, UYJULIAN, ASMBLUR, AKUHAK, PCM720,",
        "BERION, RIPTO, NUNO, GHOSTTOWNUS, KRAHJOHLITO, KRHACKEN",
        "PRESS START TO RETURN TO LAUNCH KEYS",
    };
    const u32 colors[] = {
        0x00ffff,
        0x00ffff,
        0xffffff,
        0xffffff,
        0xffffff,
        0xffffff,
        0xffffff,
        0x15d670,
    };
    const int line_count = (int)(sizeof(lines) / sizeof(lines[0]));
    int screen_w = SplashRenderGetScreenWidth();
    int screen_h = SplashRenderGetScreenHeight();
    int anchor_center_x;
    int block_h = (line_count - 1) * 16 + 7;
    int box_w = 0;
    int y;
    int i;

    // BIBLE: a page: its box over the dimmed logo, the launch keys put away
    for (i = 0; i < line_count; i++)
        if ((int)strlen(lines[i]) * 6 > box_w)
            box_w = (int)strlen(lines[i]) * 6;
    box_w += 2 * PAGE_PAD_X;
    anchor_center_x = PageCenterX(screen_w);
    y = PageCenterY(screen_h) - block_h / 2;
    if (y < 8 + PAGE_PAD_Y)
        y = 8 + PAGE_PAD_Y;

    SplashRenderSetHotkeysVisible(0);
    SplashRenderBeginFrame();
    SplashRenderPageBox(anchor_center_x - box_w / 2, y - PAGE_PAD_Y, box_w, block_h + 2 * PAGE_PAD_Y);
    for (i = 0; i < line_count; i++) {
        int line_w = (int)strlen(lines[i]) * 6;
        int x = anchor_center_x - (line_w / 2);

        if (x < 8)
            x = 8;
        if (x + line_w > screen_w - 8)
            x = screen_w - line_w - 8;
        if (x < 8)
            x = 8;

        SplashRenderDrawTextPxScaled(x, y + (i * 16), colors[i], lines[i], 1);
    }
    SplashRenderPresent();
}

int credits(void)
{
    int use_splash = SplashRenderIsActive();
    int prev_pad = ReadCombinedPadStatus_raw();

    if (use_splash)
        SplashRenderPageBegin();
    scr_clear();
    scr_printf("\n\n");
    if (!use_splash) {
        scr_printf("\tPlayStation2 Basic BootLoader Extended\n");
        scr_printf("\tBy Matias Israelson (AKA: El_isra). Extended by R3Z3N and AI\n");
        scr_printf("\tTuned up by akilluminati47 with Claude\n");
        scr_printf("\thttps://ps2homebrewstore.com - Modified - 9 Paths\n");
        scr_printf("\tv" VERSION "-" SUBVERSION "-" PATCHLEVEL " - " STATUS
#ifdef DEBUG
                   " - DEBUG"
#endif
                   "\n");
        scr_printf("\n"
                   "\n"
                   "\tBased on SP193 OSD Init samples.\n"
                   "\t\tall credits go to him\n"
                   "\tThanks to: fjtrujy, uyjulian, asmblur, AKuHAK, PCM720,\n"
                   "\t\tBERION, RIPTO, Nuno, GhostTownUS, KrahJohlito, krHACKen\n"
                   "\tbuild hash [" COMMIT_HASH "]\n"
                   "\t\tcompiled on "__DATE__
                   " "__TIME__
                   "\n"
#ifdef MX4SIO
                   " MX4SIO"
#endif
#ifdef HDD
                   " HDD "
#endif
                   "\n"
                   "\n"
                   "\tPress START to return to Launch Keys.\n");
    }

    while (1) {
        int pad = ReadCombinedPadStatus_raw();

        if (use_splash)
            DrawCreditsSplashFrame();
        if (!(prev_pad & PAD_START) && (pad & PAD_START))
            break;

        prev_pad = pad;
        delay_ms(CREDITS_POLL_INTERVAL_MS);
    }

    SplashRenderPageEnd();
    return 1;
}

// BIBLE: the launch keys page (L2 + R2 held at boot): every key's glyph with what it starts, in the splash's two
// rows turned into two columns, over the dimmed logo, so the setup can always be read. START goes back.
#define KEYS_PAGE_ROW_H 24
#define KEYS_PAGE_COL_W 300
#define KEYS_PAGE_TEXT_X 28 // from the glyph's left to the text
static const char *const g_keys_page_cols[2][8] = {
    {"TRIANGLE", "CIRCLE", "CROSS", "SQUARE", "L1", "R1", "START", "SELECT"},
    {"L2", "R2", "L3", "R3", "UP", "DOWN", "LEFT", "RIGHT"}};

static int KeyIndexByName(const char *name)
{
    int k;

    for (k = 0; k < KEY_COUNT; k++)
        if (!strcmp(KEYS_ID[k], name))
            return k;
    return -1;
}

// what key k starts: its NAME_ when there is one, else its first path, and "+N" for its further entries
static void KeyLaunchText(int k, char *out, size_t out_size, int max_chars)
{
    const char *first = NULL;
    int more = 0;
    int j;
    char buf[160];

    out[0] = '\0';
    if (k < 0)
        return;
    for (j = 0; j < CONFIG_KEY_INDEXES; j++) {
        const char *p = GLOBCFG.KEYPATHS[k][j];

        if (p == NULL || *p == '\0')
            continue;
        if (first == NULL)
            first = p;
        else
            more++;
    }
    if (first == NULL) {
        snprintf(out, out_size, "-");
        return;
    }
    if (GLOBCFG.KEYNAMES[k] != NULL && GLOBCFG.KEYNAMES[k][0] != '\0')
        snprintf(buf, sizeof(buf), "%s  %s", GLOBCFG.KEYNAMES[k], first);
    else
        snprintf(buf, sizeof(buf), "%s", first);
    if (more > 0) {
        size_t n = strlen(buf);
        snprintf(buf + n, sizeof(buf) - n, " +%d", more);
    }
    if ((int)strlen(buf) > max_chars && max_chars > 3) {
        buf[max_chars - 3] = '.';
        buf[max_chars - 2] = '.';
        buf[max_chars - 1] = '.';
        buf[max_chars] = '\0';
    }
    snprintf(out, out_size, "%s", buf);
}

static void DrawKeysPageFrame(void)
{
    const char *title = "LAUNCH KEYS";
    const char *footer = "PRESS START TO RETURN TO LAUNCH KEYS";
    int screen_w = SplashRenderGetScreenWidth();
    int screen_h = SplashRenderGetScreenHeight();
    int glyph = SplashRenderGlyphSize();
    int max_chars = (KEYS_PAGE_COL_W - KEYS_PAGE_TEXT_X - 8) / 6;
    int box_w = 2 * KEYS_PAGE_COL_W + 2 * PAGE_PAD_X;
    int box_h = 7 + 12 + 7 + 14 + 8 * KEYS_PAGE_ROW_H + 8 + 7;
    int cx = PageCenterX(screen_w);
    int box_x;
    int box_y;
    int y;
    int c;
    int r;
    char text[96];

    if (box_w > screen_w - 16)
        box_w = screen_w - 16;
    box_x = cx - box_w / 2;
    if (box_x < 8)
        box_x = 8;
    box_y = PageCenterY(screen_h) - (box_h + 2 * PAGE_PAD_Y) / 2;
    if (box_y < 8)
        box_y = 8;

    SplashRenderSetHotkeysVisible(0);
    SplashRenderBeginFrame();
    SplashRenderPageBox(box_x, box_y, box_w, box_h + 2 * PAGE_PAD_Y);
    y = box_y + PAGE_PAD_Y;
    SplashRenderDrawTextPxScaled(cx - (int)strlen(title) * 3, y, 0x00ffff, title, 1);
    y += 7 + 12;
    KeyLaunchText(0, text, sizeof(text), (box_w - 2 * PAGE_PAD_X) / 6 - 6);
    SplashRenderDrawTextPxScaled(box_x + PAGE_PAD_X, y, 0xffffff, "AUTO:", 1);
    SplashRenderDrawTextPxScaled(box_x + PAGE_PAD_X + 36, y, 0xc0c0c0, text, 1);
    y += 7 + 14;
    for (c = 0; c < 2; c++) {
        int col_x = box_x + PAGE_PAD_X + c * KEYS_PAGE_COL_W;

        for (r = 0; r < 8; r++) {
            const char *key = g_keys_page_cols[c][r];
            int row_y = y + r * KEYS_PAGE_ROW_H;

            KeyLaunchText(KeyIndexByName(key), text, sizeof(text), max_chars);
            if (!SplashRenderDrawGlyph(SplashRenderGlyphForKey(key), col_x, row_y))
                SplashRenderDrawTextPxScaled(col_x, row_y + (glyph - 7) / 2, 0xffffff, key, 1);
            SplashRenderDrawTextPxScaled(col_x + KEYS_PAGE_TEXT_X, row_y + (glyph - 7) / 2,
                                         strcmp(text, "-") ? 0xffffff : 0x808080, text, 1);
        }
    }
    y += 8 * KEYS_PAGE_ROW_H + 8;
    SplashRenderDrawTextPxScaled(cx - (int)strlen(footer) * 3, y, 0x15d670, footer, 1);
    SplashRenderPresent();
}

int keyspage(void)
{
    int use_splash = SplashRenderIsActive();
    int prev_pad = ReadCombinedPadStatus_raw();
    char text[96];
    int k;

    if (use_splash)
        SplashRenderPageBegin();
    else {
        scr_clear();
        scr_printf("\n\n\tLAUNCH KEYS\n\n");
        for (k = 0; k < KEY_COUNT; k++) {
            KeyLaunchText(k, text, sizeof(text), 60);
            scr_printf("\t%-9s %s\n", KEYS_ID[k], text);
        }
        scr_printf("\n\tPress START to return to Launch Keys.\n");
    }

    while (1) {
        int pad = ReadCombinedPadStatus_raw();

        if (use_splash)
            DrawKeysPageFrame();
        if (!(prev_pad & PAD_START) && (pad & PAD_START))
            break;

        prev_pad = pad;
        delay_ms(CREDITS_POLL_INTERVAL_MS);
    }

    SplashRenderPageEnd();
    while (ReadCombinedPadStatus_raw() & PAD_START)
        delay_ms(CREDITS_POLL_INTERVAL_MS);
    return 1;
}

void runOSDNoUpdate(void)
{
    char *args[3] = {"SkipHdd", "BootBrowser", "SkipMc"};
    CleanUp();
    SifExitCmd();
    ExecOSD(3, args);
}

void LoaderRunEmergencyMode(const char *reason)
{
    const char *rescue_path = "mass:/RESCUE.ELF";
    int rescue_family_ready = 0;

    if (!SplashRenderIsActive()) {
        int emergency_logo_disp = normalize_logo_display(GLOBCFG.LOGO_DISP);

        if (emergency_logo_disp < 1)
            emergency_logo_disp = 1;
        SplashRenderSetVideoMode(GLOBCFG.VIDEO_MODE, g_native_video_mode);
        SplashRenderTextBody(emergency_logo_disp, g_is_psx_desr);
    }

    SplashDrawEmergencyModeStatus(reason);
    while (1) {
        char *resolved_rescue_path = NULL;

        delay_ms(EMERGENCY_RESCUE_POLL_INTERVAL_MS);

        // Match launch-entry behavior: ensure BDM family is active first.
        // If booted on MC/MMCE/HDD, this may reboot IOP once to load USB stack.
        if (!rescue_family_ready) {
            int ensure_ready = LoaderEnsurePathFamilyReady(rescue_path);

            if (ensure_ready < 0) {
                DPRINTF("Emergency mode: failed to ready path family for '%s' (ret=%d), retrying\n",
                        rescue_path,
                        ensure_ready);
                continue;
            }

            rescue_family_ready = 1;
            DPRINTF("Emergency mode: path family ready for '%s'\n", rescue_path);
        }

        resolved_rescue_path = CheckPath(rescue_path);
        if (resolved_rescue_path != NULL &&
            *resolved_rescue_path != '\0' &&
            exist(resolved_rescue_path)) {
            if (SplashRenderIsActive())
                SplashRenderEnd();
            CleanUp();
            RunLoaderElf(resolved_rescue_path, NULL, 0, NULL);
        }
    }
}

void EMERGENCY(void)
{
    LoaderRunEmergencyMode(NULL);
}
