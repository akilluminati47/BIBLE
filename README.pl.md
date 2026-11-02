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
  <b>Polski</b> |
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

<p align="center"><sub>Tłumaczenie angielskiego README; w razie różnic obowiązuje wersja angielska. <a href="README.md">English</a></sub></p>

<p align="center"><sub><a href="https://github.com/akilluminati47/RIPPS2">RIPPS2</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2/releases/latest/download/RIPPS2.elf">Pobierz</a> &nbsp;&middot;&nbsp; <b>BIBLE</b> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2-themes">Motywy</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPCSX2">RIPPCSX2</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2-fonts">Czcionki</a> &nbsp;&middot;&nbsp; <a href="https://akilluminati47.github.io/RIPPS2/">Strona</a> &nbsp;&middot;&nbsp; <a href="https://www.psx-place.com/threads/ripps2-a-ps2-front-end-in-one-elf-launch-disc-storage-memory-files.51316/">psx-place</a> &nbsp;&middot;&nbsp; <a href="https://discord.gg/Z7m9u5kby">Discord</a></sub></p>

<h1 align="center">BIBLE</h1>
<p align="center">
  <a href="https://github.com/akilluminati47/RIPPS2">RIPPS2</a> ·
  <a href="https://github.com/akilluminati47/BIBLE/actions">Kompilacje</a> ·
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
  <sub>Przytrzymaj L2 + R2 przy starcie, aby otworzyć stronę klawiszy uruchamiania, TRIANGLE + CROSS dla strony trybu wideo; klawisz ustawiony na <code>$CREDITS</code> pokazuje twórców.</sub>
</p>

BIBLE to boot loader, który instaluje RIPPS2: fork PS2BBL Extended autorstwa saildot4k.

**Co zmienia ten fork**

- Ekran startowy: logo PS2 na środku nieba RIPPS2, z przyciskami pod nim i ewentualnym tekstem nad nim.
  `BIBLE_GLYPHS` 0 brak, 1 przyciski czołowe (domyślnie), 2 wszystkie szesnaście w dwóch rzędach po osiem.
  `BIBLE_INFO` 1 pokazuje informacje o konsoli, zegar i odliczanie (domyślnie wyłączone).
  Niebo pasuje do twojego Color Theme z RIPPS2: bez `BIBLE_COLOR` BIBLE czyta niebo, które RIPPS2 zapisuje ze swoimi
  ustawieniami, z folderu RIPPS2 uruchamianego przez jego wpis AUTO (`BIBLE_COLOR` w konfiguracji ma pierwszeństwo).
  Ten sam wygląd w każdym trybie wideo. Strony (tryb wideo, twórcy, klawisze uruchamiania) pojawiają się na przyciemnionym logo
  z odłożonymi przyciskami, więc klawisze uruchamiania czyta się spokojnie.
- Tryby wideo: `VIDEO_MODE` przyjmuje też `576P`, `720P` i `1080I`, pozostałe tryby RIPPS2. `AUTO` (domyślnie)
  startuje w Video Mode z RIPPS2, gdy jego ustawienia leżą obok wpisu AUTO, a w przeciwnym razie w trybie konsoli.
- `BIBLE_WIDESCREEN`: `AUTO` (domyślnie: Widescreen z RIPPS2, a w przeciwnym razie ustawienie ekranu 16:9 w PS2), `ON` lub
  `OFF`. W 480i, 576i, 480p i 576p ekran startowy jest rysowany dla telewizora, który rozciąga obraz do 16:9, bez
  spłaszczenia. 720p i 1080i są już w 16:9.
- Bez przeskoku przy wejściu do RIPPS2: przy uruchomieniu logo i przyciski znikają, a niebo zostaje na ekranie w trybie RIPPS2;
  RIPPS2 startuje na tym samym niebie. Przytrzymaj TRIANGLE + CROSS przy starcie dla strony trybu wideo, która zawsze otwiera się
  we własnym trybie z przeplotem konsoli (droga powrotna z 720p lub 1080i na kablu kompozytowym).
- Nowość: strona klawiszy uruchamiania. Przytrzymaj L2 + R2 przy starcie, aby odczytać ścieżkę każdego klawisza, niezależnie od ustawień ekranu startowego.
- Kombinacje trzymane od włączenia otwierają teraz swoje strony (TRIANGLE + CROSS umykało, gdy pady jeszcze
  się uruchamiały).
- `KEY_READ_WAIT_TIME = 0` jest dozwolone (minimum w upstream to 500 ms).
- Kompilacje PS2 na kartę pamięci / USB, MMCE, MX4SIO i HDD. Etap 2 eGSM jest pominięty.

**Jak RIPPS2 go używa**

RIPPS2 będzie zawierać BIBLE jako podpisane pliki rozruchowe i instalować go ze swoich Settings (Boot Loader), w miejsce PS2BBL 1.2.0, który zawiera dziś. BIBLE działa też jako ELF uruchamiany przez inny loader (FMCB, OSDMenu, loader SD2PSX). Nie ma jeszcze wydania BIBLE.

<p align="center"><img src="assets/readme/ripps2-icon.png" alt="RIPPS2" width="48" height="48"><br><sub>BIBLE jest częścią <a href="https://github.com/akilluminati47/RIPPS2">RIPPS2</a>.</sub></p>

---

<p align="center"><sub>Wszystko poniżej to oryginalne README PS2BBL Extended, przetłumaczone i poza tym niezmienione.</sub></p>

---


<br />
<p align="center">
  <a href="https://israpps.github.io/PlayStation2-Basic-BootLoader/">
    <img src="https://github.com/saildot4k/PlayStation2-Basic-BootLoader-Extended/blob/main/assets/ps2bbl_example.png" alt="Logo" width="50%" height="auto">
  </a>

  <p align="center">
    Elastyczny boot loader dla PlayStation 2™ i PSX-DESR
    <br />
  </p>
</p>  


To fork PS2BBL autorstwa [El Isra](https://github.com/israpps/PlayStation2-Basic-BootLoader/)


<a id="documentation"></a>

## Dokumentacja

Jest na [github pages](https://israpps.github.io/PlayStation2-Basic-BootLoader/), ale z dodatkami poniżej:

<a id="config-and-arguments"></a>

## Konfiguracja i argumenty

Edytuj plik konfiguracyjny według potrzeb. Do edycji polecany jest [R3Configurator](https://github.com/saildot4k/R3CONFIGURATOR). Ścieżki są już ustawione zgodnie z plikami pobranymi z [PS2 Homebrew Store](https://ps2homebrewstore.com). Powinno więc wystarczyć zmienić wybór Auto i najlepiej ustawić argumenty NHDDL dla urządzenia, z którego wczytujesz pliki ISO.

<a id="config-path-search-order"></a>

### Kolejność szukania konfiguracji

Szukanie konfiguracji uwzględnia teraz rodzinę rozruchu, aby nie wczytywać przy starcie zbędnych sterowników:

1. `CONFIG.INI` (CWD: bieżący katalog roboczy)
2. Przy wczytaniu z urządzenia:
   - Rozruch z MMCE: `mmce?:/PS2BBL/CONFIG.INI`
   - Rozruch z MX4SIO: `mx4sio:/PS2BBL/CONFIG.INI`
   - Rozruch z APA HDD: `hdd0:__sysconf:pfs:/PS2BBL/CONFIG.INI`
   - Rozruch z BDM: `usb:/PS2BBL/CONFIG.INI` / `mass:/PS2BBL/CONFIG.INI` / `ata:/PS2BBL/CONFIG.INI`
3. Zapas na karcie pamięci:
   - Na PS2: `mc?:/SYS-CONF/PS2BBL.INI`
   - Na PSX-DESR: `mc?:/SYS-CONF/PSXBBL.INI`
4. Ostatni zapas na PSX
   - `xfrom:/PS2BBL/CONFIG.INI`
5. Po kompilacji z `DISC_STOP_AT_BOOT=1
   - `cdrom0:/PS2BBL/CONFIG.INI`
   - Zapas na karcie pamięci jak w punkcie 3 powyżej.

<a id="device-path-prefixes"></a>

### Przedrostki ścieżek urządzeń
PS2BBL obsługuje te przedrostki ścieżek uruchamiania/konfiguracji:
- `mc0:/`, `mc1:/`, `mc?:/`
- `usb:/` (zalecany) i `mass:/` (stary)

<a id="build-specific"></a>

#### Zależnie od kompilacji:  
- `mmce0:/`, `mmce1:/`, `mmce?:/` __kompilacje MMCE__
- `mx4sio:/` (zalecany) i `massX:/` (stary)  __kompilacje MX4SIO__
- `hdd0:partition:pfs:/<path to elf>` __kompilacje HDD__
- Ścieżki `xfrom:/` __kompilacje PSX DESR__
- `ata:/` urządzenie BDM dla dysku HDD exFAT
- `ilink:/` (katalogi główne pamięci masowej BDM) __jeszcze niezaimplementowane__
- `DISC_STOP_AT_BOOT=1` profil kompilacji, który zawsze zatrzymuje dysk optyczny po wczytaniu konfiguracji

### LOGO_DISPLAY
Użyj `LOGO_DISPLAY = 3`, aby pokazywać nazwy klawiszy. Nazwy określa `NAME_<BUTTON>`.
  - `0` Bez logo i informacji o konsoli
  - `1` Informacje o konsoli
  - `2` Logo PS2BBLE/PSXBBLE i informacje o konsoli
  - `3` Grafika klawiszy z `NAME_BUTTON = <TITLE>` z pliku konfiguracyjnego
    - Przykład:
      ```
      NAME_SQUARE = POPSLOADER
      ```

<a id="custom-splash-logo-from-cwd"></a>

#### Własne logo startowe z CWD
Jeśli w CWD (bieżącym katalogu roboczym) znajduje się własny plik logo (LOGO.BIN), zastępuje on wbudowane logo PS2BBLE/PSXBBLE.

Przekonwertuj PNG na oczekiwany plik surowy:
  - PNG powinien być w RGBA, 8 bitów indeksowany, 255 kolorów na kanał i w rozdzielczości 256x64.

  - Paczka wydania (skrypt jest w katalogu głównym wydania):
  ```bash
  python png_to_logo_rbga.py my_logo.png
  ```

  - Umieść utworzony `LOGO.BIN` obok PS2BBL Extended. Powinno to być `mc?:/BOOT/`, jeśli używasz plików z [PS2 Homebrew Store](https://ps2store.com)

<a id="retrogem-visual-game-id"></a>

### Wizualny identyfikator gry Retrogem
- `APP_GAMEID = 1` włącza wizualny identyfikator gry dla aplikacji/homebrew, do 11 znaków z nazwy pliku lub dysku PS1/2
- `CDROM_DISABLE_GAMEID = 1` wyłącza wizualny identyfikator gry dla dysków uruchamianych przez `cdrom`.

<a id="disc-spin-control"></a>

### Sterowanie obrotami dysku
- Globalny klucz/wartość: `DISC_STOP = 0/1`
- `DISC_STOP = 1` zatrzymuje dysk optyczny po wczytaniu konfiguracji, gdy znaleziono plik konfiguracyjny.
- `DISC_STOP = 0` (lub pominięte) zachowuje domyślne działanie.
- `-disc_stop` można dodać do każdego wpisu, aby zatrzymać dysk po znalezieniu docelowego ELF.

<a id="video-mode"></a>

### Tryb wideo
- `VIDEO_MODE = AUTO, NTSC, PAL, 480P` Używa domyślnego trybu PS2 albo wymusza jeden z 3 pozostałych.

<a id="emergency-video-mode-selector"></a>

#### Awaryjny wybór trybu wideo
- Otwiera się przez `TRIANGLE + CROSS` podczas rozruchu
- Wybór wymusza `LOGO_DISPLAY = 3`, gdy jest aktywny, żeby było widać logo i klawisze.
- Sterowanie:
  - `LEFT/RIGHT` przełączają tryby: `AUTO`, `NTSC`, `PAL`, `480P`
  - `SELECT` zapisuje wybrany tryb w aktywnym pliku konfiguracyjnym
  - `START` zamyka wybór i przechodzi do ekranu klawiszy

<a id="cdrom-launch-args"></a>

### Argumenty uruchamiania CDROM
Dla `LK_*_E* = cdrom` obsługiwane argumenty to:
- `-nologo`
- `-nogameid`
- `-ps1fast`
- `-ps1smooth`
- `-ps1vneg`
- `-gsm=<v[:c]>`

<a id="ps2logo-arguments-ps2-discs-only"></a>

#### Argumenty PS2LOGO (tylko dyski PS2)
- Użyj `cdrom` jako ścieżki wpisu.
- Dodaj `-nologo` do argumentów wpisu, aby uruchamiać dyski PS2 bezpośrednio (z pominięciem `rom0:PS2LOGO`).
- Bez `-nologo` PS2BBL uruchamia dysk przez PS2LOGO i łata go tak, by zawsze używał regionu dysku i pomijał sprawdzanie sumy kontrolnej logo.
- DECKARD IE 75K i nowsze: XPARAM.IRX jest stosowany automatycznie, gdy jest potrzebny przy uruchamianiu bez logo.

<a id="ps1-disc-arguments-per-launch"></a>

#### Argumenty dysków PS1 (na uruchomienie)
Dotyczą każdego wpisu `cdrom`, a nie całości.
- `-ps1fast` włącza szybką prędkość dysku PS1.
- `-ps1smooth` włącza wygładzanie tekstur.
- `-ps1vneg` uruchamia PS1DRV przez PS1VModeNegator. Przydatne tam, gdzie tryb konsoli i tryb dysku się różnią (na przykład w niektórych przypadkach MechaPwn/modchipów).

<a id="app-arguments"></a>

### Argumenty aplikacji
Używaj linii `ARG_<BUTTON>_E? =`, aby przekazać argumenty do ELF (zobacz przykłady INI).
- Najpierw wpisz argumenty uruchamianego elf, a potem dopisz wybrane wewnętrzne argumenty PS2BBL (zobacz niżej). [NHDDL](https://github.com/pcm720/nhddl) świetnie nadaje się do argumentów, bo przyspieszają jego rozruch.
- `-titleid=SLUS_123.45` zastępuje identyfikator tytułu aplikacji (do 11 znaków).
- `-appid` wymusza wizualny identyfikator gry aplikacji nawet przy `APP_GAMEID = 0`.
- `-disc_stop` zatrzymuje dysk po wczytaniu docelowego ELF (przydatne dla wpisu bez kompilacji `DISC_STOP_AT_BOOT`).
- `-gsm=<v[:c]>` uruchamia docelowy ELF przez wbudowany eGSM (ignorowane dla ścieżek `rom?:`). Jeśli jest użyty, musi być ostatnim argumentem.
- `-disc_stop` jest ignorowany dla wpisów `cdrom`.
- `-dev9=<mode>` ustawia politykę DEV9/HDD przed uruchomieniem docelowego ELF. Obsługiwane tryby:
  - `NICHDD` utrzymuje włączone zarówno DEV9 (kartę sieciową), jak i HDD.
  - `NIC` utrzymuje włączone DEV9/sieć, odmontowuje `pfs0:` i od razu usypia `hdd0:`/`hdd1:`.
  - jeśli pominięte, PS2BBL nie wymusza żadnej polityki DEV9.
  - uwaga: w kompilacjach bez HDD ta opcja nic nie robi.
- `-patinfo` włącza obsługę PATINFO dla wpisów `:PATINFO`.
  - PS2BBL czyta `SYSTEM.CNF` z obszaru atrybutów partycji (`PS2ICON3D`) i stosuje `BOOT2/BOOT/path`, `arg*`, `skip_argv0` oraz `HDDUNITPOWER`.
  - przy `BOOT2/BOOT/path=PATINFO` PS2BBL wczytuje wbudowany ELF z obszaru atrybutów partycji i używa wewnętrznego przekazania `-la=E...`.
  - przy `IOPRP=PATINFO` (lub własnej ścieżce) PS2BBL przekazuje go do etapu 2 przez wewnętrzne przekazanie `-la=I...`.
  - jeśli jest `-patinfo`, pierwszy pozostały argument zastępuje cel `BOOT2/BOOT/path` z CNF.
  To dotyczy kompilacji HDD.  
  Przykład PATINFO:  
    ```
    NAME_R1 = My App via PATINFO
    LK_R1_E1 = hdd0:+OSDMENU:PATINFO
    ARG_R1_E1 = pfs:/APPS/MYAPP.ELF
    ARG_R1_E1 = -patinfo               # Tells PS2BBL to use first arg as patinfo boot path.
    ```

Przykład uruchomienia NHDDL w trybie wideo 480p i szukania plików ISO na mmce i dysku HDD exFAT bez potrzeby nhddl.yaml. Zaleta: brak straty czasu na wczytywanie sterowników oraz szukanie i wczytywanie nhddl.yaml. To najszybszy sposób, by uruchomić NHDDL i pokazać listę ISO.
```
NAME_R1 = NHDDL
LK_R1_E1 = mmce?:/NEUTRINO/nhddl.elf
ARG_R1_E1 = -video=480p
ARG_R1_E1 = -mode=mmce
ARG_R1_E1 = -mode=ata
```

<a id="argument-precedence-and-order"></a>

#### Pierwszeństwo i kolejność argumentów
1. PS2BBL analizuje i zużywa tylko końcowe argumenty sterujące loadera z `ARG_*`: `-appid`, `-titleid=`, `-dev9=`, `-patinfo`, `-disc_stop`, `-gsm=`.
2. Analiza idzie od dołu do góry i zatrzymuje się na pierwszym argumencie, który nie jest sterujący (zachowanie końcowe jak w OSDMenu).
4. Dla ścieżek `:PATINFO` PS2BBL analizuje `SYSTEM.CNF` z atrybutu partycji i dopisuje wpisy `arg*` z CNF po argumentach aplikacji użytkownika.
5. Jeśli ustawiono `-patinfo`, a ścieżka zawiera `:PATINFO`, pierwszy pozostały argument użytkownika staje się ścieżką docelowego ELF (zastępuje ścieżkę rozruchu z CNF) i jest usuwany z argv aplikacji. Jeśli nie zostaje żaden argument, uruchamianie jest przerywane (jak w OSDMenu), a `BOOT2/BOOT/path` z CNF nie jest używane.
6. Pozostałe argumenty zachowują kolejność i trafiają do uruchomionej aplikacji.


### eGSM (external Graphics Synthesize Mode)
Dla dysków PS2 eGSM jest czytany automatycznie z `OSDGSM.CNF` (bez ścieżki w INI). Format pliku konfiguracyjnego jest opisany [tutaj](https://github.com/pcm720/OSDMenu/blob/main/patcher/README.md#osdgsmcnf).

- `-gsm=<v[:c]>` uruchamia docelowy ELF przez wbudowany eGSM (ignorowane dla ścieżek `rom?:`).
  - eGSM dotyczy uruchomionego celu (ELF/dysku), a nie samego PS2BBL.
  Format eGSM (w stylu OSDMenu):
- `v` = tryb wideo:
- puste = bez wymuszania (domyślnie)
- `fp1` = wymuś skanowanie progresywne (240p/288p)
- `fp2` = wymuś skanowanie progresywne (480p/576p)
- `1080ix1` = wymuś 1080i, szerokość/wysokość x1
- `1080ix2` = wymuś 1080i, szerokość/wysokość x2
- `1080ix3` = wymuś 1080i, szerokość/wysokość x3
- `c` = tryb zgodności:
- puste = brak (domyślnie)
- `1` = zamiana pól typ 1
- `2` = zamiana pól typ 2
- `3` = zamiana pól typ 3

Przykłady ARG eGSM:
- `-gsm=fp2`
- `-gsm=fp2:1`
- `-gsm=1080ix2`

Przykład użycia:
```
LK_TRIANGLE_E1 = mc0:/APP_WLE-ISR/WLE-ISR.ELF
ARG_TRIANGLE_E1 = -gsm=1080ix2
```

<a id="deprecatedremoved"></a>

## Przestarzałe/Usunięte
- ~~`RUNKELF`~~ PS2BBLE uruchamia teraz elf/kelf wewnętrznie, bez potrzeby definiowania przez użytkownika akcji uruchamiania kelf.


<a id="known-bugsissues"></a>

## Znane błędy/problemy

ty mi powiedz ;)

<a id="credits--thanks"></a>

## Twórcy i podziękowania

- Od saildot4k
  - @israpps za [PS2BBL](https://github.com/israpps/PlayStation2-Basic-BootLoader/)
  - @pcm720 za
    - gameID Retrogem, PS1 Video Negator, eGSM i kod PS2LOGO z [OSDMenu](https://github.com/pcm720/OSDMenu)
    - opcje trybu wideo z [NHDDL](https://github.com/pcm720/nhddl)
  - @sp193 za [PS1 Video Negator](https://github.com/ps2homebrew/PS1VModeNeg)
  - @nathanneurotic za 10 ścieżek PS2BBLE, pomysły i namowy
  - [@Berion](https://www.psx-place.com/members/berion.1431/) za loga, tło i grafiki klawiszy

- Od [El Isra](https://israpps.github.io/) (twórcy PS2BBL): 
  - @SP193 za biblioteki inicjalizacji OSD, które są podstawą tego projektu
  - @asmblur za zachętę do zrobienia tego potwora na najnowszym SDK
  - @uyjulian i @fjtrujy za to, że zawsze mi pomagają


<p align="center"><sub><a href="https://github.com/akilluminati47/RIPPS2">RIPPS2</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2/releases/latest/download/RIPPS2.elf">Pobierz</a> &nbsp;&middot;&nbsp; <b>BIBLE</b> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2-themes">Motywy</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPCSX2">RIPPCSX2</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2-fonts">Czcionki</a> &nbsp;&middot;&nbsp; <a href="https://akilluminati47.github.io/RIPPS2/">Strona</a> &nbsp;&middot;&nbsp; <a href="https://www.psx-place.com/threads/ripps2-a-ps2-front-end-in-one-elf-launch-disc-storage-memory-files.51316/">psx-place</a> &nbsp;&middot;&nbsp; <a href="https://discord.gg/Z7m9u5kby">Discord</a></sub></p>

