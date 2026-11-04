// RIPPS2's Color Themes, ported from RiptOPL src/ripps2ui.c: each theme turns RIPPS2's blue with one colour matrix, built so a grey stays the same grey,
// and the sky BIBLE shows is RIPPS2's Storage sky put through that same matrix (ripps2BibleSky).
export const THEMES = [
  ['RIPPS2', 0, 1, 0], ['Ember', 150, 1.6, 0], ['Blood', 130, 1.8, 0], ['Ectoplasm', 250, 1.2, 0], ['Amethyst', 40, 1.1, 0], ['Bone', 180, 0.25, 0],
  ['Tangerine', 172, 1.7, 0.05], ['Flamingo', 112, 0.85, 0.18], ['Turquoise', 318, 1.15, 0.04], ['Moonlight', 0, 0.1, 0.55],
];

const hex = (s) => [parseInt(s.slice(0, 2), 16), parseInt(s.slice(2, 4), 16), parseInt(s.slice(4, 6), 16)];
const sw = (n, ...c) => [n, c.map(hex)];
export const SWEEPS = [
  sw('Rainbow', 'FF4D4D', 'FFD23F', '3DDC84', '4A8CF0', 'B266FF'), sw('RIPPS2', '2E5BFF', '4A8CF0', '6FB4FF', '3A6FD8', '8AA8FF'),
  sw('Ember', 'FF6A2E', 'FF9A3C', 'E8462E', 'FFB25C', 'D9542B'), sw('Blood', 'B3122E', 'E0243A', '8C0F23', 'FF4058', 'A31A30'),
  sw('Ectoplasm', '3DDC84', '7CFF9E', '2EB872', 'A6FFC4', '4FE0A0'), sw('Amethyst', '8E5CFF', 'B07CFF', '6A3FD9', 'C9A3FF', '7D4FE8'),
  sw('Bone', 'D8D2C4', 'BEB6A6', 'E8E2D4', 'A89F8E', 'CFC7B6'), sw('Tangerine', 'FF8C1A', 'FFA94D', 'FF7A00', 'FFC27A', 'FF9933'),
  sw('Flamingo', 'FF5FA2', 'FF8DC0', 'FF3D8B', 'FFB3D4', 'F06AAE'), sw('Turquoise', '1AD1C2', '4DE3D6', '0FB8AA', '7FF0E6', '2EC4D4'),
  sw('Moonlight', 'F2F4FF', 'DDE3F5', 'FFFFFF', 'C9D2EE', 'E8ECFF'),
];
export const SWEEP_SECS = { Slow: 9, Normal: 6, Lively: 3.5 };

const TINT_BASE = [0x4A, 0x8C, 0xF0];
const SKY = [[0x01, 0x02, 0x09], [0x0B, 0x19, 0x4C], [0x02, 0x04, 0x10]]; // the sky's top, horizon and floor

export function tintMatrix(hue, sat) {
  const L = [0.213, 0.715, 0.072], rad = (hue * Math.PI) / 180, c = Math.cos(rad), s = Math.sin(rad);
  const h = [0.213 + c * 0.787 - s * 0.213, 0.715 - c * 0.715 - s * 0.715, 0.072 - c * 0.072 + s * 0.928,
    0.213 - c * 0.213 + s * 0.143, 0.715 + c * 0.285 + s * 0.14, 0.072 - c * 0.072 - s * 0.283,
    0.213 - c * 0.213 - s * 0.787, 0.715 - c * 0.715 + s * 0.715, 0.072 + c * 0.928 + s * 0.072];
  const m = new Array(9);
  for (let i = 0; i < 3; i++)
    for (let j = 0; j < 3; j++) {
      let v = 0;
      for (let k = 0; k < 3; k++) v += ((i === k ? sat : 0) + L[k] * (1 - sat)) * h[k * 3 + j];
      m[i * 3 + j] = v;
    }
  return m;
}

export function tintApply(hue, sat, lift, rgb) {
  const m = tintMatrix(hue, sat), d = Math.max(...rgb) - Math.min(...rgb);
  return [0, 1, 2].map((i) => Math.min(255, Math.max(0, m[i * 3] * rgb[0] + m[i * 3 + 1] * rgb[1] + m[i * 3 + 2] * rgb[2] + lift * d)));
}

function hsv(c) {
  const mx = Math.max(...c), mn = Math.min(...c), d = mx - mn;
  let h = 0;
  if (d > 0) {
    if (mx === c[0]) h = 60 * ((((c[1] - c[2]) / d) + 6) % 6);
    else if (mx === c[1]) h = 60 * ((c[2] - c[0]) / d + 2);
    else h = 60 * ((c[0] - c[1]) / d + 4);
  }
  return [h, mx > 0 ? d / mx : 0, mx / 255];
}

// tintSolve: the tint that turns RIPPS2's blue into a colour (Custom, a sweep's colours)
export function tintSolve(t) {
  const [th, ts, tv] = hsv(t);
  let h = th - 216, s = ts / 0.69;
  for (let k = 0; k < 4; k++) {
    const [oh, os] = hsv(tintApply(h, s, 0, TINT_BASE));
    let dh = th - oh;
    while (dh > 180) dh -= 360;
    while (dh < -180) dh += 360;
    if (ts > 0.08 && os > 0.02) h += dh;
    if (os > 0.01) s *= ts / os;
    s = Math.max(0, Math.min(2.5, s));
  }
  const ov = Math.max(...tintApply(h, s, 0, TINT_BASE));
  const lift = Math.min(1, tv * 255 > ov ? (tv * 255 - ov) / 166 : 0);
  return [((h + 720) % 360), s, lift];
}

export const swatch = (hue, sat, lift) => tintApply(hue, sat, lift, TINT_BASE).map(Math.round);
export const skyOf = (hue, sat, lift) => SKY.map((c) => tintApply(hue, sat, lift, c).map((v) => Math.round(v)));
export const skyText = (sky) => sky.map((c) => c.map((v) => v.toString(16).padStart(2, '0')).join('').toUpperCase()).join(',');
export const customRgb = (s) => hex(s.replace('#', ''));

export function resolveTheme(st) {
  let first, tints = null;
  if (st.sweep !== 'Off') {
    const sweep = SWEEPS.find((x) => x[0] === st.sweep) || SWEEPS[0];
    tints = sweep[1].map(tintSolve);
    first = tints[0];
  } else if (st.theme === 'Custom') first = tintSolve(customRgb(st.custom));
  else {
    const p = THEMES.find((x) => x[0] === st.theme) || THEMES[0];
    first = p.slice(1);
  }
  return { tint: first, sky: skyOf(...first), tints, secs: SWEEP_SECS[st.sweepSpeed] || 6 };
}

// the tint in effect t seconds into a sweep: each colour eased into the next
export function tintAt(theme, t) {
  if (!theme.tints) return theme.tint;
  const n = theme.tints.length, u = t / theme.secs, i = Math.floor(u) % n, f = u - Math.floor(u), e = f * f * (3 - 2 * f);
  const a = theme.tints[i], b = theme.tints[(i + 1) % n];
  let dh = b[0] - a[0];
  while (dh > 180) dh -= 360;
  while (dh < -180) dh += 360;
  return [a[0] + dh * e, a[1] + (b[1] - a[1]) * e, a[2] + (b[2] - a[2]) * e];
}
