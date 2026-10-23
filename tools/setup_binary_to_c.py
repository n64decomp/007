#!/usr/bin/env python3
"""GoldenEye setup (mission scripting) binary to C converter.

Third and last of the classes that had no in-tree converter.  A setup carries
the mission logic: pads, guard paths, prop/objective definitions, the intro
block and the AI lists.

The authoritative format description is assets/obseg/setup/readme.md; this
implements it.  Two properties of that format matter most:

  * Pointers are PLAIN ZERO-BASED FILE OFFSETS, not N64 addresses.  Unlike bg
    (0x0F000000) and chr/prop (0x05000000) there is no base to subtract --
    `pads` sits at 0x28, immediately past the 40-byte header.
  * Sections are SENTINEL-TERMINATED, not sized by the gap to the next
    section.  Between main sections lie "filler" blocks holding data those
    sections point at (neighbour arrays, AI bytecode), so gap arithmetic
    measures filler too and would overcount every time.

Values are big-endian.  Setups are stored 1172-compressed in ROM.

WHAT THIS EMITS
    All ten sections, plus the filler between them, IN THE ORDER THEY SAT IN
    THE FILE.  Every count below is confirmed against the committed
    assets/obseg/setup/u/UsetupcradZ.c:

        padlist 153, pad3dlist 7, propDefs 861 words, intro 165 words,
        pathsets 16, pathwaypoints 142, patrolpaths 1, ailists 43,
        42 AI blocks, and two unreferenced name tables of 16 and 142

    Auxiliary arrays (neighbour and index lists) live in the filler blocks and
    are shared by offset, so they are interned -- one symbol per distinct
    offset, emitted ahead of the tables that point at them.

IT ROUND-TRIPS: ALL 34 SETUPS IN THE RETAIL ROM, BYTE FOR BYTE
    ROM binary -> C -> IDO -> ld -> objcopy -> the same bytes back, checked
    for every setup in baserom.u.z64.  That is a stronger check than any
    count: it is the only one that catches a field read from the wrong offset.

    Four things it took, and each was a real defect rather than a refinement:

      * ORDER.  A setup is a pile of internal file offsets and the compiler
        lays .data out in source order, so every definition has to be emitted
        where it was.  Sorting by offset is what emit() does.
      * AI BLOCK LENGTHS come from the tiling, not from the first 0x04 byte;
        0x04 is `ai_list_end` and also an ordinary operand.
      * THE NAME TABLES are emitted, referenced or not.  Ten of the 34 setups
        name them in the header, and Cradle carries two of them unreferenced.
      * AN EMPTY NAME is a pointer to a zero-length string, not a NULL.

ONE DELIBERATE SHORTFALL: AI BYTECODE IS EMITTED AS RAW BYTES
    Getools disassembles each AI block into readable macros from
    bondaicommands.h -- `guard_set_health_total(0x2800)`, `ai_list_end` and so
    on, 230 of them.  This emits `u8 ai_N[] = {0x2b, 0x29, ...}` instead.  The
    macros expand to exactly those bytes, so the result is functionally
    identical and compiles; it is simply unreadable where the committed
    sources are readable.  Disassembling properly means deriving all 230
    opcodes and their operand widths from bondaicommands.h, with
    tools/aiParse.c as prior art.  Worth doing, not needed to import a level.

Usage:
    python3 tools/setup_binary_to_c.py <in.bin> [out.c] [--name UsetupcradZ]
    python3 tools/setup_binary_to_c.py <in.bin> --report
"""

import argparse
import os
import struct
import sys

HEADER_LEN = 40
PAD_LEN = 44                  # PadRecord, bondtypes.h 0x2c
BOUNDPAD_LEN = 68             # BoundPadRecord, bondtypes.h 0x44
PROPDEF_END = 48              # PROPDEF_TYPE, bondconstants.h

# Words per propdef record, by PROPDEF_TYPE, from the game's sizepropdef().
PROPDEF_WORDS = {1: 64, 2: 2, 3: 32, 4: 33, 5: 32, 6: 59, 7: 33, 8: 34, 9: 7,
                 10: 64, 11: 149, 12: 32, 13: 54, 14: 3, 15: 1, 16: 1, 17: 32,
                 18: 3, 19: 4, 20: 45, 21: 34, 22: 4, 23: 4, 24: 1, 25: 2,
                 26: 2, 27: 2, 28: 2, 29: 2, 30: 4, 31: 1, 32: 4, 33: 5,
                 34: 1, 35: 4, 36: 32, 37: 10, 38: 4, 39: 44, 40: 45, 41: 1,
                 42: 32, 43: 32, 44: 5, 45: 56, 46: 7, 47: 37}
INTROTYPE_END = 9             # INTRO_TYPE, bondconstants.h

# Words per intro entry, indexed by INTRO_TYPE.  Derived rather than guessed:
# the lengths come from the type comments Getools left in all 54 committed
# setup sources (each type has exactly one length across every file), and the
# type<->length pairing was then confirmed against Cradle's actual bytes by
# walking its committed entry sequence through the binary.  That walk lands on
# 165 words, which is what the committed intro[] holds.
#
# 4 (ANIM) and 8 (CREDITS) do not appear in Cradle, but both are length 2 in
# the corpus, so the table is unambiguous even where the naming is not.
INTRO_LEN = {0: 3, 1: 4, 2: 4, 3: 8, 4: 2, 5: 2, 6: 10, 7: 3, 8: 2, 9: 1}

# stagesetup field order (bondtypes.h:3998) paired with the symbol names
# Getools emits, which differ for two of them.
# Declared type per emitted symbol, for the forward-declaration block.
DECL_TYPE = {
    "pathwaypoints": "waypoint",
    "pathsets":      "waygroup",
    "intro":         "s32",
    "propDefs":      "s32",
    "patrolpaths":   "PathRecord",
    "ailists":       "AIListRecord",
    "padlist":       "PadRecord",
    "pad3dlist":     "BoundPadRecord",
    "padnames":      "char *",
    "pad3dnames":    "char *",
}

# The ten header pointers, paired with the symbol each is emitted as. Getools
# names two of them differently, hence the pairing rather than one list.
#
# padnames and boundpadnames used to be None here -- the converter did not emit
# them, so the header came out with NULL in slots 8 and 9 whatever the original
# said. Ten of the retail ROM's 34 setups do name those tables, and every one
# of them failed the round trip on those two words alone.
FIELDS = [
    ("pathwaypoints",  "pathwaypoints"),
    ("waypointgroups", "pathsets"),
    ("intro",          "intro"),
    ("propDefs",       "propDefs"),
    ("patrolpaths",    "patrolpaths"),
    ("ailists",        "ailists"),
    ("pads",           "padlist"),
    ("boundpads",      "pad3dlist"),
    ("padnames",       "padnames"),
    ("boundpadnames",  "pad3dnames"),
]


def decl(sym):
    """`waypoint pathwaypoints[];` -- and `char *padnames[];`, not `char * p`."""
    t = DECL_TYPE[sym]
    return f"{t}{sym}[];" if t.endswith("*") else f"{t} {sym}[];"


def f32(v):
    """Format a float the way the committed sources do."""
    if v == int(v) and abs(v) < 1e16:
        return f"{v:.1f}f"
    return f"{v!r}f"


def cname(nm):
    """A name as C: a quoted string, or NULL when the pointer was NULL.

    Formatting it straight would render a missing name as the literal
    string "None", which compiles and is wrong.

    TESTED AGAINST None, NOT AGAINST TRUTH. An empty name is a pointer to a
    zero-length string, which occupies four bytes of .rodata like any other;
    `if nm` folds it in with "no pointer at all" and emits NULL, which costs
    those bytes and every offset after them. Cradle carries 156 empty names in
    its two unreferenced name tables, and that one `if` was the last 624 bytes
    of its 3,888-byte round-trip gap.
    """
    return "NULL" if nm is None else f'"{nm}"'


def cstr(data, off):
    if off == 0 or off >= len(data):
        return None
    end = data.find(b"\x00", off)
    return data[off:end if end >= 0 else len(data)].decode("ascii", "replace")


def parse_header(data):
    if len(data) < HEADER_LEN:
        raise ValueError("shorter than a setup header")
    vals = struct.unpack_from(">10I", data, 0)
    hdr = {name: off for (name, _), off in zip(FIELDS, vals)}
    for name, off in hdr.items():
        if off and off >= len(data):
            raise ValueError(f"{name} offset {off:#x} past end of file "
                             f"({len(data)}) -- wrong base ROM or not a setup")
    return hdr


def parse_pads(data, off, length, nfloat):
    """Read fixed-size pad records until the all-zero terminator.

    Both record types share a leading PadRecord: pos/up/look in words 0-8,
    then plink in word 9 and stan in word 10.  BoundPadRecord appends its
    bbox in words 11-16.  So the pointer pair is at a FIXED offset 36 in both
    -- deriving it from the record length instead reads words 15-16 of a
    BoundPadRecord, which are bbox floats, and yields a garbage name and a
    float bit pattern for stan.
    """
    out = []
    while off + length <= len(data):
        vals = struct.unpack_from(f">{nfloat}f", data, off)
        plink, stan = struct.unpack_from(">II", data, off + 36)
        # terminator: every float zero and no name
        if plink == 0 and not any(vals):
            out.append(None)          # the empty entry is emitted too
            break
        # plink is carried as well as the name it resolves to: the string is a
        # .rodata object of its own, and the gap pass has to know where it sat.
        out.append((vals, cstr(data, plink), stan, plink))
        off += length
    return out


def parse_intro(data, off, limit):
    """Walk intro entries by type until INTROTYPE_END.

    The gap to the next section is NOT the answer here -- filler follows the
    intro block, and bounding by it over-reads (372 words against Cradle's
    real 165).  Entries are a type word plus a type-sized payload.
    """
    words, cur = [], off
    while cur + 4 <= limit:
        t = struct.unpack_from(">i", data, cur)[0]
        n = INTRO_LEN.get(t)
        if n is None:
            raise ValueError(f"intro: unknown type {t} at {cur:#x}")
        if cur + n * 4 > limit:
            raise ValueError(f"intro: type {t} at {cur:#x} runs past the section")
        words += list(struct.unpack_from(f">{n}i", data, cur))
        cur += n * 4
        if t == INTROTYPE_END:
            break
    else:
        raise ValueError("intro: ran off the end without INTROTYPE_END")
    return words


def s32_array(data, off, limit):
    """A -1 terminated s32 array, as neighbour and index lists are stored."""
    out = []
    while off + 4 <= limit:
        v = struct.unpack_from(">i", data, off)[0]
        out.append(v)
        off += 4
        if v == -1:
            break
    return out


def parse_waypoints(data, off, limit, aux):
    """waypoint[16]: padID, *neighbours, groupNum, dist.  Ends at padID == -1."""
    out = []
    while off + 16 <= limit:
        pad, nb, grp, dist = struct.unpack_from(">iIii", data, off)
        off += 16
        if pad == -1:
            out.append(None)
            break
        sym = None
        if nb:
            sym = aux("path_table", nb, s32_array(data, nb, limit))
        out.append((pad, sym, grp, dist))
    return out


def parse_waygroups(data, off, limit, aux):
    """waygroup[12]: *neighbours, *waypoints, dist.  Ends when both are NULL."""
    out = []
    while off + 12 <= limit:
        nb, wp, dist = struct.unpack_from(">IIi", data, off)
        off += 12
        if not nb and not wp:
            out.append(None)
            break
        out.append((aux("path_neighbors", nb, s32_array(data, nb, limit)) if nb else None,
                    aux("path_indeces", wp, s32_array(data, wp, limit)) if wp else None,
                    dist))
    return out


def parse_patrolpaths(data, off, limit, aux):
    """PathRecord[8]: *waypoints, u8 ID, u8 isLoop, u16 len.  NULL ends it.

    EIGHT bytes, not twelve.  bondtypes.h:1734 is `s32 *waypoints; u8 ID;
    u8 isLoop; u16 len;` -- 4+1+1+2.  This strode 12 and read every record
    after the first from the wrong place; Cradle hid it because its only
    entry is the terminator.  The linker agrees: patrolpaths occupies
    0x4438..0x4440 in UsetupcradZ.elf, which is one 8-byte record.
    """
    out = []
    while off + 8 <= limit:
        wp, pid, loop, ln = struct.unpack_from(">IBBH", data, off)
        off += 8
        if not wp:
            out.append(None)
            break
        out.append((aux("path_set", wp, s32_array(data, wp, limit)), pid, loop, ln))
    return out


def parse_ailists(data, off, limit, blocks):
    """AIListRecord[8]: *ailist, ID.  NULL ends it."""
    out = []
    while off + 8 <= limit:
        ptr, aid = struct.unpack_from(">Ii", data, off)
        off += 8
        if not ptr:
            out.append(None)
            break
        out.append((blocks(ptr), aid))
    return out


def bound_of(hdr, start, total):
    """Nearest section start above `start` -- the bound for a flat section."""
    highs = [o for o in hdr.values() if o and o > start]
    return min(highs) if highs else total


def parse_propdefs(data, off):
    """Walk propdef entries by type until PROPDEF_END, and return the words.

    Bounding this by the next section start instead measures the FILLER that
    follows too.  It happened to be exact for Cradle and is not a rule: the
    section is sentinel-terminated (assets/obseg/setup/readme.md), and the
    per-type word counts are in PROPDEF_WORDS.
    """
    i = off
    while i + 4 <= len(data):
        t = struct.unpack_from(">i", data, i)[0] & 0xFF
        if t == PROPDEF_END:
            i += 4
            break
        size = PROPDEF_WORDS.get(t)
        if size is None:
            raise ValueError(f"propDefs: unknown type {t} at {i:#x}")
        i += size * 4
    else:
        raise ValueError("propDefs: ran off the end without PROPDEF_END")
    return list(struct.unpack_from(f">{(i - off) // 4}i", data, off)), i


def cstr_end(data, off):
    """One past the NUL of the string at `off`."""
    end = data.find(b"\x00", off)
    return (len(data) if end < 0 else end) + 1


def parse(data):
    hdr = parse_header(data)
    r = {"header": hdr, "size": len(data)}

    # WHERE EACH EMITTED SYMBOL SAT IN THE ORIGINAL FILE.
    #
    # A setup is a pile of internal file offsets, so a converted one only
    # round-trips byte for byte when every symbol lands back where it started.
    # The compiler lays .data out in source order, so
    # recording the offset here is what lets emit() sort by it.  Entries are
    # [offset, end, kind, symbol, payload]; `end` bounds gap detection.
    objs = []
    r["objs"] = objs

    def add(off, end, kind, sym, payload):
        objs.append([off, end, kind, sym, payload])

    # The stagesetup struct itself, so the gap pass does not read the header
    # back as unreferenced filler and emit it a second time. emit() writes it
    # out ahead of the loop, since the forward declarations have to precede it.
    add(0, HEADER_LEN, "header", None, None)

    if hdr["pads"]:
        # PadRecord is 3 coord3d + 2 words; read 9 floats then the two words
        r["padlist"] = parse_pads(data, hdr["pads"], PAD_LEN, 11)
        add(hdr["pads"], hdr["pads"] + len(r["padlist"]) * PAD_LEN,
            "padlist", "padlist", r["padlist"])
    if hdr["boundpads"]:
        r["pad3dlist"] = parse_pads(data, hdr["boundpads"], BOUNDPAD_LEN, 17)
        add(hdr["boundpads"], hdr["boundpads"] + len(r["pad3dlist"]) * BOUNDPAD_LEN,
            "pad3dlist", "pad3dlist", r["pad3dlist"])

    if hdr["propDefs"]:
        r["propDefs"], end = parse_propdefs(data, hdr["propDefs"])
        add(hdr["propDefs"], end, "flat", "propDefs", r["propDefs"])

    if hdr["intro"]:
        r["intro"] = parse_intro(data, hdr["intro"], bound_of(hdr, hdr["intro"], len(data)))
        add(hdr["intro"], hdr["intro"] + len(r["intro"]) * 4, "flat", "intro", r["intro"])

    # Auxiliary arrays live in filler blocks between the main sections and are
    # shared by offset, so they are interned: one symbol per distinct offset.
    # Their NUMBER comes from the order the owning table mentions them, the way
    # the committed sources number them; their PLACE comes from the offset.
    r["aux"], r["ai"] = [], []
    seen_aux, seen_ai = {}, {}

    def aux(family, off, values):
        if off in seen_aux:
            return seen_aux[off]
        sym = f"{family}_{sum(1 for s in r['aux'] if s[0].startswith(family + '_'))}"
        seen_aux[off] = sym
        r["aux"].append((sym, values))
        add(off, off + len(values) * 4, "aux", sym, values)
        return sym

    # AI BLOCK LENGTHS COME FROM THE TILING, NOT FROM THE FIRST 0x04.
    #
    # `ai_list_end` is one byte, 0x04, and 0x04 is also an ordinary operand
    # byte -- so "read until the first 0x04" cut 40 of Cradle's 42 blocks
    # short and lost 2,693 of the file's 3,888 missing bytes.  The blocks tile
    # the span between patrolpaths and ailists with no holes, so a block runs
    # to the next block's start (or to ailists for the last one).  Measured on
    # Cradle: all 42 spans end in 0x04 followed by 0-3 zero pad bytes, and all
    # 42 are a multiple of four long, which is the word alignment the readme
    # describes.  Emitting that padding INSIDE the u8 array is what keeps the
    # next symbol where it was -- a u8 array carries no alignment of its own.
    ai_starts = []

    def block(off):
        if off in seen_ai:
            return seen_ai[off]
        sym = f"ai_{len(r['ai'])}"
        seen_ai[off] = sym
        ai_starts.append(off)
        r["ai"].append([sym, off, b""])          # bytes filled in below
        return sym

    end = len(data)
    if hdr["pathwaypoints"]:
        r["pathwaypoints"] = parse_waypoints(data, hdr["pathwaypoints"], end, aux)
        add(hdr["pathwaypoints"], hdr["pathwaypoints"] + len(r["pathwaypoints"]) * 16,
            "pathwaypoints", "pathwaypoints", r["pathwaypoints"])
    if hdr["waypointgroups"]:
        r["pathsets"] = parse_waygroups(data, hdr["waypointgroups"], end, aux)
        add(hdr["waypointgroups"], hdr["waypointgroups"] + len(r["pathsets"]) * 12,
            "pathsets", "pathsets", r["pathsets"])
    if hdr["patrolpaths"]:
        r["patrolpaths"] = parse_patrolpaths(data, hdr["patrolpaths"], end, aux)
        add(hdr["patrolpaths"], hdr["patrolpaths"] + len(r["patrolpaths"]) * 8,
            "patrolpaths", "patrolpaths", r["patrolpaths"])
    if hdr["ailists"]:
        r["ailists"] = parse_ailists(data, hdr["ailists"], end, block)
        add(hdr["ailists"], hdr["ailists"] + len(r["ailists"]) * 8,
            "ailists", "ailists", r["ailists"])

    # The pad name tables, when the header names them.  When it does not they
    # are still in the file, unreferenced, and the gap pass below picks them up.
    for field, sym in (("padnames", "padnames"), ("boundpadnames", "pad3dnames")):
        if hdr[field]:
            off = o = hdr[field]
            names = []
            while o + 4 <= len(data):
                p = struct.unpack_from(">I", data, o)[0]
                o += 4
                if not p:
                    names.append(None)
                    break
                names.append(cstr(data, p))
                add(p, cstr_end(data, p), "str", None, None)
            r[sym] = names
            add(off, o, "names", sym, names)

    # Every pad name string is its own .rodata object, and they are NOT
    # deduplicated -- Cradle carries "p432d1" twice at two addresses.  They are
    # recorded so the gap pass can tell string storage from a filler block.
    for sym in ("padlist", "pad3dlist"):
        for e in r.get(sym, []):
            if e is None:
                continue
            plink = e[3] if len(e) > 3 else None
            if plink:
                add(plink, cstr_end(data, plink), "str", None, None)

    _close_ai_blocks(data, r, ai_starts, objs)
    _classify_gaps(data, r, objs)
    objs.sort(key=lambda o: (o[0], o[1]))
    return r


def _close_ai_blocks(data, r, ai_starts, objs):
    """Give each AI block the span up to whatever starts next."""
    if not r["ai"]:
        return
    edges = sorted(set(ai_starts) | {o[0] for o in objs if o[0] > min(ai_starts)}
                   | {len(data)})
    for entry in r["ai"]:
        sym, off, _ = entry
        nxt = min(e for e in edges if e > off)
        entry[2] = data[off:nxt]
        objs.append([off, nxt, "ai", sym, entry[2]])


def _classify_gaps(data, r, objs):
    """Whatever no section claims, emitted so it lands back where it was.

    Two kinds, and the difference is that one holds pointers:

      * A NAMES TABLE -- a run of file offsets into the string area, ending
        in a NULL.  assets/obseg/setup/readme.md calls padnames and
        pad3dnames optional and says they "may also consist of data, but be
        unreferenced", which is exactly Cradle: its header has NULL for both
        and the file still carries a 16-entry table at 0x3054 and a 142-entry
        one at 0x4200, 632 bytes between them, with 624 bytes of empty
        strings behind them in .rodata.  Emitted as `char *[]` so the strings
        are emitted too and the pointers come out as addresses rather than as
        stale numbers.

        They are NOT named padnames/pad3dnames here.  Nothing in the file says
        which is which -- the header entry that would is NULL, and neither
        count matches its pad count (15 against 6 bound pads, 141 against 152
        pads).  Getools guessed; this says unref_names_N and leaves it.

      * ANYTHING ELSE -- emitted verbatim as a word or byte array.  Byte-exact,
        because a setup's pointers are plain file offsets and .data links at 0,
        so the bytes ARE the right values.  A credits block reached from an
        intro entry lands here, and so does Jungle's lone `{ -1 }` word.

    A GAP IS PEELED, NOT CLASSIFIED WHOLE.  Jungle's unreferenced padnames runs
    straight into that stray `{ -1 }` with nothing between them, so testing the
    whole run for "ends in NULL" rejected a 118-entry name table over its
    neighbour's four bytes -- and the 472 bytes of empty strings behind it went
    unemitted.  So the front of a gap is matched as a name table up to its own
    NULL terminator, and whatever is left is offered to the same test again.

    Trailing alignment is not a gap: runs shorter than four bytes are the
    padding between strings, and the run at the end of .data is the linker
    aligning .rodata.  Both come back on their own.
    """
    covered = bytearray(len(data))
    for off, end, _, _, _ in objs:
        for i in range(off, min(end, len(data))):
            covered[i] = 1
    data_end = max((o[1] for o in objs if o[2] != "str"), default=0)

    def names_prefix(start, limit):
        """Length of the name table at `start`, terminator included, or 0.

        Every entry has to resolve to a string ABOVE the last .data object --
        that is what separates a table of `char *` from a table of anything
        else, since every other pointer in a setup aims back into .data.
        """
        k = start
        n = 0
        while k + 4 <= limit:
            w = struct.unpack_from(">I", data, k)[0]
            k += 4
            if w == 0:
                return (k - start) if n else 0
            if not (data_end <= w < len(data)):
                return 0
            n += 1
        return 0

    counts = {"names": 0, "data": 0}
    i = 0
    while i < len(data):
        if covered[i]:
            i += 1
            continue
        j = i
        while j < len(data) and not covered[j]:
            j += 1
        # Only .data gaps are ours. Past the last section is .rodata, where a
        # gap is the alignment between two strings.
        if i >= data_end:
            i = j
            continue
        while i < j:
            take = names_prefix(i, j)
            if take:
                words = struct.unpack_from(f">{take // 4}I", data, i)
                names = [cstr(data, w) for w in words[:-1]] + [None]
                sym = f"unref_names_{counts['names']}"
                counts["names"] += 1
                r.setdefault("unref", []).append((sym, names))
                objs.append([i, i + take, "names", sym, names])
                for w in words[:-1]:
                    objs.append([w, cstr_end(data, w), "str", None, None])
                i += take
                continue
            # Not a name table: take the rest of the gap as it stands.
            sym = f"unref_data_{counts['data']}"
            counts["data"] += 1
            objs.append([i, j, "blob", sym, data[i:j]])
            i = j
        i = j


def emit(r, name):
    L = []
    a = L.append
    a("/*")
    a(" * Generated by tools/setup_binary_to_c.py.")
    a(" *")
    a(" * EVERY DEFINITION IS IN THE ORDER IT SAT IN THE ORIGINAL FILE, because")
    a(" * a setup is a pile of internal file offsets and the compiler lays .data")
    a(" * out in source order. Reordering these compiles and links; it does not")
    a(" * round-trip.")
    a(" *")
    a(" * AI bytecode is raw bytes rather than the macros from bondaicommands.h")
    a(" * -- functionally identical, simply unreadable. See the tool docstring.")
    a(" */")
    a("")
    a('#include "ultra64.h"')
    a('#include "bondtypes.h"')
    a('#include "bondaicommands.h"')
    a("")
    missing = [sym for field, sym in FIELDS
               if sym and r["header"][field] and sym not in r]
    if missing:
        a("/* NOT EMITTED, so this file does not compile as it stands:")
        a(" *   " + ", ".join(missing))
        a(" * They point into filler blocks and, for ailists, AI bytecode.")
        a(" * The stagesetup below still references them so the intended shape")
        a(" * is visible; supply them before building. */")
        a("")
    # Forward declarations, and they are not optional: the stagesetup
    # initialiser below takes the address of every table, and four of them are
    # defined after it. Without these, IDO takes the implicit declaration and
    # then rejects the real definition -- "redeclaration of 'patrolpaths'".
    # The committed sources carry exactly this block for the same reason.
    #
    # Only the eight header tables need one. Measured across all 34 setups in
    # the retail ROM: every aux array and every AI block sits BELOW the table
    # that points at it, which is what the readme means by "sequences defined
    # immediately prior to this section".
    a("// forward declarations")
    for field, sym in FIELDS:
        if sym and sym in r:
            a(decl(sym))
    a("")
    a(f"stagesetup {name} = {{")
    for field, sym in FIELDS:
        a(f"    &{sym}," if sym and r["header"][field] else "    NULL,")
    L[-1] = L[-1].rstrip(",")
    a("};")
    a("")

    for off, end, kind, sym, payload in r["objs"]:
        if kind in ("str", "header"):
            continue                  # already written, or written inline
        emit_one(a, kind, sym, payload)
    return "\n".join(L) + "\n"


def emit_one(a, kind, sym, payload):
    """One definition, at the point offset order put it."""
    if kind == "padlist":
        a(f"PadRecord {sym}[] = {{")
        for e in payload:
            if e is None:
                a("    { {0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f}, "
                  "{0.0f, 0.0f, 0.0f}, NULL, 0 }")
                continue
            v, nm, stan, _ = e
            a(f"    {{ {{{f32(v[0])}, {f32(v[1])}, {f32(v[2])}}}, "
              f"{{{f32(v[3])}, {f32(v[4])}, {f32(v[5])}}}, "
              f"{{{f32(v[6])}, {f32(v[7])}, {f32(v[8])}}}, "
              f'{cname(nm)}, {stan} }},')
        a("};")
        a("")

    elif kind == "pad3dlist":
        a(f"BoundPadRecord {sym}[] = {{")
        for e in payload:
            if e is None:
                a("    { {0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f}, "
                  "NULL, 0, {0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f} }")
                continue
            v, nm, stan, _ = e
            # BoundPadRecord is 17 words: pos 0-2, up 3-5, look 6-8,
            # plink 9, stan 10, bbox 11-16. Slicing 9:15 here emitted the two
            # POINTERS as floats -- which IDO flagged as "number outside range
            # for single precision" and which silently corrupted every bbox.
            bb = ", ".join(f32(x) for x in v[11:17])
            a(f"    {{ {{{f32(v[0])}, {f32(v[1])}, {f32(v[2])}}}, "
              f"{{{f32(v[3])}, {f32(v[4])}, {f32(v[5])}}}, "
              f"{{{f32(v[6])}, {f32(v[7])}, {f32(v[8])}}}, "
              f'{cname(nm)}, {stan}, {{{bb}}} }},')
        a("};")
        a("")

    elif kind == "flat":
        a(f"s32 {sym}[] = {{")
        for i in range(0, len(payload), 8):
            a("    " + ", ".join(str(w) for w in payload[i:i + 8]) + ",")
        a("};")
        a("")

    elif kind == "aux":
        a(f"s32 {sym}[] = {{ " + ", ".join(str(v) for v in payload) + " };")
        a("")

    elif kind == "pathsets":
        a(f"waygroup {sym}[] = {{")
        for e in payload:
            if e is None:
                a("    { NULL, NULL, 0 }")
                continue
            nb, wp, dist = e
            a(f"    {{ {'&' + nb if nb else 'NULL'}, "
              f"{'&' + wp if wp else 'NULL'}, {dist} }},")
        a("};")
        a("")

    elif kind == "pathwaypoints":
        a(f"waypoint {sym}[] = {{")
        for e in payload:
            if e is None:
                a("    { 0xffffffff, NULL, 0x00000000, 0x00000000 }")
                continue
            pad, ref, grp, dist = e
            a(f"    {{ {pad:#010x}, {'&' + ref if ref else 'NULL'}, "
              f"{grp:#010x}, {dist:#010x} }},")
        a("};")
        a("")

    elif kind == "patrolpaths":
        a(f"PathRecord {sym}[] = {{")
        for e in payload:
            if e is None:
                a("    { NULL, 0x00, 0x00, 0x0000 }")
                continue
            wp, pid, loop, ln = e
            a(f"    {{ &{wp}, {pid:#04x}, {loop:#04x}, {ln:#06x} }},")
        a("};")
        a("")

    elif kind == "ailists":
        a(f"AIListRecord {sym}[] = {{")
        for e in payload:
            if e is None:
                a("    { NULL, 0x00000000 }")
                continue
            ref, aid = e
            a(f"    {{ &{ref}, {aid:#010x} }},")
        a("};")
        a("")

    elif kind == "ai":
        a(f"u8 {sym}[] = {{")
        for i in range(0, len(payload), 12):
            a("    " + ", ".join(f"0x{b:02x}" for b in payload[i:i + 12]) + ",")
        a("};")
        a("")

    elif kind == "names":
        a(f"char *{sym}[] = {{")
        for nm in payload:
            a(f"    {cname(nm)},")
        a("};")
        a("")

    elif kind == "blob":
        # Unreferenced filler, verbatim: a setup's pointers are file offsets
        # and .data links at 0, so the bytes are already the right values --
        # there is nothing here to relocate.
        #
        # As WORDS when it is a whole number of them, which is both what
        # Getools does (`s32 unknown_setup_block_0[] = { -1 };`) and the safer
        # shape: a u8 array is 1-aligned, so a run that is not a multiple of
        # four would let the compiler pad ahead of the next symbol.
        if len(payload) % 4 == 0:
            words = struct.unpack(f">{len(payload) // 4}i", payload)
            a(f"s32 {sym}[] = {{")
            for i in range(0, len(words), 8):
                a("    " + ", ".join(str(w) for w in words[i:i + 8]) + ",")
        else:
            a(f"u8 {sym}[] = {{")
            for i in range(0, len(payload), 12):
                a("    " + ", ".join(f"0x{b:02x}" for b in payload[i:i + 12]) + ",")
        a("};")
        a("")

    else:
        raise ValueError(f"emit: unknown object kind {kind!r}")


def report(r, path):
    print(f"{os.path.basename(path)}: {r['size']:,} bytes")
    print("  header offsets:")
    for field, sym in FIELDS:
        off = r["header"][field]
        print(f"    {field:<15} {off:#08x}" + (f"  -> {sym}" if sym else "  (NULL)"))
    if "padlist" in r:
        n = len(r["padlist"])
        print(f"  padlist        {n - 1} pads + terminator")
    if "pad3dlist" in r:
        n = len(r["pad3dlist"])
        print(f"  pad3dlist      {n - 1} bound pads + terminator")
    for flat in ("propDefs", "intro"):
        if flat in r:
            print(f"  {flat:<14} {len(r[flat])} words")
    for tbl in ("pathsets", "pathwaypoints", "patrolpaths", "ailists"):
        if tbl in r:
            print(f"  {tbl:<14} {len(r[tbl])} entries (incl. terminator)")
    for sym, names in r.get("unref", []):
        print(f"  {sym:<14} {len(names) - 1} names + terminator "
              f"(unreferenced -- see _classify_gaps)")
    if r.get("aux"):
        print(f"  aux arrays     {len(r['aux'])}")
    if r.get("ai"):
        print(f"  ai blocks      {len(r['ai'])}, "
              f"{sum(len(b) for _, _, b in r['ai'])} bytes")
    # Every byte of the file falls in exactly one emitted object, or in the
    # alignment padding between two. Anything else is a gap the emitter cannot
    # reproduce, and a round trip would fail on it.
    covered = sum(e - s for s, e, k, _, _ in r["objs"])
    print(f"  accounted for  {covered:,} of {r['size']:,} bytes")


def main():
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("input")
    ap.add_argument("output", nargs="?")
    ap.add_argument("--name", help="stagesetup symbol name (default: from filename)")
    ap.add_argument("--report", action="store_true", help="describe, do not emit")
    a = ap.parse_args()

    data = open(a.input, "rb").read()
    try:
        r = parse(data)
    except ValueError as e:
        sys.exit(f"{a.input}: {e}")

    if a.report:
        report(r, a.input)
        return

    name = a.name or os.path.basename(a.input).rsplit(".", 1)[0]
    out = a.output or os.path.splitext(a.input)[0] + ".c"
    open(out, "w").write(emit(r, name))
    report(r, a.input)
    print(f"wrote {out}")


if __name__ == "__main__":
    main()
