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
  <b>Română</b> |
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

<p align="center"><sub>Traducerea README-ului în engleză; dacă diferă, este valabilă engleza. <a href="README.md">English</a></sub></p>

<p align="center"><sub><a href="https://github.com/akilluminati47/RIPPS2">RIPPS2</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2/releases/latest/download/RIPPS2.elf">Descarcă</a> &nbsp;&middot;&nbsp; <b>BIBLE</b> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2-themes">Teme</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPCSX2">RIPPCSX2</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2-fonts">Fonturi</a> &nbsp;&middot;&nbsp; <a href="https://akilluminati47.github.io/RIPPS2/">Site</a> &nbsp;&middot;&nbsp; <a href="https://www.psx-place.com/threads/ripps2-a-ps2-front-end-in-one-elf-launch-disc-storage-memory-files.51316/">psx-place</a> &nbsp;&middot;&nbsp; <a href="https://discord.gg/Z7m9u5kby">Discord</a></sub></p>

<h1 align="center">BIBLE</h1>
<p align="center">
  <a href="https://akilluminati47.github.io/BIBLE/">Site</a> ·
  <a href="https://github.com/akilluminati47/RIPPS2">RIPPS2</a> ·
  <a href="https://github.com/akilluminati47/BIBLE/actions">Compilări</a> ·
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
  <sub>Ține apăsat L2 + R2 la pornire pentru pagina tastelor de lansare, TRIANGLE + CROSS pentru pagina modului video; o tastă setată la <code>$CREDITS</code> arată creditele.</sub>
</p>

BIBLE este boot loaderul pe care îl instalează RIPPS2: un fork al PS2BBL Extended de la saildot4k.

**Ce schimbă acest fork**

- Ecranul de pornire: logo-ul PS2 în mijlocul cerului RIPPS2, cu butoanele dedesubt și eventualul text deasupra. `BIBLE_GLYPHS` 0 niciunul, 1 butoanele de acțiune (implicit), 2 toate cele șaisprezece pe două rânduri de câte opt. `BIBLE_INFO` 1 arată informații despre consolă, ceasul și numărătoarea inversă (oprit implicit). Cerul urmează Color Theme-ul tău din RIPPS2: fără `BIBLE_COLOR`, BIBLE citește cerul pe care RIPPS2 îl salvează cu setările sale, din folderul pe care îl pornește intrarea AUTO, sau din folderul `RIPPS2` al unui card de memorie când intrarea AUTO este RIPPS2 pe un SD2PSX, USB sau HDD (`BIBLE_COLOR` din configurație are prioritate). Același aspect în fiecare mod video.
- `BIBLE_BACKGROUND`: `AUTO` (implicit: cerul când setările RIPPS2 sunt găsite sau `BIBLE_COLOR` este setat, altfel negru în modul propriu al consolei, un bootloader simplu), `SKY` sau `BLANK` (negru). Trecerea la un program e oricum neagră câteva secunde, așa că negrul pare o singură bucată cu ea.
- Sunetul de pornire: Boot Sound On (fast) din RIPPS2 poate ține `boot.adp` lângă configurația BIBLE (`mc?:/SYS-CONF/boot.adp`), iar RIPPS2 îl citește înainte de pornirea oricărei unități. BIBLE nu îl citește niciodată: doar îi spune lui RIPPS2 dosarul. **Fără sunet pornește cel mai repede.** Înțelegerea și partea RIPPS2: [docs/boot-sound-handoff.md](docs/boot-sound-handoff.md).
- Întâi RIPPS2: șablonul de configurare (`release/SYS-CONF/PS2BBL.INI`) și valorile implicite încorporate încearcă `mc?:/RIPPS2/RIPPS2.ELF` și `mmce?:/APPS/RIPPS2.ELF` înaintea OSDMenu și FMCB, iar șablonul listează cheile proprii BIBLE cu note. Paginile (mod video, credite, taste de lansare) apar peste logo-ul estompat, cu butoanele strânse, ca tastele de lansare să se citească liniștit.
- Moduri video: `VIDEO_MODE` acceptă și `576P`, `720P` și `1080I`, restul modurilor RIPPS2. `AUTO` (implicit)
  pornește în Video Mode din RIPPS2 când setările lui sunt lângă intrarea AUTO, altfel în modul consolei.
- `BIBLE_WIDESCREEN`: `AUTO` (implicit: Widescreen din RIPPS2, altfel setarea de ecran 16:9 a PS2), `ON` sau
  `OFF`. În 480i, 576i, 480p și 576p ecranul de pornire e desenat pentru un televizor care întinde imaginea la 16:9, fără
  turtire. 720p și 1080i sunt deja 16:9.
- Trecerea la RIPPS2: la lansare logoul și butoanele dispar, iar cerul rămâne până când consola încarcă următorul program, ceea ce înnegrește ecranul (circa 7 s în laborator, cu RIPPS2 pe un card de memorie). Apoi RIPPS2 apare în același mod video și cu aceleași culori. Ține apăsat TRIANGLE + CROSS la pornire pentru pagina modului video, care se deschide mereu
  în modul întrețesut al consolei (drumul înapoi din 720p sau 1080i pe un cablu compozit).
- Nou: pagina tastelor de lansare. Ține L2 + R2 la pornire și BIBLE face o pauză înainte să pornească ceva, arătând căile de lansare actuale ale fiecărei taste, oricare ar fi setările ecranului de pornire (util cu `LOGO_DISPLAY = 0`, unde nu se vede altceva).
- Combinațiile ținute de la pornire își deschid acum paginile (TRIANGLE + CROSS se pierdea cât timp controlerele încă
  porneau).
- `KEY_READ_WAIT_TIME = 0` este permis (minimul din upstream este 500 ms).
- Compilări PS2 pentru card de memorie / USB, MMCE, MX4SIO și HDD. Etapa 2 a eGSM este omisă.

**Cum îl folosește RIPPS2**

RIPPS2 poartă BIBLE în RIPPS2.elf, fiecare versiune semnată de akilluminati47, și îl instalează sau actualizează din Setări > General > Boot Loader > Manage, unde setează și cheile BIBLE: Background, Splash, Button Glyphs, Info Line, Power-on Wait, Video Mode și Widescreen. Versiunile semnate și un card BOOT SD2PSX gata făcut sunt pe [pagina de versiuni](https://github.com/akilluminati47/BIBLE/releases/latest). BIBLE rulează și ca ELF pornit de alt loader (FMCB, OSDMenu, loaderul unui SD2PSX).

<p align="center"><img src="assets/readme/ripps2-icon.png" alt="RIPPS2" width="48" height="48"><br><sub>BIBLE face parte din <a href="https://github.com/akilluminati47/RIPPS2">RIPPS2</a>.</sub></p>

---

<p align="center"><sub>Tot ce urmează este README-ul original al PS2BBL Extended, tradus și altfel neschimbat.</sub></p>

---


<br />
<p align="center">
  <a href="https://israpps.github.io/PlayStation2-Basic-BootLoader/">
    <img src="https://github.com/saildot4k/PlayStation2-Basic-BootLoader-Extended/blob/main/assets/ps2bbl_example.png" alt="Logo" width="50%" height="auto">
  </a>

  <p align="center">
    Un boot loader flexibil pentru PlayStation 2™ și PSX-DESR
    <br />
  </p>
</p>  


Acesta este un fork al PS2BBL de [El Isra](https://github.com/israpps/PlayStation2-Basic-BootLoader/)


<a id="documentation"></a>

## Documentație

Este găzduită pe [github pages](https://israpps.github.io/PlayStation2-Basic-BootLoader/), dar cu adăugirile de mai jos:

<a id="config-and-arguments"></a>

## Configurare și argumente

Editează fișierul de configurare după nevoie. Pentru editare se recomandă [R3Configurator](https://github.com/saildot4k/R3CONFIGURATOR). Căile sunt deja setate să se potrivească cu descărcările din [PS2 Homebrew Store](https://ps2homebrewstore.com). Așa că ar trebui să editezi doar alegerea Auto și, de preferat, să setezi argumentele pentru NHDDL după dispozitivul de pe care încarci ISO-urile.

<a id="config-path-search-order"></a>

### Ordinea de căutare a configurației

Căutarea configurației ține cont acum de familia de pornire, ca să nu încarce drivere inutile la start:

1. `CONFIG.INI` (CWD: directorul de lucru curent)
2. La încărcarea de pe un dispozitiv:
   - Pornire de pe MMCE: `mmce?:/PS2BBL/CONFIG.INI`
   - Pornire de pe MX4SIO: `mx4sio:/PS2BBL/CONFIG.INI`
   - Pornire de pe APA HDD: `hdd0:__sysconf:pfs:/PS2BBL/CONFIG.INI`
   - Pornire de pe BDM: `usb:/PS2BBL/CONFIG.INI` / `mass:/PS2BBL/CONFIG.INI` / `ata:/PS2BBL/CONFIG.INI`
3. Rezervă pe cardul de memorie:
   - Pe PS2: `mc?:/SYS-CONF/PS2BBL.INI`
   - Pe PSX-DESR: `mc?:/SYS-CONF/PSXBBL.INI`
4. Ultima rezervă pe PSX
   - `xfrom:/PS2BBL/CONFIG.INI`
5. Când e compilat cu `DISC_STOP_AT_BOOT=1
   - `cdrom0:/PS2BBL/CONFIG.INI`
   - Rezervă pe cardul de memorie ca la punctul 3 de mai sus.

<a id="device-path-prefixes"></a>

### Prefixele căilor dispozitivelor
PS2BBL acceptă aceste prefixe pentru căile de lansare/configurare:
- `mc0:/`, `mc1:/`, `mc?:/`
- `usb:/` (preferat) și `mass:/` (vechi)

<a id="build-specific"></a>

#### În funcție de compilare:  
- `mmce0:/`, `mmce1:/`, `mmce?:/` __compilări MMCE__
- `mx4sio:/` (preferat) și `massX:/` (vechi)  __compilări MX4SIO__
- `hdd0:partition:pfs:/<path to elf>` __compilări HDD__
- Căi `xfrom:/` __compilări PSX DESR__
- `ata:/` dispozitiv BDM pentru HDD exFAT
- `ilink:/` (rădăcini de stocare în masă BDM) __încă neimplementat__
- `DISC_STOP_AT_BOOT=1` profil de compilare care oprește mereu discul optic după încărcarea configurației

### LOGO_DISPLAY
Folosește `LOGO_DISPLAY = 3` pentru afișarea numelor tastelor. Numele sunt definite de `NAME_<BUTTON>`.
  - `0` Fără logo și informații despre consolă
  - `1` Informații despre consolă
  - `2` Logo PS2BBLE/PSXBBLE și informații despre consolă
  - `3` Grafică a tastelor cu `NAME_BUTTON = <TITLE>` din fișierul de configurare
    - Exemplu:
      ```
      NAME_SQUARE = POPSLOADER
      ```

<a id="custom-splash-logo-from-cwd"></a>

#### Logo de pornire propriu din CWD
Dacă în CWD (directorul de lucru curent) se găsește un fișier de logo propriu (LOGO.BIN), acesta înlocuiește logoul PS2BBLE/PSXBBLE integrat.

Convertește un PNG în fișierul brut așteptat:
  - PNG-ul trebuie să fie RGBA pe 8 biți indexat, 255 de culori pe canal și rezoluție 256x64.

  - Pachetul versiunii (scriptul este în rădăcina versiunii):
  ```bash
  python png_to_logo_rbga.py my_logo.png
  ```

  - Pune `LOGO.BIN` creat lângă PS2BBL Extended. Ar trebui să fie `mc?:/BOOT/` dacă folosești descărcări din [PS2 Homebrew Store](https://ps2store.com)

<a id="retrogem-visual-game-id"></a>

### ID-ul vizual al jocului de la Retrogem
- `APP_GAMEID = 1` activează ID-ul vizual al jocului pentru aplicații/homebrew, până la 11 caractere din numele fișierului sau de pe discul PS1/2
- `CDROM_DISABLE_GAMEID = 1` dezactivează ID-ul vizual al jocului pentru discurile lansate prin `cdrom`.

<a id="disc-spin-control"></a>

### Controlul rotirii discului
- Cheie/valoare globală: `DISC_STOP = 0/1`
- `DISC_STOP = 1` oprește discul optic după încărcarea configurației, când s-a găsit un fișier de configurare.
- `DISC_STOP = 0` (sau omis) păstrează comportamentul implicit.
- `-disc_stop` poate fi adăugat la fiecare intrare de lansare ca să oprească discul după ce ELF-ul țintă e găsit.

<a id="video-mode"></a>

### Mod video
- `VIDEO_MODE = AUTO, NTSC, PAL, 480P` Folosește modul implicit al PS2 sau impune unul dintre celelalte 3.

<a id="emergency-video-mode-selector"></a>

#### Selector de urgență al modului video
- Se deschide cu `TRIANGLE + CROSS` în timpul pornirii
- Selectorul impune `LOGO_DISPLAY = 3` cât timp e activ, ca să vezi logoul și tastele.
- Comenzi:
  - `LEFT/RIGHT` schimbă modurile: `AUTO`, `NTSC`, `PAL`, `480P`
  - `SELECT` salvează modul ales în fișierul de configurare activ
  - `START` iese din selector și continuă la afișarea tastelor

<a id="cdrom-launch-args"></a>

### Argumente de lansare pentru CDROM
Pentru `LK_*_E* = cdrom`, argumentele acceptate sunt:
- `-nologo`
- `-nogameid`
- `-ps1fast`
- `-ps1smooth`
- `-ps1vneg`
- `-gsm=<v[:c]>`

<a id="ps2logo-arguments-ps2-discs-only"></a>

#### Argumente PS2LOGO (doar discuri PS2)
- Folosește `cdrom` drept cale a intrării de lansare.
- Adaugă `-nologo` la argumentele intrării ca discurile PS2 să pornească direct (fără `rom0:PS2LOGO`).
- Fără `-nologo`, PS2BBL pornește discul prin PS2LOGO și îl modifică să folosească mereu regiunea discului și să ocolească verificarea sumei de control a logoului.
- DECKARD IE 75K și mai noi: XPARAM.IRX se aplică automat când e nevoie pentru lansările fără logo.

<a id="ps1-disc-arguments-per-launch"></a>

#### Argumente pentru discuri PS1 (pe lansare)
Se aplică fiecărei intrări de lansare `cdrom`, nu global.
- `-ps1fast` activează viteza rapidă a discului PS1.
- `-ps1smooth` activează netezirea texturilor.
- `-ps1vneg` rulează PS1DRV prin PS1VModeNegator. Util acolo unde modul consolei și cel al discului diferă (de exemplu unele cazuri MechaPwn/modchip).

<a id="app-arguments"></a>

### Argumente pentru aplicații
Folosește rânduri `ARG_<BUTTON>_E? =` ca să dai argumente unui ELF (vezi exemplele INI).
- Pune întâi argumentele elf-ului lansat, apoi adaugă argumentele interne PS2BBL dorite (vezi mai jos). [NHDDL](https://github.com/pcm720/nhddl) e un candidat excelent pentru argumente, pentru că îi accelerează pornirea.
- `-titleid=SLUS_123.45` înlocuiește ID-ul titlului aplicației (până la 11 caractere).
- `-appid` impune ID-ul vizual al jocului aplicației chiar și cu `APP_GAMEID = 0`.
- `-disc_stop` oprește discul după încărcarea ELF-ului țintă (util pe intrare fără compilări `DISC_STOP_AT_BOOT`).
- `-gsm=<v[:c]>` rulează ELF-ul țintă prin eGSM-ul integrat (ignorat pentru căile `rom?:`). Dacă e folosit, trebuie să fie ultimul argument.
- `-disc_stop` este ignorat pentru intrările de lansare `cdrom`.
- `-dev9=<mode>` setează politica DEV9/HDD înainte de lansarea ELF-ului țintă. Moduri acceptate:
  - `NICHDD` ține pornite atât DEV9 (adaptorul de rețea), cât și HDD-ul.
  - `NIC` ține pornite DEV9/rețeaua, demontează `pfs0:` și pune imediat `hdd0:`/`hdd1:` în repaus.
  - dacă e omis, PS2BBL nu impune nicio politică DEV9.
  - notă: pe compilările fără HDD această opțiune nu are efect.
- `-patinfo` activează tratarea PATINFO pentru intrările `:PATINFO`.
  - PS2BBL citește `SYSTEM.CNF` din zona de atribute a partiției (`PS2ICON3D`) și aplică `BOOT2/BOOT/path`, `arg*`, `skip_argv0` și `HDDUNITPOWER`.
  - dacă `BOOT2/BOOT/path=PATINFO`, PS2BBL încarcă ELF-ul integrat din zona de atribute a partiției și folosește predarea internă `-la=E...`.
  - dacă `IOPRP=PATINFO` (sau o cale proprie), PS2BBL îl transmite etapei 2 prin predarea internă `-la=I...`.
  - dacă `-patinfo` este prezent, primul argument rămas înlocuiește ținta `BOOT2/BOOT/path` din CNF.
  Asta e pentru compilările HDD.  
  Exemplu PATINFO:  
    ```
    NAME_R1 = My App via PATINFO
    LK_R1_E1 = hdd0:+OSDMENU:PATINFO
    ARG_R1_E1 = pfs:/APPS/MYAPP.ELF
    ARG_R1_E1 = -patinfo               # Tells PS2BBL to use first arg as patinfo boot path.
    ```

Exemplu de lansare a NHDDL în modul video 480p, cu căutare de ISO-uri pe mmce și pe un HDD exFAT fără nevoie de nhddl.yaml. Avantajul: nu se pierde timp cu încărcarea driverelor, găsirea și încărcarea nhddl.yaml. E cel mai rapid mod de a porni NHDDL și de a arăta lista de ISO-uri.
```
NAME_R1 = NHDDL
LK_R1_E1 = mmce?:/NEUTRINO/nhddl.elf
ARG_R1_E1 = -video=480p
ARG_R1_E1 = -mode=mmce
ARG_R1_E1 = -mode=ata
```

<a id="argument-precedence-and-order"></a>

#### Prioritatea și ordinea argumentelor
1. PS2BBL analizează și consumă doar argumentele de control ale loaderului de la finalul `ARG_*`: `-appid`, `-titleid=`, `-dev9=`, `-patinfo`, `-disc_stop`, `-gsm=`.
2. Analiza merge de jos în sus și se oprește la primul argument care nu e de control (comportament final în stilul OSDMenu).
4. Pentru căile de lansare `:PATINFO`, PS2BBL analizează `SYSTEM.CNF` din atributul partiției și adaugă intrările `arg*` din CNF după argumentele aplicației utilizatorului.
5. Dacă `-patinfo` e setat și calea de lansare conține `:PATINFO`, primul argument rămas al utilizatorului devine calea ELF-ului țintă (înlocuiește calea de pornire din CNF) și este scos din argv-ul aplicației. Dacă nu rămâne niciun argument, lansarea e anulată (ca în OSDMenu), iar `BOOT2/BOOT/path` din CNF nu este folosit.
6. Argumentele rămase își păstrează ordinea și sunt transmise aplicației lansate.


### eGSM (external Graphics Synthesize Mode)
Pentru discurile PS2, eGSM se citește automat din `OSDGSM.CNF` (nu e nevoie de nicio cale în INI). Vezi [aici](https://github.com/pcm720/OSDMenu/blob/main/patcher/README.md#osdgsmcnf) formatul fișierului de configurare.

- `-gsm=<v[:c]>` rulează ELF-ul țintă prin eGSM-ul integrat (ignorat pentru căile `rom?:`).
  - eGSM se aplică țintei lansate (ELF/disc), nu PS2BBL-ului însuși.
  Formatul eGSM (în stilul OSDMenu):
- `v` = mod video:
- gol = nu impune nimic (implicit)
- `fp1` = impune scanare progresivă (240p/288p)
- `fp2` = impune scanare progresivă (480p/576p)
- `1080ix1` = impune 1080i, lățime/înălțime x1
- `1080ix2` = impune 1080i, lățime/înălțime x2
- `1080ix3` = impune 1080i, lățime/înălțime x3
- `c` = mod de compatibilitate:
- gol = niciunul (implicit)
- `1` = inversarea câmpurilor tip 1
- `2` = inversarea câmpurilor tip 2
- `3` = inversarea câmpurilor tip 3

Exemple de ARG eGSM:
- `-gsm=fp2`
- `-gsm=fp2:1`
- `-gsm=1080ix2`

Exemplu de utilizare:
```
LK_TRIANGLE_E1 = mc0:/APP_WLE-ISR/WLE-ISR.ELF
ARG_TRIANGLE_E1 = -gsm=1080ix2
```

<a id="deprecatedremoved"></a>

## Învechit/Eliminat
- ~~`RUNKELF`~~ PS2BBLE lansează acum intern elf/kelf, fără ca utilizatorul să trebuiască să definească o acțiune de lansare kelf.


<a id="known-bugsissues"></a>

## Erori/probleme cunoscute

spune-mi tu ;)

<a id="credits--thanks"></a>

## Credite și mulțumiri

- De la saildot4k
  - @israpps pentru [PS2BBL](https://github.com/israpps/PlayStation2-Basic-BootLoader/)
  - @pcm720 pentru
    - gameID-ul Retrogem, PS1 Video Negator, eGSM și codul PS2LOGO din [OSDMenu](https://github.com/pcm720/OSDMenu)
    - opțiunile de mod video din [NHDDL](https://github.com/pcm720/nhddl)
  - @sp193 pentru [PS1 Video Negator](https://github.com/ps2homebrew/PS1VModeNeg)
  - @nathanneurotic pentru cele 10 căi ale PS2BBLE, idei și convingere
  - [@Berion](https://www.psx-place.com/members/berion.1431/) pentru logouri, fundal și grafica tastelor

- De la [El Isra](https://israpps.github.io/) (dezvoltatorul PS2BBL): 
  - @SP193 pentru bibliotecile de inițializare OSD, care stau la baza acestui proiect
  - @asmblur, pentru că m-a încurajat să fac acest monstru pe cel mai nou SDK
  - @uyjulian și @fjtrujy pentru că mă ajută mereu


<p align="center"><sub><a href="https://github.com/akilluminati47/RIPPS2">RIPPS2</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2/releases/latest/download/RIPPS2.elf">Descarcă</a> &nbsp;&middot;&nbsp; <b>BIBLE</b> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2-themes">Teme</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPCSX2">RIPPCSX2</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2-fonts">Fonturi</a> &nbsp;&middot;&nbsp; <a href="https://akilluminati47.github.io/RIPPS2/">Site</a> &nbsp;&middot;&nbsp; <a href="https://www.psx-place.com/threads/ripps2-a-ps2-front-end-in-one-elf-launch-disc-storage-memory-files.51316/">psx-place</a> &nbsp;&middot;&nbsp; <a href="https://discord.gg/Z7m9u5kby">Discord</a></sub></p>

