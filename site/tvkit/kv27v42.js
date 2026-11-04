// Sony KV-27V42, one of the last curved Trinitrons (1999 to about 2001). Sizes in millimetres from Sony's manual: 692 wide, 578 high, 505 deep
// (27 1/4 x 22 3/4 x 19 7/8 in), 27 inch viewable. Layout from photographs: a charcoal cabinet with a wide flat bezel stepping in to the tube,
// the Trinitron mark top left, the wordmark low and centred with a small window to its right, a pale pedestal lip, side speakers and
// controls on the top instead of the front. Fan-made from those facts, not from any manufacturer's data.
import * as THREE from 'three';
import { Model, surface, glass, label, grilleTexture, ventTexture, grainTexture, plastic } from './kit.js';

const W = 692, H = 578, D = 505;
const FOOT = 26;              // the pedestal under the cabinet
const FACE_H = H - FOOT;      // the front of the cabinet
const TUBE_W = 549, TUBE_H = 411;
const TUBE_Y = 44;            // the tube sits high: a narrow top, a deep chin

export function buildKV27V42() {
  const m = new Model('Sony KV-27V42');
  m.size = { w: W, h: H, d: D };
  m.kind = 'crt';
  const grain = grainTexture();
  grain.repeat.set(5, 5);
  const shellMat = plastic(0x3b3b3e, 0.58, { roughnessMap: grain });
  const stepMat = plastic(0x2a2a2c, 0.5);
  const rearMat = plastic(0x2e2e30, 0.72);
  const footMat = plastic(0x5e5e60, 0.5);
  const cy = FOOT + FACE_H / 2;

  // the front: side wall, a soft edge, the wide flat bezel, then the two steps in to the tube
  m.part('cabinet front', surface([
    { w: W - 10, h: FACE_H - 10, r: 22, z: -150 },
    { w: W, h: FACE_H, r: 20, z: -112 },
    { w: W, h: FACE_H, r: 20, z: -8, s: true },
    { w: W - 6, h: FACE_H - 6, r: 18, z: 0, s: true },
    { w: TUBE_W + 62, h: TUBE_H + 56, r: 18, z: 0, y: TUBE_Y - 2 },
    { w: TUBE_W + 42, h: TUBE_H + 36, r: 15, z: -7, y: TUBE_Y },
    { w: TUBE_W + 12, h: TUBE_H + 10, r: 12, z: -24, y: TUBE_Y },
    { w: TUBE_W, h: TUBE_H, r: 10, z: -32, y: TUBE_Y },
    { w: TUBE_W - 6, h: TUBE_H - 6, r: 8, z: -60, y: TUBE_Y },
  ], { corner: 8 }), shellMat, { y: cy, mass: 1.2 });

  // the step is a touch darker: a thin frame laid over the deeper part of the slope
  m.part('tube surround', surface([
    { w: TUBE_W + 40, h: TUBE_H + 34, r: 15, z: -7.5 },
    { w: TUBE_W + 11, h: TUBE_H + 9, r: 12, z: -24.5 },
    { w: TUBE_W - 1, h: TUBE_H - 1, r: 10, z: -32.5 },
  ], { corner: 8 }), stepMat, { y: cy + TUBE_Y, flies: false });

  // the back tapers hard towards the neck of the tube
  const vent = ventTexture('#2e2e30');
  vent.repeat.set(6, 3);
  m.part('cabinet rear', surface([
    { w: 200, h: 170, r: 18, z: -D },
    { w: 400, h: 330, r: 30, z: -D + 18 },
    { w: 520, h: 420, r: 38, z: -372, s: true },
    { w: 630, h: 500, r: 34, z: -240, s: true },
    { w: W - 12, h: FACE_H - 12, r: 24, z: -146, s: true },
  ], { capStart: true, corner: 8 }), rearMat, { y: cy - 8, mass: 1.6 });
  m.part('rear vents', surface([
    { w: 396, h: 326, r: 30, z: -D + 22 },
    { w: 516, h: 416, r: 38, z: -372, s: true },
  ], { corner: 8 }), new THREE.MeshStandardMaterial({ map: vent, roughness: 0.8 }), { y: cy - 8, flies: false });

  // the pedestal: a pale lip proud of the cabinet at the front
  m.part('pedestal', surface([
    { w: 470, h: 16, r: 6, z: -360 },
    { w: 560, h: FOOT, r: 10, z: -90, s: true },
    { w: 590, h: FOOT, r: 10, z: 12, s: true },
  ], { capStart: true, capEnd: true, corner: 4 }), footMat, { y: FOOT / 2 - 1, mass: 0.7 });

  // side speakers: V series only, behind a fine grille on each flank
  const gr = grilleTexture('#050506', '#2b2b2e', 6, 6);
  gr.repeat.set(10, 26);
  const grMat = new THREE.MeshStandardMaterial({ map: gr, roughness: 0.9 });
  m.flat('speaker left', 86, 310, grMat, { x: -W / 2 - 0.4, y: cy + 10, z: -62, ry: -Math.PI / 2 });
  m.flat('speaker right', 86, 310, grMat, { x: W / 2 + 0.4, y: cy + 10, z: -62, ry: Math.PI / 2 });

  // the controls on the top, set back behind the bezel: a door of small keys and a power button
  m.part('top keys', surface([
    { w: 150, h: 40, r: 6, z: -2 },
    { w: 146, h: 36, r: 5, z: 2, s: true },
  ], { capEnd: true, corner: 4 }), plastic(0x242426, 0.45), { x: 170, y: H - 0.5, z: -56, rx: -Math.PI / 2, flies: false });
  for (let i = 0; i < 6; i++) {
    m.part('key ' + i, surface([
      { w: 16, h: 8, r: 2, z: 0 },
      { w: 15, h: 7, r: 2, z: 3, s: true },
    ], { capEnd: true, corner: 3 }), plastic(0x565658, 0.35), { x: 118 + i * 21, y: H + 1.5, z: -56, rx: -Math.PI / 2, flies: false });
  }

  // the wordmarks and the little window under the tube
  m.decal('sony', label('SONY', { font: 'bold 92px Georgia, "Times New Roman", serif', color: '#cfcfd1', spacing: 12 }), 74, 18.5, { y: FOOT + 42, z: 0.6 });
  m.decal('trinitron', label('Trinitron', { font: '74px Georgia, "Times New Roman", serif', color: '#a9a9ab', spacing: 2, italic: true }), 46, 11.5, { x: -W / 2 + 74, y: H - 22, z: 0.6 });
  const win = new THREE.MeshStandardMaterial({ color: 0x050506, roughness: 0.15, metalness: 0.2 });
  m.flat('remote window', 44, 9, win, { x: 66, y: FOOT + 42, z: 0.5 });
  const led = new THREE.MeshBasicMaterial({ color: 0xff2a1a });
  m.flat('power light', 3, 3, led, { x: 80, y: FOOT + 42, z: 0.7 });

  // the tube: a little larger than its opening, the bezel covers the rest
  const scr = glass(TUBE_W + 14, TUBE_H + 14, 16);
  const screen = m.part('picture tube', scr, new THREE.MeshBasicMaterial({ color: 0x000000 }), { y: cy + TUBE_Y, z: -44, mass: 0.5 });
  m.screen = screen;
  m.screenSize = { w: TUBE_W, h: TUBE_H, overW: TUBE_W + 14, overH: TUBE_H + 14, corner: 10 };
  m.glassGeo = scr;
  return m;
}
