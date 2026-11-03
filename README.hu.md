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
  <b>Magyar</b> |
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

<p align="center"><sub>Az angol README fordítása; eltérés esetén az angol az irányadó. <a href="README.md">English</a></sub></p>

<p align="center"><sub><a href="https://github.com/akilluminati47/RIPPS2">RIPPS2</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2/releases/latest/download/RIPPS2.elf">Letöltés</a> &nbsp;&middot;&nbsp; <b>BIBLE</b> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2-themes">Témák</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPCSX2">RIPPCSX2</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2-fonts">Betűtípusok</a> &nbsp;&middot;&nbsp; <a href="https://akilluminati47.github.io/RIPPS2/">Weboldal</a> &nbsp;&middot;&nbsp; <a href="https://www.psx-place.com/threads/ripps2-a-ps2-front-end-in-one-elf-launch-disc-storage-memory-files.51316/">psx-place</a> &nbsp;&middot;&nbsp; <a href="https://discord.gg/Z7m9u5kby">Discord</a></sub></p>

<h1 align="center">BIBLE</h1>
<p align="center">
  <a href="https://github.com/akilluminati47/RIPPS2">RIPPS2</a> ·
  <a href="https://github.com/akilluminati47/BIBLE/actions">Buildek</a> ·
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
  <sub>Indításkor tartsd lenyomva az L2 + R2 gombot az indítógombok oldalához, a TRIANGLE + CROSS gombot a videómód oldalához; a <code>$CREDITS</code> értékre állított gomb a stáblistát mutatja.</sub>
</p>

A BIBLE az a rendszerbetöltő, amelyet a RIPPS2 telepít: saildot4k PS2BBL Extended programjának forkja.

**Mit változtat ez a fork**

- A nyitókép: a PS2 logó középen a RIPPS2 égboltján, alatta a gombok, felette az esetleges szöveg. `BIBLE_GLYPHS` 0 semmi, 1 az akciógombok (alapértelmezett), 2 mind a tizenhat két nyolcas sorban. `BIBLE_INFO` 1 mutatja a konzol adatait, az órát és a visszaszámlálást (alapból ki). Az égbolt a RIPPS2 Color Theme-et követi: `BIBLE_COLOR` nélkül a BIBLE azt az égboltot olvassa, amit a RIPPS2 a beállításaival ment, abból a mappából, amit az AUTO bejegyzése indít, vagy egy memóriakártya `RIPPS2` mappájából, ha az AUTO bejegyzés a RIPPS2 SD2PSX-en, USB-n vagy a merevlemezen (a konfigurációban lévő `BIBLE_COLOR` nyer). Ugyanaz a kinézet minden videómódban.
- `BIBLE_BACKGROUND`: `AUTO` (alapértelmezett: az égbolt, ha megvannak a RIPPS2 beállításai vagy be van állítva `BIBLE_COLOR`, különben fekete a konzol saját módjában, egy egyszerű bootloader), `SKY` vagy `BLANK` (fekete). Az átmenet egy programba úgyis néhány másodpercig fekete, így a fekete egy darabnak hat vele.
- Az indítási hang, előkészítve: a RIPPS2 Boot Sound On (fast) beállítása a `boot.adp` fájlt a BIBLE konfigurációja mellett tarthatja (`mc?:/SYS-CONF/boot.adp`). A BIBLE beolvassa, amíg a nyitókép visszaszámol, és a RAM-ban átadja a RIPPS2-nek, így a RIPPS2 első képkockájával szól akkor is, ha a RIPPS2 SD2PSX-ről indul (MMCE, MX4SIO és HDD build; a memóriakártyás / USB build megmondja a RIPPS2-nek a mappát, és a RIPPS2 olvassa be). A BIBLE indításkor megvárja a még be nem olvasott részt: `KEY_READ_WAIT_TIME = 0` mellett ez a teljes olvasás, kb. 2 s memóriakártyán. **Hang nélkül a leggyorsabb az indulás.** A megállapodás és a RIPPS2 oldala: [docs/boot-sound-handoff.md](docs/boot-sound-handoff.md).
- Először a RIPPS2: a konfigurációs sablon (`release/SYS-CONF/PS2BBL.INI`) és a beépített alapértékek a `mc?:/RIPPS2/RIPPS2.ELF` és a `mmce?:/APPS/RIPPS2.ELF` útvonalat próbálják az OSDMenu és az FMCB előtt, a sablon pedig megjegyzésekkel sorolja a BIBLE saját kulcsait. Az oldalak (videómód, készítők, indítógombok) a halványított logó fölött úsznak be, a gombok elrakva, hogy az indítógombok nyugodtan olvashatók legyenek.
- Videómódok: a `VIDEO_MODE` elfogadja a `576P`, `720P` és `1080I` értéket is, a RIPPS2 többi módját. Az `AUTO` (alapértelmezés)
  a RIPPS2 Video Mode beállításában indul, ha annak beállításai az AUTO bejegyzés mellett vannak, különben a konzol saját módjában.
- `BIBLE_WIDESCREEN`: `AUTO` (alapértelmezés: a RIPPS2 Widescreen beállítása, különben a PS2 16:9-es képernyőbeállítása), `ON` vagy
  `OFF`. 480i, 576i, 480p és 576p módban az indítóképernyő olyan tévéhez készül, amely 16:9-re nyújtja a képet, lapítás
  nélkül. A 720p és az 1080i már eleve 16:9.
- Nincs ugrás a RIPPS2-be lépéskor: indításkor a logó és a gombok elhalványulnak, az ég pedig a képernyőn marad a RIPPS2 módjában;
  a RIPPS2 ugyanezen az égen indul. Indításkor tartsd lenyomva a TRIANGLE + CROSS gombot a videómód oldalához, amely mindig
  a konzol saját váltottsoros módjában nyílik meg (az út vissza 720p-ből vagy 1080i-ből kompozit kábelen).
- Új: az indítógombok oldala. Tartsd lenyomva az L2 + R2 gombot bekapcsoláskor, és a BIBLE megáll, mielőtt bármit elindítana, és megmutatja minden gomb jelenlegi indítási útvonalát, bármi is a nyitókép beállítása (hasznos `LOGO_DISPLAY = 0` mellett, ahol semmi más nem látszik).
- A bekapcsolástól nyomva tartott kombinációk most megnyitják az oldalaikat (a TRIANGLE + CROSS elveszett, amíg a kontrollerek még
  indultak).
- A `KEY_READ_WAIT_TIME = 0` megengedett (az upstream minimuma 500 ms).
- PS2 buildek memóriakártyára / USB-re, MMCE-re, MX4SIO-ra és HDD-re. Az eGSM 2. szakasza kimarad.

**Hogyan használja a RIPPS2**

A RIPPS2 a RIPPS2.elf fájlban hordozza a BIBLE-t, minden buildet akilluminati47 írt alá, és a Beállítások > Általános > Boot Loader > Manage menüből telepíti vagy frissíti, ahol a BIBLE kulcsait is beállítja: Background, Splash, Button Glyphs, Info Line, Power-on Wait, Video Mode és Widescreen. Az aláírt buildek és egy kész SD2PSX BOOT kártya a [kiadások oldalán](https://github.com/akilluminati47/BIBLE/releases/latest) vannak. A BIBLE ELF-ként is fut, ha egy másik betöltő indítja (FMCB, OSDMenu, egy SD2PSX betöltője).

<p align="center"><img src="assets/readme/ripps2-icon.png" alt="RIPPS2" width="48" height="48"><br><sub>A BIBLE a(z) <a href="https://github.com/akilluminati47/RIPPS2">RIPPS2</a> része.</sub></p>

---

<p align="center"><sub>Minden, ami ezután jön, a PS2BBL Extended eredeti README-je, lefordítva és egyébként változatlanul.</sub></p>

---


<br />
<p align="center">
  <a href="https://israpps.github.io/PlayStation2-Basic-BootLoader/">
    <img src="https://github.com/saildot4k/PlayStation2-Basic-BootLoader-Extended/blob/main/assets/ps2bbl_example.png" alt="Logo" width="50%" height="auto">
  </a>

  <p align="center">
    Rugalmas rendszerbetöltő PlayStation 2™-höz és PSX-DESR-hez
    <br />
  </p>
</p>  


Ez [El Isra](https://github.com/israpps/PlayStation2-Basic-BootLoader/) PS2BBL programjának forkja


<a id="documentation"></a>

## Dokumentáció

A [github pages](https://israpps.github.io/PlayStation2-Basic-BootLoader/) oldalon található, de az alábbi kiegészítésekkel:

<a id="config-and-arguments"></a>

## Konfiguráció és argumentumok

Szerkeszd a konfigurációs fájlt igény szerint. A szerkesztéshez a [R3Configurator](https://github.com/saildot4k/R3CONFIGURATOR) ajánlott. Az útvonalak már úgy vannak beállítva, hogy illeszkedjenek a [PS2 Homebrew Store](https://ps2homebrewstore.com) letöltéseihez. Így elég csak az Auto választásodat szerkeszteni, és érdemes az NHDDL argumentumait annak az eszköznek megfelelően beállítani, amelyről az ISO-kat töltöd.

<a id="config-path-search-order"></a>

### A konfiguráció keresési sorrendje

A konfiguráció keresése most figyelembe veszi az indítási családot, hogy induláskor ne töltsön be fölösleges illesztőprogramokat:

1. `CONFIG.INI` (CWD: aktuális munkakönyvtár)
2. Eszközről betöltve:
   - MMCE-indítás: `mmce?:/PS2BBL/CONFIG.INI`
   - MX4SIO-indítás: `mx4sio:/PS2BBL/CONFIG.INI`
   - APA HDD-indítás: `hdd0:__sysconf:pfs:/PS2BBL/CONFIG.INI`
   - BDM-indítás: `usb:/PS2BBL/CONFIG.INI` / `mass:/PS2BBL/CONFIG.INI` / `ata:/PS2BBL/CONFIG.INI`
3. Tartalék a memóriakártyán:
   - PS2-n: `mc?:/SYS-CONF/PS2BBL.INI`
   - PSX-DESR-en: `mc?:/SYS-CONF/PSXBBL.INI`
4. Utolsó tartalék PSX-en
   - `xfrom:/PS2BBL/CONFIG.INI`
5. Ha `DISC_STOP_AT_BOOT=1 beállítással fordították
   - `cdrom0:/PS2BBL/CONFIG.INI`
   - Tartalék a memóriakártyán a fenti 3. pont szerint.

<a id="device-path-prefixes"></a>

### Az eszközök útvonal-előtagjai
A PS2BBL ezeket az indítási/konfigurációs útvonal-előtagokat támogatja:
- `mc0:/`, `mc1:/`, `mc?:/`
- `usb:/` (ajánlott) és `mass:/` (régi)

<a id="build-specific"></a>

#### Buildtől függően:  
- `mmce0:/`, `mmce1:/`, `mmce?:/` __MMCE buildek__
- `mx4sio:/` (ajánlott) és `massX:/` (régi)  __MX4SIO buildek__
- `hdd0:partition:pfs:/<path to elf>` __HDD buildek__
- `xfrom:/` útvonalak __PSX DESR buildek__
- `ata:/` BDM eszköz exFAT HDD-hez
- `ilink:/` (BDM háttértár-gyökerek) __még nincs megvalósítva__
- `DISC_STOP_AT_BOOT=1` fordítási profil, amely a konfiguráció betöltése után mindig leállítja az optikai lemezt

### LOGO_DISPLAY
A gombok nevének megjelenítéséhez használd a `LOGO_DISPLAY = 3` beállítást. A neveket a `NAME_<BUTTON>` adja meg.
  - `0` Se logó, se konzoladatok
  - `1` Konzoladatok
  - `2` PS2BBLE/PSXBBLE logó és konzoladatok
  - `3` Gombgrafika a konfigurációs fájlból vett `NAME_BUTTON = <TITLE>` értékekkel
    - Példa:
      ```
      NAME_SQUARE = POPSLOADER
      ```

<a id="custom-splash-logo-from-cwd"></a>

#### Saját indítólogó a CWD-ből
Ha a CWD-ben (aktuális munkakönyvtárban) saját logófájl (LOGO.BIN) található, az lecseréli a beépített PS2BBLE/PSXBBLE logót.

Alakíts át egy PNG-t a várt nyers fájllá:
  - A PNG legyen RGBA, 8 bites indexelt, csatornánként 255 szín, 256x64 felbontás.

  - Kiadási csomag (a szkript a kiadás gyökerében van):
  ```bash
  python png_to_logo_rbga.py my_logo.png
  ```

  - Tedd a létrehozott `LOGO.BIN` fájlt a PS2BBL Extended mellé. Ez `mc?:/BOOT/` legyen, ha a [PS2 Homebrew Store](https://ps2store.com) letöltéseit használod

<a id="retrogem-visual-game-id"></a>

### A Retrogem vizuális játékazonosítója
- Az `APP_GAMEID = 1` bekapcsolja a vizuális játékazonosítót appokhoz/homebrew-hoz, legfeljebb 11 karakterrel a fájlnévből vagy a PS1/2 lemezről
- A `CDROM_DISABLE_GAMEID = 1` kikapcsolja a vizuális játékazonosítót a `cdrom` útján indított lemezeknél.

<a id="disc-spin-control"></a>

### A lemez forgásának vezérlése
- Globális kulcs/érték: `DISC_STOP = 0/1`
- A `DISC_STOP = 1` a konfiguráció betöltése után leállítja az optikai lemezt, ha talált konfigurációs fájlt.
- A `DISC_STOP = 0` (vagy elhagyva) megtartja az alapértelmezett viselkedést.
- A `-disc_stop` minden indítási bejegyzéshez hozzáadható, hogy a lemez megálljon, amint megvan a cél ELF.

<a id="video-mode"></a>

### Videómód
- `VIDEO_MODE = AUTO, NTSC, PAL, 480P` A PS2 alapértelmezését használja, vagy kikényszeríti a másik 3 mód egyikét.

<a id="emergency-video-mode-selector"></a>

#### Vészhelyzeti videómód-választó
- Indítás közben a `TRIANGLE + CROSS` gombbal nyílik meg
- Amíg aktív, a választó kikényszeríti a `LOGO_DISPLAY = 3` beállítást, hogy lásd a logót és a gombokat.
- Vezérlés:
  - `LEFT/RIGHT` lépteti a módokat: `AUTO`, `NTSC`, `PAL`, `480P`
  - `SELECT` elmenti a kiválasztott módot az aktív konfigurációs fájlba
  - `START` kilép a választóból, és továbblép a gombok kijelzésére

<a id="cdrom-launch-args"></a>

### CDROM indítási argumentumok
A `LK_*_E* = cdrom` esetén támogatott argumentumok:
- `-nologo`
- `-nogameid`
- `-ps1fast`
- `-ps1smooth`
- `-ps1vneg`
- `-gsm=<v[:c]>`

<a id="ps2logo-arguments-ps2-discs-only"></a>

#### PS2LOGO argumentumok (csak PS2 lemezek)
- Az indítási bejegyzés útvonalaként használd a `cdrom` értéket.
- Add hozzá a `-nologo` argumentumot a bejegyzéshez, hogy a PS2 lemezek közvetlenül induljanak (a `rom0:PS2LOGO` kihagyásával).
- `-nologo` nélkül a PS2BBL a PS2LOGO-n keresztül indítja a lemezt, és úgy foltozza, hogy mindig a lemez régióját használja és kikerülje a logó ellenőrzőösszegét.
- DECKARD IE 75K és újabb: az XPARAM.IRX automatikusan alkalmazódik, ha a logó nélküli indításhoz szükséges.

<a id="ps1-disc-arguments-per-launch"></a>

#### PS1 lemezek argumentumai (indításonként)
Ezek a `cdrom` indítási bejegyzésekre egyenként érvényesek, nem globálisan.
- A `-ps1fast` bekapcsolja a gyors PS1 lemezsebességet.
- A `-ps1smooth` bekapcsolja a textúrasimítást.
- A `-ps1vneg` a PS1VModeNegator-on keresztül futtatja a PS1DRV-t. Hasznos ott, ahol a konzol és a lemez módja eltér (például egyes MechaPwn/modchip esetekben).

<a id="app-arguments"></a>

### Appok argumentumai
Az `ARG_<BUTTON>_E? =` sorokkal adhatsz át argumentumokat egy ELF-nek (lásd az INI példákat).
- Először add meg az indított elf argumentumait, utána fűzd hozzá a kívánt belső PS2BBL argumentumokat (lásd lent). Az [NHDDL](https://github.com/pcm720/nhddl) remek jelölt az argumentumokra, mert gyorsítják az indulását.
- A `-titleid=SLUS_123.45` felülírja az app címazonosítóját (legfeljebb 11 karakter).
- Az `-appid` kikényszeríti az app vizuális játékazonosítóját akkor is, ha `APP_GAMEID = 0`.
- A `-disc_stop` a cél ELF betöltése után leállítja a lemezt (bejegyzésenként hasznos `DISC_STOP_AT_BOOT` buildek nélkül).
- A `-gsm=<v[:c]>` a beépített eGSM-en keresztül futtatja a cél ELF-et (`rom?:` útvonalaknál figyelmen kívül marad). Ha használod, ennek kell az utolsó argumentumnak lennie.
- A `-disc_stop` a `cdrom` indítási bejegyzéseknél figyelmen kívül marad.
- A `-dev9=<mode>` a cél ELF indítása előtt beállítja a DEV9/HDD szabályt. Támogatott módok:
  - `NICHDD` bekapcsolva tartja a DEV9-et (hálózati adapter) és a HDD-t is.
  - `NIC` bekapcsolva tartja a DEV9-et/hálózatot, leválasztja a `pfs0:` kötetet, és azonnal pihenőbe teszi a `hdd0:`/`hdd1:` lemezt.
  - ha elhagyod, a PS2BBL nem kényszerít ki DEV9 szabályt.
  - megjegyzés: HDD nélküli buildeken ennek az opciónak nincs hatása.
- A `-patinfo` bekapcsolja a PATINFO kezelését a `:PATINFO` bejegyzésekhez.
  - A PS2BBL a partíció attribútumterületéről (`PS2ICON3D`) olvassa a `SYSTEM.CNF` fájlt, és alkalmazza a `BOOT2/BOOT/path`, `arg*`, `skip_argv0` és `HDDUNITPOWER` értékeket.
  - ha `BOOT2/BOOT/path=PATINFO`, a PS2BBL a partíció attribútumterületéről tölti be a beágyazott ELF-et, és a belső `-la=E...` átadást használja.
  - ha `IOPRP=PATINFO` (vagy saját útvonal), a PS2BBL a belső `-la=I...` átadással adja tovább a 2. szakasznak.
  - ha a `-patinfo` jelen van, az első megmaradt argumentum felülírja a CNF `BOOT2/BOOT/path` célját.
  Ez a HDD buildekre vonatkozik.  
  PATINFO példa:  
    ```
    NAME_R1 = My App via PATINFO
    LK_R1_E1 = hdd0:+OSDMENU:PATINFO
    ARG_R1_E1 = pfs:/APPS/MYAPP.ELF
    ARG_R1_E1 = -patinfo               # Tells PS2BBL to use first arg as patinfo boot path.
    ```

Példa az NHDDL indítására 480p videómódban, amely nhddl.yaml nélkül keres ISO-kat mmce-n és exFAT HDD-n. Az előny, hogy nem megy el idő illesztőprogramok betöltésére, a nhddl.yaml keresésére és betöltésére. Ez a leggyorsabb módja az NHDDL indításának és az ISO lista megjelenítésének.
```
NAME_R1 = NHDDL
LK_R1_E1 = mmce?:/NEUTRINO/nhddl.elf
ARG_R1_E1 = -video=480p
ARG_R1_E1 = -mode=mmce
ARG_R1_E1 = -mode=ata
```

<a id="argument-precedence-and-order"></a>

#### Az argumentumok elsőbbsége és sorrendje
1. A PS2BBL csak az `ARG_*` végén álló betöltővezérlő argumentumokat dolgozza fel és használja el: `-appid`, `-titleid=`, `-dev9=`, `-patinfo`, `-disc_stop`, `-gsm=`.
2. A feldolgozás alulról felfelé halad, és az első nem vezérlő argumentumnál megáll (záró viselkedés OSDMenu módra).
4. `:PATINFO` indítási útvonalaknál a PS2BBL feldolgozza a partícióattribútum `SYSTEM.CNF` fájlját, és a felhasználó app-argumentumai után fűzi a CNF `arg*` bejegyzéseit.
5. Ha a `-patinfo` be van állítva, és az indítási útvonal tartalmazza a `:PATINFO` részt, a felhasználó első megmaradt app-argumentuma lesz a cél ELF útvonala (felülírja a CNF indítási útvonalát), és kikerül az app argv-jéből. Ha nem marad argumentum, az indítás megszakad (mint az OSDMenu-ben), és a CNF `BOOT2/BOOT/path` értéke nem kerül felhasználásra.
6. A megmaradt argumentumok megtartják a sorrendjüket, és az indított app kapja meg őket.


### eGSM (external Graphics Synthesize Mode)
PS2 lemezeknél az eGSM automatikusan az `OSDGSM.CNF` fájlból töltődik be (nem kell útvonal az INI-ben). A konfigurációs fájl formátumát lásd [itt](https://github.com/pcm720/OSDMenu/blob/main/patcher/README.md#osdgsmcnf).

- A `-gsm=<v[:c]>` a beépített eGSM-en keresztül futtatja a cél ELF-et (`rom?:` útvonalaknál figyelmen kívül marad).
  - Az eGSM az indított célra (ELF/lemez) vonatkozik, nem magára a PS2BBL-re.
  Az eGSM formátuma (OSDMenu módra):
- `v` = videómód:
- üres = nincs kényszerítés (alapértelmezés)
- `fp1` = progresszív letapogatás kényszerítése (240p/288p)
- `fp2` = progresszív letapogatás kényszerítése (480p/576p)
- `1080ix1` = 1080i kényszerítése, szélesség/magasság x1
- `1080ix2` = 1080i kényszerítése, szélesség/magasság x2
- `1080ix3` = 1080i kényszerítése, szélesség/magasság x3
- `c` = kompatibilitási mód:
- üres = nincs (alapértelmezés)
- `1` = félképcsere, 1-es típus
- `2` = félképcsere, 2-es típus
- `3` = félképcsere, 3-as típus

eGSM ARG példák:
- `-gsm=fp2`
- `-gsm=fp2:1`
- `-gsm=1080ix2`

Használati példa:
```
LK_TRIANGLE_E1 = mc0:/APP_WLE-ISR/WLE-ISR.ELF
ARG_TRIANGLE_E1 = -gsm=1080ix2
```

<a id="deprecatedremoved"></a>

## Elavult/Eltávolítva
- ~~`RUNKELF`~~ A PS2BBLE most belsőleg indítja az elf/kelf fájlokat, a felhasználónak nem kell kelf indítási műveletet megadnia.


<a id="known-bugsissues"></a>

## Ismert hibák/problémák

te mondd meg ;)

<a id="credits--thanks"></a>

## Köszönet és elismerés

- saildot4k részéről
  - @israpps a [PS2BBL](https://github.com/israpps/PlayStation2-Basic-BootLoader/) miatt
  - @pcm720:
    - a Retrogem gameID, a PS1 Video Negator, az eGSM és a PS2LOGO kód az [OSDMenu](https://github.com/pcm720/OSDMenu) programból
    - a videómód beállításai az [NHDDL](https://github.com/pcm720/nhddl) programból
  - @sp193 a [PS1 Video Negator](https://github.com/ps2homebrew/PS1VModeNeg) miatt
  - @nathanneurotic a PS2BBLE 10 útvonaláért, az ötletekért és a rábeszélésért
  - [@Berion](https://www.psx-place.com/members/berion.1431/) a logókért, a háttérért és a gombgrafikákért

- [El Isra](https://israpps.github.io/) (a PS2BBL fejlesztője) részéről: 
  - @SP193 az OSD inicializáló könyvtárakért, amelyekre ez a projekt épül
  - @asmblur, aki biztatott, hogy a legújabb SDK-n készítsem el ezt a szörnyet
  - @uyjulian és @fjtrujy, mert mindig segítenek


<p align="center"><sub><a href="https://github.com/akilluminati47/RIPPS2">RIPPS2</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2/releases/latest/download/RIPPS2.elf">Letöltés</a> &nbsp;&middot;&nbsp; <b>BIBLE</b> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2-themes">Témák</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPCSX2">RIPPCSX2</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2-fonts">Betűtípusok</a> &nbsp;&middot;&nbsp; <a href="https://akilluminati47.github.io/RIPPS2/">Weboldal</a> &nbsp;&middot;&nbsp; <a href="https://www.psx-place.com/threads/ripps2-a-ps2-front-end-in-one-elf-launch-disc-storage-memory-files.51316/">psx-place</a> &nbsp;&middot;&nbsp; <a href="https://discord.gg/Z7m9u5kby">Discord</a></sub></p>

