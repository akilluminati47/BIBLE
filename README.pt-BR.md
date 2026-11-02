<!-- i18n: the language bar, made by ps2-pillars tools/readme-i18n -->
<p align="center">
  <a href="README.md">English</a> |
  <a href="README.es.md">Español</a> |
  <b>Português (Brasil)</b> |
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

<p align="center"><sub>Tradução do README em inglês; se diferirem, vale o inglês. <a href="README.md">English</a></sub></p>

<p align="center"><sub><a href="https://github.com/akilluminati47/RIPPS2">RIPPS2</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2/releases/latest/download/RIPPS2.elf">Baixar</a> &nbsp;&middot;&nbsp; <b>BIBLE</b> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2-themes">Temas</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPCSX2">RIPPCSX2</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2-fonts">Fontes</a> &nbsp;&middot;&nbsp; <a href="https://akilluminati47.github.io/RIPPS2/">Site</a> &nbsp;&middot;&nbsp; <a href="https://www.psx-place.com/threads/ripps2-a-ps2-front-end-in-one-elf-launch-disc-storage-memory-files.51316/">psx-place</a> &nbsp;&middot;&nbsp; <a href="https://discord.gg/Z7m9u5kby">Discord</a></sub></p>

<h1 align="center">BIBLE</h1>
<p align="center">
  <a href="https://github.com/akilluminati47/RIPPS2">RIPPS2</a> ·
  <a href="https://github.com/akilluminati47/BIBLE/actions">Builds</a> ·
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
  <sub>Segure L2 + R2 ao ligar para a página das teclas de inicialização, TRIANGLE + CROSS para a página do modo de vídeo; uma tecla definida como <code>$CREDITS</code> mostra os créditos.</sub>
</p>

BIBLE é o boot loader que o RIPPS2 instala: um fork do PS2BBL Extended de saildot4k.

**O que este fork muda**

- A tela de abertura: o logo do PS2 centralizado no céu do RIPPS2, com os botões abaixo e qualquer texto acima.
  `BIBLE_GLYPHS` 0 nenhum, 1 os botões frontais (padrão), 2 todos os dezesseis em duas fileiras de oito.
  `BIBLE_INFO` 1 mostra as informações do console, o relógio e a contagem regressiva (desligado por padrão).
  O céu combina com o seu Color Theme do RIPPS2: sem `BIBLE_COLOR`, o BIBLE lê o céu que o RIPPS2 salva com suas
  configurações, da pasta do RIPPS2 que a entrada AUTO inicia (`BIBLE_COLOR` na configuração prevalece).
  O mesmo visual em todos os modos de vídeo. As páginas (modo de vídeo, créditos, teclas de inicialização) surgem sobre o logo escurecido
  com os botões recolhidos, para que as teclas de inicialização fiquem fáceis de ler.
- Modos de vídeo: `VIDEO_MODE` também aceita `576P`, `720P` e `1080I`, o resto dos do RIPPS2. `AUTO` (o padrão)
  inicia no Video Mode do RIPPS2 quando as configurações dele estão ao lado da entrada AUTO, senão no do próprio console.
- `BIBLE_WIDESCREEN`: `AUTO` (o padrão: o Widescreen do RIPPS2, senão a configuração de tela 16:9 do PS2), `ON` ou
  `OFF`. Em 480i, 576i, 480p e 576p a abertura é desenhada para uma TV que estica a imagem para 16:9, sem
  achatar. 720p e 1080i já são 16:9.
- Sem salto ao entrar no RIPPS2: ao iniciar, o logo e os botões somem e o céu fica na tela, no modo do RIPPS2;
  o RIPPS2 começa nesse mesmo céu. Segure TRIANGLE + CROSS ao ligar para a página do modo de vídeo, que sempre abre
  no modo entrelaçado do próprio console (o caminho de volta do 720p ou 1080i num cabo composto).
- Novo: a página das teclas de inicialização. Segure L2 + R2 ao ligar para ler o caminho de cada tecla, sejam quais forem suas configurações de abertura.
- Combinações seguradas desde o momento em que se liga agora abrem suas páginas (TRIANGLE + CROSS se perdia enquanto os controles ainda
  iniciavam).
- `KEY_READ_WAIT_TIME = 0` é permitido (o mínimo do upstream é 500 ms).
- Builds de PS2 para memory card / USB, MMCE, MX4SIO e HDD. O estágio 2 do eGSM fica de fora.

**Como o RIPPS2 o usa**

O RIPPS2 vai levar o BIBLE como arquivos de boot assinados e instalá-lo pelas suas Settings (Boot Loader), no lugar do PS2BBL 1.2.0 que leva hoje. O BIBLE também roda como um ELF iniciado por outro loader (FMCB, OSDMenu, o loader de um SD2PSX). Ainda não há release do BIBLE.

<p align="center"><img src="assets/readme/ripps2-icon.png" alt="RIPPS2" width="48" height="48"><br><sub>BIBLE faz parte do <a href="https://github.com/akilluminati47/RIPPS2">RIPPS2</a>.</sub></p>

---

<p align="center"><sub>Tudo abaixo é o README original do PS2BBL Extended, traduzido sem outras mudanças.</sub></p>

---


<br />
<p align="center">
  <a href="https://israpps.github.io/PlayStation2-Basic-BootLoader/">
    <img src="https://github.com/saildot4k/PlayStation2-Basic-BootLoader-Extended/blob/main/assets/ps2bbl_example.png" alt="Logo" width="50%" height="auto">
  </a>

  <p align="center">
    Um boot loader flexível para PlayStation 2™ e PSX-DESR
    <br />
  </p>
</p>  


Este é um fork do PS2BBL de [El Isra](https://github.com/israpps/PlayStation2-Basic-BootLoader/)


<a id="documentation"></a>

## Documentação

Está hospedada no [github pages](https://israpps.github.io/PlayStation2-Basic-BootLoader/), mas com os acréscimos abaixo:

<a id="config-and-arguments"></a>

## Configuração e argumentos

Edite o arquivo de configuração conforme precisar. Recomenda-se o [R3Configurator](https://github.com/saildot4k/R3CONFIGURATOR) para editar o arquivo. Os caminhos já vêm prontos para combinar com os downloads da [PS2 Homebrew Store](https://ps2homebrewstore.com). Assim você só deve precisar editar sua escolha Auto e, de preferência, definir os argumentos do NHDDL conforme o dispositivo de onde carrega as ISOs.

<a id="config-path-search-order"></a>

### Ordem de busca da configuração

A busca da configuração agora leva em conta a família de boot para não carregar drivers desnecessários na inicialização:

1. `CONFIG.INI` (CWD: diretório de trabalho atual)
2. Quando carregado de um dispositivo:
   - Boot por MMCE: `mmce?:/PS2BBL/CONFIG.INI`
   - Boot por MX4SIO: `mx4sio:/PS2BBL/CONFIG.INI`
   - Boot por APA HDD: `hdd0:__sysconf:pfs:/PS2BBL/CONFIG.INI`
   - Boot por BDM: `usb:/PS2BBL/CONFIG.INI` / `mass:/PS2BBL/CONFIG.INI` / `ata:/PS2BBL/CONFIG.INI`
3. Alternativa no memory card:
   - No PS2: `mc?:/SYS-CONF/PS2BBL.INI`
   - No PSX-DESR: `mc?:/SYS-CONF/PSXBBL.INI`
4. Última alternativa no PSX
   - `xfrom:/PS2BBL/CONFIG.INI`
5. Quando compilado com `DISC_STOP_AT_BOOT=1
   - `cdrom0:/PS2BBL/CONFIG.INI`
   - Alternativa no memory card como no item 3 acima.

<a id="device-path-prefixes"></a>

### Prefixos de caminho de dispositivo
O PS2BBL aceita estes prefixos de caminho de inicialização/configuração:
- `mc0:/`, `mc1:/`, `mc?:/`
- `usb:/` (preferido) e `mass:/` (antigo)

<a id="build-specific"></a>

#### Conforme a build:  
- `mmce0:/`, `mmce1:/`, `mmce?:/` __builds MMCE__
- `mx4sio:/` (preferido) e `massX:/` (antigo)  __builds MX4SIO__
- `hdd0:partition:pfs:/<path to elf>` __builds HDD__
- Caminhos `xfrom:/` __builds PSX DESR__
- `ata:/` dispositivo BDM de HDD exFAT
- `ilink:/` (raízes de armazenamento em massa BDM) __ainda não implementado__
- `DISC_STOP_AT_BOOT=1` perfil de compilação para sempre parar o disco óptico após carregar a configuração

### LOGO_DISPLAY
Use `LOGO_DISPLAY = 3` para mostrar os nomes das teclas. Os nomes são definidos por `NAME_<BUTTON>`.
  - `0` Sem logo nem informações do console
  - `1` Informações do console
  - `2` Logo PS2BBLE/PSXBBLE e informações do console
  - `3` Gráfico das teclas com `NAME_BUTTON = <TITLE>` vindo do arquivo de configuração
    - Exemplo:
      ```
      NAME_SQUARE = POPSLOADER
      ```

<a id="custom-splash-logo-from-cwd"></a>

#### Logo de abertura próprio a partir do CWD
Se um arquivo de logo próprio (LOGO.BIN) for encontrado no CWD (diretório de trabalho atual), ele substitui o logo PS2BBLE/PSXBBLE embutido.

Converta um PNG no arquivo bruto esperado:
  - O PNG deve ser RGBA de 8 bits indexado, 255 cores por canal e resolução 256x64.

  - Pacote do release (o script fica na raiz do release):
  ```bash
  python png_to_logo_rbga.py my_logo.png
  ```

  - Coloque o `LOGO.BIN` criado ao lado do PS2BBL Extended. Deve ser `mc?:/BOOT/` se usar os downloads da [PS2 Homebrew Store](https://ps2store.com)

<a id="retrogem-visual-game-id"></a>

### ID visual de jogo do Retrogem
- `APP_GAMEID = 1` ativa o ID visual de jogo para apps/homebrew, com até 11 caracteres tirados do nome do arquivo ou do disco de PS1/2
- `CDROM_DISABLE_GAMEID = 1` desativa o ID visual de jogo para discos iniciados via `cdrom`.

<a id="disc-spin-control"></a>

### Controle de rotação do disco
- Chave/valor global: `DISC_STOP = 0/1`
- `DISC_STOP = 1` para o disco óptico após carregar a configuração quando um arquivo de configuração foi encontrado.
- `DISC_STOP = 0` (ou omitido) mantém o comportamento padrão.
- `-disc_stop` pode ser adicionado a cada entrada para parar o disco depois que o ELF de destino é encontrado.

<a id="video-mode"></a>

### Modo de vídeo
- `VIDEO_MODE = AUTO, NTSC, PAL, 480P` Usa o padrão do PS2 ou força um dos outros 3 modos.

<a id="emergency-video-mode-selector"></a>

#### Seletor de modo de vídeo de emergência
- Entre com `TRIANGLE + CROSS` durante o boot
- O seletor força `LOGO_DISPLAY = 3` enquanto está ativo, para que você veja o contexto do logo e das teclas.
- Controles:
  - `LEFT/RIGHT` alternam os modos: `AUTO`, `NTSC`, `PAL`, `480P`
  - `SELECT` salva o modo selecionado no arquivo de configuração ativo
  - `START` sai do seletor e segue para a tela das teclas

<a id="cdrom-launch-args"></a>

### Argumentos de inicialização de CDROM
Para `LK_*_E* = cdrom`, os argumentos aceitos são:
- `-nologo`
- `-nogameid`
- `-ps1fast`
- `-ps1smooth`
- `-ps1vneg`
- `-gsm=<v[:c]>`

<a id="ps2logo-arguments-ps2-discs-only"></a>

#### Argumentos do PS2LOGO (só discos de PS2)
- Use `cdrom` como caminho da entrada.
- Adicione `-nologo` aos argumentos da entrada para iniciar discos de PS2 diretamente (pula o `rom0:PS2LOGO`).
- Sem `-nologo`, o PS2BBL roda o disco pelo PS2LOGO e o corrige para sempre usar a região do disco e pular a verificação de checksum do logo.
- DECKARD IE 75K e posteriores: o XPARAM.IRX é aplicado automaticamente quando necessário para inicializações sem logo.

<a id="ps1-disc-arguments-per-launch"></a>

#### Argumentos de discos de PS1 (por inicialização)
Valem para cada entrada `cdrom`, não de forma global.
- `-ps1fast` ativa a velocidade rápida do disco de PS1.
- `-ps1smooth` ativa a suavização de texturas.
- `-ps1vneg` roda o PS1DRV pelo PS1VModeNegator. Útil em configurações em que o modo do console e o do disco diferem (por exemplo alguns casos de MechaPwn/modchip).

<a id="app-arguments"></a>

### Argumentos de apps
Use linhas `ARG_<BUTTON>_E? =` para passar argumentos a um ELF (veja os exemplos de INI).
- Coloque primeiro os argumentos do elf iniciado e depois acrescente os argumentos internos do PS2BBL que quiser (veja abaixo). O [NHDDL](https://github.com/pcm720/nhddl) é um ótimo candidato para usar argumentos, pois acelera o boot do NHDDL.
- `-titleid=SLUS_123.45` substitui o ID de título do app (até 11 caracteres).
- `-appid` força o ID visual de jogo do app mesmo com `APP_GAMEID = 0`.
- `-disc_stop` para o disco depois que o ELF de destino é carregado (útil por entrada sem builds `DISC_STOP_AT_BOOT`).
- `-gsm=<v[:c]>` roda o ELF de destino pelo eGSM embutido (ignorado em caminhos `rom?:`). Se usado, deve ser o último argumento.
- `-disc_stop` é ignorado em entradas `cdrom`.
- `-dev9=<mode>` define a política de DEV9/HDD antes de iniciar o ELF de destino. Modos aceitos:
  - `NICHDD` mantém ligados tanto o DEV9 (adaptador de rede) quanto o HDD.
  - `NIC` mantém o DEV9/rede ligados, desmonta `pfs0:` e coloca `hdd0:`/`hdd1:` em repouso imediato.
  - se omitido, o PS2BBL não força nenhuma política de DEV9.
  - obs.: em builds sem HDD esta opção não tem efeito.
- `-patinfo` ativa o tratamento de PATINFO para entradas `:PATINFO`.
  - O PS2BBL lê o `SYSTEM.CNF` da área de atributos da partição (`PS2ICON3D`) e aplica `BOOT2/BOOT/path`, `arg*`, `skip_argv0` e `HDDUNITPOWER`.
  - se `BOOT2/BOOT/path=PATINFO`, o PS2BBL carrega o ELF embutido da área de atributos da partição e usa a passagem interna `-la=E...`.
  - se `IOPRP=PATINFO` (ou um caminho próprio), o PS2BBL o passa ao estágio 2 pela passagem interna `-la=I...`.
  - se `-patinfo` estiver presente, o primeiro argumento restante substitui o destino `BOOT2/BOOT/path` do CNF.
  Isto é para builds HDD.  
  Exemplo de PATINFO:  
    ```
    NAME_R1 = My App via PATINFO
    LK_R1_E1 = hdd0:+OSDMENU:PATINFO
    ARG_R1_E1 = pfs:/APPS/MYAPP.ELF
    ARG_R1_E1 = -patinfo               # Tells PS2BBL to use first arg as patinfo boot path.
    ```

Exemplo para iniciar o NHDDL em modo de vídeo 480p e procurar ISOs no mmce e num HDD exFAT sem precisar do nhddl.yaml. A vantagem é não perder tempo carregando drivers, procurando e carregando o nhddl.yaml. É o jeito mais rápido de iniciar o NHDDL e mostrar a lista de ISOs.
```
NAME_R1 = NHDDL
LK_R1_E1 = mmce?:/NEUTRINO/nhddl.elf
ARG_R1_E1 = -video=480p
ARG_R1_E1 = -mode=mmce
ARG_R1_E1 = -mode=ata
```

<a id="argument-precedence-and-order"></a>

#### Precedência e ordem dos argumentos
1. O PS2BBL analisa e consome só os argumentos finais de controle do loader de `ARG_*`: `-appid`, `-titleid=`, `-dev9=`, `-patinfo`, `-disc_stop`, `-gsm=`.
2. A análise vai de baixo para cima e para no primeiro argumento que não é de controle (comportamento final no estilo do OSDMenu).
4. Para caminhos `:PATINFO`, o PS2BBL analisa o `SYSTEM.CNF` do atributo da partição e acrescenta as entradas `arg*` do CNF após os argumentos do app do usuário.
5. Se `-patinfo` estiver definido e o caminho contiver `:PATINFO`, o primeiro argumento restante do usuário vira o caminho do ELF de destino (substitui o caminho de boot do CNF) e é removido do argv do app. Se não sobrar argumento, a inicialização é cancelada (igual ao OSDMenu) e o `BOOT2/BOOT/path` do CNF não é usado.
6. Os argumentos restantes mantêm a ordem e são passados ao app iniciado.


### eGSM (external Graphics Synthesize Mode)
Para discos de PS2, o eGSM é lido automaticamente de `OSDGSM.CNF` (sem precisar de caminho no INI). Veja [aqui](https://github.com/pcm720/OSDMenu/blob/main/patcher/README.md#osdgsmcnf) o formato do arquivo de configuração.

- `-gsm=<v[:c]>` roda o ELF de destino pelo eGSM embutido (ignorado em caminhos `rom?:`).
  - O eGSM é aplicado ao destino iniciado (ELF/disco), não ao próprio PS2BBL.
  Formato do eGSM (no estilo do OSDMenu):
- `v` = modo de vídeo:
- vazio = não forçar (padrão)
- `fp1` = forçar varredura progressiva (240p/288p)
- `fp2` = forçar varredura progressiva (480p/576p)
- `1080ix1` = forçar 1080i, largura/altura x1
- `1080ix2` = forçar 1080i, largura/altura x2
- `1080ix3` = forçar 1080i, largura/altura x3
- `c` = modo de compatibilidade:
- vazio = nenhum (padrão)
- `1` = inversão de campos tipo 1
- `2` = inversão de campos tipo 2
- `3` = inversão de campos tipo 3

Exemplos de ARG do eGSM:
- `-gsm=fp2`
- `-gsm=fp2:1`
- `-gsm=1080ix2`

Exemplo de uso:
```
LK_TRIANGLE_E1 = mc0:/APP_WLE-ISR/WLE-ISR.ELF
ARG_TRIANGLE_E1 = -gsm=1080ix2
```

<a id="deprecatedremoved"></a>

## Obsoleto/Removido
- ~~`RUNKELF`~~ O PS2BBLE agora inicia elf/kelf internamente, sem o usuário precisar definir uma ação de inicialização kelf.


<a id="known-bugsissues"></a>

## Bugs/problemas conhecidos

me conta você ;)

<a id="credits--thanks"></a>

## Créditos e agradecimentos

- De saildot4k
  - @israpps pelo [PS2BBL](https://github.com/israpps/PlayStation2-Basic-BootLoader/)
  - @pcm720 por
    - gameID do Retrogem, PS1 Video Negator, eGSM e o código do PS2LOGO do [OSDMenu](https://github.com/pcm720/OSDMenu)
    - As opções de modo de vídeo do [NHDDL](https://github.com/pcm720/nhddl)
  - @sp193 pelo [PS1 Video Negator](https://github.com/ps2homebrew/PS1VModeNeg)
  - @nathanneurotic pelos 10 caminhos do PS2BBLE, ideias e persuasão
  - [@Berion](https://www.psx-place.com/members/berion.1431/) pelos logos, fundo e gráficos das teclas

- De [El Isra](https://israpps.github.io/) (desenvolvedor do PS2BBL): 
  - @SP193 pelas bibliotecas de inicialização do OSD, que são a base deste projeto
  - @asmblur, por me incentivar a fazer este monstro no SDK mais recente
  - @uyjulian e @fjtrujy por sempre me ajudarem


<p align="center"><sub><a href="https://github.com/akilluminati47/RIPPS2">RIPPS2</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2/releases/latest/download/RIPPS2.elf">Baixar</a> &nbsp;&middot;&nbsp; <b>BIBLE</b> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2-themes">Temas</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPCSX2">RIPPCSX2</a> &nbsp;&middot;&nbsp; <a href="https://github.com/akilluminati47/RIPPS2-fonts">Fontes</a> &nbsp;&middot;&nbsp; <a href="https://akilluminati47.github.io/RIPPS2/">Site</a> &nbsp;&middot;&nbsp; <a href="https://www.psx-place.com/threads/ripps2-a-ps2-front-end-in-one-elf-launch-disc-storage-memory-files.51316/">psx-place</a> &nbsp;&middot;&nbsp; <a href="https://discord.gg/Z7m9u5kby">Discord</a></sub></p>

