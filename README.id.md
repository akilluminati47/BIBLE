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
  <a href="README.vi.md">Tiếng Việt</a> |
  <a href="README.lo.md">ລາວ</a> |
  <b>Bahasa Indonesia</b> |
  <a href="README.fil.md">Filipino</a> |
  <a href="README.ceb.md">Cebuano</a>
</p>
<!-- /i18n -->

<p align="center"><sub>Terjemahan README bahasa Inggris; jika berbeda, yang berlaku bahasa Inggris. <a href="README.md">English</a></sub></p>

<p align="center"><sub><a href="https://github.com/akilluminati47/RIPPS2">RIPPS2</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2/releases/latest/download/RIPPS2.elf">Unduh</a> &nbsp;&middot;&nbsp; <b>BIBLE</b> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2-themes">Tema</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPCSX2">RIPPCSX2</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2-fonts">Fon</a> &nbsp;&middot;&nbsp; <a href="https://akilluminati47.github.io/RIPPS2/">Situs</a> &nbsp;&middot;&nbsp; <a href="https://www.psx-place.com/threads/ripps2-a-ps2-front-end-in-one-elf-launch-disc-storage-memory-files.51316/">psx-place</a> &nbsp;&middot;&nbsp; <a href="https://discord.gg/Z7m9u5kby">Discord</a></sub></p>

<h1 align="center">BIBLE</h1>
<p align="center">
  <a href="https://github.com/akilluminati47/RIPPS2">RIPPS2</a> ·
  <a href="https://github.com/akilluminati47/BIBLE/actions">Build</a> ·
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
  <sub>Tahan L2 + R2 saat menyala untuk halaman tombol peluncuran, TRIANGLE + CROSS untuk halaman mode video; tombol yang diatur ke <code>$CREDITS</code> menampilkan kredit.</sub>
</p>

BIBLE adalah boot loader yang dipasang RIPPS2: fork dari PS2BBL Extended milik saildot4k.

**Apa yang diubah fork ini**

- Layar pembuka: logo PS2 di tengah langit RIPPS2, dengan tombol di bawahnya dan teks apa pun di atasnya.
  `BIBLE_GLYPHS` 0 tidak ada, 1 tombol muka (bawaan), 2 keenam belas tombol dalam dua baris berisi delapan.
  `BIBLE_INFO` 1 menampilkan info konsol, jam, dan hitung mundur (mati secara bawaan).
  Langitnya mengikuti Color Theme RIPPS2 Anda: tanpa `BIBLE_COLOR`, BIBLE membaca langit yang disimpan RIPPS2 bersama
  pengaturannya, dari folder RIPPS2 yang dijalankan entri AUTO-nya (`BIBLE_COLOR` di konfigurasi lebih diutamakan).
  Tampilan yang sama di setiap mode video. Halaman (mode video, kredit, tombol peluncuran) muncul perlahan di atas logo yang diredupkan
  dengan tombol disingkirkan, agar tombol peluncuran bisa dibaca dengan tenang.
- Mode video: `VIDEO_MODE` juga menerima `576P`, `720P`, dan `1080I`, sisa mode milik RIPPS2. `AUTO` (bawaan)
  mulai di Video Mode RIPPS2 bila pengaturannya ada di samping entri AUTO, jika tidak di mode konsol itu sendiri.
- `BIBLE_WIDESCREEN`: `AUTO` (bawaan: Widescreen RIPPS2, jika tidak pengaturan layar 16:9 PS2), `ON` atau
  `OFF`. Di 480i, 576i, 480p, dan 576p layar pembuka digambar untuk TV yang meregangkan gambar ke 16:9, tanpa
  gepeng. 720p dan 1080i sudah 16:9.
- Tidak ada lompatan saat masuk ke RIPPS2: saat peluncuran, logo dan tombol memudar dan langit tetap di layar, dalam mode RIPPS2;
  RIPPS2 mulai di langit yang sama. Tahan TRIANGLE + CROSS saat menyala untuk halaman mode video, yang selalu terbuka di
  mode interlaced konsol itu sendiri (jalan kembali dari 720p atau 1080i pada kabel komposit).
- Baru: halaman tombol peluncuran. Tahan L2 + R2 saat menyala untuk membaca jalur peluncuran setiap tombol, apa pun pengaturan layar pembuka Anda.
- Kombinasi yang ditahan sejak dinyalakan kini membuka halamannya (TRIANGLE + CROSS dulu terlewat saat controller masih
  menyala).
- `KEY_READ_WAIT_TIME = 0` diizinkan (batas bawah upstream adalah 500 ms).
- Build PS2 untuk kartu memori / USB, MMCE, MX4SIO, dan HDD. eGSM tahap 2 tidak disertakan.

**Cara RIPPS2 memakainya**

RIPPS2 akan membawa BIBLE sebagai file boot yang ditandatangani dan memasangnya dari Settings (Boot Loader), menggantikan PS2BBL 1.2.0 yang dibawanya saat ini. BIBLE juga berjalan sebagai ELF yang dijalankan loader lain (FMCB, OSDMenu, loader milik SD2PSX). Belum ada rilis BIBLE.

<p align="center"><img src="assets/readme/ripps2-icon.png" alt="RIPPS2" width="48" height="48"><br><sub>BIBLE adalah bagian dari <a href="https://github.com/akilluminati47/RIPPS2">RIPPS2</a>.</sub></p>

---

<p align="center"><sub>Semua di bawah ini adalah README asli PS2BBL Extended, diterjemahkan tanpa perubahan lain.</sub></p>

---


<br />
<p align="center">
  <a href="https://israpps.github.io/PlayStation2-Basic-BootLoader/">
    <img src="https://github.com/saildot4k/PlayStation2-Basic-BootLoader-Extended/blob/main/assets/ps2bbl_example.png" alt="Logo" width="50%" height="auto">
  </a>

  <p align="center">
    Boot loader fleksibel untuk PlayStation 2™ dan PSX-DESR
    <br />
  </p>
</p>  


Ini adalah fork dari PS2BBL oleh [El Isra](https://github.com/israpps/PlayStation2-Basic-BootLoader/)


## Dokumentasi

Dihosting di [github pages](https://israpps.github.io/PlayStation2-Basic-BootLoader/) tetapi dengan tambahan di bawah:

## Konfigurasi dan argumen

Sunting file konfigurasi sesuai kebutuhan. Disarankan [R3Configurator](https://github.com/saildot4k/R3CONFIGURATOR) untuk menyuntingnya. Jalur sudah diatur agar cocok dengan unduhan dari [PS2 Homebrew Store](https://ps2homebrewstore.com). Jadi Anda cukup menyunting pilihan Auto dan sebaiknya mengatur argumen NHDDL sesuai perangkat tempat Anda memuat ISO.

### Urutan pencarian konfigurasi

Pencarian konfigurasi kini mengenali keluarga boot agar tidak memuat driver yang tidak perlu saat mulai:

1. `CONFIG.INI` (CWD: direktori kerja saat ini)
2. Saat dimuat dari perangkat:
   - Boot MMCE: `mmce?:/PS2BBL/CONFIG.INI`
   - Boot MX4SIO: `mx4sio:/PS2BBL/CONFIG.INI`
   - Boot APA HDD: `hdd0:__sysconf:pfs:/PS2BBL/CONFIG.INI`
   - Boot BDM: `usb:/PS2BBL/CONFIG.INI` / `mass:/PS2BBL/CONFIG.INI` / `ata:/PS2BBL/CONFIG.INI`
3. Cadangan di kartu memori:
   - Di PS2: `mc?:/SYS-CONF/PS2BBL.INI`
   - Di PSX-DESR: `mc?:/SYS-CONF/PSXBBL.INI`
4. Cadangan terakhir di PSX
   - `xfrom:/PS2BBL/CONFIG.INI`
5. Bila dikompilasi dengan `DISC_STOP_AT_BOOT=1
   - `cdrom0:/PS2BBL/CONFIG.INI`
   - Cadangan di kartu memori seperti poin 3 di atas.

### Awalan jalur perangkat
PS2BBL mendukung awalan jalur peluncuran/konfigurasi berikut:
- `mc0:/`, `mc1:/`, `mc?:/`
- `usb:/` (disarankan), dan `mass:/` (lama)

#### Khusus build:  
- `mmce0:/`, `mmce1:/`, `mmce?:/` __build MMCE__
- `mx4sio:/` (disarankan), dan `massX:/` (lama)  __build MX4SIO__
- `hdd0:partition:pfs:/<path to elf>` __build HDD__
- Jalur `xfrom:/` __build PSX DESR__
- `ata:/` perangkat BDM HDD exFAT
- `ilink:/` (akar penyimpanan massal BDM) __belum diterapkan__
- `DISC_STOP_AT_BOOT=1` profil kompilasi yang selalu menghentikan disk optik setelah konfigurasi dimuat

### LOGO_DISPLAY
Gunakan `LOGO_DISPLAY = 3` untuk menampilkan nama tombol. Nama diatur oleh `NAME_<BUTTON>`.
  - `0` Tanpa logo dan info konsol
  - `1` Info konsol
  - `2` Logo PS2BBLE/PSXBBLE dan info konsol
  - `3` Grafik tombol dengan `NAME_BUTTON = <TITLE>` dari file konfigurasi
    - Contoh:
      ```
      NAME_SQUARE = POPSLOADER
      ```

#### Logo pembuka kustom dari CWD
Jika file logo kustom (LOGO.BIN) ditemukan di CWD (direktori kerja saat ini), file itu menggantikan logo PS2BBLE/PSXBBLE bawaan.

Ubah PNG menjadi file mentah yang diharapkan:
  - PNG harus RGBA 8 bit berindeks, 255 warna per kanal, dan resolusi 256x64.

  - Paket rilis (skrip ada di akar rilis):
  ```bash
  python png_to_logo_rbga.py my_logo.png
  ```

  - Letakkan `LOGO.BIN` yang dibuat di samping PS2BBL Extended. Seharusnya `mc?:/BOOT/` jika memakai unduhan dari [PS2 Homebrew Store](https://ps2store.com)

### ID game visual Retrogem
- `APP_GAMEID = 1` menyalakan ID game visual untuk aplikasi/homebrew, hingga 11 karakter dari nama file atau disk PS1/2
- `CDROM_DISABLE_GAMEID = 1` mematikan ID game visual untuk disk yang diluncurkan lewat `cdrom`.

### Kendali putaran disk
- Kunci/nilai global: `DISC_STOP = 0/1`
- `DISC_STOP = 1` menghentikan disk optik setelah konfigurasi dimuat bila file konfigurasi ditemukan.
- `DISC_STOP = 0` (atau dihilangkan) mempertahankan perilaku bawaan.
- `-disc_stop` bisa ditambahkan per entri peluncuran untuk menghentikan disk setelah ELF tujuan ditemukan.

### Mode Video
- `VIDEO_MODE = AUTO, NTSC, PAL, 480P` Memakai bawaan PS2 atau memaksa salah satu dari 3 mode lainnya.

#### Pemilih mode video darurat
- Masuk dengan `TRIANGLE + CROSS` saat boot
- Pemilih memaksa `LOGO_DISPLAY = 3` selama aktif agar Anda bisa melihat konteks logo/tombol.
- Kontrol:
  - `LEFT/RIGHT` mengganti mode: `AUTO`, `NTSC`, `PAL`, `480P`
  - `SELECT` menyimpan mode yang dipilih ke file konfigurasi aktif
  - `START` keluar dari pemilih dan lanjut ke tampilan tombol

### Argumen peluncuran CDROM
Untuk `LK_*_E* = cdrom`, argumen yang didukung adalah:
- `-nologo`
- `-nogameid`
- `-ps1fast`
- `-ps1smooth`
- `-ps1vneg`
- `-gsm=<v[:c]>`

#### Argumen PS2LOGO (hanya disk PS2)
- Gunakan `cdrom` sebagai jalur entri peluncuran.
- Tambahkan `-nologo` ke argumen entri untuk mem-boot disk PS2 langsung (melewati `rom0:PS2LOGO`).
- Tanpa `-nologo`, PS2BBL menjalankan disk lewat PS2LOGO dan menambalnya agar selalu memakai region disk dan melewati pemeriksaan checksum logo.
- DECKARD IE 75K dan sesudahnya: XPARAM.IRX diterapkan otomatis bila dibutuhkan untuk peluncuran tanpa logo.

#### Argumen disk PS1 (per peluncuran)
Ini berlaku per entri peluncuran `cdrom`, bukan secara global.
- `-ps1fast` menyalakan kecepatan disk PS1 cepat.
- `-ps1smooth` menyalakan penghalusan tekstur.
- `-ps1vneg` menjalankan PS1DRV lewat PS1VModeNegator. Berguna pada perangkat yang mode konsol dan mode disk-nya berbeda (misalnya beberapa kasus MechaPwn/modchip).

### Argumen aplikasi
Gunakan baris `ARG_<BUTTON>_E? =` untuk memberi argumen ke ELF (lihat contoh INI).
- Masukkan dulu argumen elf yang diluncurkan, lalu tambahkan argumen internal PS2BBL yang diinginkan (lihat di bawah). [NHDDL](https://github.com/pcm720/nhddl) adalah kandidat bagus untuk argumen, karena argumen mempercepat boot NHDDL.
- `-titleid=SLUS_123.45` mengganti ID judul aplikasi (hingga 11 karakter).
- `-appid` memaksa ID game visual aplikasi meski `APP_GAMEID = 0`.
- `-disc_stop` menghentikan disk setelah ELF tujuan dimuat (berguna per entri tanpa build `DISC_STOP_AT_BOOT`).
- `-gsm=<v[:c]>` menjalankan ELF tujuan lewat eGSM bawaan (diabaikan untuk jalur `rom?:`). Jika dipakai, ini harus menjadi argumen terakhir.
- `-disc_stop` diabaikan untuk entri peluncuran `cdrom`.
- `-dev9=<mode>` mengatur kebijakan DEV9/HDD sebelum meluncurkan ELF tujuan. Mode yang didukung:
  - `NICHDD` menjaga DEV9 (adaptor jaringan) dan HDD tetap menyala.
  - `NIC` menjaga DEV9/jaringan menyala, melepas `pfs0:`, dan langsung membuat `hdd0:`/`hdd1:` diam.
  - jika dihilangkan, PS2BBL tidak memaksakan kebijakan DEV9.
  - catatan: pada build tanpa HDD opsi ini tidak berpengaruh.
- `-patinfo` menyalakan penanganan PATINFO untuk entri `:PATINFO`.
  - PS2BBL membaca `SYSTEM.CNF` dari area atribut partisi (`PS2ICON3D`) dan menerapkan `BOOT2/BOOT/path`, `arg*`, `skip_argv0`, serta `HDDUNITPOWER`.
  - jika `BOOT2/BOOT/path=PATINFO`, PS2BBL memuat ELF tertanam dari area atribut partisi dan memakai serah terima internal `-la=E...`.
  - jika `IOPRP=PATINFO` (atau jalur kustom), PS2BBL meneruskannya ke tahap 2 lewat serah terima internal `-la=I...`.
  - jika `-patinfo` ada, argumen pertama yang tersisa menggantikan target `BOOT2/BOOT/path` milik CNF.
  Ini untuk build HDD.  
  Contoh PATINFO:  
    ```
    NAME_R1 = My App via PATINFO
    LK_R1_E1 = hdd0:+OSDMENU:PATINFO
    ARG_R1_E1 = pfs:/APPS/MYAPP.ELF
    ARG_R1_E1 = -patinfo               # Tells PS2BBL to use first arg as patinfo boot path.
    ```

Contoh meluncurkan NHDDL dengan mode video 480p dan mencari ISO di mmce dan HDD exfat tanpa perlu nhddl.yaml. Keuntungannya tidak ada waktu terbuang untuk memuat driver, mencari dan memuat nhddl.yaml. Ini cara tercepat untuk mem-boot NHDDL dan menampilkan daftar ISO.
```
NAME_R1 = NHDDL
LK_R1_E1 = mmce?:/NEUTRINO/nhddl.elf
ARG_R1_E1 = -video=480p
ARG_R1_E1 = -mode=mmce
ARG_R1_E1 = -mode=ata
```

#### Prioritas dan urutan argumen
1. PS2BBL mengurai dan memakai hanya argumen kendali loader di akhir `ARG_*`: `-appid`, `-titleid=`, `-dev9=`, `-patinfo`, `-disc_stop`, `-gsm=`.
2. Penguraian berjalan dari bawah ke atas dan berhenti di argumen pertama yang bukan kendali (perilaku akhir ala OSDMenu).
4. Untuk jalur peluncuran `:PATINFO`, PS2BBL mengurai `SYSTEM.CNF` dari atribut partisi dan menambahkan entri `arg*` CNF setelah argumen aplikasi pengguna.
5. Jika `-patinfo` diatur dan jalur peluncuran memuat `:PATINFO`, argumen aplikasi pengguna pertama yang tersisa menjadi jalur ELF tujuan (menggantikan jalur boot CNF) dan dihapus dari argv aplikasi. Jika tidak ada argumen tersisa, peluncuran dibatalkan (sama seperti OSDMenu), dan `BOOT2/BOOT/path` CNF tidak dipakai.
6. Argumen yang tersisa mempertahankan urutan dan diteruskan ke aplikasi yang diluncurkan.


### eGSM (external Graphics Synthesize Mode)
Untuk disk PS2, eGSM dibaca otomatis dari `OSDGSM.CNF` (tidak perlu pengaturan jalur di INI). Lihat [di sini](https://github.com/pcm720/OSDMenu/blob/main/patcher/README.md#osdgsmcnf) untuk format file konfigurasi.

- `-gsm=<v[:c]>` menjalankan ELF tujuan lewat eGSM bawaan (diabaikan untuk jalur `rom?:`).
  - eGSM diterapkan pada target yang diluncurkan (ELF/disk), bukan pada PS2BBL itu sendiri.
  Format eGSM (ala OSDMenu):
- `v` = mode video:
- kosong = tidak dipaksa (bawaan)
- `fp1` = paksa pemindaian progresif (240p/288p)
- `fp2` = paksa pemindaian progresif (480p/576p)
- `1080ix1` = paksa 1080i, lebar/tinggi x1
- `1080ix2` = paksa 1080i, lebar/tinggi x2
- `1080ix3` = paksa 1080i, lebar/tinggi x3
- `c` = mode kompatibilitas:
- kosong = tidak ada (bawaan)
- `1` = pembalikan field tipe 1
- `2` = pembalikan field tipe 2
- `3` = pembalikan field tipe 3

Contoh ARG eGSM:
- `-gsm=fp2`
- `-gsm=fp2:1`
- `-gsm=1080ix2`

Contoh penggunaan:
```
LK_TRIANGLE_E1 = mc0:/APP_WLE-ISR/WLE-ISR.ELF
ARG_TRIANGLE_E1 = -gsm=1080ix2
```

## Usang/Dihapus
- ~~`RUNKELF`~~ PS2BBLE kini menangani peluncuran elf/kelf secara internal tanpa pengguna perlu mendefinisikan aksi peluncuran kelf.


## Bug/masalah yang diketahui

Anda yang beri tahu saya ;)

## Kredit & Terima Kasih

- Dari saildot4k
  - @israpps untuk [PS2BBL](https://github.com/israpps/PlayStation2-Basic-BootLoader/)
  - @pcm720 untuk
    - gameID Retrogem, PS1 Video Negator, eGSM, dan kode PS2LOGO dari [OSDMenu](https://github.com/pcm720/OSDMenu)
    - Opsi mode video dari [NHDDL](https://github.com/pcm720/nhddl)
  - @sp193 untuk [PS1 Video Negator](https://github.com/ps2homebrew/PS1VModeNeg)
  - @nathanneurotic untuk 10 jalur PS2BBLE, ide, dan bujukan
  - [@Berion](https://www.psx-place.com/members/berion.1431/) untuk logo, latar, dan grafik tombol

- Dari [El Isra](https://israpps.github.io/) (Pengembang PS2BBL): 
  - @SP193 untuk pustaka inisialisasi OSD, yang menjadi fondasi proyek ini
  - @asmblur, karena mendorong saya membuat monster ini di SDK terbaru
  - @uyjulian dan @fjtrujy karena selalu membantu saya


<p align="center"><sub><a href="https://github.com/akilluminati47/RIPPS2">RIPPS2</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2/releases/latest/download/RIPPS2.elf">Unduh</a> &nbsp;&middot;&nbsp; <b>BIBLE</b> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2-themes">Tema</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPCSX2">RIPPCSX2</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2-fonts">Fon</a> &nbsp;&middot;&nbsp; <a href="https://akilluminati47.github.io/RIPPS2/">Situs</a> &nbsp;&middot;&nbsp; <a href="https://www.psx-place.com/threads/ripps2-a-ps2-front-end-in-one-elf-launch-disc-storage-memory-files.51316/">psx-place</a> &nbsp;&middot;&nbsp; <a href="https://discord.gg/Z7m9u5kby">Discord</a></sub></p>

