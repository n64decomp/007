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

stagesetup Ump_setuprefZ = {
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
    { {-5.0f, 586.0f, 767.0f}, {0.0f, 1.0f, 0.0f}, {0.0f, 0.0f, 1.0f}, "p523a", 0 },
    { {2187.0f, 746.0f, -1031.0f}, {0.0f, 1.0f, 0.0f}, {-0.707107f, 0.0f, 0.707107f}, "p47b1", 0 },
    { {1134.0f, 586.0f, 223.0f}, {0.0f, 1.0f, 0.0f}, {0.0f, 0.0f, 1.0f}, "p14b2", 0 },
    { {-1551.0f, 586.0f, -329.0f}, {0.0f, 1.0f, 0.0f}, {1.0f, 0.0f, 0.0f}, "p1a1", 0 },
    { {-853.0f, 586.0f, 2134.0f}, {0.0f, 1.0f, 0.0f}, {1.0f, 0.0f, 0.0f}, "p56c2", 0 },
    { {973.0f, 586.0f, -984.0f}, {0.0f, 1.0f, 0.0f}, {0.0f, 0.0f, 1.0f}, "p39b1", 0 },
    { {-676.0f, 586.0f, 990.0f}, {0.0f, 1.0f, 0.0f}, {0.0f, 0.0f, -1.0f}, "p56a1", 0 },
    { {-369.0f, 586.0f, -91.0f}, {0.0f, 1.0f, 0.0f}, {1.0f, 0.0f, 0.0f}, "p425a", 0 },
    { {-1161.0f, 594.0f, 1100.0f}, {0.0f, 1.0f, 0.0f}, {0.016799f, 0.0f, -0.999859f}, "p233c2", 0 },
    { {-1620.0f, 594.0f, 1322.0f}, {0.0f, 1.0f, 0.0f}, {-0.016799f, 0.0f, 0.999859f}, "p193c2", 0 },
    { {-1484.0f, 594.0f, 268.0f}, {0.0f, 1.0f, 0.0f}, {0.999859f, 0.0f, 0.016799f}, "p6a", 0 },
    { {1117.0f, 594.0f, 1075.0f}, {0.0f, 1.0f, 0.0f}, {-0.999859f, 0.0f, -0.016799f}, "p284b2", 0 },
    { {1219.0f, 594.0f, -829.0f}, {0.0f, 1.0f, 0.0f}, {-0.016799f, 0.0f, 0.999859f}, "p39b2", 0 },
    { {4.0f, 594.0f, 429.0f}, {0.0f, 1.0f, 0.0f}, {-0.016799f, 0.0f, 0.999859f}, "p525a", 0 },
    { {144.0f, 594.0f, 1938.0f}, {0.0f, 1.0f, 0.0f}, {-0.999859f, 0.0f, -0.016799f}, "p645c", 0 },
    { {2095.0f, 594.0f, -327.0f}, {0.0f, 1.0f, 0.0f}, {-0.016799f, 0.0f, 0.999859f}, "p33b2", 0 },
    { {1372.0f, 594.0f, 633.0f}, {0.0f, 1.0f, 0.0f}, {-0.016799f, 0.0f, 0.999859f}, "p14b1", 0 },
    { {1126.0f, 594.0f, -106.0f}, {0.0f, 1.0f, 0.0f}, {-0.016799f, 0.0f, 0.999859f}, "p227b1", 0 },
    { {-872.0f, 594.0f, 1296.0f}, {0.0f, 1.0f, 0.0f}, {-0.016799f, 0.0f, 0.999859f}, "p57a", 0 },
    { {-141.0f, 594.0f, -854.0f}, {0.0f, 1.0f, 0.0f}, {-0.016799f, 0.0f, 0.999859f}, "p16a1", 0 },
    { {-540.0f, 594.0f, 1772.0f}, {0.0f, 1.0f, 0.0f}, {-0.016799f, 0.0f, 0.999859f}, "p59c2", 0 },
    { {625.0f, 594.0f, -429.0f}, {0.0f, 1.0f, 0.0f}, {0.999859f, 0.0f, 0.016799f}, "p534a1", 0 },
    { {2290.0f, 594.0f, -395.0f}, {0.0f, 1.0f, 0.0f}, {-0.999859f, 0.0f, -0.016799f}, "p46b2", 0 },
    { {6.0f, 793.0f, 1186.0f}, {0.0f, 1.0f, 0.0f}, {-0.016799f, 0.0f, 0.999859f}, "p521a", 0 },
    { {-548.0f, 594.0f, 2106.0f}, {0.0f, 1.0f, 0.0f}, {-0.016799f, 0.0f, 0.999859f}, "p58c1", 0 },
    { {-548.0f, 594.0f, 2207.0f}, {0.0f, 1.0f, 0.0f}, {-0.016799f, 0.0f, 0.999859f}, "p2c2", 0 },
    { {-548.0f, 594.0f, 1671.0f}, {0.0f, 1.0f, 0.0f}, {-0.016799f, 0.0f, 0.999859f}, "p4c1", 0 },
    { {129.0f, 594.0f, 2140.0f}, {0.0f, 1.0f, 0.0f}, {-0.016799f, 0.0f, 0.999859f}, "p645c", 0 },
    { {129.0f, 594.0f, 1688.0f}, {0.0f, 1.0f, 0.0f}, {-0.016799f, 0.0f, 0.999859f}, "p75c1", 0 },
    { {839.0f, 594.0f, 1596.0f}, {0.0f, 1.0f, 0.0f}, {-0.999859f, 0.0f, -0.016799f}, "p53b1", 0 },
    { {605.0f, 594.0f, 1320.0f}, {0.0f, 1.0f, 0.0f}, {-0.999859f, 0.0f, -0.016799f}, "p70a2", 0 },
    { {1818.0f, 594.0f, -956.0f}, {0.0f, 1.0f, 0.0f}, {-0.999859f, 0.0f, -0.016799f}, "p36b", 0 },
    { {2010.0f, 594.0f, -103.0f}, {0.0f, 1.0f, 0.0f}, {-0.999859f, 0.0f, -0.016799f}, "p28b1", 0 },
    { {-379.0f, 594.0f, -437.0f}, {0.0f, 1.0f, 0.0f}, {0.999859f, 0.0f, 0.016799f}, "p27a1", 0 },
    { {-890.0f, 594.0f, -245.0f}, {0.0f, 1.0f, 0.0f}, {0.999859f, 0.0f, 0.016799f}, "p30a2", 0 },
    { {-890.0f, 594.0f, -94.0f}, {0.0f, 1.0f, 0.0f}, {0.999859f, 0.0f, 0.016799f}, "p33a1", 0 },
    { {-831.0f, 594.0f, 282.0f}, {0.0f, 1.0f, 0.0f}, {0.999859f, 0.0f, 0.016799f}, "p7a1", 0 },
    { {-815.0f, 594.0f, -387.0f}, {0.0f, 1.0f, 0.0f}, {0.999859f, 0.0f, 0.016799f}, "p11a", 0 },
    { {-1576.0f, 594.0f, 274.0f}, {0.0f, 1.0f, 0.0f}, {0.999859f, 0.0f, 0.016799f}, "p6a", 0 },
    { {-1668.0f, 594.0f, 291.0f}, {0.0f, 1.0f, 0.0f}, {0.999859f, 0.0f, 0.016799f}, "p5a1", 0 },
    { {-1143.0f, 594.0f, 1704.0f}, {0.0f, 1.0f, 0.0f}, {0.016799f, 0.0f, -0.999859f}, "p169c1", 0 },
    { {-1628.0f, 594.0f, 683.0f}, {0.0f, 1.0f, 0.0f}, {0.016799f, 0.0f, -0.999859f}, "p183c2", 0 },
    { {-113.0f, 594.0f, 2449.0f}, {0.0f, 1.0f, 0.0f}, {-0.016799f, 0.0f, 0.999859f}, "p78c1", 0 },
    { {807.0f, 594.0f, 449.0f}, {0.0f, 1.0f, 0.0f}, {-0.016799f, 0.0f, 0.999859f}, "p232b1", 0 },
    { {1150.0f, 594.0f, 851.0f}, {0.0f, 1.0f, 0.0f}, {-0.016799f, 0.0f, 0.999859f}, "p231b2", 0 },
    { {1485.0f, 594.0f, 324.0f}, {0.0f, 1.0f, 0.0f}, {-0.016799f, 0.0f, 0.999859f}, "p225b1", 0 },
    { {-808.0f, 594.0f, 650.0f}, {0.0f, 1.0f, 0.0f}, {-0.016799f, 0.0f, 0.999859f}, "p59a", 0 },
    { {-481.0f, 594.0f, 1069.0f}, {0.0f, 1.0f, 0.0f}, {-0.016799f, 0.0f, 0.999859f}, "p55a2", 0 },
    { {1123.0f, 594.0f, 1328.0f}, {0.0f, 1.0f, 0.0f}, {-0.999859f, 0.0f, -0.016799f}, "p50b2", 0 },
    { {0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f}, NULL, 0 }
};


BoundPadRecord pad3dlist[] = {
    { {0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f}, NULL, 0, {0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f} }
};


s32 propDefs[] = {
    /* Type = Collectable; index = 0 */
    _mkword(256, _mkshort(0, 8)), _mkword(333, 2), 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0, _mkword(_mkshort(0x58, 0xff), 0xffff), 0,
    /* Type = Collectable; index = 1 */
    _mkword(512, _mkshort(0, 8)), _mkword(0, 41), 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0, _mkword(_mkshort(0xf0, 0xff), 0xffff), 0,
    /* Type = AmmoBox; index = 2 */
    _mkword(153, _mkshort(0, 20)), _mkword(5, 8), 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0, _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0),
    /* Type = AmmoBox; index = 3 */
    _mkword(153, _mkshort(0, 20)), _mkword(5, 9), 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0, _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0),
    /* Type = Collectable; index = 4 */
    _mkword(512, _mkshort(0, 8)), _mkword(0, 22), 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0, _mkword(_mkshort(0xf1, 0xff), 0xffff), 0,
    /* Type = AmmoBox; index = 5 */
    _mkword(153, _mkshort(0, 20)), _mkword(5, 31), 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0, _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0),
    /* Type = AmmoBox; index = 6 */
    _mkword(153, _mkshort(0, 20)), _mkword(5, 32), 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0, _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0),
    /* Type = Collectable; index = 7 */
    _mkword(512, _mkshort(0, 8)), _mkword(0, 23), 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0, _mkword(_mkshort(0xf2, 0xff), 0xffff), 0,
    /* Type = AmmoBox; index = 8 */
    _mkword(153, _mkshort(0, 20)), _mkword(5, 47), 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0, _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0),
    /* Type = AmmoBox; index = 9 */
    _mkword(153, _mkshort(0, 20)), _mkword(5, 30), 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0, _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0),
    /* Type = Collectable; index = 10 */
    _mkword(307, _mkshort(0, 8)), _mkword(0, 10), 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0, _mkword(_mkshort(0xf3, 0xff), 0xffff), 0,
    /* Type = AmmoBox; index = 11 */
    _mkword(153, _mkshort(0, 20)), _mkword(5, 38), 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0, _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0),
    /* Type = AmmoBox; index = 12 */
    _mkword(153, _mkshort(0, 20)), _mkword(5, 39), 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0, _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0),
    /* Type = Collectable; index = 13 */
    _mkword(307, _mkshort(0, 8)), _mkword(0, 14), 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0, _mkword(_mkshort(0xf4, 0xff), 0xffff), 0,
    /* Type = AmmoBox; index = 14 */
    _mkword(153, _mkshort(0, 20)), _mkword(5, 27), 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0, _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0),
    /* Type = AmmoBox; index = 15 */
    _mkword(153, _mkshort(0, 20)), _mkword(5, 28), 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0, _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0),
    /* Type = Collectable; index = 16 */
    _mkword(307, _mkshort(0, 8)), _mkword(0, 17), 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0, _mkword(_mkshort(0xf5, 0xff), 0xffff), 0,
    /* Type = AmmoBox; index = 17 */
    _mkword(153, _mkshort(0, 20)), _mkword(5, 43), 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0, _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0),
    /* Type = AmmoBox; index = 18 */
    _mkword(153, _mkshort(0, 20)), _mkword(5, 45), 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0, _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0),
    /* Type = Collectable; index = 19 */
    _mkword(256, _mkshort(0, 8)), _mkword(0, 26), 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0, _mkword(_mkshort(0xf6, 0xff), 0xffff), 0,
    /* Type = AmmoBox; index = 20 */
    _mkword(153, _mkshort(0, 20)), _mkword(5, 25), 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0, _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0),
    /* Type = AmmoBox; index = 21 */
    _mkword(153, _mkshort(0, 20)), _mkword(5, 42), 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0, _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0),
    /* Type = Collectable; index = 22 */
    _mkword(256, _mkshort(0, 8)), _mkword(0, 33), 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0, _mkword(_mkshort(0xf7, 0xff), 0xffff), 0,
    /* Type = AmmoBox; index = 23 */
    _mkword(153, _mkshort(0, 20)), _mkword(5, 34), 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0, _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0),
    /* Type = AmmoBox; index = 24 */
    _mkword(153, _mkshort(0, 20)), _mkword(5, 35), 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0, _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0),
    /* Type = Armour; index = 25 */
    _mkword(384, _mkshort(0, 21)), _mkword(115, 15), 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0, 65536, 0,
    /* Type = Armour; index = 26 */
    _mkword(384, _mkshort(0, 21)), _mkword(115, 18), 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0, 65536, 0,
    /* Type = Armour; index = 27 */
    _mkword(384, _mkshort(0, 21)), _mkword(115, 21), 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0, 65536, 0,
    /* Type = EndProps; index = 28 */
    _mkword(0, _mkshort(0, 48))
};


s32 intro[] = {
    /* Type = Spawn; index = 0 */
    _mkword(0, _mkshort(0, 0)), 0, 0,
    /* Type = Spawn; index = 1 */
    _mkword(0, _mkshort(0, 0)), 1, 0,
    /* Type = Spawn; index = 2 */
    _mkword(0, _mkshort(0, 0)), 3, 0,
    /* Type = Spawn; index = 3 */
    _mkword(0, _mkshort(0, 0)), 4, 0,
    /* Type = Spawn; index = 4 */
    _mkword(0, _mkshort(0, 0)), 5, 0,
    /* Type = Spawn; index = 5 */
    _mkword(0, _mkshort(0, 0)), 6, 0,
    /* Type = Spawn; index = 6 */
    _mkword(0, _mkshort(0, 0)), 7, 0,
    /* Type = StartWeapon; index = 7 */
    _mkword(0, _mkshort(0, 1)), 1, -1, 0,
    /* Type = Cuff; index = 8 */
    _mkword(0, _mkshort(0, 5)), 3,
    /* Type = EndIntro; index = 9 */
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




