/*
* This file was automatically generated
* 
* Monday, January 17, 2022 9:36:06 AM
* Getools.Lib: 21.9.18.1
*/

#include "ultra64.h"
#include "bondtypes.h"

// forward declarations
PadRecord padlist[];
BoundPadRecord pad3dlist[];
s32 propDefs[];
s32 intro[];
waygroup pathsets[];
waypoint pathwaypoints[];
PathRecord patrolpaths[];
AIListRecord ailists[];

stagesetup Ump_setupdishZ = {
    &pathwaypoints,
    &pathsets,
    &intro,
    &propDefs,
    &patrolpaths,
    &ailists,
    &padlist,
    &pad3dlist,
    NULL,
    NULL
};

PadRecord padlist[] = {
    { {-972.0f, 47.0f, 135.0f}, {0.0f, 1.0f, 0.0f}, {0.016799f, 0.0f, -0.999859f}, "p230a1", 0 },
    { {-1246.0f, 47.0f, -128.0f}, {0.0f, 1.0f, 0.0f}, {-0.016799f, 0.0f, 0.999859f}, "p229a2", 0 },
    { {-1250.0f, 27.0f, -1137.0f}, {0.0f, 1.0f, 0.0f}, {-0.016799f, 0.0f, 0.999859f}, "p223a1", 0 },
    { {-1032.0f, 27.0f, -1321.0f}, {0.0f, 1.0f, 0.0f}, {-0.016799f, 0.0f, 0.999859f}, "p224a1", 0 },
    { {805.0f, 47.0f, -1032.0f}, {0.0f, 1.0f, 0.0f}, {-0.016799f, 0.0f, 0.999859f}, "p192a1", 0 },
    { {514.0f, 47.0f, -766.0f}, {0.0f, 1.0f, 0.0f}, {-0.016799f, 0.0f, 0.999859f}, "p190a2", 0 },
    { {964.0f, 249.0f, 3.0f}, {0.0f, 1.0f, 0.0f}, {-0.016799f, 0.0f, 0.999859f}, "p238a2", 0 },
    { {2086.0f, 0.0f, 721.0f}, {0.0f, 1.0f, 0.0f}, {-0.016799f, 0.0f, 0.999859f}, "p211a1", 0 },
    { {1873.0f, 0.0f, -286.0f}, {0.0f, 1.0f, 0.0f}, {-0.016799f, 0.0f, 0.999859f}, "p206a2", 0 },
    { {1621.0f, 0.0f, -654.0f}, {0.0f, 1.0f, 0.0f}, {-0.016799f, 0.0f, 0.999859f}, "p198a1", 0 },
    { {-354.0f, 0.0f, 540.0f}, {0.0f, 1.0f, 0.0f}, {-0.016799f, 0.0f, 0.999859f}, "p256a", 0 },
    { {214.0f, 0.0f, 547.0f}, {0.0f, 1.0f, 0.0f}, {-0.016799f, 0.0f, 0.999859f}, "p257a", 0 },
    { {176.0f, 0.0f, -441.0f}, {0.0f, 1.0f, 0.0f}, {-0.016799f, 0.0f, 0.999859f}, "p341a1", 0 },
    { {137.0f, 411.0f, -1428.0f}, {0.0f, 1.0f, 0.0f}, {-0.016799f, 0.0f, 0.999859f}, "p184a1", 0 },
    { {-192.0f, 411.0f, -854.0f}, {0.0f, 1.0f, 0.0f}, {-0.016799f, 0.0f, 0.999859f}, "p183a1", 0 },
    { {-89.0f, 411.0f, 398.0f}, {0.0f, 1.0f, 0.0f}, {-0.016799f, 0.0f, 0.999859f}, "p180a2", 0 },
    { {1609.0f, 0.0f, -77.0f}, {0.0f, 1.0f, 0.0f}, {-0.999859f, 0.0f, -0.016799f}, "p206a2", 0 },
    { {1991.0f, 0.0f, -805.0f}, {0.0f, 1.0f, 0.0f}, {-0.999859f, 0.0f, -0.016799f}, "p198a1", 0 },
    { {2119.0f, 0.0f, -1510.0f}, {0.0f, 1.0f, 0.0f}, {-0.999859f, 0.0f, -0.016799f}, "p205a2", 0 },
    { {1113.0f, 249.0f, 28.0f}, {0.0f, 1.0f, 0.0f}, {-0.999859f, 0.0f, -0.016799f}, "p237a1", 0 },
    { {1113.0f, 249.0f, 155.0f}, {0.0f, 1.0f, 0.0f}, {-0.999859f, 0.0f, -0.016799f}, "p237a2", 0 },
    { {509.0f, 47.0f, -903.0f}, {0.0f, 1.0f, 0.0f}, {-0.016799f, 0.0f, 0.999859f}, "p190a1", 0 },
    { {659.0f, 47.0f, -753.0f}, {0.0f, 1.0f, 0.0f}, {-0.016799f, 0.0f, 0.999859f}, "p191a", 0 },
    { {-350.0f, 411.0f, -1413.0f}, {0.0f, 1.0f, 0.0f}, {-0.999859f, 0.0f, -0.016799f}, "p184a1", 0 },
    { {-350.0f, 411.0f, -1270.0f}, {0.0f, 1.0f, 0.0f}, {-0.999859f, 0.0f, -0.016799f}, "p184a1", 0 },
    { {-350.0f, 411.0f, -1143.0f}, {0.0f, 1.0f, 0.0f}, {-0.999859f, 0.0f, -0.016799f}, "p184a1", 0 },
    { {-372.0f, 411.0f, 178.0f}, {0.0f, 1.0f, 0.0f}, {-0.999859f, 0.0f, -0.016799f}, "p180a1", 0 },
    { {243.0f, 411.0f, 328.0f}, {0.0f, 1.0f, 0.0f}, {-0.999859f, 0.0f, -0.016799f}, "p180a2", 0 },
    { {243.0f, 411.0f, 455.0f}, {0.0f, 1.0f, 0.0f}, {-0.999859f, 0.0f, -0.016799f}, "p180a2", 0 },
    { {-950.0f, 47.0f, -138.0f}, {0.0f, 1.0f, 0.0f}, {-0.999859f, 0.0f, -0.016799f}, "p230a2", 0 },
    { {-1253.0f, 47.0f, 147.0f}, {0.0f, 1.0f, 0.0f}, {0.999859f, 0.0f, 0.016799f}, "p229a1", 0 },
    { {-957.0f, 27.0f, -723.0f}, {0.0f, 1.0f, 0.0f}, {-0.999859f, 0.0f, -0.016799f}, "p224a2", 0 },
    { {-785.0f, 27.0f, -978.0f}, {0.0f, 1.0f, 0.0f}, {-0.999859f, 0.0f, -0.016799f}, "p225a2", 0 },
    { {-1205.0f, 27.0f, -1330.0f}, {0.0f, 1.0f, 0.0f}, {-0.999859f, 0.0f, -0.016799f}, "p223a1", 0 },
    { {-357.0f, 411.0f, 1326.0f}, {0.0f, 1.0f, 0.0f}, {-0.999859f, 0.0f, -0.016799f}, "p166a1", 0 },
    { {251.0f, 411.0f, 1326.0f}, {0.0f, 1.0f, 0.0f}, {-0.999859f, 0.0f, -0.016799f}, "p168a1", 0 },
    { {243.0f, -145.0f, 455.0f}, {0.0f, 1.0f, 0.0f}, {-0.999859f, 0.0f, -0.016799f}, "p257a", 0 },
    { {-27.0f, -145.0f, -445.0f}, {0.0f, 1.0f, 0.0f}, {-0.999859f, 0.0f, -0.016799f}, "p341a2", 0 },
    { {251.0f, -145.0f, -168.0f}, {0.0f, 1.0f, 0.0f}, {-0.999859f, 0.0f, -0.016799f}, "p336a1", 0 },
    { {-380.0f, -145.0f, -145.0f}, {0.0f, 1.0f, 0.0f}, {-0.999859f, 0.0f, -0.016799f}, "p333a1", 0 },
    { {-50.0f, -145.0f, 125.0f}, {0.0f, 1.0f, 0.0f}, {-0.999859f, 0.0f, -0.016799f}, "p254a2", 0 },
    { {0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f}, NULL, 0 }
};


BoundPadRecord pad3dlist[] = {
    { {843.0f, 73.0f, -441.0f}, {-1.0f, 0.0f, 0.0f}, {0.0f, 1.0f, 0.0f}, "p194a1", 0, {-73.000015f, 74.00001f, -39.00001f, 108.000015f, -73.0f, 231.0f} },
    { {337.0f, 294.0f, -1618.0f}, {-1.0f, 0.0f, 0.0f}, {0.0f, 1.0f, 0.0f}, "p186a2", 0, {-74.00001f, 73.00001f, -16.000004f, 43.000004f, -73.0f, 221.0f} },
    { {337.0f, 294.0f, 735.0f}, {-1.0f, 0.0f, 0.0f}, {0.0f, 1.0f, 0.0f}, "p176a2", 0, {-74.00001f, 73.00001f, -16.000004f, 43.000004f, -73.0f, 221.0f} },
    { {-484.0f, 294.0f, 735.0f}, {1.0f, 0.0f, 0.0f}, {0.0f, 1.0f, 0.0f}, "p177a1", 0, {-73.00001f, 74.00001f, -16.000006f, 43.000008f, -73.0f, 221.0f} },
    { {-484.0f, 294.0f, -441.0f}, {1.0f, 0.0f, 0.0f}, {0.0f, 1.0f, 0.0f}, "p217a1", 0, {-74.00001f, 73.00001f, -16.000006f, 43.000008f, -73.0f, 221.0f} },
    { {-1250.0f, 73.0f, -558.0f}, {0.0f, 0.0f, 1.0f}, {0.0f, 1.0f, 0.0f}, "p222a2", 0, {-74.00001f, 74.00001f, -16.000006f, 43.000008f, -73.0f, 221.0f} },
    { {0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f}, NULL, 0, {0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f} }
};


s32 propDefs[] = {
    /* Type = Collectable; index = 0 */
    _mkword(256, _mkshort(0, 8)), _mkword(333, 27), 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0, _mkword(_mkshort(0x58, 0xff), 0xffff), 0,
    /* Type = Collectable; index = 1 */
    _mkword(256, _mkshort(0, 8)), _mkword(0, 0), 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0, _mkword(_mkshort(0xf0, 0xff), 0xffff), 0,
    /* Type = AmmoBox; index = 2 */
    _mkword(256, _mkshort(0, 20)), _mkword(5, 29), 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0, _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0),
    /* Type = AmmoBox; index = 3 */
    _mkword(256, _mkshort(0, 20)), _mkword(5, 30), 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0, _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0),
    /* Type = Collectable; index = 4 */
    _mkword(256, _mkshort(0, 8)), _mkword(0, 26), 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0, _mkword(_mkshort(0xf1, 0xff), 0xffff), 0,
    /* Type = AmmoBox; index = 5 */
    _mkword(256, _mkshort(0, 20)), _mkword(5, 31), 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0, _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0),
    /* Type = AmmoBox; index = 6 */
    _mkword(256, _mkshort(0, 20)), _mkword(5, 32), 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0, _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0),
    /* Type = Collectable; index = 7 */
    _mkword(256, _mkshort(0, 8)), _mkword(0, 2), 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0, _mkword(_mkshort(0xf2, 0xff), 0xffff), 0,
    /* Type = AmmoBox; index = 8 */
    _mkword(256, _mkshort(0, 20)), _mkword(5, 19), 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0, _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0),
    /* Type = AmmoBox; index = 9 */
    _mkword(256, _mkshort(0, 20)), _mkword(5, 20), 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0, _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0),
    /* Type = Collectable; index = 10 */
    _mkword(256, _mkshort(0, 8)), _mkword(0, 6), 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0, _mkword(_mkshort(0xf3, 0xff), 0xffff), 0,
    /* Type = AmmoBox; index = 11 */
    _mkword(256, _mkshort(0, 20)), _mkword(5, 31), 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0, _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0),
    /* Type = AmmoBox; index = 12 */
    _mkword(256, _mkshort(0, 20)), _mkword(5, 32), 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0, _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0),
    /* Type = Collectable; index = 13 */
    _mkword(256, _mkshort(0, 8)), _mkword(0, 5), 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0, _mkword(_mkshort(0xf4, 0xff), 0xffff), 0,
    /* Type = AmmoBox; index = 14 */
    _mkword(256, _mkshort(0, 20)), _mkword(5, 21), 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0, _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0),
    /* Type = AmmoBox; index = 15 */
    _mkword(256, _mkshort(0, 20)), _mkword(5, 22), 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0, _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0),
    /* Type = Collectable; index = 16 */
    _mkword(256, _mkshort(0, 8)), _mkword(0, 13), 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0, _mkword(_mkshort(0xf5, 0xff), 0xffff), 0,
    /* Type = AmmoBox; index = 17 */
    _mkword(256, _mkshort(0, 20)), _mkword(5, 23), 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0, _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0),
    /* Type = AmmoBox; index = 18 */
    _mkword(256, _mkshort(0, 20)), _mkword(5, 25), 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0, _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0),
    /* Type = Collectable; index = 19 */
    _mkword(256, _mkshort(0, 8)), _mkword(0, 8), 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0, _mkword(_mkshort(0xf6, 0xff), 0xffff), 0,
    /* Type = AmmoBox; index = 20 */
    _mkword(256, _mkshort(0, 20)), _mkword(5, 17), 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0, _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0),
    /* Type = AmmoBox; index = 21 */
    _mkword(256, _mkshort(0, 20)), _mkword(5, 25), 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0, _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0),
    /* Type = Collectable; index = 22 */
    _mkword(256, _mkshort(0, 8)), _mkword(0, 40), 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0, _mkword(_mkshort(0xf7, 0xff), 0xffff), 0,
    /* Type = AmmoBox; index = 23 */
    _mkword(256, _mkshort(0, 20)), _mkword(5, 38), 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0, _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0),
    /* Type = AmmoBox; index = 24 */
    _mkword(256, _mkshort(0, 20)), _mkword(5, 39), 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0, _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0),
    /* Type = Armour; index = 25 */
    _mkword(384, _mkshort(0, 21)), _mkword(115, 7), 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0, 65536, 0,
    /* Type = Door; index = 26 */
    _mkword(256, _mkshort(0, 1)), _mkword(171, 0), 0x10000000, 0x80000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0, 0x00000000, 0x0000f333, 0x0000551e, 0x0000000a, 0x0000000a, 0x000000da, _mkword(4, 4), 0x00000000, 1500, 15, 0.0f, 0, 0, 0, 0.0f, _mkword(0, 0), 0, _mkword(0, _mkshort(0, 0)), 0x00000000, _mkword(_mkshort(0, 0), 0), 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    /* Type = Door; index = 27 */
    _mkword(256, _mkshort(0, 1)), _mkword(171, 1), 0x10000000, 0x80000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0, 0x00000000, 0x0000f333, 0x0000551e, 0x0000000a, 0x0000000a, 0x000000da, _mkword(4, 4), 0x00000000, 1500, 15, 0.0f, 0, 0, 0, 0.0f, _mkword(0, 0), 0, _mkword(0, _mkshort(0, 0)), 0x00000000, _mkword(_mkshort(0, 0), 0), 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    /* Type = Door; index = 28 */
    _mkword(256, _mkshort(0, 1)), _mkword(171, 2), 0x10000000, 0x80000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0, 0x00000000, 0x0000f333, 0x0000551e, 0x0000000a, 0x0000000a, 0x000000da, _mkword(4, 4), 0x00000000, 1500, 15, 0.0f, 0, 0, 0, 0.0f, _mkword(0, 0), 0, _mkword(0, _mkshort(0, 0)), 0x00000000, _mkword(_mkshort(0, 0), 0), 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    /* Type = Door; index = 29 */
    _mkword(256, _mkshort(0, 1)), _mkword(171, 3), 0x10000000, 0x80000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0, 0x00000000, 0x0000f333, 0x0000551e, 0x0000000a, 0x0000000a, 0x000000da, _mkword(4, 4), 0x00000000, 1500, 15, 0.0f, 0, 0, 0, 0.0f, _mkword(0, 0), 0, _mkword(0, _mkshort(0, 0)), 0x00000000, _mkword(_mkshort(0, 0), 0), 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    /* Type = Door; index = 30 */
    _mkword(256, _mkshort(0, 1)), _mkword(171, 4), 0x10000000, 0x80000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0, 0x00000000, 0x0000f333, 0x0000551e, 0x0000000a, 0x0000000a, 0x000000da, _mkword(4, 4), 0x00000000, 1500, 15, 0.0f, 0, 0, 0, 0.0f, _mkword(0, 0), 0, _mkword(0, _mkshort(0, 0)), 0x00000000, _mkword(_mkshort(0, 0), 0), 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    /* Type = Door; index = 31 */
    _mkword(256, _mkshort(0, 1)), _mkword(171, 5), 0x10000000, 0x80000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0, 0x00000000, 0x0000f333, 0x0000551e, 0x0000000a, 0x0000000a, 0x000000da, _mkword(4, 4), 0x00000000, 1500, 15, 0.0f, 0, 0, 0, 0.0f, _mkword(0, 0), 0, _mkword(0, _mkshort(0, 0)), 0x00000000, _mkword(_mkshort(0, 0), 0), 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    /* Type = EndProps; index = 32 */
    _mkword(0, _mkshort(0, 48))
};


s32 intro[] = {
    /* Type = Spawn; index = 0 */
    _mkword(0, _mkshort(0, 0)), 1, 0,
    /* Type = Spawn; index = 1 */
    _mkword(0, _mkshort(0, 0)), 3, 0,
    /* Type = Spawn; index = 2 */
    _mkword(0, _mkshort(0, 0)), 4, 0,
    /* Type = Spawn; index = 3 */
    _mkword(0, _mkshort(0, 0)), 9, 0,
    /* Type = Spawn; index = 4 */
    _mkword(0, _mkshort(0, 0)), 15, 0,
    /* Type = StartWeapon; index = 5 */
    _mkword(0, _mkshort(0, 1)), 1, -1, 0,
    /* Type = Cuff; index = 6 */
    _mkword(0, _mkshort(0, 5)), 2,
    /* Type = EndIntro; index = 7 */
    _mkword(0, _mkshort(0, 9))
};


waygroup pathsets[] = {
    { NULL, NULL, 0 }
};


waypoint pathwaypoints[] = {
    { 0xffffffff, NULL, 0x00000000, 0x00000000 }
};


PathRecord patrolpaths[] = {
    { NULL, 0x00, 0x00, 0x0000 }
};


AIListRecord ailists[] = {
    /* index = 0 */
    { NULL, 0x00000000 }
};




