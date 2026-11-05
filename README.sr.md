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
  <b>Srpski</b> |
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

<p align="center"><sub>Prevod engleskog README-a; ako se razlikuju, važi engleski. <a href="README.md">English</a></sub></p>

<p align="center"><sub><a href="https://github.com/akilluminati47/RIPPS2">RIPPS2</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2/releases/latest/download/RIPPS2.elf">Preuzmi</a> &nbsp;&middot;&nbsp; <b>BIBLE</b> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2-themes">Teme</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPCSX2">RIPPCSX2</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2-fonts">Fontovi</a> &nbsp;&middot;&nbsp; <a href="https://akilluminati47.github.io/RIPPS2/">Sajt</a> &nbsp;&middot;&nbsp; <a href="https://www.psx-place.com/threads/ripps2-a-ps2-front-end-in-one-elf-launch-disc-storage-memory-files.51316/">psx-place</a> &nbsp;&middot;&nbsp; <a href="https://discord.gg/Z7m9u5kby">Discord</a></sub></p>

<h1 align="center">BIBLE</h1>
<p align="center">
  <a href="https://akilluminati47.github.io/BIBLE/">Sajt</a> ·
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
  <sub>Pri pokretanju držite L2 + R2 za stranicu tastera za pokretanje, TRIANGLE + CROSS za stranicu video režima; taster podešen na <code>$CREDITS</code> prikazuje zasluge.</sub>
</p>

BIBLE je boot loader koji podešava RIPPS2: fork PS2BBL Extended od saildot4k.

**Šta ovaj fork menja**

- Uvodni ekran: PS2 logo u sredini neba RIPPS2-a, sa tasterima ispod i eventualnim tekstom iznad. `BIBLE_GLYPHS` 0 ništa, 1 tasteri za radnje (podrazumevano), 2 svih šesnaest u dva reda po osam. `BIBLE_INFO` 1 prikazuje podatke o konzoli, sat i odbrojavanje (podrazumevano isključeno). Nebo prati tvoj RIPPS2 Color Theme: bez `BIBLE_COLOR` BIBLE čita nebo koje RIPPS2 čuva uz svoja podešavanja, iz fascikle koju pokreće njegov unos AUTO, ili iz fascikle `RIPPS2` na memorijskoj kartici kad je unos AUTO RIPPS2 na SD2PSX-u, USB-u ili hard disku (`BIBLE_COLOR` u konfiguraciji ima prednost). Isti izgled u svakom video režimu.
- `BIBLE_BACKGROUND`: `AUTO` (podrazumevano: nebo kad se nađu podešavanja RIPPS2-a ili je postavljen `BIBLE_COLOR`, inače crna u sopstvenom režimu konzole, običan bootloader), `SKY` ili `BLANK` (crna). Prelaz u program ionako je nekoliko sekundi crn, pa crna sa njim deluje kao jedna celina.
- Zvuk pokretanja: Boot Sound On (fast) u RIPPS2-u može da drži `boot.adp` pored BIBLE-ove konfiguracije (`mc?:/SYS-CONF/boot.adp`), a RIPPS2 ga čita pre pokretanja bilo kog uređaja. BIBLE ga nikad ne čita: samo javlja RIPPS2-u fasciklu. **Bez zvuka je najbrže pokretanje.** Dogovor i strana RIPPS2-a: [docs/boot-sound-handoff.md](docs/boot-sound-handoff.md).
- RIPPS2 prvi: šablon konfiguracije (`release/SYS-CONF/PS2BBL.INI`) i ugrađene podrazumevane vrednosti pokušavaju `mc?:/RIPPS2/RIPPS2.ELF` i `mmce?:/APPS/RIPPS2.ELF` pre OSDMenu-a i FMCB-a, a šablon navodi BIBLE-ove sopstvene ključeve sa napomenama. Stranice (video režim, zasluge, tasteri za pokretanje) pojavljuju se preko zatamnjenog loga sa sklonjenim tasterima, da se tasteri za pokretanje mirno čitaju.
- Video režimi: `VIDEO_MODE` prima i `576P`, `720P` i `1080I`, ostatak režima RIPPS2. `AUTO` (podrazumevano)
  pokreće se u Video Mode od RIPPS2 kada su njegova podešavanja pored unosa AUTO, inače u režimu konzole.
- `BIBLE_WIDESCREEN`: `AUTO` (podrazumevano: Widescreen od RIPPS2, inače podešavanje ekrana 16:9 na PS2), `ON` ili
  `OFF`. U 480i, 576i, 480p i 576p početni ekran se crta za televizor koji razvlači sliku na 16:9, bez
  spljoštavanja. 720p i 1080i su već 16:9.
- Prelaz u RIPPS2: pri pokretanju logo i tasteri nestaju, a nebo ostaje dok konzola ne učita sledeći program, što zatamni ekran (oko 7 s u laboratoriji sa RIPPS2-om na memorijskoj kartici). Zatim se RIPPS2 pojavljuje u istom video režimu i istim bojama. Pri pokretanju držite TRIANGLE + CROSS za stranicu video režima, koja se uvek otvara
  u sopstvenom proplitanom režimu konzole (put nazad iz 720p ili 1080i na kompozitnom kablu).
- Novo: stranica tastera za pokretanje. Drži L2 + R2 pri uključenju i BIBLE zastane pre nego što išta pokrene, pokazujući trenutne putanje svakog tastera, bez obzira na podešavanja uvodnog ekrana (korisno uz `LOGO_DISPLAY = 0`, gde se ništa drugo ne prikazuje).
- Kombinacije držane od uključivanja sada otvaraju svoje stranice (TRIANGLE + CROSS se gubio dok su se kontroleri još
  pokretali).
- `KEY_READ_WAIT_TIME = 0` je dozvoljen (minimum u upstreamu je 500 ms).
- Izgradnje za PS2 za memorijsku karticu / USB, MMCE, MX4SIO i HDD. Faza 2 eGSM-a je izostavljena.

**Kako ga RIPPS2 koristi**

RIPPS2 nosi BIBLE unutar RIPPS2.elf, svaku verziju potpisao akilluminati47, i instalira ga ili ažurira u Podešavanja > Opšte > Boot Loader > Manage, gde postavlja i BIBLE-ove ključeve: Background, Splash, Button Glyphs, Info Line, Power-on Wait, Video Mode i Widescreen. Potpisane verzije i gotova SD2PSX BOOT kartica su na [stranici izdanja](https://github.com/akilluminati47/BIBLE/releases/latest). BIBLE radi i kao ELF koji pokreće drugi loader (FMCB, OSDMenu, loader SD2PSX-a).

<p align="center"><img src="assets/readme/ripps2-icon.png" alt="RIPPS2" width="48" height="48"><br><sub>BIBLE je deo <a href="https://github.com/akilluminati47/RIPPS2">RIPPS2</a>.</sub></p>

---

<p align="center"><sub>Sve ispod je izvorni README od PS2BBL Extended, preveden i inače nepromenjen.</sub></p>

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

Nalazi se na [github pages](https://israpps.github.io/PlayStation2-Basic-BootLoader/), ali sa dodacima ispod:

<a id="config-and-arguments"></a>

## Konfiguracija i argumenti

Uredite konfiguracionu datoteku po potrebi. Za uređivanje se preporučuje [R3Configurator](https://github.com/saildot4k/R3CONFIGURATOR). Putanje su već podešene da odgovaraju preuzimanjima iz [PS2 Homebrew Store](https://ps2homebrewstore.com). Trebalo bi da uredite samo svoj izbor Auto i najbolje podesite argumente za NHDDL prema uređaju sa kog učitavate ISO datoteke.

<a id="config-path-search-order"></a>

### Redosled traženja konfiguracije

Traženje konfiguracije sada uzima u obzir porodicu pokretanja, da se pri pokretanju ne bi učitavali nepotrebni drajveri:

1. `CONFIG.INI` (CWD: trenutna radna fascikla)
2. Pri učitavanju sa uređaja:
   - Pokretanje sa MMCE: `mmce?:/PS2BBL/CONFIG.INI`
   - Pokretanje sa MX4SIO: `mx4sio:/PS2BBL/CONFIG.INI`
   - Pokretanje sa APA HDD: `hdd0:__sysconf:pfs:/PS2BBL/CONFIG.INI`
   - Pokretanje sa BDM: `usb:/PS2BBL/CONFIG.INI` / `mass:/PS2BBL/CONFIG.INI` / `ata:/PS2BBL/CONFIG.INI`
3. Rezerva na memorijskoj kartici:
   - Na PS2: `mc?:/SYS-CONF/PS2BBL.INI`
   - Na PSX-DESR: `mc?:/SYS-CONF/PSXBBL.INI`
4. Poslednja rezerva na PSX-u
   - `xfrom:/PS2BBL/CONFIG.INI`
5. Kada je izgrađeno sa `DISC_STOP_AT_BOOT=1
   - `cdrom0:/PS2BBL/CONFIG.INI`
   - Rezerva na memorijskoj kartici kao u tački 3 iznad.

<a id="device-path-prefixes"></a>

### Prefiksi putanja uređaja
PS2BBL podržava ove prefikse putanja za pokretanje/konfiguraciju:
- `mc0:/`, `mc1:/`, `mc?:/`
- `usb:/` (preporučeno) i `mass:/` (staro)

<a id="build-specific"></a>

#### Zavisno od izgradnje:  
- `mmce0:/`, `mmce1:/`, `mmce?:/` __izgradnje MMCE__
- `mx4sio:/` (preporučeno) i `massX:/` (staro)  __izgradnje MX4SIO__
- `hdd0:partition:pfs:/<path to elf>` __izgradnje HDD__
- Putanje `xfrom:/` __izgradnje PSX DESR__
- `ata:/` BDM uređaj za exFAT HDD
- `ilink:/` (koreni BDM masovnog skladišta) __još nije implementirano__
- `DISC_STOP_AT_BOOT=1` profil izgradnje koji uvek zaustavlja optički disk posle učitavanja konfiguracije

### LOGO_DISPLAY
Koristite `LOGO_DISPLAY = 3` za prikaz naziva tastera. Nazivi se određuju sa `NAME_<BUTTON>`.
  - `0` Bez loga i podataka o konzoli
  - `1` Podaci o konzoli
  - `2` Logo PS2BBLE/PSXBBLE i podaci o konzoli
  - `3` Grafika tastera sa `NAME_BUTTON = <TITLE>` iz konfiguracione datoteke
    - Primer:
      ```
      NAME_SQUARE = POPSLOADER
      ```

<a id="custom-splash-logo-from-cwd"></a>

#### Sopstveni početni logo iz CWD-a
Ako se u CWD-u (trenutnoj radnoj fascikli) nađe sopstvena datoteka loga (LOGO.BIN), ona zamenjuje ugrađeni logo PS2BBLE/PSXBBLE.

Pretvorite PNG u očekivanu sirovu datoteku:
  - PNG treba da bude RGBA, 8-bitni indeksirani, 255 boja po kanalu i u rezoluciji 256x64.

  - Paket izdanja (skripta je u korenu izdanja):
  ```bash
  python png_to_logo_rbga.py my_logo.png
  ```

  - Napravljeni `LOGO.BIN` stavite pored PS2BBL Extended. To bi trebalo da bude `mc?:/BOOT/` ako koristite preuzimanja iz [PS2 Homebrew Store](https://ps2store.com)

<a id="retrogem-visual-game-id"></a>

### Vizuelni ID igre od Retrogema
- `APP_GAMEID = 1` uključuje vizuelni ID igre za aplikacije/homebrew, do 11 znakova iz naziva datoteke ili sa diska PS1/2
- `CDROM_DISABLE_GAMEID = 1` isključuje vizuelni ID igre za diskove pokrenute preko `cdrom`.

<a id="disc-spin-control"></a>

### Upravljanje okretanjem diska
- Globalni ključ/vrednost: `DISC_STOP = 0/1`
- `DISC_STOP = 1` zaustavlja optički disk posle učitavanja konfiguracije kada je pronađena konfiguraciona datoteka.
- `DISC_STOP = 0` (ili izostavljeno) zadržava podrazumevano ponašanje.
- `-disc_stop` može da se doda svakom unosu za pokretanje da se disk zaustavi kada se pronađe ciljni ELF.

<a id="video-mode"></a>

### Video režim
- `VIDEO_MODE = AUTO, NTSC, PAL, 480P` Koristi podrazumevani režim PS2 ili nameće jedan od ostala 3.

<a id="emergency-video-mode-selector"></a>

#### Hitni izbor video režima
- Otvara se sa `TRIANGLE + CROSS` tokom pokretanja
- Izbor nameće `LOGO_DISPLAY = 3` dok je aktivan, da vidite logo i tastere.
- Upravljanje:
  - `LEFT/RIGHT` menjaju režime: `AUTO`, `NTSC`, `PAL`, `480P`
  - `SELECT` čuva izabrani režim u aktivnoj konfiguracionoj datoteci
  - `START` izlazi iz izbora i nastavlja na prikaz tastera

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
- Dodajte `-nologo` argumentima unosa da se PS2 diskovi pokreću direktno (bez `rom0:PS2LOGO`).
- Bez `-nologo`, PS2BBL pokreće disk preko PS2LOGO i krpi ga da uvek koristi region diska i preskoči proveru kontrolnog zbira loga.
- DECKARD IE 75K i noviji: XPARAM.IRX se primenjuje automatski kada je potrebno za pokretanja bez loga.

<a id="ps1-disc-arguments-per-launch"></a>

#### Argumenti za PS1 diskove (po pokretanju)
Važe za svaki unos `cdrom`, a ne globalno.
- `-ps1fast` uključuje brzu brzinu diska PS1.
- `-ps1smooth` uključuje ublažavanje tekstura.
- `-ps1vneg` pokreće PS1DRV preko PS1VModeNegator. Korisno tamo gde se režim konzole i režim diska razlikuju (na primer neki slučajevi MechaPwn/modčipova).

<a id="app-arguments"></a>

### Argumenti aplikacija
Redovima `ARG_<BUTTON>_E? =` predajete argumente ELF-u (pogledajte INI primere).
- Prvo upišite argumente pokrenutog elf-a, pa zatim dodajte željene interne argumente PS2BBL-a (vidi ispod). [NHDDL](https://github.com/pcm720/nhddl) je odličan kandidat za argumente jer ubrzavaju njegovo pokretanje.
- `-titleid=SLUS_123.45` zamenjuje ID naslova aplikacije (do 11 znakova).
- `-appid` nameće vizuelni ID igre aplikacije čak i uz `APP_GAMEID = 0`.
- `-disc_stop` zaustavlja disk posle učitavanja ciljnog ELF-a (korisno po unosu bez izgradnji `DISC_STOP_AT_BOOT`).
- `-gsm=<v[:c]>` pokreće ciljni ELF preko ugrađenog eGSM-a (zanemaruje se za putanje `rom?:`). Ako se koristi, mora biti poslednji argument.
- `-disc_stop` se zanemaruje za unose `cdrom`.
- `-dev9=<mode>` podešava pravilo DEV9/HDD pre pokretanja ciljnog ELF-a. Podržani režimi:
  - `NICHDD` drži uključenim i DEV9 (mrežni adapter) i HDD.
  - `NIC` drži DEV9/mrežu uključenim, demontira `pfs0:` i odmah uspavljuje `hdd0:`/`hdd1:`.
  - ako je izostavljeno, PS2BBL ne nameće nikakvo pravilo DEV9.
  - napomena: u izgradnjama bez HDD-a ova opcija nema efekta.
- `-patinfo` uključuje obradu PATINFO za unose `:PATINFO`.
  - PS2BBL čita `SYSTEM.CNF` iz oblasti atributa particije (`PS2ICON3D`) i primenjuje `BOOT2/BOOT/path`, `arg*`, `skip_argv0` i `HDDUNITPOWER`.
  - ako je `BOOT2/BOOT/path=PATINFO`, PS2BBL učitava ugrađeni ELF iz oblasti atributa particije i koristi interno predavanje `-la=E...`.
  - ako je `IOPRP=PATINFO` (ili sopstvena putanja), PS2BBL ga predaje fazi 2 internim predavanjem `-la=I...`.
  - ako je prisutan `-patinfo`, prvi preostali argument zamenjuje cilj `BOOT2/BOOT/path` iz CNF-a.
  Ovo je za izgradnje HDD.  
  Primer PATINFO:  
    ```
    NAME_R1 = My App via PATINFO
    LK_R1_E1 = hdd0:+OSDMENU:PATINFO
    ARG_R1_E1 = pfs:/APPS/MYAPP.ELF
    ARG_R1_E1 = -patinfo               # Tells PS2BBL to use first arg as patinfo boot path.
    ```

Primer pokretanja NHDDL-a u video režimu 480p uz traženje ISO datoteka na mmce i exFAT HDD-u bez potrebe za nhddl.yaml. Prednost je što se ne gubi vreme na učitavanje drajvera i traženje i učitavanje nhddl.yaml. To je najbrži način da pokrenete NHDDL i prikažete spisak ISO datoteka.
```
NAME_R1 = NHDDL
LK_R1_E1 = mmce?:/NEUTRINO/nhddl.elf
ARG_R1_E1 = -video=480p
ARG_R1_E1 = -mode=mmce
ARG_R1_E1 = -mode=ata
```

<a id="argument-precedence-and-order"></a>

#### Prednost i redosled argumenata
1. PS2BBL obrađuje i troši samo završne kontrolne argumente loadera iz `ARG_*`: `-appid`, `-titleid=`, `-dev9=`, `-patinfo`, `-disc_stop`, `-gsm=`.
2. Obrada ide odozdo nagore i staje na prvom argumentu koji nije kontrolni (završno ponašanje kao u OSDMenu).
4. Za putanje `:PATINFO`, PS2BBL obrađuje `SYSTEM.CNF` iz atributa particije i dodaje unose `arg*` iz CNF-a posle korisnikovih argumenata aplikacije.
5. Ako je podešen `-patinfo` i putanja sadrži `:PATINFO`, korisnikov prvi preostali argument aplikacije postaje putanja ciljnog ELF-a (zamenjuje putanju pokretanja iz CNF-a) i uklanja se iz argv aplikacije. Ako ne ostane nijedan argument, pokretanje se prekida (kao u OSDMenu), a `BOOT2/BOOT/path` iz CNF-a se ne koristi.
6. Preostali argumenti zadržavaju redosled i predaju se pokrenutoj aplikaciji.


### eGSM (external Graphics Synthesize Mode)
Za PS2 diskove eGSM se automatski čita iz `OSDGSM.CNF` (u INI-ju nije potrebna putanja). Format konfiguracione datoteke pogledajte [ovde](https://github.com/pcm720/OSDMenu/blob/main/patcher/README.md#osdgsmcnf).

- `-gsm=<v[:c]>` pokreće ciljni ELF preko ugrađenog eGSM-a (zanemaruje se za putanje `rom?:`).
  - eGSM se primenjuje na pokrenuti cilj (ELF/disk), a ne na sam PS2BBL.
  Format eGSM-a (kao u OSDMenu):
- `v` = video režim:
- prazno = ne nametati (podrazumevano)
- `fp1` = nametni progresivno skeniranje (240p/288p)
- `fp2` = nametni progresivno skeniranje (480p/576p)
- `1080ix1` = nametni 1080i, širina/visina x1
- `1080ix2` = nametni 1080i, širina/visina x2
- `1080ix3` = nametni 1080i, širina/visina x3
- `c` = režim kompatibilnosti:
- prazno = nijedan (podrazumevano)
- `1` = zamena poluslika tip 1
- `2` = zamena poluslika tip 2
- `3` = zamena poluslika tip 3

Primeri ARG-ova za eGSM:
- `-gsm=fp2`
- `-gsm=fp2:1`
- `-gsm=1080ix2`

Primer upotrebe:
```
LK_TRIANGLE_E1 = mc0:/APP_WLE-ISR/WLE-ISR.ELF
ARG_TRIANGLE_E1 = -gsm=1080ix2
```

<a id="deprecatedremoved"></a>

## Zastarelo/Uklonjeno
- ~~`RUNKELF`~~ PS2BBLE sada interno pokreće elf/kelf, bez potrebe da korisnik definiše radnju pokretanja kelf.


<a id="known-bugsissues"></a>

## Poznate greške/problemi

vi meni recite ;)

<a id="credits--thanks"></a>

## Zasluge i zahvalnice

- Od saildot4k
  - @israpps za [PS2BBL](https://github.com/israpps/PlayStation2-Basic-BootLoader/)
  - @pcm720 za
    - Retrogem gameID, PS1 Video Negator, eGSM i kod PS2LOGO iz [OSDMenu](https://github.com/pcm720/OSDMenu)
    - opcije video režima iz [NHDDL](https://github.com/pcm720/nhddl)
  - @sp193 za [PS1 Video Negator](https://github.com/ps2homebrew/PS1VModeNeg)
  - @nathanneurotic za 10 putanja PS2BBLE-a, ideje i nagovaranje
  - [@Berion](https://www.psx-place.com/members/berion.1431/) za logotipe, pozadinu i grafiku tastera

- Od [El Isra](https://israpps.github.io/) (programer PS2BBL-a): 
  - @SP193 za biblioteke za inicijalizaciju OSD-a, koje su temelj ovog projekta
  - @asmblur, što me je podstakao da napravim ovo čudovište na najnovijem SDK-u
  - @uyjulian i @fjtrujy što mi uvek pomažu


<p align="center"><sub><a href="https://github.com/akilluminati47/RIPPS2">RIPPS2</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2/releases/latest/download/RIPPS2.elf">Preuzmi</a> &nbsp;&middot;&nbsp; <b>BIBLE</b> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2-themes">Teme</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPCSX2">RIPPCSX2</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2-fonts">Fontovi</a> &nbsp;&middot;&nbsp; <a href="https://akilluminati47.github.io/RIPPS2/">Sajt</a> &nbsp;&middot;&nbsp; <a href="https://www.psx-place.com/threads/ripps2-a-ps2-front-end-in-one-elf-launch-disc-storage-memory-files.51316/">psx-place</a> &nbsp;&middot;&nbsp; <a href="https://discord.gg/Z7m9u5kby">Discord</a></sub></p>

