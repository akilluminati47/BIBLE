<!-- i18n: the language bar, made by ps2-pillars tools/readme-i18n -->
<p align="center">
  <a href="README.md">English</a> |
  <a href="README.es.md">Español</a> |
  <a href="README.pt-BR.md">Português (Brasil)</a> |
  <b>Português</b> |
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

<p align="center"><sub>Tradução do README em inglês; se diferirem, vale o inglês. <a href="README.md">English</a></sub></p>

<p align="center"><sub><a href="https://github.com/akilluminati47/RIPPS2">RIPPS2</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2/releases/latest/download/RIPPS2.elf">Transferir</a> &nbsp;&middot;&nbsp; <b>BIBLE</b> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2-themes">Temas</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPCSX2">RIPPCSX2</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2-fonts">Tipos de letra</a> &nbsp;&middot;&nbsp; <a href="https://akilluminati47.github.io/RIPPS2/">Site</a> &nbsp;&middot;&nbsp; <a href="https://www.psx-place.com/threads/ripps2-a-ps2-front-end-in-one-elf-launch-disc-storage-memory-files.51316/">psx-place</a> &nbsp;&middot;&nbsp; <a href="https://discord.gg/Z7m9u5kby">Discord</a></sub></p>

<h1 align="center">BIBLE</h1>
<p align="center">
  <a href="https://github.com/akilluminati47/RIPPS2">RIPPS2</a> ·
  <a href="https://github.com/akilluminati47/BIBLE/actions">Compilações</a> ·
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
  <sub>Mantenha L2 + R2 premidos no arranque para a página das teclas de arranque, TRIANGLE + CROSS para a página do modo de vídeo; uma tecla definida como <code>$CREDITS</code> mostra os créditos.</sub>
</p>

O BIBLE é o carregador de arranque que o RIPPS2 instala: um fork do PS2BBL Extended de saildot4k.

**O que este fork muda**

- O ecrã inicial: o logótipo da PS2 centrado no céu do RIPPS2, com os botões por baixo e qualquer texto por cima.
  `BIBLE_GLYPHS` 0 nenhum, 1 os botões frontais (predefinição), 2 os dezasseis em duas filas de oito.
  `BIBLE_INFO` 1 mostra a informação da consola, o relógio e a contagem decrescente (desligado por predefinição).
  O céu acompanha o seu Color Theme do RIPPS2: sem `BIBLE_COLOR`, o BIBLE lê o céu que o RIPPS2 guarda com as suas
  definições, da pasta do RIPPS2 que a entrada AUTO inicia (`BIBLE_COLOR` na configuração prevalece).
  O mesmo aspeto em todos os modos de vídeo. As páginas (modo de vídeo, créditos, teclas de arranque) surgem sobre o logótipo escurecido
  com os botões arrumados, para que as teclas de arranque se leiam com calma.
- Modos de vídeo: `VIDEO_MODE` também aceita `576P`, `720P` e `1080I`, os restantes do RIPPS2. `AUTO` (a predefinição)
  arranca no Video Mode do RIPPS2 quando as definições dele estão ao lado da entrada AUTO, senão no da própria consola.
- `BIBLE_WIDESCREEN`: `AUTO` (a predefinição: o Widescreen do RIPPS2, senão a definição de ecrã 16:9 da PS2), `ON` ou
  `OFF`. Em 480i, 576i, 480p e 576p o ecrã inicial é desenhado para uma TV que estica a imagem para 16:9, sem
  a achatar. 720p e 1080i já são 16:9.
- Sem salto ao entrar no RIPPS2: ao arrancar algo, o logótipo e os botões desvanecem e o céu fica no ecrã, no modo do RIPPS2;
  o RIPPS2 começa nesse mesmo céu. Mantenha TRIANGLE + CROSS no arranque para a página do modo de vídeo, que abre sempre
  no modo entrelaçado da própria consola (o caminho de volta de 720p ou 1080i num cabo composto).
- Novo: a página das teclas de arranque. Mantenha L2 + R2 no arranque para ler o caminho de cada tecla, sejam quais forem as definições do ecrã inicial.
- As combinações mantidas desde que se liga a consola abrem agora as suas páginas (TRIANGLE + CROSS perdia-se enquanto os comandos ainda
  arrancavam).
- `KEY_READ_WAIT_TIME = 0` é permitido (o mínimo do upstream é 500 ms).
- Compilações para PS2 para cartão de memória / USB, MMCE, MX4SIO e HDD. A fase 2 do eGSM fica de fora.

**Como o RIPPS2 o usa**

O RIPPS2 leva o BIBLE como ficheiros de arranque assinados desde a v1.3.4-beta e instala-o a partir de Settings > General > Boot Loader > Manage. O BIBLE também corre como um ELF iniciado por outro carregador (FMCB, OSDMenu, o carregador de um SD2PSX). As builds assinadas estão na [página da versão](https://github.com/akilluminati47/BIBLE/releases/tag/signed-f31c8d5); nenhuma consola as tinha associado quando saíram, por isso experimenta primeiro num cartão de memória de reserva.

<p align="center"><img src="assets/readme/ripps2-icon.png" alt="RIPPS2" width="48" height="48"><br><sub>O BIBLE faz parte do <a href="https://github.com/akilluminati47/RIPPS2">RIPPS2</a>.</sub></p>

---

<p align="center"><sub>Tudo o que se segue é o README original do PS2BBL Extended, traduzido sem outras alterações.</sub></p>

---


<br />
<p align="center">
  <a href="https://israpps.github.io/PlayStation2-Basic-BootLoader/">
    <img src="https://github.com/saildot4k/PlayStation2-Basic-BootLoader-Extended/blob/main/assets/ps2bbl_example.png" alt="Logo" width="50%" height="auto">
  </a>

  <p align="center">
    Um carregador de arranque flexível para PlayStation 2™ e PSX-DESR
    <br />
  </p>
</p>  


Este é um fork do PS2BBL de [El Isra](https://github.com/israpps/PlayStation2-Basic-BootLoader/)


<a id="documentation"></a>

## Documentação

Está alojada no [github pages](https://israpps.github.io/PlayStation2-Basic-BootLoader/), mas com os acréscimos abaixo:

<a id="config-and-arguments"></a>

## Configuração e argumentos

Edite o ficheiro de configuração conforme precisar. Recomenda-se o [R3Configurator](https://github.com/saildot4k/R3CONFIGURATOR) para editar o ficheiro. Os caminhos já vêm preparados para coincidir com as transferências da [PS2 Homebrew Store](https://ps2homebrewstore.com). Assim só deverá precisar de editar a sua escolha Auto e, de preferência, definir os argumentos do NHDDL conforme o dispositivo de onde carrega as ISO.

<a id="config-path-search-order"></a>

### Ordem de procura da configuração

A procura da configuração tem agora em conta a família de arranque, para não carregar controladores desnecessários no arranque:

1. `CONFIG.INI` (CWD: diretório de trabalho atual)
2. Quando carregado a partir de um dispositivo:
   - Arranque por MMCE: `mmce?:/PS2BBL/CONFIG.INI`
   - Arranque por MX4SIO: `mx4sio:/PS2BBL/CONFIG.INI`
   - Arranque por APA HDD: `hdd0:__sysconf:pfs:/PS2BBL/CONFIG.INI`
   - Arranque por BDM: `usb:/PS2BBL/CONFIG.INI` / `mass:/PS2BBL/CONFIG.INI` / `ata:/PS2BBL/CONFIG.INI`
3. Alternativa no cartão de memória:
   - Na PS2: `mc?:/SYS-CONF/PS2BBL.INI`
   - Na PSX-DESR: `mc?:/SYS-CONF/PSXBBL.INI`
4. Última alternativa na PSX
   - `xfrom:/PS2BBL/CONFIG.INI`
5. Quando compilado com `DISC_STOP_AT_BOOT=1
   - `cdrom0:/PS2BBL/CONFIG.INI`
   - Alternativa no cartão de memória como no ponto 3 acima.

<a id="device-path-prefixes"></a>

### Prefixos de caminho de dispositivo
O PS2BBL aceita estes prefixos de caminho de arranque/configuração:
- `mc0:/`, `mc1:/`, `mc?:/`
- `usb:/` (preferido) e `mass:/` (antigo)

<a id="build-specific"></a>

#### Conforme a compilação:  
- `mmce0:/`, `mmce1:/`, `mmce?:/` __compilações MMCE__
- `mx4sio:/` (preferido) e `massX:/` (antigo)  __compilações MX4SIO__
- `hdd0:partition:pfs:/<path to elf>` __compilações HDD__
- Caminhos `xfrom:/` __compilações PSX DESR__
- `ata:/` dispositivo BDM de HDD exFAT
- `ilink:/` (raízes de armazenamento em massa BDM) __ainda não implementado__
- `DISC_STOP_AT_BOOT=1` perfil de compilação para parar sempre o disco ótico depois de carregar a configuração

### LOGO_DISPLAY
Use `LOGO_DISPLAY = 3` para mostrar os nomes das teclas. Os nomes são definidos por `NAME_<BUTTON>`.
  - `0` Sem logótipo nem informação da consola
  - `1` Informação da consola
  - `2` Logótipo PS2BBLE/PSXBBLE e informação da consola
  - `3` Gráfico das teclas com `NAME_BUTTON = <TITLE>` vindo do ficheiro de configuração
    - Exemplo:
      ```
      NAME_SQUARE = POPSLOADER
      ```

<a id="custom-splash-logo-from-cwd"></a>

#### Logótipo inicial próprio a partir do CWD
Se for encontrado um ficheiro de logótipo próprio (LOGO.BIN) no CWD (diretório de trabalho atual), substitui o logótipo PS2BBLE/PSXBBLE incorporado.

Converta um PNG no ficheiro em bruto esperado:
  - O PNG deve ser RGBA de 8 bits indexado, 255 cores por canal e resolução 256x64.

  - Pacote da versão (o script está na raiz da versão):
  ```bash
  python png_to_logo_rbga.py my_logo.png
  ```

  - Coloque o `LOGO.BIN` criado ao lado do PS2BBL Extended. Deve ser `mc?:/BOOT/` se usar as transferências da [PS2 Homebrew Store](https://ps2store.com)

<a id="retrogem-visual-game-id"></a>

### ID visual de jogo do Retrogem
- `APP_GAMEID = 1` ativa o ID visual de jogo para apps/homebrew, com até 11 caracteres tirados do nome do ficheiro ou do disco de PS1/2
- `CDROM_DISABLE_GAMEID = 1` desativa o ID visual de jogo para discos arrancados via `cdrom`.

<a id="disc-spin-control"></a>

### Controlo da rotação do disco
- Chave/valor global: `DISC_STOP = 0/1`
- `DISC_STOP = 1` para o disco ótico depois de carregar a configuração, quando foi encontrado um ficheiro de configuração.
- `DISC_STOP = 0` (ou omitido) mantém o comportamento predefinido.
- `-disc_stop` pode ser acrescentado a cada entrada para parar o disco depois de encontrado o ELF de destino.

<a id="video-mode"></a>

### Modo de vídeo
- `VIDEO_MODE = AUTO, NTSC, PAL, 480P` Usa a predefinição da PS2 ou força um dos outros 3 modos.

<a id="emergency-video-mode-selector"></a>

#### Seletor de modo de vídeo de emergência
- Entre com `TRIANGLE + CROSS` durante o arranque
- O seletor força `LOGO_DISPLAY = 3` enquanto está ativo, para que veja o contexto do logótipo e das teclas.
- Controlos:
  - `LEFT/RIGHT` percorrem os modos: `AUTO`, `NTSC`, `PAL`, `480P`
  - `SELECT` guarda o modo selecionado no ficheiro de configuração ativo
  - `START` sai do seletor e segue para o ecrã das teclas

<a id="cdrom-launch-args"></a>

### Argumentos de arranque de CDROM
Para `LK_*_E* = cdrom`, os argumentos aceites são:
- `-nologo`
- `-nogameid`
- `-ps1fast`
- `-ps1smooth`
- `-ps1vneg`
- `-gsm=<v[:c]>`

<a id="ps2logo-arguments-ps2-discs-only"></a>

#### Argumentos do PS2LOGO (só discos de PS2)
- Use `cdrom` como caminho da entrada.
- Acrescente `-nologo` aos argumentos da entrada para arrancar discos de PS2 diretamente (salta o `rom0:PS2LOGO`).
- Sem `-nologo`, o PS2BBL arranca o disco através do PS2LOGO e corrige-o para usar sempre a região do disco e saltar a verificação do checksum do logótipo.
- DECKARD IE 75K e posteriores: o XPARAM.IRX é aplicado automaticamente quando é preciso para arranques sem logótipo.

<a id="ps1-disc-arguments-per-launch"></a>

#### Argumentos de discos de PS1 (por arranque)
Aplicam-se a cada entrada `cdrom`, não de forma global.
- `-ps1fast` ativa a velocidade rápida do disco de PS1.
- `-ps1smooth` ativa a suavização de texturas.
- `-ps1vneg` corre o PS1DRV através do PS1VModeNegator. Útil em configurações em que o modo da consola e o do disco diferem (por exemplo alguns casos de MechaPwn/modchip).

<a id="app-arguments"></a>

### Argumentos de apps
Use linhas `ARG_<BUTTON>_E? =` para passar argumentos a um ELF (veja os exemplos de INI).
- Ponha primeiro os argumentos do elf arrancado e acrescente depois os argumentos internos do PS2BBL que quiser (ver abaixo). O [NHDDL](https://github.com/pcm720/nhddl) é um ótimo candidato para usar argumentos, pois acelera o arranque do NHDDL.
- `-titleid=SLUS_123.45` substitui o ID de título da app (até 11 caracteres).
- `-appid` força o ID visual de jogo da app mesmo com `APP_GAMEID = 0`.
- `-disc_stop` para o disco depois de carregado o ELF de destino (útil por entrada sem compilações `DISC_STOP_AT_BOOT`).
- `-gsm=<v[:c]>` corre o ELF de destino através do eGSM incorporado (ignorado em caminhos `rom?:`). Se usado, tem de ser o último argumento.
- `-disc_stop` é ignorado em entradas `cdrom`.
- `-dev9=<mode>` define a política de DEV9/HDD antes de arrancar o ELF de destino. Modos aceites:
  - `NICHDD` mantém ligados tanto o DEV9 (adaptador de rede) como o HDD.
  - `NIC` mantém o DEV9/rede ligados, desmonta `pfs0:` e põe `hdd0:`/`hdd1:` em repouso imediato.
  - se omitido, o PS2BBL não força nenhuma política de DEV9.
  - nota: em compilações sem HDD esta opção não tem efeito.
- `-patinfo` ativa o tratamento de PATINFO para entradas `:PATINFO`.
  - O PS2BBL lê o `SYSTEM.CNF` da área de atributos da partição (`PS2ICON3D`) e aplica `BOOT2/BOOT/path`, `arg*`, `skip_argv0` e `HDDUNITPOWER`.
  - se `BOOT2/BOOT/path=PATINFO`, o PS2BBL carrega o ELF incorporado da área de atributos da partição e usa a passagem interna `-la=E...`.
  - se `IOPRP=PATINFO` (ou um caminho próprio), o PS2BBL passa-o à fase 2 pela passagem interna `-la=I...`.
  - se `-patinfo` estiver presente, o primeiro argumento restante substitui o destino `BOOT2/BOOT/path` do CNF.
  Isto é para compilações HDD.  
  Exemplo de PATINFO:  
    ```
    NAME_R1 = My App via PATINFO
    LK_R1_E1 = hdd0:+OSDMENU:PATINFO
    ARG_R1_E1 = pfs:/APPS/MYAPP.ELF
    ARG_R1_E1 = -patinfo               # Tells PS2BBL to use first arg as patinfo boot path.
    ```

Exemplo para arrancar o NHDDL em modo de vídeo 480p e procurar ISO no mmce e num HDD exFAT sem precisar do nhddl.yaml. A vantagem é não perder tempo a carregar controladores, a procurar e a carregar o nhddl.yaml. É a forma mais rápida de arrancar o NHDDL e mostrar a lista de ISO.
```
NAME_R1 = NHDDL
LK_R1_E1 = mmce?:/NEUTRINO/nhddl.elf
ARG_R1_E1 = -video=480p
ARG_R1_E1 = -mode=mmce
ARG_R1_E1 = -mode=ata
```

<a id="argument-precedence-and-order"></a>

#### Precedência e ordem dos argumentos
1. O PS2BBL analisa e consome apenas os argumentos finais de controlo do carregador de `ARG_*`: `-appid`, `-titleid=`, `-dev9=`, `-patinfo`, `-disc_stop`, `-gsm=`.
2. A análise vai de baixo para cima e para no primeiro argumento que não é de controlo (comportamento final ao estilo do OSDMenu).
4. Para caminhos `:PATINFO`, o PS2BBL analisa o `SYSTEM.CNF` do atributo da partição e acrescenta as entradas `arg*` do CNF depois dos argumentos da app do utilizador.
5. Se `-patinfo` estiver definido e o caminho contiver `:PATINFO`, o primeiro argumento restante do utilizador passa a ser o caminho do ELF de destino (substitui o caminho de arranque do CNF) e é retirado do argv da app. Se não sobrar nenhum argumento, o arranque é cancelado (como no OSDMenu) e o `BOOT2/BOOT/path` do CNF não é usado.
6. Os argumentos restantes mantêm a ordem e são passados à app arrancada.


### eGSM (external Graphics Synthesize Mode)
Para discos de PS2, o eGSM é lido automaticamente de `OSDGSM.CNF` (não é preciso caminho no INI). Veja [aqui](https://github.com/pcm720/OSDMenu/blob/main/patcher/README.md#osdgsmcnf) o formato do ficheiro de configuração.

- `-gsm=<v[:c]>` corre o ELF de destino através do eGSM incorporado (ignorado em caminhos `rom?:`).
  - O eGSM é aplicado ao destino arrancado (ELF/disco), não ao próprio PS2BBL.
  Formato do eGSM (ao estilo do OSDMenu):
- `v` = modo de vídeo:
- vazio = não forçar (predefinição)
- `fp1` = forçar varrimento progressivo (240p/288p)
- `fp2` = forçar varrimento progressivo (480p/576p)
- `1080ix1` = forçar 1080i, largura/altura x1
- `1080ix2` = forçar 1080i, largura/altura x2
- `1080ix3` = forçar 1080i, largura/altura x3
- `c` = modo de compatibilidade:
- vazio = nenhum (predefinição)
- `1` = inversão de campos tipo 1
- `2` = inversão de campos tipo 2
- `3` = inversão de campos tipo 3

Exemplos de ARG do eGSM:
- `-gsm=fp2`
- `-gsm=fp2:1`
- `-gsm=1080ix2`

Exemplo de utilização:
```
LK_TRIANGLE_E1 = mc0:/APP_WLE-ISR/WLE-ISR.ELF
ARG_TRIANGLE_E1 = -gsm=1080ix2
```

<a id="deprecatedremoved"></a>

## Obsoleto/Removido
- ~~`RUNKELF`~~ O PS2BBLE arranca agora elf/kelf internamente, sem o utilizador ter de definir uma ação de arranque kelf.


<a id="known-bugsissues"></a>

## Erros/problemas conhecidos

diga-me você ;)

<a id="credits--thanks"></a>

## Créditos e agradecimentos

- De saildot4k
  - @israpps pelo [PS2BBL](https://github.com/israpps/PlayStation2-Basic-BootLoader/)
  - @pcm720 por
    - gameID do Retrogem, PS1 Video Negator, eGSM e o código do PS2LOGO do [OSDMenu](https://github.com/pcm720/OSDMenu)
    - As opções de modo de vídeo do [NHDDL](https://github.com/pcm720/nhddl)
  - @sp193 pelo [PS1 Video Negator](https://github.com/ps2homebrew/PS1VModeNeg)
  - @nathanneurotic pelos 10 caminhos do PS2BBLE, ideias e persuasão
  - [@Berion](https://www.psx-place.com/members/berion.1431/) pelos logótipos, fundo e gráficos das teclas

- De [El Isra](https://israpps.github.io/) (programador do PS2BBL): 
  - @SP193 pelas bibliotecas de inicialização do OSD, que são a base deste projeto
  - @asmblur, por me incentivar a fazer este monstro no SDK mais recente
  - @uyjulian e @fjtrujy por me ajudarem sempre


<p align="center"><sub><a href="https://github.com/akilluminati47/RIPPS2">RIPPS2</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2/releases/latest/download/RIPPS2.elf">Transferir</a> &nbsp;&middot;&nbsp; <b>BIBLE</b> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2-themes">Temas</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPCSX2">RIPPCSX2</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2-fonts">Tipos de letra</a> &nbsp;&middot;&nbsp; <a href="https://akilluminati47.github.io/RIPPS2/">Site</a> &nbsp;&middot;&nbsp; <a href="https://www.psx-place.com/threads/ripps2-a-ps2-front-end-in-one-elf-launch-disc-storage-memory-files.51316/">psx-place</a> &nbsp;&middot;&nbsp; <a href="https://discord.gg/Z7m9u5kby">Discord</a></sub></p>

