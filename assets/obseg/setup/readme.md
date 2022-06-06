# Setup File Readme

Known as `setup`. Setups contain the mission scripting logic, AI Scripting, object information, Pad and Portal placement, guard paths and nav mesh, intro camera and cutscene configuration, and the end credits.

Values are stored most significant byte first.

## Definitions

This readme uses the term "section" to refer to a continuous sequence of bytes in the setup file. There are "main" sections which are referenced by the pointer in the header. Seperate from "main" sections are "filler" sections, which lie in between main sections. This usually consists of data referenced by a main section.

If a section (sequence of bytes) is not referenced by anything in the setup file it will be referred to as "unreferenced". A main section can be unreferenced, such as the `padnames`. More common, a filler section is unreferenced e.g., multiplayer maps empty/unused nav mesh.

# File Strucutre

The file always starts with the header, followed by the padlist and pad3dlist sections. If there is a credits data block, it should follow the pad3dlist section. Next are the object and intro sections.

The remaining sections and data can appear in various order.

## Header

The header consists of a data structure of 10 pointers in the following order:

- path table section
- path link section (path list section)
- intro block
- object / propdef / objective section
- path sets section
- AI List section
- pad list section
- pad3d list section
- pad names section
- pad3d names section

## Pad List Section 

List of sequence of pads. Does not reference any data outside this section. Always ends with an empty entry

    { {0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f}, NULL, 0 }

## Pad3d List Section 

List of sequence of pad3ds. Does not reference any data outside this section. Always ends with an empty entry  

    { {0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f}, NULL, 0, {0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f} }

## Object / Objective Section

Each entry is specified by type `enum PROPDEF_TYPE`. This section lists

- guards (and hats)
- props (doors, vehicle, tank, monitor, etc)
- collectibles (body armor, ammo, weapons, items in safe, etc)
- objectives
- autogun / drones
- CCTV / surveilance cameras
- keys, locked doors, and locks
- glass
- watch menu text
- poison gas (facility)
- meta items (rename, link, switch)
- meta programming (tag, `PROPDEF_END`)

This section does not reference any data outside this section. The section always ends with a propdef entry with type `PROPDEF_END`.

## Intro Section

Each entry is specified by type `enum INTRO_TYPE`. This section describes  

- Spawn location
- Starting inventory and ammo amounts
- Opening cinemas and camera locations
- Bond's outfit (cuffs)
- Special flag to mark as credits

The "credits" type can reference data outside this section, otherwise all data is contained within the section itself. The section always ends with a propdef entry with type `INTROTYPE_END`.

### Intro: Animation

Discord comment:
> Animation is used by Bond during the intro swirl process. It's actually a bunch of preset values for each animation. To get around this limitations, some setups such as Silo will instead not set an animation used for the intro swirl, but will have a dedicated AI list that'll just watch for when the intro swirl has triggered, and then trigger an animation that isn't selectable by the intro block animation's range. Sometimes this is used because the intro swirl is quite long, so some manual timing is required via AI list.

### Intro: Credits

A "credits" type intro entry consists of a single pointer to a block of credits data. This just a list of (global) text ids with alignment and position info. See `CreditsEntry` for struct layout.

The credits block ends with an empty entry  

    { 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000 }

## Path Table Section

List of sequence of path tables. Elements will reference variables defined immediately prior to this section. Always ends with an empty entry  

    { 0xffff, 0xffff, NULL, 0x00000000, 0x00000000 }

## Path Link Section

List of sequence of path links. Elements will reference variables defined immediately prior to this section. Always ends with an empty entry  

    { NULL, NULL, 0 }

## Path Sets Section

List of sequence of path sets. Elements will reference variables defined immediately prior to this section. Always ends with an empty entry  

    { NULL, 0x00000000 }

## Padnames Section

List of sequence of pad names. This section is optional. It may also consist of data, but be unreferenced. This section references strings in .rodata. If present, the section always ends with a single `NULL` entry.

## Pad3dnames Section

List of sequence of pad3d names. This section is optional. It may also consist of data, but be unreferenced. This section references strings in .rodata. If present, the section always ends with a single `NULL` entry.

## AI List Section

List of pointers and ids to AI functions. These are used by guards or as part of the level. Elements will reference sequences defined immediately prior to this section; sequences are word aligned, but the last data value in the sequence is a single byte `0x04`. The AI List ends with an empty entry  

    { NULL, 0x00000000 }

## Filler Blocks

Occasionally a main section will be empty except the "end of sequence" entry (e.g., multiplayer setups). The area immediately prior to the main section then might have an unreferenced/unused sequence of data. This is usually only one or two bytes, of either `{ 0 }` or `{ -1 }`. The AI List entries block may lead with an unreferenced AI Function, the single byte `0x04` (word aligned / zero padded).

## .rodata

The .bin file will end with the .rodata section consisting of the strings used in padlist, pad3dlist, padnames, and pad3dnames.