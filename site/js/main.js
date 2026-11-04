// The page: a room, a TV, one loop of a PS2 starting up on it, and a way to blow the TV up.
import * as THREE from 'three';
import { EffectComposer } from 'three/addons/postprocessing/EffectComposer.js';
import { RenderPass } from 'three/addons/postprocessing/RenderPass.js';
import { UnrealBloomPass } from 'three/addons/postprocessing/UnrealBloomPass.js';
import { OutputPass } from 'three/addons/postprocessing/OutputPass.js';
import { RoomEnvironment } from 'three/addons/environments/RoomEnvironment.js';
import { buildKV27V42 } from '../tvkit/kv27v42.js';
import { buildBravia } from '../tvkit/bravia.js';
import { MM } from '../tvkit/kit.js';
import { load, save } from './settings.js';
import { resolveTheme, tintAt, tintMatrix, tintApply } from './themes.js';
import { buildLoop, phaseAt, FADE_S } from './timeline.js';
import { loadAssets, drawSplash, screenSize, isWide, modeLabel } from './splash.js';
import { createField, createSwoop } from './towers.js';
import { FX, Boom } from './fx.js';
import { initPanel, barInto } from './ui.js';

const $ = (id) => document.getElementById(id);
const st = load();
const reduced = matchMedia('(prefers-reduced-motion: reduce)').matches;
const coarse = matchMedia('(pointer: coarse)').matches;
const lowGuess = coarse && Math.min(screen.width, screen.height) < 700;

// ---- the renderer ----
const canvas = $('stage');
let renderer;
try {
  renderer = new THREE.WebGLRenderer({ canvas, antialias: false, powerPreference: 'high-performance' });
  if (!renderer.capabilities.isWebGL2) throw new Error('WebGL 2');
} catch {
  $('nogl').hidden = false;
  throw new Error('no WebGL');
}
renderer.toneMapping = THREE.NoToneMapping; // the sky's colours are BIBLE's own, exact
renderer.setClearColor(0x000000, 1);

const q = { level: st.quality === 'low' || (st.quality === 'auto' && lowGuess) ? 0 : 1, dpr: 1 };
const budget = q.level ? 1 : 0.45;

const scene = new THREE.Scene();
const camera = new THREE.PerspectiveCamera(26, 1, 0.05, 80);
const pmrem = new THREE.PMREMGenerator(renderer);
scene.environment = pmrem.fromScene(new RoomEnvironment(renderer), 0.04).texture;

const composer = new EffectComposer(renderer, new THREE.WebGLRenderTarget(4, 4, { type: THREE.HalfFloatType, samples: q.level ? 4 : 2 }));
composer.addPass(new RenderPass(scene, camera));
const bloom = new UnrealBloomPass(new THREE.Vector2(1, 1), 0.3, 0.5, 0.82);
composer.addPass(bloom);
composer.addPass(new OutputPass());

// ---- the room: RIPPS2's sky round it, the floor's grid under it, its towers far behind ----
const linear = (c, k = 1) => new THREE.Color().setRGB((c[0] / 255) * k, (c[1] / 255) * k, (c[2] / 255) * k, THREE.SRGBColorSpace);
const roomU = { uTop: { value: new THREE.Color() }, uMid: { value: new THREE.Color() }, uLow: { value: new THREE.Color() } };
const room = new THREE.Mesh(new THREE.SphereGeometry(40, 32, 16), new THREE.ShaderMaterial({
  side: THREE.BackSide, depthWrite: false, uniforms: roomU,
  vertexShader: 'varying vec3 vP; void main(){ vP = position; gl_Position = projectionMatrix * modelViewMatrix * vec4(position, 1.0); }',
  fragmentShader: `uniform vec3 uTop, uMid, uLow; varying vec3 vP;
    void main(){ float y = normalize(vP).y; vec3 c = y > 0.04 ? mix(uMid, uTop, smoothstep(0.04, 0.42, y)) : mix(uMid, uLow, smoothstep(0.04, -0.2, y)); gl_FragColor = vec4(c, 1.0); }`,
}));
room.renderOrder = -2;
scene.add(room);

const floorU = {
  uGlow: { value: new THREE.Color(0, 0, 0) }, uGrid: { value: new THREE.Color() }, uFar: { value: new THREE.Color() }, uBurn: { value: 0 }, uFire: { value: 0 }, uHalf: { value: new THREE.Vector2(0.4, 0.3) },
};
const floor = new THREE.Mesh(new THREE.PlaneGeometry(60, 60), new THREE.ShaderMaterial({
  uniforms: floorU,
  vertexShader: 'varying vec3 vW; void main(){ vec4 w = modelMatrix * vec4(position, 1.0); vW = w.xyz; gl_Position = projectionMatrix * viewMatrix * w; }',
  fragmentShader: `uniform vec3 uGlow, uGrid, uFar; uniform float uBurn, uFire; uniform vec2 uHalf; varying vec3 vW;
    float hash(vec2 p){ return fract(sin(dot(p, vec2(127.1, 311.7))) * 43758.5453); }
    float noise(vec2 p){ vec2 i = floor(p), f = fract(p); f = f*f*(3.0-2.0*f); return mix(mix(hash(i),hash(i+vec2(1,0)),f.x),mix(hash(i+vec2(0,1)),hash(i+vec2(1,1)),f.x),f.y); }
    void main(){
      vec2 p = vW.xz; float d = length(p);
      vec2 c = p / 0.4 + 0.5; vec2 g = abs(fract(c - 0.5) - 0.5) / fwidth(c); float line = 1.0 - min(min(g.x, g.y), 1.0);
      vec3 col = uFar * 0.34 + uGrid * line * 0.5 * exp(-d * 0.22);
      float spill = exp(-pow(max(0.0, p.y - 0.05) * 1.1, 2.0)) * exp(-pow(p.x * 1.05, 2.0)) * step(0.0, p.y + 0.02);
      col += uGlow * spill * 0.24;
      vec2 s = (abs(p - vec2(0.0, -uHalf.y * 0.55)) - uHalf * vec2(0.9, 0.62)) ;
      float contact = smoothstep(0.34, 0.0, max(s.x, s.y));
      col *= 1.0 - contact * 0.85;
      float burn = smoothstep(0.42, 0.75, noise(p * 7.0) * 0.5 + 0.5 - length(p - vec2(0.0, 0.12)) * 0.62) * uBurn;
      col = mix(col, vec3(0.002), burn * 0.9);
      col += vec3(1.5, 0.55, 0.12) * uFire * exp(-d * d * 1.9) * 0.55;
      col = mix(col, uFar * 0.5, smoothstep(2.6, 11.0, d));
      gl_FragColor = vec4(col, 1.0);
    }`,
}));
floor.rotation.x = -Math.PI / 2;
scene.add(floor);

const backdrop = createField({ grid: 11, spacing: 2.4, motes: q.level ? 90 : 0, mirror: false, floor: false, sky: false, fogDensity: 0.03 });
backdrop.group.scale.setScalar(0.34);
backdrop.group.position.set(0, -0.02, -7.4);
backdrop.setMoteScale(0.8);
scene.add(backdrop.group);
backdrop.pose(14);

const key = new THREE.DirectionalLight(0xdfe8ff, 0.9);
key.position.set(-1.4, 2.6, 2.4);
const fill = new THREE.DirectionalLight(0x8fa8ff, 0.28);
fill.position.set(2.4, 1, 1.2);
const screenLight = new THREE.PointLight(0xffffff, 0, 3.4, 1.8);
scene.add(key, fill, screenLight);

// ---- the screen: the splash canvas or the towers, through a tube or a panel ----
const sc = document.createElement('canvas');
const scCtx = sc.getContext('2d', { alpha: false });
let scTex = new THREE.CanvasTexture(sc);
const fixTex = (t) => { t.colorSpace = THREE.SRGBColorSpace; t.minFilter = t.magFilter = THREE.LinearFilter; t.generateMipmaps = false; };
fixTex(scTex);
const swoop = createSwoop(renderer, q.level ? 700 : 200);
const shared = {
  tSplash: { value: scTex }, tTowers: { value: swoop.rt.texture }, uSrc: { value: 0 }, uFade: { value: 1 },
  uTintM: { value: new THREE.Matrix3() }, uTintLift: { value: 0 },
};
function screenMaterial(model) {
  const s = model.screenSize;
  return new THREE.ShaderMaterial({
    uniforms: { ...shared, uOver: { value: new THREE.Vector2(s.w / s.overW, s.h / s.overH) }, uCrt: { value: model.kind === 'crt' ? 1 : 0 }, uLines: { value: new THREE.Vector2(640, 448) } },
    vertexShader: 'varying vec2 vUv; void main(){ vUv = uv; gl_Position = projectionMatrix * modelViewMatrix * vec4(position, 1.0); }',
    fragmentShader: `uniform sampler2D tSplash, tTowers; uniform float uSrc, uFade, uCrt, uTintLift; uniform vec2 uOver, uLines; uniform mat3 uTintM; varying vec2 vUv;
      vec3 aces(vec3 x){ return clamp((x*(2.51*x+0.03))/(x*(2.43*x+0.59)+0.14), 0.0, 1.0); }
      vec3 toS(vec3 c){ return mix(c*12.92, 1.055*pow(max(c,vec3(0.0)),vec3(1.0/2.4))-0.055, step(0.0031308,c)); }
      vec3 toL(vec3 c){ return mix(c/12.92, pow((c+0.055)/1.055,vec3(2.4)), step(0.04045,c)); }
      vec3 towers(vec2 uv){
        vec3 c = toS(aces(texture2D(tTowers, uv).rgb * 0.95));
        float mx = max(c.r,max(c.g,c.b)), mn = min(c.r,min(c.g,c.b));
        return toL(clamp(uTintM * c + uTintLift * (mx - mn), 0.0, 1.0));
      }
      vec3 pick(vec2 uv){ return uSrc > 1.5 ? towers(uv) : texture2D(tSplash, uv).rgb; }
      void main(){
        vec2 uv = (vUv - 0.5) / uOver + 0.5;
        vec3 c = vec3(0.0);
        if (uSrc > 0.5 && uv.x > 0.0 && uv.x < 1.0 && uv.y > 0.0 && uv.y < 1.0) {
          if (uCrt > 0.5) {   // a soft composite picture, a little of each neighbour across the line
            float dx = 1.1 / uLines.x;
            c = pick(uv) * 0.58 + (pick(uv + vec2(dx, 0.0)) + pick(uv - vec2(dx, 0.0))) * 0.21;
          } else c = pick(uv);
          c *= uFade;
        }
        if (uCrt > 0.5) {
          vec2 w = fwidth(uv) ;
          float sl = cos(uv.y * uLines.y * 6.2832);
          float gr = cos(uv.x * uLines.x * 3.0 * 6.2832);
          float kl = smoothstep(0.55, 0.15, w.y * uLines.y), kg = smoothstep(0.34, 0.1, w.x * uLines.x * 3.0);
          c *= (1.0 - 0.22 * kl * (0.5 + 0.5 * sl)) * (1.0 - 0.14 * kg * (0.5 + 0.5 * gr));
          vec2 e = uv * 2.0 - 1.0;
          c *= 1.0 - 0.16 * dot(e, e) * 0.5;
          c += vec3(0.006, 0.0065, 0.008);    // the tube's own grey when the signal is black
          c *= 1.28;                          // phosphor is brighter than the room
        } else {
          c = c * 1.12 + vec3(0.0035, 0.004, 0.006); // an LCD's black still glows
        }
        gl_FragColor = vec4(c, 1.0);
      }`,
  });
}

// ---- the sets ----
const models = { crt: buildKV27V42(), lcd: buildBravia() };
const glassMat = new THREE.MeshStandardMaterial({ color: 0x000000, roughness: 0.16, metalness: 0.0, envMapIntensity: 0.05, transparent: true, blending: THREE.AdditiveBlending, depthWrite: false });
for (const m of Object.values(models)) {
  m.traverse((o) => { if (o.isMesh && o.material.envMapIntensity !== undefined && o.material !== glassMat) o.material.envMapIntensity = m.kind === 'crt' ? 0.34 : 0.55; });
  m.screen.material = screenMaterial(m);
  const home = m.screen.userData.home.p;
  m.part('glass', m.glassGeo, m.kind === 'crt' ? glassMat : glassMat, { x: home.x, y: home.y, z: home.z + 1.2, flies: false });
  m.visible = false;
  m.rotation.y = 0;
  scene.add(m);
}

const tv = { kind: isWide(st) ? 'lcd' : 'crt', alive: true, respawnAt: 0, blinkUntil: 0, deadSince: 0, next: null, bounce: 0, flying: [], t: 0 };
const pick = new THREE.Mesh(new THREE.BoxGeometry(1, 1, 1), new THREE.MeshBasicMaterial());
pick.visible = false;
scene.add(pick);
const model = () => models[tv.kind];
function fitPick() {
  const s = model().size;
  pick.scale.set(s.w * MM + 0.04, s.h * MM + 0.03, s.d * MM);
  pick.position.set(0, (s.h * MM) / 2, (-s.d * MM) / 2 + 0.02);
  floorU.uHalf.value.set((s.w * MM) / 2, (s.d * MM) / 2);
}
model().visible = true;
fitPick();

const fx = new FX(scene, budget);
const boom = new Boom();
boom.on = st.sound === '1';

// ---- the loop ----
let loop = buildLoop(st), theme = resolveTheme(st), loopT = 0, paused = false, A = null, segs = [], lastSplash = -1, sceneT = 0;
const pv = $('pv'), pvCtx = pv.getContext('2d', { alpha: false });
const fmt = (s) => s.toFixed(1) + ' s';

function towersSize() {
  const { wide } = screenSize(st), hd = q.level && (st.mode === '720P' || st.mode === '1080I');
  if (hd) swoop.size(1280, 720);
  else if (wide) swoop.size(q.level ? 960 : 640, q.level ? 540 : 360);
  else swoop.size(q.level ? 800 : 512, q.level ? 600 : 384);
}

function applyTheme() {
  theme = resolveTheme(st);
  const [t, m, l] = theme.sky;
  roomU.uTop.value.copy(linear(t, 0.9));
  roomU.uMid.value.copy(linear(m, 0.42));
  roomU.uLow.value.copy(linear(l, 0.8));
  floorU.uFar.value.copy(linear(m, 0.42));
  const glow = tintApply(...theme.tint, [0x2f, 0x6b, 0xff]);
  floorU.uGrid.value.copy(linear(glow, 0.5));
  backdrop.colors.base.copy(linear(tintApply(...theme.tint, [0x0a, 0x1a, 0x52]), 0.6));
  backdrop.colors.glow.copy(linear(glow, 0.32));
  backdrop.colors.rim.copy(linear(tintApply(...theme.tint, [0x7e, 0xc2, 0xff]), 0.3));
  backdrop.colors.horizon.copy(linear(m, 0.42));
  backdrop.fogColor.copy(linear(m, 0.42));
  document.documentElement.style.setProperty('--sky', `rgb(${tintApply(...theme.tint, [0x4a, 0x8c, 0xf0]).map(Math.round).join(',')})`);
}

function applyLoop() {
  loop = buildLoop(st);
  segs = barInto($('bar'), loop);
  $('caption').textContent = `${tv.kind === 'crt' ? 'KV-27V42' : 'BRAVIA'} / ${modeLabel(st)}`;
}

function renderPreview() {
  if (!A) return;
  drawSplash(pvCtx, st, A, { sky: theme.sky, fade: 1, remaining: Math.max(0.1, loop.wait), now: new Date() });
  const l = buildLoop(st);
  $('pvtotal').textContent = fmt(l.total);
  barInto($('pvbar'), l, false);
  const best = buildLoop({ ...st, wait: '0', disc: '0' }).total;
  const parts = [`Black ${fmt(l.black)}` + (l.disc > 0.05 ? `, ${fmt(l.disc)} of it on the drive` : '')];
  parts.push(l.total > best + 0.05 ? `Shortest here: ${fmt(best)}` : 'The shortest loop there is');
  $('pvnote').textContent = parts.join('. ') + '.';
}

function drawScreen(force) {
  const { phase, into } = phaseAt(loop, loopT);
  const u = shared;
  if (phase.id === 'splash') {
    u.uSrc.value = 1;
    u.uFade.value = 1;
    const fps = q.level ? 30 : 12, step = Math.floor(sceneT * fps);
    if (force || step !== lastSplash || into > phase.d - FADE_S - 0.1) {
      lastSplash = step;
      const size = sc.width + 'x' + sc.height;
      const fade = Math.min(1, Math.max(0, (phase.d - into) / FADE_S));
      const shimmer = reduced ? null : ((sceneT * 0.28) % 1.4) / 1.4;
      drawSplash(scCtx, st, A, { sky: theme.sky, fade, remaining: Math.max(0, phase.wait - into), now: new Date(), shimmer });
      if (size !== sc.width + 'x' + sc.height) { // a new mode: a new texture its size
        scTex.dispose();
        scTex = new THREE.CanvasTexture(sc);
        fixTex(scTex);
        shared.tSplash.value = scTex;
        for (const m of Object.values(models)) m.screen.material.uniforms.tSplash.value = scTex;
      }
      scTex.needsUpdate = true;
    }
    const sky = st.logo === '0' || st.bg === 'BLANK' ? 0 : 1;
    setGlow(sky ? theme.sky[1] : [8, 8, 10], sky ? 1.5 : 0.5);
  } else if (phase.id === 'towers') {
    u.uSrc.value = 2;
    u.uFade.value = Math.min(1, into / 0.3);
    if (!paused) {
      swoop.render(into);
      const m = tintAt(theme, sceneT);
      shared.uTintM.value.fromArray(tintMatrix(m[0], m[1])).transpose();
      shared.uTintLift.value = m[2];
      setGlow(tintApply(...m, [0x2f, 0x6b, 0xff]), Math.min(1, into / 1.4) * 1.3);
    }
  } else {
    u.uSrc.value = 0;
    setGlow([0, 0, 0], 0);
  }
}

const glowC = new THREE.Color();
function setGlow(rgb, k) {
  glowC.copy(linear(rgb));
  floorU.uGlow.value.lerp(glowC.clone().multiplyScalar(k * 1.2), 0.2);
  screenLight.color.lerp(glowC, 0.2);
  const on = tv.alive ? k : 0;
  screenLight.intensity += (on * 0.3 - screenLight.intensity) * 0.2;
}

function updateHud() {
  const { phase, into } = phaseAt(loop, loopT);
  loop.phases.forEach((p, i) => {
    const f = p === phase ? into / p.d : loopT >= p.at + p.d ? 1 : 0;
    segs[i].firstChild.style.transform = `scaleX(${f.toFixed(4)})`;
  });
  const words = { power: 'BIOS to BIBLE', splash: st.logo === '0' ? 'BIBLE, nothing on screen' : 'BIBLE', black: 'The load, black', towers: 'RIPPS2 towers rising' };
  $('readout').innerHTML = `<b>${words[phase.id]}</b> &nbsp; ${loopT.toFixed(1)} of ${loop.total.toFixed(1)} s`;
}

// ---- the camera ----
const view = { first: true, yaw: -0.3, pitch: 0.07, ty: -0.3, tp: 0.07, dist: 3, target: 0.3, dragging: false, H: 1, W: 1, top: 0, bot: 0, shake: 0 };

function layout() {
  const W = innerWidth, H = innerHeight;
  q.dpr = Math.min(devicePixelRatio || 1, q.level ? 2 : 1.5);
  renderer.setPixelRatio(q.dpr);
  renderer.setSize(W, H, false);
  composer.setPixelRatio(q.dpr);
  composer.setSize(W, H);
  bloom.enabled = !!q.level;
  view.W = W;
  view.H = H;
  view.top = $('top').getBoundingClientRect().bottom;
  view.bot = H - $('hud').getBoundingClientRect().top;
  camera.aspect = W / H;
  camera.updateProjectionMatrix();
  fx.setScale((H * q.dpr) / (2 * Math.tan((camera.fov * Math.PI) / 360)));
  view.ty = W < H ? -0.16 : -0.3;
  view.first = true;
}
new ResizeObserver(layout).observe(document.documentElement);
addEventListener('orientationchange', layout);

function placeCamera(dt) {
  const s = model().size, tan = Math.tan((camera.fov * Math.PI) / 360);
  // the set fits between the bars, whichever way the screen is held, with a margin
  const availH = Math.max(120, view.H - view.top - view.bot - 16), availW = view.W - 16;
  const w = (s.w * MM) * Math.cos(view.yaw) + (s.d * MM) * Math.abs(Math.sin(view.yaw)), h = s.h * MM + 0.03;
  const want = Math.max((h / (2 * tan)) * (view.H / availH), ((w / (2 * tan * camera.aspect)) * (view.W / availW))) * 1.06 + (s.d * MM) * 0.25;
  view.dist = view.first ? want : view.dist + (want - view.dist) * Math.min(1, dt * 5);
  view.first = false;
  if (!view.dragging) { view.yaw += (view.ty - view.yaw) * Math.min(1, dt * 0.9); view.pitch += (view.tp - view.pitch) * Math.min(1, dt * 0.9); }
  const sway = reduced ? 0 : Math.sin(sceneT * 0.27) * 0.035;
  const yaw = view.yaw + sway, cy = (s.h * MM) / 2;
  camera.position.set(Math.sin(yaw) * Math.cos(view.pitch) * view.dist, cy + Math.sin(view.pitch) * view.dist, Math.cos(yaw) * Math.cos(view.pitch) * view.dist - (s.d * MM) * 0.25);
  camera.lookAt(0, cy, -(s.d * MM) * 0.25);
  if (view.shake > 0.001 && !reduced) {
    camera.position.x += Math.sin(sceneT * 61) * view.shake * 0.05;
    camera.position.y += Math.sin(sceneT * 47 + 1.3) * view.shake * 0.04;
  }
  view.shake *= Math.exp(-dt * 6);
  // the picture sits centred in the space between the bars
  camera.setViewOffset(view.W, view.H, 0, (view.bot - view.top) / 2, view.W, view.H);
}

// ---- boom ----
let count = 0;
try { count = +localStorage.getItem('bible-site-blown') || 0; } catch { /* not kept */ }
$('count').textContent = count;
let lastFlash = 0, flashAnim = null;

// Never more than three full-screen flashes a second, however fast the clicks come
function flash(strength) {
  const now = performance.now();
  if (now - lastFlash < 340) return;
  lastFlash = now;
  const soft = st.flash === 'soft' || reduced;
  flashAnim?.cancel();
  flashAnim = $('flash').animate(soft ? [{ opacity: 0.12 }, { opacity: 0 }] : [{ opacity: 0.75 * strength }, { opacity: 0 }], { duration: soft ? 260 : 170, easing: 'ease-out' });
}

const colorsOf = (kind) => (kind === 'crt' ? ['#3b3b3e', '#2a2a2c', '#5e5e60', '#141417', '#8fb4c8'] : ['#08080a', '#1a1a1c', '#9d9fa3', '#050506', '#2a3040']);

function blow(point, { power = 1, next = null } = {}) {
  boom.unlock();
  const s = model().size, c = new THREE.Vector3(0, (s.h * MM) / 2, -0.12);
  const p = point || c;
  fx.burst(p, power);
  boom.play(power);
  view.shake = Math.min(1.4, view.shake + 0.55 * power);
  floorU.uFire.value = Math.min(1.6, floorU.uFire.value + 0.6 * power);
  floorU.uBurn.value = Math.min(1, floorU.uBurn.value + 0.16);
  bloomKick = Math.min(0.45, bloomKick + 0.16);
  if (next) tv.next = next;
  count++;
  $('count').textContent = count;
  try { localStorage.setItem('bible-site-blown', count); } catch { /* not kept */ }
  $('hint').classList.add('gone');
  const now = performance.now();
  if (tv.alive) {
    tv.alive = false;
    tv.deadSince = now;
    tv.respawnAt = now + (next ? 1250 : 1000);
    const m = model();
    fx.burst(c, 1.5, { x: (s.w * MM) * 0.75, y: (s.h * MM) * 0.75 });
    fx.wreck(c, new THREE.Vector3(s.w * MM, s.h * MM, s.d * MM), colorsOf(tv.kind));
    flash(1);
    tv.flying = [];
    for (const part of m.parts) {
      if (!part.userData.flies || part === m.screen) { part.visible = false; continue; }
      const dir = part.position.clone();
      dir.y -= s.h / 2;
      dir.z += 120;
      if (dir.lengthSq() < 1) dir.set(0, 1, 0);
      dir.normalize();
      const sp = (700 + Math.random() * 900) / part.userData.mass;
      tv.flying.push({ part, v: new THREE.Vector3(dir.x * sp + (Math.random() - 0.5) * 1100, Math.abs(dir.y) * sp + 1000 + Math.random() * 1000, Math.min(300, dir.z * sp * 0.4) + Math.random() * 180), w: new THREE.Vector3(Math.random() * 7 - 3.5, Math.random() * 7 - 3.5, Math.random() * 7 - 3.5), burn: 0 });
    }
  } else {
    // spamming the wreck: it stays down a little longer, within reason
    tv.respawnAt = Math.min(tv.deadSince + 2600, Math.max(tv.respawnAt, now + 650));
    flash(0.55);
  }
}

let bloomKick = 0, readyTimer = 0;

function respawn() {
  const was = tv.kind, wantKind = tv.next || tv.kind;
  models[was].visible = false;
  tv.kind = wantKind;
  tv.next = null;
  tv.alive = true;
  const m = model();
  m.home();
  m.visible = true;
  fitPick();
  fx.clearShards();
  tv.blinkUntil = performance.now() + 1150;
  tv.bounce = 1;
  flash(1);
  boom.blip();
  applyLoop();
  const r = $('ready');
  r.textContent = wantKind !== was ? (wantKind === 'lcd' ? '16:9 READY' : '4:3 READY') : 'READY';
  r.classList.remove('on');
  void r.offsetWidth;
  r.classList.add('on');
  clearTimeout(readyTimer);
  readyTimer = setTimeout(() => r.classList.remove('on'), 1400);
  fx.burst(new THREE.Vector3(0, 0.02, 0.02), 0.28, { x: (m.size.w * MM), y: 0.02 });
}

function updateTV(dt) {
  const now = performance.now(), m = model();
  if (!tv.alive) {
    for (const f of tv.flying) {
      f.v.y -= 5400 * dt;
      f.part.position.addScaledVector(f.v, dt);
      f.part.rotation.x += f.w.x * dt;
      f.part.rotation.y += f.w.y * dt;
      f.part.rotation.z += f.w.z * dt;
      if (f.part.position.y < 30) { f.part.position.y = 30; f.v.y *= -0.34; f.v.x *= 0.7; f.v.z *= 0.7; f.w.multiplyScalar(0.55); }
    }
    if (now >= tv.respawnAt) respawn();
  } else if (now < tv.blinkUntil) {
    m.visible = reduced || Math.floor(now / 70) % 2 === 0;
  } else {
    m.visible = true;
  }
  tv.bounce *= Math.exp(-dt * 7);
  const k = tv.bounce;
  m.position.y = tv.alive ? Math.abs(Math.sin(k * 7)) * 0.05 * k : 0;
  m.scale.setScalar(1 - 0.07 * k);
  floorU.uFire.value *= Math.exp(-dt * 2.2);
  floorU.uBurn.value *= Math.exp(-dt * 0.06);
  bloomKick *= Math.exp(-dt * 5);
  bloom.strength = 0.3 + bloomKick;
}

// ---- the pointer: a press that does not move is a shot, a drag turns the room ----
const ray = new THREE.Raycaster();
const ndc = new THREE.Vector2();
function hit(e) {
  const r = canvas.getBoundingClientRect();
  ndc.set(((e.clientX - r.left) / r.width) * 2 - 1, -((e.clientY - r.top) / r.height) * 2 + 1);
  ray.setFromCamera(ndc, camera);
  return ray.intersectObject(pick, false)[0] || null;
}
let down = null;
canvas.addEventListener('pointerdown', (e) => {
  boom.unlock();
  down = { x: e.clientX, y: e.clientY, sx: e.clientX, sy: e.clientY, moved: false };
  canvas.setPointerCapture(e.pointerId);
});
canvas.addEventListener('pointermove', (e) => {
  if (down) {
    const dx = e.clientX - down.x, dy = e.clientY - down.y;
    if (Math.hypot(e.clientX - down.sx, e.clientY - down.sy) > 9) { down.moved = true; view.dragging = true; }
    if (down.moved) {
      view.yaw = Math.max(-1.25, Math.min(1.25, view.yaw - dx * 0.0052));
      view.pitch = Math.max(-0.02, Math.min(0.5, view.pitch + dy * 0.003));
    }
    down.x = e.clientX;
    down.y = e.clientY;
  } else canvas.classList.toggle('aim', !!hit(e));
});
canvas.addEventListener('pointerup', (e) => {
  if (down && !down.moved) {
    const h = hit(e);
    if (h) blow(h.point.clone().setZ(Math.max(h.point.z, -0.1)));
  }
  down = null;
  view.dragging = false;
});
canvas.addEventListener('pointercancel', () => { down = null; view.dragging = false; });
$('boom').onclick = () => blow(new THREE.Vector3((Math.random() - 0.5) * 0.3, (model().size.h * MM) * (0.35 + Math.random() * 0.4), 0.02));
addEventListener('keydown', (e) => {
  if ((e.key === 'b' || e.key === 'B') && !document.body.classList.contains('open')) $('boom').click();
});
const setMute = () => {
  const on = st.sound === '1';
  $('mute').setAttribute('aria-pressed', on);
  document.getElementById('waves').toggleAttribute('hidden', !on);
  document.getElementById('cross').toggleAttribute('hidden', on);
  boom.on = on;
};
$('mute').onclick = () => { st.sound = st.sound === '1' ? '0' : '1'; boom.unlock(); setMute(); save(st); panelApi?.mark('sound'); };

// ---- the panel ----
let panelApi = null;
panelApi = initPanel({
  st,
  onChange(id) {
    save(st);
    if (id === 'sound') setMute();
    applyTheme();
    renderPreview();
  },
  onOpen() { paused = true; renderPreview(); },
  onClose() {
    paused = false;
    applyTheme();
    const want = isWide(st) ? 'lcd' : 'crt';
    towersSize();
    loopT = 0;
    lastSplash = -1;
    if (want !== tv.kind && tv.alive) setTimeout(() => blow(null, { power: 2, next: want }), 380); // through the glass, then the set goes up
    else if (want !== tv.kind) tv.next = want;
    else if (tv.next && tv.next !== want) tv.next = want;
    applyLoop();
  },
});

// ---- go ----
applyTheme();
applyLoop();
setMute();
towersSize();
layout();
$('hint').textContent = coarse ? 'Tap the TV. Drag to look around.' : 'Click the TV. Drag to look around.';

loadAssets().then((a) => {
  A = a;
  drawScreen(true);
  renderPreview();
  swoop.render(0.01); // its shaders built now, not at the first towers
  const hidden = [models.crt, models.lcd, fx.shards].filter((o) => !o.visible);
  hidden.forEach((o) => { o.visible = true; });
  placeCamera(0.016);
  renderer.compile(scene, camera);
  hidden.forEach((o) => { o.visible = false; });
  requestAnimationFrame(frame);
});

let lastT = performance.now(), slow = 0, slowN = 0, frames = 0;
function frame(now) {
  requestAnimationFrame(frame);
  if (++frames === 4) { $('veil').classList.add('gone'); setTimeout(() => $('veil').remove(), 700); slow = 0; slowN = 0; }
  const dt = Math.min(0.05, (now - lastT) / 1000);
  lastT = now;
  sceneT += dt;
  if (!paused) {
    loopT += dt;
    if (loopT >= loop.total) { loopT -= loop.total; lastSplash = -1; }
  }
  drawScreen(false);
  updateHud();
  updateTV(dt);
  fx.update(dt);
  placeCamera(dt);
  const s = model().screen.parent, h = model().screen.position;
  screenLight.position.set(0, h.y * s.scale.y, 0.7);
  if (q.level && !reduced && !paused && Math.floor(sceneT * 12) !== Math.floor((sceneT - dt) * 12)) backdrop.pose(14 + sceneT * 0.5);
  composer.render(dt);

  // a device that cannot keep up gives up the extras
  slow += dt; slowN++;
  if (slowN >= 80) {
    if (st.quality === 'auto' && q.level && slow / slowN > 1 / 38) {
      q.level = 0;
      layout();
      towersSize();
    }
    slow = 0; slowN = 0;
  }
}
window.__bible = { st, blow, models, tv, get loopT() { return loopT; }, set loopT(v) { loopT = v; }, get loop() { return loop; }, view };
