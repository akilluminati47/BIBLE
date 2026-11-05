"""RIPPS2's icon viewer on the PC: the same maths as ripps2ViewSaveIcon (src/ripps2media.c), so a model can be judged
before a lab run. No z-buffer, no culling: triangles are sorted far first by the sum of their three depths, exactly as
the viewer does. The same frame is also drawn with a z-buffer, which is what the model means, and the two are compared.

    python painter.py bible.icn icon.sys out.png            a sheet of viewer frames, painter over z-buffer
    python painter.py bible.icn icon.sys --score            the mismatch only
"""
import struct
import sys

import numpy as np
from PIL import Image

SIZE = 220


def load(path):
    d = open(path, 'rb').read()
    magic, shapes, textype, _, verts = struct.unpack_from('<IIIfI', d, 0)
    assert magic == 0x00010000 and shapes == 1 and verts % 3 == 0, (magic, shapes, verts)
    off = 20
    pos, uv, rgba = [], [], []
    for _ in range(verts):
        x, y, z, _w = struct.unpack_from('<hhhh', d, off)
        u, v = struct.unpack_from('<hh', d, off + 16)
        pos.append((x, y, z))
        uv.append((u / 32.0, v / 32.0))
        rgba.append(d[off + 20:off + 24])
        off += 24
    tag = struct.unpack_from('<I', d, off)[0]
    assert tag == 1
    frames = struct.unpack_from('<I', d, off + 16)[0]
    off += 20
    for _ in range(frames):
        count = struct.unpack_from('<I', d, off + 4)[0]
        off += 8 + 8 * count
    assert textype & 12 == 12
    packed = struct.unpack_from('<I', d, off)[0]
    off += 4
    end = off + packed
    px = []
    while off < end:
        code = struct.unpack_from('<H', d, off)[0]
        off += 2
        if code & 0x8000:
            n = 0x10000 - code
            px += list(struct.unpack_from('<%dH' % n, d, off))
            off += 2 * n
        else:
            px += [struct.unpack_from('<H', d, off)[0]] * code
            off += 2
    assert len(px) == 128 * 128, len(px)
    px = np.array(px, np.uint32).reshape(128, 128)
    # the GS expands a 5-bit channel by shifting it up
    tex = np.stack([(px & 31) << 3, ((px >> 5) & 31) << 3, ((px >> 10) & 31) << 3], -1).astype(np.float32)
    col = np.array([list(c[:3]) for c in rgba], np.float32)
    return np.array(pos, np.float32), np.array(uv, np.float32), col, tex, len(d)


def background(sys_path):
    s = open(sys_path, 'rb').read()
    c = [np.array([s[0x10 + 16 * i], s[0x14 + 16 * i], s[0x18 + 16 * i]], np.float32) / 2 for i in range(4)]
    h = np.linspace(0, 1, SIZE)[:, None, None]
    return (c[0][None, None] * (1 - h) + c[2][None, None] * h) * np.ones((SIZE, SIZE, 3), np.float32) * 2  # GS 0x80 = full


def project(pos, yaw, pitch):
    lo, hi = pos.min(0), pos.max(0)
    pivot = (lo + hi) * 0.5
    p = pos - pivot
    radius = np.sqrt((p ** 2).sum(1)).max()
    scale = (SIZE * 0.48) / radius
    cy, sy, cp, sp = np.cos(yaw), np.sin(yaw), np.cos(pitch), np.sin(pitch)
    x1 = p[:, 0] * cy + p[:, 2] * sy
    z1 = p[:, 2] * cy - p[:, 0] * sy
    sx = SIZE / 2 + x1 * scale
    sy_ = SIZE / 2 + (p[:, 1] * cp - z1 * sp) * scale
    z = p[:, 1] * sp + z1 * cp
    return sx, sy_, z


def draw(model, bg, yaw, pitch, zbuffer):
    pos, uv, col, tex, _ = model
    img = bg.copy()
    sx, sy, z = project(pos, yaw, pitch)
    tris = len(pos) // 3
    idx = np.arange(tris)
    if not zbuffer:
        depth = z[0::3] + z[1::3] + z[2::3]
        idx = idx[np.argsort(-depth, kind='stable')]  # far first; +z is into the screen
    zb = np.full((SIZE, SIZE), 1e18, np.float64)
    mask = np.zeros((SIZE, SIZE), bool)
    for t in idx:
        a = t * 3
        x0, x1, x2 = sx[a], sx[a + 1], sx[a + 2]
        y0, y1, y2 = sy[a], sy[a + 1], sy[a + 2]
        area = (x1 - x0) * (y2 - y0) - (x2 - x0) * (y1 - y0)
        if abs(area) < 1e-6:
            continue
        xa, xb = int(max(0, np.floor(min(x0, x1, x2)))), int(min(SIZE - 1, np.ceil(max(x0, x1, x2))))
        ya, yb = int(max(0, np.floor(min(y0, y1, y2)))), int(min(SIZE - 1, np.ceil(max(y0, y1, y2))))
        if xb < xa or yb < ya:
            continue
        gx, gy = np.meshgrid(np.arange(xa, xb + 1) + 0.5, np.arange(ya, yb + 1) + 0.5)
        w1 = ((gx - x0) * (y2 - y0) - (x2 - x0) * (gy - y0)) / area
        w2 = ((x1 - x0) * (gy - y0) - (gx - x0) * (y1 - y0)) / area
        w0 = 1 - w1 - w2
        hit = (w0 >= 0) & (w1 >= 0) & (w2 >= 0)
        if not hit.any():
            continue
        ys, xs = np.nonzero(hit)
        ys_, xs_ = ys + ya, xs + xa
        b0, b1, b2 = w0[ys, xs], w1[ys, xs], w2[ys, xs]
        if zbuffer:
            d = b0 * z[a] + b1 * z[a + 1] + b2 * z[a + 2]
            near = d < zb[ys_, xs_]
            ys_, xs_, b0, b1, b2, d = ys_[near], xs_[near], b0[near], b1[near], b2[near], d[near]
            zb[ys_, xs_] = d
        u = b0 * uv[a, 0] + b1 * uv[a + 1, 0] + b2 * uv[a + 2, 0]
        v = b0 * uv[a, 1] + b1 * uv[a + 1, 1] + b2 * uv[a + 2, 1]
        texel = tex[np.clip(v.astype(int), 0, 127), np.clip(u.astype(int), 0, 127)]
        shade = (b0[:, None] * col[a] + b1[:, None] * col[a + 1] + b2[:, None] * col[a + 2]) / 128.0
        img[ys_, xs_] = np.minimum(texel * shade, 255)
        mask[ys_, xs_] = True
    return img, mask


ANGLES = [(np.radians(y), p) for p in (0.0, 0.45, -0.45, 1.0, -1.0) for y in range(0, 360, 15)]


def score(model, bg):
    """Share of the icon's pixels the viewer gets wrong, by pitch, and the worst single frame."""
    per, worst = {}, (0.0, None)
    for yaw, pitch in ANGLES:
        a, m = draw(model, bg, yaw, pitch, False)
        b, _ = draw(model, bg, yaw, pitch, True)
        bad = (np.abs(a - b).max(-1) > 30) & m
        share = bad.sum() / max(1, m.sum())
        per.setdefault(pitch, []).append(share)
        if share > worst[0]:
            worst = (share, (round(float(np.degrees(yaw))), pitch))
    return {k: round(float(np.mean(v)) * 100, 2) for k, v in per.items()}, round(worst[0] * 100, 2), worst[1]


if __name__ == '__main__':
    model = load(sys.argv[1])
    bg = background(sys.argv[2])
    print('%d triangles, %d bytes' % (len(model[0]) // 3, model[4]))
    mean, worst, where = score(model, bg)
    print('wrong pixels, mean by pitch (%):', mean, '| worst frame %.2f%% at (yaw, pitch) %s' % (worst, where))
    if len(sys.argv) > 3 and sys.argv[3] != '--score':
        yaws = [0, 30, 60, 90, 135, 180, 225, 270, 300, 330]
        rows = []
        for pitch in (0.0, 0.45):
            rows.append(np.concatenate([draw(model, bg, np.radians(y), pitch, False)[0] for y in yaws], 1))
        rows.append(np.concatenate([draw(model, bg, np.radians(y), 0.0, True)[0] for y in yaws], 1))
        Image.fromarray(np.concatenate(rows, 0).astype(np.uint8)).save(sys.argv[3])
