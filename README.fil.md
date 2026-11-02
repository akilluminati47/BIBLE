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
  <b>Filipino</b> |
  <a href="README.ceb.md">Cebuano</a>
</p>
<!-- /i18n -->

<p align="center"><sub>Salin ng README sa Ingles; kung magkaiba, ang Ingles ang masusunod. <a href="README.md">English</a></sub></p>

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
  <sub>Pindutin nang matagal ang L2 + R2 sa pag-boot para sa page ng mga launch key, TRIANGLE + CROSS para sa page ng video mode; ang key na naka-set sa <code>$CREDITS</code> ay nagpapakita ng credits.</sub>
</p>

Ang BIBLE ang boot loader na inihahanda ng RIPPS2: isang fork ng PS2BBL Extended ni saildot4k.

**Ano ang binago ng fork na ito**

- Ang splash: ang PS2 logo sa gitna ng langit ng RIPPS2, may mga button sa ilalim at anumang text sa ibabaw.
  `BIBLE_GLYPHS` 0 wala, 1 ang mga face button (default), 2 lahat ng labing-anim sa dalawang hanay na tig-walo.
  `BIBLE_INFO` 1 ay nagpapakita ng impormasyon ng console, orasan at countdown (naka-off bilang default).
  Tugma ang langit sa iyong RIPPS2 Color Theme: kapag walang `BIBLE_COLOR`, binabasa ng BIBLE ang langit na sine-save ng RIPPS2 kasama ng
  mga setting nito, mula sa RIPPS2 folder na sinisimulan ng AUTO entry nito (nananaig ang `BIBLE_COLOR` sa config).
  Pareho ang itsura sa bawat video mode. Ang mga page (video mode, credits, launch keys) ay unti-unting lumilitaw sa ibabaw ng pinalabong logo
  habang nakaligpit ang mga button, kaya mahinahong nababasa ang mga launch key.
- Mga video mode: tumatanggap din ang `VIDEO_MODE` ng `576P`, `720P` at `1080I`, ang iba pang mode ng RIPPS2. Ang `AUTO` (default)
  ay nagsisimula sa Video Mode ng RIPPS2 kapag nasa tabi ng AUTO entry ang mga setting nito, kung hindi ay sa sariling mode ng console.
- `BIBLE_WIDESCREEN`: `AUTO` (default: ang Widescreen ng RIPPS2, kung hindi ay ang 16:9 screen setting ng PS2), `ON` o
  `OFF`. Sa 480i, 576i, 480p at 576p, iginuguhit ang splash para sa TV na binabanat ang larawan sa 16:9, nang walang
  pagkapipi. 16:9 na ang 720p at 1080i.
- Walang talon papasok sa RIPPS2: sa pag-launch, kumukupas ang logo at mga button at nananatili ang langit sa screen, sa mode ng RIPPS2;
  nagsisimula ang RIPPS2 sa parehong langit. Pindutin nang matagal ang TRIANGLE + CROSS sa pag-boot para sa page ng video mode, na laging bumubukas
  sa sariling interlaced mode ng console (ang daan pabalik mula 720p o 1080i sa composite cable).
- Bago: ang page ng mga launch key. Pindutin nang matagal ang L2 + R2 sa pag-boot para mabasa ang launch path ng bawat key, anuman ang iyong mga splash setting.
- Ang mga combo na hawak mula sa pag-on ay nagbubukas na ng kanilang mga page (nakakaligtaan ang TRIANGLE + CROSS habang nag-i-start pa
  ang mga controller).
- Pinapayagan ang `KEY_READ_WAIT_TIME = 0` (500 ms ang pinakamababa sa upstream).
- Mga PS2 build para sa memory card / USB, MMCE, MX4SIO at HDD. Hindi kasama ang eGSM stage 2.

**Paano ito ginagamit ng RIPPS2**

Dadalhin ng RIPPS2 ang BIBLE bilang mga signed boot file at ii-install ito mula sa Settings (Boot Loader) nito, kapalit ng PS2BBL 1.2.0 na dala nito ngayon. Tumatakbo rin ang BIBLE bilang ELF na sinimulan ng ibang loader (FMCB, OSDMenu, ang loader ng isang SD2PSX). Wala pang release ng BIBLE.

<p align="center"><img src="assets/readme/ripps2-icon.png" alt="RIPPS2" width="48" height="48"><br><sub>Bahagi ang BIBLE ng <a href="https://github.com/akilluminati47/RIPPS2">RIPPS2</a>.</sub></p>

---

<p align="center"><sub>Lahat ng nasa ibaba ay ang orihinal na README ng PS2BBL Extended, isinalin at walang ibang binago.</sub></p>

---


<br />
<p align="center">
  <a href="https://israpps.github.io/PlayStation2-Basic-BootLoader/">
    <img src="https://github.com/saildot4k/PlayStation2-Basic-BootLoader-Extended/blob/main/assets/ps2bbl_example.png" alt="Logo" width="50%" height="auto">
  </a>

  <p align="center">
    Isang flexible na BootLoader para sa PlayStation 2™ at PSX-DESR
    <br />
  </p>
</p>  


Ito ay fork ng PS2BBL ni [El Isra](https://github.com/israpps/PlayStation2-Basic-BootLoader/)


<a id="documentation"></a>

## Dokumentasyon

Naka-host ito sa [github pages](https://israpps.github.io/PlayStation2-Basic-BootLoader/) pero may mga dagdag sa ibaba:

<a id="config-and-arguments"></a>

## Config at mga argument

I-edit ang config file ayon sa kailangan. Inirerekomenda ang [R3Configurator](https://github.com/saildot4k/R3CONFIGURATOR) para i-edit ang config file mo. Naka-set na ang mga path para tumugma sa mga download mula sa [PS2 Homebrew Store](https://ps2homebrewstore.com). Ibig sabihin, ang Auto choice mo lang ang kailangang i-edit, at mas mabuting i-set ang mga argument ng NHDDL ayon sa device kung saan ka naglo-load ng mga ISO.

<a id="config-path-search-order"></a>

### Pagkakasunod ng paghahanap ng config

Alam na ngayon ng paghahanap ng config ang boot family para hindi mag-load ng mga hindi kailangang driver sa startup:

1. `CONFIG.INI` (CWD: Current Working Directory)
2. Kapag na-load mula sa device:
   - MMCE boot: `mmce?:/PS2BBL/CONFIG.INI`
   - MX4SIO boot: `mx4sio:/PS2BBL/CONFIG.INI`
   - APA HDD boot: `hdd0:__sysconf:pfs:/PS2BBL/CONFIG.INI`
   - BDM boot: `usb:/PS2BBL/CONFIG.INI` / `mass:/PS2BBL/CONFIG.INI` / `ata:/PS2BBL/CONFIG.INI`
3. Fallback sa memory card:
   - Sa PS2: `mc?:/SYS-CONF/PS2BBL.INI`
   - Sa PSX-DESR: `mc?:/SYS-CONF/PSXBBL.INI`
4. Huling fallback sa PSX
   - `xfrom:/PS2BBL/CONFIG.INI`
5. Kapag na-compile na may `DISC_STOP_AT_BOOT=1
   - `cdrom0:/PS2BBL/CONFIG.INI`
   - Fallback sa memory card ayon sa punto 3 sa itaas.

<a id="device-path-prefixes"></a>

### Mga prefix ng device path
Sinusuportahan ng PS2BBL ang mga prefix ng launch/config path na ito:
- `mc0:/`, `mc1:/`, `mc?:/`
- `usb:/` (mas gusto), at `mass:/` (luma)

<a id="build-specific"></a>

#### Ayon sa build:  
- `mmce0:/`, `mmce1:/`, `mmce?:/` __mga MMCE build__
- `mx4sio:/` (mas gusto), at `massX:/` (luma)  __mga MX4SIO build__
- `hdd0:partition:pfs:/<path to elf>` __mga HDD build__
- Mga path na `xfrom:/` __mga PSX DESR build__
- `ata:/` BDM device para sa exFAT HDD
- `ilink:/` (mga root ng BDM mass-storage) __hindi pa naipapatupad__
- `DISC_STOP_AT_BOOT=1` compile-time profile na laging humihinto sa optical disc pagkatapos ma-load ang config

### LOGO_DISPLAY
Gamitin ang `LOGO_DISPLAY = 3` para ipakita ang mga pangalan ng hotkey. Ang mga pangalan ay itinatakda ng `NAME_<BUTTON>`.
  - `0` Walang logo at impormasyon ng console
  - `1` Impormasyon ng console
  - `2` PS2BBLE/PSXBBLE logo at impormasyon ng console
  - `3` Graphic ng hotkey na may `NAME_BUTTON = <TITLE>` mula sa config file
    - Halimbawa:
      ```
      NAME_SQUARE = POPSLOADER
      ```

<a id="custom-splash-logo-from-cwd"></a>

#### Sariling splash logo mula sa CWD
Kung may sariling logo file (LOGO.BIN) sa CWD (current working directory), papalitan nito ang naka-embed na PS2BBLE/PSXBBLE logo.

I-convert ang PNG sa inaasahang raw file:
  - Ang PNG ay dapat RGBA 8 Bit indexed, 255 kulay bawat channel at 256x64 ang resolution.

  - Release package (nasa release root ang script):
  ```bash
  python png_to_logo_rbga.py my_logo.png
  ```

  - Ilagay ang ginawang `LOGO.BIN` sa tabi ng PS2BBL Extended. Dapat itong `mc?:/BOOT/` kung gumagamit ka ng mga download mula sa [PS2 Homebrew Store](https://ps2store.com)

### Retrogem visual game ID
- Ina-on ng `APP_GAMEID = 1` ang visual game ID para sa apps/homebrew, hanggang 11 character mula sa filename o PS1/2 Disc
- Ina-off ng `CDROM_DISABLE_GAMEID = 1` ang visual game ID para sa mga disc na inilunsad sa `cdrom`.

<a id="disc-spin-control"></a>

### Kontrol sa pag-ikot ng disc
- Global na key/value: `DISC_STOP = 0/1`
- Hinihinto ng `DISC_STOP = 1` ang optical disc pagkatapos ma-load ang config kapag may nakitang config file.
- Pinapanatili ng `DISC_STOP = 0` (o kapag wala) ang default na kilos.
- Puwedeng idagdag ang `-disc_stop` sa bawat launch entry para huminto ang disc kapag nakita na ang target ELF.

### Video Mode
- `VIDEO_MODE = AUTO, NTSC, PAL, 480P` Gagamitin ang default ng PS2 o pipilitin ang isa sa 3 ibang mode.

<a id="emergency-video-mode-selector"></a>

#### Pang-emergency na selector ng video mode
- Pumasok gamit ang `TRIANGLE + CROSS` habang nagbo-boot
- Pinipilit ng selector ang `LOGO_DISPLAY = 3` habang aktibo para makita mo ang logo at hotkey UI.
- Mga kontrol:
  - `LEFT/RIGHT` umiikot sa mga mode: `AUTO`, `NTSC`, `PAL`, `480P`
  - `SELECT` sine-save ang napiling mode sa aktibong config file
  - `START` lumalabas sa selector at tumutuloy sa hotkey display

<a id="cdrom-launch-args"></a>

### Mga launch argument ng CDROM
Para sa `LK_*_E* = cdrom`, ang mga suportadong argument ay:
- `-nologo`
- `-nogameid`
- `-ps1fast`
- `-ps1smooth`
- `-ps1vneg`
- `-gsm=<v[:c]>`

<a id="ps2logo-arguments-ps2-discs-only"></a>

#### Mga argument ng PS2LOGO (PS2 disc lang)
- Gamitin ang `cdrom` bilang path ng launch entry.
- Idagdag ang `-nologo` sa mga argument ng entry para direktang mag-boot ng PS2 disc (nilalaktawan ang `rom0:PS2LOGO`).
- Kapag walang `-nologo`, pinapatakbo ng PS2BBL ang disc sa PS2LOGO at pina-patch ito para laging gamitin ang region ng disc at lampasan ang checksum check ng logo.
- DECKARD IE 75K at mas bago: awtomatikong inilalapat ang XPARAM.IRX kapag kailangan para sa mga launch na walang logo.

<a id="ps1-disc-arguments-per-launch"></a>

#### Mga argument ng PS1 disc (bawat launch)
Para ito sa bawat `cdrom` launch entry, hindi pangkalahatan.
- Ina-on ng `-ps1fast` ang mabilis na bilis ng PS1 disc.
- Ina-on ng `-ps1smooth` ang pagpapakinis ng texture.
- Pinapatakbo ng `-ps1vneg` ang PS1DRV sa PS1VModeNegator. Kapaki-pakinabang sa mga setup kung saan magkaiba ang mode ng console at ng disc (halimbawa ilang kaso ng MechaPwn/modchip).

<a id="app-arguments"></a>

### Mga argument ng app
Gamitin ang mga linyang `ARG_<BUTTON>_E? =` para magpasa ng argument sa ELF (tingnan ang mga halimbawa ng INI).
- Ilagay muna ang mga argument ng elf na ilulunsad, saka idugtong ang gustong internal na argument ng PS2BBL (tingnan sa ibaba). Mahusay na kandidato ang [NHDDL](https://github.com/pcm720/nhddl) para sa mga argument, dahil pinabibilis nito ang boot ng NHDDL.
- Pinapalitan ng `-titleid=SLUS_123.45` ang title ID ng app (hanggang 11 character).
- Pinipilit ng `-appid` ang visual game ID ng app kahit `APP_GAMEID = 0`.
- Hinihinto ng `-disc_stop` ang disc pagkatapos ma-load ang target ELF (kapaki-pakinabang bawat entry kapag walang `DISC_STOP_AT_BOOT` build).
- Pinapatakbo ng `-gsm=<v[:c]>` ang target ELF sa naka-embed na eGSM (binabalewala para sa mga path na `rom?:`). Dapat itong huling argument kung gagamitin.
- Binabalewala ang `-disc_stop` para sa mga `cdrom` launch entry.
- Itinatakda ng `-dev9=<mode>` ang DEV9/HDD policy bago ilunsad ang target ELF. Mga suportadong mode:
  - Pinananatiling naka-on ng `NICHDD` ang DEV9 (network adapter) at HDD.
  - Pinananatiling naka-on ng `NIC` ang DEV9/network, ina-unmount ang `pfs0:`, at agad pinapa-idle ang `hdd0:`/`hdd1:`.
  - kapag wala, hindi nagpipilit ang PS2BBL ng DEV9 policy.
  - paalala: sa mga build na walang HDD, walang epekto ang opsyong ito.
- Ina-on ng `-patinfo` ang paghawak ng PATINFO para sa mga `:PATINFO` entry.
  - Binabasa ng PS2BBL ang `SYSTEM.CNF` mula sa partition attribute area (`PS2ICON3D`) at inilalapat ang `BOOT2/BOOT/path`, `arg*`, `skip_argv0`, at `HDDUNITPOWER`.
  - kung `BOOT2/BOOT/path=PATINFO`, ilo-load ng PS2BBL ang naka-embed na ELF mula sa partition attribute area at gagamitin ang internal na `-la=E...` handoff.
  - kung `IOPRP=PATINFO` (o sariling path), ipapasa ito ng PS2BBL sa stage2 sa internal na `-la=I...` handoff.
  - kung may `-patinfo`, papalitan ng unang natitirang argument ang target na `BOOT2/BOOT/path` ng CNF.
  Para ito sa mga HDD build.  
  Halimbawa ng PATINFO:  
    ```
    NAME_R1 = My App via PATINFO
    LK_R1_E1 = hdd0:+OSDMENU:PATINFO
    ARG_R1_E1 = pfs:/APPS/MYAPP.ELF
    ARG_R1_E1 = -patinfo               # Tells PS2BBL to use first arg as patinfo boot path.
    ```

Halimbawa ng paglunsad ng NHDDL sa video mode 480p at paghahanap ng mga iso sa mmce at exfat hdd nang hindi kailangan ang nhddl.yaml. Ang pakinabang ay walang nasasayang na oras sa pag-load ng mga driver, paghahanap at pag-load ng nhddl.yaml. Ito ang pinakamabilis na paraan para i-boot ang NHDDL at ipakita ang ISO list.
```
NAME_R1 = NHDDL
LK_R1_E1 = mmce?:/NEUTRINO/nhddl.elf
ARG_R1_E1 = -video=480p
ARG_R1_E1 = -mode=mmce
ARG_R1_E1 = -mode=ata
```

<a id="argument-precedence-and-order"></a>

#### Pagkakauna at pagkakasunod ng mga argument
1. Ang PS2BBL ay nagpa-parse at kumokonsumo lang ng mga trailing loader-control arg mula sa `ARG_*`: `-appid`, `-titleid=`, `-dev9=`, `-patinfo`, `-disc_stop`, `-gsm=`.
2. Mula ibaba pataas ang pag-parse at humihinto sa unang hindi-control na arg (trailing na kilos na istilong OSDMenu).
4. Para sa mga launch path na `:PATINFO`, pina-parse ng PS2BBL ang partition-attribute na `SYSTEM.CNF` at idinudugtong ang mga `arg*` entry ng CNF pagkatapos ng mga argument ng app ng user.
5. Kung naka-set ang `-patinfo` at may `:PATINFO` ang launch path, ang unang natitirang argument ng app ng user ang magiging path ng target ELF (pinapalitan ang boot path ng CNF) at inaalis ito sa argv ng app. Kung walang natitirang argument, ina-abort ang launch (katulad ng OSDMenu), at hindi ginagamit ang `BOOT2/BOOT/path` ng CNF.
6. Pinananatili ng natitirang mga argument ang pagkakasunod at ipinapasa sa inilunsad na app.


### eGSM (external Graphics Synthesize Mode)
Para sa mga PS2 disc, awtomatikong binabasa ang eGSM mula sa `OSDGSM.CNF` (walang kailangang INI path setting). Tingnan [dito](https://github.com/pcm720/OSDMenu/blob/main/patcher/README.md#osdgsmcnf) ang format ng config file.

- Pinapatakbo ng `-gsm=<v[:c]>` ang target ELF sa naka-embed na eGSM (binabalewala para sa mga path na `rom?:`).
  - Inilalapat ang eGSM sa inilunsad na target (ELF/disc), hindi sa PS2BBL mismo.
  Format ng eGSM (istilong OSDMenu):
- `v` = video mode:
- walang laman = huwag pilitin (default)
- `fp1` = pilitin ang progressive scan (240p/288p)
- `fp2` = pilitin ang progressive scan (480p/576p)
- `1080ix1` = pilitin ang 1080i, lapad/taas x1
- `1080ix2` = pilitin ang 1080i, lapad/taas x2
- `1080ix3` = pilitin ang 1080i, lapad/taas x3
- `c` = compatibility mode:
- walang laman = wala (default)
- `1` = field flipping uri 1
- `2` = field flipping uri 2
- `3` = field flipping uri 3

Mga halimbawa ng eGSM ARG:
- `-gsm=fp2`
- `-gsm=fp2:1`
- `-gsm=1080ix2`

Halimbawa ng paggamit:
```
LK_TRIANGLE_E1 = mc0:/APP_WLE-ISR/WLE-ISR.ELF
ARG_TRIANGLE_E1 = -gsm=1080ix2
```

<a id="deprecatedremoved"></a>

## Hindi na ginagamit/Inalis
- ~~`RUNKELF`~~ Hinahawakan na ngayon ng PS2BBLE ang paglunsad ng elf/kelf sa loob nito nang hindi na kailangang magtakda ang user ng kelf launch action.


<a id="known-bugsissues"></a>

## Mga kilalang bug/isyu

ikaw ang magsabi sa akin ;)

<a id="credits--thanks"></a>

## Mga kredito at pasasalamat

- Mula kay saildot4k
  - @israpps para sa [PS2BBL](https://github.com/israpps/PlayStation2-Basic-BootLoader/)
  - @pcm720 para sa
    - Retrogem gameID, PS1 Video Negator, eGSM, at PS2LOGO code mula sa [OSDMenu](https://github.com/pcm720/OSDMenu)
    - Mga opsyon ng video mode mula sa [NHDDL](https://github.com/pcm720/nhddl)
  - @sp193 para sa [PS1 Video Negator](https://github.com/ps2homebrew/PS1VModeNeg)
  - @nathanneurotic para sa 10path ng PS2BBLE, mga ideya at panghihikayat
  - [@Berion](https://www.psx-place.com/members/berion.1431/) para sa mga logo, background at hotkey graphics

- Mula kay [El Isra](https://israpps.github.io/) (Developer ng PS2BBL): 
  - @SP193 para sa mga OSD initialization library, na pundasyon ng proyektong ito
  - @asmblur, sa paghikayat sa akin na gawin ang halimaw na ito sa pinakabagong sdk
  - @uyjulian at @fjtrujy sa laging pagtulong sa akin


<p align="center"><sub><a href="https://github.com/akilluminati47/RIPPS2">RIPPS2</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2/releases/latest/download/RIPPS2.elf">I-download</a> &nbsp;&middot;&nbsp; <b>BIBLE</b> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2-themes">Mga tema</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPCSX2">RIPPCSX2</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2-fonts">Mga font</a> &nbsp;&middot;&nbsp; <a href="https://akilluminati47.github.io/RIPPS2/">Website</a> &nbsp;&middot;&nbsp; <a href="https://www.psx-place.com/threads/ripps2-a-ps2-front-end-in-one-elf-launch-disc-storage-memory-files.51316/">psx-place</a> &nbsp;&middot;&nbsp; <a href="https://discord.gg/Z7m9u5kby">Discord</a></sub></p>

