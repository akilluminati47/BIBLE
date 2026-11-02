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
  <b>Svenska</b> |
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

<p align="center"><sub>Översättning av den engelska README; vid skillnader gäller den engelska. <a href="README.md">English</a></sub></p>

<p align="center"><sub><a href="https://github.com/akilluminati47/RIPPS2">RIPPS2</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2/releases/latest/download/RIPPS2.elf">Ladda ner</a> &nbsp;&middot;&nbsp; <b>BIBLE</b> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2-themes">Teman</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPCSX2">RIPPCSX2</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2-fonts">Typsnitt</a> &nbsp;&middot;&nbsp; <a href="https://akilluminati47.github.io/RIPPS2/">Webbplats</a> &nbsp;&middot;&nbsp; <a href="https://www.psx-place.com/threads/ripps2-a-ps2-front-end-in-one-elf-launch-disc-storage-memory-files.51316/">psx-place</a> &nbsp;&middot;&nbsp; <a href="https://discord.gg/Z7m9u5kby">Discord</a></sub></p>

<h1 align="center">BIBLE</h1>
<p align="center">
  <a href="https://github.com/akilluminati47/RIPPS2">RIPPS2</a> ·
  <a href="https://github.com/akilluminati47/BIBLE/actions">Byggen</a> ·
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
  <sub>Håll L2 + R2 vid start för sidan med starttangenter, TRIANGLE + CROSS för sidan med videoläge; en tangent satt till <code>$CREDITS</code> visar eftertexterna.</sub>
</p>

BIBLE är startladdaren som RIPPS2 sätter upp: en fork av saildot4ks PS2BBL Extended.

**Vad den här forken ändrar**

- Startskärmen: PS2-logon centrerad på RIPPS2:s himmel, med knapparna under och eventuell text ovanför.
  `BIBLE_GLYPHS` 0 inga, 1 frontknapparna (standard), 2 alla sexton i två rader om åtta.
  `BIBLE_INFO` 1 visar konsolinfo, klocka och nedräkning (av som standard).
  Himlen följer ditt RIPPS2 Color Theme: utan `BIBLE_COLOR` läser BIBLE den himmel RIPPS2 sparar med sina
  inställningar, från den RIPPS2-mapp som dess AUTO-post startar (`BIBLE_COLOR` i konfigurationen vinner).
  Samma utseende i varje videoläge. Sidor (videoläge, eftertexter, starttangenter) tonar in över den dämpade logon
  med knapparna undanplockade, så att starttangenterna går att läsa i lugn och ro.
- Videolägen: `VIDEO_MODE` tar också `576P`, `720P` och `1080I`, resten av RIPPS2:s. `AUTO` (standard)
  startar i RIPPS2:s Video Mode när dess inställningar finns bredvid AUTO-posten, annars i konsolens eget.
- `BIBLE_WIDESCREEN`: `AUTO` (standard: RIPPS2:s Widescreen, annars PS2:ans 16:9-skärminställning), `ON` eller
  `OFF`. I 480i, 576i, 480p och 576p ritas startskärmen för en tv som sträcker bilden till 16:9, utan
  hoptryckning. 720p och 1080i är redan 16:9.
- Inget hopp in i RIPPS2: vid start tonar logon och knapparna bort och himlen stannar kvar på skärmen, i RIPPS2:s läge;
  RIPPS2 startar på samma himmel. Håll TRIANGLE + CROSS vid start för sidan med videoläge, som alltid öppnas i
  konsolens eget interlaced-läge (vägen tillbaka från 720p eller 1080i på en kompositkabel).
- Nytt: sidan med starttangenter. Håll L2 + R2 vid start för att läsa varje tangents startsökväg, oavsett dina startskärmsinställningar.
- Kombinationer som hålls från påslag öppnar nu sina sidor (TRIANGLE + CROSS missades medan handkontrollerna fortfarande
  startade).
- `KEY_READ_WAIT_TIME = 0` är tillåtet (upstreams lägsta värde är 500 ms).
- PS2-byggen för minneskort / USB, MMCE, MX4SIO och HDD. eGSM steg 2 är utelämnat.

**Så använder RIPPS2 den**

RIPPS2 kommer att bära med sig BIBLE som signerade startfiler och installera den från sina Settings (Boot Loader), i stället för den PS2BBL 1.2.0 den bär i dag. BIBLE körs också som en ELF startad av en annan laddare (FMCB, OSDMenu, en SD2PSX-laddare). Det finns ännu ingen BIBLE-version.

<p align="center"><img src="assets/readme/ripps2-icon.png" alt="RIPPS2" width="48" height="48"><br><sub>BIBLE är en del av <a href="https://github.com/akilluminati47/RIPPS2">RIPPS2</a>.</sub></p>

---

<p align="center"><sub>Allt nedan är den ursprungliga README:n för PS2BBL Extended, översatt och annars oförändrad.</sub></p>

---


<br />
<p align="center">
  <a href="https://israpps.github.io/PlayStation2-Basic-BootLoader/">
    <img src="https://github.com/saildot4k/PlayStation2-Basic-BootLoader-Extended/blob/main/assets/ps2bbl_example.png" alt="Logo" width="50%" height="auto">
  </a>

  <p align="center">
    En flexibel startladdare för PlayStation 2™ och PSX-DESR
    <br />
  </p>
</p>  


Det här är en fork av PS2BBL av [El Isra](https://github.com/israpps/PlayStation2-Basic-BootLoader/)


## Dokumentation

Den finns på [github pages](https://israpps.github.io/PlayStation2-Basic-BootLoader/), men med tilläggen nedan:

## Konfiguration och argument

Redigera konfigurationsfilen efter behov. För att redigera den rekommenderas [R3Configurator](https://github.com/saildot4k/R3CONFIGURATOR). Sökvägarna är redan inställda för att stämma med nedladdningar från [PS2 Homebrew Store](https://ps2homebrewstore.com). Du ska alltså bara behöva redigera ditt Auto-val och helst ställa in argument för NHDDL efter enheten du läser in ISO-filer från.

### Sökordning för konfigurationen

Sökningen efter konfigurationen tar nu hänsyn till startfamiljen, så att inga onödiga drivrutiner läses in vid start:

1. `CONFIG.INI` (CWD: aktuell arbetsmapp)
2. Vid inläsning från en enhet:
   - MMCE-start: `mmce?:/PS2BBL/CONFIG.INI`
   - MX4SIO-start: `mx4sio:/PS2BBL/CONFIG.INI`
   - APA HDD-start: `hdd0:__sysconf:pfs:/PS2BBL/CONFIG.INI`
   - BDM-start: `usb:/PS2BBL/CONFIG.INI` / `mass:/PS2BBL/CONFIG.INI` / `ata:/PS2BBL/CONFIG.INI`
3. Reserv på minneskort:
   - På PS2: `mc?:/SYS-CONF/PS2BBL.INI`
   - På PSX-DESR: `mc?:/SYS-CONF/PSXBBL.INI`
4. Sista reserv på PSX
   - `xfrom:/PS2BBL/CONFIG.INI`
5. När den kompileras med `DISC_STOP_AT_BOOT=1
   - `cdrom0:/PS2BBL/CONFIG.INI`
   - Reserv på minneskort enligt punkt 3 ovan.

### Sökvägsprefix för enheter
PS2BBL stöder dessa prefix för start- och konfigurationssökvägar:
- `mc0:/`, `mc1:/`, `mc?:/`
- `usb:/` (föredras) och `mass:/` (äldre)

#### Beroende på bygge:  
- `mmce0:/`, `mmce1:/`, `mmce?:/` __MMCE-byggen__
- `mx4sio:/` (föredras) och `massX:/` (äldre)  __MX4SIO-byggen__
- `hdd0:partition:pfs:/<path to elf>` __HDD-byggen__
- `xfrom:/`-sökvägar __PSX DESR-byggen__
- `ata:/` BDM-enhet för exFAT-HDD
- `ilink:/` (BDM-masslagringsrötter) __inte implementerat än__
- `DISC_STOP_AT_BOOT=1` byggprofil som alltid stoppar den optiska skivan efter att konfigurationen lästs in

### LOGO_DISPLAY
Använd `LOGO_DISPLAY = 3` för att visa tangenternas namn. Namnen anges med `NAME_<BUTTON>`.
  - `0` Varken logo eller konsolinfo
  - `1` Konsolinfo
  - `2` PS2BBLE/PSXBBLE-logo och konsolinfo
  - `3` Tangentgrafik med `NAME_BUTTON = <TITLE>` från konfigurationsfilen
    - Exempel:
      ```
      NAME_SQUARE = POPSLOADER
      ```

#### Egen startlogo från CWD
Om en egen logofil (LOGO.BIN) finns i CWD (aktuell arbetsmapp) ersätter den den inbyggda PS2BBLE/PSXBBLE-logon.

Konvertera en PNG till den förväntade råfilen:
  - PNG-filen ska vara RGBA 8 bitar indexerad, 255 färger per kanal och 256x64 i upplösning.

  - Versionspaket (skriptet ligger i versionens rot):
  ```bash
  python png_to_logo_rbga.py my_logo.png
  ```

  - Lägg den skapade `LOGO.BIN` bredvid PS2BBL Extended. Det bör vara `mc?:/BOOT/` om du använder nedladdningar från [PS2 Homebrew Store](https://ps2store.com)

### Visuellt spel-ID från Retrogem
- `APP_GAMEID = 1` slår på visuellt spel-ID för appar/homebrew, upp till 11 tecken från filnamnet eller PS1/2-skivan
- `CDROM_DISABLE_GAMEID = 1` slår av visuellt spel-ID för skivor som startas via `cdrom`.

### Styrning av skivans rotation
- Global nyckel/värde: `DISC_STOP = 0/1`
- `DISC_STOP = 1` stoppar den optiska skivan efter att konfigurationen lästs in, när en konfigurationsfil hittades.
- `DISC_STOP = 0` (eller utelämnat) behåller standardbeteendet.
- `-disc_stop` kan läggas till per startpost för att stoppa skivan när mål-ELF:en hittats.

### Videoläge
- `VIDEO_MODE = AUTO, NTSC, PAL, 480P` Använder PS2:ans standard eller tvingar fram ett av de andra 3 lägena.

#### Nödväljare för videoläge
- Öppnas med `TRIANGLE + CROSS` under start
- Väljaren tvingar `LOGO_DISPLAY = 3` medan den är aktiv, så att du ser logon och tangenterna.
- Kontroller:
  - `LEFT/RIGHT` bläddrar mellan lägena: `AUTO`, `NTSC`, `PAL`, `480P`
  - `SELECT` sparar det valda läget i den aktiva konfigurationsfilen
  - `START` lämnar väljaren och fortsätter till tangentvisningen

### Startargument för CDROM
För `LK_*_E* = cdrom` stöds dessa argument:
- `-nologo`
- `-nogameid`
- `-ps1fast`
- `-ps1smooth`
- `-ps1vneg`
- `-gsm=<v[:c]>`

#### PS2LOGO-argument (endast PS2-skivor)
- Använd `cdrom` som startpostens sökväg.
- Lägg till `-nologo` i postens argument för att starta PS2-skivor direkt (utan `rom0:PS2LOGO`).
- Utan `-nologo` startar PS2BBL skivan via PS2LOGO och patchar den så att skivans region alltid används och logons kontrollsumma hoppas över.
- DECKARD IE 75K och senare: XPARAM.IRX tillämpas automatiskt vid behov för starter utan logo.

#### Argument för PS1-skivor (per start)
De gäller per `cdrom`-startpost, inte globalt.
- `-ps1fast` slår på snabb skivhastighet för PS1.
- `-ps1smooth` slår på texturutjämning.
- `-ps1vneg` kör PS1DRV via PS1VModeNegator. Användbart i uppsättningar där konsolens och skivans läge skiljer sig (till exempel vissa MechaPwn/modchip-fall).

### App-argument
Använd rader `ARG_<BUTTON>_E? =` för att skicka argument till en ELF (se INI-exemplen).
- Lägg först den startade elf:ens argument och lägg sedan till de interna PS2BBL-argument du vill ha (se nedan). [NHDDL](https://github.com/pcm720/nhddl) är en utmärkt kandidat för argument, eftersom de snabbar upp starten av NHDDL.
- `-titleid=SLUS_123.45` ersätter appens titel-ID (upp till 11 tecken).
- `-appid` tvingar appens visuella spel-ID även med `APP_GAMEID = 0`.
- `-disc_stop` stoppar skivan efter att mål-ELF:en lästs in (användbart per post utan `DISC_STOP_AT_BOOT`-byggen).
- `-gsm=<v[:c]>` kör mål-ELF:en via den inbyggda eGSM (ignoreras för `rom?:`-sökvägar). Om det används måste det vara sista argumentet.
- `-disc_stop` ignoreras för `cdrom`-startposter.
- `-dev9=<mode>` ställer in DEV9/HDD-policyn innan mål-ELF:en startas. Lägen som stöds:
  - `NICHDD` håller både DEV9 (nätverksadapter) och HDD påslagna.
  - `NIC` håller DEV9/nätverk på, avmonterar `pfs0:` och sätter `hdd0:`/`hdd1:` i viloläge direkt.
  - om det utelämnas tvingar PS2BBL ingen DEV9-policy.
  - obs: på byggen utan HDD har det här alternativet ingen effekt.
- `-patinfo` slår på hantering av PATINFO för `:PATINFO`-poster.
  - PS2BBL läser `SYSTEM.CNF` från partitionens attributområde (`PS2ICON3D`) och tillämpar `BOOT2/BOOT/path`, `arg*`, `skip_argv0` och `HDDUNITPOWER`.
  - vid `BOOT2/BOOT/path=PATINFO` läser PS2BBL in den inbyggda ELF:en från partitionens attributområde och använder den interna överlämningen `-la=E...`.
  - vid `IOPRP=PATINFO` (eller en egen sökväg) skickar PS2BBL den vidare till steg 2 via den interna överlämningen `-la=I...`.
  - om `-patinfo` finns ersätter det första återstående argumentet CNF-målet `BOOT2/BOOT/path`.
  Det här gäller HDD-byggen.  
  PATINFO-exempel:  
    ```
    NAME_R1 = My App via PATINFO
    LK_R1_E1 = hdd0:+OSDMENU:PATINFO
    ARG_R1_E1 = pfs:/APPS/MYAPP.ELF
    ARG_R1_E1 = -patinfo               # Tells PS2BBL to use first arg as patinfo boot path.
    ```

Exempel på att starta NHDDL i videoläge 480p och leta efter ISO-filer på mmce och en exFAT-HDD utan att behöva nhddl.yaml. Fördelen är att ingen tid går åt till att läsa in drivrutiner och hitta och läsa in nhddl.yaml. Det är det snabbaste sättet att starta NHDDL och visa ISO-listan.
```
NAME_R1 = NHDDL
LK_R1_E1 = mmce?:/NEUTRINO/nhddl.elf
ARG_R1_E1 = -video=480p
ARG_R1_E1 = -mode=mmce
ARG_R1_E1 = -mode=ata
```

#### Argumentens företräde och ordning
1. PS2BBL läser och förbrukar bara laddarens styrargument i slutet av `ARG_*`: `-appid`, `-titleid=`, `-dev9=`, `-patinfo`, `-disc_stop`, `-gsm=`.
2. Läsningen går nerifrån och upp och stannar vid första argumentet som inte är ett styrargument (slutbeteende som i OSDMenu).
4. För `:PATINFO`-startsökvägar läser PS2BBL partitionsattributets `SYSTEM.CNF` och lägger till CNF:ens `arg*`-poster efter användarens app-argument.
5. Om `-patinfo` är satt och startsökvägen innehåller `:PATINFO` blir användarens första återstående app-argument mål-ELF:ens sökväg (det ersätter CNF:ens startsökväg) och tas bort från appens argv. Finns inget argument kvar avbryts starten (som i OSDMenu) och CNF:ens `BOOT2/BOOT/path` används inte.
6. De återstående argumenten behåller sin ordning och skickas till den startade appen.


### eGSM (external Graphics Synthesize Mode)
För PS2-skivor läses eGSM automatiskt från `OSDGSM.CNF` (ingen sökväg i INI-filen behövs). Se [här](https://github.com/pcm720/OSDMenu/blob/main/patcher/README.md#osdgsmcnf) för konfigurationsfilens format.

- `-gsm=<v[:c]>` kör mål-ELF:en via den inbyggda eGSM (ignoreras för `rom?:`-sökvägar).
  - eGSM tillämpas på det startade målet (ELF/skiva), inte på PS2BBL självt.
  eGSM-format (som i OSDMenu):
- `v` = videoläge:
- tomt = tvinga inget (standard)
- `fp1` = tvinga progressiv avsökning (240p/288p)
- `fp2` = tvinga progressiv avsökning (480p/576p)
- `1080ix1` = tvinga 1080i, bredd/höjd x1
- `1080ix2` = tvinga 1080i, bredd/höjd x2
- `1080ix3` = tvinga 1080i, bredd/höjd x3
- `c` = kompatibilitetsläge:
- tomt = inget (standard)
- `1` = fältvändning typ 1
- `2` = fältvändning typ 2
- `3` = fältvändning typ 3

Exempel på eGSM-ARG:
- `-gsm=fp2`
- `-gsm=fp2:1`
- `-gsm=1080ix2`

Användningsexempel:
```
LK_TRIANGLE_E1 = mc0:/APP_WLE-ISR/WLE-ISR.ELF
ARG_TRIANGLE_E1 = -gsm=1080ix2
```

## Föråldrat/Borttaget
- ~~`RUNKELF`~~ PS2BBLE startar nu elf/kelf internt, utan att användaren behöver ange en kelf-startåtgärd.


## Kända buggar/problem

det får du berätta för mig ;)

## Tack och erkännanden

- Från saildot4k
  - @israpps för [PS2BBL](https://github.com/israpps/PlayStation2-Basic-BootLoader/)
  - @pcm720 för
    - Retrogem gameID, PS1 Video Negator, eGSM och PS2LOGO-koden från [OSDMenu](https://github.com/pcm720/OSDMenu)
    - videolägesalternativen från [NHDDL](https://github.com/pcm720/nhddl)
  - @sp193 för [PS1 Video Negator](https://github.com/ps2homebrew/PS1VModeNeg)
  - @nathanneurotic för PS2BBLE:s 10 sökvägar, idéer och övertalning
  - [@Berion](https://www.psx-place.com/members/berion.1431/) för logotyper, bakgrund och tangentgrafik

- Från [El Isra](https://israpps.github.io/) (utvecklare av PS2BBL): 
  - @SP193 för OSD-initieringsbiblioteken, som är grunden för det här projektet
  - @asmblur, för att ha uppmuntrat mig att göra det här monstret på senaste SDK
  - @uyjulian och @fjtrujy för att de alltid hjälper mig


<p align="center"><sub><a href="https://github.com/akilluminati47/RIPPS2">RIPPS2</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2/releases/latest/download/RIPPS2.elf">Ladda ner</a> &nbsp;&middot;&nbsp; <b>BIBLE</b> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2-themes">Teman</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPCSX2">RIPPCSX2</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2-fonts">Typsnitt</a> &nbsp;&middot;&nbsp; <a href="https://akilluminati47.github.io/RIPPS2/">Webbplats</a> &nbsp;&middot;&nbsp; <a href="https://www.psx-place.com/threads/ripps2-a-ps2-front-end-in-one-elf-launch-disc-storage-memory-files.51316/">psx-place</a> &nbsp;&middot;&nbsp; <a href="https://discord.gg/Z7m9u5kby">Discord</a></sub></p>

