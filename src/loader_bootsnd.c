// BIBLE: RIPPS2's boot sound, primed. RIPPS2's Boot Sound On (fast) keeps a copy of boot.adp on a memory card so its
// boot can read it before any drive is up; started from an SD2PSX, USB or the HDD, RIPPS2 is on no card, so the copy
// lives beside BIBLE's config instead (mc?:/SYS-CONF/boot.adp, the folder BIBLE read PS2BBL.INI from). BIBLE reads it
// while its splash shows, a piece a frame with libmc's asynchronous reads (the splash keeps its pace), into RAM that
// survives the launch, and tells RIPPS2 where it is in two arguments:
//   -bible-home=mc0:/SYS-CONF/                       the folder, where On (fast) writes the copy and RIPPS2 reads it
//   -bible-bootsnd=mem:<addr>:<size>:<crc32>          the sound in RAM, all eight-digit hex
// The stage 2 loader keeps that RAM when it clears memory for the ELF (its 'K' flag), RIPPS2 checks the CRC and plays
// it with its first frame; a sound that did not survive is read from the card again. docs/boot-sound-handoff.md.
#include "main.h"
#include "loader_bootsnd.h"

#define MC_O_RDONLY 0x0001 // MCMAN's own open flag (newlib's O_RDONLY is 0)
#define BOOTSND_ARG_HOME "-bible-home="
#define BOOTSND_ARG_SOUND "-bible-bootsnd="

enum {
    BS_IDLE = 0, // not asked for yet
    BS_OFF,      // nothing to read, or the read was let go
    BS_READING,
    BS_READY,    // all of it in RAM, checked
};

static int s_state = BS_IDLE;
static int s_port = -1;
static int s_fd = -1;
static int s_size = 0;
static int s_have = 0;
static int s_inflight = 0; // bytes asked for and not yet in
static u32 s_crc = 0;
static u64 s_t0 = 0;
static char s_home[64] = ""; // "mc0:/SYS-CONF/"

int LoaderIsRipps2Path(const char *path)
{
    const char *base = path;
    const char *p;

    if (path == NULL)
        return 0;
    for (p = path; *p != '\0'; p++)
        if (*p == '/' || *p == '\\' || *p == ':')
            base = p + 1;
    return ci_starts_with(base, "RIPPS2");
}

// The folder of the config BIBLE read, when it is on a memory card: home gets "mcN:/DIR/", card_path "/DIR/boot.adp"
static int bootsnd_home(char *home, size_t home_size, char *card_path, size_t card_size, int *port)
{
    const char *cfg = LoaderGetResolvedConfigPath();
    const char *slash;
    const char *dir;
    size_t dir_len;

    if (cfg == NULL || (cfg[0] != 'm' && cfg[0] != 'M') || (cfg[1] != 'c' && cfg[1] != 'C') ||
        (cfg[2] != '0' && cfg[2] != '1') || cfg[3] != ':')
        return 0;
    dir = cfg + 4;
    slash = strrchr(dir, '/');
    dir_len = (slash != NULL) ? (size_t)(slash - dir + 1) : 0;
    if (snprintf(home, home_size, "mc%c:%s%.*s", cfg[2], (dir[0] == '/') ? "" : "/", (int)dir_len, dir) >= (int)home_size)
        return 0;
    if (snprintf(card_path, card_size, "%s%s", home + 4, BOOTSND_FILE) >= (int)card_size)
        return 0;
    *port = cfg[2] - '0';
    return 1;
}

// The AUTO key's first entry, as the launch tries it first
static int auto_entry_is_ripps2(void)
{
    int j;

    for (j = 0; j < CONFIG_KEY_INDEXES; j++) {
        const char *entry = GLOBCFG.KEYPATHS[0][j];

        if (entry != NULL && *entry != '\0')
            return LoaderIsRipps2Path(entry);
    }
    return 0;
}

// The CRC-32 zlib and the PNG format use (RIPPS2 checks with zlib's crc32())
static u32 bootsnd_crc32(const unsigned char *p, int n)
{
    static u32 table[256];
    static int table_ready = 0;
    u32 c;
    int i, k;

    if (!table_ready) {
        for (i = 0; i < 256; i++) {
            c = (u32)i;
            for (k = 0; k < 8; k++)
                c = (c & 1) ? 0xEDB88320u ^ (c >> 1) : c >> 1;
            table[i] = c;
        }
        table_ready = 1;
    }
    c = 0xFFFFFFFFu;
    for (i = 0; i < n; i++)
        c = table[(c ^ p[i]) & 0xFF] ^ (c >> 8);
    return c ^ 0xFFFFFFFFu;
}

static void bootsnd_close(void)
{
    int ret;

    if (s_fd >= 0 && mcClose(s_fd) == 0)
        mcSync(0, NULL, &ret);
    s_fd = -1;
}

static void bootsnd_fail(const char *why)
{
    DPRINTF("Boot sound: %s after %d of %d bytes; RIPPS2 reads it from the card itself\n", why, s_have, s_size);
    bootsnd_close();
    s_inflight = 0;
    s_state = BS_OFF;
}

// The hand-off RAM is above BIBLE's own heap (which stays a few MB)
static int bootsnd_ram_free(void)
{
    return (u32)sbrk(0) < BOOTSND_ADDR;
}

static void bootsnd_complete(void)
{
    const unsigned char *data = (const unsigned char *)BOOTSND_ADDR;

    bootsnd_close();
    if (memcmp(data, "APCM", 4) != 0) {
        bootsnd_fail("not an .adp (no APCM header)");
        return;
    }
    if (!bootsnd_ram_free()) {
        bootsnd_fail("BIBLE's heap reached the hand-off RAM");
        return;
    }
    s_crc = bootsnd_crc32(data, s_size);
    s_state = BS_READY;
    DPRINTF("Boot sound: %d bytes from %s%s in %u ms, crc %08x\n", s_size, s_home, BOOTSND_FILE,
            (unsigned int)(Timer() - s_t0), (unsigned int)s_crc);
}

// A piece came in: ret is what the card read gave
static void bootsnd_piece(int ret)
{
    if (ret != s_inflight) {
        bootsnd_fail("a card read came up short");
        return;
    }
    s_have += ret;
    s_inflight = 0;
    if (s_have >= s_size)
        bootsnd_complete();
}

static void bootsnd_ask(void)
{
    int n = s_size - s_have;

    if (n > BOOTSND_CHUNK)
        n = BOOTSND_CHUNK;
    if (mcRead(s_fd, (void *)(BOOTSND_ADDR + (u32)s_have), n) != 0) {
        bootsnd_fail("the card would not take a read");
        return;
    }
    s_inflight = n;
}

void LoaderBootSoundPrime(void)
{
    char card_path[80];
    int ret = -1, size = -1;

    if (s_state != BS_IDLE)
        return;
    s_state = BS_OFF;
#if !EGSM_BUILD && !BOOTSND_STAGE2
    // No stage 2 loader in this build (the plain memory card / USB one, which has no fileXio for it): the launch goes
    // through ps2sdk's loader, which wipes user memory, so a read here would only make the launch wait. RIPPS2 still
    // gets -bible-home= and reads the copy from the card itself.
    return;
#endif
    if (!auto_entry_is_ripps2() ||
        !bootsnd_home(s_home, sizeof(s_home), card_path, sizeof(card_path), &s_port) || !bootsnd_ram_free())
        return;
    s_t0 = Timer();
    if (mcOpen(s_port, 0, card_path, MC_O_RDONLY) != 0 || mcSync(0, NULL, &ret) != 1 || ret < 0) {
        DPRINTF("Boot sound: no %s%s (%d)\n", s_home, BOOTSND_FILE, ret);
        return;
    }
    s_fd = ret;
    if (mcSeek(s_fd, 0, SEEK_END) != 0 || mcSync(0, NULL, &size) != 1 || size < 32 || size > BOOTSND_MAX ||
        mcSeek(s_fd, 0, SEEK_SET) != 0 || mcSync(0, NULL, &ret) != 1 || ret != 0) {
        s_size = size;
        bootsnd_fail("the size will not do");
        return;
    }
    s_size = size;
    s_have = 0;
    s_state = BS_READING;
    DPRINTF("Boot sound: reading %d bytes from %s%s while the splash shows\n", s_size, s_home, BOOTSND_FILE);
    bootsnd_ask();
}

void LoaderBootSoundPump(void)
{
    int cmd, ret = -1, done;

    if (s_state != BS_READING)
        return;
    if (s_inflight) {
        done = mcSync(1, &cmd, &ret);
        if (done == 0)
            return; // still on its way
        if (done != 1) {
            bootsnd_fail("the card read was lost");
            return;
        }
        bootsnd_piece(ret);
    }
    if (s_state == BS_READING && !s_inflight)
        bootsnd_ask();
}

void LoaderBootSoundQuiesce(void)
{
    int cmd, ret = -1;

    if (s_state != BS_READING || !s_inflight)
        return;
    if (mcSync(0, &cmd, &ret) != 1) {
        bootsnd_fail("the card read was lost");
        return;
    }
    bootsnd_piece(ret);
}

void LoaderBootSoundDrop(void)
{
    if (s_state != BS_READING)
        return; // a sound already in RAM stays: an IOP reset does not touch it
    LoaderBootSoundQuiesce();
    if (s_state == BS_READING)
        bootsnd_fail("let go before an IOP reset");
}

void LoaderBootSoundLaunch(const char *path)
{
    u64 t_wait;

    if (s_state != BS_READING)
        return;
    if (!LoaderIsRipps2Path(path)) {
        LoaderBootSoundDrop();
        return;
    }
    // the user, 11/03: wait for the rest and hand it all over
    t_wait = Timer();
    while (s_state == BS_READING) {
        if (!s_inflight)
            bootsnd_ask();
        LoaderBootSoundQuiesce();
    }
    DPRINTF("Boot sound: the launch waited %u ms for the rest\n", (unsigned int)(Timer() - t_wait));
    (void)t_wait;
}

int LoaderBootSoundAppArgs(char *args[], int max)
{
    static char home_arg[sizeof(BOOTSND_ARG_HOME) + sizeof(s_home)];
    static char sound_arg[sizeof(BOOTSND_ARG_SOUND) + 32];
    char card_path[80];
    int port, n = 0;

    if (s_home[0] == '\0' && !bootsnd_home(s_home, sizeof(s_home), card_path, sizeof(card_path), &port))
        return 0; // BIBLE's config is not on a memory card: RIPPS2 keeps its own place for the copy
    if (n < max) {
        snprintf(home_arg, sizeof(home_arg), "%s%s", BOOTSND_ARG_HOME, s_home);
        args[n++] = home_arg;
    }
    if (s_state == BS_READY && n < max) {
        snprintf(sound_arg, sizeof(sound_arg), "%smem:%08X:%08X:%08X", BOOTSND_ARG_SOUND, (unsigned int)BOOTSND_ADDR,
                 (unsigned int)s_size, (unsigned int)s_crc);
        args[n++] = sound_arg;
    }
    return n;
}

int LoaderBootSoundKeep(u32 *addr, u32 *size)
{
    if (s_state != BS_READY)
        return 0;
    *addr = BOOTSND_ADDR;
    *size = (u32)s_size;
    return 1;
}
