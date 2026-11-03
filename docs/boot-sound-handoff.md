# The boot sound hand-off, and RIPPS2's BIBLE menu

BIBLE branch `bible-boot-sound-sky` (11/03). This is the contract between BIBLE and RIPPS2 for the boot sound, and
the spec for the RIPPS2 side, which is a later RIPPS2 build (nothing here changes RIPPS2 by itself).

## Why

RIPPS2's **Boot Sound: On (fast)** keeps a copy of `boot.adp` on a memory card, so the boot reads it before any
drive is up and the sound plays with the pillars' first frame. It copies it beside RIPPS2 on the card RIPPS2 starts
from. Started by BIBLE from an SD2PSX (`mmce?:/APPS/RIPPS2.ELF`), USB or the HDD, RIPPS2 is on no card, so there is
nowhere for the copy and the sound waits for the drive, seconds after the pillars.

So the copy lives beside BIBLE's install instead, and BIBLE reads it while its splash shows and hands it to RIPPS2
in RAM.

## Where the copy lives

`<the folder BIBLE read its config from>boot.adp`, on a memory card only. With BIBLE installed the usual way that is
**`mc0:/SYS-CONF/boot.adp`** (or `mc1:`), next to `PS2BBL.INI`. On an SD2PSX it is the BOOT card's SYS-CONF.

- The name is lowercase `boot.adp`, RIPPS2's own name for the sound (the memory card's file system keeps case).
- A config read from anywhere else (CWD `CONFIG.INI`, USB, MMCE, HDD) means no copy and no `-bible-home=`.

## What BIBLE does

1. After the config is read, if the **AUTO key's first entry** is RIPPS2 (its file name starts with `RIPPS2`, any
   case) and `boot.adp` is there (32 bytes to 1 MB), BIBLE opens it with libmc and starts reading (the MMCE, MX4SIO
   and HDD builds only; see the table below).
2. The read goes in 32 KB pieces with libmc's asynchronous `mcRead`: one piece is in flight while the splash draws
   its frames and counts down, so the splash keeps its pace (`LoaderBootSoundPump`, once a frame).
3. Anything else that may touch the card first waits out the piece in flight (`LoaderBootSoundQuiesce`): a key's
   launch, the AUTO launch, the video mode and launch keys pages. An IOP reset for a launch on another drive family
   and the rescue mode let an unfinished read go (`LoaderBootSoundDrop`; a sound already in RAM stays).
4. At an ELF launch: for RIPPS2, BIBLE **waits for whatever is still unread** (the user's choice, 11/03) and hands it
   all over; for any other program the read is let go.
5. The sound sits at **`0x01400000`** (20 MB in), checked for the `APCM` header, with a CRC-32 over the whole file.

### The cost at 0 ms (say this wherever the setting is offered)

The read only hides behind time BIBLE spends anyway: the splash's countdown (`KEY_READ_WAIT_TIME`) and its frames.
A 360 KB `boot.adp` takes about 2 s on a real memory card. With `KEY_READ_WAIT_TIME = 6000` it is long done before
the launch. With `KEY_READ_WAIT_TIME = 0` or `LOGO_DISPLAY = 0` (the config RIPPS2's Manage writes today) there is
no countdown to hide behind, so **the whole read comes before RIPPS2 starts**: the sound still plays with RIPPS2's
first frame, but that frame comes about 2 s later. **Silent is the fastest boot**: no `boot.adp` beside BIBLE's
config (RIPPS2's Boot Sound Off) means BIBLE reads nothing and waits for nothing.

## The arguments RIPPS2 gets

Added only when the launched file's name starts with `RIPPS2`, after BIBLE's own launch-control arguments are taken
(a trailing `-gsm=` still works), and only when everything still fits what ExecPS2 carries (16 arguments, 256 bytes;
otherwise both are left out and the log says so):

| Argument | When | Meaning |
|---|---|---|
| `-bible-home=mc0:/SYS-CONF/` | BIBLE's config is on a memory card | The folder BIBLE read its config from, ending in `/`. Where **On (fast)** writes `boot.adp`, and where RIPPS2 reads it when the RAM copy is missing or bad. |
| `-bible-bootsnd=mem:01400000:00058C40:1A2B3C4D` | BIBLE read the whole sound | `mem:<address>:<size>:<crc32>`, each 8 hex digits. CRC-32 as zlib's `crc32()` (polynomial 0xEDB88320). The address is 64-byte aligned; the size is at most 1 MB. |

Both are plain `argv[]` entries after `argv[0]`. RIPPS2's `main` only looks at `argv[4]` when `argc >= 5`
(`mini` / `bdm` auto-launch), which these never reach.

### Which builds hand it over in RAM

| Build | RAM hand-off | Why |
|---|---|---|
| PS2_MMCE, PS2_MX4SIO, PS2_HDD | yes | They load fileXio, so they embed BIBLE's stage 2 loader (built without eGSM, `BOOTSND_STAGE2`) and start RIPPS2-with-a-sound through it. |
| PS2 (memory card / USB) | no, `-bible-home=` only | No fileXio, which the stage 2 loader's DEV9 shutdown needs (fileXio's init would wait forever). BIBLE reads nothing and never waits; RIPPS2 reads `<home>boot.adp` itself. |

Every other launch, in every build, still goes through ps2sdk's `LoadELFFromFile`, unchanged.

### Why the RAM survives

- ps2sdk's own ELF loader (`LoadELFFromFile`) runs `wipeUserMem()` over all user RAM (`0x00100000` to the end)
  before it loads: the lab caught it zeroing the sound the moment it started (take C below). So a RIPPS2 launch with
  a sound goes through **BIBLE's stage 2 loader** instead, which also clears user memory but has a new **`K`** flag
  (`-la=K...`, with `mem:<addr>:<size>` as the argument nearest `-la=`): it leaves that range as it is and does not
  pass it on. The range is exactly the sound. BIBLE adds **`R`** with it, so the IOP is reset after the ELF is loaded,
  as ps2sdk's loader does for every launch.
- RIPPS2's packed ELF (build 138: one segment at `0x01A5AEF0`..`0x01D05C60`) is loaded above it; the LZMA stub
  unpacks to `0x00100000`..`0x007A8D14` (the packed header's section size) plus its BSS, below it (the header's next
  field, read as the BSS, puts the end near `0x00A4E000`). The stack is at the top of RAM.
- RIPPS2's heap starts at the end of its BSS and grows up: it reaches 20 MB only after about 9.5 MB of allocations,
  so RIPPS2 must copy the sound out **before anything big is allocated**, at the top of `main`.
- If a later RIPPS2 grows enough to overlap (unpacked end past `0x01400000`, or packed start below `0x01500000`),
  the CRC fails and RIPPS2 falls back to reading the card. Nothing breaks; the fast path is just lost. Move
  `BOOTSND_ADDR` in `include/loader_bootsnd.h` then.

## The RIPPS2 side (spec for a later build)

### Reading the hand-off

1. **First thing in `main`**, before `reset()`: scan `argv` for `-bible-home=` and `-bible-bootsnd=`. Keep the home
   in a global (for example `gBibleHome`).
2. For `-bible-bootsnd=mem:A:S:C`: accept only `0x00100000 <= A`, `A + S <= 0x02000000`, `32 <= S <= SFX_MAX_BYTES`.
   Compute `crc32(0, (void *)A, S)`; on a match, and with `sfxHeaderMs()` non-zero, `memalign(64, S)` and copy.
   Hand the buffer to the boot sound as `sfxBootEarlyWork` would after `sfxRead` (`sfx_files[SFX_BOOT]` buffer,
   size, `baked = 0`, `duration_ms`), with `sfxBootEarly = SFX_EARLY_READ`, so `sfxBootStart` queues the upload on
   the IO worker as it does now (the IOP reset in between does not matter: the data is in EE RAM). Skip the card
   read in `sfxBootEarlyWork` when this already happened.
3. Bad CRC, bad header, out of range, or no argument: nothing changes; the boot reads the copy from the card as below.
4. Write `ripps2Diag` lines for each case (taken, CRC mismatch, not passed), so DIAG.TXT says which path ran.

### Where On (fast) writes and reads

- `sfxCardBootPath`: when `gBibleHome` is set, the copy is `<gBibleHome>boot.adp` (read at boot when the RAM copy is
  missing, and written by **On (fast)** and the BIOS Sounds rip offer). Without it, as now: beside RIPPS2 on its card.
- Choosing **Off** or **On** (not fast) removes `<gBibleHome>boot.adp`, so BIBLE stops reading it and stops waiting.
- STATUS's boot sound line (`sfxBootSoundWhere`) names `<gBibleHome>boot.adp` and says "handed over by BIBLE" when
  the RAM copy was taken.
- The setting's help text says the cost: "BIBLE reads it while its splash counts down. With BIBLE's wait at 0 ms it
  reads it before RIPPS2 starts (about 2 s). Off is the fastest boot."

### A BIBLE menu (the user, 11/03)

When BIBLE is detected (RIPPS2 was started with `-bible-home=`, or Manage finds BIBLE installed on a card),
**Settings > General > Boot Loader** opens a BIBLE menu, and **Manage** (install, bind, BOOT LOCK) is one item in it
instead of the only one. Without BIBLE it stays as it is. Every key of BIBLE's config is offered, edited in place in
`PS2BBL.INI` (the file in `-bible-home=`, else Manage's `mc?:/SYS-CONF/PS2BBL.INI`):

- **Background**: `BIBLE_BACKGROUND` Auto / Sky / Black.
- **Sky colour**: `BIBLE_COLOR` unset (follows the Color Theme through `ripps2_bible_sky`) or a fixed one.
- **Video Mode**: `VIDEO_MODE` (Auto follows RIPPS2's own), **Widescreen**: `BIBLE_WIDESCREEN`.
- **Wait**: `KEY_READ_WAIT_TIME` (0 ms to 10 s), with the boot sound note above.
- **Splash**: `LOGO_DISPLAY`, `BIBLE_GLYPHS`, `BIBLE_INFO`.
- **Boot sound**: the same three choices as Audio's Boot Sound, here because the copy lives with BIBLE.
- **Disc and history**: `EJECT_TRAY`, `DISC_STOP`, `OSDHISTORY_READ`, `APP_GAMEID`, `CDROM_DISABLE_GAMEID`.
- **Launch keys**: for each button (AUTO, the face buttons, L1 to R3, START, SELECT, the d-pad), its name
  (`NAME_<KEY>`) and up to ten paths (`LK_<KEY>_E1` to `E10`) picked with the Memory Files browser (choose an ELF
  instead of typing a path), plus `ARG_<KEY>_E<n>`. The page also says: hold **L2 + R2** at power on and BIBLE pauses
  on its launch keys page showing every key's current paths, so the user can check what each button starts.
- **Edits keep the file hand-editable**: change only the lines of the keys touched (add a missing key under BIBLE's
  section), keep comments and unknown keys, write a temporary file and rename it over the old one.
- Other boot loaders' configs (FMCB, OSDMenu, El Isra's PS2BBL) stay with BOOT LOCK or Memory Files.

## Config template audit (11/03)

| | PS2BBL Extended's template (BIBLE's `release/` before) | RIPPS2 Manage's config (`blBibleConfig`) | BIBLE's template now |
|---|---|---|---|
| AUTO | E1, E2 empty; OSDMenu, FMCB 1.966 to 1.8C, BOOT2, `$OSDSYS` | `$OSDSYS` (BOOT LOCK puts RIPPS2 first) | **E1 `mc?:/RIPPS2/RIPPS2.ELF`, E2 `mmce?:/APPS/RIPPS2.ELF`**, then the same list |
| TRIANGLE | wLE ISR (MMCE, MX4SIO, exFAT) | `$OSDSYS` (the browser) | unchanged |
| Wait / splash | 6000 ms, LOGO_DISPLAY 3 | 0 ms, LOGO_DISPLAY 0 | unchanged, plus BIBLE's keys with notes |
| BIBLE keys | none | none | `VIDEO_MODE`, `BIBLE_BACKGROUND`, `BIBLE_COLOR` (commented), `BIBLE_GLYPHS`, `BIBLE_INFO`, `BIBLE_WIDESCREEN` |
| Notes | none | the hold keys | L2 + R2 launch keys page, TRIANGLE + CROSS video page, the boot sound's cost at 0 ms |

The built-in defaults (no config found) also try the two RIPPS2 paths first. For RIPPS2's Manage config: with the
boot sound hand-off, its `KEY_READ_WAIT_TIME = 0` and `LOGO_DISPLAY = 0` mean the read is not hidden (see above);
the BIBLE menu is where the user picks.

## Checking it

- PCSX2 with an EE_SIO build (`gh workflow run CI.yml -R akilluminati47/BIBLE --ref <branch> -f printf=EE_SIO`):
  the log says `Boot sound: reading N bytes`, `Boot sound: N bytes from mc0:/SYS-CONF/boot.adp in T ms, crc X`,
  `the launch waited T ms`, the stage 2 argv with `mem:01400000:...` and `-la=KR`.
- While it runs, PINE (`EnablePINE`, slot 28012) reads EE RAM at `0x01400000`. Each PINE connection is a line in
  `emulog.txt`, so a poller that connects once per read lines its reads up with the emulator's clock exactly.

### Lab results (11/03, PCSX2, RIPPS2 t138b on the card)

- Take A (PS2 build, before the stage 2 change): config `mc0:/SYS-CONF/PS2BBL.INI`, RIPPS2's settings found in
  `mc0:/RIPPS2` (the new fallback for an AUTO entry with none beside it), Blood sky, NTSC. `boot.adp` (367,904 bytes)
  read in 623 ms while the 3 s countdown ran, CRC `0c94373a` (the file's own). RIPPS2 started with the two arguments.
- Take B: AUTO not RIPPS2 (`$OSDSYS`): black splash in the console's own mode, no settings read, no sound read.
- Take C: `BIBLE_BACKGROUND = BLANK` with RIPPS2 as AUTO: black splash, RIPPS2's NTSC mode. Polling RAM four times a
  second showed the sound intact until ps2sdk's loader started, and zero from its first moments (`wipeUserMem`),
  which is why the stage 2 path above exists.
