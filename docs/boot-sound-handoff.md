# The boot sound and BIBLE, and RIPPS2's BIBLE menu

This is the contract between BIBLE and RIPPS2 for the boot sound. BIBLE tells RIPPS2 where the sound lives and never
reads it. BIBLE 3282396 also read it into RAM during its splash; that went on 11/04 (below), and RIPPS2 still takes the
RAM copy from a card bound with that older BIBLE.

## Why the copy lives beside BIBLE

RIPPS2's **Boot Sound: On (fast)** keeps a copy of `boot.adp` on a memory card, so the boot reads it before any drive is
up and the sound plays with the pillars. Started by BIBLE from an SD2PSX (`mmce?:/APPS/RIPPS2.ELF`), USB or the HDD,
RIPPS2 is on no card, so the copy lives beside BIBLE's config instead.

## Where the copy lives

`<the folder BIBLE read its config from>boot.adp`, on a memory card only. With BIBLE installed the usual way that is
**`mc0:/SYS-CONF/boot.adp`** (or `mc1:`), next to `PS2BBL.INI`. On an SD2PSX it is the BOOT card's SYS-CONF.

- The name is lowercase `boot.adp`, RIPPS2's own name for the sound (the memory card's file system keeps case).
- A config read from anywhere else (CWD `CONFIG.INI`, USB, MMCE, HDD) means no copy and no `-bible-home=`.

## What BIBLE does

Every build, every launch: when the launched file's name starts with `RIPPS2` (any case), BIBLE adds one argument, after
its own launch-control arguments are taken (a trailing `-gsm=` still works), and only when it still fits what ExecPS2
carries (16 arguments, 256 bytes; otherwise it is left out and the log says so):

| Argument | When | Meaning |
|---|---|---|
| `-bible-home=mc0:/SYS-CONF/` | BIBLE's config is on a memory card | The folder BIBLE read its config from, ending in `/`. Where **On (fast)** writes `boot.adp`, and where RIPPS2 reads it. |

It is a plain `argv[]` entry after `argv[0]`. RIPPS2's `main` only looks at `argv[4]` when `argc >= 5` (`mini` / `bdm`
auto-launch), which this never reaches.

## Why the RAM read went

The user, 11/04: "if we dont need to load the boot sound into memory during bible lets not". We do not need it.

- **On a real SD2PSX it never arrived.** RIPPS2 read the card itself (DIAG: "no boot sound handed over", 1.1 s, the sound
  0.26 s after the towers on a SCPH-39001). By the code, the launch resets the IOP for the MMCE driver and that lets an
  unfinished read go.
- **On a memory card launch at 0 ms the whole read came before RIPPS2.** It only moved the wait from RIPPS2 to BIBLE, and
  BIBLE's read was slower: 32 KB a frame, a CRC, then a second loader.
- **RIPPS2's towers wait for its own read and the sound follows them either way.**
- **It needed a second launch path**: the stage 2 loader in the MMCE, MX4SIO and HDD builds, for this one launch, with a
  `K` flag and a fixed RAM address that a larger RIPPS2 could overlap.

Lab, 11/04: PCSX2, BIBLE's MMCE build, RIPPS2 v1.4.1, a 367,904-byte `boot.adp`, RIPPS2 on the memory card. Seconds from
the emulator answering to RIPPS2's towers, polled over PINE; "before" is 3282396, "after" is this change.

| Config | Before | After |
|---|---|---|
| 0 ms, splash on (`LOGO_DISPLAY = 2`) | 5.26, 5.26 | 4.85, 4.79 |
| 0 ms, no splash (`LOGO_DISPLAY = 0`, what Manage writes) | 5.16, 4.88, 4.73 | 3.99, 4.31, 3.95 |
| 3 s countdown (`LOGO_DISPLAY = 3`) | 7.60 | 7.55, 7.27 |
| The sound after the towers, every take | 0.13 | 0.14 |

One "before" countdown take read 12.13 s, and one "after" take that launched a file with another name read 7.12 s against
4.05 and 4.34 on its repeats. A lab boot sometimes runs a few seconds long, so read these as a pattern, not to the
hundredth.

| Build | Packed before | Packed after |
|---|---|---|
| PS2_MMCE | 179,028 | 169,428 |
| PS2_MX4SIO | 176,308 | 166,692 |
| PS2_HDD | 169,556 | 160,036 |
| PS2 | 117,012 | 116,436 |

Also passed in the lab on this change: the PS2, MX4SIO and HDD builds start RIPPS2 from a memory card with the home and
the sound; AUTO with `mmce?:/APPS/RIPPS2.ELF` and no device goes on to the next path after about 2 s; L1 held at power
on starts its path; a program with another name gets no `-bible-home=`; no copy beside BIBLE starts RIPPS2 as usual. Not
run: a real PS2, an MMCE or USB launch on a real device.

## BIBLE 3282396, still on people's cards

That BIBLE read `boot.adp` with libmc's asynchronous `mcRead` during the splash when its AUTO key's first entry was
RIPPS2 (the MMCE, MX4SIO and HDD builds), and passed `-bible-bootsnd=mem:01400000:<size>:<crc32>` (8 hex digits each) as
well as the home. ps2sdk's `LoadELFFromFile` runs `wipeUserMem()` over all user RAM, so that launch went through the
stage 2 loader with `-la=KR`, which left the range alone.

RIPPS2 keeps taking it: `ripps2BibleArgs` checks the range, the CRC and the `APCM` header, copies it out first thing in
`main`, and DIAG.TXT says which path ran. With no argument, or a bad one, RIPPS2 reads `<home>boot.adp`.

## RIPPS2's side

- `sfxCardBootPath`: when `gBibleHome` is set, the copy is `<gBibleHome>boot.adp` (read at boot, and written by
  **On (fast)** and the BIOS Sounds rip offer). Without it: beside RIPPS2 on its card.
- Choosing **Off** or **On** (not fast) removes `<gBibleHome>boot.adp`.
- STATUS's boot sound line (`sfxBootSoundWhere`) names the file.

## A BIBLE menu (the user, 11/03)

When BIBLE is detected (RIPPS2 was started with `-bible-home=`, or Manage finds BIBLE installed on a card),
**Settings > General > Boot Loader** opens a BIBLE menu, and **Manage** (install, bind, BOOT LOCK) is one item in it
instead of the only one. Every key of BIBLE's config is offered, edited in place in `PS2BBL.INI`:

- **Background**: `BIBLE_BACKGROUND` Auto / Sky / Black.
- **Sky colour**: `BIBLE_COLOR` unset (follows the Color Theme through `ripps2_bible_sky`) or a fixed one.
- **Video Mode**: `VIDEO_MODE` (Auto follows RIPPS2's own), **Widescreen**: `BIBLE_WIDESCREEN`.
- **Wait**: `KEY_READ_WAIT_TIME` (0 ms to 10 s).
- **Splash**: `LOGO_DISPLAY`, `BIBLE_GLYPHS`, `BIBLE_INFO`.
- **Boot sound**: the same three choices as Audio's Boot Sound, here because the copy lives with BIBLE.
- **Disc and history**: `EJECT_TRAY`, `DISC_STOP`, `OSDHISTORY_READ`, `APP_GAMEID`, `CDROM_DISABLE_GAMEID`.
- **Launch keys**: for each button (AUTO, the face buttons, L1 to R3, START, SELECT, the d-pad), its name
  (`NAME_<KEY>`) and up to ten paths (`LK_<KEY>_E1` to `E10`) picked with the Memory Files browser, plus
  `ARG_<KEY>_E<n>`. Hold **L2 + R2** at power on and BIBLE pauses on its launch keys page.
- **Edits keep the file hand-editable**: change only the lines of the keys touched, keep comments and unknown keys, write
  a temporary file and rename it over the old one.
- Other boot loaders' configs (FMCB, OSDMenu, El Isra's PS2BBL) stay with BOOT LOCK or Memory Files.

## Config template audit (11/03)

| | PS2BBL Extended's template (BIBLE's `release/` before) | RIPPS2 Manage's config (`blBibleConfig`) | BIBLE's template now |
|---|---|---|---|
| AUTO | E1, E2 empty; OSDMenu, FMCB 1.966 to 1.8C, BOOT2, `$OSDSYS` | `$OSDSYS` (BOOT LOCK puts RIPPS2 first) | **E1 `mc?:/RIPPS2/RIPPS2.ELF`, E2 `mmce?:/APPS/RIPPS2.ELF`**, then the same list |
| TRIANGLE | wLE ISR (MMCE, MX4SIO, exFAT) | `$OSDSYS` (the browser) | unchanged |
| Wait / splash | 6000 ms, LOGO_DISPLAY 3 | 0 ms, LOGO_DISPLAY 0 | unchanged, plus BIBLE's keys with notes |
| BIBLE keys | none | none | `VIDEO_MODE`, `BIBLE_BACKGROUND`, `BIBLE_COLOR` (commented), `BIBLE_GLYPHS`, `BIBLE_INFO`, `BIBLE_WIDESCREEN` |
| Notes | none | the hold keys | L2 + R2 launch keys page, TRIANGLE + CROSS video page, where the boot sound lives |

The built-in defaults (no config found) also try the two RIPPS2 paths first.
