// BIBLE's splash on a 2D canvas, laid out as src/splash_render.c and src/splash_screen.c do it: the sky, the logo in the middle, the buttons from
// hotkeys.png under it at their own size, the info line above it, the clock block top right, and the names sheet for LOGO_DISPLAY 3.
import { FONT } from './font5x7.js';

const GLYPH_SRC_X = 6, GLYPH_SRC_W = 21, CELL = 21, GAP = 9, ROW_GAP = 8, BELOW = 20, TEXT_PAD = 18, TEXT_H = 7, ADVANCE = 6;
const SRC = { tri: [22, 20], cir: [43, 20], cro: [64, 20], squ: [85, 20], up: [106, 20], dn: [127, 20], lf: [148, 20], rt: [169, 20], l1: [191, 17], l2: [211, 20], l3: [232, 20], r1: [254, 17], r2: [274, 20], r3: [295, 20], sel: [319, 16], sta: [337, 19] };
const ROWS = [['tri', 'cir', 'cro', 'squ', 'l1', 'r1', 'sta', 'sel'], ['l2', 'r2', 'l3', 'r3', 'up', 'dn', 'lf', 'rt']];
const INFO = 'MODEL: SCPH-39001  ROM: 1.60A  DVD:   PS1DRV: 1.10  CFG SRC: MC0';
// the names sheet, in hotkeys.png's order; what Manage's config offers, plus a few of the usual launchers
const NAMES = ['RIPPS2', 'BROWSER', 'WLAUNCHELF', 'DISC', 'CREDITS', '', '', '', '', 'NEUTRINO', '', '', 'OPL', '', '', '', 'DISC'];
const MODES = { AUTO: [640, 448], NTSC: [640, 448], PAL: [640, 512], '480P': [640, 480], '576P': [720, 576], '720P': [1280, 720], '1080I': [1920, 1080] };

export const isHD = (st) => st.mode === '720P' || st.mode === '1080I';
export const isWide = (st) => isHD(st) || st.ws === 'ON';

// the picture's own pixels; a 4:3 mode with Widescreen on is drawn for a TV that stretches it, which here is simply a wider canvas
export function screenSize(st) {
  const [w, h] = MODES[st.mode] || MODES.AUTO;
  if (isWide(st) && !isHD(st)) return { w: Math.round((h * 16) / 9), h, wide: true };
  return { w, h, wide: isWide(st) };
}
export const modeLabel = (st) => {
  const { h, wide } = screenSize(st);
  const scan = st.mode === 'AUTO' || st.mode === 'NTSC' ? '480i' : st.mode === 'PAL' ? '576i' : st.mode.toLowerCase();
  return `${scan} ${wide ? '16:9' : '4:3'}` + (h ? '' : '');
};

const load = (src) => new Promise((ok, no) => { const i = new Image(); i.onload = () => ok(i); i.onerror = no; i.src = src; });
export const loadAssets = async () => ({ logo: await load('assets/logo_ps2bble.png'), sheet: await load('assets/hotkeys.png') });

function text(ctx, s, x, y, color, alpha = 1) {
  s = s.toUpperCase();
  for (let pass = 0; pass < 2; pass++) {
    ctx.fillStyle = pass ? color : '#000';
    ctx.globalAlpha = pass ? alpha : alpha * 0.6;
    const ox = pass ? 0 : 1, oy = pass ? 0 : 1;
    for (let i = 0; i < s.length; i++) {
      const g = FONT[s[i]];
      if (!g) continue;
      for (let r = 0; r < 7; r++)
        for (let c = 0; c < 5; c++)
          if (g[r] & (0x10 >> c)) ctx.fillRect(x + i * ADVANCE + c + ox, y + r + oy, 1, 1);
    }
  }
  ctx.globalAlpha = 1;
}

const css = (c) => `rgb(${c[0]},${c[1]},${c[2]})`;

export function drawSky(ctx, w, h, sky) {
  const g = ctx.createLinearGradient(0, 0, 0, h), mid = 290 / 480;
  g.addColorStop(0, css(sky[0]));
  g.addColorStop(mid, css(sky[1]));
  g.addColorStop(1, css(sky[2]));
  ctx.fillStyle = g;
  ctx.fillRect(0, 0, w, h);
}

// o: { sky (null: black), fade 0..1, remaining seconds, now Date, shimmer 0..1 (null: none) }
export function drawSplash(ctx, st, A, o) {
  const { w, h } = screenSize(st);
  if (ctx.canvas.width !== w || ctx.canvas.height !== h) { ctx.canvas.width = w; ctx.canvas.height = h; }
  ctx.imageSmoothingEnabled = false;
  ctx.globalAlpha = 1;
  ctx.globalCompositeOperation = 'source-over';
  if (st.logo === '0') { ctx.fillStyle = '#000'; ctx.fillRect(0, 0, w, h); return; } // LOGO_DISPLAY 0: nothing on screen
  if (st.bg === 'BLANK') { ctx.fillStyle = '#000'; ctx.fillRect(0, 0, w, h); } else drawSky(ctx, w, h, o.sky);

  const lw = A.logo.width, lh = A.logo.height, lx = Math.round(w / 2 - lw / 2), ly = Math.round(h / 2 - lh / 2), names = st.logo === '3', f = o.fade ?? 1;
  ctx.globalAlpha = (names ? 0.2 : 1) * f; // LOGO_TRANSPARENCY_PERCENT_WITH_HOTKEYS: 80
  ctx.drawImage(A.logo, lx, ly);
  if (o.shimmer != null && !names) { // the slow band of light across the logo (LOGO_SHIMMER_*)
    const bw = Math.max(8, lw * 0.12), bx = lx + o.shimmer * (lw + bw) - bw;
    ctx.save();
    ctx.beginPath();
    ctx.rect(bx, ly, bw, lh);
    ctx.clip();
    ctx.globalCompositeOperation = 'lighter';
    ctx.globalAlpha = 0.22 * f;
    ctx.drawImage(A.logo, lx, ly);
    ctx.restore();
    ctx.globalAlpha = 1;
  }
  ctx.globalAlpha = f;

  if (names) { // LOGO_DISPLAY 3: upstream's button sheet at 10% across, each button's name beside it
    const sx = Math.round(w * 0.1), sy = Math.round(h / 2 - A.sheet.height / 2);
    ctx.drawImage(A.sheet, sx, sy);
    if (f > 0.99) NAMES.forEach((n, i) => { if (n) text(ctx, n, sx + 50, sy + 6 + i * 21, '#ffffff'); });
  } else if (st.glyphs !== '0') {
    const rows = st.glyphs === '2' ? ROWS : [ROWS[0].slice(0, 4)], cols = rows[0].length, bw = cols * CELL + (cols - 1) * GAP;
    const gx = Math.round(w / 2 - bw / 2), gy = ly + lh + BELOW;
    rows.forEach((row, r) => row.forEach((id, k) => {
      const [sy, sh] = SRC[id];
      ctx.drawImage(A.sheet, GLYPH_SRC_X, sy, GLYPH_SRC_W, sh, gx + k * (CELL + GAP), gy + r * (CELL + ROW_GAP) + Math.floor((CELL - sh) / 2), CELL, sh);
    }));
  }
  ctx.globalAlpha = 1;

  if (st.info === '1' && f > 0.99) { // BIBLE_INFO 1: the console line above the logo; countdown, clock and date top right
    const lineW = INFO.length * ADVANCE, x = Math.round(w / 2 - lineW / 2);
    if (!names) text(ctx, INFO, x, ly - TEXT_PAD - TEXT_H, '#707070');
    const right = names ? w - Math.round(w * 0.1) : x + lineW, by = Math.round(h * 0.1), d = o.now || new Date();
    const pad = (v) => String(v).padStart(2, '0');
    const time = `${pad(d.getHours())}:${pad(d.getMinutes())}:${pad(d.getSeconds())}`, date = `${d.getFullYear()}/${pad(d.getMonth() + 1)}/${pad(d.getDate())}`;
    const bx = right - 10 * ADVANCE;
    if (o.remaining != null && o.remaining > 0) text(ctx, o.remaining.toFixed(1), bx, by, '#15d670');
    text(ctx, time, bx, by + 21, '#707070');
    text(ctx, date, bx, by + 42, '#707070');
  }
}
