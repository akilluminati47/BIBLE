<!-- i18n: the language bar, made by ps2-pillars tools/readme-i18n -->
<p align="center">
  <a href="README.md">English</a> |
  <a href="README.es.md">Español</a> |
  <a href="README.pt-BR.md">Português (Brasil)</a> |
  <a href="README.pt.md">Português</a> |
  <a href="README.fr.md">Français</a> |
  <a href="README.de.md">Deutsch</a> |
  <a href="README.it.md">Italiano</a> |
  <b>Nederlands</b> |
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

<p align="center"><sub>Vertaling van de Engelse README; bij verschillen geldt het Engels. <a href="README.md">English</a></sub></p>

<p align="center"><sub><a href="https://github.com/akilluminati47/RIPPS2">RIPPS2</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2/releases/latest/download/RIPPS2.elf">Downloaden</a> &nbsp;&middot;&nbsp; <b>BIBLE</b> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2-themes">Thema's</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPCSX2">RIPPCSX2</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2-fonts">Lettertypen</a> &nbsp;&middot;&nbsp; <a href="https://akilluminati47.github.io/RIPPS2/">Website</a> &nbsp;&middot;&nbsp; <a href="https://www.psx-place.com/threads/ripps2-a-ps2-front-end-in-one-elf-launch-disc-storage-memory-files.51316/">psx-place</a> &nbsp;&middot;&nbsp; <a href="https://discord.gg/Z7m9u5kby">Discord</a></sub></p>

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
  <sub>Houd bij het opstarten L2 + R2 ingedrukt voor de pagina met starttoetsen, TRIANGLE + CROSS voor de pagina met de videomodus; een toets ingesteld op <code>$CREDITS</code> toont de credits.</sub>
</p>

BIBLE is de bootloader die RIPPS2 installeert: een fork van PS2BBL Extended van saildot4k.

**Wat deze fork verandert**

- Het startscherm: het PS2-logo midden op de lucht van RIPPS2, met de knoppen eronder en eventuele tekst erboven. `BIBLE_GLYPHS` 0 geen, 1 de actieknoppen (standaard), 2 alle zestien in twee rijen van acht. `BIBLE_INFO` 1 toont console-info, klok en aftelling (standaard uit). De lucht volgt je RIPPS2 Color Theme: zonder `BIBLE_COLOR` leest BIBLE de lucht die RIPPS2 met zijn instellingen opslaat, uit de map die zijn AUTO-regel start, of uit de map `RIPPS2` van een geheugenkaart als de AUTO-regel RIPPS2 op een SD2PSX, USB of de harde schijf is (`BIBLE_COLOR` in de configuratie wint). Dezelfde look in elke videomodus.
- `BIBLE_BACKGROUND`: `AUTO` (standaard: de lucht als de instellingen van RIPPS2 gevonden worden of `BIBLE_COLOR` is gezet, anders zwart in de eigen modus van de console, een gewone bootloader), `SKY` of `BLANK` (zwart). De overgang naar een programma is sowieso een paar seconden zwart, dus zwart oogt als één geheel ermee.
- Het opstartgeluid, klaargezet: Boot Sound On (fast) van RIPPS2 kan `boot.adp` naast de configuratie van BIBLE bewaren (`mc?:/SYS-CONF/boot.adp`). Het wordt gelezen voordat een station start. BIBLE kan het ook in het RAM aan RIPPS2 doorgeven, maar dat is alleen in het lab geslaagd: op een echte SD2PSX las RIPPS2 de kopie op de kaart zelf. **Zonder geluid start het snelst.** De afspraak en de kant van RIPPS2: [docs/boot-sound-handoff.md](docs/boot-sound-handoff.md).
- RIPPS2 eerst: het configuratiesjabloon (`release/SYS-CONF/PS2BBL.INI`) en de ingebouwde standaarden proberen `mc?:/RIPPS2/RIPPS2.ELF` en `mmce?:/APPS/RIPPS2.ELF` vóór OSDMenu en FMCB, en het sjabloon noemt de eigen sleutels van BIBLE met uitleg. De pagina's (videomodus, credits, startknoppen) faden in over het gedimde logo met de knoppen weggezet, zodat de startknoppen rustig te lezen zijn.
- Videomodi: `VIDEO_MODE` accepteert ook `576P`, `720P` en `1080I`, de rest van die van RIPPS2. `AUTO` (standaard)
  start in de Video Mode van RIPPS2 als zijn instellingen naast het AUTO-item staan, anders in die van de console.
- `BIBLE_WIDESCREEN`: `AUTO` (standaard: de Widescreen van RIPPS2, anders de 16:9-scherminstelling van de PS2), `ON` of
  `OFF`. In 480i, 576i, 480p en 576p wordt het opstartscherm getekend voor een tv die het beeld naar 16:9 uitrekt, zonder
  platdrukken. 720p en 1080i zijn al 16:9.
- De overgang naar RIPPS2: bij het starten faden het logo en de knoppen weg en blijft de lucht staan tot de console het volgende programma laadt, waardoor het beeld zwart wordt (ongeveer 7 s in het lab met RIPPS2 op een geheugenkaart). Daarna verschijnt RIPPS2 in dezelfde videomodus en kleuren. Houd bij het opstarten TRIANGLE + CROSS ingedrukt voor de pagina met de videomodus, die altijd opent in
  de eigen interlaced-modus van de console (de weg terug uit 720p of 1080i op een composietkabel).
- Nieuw: de pagina met startknoppen. Houd L2 + R2 vast bij het aanzetten en BIBLE pauzeert voordat er iets start, met de huidige startpaden van elke knop, wat je startscherm-instellingen ook zijn (handig met `LOGO_DISPLAY = 0`, waar verder niets verschijnt).
- Combinaties die vanaf het aanzetten worden vastgehouden openen nu hun pagina's (TRIANGLE + CROSS werd gemist terwijl de controllers nog
  opstartten).
- `KEY_READ_WAIT_TIME = 0` is toegestaan (het minimum van upstream is 500 ms).
- PS2-builds voor memory card / USB, MMCE, MX4SIO en HDD. eGSM fase 2 is weggelaten.

**Hoe RIPPS2 het gebruikt**

RIPPS2 draagt BIBLE in RIPPS2.elf, elke build ondertekend door akilluminati47, en installeert of werkt het bij via Instellingen > Algemeen > Boot Loader > Manage, waar ook de sleutels van BIBLE worden gezet: Background, Splash, Button Glyphs, Info Line, Power-on Wait, Video Mode en Widescreen. De ondertekende builds en een kant-en-klare SD2PSX BOOT-kaart staan op [de releasepagina](https://github.com/akilluminati47/BIBLE/releases/latest). BIBLE draait ook als ELF die door een andere loader wordt gestart (FMCB, OSDMenu, de loader van een SD2PSX).

<p align="center"><img src="assets/readme/ripps2-icon.png" alt="RIPPS2" width="48" height="48"><br><sub>BIBLE is onderdeel van <a href="https://github.com/akilluminati47/RIPPS2">RIPPS2</a>.</sub></p>

---

<p align="center"><sub>Alles hieronder is de originele README van PS2BBL Extended, vertaald en verder ongewijzigd.</sub></p>

---


<br />
<p align="center">
  <a href="https://israpps.github.io/PlayStation2-Basic-BootLoader/">
    <img src="https://github.com/saildot4k/PlayStation2-Basic-BootLoader-Extended/blob/main/assets/ps2bbl_example.png" alt="Logo" width="50%" height="auto">
  </a>

  <p align="center">
    Een flexibele bootloader voor PlayStation 2™ en PSX-DESR
    <br />
  </p>
</p>  


Dit is een fork van PS2BBL door [El Isra](https://github.com/israpps/PlayStation2-Basic-BootLoader/)


<a id="documentation"></a>

## Documentatie

Die staat op [github pages](https://israpps.github.io/PlayStation2-Basic-BootLoader/), maar met de toevoegingen hieronder:

<a id="config-and-arguments"></a>

## Configuratie en argumenten

Bewerk het configuratiebestand naar behoefte. Voor het bewerken wordt [R3Configurator](https://github.com/saildot4k/R3CONFIGURATOR) aanbevolen. De paden zijn al ingesteld op de downloads van de [PS2 Homebrew Store](https://ps2homebrewstore.com). Je hoeft dus alleen je Auto-keuze aan te passen en het liefst de argumenten voor NHDDL in te stellen voor het apparaat waar je ISO's vanaf laadt.

<a id="config-path-search-order"></a>

### Zoekvolgorde van de configuratie

Het zoeken naar de configuratie houdt nu rekening met de opstartfamilie, zodat bij het starten geen onnodige drivers worden geladen:

1. `CONFIG.INI` (CWD: huidige werkmap)
2. Bij laden vanaf een apparaat:
   - MMCE-boot: `mmce?:/PS2BBL/CONFIG.INI`
   - MX4SIO-boot: `mx4sio:/PS2BBL/CONFIG.INI`
   - APA HDD-boot: `hdd0:__sysconf:pfs:/PS2BBL/CONFIG.INI`
   - BDM-boot: `usb:/PS2BBL/CONFIG.INI` / `mass:/PS2BBL/CONFIG.INI` / `ata:/PS2BBL/CONFIG.INI`
3. Terugval op de memory card:
   - Op de PS2: `mc?:/SYS-CONF/PS2BBL.INI`
   - Op de PSX-DESR: `mc?:/SYS-CONF/PSXBBL.INI`
4. Laatste terugval op de PSX
   - `xfrom:/PS2BBL/CONFIG.INI`
5. Als gecompileerd met `DISC_STOP_AT_BOOT=1
   - `cdrom0:/PS2BBL/CONFIG.INI`
   - Terugval op de memory card zoals in punt 3 hierboven.

<a id="device-path-prefixes"></a>

### Padvoorvoegsels van apparaten
PS2BBL ondersteunt deze voorvoegsels voor start- en configuratiepaden:
- `mc0:/`, `mc1:/`, `mc?:/`
- `usb:/` (voorkeur) en `mass:/` (oud)

<a id="build-specific"></a>

#### Per build:  
- `mmce0:/`, `mmce1:/`, `mmce?:/` __MMCE-builds__
- `mx4sio:/` (voorkeur) en `massX:/` (oud)  __MX4SIO-builds__
- `hdd0:partition:pfs:/<path to elf>` __HDD-builds__
- `xfrom:/`-paden __PSX DESR-builds__
- `ata:/` BDM-apparaat voor exFAT-HDD
- `ilink:/` (BDM-massaopslagroots) __nog niet geïmplementeerd__
- `DISC_STOP_AT_BOOT=1` buildprofiel dat de optische schijf na het laden van de configuratie altijd stopt

### LOGO_DISPLAY
Gebruik `LOGO_DISPLAY = 3` om de namen van de toetsen te tonen. De namen worden bepaald door `NAME_<BUTTON>`.
  - `0` Geen logo of console-info
  - `1` Console-info
  - `2` PS2BBLE/PSXBBLE-logo en console-info
  - `3` Toetsengrafiek met `NAME_BUTTON = <TITLE>` uit het configuratiebestand
    - Voorbeeld:
      ```
      NAME_SQUARE = POPSLOADER
      ```

<a id="custom-splash-logo-from-cwd"></a>

#### Eigen opstartlogo uit de CWD
Als er een eigen logobestand (LOGO.BIN) in de CWD (huidige werkmap) staat, vervangt het het ingebouwde PS2BBLE/PSXBBLE-logo.

Zet een PNG om naar het verwachte ruwe bestand:
  - De PNG moet RGBA 8 bit geïndexeerd zijn, 255 kleuren per kanaal en 256x64 groot.

  - Releasepakket (het script staat in de root van de release):
  ```bash
  python png_to_logo_rbga.py my_logo.png
  ```

  - Zet de gemaakte `LOGO.BIN` naast PS2BBL Extended. Dat zou `mc?:/BOOT/` moeten zijn als je downloads van de [PS2 Homebrew Store](https://ps2store.com) gebruikt

<a id="retrogem-visual-game-id"></a>

### Visuele game-ID van Retrogem
- `APP_GAMEID = 1` zet de visuele game-ID aan voor apps/homebrew, tot 11 tekens uit de bestandsnaam of de PS1/2-schijf
- `CDROM_DISABLE_GAMEID = 1` zet de visuele game-ID uit voor schijven die via `cdrom` worden gestart.

<a id="disc-spin-control"></a>

### Draaien van de schijf regelen
- Globale sleutel/waarde: `DISC_STOP = 0/1`
- `DISC_STOP = 1` stopt de optische schijf na het laden van de configuratie als er een configuratiebestand is gevonden.
- `DISC_STOP = 0` (of weggelaten) houdt het standaardgedrag.
- `-disc_stop` kan per startitem worden toegevoegd om de schijf te stoppen zodra de doel-ELF is gevonden.

<a id="video-mode"></a>

### Videomodus
- `VIDEO_MODE = AUTO, NTSC, PAL, 480P` Gebruikt de standaard van de PS2 of forceert een van de andere 3 modi.

<a id="emergency-video-mode-selector"></a>

#### Noodkiezer voor de videomodus
- Open met `TRIANGLE + CROSS` tijdens het opstarten
- De kiezer forceert `LOGO_DISPLAY = 3` zolang hij actief is, zodat je logo en toetsen in beeld hebt.
- Bediening:
  - `LEFT/RIGHT` wisselen de modi: `AUTO`, `NTSC`, `PAL`, `480P`
  - `SELECT` slaat de gekozen modus op in het actieve configuratiebestand
  - `START` verlaat de kiezer en gaat door naar de toetsenweergave

<a id="cdrom-launch-args"></a>

### Startargumenten voor CDROM
Voor `LK_*_E* = cdrom` zijn de ondersteunde argumenten:
- `-nologo`
- `-nogameid`
- `-ps1fast`
- `-ps1smooth`
- `-ps1vneg`
- `-gsm=<v[:c]>`

<a id="ps2logo-arguments-ps2-discs-only"></a>

#### PS2LOGO-argumenten (alleen PS2-schijven)
- Gebruik `cdrom` als pad van het startitem.
- Voeg `-nologo` toe aan de argumenten van het item om PS2-schijven direct te starten (zonder `rom0:PS2LOGO`).
- Zonder `-nologo` start PS2BBL de schijf via PS2LOGO en past het zo aan dat altijd de regio van de schijf wordt gebruikt en de checksumcontrole van het logo wordt overgeslagen.
- DECKARD IE 75K en later: XPARAM.IRX wordt bij starts zonder logo automatisch toegepast als dat nodig is.

<a id="ps1-disc-arguments-per-launch"></a>

#### Argumenten voor PS1-schijven (per start)
Deze gelden per `cdrom`-startitem, niet globaal.
- `-ps1fast` zet de snelle schijfsnelheid van de PS1 aan.
- `-ps1smooth` zet het gladstrijken van texturen aan.
- `-ps1vneg` start PS1DRV via PS1VModeNegator. Handig bij opstellingen waar de modus van de console en die van de schijf verschillen (bijvoorbeeld sommige MechaPwn/modchip-gevallen).

<a id="app-arguments"></a>

### App-argumenten
Gebruik regels `ARG_<BUTTON>_E? =` om argumenten aan een ELF door te geven (zie de INI-voorbeelden).
- Zet eerst de argumenten van de gestarte elf en voeg daarna de gewenste interne PS2BBL-argumenten toe (zie hieronder). [NHDDL](https://github.com/pcm720/nhddl) is een prima kandidaat voor argumenten, omdat ze het opstarten van NHDDL versnellen.
- `-titleid=SLUS_123.45` overschrijft de titel-ID van de app (tot 11 tekens).
- `-appid` forceert de visuele game-ID van de app, ook bij `APP_GAMEID = 0`.
- `-disc_stop` stopt de schijf nadat de doel-ELF is geladen (per item handig zonder `DISC_STOP_AT_BOOT`-builds).
- `-gsm=<v[:c]>` start de doel-ELF via de ingebouwde eGSM (genegeerd voor `rom?:`-paden). Als het wordt gebruikt, moet het het laatste argument zijn.
- `-disc_stop` wordt genegeerd voor `cdrom`-startitems.
- `-dev9=<mode>` stelt het DEV9/HDD-beleid in voordat de doel-ELF start. Ondersteunde modi:
  - `NICHDD` houdt zowel DEV9 (netwerkadapter) als de HDD aan.
  - `NIC` houdt DEV9/netwerk aan, ontkoppelt `pfs0:` en zet `hdd0:`/`hdd1:` direct in rust.
  - als het is weggelaten, forceert PS2BBL geen DEV9-beleid.
  - let op: bij builds zonder HDD heeft deze optie geen effect.
- `-patinfo` zet de afhandeling van PATINFO aan voor `:PATINFO`-items.
  - PS2BBL leest `SYSTEM.CNF` uit het attribuutgebied van de partitie (`PS2ICON3D`) en past `BOOT2/BOOT/path`, `arg*`, `skip_argv0` en `HDDUNITPOWER` toe.
  - bij `BOOT2/BOOT/path=PATINFO` laadt PS2BBL de ingebouwde ELF uit het attribuutgebied van de partitie en gebruikt het de interne overdracht `-la=E...`.
  - bij `IOPRP=PATINFO` (of een eigen pad) geeft PS2BBL het via de interne overdracht `-la=I...` door aan fase 2.
  - als `-patinfo` aanwezig is, overschrijft het eerste overgebleven argument het doel `BOOT2/BOOT/path` van de CNF.
  Dit is voor HDD-builds.  
  PATINFO-voorbeeld:  
    ```
    NAME_R1 = My App via PATINFO
    LK_R1_E1 = hdd0:+OSDMENU:PATINFO
    ARG_R1_E1 = pfs:/APPS/MYAPP.ELF
    ARG_R1_E1 = -patinfo               # Tells PS2BBL to use first arg as patinfo boot path.
    ```

Voorbeeld om NHDDL in videomodus 480p te starten en zonder nhddl.yaml naar ISO's op mmce en een exFAT-HDD te zoeken. Het voordeel: geen tijd verloren aan het laden van drivers en het zoeken en laden van nhddl.yaml. Zo start NHDDL het snelst en toont het de ISO-lijst.
```
NAME_R1 = NHDDL
LK_R1_E1 = mmce?:/NEUTRINO/nhddl.elf
ARG_R1_E1 = -video=480p
ARG_R1_E1 = -mode=mmce
ARG_R1_E1 = -mode=ata
```

<a id="argument-precedence-and-order"></a>

#### Voorrang en volgorde van argumenten
1. PS2BBL leest en verbruikt alleen de loader-stuurargumenten aan het eind van `ARG_*`: `-appid`, `-titleid=`, `-dev9=`, `-patinfo`, `-disc_stop`, `-gsm=`.
2. Er wordt van onder naar boven gelezen, en het stopt bij het eerste argument dat geen stuurargument is (eindgedrag zoals bij OSDMenu).
4. Voor `:PATINFO`-startpaden leest PS2BBL de `SYSTEM.CNF` van het partitieattribuut en voegt het de `arg*`-items van de CNF toe na de app-argumenten van de gebruiker.
5. Als `-patinfo` is ingesteld en het startpad `:PATINFO` bevat, wordt het eerste overgebleven app-argument van de gebruiker het pad van de doel-ELF (het overschrijft het opstartpad van de CNF) en wordt het uit de argv van de app gehaald. Blijft er geen argument over, dan wordt het starten afgebroken (net als bij OSDMenu) en wordt `BOOT2/BOOT/path` van de CNF niet gebruikt.
6. De overige argumenten houden hun volgorde en worden aan de gestarte app doorgegeven.


### eGSM (external Graphics Synthesize Mode)
Voor PS2-schijven wordt eGSM automatisch uit `OSDGSM.CNF` gelezen (geen pad in de INI nodig). Zie [hier](https://github.com/pcm720/OSDMenu/blob/main/patcher/README.md#osdgsmcnf) voor het formaat van het configuratiebestand.

- `-gsm=<v[:c]>` start de doel-ELF via de ingebouwde eGSM (genegeerd voor `rom?:`-paden).
  - eGSM wordt toegepast op het gestarte doel (ELF/schijf), niet op PS2BBL zelf.
  eGSM-formaat (zoals bij OSDMenu):
- `v` = videomodus:
- leeg = niets forceren (standaard)
- `fp1` = progressieve scan forceren (240p/288p)
- `fp2` = progressieve scan forceren (480p/576p)
- `1080ix1` = 1080i forceren, breedte/hoogte x1
- `1080ix2` = 1080i forceren, breedte/hoogte x2
- `1080ix3` = 1080i forceren, breedte/hoogte x3
- `c` = compatibiliteitsmodus:
- leeg = geen (standaard)
- `1` = veldomwisseling type 1
- `2` = veldomwisseling type 2
- `3` = veldomwisseling type 3

Voorbeelden van eGSM-ARG:
- `-gsm=fp2`
- `-gsm=fp2:1`
- `-gsm=1080ix2`

Gebruiksvoorbeeld:
```
LK_TRIANGLE_E1 = mc0:/APP_WLE-ISR/WLE-ISR.ELF
ARG_TRIANGLE_E1 = -gsm=1080ix2
```

<a id="deprecatedremoved"></a>

## Verouderd/Verwijderd
- ~~`RUNKELF`~~ PS2BBLE start elf/kelf nu intern, zonder dat de gebruiker een kelf-startactie hoeft te bepalen.


<a id="known-bugsissues"></a>

## Bekende bugs/problemen

vertel jij het mij maar ;)

<a id="credits--thanks"></a>

## Credits en dank

- Van saildot4k
  - @israpps voor [PS2BBL](https://github.com/israpps/PlayStation2-Basic-BootLoader/)
  - @pcm720 voor
    - Retrogem gameID, PS1 Video Negator, eGSM en de PS2LOGO-code uit [OSDMenu](https://github.com/pcm720/OSDMenu)
    - de videomodusopties uit [NHDDL](https://github.com/pcm720/nhddl)
  - @sp193 voor [PS1 Video Negator](https://github.com/ps2homebrew/PS1VModeNeg)
  - @nathanneurotic voor de 10 paden van PS2BBLE, ideeën en overtuigingskracht
  - [@Berion](https://www.psx-place.com/members/berion.1431/) voor logo's, achtergrond en toetsengraphics

- Van [El Isra](https://israpps.github.io/) (ontwikkelaar van PS2BBL): 
  - @SP193 voor de OSD-initialisatiebibliotheken, die de basis van dit project vormen
  - @asmblur, die me aanmoedigde om dit monster op de nieuwste SDK te maken
  - @uyjulian en @fjtrujy, die me altijd helpen


<p align="center"><sub><a href="https://github.com/akilluminati47/RIPPS2">RIPPS2</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2/releases/latest/download/RIPPS2.elf">Downloaden</a> &nbsp;&middot;&nbsp; <b>BIBLE</b> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2-themes">Thema's</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPCSX2">RIPPCSX2</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2-fonts">Lettertypen</a> &nbsp;&middot;&nbsp; <a href="https://akilluminati47.github.io/RIPPS2/">Website</a> &nbsp;&middot;&nbsp; <a href="https://www.psx-place.com/threads/ripps2-a-ps2-front-end-in-one-elf-launch-disc-storage-memory-files.51316/">psx-place</a> &nbsp;&middot;&nbsp; <a href="https://discord.gg/Z7m9u5kby">Discord</a></sub></p>

