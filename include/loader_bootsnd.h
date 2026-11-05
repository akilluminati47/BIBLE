#ifndef LOADER_BOOTSND_H
#define LOADER_BOOTSND_H

// BIBLE: tells RIPPS2 where its boot sound lives, beside BIBLE's config (docs/boot-sound-handoff.md). BIBLE never reads it.
int LoaderIsRipps2Path(const char *path);          // the file's name starts with RIPPS2
int LoaderBootSoundAppArgs(char *args[], int max); // RIPPS2's -bible-home= argument

#endif
