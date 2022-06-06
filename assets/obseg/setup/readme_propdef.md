# Object / Propdef Readme

This file desribes how items in the setup objects list are used in the game.

Items are described by the `enum PROPDEF_TYPE`. There are various kinds of objects that can be listed:

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

Level objects are just blank structs ready to be used by the game. For instance, the structs have position fields that are zero in the setup file but are set (and updated) when the level is loaded and active. The only exception to this is guards (characters) which are copied to a much larger character struct on level load.

# Item Location

If an item is to be placed at a specific coordinate, it will be associated with a "preset location". This is the second half of the second word in the item `propdef`. This preset id is an index into the `padlist`. The pad contains the position (and `up` and `orientiation` vectors) to describe where the item will be placed. The pad also contains an associated stan tile name. A brief example:

UsetuprunZ.c

    s32 objlist[] = {
        /* Type = AmmoBox; index = 99 */
        _mkword(128, _mkshort(0, 20)), _mkword(4, 24) ...

    struct pad padlist[] = {
        /* index = 24 */
        { {683.0f, -38.0f, -467.0f}, {0.0f, 1.0f, 0.0f}, {0.002546f, 0.0f, 0.999997f}, "p3830a", 0 },

Tbg_run_all_p_stanZ.c

    StandTile tile_429 = {
        0x0ef600, 0x04,
        0x0,
        0xf, 0xf, 0xf,
        3,
        0x0, 0x1, 0x2,
        {
            {701, -41, -446, 0x06d1},
            {710, -41, -472, 0x0000},
            {665, -41, -472, 0x06c9}
        }
    };

Here the Runway ammobox is associated to preset 24, so it will use the coordinates from pad with index 24. The pad has link "p3830a", which refers to tile name 3830, or in hex, 0x0ef6.