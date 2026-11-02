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
  <b>Български</b> |
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

<p align="center"><sub>Превод на английския README; при разлики важи английският. <a href="README.md">English</a></sub></p>

<p align="center"><sub><a href="https://github.com/akilluminati47/RIPPS2">RIPPS2</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2/releases/latest/download/RIPPS2.elf">Изтегляне</a> &nbsp;&middot;&nbsp; <b>BIBLE</b> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2-themes">Теми</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPCSX2">RIPPCSX2</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2-fonts">Шрифтове</a> &nbsp;&middot;&nbsp; <a href="https://akilluminati47.github.io/RIPPS2/">Сайт</a> &nbsp;&middot;&nbsp; <a href="https://www.psx-place.com/threads/ripps2-a-ps2-front-end-in-one-elf-launch-disc-storage-memory-files.51316/">psx-place</a> &nbsp;&middot;&nbsp; <a href="https://discord.gg/Z7m9u5kby">Discord</a></sub></p>

<h1 align="center">BIBLE</h1>
<p align="center">
  <a href="https://github.com/akilluminati47/RIPPS2">RIPPS2</a> ·
  <a href="https://github.com/akilluminati47/BIBLE/actions">Компилации</a> ·
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
  <sub>Задръжте L2 + R2 при стартиране за страницата с клавишите за стартиране, TRIANGLE + CROSS за страницата с видео режима; клавиш, зададен на <code>$CREDITS</code>, показва надписите.</sub>
</p>

BIBLE е зареждащата програма, която RIPPS2 инсталира: форк на PS2BBL Extended на saildot4k.

**Какво променя този форк**

- Началният екран: логото на PS2 в средата на небето на RIPPS2, с бутоните под него и евентуален текст над него.
  `BIBLE_GLYPHS` 0 никакви, 1 предните бутони (по подразбиране), 2 всички шестнайсет в два реда по осем.
  `BIBLE_INFO` 1 показва информация за конзолата, часовник и обратно броене (изключено по подразбиране).
  Небето следва вашия Color Theme от RIPPS2: без `BIBLE_COLOR` BIBLE чете небето, което RIPPS2 записва със своите
  настройки, от папката на RIPPS2, която записът му AUTO стартира (`BIBLE_COLOR` в конфигурацията има предимство).
  Същият вид във всеки видео режим. Страниците (видео режим, надписи, клавиши за стартиране) се появяват плавно върху затъмненото лого
  с прибрани бутони, така че клавишите за стартиране се четат спокойно.
- Видео режими: `VIDEO_MODE` приема и `576P`, `720P` и `1080I`, останалите режими на RIPPS2. `AUTO` (по подразбиране)
  стартира във Video Mode на RIPPS2, когато настройките му са до записа AUTO, иначе в режима на конзолата.
- `BIBLE_WIDESCREEN`: `AUTO` (по подразбиране: Widescreen на RIPPS2, иначе настройката за екран 16:9 на PS2), `ON` или
  `OFF`. В 480i, 576i, 480p и 576p началният екран се рисува за телевизор, който разтяга картината до 16:9, без
  сплескване. 720p и 1080i вече са 16:9.
- Без скок при влизане в RIPPS2: при стартиране логото и бутоните изчезват, а небето остава на екрана в режима на RIPPS2;
  RIPPS2 започва на същото небе. Задръжте TRIANGLE + CROSS при стартиране за страницата с видео режима, която винаги се отваря
  в собствения презредов режим на конзолата (пътят обратно от 720p или 1080i с композитен кабел).
- Ново: страницата с клавишите за стартиране. Задръжте L2 + R2 при стартиране, за да прочетете пътя на всеки клавиш, каквито и да са настройките на началния екран.
- Комбинациите, задържани от включването, вече отварят своите страници (TRIANGLE + CROSS се изпускаше, докато контролерите още
  стартираха).
- `KEY_READ_WAIT_TIME = 0` е разрешено (минимумът в upstream е 500 ms).
- Компилации за PS2 за карта с памет / USB, MMCE, MX4SIO и HDD. Етап 2 на eGSM е изпуснат.

**Как го използва RIPPS2**

RIPPS2 ще носи BIBLE като подписани файлове за стартиране и ще го инсталира от своите Settings (Boot Loader), вместо PS2BBL 1.2.0, който носи днес. BIBLE работи и като ELF, стартиран от друга зареждаща програма (FMCB, OSDMenu, зареждащата програма на SD2PSX). Все още няма издание на BIBLE.

<p align="center"><img src="assets/readme/ripps2-icon.png" alt="RIPPS2" width="48" height="48"><br><sub>BIBLE е част от <a href="https://github.com/akilluminati47/RIPPS2">RIPPS2</a>.</sub></p>

---

<p align="center"><sub>Всичко по-долу е оригиналният README на PS2BBL Extended, преведен и иначе непроменен.</sub></p>

---


<br />
<p align="center">
  <a href="https://israpps.github.io/PlayStation2-Basic-BootLoader/">
    <img src="https://github.com/saildot4k/PlayStation2-Basic-BootLoader-Extended/blob/main/assets/ps2bbl_example.png" alt="Logo" width="50%" height="auto">
  </a>

  <p align="center">
    Гъвкава зареждаща програма за PlayStation 2™ и PSX-DESR
    <br />
  </p>
</p>  


Това е форк на PS2BBL от [El Isra](https://github.com/israpps/PlayStation2-Basic-BootLoader/)


<a id="documentation"></a>

## Документация

Тя е в [github pages](https://israpps.github.io/PlayStation2-Basic-BootLoader/), но с добавките по-долу:

<a id="config-and-arguments"></a>

## Конфигурация и аргументи

Редактирайте конфигурационния файл според нуждите. За редакция се препоръчва [R3Configurator](https://github.com/saildot4k/R3CONFIGURATOR). Пътищата вече са настроени да съвпадат с изтеглянията от [PS2 Homebrew Store](https://ps2homebrewstore.com). Така би трябвало да редактирате само избора си Auto и най-добре да зададете аргументи за NHDDL според устройството, от което зареждате ISO файлове.

<a id="config-path-search-order"></a>

### Ред на търсене на конфигурацията

Търсенето на конфигурацията вече отчита семейството на стартиране, за да не се зареждат ненужни драйвери при старт:

1. `CONFIG.INI` (CWD: текуща работна папка)
2. При зареждане от устройство:
   - Стартиране от MMCE: `mmce?:/PS2BBL/CONFIG.INI`
   - Стартиране от MX4SIO: `mx4sio:/PS2BBL/CONFIG.INI`
   - Стартиране от APA HDD: `hdd0:__sysconf:pfs:/PS2BBL/CONFIG.INI`
   - Стартиране от BDM: `usb:/PS2BBL/CONFIG.INI` / `mass:/PS2BBL/CONFIG.INI` / `ata:/PS2BBL/CONFIG.INI`
3. Резерва на картата с памет:
   - На PS2: `mc?:/SYS-CONF/PS2BBL.INI`
   - На PSX-DESR: `mc?:/SYS-CONF/PSXBBL.INI`
4. Последна резерва на PSX
   - `xfrom:/PS2BBL/CONFIG.INI`
5. При компилация с `DISC_STOP_AT_BOOT=1
   - `cdrom0:/PS2BBL/CONFIG.INI`
   - Резерва на картата с памет като в точка 3 по-горе.

<a id="device-path-prefixes"></a>

### Представки на пътищата на устройства
PS2BBL поддържа тези представки за пътища за стартиране/конфигурация:
- `mc0:/`, `mc1:/`, `mc?:/`
- `usb:/` (предпочитана) и `mass:/` (стара)

<a id="build-specific"></a>

#### Според компилацията:  
- `mmce0:/`, `mmce1:/`, `mmce?:/` __компилации MMCE__
- `mx4sio:/` (предпочитана) и `massX:/` (стара)  __компилации MX4SIO__
- `hdd0:partition:pfs:/<path to elf>` __компилации HDD__
- Пътища `xfrom:/` __компилации PSX DESR__
- `ata:/` BDM устройство за exFAT HDD
- `ilink:/` (корени на BDM масова памет) __още не е реализирано__
- `DISC_STOP_AT_BOOT=1` профил на компилация, който винаги спира оптичния диск след зареждане на конфигурацията

### LOGO_DISPLAY
Използвайте `LOGO_DISPLAY = 3`, за да показвате имената на клавишите. Имената се задават с `NAME_<BUTTON>`.
  - `0` Без лого и информация за конзолата
  - `1` Информация за конзолата
  - `2` Лого PS2BBLE/PSXBBLE и информация за конзолата
  - `3` Графика на клавишите с `NAME_BUTTON = <TITLE>` от конфигурационния файл
    - Пример:
      ```
      NAME_SQUARE = POPSLOADER
      ```

<a id="custom-splash-logo-from-cwd"></a>

#### Собствено начално лого от CWD
Ако в CWD (текущата работна папка) има собствен файл с лого (LOGO.BIN), той заменя вграденото лого PS2BBLE/PSXBBLE.

Преобразувайте PNG в очаквания суров файл:
  - PNG трябва да е RGBA, 8-битов индексиран, 255 цвята на канал и с резолюция 256x64.

  - Пакет на изданието (скриптът е в корена на изданието):
  ```bash
  python png_to_logo_rbga.py my_logo.png
  ```

  - Сложете създадения `LOGO.BIN` до PS2BBL Extended. Това трябва да е `mc?:/BOOT/`, ако използвате изтегляния от [PS2 Homebrew Store](https://ps2store.com)

<a id="retrogem-visual-game-id"></a>

### Визуален ID на играта от Retrogem
- `APP_GAMEID = 1` включва визуалния ID на играта за приложения/homebrew, до 11 знака от името на файла или от диска на PS1/2
- `CDROM_DISABLE_GAMEID = 1` изключва визуалния ID на играта за дискове, стартирани чрез `cdrom`.

<a id="disc-spin-control"></a>

### Управление на въртенето на диска
- Глобален ключ/стойност: `DISC_STOP = 0/1`
- `DISC_STOP = 1` спира оптичния диск след зареждане на конфигурацията, когато е намерен конфигурационен файл.
- `DISC_STOP = 0` (или пропуснато) запазва поведението по подразбиране.
- `-disc_stop` може да се добави към всеки запис, за да спре диска, щом бъде намерен целевият ELF.

<a id="video-mode"></a>

### Видео режим
- `VIDEO_MODE = AUTO, NTSC, PAL, 480P` Използва режима по подразбиране на PS2 или налага някой от другите 3.

<a id="emergency-video-mode-selector"></a>

#### Авариен избор на видео режим
- Отваря се с `TRIANGLE + CROSS` по време на стартиране
- Изборът налага `LOGO_DISPLAY = 3`, докато е активен, за да виждате логото и клавишите.
- Управление:
  - `LEFT/RIGHT` сменят режимите: `AUTO`, `NTSC`, `PAL`, `480P`
  - `SELECT` записва избрания режим в активния конфигурационен файл
  - `START` излиза от избора и продължава към показването на клавишите

<a id="cdrom-launch-args"></a>

### Аргументи за стартиране от CDROM
За `LK_*_E* = cdrom` поддържаните аргументи са:
- `-nologo`
- `-nogameid`
- `-ps1fast`
- `-ps1smooth`
- `-ps1vneg`
- `-gsm=<v[:c]>`

<a id="ps2logo-arguments-ps2-discs-only"></a>

#### Аргументи за PS2LOGO (само дискове за PS2)
- Използвайте `cdrom` като път на записа.
- Добавете `-nologo` към аргументите на записа, за да стартирате дискове за PS2 директно (без `rom0:PS2LOGO`).
- Без `-nologo` PS2BBL стартира диска чрез PS2LOGO и го поправя да използва винаги региона на диска и да пропуска проверката на контролната сума на логото.
- DECKARD IE 75K и по-нови: XPARAM.IRX се прилага автоматично, когато е нужно, при стартиране без лого.

<a id="ps1-disc-arguments-per-launch"></a>

#### Аргументи за дискове за PS1 (за всяко стартиране)
Важат за всеки запис `cdrom`, а не глобално.
- `-ps1fast` включва бързата скорост на диска за PS1.
- `-ps1smooth` включва изглаждането на текстурите.
- `-ps1vneg` стартира PS1DRV чрез PS1VModeNegator. Полезно там, където режимът на конзолата и този на диска се различават (например някои случаи с MechaPwn/модчипове).

<a id="app-arguments"></a>

### Аргументи на приложения
Използвайте редове `ARG_<BUTTON>_E? =`, за да подадете аргументи на ELF (вижте примерите за INI).
- Първо сложете аргументите на стартирания elf, а след това добавете желаните вътрешни аргументи на PS2BBL (вижте по-долу). [NHDDL](https://github.com/pcm720/nhddl) е отличен кандидат за аргументи, защото ускоряват стартирането му.
- `-titleid=SLUS_123.45` заменя ID на заглавието на приложението (до 11 знака).
- `-appid` налага визуалния ID на играта на приложението дори при `APP_GAMEID = 0`.
- `-disc_stop` спира диска, след като целевият ELF е зареден (полезно за запис без компилации `DISC_STOP_AT_BOOT`).
- `-gsm=<v[:c]>` стартира целевия ELF чрез вградения eGSM (пренебрегва се за пътища `rom?:`). Ако се използва, трябва да е последният аргумент.
- `-disc_stop` се пренебрегва за записи `cdrom`.
- `-dev9=<mode>` задава политиката за DEV9/HDD преди стартиране на целевия ELF. Поддържани режими:
  - `NICHDD` държи включени и DEV9 (мрежовия адаптер), и HDD.
  - `NIC` държи DEV9/мрежата включени, демонтира `pfs0:` и веднага приспива `hdd0:`/`hdd1:`.
  - ако е пропуснато, PS2BBL не налага политика за DEV9.
  - бележка: при компилации без HDD тази опция няма ефект.
- `-patinfo` включва обработката на PATINFO за записи `:PATINFO`.
  - PS2BBL чете `SYSTEM.CNF` от областта с атрибути на дяла (`PS2ICON3D`) и прилага `BOOT2/BOOT/path`, `arg*`, `skip_argv0` и `HDDUNITPOWER`.
  - ако `BOOT2/BOOT/path=PATINFO`, PS2BBL зарежда вградения ELF от областта с атрибути на дяла и използва вътрешното предаване `-la=E...`.
  - ако `IOPRP=PATINFO` (или собствен път), PS2BBL го предава на етап 2 чрез вътрешното предаване `-la=I...`.
  - ако има `-patinfo`, първият оставащ аргумент заменя целта `BOOT2/BOOT/path` от CNF.
  Това е за компилации HDD.  
  Пример за PATINFO:  
    ```
    NAME_R1 = My App via PATINFO
    LK_R1_E1 = hdd0:+OSDMENU:PATINFO
    ARG_R1_E1 = pfs:/APPS/MYAPP.ELF
    ARG_R1_E1 = -patinfo               # Tells PS2BBL to use first arg as patinfo boot path.
    ```

Пример за стартиране на NHDDL във видео режим 480p с търсене на ISO файлове на mmce и на exFAT HDD без нужда от nhddl.yaml. Предимството е, че не се губи време за зареждане на драйвери и за търсене и зареждане на nhddl.yaml. Това е най-бързият начин да стартирате NHDDL и да покажете списъка с ISO.
```
NAME_R1 = NHDDL
LK_R1_E1 = mmce?:/NEUTRINO/nhddl.elf
ARG_R1_E1 = -video=480p
ARG_R1_E1 = -mode=mmce
ARG_R1_E1 = -mode=ata
```

<a id="argument-precedence-and-order"></a>

#### Предимство и ред на аргументите
1. PS2BBL анализира и използва само крайните управляващи аргументи на зареждащата програма от `ARG_*`: `-appid`, `-titleid=`, `-dev9=`, `-patinfo`, `-disc_stop`, `-gsm=`.
2. Анализът върви отдолу нагоре и спира на първия аргумент, който не е управляващ (крайно поведение като в OSDMenu).
4. За пътища `:PATINFO` PS2BBL анализира `SYSTEM.CNF` от атрибута на дяла и добавя записите `arg*` от CNF след аргументите на приложението на потребителя.
5. Ако е зададено `-patinfo` и пътят съдържа `:PATINFO`, първият оставащ аргумент на потребителя става път на целевия ELF (заменя пътя за стартиране от CNF) и се премахва от argv на приложението. Ако не остане аргумент, стартирането се прекратява (както в OSDMenu), а `BOOT2/BOOT/path` от CNF не се използва.
6. Останалите аргументи запазват реда си и се подават на стартираното приложение.


### eGSM (external Graphics Synthesize Mode)
За дискове за PS2 eGSM се чете автоматично от `OSDGSM.CNF` (не е нужен път в INI). Форматът на конфигурационния файл е описан [тук](https://github.com/pcm720/OSDMenu/blob/main/patcher/README.md#osdgsmcnf).

- `-gsm=<v[:c]>` стартира целевия ELF чрез вградения eGSM (пренебрегва се за пътища `rom?:`).
  - eGSM се прилага към стартираната цел (ELF/диск), а не към самия PS2BBL.
  Формат на eGSM (като в OSDMenu):
- `v` = видео режим:
- празно = без налагане (по подразбиране)
- `fp1` = налага прогресивно сканиране (240p/288p)
- `fp2` = налага прогресивно сканиране (480p/576p)
- `1080ix1` = налага 1080i, ширина/височина x1
- `1080ix2` = налага 1080i, ширина/височина x2
- `1080ix3` = налага 1080i, ширина/височина x3
- `c` = режим на съвместимост:
- празно = никакъв (по подразбиране)
- `1` = размяна на полукадрите тип 1
- `2` = размяна на полукадрите тип 2
- `3` = размяна на полукадрите тип 3

Примери за ARG на eGSM:
- `-gsm=fp2`
- `-gsm=fp2:1`
- `-gsm=1080ix2`

Пример за употреба:
```
LK_TRIANGLE_E1 = mc0:/APP_WLE-ISR/WLE-ISR.ELF
ARG_TRIANGLE_E1 = -gsm=1080ix2
```

<a id="deprecatedremoved"></a>

## Остаряло/Премахнато
- ~~`RUNKELF`~~ PS2BBLE вече стартира elf/kelf вътрешно, без потребителят да трябва да задава действие за стартиране на kelf.


<a id="known-bugsissues"></a>

## Известни грешки/проблеми

вие ми кажете ;)

<a id="credits--thanks"></a>

## Благодарности

- От saildot4k
  - @israpps за [PS2BBL](https://github.com/israpps/PlayStation2-Basic-BootLoader/)
  - @pcm720 за
    - gameID на Retrogem, PS1 Video Negator, eGSM и кода на PS2LOGO от [OSDMenu](https://github.com/pcm720/OSDMenu)
    - опциите за видео режим от [NHDDL](https://github.com/pcm720/nhddl)
  - @sp193 за [PS1 Video Negator](https://github.com/ps2homebrew/PS1VModeNeg)
  - @nathanneurotic за 10-те пътя на PS2BBLE, идеите и убеждаването
  - [@Berion](https://www.psx-place.com/members/berion.1431/) за логата, фона и графиката на клавишите

- От [El Isra](https://israpps.github.io/) (разработчик на PS2BBL): 
  - @SP193 за библиотеките за инициализация на OSD, които са основата на този проект
  - @asmblur, че ме насърчи да направя това чудовище на най-новия SDK
  - @uyjulian и @fjtrujy, че винаги ми помагат


<p align="center"><sub><a href="https://github.com/akilluminati47/RIPPS2">RIPPS2</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2/releases/latest/download/RIPPS2.elf">Изтегляне</a> &nbsp;&middot;&nbsp; <b>BIBLE</b> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2-themes">Теми</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPCSX2">RIPPCSX2</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2-fonts">Шрифтове</a> &nbsp;&middot;&nbsp; <a href="https://akilluminati47.github.io/RIPPS2/">Сайт</a> &nbsp;&middot;&nbsp; <a href="https://www.psx-place.com/threads/ripps2-a-ps2-front-end-in-one-elf-launch-disc-storage-memory-files.51316/">psx-place</a> &nbsp;&middot;&nbsp; <a href="https://discord.gg/Z7m9u5kby">Discord</a></sub></p>

