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
  <b>Türkçe</b> |
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

<p align="center"><sub>İngilizce README’nin çevirisi; farklılık olursa İngilizce geçerlidir. <a href="README.md">English</a></sub></p>

<p align="center"><sub><a href="https://github.com/akilluminati47/RIPPS2">RIPPS2</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2/releases/latest/download/RIPPS2.elf">İndir</a> &nbsp;&middot;&nbsp; <b>BIBLE</b> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2-themes">Temalar</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPCSX2">RIPPCSX2</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2-fonts">Yazı tipleri</a> &nbsp;&middot;&nbsp; <a href="https://akilluminati47.github.io/RIPPS2/">Web sitesi</a> &nbsp;&middot;&nbsp; <a href="https://www.psx-place.com/threads/ripps2-a-ps2-front-end-in-one-elf-launch-disc-storage-memory-files.51316/">psx-place</a> &nbsp;&middot;&nbsp; <a href="https://discord.gg/Z7m9u5kby">Discord</a></sub></p>

<h1 align="center">BIBLE</h1>
<p align="center">
  <a href="https://akilluminati47.github.io/BIBLE/">Web sitesi</a> ·
  <a href="https://github.com/akilluminati47/RIPPS2">RIPPS2</a> ·
  <a href="https://github.com/akilluminati47/BIBLE/actions">Derlemeler</a> ·
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
  <sub>Başlatma tuşları sayfası için açılışta L2 + R2’yi, video modu sayfası için TRIANGLE + CROSS’u basılı tutun; <code>$CREDITS</code> olarak ayarlanan bir tuş emeği geçenleri gösterir.</sub>
</p>

BIBLE, RIPPS2’nin kurduğu önyükleyicidir: saildot4k’nin PS2BBL Extended’ının bir fork’u.

**Bu fork neyi değiştiriyor**

- Açılış ekranı: PS2 logosu RIPPS2'nin gökyüzünün ortasında, altında düğmeler ve üstünde varsa metin. `BIBLE_GLYPHS` 0 yok, 1 eylem düğmeleri (varsayılan), 2 on altısı da sekizerli iki sırada. `BIBLE_INFO` 1 konsol bilgisini, saati ve geri sayımı gösterir (varsayılan olarak kapalı). Gökyüzü RIPPS2 Color Theme'inize uyar: `BIBLE_COLOR` yoksa BIBLE, RIPPS2'nin ayarlarıyla kaydettiği gökyüzünü AUTO girdisinin başlattığı klasörden ya da AUTO girdisi bir SD2PSX, USB veya sabit diskteki RIPPS2 olduğunda bir hafıza kartının `RIPPS2` klasöründen okur (yapılandırmadaki `BIBLE_COLOR` önceliklidir). Her video modunda aynı görünüm.
- `BIBLE_BACKGROUND`: `AUTO` (varsayılan: RIPPS2'nin ayarları bulunduğunda ya da `BIBLE_COLOR` ayarlıysa gökyüzü, yoksa konsolun kendi modunda siyah, sade bir önyükleyici), `SKY` ya da `BLANK` (siyah). Bir programa geçiş zaten birkaç saniye siyah olur, bu yüzden siyah onunla tek parça gibi görünür.
- Açılış sesi: RIPPS2'nin Boot Sound On (fast) ayarı `boot.adp` dosyasını BIBLE'ın yapılandırmasının yanında tutabilir (`mc?:/SYS-CONF/boot.adp`), ve RIPPS2 onu herhangi bir sürücü başlamadan önce okur. BIBLE onu asla okumaz: RIPPS2'ye yalnızca klasörü söyler. **Sessiz açılış en hızlısıdır.** Anlaşma ve RIPPS2 tarafı: [docs/boot-sound-handoff.md](docs/boot-sound-handoff.md).
- Önce RIPPS2: yapılandırma şablonu (`release/SYS-CONF/PS2BBL.INI`) ve yerleşik varsayılanlar OSDMenu ve FMCB'den önce `mc?:/RIPPS2/RIPPS2.ELF` ve `mmce?:/APPS/RIPPS2.ELF` yollarını dener, şablon da BIBLE'ın kendi anahtarlarını notlarıyla listeler. Sayfalar (video modu, emeği geçenler, başlatma tuşları) düğmeler kaldırılmış, karartılmış logonun üzerinde belirir, böylece başlatma tuşları rahatça okunur.
- Video modları: `VIDEO_MODE` ayrıca `576P`, `720P` ve `1080I` alır, yani RIPPS2’nin geri kalan modlarını. `AUTO` (varsayılan)
  ayarları AUTO girdisinin yanında bulunursa RIPPS2’nin Video Mode’unda, yoksa konsolun kendi modunda başlar.
- `BIBLE_WIDESCREEN`: `AUTO` (varsayılan: RIPPS2’nin Widescreen’i, yoksa PS2’nin 16:9 ekran ayarı), `ON` ya da
  `OFF`. 480i, 576i, 480p ve 576p’de açılış ekranı, resmi 16:9’a geren bir televizyon için çizilir,
  basıklık olmadan. 720p ve 1080i zaten 16:9’dur.
- RIPPS2’ye geçiş: başlatırken logo ve düğmeler kaybolur, gökyüzü konsol sonraki programı yükleyene kadar kalır; bu yükleme ekranı karartır (laboratuvarda, RIPPS2 bir hafıza kartındayken yaklaşık 7 s). Ardından RIPPS2 aynı video modunda ve aynı renklerle gelir. Video modu sayfası için açılışta TRIANGLE + CROSS’u basılı tutun; bu sayfa her zaman
  konsolun kendi geçmeli modunda açılır (kompozit kabloda 720p ya da 1080i’den geri dönüş yolu).
- Yeni: başlatma tuşları sayfası. Açılışta L2 + R2'yi basılı tutun, BIBLE bir şey başlatmadan önce durur ve açılış ekranı ayarlarınız ne olursa olsun her tuşun güncel başlatma yollarını gösterir (`LOGO_DISPLAY = 0` ile kullanışlı, orada başka hiçbir şey görünmez).
- Açılıştan itibaren basılı tutulan kombinasyonlar artık sayfalarını açıyor (kumandalar hâlâ başlarken TRIANGLE + CROSS
  kaçırılıyordu).
- `KEY_READ_WAIT_TIME = 0` artık serbest (upstream’in alt sınırı 500 ms).
- Hafıza kartı / USB, MMCE, MX4SIO ve HDD için PS2 derlemeleri. eGSM aşama 2 dahil edilmedi.

**RIPPS2 onu nasıl kullanıyor**

RIPPS2, BIBLE'ı RIPPS2.elf içinde taşır, her sürüm akilluminati47 tarafından imzalanmıştır, ve onu Ayarlar > Genel > Boot Loader > Manage'den kurar ya da günceller; burada BIBLE'ın anahtarlarını da ayarlar: Background, Splash, Button Glyphs, Info Line, Power-on Wait, Video Mode ve Widescreen. İmzalı sürümler ve hazır bir SD2PSX BOOT kartı [sürümler sayfasında](https://github.com/akilluminati47/BIBLE/releases/latest). BIBLE başka bir yükleyicinin başlattığı bir ELF olarak da çalışır (FMCB, OSDMenu, bir SD2PSX'in yükleyicisi).

<p align="center"><img src="assets/readme/ripps2-icon.png" alt="RIPPS2" width="48" height="48"><br><sub>BIBLE, <a href="https://github.com/akilluminati47/RIPPS2">RIPPS2</a> projesinin bir parçasıdır.</sub></p>

---

<p align="center"><sub>Aşağıdaki her şey PS2BBL Extended’ın orijinal README’sidir; çevrildi, başka bir şey değişmedi.</sub></p>

---


<br />
<p align="center">
  <a href="https://israpps.github.io/PlayStation2-Basic-BootLoader/">
    <img src="https://github.com/saildot4k/PlayStation2-Basic-BootLoader-Extended/blob/main/assets/ps2bbl_example.png" alt="Logo" width="50%" height="auto">
  </a>

  <p align="center">
    PlayStation 2™ ve PSX-DESR için esnek bir önyükleyici
    <br />
  </p>
</p>  


Bu, [El Isra](https://github.com/israpps/PlayStation2-Basic-BootLoader/) tarafından yapılan PS2BBL’ın bir fork’udur


<a id="documentation"></a>

## Belgeler

[github pages](https://israpps.github.io/PlayStation2-Basic-BootLoader/) üzerinde barındırılıyor, ancak aşağıdaki eklemelerle:

<a id="config-and-arguments"></a>

## Yapılandırma ve argümanlar

Yapılandırma dosyasını gerektiği gibi düzenleyin. Düzenlemek için [R3Configurator](https://github.com/saildot4k/R3CONFIGURATOR) önerilir. Yollar zaten [PS2 Homebrew Store](https://ps2homebrewstore.com) indirmeleriyle uyumlu olacak şekilde ayarlı. Yani yalnızca Auto seçiminizi düzenlemeniz ve en iyisi ISO yüklediğiniz aygıta göre NHDDL argümanlarını ayarlamanız yeterli olmalı.

<a id="config-path-search-order"></a>

### Yapılandırma arama sırası

Yapılandırma araması artık açılışta gereksiz sürücüler yüklenmesin diye önyükleme ailesini dikkate alıyor:

1. `CONFIG.INI` (CWD: geçerli çalışma dizini)
2. Bir aygıttan yüklendiğinde:
   - MMCE önyüklemesi: `mmce?:/PS2BBL/CONFIG.INI`
   - MX4SIO önyüklemesi: `mx4sio:/PS2BBL/CONFIG.INI`
   - APA HDD önyüklemesi: `hdd0:__sysconf:pfs:/PS2BBL/CONFIG.INI`
   - BDM önyüklemesi: `usb:/PS2BBL/CONFIG.INI` / `mass:/PS2BBL/CONFIG.INI` / `ata:/PS2BBL/CONFIG.INI`
3. Hafıza kartı yedeği:
   - PS2’de: `mc?:/SYS-CONF/PS2BBL.INI`
   - PSX-DESR’de: `mc?:/SYS-CONF/PSXBBL.INI`
4. PSX’te son yedek
   - `xfrom:/PS2BBL/CONFIG.INI`
5. `DISC_STOP_AT_BOOT=1 ile derlendiğinde
   - `cdrom0:/PS2BBL/CONFIG.INI`
   - Yukarıdaki 3. maddede tanımlandığı gibi hafıza kartı yedeği.

<a id="device-path-prefixes"></a>

### Aygıt yolu önekleri
PS2BBL şu başlatma/yapılandırma yolu öneklerini destekler:
- `mc0:/`, `mc1:/`, `mc?:/`
- `usb:/` (tercih edilen) ve `mass:/` (eski)

<a id="build-specific"></a>

#### Derlemeye özel:  
- `mmce0:/`, `mmce1:/`, `mmce?:/` __MMCE derlemeleri__
- `mx4sio:/` (tercih edilen) ve `massX:/` (eski)  __MX4SIO derlemeleri__
- `hdd0:partition:pfs:/<path to elf>` __HDD derlemeleri__
- `xfrom:/` yolları __PSX DESR derlemeleri__
- `ata:/` exFAT HDD için BDM aygıtı
- `ilink:/` (BDM yığın depolama kökleri) __henüz uygulanmadı__
- `DISC_STOP_AT_BOOT=1` yapılandırma yüklendikten sonra optik diski her zaman durduran derleme profili

### LOGO_DISPLAY
Tuş adlarını göstermek için `LOGO_DISPLAY = 3` kullanın. Adlar `NAME_<BUTTON>` ile tanımlanır.
  - `0` Logo ve konsol bilgisi yok
  - `1` Konsol bilgisi
  - `2` PS2BBLE/PSXBBLE logosu ve konsol bilgisi
  - `3` Yapılandırma dosyasındaki `NAME_BUTTON = <TITLE>` ile tuş grafiği
    - Örnek:
      ```
      NAME_SQUARE = POPSLOADER
      ```

<a id="custom-splash-logo-from-cwd"></a>

#### CWD’den özel açılış logosu
CWD’de (geçerli çalışma dizini) özel bir logo dosyası (LOGO.BIN) bulunursa, yerleşik PS2BBLE/PSXBBLE logosunun yerini alır.

Bir PNG’yi beklenen ham dosyaya dönüştürün:
  - PNG, RGBA 8 bit dizinli, kanal başına 255 renk ve 256x64 çözünürlükte olmalı.

  - Sürüm paketi (betik sürümün kök klasöründe):
  ```bash
  python png_to_logo_rbga.py my_logo.png
  ```

  - Oluşturulan `LOGO.BIN` dosyasını PS2BBL Extended’ın yanına koyun. [PS2 Homebrew Store](https://ps2store.com) indirmelerini kullanıyorsanız bu `mc?:/BOOT/` olmalı

<a id="retrogem-visual-game-id"></a>

### Retrogem görsel oyun kimliği
- `APP_GAMEID = 1`, dosya adından ya da PS1/2 diskinden alınan en fazla 11 karakterle uygulamalar/homebrew için görsel oyun kimliğini açar
- `CDROM_DISABLE_GAMEID = 1`, `cdrom` ile başlatılan diskler için görsel oyun kimliğini kapatır.

<a id="disc-spin-control"></a>

### Disk dönüş denetimi
- Genel anahtar/değer: `DISC_STOP = 0/1`
- `DISC_STOP = 1`, bir yapılandırma dosyası bulunduğunda yapılandırma yüklendikten sonra optik diski durdurur.
- `DISC_STOP = 0` (ya da yazılmazsa) varsayılan davranışı korur.
- `-disc_stop`, hedef ELF bulunduktan sonra diski durdurmak için her başlatma girdisine eklenebilir.

<a id="video-mode"></a>

### Video Modu
- `VIDEO_MODE = AUTO, NTSC, PAL, 480P` PS2 varsayılanını kullanır ya da diğer 3 moddan birini zorlar.

<a id="emergency-video-mode-selector"></a>

#### Acil durum video modu seçicisi
- Önyükleme sırasında `TRIANGLE + CROSS` ile açılır
- Seçici etkinken `LOGO_DISPLAY = 3` zorlanır, böylece logo ve tuş arayüzünü görebilirsiniz.
- Kontroller:
  - `LEFT/RIGHT` modlar arasında geçiş yapar: `AUTO`, `NTSC`, `PAL`, `480P`
  - `SELECT` seçili modu etkin yapılandırma dosyasına kaydeder
  - `START` seçiciden çıkar ve tuş ekranına geçer

<a id="cdrom-launch-args"></a>

### CDROM başlatma argümanları
`LK_*_E* = cdrom` için desteklenen argümanlar:
- `-nologo`
- `-nogameid`
- `-ps1fast`
- `-ps1smooth`
- `-ps1vneg`
- `-gsm=<v[:c]>`

<a id="ps2logo-arguments-ps2-discs-only"></a>

#### PS2LOGO argümanları (yalnızca PS2 diskleri)
- Başlatma girdisi yolu olarak `cdrom` kullanın.
- PS2 disklerini doğrudan başlatmak için girdi argümanlarına `-nologo` ekleyin (`rom0:PS2LOGO` atlanır).
- `-nologo` olmadan PS2BBL diski PS2LOGO üzerinden çalıştırır ve her zaman disk bölgesini kullanması ve logo sağlama toplamı denetimlerini atlaması için yamalar.
- DECKARD IE 75K ve sonrası: logosuz başlatmalarda gerektiğinde XPARAM.IRX otomatik uygulanır.

<a id="ps1-disc-arguments-per-launch"></a>

#### PS1 disk argümanları (başlatma başına)
Bunlar genel değil, her `cdrom` başlatma girdisi için ayrı ayrı geçerlidir.
- `-ps1fast` hızlı PS1 disk hızını açar.
- `-ps1smooth` doku yumuşatmayı açar.
- `-ps1vneg` PS1DRV’yi PS1VModeNegator üzerinden çalıştırır. Konsol modu ile disk modunun farklı olduğu kurulumlarda işe yarar (örneğin bazı MechaPwn/modchip durumları).

<a id="app-arguments"></a>

### Uygulama argümanları
Bir ELF’e argüman geçmek için `ARG_<BUTTON>_E? =` satırlarını kullanın (INI örneklerine bakın).
- Önce başlatılan elf’in argümanlarını yazın, ardından istediğiniz dahili PS2BBL argümanlarını ekleyin (aşağıya bakın). [NHDDL](https://github.com/pcm720/nhddl) argüman kullanmak için harika bir aday, çünkü argümanlar NHDDL’ın açılışını hızlandırır.
- `-titleid=SLUS_123.45` uygulamanın başlık kimliğini değiştirir (en fazla 11 karakter).
- `-appid`, `APP_GAMEID = 0` olsa bile uygulamanın görsel oyun kimliğini zorlar.
- `-disc_stop` hedef ELF yüklendikten sonra diski durdurur (`DISC_STOP_AT_BOOT` derlemeleri olmadan girdi başına işe yarar).
- `-gsm=<v[:c]>` hedef ELF’i yerleşik eGSM üzerinden çalıştırır (`rom?:` yollarında yok sayılır). Kullanılırsa son argüman olmalıdır.
- `-disc_stop`, `cdrom` başlatma girdilerinde yok sayılır.
- `-dev9=<mode>` hedef ELF başlatılmadan önce DEV9/HDD politikasını ayarlar. Desteklenen modlar:
  - `NICHDD` hem DEV9’u (ağ bağdaştırıcısı) hem HDD’yi açık tutar.
  - `NIC` DEV9’u/ağı açık tutar, `pfs0:` bağlantısını kaldırır ve `hdd0:`/`hdd1:` diskini hemen beklemeye alır.
  - yazılmazsa PS2BBL bir DEV9 politikası zorlamaz.
  - not: HDD olmayan derlemelerde bu seçeneğin etkisi yoktur.
- `-patinfo`, `:PATINFO` girdileri için PATINFO işlemeyi açar.
  - PS2BBL, `SYSTEM.CNF` dosyasını bölümün öznitelik alanından (`PS2ICON3D`) okur ve `BOOT2/BOOT/path`, `arg*`, `skip_argv0` ile `HDDUNITPOWER` değerlerini uygular.
  - `BOOT2/BOOT/path=PATINFO` ise PS2BBL gömülü ELF’i bölümün öznitelik alanından yükler ve dahili `-la=E...` devrini kullanır.
  - `IOPRP=PATINFO` (ya da özel bir yol) ise PS2BBL onu dahili `-la=I...` devriyle 2. aşamaya geçirir.
  - `-patinfo` varsa kalan ilk argüman, CNF’nin `BOOT2/BOOT/path` hedefinin yerini alır.
  Bu, HDD derlemeleri içindir.  
  PATINFO örneği:  
    ```
    NAME_R1 = My App via PATINFO
    LK_R1_E1 = hdd0:+OSDMENU:PATINFO
    ARG_R1_E1 = pfs:/APPS/MYAPP.ELF
    ARG_R1_E1 = -patinfo               # Tells PS2BBL to use first arg as patinfo boot path.
    ```

NHDDL’ı 480p video modunda başlatıp nhddl.yaml gerekmeden mmce ve exfat HDD’de ISO arayan örnek. Avantajı, sürücü yüklemeye ve nhddl.yaml’ı bulup yüklemeye zaman harcanmamasıdır. NHDDL’ı başlatıp ISO listesini göstermenin en hızlı yolu budur.
```
NAME_R1 = NHDDL
LK_R1_E1 = mmce?:/NEUTRINO/nhddl.elf
ARG_R1_E1 = -video=480p
ARG_R1_E1 = -mode=mmce
ARG_R1_E1 = -mode=ata
```

<a id="argument-precedence-and-order"></a>

#### Argüman önceliği ve sırası
1. PS2BBL, `ARG_*` içinden yalnızca sondaki yükleyici denetim argümanlarını ayrıştırır ve tüketir: `-appid`, `-titleid=`, `-dev9=`, `-patinfo`, `-disc_stop`, `-gsm=`.
2. Ayrıştırma aşağıdan yukarıya yapılır ve denetim argümanı olmayan ilk argümanda durur (OSDMenu tarzı son davranış).
4. `:PATINFO` başlatma yollarında PS2BBL, bölüm özniteliğindeki `SYSTEM.CNF` dosyasını ayrıştırır ve CNF’nin `arg*` girdilerini kullanıcının uygulama argümanlarının ardına ekler.
5. `-patinfo` ayarlıysa ve başlatma yolu `:PATINFO` içeriyorsa, kullanıcının kalan ilk uygulama argümanı hedef ELF yolu olur (CNF önyükleme yolunun yerini alır) ve uygulamanın argv’sinden çıkarılır. Hiç argüman kalmazsa başlatma iptal edilir (OSDMenu ile aynı) ve CNF’nin `BOOT2/BOOT/path` değeri kullanılmaz.
6. Kalan argümanlar sıralarını korur ve başlatılan uygulamaya geçirilir.


### eGSM (external Graphics Synthesize Mode)
PS2 disklerinde eGSM, `OSDGSM.CNF` dosyasından otomatik okunur (INI’de yol ayarı gerekmez). Yapılandırma dosyası biçimi için [buraya](https://github.com/pcm720/OSDMenu/blob/main/patcher/README.md#osdgsmcnf) bakın.

- `-gsm=<v[:c]>` hedef ELF’i yerleşik eGSM üzerinden çalıştırır (`rom?:` yollarında yok sayılır).
  - eGSM, PS2BBL’ın kendisine değil, başlatılan hedefe (ELF/disk) uygulanır.
  eGSM biçimi (OSDMenu tarzı):
- `v` = video modu:
- boş = zorlama yok (varsayılan)
- `fp1` = aşamalı taramayı zorla (240p/288p)
- `fp2` = aşamalı taramayı zorla (480p/576p)
- `1080ix1` = 1080i’yi zorla, genişlik/yükseklik x1
- `1080ix2` = 1080i’yi zorla, genişlik/yükseklik x2
- `1080ix3` = 1080i’yi zorla, genişlik/yükseklik x3
- `c` = uyumluluk modu:
- boş = yok (varsayılan)
- `1` = alan çevirme türü 1
- `2` = alan çevirme türü 2
- `3` = alan çevirme türü 3

eGSM ARG örnekleri:
- `-gsm=fp2`
- `-gsm=fp2:1`
- `-gsm=1080ix2`

Kullanım örneği:
```
LK_TRIANGLE_E1 = mc0:/APP_WLE-ISR/WLE-ISR.ELF
ARG_TRIANGLE_E1 = -gsm=1080ix2
```

<a id="deprecatedremoved"></a>

## Kullanımdan kaldırılan/Silinen
- ~~`RUNKELF`~~ PS2BBLE artık elf/kelf başlatmayı kendi içinde hallediyor, kullanıcının bir kelf başlatma eylemi tanımlaması gerekmiyor.


<a id="known-bugsissues"></a>

## Bilinen hatalar/sorunlar

siz söyleyin ;)

<a id="credits--thanks"></a>

## Emeği geçenler ve teşekkürler

- saildot4k’den
  - [PS2BBL](https://github.com/israpps/PlayStation2-Basic-BootLoader/) için @israpps
  - @pcm720:
    - [OSDMenu](https://github.com/pcm720/OSDMenu) içinden Retrogem gameID, PS1 Video Negator, eGSM ve PS2LOGO kodu
    - [NHDDL](https://github.com/pcm720/nhddl) içinden video modu seçenekleri
  - [PS1 Video Negator](https://github.com/ps2homebrew/PS1VModeNeg) için @sp193
  - PS2BBLE’ın 10 yolu, fikirler ve ikna için @nathanneurotic
  - Logolar, arka plan ve tuş grafikleri için [@Berion](https://www.psx-place.com/members/berion.1431/)

- [El Isra](https://israpps.github.io/)’dan (PS2BBL geliştiricisi): 
  - Bu projenin temeli olan OSD başlatma kütüphaneleri için @SP193
  - Bu canavarı en yeni SDK ile yapmam için beni yüreklendiren @asmblur
  - Bana her zaman yardım eden @uyjulian ve @fjtrujy


<p align="center"><sub><a href="https://github.com/akilluminati47/RIPPS2">RIPPS2</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2/releases/latest/download/RIPPS2.elf">İndir</a> &nbsp;&middot;&nbsp; <b>BIBLE</b> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2-themes">Temalar</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPCSX2">RIPPCSX2</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2-fonts">Yazı tipleri</a> &nbsp;&middot;&nbsp; <a href="https://akilluminati47.github.io/RIPPS2/">Web sitesi</a> &nbsp;&middot;&nbsp; <a href="https://www.psx-place.com/threads/ripps2-a-ps2-front-end-in-one-elf-launch-disc-storage-memory-files.51316/">psx-place</a> &nbsp;&middot;&nbsp; <a href="https://discord.gg/Z7m9u5kby">Discord</a></sub></p>

