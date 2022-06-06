/*
* This file was automatically generated
* 
* Monday, January 17, 2022 9:36:07 AM
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

stagesetup Ump_setupoatZ = {
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
    { {2597.0f, 130.0f, -1427.0f}, {0.0f, 1.0f, 0.0f}, {0.016799f, 0.0f, -0.999859f}, "p1142a", 0 },
    { {2686.0f, 132.0f, -1133.0f}, {0.0f, 1.0f, 0.0f}, {-0.016799f, 0.0f, 0.999859f}, "p3131a", 0 },
    { {2881.0f, 201.0f, -935.0f}, {0.0f, 1.0f, 0.0f}, {-0.016799f, 0.0f, 0.999859f}, "p3315a", 0 },
    { {2765.0f, 195.0f, -678.0f}, {0.0f, 1.0f, 0.0f}, {-0.016799f, 0.0f, 0.999859f}, "p3850a", 0 },
    { {3195.0f, 289.0f, -900.0f}, {0.0f, 1.0f, 0.0f}, {-0.016799f, 0.0f, 0.999859f}, "p3906a", 0 },
    { {3131.0f, 298.0f, -519.0f}, {0.0f, 1.0f, 0.0f}, {-0.016799f, 0.0f, 0.999859f}, "p4127a", 0 },
    { {2897.0f, 130.0f, -1417.0f}, {0.0f, 1.0f, 0.0f}, {-0.016799f, 0.0f, 0.999859f}, "p2412a", 0 },
    { {2909.0f, 189.0f, -1392.0f}, {0.0f, 1.0f, 0.0f}, {-0.016799f, 0.0f, 0.999859f}, "p2441a", 0 },
    { {2556.0f, 130.0f, -1436.0f}, {0.0f, 1.0f, 0.0f}, {-0.999859f, 0.0f, -0.016799f}, "p1140a", 0 },
    { {2644.0f, 130.0f, -1441.0f}, {0.0f, 1.0f, 0.0f}, {-0.999859f, 0.0f, -0.016799f}, "p1154a", 0 },
    { {2709.0f, 128.0f, -1163.0f}, {0.0f, 1.0f, 0.0f}, {-0.999859f, 0.0f, -0.016799f}, "p3128a", 0 },
    { {2675.0f, 130.0f, -1102.0f}, {0.0f, 1.0f, 0.0f}, {-0.999859f, 0.0f, -0.016799f}, "p3131a", 0 },
    { {2902.0f, 201.0f, -900.0f}, {0.0f, 1.0f, 0.0f}, {-0.999859f, 0.0f, -0.016799f}, "p3316a", 0 },
    { {2860.0f, 203.0f, -973.0f}, {0.0f, 1.0f, 0.0f}, {-0.016799f, 0.0f, 0.999859f}, "p3322a", 0 },
    { {2800.0f, 197.0f, -652.0f}, {0.0f, 1.0f, 0.0f}, {-0.016799f, 0.0f, 0.999859f}, "p3848a", 0 },
    { {2730.0f, 195.0f, -698.0f}, {0.0f, 1.0f, 0.0f}, {-0.999859f, 0.0f, -0.016799f}, "p3844a", 0 },
    { {3181.0f, 288.0f, -933.0f}, {0.0f, 1.0f, 0.0f}, {-0.999859f, 0.0f, -0.016799f}, "p3911a", 0 },
    { {3182.0f, 288.0f, -858.0f}, {0.0f, 1.0f, 0.0f}, {-0.999859f, 0.0f, -0.016799f}, "p3907a", 0 },
    { {3089.0f, 296.0f, -524.0f}, {0.0f, 1.0f, 0.0f}, {-0.999859f, 0.0f, -0.016799f}, "p4124a", 0 },
    { {3191.0f, 296.0f, -522.0f}, {0.0f, 1.0f, 0.0f}, {-0.999859f, 0.0f, -0.016799f}, "p4130a", 0 },
    { {2998.0f, 132.0f, -1470.0f}, {0.0f, 1.0f, 0.0f}, {-0.999859f, 0.0f, -0.016799f}, "p2422a", 0 },
    { {3044.0f, 132.0f, -1388.0f}, {0.0f, 1.0f, 0.0f}, {0.999859f, 0.0f, 0.016799f}, "p2432a", 0 },
    { {2902.0f, 191.0f, -1322.0f}, {0.0f, 1.0f, 0.0f}, {-0.999859f, 0.0f, -0.016799f}, "p2444a", 0 },
    { {2811.0f, 191.0f, -1260.0f}, {0.0f, 1.0f, 0.0f}, {-0.999859f, 0.0f, -0.016799f}, "p2454a", 0 },
    { {2601.0f, 130.0f, -1469.0f}, {0.0f, 1.0f, 0.0f}, {-0.016799f, 0.0f, 0.999859f}, "p1155a", 0 },
    { {2467.0f, 128.0f, -1165.0f}, {0.0f, 1.0f, 0.0f}, {0.999859f, 0.0f, 0.016799f}, "p3121a", 0 },
    { {2795.0f, 199.0f, -925.0f}, {0.0f, 1.0f, 0.0f}, {0.999859f, 0.0f, 0.016798f}, "p3304a", 0 },
    { {2725.0f, 193.0f, -650.0f}, {0.0f, 1.0f, 0.0f}, {0.718927f, 0.0f, -0.695086f}, "p3846a", 0 },
    { {3195.0f, 286.0f, -815.0f}, {0.0f, 1.0f, 0.0f}, {0.016799f, 0.0f, -0.999859f}, "p4098a", 0 },
    { {3124.0f, 296.0f, -455.0f}, {0.0f, 1.0f, 0.0f}, {0.016799f, 0.0f, -0.999859f}, "p4156a", 0 },
    { {2972.0f, 130.0f, -1432.0f}, {0.0f, 1.0f, 0.0f}, {-0.999859f, 0.0f, -0.016798f}, "p2421a", 0 },
    { {2886.0f, 191.0f, -1275.0f}, {0.0f, 1.0f, 0.0f}, {-0.016799f, 0.0f, 0.999859f}, "p2457a", 0 },
    { {2589.0f, 130.0f, -1278.0f}, {0.0f, 1.0f, 0.0f}, {-0.999859f, 0.0f, -0.016799f}, "p3172a", 0 },
    { {2790.0f, 206.0f, -1527.0f}, {0.0f, 1.0f, 0.0f}, {-0.999859f, 0.0f, -0.016799f}, "p1175a", 0 },
    { {2885.0f, 289.0f, -832.0f}, {0.0f, 1.0f, 0.0f}, {-0.999859f, 0.0f, -0.016799f}, "p3599a", 0 },
    { {0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f}, NULL, 0 }
};


BoundPadRecord pad3dlist[] = {
    { {0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f}, NULL, 0, {0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f} }
};


s32 propDefs[] = {
    /* Type = Collectable; index = 0 */
    _mkword(256, _mkshort(0, 8)), _mkword(333, 32), 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0, _mkword(_mkshort(0x58, 0xff), 0xffff), 0,
    /* Type = Collectable; index = 1 */
    _mkword(512, _mkshort(0, 8)), _mkword(0, 0), 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0, _mkword(_mkshort(0xf0, 0xff), 0xffff), 0,
    /* Type = AmmoBox; index = 2 */
    _mkword(153, _mkshort(0, 20)), _mkword(5, 8), 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0, _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0),
    /* Type = AmmoBox; index = 3 */
    _mkword(153, _mkshort(0, 20)), _mkword(5, 9), 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0, _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0),
    /* Type = Collectable; index = 4 */
    _mkword(512, _mkshort(0, 8)), _mkword(0, 1), 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0, _mkword(_mkshort(0xf1, 0xff), 0xffff), 0,
    /* Type = AmmoBox; index = 5 */
    _mkword(153, _mkshort(0, 20)), _mkword(5, 10), 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0, _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0),
    /* Type = AmmoBox; index = 6 */
    _mkword(153, _mkshort(0, 20)), _mkword(5, 11), 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0, _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0),
    /* Type = Collectable; index = 7 */
    _mkword(307, _mkshort(0, 8)), _mkword(0, 2), 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0, _mkword(_mkshort(0xf2, 0xff), 0xffff), 0,
    /* Type = AmmoBox; index = 8 */
    _mkword(153, _mkshort(0, 20)), _mkword(5, 12), 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0, _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0),
    /* Type = AmmoBox; index = 9 */
    _mkword(153, _mkshort(0, 20)), _mkword(5, 13), 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0, _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0),
    /* Type = Collectable; index = 10 */
    _mkword(307, _mkshort(0, 8)), _mkword(0, 6), 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0, _mkword(_mkshort(0xf3, 0xff), 0xffff), 0,
    /* Type = AmmoBox; index = 11 */
    _mkword(153, _mkshort(0, 20)), _mkword(5, 20), 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0, _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0),
    /* Type = AmmoBox; index = 12 */
    _mkword(153, _mkshort(0, 20)), _mkword(5, 21), 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0, _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0),
    /* Type = Collectable; index = 13 */
    _mkword(307, _mkshort(0, 8)), _mkword(0, 4), 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0, _mkword(_mkshort(0xf4, 0xff), 0xffff), 0,
    /* Type = AmmoBox; index = 14 */
    _mkword(153, _mkshort(0, 20)), _mkword(5, 16), 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0, _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0),
    /* Type = AmmoBox; index = 15 */
    _mkword(153, _mkshort(0, 20)), _mkword(5, 17), 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0, _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0),
    /* Type = Collectable; index = 16 */
    _mkword(307, _mkshort(0, 8)), _mkword(0, 5), 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0, _mkword(_mkshort(0xf5, 0xff), 0xffff), 0,
    /* Type = AmmoBox; index = 17 */
    _mkword(153, _mkshort(0, 20)), _mkword(5, 18), 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0, _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0),
    /* Type = AmmoBox; index = 18 */
    _mkword(153, _mkshort(0, 20)), _mkword(5, 19), 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0, _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0),
    /* Type = Collectable; index = 19 */
    _mkword(307, _mkshort(0, 8)), _mkword(0, 3), 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0, _mkword(_mkshort(0xf6, 0xff), 0xffff), 0,
    /* Type = AmmoBox; index = 20 */
    _mkword(153, _mkshort(0, 20)), _mkword(5, 14), 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0, _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0),
    /* Type = AmmoBox; index = 21 */
    _mkword(153, _mkshort(0, 20)), _mkword(5, 15), 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0, _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0),
    /* Type = Collectable; index = 22 */
    _mkword(307, _mkshort(0, 8)), _mkword(0, 7), 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0, _mkword(_mkshort(0xf7, 0xff), 0xffff), 0,
    /* Type = AmmoBox; index = 23 */
    _mkword(153, _mkshort(0, 20)), _mkword(5, 22), 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0, _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0),
    /* Type = AmmoBox; index = 24 */
    _mkword(153, _mkshort(0, 20)), _mkword(5, 23), 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0, _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0),
    /* Type = Armour; index = 25 */
    _mkword(384, _mkshort(0, 21)), _mkword(115, 33), 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0, 65536, 0,
    /* Type = Armour; index = 26 */
    _mkword(384, _mkshort(0, 21)), _mkword(115, 34), 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0, 65536, 0,
    /* Type = EndProps; index = 27 */
    _mkword(0, _mkshort(0, 48))
};


s32 intro[] = {
    /* Type = Spawn; index = 0 */
    _mkword(0, _mkshort(0, 0)), 24, 0,
    /* Type = Spawn; index = 1 */
    _mkword(0, _mkshort(0, 0)), 25, 0,
    /* Type = Spawn; index = 2 */
    _mkword(0, _mkshort(0, 0)), 26, 0,
    /* Type = Spawn; index = 3 */
    _mkword(0, _mkshort(0, 0)), 27, 0,
    /* Type = Spawn; index = 4 */
    _mkword(0, _mkshort(0, 0)), 28, 0,
    /* Type = Spawn; index = 5 */
    _mkword(0, _mkshort(0, 0)), 29, 0,
    /* Type = Spawn; index = 6 */
    _mkword(0, _mkshort(0, 0)), 30, 0,
    /* Type = Spawn; index = 7 */
    _mkword(0, _mkshort(0, 0)), 31, 0,
    /* Type = StartWeapon; index = 8 */
    _mkword(0, _mkshort(0, 1)), 1, -1, 0,
    /* Type = Cuff; index = 9 */
    _mkword(0, _mkshort(0, 5)), 3,
    /* Type = EndIntro; index = 10 */
    _mkword(0, _mkshort(0, 9))
};


s32 unknown_setup_block_0[] = { -1, -1 };


waygroup pathsets[] = {
    { NULL, NULL, 0 }
};


s32 unknown_setup_block_1[] = { -1 };


waypoint pathwaypoints[] = {
    { 0xffffffff, NULL, 0x00000000, 0x00000000 }
};


s32 unknown_setup_block_2[] = { -1 };


PathRecord patrolpaths[] = {
    { NULL, 0x00, 0x00, 0x0000 }
};


u32 ai_not_used_0[] = { 0x04000000 };



AIListRecord ailists[] = {
    /* index = 0 */
    { NULL, 0x00000000 }
};




