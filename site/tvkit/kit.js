// tvkit: the modelling kit that stands in for Blender here. Everything is built from code in real millimetres, so a model is a plain
// text file: change a number, reload, and studio.html shows it (and exports a .glb that Blender can open later).
//
//   surface(rings)        a skin through rounded rectangles: cabinets, bezels, tapers. A ring { w, h, r, z, x, y, s }: s true runs
//                         smooth from the ring before it, otherwise the edge between them is a crease.
//   glass(w, h, curve)    a Trinitron's face: curved across, flat down. uv 0..1 over it.
//   flat(w, h, material)  a plane with its back to the model, for grilles and labels.
//   label(...)            a wordmark drawn to a texture.
//   grilleTexture(), ventTexture(), grainTexture()   surfaces drawn in code.
//   class Model           named parts in millimetres; model.parts is what the explosion and the studio's exploded view move.
import * as THREE from 'three';
import { mergeGeometries } from 'three/addons/utils/BufferGeometryUtils.js';

export const MM = 0.001;

function ringPoints(w, h, r, corner) {
  r = Math.min(r, w / 2 - 0.01, h / 2 - 0.01);
  const pts = [], cx = [w / 2 - r, -w / 2 + r, -w / 2 + r, w / 2 - r], cy = [h / 2 - r, h / 2 - r, -h / 2 + r, -h / 2 + r];
  for (let c = 0; c < 4; c++)
    for (let i = 0; i <= corner; i++) {
      const a = (c + i / corner) * Math.PI / 2;
      pts.push([cx[c] + Math.cos(a) * r, cy[c] + Math.sin(a) * r]);
    }
  pts.push(pts[0]);
  return pts;
}

function strip(rings, corner) {
  const rows = rings.map((g) => ringPoints(g.w, g.h, g.r ?? 0.5, corner).map(([x, y]) => [x + (g.x || 0), y + (g.y || 0), g.z]));
  const n = rows[0].length, pos = [], uv = [], idx = [];
  rows.forEach((row, j) => row.forEach((p, i) => { pos.push(...p); uv.push(i / (n - 1), j / Math.max(1, rows.length - 1)); }));
  for (let j = 0; j < rows.length - 1; j++)
    for (let i = 0; i < n - 1; i++) {
      const a = j * n + i, b = a + 1, c = a + n, d = c + 1;
      idx.push(a, b, c, b, d, c);
    }
  const g = new THREE.BufferGeometry();
  g.setAttribute('position', new THREE.Float32BufferAttribute(pos, 3));
  g.setAttribute('uv', new THREE.Float32BufferAttribute(uv, 2));
  g.setIndex(idx);
  g.computeVertexNormals();
  const nor = g.attributes.normal; // the seam: the first and last columns share a normal
  for (let j = 0; j < rows.length; j++) {
    const a = j * n, b = a + n - 1, v = new THREE.Vector3(nor.getX(a) + nor.getX(b), nor.getY(a) + nor.getY(b), nor.getZ(a) + nor.getZ(b)).normalize();
    nor.setXYZ(a, v.x, v.y, v.z);
    nor.setXYZ(b, v.x, v.y, v.z);
  }
  return g;
}

function cap(g, corner, flip) {
  const row = ringPoints(g.w, g.h, g.r ?? 0.5, corner), pos = [(g.x || 0), (g.y || 0), g.z], idx = [], uv = [0.5, 0.5];
  row.forEach(([x, y]) => { pos.push(x + (g.x || 0), y + (g.y || 0), g.z); uv.push(x / g.w + 0.5, y / g.h + 0.5); });
  for (let i = 1; i < row.length; i++) flip ? idx.push(0, i + 1, i) : idx.push(0, i, i + 1);
  const b = new THREE.BufferGeometry();
  b.setAttribute('position', new THREE.Float32BufferAttribute(pos, 3));
  b.setAttribute('uv', new THREE.Float32BufferAttribute(uv, 2));
  b.setIndex(idx);
  b.computeVertexNormals();
  return b;
}

// rings run from the back of a shape forward and then inward, so the skin faces out all the way along it
export function surface(rings, { corner = 6, capStart = false, capEnd = false } = {}) {
  const parts = [];
  let run = [rings[0]];
  for (let i = 1; i < rings.length; i++) {
    if (rings[i].s) run.push(rings[i]);
    else { run.push(rings[i]); parts.push(strip(run, corner)); run = [rings[i]]; }
  }
  if (run.length > 1) parts.push(strip(run, corner));
  if (capStart) parts.push(cap(rings[0], corner, true));
  if (capEnd) parts.push(cap(rings[rings.length - 1], corner, false));
  return mergeGeometries(parts, false);
}

export function glass(w, h, curve, segs = 32) {
  const g = new THREE.PlaneGeometry(w, h, segs, 8), p = g.attributes.position;
  for (let i = 0; i < p.count; i++) {
    const x = p.getX(i) / (w / 2);
    p.setZ(i, curve * (1 - x * x));
  }
  g.computeVertexNormals();
  return g;
}

function canvasTexture(w, h, draw, { srgb = true, repeat = false } = {}) {
  const c = document.createElement('canvas');
  c.width = w;
  c.height = h;
  draw(c.getContext('2d'), w, h);
  const t = new THREE.CanvasTexture(c);
  if (srgb) t.colorSpace = THREE.SRGBColorSpace;
  t.anisotropy = 8;
  if (repeat) t.wrapS = t.wrapT = THREE.RepeatWrapping;
  return t;
}

// a wordmark: the type is drawn wide and small-capped by hand, since a model cannot depend on what a phone has installed
export function label(text, { font = 'bold 96px Georgia, "Times New Roman", serif', color = '#d8d8d8', spacing = 10, w = 512, h = 128, italic = false } = {}) {
  return canvasTexture(w, h, (ctx) => {
    ctx.font = (italic ? 'italic ' : '') + font;
    ctx.fillStyle = color;
    ctx.textBaseline = 'middle';
    ctx.textAlign = 'left';
    let total = 0;
    for (const ch of text) total += ctx.measureText(ch).width + spacing;
    let x = (w - total + spacing) / 2;
    for (const ch of text) {
      ctx.fillText(ch, x, h / 2 + 4);
      x += ctx.measureText(ch).width + spacing;
    }
  });
}

export const grilleTexture = (dark = '#050506', hole = '#2b2b2e', cols = 6, rows = 6) => canvasTexture(64, 64, (ctx, w, h) => {
  ctx.fillStyle = hole;
  ctx.fillRect(0, 0, w, h);
  ctx.fillStyle = dark;
  for (let y = 0; y < rows; y++)
    for (let x = 0; x < cols; x++) {
      ctx.beginPath();
      ctx.arc((x + 0.5 + (y % 2) * 0.5) * w / cols, (y + 0.5) * h / rows, w / cols * 0.3, 0, 7);
      ctx.fill();
    }
}, { repeat: true });

export const ventTexture = (base = '#343437') => canvasTexture(256, 64, (ctx, w, h) => {
  ctx.fillStyle = base;
  ctx.fillRect(0, 0, w, h);
  ctx.fillStyle = '#0a0a0b';
  for (let i = 0; i < 12; i++) ctx.fillRect(8 + i * 20, 12, 9, h - 24);
}, { repeat: true });

export const grainTexture = () => canvasTexture(128, 128, (ctx, w, h) => {
  const im = ctx.createImageData(w, h);
  let s = 12345;
  for (let i = 0; i < im.data.length; i += 4) {
    s = (s * 1664525 + 1013904223) >>> 0;
    const v = 118 + (s >>> 24) / 255 * 20;
    im.data[i] = im.data[i + 1] = im.data[i + 2] = v;
    im.data[i + 3] = 255;
  }
  ctx.putImageData(im, 0, 0);
}, { srgb: false, repeat: true });

export const plastic = (color, roughness = 0.62, extra = {}) => new THREE.MeshStandardMaterial({ color, roughness, metalness: 0.02, ...extra });

export class Model extends THREE.Group {
  constructor(name) {
    super();
    this.name = name;
    this.parts = [];
    this.screen = null;
    this.size = { w: 0, h: 0, d: 0 };
    this.body = new THREE.Group();
    this.body.scale.setScalar(MM);
    this.add(this.body);
  }

  // a piece in millimetres; `flies` false keeps it fixed to the part it sits on when the model explodes
  part(name, geometry, material, { x = 0, y = 0, z = 0, ry = 0, rx = 0, flies = true, mass = 1 } = {}) {
    const m = new THREE.Mesh(geometry, material);
    m.name = name;
    m.position.set(x, y, z);
    m.rotation.set(rx, ry, 0);
    m.userData.home = { p: m.position.clone(), r: m.rotation.clone() };
    m.userData.flies = flies;
    m.userData.mass = mass;
    this.body.add(m);
    this.parts.push(m);
    return m;
  }

  flat(name, w, h, material, opts = {}) {
    return this.part(name, new THREE.PlaneGeometry(w, h), material, { flies: false, ...opts });
  }

  decal(name, texture, w, h, opts = {}) {
    const mat = new THREE.MeshStandardMaterial({ map: texture, transparent: true, roughness: 0.35, metalness: 0.5, polygonOffset: true, polygonOffsetFactor: -2 });
    return this.flat(name, w, h, mat, opts);
  }

  home() {
    for (const m of this.parts) {
      m.position.copy(m.userData.home.p);
      m.rotation.copy(m.userData.home.r);
      m.visible = true;
    }
  }
}
