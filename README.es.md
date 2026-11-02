<!-- i18n: the language bar, made by ps2-pillars tools/readme-i18n -->
<p align="center">
  <a href="README.md">English</a> |
  <b>Español</b> |
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
  <a href="README.id.md">Bahasa Indonesia</a> |
  <a href="README.fil.md">Filipino</a> |
  <a href="README.ceb.md">Cebuano</a>
</p>
<!-- /i18n -->

<p align="center"><sub>Traducción del README en inglés; si difieren, vale el inglés. <a href="README.md">English</a></sub></p>

<p align="center"><sub><a href="https://github.com/akilluminati47/RIPPS2">RIPPS2</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2/releases/latest/download/RIPPS2.elf">Descargar</a> &nbsp;&middot;&nbsp; <b>BIBLE</b> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2-themes">Temas</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPCSX2">RIPPCSX2</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2-fonts">Fuentes</a> &nbsp;&middot;&nbsp; <a href="https://akilluminati47.github.io/RIPPS2/">Web</a> &nbsp;&middot;&nbsp; <a href="https://www.psx-place.com/threads/ripps2-a-ps2-front-end-in-one-elf-launch-disc-storage-memory-files.51316/">psx-place</a> &nbsp;&middot;&nbsp; <a href="https://discord.gg/Z7m9u5kby">Discord</a></sub></p>

<h1 align="center">BIBLE</h1>
<p align="center">
  <a href="https://github.com/akilluminati47/RIPPS2">RIPPS2</a> ·
  <a href="https://github.com/akilluminati47/BIBLE/actions">Compilaciones</a> ·
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
  <sub>Mantén L2 + R2 al arrancar para la página de teclas de lanzamiento, TRIANGLE + CROSS para la página del modo de vídeo; una tecla configurada como <code>$CREDITS</code> muestra los créditos.</sub>
</p>

BIBLE es el cargador de arranque que instala RIPPS2: un fork de PS2BBL Extended de saildot4k.

**Qué cambia este fork**

- La pantalla de inicio: el logo de PS2 centrado sobre el cielo de RIPPS2, con los botones debajo y cualquier texto encima.
  `BIBLE_GLYPHS` 0 ninguno, 1 los botones frontales (por defecto), 2 los dieciséis en dos filas de ocho.
  `BIBLE_INFO` 1 muestra la información de la consola, el reloj y la cuenta atrás (desactivado por defecto).
  El cielo coincide con tu Color Theme de RIPPS2: sin `BIBLE_COLOR`, BIBLE lee el cielo que RIPPS2 guarda con sus
  ajustes, desde la carpeta de RIPPS2 que inicia su entrada AUTO (`BIBLE_COLOR` en la configuración manda).
  El mismo aspecto en todos los modos de vídeo. Las páginas (modo de vídeo, créditos, teclas de lanzamiento) aparecen sobre el logo atenuado
  con los botones guardados, así las teclas de lanzamiento se leen con calma.
- Modos de vídeo: `VIDEO_MODE` también acepta `576P`, `720P` y `1080I`, el resto de los de RIPPS2. `AUTO` (por defecto)
  arranca en el Video Mode de RIPPS2 cuando encuentra sus ajustes junto a la entrada AUTO, si no en el de la consola.
- `BIBLE_WIDESCREEN`: `AUTO` (por defecto: el Widescreen de RIPPS2, si no el ajuste de pantalla 16:9 de la PS2), `ON` u
  `OFF`. En 480i, 576i, 480p y 576p la pantalla de inicio se dibuja para un televisor que estira la imagen a 16:9, sin
  aplastarla. 720p y 1080i ya son 16:9.
- Sin salto al entrar en RIPPS2: al lanzar, el logo y los botones se desvanecen y el cielo se queda en pantalla, en el modo de RIPPS2;
  RIPPS2 arranca sobre ese mismo cielo. Mantén TRIANGLE + CROSS al arrancar para la página del modo de vídeo, que siempre se abre en
  el modo entrelazado de la propia consola (el camino de vuelta desde 720p o 1080i con un cable compuesto).
- Nuevo: la página de teclas de lanzamiento. Mantén L2 + R2 al arrancar para leer la ruta de lanzamiento de cada tecla, sean cuales sean tus ajustes de inicio.
- Las combinaciones mantenidas desde el encendido ahora abren sus páginas (TRIANGLE + CROSS se perdía mientras los mandos aún
  se iniciaban).
- Se permite `KEY_READ_WAIT_TIME = 0` (el mínimo de upstream es 500 ms).
- Compilaciones de PS2 para tarjeta de memoria / USB, MMCE, MX4SIO y HDD. La etapa 2 de eGSM queda fuera.

**Cómo lo usa RIPPS2**

RIPPS2 llevará BIBLE como archivos de arranque firmados y lo instalará desde sus Settings (Boot Loader), en lugar del PS2BBL 1.2.0 que lleva hoy. BIBLE también funciona como un ELF iniciado por otro cargador (FMCB, OSDMenu, el cargador de un SD2PSX). Todavía no hay versión publicada de BIBLE.

<p align="center"><img src="assets/readme/ripps2-icon.png" alt="RIPPS2" width="48" height="48"><br><sub>BIBLE es parte de <a href="https://github.com/akilluminati47/RIPPS2">RIPPS2</a>.</sub></p>

---

<p align="center"><sub>Todo lo que sigue es el README original de PS2BBL Extended, traducido sin otros cambios.</sub></p>

---


<br />
<p align="center">
  <a href="https://israpps.github.io/PlayStation2-Basic-BootLoader/">
    <img src="https://github.com/saildot4k/PlayStation2-Basic-BootLoader-Extended/blob/main/assets/ps2bbl_example.png" alt="Logo" width="50%" height="auto">
  </a>

  <p align="center">
    Un cargador de arranque flexible para PlayStation 2™ y PSX-DESR
    <br />
  </p>
</p>  


Este es un fork de PS2BBL de [El Isra](https://github.com/israpps/PlayStation2-Basic-BootLoader/)


## Documentación

Está alojada en [github pages](https://israpps.github.io/PlayStation2-Basic-BootLoader/) pero con los añadidos de abajo:

## Configuración y argumentos

Edita el archivo de configuración según necesites. Se recomienda [R3Configurator](https://github.com/saildot4k/R3CONFIGURATOR) para editar tu archivo de configuración. Las rutas ya vienen preparadas para coincidir con las descargas de [PS2 Homebrew Store](https://ps2homebrewstore.com). Así solo deberías tener que editar tu opción Auto y, mejor, poner los argumentos de NHDDL según el dispositivo desde el que cargas las ISO.

### Orden de búsqueda de la configuración

La búsqueda de configuración ahora tiene en cuenta la familia de arranque para no cargar controladores innecesarios al iniciar:

1. `CONFIG.INI` (CWD: directorio de trabajo actual)
2. Al cargar desde un dispositivo:
   - Arranque MMCE: `mmce?:/PS2BBL/CONFIG.INI`
   - Arranque MX4SIO: `mx4sio:/PS2BBL/CONFIG.INI`
   - Arranque APA HDD: `hdd0:__sysconf:pfs:/PS2BBL/CONFIG.INI`
   - Arranque BDM: `usb:/PS2BBL/CONFIG.INI` / `mass:/PS2BBL/CONFIG.INI` / `ata:/PS2BBL/CONFIG.INI`
3. Respaldo en tarjeta de memoria:
   - En PS2: `mc?:/SYS-CONF/PS2BBL.INI`
   - En PSX-DESR: `mc?:/SYS-CONF/PSXBBL.INI`
4. Último respaldo en PSX
   - `xfrom:/PS2BBL/CONFIG.INI`
5. Si se compila con `DISC_STOP_AT_BOOT=1
   - `cdrom0:/PS2BBL/CONFIG.INI`
   - Respaldo en tarjeta de memoria como en el punto 3.

### Prefijos de ruta de dispositivo
PS2BBL admite estos prefijos de ruta de lanzamiento/configuración:
- `mc0:/`, `mc1:/`, `mc?:/`
- `usb:/` (preferido) y `mass:/` (antiguo)

#### Según la compilación:  
- `mmce0:/`, `mmce1:/`, `mmce?:/` __compilaciones MMCE__
- `mx4sio:/` (preferido) y `massX:/` (antiguo)  __compilaciones MX4SIO__
- `hdd0:partition:pfs:/<path to elf>` __compilaciones HDD__
- Rutas `xfrom:/` __compilaciones PSX DESR__
- `ata:/` dispositivo BDM de HDD exFAT
- `ilink:/` (raíces de almacenamiento masivo BDM) __aún no implementado__
- `DISC_STOP_AT_BOOT=1` perfil de compilación para detener siempre el disco óptico tras cargar la configuración

### LOGO_DISPLAY
Usa `LOGO_DISPLAY = 3` para mostrar los nombres de las teclas. Los nombres se definen con `NAME_<BUTTON>`.
  - `0` Sin logo ni información de la consola
  - `1` Información de la consola
  - `2` Logo PS2BBLE/PSXBBLE e información de la consola
  - `3` Gráfico de teclas con `NAME_BUTTON = <TITLE>` tomado del archivo de configuración
    - Ejemplo:
      ```
      NAME_SQUARE = POPSLOADER
      ```

#### Logo de inicio propio desde el CWD
Si hay un archivo de logo propio (LOGO.BIN) en el CWD (directorio de trabajo actual), sustituye al logo PS2BBLE/PSXBBLE integrado.

Convierte un PNG al archivo en bruto esperado:
  - El PNG debe ser RGBA de 8 bits indexado, 255 colores por canal y resolución 256x64.

  - Paquete de la versión (el script está en la raíz de la versión):
  ```bash
  python png_to_logo_rbga.py my_logo.png
  ```

  - Coloca el `LOGO.BIN` creado junto a PS2BBL Extended. Debería ser `mc?:/BOOT/` si usas las descargas de [PS2 Homebrew Store](https://ps2store.com)

### ID visual de juego de Retrogem
- `APP_GAMEID = 1` activa el ID visual de juego para apps/homebrew, de hasta 11 caracteres tomados del nombre del archivo o del disco de PS1/2
- `CDROM_DISABLE_GAMEID = 1` desactiva el ID visual de juego para los discos lanzados con `cdrom`.

### Control del giro del disco
- Clave/valor global: `DISC_STOP = 0/1`
- `DISC_STOP = 1` detiene el disco óptico tras cargar la configuración cuando se encontró un archivo de configuración.
- `DISC_STOP = 0` (u omitido) mantiene el comportamiento por defecto.
- `-disc_stop` se puede añadir a cada entrada de lanzamiento para detener el disco cuando se encuentra el ELF de destino.

### Modo de vídeo
- `VIDEO_MODE = AUTO, NTSC, PAL, 480P` Usa el modo por defecto de la PS2 o fuerza uno de los otros 3 modos.

#### Selector de modo de vídeo de emergencia
- Se entra con `TRIANGLE + CROSS` durante el arranque
- El selector fuerza `LOGO_DISPLAY = 3` mientras está activo para que veas el contexto del logo y las teclas.
- Controles:
  - `LEFT/RIGHT` recorren los modos: `AUTO`, `NTSC`, `PAL`, `480P`
  - `SELECT` guarda el modo seleccionado en el archivo de configuración activo
  - `START` sale del selector y continúa a la pantalla de teclas

### Argumentos de lanzamiento de CDROM
Para `LK_*_E* = cdrom`, los argumentos admitidos son:
- `-nologo`
- `-nogameid`
- `-ps1fast`
- `-ps1smooth`
- `-ps1vneg`
- `-gsm=<v[:c]>`

#### Argumentos de PS2LOGO (solo discos de PS2)
- Usa `cdrom` como ruta de la entrada de lanzamiento.
- Añade `-nologo` a los argumentos de la entrada para arrancar discos de PS2 directamente (sin `rom0:PS2LOGO`).
- Sin `-nologo`, PS2BBL arranca el disco a través de PS2LOGO y lo parchea para usar siempre la región del disco y saltarse la comprobación del checksum del logo.
- DECKARD IE 75K y posteriores: XPARAM.IRX se aplica automáticamente cuando hace falta para los lanzamientos sin logo.

#### Argumentos de discos de PS1 (por lanzamiento)
Se aplican a cada entrada de lanzamiento `cdrom`, no de forma global.
- `-ps1fast` activa la velocidad rápida del disco de PS1.
- `-ps1smooth` activa el suavizado de texturas.
- `-ps1vneg` ejecuta PS1DRV a través de PS1VModeNegator. Útil en configuraciones donde el modo de la consola y el del disco difieren (por ejemplo algunos casos de MechaPwn/modchip).

### Argumentos de apps
Usa líneas `ARG_<BUTTON>_E? =` para pasar argumentos a un ELF (mira los ejemplos de INI).
- Pon primero los argumentos del elf lanzado y añade después los argumentos internos de PS2BBL que quieras (ver abajo). [NHDDL](https://github.com/pcm720/nhddl) es un gran candidato para usar argumentos, ya que acelera su arranque.
- `-titleid=SLUS_123.45` sustituye el ID de título de la app (hasta 11 caracteres).
- `-appid` fuerza el ID visual de juego de la app aunque `APP_GAMEID = 0`.
- `-disc_stop` detiene el disco tras cargar el ELF de destino (útil por entrada sin compilaciones `DISC_STOP_AT_BOOT`).
- `-gsm=<v[:c]>` ejecuta el ELF de destino a través del eGSM integrado (se ignora en rutas `rom?:`). Si se usa, debe ser el último argumento.
- `-disc_stop` se ignora en las entradas de lanzamiento `cdrom`.
- `-dev9=<mode>` fija la política de DEV9/HDD antes de lanzar el ELF de destino. Modos admitidos:
  - `NICHDD` mantiene encendidos tanto DEV9 (adaptador de red) como el HDD.
  - `NIC` mantiene DEV9/red encendidos, desmonta `pfs0:` y pone `hdd0:`/`hdd1:` en reposo inmediato.
  - si se omite, PS2BBL no fuerza ninguna política de DEV9.
  - nota: en compilaciones sin HDD esta opción no tiene efecto.
- `-patinfo` activa el manejo de PATINFO para las entradas `:PATINFO`.
  - PS2BBL lee `SYSTEM.CNF` del área de atributos de la partición (`PS2ICON3D`) y aplica `BOOT2/BOOT/path`, `arg*`, `skip_argv0` y `HDDUNITPOWER`.
  - si `BOOT2/BOOT/path=PATINFO`, PS2BBL carga el ELF integrado del área de atributos de la partición y usa el traspaso interno `-la=E...`.
  - si `IOPRP=PATINFO` (o una ruta propia), PS2BBL lo pasa a la etapa 2 con el traspaso interno `-la=I...`.
  - si `-patinfo` está presente, el primer argumento restante sustituye el destino `BOOT2/BOOT/path` del CNF.
  Esto es para compilaciones HDD.  
  Ejemplo de PATINFO:  
    ```
    NAME_R1 = My App via PATINFO
    LK_R1_E1 = hdd0:+OSDMENU:PATINFO
    ARG_R1_E1 = pfs:/APPS/MYAPP.ELF
    ARG_R1_E1 = -patinfo               # Tells PS2BBL to use first arg as patinfo boot path.
    ```

Ejemplo para lanzar NHDDL en modo de vídeo 480p y buscar ISO en mmce y en un HDD exFAT sin necesitar nhddl.yaml. La ventaja es no perder tiempo cargando controladores ni buscando y cargando nhddl.yaml. Es la forma más rápida de arrancar NHDDL y mostrar la lista de ISO.
```
NAME_R1 = NHDDL
LK_R1_E1 = mmce?:/NEUTRINO/nhddl.elf
ARG_R1_E1 = -video=480p
ARG_R1_E1 = -mode=mmce
ARG_R1_E1 = -mode=ata
```

#### Precedencia y orden de los argumentos
1. PS2BBL analiza y consume solo los argumentos finales de control del cargador de `ARG_*`: `-appid`, `-titleid=`, `-dev9=`, `-patinfo`, `-disc_stop`, `-gsm=`.
2. El análisis va de abajo arriba y se detiene en el primer argumento que no es de control (comportamiento final al estilo de OSDMenu).
4. Para rutas de lanzamiento `:PATINFO`, PS2BBL analiza el `SYSTEM.CNF` del atributo de la partición y añade las entradas `arg*` del CNF tras los argumentos de la app del usuario.
5. Si `-patinfo` está activo y la ruta de lanzamiento contiene `:PATINFO`, el primer argumento restante del usuario pasa a ser la ruta del ELF de destino (sustituye la ruta de arranque del CNF) y se quita del argv de la app. Si no queda ningún argumento, el lanzamiento se cancela (igual que OSDMenu) y no se usa el `BOOT2/BOOT/path` del CNF.
6. Los argumentos restantes conservan su orden y se pasan a la app lanzada.


### eGSM (external Graphics Synthesize Mode)
Para discos de PS2, eGSM se lee automáticamente de `OSDGSM.CNF` (no hace falta ninguna ruta en el INI). Mira [aquí](https://github.com/pcm720/OSDMenu/blob/main/patcher/README.md#osdgsmcnf) el formato del archivo de configuración.

- `-gsm=<v[:c]>` ejecuta el ELF de destino a través del eGSM integrado (se ignora en rutas `rom?:`).
  - eGSM se aplica al destino lanzado (ELF/disco), no al propio PS2BBL.
  Formato de eGSM (al estilo de OSDMenu):
- `v` = modo de vídeo:
- vacío = no forzar (por defecto)
- `fp1` = forzar escaneo progresivo (240p/288p)
- `fp2` = forzar escaneo progresivo (480p/576p)
- `1080ix1` = forzar 1080i, ancho/alto x1
- `1080ix2` = forzar 1080i, ancho/alto x2
- `1080ix3` = forzar 1080i, ancho/alto x3
- `c` = modo de compatibilidad:
- vacío = ninguno (por defecto)
- `1` = inversión de campos tipo 1
- `2` = inversión de campos tipo 2
- `3` = inversión de campos tipo 3

Ejemplos de ARG de eGSM:
- `-gsm=fp2`
- `-gsm=fp2:1`
- `-gsm=1080ix2`

Ejemplo de uso:
```
LK_TRIANGLE_E1 = mc0:/APP_WLE-ISR/WLE-ISR.ELF
ARG_TRIANGLE_E1 = -gsm=1080ix2
```

## Obsoleto/Eliminado
- ~~`RUNKELF`~~ PS2BBLE ahora lanza elf/kelf internamente sin que el usuario tenga que definir una acción de lanzamiento kelf.


## Errores/problemas conocidos

dímelo tú ;)

## Créditos y agradecimientos

- De saildot4k
  - @israpps por [PS2BBL](https://github.com/israpps/PlayStation2-Basic-BootLoader/)
  - @pcm720 por
    - El gameID de Retrogem, PS1 Video Negator, eGSM y el código de PS2LOGO de [OSDMenu](https://github.com/pcm720/OSDMenu)
    - Las opciones de modo de vídeo de [NHDDL](https://github.com/pcm720/nhddl)
  - @sp193 por [PS1 Video Negator](https://github.com/ps2homebrew/PS1VModeNeg)
  - @nathanneurotic por las 10 rutas de PS2BBLE, las ideas y la persuasión
  - [@Berion](https://www.psx-place.com/members/berion.1431/) por los logos, el fondo y los gráficos de teclas

- De [El Isra](https://israpps.github.io/) (desarrollador de PS2BBL): 
  - @SP193 por las bibliotecas de inicialización del OSD, que son la base de este proyecto
  - @asmblur, por animarme a hacer este monstruo con el SDK más reciente
  - @uyjulian y @fjtrujy por ayudarme siempre


<p align="center"><sub><a href="https://github.com/akilluminati47/RIPPS2">RIPPS2</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2/releases/latest/download/RIPPS2.elf">Descargar</a> &nbsp;&middot;&nbsp; <b>BIBLE</b> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2-themes">Temas</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPCSX2">RIPPCSX2</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2-fonts">Fuentes</a> &nbsp;&middot;&nbsp; <a href="https://akilluminati47.github.io/RIPPS2/">Web</a> &nbsp;&middot;&nbsp; <a href="https://www.psx-place.com/threads/ripps2-a-ps2-front-end-in-one-elf-launch-disc-storage-memory-files.51316/">psx-place</a> &nbsp;&middot;&nbsp; <a href="https://discord.gg/Z7m9u5kby">Discord</a></sub></p>

