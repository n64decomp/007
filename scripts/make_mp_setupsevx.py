#!/usr/bin/env python3
"""
Generate assets/obseg/setup/Ump_setupsevxZ.c (Surface 1 multiplayer setup)
from the solo setup assets/obseg/setup/UsetupsevxZ.c.

Keeps the level geometry props (doors, glass, standard props, monitors),
drops everything solo-only (guards, AI, objectives, cameras, keys, pickups),
unlocks all doors, then adds MP spawn points, the 8 MP weapon slots
(0xF0-0xF7, each followed by its ammo box), body armour and the flag token.

Usage: python3 scripts/make_mp_setupsevx.py
"""
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
SRC = ROOT / "assets/obseg/setup/UsetupsevxZ.c"
DST = ROOT / "assets/obseg/setup/Ump_setupsevxZ.c"

KEEP_TYPES = {"Door", "Glass", "TintedGlass", "StandardProp", "SingleMonitor"}

# Spawn pads (padlist indices). Taken from solo spawns, guard positions
# and guard path waypoints so they're all on walkable ground.
SPAWN_PADS = [45, 67, 290, 2, 7, 81, 107, 159, 182, 233, 57, 213]

# One weapon is placed near each spawn; placed weapons take these MP
# weapon slots (0xF0 + n) in order, so every slot appears at least once.
SPAWN_WEAPON_SLOTS = [0, 1, 2, 3, 4, 5, 6, 7, 1, 3, 5, 7]

WEAPON_MIN_DIST = 250   # weapon distance from its spawn
WEAPON_MAX_DIST = 900
WEAPON_SPACING = 400    # min distance between two weapons
AMMO_MAX_DIST = 500     # ammo box distance from its weapon
MAX_DY = 40             # keep pickups on the same floor as what they're near
ARMOUR_PADS = [84, 195]
TOKEN_PAD = 129

OBJ_WORDS = 32          # sizeof(ObjectRecord) / 4
DOOR_LINK_WORD = 32     # DoorRecord.linkedDoorOffset
DOOR_KEY_WORD = 39      # DoorRecord keyflags (0x9C)

FLAG_ASSIGNED_TO_CHR = 0x00004000
FLAG_INSIDE_OBJECT = 0x00008000

# rest of ObjectRecord after the 4 header words (32 words total)
PAD = "0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0"
AMMO_SLOTS = ", ".join(["_mkword(0xffff, 0)"] * 13)


def split_top(s):
    """Split on commas not nested in parentheses."""
    out, depth, cur = [], 0, ""
    for ch in s:
        if ch == "(":
            depth += 1
        elif ch == ")":
            depth -= 1
        if ch == "," and depth == 0:
            out.append(cur.strip())
            cur = ""
        else:
            cur += ch
    if cur.strip():
        out.append(cur.strip())
    return out


def to_int(tok):
    v = int(tok, 0)
    return v - (1 << 32) if v >= 0x80000000 else v


def section(text, start_re):
    m = re.search(start_re, text, re.M)
    end = text.index("\n};", m.end())
    return m.start(), m.end(), end + 3


def parse_entries(body):
    entries = []
    for m in re.finditer(r"/\* Type = (\w+); index = (\d+) \*/\n(.*?)(?=\n\s*/\* Type =|\Z)", body, re.S):
        entries.append({"type": m.group(1), "index": int(m.group(2)),
                        "words": split_top(m.group(3).strip().rstrip(","))})
    return entries


def obj_pad(words):
    m = re.match(r"_mkword\((-?\w+),\s*(-?\w+)\)", words[1])
    return int(m.group(2), 0)


def place_weapons(pads, used):
    """Pick (slot, weapon pad, ammo pad) near each spawn from pads not used by anything else."""
    import math
    taken = set(used)
    weapons = []
    for spawn in SPAWN_PADS:
        sp = pads[spawn]
        # widen the search for spawns with nothing close by on the same floor
        for lo, hi in ((WEAPON_MIN_DIST, WEAPON_MAX_DIST), (100, 1500), (100, 2500)):
            cands = [i for i, p in enumerate(pads)
                     if i not in taken
                     and abs(p[1] - sp[1]) <= MAX_DY
                     and lo <= math.dist(p, sp) <= hi
                     and all(math.dist(p, pads[w]) >= WEAPON_SPACING for _, w, _ in weapons)]
            if cands:
                break
        else:
            print(f"  spawn {spawn}: no free pad nearby, skipped")
            continue
        # nearest candidate that also has a free pad beside it for the ammo box
        for w in sorted(cands, key=lambda i: math.dist(pads[i], sp)):
            acands = [i for i, p in enumerate(pads)
                      if i not in taken and i != w and abs(p[1] - pads[w][1]) <= MAX_DY
                      and math.dist(p, pads[w]) <= AMMO_MAX_DIST]
            if acands:
                a = min(acands, key=lambda i: math.dist(pads[i], pads[w]))
                break
        else:
            # isolated spot: weapon only (picking it up still gives ammo)
            w = min(cands, key=lambda i: math.dist(pads[i], sp))
            a = None
        taken |= {w, a} - {None}
        slot = SPAWN_WEAPON_SLOTS[len(weapons)]
        weapons.append((slot, w, a))
        print(f"  slot {slot}: spawn {spawn} -> weapon pad {w} ({math.dist(pads[w], sp):.0f} away), "
              + (f"ammo pad {a} ({math.dist(pads[a], pads[w]):.0f} from weapon)" if a is not None else "no ammo box"))
    if len(weapons) < 8:
        sys.exit("fewer than 8 weapons placed, not every MP weapon slot would appear")
    return weapons


def main():
    text = SRC.read_text()

    p0, pb, p1 = section(text, r"^s32 propDefs\[\] = \{")
    entries = parse_entries(text[pb:p1 - 3])

    kept = []
    for e in entries:
        if e["type"] not in KEEP_TYPES:
            continue
        w = e["words"]
        flags = to_int(w[2]) & 0xFFFFFFFF
        if flags & (FLAG_ASSIGNED_TO_CHR | FLAG_INSIDE_OBJECT) or obj_pad(w) < 0:
            continue
        kept.append(e)

    newidx = {e["index"]: i for i, e in enumerate(kept)}
    for e in kept:
        if e["type"] != "Door":
            continue
        w = e["words"]
        link = to_int(w[DOOR_LINK_WORD])
        if link:
            target = e["index"] + link
            w[DOOR_LINK_WORD] = str(newidx[target] - newidx[e["index"]]) if target in newidx else "0"
        w[DOOR_KEY_WORD] = "0x00000000"

    padsrc = text[text.index("PadRecord padlist[] = {"):text.index("BoundPadRecord pad3dlist[] = {")]
    pads = [tuple(float(v) for v in m.groups())
            for m in re.finditer(r"\{ \{(-?[\d.e+-]+)f?, (-?[\d.e+-]+)f?, (-?[\d.e+-]+)f?\}", padsrc)]
    used = {obj_pad(e["words"]) for e in kept if obj_pad(e["words"]) < 10000}
    used |= set(SPAWN_PADS) | set(ARMOUR_PADS) | {TOKEN_PAD}
    weapons = place_weapons(pads, used)

    props = []
    for e in kept:
        props.append((e["type"], ", ".join(e["words"])))

    # Flag for The Living Daylights (ITEM_TOKEN, flag model)
    props.append(("Collectable", f"_mkword(256, _mkshort(0, 8)), _mkword(333, {TOKEN_PAD}), 0x00000001, 0x00000000, 0x00000000, 0x00000000, {PAD}, _mkword(_mkshort(0x58, 0xff), 0xffff), 0"))
    for slot, wpad, apad in weapons:
        props.append(("Collectable", f"_mkword(512, _mkshort(0, 8)), _mkword(0, {wpad}), 0x00000001, 0x00000000, 0x00000000, 0x00000000, {PAD}, _mkword(_mkshort(0x{0xf0 + slot:02x}, 0xff), 0xffff), 0"))
        if apad is None:
            continue
        props.append(("AmmoBox", f"_mkword(256, _mkshort(0, 20)), _mkword(5, {apad}), 0x00000001, 0x00000000, 0x00000000, 0x00000000, {PAD}, {AMMO_SLOTS}"))
    for apad in ARMOUR_PADS:
        props.append(("Armour", f"_mkword(384, _mkshort(0, 21)), _mkword(115, {apad}), 0x00000001, 0x00000000, 0x00000000, 0x00000000, {PAD}, 65536, 0"))

    lines = ["s32 propDefs[] = {"]
    for i, (t, body) in enumerate(props):
        lines.append(f"    /* Type = {t}; index = {i} */")
        lines.append(f"    {body},")
    lines.append(f"    /* Type = EndProps; index = {len(props)} */")
    lines.append("    _mkword(0, _mkshort(0, 48))")
    lines.append("};")
    new_props = "\n".join(lines)

    lines = ["s32 intro[] = {"]
    i = 0
    for pad in SPAWN_PADS:
        lines += [f"    /* Type = Spawn; index = {i} */", f"    _mkword(0, _mkshort(0, 0)), {pad}, 0,"]
        i += 1
    lines += [f"    /* Type = StartWeapon; index = {i} */", "    _mkword(0, _mkshort(0, 1)), 1, -1, 0,",
              f"    /* Type = Cuff; index = {i + 1} */", "    _mkword(0, _mkshort(0, 5)), 3,",
              f"    /* Type = EndIntro; index = {i + 2} */", "    _mkword(0, _mkshort(0, 9))", "};"]
    new_intro = "\n".join(lines)

    i0, _, i1 = section(text, r"^s32 intro\[\] = \{")
    a0 = re.search(r"^u8 ai_\d+\[\] = \{", text, re.M).start()

    out = text[:p0] + new_props + text[p1:i0] + new_intro + text[i1:a0]
    out += "AIListRecord ailists[] = {\n    /* index = 0 */\n    { NULL, 0x00000000 }\n};\n"

    out = out.replace("stagesetup UsetupsevxZ", "stagesetup Ump_setupsevxZ")
    out = out.replace('#include "bondaicommands.h"\n', "")
    out = re.sub(r"\* This file was automatically generated\n",
                 "* Surface multiplayer setup, generated from UsetupsevxZ.c\n* by scripts/make_mp_setupsevx.py\n", out, count=1)

    # sanity: every referenced pad index must exist
    for pad in SPAWN_PADS + ARMOUR_PADS + [TOKEN_PAD]:
        if pad >= len(pads):
            sys.exit(f"pad {pad} out of range ({len(pads)} pads)")

    DST.write_text(out)
    print(f"wrote {DST.relative_to(ROOT)}: {len(kept)} level props kept of {len(entries)}, {len(props) - len(kept)} MP props added")


if __name__ == "__main__":
    main()
