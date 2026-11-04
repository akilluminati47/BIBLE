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
  <a href="README.ro.md">Română</a> |
  <a href="README.gl.md">Galego</a> |
  <a href="README.sq.md">Shqip</a> |
  <a href="README.tr.md">Türkçe</a> |
  <a href="README.ar.md">العربية</a> |
  <b>فارسی</b> |
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

<p align="center"><sub>ترجمهٔ README انگلیسی؛ اگر فرق داشتند، نسخهٔ انگلیسی معتبر است. <a href="README.md">English</a></sub></p>

<div dir="rtl">

<p align="center"><sub><a href="https://github.com/akilluminati47/RIPPS2">RIPPS2</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2/releases/latest/download/RIPPS2.elf">دانلود</a> &nbsp;&middot;&nbsp; <b>BIBLE</b> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2-themes">پوسته‌ها</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPCSX2">RIPPCSX2</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2-fonts">فونت‌ها</a> &nbsp;&middot;&nbsp; <a href="https://akilluminati47.github.io/RIPPS2/">وب‌سایت</a> &nbsp;&middot;&nbsp; <a href="https://www.psx-place.com/threads/ripps2-a-ps2-front-end-in-one-elf-launch-disc-storage-memory-files.51316/">psx-place</a> &nbsp;&middot;&nbsp; <a href="https://discord.gg/Z7m9u5kby">Discord</a></sub></p>

<h1 align="center">BIBLE</h1>
<p align="center">
  <a href="https://github.com/akilluminati47/RIPPS2">RIPPS2</a> ·
  <a href="https://github.com/akilluminati47/BIBLE/actions">بیلدها</a> ·
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
  <sub>هنگام روشن‌شدن L2 + R2 را نگه دارید تا صفحهٔ کلیدهای اجرا باز شود، و TRIANGLE + CROSS را برای صفحهٔ حالت ویدئو؛ کلیدی که روی <code>$CREDITS</code> تنظیم شده باشد، تیتراژ را نشان می‌دهد.</sub>
</p>

BIBLE بوت‌لودری است که RIPPS2 راه‌اندازی می‌کند: یک فورک از PS2BBL Extended ساختهٔ saildot4k.

**این فورک چه چیزی را تغییر می‌دهد**

- صفحهٔ آغاز: لوگوی PS2 در میانهٔ آسمان RIPPS2، با دکمه‌ها زیر آن و هر متنی بالای آن. `BIBLE_GLYPHS` 0 هیچ، 1 دکمه‌های عمل (پیش‌فرض)، 2 هر شانزده در دو ردیف هشتایی. `BIBLE_INFO` 1 اطلاعات کنسول، ساعت و شمارش معکوس را نشان می‌دهد (پیش‌فرض خاموش). آسمان از Color Theme شما در RIPPS2 پیروی می‌کند: بدون `BIBLE_COLOR`، BIBLE آسمانی را که RIPPS2 با تنظیماتش ذخیره می‌کند می‌خواند، از پوشه‌ای که ورودی AUTO آن را اجرا می‌کند، یا از پوشهٔ `RIPPS2` یک کارت حافظه وقتی ورودی AUTO همان RIPPS2 روی SD2PSX، USB یا هارد دیسک است (`BIBLE_COLOR` در پیکربندی برنده است). همان ظاهر در هر حالت تصویر.
- `BIBLE_BACKGROUND`: `AUTO` (پیش‌فرض: آسمان وقتی تنظیمات RIPPS2 پیدا شود یا `BIBLE_COLOR` تنظیم شده باشد، وگرنه سیاه در حالت خود کنسول، یک بوت‌لودر ساده)، `SKY` یا `BLANK` (سیاه). گذر به یک برنامه به هر حال چند ثانیه سیاه است، پس سیاه با آن یکپارچه به نظر می‌رسد.
- صدای راه‌اندازی، از پیش آماده: گزینهٔ Boot Sound On (fast) در RIPPS2 می‌تواند `boot.adp` را کنار پیکربندی BIBLE نگه دارد (`mc?:/SYS-CONF/boot.adp`). پیش از شروع هر درایوی خوانده می‌شود. BIBLE می‌تواند آن را در RAM هم به RIPPS2 بدهد، اما این فقط در آزمایشگاه موفق بوده است: روی یک SD2PSX واقعی، RIPPS2 خودش نسخهٔ روی کارت را خواند. **بی‌صدا سریع‌ترین راه‌اندازی است.** قرارداد و سهم RIPPS2: [docs/boot-sound-handoff.md](docs/boot-sound-handoff.md).
- اول RIPPS2: الگوی پیکربندی (`release/SYS-CONF/PS2BBL.INI`) و پیش‌فرض‌های داخلی، `mc?:/RIPPS2/RIPPS2.ELF` و `mmce?:/APPS/RIPPS2.ELF` را پیش از OSDMenu و FMCB امتحان می‌کنند، و الگو کلیدهای خود BIBLE را با توضیح فهرست می‌کند. صفحه‌ها (حالت تصویر، سازندگان، کلیدهای اجرا) روی لوگوی کم‌نور با دکمه‌های کنارگذاشته ظاهر می‌شوند، تا کلیدهای اجرا آرام خوانده شوند.
- حالت‌های ویدئو: `VIDEO_MODE` همچنین `576P`، `720P` و `1080I` را می‌پذیرد، یعنی بقیهٔ حالت‌های RIPPS2. `AUTO` (پیش‌فرض)
  وقتی تنظیمات RIPPS2 کنار ورودی AUTO باشد در Video Mode آن شروع می‌شود، وگرنه در حالت خود کنسول.
- `BIBLE_WIDESCREEN`: `AUTO` (پیش‌فرض: Widescreen در RIPPS2، وگرنه تنظیم صفحهٔ 16:9 در PS2)، `ON` یا
  `OFF`. در 480i، 576i، 480p و 576p صفحهٔ آغاز برای تلویزیونی کشیده می‌شود که تصویر را تا 16:9 کش می‌دهد، بی
  فشردگی. 720p و 1080i از قبل 16:9 هستند.
- گذر به RIPPS2: هنگام اجرا لوگو و دکمه‌ها محو می‌شوند و آسمان می‌ماند تا کنسول برنامهٔ بعدی را بارگذاری کند، که صفحه را سیاه می‌کند (حدود ۷ ثانیه در آزمایشگاه با RIPPS2 روی کارت حافظه). سپس RIPPS2 در همان حالت ویدئو و همان رنگ‌ها ظاهر می‌شود. هنگام روشن‌شدن TRIANGLE + CROSS را برای صفحهٔ حالت ویدئو نگه دارید، که همیشه
  در حالت درهم‌بافتهٔ خود کنسول باز می‌شود (راه بازگشت از 720p یا 1080i روی کابل کامپوزیت).
- تازه: صفحهٔ کلیدهای اجرا. هنگام روشن کردن L2 + R2 را نگه دارید تا BIBLE پیش از اجرای هر چیزی مکث کند و مسیرهای اجرای فعلی هر کلید را نشان دهد، هر تنظیمی که برای صفحهٔ آغاز دارید (با `LOGO_DISPLAY = 0` که چیز دیگری نشان داده نمی‌شود، به کار می‌آید).
- ترکیب‌هایی که از لحظهٔ روشن‌شدن نگه داشته می‌شوند اکنون صفحه‌هایشان را باز می‌کنند (TRIANGLE + CROSS وقتی دسته‌ها هنوز
  در حال راه‌اندازی بودند از دست می‌رفت).
- `KEY_READ_WAIT_TIME = 0` مجاز است (کمینهٔ upstream برابر 500 ms است).
- بیلدهای PS2 برای کارت حافظه / USB، MMCE، MX4SIO و HDD. مرحلهٔ 2 از eGSM کنار گذاشته شده است.

**RIPPS2 چگونه از آن استفاده می‌کند**

RIPPS2، BIBLE را درون RIPPS2.elf دارد، هر نسخه امضاشده توسط akilluminati47، و آن را از تنظیمات > عمومی > Boot Loader > Manage نصب یا به‌روز می‌کند، که کلیدهای BIBLE را هم تنظیم می‌کند: Background، Splash، Button Glyphs، Info Line، Power-on Wait، Video Mode و Widescreen. نسخه‌های امضاشده و یک کارت BOOT آمادهٔ SD2PSX در [صفحهٔ انتشارها](https://github.com/akilluminati47/BIBLE/releases/latest) هستند. BIBLE همچنین به‌صورت ELF اجرا می‌شود که بارگذار دیگری آن را اجرا کند (FMCB، OSDMenu، بارگذار یک SD2PSX).

<p align="center"><img src="assets/readme/ripps2-icon.png" alt="RIPPS2" width="48" height="48"><br><sub>BIBLE بخشی از <a href="https://github.com/akilluminati47/RIPPS2">RIPPS2</a> است.</sub></p>

---

<p align="center"><sub>همهٔ آنچه در ادامه می‌آید README اصلی PS2BBL Extended است، ترجمه‌شده و بی هیچ تغییر دیگری.</sub></p>

---


<br />
<p align="center">
  <a href="https://israpps.github.io/PlayStation2-Basic-BootLoader/">
    <img src="https://github.com/saildot4k/PlayStation2-Basic-BootLoader-Extended/blob/main/assets/ps2bbl_example.png" alt="Logo" width="50%" height="auto">
  </a>

  <p align="center">
    یک بوت‌لودر انعطاف‌پذیر برای PlayStation 2™ و PSX-DESR
    <br />
  </p>
</p>  


این یک فورک از PS2BBL ساختهٔ [El Isra](https://github.com/israpps/PlayStation2-Basic-BootLoader/) است


<a id="documentation"></a>

## مستندات

روی [github pages](https://israpps.github.io/PlayStation2-Basic-BootLoader/) میزبانی می‌شود، اما با افزوده‌های زیر:

<a id="config-and-arguments"></a>

## پیکربندی و آرگومان‌ها

فایل پیکربندی را در صورت نیاز ویرایش کنید. برای ویرایش آن [R3Configurator](https://github.com/saildot4k/R3CONFIGURATOR) پیشنهاد می‌شود. مسیرها از پیش با دانلودهای [PS2 Homebrew Store](https://ps2homebrewstore.com) هماهنگ شده‌اند. بنابراین فقط باید گزینهٔ Auto را ویرایش کنید و بهتر است آرگومان‌های NHDDL را بر اساس دستگاهی که ISOها را از آن بارگذاری می‌کنید تنظیم کنید.

<a id="config-path-search-order"></a>

### ترتیب جست‌وجوی پیکربندی

جست‌وجوی پیکربندی اکنون خانوادهٔ بوت را در نظر می‌گیرد تا هنگام شروع درایورهای غیرضروری بارگذاری نشوند:

1. `CONFIG.INI` (CWD: پوشهٔ کاری فعلی)
2. هنگام بارگذاری از یک دستگاه:
   - بوت از MMCE: `mmce?:/PS2BBL/CONFIG.INI`
   - بوت از MX4SIO: `mx4sio:/PS2BBL/CONFIG.INI`
   - بوت از APA HDD: `hdd0:__sysconf:pfs:/PS2BBL/CONFIG.INI`
   - بوت از BDM: `usb:/PS2BBL/CONFIG.INI` / `mass:/PS2BBL/CONFIG.INI` / `ata:/PS2BBL/CONFIG.INI`
3. جایگزین روی کارت حافظه:
   - روی PS2: `mc?:/SYS-CONF/PS2BBL.INI`
   - روی PSX-DESR: `mc?:/SYS-CONF/PSXBBL.INI`
4. آخرین جایگزین روی PSX
   - `xfrom:/PS2BBL/CONFIG.INI`
5. وقتی با `DISC_STOP_AT_BOOT=1 کامپایل شده باشد
   - `cdrom0:/PS2BBL/CONFIG.INI`
   - جایگزین روی کارت حافظه همان‌طور که در بند 3 بالا آمده است.

<a id="device-path-prefixes"></a>

### پیشوندهای مسیر دستگاه
PS2BBL این پیشوندهای مسیر اجرا/پیکربندی را پشتیبانی می‌کند:
- `mc0:/`, `mc1:/`, `mc?:/`
- `usb:/` (ترجیحی)، و `mass:/` (قدیمی)

<a id="build-specific"></a>

#### ویژهٔ هر بیلد:  
- `mmce0:/`، `mmce1:/`، `mmce?:/` __بیلدهای MMCE__
- `mx4sio:/` (ترجیحی)، و `massX:/` (قدیمی)  __بیلدهای MX4SIO__
- `hdd0:partition:pfs:/<path to elf>` __بیلدهای HDD__
- مسیرهای `xfrom:/` __بیلدهای PSX DESR__
- `ata:/` دستگاه BDM برای HDD با exFAT
- `ilink:/` (ریشه‌های ذخیره‌سازی انبوه BDM) __هنوز پیاده‌سازی نشده__
- `DISC_STOP_AT_BOOT=1` پروفایل کامپایلی که همیشه پس از بارگذاری پیکربندی دیسک نوری را متوقف می‌کند

### LOGO_DISPLAY
برای نمایش نام کلیدها از `LOGO_DISPLAY = 3` استفاده کنید. نام‌ها با `NAME_<BUTTON>` تعیین می‌شوند.
  - `0` بدون لوگو و اطلاعات کنسول
  - `1` اطلاعات کنسول
  - `2` لوگوی PS2BBLE/PSXBBLE و اطلاعات کنسول
  - `3` نمایش گرافیکی کلیدها با `NAME_BUTTON = <TITLE>` از فایل پیکربندی
    - نمونه:
      ```
      NAME_SQUARE = POPSLOADER
      ```

<a id="custom-splash-logo-from-cwd"></a>

#### لوگوی آغاز سفارشی از CWD
اگر فایل لوگوی سفارشی (LOGO.BIN) در CWD (پوشهٔ کاری فعلی) پیدا شود، جای لوگوی تعبیه‌شدهٔ PS2BBLE/PSXBBLE را می‌گیرد.

یک PNG را به فایل خام مورد انتظار تبدیل کنید:
  - PNG باید RGBA نمایه‌دار 8 بیتی، با 255 رنگ در هر کانال و وضوح 256x64 باشد.

  - بستهٔ انتشار (اسکریپت در ریشهٔ انتشار است):
  ```bash
  python png_to_logo_rbga.py my_logo.png
  ```

  - `LOGO.BIN` ساخته‌شده را کنار PS2BBL Extended بگذارید. اگر از دانلودهای [PS2 Homebrew Store](https://ps2store.com) استفاده می‌کنید، باید `mc?:/BOOT/` باشد

<a id="retrogem-visual-game-id"></a>

### شناسهٔ تصویری بازی Retrogem
- `APP_GAMEID = 1` شناسهٔ تصویری بازی را برای برنامه‌ها/homebrew فعال می‌کند، تا 11 نویسه برگرفته از نام فایل یا دیسک PS1/2
- `CDROM_DISABLE_GAMEID = 1` شناسهٔ تصویری بازی را برای دیسک‌هایی که با `cdrom` اجرا می‌شوند غیرفعال می‌کند.

<a id="disc-spin-control"></a>

### کنترل چرخش دیسک
- کلید/مقدار سراسری: `DISC_STOP = 0/1`
- `DISC_STOP = 1` پس از بارگذاری پیکربندی، اگر فایل پیکربندی پیدا شده باشد، دیسک نوری را متوقف می‌کند.
- `DISC_STOP = 0` (یا ننوشتن آن) رفتار پیش‌فرض را نگه می‌دارد.
- `-disc_stop` را می‌توان به هر ورودی اجرا افزود تا پس از یافتن ELF مقصد دیسک متوقف شود.

<a id="video-mode"></a>

### حالت ویدئو
- `VIDEO_MODE = AUTO, NTSC, PAL, 480P` از پیش‌فرض PS2 استفاده می‌کند یا یکی از 3 حالت دیگر را تحمیل می‌کند.

<a id="emergency-video-mode-selector"></a>

#### انتخابگر اضطراری حالت ویدئو
- با `TRIANGLE + CROSS` هنگام بوت وارد شوید
- انتخابگر تا وقتی فعال است `LOGO_DISPLAY = 3` را تحمیل می‌کند تا زمینهٔ لوگو و کلیدها را ببینید.
- کنترل‌ها:
  - `LEFT/RIGHT` میان حالت‌ها جابه‌جا می‌شوند: `AUTO`، `NTSC`، `PAL`، `480P`
  - `SELECT` حالت انتخاب‌شده را در فایل پیکربندی فعال ذخیره می‌کند
  - `START` از انتخابگر خارج می‌شود و به نمایش کلیدها می‌رود

<a id="cdrom-launch-args"></a>

### آرگومان‌های اجرای CDROM
برای `LK_*_E* = cdrom`، آرگومان‌های پشتیبانی‌شده این‌ها هستند:
- `-nologo`
- `-nogameid`
- `-ps1fast`
- `-ps1smooth`
- `-ps1vneg`
- `-gsm=<v[:c]>`

<a id="ps2logo-arguments-ps2-discs-only"></a>

#### آرگومان‌های PS2LOGO (فقط دیسک‌های PS2)
- از `cdrom` به‌عنوان مسیر ورودی اجرا استفاده کنید.
- `-nologo` را به آرگومان‌های ورودی بیفزایید تا دیسک‌های PS2 مستقیم بوت شوند (رد شدن از `rom0:PS2LOGO`).
- بدون `-nologo`، PS2BBL دیسک را از طریق PS2LOGO اجرا می‌کند و آن را وصله می‌کند تا همیشه از منطقهٔ دیسک استفاده کند و از بررسی checksum لوگو بگذرد.
- DECKARD IE 75K و پس از آن: XPARAM.IRX هر جا برای اجرای بی‌لوگو لازم باشد خودکار اعمال می‌شود.

<a id="ps1-disc-arguments-per-launch"></a>

#### آرگومان‌های دیسک PS1 (برای هر اجرا)
این‌ها برای هر ورودی اجرای `cdrom` جداگانه اعمال می‌شوند، نه به‌صورت سراسری.
- `-ps1fast` سرعت سریع دیسک PS1 را فعال می‌کند.
- `-ps1smooth` هموارسازی بافت را فعال می‌کند.
- `-ps1vneg` برنامهٔ PS1DRV را از طریق PS1VModeNegator اجرا می‌کند. در جایی که حالت کنسول و حالت دیسک متفاوت است مفید است (مثلاً برخی موارد MechaPwn/مادچیپ).

<a id="app-arguments"></a>

### آرگومان‌های برنامه
برای فرستادن آرگومان به یک ELF از خطوط `ARG_<BUTTON>_E? =` استفاده کنید (نمونه‌های INI را ببینید).
- اول آرگومان‌های elf اجراشده را بگذارید و سپس آرگومان‌های داخلی دلخواه PS2BBL را بیفزایید (پایین را ببینید). [NHDDL](https://github.com/pcm720/nhddl) نامزد بسیار خوبی برای آرگومان‌هاست، چون بوت آن را سریع‌تر می‌کنند.
- `-titleid=SLUS_123.45` شناسهٔ عنوان برنامه را جایگزین می‌کند (تا 11 نویسه).
- `-appid` حتی اگر `APP_GAMEID = 0` باشد شناسهٔ تصویری بازی برنامه را تحمیل می‌کند.
- `-disc_stop` پس از بارگذاری ELF مقصد دیسک را متوقف می‌کند (برای هر ورودی بدون بیلدهای `DISC_STOP_AT_BOOT` مفید است).
- `-gsm=<v[:c]>` ELF مقصد را از طریق eGSM تعبیه‌شده اجرا می‌کند (برای مسیرهای `rom?:` نادیده گرفته می‌شود). اگر استفاده شود باید آخرین آرگومان باشد.
- `-disc_stop` برای ورودی‌های اجرای `cdrom` نادیده گرفته می‌شود.
- `-dev9=<mode>` پیش از اجرای ELF مقصد سیاست DEV9/HDD را تنظیم می‌کند. حالت‌های پشتیبانی‌شده:
  - `NICHDD` هم DEV9 (آداپتور شبکه) و هم HDD را روشن نگه می‌دارد.
  - `NIC` DEV9/شبکه را روشن نگه می‌دارد، `pfs0:` را جدا می‌کند و `hdd0:`/`hdd1:` را بی‌درنگ به حالت بیکار می‌برد.
  - اگر ننویسید، PS2BBL هیچ سیاستی برای DEV9 تحمیل نمی‌کند.
  - نکته: در بیلدهای بدون HDD این گزینه اثری ندارد.
- `-patinfo` رسیدگی به PATINFO را برای ورودی‌های `:PATINFO` فعال می‌کند.
  - PS2BBL فایل `SYSTEM.CNF` را از ناحیهٔ ویژگی‌های پارتیشن (`PS2ICON3D`) می‌خواند و `BOOT2/BOOT/path`، `arg*`، `skip_argv0` و `HDDUNITPOWER` را اعمال می‌کند.
  - اگر `BOOT2/BOOT/path=PATINFO` باشد، PS2BBL فایل ELF تعبیه‌شده را از ناحیهٔ ویژگی‌های پارتیشن بارگذاری می‌کند و از تحویل داخلی `-la=E...` استفاده می‌کند.
  - اگر `IOPRP=PATINFO` (یا مسیری سفارشی) باشد، PS2BBL آن را از طریق تحویل داخلی `-la=I...` به مرحلهٔ 2 می‌دهد.
  - اگر `-patinfo` باشد، نخستین آرگومان باقی‌مانده جای مقصد `BOOT2/BOOT/path` در CNF را می‌گیرد.
  این برای بیلدهای HDD است.  
  نمونهٔ PATINFO:  
    ```
    NAME_R1 = My App via PATINFO
    LK_R1_E1 = hdd0:+OSDMENU:PATINFO
    ARG_R1_E1 = pfs:/APPS/MYAPP.ELF
    ARG_R1_E1 = -patinfo               # Tells PS2BBL to use first arg as patinfo boot path.
    ```

نمونه‌ای برای اجرای NHDDL در حالت ویدئوی 480p و جست‌وجوی ISO روی mmce و HDD با exfat بدون نیاز به nhddl.yaml. مزیتش این است که وقتی برای بارگذاری درایورها و یافتن و بارگذاری nhddl.yaml هدر نمی‌رود. این سریع‌ترین راه برای بوت NHDDL و نمایش فهرست ISO است.
```
NAME_R1 = NHDDL
LK_R1_E1 = mmce?:/NEUTRINO/nhddl.elf
ARG_R1_E1 = -video=480p
ARG_R1_E1 = -mode=mmce
ARG_R1_E1 = -mode=ata
```

<a id="argument-precedence-and-order"></a>

#### اولویت و ترتیب آرگومان‌ها
1. PS2BBL فقط آرگومان‌های کنترلی بوت‌لودر در انتهای `ARG_*` را تجزیه و مصرف می‌کند: `-appid`، `-titleid=`، `-dev9=`، `-patinfo`، `-disc_stop`، `-gsm=`.
2. تجزیه از پایین به بالا انجام می‌شود و در نخستین آرگومان غیرکنترلی متوقف می‌شود (رفتار پایانی به سبک OSDMenu).
4. برای مسیرهای اجرای `:PATINFO`، PS2BBL فایل `SYSTEM.CNF` ویژگی پارتیشن را تجزیه می‌کند و ورودی‌های `arg*` در CNF را پس از آرگومان‌های برنامهٔ کاربر می‌افزاید.
5. اگر `-patinfo` تنظیم شده باشد و مسیر اجرا شامل `:PATINFO` باشد، نخستین آرگومان باقی‌ماندهٔ کاربر مسیر ELF مقصد می‌شود (جای مسیر بوت CNF را می‌گیرد) و از argv برنامه حذف می‌شود. اگر هیچ آرگومانی باقی نماند، اجرا لغو می‌شود (همانند OSDMenu) و از `BOOT2/BOOT/path` در CNF استفاده نمی‌شود.
6. آرگومان‌های باقی‌مانده ترتیبشان را حفظ می‌کنند و به برنامهٔ اجراشده داده می‌شوند.


### eGSM (external Graphics Synthesize Mode)
برای دیسک‌های PS2، eGSM خودکار از `OSDGSM.CNF` خوانده می‌شود (نیازی به تنظیم مسیر در INI نیست). قالب فایل پیکربندی را [این‌جا](https://github.com/pcm720/OSDMenu/blob/main/patcher/README.md#osdgsmcnf) ببینید.

- `-gsm=<v[:c]>` ELF مقصد را از طریق eGSM تعبیه‌شده اجرا می‌کند (برای مسیرهای `rom?:` نادیده گرفته می‌شود).
  - eGSM روی مقصد اجراشده (ELF/دیسک) اعمال می‌شود، نه روی خود PS2BBL.
  قالب eGSM (به سبک OSDMenu):
- `v` = حالت ویدئو:
- خالی = بدون تحمیل (پیش‌فرض)
- `fp1` = تحمیل پویش پیشرونده (240p/288p)
- `fp2` = تحمیل پویش پیشرونده (480p/576p)
- `1080ix1` = تحمیل 1080i، پهنا/ارتفاع x1
- `1080ix2` = تحمیل 1080i، پهنا/ارتفاع x2
- `1080ix3` = تحمیل 1080i، پهنا/ارتفاع x3
- `c` = حالت سازگاری:
- خالی = هیچ (پیش‌فرض)
- `1` = وارونه‌سازی فیلدها نوع 1
- `2` = وارونه‌سازی فیلدها نوع 2
- `3` = وارونه‌سازی فیلدها نوع 3

نمونه‌های ARG برای eGSM:
- `-gsm=fp2`
- `-gsm=fp2:1`
- `-gsm=1080ix2`

نمونهٔ استفاده:
```
LK_TRIANGLE_E1 = mc0:/APP_WLE-ISR/WLE-ISR.ELF
ARG_TRIANGLE_E1 = -gsm=1080ix2
```

<a id="deprecatedremoved"></a>

## منسوخ/حذف‌شده
- ~~`RUNKELF`~~ اکنون PS2BBLE اجرای elf/kelf را در درون خود انجام می‌دهد و کاربر نیازی به تعریف کنش اجرای kelf ندارد.


<a id="known-bugsissues"></a>

## اشکال‌ها/مشکلات شناخته‌شده

شما به من بگویید ;)

<a id="credits--thanks"></a>

## سپاس و قدردانی

- از saildot4k
  - @israpps برای [PS2BBL](https://github.com/israpps/PlayStation2-Basic-BootLoader/)
  - @pcm720 برای
    - gameID از Retrogem، PS1 Video Negator، eGSM و کد PS2LOGO از [OSDMenu](https://github.com/pcm720/OSDMenu)
    - گزینه‌های حالت ویدئو از [NHDDL](https://github.com/pcm720/nhddl)
  - @sp193 برای [PS1 Video Negator](https://github.com/ps2homebrew/PS1VModeNeg)
  - @nathanneurotic برای 10 مسیر PS2BBLE، ایده‌ها و ترغیب
  - [@Berion](https://www.psx-place.com/members/berion.1431/) برای لوگوها، پس‌زمینه و گرافیک کلیدها

- از [El Isra](https://israpps.github.io/) (توسعه‌دهندهٔ PS2BBL): 
  - @SP193 برای کتابخانه‌های راه‌اندازی OSD، که پایهٔ این پروژه‌اند
  - @asmblur، برای تشویق من به ساختن این هیولا روی جدیدترین SDK
  - @uyjulian و @fjtrujy که همیشه کمکم می‌کنند


<p align="center"><sub><a href="https://github.com/akilluminati47/RIPPS2">RIPPS2</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2/releases/latest/download/RIPPS2.elf">دانلود</a> &nbsp;&middot;&nbsp; <b>BIBLE</b> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2-themes">پوسته‌ها</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPCSX2">RIPPCSX2</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2-fonts">فونت‌ها</a> &nbsp;&middot;&nbsp; <a href="https://akilluminati47.github.io/RIPPS2/">وب‌سایت</a> &nbsp;&middot;&nbsp; <a href="https://www.psx-place.com/threads/ripps2-a-ps2-front-end-in-one-elf-launch-disc-storage-memory-files.51316/">psx-place</a> &nbsp;&middot;&nbsp; <a href="https://discord.gg/Z7m9u5kby">Discord</a></sub></p>


</div>
