#include <ultra64.h>

#include <bondtypes.h>
#include <bondconstants.h>
#include <fr.h>
#include "bg.h"
#include "bondview.h"
#include "fog.h"
#include <limits.h>

/**
 * Address 0x800825C0.
*/
s32 g_FogSkyIsEnabled;

/**
 * Address 0x800825C4.
*/
NearFogRecord *g_NearFogValuesP;

/**
 * Address 0x800825C8. Private struct to this file only
*/
struct FogDetails
{
    f32 g_CurFogDetails;
    f32 scaled_far_fog_dist;
    u32 unk08;
    u32 unk0c;
    f32 far_fog_dist_scaled;
    f32 near_fog_dist_scaled;
} g_CurFogDetails;

/**
 * Address 0x800825E0.
*/
f32 g_FarFogIntensity;

/**
 * Address 0x800825E4.
*/
f32 g_DifferenceFromFarFogIntensity;

/**
 * Address 0x800825E8.
*/
EnvironmentRecord *g_EnvironmentFoundp;

/**
 * Address 0x800825EC.
*/
EnvironmentRecord * g_EnvironmentMainp;

/**
 * Address 0x800825F0.
*/
EnvironmentRecord * g_EnvironmentAltp;

/**
 * Unreferenced.
 * 
 * Address 0x800825F4.
*/
s32 D_800825F4;

#if defined(VERSION_EU)
struct NearFogRecordF eu_loadCurrentNearFog;
#endif

/**
 * Unreferenced.
 * 
 * Address 0x80044DC0.
*/
s32 D_80044DC0 = 0;


/**
 * Address 0x80044DC4.
*/
f32 g_ScaledFarFogIntensity = FLT_MAX;

/**
 * Address 0x80044DC8.
*/
f32 g_ScaledDifferenceFromFarFogIntensity = 0.0;

/**
 * Address 0x80044DCC.
*/
CurrentEnvironmentRecord g_CurrentEnvironment = { 
    0x384, // s32 DifferenceFromFarIntensity;
    0x3e8, // u32 FarIntensity;
        0,     // u8  Red;
        0,     // u8  Green;
        0,     // u8  Blue;
        0,     // u8  Clouds;
        0.0f,  // f32 CloudRepeat;
        0,     // s16 SkyImageId;
        0,
        0.0f,  // f32 CloudRed;
        0.0f,  // f32 CloudGreen;
        0.0f,  // f32 CloudBlue;
        0,     // u8  IsWater;
        0,0,0,
        0.0f,  // f32 WaterRepeat;
        0,     // s16 WaterImageId;
        0,
        0.0f,  // f32 WaterRed;
        0.0f,  // f32 WaterGreen;
        0.0f,  // f32 WaterBlue;
        0.0f  // f32 WaterConcavity;
};

s32 D_80044E08 = 0;
s32 D_80044E0C = 0;

#if defined(VERSION_EU)
EnvironmentRecord fog_tables[] = {
     //stageID                              blendmultiplier    farfog    nearfog  mvisrng  mobfnrng  dif_ght  far_alight    red     green     blue    clouds   cloudrept  skymid, cloudred   green    blue   iswater  waterrepeat  waterid  water red,green,blue  waterconcavity
    {LEVELID_STATUE                             ,        15,      3500,    2000,     2500,    2000,    0x3E4,    0x3E8,       0,       0,       8,        1,      5000,       0,      170,    100,     40,        0,       -1000,       0,       0,     0,    0,    30.0 },
    {LEVELID_CONTROL                            ,        10,     10000,    2500,     5000,     800,    0x3E4,    0x3E8,       0,       0,       0,        0,         0,       0,        0,      0,      0,        0,           0,       0,       0,     0,    0,     0.0 },
    {LEVELID_ARCHIVES                           ,        10,      3000,    2000,     3000,     500,    0x3E4,    0x3E8,       0,       0,       0,        1,      5000,       0,      255,    255,    255,        0,       -1000,       0,       0,     0,    0,     0.0 },
    {LEVELID_TRAIN                              ,        10,      1500,       0,        0,       0,    0x3E4,    0x3E8,       0,       0,       8,        1,      5000,       0,      255,    255,    255,        0,           0,       1,       0,   255,  255,    25.0 },
    {LEVELID_TRAIN + ENVIRONMENTDATA_ALT        ,        20,     15000,       0,        0,       0,    0x3E4,    0x3E8,       0,       0,       8,        1,      5000,       0,      255,    255,    255,        0,           0,       1,       0,   255,  255,    25.0 },
    {LEVELID_STREETS                            ,        10,      7500,    5000,     6000,    1000,    0x3E4,    0x3E8,    0x10,    0x18,    0x20,        1,      5000,       0,      225,    175,    100,        0,       -1000,       0,       0,     0,    0,    25.0 },
    {LEVELID_DEPOT                              ,        10,      3000,    1600,     2000,     800,    0x3E4,    0x3E8,       0,       0,       8,        1,      7500,       0,       70,    199,    186,        0,       -1000,       1,       0,   255,  255,    25.0 },
    {LEVELID_COMPLEX                            ,        10,      5000,       0,        0,       0,    0x3E4,    0x3E8,    0x28,       0,       0,        1,     10000,       0,      220,      0,     20,        0,           0,       0,       0,     0,    0,     0.0 },
    {LEVELID_DAM                                ,         5,     15000,    3333,     4444,     600,    0x3E3,    0x3E8,    0x10,    0x30,    0x60,        1,      5000,       0,      255,    255,    255,        0,       -1000,       0,       0,     0,    0,     0.0 },
    {LEVELID_DAM + ENVIRONMENTDATA_CINEMA       ,        30,     15000,    3333,     4444,     600,    0x3E3,    0x3E8,    0x10,    0x30,    0x60,        1,      5000,       0,      255,    255,    255,        0,       -1000,       0,       0,     0,    0,     0.0 },
    {LEVELID_FACILITY                           ,        10,      5000,       0,        0,       0,    0x3DE,    0x3E8,    0x10,    0x20,    0x10,        0,      5000,       0,      255,    255,    255,        0,       -1000,       0,       0,     0,    0,     0.0 },
    {LEVELID_FACILITY + ENVIRONMENTDATA_ALT     ,        10,      1000,       0,        0,       0,    0x3DE,    0x3E8,    0x40,    0x80,    0x40,        0,      5000,       0,      255,    255,    255,        0,           0,       0,       0,     0,    0,     0.0 },
    {LEVELID_RUNWAY                             ,        10,     15000,    6000,     8000,     800,    0x3E4,    0x3E8,    0x10,    0x30,    0x40,        1,      5000,       0,       25,     25,     25,        0,       -1000,       0,       0,     0,    0,     0.0 },
    {LEVELID_SURFACE                            ,         2,      2500,    4444,     5555,     800,    0x3E4,    0x3E8,    0x60,    0x60,    0x80,        1,     10000,       0,      240,    120,    30,         0,           0,       1,       0,   255,  255,     7.0 },
    {LEVELID_JUNGLE                             ,        10,      2500,    1500,     2500,    1000,    0x3E4,    0x3E8,    0x18,    0x20,       0,        0,      5000,       0,      255,    255,    255,        0,           0,       0,       0,     0,    0,     0.0 },
    {LEVELID_TEMPLE                             ,        10,      6000,       0,        0,       0,    0x3E4,    0x3E8,    0x18,    0x18,    0x28,        1,     10000,       0,      160,    160,    190,        0,        -500,       0,       0,     0,    0,     0.0 },
    {LEVELID_CAVERNS                            ,        10,      6000,       0,        0,       0,    0x3E1,    0x3E8,       8,       0,       8,        0,      5000,       0,      255,    255,    255,        0,       -3000,       1,       0,   255,  255,     0.0 },
    {LEVELID_CRADLE                             ,        10,      9500,    3333,     4444,     800,    0x3E4,    0x3E8,    0x60,    0x80,    0xA0,        1,      5000,       0,      255,    255,      0,        0,      -10000,       1,       0,   255,  255,     0.0 },
    {LEVELID_SURFACE2                           ,         2,      2000,    2500,     3055,     750,    0x3BD,    0x3E8,    0x20,    0x10,    0x10,        1,      5000,       0,       58,     17,      0,        0,       -1000,       1,       0,   255,  255,    20.0 },
    {LEVELID_SURFACE2 + ENVIRONMENTDATA_CINEMA  ,         2,      8000,    6000,     8000,     800,    0x3DF,    0x3E8,    0x20,    0x10,    0x10,        1,      5000,       0,       58,     17,      0,        0,       -1000,       1,       0,   255,  255,     0.0 },
    {LEVELID_BUNKER2                            ,        10,     10000,    1000,    15000,     750,    0x3E4,    0x41A,    0x10,       0,       0,        1,      5000,       0,       58,     17,      0,        0,       -1000,       1,       0,   255,  255,     0.0 },
    {LEVELID_BUNKER1 + ENVIRONMENTDATA_PLAYERS_2,        10,      2500,       0,        0,       0,    0x3E4,    0x3E8,    0x80,    0x78,    0x70,        0,         0,       0,      130,    120,    110,        0,           0,       0,       0,     0,    0,     0.0 },
    {LEVELID_BUNKER1 + ENVIRONMENTDATA_PLAYERS_3,        10,      2000,       0,        0,       0,    0x3E4,    0x3E8,    0x80,    0x78,    0x70,        0,         0,       0,      130,    120,    110,        0,           0,       0,       0,     0,    0,     0.0 },
    {LEVELID_BUNKER1 + ENVIRONMENTDATA_PLAYERS_4,        10,      1500,       0,        0,       0,    0x3E4,    0x3E8,    0x80,    0x78,    0x70,        0,         0,       0,      130,    120,    110,        0,           0,       0,       0,     0,    0,     0.0 },
    {LEVELID_CRADLE + ENVIRONMENTDATA_PLAYERS_2 ,        10,      7000,    3333,     4444,     800,    0x3E4,    0x3E8,    0x60,    0x80,    0xA0,        1,      5000,       0,      255,    255,      0,        0,      -10000,       1,       0,   255,  255,     0.0 },
    {LEVELID_CRADLE + ENVIRONMENTDATA_PLAYERS_3 ,        10,      5500,    3333,     4444,     800,    0x3E4,    0x3E8,    0x60,    0x80,    0xA0,        1,      5000,       0,      255,    255,      0,        0,      -10000,       1,       0,   255,  255,     0.0 },
    {LEVELID_CRADLE + ENVIRONMENTDATA_PLAYERS_4 ,        10,      4000,    3333,     4444,     800,    0x3E4,    0x3E8,    0x60,    0x80,    0xA0,        1,      5000,       0,      255,    255,      0,        0,      -10000,       1,       0,   255,  255,     0.0 },
    {LEVELID_TEMPLE + ENVIRONMENTDATA_PLAYERS_2 ,        10,      6000,       0,        0,       0,    0x3E4,    0x3E8,    0x18,    0x18,    0x18,        1,     10000,       0,      120,    120,    120,        0,        -500,       0,       0,     0,    0,     0.0 },
    {LEVELID_TEMPLE + ENVIRONMENTDATA_PLAYERS_3 ,        10,      6000,       0,        0,       0,    0x3E4,    0x3E8,    0x18,    0x18,    0x18,        1,     10000,       0,      120,    120,    120,        0,        -500,       0,       0,     0,    0,     0.0 },
    {LEVELID_TEMPLE + ENVIRONMENTDATA_PLAYERS_4 ,        10,      6000,       0,        0,       0,    0x3E4,    0x3E8,    0x18,    0x18,    0x18,        1,     10000,       0,      120,    120,    120,        0,        -500,       0,       0,     0,    0,     0.0 },
    {LEVELID_CAVERNS + ENVIRONMENTDATA_PLAYERS_2,        10,      7500,       0,        0,       0,    0x3E1,    0x3E8,       8,       0,       8,        0,      5000,       0,      255,    255,    255,        0,       -3000,       1,       0,   255,  255,     0.0 },
    {LEVELID_CAVERNS + ENVIRONMENTDATA_PLAYERS_3,        10,      6000,       0,        0,       0,    0x3E1,    0x3E8,       8,       0,       8,        0,      5000,       0,      255,    255,    255,        0,       -3000,       1,       0,   255,  255,     0.0 },
    {LEVELID_CAVERNS + ENVIRONMENTDATA_PLAYERS_4,        10,      5000,       0,        0,       0,    0x3E1,    0x3E8,       8,       0,       8,        0,      5000,       0,      255,    255,    255,        0,       -3000,       1,       0,   255,  255,     0.0 },
    {LEVELID_DEFAULT + ENVIRONMENTDATA_PLAYERS_2,        10,      7500,       0,        0,       0,    0x3E4,    0x3E8,       0,       0,       0,        0,         0,       0,        0,      0,      0,        0,           0,       0,       0,     0,    0,     0.0 },
    {LEVELID_DEFAULT + ENVIRONMENTDATA_PLAYERS_3,        10,      6000,       0,        0,       0,    0x3E4,    0x3E8,       0,       0,       0,        0,         0,       0,        0,      0,      0,        0,           0,       0,       0,     0,    0,     0.0 },
    {LEVELID_DEFAULT + ENVIRONMENTDATA_PLAYERS_4,        10,      5000,       0,        0,       0,    0x3E4,    0x3E8,       0,       0,       0,        0,         0,       0,        0,      0,      0,        0,           0,       0,       0,     0,    0,     0.0 },
    {LEVELID_CITADEL                            ,        10,     20000,       0,        0,       0,    0x3E4,    0x3E8,    0x18,    0x50,    0x38,        1,      5000,       0,      255,    108,      0,        0,       -1000,       1,       0,   255,  255,     0.0 },
    {LEVELID_CITADEL + ENVIRONMENTDATA_PLAYERS_2,        10,     20000,       0,        0,       0,    0x3E4,    0x3E8,    0x18,    0x50,    0x38,        1,      5000,       0,      255,    108,      0,        0,       -1000,       1,       0,   255,  255,     0.0 },
    {LEVELID_CITADEL + ENVIRONMENTDATA_PLAYERS_3,        10,     20000,       0,        0,       0,    0x3E4,    0x3E8,    0x18,    0x50,    0x38,        1,      5000,       0,      255,    108,      0,        0,       -1000,       1,       0,   255,  255,     0.0 },
    {LEVELID_CITADEL + ENVIRONMENTDATA_PLAYERS_4,        10,     20000,       0,        0,       0,    0x3E4,    0x3E8,    0x18,    0x50,    0x38,        1,      5000,       0,      255,    108,      0,        0,       -1000,       1,       0,   255,  255,     0.0 },
    {LEVELID_COMPLEX + ENVIRONMENTDATA_PLAYERS_2,        10,      5000,       0,        0,       0,    0x3E4,    0x3E8,    0x28,       0,       0,        1,     10000,       0,      220,      0,     20,        0,           0,       0,       0,     0,    0,     0.0 },
    {LEVELID_COMPLEX + ENVIRONMENTDATA_PLAYERS_3,        10,      5000,       0,        0,       0,    0x3E4,    0x3E8,    0x28,       0,       0,        1,     10000,       0,      220,      0,     20,        0,           0,       0,       0,     0,    0,     0.0 },
    {LEVELID_COMPLEX + ENVIRONMENTDATA_PLAYERS_4,        10,      5000,       0,        0,       0,    0x3E4,    0x3E8,    0x28,       0,       0,        1,     10000,       0,      220,      0,     20,        0,           0,       0,       0,     0,    0,     0.0 },
    {LEVELID_AZTEC                              ,        10,     15000,    3000,     4000,     600,    0x3E4,    0x3E8,       0,       0,       0,        1,      7500,       0,       83,     72,     65,        0,       -5000,       0,       0,     0,    0,     0.0 },
    {LEVELID_AZTEC + ENVIRONMENTDATA_ALT        ,        30,     15000,    3000,     4000,     600,    0x3E4,    0x3E8,       0,       0,       0,        1,      7500,       0,       83,     72,     65,        0,       -5000,       0,       0,     0,    0,     0.0 },
    {LEVELID_EGYPT                              ,        10,     20000,    3000,     4000,     600,    0x3E4,    0x3E8,    0x10,    0x30,    0x60,        1,      5000,       0,      255,    255,    255,        0,       -5000,       0,       0,     0,    0,     0.0 },
    {LEVELID_EGYPT + ENVIRONMENTDATA_ALT        ,        10,     10000,    3000,     4000,     600,    0x3CC,    0x3E8,       0,       0,       0,        1,      7500,       0,       83,     10,     10,        0,       -5000,       0,       0,     0,    0,     0.0 },
    {ENVIRONMENTDATA_END},
};
#else
/**
 * Address 0x80044E10.
*/
EnvironmentRecord fog_tables[] = {
     //stageID                              blendmultiplier    farfog    nearfog  mvisrng  mobfnrng  mnvisrng   intensity  dif_ght  far_alight    red     green     blue    clouds   cloudrept skyimid reserved  cloudred   green    blue   iswater  padding[3]  waterrepeat  waterid reserved2   water red,green,blue  waterconcavity
    {LEVELID_STATUE                             ,        15,      3500,    2000,     2500,    2000,        0,      0x3E7,    0x3E4,    0x3E8,       0,       0,       8,        1,      5000,    0,        0,        170,    100,     40,        0,    0,0,0,         -1000,       0,        0,        0,     0,    0,    30.0 },
    {LEVELID_CONTROL                            ,        10,     10000,    2500,     5000,     800,        0,      0x3E7,    0x3E4,    0x3E8,       0,       0,       0,        0,         0,    0,        0,          0,      0,      0,        0,    0,0,0,             0,       0,        0,        0,     0,    0,     0.0 },
    {LEVELID_ARCHIVES                           ,        10,      3000,    2000,     3000,     500,        0,      0x3E7,    0x3E4,    0x3E8,       0,       0,       0,        1,      5000,    0,        0,        255,    255,    255,        0,    0,0,0,         -1000,       0,        0,        0,     0,    0,     0.0 },
    {LEVELID_TRAIN                              ,        10,      1500,       0,        0,       0,        0,      0x3E7,    0x3E4,    0x3E8,       0,       0,       8,        1,      5000,    0,        0,        255,    255,    255,        0,    0,0,0,             0,       1,        0,        0,   255,  255,    25.0 },
    {LEVELID_TRAIN + ENVIRONMENTDATA_ALT        ,        20,     15000,       0,        0,       0,        0,      0x3E7,    0x3E4,    0x3E8,       0,       0,       8,        1,      5000,    0,        0,        255,    255,    255,        0,    0,0,0,             0,       1,        0,        0,   255,  255,    25.0 },
    {LEVELID_STREETS                            ,        10,      7500,    5000,     6000,    1000,        0,      0x3E7,    0x3E4,    0x3E8,    0x10,    0x18,    0x20,        1,      5000,    0,        0,        225,    175,    100,        0,    0,0,0,         -1000,       0,        0,        0,     0,    0,    25.0 },
    {LEVELID_DEPOT                              ,        10,      3000,    1600,     2000,     800,        0,      0x3E7,    0x3E4,    0x3E8,       0,       0,       8,        1,      7500,    0,        0,         70,    199,    186,        0,    0,0,0,         -1000,       1,        0,        0,   255,  255,    25.0 },
    {LEVELID_COMPLEX                            ,        10,      5000,       0,        0,       0,        0,      0x3E7,    0x3E4,    0x3E8,    0x28,       0,       0,        1,     10000,    0,        0,        220,      0,     20,        0,    0,0,0,             0,       0,        0,        0,     0,    0,     0.0 },
    {LEVELID_DAM                                ,         5,     15000,    3333,     4444,     600,        0,      0x3E7,    0x3E3,    0x3E8,    0x10,    0x30,    0x60,        1,      5000,    0,        0,        255,    255,    255,        0,    0,0,0,         -1000,       0,        0,        0,     0,    0,     0.0 },
    {LEVELID_DAM + ENVIRONMENTDATA_CINEMA       ,        30,     15000,    3333,     4444,     600,        0,      0x3E7,    0x3E3,    0x3E8,    0x10,    0x30,    0x60,        1,      5000,    0,        0,        255,    255,    255,        0,    0,0,0,         -1000,       0,        0,        0,     0,    0,     0.0 },
    {LEVELID_FACILITY                           ,        10,      5000,       0,        0,       0,        0,      0x3E7,    0x3DE,    0x3E8,    0x10,    0x20,    0x10,        0,      5000,    0,        0,        255,    255,    255,        0,    0,0,0,         -1000,       0,        0,        0,     0,    0,     0.0 },
    {LEVELID_FACILITY + ENVIRONMENTDATA_ALT     ,        10,      1000,       0,        0,       0,        0,      0x3E7,    0x3DE,    0x3E8,    0x40,    0x80,    0x40,        0,      5000,    0,        0,        255,    255,    255,        0,    0,0,0,             0,       0,        0,        0,     0,    0,     0.0 },
    {LEVELID_RUNWAY                             ,        10,     15000,    6000,     8000,     800,        0,      0x3E7,    0x3E4,    0x3E8,    0x10,    0x30,    0x40,        1,      5000,    0,        0,         25,     25,     25,        0,    0,0,0,         -1000,       0,        0,        0,     0,    0,     0.0 },
    {LEVELID_SURFACE                            ,         2,      2500,    4444,     5555,     800,        0,      0x3E7,    0x3E4,    0x3E8,    0x60,    0x60,    0x80,        1,     10000,    0,        0,        240,    120,    30,         0,    0,0,0,             0,       1,        0,        0,   255,  255,     7.0 },
    {LEVELID_JUNGLE                             ,        10,      2500,    1500,     2500,    1000,        0,      0x3E7,    0x3E4,    0x3E8,    0x18,    0x20,       0,        0,      5000,    0,        0,        255,    255,    255,        0,    0,0,0,             0,       0,        0,        0,     0,    0,     0.0 },
    {LEVELID_TEMPLE                             ,        10,      6000,       0,        0,       0,        0,      0x3E7,    0x3E4,    0x3E8,    0x18,    0x18,    0x28,        1,     10000,    0,        0,        160,    160,    190,        0,    0,0,0,          -500,       0,        0,        0,     0,    0,     0.0 },
    {LEVELID_CAVERNS                            ,        10,      6000,       0,        0,       0,        0,      0x3E7,    0x3E1,    0x3E8,       8,       0,       8,        0,      5000,    0,        0,        255,    255,    255,        0,    0,0,0,         -3000,       1,        0,        0,   255,  255,     0.0 },
    {LEVELID_CRADLE                             ,        10,      9500,    3333,     4444,     800,        0,      0x3E7,    0x3E4,    0x3E8,    0x60,    0x80,    0xA0,        1,      5000,    0,        0,        255,    255,      0,        0,    0,0,0,        -10000,       1,        0,        0,   255,  255,     0.0 },
    {LEVELID_SURFACE2                           ,         2,      2000,    2500,     3055,     750,        0,      0x3E7,    0x3BD,    0x3E8,    0x20,    0x10,    0x10,        1,      5000,    0,        0,         58,     17,      0,        0,    0,0,0,         -1000,       1,        0,        0,   255,  255,    20.0 },
    {LEVELID_SURFACE2 + ENVIRONMENTDATA_CINEMA  ,         2,      8000,    6000,     8000,     800,        0,      0x3E7,    0x3DF,    0x3E8,    0x20,    0x10,    0x10,        1,      5000,    0,        0,         58,     17,      0,        0,    0,0,0,         -1000,       1,        0,        0,   255,  255,     0.0 },
    {LEVELID_BUNKER2                            ,        10,     10000,    1000,    15000,     750,        0,      0x3E7,    0x3E4,    0x41A,    0x10,       0,       0,        1,      5000,    0,        0,         58,     17,      0,        0,    0,0,0,         -1000,       1,        0,        0,   255,  255,     0.0 },
    {LEVELID_BUNKER1 + ENVIRONMENTDATA_PLAYERS_2,        10,      2500,       0,        0,       0,        0,      0x3E7,    0x3E4,    0x3E8,    0x80,    0x78,    0x70,        0,         0,    0,        0,        130,    120,    110,        0,    0,0,0,             0,       0,        0,        0,     0,    0,     0.0 },
    {LEVELID_BUNKER1 + ENVIRONMENTDATA_PLAYERS_3,        10,      2000,       0,        0,       0,        0,      0x3E7,    0x3E4,    0x3E8,    0x80,    0x78,    0x70,        0,         0,    0,        0,        130,    120,    110,        0,    0,0,0,             0,       0,        0,        0,     0,    0,     0.0 },
    {LEVELID_BUNKER1 + ENVIRONMENTDATA_PLAYERS_4,        10,      1500,       0,        0,       0,        0,      0x3E7,    0x3E4,    0x3E8,    0x80,    0x78,    0x70,        0,         0,    0,        0,        130,    120,    110,        0,    0,0,0,             0,       0,        0,        0,     0,    0,     0.0 },
    {LEVELID_CRADLE + ENVIRONMENTDATA_PLAYERS_2 ,        10,      7000,    3333,     4444,     800,        0,      0x3E7,    0x3E4,    0x3E8,    0x60,    0x80,    0xA0,        1,      5000,    0,        0,        255,    255,      0,        0,    0,0,0,        -10000,       1,        0,        0,   255,  255,     0.0 },
    {LEVELID_CRADLE + ENVIRONMENTDATA_PLAYERS_3 ,        10,      5500,    3333,     4444,     800,        0,      0x3E7,    0x3E4,    0x3E8,    0x60,    0x80,    0xA0,        1,      5000,    0,        0,        255,    255,      0,        0,    0,0,0,        -10000,       1,        0,        0,   255,  255,     0.0 },
    {LEVELID_CRADLE + ENVIRONMENTDATA_PLAYERS_4 ,        10,      4000,    3333,     4444,     800,        0,      0x3E7,    0x3E4,    0x3E8,    0x60,    0x80,    0xA0,        1,      5000,    0,        0,        255,    255,      0,        0,    0,0,0,        -10000,       1,        0,        0,   255,  255,     0.0 },
    {LEVELID_TEMPLE + ENVIRONMENTDATA_PLAYERS_2 ,        10,      6000,       0,        0,       0,        0,      0x3E7,    0x3E4,    0x3E8,    0x18,    0x18,    0x18,        1,     10000,    0,        0,        120,    120,    120,        0,    0,0,0,          -500,       0,        0,        0,     0,    0,     0.0 },
    {LEVELID_TEMPLE + ENVIRONMENTDATA_PLAYERS_3 ,        10,      6000,       0,        0,       0,        0,      0x3E7,    0x3E4,    0x3E8,    0x18,    0x18,    0x18,        1,     10000,    0,        0,        120,    120,    120,        0,    0,0,0,          -500,       0,        0,        0,     0,    0,     0.0 },
    {LEVELID_TEMPLE + ENVIRONMENTDATA_PLAYERS_4 ,        10,      6000,       0,        0,       0,        0,      0x3E7,    0x3E4,    0x3E8,    0x18,    0x18,    0x18,        1,     10000,    0,        0,        120,    120,    120,        0,    0,0,0,          -500,       0,        0,        0,     0,    0,     0.0 },
    {LEVELID_CAVERNS + ENVIRONMENTDATA_PLAYERS_2,        10,      7500,       0,        0,       0,        0,      0x3E7,    0x3E1,    0x3E8,       8,       0,       8,        0,      5000,    0,        0,        255,    255,    255,        0,    0,0,0,         -3000,       1,        0,        0,   255,  255,     0.0 },
    {LEVELID_CAVERNS + ENVIRONMENTDATA_PLAYERS_3,        10,      6000,       0,        0,       0,        0,      0x3E7,    0x3E1,    0x3E8,       8,       0,       8,        0,      5000,    0,        0,        255,    255,    255,        0,    0,0,0,         -3000,       1,        0,        0,   255,  255,     0.0 },
    {LEVELID_CAVERNS + ENVIRONMENTDATA_PLAYERS_4,        10,      5000,       0,        0,       0,        0,      0x3E7,    0x3E1,    0x3E8,       8,       0,       8,        0,      5000,    0,        0,        255,    255,    255,        0,    0,0,0,         -3000,       1,        0,        0,   255,  255,     0.0 },
    {LEVELID_DEFAULT + ENVIRONMENTDATA_PLAYERS_2,        10,      7500,       0,        0,       0,        0,      0x3E7,    0x3E4,    0x3E8,       0,       0,       0,        0,         0,    0,        0,          0,      0,      0,        0,    0,0,0,             0,       0,        0,        0,     0,    0,     0.0 },
    {LEVELID_DEFAULT + ENVIRONMENTDATA_PLAYERS_3,        10,      6000,       0,        0,       0,        0,      0x3E7,    0x3E4,    0x3E8,       0,       0,       0,        0,         0,    0,        0,          0,      0,      0,        0,    0,0,0,             0,       0,        0,        0,     0,    0,     0.0 },
    {LEVELID_DEFAULT + ENVIRONMENTDATA_PLAYERS_4,        10,      5000,       0,        0,       0,        0,      0x3E7,    0x3E4,    0x3E8,       0,       0,       0,        0,         0,    0,        0,          0,      0,      0,        0,    0,0,0,             0,       0,        0,        0,     0,    0,     0.0 },
    {LEVELID_CITADEL                            ,        10,     20000,       0,        0,       0,        0,      0x3E7,    0x3E4,    0x3E8,    0x18,    0x50,    0x38,        1,      5000,    0,        0,        255,    108,      0,        0,    0,0,0,         -1000,       1,        0,        0,   255,  255,     0.0 },
    {LEVELID_CITADEL + ENVIRONMENTDATA_PLAYERS_2,        10,     20000,       0,        0,       0,        0,      0x3E7,    0x3E4,    0x3E8,    0x18,    0x50,    0x38,        1,      5000,    0,        0,        255,    108,      0,        0,    0,0,0,         -1000,       1,        0,        0,   255,  255,     0.0 },
    {LEVELID_CITADEL + ENVIRONMENTDATA_PLAYERS_3,        10,     20000,       0,        0,       0,        0,      0x3E7,    0x3E4,    0x3E8,    0x18,    0x50,    0x38,        1,      5000,    0,        0,        255,    108,      0,        0,    0,0,0,         -1000,       1,        0,        0,   255,  255,     0.0 },
    {LEVELID_CITADEL + ENVIRONMENTDATA_PLAYERS_4,        10,     20000,       0,        0,       0,        0,      0x3E7,    0x3E4,    0x3E8,    0x18,    0x50,    0x38,        1,      5000,    0,        0,        255,    108,      0,        0,    0,0,0,         -1000,       1,        0,        0,   255,  255,     0.0 },
    {LEVELID_COMPLEX + ENVIRONMENTDATA_PLAYERS_2,        10,      5000,       0,        0,       0,        0,      0x3E7,    0x3E4,    0x3E8,    0x28,       0,       0,        1,     10000,    0,        0,        220,      0,     20,        0,    0,0,0,             0,       0,        0,        0,     0,    0,     0.0 },
    {LEVELID_COMPLEX + ENVIRONMENTDATA_PLAYERS_3,        10,      5000,       0,        0,       0,        0,      0x3E7,    0x3E4,    0x3E8,    0x28,       0,       0,        1,     10000,    0,        0,        220,      0,     20,        0,    0,0,0,             0,       0,        0,        0,     0,    0,     0.0 },
    {LEVELID_COMPLEX + ENVIRONMENTDATA_PLAYERS_4,        10,      5000,       0,        0,       0,        0,      0x3E7,    0x3E4,    0x3E8,    0x28,       0,       0,        1,     10000,    0,        0,        220,      0,     20,        0,    0,0,0,             0,       0,        0,        0,     0,    0,     0.0 },
    {LEVELID_AZTEC                              ,        10,     15000,    3000,     4000,     600,        0,      0x3E7,    0x3E4,    0x3E8,       0,       0,       0,        1,      7500,    0,        0,         83,     72,     65,        0,    0,0,0,         -5000,       0,        0,        0,     0,    0,     0.0 },
    {LEVELID_AZTEC + ENVIRONMENTDATA_ALT        ,        30,     15000,    3000,     4000,     600,        0,      0x3E7,    0x3E4,    0x3E8,       0,       0,       0,        1,      7500,    0,        0,         83,     72,     65,        0,    0,0,0,         -5000,       0,        0,        0,     0,    0,     0.0 },
    {LEVELID_EGYPT                              ,        10,     20000,    3000,     4000,     600,        0,      0x3E7,    0x3E4,    0x3E8,    0x10,    0x30,    0x60,        1,      5000,    0,        0,        255,    255,    255,        0,    0,0,0,         -5000,       0,        0,        0,     0,    0,     0.0 },
    {LEVELID_EGYPT + ENVIRONMENTDATA_ALT        ,        10,     10000,    3000,     4000,     600,        0,      0x3E7,    0x3CC,    0x3E8,       0,       0,       0,        1,      7500,    0,        0,         83,     10,     10,        0,    0,0,0,         -5000,       0,        0,        0,     0,    0,     0.0 },
    {ENVIRONMENTDATA_END},
};
#endif


EnvironmentFoglessRecord fog_tables2[] = {
    {LEVELID_NONE   ,    0,       0x10,    0x40,    0,        5000.0,        0,        0,        255.0,        255.0,        255.0,        0,        0,        0,        0,           0.0,        0,        0,          0.0,          0.0,          0.0,        0.0},
    {LEVELID_FRIGATE,    0x10,    0x30,    0x60,    1,        3000.0,        0,        0,        230.0,        230.0,        230.0,        1,        0,        0,        0,        -150.0,        2,        0,        255.0,        255.0,        150.0,        0.0},
    {LEVELID_CUBA   ,    0x30,    0x40,    0x10,    0,        5000.0,        0,        0,        255.0,        255.0,        255.0,        0,        0,        0,        0,           0.0,        0,        0,          0.0,          0.0,          0.0,        0.0},
    {ENVIRONMENTDATA_END}
};

// forward declarations

void fogLoadCurrentEnvironment(EnvironmentRecord *arg0);
void fogLoadFoglessCurrentEnvironment(EnvironmentFoglessRecord *arg0);

// end forward declarations



/**
 * Unreferenced.
 * 
 * Address 0x7F0BA720.
*/
void sub_GAME_7F0BA720(s32 a, s32 b)
{
    return;
}

/**
* @return Pointer to Current Environment
*/
CurrentEnvironmentRecord *fogGetCurrentEnvironmentp(void)
{
    return &g_CurrentEnvironment;
}


/**
 * Unreferenced.
*/
f32 fogGetScaledFarFogIntensity(void)
{
    return g_ScaledFarFogIntensity;
}


f32 fogGetScaledFarFogIntensitySquared(void)
{
    return g_ScaledFarFogIntensity * g_ScaledFarFogIntensity;
}


/**
 * Address 0x7F0BA758.
*/
void fogLoadCurrentEnvironment(EnvironmentRecord *arg0)
{
    f32 zrange[2]; // 48
    f32 pk0;
    f32 pk4;
    f32 temp_f0;
    f32 sp20; // 32
    f32 sp1C; // 28

    viSetZRange(arg0->Visibility.BlendMultiplier, arg0->Visibility.FarFog);
    viGetZRange(&zrange);

    temp_f0 = bgGetLevelVisibilityScale();
    zrange[0] /= temp_f0;
    zrange[1] /= temp_f0;

    g_DifferenceFromFarFogIntensity = ((f32) arg0->Fog.DifferenceFromFarIntensity / 1000.0f);
    g_FarFogIntensity = ((f32) arg0->Fog.FarIntensity / 1000.0f);

    g_ScaledFarFogIntensity = ((zrange[1] - zrange[0]) *  g_FarFogIntensity) + zrange[0];
    g_ScaledDifferenceFromFarFogIntensity = ((zrange[1] - zrange[0]) * g_DifferenceFromFarFogIntensity) + zrange[0];

    g_CurFogDetails.g_CurFogDetails = (arg0->Visibility.BlendMultiplier / temp_f0);
    pk0 = g_CurFogDetails.g_CurFogDetails;
    g_CurFogDetails.scaled_far_fog_dist = (arg0->Visibility.FarFog / temp_f0);
    pk4 = g_CurFogDetails.scaled_far_fog_dist;

    // numerator is constant 128.0f
    sp20 = (256.0f * (0.5f -         0.0f)) / (g_FarFogIntensity - g_DifferenceFromFarFogIntensity);
    sp1C = (256.0f * (0.5f - g_DifferenceFromFarFogIntensity)) / (g_FarFogIntensity - g_DifferenceFromFarFogIntensity);

    g_CurFogDetails.far_fog_dist_scaled = ((pk4 * -sp20 * (pk0 + 1.0f)) / (pk4 - pk0)) / 255.0f;
    g_CurFogDetails.near_fog_dist_scaled = ((sp20 * (pk4 + 1.0f) / (pk4 - pk0)) + sp1C) / 255.0f;

    g_CurrentEnvironment.DifferenceFromFarIntensity = (s32) arg0->Fog.DifferenceFromFarIntensity;
    g_CurrentEnvironment.FarIntensity = arg0->Fog.FarIntensity;
    g_CurrentEnvironment.Red = arg0->Sky.Red;
    g_CurrentEnvironment.Green = arg0->Sky.Green;
    g_CurrentEnvironment.Blue = arg0->Sky.Blue;
    g_CurrentEnvironment.Clouds = arg0->Sky.Clouds;
    g_CurrentEnvironment.CloudRepeat = arg0->Sky.CloudRepeat;
    g_CurrentEnvironment.SkyImageId = (s16) arg0->Sky.SkyImageId;
    g_CurrentEnvironment.CloudRed = arg0->Sky.CloudRed;
    g_CurrentEnvironment.CloudGreen = arg0->Sky.CloudGreen;
    g_CurrentEnvironment.CloudBlue = arg0->Sky.CloudBlue;
    g_CurrentEnvironment.IsWater = arg0->Sky.IsWater;
    g_CurrentEnvironment.WaterRepeat = arg0->Sky.WaterRepeat;
    g_CurrentEnvironment.WaterImageId = (s16) arg0->Sky.WaterImageId;
    g_CurrentEnvironment.WaterRed = arg0->Sky.WaterRed;
    g_CurrentEnvironment.WaterGreen = arg0->Sky.WaterGreen;
    g_CurrentEnvironment.WaterBlue = arg0->Sky.WaterBlue;
    g_CurrentEnvironment.WaterConcavity = arg0->Sky.WaterConcavity;

#if defined(VERSION_EU)
    #define FOG_ZERO 0
#else
    #define FOG_ZERO 0.0f
#endif
    
    if (arg0->Visibility.Nfd.NearFog == FOG_ZERO)
    {
        g_NearFogValuesP = NULL;
    }
    else
    {
#if defined(VERSION_EU)
        eu_loadCurrentNearFog.NearFog = arg0->Visibility.Nfd.NearFog;
        eu_loadCurrentNearFog.MaxVisRange = arg0->Visibility.Nfd.MaxVisRange;
        eu_loadCurrentNearFog.MaxObfuscationRange = arg0->Visibility.Nfd.MaxObfuscationRange;
        g_NearFogValuesP = &eu_loadCurrentNearFog;
#else
        g_NearFogValuesP = &arg0->Visibility.Nfd;
#endif
    }

#undef FOG_ZERO

    g_FogSkyIsEnabled = 1;
}

/**
 * Address 0x7F0BA9D0.
*/
void fogLoadFoglessCurrentEnvironment(EnvironmentFoglessRecord *arg0)
{
    g_CurrentEnvironment.Red = arg0->Red;
    g_CurrentEnvironment.Green = arg0->Green;
    g_CurrentEnvironment.Blue = arg0->Blue;
    g_CurrentEnvironment.Clouds = arg0->Clouds;
    g_CurrentEnvironment.CloudRepeat = arg0->CloudRepeat;
    g_CurrentEnvironment.SkyImageId = arg0->SkyImageId;
    g_CurrentEnvironment.CloudRed = arg0->CloudRed;
    g_CurrentEnvironment.CloudGreen = arg0->CloudGreen;
    g_CurrentEnvironment.CloudBlue = arg0->CloudBlue;
    g_CurrentEnvironment.IsWater = arg0->IsWater;
    g_CurrentEnvironment.WaterRepeat = arg0->WaterRepeat;
    g_CurrentEnvironment.WaterImageId = arg0->WaterImageId;
    g_CurrentEnvironment.WaterRed = arg0->WaterRed;
    g_CurrentEnvironment.WaterGreen = arg0->WaterGreen;
    g_CurrentEnvironment.WaterBlue = arg0->WaterBlue;
    g_CurrentEnvironment.WaterConcavity = arg0->WaterConcavity;
}


/**
 * Address 0x7F0BAA5C.
*/
void fogRemoved7F0BAA5C(s32 a)
{
    return;
}


/**
 * Address 0x7F0BAA64.
*/
void fogLoadLevelEnvironment(s32 level_id, s32 arg1)
{
    EnvironmentRecord *phi_v1;
    EnvironmentFoglessRecord *phi_v2;
    EnvironmentFoglessRecord *sp1C;
    s32 num_players;

    sp1C = NULL;

    num_players = getPlayerCount();
    
    if (num_players == 1)
    {
        num_players = 0;
    }

    g_ScaledFarFogIntensity = FLT_MAX;
    g_ScaledDifferenceFromFarFogIntensity = 0.0f;

    if (arg1)
    {
        for (phi_v1 = &fog_tables[0]; phi_v1->Id != 0; phi_v1++)
        {
            if (phi_v1->Id == (level_id + 900))
            {
                g_EnvironmentFoundp = phi_v1;
                g_EnvironmentMainp = phi_v1;
                g_EnvironmentAltp = phi_v1 + 1;

                fogLoadCurrentEnvironment(g_EnvironmentFoundp);

                return;
            }
        }
    }
    
    for (phi_v1 = &fog_tables[0]; phi_v1->Id != 0; phi_v1++)
    {
        if (phi_v1->Id == (level_id + (num_players * 100)))
        {
            g_EnvironmentFoundp = phi_v1;
            g_EnvironmentMainp = phi_v1;
            g_EnvironmentAltp = phi_v1 + 1;

            fogLoadCurrentEnvironment(g_EnvironmentFoundp);

            return;
        }
    }

    if(1)
    {
        // removed
    }

    if (num_players >= 2)
    {
        for (phi_v1 = &fog_tables[0]; phi_v1->Id != 0; phi_v1++)
        {
            if (phi_v1->Id == (num_players * 100))
            {
                g_EnvironmentFoundp = phi_v1;
                g_EnvironmentMainp = phi_v1;
                g_EnvironmentAltp = phi_v1 + 1;

                fogLoadCurrentEnvironment(g_EnvironmentFoundp);

                return;
            }
        }
    }

    viSetZRange(15.0f, 10000.0f);
    g_FogSkyIsEnabled = 0;

    for (phi_v2 = fog_tables2; phi_v2->Id != 0; phi_v2++)
    {
        if (phi_v2->Id == level_id)
        {
            sp1C = phi_v2;

            if(1)
            {
                // removed.
                // break or return maybe?
            }
        }
    }

    if (sp1C == NULL)
    {
        sp1C = &fog_tables2[0];
    }

    fogLoadFoglessCurrentEnvironment(sp1C);
    g_EnvironmentFoundp = NULL;
}

/**
 * Address 0x7F0BACA8.
 * Switch to next Environment. 
 * @param isTransition: Usually 0 for instant switch or 1 to transition gradually
 */
void fogSwitchToSolosky2(f32 arg0)
{
    static EnvironmentRecord static_envr;

    static_envr = *g_EnvironmentMainp;

    static_envr.Visibility.BlendMultiplier = 
        g_EnvironmentMainp->Visibility.BlendMultiplier
#if defined(VERSION_EU)
        + (arg0 * ((f32)g_EnvironmentAltp->Visibility.BlendMultiplier - (f32)g_EnvironmentMainp->Visibility.BlendMultiplier));
#else
        + (arg0 * (g_EnvironmentAltp->Visibility.BlendMultiplier - g_EnvironmentMainp->Visibility.BlendMultiplier));
#endif

    static_envr.Visibility.FarFog = 
        g_EnvironmentMainp->Visibility.FarFog
#if defined(VERSION_EU)
        + (arg0 * ((f32)g_EnvironmentAltp->Visibility.FarFog - (f32)g_EnvironmentMainp->Visibility.FarFog));
#else
        + (arg0 * (g_EnvironmentAltp->Visibility.FarFog - g_EnvironmentMainp->Visibility.FarFog));
#endif

    static_envr.Fog.DifferenceFromFarIntensity = 
        (f32)g_EnvironmentMainp->Fog.DifferenceFromFarIntensity
        + (arg0 * ((f32)g_EnvironmentAltp->Fog.DifferenceFromFarIntensity - (f32)g_EnvironmentMainp->Fog.DifferenceFromFarIntensity));

    static_envr.Fog.FarIntensity = 
        (f32)g_EnvironmentMainp->Fog.FarIntensity
        + (arg0 * ((f32)g_EnvironmentAltp->Fog.FarIntensity - (f32)g_EnvironmentMainp->Fog.FarIntensity));
    
    static_envr.Sky.Red = 
        (f32)g_EnvironmentMainp->Sky.Red
        + (arg0 * ((f32)g_EnvironmentAltp->Sky.Red - (f32)g_EnvironmentMainp->Sky.Red));

    static_envr.Sky.Green = 
        (f32)g_EnvironmentMainp->Sky.Green
        + (arg0 * ((f32)g_EnvironmentAltp->Sky.Green - (f32)g_EnvironmentMainp->Sky.Green));

    static_envr.Sky.Blue = 
        (f32)g_EnvironmentMainp->Sky.Blue
        + (arg0 * ((f32)g_EnvironmentAltp->Sky.Blue - (f32)g_EnvironmentMainp->Sky.Blue));

    static_envr.Sky.Red &= 0xf8;
    static_envr.Sky.Green &= 0xf8;
    static_envr.Sky.Blue &= 0xf8;

    fogLoadCurrentEnvironment(&static_envr);
}


/**
 * @param gdl:
 * @param arg1: not used?
 * 
 * Address 0x7F0BB070.
*/
Gfx *fogSetRenderFogColor(Gfx *gdl, s32 arg1)
{
    if (g_FogSkyIsEnabled == 0)
    {
        return gdl;
    }

    // note: both branches are exactly the same.
    // maybe one has debug code?
    if (arg1)
    {
        gDPSetFogColor(gdl++, g_CurrentEnvironment.Red, g_CurrentEnvironment.Green, g_CurrentEnvironment.Blue, 0xff);
        gSPFogPosition(gdl++, g_CurrentEnvironment.DifferenceFromFarIntensity, g_CurrentEnvironment.FarIntensity);
    }
    else
    {
        gDPSetFogColor(gdl++, g_CurrentEnvironment.Red, g_CurrentEnvironment.Green, g_CurrentEnvironment.Blue, 0xff);
        gSPFogPosition(gdl++, g_CurrentEnvironment.DifferenceFromFarIntensity, g_CurrentEnvironment.FarIntensity);
    }

    gSPSetGeometryMode(gdl++, G_FOG);
    gDPSetAlphaDither(gdl++, G_AD_NOISE);

    return gdl;
}


/**
 * Address 0x7F0BB298.
*/
Gfx *fogRenderClearFogMode(Gfx *gdl)
{
    if (g_FogSkyIsEnabled == 0)
    {
        return gdl;
    }

    gSPClearGeometryMode(gdl++, G_FOG);

    return gdl;
}


/**
 * Address 0x7F0BB2C8.
*/
s32 fogPositionIsVisibleThroughFog(coord3d *pos, f32 range)
{
    coord3d sp24;
    f32 ff;
    coord3d *player_pos;
    Mtxf *player_mtx;

    if (g_FogSkyIsEnabled == 0)
    {
        return 1;
    }

    player_pos = bondviewGetCurrentPlayersPosition();
    player_mtx = camGetWorldToScreenMtxf();

    sp24.f[0] = pos->f[0] - player_pos->f[0];
    sp24.f[1] = pos->f[1] - player_pos->f[1];
    sp24.f[2] = pos->f[2] - player_pos->f[2];

    ff = (((sp24.f[0] * player_mtx->m[0][0]) + (sp24.f[1] * player_mtx->m[0][1]) + (sp24.f[2] * player_mtx->m[0][2])));

    if (ff > (g_ScaledFarFogIntensity + range))
    {
        return 0;
    }

    return 1;
}


NearFogRecord *fogGetNearFogValuesP(void)
{
    return g_NearFogValuesP;
}


/**
 * Address 0x7F0BB3A4.
*/
s32 fogGetPropDistColor(PropRecord *prop, rgba_f32 *color)
{
    if (g_FogSkyIsEnabled == 0)
    {
        return 2; // No fog, props cannot be obscured by fog
    }

    if (prop->zDepth < 0.0f)
    {
        return 2; // Prop is behind the camera
    }

    color->rgba[0] = (f32) g_CurrentEnvironment.Red / 255.0f;
    color->rgba[1] = (f32) g_CurrentEnvironment.Green / 255.0f;
    color->rgba[2] = (f32) g_CurrentEnvironment.Blue / 255.0f;
    color->rgba[3] = (g_CurFogDetails.far_fog_dist_scaled / prop->zDepth) + g_CurFogDetails.near_fog_dist_scaled;

    if (color->rgba[3] < 0.0f)
    {
        return 2; // Prop has no fog effect coloring applied to it
    }

    if (color->rgba[3] > 1.0f)
    {
        return 0; // Prop is completely obscured by fog (don't render)
    }

    return 1; // Fog color will be applied to prop
}
