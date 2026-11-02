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
  <b>简体中文</b> |
  <a href="README.zh-TW.md">繁體中文</a> |
  <a href="README.vi.md">Tiếng Việt</a> |
  <a href="README.lo.md">ລາວ</a> |
  <a href="README.id.md">Bahasa Indonesia</a> |
  <a href="README.fil.md">Filipino</a> |
  <a href="README.ceb.md">Cebuano</a>
</p>
<!-- /i18n -->

<p align="center"><sub>英文 README 的译本；如有出入，以英文为准。 <a href="README.md">English</a></sub></p>

<p align="center"><sub><a href="https://github.com/akilluminati47/RIPPS2">RIPPS2</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2/releases/latest/download/RIPPS2.elf">下载</a> &nbsp;&middot;&nbsp; <b>BIBLE</b> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2-themes">主题</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPCSX2">RIPPCSX2</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2-fonts">字体</a> &nbsp;&middot;&nbsp; <a href="https://akilluminati47.github.io/RIPPS2/">网站</a> &nbsp;&middot;&nbsp; <a href="https://www.psx-place.com/threads/ripps2-a-ps2-front-end-in-one-elf-launch-disc-storage-memory-files.51316/">psx-place</a> &nbsp;&middot;&nbsp; <a href="https://discord.gg/Z7m9u5kby">Discord</a></sub></p>

<h1 align="center">BIBLE</h1>
<p align="center">
  <a href="https://github.com/akilluminati47/RIPPS2">RIPPS2</a> ·
  <a href="https://github.com/akilluminati47/BIBLE/actions">构建</a> ·
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
  <sub>开机时按住 L2 + R2 打开启动键页面，按住 TRIANGLE + CROSS 打开视频模式页面；设为 <code>$CREDITS</code> 的键会显示制作人员名单。</sub>
</p>

BIBLE 是 RIPPS2 安装的引导程序：saildot4k 的 PS2BBL Extended 的一个分支。

**此分支的改动**

- 启动画面：PS2 标志居中于 RIPPS2 的天空，按键在下方，文字在上方。
  `BIBLE_GLYPHS` 0 不显示，1 正面按键（默认），2 全部十六个，分两行每行八个。
  `BIBLE_INFO` 1 显示主机信息、时钟和倒计时（默认关闭）。
  天空与你的 RIPPS2 Color Theme 一致：未设置 `BIBLE_COLOR` 时，BIBLE 读取 RIPPS2 随其
  设置保存的天空，来自其 AUTO 条目启动的 RIPPS2 文件夹（配置中的 `BIBLE_COLOR` 优先）。
  在所有视频模式下外观一致。页面（视频模式、制作人员、启动键）在变暗的标志上淡入，
  按键收起，让启动键可以从容阅读。
- 视频模式：`VIDEO_MODE` 也接受 `576P`、`720P` 和 `1080I`，即 RIPPS2 的其余模式。`AUTO`（默认）
  在 AUTO 条目旁找到 RIPPS2 的设置时以其 Video Mode 启动，否则使用主机自身的模式。
- `BIBLE_WIDESCREEN`：`AUTO`（默认：RIPPS2 的 Widescreen，否则用 PS2 的 16:9 屏幕设置）、`ON` 或
  `OFF`。在 480i、576i、480p 和 576p 下，启动画面为会把画面拉伸到 16:9 的电视绘制，不会
  被压扁。720p 和 1080i 本来就是 16:9。
- 进入 RIPPS2 不跳屏：启动时标志和按键淡出，天空以 RIPPS2 的模式留在屏幕上；
  RIPPS2 就在同一片天空上启动。开机时按住 TRIANGLE + CROSS 打开视频模式页面，它总是以
  主机自身的隔行模式打开（在复合线上从 720p 或 1080i 回来的方法）。
- 新增：启动键页面。开机时按住 L2 + R2，无论启动画面如何设置，都能看到每个键的启动路径。
- 从开机起就按住的组合键现在会打开相应页面（以前手柄仍在
  初始化时会漏掉 TRIANGLE + CROSS）。
- 允许 `KEY_READ_WAIT_TIME = 0`（upstream 的下限是 500 ms）。
- 面向记忆卡 / USB、MMCE、MX4SIO 和 HDD 的 PS2 构建。不包含 eGSM 第 2 阶段。

**RIPPS2 如何使用它**

RIPPS2 将以签名启动文件的形式附带 BIBLE，并从其 Settings（Boot Loader）中安装，取代它现在附带的 PS2BBL 1.2.0。BIBLE 也可以作为由其他引导程序启动的 ELF 运行（FMCB、OSDMenu、SD2PSX 的引导程序）。BIBLE 还没有正式发布。

<p align="center"><img src="assets/readme/ripps2-icon.png" alt="RIPPS2" width="48" height="48"><br><sub>BIBLE 是 <a href="https://github.com/akilluminati47/RIPPS2">RIPPS2</a> 的一部分。</sub></p>

---

<p align="center"><sub>以下全部是 PS2BBL Extended 的原始 README，仅作翻译，其余未改动。</sub></p>

---


<br />
<p align="center">
  <a href="https://israpps.github.io/PlayStation2-Basic-BootLoader/">
    <img src="https://github.com/saildot4k/PlayStation2-Basic-BootLoader-Extended/blob/main/assets/ps2bbl_example.png" alt="Logo" width="50%" height="auto">
  </a>

  <p align="center">
    一款适用于 PlayStation 2™ 和 PSX-DESR 的灵活引导程序
    <br />
  </p>
</p>  


这是 [El Isra](https://github.com/israpps/PlayStation2-Basic-BootLoader/) 的 PS2BBL 的分支


## 文档

文档托管在 [github pages](https://israpps.github.io/PlayStation2-Basic-BootLoader/)，但有以下补充：

## 配置与参数

按需编辑配置文件。推荐使用 [R3Configurator](https://github.com/saildot4k/R3CONFIGURATOR) 编辑配置文件。路径已预先设置好，与 [PS2 Homebrew Store](https://ps2homebrewstore.com) 的下载相匹配。因此你通常只需编辑 Auto 选项，最好再根据加载 ISO 的设备设置 NHDDL 的参数。

### 配置文件搜索顺序

配置搜索现在会识别启动方式，避免在启动时加载不必要的驱动：

1. `CONFIG.INI`（CWD：当前工作目录）
2. 从设备加载时：
   - MMCE 启动：`mmce?:/PS2BBL/CONFIG.INI`
   - MX4SIO 启动：`mx4sio:/PS2BBL/CONFIG.INI`
   - APA HDD 启动：`hdd0:__sysconf:pfs:/PS2BBL/CONFIG.INI`
   - BDM 启动：`usb:/PS2BBL/CONFIG.INI` / `mass:/PS2BBL/CONFIG.INI` / `ata:/PS2BBL/CONFIG.INI`
3. 记忆卡备选：
   - PS2 上：`mc?:/SYS-CONF/PS2BBL.INI`
   - PSX-DESR 上：`mc?:/SYS-CONF/PSXBBL.INI`
4. PSX 上的最终备选
   - `xfrom:/PS2BBL/CONFIG.INI`
5. 使用 `DISC_STOP_AT_BOOT=1 编译时
   - `cdrom0:/PS2BBL/CONFIG.INI`
   - 按上面第 3 点的记忆卡备选。

### 设备路径前缀
PS2BBL 支持以下启动/配置路径前缀：
- `mc0:/`, `mc1:/`, `mc?:/`
- `usb:/`（首选）和 `mass:/`（旧式）

#### 按构建区分：  
- `mmce0:/`、`mmce1:/`、`mmce?:/` __MMCE 构建__
- `mx4sio:/`（首选）和 `massX:/`（旧式）  __MX4SIO 构建__
- `hdd0:partition:pfs:/<path to elf>` __HDD 构建__
- `xfrom:/` 路径 __PSX DESR 构建__
- `ata:/` exFAT HDD 的 BDM 设备
- `ilink:/`（BDM 大容量存储根目录）__尚未实现__
- `DISC_STOP_AT_BOOT=1` 编译配置，读取配置后总是停止光盘

### LOGO_DISPLAY
使用 `LOGO_DISPLAY = 3` 显示按键名称。名称由 `NAME_<BUTTON>` 定义。
  - `0` 无标志、无主机信息
  - `1` 主机信息
  - `2` PS2BBLE/PSXBBLE 标志和主机信息
  - `3` 显示配置文件中 `NAME_BUTTON = <TITLE>` 的按键图形
    - 示例：
      ```
      NAME_SQUARE = POPSLOADER
      ```

#### 来自 CWD 的自定义启动标志
如果在 CWD（当前工作目录）中找到自定义标志文件（LOGO.BIN），它会替换内置的 PS2BBLE/PSXBBLE 标志。

把 PNG 转换为所需的原始文件：
  - PNG 应为 RGBA 8 位索引色，每通道 255 色，分辨率 256x64。

  - 发布包（脚本在发布包根目录）：
  ```bash
  python png_to_logo_rbga.py my_logo.png
  ```

  - 把生成的 `LOGO.BIN` 放在 PS2BBL Extended 旁边。如果你使用 [PS2 Homebrew Store](https://ps2store.com) 的下载，应为 `mc?:/BOOT/`

### Retrogem 可视游戏 ID
- `APP_GAMEID = 1` 为应用/homebrew 启用可视游戏 ID，最多 11 个字符，取自文件名或 PS1/2 光盘
- `CDROM_DISABLE_GAMEID = 1` 为通过 `cdrom` 启动的光盘禁用可视游戏 ID。

### 光盘转动控制
- 全局键/值：`DISC_STOP = 0/1`
- `DISC_STOP = 1` 在找到配置文件时，读取配置后停止光盘。
- `DISC_STOP = 0`（或省略）保持默认行为。
- 可在每个启动条目中加入 `-disc_stop`，在找到目标 ELF 后停止光盘。

### 视频模式
- `VIDEO_MODE = AUTO, NTSC, PAL, 480P` 使用 PS2 默认模式或强制使用另外 3 种模式之一。

#### 应急视频模式选择器
- 启动时按 `TRIANGLE + CROSS` 进入
- 选择器激活时会强制 `LOGO_DISPLAY = 3`，让你看到标志和按键界面。
- 操作：
  - `LEFT/RIGHT` 切换模式：`AUTO`、`NTSC`、`PAL`、`480P`
  - `SELECT` 将所选模式保存到当前配置文件
  - `START` 退出选择器并继续显示按键

### CDROM 启动参数
对于 `LK_*_E* = cdrom`，支持的参数有：
- `-nologo`
- `-nogameid`
- `-ps1fast`
- `-ps1smooth`
- `-ps1vneg`
- `-gsm=<v[:c]>`

#### PS2LOGO 参数（仅 PS2 光盘）
- 使用 `cdrom` 作为启动条目路径。
- 在条目参数中加入 `-nologo` 可直接启动 PS2 光盘（跳过 `rom0:PS2LOGO`）。
- 不加 `-nologo` 时，PS2BBL 通过 PS2LOGO 运行光盘，并打补丁使其始终使用光盘区域、绕过标志校验和检查。
- DECKARD IE 75K 及以后：无标志启动需要时会自动应用 XPARAM.IRX。

#### PS1 光盘参数（每次启动）
这些参数作用于每个 `cdrom` 启动条目，而不是全局。
- `-ps1fast` 启用 PS1 光盘快速读取。
- `-ps1smooth` 启用纹理平滑。
- `-ps1vneg` 通过 PS1VModeNegator 运行 PS1DRV。在主机模式和光盘模式不同的环境中很有用（例如某些 MechaPwn/改机芯片的情况）。

### 应用参数
使用 `ARG_<BUTTON>_E? =` 行向 ELF 传递参数（见 INI 示例）。
- 先写被启动 elf 的参数，再接上所需的 PS2BBL 内部参数（见下文）。[NHDDL](https://github.com/pcm720/nhddl) 很适合使用参数，因为参数能加快 NHDDL 的启动。
- `-titleid=SLUS_123.45` 覆盖应用的标题 ID（最多 11 个字符）。
- `-appid` 即使 `APP_GAMEID = 0` 也强制显示应用的可视游戏 ID。
- `-disc_stop` 在目标 ELF 加载后停止光盘（在非 `DISC_STOP_AT_BOOT` 构建中按条目使用很方便）。
- `-gsm=<v[:c]>` 通过内置 eGSM 运行目标 ELF（对 `rom?:` 路径无效）。如使用，必须是最后一个参数。
- `-disc_stop` 对 `cdrom` 启动条目无效。
- `-dev9=<mode>` 在启动目标 ELF 前设置 DEV9/HDD 策略。支持的模式：
  - `NICHDD` 保持 DEV9（网络适配器）和 HDD 都通电。
  - `NIC` 保持 DEV9/网络开启，卸载 `pfs0:`，并让 `hdd0:`/`hdd1:` 立即进入待机。
  - 省略时，PS2BBL 不强制任何 DEV9 策略。
  - 注意：在无 HDD 的构建中此选项无效。
- `-patinfo` 为 `:PATINFO` 条目启用 PATINFO 处理。
  - PS2BBL 从分区属性区域（`PS2ICON3D`）读取 `SYSTEM.CNF`，并应用 `BOOT2/BOOT/path`、`arg*`、`skip_argv0` 和 `HDDUNITPOWER`。
  - 如果 `BOOT2/BOOT/path=PATINFO`，PS2BBL 从分区属性区域加载内嵌 ELF，并使用内部的 `-la=E...` 交接。
  - 如果 `IOPRP=PATINFO`（或自定义路径），PS2BBL 通过内部的 `-la=I...` 交接把它传给第 2 阶段。
  - 如果有 `-patinfo`，剩下的第一个参数会覆盖 CNF 的 `BOOT2/BOOT/path` 目标。
  这适用于 HDD 构建。  
  PATINFO 示例：  
    ```
    NAME_R1 = My App via PATINFO
    LK_R1_E1 = hdd0:+OSDMENU:PATINFO
    ARG_R1_E1 = pfs:/APPS/MYAPP.ELF
    ARG_R1_E1 = -patinfo               # Tells PS2BBL to use first arg as patinfo boot path.
    ```

以 480p 视频模式启动 NHDDL，并在不需要 nhddl.yaml 的情况下在 mmce 和 exfat HDD 上查找 ISO 的示例。好处是不必浪费时间加载驱动、查找和加载 nhddl.yaml。这是启动 NHDDL 并显示 ISO 列表最快的方式。
```
NAME_R1 = NHDDL
LK_R1_E1 = mmce?:/NEUTRINO/nhddl.elf
ARG_R1_E1 = -video=480p
ARG_R1_E1 = -mode=mmce
ARG_R1_E1 = -mode=ata
```

#### 参数优先级与顺序
1. PS2BBL 只解析并消耗 `ARG_*` 末尾的引导程序控制参数：`-appid`、`-titleid=`、`-dev9=`、`-patinfo`、`-disc_stop`、`-gsm=`。
2. 解析从下往上进行，遇到第一个非控制参数即停止（OSDMenu 风格的末尾处理）。
4. 对于 `:PATINFO` 启动路径，PS2BBL 解析分区属性中的 `SYSTEM.CNF`，并把 CNF 的 `arg*` 条目追加在用户应用参数之后。
5. 如果设置了 `-patinfo` 且启动路径包含 `:PATINFO`，用户剩下的第一个应用参数会成为目标 ELF 路径（覆盖 CNF 启动路径），并从应用的 argv 中移除。如果没有剩余参数，则中止启动（与 OSDMenu 一致），也不使用 CNF 的 `BOOT2/BOOT/path`。
6. 其余参数保持顺序并传给被启动的应用。


### eGSM (external Graphics Synthesize Mode)
对于 PS2 光盘，eGSM 会自动从 `OSDGSM.CNF` 读取（无需在 INI 中设置路径）。配置文件格式见[这里](https://github.com/pcm720/OSDMenu/blob/main/patcher/README.md#osdgsmcnf)。

- `-gsm=<v[:c]>` 通过内置 eGSM 运行目标 ELF（对 `rom?:` 路径无效）。
  - eGSM 作用于被启动的目标（ELF/光盘），而不是 PS2BBL 本身。
  eGSM 格式（OSDMenu 风格）：
- `v` = 视频模式：
- 空 = 不强制（默认）
- `fp1` = 强制逐行扫描（240p/288p）
- `fp2` = 强制逐行扫描（480p/576p）
- `1080ix1` = 强制 1080i，宽/高 x1
- `1080ix2` = 强制 1080i，宽/高 x2
- `1080ix3` = 强制 1080i，宽/高 x3
- `c` = 兼容模式：
- 空 = 无（默认）
- `1` = 场翻转类型 1
- `2` = 场翻转类型 2
- `3` = 场翻转类型 3

eGSM ARG 示例：
- `-gsm=fp2`
- `-gsm=fp2:1`
- `-gsm=1080ix2`

用法示例：
```
LK_TRIANGLE_E1 = mc0:/APP_WLE-ISR/WLE-ISR.ELF
ARG_TRIANGLE_E1 = -gsm=1080ix2
```

## 已弃用/已移除
- ~~`RUNKELF`~~ PS2BBLE 现在会在内部处理 elf/kelf 的启动，用户无需定义 kelf 启动操作。


## 已知错误/问题

你来告诉我 ;)

## 致谢

- 来自 saildot4k
  - @israpps 的 [PS2BBL](https://github.com/israpps/PlayStation2-Basic-BootLoader/)
  - @pcm720 的
    - 来自 [OSDMenu](https://github.com/pcm720/OSDMenu) 的 Retrogem gameID、PS1 Video Negator、eGSM 和 PS2LOGO 代码
    - 来自 [NHDDL](https://github.com/pcm720/nhddl) 的视频模式选项
  - @sp193 的 [PS1 Video Negator](https://github.com/ps2homebrew/PS1VModeNeg)
  - @nathanneurotic 的 PS2BBLE 10 路径、想法和劝说
  - [@Berion](https://www.psx-place.com/members/berion.1431/) 的标志、背景和按键图形

- 来自 [El Isra](https://israpps.github.io/)（PS2BBL 开发者）： 
  - @SP193 的 OSD 初始化库，它们是本项目的基础
  - @asmblur，鼓励我在最新 SDK 上做出这个怪物
  - @uyjulian 和 @fjtrujy，总是帮助我


<p align="center"><sub><a href="https://github.com/akilluminati47/RIPPS2">RIPPS2</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2/releases/latest/download/RIPPS2.elf">下载</a> &nbsp;&middot;&nbsp; <b>BIBLE</b> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2-themes">主题</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPCSX2">RIPPCSX2</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2-fonts">字体</a> &nbsp;&middot;&nbsp; <a href="https://akilluminati47.github.io/RIPPS2/">网站</a> &nbsp;&middot;&nbsp; <a href="https://www.psx-place.com/threads/ripps2-a-ps2-front-end-in-one-elf-launch-disc-storage-memory-files.51316/">psx-place</a> &nbsp;&middot;&nbsp; <a href="https://discord.gg/Z7m9u5kby">Discord</a></sub></p>

