// BIBLE: where RIPPS2's boot sound lives. RIPPS2's Boot Sound On (fast) keeps a copy of boot.adp on a memory card so its
// boot can read it before any drive is up; started from an SD2PSX, USB or the HDD, RIPPS2 is on no card, so the copy
// lives beside BIBLE's config instead (mc?:/SYS-CONF/boot.adp, the folder BIBLE read PS2BBL.INI from). BIBLE tells RIPPS2
// the folder and never opens the file:
//   -bible-home=mc0:/SYS-CONF/     the folder, where On (fast) writes the copy and RIPPS2 reads it
// BIBLE 3282396 also read the sound during its splash and handed it over in RAM: docs/boot-sound-handoff.md says why that
// went.
#include "main.h"
#include "loader_bootsnd.h"

#define BOOTSND_ARG_HOME "-bible-home="

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

// The folder of the config BIBLE read, when it is on a memory card: "mcN:/DIR/"
static int bootsnd_home(char *home, size_t home_size)
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
    return snprintf(home, home_size, "mc%c:%s%.*s", cfg[2], (dir[0] == '/') ? "" : "/", (int)dir_len, dir) < (int)home_size;
}

int LoaderBootSoundAppArgs(char *args[], int max)
{
    static char home_arg[sizeof(BOOTSND_ARG_HOME) + sizeof(s_home)];

    if (max < 1 || (s_home[0] == '\0' && !bootsnd_home(s_home, sizeof(s_home))))
        return 0; // BIBLE's config is not on a memory card: RIPPS2 keeps its own place for the copy
    snprintf(home_arg, sizeof(home_arg), "%s%s", BOOTSND_ARG_HOME, s_home);
    args[0] = home_arg;
    return 1;
}
