"""BIBLE's own memory card icon: a dark plate standing in 3D, the PS2 logo raised on it in blue and an open white book
under it, the same family as the plate icons FMCB and PS2BBL show in the browser, so a BIBLE folder sits with them.
Every point here is drawn by this file; nothing comes out of another icon.

The format is the one RIPPS2's hat uses (ps2-pillars elf/theme/tools/make_hat_icon.py): a 20-byte header (0x00010000,
shapes, texture type 0x0E, 1.0, vertices), per vertex an 8-byte position, an 8-byte normal, a 4-byte UV and a 4-byte
RGBA (4.12 fixed point), the animation block, then a 128 x 128 RLE texture. One shape only: a v1.60 browser calls any
icon with more than one shape corrupted data (RIPPS2 build 119). Icon space: +x right, +y DOWN, +z into the screen.

    python make_bible_icon.py OUTDIR [--template release/icon.sys]

writes OUTDIR/bible.icn and OUTDIR/icon.sys (BOOT's) and OUTDIR/icon-sysconf.sys (a SYS-CONF folder's). Titles are
full-width Shift-JIS: a v1.60 browser shows plain ASCII there as nothing.
"""
import math
import os
import struct
import sys

import numpy as np

TEX = 128

# ---- the texture atlas ---------------------------------------------------------------------------------------
FACE = (0, 0, 128, 96)     # the plate's front
SIDE = (0, 96, 32, 16)     # the plate's edges
BLUE = (32, 96, 16, 16)    # the logo's face
BLUED = (48, 96, 16, 16)   # the logo's sides
COVER = (64, 96, 16, 16)   # the book's cover
PAGE = (0, 112, 32, 16)    # a page, with its lines
EDGE = (32, 112, 16, 16)   # the pages' edges
BEVEL = (48, 112, 16, 16)  # the plate's bevel


def fill(img, region, color):
    x, y, w, h = region
    img[y:y + h, x:x + w] = color


def make_texture():
    img = np.zeros((TEX, TEX, 3), np.float32)
    x0, y0, w, h = FACE
    top, mid, foot = np.array([22, 30, 78], np.float32), np.array([20, 20, 34], np.float32), np.array([16, 16, 24], np.float32)
    for y in range(h):
        t = y / (h - 1)
        c = top + (mid - top) * (t / 0.3) if t < 0.3 else mid + (foot - mid) * ((t - 0.3) / 0.7)
        img[y0 + y, x0:x0 + w] = c
    fill(img, SIDE, (60, 66, 92))
    fill(img, BLUE, (62, 148, 245))
    fill(img, BLUED, (22, 62, 150))
    fill(img, COVER, (30, 72, 190))
    fill(img, EDGE, (176, 180, 192))
    fill(img, BEVEL, (128, 138, 176))
    x0, y0, w, h = PAGE
    img[y0:y0 + h, x0:x0 + w] = (244, 244, 240)
    for y in (3, 6, 9, 12):
        img[y0 + y, x0 + 3:x0 + w - 3] = (150, 152, 164)
    return np.clip(img, 0, 255).astype(np.uint8)


def texel(u, v, region):
    """A region-relative (0..1, 0..1) point to the 4.12 UV the format stores (32 per texel), kept half a texel in."""
    x0, y0, w, h = region
    return int(round((x0 + 0.5 + u * (w - 1)) * 32)), int(round((y0 + 0.5 + v * (h - 1)) * 32))


# ---- the model: built y up, +z toward the viewer, and turned into icon space at the end -------------------------
tris = []  # each: three (position, normal, uv), counter-clockwise from outside


def tri(a, b, c, uv, normal=None, shine=0x7F):
    a, b, c = np.array(a, float), np.array(b, float), np.array(c, float)
    n = np.cross(b - a, c - a) if normal is None else np.array(normal, float)
    n = n / (np.linalg.norm(n) or 1)
    tris.append([(tuple(p), tuple(n), t, shine) for p, t in zip((a, b, c), uv)])


# a vertex's own brightness: 0x7F shows the texture as it is in the browser's light, more lifts it above the plate
SHINE = {BLUE: 0xFF, BLUED: 0xB0, PAGE: 0xC0, EDGE: 0xA0, COVER: 0xC0}


def quad(a, b, c, d, region, normal=None, uvs=((0, 1), (1, 1), (1, 0), (0, 0))):
    """a, b, c, d counter-clockwise from outside; uvs give the region's corners for each."""
    t = [texel(u, v, region) for u, v in uvs]
    shine = SHINE.get(region, 0x7F)
    tri(a, b, c, (t[0], t[1], t[2]), normal, shine)
    tri(a, c, d, (t[0], t[2], t[3]), normal, shine)


# the plate
W, H, D, B = 4.2, 3.5, 0.5, 0.07
x1, y1, zf, zb = W / 2, H, D / 2, -D / 2
inner = [(-x1 + B, B), (x1 - B, B), (x1 - B, y1 - B), (-x1 + B, y1 - B)]
outer = [(-x1, 0), (x1, 0), (x1, y1), (-x1, y1)]
ir = (inner[0][0], inner[0][1], inner[2][0], inner[2][1])
quad((*inner[0], zf), (*inner[1], zf), (*inner[2], zf), (*inner[3], zf), FACE, (0, 0, 1))
for k in range(4):  # the bevel, then the edge behind it, then the back
    m = (k + 1) % 4
    quad((*outer[k], zf - B), (*outer[m], zf - B), (*inner[m], zf), (*inner[k], zf), BEVEL)
    quad((*outer[k], zb), (*outer[m], zb), (*outer[m], zf - B), (*outer[k], zf - B), SIDE)
quad((*outer[1], zb), (*outer[0], zb), (*outer[3], zb), (*outer[2], zb), SIDE, (0, 0, -1))


def centreline(points, radius, arc=1):
    """A path of straight runs with its corners rounded, as (x, y) points."""
    out = [points[0]]
    for i in range(1, len(points) - 1):
        p0, p1, p2 = (np.array(points[k], float) for k in (i - 1, i, i + 1))
        d0, d1 = p0 - p1, p2 - p1
        l0, l1 = np.linalg.norm(d0), np.linalg.norm(d1)
        d0, d1 = d0 / l0, d1 / l1
        r = min(radius, l0 * 0.5, l1 * 0.5)
        a, b = p1 + d0 * r, p1 + d1 * r
        for s in range(arc + 1):
            t = s / arc
            out.append(tuple((1 - t) ** 2 * a + 2 * (1 - t) * t * p1 + t * t * b))
    out.append(points[-1])
    return out


def stroke(points, width, z0, z1, radius):
    """A flat ribbon along a path, raised from z0 to z1: its face, both walls and both ends."""
    c = np.array(centreline(points, radius), float)
    n = len(c)
    dirs = []
    for i in range(n):
        d = c[min(i + 1, n - 1)] - c[max(i - 1, 0)]
        dirs.append(d / np.linalg.norm(d))
    left = np.array([c[i] + np.array([-dirs[i][1], dirs[i][0]]) * width / 2 for i in range(n)])
    right = np.array([c[i] - np.array([-dirs[i][1], dirs[i][0]]) * width / 2 for i in range(n)])
    for i in range(n - 1):
        l0, l1, r0, r1 = left[i], left[i + 1], right[i], right[i + 1]
        quad((*r0, z1), (*r1, z1), (*l1, z1), (*l0, z1), BLUE, (0, 0, 1))
        quad((*l1, z0), (*l0, z0), (*l0, z1), (*l1, z1), BLUED)
        quad((*r0, z0), (*r1, z0), (*r1, z1), (*r0, z1), BLUED)
    quad((*left[0], z0), (*right[0], z0), (*right[0], z1), (*left[0], z1), BLUED)
    quad((*right[-1], z0), (*left[-1], z0), (*left[-1], z1), (*right[-1], z1), BLUED)


# the PS2 logo, on the centre lines of BIBLE's own (assets/embedded/logo_ps2bble.png, 382 x 66 with 5 px strokes): the
# same letters and spacing, the stroke a little heavier so it holds at a browser icon's few pixels
LW = 3.6                          # across
PX = LW / 382                     # one of the logo's pixels
SW, RAD = 0.1, 0.03               # the stroke and its corners (all but square, as the logo's are)
LX, LY = -LW / 2, 2.3             # its left foot on the plate (high: the browser looks down, so what is raised reads lower)
RAISE = 0.2


def lp(x, y):
    """A point in the logo's pixels (y down from its top) to the plate."""
    return (LX + x * PX, LY + (65 - y) * PX)


TOPY, MIDY, FOOTY = 2, 32, 63
letters = [
    # P: along the top, down the right, back along the middle, then the stem down from there
    [lp(0, TOPY), lp(116, TOPY), lp(116, MIDY), lp(2, MIDY), lp(2, 65)],
    # S: the low run from the left, straight up the middle, the high run to the right
    [lp(119, FOOTY), lp(182, FOOTY), lp(182, TOPY), lp(244, TOPY)],
    # 2: along the top, down the right, back along the middle, down the left, along the foot
    [lp(263, TOPY), lp(379, TOPY), lp(379, MIDY), lp(265, MIDY), lp(265, FOOTY), lp(381, FOOTY)],
]
for path in letters:
    stroke(path, SW, zf, zf + RAISE, RAD)

# the book: two pages opened in a shallow V, their outer edges toward the viewer, on a cover a little wider
BX, BY, BW, BH = 0.0, 1.22, 0.74, 0.9  # the spine's middle, a page's width and height
STRIPS = 3
Z0, ZOUT = zf + 0.08, zf + 0.3


def page_point(s, v, side):
    """s 0 at the spine .. 1 at the outer edge, v 0 foot .. 1 head; side -1 left, +1 right."""
    x = BX + side * (0.025 + BW * s)
    lift = 0.07 * math.sin(math.pi * min(1.0, s * 1.15))  # the pages bow up from the spine
    y = BY - BH / 2 + BH * v + lift - 0.05 * s
    z = Z0 + (ZOUT - Z0) * s
    return (x, y, z)


for side in (-1, 1):
    for i in range(STRIPS):
        s0, s1 = i / STRIPS, (i + 1) / STRIPS
        a, b, c, d = page_point(s0, 0, side), page_point(s1, 0, side), page_point(s1, 1, side), page_point(s0, 1, side)
        u0, u1 = (s0, s1)
        uvs = ((u0, 1), (u1, 1), (u1, 0), (u0, 0))
        if side > 0:
            quad(a, b, c, d, PAGE, None, uvs)
        else:
            quad(b, a, d, c, PAGE, None, (uvs[1], uvs[0], uvs[3], uvs[2]))
        # the block of pages under the foot and the head, down to the plate
        for v, flip in ((0, False), (1, True)):
            p, q = page_point(s0, v, side), page_point(s1, v, side)
            p0, q0 = (p[0], p[1], zf), (q[0], q[1], zf)
            quads = (p0, q0, q, p) if (side > 0) != flip else (q0, p0, p, q)
            quad(*quads, EDGE)
    # the outer edge of the block
    p, q = page_point(1, 0, side), page_point(1, 1, side)
    p0, q0 = (p[0], p[1], zf), (q[0], q[1], zf)
    quads = (p0, q0, q, p) if side > 0 else (q0, p0, p, q)
    quad(*quads, EDGE)
# the cover showing round the pages, flat on the plate
cx0, cx1, cy0, cy1 = BX - BW - 0.11, BX + BW + 0.11, BY - BH / 2 - 0.12, BY + BH / 2 + 0.1
zc = zf + 0.035
quad((cx0, cy0, zc), (cx1, cy0, zc), (cx1, cy1, zc), (cx0, cy1, zc), COVER, (0, 0, 1))

# ---- into icon space and out ---------------------------------------------------------------------------------
FOOT = -0.75  # where y = 0 (the plate's foot) lands


def to_icon(p):
    x, y, z = p
    return (x, FOOT - y, -z)


def fx(v):
    return max(-32768, min(32767, int(round(v * 4096))))


def rle(px):
    out, i, n = [], 0, len(px)
    while i < n:
        j = i
        while j < n and px[j] == px[i] and j - i < 0x7FFF:
            j += 1
        if j - i >= 2:
            out.append(struct.pack('<HH', j - i, px[i]))
            i = j
            continue
        k = i
        while k < n and k - i < 0x7FFF and not (k + 1 < n and px[k + 1] == px[k]):
            k += 1
        if k == i:
            k = i + 1
        out.append(struct.pack('<H', 0x10000 - (k - i)) + struct.pack('<%dH' % (k - i), *px[i:k]))
        i = k
    return b''.join(out)


def build():
    verts = [v for t in tris for v in t]
    out = [struct.pack('<IIIfI', 0x00010000, 1, 0x0E, 1.0, len(verts))]
    for pos, n, uv, shine in verts:
        x, y, z = to_icon(pos)
        out.append(struct.pack('<hhhh', fx(x), fx(y), fx(z), 0x400))
        out.append(struct.pack('<hhhh', fx(n[0]), fx(-n[1]), fx(-n[2]), 0x400))
        out.append(struct.pack('<hh', uv[0], uv[1]))
        out.append(bytes([shine, shine, shine, 0x80]))
    # one frame of one shape, byte for byte as OPL's list.icn has it (which a v1.60 browser shows)
    out.append(struct.pack('<IIfII', 1, 1, 0.0, 0, 1) + struct.pack('<IIff', 0, 1, 0.0, 1.0))
    img = make_texture()
    px = [((int(r) >> 3) | ((int(g) >> 3) << 5) | ((int(b) >> 3) << 10)) for r, g, b in img.reshape(-1, 3)]
    packed = rle(px)
    out.append(struct.pack('<I', len(packed)) + packed)
    return b''.join(out), len(verts)


def sjis(s):
    """Full-width Shift-JIS, as RIPPS2's blSjis writes a title."""
    out = bytearray()
    for ch in s:
        c = ord(ch)
        w = 0
        if 0x30 <= c <= 0x39:
            w = 0x824F + c - 0x30
        elif 0x41 <= c <= 0x5A:
            w = 0x8260 + c - 0x41
        elif 0x61 <= c <= 0x7A:
            w = 0x8281 + c - 0x61
        elif c == 0x20:
            w = 0x8140
        if w:
            out += bytes((w >> 8, w & 0xFF))
        else:
            out.append(c)
    return bytes(out)


def icon_sys(template, first, second):
    """A template icon.sys retitled, naming bible.icn three times, over BIBLE's sky (RIPPS2's blue, top then foot)."""
    s = bytearray(template)
    assert s[:4] == b'PS2D' and len(s) == 964
    a, b = sjis(first), sjis(second)
    s[0xC0:0x104] = (a + b).ljust(68, b'\0')
    s[6:8] = struct.pack('<H', len(a))
    s[0x104:0x1C4] = b'\0' * 192
    for off in (0x104, 0x144, 0x184):
        s[off:off + 9] = b'bible.icn'
    corners = ((1, 2, 9), (1, 2, 9), (11, 25, 76), (11, 25, 76))
    for i, c in enumerate(corners):
        struct.pack_into('<4i', s, 0x10 + 16 * i, c[0], c[1], c[2], 0)
    return bytes(s)


if __name__ == '__main__':
    outdir = sys.argv[1]
    tpl = sys.argv[sys.argv.index('--template') + 1] if '--template' in sys.argv else os.path.join(os.path.dirname(__file__), '..', '..', 'release', 'icon.sys')
    os.makedirs(outdir, exist_ok=True)
    data, nv = build()
    open(os.path.join(outdir, 'bible.icn'), 'wb').write(data)
    t = open(tpl, 'rb').read()
    open(os.path.join(outdir, 'icon.sys'), 'wb').write(icon_sys(t, 'BIBLE', 'Boot Loader'))
    open(os.path.join(outdir, 'icon-sysconf.sys'), 'wb').write(icon_sys(t, 'BIBLE', 'Settings'))
    print('bible.icn: %d vertices (%d triangles), 1 shape, %d bytes' % (nv, nv // 3, len(data)))
