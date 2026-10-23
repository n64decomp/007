#!/usr/bin/env python3
"""GoldenEye stan (standing tile) binary to C converter.

Second of the three classes that had no in-tree converter.  Stan files carry
the walkable-surface tiles the AI and collision code path over.

Layout, confirmed against retail bg_crad by decoding and comparing to the
committed Tbg_crad_all_p_stanZ.c:

    StandFileHeader   4  unused pointer (0)
                      4  offset of the first tile (0x28 -- i.e. 40)
                     32  trailing bytes, emitted verbatim
    StandTile[]       4  u32: id in the top 24 bits, room in the low 8
                      2  u16 nibbles: special, r, g, b
                      2  u16 nibbles: pointCount, headerC, headerD, headerE
                    8*n  StandTilePoint: s16 x, s16 y, s16 z, u16 link
    StandFileFooter      a name string then four NULLs

Tiles are variable length and run until one has pointCount == 0, which
terminates the chain and is itself emitted (retail's last tile is a zero tile).

Usage:
    python3 tools/stan_binary_to_c.py <in.bin> [out.c] [--name Tbg_x_all_p_stanZ]
"""

import argparse
import os
import struct
import sys

HEADER_LEN = 40
TILE_HEAD = 8
POINT_LEN = 8


def parse_stan(data):
    if len(data) < HEADER_LEN:
        raise ValueError("shorter than a stan header")
    _unused, first = struct.unpack_from(">II", data, 0)
    if not (8 <= first <= len(data)):
        raise ValueError(f"implausible first-tile offset {first:#x}")
    if first != HEADER_LEN:
        # Retail is always 0x28, but ROM hacks are not: at least one
        # hack's stan puts the first tile at 0xc.  The trailing block is whatever lies
        # between the two pointers and the first tile -- deriving it from
        # `first` rather than assuming 40 is what keeps those files correct.
        print(f"  note: first tile offset is {first:#x}, not {HEADER_LEN:#x}")
    trailing = data[8:first]

    tiles, off = [], first
    while off + TILE_HEAD <= len(data):
        word = struct.unpack_from(">I", data, off)[0]
        mid, tail = struct.unpack_from(">HH", data, off + 4)
        pc = (tail >> 12) & 0xF
        if off + TILE_HEAD + pc * POINT_LEN > len(data):
            break
        pts = [struct.unpack_from(">hhhH", data, off + TILE_HEAD + k * POINT_LEN)
               for k in range(pc)]
        tiles.append({
            "id": word >> 8, "room": word & 0xFF,
            "special": (mid >> 12) & 0xF, "r": (mid >> 8) & 0xF,
            "g": (mid >> 4) & 0xF, "b": mid & 0xF,
            "pc": pc, "c": (tail >> 8) & 0xF, "d": (tail >> 4) & 0xF,
            "e": tail & 0xF, "points": pts,
        })
        off += TILE_HEAD + pc * POINT_LEN
        if pc == 0:                       # zero tile terminates the chain
            break

    footer = data[off:]
    name = ""
    if footer:
        end = footer.find(b"\x00")
        name = footer[:end if end > 0 else len(footer)].decode("ascii", "replace")
    return trailing, tiles, name, off


def emit(name, trailing, tiles, footer_name):
    o = ["/*", "* This file was automatically generated", "*",
         "* tools/stan_binary_to_c.py", "*/", "",
         "#include <ultra64.h>", "#include <game/stan.h>", "",
         "// forward declarations", "StandTile tile_0;", "",
         f"StandFileHeader {name} = {{", "    NULL,", "    &tile_0,",
         "    {" + ", ".join(f"0x{b:02x}" for b in trailing) + "}", "};", ""]
    for i, t in enumerate(tiles):
        o.append(f"StandTile tile_{i} = {{")
        o.append(f"    0x{t['id']:06x}, 0x{t['room']:02x},")
        o.append(f"    0x{t['special']:x},")
        o.append(f"    0x{t['r']:x}, 0x{t['g']:x}, 0x{t['b']:x},")
        o.append(f"    {t['pc']},")
        line = f"    0x{t['c']:x}, 0x{t['d']:x}, 0x{t['e']:x}"
        if t["points"]:
            o.append(line + ",")
            o.append("    {")
            rows = [f"        {{{x}, {y}, {z}, 0x{lk:04x}}}" for x, y, z, lk in t["points"]]
            o.append(",\n".join(rows))
            o.append("    }")
        else:
            o.append(line)
        o.append("};")
        o.append("")
    o += ["", f'StandFileFooter footer = {{', f'    "{footer_name}",',
          "    NULL,", "    NULL,", "    NULL,", "    NULL", "};", "", "", ""]
    return "\n".join(o)


def main():
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("input")
    ap.add_argument("output", nargs="?")
    ap.add_argument("--name", help="C symbol name (default: input basename)")
    a = ap.parse_args()

    data = open(a.input, "rb").read()
    name = a.name or os.path.basename(a.input).split(".")[0]
    try:
        trailing, tiles, footer_name, consumed = parse_stan(data)
    except (ValueError, struct.error) as e:
        sys.exit(f"{a.input}: {e}")
    out = a.output or a.input.replace(".bin", ".c")
    open(out, "w").write(emit(name, trailing, tiles, footer_name))
    pts = sum(t["pc"] for t in tiles)
    print(f"{os.path.basename(a.input)}: {len(tiles)} tiles, {pts} points, "
          f"footer={footer_name!r}, {consumed}/{len(data)} B consumed -> {out}")


if __name__ == "__main__":
    main()
