<!-- i18n: the language bar, made by ps2-pillars tools/readme-i18n -->
<p align="center">
  <a href="README.md">English</a> |
  <a href="README.es.md">Español</a> |
  <a href="README.pt-BR.md">Português (Brasil)</a> |
  <a href="README.pt.md">Português</a> |
  <a href="README.fr.md">Français</a> |
  <b>Deutsch</b> |
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
  <a href="README.ceb.md">Cebuano</a>
</p>
<!-- /i18n -->

<p align="center"><sub>Übersetzung der englischen README; bei Abweichungen gilt das Englische. <a href="README.md">English</a></sub></p>

<p align="center"><sub><a href="https://github.com/akilluminati47/RIPPS2">RIPPS2</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2/releases/latest/download/RIPPS2.elf">Download</a> &nbsp;&middot;&nbsp; <b>BIBLE</b> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2-themes">Themes</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPCSX2">RIPPCSX2</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2-fonts">Schriften</a> &nbsp;&middot;&nbsp; <a href="https://akilluminati47.github.io/RIPPS2/">Website</a> &nbsp;&middot;&nbsp; <a href="https://www.psx-place.com/threads/ripps2-a-ps2-front-end-in-one-elf-launch-disc-storage-memory-files.51316/">psx-place</a> &nbsp;&middot;&nbsp; <a href="https://discord.gg/Z7m9u5kby">Discord</a></sub></p>

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
  <sub>Halte beim Start L2 + R2 für die Seite der Starttasten, TRIANGLE + CROSS für die Seite des Videomodus; eine auf <code>$CREDITS</code> gesetzte Taste zeigt die Credits.</sub>
</p>

BIBLE ist der Bootloader, den RIPPS2 einrichtet: ein Fork von saildot4ks PS2BBL Extended.

**Was dieser Fork ändert**

- Der Startbildschirm: das PS2-Logo mittig auf dem Himmel von RIPPS2, die Tasten darunter und jeder Text darüber.
  `BIBLE_GLYPHS` 0 keine, 1 die Fronttasten (Standard), 2 alle sechzehn in zwei Reihen zu acht.
  `BIBLE_INFO` 1 zeigt Konsoleninfos, Uhr und Countdown (standardmäßig aus).
  Der Himmel passt zu deinem RIPPS2 Color Theme: ohne `BIBLE_COLOR` liest BIBLE den Himmel, den RIPPS2 mit seinen
  Einstellungen speichert, aus dem RIPPS2-Ordner, den sein AUTO-Eintrag startet (`BIBLE_COLOR` in der Konfiguration hat Vorrang).
  Derselbe Look in jedem Videomodus. Seiten (Videomodus, Credits, Starttasten) blenden über dem abgedunkelten Logo ein,
  die Tasten weggeräumt, damit die Starttasten in Ruhe lesbar sind.
- Videomodi: `VIDEO_MODE` nimmt auch `576P`, `720P` und `1080I`, die übrigen von RIPPS2. `AUTO` (Standard)
  startet im Video Mode von RIPPS2, wenn dessen Einstellungen neben dem AUTO-Eintrag liegen, sonst in dem der Konsole.
- `BIBLE_WIDESCREEN`: `AUTO` (Standard: das Widescreen von RIPPS2, sonst die 16:9-Bildschirmeinstellung der PS2), `ON` oder
  `OFF`. In 480i, 576i, 480p und 576p wird der Startbildschirm für einen Fernseher gezeichnet, der das Bild auf 16:9 streckt, ohne
  Stauchung. 720p und 1080i sind bereits 16:9.
- Kein Sprung beim Wechsel zu RIPPS2: beim Start blenden Logo und Tasten aus, und der Himmel bleibt im Modus von RIPPS2 stehen;
  RIPPS2 startet auf genau diesem Himmel. Halte beim Start TRIANGLE + CROSS für die Seite des Videomodus, die sich immer im
  eigenen Interlaced-Modus der Konsole öffnet (der Weg zurück aus 720p oder 1080i an einem Composite-Kabel).
- Neu: die Seite der Starttasten. Halte beim Start L2 + R2, um den Startpfad jeder Taste zu lesen, egal wie dein Startbildschirm eingestellt ist.
- Ab dem Einschalten gehaltene Kombinationen öffnen jetzt ihre Seiten (TRIANGLE + CROSS ging verloren, solange die Controller noch
  hochfuhren).
- `KEY_READ_WAIT_TIME = 0` ist erlaubt (das Minimum von upstream liegt bei 500 ms).
- PS2-Builds für Memory Card / USB, MMCE, MX4SIO und HDD. eGSM Stufe 2 bleibt außen vor.

**Wie RIPPS2 es nutzt**

RIPPS2 wird BIBLE als signierte Boot-Dateien mitbringen und es über seine Settings (Boot Loader) installieren, anstelle des PS2BBL 1.2.0, das es heute mitbringt. BIBLE läuft auch als ELF, das von einem anderen Loader gestartet wird (FMCB, OSDMenu, der Loader eines SD2PSX). Es gibt noch kein BIBLE-Release.

<p align="center"><img src="assets/readme/ripps2-icon.png" alt="RIPPS2" width="48" height="48"><br><sub>BIBLE ist Teil von <a href="https://github.com/akilluminati47/RIPPS2">RIPPS2</a>.</sub></p>

---

<p align="center"><sub>Alles Folgende ist die Original-README von PS2BBL Extended, übersetzt und sonst unverändert.</sub></p>

---


<br />
<p align="center">
  <a href="https://israpps.github.io/PlayStation2-Basic-BootLoader/">
    <img src="https://github.com/saildot4k/PlayStation2-Basic-BootLoader-Extended/blob/main/assets/ps2bbl_example.png" alt="Logo" width="50%" height="auto">
  </a>

  <p align="center">
    Ein flexibler Bootloader für PlayStation 2™ und PSX-DESR
    <br />
  </p>
</p>  


Dies ist ein Fork von PS2BBL von [El Isra](https://github.com/israpps/PlayStation2-Basic-BootLoader/)


<a id="documentation"></a>

## Dokumentation

Sie liegt auf [github pages](https://israpps.github.io/PlayStation2-Basic-BootLoader/), aber mit den Ergänzungen unten:

<a id="config-and-arguments"></a>

## Konfiguration und Argumente

Bearbeite die Konfigurationsdatei nach Bedarf. Zum Bearbeiten wird [R3Configurator](https://github.com/saildot4k/R3CONFIGURATOR) empfohlen. Die Pfade sind bereits passend zu den Downloads aus dem [PS2 Homebrew Store](https://ps2homebrewstore.com) voreingestellt. Du solltest also nur deine Auto-Wahl anpassen und am besten die Argumente für NHDDL passend zu dem Gerät setzen, von dem du ISOs lädst.

<a id="config-path-search-order"></a>

### Suchreihenfolge der Konfiguration

Die Suche nach der Konfiguration berücksichtigt jetzt die Boot-Familie, damit beim Start keine unnötigen Treiber geladen werden:

1. `CONFIG.INI` (CWD: aktuelles Arbeitsverzeichnis)
2. Beim Laden von einem Gerät:
   - MMCE-Boot: `mmce?:/PS2BBL/CONFIG.INI`
   - MX4SIO-Boot: `mx4sio:/PS2BBL/CONFIG.INI`
   - APA-HDD-Boot: `hdd0:__sysconf:pfs:/PS2BBL/CONFIG.INI`
   - BDM-Boot: `usb:/PS2BBL/CONFIG.INI` / `mass:/PS2BBL/CONFIG.INI` / `ata:/PS2BBL/CONFIG.INI`
3. Rückfall auf die Memory Card:
   - Auf der PS2: `mc?:/SYS-CONF/PS2BBL.INI`
   - Auf der PSX-DESR: `mc?:/SYS-CONF/PSXBBL.INI`
4. Letzter Rückfall auf der PSX
   - `xfrom:/PS2BBL/CONFIG.INI`
5. Wenn mit `DISC_STOP_AT_BOOT=1 kompiliert
   - `cdrom0:/PS2BBL/CONFIG.INI`
   - Rückfall auf die Memory Card wie in Punkt 3 oben.

<a id="device-path-prefixes"></a>

### Pfadpräfixe der Geräte
PS2BBL unterstützt diese Präfixe für Start- und Konfigurationspfade:
- `mc0:/`, `mc1:/`, `mc?:/`
- `usb:/` (bevorzugt) und `mass:/` (alt)

<a id="build-specific"></a>

#### Je nach Build:  
- `mmce0:/`, `mmce1:/`, `mmce?:/` __MMCE-Builds__
- `mx4sio:/` (bevorzugt) und `massX:/` (alt)  __MX4SIO-Builds__
- `hdd0:partition:pfs:/<path to elf>` __HDD-Builds__
- `xfrom:/`-Pfade __PSX-DESR-Builds__
- `ata:/` BDM-Gerät für exFAT-HDD
- `ilink:/` (BDM-Massenspeicher-Wurzeln) __noch nicht umgesetzt__
- `DISC_STOP_AT_BOOT=1` Build-Profil, das die optische Disc nach dem Laden der Konfiguration immer stoppt

### LOGO_DISPLAY
Nutze `LOGO_DISPLAY = 3`, um die Tastennamen anzuzeigen. Die Namen werden mit `NAME_<BUTTON>` festgelegt.
  - `0` Kein Logo, keine Konsoleninfos
  - `1` Konsoleninfos
  - `2` PS2BBLE/PSXBBLE-Logo und Konsoleninfos
  - `3` Tastengrafik mit `NAME_BUTTON = <TITLE>` aus der Konfigurationsdatei
    - Beispiel:
      ```
      NAME_SQUARE = POPSLOADER
      ```

<a id="custom-splash-logo-from-cwd"></a>

#### Eigenes Startlogo aus dem CWD
Liegt eine eigene Logodatei (LOGO.BIN) im CWD (aktuelles Arbeitsverzeichnis), ersetzt sie das eingebaute PS2BBLE/PSXBBLE-Logo.

Wandle ein PNG in die erwartete Rohdatei um:
  - Das PNG sollte RGBA, 8 Bit indiziert, 255 Farben pro Kanal und 256x64 groß sein.

  - Release-Paket (das Skript liegt im Release-Stammordner):
  ```bash
  python png_to_logo_rbga.py my_logo.png
  ```

  - Lege die erzeugte `LOGO.BIN` neben PS2BBL Extended. Das sollte `mc?:/BOOT/` sein, wenn du Downloads aus dem [PS2 Homebrew Store](https://ps2store.com) nutzt

<a id="retrogem-visual-game-id"></a>

### Visuelle Spiel-ID von Retrogem
- `APP_GAMEID = 1` schaltet die visuelle Spiel-ID für Apps/Homebrew ein, bis zu 11 Zeichen aus dem Dateinamen oder der PS1/2-Disc
- `CDROM_DISABLE_GAMEID = 1` schaltet die visuelle Spiel-ID für über `cdrom` gestartete Discs aus.

<a id="disc-spin-control"></a>

### Steuerung der Disc-Drehung
- Globaler Schlüssel/Wert: `DISC_STOP = 0/1`
- `DISC_STOP = 1` stoppt die optische Disc nach dem Laden der Konfiguration, wenn eine Konfigurationsdatei gefunden wurde.
- `DISC_STOP = 0` (oder weggelassen) behält das Standardverhalten.
- `-disc_stop` kann pro Starteintrag gesetzt werden, um die Disc zu stoppen, sobald das Ziel-ELF gefunden ist.

<a id="video-mode"></a>

### Videomodus
- `VIDEO_MODE = AUTO, NTSC, PAL, 480P` Nutzt den Standard der PS2 oder erzwingt einen der anderen 3 Modi.

<a id="emergency-video-mode-selector"></a>

#### Notfall-Auswahl des Videomodus
- Aufruf mit `TRIANGLE + CROSS` während des Starts
- Die Auswahl erzwingt `LOGO_DISPLAY = 3`, solange sie aktiv ist, damit du Logo und Tasten im Blick hast.
- Steuerung:
  - `LEFT/RIGHT` wechseln die Modi: `AUTO`, `NTSC`, `PAL`, `480P`
  - `SELECT` speichert den gewählten Modus in der aktiven Konfigurationsdatei
  - `START` verlässt die Auswahl und geht weiter zur Tastenanzeige

<a id="cdrom-launch-args"></a>

### Startargumente für CDROM
Für `LK_*_E* = cdrom` werden diese Argumente unterstützt:
- `-nologo`
- `-nogameid`
- `-ps1fast`
- `-ps1smooth`
- `-ps1vneg`
- `-gsm=<v[:c]>`

<a id="ps2logo-arguments-ps2-discs-only"></a>

#### PS2LOGO-Argumente (nur PS2-Discs)
- Nutze `cdrom` als Pfad des Starteintrags.
- Füge `-nologo` zu den Argumenten des Eintrags hinzu, um PS2-Discs direkt zu starten (ohne `rom0:PS2LOGO`).
- Ohne `-nologo` startet PS2BBL die Disc über PS2LOGO und patcht es so, dass immer die Region der Disc genutzt und die Prüfsumme des Logos übergangen wird.
- DECKARD IE 75K und neuer: XPARAM.IRX wird bei Starts ohne Logo bei Bedarf automatisch angewandt.

<a id="ps1-disc-arguments-per-launch"></a>

#### Argumente für PS1-Discs (pro Start)
Sie gelten pro `cdrom`-Starteintrag, nicht global.
- `-ps1fast` schaltet die schnelle Disc-Geschwindigkeit der PS1 ein.
- `-ps1smooth` schaltet die Texturglättung ein.
- `-ps1vneg` startet PS1DRV über PS1VModeNegator. Nützlich, wenn Konsolenmodus und Disc-Modus abweichen (zum Beispiel bei manchen MechaPwn/Modchip-Fällen).

<a id="app-arguments"></a>

### App-Argumente
Nutze Zeilen `ARG_<BUTTON>_E? =`, um einem ELF Argumente zu übergeben (siehe INI-Beispiele).
- Setze zuerst die Argumente des gestarteten ELF und hänge danach die gewünschten internen PS2BBL-Argumente an (siehe unten). [NHDDL](https://github.com/pcm720/nhddl) eignet sich hervorragend für Argumente, da sie den Start von NHDDL beschleunigen.
- `-titleid=SLUS_123.45` überschreibt die Titel-ID der App (bis zu 11 Zeichen).
- `-appid` erzwingt die visuelle Spiel-ID der App, auch bei `APP_GAMEID = 0`.
- `-disc_stop` stoppt die Disc, nachdem das Ziel-ELF geladen ist (pro Eintrag nützlich ohne `DISC_STOP_AT_BOOT`-Builds).
- `-gsm=<v[:c]>` startet das Ziel-ELF über das eingebaute eGSM (bei `rom?:`-Pfaden ignoriert). Falls genutzt, muss es das letzte Argument sein.
- `-disc_stop` wird bei `cdrom`-Starteinträgen ignoriert.
- `-dev9=<mode>` legt vor dem Start des Ziel-ELF die DEV9/HDD-Richtlinie fest. Unterstützte Modi:
  - `NICHDD` hält DEV9 (Netzwerkadapter) und HDD beide eingeschaltet.
  - `NIC` hält DEV9/Netzwerk an, hängt `pfs0:` aus und versetzt `hdd0:`/`hdd1:` sofort in den Ruhezustand.
  - wenn weggelassen, erzwingt PS2BBL keine DEV9-Richtlinie.
  - Hinweis: bei Builds ohne HDD hat diese Option keine Wirkung.
- `-patinfo` schaltet die PATINFO-Behandlung für `:PATINFO`-Einträge ein.
  - PS2BBL liest `SYSTEM.CNF` aus dem Attributbereich der Partition (`PS2ICON3D`) und wendet `BOOT2/BOOT/path`, `arg*`, `skip_argv0` und `HDDUNITPOWER` an.
  - bei `BOOT2/BOOT/path=PATINFO` lädt PS2BBL das eingebettete ELF aus dem Attributbereich der Partition und nutzt die interne Übergabe `-la=E...`.
  - bei `IOPRP=PATINFO` (oder einem eigenen Pfad) reicht PS2BBL es über die interne Übergabe `-la=I...` an Stufe 2 weiter.
  - ist `-patinfo` gesetzt, überschreibt das erste verbleibende Argument das Ziel `BOOT2/BOOT/path` der CNF.
  Das gilt für HDD-Builds.  
  PATINFO-Beispiel:  
    ```
    NAME_R1 = My App via PATINFO
    LK_R1_E1 = hdd0:+OSDMENU:PATINFO
    ARG_R1_E1 = pfs:/APPS/MYAPP.ELF
    ARG_R1_E1 = -patinfo               # Tells PS2BBL to use first arg as patinfo boot path.
    ```

Beispiel, um NHDDL im Videomodus 480p zu starten und ohne nhddl.yaml nach ISOs auf mmce und einer exFAT-HDD zu suchen. Der Vorteil: keine Zeit verloren mit dem Laden von Treibern und dem Suchen und Laden von nhddl.yaml. So startet NHDDL am schnellsten und zeigt die ISO-Liste.
```
NAME_R1 = NHDDL
LK_R1_E1 = mmce?:/NEUTRINO/nhddl.elf
ARG_R1_E1 = -video=480p
ARG_R1_E1 = -mode=mmce
ARG_R1_E1 = -mode=ata
```

<a id="argument-precedence-and-order"></a>

#### Vorrang und Reihenfolge der Argumente
1. PS2BBL liest und verbraucht nur die Loader-Steuerargumente am Ende von `ARG_*`: `-appid`, `-titleid=`, `-dev9=`, `-patinfo`, `-disc_stop`, `-gsm=`.
2. Gelesen wird von unten nach oben, und es stoppt beim ersten Argument, das kein Steuerargument ist (Verhalten am Ende wie bei OSDMenu).
4. Bei `:PATINFO`-Startpfaden liest PS2BBL die `SYSTEM.CNF` des Partitionsattributs und hängt die `arg*`-Einträge der CNF hinter die App-Argumente des Nutzers.
5. Ist `-patinfo` gesetzt und enthält der Startpfad `:PATINFO`, wird das erste verbleibende App-Argument des Nutzers zum Pfad des Ziel-ELF (es überschreibt den Boot-Pfad der CNF) und aus dem argv der App entfernt. Bleibt kein Argument übrig, wird der Start abgebrochen (wie bei OSDMenu), und `BOOT2/BOOT/path` der CNF wird nicht genutzt.
6. Die übrigen Argumente behalten ihre Reihenfolge und werden an die gestartete App übergeben.


### eGSM (external Graphics Synthesize Mode)
Für PS2-Discs wird eGSM automatisch aus `OSDGSM.CNF` gelesen (kein Pfad in der INI nötig). Das Format der Konfigurationsdatei steht [hier](https://github.com/pcm720/OSDMenu/blob/main/patcher/README.md#osdgsmcnf).

- `-gsm=<v[:c]>` startet das Ziel-ELF über das eingebaute eGSM (bei `rom?:`-Pfaden ignoriert).
  - eGSM wird auf das gestartete Ziel (ELF/Disc) angewandt, nicht auf PS2BBL selbst.
  eGSM-Format (wie bei OSDMenu):
- `v` = Videomodus:
- leer = nichts erzwingen (Standard)
- `fp1` = progressive Abtastung erzwingen (240p/288p)
- `fp2` = progressive Abtastung erzwingen (480p/576p)
- `1080ix1` = 1080i erzwingen, Breite/Höhe x1
- `1080ix2` = 1080i erzwingen, Breite/Höhe x2
- `1080ix3` = 1080i erzwingen, Breite/Höhe x3
- `c` = Kompatibilitätsmodus:
- leer = keiner (Standard)
- `1` = Halbbildtausch Typ 1
- `2` = Halbbildtausch Typ 2
- `3` = Halbbildtausch Typ 3

eGSM-ARG-Beispiele:
- `-gsm=fp2`
- `-gsm=fp2:1`
- `-gsm=1080ix2`

Anwendungsbeispiel:
```
LK_TRIANGLE_E1 = mc0:/APP_WLE-ISR/WLE-ISR.ELF
ARG_TRIANGLE_E1 = -gsm=1080ix2
```

<a id="deprecatedremoved"></a>

## Veraltet/Entfernt
- ~~`RUNKELF`~~ PS2BBLE startet elf/kelf jetzt intern, ohne dass der Nutzer eine kelf-Startaktion festlegen muss.


<a id="known-bugsissues"></a>

## Bekannte Fehler/Probleme

sag du es mir ;)

<a id="credits--thanks"></a>

## Credits und Dank

- Von saildot4k
  - @israpps für [PS2BBL](https://github.com/israpps/PlayStation2-Basic-BootLoader/)
  - @pcm720 für
    - Retrogem gameID, PS1 Video Negator, eGSM und den PS2LOGO-Code aus [OSDMenu](https://github.com/pcm720/OSDMenu)
    - die Videomodus-Optionen aus [NHDDL](https://github.com/pcm720/nhddl)
  - @sp193 für [PS1 Video Negator](https://github.com/ps2homebrew/PS1VModeNeg)
  - @nathanneurotic für die 10 Pfade von PS2BBLE, Ideen und Überzeugungsarbeit
  - [@Berion](https://www.psx-place.com/members/berion.1431/) für Logos, Hintergrund und Tastengrafiken

- Von [El Isra](https://israpps.github.io/) (Entwickler von PS2BBL): 
  - @SP193 für die OSD-Initialisierungsbibliotheken, die die Grundlage dieses Projekts sind
  - @asmblur, der mich ermutigt hat, dieses Monster auf dem neuesten SDK zu bauen
  - @uyjulian und @fjtrujy, die mir immer helfen


<p align="center"><sub><a href="https://github.com/akilluminati47/RIPPS2">RIPPS2</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2/releases/latest/download/RIPPS2.elf">Download</a> &nbsp;&middot;&nbsp; <b>BIBLE</b> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2-themes">Themes</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPCSX2">RIPPCSX2</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2-fonts">Schriften</a> &nbsp;&middot;&nbsp; <a href="https://akilluminati47.github.io/RIPPS2/">Website</a> &nbsp;&middot;&nbsp; <a href="https://www.psx-place.com/threads/ripps2-a-ps2-front-end-in-one-elf-launch-disc-storage-memory-files.51316/">psx-place</a> &nbsp;&middot;&nbsp; <a href="https://discord.gg/Z7m9u5kby">Discord</a></sub></p>

