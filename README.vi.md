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
  <a href="README.fa.md">فارسی</a> |
  <a href="README.ja.md">日本語</a> |
  <a href="README.ko.md">한국어</a> |
  <a href="README.zh-CN.md">简体中文</a> |
  <a href="README.zh-TW.md">繁體中文</a> |
  <b>Tiếng Việt</b> |
  <a href="README.lo.md">ລາວ</a> |
  <a href="README.id.md">Bahasa Indonesia</a> |
  <a href="README.fil.md">Filipino</a> |
  <a href="README.ceb.md">Cebuano</a>
</p>
<!-- /i18n -->

<p align="center"><sub>Bản dịch README tiếng Anh; nếu khác nhau, bản tiếng Anh là chuẩn. <a href="README.md">English</a></sub></p>

<p align="center"><sub><a href="https://github.com/akilluminati47/RIPPS2">RIPPS2</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2/releases/latest/download/RIPPS2.elf">Tải về</a> &nbsp;&middot;&nbsp; <b>BIBLE</b> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2-themes">Giao diện</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPCSX2">RIPPCSX2</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2-fonts">Phông chữ</a> &nbsp;&middot;&nbsp; <a href="https://akilluminati47.github.io/RIPPS2/">Trang web</a> &nbsp;&middot;&nbsp; <a href="https://www.psx-place.com/threads/ripps2-a-ps2-front-end-in-one-elf-launch-disc-storage-memory-files.51316/">psx-place</a> &nbsp;&middot;&nbsp; <a href="https://discord.gg/Z7m9u5kby">Discord</a></sub></p>

<h1 align="center">BIBLE</h1>
<p align="center">
  <a href="https://github.com/akilluminati47/RIPPS2">RIPPS2</a> ·
  <a href="https://github.com/akilluminati47/BIBLE/actions">Bản build</a> ·
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
  <sub>Giữ L2 + R2 khi khởi động để mở trang phím khởi chạy, TRIANGLE + CROSS để mở trang chế độ video; phím đặt thành <code>$CREDITS</code> sẽ hiện danh sách ghi công.</sub>
</p>

BIBLE là trình khởi động mà RIPPS2 cài đặt: một bản fork của PS2BBL Extended do saildot4k làm.

**Bản fork này thay đổi gì**

- Màn hình khởi động: logo PS2 ở giữa bầu trời của RIPPS2, các nút ở dưới và chữ (nếu có) ở trên.
  `BIBLE_GLYPHS` 0 không có, 1 các nút mặt trước (mặc định), 2 cả mười sáu nút thành hai hàng tám.
  `BIBLE_INFO` 1 hiện thông tin máy, đồng hồ và đếm ngược (mặc định tắt).
  Bầu trời theo Color Theme của RIPPS2: khi không có `BIBLE_COLOR`, BIBLE đọc bầu trời mà RIPPS2 lưu cùng
  cài đặt của nó, từ thư mục RIPPS2 mà mục AUTO khởi chạy (`BIBLE_COLOR` trong cấu hình được ưu tiên).
  Cùng một giao diện ở mọi chế độ video. Các trang (chế độ video, ghi công, phím khởi chạy) hiện dần trên logo đã làm tối
  với các nút được cất đi, để đọc phím khởi chạy cho thong thả.
- Chế độ video: `VIDEO_MODE` nhận cả `576P`, `720P` và `1080I`, tức các chế độ còn lại của RIPPS2. `AUTO` (mặc định)
  khởi động trong Video Mode của RIPPS2 khi tìm thấy cài đặt của nó cạnh mục AUTO, nếu không thì theo chế độ của máy.
- `BIBLE_WIDESCREEN`: `AUTO` (mặc định: Widescreen của RIPPS2, nếu không thì cài đặt màn hình 16:9 của PS2), `ON` hoặc
  `OFF`. Ở 480i, 576i, 480p và 576p, màn hình khởi động được vẽ cho TV kéo giãn hình ra 16:9, không
  bị bẹp. 720p và 1080i vốn đã là 16:9.
- Không giật khi vào RIPPS2: khi khởi chạy, logo và các nút mờ đi còn bầu trời vẫn ở trên màn hình, trong chế độ của RIPPS2;
  RIPPS2 bắt đầu trên chính bầu trời đó. Giữ TRIANGLE + CROSS khi khởi động để mở trang chế độ video, trang này luôn mở
  ở chế độ xen kẽ của chính máy (đường quay lại từ 720p hoặc 1080i trên dây composite).
- Mới: trang phím khởi chạy. Giữ L2 + R2 khi khởi động để đọc đường dẫn khởi chạy của từng phím, bất kể cài đặt màn hình khởi động.
- Tổ hợp phím giữ từ lúc bật máy giờ mở được trang của chúng (trước đây TRIANGLE + CROSS bị bỏ lỡ khi tay cầm vẫn
  đang khởi động).
- Cho phép `KEY_READ_WAIT_TIME = 0` (mức tối thiểu của upstream là 500 ms).
- Bản build PS2 cho thẻ nhớ / USB, MMCE, MX4SIO và HDD. Giai đoạn 2 của eGSM bị bỏ ra.

**RIPPS2 dùng nó thế nào**

RIPPS2 sẽ mang BIBLE dưới dạng các file khởi động đã ký và cài nó từ Settings (Boot Loader), thay cho PS2BBL 1.2.0 mà nó mang hiện nay. BIBLE cũng chạy như một ELF được trình nạp khác khởi chạy (FMCB, OSDMenu, trình nạp của SD2PSX). Hiện chưa có bản phát hành BIBLE.

<p align="center"><img src="assets/readme/ripps2-icon.png" alt="RIPPS2" width="48" height="48"><br><sub>BIBLE là một phần của <a href="https://github.com/akilluminati47/RIPPS2">RIPPS2</a>.</sub></p>

---

<p align="center"><sub>Mọi thứ bên dưới là README gốc của PS2BBL Extended, được dịch và không thay đổi gì khác.</sub></p>

---


<br />
<p align="center">
  <a href="https://israpps.github.io/PlayStation2-Basic-BootLoader/">
    <img src="https://github.com/saildot4k/PlayStation2-Basic-BootLoader-Extended/blob/main/assets/ps2bbl_example.png" alt="Logo" width="50%" height="auto">
  </a>

  <p align="center">
    Một trình khởi động linh hoạt cho PlayStation 2™ và PSX-DESR
    <br />
  </p>
</p>  


Đây là bản fork của PS2BBL do [El Isra](https://github.com/israpps/PlayStation2-Basic-BootLoader/) làm


<a id="documentation"></a>

## Tài liệu

Tài liệu nằm trên [github pages](https://israpps.github.io/PlayStation2-Basic-BootLoader/) nhưng có thêm các phần bên dưới:

<a id="config-and-arguments"></a>

## Cấu hình và đối số

Sửa file cấu hình khi cần. Nên dùng [R3Configurator](https://github.com/saildot4k/R3CONFIGURATOR) để sửa file cấu hình. Các đường dẫn đã được đặt sẵn khớp với bản tải từ [PS2 Homebrew Store](https://ps2homebrewstore.com). Nghĩa là bạn chỉ cần sửa lựa chọn Auto và tốt nhất là đặt đối số cho NHDDL theo thiết bị bạn nạp ISO.

<a id="config-path-search-order"></a>

### Thứ tự tìm file cấu hình

Việc tìm cấu hình giờ đã nhận biết kiểu khởi động để tránh nạp driver không cần thiết lúc khởi động:

1. `CONFIG.INI` (CWD: thư mục làm việc hiện tại)
2. Khi nạp từ thiết bị:
   - Khởi động MMCE: `mmce?:/PS2BBL/CONFIG.INI`
   - Khởi động MX4SIO: `mx4sio:/PS2BBL/CONFIG.INI`
   - Khởi động APA HDD: `hdd0:__sysconf:pfs:/PS2BBL/CONFIG.INI`
   - Khởi động BDM: `usb:/PS2BBL/CONFIG.INI` / `mass:/PS2BBL/CONFIG.INI` / `ata:/PS2BBL/CONFIG.INI`
3. Dự phòng trên thẻ nhớ:
   - Trên PS2: `mc?:/SYS-CONF/PS2BBL.INI`
   - Trên PSX-DESR: `mc?:/SYS-CONF/PSXBBL.INI`
4. Dự phòng cuối cùng trên PSX
   - `xfrom:/PS2BBL/CONFIG.INI`
5. Khi biên dịch với `DISC_STOP_AT_BOOT=1
   - `cdrom0:/PS2BBL/CONFIG.INI`
   - Dự phòng trên thẻ nhớ như ở mục 3 bên trên.

<a id="device-path-prefixes"></a>

### Tiền tố đường dẫn thiết bị
PS2BBL hỗ trợ các tiền tố đường dẫn khởi chạy/cấu hình sau:
- `mc0:/`, `mc1:/`, `mc?:/`
- `usb:/` (nên dùng) và `mass:/` (cũ)

<a id="build-specific"></a>

#### Tùy bản build:  
- `mmce0:/`, `mmce1:/`, `mmce?:/` __bản build MMCE__
- `mx4sio:/` (nên dùng) và `massX:/` (cũ)  __bản build MX4SIO__
- `hdd0:partition:pfs:/<path to elf>` __bản build HDD__
- Đường dẫn `xfrom:/` __bản build PSX DESR__
- `ata:/` thiết bị BDM cho HDD exFAT
- `ilink:/` (gốc lưu trữ lớn BDM) __chưa được hiện thực__
- `DISC_STOP_AT_BOOT=1` cấu hình biên dịch luôn dừng đĩa quang sau khi nạp cấu hình

### LOGO_DISPLAY
Dùng `LOGO_DISPLAY = 3` để hiện tên phím. Tên được đặt bằng `NAME_<BUTTON>`.
  - `0` Không có logo và thông tin máy
  - `1` Thông tin máy
  - `2` Logo PS2BBLE/PSXBBLE và thông tin máy
  - `3` Đồ họa phím với `NAME_BUTTON = <TITLE>` lấy từ file cấu hình
    - Ví dụ:
      ```
      NAME_SQUARE = POPSLOADER
      ```

<a id="custom-splash-logo-from-cwd"></a>

#### Logo khởi động riêng từ CWD
Nếu tìm thấy file logo riêng (LOGO.BIN) trong CWD (thư mục làm việc hiện tại), nó sẽ thay logo PS2BBLE/PSXBBLE có sẵn.

Chuyển một PNG thành file thô như yêu cầu:
  - PNG phải là RGBA 8 bit có bảng màu, 255 màu mỗi kênh và độ phân giải 256x64.

  - Gói phát hành (script nằm ở gốc gói phát hành):
  ```bash
  python png_to_logo_rbga.py my_logo.png
  ```

  - Đặt `LOGO.BIN` vừa tạo cạnh PS2BBL Extended. Đó nên là `mc?:/BOOT/` nếu bạn dùng bản tải từ [PS2 Homebrew Store](https://ps2store.com)

<a id="retrogem-visual-game-id"></a>

### ID game trực quan của Retrogem
- `APP_GAMEID = 1` bật ID game trực quan cho ứng dụng/homebrew, tối đa 11 ký tự lấy từ tên file hoặc đĩa PS1/2
- `CDROM_DISABLE_GAMEID = 1` tắt ID game trực quan cho đĩa khởi chạy qua `cdrom`.

<a id="disc-spin-control"></a>

### Điều khiển quay đĩa
- Khóa/giá trị chung: `DISC_STOP = 0/1`
- `DISC_STOP = 1` dừng đĩa quang sau khi nạp cấu hình nếu tìm thấy file cấu hình.
- `DISC_STOP = 0` (hoặc bỏ trống) giữ hành vi mặc định.
- Có thể thêm `-disc_stop` vào từng mục khởi chạy để dừng đĩa sau khi tìm thấy ELF đích.

<a id="video-mode"></a>

### Chế độ video
- `VIDEO_MODE = AUTO, NTSC, PAL, 480P` Dùng mặc định của PS2 hoặc ép một trong 3 chế độ còn lại.

<a id="emergency-video-mode-selector"></a>

#### Bộ chọn chế độ video khẩn cấp
- Vào bằng `TRIANGLE + CROSS` trong lúc khởi động
- Bộ chọn ép `LOGO_DISPLAY = 3` khi đang bật để bạn thấy logo và giao diện phím.
- Điều khiển:
  - `LEFT/RIGHT` chuyển chế độ: `AUTO`, `NTSC`, `PAL`, `480P`
  - `SELECT` lưu chế độ đang chọn vào file cấu hình đang dùng
  - `START` thoát bộ chọn và tiếp tục tới màn hình phím

<a id="cdrom-launch-args"></a>

### Đối số khởi chạy CDROM
Với `LK_*_E* = cdrom`, các đối số được hỗ trợ là:
- `-nologo`
- `-nogameid`
- `-ps1fast`
- `-ps1smooth`
- `-ps1vneg`
- `-gsm=<v[:c]>`

<a id="ps2logo-arguments-ps2-discs-only"></a>

#### Đối số PS2LOGO (chỉ đĩa PS2)
- Dùng `cdrom` làm đường dẫn mục khởi chạy.
- Thêm `-nologo` vào đối số của mục để khởi động đĩa PS2 trực tiếp (bỏ qua `rom0:PS2LOGO`).
- Khi không có `-nologo`, PS2BBL chạy đĩa qua PS2LOGO và vá nó để luôn dùng vùng của đĩa và bỏ qua kiểm tra checksum logo.
- DECKARD IE 75K trở về sau: XPARAM.IRX được áp dụng tự động khi cần cho các lần khởi chạy không logo.

<a id="ps1-disc-arguments-per-launch"></a>

#### Đối số đĩa PS1 (mỗi lần khởi chạy)
Các đối số này áp dụng cho từng mục khởi chạy `cdrom`, không phải toàn cục.
- `-ps1fast` bật tốc độ đọc đĩa PS1 nhanh.
- `-ps1smooth` bật làm mịn texture.
- `-ps1vneg` chạy PS1DRV qua PS1VModeNegator. Hữu ích khi chế độ của máy và của đĩa khác nhau (ví dụ một số trường hợp MechaPwn/chip mod).

<a id="app-arguments"></a>

### Đối số ứng dụng
Dùng các dòng `ARG_<BUTTON>_E? =` để truyền đối số cho ELF (xem ví dụ INI).
- Đặt đối số của elf được khởi chạy trước, sau đó thêm các đối số nội bộ của PS2BBL mà bạn muốn (xem bên dưới). [NHDDL](https://github.com/pcm720/nhddl) rất hợp để dùng đối số, vì chúng giúp NHDDL khởi động nhanh hơn.
- `-titleid=SLUS_123.45` thay ID tiêu đề của ứng dụng (tối đa 11 ký tự).
- `-appid` ép ID game trực quan của ứng dụng ngay cả khi `APP_GAMEID = 0`.
- `-disc_stop` dừng đĩa sau khi ELF đích được nạp (hữu ích cho từng mục khi không dùng bản build `DISC_STOP_AT_BOOT`).
- `-gsm=<v[:c]>` chạy ELF đích qua eGSM có sẵn (bị bỏ qua với đường dẫn `rom?:`). Nếu dùng, nó phải là đối số cuối cùng.
- `-disc_stop` bị bỏ qua với các mục khởi chạy `cdrom`.
- `-dev9=<mode>` đặt chính sách DEV9/HDD trước khi khởi chạy ELF đích. Các chế độ được hỗ trợ:
  - `NICHDD` giữ cả DEV9 (bộ chuyển mạng) và HDD đều bật.
  - `NIC` giữ DEV9/mạng bật, gỡ `pfs0:` và cho `hdd0:`/`hdd1:` nghỉ ngay lập tức.
  - nếu bỏ trống, PS2BBL không ép chính sách DEV9 nào.
  - lưu ý: trên bản build không có HDD tùy chọn này không có tác dụng.
- `-patinfo` bật xử lý PATINFO cho các mục `:PATINFO`.
  - PS2BBL đọc `SYSTEM.CNF` từ vùng thuộc tính của phân vùng (`PS2ICON3D`) và áp dụng `BOOT2/BOOT/path`, `arg*`, `skip_argv0` và `HDDUNITPOWER`.
  - nếu `BOOT2/BOOT/path=PATINFO`, PS2BBL nạp ELF nhúng từ vùng thuộc tính của phân vùng và dùng chuyển giao nội bộ `-la=E...`.
  - nếu `IOPRP=PATINFO` (hoặc đường dẫn riêng), PS2BBL chuyển nó cho giai đoạn 2 qua chuyển giao nội bộ `-la=I...`.
  - nếu có `-patinfo`, đối số đầu tiên còn lại sẽ thay đích `BOOT2/BOOT/path` của CNF.
  Phần này dành cho bản build HDD.  
  Ví dụ PATINFO:  
    ```
    NAME_R1 = My App via PATINFO
    LK_R1_E1 = hdd0:+OSDMENU:PATINFO
    ARG_R1_E1 = pfs:/APPS/MYAPP.ELF
    ARG_R1_E1 = -patinfo               # Tells PS2BBL to use first arg as patinfo boot path.
    ```

Ví dụ khởi chạy NHDDL ở chế độ video 480p và tìm ISO trên mmce và HDD exfat mà không cần nhddl.yaml. Lợi ích là không mất thời gian nạp driver, tìm và nạp nhddl.yaml. Đây là cách nhanh nhất để khởi động NHDDL và hiện danh sách ISO.
```
NAME_R1 = NHDDL
LK_R1_E1 = mmce?:/NEUTRINO/nhddl.elf
ARG_R1_E1 = -video=480p
ARG_R1_E1 = -mode=mmce
ARG_R1_E1 = -mode=ata
```

<a id="argument-precedence-and-order"></a>

#### Thứ tự ưu tiên của đối số
1. PS2BBL chỉ phân tích và lấy đi các đối số điều khiển trình nạp ở cuối `ARG_*`: `-appid`, `-titleid=`, `-dev9=`, `-patinfo`, `-disc_stop`, `-gsm=`.
2. Việc phân tích đi từ dưới lên và dừng ở đối số đầu tiên không phải đối số điều khiển (hành vi cuối kiểu OSDMenu).
4. Với đường dẫn khởi chạy `:PATINFO`, PS2BBL phân tích `SYSTEM.CNF` trong thuộc tính phân vùng và nối các mục `arg*` của CNF sau đối số ứng dụng của người dùng.
5. Nếu đặt `-patinfo` và đường dẫn khởi chạy có `:PATINFO`, đối số ứng dụng đầu tiên còn lại của người dùng trở thành đường dẫn ELF đích (thay đường dẫn khởi động của CNF) và bị gỡ khỏi argv của ứng dụng. Nếu không còn đối số nào, việc khởi chạy bị hủy (giống OSDMenu) và `BOOT2/BOOT/path` của CNF không được dùng.
6. Các đối số còn lại giữ nguyên thứ tự và được truyền cho ứng dụng được khởi chạy.


### eGSM (external Graphics Synthesize Mode)
Với đĩa PS2, eGSM được đọc tự động từ `OSDGSM.CNF` (không cần đặt đường dẫn trong INI). Xem [tại đây](https://github.com/pcm720/OSDMenu/blob/main/patcher/README.md#osdgsmcnf) để biết định dạng file cấu hình.

- `-gsm=<v[:c]>` chạy ELF đích qua eGSM có sẵn (bị bỏ qua với đường dẫn `rom?:`).
  - eGSM được áp dụng cho đích được khởi chạy (ELF/đĩa), không phải cho chính PS2BBL.
  Định dạng eGSM (kiểu OSDMenu):
- `v` = chế độ video:
- trống = không ép (mặc định)
- `fp1` = ép quét liên tục (240p/288p)
- `fp2` = ép quét liên tục (480p/576p)
- `1080ix1` = ép 1080i, rộng/cao x1
- `1080ix2` = ép 1080i, rộng/cao x2
- `1080ix3` = ép 1080i, rộng/cao x3
- `c` = chế độ tương thích:
- trống = không có (mặc định)
- `1` = lật trường kiểu 1
- `2` = lật trường kiểu 2
- `3` = lật trường kiểu 3

Ví dụ ARG của eGSM:
- `-gsm=fp2`
- `-gsm=fp2:1`
- `-gsm=1080ix2`

Ví dụ sử dụng:
```
LK_TRIANGLE_E1 = mc0:/APP_WLE-ISR/WLE-ISR.ELF
ARG_TRIANGLE_E1 = -gsm=1080ix2
```

<a id="deprecatedremoved"></a>

## Đã lỗi thời/Đã gỡ bỏ
- ~~`RUNKELF`~~ PS2BBLE giờ tự xử lý việc khởi chạy elf/kelf bên trong, người dùng không cần định nghĩa thao tác khởi chạy kelf.


<a id="known-bugsissues"></a>

## Lỗi/vấn đề đã biết

bạn nói cho tôi đi ;)

<a id="credits--thanks"></a>

## Ghi công và cảm ơn

- Từ saildot4k
  - @israpps cho [PS2BBL](https://github.com/israpps/PlayStation2-Basic-BootLoader/)
  - @pcm720 cho
    - gameID của Retrogem, PS1 Video Negator, eGSM và mã PS2LOGO từ [OSDMenu](https://github.com/pcm720/OSDMenu)
    - các tùy chọn chế độ video từ [NHDDL](https://github.com/pcm720/nhddl)
  - @sp193 cho [PS1 Video Negator](https://github.com/ps2homebrew/PS1VModeNeg)
  - @nathanneurotic cho 10 đường dẫn của PS2BBLE, ý tưởng và sự thuyết phục
  - [@Berion](https://www.psx-place.com/members/berion.1431/) cho logo, nền và đồ họa phím

- Từ [El Isra](https://israpps.github.io/) (nhà phát triển PS2BBL): 
  - @SP193 cho các thư viện khởi tạo OSD, nền móng của dự án này
  - @asmblur, vì đã động viên tôi làm con quái vật này trên SDK mới nhất
  - @uyjulian và @fjtrujy vì luôn giúp đỡ tôi


<p align="center"><sub><a href="https://github.com/akilluminati47/RIPPS2">RIPPS2</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2/releases/latest/download/RIPPS2.elf">Tải về</a> &nbsp;&middot;&nbsp; <b>BIBLE</b> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2-themes">Giao diện</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPCSX2">RIPPCSX2</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2-fonts">Phông chữ</a> &nbsp;&middot;&nbsp; <a href="https://akilluminati47.github.io/RIPPS2/">Trang web</a> &nbsp;&middot;&nbsp; <a href="https://www.psx-place.com/threads/ripps2-a-ps2-front-end-in-one-elf-launch-disc-storage-memory-files.51316/">psx-place</a> &nbsp;&middot;&nbsp; <a href="https://discord.gg/Z7m9u5kby">Discord</a></sub></p>

