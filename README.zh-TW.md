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
  <b>繁體中文</b> |
  <a href="README.vi.md">Tiếng Việt</a> |
  <a href="README.lo.md">ລາວ</a> |
  <a href="README.id.md">Bahasa Indonesia</a> |
  <a href="README.fil.md">Filipino</a> |
  <a href="README.ceb.md">Cebuano</a>
</p>
<!-- /i18n -->

<p align="center"><sub>英文 README 的譯本；如有出入，以英文為準。 <a href="README.md">English</a></sub></p>

<p align="center"><sub><a href="https://github.com/akilluminati47/RIPPS2">RIPPS2</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2/releases/latest/download/RIPPS2.elf">下載</a> &nbsp;&middot;&nbsp; <b>BIBLE</b> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2-themes">主題</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPCSX2">RIPPCSX2</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2-fonts">字型</a> &nbsp;&middot;&nbsp; <a href="https://akilluminati47.github.io/RIPPS2/">網站</a> &nbsp;&middot;&nbsp; <a href="https://www.psx-place.com/threads/ripps2-a-ps2-front-end-in-one-elf-launch-disc-storage-memory-files.51316/">psx-place</a> &nbsp;&middot;&nbsp; <a href="https://discord.gg/Z7m9u5kby">Discord</a></sub></p>

<h1 align="center">BIBLE</h1>
<p align="center">
  <a href="https://github.com/akilluminati47/RIPPS2">RIPPS2</a> ·
  <a href="https://github.com/akilluminati47/BIBLE/actions">組建</a> ·
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
  <sub>開機時按住 L2 + R2 開啟啟動鍵頁面，按住 TRIANGLE + CROSS 開啟視訊模式頁面；設為 <code>$CREDITS</code> 的按鍵會顯示製作名單。</sub>
</p>

BIBLE 是 RIPPS2 安裝的開機載入程式：saildot4k 的 PS2BBL Extended 的分支。

**這個分支改了什麼**

- 開機畫面：PS2 標誌置中於 RIPPS2 的天空，按鍵在下方，文字在上方。
  `BIBLE_GLYPHS` 0 不顯示，1 正面按鍵（預設），2 全部十六個，分兩列每列八個。
  `BIBLE_INFO` 1 顯示主機資訊、時鐘與倒數（預設關閉）。
  天空會配合你的 RIPPS2 Color Theme：未設定 `BIBLE_COLOR` 時，BIBLE 會讀取 RIPPS2 隨其
  設定儲存的天空，來源是其 AUTO 項目啟動的 RIPPS2 資料夾（設定檔中的 `BIBLE_COLOR` 優先）。
  所有視訊模式下外觀一致。頁面（視訊模式、製作名單、啟動鍵）會在變暗的標誌上淡入，
  按鍵收起，讓啟動鍵能從容閱讀。
- 視訊模式：`VIDEO_MODE` 也接受 `576P`、`720P` 與 `1080I`，即 RIPPS2 其餘的模式。`AUTO`（預設）
  在 AUTO 項目旁找到 RIPPS2 的設定時以其 Video Mode 啟動，否則使用主機本身的模式。
- `BIBLE_WIDESCREEN`：`AUTO`（預設：RIPPS2 的 Widescreen，否則用 PS2 的 16:9 螢幕設定）、`ON` 或
  `OFF`。在 480i、576i、480p 與 576p 下，開機畫面是為會把畫面拉寬到 16:9 的電視繪製，不會
  被壓扁。720p 與 1080i 本來就是 16:9。
- 進入 RIPPS2 不跳畫面：啟動時標誌與按鍵淡出，天空以 RIPPS2 的模式留在螢幕上；
  RIPPS2 就在同一片天空上啟動。開機時按住 TRIANGLE + CROSS 開啟視訊模式頁面，它總是以
  主機本身的交錯模式開啟（在複合端子線上從 720p 或 1080i 回來的方法）。
- 新功能：啟動鍵頁面。開機時按住 L2 + R2，不論開機畫面怎麼設定，都能讀到每個按鍵的啟動路徑。
- 從開機起就按住的組合鍵現在會開啟對應頁面（以前手把仍在
  初始化時會漏掉 TRIANGLE + CROSS）。
- 允許 `KEY_READ_WAIT_TIME = 0`（upstream 的下限是 500 ms）。
- 適用記憶卡 / USB、MMCE、MX4SIO 與 HDD 的 PS2 組建。不含 eGSM 第 2 階段。

**RIPPS2 如何使用它**

RIPPS2 從 v1.3.4-beta 起以簽署過的開機檔案附帶 BIBLE，並從 Settings > General > Boot Loader > Manage 安裝。BIBLE 也能作為由其他載入程式啟動的 ELF 執行（FMCB、OSDMenu、SD2PSX 的載入程式）。簽署過的組建在[發行頁面](https://github.com/akilluminati47/BIBLE/releases/tag/signed-f31c8d5)上；發行時還沒有任何主機綁定過它們，所以請先用一張備用記憶卡試試。

<p align="center"><img src="assets/readme/ripps2-icon.png" alt="RIPPS2" width="48" height="48"><br><sub>BIBLE 是 <a href="https://github.com/akilluminati47/RIPPS2">RIPPS2</a> 的一部分。</sub></p>

---

<p align="center"><sub>以下全部是 PS2BBL Extended 的原始 README，僅作翻譯，其餘未更動。</sub></p>

---


<br />
<p align="center">
  <a href="https://israpps.github.io/PlayStation2-Basic-BootLoader/">
    <img src="https://github.com/saildot4k/PlayStation2-Basic-BootLoader-Extended/blob/main/assets/ps2bbl_example.png" alt="Logo" width="50%" height="auto">
  </a>

  <p align="center">
    一款適用於 PlayStation 2™ 與 PSX-DESR 的彈性開機載入程式
    <br />
  </p>
</p>  


這是 [El Isra](https://github.com/israpps/PlayStation2-Basic-BootLoader/) 的 PS2BBL 的分支


<a id="documentation"></a>

## 文件

文件放在 [github pages](https://israpps.github.io/PlayStation2-Basic-BootLoader/)，但有以下補充：

<a id="config-and-arguments"></a>

## 設定與參數

依需要編輯設定檔。建議使用 [R3Configurator](https://github.com/saildot4k/R3CONFIGURATOR) 編輯設定檔。路徑已預先設好，與 [PS2 Homebrew Store](https://ps2homebrewstore.com) 的下載相符。所以你通常只需編輯 Auto 選項，最好再依載入 ISO 的裝置設定 NHDDL 的參數。

<a id="config-path-search-order"></a>

### 設定檔搜尋順序

設定檔搜尋現在會辨識開機方式，避免啟動時載入不必要的驅動程式：

1. `CONFIG.INI`（CWD：目前的工作目錄）
2. 從裝置載入時：
   - MMCE 開機：`mmce?:/PS2BBL/CONFIG.INI`
   - MX4SIO 開機：`mx4sio:/PS2BBL/CONFIG.INI`
   - APA HDD 開機：`hdd0:__sysconf:pfs:/PS2BBL/CONFIG.INI`
   - BDM 開機：`usb:/PS2BBL/CONFIG.INI` / `mass:/PS2BBL/CONFIG.INI` / `ata:/PS2BBL/CONFIG.INI`
3. 記憶卡備援：
   - PS2 上：`mc?:/SYS-CONF/PS2BBL.INI`
   - PSX-DESR 上：`mc?:/SYS-CONF/PSXBBL.INI`
4. PSX 上的最後備援
   - `xfrom:/PS2BBL/CONFIG.INI`
5. 以 `DISC_STOP_AT_BOOT=1 編譯時
   - `cdrom0:/PS2BBL/CONFIG.INI`
   - 依上面第 3 點的記憶卡備援。

<a id="device-path-prefixes"></a>

### 裝置路徑前綴
PS2BBL 支援下列啟動/設定路徑前綴：
- `mc0:/`, `mc1:/`, `mc?:/`
- `usb:/`（建議）與 `mass:/`（舊式）

<a id="build-specific"></a>

#### 依組建而定：  
- `mmce0:/`、`mmce1:/`、`mmce?:/` __MMCE 組建__
- `mx4sio:/`（建議）與 `massX:/`（舊式）  __MX4SIO 組建__
- `hdd0:partition:pfs:/<path to elf>` __HDD 組建__
- `xfrom:/` 路徑 __PSX DESR 組建__
- `ata:/` exFAT HDD 的 BDM 裝置
- `ilink:/`（BDM 大量儲存根目錄）__尚未實作__
- `DISC_STOP_AT_BOOT=1` 編譯設定檔，讀取設定後一律停止光碟

### LOGO_DISPLAY
使用 `LOGO_DISPLAY = 3` 顯示按鍵名稱。名稱由 `NAME_<BUTTON>` 定義。
  - `0` 無標誌、無主機資訊
  - `1` 主機資訊
  - `2` PS2BBLE/PSXBBLE 標誌與主機資訊
  - `3` 顯示設定檔中 `NAME_BUTTON = <TITLE>` 的按鍵圖形
    - 範例：
      ```
      NAME_SQUARE = POPSLOADER
      ```

<a id="custom-splash-logo-from-cwd"></a>

#### 來自 CWD 的自訂開機標誌
如果在 CWD（目前的工作目錄）中找到自訂標誌檔（LOGO.BIN），它會取代內建的 PS2BBLE/PSXBBLE 標誌。

把 PNG 轉換成所需的原始檔：
  - PNG 應為 RGBA 8 位元索引色，每通道 255 色，解析度 256x64。

  - 發行套件（指令碼在發行套件根目錄）：
  ```bash
  python png_to_logo_rbga.py my_logo.png
  ```

  - 把產生的 `LOGO.BIN` 放在 PS2BBL Extended 旁邊。如果你使用 [PS2 Homebrew Store](https://ps2store.com) 的下載，應為 `mc?:/BOOT/`

<a id="retrogem-visual-game-id"></a>

### Retrogem 視覺遊戲 ID
- `APP_GAMEID = 1` 為應用程式/homebrew 啟用視覺遊戲 ID，最多 11 個字元，取自檔名或 PS1/2 光碟
- `CDROM_DISABLE_GAMEID = 1` 為透過 `cdrom` 啟動的光碟停用視覺遊戲 ID。

<a id="disc-spin-control"></a>

### 光碟轉動控制
- 全域鍵/值：`DISC_STOP = 0/1`
- `DISC_STOP = 1` 在找到設定檔時，讀取設定後停止光碟。
- `DISC_STOP = 0`（或省略）維持預設行為。
- 可在每個啟動項目加上 `-disc_stop`，在找到目標 ELF 後停止光碟。

<a id="video-mode"></a>

### 視訊模式
- `VIDEO_MODE = AUTO, NTSC, PAL, 480P` 使用 PS2 預設模式，或強制使用另外 3 種模式之一。

<a id="emergency-video-mode-selector"></a>

#### 緊急視訊模式選擇器
- 開機時按 `TRIANGLE + CROSS` 進入
- 選擇器啟用時會強制 `LOGO_DISPLAY = 3`，讓你看到標誌與按鍵介面。
- 操作：
  - `LEFT/RIGHT` 切換模式：`AUTO`、`NTSC`、`PAL`、`480P`
  - `SELECT` 將選取的模式存入目前的設定檔
  - `START` 離開選擇器並繼續顯示按鍵

<a id="cdrom-launch-args"></a>

### CDROM 啟動參數
對 `LK_*_E* = cdrom`，支援的參數有：
- `-nologo`
- `-nogameid`
- `-ps1fast`
- `-ps1smooth`
- `-ps1vneg`
- `-gsm=<v[:c]>`

<a id="ps2logo-arguments-ps2-discs-only"></a>

#### PS2LOGO 參數（僅 PS2 光碟）
- 使用 `cdrom` 作為啟動項目路徑。
- 在項目參數加上 `-nologo` 可直接啟動 PS2 光碟（略過 `rom0:PS2LOGO`）。
- 不加 `-nologo` 時，PS2BBL 透過 PS2LOGO 執行光碟，並修補它一律使用光碟區域、略過標誌檢查碼檢查。
- DECKARD IE 75K 及之後：無標誌啟動需要時會自動套用 XPARAM.IRX。

<a id="ps1-disc-arguments-per-launch"></a>

#### PS1 光碟參數（每次啟動）
這些參數作用於每個 `cdrom` 啟動項目，而非全域。
- `-ps1fast` 啟用 PS1 光碟快速讀取。
- `-ps1smooth` 啟用貼圖平滑。
- `-ps1vneg` 透過 PS1VModeNegator 執行 PS1DRV。在主機模式與光碟模式不同的環境中很有用（例如某些 MechaPwn/改機晶片的情況）。

<a id="app-arguments"></a>

### 應用程式參數
使用 `ARG_<BUTTON>_E? =` 行向 ELF 傳遞參數（見 INI 範例）。
- 先寫被啟動 elf 的參數，再接上所需的 PS2BBL 內部參數（見下文）。[NHDDL](https://github.com/pcm720/nhddl) 很適合使用參數，因為參數能加快 NHDDL 的啟動。
- `-titleid=SLUS_123.45` 覆寫應用程式的標題 ID（最多 11 個字元）。
- `-appid` 即使 `APP_GAMEID = 0` 也強制顯示應用程式的視覺遊戲 ID。
- `-disc_stop` 在目標 ELF 載入後停止光碟（在非 `DISC_STOP_AT_BOOT` 組建中逐項使用很方便）。
- `-gsm=<v[:c]>` 透過內建 eGSM 執行目標 ELF（對 `rom?:` 路徑無效）。若使用，必須是最後一個參數。
- `-disc_stop` 對 `cdrom` 啟動項目無效。
- `-dev9=<mode>` 在啟動目標 ELF 前設定 DEV9/HDD 原則。支援的模式：
  - `NICHDD` 讓 DEV9（網路介面卡）與 HDD 都保持通電。
  - `NIC` 讓 DEV9/網路保持開啟，卸載 `pfs0:`，並讓 `hdd0:`/`hdd1:` 立即進入待機。
  - 省略時，PS2BBL 不強制任何 DEV9 原則。
  - 注意：在沒有 HDD 的組建中此選項無效。
- `-patinfo` 為 `:PATINFO` 項目啟用 PATINFO 處理。
  - PS2BBL 從分割區屬性區（`PS2ICON3D`）讀取 `SYSTEM.CNF`，並套用 `BOOT2/BOOT/path`、`arg*`、`skip_argv0` 與 `HDDUNITPOWER`。
  - 若 `BOOT2/BOOT/path=PATINFO`，PS2BBL 從分割區屬性區載入內嵌 ELF，並使用內部的 `-la=E...` 交接。
  - 若 `IOPRP=PATINFO`（或自訂路徑），PS2BBL 透過內部的 `-la=I...` 交接把它傳給第 2 階段。
  - 若有 `-patinfo`，剩下的第一個參數會覆寫 CNF 的 `BOOT2/BOOT/path` 目標。
  這適用於 HDD 組建。  
  PATINFO 範例：  
    ```
    NAME_R1 = My App via PATINFO
    LK_R1_E1 = hdd0:+OSDMENU:PATINFO
    ARG_R1_E1 = pfs:/APPS/MYAPP.ELF
    ARG_R1_E1 = -patinfo               # Tells PS2BBL to use first arg as patinfo boot path.
    ```

以 480p 視訊模式啟動 NHDDL，並在不需要 nhddl.yaml 的情況下於 mmce 與 exfat HDD 上尋找 ISO 的範例。好處是不必浪費時間載入驅動程式、尋找與載入 nhddl.yaml。這是啟動 NHDDL 並顯示 ISO 清單最快的方式。
```
NAME_R1 = NHDDL
LK_R1_E1 = mmce?:/NEUTRINO/nhddl.elf
ARG_R1_E1 = -video=480p
ARG_R1_E1 = -mode=mmce
ARG_R1_E1 = -mode=ata
```

<a id="argument-precedence-and-order"></a>

#### 參數優先順序與次序
1. PS2BBL 只解析並消耗 `ARG_*` 末端的載入程式控制參數：`-appid`、`-titleid=`、`-dev9=`、`-patinfo`、`-disc_stop`、`-gsm=`。
2. 解析由下往上進行，遇到第一個非控制參數就停止（OSDMenu 風格的末端處理）。
4. 對 `:PATINFO` 啟動路徑，PS2BBL 解析分割區屬性中的 `SYSTEM.CNF`，並把 CNF 的 `arg*` 項目附加在使用者應用程式參數之後。
5. 若設定了 `-patinfo` 且啟動路徑包含 `:PATINFO`，使用者剩下的第一個應用程式參數會成為目標 ELF 路徑（覆寫 CNF 開機路徑），並從應用程式的 argv 中移除。若沒有剩餘參數，則中止啟動（與 OSDMenu 一致），也不使用 CNF 的 `BOOT2/BOOT/path`。
6. 其餘參數保持次序並傳給被啟動的應用程式。


### eGSM (external Graphics Synthesize Mode)
對 PS2 光碟，eGSM 會自動從 `OSDGSM.CNF` 讀取（不需在 INI 設定路徑）。設定檔格式見[這裡](https://github.com/pcm720/OSDMenu/blob/main/patcher/README.md#osdgsmcnf)。

- `-gsm=<v[:c]>` 透過內建 eGSM 執行目標 ELF（對 `rom?:` 路徑無效）。
  - eGSM 作用於被啟動的目標（ELF/光碟），而非 PS2BBL 本身。
  eGSM 格式（OSDMenu 風格）：
- `v` = 視訊模式：
- 空 = 不強制（預設）
- `fp1` = 強制循序掃描（240p/288p）
- `fp2` = 強制循序掃描（480p/576p）
- `1080ix1` = 強制 1080i，寬/高 x1
- `1080ix2` = 強制 1080i，寬/高 x2
- `1080ix3` = 強制 1080i，寬/高 x3
- `c` = 相容模式：
- 空 = 無（預設）
- `1` = 圖場翻轉類型 1
- `2` = 圖場翻轉類型 2
- `3` = 圖場翻轉類型 3

eGSM ARG 範例：
- `-gsm=fp2`
- `-gsm=fp2:1`
- `-gsm=1080ix2`

使用範例：
```
LK_TRIANGLE_E1 = mc0:/APP_WLE-ISR/WLE-ISR.ELF
ARG_TRIANGLE_E1 = -gsm=1080ix2
```

<a id="deprecatedremoved"></a>

## 已淘汰/已移除
- ~~`RUNKELF`~~ PS2BBLE 現在會在內部處理 elf/kelf 的啟動，使用者不必定義 kelf 啟動動作。


<a id="known-bugsissues"></a>

## 已知錯誤/問題

你來告訴我 ;)

<a id="credits--thanks"></a>

## 致謝

- 來自 saildot4k
  - @israpps 的 [PS2BBL](https://github.com/israpps/PlayStation2-Basic-BootLoader/)
  - @pcm720 的
    - 來自 [OSDMenu](https://github.com/pcm720/OSDMenu) 的 Retrogem gameID、PS1 Video Negator、eGSM 與 PS2LOGO 程式碼
    - 來自 [NHDDL](https://github.com/pcm720/nhddl) 的視訊模式選項
  - @sp193 的 [PS1 Video Negator](https://github.com/ps2homebrew/PS1VModeNeg)
  - @nathanneurotic 的 PS2BBLE 10 路徑、點子與說服
  - [@Berion](https://www.psx-place.com/members/berion.1431/) 的標誌、背景與按鍵圖形

- 來自 [El Isra](https://israpps.github.io/)（PS2BBL 開發者）： 
  - @SP193 的 OSD 初始化函式庫，它們是本專案的基礎
  - @asmblur，鼓勵我在最新 SDK 上做出這個怪物
  - @uyjulian 與 @fjtrujy，總是幫助我


<p align="center"><sub><a href="https://github.com/akilluminati47/RIPPS2">RIPPS2</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2/releases/latest/download/RIPPS2.elf">下載</a> &nbsp;&middot;&nbsp; <b>BIBLE</b> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2-themes">主題</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPCSX2">RIPPCSX2</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2-fonts">字型</a> &nbsp;&middot;&nbsp; <a href="https://akilluminati47.github.io/RIPPS2/">網站</a> &nbsp;&middot;&nbsp; <a href="https://www.psx-place.com/threads/ripps2-a-ps2-front-end-in-one-elf-launch-disc-storage-memory-files.51316/">psx-place</a> &nbsp;&middot;&nbsp; <a href="https://discord.gg/Z7m9u5kby">Discord</a></sub></p>

