#!/usr/bin/env python3
"""GoldenEye text-bank binary to C converter.

One of the three classes that had no in-tree converter (`setup`, `stan`,
`text`).  The format is the simplest of them:

    u32 offset[N]        big-endian, byte offsets from the start of the file
    ...                  null-terminated strings at those offsets

N is not stored.  It is implied: the table runs until the first string, so
N == offset[0] / 4.  A zero offset means an empty slot and emits 0 rather than
a string, which is how retail's multiplayer-only banks come out all-zero.

Output matches the committed form:

    char *LcradE[] = {
     "text\\n",
     0,
    };

Usage:
    python3 tools/text_binary_to_c.py <in.bin> [out.c] [--name LcradE]
"""

import argparse
import os
import struct
import sys

# C escapes for bytes that cannot sit raw in a string literal.  GoldenEye text
# is 7-bit plus a handful of control codes the engine reads as formatting; those
# are emitted as \xNN so a round-trip stays byte-exact.
SIMPLE = {0x0A: "\\n", 0x09: "\\t", 0x22: '\\"', 0x5C: "\\\\"}


def c_escape(raw):
    out = []
    for b in raw:
        if b in SIMPLE:
            out.append(SIMPLE[b])
        elif 0x20 <= b < 0x7F:
            out.append(chr(b))
        else:
            out.append(f"\\x{b:02x}")
    return "".join(out)


def parse_text_bank(data):
    """-> list of str|None, one per slot (None for an empty slot)."""
    if len(data) < 4:
        raise ValueError("too short to be a text bank")
    first = struct.unpack_from(">I", data, 0)[0]
    if first == 0 or first % 4 or first > len(data):
        raise ValueError(f"implausible first offset {first:#x}; not a text bank")
    n = first // 4
    offsets = list(struct.unpack_from(f">{n}I", data, 0))
    out = []
    for off in offsets:
        if off == 0:
            out.append(None)
            continue
        if off >= len(data):
            raise ValueError(f"offset {off:#x} past end of file")
        end = data.find(b"\x00", off)
        if end < 0:
            end = len(data)
        out.append(c_escape(data[off:end]))
    return out


def emit(name, strings):
    lines = [f"\nchar *{name}[] = {{"]
    for s in strings:
        lines.append(" 0," if s is None else f' "{s}",')
    if len(lines) > 1:
        lines[-1] = lines[-1].rstrip(",")      # retail omits the trailing comma
    lines.append("};\n")
    return "\n".join(lines)


def main():
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("input")
    ap.add_argument("output", nargs="?")
    ap.add_argument("--name", help="C array name (default: input basename)")
    a = ap.parse_args()

    data = open(a.input, "rb").read()
    name = a.name or os.path.basename(a.input).split(".")[0]
    try:
        strings = parse_text_bank(data)
    except ValueError as e:
        sys.exit(f"{a.input}: {e}")
    out = a.output or a.input.replace(".bin", ".c")
    open(out, "w").write(emit(name, strings))
    filled = sum(1 for s in strings if s is not None)
    print(f"{os.path.basename(a.input)}: {len(strings)} slots, {filled} strings -> {out}")


if __name__ == "__main__":
    main()
