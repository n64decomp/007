#include <ultra64.h>
#include <PR/gbi.h>
#include <PR/gu.h>
#include <PR/os.h>
#include <assets/font_dl.h>
#include <assets/animationtable_data.h>
#include <bondgame.h>
#include <fr.h>
#include <macro.h>
#include <ramrom.h>
#include "matrixmath.h"
#include "blood_animation.h"
#include "chr.h"
#include "chr_b.h"
#include "math_floor.h"
#include "title.h"
#include "unk_01B240.h"
#include "unk_01BAE0.h"
#include "bondtypes.h"
#include "image.h"
#include "math.h"
#include "objecthandler.h"
#include "ob.h"
#include "chr_b.h"
#include "initanitable.h"
#include "chrobjdata.h"



extern signed short sins(unsigned short x);

// bss
//CODE.bss:80069550
s32 barrelDisplayListPtr;
//CODE.bss:80069554
Gfx *gunbarrelgfxListPointer;
//CODE.bss:80069558
Mtx *matrixBufferRareLogo0;
//CODE.bss:8006955C
Mtx *matrixBufferGunbarrel0;
//CODE.bss:80069560
Mtx *matrixBufferRareLogo1;
//CODE.bss:80069564
Mtx *matrixBufferRareLogo2;
//CODE.bss:80069568
Mtx *matrixBufferGunbarrel1;
//CODE.bss:8006956C
Mtx *matrixBufferIntroBackdrop;
//CODE.bss:80069570
Mtx *matrixBufferIntroBond;
//CODE.bss:80069574
f32 g_TitleX;
//CODE.bss:80069578
f32 g_TitleY;
//CODE.bss:8006957C
f32 titleTransitionX;
//CODE.bss:80069580
f32 titleTransitionY;
//CODE.bss:80069584
s16 word_CODE_bss_80069584;
//CODE.bss:80069588
s32 dword_CODE_bss_80069588;
//CODE.bss:8006958C
s32 dword_CODE_bss_8006958C;
//CODE.bss:80069590
s32 virtualaddress;

/**
 * Address 80069594
 * EU .bss 800684D4
*/
s32 dword_CODE_bss_80069594;


// data
u32 D_8002A7D0 = 0;
u8 gunbarrel_mode = 0x3;
u32 D_8002A7D8 = 0;
/*
s32 D_8002A7DC[3] = {0x00, 0x00, 0x00};
s32 D_8002A7E8[3] = {0xFF, 0xFF, 0xFF};
*/
struct FolderSelect D_8002A7DC = { 0x00, 0x00, 0x00 };
struct FolderSelect D_8002A7E8 = { 0xFF, 0xFF, 0xFF };

Model *chrModelInstance = NULL;
Model *gunModelInstance = NULL;

u32 D_8002A7FC = 0;
u32 D_8002A800 = 1;
u32 D_8002A804 = 3;
u32 D_8002A808 = 0;
u32 D_8002A80C = 0;
u32 D_8002A810 = 0;
u32 D_8002A814 = 0;
u32 D_8002A818 = 0;
u32 D_8002A81C = 0;
u32 D_8002A820 = 0;
u32 D_8002A824 = 0;
u32 D_8002A828 = 0;
u32 D_8002A82C = 0;
u32 D_8002A830 = 0;
u32 D_8002A834 = 0;
u32 D_8002A838 = 0;

f32 gunbarrelPosition1[3] = {1758.2957f, 220.0f, 684.28143f};
f32 gunbarrelPosition2[3] = {-0.97f, 0.0f, 0.24f};
f32 gunbarrelPosition3[3] = {0.0f, 1.0f, -0.0f};

Lights1 gunbarrelLights = gdSPDefLights1(0xDC, 0xDC, 0xDC, 0xFF, 0xFF, 0xFF, 0x00, 0x7F, 0x00);

f32 cameraPosition1[3] = {0.0f, 0.0f, 4883.0f};
f32 cameraPosition2[3] = {0.0f, 0.0f, -1.0f};
f32 cameraPosition3[3] = {0.0f, 1.0f, 0.0f};

f32 D_8002A89C = 0.0f;
s32 intro_eye_counter = 0;
u32 intro_state_blood_animation = 0;
struct coord3d D_8002A8A8 = { 0, 0, 0 };


/**
 * Manipulates matrices for the gun barrel and Rareware logo during the intro sequence.
 * 
 * @param gdl The display list to append graphics commands to.
 * @return Updated display list.
 */
Gfx *manipulateGunbarrelAndLogoMatrices(Gfx *gdl)
{
    guTranslate(&matrixBufferRareLogo2[D_8002A7D0], g_TitleX, g_TitleY, -5.0f);
    guTranslate(&matrixBufferGunbarrel1[D_8002A7D0], titleTransitionX, titleTransitionY, -5.0f);
    gSPDisplayList(gdl++, &dlBasicGeometry);

    gdl = sub_GAME_7F01C1A4(insert_imageDL(gdl));

    gDPSetCombineMode(gdl++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
    gDPSetPrimColor(gdl++, 0, 0, 0xE6, 0xE6, 0xE6, 0x00);
    gSPDisplayList(gdl++, OS_K0_TO_PHYSICAL(gunbarrelgfxListPointer));
    gSPMatrix(gdl++, osVirtualToPhysical(&matrixBufferGunbarrel1[D_8002A7D0]), (G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW));
    gSPDisplayList(gdl++, OS_K0_TO_PHYSICAL(gunbarrelgfxListPointer));

    return gdl;
}

Gfx *insert_sight_backdrop_eye_intro(Gfx *gdl)
{
    guTranslate(&matrixBufferRareLogo2[D_8002A7D0], g_TitleX + 768.0f, g_TitleY - 40.0f, -5.0f);
    guScale(&matrixBufferGunbarrel1[D_8002A7D0], 2.7f, 2.57f, 1.0f);
    gSPDisplayList(gdl++, &dlBasicGeometry);
    gSPDisplayList(gdl++, &dlFastPipelineSetup);

    gdl = sub_GAME_7F01C1A4(gdl);

    gSPMatrix(gdl++, osVirtualToPhysical(&matrixBufferGunbarrel1[D_8002A7D0]), (G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW));
    gSPDisplayList(gdl++, OS_K0_TO_PHYSICAL(gunbarrelgfxListPointer));

    return gdl;
}

Gfx *sub_GAME_7F007CC8(Gfx *gdl, s32 arg1, struct FolderSelect *arg2, struct FolderSelect *arg3)
{
    gDPSetRenderMode(gdl++, G_RM_OPA_SURF, G_RM_OPA_SURF2);
    gDPSetCycleType(gdl++, G_CYC_1CYCLE);
    gDPSetTexturePersp(gdl++, G_TP_NONE);
    gDPSetTextureFilter(gdl++, G_TF_POINT);
    gDPPipeSync(gdl++);

    return sub_GAME_7F01B240(gdl, OS_K0_TO_PHYSICAL(dword_CODE_bss_8006958C), arg1, arg2, arg3);
}

Gfx *insert_sniper_sight_eye_intro(Gfx *gdl)
{
    struct FolderSelect sp3C = D_8002A7DC;
    struct FolderSelect sp30 = D_8002A7E8;

    gSPDisplayList(gdl++, &dlBasicGeometry);

    gdl = insert_imageDL(gdl);

    gDPSetCombineMode(gdl++, G_CC_MODULATEI_PRIM, G_CC_MODULATEI_PRIM);

    return sub_GAME_7F007CC8(gdl, floorFloat((viGetX() * g_TitleX) / 1280.0f), &sp3C, &sp30);
}

Gfx *sub_GAME_7F007E70(Gfx *gdl, u32 alpha)
{
    gdl = sub_GAME_7F01C1A4(gdl);

    gDPSetRenderMode(gdl++, G_RM_CLD_SURF, G_RM_CLD_SURF2);
    gDPSetCombineMode(gdl++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
    gDPSetPrimColor(gdl++, 0, 0, 0x00, 0x00, 0x00, alpha);
    gDPSetColorDither(gdl++, G_CD_MAGICSQ);
    gDPFillRectangle(gdl++, 0, 0, viGetX(), viGetY());

    return gdl;
}

#ifdef NONMATCHING
Gfx *sub_GAME_7F007F30(Gfx*, s32, s32) {

}
#else
Gfx *sub_GAME_7F007F30(Gfx*, s32, s32);

#if defined(LEFTOVERDEBUG)
GLOBAL_ASM(
.late_rodata
glabel D_8004F2D0
.word 0x3f68f5c3
.text
glabel sub_GAME_7F007F30
/* 03CA60 7F007F30 27BDFEE0 */  addiu $sp, $sp, -0x120
/* 03CA64 7F007F34 3C0F8003 */  lui   $t7, %hi(D_8002A7FC) 
/* 03CA68 7F007F38 25EFA7FC */  addiu $t7, %lo(D_8002A7FC) # addiu $t7, $t7, -0x5804
/* 03CA6C 7F007F3C AFBF0034 */  sw    $ra, 0x34($sp)
/* 03CA70 7F007F40 AFB50030 */  sw    $s5, 0x30($sp)
/* 03CA74 7F007F44 AFB4002C */  sw    $s4, 0x2c($sp)
/* 03CA78 7F007F48 AFB30028 */  sw    $s3, 0x28($sp)
/* 03CA7C 7F007F4C AFB20024 */  sw    $s2, 0x24($sp)
/* 03CA80 7F007F50 AFB10020 */  sw    $s1, 0x20($sp)
/* 03CA84 7F007F54 AFB0001C */  sw    $s0, 0x1c($sp)
/* 03CA88 7F007F58 AFA40120 */  sw    $a0, 0x120($sp)
/* 03CA8C 7F007F5C AFA50124 */  sw    $a1, 0x124($sp)
/* 03CA90 7F007F60 AFA60128 */  sw    $a2, 0x128($sp)
/* 03CA94 7F007F64 25E8003C */  addiu $t0, $t7, 0x3c
/* 03CA98 7F007F68 27AE00DC */  addiu $t6, $sp, 0xdc
.L7F007F6C:
/* 03CA9C 7F007F6C 8DE10000 */  lw    $at, ($t7)
/* 03CAA0 7F007F70 25EF000C */  addiu $t7, $t7, 0xc
/* 03CAA4 7F007F74 25CE000C */  addiu $t6, $t6, 0xc
/* 03CAA8 7F007F78 ADC1FFF4 */  sw    $at, -0xc($t6)
/* 03CAAC 7F007F7C 8DE1FFF8 */  lw    $at, -8($t7)
/* 03CAB0 7F007F80 ADC1FFF8 */  sw    $at, -8($t6)
/* 03CAB4 7F007F84 8DE1FFFC */  lw    $at, -4($t7)
/* 03CAB8 7F007F88 15E8FFF8 */  bne   $t7, $t0, .L7F007F6C
/* 03CABC 7F007F8C ADC1FFFC */   sw    $at, -4($t6)
/* 03CAC0 7F007F90 8DE10000 */  lw    $at, ($t7)
/* 03CAC4 7F007F94 0000A825 */  move  $s5, $zero
/* 03CAC8 7F007F98 00009025 */  move  $s2, $zero
/* 03CACC 7F007F9C ADC10000 */  sw    $at, ($t6)
/* 03CAD0 7F007FA0 8FA90124 */  lw    $t1, 0x124($sp)
/* 03CAD4 7F007FA4 19200034 */  blez  $t1, .L7F008078
/* 03CAD8 7F007FA8 3C140000 */   lui   $s4, 0
/* 03CADC 7F007FAC 3C138003 */  lui   $s3, %hi(chrModelInstance)
/* 03CAE0 7F007FB0 3C108007 */  lui   $s0, %hi(dword_CODE_bss_80069594)
/* 03CAE4 7F007FB4 26109594 */  addiu $s0, %lo(dword_CODE_bss_80069594) # addiu $s0, $s0, -0x6a6c
/* 03CAE8 7F007FB8 2673A7F4 */  addiu $s3, %lo(chrModelInstance) # addiu $s3, $s3, -0x580c
/* 03CAEC 7F007FBC 26944298 */  addiu $s4, $s4, 0x4298
/* 03CAF0 7F007FC0 24110089 */  li    $s1, 137
/* 03CAF4 7F007FC4 8E020000 */  lw    $v0, ($s0)
.L7F007FC8:
/* 03CAF8 7F007FC8 04400019 */  bltz  $v0, .L7F008030
/* 03CAFC 7F007FCC 244A0001 */   addiu $t2, $v0, 1
/* 03CB00 7F007FD0 AE0A0000 */  sw    $t2, ($s0)
/* 03CB04 7F007FD4 162A000F */  bne   $s1, $t2, .L7F008014
/* 03CB08 7F007FD8 01401025 */   move  $v0, $t2
/* 03CB0C 7F007FDC 3C018005 */  lui   $at, %hi(D_8004F2D0)
/* 03CB10 7F007FE0 C424F2D0 */  lwc1  $f4, %lo(D_8004F2D0)($at)
/* 03CB14 7F007FE4 3C014180 */  li    $at, 0x41800000 # 16.000000
/* 03CB18 7F007FE8 3C0B8007 */  lui   $t3, %hi(ptr_animation_table) 
/* 03CB1C 7F007FEC 8D6B9538 */  lw    $t3, %lo(ptr_animation_table)($t3)
/* 03CB20 7F007FF0 44813000 */  mtc1  $at, $f6
/* 03CB24 7F007FF4 8E640000 */  lw    $a0, ($s3)
/* 03CB28 7F007FF8 00003025 */  move  $a2, $zero
/* 03CB2C 7F007FFC 3C074000 */  lui   $a3, 0x4000
/* 03CB30 7F008000 E7A40010 */  swc1  $f4, 0x10($sp)
/* 03CB34 7F008004 028B2821 */  addu  $a1, $s4, $t3
/* 03CB38 7F008008 0FC1BF2A */  jal   modelSetAnimation
/* 03CB3C 7F00800C E7A60014 */   swc1  $f6, 0x14($sp)
/* 03CB40 7F008010 8E020000 */  lw    $v0, ($s0)
.L7F008014:
/* 03CB44 7F008014 240100D4 */  li    $at, 212
/* 03CB48 7F008018 14410005 */  bne   $v0, $at, .L7F008030
/* 03CB4C 7F00801C 3C053FCC */   lui   $a1, (0x3FCCCCCD >> 16) # lui $a1, 0x3fcc
/* 03CB50 7F008020 8E640000 */  lw    $a0, ($s3)
/* 03CB54 7F008024 34A5CCCD */  ori   $a1, (0x3FCCCCCD & 0xFFFF) # ori $a1, $a1, 0xcccd
/* 03CB58 7F008028 0FC1BF93 */  jal   modelSetAnimSpeed
/* 03CB5C 7F00802C 3C064100 */   lui   $a2, 0x4100
.L7F008030:
/* 03CB60 7F008030 8E640000 */  lw    $a0, ($s3)
/* 03CB64 7F008034 24050001 */  li    $a1, 1
/* 03CB68 7F008038 0FC1C2BB */  jal   modelTickAnimQuarterSpeed
/* 03CB6C 7F00803C 24060001 */   li    $a2, 1
/* 03CB70 7F008040 8E0C0000 */  lw    $t4, ($s0)
/* 03CB74 7F008044 240100E6 */  li    $at, 230
/* 03CB78 7F008048 3C048006 */  lui   $a0, %hi(g_musicSfxBufferPtr)
/* 03CB7C 7F00804C 15810005 */  bne   $t4, $at, .L7F008064
/* 03CB80 7F008050 2405006F */   li    $a1, 111
/* 03CB84 7F008054 8C843720 */  lw    $a0, %lo(g_musicSfxBufferPtr)($a0)
/* 03CB88 7F008058 00003025 */  move  $a2, $zero
/* 03CB8C 7F00805C 0C002382 */  jal   sndPlaySfx
/* 03CB90 7F008060 24150001 */   li    $s5, 1
.L7F008064:
/* 03CB94 7F008064 8FAD0124 */  lw    $t5, 0x124($sp)
/* 03CB98 7F008068 26520001 */  addiu $s2, $s2, 1
/* 03CB9C 7F00806C 564DFFD6 */  bnel  $s2, $t5, .L7F007FC8
/* 03CBA0 7F008070 8E020000 */   lw    $v0, ($s0)
/* 03CBA4 7F008074 00009025 */  move  $s2, $zero
.L7F008078:
/* 03CBA8 7F008078 3C138003 */  lui   $s3, %hi(chrModelInstance)
/* 03CBAC 7F00807C 2673A7F4 */  addiu $s3, %lo(chrModelInstance) # addiu $s3, $s3, -0x580c
/* 03CBB0 7F008080 0FC1B100 */  jal   modelSetDistanceDisabled
/* 03CBB4 7F008084 24040001 */   li    $a0, 1
/* 03CBB8 7F008088 0FC1CFF2 */  jal   sub_GAME_7F073FC8
/* 03CBBC 7F00808C 24040050 */   li    $a0, 80
/* 03CBC0 7F008090 0FC1B5AC */  jal   subcalcpos
/* 03CBC4 7F008094 8E640000 */   lw    $a0, ($s3)
/* 03CBC8 7F008098 3C148003 */  lui   $s4, %hi(gunModelInstance)
/* 03CBCC 7F00809C 2694A7F8 */  addiu $s4, %lo(gunModelInstance) # addiu $s4, $s4, -0x5808
/* 03CBD0 7F0080A0 8E860000 */  lw    $a2, ($s4)
/* 03CBD4 7F0080A4 8CD90008 */  lw    $t9, 8($a2)
/* 03CBD8 7F0080A8 8F230008 */  lw    $v1, 8($t9)
/* 03CBDC 7F0080AC 8C650000 */  lw    $a1, ($v1)
/* 03CBE0 7F0080B0 50A00008 */  beql  $a1, $zero, .L7F0080D4
/* 03CBE4 7F0080B4 8C650008 */   lw    $a1, 8($v1)
/* 03CBE8 7F0080B8 0FC1B1E7 */  jal   modelGetNodeRwData
/* 03CBEC 7F0080BC 00C02025 */   move  $a0, $a2
/* 03CBF0 7F0080C0 A4550000 */  sh    $s5, ($v0)
/* 03CBF4 7F0080C4 8E860000 */  lw    $a2, ($s4)
/* 03CBF8 7F0080C8 8CD80008 */  lw    $t8, 8($a2)
/* 03CBFC 7F0080CC 8F030008 */  lw    $v1, 8($t8)
/* 03CC00 7F0080D0 8C650008 */  lw    $a1, 8($v1)
.L7F0080D4:
/* 03CC04 7F0080D4 50A00005 */  beql  $a1, $zero, .L7F0080EC
/* 03CC08 7F0080D8 8FA80128 */   lw    $t0, 0x128($sp)
/* 03CC0C 7F0080DC 0FC1B1E7 */  jal   modelGetNodeRwData
/* 03CC10 7F0080E0 00C02025 */   move  $a0, $a2
/* 03CC14 7F0080E4 AC550000 */  sw    $s5, ($v0)
/* 03CC18 7F0080E8 8FA80128 */  lw    $t0, 0x128($sp)
.L7F0080EC:
/* 03CC1C 7F0080EC 8E6F0000 */  lw    $t7, ($s3)
/* 03CC20 7F0080F0 AFA800DC */  sw    $t0, 0xdc($sp)
/* 03CC24 7F0080F4 8DEE0008 */  lw    $t6, 8($t7)
/* 03CC28 7F0080F8 85C4000E */  lh    $a0, 0xe($t6)
/* 03CC2C 7F0080FC 00044980 */  sll   $t1, $a0, 6
/* 03CC30 7F008100 0FC2F5C5 */  jal   dynAllocate
/* 03CC34 7F008104 01202025 */   move  $a0, $t1
/* 03CC38 7F008108 AFA200EC */  sw    $v0, 0xec($sp)
/* 03CC3C 7F00810C 27A400DC */  addiu $a0, $sp, 0xdc
/* 03CC40 7F008110 0FC1BCBE */  jal   subcalcmatrices
/* 03CC44 7F008114 8E650000 */   lw    $a1, ($s3)
/* 03CC48 7F008118 8E8A0000 */  lw    $t2, ($s4)
/* 03CC4C 7F00811C 8E640000 */  lw    $a0, ($s3)
/* 03CC50 7F008120 00003025 */  move  $a2, $zero
/* 03CC54 7F008124 0FC1B198 */  jal   modelFindNodeMtx
/* 03CC58 7F008128 8D45001C */   lw    $a1, 0x1c($t2)
/* 03CC5C 7F00812C 8E8B0000 */  lw    $t3, ($s4)
/* 03CC60 7F008130 AFA200DC */  sw    $v0, 0xdc($sp)
/* 03CC64 7F008134 8D6C0008 */  lw    $t4, 8($t3)
/* 03CC68 7F008138 8584000E */  lh    $a0, 0xe($t4)
/* 03CC6C 7F00813C 00046980 */  sll   $t5, $a0, 6
/* 03CC70 7F008140 0FC2F5C5 */  jal   dynAllocate
/* 03CC74 7F008144 01A02025 */   move  $a0, $t5
/* 03CC78 7F008148 AFA200EC */  sw    $v0, 0xec($sp)
/* 03CC7C 7F00814C 27A400DC */  addiu $a0, $sp, 0xdc
/* 03CC80 7F008150 0FC1BC92 */  jal   instcalcmatrices
/* 03CC84 7F008154 8E850000 */   lw    $a1, ($s4)
/* 03CC88 7F008158 00002025 */  move  $a0, $zero
/* 03CC8C 7F00815C 0FC1AC48 */  jal   sub_GAME_7F06B120
/* 03CC90 7F008160 8E650000 */   lw    $a1, ($s3)
/* 03CC94 7F008164 00402025 */  move  $a0, $v0
/* 03CC98 7F008168 0FC1AC48 */  jal   sub_GAME_7F06B120
/* 03CC9C 7F00816C 8E850000 */   lw    $a1, ($s4)
/* 03CCA0 7F008170 00408025 */  move  $s0, $v0
/* 03CCA4 7F008174 0FC1ACA7 */  jal   sub_GAME_7F06B29C
/* 03CCA8 7F008178 00402025 */   move  $a0, $v0
/* 03CCAC 7F00817C 0FC1AECA */  jal   sub_GAME_7F06BB28
/* 03CCB0 7F008180 02002025 */   move  $a0, $s0
/* 03CCB4 7F008184 8FB80120 */  lw    $t8, 0x120($sp)
/* 03CCB8 7F008188 24190007 */  li    $t9, 7
/* 03CCBC 7F00818C 24080001 */  li    $t0, 1
/* 03CCC0 7F008190 00408025 */  move  $s0, $v0
/* 03CCC4 7F008194 AFB9010C */  sw    $t9, 0x10c($sp)
/* 03CCC8 7F008198 AFA000E0 */  sw    $zero, 0xe0($sp)
/* 03CCCC 7F00819C AFA800E4 */  sw    $t0, 0xe4($sp)
/* 03CCD0 7F0081A0 27A400DC */  addiu $a0, $sp, 0xdc
/* 03CCD4 7F0081A4 00402825 */  move  $a1, $v0
/* 03CCD8 7F0081A8 0FC1AF03 */  jal   drawjointlist
/* 03CCDC 7F0081AC AFB800E8 */   sw    $t8, 0xe8($sp)
/* 03CCE0 7F0081B0 240F0002 */  li    $t7, 2
/* 03CCE4 7F0081B4 AFAF00E4 */  sw    $t7, 0xe4($sp)
/* 03CCE8 7F0081B8 27A400DC */  addiu $a0, $sp, 0xdc
/* 03CCEC 7F0081BC 0FC1AF03 */  jal   drawjointlist
/* 03CCF0 7F0081C0 02002825 */   move  $a1, $s0
/* 03CCF4 7F0081C4 0FC1B100 */  jal   modelSetDistanceDisabled
/* 03CCF8 7F0081C8 00002025 */   move  $a0, $zero
/* 03CCFC 7F0081CC 0FC1AC92 */  jal   sub_GAME_7F06B248
/* 03CD00 7F0081D0 02002025 */   move  $a0, $s0
/* 03CD04 7F0081D4 8E620000 */  lw    $v0, ($s3)
/* 03CD08 7F0081D8 00008025 */  move  $s0, $zero
/* 03CD0C 7F0081DC 27B10088 */  addiu $s1, $sp, 0x88
/* 03CD10 7F0081E0 8C4E0008 */  lw    $t6, 8($v0)
/* 03CD14 7F0081E4 85C9000E */  lh    $t1, 0xe($t6)
/* 03CD18 7F0081E8 59200015 */  blezl $t1, .L7F008240
/* 03CD1C 7F0081EC 8E860000 */   lw    $a2, ($s4)
/* 03CD20 7F0081F0 8C4A000C */  lw    $t2, 0xc($v0)
.L7F0081F4:
/* 03CD24 7F0081F4 02202825 */  move  $a1, $s1
/* 03CD28 7F0081F8 0FC16008 */  jal   matrix_4x4_copy
/* 03CD2C 7F0081FC 01502021 */   addu  $a0, $t2, $s0
/* 03CD30 7F008200 8E6B0000 */  lw    $t3, ($s3)
/* 03CD34 7F008204 00126980 */  sll   $t5, $s2, 6
/* 03CD38 7F008208 02202025 */  move  $a0, $s1
/* 03CD3C 7F00820C 8D6C000C */  lw    $t4, 0xc($t3)
/* 03CD40 7F008210 0FC16327 */  jal   matrix_4x4_f32_to_s32
/* 03CD44 7F008214 018D2821 */   addu  $a1, $t4, $t5
/* 03CD48 7F008218 8E620000 */  lw    $v0, ($s3)
/* 03CD4C 7F00821C 26520001 */  addiu $s2, $s2, 1
/* 03CD50 7F008220 26100040 */  addiu $s0, $s0, 0x40
/* 03CD54 7F008224 8C590008 */  lw    $t9, 8($v0)
/* 03CD58 7F008228 8738000E */  lh    $t8, 0xe($t9)
/* 03CD5C 7F00822C 0258082A */  slt   $at, $s2, $t8
/* 03CD60 7F008230 5420FFF0 */  bnezl $at, .L7F0081F4
/* 03CD64 7F008234 8C4A000C */   lw    $t2, 0xc($v0)
/* 03CD68 7F008238 00009025 */  move  $s2, $zero
/* 03CD6C 7F00823C 8E860000 */  lw    $a2, ($s4)
.L7F008240:
/* 03CD70 7F008240 00008025 */  move  $s0, $zero
/* 03CD74 7F008244 27B10048 */  addiu $s1, $sp, 0x48
/* 03CD78 7F008248 8CC80008 */  lw    $t0, 8($a2)
/* 03CD7C 7F00824C 850F000E */  lh    $t7, 0xe($t0)
/* 03CD80 7F008250 59E00014 */  blezl $t7, .L7F0082A4
/* 03CD84 7F008254 8FBF0034 */   lw    $ra, 0x34($sp)
/* 03CD88 7F008258 8CCE000C */  lw    $t6, 0xc($a2)
.L7F00825C:
/* 03CD8C 7F00825C 02202825 */  move  $a1, $s1
/* 03CD90 7F008260 0FC16008 */  jal   matrix_4x4_copy
/* 03CD94 7F008264 01D02021 */   addu  $a0, $t6, $s0
/* 03CD98 7F008268 8E890000 */  lw    $t1, ($s4)
/* 03CD9C 7F00826C 00125980 */  sll   $t3, $s2, 6
/* 03CDA0 7F008270 02202025 */  move  $a0, $s1
/* 03CDA4 7F008274 8D2A000C */  lw    $t2, 0xc($t1)
/* 03CDA8 7F008278 0FC16327 */  jal   matrix_4x4_f32_to_s32
/* 03CDAC 7F00827C 014B2821 */   addu  $a1, $t2, $t3
/* 03CDB0 7F008280 8E860000 */  lw    $a2, ($s4)
/* 03CDB4 7F008284 26520001 */  addiu $s2, $s2, 1
/* 03CDB8 7F008288 26100040 */  addiu $s0, $s0, 0x40
/* 03CDBC 7F00828C 8CCC0008 */  lw    $t4, 8($a2)
/* 03CDC0 7F008290 858D000E */  lh    $t5, 0xe($t4)
/* 03CDC4 7F008294 024D082A */  slt   $at, $s2, $t5
/* 03CDC8 7F008298 5420FFF0 */  bnezl $at, .L7F00825C
/* 03CDCC 7F00829C 8CCE000C */   lw    $t6, 0xc($a2)
/* 03CDD0 7F0082A0 8FBF0034 */  lw    $ra, 0x34($sp)
.L7F0082A4:
/* 03CDD4 7F0082A4 8FA200E8 */  lw    $v0, 0xe8($sp)
/* 03CDD8 7F0082A8 8FB0001C */  lw    $s0, 0x1c($sp)
/* 03CDDC 7F0082AC 8FB10020 */  lw    $s1, 0x20($sp)
/* 03CDE0 7F0082B0 8FB20024 */  lw    $s2, 0x24($sp)
/* 03CDE4 7F0082B4 8FB30028 */  lw    $s3, 0x28($sp)
/* 03CDE8 7F0082B8 8FB4002C */  lw    $s4, 0x2c($sp)
/* 03CDEC 7F0082BC 8FB50030 */  lw    $s5, 0x30($sp)
/* 03CDF0 7F0082C0 03E00008 */  jr    $ra
/* 03CDF4 7F0082C4 27BD0120 */   addiu $sp, $sp, 0x120
)
#endif

#if !defined(LEFTOVERDEBUG)
GLOBAL_ASM(
.late_rodata
glabel D_80047720
.word 0x3f68f5c3
.text
glabel sub_GAME_7F007F30
/* 03A8A0 7F007EB0 27BDFEE0 */  addiu $sp, $sp, -0x120
/* 03A8A4 7F007EB4 3C0F8002 */  lui   $t7, %hi(D_8002A7FC) # $t7, 0x8002
/* 03A8A8 7F007EB8 25EF5D4C */  addiu $t7, %lo(D_8002A7FC) # addiu $t7, $t7, 0x5d4c
/* 03A8AC 7F007EBC AFBF0034 */  sw    $ra, 0x34($sp)
/* 03A8B0 7F007EC0 AFB50030 */  sw    $s5, 0x30($sp)
/* 03A8B4 7F007EC4 AFB4002C */  sw    $s4, 0x2c($sp)
/* 03A8B8 7F007EC8 AFB30028 */  sw    $s3, 0x28($sp)
/* 03A8BC 7F007ECC AFB20024 */  sw    $s2, 0x24($sp)
/* 03A8C0 7F007ED0 AFB10020 */  sw    $s1, 0x20($sp)
/* 03A8C4 7F007ED4 AFB0001C */  sw    $s0, 0x1c($sp)
/* 03A8C8 7F007ED8 AFA40120 */  sw    $a0, 0x120($sp)
/* 03A8CC 7F007EDC AFA50124 */  sw    $a1, 0x124($sp)
/* 03A8D0 7F007EE0 AFA60128 */  sw    $a2, 0x128($sp)
/* 03A8D4 7F007EE4 25E8003C */  addiu $t0, $t7, 0x3c
/* 03A8D8 7F007EE8 27AE00DC */  addiu $t6, $sp, 0xdc
.L7F007EEC:
/* 03A8DC 7F007EEC 8DE10000 */  lw    $at, ($t7)
/* 03A8E0 7F007EF0 25EF000C */  addiu $t7, $t7, 0xc
/* 03A8E4 7F007EF4 25CE000C */  addiu $t6, $t6, 0xc
/* 03A8E8 7F007EF8 ADC1FFF4 */  sw    $at, -0xc($t6)
/* 03A8EC 7F007EFC 8DE1FFF8 */  lw    $at, -8($t7)
/* 03A8F0 7F007F00 ADC1FFF8 */  sw    $at, -8($t6)
/* 03A8F4 7F007F04 8DE1FFFC */  lw    $at, -4($t7)
/* 03A8F8 7F007F08 15E8FFF8 */  bne   $t7, $t0, .L7F007EEC
/* 03A8FC 7F007F0C ADC1FFFC */   sw    $at, -4($t6)
/* 03A900 7F007F10 8DE10000 */  lw    $at, ($t7)
/* 03A904 7F007F14 0000A825 */  move  $s5, $zero
/* 03A908 7F007F18 00009025 */  move  $s2, $zero
/* 03A90C 7F007F1C ADC10000 */  sw    $at, ($t6)
/* 03A910 7F007F20 8FA90124 */  lw    $t1, 0x124($sp)
/* 03A914 7F007F24 19200034 */  blez  $t1, .L7F007FF8
/* 03A918 7F007F28 3C140000 */   lui   $s4, 0 # $s4, 0
/* 03A91C 7F007F2C 3C138002 */  lui   $s3, %hi(chrModelInstance) # $s3, 0x8002
/* 03A920 7F007F30 3C108006 */  lui   $s0, %hi(dword_CODE_bss_80069594) # $s0, 0x8006
/* 03A924 7F007F34 261084D4 */  addiu $s0, %lo(dword_CODE_bss_80069594) # addiu $s0, $s0, -0x7b2c
/* 03A928 7F007F38 26735D44 */  addiu $s3, %lo(chrModelInstance) # addiu $s3, $s3, 0x5d44
/* 03A92C 7F007F3C 26944298 */  addiu $s4, 0x4298 # addiu $s4, $s4, 0x4298
/* 03A930 7F007F40 24110072 */  li    $s1, 114
/* 03A934 7F007F44 8E020000 */  lw    $v0, ($s0)
.L7F007F48:
/* 03A938 7F007F48 04400019 */  bltz  $v0, .L7F007FB0
/* 03A93C 7F007F4C 244A0001 */   addiu $t2, $v0, 1
/* 03A940 7F007F50 AE0A0000 */  sw    $t2, ($s0)
/* 03A944 7F007F54 162A000F */  bne   $s1, $t2, .L7F007F94
/* 03A948 7F007F58 01401025 */   move  $v0, $t2
/* 03A94C 7F007F5C 3C018004 */  lui   $at, %hi(D_80047720) # $at, 0x8004
/* 03A950 7F007F60 C4247720 */  lwc1  $f4, %lo(D_80047720)($at)
/* 03A954 7F007F64 3C014180 */  li    $at, 0x41800000 # 16.000000
/* 03A958 7F007F68 3C0B8006 */  lui   $t3, %hi(ptr_animation_table) # $t3, 0x8006
/* 03A95C 7F007F6C 8D6B8478 */  lw    $t3, %lo(ptr_animation_table)($t3)
/* 03A960 7F007F70 44813000 */  mtc1  $at, $f6
/* 03A964 7F007F74 8E640000 */  lw    $a0, ($s3)
/* 03A968 7F007F78 00003025 */  move  $a2, $zero
/* 03A96C 7F007F7C 3C074000 */  lui   $a3, 0x4000
/* 03A970 7F007F80 E7A40010 */  swc1  $f4, 0x10($sp)
/* 03A974 7F007F84 028B2821 */  addu  $a1, $s4, $t3
/* 03A978 7F007F88 0FC1BF92 */  jal   modelSetAnimation
/* 03A97C 7F007F8C E7A60014 */   swc1  $f6, 0x14($sp)
/* 03A980 7F007F90 8E020000 */  lw    $v0, ($s0)
.L7F007F94:
/* 03A984 7F007F94 240100B0 */  li    $at, 176
/* 03A988 7F007F98 14410005 */  bne   $v0, $at, .L7F007FB0
/* 03A98C 7F007F9C 3C053FCC */   lui   $a1, (0x3FCCCCCD >> 16) # lui $a1, 0x3fcc
/* 03A990 7F007FA0 8E640000 */  lw    $a0, ($s3)
/* 03A994 7F007FA4 34A5CCCD */  ori   $a1, (0x3FCCCCCD & 0xFFFF) # ori $a1, $a1, 0xcccd
/* 03A998 7F007FA8 0FC1BFFB */  jal   modelSetAnimSpeed
/* 03A99C 7F007FAC 3C064100 */   lui   $a2, 0x4100
.L7F007FB0:
/* 03A9A0 7F007FB0 8E640000 */  lw    $a0, ($s3)
/* 03A9A4 7F007FB4 24050001 */  li    $a1, 1
/* 03A9A8 7F007FB8 0FC1C323 */  jal   modelTickAnimQuarterSpeed
/* 03A9AC 7F007FBC 24060001 */   li    $a2, 1
/* 03A9B0 7F007FC0 8E0C0000 */  lw    $t4, ($s0)
/* 03A9B4 7F007FC4 240100BF */  li    $at, 191
/* 03A9B8 7F007FC8 3C048005 */  lui   $a0, %hi(g_musicSfxBufferPtr) # $a0, 0x8005
/* 03A9BC 7F007FCC 15810005 */  bne   $t4, $at, .L7F007FE4
/* 03A9C0 7F007FD0 2405006F */   li    $a1, 111
/* 03A9C4 7F007FD4 8C846900 */  lw    $a0, %lo(g_musicSfxBufferPtr)($a0)
/* 03A9C8 7F007FD8 00003025 */  move  $a2, $zero
/* 03A9CC 7F007FDC 0C00209A */  jal   sndPlaySfx
/* 03A9D0 7F007FE0 24150001 */   li    $s5, 1
.L7F007FE4:
/* 03A9D4 7F007FE4 8FAD0124 */  lw    $t5, 0x124($sp)
/* 03A9D8 7F007FE8 26520001 */  addiu $s2, $s2, 1
/* 03A9DC 7F007FEC 564DFFD6 */  bnel  $s2, $t5, .L7F007F48
/* 03A9E0 7F007FF0 8E020000 */   lw    $v0, ($s0)
/* 03A9E4 7F007FF4 00009025 */  move  $s2, $zero
.L7F007FF8:
/* 03A9E8 7F007FF8 3C138002 */  lui   $s3, %hi(chrModelInstance) # $s3, 0x8002
/* 03A9EC 7F007FFC 26735D44 */  addiu $s3, %lo(chrModelInstance) # addiu $s3, $s3, 0x5d44
/* 03A9F0 7F008000 0FC1B2D0 */  jal   modelSetDistanceDisabled
/* 03A9F4 7F008004 24040001 */   li    $a0, 1
/* 03A9F8 7F008008 0FC1D037 */  jal   sub_GAME_7F073FC8
/* 03A9FC 7F00800C 24040050 */   li    $a0, 80
/* 03AA00 7F008010 0FC1B6B8 */  jal   subcalcpos
/* 03AA04 7F008014 8E640000 */   lw    $a0, ($s3)
/* 03AA08 7F008018 3C148002 */  lui   $s4, %hi(gunModelInstance) # $s4, 0x8002
/* 03AA0C 7F00801C 26945D48 */  addiu $s4, %lo(gunModelInstance) # addiu $s4, $s4, 0x5d48
/* 03AA10 7F008020 8E860000 */  lw    $a2, ($s4)
/* 03AA14 7F008024 8CD90008 */  lw    $t9, 8($a2)
/* 03AA18 7F008028 8F230008 */  lw    $v1, 8($t9)
/* 03AA1C 7F00802C 8C650000 */  lw    $a1, ($v1)
/* 03AA20 7F008030 50A00008 */  beql  $a1, $zero, .L7F008054
/* 03AA24 7F008034 8C650008 */   lw    $a1, 8($v1)
/* 03AA28 7F008038 0FC1B3A3 */  jal   modelGetNodeRwData
/* 03AA2C 7F00803C 00C02025 */   move  $a0, $a2
/* 03AA30 7F008040 A4550000 */  sh    $s5, ($v0)
/* 03AA34 7F008044 8E860000 */  lw    $a2, ($s4)
/* 03AA38 7F008048 8CD80008 */  lw    $t8, 8($a2)
/* 03AA3C 7F00804C 8F030008 */  lw    $v1, 8($t8)
/* 03AA40 7F008050 8C650008 */  lw    $a1, 8($v1)
.L7F008054:
/* 03AA44 7F008054 50A00005 */  beql  $a1, $zero, .L7F00806C
/* 03AA48 7F008058 8FA80128 */   lw    $t0, 0x128($sp)
/* 03AA4C 7F00805C 0FC1B3A3 */  jal   modelGetNodeRwData
/* 03AA50 7F008060 00C02025 */   move  $a0, $a2
/* 03AA54 7F008064 AC550000 */  sw    $s5, ($v0)
/* 03AA58 7F008068 8FA80128 */  lw    $t0, 0x128($sp)
.L7F00806C:
/* 03AA5C 7F00806C 8E6F0000 */  lw    $t7, ($s3)
/* 03AA60 7F008070 AFA800DC */  sw    $t0, 0xdc($sp)
/* 03AA64 7F008074 8DEE0008 */  lw    $t6, 8($t7)
/* 03AA68 7F008078 85C4000E */  lh    $a0, 0xe($t6)
/* 03AA6C 7F00807C 00044980 */  sll   $t1, $a0, 6
/* 03AA70 7F008080 0FC2F2B1 */  jal   dynAllocate
/* 03AA74 7F008084 01202025 */   move  $a0, $t1
/* 03AA78 7F008088 AFA200EC */  sw    $v0, 0xec($sp)
/* 03AA7C 7F00808C 27A400DC */  addiu $a0, $sp, 0xdc
/* 03AA80 7F008090 0FC1BD9C */  jal   subcalcmatrices
/* 03AA84 7F008094 8E650000 */   lw    $a1, ($s3)
/* 03AA88 7F008098 8E8A0000 */  lw    $t2, ($s4)
/* 03AA8C 7F00809C 8E640000 */  lw    $a0, ($s3)
/* 03AA90 7F0080A0 00003025 */  move  $a2, $zero
/* 03AA94 7F0080A4 0FC1B366 */  jal   modelFindNodeMtx
/* 03AA98 7F0080A8 8D45001C */   lw    $a1, 0x1c($t2)
/* 03AA9C 7F0080AC 8E8B0000 */  lw    $t3, ($s4)
/* 03AAA0 7F0080B0 AFA200DC */  sw    $v0, 0xdc($sp)
/* 03AAA4 7F0080B4 8D6C0008 */  lw    $t4, 8($t3)
/* 03AAA8 7F0080B8 8584000E */  lh    $a0, 0xe($t4)
/* 03AAAC 7F0080BC 00046980 */  sll   $t5, $a0, 6
/* 03AAB0 7F0080C0 0FC2F2B1 */  jal   dynAllocate
/* 03AAB4 7F0080C4 01A02025 */   move  $a0, $t5
/* 03AAB8 7F0080C8 AFA200EC */  sw    $v0, 0xec($sp)
/* 03AABC 7F0080CC 27A400DC */  addiu $a0, $sp, 0xdc
/* 03AAC0 7F0080D0 0FC1BD8D */  jal   instcalcmatrices
/* 03AAC4 7F0080D4 8E850000 */   lw    $a1, ($s4)
/* 03AAC8 7F0080D8 00002025 */  move  $a0, $zero
/* 03AACC 7F0080DC 0FC1AE34 */  jal   sub_GAME_7F06B120
/* 03AAD0 7F0080E0 8E650000 */   lw    $a1, ($s3)
/* 03AAD4 7F0080E4 00402025 */  move  $a0, $v0
/* 03AAD8 7F0080E8 0FC1AE34 */  jal   sub_GAME_7F06B120
/* 03AADC 7F0080EC 8E850000 */   lw    $a1, ($s4)
/* 03AAE0 7F0080F0 00408025 */  move  $s0, $v0
/* 03AAE4 7F0080F4 0FC1AE93 */  jal   sub_GAME_7F06B29C
/* 03AAE8 7F0080F8 00402025 */   move  $a0, $v0
/* 03AAEC 7F0080FC 0FC1B0B6 */  jal   sub_GAME_7F06BB28
/* 03AAF0 7F008100 02002025 */   move  $a0, $s0
/* 03AAF4 7F008104 8FB80120 */  lw    $t8, 0x120($sp)
/* 03AAF8 7F008108 24190007 */  li    $t9, 7
/* 03AAFC 7F00810C 24080001 */  li    $t0, 1
/* 03AB00 7F008110 00408025 */  move  $s0, $v0
/* 03AB04 7F008114 AFB9010C */  sw    $t9, 0x10c($sp)
/* 03AB08 7F008118 AFA000E0 */  sw    $zero, 0xe0($sp)
/* 03AB0C 7F00811C AFA800E4 */  sw    $t0, 0xe4($sp)
/* 03AB10 7F008120 27A400DC */  addiu $a0, $sp, 0xdc
/* 03AB14 7F008124 00402825 */  move  $a1, $v0
/* 03AB18 7F008128 0FC1B0EF */  jal   drawjointlist
/* 03AB1C 7F00812C AFB800E8 */   sw    $t8, 0xe8($sp)
/* 03AB20 7F008130 240F0002 */  li    $t7, 2
/* 03AB24 7F008134 AFAF00E4 */  sw    $t7, 0xe4($sp)
/* 03AB28 7F008138 27A400DC */  addiu $a0, $sp, 0xdc
/* 03AB2C 7F00813C 0FC1B0EF */  jal   drawjointlist
/* 03AB30 7F008140 02002825 */   move  $a1, $s0
/* 03AB34 7F008144 0FC1B2D0 */  jal   modelSetDistanceDisabled
/* 03AB38 7F008148 00002025 */   move  $a0, $zero
/* 03AB3C 7F00814C 0FC1AE7E */  jal   sub_GAME_7F06B248
/* 03AB40 7F008150 02002025 */   move  $a0, $s0
/* 03AB44 7F008154 8E620000 */  lw    $v0, ($s3)
/* 03AB48 7F008158 00008025 */  move  $s0, $zero
/* 03AB4C 7F00815C 27B10088 */  addiu $s1, $sp, 0x88
/* 03AB50 7F008160 8C4E0008 */  lw    $t6, 8($v0)
/* 03AB54 7F008164 85C9000E */  lh    $t1, 0xe($t6)
/* 03AB58 7F008168 59200015 */  blezl $t1, .L7F0081C0
/* 03AB5C 7F00816C 8E860000 */   lw    $a2, ($s4)
/* 03AB60 7F008170 8C4A000C */  lw    $t2, 0xc($v0)
.L7F008174:
/* 03AB64 7F008174 02202825 */  move  $a1, $s1
/* 03AB68 7F008178 0FC16132 */  jal   matrix_4x4_copy
/* 03AB6C 7F00817C 01502021 */   addu  $a0, $t2, $s0
/* 03AB70 7F008180 8E6B0000 */  lw    $t3, ($s3)
/* 03AB74 7F008184 00126980 */  sll   $t5, $s2, 6
/* 03AB78 7F008188 02202025 */  move  $a0, $s1
/* 03AB7C 7F00818C 8D6C000C */  lw    $t4, 0xc($t3)
/* 03AB80 7F008190 0FC16451 */  jal   matrix_4x4_f32_to_s32
/* 03AB84 7F008194 018D2821 */   addu  $a1, $t4, $t5
/* 03AB88 7F008198 8E620000 */  lw    $v0, ($s3)
/* 03AB8C 7F00819C 26520001 */  addiu $s2, $s2, 1
/* 03AB90 7F0081A0 26100040 */  addiu $s0, $s0, 0x40
/* 03AB94 7F0081A4 8C590008 */  lw    $t9, 8($v0)
/* 03AB98 7F0081A8 8738000E */  lh    $t8, 0xe($t9)
/* 03AB9C 7F0081AC 0258082A */  slt   $at, $s2, $t8
/* 03ABA0 7F0081B0 5420FFF0 */  bnezl $at, .L7F008174
/* 03ABA4 7F0081B4 8C4A000C */   lw    $t2, 0xc($v0)
/* 03ABA8 7F0081B8 00009025 */  move  $s2, $zero
/* 03ABAC 7F0081BC 8E860000 */  lw    $a2, ($s4)
.L7F0081C0:
/* 03ABB0 7F0081C0 00008025 */  move  $s0, $zero
/* 03ABB4 7F0081C4 27B10048 */  addiu $s1, $sp, 0x48
/* 03ABB8 7F0081C8 8CC80008 */  lw    $t0, 8($a2)
/* 03ABBC 7F0081CC 850F000E */  lh    $t7, 0xe($t0)
/* 03ABC0 7F0081D0 59E00014 */  blezl $t7, .L7F008224
/* 03ABC4 7F0081D4 8FBF0034 */   lw    $ra, 0x34($sp)
/* 03ABC8 7F0081D8 8CCE000C */  lw    $t6, 0xc($a2)
.L7F0081DC:
/* 03ABCC 7F0081DC 02202825 */  move  $a1, $s1
/* 03ABD0 7F0081E0 0FC16132 */  jal   matrix_4x4_copy
/* 03ABD4 7F0081E4 01D02021 */   addu  $a0, $t6, $s0
/* 03ABD8 7F0081E8 8E890000 */  lw    $t1, ($s4)
/* 03ABDC 7F0081EC 00125980 */  sll   $t3, $s2, 6
/* 03ABE0 7F0081F0 02202025 */  move  $a0, $s1
/* 03ABE4 7F0081F4 8D2A000C */  lw    $t2, 0xc($t1)
/* 03ABE8 7F0081F8 0FC16451 */  jal   matrix_4x4_f32_to_s32
/* 03ABEC 7F0081FC 014B2821 */   addu  $a1, $t2, $t3
/* 03ABF0 7F008200 8E860000 */  lw    $a2, ($s4)
/* 03ABF4 7F008204 26520001 */  addiu $s2, $s2, 1
/* 03ABF8 7F008208 26100040 */  addiu $s0, $s0, 0x40
/* 03ABFC 7F00820C 8CCC0008 */  lw    $t4, 8($a2)
/* 03AC00 7F008210 858D000E */  lh    $t5, 0xe($t4)
/* 03AC04 7F008214 024D082A */  slt   $at, $s2, $t5
/* 03AC08 7F008218 5420FFF0 */  bnezl $at, .L7F0081DC
/* 03AC0C 7F00821C 8CCE000C */   lw    $t6, 0xc($a2)
/* 03AC10 7F008220 8FBF0034 */  lw    $ra, 0x34($sp)
.L7F008224:
/* 03AC14 7F008224 8FA200E8 */  lw    $v0, 0xe8($sp)
/* 03AC18 7F008228 8FB0001C */  lw    $s0, 0x1c($sp)
/* 03AC1C 7F00822C 8FB10020 */  lw    $s1, 0x20($sp)
/* 03AC20 7F008230 8FB20024 */  lw    $s2, 0x24($sp)
/* 03AC24 7F008234 8FB30028 */  lw    $s3, 0x28($sp)
/* 03AC28 7F008238 8FB4002C */  lw    $s4, 0x2c($sp)
/* 03AC2C 7F00823C 8FB50030 */  lw    $s5, 0x30($sp)
/* 03AC30 7F008240 03E00008 */  jr    $ra
/* 03AC34 7F008244 27BD0120 */   addiu $sp, $sp, 0x120
)
#endif

#endif

Gfx *insert_bond_eye_intro(Gfx *gdl) {
    Mtxf matrix;
    u16 perspNorm;
    guTranslate(&matrixBufferIntroBackdrop[D_8002A7D0], 0.0f, 0.0f, 0.0f);
    guPerspective(&matrixBufferIntroBond[D_8002A7D0], &perspNorm, 46.0f, (320.0f / 240.0f), 10.0f, 10000.0f, 1.0f);
    gSPPerspNormalize(gdl++, perspNorm);
    gDPSetCombineMode(gdl++, G_CC_SHADE, G_CC_SHADE);
    gDPSetRenderMode(gdl++, G_RM_AA_OPA_SURF, G_RM_AA_OPA_SURF2);
    gSPMatrix(gdl++, osVirtualToPhysical(&matrixBufferIntroBond[D_8002A7D0]), (G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION));
    gSPMatrix(gdl++, osVirtualToPhysical(&matrixBufferIntroBackdrop[D_8002A7D0]), (G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW));
    
    matrix_4x4_7F059694(&matrix, gunbarrelPosition1[0], gunbarrelPosition1[1], gunbarrelPosition1[2], (gunbarrelPosition1[0] + gunbarrelPosition2[0]), (gunbarrelPosition1[1] + gunbarrelPosition2[1]), (gunbarrelPosition1[2] + gunbarrelPosition2[2]), gunbarrelPosition3[0], gunbarrelPosition3[1], gunbarrelPosition3[2]);

#if defined REFRESH_PAL
    return sub_GAME_7F007F30(gdl, 1, &matrix);
#else
    return sub_GAME_7F007F30(gdl, 2, &matrix);
#endif
}

extern Gfx *D_020043E8;
extern Gfx *DL_RAREWARETEXT;
extern Gfx *D_02004758;
extern u8 *D_02004FE8;
extern u8 *D_02005FF0;
Gfx *load_display_rare_logo(Gfx *gdl, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    cameraPosition1[2] = arg3;
    gSPDisplayList(gdl++, &dlBasicGeometry);
    gdl = insert_imageDL(gdl);
    {
        u16 perspNorm;
        guPerspective(&matrixBufferRareLogo0[D_8002A7D0], &perspNorm, 60.0f, (320.0f / 240.0f), 100.0f, 5000.0f, 1.0f);
        gSPPerspNormalize(gdl++, perspNorm);
    }
    gSPMatrix(gdl++, osVirtualToPhysical(&matrixBufferRareLogo0[D_8002A7D0]), (G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION));
    gSPClearGeometryMode(gdl++, -1);
    gSPSetGeometryMode(gdl++, (G_SHADE | G_CULL_BACK | G_LIGHTING | G_TEXTURE_GEN | G_SHADING_SMOOTH));
    guLookAt(&matrixBufferRareLogo1[D_8002A7D0], cameraPosition1[0], cameraPosition1[1], cameraPosition1[2], (cameraPosition1[0] + cameraPosition2[0]), (cameraPosition1[1] + cameraPosition2[1]), (cameraPosition1[2] + cameraPosition2[2]), cameraPosition3[0], cameraPosition3[1], cameraPosition3[2]);
    gSPMatrix(gdl++,  osVirtualToPhysical(&matrixBufferRareLogo1[D_8002A7D0]), (G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW));
    guRotate(&matrixBufferRareLogo2[D_8002A7D0], D_8002A89C, 0.0f, 1.0f, 0.0f);
#if defined(REFRESH_PAL)
    D_8002A89C += 2.4f;
#else
    D_8002A89C += 2.0f;
#endif
    gSPMatrix(gdl++, osVirtualToPhysical(&matrixBufferRareLogo2[D_8002A7D0]), (G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW));
    gSPSetLights1(gdl++, gunbarrelLights);
    gunbarrelLights.a.l.col[0] = gunbarrelLights.a.l.col[1] = gunbarrelLights.a.l.col[2] = gunbarrelLights.a.l.colc[0] = gunbarrelLights.a.l.colc[1] = gunbarrelLights.a.l.colc[2] = arg4;
    gDPPipeSync(gdl++);
    gDPPipeSync(gdl++);
    gDPSetCombineMode(gdl++, G_CC_MODULATEI, G_CC_MODULATEI);
    gDPSetTexturePersp(gdl++, G_TP_PERSP);
    gDPSetTextureDetail(gdl++, G_TD_CLAMP);
    gDPSetTextureLOD(gdl++, G_TL_TILE);
    gDPSetTextureLUT(gdl++, G_TT_NONE);
    gDPSetTextureFilter(gdl++, G_TF_BILERP);
    gDPSetTextureConvert(gdl++, G_TC_FILT);
    gDPPipeSync(gdl++);
    gDPPipeSync(gdl++);
    gSPTexture(gdl++, 0x0800, 0x0800, 0, G_TX_RENDERTILE, G_ON);
    gDPLoadTextureBlock(gdl++, &D_02004FE8, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32, 0, (G_TX_NOMIRROR | G_TX_WRAP), (G_TX_NOMIRROR | G_TX_WRAP), 5, 5, G_TX_NOLOD, G_TX_NOLOD);
    gDPSetPrimColor(gdl++, 0, 0, arg4, arg4, arg4, 0xFF);
    gSPDisplayList(gdl++, &D_020043E8);
    gSPDisplayList(gdl++, &DL_RAREWARETEXT);
    gDPLoadTextureBlock(gdl++, &D_02005FF0, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32, 0, (G_TX_NOMIRROR | G_TX_WRAP), (G_TX_NOMIRROR | G_TX_WRAP), 5, 5, G_TX_NOLOD, G_TX_NOLOD);
    gDPSetPrimColor(gdl++, 0, 0, ((arg4 * 0xF0) / 0xFF), ((arg4 * 0xD0) / 0xFF), ((arg4 * 0xF0) / 0xFF), 0xFF);
    gSPDisplayList(gdl++, &D_02004758);

    return gdl;
}

extern void *_rarewarelogoSegmentRomStart;
extern void *_rarewarelogoSegmentStart;
extern void *_rarewarelogoSegmentEnd; 
void sub_GAME_7F008B58(s32 address, s32 size) {
    gunbarrel_mode = 0;
    g_TitleX = 880.0f;
    D_8002A89C = -40.0f;
    intro_eye_counter = 0;
    virtualaddress = address;
    romCopy(virtualaddress, &_rarewarelogoSegmentRomStart, ALIGN64_V2((u32)&_rarewarelogoSegmentEnd - (u32)&_rarewarelogoSegmentStart));
}

Gfx *retrieve_display_rareware_logo(Gfx *gdl)
{
#if defined(REFRESH_PAL)
#define RAREWARE_LOGO_DEN 58
#define RAREWARE_LOGO_SUB 33915
#define RAREWARE_LOGO_EYE_COUNT1 216
#define RAREWARE_LOGO_EYE_COUNT2 241
#else
#define RAREWARE_LOGO_DEN 70
#define RAREWARE_LOGO_SUB 40800
#define RAREWARE_LOGO_EYE_COUNT1 260
#define RAREWARE_LOGO_EYE_COUNT2 290
#endif

    D_8002A7D0 = (1 - D_8002A7D0);
    gSPSegment(gdl++, SPSEGMENT_GETITLE, osVirtualToPhysical(virtualaddress));
    if ((gunbarrel_mode == 0) || (gunbarrel_mode == 1)) {
        s32 var1;
        s32 var2;
        var1 = (intro_eye_counter * 255) / RAREWARE_LOGO_DEN;
        if (var1 > 255) {
            var1 = 255;
        }
        if (var1 < 0) {
            var1 = 0;
        }

        var2 = 255 - (((intro_eye_counter * 255) - RAREWARE_LOGO_SUB) / RAREWARE_LOGO_DEN);
        if (var2 > 255) {
            var2 = 255;
        }
        if (var2 < 0) {
            var2 = 0;
        }
        gdl = load_display_rare_logo(gdl, 403, 488, g_TitleX, (var1 * var2) / 255);
        if (intro_eye_counter++ >= RAREWARE_LOGO_EYE_COUNT1) {
            if (intro_eye_counter >= RAREWARE_LOGO_EYE_COUNT2) {
                intro_eye_counter = 0;
                gunbarrel_mode++;
                gunbarrel_mode++;
            }
        }
    }

    return gdl;
}

s32 isGunBarrelInMode2(void) {
    return (gunbarrel_mode == 2);
}

#ifdef NONMATCHING
// Minor reordering + regalloc
void sub_GAME_7F01B0E0(s32, s32);
extern void *unknown2;
extern void *unknown2_end;
void sub_GAME_7F008DE4(u8 **addr, s32 *size) {
    dword_CODE_bss_8006958C = *addr;
    *size -= 0x40400;
    *addr += 0x40400;
    dword_CODE_bss_80069588 = *addr;
    romCopy(dword_CODE_bss_80069588, &unknown2, ALIGN64_V2(((u32)&unknown2_end - (u32)&unknown2)));
    sub_GAME_7F01B0E0(dword_CODE_bss_80069588, dword_CODE_bss_8006958C);
}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F008DE4
/* 03D914 7F008DE4 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 03D918 7F008DE8 AFBF0014 */  sw    $ra, 0x14($sp)
/* 03D91C 7F008DEC AFA5001C */  sw    $a1, 0x1c($sp)
/* 03D920 7F008DF0 8C8E0000 */  lw    $t6, ($a0)
/* 03D924 7F008DF4 3C018007 */  lui   $at, %hi(dword_CODE_bss_8006958C)
/* 03D928 7F008DF8 3C03002A */  lui   $v1, %hi(unknown2) # $v1, 0x2a
/* 03D92C 7F008DFC AC2E958C */  sw    $t6, %lo(dword_CODE_bss_8006958C)($at)
/* 03D930 7F008E00 8CB80000 */  lw    $t8, ($a1)
/* 03D934 7F008E04 3C01FFFB */  lui   $at, (0xFFFBFC00 >> 16) # lui $at, 0xfffb
/* 03D938 7F008E08 3421FC00 */  ori   $at, (0xFFFBFC00 & 0xFFFF) # ori $at, $at, 0xfc00
/* 03D93C 7F008E0C 0301C821 */  addu  $t9, $t8, $at
/* 03D940 7F008E10 ACB90000 */  sw    $t9, ($a1)
/* 03D944 7F008E14 8C880000 */  lw    $t0, ($a0)
/* 03D948 7F008E18 3C0B002C */  lui   $t3, %hi(_ramromDam1SegmentRomStart) # $t3, 0x2c
/* 03D94C 7F008E1C 24634D50 */  addiu $v1, %lo(unknown2) # addiu $v1, $v1, 0x4d50
/* 03D950 7F008E20 3C010004 */  lui   $at, (0x00040400 >> 16) # lui $at, 4
/* 03D954 7F008E24 256BF2D0 */  addiu $t3, %lo(_ramromDam1SegmentRomStart) # addiu $t3, $t3, -0xd30
/* 03D958 7F008E28 34210400 */  ori   $at, (0x00040400 & 0xFFFF) # ori $at, $at, 0x400
/* 03D95C 7F008E2C 01633023 */  subu  $a2, $t3, $v1
/* 03D960 7F008E30 3C028007 */  lui   $v0, %hi(dword_CODE_bss_80069588)
/* 03D964 7F008E34 24C6003F */  addiu $a2, $a2, 0x3f
/* 03D968 7F008E38 01014821 */  addu  $t1, $t0, $at
/* 03D96C 7F008E3C 24429588 */  addiu $v0, %lo(dword_CODE_bss_80069588) # addiu $v0, $v0, -0x6a78
/* 03D970 7F008E40 AC890000 */  sw    $t1, ($a0)
/* 03D974 7F008E44 34CC003F */  ori   $t4, $a2, 0x3f
/* 03D978 7F008E48 AC490000 */  sw    $t1, ($v0)
/* 03D97C 7F008E4C 3986003F */  xori  $a2, $t4, 0x3f
/* 03D980 7F008E50 01202025 */  move  $a0, $t1
/* 03D984 7F008E54 0C001707 */  jal   romCopy
/* 03D988 7F008E58 00602825 */   move  $a1, $v1
/* 03D98C 7F008E5C 3C048007 */  lui   $a0, %hi(dword_CODE_bss_80069588)
/* 03D990 7F008E60 3C058007 */  lui   $a1, %hi(dword_CODE_bss_8006958C)
/* 03D994 7F008E64 8CA5958C */  lw    $a1, %lo(dword_CODE_bss_8006958C)($a1)
/* 03D998 7F008E68 0FC06C38 */  jal   sub_GAME_7F01B0E0
/* 03D99C 7F008E6C 8C849588 */   lw    $a0, %lo(dword_CODE_bss_80069588)($a0)
/* 03D9A0 7F008E70 8FBF0014 */  lw    $ra, 0x14($sp)
/* 03D9A4 7F008E74 27BD0018 */  addiu $sp, $sp, 0x18
/* 03D9A8 7F008E78 03E00008 */  jr    $ra
/* 03D9AC 7F008E7C 00000000 */   nop   
)
#endif



void initializeGunBarrelIntro(u8 *gfxBuffer, s32 bufferSize)
{
    struct ModelAnimation *animation;
    struct coord3d sp50;
    struct texpool texturePool;
    s32 temp_t9;
    s32 startframe;
    
    gunbarrel_mode = 2;
    
    guOrtho(matrixBufferGunbarrel0, 0.0f, 1280.0f, 0.0f, 960.0f, 1.0f, 8.0f, 256.0f);
    
    g_TitleX = -30.0f;
    g_TitleY = 482.0f;
    titleTransitionX = -100.0f;
    titleTransitionY = 482.0f;
    word_CODE_bss_80069584 = 0x42;
    barrelDisplayListPtr = gfxBuffer;
    bufferSize -= 0x200;
    gfxBuffer += 0x200;
    
    createGunbarrelRenderHole(barrelDisplayListPtr, 0x1E);
    
    gunbarrelgfxListPointer = (Gfx*)gfxBuffer;
    bufferSize -= 0x100;
    gfxBuffer += 0x100;
    
    sub_GAME_7F01BFF8(gunbarrelgfxListPointer, barrelDisplayListPtr + 0x80000000, 0x1E);
    sub_GAME_7F008DE4((u8 **)&gfxBuffer, &bufferSize);

    // struct copy
    sp50 = D_8002A8A8;
    
    temp_t9 = 0x12C00;
    
    texInitPool(&texturePool, gfxBuffer, temp_t9);
    
    gfxBuffer += temp_t9;
    bufferSize -= temp_t9;
    
    load_object_fill_header(c_item_entries[BODY_Brosnan_Tuxedo].header, c_item_entries[BODY_Brosnan_Tuxedo].filename, gfxBuffer, bufferSize, &texturePool);
    
    temp_t9 = ((get_pc_buffer_remaining_value(c_item_entries[BODY_Brosnan_Tuxedo].filename) + 0x3F) | 0x3F) ^ 0x3F;
    bufferSize -= temp_t9;
    gfxBuffer += temp_t9;
    
    load_object_fill_header(c_item_entries[BODY_Male_Pierce_Bond_Tuxedo].header, c_item_entries[BODY_Male_Pierce_Bond_Tuxedo].filename, gfxBuffer, bufferSize, &texturePool);
    
    temp_t9 = ((get_pc_buffer_remaining_value(c_item_entries[BODY_Male_Pierce_Bond_Tuxedo].filename) + 0x3F) | 0x3F) ^ 0x3F;
    bufferSize -= temp_t9;
    gfxBuffer += temp_t9;
    
    chrModelInstance = setup_chr_instance(BODY_Brosnan_Tuxedo, BODY_Male_Pierce_Bond_Tuxedo, c_item_entries[BODY_Brosnan_Tuxedo].header, c_item_entries[BODY_Male_Pierce_Bond_Tuxedo].header, 0);

    modelSetScale(chrModelInstance, 0.18779343f);
    sub_GAME_7F06CE84(chrModelInstance, 1.0f);
    setsuboffset(chrModelInstance, &sp50);
    setsubroty(chrModelInstance, 0.0f);
#if defined(VERSION_EU)
    #define S_7F008E80_ANIM_SPEED 0.6f
#else
    #define S_7F008E80_ANIM_SPEED 0.5f
#endif
    modelSetAnimPlaySpeed(chrModelInstance, S_7F008E80_ANIM_SPEED, 0.0f);
#undef S_7F008E80_ANIM_SPEED
    
    animation = (struct ModelAnimation*)((s32)ptr_animation_table + (s32)&ANIM_DATA_bond_eye_walk);
    startframe = animation->unk04 - 0x44;
    while (startframe < 0)
    {
        startframe += animation->unk04;
    }
    
    modelSetAnimation(chrModelInstance, (struct ModelAnimation *) animation, 0, (f32) startframe, 0.91f, 0.0f);
    load_object_fill_header(PitemZ_entries[PROP_CHRWPPK].header, PitemZ_entries[PROP_CHRWPPK].filename, gfxBuffer, bufferSize, &texturePool);
    
    temp_t9 = ((get_pc_buffer_remaining_value(PitemZ_entries[PROP_CHRWPPK].filename) + 0x3F) | 0x3F) ^ 0x3F;
    bufferSize -= temp_t9;
    gfxBuffer += temp_t9;
    
    modelCalculateRwDataLen(PitemZ_entries[191].header);
    
    gunModelInstance = get_obj_instance_controller_for_header(PitemZ_entries[PROP_CHRWPPK].header);
    
    modelSetScale(gunModelInstance, 0.18779343f);
    
    gunModelInstance->attachedto = chrModelInstance;
    gunModelInstance->attachedto_objinst = chrModelInstance->obj->Switches[3];
    dword_CODE_bss_80069594 = 0;    
}


void sub_GAME_7F00920C(void)
{
    if (chrModelInstance)
    {
        clear_aircraft_model_obj(chrModelInstance);
    }

    if (gunModelInstance)
    {
        clear_model_obj(gunModelInstance);
    }
}

#ifndef REFRESH_PAL
    #define XINC 6.0f
    #define XDEC 12.0f
    #define XDEC2 6
    #define XDEC3 5.8183274f
    #define INCVAL 0x38E
    #define INTRO_EYE_COUNTER_CASE_4 108
    #define INTRO_EYE_COUNTER_CASE_5_ADD 8
    #define INTRO_EYE_COUNTER_CASE_6 0x1e
#else
    #define XINC 7.0f
    #define XDEC 14.0f
    #define XDEC2 6
    #define XDEC3 3.63643622398f
    #define INCVAL 0x444
    #define INTRO_EYE_COUNTER_CASE_4 90
    #define INTRO_EYE_COUNTER_CASE_5_ADD 9
    #define INTRO_EYE_COUNTER_CASE_6 0x19
#endif


Gfx *sub_GAME_7F009254(Gfx *gdl) {
    D_8002A7D0 = (1 - D_8002A7D0);
    switch (gunbarrel_mode - 2)
    {
    case 0:
        gdl = manipulateGunbarrelAndLogoMatrices(gdl);
        g_TitleX += XINC;
        if (word_CODE_bss_80069584 < 0) {
            word_CODE_bss_80069584 = 200;
            titleTransitionX = (g_TitleX - XDEC);
        } else {
#if defined(VERSION_EU)
            word_CODE_bss_80069584 -= 7;
#else
            word_CODE_bss_80069584 -= 6;
#endif
        }
        if (g_TitleX > 1390.0f) {
            gunbarrel_mode++;
            g_TitleX = 1276.0f;
        }
        break;

    case 1:
        #if defined(LEFTOVERDEBUG)
        gSPDisplayList(gdl++, &dlBasicGeometry);
        gdl = insert_imageDL(gdl++);
        gdl = insert_imageDL(gdl++);
        gdl = insert_imageDL(gdl++);
        gdl = insert_imageDL(gdl++);
        gdl = insert_imageDL(gdl++);
        #endif
        gdl = insert_sniper_sight_eye_intro(gdl++);
        gdl = insert_sight_backdrop_eye_intro(gdl++);
        
        if (g_TitleX < 600.0f) {
            gdl = insert_bond_eye_intro(gdl);
        }
        g_TitleX -= XDEC3;
        if (g_TitleX <= -80.0f) {
            gunbarrel_mode++;
            intro_eye_counter = 20;
        }
        break;

    case 2:
        gdl = insert_sniper_sight_eye_intro(gdl);
        gdl = insert_sight_backdrop_eye_intro(gdl);
        gdl = insert_bond_eye_intro(gdl);
        intro_eye_counter--;
        if (intro_eye_counter < 0) {
            gunbarrel_mode++;
            die_blood_image_routine(0);
            intro_state_blood_animation = 0;
            intro_eye_counter = 1;
        }
        break;

    case 3:
        intro_eye_counter--;
        if (intro_eye_counter == 0) {
            intro_state_blood_animation = die_blood_image_routine(1);
            intro_eye_counter = 2;
        }
        gdl = insert_sniper_sight_eye_intro(gdl);
        gdl = insert_sight_backdrop_eye_intro(gdl);
        gdl = insert_bond_eye_intro(gdl);
        gdl = gunbarrelBloodOverlayDL(gdl);
        if (intro_state_blood_animation != 0) {
            gunbarrel_mode++;
            word_CODE_bss_80069584 = 0;
            titleTransitionX = g_TitleX;
            intro_eye_counter = 0;
        }
        break;

    case 4:
        word_CODE_bss_80069584 += INCVAL;
        intro_eye_counter++;
        g_TitleX = ((sins(word_CODE_bss_80069584) * 64.0f) / 32768.0f) + titleTransitionX;
        gdl = insert_sniper_sight_eye_intro(gdl);
        gdl = insert_sight_backdrop_eye_intro(gdl);
        gdl = insert_bond_eye_intro(gdl);
        gdl = sub_GAME_7F01CA18(gdl);
        if (intro_eye_counter >= INTRO_EYE_COUNTER_CASE_4)
        {
            intro_eye_counter = 0;
            gunbarrel_mode++;
        }
        break;

    case 5:
        word_CODE_bss_80069584 += INCVAL;
        g_TitleX = ((sins(word_CODE_bss_80069584) * 64.0f) / 32768.0f) + titleTransitionX;
        gdl = insert_sniper_sight_eye_intro(gdl);
        gdl = insert_sight_backdrop_eye_intro(gdl);
        gdl = insert_bond_eye_intro(gdl);
        gdl = sub_GAME_7F01CA18(gdl);
        
        intro_eye_counter += INTRO_EYE_COUNTER_CASE_5_ADD;
        
        gdl = sub_GAME_7F007E70(gdl, intro_eye_counter);
        if (intro_eye_counter >= 0xF7) {
            intro_eye_counter = 0;
            gunbarrel_mode++;                
        }
        break;

    case 6:
        gSPDisplayList(gdl++, &dlBasicGeometry);
        gdl = insert_imageDL(gdl);
        if (intro_eye_counter++ >= INTRO_EYE_COUNTER_CASE_6) {
            intro_eye_counter = 0;
            gunbarrel_mode++;
        }
        break;
    };

    return gdl;
}

s32 isGunBarrelInMode9(void) {
    return (gunbarrel_mode == 9);
}
