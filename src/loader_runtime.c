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
        SplashRenderHandoff(); // BIBLE: the sky alone left on screen for the program launched

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

// BIBLE: the launch keys page (L2 + R2 held at boot): upstream's button sheet down the left with what each key starts
// beside it (the LOGO_DISPLAY 3 lines, one column, so a long path fits), over the dimmed logo. START goes back.
static const char *const g_keys_page_order[KEY_COUNT] = {"AUTO", "TRIANGLE", "CIRCLE", "CROSS", "SQUARE", "UP", "DOWN",
    "LEFT", "RIGHT", "L1", "L2", "L3", "R1", "R2", "R3", "SELECT", "START"}; // the sheet's rows, top down
#define KEYS_PAGE_MAX_CHARS 70

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

static void DrawKeysPageFrame(const char *const lines[KEY_COUNT])
{
    const char *footer = "PRESS START TO RETURN TO LAUNCH KEYS";
    int screen_w = SplashRenderGetScreenWidth();
    int screen_h = SplashRenderGetScreenHeight();

    SplashRenderPageSheet(1);
    SplashRenderSetHotkeysVisible(1);
    SplashRenderBeginFrame();
    SplashRenderHotkeyLines(3, lines); // upstream's lines beside the sheet
    SplashRenderDrawTextPxScaled(screen_w / 2 - (int)strlen(footer) * 3, screen_h - 20, 0x15d670, footer, 1);
    SplashRenderPresent();
}

int keyspage(void)
{
    int use_splash = SplashRenderIsActive();
    int prev_pad = ReadCombinedPadStatus_raw();
    char text[160];
    static char line_buf[KEY_COUNT][KEYS_PAGE_MAX_CHARS + 1];
    const char *lines[KEY_COUNT];
    int k;

    for (k = 0; k < KEY_COUNT; k++) {
        KeyLaunchText(KeyIndexByName(g_keys_page_order[k]), line_buf[k], sizeof(line_buf[k]), KEYS_PAGE_MAX_CHARS);
        lines[k] = strcmp(line_buf[k], "-") ? line_buf[k] : "";
    }

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
            DrawKeysPageFrame(lines);
        if (!(prev_pad & PAD_START) && (pad & PAD_START))
            break;

        prev_pad = pad;
        delay_ms(CREDITS_POLL_INTERVAL_MS);
    }

    SplashRenderPageEnd();
    SplashRenderSetHotkeysVisible(0);
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
            CleanUp();
            RunLoaderElf(resolved_rescue_path, NULL, 0, NULL);
        }
    }
}

void EMERGENCY(void)
{
    LoaderRunEmergencyMode(NULL);
}
