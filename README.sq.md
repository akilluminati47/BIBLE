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
  <b>Shqip</b> |
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

<p align="center"><sub>Përkthim i README-së në anglisht; nëse ndryshojnë, vlen anglishtja. <a href="README.md">English</a></sub></p>

<p align="center"><sub><a href="https://github.com/akilluminati47/RIPPS2">RIPPS2</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2/releases/latest/download/RIPPS2.elf">Shkarko</a> &nbsp;&middot;&nbsp; <b>BIBLE</b> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2-themes">Temat</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPCSX2">RIPPCSX2</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2-fonts">Fontet</a> &nbsp;&middot;&nbsp; <a href="https://akilluminati47.github.io/RIPPS2/">Faqja</a> &nbsp;&middot;&nbsp; <a href="https://www.psx-place.com/threads/ripps2-a-ps2-front-end-in-one-elf-launch-disc-storage-memory-files.51316/">psx-place</a> &nbsp;&middot;&nbsp; <a href="https://discord.gg/Z7m9u5kby">Discord</a></sub></p>

<h1 align="center">BIBLE</h1>
<p align="center">
  <a href="https://github.com/akilluminati47/RIPPS2">RIPPS2</a> ·
  <a href="https://github.com/akilluminati47/BIBLE/actions">Ndërtimet</a> ·
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
  <sub>Mbaj L2 + R2 gjatë ndezjes për faqen e tasteve të nisjes, TRIANGLE + CROSS për faqen e mënyrës video; një tast i vendosur në <code>$CREDITS</code> shfaq kreditet.</sub>
</p>

BIBLE është ngarkuesi i nisjes që vendos RIPPS2: një fork i PS2BBL Extended të saildot4k.

**Çfarë ndryshon ky fork**

- Ekrani i hapjes: logoja e PS2 në mes të qiellit të RIPPS2, me butonat poshtë saj dhe çdo tekst sipër. `BIBLE_GLYPHS` 0 asnjë, 1 butonat e veprimit (parazgjedhje), 2 të gjashtëmbëdhjetë në dy rreshta me tetë. `BIBLE_INFO` 1 shfaq të dhënat e konsolës, orën dhe numërimin mbrapsht (i fikur si parazgjedhje). Qielli ndjek Color Theme-n tënd të RIPPS2: pa `BIBLE_COLOR`, BIBLE lexon qiellin që RIPPS2 ruan me cilësimet e tij, nga dosja që nis hyrja e tij AUTO, ose nga dosja `RIPPS2` e një karte memorieje kur hyrja AUTO është RIPPS2 në një SD2PSX, USB ose diskun e ngurtë (`BIBLE_COLOR` në konfigurim fiton). E njëjta pamje në çdo mënyrë video.
- `BIBLE_BACKGROUND`: `AUTO` (parazgjedhje: qielli kur gjenden cilësimet e RIPPS2 ose është vendosur `BIBLE_COLOR`, përndryshe e zezë në mënyrën e vetë konsolës, një ngarkues i thjeshtë), `SKY` ose `BLANK` (e zezë). Kalimi në një program është gjithsesi i zi për disa sekonda, ndaj e zeza duket një copë e vetme me të.
- Tingulli i nisjes, i përgatitur: Boot Sound On (fast) i RIPPS2 mund ta mbajë `boot.adp` pranë konfigurimit të BIBLE (`mc?:/SYS-CONF/boot.adp`). Lexohet para se të niset çdo njësi. BIBLE mund t'ia dorëzojë edhe RIPPS2 në RAM, por kjo ka kaluar vetëm në laborator: në një SD2PSX të vërtetë, RIPPS2 e lexoi vetë kopjen e kartës. **Pa tingull nisja është më e shpejta.** Marrëveshja dhe ana e RIPPS2: [docs/boot-sound-handoff.md](docs/boot-sound-handoff.md).
- RIPPS2 i pari: shablloni i konfigurimit (`release/SYS-CONF/PS2BBL.INI`) dhe vlerat e brendshme provojnë `mc?:/RIPPS2/RIPPS2.ELF` dhe `mmce?:/APPS/RIPPS2.ELF` para OSDMenu dhe FMCB, dhe shablloni rendit çelësat e vetë BIBLE me shënime. Faqet (mënyra video, kreditet, tastet e nisjes) shfaqen mbi logon e zbehur me butonat të mënjanuar, që tastet e nisjes të lexohen qetë.
- Mënyrat video: `VIDEO_MODE` pranon edhe `576P`, `720P` dhe `1080I`, mënyrat e tjera të RIPPS2. `AUTO` (parazgjedhje)
  nis në Video Mode të RIPPS2 kur cilësimet e tij janë pranë hyrjes AUTO, përndryshe në mënyrën e konsolës.
- `BIBLE_WIDESCREEN`: `AUTO` (parazgjedhje: Widescreen i RIPPS2, përndryshe cilësimi i ekranit 16:9 i PS2), `ON` ose
  `OFF`. Në 480i, 576i, 480p dhe 576p ekrani i hapjes vizatohet për një televizor që e shtrin figurën në 16:9, pa
  e shtypur. 720p dhe 1080i janë tashmë 16:9.
- Kalimi në RIPPS2: gjatë nisjes logoja dhe butonat zbehen dhe qielli mbetet derisa konsola të ngarkojë programin tjetër, gjë që e nxin ekranin (rreth 7 s në laborator me RIPPS2 në një kartë memorie). Pastaj RIPPS2 shfaqet në të njëjtën mënyrë video dhe me të njëjtat ngjyra. Mbaj TRIANGLE + CROSS gjatë ndezjes për faqen e mënyrës video, që hapet gjithmonë
  në mënyrën e ndërthurur të vetë konsolës (rruga e kthimit nga 720p ose 1080i me kabllo kompozit).
- E re: faqja e tasteve të nisjes. Mbaj L2 + R2 kur ndez dhe BIBLE ndalon para se të nisë diçka, duke treguar shtigjet aktuale të nisjes për çdo tast, cilado qofshin cilësimet e ekranit të hapjes (e dobishme me `LOGO_DISPLAY = 0`, ku s'shfaqet asgjë tjetër).
- Kombinimet e mbajtura që nga ndezja tani hapin faqet e tyre (TRIANGLE + CROSS humbiste kur kontrollorët ende
  po niseshin).
- Lejohet `KEY_READ_WAIT_TIME = 0` (minimumi i upstream është 500 ms).
- Ndërtime për PS2 për kartë memorieje / USB, MMCE, MX4SIO dhe HDD. Faza 2 e eGSM lihet jashtë.

**Si e përdor RIPPS2**

RIPPS2 e mbart BIBLE brenda RIPPS2.elf, çdo version i nënshkruar nga akilluminati47, dhe e instalon ose e përditëson nga Cilësimet > Të përgjithshme > Boot Loader > Manage, që vendos edhe çelësat e BIBLE: Background, Splash, Button Glyphs, Info Line, Power-on Wait, Video Mode dhe Widescreen. Versionet e nënshkruara dhe një kartë BOOT SD2PSX e gatshme janë në [faqen e versioneve](https://github.com/akilluminati47/BIBLE/releases/latest). BIBLE punon edhe si ELF i nisur nga një ngarkues tjetër (FMCB, OSDMenu, ngarkuesi i një SD2PSX).

<p align="center"><img src="assets/readme/ripps2-icon.png" alt="RIPPS2" width="48" height="48"><br><sub>BIBLE është pjesë e <a href="https://github.com/akilluminati47/RIPPS2">RIPPS2</a>.</sub></p>

---

<p align="center"><sub>Gjithçka më poshtë është README origjinal i PS2BBL Extended, i përkthyer dhe përndryshe i pandryshuar.</sub></p>

---


<br />
<p align="center">
  <a href="https://israpps.github.io/PlayStation2-Basic-BootLoader/">
    <img src="https://github.com/saildot4k/PlayStation2-Basic-BootLoader-Extended/blob/main/assets/ps2bbl_example.png" alt="Logo" width="50%" height="auto">
  </a>

  <p align="center">
    Një ngarkues nisjeje fleksibël për PlayStation 2™ dhe PSX-DESR
    <br />
  </p>
</p>  


Ky është një fork i PS2BBL nga [El Isra](https://github.com/israpps/PlayStation2-Basic-BootLoader/)


<a id="documentation"></a>

## Dokumentimi

Ndodhet në [github pages](https://israpps.github.io/PlayStation2-Basic-BootLoader/), por me shtesat më poshtë:

<a id="config-and-arguments"></a>

## Konfigurimi dhe argumentet

Ndrysho skedarin e konfigurimit sipas nevojës. Për ta ndryshuar rekomandohet [R3Configurator](https://github.com/saildot4k/R3CONFIGURATOR). Shtigjet janë vendosur tashmë që të përputhen me shkarkimet nga [PS2 Homebrew Store](https://ps2homebrewstore.com). Kështu duhet të ndryshosh vetëm zgjedhjen Auto dhe, më mirë, të vendosësh argumentet për NHDDL sipas pajisjes nga e cila ngarkon ISO-t.

<a id="config-path-search-order"></a>

### Rendi i kërkimit të konfigurimit

Kërkimi i konfigurimit tani merr parasysh familjen e nisjes, që të mos ngarkohen drejtues të panevojshëm gjatë nisjes:

1. `CONFIG.INI` (CWD: dosja aktuale e punës)
2. Kur ngarkohet nga një pajisje:
   - Nisje nga MMCE: `mmce?:/PS2BBL/CONFIG.INI`
   - Nisje nga MX4SIO: `mx4sio:/PS2BBL/CONFIG.INI`
   - Nisje nga APA HDD: `hdd0:__sysconf:pfs:/PS2BBL/CONFIG.INI`
   - Nisje nga BDM: `usb:/PS2BBL/CONFIG.INI` / `mass:/PS2BBL/CONFIG.INI` / `ata:/PS2BBL/CONFIG.INI`
3. Rezervë në kartën e memories:
   - Në PS2: `mc?:/SYS-CONF/PS2BBL.INI`
   - Në PSX-DESR: `mc?:/SYS-CONF/PSXBBL.INI`
4. Rezerva e fundit në PSX
   - `xfrom:/PS2BBL/CONFIG.INI`
5. Kur kompilohet me `DISC_STOP_AT_BOOT=1
   - `cdrom0:/PS2BBL/CONFIG.INI`
   - Rezervë në kartën e memories si në pikën 3 më sipër.

<a id="device-path-prefixes"></a>

### Parashtesat e shtigjeve të pajisjeve
PS2BBL mbështet këto parashtesa shtigjesh nisjeje/konfigurimi:
- `mc0:/`, `mc1:/`, `mc?:/`
- `usb:/` (e preferuar) dhe `mass:/` (e vjetër)

<a id="build-specific"></a>

#### Sipas ndërtimit:  
- `mmce0:/`, `mmce1:/`, `mmce?:/` __ndërtimet MMCE__
- `mx4sio:/` (e preferuar) dhe `massX:/` (e vjetër)  __ndërtimet MX4SIO__
- `hdd0:partition:pfs:/<path to elf>` __ndërtimet HDD__
- Shtigjet `xfrom:/` __ndërtimet PSX DESR__
- `ata:/` pajisje BDM për HDD exFAT
- `ilink:/` (rrënjët e ruajtjes masive BDM) __ende e pazbatuar__
- `DISC_STOP_AT_BOOT=1` profil ndërtimi që e ndalon gjithmonë diskun optik pas ngarkimit të konfigurimit

### LOGO_DISPLAY
Përdor `LOGO_DISPLAY = 3` për të shfaqur emrat e tasteve. Emrat përcaktohen nga `NAME_<BUTTON>`.
  - `0` Pa logo dhe pa informacion konsole
  - `1` Informacioni i konsolës
  - `2` Logoja PS2BBLE/PSXBBLE dhe informacioni i konsolës
  - `3` Grafika e tasteve me `NAME_BUTTON = <TITLE>` nga skedari i konfigurimit
    - Shembull:
      ```
      NAME_SQUARE = POPSLOADER
      ```

<a id="custom-splash-logo-from-cwd"></a>

#### Logo e vetë e hapjes nga CWD
Nëse në CWD (dosjen aktuale të punës) gjendet një skedar logoje i vetë (LOGO.BIN), ai zëvendëson logon e integruar PS2BBLE/PSXBBLE.

Shndërro një PNG në skedarin e papërpunuar të pritur:
  - PNG duhet të jetë RGBA 8 bit i indeksuar, 255 ngjyra për kanal dhe rezolucion 256x64.

  - Paketa e botimit (skripti është në rrënjën e botimit):
  ```bash
  python png_to_logo_rbga.py my_logo.png
  ```

  - Vendos `LOGO.BIN` e krijuar pranë PS2BBL Extended. Duhet të jetë `mc?:/BOOT/` nëse përdor shkarkime nga [PS2 Homebrew Store](https://ps2store.com)

<a id="retrogem-visual-game-id"></a>

### ID vizuale e lojës nga Retrogem
- `APP_GAMEID = 1` aktivizon ID-në vizuale të lojës për aplikacione/homebrew, deri në 11 karaktere nga emri i skedarit ose disku PS1/2
- `CDROM_DISABLE_GAMEID = 1` çaktivizon ID-në vizuale të lojës për disqet e nisura nëpërmjet `cdrom`.

<a id="disc-spin-control"></a>

### Kontrolli i rrotullimit të diskut
- Çelës/vlerë globale: `DISC_STOP = 0/1`
- `DISC_STOP = 1` ndalon diskun optik pas ngarkimit të konfigurimit kur u gjet një skedar konfigurimi.
- `DISC_STOP = 0` (ose i hequr) ruan sjelljen e parazgjedhur.
- `-disc_stop` mund t'i shtohet çdo hyrjeje nisjeje për ta ndalur diskun pasi të gjendet ELF-i i synuar.

<a id="video-mode"></a>

### Mënyra video
- `VIDEO_MODE = AUTO, NTSC, PAL, 480P` Përdor parazgjedhjen e PS2 ose detyron një nga 3 mënyrat e tjera.

<a id="emergency-video-mode-selector"></a>

#### Zgjedhësi emergjent i mënyrës video
- Hapet me `TRIANGLE + CROSS` gjatë nisjes
- Zgjedhësi detyron `LOGO_DISPLAY = 3` sa është aktiv, që të shohësh logon dhe tastet.
- Kontrollet:
  - `LEFT/RIGHT` ndërrojnë mënyrat: `AUTO`, `NTSC`, `PAL`, `480P`
  - `SELECT` ruan mënyrën e zgjedhur në skedarin aktiv të konfigurimit
  - `START` del nga zgjedhësi dhe vazhdon te shfaqja e tasteve

<a id="cdrom-launch-args"></a>

### Argumentet e nisjes për CDROM
Për `LK_*_E* = cdrom`, argumentet e mbështetura janë:
- `-nologo`
- `-nogameid`
- `-ps1fast`
- `-ps1smooth`
- `-ps1vneg`
- `-gsm=<v[:c]>`

<a id="ps2logo-arguments-ps2-discs-only"></a>

#### Argumentet e PS2LOGO (vetëm disqe PS2)
- Përdor `cdrom` si shteg të hyrjes së nisjes.
- Shto `-nologo` te argumentet e hyrjes për t'i nisur disqet PS2 drejtpërdrejt (pa `rom0:PS2LOGO`).
- Pa `-nologo`, PS2BBL e nis diskun nëpërmjet PS2LOGO dhe e arnon që të përdorë gjithmonë rajonin e diskut dhe të anashkalojë kontrollin e checksum të logos.
- DECKARD IE 75K e më të rinj: XPARAM.IRX zbatohet automatikisht kur nevojitet për nisjet pa logo.

<a id="ps1-disc-arguments-per-launch"></a>

#### Argumentet e disqeve PS1 (për çdo nisje)
Vlejnë për çdo hyrje nisjeje `cdrom`, jo globalisht.
- `-ps1fast` aktivizon shpejtësinë e shpejtë të diskut PS1.
- `-ps1smooth` aktivizon zbutjen e teksturave.
- `-ps1vneg` nis PS1DRV nëpërmjet PS1VModeNegator. E dobishme kur mënyra e konsolës dhe ajo e diskut ndryshojnë (për shembull disa raste MechaPwn/modchip).

<a id="app-arguments"></a>

### Argumentet e aplikacioneve
Përdor rreshtat `ARG_<BUTTON>_E? =` për t'i dhënë argumente një ELF-i (shih shembujt INI).
- Vendos fillimisht argumentet e elf-it që niset dhe pastaj shto argumentet e brendshme të PS2BBL që dëshiron (shih më poshtë). [NHDDL](https://github.com/pcm720/nhddl) është kandidat i shkëlqyer për argumente, sepse ia përshpejtojnë nisjen.
- `-titleid=SLUS_123.45` zëvendëson ID-në e titullit të aplikacionit (deri në 11 karaktere).
- `-appid` detyron ID-në vizuale të lojës së aplikacionit edhe kur `APP_GAMEID = 0`.
- `-disc_stop` ndalon diskun pasi ngarkohet ELF-i i synuar (e dobishme për hyrje pa ndërtime `DISC_STOP_AT_BOOT`).
- `-gsm=<v[:c]>` nis ELF-in e synuar nëpërmjet eGSM të integruar (shpërfillet për shtigjet `rom?:`). Nëse përdoret, duhet të jetë argumenti i fundit.
- `-disc_stop` shpërfillet për hyrjet e nisjes `cdrom`.
- `-dev9=<mode>` vendos politikën DEV9/HDD para nisjes së ELF-it të synuar. Mënyrat e mbështetura:
  - `NICHDD` mban të ndezura si DEV9 (përshtatësin e rrjetit) ashtu edhe HDD-në.
  - `NIC` mban të ndezur DEV9/rrjetin, çmonton `pfs0:` dhe vë menjëherë në pushim `hdd0:`/`hdd1:`.
  - nëse hiqet, PS2BBL nuk detyron asnjë politikë DEV9.
  - shënim: në ndërtimet pa HDD ky opsion nuk ka efekt.
- `-patinfo` aktivizon trajtimin e PATINFO për hyrjet `:PATINFO`.
  - PS2BBL lexon `SYSTEM.CNF` nga zona e atributeve të ndarjes (`PS2ICON3D`) dhe zbaton `BOOT2/BOOT/path`, `arg*`, `skip_argv0` dhe `HDDUNITPOWER`.
  - nëse `BOOT2/BOOT/path=PATINFO`, PS2BBL ngarkon ELF-in e integruar nga zona e atributeve të ndarjes dhe përdor dorëzimin e brendshëm `-la=E...`.
  - nëse `IOPRP=PATINFO` (ose një shteg i vetë), PS2BBL ia kalon fazës 2 nëpërmjet dorëzimit të brendshëm `-la=I...`.
  - nëse `-patinfo` është i pranishëm, argumenti i parë i mbetur zëvendëson objektivin `BOOT2/BOOT/path` të CNF.
  Kjo vlen për ndërtimet HDD.  
  Shembull PATINFO:  
    ```
    NAME_R1 = My App via PATINFO
    LK_R1_E1 = hdd0:+OSDMENU:PATINFO
    ARG_R1_E1 = pfs:/APPS/MYAPP.ELF
    ARG_R1_E1 = -patinfo               # Tells PS2BBL to use first arg as patinfo boot path.
    ```

Shembull për të nisur NHDDL në mënyrën video 480p dhe për të kërkuar ISO në mmce dhe në një HDD exFAT pa pasur nevojë për nhddl.yaml. Përfitimi është se nuk humbet kohë me ngarkimin e drejtuesve, gjetjen dhe ngarkimin e nhddl.yaml. Kjo është mënyra më e shpejtë për të nisur NHDDL dhe për të shfaqur listën e ISO-ve.
```
NAME_R1 = NHDDL
LK_R1_E1 = mmce?:/NEUTRINO/nhddl.elf
ARG_R1_E1 = -video=480p
ARG_R1_E1 = -mode=mmce
ARG_R1_E1 = -mode=ata
```

<a id="argument-precedence-and-order"></a>

#### Përparësia dhe rendi i argumenteve
1. PS2BBL analizon dhe konsumon vetëm argumentet e kontrollit të ngarkuesit në fund të `ARG_*`: `-appid`, `-titleid=`, `-dev9=`, `-patinfo`, `-disc_stop`, `-gsm=`.
2. Analiza shkon nga poshtë lart dhe ndalet te argumenti i parë që nuk është kontrolli (sjellje përfundimtare si në OSDMenu).
4. Për shtigjet e nisjes `:PATINFO`, PS2BBL analizon `SYSTEM.CNF` të atributit të ndarjes dhe shton hyrjet `arg*` të CNF pas argumenteve të aplikacionit të përdoruesit.
5. Nëse `-patinfo` është vendosur dhe shtegu i nisjes përmban `:PATINFO`, argumenti i parë i mbetur i përdoruesit bëhet shtegu i ELF-it të synuar (zëvendëson shtegun e nisjes së CNF) dhe hiqet nga argv i aplikacionit. Nëse nuk mbetet asnjë argument, nisja anulohet (si në OSDMenu) dhe `BOOT2/BOOT/path` i CNF nuk përdoret.
6. Argumentet e mbetura ruajnë rendin dhe i kalohen aplikacionit të nisur.


### eGSM (external Graphics Synthesize Mode)
Për disqet PS2, eGSM lexohet automatikisht nga `OSDGSM.CNF` (nuk nevojitet shteg në INI). Shih [këtu](https://github.com/pcm720/OSDMenu/blob/main/patcher/README.md#osdgsmcnf) formatin e skedarit të konfigurimit.

- `-gsm=<v[:c]>` nis ELF-in e synuar nëpërmjet eGSM të integruar (shpërfillet për shtigjet `rom?:`).
  - eGSM zbatohet te objektivi i nisur (ELF/disk), jo te vetë PS2BBL.
  Formati i eGSM (si në OSDMenu):
- `v` = mënyra video:
- bosh = mos detyro asgjë (parazgjedhje)
- `fp1` = detyro skanimin progresiv (240p/288p)
- `fp2` = detyro skanimin progresiv (480p/576p)
- `1080ix1` = detyro 1080i, gjerësi/lartësi x1
- `1080ix2` = detyro 1080i, gjerësi/lartësi x2
- `1080ix3` = detyro 1080i, gjerësi/lartësi x3
- `c` = mënyra e përputhshmërisë:
- bosh = asnjë (parazgjedhje)
- `1` = përmbysje e fushave lloji 1
- `2` = përmbysje e fushave lloji 2
- `3` = përmbysje e fushave lloji 3

Shembuj ARG për eGSM:
- `-gsm=fp2`
- `-gsm=fp2:1`
- `-gsm=1080ix2`

Shembull përdorimi:
```
LK_TRIANGLE_E1 = mc0:/APP_WLE-ISR/WLE-ISR.ELF
ARG_TRIANGLE_E1 = -gsm=1080ix2
```

<a id="deprecatedremoved"></a>

## E vjetruar/E hequr
- ~~`RUNKELF`~~ PS2BBLE tani i nis elf/kelf brenda vetes, pa pasur nevojë që përdoruesi të përcaktojë një veprim nisjeje kelf.


<a id="known-bugsissues"></a>

## Gabime/probleme të njohura

më trego ti ;)

<a id="credits--thanks"></a>

## Kreditet dhe falënderimet

- Nga saildot4k
  - @israpps për [PS2BBL](https://github.com/israpps/PlayStation2-Basic-BootLoader/)
  - @pcm720 për
    - gameID e Retrogem, PS1 Video Negator, eGSM dhe kodin PS2LOGO nga [OSDMenu](https://github.com/pcm720/OSDMenu)
    - opsionet e mënyrës video nga [NHDDL](https://github.com/pcm720/nhddl)
  - @sp193 për [PS1 Video Negator](https://github.com/ps2homebrew/PS1VModeNeg)
  - @nathanneurotic për 10 shtigjet e PS2BBLE, idetë dhe bindjen
  - [@Berion](https://www.psx-place.com/members/berion.1431/) për logot, sfondin dhe grafikën e tasteve

- Nga [El Isra](https://israpps.github.io/) (zhvilluesi i PS2BBL): 
  - @SP193 për bibliotekat e inicializimit të OSD, që janë themeli i këtij projekti
  - @asmblur, që më nxiti ta bëj këtë përbindësh me SDK-në më të re
  - @uyjulian dhe @fjtrujy që më ndihmojnë gjithmonë


<p align="center"><sub><a href="https://github.com/akilluminati47/RIPPS2">RIPPS2</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2/releases/latest/download/RIPPS2.elf">Shkarko</a> &nbsp;&middot;&nbsp; <b>BIBLE</b> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2-themes">Temat</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPCSX2">RIPPCSX2</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2-fonts">Fontet</a> &nbsp;&middot;&nbsp; <a href="https://akilluminati47.github.io/RIPPS2/">Faqja</a> &nbsp;&middot;&nbsp; <a href="https://www.psx-place.com/threads/ripps2-a-ps2-front-end-in-one-elf-launch-disc-storage-memory-files.51316/">psx-place</a> &nbsp;&middot;&nbsp; <a href="https://discord.gg/Z7m9u5kby">Discord</a></sub></p>

