<!-- i18n: the language bar, made by ps2-pillars tools/readme-i18n -->
<p align="center">
  <a href="README.md">English</a> |
  <a href="README.es.md">Español</a> |
  <a href="README.pt-BR.md">Português (Brasil)</a> |
  <a href="README.pt.md">Português</a> |
  <a href="README.fr.md">Français</a> |
  <a href="README.de.md">Deutsch</a> |
  <b>Italiano</b> |
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

<p align="center"><sub>Traduzione del README inglese; se differiscono, vale l’inglese. <a href="README.md">English</a></sub></p>

<p align="center"><sub><a href="https://github.com/akilluminati47/RIPPS2">RIPPS2</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2/releases/latest/download/RIPPS2.elf">Scarica</a> &nbsp;&middot;&nbsp; <b>BIBLE</b> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2-themes">Temi</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPCSX2">RIPPCSX2</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2-fonts">Font</a> &nbsp;&middot;&nbsp; <a href="https://akilluminati47.github.io/RIPPS2/">Sito</a> &nbsp;&middot;&nbsp; <a href="https://www.psx-place.com/threads/ripps2-a-ps2-front-end-in-one-elf-launch-disc-storage-memory-files.51316/">psx-place</a> &nbsp;&middot;&nbsp; <a href="https://discord.gg/Z7m9u5kby">Discord</a></sub></p>

<h1 align="center">BIBLE</h1>
<p align="center">
  <a href="https://akilluminati47.github.io/BIBLE/">Sito</a> ·
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
  <sub>Tieni premuti L2 + R2 all'avvio per la pagina dei tasti di avvio, TRIANGLE + CROSS per la pagina della modalità video; un tasto impostato su <code>$CREDITS</code> mostra i crediti.</sub>
</p>

BIBLE è il boot loader che RIPPS2 installa: un fork di PS2BBL Extended di saildot4k.

**Cosa cambia questo fork**

- La schermata iniziale: il logo PS2 al centro del cielo di RIPPS2, con i tasti sotto e l'eventuale testo sopra. `BIBLE_GLYPHS` 0 nessuno, 1 i tasti azione (predefinito), 2 tutti e sedici in due file da otto. `BIBLE_INFO` 1 mostra informazioni sulla console, orologio e conto alla rovescia (spento di default). Il cielo segue il tuo Color Theme di RIPPS2: senza `BIBLE_COLOR`, BIBLE legge il cielo che RIPPS2 salva con le sue impostazioni, dalla cartella che avvia la sua voce AUTO, o dalla cartella `RIPPS2` di una memory card quando la voce AUTO è RIPPS2 su un SD2PSX, una USB o l'HDD (`BIBLE_COLOR` nella configurazione ha la precedenza). Lo stesso aspetto in ogni modalità video.
- `BIBLE_BACKGROUND`: `AUTO` (predefinito: il cielo quando si trovano le impostazioni di RIPPS2 o `BIBLE_COLOR` è impostato, altrimenti nero nella modalità propria della console, un boot loader semplice), `SKY` o `BLANK` (nero). Il passaggio a un programma è comunque nero per qualche secondo, così il nero si legge come un tutt'uno con esso.
- Il suono di avvio: il Boot Sound On (fast) di RIPPS2 può tenere `boot.adp` accanto alla configurazione di BIBLE (`mc?:/SYS-CONF/boot.adp`), e RIPPS2 lo legge prima dell'avvio di qualsiasi unità. BIBLE non lo legge mai: indica solo la cartella a RIPPS2. **Senza suono è l'avvio più rapido.** L'accordo e la parte di RIPPS2: [docs/boot-sound-handoff.md](docs/boot-sound-handoff.md).
- Prima RIPPS2: il modello di configurazione (`release/SYS-CONF/PS2BBL.INI`) e i valori interni provano `mc?:/RIPPS2/RIPPS2.ELF` e `mmce?:/APPS/RIPPS2.ELF` prima di OSDMenu e FMCB, e il modello elenca le chiavi di BIBLE con note. Le pagine (modalità video, crediti, tasti di avvio) compaiono in dissolvenza sul logo scurito con i tasti messi via, così i tasti di avvio si leggono con calma.
- Modalità video: `VIDEO_MODE` accetta anche `576P`, `720P` e `1080I`, le altre di RIPPS2. `AUTO` (predefinito)
  parte nel Video Mode di RIPPS2 quando ne trova le impostazioni accanto alla voce AUTO, altrimenti in quello della console.
- `BIBLE_WIDESCREEN`: `AUTO` (predefinito: il Widescreen di RIPPS2, altrimenti l'impostazione schermo 16:9 della PS2), `ON` o
  `OFF`. In 480i, 576i, 480p e 576p la schermata iniziale è disegnata per un televisore che allarga l'immagine a 16:9, senza
  schiacciarla. 720p e 1080i sono già 16:9.
- Il passaggio a RIPPS2: all'avvio il logo e i tasti svaniscono e il cielo resta finché la console non carica il programma successivo, che oscura lo schermo (circa 7 s in laboratorio con RIPPS2 su una memory card). Poi RIPPS2 appare nella stessa modalità video e con gli stessi colori. Tieni premuti TRIANGLE + CROSS all'avvio per la pagina della modalità video, che si apre sempre
  nella modalità interlacciata della console (la via del ritorno da 720p o 1080i con un cavo composito).
- Novità: la pagina dei tasti di avvio. Tieni premuti L2 + R2 all'accensione e BIBLE si ferma prima di avviare qualsiasi cosa, mostrando i percorsi di avvio attuali di ogni tasto, qualunque siano le impostazioni della schermata iniziale (utile con `LOGO_DISPLAY = 0`, dove non compare altro).
- Le combinazioni tenute premute dall'accensione ora aprono le loro pagine (TRIANGLE + CROSS si perdeva mentre i controller erano ancora
  in avvio).
- `KEY_READ_WAIT_TIME = 0` è consentito (il minimo di upstream è 500 ms).
- Build per PS2 per memory card / USB, MMCE, MX4SIO e HDD. La fase 2 di eGSM è esclusa.

**Come lo usa RIPPS2**

RIPPS2 porta BIBLE dentro RIPPS2.elf, ogni build firmata da akilluminati47, e lo installa o aggiorna da Impostazioni > Generale > Boot Loader > Manage, che imposta anche le chiavi di BIBLE: Background, Splash, Button Glyphs, Info Line, Power-on Wait, Video Mode e Widescreen. Le build firmate e una card BOOT per SD2PSX pronta sono nella [pagina delle release](https://github.com/akilluminati47/BIBLE/releases/latest). BIBLE funziona anche come ELF avviato da un altro loader (FMCB, OSDMenu, il loader di un SD2PSX).

<p align="center"><img src="assets/readme/ripps2-icon.png" alt="RIPPS2" width="48" height="48"><br><sub>BIBLE fa parte di <a href="https://github.com/akilluminati47/RIPPS2">RIPPS2</a>.</sub></p>

---

<p align="center"><sub>Tutto quello che segue è il README originale di PS2BBL Extended, tradotto senza altre modifiche.</sub></p>

---


<br />
<p align="center">
  <a href="https://israpps.github.io/PlayStation2-Basic-BootLoader/">
    <img src="https://github.com/saildot4k/PlayStation2-Basic-BootLoader-Extended/blob/main/assets/ps2bbl_example.png" alt="Logo" width="50%" height="auto">
  </a>

  <p align="center">
    Un boot loader flessibile per PlayStation 2™ e PSX-DESR
    <br />
  </p>
</p>  


Questo è un fork di PS2BBL di [El Isra](https://github.com/israpps/PlayStation2-Basic-BootLoader/)


<a id="documentation"></a>

## Documentazione

È ospitata su [github pages](https://israpps.github.io/PlayStation2-Basic-BootLoader/), ma con le aggiunte qui sotto:

<a id="config-and-arguments"></a>

## Configurazione e argomenti

Modifica il file di configurazione come serve. Per modificarlo si consiglia [R3Configurator](https://github.com/saildot4k/R3CONFIGURATOR). I percorsi sono già impostati per coincidere con i download del [PS2 Homebrew Store](https://ps2homebrewstore.com). Così dovresti dover modificare solo la tua scelta Auto e, meglio ancora, impostare gli argomenti di NHDDL in base al dispositivo da cui carichi le ISO.

<a id="config-path-search-order"></a>

### Ordine di ricerca della configurazione

La ricerca della configurazione ora tiene conto della famiglia di avvio, per non caricare driver inutili all'avvio:

1. `CONFIG.INI` (CWD: directory di lavoro corrente)
2. Se caricato da un dispositivo:
   - Avvio da MMCE: `mmce?:/PS2BBL/CONFIG.INI`
   - Avvio da MX4SIO: `mx4sio:/PS2BBL/CONFIG.INI`
   - Avvio da APA HDD: `hdd0:__sysconf:pfs:/PS2BBL/CONFIG.INI`
   - Avvio da BDM: `usb:/PS2BBL/CONFIG.INI` / `mass:/PS2BBL/CONFIG.INI` / `ata:/PS2BBL/CONFIG.INI`
3. Ripiego sulla memory card:
   - Su PS2: `mc?:/SYS-CONF/PS2BBL.INI`
   - Su PSX-DESR: `mc?:/SYS-CONF/PSXBBL.INI`
4. Ultimo ripiego su PSX
   - `xfrom:/PS2BBL/CONFIG.INI`
5. Se compilato con `DISC_STOP_AT_BOOT=1
   - `cdrom0:/PS2BBL/CONFIG.INI`
   - Ripiego sulla memory card come al punto 3 sopra.

<a id="device-path-prefixes"></a>

### Prefissi dei percorsi dei dispositivi
PS2BBL supporta questi prefissi per i percorsi di avvio/configurazione:
- `mc0:/`, `mc1:/`, `mc?:/`
- `usb:/` (preferito) e `mass:/` (vecchio)

<a id="build-specific"></a>

#### A seconda della build:  
- `mmce0:/`, `mmce1:/`, `mmce?:/` __build MMCE__
- `mx4sio:/` (preferito) e `massX:/` (vecchio)  __build MX4SIO__
- `hdd0:partition:pfs:/<path to elf>` __build HDD__
- Percorsi `xfrom:/` __build PSX DESR__
- `ata:/` dispositivo BDM per HDD exFAT
- `ilink:/` (radici di archiviazione di massa BDM) __non ancora implementato__
- `DISC_STOP_AT_BOOT=1` profilo di compilazione per fermare sempre il disco ottico dopo il caricamento della configurazione

### LOGO_DISPLAY
Usa `LOGO_DISPLAY = 3` per mostrare i nomi dei tasti. I nomi si definiscono con `NAME_<BUTTON>`.
  - `0` Niente logo né informazioni della console
  - `1` Informazioni della console
  - `2` Logo PS2BBLE/PSXBBLE e informazioni della console
  - `3` Grafica dei tasti con `NAME_BUTTON = <TITLE>` preso dal file di configurazione
    - Esempio:
      ```
      NAME_SQUARE = POPSLOADER
      ```

<a id="custom-splash-logo-from-cwd"></a>

#### Logo iniziale personalizzato dal CWD
Se nel CWD (directory di lavoro corrente) si trova un file di logo personalizzato (LOGO.BIN), sostituisce il logo PS2BBLE/PSXBBLE integrato.

Converti un PNG nel file grezzo atteso:
  - Il PNG deve essere RGBA a 8 bit indicizzato, 255 colori per canale e risoluzione 256x64.

  - Pacchetto della release (lo script è nella radice della release):
  ```bash
  python png_to_logo_rbga.py my_logo.png
  ```

  - Metti il `LOGO.BIN` creato accanto a PS2BBL Extended. Dovrebbe essere `mc?:/BOOT/` se usi i download del [PS2 Homebrew Store](https://ps2store.com)

<a id="retrogem-visual-game-id"></a>

### ID visivo del gioco di Retrogem
- `APP_GAMEID = 1` attiva l'ID visivo del gioco per app/homebrew, fino a 11 caratteri presi dal nome del file o dal disco PS1/2
- `CDROM_DISABLE_GAMEID = 1` disattiva l'ID visivo del gioco per i dischi avviati tramite `cdrom`.

<a id="disc-spin-control"></a>

### Controllo della rotazione del disco
- Chiave/valore globale: `DISC_STOP = 0/1`
- `DISC_STOP = 1` ferma il disco ottico dopo il caricamento della configurazione, se è stato trovato un file di configurazione.
- `DISC_STOP = 0` (o omesso) mantiene il comportamento predefinito.
- `-disc_stop` si può aggiungere a ogni voce di avvio per fermare il disco una volta trovato l'ELF di destinazione.

<a id="video-mode"></a>

### Modalità video
- `VIDEO_MODE = AUTO, NTSC, PAL, 480P` Usa la modalità predefinita della PS2 o forza una delle altre 3.

<a id="emergency-video-mode-selector"></a>

#### Selettore di emergenza della modalità video
- Si apre con `TRIANGLE + CROSS` durante l'avvio
- Il selettore forza `LOGO_DISPLAY = 3` mentre è attivo, così vedi il contesto del logo e dei tasti.
- Comandi:
  - `LEFT/RIGHT` scorrono le modalità: `AUTO`, `NTSC`, `PAL`, `480P`
  - `SELECT` salva la modalità scelta nel file di configurazione attivo
  - `START` esce dal selettore e passa alla schermata dei tasti

<a id="cdrom-launch-args"></a>

### Argomenti di avvio da CDROM
Per `LK_*_E* = cdrom`, gli argomenti supportati sono:
- `-nologo`
- `-nogameid`
- `-ps1fast`
- `-ps1smooth`
- `-ps1vneg`
- `-gsm=<v[:c]>`

<a id="ps2logo-arguments-ps2-discs-only"></a>

#### Argomenti di PS2LOGO (solo dischi PS2)
- Usa `cdrom` come percorso della voce di avvio.
- Aggiungi `-nologo` agli argomenti della voce per avviare direttamente i dischi PS2 (salta `rom0:PS2LOGO`).
- Senza `-nologo`, PS2BBL avvia il disco tramite PS2LOGO e lo modifica per usare sempre la regione del disco e saltare il controllo del checksum del logo.
- DECKARD IE 75K e successive: XPARAM.IRX viene applicato automaticamente quando serve per gli avvii senza logo.

<a id="ps1-disc-arguments-per-launch"></a>

#### Argomenti dei dischi PS1 (per avvio)
Valgono per ogni voce di avvio `cdrom`, non in modo globale.
- `-ps1fast` attiva la velocità rapida del disco PS1.
- `-ps1smooth` attiva lo smussamento delle texture.
- `-ps1vneg` avvia PS1DRV tramite PS1VModeNegator. Utile nelle configurazioni in cui la modalità della console e quella del disco differiscono (per esempio alcuni casi MechaPwn/modchip).

<a id="app-arguments"></a>

### Argomenti delle app
Usa righe `ARG_<BUTTON>_E? =` per passare argomenti a un ELF (vedi gli esempi INI).
- Metti prima gli argomenti dell'elf avviato e poi aggiungi gli argomenti interni di PS2BBL che vuoi (vedi sotto). [NHDDL](https://github.com/pcm720/nhddl) è un ottimo candidato per gli argomenti, perché ne accelerano l'avvio.
- `-titleid=SLUS_123.45` sostituisce l'ID del titolo dell'app (fino a 11 caratteri).
- `-appid` forza l'ID visivo del gioco dell'app anche con `APP_GAMEID = 0`.
- `-disc_stop` ferma il disco dopo il caricamento dell'ELF di destinazione (utile per voce senza build `DISC_STOP_AT_BOOT`).
- `-gsm=<v[:c]>` avvia l'ELF di destinazione tramite l'eGSM integrato (ignorato per i percorsi `rom?:`). Se usato, deve essere l'ultimo argomento.
- `-disc_stop` è ignorato per le voci di avvio `cdrom`.
- `-dev9=<mode>` imposta la politica DEV9/HDD prima di avviare l'ELF di destinazione. Modalità supportate:
  - `NICHDD` tiene accesi sia DEV9 (adattatore di rete) sia l'HDD.
  - `NIC` tiene accesi DEV9/rete, smonta `pfs0:` e mette `hdd0:`/`hdd1:` subito in standby.
  - se omesso, PS2BBL non forza alcuna politica DEV9.
  - nota: nelle build senza HDD questa opzione non ha effetto.
- `-patinfo` attiva la gestione di PATINFO per le voci `:PATINFO`.
  - PS2BBL legge `SYSTEM.CNF` dall'area attributi della partizione (`PS2ICON3D`) e applica `BOOT2/BOOT/path`, `arg*`, `skip_argv0` e `HDDUNITPOWER`.
  - se `BOOT2/BOOT/path=PATINFO`, PS2BBL carica l'ELF integrato dall'area attributi della partizione e usa il passaggio interno `-la=E...`.
  - se `IOPRP=PATINFO` (o un percorso personalizzato), PS2BBL lo passa alla fase 2 tramite il passaggio interno `-la=I...`.
  - se `-patinfo` è presente, il primo argomento rimasto sostituisce la destinazione `BOOT2/BOOT/path` del CNF.
  Questo vale per le build HDD.  
  Esempio di PATINFO:  
    ```
    NAME_R1 = My App via PATINFO
    LK_R1_E1 = hdd0:+OSDMENU:PATINFO
    ARG_R1_E1 = pfs:/APPS/MYAPP.ELF
    ARG_R1_E1 = -patinfo               # Tells PS2BBL to use first arg as patinfo boot path.
    ```

Esempio per avviare NHDDL in modalità video 480p e cercare ISO su mmce e su un HDD exFAT senza bisogno di nhddl.yaml. Il vantaggio è non perdere tempo a caricare driver, cercare e caricare nhddl.yaml. È il modo più rapido per avviare NHDDL e mostrare l'elenco delle ISO.
```
NAME_R1 = NHDDL
LK_R1_E1 = mmce?:/NEUTRINO/nhddl.elf
ARG_R1_E1 = -video=480p
ARG_R1_E1 = -mode=mmce
ARG_R1_E1 = -mode=ata
```

<a id="argument-precedence-and-order"></a>

#### Precedenza e ordine degli argomenti
1. PS2BBL analizza e consuma solo gli argomenti di controllo del loader in fondo a `ARG_*`: `-appid`, `-titleid=`, `-dev9=`, `-patinfo`, `-disc_stop`, `-gsm=`.
2. L'analisi va dal basso verso l'alto e si ferma al primo argomento che non è di controllo (comportamento finale in stile OSDMenu).
4. Per i percorsi di avvio `:PATINFO`, PS2BBL analizza il `SYSTEM.CNF` dell'attributo della partizione e aggiunge le voci `arg*` del CNF dopo gli argomenti dell'app dell'utente.
5. Se `-patinfo` è impostato e il percorso di avvio contiene `:PATINFO`, il primo argomento rimasto dell'utente diventa il percorso dell'ELF di destinazione (sostituisce il percorso di avvio del CNF) e viene tolto dall'argv dell'app. Se non resta alcun argomento, l'avvio viene annullato (come in OSDMenu) e il `BOOT2/BOOT/path` del CNF non viene usato.
6. Gli argomenti rimasti mantengono l'ordine e vengono passati all'app avviata.


### eGSM (external Graphics Synthesize Mode)
Per i dischi PS2, eGSM viene letto automaticamente da `OSDGSM.CNF` (non serve nessun percorso nell'INI). Vedi [qui](https://github.com/pcm720/OSDMenu/blob/main/patcher/README.md#osdgsmcnf) il formato del file di configurazione.

- `-gsm=<v[:c]>` avvia l'ELF di destinazione tramite l'eGSM integrato (ignorato per i percorsi `rom?:`).
  - eGSM si applica alla destinazione avviata (ELF/disco), non a PS2BBL stesso.
  Formato di eGSM (in stile OSDMenu):
- `v` = modalità video:
- vuoto = non forzare (predefinito)
- `fp1` = forza la scansione progressiva (240p/288p)
- `fp2` = forza la scansione progressiva (480p/576p)
- `1080ix1` = forza 1080i, larghezza/altezza x1
- `1080ix2` = forza 1080i, larghezza/altezza x2
- `1080ix3` = forza 1080i, larghezza/altezza x3
- `c` = modalità di compatibilità:
- vuoto = nessuna (predefinito)
- `1` = inversione dei campi tipo 1
- `2` = inversione dei campi tipo 2
- `3` = inversione dei campi tipo 3

Esempi di ARG eGSM:
- `-gsm=fp2`
- `-gsm=fp2:1`
- `-gsm=1080ix2`

Esempio d'uso:
```
LK_TRIANGLE_E1 = mc0:/APP_WLE-ISR/WLE-ISR.ELF
ARG_TRIANGLE_E1 = -gsm=1080ix2
```

<a id="deprecatedremoved"></a>

## Deprecato/Rimosso
- ~~`RUNKELF`~~ PS2BBLE ora avvia elf/kelf internamente, senza che l'utente debba definire un'azione di avvio kelf.


<a id="known-bugsissues"></a>

## Bug/problemi noti

dimmelo tu ;)

<a id="credits--thanks"></a>

## Crediti e ringraziamenti

- Da saildot4k
  - @israpps per [PS2BBL](https://github.com/israpps/PlayStation2-Basic-BootLoader/)
  - @pcm720 per
    - il gameID di Retrogem, PS1 Video Negator, eGSM e il codice PS2LOGO da [OSDMenu](https://github.com/pcm720/OSDMenu)
    - le opzioni della modalità video da [NHDDL](https://github.com/pcm720/nhddl)
  - @sp193 per [PS1 Video Negator](https://github.com/ps2homebrew/PS1VModeNeg)
  - @nathanneurotic per i 10 percorsi di PS2BBLE, le idee e la persuasione
  - [@Berion](https://www.psx-place.com/members/berion.1431/) per loghi, sfondo e grafica dei tasti

- Da [El Isra](https://israpps.github.io/) (sviluppatore di PS2BBL): 
  - @SP193 per le librerie di inizializzazione dell'OSD, che sono la base di questo progetto
  - @asmblur, per avermi spinto a fare questo mostro sull'SDK più recente
  - @uyjulian e @fjtrujy perché mi aiutano sempre


<p align="center"><sub><a href="https://github.com/akilluminati47/RIPPS2">RIPPS2</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2/releases/latest/download/RIPPS2.elf">Scarica</a> &nbsp;&middot;&nbsp; <b>BIBLE</b> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2-themes">Temi</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPCSX2">RIPPCSX2</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2-fonts">Font</a> &nbsp;&middot;&nbsp; <a href="https://akilluminati47.github.io/RIPPS2/">Sito</a> &nbsp;&middot;&nbsp; <a href="https://www.psx-place.com/threads/ripps2-a-ps2-front-end-in-one-elf-launch-disc-storage-memory-files.51316/">psx-place</a> &nbsp;&middot;&nbsp; <a href="https://discord.gg/Z7m9u5kby">Discord</a></sub></p>

