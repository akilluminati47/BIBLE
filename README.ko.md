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
  <b>한국어</b> |
  <a href="README.zh-CN.md">简体中文</a> |
  <a href="README.zh-TW.md">繁體中文</a> |
  <a href="README.vi.md">Tiếng Việt</a> |
  <a href="README.lo.md">ລາວ</a> |
  <a href="README.id.md">Bahasa Indonesia</a> |
  <a href="README.fil.md">Filipino</a> |
  <a href="README.ceb.md">Cebuano</a>
</p>
<!-- /i18n -->

<p align="center"><sub>영어 README의 번역입니다. 내용이 다르면 영어판이 기준입니다. <a href="README.md">English</a></sub></p>

<p align="center"><sub><a href="https://github.com/akilluminati47/RIPPS2">RIPPS2</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2/releases/latest/download/RIPPS2.elf">다운로드</a> &nbsp;&middot;&nbsp; <b>BIBLE</b> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2-themes">테마</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPCSX2">RIPPCSX2</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2-fonts">글꼴</a> &nbsp;&middot;&nbsp; <a href="https://akilluminati47.github.io/RIPPS2/">웹사이트</a> &nbsp;&middot;&nbsp; <a href="https://www.psx-place.com/threads/ripps2-a-ps2-front-end-in-one-elf-launch-disc-storage-memory-files.51316/">psx-place</a> &nbsp;&middot;&nbsp; <a href="https://discord.gg/Z7m9u5kby">Discord</a></sub></p>

<h1 align="center">BIBLE</h1>
<p align="center">
  <a href="https://akilluminati47.github.io/BIBLE/">웹사이트</a> ·
  <a href="https://github.com/akilluminati47/RIPPS2">RIPPS2</a> ·
  <a href="https://github.com/akilluminati47/BIBLE/actions">빌드</a> ·
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
  <sub>부팅 시 L2 + R2를 누르고 있으면 실행 키 페이지, TRIANGLE + CROSS는 비디오 모드 페이지가 열립니다. <code>$CREDITS</code>로 설정한 키는 크레디트를 보여 줍니다.</sub>
</p>

BIBLE은 RIPPS2가 설치하는 부트 로더로, saildot4k의 PS2BBL Extended를 포크한 것입니다.

**이 포크에서 바뀐 점**

- 스플래시: RIPPS2의 하늘 가운데에 PS2 로고, 그 아래에 버튼, 위에는 글자(있으면). `BIBLE_GLYPHS` 0 없음, 1 액션 버튼(기본), 2 16개 모두를 8개씩 두 줄로. `BIBLE_INFO` 1은 본체 정보, 시계, 카운트다운을 보여줍니다(기본은 꺼짐). 하늘은 RIPPS2의 Color Theme를 따릅니다. `BIBLE_COLOR`가 없으면 BIBLE은 RIPPS2가 설정과 함께 저장하는 하늘을 AUTO 항목이 실행하는 폴더에서, 또는 AUTO 항목이 SD2PSX, USB, HDD의 RIPPS2일 때는 메모리 카드의 `RIPPS2` 폴더에서 읽습니다(설정 파일의 `BIBLE_COLOR`가 우선). 모든 비디오 모드에서 같은 모습입니다.
- `BIBLE_BACKGROUND`: `AUTO`(기본: RIPPS2의 설정이 있거나 `BIBLE_COLOR`가 있으면 하늘, 없으면 본체 고유 모드의 검정, 평범한 부트로더처럼), `SKY` 또는 `BLANK`(검정). 프로그램으로 넘어갈 때는 어차피 몇 초 동안 검으므로, 검정이면 그와 한 덩어리로 보입니다.
- 미리 준비한 부팅음: RIPPS2의 Boot Sound On (fast)은 `boot.adp`를 BIBLE 설정 파일 옆(`mc?:/SYS-CONF/boot.adp`)에 둘 수 있습니다. 어떤 드라이브보다 먼저 읽습니다. BIBLE은 RAM으로 RIPPS2에 넘겨줄 수도 있지만, 지금까지는 실험실에서만 통과했습니다. 실제 SD2PSX에서는 RIPPS2가 카드의 사본을 직접 읽었습니다. **무음이 가장 빠른 부팅입니다.** 약속과 RIPPS2 쪽: [docs/boot-sound-handoff.md](docs/boot-sound-handoff.md).
- RIPPS2 먼저: 설정 템플릿(`release/SYS-CONF/PS2BBL.INI`)과 내장 기본값은 OSDMenu와 FMCB보다 먼저 `mc?:/RIPPS2/RIPPS2.ELF`와 `mmce?:/APPS/RIPPS2.ELF`를 시도하고, 템플릿에는 BIBLE 고유 키가 설명과 함께 있습니다. 페이지(비디오 모드, 크레딧, 실행 키)는 버튼을 치운 어두운 로고 위에 서서히 나타나, 실행 키를 차분히 읽을 수 있습니다.
- 비디오 모드: `VIDEO_MODE`는 `576P`, `720P`, `1080I`도 받으며, 이는 RIPPS2의 나머지 모드입니다. `AUTO`(기본값)는
  AUTO 항목 옆에 RIPPS2의 설정이 있으면 그 Video Mode로, 없으면 콘솔 자체의 모드로 시작합니다.
- `BIBLE_WIDESCREEN`: `AUTO`(기본값: RIPPS2의 Widescreen, 없으면 PS2의 16:9 화면 설정), `ON` 또는
  `OFF`. 480i, 576i, 480p, 576p에서는 화면을 16:9로 늘리는 TV에 맞게 스플래시를 그리므로
  찌그러지지 않습니다. 720p와 1080i는 이미 16:9입니다.
- RIPPS2로 넘어가기: 실행할 때 로고와 버튼이 사라지고, 콘솔이 다음 프로그램을 불러올 때까지 하늘이 남습니다. 이때 화면이 꺼집니다(메모리 카드의 RIPPS2로 실험실에서 약 7초). 그런 다음 RIPPS2가 같은 비디오 모드와 같은 색으로 나타납니다. 부팅 시 TRIANGLE + CROSS를 누르고 있으면 비디오 모드 페이지가 열리는데, 이 페이지는 항상
  콘솔 자체의 인터레이스 모드로 열립니다(컴포지트 케이블에서 720p나 1080i로부터 돌아오는 길).
- 새 기능: 실행 키 페이지. 전원을 켤 때 L2 + R2를 누르고 있으면 BIBLE이 무엇이든 실행하기 전에 멈추고, 스플래시 설정과 상관없이 각 키의 현재 실행 경로를 보여줍니다(다른 것이 아무것도 보이지 않는 `LOGO_DISPLAY = 0`에서 유용합니다).
- 전원을 켤 때부터 누르고 있던 조합이 이제 해당 페이지를 엽니다(컨트롤러가 아직
  시작 중일 때 TRIANGLE + CROSS를 놓치곤 했습니다).
- `KEY_READ_WAIT_TIME = 0`을 허용합니다(upstream의 최소값은 500 ms).
- 메모리 카드 / USB, MMCE, MX4SIO, HDD용 PS2 빌드. eGSM 2단계는 빠져 있습니다.

**RIPPS2에서 쓰는 방식**

RIPPS2는 BIBLE을 RIPPS2.elf 안에 담고 있으며 모든 빌드는 akilluminati47가 서명했습니다. 설정 > 일반 > Boot Loader > Manage에서 설치하거나 업데이트하고, 여기서 BIBLE의 키도 설정합니다: Background, Splash, Button Glyphs, Info Line, Power-on Wait, Video Mode, Widescreen. 서명된 빌드와 바로 쓰는 SD2PSX BOOT 카드는 [릴리스 페이지](https://github.com/akilluminati47/BIBLE/releases/latest)에 있습니다. BIBLE은 다른 로더(FMCB, OSDMenu, SD2PSX의 로더)가 실행하는 ELF로도 동작합니다.

<p align="center"><img src="assets/readme/ripps2-icon.png" alt="RIPPS2" width="48" height="48"><br><sub>BIBLE은 <a href="https://github.com/akilluminati47/RIPPS2">RIPPS2</a>의 일부입니다.</sub></p>

---

<p align="center"><sub>아래는 모두 PS2BBL Extended의 원래 README를 번역한 것이며, 다른 것은 바꾸지 않았습니다.</sub></p>

---


<br />
<p align="center">
  <a href="https://israpps.github.io/PlayStation2-Basic-BootLoader/">
    <img src="https://github.com/saildot4k/PlayStation2-Basic-BootLoader-Extended/blob/main/assets/ps2bbl_example.png" alt="Logo" width="50%" height="auto">
  </a>

  <p align="center">
    PlayStation 2™와 PSX-DESR을 위한 유연한 부트 로더
    <br />
  </p>
</p>  


이것은 [El Isra](https://github.com/israpps/PlayStation2-Basic-BootLoader/)가 만든 PS2BBL의 포크입니다


<a id="documentation"></a>

## 문서

[github pages](https://israpps.github.io/PlayStation2-Basic-BootLoader/)에 있지만, 아래 추가 사항이 있습니다:

<a id="config-and-arguments"></a>

## 설정과 인수

필요에 따라 설정 파일을 편집하세요. 편집에는 [R3Configurator](https://github.com/saildot4k/R3CONFIGURATOR)를 권장합니다. 경로는 이미 [PS2 Homebrew Store](https://ps2homebrewstore.com)의 다운로드에 맞춰 설정되어 있습니다. 그러니 Auto 선택만 편집하고, ISO를 불러오는 장치에 맞게 NHDDL 인수를 설정하는 것이 가장 좋습니다.

<a id="config-path-search-order"></a>

### 설정 파일 검색 순서

시작할 때 불필요한 드라이버를 불러오지 않도록, 설정 검색이 이제 부팅 계열을 고려합니다:

1. `CONFIG.INI`(CWD: 현재 작업 디렉터리)
2. 장치에서 불러왔을 때:
   - MMCE 부팅: `mmce?:/PS2BBL/CONFIG.INI`
   - MX4SIO 부팅: `mx4sio:/PS2BBL/CONFIG.INI`
   - APA HDD 부팅: `hdd0:__sysconf:pfs:/PS2BBL/CONFIG.INI`
   - BDM 부팅: `usb:/PS2BBL/CONFIG.INI` / `mass:/PS2BBL/CONFIG.INI` / `ata:/PS2BBL/CONFIG.INI`
3. 메모리 카드 예비:
   - PS2에서: `mc?:/SYS-CONF/PS2BBL.INI`
   - PSX-DESR에서: `mc?:/SYS-CONF/PSXBBL.INI`
4. PSX의 마지막 예비
   - `xfrom:/PS2BBL/CONFIG.INI`
5. `DISC_STOP_AT_BOOT=1로 컴파일했을 때
   - `cdrom0:/PS2BBL/CONFIG.INI`
   - 위 3번과 같은 메모리 카드 예비.

<a id="device-path-prefixes"></a>

### 장치 경로 접두사
PS2BBL은 다음 실행/설정 경로 접두사를 지원합니다:
- `mc0:/`, `mc1:/`, `mc?:/`
- `usb:/`(권장)와 `mass:/`(구식)

<a id="build-specific"></a>

#### 빌드별:  
- `mmce0:/`, `mmce1:/`, `mmce?:/` __MMCE 빌드__
- `mx4sio:/`(권장)와 `massX:/`(구식)  __MX4SIO 빌드__
- `hdd0:partition:pfs:/<path to elf>` __HDD 빌드__
- `xfrom:/` 경로 __PSX DESR 빌드__
- `ata:/` exFAT HDD용 BDM 장치
- `ilink:/`(BDM 대용량 저장소 루트) __아직 구현되지 않음__
- `DISC_STOP_AT_BOOT=1` 설정을 불러온 뒤 항상 광학 디스크를 멈추는 컴파일 프로필

### LOGO_DISPLAY
키 이름을 표시하려면 `LOGO_DISPLAY = 3`을 쓰세요. 이름은 `NAME_<BUTTON>`으로 정합니다.
  - `0` 로고와 콘솔 정보 없음
  - `1` 콘솔 정보
  - `2` PS2BBLE/PSXBBLE 로고와 콘솔 정보
  - `3` 설정 파일의 `NAME_BUTTON = <TITLE>`을 보여 주는 키 그래픽
    - 예:
      ```
      NAME_SQUARE = POPSLOADER
      ```

<a id="custom-splash-logo-from-cwd"></a>

#### CWD의 사용자 스플래시 로고
CWD(현재 작업 디렉터리)에 사용자 로고 파일(LOGO.BIN)이 있으면 내장된 PS2BBLE/PSXBBLE 로고를 대신합니다.

PNG를 기대하는 원시 파일로 변환하세요:
  - PNG는 RGBA 8비트 인덱스, 채널당 255색, 해상도 256x64여야 합니다.

  - 릴리스 패키지(스크립트는 릴리스 루트에 있음):
  ```bash
  python png_to_logo_rbga.py my_logo.png
  ```

  - 만든 `LOGO.BIN`을 PS2BBL Extended 옆에 두세요. [PS2 Homebrew Store](https://ps2store.com)의 다운로드를 쓴다면 `mc?:/BOOT/`여야 합니다

<a id="retrogem-visual-game-id"></a>

### Retrogem 시각적 게임 ID
- `APP_GAMEID = 1`은 파일 이름이나 PS1/2 디스크에서 가져온 최대 11자로 앱/homebrew의 시각적 게임 ID를 켭니다
- `CDROM_DISABLE_GAMEID = 1`은 `cdrom`으로 실행한 디스크의 시각적 게임 ID를 끕니다.

<a id="disc-spin-control"></a>

### 디스크 회전 제어
- 전역 키/값: `DISC_STOP = 0/1`
- `DISC_STOP = 1`은 설정 파일을 찾았을 때 설정을 불러온 뒤 광학 디스크를 멈춥니다.
- `DISC_STOP = 0`(또는 생략)은 기본 동작을 유지합니다.
- `-disc_stop`을 실행 항목마다 붙이면 대상 ELF를 찾은 뒤 디스크를 멈춥니다.

<a id="video-mode"></a>

### 비디오 모드
- `VIDEO_MODE = AUTO, NTSC, PAL, 480P` PS2 기본값을 쓰거나 다른 3개 모드 중 하나를 강제합니다.

<a id="emergency-video-mode-selector"></a>

#### 비상용 비디오 모드 선택기
- 부팅 중 `TRIANGLE + CROSS`로 들어갑니다
- 선택기는 켜져 있는 동안 `LOGO_DISPLAY = 3`을 강제해 로고와 키 화면을 볼 수 있게 합니다.
- 조작:
  - `LEFT/RIGHT`로 모드 전환: `AUTO`, `NTSC`, `PAL`, `480P`
  - `SELECT`로 선택한 모드를 사용 중인 설정 파일에 저장
  - `START`로 선택기를 나가 키 표시로 계속

<a id="cdrom-launch-args"></a>

### CDROM 실행 인수
`LK_*_E* = cdrom`에서 지원하는 인수:
- `-nologo`
- `-nogameid`
- `-ps1fast`
- `-ps1smooth`
- `-ps1vneg`
- `-gsm=<v[:c]>`

<a id="ps2logo-arguments-ps2-discs-only"></a>

#### PS2LOGO 인수(PS2 디스크만)
- 실행 항목의 경로로 `cdrom`을 쓰세요.
- 항목 인수에 `-nologo`를 더하면 PS2 디스크를 바로 부팅합니다(`rom0:PS2LOGO` 건너뜀).
- `-nologo`가 없으면 PS2BBL은 PS2LOGO를 거쳐 디스크를 실행하고, 항상 디스크 지역을 쓰며 로고 체크섬 검사를 건너뛰도록 패치합니다.
- DECKARD IE 75K 이후: 로고 없는 실행에 필요할 때 XPARAM.IRX를 자동으로 적용합니다.

<a id="ps1-disc-arguments-per-launch"></a>

#### PS1 디스크 인수(실행마다)
이 인수는 전역이 아니라 `cdrom` 실행 항목마다 적용됩니다.
- `-ps1fast`는 PS1 디스크 고속 읽기를 켭니다.
- `-ps1smooth`는 텍스처 스무딩을 켭니다.
- `-ps1vneg`는 PS1VModeNegator를 거쳐 PS1DRV를 실행합니다. 콘솔 모드와 디스크 모드가 다른 환경(예: 일부 MechaPwn/모드칩 경우)에서 유용합니다.

<a id="app-arguments"></a>

### 앱 인수
ELF에 인수를 넘기려면 `ARG_<BUTTON>_E? =` 줄을 쓰세요(INI 예시 참고).
- 실행하는 elf의 인수를 먼저 쓰고, 그 뒤에 원하는 PS2BBL 내부 인수를 붙이세요(아래 참고). [NHDDL](https://github.com/pcm720/nhddl)은 인수를 쓰기에 아주 좋은 후보로, 인수가 NHDDL의 부팅을 빠르게 해 줍니다.
- `-titleid=SLUS_123.45`는 앱의 타이틀 ID를 덮어씁니다(최대 11자).
- `-appid`는 `APP_GAMEID = 0`이어도 앱의 시각적 게임 ID를 강제합니다.
- `-disc_stop`은 대상 ELF를 불러온 뒤 디스크를 멈춥니다(`DISC_STOP_AT_BOOT` 빌드가 아닐 때 항목별로 유용).
- `-gsm=<v[:c]>`는 내장 eGSM을 거쳐 대상 ELF를 실행합니다(`rom?:` 경로에서는 무시). 쓴다면 마지막 인수여야 합니다.
- `-disc_stop`은 `cdrom` 실행 항목에서는 무시됩니다.
- `-dev9=<mode>`는 대상 ELF를 실행하기 전에 DEV9/HDD 정책을 정합니다. 지원 모드:
  - `NICHDD`는 DEV9(네트워크 어댑터)와 HDD 둘 다 켜 둡니다.
  - `NIC`는 DEV9/네트워크를 켜 두고, `pfs0:`을 마운트 해제하며, `hdd0:`/`hdd1:`을 즉시 대기 상태로 만듭니다.
  - 생략하면 PS2BBL은 DEV9 정책을 강제하지 않습니다.
  - 참고: HDD가 없는 빌드에서는 이 옵션이 효과가 없습니다.
- `-patinfo`는 `:PATINFO` 항목의 PATINFO 처리를 켭니다.
  - PS2BBL은 파티션 속성 영역(`PS2ICON3D`)에서 `SYSTEM.CNF`를 읽고 `BOOT2/BOOT/path`, `arg*`, `skip_argv0`, `HDDUNITPOWER`를 적용합니다.
  - `BOOT2/BOOT/path=PATINFO`이면 PS2BBL은 파티션 속성 영역에서 내장 ELF를 불러와 내부 `-la=E...` 인계를 씁니다.
  - `IOPRP=PATINFO`(또는 사용자 경로)이면 PS2BBL은 내부 `-la=I...` 인계로 2단계에 넘깁니다.
  - `-patinfo`가 있으면 남은 첫 인수가 CNF의 `BOOT2/BOOT/path` 대상을 덮어씁니다.
  HDD 빌드용입니다.  
  PATINFO 예:  
    ```
    NAME_R1 = My App via PATINFO
    LK_R1_E1 = hdd0:+OSDMENU:PATINFO
    ARG_R1_E1 = pfs:/APPS/MYAPP.ELF
    ARG_R1_E1 = -patinfo               # Tells PS2BBL to use first arg as patinfo boot path.
    ```

NHDDL을 비디오 모드 480p로 실행하고, nhddl.yaml 없이 mmce와 exfat HDD에서 ISO를 찾는 예입니다. 드라이버를 불러오거나 nhddl.yaml을 찾아 불러오는 데 시간을 낭비하지 않는 것이 장점입니다. NHDDL을 부팅해 ISO 목록을 보여 주는 가장 빠른 방법입니다.
```
NAME_R1 = NHDDL
LK_R1_E1 = mmce?:/NEUTRINO/nhddl.elf
ARG_R1_E1 = -video=480p
ARG_R1_E1 = -mode=mmce
ARG_R1_E1 = -mode=ata
```

<a id="argument-precedence-and-order"></a>

#### 인수의 우선순위와 순서
1. PS2BBL은 `ARG_*` 끝에 있는 로더 제어 인수만 해석해 소비합니다: `-appid`, `-titleid=`, `-dev9=`, `-patinfo`, `-disc_stop`, `-gsm=`.
2. 해석은 아래에서 위로 진행하며 제어 인수가 아닌 첫 인수에서 멈춥니다(OSDMenu 방식의 끝부분 처리).
4. `:PATINFO` 실행 경로에서 PS2BBL은 파티션 속성의 `SYSTEM.CNF`를 해석해 CNF의 `arg*` 항목을 사용자의 앱 인수 뒤에 덧붙입니다.
5. `-patinfo`가 설정되어 있고 실행 경로에 `:PATINFO`가 있으면, 사용자의 남은 첫 앱 인수가 대상 ELF 경로가 되며(CNF 부팅 경로를 덮어씀) 앱의 argv에서 빠집니다. 남은 인수가 없으면 실행을 중단하고(OSDMenu와 같음), CNF의 `BOOT2/BOOT/path`는 쓰지 않습니다.
6. 나머지 인수는 순서를 그대로 유지한 채 실행한 앱에 넘어갑니다.


### eGSM (external Graphics Synthesize Mode)
PS2 디스크에서는 eGSM을 `OSDGSM.CNF`에서 자동으로 읽습니다(INI 경로 설정 불필요). 설정 파일 형식은 [여기](https://github.com/pcm720/OSDMenu/blob/main/patcher/README.md#osdgsmcnf)를 보세요.

- `-gsm=<v[:c]>`는 내장 eGSM을 거쳐 대상 ELF를 실행합니다(`rom?:` 경로에서는 무시).
  - eGSM은 PS2BBL 자체가 아니라 실행하는 대상(ELF/디스크)에 적용됩니다.
  eGSM 형식(OSDMenu 방식):
- `v` = 비디오 모드:
- 비어 있음 = 강제하지 않음(기본값)
- `fp1` = 프로그레시브 스캔 강제(240p/288p)
- `fp2` = 프로그레시브 스캔 강제(480p/576p)
- `1080ix1` = 1080i 강제, 너비/높이 x1
- `1080ix2` = 1080i 강제, 너비/높이 x2
- `1080ix3` = 1080i 강제, 너비/높이 x3
- `c` = 호환 모드:
- 비어 있음 = 없음(기본값)
- `1` = 필드 뒤집기 유형 1
- `2` = 필드 뒤집기 유형 2
- `3` = 필드 뒤집기 유형 3

eGSM ARG 예:
- `-gsm=fp2`
- `-gsm=fp2:1`
- `-gsm=1080ix2`

사용 예:
```
LK_TRIANGLE_E1 = mc0:/APP_WLE-ISR/WLE-ISR.ELF
ARG_TRIANGLE_E1 = -gsm=1080ix2
```

<a id="deprecatedremoved"></a>

## 폐기/제거됨
- ~~`RUNKELF`~~ 이제 PS2BBLE이 elf/kelf 실행을 내부에서 처리하므로 사용자가 kelf 실행 동작을 정의할 필요가 없습니다.


<a id="known-bugsissues"></a>

## 알려진 버그/문제

여러분이 알려 주세요 ;)

<a id="credits--thanks"></a>

## 크레디트와 감사

- saildot4k로부터
  - [PS2BBL](https://github.com/israpps/PlayStation2-Basic-BootLoader/)의 @israpps
  - @pcm720:
    - [OSDMenu](https://github.com/pcm720/OSDMenu)의 Retrogem gameID, PS1 Video Negator, eGSM, PS2LOGO 코드
    - [NHDDL](https://github.com/pcm720/nhddl)의 비디오 모드 옵션
  - [PS1 Video Negator](https://github.com/ps2homebrew/PS1VModeNeg)의 @sp193
  - PS2BBLE의 10개 경로, 아이디어와 설득의 @nathanneurotic
  - 로고, 배경, 키 그래픽의 [@Berion](https://www.psx-place.com/members/berion.1431/)

- [El Isra](https://israpps.github.io/)(PS2BBL 개발자)로부터: 
  - 이 프로젝트의 토대인 OSD 초기화 라이브러리의 @SP193
  - 최신 SDK로 이 괴물을 만들도록 격려해 준 @asmblur
  - 늘 도와주는 @uyjulian과 @fjtrujy


<p align="center"><sub><a href="https://github.com/akilluminati47/RIPPS2">RIPPS2</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2/releases/latest/download/RIPPS2.elf">다운로드</a> &nbsp;&middot;&nbsp; <b>BIBLE</b> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2-themes">테마</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPCSX2">RIPPCSX2</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2-fonts">글꼴</a> &nbsp;&middot;&nbsp; <a href="https://akilluminati47.github.io/RIPPS2/">웹사이트</a> &nbsp;&middot;&nbsp; <a href="https://www.psx-place.com/threads/ripps2-a-ps2-front-end-in-one-elf-launch-disc-storage-memory-files.51316/">psx-place</a> &nbsp;&middot;&nbsp; <a href="https://discord.gg/Z7m9u5kby">Discord</a></sub></p>

