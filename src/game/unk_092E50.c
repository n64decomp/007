#include <ultra64.h>
#include "unk_092E50.h"

// bss
//CODE.bss:80079E80
f32 flt_CODE_bss_80079E80;
//CODE.bss:80079E84
f32 flt_CODE_bss_80079E84;
//CODE.bss:80079E88
f32 flt_CODE_bss_80079E88;


// data
//D:8003FCC0
Gfx MipMap2C_Something_Setup[] = {
    gsDPSetTile(G_IM_FMT_I, G_IM_SIZ_4b, 4, 0, 0, 0, G_TX_WRAP, 6, 0, G_TX_WRAP, 6, 0),
    gsDPSetTile(G_IM_FMT_I, G_IM_SIZ_4b, 4, 0, 1, 0, G_TX_WRAP, 6, 0, G_TX_WRAP, 6, 0),
    gsDPSetTileSize(0, 2, 2, 0, 0),
    gsDPSetTileSize(1, 2, 2, 0, 0),
    gsDPSetPrimColor(0, 15, 255, 255, 255, 255),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTextureFilter(G_TF_BILERP),
    gsDPSetCombineLERP(TEXEL1, TEXEL0, PRIM_LOD_FRAC, TEXEL0,  TEXEL1, TEXEL0, PRIM_LOD_FRAC, TEXEL0,  COMBINED, 0, SHADE, 0,  COMBINED, 0, SHADE, 0),
    gsDPSetRenderMode(G_RM_PASS, G_RM_AA_ZB_OPA_SURF2),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPSetCycleType(G_CYC_2CYCLE),
    gsSPSetGeometryMode(G_CULL_BACK ),
    gsSPEndDisplayList()
};

//D:8003FD28
Gfx MipMap2C_Something2_Setup[] = {
    gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_8b, 2, 0, 0, 0, G_TX_WRAP, 5, 0, G_TX_WRAP, 5, 0),
    gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_8b, 2, 0, 1, 0, G_TX_WRAP, 5, 0, G_TX_WRAP, 5, 0),
    gsDPSetTileSize(0, 2, 2, 0, 0),
    gsDPSetTileSize(1, 2, 2, 0, 0),
    gsDPSetPrimColor(0, 15, 255, 255, 255, 255),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTextureFilter(G_TF_BILERP),
    gsDPSetCombineLERP(TEXEL1, TEXEL0, PRIM_LOD_FRAC, TEXEL0,  TEXEL1, TEXEL0, PRIM_LOD_FRAC, TEXEL0,  COMBINED, 0, SHADE, 0,  COMBINED, 0, SHADE, 0),
    gsDPSetRenderMode(G_RM_PASS, G_RM_AA_ZB_OPA_SURF2),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPSetCycleType(G_CYC_2CYCLE),
    gsSPSetGeometryMode(G_CULL_BACK ),
    gsSPEndDisplayList()
};

//End Dl means this gfx list cannot go any further. perhaps below is a vtx array?

u32 D_8003FD90 = 0;
f32 D_8003FD94[] = {0, 0, 0};
u32 D_8003FDA0 = 0;
u32 D_8003FDA4 = 0xFFFFFFFF;
//D:D_8003FDA8

u64 D_8003FDA8[] = {
              0x100,                 0,                 0,                 0,
                  0,                 0,                 0,                 0,
                  0,                 0,                 0,                 0,
                  0,                 0,        0x3F800000,                 0,
                  0,0x3F80000000000000,                 0,        0x3F800000,
                  0,                 0,0x3F80000000000000,                 0,
                  0,        0xBF800000,        0x3F800000,                 0,
#if defined(BUGFIX_R2)
                  0,                 0,0xc18600da00000000,0x418600da00000000,
#else
                  0,                 0,0xC19FFFFE00000000,0x419FFFFE00000000,
#endif
                  0,                 0,                 0,                 0,
                  0,                 0,                 0,0xBF80000000000000,
         0xBF800000,                 0,0xBF80000000000000,        0xBF800000,
         0x3F800000,                 0,0x3F80000000000000,        0x3F800000,
                  0,0x3F80000000000000,                 0,0x3F8000003F800000,
                  0,                 0,                 0,                 0,
                  0,0x447A000000000000,                 0,        0xFF000000,
                  0,                 0,                 0,                 0,
                  0,                 0,                 0,                 0,
                  0,                 0,                 0,                 0,
                  0,                 0,                 0,                 0,
                  0,                 0,                 0,                 0,
                  0,                 0,                 0,                 0,
                  0,                 0,                 0,                 0,
                  0,                 0,                 0,                 0,
                  0,                 0,                 0,                 0,
                  0,                 0,                 0,                 0,
                  0,                 0,                 0,                 0,
                  0,                 0,                 0,                 0,
                  0,                 0,                 0,                 0,
                  0,                 0,                 0,                 0,
                  0,                 0,                 0
};
//#endif
// rodata



#ifdef NONMATCHING
void sub_GAME_7F092E50(void) {

}
#else
#ifndef VERSION_EU
GLOBAL_ASM(
.late_rodata
glabel D_80057510
.word 0x3dcccccd /*0.1*/
glabel D_80057514
.word 0x40c90fd0 /*6.2831802*/
glabel D_80057518
.word 0x3d23d70a /*0.039999999*/
.text
glabel sub_GAME_7F092E50
/* 0C7980 7F092E50 3C0E8005 */  lui   $t6, %hi(g_ClockTimer) 
/* 0C7984 7F092E54 8DCE8374 */  lw    $t6, %lo(g_ClockTimer)($t6)
/* 0C7988 7F092E58 3C014380 */  li    $at, 0x43800000 # 256.000000
/* 0C798C 7F092E5C 44810000 */  mtc1  $at, $f0
/* 0C7990 7F092E60 448E2000 */  mtc1  $t6, $f4
/* 0C7994 7F092E64 3C013E80 */  li    $at, 0x3E800000 # 0.250000
/* 0C7998 7F092E68 44814000 */  mtc1  $at, $f8
/* 0C799C 7F092E6C 46802420 */  cvt.s.w $f16, $f4
/* 0C79A0 7F092E70 3C088008 */  lui   $t0, %hi(flt_CODE_bss_80079E80) 
/* 0C79A4 7F092E74 25089E80 */  addiu $t0, %lo(flt_CODE_bss_80079E80) # addiu $t0, $t0, -0x6180
/* 0C79A8 7F092E78 C5060000 */  lwc1  $f6, ($t0)
/* 0C79AC 7F092E7C 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0C79B0 7F092E80 44809000 */  mtc1  $zero, $f18
/* 0C79B4 7F092E84 46088282 */  mul.s $f10, $f16, $f8
/* 0C79B8 7F092E88 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0C79BC 7F092E8C 3C018005 */  lui   $at, %hi(D_80057510)
/* 0C79C0 7F092E90 24180001 */  li    $t8, 1
/* 0C79C4 7F092E94 460A3100 */  add.s $f4, $f6, $f10
/* 0C79C8 7F092E98 E5040000 */  swc1  $f4, ($t0)
/* 0C79CC 7F092E9C C50E0000 */  lwc1  $f14, ($t0)
/* 0C79D0 7F092EA0 460E003E */  c.le.s $f0, $f14
/* 0C79D4 7F092EA4 00000000 */  nop   
/* 0C79D8 7F092EA8 45020005 */  bc1fl .L7F092EC0
/* 0C79DC 7F092EAC 4612703C */   c.lt.s $f14, $f18
/* 0C79E0 7F092EB0 46007201 */  sub.s $f8, $f14, $f0
/* 0C79E4 7F092EB4 E5080000 */  swc1  $f8, ($t0)
/* 0C79E8 7F092EB8 C50E0000 */  lwc1  $f14, ($t0)
/* 0C79EC 7F092EBC 4612703C */  c.lt.s $f14, $f18
.L7F092EC0:
/* 0C79F0 7F092EC0 00000000 */  nop   
/* 0C79F4 7F092EC4 45000004 */  bc1f  .L7F092ED8
/* 0C79F8 7F092EC8 00000000 */   nop   
/* 0C79FC 7F092ECC 46007180 */  add.s $f6, $f14, $f0
/* 0C7A00 7F092ED0 E5060000 */  swc1  $f6, ($t0)
/* 0C7A04 7F092ED4 C50E0000 */  lwc1  $f14, ($t0)
.L7F092ED8:
/* 0C7A08 7F092ED8 C4247510 */  lwc1  $f4, %lo(D_80057510)($at)
/* 0C7A0C 7F092EDC 3C078008 */  lui   $a3, %hi(flt_CODE_bss_80079E84)
/* 0C7A10 7F092EE0 24E79E84 */  addiu $a3, %lo(flt_CODE_bss_80079E84) # addiu $a3, $a3, -0x617c
/* 0C7A14 7F092EE4 46048202 */  mul.s $f8, $f16, $f4
/* 0C7A18 7F092EE8 C4EA0000 */  lwc1  $f10, ($a3)
/* 0C7A1C 7F092EEC 3C018005 */  lui   $at, %hi(D_80057514)
/* 0C7A20 7F092EF0 46085180 */  add.s $f6, $f10, $f8
/* 0C7A24 7F092EF4 E4E60000 */  swc1  $f6, ($a3)
/* 0C7A28 7F092EF8 C4E20000 */  lwc1  $f2, ($a3)
/* 0C7A2C 7F092EFC 4602003E */  c.le.s $f0, $f2
/* 0C7A30 7F092F00 00000000 */  nop   
/* 0C7A34 7F092F04 45020005 */  bc1fl .L7F092F1C
/* 0C7A38 7F092F08 4612103C */   c.lt.s $f2, $f18
/* 0C7A3C 7F092F0C 46001101 */  sub.s $f4, $f2, $f0
/* 0C7A40 7F092F10 E4E40000 */  swc1  $f4, ($a3)
/* 0C7A44 7F092F14 C4E20000 */  lwc1  $f2, ($a3)
/* 0C7A48 7F092F18 4612103C */  c.lt.s $f2, $f18
.L7F092F1C:
/* 0C7A4C 7F092F1C 00000000 */  nop   
/* 0C7A50 7F092F20 45000004 */  bc1f  .L7F092F34
/* 0C7A54 7F092F24 00000000 */   nop   
/* 0C7A58 7F092F28 46001280 */  add.s $f10, $f2, $f0
/* 0C7A5C 7F092F2C E4EA0000 */  swc1  $f10, ($a3)
/* 0C7A60 7F092F30 C4E20000 */  lwc1  $f2, ($a3)
.L7F092F34:
/* 0C7A64 7F092F34 C4207514 */  lwc1  $f0, %lo(D_80057514)($at)
/* 0C7A68 7F092F38 3C018005 */  lui   $at, %hi(D_80057518)
/* 0C7A6C 7F092F3C C4267518 */  lwc1  $f6, %lo(D_80057518)($at)
/* 0C7A70 7F092F40 3C068008 */  lui   $a2, %hi(flt_CODE_bss_80079E88)
/* 0C7A74 7F092F44 24C69E88 */  addiu $a2, %lo(flt_CODE_bss_80079E88) # addiu $a2, $a2, -0x6178
/* 0C7A78 7F092F48 46068102 */  mul.s $f4, $f16, $f6
/* 0C7A7C 7F092F4C C4C80000 */  lwc1  $f8, ($a2)
/* 0C7A80 7F092F50 46044280 */  add.s $f10, $f8, $f4
/* 0C7A84 7F092F54 E4CA0000 */  swc1  $f10, ($a2)
/* 0C7A88 7F092F58 C4CC0000 */  lwc1  $f12, ($a2)
/* 0C7A8C 7F092F5C 460C003E */  c.le.s $f0, $f12
/* 0C7A90 7F092F60 00000000 */  nop   
/* 0C7A94 7F092F64 45020005 */  bc1fl .L7F092F7C
/* 0C7A98 7F092F68 4612603C */   c.lt.s $f12, $f18
/* 0C7A9C 7F092F6C 46006181 */  sub.s $f6, $f12, $f0
/* 0C7AA0 7F092F70 E4C60000 */  swc1  $f6, ($a2)
/* 0C7AA4 7F092F74 C4CC0000 */  lwc1  $f12, ($a2)
/* 0C7AA8 7F092F78 4612603C */  c.lt.s $f12, $f18
.L7F092F7C:
/* 0C7AAC 7F092F7C 00000000 */  nop   
/* 0C7AB0 7F092F80 45020005 */  bc1fl .L7F092F98
/* 0C7AB4 7F092F84 444FF800 */   cfc1  $t7, $31
/* 0C7AB8 7F092F88 46006200 */  add.s $f8, $f12, $f0
/* 0C7ABC 7F092F8C E4C80000 */  swc1  $f8, ($a2)
/* 0C7AC0 7F092F90 C4CC0000 */  lwc1  $f12, ($a2)
/* 0C7AC4 7F092F94 444FF800 */  cfc1  $t7, $31
.L7F092F98:
/* 0C7AC8 7F092F98 44D8F800 */  ctc1  $t8, $31
/* 0C7ACC 7F092F9C 3C028004 */  lui   $v0, %hi(MipMap2C_Something_Setup)
/* 0C7AD0 7F092FA0 2442FCC0 */  addiu $v0, %lo(MipMap2C_Something_Setup) # addiu $v0, $v0, -0x340
/* 0C7AD4 7F092FA4 46007124 */  cvt.w.s $f4, $f14
/* 0C7AD8 7F092FA8 8C430010 */  lw    $v1, 0x10($v0)
/* 0C7ADC 7F092FAC 3C014F00 */  li    $at, 0x4F000000 # 2147483648.000000
/* 0C7AE0 7F092FB0 4458F800 */  cfc1  $t8, $31
/* 0C7AE4 7F092FB4 00000000 */  nop   
/* 0C7AE8 7F092FB8 33180078 */  andi  $t8, $t8, 0x78
/* 0C7AEC 7F092FBC 53000013 */  beql  $t8, $zero, .L7F09300C
/* 0C7AF0 7F092FC0 44182000 */   mfc1  $t8, $f4
/* 0C7AF4 7F092FC4 44812000 */  mtc1  $at, $f4
/* 0C7AF8 7F092FC8 24180001 */  li    $t8, 1
/* 0C7AFC 7F092FCC 46047101 */  sub.s $f4, $f14, $f4
/* 0C7B00 7F092FD0 44D8F800 */  ctc1  $t8, $31
/* 0C7B04 7F092FD4 00000000 */  nop   
/* 0C7B08 7F092FD8 46002124 */  cvt.w.s $f4, $f4
/* 0C7B0C 7F092FDC 4458F800 */  cfc1  $t8, $31
/* 0C7B10 7F092FE0 00000000 */  nop   
/* 0C7B14 7F092FE4 33180078 */  andi  $t8, $t8, 0x78
/* 0C7B18 7F092FE8 17000005 */  bnez  $t8, .L7F093000
/* 0C7B1C 7F092FEC 00000000 */   nop   
/* 0C7B20 7F092FF0 44182000 */  mfc1  $t8, $f4
/* 0C7B24 7F092FF4 3C018000 */  lui   $at, 0x8000
/* 0C7B28 7F092FF8 10000007 */  b     .L7F093018
/* 0C7B2C 7F092FFC 0301C025 */   or    $t8, $t8, $at
.L7F093000:
/* 0C7B30 7F093000 10000005 */  b     .L7F093018
/* 0C7B34 7F093004 2418FFFF */   li    $t8, -1
/* 0C7B38 7F093008 44182000 */  mfc1  $t8, $f4
.L7F09300C:
/* 0C7B3C 7F09300C 00000000 */  nop   
/* 0C7B40 7F093010 0700FFFB */  bltz  $t8, .L7F093000
/* 0C7B44 7F093014 00000000 */   nop   
.L7F093018:
/* 0C7B48 7F093018 44CFF800 */  ctc1  $t7, $31
/* 0C7B4C 7F09301C 240F0001 */  li    $t7, 1
/* 0C7B50 7F093020 00034B02 */  srl   $t1, $v1, 0xc
/* 0C7B54 7F093024 03095026 */  xor   $t2, $t8, $t1
/* 0C7B58 7F093028 444EF800 */  cfc1  $t6, $31
/* 0C7B5C 7F09302C 44CFF800 */  ctc1  $t7, $31
/* 0C7B60 7F093030 000A5D00 */  sll   $t3, $t2, 0x14
/* 0C7B64 7F093034 000B6202 */  srl   $t4, $t3, 8
/* 0C7B68 7F093038 460012A4 */  cvt.w.s $f10, $f2
/* 0C7B6C 7F09303C 01836826 */  xor   $t5, $t4, $v1
/* 0C7B70 7F093040 AC4D0010 */  sw    $t5, 0x10($v0)
/* 0C7B74 7F093044 3C014F00 */  li    $at, 0x4F000000 # 2147483648.000000
/* 0C7B78 7F093048 444FF800 */  cfc1  $t7, $31
/* 0C7B7C 7F09304C 00000000 */  nop   
/* 0C7B80 7F093050 31EF0078 */  andi  $t7, $t7, 0x78
/* 0C7B84 7F093054 51E00013 */  beql  $t7, $zero, .L7F0930A4
/* 0C7B88 7F093058 440F5000 */   mfc1  $t7, $f10
/* 0C7B8C 7F09305C 44815000 */  mtc1  $at, $f10
/* 0C7B90 7F093060 240F0001 */  li    $t7, 1
/* 0C7B94 7F093064 460A1281 */  sub.s $f10, $f2, $f10
/* 0C7B98 7F093068 44CFF800 */  ctc1  $t7, $31
/* 0C7B9C 7F09306C 00000000 */  nop   
/* 0C7BA0 7F093070 460052A4 */  cvt.w.s $f10, $f10
/* 0C7BA4 7F093074 444FF800 */  cfc1  $t7, $31
/* 0C7BA8 7F093078 00000000 */  nop   
/* 0C7BAC 7F09307C 31EF0078 */  andi  $t7, $t7, 0x78
/* 0C7BB0 7F093080 15E00005 */  bnez  $t7, .L7F093098
/* 0C7BB4 7F093084 00000000 */   nop   
/* 0C7BB8 7F093088 440F5000 */  mfc1  $t7, $f10
/* 0C7BBC 7F09308C 3C018000 */  lui   $at, 0x8000
/* 0C7BC0 7F093090 10000007 */  b     .L7F0930B0
/* 0C7BC4 7F093094 01E17825 */   or    $t7, $t7, $at
.L7F093098:
/* 0C7BC8 7F093098 10000005 */  b     .L7F0930B0
/* 0C7BCC 7F09309C 240FFFFF */   li    $t7, -1
/* 0C7BD0 7F0930A0 440F5000 */  mfc1  $t7, $f10
.L7F0930A4:
/* 0C7BD4 7F0930A4 00000000 */  nop   
/* 0C7BD8 7F0930A8 05E0FFFB */  bltz  $t7, .L7F093098
/* 0C7BDC 7F0930AC 00000000 */   nop   
.L7F0930B0:
/* 0C7BE0 7F0930B0 44CEF800 */  ctc1  $t6, $31
/* 0C7BE4 7F0930B4 94490012 */  lhu   $t1, 0x12($v0)
/* 0C7BE8 7F0930B8 8C440018 */  lw    $a0, 0x18($v0)
/* 0C7BEC 7F0930BC 4600718D */  trunc.w.s $f6, $f14
/* 0C7BF0 7F0930C0 31F90FFF */  andi  $t9, $t7, 0xfff
/* 0C7BF4 7F0930C4 312AF000 */  andi  $t2, $t1, 0xf000
/* 0C7BF8 7F0930C8 032A5825 */  or    $t3, $t9, $t2
/* 0C7BFC 7F0930CC 440D3000 */  mfc1  $t5, $f6
/* 0C7C00 7F0930D0 00044B02 */  srl   $t1, $a0, 0xc
/* 0C7C04 7F0930D4 4600120D */  trunc.w.s $f8, $f2
/* 0C7C08 7F0930D8 25AE005A */  addiu $t6, $t5, 0x5a
/* 0C7C0C 7F0930DC 31D800FF */  andi  $t8, $t6, 0xff
/* 0C7C10 7F0930E0 0309C826 */  xor   $t9, $t8, $t1
/* 0C7C14 7F0930E4 A44B0012 */  sh    $t3, 0x12($v0)
/* 0C7C18 7F0930E8 00195500 */  sll   $t2, $t9, 0x14
/* 0C7C1C 7F0930EC 000A5A02 */  srl   $t3, $t2, 8
/* 0C7C20 7F0930F0 01646026 */  xor   $t4, $t3, $a0
/* 0C7C24 7F0930F4 440E4000 */  mfc1  $t6, $f8
/* 0C7C28 7F0930F8 AC4C0018 */  sw    $t4, 0x18($v0)
/* 0C7C2C 7F0930FC 944A001A */  lhu   $t2, 0x1a($v0)
/* 0C7C30 7F093100 25C90096 */  addiu $t1, $t6, 0x96
/* 0C7C34 7F093104 313900FF */  andi  $t9, $t1, 0xff
/* 0C7C38 7F093108 314BF000 */  andi  $t3, $t2, 0xf000
/* 0C7C3C 7F09310C 032B6025 */  or    $t4, $t9, $t3
/* 0C7C40 7F093110 0FC15FAB */  jal   sinf
/* 0C7C44 7F093114 A44C001A */   sh    $t4, 0x1a($v0)
/* 0C7C48 7F093118 3C0142FE */  li    $at, 0x42FE0000 # 127.000000
/* 0C7C4C 7F09311C 44812000 */  mtc1  $at, $f4
/* 0C7C50 7F093120 3C014300 */  li    $at, 0x43000000 # 128.000000
/* 0C7C54 7F093124 44813000 */  mtc1  $at, $f6
/* 0C7C58 7F093128 46040282 */  mul.s $f10, $f0, $f4
/* 0C7C5C 7F09312C 240E0001 */  li    $t6, 1
/* 0C7C60 7F093130 3C028004 */  lui   $v0, %hi(MipMap2C_Something_Setup)
/* 0C7C64 7F093134 3C038004 */  lui   $v1, %hi(MipMap2C_Something2_Setup)
/* 0C7C68 7F093138 3C068008 */  lui   $a2, %hi(flt_CODE_bss_80079E88)
/* 0C7C6C 7F09313C 3C078008 */  lui   $a3, %hi(flt_CODE_bss_80079E84)
/* 0C7C70 7F093140 3C088008 */  lui   $t0, %hi(flt_CODE_bss_80079E80) 
/* 0C7C74 7F093144 46065200 */  add.s $f8, $f10, $f6
/* 0C7C78 7F093148 25089E80 */  addiu $t0, %lo(flt_CODE_bss_80079E80) # addiu $t0, $t0, -0x6180
/* 0C7C7C 7F09314C 24E79E84 */  addiu $a3, %lo(flt_CODE_bss_80079E84) # addiu $a3, $a3, -0x617c
/* 0C7C80 7F093150 24C69E88 */  addiu $a2, %lo(flt_CODE_bss_80079E88) # addiu $a2, $a2, -0x6178
/* 0C7C84 7F093154 444DF800 */  cfc1  $t5, $31
/* 0C7C88 7F093158 44CEF800 */  ctc1  $t6, $31
/* 0C7C8C 7F09315C 2463FD28 */  addiu $v1, %lo(MipMap2C_Something2_Setup) # addiu $v1, $v1, -0x2d8
/* 0C7C90 7F093160 2442FCC0 */  addiu $v0, %lo(MipMap2C_Something_Setup) # addiu $v0, $v0, -0x340
/* 0C7C94 7F093164 46004124 */  cvt.w.s $f4, $f8
/* 0C7C98 7F093168 3C014F00 */  li    $at, 0x4F000000 # 2147483648.000000
/* 0C7C9C 7F09316C 444EF800 */  cfc1  $t6, $31
/* 0C7CA0 7F093170 00000000 */  nop   
/* 0C7CA4 7F093174 31CE0078 */  andi  $t6, $t6, 0x78
/* 0C7CA8 7F093178 51C00013 */  beql  $t6, $zero, .L7F0931C8
/* 0C7CAC 7F09317C 440E2000 */   mfc1  $t6, $f4
/* 0C7CB0 7F093180 44812000 */  mtc1  $at, $f4
/* 0C7CB4 7F093184 240E0001 */  li    $t6, 1
/* 0C7CB8 7F093188 46044101 */  sub.s $f4, $f8, $f4
/* 0C7CBC 7F09318C 44CEF800 */  ctc1  $t6, $31
/* 0C7CC0 7F093190 00000000 */  nop   
/* 0C7CC4 7F093194 46002124 */  cvt.w.s $f4, $f4
/* 0C7CC8 7F093198 444EF800 */  cfc1  $t6, $31
/* 0C7CCC 7F09319C 00000000 */  nop   
/* 0C7CD0 7F0931A0 31CE0078 */  andi  $t6, $t6, 0x78
/* 0C7CD4 7F0931A4 15C00005 */  bnez  $t6, .L7F0931BC
/* 0C7CD8 7F0931A8 00000000 */   nop   
/* 0C7CDC 7F0931AC 440E2000 */  mfc1  $t6, $f4
/* 0C7CE0 7F0931B0 3C018000 */  lui   $at, 0x8000
/* 0C7CE4 7F0931B4 10000007 */  b     .L7F0931D4
/* 0C7CE8 7F0931B8 01C17025 */   or    $t6, $t6, $at
.L7F0931BC:
/* 0C7CEC 7F0931BC 10000005 */  b     .L7F0931D4
/* 0C7CF0 7F0931C0 240EFFFF */   li    $t6, -1
/* 0C7CF4 7F0931C4 440E2000 */  mfc1  $t6, $f4
.L7F0931C8:
/* 0C7CF8 7F0931C8 00000000 */  nop   
/* 0C7CFC 7F0931CC 05C0FFFB */  bltz  $t6, .L7F0931BC
/* 0C7D00 7F0931D0 00000000 */   nop   
.L7F0931D4:
/* 0C7D04 7F0931D4 44CDF800 */  ctc1  $t5, $31
/* 0C7D08 7F0931D8 24190001 */  li    $t9, 1
/* 0C7D0C 7F0931DC C50E0000 */  lwc1  $f14, ($t0)
/* 0C7D10 7F0931E0 8C4F0020 */  lw    $t7, 0x20($v0)
/* 0C7D14 7F0931E4 444AF800 */  cfc1  $t2, $31
/* 0C7D18 7F0931E8 44D9F800 */  ctc1  $t9, $31
/* 0C7D1C 7F0931EC 2401FF00 */  li    $at, -256
/* 0C7D20 7F0931F0 01E1C024 */  and   $t8, $t7, $at
/* 0C7D24 7F0931F4 460072A4 */  cvt.w.s $f10, $f14
/* 0C7D28 7F0931F8 01D84825 */  or    $t1, $t6, $t8
/* 0C7D2C 7F0931FC AC490020 */  sw    $t1, 0x20($v0)
/* 0C7D30 7F093200 3C014F00 */  li    $at, 0x4F000000 # 2147483648.000000
/* 0C7D34 7F093204 4459F800 */  cfc1  $t9, $31
/* 0C7D38 7F093208 8C640010 */  lw    $a0, 0x10($v1)
/* 0C7D3C 7F09320C 33390078 */  andi  $t9, $t9, 0x78
/* 0C7D40 7F093210 53200013 */  beql  $t9, $zero, .L7F093260
/* 0C7D44 7F093214 44195000 */   mfc1  $t9, $f10
/* 0C7D48 7F093218 44815000 */  mtc1  $at, $f10
/* 0C7D4C 7F09321C 24190001 */  li    $t9, 1
/* 0C7D50 7F093220 460A7281 */  sub.s $f10, $f14, $f10
/* 0C7D54 7F093224 44D9F800 */  ctc1  $t9, $31
/* 0C7D58 7F093228 00000000 */  nop   
/* 0C7D5C 7F09322C 460052A4 */  cvt.w.s $f10, $f10
/* 0C7D60 7F093230 4459F800 */  cfc1  $t9, $31
/* 0C7D64 7F093234 00000000 */  nop   
/* 0C7D68 7F093238 33390078 */  andi  $t9, $t9, 0x78
/* 0C7D6C 7F09323C 17200005 */  bnez  $t9, .L7F093254
/* 0C7D70 7F093240 00000000 */   nop   
/* 0C7D74 7F093244 44195000 */  mfc1  $t9, $f10
/* 0C7D78 7F093248 3C018000 */  lui   $at, 0x8000
/* 0C7D7C 7F09324C 10000007 */  b     .L7F09326C
/* 0C7D80 7F093250 0321C825 */   or    $t9, $t9, $at
.L7F093254:
/* 0C7D84 7F093254 10000005 */  b     .L7F09326C
/* 0C7D88 7F093258 2419FFFF */   li    $t9, -1
/* 0C7D8C 7F09325C 44195000 */  mfc1  $t9, $f10
.L7F093260:
/* 0C7D90 7F093260 00000000 */  nop   
/* 0C7D94 7F093264 0720FFFB */  bltz  $t9, .L7F093254
/* 0C7D98 7F093268 00000000 */   nop   
.L7F09326C:
/* 0C7D9C 7F09326C 44CAF800 */  ctc1  $t2, $31
/* 0C7DA0 7F093270 240A0001 */  li    $t2, 1
/* 0C7DA4 7F093274 C4E20000 */  lwc1  $f2, ($a3)
/* 0C7DA8 7F093278 00046302 */  srl   $t4, $a0, 0xc
/* 0C7DAC 7F09327C 4449F800 */  cfc1  $t1, $31
/* 0C7DB0 7F093280 44CAF800 */  ctc1  $t2, $31
/* 0C7DB4 7F093284 032C6826 */  xor   $t5, $t9, $t4
/* 0C7DB8 7F093288 000D7D00 */  sll   $t7, $t5, 0x14
/* 0C7DBC 7F09328C 460011A4 */  cvt.w.s $f6, $f2
/* 0C7DC0 7F093290 000F7202 */  srl   $t6, $t7, 8
/* 0C7DC4 7F093294 01C4C026 */  xor   $t8, $t6, $a0
/* 0C7DC8 7F093298 AC780010 */  sw    $t8, 0x10($v1)
/* 0C7DCC 7F09329C 444AF800 */  cfc1  $t2, $31
/* 0C7DD0 7F0932A0 3C014F00 */  li    $at, 0x4F000000 # 2147483648.000000
/* 0C7DD4 7F0932A4 314A0078 */  andi  $t2, $t2, 0x78
/* 0C7DD8 7F0932A8 51400013 */  beql  $t2, $zero, .L7F0932F8
/* 0C7DDC 7F0932AC 440A3000 */   mfc1  $t2, $f6
/* 0C7DE0 7F0932B0 44813000 */  mtc1  $at, $f6
/* 0C7DE4 7F0932B4 240A0001 */  li    $t2, 1
/* 0C7DE8 7F0932B8 46061181 */  sub.s $f6, $f2, $f6
/* 0C7DEC 7F0932BC 44CAF800 */  ctc1  $t2, $31
/* 0C7DF0 7F0932C0 00000000 */  nop   
/* 0C7DF4 7F0932C4 460031A4 */  cvt.w.s $f6, $f6
/* 0C7DF8 7F0932C8 444AF800 */  cfc1  $t2, $31
/* 0C7DFC 7F0932CC 00000000 */  nop   
/* 0C7E00 7F0932D0 314A0078 */  andi  $t2, $t2, 0x78
/* 0C7E04 7F0932D4 15400005 */  bnez  $t2, .L7F0932EC
/* 0C7E08 7F0932D8 00000000 */   nop   
/* 0C7E0C 7F0932DC 440A3000 */  mfc1  $t2, $f6
/* 0C7E10 7F0932E0 3C018000 */  lui   $at, 0x8000
/* 0C7E14 7F0932E4 10000007 */  b     .L7F093304
/* 0C7E18 7F0932E8 01415025 */   or    $t2, $t2, $at
.L7F0932EC:
/* 0C7E1C 7F0932EC 10000005 */  b     .L7F093304
/* 0C7E20 7F0932F0 240AFFFF */   li    $t2, -1
/* 0C7E24 7F0932F4 440A3000 */  mfc1  $t2, $f6
.L7F0932F8:
/* 0C7E28 7F0932F8 00000000 */  nop   
/* 0C7E2C 7F0932FC 0540FFFB */  bltz  $t2, .L7F0932EC
/* 0C7E30 7F093300 00000000 */   nop   
.L7F093304:
/* 0C7E34 7F093304 44C9F800 */  ctc1  $t1, $31
/* 0C7E38 7F093308 946C0012 */  lhu   $t4, 0x12($v1)
/* 0C7E3C 7F09330C 8C650018 */  lw    $a1, 0x18($v1)
/* 0C7E40 7F093310 4600720D */  trunc.w.s $f8, $f14
/* 0C7E44 7F093314 314B0FFF */  andi  $t3, $t2, 0xfff
/* 0C7E48 7F093318 318DF000 */  andi  $t5, $t4, 0xf000
/* 0C7E4C 7F09331C 016D7825 */  or    $t7, $t3, $t5
/* 0C7E50 7F093320 44184000 */  mfc1  $t8, $f8
/* 0C7E54 7F093324 00056302 */  srl   $t4, $a1, 0xc
/* 0C7E58 7F093328 4600110D */  trunc.w.s $f4, $f2
/* 0C7E5C 7F09332C 2709005A */  addiu $t1, $t8, 0x5a
/* 0C7E60 7F093330 313900FF */  andi  $t9, $t1, 0xff
/* 0C7E64 7F093334 032C5826 */  xor   $t3, $t9, $t4
/* 0C7E68 7F093338 A46F0012 */  sh    $t7, 0x12($v1)
/* 0C7E6C 7F09333C 000B6D00 */  sll   $t5, $t3, 0x14
/* 0C7E70 7F093340 000D7A02 */  srl   $t7, $t5, 8
/* 0C7E74 7F093344 01E57026 */  xor   $t6, $t7, $a1
/* 0C7E78 7F093348 44092000 */  mfc1  $t1, $f4
/* 0C7E7C 7F09334C AC6E0018 */  sw    $t6, 0x18($v1)
/* 0C7E80 7F093350 946D001A */  lhu   $t5, 0x1a($v1)
/* 0C7E84 7F093354 252C0096 */  addiu $t4, $t1, 0x96
/* 0C7E88 7F093358 318B00FF */  andi  $t3, $t4, 0xff
/* 0C7E8C 7F09335C 31AFF000 */  andi  $t7, $t5, 0xf000
/* 0C7E90 7F093360 016F7025 */  or    $t6, $t3, $t7
/* 0C7E94 7F093364 A46E001A */  sh    $t6, 0x1a($v1)
/* 0C7E98 7F093368 0FC15FAB */  jal   sinf
/* 0C7E9C 7F09336C C4CC0000 */   lwc1  $f12, ($a2)
/* 0C7EA0 7F093370 3C0142FE */  li    $at, 0x42FE0000 # 127.000000
/* 0C7EA4 7F093374 44815000 */  mtc1  $at, $f10
/* 0C7EA8 7F093378 3C014300 */  li    $at, 0x43000000 # 128.000000
/* 0C7EAC 7F09337C 44814000 */  mtc1  $at, $f8
/* 0C7EB0 7F093380 460A0182 */  mul.s $f6, $f0, $f10
/* 0C7EB4 7F093384 24090001 */  li    $t1, 1
/* 0C7EB8 7F093388 3C028004 */  lui   $v0, %hi(MipMap2C_Something_Setup)
/* 0C7EBC 7F09338C 3C038004 */  lui   $v1, %hi(MipMap2C_Something2_Setup)
/* 0C7EC0 7F093390 2463FD28 */  addiu $v1, %lo(MipMap2C_Something2_Setup) # addiu $v1, $v1, -0x2d8
/* 0C7EC4 7F093394 2442FCC0 */  addiu $v0, %lo(MipMap2C_Something_Setup) # addiu $v0, $v0, -0x340
/* 0C7EC8 7F093398 3C014F00 */  li    $at, 0x4F000000 # 2147483648.000000
/* 0C7ECC 7F09339C 46083100 */  add.s $f4, $f6, $f8
/* 0C7ED0 7F0933A0 4458F800 */  cfc1  $t8, $31
/* 0C7ED4 7F0933A4 44C9F800 */  ctc1  $t1, $31
/* 0C7ED8 7F0933A8 00000000 */  nop   
/* 0C7EDC 7F0933AC 460022A4 */  cvt.w.s $f10, $f4
/* 0C7EE0 7F0933B0 4449F800 */  cfc1  $t1, $31
/* 0C7EE4 7F0933B4 00000000 */  nop   
/* 0C7EE8 7F0933B8 31290078 */  andi  $t1, $t1, 0x78
/* 0C7EEC 7F0933BC 51200013 */  beql  $t1, $zero, .L7F09340C
/* 0C7EF0 7F0933C0 44095000 */   mfc1  $t1, $f10
/* 0C7EF4 7F0933C4 44815000 */  mtc1  $at, $f10
/* 0C7EF8 7F0933C8 24090001 */  li    $t1, 1
/* 0C7EFC 7F0933CC 460A2281 */  sub.s $f10, $f4, $f10
/* 0C7F00 7F0933D0 44C9F800 */  ctc1  $t1, $31
/* 0C7F04 7F0933D4 00000000 */  nop   
/* 0C7F08 7F0933D8 460052A4 */  cvt.w.s $f10, $f10
/* 0C7F0C 7F0933DC 4449F800 */  cfc1  $t1, $31
/* 0C7F10 7F0933E0 00000000 */  nop   
/* 0C7F14 7F0933E4 31290078 */  andi  $t1, $t1, 0x78
/* 0C7F18 7F0933E8 15200005 */  bnez  $t1, .L7F093400
/* 0C7F1C 7F0933EC 00000000 */   nop   
/* 0C7F20 7F0933F0 44095000 */  mfc1  $t1, $f10
/* 0C7F24 7F0933F4 3C018000 */  lui   $at, 0x8000
/* 0C7F28 7F0933F8 10000007 */  b     .L7F093418
/* 0C7F2C 7F0933FC 01214825 */   or    $t1, $t1, $at
.L7F093400:
/* 0C7F30 7F093400 10000005 */  b     .L7F093418
/* 0C7F34 7F093404 2409FFFF */   li    $t1, -1
/* 0C7F38 7F093408 44095000 */  mfc1  $t1, $f10
.L7F09340C:
/* 0C7F3C 7F09340C 00000000 */  nop   
/* 0C7F40 7F093410 0520FFFB */  bltz  $t1, .L7F093400
/* 0C7F44 7F093414 00000000 */   nop   
.L7F093418:
/* 0C7F48 7F093418 8C4A0020 */  lw    $t2, 0x20($v0)
/* 0C7F4C 7F09341C 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0C7F50 7F093420 2401FF00 */  li    $at, -256
/* 0C7F54 7F093424 0141C824 */  and   $t9, $t2, $at
/* 0C7F58 7F093428 01396025 */  or    $t4, $t1, $t9
/* 0C7F5C 7F09342C 44D8F800 */  ctc1  $t8, $31
/* 0C7F60 7F093430 AC6C0020 */  sw    $t4, 0x20($v1)
/* 0C7F64 7F093434 03E00008 */  jr    $ra
/* 0C7F68 7F093438 27BD0018 */   addiu $sp, $sp, 0x18
)
#endif
#ifdef VERSION_EU
GLOBAL_ASM(
.late_rodata
glabel D_80057510
.word 0x3dcccccd /*0.1*/
glabel D_80057514
.word 0x40c90fd0 /*6.2831802*/
glabel D_80057518
.word 0x3d23d70a /*0.039999999*/
.text
glabel sub_GAME_7F092E50
/* 0C4D80 7F092390 3C014380 */  li    $at, 0x43800000 # 256.000000
/* 0C4D84 7F092394 44810000 */  mtc1  $at, $f0
/* 0C4D88 7F092398 3C018004 */  lui   $at, %hi(g_GlobalTimerDelta) # $at, 0x8004
/* 0C4D8C 7F09239C C4301004 */  lwc1  $f16, %lo(g_GlobalTimerDelta)($at)
/* 0C4D90 7F0923A0 3C013E80 */  li    $at, 0x3E800000 # 0.250000
/* 0C4D94 7F0923A4 44813000 */  mtc1  $at, $f6
/* 0C4D98 7F0923A8 3C088007 */  lui   $t0, %hi(flt_CODE_bss_80079E80) # $t0, 0x8007
/* 0C4D9C 7F0923AC 25088990 */  addiu $t0, %lo(flt_CODE_bss_80079E80) # addiu $t0, $t0, -0x7670
/* 0C4DA0 7F0923B0 46068202 */  mul.s $f8, $f16, $f6
/* 0C4DA4 7F0923B4 C5040000 */  lwc1  $f4, ($t0)
/* 0C4DA8 7F0923B8 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0C4DAC 7F0923BC 44809000 */  mtc1  $zero, $f18
/* 0C4DB0 7F0923C0 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0C4DB4 7F0923C4 3C018005 */  lui   $at, %hi(D_80057510) # $at, 0x8005
/* 0C4DB8 7F0923C8 240F0001 */  li    $t7, 1
/* 0C4DBC 7F0923CC 46082280 */  add.s $f10, $f4, $f8
/* 0C4DC0 7F0923D0 E50A0000 */  swc1  $f10, ($t0)
/* 0C4DC4 7F0923D4 C50E0000 */  lwc1  $f14, ($t0)
/* 0C4DC8 7F0923D8 460E003E */  c.le.s $f0, $f14
/* 0C4DCC 7F0923DC 00000000 */  nop   
/* 0C4DD0 7F0923E0 45020005 */  bc1fl .L7F0923F8
/* 0C4DD4 7F0923E4 4612703C */   c.lt.s $f14, $f18
/* 0C4DD8 7F0923E8 46007181 */  sub.s $f6, $f14, $f0
/* 0C4DDC 7F0923EC E5060000 */  swc1  $f6, ($t0)
/* 0C4DE0 7F0923F0 C50E0000 */  lwc1  $f14, ($t0)
/* 0C4DE4 7F0923F4 4612703C */  c.lt.s $f14, $f18
.L7F0923F8:
/* 0C4DE8 7F0923F8 00000000 */  nop   
/* 0C4DEC 7F0923FC 45000004 */  bc1f  .L7F092410
/* 0C4DF0 7F092400 00000000 */   nop   
/* 0C4DF4 7F092404 46007100 */  add.s $f4, $f14, $f0
/* 0C4DF8 7F092408 E5040000 */  swc1  $f4, ($t0)
/* 0C4DFC 7F09240C C50E0000 */  lwc1  $f14, ($t0)
.L7F092410:
/* 0C4E00 7F092410 C42ACBD0 */  lwc1  $f10, %lo(D_80057510)($at)
/* 0C4E04 7F092414 3C078007 */  lui   $a3, %hi(flt_CODE_bss_80079E84) # $a3, 0x8007
/* 0C4E08 7F092418 24E78994 */  addiu $a3, %lo(flt_CODE_bss_80079E84) # addiu $a3, $a3, -0x766c
/* 0C4E0C 7F09241C 460A8182 */  mul.s $f6, $f16, $f10
/* 0C4E10 7F092420 C4E80000 */  lwc1  $f8, ($a3)
/* 0C4E14 7F092424 3C018005 */  lui   $at, %hi(D_80057514) # $at, 0x8005
/* 0C4E18 7F092428 46064100 */  add.s $f4, $f8, $f6
/* 0C4E1C 7F09242C E4E40000 */  swc1  $f4, ($a3)
/* 0C4E20 7F092430 C4E20000 */  lwc1  $f2, ($a3)
/* 0C4E24 7F092434 4602003E */  c.le.s $f0, $f2
/* 0C4E28 7F092438 00000000 */  nop   
/* 0C4E2C 7F09243C 45020005 */  bc1fl .L7F092454
/* 0C4E30 7F092440 4612103C */   c.lt.s $f2, $f18
/* 0C4E34 7F092444 46001281 */  sub.s $f10, $f2, $f0
/* 0C4E38 7F092448 E4EA0000 */  swc1  $f10, ($a3)
/* 0C4E3C 7F09244C C4E20000 */  lwc1  $f2, ($a3)
/* 0C4E40 7F092450 4612103C */  c.lt.s $f2, $f18
.L7F092454:
/* 0C4E44 7F092454 00000000 */  nop   
/* 0C4E48 7F092458 45000004 */  bc1f  .L7F09246C
/* 0C4E4C 7F09245C 00000000 */   nop   
/* 0C4E50 7F092460 46001200 */  add.s $f8, $f2, $f0
/* 0C4E54 7F092464 E4E80000 */  swc1  $f8, ($a3)
/* 0C4E58 7F092468 C4E20000 */  lwc1  $f2, ($a3)
.L7F09246C:
/* 0C4E5C 7F09246C C420CBD4 */  lwc1  $f0, %lo(D_80057514)($at)
/* 0C4E60 7F092470 3C018005 */  lui   $at, %hi(D_80057518) # $at, 0x8005
/* 0C4E64 7F092474 C424CBD8 */  lwc1  $f4, %lo(D_80057518)($at)
/* 0C4E68 7F092478 3C068007 */  lui   $a2, %hi(flt_CODE_bss_80079E88) # $a2, 0x8007
/* 0C4E6C 7F09247C 24C68998 */  addiu $a2, %lo(flt_CODE_bss_80079E88) # addiu $a2, $a2, -0x7668
/* 0C4E70 7F092480 46048282 */  mul.s $f10, $f16, $f4
/* 0C4E74 7F092484 C4C60000 */  lwc1  $f6, ($a2)
/* 0C4E78 7F092488 460A3200 */  add.s $f8, $f6, $f10
/* 0C4E7C 7F09248C E4C80000 */  swc1  $f8, ($a2)
/* 0C4E80 7F092490 C4CC0000 */  lwc1  $f12, ($a2)
/* 0C4E84 7F092494 460C003E */  c.le.s $f0, $f12
/* 0C4E88 7F092498 00000000 */  nop   
/* 0C4E8C 7F09249C 45020005 */  bc1fl .L7F0924B4
/* 0C4E90 7F0924A0 4612603C */   c.lt.s $f12, $f18
/* 0C4E94 7F0924A4 46006101 */  sub.s $f4, $f12, $f0
/* 0C4E98 7F0924A8 E4C40000 */  swc1  $f4, ($a2)
/* 0C4E9C 7F0924AC C4CC0000 */  lwc1  $f12, ($a2)
/* 0C4EA0 7F0924B0 4612603C */  c.lt.s $f12, $f18
.L7F0924B4:
/* 0C4EA4 7F0924B4 00000000 */  nop   
/* 0C4EA8 7F0924B8 45020005 */  bc1fl .L7F0924D0
/* 0C4EAC 7F0924BC 444EF800 */   cfc1  $t6, $31
/* 0C4EB0 7F0924C0 46006180 */  add.s $f6, $f12, $f0
/* 0C4EB4 7F0924C4 E4C60000 */  swc1  $f6, ($a2)
/* 0C4EB8 7F0924C8 C4CC0000 */  lwc1  $f12, ($a2)
/* 0C4EBC 7F0924CC 444EF800 */  cfc1  $t6, $31
.L7F0924D0:
/* 0C4EC0 7F0924D0 44CFF800 */  ctc1  $t7, $31
/* 0C4EC4 7F0924D4 3C028004 */  lui   $v0, %hi(MipMap2C_Something_Setup) # $v0, 0x8004
/* 0C4EC8 7F0924D8 24429910 */  addiu $v0, %lo(MipMap2C_Something_Setup) # addiu $v0, $v0, -0x66f0
/* 0C4ECC 7F0924DC 460072A4 */  cvt.w.s $f10, $f14
/* 0C4ED0 7F0924E0 8C430010 */  lw    $v1, 0x10($v0)
/* 0C4ED4 7F0924E4 3C014F00 */  li    $at, 0x4F000000 # 2147483648.000000
/* 0C4ED8 7F0924E8 444FF800 */  cfc1  $t7, $31
/* 0C4EDC 7F0924EC 00000000 */  nop   
/* 0C4EE0 7F0924F0 31EF0078 */  andi  $t7, $t7, 0x78
/* 0C4EE4 7F0924F4 51E00013 */  beql  $t7, $zero, .L7F092544
/* 0C4EE8 7F0924F8 440F5000 */   mfc1  $t7, $f10
/* 0C4EEC 7F0924FC 44815000 */  mtc1  $at, $f10
/* 0C4EF0 7F092500 240F0001 */  li    $t7, 1
/* 0C4EF4 7F092504 460A7281 */  sub.s $f10, $f14, $f10
/* 0C4EF8 7F092508 44CFF800 */  ctc1  $t7, $31
/* 0C4EFC 7F09250C 00000000 */  nop   
/* 0C4F00 7F092510 460052A4 */  cvt.w.s $f10, $f10
/* 0C4F04 7F092514 444FF800 */  cfc1  $t7, $31
/* 0C4F08 7F092518 00000000 */  nop   
/* 0C4F0C 7F09251C 31EF0078 */  andi  $t7, $t7, 0x78
/* 0C4F10 7F092520 15E00005 */  bnez  $t7, .L7F092538
/* 0C4F14 7F092524 00000000 */   nop   
/* 0C4F18 7F092528 440F5000 */  mfc1  $t7, $f10
/* 0C4F1C 7F09252C 3C018000 */  lui   $at, 0x8000
/* 0C4F20 7F092530 10000007 */  b     .L7F092550
/* 0C4F24 7F092534 01E17825 */   or    $t7, $t7, $at
.L7F092538:
/* 0C4F28 7F092538 10000005 */  b     .L7F092550
/* 0C4F2C 7F09253C 240FFFFF */   li    $t7, -1
/* 0C4F30 7F092540 440F5000 */  mfc1  $t7, $f10
.L7F092544:
/* 0C4F34 7F092544 00000000 */  nop   
/* 0C4F38 7F092548 05E0FFFB */  bltz  $t7, .L7F092538
/* 0C4F3C 7F09254C 00000000 */   nop   
.L7F092550:
/* 0C4F40 7F092550 44CEF800 */  ctc1  $t6, $31
/* 0C4F44 7F092554 240E0001 */  li    $t6, 1
/* 0C4F48 7F092558 0003CB02 */  srl   $t9, $v1, 0xc
/* 0C4F4C 7F09255C 01F94826 */  xor   $t1, $t7, $t9
/* 0C4F50 7F092560 444DF800 */  cfc1  $t5, $31
/* 0C4F54 7F092564 44CEF800 */  ctc1  $t6, $31
/* 0C4F58 7F092568 00095500 */  sll   $t2, $t1, 0x14
/* 0C4F5C 7F09256C 000A5A02 */  srl   $t3, $t2, 8
/* 0C4F60 7F092570 46001224 */  cvt.w.s $f8, $f2
/* 0C4F64 7F092574 01636026 */  xor   $t4, $t3, $v1
/* 0C4F68 7F092578 AC4C0010 */  sw    $t4, 0x10($v0)
/* 0C4F6C 7F09257C 3C014F00 */  li    $at, 0x4F000000 # 2147483648.000000
/* 0C4F70 7F092580 444EF800 */  cfc1  $t6, $31
/* 0C4F74 7F092584 00000000 */  nop   
/* 0C4F78 7F092588 31CE0078 */  andi  $t6, $t6, 0x78
/* 0C4F7C 7F09258C 51C00013 */  beql  $t6, $zero, .L7F0925DC
/* 0C4F80 7F092590 440E4000 */   mfc1  $t6, $f8
/* 0C4F84 7F092594 44814000 */  mtc1  $at, $f8
/* 0C4F88 7F092598 240E0001 */  li    $t6, 1
/* 0C4F8C 7F09259C 46081201 */  sub.s $f8, $f2, $f8
/* 0C4F90 7F0925A0 44CEF800 */  ctc1  $t6, $31
/* 0C4F94 7F0925A4 00000000 */  nop   
/* 0C4F98 7F0925A8 46004224 */  cvt.w.s $f8, $f8
/* 0C4F9C 7F0925AC 444EF800 */  cfc1  $t6, $31
/* 0C4FA0 7F0925B0 00000000 */  nop   
/* 0C4FA4 7F0925B4 31CE0078 */  andi  $t6, $t6, 0x78
/* 0C4FA8 7F0925B8 15C00005 */  bnez  $t6, .L7F0925D0
/* 0C4FAC 7F0925BC 00000000 */   nop   
/* 0C4FB0 7F0925C0 440E4000 */  mfc1  $t6, $f8
/* 0C4FB4 7F0925C4 3C018000 */  lui   $at, 0x8000
/* 0C4FB8 7F0925C8 10000007 */  b     .L7F0925E8
/* 0C4FBC 7F0925CC 01C17025 */   or    $t6, $t6, $at
.L7F0925D0:
/* 0C4FC0 7F0925D0 10000005 */  b     .L7F0925E8
/* 0C4FC4 7F0925D4 240EFFFF */   li    $t6, -1
/* 0C4FC8 7F0925D8 440E4000 */  mfc1  $t6, $f8
.L7F0925DC:
/* 0C4FCC 7F0925DC 00000000 */  nop   
/* 0C4FD0 7F0925E0 05C0FFFB */  bltz  $t6, .L7F0925D0
/* 0C4FD4 7F0925E4 00000000 */   nop   
.L7F0925E8:
/* 0C4FD8 7F0925E8 44CDF800 */  ctc1  $t5, $31
/* 0C4FDC 7F0925EC 94590012 */  lhu   $t9, 0x12($v0)
/* 0C4FE0 7F0925F0 8C440018 */  lw    $a0, 0x18($v0)
/* 0C4FE4 7F0925F4 4600710D */  trunc.w.s $f4, $f14
/* 0C4FE8 7F0925F8 31D80FFF */  andi  $t8, $t6, 0xfff
/* 0C4FEC 7F0925FC 3329F000 */  andi  $t1, $t9, 0xf000
/* 0C4FF0 7F092600 03095025 */  or    $t2, $t8, $t1
/* 0C4FF4 7F092604 440C2000 */  mfc1  $t4, $f4
/* 0C4FF8 7F092608 0004CB02 */  srl   $t9, $a0, 0xc
/* 0C4FFC 7F09260C 4600118D */  trunc.w.s $f6, $f2
/* 0C5000 7F092610 258D005A */  addiu $t5, $t4, 0x5a
/* 0C5004 7F092614 31AF00FF */  andi  $t7, $t5, 0xff
/* 0C5008 7F092618 01F9C026 */  xor   $t8, $t7, $t9
/* 0C500C 7F09261C A44A0012 */  sh    $t2, 0x12($v0)
/* 0C5010 7F092620 00184D00 */  sll   $t1, $t8, 0x14
/* 0C5014 7F092624 00095202 */  srl   $t2, $t1, 8
/* 0C5018 7F092628 01445826 */  xor   $t3, $t2, $a0
/* 0C501C 7F09262C 440D3000 */  mfc1  $t5, $f6
/* 0C5020 7F092630 AC4B0018 */  sw    $t3, 0x18($v0)
/* 0C5024 7F092634 9449001A */  lhu   $t1, 0x1a($v0)
/* 0C5028 7F092638 25B90096 */  addiu $t9, $t5, 0x96
/* 0C502C 7F09263C 333800FF */  andi  $t8, $t9, 0xff
/* 0C5030 7F092640 312AF000 */  andi  $t2, $t1, 0xf000
/* 0C5034 7F092644 030A5825 */  or    $t3, $t8, $t2
/* 0C5038 7F092648 0FC1606B */  jal   sinf
/* 0C503C 7F09264C A44B001A */   sh    $t3, 0x1a($v0)
/* 0C5040 7F092650 3C0142FE */  li    $at, 0x42FE0000 # 127.000000
/* 0C5044 7F092654 44815000 */  mtc1  $at, $f10
/* 0C5048 7F092658 3C014300 */  li    $at, 0x43000000 # 128.000000
/* 0C504C 7F09265C 44812000 */  mtc1  $at, $f4
/* 0C5050 7F092660 460A0202 */  mul.s $f8, $f0, $f10
/* 0C5054 7F092664 240D0001 */  li    $t5, 1
/* 0C5058 7F092668 3C028004 */  lui   $v0, %hi(MipMap2C_Something_Setup) # $v0, 0x8004
/* 0C505C 7F09266C 3C038004 */  lui   $v1, %hi(MipMap2C_Something2_Setup) # $v1, 0x8004
/* 0C5060 7F092670 3C068007 */  lui   $a2, %hi(flt_CODE_bss_80079E88) # $a2, 0x8007
/* 0C5064 7F092674 3C078007 */  lui   $a3, %hi(flt_CODE_bss_80079E84) # $a3, 0x8007
/* 0C5068 7F092678 3C088007 */  lui   $t0, %hi(flt_CODE_bss_80079E80) # $t0, 0x8007
/* 0C506C 7F09267C 46044180 */  add.s $f6, $f8, $f4
/* 0C5070 7F092680 25088990 */  addiu $t0, %lo(flt_CODE_bss_80079E80) # addiu $t0, $t0, -0x7670
/* 0C5074 7F092684 24E78994 */  addiu $a3, %lo(flt_CODE_bss_80079E84) # addiu $a3, $a3, -0x766c
/* 0C5078 7F092688 24C68998 */  addiu $a2, %lo(flt_CODE_bss_80079E88) # addiu $a2, $a2, -0x7668
/* 0C507C 7F09268C 444CF800 */  cfc1  $t4, $31
/* 0C5080 7F092690 44CDF800 */  ctc1  $t5, $31
/* 0C5084 7F092694 24639978 */  addiu $v1, %lo(MipMap2C_Something2_Setup) # addiu $v1, $v1, -0x6688
/* 0C5088 7F092698 24429910 */  addiu $v0, %lo(MipMap2C_Something_Setup) # addiu $v0, $v0, -0x66f0
/* 0C508C 7F09269C 460032A4 */  cvt.w.s $f10, $f6
/* 0C5090 7F0926A0 3C014F00 */  li    $at, 0x4F000000 # 2147483648.000000
/* 0C5094 7F0926A4 444DF800 */  cfc1  $t5, $31
/* 0C5098 7F0926A8 00000000 */  nop   
/* 0C509C 7F0926AC 31AD0078 */  andi  $t5, $t5, 0x78
/* 0C50A0 7F0926B0 51A00013 */  beql  $t5, $zero, .L7F092700
/* 0C50A4 7F0926B4 440D5000 */   mfc1  $t5, $f10
/* 0C50A8 7F0926B8 44815000 */  mtc1  $at, $f10
/* 0C50AC 7F0926BC 240D0001 */  li    $t5, 1
/* 0C50B0 7F0926C0 460A3281 */  sub.s $f10, $f6, $f10
/* 0C50B4 7F0926C4 44CDF800 */  ctc1  $t5, $31
/* 0C50B8 7F0926C8 00000000 */  nop   
/* 0C50BC 7F0926CC 460052A4 */  cvt.w.s $f10, $f10
/* 0C50C0 7F0926D0 444DF800 */  cfc1  $t5, $31
/* 0C50C4 7F0926D4 00000000 */  nop   
/* 0C50C8 7F0926D8 31AD0078 */  andi  $t5, $t5, 0x78
/* 0C50CC 7F0926DC 15A00005 */  bnez  $t5, .L7F0926F4
/* 0C50D0 7F0926E0 00000000 */   nop   
/* 0C50D4 7F0926E4 440D5000 */  mfc1  $t5, $f10
/* 0C50D8 7F0926E8 3C018000 */  lui   $at, 0x8000
/* 0C50DC 7F0926EC 10000007 */  b     .L7F09270C
/* 0C50E0 7F0926F0 01A16825 */   or    $t5, $t5, $at
.L7F0926F4:
/* 0C50E4 7F0926F4 10000005 */  b     .L7F09270C
/* 0C50E8 7F0926F8 240DFFFF */   li    $t5, -1
/* 0C50EC 7F0926FC 440D5000 */  mfc1  $t5, $f10
.L7F092700:
/* 0C50F0 7F092700 00000000 */  nop   
/* 0C50F4 7F092704 05A0FFFB */  bltz  $t5, .L7F0926F4
/* 0C50F8 7F092708 00000000 */   nop   
.L7F09270C:
/* 0C50FC 7F09270C 44CCF800 */  ctc1  $t4, $31
/* 0C5100 7F092710 24180001 */  li    $t8, 1
/* 0C5104 7F092714 C50E0000 */  lwc1  $f14, ($t0)
/* 0C5108 7F092718 8C4E0020 */  lw    $t6, 0x20($v0)
/* 0C510C 7F09271C 4449F800 */  cfc1  $t1, $31
/* 0C5110 7F092720 44D8F800 */  ctc1  $t8, $31
/* 0C5114 7F092724 2401FF00 */  li    $at, -256
/* 0C5118 7F092728 01C17824 */  and   $t7, $t6, $at
/* 0C511C 7F09272C 46007224 */  cvt.w.s $f8, $f14
/* 0C5120 7F092730 01AFC825 */  or    $t9, $t5, $t7
/* 0C5124 7F092734 AC590020 */  sw    $t9, 0x20($v0)
/* 0C5128 7F092738 3C014F00 */  li    $at, 0x4F000000 # 2147483648.000000
/* 0C512C 7F09273C 4458F800 */  cfc1  $t8, $31
/* 0C5130 7F092740 8C640010 */  lw    $a0, 0x10($v1)
/* 0C5134 7F092744 33180078 */  andi  $t8, $t8, 0x78
/* 0C5138 7F092748 53000013 */  beql  $t8, $zero, .L7F092798
/* 0C513C 7F09274C 44184000 */   mfc1  $t8, $f8
/* 0C5140 7F092750 44814000 */  mtc1  $at, $f8
/* 0C5144 7F092754 24180001 */  li    $t8, 1
/* 0C5148 7F092758 46087201 */  sub.s $f8, $f14, $f8
/* 0C514C 7F09275C 44D8F800 */  ctc1  $t8, $31
/* 0C5150 7F092760 00000000 */  nop   
/* 0C5154 7F092764 46004224 */  cvt.w.s $f8, $f8
/* 0C5158 7F092768 4458F800 */  cfc1  $t8, $31
/* 0C515C 7F09276C 00000000 */  nop   
/* 0C5160 7F092770 33180078 */  andi  $t8, $t8, 0x78
/* 0C5164 7F092774 17000005 */  bnez  $t8, .L7F09278C
/* 0C5168 7F092778 00000000 */   nop   
/* 0C516C 7F09277C 44184000 */  mfc1  $t8, $f8
/* 0C5170 7F092780 3C018000 */  lui   $at, 0x8000
/* 0C5174 7F092784 10000007 */  b     .L7F0927A4
/* 0C5178 7F092788 0301C025 */   or    $t8, $t8, $at
.L7F09278C:
/* 0C517C 7F09278C 10000005 */  b     .L7F0927A4
/* 0C5180 7F092790 2418FFFF */   li    $t8, -1
/* 0C5184 7F092794 44184000 */  mfc1  $t8, $f8
.L7F092798:
/* 0C5188 7F092798 00000000 */  nop   
/* 0C518C 7F09279C 0700FFFB */  bltz  $t8, .L7F09278C
/* 0C5190 7F0927A0 00000000 */   nop   
.L7F0927A4:
/* 0C5194 7F0927A4 44C9F800 */  ctc1  $t1, $31
/* 0C5198 7F0927A8 24090001 */  li    $t1, 1
/* 0C519C 7F0927AC C4E20000 */  lwc1  $f2, ($a3)
/* 0C51A0 7F0927B0 00045B02 */  srl   $t3, $a0, 0xc
/* 0C51A4 7F0927B4 4459F800 */  cfc1  $t9, $31
/* 0C51A8 7F0927B8 44C9F800 */  ctc1  $t1, $31
/* 0C51AC 7F0927BC 030B6026 */  xor   $t4, $t8, $t3
/* 0C51B0 7F0927C0 000C7500 */  sll   $t6, $t4, 0x14
/* 0C51B4 7F0927C4 46001124 */  cvt.w.s $f4, $f2
/* 0C51B8 7F0927C8 000E6A02 */  srl   $t5, $t6, 8
/* 0C51BC 7F0927CC 01A47826 */  xor   $t7, $t5, $a0
/* 0C51C0 7F0927D0 AC6F0010 */  sw    $t7, 0x10($v1)
/* 0C51C4 7F0927D4 4449F800 */  cfc1  $t1, $31
/* 0C51C8 7F0927D8 3C014F00 */  li    $at, 0x4F000000 # 2147483648.000000
/* 0C51CC 7F0927DC 31290078 */  andi  $t1, $t1, 0x78
/* 0C51D0 7F0927E0 51200013 */  beql  $t1, $zero, .L7F092830
/* 0C51D4 7F0927E4 44092000 */   mfc1  $t1, $f4
/* 0C51D8 7F0927E8 44812000 */  mtc1  $at, $f4
/* 0C51DC 7F0927EC 24090001 */  li    $t1, 1
/* 0C51E0 7F0927F0 46041101 */  sub.s $f4, $f2, $f4
/* 0C51E4 7F0927F4 44C9F800 */  ctc1  $t1, $31
/* 0C51E8 7F0927F8 00000000 */  nop   
/* 0C51EC 7F0927FC 46002124 */  cvt.w.s $f4, $f4
/* 0C51F0 7F092800 4449F800 */  cfc1  $t1, $31
/* 0C51F4 7F092804 00000000 */  nop   
/* 0C51F8 7F092808 31290078 */  andi  $t1, $t1, 0x78
/* 0C51FC 7F09280C 15200005 */  bnez  $t1, .L7F092824
/* 0C5200 7F092810 00000000 */   nop   
/* 0C5204 7F092814 44092000 */  mfc1  $t1, $f4
/* 0C5208 7F092818 3C018000 */  lui   $at, 0x8000
/* 0C520C 7F09281C 10000007 */  b     .L7F09283C
/* 0C5210 7F092820 01214825 */   or    $t1, $t1, $at
.L7F092824:
/* 0C5214 7F092824 10000005 */  b     .L7F09283C
/* 0C5218 7F092828 2409FFFF */   li    $t1, -1
/* 0C521C 7F09282C 44092000 */  mfc1  $t1, $f4
.L7F092830:
/* 0C5220 7F092830 00000000 */  nop   
/* 0C5224 7F092834 0520FFFB */  bltz  $t1, .L7F092824
/* 0C5228 7F092838 00000000 */   nop   
.L7F09283C:
/* 0C522C 7F09283C 44D9F800 */  ctc1  $t9, $31
/* 0C5230 7F092840 946B0012 */  lhu   $t3, 0x12($v1)
/* 0C5234 7F092844 8C650018 */  lw    $a1, 0x18($v1)
/* 0C5238 7F092848 4600718D */  trunc.w.s $f6, $f14
/* 0C523C 7F09284C 312A0FFF */  andi  $t2, $t1, 0xfff
/* 0C5240 7F092850 316CF000 */  andi  $t4, $t3, 0xf000
/* 0C5244 7F092854 014C7025 */  or    $t6, $t2, $t4
/* 0C5248 7F092858 440F3000 */  mfc1  $t7, $f6
/* 0C524C 7F09285C 00055B02 */  srl   $t3, $a1, 0xc
/* 0C5250 7F092860 4600128D */  trunc.w.s $f10, $f2
/* 0C5254 7F092864 25F9005A */  addiu $t9, $t7, 0x5a
/* 0C5258 7F092868 333800FF */  andi  $t8, $t9, 0xff
/* 0C525C 7F09286C 030B5026 */  xor   $t2, $t8, $t3
/* 0C5260 7F092870 A46E0012 */  sh    $t6, 0x12($v1)
/* 0C5264 7F092874 000A6500 */  sll   $t4, $t2, 0x14
/* 0C5268 7F092878 000C7202 */  srl   $t6, $t4, 8
/* 0C526C 7F09287C 01C56826 */  xor   $t5, $t6, $a1
/* 0C5270 7F092880 44195000 */  mfc1  $t9, $f10
/* 0C5274 7F092884 AC6D0018 */  sw    $t5, 0x18($v1)
/* 0C5278 7F092888 946C001A */  lhu   $t4, 0x1a($v1)
/* 0C527C 7F09288C 272B0096 */  addiu $t3, $t9, 0x96
/* 0C5280 7F092890 316A00FF */  andi  $t2, $t3, 0xff
/* 0C5284 7F092894 318EF000 */  andi  $t6, $t4, 0xf000
/* 0C5288 7F092898 014E6825 */  or    $t5, $t2, $t6
/* 0C528C 7F09289C A46D001A */  sh    $t5, 0x1a($v1)
/* 0C5290 7F0928A0 0FC1606B */  jal   sinf
/* 0C5294 7F0928A4 C4CC0000 */   lwc1  $f12, ($a2)
/* 0C5298 7F0928A8 3C0142FE */  li    $at, 0x42FE0000 # 127.000000
/* 0C529C 7F0928AC 44814000 */  mtc1  $at, $f8
/* 0C52A0 7F0928B0 3C014300 */  li    $at, 0x43000000 # 128.000000
/* 0C52A4 7F0928B4 44813000 */  mtc1  $at, $f6
/* 0C52A8 7F0928B8 46080102 */  mul.s $f4, $f0, $f8
/* 0C52AC 7F0928BC 24190001 */  li    $t9, 1
/* 0C52B0 7F0928C0 3C028004 */  lui   $v0, %hi(MipMap2C_Something_Setup) # $v0, 0x8004
/* 0C52B4 7F0928C4 3C038004 */  lui   $v1, %hi(MipMap2C_Something2_Setup) # $v1, 0x8004
/* 0C52B8 7F0928C8 24639978 */  addiu $v1, %lo(MipMap2C_Something2_Setup) # addiu $v1, $v1, -0x6688
/* 0C52BC 7F0928CC 24429910 */  addiu $v0, %lo(MipMap2C_Something_Setup) # addiu $v0, $v0, -0x66f0
/* 0C52C0 7F0928D0 3C014F00 */  li    $at, 0x4F000000 # 2147483648.000000
/* 0C52C4 7F0928D4 46062280 */  add.s $f10, $f4, $f6
/* 0C52C8 7F0928D8 444FF800 */  cfc1  $t7, $31
/* 0C52CC 7F0928DC 44D9F800 */  ctc1  $t9, $31
/* 0C52D0 7F0928E0 00000000 */  nop   
/* 0C52D4 7F0928E4 46005224 */  cvt.w.s $f8, $f10
/* 0C52D8 7F0928E8 4459F800 */  cfc1  $t9, $31
/* 0C52DC 7F0928EC 00000000 */  nop   
/* 0C52E0 7F0928F0 33390078 */  andi  $t9, $t9, 0x78
/* 0C52E4 7F0928F4 53200013 */  beql  $t9, $zero, .L7F092944
/* 0C52E8 7F0928F8 44194000 */   mfc1  $t9, $f8
/* 0C52EC 7F0928FC 44814000 */  mtc1  $at, $f8
/* 0C52F0 7F092900 24190001 */  li    $t9, 1
/* 0C52F4 7F092904 46085201 */  sub.s $f8, $f10, $f8
/* 0C52F8 7F092908 44D9F800 */  ctc1  $t9, $31
/* 0C52FC 7F09290C 00000000 */  nop   
/* 0C5300 7F092910 46004224 */  cvt.w.s $f8, $f8
/* 0C5304 7F092914 4459F800 */  cfc1  $t9, $31
/* 0C5308 7F092918 00000000 */  nop   
/* 0C530C 7F09291C 33390078 */  andi  $t9, $t9, 0x78
/* 0C5310 7F092920 17200005 */  bnez  $t9, .L7F092938
/* 0C5314 7F092924 00000000 */   nop   
/* 0C5318 7F092928 44194000 */  mfc1  $t9, $f8
/* 0C531C 7F09292C 3C018000 */  lui   $at, 0x8000
/* 0C5320 7F092930 10000007 */  b     .L7F092950
/* 0C5324 7F092934 0321C825 */   or    $t9, $t9, $at
.L7F092938:
/* 0C5328 7F092938 10000005 */  b     .L7F092950
/* 0C532C 7F09293C 2419FFFF */   li    $t9, -1
/* 0C5330 7F092940 44194000 */  mfc1  $t9, $f8
.L7F092944:
/* 0C5334 7F092944 00000000 */  nop   
/* 0C5338 7F092948 0720FFFB */  bltz  $t9, .L7F092938
/* 0C533C 7F09294C 00000000 */   nop   
.L7F092950:
/* 0C5340 7F092950 8C490020 */  lw    $t1, 0x20($v0)
/* 0C5344 7F092954 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0C5348 7F092958 2401FF00 */  li    $at, -256
/* 0C534C 7F09295C 0121C024 */  and   $t8, $t1, $at
/* 0C5350 7F092960 03385825 */  or    $t3, $t9, $t8
/* 0C5354 7F092964 44CFF800 */  ctc1  $t7, $31
/* 0C5358 7F092968 AC6B0020 */  sw    $t3, 0x20($v1)
/* 0C535C 7F09296C 03E00008 */  jr    $ra
/* 0C5360 7F092970 27BD0018 */   addiu $sp, $sp, 0x18
)
#endif
#endif





#ifdef NONMATCHING
void sub_GAME_7F09343C(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F09343C
/* 0C7F6C 7F09343C 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 0C7F70 7F093440 10A00009 */  beqz  $a1, .L7F093468
/* 0C7F74 7F093444 AFBF0014 */   sw    $ra, 0x14($sp)
/* 0C7F78 7F093448 00801025 */  move  $v0, $a0
/* 0C7F7C 7F09344C 3C0F8004 */  lui   $t7, %hi(MipMap2C_Something_Setup) 
/* 0C7F80 7F093450 25EFFCC0 */  addiu $t7, %lo(MipMap2C_Something_Setup) # addiu $t7, $t7, -0x340
/* 0C7F84 7F093454 3C0E0600 */  lui   $t6, 0x600
/* 0C7F88 7F093458 AC4E0000 */  sw    $t6, ($v0)
/* 0C7F8C 7F09345C AC4F0004 */  sw    $t7, 4($v0)
/* 0C7F90 7F093460 10000079 */  b     .L7F093648
/* 0C7F94 7F093464 24840008 */   addiu $a0, $a0, 8
.L7F093468:
/* 0C7F98 7F093468 3C08F510 */  lui   $t0, %hi(0xF5100004) # $t0, 0xf510
/* 0C7F9C 7F09346C 00801025 */  move  $v0, $a0
/* 0C7FA0 7F093470 3C180001 */  lui   $t8, (0x00014050 >> 16) # lui $t8, 1
/* 0C7FA4 7F093474 35080800 */  ori   $t0, (0xF5100800 & 0xFFFF) # ori $t0, $t0, 0x800
/* 0C7FA8 7F093478 37184050 */  ori   $t8, (0x00014050 & 0xFFFF) # ori $t8, $t8, 0x4050
/* 0C7FAC 7F09347C 24830008 */  addiu $v1, $a0, 8
/* 0C7FB0 7F093480 AC580004 */  sw    $t8, 4($v0)
/* 0C7FB4 7F093484 AC480000 */  sw    $t0, ($v0)
/* 0C7FB8 7F093488 3C190101 */  lui   $t9, (0x01014050 >> 16) # lui $t9, 0x101
/* 0C7FBC 7F09348C 37394050 */  ori   $t9, (0x01014050 & 0xFFFF) # ori $t9, $t9, 0x4050
/* 0C7FC0 7F093490 24650008 */  addiu $a1, $v1, 8
/* 0C7FC4 7F093494 AC790004 */  sw    $t9, 4($v1)
/* 0C7FC8 7F093498 AC680000 */  sw    $t0, ($v1)
/* 0C7FCC 7F09349C 24A60008 */  addiu $a2, $a1, 8
/* 0C7FD0 7F0934A0 3C0AF200 */  lui   $t2, 0xf200
/* 0C7FD4 7F0934A4 ACAA0000 */  sw    $t2, ($a1)
/* 0C7FD8 7F0934A8 ACA00004 */  sw    $zero, 4($a1)
/* 0C7FDC 7F0934AC 3C0BF205 */  lui   $t3, (0xF205A096 >> 16) # lui $t3, 0xf205
/* 0C7FE0 7F0934B0 356BA096 */  ori   $t3, (0xF205A096 & 0xFFFF) # ori $t3, $t3, 0xa096
/* 0C7FE4 7F0934B4 3C0C0100 */  lui   $t4, 0x100
/* 0C7FE8 7F0934B8 ACCC0004 */  sw    $t4, 4($a2)
/* 0C7FEC 7F0934BC ACCB0000 */  sw    $t3, ($a2)
/* 0C7FF0 7F0934C0 24C70008 */  addiu $a3, $a2, 8
/* 0C7FF4 7F0934C4 24E40008 */  addiu $a0, $a3, 8
/* 0C7FF8 7F0934C8 3C018008 */  lui   $at, %hi(flt_CODE_bss_80079E88)
/* 0C7FFC 7F0934CC C42C9E88 */  lwc1  $f12, %lo(flt_CODE_bss_80079E88)($at)
/* 0C8000 7F0934D0 AFA40030 */  sw    $a0, 0x30($sp)
/* 0C8004 7F0934D4 0FC15FAB */  jal   sinf
/* 0C8008 7F0934D8 AFA70018 */   sw    $a3, 0x18($sp)
/* 0C800C 7F0934DC 3C0142FE */  li    $at, 0x42FE0000 # 127.000000
/* 0C8010 7F0934E0 44812000 */  mtc1  $at, $f4
/* 0C8014 7F0934E4 3C014300 */  li    $at, 0x43000000 # 128.000000
/* 0C8018 7F0934E8 44814000 */  mtc1  $at, $f8
/* 0C801C 7F0934EC 46040182 */  mul.s $f6, $f0, $f4
/* 0C8020 7F0934F0 240E0001 */  li    $t6, 1
/* 0C8024 7F0934F4 8FA40030 */  lw    $a0, 0x30($sp)
/* 0C8028 7F0934F8 3C0ABA00 */  lui   $t2, (0xBA001102 >> 16) # lui $t2, 0xba00
/* 0C802C 7F0934FC 3C0BBA00 */  lui   $t3, (0xBA000C02 >> 16) # lui $t3, 0xba00
/* 0C8030 7F093500 00801025 */  move  $v0, $a0
/* 0C8034 7F093504 24840008 */  addiu $a0, $a0, 8
/* 0C8038 7F093508 46083280 */  add.s $f10, $f6, $f8
/* 0C803C 7F09350C 00801825 */  move  $v1, $a0
/* 0C8040 7F093510 24840008 */  addiu $a0, $a0, 8
/* 0C8044 7F093514 00802825 */  move  $a1, $a0
/* 0C8048 7F093518 444DF800 */  cfc1  $t5, $31
/* 0C804C 7F09351C 44CEF800 */  ctc1  $t6, $31
/* 0C8050 7F093520 3C0CFC27 */  lui   $t4, (0xFC272C04 >> 16) # lui $t4, 0xfc27
/* 0C8054 7F093524 8FA70018 */  lw    $a3, 0x18($sp)
/* 0C8058 7F093528 46005424 */  cvt.w.s $f16, $f10
/* 0C805C 7F09352C 24092000 */  li    $t1, 8192
/* 0C8060 7F093530 2419FFFF */  li    $t9, -1
/* 0C8064 7F093534 354A1102 */  ori   $t2, (0xBA001102 & 0xFFFF) # ori $t2, $t2, 0x1102
/* 0C8068 7F093538 444EF800 */  cfc1  $t6, $31
/* 0C806C 7F09353C 356B0C02 */  ori   $t3, (0xBA000C02 & 0xFFFF) # ori $t3, $t3, 0xc02
/* 0C8070 7F093540 358C2C04 */  ori   $t4, (0xFC272C04 & 0xFFFF) # ori $t4, $t4, 0x2c04
/* 0C8074 7F093544 31CE0078 */  andi  $t6, $t6, 0x78
/* 0C8078 7F093548 11C00013 */  beqz  $t6, .L7F093598
/* 0C807C 7F09354C 24840008 */   addiu $a0, $a0, 8
/* 0C8080 7F093550 3C014F00 */  li    $at, 0x4F000000 # 2147483648.000000
/* 0C8084 7F093554 44818000 */  mtc1  $at, $f16
/* 0C8088 7F093558 240E0001 */  li    $t6, 1
/* 0C808C 7F09355C 46105401 */  sub.s $f16, $f10, $f16
/* 0C8090 7F093560 44CEF800 */  ctc1  $t6, $31
/* 0C8094 7F093564 00000000 */  nop   
/* 0C8098 7F093568 46008424 */  cvt.w.s $f16, $f16
/* 0C809C 7F09356C 444EF800 */  cfc1  $t6, $31
/* 0C80A0 7F093570 00000000 */  nop   
/* 0C80A4 7F093574 31CE0078 */  andi  $t6, $t6, 0x78
/* 0C80A8 7F093578 15C00005 */  bnez  $t6, .L7F093590
/* 0C80AC 7F09357C 00000000 */   nop   
/* 0C80B0 7F093580 440E8000 */  mfc1  $t6, $f16
/* 0C80B4 7F093584 3C018000 */  lui   $at, 0x8000
/* 0C80B8 7F093588 10000007 */  b     .L7F0935A8
/* 0C80BC 7F09358C 01C17025 */   or    $t6, $t6, $at
.L7F093590:
/* 0C80C0 7F093590 10000005 */  b     .L7F0935A8
/* 0C80C4 7F093594 240EFFFF */   li    $t6, -1
.L7F093598:
/* 0C80C8 7F093598 440E8000 */  mfc1  $t6, $f16
/* 0C80CC 7F09359C 00000000 */  nop   
/* 0C80D0 7F0935A0 05C0FFFB */  bltz  $t6, .L7F093590
/* 0C80D4 7F0935A4 00000000 */   nop   
.L7F0935A8:
/* 0C80D8 7F0935A8 31CF00FF */  andi  $t7, $t6, 0xff
/* 0C80DC 7F0935AC 3C01FA00 */  lui   $at, 0xfa00
/* 0C80E0 7F0935B0 01E1C025 */  or    $t8, $t7, $at
/* 0C80E4 7F0935B4 ACF80000 */  sw    $t8, ($a3)
/* 0C80E8 7F0935B8 ACF90004 */  sw    $t9, 4($a3)
/* 0C80EC 7F0935BC AC400004 */  sw    $zero, 4($v0)
/* 0C80F0 7F0935C0 AC4A0000 */  sw    $t2, ($v0)
/* 0C80F4 7F0935C4 44CDF800 */  ctc1  $t5, $31
/* 0C80F8 7F0935C8 AC690004 */  sw    $t1, 4($v1)
/* 0C80FC 7F0935CC AC6B0000 */  sw    $t3, ($v1)
/* 0C8100 7F0935D0 3C0D1F10 */  lui   $t5, (0x1F1093FF >> 16) # lui $t5, 0x1f10
/* 0C8104 7F0935D4 35AD93FF */  ori   $t5, (0x1F1093FF & 0xFFFF) # ori $t5, $t5, 0x93ff
/* 0C8108 7F0935D8 00803025 */  move  $a2, $a0
/* 0C810C 7F0935DC ACAD0004 */  sw    $t5, 4($a1)
/* 0C8110 7F0935E0 ACAC0000 */  sw    $t4, ($a1)
/* 0C8114 7F0935E4 24840008 */  addiu $a0, $a0, 8
/* 0C8118 7F0935E8 3C0F0C19 */  lui   $t7, (0x0C192078 >> 16) # lui $t7, 0xc19
/* 0C811C 7F0935EC 3C0EB900 */  lui   $t6, (0xB900031D >> 16) # lui $t6, 0xb900
/* 0C8120 7F0935F0 35CE031D */  ori   $t6, (0xB900031D & 0xFFFF) # ori $t6, $t6, 0x31d
/* 0C8124 7F0935F4 35EF2078 */  ori   $t7, (0x0C192078 & 0xFFFF) # ori $t7, $t7, 0x2078
/* 0C8128 7F0935F8 00804025 */  move  $t0, $a0
/* 0C812C 7F0935FC ACCF0004 */  sw    $t7, 4($a2)
/* 0C8130 7F093600 ACCE0000 */  sw    $t6, ($a2)
/* 0C8134 7F093604 24840008 */  addiu $a0, $a0, 8
/* 0C8138 7F093608 3C18BA00 */  lui   $t8, (0xBA001001 >> 16) # lui $t8, 0xba00
/* 0C813C 7F09360C 37181001 */  ori   $t8, (0xBA001001 & 0xFFFF) # ori $t8, $t8, 0x1001
/* 0C8140 7F093610 00801025 */  move  $v0, $a0
/* 0C8144 7F093614 AD180000 */  sw    $t8, ($t0)
/* 0C8148 7F093618 AD000004 */  sw    $zero, %lo(0xF5100004)($t0)
/* 0C814C 7F09361C 24840008 */  addiu $a0, $a0, 8
/* 0C8150 7F093620 3C19BA00 */  lui   $t9, (0xBA001402 >> 16) # lui $t9, 0xba00
/* 0C8154 7F093624 37391402 */  ori   $t9, (0xBA001402 & 0xFFFF) # ori $t9, $t9, 0x1402
/* 0C8158 7F093628 3C0A0010 */  lui   $t2, 0x10
/* 0C815C 7F09362C 00801825 */  move  $v1, $a0
/* 0C8160 7F093630 AC4A0004 */  sw    $t2, 4($v0)
/* 0C8164 7F093634 AC590000 */  sw    $t9, ($v0)
/* 0C8168 7F093638 3C0BB700 */  lui   $t3, 0xb700
/* 0C816C 7F09363C AC6B0000 */  sw    $t3, ($v1)
/* 0C8170 7F093640 AC690004 */  sw    $t1, 4($v1)
/* 0C8174 7F093644 24840008 */  addiu $a0, $a0, 8
.L7F093648:
/* 0C8178 7F093648 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0C817C 7F09364C 27BD0030 */  addiu $sp, $sp, 0x30
/* 0C8180 7F093650 00801025 */  move  $v0, $a0
/* 0C8184 7F093654 03E00008 */  jr    $ra
/* 0C8188 7F093658 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F09365C(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F09365C
/* 0C818C 7F09365C 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 0C8190 7F093660 10A00009 */  beqz  $a1, .L7F093688
/* 0C8194 7F093664 AFBF0014 */   sw    $ra, 0x14($sp)
/* 0C8198 7F093668 00801025 */  move  $v0, $a0
/* 0C819C 7F09366C 3C0F8004 */  lui   $t7, %hi(MipMap2C_Something2_Setup) 
/* 0C81A0 7F093670 25EFFD28 */  addiu $t7, %lo(MipMap2C_Something2_Setup) # addiu $t7, $t7, -0x2d8
/* 0C81A4 7F093674 3C0E0600 */  lui   $t6, 0x600
/* 0C81A8 7F093678 AC4E0000 */  sw    $t6, ($v0)
/* 0C81AC 7F09367C AC4F0004 */  sw    $t7, 4($v0)
/* 0C81B0 7F093680 10000079 */  b     .L7F093868
/* 0C81B4 7F093684 24840008 */   addiu $a0, $a0, 8
.L7F093688:
/* 0C81B8 7F093688 3C08F548 */  lui   $t0, %hi(0xF5480004) # $t0, 0xf548
/* 0C81BC 7F09368C 00801025 */  move  $v0, $a0
/* 0C81C0 7F093690 3C180001 */  lui   $t8, (0x00014050 >> 16) # lui $t8, 1
/* 0C81C4 7F093694 35080400 */  ori   $t0, (0xF5480400 & 0xFFFF) # ori $t0, $t0, 0x400
/* 0C81C8 7F093698 37184050 */  ori   $t8, (0x00014050 & 0xFFFF) # ori $t8, $t8, 0x4050
/* 0C81CC 7F09369C 24830008 */  addiu $v1, $a0, 8
/* 0C81D0 7F0936A0 AC580004 */  sw    $t8, 4($v0)
/* 0C81D4 7F0936A4 AC480000 */  sw    $t0, ($v0)
/* 0C81D8 7F0936A8 3C190101 */  lui   $t9, (0x01014050 >> 16) # lui $t9, 0x101
/* 0C81DC 7F0936AC 37394050 */  ori   $t9, (0x01014050 & 0xFFFF) # ori $t9, $t9, 0x4050
/* 0C81E0 7F0936B0 24650008 */  addiu $a1, $v1, 8
/* 0C81E4 7F0936B4 AC790004 */  sw    $t9, 4($v1)
/* 0C81E8 7F0936B8 AC680000 */  sw    $t0, ($v1)
/* 0C81EC 7F0936BC 24A60008 */  addiu $a2, $a1, 8
/* 0C81F0 7F0936C0 3C0AF200 */  lui   $t2, 0xf200
/* 0C81F4 7F0936C4 ACAA0000 */  sw    $t2, ($a1)
/* 0C81F8 7F0936C8 ACA00004 */  sw    $zero, 4($a1)
/* 0C81FC 7F0936CC 3C0BF205 */  lui   $t3, (0xF205A096 >> 16) # lui $t3, 0xf205
/* 0C8200 7F0936D0 356BA096 */  ori   $t3, (0xF205A096 & 0xFFFF) # ori $t3, $t3, 0xa096
/* 0C8204 7F0936D4 3C0C0100 */  lui   $t4, 0x100
/* 0C8208 7F0936D8 ACCC0004 */  sw    $t4, 4($a2)
/* 0C820C 7F0936DC ACCB0000 */  sw    $t3, ($a2)
/* 0C8210 7F0936E0 24C70008 */  addiu $a3, $a2, 8
/* 0C8214 7F0936E4 24E40008 */  addiu $a0, $a3, 8
/* 0C8218 7F0936E8 3C018008 */  lui   $at, %hi(flt_CODE_bss_80079E88)
/* 0C821C 7F0936EC C42C9E88 */  lwc1  $f12, %lo(flt_CODE_bss_80079E88)($at)
/* 0C8220 7F0936F0 AFA40030 */  sw    $a0, 0x30($sp)
/* 0C8224 7F0936F4 0FC15FAB */  jal   sinf
/* 0C8228 7F0936F8 AFA70018 */   sw    $a3, 0x18($sp)
/* 0C822C 7F0936FC 3C0142FE */  li    $at, 0x42FE0000 # 127.000000
/* 0C8230 7F093700 44812000 */  mtc1  $at, $f4
/* 0C8234 7F093704 3C014300 */  li    $at, 0x43000000 # 128.000000
/* 0C8238 7F093708 44814000 */  mtc1  $at, $f8
/* 0C823C 7F09370C 46040182 */  mul.s $f6, $f0, $f4
/* 0C8240 7F093710 240E0001 */  li    $t6, 1
/* 0C8244 7F093714 8FA40030 */  lw    $a0, 0x30($sp)
/* 0C8248 7F093718 3C0ABA00 */  lui   $t2, (0xBA001102 >> 16) # lui $t2, 0xba00
/* 0C824C 7F09371C 3C0BBA00 */  lui   $t3, (0xBA000C02 >> 16) # lui $t3, 0xba00
/* 0C8250 7F093720 00801025 */  move  $v0, $a0
/* 0C8254 7F093724 24840008 */  addiu $a0, $a0, 8
/* 0C8258 7F093728 46083280 */  add.s $f10, $f6, $f8
/* 0C825C 7F09372C 00801825 */  move  $v1, $a0
/* 0C8260 7F093730 24840008 */  addiu $a0, $a0, 8
/* 0C8264 7F093734 00802825 */  move  $a1, $a0
/* 0C8268 7F093738 444DF800 */  cfc1  $t5, $31
/* 0C826C 7F09373C 44CEF800 */  ctc1  $t6, $31
/* 0C8270 7F093740 3C0CFC27 */  lui   $t4, (0xFC272C04 >> 16) # lui $t4, 0xfc27
/* 0C8274 7F093744 8FA70018 */  lw    $a3, 0x18($sp)
/* 0C8278 7F093748 46005424 */  cvt.w.s $f16, $f10
/* 0C827C 7F09374C 24092000 */  li    $t1, 8192
/* 0C8280 7F093750 2419FFFF */  li    $t9, -1
/* 0C8284 7F093754 354A1102 */  ori   $t2, (0xBA001102 & 0xFFFF) # ori $t2, $t2, 0x1102
/* 0C8288 7F093758 444EF800 */  cfc1  $t6, $31
/* 0C828C 7F09375C 356B0C02 */  ori   $t3, (0xBA000C02 & 0xFFFF) # ori $t3, $t3, 0xc02
/* 0C8290 7F093760 358C2C04 */  ori   $t4, (0xFC272C04 & 0xFFFF) # ori $t4, $t4, 0x2c04
/* 0C8294 7F093764 31CE0078 */  andi  $t6, $t6, 0x78
/* 0C8298 7F093768 11C00013 */  beqz  $t6, .L7F0937B8
/* 0C829C 7F09376C 24840008 */   addiu $a0, $a0, 8
/* 0C82A0 7F093770 3C014F00 */  li    $at, 0x4F000000 # 2147483648.000000
/* 0C82A4 7F093774 44818000 */  mtc1  $at, $f16
/* 0C82A8 7F093778 240E0001 */  li    $t6, 1
/* 0C82AC 7F09377C 46105401 */  sub.s $f16, $f10, $f16
/* 0C82B0 7F093780 44CEF800 */  ctc1  $t6, $31
/* 0C82B4 7F093784 00000000 */  nop   
/* 0C82B8 7F093788 46008424 */  cvt.w.s $f16, $f16
/* 0C82BC 7F09378C 444EF800 */  cfc1  $t6, $31
/* 0C82C0 7F093790 00000000 */  nop   
/* 0C82C4 7F093794 31CE0078 */  andi  $t6, $t6, 0x78
/* 0C82C8 7F093798 15C00005 */  bnez  $t6, .L7F0937B0
/* 0C82CC 7F09379C 00000000 */   nop   
/* 0C82D0 7F0937A0 440E8000 */  mfc1  $t6, $f16
/* 0C82D4 7F0937A4 3C018000 */  lui   $at, 0x8000
/* 0C82D8 7F0937A8 10000007 */  b     .L7F0937C8
/* 0C82DC 7F0937AC 01C17025 */   or    $t6, $t6, $at
.L7F0937B0:
/* 0C82E0 7F0937B0 10000005 */  b     .L7F0937C8
/* 0C82E4 7F0937B4 240EFFFF */   li    $t6, -1
.L7F0937B8:
/* 0C82E8 7F0937B8 440E8000 */  mfc1  $t6, $f16
/* 0C82EC 7F0937BC 00000000 */  nop   
/* 0C82F0 7F0937C0 05C0FFFB */  bltz  $t6, .L7F0937B0
/* 0C82F4 7F0937C4 00000000 */   nop   
.L7F0937C8:
/* 0C82F8 7F0937C8 31CF00FF */  andi  $t7, $t6, 0xff
/* 0C82FC 7F0937CC 3C01FA00 */  lui   $at, 0xfa00
/* 0C8300 7F0937D0 01E1C025 */  or    $t8, $t7, $at
/* 0C8304 7F0937D4 ACF80000 */  sw    $t8, ($a3)
/* 0C8308 7F0937D8 ACF90004 */  sw    $t9, 4($a3)
/* 0C830C 7F0937DC AC400004 */  sw    $zero, 4($v0)
/* 0C8310 7F0937E0 AC4A0000 */  sw    $t2, ($v0)
/* 0C8314 7F0937E4 44CDF800 */  ctc1  $t5, $31
/* 0C8318 7F0937E8 AC690004 */  sw    $t1, 4($v1)
/* 0C831C 7F0937EC AC6B0000 */  sw    $t3, ($v1)
/* 0C8320 7F0937F0 3C0D1F10 */  lui   $t5, (0x1F1093FF >> 16) # lui $t5, 0x1f10
/* 0C8324 7F0937F4 35AD93FF */  ori   $t5, (0x1F1093FF & 0xFFFF) # ori $t5, $t5, 0x93ff
/* 0C8328 7F0937F8 00803025 */  move  $a2, $a0
/* 0C832C 7F0937FC ACAD0004 */  sw    $t5, 4($a1)
/* 0C8330 7F093800 ACAC0000 */  sw    $t4, ($a1)
/* 0C8334 7F093804 24840008 */  addiu $a0, $a0, 8
/* 0C8338 7F093808 3C0F0C19 */  lui   $t7, (0x0C192078 >> 16) # lui $t7, 0xc19
/* 0C833C 7F09380C 3C0EB900 */  lui   $t6, (0xB900031D >> 16) # lui $t6, 0xb900
/* 0C8340 7F093810 35CE031D */  ori   $t6, (0xB900031D & 0xFFFF) # ori $t6, $t6, 0x31d
/* 0C8344 7F093814 35EF2078 */  ori   $t7, (0x0C192078 & 0xFFFF) # ori $t7, $t7, 0x2078
/* 0C8348 7F093818 00804025 */  move  $t0, $a0
/* 0C834C 7F09381C ACCF0004 */  sw    $t7, 4($a2)
/* 0C8350 7F093820 ACCE0000 */  sw    $t6, ($a2)
/* 0C8354 7F093824 24840008 */  addiu $a0, $a0, 8
/* 0C8358 7F093828 3C18BA00 */  lui   $t8, (0xBA001001 >> 16) # lui $t8, 0xba00
/* 0C835C 7F09382C 37181001 */  ori   $t8, (0xBA001001 & 0xFFFF) # ori $t8, $t8, 0x1001
/* 0C8360 7F093830 00801025 */  move  $v0, $a0
/* 0C8364 7F093834 AD180000 */  sw    $t8, ($t0)
/* 0C8368 7F093838 AD000004 */  sw    $zero, %lo(0xF5480004)($t0)
/* 0C836C 7F09383C 24840008 */  addiu $a0, $a0, 8
/* 0C8370 7F093840 3C19BA00 */  lui   $t9, (0xBA001402 >> 16) # lui $t9, 0xba00
/* 0C8374 7F093844 37391402 */  ori   $t9, (0xBA001402 & 0xFFFF) # ori $t9, $t9, 0x1402
/* 0C8378 7F093848 3C0A0010 */  lui   $t2, 0x10
/* 0C837C 7F09384C 00801825 */  move  $v1, $a0
/* 0C8380 7F093850 AC4A0004 */  sw    $t2, 4($v0)
/* 0C8384 7F093854 AC590000 */  sw    $t9, ($v0)
/* 0C8388 7F093858 3C0BB700 */  lui   $t3, 0xb700
/* 0C838C 7F09385C AC6B0000 */  sw    $t3, ($v1)
/* 0C8390 7F093860 AC690004 */  sw    $t1, 4($v1)
/* 0C8394 7F093864 24840008 */  addiu $a0, $a0, 8
.L7F093868:
/* 0C8398 7F093868 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0C839C 7F09386C 27BD0030 */  addiu $sp, $sp, 0x30
/* 0C83A0 7F093870 00801025 */  move  $v0, $a0
/* 0C83A4 7F093874 03E00008 */  jr    $ra
/* 0C83A8 7F093878 00000000 */   nop   
)
#endif


