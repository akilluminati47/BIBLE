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
  <b>日本語</b> |
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

<p align="center"><sub>英語の README の翻訳です。内容が異なる場合は英語版が正です。 <a href="README.md">English</a></sub></p>

<p align="center"><sub><a href="https://github.com/akilluminati47/RIPPS2">RIPPS2</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2/releases/latest/download/RIPPS2.elf">ダウンロード</a> &nbsp;&middot;&nbsp; <b>BIBLE</b> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2-themes">テーマ</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPCSX2">RIPPCSX2</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2-fonts">フォント</a> &nbsp;&middot;&nbsp; <a href="https://akilluminati47.github.io/RIPPS2/">ウェブサイト</a> &nbsp;&middot;&nbsp; <a href="https://www.psx-place.com/threads/ripps2-a-ps2-front-end-in-one-elf-launch-disc-storage-memory-files.51316/">psx-place</a> &nbsp;&middot;&nbsp; <a href="https://discord.gg/Z7m9u5kby">Discord</a></sub></p>

<h1 align="center">BIBLE</h1>
<p align="center">
  <a href="https://akilluminati47.github.io/BIBLE/">ウェブサイト</a> ·
  <a href="https://github.com/akilluminati47/RIPPS2">RIPPS2</a> ·
  <a href="https://github.com/akilluminati47/BIBLE/actions">ビルド</a> ·
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
  <sub>起動時に L2 + R2 を押し続けると起動キーのページ、TRIANGLE + CROSS でビデオモードのページが開きます。<code>$CREDITS</code> に設定したキーはクレジットを表示します。</sub>
</p>

BIBLE は RIPPS2 がセットアップするブートローダーで、saildot4k の PS2BBL Extended のフォークです。

**このフォークの変更点**

- スプラッシュ: RIPPS2 の空の中央に PS2 ロゴ、その下にボタン、上に文字（あれば）。`BIBLE_GLYPHS` 0 なし、1 アクションボタン（既定）、2 16 個すべてを 8 個ずつ 2 段で。`BIBLE_INFO` 1 で本体情報、時計、カウントダウンを表示（既定はオフ）。空は RIPPS2 の Color Theme に合わせます。`BIBLE_COLOR` がなければ、BIBLE は RIPPS2 が設定と一緒に保存する空を、AUTO エントリが起動するフォルダから、または AUTO エントリが SD2PSX、USB、HDD 上の RIPPS2 のときはメモリーカードの `RIPPS2` フォルダから読みます（設定ファイルの `BIBLE_COLOR` が優先）。どのビデオモードでも同じ見た目です。
- `BIBLE_BACKGROUND`: `AUTO`（既定: RIPPS2 の設定が見つかるか `BIBLE_COLOR` があれば空、なければ本体自身のモードで黒、普通のブートローダーと同じ）、`SKY` または `BLANK`（黒）。プログラムへの切り替えはどのみち数秒黒くなるので、黒ならそれと一続きに見えます。
- 起動音: RIPPS2 の Boot Sound On (fast) は `boot.adp` を BIBLE の設定ファイルの隣（`mc?:/SYS-CONF/boot.adp`）に置けます。どのドライブが起動するよりも前に RIPPS2 が読み込みます。BIBLE はこのファイルを読みません。RIPPS2 にフォルダを伝えるだけです。 **無音がいちばん速い起動です。** 取り決めと RIPPS2 側: [docs/boot-sound-handoff.md](docs/boot-sound-handoff.md)。
- RIPPS2 を最初に: 設定ファイルのひな形（`release/SYS-CONF/PS2BBL.INI`）と組み込みの既定値は、OSDMenu や FMCB より先に `mc?:/RIPPS2/RIPPS2.ELF` と `mmce?:/APPS/RIPPS2.ELF` を試し、ひな形には BIBLE 独自のキーが説明付きで並びます。各ページ（ビデオモード、クレジット、起動キー）は、ボタンをしまって暗くしたロゴの上にフェードインするので、起動キーが落ち着いて読めます。
- ビデオモード：`VIDEO_MODE` は `576P`、`720P`、`1080I` も受け付けます（RIPPS2 の残りのモード）。`AUTO`（既定）は
  AUTO エントリの隣に RIPPS2 の設定があればその Video Mode で、なければ本体自身のモードで起動します。
- `BIBLE_WIDESCREEN`：`AUTO`（既定：RIPPS2 の Widescreen、なければ PS2 の 16:9 画面設定）、`ON` または
  `OFF`。480i、576i、480p、576p では、映像を 16:9 に引き伸ばすテレビ向けにスプラッシュを描くので、
  潰れません。720p と 1080i は最初から 16:9 です。
- RIPPS2 への移行：起動時にロゴとボタンがフェードアウトし、本体が次のプログラムを読み込むまで空が残ります。読み込み中は画面が暗くなります（メモリーカード上の RIPPS2 でラボでは約 7 秒）。その後、RIPPS2 が同じビデオモードと同じ色で現れます。起動時に TRIANGLE + CROSS を押し続けるとビデオモードのページが開き、これは常に
  本体自身のインターレースモードで開きます（コンポジットケーブルで 720p や 1080i から戻る道）。
- 新機能: 起動キーのページ。電源投入時に L2 + R2 を押し続けると、BIBLE は何かを起動する前に止まり、スプラッシュの設定にかかわらず各キーの現在の起動パスを表示します（ほかに何も表示されない `LOGO_DISPLAY = 0` で便利です）。
- 電源投入時から押し続けたコンボでページが開くようになりました（コントローラーがまだ
  起動中だと TRIANGLE + CROSS を取りこぼしていました）。
- `KEY_READ_WAIT_TIME = 0` を許可しました（upstream の下限は 500 ms）。
- メモリーカード / USB、MMCE、MX4SIO、HDD 向けの PS2 ビルド。eGSM のステージ 2 は含めていません。

**RIPPS2 での使い方**

RIPPS2 は BIBLE を RIPPS2.elf の中に持っており、どのビルドも akilluminati47 が署名しています。設定 > 一般 > Boot Loader > Manage から導入や更新ができ、そこで BIBLE のキーも設定できます: Background、Splash、Button Glyphs、Info Line、Power-on Wait、Video Mode、Widescreen。署名済みビルドと SD2PSX 用の完成した BOOT カードは[リリースページ](https://github.com/akilluminati47/BIBLE/releases/latest)にあります。BIBLE はほかのローダー（FMCB、OSDMenu、SD2PSX のローダー）から起動する ELF としても動きます。

<p align="center"><img src="assets/readme/ripps2-icon.png" alt="RIPPS2" width="48" height="48"><br><sub>BIBLE は <a href="https://github.com/akilluminati47/RIPPS2">RIPPS2</a> の一部です。</sub></p>

---

<p align="center"><sub>以下はすべて PS2BBL Extended の元の README を翻訳したもので、ほかは何も変えていません。</sub></p>

---


<br />
<p align="center">
  <a href="https://israpps.github.io/PlayStation2-Basic-BootLoader/">
    <img src="https://github.com/saildot4k/PlayStation2-Basic-BootLoader-Extended/blob/main/assets/ps2bbl_example.png" alt="Logo" width="50%" height="auto">
  </a>

  <p align="center">
    PlayStation 2™ と PSX-DESR 向けの柔軟なブートローダー
    <br />
  </p>
</p>  


これは [El Isra](https://github.com/israpps/PlayStation2-Basic-BootLoader/) による PS2BBL のフォークです


<a id="documentation"></a>

## ドキュメント

[github pages](https://israpps.github.io/PlayStation2-Basic-BootLoader/) にありますが、以下の追加があります：

<a id="config-and-arguments"></a>

## 設定と引数

必要に応じて設定ファイルを編集してください。編集には [R3Configurator](https://github.com/saildot4k/R3CONFIGURATOR) をおすすめします。パスは [PS2 Homebrew Store](https://ps2homebrewstore.com) からのダウンロードに合わせて設定済みです。そのため Auto の選択を編集し、ISO を読み込むデバイスに合わせて NHDDL の引数を設定するだけで済むはずです。

<a id="config-path-search-order"></a>

### 設定ファイルの検索順

起動時に不要なドライバーを読み込まないよう、設定の検索はブートの系統を考慮するようになりました：

1. `CONFIG.INI`（CWD：現在の作業ディレクトリ）
2. デバイスから読み込まれた場合：
   - MMCE ブート：`mmce?:/PS2BBL/CONFIG.INI`
   - MX4SIO ブート：`mx4sio:/PS2BBL/CONFIG.INI`
   - APA HDD ブート：`hdd0:__sysconf:pfs:/PS2BBL/CONFIG.INI`
   - BDM ブート：`usb:/PS2BBL/CONFIG.INI` / `mass:/PS2BBL/CONFIG.INI` / `ata:/PS2BBL/CONFIG.INI`
3. メモリーカードの予備：
   - PS2 の場合：`mc?:/SYS-CONF/PS2BBL.INI`
   - PSX-DESR の場合：`mc?:/SYS-CONF/PSXBBL.INI`
4. PSX での最後の予備
   - `xfrom:/PS2BBL/CONFIG.INI`
5. `DISC_STOP_AT_BOOT=1 付きでコンパイルした場合
   - `cdrom0:/PS2BBL/CONFIG.INI`
   - 上の 3 と同じメモリーカードの予備。

<a id="device-path-prefixes"></a>

### デバイスパスの接頭辞
PS2BBL は次の起動/設定パスの接頭辞に対応しています：
- `mc0:/`, `mc1:/`, `mc?:/`
- `usb:/`（推奨）と `mass:/`（旧式）

<a id="build-specific"></a>

#### ビルドごと：  
- `mmce0:/`、`mmce1:/`、`mmce?:/` __MMCE ビルド__
- `mx4sio:/`（推奨）と `massX:/`（旧式）  __MX4SIO ビルド__
- `hdd0:partition:pfs:/<path to elf>` __HDD ビルド__
- `xfrom:/` パス __PSX DESR ビルド__
- `ata:/` exFAT HDD の BDM デバイス
- `ilink:/`（BDM マスストレージのルート）__未実装__
- `DISC_STOP_AT_BOOT=1` 設定の読み込み後に必ず光学ディスクを止めるコンパイル時プロファイル

### LOGO_DISPLAY
キー名を表示するには `LOGO_DISPLAY = 3` を使います。名前は `NAME_<BUTTON>` で定義します。
  - `0` ロゴも本体情報もなし
  - `1` 本体情報
  - `2` PS2BBLE/PSXBBLE ロゴと本体情報
  - `3` 設定ファイルの `NAME_BUTTON = <TITLE>` を表示するキーのグラフィック
    - 例：
      ```
      NAME_SQUARE = POPSLOADER
      ```

<a id="custom-splash-logo-from-cwd"></a>

#### CWD からの独自スプラッシュロゴ
CWD（現在の作業ディレクトリ）に独自のロゴファイル（LOGO.BIN）があると、内蔵の PS2BBLE/PSXBBLE ロゴの代わりに使われます。

PNG を想定どおりの生ファイルに変換します：
  - PNG は RGBA 8 ビットのインデックスカラー、チャンネルあたり 255 色、解像度 256x64 にしてください。

  - リリースパッケージ（スクリプトはリリースのルートにあります）：
  ```bash
  python png_to_logo_rbga.py my_logo.png
  ```

  - 作成した `LOGO.BIN` を PS2BBL Extended の隣に置きます。[PS2 Homebrew Store](https://ps2store.com) からのダウンロードを使っているなら `mc?:/BOOT/` になるはずです

<a id="retrogem-visual-game-id"></a>

### Retrogem の視覚的なゲーム ID
- `APP_GAMEID = 1` でアプリ/homebrew の視覚的なゲーム ID を有効にします。ファイル名または PS1/2 ディスクから最大 11 文字を取ります
- `CDROM_DISABLE_GAMEID = 1` で `cdrom` から起動したディスクの視覚的なゲーム ID を無効にします。

<a id="disc-spin-control"></a>

### ディスク回転の制御
- 全体のキー/値：`DISC_STOP = 0/1`
- `DISC_STOP = 1` は、設定ファイルが見つかった場合、設定の読み込み後に光学ディスクを止めます。
- `DISC_STOP = 0`（または省略）で既定の動作のままです。
- `-disc_stop` を起動エントリごとに付けると、対象の ELF が見つかった後にディスクを止めます。

<a id="video-mode"></a>

### ビデオモード
- `VIDEO_MODE = AUTO, NTSC, PAL, 480P` PS2 の既定を使うか、ほかの 3 つのモードのどれかを強制します。

<a id="emergency-video-mode-selector"></a>

#### 緊急用ビデオモード選択
- 起動中に `TRIANGLE + CROSS` で入ります
- 選択中は `LOGO_DISPLAY = 3` を強制するので、ロゴとキーの画面を見ながら操作できます。
- 操作：
  - `LEFT/RIGHT` でモードを切り替え：`AUTO`、`NTSC`、`PAL`、`480P`
  - `SELECT` で選んだモードを使用中の設定ファイルに保存
  - `START` で選択を終えてキー表示へ進む

<a id="cdrom-launch-args"></a>

### CDROM の起動引数
`LK_*_E* = cdrom` で使える引数：
- `-nologo`
- `-nogameid`
- `-ps1fast`
- `-ps1smooth`
- `-ps1vneg`
- `-gsm=<v[:c]>`

<a id="ps2logo-arguments-ps2-discs-only"></a>

#### PS2LOGO の引数（PS2 ディスクのみ）
- 起動エントリのパスには `cdrom` を使います。
- エントリの引数に `-nologo` を加えると PS2 ディスクを直接起動します（`rom0:PS2LOGO` を飛ばす）。
- `-nologo` がない場合、PS2BBL は PS2LOGO 経由でディスクを起動し、常にディスクのリージョンを使ってロゴのチェックサム確認を回避するようパッチします。
- DECKARD IE 75K 以降：ロゴなし起動で必要なときは XPARAM.IRX を自動で適用します。

<a id="ps1-disc-arguments-per-launch"></a>

#### PS1 ディスクの引数（起動ごと）
これらは全体ではなく、`cdrom` の起動エントリごとに適用されます。
- `-ps1fast` で PS1 ディスクの高速読み込みを有効にします。
- `-ps1smooth` でテクスチャのスムージングを有効にします。
- `-ps1vneg` で PS1VModeNegator 経由で PS1DRV を実行します。本体のモードとディスクのモードが違う環境で役立ちます（たとえば一部の MechaPwn/改造チップの例）。

<a id="app-arguments"></a>

### アプリの引数
ELF に引数を渡すには `ARG_<BUTTON>_E? =` の行を使います（INI の例を参照）。
- 起動する elf の引数を先に書き、その後に必要な PS2BBL 内部の引数を続けます（下記参照）。[NHDDL](https://github.com/pcm720/nhddl) は引数を使うのに最適で、NHDDL の起動が速くなります。
- `-titleid=SLUS_123.45` でアプリのタイトル ID を上書きします（最大 11 文字）。
- `-appid` で `APP_GAMEID = 0` でもアプリの視覚的なゲーム ID を強制します。
- `-disc_stop` で対象の ELF を読み込んだ後にディスクを止めます（`DISC_STOP_AT_BOOT` ビルドでない場合のエントリごとの指定に便利）。
- `-gsm=<v[:c]>` で内蔵の eGSM 経由で対象の ELF を実行します（`rom?:` パスでは無視）。使う場合は最後の引数にしてください。
- `-disc_stop` は `cdrom` の起動エントリでは無視されます。
- `-dev9=<mode>` で対象の ELF を起動する前に DEV9/HDD のポリシーを設定します。対応モード：
  - `NICHDD` は DEV9（ネットワークアダプター）と HDD の両方を電源オンのままにします。
  - `NIC` は DEV9/ネットワークをオンのままにし、`pfs0:` をアンマウントして `hdd0:`/`hdd1:` を即座にアイドルにします。
  - 省略した場合、PS2BBL は DEV9 のポリシーを強制しません。
  - 注意：HDD なしのビルドではこのオプションは効果がありません。
- `-patinfo` で `:PATINFO` エントリの PATINFO 処理を有効にします。
  - PS2BBL はパーティションの属性領域（`PS2ICON3D`）から `SYSTEM.CNF` を読み、`BOOT2/BOOT/path`、`arg*`、`skip_argv0`、`HDDUNITPOWER` を適用します。
  - `BOOT2/BOOT/path=PATINFO` の場合、PS2BBL はパーティションの属性領域から埋め込みの ELF を読み込み、内部の `-la=E...` の受け渡しを使います。
  - `IOPRP=PATINFO`（または独自のパス）の場合、PS2BBL は内部の `-la=I...` の受け渡しでステージ 2 に渡します。
  - `-patinfo` がある場合、残った最初の引数が CNF の `BOOT2/BOOT/path` の対象を上書きします。
  これは HDD ビルド向けです。  
  PATINFO の例：  
    ```
    NAME_R1 = My App via PATINFO
    LK_R1_E1 = hdd0:+OSDMENU:PATINFO
    ARG_R1_E1 = pfs:/APPS/MYAPP.ELF
    ARG_R1_E1 = -patinfo               # Tells PS2BBL to use first arg as patinfo boot path.
    ```

NHDDL をビデオモード 480p で起動し、nhddl.yaml なしで mmce と exfat の HDD から ISO を探す例です。ドライバーの読み込みや nhddl.yaml の検索と読み込みで時間を無駄にしないのが利点です。NHDDL を起動して ISO 一覧を表示する最速の方法です。
```
NAME_R1 = NHDDL
LK_R1_E1 = mmce?:/NEUTRINO/nhddl.elf
ARG_R1_E1 = -video=480p
ARG_R1_E1 = -mode=mmce
ARG_R1_E1 = -mode=ata
```

<a id="argument-precedence-and-order"></a>

#### 引数の優先順位と順序
1. PS2BBL は `ARG_*` の末尾にあるローダー制御用の引数だけを解析して取り除きます：`-appid`、`-titleid=`、`-dev9=`、`-patinfo`、`-disc_stop`、`-gsm=`。
2. 解析は下から上へ進み、制御用でない最初の引数で止まります（OSDMenu 式の末尾の扱い）。
4. `:PATINFO` の起動パスでは、PS2BBL はパーティション属性の `SYSTEM.CNF` を解析し、CNF の `arg*` エントリをユーザーのアプリ引数の後に追加します。
5. `-patinfo` が設定され、起動パスに `:PATINFO` が含まれる場合、ユーザーのアプリ引数のうち残った最初のものが対象の ELF のパスになり（CNF のブートパスを上書き）、アプリの argv から取り除かれます。残る引数がない場合は起動を中止し（OSDMenu と同じ）、CNF の `BOOT2/BOOT/path` は使いません。
6. 残りの引数は順序を保ったまま起動するアプリに渡されます。


### eGSM (external Graphics Synthesize Mode)
PS2 ディスクでは、eGSM は `OSDGSM.CNF` から自動で読み込まれます（INI でのパス設定は不要）。設定ファイルの形式は[こちら](https://github.com/pcm720/OSDMenu/blob/main/patcher/README.md#osdgsmcnf)を参照してください。

- `-gsm=<v[:c]>` で内蔵の eGSM 経由で対象の ELF を実行します（`rom?:` パスでは無視）。
  - eGSM は起動する対象（ELF/ディスク）に適用され、PS2BBL 自体には適用されません。
  eGSM の形式（OSDMenu 式）：
- `v` = ビデオモード：
- 空 = 強制しない（既定）
- `fp1` = プログレッシブ走査を強制（240p/288p）
- `fp2` = プログレッシブ走査を強制（480p/576p）
- `1080ix1` = 1080i を強制、幅/高さ x1
- `1080ix2` = 1080i を強制、幅/高さ x2
- `1080ix3` = 1080i を強制、幅/高さ x3
- `c` = 互換モード：
- 空 = なし（既定）
- `1` = フィールド反転 タイプ 1
- `2` = フィールド反転 タイプ 2
- `3` = フィールド反転 タイプ 3

eGSM の ARG の例：
- `-gsm=fp2`
- `-gsm=fp2:1`
- `-gsm=1080ix2`

使用例：
```
LK_TRIANGLE_E1 = mc0:/APP_WLE-ISR/WLE-ISR.ELF
ARG_TRIANGLE_E1 = -gsm=1080ix2
```

<a id="deprecatedremoved"></a>

## 非推奨/削除
- ~~`RUNKELF`~~ PS2BBLE は elf/kelf の起動を内部で処理するようになり、ユーザーが kelf の起動アクションを定義する必要はなくなりました。


<a id="known-bugsissues"></a>

## 既知のバグ/問題

あなたが教えて ;)

<a id="credits--thanks"></a>

## クレジットと謝辞

- saildot4k より
  - [PS2BBL](https://github.com/israpps/PlayStation2-Basic-BootLoader/) の @israpps
  - @pcm720：
    - [OSDMenu](https://github.com/pcm720/OSDMenu) の Retrogem gameID、PS1 Video Negator、eGSM、PS2LOGO のコード
    - [NHDDL](https://github.com/pcm720/nhddl) のビデオモードのオプション
  - [PS1 Video Negator](https://github.com/ps2homebrew/PS1VModeNeg) の @sp193
  - PS2BBLE の 10 パス、アイデア、説得の @nathanneurotic
  - ロゴ、背景、キーのグラフィックの [@Berion](https://www.psx-place.com/members/berion.1431/)

- [El Isra](https://israpps.github.io/)（PS2BBL の開発者）より： 
  - このプロジェクトの土台となる OSD 初期化ライブラリの @SP193
  - 最新の SDK でこの怪物を作るよう励ましてくれた @asmblur
  - いつも助けてくれる @uyjulian と @fjtrujy


<p align="center"><sub><a href="https://github.com/akilluminati47/RIPPS2">RIPPS2</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2/releases/latest/download/RIPPS2.elf">ダウンロード</a> &nbsp;&middot;&nbsp; <b>BIBLE</b> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2-themes">テーマ</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPCSX2">RIPPCSX2</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2-fonts">フォント</a> &nbsp;&middot;&nbsp; <a href="https://akilluminati47.github.io/RIPPS2/">ウェブサイト</a> &nbsp;&middot;&nbsp; <a href="https://www.psx-place.com/threads/ripps2-a-ps2-front-end-in-one-elf-launch-disc-storage-memory-files.51316/">psx-place</a> &nbsp;&middot;&nbsp; <a href="https://discord.gg/Z7m9u5kby">Discord</a></sub></p>

