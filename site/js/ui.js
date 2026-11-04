// The glass panel: RIPPS2's rows, each a label and its choices, nothing hidden behind a second tap. While it is open the loop waits; closing it plays the result.
import { SCHEMA, iniText, swatchThemes, DEFAULTS } from './settings.js';
import { THEMES, swatch } from './themes.js';

const $ = (id) => document.getElementById(id);
const rgb = (c) => `rgb(${c[0]},${c[1]},${c[2]})`;

export function initPanel({ st, onChange, onOpen, onClose }) {
  const rows = $('rows');

  function radio(el, value, group) {
    el.setAttribute('role', 'radio');
    el.dataset.v = value;
    el.type = 'button';
    el.onclick = () => set(group, value, el);
    el.onkeydown = (e) => {
      const d = { ArrowRight: 1, ArrowDown: 1, ArrowLeft: -1, ArrowUp: -1 }[e.key];
      if (!d) return;
      e.preventDefault();
      const all = [...el.parentElement.children], next = all[(all.indexOf(el) + d + all.length) % all.length];
      next.focus();
      next.click();
    };
  }

  function mark(id) {
    document.querySelectorAll(`[data-group="${id}"] [role=radio]`).forEach((o) => {
      const on = o.dataset.v === st[id];
      o.setAttribute('aria-checked', on);
      o.tabIndex = on ? 0 : -1;
    });
    const sets = rows.querySelectorAll('.set[data-show]');
    sets.forEach((s) => s.classList.toggle('dim', !find(s.dataset.show).showIf(st)));
    const cust = $('customrow');
    if (cust) cust.hidden = st.theme !== 'Custom' || st.sweep !== 'Off';
  }

  const find = (id) => SCHEMA.flatMap((g) => g.rows).find((r) => r.id === id);

  function set(id, value) {
    st[id] = value;
    mark(id);
    if (id === 'sweep' && value !== 'Off') mark('theme');
    onChange(id);
    refresh();
  }

  function refresh() { $('ini').textContent = iniText(st); }

  for (const g of SCHEMA) {
    const sec = document.createElement('section');
    sec.className = 'group';
    sec.innerHTML = `<h3>${g.title}</h3>` + (g.note ? `<p class="note">${g.note}</p>` : '');
    for (const r of g.rows) {
      const div = document.createElement('div');
      div.className = 'set';
      if (r.showIf) div.dataset.show = r.id;
      const nameId = 'n-' + r.id;
      div.innerHTML = `<div class="name" id="${nameId}">${r.label}</div>`;
      const box = document.createElement('div');
      box.setAttribute('role', 'radiogroup');
      box.setAttribute('aria-labelledby', nameId);
      box.dataset.group = r.id;
      if (r.type === 'theme') {
        box.className = 'swatches';
        for (const name of swatchThemes) {
          const b = document.createElement('button');
          b.className = 'swatch';
          const t = THEMES.find((x) => x[0] === name), c = t ? rgb(swatch(t[1], t[2], t[3])) : st.custom;
          b.innerHTML = `<i style="--s:${c}"></i>${name}`;
          radio(b, name, r.id);
          box.append(b);
        }
      } else {
        box.className = 'opts';
        for (const [v, text] of r.opts) {
          const b = document.createElement('button');
          b.className = 'opt';
          b.textContent = text;
          radio(b, v, r.id);
          box.append(b);
        }
      }
      div.append(box);
      if (r.type === 'theme') {
        const c = document.createElement('label');
        c.className = 'custom';
        c.id = 'customrow';
        c.innerHTML = `Custom colour <input type="color" id="customcolor" value="${st.custom}">`;
        div.append(c);
      }
      if (r.hint) {
        const h = document.createElement('p');
        h.className = 'hint';
        h.textContent = r.hint;
        div.append(h);
      }
      sec.append(div);
    }
    rows.append(sec);
  }
  $('customcolor').oninput = (e) => {
    st.custom = e.target.value;
    document.querySelector('[data-group="theme"] [data-v="Custom"] i').style.setProperty('--s', st.custom);
    onChange('custom');
    refresh();
  };
  for (const r of SCHEMA.flatMap((g) => g.rows)) mark(r.id);
  refresh();

  $('copy').onclick = async () => {
    const b = $('copy');
    try { await navigator.clipboard.writeText($('ini').textContent); b.textContent = 'Copied'; } catch { b.textContent = 'Select it above to copy'; }
    setTimeout(() => { b.textContent = 'Copy'; }, 1600);
  };

  $('reset').onclick = () => {
    Object.assign(st, DEFAULTS);
    $('customcolor').value = st.custom;
    for (const r of SCHEMA.flatMap((g) => g.rows)) mark(r.id);
    onChange('reset');
    refresh();
  };

  // open and close
  const panel = $('panel'), hudBits = [$('hud'), $('top')];
  let last = null, isOpen = false;
  function open() {
    if (isOpen) return;
    isOpen = true;
    last = document.activeElement;
    document.body.classList.add('show');
    void panel.offsetWidth; // shown at its start, so the slide runs
    document.body.classList.add('open');
    panel.inert = false;
    hudBits.forEach((h) => { h.inert = true; });
    $('close').focus();
    onOpen();
  }
  function close() {
    if (!isOpen) return;
    isOpen = false;
    document.body.classList.remove('open');
    setTimeout(() => { if (!isOpen) document.body.classList.remove('show'); }, 400);
    panel.inert = true;
    hudBits.forEach((h) => { h.inert = false; });
    last?.focus?.();
    onClose();
  }
  $('open').onclick = open;
  $('close').onclick = close;
  $('scrim').onclick = close;
  addEventListener('keydown', (e) => { if (e.key === 'Escape') close(); });
  panel.addEventListener('keydown', (e) => { // the focus stays in the panel
    if (e.key !== 'Tab') return;
    const f = [...panel.querySelectorAll('button:not([tabindex="-1"]), a, input, pre')].filter((x) => x.offsetParent !== null);
    const a = f[0], z = f[f.length - 1];
    if (e.shiftKey && document.activeElement === a) { e.preventDefault(); z.focus(); }
    else if (!e.shiftKey && document.activeElement === z) { e.preventDefault(); a.focus(); }
  });
  return { isOpen: () => isOpen, mark, defaults: DEFAULTS };
}

export function barInto(el, loop, labels = true) {
  el.innerHTML = '';
  return loop.phases.map((p) => {
    const s = document.createElement('div');
    s.className = 'seg ' + p.id;
    s.style.flex = `${Math.max(p.d, 0.2)} 1 0`;
    s.innerHTML = '<i></i>' + (labels ? `<span>${p.label}</span><em>${p.d.toFixed(1)}</em>` : '');
    el.append(s);
    return s;
  });
}
