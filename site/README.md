# BIBLE's website

**[akilluminati47.github.io/BIBLE](https://akilluminati47.github.io/BIBLE/)**: BIBLE's splash on a Sony KV-27V42, every setting from RIPPS2's Manage plus its Color Themes, one loop from power on to the towers, and a TV you can blow up. Pick 16:9 and the Trinitron does not survive.

It is a plain static site: no build step, no trackers, no accounts, nothing from another server. Settings stay in your browser.

## The toolset: models without Blender

The TVs are text. `tvkit/` is a small modelling kit that builds them from code in real millimetres:

| File | What it is |
|---|---|
| `tvkit/kit.js` | The kit: `surface()` skins a shape through rounded rectangles, `glass()` makes a Trinitron's face, plus labels, grilles, vents, and named parts |
| `tvkit/kv27v42.js` | The Sony KV-27V42, 692 x 578 x 505 mm, from Sony's manual and photographs |
| `tvkit/bravia.js` | A BRAVIA of the KDL-32V2500's era, 792 x 593 x 219 mm |
| `studio.html` | The model studio: turn a model, spread its parts, wireframe, save a picture, and **export a .glb** that Blender opens |

Change a number in a model and reload. To try it on your PC:

```bash
python tools/site/serve.py
```

Then open http://localhost:8333/ or http://localhost:8333/studio.html.

## What is real on the screen

- **The splash** (`js/splash.js`) follows `src/splash_render.c` and `src/splash_screen.c`: BIBLE's own logo, button sheet and 5x7 font, its positions, and its pixels at each video mode.
- **The sky and themes** (`js/themes.js`) are ported from RIPPS2's `src/ripps2ui.c`.
- **The towers** (`js/towers.js`) are the RIPPS2 site's scene, with the boot swoop's camera, and stop at 3.2 s (`INTRO_UI_S`), where a legacy theme takes over.
- **The timings** (`js/timeline.js`) list where each number came from. Black time is measured from PCSX2 frames; the console figure is an estimate from a real DIAG.TXT, and the page says so.

`tools/site/gen_site.py` regenerates the font, the shaders and the assets from those sources. There is no Sony audio here: the explosions are synthesised.

Unofficial fan project. Both TVs are fan-made from published sizes and photographs. Sony, Trinitron, BRAVIA, PlayStation and PS2 are trademarks of Sony Group Corporation or its affiliates.
