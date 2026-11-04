// The settings: BIBLE's rows are Manage's, with its names and its values (RIPPS2 src/ripps2boot.c, blSets), each one line of PS2BBL.INI; then RIPPS2's Color
// Theme, since BIBLE's sky follows it; then what this page itself does. Kept in this browser only.
import { THEMES, SWEEPS, skyText, resolveTheme } from './themes.js';

const onoff = [['0', 'Off'], ['1', 'On']];
export const SCHEMA = [
  { title: 'BIBLE', note: "Every row Manage's BIBLE menu offers. Each is one line of PS2BBL.INI.", rows: [
    { id: 'bg', label: 'Background', key: 'BIBLE_BACKGROUND', opts: [['AUTO', 'Auto'], ['SKY', 'Sky'], ['BLANK', 'Black']], hint: 'Auto is your RIPPS2 sky when BIBLE starts RIPPS2, as it does here.' },
    { id: 'logo', label: 'Splash', key: 'LOGO_DISPLAY', opts: [['0', 'Off'], ['2', 'Logo'], ['3', 'Logo and Names']] },
    { id: 'glyphs', label: 'Button Glyphs', key: 'BIBLE_GLYPHS', opts: [['0', 'None'], ['1', 'Face Buttons'], ['2', 'All Sixteen']] },
    { id: 'info', label: 'Info Line', key: 'BIBLE_INFO', opts: onoff },
    { id: 'wait', label: 'Power-on Wait', key: 'KEY_READ_WAIT_TIME', opts: ['0', '1000', '2000', '3000', '6000', '10000'].map((v) => [v, v + ' ms']), hint: '0 ms is the shortest loop. A button held from power on still picks its entry.' },
    { id: 'disc', label: 'Stop Disc at Launch', key: 'DISC_STOP', opts: onoff, hint: 'On waits for the drive at launch: about 3.3 s at 0 ms in the lab, none by 6000 ms. Off leaves a disc spinning.' },
    { id: 'mode', label: 'Video Mode', key: 'VIDEO_MODE', opts: [['AUTO', 'Auto'], ['NTSC', 'NTSC'], ['PAL', 'PAL'], ['480P', '480p'], ['576P', '576p'], ['720P', '720p'], ['1080I', '1080i']], hint: '720p and 1080i are 16:9, so the Trinitron does not survive them.' },
    { id: 'ws', label: 'Widescreen', key: 'BIBLE_WIDESCREEN', opts: [['AUTO', 'Auto'], ['ON', 'On'], ['OFF', 'Off']], hint: 'On means 16:9. Close this panel and watch.' },
  ] },
  { title: 'RIPPS2 Color Theme', note: 'BIBLE reads the sky RIPPS2 saves, so the theme sets the splash and the towers.', rows: [
    { id: 'theme', label: 'Color Theme', type: 'theme' },
    { id: 'sweep', label: 'Color Sweep', opts: [['Off', 'Off'], ...SWEEPS.map((s) => [s[0], s[0]])], hint: 'The towers fade through its five colours. BIBLE takes the sky from the first.' },
    { id: 'sweepSpeed', label: 'Sweep Speed', opts: [['Slow', 'Slow'], ['Normal', 'Normal'], ['Lively', 'Lively']], showIf: (s) => s.sweep !== 'Off' },
  ] },
  { title: 'This page', rows: [
    { id: 'black', label: 'Black time', opts: [['lab', 'Lab, measured'], ['console', 'SD2PSX console, estimate']], hint: 'Lab: 7.4 s between the splash and the towers, in frames from PCSX2. Console: the towers come 2.44 s later in RIPPS2\'s own DIAG.TXT on a SCPH-39001, added to the lab\'s load.' },
    { id: 'sound', label: 'Explosion sound', opts: onoff },
    { id: 'flash', label: 'Flashes', opts: [['full', 'Full'], ['soft', 'Reduced']], hint: 'Never more than three a second either way.' },
    { id: 'quality', label: 'Quality', opts: [['auto', 'Auto'], ['high', 'High'], ['low', 'Low']] },
  ] },
];

export const DEFAULTS = {
  bg: 'AUTO', logo: '2', glyphs: '1', info: '0', wait: '2000', disc: '0', mode: 'AUTO', ws: 'AUTO',
  theme: 'RIPPS2', custom: '#ff83af', sweep: 'Off', sweepSpeed: 'Normal',
  black: 'lab', sound: '1', flash: matchMedia('(prefers-reduced-motion: reduce)').matches ? 'soft' : 'full', quality: 'auto',
};

const KEY = 'bible-site-settings-1';
export function load() {
  try {
    const s = JSON.parse(localStorage.getItem(KEY) || '{}');
    return { ...DEFAULTS, ...s };
  } catch { return { ...DEFAULTS }; }
}
export function save(st) {
  try { localStorage.setItem(KEY, JSON.stringify(st)); } catch { /* a private window: it simply is not kept */ }
}

export function iniText(st) {
  const lines = ["# BIBLE's settings, from akilluminati47.github.io/BIBLE. Paste over these lines in mc?:/SYS-CONF/PS2BBL.INI", '# and keep your own NAME_ and LK_ lines. Manage in RIPPS2 changes them for you too.'];
  for (const row of SCHEMA[0].rows) lines.push(`${row.key} = ${st[row.id]}`);
  lines.push(`# BIBLE_COLOR stays unset: RIPPS2 saves this sky with its settings and BIBLE reads it: ${skyText(resolveTheme(st).sky)}`);
  return lines.join('\n');
}

export const swatchThemes = [...THEMES.map((t) => t[0]), 'Custom'];
