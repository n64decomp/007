#include <ultra64.h>
#include <PR/os.h>
#include <PR/gbi.h>
#include <gbi_extension.h>
#include <bondconstants.h>
#include <bondtypes.h>
#include "bg.h"
#include "image_bank.h"
#include "othermodemicrocode.h"
#include "explosions.h"
#include "unk_0BC530.h"
#include <assets/GlobalImageTable.h>

// bss
//CODE.bss:8007A100
char dword_CODE_bss_8007A100[0x40];

/**
 * ptr_smoke_buf = mempAllocBytesInBank(0x1FE0, 4);
 * Address 0x8007A140.
*/
struct Smoke *ptr_smoke_buf;

/**
 * ptr_explosion_buf = mempAllocBytesInBank(0x1740, 4);
 * Address 0x8007A144.
*/
struct Explosion *ptr_explosion_buf;

//CODE.bss:8007A148
s32 max_casings;
//CODE.bss:8007A14C
struct EjectedCasing *ptr_ejected_casing_buf;

/**
 * ptr_scorch_buf = mempAllocBytesInBank(0x6E0, 4);
 * sizeof each entry == 0x58
 * Address 0x8007A150.
*/
struct Scorch *ptr_scorch_buf;

/**
 * ptr_bullet_impact_buf = mempAllocBytesInBank(0x1F40, 4);
 * Address 0x8007A154.
*/
struct BulletImpact *ptr_bullet_impact_buf;

// data
//D:80040170
s32 numExplosionEntries = 0;
//D:80040174
s32 numSmokeEntries = 0;
//D:80040178
f32 D_80040178 = 1.0;

#if defined(VERSION_EU)
s_smoketype array_smoke_types[] = {
    // dur,   appr,    dis,   size,    bgrate,             r,  g,    b,    fgrate,         propclouds
    { 0x0001, 0x0032, 0x0063, 0x0000, 0.0f,              0x80, 0x80, 0x80, 0.300000011921f, 0x0096 },
    { 0x0190, 0x0032, 0x0025, 0x003C, 0.019999999553f,   0x50, 0x50, 0x60, 0.300000011921f, 0x0096 },
    { 0x0190, 0x0032, 0x002A, 0x0014, 0.00999999977648f, 0x80, 0x80, 0x80, 0.300000011921f, 0x0096 },
    { 0x020D, 0x0032, 0x0064, 0x0064, 0.00999999977648f, 0xC0, 0xC0, 0xC0, 0.300000011921f, 0x0096 },
    { 0x020D, 0x0032, 0x0032, 0x0050, 0.019999999553f,   0x40, 0x40, 0x40, 0.300000011921f, 0x0096 },
    { 0x0280, 0x0032, 0x002A, 0x00BE, 0.15000000596f,    0x40, 0x40, 0x40, 0.300000011921f, 0x0096 },
    { 0x02EE, 0x0032, 0x003A, 0x012C, 0.00999999977648f, 0x40, 0x40, 0x40, 0.300000011921f, 0x0096 },
    { 0x0032, 0x0032, 0x0007, 0x000F, 0.0299999993294f,  0xFF, 0xFF, 0xFF, 0.300000011921f, 0x0096 },
    { 0x0011, 0x0001, 0x0005, 0x001E, 0.0299999993294f,  0xFF, 0xFF, 0xFF, 2.0f,            0x0019 },
    { 0x0015, 0x0001, 0x0006, 0x0010, 0.0299999993294f,  0xE0, 0xE0, 0xE0, 3.0f,            0x0019 },
    { 0x02EE, 0x0032, 0x003A, 0x0384, 0.00999999977648f, 0x40, 0x40, 0x40, 0.300000011921f, 0x0096 }
};
#else
//D:8004017C
s_smoketype array_smoke_types[] = {
   // dur, appr, dis,size, bgrate,   r,  g,    b, fgrate, propclouds
    {   1,   60,  99,   0,   0.0f, 128, 128, 128,   0.3f,     180},
    { 480,   60,  45,  60,  0.02f,  80,  80,  96,   0.3f,     180},
    { 480,   60,  50,  20,  0.01f, 128, 128, 128,   0.3f,     180},
    { 640,   60, 120, 100,  0.01f, 192, 192, 192,   0.3f,     180},
    { 640,   60,  60,  80,  0.02f,  64,  64,  64,   0.3f,     180},
    { 770,   60,  50, 190,  0.15f,  64,  64,  64,   0.3f,     180},
    { 900,   60,  70, 300,  0.01f,  64,  64,  64,   0.3f,     180},
    {  60,   60,   8,  15,  0.03f, 255, 255, 255,   0.3f,     180},
    {  20,    1,   6,  30,  0.03f, 255, 255, 255,   2.0f,      30},
    {  25,    1,   7,  16,  0.03f, 224, 224, 224,   3.0f,      30},
    { 900,   60,  70, 900,  0.01f,  64,  64,  64,   0.3f,     180}
};
#endif

#if defined(VERSION_EU)
s_explosiontype array_explosion_types[] = {
   //hrange, vrange,    hchg,               vchg,           expsize, exprang, dmgrang,   dur, proprate, flarespd, nbits,  bitsize, bitdist, bithvel, bitvvel, smoketype,             sndid, damage
    {  0.1f,   0.1f,    0.0f,               0.0f,                   0.1f,    0.0f,    0.0f,     1,        1,     1.0f,     0,     0.1f,    0.0f,    0.0f,    0.0f,         0,              0x00,   0.0f},
    {  1.0f,   1.0f,    0.0f,               0.0f,                   1.0f,    0.0f,    0.0f,    25,        1,     1.0f,    10,     5.0f,    0.0f,    2.0f,    6.0f,         7,              0x00,   0.0f},
    { 20.0f,  20.0f,    0.0f,               0.0f,                  30.0f,   50.0f,   50.0f,    67,        1,     3.0f,    40,     6.0f,    5.0f,    0.7f,    6.0f,         2,  EXPLOSION_1B_SFX, 0.125f},
    { 50.0f,  50.0f,    0.0f,               0.0f,                  50.0f,  100.0f,  100.0f,    75,        1,     4.0f,    50,     6.0f,   10.0f,    1.0f,    6.0f,         2,  EXPLOSION_1C_SFX,   0.5f},
    { 60.0f,  80.0f,    1.20000004768f,     0.360000014305f,      100.0f,  150.0f,  280.0f,   100,        2,     5.0f,    80,     8.0f,   30.0f,    2.0f,    6.0f,         1,  EXPLOSION_4A_SFX,   1.0f},
    { 60.0f, 120.0f,    1.20000004768f,     0.360000014305f,      150.0f,  200.0f,  310.0f,   100,        2,     5.0f,    80,     8.0f,   30.0f,    2.0f,    6.0f,         1,  EXPLOSION_4A_SFX,   2.0f},
    { 20.0f,  20.0f,    0.0f,               0.0f,                  22.0f,   40.0f,   40.0f,    67,        1,     3.0f,    40,     6.0f,    5.0f,    0.7f,    6.0f,         2,  EXPLOSION_1B_SFX,   0.5f},
    { 35.0f,  40.0f,    0.0f,               0.0f,                  35.0f,   70.0f,   70.0f,    75,        1,     4.0f,    50,     6.0f,   10.0f,    1.0f,    6.0f,         2,  EXPLOSION_1C_SFX,   1.0f},
    { 50.0f,  80.0f,    1.20000004768f,     0.360000014305f,       50.0f,  100.0f,  220.0f,   100,        2,     5.0f,    80,     8.0f,   30.0f,    2.0f,    6.0f,         1,  EXPLOSION_4A_SFX,   2.0f},
    { 60.0f, 120.0f,    1.20000004768f,     0.360000014305f,       50.0f,  130.0f,  230.0f,   100,        2,     5.0f,    80,     8.0f,   30.0f,    2.0f,    6.0f,         1,  EXPLOSION_4A_SFX,   2.0f},
    { 40.0f,  40.0f,    0.5f,               0.239999994635582f,    70.0f,  100.0f,  180.0f,   162,        4,     5.0f,   120,     6.0f,   30.0f,    2.5f,    6.0f,         4,  EXPLOSION_5A_SFX,   1.0f},
    { 50.0f,  50.0f,    0.699999988079071f, 0.5f,                 100.0f,  150.0f,  260.0f,   150,        1,     4.0f,   150,     6.0f,   30.0f,    3.0f,    6.0f,         4,  EXPLOSION_4A_SFX,   2.0f},
    { 70.0f,  60.0f,    1.20000004768372f,  0.699999988079071f,   150.0f,  225.0f,  320.0f,   150,        2,     5.0f,   150,     6.0f,   30.0f,    4.0f,   12.0f,         5,  EXPLOSION_4A_SFX,   4.0f},
    { 80.0f,  60.0f,    2.40000009536743f,  0.899999976158142f,   200.0f,  300.0f,  480.0f,   150,        2,     5.0f,   200,     6.0f,   30.0f,    6.0f,   15.0f,         6,  EXPLOSION_4B_SFX,   4.0f},
    { 50.0f,  50.0f,    0.0f,               0.0f,                 120.0f,  200.0f,  400.0f,   125,        4,     4.0f,   150,     6.0f,   30.0f,    3.0f,    6.0f,         4,  EXPLOSION_4B_SFX,   4.0f},
    {  1.0f,   1.0f,    0.0f,               0.0f,                   1.0f,    0.0f,    0.0f,     1,        1,     1.0f,   150,     6.0f,   30.0f,    2.5f,    6.0f,         7,  EXPLOSION_2B_SFX,   0.0f},
    {  1.0f,   1.0f,    0.0f,               0.0f,                   1.0f,    0.0f,    0.0f,     1,        1,     1.0f,   100,     6.0f,   30.0f,    2.5f,    6.0f,         7,  EXPLOSION_2B_SFX,   0.0f},
    { 80.0f,  60.0f,   18.0f,               6.0f,                1500.0f, 2200.0f, 3600.0f,   250,        1,     2.0f,     0,     0.0f,    0.0f,    0.0f,    0.0f,         0,  EXPLOSION_4B_SFX,   4.0f},
    { 80.0f,  60.0f,    3.59999990463257f,  1.20000004768372f,    300.0f,  450.0f,  640.0f,    50,        1,     2.0f,     0,     0.0f,    0.0f,    0.0f,    0.0f,         0,  EXPLOSION_4B_SFX,   4.0f},
    { 90.0f,  75.0f,    3.0f,               1.0f,                 250.0f,  375.0f,  600.0f,   150,        2,     5.0f,   200,     6.0f,   30.0f,    6.0f,   15.0f,         6,  EXPLOSION_4B_SFX,   4.0f},
    {160.0f, 120.0f,    7.19999980926514f,  2.40000009536743f,    600.0f,  450.0f,  640.0f,    50,        1,     2.0f,     0,     0.0f,    0.0f,    0.0f,    0.0f,         0,  EXPLOSION_4B_SFX,   4.0f},
};
#else
s_explosiontype array_explosion_types[] = {
   //hrange, vrange,    hchg,  vchg,  expsize, exprang, dmgrang,   dur, proprate, flarespd, nbits,  bitsize, bitdist, bithvel, bitvvel, smoketype,             sndid, damage
    {  0.1f,   0.1f,    0.0f,  0.0f,     0.1f,    0.0f,    0.0f,     1,        1,     1.0f,     0,     0.1f,    0.0f,    0.0f,    0.0f,         0,              0x00,   0.0f},
    {  1.0f,   1.0f,    0.0f,  0.0f,     1.0f,    0.0f,    0.0f,    30,        1,     1.0f,    10,     5.0f,    0.0f,    2.0f,    6.0f,         7,              0x00,   0.0f},
    { 20.0f,  20.0f,    0.0f,  0.0f,    30.0f,   50.0f,   50.0f,    80,        1,     3.0f,    40,     6.0f,    5.0f,    0.7f,    6.0f,         2,  EXPLOSION_1B_SFX, 0.125f},
    { 50.0f,  50.0f,    0.0f,  0.0f,    50.0f,  100.0f,  100.0f,    90,        1,     4.0f,    50,     6.0f,   10.0f,    1.0f,    6.0f,         2,  EXPLOSION_1C_SFX,   0.5f},
    { 60.0f,  80.0f,    1.0f,  0.3f,   100.0f,  150.0f,  280.0f,   120,        2,     5.0f,    80,     8.0f,   30.0f,    2.0f,    6.0f,         1,  EXPLOSION_4A_SFX,   1.0f},
    { 60.0f, 120.0f,    1.0f,  0.3f,   150.0f,  200.0f,  310.0f,   120,        2,     5.0f,    80,     8.0f,   30.0f,    2.0f,    6.0f,         1,  EXPLOSION_4A_SFX,   2.0f},
    { 20.0f,  20.0f,    0.0f,  0.0f,    22.0f,   40.0f,   40.0f,    80,        1,     3.0f,    40,     6.0f,    5.0f,    0.7f,    6.0f,         2,  EXPLOSION_1B_SFX,   0.5f},
    { 35.0f,  40.0f,    0.0f,  0.0f,    35.0f,   70.0f,   70.0f,    90,        1,     4.0f,    50,     6.0f,   10.0f,    1.0f,    6.0f,         2,  EXPLOSION_1C_SFX,   1.0f},
    { 50.0f,  80.0f,    1.0f,  0.3f,    50.0f,  100.0f,  220.0f,   120,        2,     5.0f,    80,     8.0f,   30.0f,    2.0f,    6.0f,         1,  EXPLOSION_4A_SFX,   2.0f},
    { 60.0f, 120.0f,    1.0f,  0.3f,    50.0f,  130.0f,  230.0f,   120,        2,     5.0f,    80,     8.0f,   30.0f,    2.0f,    6.0f,         1,  EXPLOSION_4A_SFX,   2.0f},
    { 40.0f,  40.0f,    0.4f,  0.2f,    70.0f,  100.0f,  180.0f,   170,        4,     5.0f,   120,     6.0f,   30.0f,    2.5f,    6.0f,         4,  EXPLOSION_5A_SFX,   1.0f},
    { 50.0f,  50.0f,    0.6f,  0.4f,   100.0f,  150.0f,  260.0f,   180,        1,     4.0f,   150,     6.0f,   30.0f,    3.0f,    6.0f,         4,  EXPLOSION_4A_SFX,   2.0f},
    { 70.0f,  60.0f,    1.0f,  0.6f,   150.0f,  225.0f,  320.0f,   180,        2,     5.0f,   150,     6.0f,   30.0f,    4.0f,   12.0f,         5,  EXPLOSION_4A_SFX,   4.0f},
    { 80.0f,  60.0f,    2.0f,  0.7f,   200.0f,  300.0f,  480.0f,   180,        2,     5.0f,   200,     6.0f,   30.0f,    6.0f,   15.0f,         6,  EXPLOSION_4B_SFX,   4.0f},
    { 50.0f,  50.0f,    0.0f,  0.0f,   120.0f,  200.0f,  400.0f,   150,        4,     4.0f,   150,     6.0f,   30.0f,    3.0f,    6.0f,         4,  EXPLOSION_4B_SFX,   4.0f},
    {  1.0f,   1.0f,    0.0f,  0.0f,     1.0f,    0.0f,    0.0f,     1,        1,     1.0f,   150,     6.0f,   30.0f,    2.5f,    6.0f,         7,  EXPLOSION_2B_SFX,   0.0f},
    {  1.0f,   1.0f,    0.0f,  0.0f,     1.0f,    0.0f,    0.0f,     1,        1,     1.0f,   100,     6.0f,   30.0f,    2.5f,    6.0f,         7,  EXPLOSION_2B_SFX,   0.0f},
    { 80.0f,  60.0f,   15.0f,  5.0f,  1500.0f, 2200.0f, 3600.0f,   300,        1,     2.0f,     0,     0.0f,    0.0f,    0.0f,    0.0f,         0,  EXPLOSION_4B_SFX,   4.0f},
    { 80.0f,  60.0f,    3.0f,  1.0f,   300.0f,  450.0f,  640.0f,    60,        1,     2.0f,     0,     0.0f,    0.0f,    0.0f,    0.0f,         0,  EXPLOSION_4B_SFX,   4.0f},
    { 90.0f,  75.0f,    2.5f, 0.87f,   250.0f,  375.0f,  600.0f,   180,        2,     5.0f,   200,     6.0f,   30.0f,    6.0f,   15.0f,         6,  EXPLOSION_4B_SFX,   4.0f},
    {160.0f, 120.0f,    6.0f,  2.0f,   600.0f,  450.0f,  640.0f,    60,        1,     2.0f,     0,     0.0f,    0.0f,    0.0f,    0.0f,         0,  EXPLOSION_4B_SFX,   4.0f},
};
#endif

u32 array_explosion_dl_ptrs[] = {
    &globalDL_0x078,
    &globalDL_0x120,
    &globalDL_0x1c8,
    &globalDL_0x270, 
    &globalDL_0x318, 
    &globalDL_0x3c0,
    &globalDL_0x468, 
    &globalDL_0x510, 
    &globalDL_0x5b8, 
    &globalDL_0x660,
    &globalDL_0x708, 
    &globalDL_0x7b0, 
    &globalDL_0x858, 
    &globalDL_0x900,
    &globalDL_0x9a8       
};
s32 numCasingEntries = 0;
s32 numScorchEntries = 0;
s32 numImpactEntries = 0;
//D:8004080C
s_impacttype D_8004080C[] = {
    {10.0f, 10.0f, 1, 2, 8},
    { 6.0f,  6.0f, 1, 2, 8},
    { 8.0f,  8.0f, 0, 2, 8},
    {20.0f, 20.0f, 1, 2, 8},
    { 6.0f,  6.0f, 1, 2, 8},
    { 8.0f,  8.0f, 1, 2, 8},
    {12.0f, 12.0f, 1, 2, 8},
    { 6.0f,  6.0f, 1, 2, 8},
    {20.0f, 20.0f, 1, 2, 8},
    {20.0f, 20.0f, 1, 2, 8},
    {20.0f, 20.0f, 1, 2, 8},
    {20.0f, 20.0f, 1, 2, 8},
    {20.0f, 20.0f, 1, 2, 8},
    {24.0f, 24.0f, 1, 2, 8},
    { 6.0f,  6.0f, 1, 2, 1},
    { 6.0f,  6.0f, 1, 2, 1},
    {24.0f, 24.0f, 2, 2, 8},
    { 6.0f,  6.0f, 1, 2, 1},
    { 8.0f,  8.0f, 1, 2, 1},
    {12.0f, 12.0f, 1, 2, 1},
};

u32 D_800408FC = 0; 
u32 D_80040900 = 0;
u32 D_80040904 = 0;
u32 D_80040908 = 0;
//D:8004090C
u32 D_8004090C = 0xFFFFFFFF;
//D:80040910
u32 D_80040910 = 0;
//D:80040914
u32 D_80040914 = 0;
//D:80040918
u32 D_80040918 = 0;
//D:8004091C
u32 D_8004091C = 0;
//D:80040920
u32 D_80040920 = 0;
//D:80040924
u32 D_80040924 = 0;
//D:80040928
u32 D_80040928 = 0;
//D:8004092C
u32 D_8004092C = 0xDC;
//D:80040930
u32 D_80040930 = 0;
//D:80040934
u32 D_80040934 = 0;
//D:80040938
u32 D_80040938 = 0;
//D:8004093C
u32 D_8004093C = 0xDC;


// rodata


/**
 * Named same as Perfect Dark.
*/
#ifdef NONMATCHING
void explosionCreate(void) {

}
#else
#ifdef VERSION_US
GLOBAL_ASM(
.late_rodata
glabel D_800576B0
.word 0x497423fe /*999999.88*/
glabel D_800576B4
.word 0x40c90fdb /*6.2831855*/
.text
glabel explosionCreate
/* 0D0D80 7F09C250 27BDFFB8 */  addiu $sp, $sp, -0x48
/* 0D0D84 7F09C254 00077400 */  sll   $t6, $a3, 0x10
/* 0D0D88 7F09C258 000E7C03 */  sra   $t7, $t6, 0x10
/* 0D0D8C 7F09C25C 3C198004 */  lui   $t9, %hi(array_explosion_types) 
/* 0D0D90 7F09C260 AFB10020 */  sw    $s1, 0x20($sp)
/* 0D0D94 7F09C264 27390284 */  addiu $t9, %lo(array_explosion_types) # addiu $t9, $t9, 0x284
/* 0D0D98 7F09C268 000FC180 */  sll   $t8, $t7, 6
/* 0D0D9C 7F09C26C AFB30028 */  sw    $s3, 0x28($sp)
/* 0D0DA0 7F09C270 AFA70054 */  sw    $a3, 0x54($sp)
/* 0D0DA4 7F09C274 03198821 */  addu  $s1, $t8, $t9
/* 0D0DA8 7F09C278 24010010 */  li    $at, 16
/* 0D0DAC 7F09C27C 01E03825 */  move  $a3, $t7
/* 0D0DB0 7F09C280 00A09825 */  move  $s3, $a1
/* 0D0DB4 7F09C284 AFBF002C */  sw    $ra, 0x2c($sp)
/* 0D0DB8 7F09C288 AFB20024 */  sw    $s2, 0x24($sp)
/* 0D0DBC 7F09C28C AFB0001C */  sw    $s0, 0x1c($sp)
/* 0D0DC0 7F09C290 AFA40048 */  sw    $a0, 0x48($sp)
/* 0D0DC4 7F09C294 AFA60050 */  sw    $a2, 0x50($sp)
/* 0D0DC8 7F09C298 AFB10044 */  sw    $s1, 0x44($sp)
/* 0D0DCC 7F09C29C 11E10006 */  beq   $t7, $at, .L7F09C2B8
/* 0D0DD0 7F09C2A0 00004025 */   move  $t0, $zero
/* 0D0DD4 7F09C2A4 24010001 */  li    $at, 1
/* 0D0DD8 7F09C2A8 11E10003 */  beq   $t7, $at, .L7F09C2B8
/* 0D0DDC 7F09C2AC 240E0006 */   li    $t6, 6
/* 0D0DE0 7F09C2B0 3C018004 */  lui   $at, %hi(numExplosionEntries)
/* 0D0DE4 7F09C2B4 AC2E0170 */  sw    $t6, %lo(numExplosionEntries)($at)
.L7F09C2B8:
/* 0D0DE8 7F09C2B8 3C048008 */  lui   $a0, %hi(ptr_explosion_buf)
/* 0D0DEC 7F09C2BC 8C84A144 */  lw    $a0, %lo(ptr_explosion_buf)($a0)
/* 0D0DF0 7F09C2C0 00001025 */  move  $v0, $zero
/* 0D0DF4 7F09C2C4 00801825 */  move  $v1, $a0
.L7F09C2C8:
/* 0D0DF8 7F09C2C8 8C6F0000 */  lw    $t7, ($v1)
/* 0D0DFC 7F09C2CC 55E00004 */  bnezl $t7, .L7F09C2E0
/* 0D0E00 7F09C2D0 244203E0 */   addiu $v0, $v0, 0x3e0
/* 0D0E04 7F09C2D4 10000005 */  b     .L7F09C2EC
/* 0D0E08 7F09C2D8 00444021 */   addu  $t0, $v0, $a0
/* 0D0E0C 7F09C2DC 244203E0 */  addiu $v0, $v0, 0x3e0
.L7F09C2E0:
/* 0D0E10 7F09C2E0 28411740 */  slti  $at, $v0, 0x1740
/* 0D0E14 7F09C2E4 1420FFF8 */  bnez  $at, .L7F09C2C8
/* 0D0E18 7F09C2E8 246303E0 */   addiu $v1, $v1, 0x3e0
.L7F09C2EC:
/* 0D0E1C 7F09C2EC 51000129 */  beql  $t0, $zero, .L7F09C794
/* 0D0E20 7F09C2F0 8FBF002C */   lw    $ra, 0x2c($sp)
/* 0D0E24 7F09C2F4 A7A70056 */  sh    $a3, 0x56($sp)
/* 0D0E28 7F09C2F8 0FC0E90C */  jal   chrpropAllocate
/* 0D0E2C 7F09C2FC AFA80040 */   sw    $t0, 0x40($sp)
/* 0D0E30 7F09C300 92230039 */  lbu   $v1, 0x39($s1)
/* 0D0E34 7F09C304 8FA80040 */  lw    $t0, 0x40($sp)
/* 0D0E38 7F09C308 00403825 */  move  $a3, $v0
/* 0D0E3C 7F09C30C 1860000E */  blez  $v1, .L7F09C348
/* 0D0E40 7F09C310 3C048006 */   lui   $a0, %hi(g_musicSfxBufferPtr)
/* 0D0E44 7F09C314 00032C00 */  sll   $a1, $v1, 0x10
/* 0D0E48 7F09C318 0005C403 */  sra   $t8, $a1, 0x10
/* 0D0E4C 7F09C31C 03002825 */  move  $a1, $t8
/* 0D0E50 7F09C320 8C843720 */  lw    $a0, %lo(g_musicSfxBufferPtr)($a0)
/* 0D0E54 7F09C324 00003025 */  move  $a2, $zero
/* 0D0E58 7F09C328 AFA20030 */  sw    $v0, 0x30($sp)
/* 0D0E5C 7F09C32C 0C002382 */  jal   sndPlaySfx
/* 0D0E60 7F09C330 AFA80040 */   sw    $t0, 0x40($sp)
/* 0D0E64 7F09C334 00402025 */  move  $a0, $v0
/* 0D0E68 7F09C338 0FC14E84 */  jal   sub_GAME_7F053A10
/* 0D0E6C 7F09C33C 02602825 */   move  $a1, $s3
/* 0D0E70 7F09C340 8FA70030 */  lw    $a3, 0x30($sp)
/* 0D0E74 7F09C344 8FA80040 */  lw    $t0, 0x40($sp)
.L7F09C348:
/* 0D0E78 7F09C348 10E00111 */  beqz  $a3, .L7F09C790
/* 0D0E7C 7F09C34C 8FA60060 */   lw    $a2, 0x60($sp)
/* 0D0E80 7F09C350 90EE0001 */  lbu   $t6, 1($a3)
/* 0D0E84 7F09C354 24190007 */  li    $t9, 7
/* 0D0E88 7F09C358 A0F90000 */  sb    $t9, ($a3)
/* 0D0E8C 7F09C35C 35CF0002 */  ori   $t7, $t6, 2
/* 0D0E90 7F09C360 A0EF0001 */  sb    $t7, 1($a3)
/* 0D0E94 7F09C364 ACE80004 */  sw    $t0, 4($a3)
/* 0D0E98 7F09C368 8FB80050 */  lw    $t8, 0x50($sp)
/* 0D0E9C 7F09C36C 240500FF */  li    $a1, 255
/* 0D0EA0 7F09C370 00008025 */  move  $s0, $zero
/* 0D0EA4 7F09C374 ACF80014 */  sw    $t8, 0x14($a3)
/* 0D0EA8 7F09C378 C6640000 */  lwc1  $f4, ($s3)
/* 0D0EAC 7F09C37C 240E00FF */  li    $t6, 255
/* 0D0EB0 7F09C380 E4E40008 */  swc1  $f4, 8($a3)
/* 0D0EB4 7F09C384 C6660004 */  lwc1  $f6, 4($s3)
/* 0D0EB8 7F09C388 E4E6000C */  swc1  $f6, 0xc($a3)
/* 0D0EBC 7F09C38C C6680008 */  lwc1  $f8, 8($s3)
/* 0D0EC0 7F09C390 E4E80010 */  swc1  $f8, 0x10($a3)
/* 0D0EC4 7F09C394 90D90000 */  lbu   $t9, ($a2)
/* 0D0EC8 7F09C398 10B9000C */  beq   $a1, $t9, .L7F09C3CC
/* 0D0ECC 7F09C39C 00E01821 */   addu  $v1, $a3, $zero
/* 0D0ED0 7F09C3A0 00C01021 */  addu  $v0, $a2, $zero
/* 0D0ED4 7F09C3A4 90C40000 */  lbu   $a0, ($a2)
/* 0D0ED8 7F09C3A8 24120007 */  li    $s2, 7
/* 0D0EDC 7F09C3AC A064002C */  sb    $a0, 0x2c($v1)
.L7F09C3B0:
/* 0D0EE0 7F09C3B0 90440001 */  lbu   $a0, 1($v0)
/* 0D0EE4 7F09C3B4 26100001 */  addiu $s0, $s0, 1
/* 0D0EE8 7F09C3B8 24630001 */  addiu $v1, $v1, 1
/* 0D0EEC 7F09C3BC 10A40003 */  beq   $a1, $a0, .L7F09C3CC
/* 0D0EF0 7F09C3C0 24420001 */   addiu $v0, $v0, 1
/* 0D0EF4 7F09C3C4 5612FFFA */  bnel  $s0, $s2, .L7F09C3B0
/* 0D0EF8 7F09C3C8 A064002C */   sb    $a0, 0x2c($v1)
.L7F09C3CC:
/* 0D0EFC 7F09C3CC 00F07821 */  addu  $t7, $a3, $s0
/* 0D0F00 7F09C3D0 A1EE002C */  sb    $t6, 0x2c($t7)
/* 0D0F04 7F09C3D4 8FB80064 */  lw    $t8, 0x64($sp)
/* 0D0F08 7F09C3D8 24120007 */  li    $s2, 7
/* 0D0F0C 7F09C3DC 00008025 */  move  $s0, $zero
/* 0D0F10 7F09C3E0 13000004 */  beqz  $t8, .L7F09C3F4
/* 0D0F14 7F09C3E4 00E02025 */   move  $a0, $a3
/* 0D0F18 7F09C3E8 90F90001 */  lbu   $t9, 1($a3)
/* 0D0F1C 7F09C3EC 372E0008 */  ori   $t6, $t9, 8
/* 0D0F20 7F09C3F0 A0EE0001 */  sb    $t6, 1($a3)
.L7F09C3F4:
/* 0D0F24 7F09C3F4 AFA70030 */  sw    $a3, 0x30($sp)
/* 0D0F28 7F09C3F8 0FC0E93C */  jal   chrpropActivateThisFrame
/* 0D0F2C 7F09C3FC AFA80040 */   sw    $t0, 0x40($sp)
/* 0D0F30 7F09C400 0FC0E901 */  jal   chrpropEnable
/* 0D0F34 7F09C404 8FA40030 */   lw    $a0, 0x30($sp)
/* 0D0F38 7F09C408 8FA80040 */  lw    $t0, 0x40($sp)
/* 0D0F3C 7F09C40C 8FA20058 */  lw    $v0, 0x58($sp)
/* 0D0F40 7F09C410 8FA70030 */  lw    $a3, 0x30($sp)
/* 0D0F44 7F09C414 8FA90048 */  lw    $t1, 0x48($sp)
/* 0D0F48 7F09C418 87AF0056 */  lh    $t7, 0x56($sp)
/* 0D0F4C 7F09C41C 2418FFFF */  li    $t8, -1
/* 0D0F50 7F09C420 A50003C8 */  sh    $zero, 0x3c8($t0)
/* 0D0F54 7F09C424 A51803CA */  sh    $t8, 0x3ca($t0)
/* 0D0F58 7F09C428 A10203CD */  sb    $v0, 0x3cd($t0)
/* 0D0F5C 7F09C42C AD070000 */  sw    $a3, ($t0)
/* 0D0F60 7F09C430 AD090004 */  sw    $t1, 4($t0)
/* 0D0F64 7F09C434 A10F03CC */  sb    $t7, 0x3cc($t0)
/* 0D0F68 7F09C438 8FB9005C */  lw    $t9, 0x5c($sp)
/* 0D0F6C 7F09C43C 3C018005 */  lui   $at, %hi(D_800576B0)
/* 0D0F70 7F09C440 1040002D */  beqz  $v0, .L7F09C4F8
/* 0D0F74 7F09C444 A11903CE */   sb    $t9, 0x3ce($t0)
/* 0D0F78 7F09C448 51200019 */  beql  $t1, $zero, .L7F09C4B0
/* 0D0F7C 7F09C44C C6660000 */   lwc1  $f6, ($s3)
/* 0D0F80 7F09C450 8D2E0014 */  lw    $t6, 0x14($t1)
/* 0D0F84 7F09C454 51C00016 */  beql  $t6, $zero, .L7F09C4B0
/* 0D0F88 7F09C458 C6660000 */   lwc1  $f6, ($s3)
/* 0D0F8C 7F09C45C C52A0008 */  lwc1  $f10, 8($t1)
/* 0D0F90 7F09C460 E50A03D0 */  swc1  $f10, 0x3d0($t0)
/* 0D0F94 7F09C464 8D260010 */  lw    $a2, 0x10($t1)
/* 0D0F98 7F09C468 8D250008 */  lw    $a1, 8($t1)
/* 0D0F9C 7F09C46C 8D240014 */  lw    $a0, 0x14($t1)
/* 0D0FA0 7F09C470 0FC2CA5C */  jal   stanGetPositionYValue
/* 0D0FA4 7F09C474 AFA80040 */   sw    $t0, 0x40($sp)
/* 0D0FA8 7F09C478 3C014080 */  li    $at, 0x40800000 # 4.000000
/* 0D0FAC 7F09C47C 44818000 */  mtc1  $at, $f16
/* 0D0FB0 7F09C480 8FA80040 */  lw    $t0, 0x40($sp)
/* 0D0FB4 7F09C484 8FA90048 */  lw    $t1, 0x48($sp)
/* 0D0FB8 7F09C488 46100480 */  add.s $f18, $f0, $f16
/* 0D0FBC 7F09C48C E51203D4 */  swc1  $f18, 0x3d4($t0)
/* 0D0FC0 7F09C490 C5240010 */  lwc1  $f4, 0x10($t1)
/* 0D0FC4 7F09C494 E50403D8 */  swc1  $f4, 0x3d8($t0)
/* 0D0FC8 7F09C498 0FC2CBF6 */  jal   getTileRoom
/* 0D0FCC 7F09C49C 8D240014 */   lw    $a0, 0x14($t1)
/* 0D0FD0 7F09C4A0 8FA80040 */  lw    $t0, 0x40($sp)
/* 0D0FD4 7F09C4A4 10000016 */  b     .L7F09C500
/* 0D0FD8 7F09C4A8 A50203DC */   sh    $v0, 0x3dc($t0)
/* 0D0FDC 7F09C4AC C6660000 */  lwc1  $f6, ($s3)
.L7F09C4B0:
/* 0D0FE0 7F09C4B0 E50603D0 */  swc1  $f6, 0x3d0($t0)
/* 0D0FE4 7F09C4B4 8E660008 */  lw    $a2, 8($s3)
/* 0D0FE8 7F09C4B8 8E650000 */  lw    $a1, ($s3)
/* 0D0FEC 7F09C4BC AFA80040 */  sw    $t0, 0x40($sp)
/* 0D0FF0 7F09C4C0 0FC2CA5C */  jal   stanGetPositionYValue
/* 0D0FF4 7F09C4C4 8FA40050 */   lw    $a0, 0x50($sp)
/* 0D0FF8 7F09C4C8 3C014080 */  li    $at, 0x40800000 # 4.000000
/* 0D0FFC 7F09C4CC 44814000 */  mtc1  $at, $f8
/* 0D1000 7F09C4D0 8FA80040 */  lw    $t0, 0x40($sp)
/* 0D1004 7F09C4D4 46080280 */  add.s $f10, $f0, $f8
/* 0D1008 7F09C4D8 E50A03D4 */  swc1  $f10, 0x3d4($t0)
/* 0D100C 7F09C4DC C6700008 */  lwc1  $f16, 8($s3)
/* 0D1010 7F09C4E0 E51003D8 */  swc1  $f16, 0x3d8($t0)
/* 0D1014 7F09C4E4 0FC2CBF6 */  jal   getTileRoom
/* 0D1018 7F09C4E8 8FA40050 */   lw    $a0, 0x50($sp)
/* 0D101C 7F09C4EC 8FA80040 */  lw    $t0, 0x40($sp)
/* 0D1020 7F09C4F0 10000003 */  b     .L7F09C500
/* 0D1024 7F09C4F4 A50203DC */   sh    $v0, 0x3dc($t0)
.L7F09C4F8:
/* 0D1028 7F09C4F8 C43276B0 */  lwc1  $f18, %lo(D_800576B0)($at)
/* 0D102C 7F09C4FC E51203D0 */  swc1  $f18, 0x3d0($t0)
.L7F09C500:
/* 0D1030 7F09C500 0C002914 */  jal   randomGetNext
/* 0D1034 7F09C504 AFA80040 */   sw    $t0, 0x40($sp)
/* 0D1038 7F09C508 44822000 */  mtc1  $v0, $f4
/* 0D103C 7F09C50C 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0D1040 7F09C510 04410004 */  bgez  $v0, .L7F09C524
/* 0D1044 7F09C514 468021A0 */   cvt.s.w $f6, $f4
/* 0D1048 7F09C518 44814000 */  mtc1  $at, $f8
/* 0D104C 7F09C51C 00000000 */  nop   
/* 0D1050 7F09C520 46083180 */  add.s $f6, $f6, $f8
.L7F09C524:
/* 0D1054 7F09C524 3C012F80 */  li    $at, 0x2F800000 # 0.000000
/* 0D1058 7F09C528 44815000 */  mtc1  $at, $f10
/* 0D105C 7F09C52C 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 0D1060 7F09C530 44819000 */  mtc1  $at, $f18
/* 0D1064 7F09C534 460A3402 */  mul.s $f16, $f6, $f10
/* 0D1068 7F09C538 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0D106C 7F09C53C 44814000 */  mtc1  $at, $f8
/* 0D1070 7F09C540 C62A0010 */  lwc1  $f10, 0x10($s1)
/* 0D1074 7F09C544 46128102 */  mul.s $f4, $f16, $f18
/* 0D1078 7F09C548 46082180 */  add.s $f6, $f4, $f8
/* 0D107C 7F09C54C 460A3402 */  mul.s $f16, $f6, $f10
/* 0D1080 7F09C550 0C002914 */  jal   randomGetNext
/* 0D1084 7F09C554 E7B0003C */   swc1  $f16, 0x3c($sp)
/* 0D1088 7F09C558 44829000 */  mtc1  $v0, $f18
/* 0D108C 7F09C55C 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0D1090 7F09C560 04410004 */  bgez  $v0, .L7F09C574
/* 0D1094 7F09C564 46809120 */   cvt.s.w $f4, $f18
/* 0D1098 7F09C568 44814000 */  mtc1  $at, $f8
/* 0D109C 7F09C56C 00000000 */  nop   
/* 0D10A0 7F09C570 46082100 */  add.s $f4, $f4, $f8
.L7F09C574:
/* 0D10A4 7F09C574 3C012F80 */  li    $at, 0x2F800000 # 0.000000
/* 0D10A8 7F09C578 44813000 */  mtc1  $at, $f6
/* 0D10AC 7F09C57C 3C018005 */  lui   $at, %hi(D_800576B4)
/* 0D10B0 7F09C580 C43076B4 */  lwc1  $f16, %lo(D_800576B4)($at)
/* 0D10B4 7F09C584 46062282 */  mul.s $f10, $f4, $f6
/* 0D10B8 7F09C588 00000000 */  nop   
/* 0D10BC 7F09C58C 46105302 */  mul.s $f12, $f10, $f16
/* 0D10C0 7F09C590 0FC15FA8 */  jal   cosf
/* 0D10C4 7F09C594 E7AC0038 */   swc1  $f12, 0x38($sp)
/* 0D10C8 7F09C598 C7B2003C */  lwc1  $f18, 0x3c($sp)
/* 0D10CC 7F09C59C 8FA80040 */  lw    $t0, 0x40($sp)
/* 0D10D0 7F09C5A0 46120202 */  mul.s $f8, $f0, $f18
/* 0D10D4 7F09C5A4 E5080014 */  swc1  $f8, 0x14($t0)
/* 0D10D8 7F09C5A8 0FC15FAB */  jal   sinf
/* 0D10DC 7F09C5AC C7AC0038 */   lwc1  $f12, 0x38($sp)
/* 0D10E0 7F09C5B0 C7A4003C */  lwc1  $f4, 0x3c($sp)
/* 0D10E4 7F09C5B4 8FA80040 */  lw    $t0, 0x40($sp)
/* 0D10E8 7F09C5B8 240F0001 */  li    $t7, 1
/* 0D10EC 7F09C5BC 46040182 */  mul.s $f6, $f0, $f4
/* 0D10F0 7F09C5C0 A50F001C */  sh    $t7, 0x1c($t0)
/* 0D10F4 7F09C5C4 E5060018 */  swc1  $f6, 0x18($t0)
/* 0D10F8 7F09C5C8 C66A0000 */  lwc1  $f10, ($s3)
/* 0D10FC 7F09C5CC E50A0008 */  swc1  $f10, 8($t0)
/* 0D1100 7F09C5D0 C6700004 */  lwc1  $f16, 4($s3)
/* 0D1104 7F09C5D4 E510000C */  swc1  $f16, 0xc($t0)
/* 0D1108 7F09C5D8 C6720008 */  lwc1  $f18, 8($s3)
/* 0D110C 7F09C5DC E5120010 */  swc1  $f18, 0x10($t0)
/* 0D1110 7F09C5E0 86380024 */  lh    $t8, 0x24($s1)
/* 0D1114 7F09C5E4 1B00000E */  blez  $t8, .L7F09C620
/* 0D1118 7F09C5E8 00000000 */   nop   
/* 0D111C 7F09C5EC C6280028 */  lwc1  $f8, 0x28($s1)
.L7F09C5F0:
/* 0D1120 7F09C5F0 8E25002C */  lw    $a1, 0x2c($s1)
/* 0D1124 7F09C5F4 8E260030 */  lw    $a2, 0x30($s1)
/* 0D1128 7F09C5F8 8E270034 */  lw    $a3, 0x34($s1)
/* 0D112C 7F09C5FC 02602025 */  move  $a0, $s3
/* 0D1130 7F09C600 0FC27C95 */  jal   sub_GAME_7F09F254
/* 0D1134 7F09C604 E7A80010 */   swc1  $f8, 0x10($sp)
/* 0D1138 7F09C608 8FB90044 */  lw    $t9, 0x44($sp)
/* 0D113C 7F09C60C 26100001 */  addiu $s0, $s0, 1
/* 0D1140 7F09C610 872E0024 */  lh    $t6, 0x24($t9)
/* 0D1144 7F09C614 020E082A */  slt   $at, $s0, $t6
/* 0D1148 7F09C618 5420FFF5 */  bnezl $at, .L7F09C5F0
/* 0D114C 7F09C61C C6280028 */   lwc1  $f8, 0x28($s1)
.L7F09C620:
/* 0D1150 7F09C620 0FC26919 */  jal   getPlayerCount
/* 0D1154 7F09C624 00000000 */   nop   
/* 0D1158 7F09C628 28410002 */  slti  $at, $v0, 2
/* 0D115C 7F09C62C 14200058 */  bnez  $at, .L7F09C790
/* 0D1160 7F09C630 00003025 */   move  $a2, $zero
/* 0D1164 7F09C634 3C0D8008 */  lui   $t5, %hi(ptr_smoke_buf) 
/* 0D1168 7F09C638 3C0B8004 */  lui   $t3, %hi(array_smoke_types) 
/* 0D116C 7F09C63C 256B017C */  addiu $t3, %lo(array_smoke_types) # addiu $t3, $t3, 0x17c
/* 0D1170 7F09C640 25ADA140 */  addiu $t5, %lo(ptr_smoke_buf) # addiu $t5, $t5, -0x5ec0
/* 0D1174 7F09C644 241F1FE0 */  li    $ra, 8160
/* 0D1178 7F09C648 240C0018 */  li    $t4, 24
/* 0D117C 7F09C64C 240A0009 */  li    $t2, 9
/* 0D1180 7F09C650 24090008 */  li    $t1, 8
/* 0D1184 7F09C654 8DA30000 */  lw    $v1, ($t5)
.L7F09C658:
/* 0D1188 7F09C658 00662821 */  addu  $a1, $v1, $a2
/* 0D118C 7F09C65C 8CAF0000 */  lw    $t7, ($a1)
/* 0D1190 7F09C660 00C33821 */  addu  $a3, $a2, $v1
/* 0D1194 7F09C664 51E00011 */  beql  $t7, $zero, .L7F09C6AC
/* 0D1198 7F09C668 8CAF0198 */   lw    $t7, 0x198($a1)
/* 0D119C 7F09C66C 84E20006 */  lh    $v0, 6($a3)
/* 0D11A0 7F09C670 5242000E */  beql  $s2, $v0, .L7F09C6AC
/* 0D11A4 7F09C674 8CAF0198 */   lw    $t7, 0x198($a1)
/* 0D11A8 7F09C678 84E80006 */  lh    $t0, 6($a3)
/* 0D11AC 7F09C67C 5128000B */  beql  $t1, $t0, .L7F09C6AC
/* 0D11B0 7F09C680 8CAF0198 */   lw    $t7, 0x198($a1)
/* 0D11B4 7F09C684 51480009 */  beql  $t2, $t0, .L7F09C6AC
/* 0D11B8 7F09C688 8CAF0198 */   lw    $t7, 0x198($a1)
/* 0D11BC 7F09C68C 004C0019 */  multu $v0, $t4
/* 0D11C0 7F09C690 0000C012 */  mflo  $t8
/* 0D11C4 7F09C694 0178C821 */  addu  $t9, $t3, $t8
/* 0D11C8 7F09C698 872E0000 */  lh    $t6, ($t9)
/* 0D11CC 7F09C69C A4EE0004 */  sh    $t6, 4($a3)
/* 0D11D0 7F09C6A0 8DA30000 */  lw    $v1, ($t5)
/* 0D11D4 7F09C6A4 00662821 */  addu  $a1, $v1, $a2
/* 0D11D8 7F09C6A8 8CAF0198 */  lw    $t7, 0x198($a1)
.L7F09C6AC:
/* 0D11DC 7F09C6AC 00C32021 */  addu  $a0, $a2, $v1
/* 0D11E0 7F09C6B0 51E00011 */  beql  $t7, $zero, .L7F09C6F8
/* 0D11E4 7F09C6B4 8CAF0330 */   lw    $t7, 0x330($a1)
/* 0D11E8 7F09C6B8 8482019E */  lh    $v0, 0x19e($a0)
/* 0D11EC 7F09C6BC 24840198 */  addiu $a0, $a0, 0x198
/* 0D11F0 7F09C6C0 5242000D */  beql  $s2, $v0, .L7F09C6F8
/* 0D11F4 7F09C6C4 8CAF0330 */   lw    $t7, 0x330($a1)
/* 0D11F8 7F09C6C8 5122000B */  beql  $t1, $v0, .L7F09C6F8
/* 0D11FC 7F09C6CC 8CAF0330 */   lw    $t7, 0x330($a1)
/* 0D1200 7F09C6D0 51420009 */  beql  $t2, $v0, .L7F09C6F8
/* 0D1204 7F09C6D4 8CAF0330 */   lw    $t7, 0x330($a1)
/* 0D1208 7F09C6D8 004C0019 */  multu $v0, $t4
/* 0D120C 7F09C6DC 0000C012 */  mflo  $t8
/* 0D1210 7F09C6E0 0178C821 */  addu  $t9, $t3, $t8
/* 0D1214 7F09C6E4 872E0000 */  lh    $t6, ($t9)
/* 0D1218 7F09C6E8 A48E0004 */  sh    $t6, 4($a0)
/* 0D121C 7F09C6EC 8DA30000 */  lw    $v1, ($t5)
/* 0D1220 7F09C6F0 00662821 */  addu  $a1, $v1, $a2
/* 0D1224 7F09C6F4 8CAF0330 */  lw    $t7, 0x330($a1)
.L7F09C6F8:
/* 0D1228 7F09C6F8 00C32021 */  addu  $a0, $a2, $v1
/* 0D122C 7F09C6FC 51E00011 */  beql  $t7, $zero, .L7F09C744
/* 0D1230 7F09C700 8CAF04C8 */   lw    $t7, 0x4c8($a1)
/* 0D1234 7F09C704 84820336 */  lh    $v0, 0x336($a0)
/* 0D1238 7F09C708 24840330 */  addiu $a0, $a0, 0x330
/* 0D123C 7F09C70C 5242000D */  beql  $s2, $v0, .L7F09C744
/* 0D1240 7F09C710 8CAF04C8 */   lw    $t7, 0x4c8($a1)
/* 0D1244 7F09C714 5122000B */  beql  $t1, $v0, .L7F09C744
/* 0D1248 7F09C718 8CAF04C8 */   lw    $t7, 0x4c8($a1)
/* 0D124C 7F09C71C 51420009 */  beql  $t2, $v0, .L7F09C744
/* 0D1250 7F09C720 8CAF04C8 */   lw    $t7, 0x4c8($a1)
/* 0D1254 7F09C724 004C0019 */  multu $v0, $t4
/* 0D1258 7F09C728 0000C012 */  mflo  $t8
/* 0D125C 7F09C72C 0178C821 */  addu  $t9, $t3, $t8
/* 0D1260 7F09C730 872E0000 */  lh    $t6, ($t9)
/* 0D1264 7F09C734 A48E0004 */  sh    $t6, 4($a0)
/* 0D1268 7F09C738 8DA30000 */  lw    $v1, ($t5)
/* 0D126C 7F09C73C 00662821 */  addu  $a1, $v1, $a2
/* 0D1270 7F09C740 8CAF04C8 */  lw    $t7, 0x4c8($a1)
.L7F09C744:
/* 0D1274 7F09C744 00C32021 */  addu  $a0, $a2, $v1
/* 0D1278 7F09C748 51E0000F */  beql  $t7, $zero, .L7F09C788
/* 0D127C 7F09C74C 24C60660 */   addiu $a2, $a2, 0x660
/* 0D1280 7F09C750 848204CE */  lh    $v0, 0x4ce($a0)
/* 0D1284 7F09C754 248404C8 */  addiu $a0, $a0, 0x4c8
/* 0D1288 7F09C758 5242000B */  beql  $s2, $v0, .L7F09C788
/* 0D128C 7F09C75C 24C60660 */   addiu $a2, $a2, 0x660
/* 0D1290 7F09C760 51220009 */  beql  $t1, $v0, .L7F09C788
/* 0D1294 7F09C764 24C60660 */   addiu $a2, $a2, 0x660
/* 0D1298 7F09C768 51420007 */  beql  $t2, $v0, .L7F09C788
/* 0D129C 7F09C76C 24C60660 */   addiu $a2, $a2, 0x660
/* 0D12A0 7F09C770 004C0019 */  multu $v0, $t4
/* 0D12A4 7F09C774 0000C012 */  mflo  $t8
/* 0D12A8 7F09C778 0178C821 */  addu  $t9, $t3, $t8
/* 0D12AC 7F09C77C 872E0000 */  lh    $t6, ($t9)
/* 0D12B0 7F09C780 A48E0004 */  sh    $t6, 4($a0)
/* 0D12B4 7F09C784 24C60660 */  addiu $a2, $a2, 0x660
.L7F09C788:
/* 0D12B8 7F09C788 54DFFFB3 */  bnel  $a2, $ra, .L7F09C658
/* 0D12BC 7F09C78C 8DA30000 */   lw    $v1, ($t5)
.L7F09C790:
/* 0D12C0 7F09C790 8FBF002C */  lw    $ra, 0x2c($sp)
.L7F09C794:
/* 0D12C4 7F09C794 8FB0001C */  lw    $s0, 0x1c($sp)
/* 0D12C8 7F09C798 8FB10020 */  lw    $s1, 0x20($sp)
/* 0D12CC 7F09C79C 8FB20024 */  lw    $s2, 0x24($sp)
/* 0D12D0 7F09C7A0 8FB30028 */  lw    $s3, 0x28($sp)
/* 0D12D4 7F09C7A4 03E00008 */  jr    $ra
/* 0D12D8 7F09C7A8 27BD0048 */   addiu $sp, $sp, 0x48
)
#endif

#ifndef VERSION_US
GLOBAL_ASM(
.late_rodata
glabel D_800576B0
.word 0x497423fe /*999999.88*/
glabel D_800576B4
.word 0x40c90fdb /*6.2831855*/
.text
glabel explosionCreate
/* 0D1960 7F09CDF0 27BDFFB0 */  addiu $sp, $sp, -0x50
/* 0D1964 7F09CDF4 AFA7005C */  sw    $a3, 0x5c($sp)
/* 0D1968 7F09CDF8 87AE005E */  lh    $t6, 0x5e($sp)
/* 0D196C 7F09CDFC 3C088008 */  lui   $t0, %hi(ptr_explosion_buf) # $t0, 0x8008
/* 0D1970 7F09CE00 8D08A1B4 */  lw    $t0, %lo(ptr_explosion_buf)($t0)
/* 0D1974 7F09CE04 3C188004 */  lui   $t8, %hi(array_explosion_types) # $t8, 0x8004
/* 0D1978 7F09CE08 AFB10024 */  sw    $s1, 0x24($sp)
/* 0D197C 7F09CE0C 271802B4 */  addiu $t8, %lo(array_explosion_types) # addiu $t8, $t8, 0x2b4
/* 0D1980 7F09CE10 000E7980 */  sll   $t7, $t6, 6
/* 0D1984 7F09CE14 AFB40030 */  sw    $s4, 0x30($sp)
/* 0D1988 7F09CE18 AFB3002C */  sw    $s3, 0x2c($sp)
/* 0D198C 7F09CE1C 01F88821 */  addu  $s1, $t7, $t8
/* 0D1990 7F09CE20 00A09825 */  move  $s3, $a1
/* 0D1994 7F09CE24 AFBF0034 */  sw    $ra, 0x34($sp)
/* 0D1998 7F09CE28 AFB20028 */  sw    $s2, 0x28($sp)
/* 0D199C 7F09CE2C AFB00020 */  sw    $s0, 0x20($sp)
/* 0D19A0 7F09CE30 AFA40050 */  sw    $a0, 0x50($sp)
/* 0D19A4 7F09CE34 AFA60058 */  sw    $a2, 0x58($sp)
/* 0D19A8 7F09CE38 AFB1004C */  sw    $s1, 0x4c($sp)
/* 0D19AC 7F09CE3C 0000A025 */  move  $s4, $zero
/* 0D19B0 7F09CE40 00001025 */  move  $v0, $zero
/* 0D19B4 7F09CE44 01001825 */  move  $v1, $t0
.Ljp7F09CE48:
/* 0D19B8 7F09CE48 8C790000 */  lw    $t9, ($v1)
/* 0D19BC 7F09CE4C 57200004 */  bnezl $t9, .Ljp7F09CE60
/* 0D19C0 7F09CE50 244203E0 */   addiu $v0, $v0, 0x3e0
/* 0D19C4 7F09CE54 10000005 */  b     .Ljp7F09CE6C
/* 0D19C8 7F09CE58 0048A021 */   addu  $s4, $v0, $t0
/* 0D19CC 7F09CE5C 244203E0 */  addiu $v0, $v0, 0x3e0
.Ljp7F09CE60:
/* 0D19D0 7F09CE60 28411740 */  slti  $at, $v0, 0x1740
/* 0D19D4 7F09CE64 1420FFF8 */  bnez  $at, .Ljp7F09CE48
/* 0D19D8 7F09CE68 246303E0 */   addiu $v1, $v1, 0x3e0
.Ljp7F09CE6C:
/* 0D19DC 7F09CE6C 52800124 */  beql  $s4, $zero, .Ljp7F09D300
/* 0D19E0 7F09CE70 8FBF0034 */   lw    $ra, 0x34($sp)
/* 0D19E4 7F09CE74 0FC0E9CC */  jal   chrpropAllocate
/* 0D19E8 7F09CE78 00000000 */   nop   
/* 0D19EC 7F09CE7C 87AE005E */  lh    $t6, 0x5e($sp)
/* 0D19F0 7F09CE80 24010010 */  li    $at, 16
/* 0D19F4 7F09CE84 00403825 */  move  $a3, $v0
/* 0D19F8 7F09CE88 11C10006 */  beq   $t6, $at, .Ljp7F09CEA4
/* 0D19FC 7F09CE8C 3C048006 */   lui   $a0, %hi(g_musicSfxBufferPtr) # $a0, 0x8006
/* 0D1A00 7F09CE90 24010001 */  li    $at, 1
/* 0D1A04 7F09CE94 11C10003 */  beq   $t6, $at, .Ljp7F09CEA4
/* 0D1A08 7F09CE98 240F0006 */   li    $t7, 6
/* 0D1A0C 7F09CE9C 3C018004 */  lui   $at, %hi(numExplosionEntries) # $at, 0x8004
/* 0D1A10 7F09CEA0 AC2F01A0 */  sw    $t7, %lo(numExplosionEntries)($at)
.Ljp7F09CEA4:
/* 0D1A14 7F09CEA4 92220039 */  lbu   $v0, 0x39($s1)
/* 0D1A18 7F09CEA8 00003025 */  move  $a2, $zero
/* 0D1A1C 7F09CEAC 1840000A */  blez  $v0, .Ljp7F09CED8
/* 0D1A20 7F09CEB0 00022C00 */   sll   $a1, $v0, 0x10
/* 0D1A24 7F09CEB4 0005C403 */  sra   $t8, $a1, 0x10
/* 0D1A28 7F09CEB8 03002825 */  move  $a1, $t8
/* 0D1A2C 7F09CEBC 8C843760 */  lw    $a0, %lo(g_musicSfxBufferPtr)($a0)
/* 0D1A30 7F09CEC0 0C002386 */  jal   sndPlaySfx
/* 0D1A34 7F09CEC4 AFA70038 */   sw    $a3, 0x38($sp)
/* 0D1A38 7F09CEC8 00402025 */  move  $a0, $v0
/* 0D1A3C 7F09CECC 0FC14FC3 */  jal   sub_GAME_7F053A10
/* 0D1A40 7F09CED0 02602825 */   move  $a1, $s3
/* 0D1A44 7F09CED4 8FA70038 */  lw    $a3, 0x38($sp)
.Ljp7F09CED8:
/* 0D1A48 7F09CED8 10E00108 */  beqz  $a3, .Ljp7F09D2FC
/* 0D1A4C 7F09CEDC 8FA60068 */   lw    $a2, 0x68($sp)
/* 0D1A50 7F09CEE0 90EE0001 */  lbu   $t6, 1($a3)
/* 0D1A54 7F09CEE4 24190007 */  li    $t9, 7
/* 0D1A58 7F09CEE8 A0F90000 */  sb    $t9, ($a3)
/* 0D1A5C 7F09CEEC 35CF0002 */  ori   $t7, $t6, 2
/* 0D1A60 7F09CEF0 A0EF0001 */  sb    $t7, 1($a3)
/* 0D1A64 7F09CEF4 ACF40004 */  sw    $s4, 4($a3)
/* 0D1A68 7F09CEF8 8FB80058 */  lw    $t8, 0x58($sp)
/* 0D1A6C 7F09CEFC 240500FF */  li    $a1, 255
/* 0D1A70 7F09CF00 00008025 */  move  $s0, $zero
/* 0D1A74 7F09CF04 ACF80014 */  sw    $t8, 0x14($a3)
/* 0D1A78 7F09CF08 C6640000 */  lwc1  $f4, ($s3)
/* 0D1A7C 7F09CF0C 240E00FF */  li    $t6, 255
/* 0D1A80 7F09CF10 E4E40008 */  swc1  $f4, 8($a3)
/* 0D1A84 7F09CF14 C6660004 */  lwc1  $f6, 4($s3)
/* 0D1A88 7F09CF18 E4E6000C */  swc1  $f6, 0xc($a3)
/* 0D1A8C 7F09CF1C C6680008 */  lwc1  $f8, 8($s3)
/* 0D1A90 7F09CF20 E4E80010 */  swc1  $f8, 0x10($a3)
/* 0D1A94 7F09CF24 90D90000 */  lbu   $t9, ($a2)
/* 0D1A98 7F09CF28 10B9000C */  beq   $a1, $t9, .Ljp7F09CF5C
/* 0D1A9C 7F09CF2C 00E01821 */   addu  $v1, $a3, $zero
/* 0D1AA0 7F09CF30 00C01021 */  addu  $v0, $a2, $zero
/* 0D1AA4 7F09CF34 90C40000 */  lbu   $a0, ($a2)
/* 0D1AA8 7F09CF38 24120007 */  li    $s2, 7
/* 0D1AAC 7F09CF3C A064002C */  sb    $a0, 0x2c($v1)
.Ljp7F09CF40:
/* 0D1AB0 7F09CF40 90440001 */  lbu   $a0, 1($v0)
/* 0D1AB4 7F09CF44 26100001 */  addiu $s0, $s0, 1
/* 0D1AB8 7F09CF48 24630001 */  addiu $v1, $v1, 1
/* 0D1ABC 7F09CF4C 10A40003 */  beq   $a1, $a0, .Ljp7F09CF5C
/* 0D1AC0 7F09CF50 24420001 */   addiu $v0, $v0, 1
/* 0D1AC4 7F09CF54 5612FFFA */  bnel  $s0, $s2, .Ljp7F09CF40
/* 0D1AC8 7F09CF58 A064002C */   sb    $a0, 0x2c($v1)
.Ljp7F09CF5C:
/* 0D1ACC 7F09CF5C 00F07821 */  addu  $t7, $a3, $s0
/* 0D1AD0 7F09CF60 A1EE002C */  sb    $t6, 0x2c($t7)
/* 0D1AD4 7F09CF64 8FB8006C */  lw    $t8, 0x6c($sp)
/* 0D1AD8 7F09CF68 24120007 */  li    $s2, 7
/* 0D1ADC 7F09CF6C 00008025 */  move  $s0, $zero
/* 0D1AE0 7F09CF70 13000004 */  beqz  $t8, .Ljp7F09CF84
/* 0D1AE4 7F09CF74 00E02025 */   move  $a0, $a3
/* 0D1AE8 7F09CF78 90F90001 */  lbu   $t9, 1($a3)
/* 0D1AEC 7F09CF7C 372E0008 */  ori   $t6, $t9, 8
/* 0D1AF0 7F09CF80 A0EE0001 */  sb    $t6, 1($a3)
.Ljp7F09CF84:
/* 0D1AF4 7F09CF84 0FC0E9FC */  jal   chrpropActivateThisFrame
/* 0D1AF8 7F09CF88 AFA70038 */   sw    $a3, 0x38($sp)
/* 0D1AFC 7F09CF8C 0FC0E9C1 */  jal   chrpropEnable
/* 0D1B00 7F09CF90 8FA40038 */   lw    $a0, 0x38($sp)
/* 0D1B04 7F09CF94 8FA20060 */  lw    $v0, 0x60($sp)
/* 0D1B08 7F09CF98 8FA70038 */  lw    $a3, 0x38($sp)
/* 0D1B0C 7F09CF9C 8FA80050 */  lw    $t0, 0x50($sp)
/* 0D1B10 7F09CFA0 87AF005E */  lh    $t7, 0x5e($sp)
/* 0D1B14 7F09CFA4 2418FFFF */  li    $t8, -1
/* 0D1B18 7F09CFA8 A68003C8 */  sh    $zero, 0x3c8($s4)
/* 0D1B1C 7F09CFAC A69803CA */  sh    $t8, 0x3ca($s4)
/* 0D1B20 7F09CFB0 A28203CD */  sb    $v0, 0x3cd($s4)
/* 0D1B24 7F09CFB4 AE870000 */  sw    $a3, ($s4)
/* 0D1B28 7F09CFB8 AE880004 */  sw    $t0, 4($s4)
/* 0D1B2C 7F09CFBC A28F03CC */  sb    $t7, 0x3cc($s4)
/* 0D1B30 7F09CFC0 8FB90064 */  lw    $t9, 0x64($sp)
/* 0D1B34 7F09CFC4 3C018005 */  lui   $at, %hi(D_800576B0) # $at, 0x8005
/* 0D1B38 7F09CFC8 10400028 */  beqz  $v0, .Ljp7F09D06C
/* 0D1B3C 7F09CFCC A29903CE */   sb    $t9, 0x3ce($s4)
/* 0D1B40 7F09CFD0 51000016 */  beql  $t0, $zero, .Ljp7F09D02C
/* 0D1B44 7F09CFD4 C6660000 */   lwc1  $f6, ($s3)
/* 0D1B48 7F09CFD8 8D0E0014 */  lw    $t6, 0x14($t0)
/* 0D1B4C 7F09CFDC 51C00013 */  beql  $t6, $zero, .Ljp7F09D02C
/* 0D1B50 7F09CFE0 C6660000 */   lwc1  $f6, ($s3)
/* 0D1B54 7F09CFE4 C50A0008 */  lwc1  $f10, 8($t0)
/* 0D1B58 7F09CFE8 E68A03D0 */  swc1  $f10, 0x3d0($s4)
/* 0D1B5C 7F09CFEC 8D060010 */  lw    $a2, 0x10($t0)
/* 0D1B60 7F09CFF0 8D050008 */  lw    $a1, 8($t0)
/* 0D1B64 7F09CFF4 0FC2CD48 */  jal   stanGetPositionYValue
/* 0D1B68 7F09CFF8 8D040014 */   lw    $a0, 0x14($t0)
/* 0D1B6C 7F09CFFC 3C014080 */  li    $at, 0x40800000 # 4.000000
/* 0D1B70 7F09D000 44818000 */  mtc1  $at, $f16
/* 0D1B74 7F09D004 8FA80050 */  lw    $t0, 0x50($sp)
/* 0D1B78 7F09D008 46100480 */  add.s $f18, $f0, $f16
/* 0D1B7C 7F09D00C E69203D4 */  swc1  $f18, 0x3d4($s4)
/* 0D1B80 7F09D010 C5040010 */  lwc1  $f4, 0x10($t0)
/* 0D1B84 7F09D014 E68403D8 */  swc1  $f4, 0x3d8($s4)
/* 0D1B88 7F09D018 0FC2CEE2 */  jal   getTileRoom
/* 0D1B8C 7F09D01C 8D040014 */   lw    $a0, 0x14($t0)
/* 0D1B90 7F09D020 10000014 */  b     .Ljp7F09D074
/* 0D1B94 7F09D024 A68203DC */   sh    $v0, 0x3dc($s4)
/* 0D1B98 7F09D028 C6660000 */  lwc1  $f6, ($s3)
.Ljp7F09D02C:
/* 0D1B9C 7F09D02C E68603D0 */  swc1  $f6, 0x3d0($s4)
/* 0D1BA0 7F09D030 8E660008 */  lw    $a2, 8($s3)
/* 0D1BA4 7F09D034 8E650000 */  lw    $a1, ($s3)
/* 0D1BA8 7F09D038 0FC2CD48 */  jal   stanGetPositionYValue
/* 0D1BAC 7F09D03C 8FA40058 */   lw    $a0, 0x58($sp)
/* 0D1BB0 7F09D040 3C014080 */  li    $at, 0x40800000 # 4.000000
/* 0D1BB4 7F09D044 44814000 */  mtc1  $at, $f8
/* 0D1BB8 7F09D048 00000000 */  nop   
/* 0D1BBC 7F09D04C 46080280 */  add.s $f10, $f0, $f8
/* 0D1BC0 7F09D050 E68A03D4 */  swc1  $f10, 0x3d4($s4)
/* 0D1BC4 7F09D054 C6700008 */  lwc1  $f16, 8($s3)
/* 0D1BC8 7F09D058 E69003D8 */  swc1  $f16, 0x3d8($s4)
/* 0D1BCC 7F09D05C 0FC2CEE2 */  jal   getTileRoom
/* 0D1BD0 7F09D060 8FA40058 */   lw    $a0, 0x58($sp)
/* 0D1BD4 7F09D064 10000003 */  b     .Ljp7F09D074
/* 0D1BD8 7F09D068 A68203DC */   sh    $v0, 0x3dc($s4)
.Ljp7F09D06C:
/* 0D1BDC 7F09D06C C43276E0 */  lwc1  $f18, %lo(D_800576B0)($at)
/* 0D1BE0 7F09D070 E69203D0 */  swc1  $f18, 0x3d0($s4)
.Ljp7F09D074:
/* 0D1BE4 7F09D074 0C002918 */  jal   randomGetNext
/* 0D1BE8 7F09D078 00000000 */   nop   
/* 0D1BEC 7F09D07C 44822000 */  mtc1  $v0, $f4
/* 0D1BF0 7F09D080 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0D1BF4 7F09D084 04410004 */  bgez  $v0, .Ljp7F09D098
/* 0D1BF8 7F09D088 468021A0 */   cvt.s.w $f6, $f4
/* 0D1BFC 7F09D08C 44814000 */  mtc1  $at, $f8
/* 0D1C00 7F09D090 00000000 */  nop   
/* 0D1C04 7F09D094 46083180 */  add.s $f6, $f6, $f8
.Ljp7F09D098:
/* 0D1C08 7F09D098 3C012F80 */  li    $at, 0x2F800000 # 0.000000
/* 0D1C0C 7F09D09C 44815000 */  mtc1  $at, $f10
/* 0D1C10 7F09D0A0 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 0D1C14 7F09D0A4 44819000 */  mtc1  $at, $f18
/* 0D1C18 7F09D0A8 460A3402 */  mul.s $f16, $f6, $f10
/* 0D1C1C 7F09D0AC 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0D1C20 7F09D0B0 44814000 */  mtc1  $at, $f8
/* 0D1C24 7F09D0B4 C62A0010 */  lwc1  $f10, 0x10($s1)
/* 0D1C28 7F09D0B8 46128102 */  mul.s $f4, $f16, $f18
/* 0D1C2C 7F09D0BC 46082180 */  add.s $f6, $f4, $f8
/* 0D1C30 7F09D0C0 460A3402 */  mul.s $f16, $f6, $f10
/* 0D1C34 7F09D0C4 0C002918 */  jal   randomGetNext
/* 0D1C38 7F09D0C8 E7B00044 */   swc1  $f16, 0x44($sp)
/* 0D1C3C 7F09D0CC 44829000 */  mtc1  $v0, $f18
/* 0D1C40 7F09D0D0 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0D1C44 7F09D0D4 04410004 */  bgez  $v0, .Ljp7F09D0E8
/* 0D1C48 7F09D0D8 46809120 */   cvt.s.w $f4, $f18
/* 0D1C4C 7F09D0DC 44814000 */  mtc1  $at, $f8
/* 0D1C50 7F09D0E0 00000000 */  nop   
/* 0D1C54 7F09D0E4 46082100 */  add.s $f4, $f4, $f8
.Ljp7F09D0E8:
/* 0D1C58 7F09D0E8 3C012F80 */  li    $at, 0x2F800000 # 0.000000
/* 0D1C5C 7F09D0EC 44813000 */  mtc1  $at, $f6
/* 0D1C60 7F09D0F0 3C018005 */  lui   $at, %hi(D_800576B4) # $at, 0x8005
/* 0D1C64 7F09D0F4 C43076E4 */  lwc1  $f16, %lo(D_800576B4)($at)
/* 0D1C68 7F09D0F8 46062282 */  mul.s $f10, $f4, $f6
/* 0D1C6C 7F09D0FC 00000000 */  nop   
/* 0D1C70 7F09D100 46105302 */  mul.s $f12, $f10, $f16
/* 0D1C74 7F09D104 0FC160F0 */  jal   cosf
/* 0D1C78 7F09D108 E7AC0040 */   swc1  $f12, 0x40($sp)
/* 0D1C7C 7F09D10C C7B20044 */  lwc1  $f18, 0x44($sp)
/* 0D1C80 7F09D110 46120202 */  mul.s $f8, $f0, $f18
/* 0D1C84 7F09D114 E6880014 */  swc1  $f8, 0x14($s4)
/* 0D1C88 7F09D118 0FC160F3 */  jal   sinf
/* 0D1C8C 7F09D11C C7AC0040 */   lwc1  $f12, 0x40($sp)
/* 0D1C90 7F09D120 C7A40044 */  lwc1  $f4, 0x44($sp)
/* 0D1C94 7F09D124 240F0001 */  li    $t7, 1
/* 0D1C98 7F09D128 A68F001C */  sh    $t7, 0x1c($s4)
/* 0D1C9C 7F09D12C 46040182 */  mul.s $f6, $f0, $f4
/* 0D1CA0 7F09D130 E6860018 */  swc1  $f6, 0x18($s4)
/* 0D1CA4 7F09D134 C66A0000 */  lwc1  $f10, ($s3)
/* 0D1CA8 7F09D138 E68A0008 */  swc1  $f10, 8($s4)
/* 0D1CAC 7F09D13C C6700004 */  lwc1  $f16, 4($s3)
/* 0D1CB0 7F09D140 E690000C */  swc1  $f16, 0xc($s4)
/* 0D1CB4 7F09D144 C6720008 */  lwc1  $f18, 8($s3)
/* 0D1CB8 7F09D148 E6920010 */  swc1  $f18, 0x10($s4)
/* 0D1CBC 7F09D14C 86380024 */  lh    $t8, 0x24($s1)
/* 0D1CC0 7F09D150 1B00000E */  blez  $t8, .Ljp7F09D18C
/* 0D1CC4 7F09D154 00000000 */   nop   
/* 0D1CC8 7F09D158 C6280028 */  lwc1  $f8, 0x28($s1)
.Ljp7F09D15C:
/* 0D1CCC 7F09D15C 8E25002C */  lw    $a1, 0x2c($s1)
/* 0D1CD0 7F09D160 8E260030 */  lw    $a2, 0x30($s1)
/* 0D1CD4 7F09D164 8E270034 */  lw    $a3, 0x34($s1)
/* 0D1CD8 7F09D168 02602025 */  move  $a0, $s3
/* 0D1CDC 7F09D16C 0FC27F7E */  jal   sub_GAME_7F09F254
/* 0D1CE0 7F09D170 E7A80010 */   swc1  $f8, 0x10($sp)
/* 0D1CE4 7F09D174 8FB9004C */  lw    $t9, 0x4c($sp)
/* 0D1CE8 7F09D178 26100001 */  addiu $s0, $s0, 1
/* 0D1CEC 7F09D17C 872E0024 */  lh    $t6, 0x24($t9)
/* 0D1CF0 7F09D180 020E082A */  slt   $at, $s0, $t6
/* 0D1CF4 7F09D184 5420FFF5 */  bnezl $at, .Ljp7F09D15C
/* 0D1CF8 7F09D188 C6280028 */   lwc1  $f8, 0x28($s1)
.Ljp7F09D18C:
/* 0D1CFC 7F09D18C 0FC26C01 */  jal   getPlayerCount
/* 0D1D00 7F09D190 00000000 */   nop   
/* 0D1D04 7F09D194 28410002 */  slti  $at, $v0, 2
/* 0D1D08 7F09D198 14200058 */  bnez  $at, .Ljp7F09D2FC
/* 0D1D0C 7F09D19C 00003025 */   move  $a2, $zero
/* 0D1D10 7F09D1A0 3C0D8008 */  lui   $t5, %hi(ptr_smoke_buf) # $t5, 0x8008
/* 0D1D14 7F09D1A4 3C0B8004 */  lui   $t3, %hi(array_smoke_types) # $t3, 0x8004
/* 0D1D18 7F09D1A8 256B01AC */  addiu $t3, %lo(array_smoke_types) # addiu $t3, $t3, 0x1ac
/* 0D1D1C 7F09D1AC 25ADA1B0 */  addiu $t5, %lo(ptr_smoke_buf) # addiu $t5, $t5, -0x5e50
/* 0D1D20 7F09D1B0 241F1FE0 */  li    $ra, 8160
/* 0D1D24 7F09D1B4 240C0018 */  li    $t4, 24
/* 0D1D28 7F09D1B8 240A0009 */  li    $t2, 9
/* 0D1D2C 7F09D1BC 24090008 */  li    $t1, 8
/* 0D1D30 7F09D1C0 8DA30000 */  lw    $v1, ($t5)
.Ljp7F09D1C4:
/* 0D1D34 7F09D1C4 00662821 */  addu  $a1, $v1, $a2
/* 0D1D38 7F09D1C8 8CAF0000 */  lw    $t7, ($a1)
/* 0D1D3C 7F09D1CC 00C33821 */  addu  $a3, $a2, $v1
/* 0D1D40 7F09D1D0 51E00011 */  beql  $t7, $zero, .Ljp7F09D218
/* 0D1D44 7F09D1D4 8CAF0198 */   lw    $t7, 0x198($a1)
/* 0D1D48 7F09D1D8 84E20006 */  lh    $v0, 6($a3)
/* 0D1D4C 7F09D1DC 5242000E */  beql  $s2, $v0, .Ljp7F09D218
/* 0D1D50 7F09D1E0 8CAF0198 */   lw    $t7, 0x198($a1)
/* 0D1D54 7F09D1E4 84E80006 */  lh    $t0, 6($a3)
/* 0D1D58 7F09D1E8 5128000B */  beql  $t1, $t0, .Ljp7F09D218
/* 0D1D5C 7F09D1EC 8CAF0198 */   lw    $t7, 0x198($a1)
/* 0D1D60 7F09D1F0 51480009 */  beql  $t2, $t0, .Ljp7F09D218
/* 0D1D64 7F09D1F4 8CAF0198 */   lw    $t7, 0x198($a1)
/* 0D1D68 7F09D1F8 004C0019 */  multu $v0, $t4
/* 0D1D6C 7F09D1FC 0000C012 */  mflo  $t8
/* 0D1D70 7F09D200 0178C821 */  addu  $t9, $t3, $t8
/* 0D1D74 7F09D204 872E0000 */  lh    $t6, ($t9)
/* 0D1D78 7F09D208 A4EE0004 */  sh    $t6, 4($a3)
/* 0D1D7C 7F09D20C 8DA30000 */  lw    $v1, ($t5)
/* 0D1D80 7F09D210 00662821 */  addu  $a1, $v1, $a2
/* 0D1D84 7F09D214 8CAF0198 */  lw    $t7, 0x198($a1)
.Ljp7F09D218:
/* 0D1D88 7F09D218 00C32021 */  addu  $a0, $a2, $v1
/* 0D1D8C 7F09D21C 51E00011 */  beql  $t7, $zero, .Ljp7F09D264
/* 0D1D90 7F09D220 8CAF0330 */   lw    $t7, 0x330($a1)
/* 0D1D94 7F09D224 8482019E */  lh    $v0, 0x19e($a0)
/* 0D1D98 7F09D228 24840198 */  addiu $a0, $a0, 0x198
/* 0D1D9C 7F09D22C 5242000D */  beql  $s2, $v0, .Ljp7F09D264
/* 0D1DA0 7F09D230 8CAF0330 */   lw    $t7, 0x330($a1)
/* 0D1DA4 7F09D234 5122000B */  beql  $t1, $v0, .Ljp7F09D264
/* 0D1DA8 7F09D238 8CAF0330 */   lw    $t7, 0x330($a1)
/* 0D1DAC 7F09D23C 51420009 */  beql  $t2, $v0, .Ljp7F09D264
/* 0D1DB0 7F09D240 8CAF0330 */   lw    $t7, 0x330($a1)
/* 0D1DB4 7F09D244 004C0019 */  multu $v0, $t4
/* 0D1DB8 7F09D248 0000C012 */  mflo  $t8
/* 0D1DBC 7F09D24C 0178C821 */  addu  $t9, $t3, $t8
/* 0D1DC0 7F09D250 872E0000 */  lh    $t6, ($t9)
/* 0D1DC4 7F09D254 A48E0004 */  sh    $t6, 4($a0)
/* 0D1DC8 7F09D258 8DA30000 */  lw    $v1, ($t5)
/* 0D1DCC 7F09D25C 00662821 */  addu  $a1, $v1, $a2
/* 0D1DD0 7F09D260 8CAF0330 */  lw    $t7, 0x330($a1)
.Ljp7F09D264:
/* 0D1DD4 7F09D264 00C32021 */  addu  $a0, $a2, $v1
/* 0D1DD8 7F09D268 51E00011 */  beql  $t7, $zero, .Ljp7F09D2B0
/* 0D1DDC 7F09D26C 8CAF04C8 */   lw    $t7, 0x4c8($a1)
/* 0D1DE0 7F09D270 84820336 */  lh    $v0, 0x336($a0)
/* 0D1DE4 7F09D274 24840330 */  addiu $a0, $a0, 0x330
/* 0D1DE8 7F09D278 5242000D */  beql  $s2, $v0, .Ljp7F09D2B0
/* 0D1DEC 7F09D27C 8CAF04C8 */   lw    $t7, 0x4c8($a1)
/* 0D1DF0 7F09D280 5122000B */  beql  $t1, $v0, .Ljp7F09D2B0
/* 0D1DF4 7F09D284 8CAF04C8 */   lw    $t7, 0x4c8($a1)
/* 0D1DF8 7F09D288 51420009 */  beql  $t2, $v0, .Ljp7F09D2B0
/* 0D1DFC 7F09D28C 8CAF04C8 */   lw    $t7, 0x4c8($a1)
/* 0D1E00 7F09D290 004C0019 */  multu $v0, $t4
/* 0D1E04 7F09D294 0000C012 */  mflo  $t8
/* 0D1E08 7F09D298 0178C821 */  addu  $t9, $t3, $t8
/* 0D1E0C 7F09D29C 872E0000 */  lh    $t6, ($t9)
/* 0D1E10 7F09D2A0 A48E0004 */  sh    $t6, 4($a0)
/* 0D1E14 7F09D2A4 8DA30000 */  lw    $v1, ($t5)
/* 0D1E18 7F09D2A8 00662821 */  addu  $a1, $v1, $a2
/* 0D1E1C 7F09D2AC 8CAF04C8 */  lw    $t7, 0x4c8($a1)
.Ljp7F09D2B0:
/* 0D1E20 7F09D2B0 00C32021 */  addu  $a0, $a2, $v1
/* 0D1E24 7F09D2B4 51E0000F */  beql  $t7, $zero, .Ljp7F09D2F4
/* 0D1E28 7F09D2B8 24C60660 */   addiu $a2, $a2, 0x660
/* 0D1E2C 7F09D2BC 848204CE */  lh    $v0, 0x4ce($a0)
/* 0D1E30 7F09D2C0 248404C8 */  addiu $a0, $a0, 0x4c8
/* 0D1E34 7F09D2C4 5242000B */  beql  $s2, $v0, .Ljp7F09D2F4
/* 0D1E38 7F09D2C8 24C60660 */   addiu $a2, $a2, 0x660
/* 0D1E3C 7F09D2CC 51220009 */  beql  $t1, $v0, .Ljp7F09D2F4
/* 0D1E40 7F09D2D0 24C60660 */   addiu $a2, $a2, 0x660
/* 0D1E44 7F09D2D4 51420007 */  beql  $t2, $v0, .Ljp7F09D2F4
/* 0D1E48 7F09D2D8 24C60660 */   addiu $a2, $a2, 0x660
/* 0D1E4C 7F09D2DC 004C0019 */  multu $v0, $t4
/* 0D1E50 7F09D2E0 0000C012 */  mflo  $t8
/* 0D1E54 7F09D2E4 0178C821 */  addu  $t9, $t3, $t8
/* 0D1E58 7F09D2E8 872E0000 */  lh    $t6, ($t9)
/* 0D1E5C 7F09D2EC A48E0004 */  sh    $t6, 4($a0)
/* 0D1E60 7F09D2F0 24C60660 */  addiu $a2, $a2, 0x660
.Ljp7F09D2F4:
/* 0D1E64 7F09D2F4 54DFFFB3 */  bnel  $a2, $ra, .Ljp7F09D1C4
/* 0D1E68 7F09D2F8 8DA30000 */   lw    $v1, ($t5)
.Ljp7F09D2FC:
/* 0D1E6C 7F09D2FC 8FBF0034 */  lw    $ra, 0x34($sp)
.Ljp7F09D300:
/* 0D1E70 7F09D300 0014102B */  sltu  $v0, $zero, $s4
/* 0D1E74 7F09D304 8FB40030 */  lw    $s4, 0x30($sp)
/* 0D1E78 7F09D308 8FB00020 */  lw    $s0, 0x20($sp)
/* 0D1E7C 7F09D30C 8FB10024 */  lw    $s1, 0x24($sp)
/* 0D1E80 7F09D310 8FB20028 */  lw    $s2, 0x28($sp)
/* 0D1E84 7F09D314 8FB3002C */  lw    $s3, 0x2c($sp)
/* 0D1E88 7F09D318 03E00008 */  jr    $ra
/* 0D1E8C 7F09D31C 27BD0050 */   addiu $sp, $sp, 0x50
)
#endif



#endif


void setSixExplosionAndSmokeEntries(void) {
        numExplosionEntries = 6;
        numSmokeEntries = 6;
}





#ifdef NONMATCHING
void sub_GAME_7F09C7C4(void) {

}
#else
#ifdef VERSION_US
GLOBAL_ASM(
.late_rodata
glabel D_800576B8
.word 0x3f4ccccd /*0.80000001*/
.text
glabel sub_GAME_7F09C7C4
/* 0D12F4 7F09C7C4 27BDFFA8 */  addiu $sp, $sp, -0x58
/* 0D12F8 7F09C7C8 3C0E8004 */  lui   $t6, %hi(numExplosionEntries) 
/* 0D12FC 7F09C7CC 8DCE0170 */  lw    $t6, %lo(numExplosionEntries)($t6)
/* 0D1300 7F09C7D0 AFB20030 */  sw    $s2, 0x30($sp)
/* 0D1304 7F09C7D4 AFB1002C */  sw    $s1, 0x2c($sp)
/* 0D1308 7F09C7D8 00808825 */  move  $s1, $a0
/* 0D130C 7F09C7DC 00A09025 */  move  $s2, $a1
/* 0D1310 7F09C7E0 AFBF003C */  sw    $ra, 0x3c($sp)
/* 0D1314 7F09C7E4 AFB40038 */  sw    $s4, 0x38($sp)
/* 0D1318 7F09C7E8 AFB30034 */  sw    $s3, 0x34($sp)
/* 0D131C 7F09C7EC AFB00028 */  sw    $s0, 0x28($sp)
/* 0D1320 7F09C7F0 F7B60020 */  sdc1  $f22, 0x20($sp)
/* 0D1324 7F09C7F4 F7B40018 */  sdc1  $f20, 0x18($sp)
/* 0D1328 7F09C7F8 15C00006 */  bnez  $t6, .L7F09C814
/* 0D132C 7F09C7FC AFA60060 */   sw    $a2, 0x60($sp)
/* 0D1330 7F09C800 44806000 */  mtc1  $zero, $f12
/* 0D1334 7F09C804 0C000EC1 */  jal   viShake
/* 0D1338 7F09C808 00000000 */   nop   
/* 0D133C 7F09C80C 10000069 */  b     .L7F09C9B4
/* 0D1340 7F09C810 8FBF003C */   lw    $ra, 0x3c($sp)
.L7F09C814:
/* 0D1344 7F09C814 3C018005 */  lui   $at, %hi(D_800576B8)
/* 0D1348 7F09C818 C43476B8 */  lwc1  $f20, %lo(D_800576B8)($at)
/* 0D134C 7F09C81C 0FC15FA8 */  jal   cosf
/* 0D1350 7F09C820 4600A306 */   mov.s $f12, $f20
/* 0D1354 7F09C824 46000586 */  mov.s $f22, $f0
/* 0D1358 7F09C828 0FC15FAB */  jal   sinf
/* 0D135C 7F09C82C 4600A306 */   mov.s $f12, $f20
/* 0D1360 7F09C830 C6440000 */  lwc1  $f4, ($s2)
/* 0D1364 7F09C834 C6480008 */  lwc1  $f8, 8($s2)
/* 0D1368 7F09C838 4600A306 */  mov.s $f12, $f20
/* 0D136C 7F09C83C 4604B182 */  mul.s $f6, $f22, $f4
/* 0D1370 7F09C840 00000000 */  nop   
/* 0D1374 7F09C844 46004282 */  mul.s $f10, $f8, $f0
/* 0D1378 7F09C848 460A3401 */  sub.s $f16, $f6, $f10
/* 0D137C 7F09C84C 0FC15FAB */  jal   sinf
/* 0D1380 7F09C850 E7B00044 */   swc1  $f16, 0x44($sp)
/* 0D1384 7F09C854 46000586 */  mov.s $f22, $f0
/* 0D1388 7F09C858 0FC15FA8 */  jal   cosf
/* 0D138C 7F09C85C 4600A306 */   mov.s $f12, $f20
/* 0D1390 7F09C860 C6520008 */  lwc1  $f18, 8($s2)
/* 0D1394 7F09C864 C6480000 */  lwc1  $f8, ($s2)
/* 0D1398 7F09C868 3C014170 */  li    $at, 0x41700000 # 15.000000
/* 0D139C 7F09C86C 46009102 */  mul.s $f4, $f18, $f0
/* 0D13A0 7F09C870 3C128004 */  lui   $s2, %hi(array_explosion_types)
/* 0D13A4 7F09C874 3C028008 */  lui   $v0, %hi(ptr_explosion_buf)
/* 0D13A8 7F09C878 4608B182 */  mul.s $f6, $f22, $f8
/* 0D13AC 7F09C87C 3C138008 */  lui   $s3, %hi(ptr_explosion_buf)
/* 0D13B0 7F09C880 4480A000 */  mtc1  $zero, $f20
/* 0D13B4 7F09C884 4481B000 */  mtc1  $at, $f22
/* 0D13B8 7F09C888 2673A144 */  addiu $s3, %lo(ptr_explosion_buf) # addiu $s3, $s3, -0x5ebc
/* 0D13BC 7F09C88C 8C42A144 */  lw    $v0, %lo(ptr_explosion_buf)($v0)
/* 0D13C0 7F09C890 26520284 */  addiu $s2, %lo(array_explosion_types) # addiu $s2, $s2, 0x284
/* 0D13C4 7F09C894 46062280 */  add.s $f10, $f4, $f6
/* 0D13C8 7F09C898 00008025 */  move  $s0, $zero
/* 0D13CC 7F09C89C 24141740 */  li    $s4, 5952
/* 0D13D0 7F09C8A0 E7AA0040 */  swc1  $f10, 0x40($sp)
.L7F09C8A4:
/* 0D13D4 7F09C8A4 8C430000 */  lw    $v1, ($v0)
/* 0D13D8 7F09C8A8 5060001A */  beql  $v1, $zero, .L7F09C914
/* 0D13DC 7F09C8AC 261003E0 */   addiu $s0, $s0, 0x3e0
/* 0D13E0 7F09C8B0 C4700008 */  lwc1  $f16, 8($v1)
/* 0D13E4 7F09C8B4 C6320000 */  lwc1  $f18, ($s1)
/* 0D13E8 7F09C8B8 C468000C */  lwc1  $f8, 0xc($v1)
/* 0D13EC 7F09C8BC C6240004 */  lwc1  $f4, 4($s1)
/* 0D13F0 7F09C8C0 46128001 */  sub.s $f0, $f16, $f18
/* 0D13F4 7F09C8C4 C4660010 */  lwc1  $f6, 0x10($v1)
/* 0D13F8 7F09C8C8 C62A0008 */  lwc1  $f10, 8($s1)
/* 0D13FC 7F09C8CC 46044081 */  sub.s $f2, $f8, $f4
/* 0D1400 7F09C8D0 46000402 */  mul.s $f16, $f0, $f0
/* 0D1404 7F09C8D4 460A3381 */  sub.s $f14, $f6, $f10
/* 0D1408 7F09C8D8 46021482 */  mul.s $f18, $f2, $f2
/* 0D140C 7F09C8DC 46128200 */  add.s $f8, $f16, $f18
/* 0D1410 7F09C8E0 460E7102 */  mul.s $f4, $f14, $f14
/* 0D1414 7F09C8E4 0C007DF8 */  jal   sqrtf
/* 0D1418 7F09C8E8 46044300 */   add.s $f12, $f8, $f4
/* 0D141C 7F09C8EC 8E6F0000 */  lw    $t7, ($s3)
/* 0D1420 7F09C8F0 01F01021 */  addu  $v0, $t7, $s0
/* 0D1424 7F09C8F4 805803CC */  lb    $t8, 0x3cc($v0)
/* 0D1428 7F09C8F8 0018C980 */  sll   $t9, $t8, 6
/* 0D142C 7F09C8FC 02594021 */  addu  $t0, $s2, $t9
/* 0D1430 7F09C900 C5060010 */  lwc1  $f6, 0x10($t0)
/* 0D1434 7F09C904 46003083 */  div.s $f2, $f6, $f0
/* 0D1438 7F09C908 46161282 */  mul.s $f10, $f2, $f22
/* 0D143C 7F09C90C 460AA500 */  add.s $f20, $f20, $f10
/* 0D1440 7F09C910 261003E0 */  addiu $s0, $s0, 0x3e0
.L7F09C914:
/* 0D1444 7F09C914 1614FFE3 */  bne   $s0, $s4, .L7F09C8A4
/* 0D1448 7F09C918 244203E0 */   addiu $v0, $v0, 0x3e0
/* 0D144C 7F09C91C 3C038004 */  lui   $v1, %hi(numSmokeEntries)
/* 0D1450 7F09C920 24630174 */  addiu $v1, %lo(numSmokeEntries) # addiu $v1, $v1, 0x174
/* 0D1454 7F09C924 8C620000 */  lw    $v0, ($v1)
/* 0D1458 7F09C928 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0D145C 7F09C92C 18400005 */  blez  $v0, .L7F09C944
/* 0D1460 7F09C930 00000000 */   nop   
/* 0D1464 7F09C934 44818000 */  mtc1  $at, $f16
/* 0D1468 7F09C938 2449FFFF */  addiu $t1, $v0, -1
/* 0D146C 7F09C93C AC690000 */  sw    $t1, ($v1)
/* 0D1470 7F09C940 4610A500 */  add.s $f20, $f20, $f16
.L7F09C944:
/* 0D1474 7F09C944 3C028004 */  lui   $v0, %hi(numExplosionEntries)
/* 0D1478 7F09C948 24420170 */  addiu $v0, %lo(numExplosionEntries) # addiu $v0, $v0, 0x170
/* 0D147C 7F09C94C 8C4A0000 */  lw    $t2, ($v0)
/* 0D1480 7F09C950 254BFFFF */  addiu $t3, $t2, -1
/* 0D1484 7F09C954 316D0002 */  andi  $t5, $t3, 2
/* 0D1488 7F09C958 11A00005 */  beqz  $t5, .L7F09C970
/* 0D148C 7F09C95C AC4B0000 */   sw    $t3, ($v0)
/* 0D1490 7F09C960 8FA30060 */  lw    $v1, 0x60($sp)
/* 0D1494 7F09C964 E4740004 */  swc1  $f20, 4($v1)
/* 0D1498 7F09C968 10000004 */  b     .L7F09C97C
/* 0D149C 7F09C96C 4600A507 */   neg.s $f20, $f20
.L7F09C970:
/* 0D14A0 7F09C970 8FA30060 */  lw    $v1, 0x60($sp)
/* 0D14A4 7F09C974 4600A487 */  neg.s $f18, $f20
/* 0D14A8 7F09C978 E4720004 */  swc1  $f18, 4($v1)
.L7F09C97C:
/* 0D14AC 7F09C97C C7A80044 */  lwc1  $f8, 0x44($sp)
/* 0D14B0 7F09C980 4608A102 */  mul.s $f4, $f20, $f8
/* 0D14B4 7F09C984 E4640000 */  swc1  $f4, ($v1)
/* 0D14B8 7F09C988 C7A60040 */  lwc1  $f6, 0x40($sp)
/* 0D14BC 7F09C98C 4606A282 */  mul.s $f10, $f20, $f6
/* 0D14C0 7F09C990 E46A0008 */  swc1  $f10, 8($v1)
/* 0D14C4 7F09C994 8C4F0000 */  lw    $t7, ($v0)
/* 0D14C8 7F09C998 448F8000 */  mtc1  $t7, $f16
/* 0D14CC 7F09C99C 00000000 */  nop   
/* 0D14D0 7F09C9A0 468084A0 */  cvt.s.w $f18, $f16
/* 0D14D4 7F09C9A4 46149302 */  mul.s $f12, $f18, $f20
/* 0D14D8 7F09C9A8 0C000EC1 */  jal   viShake
/* 0D14DC 7F09C9AC 00000000 */   nop   
/* 0D14E0 7F09C9B0 8FBF003C */  lw    $ra, 0x3c($sp)
.L7F09C9B4:
/* 0D14E4 7F09C9B4 D7B40018 */  ldc1  $f20, 0x18($sp)
/* 0D14E8 7F09C9B8 D7B60020 */  ldc1  $f22, 0x20($sp)
/* 0D14EC 7F09C9BC 8FB00028 */  lw    $s0, 0x28($sp)
/* 0D14F0 7F09C9C0 8FB1002C */  lw    $s1, 0x2c($sp)
/* 0D14F4 7F09C9C4 8FB20030 */  lw    $s2, 0x30($sp)
/* 0D14F8 7F09C9C8 8FB30034 */  lw    $s3, 0x34($sp)
/* 0D14FC 7F09C9CC 8FB40038 */  lw    $s4, 0x38($sp)
/* 0D1500 7F09C9D0 03E00008 */  jr    $ra
/* 0D1504 7F09C9D4 27BD0058 */   addiu $sp, $sp, 0x58
)
#endif

#ifndef VERSION_US
GLOBAL_ASM(
.late_rodata
glabel D_800576B8
.word 0x3f4ccccd /*0.80000001*/
.word 0x38d1b717
.text
glabel sub_GAME_7F09C7C4
/* 0D1EA8 7F09D338 27BDFF98 */  addiu $sp, $sp, -0x68
/* 0D1EAC 7F09D33C 3C0E8004 */  lui   $t6, %hi(numExplosionEntries) # $t6, 0x8004
/* 0D1EB0 7F09D340 8DCE01A0 */  lw    $t6, %lo(numExplosionEntries)($t6)
/* 0D1EB4 7F09D344 AFB20040 */  sw    $s2, 0x40($sp)
/* 0D1EB8 7F09D348 AFB1003C */  sw    $s1, 0x3c($sp)
/* 0D1EBC 7F09D34C 00808825 */  move  $s1, $a0
/* 0D1EC0 7F09D350 00A09025 */  move  $s2, $a1
/* 0D1EC4 7F09D354 AFBF004C */  sw    $ra, 0x4c($sp)
/* 0D1EC8 7F09D358 AFB40048 */  sw    $s4, 0x48($sp)
/* 0D1ECC 7F09D35C AFB30044 */  sw    $s3, 0x44($sp)
/* 0D1ED0 7F09D360 AFB00038 */  sw    $s0, 0x38($sp)
/* 0D1ED4 7F09D364 F7BA0030 */  sdc1  $f26, 0x30($sp)
/* 0D1ED8 7F09D368 F7B80028 */  sdc1  $f24, 0x28($sp)
/* 0D1EDC 7F09D36C F7B60020 */  sdc1  $f22, 0x20($sp)
/* 0D1EE0 7F09D370 F7B40018 */  sdc1  $f20, 0x18($sp)
/* 0D1EE4 7F09D374 15C00006 */  bnez  $t6, .Ljp7F09D390
/* 0D1EE8 7F09D378 AFA60070 */   sw    $a2, 0x70($sp)
/* 0D1EEC 7F09D37C 44806000 */  mtc1  $zero, $f12
/* 0D1EF0 7F09D380 0C000EC1 */  jal   viShake
/* 0D1EF4 7F09D384 00000000 */   nop   
/* 0D1EF8 7F09D388 10000071 */  b     .Ljp7F09D550
/* 0D1EFC 7F09D38C 8FBF004C */   lw    $ra, 0x4c($sp)
.Ljp7F09D390:
/* 0D1F00 7F09D390 3C018005 */  lui   $at, %hi(D_800576B8) # $at, 0x8005
/* 0D1F04 7F09D394 C43476E8 */  lwc1  $f20, %lo(D_800576B8)($at)
/* 0D1F08 7F09D398 0FC160F0 */  jal   cosf
/* 0D1F0C 7F09D39C 4600A306 */   mov.s $f12, $f20
/* 0D1F10 7F09D3A0 46000606 */  mov.s $f24, $f0
/* 0D1F14 7F09D3A4 0FC160F3 */  jal   sinf
/* 0D1F18 7F09D3A8 4600A306 */   mov.s $f12, $f20
/* 0D1F1C 7F09D3AC C6440000 */  lwc1  $f4, ($s2)
/* 0D1F20 7F09D3B0 C6480008 */  lwc1  $f8, 8($s2)
/* 0D1F24 7F09D3B4 4600A306 */  mov.s $f12, $f20
/* 0D1F28 7F09D3B8 4604C182 */  mul.s $f6, $f24, $f4
/* 0D1F2C 7F09D3BC 00000000 */  nop   
/* 0D1F30 7F09D3C0 46004282 */  mul.s $f10, $f8, $f0
/* 0D1F34 7F09D3C4 460A3401 */  sub.s $f16, $f6, $f10
/* 0D1F38 7F09D3C8 0FC160F3 */  jal   sinf
/* 0D1F3C 7F09D3CC E7B00054 */   swc1  $f16, 0x54($sp)
/* 0D1F40 7F09D3D0 46000606 */  mov.s $f24, $f0
/* 0D1F44 7F09D3D4 0FC160F0 */  jal   cosf
/* 0D1F48 7F09D3D8 4600A306 */   mov.s $f12, $f20
/* 0D1F4C 7F09D3DC C6520008 */  lwc1  $f18, 8($s2)
/* 0D1F50 7F09D3E0 C6480000 */  lwc1  $f8, ($s2)
/* 0D1F54 7F09D3E4 4480B000 */  mtc1  $zero, $f22
/* 0D1F58 7F09D3E8 46009102 */  mul.s $f4, $f18, $f0
/* 0D1F5C 7F09D3EC 3C014170 */  li    $at, 0x41700000 # 15.000000
/* 0D1F60 7F09D3F0 4481D000 */  mtc1  $at, $f26
/* 0D1F64 7F09D3F4 4608C182 */  mul.s $f6, $f24, $f8
/* 0D1F68 7F09D3F8 3C018005 */  lui   $at, %hi(D_800576B8+0x4) # $at, 0x8005
/* 0D1F6C 7F09D3FC 3C128004 */  lui   $s2, %hi(array_explosion_types) # $s2, 0x8004
/* 0D1F70 7F09D400 3C028008 */  lui   $v0, %hi(ptr_explosion_buf) # $v0, 0x8008
/* 0D1F74 7F09D404 3C138008 */  lui   $s3, %hi(ptr_explosion_buf) # $s3, 0x8008
/* 0D1F78 7F09D408 2673A1B4 */  addiu $s3, %lo(ptr_explosion_buf) # addiu $s3, $s3, -0x5e4c
/* 0D1F7C 7F09D40C 8C42A1B4 */  lw    $v0, %lo(ptr_explosion_buf)($v0)
/* 0D1F80 7F09D410 46062280 */  add.s $f10, $f4, $f6
/* 0D1F84 7F09D414 265202B4 */  addiu $s2, %lo(array_explosion_types) # addiu $s2, $s2, 0x2b4
/* 0D1F88 7F09D418 C43876EC */  lwc1  $f24, %lo(D_800576B8+0x4)($at)
/* 0D1F8C 7F09D41C 00008025 */  move  $s0, $zero
/* 0D1F90 7F09D420 E7AA0050 */  swc1  $f10, 0x50($sp)
/* 0D1F94 7F09D424 24141740 */  li    $s4, 5952
/* 0D1F98 7F09D428 4600B506 */  mov.s $f20, $f22
.Ljp7F09D42C:
/* 0D1F9C 7F09D42C 8C430000 */  lw    $v1, ($v0)
/* 0D1FA0 7F09D430 5060001F */  beql  $v1, $zero, .Ljp7F09D4B0
/* 0D1FA4 7F09D434 261003E0 */   addiu $s0, $s0, 0x3e0
/* 0D1FA8 7F09D438 C4700008 */  lwc1  $f16, 8($v1)
/* 0D1FAC 7F09D43C C6320000 */  lwc1  $f18, ($s1)
/* 0D1FB0 7F09D440 C468000C */  lwc1  $f8, 0xc($v1)
/* 0D1FB4 7F09D444 C6240004 */  lwc1  $f4, 4($s1)
/* 0D1FB8 7F09D448 46128001 */  sub.s $f0, $f16, $f18
/* 0D1FBC 7F09D44C C4660010 */  lwc1  $f6, 0x10($v1)
/* 0D1FC0 7F09D450 C62A0008 */  lwc1  $f10, 8($s1)
/* 0D1FC4 7F09D454 46044081 */  sub.s $f2, $f8, $f4
/* 0D1FC8 7F09D458 46000402 */  mul.s $f16, $f0, $f0
/* 0D1FCC 7F09D45C 460A3381 */  sub.s $f14, $f6, $f10
/* 0D1FD0 7F09D460 46021482 */  mul.s $f18, $f2, $f2
/* 0D1FD4 7F09D464 46128200 */  add.s $f8, $f16, $f18
/* 0D1FD8 7F09D468 460E7102 */  mul.s $f4, $f14, $f14
/* 0D1FDC 7F09D46C 0C007E08 */  jal   sqrtf
/* 0D1FE0 7F09D470 46044300 */   add.s $f12, $f8, $f4
/* 0D1FE4 7F09D474 46160032 */  c.eq.s $f0, $f22
/* 0D1FE8 7F09D478 46000086 */  mov.s $f2, $f0
/* 0D1FEC 7F09D47C 45020003 */  bc1fl .Ljp7F09D48C
/* 0D1FF0 7F09D480 8E6F0000 */   lw    $t7, ($s3)
/* 0D1FF4 7F09D484 4600C086 */  mov.s $f2, $f24
/* 0D1FF8 7F09D488 8E6F0000 */  lw    $t7, ($s3)
.Ljp7F09D48C:
/* 0D1FFC 7F09D48C 01F01021 */  addu  $v0, $t7, $s0
/* 0D2000 7F09D490 805803CC */  lb    $t8, 0x3cc($v0)
/* 0D2004 7F09D494 0018C980 */  sll   $t9, $t8, 6
/* 0D2008 7F09D498 02594021 */  addu  $t0, $s2, $t9
/* 0D200C 7F09D49C C5060010 */  lwc1  $f6, 0x10($t0)
/* 0D2010 7F09D4A0 46023003 */  div.s $f0, $f6, $f2
/* 0D2014 7F09D4A4 461A0282 */  mul.s $f10, $f0, $f26
/* 0D2018 7F09D4A8 460AA500 */  add.s $f20, $f20, $f10
/* 0D201C 7F09D4AC 261003E0 */  addiu $s0, $s0, 0x3e0
.Ljp7F09D4B0:
/* 0D2020 7F09D4B0 1614FFDE */  bne   $s0, $s4, .Ljp7F09D42C
/* 0D2024 7F09D4B4 244203E0 */   addiu $v0, $v0, 0x3e0
/* 0D2028 7F09D4B8 3C038004 */  lui   $v1, %hi(numSmokeEntries) # $v1, 0x8004
/* 0D202C 7F09D4BC 246301A4 */  addiu $v1, %lo(numSmokeEntries) # addiu $v1, $v1, 0x1a4
/* 0D2030 7F09D4C0 8C620000 */  lw    $v0, ($v1)
/* 0D2034 7F09D4C4 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0D2038 7F09D4C8 18400005 */  blez  $v0, .Ljp7F09D4E0
/* 0D203C 7F09D4CC 00000000 */   nop   
/* 0D2040 7F09D4D0 44818000 */  mtc1  $at, $f16
/* 0D2044 7F09D4D4 2449FFFF */  addiu $t1, $v0, -1
/* 0D2048 7F09D4D8 AC690000 */  sw    $t1, ($v1)
/* 0D204C 7F09D4DC 4610A500 */  add.s $f20, $f20, $f16
.Ljp7F09D4E0:
/* 0D2050 7F09D4E0 3C028004 */  lui   $v0, %hi(numExplosionEntries) # $v0, 0x8004
/* 0D2054 7F09D4E4 244201A0 */  addiu $v0, %lo(numExplosionEntries) # addiu $v0, $v0, 0x1a0
/* 0D2058 7F09D4E8 8C4A0000 */  lw    $t2, ($v0)
/* 0D205C 7F09D4EC 254BFFFF */  addiu $t3, $t2, -1
/* 0D2060 7F09D4F0 316D0002 */  andi  $t5, $t3, 2
/* 0D2064 7F09D4F4 11A00005 */  beqz  $t5, .Ljp7F09D50C
/* 0D2068 7F09D4F8 AC4B0000 */   sw    $t3, ($v0)
/* 0D206C 7F09D4FC 8FA30070 */  lw    $v1, 0x70($sp)
/* 0D2070 7F09D500 E4740004 */  swc1  $f20, 4($v1)
/* 0D2074 7F09D504 10000004 */  b     .Ljp7F09D518
/* 0D2078 7F09D508 4600A507 */   neg.s $f20, $f20
.Ljp7F09D50C:
/* 0D207C 7F09D50C 8FA30070 */  lw    $v1, 0x70($sp)
/* 0D2080 7F09D510 4600A487 */  neg.s $f18, $f20
/* 0D2084 7F09D514 E4720004 */  swc1  $f18, 4($v1)
.Ljp7F09D518:
/* 0D2088 7F09D518 C7A80054 */  lwc1  $f8, 0x54($sp)
/* 0D208C 7F09D51C 4608A102 */  mul.s $f4, $f20, $f8
/* 0D2090 7F09D520 E4640000 */  swc1  $f4, ($v1)
/* 0D2094 7F09D524 C7A60050 */  lwc1  $f6, 0x50($sp)
/* 0D2098 7F09D528 4606A282 */  mul.s $f10, $f20, $f6
/* 0D209C 7F09D52C E46A0008 */  swc1  $f10, 8($v1)
/* 0D20A0 7F09D530 8C4F0000 */  lw    $t7, ($v0)
/* 0D20A4 7F09D534 448F8000 */  mtc1  $t7, $f16
/* 0D20A8 7F09D538 00000000 */  nop   
/* 0D20AC 7F09D53C 468084A0 */  cvt.s.w $f18, $f16
/* 0D20B0 7F09D540 46149302 */  mul.s $f12, $f18, $f20
/* 0D20B4 7F09D544 0C000EC1 */  jal   viShake
/* 0D20B8 7F09D548 00000000 */   nop   
/* 0D20BC 7F09D54C 8FBF004C */  lw    $ra, 0x4c($sp)
.Ljp7F09D550:
/* 0D20C0 7F09D550 D7B40018 */  ldc1  $f20, 0x18($sp)
/* 0D20C4 7F09D554 D7B60020 */  ldc1  $f22, 0x20($sp)
/* 0D20C8 7F09D558 D7B80028 */  ldc1  $f24, 0x28($sp)
/* 0D20CC 7F09D55C D7BA0030 */  ldc1  $f26, 0x30($sp)
/* 0D20D0 7F09D560 8FB00038 */  lw    $s0, 0x38($sp)
/* 0D20D4 7F09D564 8FB1003C */  lw    $s1, 0x3c($sp)
/* 0D20D8 7F09D568 8FB20040 */  lw    $s2, 0x40($sp)
/* 0D20DC 7F09D56C 8FB30044 */  lw    $s3, 0x44($sp)
/* 0D20E0 7F09D570 8FB40048 */  lw    $s4, 0x48($sp)
/* 0D20E4 7F09D574 03E00008 */  jr    $ra
/* 0D20E8 7F09D578 27BD0068 */   addiu $sp, $sp, 0x68
)
#endif


#endif



#ifdef NONMATCHING
void sub_GAME_7F09C9D8(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F09C9D8
/* 0D1508 7F09C9D8 27BDFF00 */  addiu $sp, $sp, -0x100
/* 0D150C 7F09C9DC AFBF006C */  sw    $ra, 0x6c($sp)
/* 0D1510 7F09C9E0 AFB60068 */  sw    $s6, 0x68($sp)
/* 0D1514 7F09C9E4 AFB50064 */  sw    $s5, 0x64($sp)
/* 0D1518 7F09C9E8 AFB40060 */  sw    $s4, 0x60($sp)
/* 0D151C 7F09C9EC AFB3005C */  sw    $s3, 0x5c($sp)
/* 0D1520 7F09C9F0 AFB20058 */  sw    $s2, 0x58($sp)
/* 0D1524 7F09C9F4 AFB10054 */  sw    $s1, 0x54($sp)
/* 0D1528 7F09C9F8 AFB00050 */  sw    $s0, 0x50($sp)
/* 0D152C 7F09C9FC F7BE0048 */  sdc1  $f30, 0x48($sp)
/* 0D1530 7F09CA00 F7BC0040 */  sdc1  $f28, 0x40($sp)
/* 0D1534 7F09CA04 F7BA0038 */  sdc1  $f26, 0x38($sp)
/* 0D1538 7F09CA08 F7B80030 */  sdc1  $f24, 0x30($sp)
/* 0D153C 7F09CA0C F7B60028 */  sdc1  $f22, 0x28($sp)
/* 0D1540 7F09CA10 F7B40020 */  sdc1  $f20, 0x20($sp)
/* 0D1544 7F09CA14 AFA60108 */  sw    $a2, 0x108($sp)
/* 0D1548 7F09CA18 8C920004 */  lw    $s2, 4($a0)
/* 0D154C 7F09CA1C 3C188004 */  lui   $t8, %hi(array_explosion_types) 
/* 0D1550 7F09CA20 4485E000 */  mtc1  $a1, $f28
/* 0D1554 7F09CA24 824E03CC */  lb    $t6, 0x3cc($s2)
/* 0D1558 7F09CA28 865903C8 */  lh    $t9, 0x3c8($s2)
/* 0D155C 7F09CA2C 864803CA */  lh    $t0, 0x3ca($s2)
/* 0D1560 7F09CA30 27180284 */  addiu $t8, %lo(array_explosion_types) # addiu $t8, $t8, 0x284
/* 0D1564 7F09CA34 000E7980 */  sll   $t7, $t6, 6
/* 0D1568 7F09CA38 0328082A */  slt   $at, $t9, $t0
/* 0D156C 7F09CA3C 00808825 */  move  $s1, $a0
/* 0D1570 7F09CA40 14200119 */  bnez  $at, .L7F09CEA8
/* 0D1574 7F09CA44 01F8B021 */   addu  $s6, $t7, $t8
/* 0D1578 7F09CA48 27B000E0 */  addiu $s0, $sp, 0xe0
/* 0D157C 7F09CA4C 0FC0F2E3 */  jal   chraiGetPropRoomIds
/* 0D1580 7F09CA50 02002825 */   move  $a1, $s0
/* 0D1584 7F09CA54 0FC0F8FF */  jal   sub_GAME_7F03E3FC
/* 0D1588 7F09CA58 02002025 */   move  $a0, $s0
/* 0D158C 7F09CA5C 3C138007 */  lui   $s3, %hi(ptr_list_object_lookup_indices)
/* 0D1590 7F09CA60 8E739C30 */  lw    $s3, %lo(ptr_list_object_lookup_indices)($s3)
/* 0D1594 7F09CA64 24150003 */  li    $s5, 3
/* 0D1598 7F09CA68 86620000 */  lh    $v0, ($s3)
/* 0D159C 7F09CA6C 0442010A */  bltzl $v0, .L7F09CE98
/* 0D15A0 7F09CA70 86C9001C */   lh    $t1, 0x1c($s6)
/* 0D15A4 7F09CA74 4480F000 */  mtc1  $zero, $f30
/* 0D15A8 7F09CA78 24140001 */  li    $s4, 1
/* 0D15AC 7F09CA7C 00024880 */  sll   $t1, $v0, 2
.L7F09CA80:
/* 0D15B0 7F09CA80 01224823 */  subu  $t1, $t1, $v0
/* 0D15B4 7F09CA84 00094880 */  sll   $t1, $t1, 2
/* 0D15B8 7F09CA88 8E4B0004 */  lw    $t3, 4($s2)
/* 0D15BC 7F09CA8C 01224821 */  addu  $t1, $t1, $v0
/* 0D15C0 7F09CA90 3C0A8007 */  lui   $t2, %hi(pos_data_entry) 
/* 0D15C4 7F09CA94 254A9C38 */  addiu $t2, %lo(pos_data_entry) # addiu $t2, $t2, -0x63c8
/* 0D15C8 7F09CA98 00094880 */  sll   $t1, $t1, 2
/* 0D15CC 7F09CA9C 012A8021 */  addu  $s0, $t1, $t2
/* 0D15D0 7F09CAA0 520B00F9 */  beql  $s0, $t3, .L7F09CE88
/* 0D15D4 7F09CAA4 86620002 */   lh    $v0, 2($s3)
/* 0D15D8 7F09CAA8 860C0002 */  lh    $t4, 2($s0)
/* 0D15DC 7F09CAAC 558000F6 */  bnezl $t4, .L7F09CE88
/* 0D15E0 7F09CAB0 86620002 */   lh    $v0, 2($s3)
/* 0D15E4 7F09CAB4 92020000 */  lbu   $v0, ($s0)
/* 0D15E8 7F09CAB8 24010004 */  li    $at, 4
/* 0D15EC 7F09CABC 52820006 */  beql  $s4, $v0, .L7F09CAD8
/* 0D15F0 7F09CAC0 8E030004 */   lw    $v1, 4($s0)
/* 0D15F4 7F09CAC4 10410003 */  beq   $v0, $at, .L7F09CAD4
/* 0D15F8 7F09CAC8 24010002 */   li    $at, 2
/* 0D15FC 7F09CACC 1441006B */  bne   $v0, $at, .L7F09CC7C
/* 0D1600 7F09CAD0 00000000 */   nop   
.L7F09CAD4:
/* 0D1604 7F09CAD4 8E030004 */  lw    $v1, 4($s0)
.L7F09CAD8:
/* 0D1608 7F09CAD8 C6260008 */  lwc1  $f6, 8($s1)
/* 0D160C 7F09CADC C62A000C */  lwc1  $f10, 0xc($s1)
/* 0D1610 7F09CAE0 C4640058 */  lwc1  $f4, 0x58($v1)
/* 0D1614 7F09CAE4 C468005C */  lwc1  $f8, 0x5c($v1)
/* 0D1618 7F09CAE8 46062481 */  sub.s $f18, $f4, $f6
/* 0D161C 7F09CAEC C6260010 */  lwc1  $f6, 0x10($s1)
/* 0D1620 7F09CAF0 C4640060 */  lwc1  $f4, 0x60($v1)
/* 0D1624 7F09CAF4 460A4501 */  sub.s $f20, $f8, $f10
/* 0D1628 7F09CAF8 461C903E */  c.le.s $f18, $f28
/* 0D162C 7F09CAFC 46062581 */  sub.s $f22, $f4, $f6
/* 0D1630 7F09CB00 4500005C */  bc1f  .L7F09CC74
/* 0D1634 7F09CB04 00000000 */   nop   
/* 0D1638 7F09CB08 4600E007 */  neg.s $f0, $f28
/* 0D163C 7F09CB0C C7A80108 */  lwc1  $f8, 0x108($sp)
/* 0D1640 7F09CB10 4612003E */  c.le.s $f0, $f18
/* 0D1644 7F09CB14 00000000 */  nop   
/* 0D1648 7F09CB18 45000056 */  bc1f  .L7F09CC74
/* 0D164C 7F09CB1C 00000000 */   nop   
/* 0D1650 7F09CB20 4608A03E */  c.le.s $f20, $f8
/* 0D1654 7F09CB24 00000000 */  nop   
/* 0D1658 7F09CB28 45000052 */  bc1f  .L7F09CC74
/* 0D165C 7F09CB2C 00000000 */   nop   
/* 0D1660 7F09CB30 46004287 */  neg.s $f10, $f8
/* 0D1664 7F09CB34 4614503E */  c.le.s $f10, $f20
/* 0D1668 7F09CB38 00000000 */  nop   
/* 0D166C 7F09CB3C 4500004D */  bc1f  .L7F09CC74
/* 0D1670 7F09CB40 00000000 */   nop   
/* 0D1674 7F09CB44 461CB03E */  c.le.s $f22, $f28
/* 0D1678 7F09CB48 00000000 */  nop   
/* 0D167C 7F09CB4C 45000049 */  bc1f  .L7F09CC74
/* 0D1680 7F09CB50 00000000 */   nop   
/* 0D1684 7F09CB54 4616003E */  c.le.s $f0, $f22
/* 0D1688 7F09CB58 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0D168C 7F09CB5C 45000045 */  bc1f  .L7F09CC74
/* 0D1690 7F09CB60 00000000 */   nop   
/* 0D1694 7F09CB64 461C9083 */  div.s $f2, $f18, $f28
/* 0D1698 7F09CB68 C6DA003C */  lwc1  $f26, 0x3c($s6)
/* 0D169C 7F09CB6C 4608A383 */  div.s $f14, $f20, $f8
/* 0D16A0 7F09CB70 46001006 */  mov.s $f0, $f2
/* 0D16A4 7F09CB74 461E103C */  c.lt.s $f2, $f30
/* 0D16A8 7F09CB78 461CB603 */  div.s $f24, $f22, $f28
/* 0D16AC 7F09CB7C 4481B000 */  mtc1  $at, $f22
/* 0D16B0 7F09CB80 46007306 */  mov.s $f12, $f14
/* 0D16B4 7F09CB84 45000002 */  bc1f  .L7F09CB90
/* 0D16B8 7F09CB88 4600C406 */   mov.s $f16, $f24
/* 0D16BC 7F09CB8C 46001007 */  neg.s $f0, $f2
.L7F09CB90:
/* 0D16C0 7F09CB90 461E703C */  c.lt.s $f14, $f30
/* 0D16C4 7F09CB94 4600B501 */  sub.s $f20, $f22, $f0
/* 0D16C8 7F09CB98 45020003 */  bc1fl .L7F09CBA8
/* 0D16CC 7F09CB9C 461EC03C */   c.lt.s $f24, $f30
/* 0D16D0 7F09CBA0 46007307 */  neg.s $f12, $f14
/* 0D16D4 7F09CBA4 461EC03C */  c.lt.s $f24, $f30
.L7F09CBA8:
/* 0D16D8 7F09CBA8 460CB301 */  sub.s $f12, $f22, $f12
/* 0D16DC 7F09CBAC 45020003 */  bc1fl .L7F09CBBC
/* 0D16E0 7F09CBB0 4614603C */   c.lt.s $f12, $f20
/* 0D16E4 7F09CBB4 4600C407 */  neg.s $f16, $f24
/* 0D16E8 7F09CBB8 4614603C */  c.lt.s $f12, $f20
.L7F09CBBC:
/* 0D16EC 7F09CBBC 4610B401 */  sub.s $f16, $f22, $f16
/* 0D16F0 7F09CBC0 45020003 */  bc1fl .L7F09CBD0
/* 0D16F4 7F09CBC4 4614803C */   c.lt.s $f16, $f20
/* 0D16F8 7F09CBC8 46006506 */  mov.s $f20, $f12
/* 0D16FC 7F09CBCC 4614803C */  c.lt.s $f16, $f20
.L7F09CBD0:
/* 0D1700 7F09CBD0 00000000 */  nop   
/* 0D1704 7F09CBD4 45020003 */  bc1fl .L7F09CBE4
/* 0D1708 7F09CBD8 8C6D0064 */   lw    $t5, 0x64($v1)
/* 0D170C 7F09CBDC 46008506 */  mov.s $f20, $f16
/* 0D1710 7F09CBE0 8C6D0064 */  lw    $t5, 0x64($v1)
.L7F09CBE4:
/* 0D1714 7F09CBE4 461AA502 */  mul.s $f20, $f20, $f26
/* 0D1718 7F09CBE8 31AE1000 */  andi  $t6, $t5, 0x1000
/* 0D171C 7F09CBEC 15C00021 */  bnez  $t6, .L7F09CC74
/* 0D1720 7F09CBF0 00000000 */   nop   
/* 0D1724 7F09CBF4 8C6F000C */  lw    $t7, 0xc($v1)
/* 0D1728 7F09CBF8 3C010020 */  lui   $at, (0x00200400 >> 16) # lui $at, 0x20
/* 0D172C 7F09CBFC 34210400 */  ori   $at, (0x00200400 & 0xFFFF) # ori $at, $at, 0x400
/* 0D1730 7F09CC00 01E1C024 */  and   $t8, $t7, $at
/* 0D1734 7F09CC04 1700001B */  bnez  $t8, .L7F09CC74
/* 0D1738 7F09CC08 00000000 */   nop   
/* 0D173C 7F09CC0C 0C002914 */  jal   randomGetNext
/* 0D1740 7F09CC10 AFA300CC */   sw    $v1, 0xcc($sp)
/* 0D1744 7F09CC14 44822000 */  mtc1  $v0, $f4
/* 0D1748 7F09CC18 8FA300CC */  lw    $v1, 0xcc($sp)
/* 0D174C 7F09CC1C 02002025 */  move  $a0, $s0
/* 0D1750 7F09CC20 04410005 */  bgez  $v0, .L7F09CC38
/* 0D1754 7F09CC24 468021A0 */   cvt.s.w $f6, $f4
/* 0D1758 7F09CC28 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0D175C 7F09CC2C 44815000 */  mtc1  $at, $f10
/* 0D1760 7F09CC30 00000000 */  nop   
/* 0D1764 7F09CC34 460A3180 */  add.s $f6, $f6, $f10
.L7F09CC38:
/* 0D1768 7F09CC38 3C012F80 */  li    $at, 0x2F800000 # 0.000000
/* 0D176C 7F09CC3C 44814000 */  mtc1  $at, $f8
/* 0D1770 7F09CC40 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 0D1774 7F09CC44 44815000 */  mtc1  $at, $f10
/* 0D1778 7F09CC48 46083102 */  mul.s $f4, $f6, $f8
/* 0D177C 7F09CC4C 825903CE */  lb    $t9, 0x3ce($s2)
/* 0D1780 7F09CC50 24660058 */  addiu $a2, $v1, 0x58
/* 0D1784 7F09CC54 2407001D */  li    $a3, 29
/* 0D1788 7F09CC58 AFB90010 */  sw    $t9, 0x10($sp)
/* 0D178C 7F09CC5C 460A2182 */  mul.s $f6, $f4, $f10
/* 0D1790 7F09CC60 46163200 */  add.s $f8, $f6, $f22
/* 0D1794 7F09CC64 46144102 */  mul.s $f4, $f8, $f20
/* 0D1798 7F09CC68 44052000 */  mfc1  $a1, $f4
/* 0D179C 7F09CC6C 0FC137BF */  jal   sub_GAME_7F04DEFC
/* 0D17A0 7F09CC70 00000000 */   nop   
.L7F09CC74:
/* 0D17A4 7F09CC74 10000084 */  b     .L7F09CE88
/* 0D17A8 7F09CC78 86620002 */   lh    $v0, 2($s3)
.L7F09CC7C:
/* 0D17AC 7F09CC7C 12A20003 */  beq   $s5, $v0, .L7F09CC8C
/* 0D17B0 7F09CC80 24010006 */   li    $at, 6
/* 0D17B4 7F09CC84 54410080 */  bnel  $v0, $at, .L7F09CE88
/* 0D17B8 7F09CC88 86620002 */   lh    $v0, 2($s3)
.L7F09CC8C:
/* 0D17BC 7F09CC8C C60A0008 */  lwc1  $f10, 8($s0)
/* 0D17C0 7F09CC90 C6260008 */  lwc1  $f6, 8($s1)
/* 0D17C4 7F09CC94 C608000C */  lwc1  $f8, 0xc($s0)
/* 0D17C8 7F09CC98 C624000C */  lwc1  $f4, 0xc($s1)
/* 0D17CC 7F09CC9C 46065581 */  sub.s $f22, $f10, $f6
/* 0D17D0 7F09CCA0 C6260010 */  lwc1  $f6, 0x10($s1)
/* 0D17D4 7F09CCA4 C60A0010 */  lwc1  $f10, 0x10($s0)
/* 0D17D8 7F09CCA8 46044481 */  sub.s $f18, $f8, $f4
/* 0D17DC 7F09CCAC 461CB03E */  c.le.s $f22, $f28
/* 0D17E0 7F09CCB0 46065601 */  sub.s $f24, $f10, $f6
/* 0D17E4 7F09CCB4 45020074 */  bc1fl .L7F09CE88
/* 0D17E8 7F09CCB8 86620002 */   lh    $v0, 2($s3)
/* 0D17EC 7F09CCBC 4600E007 */  neg.s $f0, $f28
/* 0D17F0 7F09CCC0 C7A80108 */  lwc1  $f8, 0x108($sp)
/* 0D17F4 7F09CCC4 4616003E */  c.le.s $f0, $f22
/* 0D17F8 7F09CCC8 00000000 */  nop   
/* 0D17FC 7F09CCCC 4502006E */  bc1fl .L7F09CE88
/* 0D1800 7F09CCD0 86620002 */   lh    $v0, 2($s3)
/* 0D1804 7F09CCD4 4608903E */  c.le.s $f18, $f8
/* 0D1808 7F09CCD8 00000000 */  nop   
/* 0D180C 7F09CCDC 4502006A */  bc1fl .L7F09CE88
/* 0D1810 7F09CCE0 86620002 */   lh    $v0, 2($s3)
/* 0D1814 7F09CCE4 46004107 */  neg.s $f4, $f8
/* 0D1818 7F09CCE8 4612203E */  c.le.s $f4, $f18
/* 0D181C 7F09CCEC 00000000 */  nop   
/* 0D1820 7F09CCF0 45020065 */  bc1fl .L7F09CE88
/* 0D1824 7F09CCF4 86620002 */   lh    $v0, 2($s3)
/* 0D1828 7F09CCF8 461CC03E */  c.le.s $f24, $f28
/* 0D182C 7F09CCFC 00000000 */  nop   
/* 0D1830 7F09CD00 45020061 */  bc1fl .L7F09CE88
/* 0D1834 7F09CD04 86620002 */   lh    $v0, 2($s3)
/* 0D1838 7F09CD08 4618003E */  c.le.s $f0, $f24
/* 0D183C 7F09CD0C 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0D1840 7F09CD10 4502005D */  bc1fl .L7F09CE88
/* 0D1844 7F09CD14 86620002 */   lh    $v0, 2($s3)
/* 0D1848 7F09CD18 461CB083 */  div.s $f2, $f22, $f28
/* 0D184C 7F09CD1C C6DA003C */  lwc1  $f26, 0x3c($s6)
/* 0D1850 7F09CD20 26250008 */  addiu $a1, $s1, 8
/* 0D1854 7F09CD24 02803825 */  move  $a3, $s4
/* 0D1858 7F09CD28 46089383 */  div.s $f14, $f18, $f8
/* 0D185C 7F09CD2C 46001006 */  mov.s $f0, $f2
/* 0D1860 7F09CD30 461E103C */  c.lt.s $f2, $f30
/* 0D1864 7F09CD34 461CC503 */  div.s $f20, $f24, $f28
/* 0D1868 7F09CD38 46007306 */  mov.s $f12, $f14
/* 0D186C 7F09CD3C 45000002 */  bc1f  .L7F09CD48
/* 0D1870 7F09CD40 4600A406 */   mov.s $f16, $f20
/* 0D1874 7F09CD44 46001007 */  neg.s $f0, $f2
.L7F09CD48:
/* 0D1878 7F09CD48 461E703C */  c.lt.s $f14, $f30
/* 0D187C 7F09CD4C 44811000 */  mtc1  $at, $f2
/* 0D1880 7F09CD50 45020003 */  bc1fl .L7F09CD60
/* 0D1884 7F09CD54 461EA03C */   c.lt.s $f20, $f30
/* 0D1888 7F09CD58 46007307 */  neg.s $f12, $f14
/* 0D188C 7F09CD5C 461EA03C */  c.lt.s $f20, $f30
.L7F09CD60:
/* 0D1890 7F09CD60 460C1301 */  sub.s $f12, $f2, $f12
/* 0D1894 7F09CD64 45020003 */  bc1fl .L7F09CD74
/* 0D1898 7F09CD68 46001501 */   sub.s $f20, $f2, $f0
/* 0D189C 7F09CD6C 4600A407 */  neg.s $f16, $f20
/* 0D18A0 7F09CD70 46001501 */  sub.s $f20, $f2, $f0
.L7F09CD74:
/* 0D18A4 7F09CD74 46101401 */  sub.s $f16, $f2, $f16
/* 0D18A8 7F09CD78 4614603C */  c.lt.s $f12, $f20
/* 0D18AC 7F09CD7C 00000000 */  nop   
/* 0D18B0 7F09CD80 45020003 */  bc1fl .L7F09CD90
/* 0D18B4 7F09CD84 4614803C */   c.lt.s $f16, $f20
/* 0D18B8 7F09CD88 46006506 */  mov.s $f20, $f12
/* 0D18BC 7F09CD8C 4614803C */  c.lt.s $f16, $f20
.L7F09CD90:
/* 0D18C0 7F09CD90 00000000 */  nop   
/* 0D18C4 7F09CD94 45000002 */  bc1f  .L7F09CDA0
/* 0D18C8 7F09CD98 00000000 */   nop   
/* 0D18CC 7F09CD9C 46008506 */  mov.s $f20, $f16
.L7F09CDA0:
/* 0D18D0 7F09CDA0 4614A502 */  mul.s $f20, $f20, $f20
/* 0D18D4 7F09CDA4 00000000 */  nop   
/* 0D18D8 7F09CDA8 461AA502 */  mul.s $f20, $f20, $f26
/* 0D18DC 7F09CDAC 16A20006 */  bne   $s5, $v0, .L7F09CDC8
/* 0D18E0 7F09CDB0 00000000 */   nop   
/* 0D18E4 7F09CDB4 4406A000 */  mfc1  $a2, $f20
/* 0D18E8 7F09CDB8 0FC09E01 */  jal   chrlvExplosionDamage
/* 0D18EC 7F09CDBC 8E040004 */   lw    $a0, 4($s0)
/* 0D18F0 7F09CDC0 10000031 */  b     .L7F09CE88
/* 0D18F4 7F09CDC4 86620002 */   lh    $v0, 2($s3)
.L7F09CDC8:
/* 0D18F8 7F09CDC8 461EB032 */  c.eq.s $f22, $f30
/* 0D18FC 7F09CDCC 00000000 */  nop   
/* 0D1900 7F09CDD0 45000005 */  bc1f  .L7F09CDE8
/* 0D1904 7F09CDD4 00000000 */   nop   
/* 0D1908 7F09CDD8 461EC032 */  c.eq.s $f24, $f30
/* 0D190C 7F09CDDC 00000000 */  nop   
/* 0D1910 7F09CDE0 4501000E */  bc1t  .L7F09CE1C
/* 0D1914 7F09CDE4 00000000 */   nop   
.L7F09CDE8:
/* 0D1918 7F09CDE8 4616B282 */  mul.s $f10, $f22, $f22
/* 0D191C 7F09CDEC 00000000 */  nop   
/* 0D1920 7F09CDF0 4618C182 */  mul.s $f6, $f24, $f24
/* 0D1924 7F09CDF4 0C007DF8 */  jal   sqrtf
/* 0D1928 7F09CDF8 46065300 */   add.s $f12, $f10, $f6
/* 0D192C 7F09CDFC 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0D1930 7F09CE00 44812000 */  mtc1  $at, $f4
/* 0D1934 7F09CE04 00000000 */  nop   
/* 0D1938 7F09CE08 46002083 */  div.s $f2, $f4, $f0
/* 0D193C 7F09CE0C 4602B582 */  mul.s $f22, $f22, $f2
/* 0D1940 7F09CE10 00000000 */  nop   
/* 0D1944 7F09CE14 4602C602 */  mul.s $f24, $f24, $f2
/* 0D1948 7F09CE18 00000000 */  nop   
.L7F09CE1C:
/* 0D194C 7F09CE1C 0FC26C54 */  jal   get_cur_playernum
/* 0D1950 7F09CE20 00000000 */   nop   
/* 0D1954 7F09CE24 AFA20090 */  sw    $v0, 0x90($sp)
/* 0D1958 7F09CE28 0FC26C57 */  jal   sub_GAME_7F09B15C
/* 0D195C 7F09CE2C 02002025 */   move  $a0, $s0
/* 0D1960 7F09CE30 0FC26C43 */  jal   set_cur_player
/* 0D1964 7F09CE34 00402025 */   move  $a0, $v0
/* 0D1968 7F09CE38 0FC26919 */  jal   getPlayerCount
/* 0D196C 7F09CE3C 00000000 */   nop   
/* 0D1970 7F09CE40 14540004 */  bne   $v0, $s4, .L7F09CE54
/* 0D1974 7F09CE44 3C018004 */   lui   $at, %hi(D_80040178)
/* 0D1978 7F09CE48 C4280178 */  lwc1  $f8, %lo(D_80040178)($at)
/* 0D197C 7F09CE4C 4608A502 */  mul.s $f20, $f20, $f8
/* 0D1980 7F09CE50 00000000 */  nop   
.L7F09CE54:
/* 0D1984 7F09CE54 0FC1F39E */  jal   isBondInTank
/* 0D1988 7F09CE58 00000000 */   nop   
/* 0D198C 7F09CE5C 14540002 */  bne   $v0, $s4, .L7F09CE68
/* 0D1990 7F09CE60 4600B386 */   mov.s $f14, $f22
/* 0D1994 7F09CE64 4614A500 */  add.s $f20, $f20, $f20
.L7F09CE68:
/* 0D1998 7F09CE68 4406C000 */  mfc1  $a2, $f24
/* 0D199C 7F09CE6C 824703CE */  lb    $a3, 0x3ce($s2)
/* 0D19A0 7F09CE70 AFB40010 */  sw    $s4, 0x10($sp)
/* 0D19A4 7F09CE74 0FC22647 */  jal   record_damage_kills
/* 0D19A8 7F09CE78 4600A306 */   mov.s $f12, $f20
/* 0D19AC 7F09CE7C 0FC26C43 */  jal   set_cur_player
/* 0D19B0 7F09CE80 8FA40090 */   lw    $a0, 0x90($sp)
/* 0D19B4 7F09CE84 86620002 */  lh    $v0, 2($s3)
.L7F09CE88:
/* 0D19B8 7F09CE88 26730002 */  addiu $s3, $s3, 2
/* 0D19BC 7F09CE8C 0443FEFC */  bgezl $v0, .L7F09CA80
/* 0D19C0 7F09CE90 00024880 */   sll   $t1, $v0, 2
/* 0D19C4 7F09CE94 86C9001C */  lh    $t1, 0x1c($s6)
.L7F09CE98:
/* 0D19C8 7F09CE98 864803C8 */  lh    $t0, 0x3c8($s2)
/* 0D19CC 7F09CE9C 00095083 */  sra   $t2, $t1, 2
/* 0D19D0 7F09CEA0 010A5821 */  addu  $t3, $t0, $t2
/* 0D19D4 7F09CEA4 A64B03CA */  sh    $t3, 0x3ca($s2)
.L7F09CEA8:
/* 0D19D8 7F09CEA8 8FBF006C */  lw    $ra, 0x6c($sp)
/* 0D19DC 7F09CEAC D7B40020 */  ldc1  $f20, 0x20($sp)
/* 0D19E0 7F09CEB0 D7B60028 */  ldc1  $f22, 0x28($sp)
/* 0D19E4 7F09CEB4 D7B80030 */  ldc1  $f24, 0x30($sp)
/* 0D19E8 7F09CEB8 D7BA0038 */  ldc1  $f26, 0x38($sp)
/* 0D19EC 7F09CEBC D7BC0040 */  ldc1  $f28, 0x40($sp)
/* 0D19F0 7F09CEC0 D7BE0048 */  ldc1  $f30, 0x48($sp)
/* 0D19F4 7F09CEC4 8FB00050 */  lw    $s0, 0x50($sp)
/* 0D19F8 7F09CEC8 8FB10054 */  lw    $s1, 0x54($sp)
/* 0D19FC 7F09CECC 8FB20058 */  lw    $s2, 0x58($sp)
/* 0D1A00 7F09CED0 8FB3005C */  lw    $s3, 0x5c($sp)
/* 0D1A04 7F09CED4 8FB40060 */  lw    $s4, 0x60($sp)
/* 0D1A08 7F09CED8 8FB50064 */  lw    $s5, 0x64($sp)
/* 0D1A0C 7F09CEDC 8FB60068 */  lw    $s6, 0x68($sp)
/* 0D1A10 7F09CEE0 03E00008 */  jr    $ra
/* 0D1A14 7F09CEE4 27BD0100 */   addiu $sp, $sp, 0x100
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F09CEE8(void) {

}
#else
GLOBAL_ASM(
.late_rodata
glabel D_800576BC
.word 0x40c90fdb /*6.2831855*/
.text
glabel sub_GAME_7F09CEE8
/* 0D1A18 7F09CEE8 27BDFF38 */  addiu $sp, $sp, -0xc8
/* 0D1A1C 7F09CEEC AFBF006C */  sw    $ra, 0x6c($sp)
/* 0D1A20 7F09CEF0 AFB70068 */  sw    $s7, 0x68($sp)
/* 0D1A24 7F09CEF4 AFB60064 */  sw    $s6, 0x64($sp)
/* 0D1A28 7F09CEF8 AFB50060 */  sw    $s5, 0x60($sp)
/* 0D1A2C 7F09CEFC AFB4005C */  sw    $s4, 0x5c($sp)
/* 0D1A30 7F09CF00 AFB30058 */  sw    $s3, 0x58($sp)
/* 0D1A34 7F09CF04 AFB20054 */  sw    $s2, 0x54($sp)
/* 0D1A38 7F09CF08 AFB10050 */  sw    $s1, 0x50($sp)
/* 0D1A3C 7F09CF0C AFB0004C */  sw    $s0, 0x4c($sp)
/* 0D1A40 7F09CF10 F7BE0040 */  sdc1  $f30, 0x40($sp)
/* 0D1A44 7F09CF14 F7BC0038 */  sdc1  $f28, 0x38($sp)
/* 0D1A48 7F09CF18 F7BA0030 */  sdc1  $f26, 0x30($sp)
/* 0D1A4C 7F09CF1C F7B80028 */  sdc1  $f24, 0x28($sp)
/* 0D1A50 7F09CF20 F7B60020 */  sdc1  $f22, 0x20($sp)
/* 0D1A54 7F09CF24 F7B40018 */  sdc1  $f20, 0x18($sp)
/* 0D1A58 7F09CF28 8C920004 */  lw    $s2, 4($a0)
/* 0D1A5C 7F09CF2C 3C028005 */  lui   $v0, %hi(g_ClockTimer)
/* 0D1A60 7F09CF30 8C428374 */  lw    $v0, %lo(g_ClockTimer)($v0)
/* 0D1A64 7F09CF34 824503CC */  lb    $a1, 0x3cc($s2)
/* 0D1A68 7F09CF38 3C0F8004 */  lui   $t7, %hi(array_explosion_types) 
/* 0D1A6C 7F09CF3C 25EF0284 */  addiu $t7, %lo(array_explosion_types) # addiu $t7, $t7, 0x284
/* 0D1A70 7F09CF40 00057180 */  sll   $t6, $a1, 6
/* 0D1A74 7F09CF44 00809825 */  move  $s3, $a0
/* 0D1A78 7F09CF48 14400003 */  bnez  $v0, .L7F09CF58
/* 0D1A7C 7F09CF4C 01CFA821 */   addu  $s5, $t6, $t7
/* 0D1A80 7F09CF50 10000155 */  b     .L7F09D4A8
/* 0D1A84 7F09CF54 00001025 */   move  $v0, $zero
.L7F09CF58:
/* 0D1A88 7F09CF58 2841000F */  slti  $at, $v0, 0xf
/* 0D1A8C 7F09CF5C 50200007 */  beql  $at, $zero, .L7F09CF7C
/* 0D1A90 7F09CF60 3C014170 */   lui   $at, 0x4170
/* 0D1A94 7F09CF64 44822000 */  mtc1  $v0, $f4
/* 0D1A98 7F09CF68 00000000 */  nop   
/* 0D1A9C 7F09CF6C 468021A0 */  cvt.s.w $f6, $f4
/* 0D1AA0 7F09CF70 10000005 */  b     .L7F09CF88
/* 0D1AA4 7F09CF74 E7A600A0 */   swc1  $f6, 0xa0($sp)
/* 0D1AA8 7F09CF78 3C014170 */  li    $at, 0x41700000 # 15.000000
.L7F09CF7C:
/* 0D1AAC 7F09CF7C 44814000 */  mtc1  $at, $f8
/* 0D1AB0 7F09CF80 00000000 */  nop   
/* 0D1AB4 7F09CF84 E7A800A0 */  swc1  $f8, 0xa0($sp)
.L7F09CF88:
/* 0D1AB8 7F09CF88 864303C8 */  lh    $v1, 0x3c8($s2)
/* 0D1ABC 7F09CF8C 28610008 */  slti  $at, $v1, 8
/* 0D1AC0 7F09CF90 542000D5 */  bnezl $at, .L7F09D2E8
/* 0D1AC4 7F09CF94 C7AA00A0 */   lwc1  $f10, 0xa0($sp)
/* 0D1AC8 7F09CF98 86A2001C */  lh    $v0, 0x1c($s5)
/* 0D1ACC 7F09CF9C 0062082A */  slt   $at, $v1, $v0
/* 0D1AD0 7F09CFA0 502000D1 */  beql  $at, $zero, .L7F09D2E8
/* 0D1AD4 7F09CFA4 C7AA00A0 */   lwc1  $f10, 0xa0($sp)
/* 0D1AD8 7F09CFA8 44835000 */  mtc1  $v1, $f10
/* 0D1ADC 7F09CFAC C6B20008 */  lwc1  $f18, 8($s5)
/* 0D1AE0 7F09CFB0 C6A8000C */  lwc1  $f8, 0xc($s5)
/* 0D1AE4 7F09CFB4 46805020 */  cvt.s.w $f0, $f10
/* 0D1AE8 7F09CFB8 C6B00000 */  lwc1  $f16, ($s5)
/* 0D1AEC 7F09CFBC C6A60004 */  lwc1  $f6, 4($s5)
/* 0D1AF0 7F09CFC0 2417000E */  li    $s7, 14
/* 0D1AF4 7F09CFC4 28610020 */  slti  $at, $v1, 0x20
/* 0D1AF8 7F09CFC8 24160001 */  li    $s6, 1
/* 0D1AFC 7F09CFCC 46009102 */  mul.s $f4, $f18, $f0
/* 0D1B00 7F09CFD0 00000000 */  nop   
/* 0D1B04 7F09CFD4 46004282 */  mul.s $f10, $f8, $f0
/* 0D1B08 7F09CFD8 46048700 */  add.s $f28, $f16, $f4
/* 0D1B0C 7F09CFDC 16E5001F */  bne   $s7, $a1, .L7F09D05C
/* 0D1B10 7F09CFE0 460A3780 */   add.s $f30, $f6, $f10
/* 0D1B14 7F09CFE4 1020000C */  beqz  $at, .L7F09D018
/* 0D1B18 7F09CFE8 C7B000A0 */   lwc1  $f16, 0xa0($sp)
/* 0D1B1C 7F09CFEC 3C014120 */  li    $at, 0x41200000 # 10.000000
/* 0D1B20 7F09CFF0 44819000 */  mtc1  $at, $f18
/* 0D1B24 7F09CFF4 C668000C */  lwc1  $f8, 0xc($s3)
/* 0D1B28 7F09CFF8 46109102 */  mul.s $f4, $f18, $f16
/* 0D1B2C 7F09CFFC 46044180 */  add.s $f6, $f8, $f4
/* 0D1B30 7F09D000 E666000C */  swc1  $f6, 0xc($s3)
/* 0D1B34 7F09D004 864303C8 */  lh    $v1, 0x3c8($s2)
/* 0D1B38 7F09D008 86A2001C */  lh    $v0, 0x1c($s5)
/* 0D1B3C 7F09D00C 44835000 */  mtc1  $v1, $f10
/* 0D1B40 7F09D010 00000000 */  nop   
/* 0D1B44 7F09D014 46805020 */  cvt.s.w $f0, $f10
.L7F09D018:
/* 0D1B48 7F09D018 28610021 */  slti  $at, $v1, 0x21
/* 0D1B4C 7F09D01C 1420000F */  bnez  $at, .L7F09D05C
/* 0D1B50 7F09D020 3C014396 */   li    $at, 0x43960000 # 300.000000
/* 0D1B54 7F09D024 44811000 */  mtc1  $at, $f2
/* 0D1B58 7F09D028 3C014040 */  li    $at, 0x40400000 # 3.000000
/* 0D1B5C 7F09D02C 44819000 */  mtc1  $at, $f18
/* 0D1B60 7F09D030 3C014220 */  li    $at, 0x42200000 # 40.000000
/* 0D1B64 7F09D034 44814000 */  mtc1  $at, $f8
/* 0D1B68 7F09D038 46120402 */  mul.s $f16, $f0, $f18
/* 0D1B6C 7F09D03C 3C0141A0 */  li    $at, 0x41A00000 # 20.000000
/* 0D1B70 7F09D040 4481F000 */  mtc1  $at, $f30
/* 0D1B74 7F09D044 46088700 */  add.s $f28, $f16, $f8
/* 0D1B78 7F09D048 461C103C */  c.lt.s $f2, $f28
/* 0D1B7C 7F09D04C 00000000 */  nop   
/* 0D1B80 7F09D050 45000002 */  bc1f  .L7F09D05C
/* 0D1B84 7F09D054 00000000 */   nop   
/* 0D1B88 7F09D058 46001706 */  mov.s $f28, $f2
.L7F09D05C:
/* 0D1B8C 7F09D05C 86B8001E */  lh    $t8, 0x1e($s5)
/* 0D1B90 7F09D060 44829000 */  mtc1  $v0, $f18
/* 0D1B94 7F09D064 0000A025 */  move  $s4, $zero
/* 0D1B98 7F09D068 44982000 */  mtc1  $t8, $f4
/* 0D1B9C 7F09D06C 46809420 */  cvt.s.w $f16, $f18
/* 0D1BA0 7F09D070 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 0D1BA4 7F09D074 468021A0 */  cvt.s.w $f6, $f4
/* 0D1BA8 7F09D078 46003282 */  mul.s $f10, $f6, $f0
/* 0D1BAC 7F09D07C 46105203 */  div.s $f8, $f10, $f16
/* 0D1BB0 7F09D080 4600410D */  trunc.w.s $f4, $f8
/* 0D1BB4 7F09D084 44082000 */  mfc1  $t0, $f4
/* 0D1BB8 7F09D088 00000000 */  nop   
/* 0D1BBC 7F09D08C 25090001 */  addiu $t1, $t0, 1
/* 0D1BC0 7F09D090 19200061 */  blez  $t1, .L7F09D218
/* 0D1BC4 7F09D094 AFA9009C */   sw    $t1, 0x9c($sp)
/* 0D1BC8 7F09D098 4481D000 */  mtc1  $at, $f26
/* 0D1BCC 7F09D09C 3C012F80 */  li    $at, 0x2F800000 # 0.000000
/* 0D1BD0 7F09D0A0 4481B000 */  mtc1  $at, $f22
/* 0D1BD4 7F09D0A4 241103C0 */  li    $s1, 960
/* 0D1BD8 7F09D0A8 00001025 */  move  $v0, $zero
.L7F09D0AC:
/* 0D1BDC 7F09D0AC 02408025 */  move  $s0, $s2
.L7F09D0B0:
/* 0D1BE0 7F09D0B0 860A001C */  lh    $t2, 0x1c($s0)
/* 0D1BE4 7F09D0B4 24420018 */  addiu $v0, $v0, 0x18
/* 0D1BE8 7F09D0B8 15400051 */  bnez  $t2, .L7F09D200
/* 0D1BEC 7F09D0BC 00000000 */   nop   
/* 0D1BF0 7F09D0C0 0C002914 */  jal   randomGetNext
/* 0D1BF4 7F09D0C4 A616001C */   sh    $s6, 0x1c($s0)
/* 0D1BF8 7F09D0C8 44823000 */  mtc1  $v0, $f6
/* 0D1BFC 7F09D0CC 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0D1C00 7F09D0D0 04410004 */  bgez  $v0, .L7F09D0E4
/* 0D1C04 7F09D0D4 468034A0 */   cvt.s.w $f18, $f6
/* 0D1C08 7F09D0D8 44815000 */  mtc1  $at, $f10
/* 0D1C0C 7F09D0DC 00000000 */  nop   
/* 0D1C10 7F09D0E0 460A9480 */  add.s $f18, $f18, $f10
.L7F09D0E4:
/* 0D1C14 7F09D0E4 46169402 */  mul.s $f16, $f18, $f22
/* 0D1C18 7F09D0E8 C6660008 */  lwc1  $f6, 8($s3)
/* 0D1C1C 7F09D0EC 461A8201 */  sub.s $f8, $f16, $f26
/* 0D1C20 7F09D0F0 461C4102 */  mul.s $f4, $f8, $f28
/* 0D1C24 7F09D0F4 46062280 */  add.s $f10, $f4, $f6
/* 0D1C28 7F09D0F8 0C002914 */  jal   randomGetNext
/* 0D1C2C 7F09D0FC E60A0008 */   swc1  $f10, 8($s0)
/* 0D1C30 7F09D100 44829000 */  mtc1  $v0, $f18
/* 0D1C34 7F09D104 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0D1C38 7F09D108 04410004 */  bgez  $v0, .L7F09D11C
/* 0D1C3C 7F09D10C 46809420 */   cvt.s.w $f16, $f18
/* 0D1C40 7F09D110 44814000 */  mtc1  $at, $f8
/* 0D1C44 7F09D114 00000000 */  nop   
/* 0D1C48 7F09D118 46088400 */  add.s $f16, $f16, $f8
.L7F09D11C:
/* 0D1C4C 7F09D11C 46168102 */  mul.s $f4, $f16, $f22
/* 0D1C50 7F09D120 C672000C */  lwc1  $f18, 0xc($s3)
/* 0D1C54 7F09D124 461A2181 */  sub.s $f6, $f4, $f26
/* 0D1C58 7F09D128 461E3282 */  mul.s $f10, $f6, $f30
/* 0D1C5C 7F09D12C 46125200 */  add.s $f8, $f10, $f18
/* 0D1C60 7F09D130 0C002914 */  jal   randomGetNext
/* 0D1C64 7F09D134 E608000C */   swc1  $f8, 0xc($s0)
/* 0D1C68 7F09D138 44828000 */  mtc1  $v0, $f16
/* 0D1C6C 7F09D13C 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0D1C70 7F09D140 04410004 */  bgez  $v0, .L7F09D154
/* 0D1C74 7F09D144 46808120 */   cvt.s.w $f4, $f16
/* 0D1C78 7F09D148 44813000 */  mtc1  $at, $f6
/* 0D1C7C 7F09D14C 00000000 */  nop   
/* 0D1C80 7F09D150 46062100 */  add.s $f4, $f4, $f6
.L7F09D154:
/* 0D1C84 7F09D154 46162282 */  mul.s $f10, $f4, $f22
/* 0D1C88 7F09D158 C6700010 */  lwc1  $f16, 0x10($s3)
/* 0D1C8C 7F09D15C 461A5481 */  sub.s $f18, $f10, $f26
/* 0D1C90 7F09D160 461C9202 */  mul.s $f8, $f18, $f28
/* 0D1C94 7F09D164 46104180 */  add.s $f6, $f8, $f16
/* 0D1C98 7F09D168 0C002914 */  jal   randomGetNext
/* 0D1C9C 7F09D16C E6060010 */   swc1  $f6, 0x10($s0)
/* 0D1CA0 7F09D170 44822000 */  mtc1  $v0, $f4
/* 0D1CA4 7F09D174 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0D1CA8 7F09D178 04410004 */  bgez  $v0, .L7F09D18C
/* 0D1CAC 7F09D17C 468022A0 */   cvt.s.w $f10, $f4
/* 0D1CB0 7F09D180 44819000 */  mtc1  $at, $f18
/* 0D1CB4 7F09D184 00000000 */  nop   
/* 0D1CB8 7F09D188 46125280 */  add.s $f10, $f10, $f18
.L7F09D18C:
/* 0D1CBC 7F09D18C 46165202 */  mul.s $f8, $f10, $f22
/* 0D1CC0 7F09D190 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0D1CC4 7F09D194 44813000 */  mtc1  $at, $f6
/* 0D1CC8 7F09D198 C6B20010 */  lwc1  $f18, 0x10($s5)
/* 0D1CCC 7F09D19C 461A4402 */  mul.s $f16, $f8, $f26
/* 0D1CD0 7F09D1A0 46068100 */  add.s $f4, $f16, $f6
/* 0D1CD4 7F09D1A4 46122502 */  mul.s $f20, $f4, $f18
/* 0D1CD8 7F09D1A8 0C002914 */  jal   randomGetNext
/* 0D1CDC 7F09D1AC 00000000 */   nop   
/* 0D1CE0 7F09D1B0 44825000 */  mtc1  $v0, $f10
/* 0D1CE4 7F09D1B4 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0D1CE8 7F09D1B8 04410004 */  bgez  $v0, .L7F09D1CC
/* 0D1CEC 7F09D1BC 46805220 */   cvt.s.w $f8, $f10
/* 0D1CF0 7F09D1C0 44818000 */  mtc1  $at, $f16
/* 0D1CF4 7F09D1C4 00000000 */  nop   
/* 0D1CF8 7F09D1C8 46104200 */  add.s $f8, $f8, $f16
.L7F09D1CC:
/* 0D1CFC 7F09D1CC 46164182 */  mul.s $f6, $f8, $f22
/* 0D1D00 7F09D1D0 3C018005 */  lui   $at, %hi(D_800576BC)
/* 0D1D04 7F09D1D4 C42476BC */  lwc1  $f4, %lo(D_800576BC)($at)
/* 0D1D08 7F09D1D8 46043302 */  mul.s $f12, $f6, $f4
/* 0D1D0C 7F09D1DC 0FC15FA8 */  jal   cosf
/* 0D1D10 7F09D1E0 46006606 */   mov.s $f24, $f12
/* 0D1D14 7F09D1E4 46140482 */  mul.s $f18, $f0, $f20
/* 0D1D18 7F09D1E8 4600C306 */  mov.s $f12, $f24
/* 0D1D1C 7F09D1EC 0FC15FAB */  jal   sinf
/* 0D1D20 7F09D1F0 E6120014 */   swc1  $f18, 0x14($s0)
/* 0D1D24 7F09D1F4 46140282 */  mul.s $f10, $f0, $f20
/* 0D1D28 7F09D1F8 10000003 */  b     .L7F09D208
/* 0D1D2C 7F09D1FC E60A0018 */   swc1  $f10, 0x18($s0)
.L7F09D200:
/* 0D1D30 7F09D200 1451FFAB */  bne   $v0, $s1, .L7F09D0B0
/* 0D1D34 7F09D204 26100018 */   addiu $s0, $s0, 0x18
.L7F09D208:
/* 0D1D38 7F09D208 8FAB009C */  lw    $t3, 0x9c($sp)
/* 0D1D3C 7F09D20C 26940001 */  addiu $s4, $s4, 1
/* 0D1D40 7F09D210 568BFFA6 */  bnel  $s4, $t3, .L7F09D0AC
/* 0D1D44 7F09D214 00001025 */   move  $v0, $zero
.L7F09D218:
/* 0D1D48 7F09D218 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 0D1D4C 7F09D21C 4481D000 */  mtc1  $at, $f26
/* 0D1D50 7F09D220 3C013FC0 */  li    $at, 0x3FC00000 # 1.500000
/* 0D1D54 7F09D224 44814000 */  mtc1  $at, $f8
/* 0D1D58 7F09D228 C6B00010 */  lwc1  $f16, 0x10($s5)
/* 0D1D5C 7F09D22C C6720008 */  lwc1  $f18, 8($s3)
/* 0D1D60 7F09D230 02602025 */  move  $a0, $s3
/* 0D1D64 7F09D234 46088002 */  mul.s $f0, $f16, $f8
/* 0D1D68 7F09D238 27A50090 */  addiu $a1, $sp, 0x90
/* 0D1D6C 7F09D23C 27A60084 */  addiu $a2, $sp, 0x84
/* 0D1D70 7F09D240 461AE182 */  mul.s $f6, $f28, $f26
/* 0D1D74 7F09D244 46003700 */  add.s $f28, $f6, $f0
/* 0D1D78 7F09D248 461AF102 */  mul.s $f4, $f30, $f26
/* 0D1D7C 7F09D24C 4407E000 */  mfc1  $a3, $f28
/* 0D1D80 7F09D250 461C9281 */  sub.s $f10, $f18, $f28
/* 0D1D84 7F09D254 46002780 */  add.s $f30, $f4, $f0
/* 0D1D88 7F09D258 E7AA0090 */  swc1  $f10, 0x90($sp)
/* 0D1D8C 7F09D25C C670000C */  lwc1  $f16, 0xc($s3)
/* 0D1D90 7F09D260 461E8201 */  sub.s $f8, $f16, $f30
/* 0D1D94 7F09D264 E7A80094 */  swc1  $f8, 0x94($sp)
/* 0D1D98 7F09D268 C6660010 */  lwc1  $f6, 0x10($s3)
/* 0D1D9C 7F09D26C 461C3101 */  sub.s $f4, $f6, $f28
/* 0D1DA0 7F09D270 E7A40098 */  swc1  $f4, 0x98($sp)
/* 0D1DA4 7F09D274 C6720008 */  lwc1  $f18, 8($s3)
/* 0D1DA8 7F09D278 461C9280 */  add.s $f10, $f18, $f28
/* 0D1DAC 7F09D27C E7AA0084 */  swc1  $f10, 0x84($sp)
/* 0D1DB0 7F09D280 C670000C */  lwc1  $f16, 0xc($s3)
/* 0D1DB4 7F09D284 461E8200 */  add.s $f8, $f16, $f30
/* 0D1DB8 7F09D288 E7A80088 */  swc1  $f8, 0x88($sp)
/* 0D1DBC 7F09D28C C6660010 */  lwc1  $f6, 0x10($s3)
/* 0D1DC0 7F09D290 461C3100 */  add.s $f4, $f6, $f28
/* 0D1DC4 7F09D294 0FC0F89F */  jal   sub_GAME_7F03E27C
/* 0D1DC8 7F09D298 E7A4008C */   swc1  $f4, 0x8c($sp)
/* 0D1DCC 7F09D29C 864C03C8 */  lh    $t4, 0x3c8($s2)
/* 0D1DD0 7F09D2A0 C6A00014 */  lwc1  $f0, 0x14($s5)
/* 0D1DD4 7F09D2A4 C6B20018 */  lwc1  $f18, 0x18($s5)
/* 0D1DD8 7F09D2A8 448C8000 */  mtc1  $t4, $f16
/* 0D1DDC 7F09D2AC 86AD001C */  lh    $t5, 0x1c($s5)
/* 0D1DE0 7F09D2B0 46009281 */  sub.s $f10, $f18, $f0
/* 0D1DE4 7F09D2B4 02602025 */  move  $a0, $s3
/* 0D1DE8 7F09D2B8 448D2000 */  mtc1  $t5, $f4
/* 0D1DEC 7F09D2BC 46808220 */  cvt.s.w $f8, $f16
/* 0D1DF0 7F09D2C0 468024A0 */  cvt.s.w $f18, $f4
/* 0D1DF4 7F09D2C4 46085182 */  mul.s $f6, $f10, $f8
/* 0D1DF8 7F09D2C8 46123403 */  div.s $f16, $f6, $f18
/* 0D1DFC 7F09D2CC 46100780 */  add.s $f30, $f0, $f16
/* 0D1E00 7F09D2D0 4405F000 */  mfc1  $a1, $f30
/* 0D1E04 7F09D2D4 4406F000 */  mfc1  $a2, $f30
/* 0D1E08 7F09D2D8 0FC27276 */  jal   sub_GAME_7F09C9D8
/* 0D1E0C 7F09D2DC 00000000 */   nop   
/* 0D1E10 7F09D2E0 864303C8 */  lh    $v1, 0x3c8($s2)
/* 0D1E14 7F09D2E4 C7AA00A0 */  lwc1  $f10, 0xa0($sp)
.L7F09D2E8:
/* 0D1E18 7F09D2E8 24160001 */  li    $s6, 1
/* 0D1E1C 7F09D2EC 2417000E */  li    $s7, 14
/* 0D1E20 7F09D2F0 4600520D */  trunc.w.s $f8, $f10
/* 0D1E24 7F09D2F4 0000A025 */  move  $s4, $zero
/* 0D1E28 7F09D2F8 3C014080 */  li    $at, 0x40800000 # 4.000000
/* 0D1E2C 7F09D2FC 440F4000 */  mfc1  $t7, $f8
/* 0D1E30 7F09D300 00000000 */  nop   
/* 0D1E34 7F09D304 19E00058 */  blez  $t7, .L7F09D468
/* 0D1E38 7F09D308 AFAF0070 */   sw    $t7, 0x70($sp)
/* 0D1E3C 7F09D30C 4481A000 */  mtc1  $at, $f20
/* 0D1E40 7F09D310 241103C0 */  li    $s1, 960
/* 0D1E44 7F09D314 24780001 */  addiu $t8, $v1, 1
.L7F09D318:
/* 0D1E48 7F09D318 A65803C8 */  sh    $t8, 0x3c8($s2)
/* 0D1E4C 7F09D31C 00001025 */  move  $v0, $zero
/* 0D1E50 7F09D320 02408025 */  move  $s0, $s2
.L7F09D324:
/* 0D1E54 7F09D324 8603001C */  lh    $v1, 0x1c($s0)
/* 0D1E58 7F09D328 24420018 */  addiu $v0, $v0, 0x18
/* 0D1E5C 7F09D32C 18600002 */  blez  $v1, .L7F09D338
/* 0D1E60 7F09D330 24790001 */   addiu $t9, $v1, 1
/* 0D1E64 7F09D334 A619001C */  sh    $t9, 0x1c($s0)
.L7F09D338:
/* 0D1E68 7F09D338 1451FFFA */  bne   $v0, $s1, .L7F09D324
/* 0D1E6C 7F09D33C 26100018 */   addiu $s0, $s0, 0x18
/* 0D1E70 7F09D340 864303C8 */  lh    $v1, 0x3c8($s2)
/* 0D1E74 7F09D344 2401000F */  li    $at, 15
/* 0D1E78 7F09D348 54610005 */  bnel  $v1, $at, .L7F09D360
/* 0D1E7C 7F09D34C 86A2001C */   lh    $v0, 0x1c($s5)
/* 0D1E80 7F09D350 824803CC */  lb    $t0, 0x3cc($s2)
/* 0D1E84 7F09D354 52E80009 */  beql  $s7, $t0, .L7F09D37C
/* 0D1E88 7F09D358 8E420004 */   lw    $v0, 4($s2)
/* 0D1E8C 7F09D35C 86A2001C */  lh    $v0, 0x1c($s5)
.L7F09D360:
/* 0D1E90 7F09D360 24690014 */  addiu $t1, $v1, 0x14
/* 0D1E94 7F09D364 5449002F */  bnel  $v0, $t1, .L7F09D424
/* 0D1E98 7F09D368 00025843 */   sra   $t3, $v0, 1
/* 0D1E9C 7F09D36C 824A03CC */  lb    $t2, 0x3cc($s2)
/* 0D1EA0 7F09D370 52EA002C */  beql  $s7, $t2, .L7F09D424
/* 0D1EA4 7F09D374 00025843 */   sra   $t3, $v0, 1
/* 0D1EA8 7F09D378 8E420004 */  lw    $v0, 4($s2)
.L7F09D37C:
/* 0D1EAC 7F09D37C 26640008 */  addiu $a0, $s3, 8
/* 0D1EB0 7F09D380 2667002C */  addiu $a3, $s3, 0x2c
/* 0D1EB4 7F09D384 5040001E */  beql  $v0, $zero, .L7F09D400
/* 0D1EB8 7F09D388 92680001 */   lbu   $t0, 1($s3)
/* 0D1EBC 7F09D38C 8C450014 */  lw    $a1, 0x14($v0)
/* 0D1EC0 7F09D390 50A0001B */  beql  $a1, $zero, .L7F09D400
/* 0D1EC4 7F09D394 92680001 */   lbu   $t0, 1($s3)
/* 0D1EC8 7F09D398 904B0000 */  lbu   $t3, ($v0)
/* 0D1ECC 7F09D39C 2447002C */  addiu $a3, $v0, 0x2c
/* 0D1ED0 7F09D3A0 24440008 */  addiu $a0, $v0, 8
/* 0D1ED4 7F09D3A4 56CB000C */  bnel  $s6, $t3, .L7F09D3D8
/* 0D1ED8 7F09D3A8 926F0001 */   lbu   $t7, 1($s3)
/* 0D1EDC 7F09D3AC 926C0001 */  lbu   $t4, 1($s3)
/* 0D1EE0 7F09D3B0 8C430004 */  lw    $v1, 4($v0)
/* 0D1EE4 7F09D3B4 92A60038 */  lbu   $a2, 0x38($s5)
/* 0D1EE8 7F09D3B8 318D0008 */  andi  $t5, $t4, 8
/* 0D1EEC 7F09D3BC 000D702B */  sltu  $t6, $zero, $t5
/* 0D1EF0 7F09D3C0 AFAE0010 */  sw    $t6, 0x10($sp)
/* 0D1EF4 7F09D3C4 0FC279C0 */  jal   sub_GAME_7F09E700
/* 0D1EF8 7F09D3C8 24640058 */   addiu $a0, $v1, 0x58
/* 0D1EFC 7F09D3CC 10000009 */  b     .L7F09D3F4
/* 0D1F00 7F09D3D0 864303C8 */   lh    $v1, 0x3c8($s2)
/* 0D1F04 7F09D3D4 926F0001 */  lbu   $t7, 1($s3)
.L7F09D3D8:
/* 0D1F08 7F09D3D8 92A60038 */  lbu   $a2, 0x38($s5)
/* 0D1F0C 7F09D3DC 2447002C */  addiu $a3, $v0, 0x2c
/* 0D1F10 7F09D3E0 31F80008 */  andi  $t8, $t7, 8
/* 0D1F14 7F09D3E4 0018C82B */  sltu  $t9, $zero, $t8
/* 0D1F18 7F09D3E8 0FC279C0 */  jal   sub_GAME_7F09E700
/* 0D1F1C 7F09D3EC AFB90010 */   sw    $t9, 0x10($sp)
/* 0D1F20 7F09D3F0 864303C8 */  lh    $v1, 0x3c8($s2)
.L7F09D3F4:
/* 0D1F24 7F09D3F4 1000000A */  b     .L7F09D420
/* 0D1F28 7F09D3F8 86A2001C */   lh    $v0, 0x1c($s5)
/* 0D1F2C 7F09D3FC 92680001 */  lbu   $t0, 1($s3)
.L7F09D400:
/* 0D1F30 7F09D400 8E650014 */  lw    $a1, 0x14($s3)
/* 0D1F34 7F09D404 92A60038 */  lbu   $a2, 0x38($s5)
/* 0D1F38 7F09D408 31090008 */  andi  $t1, $t0, 8
/* 0D1F3C 7F09D40C 0009502B */  sltu  $t2, $zero, $t1
/* 0D1F40 7F09D410 0FC279C0 */  jal   sub_GAME_7F09E700
/* 0D1F44 7F09D414 AFAA0010 */   sw    $t2, 0x10($sp)
/* 0D1F48 7F09D418 864303C8 */  lh    $v1, 0x3c8($s2)
/* 0D1F4C 7F09D41C 86A2001C */  lh    $v0, 0x1c($s5)
.L7F09D420:
/* 0D1F50 7F09D420 00025843 */  sra   $t3, $v0, 1
.L7F09D424:
/* 0D1F54 7F09D424 5563000D */  bnel  $t3, $v1, .L7F09D45C
/* 0D1F58 7F09D428 8FAD0070 */   lw    $t5, 0x70($sp)
/* 0D1F5C 7F09D42C 824C03CD */  lb    $t4, 0x3cd($s2)
/* 0D1F60 7F09D430 5180000A */  beql  $t4, $zero, .L7F09D45C
/* 0D1F64 7F09D434 8FAD0070 */   lw    $t5, 0x70($sp)
/* 0D1F68 7F09D438 C6A40010 */  lwc1  $f4, 0x10($s5)
/* 0D1F6C 7F09D43C 264403D0 */  addiu $a0, $s2, 0x3d0
/* 0D1F70 7F09D440 864603DC */  lh    $a2, 0x3dc($s2)
/* 0D1F74 7F09D444 46142182 */  mul.s $f6, $f4, $f20
/* 0D1F78 7F09D448 44053000 */  mfc1  $a1, $f6
/* 0D1F7C 7F09D44C 0FC2809F */  jal   sub_GAME_7F0A027C
/* 0D1F80 7F09D450 00000000 */   nop   
/* 0D1F84 7F09D454 864303C8 */  lh    $v1, 0x3c8($s2)
/* 0D1F88 7F09D458 8FAD0070 */  lw    $t5, 0x70($sp)
.L7F09D45C:
/* 0D1F8C 7F09D45C 26940001 */  addiu $s4, $s4, 1
/* 0D1F90 7F09D460 568DFFAD */  bnel  $s4, $t5, .L7F09D318
/* 0D1F94 7F09D464 24780001 */   addiu $t8, $v1, 1
.L7F09D468:
/* 0D1F98 7F09D468 3C014180 */  li    $at, 0x41800000 # 16.000000
/* 0D1F9C 7F09D46C 44819000 */  mtc1  $at, $f18
/* 0D1FA0 7F09D470 C6B00020 */  lwc1  $f16, 0x20($s5)
/* 0D1FA4 7F09D474 86B8001C */  lh    $t8, 0x1c($s5)
/* 0D1FA8 7F09D478 00001025 */  move  $v0, $zero
/* 0D1FAC 7F09D47C 46109282 */  mul.s $f10, $f18, $f16
/* 0D1FB0 7F09D480 4600520D */  trunc.w.s $f8, $f10
/* 0D1FB4 7F09D484 440F4000 */  mfc1  $t7, $f8
/* 0D1FB8 7F09D488 00000000 */  nop   
/* 0D1FBC 7F09D48C 030FC821 */  addu  $t9, $t8, $t7
/* 0D1FC0 7F09D490 0079082A */  slt   $at, $v1, $t9
/* 0D1FC4 7F09D494 14200004 */  bnez  $at, .L7F09D4A8
/* 0D1FC8 7F09D498 00000000 */   nop   
/* 0D1FCC 7F09D49C AE400000 */  sw    $zero, ($s2)
/* 0D1FD0 7F09D4A0 10000001 */  b     .L7F09D4A8
/* 0D1FD4 7F09D4A4 24020001 */   li    $v0, 1
.L7F09D4A8:
/* 0D1FD8 7F09D4A8 8FBF006C */  lw    $ra, 0x6c($sp)
/* 0D1FDC 7F09D4AC D7B40018 */  ldc1  $f20, 0x18($sp)
/* 0D1FE0 7F09D4B0 D7B60020 */  ldc1  $f22, 0x20($sp)
/* 0D1FE4 7F09D4B4 D7B80028 */  ldc1  $f24, 0x28($sp)
/* 0D1FE8 7F09D4B8 D7BA0030 */  ldc1  $f26, 0x30($sp)
/* 0D1FEC 7F09D4BC D7BC0038 */  ldc1  $f28, 0x38($sp)
/* 0D1FF0 7F09D4C0 D7BE0040 */  ldc1  $f30, 0x40($sp)
/* 0D1FF4 7F09D4C4 8FB0004C */  lw    $s0, 0x4c($sp)
/* 0D1FF8 7F09D4C8 8FB10050 */  lw    $s1, 0x50($sp)
/* 0D1FFC 7F09D4CC 8FB20054 */  lw    $s2, 0x54($sp)
/* 0D2000 7F09D4D0 8FB30058 */  lw    $s3, 0x58($sp)
/* 0D2004 7F09D4D4 8FB4005C */  lw    $s4, 0x5c($sp)
/* 0D2008 7F09D4D8 8FB50060 */  lw    $s5, 0x60($sp)
/* 0D200C 7F09D4DC 8FB60064 */  lw    $s6, 0x64($sp)
/* 0D2010 7F09D4E0 8FB70068 */  lw    $s7, 0x68($sp)
/* 0D2014 7F09D4E4 03E00008 */  jr    $ra
/* 0D2018 7F09D4E8 27BD00C8 */   addiu $sp, $sp, 0xc8
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F09D4EC(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F09D4EC
/* 0D201C 7F09D4EC 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0D2020 7F09D4F0 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0D2024 7F09D4F4 0FC1E0F1 */  jal   currentPlayerGetMatrix10CC
/* 0D2028 7F09D4F8 AFA40018 */   sw    $a0, 0x18($sp)
/* 0D202C 7F09D4FC 8FA40018 */  lw    $a0, 0x18($sp)
/* 0D2030 7F09D500 C4440008 */  lwc1  $f4, 8($v0)
/* 0D2034 7F09D504 C44A0018 */  lwc1  $f10, 0x18($v0)
/* 0D2038 7F09D508 C4860008 */  lwc1  $f6, 8($a0)
/* 0D203C 7F09D50C C490000C */  lwc1  $f16, 0xc($a0)
/* 0D2040 7F09D510 3C0142C8 */  li    $at, 0x42C80000 # 100.000000
/* 0D2044 7F09D514 46062202 */  mul.s $f8, $f4, $f6
/* 0D2048 7F09D518 C4460028 */  lwc1  $f6, 0x28($v0)
/* 0D204C 7F09D51C 44811000 */  mtc1  $at, $f2
/* 0D2050 7F09D520 46105482 */  mul.s $f18, $f10, $f16
/* 0D2054 7F09D524 C48A0010 */  lwc1  $f10, 0x10($a0)
/* 0D2058 7F09D528 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 0D205C 7F09D52C 3C0E8005 */  lui   $t6, %hi(g_ClockTimer) 
/* 0D2060 7F09D530 460A3402 */  mul.s $f16, $f6, $f10
/* 0D2064 7F09D534 46124100 */  add.s $f4, $f8, $f18
/* 0D2068 7F09D538 C4520038 */  lwc1  $f18, 0x38($v0)
/* 0D206C 7F09D53C 00001025 */  move  $v0, $zero
/* 0D2070 7F09D540 46102200 */  add.s $f8, $f4, $f16
/* 0D2074 7F09D544 46089180 */  add.s $f6, $f18, $f8
/* 0D2078 7F09D548 46003287 */  neg.s $f10, $f6
/* 0D207C 7F09D54C E48A0018 */  swc1  $f10, 0x18($a0)
/* 0D2080 7F09D550 C4800018 */  lwc1  $f0, 0x18($a0)
/* 0D2084 7F09D554 4602003C */  c.lt.s $f0, $f2
/* 0D2088 7F09D558 00000000 */  nop   
/* 0D208C 7F09D55C 45020007 */  bc1fl .L7F09D57C
/* 0D2090 7F09D560 46020481 */   sub.s $f18, $f0, $f2
/* 0D2094 7F09D564 44812000 */  mtc1  $at, $f4
/* 0D2098 7F09D568 00000000 */  nop   
/* 0D209C 7F09D56C 46040402 */  mul.s $f16, $f0, $f4
/* 0D20A0 7F09D570 10000003 */  b     .L7F09D580
/* 0D20A4 7F09D574 E4900018 */   swc1  $f16, 0x18($a0)
/* 0D20A8 7F09D578 46020481 */  sub.s $f18, $f0, $f2
.L7F09D57C:
/* 0D20AC 7F09D57C E4920018 */  swc1  $f18, 0x18($a0)
.L7F09D580:
/* 0D20B0 7F09D580 8DCE8374 */  lw    $t6, %lo(g_ClockTimer)($t6)
/* 0D20B4 7F09D584 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0D20B8 7F09D588 15C00003 */  bnez  $t6, .L7F09D598
/* 0D20BC 7F09D58C 00000000 */   nop   
/* 0D20C0 7F09D590 10000001 */  b     .L7F09D598
/* 0D20C4 7F09D594 00001025 */   move  $v0, $zero
.L7F09D598:
/* 0D20C8 7F09D598 03E00008 */  jr    $ra
/* 0D20CC 7F09D59C 27BD0018 */   addiu $sp, $sp, 0x18
)
#endif





#ifdef NONMATCHING
void unk09c250RenderPropExplosion(void) {

}
#else
GLOBAL_ASM(
.text
glabel unk09c250RenderPropExplosion
/* 0D20D0 7F09D5A0 27BDFF70 */  addiu $sp, $sp, -0x90
/* 0D20D4 7F09D5A4 AFB0001C */  sw    $s0, 0x1c($sp)
/* 0D20D8 7F09D5A8 AFBF003C */  sw    $ra, 0x3c($sp)
/* 0D20DC 7F09D5AC AFB70038 */  sw    $s7, 0x38($sp)
/* 0D20E0 7F09D5B0 AFB60034 */  sw    $s6, 0x34($sp)
/* 0D20E4 7F09D5B4 AFB50030 */  sw    $s5, 0x30($sp)
/* 0D20E8 7F09D5B8 AFB4002C */  sw    $s4, 0x2c($sp)
/* 0D20EC 7F09D5BC AFB30028 */  sw    $s3, 0x28($sp)
/* 0D20F0 7F09D5C0 AFB20024 */  sw    $s2, 0x24($sp)
/* 0D20F4 7F09D5C4 AFB10020 */  sw    $s1, 0x20($sp)
/* 0D20F8 7F09D5C8 9091002C */  lbu   $s1, 0x2c($a0)
/* 0D20FC 7F09D5CC 00808025 */  move  $s0, $a0
/* 0D2100 7F09D5D0 8C950004 */  lw    $s5, 4($a0)
/* 0D2104 7F09D5D4 00C09025 */  move  $s2, $a2
/* 0D2108 7F09D5D8 00A0A025 */  move  $s4, $a1
/* 0D210C 7F09D5DC 0FC2F285 */  jal   getRoomIndexPOS
/* 0D2110 7F09D5E0 02202025 */   move  $a0, $s1
/* 0D2114 7F09D5E4 16400003 */  bnez  $s2, .L7F09D5F4
/* 0D2118 7F09D5E8 0040B025 */   move  $s6, $v0
/* 0D211C 7F09D5EC 10000084 */  b     .L7F09D800
/* 0D2120 7F09D5F0 02801025 */   move  $v0, $s4
.L7F09D5F4:
/* 0D2124 7F09D5F4 02002025 */  move  $a0, $s0
/* 0D2128 7F09D5F8 0FC15299 */  jal   sub_GAME_7F054A64
/* 0D212C 7F09D5FC 27A50070 */   addiu $a1, $sp, 0x70
/* 0D2130 7F09D600 1840000A */  blez  $v0, .L7F09D62C
/* 0D2134 7F09D604 00000000 */   nop   
/* 0D2138 7F09D608 C7A4007C */  lwc1  $f4, 0x7c($sp)
/* 0D213C 7F09D60C 02802025 */  move  $a0, $s4
/* 0D2140 7F09D610 8FA50070 */  lw    $a1, 0x70($sp)
/* 0D2144 7F09D614 8FA60074 */  lw    $a2, 0x74($sp)
/* 0D2148 7F09D618 8FA70078 */  lw    $a3, 0x78($sp)
/* 0D214C 7F09D61C 0FC2D3FD */  jal   bgScissorCurrentPlayerViewF
/* 0D2150 7F09D620 E7A40010 */   swc1  $f4, 0x10($sp)
/* 0D2154 7F09D624 10000004 */  b     .L7F09D638
/* 0D2158 7F09D628 0040A025 */   move  $s4, $v0
.L7F09D62C:
/* 0D215C 7F09D62C 0FC2D3ED */  jal   bgScissorCurrentPlayerViewDefault
/* 0D2160 7F09D630 02802025 */   move  $a0, $s4
/* 0D2164 7F09D634 0040A025 */  move  $s4, $v0
.L7F09D638:
/* 0D2168 7F09D638 02801025 */  move  $v0, $s4
/* 0D216C 7F09D63C 3C0F0001 */  lui   $t7, (0x00013000 >> 16) # lui $t7, 1
/* 0D2170 7F09D640 35EF3000 */  ori   $t7, (0x00013000 & 0xFFFF) # ori $t7, $t7, 0x3000
/* 0D2174 7F09D644 26940008 */  addiu $s4, $s4, 8
/* 0D2178 7F09D648 3C0EB600 */  lui   $t6, 0xb600
/* 0D217C 7F09D64C 3C180103 */  lui   $t8, (0x01030040 >> 16) # lui $t8, 0x103
/* 0D2180 7F09D650 AC4E0000 */  sw    $t6, ($v0)
/* 0D2184 7F09D654 AC4F0004 */  sw    $t7, 4($v0)
/* 0D2188 7F09D658 37180040 */  ori   $t8, (0x01030040 & 0xFFFF) # ori $t8, $t8, 0x40
/* 0D218C 7F09D65C 02808025 */  move  $s0, $s4
/* 0D2190 7F09D660 AE180000 */  sw    $t8, ($s0)
/* 0D2194 7F09D664 0FC1E0E5 */  jal   get_BONDdata_field_10E0
/* 0D2198 7F09D668 26940008 */   addiu $s4, $s4, 8
/* 0D219C 7F09D66C 0C003A2C */  jal   osVirtualToPhysical
/* 0D21A0 7F09D670 00402025 */   move  $a0, $v0
/* 0D21A4 7F09D674 AE020004 */  sw    $v0, 4($s0)
/* 0D21A8 7F09D678 02802025 */  move  $a0, $s4
/* 0D21AC 7F09D67C 0FC2F271 */  jal   sub_GAME_7F0BC9C4
/* 0D21B0 7F09D680 02202825 */   move  $a1, $s1
/* 0D21B4 7F09D684 3C19BC00 */  lui   $t9, (0xBC000806 >> 16) # lui $t9, 0xbc00
/* 0D21B8 7F09D688 37390806 */  ori   $t9, (0xBC000806 & 0xFFFF) # ori $t9, $t9, 0x806
/* 0D21BC 7F09D68C AC590000 */  sw    $t9, ($v0)
/* 0D21C0 7F09D690 3C048009 */  lui   $a0, %hi(pGlobalimagetable)
/* 0D21C4 7F09D694 8C84D0B4 */  lw    $a0, %lo(pGlobalimagetable)($a0)
/* 0D21C8 7F09D698 00408025 */  move  $s0, $v0
/* 0D21CC 7F09D69C 0C003A2C */  jal   osVirtualToPhysical
/* 0D21D0 7F09D6A0 24540008 */   addiu $s4, $v0, 8
/* 0D21D4 7F09D6A4 3C178004 */  lui   $s7, %hi(array_smoke_types+0x680) 
/* 0D21D8 7F09D6A8 3C138004 */  lui   $s3, %hi(array_explosion_types)
/* 0D21DC 7F09D6AC AE020004 */  sw    $v0, 4($s0)
/* 0D21E0 7F09D6B0 26730284 */  addiu $s3, %lo(array_explosion_types) # addiu $s3, $s3, 0x284
/* 0D21E4 7F09D6B4 26F707FC */  addiu $s7, %lo(array_smoke_types+0x680) # addiu $s7, $s7, 0x7fc
/* 0D21E8 7F09D6B8 2412000E */  li    $s2, 14
.L7F09D6BC:
/* 0D21EC 7F09D6BC 02801025 */  move  $v0, $s4
/* 0D21F0 7F09D6C0 3C080600 */  lui   $t0, 0x600
/* 0D21F4 7F09D6C4 AC480000 */  sw    $t0, ($v0)
/* 0D21F8 7F09D6C8 8EE90000 */  lw    $t1, ($s7)
/* 0D21FC 7F09D6CC 26940008 */  addiu $s4, $s4, 8
/* 0D2200 7F09D6D0 00008825 */  move  $s1, $zero
/* 0D2204 7F09D6D4 02A08025 */  move  $s0, $s5
/* 0D2208 7F09D6D8 AC490004 */  sw    $t1, 4($v0)
.L7F09D6DC:
/* 0D220C 7F09D6DC 8602001C */  lh    $v0, 0x1c($s0)
/* 0D2210 7F09D6E0 18400012 */  blez  $v0, .L7F09D72C
/* 0D2214 7F09D6E4 244AFFFF */   addiu $t2, $v0, -1
/* 0D2218 7F09D6E8 448A3000 */  mtc1  $t2, $f6
/* 0D221C 7F09D6EC 82AB03CC */  lb    $t3, 0x3cc($s5)
/* 0D2220 7F09D6F0 26040008 */  addiu $a0, $s0, 8
/* 0D2224 7F09D6F4 46803220 */  cvt.s.w $f8, $f6
/* 0D2228 7F09D6F8 000B6180 */  sll   $t4, $t3, 6
/* 0D222C 7F09D6FC 026C6821 */  addu  $t5, $s3, $t4
/* 0D2230 7F09D700 C5AA0020 */  lwc1  $f10, 0x20($t5)
/* 0D2234 7F09D704 02802825 */  move  $a1, $s4
/* 0D2238 7F09D708 460A4403 */  div.s $f16, $f8, $f10
/* 0D223C 7F09D70C 4600848D */  trunc.w.s $f18, $f16
/* 0D2240 7F09D710 440F9000 */  mfc1  $t7, $f18
/* 0D2244 7F09D714 00000000 */  nop   
/* 0D2248 7F09D718 564F0005 */  bnel  $s2, $t7, .L7F09D730
/* 0D224C 7F09D71C 26310018 */   addiu $s1, $s1, 0x18
/* 0D2250 7F09D720 0FC2760B */  jal   sub_GAME_7F09D82C
/* 0D2254 7F09D724 02C03025 */   move  $a2, $s6
/* 0D2258 7F09D728 0040A025 */  move  $s4, $v0
.L7F09D72C:
/* 0D225C 7F09D72C 26310018 */  addiu $s1, $s1, 0x18
.L7F09D730:
/* 0D2260 7F09D730 2A2103C0 */  slti  $at, $s1, 0x3c0
/* 0D2264 7F09D734 1420FFE9 */  bnez  $at, .L7F09D6DC
/* 0D2268 7F09D738 26100018 */   addiu $s0, $s0, 0x18
/* 0D226C 7F09D73C 2652FFFF */  addiu $s2, $s2, -1
/* 0D2270 7F09D740 0641FFDE */  bgez  $s2, .L7F09D6BC
/* 0D2274 7F09D744 26F7FFFC */   addiu $s7, $s7, -4
/* 0D2278 7F09D748 3C180103 */  lui   $t8, (0x01030040 >> 16) # lui $t8, 0x103
/* 0D227C 7F09D74C 37180040 */  ori   $t8, (0x01030040 & 0xFFFF) # ori $t8, $t8, 0x40
/* 0D2280 7F09D750 02809025 */  move  $s2, $s4
/* 0D2284 7F09D754 AE580000 */  sw    $t8, ($s2)
/* 0D2288 7F09D758 0FC1E0DD */  jal   currentPlayerGetProjectionMatrix
/* 0D228C 7F09D75C 26940008 */   addiu $s4, $s4, 8
/* 0D2290 7F09D760 0C003A2C */  jal   osVirtualToPhysical
/* 0D2294 7F09D764 00402025 */   move  $a0, $v0
/* 0D2298 7F09D768 AE420004 */  sw    $v0, 4($s2)
/* 0D229C 7F09D76C 82B903CC */  lb    $t9, 0x3cc($s5)
/* 0D22A0 7F09D770 3C014170 */  li    $at, 0x41700000 # 15.000000
/* 0D22A4 7F09D774 44813000 */  mtc1  $at, $f6
/* 0D22A8 7F09D778 00194180 */  sll   $t0, $t9, 6
/* 0D22AC 7F09D77C 02684821 */  addu  $t1, $s3, $t0
/* 0D22B0 7F09D780 C5240020 */  lwc1  $f4, 0x20($t1)
/* 0D22B4 7F09D784 240203C0 */  li    $v0, 960
/* 0D22B8 7F09D788 00008825 */  move  $s1, $zero
/* 0D22BC 7F09D78C 46062202 */  mul.s $f8, $f4, $f6
/* 0D22C0 7F09D790 02A08025 */  move  $s0, $s5
/* 0D22C4 7F09D794 4600428D */  trunc.w.s $f10, $f8
/* 0D22C8 7F09D798 44035000 */  mfc1  $v1, $f10
/* 0D22CC 7F09D79C 00000000 */  nop   
.L7F09D7A0:
/* 0D22D0 7F09D7A0 860B001C */  lh    $t3, 0x1c($s0)
/* 0D22D4 7F09D7A4 26310060 */  addiu $s1, $s1, 0x60
/* 0D22D8 7F09D7A8 006B082A */  slt   $at, $v1, $t3
/* 0D22DC 7F09D7AC 50200003 */  beql  $at, $zero, .L7F09D7BC
/* 0D22E0 7F09D7B0 860C0034 */   lh    $t4, 0x34($s0)
/* 0D22E4 7F09D7B4 A600001C */  sh    $zero, 0x1c($s0)
/* 0D22E8 7F09D7B8 860C0034 */  lh    $t4, 0x34($s0)
.L7F09D7BC:
/* 0D22EC 7F09D7BC 006C082A */  slt   $at, $v1, $t4
/* 0D22F0 7F09D7C0 50200003 */  beql  $at, $zero, .L7F09D7D0
/* 0D22F4 7F09D7C4 860D004C */   lh    $t5, 0x4c($s0)
/* 0D22F8 7F09D7C8 A6000034 */  sh    $zero, 0x34($s0)
/* 0D22FC 7F09D7CC 860D004C */  lh    $t5, 0x4c($s0)
.L7F09D7D0:
/* 0D2300 7F09D7D0 006D082A */  slt   $at, $v1, $t5
/* 0D2304 7F09D7D4 50200003 */  beql  $at, $zero, .L7F09D7E4
/* 0D2308 7F09D7D8 860E0064 */   lh    $t6, 0x64($s0)
/* 0D230C 7F09D7DC A600004C */  sh    $zero, 0x4c($s0)
/* 0D2310 7F09D7E0 860E0064 */  lh    $t6, 0x64($s0)
.L7F09D7E4:
/* 0D2314 7F09D7E4 006E082A */  slt   $at, $v1, $t6
/* 0D2318 7F09D7E8 10200002 */  beqz  $at, .L7F09D7F4
/* 0D231C 7F09D7EC 00000000 */   nop   
/* 0D2320 7F09D7F0 A6000064 */  sh    $zero, 0x64($s0)
.L7F09D7F4:
/* 0D2324 7F09D7F4 1622FFEA */  bne   $s1, $v0, .L7F09D7A0
/* 0D2328 7F09D7F8 26100060 */   addiu $s0, $s0, 0x60
/* 0D232C 7F09D7FC 02801025 */  move  $v0, $s4
.L7F09D800:
/* 0D2330 7F09D800 8FBF003C */  lw    $ra, 0x3c($sp)
/* 0D2334 7F09D804 8FB0001C */  lw    $s0, 0x1c($sp)
/* 0D2338 7F09D808 8FB10020 */  lw    $s1, 0x20($sp)
/* 0D233C 7F09D80C 8FB20024 */  lw    $s2, 0x24($sp)
/* 0D2340 7F09D810 8FB30028 */  lw    $s3, 0x28($sp)
/* 0D2344 7F09D814 8FB4002C */  lw    $s4, 0x2c($sp)
/* 0D2348 7F09D818 8FB50030 */  lw    $s5, 0x30($sp)
/* 0D234C 7F09D81C 8FB60034 */  lw    $s6, 0x34($sp)
/* 0D2350 7F09D820 8FB70038 */  lw    $s7, 0x38($sp)
/* 0D2354 7F09D824 03E00008 */  jr    $ra
/* 0D2358 7F09D828 27BD0090 */   addiu $sp, $sp, 0x90
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F09D82C(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F09D82C
/* 0D235C 7F09D82C 27BDFF48 */  addiu $sp, $sp, -0xb8
/* 0D2360 7F09D830 3C0F8004 */  lui   $t7, %hi(D_8004080C+0xF4) 
/* 0D2364 7F09D834 AFBF0024 */  sw    $ra, 0x24($sp)
/* 0D2368 7F09D838 AFB20020 */  sw    $s2, 0x20($sp)
/* 0D236C 7F09D83C AFB1001C */  sw    $s1, 0x1c($sp)
/* 0D2370 7F09D840 AFB00018 */  sw    $s0, 0x18($sp)
/* 0D2374 7F09D844 25EF0900 */  addiu $t7, %lo(D_8004080C+0xF4) # addiu $t7, $t7, 0x900
/* 0D2378 7F09D848 8DE10000 */  lw    $at, ($t7)
/* 0D237C 7F09D84C 8DE80004 */  lw    $t0, 4($t7)
/* 0D2380 7F09D850 27AE00A0 */  addiu $t6, $sp, 0xa0
/* 0D2384 7F09D854 ADC10000 */  sw    $at, ($t6)
/* 0D2388 7F09D858 ADC80004 */  sw    $t0, 4($t6)
/* 0D238C 7F09D85C 8DE8000C */  lw    $t0, 0xc($t7)
/* 0D2390 7F09D860 8DE10008 */  lw    $at, 8($t7)
/* 0D2394 7F09D864 00808025 */  move  $s0, $a0
/* 0D2398 7F09D868 00C08825 */  move  $s1, $a2
/* 0D239C 7F09D86C 00A09025 */  move  $s2, $a1
/* 0D23A0 7F09D870 ADC8000C */  sw    $t0, 0xc($t6)
/* 0D23A4 7F09D874 0FC1E111 */  jal   currentPlayerGetMatrix10D4
/* 0D23A8 7F09D878 ADC10008 */   sw    $at, 8($t6)
/* 0D23AC 7F09D87C 0FC227F5 */  jal   bondviewGetCurrentPlayersPosition
/* 0D23B0 7F09D880 AFA2009C */   sw    $v0, 0x9c($sp)
/* 0D23B4 7F09D884 C6040000 */  lwc1  $f4, ($s0)
/* 0D23B8 7F09D888 C4460000 */  lwc1  $f6, ($v0)
/* 0D23BC 7F09D88C C6080004 */  lwc1  $f8, 4($s0)
/* 0D23C0 7F09D890 C44A0004 */  lwc1  $f10, 4($v0)
/* 0D23C4 7F09D894 46062381 */  sub.s $f14, $f4, $f6
/* 0D23C8 7F09D898 C4460008 */  lwc1  $f6, 8($v0)
/* 0D23CC 7F09D89C C6040008 */  lwc1  $f4, 8($s0)
/* 0D23D0 7F09D8A0 460A4401 */  sub.s $f16, $f8, $f10
/* 0D23D4 7F09D8A4 460E7202 */  mul.s $f8, $f14, $f14
/* 0D23D8 7F09D8A8 E7AE0064 */  swc1  $f14, 0x64($sp)
/* 0D23DC 7F09D8AC 46062481 */  sub.s $f18, $f4, $f6
/* 0D23E0 7F09D8B0 46108282 */  mul.s $f10, $f16, $f16
/* 0D23E4 7F09D8B4 E7B00060 */  swc1  $f16, 0x60($sp)
/* 0D23E8 7F09D8B8 AFA20098 */  sw    $v0, 0x98($sp)
/* 0D23EC 7F09D8BC 46129182 */  mul.s $f6, $f18, $f18
/* 0D23F0 7F09D8C0 E7B2005C */  swc1  $f18, 0x5c($sp)
/* 0D23F4 7F09D8C4 460A4100 */  add.s $f4, $f8, $f10
/* 0D23F8 7F09D8C8 0C007DF8 */  jal   sqrtf
/* 0D23FC 7F09D8CC 46062300 */   add.s $f12, $f4, $f6
/* 0D2400 7F09D8D0 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 0D2404 7F09D8D4 44814000 */  mtc1  $at, $f8
/* 0D2408 7F09D8D8 3C0142C8 */  li    $at, 0x42C80000 # 100.000000
/* 0D240C 7F09D8DC 44815000 */  mtc1  $at, $f10
/* 0D2410 7F09D8E0 46080302 */  mul.s $f12, $f0, $f8
/* 0D2414 7F09D8E4 44802000 */  mtc1  $zero, $f4
/* 0D2418 7F09D8E8 8FA3009C */  lw    $v1, 0x9c($sp)
/* 0D241C 7F09D8EC 8FA50098 */  lw    $a1, 0x98($sp)
/* 0D2420 7F09D8F0 C7AE0064 */  lwc1  $f14, 0x64($sp)
/* 0D2424 7F09D8F4 C7B00060 */  lwc1  $f16, 0x60($sp)
/* 0D2428 7F09D8F8 C7B2005C */  lwc1  $f18, 0x5c($sp)
/* 0D242C 7F09D8FC 460C503C */  c.lt.s $f10, $f12
/* 0D2430 7F09D900 00000000 */  nop   
/* 0D2434 7F09D904 45000003 */  bc1f  .L7F09D914
/* 0D2438 7F09D908 3C0142C8 */   li    $at, 0x42C80000 # 100.000000
/* 0D243C 7F09D90C 44816000 */  mtc1  $at, $f12
/* 0D2440 7F09D910 00000000 */  nop   
.L7F09D914:
/* 0D2444 7F09D914 46040032 */  c.eq.s $f0, $f4
/* 0D2448 7F09D918 00000000 */  nop   
/* 0D244C 7F09D91C 45020005 */  bc1fl .L7F09D934
/* 0D2450 7F09D920 460C0181 */   sub.s $f6, $f0, $f12
/* 0D2454 7F09D924 44801000 */  mtc1  $zero, $f2
/* 0D2458 7F09D928 10000004 */  b     .L7F09D93C
/* 0D245C 7F09D92C C608000C */   lwc1  $f8, 0xc($s0)
/* 0D2460 7F09D930 460C0181 */  sub.s $f6, $f0, $f12
.L7F09D934:
/* 0D2464 7F09D934 46003083 */  div.s $f2, $f6, $f0
/* 0D2468 7F09D938 C608000C */  lwc1  $f8, 0xc($s0)
.L7F09D93C:
/* 0D246C 7F09D93C C60A0010 */  lwc1  $f10, 0x10($s0)
/* 0D2470 7F09D940 C4A40000 */  lwc1  $f4, ($a1)
/* 0D2474 7F09D944 46024002 */  mul.s $f0, $f8, $f2
/* 0D2478 7F09D948 24040004 */  li    $a0, 4
/* 0D247C 7F09D94C 46025302 */  mul.s $f12, $f10, $f2
/* 0D2480 7F09D950 00000000 */  nop   
/* 0D2484 7F09D954 46027182 */  mul.s $f6, $f14, $f2
/* 0D2488 7F09D958 46062200 */  add.s $f8, $f4, $f6
/* 0D248C 7F09D95C 46028102 */  mul.s $f4, $f16, $f2
/* 0D2490 7F09D960 E7A8004C */  swc1  $f8, 0x4c($sp)
/* 0D2494 7F09D964 C4AA0004 */  lwc1  $f10, 4($a1)
/* 0D2498 7F09D968 46045180 */  add.s $f6, $f10, $f4
/* 0D249C 7F09D96C 46029282 */  mul.s $f10, $f18, $f2
/* 0D24A0 7F09D970 E7A60048 */  swc1  $f6, 0x48($sp)
/* 0D24A4 7F09D974 C4A80008 */  lwc1  $f8, 8($a1)
/* 0D24A8 7F09D978 E7AC0050 */  swc1  $f12, 0x50($sp)
/* 0D24AC 7F09D97C E7A00054 */  swc1  $f0, 0x54($sp)
/* 0D24B0 7F09D980 460A4100 */  add.s $f4, $f8, $f10
/* 0D24B4 7F09D984 AFA3009C */  sw    $v1, 0x9c($sp)
/* 0D24B8 7F09D988 0FC2F5B1 */  jal   dynAllocate7F0BD6C4
/* 0D24BC 7F09D98C E7A40044 */   swc1  $f4, 0x44($sp)
/* 0D24C0 7F09D990 27A400A0 */  addiu $a0, $sp, 0xa0
/* 0D24C4 7F09D994 8C810000 */  lw    $at, ($a0)
/* 0D24C8 7F09D998 8FA3009C */  lw    $v1, 0x9c($sp)
/* 0D24CC 7F09D99C C7A00054 */  lwc1  $f0, 0x54($sp)
/* 0D24D0 7F09D9A0 C7AC0050 */  lwc1  $f12, 0x50($sp)
/* 0D24D4 7F09D9A4 AC410000 */  sw    $at, ($v0)
/* 0D24D8 7F09D9A8 8C8B0004 */  lw    $t3, 4($a0)
/* 0D24DC 7F09D9AC 00408025 */  move  $s0, $v0
/* 0D24E0 7F09D9B0 AC4B0004 */  sw    $t3, 4($v0)
/* 0D24E4 7F09D9B4 8C810008 */  lw    $at, 8($a0)
/* 0D24E8 7F09D9B8 AC410008 */  sw    $at, 8($v0)
/* 0D24EC 7F09D9BC 8C8B000C */  lw    $t3, 0xc($a0)
/* 0D24F0 7F09D9C0 AC4B000C */  sw    $t3, 0xc($v0)
/* 0D24F4 7F09D9C4 8C810000 */  lw    $at, ($a0)
/* 0D24F8 7F09D9C8 AC410010 */  sw    $at, 0x10($v0)
/* 0D24FC 7F09D9CC 8C990004 */  lw    $t9, 4($a0)
/* 0D2500 7F09D9D0 AC590014 */  sw    $t9, 0x14($v0)
/* 0D2504 7F09D9D4 8C810008 */  lw    $at, 8($a0)
/* 0D2508 7F09D9D8 AC410018 */  sw    $at, 0x18($v0)
/* 0D250C 7F09D9DC 8C99000C */  lw    $t9, 0xc($a0)
/* 0D2510 7F09D9E0 AC59001C */  sw    $t9, 0x1c($v0)
/* 0D2514 7F09D9E4 8C810000 */  lw    $at, ($a0)
/* 0D2518 7F09D9E8 AC410020 */  sw    $at, 0x20($v0)
/* 0D251C 7F09D9EC 8C8F0004 */  lw    $t7, 4($a0)
/* 0D2520 7F09D9F0 AC4F0024 */  sw    $t7, 0x24($v0)
/* 0D2524 7F09D9F4 8C810008 */  lw    $at, 8($a0)
/* 0D2528 7F09D9F8 AC410028 */  sw    $at, 0x28($v0)
/* 0D252C 7F09D9FC 8C8F000C */  lw    $t7, 0xc($a0)
/* 0D2530 7F09DA00 AC4F002C */  sw    $t7, 0x2c($v0)
/* 0D2534 7F09DA04 8C810000 */  lw    $at, ($a0)
/* 0D2538 7F09DA08 AC410030 */  sw    $at, 0x30($v0)
/* 0D253C 7F09DA0C 8C890004 */  lw    $t1, 4($a0)
/* 0D2540 7F09DA10 AC490034 */  sw    $t1, 0x34($v0)
/* 0D2544 7F09DA14 8C810008 */  lw    $at, 8($a0)
/* 0D2548 7F09DA18 AC410038 */  sw    $at, 0x38($v0)
/* 0D254C 7F09DA1C 8C89000C */  lw    $t1, 0xc($a0)
/* 0D2550 7F09DA20 AC49003C */  sw    $t1, 0x3c($v0)
/* 0D2554 7F09DA24 8C810000 */  lw    $at, ($a0)
/* 0D2558 7F09DA28 AC410040 */  sw    $at, 0x40($v0)
/* 0D255C 7F09DA2C 8C8C0004 */  lw    $t4, 4($a0)
/* 0D2560 7F09DA30 AC4C0044 */  sw    $t4, 0x44($v0)
/* 0D2564 7F09DA34 8C810008 */  lw    $at, 8($a0)
/* 0D2568 7F09DA38 AC410048 */  sw    $at, 0x48($v0)
/* 0D256C 7F09DA3C 8C8C000C */  lw    $t4, 0xc($a0)
/* 0D2570 7F09DA40 AC4C004C */  sw    $t4, 0x4c($v0)
/* 0D2574 7F09DA44 C4660000 */  lwc1  $f6, ($v1)
/* 0D2578 7F09DA48 46003202 */  mul.s $f8, $f6, $f0
/* 0D257C 7F09DA4C E7A8008C */  swc1  $f8, 0x8c($sp)
/* 0D2580 7F09DA50 C46A0004 */  lwc1  $f10, 4($v1)
/* 0D2584 7F09DA54 46005102 */  mul.s $f4, $f10, $f0
/* 0D2588 7F09DA58 E7A40090 */  swc1  $f4, 0x90($sp)
/* 0D258C 7F09DA5C C4660008 */  lwc1  $f6, 8($v1)
/* 0D2590 7F09DA60 46003202 */  mul.s $f8, $f6, $f0
/* 0D2594 7F09DA64 E7A80094 */  swc1  $f8, 0x94($sp)
/* 0D2598 7F09DA68 C46A0000 */  lwc1  $f10, ($v1)
/* 0D259C 7F09DA6C 460C5102 */  mul.s $f4, $f10, $f12
/* 0D25A0 7F09DA70 E7A40080 */  swc1  $f4, 0x80($sp)
/* 0D25A4 7F09DA74 C4660004 */  lwc1  $f6, 4($v1)
/* 0D25A8 7F09DA78 460C3202 */  mul.s $f8, $f6, $f12
/* 0D25AC 7F09DA7C E7A80084 */  swc1  $f8, 0x84($sp)
/* 0D25B0 7F09DA80 C46A0008 */  lwc1  $f10, 8($v1)
/* 0D25B4 7F09DA84 460C5102 */  mul.s $f4, $f10, $f12
/* 0D25B8 7F09DA88 E7A40088 */  swc1  $f4, 0x88($sp)
/* 0D25BC 7F09DA8C C4660010 */  lwc1  $f6, 0x10($v1)
/* 0D25C0 7F09DA90 46003202 */  mul.s $f8, $f6, $f0
/* 0D25C4 7F09DA94 E7A80074 */  swc1  $f8, 0x74($sp)
/* 0D25C8 7F09DA98 C46A0014 */  lwc1  $f10, 0x14($v1)
/* 0D25CC 7F09DA9C 46005102 */  mul.s $f4, $f10, $f0
/* 0D25D0 7F09DAA0 E7A40078 */  swc1  $f4, 0x78($sp)
/* 0D25D4 7F09DAA4 C4660018 */  lwc1  $f6, 0x18($v1)
/* 0D25D8 7F09DAA8 46003202 */  mul.s $f8, $f6, $f0
/* 0D25DC 7F09DAAC E7A8007C */  swc1  $f8, 0x7c($sp)
/* 0D25E0 7F09DAB0 C46A0010 */  lwc1  $f10, 0x10($v1)
/* 0D25E4 7F09DAB4 460C5102 */  mul.s $f4, $f10, $f12
/* 0D25E8 7F09DAB8 E7A40068 */  swc1  $f4, 0x68($sp)
/* 0D25EC 7F09DABC C4660014 */  lwc1  $f6, 0x14($v1)
/* 0D25F0 7F09DAC0 460C3202 */  mul.s $f8, $f6, $f12
/* 0D25F4 7F09DAC4 E7A8006C */  swc1  $f8, 0x6c($sp)
/* 0D25F8 7F09DAC8 C46A0018 */  lwc1  $f10, 0x18($v1)
/* 0D25FC 7F09DACC 460C5102 */  mul.s $f4, $f10, $f12
/* 0D2600 7F09DAD0 0FC2D20F */  jal   get_room_data_float1
/* 0D2604 7F09DAD4 E7A40070 */   swc1  $f4, 0x70($sp)
/* 0D2608 7F09DAD8 C7A6004C */  lwc1  $f6, 0x4c($sp)
/* 0D260C 7F09DADC C7A8008C */  lwc1  $f8, 0x8c($sp)
/* 0D2610 7F09DAE0 C7A40068 */  lwc1  $f4, 0x68($sp)
/* 0D2614 7F09DAE4 46083281 */  sub.s $f10, $f6, $f8
/* 0D2618 7F09DAE8 46045181 */  sub.s $f6, $f10, $f4
/* 0D261C 7F09DAEC C62A0000 */  lwc1  $f10, ($s1)
/* 0D2620 7F09DAF0 46003202 */  mul.s $f8, $f6, $f0
/* 0D2624 7F09DAF4 460A4101 */  sub.s $f4, $f8, $f10
/* 0D2628 7F09DAF8 4600218D */  trunc.w.s $f6, $f4
/* 0D262C 7F09DAFC 440E3000 */  mfc1  $t6, $f6
/* 0D2630 7F09DB00 0FC2D20F */  jal   get_room_data_float1
/* 0D2634 7F09DB04 A60E0000 */   sh    $t6, ($s0)
/* 0D2638 7F09DB08 C7A80048 */  lwc1  $f8, 0x48($sp)
/* 0D263C 7F09DB0C C7AA0090 */  lwc1  $f10, 0x90($sp)
/* 0D2640 7F09DB10 C7A6006C */  lwc1  $f6, 0x6c($sp)
/* 0D2644 7F09DB14 460A4101 */  sub.s $f4, $f8, $f10
/* 0D2648 7F09DB18 46062201 */  sub.s $f8, $f4, $f6
/* 0D264C 7F09DB1C C6240004 */  lwc1  $f4, 4($s1)
/* 0D2650 7F09DB20 46004282 */  mul.s $f10, $f8, $f0
/* 0D2654 7F09DB24 46045181 */  sub.s $f6, $f10, $f4
/* 0D2658 7F09DB28 4600320D */  trunc.w.s $f8, $f6
/* 0D265C 7F09DB2C 440F4000 */  mfc1  $t7, $f8
/* 0D2660 7F09DB30 0FC2D20F */  jal   get_room_data_float1
/* 0D2664 7F09DB34 A60F0002 */   sh    $t7, 2($s0)
/* 0D2668 7F09DB38 C7AA0044 */  lwc1  $f10, 0x44($sp)
/* 0D266C 7F09DB3C C7A40094 */  lwc1  $f4, 0x94($sp)
/* 0D2670 7F09DB40 C7A80070 */  lwc1  $f8, 0x70($sp)
/* 0D2674 7F09DB44 240906E0 */  li    $t1, 1760
/* 0D2678 7F09DB48 46045181 */  sub.s $f6, $f10, $f4
/* 0D267C 7F09DB4C 46083281 */  sub.s $f10, $f6, $f8
/* 0D2680 7F09DB50 C6260008 */  lwc1  $f6, 8($s1)
/* 0D2684 7F09DB54 A6090008 */  sh    $t1, 8($s0)
/* 0D2688 7F09DB58 A600000A */  sh    $zero, 0xa($s0)
/* 0D268C 7F09DB5C 46005102 */  mul.s $f4, $f10, $f0
/* 0D2690 7F09DB60 46062201 */  sub.s $f8, $f4, $f6
/* 0D2694 7F09DB64 4600428D */  trunc.w.s $f10, $f8
/* 0D2698 7F09DB68 44085000 */  mfc1  $t0, $f10
/* 0D269C 7F09DB6C 0FC2D20F */  jal   get_room_data_float1
/* 0D26A0 7F09DB70 A6080004 */   sh    $t0, 4($s0)
/* 0D26A4 7F09DB74 C7A4004C */  lwc1  $f4, 0x4c($sp)
/* 0D26A8 7F09DB78 C7A60080 */  lwc1  $f6, 0x80($sp)
/* 0D26AC 7F09DB7C C7AA0074 */  lwc1  $f10, 0x74($sp)
/* 0D26B0 7F09DB80 46062200 */  add.s $f8, $f4, $f6
/* 0D26B4 7F09DB84 460A4101 */  sub.s $f4, $f8, $f10
/* 0D26B8 7F09DB88 C6280000 */  lwc1  $f8, ($s1)
/* 0D26BC 7F09DB8C 46002182 */  mul.s $f6, $f4, $f0
/* 0D26C0 7F09DB90 46083281 */  sub.s $f10, $f6, $f8
/* 0D26C4 7F09DB94 4600510D */  trunc.w.s $f4, $f10
/* 0D26C8 7F09DB98 440B2000 */  mfc1  $t3, $f4
/* 0D26CC 7F09DB9C 0FC2D20F */  jal   get_room_data_float1
/* 0D26D0 7F09DBA0 A60B0010 */   sh    $t3, 0x10($s0)
/* 0D26D4 7F09DBA4 C7A60048 */  lwc1  $f6, 0x48($sp)
/* 0D26D8 7F09DBA8 C7A80084 */  lwc1  $f8, 0x84($sp)
/* 0D26DC 7F09DBAC C7A40078 */  lwc1  $f4, 0x78($sp)
/* 0D26E0 7F09DBB0 46083280 */  add.s $f10, $f6, $f8
/* 0D26E4 7F09DBB4 46045181 */  sub.s $f6, $f10, $f4
/* 0D26E8 7F09DBB8 C62A0004 */  lwc1  $f10, 4($s1)
/* 0D26EC 7F09DBBC 46003202 */  mul.s $f8, $f6, $f0
/* 0D26F0 7F09DBC0 460A4101 */  sub.s $f4, $f8, $f10
/* 0D26F4 7F09DBC4 4600218D */  trunc.w.s $f6, $f4
/* 0D26F8 7F09DBC8 44193000 */  mfc1  $t9, $f6
/* 0D26FC 7F09DBCC 0FC2D20F */  jal   get_room_data_float1
/* 0D2700 7F09DBD0 A6190012 */   sh    $t9, 0x12($s0)
/* 0D2704 7F09DBD4 C7A80044 */  lwc1  $f8, 0x44($sp)
/* 0D2708 7F09DBD8 C7AA0088 */  lwc1  $f10, 0x88($sp)
/* 0D270C 7F09DBDC C7A6007C */  lwc1  $f6, 0x7c($sp)
/* 0D2710 7F09DBE0 460A4100 */  add.s $f4, $f8, $f10
/* 0D2714 7F09DBE4 46062201 */  sub.s $f8, $f4, $f6
/* 0D2718 7F09DBE8 C6240008 */  lwc1  $f4, 8($s1)
/* 0D271C 7F09DBEC A6000018 */  sh    $zero, 0x18($s0)
/* 0D2720 7F09DBF0 A600001A */  sh    $zero, 0x1a($s0)
/* 0D2724 7F09DBF4 46004282 */  mul.s $f10, $f8, $f0
/* 0D2728 7F09DBF8 46045181 */  sub.s $f6, $f10, $f4
/* 0D272C 7F09DBFC 4600320D */  trunc.w.s $f8, $f6
/* 0D2730 7F09DC00 44184000 */  mfc1  $t8, $f8
/* 0D2734 7F09DC04 0FC2D20F */  jal   get_room_data_float1
/* 0D2738 7F09DC08 A6180014 */   sh    $t8, 0x14($s0)
/* 0D273C 7F09DC0C C7AA004C */  lwc1  $f10, 0x4c($sp)
/* 0D2740 7F09DC10 C7A4008C */  lwc1  $f4, 0x8c($sp)
/* 0D2744 7F09DC14 C7A80068 */  lwc1  $f8, 0x68($sp)
/* 0D2748 7F09DC18 46045180 */  add.s $f6, $f10, $f4
/* 0D274C 7F09DC1C 46083280 */  add.s $f10, $f6, $f8
/* 0D2750 7F09DC20 C6260000 */  lwc1  $f6, ($s1)
/* 0D2754 7F09DC24 46005102 */  mul.s $f4, $f10, $f0
/* 0D2758 7F09DC28 46062201 */  sub.s $f8, $f4, $f6
/* 0D275C 7F09DC2C 4600428D */  trunc.w.s $f10, $f8
/* 0D2760 7F09DC30 440A5000 */  mfc1  $t2, $f10
/* 0D2764 7F09DC34 0FC2D20F */  jal   get_room_data_float1
/* 0D2768 7F09DC38 A60A0020 */   sh    $t2, 0x20($s0)
/* 0D276C 7F09DC3C C7A40048 */  lwc1  $f4, 0x48($sp)
/* 0D2770 7F09DC40 C7A60090 */  lwc1  $f6, 0x90($sp)
/* 0D2774 7F09DC44 C7AA006C */  lwc1  $f10, 0x6c($sp)
/* 0D2778 7F09DC48 46062200 */  add.s $f8, $f4, $f6
/* 0D277C 7F09DC4C 460A4100 */  add.s $f4, $f8, $f10
/* 0D2780 7F09DC50 C6280004 */  lwc1  $f8, 4($s1)
/* 0D2784 7F09DC54 46002182 */  mul.s $f6, $f4, $f0
/* 0D2788 7F09DC58 46083281 */  sub.s $f10, $f6, $f8
/* 0D278C 7F09DC5C 4600510D */  trunc.w.s $f4, $f10
/* 0D2790 7F09DC60 44092000 */  mfc1  $t1, $f4
/* 0D2794 7F09DC64 0FC2D20F */  jal   get_room_data_float1
/* 0D2798 7F09DC68 A6090022 */   sh    $t1, 0x22($s0)
/* 0D279C 7F09DC6C C7A60044 */  lwc1  $f6, 0x44($sp)
/* 0D27A0 7F09DC70 C7A80094 */  lwc1  $f8, 0x94($sp)
/* 0D27A4 7F09DC74 C7A40070 */  lwc1  $f4, 0x70($sp)
/* 0D27A8 7F09DC78 240C06E0 */  li    $t4, 1760
/* 0D27AC 7F09DC7C 46083280 */  add.s $f10, $f6, $f8
/* 0D27B0 7F09DC80 46045180 */  add.s $f6, $f10, $f4
/* 0D27B4 7F09DC84 C62A0008 */  lwc1  $f10, 8($s1)
/* 0D27B8 7F09DC88 A6000028 */  sh    $zero, 0x28($s0)
/* 0D27BC 7F09DC8C A60C002A */  sh    $t4, 0x2a($s0)
/* 0D27C0 7F09DC90 46003202 */  mul.s $f8, $f6, $f0
/* 0D27C4 7F09DC94 460A4101 */  sub.s $f4, $f8, $f10
/* 0D27C8 7F09DC98 4600218D */  trunc.w.s $f6, $f4
/* 0D27CC 7F09DC9C 440B3000 */  mfc1  $t3, $f6
/* 0D27D0 7F09DCA0 0FC2D20F */  jal   get_room_data_float1
/* 0D27D4 7F09DCA4 A60B0024 */   sh    $t3, 0x24($s0)
/* 0D27D8 7F09DCA8 C7A8004C */  lwc1  $f8, 0x4c($sp)
/* 0D27DC 7F09DCAC C7AA0080 */  lwc1  $f10, 0x80($sp)
/* 0D27E0 7F09DCB0 C7A60074 */  lwc1  $f6, 0x74($sp)
/* 0D27E4 7F09DCB4 460A4101 */  sub.s $f4, $f8, $f10
/* 0D27E8 7F09DCB8 46062200 */  add.s $f8, $f4, $f6
/* 0D27EC 7F09DCBC C6240000 */  lwc1  $f4, ($s1)
/* 0D27F0 7F09DCC0 46004282 */  mul.s $f10, $f8, $f0
/* 0D27F4 7F09DCC4 46045181 */  sub.s $f6, $f10, $f4
/* 0D27F8 7F09DCC8 4600320D */  trunc.w.s $f8, $f6
/* 0D27FC 7F09DCCC 440E4000 */  mfc1  $t6, $f8
/* 0D2800 7F09DCD0 0FC2D20F */  jal   get_room_data_float1
/* 0D2804 7F09DCD4 A60E0030 */   sh    $t6, 0x30($s0)
/* 0D2808 7F09DCD8 C7AA0048 */  lwc1  $f10, 0x48($sp)
/* 0D280C 7F09DCDC C7A40084 */  lwc1  $f4, 0x84($sp)
/* 0D2810 7F09DCE0 C7A80078 */  lwc1  $f8, 0x78($sp)
/* 0D2814 7F09DCE4 46045181 */  sub.s $f6, $f10, $f4
/* 0D2818 7F09DCE8 46083280 */  add.s $f10, $f6, $f8
/* 0D281C 7F09DCEC C6260004 */  lwc1  $f6, 4($s1)
/* 0D2820 7F09DCF0 46005102 */  mul.s $f4, $f10, $f0
/* 0D2824 7F09DCF4 46062201 */  sub.s $f8, $f4, $f6
/* 0D2828 7F09DCF8 4600428D */  trunc.w.s $f10, $f8
/* 0D282C 7F09DCFC 440F5000 */  mfc1  $t7, $f10
/* 0D2830 7F09DD00 0FC2D20F */  jal   get_room_data_float1
/* 0D2834 7F09DD04 A60F0032 */   sh    $t7, 0x32($s0)
/* 0D2838 7F09DD08 C7A40044 */  lwc1  $f4, 0x44($sp)
/* 0D283C 7F09DD0C C7A60088 */  lwc1  $f6, 0x88($sp)
/* 0D2840 7F09DD10 C7AA007C */  lwc1  $f10, 0x7c($sp)
/* 0D2844 7F09DD14 240906E0 */  li    $t1, 1760
/* 0D2848 7F09DD18 46062201 */  sub.s $f8, $f4, $f6
/* 0D284C 7F09DD1C 240D06E0 */  li    $t5, 1760
/* 0D2850 7F09DD20 3C0B0430 */  lui   $t3, (0x04300040 >> 16) # lui $t3, 0x430
/* 0D2854 7F09DD24 356B0040 */  ori   $t3, (0x04300040 & 0xFFFF) # ori $t3, $t3, 0x40
/* 0D2858 7F09DD28 460A4100 */  add.s $f4, $f8, $f10
/* 0D285C 7F09DD2C C6280008 */  lwc1  $f8, 8($s1)
/* 0D2860 7F09DD30 A6090038 */  sh    $t1, 0x38($s0)
/* 0D2864 7F09DD34 A60D003A */  sh    $t5, 0x3a($s0)
/* 0D2868 7F09DD38 46002182 */  mul.s $f6, $f4, $f0
/* 0D286C 7F09DD3C 02402825 */  move  $a1, $s2
/* 0D2870 7F09DD40 26520008 */  addiu $s2, $s2, 8
/* 0D2874 7F09DD44 02002025 */  move  $a0, $s0
/* 0D2878 7F09DD48 46083281 */  sub.s $f10, $f6, $f8
/* 0D287C 7F09DD4C 4600510D */  trunc.w.s $f4, $f10
/* 0D2880 7F09DD50 44082000 */  mfc1  $t0, $f4
/* 0D2884 7F09DD54 00000000 */  nop   
/* 0D2888 7F09DD58 A6080034 */  sh    $t0, 0x34($s0)
/* 0D288C 7F09DD5C ACAB0000 */  sw    $t3, ($a1)
/* 0D2890 7F09DD60 0C003A2C */  jal   osVirtualToPhysical
/* 0D2894 7F09DD64 AFA50038 */   sw    $a1, 0x38($sp)
/* 0D2898 7F09DD68 8FA50038 */  lw    $a1, 0x38($sp)
/* 0D289C 7F09DD6C 02401825 */  move  $v1, $s2
/* 0D28A0 7F09DD70 3C0CB100 */  lui   $t4, (0xB1000032 >> 16) # lui $t4, 0xb100
/* 0D28A4 7F09DD74 ACA20004 */  sw    $v0, 4($a1)
/* 0D28A8 7F09DD78 358C0032 */  ori   $t4, (0xB1000032 & 0xFFFF) # ori $t4, $t4, 0x32
/* 0D28AC 7F09DD7C 24192010 */  li    $t9, 8208
/* 0D28B0 7F09DD80 AC790004 */  sw    $t9, 4($v1)
/* 0D28B4 7F09DD84 AC6C0000 */  sw    $t4, ($v1)
/* 0D28B8 7F09DD88 8FBF0024 */  lw    $ra, 0x24($sp)
/* 0D28BC 7F09DD8C 26420008 */  addiu $v0, $s2, 8
/* 0D28C0 7F09DD90 8FB20020 */  lw    $s2, 0x20($sp)
/* 0D28C4 7F09DD94 8FB1001C */  lw    $s1, 0x1c($sp)
/* 0D28C8 7F09DD98 8FB00018 */  lw    $s0, 0x18($sp)
/* 0D28CC 7F09DD9C 03E00008 */  jr    $ra
/* 0D28D0 7F09DDA0 27BD00B8 */   addiu $sp, $sp, 0xb8
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F09DDA4(void) {

}
#else
GLOBAL_ASM(
.late_rodata
glabel D_800576C0
.word 0x46ea6000 /*30000.0*/
glabel D_800576C4
.word 0x46ea6000 /*30000.0*/
glabel D_800576C8
.word 0xc6ea6000 /*-30000.0*/
.text
glabel sub_GAME_7F09DDA4
/* 0D28D4 7F09DDA4 27BDFF28 */  addiu $sp, $sp, -0xd8
/* 0D28D8 7F09DDA8 3C0F8004 */  lui   $t7, %hi(D_80040910) 
/* 0D28DC 7F09DDAC AFBF0034 */  sw    $ra, 0x34($sp)
/* 0D28E0 7F09DDB0 AFB50030 */  sw    $s5, 0x30($sp)
/* 0D28E4 7F09DDB4 AFB4002C */  sw    $s4, 0x2c($sp)
/* 0D28E8 7F09DDB8 AFB30028 */  sw    $s3, 0x28($sp)
/* 0D28EC 7F09DDBC AFB20024 */  sw    $s2, 0x24($sp)
/* 0D28F0 7F09DDC0 AFB10020 */  sw    $s1, 0x20($sp)
/* 0D28F4 7F09DDC4 AFB0001C */  sw    $s0, 0x1c($sp)
/* 0D28F8 7F09DDC8 F7B40010 */  sdc1  $f20, 0x10($sp)
/* 0D28FC 7F09DDCC AFA600E0 */  sw    $a2, 0xe0($sp)
/* 0D2900 7F09DDD0 25EF0910 */  addiu $t7, %lo(D_80040910) # addiu $t7, $t7, 0x910
/* 0D2904 7F09DDD4 8DE10000 */  lw    $at, ($t7)
/* 0D2908 7F09DDD8 8DE80004 */  lw    $t0, 4($t7)
/* 0D290C 7F09DDDC 27AE00C0 */  addiu $t6, $sp, 0xc0
/* 0D2910 7F09DDE0 ADC10000 */  sw    $at, ($t6)
/* 0D2914 7F09DDE4 ADC80004 */  sw    $t0, 4($t6)
/* 0D2918 7F09DDE8 8DE8000C */  lw    $t0, 0xc($t7)
/* 0D291C 7F09DDEC 8DE10008 */  lw    $at, 8($t7)
/* 0D2920 7F09DDF0 00A08825 */  move  $s1, $a1
/* 0D2924 7F09DDF4 00809025 */  move  $s2, $a0
/* 0D2928 7F09DDF8 00E09825 */  move  $s3, $a3
/* 0D292C 7F09DDFC ADC8000C */  sw    $t0, 0xc($t6)
/* 0D2930 7F09DE00 0FC1E111 */  jal   currentPlayerGetMatrix10D4
/* 0D2934 7F09DE04 ADC10008 */   sw    $at, 8($t6)
/* 0D2938 7F09DE08 0FC227F5 */  jal   bondviewGetCurrentPlayersPosition
/* 0D293C 7F09DE0C AFA200BC */   sw    $v0, 0xbc($sp)
/* 0D2940 7F09DE10 AFA20070 */  sw    $v0, 0x70($sp)
/* 0D2944 7F09DE14 86490006 */  lh    $t1, 6($s2)
/* 0D2948 7F09DE18 24150018 */  li    $s5, 24
/* 0D294C 7F09DE1C 3C148004 */  lui   $s4, %hi(array_smoke_types)
/* 0D2950 7F09DE20 01350019 */  multu $t1, $s5
/* 0D2954 7F09DE24 2694017C */  addiu $s4, %lo(array_smoke_types) # addiu $s4, $s4, 0x17c
/* 0D2958 7F09DE28 86250024 */  lh    $a1, 0x24($s1)
/* 0D295C 7F09DE2C 8FA300BC */  lw    $v1, 0xbc($sp)
/* 0D2960 7F09DE30 24180001 */  li    $t8, 1
/* 0D2964 7F09DE34 00005012 */  mflo  $t2
/* 0D2968 7F09DE38 028A5821 */  addu  $t3, $s4, $t2
/* 0D296C 7F09DE3C 85640002 */  lh    $a0, 2($t3)
/* 0D2970 7F09DE40 0085082A */  slt   $at, $a0, $a1
/* 0D2974 7F09DE44 5420002C */  bnezl $at, .L7F09DEF8
/* 0D2978 7F09DE48 4459F800 */   cfc1  $t9, $31
/* 0D297C 7F09DE4C 44843000 */  mtc1  $a0, $f6
/* 0D2980 7F09DE50 C6240020 */  lwc1  $f4, 0x20($s1)
/* 0D2984 7F09DE54 240D0001 */  li    $t5, 1
/* 0D2988 7F09DE58 46803220 */  cvt.s.w $f8, $f6
/* 0D298C 7F09DE5C 44853000 */  mtc1  $a1, $f6
/* 0D2990 7F09DE60 3C014F00 */  li    $at, 0x4F000000 # 2147483648.000000
/* 0D2994 7F09DE64 46082283 */  div.s $f10, $f4, $f8
/* 0D2998 7F09DE68 46803120 */  cvt.s.w $f4, $f6
/* 0D299C 7F09DE6C 46045202 */  mul.s $f8, $f10, $f4
/* 0D29A0 7F09DE70 444CF800 */  cfc1  $t4, $31
/* 0D29A4 7F09DE74 44CDF800 */  ctc1  $t5, $31
/* 0D29A8 7F09DE78 00000000 */  nop   
/* 0D29AC 7F09DE7C 460041A4 */  cvt.w.s $f6, $f8
/* 0D29B0 7F09DE80 444DF800 */  cfc1  $t5, $31
/* 0D29B4 7F09DE84 00000000 */  nop   
/* 0D29B8 7F09DE88 31AD0078 */  andi  $t5, $t5, 0x78
/* 0D29BC 7F09DE8C 51A00013 */  beql  $t5, $zero, .L7F09DEDC
/* 0D29C0 7F09DE90 440D3000 */   mfc1  $t5, $f6
/* 0D29C4 7F09DE94 44813000 */  mtc1  $at, $f6
/* 0D29C8 7F09DE98 240D0001 */  li    $t5, 1
/* 0D29CC 7F09DE9C 46064181 */  sub.s $f6, $f8, $f6
/* 0D29D0 7F09DEA0 44CDF800 */  ctc1  $t5, $31
/* 0D29D4 7F09DEA4 00000000 */  nop   
/* 0D29D8 7F09DEA8 460031A4 */  cvt.w.s $f6, $f6
/* 0D29DC 7F09DEAC 444DF800 */  cfc1  $t5, $31
/* 0D29E0 7F09DEB0 00000000 */  nop   
/* 0D29E4 7F09DEB4 31AD0078 */  andi  $t5, $t5, 0x78
/* 0D29E8 7F09DEB8 15A00005 */  bnez  $t5, .L7F09DED0
/* 0D29EC 7F09DEBC 00000000 */   nop   
/* 0D29F0 7F09DEC0 440D3000 */  mfc1  $t5, $f6
/* 0D29F4 7F09DEC4 3C018000 */  lui   $at, 0x8000
/* 0D29F8 7F09DEC8 10000007 */  b     .L7F09DEE8
/* 0D29FC 7F09DECC 01A16825 */   or    $t5, $t5, $at
.L7F09DED0:
/* 0D2A00 7F09DED0 10000005 */  b     .L7F09DEE8
/* 0D2A04 7F09DED4 240DFFFF */   li    $t5, -1
/* 0D2A08 7F09DED8 440D3000 */  mfc1  $t5, $f6
.L7F09DEDC:
/* 0D2A0C 7F09DEDC 00000000 */  nop   
/* 0D2A10 7F09DEE0 05A0FFFB */  bltz  $t5, .L7F09DED0
/* 0D2A14 7F09DEE4 00000000 */   nop   
.L7F09DEE8:
/* 0D2A18 7F09DEE8 44CCF800 */  ctc1  $t4, $31
/* 0D2A1C 7F09DEEC 10000023 */  b     .L7F09DF7C
/* 0D2A20 7F09DEF0 A3AD0077 */   sb    $t5, 0x77($sp)
/* 0D2A24 7F09DEF4 4459F800 */  cfc1  $t9, $31
.L7F09DEF8:
/* 0D2A28 7F09DEF8 44D8F800 */  ctc1  $t8, $31
/* 0D2A2C 7F09DEFC C62A0020 */  lwc1  $f10, 0x20($s1)
/* 0D2A30 7F09DF00 3C014F00 */  li    $at, 0x4F000000 # 2147483648.000000
/* 0D2A34 7F09DF04 46005124 */  cvt.w.s $f4, $f10
/* 0D2A38 7F09DF08 4458F800 */  cfc1  $t8, $31
/* 0D2A3C 7F09DF0C 00000000 */  nop   
/* 0D2A40 7F09DF10 33180078 */  andi  $t8, $t8, 0x78
/* 0D2A44 7F09DF14 53000013 */  beql  $t8, $zero, .L7F09DF64
/* 0D2A48 7F09DF18 44182000 */   mfc1  $t8, $f4
/* 0D2A4C 7F09DF1C 44812000 */  mtc1  $at, $f4
/* 0D2A50 7F09DF20 24180001 */  li    $t8, 1
/* 0D2A54 7F09DF24 46045101 */  sub.s $f4, $f10, $f4
/* 0D2A58 7F09DF28 44D8F800 */  ctc1  $t8, $31
/* 0D2A5C 7F09DF2C 00000000 */  nop   
/* 0D2A60 7F09DF30 46002124 */  cvt.w.s $f4, $f4
/* 0D2A64 7F09DF34 4458F800 */  cfc1  $t8, $31
/* 0D2A68 7F09DF38 00000000 */  nop   
/* 0D2A6C 7F09DF3C 33180078 */  andi  $t8, $t8, 0x78
/* 0D2A70 7F09DF40 17000005 */  bnez  $t8, .L7F09DF58
/* 0D2A74 7F09DF44 00000000 */   nop   
/* 0D2A78 7F09DF48 44182000 */  mfc1  $t8, $f4
/* 0D2A7C 7F09DF4C 3C018000 */  lui   $at, 0x8000
/* 0D2A80 7F09DF50 10000007 */  b     .L7F09DF70
/* 0D2A84 7F09DF54 0301C025 */   or    $t8, $t8, $at
.L7F09DF58:
/* 0D2A88 7F09DF58 10000005 */  b     .L7F09DF70
/* 0D2A8C 7F09DF5C 2418FFFF */   li    $t8, -1
/* 0D2A90 7F09DF60 44182000 */  mfc1  $t8, $f4
.L7F09DF64:
/* 0D2A94 7F09DF64 00000000 */  nop   
/* 0D2A98 7F09DF68 0700FFFB */  bltz  $t8, .L7F09DF58
/* 0D2A9C 7F09DF6C 00000000 */   nop   
.L7F09DF70:
/* 0D2AA0 7F09DF70 44D9F800 */  ctc1  $t9, $31
/* 0D2AA4 7F09DF74 A3B80077 */  sb    $t8, 0x77($sp)
/* 0D2AA8 7F09DF78 00000000 */  nop   
.L7F09DF7C:
/* 0D2AAC 7F09DF7C 24040004 */  li    $a0, 4
/* 0D2AB0 7F09DF80 0FC2F5B1 */  jal   dynAllocate7F0BD6C4
/* 0D2AB4 7F09DF84 AFA300BC */   sw    $v1, 0xbc($sp)
/* 0D2AB8 7F09DF88 27A400C0 */  addiu $a0, $sp, 0xc0
/* 0D2ABC 7F09DF8C 8C810000 */  lw    $at, ($a0)
/* 0D2AC0 7F09DF90 00408025 */  move  $s0, $v0
/* 0D2AC4 7F09DF94 AC410000 */  sw    $at, ($v0)
/* 0D2AC8 7F09DF98 8C880004 */  lw    $t0, 4($a0)
/* 0D2ACC 7F09DF9C AC480004 */  sw    $t0, 4($v0)
/* 0D2AD0 7F09DFA0 8C810008 */  lw    $at, 8($a0)
/* 0D2AD4 7F09DFA4 AC410008 */  sw    $at, 8($v0)
/* 0D2AD8 7F09DFA8 8C88000C */  lw    $t0, 0xc($a0)
/* 0D2ADC 7F09DFAC AC48000C */  sw    $t0, 0xc($v0)
/* 0D2AE0 7F09DFB0 8C810000 */  lw    $at, ($a0)
/* 0D2AE4 7F09DFB4 AC410010 */  sw    $at, 0x10($v0)
/* 0D2AE8 7F09DFB8 8C8B0004 */  lw    $t3, 4($a0)
/* 0D2AEC 7F09DFBC AC4B0014 */  sw    $t3, 0x14($v0)
/* 0D2AF0 7F09DFC0 8C810008 */  lw    $at, 8($a0)
/* 0D2AF4 7F09DFC4 AC410018 */  sw    $at, 0x18($v0)
/* 0D2AF8 7F09DFC8 8C8B000C */  lw    $t3, 0xc($a0)
/* 0D2AFC 7F09DFCC AC4B001C */  sw    $t3, 0x1c($v0)
/* 0D2B00 7F09DFD0 8C810000 */  lw    $at, ($a0)
/* 0D2B04 7F09DFD4 AC410020 */  sw    $at, 0x20($v0)
/* 0D2B08 7F09DFD8 8C990004 */  lw    $t9, 4($a0)
/* 0D2B0C 7F09DFDC AC590024 */  sw    $t9, 0x24($v0)
/* 0D2B10 7F09DFE0 8C810008 */  lw    $at, 8($a0)
/* 0D2B14 7F09DFE4 AC410028 */  sw    $at, 0x28($v0)
/* 0D2B18 7F09DFE8 8C99000C */  lw    $t9, 0xc($a0)
/* 0D2B1C 7F09DFEC AC59002C */  sw    $t9, 0x2c($v0)
/* 0D2B20 7F09DFF0 8C810000 */  lw    $at, ($a0)
/* 0D2B24 7F09DFF4 AC410030 */  sw    $at, 0x30($v0)
/* 0D2B28 7F09DFF8 8C8E0004 */  lw    $t6, 4($a0)
/* 0D2B2C 7F09DFFC AC4E0034 */  sw    $t6, 0x34($v0)
/* 0D2B30 7F09E000 8C810008 */  lw    $at, 8($a0)
/* 0D2B34 7F09E004 AC410038 */  sw    $at, 0x38($v0)
/* 0D2B38 7F09E008 8C8E000C */  lw    $t6, 0xc($a0)
/* 0D2B3C 7F09E00C AC4E003C */  sw    $t6, 0x3c($v0)
/* 0D2B40 7F09E010 0FC15FA8 */  jal   cosf
/* 0D2B44 7F09E014 C62C0010 */   lwc1  $f12, 0x10($s1)
/* 0D2B48 7F09E018 C628000C */  lwc1  $f8, 0xc($s1)
/* 0D2B4C 7F09E01C C62C0010 */  lwc1  $f12, 0x10($s1)
/* 0D2B50 7F09E020 46080382 */  mul.s $f14, $f0, $f8
/* 0D2B54 7F09E024 0FC15FAB */  jal   sinf
/* 0D2B58 7F09E028 E7AE0088 */   swc1  $f14, 0x88($sp)
/* 0D2B5C 7F09E02C C626000C */  lwc1  $f6, 0xc($s1)
/* 0D2B60 7F09E030 C62C0018 */  lwc1  $f12, 0x18($s1)
/* 0D2B64 7F09E034 46060402 */  mul.s $f16, $f0, $f6
/* 0D2B68 7F09E038 0FC15FAB */  jal   sinf
/* 0D2B6C 7F09E03C E7B00084 */   swc1  $f16, 0x84($sp)
/* 0D2B70 7F09E040 3C0140E0 */  li    $at, 0x40E00000 # 7.000000
/* 0D2B74 7F09E044 44815000 */  mtc1  $at, $f10
/* 0D2B78 7F09E048 C6280000 */  lwc1  $f8, ($s1)
/* 0D2B7C 7F09E04C 460A0102 */  mul.s $f4, $f0, $f10
/* 0D2B80 7F09E050 46082180 */  add.s $f6, $f4, $f8
/* 0D2B84 7F09E054 E7A60080 */  swc1  $f6, 0x80($sp)
/* 0D2B88 7F09E058 C62A0004 */  lwc1  $f10, 4($s1)
/* 0D2B8C 7F09E05C E7AA007C */  swc1  $f10, 0x7c($sp)
/* 0D2B90 7F09E060 0FC15FAB */  jal   sinf
/* 0D2B94 7F09E064 C62C001C */   lwc1  $f12, 0x1c($s1)
/* 0D2B98 7F09E068 3C0140E0 */  li    $at, 0x40E00000 # 7.000000
/* 0D2B9C 7F09E06C 44812000 */  mtc1  $at, $f4
/* 0D2BA0 7F09E070 C6260008 */  lwc1  $f6, 8($s1)
/* 0D2BA4 7F09E074 8FA20070 */  lw    $v0, 0x70($sp)
/* 0D2BA8 7F09E078 46040202 */  mul.s $f8, $f0, $f4
/* 0D2BAC 7F09E07C C7A40080 */  lwc1  $f4, 0x80($sp)
/* 0D2BB0 7F09E080 46064280 */  add.s $f10, $f8, $f6
/* 0D2BB4 7F09E084 C7A6007C */  lwc1  $f6, 0x7c($sp)
/* 0D2BB8 7F09E088 E7AA0078 */  swc1  $f10, 0x78($sp)
/* 0D2BBC 7F09E08C C4480000 */  lwc1  $f8, ($v0)
/* 0D2BC0 7F09E090 46082501 */  sub.s $f20, $f4, $f8
/* 0D2BC4 7F09E094 C4440004 */  lwc1  $f4, 4($v0)
/* 0D2BC8 7F09E098 C4480008 */  lwc1  $f8, 8($v0)
/* 0D2BCC 7F09E09C 46043481 */  sub.s $f18, $f6, $f4
/* 0D2BD0 7F09E0A0 4614A182 */  mul.s $f6, $f20, $f20
/* 0D2BD4 7F09E0A4 46085081 */  sub.s $f2, $f10, $f8
/* 0D2BD8 7F09E0A8 46129102 */  mul.s $f4, $f18, $f18
/* 0D2BDC 7F09E0AC E7B20068 */  swc1  $f18, 0x68($sp)
/* 0D2BE0 7F09E0B0 46021202 */  mul.s $f8, $f2, $f2
/* 0D2BE4 7F09E0B4 E7A20064 */  swc1  $f2, 0x64($sp)
/* 0D2BE8 7F09E0B8 46043280 */  add.s $f10, $f6, $f4
/* 0D2BEC 7F09E0BC 0C007DF8 */  jal   sqrtf
/* 0D2BF0 7F09E0C0 46085300 */   add.s $f12, $f10, $f8
/* 0D2BF4 7F09E0C4 3C018005 */  lui    $at, %hi(D_800576C0)
/* 0D2BF8 7F09E0C8 C42676C0 */  lwc1  $f6, %lo(D_800576C0)($at)
/* 0D2BFC 7F09E0CC 8FA300BC */  lw    $v1, 0xbc($sp)
/* 0D2C00 7F09E0D0 C7AE0088 */  lwc1  $f14, 0x88($sp)
/* 0D2C04 7F09E0D4 4600303C */  c.lt.s $f6, $f0
/* 0D2C08 7F09E0D8 C7B00084 */  lwc1  $f16, 0x84($sp)
/* 0D2C0C 7F09E0DC C7B20068 */  lwc1  $f18, 0x68($sp)
/* 0D2C10 7F09E0E0 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 0D2C14 7F09E0E4 45020004 */  bc1fl .L7F09E0F8
/* 0D2C18 7F09E0E8 44812000 */   mtc1  $at, $f4
/* 0D2C1C 7F09E0EC 1000017A */  b     .L7F09E6D8
/* 0D2C20 7F09E0F0 8FA200E0 */   lw    $v0, 0xe0($sp)
/* 0D2C24 7F09E0F4 44812000 */  mtc1  $at, $f4
.L7F09E0F8:
/* 0D2C28 7F09E0F8 3C0142C8 */  li    $at, 0x42C80000 # 100.000000
/* 0D2C2C 7F09E0FC 44815000 */  mtc1  $at, $f10
/* 0D2C30 7F09E100 46040302 */  mul.s $f12, $f0, $f4
/* 0D2C34 7F09E104 44804000 */  mtc1  $zero, $f8
/* 0D2C38 7F09E108 3C0142C8 */  li    $at, 0x42C80000 # 100.000000
/* 0D2C3C 7F09E10C 460C503C */  c.lt.s $f10, $f12
/* 0D2C40 7F09E110 00000000 */  nop   
/* 0D2C44 7F09E114 45020004 */  bc1fl .L7F09E128
/* 0D2C48 7F09E118 46080032 */   c.eq.s $f0, $f8
/* 0D2C4C 7F09E11C 44816000 */  mtc1  $at, $f12
/* 0D2C50 7F09E120 00000000 */  nop   
/* 0D2C54 7F09E124 46080032 */  c.eq.s $f0, $f8
.L7F09E128:
/* 0D2C58 7F09E128 00000000 */  nop   
/* 0D2C5C 7F09E12C 45020005 */  bc1fl .L7F09E144
/* 0D2C60 7F09E130 460C0181 */   sub.s $f6, $f0, $f12
/* 0D2C64 7F09E134 44801000 */  mtc1  $zero, $f2
/* 0D2C68 7F09E138 10000003 */  b     .L7F09E148
/* 0D2C6C 7F09E13C 00000000 */   nop   
/* 0D2C70 7F09E140 460C0181 */  sub.s $f6, $f0, $f12
.L7F09E144:
/* 0D2C74 7F09E144 46003083 */  div.s $f2, $f6, $f0
.L7F09E148:
/* 0D2C78 7F09E148 46027382 */  mul.s $f14, $f14, $f2
/* 0D2C7C 7F09E14C 8FA20070 */  lw    $v0, 0x70($sp)
/* 0D2C80 7F09E150 46028402 */  mul.s $f16, $f16, $f2
/* 0D2C84 7F09E154 C4440000 */  lwc1  $f4, ($v0)
/* 0D2C88 7F09E158 4602A282 */  mul.s $f10, $f20, $f2
/* 0D2C8C 7F09E15C 460A2200 */  add.s $f8, $f4, $f10
/* 0D2C90 7F09E160 46029102 */  mul.s $f4, $f18, $f2
/* 0D2C94 7F09E164 E7A80080 */  swc1  $f8, 0x80($sp)
/* 0D2C98 7F09E168 C4460004 */  lwc1  $f6, 4($v0)
/* 0D2C9C 7F09E16C 46043280 */  add.s $f10, $f6, $f4
/* 0D2CA0 7F09E170 C7A60064 */  lwc1  $f6, 0x64($sp)
/* 0D2CA4 7F09E174 46023102 */  mul.s $f4, $f6, $f2
/* 0D2CA8 7F09E178 E7AA007C */  swc1  $f10, 0x7c($sp)
/* 0D2CAC 7F09E17C C4480008 */  lwc1  $f8, 8($v0)
/* 0D2CB0 7F09E180 46044280 */  add.s $f10, $f8, $f4
/* 0D2CB4 7F09E184 E7AA0078 */  swc1  $f10, 0x78($sp)
/* 0D2CB8 7F09E188 C4660000 */  lwc1  $f6, ($v1)
/* 0D2CBC 7F09E18C 460E3202 */  mul.s $f8, $f6, $f14
/* 0D2CC0 7F09E190 E7A800B0 */  swc1  $f8, 0xb0($sp)
/* 0D2CC4 7F09E194 C4640004 */  lwc1  $f4, 4($v1)
/* 0D2CC8 7F09E198 460E2282 */  mul.s $f10, $f4, $f14
/* 0D2CCC 7F09E19C E7AA00B4 */  swc1  $f10, 0xb4($sp)
/* 0D2CD0 7F09E1A0 C4660008 */  lwc1  $f6, 8($v1)
/* 0D2CD4 7F09E1A4 460E3202 */  mul.s $f8, $f6, $f14
/* 0D2CD8 7F09E1A8 E7A800B8 */  swc1  $f8, 0xb8($sp)
/* 0D2CDC 7F09E1AC C4640000 */  lwc1  $f4, ($v1)
/* 0D2CE0 7F09E1B0 46102282 */  mul.s $f10, $f4, $f16
/* 0D2CE4 7F09E1B4 E7AA00A4 */  swc1  $f10, 0xa4($sp)
/* 0D2CE8 7F09E1B8 C4660004 */  lwc1  $f6, 4($v1)
/* 0D2CEC 7F09E1BC 46103202 */  mul.s $f8, $f6, $f16
/* 0D2CF0 7F09E1C0 E7A800A8 */  swc1  $f8, 0xa8($sp)
/* 0D2CF4 7F09E1C4 C4640008 */  lwc1  $f4, 8($v1)
/* 0D2CF8 7F09E1C8 46102282 */  mul.s $f10, $f4, $f16
/* 0D2CFC 7F09E1CC E7AA00AC */  swc1  $f10, 0xac($sp)
/* 0D2D00 7F09E1D0 C4660010 */  lwc1  $f6, 0x10($v1)
/* 0D2D04 7F09E1D4 460E3202 */  mul.s $f8, $f6, $f14
/* 0D2D08 7F09E1D8 E7A80098 */  swc1  $f8, 0x98($sp)
/* 0D2D0C 7F09E1DC C4640014 */  lwc1  $f4, 0x14($v1)
/* 0D2D10 7F09E1E0 460E2282 */  mul.s $f10, $f4, $f14
/* 0D2D14 7F09E1E4 E7AA009C */  swc1  $f10, 0x9c($sp)
/* 0D2D18 7F09E1E8 C4660018 */  lwc1  $f6, 0x18($v1)
/* 0D2D1C 7F09E1EC 460E3202 */  mul.s $f8, $f6, $f14
/* 0D2D20 7F09E1F0 E7A800A0 */  swc1  $f8, 0xa0($sp)
/* 0D2D24 7F09E1F4 C4640010 */  lwc1  $f4, 0x10($v1)
/* 0D2D28 7F09E1F8 46102282 */  mul.s $f10, $f4, $f16
/* 0D2D2C 7F09E1FC E7AA008C */  swc1  $f10, 0x8c($sp)
/* 0D2D30 7F09E200 C4660014 */  lwc1  $f6, 0x14($v1)
/* 0D2D34 7F09E204 46103202 */  mul.s $f8, $f6, $f16
/* 0D2D38 7F09E208 E7A80090 */  swc1  $f8, 0x90($sp)
/* 0D2D3C 7F09E20C C4640018 */  lwc1  $f4, 0x18($v1)
/* 0D2D40 7F09E210 46102282 */  mul.s $f10, $f4, $f16
/* 0D2D44 7F09E214 0FC2D20F */  jal   get_room_data_float1
/* 0D2D48 7F09E218 E7AA0094 */   swc1  $f10, 0x94($sp)
/* 0D2D4C 7F09E21C C7A60080 */  lwc1  $f6, 0x80($sp)
/* 0D2D50 7F09E220 C7A800B0 */  lwc1  $f8, 0xb0($sp)
/* 0D2D54 7F09E224 C7AA008C */  lwc1  $f10, 0x8c($sp)
/* 0D2D58 7F09E228 3C014120 */  li    $at, 0x41200000 # 10.000000
/* 0D2D5C 7F09E22C 46083101 */  sub.s $f4, $f6, $f8
/* 0D2D60 7F09E230 4481A000 */  mtc1  $at, $f20
/* 0D2D64 7F09E234 460A2181 */  sub.s $f6, $f4, $f10
/* 0D2D68 7F09E238 C6640000 */  lwc1  $f4, ($s3)
/* 0D2D6C 7F09E23C 46003202 */  mul.s $f8, $f6, $f0
/* 0D2D70 7F09E240 46044281 */  sub.s $f10, $f8, $f4
/* 0D2D74 7F09E244 46145082 */  mul.s $f2, $f10, $f20
/* 0D2D78 7F09E248 0FC2D20F */  jal   get_room_data_float1
/* 0D2D7C 7F09E24C E7A20054 */   swc1  $f2, 0x54($sp)
/* 0D2D80 7F09E250 C7A6007C */  lwc1  $f6, 0x7c($sp)
/* 0D2D84 7F09E254 C7A800B4 */  lwc1  $f8, 0xb4($sp)
/* 0D2D88 7F09E258 C7AA0090 */  lwc1  $f10, 0x90($sp)
/* 0D2D8C 7F09E25C 46083101 */  sub.s $f4, $f6, $f8
/* 0D2D90 7F09E260 460A2181 */  sub.s $f6, $f4, $f10
/* 0D2D94 7F09E264 C6640004 */  lwc1  $f4, 4($s3)
/* 0D2D98 7F09E268 46003202 */  mul.s $f8, $f6, $f0
/* 0D2D9C 7F09E26C 46044281 */  sub.s $f10, $f8, $f4
/* 0D2DA0 7F09E270 46145302 */  mul.s $f12, $f10, $f20
/* 0D2DA4 7F09E274 0FC2D20F */  jal   get_room_data_float1
/* 0D2DA8 7F09E278 E7AC0050 */   swc1  $f12, 0x50($sp)
/* 0D2DAC 7F09E27C C7A60078 */  lwc1  $f6, 0x78($sp)
/* 0D2DB0 7F09E280 C7A800B8 */  lwc1  $f8, 0xb8($sp)
/* 0D2DB4 7F09E284 C7AA0094 */  lwc1  $f10, 0x94($sp)
/* 0D2DB8 7F09E288 3C018005 */  lui   $at, %hi(D_800576C4)
/* 0D2DBC 7F09E28C 46083101 */  sub.s $f4, $f6, $f8
/* 0D2DC0 7F09E290 C43076C4 */  lwc1  $f16, %lo(D_800576C4)($at)
/* 0D2DC4 7F09E294 C7A20054 */  lwc1  $f2, 0x54($sp)
/* 0D2DC8 7F09E298 C7AC0050 */  lwc1  $f12, 0x50($sp)
/* 0D2DCC 7F09E29C 460A2181 */  sub.s $f6, $f4, $f10
/* 0D2DD0 7F09E2A0 C6640008 */  lwc1  $f4, 8($s3)
/* 0D2DD4 7F09E2A4 3C018005 */  lui   $at, %hi(D_800576C8)
/* 0D2DD8 7F09E2A8 4602803C */  c.lt.s $f16, $f2
/* 0D2DDC 7F09E2AC 46003202 */  mul.s $f8, $f6, $f0
/* 0D2DE0 7F09E2B0 46044281 */  sub.s $f10, $f8, $f4
/* 0D2DE4 7F09E2B4 46145382 */  mul.s $f14, $f10, $f20
/* 0D2DE8 7F09E2B8 45010016 */  bc1t  .L7F09E314
/* 0D2DEC 7F09E2BC 00000000 */   nop   
/* 0D2DF0 7F09E2C0 C42076C8 */  lwc1  $f0, %lo(D_800576C8)($at)
/* 0D2DF4 7F09E2C4 4600103C */  c.lt.s $f2, $f0
/* 0D2DF8 7F09E2C8 00000000 */  nop   
/* 0D2DFC 7F09E2CC 45010011 */  bc1t  .L7F09E314
/* 0D2E00 7F09E2D0 00000000 */   nop   
/* 0D2E04 7F09E2D4 460C803C */  c.lt.s $f16, $f12
/* 0D2E08 7F09E2D8 00000000 */  nop   
/* 0D2E0C 7F09E2DC 4501000D */  bc1t  .L7F09E314
/* 0D2E10 7F09E2E0 00000000 */   nop   
/* 0D2E14 7F09E2E4 4600603C */  c.lt.s $f12, $f0
/* 0D2E18 7F09E2E8 00000000 */  nop   
/* 0D2E1C 7F09E2EC 45010009 */  bc1t  .L7F09E314
/* 0D2E20 7F09E2F0 00000000 */   nop   
/* 0D2E24 7F09E2F4 460E803C */  c.lt.s $f16, $f14
/* 0D2E28 7F09E2F8 00000000 */  nop   
/* 0D2E2C 7F09E2FC 45010005 */  bc1t  .L7F09E314
/* 0D2E30 7F09E300 00000000 */   nop   
/* 0D2E34 7F09E304 4600703C */  c.lt.s $f14, $f0
/* 0D2E38 7F09E308 00000000 */  nop   
/* 0D2E3C 7F09E30C 45020004 */  bc1fl .L7F09E320
/* 0D2E40 7F09E310 4600118D */   trunc.w.s $f6, $f2
.L7F09E314:
/* 0D2E44 7F09E314 100000F0 */  b     .L7F09E6D8
/* 0D2E48 7F09E318 8FA200E0 */   lw    $v0, 0xe0($sp)
/* 0D2E4C 7F09E31C 4600118D */  trunc.w.s $f6, $f2
.L7F09E320:
/* 0D2E50 7F09E320 241906E0 */  li    $t9, 1760
/* 0D2E54 7F09E324 A6190008 */  sh    $t9, 8($s0)
/* 0D2E58 7F09E328 4600620D */  trunc.w.s $f8, $f12
/* 0D2E5C 7F09E32C 440A3000 */  mfc1  $t2, $f6
/* 0D2E60 7F09E330 A600000A */  sh    $zero, 0xa($s0)
/* 0D2E64 7F09E334 4600710D */  trunc.w.s $f4, $f14
/* 0D2E68 7F09E338 440B4000 */  mfc1  $t3, $f8
/* 0D2E6C 7F09E33C A60A0000 */  sh    $t2, ($s0)
/* 0D2E70 7F09E340 440C2000 */  mfc1  $t4, $f4
/* 0D2E74 7F09E344 A60B0002 */  sh    $t3, 2($s0)
/* 0D2E78 7F09E348 A60C0004 */  sh    $t4, 4($s0)
/* 0D2E7C 7F09E34C 864F0006 */  lh    $t7, 6($s2)
/* 0D2E80 7F09E350 01F50019 */  multu $t7, $s5
/* 0D2E84 7F09E354 0000C012 */  mflo  $t8
/* 0D2E88 7F09E358 02987021 */  addu  $t6, $s4, $t8
/* 0D2E8C 7F09E35C 91C8000C */  lbu   $t0, 0xc($t6)
/* 0D2E90 7F09E360 A208000C */  sb    $t0, 0xc($s0)
/* 0D2E94 7F09E364 864A0006 */  lh    $t2, 6($s2)
/* 0D2E98 7F09E368 01550019 */  multu $t2, $s5
/* 0D2E9C 7F09E36C 00004812 */  mflo  $t1
/* 0D2EA0 7F09E370 02895821 */  addu  $t3, $s4, $t1
/* 0D2EA4 7F09E374 916D000D */  lbu   $t5, 0xd($t3)
/* 0D2EA8 7F09E378 A20D000D */  sb    $t5, 0xd($s0)
/* 0D2EAC 7F09E37C 864C0006 */  lh    $t4, 6($s2)
/* 0D2EB0 7F09E380 01950019 */  multu $t4, $s5
/* 0D2EB4 7F09E384 0000C812 */  mflo  $t9
/* 0D2EB8 7F09E388 02997821 */  addu  $t7, $s4, $t9
/* 0D2EBC 7F09E38C 91F8000E */  lbu   $t8, 0xe($t7)
/* 0D2EC0 7F09E390 A218000E */  sb    $t8, 0xe($s0)
/* 0D2EC4 7F09E394 93AE0077 */  lbu   $t6, 0x77($sp)
/* 0D2EC8 7F09E398 0FC2D20F */  jal   get_room_data_float1
/* 0D2ECC 7F09E39C A20E000F */   sb    $t6, 0xf($s0)
/* 0D2ED0 7F09E3A0 C7AA0080 */  lwc1  $f10, 0x80($sp)
/* 0D2ED4 7F09E3A4 C7A600A4 */  lwc1  $f6, 0xa4($sp)
/* 0D2ED8 7F09E3A8 C7A40098 */  lwc1  $f4, 0x98($sp)
/* 0D2EDC 7F09E3AC 46065200 */  add.s $f8, $f10, $f6
/* 0D2EE0 7F09E3B0 46044281 */  sub.s $f10, $f8, $f4
/* 0D2EE4 7F09E3B4 C6680000 */  lwc1  $f8, ($s3)
/* 0D2EE8 7F09E3B8 46005182 */  mul.s $f6, $f10, $f0
/* 0D2EEC 7F09E3BC 46083101 */  sub.s $f4, $f6, $f8
/* 0D2EF0 7F09E3C0 46142282 */  mul.s $f10, $f4, $f20
/* 0D2EF4 7F09E3C4 4600518D */  trunc.w.s $f6, $f10
/* 0D2EF8 7F09E3C8 440A3000 */  mfc1  $t2, $f6
/* 0D2EFC 7F09E3CC 0FC2D20F */  jal   get_room_data_float1
/* 0D2F00 7F09E3D0 A60A0010 */   sh    $t2, 0x10($s0)
/* 0D2F04 7F09E3D4 C7A8007C */  lwc1  $f8, 0x7c($sp)
/* 0D2F08 7F09E3D8 C7A400A8 */  lwc1  $f4, 0xa8($sp)
/* 0D2F0C 7F09E3DC C7A6009C */  lwc1  $f6, 0x9c($sp)
/* 0D2F10 7F09E3E0 46044280 */  add.s $f10, $f8, $f4
/* 0D2F14 7F09E3E4 46065201 */  sub.s $f8, $f10, $f6
/* 0D2F18 7F09E3E8 C66A0004 */  lwc1  $f10, 4($s3)
/* 0D2F1C 7F09E3EC 46004102 */  mul.s $f4, $f8, $f0
/* 0D2F20 7F09E3F0 460A2181 */  sub.s $f6, $f4, $f10
/* 0D2F24 7F09E3F4 46143202 */  mul.s $f8, $f6, $f20
/* 0D2F28 7F09E3F8 4600410D */  trunc.w.s $f4, $f8
/* 0D2F2C 7F09E3FC 440B2000 */  mfc1  $t3, $f4
/* 0D2F30 7F09E400 0FC2D20F */  jal   get_room_data_float1
/* 0D2F34 7F09E404 A60B0012 */   sh    $t3, 0x12($s0)
/* 0D2F38 7F09E408 C7AA0078 */  lwc1  $f10, 0x78($sp)
/* 0D2F3C 7F09E40C C7A600AC */  lwc1  $f6, 0xac($sp)
/* 0D2F40 7F09E410 C7A400A0 */  lwc1  $f4, 0xa0($sp)
/* 0D2F44 7F09E414 46065200 */  add.s $f8, $f10, $f6
/* 0D2F48 7F09E418 46044281 */  sub.s $f10, $f8, $f4
/* 0D2F4C 7F09E41C C6680008 */  lwc1  $f8, 8($s3)
/* 0D2F50 7F09E420 A6000018 */  sh    $zero, 0x18($s0)
/* 0D2F54 7F09E424 A600001A */  sh    $zero, 0x1a($s0)
/* 0D2F58 7F09E428 46005182 */  mul.s $f6, $f10, $f0
/* 0D2F5C 7F09E42C 46083101 */  sub.s $f4, $f6, $f8
/* 0D2F60 7F09E430 46142282 */  mul.s $f10, $f4, $f20
/* 0D2F64 7F09E434 4600518D */  trunc.w.s $f6, $f10
/* 0D2F68 7F09E438 440C3000 */  mfc1  $t4, $f6
/* 0D2F6C 7F09E43C 00000000 */  nop   
/* 0D2F70 7F09E440 A60C0014 */  sh    $t4, 0x14($s0)
/* 0D2F74 7F09E444 86590006 */  lh    $t9, 6($s2)
/* 0D2F78 7F09E448 03350019 */  multu $t9, $s5
/* 0D2F7C 7F09E44C 00007812 */  mflo  $t7
/* 0D2F80 7F09E450 028FC021 */  addu  $t8, $s4, $t7
/* 0D2F84 7F09E454 930E000C */  lbu   $t6, 0xc($t8)
/* 0D2F88 7F09E458 A20E001C */  sb    $t6, 0x1c($s0)
/* 0D2F8C 7F09E45C 86480006 */  lh    $t0, 6($s2)
/* 0D2F90 7F09E460 01150019 */  multu $t0, $s5
/* 0D2F94 7F09E464 00005012 */  mflo  $t2
/* 0D2F98 7F09E468 028A4821 */  addu  $t1, $s4, $t2
/* 0D2F9C 7F09E46C 912B000D */  lbu   $t3, 0xd($t1)
/* 0D2FA0 7F09E470 A20B001D */  sb    $t3, 0x1d($s0)
/* 0D2FA4 7F09E474 864D0006 */  lh    $t5, 6($s2)
/* 0D2FA8 7F09E478 01B50019 */  multu $t5, $s5
/* 0D2FAC 7F09E47C 00006012 */  mflo  $t4
/* 0D2FB0 7F09E480 028CC821 */  addu  $t9, $s4, $t4
/* 0D2FB4 7F09E484 932F000E */  lbu   $t7, 0xe($t9)
/* 0D2FB8 7F09E488 A20F001E */  sb    $t7, 0x1e($s0)
/* 0D2FBC 7F09E48C 93B80077 */  lbu   $t8, 0x77($sp)
/* 0D2FC0 7F09E490 0FC2D20F */  jal   get_room_data_float1
/* 0D2FC4 7F09E494 A218001F */   sb    $t8, 0x1f($s0)
/* 0D2FC8 7F09E498 C7A80080 */  lwc1  $f8, 0x80($sp)
/* 0D2FCC 7F09E49C C7A400B0 */  lwc1  $f4, 0xb0($sp)
/* 0D2FD0 7F09E4A0 C7A6008C */  lwc1  $f6, 0x8c($sp)
/* 0D2FD4 7F09E4A4 46044280 */  add.s $f10, $f8, $f4
/* 0D2FD8 7F09E4A8 46065200 */  add.s $f8, $f10, $f6
/* 0D2FDC 7F09E4AC C66A0000 */  lwc1  $f10, ($s3)
/* 0D2FE0 7F09E4B0 46004102 */  mul.s $f4, $f8, $f0
/* 0D2FE4 7F09E4B4 460A2181 */  sub.s $f6, $f4, $f10
/* 0D2FE8 7F09E4B8 46143202 */  mul.s $f8, $f6, $f20
/* 0D2FEC 7F09E4BC 4600410D */  trunc.w.s $f4, $f8
/* 0D2FF0 7F09E4C0 44082000 */  mfc1  $t0, $f4
/* 0D2FF4 7F09E4C4 0FC2D20F */  jal   get_room_data_float1
/* 0D2FF8 7F09E4C8 A6080020 */   sh    $t0, 0x20($s0)
/* 0D2FFC 7F09E4CC C7AA007C */  lwc1  $f10, 0x7c($sp)
/* 0D3000 7F09E4D0 C7A600B4 */  lwc1  $f6, 0xb4($sp)
/* 0D3004 7F09E4D4 C7A40090 */  lwc1  $f4, 0x90($sp)
/* 0D3008 7F09E4D8 46065200 */  add.s $f8, $f10, $f6
/* 0D300C 7F09E4DC 46044280 */  add.s $f10, $f8, $f4
/* 0D3010 7F09E4E0 C6680004 */  lwc1  $f8, 4($s3)
/* 0D3014 7F09E4E4 46005182 */  mul.s $f6, $f10, $f0
/* 0D3018 7F09E4E8 46083101 */  sub.s $f4, $f6, $f8
/* 0D301C 7F09E4EC 46142282 */  mul.s $f10, $f4, $f20
/* 0D3020 7F09E4F0 4600518D */  trunc.w.s $f6, $f10
/* 0D3024 7F09E4F4 44093000 */  mfc1  $t1, $f6
/* 0D3028 7F09E4F8 0FC2D20F */  jal   get_room_data_float1
/* 0D302C 7F09E4FC A6090022 */   sh    $t1, 0x22($s0)
/* 0D3030 7F09E500 C7A80078 */  lwc1  $f8, 0x78($sp)
/* 0D3034 7F09E504 C7A400B8 */  lwc1  $f4, 0xb8($sp)
/* 0D3038 7F09E508 C7A60094 */  lwc1  $f6, 0x94($sp)
/* 0D303C 7F09E50C 240C06E0 */  li    $t4, 1760
/* 0D3040 7F09E510 46044280 */  add.s $f10, $f8, $f4
/* 0D3044 7F09E514 46065200 */  add.s $f8, $f10, $f6
/* 0D3048 7F09E518 C66A0008 */  lwc1  $f10, 8($s3)
/* 0D304C 7F09E51C A6000028 */  sh    $zero, 0x28($s0)
/* 0D3050 7F09E520 A60C002A */  sh    $t4, 0x2a($s0)
/* 0D3054 7F09E524 46004102 */  mul.s $f4, $f8, $f0
/* 0D3058 7F09E528 460A2181 */  sub.s $f6, $f4, $f10
/* 0D305C 7F09E52C 46143202 */  mul.s $f8, $f6, $f20
/* 0D3060 7F09E530 4600410D */  trunc.w.s $f4, $f8
/* 0D3064 7F09E534 440D2000 */  mfc1  $t5, $f4
/* 0D3068 7F09E538 00000000 */  nop   
/* 0D306C 7F09E53C A60D0024 */  sh    $t5, 0x24($s0)
/* 0D3070 7F09E540 86590006 */  lh    $t9, 6($s2)
/* 0D3074 7F09E544 03350019 */  multu $t9, $s5
/* 0D3078 7F09E548 00007812 */  mflo  $t7
/* 0D307C 7F09E54C 028FC021 */  addu  $t8, $s4, $t7
/* 0D3080 7F09E550 930E000C */  lbu   $t6, 0xc($t8)
/* 0D3084 7F09E554 A20E002C */  sb    $t6, 0x2c($s0)
/* 0D3088 7F09E558 86480006 */  lh    $t0, 6($s2)
/* 0D308C 7F09E55C 01150019 */  multu $t0, $s5
/* 0D3090 7F09E560 00005012 */  mflo  $t2
/* 0D3094 7F09E564 028A4821 */  addu  $t1, $s4, $t2
/* 0D3098 7F09E568 912B000D */  lbu   $t3, 0xd($t1)
/* 0D309C 7F09E56C A20B002D */  sb    $t3, 0x2d($s0)
/* 0D30A0 7F09E570 864D0006 */  lh    $t5, 6($s2)
/* 0D30A4 7F09E574 01B50019 */  multu $t5, $s5
/* 0D30A8 7F09E578 00006012 */  mflo  $t4
/* 0D30AC 7F09E57C 028CC821 */  addu  $t9, $s4, $t4
/* 0D30B0 7F09E580 932F000E */  lbu   $t7, 0xe($t9)
/* 0D30B4 7F09E584 A20F002E */  sb    $t7, 0x2e($s0)
/* 0D30B8 7F09E588 93B80077 */  lbu   $t8, 0x77($sp)
/* 0D30BC 7F09E58C 0FC2D20F */  jal   get_room_data_float1
/* 0D30C0 7F09E590 A218002F */   sb    $t8, 0x2f($s0)
/* 0D30C4 7F09E594 C7AA0080 */  lwc1  $f10, 0x80($sp)
/* 0D30C8 7F09E598 C7A600A4 */  lwc1  $f6, 0xa4($sp)
/* 0D30CC 7F09E59C C7A40098 */  lwc1  $f4, 0x98($sp)
/* 0D30D0 7F09E5A0 46065201 */  sub.s $f8, $f10, $f6
/* 0D30D4 7F09E5A4 46044280 */  add.s $f10, $f8, $f4
/* 0D30D8 7F09E5A8 C6680000 */  lwc1  $f8, ($s3)
/* 0D30DC 7F09E5AC 46005182 */  mul.s $f6, $f10, $f0
/* 0D30E0 7F09E5B0 46083101 */  sub.s $f4, $f6, $f8
/* 0D30E4 7F09E5B4 46142282 */  mul.s $f10, $f4, $f20
/* 0D30E8 7F09E5B8 4600518D */  trunc.w.s $f6, $f10
/* 0D30EC 7F09E5BC 44083000 */  mfc1  $t0, $f6
/* 0D30F0 7F09E5C0 0FC2D20F */  jal   get_room_data_float1
/* 0D30F4 7F09E5C4 A6080030 */   sh    $t0, 0x30($s0)
/* 0D30F8 7F09E5C8 C7A8007C */  lwc1  $f8, 0x7c($sp)
/* 0D30FC 7F09E5CC C7A400A8 */  lwc1  $f4, 0xa8($sp)
/* 0D3100 7F09E5D0 C7A6009C */  lwc1  $f6, 0x9c($sp)
/* 0D3104 7F09E5D4 46044281 */  sub.s $f10, $f8, $f4
/* 0D3108 7F09E5D8 46065200 */  add.s $f8, $f10, $f6
/* 0D310C 7F09E5DC C66A0004 */  lwc1  $f10, 4($s3)
/* 0D3110 7F09E5E0 46004102 */  mul.s $f4, $f8, $f0
/* 0D3114 7F09E5E4 460A2181 */  sub.s $f6, $f4, $f10
/* 0D3118 7F09E5E8 46143202 */  mul.s $f8, $f6, $f20
/* 0D311C 7F09E5EC 4600410D */  trunc.w.s $f4, $f8
/* 0D3120 7F09E5F0 44092000 */  mfc1  $t1, $f4
/* 0D3124 7F09E5F4 0FC2D20F */  jal   get_room_data_float1
/* 0D3128 7F09E5F8 A6090032 */   sh    $t1, 0x32($s0)
/* 0D312C 7F09E5FC C7AA0078 */  lwc1  $f10, 0x78($sp)
/* 0D3130 7F09E600 C7A600AC */  lwc1  $f6, 0xac($sp)
/* 0D3134 7F09E604 C7A400A0 */  lwc1  $f4, 0xa0($sp)
/* 0D3138 7F09E608 240C06E0 */  li    $t4, 1760
/* 0D313C 7F09E60C 46065201 */  sub.s $f8, $f10, $f6
/* 0D3140 7F09E610 241906E0 */  li    $t9, 1760
/* 0D3144 7F09E614 02002025 */  move  $a0, $s0
/* 0D3148 7F09E618 46044280 */  add.s $f10, $f8, $f4
/* 0D314C 7F09E61C C6680008 */  lwc1  $f8, 8($s3)
/* 0D3150 7F09E620 A60C0038 */  sh    $t4, 0x38($s0)
/* 0D3154 7F09E624 A619003A */  sh    $t9, 0x3a($s0)
/* 0D3158 7F09E628 46005182 */  mul.s $f6, $f10, $f0
/* 0D315C 7F09E62C 46083101 */  sub.s $f4, $f6, $f8
/* 0D3160 7F09E630 46142282 */  mul.s $f10, $f4, $f20
/* 0D3164 7F09E634 4600518D */  trunc.w.s $f6, $f10
/* 0D3168 7F09E638 440D3000 */  mfc1  $t5, $f6
/* 0D316C 7F09E63C 00000000 */  nop   
/* 0D3170 7F09E640 A60D0034 */  sh    $t5, 0x34($s0)
/* 0D3174 7F09E644 864F0006 */  lh    $t7, 6($s2)
/* 0D3178 7F09E648 01F50019 */  multu $t7, $s5
/* 0D317C 7F09E64C 0000C012 */  mflo  $t8
/* 0D3180 7F09E650 02987021 */  addu  $t6, $s4, $t8
/* 0D3184 7F09E654 91C8000C */  lbu   $t0, 0xc($t6)
/* 0D3188 7F09E658 A208003C */  sb    $t0, 0x3c($s0)
/* 0D318C 7F09E65C 864A0006 */  lh    $t2, 6($s2)
/* 0D3190 7F09E660 01550019 */  multu $t2, $s5
/* 0D3194 7F09E664 00004812 */  mflo  $t1
/* 0D3198 7F09E668 02895821 */  addu  $t3, $s4, $t1
/* 0D319C 7F09E66C 916D000D */  lbu   $t5, 0xd($t3)
/* 0D31A0 7F09E670 3C090430 */  lui   $t1, (0x04300040 >> 16) # lui $t1, 0x430
/* 0D31A4 7F09E674 35290040 */  ori   $t1, (0x04300040 & 0xFFFF) # ori $t1, $t1, 0x40
/* 0D31A8 7F09E678 A20D003D */  sb    $t5, 0x3d($s0)
/* 0D31AC 7F09E67C 864C0006 */  lh    $t4, 6($s2)
/* 0D31B0 7F09E680 01950019 */  multu $t4, $s5
/* 0D31B4 7F09E684 0000C812 */  mflo  $t9
/* 0D31B8 7F09E688 02997821 */  addu  $t7, $s4, $t9
/* 0D31BC 7F09E68C 91F8000E */  lbu   $t8, 0xe($t7)
/* 0D31C0 7F09E690 A218003E */  sb    $t8, 0x3e($s0)
/* 0D31C4 7F09E694 93AE0077 */  lbu   $t6, 0x77($sp)
/* 0D31C8 7F09E698 A20E003F */  sb    $t6, 0x3f($s0)
/* 0D31CC 7F09E69C 8FB100E0 */  lw    $s1, 0xe0($sp)
/* 0D31D0 7F09E6A0 262A0008 */  addiu $t2, $s1, 8
/* 0D31D4 7F09E6A4 AFAA00E0 */  sw    $t2, 0xe0($sp)
/* 0D31D8 7F09E6A8 0C003A2C */  jal   osVirtualToPhysical
/* 0D31DC 7F09E6AC AE290000 */   sw    $t1, ($s1)
/* 0D31E0 7F09E6B0 AE220004 */  sw    $v0, 4($s1)
/* 0D31E4 7F09E6B4 8FAB00E0 */  lw    $t3, 0xe0($sp)
/* 0D31E8 7F09E6B8 3C0CB100 */  lui   $t4, (0xB1000032 >> 16) # lui $t4, 0xb100
/* 0D31EC 7F09E6BC 358C0032 */  ori   $t4, (0xB1000032 & 0xFFFF) # ori $t4, $t4, 0x32
/* 0D31F0 7F09E6C0 256D0008 */  addiu $t5, $t3, 8
/* 0D31F4 7F09E6C4 AFAD00E0 */  sw    $t5, 0xe0($sp)
/* 0D31F8 7F09E6C8 24192010 */  li    $t9, 8208
/* 0D31FC 7F09E6CC AD790004 */  sw    $t9, 4($t3)
/* 0D3200 7F09E6D0 AD6C0000 */  sw    $t4, ($t3)
/* 0D3204 7F09E6D4 8FA200E0 */  lw    $v0, 0xe0($sp)
.L7F09E6D8:
/* 0D3208 7F09E6D8 8FBF0034 */  lw    $ra, 0x34($sp)
/* 0D320C 7F09E6DC D7B40010 */  ldc1  $f20, 0x10($sp)
/* 0D3210 7F09E6E0 8FB0001C */  lw    $s0, 0x1c($sp)
/* 0D3214 7F09E6E4 8FB10020 */  lw    $s1, 0x20($sp)
/* 0D3218 7F09E6E8 8FB20024 */  lw    $s2, 0x24($sp)
/* 0D321C 7F09E6EC 8FB30028 */  lw    $s3, 0x28($sp)
/* 0D3220 7F09E6F0 8FB4002C */  lw    $s4, 0x2c($sp)
/* 0D3224 7F09E6F4 8FB50030 */  lw    $s5, 0x30($sp)
/* 0D3228 7F09E6F8 03E00008 */  jr    $ra
/* 0D322C 7F09E6FC 27BD00D8 */   addiu $sp, $sp, 0xd8
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F09E700(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F09E700
/* 0D3230 7F09E700 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 0D3234 7F09E704 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0D3238 7F09E708 AFA40030 */  sw    $a0, 0x30($sp)
/* 0D323C 7F09E70C AFA50034 */  sw    $a1, 0x34($sp)
/* 0D3240 7F09E710 AFA60038 */  sw    $a2, 0x38($sp)
/* 0D3244 7F09E714 AFA7003C */  sw    $a3, 0x3c($sp)
/* 0D3248 7F09E718 0FC26919 */  jal   getPlayerCount
/* 0D324C 7F09E71C AFA0002C */   sw    $zero, 0x2c($sp)
/* 0D3250 7F09E720 3C0B8004 */  lui   $t3, %hi(array_smoke_types) 
/* 0D3254 7F09E724 3C078008 */  lui   $a3, %hi(ptr_smoke_buf)
/* 0D3258 7F09E728 8FAD002C */  lw    $t5, 0x2c($sp)
/* 0D325C 7F09E72C 24E7A140 */  addiu $a3, %lo(ptr_smoke_buf) # addiu $a3, $a3, -0x5ec0
/* 0D3260 7F09E730 256B017C */  addiu $t3, %lo(array_smoke_types) # addiu $t3, $t3, 0x17c
/* 0D3264 7F09E734 00002025 */  move  $a0, $zero
/* 0D3268 7F09E738 240C0018 */  li    $t4, 24
/* 0D326C 7F09E73C 240A0009 */  li    $t2, 9
/* 0D3270 7F09E740 24090008 */  li    $t1, 8
/* 0D3274 7F09E744 24080007 */  li    $t0, 7
/* 0D3278 7F09E748 8CE50000 */  lw    $a1, ($a3)
.L7F09E74C:
/* 0D327C 7F09E74C 28410002 */  slti  $at, $v0, 2
/* 0D3280 7F09E750 00A47021 */  addu  $t6, $a1, $a0
/* 0D3284 7F09E754 8DCF0000 */  lw    $t7, ($t6)
/* 0D3288 7F09E758 00853021 */  addu  $a2, $a0, $a1
/* 0D328C 7F09E75C 15E00003 */  bnez  $t7, .L7F09E76C
/* 0D3290 7F09E760 00000000 */   nop   
/* 0D3294 7F09E764 10000012 */  b     .L7F09E7B0
/* 0D3298 7F09E768 00856821 */   addu  $t5, $a0, $a1
.L7F09E76C:
/* 0D329C 7F09E76C 1420000D */  bnez  $at, .L7F09E7A4
/* 0D32A0 7F09E770 24840198 */   addiu $a0, $a0, 0x198
/* 0D32A4 7F09E774 84C30006 */  lh    $v1, 6($a2)
/* 0D32A8 7F09E778 5103000B */  beql  $t0, $v1, .L7F09E7A8
/* 0D32AC 7F09E77C 28811FE0 */   slti  $at, $a0, 0x1fe0
/* 0D32B0 7F09E780 51230009 */  beql  $t1, $v1, .L7F09E7A8
/* 0D32B4 7F09E784 28811FE0 */   slti  $at, $a0, 0x1fe0
/* 0D32B8 7F09E788 51430007 */  beql  $t2, $v1, .L7F09E7A8
/* 0D32BC 7F09E78C 28811FE0 */   slti  $at, $a0, 0x1fe0
/* 0D32C0 7F09E790 006C0019 */  multu $v1, $t4
/* 0D32C4 7F09E794 0000C012 */  mflo  $t8
/* 0D32C8 7F09E798 0178C821 */  addu  $t9, $t3, $t8
/* 0D32CC 7F09E79C 872E0000 */  lh    $t6, ($t9)
/* 0D32D0 7F09E7A0 A4CE0004 */  sh    $t6, 4($a2)
.L7F09E7A4:
/* 0D32D4 7F09E7A4 28811FE0 */  slti  $at, $a0, 0x1fe0
.L7F09E7A8:
/* 0D32D8 7F09E7A8 5420FFE8 */  bnezl $at, .L7F09E74C
/* 0D32DC 7F09E7AC 8CE50000 */   lw    $a1, ($a3)
.L7F09E7B0:
/* 0D32E0 7F09E7B0 51A0003B */  beql  $t5, $zero, .L7F09E8A0
/* 0D32E4 7F09E7B4 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0D32E8 7F09E7B8 0FC0E90C */  jal   chrpropAllocate
/* 0D32EC 7F09E7BC AFAD002C */   sw    $t5, 0x2c($sp)
/* 0D32F0 7F09E7C0 24080007 */  li    $t0, 7
/* 0D32F4 7F09E7C4 8FAD002C */  lw    $t5, 0x2c($sp)
/* 0D32F8 7F09E7C8 8FBF0030 */  lw    $ra, 0x30($sp)
/* 0D32FC 7F09E7CC 10400033 */  beqz  $v0, .L7F09E89C
/* 0D3300 7F09E7D0 AFA2001C */   sw    $v0, 0x1c($sp)
/* 0D3304 7F09E7D4 90580001 */  lbu   $t8, 1($v0)
/* 0D3308 7F09E7D8 8FA9003C */  lw    $t1, 0x3c($sp)
/* 0D330C 7F09E7DC 240F0008 */  li    $t7, 8
/* 0D3310 7F09E7E0 37190002 */  ori   $t9, $t8, 2
/* 0D3314 7F09E7E4 A04F0000 */  sb    $t7, ($v0)
/* 0D3318 7F09E7E8 A0590001 */  sb    $t9, 1($v0)
/* 0D331C 7F09E7EC AC4D0004 */  sw    $t5, 4($v0)
/* 0D3320 7F09E7F0 8FAE0034 */  lw    $t6, 0x34($sp)
/* 0D3324 7F09E7F4 240700FF */  li    $a3, 255
/* 0D3328 7F09E7F8 00003025 */  move  $a2, $zero
/* 0D332C 7F09E7FC AC4E0014 */  sw    $t6, 0x14($v0)
/* 0D3330 7F09E800 C7E40000 */  lwc1  $f4, ($ra)
/* 0D3334 7F09E804 00402821 */  addu  $a1, $v0, $zero
/* 0D3338 7F09E808 241800FF */  li    $t8, 255
/* 0D333C 7F09E80C E4440008 */  swc1  $f4, 8($v0)
/* 0D3340 7F09E810 C7E60004 */  lwc1  $f6, 4($ra)
/* 0D3344 7F09E814 01201821 */  addu  $v1, $t1, $zero
/* 0D3348 7F09E818 E446000C */  swc1  $f6, 0xc($v0)
/* 0D334C 7F09E81C C7E80008 */  lwc1  $f8, 8($ra)
/* 0D3350 7F09E820 E4480010 */  swc1  $f8, 0x10($v0)
/* 0D3354 7F09E824 912F0000 */  lbu   $t7, ($t1)
/* 0D3358 7F09E828 10EF0009 */  beq   $a3, $t7, .L7F09E850
/* 0D335C 7F09E82C 31E400FF */   andi  $a0, $t7, 0xff
/* 0D3360 7F09E830 A0A4002C */  sb    $a0, 0x2c($a1)
.L7F09E834:
/* 0D3364 7F09E834 90640001 */  lbu   $a0, 1($v1)
/* 0D3368 7F09E838 24C60001 */  addiu $a2, $a2, 1
/* 0D336C 7F09E83C 24630001 */  addiu $v1, $v1, 1
/* 0D3370 7F09E840 10E40003 */  beq   $a3, $a0, .L7F09E850
/* 0D3374 7F09E844 24A50001 */   addiu $a1, $a1, 1
/* 0D3378 7F09E848 54C8FFFA */  bnel  $a2, $t0, .L7F09E834
/* 0D337C 7F09E84C A0A4002C */   sb    $a0, 0x2c($a1)
.L7F09E850:
/* 0D3380 7F09E850 0046C821 */  addu  $t9, $v0, $a2
/* 0D3384 7F09E854 A338002C */  sb    $t8, 0x2c($t9)
/* 0D3388 7F09E858 8FAE0040 */  lw    $t6, 0x40($sp)
/* 0D338C 7F09E85C 51C00005 */  beql  $t6, $zero, .L7F09E874
/* 0D3390 7F09E860 8FA4001C */   lw    $a0, 0x1c($sp)
/* 0D3394 7F09E864 904F0001 */  lbu   $t7, 1($v0)
/* 0D3398 7F09E868 35F80008 */  ori   $t8, $t7, 8
/* 0D339C 7F09E86C A0580001 */  sb    $t8, 1($v0)
/* 0D33A0 7F09E870 8FA4001C */  lw    $a0, 0x1c($sp)
.L7F09E874:
/* 0D33A4 7F09E874 0FC0E93C */  jal   chrpropActivateThisFrame
/* 0D33A8 7F09E878 AFAD002C */   sw    $t5, 0x2c($sp)
/* 0D33AC 7F09E87C 0FC0E901 */  jal   chrpropEnable
/* 0D33B0 7F09E880 8FA4001C */   lw    $a0, 0x1c($sp)
/* 0D33B4 7F09E884 8FAD002C */  lw    $t5, 0x2c($sp)
/* 0D33B8 7F09E888 8FB9001C */  lw    $t9, 0x1c($sp)
/* 0D33BC 7F09E88C A5A00004 */  sh    $zero, 4($t5)
/* 0D33C0 7F09E890 ADB90000 */  sw    $t9, ($t5)
/* 0D33C4 7F09E894 87AE003A */  lh    $t6, 0x3a($sp)
/* 0D33C8 7F09E898 A5AE0006 */  sh    $t6, 6($t5)
.L7F09E89C:
/* 0D33CC 7F09E89C 8FBF0014 */  lw    $ra, 0x14($sp)
.L7F09E8A0:
/* 0D33D0 7F09E8A0 27BD0030 */  addiu $sp, $sp, 0x30
/* 0D33D4 7F09E8A4 03E00008 */  jr    $ra
/* 0D33D8 7F09E8A8 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F09E8AC(void) {

}
#else
GLOBAL_ASM(
.late_rodata
glabel D_800576CC
.word 0x3e19999a /*0.15000001*/
glabel D_800576D0
.word 0x3e99999a /*0.30000001*/
glabel D_800576D4
.word 0x3c23d70a /*0.0099999998*/
glabel D_800576D8
.word 0x3ca3d70a /*0.02*/
glabel D_800576DC
.word 0x40c90fdb /*6.2831855*/
.text
glabel sub_GAME_7F09E8AC
/* 0D33DC 7F09E8AC 27BDFF30 */  addiu $sp, $sp, -0xd0
/* 0D33E0 7F09E8B0 3C028005 */  lui   $v0, %hi(g_ClockTimer)
/* 0D33E4 7F09E8B4 8C428374 */  lw    $v0, %lo(g_ClockTimer)($v0)
/* 0D33E8 7F09E8B8 AFBF006C */  sw    $ra, 0x6c($sp)
/* 0D33EC 7F09E8BC AFBE0068 */  sw    $fp, 0x68($sp)
/* 0D33F0 7F09E8C0 AFB70064 */  sw    $s7, 0x64($sp)
/* 0D33F4 7F09E8C4 AFB60060 */  sw    $s6, 0x60($sp)
/* 0D33F8 7F09E8C8 AFB5005C */  sw    $s5, 0x5c($sp)
/* 0D33FC 7F09E8CC AFB40058 */  sw    $s4, 0x58($sp)
/* 0D3400 7F09E8D0 AFB30054 */  sw    $s3, 0x54($sp)
/* 0D3404 7F09E8D4 AFB20050 */  sw    $s2, 0x50($sp)
/* 0D3408 7F09E8D8 AFB1004C */  sw    $s1, 0x4c($sp)
/* 0D340C 7F09E8DC AFB00048 */  sw    $s0, 0x48($sp)
/* 0D3410 7F09E8E0 F7BE0040 */  sdc1  $f30, 0x40($sp)
/* 0D3414 7F09E8E4 F7BC0038 */  sdc1  $f28, 0x38($sp)
/* 0D3418 7F09E8E8 F7BA0030 */  sdc1  $f26, 0x30($sp)
/* 0D341C 7F09E8EC F7B80028 */  sdc1  $f24, 0x28($sp)
/* 0D3420 7F09E8F0 F7B60020 */  sdc1  $f22, 0x20($sp)
/* 0D3424 7F09E8F4 F7B40018 */  sdc1  $f20, 0x18($sp)
/* 0D3428 7F09E8F8 0080B825 */  move  $s7, $a0
/* 0D342C 7F09E8FC 14400003 */  bnez  $v0, .L7F09E90C
/* 0D3430 7F09E900 8C930004 */   lw    $s3, 4($a0)
/* 0D3434 7F09E904 10000193 */  b     .L7F09EF54
/* 0D3438 7F09E908 00001025 */   move  $v0, $zero
.L7F09E90C:
/* 0D343C 7F09E90C 2841000F */  slti  $at, $v0, 0xf
/* 0D3440 7F09E910 50200005 */  beql  $at, $zero, .L7F09E928
/* 0D3444 7F09E914 3C014170 */   lui   $at, 0x4170
/* 0D3448 7F09E918 44822000 */  mtc1  $v0, $f4
/* 0D344C 7F09E91C 10000004 */  b     .L7F09E930
/* 0D3450 7F09E920 46802020 */   cvt.s.w $f0, $f4
/* 0D3454 7F09E924 3C014170 */  li    $at, 0x41700000 # 15.000000
.L7F09E928:
/* 0D3458 7F09E928 44810000 */  mtc1  $at, $f0
/* 0D345C 7F09E92C 00000000 */  nop   
.L7F09E930:
/* 0D3460 7F09E930 4600018D */  trunc.w.s $f6, $f0
/* 0D3464 7F09E934 3C158004 */  lui   $s5, %hi(array_smoke_types)
/* 0D3468 7F09E938 26B5017C */  addiu $s5, %lo(array_smoke_types) # addiu $s5, $s5, 0x17c
/* 0D346C 7F09E93C 0000F025 */  move  $fp, $zero
/* 0D3470 7F09E940 440F3000 */  mfc1  $t7, $f6
/* 0D3474 7F09E944 3C018005 */  lui   $at, %hi(D_800576CC)
/* 0D3478 7F09E948 24160018 */  li    $s6, 24
/* 0D347C 7F09E94C 19E000FD */  blez  $t7, .L7F09ED44
/* 0D3480 7F09E950 AFAF008C */   sw    $t7, 0x8c($sp)
/* 0D3484 7F09E954 C43E76CC */  lwc1  $f30, %lo(D_800576CC)($at)
/* 0D3488 7F09E958 3C018005 */  lui    $at, %hi(D_800576D0)
/* 0D348C 7F09E95C C43C76D0 */  lwc1  $f28, %lo(D_800576D0)($at)
/* 0D3490 7F09E960 3C018005 */  lui    $at, %hi(D_800576D4)
/* 0D3494 7F09E964 C43876D4 */  lwc1  $f24, %lo(D_800576D4)($at)
/* 0D3498 7F09E968 3C018005 */  lui    $at, %hi(D_800576D8)
/* 0D349C 7F09E96C C43676D8 */  lwc1  $f22, %lo(D_800576D8)($at)
/* 0D34A0 7F09E970 3C012F80 */  li    $at, 0x2F800000 # 0.000000
/* 0D34A4 7F09E974 4481A000 */  mtc1  $at, $f20
/* 0D34A8 7F09E978 4480D000 */  mtc1  $zero, $f26
/* 0D34AC 7F09E97C 24140190 */  li    $s4, 400
/* 0D34B0 7F09E980 86790004 */  lh    $t9, 4($s3)
.L7F09E984:
/* 0D34B4 7F09E984 00001025 */  move  $v0, $zero
/* 0D34B8 7F09E988 00009025 */  move  $s2, $zero
/* 0D34BC 7F09E98C 27280001 */  addiu $t0, $t9, 1
/* 0D34C0 7F09E990 A6680004 */  sh    $t0, 4($s3)
/* 0D34C4 7F09E994 02608825 */  move  $s1, $s3
.L7F09E998:
/* 0D34C8 7F09E998 C6280014 */  lwc1  $f8, 0x14($s1)
/* 0D34CC 7F09E99C 4608D032 */  c.eq.s $f26, $f8
/* 0D34D0 7F09E9A0 00000000 */  nop   
/* 0D34D4 7F09E9A4 4503003C */  bc1tl .L7F09EA98
/* 0D34D8 7F09E9A8 26520028 */   addiu $s2, $s2, 0x28
/* 0D34DC 7F09E9AC 26300008 */  addiu $s0, $s1, 8
/* 0D34E0 7F09E9B0 C60A0004 */  lwc1  $f10, 4($s0)
/* 0D34E4 7F09E9B4 C612000C */  lwc1  $f18, 0xc($s0)
/* 0D34E8 7F09E9B8 C6060020 */  lwc1  $f6, 0x20($s0)
/* 0D34EC 7F09E9BC 461C5400 */  add.s $f16, $f10, $f28
/* 0D34F0 7F09E9C0 860C0024 */  lh    $t4, 0x24($s0)
/* 0D34F4 7F09E9C4 461E9100 */  add.s $f4, $f18, $f30
/* 0D34F8 7F09E9C8 E6100004 */  swc1  $f16, 4($s0)
/* 0D34FC 7F09E9CC C6100010 */  lwc1  $f16, 0x10($s0)
/* 0D3500 7F09E9D0 C6120014 */  lwc1  $f18, 0x14($s0)
/* 0D3504 7F09E9D4 E604000C */  swc1  $f4, 0xc($s0)
/* 0D3508 7F09E9D8 86690006 */  lh    $t1, 6($s3)
/* 0D350C 7F09E9DC 46128100 */  add.s $f4, $f16, $f18
/* 0D3510 7F09E9E0 258D0001 */  addiu $t5, $t4, 1
/* 0D3514 7F09E9E4 01360019 */  multu $t1, $s6
/* 0D3518 7F09E9E8 00005012 */  mflo  $t2
/* 0D351C 7F09E9EC 02AA5821 */  addu  $t3, $s5, $t2
/* 0D3520 7F09E9F0 C5680010 */  lwc1  $f8, 0x10($t3)
/* 0D3524 7F09E9F4 A60D0024 */  sh    $t5, 0x24($s0)
/* 0D3528 7F09E9F8 E6040010 */  swc1  $f4, 0x10($s0)
/* 0D352C 7F09E9FC 46083281 */  sub.s $f10, $f6, $f8
/* 0D3530 7F09EA00 0C002914 */  jal   randomGetNext
/* 0D3534 7F09EA04 E60A0020 */   swc1  $f10, 0x20($s0)
/* 0D3538 7F09EA08 44824000 */  mtc1  $v0, $f8
/* 0D353C 7F09EA0C C6060018 */  lwc1  $f6, 0x18($s0)
/* 0D3540 7F09EA10 04410005 */  bgez  $v0, .L7F09EA28
/* 0D3544 7F09EA14 468042A0 */   cvt.s.w $f10, $f8
/* 0D3548 7F09EA18 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0D354C 7F09EA1C 44818000 */  mtc1  $at, $f16
/* 0D3550 7F09EA20 00000000 */  nop   
/* 0D3554 7F09EA24 46105280 */  add.s $f10, $f10, $f16
.L7F09EA28:
/* 0D3558 7F09EA28 46145482 */  mul.s $f18, $f10, $f20
/* 0D355C 7F09EA2C 00000000 */  nop   
/* 0D3560 7F09EA30 46189102 */  mul.s $f4, $f18, $f24
/* 0D3564 7F09EA34 4604B200 */  add.s $f8, $f22, $f4
/* 0D3568 7F09EA38 46083400 */  add.s $f16, $f6, $f8
/* 0D356C 7F09EA3C 0C002914 */  jal   randomGetNext
/* 0D3570 7F09EA40 E6100018 */   swc1  $f16, 0x18($s0)
/* 0D3574 7F09EA44 44829000 */  mtc1  $v0, $f18
/* 0D3578 7F09EA48 C60A001C */  lwc1  $f10, 0x1c($s0)
/* 0D357C 7F09EA4C 04410005 */  bgez  $v0, .L7F09EA64
/* 0D3580 7F09EA50 46809120 */   cvt.s.w $f4, $f18
/* 0D3584 7F09EA54 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0D3588 7F09EA58 44813000 */  mtc1  $at, $f6
/* 0D358C 7F09EA5C 00000000 */  nop   
/* 0D3590 7F09EA60 46062100 */  add.s $f4, $f4, $f6
.L7F09EA64:
/* 0D3594 7F09EA64 46142202 */  mul.s $f8, $f4, $f20
/* 0D3598 7F09EA68 3C014080 */  li    $at, 0x40800000 # 4.000000
/* 0D359C 7F09EA6C C6040020 */  lwc1  $f4, 0x20($s0)
/* 0D35A0 7F09EA70 46184402 */  mul.s $f16, $f8, $f24
/* 0D35A4 7F09EA74 44814000 */  mtc1  $at, $f8
/* 0D35A8 7F09EA78 00000000 */  nop   
/* 0D35AC 7F09EA7C 4608203C */  c.lt.s $f4, $f8
/* 0D35B0 7F09EA80 4610B480 */  add.s $f18, $f22, $f16
/* 0D35B4 7F09EA84 46125180 */  add.s $f6, $f10, $f18
/* 0D35B8 7F09EA88 45000002 */  bc1f  .L7F09EA94
/* 0D35BC 7F09EA8C E606001C */   swc1  $f6, 0x1c($s0)
/* 0D35C0 7F09EA90 E61A000C */  swc1  $f26, 0xc($s0)
.L7F09EA94:
/* 0D35C4 7F09EA94 26520028 */  addiu $s2, $s2, 0x28
.L7F09EA98:
/* 0D35C8 7F09EA98 2A410190 */  slti  $at, $s2, 0x190
/* 0D35CC 7F09EA9C 1420FFBE */  bnez  $at, .L7F09E998
/* 0D35D0 7F09EAA0 26310028 */   addiu $s1, $s1, 0x28
/* 0D35D4 7F09EAA4 866E0006 */  lh    $t6, 6($s3)
/* 0D35D8 7F09EAA8 86630004 */  lh    $v1, 4($s3)
/* 0D35DC 7F09EAAC 01D60019 */  multu $t6, $s6
/* 0D35E0 7F09EAB0 00007812 */  mflo  $t7
/* 0D35E4 7F09EAB4 02AF2021 */  addu  $a0, $s5, $t7
/* 0D35E8 7F09EAB8 84980000 */  lh    $t8, ($a0)
/* 0D35EC 7F09EABC 0078082A */  slt   $at, $v1, $t8
/* 0D35F0 7F09EAC0 5020009D */  beql  $at, $zero, .L7F09ED38
/* 0D35F4 7F09EAC4 8FAB008C */   lw    $t3, 0x8c($sp)
/* 0D35F8 7F09EAC8 84990004 */  lh    $t9, 4($a0)
/* 0D35FC 7F09EACC 00009025 */  move  $s2, $zero
/* 0D3600 7F09EAD0 02608825 */  move  $s1, $s3
/* 0D3604 7F09EAD4 0079001A */  div   $zero, $v1, $t9
/* 0D3608 7F09EAD8 17200002 */  bnez  $t9, .L7F09EAE4
/* 0D360C 7F09EADC 00000000 */   nop   
/* 0D3610 7F09EAE0 0007000D */  break 7
.L7F09EAE4:
/* 0D3614 7F09EAE4 2401FFFF */  li    $at, -1
/* 0D3618 7F09EAE8 17210004 */  bne   $t9, $at, .L7F09EAFC
/* 0D361C 7F09EAEC 3C018000 */   li    $at, 0x80000000 # -0.000000
/* 0D3620 7F09EAF0 14610002 */  bne   $v1, $at, .L7F09EAFC
/* 0D3624 7F09EAF4 00000000 */   nop   
/* 0D3628 7F09EAF8 0006000D */  break 6
.L7F09EAFC:
/* 0D362C 7F09EAFC 24010001 */  li    $at, 1
/* 0D3630 7F09EB00 00004010 */  mfhi  $t0
/* 0D3634 7F09EB04 5501008C */  bnel  $t0, $at, .L7F09ED38
/* 0D3638 7F09EB08 8FAB008C */   lw    $t3, 0x8c($sp)
.L7F09EB0C:
/* 0D363C 7F09EB0C C6300014 */  lwc1  $f16, 0x14($s1)
/* 0D3640 7F09EB10 26520028 */  addiu $s2, $s2, 0x28
/* 0D3644 7F09EB14 4610D032 */  c.eq.s $f26, $f16
/* 0D3648 7F09EB18 00000000 */  nop   
/* 0D364C 7F09EB1C 45000083 */  bc1f  .L7F09ED2C
/* 0D3650 7F09EB20 00000000 */   nop   
/* 0D3654 7F09EB24 0C002914 */  jal   randomGetNext
/* 0D3658 7F09EB28 00000000 */   nop   
/* 0D365C 7F09EB2C 44825000 */  mtc1  $v0, $f10
/* 0D3660 7F09EB30 26300008 */  addiu $s0, $s1, 8
/* 0D3664 7F09EB34 04410005 */  bgez  $v0, .L7F09EB4C
/* 0D3668 7F09EB38 468054A0 */   cvt.s.w $f18, $f10
/* 0D366C 7F09EB3C 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0D3670 7F09EB40 44813000 */  mtc1  $at, $f6
/* 0D3674 7F09EB44 00000000 */  nop   
/* 0D3678 7F09EB48 46069480 */  add.s $f18, $f18, $f6
.L7F09EB4C:
/* 0D367C 7F09EB4C 86690006 */  lh    $t1, 6($s3)
/* 0D3680 7F09EB50 46149102 */  mul.s $f4, $f18, $f20
/* 0D3684 7F09EB54 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 0D3688 7F09EB58 01360019 */  multu $t1, $s6
/* 0D368C 7F09EB5C 44814000 */  mtc1  $at, $f8
/* 0D3690 7F09EB60 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0D3694 7F09EB64 44815000 */  mtc1  $at, $f10
/* 0D3698 7F09EB68 46082402 */  mul.s $f16, $f4, $f8
/* 0D369C 7F09EB6C 00005012 */  mflo  $t2
/* 0D36A0 7F09EB70 02AA5821 */  addu  $t3, $s5, $t2
/* 0D36A4 7F09EB74 856C0006 */  lh    $t4, 6($t3)
/* 0D36A8 7F09EB78 460A8180 */  add.s $f6, $f16, $f10
/* 0D36AC 7F09EB7C 448C9000 */  mtc1  $t4, $f18
/* 0D36B0 7F09EB80 00000000 */  nop   
/* 0D36B4 7F09EB84 46809120 */  cvt.s.w $f4, $f18
/* 0D36B8 7F09EB88 46043202 */  mul.s $f8, $f6, $f4
/* 0D36BC 7F09EB8C 0C002914 */  jal   randomGetNext
/* 0D36C0 7F09EB90 E608000C */   swc1  $f8, 0xc($s0)
/* 0D36C4 7F09EB94 24010046 */  li    $at, 70
/* 0D36C8 7F09EB98 0041001B */  divu  $zero, $v0, $at
/* 0D36CC 7F09EB9C 00006810 */  mfhi  $t5
/* 0D36D0 7F09EBA0 448D8000 */  mtc1  $t5, $f16
/* 0D36D4 7F09EBA4 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0D36D8 7F09EBA8 05A10004 */  bgez  $t5, .L7F09EBBC
/* 0D36DC 7F09EBAC 468082A0 */   cvt.s.w $f10, $f16
/* 0D36E0 7F09EBB0 44819000 */  mtc1  $at, $f18
/* 0D36E4 7F09EBB4 00000000 */  nop   
/* 0D36E8 7F09EBB8 46125280 */  add.s $f10, $f10, $f18
.L7F09EBBC:
/* 0D36EC 7F09EBBC 3C0142DC */  li    $at, 0x42DC0000 # 110.000000
/* 0D36F0 7F09EBC0 44813000 */  mtc1  $at, $f6
/* 0D36F4 7F09EBC4 A6000024 */  sh    $zero, 0x24($s0)
/* 0D36F8 7F09EBC8 46065100 */  add.s $f4, $f10, $f6
/* 0D36FC 7F09EBCC 0C002914 */  jal   randomGetNext
/* 0D3700 7F09EBD0 E6040020 */   swc1  $f4, 0x20($s0)
/* 0D3704 7F09EBD4 44824000 */  mtc1  $v0, $f8
/* 0D3708 7F09EBD8 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0D370C 7F09EBDC 04410004 */  bgez  $v0, .L7F09EBF0
/* 0D3710 7F09EBE0 46804420 */   cvt.s.w $f16, $f8
/* 0D3714 7F09EBE4 44819000 */  mtc1  $at, $f18
/* 0D3718 7F09EBE8 00000000 */  nop   
/* 0D371C 7F09EBEC 46128400 */  add.s $f16, $f16, $f18
.L7F09EBF0:
/* 0D3720 7F09EBF0 46148282 */  mul.s $f10, $f16, $f20
/* 0D3724 7F09EBF4 3C018005 */  lui    $at, %hi(D_800576DC)
/* 0D3728 7F09EBF8 C42676DC */  lwc1  $f6, %lo(D_800576DC)($at)
/* 0D372C 7F09EBFC 46065102 */  mul.s $f4, $f10, $f6
/* 0D3730 7F09EC00 0C002914 */  jal   randomGetNext
/* 0D3734 7F09EC04 E6040010 */   swc1  $f4, 0x10($s0)
/* 0D3738 7F09EC08 44829000 */  mtc1  $v0, $f18
/* 0D373C 7F09EC0C 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 0D3740 7F09EC10 44814000 */  mtc1  $at, $f8
/* 0D3744 7F09EC14 04410005 */  bgez  $v0, .L7F09EC2C
/* 0D3748 7F09EC18 46809420 */   cvt.s.w $f16, $f18
/* 0D374C 7F09EC1C 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0D3750 7F09EC20 44815000 */  mtc1  $at, $f10
/* 0D3754 7F09EC24 00000000 */  nop   
/* 0D3758 7F09EC28 460A8400 */  add.s $f16, $f16, $f10
.L7F09EC2C:
/* 0D375C 7F09EC2C 866E0006 */  lh    $t6, 6($s3)
/* 0D3760 7F09EC30 46148182 */  mul.s $f6, $f16, $f20
/* 0D3764 7F09EC34 46064101 */  sub.s $f4, $f8, $f6
/* 0D3768 7F09EC38 01D60019 */  multu $t6, $s6
/* 0D376C 7F09EC3C 00007812 */  mflo  $t7
/* 0D3770 7F09EC40 02AFC021 */  addu  $t8, $s5, $t7
/* 0D3774 7F09EC44 C7120008 */  lwc1  $f18, 8($t8)
/* 0D3778 7F09EC48 46049282 */  mul.s $f10, $f18, $f4
/* 0D377C 7F09EC4C E60A0014 */  swc1  $f10, 0x14($s0)
/* 0D3780 7F09EC50 C6F00008 */  lwc1  $f16, 8($s7)
/* 0D3784 7F09EC54 E6100000 */  swc1  $f16, ($s0)
/* 0D3788 7F09EC58 C6E8000C */  lwc1  $f8, 0xc($s7)
/* 0D378C 7F09EC5C E6080004 */  swc1  $f8, 4($s0)
/* 0D3790 7F09EC60 C6E60010 */  lwc1  $f6, 0x10($s7)
/* 0D3794 7F09EC64 0C002914 */  jal   randomGetNext
/* 0D3798 7F09EC68 E6060008 */   swc1  $f6, 8($s0)
/* 0D379C 7F09EC6C 44829000 */  mtc1  $v0, $f18
/* 0D37A0 7F09EC70 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0D37A4 7F09EC74 04410004 */  bgez  $v0, .L7F09EC88
/* 0D37A8 7F09EC78 46809120 */   cvt.s.w $f4, $f18
/* 0D37AC 7F09EC7C 44815000 */  mtc1  $at, $f10
/* 0D37B0 7F09EC80 00000000 */  nop   
/* 0D37B4 7F09EC84 460A2100 */  add.s $f4, $f4, $f10
.L7F09EC88:
/* 0D37B8 7F09EC88 46142402 */  mul.s $f16, $f4, $f20
/* 0D37BC 7F09EC8C 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 0D37C0 7F09EC90 44814000 */  mtc1  $at, $f8
/* 0D37C4 7F09EC94 00000000 */  nop   
/* 0D37C8 7F09EC98 46088182 */  mul.s $f6, $f16, $f8
/* 0D37CC 7F09EC9C 0C002914 */  jal   randomGetNext
/* 0D37D0 7F09ECA0 E6060018 */   swc1  $f6, 0x18($s0)
/* 0D37D4 7F09ECA4 44829000 */  mtc1  $v0, $f18
/* 0D37D8 7F09ECA8 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0D37DC 7F09ECAC 04410004 */  bgez  $v0, .L7F09ECC0
/* 0D37E0 7F09ECB0 468092A0 */   cvt.s.w $f10, $f18
/* 0D37E4 7F09ECB4 44812000 */  mtc1  $at, $f4
/* 0D37E8 7F09ECB8 00000000 */  nop   
/* 0D37EC 7F09ECBC 46045280 */  add.s $f10, $f10, $f4
.L7F09ECC0:
/* 0D37F0 7F09ECC0 46145402 */  mul.s $f16, $f10, $f20
/* 0D37F4 7F09ECC4 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 0D37F8 7F09ECC8 44814000 */  mtc1  $at, $f8
/* 0D37FC 7F09ECCC 00000000 */  nop   
/* 0D3800 7F09ECD0 46088182 */  mul.s $f6, $f16, $f8
/* 0D3804 7F09ECD4 E606001C */  swc1  $f6, 0x1c($s0)
/* 0D3808 7F09ECD8 86790006 */  lh    $t9, 6($s3)
/* 0D380C 7F09ECDC 86630004 */  lh    $v1, 4($s3)
/* 0D3810 7F09ECE0 03360019 */  multu $t9, $s6
/* 0D3814 7F09ECE4 00004012 */  mflo  $t0
/* 0D3818 7F09ECE8 02A82021 */  addu  $a0, $s5, $t0
/* 0D381C 7F09ECEC 84850000 */  lh    $a1, ($a0)
/* 0D3820 7F09ECF0 84860014 */  lh    $a2, 0x14($a0)
/* 0D3824 7F09ECF4 00A64823 */  subu  $t1, $a1, $a2
/* 0D3828 7F09ECF8 0123082A */  slt   $at, $t1, $v1
/* 0D382C 7F09ECFC 5020000E */  beql  $at, $zero, .L7F09ED38
/* 0D3830 7F09ED00 8FAB008C */   lw    $t3, 0x8c($sp)
/* 0D3834 7F09ED04 00A35023 */  subu  $t2, $a1, $v1
/* 0D3838 7F09ED08 448A9000 */  mtc1  $t2, $f18
/* 0D383C 7F09ED0C 44865000 */  mtc1  $a2, $f10
/* 0D3840 7F09ED10 C6060020 */  lwc1  $f6, 0x20($s0)
/* 0D3844 7F09ED14 46809120 */  cvt.s.w $f4, $f18
/* 0D3848 7F09ED18 46805420 */  cvt.s.w $f16, $f10
/* 0D384C 7F09ED1C 46102203 */  div.s $f8, $f4, $f16
/* 0D3850 7F09ED20 46083482 */  mul.s $f18, $f6, $f8
/* 0D3854 7F09ED24 10000003 */  b     .L7F09ED34
/* 0D3858 7F09ED28 E6120020 */   swc1  $f18, 0x20($s0)
.L7F09ED2C:
/* 0D385C 7F09ED2C 1654FF77 */  bne   $s2, $s4, .L7F09EB0C
/* 0D3860 7F09ED30 26310028 */   addiu $s1, $s1, 0x28
.L7F09ED34:
/* 0D3864 7F09ED34 8FAB008C */  lw    $t3, 0x8c($sp)
.L7F09ED38:
/* 0D3868 7F09ED38 27DE0001 */  addiu $fp, $fp, 1
/* 0D386C 7F09ED3C 57CBFF11 */  bnel  $fp, $t3, .L7F09E984
/* 0D3870 7F09ED40 86790004 */   lh    $t9, 4($s3)
.L7F09ED44:
/* 0D3874 7F09ED44 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0D3878 7F09ED48 44812000 */  mtc1  $at, $f4
/* 0D387C 7F09ED4C C6EA0008 */  lwc1  $f10, 8($s7)
/* 0D3880 7F09ED50 44814000 */  mtc1  $at, $f8
/* 0D3884 7F09ED54 4480D000 */  mtc1  $zero, $f26
/* 0D3888 7F09ED58 46045401 */  sub.s $f16, $f10, $f4
/* 0D388C 7F09ED5C 44812000 */  mtc1  $at, $f4
/* 0D3890 7F09ED60 3C158004 */  lui   $s5, %hi(array_smoke_types)
/* 0D3894 7F09ED64 26B5017C */  addiu $s5, %lo(array_smoke_types) # addiu $s5, $s5, 0x17c
/* 0D3898 7F09ED68 E7B000A8 */  swc1  $f16, 0xa8($sp)
/* 0D389C 7F09ED6C C6E6000C */  lwc1  $f6, 0xc($s7)
/* 0D38A0 7F09ED70 24160018 */  li    $s6, 24
/* 0D38A4 7F09ED74 00009025 */  move  $s2, $zero
/* 0D38A8 7F09ED78 46083481 */  sub.s $f18, $f6, $f8
/* 0D38AC 7F09ED7C 44814000 */  mtc1  $at, $f8
/* 0D38B0 7F09ED80 02608825 */  move  $s1, $s3
/* 0D38B4 7F09ED84 27B0009C */  addiu $s0, $sp, 0x9c
/* 0D38B8 7F09ED88 E7B200AC */  swc1  $f18, 0xac($sp)
/* 0D38BC 7F09ED8C C6EA0010 */  lwc1  $f10, 0x10($s7)
/* 0D38C0 7F09ED90 27A600B4 */  addiu $a2, $sp, 0xb4
/* 0D38C4 7F09ED94 4600D386 */  mov.s $f14, $f26
/* 0D38C8 7F09ED98 46045401 */  sub.s $f16, $f10, $f4
/* 0D38CC 7F09ED9C 44812000 */  mtc1  $at, $f4
/* 0D38D0 7F09EDA0 E7B000B0 */  swc1  $f16, 0xb0($sp)
/* 0D38D4 7F09EDA4 C6E60008 */  lwc1  $f6, 8($s7)
/* 0D38D8 7F09EDA8 46083480 */  add.s $f18, $f6, $f8
/* 0D38DC 7F09EDAC 44814000 */  mtc1  $at, $f8
/* 0D38E0 7F09EDB0 E7B2009C */  swc1  $f18, 0x9c($sp)
/* 0D38E4 7F09EDB4 C6EA000C */  lwc1  $f10, 0xc($s7)
/* 0D38E8 7F09EDB8 46045400 */  add.s $f16, $f10, $f4
/* 0D38EC 7F09EDBC E7B000A0 */  swc1  $f16, 0xa0($sp)
/* 0D38F0 7F09EDC0 C6E60010 */  lwc1  $f6, 0x10($s7)
/* 0D38F4 7F09EDC4 46083480 */  add.s $f18, $f6, $f8
/* 0D38F8 7F09EDC8 E7B200A4 */  swc1  $f18, 0xa4($sp)
.L7F09EDCC:
/* 0D38FC 7F09EDCC C62A0014 */  lwc1  $f10, 0x14($s1)
/* 0D3900 7F09EDD0 26520028 */  addiu $s2, $s2, 0x28
/* 0D3904 7F09EDD4 2A410190 */  slti  $at, $s2, 0x190
/* 0D3908 7F09EDD8 460AD032 */  c.eq.s $f26, $f10
/* 0D390C 7F09EDDC 00002025 */  move  $a0, $zero
/* 0D3910 7F09EDE0 02202825 */  move  $a1, $s1
/* 0D3914 7F09EDE4 27A200A8 */  addiu $v0, $sp, 0xa8
/* 0D3918 7F09EDE8 45010016 */  bc1t  .L7F09EE44
/* 0D391C 7F09EDEC 00000000 */   nop   
.L7F09EDF0:
/* 0D3920 7F09EDF0 C4A40008 */  lwc1  $f4, 8($a1)
/* 0D3924 7F09EDF4 C6300014 */  lwc1  $f16, 0x14($s1)
/* 0D3928 7F09EDF8 C4460000 */  lwc1  $f6, ($v0)
/* 0D392C 7F09EDFC 24A50004 */  addiu $a1, $a1, 4
/* 0D3930 7F09EE00 46102001 */  sub.s $f0, $f4, $f16
/* 0D3934 7F09EE04 02041821 */  addu  $v1, $s0, $a0
/* 0D3938 7F09EE08 4606003C */  c.lt.s $f0, $f6
/* 0D393C 7F09EE0C 00000000 */  nop   
/* 0D3940 7F09EE10 45020004 */  bc1fl .L7F09EE24
/* 0D3944 7F09EE14 C4680000 */   lwc1  $f8, ($v1)
/* 0D3948 7F09EE18 10000007 */  b     .L7F09EE38
/* 0D394C 7F09EE1C E4400000 */   swc1  $f0, ($v0)
/* 0D3950 7F09EE20 C4680000 */  lwc1  $f8, ($v1)
.L7F09EE24:
/* 0D3954 7F09EE24 4600403C */  c.lt.s $f8, $f0
/* 0D3958 7F09EE28 00000000 */  nop   
/* 0D395C 7F09EE2C 45020003 */  bc1fl .L7F09EE3C
/* 0D3960 7F09EE30 24420004 */   addiu $v0, $v0, 4
/* 0D3964 7F09EE34 E4600000 */  swc1  $f0, ($v1)
.L7F09EE38:
/* 0D3968 7F09EE38 24420004 */  addiu $v0, $v0, 4
.L7F09EE3C:
/* 0D396C 7F09EE3C 1446FFEC */  bne   $v0, $a2, .L7F09EDF0
/* 0D3970 7F09EE40 24840004 */   addiu $a0, $a0, 4
.L7F09EE44:
/* 0D3974 7F09EE44 1420FFE1 */  bnez  $at, .L7F09EDCC
/* 0D3978 7F09EE48 26310028 */   addiu $s1, $s1, 0x28
/* 0D397C 7F09EE4C C6E00008 */  lwc1  $f0, 8($s7)
/* 0D3980 7F09EE50 C7B200A8 */  lwc1  $f18, 0xa8($sp)
/* 0D3984 7F09EE54 C7AA00B0 */  lwc1  $f10, 0xb0($sp)
/* 0D3988 7F09EE58 C7A4009C */  lwc1  $f4, 0x9c($sp)
/* 0D398C 7F09EE5C 46120081 */  sub.s $f2, $f0, $f18
/* 0D3990 7F09EE60 C7B000A4 */  lwc1  $f16, 0xa4($sp)
/* 0D3994 7F09EE64 02E02025 */  move  $a0, $s7
/* 0D3998 7F09EE68 27A500A8 */  addiu $a1, $sp, 0xa8
/* 0D399C 7F09EE6C 4602D03C */  c.lt.s $f26, $f2
/* 0D39A0 7F09EE70 00000000 */  nop   
/* 0D39A4 7F09EE74 45020003 */  bc1fl .L7F09EE84
/* 0D39A8 7F09EE78 C6E20010 */   lwc1  $f2, 0x10($s7)
/* 0D39AC 7F09EE7C 46001386 */  mov.s $f14, $f2
/* 0D39B0 7F09EE80 C6E20010 */  lwc1  $f2, 0x10($s7)
.L7F09EE84:
/* 0D39B4 7F09EE84 460A1301 */  sub.s $f12, $f2, $f10
/* 0D39B8 7F09EE88 460C703C */  c.lt.s $f14, $f12
/* 0D39BC 7F09EE8C 00000000 */  nop   
/* 0D39C0 7F09EE90 45020003 */  bc1fl .L7F09EEA0
/* 0D39C4 7F09EE94 46002301 */   sub.s $f12, $f4, $f0
/* 0D39C8 7F09EE98 46006386 */  mov.s $f14, $f12
/* 0D39CC 7F09EE9C 46002301 */  sub.s $f12, $f4, $f0
.L7F09EEA0:
/* 0D39D0 7F09EEA0 46028001 */  sub.s $f0, $f16, $f2
/* 0D39D4 7F09EEA4 460C703C */  c.lt.s $f14, $f12
/* 0D39D8 7F09EEA8 00000000 */  nop   
/* 0D39DC 7F09EEAC 45020003 */  bc1fl .L7F09EEBC
/* 0D39E0 7F09EEB0 4600703C */   c.lt.s $f14, $f0
/* 0D39E4 7F09EEB4 46006386 */  mov.s $f14, $f12
/* 0D39E8 7F09EEB8 4600703C */  c.lt.s $f14, $f0
.L7F09EEBC:
/* 0D39EC 7F09EEBC 00000000 */  nop   
/* 0D39F0 7F09EEC0 45020003 */  bc1fl .L7F09EED0
/* 0D39F4 7F09EEC4 44077000 */   mfc1  $a3, $f14
/* 0D39F8 7F09EEC8 46000386 */  mov.s $f14, $f0
/* 0D39FC 7F09EECC 44077000 */  mfc1  $a3, $f14
.L7F09EED0:
/* 0D3A00 7F09EED0 0FC0F89F */  jal   sub_GAME_7F03E27C
/* 0D3A04 7F09EED4 02003025 */   move  $a2, $s0
/* 0D3A08 7F09EED8 866C0006 */  lh    $t4, 6($s3)
/* 0D3A0C 7F09EEDC 86780004 */  lh    $t8, 4($s3)
/* 0D3A10 7F09EEE0 00009025 */  move  $s2, $zero
/* 0D3A14 7F09EEE4 01960019 */  multu $t4, $s6
/* 0D3A18 7F09EEE8 02608825 */  move  $s1, $s3
/* 0D3A1C 7F09EEEC 24020190 */  li    $v0, 400
/* 0D3A20 7F09EEF0 00001825 */  move  $v1, $zero
/* 0D3A24 7F09EEF4 00006812 */  mflo  $t5
/* 0D3A28 7F09EEF8 02AD7021 */  addu  $t6, $s5, $t5
/* 0D3A2C 7F09EEFC 85CF0004 */  lh    $t7, 4($t6)
/* 0D3A30 7F09EF00 01F8082A */  slt   $at, $t7, $t8
/* 0D3A34 7F09EF04 1020000E */  beqz  $at, .L7F09EF40
/* 0D3A38 7F09EF08 00000000 */   nop   
/* 0D3A3C 7F09EF0C 24030001 */  li    $v1, 1
.L7F09EF10:
/* 0D3A40 7F09EF10 C6260014 */  lwc1  $f6, 0x14($s1)
/* 0D3A44 7F09EF14 26520028 */  addiu $s2, $s2, 0x28
/* 0D3A48 7F09EF18 4606D03C */  c.lt.s $f26, $f6
/* 0D3A4C 7F09EF1C 00000000 */  nop   
/* 0D3A50 7F09EF20 45000003 */  bc1f  .L7F09EF30
/* 0D3A54 7F09EF24 00000000 */   nop   
/* 0D3A58 7F09EF28 10000005 */  b     .L7F09EF40
/* 0D3A5C 7F09EF2C 00001825 */   move  $v1, $zero
.L7F09EF30:
/* 0D3A60 7F09EF30 1642FFF7 */  bne   $s2, $v0, .L7F09EF10
/* 0D3A64 7F09EF34 26310028 */   addiu $s1, $s1, 0x28
/* 0D3A68 7F09EF38 10000001 */  b     .L7F09EF40
/* 0D3A6C 7F09EF3C 00000000 */   nop   
.L7F09EF40:
/* 0D3A70 7F09EF40 10600004 */  beqz  $v1, .L7F09EF54
/* 0D3A74 7F09EF44 00001025 */   move  $v0, $zero
/* 0D3A78 7F09EF48 AE600000 */  sw    $zero, ($s3)
/* 0D3A7C 7F09EF4C 10000001 */  b     .L7F09EF54
/* 0D3A80 7F09EF50 24020001 */   li    $v0, 1
.L7F09EF54:
/* 0D3A84 7F09EF54 8FBF006C */  lw    $ra, 0x6c($sp)
/* 0D3A88 7F09EF58 D7B40018 */  ldc1  $f20, 0x18($sp)
/* 0D3A8C 7F09EF5C D7B60020 */  ldc1  $f22, 0x20($sp)
/* 0D3A90 7F09EF60 D7B80028 */  ldc1  $f24, 0x28($sp)
/* 0D3A94 7F09EF64 D7BA0030 */  ldc1  $f26, 0x30($sp)
/* 0D3A98 7F09EF68 D7BC0038 */  ldc1  $f28, 0x38($sp)
/* 0D3A9C 7F09EF6C D7BE0040 */  ldc1  $f30, 0x40($sp)
/* 0D3AA0 7F09EF70 8FB00048 */  lw    $s0, 0x48($sp)
/* 0D3AA4 7F09EF74 8FB1004C */  lw    $s1, 0x4c($sp)
/* 0D3AA8 7F09EF78 8FB20050 */  lw    $s2, 0x50($sp)
/* 0D3AAC 7F09EF7C 8FB30054 */  lw    $s3, 0x54($sp)
/* 0D3AB0 7F09EF80 8FB40058 */  lw    $s4, 0x58($sp)
/* 0D3AB4 7F09EF84 8FB5005C */  lw    $s5, 0x5c($sp)
/* 0D3AB8 7F09EF88 8FB60060 */  lw    $s6, 0x60($sp)
/* 0D3ABC 7F09EF8C 8FB70064 */  lw    $s7, 0x64($sp)
/* 0D3AC0 7F09EF90 8FBE0068 */  lw    $fp, 0x68($sp)
/* 0D3AC4 7F09EF94 03E00008 */  jr    $ra
/* 0D3AC8 7F09EF98 27BD00D0 */   addiu $sp, $sp, 0xd0
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F09EF9C(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F09EF9C
/* 0D3ACC 7F09EF9C 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0D3AD0 7F09EFA0 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0D3AD4 7F09EFA4 0FC1E0F1 */  jal   currentPlayerGetMatrix10CC
/* 0D3AD8 7F09EFA8 AFA40018 */   sw    $a0, 0x18($sp)
/* 0D3ADC 7F09EFAC 8FA40018 */  lw    $a0, 0x18($sp)
/* 0D3AE0 7F09EFB0 C4440008 */  lwc1  $f4, 8($v0)
/* 0D3AE4 7F09EFB4 C44A0018 */  lwc1  $f10, 0x18($v0)
/* 0D3AE8 7F09EFB8 C4860008 */  lwc1  $f6, 8($a0)
/* 0D3AEC 7F09EFBC C490000C */  lwc1  $f16, 0xc($a0)
/* 0D3AF0 7F09EFC0 3C0142C8 */  li    $at, 0x42C80000 # 100.000000
/* 0D3AF4 7F09EFC4 46062202 */  mul.s $f8, $f4, $f6
/* 0D3AF8 7F09EFC8 C4460028 */  lwc1  $f6, 0x28($v0)
/* 0D3AFC 7F09EFCC 44811000 */  mtc1  $at, $f2
/* 0D3B00 7F09EFD0 46105482 */  mul.s $f18, $f10, $f16
/* 0D3B04 7F09EFD4 C48A0010 */  lwc1  $f10, 0x10($a0)
/* 0D3B08 7F09EFD8 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 0D3B0C 7F09EFDC 460A3402 */  mul.s $f16, $f6, $f10
/* 0D3B10 7F09EFE0 46124100 */  add.s $f4, $f8, $f18
/* 0D3B14 7F09EFE4 C4520038 */  lwc1  $f18, 0x38($v0)
/* 0D3B18 7F09EFE8 46102200 */  add.s $f8, $f4, $f16
/* 0D3B1C 7F09EFEC 46089180 */  add.s $f6, $f18, $f8
/* 0D3B20 7F09EFF0 46003287 */  neg.s $f10, $f6
/* 0D3B24 7F09EFF4 E48A0018 */  swc1  $f10, 0x18($a0)
/* 0D3B28 7F09EFF8 C4800018 */  lwc1  $f0, 0x18($a0)
/* 0D3B2C 7F09EFFC 4602003C */  c.lt.s $f0, $f2
/* 0D3B30 7F09F000 00000000 */  nop   
/* 0D3B34 7F09F004 45020007 */  bc1fl .L7F09F024
/* 0D3B38 7F09F008 46020481 */   sub.s $f18, $f0, $f2
/* 0D3B3C 7F09F00C 44812000 */  mtc1  $at, $f4
/* 0D3B40 7F09F010 00000000 */  nop   
/* 0D3B44 7F09F014 46040402 */  mul.s $f16, $f0, $f4
/* 0D3B48 7F09F018 10000003 */  b     .L7F09F028
/* 0D3B4C 7F09F01C E4900018 */   swc1  $f16, 0x18($a0)
/* 0D3B50 7F09F020 46020481 */  sub.s $f18, $f0, $f2
.L7F09F024:
/* 0D3B54 7F09F024 E4920018 */  swc1  $f18, 0x18($a0)
.L7F09F028:
/* 0D3B58 7F09F028 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0D3B5C 7F09F02C 27BD0018 */  addiu $sp, $sp, 0x18
/* 0D3B60 7F09F030 00001025 */  move  $v0, $zero
/* 0D3B64 7F09F034 03E00008 */  jr    $ra
/* 0D3B68 7F09F038 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void unk09c250RenderPropSmoke(void) {

}
#else
GLOBAL_ASM(
.text
glabel unk09c250RenderPropSmoke
/* 0D3B6C 7F09F03C 27BDFF70 */  addiu $sp, $sp, -0x90
/* 0D3B70 7F09F040 AFB00024 */  sw    $s0, 0x24($sp)
/* 0D3B74 7F09F044 AFBF003C */  sw    $ra, 0x3c($sp)
/* 0D3B78 7F09F048 AFB50038 */  sw    $s5, 0x38($sp)
/* 0D3B7C 7F09F04C AFB40034 */  sw    $s4, 0x34($sp)
/* 0D3B80 7F09F050 AFB30030 */  sw    $s3, 0x30($sp)
/* 0D3B84 7F09F054 AFB2002C */  sw    $s2, 0x2c($sp)
/* 0D3B88 7F09F058 AFB10028 */  sw    $s1, 0x28($sp)
/* 0D3B8C 7F09F05C F7B40018 */  sdc1  $f20, 0x18($sp)
/* 0D3B90 7F09F060 9091002C */  lbu   $s1, 0x2c($a0)
/* 0D3B94 7F09F064 00808025 */  move  $s0, $a0
/* 0D3B98 7F09F068 8C940004 */  lw    $s4, 4($a0)
/* 0D3B9C 7F09F06C 00A09025 */  move  $s2, $a1
/* 0D3BA0 7F09F070 00C09825 */  move  $s3, $a2
/* 0D3BA4 7F09F074 0FC2F285 */  jal   getRoomIndexPOS
/* 0D3BA8 7F09F078 02202025 */   move  $a0, $s1
/* 0D3BAC 7F09F07C 16600003 */  bnez  $s3, .L7F09F08C
/* 0D3BB0 7F09F080 0040A825 */   move  $s5, $v0
/* 0D3BB4 7F09F084 10000069 */  b     .L7F09F22C
/* 0D3BB8 7F09F088 02401025 */   move  $v0, $s2
.L7F09F08C:
/* 0D3BBC 7F09F08C 02002025 */  move  $a0, $s0
/* 0D3BC0 7F09F090 0FC15299 */  jal   sub_GAME_7F054A64
/* 0D3BC4 7F09F094 27A50078 */   addiu $a1, $sp, 0x78
/* 0D3BC8 7F09F098 1840000A */  blez  $v0, .L7F09F0C4
/* 0D3BCC 7F09F09C 00000000 */   nop   
/* 0D3BD0 7F09F0A0 C7A40084 */  lwc1  $f4, 0x84($sp)
/* 0D3BD4 7F09F0A4 02402025 */  move  $a0, $s2
/* 0D3BD8 7F09F0A8 8FA50078 */  lw    $a1, 0x78($sp)
/* 0D3BDC 7F09F0AC 8FA6007C */  lw    $a2, 0x7c($sp)
/* 0D3BE0 7F09F0B0 8FA70080 */  lw    $a3, 0x80($sp)
/* 0D3BE4 7F09F0B4 0FC2D3FD */  jal   bgScissorCurrentPlayerViewF
/* 0D3BE8 7F09F0B8 E7A40010 */   swc1  $f4, 0x10($sp)
/* 0D3BEC 7F09F0BC 10000004 */  b     .L7F09F0D0
/* 0D3BF0 7F09F0C0 00409025 */   move  $s2, $v0
.L7F09F0C4:
/* 0D3BF4 7F09F0C4 0FC2D3ED */  jal   bgScissorCurrentPlayerViewDefault
/* 0D3BF8 7F09F0C8 02402025 */   move  $a0, $s2
/* 0D3BFC 7F09F0CC 00409025 */  move  $s2, $v0
.L7F09F0D0:
/* 0D3C00 7F09F0D0 02401025 */  move  $v0, $s2
/* 0D3C04 7F09F0D4 3C0F0001 */  lui   $t7, (0x00013000 >> 16) # lui $t7, 1
/* 0D3C08 7F09F0D8 35EF3000 */  ori   $t7, (0x00013000 & 0xFFFF) # ori $t7, $t7, 0x3000
/* 0D3C0C 7F09F0DC 26520008 */  addiu $s2, $s2, 8
/* 0D3C10 7F09F0E0 3C0EB600 */  lui   $t6, 0xb600
/* 0D3C14 7F09F0E4 3C180103 */  lui   $t8, (0x01030040 >> 16) # lui $t8, 0x103
/* 0D3C18 7F09F0E8 AC4E0000 */  sw    $t6, ($v0)
/* 0D3C1C 7F09F0EC AC4F0004 */  sw    $t7, 4($v0)
/* 0D3C20 7F09F0F0 37180040 */  ori   $t8, (0x01030040 & 0xFFFF) # ori $t8, $t8, 0x40
/* 0D3C24 7F09F0F4 02408025 */  move  $s0, $s2
/* 0D3C28 7F09F0F8 AE180000 */  sw    $t8, ($s0)
/* 0D3C2C 7F09F0FC 0FC1E0E5 */  jal   get_BONDdata_field_10E0
/* 0D3C30 7F09F100 26520008 */   addiu $s2, $s2, 8
/* 0D3C34 7F09F104 0C003A2C */  jal   osVirtualToPhysical
/* 0D3C38 7F09F108 00402025 */   move  $a0, $v0
/* 0D3C3C 7F09F10C AE020004 */  sw    $v0, 4($s0)
/* 0D3C40 7F09F110 02402025 */  move  $a0, $s2
/* 0D3C44 7F09F114 0FC2F271 */  jal   sub_GAME_7F0BC9C4
/* 0D3C48 7F09F118 02202825 */   move  $a1, $s1
/* 0D3C4C 7F09F11C 3C190100 */  lui   $t9, (0x01000040 >> 16) # lui $t9, 0x100
/* 0D3C50 7F09F120 37390040 */  ori   $t9, (0x01000040 & 0xFFFF) # ori $t9, $t9, 0x40
/* 0D3C54 7F09F124 3C048008 */  lui   $a0, %hi(dword_CODE_bss_8007A100)
/* 0D3C58 7F09F128 2484A100 */  addiu $a0, %lo(dword_CODE_bss_8007A100) # addiu $a0, $a0, -0x5f00
/* 0D3C5C 7F09F12C AC590000 */  sw    $t9, ($v0)
/* 0D3C60 7F09F130 00408025 */  move  $s0, $v0
/* 0D3C64 7F09F134 0C003A2C */  jal   osVirtualToPhysical
/* 0D3C68 7F09F138 24520008 */   addiu $s2, $v0, 8
/* 0D3C6C 7F09F13C 3C08BC00 */  lui   $t0, (0xBC000806 >> 16) # lui $t0, 0xbc00
/* 0D3C70 7F09F140 AE020004 */  sw    $v0, 4($s0)
/* 0D3C74 7F09F144 35080806 */  ori   $t0, (0xBC000806 & 0xFFFF) # ori $t0, $t0, 0x806
/* 0D3C78 7F09F148 02409825 */  move  $s3, $s2
/* 0D3C7C 7F09F14C AE680000 */  sw    $t0, ($s3)
/* 0D3C80 7F09F150 3C048009 */  lui   $a0, %hi(pGlobalimagetable)
/* 0D3C84 7F09F154 8C84D0B4 */  lw    $a0, %lo(pGlobalimagetable)($a0)
/* 0D3C88 7F09F158 0C003A2C */  jal   osVirtualToPhysical
/* 0D3C8C 7F09F15C 26520008 */   addiu $s2, $s2, 8
/* 0D3C90 7F09F160 AE620004 */  sw    $v0, 4($s3)
/* 0D3C94 7F09F164 02401825 */  move  $v1, $s2
/* 0D3C98 7F09F168 26520008 */  addiu $s2, $s2, 8
/* 0D3C9C 7F09F16C 3C0A0200 */  lui   $t2, 0x200
/* 0D3CA0 7F09F170 254A0000 */  addiu $t2, $t2, 0
/* 0D3CA4 7F09F174 3C090600 */  lui   $t1, 0x600
/* 0D3CA8 7F09F178 02402025 */  move  $a0, $s2
/* 0D3CAC 7F09F17C AC690000 */  sw    $t1, ($v1)
/* 0D3CB0 7F09F180 AC6A0004 */  sw    $t2, 4($v1)
/* 0D3CB4 7F09F184 3C0BBA00 */  lui   $t3, (0xBA000602 >> 16) # lui $t3, 0xba00
/* 0D3CB8 7F09F188 356B0602 */  ori   $t3, (0xBA000602 & 0xFFFF) # ori $t3, $t3, 0x602
/* 0D3CBC 7F09F18C 240C0080 */  li    $t4, 128
/* 0D3CC0 7F09F190 4480A000 */  mtc1  $zero, $f20
/* 0D3CC4 7F09F194 AC8C0004 */  sw    $t4, 4($a0)
/* 0D3CC8 7F09F198 AC8B0000 */  sw    $t3, ($a0)
/* 0D3CCC 7F09F19C 26520008 */  addiu $s2, $s2, 8
/* 0D3CD0 7F09F1A0 24130190 */  li    $s3, 400
/* 0D3CD4 7F09F1A4 00008825 */  move  $s1, $zero
/* 0D3CD8 7F09F1A8 02808025 */  move  $s0, $s4
.L7F09F1AC:
/* 0D3CDC 7F09F1AC C6060014 */  lwc1  $f6, 0x14($s0)
/* 0D3CE0 7F09F1B0 02802025 */  move  $a0, $s4
/* 0D3CE4 7F09F1B4 26050008 */  addiu $a1, $s0, 8
/* 0D3CE8 7F09F1B8 4606A03C */  c.lt.s $f20, $f6
/* 0D3CEC 7F09F1BC 02403025 */  move  $a2, $s2
/* 0D3CF0 7F09F1C0 45020006 */  bc1fl .L7F09F1DC
/* 0D3CF4 7F09F1C4 E6140014 */   swc1  $f20, 0x14($s0)
/* 0D3CF8 7F09F1C8 0FC27769 */  jal   sub_GAME_7F09DDA4
/* 0D3CFC 7F09F1CC 02A03825 */   move  $a3, $s5
/* 0D3D00 7F09F1D0 10000002 */  b     .L7F09F1DC
/* 0D3D04 7F09F1D4 00409025 */   move  $s2, $v0
/* 0D3D08 7F09F1D8 E6140014 */  swc1  $f20, 0x14($s0)
.L7F09F1DC:
/* 0D3D0C 7F09F1DC 26310028 */  addiu $s1, $s1, 0x28
/* 0D3D10 7F09F1E0 1633FFF2 */  bne   $s1, $s3, .L7F09F1AC
/* 0D3D14 7F09F1E4 26100028 */   addiu $s0, $s0, 0x28
/* 0D3D18 7F09F1E8 02401025 */  move  $v0, $s2
/* 0D3D1C 7F09F1EC 3C0DBA00 */  lui   $t5, (0xBA000602 >> 16) # lui $t5, 0xba00
/* 0D3D20 7F09F1F0 35AD0602 */  ori   $t5, (0xBA000602 & 0xFFFF) # ori $t5, $t5, 0x602
/* 0D3D24 7F09F1F4 26520008 */  addiu $s2, $s2, 8
/* 0D3D28 7F09F1F8 240E0040 */  li    $t6, 64
/* 0D3D2C 7F09F1FC 3C0F0103 */  lui   $t7, (0x01030040 >> 16) # lui $t7, 0x103
/* 0D3D30 7F09F200 AC4E0004 */  sw    $t6, 4($v0)
/* 0D3D34 7F09F204 AC4D0000 */  sw    $t5, ($v0)
/* 0D3D38 7F09F208 35EF0040 */  ori   $t7, (0x01030040 & 0xFFFF) # ori $t7, $t7, 0x40
/* 0D3D3C 7F09F20C 02408025 */  move  $s0, $s2
/* 0D3D40 7F09F210 AE0F0000 */  sw    $t7, ($s0)
/* 0D3D44 7F09F214 0FC1E0DD */  jal   currentPlayerGetProjectionMatrix
/* 0D3D48 7F09F218 26520008 */   addiu $s2, $s2, 8
/* 0D3D4C 7F09F21C 0C003A2C */  jal   osVirtualToPhysical
/* 0D3D50 7F09F220 00402025 */   move  $a0, $v0
/* 0D3D54 7F09F224 AE020004 */  sw    $v0, 4($s0)
/* 0D3D58 7F09F228 02401025 */  move  $v0, $s2
.L7F09F22C:
/* 0D3D5C 7F09F22C 8FBF003C */  lw    $ra, 0x3c($sp)
/* 0D3D60 7F09F230 D7B40018 */  ldc1  $f20, 0x18($sp)
/* 0D3D64 7F09F234 8FB00024 */  lw    $s0, 0x24($sp)
/* 0D3D68 7F09F238 8FB10028 */  lw    $s1, 0x28($sp)
/* 0D3D6C 7F09F23C 8FB2002C */  lw    $s2, 0x2c($sp)
/* 0D3D70 7F09F240 8FB30030 */  lw    $s3, 0x30($sp)
/* 0D3D74 7F09F244 8FB40034 */  lw    $s4, 0x34($sp)
/* 0D3D78 7F09F248 8FB50038 */  lw    $s5, 0x38($sp)
/* 0D3D7C 7F09F24C 03E00008 */  jr    $ra
/* 0D3D80 7F09F250 27BD0090 */   addiu $sp, $sp, 0x90
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F09F254(void) {

}
#else
GLOBAL_ASM(
.late_rodata
glabel D_800576E0
.word 0x3f8f5c29 /*1.12*/
glabel D_800576E4
.word 0x3df5c28f /*0.12*/
glabel D_800576E8
.word 0x40c90fdb /*6.2831855*/
glabel D_800576EC
.word 0x3dcccccd /*0.1*/
.text
glabel sub_GAME_7F09F254
/* 0D3D84 7F09F254 27BDFFB0 */  addiu $sp, $sp, -0x50
/* 0D3D88 7F09F258 AFBF0034 */  sw    $ra, 0x34($sp)
/* 0D3D8C 7F09F25C AFB20030 */  sw    $s2, 0x30($sp)
/* 0D3D90 7F09F260 AFB1002C */  sw    $s1, 0x2c($sp)
/* 0D3D94 7F09F264 AFB00028 */  sw    $s0, 0x28($sp)
/* 0D3D98 7F09F268 F7B60020 */  sdc1  $f22, 0x20($sp)
/* 0D3D9C 7F09F26C F7B40018 */  sdc1  $f20, 0x18($sp)
/* 0D3DA0 7F09F270 AFA40050 */  sw    $a0, 0x50($sp)
/* 0D3DA4 7F09F274 AFA50054 */  sw    $a1, 0x54($sp)
/* 0D3DA8 7F09F278 AFA60058 */  sw    $a2, 0x58($sp)
/* 0D3DAC 7F09F27C 0C002914 */  jal   randomGetNext
/* 0D3DB0 7F09F280 AFA7005C */   sw    $a3, 0x5c($sp)
/* 0D3DB4 7F09F284 44822000 */  mtc1  $v0, $f4
/* 0D3DB8 7F09F288 3C012F80 */  li    $at, 0x2F800000 # 0.000000
/* 0D3DBC 7F09F28C 4481B000 */  mtc1  $at, $f22
/* 0D3DC0 7F09F290 04410005 */  bgez  $v0, .L7F09F2A8
/* 0D3DC4 7F09F294 468021A0 */   cvt.s.w $f6, $f4
/* 0D3DC8 7F09F298 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0D3DCC 7F09F29C 44814000 */  mtc1  $at, $f8
/* 0D3DD0 7F09F2A0 00000000 */  nop   
/* 0D3DD4 7F09F2A4 46083180 */  add.s $f6, $f6, $f8
.L7F09F2A8:
/* 0D3DD8 7F09F2A8 46163002 */  mul.s $f0, $f6, $f22
/* 0D3DDC 7F09F2AC 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0D3DE0 7F09F2B0 44819000 */  mtc1  $at, $f18
/* 0D3DE4 7F09F2B4 46000280 */  add.s $f10, $f0, $f0
/* 0D3DE8 7F09F2B8 0C002914 */  jal   randomGetNext
/* 0D3DEC 7F09F2BC 46125501 */   sub.s $f20, $f10, $f18
/* 0D3DF0 7F09F2C0 44822000 */  mtc1  $v0, $f4
/* 0D3DF4 7F09F2C4 04410005 */  bgez  $v0, .L7F09F2DC
/* 0D3DF8 7F09F2C8 46802220 */   cvt.s.w $f8, $f4
/* 0D3DFC 7F09F2CC 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0D3E00 7F09F2D0 44813000 */  mtc1  $at, $f6
/* 0D3E04 7F09F2D4 00000000 */  nop   
/* 0D3E08 7F09F2D8 46064200 */  add.s $f8, $f8, $f6
.L7F09F2DC:
/* 0D3E0C 7F09F2DC 46164282 */  mul.s $f10, $f8, $f22
/* 0D3E10 7F09F2E0 3C018005 */  lui   $at, %hi(D_800576E0)
/* 0D3E14 7F09F2E4 C43276E0 */  lwc1  $f18, %lo(D_800576E0)($at)
/* 0D3E18 7F09F2E8 3C018005 */  lui   $at, %hi(D_800576E4)
/* 0D3E1C 7F09F2EC C42676E4 */  lwc1  $f6, %lo(D_800576E4)($at)
/* 0D3E20 7F09F2F0 46125102 */  mul.s $f4, $f10, $f18
/* 0D3E24 7F09F2F4 46062301 */  sub.s $f12, $f4, $f6
/* 0D3E28 7F09F2F8 0C002914 */  jal   randomGetNext
/* 0D3E2C 7F09F2FC E7AC0048 */   swc1  $f12, 0x48($sp)
/* 0D3E30 7F09F300 3C128004 */  lui   $s2, %hi(numCasingEntries)
/* 0D3E34 7F09F304 26520800 */  addiu $s2, %lo(numCasingEntries) # addiu $s2, $s2, 0x800
/* 0D3E38 7F09F308 8E580000 */  lw    $t8, ($s2)
/* 0D3E3C 7F09F30C 24110078 */  li    $s1, 120
/* 0D3E40 7F09F310 3C108008 */  lui   $s0, %hi(ptr_ejected_casing_buf)
/* 0D3E44 7F09F314 03110019 */  multu $t8, $s1
/* 0D3E48 7F09F318 2610A14C */  addiu $s0, %lo(ptr_ejected_casing_buf) # addiu $s0, $s0, -0x5eb4
/* 0D3E4C 7F09F31C 8E0F0000 */  lw    $t7, ($s0)
/* 0D3E50 7F09F320 8FA30050 */  lw    $v1, 0x50($sp)
/* 0D3E54 7F09F324 C7AC0048 */  lwc1  $f12, 0x48($sp)
/* 0D3E58 7F09F328 C7AE0054 */  lwc1  $f14, 0x54($sp)
/* 0D3E5C 7F09F32C C7B00058 */  lwc1  $f16, 0x58($sp)
/* 0D3E60 7F09F330 240E0001 */  li    $t6, 1
/* 0D3E64 7F09F334 46147282 */  mul.s $f10, $f14, $f20
/* 0D3E68 7F09F338 0000C812 */  mflo  $t9
/* 0D3E6C 7F09F33C 01F94021 */  addu  $t0, $t7, $t9
/* 0D3E70 7F09F340 AD0E0000 */  sw    $t6, ($t0)
/* 0D3E74 7F09F344 8E4A0000 */  lw    $t2, ($s2)
/* 0D3E78 7F09F348 C4680000 */  lwc1  $f8, ($v1)
/* 0D3E7C 7F09F34C 8E090000 */  lw    $t1, ($s0)
/* 0D3E80 7F09F350 01510019 */  multu $t2, $s1
/* 0D3E84 7F09F354 460A4480 */  add.s $f18, $f8, $f10
/* 0D3E88 7F09F358 460C7182 */  mul.s $f6, $f14, $f12
/* 0D3E8C 7F09F35C 44825000 */  mtc1  $v0, $f10
/* 0D3E90 7F09F360 00005812 */  mflo  $t3
/* 0D3E94 7F09F364 012B6021 */  addu  $t4, $t1, $t3
/* 0D3E98 7F09F368 E5920004 */  swc1  $f18, 4($t4)
/* 0D3E9C 7F09F36C 8E580000 */  lw    $t8, ($s2)
/* 0D3EA0 7F09F370 C4640004 */  lwc1  $f4, 4($v1)
/* 0D3EA4 7F09F374 8E0D0000 */  lw    $t5, ($s0)
/* 0D3EA8 7F09F378 03110019 */  multu $t8, $s1
/* 0D3EAC 7F09F37C 46062200 */  add.s $f8, $f4, $f6
/* 0D3EB0 7F09F380 468054A0 */  cvt.s.w $f18, $f10
/* 0D3EB4 7F09F384 00007812 */  mflo  $t7
/* 0D3EB8 7F09F388 01AFC821 */  addu  $t9, $t5, $t7
/* 0D3EBC 7F09F38C 04410005 */  bgez  $v0, .L7F09F3A4
/* 0D3EC0 7F09F390 E7280008 */   swc1  $f8, 8($t9)
/* 0D3EC4 7F09F394 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0D3EC8 7F09F398 44812000 */  mtc1  $at, $f4
/* 0D3ECC 7F09F39C 00000000 */  nop   
/* 0D3ED0 7F09F3A0 46049480 */  add.s $f18, $f18, $f4
.L7F09F3A4:
/* 0D3ED4 7F09F3A4 46169002 */  mul.s $f0, $f18, $f22
/* 0D3ED8 7F09F3A8 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0D3EDC 7F09F3AC 44814000 */  mtc1  $at, $f8
/* 0D3EE0 7F09F3B0 8E480000 */  lw    $t0, ($s2)
/* 0D3EE4 7F09F3B4 C46A0008 */  lwc1  $f10, 8($v1)
/* 0D3EE8 7F09F3B8 8E0E0000 */  lw    $t6, ($s0)
/* 0D3EEC 7F09F3BC 01110019 */  multu $t0, $s1
/* 0D3EF0 7F09F3C0 46000180 */  add.s $f6, $f0, $f0
/* 0D3EF4 7F09F3C4 46083081 */  sub.s $f2, $f6, $f8
/* 0D3EF8 7F09F3C8 46027102 */  mul.s $f4, $f14, $f2
/* 0D3EFC 7F09F3CC 00005012 */  mflo  $t2
/* 0D3F00 7F09F3D0 01CA4821 */  addu  $t1, $t6, $t2
/* 0D3F04 7F09F3D4 4610A182 */  mul.s $f6, $f20, $f16
/* 0D3F08 7F09F3D8 46045480 */  add.s $f18, $f10, $f4
/* 0D3F0C 7F09F3DC E532000C */  swc1  $f18, 0xc($t1)
/* 0D3F10 7F09F3E0 8E4C0000 */  lw    $t4, ($s2)
/* 0D3F14 7F09F3E4 8E0B0000 */  lw    $t3, ($s0)
/* 0D3F18 7F09F3E8 01910019 */  multu $t4, $s1
/* 0D3F1C 7F09F3EC 0000C012 */  mflo  $t8
/* 0D3F20 7F09F3F0 01786821 */  addu  $t5, $t3, $t8
/* 0D3F24 7F09F3F4 E5A6001C */  swc1  $f6, 0x1c($t5)
/* 0D3F28 7F09F3F8 8E590000 */  lw    $t9, ($s2)
/* 0D3F2C 7F09F3FC C7A8005C */  lwc1  $f8, 0x5c($sp)
/* 0D3F30 7F09F400 8E0F0000 */  lw    $t7, ($s0)
/* 0D3F34 7F09F404 03310019 */  multu $t9, $s1
/* 0D3F38 7F09F408 46086282 */  mul.s $f10, $f12, $f8
/* 0D3F3C 7F09F40C 00000000 */  nop   
/* 0D3F40 7F09F410 46101102 */  mul.s $f4, $f2, $f16
/* 0D3F44 7F09F414 00004012 */  mflo  $t0
/* 0D3F48 7F09F418 01E87021 */  addu  $t6, $t7, $t0
/* 0D3F4C 7F09F41C E5CA0020 */  swc1  $f10, 0x20($t6)
/* 0D3F50 7F09F420 8E490000 */  lw    $t1, ($s2)
/* 0D3F54 7F09F424 8E0A0000 */  lw    $t2, ($s0)
/* 0D3F58 7F09F428 01310019 */  multu $t1, $s1
/* 0D3F5C 7F09F42C 00006012 */  mflo  $t4
/* 0D3F60 7F09F430 014C5821 */  addu  $t3, $t2, $t4
/* 0D3F64 7F09F434 0C002914 */  jal   randomGetNext
/* 0D3F68 7F09F438 E5640024 */   swc1  $f4, 0x24($t3)
/* 0D3F6C 7F09F43C 44829000 */  mtc1  $v0, $f18
/* 0D3F70 7F09F440 3C013F40 */  li    $at, 0x3F400000 # 0.750000
/* 0D3F74 7F09F444 4481A000 */  mtc1  $at, $f20
/* 0D3F78 7F09F448 04410005 */  bgez  $v0, .L7F09F460
/* 0D3F7C 7F09F44C 468091A0 */   cvt.s.w $f6, $f18
/* 0D3F80 7F09F450 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0D3F84 7F09F454 44814000 */  mtc1  $at, $f8
/* 0D3F88 7F09F458 00000000 */  nop   
/* 0D3F8C 7F09F45C 46083180 */  add.s $f6, $f6, $f8
.L7F09F460:
/* 0D3F90 7F09F460 46163282 */  mul.s $f10, $f6, $f22
/* 0D3F94 7F09F464 C7A80060 */  lwc1  $f8, 0x60($sp)
/* 0D3F98 7F09F468 8E4F0000 */  lw    $t7, ($s2)
/* 0D3F9C 7F09F46C 8E190000 */  lw    $t9, ($s0)
/* 0D3FA0 7F09F470 01F10019 */  multu $t7, $s1
/* 0D3FA4 7F09F474 46145102 */  mul.s $f4, $f10, $f20
/* 0D3FA8 7F09F478 46142480 */  add.s $f18, $f4, $f20
/* 0D3FAC 7F09F47C 00004012 */  mflo  $t0
/* 0D3FB0 7F09F480 03287021 */  addu  $t6, $t9, $t0
/* 0D3FB4 7F09F484 46089182 */  mul.s $f6, $f18, $f8
/* 0D3FB8 7F09F488 4600328D */  trunc.w.s $f10, $f6
/* 0D3FBC 7F09F48C 440D5000 */  mfc1  $t5, $f10
/* 0D3FC0 7F09F490 00000000 */  nop   
/* 0D3FC4 7F09F494 A5CD0038 */  sh    $t5, 0x38($t6)
/* 0D3FC8 7F09F498 8E4A0000 */  lw    $t2, ($s2)
/* 0D3FCC 7F09F49C 8E090000 */  lw    $t1, ($s0)
/* 0D3FD0 7F09F4A0 01510019 */  multu $t2, $s1
/* 0D3FD4 7F09F4A4 00006012 */  mflo  $t4
/* 0D3FD8 7F09F4A8 012C5821 */  addu  $t3, $t1, $t4
/* 0D3FDC 7F09F4AC 0C002914 */  jal   randomGetNext
/* 0D3FE0 7F09F4B0 A560003A */   sh    $zero, 0x3a($t3)
/* 0D3FE4 7F09F4B4 44822000 */  mtc1  $v0, $f4
/* 0D3FE8 7F09F4B8 04410005 */  bgez  $v0, .L7F09F4D0
/* 0D3FEC 7F09F4BC 468024A0 */   cvt.s.w $f18, $f4
/* 0D3FF0 7F09F4C0 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0D3FF4 7F09F4C4 44814000 */  mtc1  $at, $f8
/* 0D3FF8 7F09F4C8 00000000 */  nop   
/* 0D3FFC 7F09F4CC 46089480 */  add.s $f18, $f18, $f8
.L7F09F4D0:
/* 0D4000 7F09F4D0 46169182 */  mul.s $f6, $f18, $f22
/* 0D4004 7F09F4D4 C7A80060 */  lwc1  $f8, 0x60($sp)
/* 0D4008 7F09F4D8 8E480000 */  lw    $t0, ($s2)
/* 0D400C 7F09F4DC 8E190000 */  lw    $t9, ($s0)
/* 0D4010 7F09F4E0 01110019 */  multu $t0, $s1
/* 0D4014 7F09F4E4 46143282 */  mul.s $f10, $f6, $f20
/* 0D4018 7F09F4E8 46145100 */  add.s $f4, $f10, $f20
/* 0D401C 7F09F4EC 00006812 */  mflo  $t5
/* 0D4020 7F09F4F0 032D7021 */  addu  $t6, $t9, $t5
/* 0D4024 7F09F4F4 46082482 */  mul.s $f18, $f4, $f8
/* 0D4028 7F09F4F8 4600918D */  trunc.w.s $f6, $f18
/* 0D402C 7F09F4FC 440F3000 */  mfc1  $t7, $f6
/* 0D4030 7F09F500 0C002914 */  jal   randomGetNext
/* 0D4034 7F09F504 A5CF003C */   sh    $t7, 0x3c($t6)
/* 0D4038 7F09F508 44825000 */  mtc1  $v0, $f10
/* 0D403C 7F09F50C 04410005 */  bgez  $v0, .L7F09F524
/* 0D4040 7F09F510 46805120 */   cvt.s.w $f4, $f10
/* 0D4044 7F09F514 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0D4048 7F09F518 44814000 */  mtc1  $at, $f8
/* 0D404C 7F09F51C 00000000 */  nop   
/* 0D4050 7F09F520 46082100 */  add.s $f4, $f4, $f8
.L7F09F524:
/* 0D4054 7F09F524 46162482 */  mul.s $f18, $f4, $f22
/* 0D4058 7F09F528 C7A80060 */  lwc1  $f8, 0x60($sp)
/* 0D405C 7F09F52C 8E4B0000 */  lw    $t3, ($s2)
/* 0D4060 7F09F530 8E0C0000 */  lw    $t4, ($s0)
/* 0D4064 7F09F534 01710019 */  multu $t3, $s1
/* 0D4068 7F09F538 46149182 */  mul.s $f6, $f18, $f20
/* 0D406C 7F09F53C 46143280 */  add.s $f10, $f6, $f20
/* 0D4070 7F09F540 0000C012 */  mflo  $t8
/* 0D4074 7F09F544 01984021 */  addu  $t0, $t4, $t8
/* 0D4078 7F09F548 46085102 */  mul.s $f4, $f10, $f8
/* 0D407C 7F09F54C 4600248D */  trunc.w.s $f18, $f4
/* 0D4080 7F09F550 44099000 */  mfc1  $t1, $f18
/* 0D4084 7F09F554 00000000 */  nop   
/* 0D4088 7F09F558 A5090048 */  sh    $t1, 0x48($t0)
/* 0D408C 7F09F55C 8E4D0000 */  lw    $t5, ($s2)
/* 0D4090 7F09F560 8E190000 */  lw    $t9, ($s0)
/* 0D4094 7F09F564 01B10019 */  multu $t5, $s1
/* 0D4098 7F09F568 00007812 */  mflo  $t7
/* 0D409C 7F09F56C 032F7021 */  addu  $t6, $t9, $t7
/* 0D40A0 7F09F570 0C002914 */  jal   randomGetNext
/* 0D40A4 7F09F574 A5C0004A */   sh    $zero, 0x4a($t6)
/* 0D40A8 7F09F578 C7A00060 */  lwc1  $f0, 0x60($sp)
/* 0D40AC 7F09F57C 44823000 */  mtc1  $v0, $f6
/* 0D40B0 7F09F580 46000007 */  neg.s $f0, $f0
/* 0D40B4 7F09F584 04410005 */  bgez  $v0, .L7F09F59C
/* 0D40B8 7F09F588 468032A0 */   cvt.s.w $f10, $f6
/* 0D40BC 7F09F58C 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0D40C0 7F09F590 44814000 */  mtc1  $at, $f8
/* 0D40C4 7F09F594 00000000 */  nop   
/* 0D40C8 7F09F598 46085280 */  add.s $f10, $f10, $f8
.L7F09F59C:
/* 0D40CC 7F09F59C 46165102 */  mul.s $f4, $f10, $f22
/* 0D40D0 7F09F5A0 8E580000 */  lw    $t8, ($s2)
/* 0D40D4 7F09F5A4 8E0C0000 */  lw    $t4, ($s0)
/* 0D40D8 7F09F5A8 03110019 */  multu $t8, $s1
/* 0D40DC 7F09F5AC 46142482 */  mul.s $f18, $f4, $f20
/* 0D40E0 7F09F5B0 46149180 */  add.s $f6, $f18, $f20
/* 0D40E4 7F09F5B4 00004812 */  mflo  $t1
/* 0D40E8 7F09F5B8 01894021 */  addu  $t0, $t4, $t1
/* 0D40EC 7F09F5BC 46003202 */  mul.s $f8, $f6, $f0
/* 0D40F0 7F09F5C0 4600428D */  trunc.w.s $f10, $f8
/* 0D40F4 7F09F5C4 440B5000 */  mfc1  $t3, $f10
/* 0D40F8 7F09F5C8 00000000 */  nop   
/* 0D40FC 7F09F5CC A50B004C */  sh    $t3, 0x4c($t0)
/* 0D4100 7F09F5D0 0C002914 */  jal   randomGetNext
/* 0D4104 7F09F5D4 E7A00038 */   swc1  $f0, 0x38($sp)
/* 0D4108 7F09F5D8 44822000 */  mtc1  $v0, $f4
/* 0D410C 7F09F5DC 04410005 */  bgez  $v0, .L7F09F5F4
/* 0D4110 7F09F5E0 468024A0 */   cvt.s.w $f18, $f4
/* 0D4114 7F09F5E4 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0D4118 7F09F5E8 44813000 */  mtc1  $at, $f6
/* 0D411C 7F09F5EC 00000000 */  nop   
/* 0D4120 7F09F5F0 46069480 */  add.s $f18, $f18, $f6
.L7F09F5F4:
/* 0D4124 7F09F5F4 46169202 */  mul.s $f8, $f18, $f22
/* 0D4128 7F09F5F8 C7A60038 */  lwc1  $f6, 0x38($sp)
/* 0D412C 7F09F5FC 8E4E0000 */  lw    $t6, ($s2)
/* 0D4130 7F09F600 8E0F0000 */  lw    $t7, ($s0)
/* 0D4134 7F09F604 01D10019 */  multu $t6, $s1
/* 0D4138 7F09F608 46144282 */  mul.s $f10, $f8, $f20
/* 0D413C 7F09F60C 46145100 */  add.s $f4, $f10, $f20
/* 0D4140 7F09F610 00005012 */  mflo  $t2
/* 0D4144 7F09F614 01EAC021 */  addu  $t8, $t7, $t2
/* 0D4148 7F09F618 46062482 */  mul.s $f18, $f4, $f6
/* 0D414C 7F09F61C 4600920D */  trunc.w.s $f8, $f18
/* 0D4150 7F09F620 44194000 */  mfc1  $t9, $f8
/* 0D4154 7F09F624 00000000 */  nop   
/* 0D4158 7F09F628 A7190058 */  sh    $t9, 0x58($t8)
/* 0D415C 7F09F62C 8E490000 */  lw    $t1, ($s2)
/* 0D4160 7F09F630 8E0C0000 */  lw    $t4, ($s0)
/* 0D4164 7F09F634 01310019 */  multu $t1, $s1
/* 0D4168 7F09F638 00005812 */  mflo  $t3
/* 0D416C 7F09F63C 018B4021 */  addu  $t0, $t4, $t3
/* 0D4170 7F09F640 0C002914 */  jal   randomGetNext
/* 0D4174 7F09F644 A500005A */   sh    $zero, 0x5a($t0)
/* 0D4178 7F09F648 44825000 */  mtc1  $v0, $f10
/* 0D417C 7F09F64C 04410005 */  bgez  $v0, .L7F09F664
/* 0D4180 7F09F650 46805120 */   cvt.s.w $f4, $f10
/* 0D4184 7F09F654 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0D4188 7F09F658 44813000 */  mtc1  $at, $f6
/* 0D418C 7F09F65C 00000000 */  nop   
/* 0D4190 7F09F660 46062100 */  add.s $f4, $f4, $f6
.L7F09F664:
/* 0D4194 7F09F664 46162482 */  mul.s $f18, $f4, $f22
/* 0D4198 7F09F668 C7A60038 */  lwc1  $f6, 0x38($sp)
/* 0D419C 7F09F66C 8E4A0000 */  lw    $t2, ($s2)
/* 0D41A0 7F09F670 8E0F0000 */  lw    $t7, ($s0)
/* 0D41A4 7F09F674 01510019 */  multu $t2, $s1
/* 0D41A8 7F09F678 46149202 */  mul.s $f8, $f18, $f20
/* 0D41AC 7F09F67C 46144280 */  add.s $f10, $f8, $f20
/* 0D41B0 7F09F680 0000C812 */  mflo  $t9
/* 0D41B4 7F09F684 01F9C021 */  addu  $t8, $t7, $t9
/* 0D41B8 7F09F688 46065102 */  mul.s $f4, $f10, $f6
/* 0D41BC 7F09F68C 4600248D */  trunc.w.s $f18, $f4
/* 0D41C0 7F09F690 440E9000 */  mfc1  $t6, $f18
/* 0D41C4 7F09F694 0C002914 */  jal   randomGetNext
/* 0D41C8 7F09F698 A70E005C */   sh    $t6, 0x5c($t8)
/* 0D41CC 7F09F69C 44824000 */  mtc1  $v0, $f8
/* 0D41D0 7F09F6A0 04410005 */  bgez  $v0, .L7F09F6B8
/* 0D41D4 7F09F6A4 468042A0 */   cvt.s.w $f10, $f8
/* 0D41D8 7F09F6A8 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0D41DC 7F09F6AC 44813000 */  mtc1  $at, $f6
/* 0D41E0 7F09F6B0 00000000 */  nop   
/* 0D41E4 7F09F6B4 46065280 */  add.s $f10, $f10, $f6
.L7F09F6B8:
/* 0D41E8 7F09F6B8 46165102 */  mul.s $f4, $f10, $f22
/* 0D41EC 7F09F6BC C7A60038 */  lwc1  $f6, 0x38($sp)
/* 0D41F0 7F09F6C0 8E480000 */  lw    $t0, ($s2)
/* 0D41F4 7F09F6C4 8E0B0000 */  lw    $t3, ($s0)
/* 0D41F8 7F09F6C8 01110019 */  multu $t0, $s1
/* 0D41FC 7F09F6CC 46142482 */  mul.s $f18, $f4, $f20
/* 0D4200 7F09F6D0 46149200 */  add.s $f8, $f18, $f20
/* 0D4204 7F09F6D4 00006812 */  mflo  $t5
/* 0D4208 7F09F6D8 016D5021 */  addu  $t2, $t3, $t5
/* 0D420C 7F09F6DC 46064282 */  mul.s $f10, $f8, $f6
/* 0D4210 7F09F6E0 4600510D */  trunc.w.s $f4, $f10
/* 0D4214 7F09F6E4 440C2000 */  mfc1  $t4, $f4
/* 0D4218 7F09F6E8 00000000 */  nop   
/* 0D421C 7F09F6EC A54C0068 */  sh    $t4, 0x68($t2)
/* 0D4220 7F09F6F0 8E590000 */  lw    $t9, ($s2)
/* 0D4224 7F09F6F4 8E0F0000 */  lw    $t7, ($s0)
/* 0D4228 7F09F6F8 03310019 */  multu $t9, $s1
/* 0D422C 7F09F6FC 00007012 */  mflo  $t6
/* 0D4230 7F09F700 01EEC021 */  addu  $t8, $t7, $t6
/* 0D4234 7F09F704 0C002914 */  jal   randomGetNext
/* 0D4238 7F09F708 A700006A */   sh    $zero, 0x6a($t8)
/* 0D423C 7F09F70C 44829000 */  mtc1  $v0, $f18
/* 0D4240 7F09F710 04410005 */  bgez  $v0, .L7F09F728
/* 0D4244 7F09F714 46809220 */   cvt.s.w $f8, $f18
/* 0D4248 7F09F718 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0D424C 7F09F71C 44813000 */  mtc1  $at, $f6
/* 0D4250 7F09F720 00000000 */  nop   
/* 0D4254 7F09F724 46064200 */  add.s $f8, $f8, $f6
.L7F09F728:
/* 0D4258 7F09F728 46164282 */  mul.s $f10, $f8, $f22
/* 0D425C 7F09F72C C7A60060 */  lwc1  $f6, 0x60($sp)
/* 0D4260 7F09F730 8E4D0000 */  lw    $t5, ($s2)
/* 0D4264 7F09F734 8E0B0000 */  lw    $t3, ($s0)
/* 0D4268 7F09F738 01B10019 */  multu $t5, $s1
/* 0D426C 7F09F73C 46145102 */  mul.s $f4, $f10, $f20
/* 0D4270 7F09F740 46142480 */  add.s $f18, $f4, $f20
/* 0D4274 7F09F744 00006012 */  mflo  $t4
/* 0D4278 7F09F748 016C5021 */  addu  $t2, $t3, $t4
/* 0D427C 7F09F74C 46069202 */  mul.s $f8, $f18, $f6
/* 0D4280 7F09F750 4600428D */  trunc.w.s $f10, $f8
/* 0D4284 7F09F754 44085000 */  mfc1  $t0, $f10
/* 0D4288 7F09F758 0C002914 */  jal   randomGetNext
/* 0D428C 7F09F75C A548006C */   sh    $t0, 0x6c($t2)
/* 0D4290 7F09F760 30460003 */  andi  $a2, $v0, 3
/* 0D4294 7F09F764 00067200 */  sll   $t6, $a2, 8
/* 0D4298 7F09F768 0C002914 */  jal   randomGetNext
/* 0D429C 7F09F76C A7AE0042 */   sh    $t6, 0x42($sp)
/* 0D42A0 7F09F770 8E490000 */  lw    $t1, ($s2)
/* 0D42A4 7F09F774 87A60042 */  lh    $a2, 0x42($sp)
/* 0D42A8 7F09F778 8E180000 */  lw    $t8, ($s0)
/* 0D42AC 7F09F77C 01310019 */  multu $t1, $s1
/* 0D42B0 7F09F780 24C400E0 */  addiu $a0, $a2, 0xe0
/* 0D42B4 7F09F784 30430003 */  andi  $v1, $v0, 3
/* 0D42B8 7F09F788 00034200 */  sll   $t0, $v1, 8
/* 0D42BC 7F09F78C 250500E0 */  addiu $a1, $t0, 0xe0
/* 0D42C0 7F09F790 01001825 */  move  $v1, $t0
/* 0D42C4 7F09F794 00006812 */  mflo  $t5
/* 0D42C8 7F09F798 030D5821 */  addu  $t3, $t8, $t5
/* 0D42CC 7F09F79C A5640040 */  sh    $a0, 0x40($t3)
/* 0D42D0 7F09F7A0 8E590000 */  lw    $t9, ($s2)
/* 0D42D4 7F09F7A4 8E0A0000 */  lw    $t2, ($s0)
/* 0D42D8 7F09F7A8 03310019 */  multu $t9, $s1
/* 0D42DC 7F09F7AC 00007812 */  mflo  $t7
/* 0D42E0 7F09F7B0 014F7021 */  addu  $t6, $t2, $t7
/* 0D42E4 7F09F7B4 A5C50042 */  sh    $a1, 0x42($t6)
/* 0D42E8 7F09F7B8 8E580000 */  lw    $t8, ($s2)
/* 0D42EC 7F09F7BC 8E090000 */  lw    $t1, ($s0)
/* 0D42F0 7F09F7C0 03110019 */  multu $t8, $s1
/* 0D42F4 7F09F7C4 00006812 */  mflo  $t5
/* 0D42F8 7F09F7C8 012D5821 */  addu  $t3, $t1, $t5
/* 0D42FC 7F09F7CC A5640050 */  sh    $a0, 0x50($t3)
/* 0D4300 7F09F7D0 8E480000 */  lw    $t0, ($s2)
/* 0D4304 7F09F7D4 8E0C0000 */  lw    $t4, ($s0)
/* 0D4308 7F09F7D8 01110019 */  multu $t0, $s1
/* 0D430C 7F09F7DC 0000C812 */  mflo  $t9
/* 0D4310 7F09F7E0 01995021 */  addu  $t2, $t4, $t9
/* 0D4314 7F09F7E4 A5430052 */  sh    $v1, 0x52($t2)
/* 0D4318 7F09F7E8 8E4E0000 */  lw    $t6, ($s2)
/* 0D431C 7F09F7EC 8E0F0000 */  lw    $t7, ($s0)
/* 0D4320 7F09F7F0 01D10019 */  multu $t6, $s1
/* 0D4324 7F09F7F4 0000C012 */  mflo  $t8
/* 0D4328 7F09F7F8 01F84821 */  addu  $t1, $t7, $t8
/* 0D432C 7F09F7FC A5260060 */  sh    $a2, 0x60($t1)
/* 0D4330 7F09F800 8E4B0000 */  lw    $t3, ($s2)
/* 0D4334 7F09F804 8E0D0000 */  lw    $t5, ($s0)
/* 0D4338 7F09F808 01710019 */  multu $t3, $s1
/* 0D433C 7F09F80C 00004012 */  mflo  $t0
/* 0D4340 7F09F810 01A86021 */  addu  $t4, $t5, $t0
/* 0D4344 7F09F814 A5830062 */  sh    $v1, 0x62($t4)
/* 0D4348 7F09F818 8E4A0000 */  lw    $t2, ($s2)
/* 0D434C 7F09F81C 8E190000 */  lw    $t9, ($s0)
/* 0D4350 7F09F820 01510019 */  multu $t2, $s1
/* 0D4354 7F09F824 00007012 */  mflo  $t6
/* 0D4358 7F09F828 032E7821 */  addu  $t7, $t9, $t6
/* 0D435C 7F09F82C A5E60070 */  sh    $a2, 0x70($t7)
/* 0D4360 7F09F830 8E490000 */  lw    $t1, ($s2)
/* 0D4364 7F09F834 8E180000 */  lw    $t8, ($s0)
/* 0D4368 7F09F838 01310019 */  multu $t1, $s1
/* 0D436C 7F09F83C 00005812 */  mflo  $t3
/* 0D4370 7F09F840 030B6821 */  addu  $t5, $t8, $t3
/* 0D4374 7F09F844 0C002914 */  jal   randomGetNext
/* 0D4378 7F09F848 A5A50072 */   sh    $a1, 0x72($t5)
/* 0D437C 7F09F84C 30480001 */  andi  $t0, $v0, 1
/* 0D4380 7F09F850 1100005B */  beqz  $t0, .L7F09F9C0
/* 0D4384 7F09F854 00000000 */   nop   
/* 0D4388 7F09F858 0C002914 */  jal   randomGetNext
/* 0D438C 7F09F85C 00000000 */   nop   
/* 0D4390 7F09F860 8E4E0000 */  lw    $t6, ($s2)
/* 0D4394 7F09F864 8E190000 */  lw    $t9, ($s0)
/* 0D4398 7F09F868 304C003F */  andi  $t4, $v0, 0x3f
/* 0D439C 7F09F86C 01D10019 */  multu $t6, $s1
/* 0D43A0 7F09F870 240A00FF */  li    $t2, 255
/* 0D43A4 7F09F874 014C1823 */  subu  $v1, $t2, $t4
/* 0D43A8 7F09F878 00007812 */  mflo  $t7
/* 0D43AC 7F09F87C 032F4821 */  addu  $t1, $t9, $t7
/* 0D43B0 7F09F880 A1230046 */  sb    $v1, 0x46($t1)
/* 0D43B4 7F09F884 8E4B0000 */  lw    $t3, ($s2)
/* 0D43B8 7F09F888 8E180000 */  lw    $t8, ($s0)
/* 0D43BC 7F09F88C 01710019 */  multu $t3, $s1
/* 0D43C0 7F09F890 00006812 */  mflo  $t5
/* 0D43C4 7F09F894 030D4021 */  addu  $t0, $t8, $t5
/* 0D43C8 7F09F898 A1030045 */  sb    $v1, 0x45($t0)
/* 0D43CC 7F09F89C 8E4C0000 */  lw    $t4, ($s2)
/* 0D43D0 7F09F8A0 8E0A0000 */  lw    $t2, ($s0)
/* 0D43D4 7F09F8A4 01910019 */  multu $t4, $s1
/* 0D43D8 7F09F8A8 00007012 */  mflo  $t6
/* 0D43DC 7F09F8AC 014EC821 */  addu  $t9, $t2, $t6
/* 0D43E0 7F09F8B0 0C002914 */  jal   randomGetNext
/* 0D43E4 7F09F8B4 A3230044 */   sb    $v1, 0x44($t9)
/* 0D43E8 7F09F8B8 8E580000 */  lw    $t8, ($s2)
/* 0D43EC 7F09F8BC 8E0B0000 */  lw    $t3, ($s0)
/* 0D43F0 7F09F8C0 304F003F */  andi  $t7, $v0, 0x3f
/* 0D43F4 7F09F8C4 03110019 */  multu $t8, $s1
/* 0D43F8 7F09F8C8 240900FF */  li    $t1, 255
/* 0D43FC 7F09F8CC 012F1823 */  subu  $v1, $t1, $t7
/* 0D4400 7F09F8D0 00006812 */  mflo  $t5
/* 0D4404 7F09F8D4 016D4021 */  addu  $t0, $t3, $t5
/* 0D4408 7F09F8D8 A1030056 */  sb    $v1, 0x56($t0)
/* 0D440C 7F09F8DC 8E4A0000 */  lw    $t2, ($s2)
/* 0D4410 7F09F8E0 8E0C0000 */  lw    $t4, ($s0)
/* 0D4414 7F09F8E4 01510019 */  multu $t2, $s1
/* 0D4418 7F09F8E8 00007012 */  mflo  $t6
/* 0D441C 7F09F8EC 018EC821 */  addu  $t9, $t4, $t6
/* 0D4420 7F09F8F0 A3230055 */  sb    $v1, 0x55($t9)
/* 0D4424 7F09F8F4 8E4F0000 */  lw    $t7, ($s2)
/* 0D4428 7F09F8F8 8E090000 */  lw    $t1, ($s0)
/* 0D442C 7F09F8FC 01F10019 */  multu $t7, $s1
/* 0D4430 7F09F900 0000C012 */  mflo  $t8
/* 0D4434 7F09F904 01385821 */  addu  $t3, $t1, $t8
/* 0D4438 7F09F908 0C002914 */  jal   randomGetNext
/* 0D443C 7F09F90C A1630054 */   sb    $v1, 0x54($t3)
/* 0D4440 7F09F910 8E4C0000 */  lw    $t4, ($s2)
/* 0D4444 7F09F914 8E0A0000 */  lw    $t2, ($s0)
/* 0D4448 7F09F918 304D003F */  andi  $t5, $v0, 0x3f
/* 0D444C 7F09F91C 01910019 */  multu $t4, $s1
/* 0D4450 7F09F920 240800FF */  li    $t0, 255
/* 0D4454 7F09F924 010D1823 */  subu  $v1, $t0, $t5
/* 0D4458 7F09F928 00007012 */  mflo  $t6
/* 0D445C 7F09F92C 014EC821 */  addu  $t9, $t2, $t6
/* 0D4460 7F09F930 A3230066 */  sb    $v1, 0x66($t9)
/* 0D4464 7F09F934 8E490000 */  lw    $t1, ($s2)
/* 0D4468 7F09F938 8E0F0000 */  lw    $t7, ($s0)
/* 0D446C 7F09F93C 01310019 */  multu $t1, $s1
/* 0D4470 7F09F940 0000C012 */  mflo  $t8
/* 0D4474 7F09F944 01F85821 */  addu  $t3, $t7, $t8
/* 0D4478 7F09F948 A1630065 */  sb    $v1, 0x65($t3)
/* 0D447C 7F09F94C 8E4D0000 */  lw    $t5, ($s2)
/* 0D4480 7F09F950 8E080000 */  lw    $t0, ($s0)
/* 0D4484 7F09F954 01B10019 */  multu $t5, $s1
/* 0D4488 7F09F958 00006012 */  mflo  $t4
/* 0D448C 7F09F95C 010C5021 */  addu  $t2, $t0, $t4
/* 0D4490 7F09F960 0C002914 */  jal   randomGetNext
/* 0D4494 7F09F964 A1430064 */   sb    $v1, 0x64($t2)
/* 0D4498 7F09F968 8E4F0000 */  lw    $t7, ($s2)
/* 0D449C 7F09F96C 8E090000 */  lw    $t1, ($s0)
/* 0D44A0 7F09F970 304E003F */  andi  $t6, $v0, 0x3f
/* 0D44A4 7F09F974 01F10019 */  multu $t7, $s1
/* 0D44A8 7F09F978 241900FF */  li    $t9, 255
/* 0D44AC 7F09F97C 032E1823 */  subu  $v1, $t9, $t6
/* 0D44B0 7F09F980 0000C012 */  mflo  $t8
/* 0D44B4 7F09F984 01385821 */  addu  $t3, $t1, $t8
/* 0D44B8 7F09F988 A1630076 */  sb    $v1, 0x76($t3)
/* 0D44BC 7F09F98C 8E480000 */  lw    $t0, ($s2)
/* 0D44C0 7F09F990 8E0D0000 */  lw    $t5, ($s0)
/* 0D44C4 7F09F994 01110019 */  multu $t0, $s1
/* 0D44C8 7F09F998 00006012 */  mflo  $t4
/* 0D44CC 7F09F99C 01AC5021 */  addu  $t2, $t5, $t4
/* 0D44D0 7F09F9A0 A1430075 */  sb    $v1, 0x75($t2)
/* 0D44D4 7F09F9A4 8E4E0000 */  lw    $t6, ($s2)
/* 0D44D8 7F09F9A8 8E190000 */  lw    $t9, ($s0)
/* 0D44DC 7F09F9AC 01D10019 */  multu $t6, $s1
/* 0D44E0 7F09F9B0 00007812 */  mflo  $t7
/* 0D44E4 7F09F9B4 032F4821 */  addu  $t1, $t9, $t7
/* 0D44E8 7F09F9B8 10000052 */  b     .L7F09FB04
/* 0D44EC 7F09F9BC A1230074 */   sb    $v1, 0x74($t1)
.L7F09F9C0:
/* 0D44F0 7F09F9C0 0C002914 */  jal   randomGetNext
/* 0D44F4 7F09F9C4 00000000 */   nop   
/* 0D44F8 7F09F9C8 8E4B0000 */  lw    $t3, ($s2)
/* 0D44FC 7F09F9CC 8E180000 */  lw    $t8, ($s0)
/* 0D4500 7F09F9D0 3043003F */  andi  $v1, $v0, 0x3f
/* 0D4504 7F09F9D4 01710019 */  multu $t3, $s1
/* 0D4508 7F09F9D8 00004012 */  mflo  $t0
/* 0D450C 7F09F9DC 03086821 */  addu  $t5, $t8, $t0
/* 0D4510 7F09F9E0 A1A30046 */  sb    $v1, 0x46($t5)
/* 0D4514 7F09F9E4 8E4A0000 */  lw    $t2, ($s2)
/* 0D4518 7F09F9E8 8E0C0000 */  lw    $t4, ($s0)
/* 0D451C 7F09F9EC 01510019 */  multu $t2, $s1
/* 0D4520 7F09F9F0 00007012 */  mflo  $t6
/* 0D4524 7F09F9F4 018EC821 */  addu  $t9, $t4, $t6
/* 0D4528 7F09F9F8 A3230045 */  sb    $v1, 0x45($t9)
/* 0D452C 7F09F9FC 8E490000 */  lw    $t1, ($s2)
/* 0D4530 7F09FA00 8E0F0000 */  lw    $t7, ($s0)
/* 0D4534 7F09FA04 01310019 */  multu $t1, $s1
/* 0D4538 7F09FA08 00005812 */  mflo  $t3
/* 0D453C 7F09FA0C 01EBC021 */  addu  $t8, $t7, $t3
/* 0D4540 7F09FA10 0C002914 */  jal   randomGetNext
/* 0D4544 7F09FA14 A3030044 */   sb    $v1, 0x44($t8)
/* 0D4548 7F09FA18 8E4D0000 */  lw    $t5, ($s2)
/* 0D454C 7F09FA1C 8E080000 */  lw    $t0, ($s0)
/* 0D4550 7F09FA20 3043003F */  andi  $v1, $v0, 0x3f
/* 0D4554 7F09FA24 01B10019 */  multu $t5, $s1
/* 0D4558 7F09FA28 00005012 */  mflo  $t2
/* 0D455C 7F09FA2C 010A6021 */  addu  $t4, $t0, $t2
/* 0D4560 7F09FA30 A1830056 */  sb    $v1, 0x56($t4)
/* 0D4564 7F09FA34 8E590000 */  lw    $t9, ($s2)
/* 0D4568 7F09FA38 8E0E0000 */  lw    $t6, ($s0)
/* 0D456C 7F09FA3C 03310019 */  multu $t9, $s1
/* 0D4570 7F09FA40 00004812 */  mflo  $t1
/* 0D4574 7F09FA44 01C97821 */  addu  $t7, $t6, $t1
/* 0D4578 7F09FA48 A1E30055 */  sb    $v1, 0x55($t7)
/* 0D457C 7F09FA4C 8E580000 */  lw    $t8, ($s2)
/* 0D4580 7F09FA50 8E0B0000 */  lw    $t3, ($s0)
/* 0D4584 7F09FA54 03110019 */  multu $t8, $s1
/* 0D4588 7F09FA58 00006812 */  mflo  $t5
/* 0D458C 7F09FA5C 016D4021 */  addu  $t0, $t3, $t5
/* 0D4590 7F09FA60 0C002914 */  jal   randomGetNext
/* 0D4594 7F09FA64 A1030054 */   sb    $v1, 0x54($t0)
/* 0D4598 7F09FA68 8E4C0000 */  lw    $t4, ($s2)
/* 0D459C 7F09FA6C 8E0A0000 */  lw    $t2, ($s0)
/* 0D45A0 7F09FA70 3043003F */  andi  $v1, $v0, 0x3f
/* 0D45A4 7F09FA74 01910019 */  multu $t4, $s1
/* 0D45A8 7F09FA78 0000C812 */  mflo  $t9
/* 0D45AC 7F09FA7C 01597021 */  addu  $t6, $t2, $t9
/* 0D45B0 7F09FA80 A1C30066 */  sb    $v1, 0x66($t6)
/* 0D45B4 7F09FA84 8E4F0000 */  lw    $t7, ($s2)
/* 0D45B8 7F09FA88 8E090000 */  lw    $t1, ($s0)
/* 0D45BC 7F09FA8C 01F10019 */  multu $t7, $s1
/* 0D45C0 7F09FA90 0000C012 */  mflo  $t8
/* 0D45C4 7F09FA94 01385821 */  addu  $t3, $t1, $t8
/* 0D45C8 7F09FA98 A1630065 */  sb    $v1, 0x65($t3)
/* 0D45CC 7F09FA9C 8E480000 */  lw    $t0, ($s2)
/* 0D45D0 7F09FAA0 8E0D0000 */  lw    $t5, ($s0)
/* 0D45D4 7F09FAA4 01110019 */  multu $t0, $s1
/* 0D45D8 7F09FAA8 00006012 */  mflo  $t4
/* 0D45DC 7F09FAAC 01AC5021 */  addu  $t2, $t5, $t4
/* 0D45E0 7F09FAB0 0C002914 */  jal   randomGetNext
/* 0D45E4 7F09FAB4 A1430064 */   sb    $v1, 0x64($t2)
/* 0D45E8 7F09FAB8 8E4E0000 */  lw    $t6, ($s2)
/* 0D45EC 7F09FABC 8E190000 */  lw    $t9, ($s0)
/* 0D45F0 7F09FAC0 3043003F */  andi  $v1, $v0, 0x3f
/* 0D45F4 7F09FAC4 01D10019 */  multu $t6, $s1
/* 0D45F8 7F09FAC8 00007812 */  mflo  $t7
/* 0D45FC 7F09FACC 032F4821 */  addu  $t1, $t9, $t7
/* 0D4600 7F09FAD0 A1230076 */  sb    $v1, 0x76($t1)
/* 0D4604 7F09FAD4 8E4B0000 */  lw    $t3, ($s2)
/* 0D4608 7F09FAD8 8E180000 */  lw    $t8, ($s0)
/* 0D460C 7F09FADC 01710019 */  multu $t3, $s1
/* 0D4610 7F09FAE0 00004012 */  mflo  $t0
/* 0D4614 7F09FAE4 03086821 */  addu  $t5, $t8, $t0
/* 0D4618 7F09FAE8 A1A30075 */  sb    $v1, 0x75($t5)
/* 0D461C 7F09FAEC 8E4A0000 */  lw    $t2, ($s2)
/* 0D4620 7F09FAF0 8E0C0000 */  lw    $t4, ($s0)
/* 0D4624 7F09FAF4 01510019 */  multu $t2, $s1
/* 0D4628 7F09FAF8 00007012 */  mflo  $t6
/* 0D462C 7F09FAFC 018EC821 */  addu  $t9, $t4, $t6
/* 0D4630 7F09FB00 A3230074 */  sb    $v1, 0x74($t9)
.L7F09FB04:
/* 0D4634 7F09FB04 8E490000 */  lw    $t1, ($s2)
/* 0D4638 7F09FB08 8E0F0000 */  lw    $t7, ($s0)
/* 0D463C 7F09FB0C 240200DC */  li    $v0, 220
/* 0D4640 7F09FB10 01310019 */  multu $t1, $s1
/* 0D4644 7F09FB14 00005812 */  mflo  $t3
/* 0D4648 7F09FB18 01EBC021 */  addu  $t8, $t7, $t3
/* 0D464C 7F09FB1C A3020047 */  sb    $v0, 0x47($t8)
/* 0D4650 7F09FB20 8E4D0000 */  lw    $t5, ($s2)
/* 0D4654 7F09FB24 8E080000 */  lw    $t0, ($s0)
/* 0D4658 7F09FB28 01B10019 */  multu $t5, $s1
/* 0D465C 7F09FB2C 00005012 */  mflo  $t2
/* 0D4660 7F09FB30 010A6021 */  addu  $t4, $t0, $t2
/* 0D4664 7F09FB34 A1820057 */  sb    $v0, 0x57($t4)
/* 0D4668 7F09FB38 8E590000 */  lw    $t9, ($s2)
/* 0D466C 7F09FB3C 8E0E0000 */  lw    $t6, ($s0)
/* 0D4670 7F09FB40 03310019 */  multu $t9, $s1
/* 0D4674 7F09FB44 00004812 */  mflo  $t1
/* 0D4678 7F09FB48 01C97821 */  addu  $t7, $t6, $t1
/* 0D467C 7F09FB4C A1E20067 */  sb    $v0, 0x67($t7)
/* 0D4680 7F09FB50 8E580000 */  lw    $t8, ($s2)
/* 0D4684 7F09FB54 8E0B0000 */  lw    $t3, ($s0)
/* 0D4688 7F09FB58 03110019 */  multu $t8, $s1
/* 0D468C 7F09FB5C 00006812 */  mflo  $t5
/* 0D4690 7F09FB60 016D4021 */  addu  $t0, $t3, $t5
/* 0D4694 7F09FB64 0C002914 */  jal   randomGetNext
/* 0D4698 7F09FB68 A1020077 */   sb    $v0, 0x77($t0)
/* 0D469C 7F09FB6C 44822000 */  mtc1  $v0, $f4
/* 0D46A0 7F09FB70 3C018005 */  lui   $at, %hi(D_800576E8)
/* 0D46A4 7F09FB74 C43476E8 */  lwc1  $f20, %lo(D_800576E8)($at)
/* 0D46A8 7F09FB78 04410005 */  bgez  $v0, .L7F09FB90
/* 0D46AC 7F09FB7C 468024A0 */   cvt.s.w $f18, $f4
/* 0D46B0 7F09FB80 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0D46B4 7F09FB84 44813000 */  mtc1  $at, $f6
/* 0D46B8 7F09FB88 00000000 */  nop   
/* 0D46BC 7F09FB8C 46069480 */  add.s $f18, $f18, $f6
.L7F09FB90:
/* 0D46C0 7F09FB90 8E4C0000 */  lw    $t4, ($s2)
/* 0D46C4 7F09FB94 46169202 */  mul.s $f8, $f18, $f22
/* 0D46C8 7F09FB98 8E0A0000 */  lw    $t2, ($s0)
/* 0D46CC 7F09FB9C 01910019 */  multu $t4, $s1
/* 0D46D0 7F09FBA0 46144282 */  mul.s $f10, $f8, $f20
/* 0D46D4 7F09FBA4 0000C812 */  mflo  $t9
/* 0D46D8 7F09FBA8 01597021 */  addu  $t6, $t2, $t9
/* 0D46DC 7F09FBAC 0C002914 */  jal   randomGetNext
/* 0D46E0 7F09FBB0 E5CA0010 */   swc1  $f10, 0x10($t6)
/* 0D46E4 7F09FBB4 44822000 */  mtc1  $v0, $f4
/* 0D46E8 7F09FBB8 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0D46EC 7F09FBBC 04410004 */  bgez  $v0, .L7F09FBD0
/* 0D46F0 7F09FBC0 468021A0 */   cvt.s.w $f6, $f4
/* 0D46F4 7F09FBC4 44819000 */  mtc1  $at, $f18
/* 0D46F8 7F09FBC8 00000000 */  nop   
/* 0D46FC 7F09FBCC 46123180 */  add.s $f6, $f6, $f18
.L7F09FBD0:
/* 0D4700 7F09FBD0 8E4F0000 */  lw    $t7, ($s2)
/* 0D4704 7F09FBD4 46163202 */  mul.s $f8, $f6, $f22
/* 0D4708 7F09FBD8 8E090000 */  lw    $t1, ($s0)
/* 0D470C 7F09FBDC 01F10019 */  multu $t7, $s1
/* 0D4710 7F09FBE0 46144282 */  mul.s $f10, $f8, $f20
/* 0D4714 7F09FBE4 0000C012 */  mflo  $t8
/* 0D4718 7F09FBE8 01385821 */  addu  $t3, $t1, $t8
/* 0D471C 7F09FBEC 0C002914 */  jal   randomGetNext
/* 0D4720 7F09FBF0 E56A0014 */   swc1  $f10, 0x14($t3)
/* 0D4724 7F09FBF4 44822000 */  mtc1  $v0, $f4
/* 0D4728 7F09FBF8 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0D472C 7F09FBFC 04410004 */  bgez  $v0, .L7F09FC10
/* 0D4730 7F09FC00 468024A0 */   cvt.s.w $f18, $f4
/* 0D4734 7F09FC04 44813000 */  mtc1  $at, $f6
/* 0D4738 7F09FC08 00000000 */  nop   
/* 0D473C 7F09FC0C 46069480 */  add.s $f18, $f18, $f6
.L7F09FC10:
/* 0D4740 7F09FC10 8E480000 */  lw    $t0, ($s2)
/* 0D4744 7F09FC14 46169202 */  mul.s $f8, $f18, $f22
/* 0D4748 7F09FC18 8E0D0000 */  lw    $t5, ($s0)
/* 0D474C 7F09FC1C 01110019 */  multu $t0, $s1
/* 0D4750 7F09FC20 46144282 */  mul.s $f10, $f8, $f20
/* 0D4754 7F09FC24 00006012 */  mflo  $t4
/* 0D4758 7F09FC28 01AC5021 */  addu  $t2, $t5, $t4
/* 0D475C 7F09FC2C 0C002914 */  jal   randomGetNext
/* 0D4760 7F09FC30 E54A0018 */   swc1  $f10, 0x18($t2)
/* 0D4764 7F09FC34 44822000 */  mtc1  $v0, $f4
/* 0D4768 7F09FC38 3C018005 */  lui   $at, %hi(D_800576EC)
/* 0D476C 7F09FC3C C43476EC */  lwc1  $f20, %lo(D_800576EC)($at)
/* 0D4770 7F09FC40 04410005 */  bgez  $v0, .L7F09FC58
/* 0D4774 7F09FC44 468021A0 */   cvt.s.w $f6, $f4
/* 0D4778 7F09FC48 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0D477C 7F09FC4C 44819000 */  mtc1  $at, $f18
/* 0D4780 7F09FC50 00000000 */  nop   
/* 0D4784 7F09FC54 46123180 */  add.s $f6, $f6, $f18
.L7F09FC58:
/* 0D4788 7F09FC58 8E4E0000 */  lw    $t6, ($s2)
/* 0D478C 7F09FC5C 46163202 */  mul.s $f8, $f6, $f22
/* 0D4790 7F09FC60 8E190000 */  lw    $t9, ($s0)
/* 0D4794 7F09FC64 01D10019 */  multu $t6, $s1
/* 0D4798 7F09FC68 46144282 */  mul.s $f10, $f8, $f20
/* 0D479C 7F09FC6C 00007812 */  mflo  $t7
/* 0D47A0 7F09FC70 032F4821 */  addu  $t1, $t9, $t7
/* 0D47A4 7F09FC74 0C002914 */  jal   randomGetNext
/* 0D47A8 7F09FC78 E52A0028 */   swc1  $f10, 0x28($t1)
/* 0D47AC 7F09FC7C 44822000 */  mtc1  $v0, $f4
/* 0D47B0 7F09FC80 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0D47B4 7F09FC84 04410004 */  bgez  $v0, .L7F09FC98
/* 0D47B8 7F09FC88 468024A0 */   cvt.s.w $f18, $f4
/* 0D47BC 7F09FC8C 44813000 */  mtc1  $at, $f6
/* 0D47C0 7F09FC90 00000000 */  nop   
/* 0D47C4 7F09FC94 46069480 */  add.s $f18, $f18, $f6
.L7F09FC98:
/* 0D47C8 7F09FC98 8E4B0000 */  lw    $t3, ($s2)
/* 0D47CC 7F09FC9C 46169202 */  mul.s $f8, $f18, $f22
/* 0D47D0 7F09FCA0 8E180000 */  lw    $t8, ($s0)
/* 0D47D4 7F09FCA4 01710019 */  multu $t3, $s1
/* 0D47D8 7F09FCA8 46144282 */  mul.s $f10, $f8, $f20
/* 0D47DC 7F09FCAC 00004012 */  mflo  $t0
/* 0D47E0 7F09FCB0 03086821 */  addu  $t5, $t8, $t0
/* 0D47E4 7F09FCB4 0C002914 */  jal   randomGetNext
/* 0D47E8 7F09FCB8 E5AA002C */   swc1  $f10, 0x2c($t5)
/* 0D47EC 7F09FCBC 44822000 */  mtc1  $v0, $f4
/* 0D47F0 7F09FCC0 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0D47F4 7F09FCC4 04410004 */  bgez  $v0, .L7F09FCD8
/* 0D47F8 7F09FCC8 468021A0 */   cvt.s.w $f6, $f4
/* 0D47FC 7F09FCCC 44819000 */  mtc1  $at, $f18
/* 0D4800 7F09FCD0 00000000 */  nop   
/* 0D4804 7F09FCD4 46123180 */  add.s $f6, $f6, $f18
.L7F09FCD8:
/* 0D4808 7F09FCD8 8E4A0000 */  lw    $t2, ($s2)
/* 0D480C 7F09FCDC 46163202 */  mul.s $f8, $f6, $f22
/* 0D4810 7F09FCE0 8E0C0000 */  lw    $t4, ($s0)
/* 0D4814 7F09FCE4 01510019 */  multu $t2, $s1
/* 0D4818 7F09FCE8 3C188008 */  lui   $t8, %hi(max_casings) 
/* 0D481C 7F09FCEC 46144282 */  mul.s $f10, $f8, $f20
/* 0D4820 7F09FCF0 00007012 */  mflo  $t6
/* 0D4824 7F09FCF4 018EC821 */  addu  $t9, $t4, $t6
/* 0D4828 7F09FCF8 E72A0030 */  swc1  $f10, 0x30($t9)
/* 0D482C 7F09FCFC 8E4F0000 */  lw    $t7, ($s2)
/* 0D4830 7F09FD00 25E90001 */  addiu $t1, $t7, 1
/* 0D4834 7F09FD04 AE490000 */  sw    $t1, ($s2)
/* 0D4838 7F09FD08 8F18A148 */  lw    $t8, %lo(max_casings)($t8)
/* 0D483C 7F09FD0C 0138082A */  slt   $at, $t1, $t8
/* 0D4840 7F09FD10 54200003 */  bnezl $at, .L7F09FD20
/* 0D4844 7F09FD14 8FBF0034 */   lw    $ra, 0x34($sp)
/* 0D4848 7F09FD18 AE400000 */  sw    $zero, ($s2)
/* 0D484C 7F09FD1C 8FBF0034 */  lw    $ra, 0x34($sp)
.L7F09FD20:
/* 0D4850 7F09FD20 D7B40018 */  ldc1  $f20, 0x18($sp)
/* 0D4854 7F09FD24 D7B60020 */  ldc1  $f22, 0x20($sp)
/* 0D4858 7F09FD28 8FB00028 */  lw    $s0, 0x28($sp)
/* 0D485C 7F09FD2C 8FB1002C */  lw    $s1, 0x2c($sp)
/* 0D4860 7F09FD30 8FB20030 */  lw    $s2, 0x30($sp)
/* 0D4864 7F09FD34 03E00008 */  jr    $ra
/* 0D4868 7F09FD38 27BD0050 */   addiu $sp, $sp, 0x50
)
#endif





#ifdef NONMATCHING
void update_gray_flying_particles(void) {
    // these are created from shooting walls with guns
    // these are limited to 5 at a time
    // spawning more will delete the oldest one to spawn a new one
}
#else
GLOBAL_ASM(
.late_rodata
glabel D_800576F0
.word 0x46ea6000 /*30000.0*/
glabel D_800576F4
.word 0xc6ea6000 /*-30000.0*/
glabel D_800576F8
.word 0x3e4ccccd /*0.2*/
.text
glabel update_gray_flying_particles
/* 0D486C 7F09FD3C 27BDFFA8 */  addiu $sp, $sp, -0x58
/* 0D4870 7F09FD40 3C028005 */  lui   $v0, %hi(g_ClockTimer)
/* 0D4874 7F09FD44 8C428374 */  lw    $v0, %lo(g_ClockTimer)($v0)
/* 0D4878 7F09FD48 AFBF0054 */  sw    $ra, 0x54($sp)
/* 0D487C 7F09FD4C AFB40050 */  sw    $s4, 0x50($sp)
/* 0D4880 7F09FD50 2841000F */  slti  $at, $v0, 0xf
/* 0D4884 7F09FD54 AFB3004C */  sw    $s3, 0x4c($sp)
/* 0D4888 7F09FD58 AFB20048 */  sw    $s2, 0x48($sp)
/* 0D488C 7F09FD5C AFB10044 */  sw    $s1, 0x44($sp)
/* 0D4890 7F09FD60 AFB00040 */  sw    $s0, 0x40($sp)
/* 0D4894 7F09FD64 F7BC0038 */  sdc1  $f28, 0x38($sp)
/* 0D4898 7F09FD68 F7BA0030 */  sdc1  $f26, 0x30($sp)
/* 0D489C 7F09FD6C F7B80028 */  sdc1  $f24, 0x28($sp)
/* 0D48A0 7F09FD70 F7B60020 */  sdc1  $f22, 0x20($sp)
/* 0D48A4 7F09FD74 10200004 */  beqz  $at, .L7F09FD88
/* 0D48A8 7F09FD78 F7B40018 */   sdc1  $f20, 0x18($sp)
/* 0D48AC 7F09FD7C 44822000 */  mtc1  $v0, $f4
/* 0D48B0 7F09FD80 10000004 */  b     .L7F09FD94
/* 0D48B4 7F09FD84 46802620 */   cvt.s.w $f24, $f4
.L7F09FD88:
/* 0D48B8 7F09FD88 3C014170 */  li    $at, 0x41700000 # 15.000000
/* 0D48BC 7F09FD8C 4481C000 */  mtc1  $at, $f24
/* 0D48C0 7F09FD90 00000000 */  nop   
.L7F09FD94:
/* 0D48C4 7F09FD94 3C148008 */  lui   $s4, %hi(max_casings)
/* 0D48C8 7F09FD98 2694A148 */  addiu $s4, %lo(max_casings) # addiu $s4, $s4, -0x5eb8
/* 0D48CC 7F09FD9C 8E8E0000 */  lw    $t6, ($s4)
/* 0D48D0 7F09FDA0 00009025 */  move  $s2, $zero
/* 0D48D4 7F09FDA4 00008025 */  move  $s0, $zero
/* 0D48D8 7F09FDA8 19C00095 */  blez  $t6, .L7F0A0000
/* 0D48DC 7F09FDAC 3C018005 */   lui   $at, %hi(D_800576F0)
/* 0D48E0 7F09FDB0 C43C76F0 */  lwc1  $f28, %lo(D_800576F0)($at)
/* 0D48E4 7F09FDB4 3C018005 */  lui   $at, %hi(D_800576F4)
/* 0D48E8 7F09FDB8 C43A76F4 */  lwc1  $f26, %lo(D_800576F4)($at)
/* 0D48EC 7F09FDBC 3C018005 */  lui   $at, %hi(D_800576F8)
/* 0D48F0 7F09FDC0 C43676F8 */  lwc1  $f22, %lo(D_800576F8)($at)
/* 0D48F4 7F09FDC4 3C01C070 */  li    $at, 0xC0700000 # -3.750000
/* 0D48F8 7F09FDC8 3C118008 */  lui   $s1, %hi(ptr_ejected_casing_buf)
/* 0D48FC 7F09FDCC 4481A000 */  mtc1  $at, $f20
/* 0D4900 7F09FDD0 2631A14C */  addiu $s1, %lo(ptr_ejected_casing_buf) # addiu $s1, $s1, -0x5eb4
/* 0D4904 7F09FDD4 2413012C */  li    $s3, 300
/* 0D4908 7F09FDD8 8E2F0000 */  lw    $t7, ($s1)
.L7F09FDDC:
/* 0D490C 7F09FDDC 01F01021 */  addu  $v0, $t7, $s0
/* 0D4910 7F09FDE0 8C450000 */  lw    $a1, ($v0)
/* 0D4914 7F09FDE4 58A00081 */  blezl $a1, .L7F09FFEC
/* 0D4918 7F09FDE8 8E990000 */   lw    $t9, ($s4)
/* 0D491C 7F09FDEC 4600C18D */  trunc.w.s $f6, $f24
/* 0D4920 7F09FDF0 00001825 */  move  $v1, $zero
/* 0D4924 7F09FDF4 44043000 */  mfc1  $a0, $f6
/* 0D4928 7F09FDF8 00000000 */  nop   
/* 0D492C 7F09FDFC 00A4C821 */  addu  $t9, $a1, $a0
/* 0D4930 7F09FE00 AC590000 */  sw    $t9, ($v0)
/* 0D4934 7F09FE04 8E280000 */  lw    $t0, ($s1)
/* 0D4938 7F09FE08 01101021 */  addu  $v0, $t0, $s0
/* 0D493C 7F09FE0C C44A0028 */  lwc1  $f10, 0x28($v0)
/* 0D4940 7F09FE10 C4480010 */  lwc1  $f8, 0x10($v0)
/* 0D4944 7F09FE14 46185402 */  mul.s $f16, $f10, $f24
/* 0D4948 7F09FE18 46104480 */  add.s $f18, $f8, $f16
/* 0D494C 7F09FE1C E4520010 */  swc1  $f18, 0x10($v0)
/* 0D4950 7F09FE20 8E290000 */  lw    $t1, ($s1)
/* 0D4954 7F09FE24 01301021 */  addu  $v0, $t1, $s0
/* 0D4958 7F09FE28 C446002C */  lwc1  $f6, 0x2c($v0)
/* 0D495C 7F09FE2C C4440014 */  lwc1  $f4, 0x14($v0)
/* 0D4960 7F09FE30 46183282 */  mul.s $f10, $f6, $f24
/* 0D4964 7F09FE34 460A2200 */  add.s $f8, $f4, $f10
/* 0D4968 7F09FE38 E4480014 */  swc1  $f8, 0x14($v0)
/* 0D496C 7F09FE3C 8E2A0000 */  lw    $t2, ($s1)
/* 0D4970 7F09FE40 01501021 */  addu  $v0, $t2, $s0
/* 0D4974 7F09FE44 C4520030 */  lwc1  $f18, 0x30($v0)
/* 0D4978 7F09FE48 C4500018 */  lwc1  $f16, 0x18($v0)
/* 0D497C 7F09FE4C 46189182 */  mul.s $f6, $f18, $f24
/* 0D4980 7F09FE50 46068100 */  add.s $f4, $f16, $f6
/* 0D4984 7F09FE54 E4440018 */  swc1  $f4, 0x18($v0)
/* 0D4988 7F09FE58 8E2B0000 */  lw    $t3, ($s1)
/* 0D498C 7F09FE5C 01701021 */  addu  $v0, $t3, $s0
/* 0D4990 7F09FE60 C448001C */  lwc1  $f8, 0x1c($v0)
/* 0D4994 7F09FE64 C44A0004 */  lwc1  $f10, 4($v0)
/* 0D4998 7F09FE68 46184482 */  mul.s $f18, $f8, $f24
/* 0D499C 7F09FE6C 46125400 */  add.s $f16, $f10, $f18
/* 0D49A0 7F09FE70 E4500004 */  swc1  $f16, 4($v0)
/* 0D49A4 7F09FE74 8E2C0000 */  lw    $t4, ($s1)
/* 0D49A8 7F09FE78 01901021 */  addu  $v0, $t4, $s0
/* 0D49AC 7F09FE7C C4440024 */  lwc1  $f4, 0x24($v0)
/* 0D49B0 7F09FE80 C446000C */  lwc1  $f6, 0xc($v0)
/* 0D49B4 7F09FE84 46182202 */  mul.s $f8, $f4, $f24
/* 0D49B8 7F09FE88 46083280 */  add.s $f10, $f6, $f8
/* 0D49BC 7F09FE8C 18800037 */  blez  $a0, .L7F09FF6C
/* 0D49C0 7F09FE90 E44A000C */   swc1  $f10, 0xc($v0)
/* 0D49C4 7F09FE94 30820001 */  andi  $v0, $a0, 1
/* 0D49C8 7F09FE98 50400014 */  beql  $v0, $zero, .L7F09FEEC
/* 0D49CC 7F09FE9C 8E2F0000 */   lw    $t7, ($s1)
/* 0D49D0 7F09FEA0 8E2D0000 */  lw    $t5, ($s1)
/* 0D49D4 7F09FEA4 24030001 */  li    $v1, 1
/* 0D49D8 7F09FEA8 01B01021 */  addu  $v0, $t5, $s0
/* 0D49DC 7F09FEAC C4520008 */  lwc1  $f18, 8($v0)
/* 0D49E0 7F09FEB0 C4500020 */  lwc1  $f16, 0x20($v0)
/* 0D49E4 7F09FEB4 46109100 */  add.s $f4, $f18, $f16
/* 0D49E8 7F09FEB8 E4440008 */  swc1  $f4, 8($v0)
/* 0D49EC 7F09FEBC 8E2E0000 */  lw    $t6, ($s1)
/* 0D49F0 7F09FEC0 01D01021 */  addu  $v0, $t6, $s0
/* 0D49F4 7F09FEC4 C4400020 */  lwc1  $f0, 0x20($v0)
/* 0D49F8 7F09FEC8 4600A03C */  c.lt.s $f20, $f0
/* 0D49FC 7F09FECC 00000000 */  nop   
/* 0D4A00 7F09FED0 45000003 */  bc1f  .L7F09FEE0
/* 0D4A04 7F09FED4 00000000 */   nop   
/* 0D4A08 7F09FED8 46160181 */  sub.s $f6, $f0, $f22
/* 0D4A0C 7F09FEDC E4460020 */  swc1  $f6, 0x20($v0)
.L7F09FEE0:
/* 0D4A10 7F09FEE0 50640023 */  beql  $v1, $a0, .L7F09FF70
/* 0D4A14 7F09FEE4 8E290000 */   lw    $t1, ($s1)
/* 0D4A18 7F09FEE8 8E2F0000 */  lw    $t7, ($s1)
.L7F09FEEC:
/* 0D4A1C 7F09FEEC 24630002 */  addiu $v1, $v1, 2
/* 0D4A20 7F09FEF0 01F01021 */  addu  $v0, $t7, $s0
/* 0D4A24 7F09FEF4 C4480008 */  lwc1  $f8, 8($v0)
/* 0D4A28 7F09FEF8 C44A0020 */  lwc1  $f10, 0x20($v0)
/* 0D4A2C 7F09FEFC 460A4480 */  add.s $f18, $f8, $f10
/* 0D4A30 7F09FF00 E4520008 */  swc1  $f18, 8($v0)
/* 0D4A34 7F09FF04 8E380000 */  lw    $t8, ($s1)
/* 0D4A38 7F09FF08 03101021 */  addu  $v0, $t8, $s0
/* 0D4A3C 7F09FF0C C4400020 */  lwc1  $f0, 0x20($v0)
/* 0D4A40 7F09FF10 4600A03C */  c.lt.s $f20, $f0
/* 0D4A44 7F09FF14 00000000 */  nop   
/* 0D4A48 7F09FF18 45020007 */  bc1fl .L7F09FF38
/* 0D4A4C 7F09FF1C C4440008 */   lwc1  $f4, 8($v0)
/* 0D4A50 7F09FF20 46160401 */  sub.s $f16, $f0, $f22
/* 0D4A54 7F09FF24 E4500020 */  swc1  $f16, 0x20($v0)
/* 0D4A58 7F09FF28 8E390000 */  lw    $t9, ($s1)
/* 0D4A5C 7F09FF2C 03301021 */  addu  $v0, $t9, $s0
/* 0D4A60 7F09FF30 C4400020 */  lwc1  $f0, 0x20($v0)
/* 0D4A64 7F09FF34 C4440008 */  lwc1  $f4, 8($v0)
.L7F09FF38:
/* 0D4A68 7F09FF38 46002180 */  add.s $f6, $f4, $f0
/* 0D4A6C 7F09FF3C E4460008 */  swc1  $f6, 8($v0)
/* 0D4A70 7F09FF40 8E280000 */  lw    $t0, ($s1)
/* 0D4A74 7F09FF44 01101021 */  addu  $v0, $t0, $s0
/* 0D4A78 7F09FF48 C4400020 */  lwc1  $f0, 0x20($v0)
/* 0D4A7C 7F09FF4C 4600A03C */  c.lt.s $f20, $f0
/* 0D4A80 7F09FF50 00000000 */  nop   
/* 0D4A84 7F09FF54 45000003 */  bc1f  .L7F09FF64
/* 0D4A88 7F09FF58 00000000 */   nop   
/* 0D4A8C 7F09FF5C 46160201 */  sub.s $f8, $f0, $f22
/* 0D4A90 7F09FF60 E4480020 */  swc1  $f8, 0x20($v0)
.L7F09FF64:
/* 0D4A94 7F09FF64 5464FFE1 */  bnel  $v1, $a0, .L7F09FEEC
/* 0D4A98 7F09FF68 8E2F0000 */   lw    $t7, ($s1)
.L7F09FF6C:
/* 0D4A9C 7F09FF6C 8E290000 */  lw    $t1, ($s1)
.L7F09FF70:
/* 0D4AA0 7F09FF70 01301021 */  addu  $v0, $t1, $s0
/* 0D4AA4 7F09FF74 8C4A0000 */  lw    $t2, ($v0)
/* 0D4AA8 7F09FF78 29410065 */  slti  $at, $t2, 0x65
/* 0D4AAC 7F09FF7C 54200011 */  bnezl $at, .L7F09FFC4
/* 0D4AB0 7F09FF80 C4400008 */   lwc1  $f0, 8($v0)
/* 0D4AB4 7F09FF84 0C002914 */  jal   randomGetNext
/* 0D4AB8 7F09FF88 00000000 */   nop   
/* 0D4ABC 7F09FF8C 304B001F */  andi  $t3, $v0, 0x1f
/* 0D4AC0 7F09FF90 51600007 */  beql  $t3, $zero, .L7F09FFB0
/* 0D4AC4 7F09FF94 8E2E0000 */   lw    $t6, ($s1)
/* 0D4AC8 7F09FF98 8E2C0000 */  lw    $t4, ($s1)
/* 0D4ACC 7F09FF9C 01901021 */  addu  $v0, $t4, $s0
/* 0D4AD0 7F09FFA0 8C4D0000 */  lw    $t5, ($v0)
/* 0D4AD4 7F09FFA4 566D0007 */  bnel  $s3, $t5, .L7F09FFC4
/* 0D4AD8 7F09FFA8 C4400008 */   lwc1  $f0, 8($v0)
/* 0D4ADC 7F09FFAC 8E2E0000 */  lw    $t6, ($s1)
.L7F09FFB0:
/* 0D4AE0 7F09FFB0 01D07821 */  addu  $t7, $t6, $s0
/* 0D4AE4 7F09FFB4 ADE00000 */  sw    $zero, ($t7)
/* 0D4AE8 7F09FFB8 8E380000 */  lw    $t8, ($s1)
/* 0D4AEC 7F09FFBC 03101021 */  addu  $v0, $t8, $s0
/* 0D4AF0 7F09FFC0 C4400008 */  lwc1  $f0, 8($v0)
.L7F09FFC4:
/* 0D4AF4 7F09FFC4 461A003C */  c.lt.s $f0, $f26
/* 0D4AF8 7F09FFC8 00000000 */  nop   
/* 0D4AFC 7F09FFCC 45030006 */  bc1tl .L7F09FFE8
/* 0D4B00 7F09FFD0 AC400000 */   sw    $zero, ($v0)
/* 0D4B04 7F09FFD4 4600E03C */  c.lt.s $f28, $f0
/* 0D4B08 7F09FFD8 00000000 */  nop   
/* 0D4B0C 7F09FFDC 45020003 */  bc1fl .L7F09FFEC
/* 0D4B10 7F09FFE0 8E990000 */   lw    $t9, ($s4)
/* 0D4B14 7F09FFE4 AC400000 */  sw    $zero, ($v0)
.L7F09FFE8:
/* 0D4B18 7F09FFE8 8E990000 */  lw    $t9, ($s4)
.L7F09FFEC:
/* 0D4B1C 7F09FFEC 26520001 */  addiu $s2, $s2, 1
/* 0D4B20 7F09FFF0 26100078 */  addiu $s0, $s0, 0x78
/* 0D4B24 7F09FFF4 0259082A */  slt   $at, $s2, $t9
/* 0D4B28 7F09FFF8 5420FF78 */  bnezl $at, .L7F09FDDC
/* 0D4B2C 7F09FFFC 8E2F0000 */   lw    $t7, ($s1)
.L7F0A0000:
/* 0D4B30 7F0A0000 8FBF0054 */  lw    $ra, 0x54($sp)
/* 0D4B34 7F0A0004 D7B40018 */  ldc1  $f20, 0x18($sp)
/* 0D4B38 7F0A0008 D7B60020 */  ldc1  $f22, 0x20($sp)
/* 0D4B3C 7F0A000C D7B80028 */  ldc1  $f24, 0x28($sp)
/* 0D4B40 7F0A0010 D7BA0030 */  ldc1  $f26, 0x30($sp)
/* 0D4B44 7F0A0014 D7BC0038 */  ldc1  $f28, 0x38($sp)
/* 0D4B48 7F0A0018 8FB00040 */  lw    $s0, 0x40($sp)
/* 0D4B4C 7F0A001C 8FB10044 */  lw    $s1, 0x44($sp)
/* 0D4B50 7F0A0020 8FB20048 */  lw    $s2, 0x48($sp)
/* 0D4B54 7F0A0024 8FB3004C */  lw    $s3, 0x4c($sp)
/* 0D4B58 7F0A0028 8FB40050 */  lw    $s4, 0x50($sp)
/* 0D4B5C 7F0A002C 03E00008 */  jr    $ra
/* 0D4B60 7F0A0030 27BD0058 */   addiu $sp, $sp, 0x58
)
#endif





#ifdef NONMATCHING
Gfx * sub_GAME_7F0A0034(Gfx *arg0) {

}
#else
GLOBAL_ASM(
.late_rodata
glabel D_800576FC
.word 0xc69c4000 /*-20000.0*/
glabel D_80057700
.word 0x469c4000 /*20000.0*/
.text
glabel sub_GAME_7F0A0034
/* 0D4B64 7F0A0034 27BDFF40 */  addiu $sp, $sp, -0xc0
/* 0D4B68 7F0A0038 AFB00028 */  sw    $s0, 0x28($sp)
/* 0D4B6C 7F0A003C AFBF004C */  sw    $ra, 0x4c($sp)
/* 0D4B70 7F0A0040 AFBE0048 */  sw    $fp, 0x48($sp)
/* 0D4B74 7F0A0044 AFB70044 */  sw    $s7, 0x44($sp)
/* 0D4B78 7F0A0048 AFB60040 */  sw    $s6, 0x40($sp)
/* 0D4B7C 7F0A004C AFB5003C */  sw    $s5, 0x3c($sp)
/* 0D4B80 7F0A0050 AFB40038 */  sw    $s4, 0x38($sp)
/* 0D4B84 7F0A0054 AFB30034 */  sw    $s3, 0x34($sp)
/* 0D4B88 7F0A0058 AFB20030 */  sw    $s2, 0x30($sp)
/* 0D4B8C 7F0A005C AFB1002C */  sw    $s1, 0x2c($sp)
/* 0D4B90 7F0A0060 F7B60020 */  sdc1  $f22, 0x20($sp)
/* 0D4B94 7F0A0064 F7B40018 */  sdc1  $f20, 0x18($sp)
/* 0D4B98 7F0A0068 3C0EB600 */  lui   $t6, 0xb600
/* 0D4B9C 7F0A006C 240F3000 */  li    $t7, 12288
/* 0D4BA0 7F0A0070 AC8F0004 */  sw    $t7, 4($a0)
/* 0D4BA4 7F0A0074 AC8E0000 */  sw    $t6, ($a0)
/* 0D4BA8 7F0A0078 24900008 */  addiu $s0, $a0, 8
/* 0D4BAC 7F0A007C 3C18BC00 */  lui   $t8, (0xBC000806 >> 16) # lui $t8, 0xbc00
/* 0D4BB0 7F0A0080 37180806 */  ori   $t8, (0xBC000806 & 0xFFFF) # ori $t8, $t8, 0x806
/* 0D4BB4 7F0A0084 02008825 */  move  $s1, $s0
/* 0D4BB8 7F0A0088 AE380000 */  sw    $t8, ($s1)
/* 0D4BBC 7F0A008C 3C048009 */  lui   $a0, %hi(pGlobalimagetable)
/* 0D4BC0 7F0A0090 8C84D0B4 */  lw    $a0, %lo(pGlobalimagetable)($a0)
/* 0D4BC4 7F0A0094 0C003A2C */  jal   osVirtualToPhysical
/* 0D4BC8 7F0A0098 26100008 */   addiu $s0, $s0, 8
/* 0D4BCC 7F0A009C 02001825 */  move  $v1, $s0
/* 0D4BD0 7F0A00A0 AE220004 */  sw    $v0, 4($s1)
/* 0D4BD4 7F0A00A4 3C080200 */  lui   $t0, 0x200
/* 0D4BD8 7F0A00A8 25080A50 */  addiu $t0, $t0, 0xa50
/* 0D4BDC 7F0A00AC 26100008 */  addiu $s0, $s0, 8
/* 0D4BE0 7F0A00B0 3C190600 */  lui   $t9, 0x600
/* 0D4BE4 7F0A00B4 AC790000 */  sw    $t9, ($v1)
/* 0D4BE8 7F0A00B8 AC680004 */  sw    $t0, 4($v1)
/* 0D4BEC 7F0A00BC 02002025 */  move  $a0, $s0
/* 0D4BF0 7F0A00C0 3C09B900 */  lui   $t1, (0xB900031D >> 16) # lui $t1, 0xb900
/* 0D4BF4 7F0A00C4 3C0A0050 */  lui   $t2, (0x005049D8 >> 16) # lui $t2, 0x50
/* 0D4BF8 7F0A00C8 354A49D8 */  ori   $t2, (0x005049D8 & 0xFFFF) # ori $t2, $t2, 0x49d8
/* 0D4BFC 7F0A00CC 3529031D */  ori   $t1, (0xB900031D & 0xFFFF) # ori $t1, $t1, 0x31d
/* 0D4C00 7F0A00D0 AC890000 */  sw    $t1, ($a0)
/* 0D4C04 7F0A00D4 AC8A0004 */  sw    $t2, 4($a0)
/* 0D4C08 7F0A00D8 3C0B8008 */  lui   $t3, %hi(max_casings) 
/* 0D4C0C 7F0A00DC 8D6BA148 */  lw    $t3, %lo(max_casings)($t3)
/* 0D4C10 7F0A00E0 26100008 */  addiu $s0, $s0, 8
/* 0D4C14 7F0A00E4 0000A825 */  move  $s5, $zero
/* 0D4C18 7F0A00E8 19600055 */  blez  $t3, .L7F0A0240
/* 0D4C1C 7F0A00EC 00009825 */   move  $s3, $zero
/* 0D4C20 7F0A00F0 3C018005 */  lui   $at, %hi(D_800576FC)
/* 0D4C24 7F0A00F4 C43676FC */  lwc1  $f22, %lo(D_800576FC)($at)
/* 0D4C28 7F0A00F8 3C018005 */  lui   $at, %hi(D_80057700)
/* 0D4C2C 7F0A00FC 3C1E0430 */  lui   $fp, (0x04300040 >> 16) # lui $fp, 0x430
/* 0D4C30 7F0A0100 3C170102 */  lui   $s7, (0x01020040 >> 16) # lui $s7, 0x102
/* 0D4C34 7F0A0104 3C168008 */  lui   $s6, %hi(ptr_ejected_casing_buf)
/* 0D4C38 7F0A0108 26D6A14C */  addiu $s6, %lo(ptr_ejected_casing_buf) # addiu $s6, $s6, -0x5eb4
/* 0D4C3C 7F0A010C 36F70040 */  ori   $s7, (0x01020040 & 0xFFFF) # ori $s7, $s7, 0x40
/* 0D4C40 7F0A0110 37DE0040 */  ori   $fp, (0x04300040 & 0xFFFF) # ori $fp, $fp, 0x40
/* 0D4C44 7F0A0114 C4347700 */  lwc1  $f20, %lo(D_80057700)($at)
/* 0D4C48 7F0A0118 27B40080 */  addiu $s4, $sp, 0x80
/* 0D4C4C 7F0A011C 8ECC0000 */  lw    $t4, ($s6)
.L7F0A0120:
/* 0D4C50 7F0A0120 01931021 */  addu  $v0, $t4, $s3
/* 0D4C54 7F0A0124 8C4D0000 */  lw    $t5, ($v0)
/* 0D4C58 7F0A0128 24440004 */  addiu $a0, $v0, 4
/* 0D4C5C 7F0A012C 24450010 */  addiu $a1, $v0, 0x10
/* 0D4C60 7F0A0130 19A0003C */  blez  $t5, .L7F0A0224
/* 0D4C64 7F0A0134 00000000 */   nop   
/* 0D4C68 7F0A0138 0FC1624B */  jal   matrix_4x4_set_position_and_rotation_around_xyz
/* 0D4C6C 7F0A013C 02803025 */   move  $a2, $s4
/* 0D4C70 7F0A0140 0FC1E0F1 */  jal   currentPlayerGetMatrix10CC
/* 0D4C74 7F0A0144 00000000 */   nop   
/* 0D4C78 7F0A0148 00402025 */  move  $a0, $v0
/* 0D4C7C 7F0A014C 0FC16026 */  jal   matrix_4x4_multiply_homogeneous_in_place
/* 0D4C80 7F0A0150 02802825 */   move  $a1, $s4
/* 0D4C84 7F0A0154 C7A000B0 */  lwc1  $f0, 0xb0($sp)
/* 0D4C88 7F0A0158 4614003C */  c.lt.s $f0, $f20
/* 0D4C8C 7F0A015C 00000000 */  nop   
/* 0D4C90 7F0A0160 45000030 */  bc1f  .L7F0A0224
/* 0D4C94 7F0A0164 00000000 */   nop   
/* 0D4C98 7F0A0168 4600B03C */  c.lt.s $f22, $f0
/* 0D4C9C 7F0A016C C7A000B4 */  lwc1  $f0, 0xb4($sp)
/* 0D4CA0 7F0A0170 4500002C */  bc1f  .L7F0A0224
/* 0D4CA4 7F0A0174 00000000 */   nop   
/* 0D4CA8 7F0A0178 4614003C */  c.lt.s $f0, $f20
/* 0D4CAC 7F0A017C 00000000 */  nop   
/* 0D4CB0 7F0A0180 45000028 */  bc1f  .L7F0A0224
/* 0D4CB4 7F0A0184 00000000 */   nop   
/* 0D4CB8 7F0A0188 4600B03C */  c.lt.s $f22, $f0
/* 0D4CBC 7F0A018C C7A000B8 */  lwc1  $f0, 0xb8($sp)
/* 0D4CC0 7F0A0190 45000024 */  bc1f  .L7F0A0224
/* 0D4CC4 7F0A0194 00000000 */   nop   
/* 0D4CC8 7F0A0198 4614003C */  c.lt.s $f0, $f20
/* 0D4CCC 7F0A019C 00000000 */  nop   
/* 0D4CD0 7F0A01A0 45000020 */  bc1f  .L7F0A0224
/* 0D4CD4 7F0A01A4 00000000 */   nop   
/* 0D4CD8 7F0A01A8 4600B03C */  c.lt.s $f22, $f0
/* 0D4CDC 7F0A01AC 00000000 */  nop   
/* 0D4CE0 7F0A01B0 4500001C */  bc1f  .L7F0A0224
/* 0D4CE4 7F0A01B4 00000000 */   nop   
/* 0D4CE8 7F0A01B8 0FC2F5B8 */  jal   dynAllocateMatrix
/* 0D4CEC 7F0A01BC 00000000 */   nop   
/* 0D4CF0 7F0A01C0 00409025 */  move  $s2, $v0
/* 0D4CF4 7F0A01C4 02802025 */  move  $a0, $s4
/* 0D4CF8 7F0A01C8 0FC16327 */  jal   matrix_4x4_f32_to_s32
/* 0D4CFC 7F0A01CC 00402825 */   move  $a1, $v0
/* 0D4D00 7F0A01D0 02008825 */  move  $s1, $s0
/* 0D4D04 7F0A01D4 AE370000 */  sw    $s7, ($s1)
/* 0D4D08 7F0A01D8 26100008 */  addiu $s0, $s0, 8
/* 0D4D0C 7F0A01DC 0C003A2C */  jal   osVirtualToPhysical
/* 0D4D10 7F0A01E0 02402025 */   move  $a0, $s2
/* 0D4D14 7F0A01E4 AE220004 */  sw    $v0, 4($s1)
/* 0D4D18 7F0A01E8 02009025 */  move  $s2, $s0
/* 0D4D1C 7F0A01EC AE5E0000 */  sw    $fp, ($s2)
/* 0D4D20 7F0A01F0 8ECE0000 */  lw    $t6, ($s6)
/* 0D4D24 7F0A01F4 26100008 */  addiu $s0, $s0, 8
/* 0D4D28 7F0A01F8 01D32021 */  addu  $a0, $t6, $s3
/* 0D4D2C 7F0A01FC 0C003A2C */  jal   osVirtualToPhysical
/* 0D4D30 7F0A0200 24840038 */   addiu $a0, $a0, 0x38
/* 0D4D34 7F0A0204 02001825 */  move  $v1, $s0
/* 0D4D38 7F0A0208 AE420004 */  sw    $v0, 4($s2)
/* 0D4D3C 7F0A020C 3C0FB100 */  lui   $t7, (0xB1000032 >> 16) # lui $t7, 0xb100
/* 0D4D40 7F0A0210 35EF0032 */  ori   $t7, (0xB1000032 & 0xFFFF) # ori $t7, $t7, 0x32
/* 0D4D44 7F0A0214 24182010 */  li    $t8, 8208
/* 0D4D48 7F0A0218 AC780004 */  sw    $t8, 4($v1)
/* 0D4D4C 7F0A021C AC6F0000 */  sw    $t7, ($v1)
/* 0D4D50 7F0A0220 26100008 */  addiu $s0, $s0, 8
.L7F0A0224:
/* 0D4D54 7F0A0224 3C198008 */  lui   $t9, %hi(max_casings) 
/* 0D4D58 7F0A0228 8F39A148 */  lw    $t9, %lo(max_casings)($t9)
/* 0D4D5C 7F0A022C 26B50001 */  addiu $s5, $s5, 1
/* 0D4D60 7F0A0230 26730078 */  addiu $s3, $s3, 0x78
/* 0D4D64 7F0A0234 02B9082A */  slt   $at, $s5, $t9
/* 0D4D68 7F0A0238 5420FFB9 */  bnezl $at, .L7F0A0120
/* 0D4D6C 7F0A023C 8ECC0000 */   lw    $t4, ($s6)
.L7F0A0240:
/* 0D4D70 7F0A0240 8FBF004C */  lw    $ra, 0x4c($sp)
/* 0D4D74 7F0A0244 02001025 */  move  $v0, $s0
/* 0D4D78 7F0A0248 8FB00028 */  lw    $s0, 0x28($sp)
/* 0D4D7C 7F0A024C D7B40018 */  ldc1  $f20, 0x18($sp)
/* 0D4D80 7F0A0250 D7B60020 */  ldc1  $f22, 0x20($sp)
/* 0D4D84 7F0A0254 8FB1002C */  lw    $s1, 0x2c($sp)
/* 0D4D88 7F0A0258 8FB20030 */  lw    $s2, 0x30($sp)
/* 0D4D8C 7F0A025C 8FB30034 */  lw    $s3, 0x34($sp)
/* 0D4D90 7F0A0260 8FB40038 */  lw    $s4, 0x38($sp)
/* 0D4D94 7F0A0264 8FB5003C */  lw    $s5, 0x3c($sp)
/* 0D4D98 7F0A0268 8FB60040 */  lw    $s6, 0x40($sp)
/* 0D4D9C 7F0A026C 8FB70044 */  lw    $s7, 0x44($sp)
/* 0D4DA0 7F0A0270 8FBE0048 */  lw    $fp, 0x48($sp)
/* 0D4DA4 7F0A0274 03E00008 */  jr    $ra
/* 0D4DA8 7F0A0278 27BD00C0 */   addiu $sp, $sp, 0xc0
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0A027C(void) {

}
#else
GLOBAL_ASM(
.late_rodata
glabel D_80057704
.word 0x40c90fdb /*6.2831855*/
glabel D_80057708
.word 0x3e4ccccd /*0.2*/
glabel D_8005770C
.word 0x3f4ccccd /*0.80000001*/
.text
glabel sub_GAME_7F0A027C
/* 0D4DAC 7F0A027C 27BDFF98 */  addiu $sp, $sp, -0x68
/* 0D4DB0 7F0A0280 3C0E8004 */  lui   $t6, %hi(D_80040920) 
/* 0D4DB4 7F0A0284 AFBF0034 */  sw    $ra, 0x34($sp)
/* 0D4DB8 7F0A0288 AFB40030 */  sw    $s4, 0x30($sp)
/* 0D4DBC 7F0A028C AFB3002C */  sw    $s3, 0x2c($sp)
/* 0D4DC0 7F0A0290 AFB20028 */  sw    $s2, 0x28($sp)
/* 0D4DC4 7F0A0294 AFB10024 */  sw    $s1, 0x24($sp)
/* 0D4DC8 7F0A0298 AFB00020 */  sw    $s0, 0x20($sp)
/* 0D4DCC 7F0A029C F7B40018 */  sdc1  $f20, 0x18($sp)
/* 0D4DD0 7F0A02A0 AFA60070 */  sw    $a2, 0x70($sp)
/* 0D4DD4 7F0A02A4 25CE0920 */  addiu $t6, %lo(D_80040920) # addiu $t6, $t6, 0x920
/* 0D4DD8 7F0A02A8 8DC10000 */  lw    $at, ($t6)
/* 0D4DDC 7F0A02AC 27B30058 */  addiu $s3, $sp, 0x58
/* 0D4DE0 7F0A02B0 4485A000 */  mtc1  $a1, $f20
/* 0D4DE4 7F0A02B4 AE610000 */  sw    $at, ($s3)
/* 0D4DE8 7F0A02B8 8DD90004 */  lw    $t9, 4($t6)
/* 0D4DEC 7F0A02BC 0080A025 */  move  $s4, $a0
/* 0D4DF0 7F0A02C0 AE790004 */  sw    $t9, 4($s3)
/* 0D4DF4 7F0A02C4 8DC10008 */  lw    $at, 8($t6)
/* 0D4DF8 7F0A02C8 AE610008 */  sw    $at, 8($s3)
/* 0D4DFC 7F0A02CC 8DD9000C */  lw    $t9, 0xc($t6)
/* 0D4E00 7F0A02D0 0C002914 */  jal   randomGetNext
/* 0D4E04 7F0A02D4 AE79000C */   sw    $t9, 0xc($s3)
/* 0D4E08 7F0A02D8 44822000 */  mtc1  $v0, $f4
/* 0D4E0C 7F0A02DC 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0D4E10 7F0A02E0 04410004 */  bgez  $v0, .L7F0A02F4
/* 0D4E14 7F0A02E4 468021A0 */   cvt.s.w $f6, $f4
/* 0D4E18 7F0A02E8 44814000 */  mtc1  $at, $f8
/* 0D4E1C 7F0A02EC 00000000 */  nop   
/* 0D4E20 7F0A02F0 46083180 */  add.s $f6, $f6, $f8
.L7F0A02F4:
/* 0D4E24 7F0A02F4 3C012F80 */  li    $at, 0x2F800000 # 0.000000
/* 0D4E28 7F0A02F8 44815000 */  mtc1  $at, $f10
/* 0D4E2C 7F0A02FC 3C018005 */  lui   $at, %hi(D_80057704)
/* 0D4E30 7F0A0300 C4327704 */  lwc1  $f18, %lo(D_80057704)($at)
/* 0D4E34 7F0A0304 460A3402 */  mul.s $f16, $f6, $f10
/* 0D4E38 7F0A0308 00000000 */  nop   
/* 0D4E3C 7F0A030C 46128102 */  mul.s $f4, $f16, $f18
/* 0D4E40 7F0A0310 0C002914 */  jal   randomGetNext
/* 0D4E44 7F0A0314 E7A40054 */   swc1  $f4, 0x54($sp)
/* 0D4E48 7F0A0318 24010050 */  li    $at, 80
/* 0D4E4C 7F0A031C 0041001B */  divu  $zero, $v0, $at
/* 0D4E50 7F0A0320 00004010 */  mfhi  $t0
/* 0D4E54 7F0A0324 240900FF */  li    $t1, 255
/* 0D4E58 7F0A0328 01285023 */  subu  $t2, $t1, $t0
/* 0D4E5C 7F0A032C A3AA004B */  sb    $t2, 0x4b($sp)
/* 0D4E60 7F0A0330 0FC2F285 */  jal   getRoomIndexPOS
/* 0D4E64 7F0A0334 87A40072 */   lh    $a0, 0x72($sp)
/* 0D4E68 7F0A0338 0FC26919 */  jal   getPlayerCount
/* 0D4E6C 7F0A033C 00408025 */   move  $s0, $v0
/* 0D4E70 7F0A0340 28410002 */  slti  $at, $v0, 2
/* 0D4E74 7F0A0344 102001D2 */  beqz  $at, .L7F0A0A90
/* 0D4E78 7F0A0348 3C014348 */   li    $at, 0x43480000 # 200.000000
/* 0D4E7C 7F0A034C 44810000 */  mtc1  $at, $f0
/* 0D4E80 7F0A0350 00000000 */  nop   
/* 0D4E84 7F0A0354 4614003C */  c.lt.s $f0, $f20
/* 0D4E88 7F0A0358 00000000 */  nop   
/* 0D4E8C 7F0A035C 45000002 */  bc1f  .L7F0A0368
/* 0D4E90 7F0A0360 00000000 */   nop   
/* 0D4E94 7F0A0364 46000506 */  mov.s $f20, $f0
.L7F0A0368:
/* 0D4E98 7F0A0368 0C002914 */  jal   randomGetNext
/* 0D4E9C 7F0A036C 00000000 */   nop   
/* 0D4EA0 7F0A0370 44824000 */  mtc1  $v0, $f8
/* 0D4EA4 7F0A0374 04410005 */  bgez  $v0, .L7F0A038C
/* 0D4EA8 7F0A0378 468041A0 */   cvt.s.w $f6, $f8
/* 0D4EAC 7F0A037C 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0D4EB0 7F0A0380 44815000 */  mtc1  $at, $f10
/* 0D4EB4 7F0A0384 00000000 */  nop   
/* 0D4EB8 7F0A0388 460A3180 */  add.s $f6, $f6, $f10
.L7F0A038C:
/* 0D4EBC 7F0A038C 3C012F80 */  li    $at, 0x2F800000 # 0.000000
/* 0D4EC0 7F0A0390 44818000 */  mtc1  $at, $f16
/* 0D4EC4 7F0A0394 3C018005 */  lui   $at, %hi(D_80057708)
/* 0D4EC8 7F0A0398 C4247708 */  lwc1  $f4, %lo(D_80057708)($at)
/* 0D4ECC 7F0A039C 46103482 */  mul.s $f18, $f6, $f16
/* 0D4ED0 7F0A03A0 3C018005 */  lui   $at, %hi(D_8005770C)
/* 0D4ED4 7F0A03A4 C42A770C */  lwc1  $f10, %lo(D_8005770C)($at)
/* 0D4ED8 7F0A03A8 46122202 */  mul.s $f8, $f4, $f18
/* 0D4EDC 7F0A03AC 46085180 */  add.s $f6, $f10, $f8
/* 0D4EE0 7F0A03B0 4606A502 */  mul.s $f20, $f20, $f6
/* 0D4EE4 7F0A03B4 0FC2D20F */  jal   get_room_data_float1
/* 0D4EE8 7F0A03B8 00000000 */   nop   
/* 0D4EEC 7F0A03BC C6900000 */  lwc1  $f16, ($s4)
/* 0D4EF0 7F0A03C0 C6120000 */  lwc1  $f18, ($s0)
/* 0D4EF4 7F0A03C4 46008102 */  mul.s $f4, $f16, $f0
/* 0D4EF8 7F0A03C8 46122281 */  sub.s $f10, $f4, $f18
/* 0D4EFC 7F0A03CC 0FC2D20F */  jal   get_room_data_float1
/* 0D4F00 7F0A03D0 E68A0000 */   swc1  $f10, ($s4)
/* 0D4F04 7F0A03D4 C6880004 */  lwc1  $f8, 4($s4)
/* 0D4F08 7F0A03D8 C6100004 */  lwc1  $f16, 4($s0)
/* 0D4F0C 7F0A03DC 46004182 */  mul.s $f6, $f8, $f0
/* 0D4F10 7F0A03E0 46103101 */  sub.s $f4, $f6, $f16
/* 0D4F14 7F0A03E4 0FC2D20F */  jal   get_room_data_float1
/* 0D4F18 7F0A03E8 E6840004 */   swc1  $f4, 4($s4)
/* 0D4F1C 7F0A03EC C6920008 */  lwc1  $f18, 8($s4)
/* 0D4F20 7F0A03F0 C6080008 */  lwc1  $f8, 8($s0)
/* 0D4F24 7F0A03F4 46009282 */  mul.s $f10, $f18, $f0
/* 0D4F28 7F0A03F8 46085181 */  sub.s $f6, $f10, $f8
/* 0D4F2C 7F0A03FC 0FC2D20F */  jal   get_room_data_float1
/* 0D4F30 7F0A0400 E6860008 */   swc1  $f6, 8($s4)
/* 0D4F34 7F0A0404 4600A502 */  mul.s $f20, $f20, $f0
/* 0D4F38 7F0A0408 0FC15FA8 */  jal   cosf
/* 0D4F3C 7F0A040C C7AC0054 */   lwc1  $f12, 0x54($sp)
/* 0D4F40 7F0A0410 46140402 */  mul.s $f16, $f0, $f20
/* 0D4F44 7F0A0414 C7AC0054 */  lwc1  $f12, 0x54($sp)
/* 0D4F48 7F0A0418 0FC15FAB */  jal   sinf
/* 0D4F4C 7F0A041C E7B00050 */   swc1  $f16, 0x50($sp)
/* 0D4F50 7F0A0420 3C128004 */  lui   $s2, %hi(numScorchEntries)
/* 0D4F54 7F0A0424 26520804 */  addiu $s2, %lo(numScorchEntries) # addiu $s2, $s2, 0x804
/* 0D4F58 7F0A0428 8E4D0000 */  lw    $t5, ($s2)
/* 0D4F5C 7F0A042C 24110058 */  li    $s1, 88
/* 0D4F60 7F0A0430 46140082 */  mul.s $f2, $f0, $f20
/* 0D4F64 7F0A0434 3C108008 */  lui   $s0, %hi(ptr_scorch_buf)
/* 0D4F68 7F0A0438 01B10019 */  multu $t5, $s1
/* 0D4F6C 7F0A043C 2610A150 */  addiu $s0, %lo(ptr_scorch_buf) # addiu $s0, $s0, -0x5eb0
/* 0D4F70 7F0A0440 8E0C0000 */  lw    $t4, ($s0)
/* 0D4F74 7F0A0444 87AB0072 */  lh    $t3, 0x72($sp)
/* 0D4F78 7F0A0448 E7A2004C */  swc1  $f2, 0x4c($sp)
/* 0D4F7C 7F0A044C 0000C012 */  mflo  $t8
/* 0D4F80 7F0A0450 01987821 */  addu  $t7, $t4, $t8
/* 0D4F84 7F0A0454 A5EB0000 */  sh    $t3, ($t7)
/* 0D4F88 7F0A0458 8E590000 */  lw    $t9, ($s2)
/* 0D4F8C 7F0A045C 8E0E0000 */  lw    $t6, ($s0)
/* 0D4F90 7F0A0460 C6840000 */  lwc1  $f4, ($s4)
/* 0D4F94 7F0A0464 03310019 */  multu $t9, $s1
/* 0D4F98 7F0A0468 00004812 */  mflo  $t1
/* 0D4F9C 7F0A046C 01C94021 */  addu  $t0, $t6, $t1
/* 0D4FA0 7F0A0470 E5040004 */  swc1  $f4, 4($t0)
/* 0D4FA4 7F0A0474 8E4D0000 */  lw    $t5, ($s2)
/* 0D4FA8 7F0A0478 8E0A0000 */  lw    $t2, ($s0)
/* 0D4FAC 7F0A047C C6920004 */  lwc1  $f18, 4($s4)
/* 0D4FB0 7F0A0480 01B10019 */  multu $t5, $s1
/* 0D4FB4 7F0A0484 00006012 */  mflo  $t4
/* 0D4FB8 7F0A0488 014CC021 */  addu  $t8, $t2, $t4
/* 0D4FBC 7F0A048C E7120008 */  swc1  $f18, 8($t8)
/* 0D4FC0 7F0A0490 8E4F0000 */  lw    $t7, ($s2)
/* 0D4FC4 7F0A0494 8E0B0000 */  lw    $t3, ($s0)
/* 0D4FC8 7F0A0498 C68A0008 */  lwc1  $f10, 8($s4)
/* 0D4FCC 7F0A049C 01F10019 */  multu $t7, $s1
/* 0D4FD0 7F0A04A0 0000C812 */  mflo  $t9
/* 0D4FD4 7F0A04A4 01797021 */  addu  $t6, $t3, $t9
/* 0D4FD8 7F0A04A8 E5CA000C */  swc1  $f10, 0xc($t6)
/* 0D4FDC 7F0A04AC 8E480000 */  lw    $t0, ($s2)
/* 0D4FE0 7F0A04B0 8E090000 */  lw    $t1, ($s0)
/* 0D4FE4 7F0A04B4 01110019 */  multu $t0, $s1
/* 0D4FE8 7F0A04B8 00006812 */  mflo  $t5
/* 0D4FEC 7F0A04BC 012D5021 */  addu  $t2, $t1, $t5
/* 0D4FF0 7F0A04C0 E5540010 */  swc1  $f20, 0x10($t2)
/* 0D4FF4 7F0A04C4 8E580000 */  lw    $t8, ($s2)
/* 0D4FF8 7F0A04C8 8E0C0000 */  lw    $t4, ($s0)
/* 0D4FFC 7F0A04CC 8E610000 */  lw    $at, ($s3)
/* 0D5000 7F0A04D0 03110019 */  multu $t8, $s1
/* 0D5004 7F0A04D4 00007812 */  mflo  $t7
/* 0D5008 7F0A04D8 018F5821 */  addu  $t3, $t4, $t7
/* 0D500C 7F0A04DC AD610018 */  sw    $at, 0x18($t3)
/* 0D5010 7F0A04E0 8E6E0004 */  lw    $t6, 4($s3)
/* 0D5014 7F0A04E4 AD6E001C */  sw    $t6, 0x1c($t3)
/* 0D5018 7F0A04E8 8E610008 */  lw    $at, 8($s3)
/* 0D501C 7F0A04EC AD610020 */  sw    $at, 0x20($t3)
/* 0D5020 7F0A04F0 8E6E000C */  lw    $t6, 0xc($s3)
/* 0D5024 7F0A04F4 AD6E0024 */  sw    $t6, 0x24($t3)
/* 0D5028 7F0A04F8 8E490000 */  lw    $t1, ($s2)
/* 0D502C 7F0A04FC 8E080000 */  lw    $t0, ($s0)
/* 0D5030 7F0A0500 8E610000 */  lw    $at, ($s3)
/* 0D5034 7F0A0504 01310019 */  multu $t1, $s1
/* 0D5038 7F0A0508 00006812 */  mflo  $t5
/* 0D503C 7F0A050C 010D5021 */  addu  $t2, $t0, $t5
/* 0D5040 7F0A0510 AD410028 */  sw    $at, 0x28($t2)
/* 0D5044 7F0A0514 8E6C0004 */  lw    $t4, 4($s3)
/* 0D5048 7F0A0518 AD4C002C */  sw    $t4, 0x2c($t2)
/* 0D504C 7F0A051C 8E610008 */  lw    $at, 8($s3)
/* 0D5050 7F0A0520 AD410030 */  sw    $at, 0x30($t2)
/* 0D5054 7F0A0524 8E6C000C */  lw    $t4, 0xc($s3)
/* 0D5058 7F0A0528 AD4C0034 */  sw    $t4, 0x34($t2)
/* 0D505C 7F0A052C 8E590000 */  lw    $t9, ($s2)
/* 0D5060 7F0A0530 8E0F0000 */  lw    $t7, ($s0)
/* 0D5064 7F0A0534 8E610000 */  lw    $at, ($s3)
/* 0D5068 7F0A0538 03310019 */  multu $t9, $s1
/* 0D506C 7F0A053C 00005812 */  mflo  $t3
/* 0D5070 7F0A0540 01EB7021 */  addu  $t6, $t7, $t3
/* 0D5074 7F0A0544 ADC10038 */  sw    $at, 0x38($t6)
/* 0D5078 7F0A0548 8E680004 */  lw    $t0, 4($s3)
/* 0D507C 7F0A054C ADC8003C */  sw    $t0, 0x3c($t6)
/* 0D5080 7F0A0550 8E610008 */  lw    $at, 8($s3)
/* 0D5084 7F0A0554 ADC10040 */  sw    $at, 0x40($t6)
/* 0D5088 7F0A0558 8E68000C */  lw    $t0, 0xc($s3)
/* 0D508C 7F0A055C ADC80044 */  sw    $t0, 0x44($t6)
/* 0D5090 7F0A0560 8E580000 */  lw    $t8, ($s2)
/* 0D5094 7F0A0564 8E0D0000 */  lw    $t5, ($s0)
/* 0D5098 7F0A0568 8E610000 */  lw    $at, ($s3)
/* 0D509C 7F0A056C 03110019 */  multu $t8, $s1
/* 0D50A0 7F0A0570 00005012 */  mflo  $t2
/* 0D50A4 7F0A0574 01AA6021 */  addu  $t4, $t5, $t2
/* 0D50A8 7F0A0578 AD810048 */  sw    $at, 0x48($t4)
/* 0D50AC 7F0A057C 8E6F0004 */  lw    $t7, 4($s3)
/* 0D50B0 7F0A0580 AD8F004C */  sw    $t7, 0x4c($t4)
/* 0D50B4 7F0A0584 8E610008 */  lw    $at, 8($s3)
/* 0D50B8 7F0A0588 AD810050 */  sw    $at, 0x50($t4)
/* 0D50BC 7F0A058C 8E6F000C */  lw    $t7, 0xc($s3)
/* 0D50C0 7F0A0590 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 0D50C4 7F0A0594 44815000 */  mtc1  $at, $f10
/* 0D50C8 7F0A0598 AD8F0054 */  sw    $t7, 0x54($t4)
/* 0D50CC 7F0A059C 8E480000 */  lw    $t0, ($s2)
/* 0D50D0 7F0A05A0 C7A60050 */  lwc1  $f6, 0x50($sp)
/* 0D50D4 7F0A05A4 C6880000 */  lwc1  $f8, ($s4)
/* 0D50D8 7F0A05A8 01110019 */  multu $t0, $s1
/* 0D50DC 7F0A05AC 8E0E0000 */  lw    $t6, ($s0)
/* 0D50E0 7F0A05B0 46064400 */  add.s $f16, $f8, $f6
/* 0D50E4 7F0A05B4 4600810D */  trunc.w.s $f4, $f16
/* 0D50E8 7F0A05B8 44092000 */  mfc1  $t1, $f4
/* 0D50EC 7F0A05BC 0000C012 */  mflo  $t8
/* 0D50F0 7F0A05C0 01D86821 */  addu  $t5, $t6, $t8
/* 0D50F4 7F0A05C4 A5A90018 */  sh    $t1, 0x18($t5)
/* 0D50F8 7F0A05C8 8E4F0000 */  lw    $t7, ($s2)
/* 0D50FC 7F0A05CC C6920004 */  lwc1  $f18, 4($s4)
/* 0D5100 7F0A05D0 8E0C0000 */  lw    $t4, ($s0)
/* 0D5104 7F0A05D4 01F10019 */  multu $t7, $s1
/* 0D5108 7F0A05D8 460A9200 */  add.s $f8, $f18, $f10
/* 0D510C 7F0A05DC 3C0E8009 */  lui   $t6, %hi(genericimage) 
/* 0D5110 7F0A05E0 4600418D */  trunc.w.s $f6, $f8
/* 0D5114 7F0A05E4 44193000 */  mfc1  $t9, $f6
/* 0D5118 7F0A05E8 00005812 */  mflo  $t3
/* 0D511C 7F0A05EC 018B4021 */  addu  $t0, $t4, $t3
/* 0D5120 7F0A05F0 A519001A */  sh    $t9, 0x1a($t0)
/* 0D5124 7F0A05F4 8E4D0000 */  lw    $t5, ($s2)
/* 0D5128 7F0A05F8 C6900008 */  lwc1  $f16, 8($s4)
/* 0D512C 7F0A05FC 8E090000 */  lw    $t1, ($s0)
/* 0D5130 7F0A0600 01B10019 */  multu $t5, $s1
/* 0D5134 7F0A0604 46028100 */  add.s $f4, $f16, $f2
/* 0D5138 7F0A0608 4600248D */  trunc.w.s $f18, $f4
/* 0D513C 7F0A060C 44189000 */  mfc1  $t8, $f18
/* 0D5140 7F0A0610 00005012 */  mflo  $t2
/* 0D5144 7F0A0614 012A7821 */  addu  $t7, $t1, $t2
/* 0D5148 7F0A0618 A5F8001C */  sh    $t8, 0x1c($t7)
/* 0D514C 7F0A061C 8E4B0000 */  lw    $t3, ($s2)
/* 0D5150 7F0A0620 8E0C0000 */  lw    $t4, ($s0)
/* 0D5154 7F0A0624 01710019 */  multu $t3, $s1
/* 0D5158 7F0A0628 0000C812 */  mflo  $t9
/* 0D515C 7F0A062C 01994021 */  addu  $t0, $t4, $t9
/* 0D5160 7F0A0630 A5000020 */  sh    $zero, 0x20($t0)
/* 0D5164 7F0A0634 8E580000 */  lw    $t8, ($s2)
/* 0D5168 7F0A0638 8DCED0B8 */  lw    $t6, %lo(genericimage)($t6)
/* 0D516C 7F0A063C 8E0A0000 */  lw    $t2, ($s0)
/* 0D5170 7F0A0640 03110019 */  multu $t8, $s1
/* 0D5174 7F0A0644 91CD0004 */  lbu   $t5, 4($t6)
/* 0D5178 7F0A0648 000D4940 */  sll   $t1, $t5, 5
/* 0D517C 7F0A064C 00007812 */  mflo  $t7
/* 0D5180 7F0A0650 014F5821 */  addu  $t3, $t2, $t7
/* 0D5184 7F0A0654 0C002914 */  jal   randomGetNext
/* 0D5188 7F0A0658 A5690022 */   sh    $t1, 0x22($t3)
/* 0D518C 7F0A065C 24010032 */  li    $at, 50
/* 0D5190 7F0A0660 0041001B */  divu  $zero, $v0, $at
/* 0D5194 7F0A0664 00009810 */  mfhi  $s3
/* 0D5198 7F0A0668 8E590000 */  lw    $t9, ($s2)
/* 0D519C 7F0A066C 8E0C0000 */  lw    $t4, ($s0)
/* 0D51A0 7F0A0670 C7B4004C */  lwc1  $f20, 0x4c($sp)
/* 0D51A4 7F0A0674 03310019 */  multu $t9, $s1
/* 0D51A8 7F0A0678 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 0D51AC 7F0A067C 44812000 */  mtc1  $at, $f4
/* 0D51B0 7F0A0680 00004012 */  mflo  $t0
/* 0D51B4 7F0A0684 01887021 */  addu  $t6, $t4, $t0
/* 0D51B8 7F0A0688 A1D30026 */  sb    $s3, 0x26($t6)
/* 0D51BC 7F0A068C 8E580000 */  lw    $t8, ($s2)
/* 0D51C0 7F0A0690 8E0D0000 */  lw    $t5, ($s0)
/* 0D51C4 7F0A0694 03110019 */  multu $t8, $s1
/* 0D51C8 7F0A0698 00005012 */  mflo  $t2
/* 0D51CC 7F0A069C 01AA7821 */  addu  $t7, $t5, $t2
/* 0D51D0 7F0A06A0 A1F30025 */  sb    $s3, 0x25($t7)
/* 0D51D4 7F0A06A4 8E4B0000 */  lw    $t3, ($s2)
/* 0D51D8 7F0A06A8 8E090000 */  lw    $t1, ($s0)
/* 0D51DC 7F0A06AC 01710019 */  multu $t3, $s1
/* 0D51E0 7F0A06B0 0000C812 */  mflo  $t9
/* 0D51E4 7F0A06B4 01396021 */  addu  $t4, $t1, $t9
/* 0D51E8 7F0A06B8 A1930024 */  sb    $s3, 0x24($t4)
/* 0D51EC 7F0A06BC 8E580000 */  lw    $t8, ($s2)
/* 0D51F0 7F0A06C0 8E0E0000 */  lw    $t6, ($s0)
/* 0D51F4 7F0A06C4 93A8004B */  lbu   $t0, 0x4b($sp)
/* 0D51F8 7F0A06C8 03110019 */  multu $t8, $s1
/* 0D51FC 7F0A06CC 00006812 */  mflo  $t5
/* 0D5200 7F0A06D0 01CD5021 */  addu  $t2, $t6, $t5
/* 0D5204 7F0A06D4 A1480027 */  sb    $t0, 0x27($t2)
/* 0D5208 7F0A06D8 8E590000 */  lw    $t9, ($s2)
/* 0D520C 7F0A06DC C68A0000 */  lwc1  $f10, ($s4)
/* 0D5210 7F0A06E0 8E090000 */  lw    $t1, ($s0)
/* 0D5214 7F0A06E4 03310019 */  multu $t9, $s1
/* 0D5218 7F0A06E8 46145200 */  add.s $f8, $f10, $f20
/* 0D521C 7F0A06EC 4600418D */  trunc.w.s $f6, $f8
/* 0D5220 7F0A06F0 440B3000 */  mfc1  $t3, $f6
/* 0D5224 7F0A06F4 00006012 */  mflo  $t4
/* 0D5228 7F0A06F8 012CC021 */  addu  $t8, $t1, $t4
/* 0D522C 7F0A06FC A70B0028 */  sh    $t3, 0x28($t8)
/* 0D5230 7F0A0700 8E4A0000 */  lw    $t2, ($s2)
/* 0D5234 7F0A0704 C6900004 */  lwc1  $f16, 4($s4)
/* 0D5238 7F0A0708 8E080000 */  lw    $t0, ($s0)
/* 0D523C 7F0A070C 01510019 */  multu $t2, $s1
/* 0D5240 7F0A0710 46048480 */  add.s $f18, $f16, $f4
/* 0D5244 7F0A0714 4600928D */  trunc.w.s $f10, $f18
/* 0D5248 7F0A0718 440D5000 */  mfc1  $t5, $f10
/* 0D524C 7F0A071C 00007812 */  mflo  $t7
/* 0D5250 7F0A0720 010FC821 */  addu  $t9, $t0, $t7
/* 0D5254 7F0A0724 A72D002A */  sh    $t5, 0x2a($t9)
/* 0D5258 7F0A0728 8E580000 */  lw    $t8, ($s2)
/* 0D525C 7F0A072C C7A60050 */  lwc1  $f6, 0x50($sp)
/* 0D5260 7F0A0730 C6880008 */  lwc1  $f8, 8($s4)
/* 0D5264 7F0A0734 03110019 */  multu $t8, $s1
/* 0D5268 7F0A0738 8E0B0000 */  lw    $t3, ($s0)
/* 0D526C 7F0A073C 46064401 */  sub.s $f16, $f8, $f6
/* 0D5270 7F0A0740 4600810D */  trunc.w.s $f4, $f16
/* 0D5274 7F0A0744 440C2000 */  mfc1  $t4, $f4
/* 0D5278 7F0A0748 00007012 */  mflo  $t6
/* 0D527C 7F0A074C 016E5021 */  addu  $t2, $t3, $t6
/* 0D5280 7F0A0750 A54C002C */  sh    $t4, 0x2c($t2)
/* 0D5284 7F0A0754 8E4F0000 */  lw    $t7, ($s2)
/* 0D5288 7F0A0758 8E080000 */  lw    $t0, ($s0)
/* 0D528C 7F0A075C 01F10019 */  multu $t7, $s1
/* 0D5290 7F0A0760 00006812 */  mflo  $t5
/* 0D5294 7F0A0764 010DC821 */  addu  $t9, $t0, $t5
/* 0D5298 7F0A0768 A7200030 */  sh    $zero, 0x30($t9)
/* 0D529C 7F0A076C 8E580000 */  lw    $t8, ($s2)
/* 0D52A0 7F0A0770 8E090000 */  lw    $t1, ($s0)
/* 0D52A4 7F0A0774 03110019 */  multu $t8, $s1
/* 0D52A8 7F0A0778 00005812 */  mflo  $t3
/* 0D52AC 7F0A077C 012B7021 */  addu  $t6, $t1, $t3
/* 0D52B0 7F0A0780 0C002914 */  jal   randomGetNext
/* 0D52B4 7F0A0784 A5C00032 */   sh    $zero, 0x32($t6)
/* 0D52B8 7F0A0788 24010032 */  li    $at, 50
/* 0D52BC 7F0A078C 0041001B */  divu  $zero, $v0, $at
/* 0D52C0 7F0A0790 00009810 */  mfhi  $s3
/* 0D52C4 7F0A0794 8E4A0000 */  lw    $t2, ($s2)
/* 0D52C8 7F0A0798 8E0C0000 */  lw    $t4, ($s0)
/* 0D52CC 7F0A079C 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 0D52D0 7F0A07A0 01510019 */  multu $t2, $s1
/* 0D52D4 7F0A07A4 44812000 */  mtc1  $at, $f4
/* 0D52D8 7F0A07A8 00007812 */  mflo  $t7
/* 0D52DC 7F0A07AC 018F4021 */  addu  $t0, $t4, $t7
/* 0D52E0 7F0A07B0 A1130036 */  sb    $s3, 0x36($t0)
/* 0D52E4 7F0A07B4 8E590000 */  lw    $t9, ($s2)
/* 0D52E8 7F0A07B8 8E0D0000 */  lw    $t5, ($s0)
/* 0D52EC 7F0A07BC 03310019 */  multu $t9, $s1
/* 0D52F0 7F0A07C0 0000C012 */  mflo  $t8
/* 0D52F4 7F0A07C4 01B84821 */  addu  $t1, $t5, $t8
/* 0D52F8 7F0A07C8 A1330035 */  sb    $s3, 0x35($t1)
/* 0D52FC 7F0A07CC 8E4E0000 */  lw    $t6, ($s2)
/* 0D5300 7F0A07D0 8E0B0000 */  lw    $t3, ($s0)
/* 0D5304 7F0A07D4 01D10019 */  multu $t6, $s1
/* 0D5308 7F0A07D8 00005012 */  mflo  $t2
/* 0D530C 7F0A07DC 016A6021 */  addu  $t4, $t3, $t2
/* 0D5310 7F0A07E0 A1930034 */  sb    $s3, 0x34($t4)
/* 0D5314 7F0A07E4 8E590000 */  lw    $t9, ($s2)
/* 0D5318 7F0A07E8 8E080000 */  lw    $t0, ($s0)
/* 0D531C 7F0A07EC 93AF004B */  lbu   $t7, 0x4b($sp)
/* 0D5320 7F0A07F0 03310019 */  multu $t9, $s1
/* 0D5324 7F0A07F4 00006812 */  mflo  $t5
/* 0D5328 7F0A07F8 010DC021 */  addu  $t8, $t0, $t5
/* 0D532C 7F0A07FC A30F0037 */  sb    $t7, 0x37($t8)
/* 0D5330 7F0A0800 8E4A0000 */  lw    $t2, ($s2)
/* 0D5334 7F0A0804 C7AA0050 */  lwc1  $f10, 0x50($sp)
/* 0D5338 7F0A0808 C6920000 */  lwc1  $f18, ($s4)
/* 0D533C 7F0A080C 01510019 */  multu $t2, $s1
/* 0D5340 7F0A0810 8E0B0000 */  lw    $t3, ($s0)
/* 0D5344 7F0A0814 460A9201 */  sub.s $f8, $f18, $f10
/* 0D5348 7F0A0818 4600418D */  trunc.w.s $f6, $f8
/* 0D534C 7F0A081C 440E3000 */  mfc1  $t6, $f6
/* 0D5350 7F0A0820 00006012 */  mflo  $t4
/* 0D5354 7F0A0824 016CC821 */  addu  $t9, $t3, $t4
/* 0D5358 7F0A0828 A72E0038 */  sh    $t6, 0x38($t9)
/* 0D535C 7F0A082C 8E580000 */  lw    $t8, ($s2)
/* 0D5360 7F0A0830 C6900004 */  lwc1  $f16, 4($s4)
/* 0D5364 7F0A0834 8E0F0000 */  lw    $t7, ($s0)
/* 0D5368 7F0A0838 03110019 */  multu $t8, $s1
/* 0D536C 7F0A083C 46048480 */  add.s $f18, $f16, $f4
/* 0D5370 7F0A0840 4600928D */  trunc.w.s $f10, $f18
/* 0D5374 7F0A0844 440D5000 */  mfc1  $t5, $f10
/* 0D5378 7F0A0848 00004812 */  mflo  $t1
/* 0D537C 7F0A084C 01E95021 */  addu  $t2, $t7, $t1
/* 0D5380 7F0A0850 A54D003A */  sh    $t5, 0x3a($t2)
/* 0D5384 7F0A0854 8E590000 */  lw    $t9, ($s2)
/* 0D5388 7F0A0858 C6880008 */  lwc1  $f8, 8($s4)
/* 0D538C 7F0A085C 8E0E0000 */  lw    $t6, ($s0)
/* 0D5390 7F0A0860 03310019 */  multu $t9, $s1
/* 0D5394 7F0A0864 46144181 */  sub.s $f6, $f8, $f20
/* 0D5398 7F0A0868 3C0F8009 */  lui   $t7, %hi(genericimage) 
/* 0D539C 7F0A086C 4600340D */  trunc.w.s $f16, $f6
/* 0D53A0 7F0A0870 440C8000 */  mfc1  $t4, $f16
/* 0D53A4 7F0A0874 00004012 */  mflo  $t0
/* 0D53A8 7F0A0878 01C8C021 */  addu  $t8, $t6, $t0
/* 0D53AC 7F0A087C A70C003C */  sh    $t4, 0x3c($t8)
/* 0D53B0 7F0A0880 8E4B0000 */  lw    $t3, ($s2)
/* 0D53B4 7F0A0884 8DEFD0B8 */  lw    $t7, %lo(genericimage)($t7)
/* 0D53B8 7F0A0888 8E0A0000 */  lw    $t2, ($s0)
/* 0D53BC 7F0A088C 01710019 */  multu $t3, $s1
/* 0D53C0 7F0A0890 91E90005 */  lbu   $t1, 5($t7)
/* 0D53C4 7F0A0894 00096940 */  sll   $t5, $t1, 5
/* 0D53C8 7F0A0898 0000C812 */  mflo  $t9
/* 0D53CC 7F0A089C 01597021 */  addu  $t6, $t2, $t9
/* 0D53D0 7F0A08A0 A5CD0040 */  sh    $t5, 0x40($t6)
/* 0D53D4 7F0A08A4 8E4C0000 */  lw    $t4, ($s2)
/* 0D53D8 7F0A08A8 8E080000 */  lw    $t0, ($s0)
/* 0D53DC 7F0A08AC 01910019 */  multu $t4, $s1
/* 0D53E0 7F0A08B0 0000C012 */  mflo  $t8
/* 0D53E4 7F0A08B4 01187821 */  addu  $t7, $t0, $t8
/* 0D53E8 7F0A08B8 0C002914 */  jal   randomGetNext
/* 0D53EC 7F0A08BC A5E00042 */   sh    $zero, 0x42($t7)
/* 0D53F0 7F0A08C0 24010032 */  li    $at, 50
/* 0D53F4 7F0A08C4 0041001B */  divu  $zero, $v0, $at
/* 0D53F8 7F0A08C8 00009810 */  mfhi  $s3
/* 0D53FC 7F0A08CC 8E4B0000 */  lw    $t3, ($s2)
/* 0D5400 7F0A08D0 8E090000 */  lw    $t1, ($s0)
/* 0D5404 7F0A08D4 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 0D5408 7F0A08D8 01710019 */  multu $t3, $s1
/* 0D540C 7F0A08DC 44813000 */  mtc1  $at, $f6
/* 0D5410 7F0A08E0 00005012 */  mflo  $t2
/* 0D5414 7F0A08E4 012AC821 */  addu  $t9, $t1, $t2
/* 0D5418 7F0A08E8 A3330046 */  sb    $s3, 0x46($t9)
/* 0D541C 7F0A08EC 8E4E0000 */  lw    $t6, ($s2)
/* 0D5420 7F0A08F0 8E0D0000 */  lw    $t5, ($s0)
/* 0D5424 7F0A08F4 01D10019 */  multu $t6, $s1
/* 0D5428 7F0A08F8 00006012 */  mflo  $t4
/* 0D542C 7F0A08FC 01AC4021 */  addu  $t0, $t5, $t4
/* 0D5430 7F0A0900 A1130045 */  sb    $s3, 0x45($t0)
/* 0D5434 7F0A0904 8E4F0000 */  lw    $t7, ($s2)
/* 0D5438 7F0A0908 8E180000 */  lw    $t8, ($s0)
/* 0D543C 7F0A090C 01F10019 */  multu $t7, $s1
/* 0D5440 7F0A0910 00005812 */  mflo  $t3
/* 0D5444 7F0A0914 030B4821 */  addu  $t1, $t8, $t3
/* 0D5448 7F0A0918 A1330044 */  sb    $s3, 0x44($t1)
/* 0D544C 7F0A091C 8E4E0000 */  lw    $t6, ($s2)
/* 0D5450 7F0A0920 8E190000 */  lw    $t9, ($s0)
/* 0D5454 7F0A0924 93AA004B */  lbu   $t2, 0x4b($sp)
/* 0D5458 7F0A0928 01D10019 */  multu $t6, $s1
/* 0D545C 7F0A092C 00006812 */  mflo  $t5
/* 0D5460 7F0A0930 032D6021 */  addu  $t4, $t9, $t5
/* 0D5464 7F0A0934 A18A0047 */  sb    $t2, 0x47($t4)
/* 0D5468 7F0A0938 8E4B0000 */  lw    $t3, ($s2)
/* 0D546C 7F0A093C C6840000 */  lwc1  $f4, ($s4)
/* 0D5470 7F0A0940 8E180000 */  lw    $t8, ($s0)
/* 0D5474 7F0A0944 01710019 */  multu $t3, $s1
/* 0D5478 7F0A0948 46142481 */  sub.s $f18, $f4, $f20
/* 0D547C 7F0A094C 4600928D */  trunc.w.s $f10, $f18
/* 0D5480 7F0A0950 440F5000 */  mfc1  $t7, $f10
/* 0D5484 7F0A0954 00004812 */  mflo  $t1
/* 0D5488 7F0A0958 03097021 */  addu  $t6, $t8, $t1
/* 0D548C 7F0A095C A5CF0048 */  sh    $t7, 0x48($t6)
/* 0D5490 7F0A0960 8E4C0000 */  lw    $t4, ($s2)
/* 0D5494 7F0A0964 C6880004 */  lwc1  $f8, 4($s4)
/* 0D5498 7F0A0968 8E0A0000 */  lw    $t2, ($s0)
/* 0D549C 7F0A096C 01910019 */  multu $t4, $s1
/* 0D54A0 7F0A0970 46064400 */  add.s $f16, $f8, $f6
/* 0D54A4 7F0A0974 4600810D */  trunc.w.s $f4, $f16
/* 0D54A8 7F0A0978 440D2000 */  mfc1  $t5, $f4
/* 0D54AC 7F0A097C 00004012 */  mflo  $t0
/* 0D54B0 7F0A0980 01485821 */  addu  $t3, $t2, $t0
/* 0D54B4 7F0A0984 A56D004A */  sh    $t5, 0x4a($t3)
/* 0D54B8 7F0A0988 8E4E0000 */  lw    $t6, ($s2)
/* 0D54BC 7F0A098C C7AA0050 */  lwc1  $f10, 0x50($sp)
/* 0D54C0 7F0A0990 C6920008 */  lwc1  $f18, 8($s4)
/* 0D54C4 7F0A0994 01D10019 */  multu $t6, $s1
/* 0D54C8 7F0A0998 8E0F0000 */  lw    $t7, ($s0)
/* 0D54CC 7F0A099C 460A9200 */  add.s $f8, $f18, $f10
/* 0D54D0 7F0A09A0 3C0A8009 */  lui   $t2, %hi(genericimage) 
/* 0D54D4 7F0A09A4 4600418D */  trunc.w.s $f6, $f8
/* 0D54D8 7F0A09A8 44093000 */  mfc1  $t1, $f6
/* 0D54DC 7F0A09AC 0000C812 */  mflo  $t9
/* 0D54E0 7F0A09B0 01F96021 */  addu  $t4, $t7, $t9
/* 0D54E4 7F0A09B4 A589004C */  sh    $t1, 0x4c($t4)
/* 0D54E8 7F0A09B8 8E580000 */  lw    $t8, ($s2)
/* 0D54EC 7F0A09BC 8D4AD0B8 */  lw    $t2, %lo(genericimage)($t2)
/* 0D54F0 7F0A09C0 8E0B0000 */  lw    $t3, ($s0)
/* 0D54F4 7F0A09C4 03110019 */  multu $t8, $s1
/* 0D54F8 7F0A09C8 91480004 */  lbu   $t0, 4($t2)
/* 0D54FC 7F0A09CC 3C198009 */  lui   $t9, %hi(genericimage) 
/* 0D5500 7F0A09D0 00086940 */  sll   $t5, $t0, 5
/* 0D5504 7F0A09D4 00007012 */  mflo  $t6
/* 0D5508 7F0A09D8 016E7821 */  addu  $t7, $t3, $t6
/* 0D550C 7F0A09DC A5ED0050 */  sh    $t5, 0x50($t7)
/* 0D5510 7F0A09E0 8E480000 */  lw    $t0, ($s2)
/* 0D5514 7F0A09E4 8F39D0B8 */  lw    $t9, %lo(genericimage)($t9)
/* 0D5518 7F0A09E8 8E0A0000 */  lw    $t2, ($s0)
/* 0D551C 7F0A09EC 01110019 */  multu $t0, $s1
/* 0D5520 7F0A09F0 93290005 */  lbu   $t1, 5($t9)
/* 0D5524 7F0A09F4 00096140 */  sll   $t4, $t1, 5
/* 0D5528 7F0A09F8 0000C012 */  mflo  $t8
/* 0D552C 7F0A09FC 01585821 */  addu  $t3, $t2, $t8
/* 0D5530 7F0A0A00 0C002914 */  jal   randomGetNext
/* 0D5534 7F0A0A04 A56C0052 */   sh    $t4, 0x52($t3)
/* 0D5538 7F0A0A08 24010032 */  li    $at, 50
/* 0D553C 7F0A0A0C 0041001B */  divu  $zero, $v0, $at
/* 0D5540 7F0A0A10 00009810 */  mfhi  $s3
/* 0D5544 7F0A0A14 8E4D0000 */  lw    $t5, ($s2)
/* 0D5548 7F0A0A18 8E0E0000 */  lw    $t6, ($s0)
/* 0D554C 7F0A0A1C 01B10019 */  multu $t5, $s1
/* 0D5550 7F0A0A20 00007812 */  mflo  $t7
/* 0D5554 7F0A0A24 01CFC821 */  addu  $t9, $t6, $t7
/* 0D5558 7F0A0A28 A3330056 */  sb    $s3, 0x56($t9)
/* 0D555C 7F0A0A2C 8E480000 */  lw    $t0, ($s2)
/* 0D5560 7F0A0A30 8E090000 */  lw    $t1, ($s0)
/* 0D5564 7F0A0A34 01110019 */  multu $t0, $s1
/* 0D5568 7F0A0A38 00005012 */  mflo  $t2
/* 0D556C 7F0A0A3C 012AC021 */  addu  $t8, $t1, $t2
/* 0D5570 7F0A0A40 A3130055 */  sb    $s3, 0x55($t8)
/* 0D5574 7F0A0A44 8E4B0000 */  lw    $t3, ($s2)
/* 0D5578 7F0A0A48 8E0C0000 */  lw    $t4, ($s0)
/* 0D557C 7F0A0A4C 01710019 */  multu $t3, $s1
/* 0D5580 7F0A0A50 00006812 */  mflo  $t5
/* 0D5584 7F0A0A54 018D7021 */  addu  $t6, $t4, $t5
/* 0D5588 7F0A0A58 A1D30054 */  sb    $s3, 0x54($t6)
/* 0D558C 7F0A0A5C 8E480000 */  lw    $t0, ($s2)
/* 0D5590 7F0A0A60 8E190000 */  lw    $t9, ($s0)
/* 0D5594 7F0A0A64 93AF004B */  lbu   $t7, 0x4b($sp)
/* 0D5598 7F0A0A68 01110019 */  multu $t0, $s1
/* 0D559C 7F0A0A6C 00004812 */  mflo  $t1
/* 0D55A0 7F0A0A70 03295021 */  addu  $t2, $t9, $t1
/* 0D55A4 7F0A0A74 A14F0057 */  sb    $t7, 0x57($t2)
/* 0D55A8 7F0A0A78 8E580000 */  lw    $t8, ($s2)
/* 0D55AC 7F0A0A7C 270B0001 */  addiu $t3, $t8, 1
/* 0D55B0 7F0A0A80 29610014 */  slti  $at, $t3, 0x14
/* 0D55B4 7F0A0A84 14200002 */  bnez  $at, .L7F0A0A90
/* 0D55B8 7F0A0A88 AE4B0000 */   sw    $t3, ($s2)
/* 0D55BC 7F0A0A8C AE400000 */  sw    $zero, ($s2)
.L7F0A0A90:
/* 0D55C0 7F0A0A90 8FBF0034 */  lw    $ra, 0x34($sp)
/* 0D55C4 7F0A0A94 D7B40018 */  ldc1  $f20, 0x18($sp)
/* 0D55C8 7F0A0A98 8FB00020 */  lw    $s0, 0x20($sp)
/* 0D55CC 7F0A0A9C 8FB10024 */  lw    $s1, 0x24($sp)
/* 0D55D0 7F0A0AA0 8FB20028 */  lw    $s2, 0x28($sp)
/* 0D55D4 7F0A0AA4 8FB3002C */  lw    $s3, 0x2c($sp)
/* 0D55D8 7F0A0AA8 8FB40030 */  lw    $s4, 0x30($sp)
/* 0D55DC 7F0A0AAC 03E00008 */  jr    $ra
/* 0D55E0 7F0A0AB0 27BD0068 */   addiu $sp, $sp, 0x68
)
#endif




/**
 * Address 0x7F0A0AB4.
*/
Gfx *sub_GAME_7F0A0AB4(Gfx *arg0)
{
    //temp_t6 = arg0;
    s32 i;
    s32 phi_s3 = -1;

    if (getPlayerCount() >= 2)
    {
        return arg0;
    }
    else
    {
        gSPSetGeometryMode(arg0++, G_CULL_BACK);
        gSPClearGeometryMode(arg0++, G_CULL_FRONT | G_FOG);
        gDPSetColorDither(arg0++, G_CD_NOISE);

        likely_generate_DL_for_image_declaration(&arg0, genericimage, 4, 1, 2);

        for (i=0; i<20; i++)
        {
            if (ptr_scorch_buf[i].roomid >= 0 && getROOMID_Bitflags(ptr_scorch_buf[i].roomid))
            {
                if (phi_s3 != ptr_scorch_buf[i].roomid)
                {
                    phi_s3 = ptr_scorch_buf[i].roomid;
                    arg0 = sub_GAME_7F0BC9C4(arg0, ptr_scorch_buf[i].roomid);
                }

                /**
                 * Loads into the RSP vertex buffer the vertices that will be used by the gSP1Triangle commands that generates polygons. 
                 * 
                 * param v: the segment address of vertex list. 
                 * param n: the number of vertices (1~32) 
                 * param v0: Starting index in vertex buffer where vertices are to be loaded 
                 * gSPVertex(Gfx *gdl, Vtx *v, u32 n, u32 v0)
                */
                gSPVertex(arg0++, osVirtualToPhysical((void*)ptr_scorch_buf[i].vertex_list), 4, 0);
                gSP2Triangles(arg0++,
                                0, 1, 2, 0,
                                0, 2, 3, 0);
            }
        }

        gDPSetColorDither(arg0++, G_CD_BAYER);
    }

    return arg0;
}





s32 sub_GAME_7F0A0C74(f32 arg0)
{
    if (arg0 >= 0.0f)
    {
        return (s32) (arg0 + 0.5f);
    }
    return (s32) (arg0 - 0.5f);
}





#ifdef NONMATCHING
void sub_GAME_7F0A0CCC(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0A0CCC
/* 0D57FC 7F0A0CCC AFA50004 */  sw    $a1, 4($sp)
/* 0D5800 7F0A0CD0 00057600 */  sll   $t6, $a1, 0x18
/* 0D5804 7F0A0CD4 3C068008 */  lui   $a2, %hi(ptr_bullet_impact_buf)
/* 0D5808 7F0A0CD8 000E2E03 */  sra   $a1, $t6, 0x18
/* 0D580C 7F0A0CDC 24C6A154 */  addiu $a2, %lo(ptr_bullet_impact_buf) # addiu $a2, $a2, -0x5eac
/* 0D5810 7F0A0CE0 00001825 */  move  $v1, $zero
/* 0D5814 7F0A0CE4 24081F40 */  li    $t0, 8000
/* 0D5818 7F0A0CE8 2407FFFF */  li    $a3, -1
/* 0D581C 7F0A0CEC 8CD80000 */  lw    $t8, ($a2)
.L7F0A0CF0:
/* 0D5820 7F0A0CF0 03031021 */  addu  $v0, $t8, $v1
/* 0D5824 7F0A0CF4 8C590048 */  lw    $t9, 0x48($v0)
/* 0D5828 7F0A0CF8 54990008 */  bnel  $a0, $t9, .L7F0A0D1C
/* 0D582C 7F0A0CFC 8C4B0098 */   lw    $t3, 0x98($v0)
/* 0D5830 7F0A0D00 8049004D */  lb    $t1, 0x4d($v0)
/* 0D5834 7F0A0D04 54A90005 */  bnel  $a1, $t1, .L7F0A0D1C
/* 0D5838 7F0A0D08 8C4B0098 */   lw    $t3, 0x98($v0)
/* 0D583C 7F0A0D0C A4470000 */  sh    $a3, ($v0)
/* 0D5840 7F0A0D10 8CCA0000 */  lw    $t2, ($a2)
/* 0D5844 7F0A0D14 01431021 */  addu  $v0, $t2, $v1
/* 0D5848 7F0A0D18 8C4B0098 */  lw    $t3, 0x98($v0)
.L7F0A0D1C:
/* 0D584C 7F0A0D1C 548B0008 */  bnel  $a0, $t3, .L7F0A0D40
/* 0D5850 7F0A0D20 8C4E00E8 */   lw    $t6, 0xe8($v0)
/* 0D5854 7F0A0D24 804C009D */  lb    $t4, 0x9d($v0)
/* 0D5858 7F0A0D28 54AC0005 */  bnel  $a1, $t4, .L7F0A0D40
/* 0D585C 7F0A0D2C 8C4E00E8 */   lw    $t6, 0xe8($v0)
/* 0D5860 7F0A0D30 A4470050 */  sh    $a3, 0x50($v0)
/* 0D5864 7F0A0D34 8CCD0000 */  lw    $t5, ($a2)
/* 0D5868 7F0A0D38 01A31021 */  addu  $v0, $t5, $v1
/* 0D586C 7F0A0D3C 8C4E00E8 */  lw    $t6, 0xe8($v0)
.L7F0A0D40:
/* 0D5870 7F0A0D40 548E0008 */  bnel  $a0, $t6, .L7F0A0D64
/* 0D5874 7F0A0D44 8C590138 */   lw    $t9, 0x138($v0)
/* 0D5878 7F0A0D48 804F00ED */  lb    $t7, 0xed($v0)
/* 0D587C 7F0A0D4C 54AF0005 */  bnel  $a1, $t7, .L7F0A0D64
/* 0D5880 7F0A0D50 8C590138 */   lw    $t9, 0x138($v0)
/* 0D5884 7F0A0D54 A44700A0 */  sh    $a3, 0xa0($v0)
/* 0D5888 7F0A0D58 8CD80000 */  lw    $t8, ($a2)
/* 0D588C 7F0A0D5C 03031021 */  addu  $v0, $t8, $v1
/* 0D5890 7F0A0D60 8C590138 */  lw    $t9, 0x138($v0)
.L7F0A0D64:
/* 0D5894 7F0A0D64 24630140 */  addiu $v1, $v1, 0x140
/* 0D5898 7F0A0D68 14990005 */  bne   $a0, $t9, .L7F0A0D80
/* 0D589C 7F0A0D6C 00000000 */   nop   
/* 0D58A0 7F0A0D70 8049013D */  lb    $t1, 0x13d($v0)
/* 0D58A4 7F0A0D74 14A90002 */  bne   $a1, $t1, .L7F0A0D80
/* 0D58A8 7F0A0D78 00000000 */   nop   
/* 0D58AC 7F0A0D7C A44700F0 */  sh    $a3, 0xf0($v0)
.L7F0A0D80:
/* 0D58B0 7F0A0D80 5468FFDB */  bnel  $v1, $t0, .L7F0A0CF0
/* 0D58B4 7F0A0D84 8CD80000 */   lw    $t8, ($a2)
/* 0D58B8 7F0A0D88 03E00008 */  jr    $ra
/* 0D58BC 7F0A0D8C 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0A0D90(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0A0D90
/* 0D58C0 7F0A0D90 3C078004 */  lui   $a3, %hi(D_8004080C)
/* 0D58C4 7F0A0D94 3C058008 */  lui   $a1, %hi(ptr_bullet_impact_buf)
/* 0D58C8 7F0A0D98 24A5A154 */  addiu $a1, %lo(ptr_bullet_impact_buf) # addiu $a1, $a1, -0x5eac
/* 0D58CC 7F0A0D9C 24E7080C */  addiu $a3, %lo(D_8004080C) # addiu $a3, $a3, 0x80c
/* 0D58D0 7F0A0DA0 00001825 */  move  $v1, $zero
/* 0D58D4 7F0A0DA4 240A1F40 */  li    $t2, 8000
/* 0D58D8 7F0A0DA8 2409FFFF */  li    $t1, -1
/* 0D58DC 7F0A0DAC 2408000C */  li    $t0, 12
/* 0D58E0 7F0A0DB0 24060002 */  li    $a2, 2
/* 0D58E4 7F0A0DB4 8CAE0000 */  lw    $t6, ($a1)
.L7F0A0DB8:
/* 0D58E8 7F0A0DB8 01C31021 */  addu  $v0, $t6, $v1
/* 0D58EC 7F0A0DBC 8C4F0048 */  lw    $t7, 0x48($v0)
/* 0D58F0 7F0A0DC0 548F000C */  bnel  $a0, $t7, .L7F0A0DF4
/* 0D58F4 7F0A0DC4 8C4E0098 */   lw    $t6, 0x98($v0)
/* 0D58F8 7F0A0DC8 84580002 */  lh    $t8, 2($v0)
/* 0D58FC 7F0A0DCC 03080019 */  multu $t8, $t0
/* 0D5900 7F0A0DD0 0000C812 */  mflo  $t9
/* 0D5904 7F0A0DD4 00F95821 */  addu  $t3, $a3, $t9
/* 0D5908 7F0A0DD8 916C0009 */  lbu   $t4, 9($t3)
/* 0D590C 7F0A0DDC 54CC0005 */  bnel  $a2, $t4, .L7F0A0DF4
/* 0D5910 7F0A0DE0 8C4E0098 */   lw    $t6, 0x98($v0)
/* 0D5914 7F0A0DE4 A4490000 */  sh    $t1, ($v0)
/* 0D5918 7F0A0DE8 8CAD0000 */  lw    $t5, ($a1)
/* 0D591C 7F0A0DEC 01A31021 */  addu  $v0, $t5, $v1
/* 0D5920 7F0A0DF0 8C4E0098 */  lw    $t6, 0x98($v0)
.L7F0A0DF4:
/* 0D5924 7F0A0DF4 548E000C */  bnel  $a0, $t6, .L7F0A0E28
/* 0D5928 7F0A0DF8 8C4D00E8 */   lw    $t5, 0xe8($v0)
/* 0D592C 7F0A0DFC 844F0052 */  lh    $t7, 0x52($v0)
/* 0D5930 7F0A0E00 01E80019 */  multu $t7, $t0
/* 0D5934 7F0A0E04 0000C012 */  mflo  $t8
/* 0D5938 7F0A0E08 00F8C821 */  addu  $t9, $a3, $t8
/* 0D593C 7F0A0E0C 932B0009 */  lbu   $t3, 9($t9)
/* 0D5940 7F0A0E10 54CB0005 */  bnel  $a2, $t3, .L7F0A0E28
/* 0D5944 7F0A0E14 8C4D00E8 */   lw    $t5, 0xe8($v0)
/* 0D5948 7F0A0E18 A4490050 */  sh    $t1, 0x50($v0)
/* 0D594C 7F0A0E1C 8CAC0000 */  lw    $t4, ($a1)
/* 0D5950 7F0A0E20 01831021 */  addu  $v0, $t4, $v1
/* 0D5954 7F0A0E24 8C4D00E8 */  lw    $t5, 0xe8($v0)
.L7F0A0E28:
/* 0D5958 7F0A0E28 548D000C */  bnel  $a0, $t5, .L7F0A0E5C
/* 0D595C 7F0A0E2C 8C4C0138 */   lw    $t4, 0x138($v0)
/* 0D5960 7F0A0E30 844E00A2 */  lh    $t6, 0xa2($v0)
/* 0D5964 7F0A0E34 01C80019 */  multu $t6, $t0
/* 0D5968 7F0A0E38 00007812 */  mflo  $t7
/* 0D596C 7F0A0E3C 00EFC021 */  addu  $t8, $a3, $t7
/* 0D5970 7F0A0E40 93190009 */  lbu   $t9, 9($t8)
/* 0D5974 7F0A0E44 54D90005 */  bnel  $a2, $t9, .L7F0A0E5C
/* 0D5978 7F0A0E48 8C4C0138 */   lw    $t4, 0x138($v0)
/* 0D597C 7F0A0E4C A44900A0 */  sh    $t1, 0xa0($v0)
/* 0D5980 7F0A0E50 8CAB0000 */  lw    $t3, ($a1)
/* 0D5984 7F0A0E54 01631021 */  addu  $v0, $t3, $v1
/* 0D5988 7F0A0E58 8C4C0138 */  lw    $t4, 0x138($v0)
.L7F0A0E5C:
/* 0D598C 7F0A0E5C 24630140 */  addiu $v1, $v1, 0x140
/* 0D5990 7F0A0E60 148C0009 */  bne   $a0, $t4, .L7F0A0E88
/* 0D5994 7F0A0E64 00000000 */   nop   
/* 0D5998 7F0A0E68 844D00F2 */  lh    $t5, 0xf2($v0)
/* 0D599C 7F0A0E6C 01A80019 */  multu $t5, $t0
/* 0D59A0 7F0A0E70 00007012 */  mflo  $t6
/* 0D59A4 7F0A0E74 00EE7821 */  addu  $t7, $a3, $t6
/* 0D59A8 7F0A0E78 91F80009 */  lbu   $t8, 9($t7)
/* 0D59AC 7F0A0E7C 14D80002 */  bne   $a2, $t8, .L7F0A0E88
/* 0D59B0 7F0A0E80 00000000 */   nop   
/* 0D59B4 7F0A0E84 A44900F0 */  sh    $t1, 0xf0($v0)
.L7F0A0E88:
/* 0D59B8 7F0A0E88 546AFFCB */  bnel  $v1, $t2, .L7F0A0DB8
/* 0D59BC 7F0A0E8C 8CAE0000 */   lw    $t6, ($a1)
/* 0D59C0 7F0A0E90 03E00008 */  jr    $ra
/* 0D59C4 7F0A0E94 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0A0E98(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0A0E98
/* 0D59C8 7F0A0E98 3C01437F */  li    $at, 0x437F0000 # 255.000000
/* 0D59CC 7F0A0E9C 44811000 */  mtc1  $at, $f2
/* 0D59D0 7F0A0EA0 3C014120 */  li    $at, 0x41200000 # 10.000000
/* 0D59D4 7F0A0EA4 3C068008 */  lui   $a2, %hi(ptr_bullet_impact_buf)
/* 0D59D8 7F0A0EA8 44810000 */  mtc1  $at, $f0
/* 0D59DC 7F0A0EAC 24C6A154 */  addiu $a2, %lo(ptr_bullet_impact_buf) # addiu $a2, $a2, -0x5eac
/* 0D59E0 7F0A0EB0 00001025 */  move  $v0, $zero
/* 0D59E4 7F0A0EB4 2408000A */  li    $t0, 10
/* 0D59E8 7F0A0EB8 24070050 */  li    $a3, 80
/* 0D59EC 7F0A0EBC 44822000 */  mtc1  $v0, $f4
.L7F0A0EC0:
/* 0D59F0 7F0A0EC0 24030001 */  li    $v1, 1
/* 0D59F4 7F0A0EC4 00870019 */  multu $a0, $a3
/* 0D59F8 7F0A0EC8 468021A0 */  cvt.s.w $f6, $f4
/* 0D59FC 7F0A0ECC 3C014F00 */  li    $at, 0x4F000000 # 2147483648.000000
/* 0D5A00 7F0A0ED0 46003203 */  div.s $f8, $f6, $f0
/* 0D5A04 7F0A0ED4 00002812 */  mflo  $a1
/* 0D5A08 7F0A0ED8 46024282 */  mul.s $f10, $f8, $f2
/* 0D5A0C 7F0A0EDC 444EF800 */  cfc1  $t6, $31
/* 0D5A10 7F0A0EE0 44C3F800 */  ctc1  $v1, $31
/* 0D5A14 7F0A0EE4 00000000 */  nop   
/* 0D5A18 7F0A0EE8 46005424 */  cvt.w.s $f16, $f10
/* 0D5A1C 7F0A0EEC 4443F800 */  cfc1  $v1, $31
/* 0D5A20 7F0A0EF0 00000000 */  nop   
/* 0D5A24 7F0A0EF4 30630078 */  andi  $v1, $v1, 0x78
/* 0D5A28 7F0A0EF8 50600013 */  beql  $v1, $zero, .L7F0A0F48
/* 0D5A2C 7F0A0EFC 44038000 */   mfc1  $v1, $f16
/* 0D5A30 7F0A0F00 44818000 */  mtc1  $at, $f16
/* 0D5A34 7F0A0F04 24030001 */  li    $v1, 1
/* 0D5A38 7F0A0F08 46105401 */  sub.s $f16, $f10, $f16
/* 0D5A3C 7F0A0F0C 44C3F800 */  ctc1  $v1, $31
/* 0D5A40 7F0A0F10 00000000 */  nop   
/* 0D5A44 7F0A0F14 46008424 */  cvt.w.s $f16, $f16
/* 0D5A48 7F0A0F18 4443F800 */  cfc1  $v1, $31
/* 0D5A4C 7F0A0F1C 00000000 */  nop   
/* 0D5A50 7F0A0F20 30630078 */  andi  $v1, $v1, 0x78
/* 0D5A54 7F0A0F24 14600005 */  bnez  $v1, .L7F0A0F3C
/* 0D5A58 7F0A0F28 00000000 */   nop   
/* 0D5A5C 7F0A0F2C 44038000 */  mfc1  $v1, $f16
/* 0D5A60 7F0A0F30 3C018000 */  lui   $at, 0x8000
/* 0D5A64 7F0A0F34 10000007 */  b     .L7F0A0F54
/* 0D5A68 7F0A0F38 00611825 */   or    $v1, $v1, $at
.L7F0A0F3C:
/* 0D5A6C 7F0A0F3C 10000005 */  b     .L7F0A0F54
/* 0D5A70 7F0A0F40 2403FFFF */   li    $v1, -1
/* 0D5A74 7F0A0F44 44038000 */  mfc1  $v1, $f16
.L7F0A0F48:
/* 0D5A78 7F0A0F48 00000000 */  nop   
/* 0D5A7C 7F0A0F4C 0460FFFB */  bltz  $v1, .L7F0A0F3C
/* 0D5A80 7F0A0F50 00000000 */   nop   
.L7F0A0F54:
/* 0D5A84 7F0A0F54 8CCF0000 */  lw    $t7, ($a2)
/* 0D5A88 7F0A0F58 44CEF800 */  ctc1  $t6, $31
/* 0D5A8C 7F0A0F5C 244E0001 */  addiu $t6, $v0, 1
/* 0D5A90 7F0A0F60 01E5C021 */  addu  $t8, $t7, $a1
/* 0D5A94 7F0A0F64 A3030047 */  sb    $v1, 0x47($t8)
/* 0D5A98 7F0A0F68 8CD90000 */  lw    $t9, ($a2)
/* 0D5A9C 7F0A0F6C 448E9000 */  mtc1  $t6, $f18
/* 0D5AA0 7F0A0F70 24840001 */  addiu $a0, $a0, 1
/* 0D5AA4 7F0A0F74 03254821 */  addu  $t1, $t9, $a1
/* 0D5AA8 7F0A0F78 A1230037 */  sb    $v1, 0x37($t1)
/* 0D5AAC 7F0A0F7C 8CCA0000 */  lw    $t2, ($a2)
/* 0D5AB0 7F0A0F80 46809120 */  cvt.s.w $f4, $f18
/* 0D5AB4 7F0A0F84 28810064 */  slti  $at, $a0, 0x64
/* 0D5AB8 7F0A0F88 01455821 */  addu  $t3, $t2, $a1
/* 0D5ABC 7F0A0F8C A1630027 */  sb    $v1, 0x27($t3)
/* 0D5AC0 7F0A0F90 8CCC0000 */  lw    $t4, ($a2)
/* 0D5AC4 7F0A0F94 24420002 */  addiu $v0, $v0, 2
/* 0D5AC8 7F0A0F98 46002183 */  div.s $f6, $f4, $f0
/* 0D5ACC 7F0A0F9C 01856821 */  addu  $t5, $t4, $a1
/* 0D5AD0 7F0A0FA0 A1A30017 */  sb    $v1, 0x17($t5)
/* 0D5AD4 7F0A0FA4 14200003 */  bnez  $at, .L7F0A0FB4
/* 0D5AD8 7F0A0FA8 24A50050 */   addiu $a1, $a1, 0x50
/* 0D5ADC 7F0A0FAC 00002025 */  move  $a0, $zero
/* 0D5AE0 7F0A0FB0 00002825 */  move  $a1, $zero
.L7F0A0FB4:
/* 0D5AE4 7F0A0FB4 46023202 */  mul.s $f8, $f6, $f2
/* 0D5AE8 7F0A0FB8 24030001 */  li    $v1, 1
/* 0D5AEC 7F0A0FBC 3C014F00 */  li    $at, 0x4F000000 # 2147483648.000000
/* 0D5AF0 7F0A0FC0 444FF800 */  cfc1  $t7, $31
/* 0D5AF4 7F0A0FC4 44C3F800 */  ctc1  $v1, $31
/* 0D5AF8 7F0A0FC8 00000000 */  nop   
/* 0D5AFC 7F0A0FCC 460042A4 */  cvt.w.s $f10, $f8
/* 0D5B00 7F0A0FD0 4443F800 */  cfc1  $v1, $31
/* 0D5B04 7F0A0FD4 00000000 */  nop   
/* 0D5B08 7F0A0FD8 30630078 */  andi  $v1, $v1, 0x78
/* 0D5B0C 7F0A0FDC 50600013 */  beql  $v1, $zero, .L7F0A102C
/* 0D5B10 7F0A0FE0 44035000 */   mfc1  $v1, $f10
/* 0D5B14 7F0A0FE4 44815000 */  mtc1  $at, $f10
/* 0D5B18 7F0A0FE8 24030001 */  li    $v1, 1
/* 0D5B1C 7F0A0FEC 460A4281 */  sub.s $f10, $f8, $f10
/* 0D5B20 7F0A0FF0 44C3F800 */  ctc1  $v1, $31
/* 0D5B24 7F0A0FF4 00000000 */  nop   
/* 0D5B28 7F0A0FF8 460052A4 */  cvt.w.s $f10, $f10
/* 0D5B2C 7F0A0FFC 4443F800 */  cfc1  $v1, $31
/* 0D5B30 7F0A1000 00000000 */  nop   
/* 0D5B34 7F0A1004 30630078 */  andi  $v1, $v1, 0x78
/* 0D5B38 7F0A1008 14600005 */  bnez  $v1, .L7F0A1020
/* 0D5B3C 7F0A100C 00000000 */   nop   
/* 0D5B40 7F0A1010 44035000 */  mfc1  $v1, $f10
/* 0D5B44 7F0A1014 3C018000 */  lui   $at, 0x8000
/* 0D5B48 7F0A1018 10000007 */  b     .L7F0A1038
/* 0D5B4C 7F0A101C 00611825 */   or    $v1, $v1, $at
.L7F0A1020:
/* 0D5B50 7F0A1020 10000005 */  b     .L7F0A1038
/* 0D5B54 7F0A1024 2403FFFF */   li    $v1, -1
/* 0D5B58 7F0A1028 44035000 */  mfc1  $v1, $f10
.L7F0A102C:
/* 0D5B5C 7F0A102C 00000000 */  nop   
/* 0D5B60 7F0A1030 0460FFFB */  bltz  $v1, .L7F0A1020
/* 0D5B64 7F0A1034 00000000 */   nop   
.L7F0A1038:
/* 0D5B68 7F0A1038 8CD80000 */  lw    $t8, ($a2)
/* 0D5B6C 7F0A103C 24840001 */  addiu $a0, $a0, 1
/* 0D5B70 7F0A1040 28810064 */  slti  $at, $a0, 0x64
/* 0D5B74 7F0A1044 0305C821 */  addu  $t9, $t8, $a1
/* 0D5B78 7F0A1048 A3230047 */  sb    $v1, 0x47($t9)
/* 0D5B7C 7F0A104C 8CC90000 */  lw    $t1, ($a2)
/* 0D5B80 7F0A1050 44CFF800 */  ctc1  $t7, $31
/* 0D5B84 7F0A1054 01255021 */  addu  $t2, $t1, $a1
/* 0D5B88 7F0A1058 A1430037 */  sb    $v1, 0x37($t2)
/* 0D5B8C 7F0A105C 8CCB0000 */  lw    $t3, ($a2)
/* 0D5B90 7F0A1060 01656021 */  addu  $t4, $t3, $a1
/* 0D5B94 7F0A1064 A1830027 */  sb    $v1, 0x27($t4)
/* 0D5B98 7F0A1068 8CCD0000 */  lw    $t5, ($a2)
/* 0D5B9C 7F0A106C 01A57021 */  addu  $t6, $t5, $a1
/* 0D5BA0 7F0A1070 14200002 */  bnez  $at, .L7F0A107C
/* 0D5BA4 7F0A1074 A1C30017 */   sb    $v1, 0x17($t6)
/* 0D5BA8 7F0A1078 00002025 */  move  $a0, $zero
.L7F0A107C:
/* 0D5BAC 7F0A107C 5448FF90 */  bnel  $v0, $t0, .L7F0A0EC0
/* 0D5BB0 7F0A1080 44822000 */   mtc1  $v0, $f4
/* 0D5BB4 7F0A1084 03E00008 */  jr    $ra
/* 0D5BB8 7F0A1088 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0A108C(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0A108C
/* 0D5BBC 7F0A108C 27BDFF10 */  addiu $sp, $sp, -0xf0
/* 0D5BC0 7F0A1090 3C0E8004 */  lui   $t6, %hi(D_80040930) 
/* 0D5BC4 7F0A1094 AFBF0034 */  sw    $ra, 0x34($sp)
/* 0D5BC8 7F0A1098 AFB60030 */  sw    $s6, 0x30($sp)
/* 0D5BCC 7F0A109C AFB5002C */  sw    $s5, 0x2c($sp)
/* 0D5BD0 7F0A10A0 AFB40028 */  sw    $s4, 0x28($sp)
/* 0D5BD4 7F0A10A4 AFB30024 */  sw    $s3, 0x24($sp)
/* 0D5BD8 7F0A10A8 AFB20020 */  sw    $s2, 0x20($sp)
/* 0D5BDC 7F0A10AC AFB1001C */  sw    $s1, 0x1c($sp)
/* 0D5BE0 7F0A10B0 AFB00018 */  sw    $s0, 0x18($sp)
/* 0D5BE4 7F0A10B4 AFA600F8 */  sw    $a2, 0xf8($sp)
/* 0D5BE8 7F0A10B8 AFA700FC */  sw    $a3, 0xfc($sp)
/* 0D5BEC 7F0A10BC 25CE0930 */  addiu $t6, %lo(D_80040930) # addiu $t6, $t6, 0x930
/* 0D5BF0 7F0A10C0 8DC10000 */  lw    $at, ($t6)
/* 0D5BF4 7F0A10C4 27B500E0 */  addiu $s5, $sp, 0xe0
/* 0D5BF8 7F0A10C8 00808825 */  move  $s1, $a0
/* 0D5BFC 7F0A10CC AEA10000 */  sw    $at, ($s5)
/* 0D5C00 7F0A10D0 8DD90004 */  lw    $t9, 4($t6)
/* 0D5C04 7F0A10D4 00A08025 */  move  $s0, $a1
/* 0D5C08 7F0A10D8 2404000F */  li    $a0, 15
/* 0D5C0C 7F0A10DC AEB90004 */  sw    $t9, 4($s5)
/* 0D5C10 7F0A10E0 8DC10008 */  lw    $at, 8($t6)
/* 0D5C14 7F0A10E4 AEA10008 */  sw    $at, 8($s5)
/* 0D5C18 7F0A10E8 8DD9000C */  lw    $t9, 0xc($t6)
/* 0D5C1C 7F0A10EC 0FC249EF */  jal   cheatIsActive
/* 0D5C20 7F0A10F0 AEB9000C */   sw    $t9, 0xc($s5)
/* 0D5C24 7F0A10F4 10400003 */  beqz  $v0, .L7F0A1104
/* 0D5C28 7F0A10F8 3C0A8004 */   lui   $t2, %hi(D_8004080C) 
/* 0D5C2C 7F0A10FC 24080010 */  li    $t0, 16
/* 0D5C30 7F0A1100 A7A800FA */  sh    $t0, 0xfa($sp)
.L7F0A1104:
/* 0D5C34 7F0A1104 C6240000 */  lwc1  $f4, ($s1)
/* 0D5C38 7F0A1108 87B400FA */  lh    $s4, 0xfa($sp)
/* 0D5C3C 7F0A110C 254A080C */  addiu $t2, %lo(D_8004080C) # addiu $t2, $t2, 0x80c
/* 0D5C40 7F0A1110 E7A400A0 */  swc1  $f4, 0xa0($sp)
/* 0D5C44 7F0A1114 C6260004 */  lwc1  $f6, 4($s1)
/* 0D5C48 7F0A1118 00144880 */  sll   $t1, $s4, 2
/* 0D5C4C 7F0A111C 01344823 */  subu  $t1, $t1, $s4
/* 0D5C50 7F0A1120 E7A600A4 */  swc1  $f6, 0xa4($sp)
/* 0D5C54 7F0A1124 C6280008 */  lwc1  $f8, 8($s1)
/* 0D5C58 7F0A1128 0009A080 */  sll   $s4, $t1, 2
/* 0D5C5C 7F0A112C 028A5821 */  addu  $t3, $s4, $t2
/* 0D5C60 7F0A1130 AFAB0050 */  sw    $t3, 0x50($sp)
/* 0D5C64 7F0A1134 E7A800A8 */  swc1  $f8, 0xa8($sp)
/* 0D5C68 7F0A1138 C56A0000 */  lwc1  $f10, ($t3)
/* 0D5C6C 7F0A113C 44808000 */  mtc1  $zero, $f16
/* 0D5C70 7F0A1140 E7AA009C */  swc1  $f10, 0x9c($sp)
/* 0D5C74 7F0A1144 C5640004 */  lwc1  $f4, 4($t3)
/* 0D5C78 7F0A1148 E7A40098 */  swc1  $f4, 0x98($sp)
/* 0D5C7C 7F0A114C C60E0000 */  lwc1  $f14, ($s0)
/* 0D5C80 7F0A1150 460E8032 */  c.eq.s $f16, $f14
/* 0D5C84 7F0A1154 00000000 */  nop   
/* 0D5C88 7F0A1158 4500000E */  bc1f  .L7F0A1194
/* 0D5C8C 7F0A115C 00000000 */   nop   
/* 0D5C90 7F0A1160 C6060008 */  lwc1  $f6, 8($s0)
/* 0D5C94 7F0A1164 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0D5C98 7F0A1168 46068032 */  c.eq.s $f16, $f6
/* 0D5C9C 7F0A116C 00000000 */  nop   
/* 0D5CA0 7F0A1170 45000008 */  bc1f  .L7F0A1194
/* 0D5CA4 7F0A1174 00000000 */   nop   
/* 0D5CA8 7F0A1178 44810000 */  mtc1  $at, $f0
/* 0D5CAC 7F0A117C E7B000B8 */  swc1  $f16, 0xb8($sp)
/* 0D5CB0 7F0A1180 E7B000B4 */  swc1  $f16, 0xb4($sp)
/* 0D5CB4 7F0A1184 E7B000BC */  swc1  $f16, 0xbc($sp)
/* 0D5CB8 7F0A1188 E7A000B0 */  swc1  $f0, 0xb0($sp)
/* 0D5CBC 7F0A118C 10000025 */  b     .L7F0A1224
/* 0D5CC0 7F0A1190 E7A000C4 */   swc1  $f0, 0xc4($sp)
.L7F0A1194:
/* 0D5CC4 7F0A1194 460E7202 */  mul.s $f8, $f14, $f14
/* 0D5CC8 7F0A1198 C6020004 */  lwc1  $f2, 4($s0)
/* 0D5CCC 7F0A119C C6000008 */  lwc1  $f0, 8($s0)
/* 0D5CD0 7F0A11A0 46021282 */  mul.s $f10, $f2, $f2
/* 0D5CD4 7F0A11A4 460A4100 */  add.s $f4, $f8, $f10
/* 0D5CD8 7F0A11A8 46000182 */  mul.s $f6, $f0, $f0
/* 0D5CDC 7F0A11AC 0C007DF8 */  jal   sqrtf
/* 0D5CE0 7F0A11B0 46043300 */   add.s $f12, $f6, $f4
/* 0D5CE4 7F0A11B4 C6080000 */  lwc1  $f8, ($s0)
/* 0D5CE8 7F0A11B8 C6060008 */  lwc1  $f6, 8($s0)
/* 0D5CEC 7F0A11BC C60A0004 */  lwc1  $f10, 4($s0)
/* 0D5CF0 7F0A11C0 46004383 */  div.s $f14, $f8, $f0
/* 0D5CF4 7F0A11C4 46003403 */  div.s $f16, $f6, $f0
/* 0D5CF8 7F0A11C8 E7AE00DC */  swc1  $f14, 0xdc($sp)
/* 0D5CFC 7F0A11CC 460E7102 */  mul.s $f4, $f14, $f14
/* 0D5D00 7F0A11D0 46005483 */  div.s $f18, $f10, $f0
/* 0D5D04 7F0A11D4 E7B000D4 */  swc1  $f16, 0xd4($sp)
/* 0D5D08 7F0A11D8 46108202 */  mul.s $f8, $f16, $f16
/* 0D5D0C 7F0A11DC 46082300 */  add.s $f12, $f4, $f8
/* 0D5D10 7F0A11E0 0C007DF8 */  jal   sqrtf
/* 0D5D14 7F0A11E4 E7B200D8 */   swc1  $f18, 0xd8($sp)
/* 0D5D18 7F0A11E8 C7AE00DC */  lwc1  $f14, 0xdc($sp)
/* 0D5D1C 7F0A11EC C7B000D4 */  lwc1  $f16, 0xd4($sp)
/* 0D5D20 7F0A11F0 C7B200D8 */  lwc1  $f18, 0xd8($sp)
/* 0D5D24 7F0A11F4 46007083 */  div.s $f2, $f14, $f0
/* 0D5D28 7F0A11F8 46000107 */  neg.s $f4, $f0
/* 0D5D2C 7F0A11FC E7A400B4 */  swc1  $f4, 0xb4($sp)
/* 0D5D30 7F0A1200 46008303 */  div.s $f12, $f16, $f0
/* 0D5D34 7F0A1204 44808000 */  mtc1  $zero, $f16
/* 0D5D38 7F0A1208 46029182 */  mul.s $f6, $f18, $f2
/* 0D5D3C 7F0A120C 46001287 */  neg.s $f10, $f2
/* 0D5D40 7F0A1210 E7AA00BC */  swc1  $f10, 0xbc($sp)
/* 0D5D44 7F0A1214 E7A600B8 */  swc1  $f6, 0xb8($sp)
/* 0D5D48 7F0A1218 460C9202 */  mul.s $f8, $f18, $f12
/* 0D5D4C 7F0A121C E7AC00C4 */  swc1  $f12, 0xc4($sp)
/* 0D5D50 7F0A1220 E7A800B0 */  swc1  $f8, 0xb0($sp)
.L7F0A1224:
/* 0D5D54 7F0A1224 8FA20100 */  lw    $v0, 0x100($sp)
/* 0D5D58 7F0A1228 10400044 */  beqz  $v0, .L7F0A133C
/* 0D5D5C 7F0A122C 00000000 */   nop   
/* 0D5D60 7F0A1230 8C500004 */  lw    $s0, 4($v0)
/* 0D5D64 7F0A1234 C7AA00C4 */  lwc1  $f10, 0xc4($sp)
/* 0D5D68 7F0A1238 83AF0107 */  lb    $t7, 0x107($sp)
/* 0D5D6C 7F0A123C 8E0D0014 */  lw    $t5, 0x14($s0)
/* 0D5D70 7F0A1240 C7A600BC */  lwc1  $f6, 0xbc($sp)
/* 0D5D74 7F0A1244 C7A400B8 */  lwc1  $f4, 0xb8($sp)
/* 0D5D78 7F0A1248 8DB8000C */  lw    $t8, 0xc($t5)
/* 0D5D7C 7F0A124C E7AA0078 */  swc1  $f10, 0x78($sp)
/* 0D5D80 7F0A1250 C7A800B4 */  lwc1  $f8, 0xb4($sp)
/* 0D5D84 7F0A1254 C7AA00B0 */  lwc1  $f10, 0xb0($sp)
/* 0D5D88 7F0A1258 000F7180 */  sll   $t6, $t7, 6
/* 0D5D8C 7F0A125C 030E8821 */  addu  $s1, $t8, $t6
/* 0D5D90 7F0A1260 E7B0007C */  swc1  $f16, 0x7c($sp)
/* 0D5D94 7F0A1264 02202025 */  move  $a0, $s1
/* 0D5D98 7F0A1268 27A50078 */  addiu $a1, $sp, 0x78
/* 0D5D9C 7F0A126C E7A60080 */  swc1  $f6, 0x80($sp)
/* 0D5DA0 7F0A1270 E7A4006C */  swc1  $f4, 0x6c($sp)
/* 0D5DA4 7F0A1274 E7A80070 */  swc1  $f8, 0x70($sp)
/* 0D5DA8 7F0A1278 0FC160F6 */  jal   matrix_4x4_rotate_vector_in_place
/* 0D5DAC 7F0A127C E7AA0074 */   swc1  $f10, 0x74($sp)
/* 0D5DB0 7F0A1280 02202025 */  move  $a0, $s1
/* 0D5DB4 7F0A1284 0FC160F6 */  jal   matrix_4x4_rotate_vector_in_place
/* 0D5DB8 7F0A1288 27A5006C */   addiu $a1, $sp, 0x6c
/* 0D5DBC 7F0A128C C7A00078 */  lwc1  $f0, 0x78($sp)
/* 0D5DC0 7F0A1290 C7A2007C */  lwc1  $f2, 0x7c($sp)
/* 0D5DC4 7F0A1294 C7AE0080 */  lwc1  $f14, 0x80($sp)
/* 0D5DC8 7F0A1298 46000182 */  mul.s $f6, $f0, $f0
/* 0D5DCC 7F0A129C 00000000 */  nop   
/* 0D5DD0 7F0A12A0 46021102 */  mul.s $f4, $f2, $f2
/* 0D5DD4 7F0A12A4 46043200 */  add.s $f8, $f6, $f4
/* 0D5DD8 7F0A12A8 460E7282 */  mul.s $f10, $f14, $f14
/* 0D5DDC 7F0A12AC 0C007DF8 */  jal   sqrtf
/* 0D5DE0 7F0A12B0 46085300 */   add.s $f12, $f10, $f8
/* 0D5DE4 7F0A12B4 C7A2006C */  lwc1  $f2, 0x6c($sp)
/* 0D5DE8 7F0A12B8 C7AE0070 */  lwc1  $f14, 0x70($sp)
/* 0D5DEC 7F0A12BC C7B00074 */  lwc1  $f16, 0x74($sp)
/* 0D5DF0 7F0A12C0 46021182 */  mul.s $f6, $f2, $f2
/* 0D5DF4 7F0A12C4 E7A00088 */  swc1  $f0, 0x88($sp)
/* 0D5DF8 7F0A12C8 460E7102 */  mul.s $f4, $f14, $f14
/* 0D5DFC 7F0A12CC 46043280 */  add.s $f10, $f6, $f4
/* 0D5E00 7F0A12D0 46108202 */  mul.s $f8, $f16, $f16
/* 0D5E04 7F0A12D4 0C007DF8 */  jal   sqrtf
/* 0D5E08 7F0A12D8 460A4300 */   add.s $f12, $f8, $f10
/* 0D5E0C 7F0A12DC C7A6009C */  lwc1  $f6, 0x9c($sp)
/* 0D5E10 7F0A12E0 C7A40088 */  lwc1  $f4, 0x88($sp)
/* 0D5E14 7F0A12E4 C7AA0098 */  lwc1  $f10, 0x98($sp)
/* 0D5E18 7F0A12E8 8FB90050 */  lw    $t9, 0x50($sp)
/* 0D5E1C 7F0A12EC 46043203 */  div.s $f8, $f6, $f4
/* 0D5E20 7F0A12F0 46005183 */  div.s $f6, $f10, $f0
/* 0D5E24 7F0A12F4 E7A8009C */  swc1  $f8, 0x9c($sp)
/* 0D5E28 7F0A12F8 E7A60098 */  swc1  $f6, 0x98($sp)
/* 0D5E2C 7F0A12FC 9328000A */  lbu   $t0, 0xa($t9)
/* 0D5E30 7F0A1300 29010002 */  slti  $at, $t0, 2
/* 0D5E34 7F0A1304 5020000A */  beql  $at, $zero, .L7F0A1330
/* 0D5E38 7F0A1308 920C0002 */   lbu   $t4, 2($s0)
/* 0D5E3C 7F0A130C 93290009 */  lbu   $t1, 9($t9)
/* 0D5E40 7F0A1310 24010002 */  li    $at, 2
/* 0D5E44 7F0A1314 55210006 */  bnel  $t1, $at, .L7F0A1330
/* 0D5E48 7F0A1318 920C0002 */   lbu   $t4, 2($s0)
/* 0D5E4C 7F0A131C 920A0002 */  lbu   $t2, 2($s0)
/* 0D5E50 7F0A1320 354B0002 */  ori   $t3, $t2, 2
/* 0D5E54 7F0A1324 10000022 */  b     .L7F0A13B0
/* 0D5E58 7F0A1328 A20B0002 */   sb    $t3, 2($s0)
/* 0D5E5C 7F0A132C 920C0002 */  lbu   $t4, 2($s0)
.L7F0A1330:
/* 0D5E60 7F0A1330 358D0001 */  ori   $t5, $t4, 1
/* 0D5E64 7F0A1334 1000001E */  b     .L7F0A13B0
/* 0D5E68 7F0A1338 A20D0002 */   sb    $t5, 2($s0)
.L7F0A133C:
/* 0D5E6C 7F0A133C 0FC2F285 */  jal   getRoomIndexPOS
/* 0D5E70 7F0A1340 87A400FE */   lh    $a0, 0xfe($sp)
/* 0D5E74 7F0A1344 0FC2D20F */  jal   get_room_data_float1
/* 0D5E78 7F0A1348 00408025 */   move  $s0, $v0
/* 0D5E7C 7F0A134C C7A400A0 */  lwc1  $f4, 0xa0($sp)
/* 0D5E80 7F0A1350 C60A0000 */  lwc1  $f10, ($s0)
/* 0D5E84 7F0A1354 46002202 */  mul.s $f8, $f4, $f0
/* 0D5E88 7F0A1358 460A4181 */  sub.s $f6, $f8, $f10
/* 0D5E8C 7F0A135C 0FC2D20F */  jal   get_room_data_float1
/* 0D5E90 7F0A1360 E7A600A0 */   swc1  $f6, 0xa0($sp)
/* 0D5E94 7F0A1364 C7A400A4 */  lwc1  $f4, 0xa4($sp)
/* 0D5E98 7F0A1368 C60A0004 */  lwc1  $f10, 4($s0)
/* 0D5E9C 7F0A136C 46002202 */  mul.s $f8, $f4, $f0
/* 0D5EA0 7F0A1370 460A4181 */  sub.s $f6, $f8, $f10
/* 0D5EA4 7F0A1374 0FC2D20F */  jal   get_room_data_float1
/* 0D5EA8 7F0A1378 E7A600A4 */   swc1  $f6, 0xa4($sp)
/* 0D5EAC 7F0A137C C7A400A8 */  lwc1  $f4, 0xa8($sp)
/* 0D5EB0 7F0A1380 C60A0008 */  lwc1  $f10, 8($s0)
/* 0D5EB4 7F0A1384 46002202 */  mul.s $f8, $f4, $f0
/* 0D5EB8 7F0A1388 460A4181 */  sub.s $f6, $f8, $f10
/* 0D5EBC 7F0A138C 0FC2D20F */  jal   get_room_data_float1
/* 0D5EC0 7F0A1390 E7A600A8 */   swc1  $f6, 0xa8($sp)
/* 0D5EC4 7F0A1394 C7A4009C */  lwc1  $f4, 0x9c($sp)
/* 0D5EC8 7F0A1398 46002202 */  mul.s $f8, $f4, $f0
/* 0D5ECC 7F0A139C 0FC2D20F */  jal   get_room_data_float1
/* 0D5ED0 7F0A13A0 E7A8009C */   swc1  $f8, 0x9c($sp)
/* 0D5ED4 7F0A13A4 C7AA0098 */  lwc1  $f10, 0x98($sp)
/* 0D5ED8 7F0A13A8 46005182 */  mul.s $f6, $f10, $f0
/* 0D5EDC 7F0A13AC E7A60098 */  swc1  $f6, 0x98($sp)
.L7F0A13B0:
/* 0D5EE0 7F0A13B0 3C128004 */  lui   $s2, %hi(numImpactEntries)
/* 0D5EE4 7F0A13B4 26520808 */  addiu $s2, %lo(numImpactEntries) # addiu $s2, $s2, 0x808
/* 0D5EE8 7F0A13B8 8E4E0000 */  lw    $t6, ($s2)
/* 0D5EEC 7F0A13BC 24160050 */  li    $s6, 80
/* 0D5EF0 7F0A13C0 3C138008 */  lui   $s3, %hi(ptr_bullet_impact_buf)
/* 0D5EF4 7F0A13C4 01D60019 */  multu $t6, $s6
/* 0D5EF8 7F0A13C8 2673A154 */  addiu $s3, %lo(ptr_bullet_impact_buf) # addiu $s3, $s3, -0x5eac
/* 0D5EFC 7F0A13CC 8E780000 */  lw    $t8, ($s3)
/* 0D5F00 7F0A13D0 8FAF0100 */  lw    $t7, 0x100($sp)
/* 0D5F04 7F0A13D4 00004012 */  mflo  $t0
/* 0D5F08 7F0A13D8 0308C821 */  addu  $t9, $t8, $t0
/* 0D5F0C 7F0A13DC AF2F0048 */  sw    $t7, 0x48($t9)
/* 0D5F10 7F0A13E0 8E4B0000 */  lw    $t3, ($s2)
/* 0D5F14 7F0A13E4 8E6A0000 */  lw    $t2, ($s3)
/* 0D5F18 7F0A13E8 83A90107 */  lb    $t1, 0x107($sp)
/* 0D5F1C 7F0A13EC 01760019 */  multu $t3, $s6
/* 0D5F20 7F0A13F0 00006012 */  mflo  $t4
/* 0D5F24 7F0A13F4 014C6821 */  addu  $t5, $t2, $t4
/* 0D5F28 7F0A13F8 A1A9004C */  sb    $t1, 0x4c($t5)
/* 0D5F2C 7F0A13FC 8E480000 */  lw    $t0, ($s2)
/* 0D5F30 7F0A1400 8E780000 */  lw    $t8, ($s3)
/* 0D5F34 7F0A1404 83AE010B */  lb    $t6, 0x10b($sp)
/* 0D5F38 7F0A1408 01160019 */  multu $t0, $s6
/* 0D5F3C 7F0A140C 00007812 */  mflo  $t7
/* 0D5F40 7F0A1410 030FC821 */  addu  $t9, $t8, $t7
/* 0D5F44 7F0A1414 A32E004D */  sb    $t6, 0x4d($t9)
/* 0D5F48 7F0A1418 8E4C0000 */  lw    $t4, ($s2)
/* 0D5F4C 7F0A141C 8E6A0000 */  lw    $t2, ($s3)
/* 0D5F50 7F0A1420 87AB00FE */  lh    $t3, 0xfe($sp)
/* 0D5F54 7F0A1424 01960019 */  multu $t4, $s6
/* 0D5F58 7F0A1428 00004812 */  mflo  $t1
/* 0D5F5C 7F0A142C 01496821 */  addu  $t5, $t2, $t1
/* 0D5F60 7F0A1430 A5AB0000 */  sh    $t3, ($t5)
/* 0D5F64 7F0A1434 8E4F0000 */  lw    $t7, ($s2)
/* 0D5F68 7F0A1438 8E780000 */  lw    $t8, ($s3)
/* 0D5F6C 7F0A143C 87A800FA */  lh    $t0, 0xfa($sp)
/* 0D5F70 7F0A1440 01F60019 */  multu $t7, $s6
/* 0D5F74 7F0A1444 00007012 */  mflo  $t6
/* 0D5F78 7F0A1448 030EC821 */  addu  $t9, $t8, $t6
/* 0D5F7C 7F0A144C A7280002 */  sh    $t0, 2($t9)
/* 0D5F80 7F0A1450 8E4A0000 */  lw    $t2, ($s2)
/* 0D5F84 7F0A1454 8E6C0000 */  lw    $t4, ($s3)
/* 0D5F88 7F0A1458 8EA10000 */  lw    $at, ($s5)
/* 0D5F8C 7F0A145C 01560019 */  multu $t2, $s6
/* 0D5F90 7F0A1460 00004812 */  mflo  $t1
/* 0D5F94 7F0A1464 01895821 */  addu  $t3, $t4, $t1
/* 0D5F98 7F0A1468 AD610008 */  sw    $at, 8($t3)
/* 0D5F9C 7F0A146C 8EAF0004 */  lw    $t7, 4($s5)
/* 0D5FA0 7F0A1470 AD6F000C */  sw    $t7, 0xc($t3)
/* 0D5FA4 7F0A1474 8EA10008 */  lw    $at, 8($s5)
/* 0D5FA8 7F0A1478 AD610010 */  sw    $at, 0x10($t3)
/* 0D5FAC 7F0A147C 8EAF000C */  lw    $t7, 0xc($s5)
/* 0D5FB0 7F0A1480 AD6F0014 */  sw    $t7, 0x14($t3)
/* 0D5FB4 7F0A1484 8E4E0000 */  lw    $t6, ($s2)
/* 0D5FB8 7F0A1488 8E780000 */  lw    $t8, ($s3)
/* 0D5FBC 7F0A148C 8EA10000 */  lw    $at, ($s5)
/* 0D5FC0 7F0A1490 01D60019 */  multu $t6, $s6
/* 0D5FC4 7F0A1494 00004012 */  mflo  $t0
/* 0D5FC8 7F0A1498 0308C821 */  addu  $t9, $t8, $t0
/* 0D5FCC 7F0A149C AF210018 */  sw    $at, 0x18($t9)
/* 0D5FD0 7F0A14A0 8EAC0004 */  lw    $t4, 4($s5)
/* 0D5FD4 7F0A14A4 AF2C001C */  sw    $t4, 0x1c($t9)
/* 0D5FD8 7F0A14A8 8EA10008 */  lw    $at, 8($s5)
/* 0D5FDC 7F0A14AC AF210020 */  sw    $at, 0x20($t9)
/* 0D5FE0 7F0A14B0 8EAC000C */  lw    $t4, 0xc($s5)
/* 0D5FE4 7F0A14B4 AF2C0024 */  sw    $t4, 0x24($t9)
/* 0D5FE8 7F0A14B8 8E4D0000 */  lw    $t5, ($s2)
/* 0D5FEC 7F0A14BC 8E690000 */  lw    $t1, ($s3)
/* 0D5FF0 7F0A14C0 8EA10000 */  lw    $at, ($s5)
/* 0D5FF4 7F0A14C4 01B60019 */  multu $t5, $s6
/* 0D5FF8 7F0A14C8 00005812 */  mflo  $t3
/* 0D5FFC 7F0A14CC 012B7821 */  addu  $t7, $t1, $t3
/* 0D6000 7F0A14D0 ADE10028 */  sw    $at, 0x28($t7)
/* 0D6004 7F0A14D4 8EB80004 */  lw    $t8, 4($s5)
/* 0D6008 7F0A14D8 ADF8002C */  sw    $t8, 0x2c($t7)
/* 0D600C 7F0A14DC 8EA10008 */  lw    $at, 8($s5)
/* 0D6010 7F0A14E0 ADE10030 */  sw    $at, 0x30($t7)
/* 0D6014 7F0A14E4 8EB8000C */  lw    $t8, 0xc($s5)
/* 0D6018 7F0A14E8 ADF80034 */  sw    $t8, 0x34($t7)
/* 0D601C 7F0A14EC 8E4A0000 */  lw    $t2, ($s2)
/* 0D6020 7F0A14F0 8E680000 */  lw    $t0, ($s3)
/* 0D6024 7F0A14F4 8EA10000 */  lw    $at, ($s5)
/* 0D6028 7F0A14F8 01560019 */  multu $t2, $s6
/* 0D602C 7F0A14FC 0000C812 */  mflo  $t9
/* 0D6030 7F0A1500 01196021 */  addu  $t4, $t0, $t9
/* 0D6034 7F0A1504 AD810038 */  sw    $at, 0x38($t4)
/* 0D6038 7F0A1508 8EA90004 */  lw    $t1, 4($s5)
/* 0D603C 7F0A150C AD89003C */  sw    $t1, 0x3c($t4)
/* 0D6040 7F0A1510 8EA10008 */  lw    $at, 8($s5)
/* 0D6044 7F0A1514 AD810040 */  sw    $at, 0x40($t4)
/* 0D6048 7F0A1518 8EA9000C */  lw    $t1, 0xc($s5)
/* 0D604C 7F0A151C AD890044 */  sw    $t1, 0x44($t4)
/* 0D6050 7F0A1520 C7A800C4 */  lwc1  $f8, 0xc4($sp)
/* 0D6054 7F0A1524 C7A4009C */  lwc1  $f4, 0x9c($sp)
/* 0D6058 7F0A1528 C7A600B8 */  lwc1  $f6, 0xb8($sp)
/* 0D605C 7F0A152C C7AA0098 */  lwc1  $f10, 0x98($sp)
/* 0D6060 7F0A1530 46082002 */  mul.s $f0, $f4, $f8
/* 0D6064 7F0A1534 C7A400A0 */  lwc1  $f4, 0xa0($sp)
/* 0D6068 7F0A1538 46065082 */  mul.s $f2, $f10, $f6
/* 0D606C 7F0A153C E7A0004C */  swc1  $f0, 0x4c($sp)
/* 0D6070 7F0A1540 46002201 */  sub.s $f8, $f4, $f0
/* 0D6074 7F0A1544 E7A20048 */  swc1  $f2, 0x48($sp)
/* 0D6078 7F0A1548 0FC2831D */  jal   sub_GAME_7F0A0C74
/* 0D607C 7F0A154C 46024301 */   sub.s $f12, $f8, $f2
/* 0D6080 7F0A1550 8E4E0000 */  lw    $t6, ($s2)
/* 0D6084 7F0A1554 8E6B0000 */  lw    $t3, ($s3)
/* 0D6088 7F0A1558 44804000 */  mtc1  $zero, $f8
/* 0D608C 7F0A155C 01D60019 */  multu $t6, $s6
/* 0D6090 7F0A1560 00007812 */  mflo  $t7
/* 0D6094 7F0A1564 016FC021 */  addu  $t8, $t3, $t7
/* 0D6098 7F0A1568 A7020008 */  sh    $v0, 8($t8)
/* 0D609C 7F0A156C C7A600B4 */  lwc1  $f6, 0xb4($sp)
/* 0D60A0 7F0A1570 C7AA0098 */  lwc1  $f10, 0x98($sp)
/* 0D60A4 7F0A1574 C7A400A4 */  lwc1  $f4, 0xa4($sp)
/* 0D60A8 7F0A1578 46065002 */  mul.s $f0, $f10, $f6
/* 0D60AC 7F0A157C 46082281 */  sub.s $f10, $f4, $f8
/* 0D60B0 7F0A1580 46005301 */  sub.s $f12, $f10, $f0
/* 0D60B4 7F0A1584 0FC2831D */  jal   sub_GAME_7F0A0C74
/* 0D60B8 7F0A1588 E7A00044 */   swc1  $f0, 0x44($sp)
/* 0D60BC 7F0A158C 8E480000 */  lw    $t0, ($s2)
/* 0D60C0 7F0A1590 8E6A0000 */  lw    $t2, ($s3)
/* 0D60C4 7F0A1594 01160019 */  multu $t0, $s6
/* 0D60C8 7F0A1598 0000C812 */  mflo  $t9
/* 0D60CC 7F0A159C 01596821 */  addu  $t5, $t2, $t9
/* 0D60D0 7F0A15A0 A5A2000A */  sh    $v0, 0xa($t5)
/* 0D60D4 7F0A15A4 C7A400BC */  lwc1  $f4, 0xbc($sp)
/* 0D60D8 7F0A15A8 C7A6009C */  lwc1  $f6, 0x9c($sp)
/* 0D60DC 7F0A15AC C7AA00B0 */  lwc1  $f10, 0xb0($sp)
/* 0D60E0 7F0A15B0 C7A80098 */  lwc1  $f8, 0x98($sp)
/* 0D60E4 7F0A15B4 46043002 */  mul.s $f0, $f6, $f4
/* 0D60E8 7F0A15B8 C7A600A8 */  lwc1  $f6, 0xa8($sp)
/* 0D60EC 7F0A15BC 460A4082 */  mul.s $f2, $f8, $f10
/* 0D60F0 7F0A15C0 E7A00040 */  swc1  $f0, 0x40($sp)
/* 0D60F4 7F0A15C4 46003101 */  sub.s $f4, $f6, $f0
/* 0D60F8 7F0A15C8 E7A2003C */  swc1  $f2, 0x3c($sp)
/* 0D60FC 7F0A15CC 0FC2831D */  jal   sub_GAME_7F0A0C74
/* 0D6100 7F0A15D0 46022301 */   sub.s $f12, $f4, $f2
/* 0D6104 7F0A15D4 8E490000 */  lw    $t1, ($s2)
/* 0D6108 7F0A15D8 8E6C0000 */  lw    $t4, ($s3)
/* 0D610C 7F0A15DC 3C108009 */  lui   $s0, %hi(impactimages)
/* 0D6110 7F0A15E0 01360019 */  multu $t1, $s6
/* 0D6114 7F0A15E4 2610D0BC */  addiu $s0, %lo(impactimages) # addiu $s0, $s0, -0x2f44
/* 0D6118 7F0A15E8 00007012 */  mflo  $t6
/* 0D611C 7F0A15EC 018E5821 */  addu  $t3, $t4, $t6
/* 0D6120 7F0A15F0 A562000C */  sh    $v0, 0xc($t3)
/* 0D6124 7F0A15F4 8E580000 */  lw    $t8, ($s2)
/* 0D6128 7F0A15F8 8E6F0000 */  lw    $t7, ($s3)
/* 0D612C 7F0A15FC 03160019 */  multu $t8, $s6
/* 0D6130 7F0A1600 00004012 */  mflo  $t0
/* 0D6134 7F0A1604 01E85021 */  addu  $t2, $t7, $t0
/* 0D6138 7F0A1608 A5400010 */  sh    $zero, 0x10($t2)
/* 0D613C 7F0A160C 8E4B0000 */  lw    $t3, ($s2)
/* 0D6140 7F0A1610 8E190000 */  lw    $t9, ($s0)
/* 0D6144 7F0A1614 8E6E0000 */  lw    $t6, ($s3)
/* 0D6148 7F0A1618 01760019 */  multu $t3, $s6
/* 0D614C 7F0A161C 03346821 */  addu  $t5, $t9, $s4
/* 0D6150 7F0A1620 91A90005 */  lbu   $t1, 5($t5)
/* 0D6154 7F0A1624 00096140 */  sll   $t4, $t1, 5
/* 0D6158 7F0A1628 0000C012 */  mflo  $t8
/* 0D615C 7F0A162C 01D87821 */  addu  $t7, $t6, $t8
/* 0D6160 7F0A1630 A5EC0012 */  sh    $t4, 0x12($t7)
/* 0D6164 7F0A1634 C7AA004C */  lwc1  $f10, 0x4c($sp)
/* 0D6168 7F0A1638 C7A800A0 */  lwc1  $f8, 0xa0($sp)
/* 0D616C 7F0A163C C7A40048 */  lwc1  $f4, 0x48($sp)
/* 0D6170 7F0A1640 460A4181 */  sub.s $f6, $f8, $f10
/* 0D6174 7F0A1644 0FC2831D */  jal   sub_GAME_7F0A0C74
/* 0D6178 7F0A1648 46043300 */   add.s $f12, $f6, $f4
/* 0D617C 7F0A164C 8E4A0000 */  lw    $t2, ($s2)
/* 0D6180 7F0A1650 8E680000 */  lw    $t0, ($s3)
/* 0D6184 7F0A1654 44805000 */  mtc1  $zero, $f10
/* 0D6188 7F0A1658 01560019 */  multu $t2, $s6
/* 0D618C 7F0A165C 0000C812 */  mflo  $t9
/* 0D6190 7F0A1660 01196821 */  addu  $t5, $t0, $t9
/* 0D6194 7F0A1664 A5A20018 */  sh    $v0, 0x18($t5)
/* 0D6198 7F0A1668 C7A800A4 */  lwc1  $f8, 0xa4($sp)
/* 0D619C 7F0A166C C7A40044 */  lwc1  $f4, 0x44($sp)
/* 0D61A0 7F0A1670 460A4181 */  sub.s $f6, $f8, $f10
/* 0D61A4 7F0A1674 0FC2831D */  jal   sub_GAME_7F0A0C74
/* 0D61A8 7F0A1678 46043300 */   add.s $f12, $f6, $f4
/* 0D61AC 7F0A167C 8E4B0000 */  lw    $t3, ($s2)
/* 0D61B0 7F0A1680 8E690000 */  lw    $t1, ($s3)
/* 0D61B4 7F0A1684 01760019 */  multu $t3, $s6
/* 0D61B8 7F0A1688 00007012 */  mflo  $t6
/* 0D61BC 7F0A168C 012EC021 */  addu  $t8, $t1, $t6
/* 0D61C0 7F0A1690 A702001A */  sh    $v0, 0x1a($t8)
/* 0D61C4 7F0A1694 C7AA0040 */  lwc1  $f10, 0x40($sp)
/* 0D61C8 7F0A1698 C7A800A8 */  lwc1  $f8, 0xa8($sp)
/* 0D61CC 7F0A169C C7A4003C */  lwc1  $f4, 0x3c($sp)
/* 0D61D0 7F0A16A0 460A4181 */  sub.s $f6, $f8, $f10
/* 0D61D4 7F0A16A4 0FC2831D */  jal   sub_GAME_7F0A0C74
/* 0D61D8 7F0A16A8 46043300 */   add.s $f12, $f6, $f4
/* 0D61DC 7F0A16AC 8E4F0000 */  lw    $t7, ($s2)
/* 0D61E0 7F0A16B0 8E6C0000 */  lw    $t4, ($s3)
/* 0D61E4 7F0A16B4 01F60019 */  multu $t7, $s6
/* 0D61E8 7F0A16B8 00005012 */  mflo  $t2
/* 0D61EC 7F0A16BC 018A4021 */  addu  $t0, $t4, $t2
/* 0D61F0 7F0A16C0 A502001C */  sh    $v0, 0x1c($t0)
/* 0D61F4 7F0A16C4 8E4D0000 */  lw    $t5, ($s2)
/* 0D61F8 7F0A16C8 8E790000 */  lw    $t9, ($s3)
/* 0D61FC 7F0A16CC 01B60019 */  multu $t5, $s6
/* 0D6200 7F0A16D0 00005812 */  mflo  $t3
/* 0D6204 7F0A16D4 032B4821 */  addu  $t1, $t9, $t3
/* 0D6208 7F0A16D8 A5200020 */  sh    $zero, 0x20($t1)
/* 0D620C 7F0A16DC 8E580000 */  lw    $t8, ($s2)
/* 0D6210 7F0A16E0 8E6E0000 */  lw    $t6, ($s3)
/* 0D6214 7F0A16E4 03160019 */  multu $t8, $s6
/* 0D6218 7F0A16E8 00007812 */  mflo  $t7
/* 0D621C 7F0A16EC 01CF6021 */  addu  $t4, $t6, $t7
/* 0D6220 7F0A16F0 A5800022 */  sh    $zero, 0x22($t4)
/* 0D6224 7F0A16F4 C7AA004C */  lwc1  $f10, 0x4c($sp)
/* 0D6228 7F0A16F8 C7A800A0 */  lwc1  $f8, 0xa0($sp)
/* 0D622C 7F0A16FC C7A40048 */  lwc1  $f4, 0x48($sp)
/* 0D6230 7F0A1700 460A4180 */  add.s $f6, $f8, $f10
/* 0D6234 7F0A1704 0FC2831D */  jal   sub_GAME_7F0A0C74
/* 0D6238 7F0A1708 46043300 */   add.s $f12, $f6, $f4
/* 0D623C 7F0A170C 8E480000 */  lw    $t0, ($s2)
/* 0D6240 7F0A1710 8E6A0000 */  lw    $t2, ($s3)
/* 0D6244 7F0A1714 44805000 */  mtc1  $zero, $f10
/* 0D6248 7F0A1718 01160019 */  multu $t0, $s6
/* 0D624C 7F0A171C 00006812 */  mflo  $t5
/* 0D6250 7F0A1720 014DC821 */  addu  $t9, $t2, $t5
/* 0D6254 7F0A1724 A7220028 */  sh    $v0, 0x28($t9)
/* 0D6258 7F0A1728 C7A800A4 */  lwc1  $f8, 0xa4($sp)
/* 0D625C 7F0A172C C7A40044 */  lwc1  $f4, 0x44($sp)
/* 0D6260 7F0A1730 460A4180 */  add.s $f6, $f8, $f10
/* 0D6264 7F0A1734 0FC2831D */  jal   sub_GAME_7F0A0C74
/* 0D6268 7F0A1738 46043300 */   add.s $f12, $f6, $f4
/* 0D626C 7F0A173C 8E490000 */  lw    $t1, ($s2)
/* 0D6270 7F0A1740 8E6B0000 */  lw    $t3, ($s3)
/* 0D6274 7F0A1744 01360019 */  multu $t1, $s6
/* 0D6278 7F0A1748 0000C012 */  mflo  $t8
/* 0D627C 7F0A174C 01787021 */  addu  $t6, $t3, $t8
/* 0D6280 7F0A1750 A5C2002A */  sh    $v0, 0x2a($t6)
/* 0D6284 7F0A1754 C7AA0040 */  lwc1  $f10, 0x40($sp)
/* 0D6288 7F0A1758 C7A800A8 */  lwc1  $f8, 0xa8($sp)
/* 0D628C 7F0A175C C7A4003C */  lwc1  $f4, 0x3c($sp)
/* 0D6290 7F0A1760 460A4180 */  add.s $f6, $f8, $f10
/* 0D6294 7F0A1764 0FC2831D */  jal   sub_GAME_7F0A0C74
/* 0D6298 7F0A1768 46043300 */   add.s $f12, $f6, $f4
/* 0D629C 7F0A176C 8E4C0000 */  lw    $t4, ($s2)
/* 0D62A0 7F0A1770 8E6F0000 */  lw    $t7, ($s3)
/* 0D62A4 7F0A1774 01960019 */  multu $t4, $s6
/* 0D62A8 7F0A1778 00004012 */  mflo  $t0
/* 0D62AC 7F0A177C 01E85021 */  addu  $t2, $t7, $t0
/* 0D62B0 7F0A1780 A542002C */  sh    $v0, 0x2c($t2)
/* 0D62B4 7F0A1784 8E4E0000 */  lw    $t6, ($s2)
/* 0D62B8 7F0A1788 8E0D0000 */  lw    $t5, ($s0)
/* 0D62BC 7F0A178C 8E780000 */  lw    $t8, ($s3)
/* 0D62C0 7F0A1790 01D60019 */  multu $t6, $s6
/* 0D62C4 7F0A1794 01B4C821 */  addu  $t9, $t5, $s4
/* 0D62C8 7F0A1798 93290004 */  lbu   $t1, 4($t9)
/* 0D62CC 7F0A179C 00095940 */  sll   $t3, $t1, 5
/* 0D62D0 7F0A17A0 00006012 */  mflo  $t4
/* 0D62D4 7F0A17A4 030C7821 */  addu  $t7, $t8, $t4
/* 0D62D8 7F0A17A8 A5EB0030 */  sh    $t3, 0x30($t7)
/* 0D62DC 7F0A17AC 8E4A0000 */  lw    $t2, ($s2)
/* 0D62E0 7F0A17B0 8E680000 */  lw    $t0, ($s3)
/* 0D62E4 7F0A17B4 01560019 */  multu $t2, $s6
/* 0D62E8 7F0A17B8 00006812 */  mflo  $t5
/* 0D62EC 7F0A17BC 010DC821 */  addu  $t9, $t0, $t5
/* 0D62F0 7F0A17C0 A7200032 */  sh    $zero, 0x32($t9)
/* 0D62F4 7F0A17C4 C7AA004C */  lwc1  $f10, 0x4c($sp)
/* 0D62F8 7F0A17C8 C7A800A0 */  lwc1  $f8, 0xa0($sp)
/* 0D62FC 7F0A17CC C7A40048 */  lwc1  $f4, 0x48($sp)
/* 0D6300 7F0A17D0 460A4180 */  add.s $f6, $f8, $f10
/* 0D6304 7F0A17D4 0FC2831D */  jal   sub_GAME_7F0A0C74
/* 0D6308 7F0A17D8 46043301 */   sub.s $f12, $f6, $f4
/* 0D630C 7F0A17DC 8E4E0000 */  lw    $t6, ($s2)
/* 0D6310 7F0A17E0 8E690000 */  lw    $t1, ($s3)
/* 0D6314 7F0A17E4 44805000 */  mtc1  $zero, $f10
/* 0D6318 7F0A17E8 01D60019 */  multu $t6, $s6
/* 0D631C 7F0A17EC 0000C012 */  mflo  $t8
/* 0D6320 7F0A17F0 01386021 */  addu  $t4, $t1, $t8
/* 0D6324 7F0A17F4 A5820038 */  sh    $v0, 0x38($t4)
/* 0D6328 7F0A17F8 C7A800A4 */  lwc1  $f8, 0xa4($sp)
/* 0D632C 7F0A17FC C7A40044 */  lwc1  $f4, 0x44($sp)
/* 0D6330 7F0A1800 460A4180 */  add.s $f6, $f8, $f10
/* 0D6334 7F0A1804 0FC2831D */  jal   sub_GAME_7F0A0C74
/* 0D6338 7F0A1808 46043301 */   sub.s $f12, $f6, $f4
/* 0D633C 7F0A180C 8E4F0000 */  lw    $t7, ($s2)
/* 0D6340 7F0A1810 8E6B0000 */  lw    $t3, ($s3)
/* 0D6344 7F0A1814 01F60019 */  multu $t7, $s6
/* 0D6348 7F0A1818 00005012 */  mflo  $t2
/* 0D634C 7F0A181C 016A4021 */  addu  $t0, $t3, $t2
/* 0D6350 7F0A1820 A502003A */  sh    $v0, 0x3a($t0)
/* 0D6354 7F0A1824 C7AA0040 */  lwc1  $f10, 0x40($sp)
/* 0D6358 7F0A1828 C7A800A8 */  lwc1  $f8, 0xa8($sp)
/* 0D635C 7F0A182C C7A4003C */  lwc1  $f4, 0x3c($sp)
/* 0D6360 7F0A1830 460A4180 */  add.s $f6, $f8, $f10
/* 0D6364 7F0A1834 0FC2831D */  jal   sub_GAME_7F0A0C74
/* 0D6368 7F0A1838 46043301 */   sub.s $f12, $f6, $f4
/* 0D636C 7F0A183C 8E590000 */  lw    $t9, ($s2)
/* 0D6370 7F0A1840 8E6D0000 */  lw    $t5, ($s3)
/* 0D6374 7F0A1844 00008825 */  move  $s1, $zero
/* 0D6378 7F0A1848 03360019 */  multu $t9, $s6
/* 0D637C 7F0A184C 24150028 */  li    $s5, 40
/* 0D6380 7F0A1850 00007012 */  mflo  $t6
/* 0D6384 7F0A1854 01AE4821 */  addu  $t1, $t5, $t6
/* 0D6388 7F0A1858 A522003C */  sh    $v0, 0x3c($t1)
/* 0D638C 7F0A185C 8E480000 */  lw    $t0, ($s2)
/* 0D6390 7F0A1860 8E180000 */  lw    $t8, ($s0)
/* 0D6394 7F0A1864 8E6A0000 */  lw    $t2, ($s3)
/* 0D6398 7F0A1868 01160019 */  multu $t0, $s6
/* 0D639C 7F0A186C 03146021 */  addu  $t4, $t8, $s4
/* 0D63A0 7F0A1870 918F0004 */  lbu   $t7, 4($t4)
/* 0D63A4 7F0A1874 000F5940 */  sll   $t3, $t7, 5
/* 0D63A8 7F0A1878 0000C812 */  mflo  $t9
/* 0D63AC 7F0A187C 01596821 */  addu  $t5, $t2, $t9
/* 0D63B0 7F0A1880 A5AB0040 */  sh    $t3, 0x40($t5)
/* 0D63B4 7F0A1884 8E480000 */  lw    $t0, ($s2)
/* 0D63B8 7F0A1888 8E0E0000 */  lw    $t6, ($s0)
/* 0D63BC 7F0A188C 8E6F0000 */  lw    $t7, ($s3)
/* 0D63C0 7F0A1890 01160019 */  multu $t0, $s6
/* 0D63C4 7F0A1894 01D44821 */  addu  $t1, $t6, $s4
/* 0D63C8 7F0A1898 91380005 */  lbu   $t8, 5($t1)
/* 0D63CC 7F0A189C 241400FF */  li    $s4, 255
/* 0D63D0 7F0A18A0 00186140 */  sll   $t4, $t8, 5
/* 0D63D4 7F0A18A4 00005012 */  mflo  $t2
/* 0D63D8 7F0A18A8 01EAC821 */  addu  $t9, $t7, $t2
/* 0D63DC 7F0A18AC A72C0042 */  sh    $t4, 0x42($t9)
/* 0D63E0 7F0A18B0 93A40061 */  lbu   $a0, 0x61($sp)
/* 0D63E4 7F0A18B4 93A50062 */  lbu   $a1, 0x62($sp)
.L7F0A18B8:
/* 0D63E8 7F0A18B8 8FAB0050 */  lw    $t3, 0x50($sp)
/* 0D63EC 7F0A18BC 24010001 */  li    $at, 1
/* 0D63F0 7F0A18C0 91620008 */  lbu   $v0, 8($t3)
/* 0D63F4 7F0A18C4 10400013 */  beqz  $v0, .L7F0A1914
/* 0D63F8 7F0A18C8 00000000 */   nop   
/* 0D63FC 7F0A18CC 10410005 */  beq   $v0, $at, .L7F0A18E4
/* 0D6400 7F0A18D0 24010002 */   li    $at, 2
/* 0D6404 7F0A18D4 1041001A */  beq   $v0, $at, .L7F0A1940
/* 0D6408 7F0A18D8 00000000 */   nop   
/* 0D640C 7F0A18DC 1000002E */  b     .L7F0A1998
/* 0D6410 7F0A18E0 00008025 */   move  $s0, $zero
.L7F0A18E4:
/* 0D6414 7F0A18E4 0C002914 */  jal   randomGetNext
/* 0D6418 7F0A18E8 00000000 */   nop   
/* 0D641C 7F0A18EC 0055001B */  divu  $zero, $v0, $s5
/* 0D6420 7F0A18F0 00006810 */  mfhi  $t5
/* 0D6424 7F0A18F4 028D1823 */  subu  $v1, $s4, $t5
/* 0D6428 7F0A18F8 16A00002 */  bnez  $s5, .L7F0A1904
/* 0D642C 7F0A18FC 00000000 */   nop   
/* 0D6430 7F0A1900 0007000D */  break 7
.L7F0A1904:
/* 0D6434 7F0A1904 306400FF */  andi  $a0, $v1, 0xff
/* 0D6438 7F0A1908 306500FF */  andi  $a1, $v1, 0xff
/* 0D643C 7F0A190C 10000022 */  b     .L7F0A1998
/* 0D6440 7F0A1910 307000FF */   andi  $s0, $v1, 0xff
.L7F0A1914:
/* 0D6444 7F0A1914 0C002914 */  jal   randomGetNext
/* 0D6448 7F0A1918 00000000 */   nop   
/* 0D644C 7F0A191C 0055001B */  divu  $zero, $v0, $s5
/* 0D6450 7F0A1920 00001810 */  mfhi  $v1
/* 0D6454 7F0A1924 306400FF */  andi  $a0, $v1, 0xff
/* 0D6458 7F0A1928 16A00002 */  bnez  $s5, .L7F0A1934
/* 0D645C 7F0A192C 00000000 */   nop   
/* 0D6460 7F0A1930 0007000D */  break 7
.L7F0A1934:
/* 0D6464 7F0A1934 306500FF */  andi  $a1, $v1, 0xff
/* 0D6468 7F0A1938 10000017 */  b     .L7F0A1998
/* 0D646C 7F0A193C 307000FF */   andi  $s0, $v1, 0xff
.L7F0A1940:
/* 0D6470 7F0A1940 0C002914 */  jal   randomGetNext
/* 0D6474 7F0A1944 00000000 */   nop   
/* 0D6478 7F0A1948 304E0001 */  andi  $t6, $v0, 1
/* 0D647C 7F0A194C 11C00003 */  beqz  $t6, .L7F0A195C
/* 0D6480 7F0A1950 00008025 */   move  $s0, $zero
/* 0D6484 7F0A1954 10000001 */  b     .L7F0A195C
/* 0D6488 7F0A1958 329000FF */   andi  $s0, $s4, 0xff
.L7F0A195C:
/* 0D648C 7F0A195C 0C002914 */  jal   randomGetNext
/* 0D6490 7F0A1960 00000000 */   nop   
/* 0D6494 7F0A1964 30490001 */  andi  $t1, $v0, 1
/* 0D6498 7F0A1968 11200003 */  beqz  $t1, .L7F0A1978
/* 0D649C 7F0A196C 00002825 */   move  $a1, $zero
/* 0D64A0 7F0A1970 10000001 */  b     .L7F0A1978
/* 0D64A4 7F0A1974 328500FF */   andi  $a1, $s4, 0xff
.L7F0A1978:
/* 0D64A8 7F0A1978 0C002914 */  jal   randomGetNext
/* 0D64AC 7F0A197C A3A50062 */   sb    $a1, 0x62($sp)
/* 0D64B0 7F0A1980 30580001 */  andi  $t8, $v0, 1
/* 0D64B4 7F0A1984 13000003 */  beqz  $t8, .L7F0A1994
/* 0D64B8 7F0A1988 93A50062 */   lbu   $a1, 0x62($sp)
/* 0D64BC 7F0A198C 10000002 */  b     .L7F0A1998
/* 0D64C0 7F0A1990 328400FF */   andi  $a0, $s4, 0xff
.L7F0A1994:
/* 0D64C4 7F0A1994 00002025 */  move  $a0, $zero
.L7F0A1998:
/* 0D64C8 7F0A1998 8E4F0000 */  lw    $t7, ($s2)
/* 0D64CC 7F0A199C 8E680000 */  lw    $t0, ($s3)
/* 0D64D0 7F0A19A0 24010040 */  li    $at, 64
/* 0D64D4 7F0A19A4 000F5080 */  sll   $t2, $t7, 2
/* 0D64D8 7F0A19A8 014F5021 */  addu  $t2, $t2, $t7
/* 0D64DC 7F0A19AC 000A5100 */  sll   $t2, $t2, 4
/* 0D64E0 7F0A19B0 010A6021 */  addu  $t4, $t0, $t2
/* 0D64E4 7F0A19B4 0191C821 */  addu  $t9, $t4, $s1
/* 0D64E8 7F0A19B8 A3300014 */  sb    $s0, 0x14($t9)
/* 0D64EC 7F0A19BC 8E4D0000 */  lw    $t5, ($s2)
/* 0D64F0 7F0A19C0 8E6B0000 */  lw    $t3, ($s3)
/* 0D64F4 7F0A19C4 000D7080 */  sll   $t6, $t5, 2
/* 0D64F8 7F0A19C8 01CD7021 */  addu  $t6, $t6, $t5
/* 0D64FC 7F0A19CC 000E7100 */  sll   $t6, $t6, 4
/* 0D6500 7F0A19D0 016E4821 */  addu  $t1, $t3, $t6
/* 0D6504 7F0A19D4 0131C021 */  addu  $t8, $t1, $s1
/* 0D6508 7F0A19D8 A3050015 */  sb    $a1, 0x15($t8)
/* 0D650C 7F0A19DC 8E480000 */  lw    $t0, ($s2)
/* 0D6510 7F0A19E0 8E6F0000 */  lw    $t7, ($s3)
/* 0D6514 7F0A19E4 00085080 */  sll   $t2, $t0, 2
/* 0D6518 7F0A19E8 01485021 */  addu  $t2, $t2, $t0
/* 0D651C 7F0A19EC 000A5100 */  sll   $t2, $t2, 4
/* 0D6520 7F0A19F0 01EA6021 */  addu  $t4, $t7, $t2
/* 0D6524 7F0A19F4 0191C821 */  addu  $t9, $t4, $s1
/* 0D6528 7F0A19F8 A3240016 */  sb    $a0, 0x16($t9)
/* 0D652C 7F0A19FC 8E4B0000 */  lw    $t3, ($s2)
/* 0D6530 7F0A1A00 8E6D0000 */  lw    $t5, ($s3)
/* 0D6534 7F0A1A04 000B7080 */  sll   $t6, $t3, 2
/* 0D6538 7F0A1A08 01CB7021 */  addu  $t6, $t6, $t3
/* 0D653C 7F0A1A0C 000E7100 */  sll   $t6, $t6, 4
/* 0D6540 7F0A1A10 01AE4821 */  addu  $t1, $t5, $t6
/* 0D6544 7F0A1A14 0131C021 */  addu  $t8, $t1, $s1
/* 0D6548 7F0A1A18 26310010 */  addiu $s1, $s1, 0x10
/* 0D654C 7F0A1A1C 1621FFA6 */  bne   $s1, $at, .L7F0A18B8
/* 0D6550 7F0A1A20 A3140017 */   sb    $s4, 0x17($t8)
/* 0D6554 7F0A1A24 8E480000 */  lw    $t0, ($s2)
/* 0D6558 7F0A1A28 A3A40061 */  sb    $a0, 0x61($sp)
/* 0D655C 7F0A1A2C A3A50062 */  sb    $a1, 0x62($sp)
/* 0D6560 7F0A1A30 25040001 */  addiu $a0, $t0, 1
/* 0D6564 7F0A1A34 28810064 */  slti  $at, $a0, 0x64
/* 0D6568 7F0A1A38 14200003 */  bnez  $at, .L7F0A1A48
/* 0D656C 7F0A1A3C AE440000 */   sw    $a0, ($s2)
/* 0D6570 7F0A1A40 AE400000 */  sw    $zero, ($s2)
/* 0D6574 7F0A1A44 00002025 */  move  $a0, $zero
.L7F0A1A48:
/* 0D6578 7F0A1A48 0FC283A6 */  jal   sub_GAME_7F0A0E98
/* 0D657C 7F0A1A4C 00000000 */   nop   
/* 0D6580 7F0A1A50 8E590000 */  lw    $t9, ($s2)
/* 0D6584 7F0A1A54 8E6C0000 */  lw    $t4, ($s3)
/* 0D6588 7F0A1A58 240AFFFF */  li    $t2, -1
/* 0D658C 7F0A1A5C 03360019 */  multu $t9, $s6
/* 0D6590 7F0A1A60 00005812 */  mflo  $t3
/* 0D6594 7F0A1A64 018B6821 */  addu  $t5, $t4, $t3
/* 0D6598 7F0A1A68 A5AA0000 */  sh    $t2, ($t5)
/* 0D659C 7F0A1A6C 8FBF0034 */  lw    $ra, 0x34($sp)
/* 0D65A0 7F0A1A70 8FB60030 */  lw    $s6, 0x30($sp)
/* 0D65A4 7F0A1A74 8FB5002C */  lw    $s5, 0x2c($sp)
/* 0D65A8 7F0A1A78 8FB40028 */  lw    $s4, 0x28($sp)
/* 0D65AC 7F0A1A7C 8FB30024 */  lw    $s3, 0x24($sp)
/* 0D65B0 7F0A1A80 8FB20020 */  lw    $s2, 0x20($sp)
/* 0D65B4 7F0A1A84 8FB1001C */  lw    $s1, 0x1c($sp)
/* 0D65B8 7F0A1A88 8FB00018 */  lw    $s0, 0x18($sp)
/* 0D65BC 7F0A1A8C 03E00008 */  jr    $ra
/* 0D65C0 7F0A1A90 27BD00F0 */   addiu $sp, $sp, 0xf0
)
#endif





#ifdef NONMATCHING
void explosionRenderBulletImpactOnProp(void) {

}
#else
GLOBAL_ASM(
.text
glabel explosionRenderBulletImpactOnProp
/* 0D65C4 7F0A1A94 27BDFFA0 */  addiu $sp, $sp, -0x60
/* 0D65C8 7F0A1A98 AFB60038 */  sw    $s6, 0x38($sp)
/* 0D65CC 7F0A1A9C AFB50034 */  sw    $s5, 0x34($sp)
/* 0D65D0 7F0A1AA0 240EFFFF */  li    $t6, -1
/* 0D65D4 7F0A1AA4 00A0B025 */  move  $s6, $a1
/* 0D65D8 7F0A1AA8 AFBF0044 */  sw    $ra, 0x44($sp)
/* 0D65DC 7F0A1AAC AFBE0040 */  sw    $fp, 0x40($sp)
/* 0D65E0 7F0A1AB0 AFB7003C */  sw    $s7, 0x3c($sp)
/* 0D65E4 7F0A1AB4 AFB40030 */  sw    $s4, 0x30($sp)
/* 0D65E8 7F0A1AB8 AFB3002C */  sw    $s3, 0x2c($sp)
/* 0D65EC 7F0A1ABC AFB20028 */  sw    $s2, 0x28($sp)
/* 0D65F0 7F0A1AC0 AFB10024 */  sw    $s1, 0x24($sp)
/* 0D65F4 7F0A1AC4 AFB00020 */  sw    $s0, 0x20($sp)
/* 0D65F8 7F0A1AC8 AFA40060 */  sw    $a0, 0x60($sp)
/* 0D65FC 7F0A1ACC AFA60068 */  sw    $a2, 0x68($sp)
/* 0D6600 7F0A1AD0 2415FFFF */  li    $s5, -1
/* 0D6604 7F0A1AD4 AFA00050 */  sw    $zero, 0x50($sp)
/* 0D6608 7F0A1AD8 AFA0004C */  sw    $zero, 0x4c($sp)
/* 0D660C 7F0A1ADC 10A00003 */  beqz  $a1, .L7F0A1AEC
/* 0D6610 7F0A1AE0 AFAE0048 */   sw    $t6, 0x48($sp)
/* 0D6614 7F0A1AE4 8CAF0004 */  lw    $t7, 4($a1)
/* 0D6618 7F0A1AE8 AFAF004C */  sw    $t7, 0x4c($sp)
.L7F0A1AEC:
/* 0D661C 7F0A1AEC 8FB80060 */  lw    $t8, 0x60($sp)
/* 0D6620 7F0A1AF0 3C08B600 */  lui   $t0, 0xb600
/* 0D6624 7F0A1AF4 24093000 */  li    $t1, 12288
/* 0D6628 7F0A1AF8 27190008 */  addiu $t9, $t8, 8
/* 0D662C 7F0A1AFC AFB90060 */  sw    $t9, 0x60($sp)
/* 0D6630 7F0A1B00 AF090004 */  sw    $t1, 4($t8)
/* 0D6634 7F0A1B04 AF080000 */  sw    $t0, ($t8)
/* 0D6638 7F0A1B08 8FAA0060 */  lw    $t2, 0x60($sp)
/* 0D663C 7F0A1B0C 3C0CBA00 */  lui   $t4, (0xBA000602 >> 16) # lui $t4, 0xba00
/* 0D6640 7F0A1B10 358C0602 */  ori   $t4, (0xBA000602 & 0xFFFF) # ori $t4, $t4, 0x602
/* 0D6644 7F0A1B14 254B0008 */  addiu $t3, $t2, 8
/* 0D6648 7F0A1B18 AFAB0060 */  sw    $t3, 0x60($sp)
/* 0D664C 7F0A1B1C 240D0080 */  li    $t5, 128
/* 0D6650 7F0A1B20 3C1E8004 */  lui   $fp, %hi(D_8004080C) 
/* 0D6654 7F0A1B24 3C178008 */  lui   $s7, %hi(ptr_bullet_impact_buf) 
/* 0D6658 7F0A1B28 26F7A154 */  addiu $s7, %lo(ptr_bullet_impact_buf) # addiu $s7, $s7, -0x5eac
/* 0D665C 7F0A1B2C 27DE080C */  addiu $fp, %lo(D_8004080C) # addiu $fp, $fp, 0x80c
/* 0D6660 7F0A1B30 0000A025 */  move  $s4, $zero
/* 0D6664 7F0A1B34 AD4D0004 */  sw    $t5, 4($t2)
/* 0D6668 7F0A1B38 AD4C0000 */  sw    $t4, ($t2)
/* 0D666C 7F0A1B3C 8EEE0000 */  lw    $t6, ($s7)
.L7F0A1B40:
/* 0D6670 7F0A1B40 01D41821 */  addu  $v1, $t6, $s4
/* 0D6674 7F0A1B44 8C6F0048 */  lw    $t7, 0x48($v1)
/* 0D6678 7F0A1B48 56CF0068 */  bnel  $s6, $t7, .L7F0A1CEC
/* 0D667C 7F0A1B4C 26940050 */   addiu $s4, $s4, 0x50
/* 0D6680 7F0A1B50 84650000 */  lh    $a1, ($v1)
/* 0D6684 7F0A1B54 04A20065 */  bltzl $a1, .L7F0A1CEC
/* 0D6688 7F0A1B58 26940050 */   addiu $s4, $s4, 0x50
/* 0D668C 7F0A1B5C 56C00008 */  bnezl $s6, .L7F0A1B80
/* 0D6690 7F0A1B60 8FB90068 */   lw    $t9, 0x68($sp)
/* 0D6694 7F0A1B64 0FC2D794 */  jal   getROOMID_Bitflags
/* 0D6698 7F0A1B68 00A02025 */   move  $a0, $a1
/* 0D669C 7F0A1B6C 5040005F */  beql  $v0, $zero, .L7F0A1CEC
/* 0D66A0 7F0A1B70 26940050 */   addiu $s4, $s4, 0x50
/* 0D66A4 7F0A1B74 8EF80000 */  lw    $t8, ($s7)
/* 0D66A8 7F0A1B78 03141821 */  addu  $v1, $t8, $s4
/* 0D66AC 7F0A1B7C 8FB90068 */  lw    $t9, 0x68($sp)
.L7F0A1B80:
/* 0D66B0 7F0A1B80 84730002 */  lh    $s3, 2($v1)
/* 0D66B4 7F0A1B84 240C0001 */  li    $t4, 1
/* 0D66B8 7F0A1B88 1320000D */  beqz  $t9, .L7F0A1BC0
/* 0D66BC 7F0A1B8C 00139080 */   sll   $s2, $s3, 2
/* 0D66C0 7F0A1B90 00139080 */  sll   $s2, $s3, 2
/* 0D66C4 7F0A1B94 02539023 */  subu  $s2, $s2, $s3
/* 0D66C8 7F0A1B98 00129080 */  sll   $s2, $s2, 2
/* 0D66CC 7F0A1B9C 03D28021 */  addu  $s0, $fp, $s2
/* 0D66D0 7F0A1BA0 9202000A */  lbu   $v0, 0xa($s0)
/* 0D66D4 7F0A1BA4 28480002 */  slti  $t0, $v0, 2
/* 0D66D8 7F0A1BA8 11000010 */  beqz  $t0, .L7F0A1BEC
/* 0D66DC 7F0A1BAC 01001025 */   move  $v0, $t0
/* 0D66E0 7F0A1BB0 92020009 */  lbu   $v0, 9($s0)
/* 0D66E4 7F0A1BB4 38490002 */  xori  $t1, $v0, 2
/* 0D66E8 7F0A1BB8 1000000C */  b     .L7F0A1BEC
/* 0D66EC 7F0A1BBC 2D220001 */   sltiu $v0, $t1, 1
.L7F0A1BC0:
/* 0D66F0 7F0A1BC0 02539023 */  subu  $s2, $s2, $s3
/* 0D66F4 7F0A1BC4 00129080 */  sll   $s2, $s2, 2
/* 0D66F8 7F0A1BC8 03D28021 */  addu  $s0, $fp, $s2
/* 0D66FC 7F0A1BCC 9202000A */  lbu   $v0, 0xa($s0)
/* 0D6700 7F0A1BD0 284A0002 */  slti  $t2, $v0, 2
/* 0D6704 7F0A1BD4 39420001 */  xori  $v0, $t2, 1
/* 0D6708 7F0A1BD8 14400004 */  bnez  $v0, .L7F0A1BEC
/* 0D670C 7F0A1BDC 00000000 */   nop   
/* 0D6710 7F0A1BE0 92020009 */  lbu   $v0, 9($s0)
/* 0D6714 7F0A1BE4 384B0002 */  xori  $t3, $v0, 2
/* 0D6718 7F0A1BE8 000B102B */  sltu  $v0, $zero, $t3
.L7F0A1BEC:
/* 0D671C 7F0A1BEC 5040003F */  beql  $v0, $zero, .L7F0A1CEC
/* 0D6720 7F0A1BF0 26940050 */   addiu $s4, $s4, 0x50
/* 0D6724 7F0A1BF4 12C00014 */  beqz  $s6, .L7F0A1C48
/* 0D6728 7F0A1BF8 AFAC0050 */   sw    $t4, 0x50($sp)
/* 0D672C 7F0A1BFC 8062004C */  lb    $v0, 0x4c($v1)
/* 0D6730 7F0A1C00 8FAE004C */  lw    $t6, 0x4c($sp)
/* 0D6734 7F0A1C04 8FB10060 */  lw    $s1, 0x60($sp)
/* 0D6738 7F0A1C08 12A20018 */  beq   $s5, $v0, .L7F0A1C6C
/* 0D673C 7F0A1C0C 00026980 */   sll   $t5, $v0, 6
/* 0D6740 7F0A1C10 8DCF0014 */  lw    $t7, 0x14($t6)
/* 0D6744 7F0A1C14 0002AC00 */  sll   $s5, $v0, 0x10
/* 0D6748 7F0A1C18 26290008 */  addiu $t1, $s1, 8
/* 0D674C 7F0A1C1C 8DF8000C */  lw    $t8, 0xc($t7)
/* 0D6750 7F0A1C20 3C0A0102 */  lui   $t2, (0x01020040 >> 16) # lui $t2, 0x102
/* 0D6754 7F0A1C24 0015CC03 */  sra   $t9, $s5, 0x10
/* 0D6758 7F0A1C28 354A0040 */  ori   $t2, (0x01020040 & 0xFFFF) # ori $t2, $t2, 0x40
/* 0D675C 7F0A1C2C AFA90060 */  sw    $t1, 0x60($sp)
/* 0D6760 7F0A1C30 0320A825 */  move  $s5, $t9
/* 0D6764 7F0A1C34 AE2A0000 */  sw    $t2, ($s1)
/* 0D6768 7F0A1C38 0C003A2C */  jal   osVirtualToPhysical
/* 0D676C 7F0A1C3C 01B82021 */   addu  $a0, $t5, $t8
/* 0D6770 7F0A1C40 1000000A */  b     .L7F0A1C6C
/* 0D6774 7F0A1C44 AE220004 */   sw    $v0, 4($s1)
.L7F0A1C48:
/* 0D6778 7F0A1C48 84650000 */  lh    $a1, ($v1)
/* 0D677C 7F0A1C4C 8FA40060 */  lw    $a0, 0x60($sp)
/* 0D6780 7F0A1C50 52A50007 */  beql  $s5, $a1, .L7F0A1C70
/* 0D6784 7F0A1C54 8FAC0048 */   lw    $t4, 0x48($sp)
/* 0D6788 7F0A1C58 0005AC00 */  sll   $s5, $a1, 0x10
/* 0D678C 7F0A1C5C 00155C03 */  sra   $t3, $s5, 0x10
/* 0D6790 7F0A1C60 0FC2F271 */  jal   sub_GAME_7F0BC9C4
/* 0D6794 7F0A1C64 0160A825 */   move  $s5, $t3
/* 0D6798 7F0A1C68 AFA20060 */  sw    $v0, 0x60($sp)
.L7F0A1C6C:
/* 0D679C 7F0A1C6C 8FAC0048 */  lw    $t4, 0x48($sp)
.L7F0A1C70:
/* 0D67A0 7F0A1C70 27A40060 */  addiu $a0, $sp, 0x60
/* 0D67A4 7F0A1C74 3C0E8009 */  lui   $t6, %hi(impactimages) 
/* 0D67A8 7F0A1C78 11930008 */  beq   $t4, $s3, .L7F0A1C9C
/* 0D67AC 7F0A1C7C 240F0002 */   li    $t7, 2
/* 0D67B0 7F0A1C80 8DCED0BC */  lw    $t6, %lo(impactimages)($t6)
/* 0D67B4 7F0A1C84 92060009 */  lbu   $a2, 9($s0)
/* 0D67B8 7F0A1C88 9207000A */  lbu   $a3, 0xa($s0)
/* 0D67BC 7F0A1C8C AFAF0010 */  sw    $t7, 0x10($sp)
/* 0D67C0 7F0A1C90 0FC1DB5A */  jal   likely_generate_DL_for_image_declaration
/* 0D67C4 7F0A1C94 024E2821 */   addu  $a1, $s2, $t6
/* 0D67C8 7F0A1C98 AFB30048 */  sw    $s3, 0x48($sp)
.L7F0A1C9C:
/* 0D67CC 7F0A1C9C 8FB00060 */  lw    $s0, 0x60($sp)
/* 0D67D0 7F0A1CA0 3C190430 */  lui   $t9, (0x04300040 >> 16) # lui $t9, 0x430
/* 0D67D4 7F0A1CA4 37390040 */  ori   $t9, (0x04300040 & 0xFFFF) # ori $t9, $t9, 0x40
/* 0D67D8 7F0A1CA8 26180008 */  addiu $t8, $s0, 8
/* 0D67DC 7F0A1CAC AFB80060 */  sw    $t8, 0x60($sp)
/* 0D67E0 7F0A1CB0 AE190000 */  sw    $t9, ($s0)
/* 0D67E4 7F0A1CB4 8EE80000 */  lw    $t0, ($s7)
/* 0D67E8 7F0A1CB8 01142021 */  addu  $a0, $t0, $s4
/* 0D67EC 7F0A1CBC 0C003A2C */  jal   osVirtualToPhysical
/* 0D67F0 7F0A1CC0 24840008 */   addiu $a0, $a0, 8
/* 0D67F4 7F0A1CC4 AE020004 */  sw    $v0, 4($s0)
/* 0D67F8 7F0A1CC8 8FA90060 */  lw    $t1, 0x60($sp)
/* 0D67FC 7F0A1CCC 3C0BB100 */  lui   $t3, (0xB1000032 >> 16) # lui $t3, 0xb100
/* 0D6800 7F0A1CD0 356B0032 */  ori   $t3, (0xB1000032 & 0xFFFF) # ori $t3, $t3, 0x32
/* 0D6804 7F0A1CD4 252A0008 */  addiu $t2, $t1, 8
/* 0D6808 7F0A1CD8 AFAA0060 */  sw    $t2, 0x60($sp)
/* 0D680C 7F0A1CDC 240C2010 */  li    $t4, 8208
/* 0D6810 7F0A1CE0 AD2C0004 */  sw    $t4, 4($t1)
/* 0D6814 7F0A1CE4 AD2B0000 */  sw    $t3, ($t1)
/* 0D6818 7F0A1CE8 26940050 */  addiu $s4, $s4, 0x50
.L7F0A1CEC:
/* 0D681C 7F0A1CEC 24011F40 */  li    $at, 8000
/* 0D6820 7F0A1CF0 5681FF93 */  bnel  $s4, $at, .L7F0A1B40
/* 0D6824 7F0A1CF4 8EEE0000 */   lw    $t6, ($s7)
/* 0D6828 7F0A1CF8 12C0000A */  beqz  $s6, .L7F0A1D24
/* 0D682C 7F0A1CFC 8FAE0050 */   lw    $t6, 0x50($sp)
/* 0D6830 7F0A1D00 15C00008 */  bnez  $t6, .L7F0A1D24
/* 0D6834 7F0A1D04 8FAF004C */   lw    $t7, 0x4c($sp)
/* 0D6838 7F0A1D08 8FB80068 */  lw    $t8, 0x68($sp)
/* 0D683C 7F0A1D0C 91ED0002 */  lbu   $t5, 2($t7)
/* 0D6840 7F0A1D10 24190001 */  li    $t9, 1
/* 0D6844 7F0A1D14 03194004 */  sllv  $t0, $t9, $t8
/* 0D6848 7F0A1D18 01004827 */  not   $t1, $t0
/* 0D684C 7F0A1D1C 01A95024 */  and   $t2, $t5, $t1
/* 0D6850 7F0A1D20 A1EA0002 */  sb    $t2, 2($t7)
.L7F0A1D24:
/* 0D6854 7F0A1D24 8FAB0060 */  lw    $t3, 0x60($sp)
/* 0D6858 7F0A1D28 3C0EBA00 */  lui   $t6, (0xBA000602 >> 16) # lui $t6, 0xba00
/* 0D685C 7F0A1D2C 35CE0602 */  ori   $t6, (0xBA000602 & 0xFFFF) # ori $t6, $t6, 0x602
/* 0D6860 7F0A1D30 256C0008 */  addiu $t4, $t3, 8
/* 0D6864 7F0A1D34 AFAC0060 */  sw    $t4, 0x60($sp)
/* 0D6868 7F0A1D38 24190040 */  li    $t9, 64
/* 0D686C 7F0A1D3C AD790004 */  sw    $t9, 4($t3)
/* 0D6870 7F0A1D40 AD6E0000 */  sw    $t6, ($t3)
/* 0D6874 7F0A1D44 8FBF0044 */  lw    $ra, 0x44($sp)
/* 0D6878 7F0A1D48 8FBE0040 */  lw    $fp, 0x40($sp)
/* 0D687C 7F0A1D4C 8FB7003C */  lw    $s7, 0x3c($sp)
/* 0D6880 7F0A1D50 8FB60038 */  lw    $s6, 0x38($sp)
/* 0D6884 7F0A1D54 8FB50034 */  lw    $s5, 0x34($sp)
/* 0D6888 7F0A1D58 8FB40030 */  lw    $s4, 0x30($sp)
/* 0D688C 7F0A1D5C 8FB3002C */  lw    $s3, 0x2c($sp)
/* 0D6890 7F0A1D60 8FB20028 */  lw    $s2, 0x28($sp)
/* 0D6894 7F0A1D64 8FB10024 */  lw    $s1, 0x24($sp)
/* 0D6898 7F0A1D68 8FB00020 */  lw    $s0, 0x20($sp)
/* 0D689C 7F0A1D6C 8FA20060 */  lw    $v0, 0x60($sp)
/* 0D68A0 7F0A1D70 03E00008 */  jr    $ra
/* 0D68A4 7F0A1D74 27BD0060 */   addiu $sp, $sp, 0x60
)
#endif






Gfx * sub_GAME_7F0A1D78(Gfx *arg0)
{
    return explosionRenderBulletImpactOnProp(arg0, NULL, 0);
}


