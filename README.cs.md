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
  <b>Čeština</b> |
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

<p align="center"><sub>Překlad anglického README; pokud se liší, platí angličtina. <a href="README.md">English</a></sub></p>

<p align="center"><sub><a href="https://github.com/akilluminati47/RIPPS2">RIPPS2</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2/releases/latest/download/RIPPS2.elf">Stáhnout</a> &nbsp;&middot;&nbsp; <b>BIBLE</b> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2-themes">Motivy</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPCSX2">RIPPCSX2</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2-fonts">Písma</a> &nbsp;&middot;&nbsp; <a href="https://akilluminati47.github.io/RIPPS2/">Web</a> &nbsp;&middot;&nbsp; <a href="https://www.psx-place.com/threads/ripps2-a-ps2-front-end-in-one-elf-launch-disc-storage-memory-files.51316/">psx-place</a> &nbsp;&middot;&nbsp; <a href="https://discord.gg/Z7m9u5kby">Discord</a></sub></p>

<h1 align="center">BIBLE</h1>
<p align="center">
  <a href="https://github.com/akilluminati47/RIPPS2">RIPPS2</a> ·
  <a href="https://github.com/akilluminati47/BIBLE/actions">Sestavení</a> ·
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
  <sub>Při startu podržte L2 + R2 pro stránku spouštěcích kláves, TRIANGLE + CROSS pro stránku režimu videa; klávesa nastavená na <code>$CREDITS</code> zobrazí titulky.</sub>
</p>

BIBLE je zavaděč, který nastavuje RIPPS2: fork PS2BBL Extended od saildot4k.

**Co tento fork mění**

- Úvodní obrazovka: logo PS2 uprostřed oblohy RIPPS2, pod ním tlačítka a nad ním případný text. `BIBLE_GLYPHS` 0 žádná, 1 akční tlačítka (výchozí), 2 všech šestnáct ve dvou řadách po osmi. `BIBLE_INFO` 1 ukáže informace o konzoli, hodiny a odpočet (ve výchozím stavu vypnuto). Obloha odpovídá vašemu Color Theme v RIPPS2: bez `BIBLE_COLOR` čte BIBLE oblohu, kterou RIPPS2 ukládá se svým nastavením, ze složky, kterou spouští jeho položka AUTO, nebo ze složky `RIPPS2` na paměťové kartě, když je položka AUTO RIPPS2 na SD2PSX, USB nebo pevném disku (`BIBLE_COLOR` v konfiguraci vyhrává). Stejný vzhled v každém video režimu.
- `BIBLE_BACKGROUND`: `AUTO` (výchozí: obloha, když se najde nastavení RIPPS2 nebo je nastaveno `BIBLE_COLOR`, jinak černá ve vlastním režimu konzole, obyčejný zavaděč), `SKY` nebo `BLANK` (černá). Přechod do programu je stejně pár sekund černý, takže černá s ním působí jako jeden celek.
- Zvuk spuštění, připravený: Boot Sound On (fast) v RIPPS2 může mít `boot.adp` vedle konfigurace BIBLE (`mc?:/SYS-CONF/boot.adp`). Čte se dřív, než se spustí jakákoli jednotka. BIBLE ho může předat RIPPS2 i v RAM, ale to zatím prošlo jen v laboratoři: na skutečném SD2PSX si RIPPS2 přečetl kopii z karty sám. **Bez zvuku je start nejrychlejší.** Dohoda a strana RIPPS2: [docs/boot-sound-handoff.md](docs/boot-sound-handoff.md).
- RIPPS2 napřed: šablona konfigurace (`release/SYS-CONF/PS2BBL.INI`) a vestavěné výchozí hodnoty zkoušejí `mc?:/RIPPS2/RIPPS2.ELF` a `mmce?:/APPS/RIPPS2.ELF` před OSDMenu a FMCB a šablona uvádí vlastní klíče BIBLE s poznámkami. Stránky (video režim, autoři, spouštěcí tlačítka) se objeví přes ztlumené logo s uklizenými tlačítky, aby se spouštěcí tlačítka dala v klidu číst.
- Režimy videa: `VIDEO_MODE` bere také `576P`, `720P` a `1080I`, zbytek režimů RIPPS2. `AUTO` (výchozí)
  startuje ve Video Mode RIPPS2, když najde jeho nastavení vedle položky AUTO, jinak v režimu konzole.
- `BIBLE_WIDESCREEN`: `AUTO` (výchozí: Widescreen z RIPPS2, jinak nastavení obrazovky 16:9 v PS2), `ON` nebo
  `OFF`. V 480i, 576i, 480p a 576p se úvodní obrazovka kreslí pro televizor, který obraz roztáhne na 16:9, bez
  zmáčknutí. 720p a 1080i už jsou 16:9.
- Přechod do RIPPS2: při spuštění logo a tlačítka zmizí a obloha zůstane, dokud konzole nenačte další program, což obrazovku zatemní (asi 7 s v laboratoři s RIPPS2 na paměťové kartě). Potom se RIPPS2 objeví ve stejném režimu videa a stejných barvách. Při startu podržte TRIANGLE + CROSS pro stránku režimu videa, která se vždy otevře
  ve vlastním prokládaném režimu konzole (cesta zpět z 720p nebo 1080i na kompozitním kabelu).
- Novinka: stránka spouštěcích tlačítek. Podržte L2 + R2 při zapnutí a BIBLE se zastaví dřív, než cokoli spustí, a ukáže aktuální spouštěcí cesty každého tlačítka bez ohledu na nastavení úvodní obrazovky (hodí se s `LOGO_DISPLAY = 0`, kde se nic jiného neukáže).
- Kombinace držené od zapnutí teď otevírají své stránky (TRIANGLE + CROSS se ztrácelo, když se ovladače ještě
  spouštěly).
- `KEY_READ_WAIT_TIME = 0` je povoleno (minimum v upstreamu je 500 ms).
- Sestavení pro PS2 pro paměťovou kartu / USB, MMCE, MX4SIO a HDD. Fáze 2 eGSM je vynechána.

**Jak ho RIPPS2 používá**

RIPPS2 nese BIBLE uvnitř RIPPS2.elf, každé sestavení podepsal akilluminati47, a instaluje ho nebo aktualizuje v Nastavení > Obecné > Boot Loader > Manage, kde také nastaví klíče BIBLE: Background, Splash, Button Glyphs, Info Line, Power-on Wait, Video Mode a Widescreen. Podepsaná sestavení a hotová karta BOOT pro SD2PSX jsou na [stránce vydání](https://github.com/akilluminati47/BIBLE/releases/latest). BIBLE běží také jako ELF spuštěný jiným zavaděčem (FMCB, OSDMenu, zavaděč SD2PSX).

<p align="center"><img src="assets/readme/ripps2-icon.png" alt="RIPPS2" width="48" height="48"><br><sub>BIBLE je součástí <a href="https://github.com/akilluminati47/RIPPS2">RIPPS2</a>.</sub></p>

---

<p align="center"><sub>Vše níže je původní README PS2BBL Extended, přeložené a jinak beze změn.</sub></p>

---


<br />
<p align="center">
  <a href="https://israpps.github.io/PlayStation2-Basic-BootLoader/">
    <img src="https://github.com/saildot4k/PlayStation2-Basic-BootLoader-Extended/blob/main/assets/ps2bbl_example.png" alt="Logo" width="50%" height="auto">
  </a>

  <p align="center">
    Pružný zavaděč pro PlayStation 2™ a PSX-DESR
    <br />
  </p>
</p>  


Toto je fork PS2BBL od [El Isra](https://github.com/israpps/PlayStation2-Basic-BootLoader/)


<a id="documentation"></a>

## Dokumentace

Je na [github pages](https://israpps.github.io/PlayStation2-Basic-BootLoader/), ale s doplňky níže:

<a id="config-and-arguments"></a>

## Konfigurace a argumenty

Upravte konfigurační soubor podle potřeby. K úpravám se doporučuje [R3Configurator](https://github.com/saildot4k/R3CONFIGURATOR). Cesty jsou už nastavené tak, aby odpovídaly souborům staženým z [PS2 Homebrew Store](https://ps2homebrewstore.com). Měli byste tedy upravit jen svou volbu Auto a nejlépe nastavit argumenty pro NHDDL podle zařízení, ze kterého načítáte ISO.

<a id="config-path-search-order"></a>

### Pořadí hledání konfigurace

Hledání konfigurace teď bere ohled na rodinu spouštění, aby se při startu nenačítaly zbytečné ovladače:

1. `CONFIG.INI` (CWD: aktuální pracovní adresář)
2. Při načtení ze zařízení:
   - Start z MMCE: `mmce?:/PS2BBL/CONFIG.INI`
   - Start z MX4SIO: `mx4sio:/PS2BBL/CONFIG.INI`
   - Start z APA HDD: `hdd0:__sysconf:pfs:/PS2BBL/CONFIG.INI`
   - Start z BDM: `usb:/PS2BBL/CONFIG.INI` / `mass:/PS2BBL/CONFIG.INI` / `ata:/PS2BBL/CONFIG.INI`
3. Záloha na paměťové kartě:
   - Na PS2: `mc?:/SYS-CONF/PS2BBL.INI`
   - Na PSX-DESR: `mc?:/SYS-CONF/PSXBBL.INI`
4. Poslední záloha na PSX
   - `xfrom:/PS2BBL/CONFIG.INI`
5. Při kompilaci s `DISC_STOP_AT_BOOT=1
   - `cdrom0:/PS2BBL/CONFIG.INI`
   - Záloha na paměťové kartě jako v bodě 3 výše.

<a id="device-path-prefixes"></a>

### Předpony cest zařízení
PS2BBL podporuje tyto předpony spouštěcích a konfiguračních cest:
- `mc0:/`, `mc1:/`, `mc?:/`
- `usb:/` (preferovaná) a `mass:/` (stará)

<a id="build-specific"></a>

#### Podle sestavení:  
- `mmce0:/`, `mmce1:/`, `mmce?:/` __sestavení MMCE__
- `mx4sio:/` (preferovaná) a `massX:/` (stará)  __sestavení MX4SIO__
- `hdd0:partition:pfs:/<path to elf>` __sestavení HDD__
- Cesty `xfrom:/` __sestavení PSX DESR__
- `ata:/` zařízení BDM pro HDD s exFAT
- `ilink:/` (kořeny velkokapacitních úložišť BDM) __zatím neimplementováno__
- `DISC_STOP_AT_BOOT=1` profil sestavení, který po načtení konfigurace vždy zastaví optický disk

### LOGO_DISPLAY
Použijte `LOGO_DISPLAY = 3` pro zobrazení názvů kláves. Názvy určuje `NAME_<BUTTON>`.
  - `0` Bez loga a informací o konzoli
  - `1` Informace o konzoli
  - `2` Logo PS2BBLE/PSXBBLE a informace o konzoli
  - `3` Grafika kláves s `NAME_BUTTON = <TITLE>` z konfiguračního souboru
    - Příklad:
      ```
      NAME_SQUARE = POPSLOADER
      ```

<a id="custom-splash-logo-from-cwd"></a>

#### Vlastní úvodní logo z CWD
Pokud je v CWD (aktuálním pracovním adresáři) vlastní soubor loga (LOGO.BIN), nahradí vestavěné logo PS2BBLE/PSXBBLE.

Převeďte PNG na očekávaný surový soubor:
  - PNG má být RGBA, 8bitové indexované, 255 barev na kanál a v rozlišení 256x64.

  - Balíček vydání (skript je v kořeni vydání):
  ```bash
  python png_to_logo_rbga.py my_logo.png
  ```

  - Vytvořený `LOGO.BIN` dejte vedle PS2BBL Extended. Mělo by to být `mc?:/BOOT/`, pokud používáte soubory z [PS2 Homebrew Store](https://ps2store.com)

<a id="retrogem-visual-game-id"></a>

### Vizuální ID hry od Retrogem
- `APP_GAMEID = 1` zapne vizuální ID hry pro aplikace/homebrew, až 11 znaků z názvu souboru nebo z disku PS1/2
- `CDROM_DISABLE_GAMEID = 1` vypne vizuální ID hry pro disky spuštěné přes `cdrom`.

<a id="disc-spin-control"></a>

### Ovládání otáčení disku
- Globální klíč/hodnota: `DISC_STOP = 0/1`
- `DISC_STOP = 1` zastaví optický disk po načtení konfigurace, pokud byl nalezen konfigurační soubor.
- `DISC_STOP = 0` (nebo vynecháno) ponechá výchozí chování.
- `-disc_stop` lze přidat ke každé spouštěcí položce, aby se disk zastavil po nalezení cílového ELF.

<a id="video-mode"></a>

### Režim videa
- `VIDEO_MODE = AUTO, NTSC, PAL, 480P` Použije výchozí režim PS2 nebo vynutí jeden z ostatních 3.

<a id="emergency-video-mode-selector"></a>

#### Nouzový výběr režimu videa
- Otevře se pomocí `TRIANGLE + CROSS` během startu
- Výběr vynutí `LOGO_DISPLAY = 3`, dokud je aktivní, abyste viděli logo a klávesy.
- Ovládání:
  - `LEFT/RIGHT` přepínají režimy: `AUTO`, `NTSC`, `PAL`, `480P`
  - `SELECT` uloží vybraný režim do aktivního konfiguračního souboru
  - `START` ukončí výběr a pokračuje na zobrazení kláves

<a id="cdrom-launch-args"></a>

### Spouštěcí argumenty CDROM
Pro `LK_*_E* = cdrom` jsou podporovány tyto argumenty:
- `-nologo`
- `-nogameid`
- `-ps1fast`
- `-ps1smooth`
- `-ps1vneg`
- `-gsm=<v[:c]>`

<a id="ps2logo-arguments-ps2-discs-only"></a>

#### Argumenty PS2LOGO (jen disky PS2)
- Jako cestu spouštěcí položky použijte `cdrom`.
- Přidejte `-nologo` do argumentů položky, aby se disky PS2 spouštěly přímo (bez `rom0:PS2LOGO`).
- Bez `-nologo` PS2BBL spustí disk přes PS2LOGO a upraví ho tak, aby vždy použil region disku a přeskočil kontrolu kontrolního součtu loga.
- DECKARD IE 75K a novější: XPARAM.IRX se při spouštění bez loga použije automaticky, když je potřeba.

<a id="ps1-disc-arguments-per-launch"></a>

#### Argumenty disků PS1 (pro každé spuštění)
Platí pro každou spouštěcí položku `cdrom`, ne globálně.
- `-ps1fast` zapne rychlou rychlost disku PS1.
- `-ps1smooth` zapne vyhlazování textur.
- `-ps1vneg` spustí PS1DRV přes PS1VModeNegator. Užitečné tam, kde se režim konzole a režim disku liší (například některé případy MechaPwn/modčipů).

<a id="app-arguments"></a>

### Argumenty aplikací
Řádky `ARG_<BUTTON>_E? =` předávají argumenty do ELF (viz příklady INI).
- Nejdřív zadejte argumenty spouštěného elf a pak připojte požadované interní argumenty PS2BBL (viz níže). [NHDDL](https://github.com/pcm720/nhddl) je skvělý kandidát na argumenty, protože zrychlují jeho start.
- `-titleid=SLUS_123.45` přepíše ID titulu aplikace (až 11 znaků).
- `-appid` vynutí vizuální ID hry aplikace i při `APP_GAMEID = 0`.
- `-disc_stop` zastaví disk po načtení cílového ELF (užitečné pro položku bez sestavení `DISC_STOP_AT_BOOT`).
- `-gsm=<v[:c]>` spustí cílový ELF přes vestavěný eGSM (u cest `rom?:` se ignoruje). Pokud se použije, musí být posledním argumentem.
- `-disc_stop` se u spouštěcích položek `cdrom` ignoruje.
- `-dev9=<mode>` nastaví zásadu DEV9/HDD před spuštěním cílového ELF. Podporované režimy:
  - `NICHDD` nechá zapnuté DEV9 (síťový adaptér) i HDD.
  - `NIC` nechá zapnuté DEV9/síť, odpojí `pfs0:` a hned uspí `hdd0:`/`hdd1:`.
  - když se vynechá, PS2BBL nevynucuje žádnou zásadu DEV9.
  - poznámka: u sestavení bez HDD nemá tato volba žádný účinek.
- `-patinfo` zapne zpracování PATINFO pro položky `:PATINFO`.
  - PS2BBL čte `SYSTEM.CNF` z oblasti atributů oddílu (`PS2ICON3D`) a použije `BOOT2/BOOT/path`, `arg*`, `skip_argv0` a `HDDUNITPOWER`.
  - při `BOOT2/BOOT/path=PATINFO` PS2BBL načte vestavěný ELF z oblasti atributů oddílu a použije interní předání `-la=E...`.
  - při `IOPRP=PATINFO` (nebo vlastní cestě) ho PS2BBL předá fázi 2 interním předáním `-la=I...`.
  - je-li přítomno `-patinfo`, první zbývající argument přepíše cíl `BOOT2/BOOT/path` z CNF.
  To platí pro sestavení HDD.  
  Příklad PATINFO:  
    ```
    NAME_R1 = My App via PATINFO
    LK_R1_E1 = hdd0:+OSDMENU:PATINFO
    ARG_R1_E1 = pfs:/APPS/MYAPP.ELF
    ARG_R1_E1 = -patinfo               # Tells PS2BBL to use first arg as patinfo boot path.
    ```

Příklad spuštění NHDDL v režimu videa 480p s hledáním ISO na mmce a HDD s exFAT bez potřeby nhddl.yaml. Výhodou je, že se neztrácí čas načítáním ovladačů a hledáním a načítáním nhddl.yaml. Je to nejrychlejší způsob, jak spustit NHDDL a ukázat seznam ISO.
```
NAME_R1 = NHDDL
LK_R1_E1 = mmce?:/NEUTRINO/nhddl.elf
ARG_R1_E1 = -video=480p
ARG_R1_E1 = -mode=mmce
ARG_R1_E1 = -mode=ata
```

<a id="argument-precedence-and-order"></a>

#### Přednost a pořadí argumentů
1. PS2BBL zpracuje a spotřebuje jen koncové řídicí argumenty zavaděče z `ARG_*`: `-appid`, `-titleid=`, `-dev9=`, `-patinfo`, `-disc_stop`, `-gsm=`.
2. Zpracování jde zdola nahoru a zastaví se u prvního argumentu, který není řídicí (koncové chování jako v OSDMenu).
4. U spouštěcích cest `:PATINFO` PS2BBL zpracuje `SYSTEM.CNF` z atributu oddílu a připojí položky `arg*` z CNF za argumenty aplikace uživatele.
5. Je-li nastaveno `-patinfo` a spouštěcí cesta obsahuje `:PATINFO`, první zbývající argument aplikace uživatele se stane cestou cílového ELF (přepíše spouštěcí cestu z CNF) a odebere se z argv aplikace. Pokud žádný argument nezbývá, spuštění se přeruší (stejně jako v OSDMenu) a `BOOT2/BOOT/path` z CNF se nepoužije.
6. Zbývající argumenty si zachovají pořadí a předají se spuštěné aplikaci.


### eGSM (external Graphics Synthesize Mode)
U disků PS2 se eGSM čte automaticky z `OSDGSM.CNF` (v INI není potřeba žádná cesta). Formát konfiguračního souboru najdete [zde](https://github.com/pcm720/OSDMenu/blob/main/patcher/README.md#osdgsmcnf).

- `-gsm=<v[:c]>` spustí cílový ELF přes vestavěný eGSM (u cest `rom?:` se ignoruje).
  - eGSM se použije na spuštěný cíl (ELF/disk), ne na samotný PS2BBL.
  Formát eGSM (jako v OSDMenu):
- `v` = režim videa:
- prázdné = nevynucovat (výchozí)
- `fp1` = vynutit progresivní zobrazení (240p/288p)
- `fp2` = vynutit progresivní zobrazení (480p/576p)
- `1080ix1` = vynutit 1080i, šířka/výška x1
- `1080ix2` = vynutit 1080i, šířka/výška x2
- `1080ix3` = vynutit 1080i, šířka/výška x3
- `c` = režim kompatibility:
- prázdné = žádný (výchozí)
- `1` = prohození půlsnímků typ 1
- `2` = prohození půlsnímků typ 2
- `3` = prohození půlsnímků typ 3

Příklady ARG pro eGSM:
- `-gsm=fp2`
- `-gsm=fp2:1`
- `-gsm=1080ix2`

Příklad použití:
```
LK_TRIANGLE_E1 = mc0:/APP_WLE-ISR/WLE-ISR.ELF
ARG_TRIANGLE_E1 = -gsm=1080ix2
```

<a id="deprecatedremoved"></a>

## Zastaralé/Odstraněné
- ~~`RUNKELF`~~ PS2BBLE teď spouští elf/kelf interně, aniž by uživatel musel definovat spouštěcí akci pro kelf.


<a id="known-bugsissues"></a>

## Známé chyby/problémy

to mi řekněte vy ;)

<a id="credits--thanks"></a>

## Poděkování

- Od saildot4k
  - @israpps za [PS2BBL](https://github.com/israpps/PlayStation2-Basic-BootLoader/)
  - @pcm720 za
    - gameID Retrogem, PS1 Video Negator, eGSM a kód PS2LOGO z [OSDMenu](https://github.com/pcm720/OSDMenu)
    - volby režimu videa z [NHDDL](https://github.com/pcm720/nhddl)
  - @sp193 za [PS1 Video Negator](https://github.com/ps2homebrew/PS1VModeNeg)
  - @nathanneurotic za 10 cest PS2BBLE, nápady a přemlouvání
  - [@Berion](https://www.psx-place.com/members/berion.1431/) za loga, pozadí a grafiku kláves

- Od [El Isra](https://israpps.github.io/) (vývojář PS2BBL): 
  - @SP193 za knihovny pro inicializaci OSD, které jsou základem tohoto projektu
  - @asmblur za povzbuzení k vytvoření tohoto monstra na nejnovějším SDK
  - @uyjulian a @fjtrujy za to, že mi vždycky pomáhají


<p align="center"><sub><a href="https://github.com/akilluminati47/RIPPS2">RIPPS2</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2/releases/latest/download/RIPPS2.elf">Stáhnout</a> &nbsp;&middot;&nbsp; <b>BIBLE</b> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2-themes">Motivy</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPCSX2">RIPPCSX2</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2-fonts">Písma</a> &nbsp;&middot;&nbsp; <a href="https://akilluminati47.github.io/RIPPS2/">Web</a> &nbsp;&middot;&nbsp; <a href="https://www.psx-place.com/threads/ripps2-a-ps2-front-end-in-one-elf-launch-disc-storage-memory-files.51316/">psx-place</a> &nbsp;&middot;&nbsp; <a href="https://discord.gg/Z7m9u5kby">Discord</a></sub></p>

