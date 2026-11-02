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
  <b>Galego</b> |
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

<p align="center"><sub>Tradución do README en inglés; se difiren, vale o inglés. <a href="README.md">English</a></sub></p>

<p align="center"><sub><a href="https://github.com/akilluminati47/RIPPS2">RIPPS2</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2/releases/latest/download/RIPPS2.elf">Descargar</a> &nbsp;&middot;&nbsp; <b>BIBLE</b> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2-themes">Temas</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPCSX2">RIPPCSX2</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2-fonts">Fontes</a> &nbsp;&middot;&nbsp; <a href="https://akilluminati47.github.io/RIPPS2/">Web</a> &nbsp;&middot;&nbsp; <a href="https://www.psx-place.com/threads/ripps2-a-ps2-front-end-in-one-elf-launch-disc-storage-memory-files.51316/">psx-place</a> &nbsp;&middot;&nbsp; <a href="https://discord.gg/Z7m9u5kby">Discord</a></sub></p>

<h1 align="center">BIBLE</h1>
<p align="center">
  <a href="https://github.com/akilluminati47/RIPPS2">RIPPS2</a> ·
  <a href="https://github.com/akilluminati47/BIBLE/actions">Compilacións</a> ·
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
  <sub>Mantén L2 + R2 ao arrancar para a páxina das teclas de lanzamento, TRIANGLE + CROSS para a páxina do modo de vídeo; unha tecla configurada como <code>$CREDITS</code> mostra os créditos.</sub>
</p>

BIBLE é o cargador de arranque que instala RIPPS2: un fork de PS2BBL Extended de saildot4k.

**Que cambia este fork**

- A pantalla de inicio: o logo da PS2 centrado no ceo de RIPPS2, cos botóns debaixo e calquera texto enriba.
  `BIBLE_GLYPHS` 0 ningún, 1 os botóns frontais (por defecto), 2 os dezaseis en dúas filas de oito.
  `BIBLE_INFO` 1 mostra a información da consola, o reloxo e a conta atrás (desactivado por defecto).
  O ceo coincide co teu Color Theme de RIPPS2: sen `BIBLE_COLOR`, BIBLE le o ceo que RIPPS2 garda cos seus
  axustes, desde o cartafol de RIPPS2 que inicia a súa entrada AUTO (`BIBLE_COLOR` na configuración manda).
  O mesmo aspecto en todos os modos de vídeo. As páxinas (modo de vídeo, créditos, teclas de lanzamento) aparecen sobre o logo atenuado
  cos botóns gardados, para que as teclas de lanzamento se lean con calma.
- Modos de vídeo: `VIDEO_MODE` tamén acepta `576P`, `720P` e `1080I`, o resto dos de RIPPS2. `AUTO` (por defecto)
  arranca no Video Mode de RIPPS2 cando atopa os seus axustes xunto á entrada AUTO, se non no da propia consola.
- `BIBLE_WIDESCREEN`: `AUTO` (por defecto: o Widescreen de RIPPS2, se non o axuste de pantalla 16:9 da PS2), `ON` ou
  `OFF`. En 480i, 576i, 480p e 576p a pantalla de inicio debúxase para un televisor que estira a imaxe a 16:9, sen
  esmagala. 720p e 1080i xa son 16:9.
- Sen salto ao entrar en RIPPS2: ao lanzar, o logo e os botóns esvaécense e o ceo queda na pantalla, no modo de RIPPS2;
  RIPPS2 arranca sobre ese mesmo ceo. Mantén TRIANGLE + CROSS ao arrancar para a páxina do modo de vídeo, que sempre se abre
  no modo entrelazado da propia consola (o camiño de volta desde 720p ou 1080i cun cable composto).
- Novo: a páxina das teclas de lanzamento. Mantén L2 + R2 ao arrancar para ler a ruta de lanzamento de cada tecla, sexan cales sexan os axustes de inicio.
- As combinacións mantidas desde o acendido abren agora as súas páxinas (TRIANGLE + CROSS perdíase mentres os mandos aínda
  se iniciaban).
- Permítese `KEY_READ_WAIT_TIME = 0` (o mínimo de upstream é 500 ms).
- Compilacións de PS2 para tarxeta de memoria / USB, MMCE, MX4SIO e HDD. A etapa 2 de eGSM queda fóra.

**Como o usa RIPPS2**

RIPPS2 levará BIBLE como ficheiros de arranque asinados e instalarao desde as súas Settings (Boot Loader), no canto do PS2BBL 1.2.0 que leva hoxe. BIBLE tamén funciona como un ELF iniciado por outro cargador (FMCB, OSDMenu, o cargador dun SD2PSX). Aínda non hai versión publicada de BIBLE.

<p align="center"><img src="assets/readme/ripps2-icon.png" alt="RIPPS2" width="48" height="48"><br><sub>BIBLE é parte de <a href="https://github.com/akilluminati47/RIPPS2">RIPPS2</a>.</sub></p>

---

<p align="center"><sub>Todo o que segue é o README orixinal de PS2BBL Extended, traducido sen outros cambios.</sub></p>

---


<br />
<p align="center">
  <a href="https://israpps.github.io/PlayStation2-Basic-BootLoader/">
    <img src="https://github.com/saildot4k/PlayStation2-Basic-BootLoader-Extended/blob/main/assets/ps2bbl_example.png" alt="Logo" width="50%" height="auto">
  </a>

  <p align="center">
    Un cargador de arranque flexible para PlayStation 2™ e PSX-DESR
    <br />
  </p>
</p>  


Este é un fork de PS2BBL de [El Isra](https://github.com/israpps/PlayStation2-Basic-BootLoader/)


## Documentación

Está aloxada en [github pages](https://israpps.github.io/PlayStation2-Basic-BootLoader/), pero cos engadidos de abaixo:

## Configuración e argumentos

Edita o ficheiro de configuración segundo precises. Recoméndase [R3Configurator](https://github.com/saildot4k/R3CONFIGURATOR) para editalo. As rutas xa veñen preparadas para coincidir coas descargas de [PS2 Homebrew Store](https://ps2homebrewstore.com). Así só deberías ter que editar a túa opción Auto e, mellor, poñer os argumentos de NHDDL segundo o dispositivo desde o que cargas as ISO.

### Orde de busca da configuración

A busca da configuración ten agora en conta a familia de arranque para non cargar controladores innecesarios ao iniciar:

1. `CONFIG.INI` (CWD: directorio de traballo actual)
2. Ao cargar desde un dispositivo:
   - Arranque MMCE: `mmce?:/PS2BBL/CONFIG.INI`
   - Arranque MX4SIO: `mx4sio:/PS2BBL/CONFIG.INI`
   - Arranque APA HDD: `hdd0:__sysconf:pfs:/PS2BBL/CONFIG.INI`
   - Arranque BDM: `usb:/PS2BBL/CONFIG.INI` / `mass:/PS2BBL/CONFIG.INI` / `ata:/PS2BBL/CONFIG.INI`
3. Reserva na tarxeta de memoria:
   - Na PS2: `mc?:/SYS-CONF/PS2BBL.INI`
   - Na PSX-DESR: `mc?:/SYS-CONF/PSXBBL.INI`
4. Última reserva na PSX
   - `xfrom:/PS2BBL/CONFIG.INI`
5. Se se compila con `DISC_STOP_AT_BOOT=1
   - `cdrom0:/PS2BBL/CONFIG.INI`
   - Reserva na tarxeta de memoria como no punto 3.

### Prefixos de ruta de dispositivo
PS2BBL admite estes prefixos de ruta de lanzamento/configuración:
- `mc0:/`, `mc1:/`, `mc?:/`
- `usb:/` (preferido) e `mass:/` (antigo)

#### Segundo a compilación:  
- `mmce0:/`, `mmce1:/`, `mmce?:/` __compilacións MMCE__
- `mx4sio:/` (preferido) e `massX:/` (antigo)  __compilacións MX4SIO__
- `hdd0:partition:pfs:/<path to elf>` __compilacións HDD__
- Rutas `xfrom:/` __compilacións PSX DESR__
- `ata:/` dispositivo BDM de HDD exFAT
- `ilink:/` (raíces de almacenamento masivo BDM) __aínda sen implementar__
- `DISC_STOP_AT_BOOT=1` perfil de compilación para deter sempre o disco óptico tras cargar a configuración

### LOGO_DISPLAY
Usa `LOGO_DISPLAY = 3` para mostrar os nomes das teclas. Os nomes defínense con `NAME_<BUTTON>`.
  - `0` Sen logo nin información da consola
  - `1` Información da consola
  - `2` Logo PS2BBLE/PSXBBLE e información da consola
  - `3` Gráfico de teclas con `NAME_BUTTON = <TITLE>` tomado do ficheiro de configuración
    - Exemplo:
      ```
      NAME_SQUARE = POPSLOADER
      ```

#### Logo de inicio propio desde o CWD
Se hai un ficheiro de logo propio (LOGO.BIN) no CWD (directorio de traballo actual), substitúe o logo PS2BBLE/PSXBBLE integrado.

Converte un PNG no ficheiro en bruto esperado:
  - O PNG debe ser RGBA de 8 bits indexado, 255 cores por canle e resolución 256x64.

  - Paquete da versión (o script está na raíz da versión):
  ```bash
  python png_to_logo_rbga.py my_logo.png
  ```

  - Pon o `LOGO.BIN` creado xunto a PS2BBL Extended. Debería ser `mc?:/BOOT/` se usas as descargas de [PS2 Homebrew Store](https://ps2store.com)

### ID visual de xogo de Retrogem
- `APP_GAMEID = 1` activa o ID visual de xogo para apps/homebrew, de ata 11 caracteres tomados do nome do ficheiro ou do disco de PS1/2
- `CDROM_DISABLE_GAMEID = 1` desactiva o ID visual de xogo para os discos lanzados con `cdrom`.

### Control do xiro do disco
- Clave/valor global: `DISC_STOP = 0/1`
- `DISC_STOP = 1` detén o disco óptico tras cargar a configuración cando se atopou un ficheiro de configuración.
- `DISC_STOP = 0` (ou omitido) mantén o comportamento por defecto.
- `-disc_stop` pódese engadir a cada entrada de lanzamento para deter o disco cando se atopa o ELF de destino.

### Modo de vídeo
- `VIDEO_MODE = AUTO, NTSC, PAL, 480P` Usa o modo por defecto da PS2 ou forza un dos outros 3 modos.

#### Selector de modo de vídeo de emerxencia
- Éntrase con `TRIANGLE + CROSS` durante o arranque
- O selector forza `LOGO_DISPLAY = 3` mentres está activo para que vexas o contexto do logo e das teclas.
- Controis:
  - `LEFT/RIGHT` percorren os modos: `AUTO`, `NTSC`, `PAL`, `480P`
  - `SELECT` garda o modo seleccionado no ficheiro de configuración activo
  - `START` sae do selector e continúa á pantalla de teclas

### Argumentos de lanzamento de CDROM
Para `LK_*_E* = cdrom`, os argumentos admitidos son:
- `-nologo`
- `-nogameid`
- `-ps1fast`
- `-ps1smooth`
- `-ps1vneg`
- `-gsm=<v[:c]>`

#### Argumentos de PS2LOGO (só discos de PS2)
- Usa `cdrom` como ruta da entrada de lanzamento.
- Engade `-nologo` aos argumentos da entrada para arrancar discos de PS2 directamente (sen `rom0:PS2LOGO`).
- Sen `-nologo`, PS2BBL arranca o disco a través de PS2LOGO e parchéao para usar sempre a rexión do disco e saltar a comprobación do checksum do logo.
- DECKARD IE 75K e posteriores: XPARAM.IRX aplícase automaticamente cando fai falla para os lanzamentos sen logo.

#### Argumentos de discos de PS1 (por lanzamento)
Aplícanse a cada entrada de lanzamento `cdrom`, non de forma global.
- `-ps1fast` activa a velocidade rápida do disco de PS1.
- `-ps1smooth` activa o suavizado de texturas.
- `-ps1vneg` executa PS1DRV a través de PS1VModeNegator. Útil en configuracións onde o modo da consola e o do disco difiren (por exemplo algúns casos de MechaPwn/modchip).

### Argumentos de apps
Usa liñas `ARG_<BUTTON>_E? =` para pasar argumentos a un ELF (mira os exemplos de INI).
- Pon primeiro os argumentos do elf lanzado e engade despois os argumentos internos de PS2BBL que queiras (ver abaixo). [NHDDL](https://github.com/pcm720/nhddl) é un gran candidato para usar argumentos, xa que aceleran o seu arranque.
- `-titleid=SLUS_123.45` substitúe o ID de título da app (ata 11 caracteres).
- `-appid` forza o ID visual de xogo da app aínda que `APP_GAMEID = 0`.
- `-disc_stop` detén o disco tras cargar o ELF de destino (útil por entrada sen compilacións `DISC_STOP_AT_BOOT`).
- `-gsm=<v[:c]>` executa o ELF de destino a través do eGSM integrado (ignórase nas rutas `rom?:`). Se se usa, debe ser o último argumento.
- `-disc_stop` ignórase nas entradas de lanzamento `cdrom`.
- `-dev9=<mode>` fixa a política de DEV9/HDD antes de lanzar o ELF de destino. Modos admitidos:
  - `NICHDD` mantén acendidos tanto DEV9 (adaptador de rede) como o HDD.
  - `NIC` mantén DEV9/rede acendidos, desmonta `pfs0:` e pon `hdd0:`/`hdd1:` en repouso inmediato.
  - se se omite, PS2BBL non forza ningunha política de DEV9.
  - nota: en compilacións sen HDD esta opción non ten efecto.
- `-patinfo` activa o manexo de PATINFO para as entradas `:PATINFO`.
  - PS2BBL le `SYSTEM.CNF` da área de atributos da partición (`PS2ICON3D`) e aplica `BOOT2/BOOT/path`, `arg*`, `skip_argv0` e `HDDUNITPOWER`.
  - se `BOOT2/BOOT/path=PATINFO`, PS2BBL carga o ELF integrado da área de atributos da partición e usa o traspaso interno `-la=E...`.
  - se `IOPRP=PATINFO` (ou unha ruta propia), PS2BBL pásallo á etapa 2 co traspaso interno `-la=I...`.
  - se `-patinfo` está presente, o primeiro argumento restante substitúe o destino `BOOT2/BOOT/path` do CNF.
  Isto é para compilacións HDD.  
  Exemplo de PATINFO:  
    ```
    NAME_R1 = My App via PATINFO
    LK_R1_E1 = hdd0:+OSDMENU:PATINFO
    ARG_R1_E1 = pfs:/APPS/MYAPP.ELF
    ARG_R1_E1 = -patinfo               # Tells PS2BBL to use first arg as patinfo boot path.
    ```

Exemplo para lanzar NHDDL en modo de vídeo 480p e buscar ISO en mmce e nun HDD exFAT sen necesitar nhddl.yaml. A vantaxe é non perder tempo cargando controladores nin buscando e cargando nhddl.yaml. É a forma máis rápida de arrancar NHDDL e mostrar a lista de ISO.
```
NAME_R1 = NHDDL
LK_R1_E1 = mmce?:/NEUTRINO/nhddl.elf
ARG_R1_E1 = -video=480p
ARG_R1_E1 = -mode=mmce
ARG_R1_E1 = -mode=ata
```

#### Precedencia e orde dos argumentos
1. PS2BBL analiza e consome só os argumentos finais de control do cargador de `ARG_*`: `-appid`, `-titleid=`, `-dev9=`, `-patinfo`, `-disc_stop`, `-gsm=`.
2. A análise vai de abaixo arriba e detense no primeiro argumento que non é de control (comportamento final ao estilo de OSDMenu).
4. Para rutas de lanzamento `:PATINFO`, PS2BBL analiza o `SYSTEM.CNF` do atributo da partición e engade as entradas `arg*` do CNF tras os argumentos da app do usuario.
5. Se `-patinfo` está activo e a ruta de lanzamento contén `:PATINFO`, o primeiro argumento restante do usuario pasa a ser a ruta do ELF de destino (substitúe a ruta de arranque do CNF) e quítase do argv da app. Se non queda ningún argumento, o lanzamento cancélase (igual que en OSDMenu) e non se usa o `BOOT2/BOOT/path` do CNF.
6. Os argumentos restantes conservan a súa orde e pásanse á app lanzada.


### eGSM (external Graphics Synthesize Mode)
Para discos de PS2, eGSM lese automaticamente de `OSDGSM.CNF` (non fai falla ningunha ruta no INI). Mira [aquí](https://github.com/pcm720/OSDMenu/blob/main/patcher/README.md#osdgsmcnf) o formato do ficheiro de configuración.

- `-gsm=<v[:c]>` executa o ELF de destino a través do eGSM integrado (ignórase nas rutas `rom?:`).
  - eGSM aplícase ao destino lanzado (ELF/disco), non ao propio PS2BBL.
  Formato de eGSM (ao estilo de OSDMenu):
- `v` = modo de vídeo:
- baleiro = non forzar (por defecto)
- `fp1` = forzar varrido progresivo (240p/288p)
- `fp2` = forzar varrido progresivo (480p/576p)
- `1080ix1` = forzar 1080i, ancho/alto x1
- `1080ix2` = forzar 1080i, ancho/alto x2
- `1080ix3` = forzar 1080i, ancho/alto x3
- `c` = modo de compatibilidade:
- baleiro = ningún (por defecto)
- `1` = inversión de campos tipo 1
- `2` = inversión de campos tipo 2
- `3` = inversión de campos tipo 3

Exemplos de ARG de eGSM:
- `-gsm=fp2`
- `-gsm=fp2:1`
- `-gsm=1080ix2`

Exemplo de uso:
```
LK_TRIANGLE_E1 = mc0:/APP_WLE-ISR/WLE-ISR.ELF
ARG_TRIANGLE_E1 = -gsm=1080ix2
```

## Obsoleto/Eliminado
- ~~`RUNKELF`~~ PS2BBLE agora lanza elf/kelf internamente sen que o usuario teña que definir unha acción de lanzamento kelf.


## Erros/problemas coñecidos

dimo ti ;)

## Créditos e agradecementos

- De saildot4k
  - @israpps por [PS2BBL](https://github.com/israpps/PlayStation2-Basic-BootLoader/)
  - @pcm720 por
    - O gameID de Retrogem, PS1 Video Negator, eGSM e o código de PS2LOGO de [OSDMenu](https://github.com/pcm720/OSDMenu)
    - As opcións de modo de vídeo de [NHDDL](https://github.com/pcm720/nhddl)
  - @sp193 por [PS1 Video Negator](https://github.com/ps2homebrew/PS1VModeNeg)
  - @nathanneurotic polas 10 rutas de PS2BBLE, as ideas e a persuasión
  - [@Berion](https://www.psx-place.com/members/berion.1431/) polos logos, o fondo e os gráficos de teclas

- De [El Isra](https://israpps.github.io/) (desenvolvedor de PS2BBL): 
  - @SP193 polas bibliotecas de inicialización do OSD, que son a base deste proxecto
  - @asmblur, por animarme a facer este monstro co SDK máis recente
  - @uyjulian e @fjtrujy por axudarme sempre


<p align="center"><sub><a href="https://github.com/akilluminati47/RIPPS2">RIPPS2</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2/releases/latest/download/RIPPS2.elf">Descargar</a> &nbsp;&middot;&nbsp; <b>BIBLE</b> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2-themes">Temas</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPCSX2">RIPPCSX2</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2-fonts">Fontes</a> &nbsp;&middot;&nbsp; <a href="https://akilluminati47.github.io/RIPPS2/">Web</a> &nbsp;&middot;&nbsp; <a href="https://www.psx-place.com/threads/ripps2-a-ps2-front-end-in-one-elf-launch-disc-storage-memory-files.51316/">psx-place</a> &nbsp;&middot;&nbsp; <a href="https://discord.gg/Z7m9u5kby">Discord</a></sub></p>

