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
  <b>Hrvatski</b> |
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

<p align="center"><sub>Prijevod engleskog README-a; ako se razlikuju, vrijedi engleski. <a href="README.md">English</a></sub></p>

<p align="center"><sub><a href="https://github.com/akilluminati47/RIPPS2">RIPPS2</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2/releases/latest/download/RIPPS2.elf">Preuzmi</a> &nbsp;&middot;&nbsp; <b>BIBLE</b> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2-themes">Teme</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPCSX2">RIPPCSX2</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2-fonts">Fontovi</a> &nbsp;&middot;&nbsp; <a href="https://akilluminati47.github.io/RIPPS2/">Web</a> &nbsp;&middot;&nbsp; <a href="https://www.psx-place.com/threads/ripps2-a-ps2-front-end-in-one-elf-launch-disc-storage-memory-files.51316/">psx-place</a> &nbsp;&middot;&nbsp; <a href="https://discord.gg/Z7m9u5kby">Discord</a></sub></p>

<h1 align="center">BIBLE</h1>
<p align="center">
  <a href="https://github.com/akilluminati47/RIPPS2">RIPPS2</a> ·
  <a href="https://github.com/akilluminati47/BIBLE/actions">Izgradnje</a> ·
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
  <sub>Pri pokretanju držite L2 + R2 za stranicu tipki za pokretanje, TRIANGLE + CROSS za stranicu video načina; tipka postavljena na <code>$CREDITS</code> prikazuje zasluge.</sub>
</p>

BIBLE je boot loader koji postavlja RIPPS2: fork PS2BBL Extended od saildot4k.

**Što ovaj fork mijenja**

- Uvodni zaslon: PS2 logo u sredini neba RIPPS2-a, s tipkama ispod i eventualnim tekstom iznad. `BIBLE_GLYPHS` 0 ništa, 1 tipke za radnje (zadano), 2 svih šesnaest u dva reda po osam. `BIBLE_INFO` 1 prikazuje podatke o konzoli, sat i odbrojavanje (zadano isključeno). Nebo prati tvoj RIPPS2 Color Theme: bez `BIBLE_COLOR` BIBLE čita nebo koje RIPPS2 sprema uz svoje postavke, iz mape koju pokreće njegov unos AUTO, ili iz mape `RIPPS2` na memorijskoj kartici kad je unos AUTO RIPPS2 na SD2PSX-u, USB-u ili tvrdom disku (`BIBLE_COLOR` u konfiguraciji ima prednost). Isti izgled u svakom video načinu.
- `BIBLE_BACKGROUND`: `AUTO` (zadano: nebo kad se nađu postavke RIPPS2-a ili je postavljen `BIBLE_COLOR`, inače crna u vlastitom načinu konzole, običan bootloader), `SKY` ili `BLANK` (crna). Prijelaz u program ionako je nekoliko sekundi crn, pa crna s njim djeluje kao jedna cjelina.
- Zvuk pokretanja, pripremljen: Boot Sound On (fast) u RIPPS2-u može držati `boot.adp` pokraj BIBLE-ove konfiguracije (`mc?:/SYS-CONF/boot.adp`). Čita se prije pokretanja bilo kojeg pogona. BIBLE ga može predati RIPPS2-u i u RAM-u, ali to je zasad prošlo samo u laboratoriju: na pravom SD2PSX-u RIPPS2 je sam pročitao kopiju s kartice. **Bez zvuka je najbrže pokretanje.** Dogovor i strana RIPPS2-a: [docs/boot-sound-handoff.md](docs/boot-sound-handoff.md).
- RIPPS2 prvi: predložak konfiguracije (`release/SYS-CONF/PS2BBL.INI`) i ugrađene zadane vrijednosti pokušavaju `mc?:/RIPPS2/RIPPS2.ELF` i `mmce?:/APPS/RIPPS2.ELF` prije OSDMenua i FMCB-a, a predložak navodi BIBLE-ove vlastite ključeve s napomenama. Stranice (video način, zasluge, tipke za pokretanje) pojavljuju se preko zatamnjenog loga s pospremljenim tipkama, da se tipke za pokretanje mirno čitaju.
- Video načini: `VIDEO_MODE` prima i `576P`, `720P` i `1080I`, ostatak načina RIPPS2. `AUTO` (zadano)
  pokreće se u Video Mode od RIPPS2 kad su njegove postavke pokraj unosa AUTO, inače u načinu konzole.
- `BIBLE_WIDESCREEN`: `AUTO` (zadano: Widescreen od RIPPS2, inače postavka zaslona 16:9 na PS2), `ON` ili
  `OFF`. U 480i, 576i, 480p i 576p početni zaslon crta se za televizor koji rasteže sliku na 16:9, bez
  spljoštavanja. 720p i 1080i već su 16:9.
- Prijelaz u RIPPS2: pri pokretanju logo i tipke nestaju, a nebo ostaje dok konzola ne učita sljedeći program, što zacrni zaslon (oko 7 s u laboratoriju s RIPPS2-om na memorijskoj kartici). Zatim se RIPPS2 pojavljuje u istom video načinu i istim bojama. Pri pokretanju držite TRIANGLE + CROSS za stranicu video načina, koja se uvijek otvara
  u vlastitom isprepletenom načinu konzole (put natrag iz 720p ili 1080i na kompozitnom kabelu).
- Novo: stranica tipki za pokretanje. Drži L2 + R2 pri uključenju i BIBLE zastane prije nego išta pokrene, pokazujući trenutne putanje svake tipke, bez obzira na postavke uvodnog zaslona (korisno uz `LOGO_DISPLAY = 0`, gdje se ništa drugo ne prikazuje).
- Kombinacije držane od uključivanja sada otvaraju svoje stranice (TRIANGLE + CROSS se gubio dok su se kontroleri još
  pokretali).
- `KEY_READ_WAIT_TIME = 0` je dopušten (minimum u upstreamu je 500 ms).
- Izgradnje za PS2 za memorijsku karticu / USB, MMCE, MX4SIO i HDD. Faza 2 eGSM-a je izostavljena.

**Kako ga RIPPS2 koristi**

RIPPS2 nosi BIBLE unutar RIPPS2.elf, svaku verziju potpisao akilluminati47, i instalira ga ili ažurira u Postavke > Općenito > Boot Loader > Manage, gdje postavlja i BIBLE-ove ključeve: Background, Splash, Button Glyphs, Info Line, Power-on Wait, Video Mode i Widescreen. Potpisane verzije i gotova SD2PSX BOOT kartica su na [stranici izdanja](https://github.com/akilluminati47/BIBLE/releases/latest). BIBLE radi i kao ELF koji pokreće drugi loader (FMCB, OSDMenu, loader SD2PSX-a).

<p align="center"><img src="assets/readme/ripps2-icon.png" alt="RIPPS2" width="48" height="48"><br><sub>BIBLE je dio <a href="https://github.com/akilluminati47/RIPPS2">RIPPS2</a>.</sub></p>

---

<p align="center"><sub>Sve ispod je izvorni README od PS2BBL Extended, preveden i inače nepromijenjen.</sub></p>

---


<br />
<p align="center">
  <a href="https://israpps.github.io/PlayStation2-Basic-BootLoader/">
    <img src="https://github.com/saildot4k/PlayStation2-Basic-BootLoader-Extended/blob/main/assets/ps2bbl_example.png" alt="Logo" width="50%" height="auto">
  </a>

  <p align="center">
    Fleksibilan boot loader za PlayStation 2™ i PSX-DESR
    <br />
  </p>
</p>  


Ovo je fork PS2BBL-a autora [El Isra](https://github.com/israpps/PlayStation2-Basic-BootLoader/)


<a id="documentation"></a>

## Dokumentacija

Nalazi se na [github pages](https://israpps.github.io/PlayStation2-Basic-BootLoader/), ali s dodacima ispod:

<a id="config-and-arguments"></a>

## Konfiguracija i argumenti

Uredite konfiguracijsku datoteku po potrebi. Za uređivanje se preporučuje [R3Configurator](https://github.com/saildot4k/R3CONFIGURATOR). Putanje su već postavljene da odgovaraju preuzimanjima iz [PS2 Homebrew Store](https://ps2homebrewstore.com). Trebali biste urediti samo svoj izbor Auto i najbolje postaviti argumente za NHDDL prema uređaju s kojeg učitavate ISO datoteke.

<a id="config-path-search-order"></a>

### Redoslijed traženja konfiguracije

Traženje konfiguracije sada uzima u obzir obitelj pokretanja, kako se pri pokretanju ne bi učitavali nepotrebni upravljački programi:

1. `CONFIG.INI` (CWD: trenutna radna mapa)
2. Pri učitavanju s uređaja:
   - Pokretanje s MMCE: `mmce?:/PS2BBL/CONFIG.INI`
   - Pokretanje s MX4SIO: `mx4sio:/PS2BBL/CONFIG.INI`
   - Pokretanje s APA HDD: `hdd0:__sysconf:pfs:/PS2BBL/CONFIG.INI`
   - Pokretanje s BDM: `usb:/PS2BBL/CONFIG.INI` / `mass:/PS2BBL/CONFIG.INI` / `ata:/PS2BBL/CONFIG.INI`
3. Rezerva na memorijskoj kartici:
   - Na PS2: `mc?:/SYS-CONF/PS2BBL.INI`
   - Na PSX-DESR: `mc?:/SYS-CONF/PSXBBL.INI`
4. Posljednja rezerva na PSX-u
   - `xfrom:/PS2BBL/CONFIG.INI`
5. Kad je izgrađeno s `DISC_STOP_AT_BOOT=1
   - `cdrom0:/PS2BBL/CONFIG.INI`
   - Rezerva na memorijskoj kartici kao u točki 3 iznad.

<a id="device-path-prefixes"></a>

### Prefiksi putanja uređaja
PS2BBL podržava ove prefikse putanja za pokretanje/konfiguraciju:
- `mc0:/`, `mc1:/`, `mc?:/`
- `usb:/` (preporučeno) i `mass:/` (staro)

<a id="build-specific"></a>

#### Ovisno o izgradnji:  
- `mmce0:/`, `mmce1:/`, `mmce?:/` __izgradnje MMCE__
- `mx4sio:/` (preporučeno) i `massX:/` (staro)  __izgradnje MX4SIO__
- `hdd0:partition:pfs:/<path to elf>` __izgradnje HDD__
- Putanje `xfrom:/` __izgradnje PSX DESR__
- `ata:/` BDM uređaj za exFAT HDD
- `ilink:/` (korijeni BDM masovne pohrane) __još nije implementirano__
- `DISC_STOP_AT_BOOT=1` profil izgradnje koji uvijek zaustavlja optički disk nakon učitavanja konfiguracije

### LOGO_DISPLAY
Koristite `LOGO_DISPLAY = 3` za prikaz naziva tipki. Nazivi se određuju s `NAME_<BUTTON>`.
  - `0` Bez loga i podataka o konzoli
  - `1` Podaci o konzoli
  - `2` Logo PS2BBLE/PSXBBLE i podaci o konzoli
  - `3` Grafika tipki s `NAME_BUTTON = <TITLE>` iz konfiguracijske datoteke
    - Primjer:
      ```
      NAME_SQUARE = POPSLOADER
      ```

<a id="custom-splash-logo-from-cwd"></a>

#### Vlastiti početni logo iz CWD-a
Ako se u CWD-u (trenutnoj radnoj mapi) nađe vlastita datoteka loga (LOGO.BIN), ona zamjenjuje ugrađeni logo PS2BBLE/PSXBBLE.

Pretvorite PNG u očekivanu sirovu datoteku:
  - PNG treba biti RGBA, 8-bitni indeksirani, 255 boja po kanalu i u razlučivosti 256x64.

  - Paket izdanja (skripta je u korijenu izdanja):
  ```bash
  python png_to_logo_rbga.py my_logo.png
  ```

  - Stvoreni `LOGO.BIN` stavite pokraj PS2BBL Extended. To bi trebalo biti `mc?:/BOOT/` ako koristite preuzimanja iz [PS2 Homebrew Store](https://ps2store.com)

<a id="retrogem-visual-game-id"></a>

### Vizualni ID igre od Retrogema
- `APP_GAMEID = 1` uključuje vizualni ID igre za aplikacije/homebrew, do 11 znakova iz naziva datoteke ili s diska PS1/2
- `CDROM_DISABLE_GAMEID = 1` isključuje vizualni ID igre za diskove pokrenute preko `cdrom`.

<a id="disc-spin-control"></a>

### Upravljanje vrtnjom diska
- Globalni ključ/vrijednost: `DISC_STOP = 0/1`
- `DISC_STOP = 1` zaustavlja optički disk nakon učitavanja konfiguracije kad je pronađena konfiguracijska datoteka.
- `DISC_STOP = 0` (ili izostavljeno) zadržava zadano ponašanje.
- `-disc_stop` se može dodati svakom unosu za pokretanje da se disk zaustavi kad se pronađe ciljni ELF.

<a id="video-mode"></a>

### Video način
- `VIDEO_MODE = AUTO, NTSC, PAL, 480P` Koristi zadani način PS2 ili prisiljava jedan od ostala 3.

<a id="emergency-video-mode-selector"></a>

#### Hitni odabir video načina
- Otvara se s `TRIANGLE + CROSS` tijekom pokretanja
- Odabir prisiljava `LOGO_DISPLAY = 3` dok je aktivan, da vidite logo i tipke.
- Upravljanje:
  - `LEFT/RIGHT` mijenjaju načine: `AUTO`, `NTSC`, `PAL`, `480P`
  - `SELECT` sprema odabrani način u aktivnu konfiguracijsku datoteku
  - `START` izlazi iz odabira i nastavlja na prikaz tipki

<a id="cdrom-launch-args"></a>

### Argumenti pokretanja za CDROM
Za `LK_*_E* = cdrom` podržani su ovi argumenti:
- `-nologo`
- `-nogameid`
- `-ps1fast`
- `-ps1smooth`
- `-ps1vneg`
- `-gsm=<v[:c]>`

<a id="ps2logo-arguments-ps2-discs-only"></a>

#### Argumenti za PS2LOGO (samo PS2 diskovi)
- Koristite `cdrom` kao putanju unosa.
- Dodajte `-nologo` argumentima unosa da se PS2 diskovi pokreću izravno (bez `rom0:PS2LOGO`).
- Bez `-nologo`, PS2BBL pokreće disk preko PS2LOGO i krpa ga da uvijek koristi regiju diska i preskoči provjeru kontrolnog zbroja loga.
- DECKARD IE 75K i noviji: XPARAM.IRX primjenjuje se automatski kad je potrebno za pokretanja bez loga.

<a id="ps1-disc-arguments-per-launch"></a>

#### Argumenti za PS1 diskove (po pokretanju)
Vrijede za svaki unos `cdrom`, a ne globalno.
- `-ps1fast` uključuje brzu brzinu diska PS1.
- `-ps1smooth` uključuje zaglađivanje tekstura.
- `-ps1vneg` pokreće PS1DRV preko PS1VModeNegator. Korisno ondje gdje se način konzole i način diska razlikuju (na primjer neki slučajevi MechaPwn/modčipova).

<a id="app-arguments"></a>

### Argumenti aplikacija
Retcima `ARG_<BUTTON>_E? =` predajete argumente ELF-u (pogledajte INI primjere).
- Najprije upišite argumente pokrenutog elf-a, a zatim dodajte željene interne argumente PS2BBL-a (vidi ispod). [NHDDL](https://github.com/pcm720/nhddl) je odličan kandidat za argumente jer ubrzavaju njegovo pokretanje.
- `-titleid=SLUS_123.45` zamjenjuje ID naslova aplikacije (do 11 znakova).
- `-appid` prisiljava vizualni ID igre aplikacije čak i uz `APP_GAMEID = 0`.
- `-disc_stop` zaustavlja disk nakon učitavanja ciljnog ELF-a (korisno po unosu bez izgradnji `DISC_STOP_AT_BOOT`).
- `-gsm=<v[:c]>` pokreće ciljni ELF preko ugrađenog eGSM-a (zanemaruje se za putanje `rom?:`). Ako se koristi, mora biti zadnji argument.
- `-disc_stop` se zanemaruje za unose `cdrom`.
- `-dev9=<mode>` postavlja pravilo DEV9/HDD prije pokretanja ciljnog ELF-a. Podržani načini:
  - `NICHDD` drži uključenima i DEV9 (mrežni adapter) i HDD.
  - `NIC` drži DEV9/mrežu uključenima, odspaja `pfs0:` i odmah uspavljuje `hdd0:`/`hdd1:`.
  - ako je izostavljeno, PS2BBL ne prisiljava nikakvo pravilo DEV9.
  - napomena: u izgradnjama bez HDD-a ova opcija nema učinka.
- `-patinfo` uključuje obradu PATINFO za unose `:PATINFO`.
  - PS2BBL čita `SYSTEM.CNF` iz područja atributa particije (`PS2ICON3D`) i primjenjuje `BOOT2/BOOT/path`, `arg*`, `skip_argv0` i `HDDUNITPOWER`.
  - ako je `BOOT2/BOOT/path=PATINFO`, PS2BBL učitava ugrađeni ELF iz područja atributa particije i koristi interno predavanje `-la=E...`.
  - ako je `IOPRP=PATINFO` (ili vlastita putanja), PS2BBL ga predaje fazi 2 internim predavanjem `-la=I...`.
  - ako je prisutan `-patinfo`, prvi preostali argument zamjenjuje cilj `BOOT2/BOOT/path` iz CNF-a.
  Ovo je za izgradnje HDD.  
  Primjer PATINFO:  
    ```
    NAME_R1 = My App via PATINFO
    LK_R1_E1 = hdd0:+OSDMENU:PATINFO
    ARG_R1_E1 = pfs:/APPS/MYAPP.ELF
    ARG_R1_E1 = -patinfo               # Tells PS2BBL to use first arg as patinfo boot path.
    ```

Primjer pokretanja NHDDL-a u video načinu 480p uz traženje ISO datoteka na mmce i exFAT HDD-u bez potrebe za nhddl.yaml. Prednost je što se ne gubi vrijeme na učitavanje upravljačkih programa te traženje i učitavanje nhddl.yaml. To je najbrži način da pokrenete NHDDL i prikažete popis ISO datoteka.
```
NAME_R1 = NHDDL
LK_R1_E1 = mmce?:/NEUTRINO/nhddl.elf
ARG_R1_E1 = -video=480p
ARG_R1_E1 = -mode=mmce
ARG_R1_E1 = -mode=ata
```

<a id="argument-precedence-and-order"></a>

#### Prednost i redoslijed argumenata
1. PS2BBL obrađuje i troši samo završne kontrolne argumente loadera iz `ARG_*`: `-appid`, `-titleid=`, `-dev9=`, `-patinfo`, `-disc_stop`, `-gsm=`.
2. Obrada ide odozdo prema gore i staje na prvom argumentu koji nije kontrolni (završno ponašanje kao u OSDMenu).
4. Za putanje `:PATINFO`, PS2BBL obrađuje `SYSTEM.CNF` iz atributa particije i dodaje unose `arg*` iz CNF-a nakon korisnikovih argumenata aplikacije.
5. Ako je postavljen `-patinfo` i putanja sadrži `:PATINFO`, korisnikov prvi preostali argument aplikacije postaje putanja ciljnog ELF-a (zamjenjuje putanju pokretanja iz CNF-a) i uklanja se iz argv aplikacije. Ako ne ostane nijedan argument, pokretanje se prekida (kao u OSDMenu), a `BOOT2/BOOT/path` iz CNF-a se ne koristi.
6. Preostali argumenti zadržavaju redoslijed i predaju se pokrenutoj aplikaciji.


### eGSM (external Graphics Synthesize Mode)
Za PS2 diskove eGSM se automatski čita iz `OSDGSM.CNF` (u INI-ju nije potrebna putanja). Format konfiguracijske datoteke pogledajte [ovdje](https://github.com/pcm720/OSDMenu/blob/main/patcher/README.md#osdgsmcnf).

- `-gsm=<v[:c]>` pokreće ciljni ELF preko ugrađenog eGSM-a (zanemaruje se za putanje `rom?:`).
  - eGSM se primjenjuje na pokrenuti cilj (ELF/disk), a ne na sam PS2BBL.
  Format eGSM-a (kao u OSDMenu):
- `v` = video način:
- prazno = ne prisiljavati (zadano)
- `fp1` = prisili progresivno skeniranje (240p/288p)
- `fp2` = prisili progresivno skeniranje (480p/576p)
- `1080ix1` = prisili 1080i, širina/visina x1
- `1080ix2` = prisili 1080i, širina/visina x2
- `1080ix3` = prisili 1080i, širina/visina x3
- `c` = način kompatibilnosti:
- prazno = nijedan (zadano)
- `1` = zamjena poluslika tip 1
- `2` = zamjena poluslika tip 2
- `3` = zamjena poluslika tip 3

Primjeri ARG-ova za eGSM:
- `-gsm=fp2`
- `-gsm=fp2:1`
- `-gsm=1080ix2`

Primjer upotrebe:
```
LK_TRIANGLE_E1 = mc0:/APP_WLE-ISR/WLE-ISR.ELF
ARG_TRIANGLE_E1 = -gsm=1080ix2
```

<a id="deprecatedremoved"></a>

## Zastarjelo/Uklonjeno
- ~~`RUNKELF`~~ PS2BBLE sada interno pokreće elf/kelf, bez potrebe da korisnik definira radnju pokretanja kelf.


<a id="known-bugsissues"></a>

## Poznate greške/problemi

vi meni recite ;)

<a id="credits--thanks"></a>

## Zasluge i zahvale

- Od saildot4k
  - @israpps za [PS2BBL](https://github.com/israpps/PlayStation2-Basic-BootLoader/)
  - @pcm720 za
    - Retrogem gameID, PS1 Video Negator, eGSM i kod PS2LOGO iz [OSDMenu](https://github.com/pcm720/OSDMenu)
    - opcije video načina iz [NHDDL](https://github.com/pcm720/nhddl)
  - @sp193 za [PS1 Video Negator](https://github.com/ps2homebrew/PS1VModeNeg)
  - @nathanneurotic za 10 putanja PS2BBLE-a, ideje i nagovaranje
  - [@Berion](https://www.psx-place.com/members/berion.1431/) za logotipe, pozadinu i grafiku tipki

- Od [El Isra](https://israpps.github.io/) (razvijatelj PS2BBL-a): 
  - @SP193 za biblioteke za inicijalizaciju OSD-a, koje su temelj ovog projekta
  - @asmblur, što me potaknuo da napravim ovo čudovište na najnovijem SDK-u
  - @uyjulian i @fjtrujy što mi uvijek pomažu


<p align="center"><sub><a href="https://github.com/akilluminati47/RIPPS2">RIPPS2</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2/releases/latest/download/RIPPS2.elf">Preuzmi</a> &nbsp;&middot;&nbsp; <b>BIBLE</b> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2-themes">Teme</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPCSX2">RIPPCSX2</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2-fonts">Fontovi</a> &nbsp;&middot;&nbsp; <a href="https://akilluminati47.github.io/RIPPS2/">Web</a> &nbsp;&middot;&nbsp; <a href="https://www.psx-place.com/threads/ripps2-a-ps2-front-end-in-one-elf-launch-disc-storage-memory-files.51316/">psx-place</a> &nbsp;&middot;&nbsp; <a href="https://discord.gg/Z7m9u5kby">Discord</a></sub></p>

