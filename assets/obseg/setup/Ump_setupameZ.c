/*
* This file was automatically generated
* 
* Monday, January 17, 2022 9:36:05 AM
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

stagesetup Ump_setupameZ = {
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
    { {-389.0f, 95.0f, 160.0f}, {0.0f, 1.0f, 0.0f}, {-0.999859f, 0.0f, -0.016799f}, "p274a2", 0 },
    { {-1536.0f, 95.0f, 767.0f}, {0.0f, 1.0f, 0.0f}, {-0.999859f, 0.0f, -0.016799f}, "p330a", 0 },
    { {-338.0f, 95.0f, -523.0f}, {0.0f, 1.0f, 0.0f}, {-0.999859f, 0.0f, -0.016799f}, "p297a", 0 },
    { {-323.0f, 95.0f, -2251.0f}, {0.0f, 1.0f, 0.0f}, {-0.999859f, 0.0f, -0.016799f}, "p306a", 0 },
    { {-1615.0f, 95.0f, -1247.0f}, {0.0f, 1.0f, 0.0f}, {-0.999859f, 0.0f, -0.016799f}, "p319a", 0 },
    { {307.0f, 95.0f, 301.0f}, {0.0f, 1.0f, 0.0f}, {0.016799f, 0.0f, -0.999859f}, "p493a2", 0 },
    { {530.0f, 95.0f, 742.0f}, {0.0f, 1.0f, 0.0f}, {0.016799f, 0.0f, -0.999859f}, "p577a2", 0 },
    { {-769.0f, 95.0f, -947.0f}, {0.0f, 1.0f, 0.0f}, {0.016799f, 0.0f, -0.999859f}, "p299a", 0 },
    { {-772.0f, 95.0f, -2027.0f}, {0.0f, 1.0f, 0.0f}, {0.016799f, 0.0f, -0.999859f}, "p309a", 0 },
    { {-1647.0f, 95.0f, -1305.0f}, {0.0f, 1.0f, 0.0f}, {0.016799f, 0.0f, -0.999859f}, "p319a", 0 },
    { {-2082.0f, 95.0f, -364.0f}, {0.0f, 1.0f, 0.0f}, {0.016799f, 0.0f, -0.999859f}, "p43a1", 0 },
    { {-1647.0f, 95.0f, 770.0f}, {0.0f, 1.0f, 0.0f}, {0.016799f, 0.0f, -0.999859f}, "p328a", 0 },
    { {258.0f, 379.0f, -1623.0f}, {0.0f, 1.0f, 0.0f}, {0.016799f, 0.0f, -0.999859f}, "p343a1", 0 },
    { {-1419.0f, 379.0f, 73.0f}, {0.0f, 1.0f, 0.0f}, {0.016799f, 0.0f, -0.999859f}, "p338a2", 0 },
    { {-1236.0f, 379.0f, -951.0f}, {0.0f, 1.0f, 0.0f}, {0.016799f, 0.0f, -0.999859f}, "p175a2", 0 },
    { {-2130.0f, 95.0f, -1043.0f}, {0.0f, 1.0f, 0.0f}, {0.016799f, 0.0f, -0.999859f}, "p51a2", 0 },
    { {-461.0f, 379.0f, -1594.0f}, {0.0f, 1.0f, 0.0f}, {0.016799f, 0.0f, -0.999859f}, "p176a1", 0 },
    { {299.0f, 95.0f, 104.0f}, {0.0f, 1.0f, 0.0f}, {0.016799f, 0.0f, -0.999859f}, "p493a1", 0 },
    { {107.0f, 95.0f, 524.0f}, {0.0f, 1.0f, 0.0f}, {0.016799f, 0.0f, -0.999859f}, "p487a1", 0 },
    { {286.0f, 95.0f, 506.0f}, {0.0f, 1.0f, 0.0f}, {0.016799f, 0.0f, -0.999859f}, "p575a", 0 },
    { {802.0f, 95.0f, 506.0f}, {0.0f, 1.0f, 0.0f}, {0.016799f, 0.0f, -0.999859f}, "p29a", 0 },
    { {-454.0f, 95.0f, -1231.0f}, {0.0f, 1.0f, 0.0f}, {0.016799f, 0.0f, -0.999859f}, "p298a", 0 },
    { {-1016.0f, 95.0f, -644.0f}, {0.0f, 1.0f, 0.0f}, {0.016799f, 0.0f, -0.999859f}, "p303a", 0 },
    { {-280.0f, 95.0f, -2246.0f}, {0.0f, 1.0f, 0.0f}, {0.016799f, 0.0f, -0.999859f}, "p306a", 0 },
    { {-1264.0f, 95.0f, -1763.0f}, {0.0f, 1.0f, 0.0f}, {0.016799f, 0.0f, -0.999859f}, "p310a", 0 },
    { {-1784.0f, 95.0f, -1815.0f}, {0.0f, 1.0f, 0.0f}, {0.016799f, 0.0f, -0.999859f}, "p316a", 0 },
    { {-2081.0f, 95.0f, -1567.0f}, {0.0f, 1.0f, 0.0f}, {0.016799f, 0.0f, -0.999859f}, "p166a2", 0 },
    { {-1957.0f, 95.0f, -625.0f}, {0.0f, 1.0f, 0.0f}, {0.016799f, 0.0f, -0.999859f}, "p323a", 0 },
    { {-1741.0f, 95.0f, -471.0f}, {0.0f, 1.0f, 0.0f}, {0.016799f, 0.0f, -0.999859f}, "p325a", 0 },
    { {-1815.0f, 95.0f, 483.0f}, {0.0f, 1.0f, 0.0f}, {0.016799f, 0.0f, -0.999859f}, "p328a", 0 },
    { {-1852.0f, 95.0f, 1084.0f}, {0.0f, 1.0f, 0.0f}, {0.016799f, 0.0f, -0.999859f}, "p331a", 0 },
    { {26.0f, 379.0f, -1200.0f}, {0.0f, 1.0f, 0.0f}, {0.016799f, 0.0f, -0.999859f}, "p184a1", 0 },
    { {14.0f, 379.0f, -2041.0f}, {0.0f, 1.0f, 0.0f}, {0.016799f, 0.0f, -0.999859f}, "p182a2", 0 },
    { {-1814.0f, 379.0f, 92.0f}, {0.0f, 1.0f, 0.0f}, {0.016799f, 0.0f, -0.999859f}, "p186a1", 0 },
    { {-1579.0f, 379.0f, 469.0f}, {0.0f, 1.0f, 0.0f}, {0.016799f, 0.0f, -0.999859f}, "p188a1", 0 },
    { {-497.0f, 379.0f, -434.0f}, {0.0f, 1.0f, 0.0f}, {0.016799f, 0.0f, -0.999859f}, "p172a1", 0 },
    { {-1010.0f, 379.0f, -1411.0f}, {0.0f, 1.0f, 0.0f}, {0.016799f, 0.0f, -0.999859f}, "p174a1", 0 },
    { {-778.0f, -142.0f, 1050.0f}, {0.0f, 1.0f, 0.0f}, {0.016799f, 0.0f, -0.999859f}, "p1104a", 0 },
    { {757.0f, -142.0f, 480.0f}, {0.0f, 1.0f, 0.0f}, {0.016799f, 0.0f, -0.999859f}, "p1162a", 0 },
    { {-1406.0f, -142.0f, -1685.0f}, {0.0f, 1.0f, 0.0f}, {0.016798f, 0.0f, -0.999859f}, "p1125a", 0 },
    { {1044.0f, -142.0f, -781.0f}, {0.0f, 1.0f, 0.0f}, {0.016798f, 0.0f, -0.999859f}, "p1171a", 0 },
    { {-688.0f, -142.0f, -744.0f}, {0.0f, 1.0f, 0.0f}, {-0.999859f, 0.0f, -0.016798f}, "p803a2", 0 },
    { {524.0f, -142.0f, 208.0f}, {0.0f, 1.0f, 0.0f}, {0.016799f, 0.0f, -0.999859f}, "p1163a", 0 },
    { {486.0f, -142.0f, -1369.0f}, {0.0f, 1.0f, 0.0f}, {0.016799f, 0.0f, -0.999859f}, "p1244a", 0 },
    { {-1220.0f, -142.0f, 84.0f}, {0.0f, 1.0f, 0.0f}, {0.016799f, 0.0f, -0.999859f}, "p787a1", 0 },
    { {-745.0f, -142.0f, 834.0f}, {0.0f, 1.0f, 0.0f}, {0.016799f, 0.0f, -0.999859f}, "p1080a", 0 },
    { {-976.0f, -142.0f, -2059.0f}, {0.0f, 1.0f, 0.0f}, {0.016799f, 0.0f, -0.999859f}, "p1145a", 0 },
    { {-968.0f, -142.0f, -736.0f}, {0.0f, 1.0f, 0.0f}, {0.016799f, 0.0f, -0.999859f}, "p799a2", 0 },
    { {-212.0f, -142.0f, -495.0f}, {0.0f, 1.0f, 0.0f}, {0.016799f, 0.0f, -0.999859f}, "p591a2", 0 },
    { {524.0f, -142.0f, 86.0f}, {0.0f, 1.0f, 0.0f}, {0.016799f, 0.0f, -0.999859f}, "p1163a", 0 },
    { {532.0f, -142.0f, 330.0f}, {0.0f, 1.0f, 0.0f}, {0.016799f, 0.0f, -0.999859f}, "p1162a", 0 },
    { {739.0f, -142.0f, -1636.0f}, {0.0f, 1.0f, 0.0f}, {0.016799f, 0.0f, -0.999859f}, "p1261a", 0 },
    { {-849.0f, -142.0f, -727.0f}, {0.0f, 1.0f, 0.0f}, {0.016799f, 0.0f, -0.999859f}, "p799a2", 0 },
    { {264.0f, -142.0f, -1047.0f}, {0.0f, 1.0f, 0.0f}, {0.016799f, 0.0f, -0.999859f}, "p1249a", 0 },
    { {-975.0f, -142.0f, 667.0f}, {0.0f, 1.0f, 0.0f}, {0.016799f, 0.0f, -0.999859f}, "p1087a", 0 },
    { {-531.0f, -142.0f, 636.0f}, {0.0f, 1.0f, 0.0f}, {0.016799f, 0.0f, -0.999859f}, "p1092a", 0 },
    { {-1365.0f, -142.0f, -152.0f}, {0.0f, 1.0f, 0.0f}, {0.016799f, 0.0f, -0.999859f}, "p792a1", 0 },
    { {-1005.0f, -142.0f, -144.0f}, {0.0f, 1.0f, 0.0f}, {0.016799f, 0.0f, -0.999859f}, "p793a2", 0 },
    { {-1280.0f, -142.0f, -2058.0f}, {0.0f, 1.0f, 0.0f}, {0.016799f, 0.0f, -0.999859f}, "p1116a", 0 },
    { {-1098.0f, -142.0f, -715.0f}, {0.0f, 1.0f, 0.0f}, {0.016799f, 0.0f, -0.999859f}, "p799a1", 0 },
    { {-1038.0f, 95.0f, -1049.0f}, {0.0f, 1.0f, 0.0f}, {0.016799f, 0.0f, -0.999859f}, "p305a", 0 },
    { {-1896.0f, -142.0f, -2399.0f}, {0.0f, 1.0f, 0.0f}, {0.016799f, 0.0f, -0.999859f}, "p938a2", 0 },
    { {0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f}, NULL, 0 }
};


BoundPadRecord pad3dlist[] = {
    { {380.0f, 95.0f, -127.0f}, {-1.0f, 0.0f, 1e-06}, {0.0f, 1.0f, 0.0f}, "p25a2", 0, {-89.0f, 90.0f, -5.7e-05, 5.6e-05, -94.99999f, 93.99999f} },
    { {199.0f, 95.0f, -265.0f}, {-1.0f, 0.0f, 1e-06}, {0.0f, 1.0f, 0.0f}, "p25a1", 0, {-110.0f, 114.0f, -5.8e-05, 5.5e-05, -94.99999f, 93.99999f} },
    { {207.0f, 95.0f, 74.0f}, {-1.0f, 0.0f, 1e-06}, {0.0f, 1.0f, 0.0f}, "p493a1", 0, {-72.0f, 74.0f, -5.7e-05, 5.6e-05, -94.99999f, 93.99999f} },
    { {207.0f, 95.0f, 307.0f}, {-1.0f, 0.0f, 1e-06}, {0.0f, 1.0f, 0.0f}, "p493a1", 0, {-72.0f, 74.0f, -5.7e-05, 5.6e-05, -94.99999f, 93.99999f} },
    { {116.0f, 95.0f, 405.0f}, {-1e-06, 0.0f, -1.0f}, {0.0f, 1.0f, 0.0f}, "p487a1", 0, {-72.0f, 73.0f, -5.7e-05, 5.6e-05, -94.99999f, 93.99999f} },
    { {-117.0f, 95.0f, 405.0f}, {-1e-06, 0.0f, -1.0f}, {0.0f, 1.0f, 0.0f}, "p487a1", 0, {-72.0f, 73.0f, -5.7e-05, 5.6e-05, -94.99999f, 93.99999f} },
    { {-479.0f, 95.0f, 623.0f}, {0.0f, 0.0f, -1.0f}, {0.0f, 1.0f, 0.0f}, "p28a2", 0, {-89.0f, 90.0f, -4.5e-05, 4.4e-05, -94.99999f, 93.99999f} },
    { {-341.0f, 95.0f, 443.0f}, {0.0f, 0.0f, -1.0f}, {0.0f, 1.0f, 0.0f}, "p28a2", 0, {-111.0f, 114.0f, -4.2e-05, 4.1e-05, -94.99999f, 93.99999f} },
    { {-1841.0f, 95.0f, -568.0f}, {0.0f, 0.0f, -1.0f}, {0.0f, 1.0f, 0.0f}, "p325a", 0, {-167.0f, 170.0f, -4.2e-05, 4.1e-05, -94.99999f, 93.99999f} },
    { {-1671.0f, 95.0f, -435.0f}, {1.0f, 0.0f, 0.0f}, {0.0f, 1.0f, 0.0f}, "p325a", 0, {-133.0f, 136.0f, -4.2e-05, 4.1e-05, -94.99999f, 93.99999f} },
    { {-1685.0f, 95.0f, -1514.0f}, {0.0f, 0.0f, -1.0f}, {0.0f, 1.0f, 0.0f}, "p319a", 0, {-167.0f, 170.0f, -4.2e-05, 4.1e-05, -94.99999f, 93.99999f} },
    { {-1667.0f, 95.0f, -1761.0f}, {1.0f, 0.0f, 0.0f}, {0.0f, 1.0f, 0.0f}, "p319a", 0, {-133.0f, 136.0f, -4.2e-05, 4.1e-05, -94.99999f, 93.99999f} },
    { {-2022.0f, 39.0f, -767.0f}, {1e-06, -1e-06, -1.0f}, {0.0f, 1.0f, 0.0f}, "p62a1", 0, {-15.000288f, 14.000024f, -9.000112f, 180.00003f, -39.000004f, 151.00002f} },
    { {-2022.0f, 39.0f, -1145.0f}, {1e-06, -1e-06, -1.0f}, {0.0f, 1.0f, 0.0f}, "p61a1", 0, {-15.000289f, 14.000024f, -9.000112f, 181.00003f, -39.000004f, 151.00002f} },
    { {464.0f, 39.0f, 402.0f}, {1.0f, -1e-06, 1e-06}, {0.0f, 1.0f, 0.0f}, "p60a2", 0, {-15.000236f, 15.000024f, -9.000112f, 142.00005f, -39.000004f, 151.00002f} },
    { {464.0f, 39.0f, -23.0f}, {1.0f, -1e-06, 1e-06}, {0.0f, 1.0f, 0.0f}, "p57a2", 0, {-15.000236f, 14.000024f, -9.000112f, 142.00003f, -39.000004f, 151.00002f} },
    { {213.0f, 39.0f, 786.0f}, {1e-06, -1e-06, -1.0f}, {0.0f, 1.0f, 0.0f}, "p58a1", 0, {-15.000236f, 14.000024f, -9.000112f, 142.00003f, -39.000004f, 151.00002f} },
    { {-213.0f, 39.0f, 786.0f}, {1e-06, -1e-06, -1.0f}, {0.0f, 1.0f, 0.0f}, "p59a1", 0, {-14.000236f, 15.000024f, -9.00011f, 142.00005f, -39.000004f, 151.00002f} },
    { {-1340.0f, 39.0f, -804.0f}, {1e-06, -1e-06, -1.0f}, {0.0f, 1.0f, 0.0f}, "p56a2", 0, {-15.000237f, 14.000024f, -9.000112f, 143.00003f, -39.000004f, 151.00002f} },
    { {-1500.0f, 39.0f, -804.0f}, {1e-06, -1e-06, -1.0f}, {0.0f, 1.0f, 0.0f}, "p56a2", 0, {-15.000237f, 14.000024f, -9.000112f, 143.00003f, -39.000004f, 151.00002f} },
    { {-2041.0f, -188.0f, -2392.0f}, {3e-06, 0.0f, -1.0f}, {0.0f, 1.0f, 0.0f}, "p938a1", 0, {-4.000306f, 4.00002f, -6.000065f, 108.00002f, -40.0f, 150.0f} },
    { {219.0f, -188.0f, 979.0f}, {3e-06, 0.0f, -1.0f}, {0.0f, 1.0f, 0.0f}, "p581a1", 0, {-5.000306f, 4.00002f, -6.000068f, 108.00002f, -40.0f, 150.0f} },
    { {0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f}, NULL, 0, {0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f} }
};


s32 propDefs[] = {
    /* Type = Collectable; index = 0 */
    _mkword(256, _mkshort(0, 8)), _mkword(333, 59), 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0, _mkword(_mkshort(0x58, 0xff), 0xffff), 0,
    /* Type = Armour; index = 1 */
    _mkword(384, _mkshort(0, 21)), _mkword(115, 48), 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0, 65536, 0,
    /* Type = Armour; index = 2 */
    _mkword(384, _mkshort(0, 21)), _mkword(115, 15), 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0, 65536, 0,
    /* Type = Armour; index = 3 */
    _mkword(384, _mkshort(0, 21)), _mkword(115, 16), 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0, 65536, 0,
    /* Type = Collectable; index = 4 */
    _mkword(512, _mkshort(0, 8)), _mkword(0, 42), 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0, _mkword(_mkshort(0xf0, 0xff), 0xffff), 0,
    /* Type = AmmoBox; index = 5 */
    _mkword(153, _mkshort(0, 20)), _mkword(5, 49), 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0, _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0),
    /* Type = AmmoBox; index = 6 */
    _mkword(153, _mkshort(0, 20)), _mkword(5, 50), 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0, _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0),
    /* Type = Collectable; index = 7 */
    _mkword(512, _mkshort(0, 8)), _mkword(0, 47), 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0, _mkword(_mkshort(0xf0, 0xff), 0xffff), 0,
    /* Type = AmmoBox; index = 8 */
    _mkword(153, _mkshort(0, 20)), _mkword(5, 52), 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0, _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0),
    /* Type = AmmoBox; index = 9 */
    _mkword(153, _mkshort(0, 20)), _mkword(5, 59), 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0, _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0),
    /* Type = Collectable; index = 10 */
    _mkword(512, _mkshort(0, 8)), _mkword(0, 8), 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0, _mkword(_mkshort(0xf1, 0xff), 0xffff), 0,
    /* Type = AmmoBox; index = 11 */
    _mkword(153, _mkshort(0, 20)), _mkword(5, 23), 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0, _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0),
    /* Type = AmmoBox; index = 12 */
    _mkword(153, _mkshort(0, 20)), _mkword(5, 24), 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0, _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0),
    /* Type = Collectable; index = 13 */
    _mkword(512, _mkshort(0, 8)), _mkword(0, 10), 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0, _mkword(_mkshort(0xf1, 0xff), 0xffff), 0,
    /* Type = AmmoBox; index = 14 */
    _mkword(153, _mkshort(0, 20)), _mkword(5, 27), 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0, _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0),
    /* Type = AmmoBox; index = 15 */
    _mkword(153, _mkshort(0, 20)), _mkword(5, 28), 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0, _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0),
    /* Type = Collectable; index = 16 */
    _mkword(307, _mkshort(0, 8)), _mkword(0, 45), 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0, _mkword(_mkshort(0xf2, 0xff), 0xffff), 0,
    /* Type = AmmoBox; index = 17 */
    _mkword(153, _mkshort(0, 20)), _mkword(5, 54), 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0, _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0),
    /* Type = AmmoBox; index = 18 */
    _mkword(153, _mkshort(0, 20)), _mkword(5, 55), 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0, _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0),
    /* Type = Collectable; index = 19 */
    _mkword(307, _mkshort(0, 8)), _mkword(0, 46), 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0, _mkword(_mkshort(0xf2, 0xff), 0xffff), 0,
    /* Type = AmmoBox; index = 20 */
    _mkword(153, _mkshort(0, 20)), _mkword(5, 58), 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0, _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0),
    /* Type = Collectable; index = 21 */
    _mkword(307, _mkshort(0, 8)), _mkword(0, 5), 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0, _mkword(_mkshort(0xf3, 0xff), 0xffff), 0,
    /* Type = AmmoBox; index = 22 */
    _mkword(153, _mkshort(0, 20)), _mkword(5, 17), 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0, _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0),
    /* Type = AmmoBox; index = 23 */
    _mkword(153, _mkshort(0, 20)), _mkword(5, 18), 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0, _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0),
    /* Type = Collectable; index = 24 */
    _mkword(307, _mkshort(0, 8)), _mkword(0, 9), 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0, _mkword(_mkshort(0xf3, 0xff), 0xffff), 0,
    /* Type = AmmoBox; index = 25 */
    _mkword(153, _mkshort(0, 20)), _mkword(5, 25), 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0, _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0),
    /* Type = AmmoBox; index = 26 */
    _mkword(153, _mkshort(0, 20)), _mkword(5, 26), 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0, _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0),
    /* Type = Collectable; index = 27 */
    _mkword(307, _mkshort(0, 8)), _mkword(0, 12), 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0, _mkword(_mkshort(0xf4, 0xff), 0xffff), 0,
    /* Type = AmmoBox; index = 28 */
    _mkword(153, _mkshort(0, 20)), _mkword(5, 31), 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0, _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0),
    /* Type = AmmoBox; index = 29 */
    _mkword(153, _mkshort(0, 20)), _mkword(5, 32), 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0, _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0),
    /* Type = Collectable; index = 30 */
    _mkword(256, _mkshort(0, 8)), _mkword(0, 43), 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0, _mkword(_mkshort(0xf4, 0xff), 0xffff), 0,
    /* Type = AmmoBox; index = 31 */
    _mkword(153, _mkshort(0, 20)), _mkword(5, 51), 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0, _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0),
    /* Type = AmmoBox; index = 32 */
    _mkword(153, _mkshort(0, 20)), _mkword(5, 53), 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0, _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0),
    /* Type = Collectable; index = 33 */
    _mkword(256, _mkshort(0, 8)), _mkword(0, 44), 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0, _mkword(_mkshort(0xf5, 0xff), 0xffff), 0,
    /* Type = AmmoBox; index = 34 */
    _mkword(153, _mkshort(0, 20)), _mkword(5, 56), 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0, _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0),
    /* Type = AmmoBox; index = 35 */
    _mkword(153, _mkshort(0, 20)), _mkword(5, 57), 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0, _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0),
    /* Type = Collectable; index = 36 */
    _mkword(256, _mkshort(0, 8)), _mkword(0, 6), 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0, _mkword(_mkshort(0xf5, 0xff), 0xffff), 0,
    /* Type = AmmoBox; index = 37 */
    _mkword(153, _mkshort(0, 20)), _mkword(5, 19), 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0, _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0),
    /* Type = AmmoBox; index = 38 */
    _mkword(153, _mkshort(0, 20)), _mkword(5, 20), 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0, _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0),
    /* Type = Collectable; index = 39 */
    _mkword(256, _mkshort(0, 8)), _mkword(0, 11), 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0, _mkword(_mkshort(0xf6, 0xff), 0xffff), 0,
    /* Type = AmmoBox; index = 40 */
    _mkword(153, _mkshort(0, 20)), _mkword(5, 29), 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0, _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0),
    /* Type = AmmoBox; index = 41 */
    _mkword(153, _mkshort(0, 20)), _mkword(5, 30), 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0, _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0),
    /* Type = Collectable; index = 42 */
    _mkword(256, _mkshort(0, 8)), _mkword(0, 13), 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0, _mkword(_mkshort(0xf6, 0xff), 0xffff), 0,
    /* Type = AmmoBox; index = 43 */
    _mkword(153, _mkshort(0, 20)), _mkword(5, 33), 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0, _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0),
    /* Type = AmmoBox; index = 44 */
    _mkword(153, _mkshort(0, 20)), _mkword(5, 34), 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0, _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0),
    /* Type = Collectable; index = 45 */
    _mkword(256, _mkshort(0, 8)), _mkword(0, 7), 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0, _mkword(_mkshort(0xf6, 0xff), 0xffff), 0,
    /* Type = AmmoBox; index = 46 */
    _mkword(153, _mkshort(0, 20)), _mkword(5, 21), 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0, _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0),
    /* Type = AmmoBox; index = 47 */
    _mkword(153, _mkshort(0, 20)), _mkword(5, 22), 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0, _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0),
    /* Type = Collectable; index = 48 */
    _mkword(256, _mkshort(0, 8)), _mkword(0, 14), 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0, _mkword(_mkshort(0xf7, 0xff), 0xffff), 0,
    /* Type = AmmoBox; index = 49 */
    _mkword(153, _mkshort(0, 20)), _mkword(5, 35), 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0, _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0),
    /* Type = AmmoBox; index = 50 */
    _mkword(153, _mkshort(0, 20)), _mkword(5, 36), 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0, _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0), _mkword(0xffff, 0),
    /* Type = Glass; index = 51 */
    _mkword(256, _mkshort(0, 42)), _mkword(104, 10000), 0x04000b62, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0,
    /* Type = Glass; index = 52 */
    _mkword(256, _mkshort(0, 42)), _mkword(104, 10001), 0x04000b62, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0,
    /* Type = Glass; index = 53 */
    _mkword(256, _mkshort(0, 42)), _mkword(104, 10002), 0x04000b62, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0,
    /* Type = Glass; index = 54 */
    _mkword(256, _mkshort(0, 42)), _mkword(104, 10003), 0x04000b62, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0,
    /* Type = Glass; index = 55 */
    _mkword(256, _mkshort(0, 42)), _mkword(104, 10004), 0x04000b62, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0,
    /* Type = Glass; index = 56 */
    _mkword(256, _mkshort(0, 42)), _mkword(104, 10005), 0x04000b62, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0,
    /* Type = Glass; index = 57 */
    _mkword(256, _mkshort(0, 42)), _mkword(104, 10006), 0x04000b62, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0,
    /* Type = Glass; index = 58 */
    _mkword(256, _mkshort(0, 42)), _mkword(104, 10007), 0x04000b62, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0,
    /* Type = Glass; index = 59 */
    _mkword(256, _mkshort(0, 42)), _mkword(104, 10008), 0x04000b62, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0,
    /* Type = Glass; index = 60 */
    _mkword(256, _mkshort(0, 42)), _mkword(104, 10009), 0x04000b62, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0,
    /* Type = Glass; index = 61 */
    _mkword(256, _mkshort(0, 42)), _mkword(104, 10010), 0x04000b62, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0,
    /* Type = Glass; index = 62 */
    _mkword(256, _mkshort(0, 42)), _mkword(104, 10011), 0x04000b62, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0,
    /* Type = Door; index = 63 */
    _mkword(256, _mkshort(0, 1)), _mkword(298, 12), 0x10000400, 0x20000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0, 0x00000000, 0x0000f333, 0x0000e70a, 0x00000051, 0x00000051, 0x00000666, _mkword(4, 4), 0x00000000, 1500, 15, 0.0f, 0, 0, 0, 0.0f, _mkword(0, 0), 0, _mkword(0, _mkshort(0, 0)), 0x00000000, _mkword(_mkshort(0, 0), 0), 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    /* Type = Door; index = 64 */
    _mkword(256, _mkshort(0, 1)), _mkword(298, 13), 0x10000400, 0x20000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0, 0x00000000, 0x0000f333, 0x0000e70a, 0x00000051, 0x00000051, 0x00000666, _mkword(4, 4), 0x00000000, 1500, 15, 0.0f, 0, 0, 0, 0.0f, _mkword(0, 0), 0, _mkword(0, _mkshort(0, 0)), 0x00000000, _mkword(_mkshort(0, 0), 0), 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    /* Type = Door; index = 65 */
    _mkword(256, _mkshort(0, 1)), _mkword(298, 14), 0x10000400, 0x20000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0, 0x00000000, 0x0000f333, 0x0000e70a, 0x00000051, 0x00000051, 0x00000666, _mkword(4, 4), 0x00000000, 1500, 15, 0.0f, 0, 0, 0, 0.0f, _mkword(0, 0), 0, _mkword(0, _mkshort(0, 0)), 0x00000000, _mkword(_mkshort(0, 0), 0), 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    /* Type = Door; index = 66 */
    _mkword(256, _mkshort(0, 1)), _mkword(298, 15), 0x10000400, 0x20000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0, 0x00000000, 0x0000f333, 0x0000e70a, 0x00000051, 0x00000051, 0x00000666, _mkword(4, 4), 0x00000000, 1500, 15, 0.0f, 0, 0, 0, 0.0f, _mkword(0, 0), 0, _mkword(0, _mkshort(0, 0)), 0x00000000, _mkword(_mkshort(0, 0), 0), 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    /* Type = Door; index = 67 */
    _mkword(256, _mkshort(0, 1)), _mkword(298, 16), 0x10000400, 0x20000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0, 0x00000000, 0x0000f333, 0x0000e70a, 0x00000051, 0x00000051, 0x00000666, _mkword(4, 4), 0x00000000, 1500, 15, 0.0f, 0, 0, 0, 0.0f, _mkword(0, 0), 0, _mkword(0, _mkshort(0, 0)), 0x00000000, _mkword(_mkshort(0, 0), 0), 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    /* Type = Door; index = 68 */
    _mkword(256, _mkshort(0, 1)), _mkword(298, 17), 0x10000400, 0x20000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0, 0x00000000, 0x0000f333, 0x0000e70a, 0x00000051, 0x00000051, 0x00000666, _mkword(4, 4), 0x00000000, 1500, 15, 0.0f, 0, 0, 0, 0.0f, _mkword(0, 0), 0, _mkword(0, _mkshort(0, 0)), 0x00000000, _mkword(_mkshort(0, 0), 0), 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    /* Type = Door; index = 69 */
    _mkword(256, _mkshort(0, 1)), _mkword(298, 18), 0x10000400, 0x20000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0, 0x00000000, 0x0000f333, 0x0000e70a, 0x00000051, 0x00000051, 0x00000666, _mkword(4, 4), 0x00000000, 1500, 15, 0.0f, 0, 0, 0, 0.0f, _mkword(0, 0), 0, _mkword(0, _mkshort(0, 0)), 0x00000000, _mkword(_mkshort(0, 0), 0), 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    /* Type = Door; index = 70 */
    _mkword(256, _mkshort(0, 1)), _mkword(298, 19), 0x10000400, 0x20000000, 0x00000000, 0x00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000000, 0x00000000, 0, 0, _mkword(1000, 0), 0, 0, 0x00000000, 0x0000f333, 0x0000e70a, 0x00000051, 0x00000051, 0x00000666, _mkword(4, 4), 0x00000000, 1500, 15, 0.0f, 0, 0, 0, 0.0f, _mkword(0, 0), 0, _mkword(0, _mkshort(0, 0)), 0x00000000, _mkword(_mkshort(0, 0), 0), 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    /* Type = EndProps; index = 71 */
    _mkword(0, _mkshort(0, 48))
};


s32 intro[] = {
    /* Type = Spawn; index = 0 */
    _mkword(0, _mkshort(0, 0)), 0, 0,
    /* Type = Spawn; index = 1 */
    _mkword(0, _mkshort(0, 0)), 1, 0,
    /* Type = Spawn; index = 2 */
    _mkword(0, _mkshort(0, 0)), 2, 0,
    /* Type = Spawn; index = 3 */
    _mkword(0, _mkshort(0, 0)), 3, 0,
    /* Type = Spawn; index = 4 */
    _mkword(0, _mkshort(0, 0)), 4, 0,
    /* Type = Spawn; index = 5 */
    _mkword(0, _mkshort(0, 0)), 37, 0,
    /* Type = Spawn; index = 6 */
    _mkword(0, _mkshort(0, 0)), 38, 0,
    /* Type = Spawn; index = 7 */
    _mkword(0, _mkshort(0, 0)), 39, 0,
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




