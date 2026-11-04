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
  <b>العربية</b> |
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

<p align="center"><sub>ترجمة لملف README الإنجليزي؛ إن اختلفا فالإنجليزي هو المعتمد. <a href="README.md">English</a></sub></p>

<div dir="rtl">

<p align="center"><sub><a href="https://github.com/akilluminati47/RIPPS2">RIPPS2</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2/releases/latest/download/RIPPS2.elf">تنزيل</a> &nbsp;&middot;&nbsp; <b>BIBLE</b> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2-themes">السمات</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPCSX2">RIPPCSX2</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2-fonts">الخطوط</a> &nbsp;&middot;&nbsp; <a href="https://akilluminati47.github.io/RIPPS2/">الموقع</a> &nbsp;&middot;&nbsp; <a href="https://www.psx-place.com/threads/ripps2-a-ps2-front-end-in-one-elf-launch-disc-storage-memory-files.51316/">psx-place</a> &nbsp;&middot;&nbsp; <a href="https://discord.gg/Z7m9u5kby">Discord</a></sub></p>

<h1 align="center">BIBLE</h1>
<p align="center">
  <a href="https://akilluminati47.github.io/BIBLE/">الموقع</a> ·
  <a href="https://github.com/akilluminati47/RIPPS2">RIPPS2</a> ·
  <a href="https://github.com/akilluminati47/BIBLE/actions">البنيات</a> ·
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
  <sub>اضغط مطولًا على L2 + R2 عند الإقلاع لصفحة مفاتيح التشغيل، وعلى TRIANGLE + CROSS لصفحة وضع الفيديو؛ والمفتاح المضبوط على <code>$CREDITS</code> يعرض الشكر والتقدير.</sub>
</p>

BIBLE هو محمّل الإقلاع الذي يجهّزه RIPPS2: فرع من PS2BBL Extended الخاص بـ saildot4k.

**ما الذي يغيّره هذا الفرع**

- شاشة البداية: شعار PS2 في وسط سماء RIPPS2، والأزرار تحته وأي نص فوقه. `BIBLE_GLYPHS` 0 لا شيء، 1 أزرار الحركة (الافتراضي)، 2 الستة عشر كلها في صفين من ثمانية. `BIBLE_INFO` 1 يعرض معلومات الجهاز والساعة والعد التنازلي (مطفأ افتراضيًا). السماء تتبع Color Theme في RIPPS2: من دون `BIBLE_COLOR` يقرأ BIBLE السماء التي يحفظها RIPPS2 مع إعداداته، من المجلد الذي يشغّله إدخال AUTO، أو من مجلد `RIPPS2` على بطاقة ذاكرة حين يكون إدخال AUTO هو RIPPS2 على SD2PSX أو USB أو القرص الصلب (`BIBLE_COLOR` في الإعدادات هو المقدَّم). المظهر نفسه في كل وضع فيديو.
- `BIBLE_BACKGROUND`: `AUTO` (الافتراضي: السماء حين توجد إعدادات RIPPS2 أو يُضبط `BIBLE_COLOR`، وإلا أسود بوضع الجهاز نفسه، كمحمّل إقلاع عادي)، `SKY` أو `BLANK` (أسود). الانتقال إلى برنامج أسود لبضع ثوانٍ على أي حال، فيبدو الأسود قطعة واحدة معه.
- صوت الإقلاع، جاهزًا مسبقًا: خيار Boot Sound On (fast) في RIPPS2 يمكنه حفظ `boot.adp` بجانب إعدادات BIBLE (`mc?:/SYS-CONF/boot.adp`). تتم قراءته قبل بدء أي محرك أقراص. ويمكن لـ BIBLE أيضًا تسليمه إلى RIPPS2 في RAM، لكن ذلك لم ينجح إلا في المختبر: على SD2PSX حقيقي قرأ RIPPS2 نسخة البطاقة بنفسه. **الإقلاع الصامت هو الأسرع.** الاتفاق وجانب RIPPS2: [docs/boot-sound-handoff.md](docs/boot-sound-handoff.md).
- RIPPS2 أولًا: قالب الإعدادات (`release/SYS-CONF/PS2BBL.INI`) والقيم المدمجة تجرّب `mc?:/RIPPS2/RIPPS2.ELF` و`mmce?:/APPS/RIPPS2.ELF` قبل OSDMenu وFMCB، ويعدّد القالب مفاتيح BIBLE الخاصة مع ملاحظات. الصفحات (وضع الفيديو، الشكر، مفاتيح التشغيل) تظهر تدريجيًا فوق الشعار الخافت مع إخفاء الأزرار، لتُقرأ مفاتيح التشغيل بهدوء.
- أوضاع الفيديو: يقبل `VIDEO_MODE` أيضًا `576P` و`720P` و`1080I`، أي بقية أوضاع RIPPS2. ويبدأ `AUTO` (الافتراضي)
  في Video Mode الخاص بـ RIPPS2 عندما توجد إعداداته بجوار مدخل AUTO، وإلا ففي وضع الجهاز نفسه.
- `BIBLE_WIDESCREEN`: `AUTO` (الافتراضي: Widescreen في RIPPS2، وإلا فإعداد شاشة 16:9 في PS2)، أو `ON` أو
  `OFF`. في 480i و576i و480p و576p تُرسم شاشة البداية لتلفاز يمدّ الصورة إلى 16:9، دون
  انضغاط. أما 720p و1080i فهما 16:9 أصلًا.
- الانتقال إلى RIPPS2: عند التشغيل يتلاشى الشعار والأزرار وتبقى السماء إلى أن يحمّل الجهاز البرنامج التالي، فتسودّ الشاشة (نحو 7 ثوانٍ في المختبر مع RIPPS2 على بطاقة ذاكرة). ثم يظهر RIPPS2 بوضع الفيديو نفسه والألوان نفسها. اضغط مطولًا على TRIANGLE + CROSS عند الإقلاع لصفحة وضع الفيديو، التي تُفتح دائمًا
  في الوضع المتشابك الخاص بالجهاز (طريق العودة من 720p أو 1080i على كابل مركّب).
- جديد: صفحة مفاتيح التشغيل. اضغط مطوّلًا L2 + R2 عند التشغيل فيتوقف BIBLE قبل تشغيل أي شيء، ويعرض مسارات التشغيل الحالية لكل مفتاح، أيًا كانت إعدادات شاشة البداية (مفيد مع `LOGO_DISPLAY = 0` حيث لا يظهر شيء آخر).
- التركيبات المضغوطة منذ التشغيل تفتح الآن صفحاتها (كان TRIANGLE + CROSS يُفقد بينما كانت أذرع التحكم لا تزال
  تبدأ).
- يُسمح بـ `KEY_READ_WAIT_TIME = 0` (الحد الأدنى في upstream هو 500 ms).
- بنيات PS2 لبطاقة الذاكرة / USB وMMCE وMX4SIO وHDD. المرحلة 2 من eGSM مستبعدة.

**كيف يستخدمه RIPPS2**

يحمل RIPPS2 برنامج BIBLE داخل RIPPS2.elf، وكل إصدار موقّع من akilluminati47، ويثبّته أو يحدّثه من الإعدادات > عام > Boot Loader > Manage، حيث يضبط أيضًا مفاتيح BIBLE: Background وSplash وButton Glyphs وInfo Line وPower-on Wait وVideo Mode وWidescreen. الإصدارات الموقّعة وبطاقة BOOT جاهزة لـ SD2PSX موجودة في [صفحة الإصدارات](https://github.com/akilluminati47/BIBLE/releases/latest). يعمل BIBLE أيضًا كملف ELF يشغّله محمّل آخر (FMCB أو OSDMenu أو محمّل SD2PSX).

<p align="center"><img src="assets/readme/ripps2-icon.png" alt="RIPPS2" width="48" height="48"><br><sub>BIBLE جزء من <a href="https://github.com/akilluminati47/RIPPS2">RIPPS2</a>.</sub></p>

---

<p align="center"><sub>كل ما يلي هو ملف README الأصلي لـ PS2BBL Extended، مترجمًا ومن دون أي تغيير آخر.</sub></p>

---


<br />
<p align="center">
  <a href="https://israpps.github.io/PlayStation2-Basic-BootLoader/">
    <img src="https://github.com/saildot4k/PlayStation2-Basic-BootLoader-Extended/blob/main/assets/ps2bbl_example.png" alt="Logo" width="50%" height="auto">
  </a>

  <p align="center">
    محمّل إقلاع مرن لجهازي PlayStation 2™ وPSX-DESR
    <br />
  </p>
</p>  


هذا فرع من PS2BBL الذي صنعه [El Isra](https://github.com/israpps/PlayStation2-Basic-BootLoader/)


<a id="documentation"></a>

## التوثيق

مستضاف على [github pages](https://israpps.github.io/PlayStation2-Basic-BootLoader/) ولكن مع الإضافات أدناه:

<a id="config-and-arguments"></a>

## الإعداد والوسائط

عدّل ملف الإعداد حسب الحاجة. يُنصح بـ [R3Configurator](https://github.com/saildot4k/R3CONFIGURATOR) لتعديل ملف الإعداد. المسارات مضبوطة مسبقًا لتتوافق مع التنزيلات من [PS2 Homebrew Store](https://ps2homebrewstore.com). لذا لن تحتاج إلا إلى تعديل اختيار Auto، والأفضل ضبط وسائط NHDDL بحسب الجهاز الذي تحمّل منه ملفات ISO.

<a id="config-path-search-order"></a>

### ترتيب البحث عن ملف الإعداد

صار البحث عن الإعداد يراعي عائلة الإقلاع لتجنّب تحميل تعريفات غير ضرورية عند البدء:

1. `CONFIG.INI` (CWD: مجلد العمل الحالي)
2. عند التحميل من جهاز تخزين:
   - إقلاع MMCE: `mmce?:/PS2BBL/CONFIG.INI`
   - إقلاع MX4SIO: `mx4sio:/PS2BBL/CONFIG.INI`
   - إقلاع APA HDD: `hdd0:__sysconf:pfs:/PS2BBL/CONFIG.INI`
   - إقلاع BDM: `usb:/PS2BBL/CONFIG.INI` / `mass:/PS2BBL/CONFIG.INI` / `ata:/PS2BBL/CONFIG.INI`
3. البديل على بطاقة الذاكرة:
   - على PS2: `mc?:/SYS-CONF/PS2BBL.INI`
   - على PSX-DESR: `mc?:/SYS-CONF/PSXBBL.INI`
4. البديل الأخير على PSX
   - `xfrom:/PS2BBL/CONFIG.INI`
5. عند البناء مع `DISC_STOP_AT_BOOT=1
   - `cdrom0:/PS2BBL/CONFIG.INI`
   - البديل على بطاقة الذاكرة كما في البند 3 أعلاه.

<a id="device-path-prefixes"></a>

### بادئات مسارات الأجهزة
يدعم PS2BBL بادئات مسارات التشغيل/الإعداد هذه:
- `mc0:/`, `mc1:/`, `mc?:/`
- `usb:/` (المفضّلة)، و`mass:/` (القديمة)

<a id="build-specific"></a>

#### بحسب البنية:  
- `mmce0:/`، `mmce1:/`، `mmce?:/` __بنيات MMCE__
- `mx4sio:/` (المفضّلة)، و`massX:/` (القديمة)  __بنيات MX4SIO__
- `hdd0:partition:pfs:/<path to elf>` __بنيات HDD__
- مسارات `xfrom:/` __بنيات PSX DESR__
- `ata:/` جهاز BDM لقرص HDD بنظام exFAT
- `ilink:/` (جذور التخزين الكبير عبر BDM) __لم يُنفَّذ بعد__
- `DISC_STOP_AT_BOOT=1` ملف تعريف بناء يوقف القرص الضوئي دائمًا بعد تحميل الإعداد

### LOGO_DISPLAY
استخدم `LOGO_DISPLAY = 3` لعرض أسماء المفاتيح. تُحدَّد الأسماء عبر `NAME_<BUTTON>`.
  - `0` لا شعار ولا معلومات جهاز
  - `1` معلومات الجهاز
  - `2` شعار PS2BBLE/PSXBBLE ومعلومات الجهاز
  - `3` رسم المفاتيح مع `NAME_BUTTON = <TITLE>` المأخوذ من ملف الإعداد
    - مثال:
      ```
      NAME_SQUARE = POPSLOADER
      ```

<a id="custom-splash-logo-from-cwd"></a>

#### شعار بداية مخصّص من CWD
إذا وُجد ملف شعار مخصّص (LOGO.BIN) في CWD (مجلد العمل الحالي)، فإنه يحل محل شعار PS2BBLE/PSXBBLE المدمج.

حوّل ملف PNG إلى الملف الخام المتوقَّع:
  - يجب أن يكون PNG بصيغة RGBA مفهرسة 8 بت، 255 لونًا لكل قناة، وبدقة 256x64.

  - حزمة الإصدار (السكربت في جذر الإصدار):
  ```bash
  python png_to_logo_rbga.py my_logo.png
  ```

  - ضع `LOGO.BIN` الذي أنشأته بجوار PS2BBL Extended. يجب أن يكون `mc?:/BOOT/` إذا كنت تستخدم التنزيلات من [PS2 Homebrew Store](https://ps2store.com)

<a id="retrogem-visual-game-id"></a>

### معرّف اللعبة المرئي من Retrogem
- يفعّل `APP_GAMEID = 1` معرّف اللعبة المرئي للتطبيقات/homebrew، حتى 11 حرفًا مأخوذة من اسم الملف أو قرص PS1/2
- يعطّل `CDROM_DISABLE_GAMEID = 1` معرّف اللعبة المرئي للأقراص المشغَّلة عبر `cdrom`.

<a id="disc-spin-control"></a>

### التحكم في دوران القرص
- مفتاح/قيمة عام: `DISC_STOP = 0/1`
- يوقف `DISC_STOP = 1` القرص الضوئي بعد تحميل الإعداد عند العثور على ملف إعداد.
- يحافظ `DISC_STOP = 0` (أو حذفه) على السلوك الافتراضي.
- يمكن إضافة `-disc_stop` لكل مدخل تشغيل لإيقاف القرص بعد العثور على ملف ELF الهدف.

<a id="video-mode"></a>

### وضع الفيديو
- `VIDEO_MODE = AUTO, NTSC, PAL, 480P` يستخدم الوضع الافتراضي لـ PS2 أو يفرض أحد الأوضاع الثلاثة الأخرى.

<a id="emergency-video-mode-selector"></a>

#### محدِّد وضع الفيديو للطوارئ
- يُفتح بالضغط على `TRIANGLE + CROSS` أثناء الإقلاع
- يفرض المحدِّد `LOGO_DISPLAY = 3` ما دام نشطًا لترى سياق الشعار والمفاتيح.
- التحكم:
  - `LEFT/RIGHT` للتنقل بين الأوضاع: `AUTO`، `NTSC`، `PAL`، `480P`
  - `SELECT` يحفظ الوضع المحدد في ملف الإعداد النشط
  - `START` يخرج من المحدِّد ويتابع إلى عرض المفاتيح

<a id="cdrom-launch-args"></a>

### وسائط تشغيل CDROM
بالنسبة لـ `LK_*_E* = cdrom`، الوسائط المدعومة هي:
- `-nologo`
- `-nogameid`
- `-ps1fast`
- `-ps1smooth`
- `-ps1vneg`
- `-gsm=<v[:c]>`

<a id="ps2logo-arguments-ps2-discs-only"></a>

#### وسائط PS2LOGO (لأقراص PS2 فقط)
- استخدم `cdrom` مسارًا لمدخل التشغيل.
- أضف `-nologo` إلى وسائط المدخل لإقلاع أقراص PS2 مباشرة (تخطّي `rom0:PS2LOGO`).
- من دون `-nologo`، يشغّل PS2BBL القرص عبر PS2LOGO ويرقّعه ليستخدم دائمًا منطقة القرص ويتجاوز فحص المجموع الاختباري للشعار.
- DECKARD IE 75K وما بعده: يُطبَّق XPARAM.IRX تلقائيًا عند الحاجة للتشغيل من دون شعار.

<a id="ps1-disc-arguments-per-launch"></a>

#### وسائط أقراص PS1 (لكل تشغيل)
تنطبق هذه على كل مدخل تشغيل `cdrom`، لا بشكل عام.
- يفعّل `-ps1fast` سرعة القرص السريعة لـ PS1.
- يفعّل `-ps1smooth` تنعيم الخامات.
- يشغّل `-ps1vneg` برنامج PS1DRV عبر PS1VModeNegator. مفيد في الأجهزة التي يختلف فيها وضع الجهاز عن وضع القرص (مثل بعض حالات MechaPwn/الشرائح المعدّلة).

<a id="app-arguments"></a>

### وسائط التطبيقات
استخدم أسطر `ARG_<BUTTON>_E? =` لتمرير الوسائط إلى ملف ELF (انظر أمثلة INI).
- ضع وسائط ملف elf المشغَّل أولًا، ثم أضف بعدها وسائط PS2BBL الداخلية المطلوبة (انظر أدناه). يُعد [NHDDL](https://github.com/pcm720/nhddl) مرشحًا ممتازًا لاستخدام الوسائط، إذ تسرّع إقلاعه.
- يستبدل `-titleid=SLUS_123.45` معرّف عنوان التطبيق (حتى 11 حرفًا).
- يفرض `-appid` معرّف اللعبة المرئي للتطبيق حتى لو كان `APP_GAMEID = 0`.
- يوقف `-disc_stop` القرص بعد تحميل ملف ELF الهدف (مفيد لكل مدخل من دون بنيات `DISC_STOP_AT_BOOT`).
- يشغّل `-gsm=<v[:c]>` ملف ELF الهدف عبر eGSM المدمج (يُتجاهل لمسارات `rom?:`). إذا استُخدم فيجب أن يكون آخر وسيط.
- يُتجاهل `-disc_stop` لمداخل تشغيل `cdrom`.
- يضبط `-dev9=<mode>` سياسة DEV9/HDD قبل تشغيل ملف ELF الهدف. الأوضاع المدعومة:
  - `NICHDD` يبقي كلًّا من DEV9 (محوّل الشبكة) وHDD قيد التشغيل.
  - `NIC` يبقي DEV9/الشبكة قيد التشغيل، ويفك تركيب `pfs0:`، ويضع `hdd0:`/`hdd1:` في الخمول فورًا.
  - إذا حُذف، لا يفرض PS2BBL أي سياسة على DEV9.
  - ملاحظة: في البنيات من دون HDD لا أثر لهذا الخيار.
- يفعّل `-patinfo` معالجة PATINFO لمداخل `:PATINFO`.
  - يقرأ PS2BBL ملف `SYSTEM.CNF` من منطقة سمات القسم (`PS2ICON3D`) ويطبّق `BOOT2/BOOT/path` و`arg*` و`skip_argv0` و`HDDUNITPOWER`.
  - إذا كان `BOOT2/BOOT/path=PATINFO`، يحمّل PS2BBL ملف ELF المدمج من منطقة سمات القسم ويستخدم التسليم الداخلي `-la=E...`.
  - إذا كان `IOPRP=PATINFO` (أو مسارًا مخصّصًا)، يمرّره PS2BBL إلى المرحلة 2 عبر التسليم الداخلي `-la=I...`.
  - إذا وُجد `-patinfo`، يستبدل أول وسيط متبقٍّ هدف `BOOT2/BOOT/path` في CNF.
  هذا لبنيات HDD.  
  مثال PATINFO:  
    ```
    NAME_R1 = My App via PATINFO
    LK_R1_E1 = hdd0:+OSDMENU:PATINFO
    ARG_R1_E1 = pfs:/APPS/MYAPP.ELF
    ARG_R1_E1 = -patinfo               # Tells PS2BBL to use first arg as patinfo boot path.
    ```

مثال لتشغيل NHDDL بوضع الفيديو 480p والبحث عن ملفات ISO على mmce وعلى قرص HDD بنظام exfat من دون الحاجة إلى nhddl.yaml. الفائدة أنه لا يضيع وقت في تحميل التعريفات والعثور على nhddl.yaml وتحميله. هذه أسرع طريقة لإقلاع NHDDL وعرض قائمة ISO.
```
NAME_R1 = NHDDL
LK_R1_E1 = mmce?:/NEUTRINO/nhddl.elf
ARG_R1_E1 = -video=480p
ARG_R1_E1 = -mode=mmce
ARG_R1_E1 = -mode=ata
```

<a id="argument-precedence-and-order"></a>

#### أسبقية الوسائط وترتيبها
1. يحلّل PS2BBL ويستهلك فقط وسائط التحكم الخاصة بالمحمّل في نهاية `ARG_*`: `-appid`، `-titleid=`، `-dev9=`، `-patinfo`، `-disc_stop`، `-gsm=`.
2. يجري التحليل من الأسفل إلى الأعلى ويتوقف عند أول وسيط ليس للتحكم (سلوك نهائي على طريقة OSDMenu).
4. لمسارات التشغيل `:PATINFO`، يحلّل PS2BBL ملف `SYSTEM.CNF` من سمات القسم ويُلحق مداخل `arg*` من CNF بعد وسائط تطبيق المستخدم.
5. إذا ضُبط `-patinfo` واحتوى مسار التشغيل على `:PATINFO`، يصبح أول وسيط متبقٍّ للمستخدم مسار ملف ELF الهدف (يستبدل مسار الإقلاع في CNF) ويُزال من argv التطبيق. وإذا لم يتبقَّ أي وسيط، يُلغى التشغيل (كما في OSDMenu)، ولا يُستخدم `BOOT2/BOOT/path` من CNF.
6. تحافظ الوسائط المتبقية على ترتيبها وتُمرَّر إلى التطبيق المشغَّل.


### eGSM (external Graphics Synthesize Mode)
لأقراص PS2، يُقرأ eGSM تلقائيًا من `OSDGSM.CNF` (لا حاجة لضبط مسار في INI). انظر [هنا](https://github.com/pcm720/OSDMenu/blob/main/patcher/README.md#osdgsmcnf) لمعرفة صيغة ملف الإعداد.

- يشغّل `-gsm=<v[:c]>` ملف ELF الهدف عبر eGSM المدمج (يُتجاهل لمسارات `rom?:`).
  - يُطبَّق eGSM على الهدف المشغَّل (ELF/قرص)، لا على PS2BBL نفسه.
  صيغة eGSM (على طريقة OSDMenu):
- `v` = وضع الفيديو:
- فارغ = لا فرض (الافتراضي)
- `fp1` = فرض المسح التدريجي (240p/288p)
- `fp2` = فرض المسح التدريجي (480p/576p)
- `1080ix1` = فرض 1080i، العرض/الارتفاع x1
- `1080ix2` = فرض 1080i، العرض/الارتفاع x2
- `1080ix3` = فرض 1080i، العرض/الارتفاع x3
- `c` = وضع التوافق:
- فارغ = لا شيء (الافتراضي)
- `1` = قلب الحقول من النوع 1
- `2` = قلب الحقول من النوع 2
- `3` = قلب الحقول من النوع 3

أمثلة على ARG لـ eGSM:
- `-gsm=fp2`
- `-gsm=fp2:1`
- `-gsm=1080ix2`

مثال على الاستخدام:
```
LK_TRIANGLE_E1 = mc0:/APP_WLE-ISR/WLE-ISR.ELF
ARG_TRIANGLE_E1 = -gsm=1080ix2
```

<a id="deprecatedremoved"></a>

## مهمل/محذوف
- ~~`RUNKELF`~~ صار PS2BBLE يتولى تشغيل elf/kelf داخليًا دون أن يحتاج المستخدم إلى تعريف إجراء تشغيل kelf.


<a id="known-bugsissues"></a>

## الأخطاء/المشكلات المعروفة

أخبرني أنت ;)

<a id="credits--thanks"></a>

## الشكر والتقدير

- من saildot4k
  - @israpps على [PS2BBL](https://github.com/israpps/PlayStation2-Basic-BootLoader/)
  - @pcm720 على
    - gameID من Retrogem وPS1 Video Negator وeGSM وشيفرة PS2LOGO من [OSDMenu](https://github.com/pcm720/OSDMenu)
    - خيارات وضع الفيديو من [NHDDL](https://github.com/pcm720/nhddl)
  - @sp193 على [PS1 Video Negator](https://github.com/ps2homebrew/PS1VModeNeg)
  - @nathanneurotic على مسارات PS2BBLE العشرة والأفكار والإقناع
  - [@Berion](https://www.psx-place.com/members/berion.1431/) على الشعارات والخلفية ورسومات المفاتيح

- من [El Isra](https://israpps.github.io/) (مطوّر PS2BBL): 
  - @SP193 على مكتبات تهيئة OSD، التي هي أساس هذا المشروع
  - @asmblur، لتشجيعي على صنع هذا الوحش على أحدث SDK
  - @uyjulian و@fjtrujy لمساعدتي دائمًا


<p align="center"><sub><a href="https://github.com/akilluminati47/RIPPS2">RIPPS2</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2/releases/latest/download/RIPPS2.elf">تنزيل</a> &nbsp;&middot;&nbsp; <b>BIBLE</b> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2-themes">السمات</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPCSX2">RIPPCSX2</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2-fonts">الخطوط</a> &nbsp;&middot;&nbsp; <a href="https://akilluminati47.github.io/RIPPS2/">الموقع</a> &nbsp;&middot;&nbsp; <a href="https://www.psx-place.com/threads/ripps2-a-ps2-front-end-in-one-elf-launch-disc-storage-memory-files.51316/">psx-place</a> &nbsp;&middot;&nbsp; <a href="https://discord.gg/Z7m9u5kby">Discord</a></sub></p>


</div>
