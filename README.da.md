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
  <b>Dansk</b> |
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
  <a href="README.ceb.md">Cebuano</a>
</p>
<!-- /i18n -->

<p align="center"><sub>Oversættelse af den engelske README; hvis de afviger, gælder den engelske. <a href="README.md">English</a></sub></p>

<p align="center"><sub><a href="https://github.com/akilluminati47/RIPPS2">RIPPS2</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2/releases/latest/download/RIPPS2.elf">Hent</a> &nbsp;&middot;&nbsp; <b>BIBLE</b> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2-themes">Temaer</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPCSX2">RIPPCSX2</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2-fonts">Skrifttyper</a> &nbsp;&middot;&nbsp; <a href="https://akilluminati47.github.io/RIPPS2/">Websted</a> &nbsp;&middot;&nbsp; <a href="https://www.psx-place.com/threads/ripps2-a-ps2-front-end-in-one-elf-launch-disc-storage-memory-files.51316/">psx-place</a> &nbsp;&middot;&nbsp; <a href="https://discord.gg/Z7m9u5kby">Discord</a></sub></p>

<h1 align="center">BIBLE</h1>
<p align="center">
  <a href="https://github.com/akilluminati47/RIPPS2">RIPPS2</a> ·
  <a href="https://github.com/akilluminati47/BIBLE/actions">Builds</a> ·
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
  <sub>Hold L2 + R2 ved opstart for siden med starttaster, TRIANGLE + CROSS for siden med videotilstand; en tast sat til <code>$CREDITS</code> viser krediteringerne.</sub>
</p>

BIBLE er den bootloader, som RIPPS2 sætter op: en fork af saildot4ks PS2BBL Extended.

**Hvad denne fork ændrer**

- Startskærmen: PS2-logoet centreret på RIPPS2's himmel, med knapperne under og eventuel tekst over.
  `BIBLE_GLYPHS` 0 ingen, 1 frontknapperne (standard), 2 alle seksten i to rækker á otte.
  `BIBLE_INFO` 1 viser konsolinfo, ur og nedtælling (slået fra som standard).
  Himlen følger dit RIPPS2 Color Theme: uden `BIBLE_COLOR` læser BIBLE den himmel, RIPPS2 gemmer med sine
  indstillinger, fra den RIPPS2-mappe, som dens AUTO-post starter (`BIBLE_COLOR` i konfigurationen vinder).
  Det samme udseende i hver videotilstand. Sider (videotilstand, krediteringer, starttaster) toner frem over det dæmpede logo
  med knapperne lagt væk, så starttasterne kan læses i ro.
- Videotilstande: `VIDEO_MODE` tager også `576P`, `720P` og `1080I`, resten af RIPPS2's. `AUTO` (standard)
  starter i RIPPS2's Video Mode, når dens indstillinger ligger ved siden af AUTO-posten, ellers i konsollens egen.
- `BIBLE_WIDESCREEN`: `AUTO` (standard: RIPPS2's Widescreen, ellers PS2'ens 16:9-skærmindstilling), `ON` eller
  `OFF`. I 480i, 576i, 480p og 576p tegnes startskærmen til et tv, der strækker billedet til 16:9, uden
  at mase det. 720p og 1080i er allerede 16:9.
- Intet hop ind i RIPPS2: ved start toner logo og knapper ud, og himlen bliver på skærmen i RIPPS2's tilstand;
  RIPPS2 starter på den samme himmel. Hold TRIANGLE + CROSS ved opstart for siden med videotilstand, som altid åbner i
  konsollens egen interlaced-tilstand (vejen tilbage fra 720p eller 1080i på et kompositkabel).
- Nyt: siden med starttaster. Hold L2 + R2 ved opstart for at læse hver tasts startsti, uanset dine indstillinger for startskærmen.
- Kombinationer holdt fra tænding åbner nu deres sider (TRIANGLE + CROSS blev misset, mens controllerne stadig
  startede op).
- `KEY_READ_WAIT_TIME = 0` er tilladt (upstreams minimum er 500 ms).
- PS2-builds til memory card / USB, MMCE, MX4SIO og HDD. eGSM trin 2 er udeladt.

**Sådan bruger RIPPS2 den**

RIPPS2 kommer til at medbringe BIBLE som signerede opstartsfiler og installere den fra sine Settings (Boot Loader) i stedet for den PS2BBL 1.2.0, den medbringer i dag. BIBLE kører også som en ELF startet af en anden loader (FMCB, OSDMenu, en SD2PSX-loader). Der er endnu ingen BIBLE-udgivelse.

<p align="center"><img src="assets/readme/ripps2-icon.png" alt="RIPPS2" width="48" height="48"><br><sub>BIBLE er en del af <a href="https://github.com/akilluminati47/RIPPS2">RIPPS2</a>.</sub></p>

---

<p align="center"><sub>Alt herunder er den oprindelige README fra PS2BBL Extended, oversat og ellers uændret.</sub></p>

---


<br />
<p align="center">
  <a href="https://israpps.github.io/PlayStation2-Basic-BootLoader/">
    <img src="https://github.com/saildot4k/PlayStation2-Basic-BootLoader-Extended/blob/main/assets/ps2bbl_example.png" alt="Logo" width="50%" height="auto">
  </a>

  <p align="center">
    En fleksibel bootloader til PlayStation 2™ og PSX-DESR
    <br />
  </p>
</p>  


Dette er en fork af PS2BBL af [El Isra](https://github.com/israpps/PlayStation2-Basic-BootLoader/)


<a id="documentation"></a>

## Dokumentation

Den ligger på [github pages](https://israpps.github.io/PlayStation2-Basic-BootLoader/), men med tilføjelserne herunder:

<a id="config-and-arguments"></a>

## Konfiguration og argumenter

Ret konfigurationsfilen efter behov. Til at rette den anbefales [R3Configurator](https://github.com/saildot4k/R3CONFIGURATOR). Stierne er allerede sat op til at passe med downloads fra [PS2 Homebrew Store](https://ps2homebrewstore.com). Du burde derfor kun skulle rette dit Auto-valg og helst sætte argumenter for NHDDL efter den enhed, du indlæser ISO'er fra.

<a id="config-path-search-order"></a>

### Søgerækkefølge for konfigurationen

Søgningen efter konfigurationen tager nu højde for opstartsfamilien, så der ikke indlæses unødvendige drivere ved start:

1. `CONFIG.INI` (CWD: nuværende arbejdsmappe)
2. Ved indlæsning fra en enhed:
   - MMCE-opstart: `mmce?:/PS2BBL/CONFIG.INI`
   - MX4SIO-opstart: `mx4sio:/PS2BBL/CONFIG.INI`
   - APA HDD-opstart: `hdd0:__sysconf:pfs:/PS2BBL/CONFIG.INI`
   - BDM-opstart: `usb:/PS2BBL/CONFIG.INI` / `mass:/PS2BBL/CONFIG.INI` / `ata:/PS2BBL/CONFIG.INI`
3. Reserve på memory card:
   - På PS2: `mc?:/SYS-CONF/PS2BBL.INI`
   - På PSX-DESR: `mc?:/SYS-CONF/PSXBBL.INI`
4. Sidste reserve på PSX
   - `xfrom:/PS2BBL/CONFIG.INI`
5. Når der er kompileret med `DISC_STOP_AT_BOOT=1
   - `cdrom0:/PS2BBL/CONFIG.INI`
   - Reserve på memory card som i punkt 3 ovenfor.

<a id="device-path-prefixes"></a>

### Stipræfikser for enheder
PS2BBL understøtter disse præfikser til start- og konfigurationsstier:
- `mc0:/`, `mc1:/`, `mc?:/`
- `usb:/` (foretrukket) og `mass:/` (gammel)

<a id="build-specific"></a>

#### Afhængigt af build:  
- `mmce0:/`, `mmce1:/`, `mmce?:/` __MMCE-builds__
- `mx4sio:/` (foretrukket) og `massX:/` (gammel)  __MX4SIO-builds__
- `hdd0:partition:pfs:/<path to elf>` __HDD-builds__
- `xfrom:/`-stier __PSX DESR-builds__
- `ata:/` BDM-enhed til exFAT-HDD
- `ilink:/` (BDM-masselagerrødder) __endnu ikke implementeret__
- `DISC_STOP_AT_BOOT=1` buildprofil, der altid stopper den optiske disk efter indlæsning af konfigurationen

### LOGO_DISPLAY
Brug `LOGO_DISPLAY = 3` til at vise tasternes navne. Navnene sættes med `NAME_<BUTTON>`.
  - `0` Hverken logo eller konsolinfo
  - `1` Konsolinfo
  - `2` PS2BBLE/PSXBBLE-logo og konsolinfo
  - `3` Tastegrafik med `NAME_BUTTON = <TITLE>` fra konfigurationsfilen
    - Eksempel:
      ```
      NAME_SQUARE = POPSLOADER
      ```

<a id="custom-splash-logo-from-cwd"></a>

#### Eget startlogo fra CWD
Findes der en egen logofil (LOGO.BIN) i CWD (nuværende arbejdsmappe), erstatter den det indbyggede PS2BBLE/PSXBBLE-logo.

Konvertér en PNG til den forventede rå fil:
  - PNG'en skal være RGBA 8 bit indekseret, 255 farver pr. kanal og 256x64 i opløsning.

  - Udgivelsespakke (scriptet ligger i udgivelsens rod):
  ```bash
  python png_to_logo_rbga.py my_logo.png
  ```

  - Læg den oprettede `LOGO.BIN` ved siden af PS2BBL Extended. Det bør være `mc?:/BOOT/`, hvis du bruger downloads fra [PS2 Homebrew Store](https://ps2store.com)

<a id="retrogem-visual-game-id"></a>

### Visuelt spil-ID fra Retrogem
- `APP_GAMEID = 1` slår visuelt spil-ID til for apps/homebrew, op til 11 tegn fra filnavnet eller PS1/2-disken
- `CDROM_DISABLE_GAMEID = 1` slår visuelt spil-ID fra for diske startet via `cdrom`.

<a id="disc-spin-control"></a>

### Styring af diskens rotation
- Global nøgle/værdi: `DISC_STOP = 0/1`
- `DISC_STOP = 1` stopper den optiske disk efter indlæsning af konfigurationen, når der blev fundet en konfigurationsfil.
- `DISC_STOP = 0` (eller udeladt) beholder standardopførslen.
- `-disc_stop` kan tilføjes pr. startpost for at stoppe disken, når mål-ELF'en er fundet.

<a id="video-mode"></a>

### Videotilstand
- `VIDEO_MODE = AUTO, NTSC, PAL, 480P` Bruger PS2'ens standard eller tvinger en af de andre 3 tilstande.

<a id="emergency-video-mode-selector"></a>

#### Nødvælger til videotilstand
- Åbnes med `TRIANGLE + CROSS` under opstart
- Vælgeren tvinger `LOGO_DISPLAY = 3`, mens den er aktiv, så du kan se logoet og tasterne.
- Betjening:
  - `LEFT/RIGHT` skifter tilstand: `AUTO`, `NTSC`, `PAL`, `480P`
  - `SELECT` gemmer den valgte tilstand i den aktive konfigurationsfil
  - `START` forlader vælgeren og fortsætter til tastevisningen

<a id="cdrom-launch-args"></a>

### Startargumenter for CDROM
For `LK_*_E* = cdrom` understøttes disse argumenter:
- `-nologo`
- `-nogameid`
- `-ps1fast`
- `-ps1smooth`
- `-ps1vneg`
- `-gsm=<v[:c]>`

<a id="ps2logo-arguments-ps2-discs-only"></a>

#### PS2LOGO-argumenter (kun PS2-diske)
- Brug `cdrom` som startpostens sti.
- Tilføj `-nologo` til postens argumenter for at starte PS2-diske direkte (uden `rom0:PS2LOGO`).
- Uden `-nologo` starter PS2BBL disken via PS2LOGO og patcher det til altid at bruge diskens region og springe logoets checksumtjek over.
- DECKARD IE 75K og nyere: XPARAM.IRX anvendes automatisk, når det er nødvendigt ved start uden logo.

<a id="ps1-disc-arguments-per-launch"></a>

#### Argumenter til PS1-diske (pr. start)
De gælder pr. `cdrom`-startpost, ikke globalt.
- `-ps1fast` slår hurtig diskhastighed til for PS1.
- `-ps1smooth` slår teksturudglatning til.
- `-ps1vneg` kører PS1DRV via PS1VModeNegator. Nyttigt på opsætninger, hvor konsollens og diskens tilstand er forskellige (for eksempel visse MechaPwn/modchip-tilfælde).

<a id="app-arguments"></a>

### App-argumenter
Brug linjer `ARG_<BUTTON>_E? =` til at give argumenter til en ELF (se INI-eksemplerne).
- Sæt først den startede elf's argumenter og tilføj derefter de ønskede interne PS2BBL-argumenter (se nedenfor). [NHDDL](https://github.com/pcm720/nhddl) er en god kandidat til argumenter, da de gør opstarten af NHDDL hurtigere.
- `-titleid=SLUS_123.45` overskriver appens titel-ID (op til 11 tegn).
- `-appid` tvinger appens visuelle spil-ID, selv med `APP_GAMEID = 0`.
- `-disc_stop` stopper disken, efter at mål-ELF'en er indlæst (nyttigt pr. post uden `DISC_STOP_AT_BOOT`-builds).
- `-gsm=<v[:c]>` kører mål-ELF'en via den indbyggede eGSM (ignoreres for `rom?:`-stier). Hvis den bruges, skal den være det sidste argument.
- `-disc_stop` ignoreres for `cdrom`-startposter.
- `-dev9=<mode>` sætter DEV9/HDD-politikken, før mål-ELF'en startes. Understøttede tilstande:
  - `NICHDD` holder både DEV9 (netværksadapter) og HDD tændt.
  - `NIC` holder DEV9/netværk tændt, afmonterer `pfs0:` og sætter `hdd0:`/`hdd1:` i dvale med det samme.
  - hvis udeladt, tvinger PS2BBL ingen DEV9-politik.
  - bemærk: på builds uden HDD har denne indstilling ingen virkning.
- `-patinfo` slår håndtering af PATINFO til for `:PATINFO`-poster.
  - PS2BBL læser `SYSTEM.CNF` fra partitionens attributområde (`PS2ICON3D`) og anvender `BOOT2/BOOT/path`, `arg*`, `skip_argv0` og `HDDUNITPOWER`.
  - ved `BOOT2/BOOT/path=PATINFO` indlæser PS2BBL den indbyggede ELF fra partitionens attributområde og bruger den interne overdragelse `-la=E...`.
  - ved `IOPRP=PATINFO` (eller en egen sti) giver PS2BBL den videre til trin 2 via den interne overdragelse `-la=I...`.
  - hvis `-patinfo` er til stede, overskriver det første resterende argument CNF-målet `BOOT2/BOOT/path`.
  Dette gælder HDD-builds.  
  PATINFO-eksempel:  
    ```
    NAME_R1 = My App via PATINFO
    LK_R1_E1 = hdd0:+OSDMENU:PATINFO
    ARG_R1_E1 = pfs:/APPS/MYAPP.ELF
    ARG_R1_E1 = -patinfo               # Tells PS2BBL to use first arg as patinfo boot path.
    ```

Eksempel på at starte NHDDL i videotilstand 480p og lede efter ISO'er på mmce og en exFAT-HDD uden at behøve nhddl.yaml. Fordelen er, at der ikke spildes tid på at indlæse drivere og finde og indlæse nhddl.yaml. Det er den hurtigste måde at starte NHDDL og vise ISO-listen på.
```
NAME_R1 = NHDDL
LK_R1_E1 = mmce?:/NEUTRINO/nhddl.elf
ARG_R1_E1 = -video=480p
ARG_R1_E1 = -mode=mmce
ARG_R1_E1 = -mode=ata
```

<a id="argument-precedence-and-order"></a>

#### Argumenternes forrang og rækkefølge
1. PS2BBL læser og forbruger kun loaderens styreargumenter i slutningen af `ARG_*`: `-appid`, `-titleid=`, `-dev9=`, `-patinfo`, `-disc_stop`, `-gsm=`.
2. Der læses nedefra og op, og det stopper ved det første argument, der ikke er et styreargument (slutopførsel som i OSDMenu).
4. For `:PATINFO`-startstier læser PS2BBL partitionsattributtens `SYSTEM.CNF` og tilføjer CNF'ens `arg*`-poster efter brugerens app-argumenter.
5. Hvis `-patinfo` er sat, og startstien indeholder `:PATINFO`, bliver brugerens første resterende app-argument mål-ELF'ens sti (det overskriver CNF'ens opstartssti) og fjernes fra appens argv. Er der intet argument tilbage, afbrydes starten (som i OSDMenu), og CNF'ens `BOOT2/BOOT/path` bruges ikke.
6. De resterende argumenter beholder deres rækkefølge og gives videre til den startede app.


### eGSM (external Graphics Synthesize Mode)
For PS2-diske læses eGSM automatisk fra `OSDGSM.CNF` (ingen sti i INI'en nødvendig). Se [her](https://github.com/pcm720/OSDMenu/blob/main/patcher/README.md#osdgsmcnf) for konfigurationsfilens format.

- `-gsm=<v[:c]>` kører mål-ELF'en via den indbyggede eGSM (ignoreres for `rom?:`-stier).
  - eGSM anvendes på det startede mål (ELF/disk), ikke på PS2BBL selv.
  eGSM-format (som i OSDMenu):
- `v` = videotilstand:
- tom = tving intet (standard)
- `fp1` = tving progressiv skanning (240p/288p)
- `fp2` = tving progressiv skanning (480p/576p)
- `1080ix1` = tving 1080i, bredde/højde x1
- `1080ix2` = tving 1080i, bredde/højde x2
- `1080ix3` = tving 1080i, bredde/højde x3
- `c` = kompatibilitetstilstand:
- tom = ingen (standard)
- `1` = feltvending type 1
- `2` = feltvending type 2
- `3` = feltvending type 3

Eksempler på eGSM-ARG:
- `-gsm=fp2`
- `-gsm=fp2:1`
- `-gsm=1080ix2`

Brugseksempel:
```
LK_TRIANGLE_E1 = mc0:/APP_WLE-ISR/WLE-ISR.ELF
ARG_TRIANGLE_E1 = -gsm=1080ix2
```

<a id="deprecatedremoved"></a>

## Forældet/Fjernet
- ~~`RUNKELF`~~ PS2BBLE starter nu elf/kelf internt, uden at brugeren skal definere en kelf-starthandling.


<a id="known-bugsissues"></a>

## Kendte fejl/problemer

det må du fortælle mig ;)

<a id="credits--thanks"></a>

## Krediteringer og tak

- Fra saildot4k
  - @israpps for [PS2BBL](https://github.com/israpps/PlayStation2-Basic-BootLoader/)
  - @pcm720 for
    - Retrogem gameID, PS1 Video Negator, eGSM og PS2LOGO-koden fra [OSDMenu](https://github.com/pcm720/OSDMenu)
    - videotilstandsindstillingerne fra [NHDDL](https://github.com/pcm720/nhddl)
  - @sp193 for [PS1 Video Negator](https://github.com/ps2homebrew/PS1VModeNeg)
  - @nathanneurotic for PS2BBLE's 10 stier, idéer og overtalelse
  - [@Berion](https://www.psx-place.com/members/berion.1431/) for logoer, baggrund og tastegrafik

- Fra [El Isra](https://israpps.github.io/) (udvikler af PS2BBL): 
  - @SP193 for OSD-initialiseringsbibliotekerne, som er grundlaget for dette projekt
  - @asmblur, for at opmuntre mig til at lave dette monster på den nyeste SDK
  - @uyjulian og @fjtrujy, fordi de altid hjælper mig


<p align="center"><sub><a href="https://github.com/akilluminati47/RIPPS2">RIPPS2</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2/releases/latest/download/RIPPS2.elf">Hent</a> &nbsp;&middot;&nbsp; <b>BIBLE</b> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2-themes">Temaer</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPCSX2">RIPPCSX2</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2-fonts">Skrifttyper</a> &nbsp;&middot;&nbsp; <a href="https://akilluminati47.github.io/RIPPS2/">Websted</a> &nbsp;&middot;&nbsp; <a href="https://www.psx-place.com/threads/ripps2-a-ps2-front-end-in-one-elf-launch-disc-storage-memory-files.51316/">psx-place</a> &nbsp;&middot;&nbsp; <a href="https://discord.gg/Z7m9u5kby">Discord</a></sub></p>

