"""Reads a PS2 .icn back on its own (a second reader for what make_bible_icon.py writes, so a slip in either shows) and
draws it turned to a few angles, with the texture and plain lighting.

    python preview_icn.py FILE.icn OUT.png [--tex tex.png] [--yaw -40,0,40,75] [--size 420]
"""
import math
import struct
import sys

import numpy as np
from PIL import Image


def read_icn(path):
    d = open(path, 'rb').read()
    magic, shapes, ttype, one, nv = struct.unpack_from('<IIIfI', d, 0)
    assert magic == 0x00010000 and abs(one - 1.0) < 1e-6, 'bad header'
    assert nv % 3 == 0, 'vertices are not triangles'
    o = 20
    pos, nrm, uvs, col = [], [], [], []
    for _ in range(nv):
        p = [struct.unpack_from('<hhhh', d, o + 8 * s) for s in range(shapes)]
        o += 8 * shapes
        n = struct.unpack_from('<hhhh', d, o)
        o += 8
        uv = struct.unpack_from('<hh', d, o)
        o += 4
        col.append(d[o:o + 4])
        o += 4
        pos.append([v / 4096 for v in p[0][:3]])
        nrm.append([v / 4096 for v in n[:3]])
        uvs.append(uv)
    tag, frame_len, speed, offs, nframes = struct.unpack_from('<IIfII', d, o)
    o += 20
    for _ in range(nframes):
        shape, keys = struct.unpack_from('<II', d, o)
        o += 8 + 8 * keys
    assert ttype == 0x0E, 'expected an RLE texture'
    packed = struct.unpack_from('<I', d, o)[0]
    o += 4
    assert o + packed == len(d), 'texture length %d leaves %d bytes' % (packed, len(d) - o)
    end, px = o + packed, []
    while o < end:
        c = struct.unpack_from('<H', d, o)[0]
        o += 2
        if c & 0x8000:
            n = 0x10000 - c
            px.extend(struct.unpack_from('<%dH' % n, d, o))
            o += 2 * n
        else:
            px.extend([struct.unpack_from('<H', d, o)[0]] * c)
            o += 2
    assert len(px) == 128 * 128, 'texture has %d pixels' % len(px)
    a = np.array(px, np.uint32)
    tex = np.stack([(a & 31) * 255 // 31, ((a >> 5) & 31) * 255 // 31, ((a >> 10) & 31) * 255 // 31], 1).reshape(128, 128, 3).astype(np.float32)
    return np.array(pos), np.array(nrm), np.array(uvs, float) / 32, tex, shapes, len(d)


def draw(pos, nrm, uv, tex, yaw, size):
    a = math.radians(yaw)
    c, s = math.cos(a), math.sin(a)
    px, pz = pos[:, 0] * c + pos[:, 2] * s, -pos[:, 0] * s + pos[:, 2] * c
    nx, nz = nrm[:, 0] * c + nrm[:, 2] * s, -nrm[:, 0] * s + nrm[:, 2] * c
    light = np.array([-0.35, -0.5, -0.8])  # from up, left and the viewer (icon space: +y down, +z in)
    light /= np.linalg.norm(light)
    shade = 0.45 + 0.7 * np.clip(nx * light[0] + nrm[:, 1] * light[1] + nz * light[2], 0, 1)
    scale = size / 6.2
    cam = 9.0
    persp = cam / (cam + pz)
    sx = size / 2 + px * scale * persp
    sy = size * 0.86 + (pos[:, 1] + 0.75) * scale * persp
    img = np.full((size, size, 3), (34.0, 38.0, 60.0), np.float32)
    zb = np.full((size, size), 1e9, np.float32)
    for t in range(0, len(pos), 3):
        i = [t, t + 1, t + 2]
        x, y = sx[i], sy[i]
        x0, x1, y0, y1 = int(max(0, x.min())), int(min(size - 1, x.max() + 1)), int(max(0, y.min())), int(min(size - 1, y.max() + 1))
        area = (x[1] - x[0]) * (y[2] - y[0]) - (x[2] - x[0]) * (y[1] - y[0])
        if abs(area) < 1e-6 or x1 < x0 or y1 < y0:
            continue
        yy, xx = np.mgrid[y0:y1 + 1, x0:x1 + 1]
        w0 = ((x[1] - xx) * (y[2] - yy) - (x[2] - xx) * (y[1] - yy)) / area
        w1 = ((x[2] - xx) * (y[0] - yy) - (x[0] - xx) * (y[2] - yy)) / area
        w2 = 1 - w0 - w1
        m = (w0 >= 0) & (w1 >= 0) & (w2 >= 0)
        if not m.any():
            continue
        z = w0 * pz[i[0]] + w1 * pz[i[1]] + w2 * pz[i[2]]
        vis = m & (z < zb[y0:y1 + 1, x0:x1 + 1])
        if not vis.any():
            continue
        u = (w0 * uv[i[0], 0] + w1 * uv[i[1], 0] + w2 * uv[i[2], 0]).astype(int).clip(0, 127)
        v = (w0 * uv[i[0], 1] + w1 * uv[i[1], 1] + w2 * uv[i[2], 1]).astype(int).clip(0, 127)
        l = w0 * shade[i[0]] + w1 * shade[i[1]] + w2 * shade[i[2]]
        col = tex[v, u] * l[..., None]
        reg = img[y0:y1 + 1, x0:x1 + 1]
        reg[vis] = col[vis]
        zb[y0:y1 + 1, x0:x1 + 1][vis] = z[vis]
    return np.clip(img, 0, 255).astype(np.uint8)


if __name__ == '__main__':
    pos, nrm, uv, tex, shapes, size_bytes = read_icn(sys.argv[1])
    yaws = [float(v) for v in sys.argv[sys.argv.index('--yaw') + 1].split(',')] if '--yaw' in sys.argv else [-40.0, 0.0, 40.0, 75.0]
    size = int(sys.argv[sys.argv.index('--size') + 1]) if '--size' in sys.argv else 420
    Image.fromarray(np.hstack([draw(pos, nrm, uv, tex, y, size) for y in yaws])).save(sys.argv[2])
    if '--tex' in sys.argv:
        Image.fromarray(tex.astype(np.uint8)).resize((512, 512), Image.NEAREST).save(sys.argv[sys.argv.index('--tex') + 1])
    print('read back: %d shape(s), %d triangles, %d bytes, x %.2f..%.2f y %.2f..%.2f z %.2f..%.2f' % (
        shapes, len(pos) // 3, size_bytes, pos[:, 0].min(), pos[:, 0].max(), pos[:, 1].min(), pos[:, 1].max(), pos[:, 2].min(), pos[:, 2].max()))
