// A BRAVIA of the PS2's last years, after the KDL-32V2500 (2006): a 32 inch 16:9 panel in a black frame with a silver speaker bar under it, on a
// swivel stand. Sizes in millimetres from Sony's manual: 792 wide, 546 high and 99 deep without the stand, 593 high and 219 deep with it.
// The details of the trim are an approximation of that era's look, fan-made, not from any manufacturer's data.
import * as THREE from 'three';
import { Model, surface, glass, label, grilleTexture, grainTexture, plastic } from './kit.js';

const W = 792, HP = 546, DP = 99, TOTAL = 593;
const SCREEN_W = 708, SCREEN_H = 398;
const LIFT = TOTAL - HP;        // the panel's bottom above the desk
const SCREEN_Y = 46;            // the screen sits high: the speaker bar is under it

export function buildBravia() {
  const m = new Model('Sony BRAVIA (KDL-32V2500 era)');
  m.size = { w: W, h: TOTAL, d: 219 };
  m.kind = 'lcd';
  const grain = grainTexture();
  grain.repeat.set(6, 6);
  const frame = plastic(0x08080a, 0.16, { metalness: 0.1 });
  const back = plastic(0x1a1a1c, 0.6, { roughnessMap: grain });
  const silver = plastic(0x9d9fa3, 0.34, { metalness: 0.75 });
  const cy = LIFT + HP / 2;

  m.part('frame', surface([
    { w: W - 40, h: HP - 40, r: 18, z: -DP + 40 },
    { w: W, h: HP, r: 14, z: -36 },
    { w: W, h: HP, r: 14, z: -6, s: true },
    { w: W - 4, h: HP - 4, r: 12, z: 0, s: true },
    { w: SCREEN_W + 16, h: SCREEN_H + 16, r: 3, z: 0, y: SCREEN_Y },
    { w: SCREEN_W + 2, h: SCREEN_H + 2, r: 2, z: -5, y: SCREEN_Y },
    { w: SCREEN_W - 4, h: SCREEN_H - 4, r: 2, z: -12, y: SCREEN_Y },
  ], { corner: 6 }), frame, { y: cy, mass: 1.1 });

  m.part('back cover', surface([
    { w: 520, h: 340, r: 26, z: -DP },
    { w: W - 40, h: HP - 40, r: 20, z: -DP + 40, s: true },
    { w: W - 2, h: HP - 2, r: 14, z: -37, s: true },
  ], { capStart: true, corner: 6 }), back, { y: cy, mass: 1.2 });

  // the speaker bar: brushed silver across the foot of the frame, a fine grille let into it
  const barH = 62, barY = LIFT + 8 + barH / 2;
  m.part('speaker bar', surface([
    { w: W - 26, h: barH, r: 6, z: -1 },
    { w: W - 30, h: barH - 4, r: 5, z: 2, s: true },
  ], { capEnd: true, corner: 4 }), silver, { y: barY, z: 0, mass: 0.5 });
  const gr = grilleTexture('#0a0a0b', '#a2a4a8', 6, 3);
  gr.repeat.set(60, 3);
  const grMat = new THREE.MeshStandardMaterial({ map: gr, roughness: 0.5, metalness: 0.4 });
  m.flat('grille left', 300, 26, grMat, { x: -215, y: barY, z: 2.4 });
  m.flat('grille right', 300, 26, grMat, { x: 215, y: barY, z: 2.4 });

  m.decal('sony', label('SONY', { font: 'bold 92px Georgia, "Times New Roman", serif', color: '#1a1a1d', spacing: 12 }), 72, 18, { y: barY, z: 2.5 });
  m.decal('bravia', label('BRAVIA', { font: '600 70px "Helvetica Neue", Arial, sans-serif', color: '#c9cace', spacing: 14 }), 58, 14.5, { x: W / 2 - 66, y: SCREEN_Y + cy - SCREEN_H / 2 - 16, z: 0.6 });
  const led = new THREE.MeshBasicMaterial({ color: 0x35d06a });
  m.flat('power light', 4, 2.4, led, { x: W / 2 - 22, y: barY, z: 2.5 });

  // the swivel stand: a neck in silver, a low oval foot in black
  m.part('stand neck', surface([
    { w: 150, h: 40, r: 10, z: -22 },
    { w: 130, h: 34, r: 10, z: 22, s: true },
  ], { capStart: true, capEnd: true, corner: 4 }), silver, { y: LIFT - 12, z: -44, mass: 0.6 });
  m.part('stand foot', surface([
    { w: 300, h: 150, r: 74, z: -7 },
    { w: 410, h: 216, r: 100, z: 2, s: true },
    { w: 400, h: 208, r: 96, z: 9, s: true },
  ], { capEnd: true, corner: 10 }), plastic(0x121214, 0.2, { metalness: 0.3 }), { y: 9, z: -44, rx: -Math.PI / 2, mass: 0.8 });

  const scr = glass(SCREEN_W + 4, SCREEN_H + 4, 0, 2);
  const screen = m.part('panel', scr, new THREE.MeshBasicMaterial({ color: 0x000000 }), { y: cy + SCREEN_Y, z: -10, mass: 0.5 });
  m.screen = screen;
  m.screenSize = { w: SCREEN_W, h: SCREEN_H, overW: SCREEN_W + 4, overH: SCREEN_H + 4, corner: 2 };
  m.glassGeo = scr;
  return m;
}
