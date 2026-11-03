<!-- i18n: the language bar, made by ps2-pillars tools/readme-i18n -->
<p align="center">
  <a href="README.md">English</a> |
  <a href="README.es.md">Español</a> |
  <a href="README.pt-BR.md">Português (Brasil)</a> |
  <a href="README.pt.md">Português</a> |
  <a href="README.fr.md">Français</a> |
  <a href="README.de.md">Deutsch</a> |
  <a href="README.it.md">Italiano</a> |
  <a href="README.nl.md">Nederlands</a> |
  <a href="README.da.md">Dansk</a> |
  <a href="README.sv.md">Svenska</a> |
  <a href="README.pl.md">Polski</a> |
  <a href="README.cs.md">Čeština</a> |
  <a href="README.hr.md">Hrvatski</a> |
  <a href="README.sr.md">Srpski</a> |
  <a href="README.bg.md">Български</a> |
  <a href="README.ru.md">Русский</a> |
  <a href="README.el.md">Ελληνικά</a> |
  <a href="README.hu.md">Magyar</a> |
  <a href="README.ro.md">Română</a> |
  <a href="README.gl.md">Galego</a> |
  <a href="README.sq.md">Shqip</a> |
  <a href="README.tr.md">Türkçe</a> |
  <a href="README.ar.md">العربية</a> |
  <a href="README.fa.md">فارسی</a> |
  <a href="README.ja.md">日本語</a> |
  <a href="README.ko.md">한국어</a> |
  <a href="README.zh-CN.md">简体中文</a> |
  <a href="README.zh-TW.md">繁體中文</a> |
  <a href="README.vi.md">Tiếng Việt</a> |
  <a href="README.lo.md">ລາວ</a> |
  <a href="README.id.md">Bahasa Indonesia</a> |
  <a href="README.fil.md">Filipino</a> |
  <b>Cebuano</b>
</p>
<!-- /i18n -->

<p align="center"><sub>Hubad sa README nga Iningles; kung lahi, ang Iningles ang sundon. <a href="README.md">English</a></sub></p>

<p align="center"><sub><a href="https://github.com/akilluminati47/RIPPS2">RIPPS2</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2/releases/latest/download/RIPPS2.elf">I-download</a> &nbsp;&middot;&nbsp; <b>BIBLE</b> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2-themes">Mga tema</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPCSX2">RIPPCSX2</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2-fonts">Mga font</a> &nbsp;&middot;&nbsp; <a href="https://akilluminati47.github.io/RIPPS2/">Website</a> &nbsp;&middot;&nbsp; <a href="https://www.psx-place.com/threads/ripps2-a-ps2-front-end-in-one-elf-launch-disc-storage-memory-files.51316/">psx-place</a> &nbsp;&middot;&nbsp; <a href="https://discord.gg/Z7m9u5kby">Discord</a></sub></p>

<h1 align="center">BIBLE</h1>
<p align="center">
  <a href="https://github.com/akilluminati47/RIPPS2">RIPPS2</a> ·
  <a href="https://github.com/akilluminati47/BIBLE/actions">Mga build</a> ·
  <a href="https://github.com/saildot4k/PlayStation2-Basic-BootLoader-Extended">PS2BBL Extended</a> ·
  <a href="https://github.com/israpps/PlayStation2-Basic-BootLoader">PS2BBL</a> ·
  <a href="LICENSE">GPL-3.0</a>
</p>

<p align="center">
  <img src="assets/readme/bible-splash.gif" width="640" alt="BIBLE's splash: the logo alone, with BIBLE_INFO, with the face buttons, with every button">
</p>
<p align="center">
  <img src="assets/readme/bible-keys.png" width="212" alt="Launch keys page">
  <img src="assets/readme/bible-video-mode.png" width="212" alt="Video mode page">
  <img src="assets/readme/bible-credits.png" width="212" alt="Credits page"><br>
  <sub>Pugngi ang L2 + R2 sa pag-boot para sa page sa mga launch key, TRIANGLE + CROSS para sa page sa video mode; ang key nga gi-set sa <code>$CREDITS</code> magpakita sa credits.</sub>
</p>

Ang BIBLE mao ang boot loader nga gi-set up sa RIPPS2: usa ka fork sa PS2BBL Extended ni saildot4k.

**Unsa ang giusab niini nga fork**

- Ang splash: ang logo sa PS2 sa tunga sa langit sa RIPPS2, ang mga button sa ubos ug ang bisan unsang teksto sa ibabaw. `BIBLE_GLYPHS` 0 wala, 1 ang mga action button (default), 2 tanang napulog-unom sa duha ka laray nga tig-walo. `BIBLE_INFO` 1 nagpakita sa info sa console, orasan ug countdown (naka-off sa default). Nagsunod ang langit sa imong Color Theme sa RIPPS2: kung walay `BIBLE_COLOR`, basahon sa BIBLE ang langit nga gi-save sa RIPPS2 uban sa mga setting niini, gikan sa folder nga ablihan sa AUTO entry niini, o gikan sa folder nga `RIPPS2` sa memory card kung ang AUTO entry kay RIPPS2 sa SD2PSX, USB o HDD (ang `BIBLE_COLOR` sa config ang modaog). Parehas nga dagway sa matag video mode.
- `BIBLE_BACKGROUND`: `AUTO` (default: ang langit kung makit-an ang mga setting sa RIPPS2 o naay `BIBLE_COLOR`, kung dili itom sa kaugalingong mode sa console, usa ka yano nga boot loader), `SKY` o `BLANK` (itom). Itom man pud sulod sa pipila ka segundo ang pagbalhin ngadto sa usa ka program, mao nga ang itom morag usa ra ka piraso uban niini.
- Ang boot sound, andam na daan: ang Boot Sound On (fast) sa RIPPS2 makatipig sa `boot.adp` tupad sa config sa BIBLE (`mc?:/SYS-CONF/boot.adp`). Basahon kini sa BIBLE samtang nag-countdown ang splash ug itunol sa RIPPS2 sa RAM, mao nga motunog kini uban sa unang frame sa RIPPS2 bisan kung magsugod ang RIPPS2 gikan sa SD2PSX (mga build nga MMCE, MX4SIO ug HDD; ang memory card / USB build mosulti sa RIPPS2 sa folder ug ang RIPPS2 ang mobasa). Hulaton sa BIBLE sa launch ang bahin nga wala pa mabasa: sa `KEY_READ_WAIT_TIME = 0` mao na kana ang tibuok pagbasa, mga 2 s sa memory card. **Ang walay tingog mao ang labing paspas nga boot.** Ang kasabutan ug ang bahin sa RIPPS2: [docs/boot-sound-handoff.md](docs/boot-sound-handoff.md).
- Una ang RIPPS2: ang config template (`release/SYS-CONF/PS2BBL.INI`) ug ang mga built-in nga default mosulay sa `mc?:/RIPPS2/RIPPS2.ELF` ug `mmce?:/APPS/RIPPS2.ELF` una sa OSDMenu ug FMCB, ug ang template naglista sa kaugalingong mga key sa BIBLE nga naay mga nota. Ang mga panid (video mode, credits, launch keys) mogawas sa ibabaw sa gipangitngit nga logo nga gitabi ang mga button, aron hinay nga mabasa ang launch keys.
- Mga video mode: modawat usab ang `VIDEO_MODE` og `576P`, `720P` ug `1080I`, ang uban pang mode sa RIPPS2. Ang `AUTO` (default)
  magsugod sa Video Mode sa RIPPS2 kung naa ang mga setting niini tupad sa AUTO entry, kung dili sa kaugalingong mode sa console.
- `BIBLE_WIDESCREEN`: `AUTO` (default: ang Widescreen sa RIPPS2, kung dili ang 16:9 screen setting sa PS2), `ON` o
  `OFF`. Sa 480i, 576i, 480p ug 576p, ang splash gidrowing para sa TV nga moinat sa hulagway ngadto sa 16:9, nga walay
  pagkapiit. 16:9 na ang 720p ug 1080i.
- Walay paglukso pagsulod sa RIPPS2: sa pag-launch, mokupas ang logo ug mga button ug magpabilin ang langit sa screen, sa mode sa RIPPS2;
  magsugod ang RIPPS2 sa parehas nga langit. Pugngi ang TRIANGLE + CROSS sa pag-boot para sa page sa video mode, nga kanunay moabli
  sa kaugalingong interlaced mode sa console (ang dalan pabalik gikan sa 720p o 1080i sa composite cable).
- Bag-o: ang panid sa launch keys. Pugngi ang L2 + R2 sa pag-on ug mohunong ang BIBLE una magsugod ug bisan unsa, nagpakita sa kasamtangang launch path sa matag key, bisan unsa pa ang setting sa imong splash (magamit sa `LOGO_DISPLAY = 0`, diin walay laing mogawas).
- Ang mga combo nga gipugngan sukad sa pag-on moabli na karon sa ilang mga page (ang TRIANGLE + CROSS malimtan samtang nagsugod pa
  ang mga controller).
- Gitugotan ang `KEY_READ_WAIT_TIME = 0` (500 ms ang pinakaubos sa upstream).
- Mga PS2 build para sa memory card / USB, MMCE, MX4SIO ug HDD. Wala gilakip ang eGSM stage 2.

**Giunsa kini paggamit sa RIPPS2**

Gidala sa RIPPS2 ang BIBLE sulod sa RIPPS2.elf, matag build gipirmahan ni akilluminati47, ug i-install o i-update kini gikan sa Settings > General > Boot Loader > Manage, nga mo-set usab sa mga key sa BIBLE: Background, Splash, Button Glyphs, Info Line, Power-on Wait, Video Mode ug Widescreen. Ang mga gipirmahan nga build ug usa ka andam nga SD2PSX BOOT card naa sa [panid sa mga release](https://github.com/akilluminati47/BIBLE/releases/latest). Modagan usab ang BIBLE isip ELF nga ablihan sa laing loader (FMCB, OSDMenu, ang loader sa SD2PSX).

<p align="center"><img src="assets/readme/ripps2-icon.png" alt="RIPPS2" width="48" height="48"><br><sub>Bahin ang BIBLE sa <a href="https://github.com/akilluminati47/RIPPS2">RIPPS2</a>.</sub></p>

---

<p align="center"><sub>Ang tanan sa ubos mao ang orihinal nga README sa PS2BBL Extended, gihubad ug wala nay laing giusab.</sub></p>

---


<br />
<p align="center">
  <a href="https://israpps.github.io/PlayStation2-Basic-BootLoader/">
    <img src="https://github.com/saildot4k/PlayStation2-Basic-BootLoader-Extended/blob/main/assets/ps2bbl_example.png" alt="Logo" width="50%" height="auto">
  </a>

  <p align="center">
    Usa ka flexible nga BootLoader para sa PlayStation 2™ ug PSX-DESR
    <br />
  </p>
</p>  


Kini usa ka fork sa PS2BBL ni [El Isra](https://github.com/israpps/PlayStation2-Basic-BootLoader/)


<a id="documentation"></a>

## Dokumentasyon

Naka-host kini sa [github pages](https://israpps.github.io/PlayStation2-Basic-BootLoader/) apan uban sa mga dugang sa ubos:

<a id="config-and-arguments"></a>

## Config ug mga argument

I-edit ang config file sumala sa gikinahanglan. Girekomendar ang [R3Configurator](https://github.com/saildot4k/R3CONFIGURATOR) sa pag-edit sa imong config file. Na-set na ang mga path aron motugma sa mga download gikan sa [PS2 Homebrew Store](https://ps2homebrewstore.com). Buot ipasabot, ang imong Auto choice ra ang kinahanglang i-edit, ug mas maayo nga i-set ang mga argument sa NHDDL sumala sa device diin ka nag-load og mga ISO.

<a id="config-path-search-order"></a>

### Han-ay sa pagpangita sa config

Nahibal-an na karon sa pagpangita sa config ang boot family aron dili mag-load og dili kinahanglang mga driver sa pagsugod:

1. `CONFIG.INI` (CWD: Current Working Directory)
2. Kung gi-load gikan sa device:
   - MMCE boot: `mmce?:/PS2BBL/CONFIG.INI`
   - MX4SIO boot: `mx4sio:/PS2BBL/CONFIG.INI`
   - APA HDD boot: `hdd0:__sysconf:pfs:/PS2BBL/CONFIG.INI`
   - BDM boot: `usb:/PS2BBL/CONFIG.INI` / `mass:/PS2BBL/CONFIG.INI` / `ata:/PS2BBL/CONFIG.INI`
3. Fallback sa memory card:
   - Sa PS2: `mc?:/SYS-CONF/PS2BBL.INI`
   - Sa PSX-DESR: `mc?:/SYS-CONF/PSXBBL.INI`
4. Katapusang fallback sa PSX
   - `xfrom:/PS2BBL/CONFIG.INI`
5. Kung gi-compile uban sa `DISC_STOP_AT_BOOT=1
   - `cdrom0:/PS2BBL/CONFIG.INI`
   - Fallback sa memory card sumala sa punto 3 sa ibabaw.

<a id="device-path-prefixes"></a>

### Mga prefix sa device path
Gisuportahan sa PS2BBL kining mga prefix sa launch/config path:
- `mc0:/`, `mc1:/`, `mc?:/`
- `usb:/` (mas gusto), ug `mass:/` (daan)

<a id="build-specific"></a>

#### Sumala sa build:  
- `mmce0:/`, `mmce1:/`, `mmce?:/` __mga MMCE build__
- `mx4sio:/` (mas gusto), ug `massX:/` (daan)  __mga MX4SIO build__
- `hdd0:partition:pfs:/<path to elf>` __mga HDD build__
- Mga path nga `xfrom:/` __mga PSX DESR build__
- `ata:/` BDM device para sa exFAT HDD
- `ilink:/` (mga root sa BDM mass-storage) __wala pa maimplementar__
- `DISC_STOP_AT_BOOT=1` compile-time profile nga kanunay mohunong sa optical disc human ma-load ang config

### LOGO_DISPLAY
Gamita ang `LOGO_DISPLAY = 3` aron ipakita ang mga ngalan sa hotkey. Ang mga ngalan gitakda sa `NAME_<BUTTON>`.
  - `0` Walay logo ug impormasyon sa console
  - `1` Impormasyon sa console
  - `2` PS2BBLE/PSXBBLE logo ug impormasyon sa console
  - `3` Graphic sa hotkey nga adunay `NAME_BUTTON = <TITLE>` gikan sa config file
    - Pananglitan:
      ```
      NAME_SQUARE = POPSLOADER
      ```

<a id="custom-splash-logo-from-cwd"></a>

#### Kaugalingong splash logo gikan sa CWD
Kung adunay kaugalingong logo file (LOGO.BIN) sa CWD (current working directory), ilisan niini ang naka-embed nga PS2BBLE/PSXBBLE logo.

I-convert ang PNG ngadto sa gipaabot nga raw file:
  - Ang PNG kinahanglan RGBA 8 Bit indexed, 255 ka kolor matag channel ug 256x64 ang resolution.

  - Release package (naa sa release root ang script):
  ```bash
  python png_to_logo_rbga.py my_logo.png
  ```

  - Ibutang ang gihimong `LOGO.BIN` tupad sa PS2BBL Extended. Kinahanglan kini `mc?:/BOOT/` kung naggamit ka og mga download gikan sa [PS2 Homebrew Store](https://ps2store.com)

### Retrogem visual game ID
- Ang `APP_GAMEID = 1` mo-on sa visual game ID para sa apps/homebrew, hangtod 11 ka character gikan sa filename o PS1/2 Disc
- Ang `CDROM_DISABLE_GAMEID = 1` mo-off sa visual game ID para sa mga disc nga gilansad pinaagi sa `cdrom`.

<a id="disc-spin-control"></a>

### Kontrol sa pagtuyok sa disc
- Global nga key/value: `DISC_STOP = 0/1`
- Ang `DISC_STOP = 1` mohunong sa optical disc human ma-load ang config kung adunay nakit-ang config file.
- Ang `DISC_STOP = 0` (o kung wala) magpabilin sa default nga kinaiya.
- Mahimong idugang ang `-disc_stop` sa matag launch entry aron mohunong ang disc human makit-an ang target ELF.

### Video Mode
- `VIDEO_MODE = AUTO, NTSC, PAL, 480P` Gamiton ang default sa PS2 o pugson ang usa sa 3 ka laing mode.

<a id="emergency-video-mode-selector"></a>

#### Pang-emerhensiya nga selector sa video mode
- Sulod gamit ang `TRIANGLE + CROSS` samtang nag-boot
- Pugson sa selector ang `LOGO_DISPLAY = 3` samtang aktibo aron makita nimo ang logo ug hotkey UI.
- Mga kontrol:
  - `LEFT/RIGHT` motuyok sa mga mode: `AUTO`, `NTSC`, `PAL`, `480P`
  - `SELECT` i-save ang napiling mode sa aktibong config file
  - `START` mogawas sa selector ug mopadayon sa hotkey display

<a id="cdrom-launch-args"></a>

### Mga launch argument sa CDROM
Para sa `LK_*_E* = cdrom`, ang mga gisuportahang argument mao ang:
- `-nologo`
- `-nogameid`
- `-ps1fast`
- `-ps1smooth`
- `-ps1vneg`
- `-gsm=<v[:c]>`

<a id="ps2logo-arguments-ps2-discs-only"></a>

#### Mga argument sa PS2LOGO (PS2 disc ra)
- Gamita ang `cdrom` isip path sa launch entry.
- Idugang ang `-nologo` sa mga argument sa entry aron direktang mag-boot sa PS2 disc (laktawan ang `rom0:PS2LOGO`).
- Kung walay `-nologo`, padaganon sa PS2BBL ang disc pinaagi sa PS2LOGO ug i-patch kini aron kanunay gamiton ang region sa disc ug lusutan ang checksum check sa logo.
- DECKARD IE 75K ug mas bag-o: awtomatikong gigamit ang XPARAM.IRX kung kinahanglan para sa mga launch nga walay logo.

<a id="ps1-disc-arguments-per-launch"></a>

#### Mga argument sa PS1 disc (matag launch)
Para kini sa matag `cdrom` launch entry, dili sa kinatibuk-an.
- Ang `-ps1fast` mo-on sa paspas nga katulin sa PS1 disc.
- Ang `-ps1smooth` mo-on sa pagpahamis sa texture.
- Ang `-ps1vneg` modagan sa PS1DRV pinaagi sa PS1VModeNegator. Mapuslanon sa mga setup diin managlahi ang mode sa console ug sa disc (pananglitan pipila ka kaso sa MechaPwn/modchip).

<a id="app-arguments"></a>

### Mga argument sa app
Gamita ang mga linya nga `ARG_<BUTTON>_E? =` aron mopasa og argument sa ELF (tan-awa ang mga pananglitan sa INI).
- Ibutang una ang mga argument sa elf nga ilansad, dayon idugtong ang gustong internal nga argument sa PS2BBL (tan-awa sa ubos). Maayong kandidato ang [NHDDL](https://github.com/pcm720/nhddl) para sa mga argument, kay mopaspas kini sa boot sa NHDDL.
- Ang `-titleid=SLUS_123.45` moilis sa title ID sa app (hangtod 11 ka character).
- Ang `-appid` mopugos sa visual game ID sa app bisan pa kung `APP_GAMEID = 0`.
- Ang `-disc_stop` mohunong sa disc human ma-load ang target ELF (mapuslanon matag entry kung walay `DISC_STOP_AT_BOOT` build).
- Ang `-gsm=<v[:c]>` modagan sa target ELF pinaagi sa naka-embed nga eGSM (gibalewala para sa mga path nga `rom?:`). Kinahanglan kini ang katapusang argument kung gamiton.
- Gibalewala ang `-disc_stop` para sa mga `cdrom` launch entry.
- Ang `-dev9=<mode>` motakda sa DEV9/HDD policy sa dili pa ilansad ang target ELF. Mga gisuportahang mode:
  - Ang `NICHDD` magpabilin nga naka-on ang DEV9 (network adapter) ug HDD.
  - Ang `NIC` magpabilin nga naka-on ang DEV9/network, mo-unmount sa `pfs0:`, ug diha-diha dayon mopa-idle sa `hdd0:`/`hdd1:`.
  - kung wala, dili mopugos ang PS2BBL og DEV9 policy.
  - pahinumdom: sa mga build nga walay HDD, walay epekto kini nga opsyon.
- Ang `-patinfo` mo-on sa pagdumala sa PATINFO para sa mga `:PATINFO` entry.
  - Basahon sa PS2BBL ang `SYSTEM.CNF` gikan sa partition attribute area (`PS2ICON3D`) ug gamiton ang `BOOT2/BOOT/path`, `arg*`, `skip_argv0`, ug `HDDUNITPOWER`.
  - kung `BOOT2/BOOT/path=PATINFO`, i-load sa PS2BBL ang naka-embed nga ELF gikan sa partition attribute area ug gamiton ang internal nga `-la=E...` handoff.
  - kung `IOPRP=PATINFO` (o kaugalingong path), ipasa kini sa PS2BBL ngadto sa stage2 pinaagi sa internal nga `-la=I...` handoff.
  - kung naa ang `-patinfo`, ang unang nahibilin nga argument moilis sa target nga `BOOT2/BOOT/path` sa CNF.
  Para kini sa mga HDD build.  
  Pananglitan sa PATINFO:  
    ```
    NAME_R1 = My App via PATINFO
    LK_R1_E1 = hdd0:+OSDMENU:PATINFO
    ARG_R1_E1 = pfs:/APPS/MYAPP.ELF
    ARG_R1_E1 = -patinfo               # Tells PS2BBL to use first arg as patinfo boot path.
    ```

Pananglitan sa paglansad sa NHDDL sa video mode 480p ug pagpangita og mga iso sa mmce ug exfat hdd nga dili kinahanglan ang nhddl.yaml. Ang kaayohan mao nga walay nausik nga oras sa pag-load sa mga driver, pagpangita ug pag-load sa nhddl.yaml. Kini ang pinakapaspas nga paagi sa pag-boot sa NHDDL ug pagpakita sa ISO list.
```
NAME_R1 = NHDDL
LK_R1_E1 = mmce?:/NEUTRINO/nhddl.elf
ARG_R1_E1 = -video=480p
ARG_R1_E1 = -mode=mmce
ARG_R1_E1 = -mode=ata
```

<a id="argument-precedence-and-order"></a>

#### Pagkauna ug han-ay sa mga argument
1. Ang PS2BBL mag-parse ug mokonsumo lang sa mga trailing loader-control arg gikan sa `ARG_*`: `-appid`, `-titleid=`, `-dev9=`, `-patinfo`, `-disc_stop`, `-gsm=`.
2. Gikan sa ubos pataas ang pag-parse ug mohunong sa unang dili-control nga arg (trailing nga kinaiya sama sa OSDMenu).
4. Para sa mga launch path nga `:PATINFO`, i-parse sa PS2BBL ang partition-attribute nga `SYSTEM.CNF` ug idugtong ang mga `arg*` entry sa CNF human sa mga argument sa app sa user.
5. Kung naka-set ang `-patinfo` ug adunay `:PATINFO` ang launch path, ang unang nahibilin nga argument sa app sa user mahimong path sa target ELF (moilis sa boot path sa CNF) ug tangtangon kini sa argv sa app. Kung walay nahibilin nga argument, i-abort ang launch (parehas sa OSDMenu), ug dili gamiton ang `BOOT2/BOOT/path` sa CNF.
6. Ang nahibilin nga mga argument magpabilin sa han-ay ug ipasa sa gilansad nga app.


### eGSM (external Graphics Synthesize Mode)
Para sa mga PS2 disc, awtomatikong basahon ang eGSM gikan sa `OSDGSM.CNF` (walay kinahanglang INI path setting). Tan-awa [dinhi](https://github.com/pcm720/OSDMenu/blob/main/patcher/README.md#osdgsmcnf) ang format sa config file.

- Ang `-gsm=<v[:c]>` modagan sa target ELF pinaagi sa naka-embed nga eGSM (gibalewala para sa mga path nga `rom?:`).
  - Gigamit ang eGSM sa gilansad nga target (ELF/disc), dili sa PS2BBL mismo.
  Format sa eGSM (sama sa OSDMenu):
- `v` = video mode:
- walay sulod = ayaw pugsa (default)
- `fp1` = pugsa ang progressive scan (240p/288p)
- `fp2` = pugsa ang progressive scan (480p/576p)
- `1080ix1` = pugsa ang 1080i, gilapdon/gitas-on x1
- `1080ix2` = pugsa ang 1080i, gilapdon/gitas-on x2
- `1080ix3` = pugsa ang 1080i, gilapdon/gitas-on x3
- `c` = compatibility mode:
- walay sulod = wala (default)
- `1` = field flipping matang 1
- `2` = field flipping matang 2
- `3` = field flipping matang 3

Mga pananglitan sa eGSM ARG:
- `-gsm=fp2`
- `-gsm=fp2:1`
- `-gsm=1080ix2`

Pananglitan sa paggamit:
```
LK_TRIANGLE_E1 = mc0:/APP_WLE-ISR/WLE-ISR.ELF
ARG_TRIANGLE_E1 = -gsm=1080ix2
```

<a id="deprecatedremoved"></a>

## Dili na gigamit/Gitangtang
- ~~`RUNKELF`~~ Ang PS2BBLE na karon ang modumala sa paglansad sa elf/kelf sa sulod niini nga dili na kinahanglan magtakda ang user og kelf launch action.


<a id="known-bugsissues"></a>

## Nahibal-ang mga bug/isyu

ikaw ang mosulti nako ;)

<a id="credits--thanks"></a>

## Mga kredito ug pasalamat

- Gikan kang saildot4k
  - @israpps para sa [PS2BBL](https://github.com/israpps/PlayStation2-Basic-BootLoader/)
  - @pcm720 para sa
    - Retrogem gameID, PS1 Video Negator, eGSM, ug PS2LOGO code gikan sa [OSDMenu](https://github.com/pcm720/OSDMenu)
    - Mga opsyon sa video mode gikan sa [NHDDL](https://github.com/pcm720/nhddl)
  - @sp193 para sa [PS1 Video Negator](https://github.com/ps2homebrew/PS1VModeNeg)
  - @nathanneurotic para sa 10path sa PS2BBLE, mga ideya ug pagdani
  - [@Berion](https://www.psx-place.com/members/berion.1431/) para sa mga logo, background ug hotkey graphics

- Gikan kang [El Isra](https://israpps.github.io/) (Developer sa PS2BBL): 
  - @SP193 para sa mga OSD initialization library, nga mao ang pundasyon niini nga proyekto
  - @asmblur, sa pag-awhag nako sa paghimo niini nga halimaw sa pinakabag-ong sdk
  - @uyjulian ug @fjtrujy sa kanunay nga pagtabang nako


<p align="center"><sub><a href="https://github.com/akilluminati47/RIPPS2">RIPPS2</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2/releases/latest/download/RIPPS2.elf">I-download</a> &nbsp;&middot;&nbsp; <b>BIBLE</b> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2-themes">Mga tema</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPCSX2">RIPPCSX2</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2-fonts">Mga font</a> &nbsp;&middot;&nbsp; <a href="https://akilluminati47.github.io/RIPPS2/">Website</a> &nbsp;&middot;&nbsp; <a href="https://www.psx-place.com/threads/ripps2-a-ps2-front-end-in-one-elf-launch-disc-storage-memory-files.51316/">psx-place</a> &nbsp;&middot;&nbsp; <a href="https://discord.gg/Z7m9u5kby">Discord</a></sub></p>

