<!-- i18n: the language bar, made by ps2-pillars tools/readme-i18n -->
<p align="center">
  <a href="README.md">English</a> |
  <a href="README.es.md">Español</a> |
  <a href="README.pt-BR.md">Português (Brasil)</a> |
  <a href="README.pt.md">Português</a> |
  <b>Français</b> |
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

<p align="center"><sub>Traduction du README anglais ; en cas de différence, l’anglais fait foi. <a href="README.md">English</a></sub></p>

<p align="center"><sub><a href="https://github.com/akilluminati47/RIPPS2">RIPPS2</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2/releases/latest/download/RIPPS2.elf">Télécharger</a> &nbsp;&middot;&nbsp; <b>BIBLE</b> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2-themes">Thèmes</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPCSX2">RIPPCSX2</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2-fonts">Polices</a> &nbsp;&middot;&nbsp; <a href="https://akilluminati47.github.io/RIPPS2/">Site web</a> &nbsp;&middot;&nbsp; <a href="https://www.psx-place.com/threads/ripps2-a-ps2-front-end-in-one-elf-launch-disc-storage-memory-files.51316/">psx-place</a> &nbsp;&middot;&nbsp; <a href="https://discord.gg/Z7m9u5kby">Discord</a></sub></p>

<h1 align="center">BIBLE</h1>
<p align="center">
  <a href="https://akilluminati47.github.io/BIBLE/">Site web</a> ·
  <a href="https://github.com/akilluminati47/RIPPS2">RIPPS2</a> ·
  <a href="https://github.com/akilluminati47/BIBLE/actions">Compilations</a> ·
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
  <sub>Maintenez L2 + R2 au démarrage pour la page des touches de lancement, TRIANGLE + CROSS pour la page du mode vidéo ; une touche réglée sur <code>$CREDITS</code> affiche les crédits.</sub>
</p>

BIBLE est le chargeur d'amorçage que RIPPS2 installe : un fork de PS2BBL Extended de saildot4k.

**Ce que ce fork change**

- L'écran de démarrage : le logo PS2 centré sur le ciel de RIPPS2, les boutons dessous et le texte éventuel dessus. `BIBLE_GLYPHS` 0 aucun, 1 les boutons d'action (par défaut), 2 les seize sur deux rangées de huit. `BIBLE_INFO` 1 affiche les infos de la console, l'horloge et le compte à rebours (désactivé par défaut). Le ciel suit votre Color Theme de RIPPS2 : sans `BIBLE_COLOR`, BIBLE lit le ciel que RIPPS2 enregistre avec ses réglages, dans le dossier que lance son entrée AUTO, ou dans le dossier `RIPPS2` d'une carte mémoire quand l'entrée AUTO est RIPPS2 sur un SD2PSX, une clé USB ou le disque dur (`BIBLE_COLOR` dans la configuration l'emporte). Le même rendu dans chaque mode vidéo.
- `BIBLE_BACKGROUND` : `AUTO` (par défaut : le ciel quand les réglages de RIPPS2 sont trouvés ou que `BIBLE_COLOR` est défini, sinon noir dans le mode propre de la console, un simple chargeur d'amorçage), `SKY` ou `BLANK` (noir). Le passage vers un programme est noir quelques secondes de toute façon, donc le noir ne fait qu'un avec lui.
- Le son de démarrage, préparé : le Boot Sound On (fast) de RIPPS2 peut garder `boot.adp` à côté de la configuration de BIBLE (`mc?:/SYS-CONF/boot.adp`). Il est lu avant le démarrage de tout lecteur. BIBLE peut aussi le transmettre à RIPPS2 en RAM, mais cela n'a été validé qu'en laboratoire : sur un vrai SD2PSX, RIPPS2 a lu lui-même la copie de la carte. **Sans son, c'est le démarrage le plus rapide.** Le contrat et la partie RIPPS2 : [docs/boot-sound-handoff.md](docs/boot-sound-handoff.md).
- RIPPS2 d'abord : le modèle de configuration (`release/SYS-CONF/PS2BBL.INI`) et les valeurs intégrées essaient `mc?:/RIPPS2/RIPPS2.ELF` et `mmce?:/APPS/RIPPS2.ELF` avant OSDMenu et FMCB, et le modèle liste les clés propres à BIBLE avec des notes. Les pages (mode vidéo, crédits, touches de lancement) apparaissent en fondu sur le logo assombri, boutons rangés, pour que les touches de lancement se lisent au calme.
- Modes vidéo : `VIDEO_MODE` accepte aussi `576P`, `720P` et `1080I`, le reste de ceux de RIPPS2. `AUTO` (par défaut)
  démarre dans le Video Mode de RIPPS2 quand ses réglages sont trouvés à côté de l'entrée AUTO, sinon dans celui de la console.
- `BIBLE_WIDESCREEN` : `AUTO` (par défaut : le Widescreen de RIPPS2, sinon le réglage d'écran 16:9 de la PS2), `ON` ou
  `OFF`. En 480i, 576i, 480p et 576p, l'écran de démarrage est dessiné pour un téléviseur qui étire l'image en 16:9, sans
  l'écraser. 720p et 1080i sont déjà en 16:9.
- Le passage à RIPPS2 : au lancement, le logo et les boutons s'effacent et le ciel reste jusqu'à ce que la console charge le programme suivant, ce qui met l'écran au noir (environ 7 s en laboratoire avec RIPPS2 sur une carte mémoire). RIPPS2 apparaît ensuite dans le même mode vidéo et les mêmes couleurs. Maintenez TRIANGLE + CROSS au démarrage pour la page du mode vidéo, qui s'ouvre toujours dans
  le mode entrelacé de la console (le chemin du retour depuis 720p ou 1080i sur un câble composite).
- Nouveau : la page des touches de lancement. Maintenez L2 + R2 à l'allumage et BIBLE fait une pause avant de lancer quoi que ce soit, en montrant les chemins de lancement actuels de chaque touche, quels que soient vos réglages d'écran de démarrage (pratique avec `LOGO_DISPLAY = 0`, où rien d'autre ne s'affiche).
- Les combinaisons maintenues dès la mise sous tension ouvrent désormais leurs pages (TRIANGLE + CROSS était manqué quand les manettes étaient encore
  en train de démarrer).
- `KEY_READ_WAIT_TIME = 0` est autorisé (le minimum d'upstream est de 500 ms).
- Compilations PS2 pour carte mémoire / USB, MMCE, MX4SIO et HDD. L'étape 2 d'eGSM est laissée de côté.

**Comment RIPPS2 l'utilise**

RIPPS2 porte BIBLE dans RIPPS2.elf, chaque version signée par akilluminati47, et l'installe ou le met à jour depuis Paramètres > Général > Boot Loader > Manage, qui règle aussi les clés de BIBLE : Background, Splash, Button Glyphs, Info Line, Power-on Wait, Video Mode et Widescreen. Les versions signées et une carte BOOT SD2PSX prête sont sur [la page des versions](https://github.com/akilluminati47/BIBLE/releases/latest). BIBLE fonctionne aussi comme ELF lancé par un autre chargeur (FMCB, OSDMenu, le chargeur d'un SD2PSX).

<p align="center"><img src="assets/readme/ripps2-icon.png" alt="RIPPS2" width="48" height="48"><br><sub>BIBLE fait partie de <a href="https://github.com/akilluminati47/RIPPS2">RIPPS2</a>.</sub></p>

---

<p align="center"><sub>Tout ce qui suit est le README d'origine de PS2BBL Extended, traduit sans autre changement.</sub></p>

---


<br />
<p align="center">
  <a href="https://israpps.github.io/PlayStation2-Basic-BootLoader/">
    <img src="https://github.com/saildot4k/PlayStation2-Basic-BootLoader-Extended/blob/main/assets/ps2bbl_example.png" alt="Logo" width="50%" height="auto">
  </a>

  <p align="center">
    Un chargeur d'amorçage souple pour PlayStation 2™ et PSX-DESR
    <br />
  </p>
</p>  


Ceci est un fork de PS2BBL par [El Isra](https://github.com/israpps/PlayStation2-Basic-BootLoader/)


## Documentation

Elle est hébergée sur [github pages](https://israpps.github.io/PlayStation2-Basic-BootLoader/), avec les ajouts ci-dessous :

<a id="config-and-arguments"></a>

## Configuration et arguments

Modifiez le fichier de configuration selon vos besoins. [R3Configurator](https://github.com/saildot4k/R3CONFIGURATOR) est recommandé pour le modifier. Les chemins sont déjà réglés pour correspondre aux téléchargements du [PS2 Homebrew Store](https://ps2homebrewstore.com). Vous ne devriez donc avoir qu'à modifier votre choix Auto et, de préférence, régler les arguments de NHDDL selon le périphérique d'où vous chargez les ISO.

<a id="config-path-search-order"></a>

### Ordre de recherche de la configuration

La recherche de la configuration tient désormais compte de la famille d'amorçage, pour ne pas charger de pilotes inutiles au démarrage :

1. `CONFIG.INI` (CWD : répertoire de travail courant)
2. En cas de chargement depuis un périphérique :
   - Amorçage MMCE : `mmce?:/PS2BBL/CONFIG.INI`
   - Amorçage MX4SIO : `mx4sio:/PS2BBL/CONFIG.INI`
   - Amorçage APA HDD : `hdd0:__sysconf:pfs:/PS2BBL/CONFIG.INI`
   - Amorçage BDM : `usb:/PS2BBL/CONFIG.INI` / `mass:/PS2BBL/CONFIG.INI` / `ata:/PS2BBL/CONFIG.INI`
3. Repli sur la carte mémoire :
   - Sur PS2 : `mc?:/SYS-CONF/PS2BBL.INI`
   - Sur PSX-DESR : `mc?:/SYS-CONF/PSXBBL.INI`
4. Dernier repli sur PSX
   - `xfrom:/PS2BBL/CONFIG.INI`
5. Si compilé avec `DISC_STOP_AT_BOOT=1
   - `cdrom0:/PS2BBL/CONFIG.INI`
   - Repli sur la carte mémoire comme au point 3 ci-dessus.

<a id="device-path-prefixes"></a>

### Préfixes de chemin de périphérique
PS2BBL accepte ces préfixes de chemin de lancement/configuration :
- `mc0:/`, `mc1:/`, `mc?:/`
- `usb:/` (préféré) et `mass:/` (ancien)

<a id="build-specific"></a>

#### Selon la compilation :  
- `mmce0:/`, `mmce1:/`, `mmce?:/` __compilations MMCE__
- `mx4sio:/` (préféré) et `massX:/` (ancien)  __compilations MX4SIO__
- `hdd0:partition:pfs:/<path to elf>` __compilations HDD__
- Chemins `xfrom:/` __compilations PSX DESR__
- `ata:/` périphérique BDM de HDD exFAT
- `ilink:/` (racines de stockage de masse BDM) __pas encore implémenté__
- `DISC_STOP_AT_BOOT=1` profil de compilation pour toujours arrêter le disque optique après le chargement de la configuration

### LOGO_DISPLAY
Utilisez `LOGO_DISPLAY = 3` pour afficher les noms des touches. Les noms sont définis par `NAME_<BUTTON>`.
  - `0` Ni logo ni infos de la console
  - `1` Infos de la console
  - `2` Logo PS2BBLE/PSXBBLE et infos de la console
  - `3` Graphique des touches avec `NAME_BUTTON = <TITLE>` tiré du fichier de configuration
    - Exemple :
      ```
      NAME_SQUARE = POPSLOADER
      ```

<a id="custom-splash-logo-from-cwd"></a>

#### Logo de démarrage personnalisé depuis le CWD
Si un fichier de logo personnalisé (LOGO.BIN) se trouve dans le CWD (répertoire de travail courant), il remplace le logo PS2BBLE/PSXBBLE intégré.

Convertissez un PNG dans le fichier brut attendu :
  - Le PNG doit être en RGBA 8 bits indexé, 255 couleurs par canal, en résolution 256x64.

  - Paquet de la version (le script est à la racine de la version) :
  ```bash
  python png_to_logo_rbga.py my_logo.png
  ```

  - Placez le `LOGO.BIN` créé à côté de PS2BBL Extended. Ce doit être `mc?:/BOOT/` si vous utilisez les téléchargements du [PS2 Homebrew Store](https://ps2store.com)

<a id="retrogem-visual-game-id"></a>

### ID visuel de jeu Retrogem
- `APP_GAMEID = 1` active l'ID visuel de jeu pour les apps/homebrew, jusqu'à 11 caractères tirés du nom de fichier ou du disque PS1/2
- `CDROM_DISABLE_GAMEID = 1` désactive l'ID visuel de jeu pour les disques lancés via `cdrom`.

<a id="disc-spin-control"></a>

### Contrôle de la rotation du disque
- Clé/valeur globale : `DISC_STOP = 0/1`
- `DISC_STOP = 1` arrête le disque optique après le chargement de la configuration quand un fichier de configuration a été trouvé.
- `DISC_STOP = 0` (ou omis) garde le comportement par défaut.
- `-disc_stop` peut être ajouté à chaque entrée de lancement pour arrêter le disque une fois l'ELF cible trouvé.

<a id="video-mode"></a>

### Mode vidéo
- `VIDEO_MODE = AUTO, NTSC, PAL, 480P` Utilise le mode par défaut de la PS2 ou force l'un des 3 autres modes.

<a id="emergency-video-mode-selector"></a>

#### Sélecteur de mode vidéo d'urgence
- S'ouvre avec `TRIANGLE + CROSS` pendant le démarrage
- Le sélecteur force `LOGO_DISPLAY = 3` tant qu'il est actif, pour que vous voyiez le contexte du logo et des touches.
- Commandes :
  - `LEFT/RIGHT` font défiler les modes : `AUTO`, `NTSC`, `PAL`, `480P`
  - `SELECT` enregistre le mode choisi dans le fichier de configuration actif
  - `START` quitte le sélecteur et passe à l'affichage des touches

<a id="cdrom-launch-args"></a>

### Arguments de lancement CDROM
Pour `LK_*_E* = cdrom`, les arguments acceptés sont :
- `-nologo`
- `-nogameid`
- `-ps1fast`
- `-ps1smooth`
- `-ps1vneg`
- `-gsm=<v[:c]>`

<a id="ps2logo-arguments-ps2-discs-only"></a>

#### Arguments PS2LOGO (disques PS2 seulement)
- Utilisez `cdrom` comme chemin de l'entrée de lancement.
- Ajoutez `-nologo` aux arguments de l'entrée pour démarrer directement les disques PS2 (sans `rom0:PS2LOGO`).
- Sans `-nologo`, PS2BBL lance le disque via PS2LOGO et le corrige pour toujours utiliser la région du disque et contourner la vérification du checksum du logo.
- DECKARD IE 75K et ultérieurs : XPARAM.IRX est appliqué automatiquement quand il le faut pour les lancements sans logo.

<a id="ps1-disc-arguments-per-launch"></a>

#### Arguments des disques PS1 (par lancement)
Ils s'appliquent à chaque entrée de lancement `cdrom`, pas globalement.
- `-ps1fast` active la vitesse rapide du disque PS1.
- `-ps1smooth` active le lissage des textures.
- `-ps1vneg` lance PS1DRV via PS1VModeNegator. Utile sur les installations où le mode de la console et celui du disque diffèrent (par exemple certains cas MechaPwn/modchip).

<a id="app-arguments"></a>

### Arguments des apps
Utilisez des lignes `ARG_<BUTTON>_E? =` pour passer des arguments à un ELF (voir les exemples INI).
- Mettez d'abord les arguments de l'elf lancé, puis ajoutez ensuite les arguments internes de PS2BBL voulus (voir ci-dessous). [NHDDL](https://github.com/pcm720/nhddl) est un excellent candidat aux arguments, car ils accélèrent son démarrage.
- `-titleid=SLUS_123.45` remplace l'ID de titre de l'app (jusqu'à 11 caractères).
- `-appid` force l'ID visuel de jeu de l'app même si `APP_GAMEID = 0`.
- `-disc_stop` arrête le disque une fois l'ELF cible chargé (utile par entrée sans compilations `DISC_STOP_AT_BOOT`).
- `-gsm=<v[:c]>` lance l'ELF cible via l'eGSM intégré (ignoré pour les chemins `rom?:`). S'il est utilisé, ce doit être le dernier argument.
- `-disc_stop` est ignoré pour les entrées de lancement `cdrom`.
- `-dev9=<mode>` fixe la politique DEV9/HDD avant de lancer l'ELF cible. Modes acceptés :
  - `NICHDD` garde DEV9 (adaptateur réseau) et le HDD tous deux allumés.
  - `NIC` garde DEV9/le réseau allumés, démonte `pfs0:` et met `hdd0:`/`hdd1:` en veille immédiate.
  - s'il est omis, PS2BBL n'impose aucune politique DEV9.
  - note : sur les compilations sans HDD, cette option n'a aucun effet.
- `-patinfo` active la gestion de PATINFO pour les entrées `:PATINFO`.
  - PS2BBL lit `SYSTEM.CNF` dans la zone d'attributs de la partition (`PS2ICON3D`) et applique `BOOT2/BOOT/path`, `arg*`, `skip_argv0` et `HDDUNITPOWER`.
  - si `BOOT2/BOOT/path=PATINFO`, PS2BBL charge l'ELF intégré depuis la zone d'attributs de la partition et utilise le passage interne `-la=E...`.
  - si `IOPRP=PATINFO` (ou un chemin personnalisé), PS2BBL le transmet à l'étape 2 via le passage interne `-la=I...`.
  - si `-patinfo` est présent, le premier argument restant remplace la cible `BOOT2/BOOT/path` du CNF.
  Ceci concerne les compilations HDD.  
  Exemple de PATINFO :  
    ```
    NAME_R1 = My App via PATINFO
    LK_R1_E1 = hdd0:+OSDMENU:PATINFO
    ARG_R1_E1 = pfs:/APPS/MYAPP.ELF
    ARG_R1_E1 = -patinfo               # Tells PS2BBL to use first arg as patinfo boot path.
    ```

Exemple pour lancer NHDDL en mode vidéo 480p et chercher les ISO sur mmce et sur un HDD exFAT sans avoir besoin de nhddl.yaml. L'avantage : aucun temps perdu à charger des pilotes, ni à trouver et charger nhddl.yaml. C'est le moyen le plus rapide de démarrer NHDDL et d'afficher la liste des ISO.
```
NAME_R1 = NHDDL
LK_R1_E1 = mmce?:/NEUTRINO/nhddl.elf
ARG_R1_E1 = -video=480p
ARG_R1_E1 = -mode=mmce
ARG_R1_E1 = -mode=ata
```

<a id="argument-precedence-and-order"></a>

#### Priorité et ordre des arguments
1. PS2BBL analyse et consomme seulement les arguments de contrôle du chargeur placés à la fin de `ARG_*` : `-appid`, `-titleid=`, `-dev9=`, `-patinfo`, `-disc_stop`, `-gsm=`.
2. L'analyse va de bas en haut et s'arrête au premier argument qui n'est pas de contrôle (comportement de fin à la manière d'OSDMenu).
4. Pour les chemins de lancement `:PATINFO`, PS2BBL analyse le `SYSTEM.CNF` de l'attribut de partition et ajoute les entrées `arg*` du CNF après les arguments de l'app de l'utilisateur.
5. Si `-patinfo` est défini et que le chemin de lancement contient `:PATINFO`, le premier argument restant de l'utilisateur devient le chemin de l'ELF cible (il remplace le chemin d'amorçage du CNF) et est retiré de l'argv de l'app. S'il ne reste aucun argument, le lancement est annulé (comme dans OSDMenu) et le `BOOT2/BOOT/path` du CNF n'est pas utilisé.
6. Les arguments restants gardent leur ordre et sont transmis à l'app lancée.


### eGSM (external Graphics Synthesize Mode)
Pour les disques PS2, eGSM est lu automatiquement depuis `OSDGSM.CNF` (aucun chemin à régler dans l'INI). Voir [ici](https://github.com/pcm720/OSDMenu/blob/main/patcher/README.md#osdgsmcnf) pour le format du fichier de configuration.

- `-gsm=<v[:c]>` lance l'ELF cible via l'eGSM intégré (ignoré pour les chemins `rom?:`).
  - eGSM s'applique à la cible lancée (ELF/disque), pas à PS2BBL lui-même.
  Format d'eGSM (à la manière d'OSDMenu) :
- `v` = mode vidéo :
- vide = ne rien forcer (par défaut)
- `fp1` = forcer le balayage progressif (240p/288p)
- `fp2` = forcer le balayage progressif (480p/576p)
- `1080ix1` = forcer le 1080i, largeur/hauteur x1
- `1080ix2` = forcer le 1080i, largeur/hauteur x2
- `1080ix3` = forcer le 1080i, largeur/hauteur x3
- `c` = mode de compatibilité :
- vide = aucun (par défaut)
- `1` = inversion de trames type 1
- `2` = inversion de trames type 2
- `3` = inversion de trames type 3

Exemples d'ARG eGSM :
- `-gsm=fp2`
- `-gsm=fp2:1`
- `-gsm=1080ix2`

Exemple d'utilisation :
```
LK_TRIANGLE_E1 = mc0:/APP_WLE-ISR/WLE-ISR.ELF
ARG_TRIANGLE_E1 = -gsm=1080ix2
```

<a id="deprecatedremoved"></a>

## Obsolète/Retiré
- ~~`RUNKELF`~~ PS2BBLE lance désormais elf/kelf en interne, sans que l'utilisateur ait à définir une action de lancement kelf.


<a id="known-bugsissues"></a>

## Bugs/problèmes connus

à vous de me le dire ;)

<a id="credits--thanks"></a>

## Crédits et remerciements

- De saildot4k
  - @israpps pour [PS2BBL](https://github.com/israpps/PlayStation2-Basic-BootLoader/)
  - @pcm720 pour
    - le gameID Retrogem, PS1 Video Negator, eGSM et le code PS2LOGO de [OSDMenu](https://github.com/pcm720/OSDMenu)
    - les options de mode vidéo de [NHDDL](https://github.com/pcm720/nhddl)
  - @sp193 pour [PS1 Video Negator](https://github.com/ps2homebrew/PS1VModeNeg)
  - @nathanneurotic pour les 10 chemins de PS2BBLE, les idées et la persuasion
  - [@Berion](https://www.psx-place.com/members/berion.1431/) pour les logos, le fond et les graphismes des touches

- De [El Isra](https://israpps.github.io/) (développeur de PS2BBL) : 
  - @SP193 pour les bibliothèques d'initialisation de l'OSD, qui servent de base à ce projet
  - @asmblur, pour m'avoir encouragé à faire ce monstre sur le SDK le plus récent
  - @uyjulian et @fjtrujy pour m'avoir toujours aidé


<p align="center"><sub><a href="https://github.com/akilluminati47/RIPPS2">RIPPS2</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2/releases/latest/download/RIPPS2.elf">Télécharger</a> &nbsp;&middot;&nbsp; <b>BIBLE</b> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2-themes">Thèmes</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPCSX2">RIPPCSX2</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2-fonts">Polices</a> &nbsp;&middot;&nbsp; <a href="https://akilluminati47.github.io/RIPPS2/">Site web</a> &nbsp;&middot;&nbsp; <a href="https://www.psx-place.com/threads/ripps2-a-ps2-front-end-in-one-elf-launch-disc-storage-memory-files.51316/">psx-place</a> &nbsp;&middot;&nbsp; <a href="https://discord.gg/Z7m9u5kby">Discord</a></sub></p>

