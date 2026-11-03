#ifndef LOADER_BOOTSND_H
#define LOADER_BOOTSND_H

#include <tamtypes.h>

// BIBLE: RIPPS2's boot sound, read from beside BIBLE's config while the splash shows and handed to RIPPS2 in RAM
// (docs/boot-sound-handoff.md is the contract RIPPS2 reads it by)
#define BOOTSND_FILE "boot.adp"
#define BOOTSND_ADDR 0x01400000u    // where the sound waits for RIPPS2: above its unpacked program, below its packed one
#define BOOTSND_MAX (1024 * 1024)   // RIPPS2's own limit for one sound (SFX_MAX_BYTES)
#define BOOTSND_CHUNK (32 * 1024)   // one card read: about a sixth of a second on a real memory card

int LoaderIsRipps2Path(const char *path);  // the file's name starts with RIPPS2
void LoaderBootSoundPrime(void);           // after the config: starts reading when the AUTO entry is RIPPS2
void LoaderBootSoundPump(void);            // once a frame: takes a piece that has come in, asks for the next
void LoaderBootSoundQuiesce(void);         // waits out a piece in flight, so the card is free for anything else
void LoaderBootSoundDrop(void);            // before an IOP reset or an emergency launch: an unfinished read is let go
void LoaderBootSoundLaunch(const char *path); // at an ELF launch: RIPPS2 gets the rest read, any other program none
int LoaderBootSoundAppArgs(char *args[], int max); // RIPPS2's -bible-home= and -bible-bootsnd= arguments
int LoaderBootSoundKeep(u32 *addr, u32 *size);     // the RAM the stage 2 loader must not clear (1 when there is some)

#endif
