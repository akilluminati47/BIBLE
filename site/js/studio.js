// tvkit's studio: look a model over from any side, spread its parts, and export it. The models themselves are text: site/tvkit/*.js.
import * as THREE from 'three';
import { RoomEnvironment } from 'three/addons/environments/RoomEnvironment.js';
import { GLTFExporter } from 'three/addons/exporters/GLTFExporter.js';
import { buildKV27V42 } from '../tvkit/kv27v42.js';
import { buildBravia } from '../tvkit/bravia.js';

const $ = (id) => document.getElementById(id);
const canvas = $('view');
const renderer = new THREE.WebGLRenderer({ canvas, antialias: true, preserveDrawingBuffer: true });
renderer.setPixelRatio(Math.min(devicePixelRatio, 2));
const scene = new THREE.Scene();
scene.background = new THREE.Color(0x10141f);
scene.environment = new THREE.PMREMGenerator(renderer).fromScene(new RoomEnvironment(renderer), 0.03).texture;
scene.add(new THREE.GridHelper(4, 40, 0x33426f, 0x1c2542));
const camera = new THREE.PerspectiveCamera(28, 1, 0.01, 50);
const builders = { crt: buildKV27V42, lcd: buildBravia };
let model = null, yaw = -0.6, pitch = 0.14, dist = 2.4, spin = true;

function load(kind) {
  if (model) scene.remove(model);
  model = builders[kind]();
  scene.add(model);
  model.screen.material = new THREE.MeshStandardMaterial({ color: 0x050608, roughness: 0.06, metalness: 0.2 });
  $('dims').textContent = `${model.name}: ${model.size.w} x ${model.size.h} x ${model.size.d} mm, ${model.parts.length} parts`;
  $('parts').innerHTML = model.parts.map((p) => `<li>${p.name}</li>`).join('');
  spread(+$('spread').value);
  wire($('wire').checked);
}

function spread(v) {
  const box = new THREE.Box3().setFromObject(model), c = box.getCenter(new THREE.Vector3()).multiplyScalar(1000);
  model.parts.forEach((p, i) => {
    const h = p.userData.home.p, d = h.clone().sub(c);
    if (d.lengthSq() < 1) d.set(Math.sin(i), Math.cos(i * 1.7), Math.sin(i * 2.3));
    p.position.copy(h).addScaledVector(d.normalize(), v * 420);
  });
}

function wire(on) { model.parts.forEach((p) => { if (p.material.wireframe !== undefined) p.material.wireframe = on; }); }

function resize() {
  renderer.setSize(innerWidth, innerHeight, false);
  camera.aspect = innerWidth / innerHeight;
  camera.fov = camera.aspect < 1 ? 42 : 28;
  camera.updateProjectionMatrix();
}
addEventListener('resize', resize);

let drag = null;
canvas.addEventListener('pointerdown', (e) => { drag = [e.clientX, e.clientY]; canvas.setPointerCapture(e.pointerId); });
canvas.addEventListener('pointermove', (e) => {
  if (!drag) return;
  yaw -= (e.clientX - drag[0]) * 0.006;
  pitch = Math.max(-0.2, Math.min(1.3, pitch + (e.clientY - drag[1]) * 0.005));
  drag = [e.clientX, e.clientY];
});
canvas.addEventListener('pointerup', () => { drag = null; });
canvas.addEventListener('wheel', (e) => { dist = Math.max(0.6, Math.min(8, dist * (1 + e.deltaY * 0.001))); e.preventDefault(); }, { passive: false });

$('model').onchange = (e) => load(e.target.value);
$('spread').oninput = (e) => spread(+e.target.value);
$('spin').onchange = (e) => { spin = e.target.checked; };
$('wire').onchange = (e) => wire(e.target.checked);

function save(blob, name) {
  const a = document.createElement('a');
  a.href = URL.createObjectURL(blob);
  a.download = name;
  a.click();
  setTimeout(() => URL.revokeObjectURL(a.href), 2000);
}
$('glb').onclick = () => new GLTFExporter().parse(model, (buf) => save(new Blob([buf], { type: 'model/gltf-binary' }), model.kind === 'crt' ? 'kv27v42.glb' : 'bravia.glb'), (e) => console.error(e), { binary: true });
$('png').onclick = () => canvas.toBlob((b) => save(b, 'tvkit.png'));

resize();
load('crt');
(function tick() {
  requestAnimationFrame(tick);
  if (spin && !drag) yaw += 0.004;
  const h = model.size.h * 0.0005;
  camera.position.set(Math.sin(yaw) * Math.cos(pitch) * dist, h + Math.sin(pitch) * dist, Math.cos(yaw) * Math.cos(pitch) * dist);
  camera.lookAt(0, h, -0.1);
  renderer.render(scene, camera);
})();
