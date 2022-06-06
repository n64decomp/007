#include <ultra64.h>
#include <PR/gbi.h>
#include <PR/gu.h>
#include <PR/os.h>
#include <assets/font_dl.h>
#include <bondgame.h>
#include <fr.h>
#include <macro.h>
#include "matrixmath.h"
#include <ramrom.h>
#include "blood_animation.h"
#include "chr.h"
#include "chr_b.h"
#include "math_floor.h"
#include "title.h"
#include "unk_01B240.h"



extern signed short sins(unsigned short x);

// bss
//CODE.bss:80069550
s32 dword_CODE_bss_80069550;
//CODE.bss:80069554
Gfx *dword_CODE_bss_80069554;
//CODE.bss:80069558
Mtx *matrix_buffer_rarelogo_0;
//CODE.bss:8006955C
Mtx *matrix_buffer_gunbarrel_0;
//CODE.bss:80069560
Mtx *matrix_buffer_rarelogo_1;
//CODE.bss:80069564
Mtx *matrix_buffer_rarelogo_2;
//CODE.bss:80069568
Mtx *matrix_buffer_gunbarrel_1;
//CODE.bss:8006956C
Mtx *matrix_buffer_intro_backdrop;
//CODE.bss:80069570
Mtx *matrix_buffer_intro_bond;
//CODE.bss:80069574
f32 g_TitleX;
//CODE.bss:80069578
f32 g_TitleY;
//CODE.bss:8006957C
f32 dword_CODE_bss_8006957C;
//CODE.bss:80069580
f32 dword_CODE_bss_80069580;
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
s32 D_8002A7DC[3] = {0x00, 0x00, 0x00};
s32 D_8002A7E8[3] = {0xFF, 0xFF, 0xFF};
u32 D_8002A7F4 = 0;
u32 D_8002A7F8 = 0;
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
f32 D_8002A83C[3] = {1758.2957f, 220.0f, 684.28143f};
f32 D_8002A848[3] = {-0.97f, 0.0f, 0.24f};
f32 D_8002A854[3] = {0.0f, 1.0f, -0.0f};
Lights1 D_8002A860 = gdSPDefLights1(0xDC, 0xDC, 0xDC, 0xFF, 0xFF, 0xFF, 0x00, 0x7F, 0x00);
f32 D_8002A878[3] = {0.0f, 0.0f, 4883.0f};
f32 D_8002A884[3] = {0.0f, 0.0f, -1.0f};
f32 D_8002A890[3] = {0.0f, 1.0f, 0.0f};

f32 D_8002A89C = 0.0f;
s32 intro_eye_counter = 0;
u32 intro_state_blood_animation = 0;
u32 D_8002A8A8 = 0;
u32 D_8002A8AC = 0;
u32 D_8002A8B0 = 0;
/*
                .word 0
                .word 0
                .word 0
*/

Gfx *something_with_gunbarrel_and_rareware_logo_matrix_manip(Gfx *gdl)
{
    guTranslate(&matrix_buffer_rarelogo_2[D_8002A7D0], g_TitleX, g_TitleY, -5.0f);
    guTranslate(&matrix_buffer_gunbarrel_1[D_8002A7D0], dword_CODE_bss_8006957C, dword_CODE_bss_80069580, -5.0f);
    gSPDisplayList(gdl++, &fontDL_0x000);

    gdl = sub_GAME_7F01C1A4(insert_imageDL(gdl));

    gDPSetCombineMode(gdl++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
    gDPSetPrimColor(gdl++, 0, 0, 0xE6, 0xE6, 0xE6, 0x00);
    gSPDisplayList(gdl++, OS_K0_TO_PHYSICAL(dword_CODE_bss_80069554));
    gSPMatrix(gdl++, osVirtualToPhysical(&matrix_buffer_gunbarrel_1[D_8002A7D0]), (G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW));
    gSPDisplayList(gdl++, OS_K0_TO_PHYSICAL(dword_CODE_bss_80069554));

    return gdl;
}

Gfx *insert_sight_backdrop_eye_intro(Gfx *gdl)
{
    guTranslate(&matrix_buffer_rarelogo_2[D_8002A7D0], g_TitleX + 768.0f, g_TitleY - 40.0f, -5.0f);
    guScale(&matrix_buffer_gunbarrel_1[D_8002A7D0], 2.7f, 2.57f, 1.0f);
    gSPDisplayList(gdl++, &fontDL_0x000);
    gSPDisplayList(gdl++, &fontDL_0x040);

    gdl = sub_GAME_7F01C1A4(gdl);

    gSPMatrix(gdl++, osVirtualToPhysical(&matrix_buffer_gunbarrel_1[D_8002A7D0]), (G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW));
    gSPDisplayList(gdl++, OS_K0_TO_PHYSICAL(dword_CODE_bss_80069554));

    return gdl;
}

Gfx *sub_GAME_7F007CC8(Gfx *gdl, s32 arg1, s32 arg2[3], s32 arg3[3])
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
    s32 sp3C[3] = D_8002A7DC;
    s32 sp30[3] = D_8002A7E8;

    gSPDisplayList(gdl++, &fontDL_0x000);

    gdl = insert_imageDL(gdl);

    gDPSetCombineMode(gdl++, G_CC_MODULATEI_PRIM, G_CC_MODULATEI_PRIM);

    return sub_GAME_7F007CC8(gdl, floorFloat((viGetX() * g_TitleX) / 1280.0f), sp3C, sp30);
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
/* 03CADC 7F007FAC 3C138003 */  lui   $s3, %hi(D_8002A7F4)
/* 03CAE0 7F007FB0 3C108007 */  lui   $s0, %hi(dword_CODE_bss_80069594)
/* 03CAE4 7F007FB4 26109594 */  addiu $s0, %lo(dword_CODE_bss_80069594) # addiu $s0, $s0, -0x6a6c
/* 03CAE8 7F007FB8 2673A7F4 */  addiu $s3, %lo(D_8002A7F4) # addiu $s3, $s3, -0x580c
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
/* 03CB68 7F008038 0FC1C2BB */  jal   sub_GAME_7F070AEC
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
/* 03CBA8 7F008078 3C138003 */  lui   $s3, %hi(D_8002A7F4)
/* 03CBAC 7F00807C 2673A7F4 */  addiu $s3, %lo(D_8002A7F4) # addiu $s3, $s3, -0x580c
/* 03CBB0 7F008080 0FC1B100 */  jal   set_80036084
/* 03CBB4 7F008084 24040001 */   li    $a0, 1
/* 03CBB8 7F008088 0FC1CFF2 */  jal   sub_GAME_7F073FC8
/* 03CBBC 7F00808C 24040050 */   li    $a0, 80
/* 03CBC0 7F008090 0FC1B5AC */  jal   subcalcpos
/* 03CBC4 7F008094 8E640000 */   lw    $a0, ($s3)
/* 03CBC8 7F008098 3C148003 */  lui   $s4, %hi(D_8002A7F8)
/* 03CBCC 7F00809C 2694A7F8 */  addiu $s4, %lo(D_8002A7F8) # addiu $s4, $s4, -0x5808
/* 03CBD0 7F0080A0 8E860000 */  lw    $a2, ($s4)
/* 03CBD4 7F0080A4 8CD90008 */  lw    $t9, 8($a2)
/* 03CBD8 7F0080A8 8F230008 */  lw    $v1, 8($t9)
/* 03CBDC 7F0080AC 8C650000 */  lw    $a1, ($v1)
/* 03CBE0 7F0080B0 50A00008 */  beql  $a1, $zero, .L7F0080D4
/* 03CBE4 7F0080B4 8C650008 */   lw    $a1, 8($v1)
/* 03CBE8 7F0080B8 0FC1B1E7 */  jal   extract_id_from_object_structure_microcode
/* 03CBEC 7F0080BC 00C02025 */   move  $a0, $a2
/* 03CBF0 7F0080C0 A4550000 */  sh    $s5, ($v0)
/* 03CBF4 7F0080C4 8E860000 */  lw    $a2, ($s4)
/* 03CBF8 7F0080C8 8CD80008 */  lw    $t8, 8($a2)
/* 03CBFC 7F0080CC 8F030008 */  lw    $v1, 8($t8)
/* 03CC00 7F0080D0 8C650008 */  lw    $a1, 8($v1)
.L7F0080D4:
/* 03CC04 7F0080D4 50A00005 */  beql  $a1, $zero, .L7F0080EC
/* 03CC08 7F0080D8 8FA80128 */   lw    $t0, 0x128($sp)
/* 03CC0C 7F0080DC 0FC1B1E7 */  jal   extract_id_from_object_structure_microcode
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
/* 03CC54 7F008124 0FC1B198 */  jal   sub_GAME_7F06C660
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
/* 03CCF4 7F0081C4 0FC1B100 */  jal   set_80036084
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
/* 03A91C 7F007F2C 3C138002 */  lui   $s3, %hi(D_8002A7F4) # $s3, 0x8002
/* 03A920 7F007F30 3C108006 */  lui   $s0, %hi(dword_CODE_bss_80069594) # $s0, 0x8006
/* 03A924 7F007F34 261084D4 */  addiu $s0, %lo(dword_CODE_bss_80069594) # addiu $s0, $s0, -0x7b2c
/* 03A928 7F007F38 26735D44 */  addiu $s3, %lo(D_8002A7F4) # addiu $s3, $s3, 0x5d44
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
/* 03A9A8 7F007FB8 0FC1C323 */  jal   sub_GAME_7F070AEC
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
/* 03A9E8 7F007FF8 3C138002 */  lui   $s3, %hi(D_8002A7F4) # $s3, 0x8002
/* 03A9EC 7F007FFC 26735D44 */  addiu $s3, %lo(D_8002A7F4) # addiu $s3, $s3, 0x5d44
/* 03A9F0 7F008000 0FC1B2D0 */  jal   set_80036084
/* 03A9F4 7F008004 24040001 */   li    $a0, 1
/* 03A9F8 7F008008 0FC1D037 */  jal   sub_GAME_7F073FC8
/* 03A9FC 7F00800C 24040050 */   li    $a0, 80
/* 03AA00 7F008010 0FC1B6B8 */  jal   subcalcpos
/* 03AA04 7F008014 8E640000 */   lw    $a0, ($s3)
/* 03AA08 7F008018 3C148002 */  lui   $s4, %hi(D_8002A7F8) # $s4, 0x8002
/* 03AA0C 7F00801C 26945D48 */  addiu $s4, %lo(D_8002A7F8) # addiu $s4, $s4, 0x5d48
/* 03AA10 7F008020 8E860000 */  lw    $a2, ($s4)
/* 03AA14 7F008024 8CD90008 */  lw    $t9, 8($a2)
/* 03AA18 7F008028 8F230008 */  lw    $v1, 8($t9)
/* 03AA1C 7F00802C 8C650000 */  lw    $a1, ($v1)
/* 03AA20 7F008030 50A00008 */  beql  $a1, $zero, .L7F008054
/* 03AA24 7F008034 8C650008 */   lw    $a1, 8($v1)
/* 03AA28 7F008038 0FC1B3A3 */  jal   extract_id_from_object_structure_microcode
/* 03AA2C 7F00803C 00C02025 */   move  $a0, $a2
/* 03AA30 7F008040 A4550000 */  sh    $s5, ($v0)
/* 03AA34 7F008044 8E860000 */  lw    $a2, ($s4)
/* 03AA38 7F008048 8CD80008 */  lw    $t8, 8($a2)
/* 03AA3C 7F00804C 8F030008 */  lw    $v1, 8($t8)
/* 03AA40 7F008050 8C650008 */  lw    $a1, 8($v1)
.L7F008054:
/* 03AA44 7F008054 50A00005 */  beql  $a1, $zero, .L7F00806C
/* 03AA48 7F008058 8FA80128 */   lw    $t0, 0x128($sp)
/* 03AA4C 7F00805C 0FC1B3A3 */  jal   extract_id_from_object_structure_microcode
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
/* 03AA94 7F0080A4 0FC1B366 */  jal   sub_GAME_7F06C660
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
/* 03AB34 7F008144 0FC1B2D0 */  jal   set_80036084
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
    guTranslate(&matrix_buffer_intro_backdrop[D_8002A7D0], 0.0f, 0.0f, 0.0f);
    guPerspective(&matrix_buffer_intro_bond[D_8002A7D0], &perspNorm, 46.0f, (320.0f / 240.0f), 10.0f, 10000.0f, 1.0f);
    gSPPerspNormalize(gdl++, perspNorm);
    gDPSetCombineMode(gdl++, G_CC_SHADE, G_CC_SHADE);
    gDPSetRenderMode(gdl++, G_RM_AA_OPA_SURF, G_RM_AA_OPA_SURF2);
    gSPMatrix(gdl++, osVirtualToPhysical(&matrix_buffer_intro_bond[D_8002A7D0]), (G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION));
    gSPMatrix(gdl++, osVirtualToPhysical(&matrix_buffer_intro_backdrop[D_8002A7D0]), (G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW));
    
    matrix_4x4_7F059694(&matrix, D_8002A83C[0], D_8002A83C[1], D_8002A83C[2], (D_8002A83C[0] + D_8002A848[0]), (D_8002A83C[1] + D_8002A848[1]), (D_8002A83C[2] + D_8002A848[2]), D_8002A854[0], D_8002A854[1], D_8002A854[2]);

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
    D_8002A878[2] = arg3;
    gSPDisplayList(gdl++, &fontDL_0x000);
    gdl = insert_imageDL(gdl);
    {
        u16 perspNorm;
        guPerspective(&matrix_buffer_rarelogo_0[D_8002A7D0], &perspNorm, 60.0f, (320.0f / 240.0f), 100.0f, 5000.0f, 1.0f);
        gSPPerspNormalize(gdl++, perspNorm);
    }
    gSPMatrix(gdl++, osVirtualToPhysical(&matrix_buffer_rarelogo_0[D_8002A7D0]), (G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION));
    gSPClearGeometryMode(gdl++, -1);
    gSPSetGeometryMode(gdl++, (G_SHADE | G_CULL_BACK | G_LIGHTING | G_TEXTURE_GEN | G_SHADING_SMOOTH));
    guLookAt(&matrix_buffer_rarelogo_1[D_8002A7D0], D_8002A878[0], D_8002A878[1], D_8002A878[2], (D_8002A878[0] + D_8002A884[0]), (D_8002A878[1] + D_8002A884[1]), (D_8002A878[2] + D_8002A884[2]), D_8002A890[0], D_8002A890[1], D_8002A890[2]);
    gSPMatrix(gdl++,  osVirtualToPhysical(&matrix_buffer_rarelogo_1[D_8002A7D0]), (G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW));
    guRotate(&matrix_buffer_rarelogo_2[D_8002A7D0], D_8002A89C, 0.0f, 1.0f, 0.0f);
#if defined(REFRESH_PAL)
    D_8002A89C += 2.4f;
#else
    D_8002A89C += 2.0f;
#endif
    gSPMatrix(gdl++, osVirtualToPhysical(&matrix_buffer_rarelogo_2[D_8002A7D0]), (G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW));
    gSPSetLights1(gdl++, D_8002A860);
    D_8002A860.a.l.col[0] = D_8002A860.a.l.col[1] = D_8002A860.a.l.col[2] = D_8002A860.a.l.colc[0] = D_8002A860.a.l.colc[1] = D_8002A860.a.l.colc[2] = arg4;
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

extern void *_GlobalimagetablecmdblkSegmentRomStart;
extern void *_GlobalimagetablecmdblkSegmentStart;
extern void *_GlobalimagetablecmdblkSegmentEnd; 
void sub_GAME_7F008B58(s32 address, s32 size) {
    gunbarrel_mode = 0;
    g_TitleX = 880.0f;
    D_8002A89C = -40.0f;
    intro_eye_counter = 0;
    virtualaddress = address;
    romCopy(virtualaddress, &_GlobalimagetablecmdblkSegmentRomStart, ALIGN64_V2((u32)&_GlobalimagetablecmdblkSegmentEnd - (u32)&_GlobalimagetablecmdblkSegmentStart));
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
    gSPSegment(gdl++, 2, osVirtualToPhysical(virtualaddress));
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

s32 sub_GAME_7F008DD0(void) {
    return (gunbarrel_mode == 2);
}

#ifdef NONMATCHING
// Minor reordering + regalloc
void sub_GAME_7F01B0E0(s32, s32);
extern void *unknown2;
extern void *unknown2_end;
void sub_GAME_7F008DE4(u8 **arg0, s32 *arg1) {
    dword_CODE_bss_8006958C = *arg0;
    *arg1 -= 0x40400;
    *arg0 += 0x40400;
    dword_CODE_bss_80069588 = *arg0;
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



#ifdef NONMATCHING
void sub_GAME_7F008E80(void) {

}
#else
#ifndef VERSION_EU
GLOBAL_ASM(
.late_rodata
glabel D_8004F2DC
.word 0x3f68f5c3
.text
glabel sub_GAME_7F008E80
/* 03D9B0 7F008E80 240E0002 */  li    $t6, 2
/* 03D9B4 7F008E84 3C018003 */  lui   $at, %hi(gunbarrel_mode)
/* 03D9B8 7F008E88 A02EA7D4 */  sb    $t6, %lo(gunbarrel_mode)($at)
/* 03D9BC 7F008E8C 3C014470 */  li    $at, 0x44700000 # 960.000000
/* 03D9C0 7F008E90 44812000 */  mtc1  $at, $f4
/* 03D9C4 7F008E94 27BDFFA0 */  addiu $sp, $sp, -0x60
/* 03D9C8 7F008E98 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 03D9CC 7F008E9C 44813000 */  mtc1  $at, $f6
/* 03D9D0 7F008EA0 44800000 */  mtc1  $zero, $f0
/* 03D9D4 7F008EA4 3C014100 */  li    $at, 0x41000000 # 8.000000
/* 03D9D8 7F008EA8 44814000 */  mtc1  $at, $f8
/* 03D9DC 7F008EAC 3C014380 */  li    $at, 0x43800000 # 256.000000
/* 03D9E0 7F008EB0 44815000 */  mtc1  $at, $f10
/* 03D9E4 7F008EB4 AFA40060 */  sw    $a0, 0x60($sp)
/* 03D9E8 7F008EB8 AFA50064 */  sw    $a1, 0x64($sp)
/* 03D9EC 7F008EBC AFBF002C */  sw    $ra, 0x2c($sp)
/* 03D9F0 7F008EC0 3C048007 */  lui   $a0, %hi(matrix_buffer_gunbarrel_0)
/* 03D9F4 7F008EC4 44050000 */  mfc1  $a1, $f0
/* 03D9F8 7F008EC8 44070000 */  mfc1  $a3, $f0
/* 03D9FC 7F008ECC AFB10028 */  sw    $s1, 0x28($sp)
/* 03DA00 7F008ED0 AFB00024 */  sw    $s0, 0x24($sp)
/* 03DA04 7F008ED4 8C84955C */  lw    $a0, %lo(matrix_buffer_gunbarrel_0)($a0)
/* 03DA08 7F008ED8 3C0644A0 */  lui   $a2, 0x44a0
/* 03DA0C 7F008EDC E7A40010 */  swc1  $f4, 0x10($sp)
/* 03DA10 7F008EE0 E7A60014 */  swc1  $f6, 0x14($sp)
/* 03DA14 7F008EE4 E7A80018 */  swc1  $f8, 0x18($sp)
/* 03DA18 7F008EE8 0C005AF1 */  jal   guOrtho
/* 03DA1C 7F008EEC E7AA001C */   swc1  $f10, 0x1c($sp)
/* 03DA20 7F008EF0 3C0143F1 */  li    $at, 0x43F10000 # 482.000000
/* 03DA24 7F008EF4 44810000 */  mtc1  $at, $f0
/* 03DA28 7F008EF8 3C01C1F0 */  li    $at, 0xC1F00000 # -30.000000
/* 03DA2C 7F008EFC 44818000 */  mtc1  $at, $f16
/* 03DA30 7F008F00 3C018007 */  lui   $at, %hi(g_TitleX)
/* 03DA34 7F008F04 8FA20060 */  lw    $v0, 0x60($sp)
/* 03DA38 7F008F08 E4309574 */  swc1  $f16, %lo(g_TitleX)($at)
/* 03DA3C 7F008F0C 3C018007 */  lui   $at, %hi(g_TitleY)
/* 03DA40 7F008F10 E4209578 */  swc1  $f0, %lo(g_TitleY)($at)
/* 03DA44 7F008F14 3C01C2C8 */  li    $at, 0xC2C80000 # -100.000000
/* 03DA48 7F008F18 44819000 */  mtc1  $at, $f18
/* 03DA4C 7F008F1C 3C018007 */  lui   $at, %hi(dword_CODE_bss_8006957C)
/* 03DA50 7F008F20 8FB80064 */  lw    $t8, 0x64($sp)
/* 03DA54 7F008F24 E432957C */  swc1  $f18, %lo(dword_CODE_bss_8006957C)($at)
/* 03DA58 7F008F28 3C018007 */  lui   $at, %hi(dword_CODE_bss_80069580)
/* 03DA5C 7F008F2C E4209580 */  swc1  $f0, %lo(dword_CODE_bss_80069580)($at)
/* 03DA60 7F008F30 3C108007 */  lui   $s0, %hi(dword_CODE_bss_80069550)
/* 03DA64 7F008F34 3C018007 */  lui   $at, %hi(word_CODE_bss_80069584)
/* 03DA68 7F008F38 240F0042 */  li    $t7, 66
/* 03DA6C 7F008F3C 26109550 */  addiu $s0, %lo(dword_CODE_bss_80069550) # addiu $s0, $s0, -0x6ab0
/* 03DA70 7F008F40 A42F9584 */  sh    $t7, %lo(word_CODE_bss_80069584)($at)
/* 03DA74 7F008F44 AE020000 */  sw    $v0, ($s0)
/* 03DA78 7F008F48 24420200 */  addiu $v0, $v0, 0x200
/* 03DA7C 7F008F4C 2719FE00 */  addiu $t9, $t8, -0x200
/* 03DA80 7F008F50 AFB90064 */  sw    $t9, 0x64($sp)
/* 03DA84 7F008F54 AFA20060 */  sw    $v0, 0x60($sp)
/* 03DA88 7F008F58 8E040000 */  lw    $a0, ($s0)
/* 03DA8C 7F008F5C 0FC06EB8 */  jal   sub_GAME_7F01BAE0
/* 03DA90 7F008F60 2405001E */   li    $a1, 30
/* 03DA94 7F008F64 8FA30060 */  lw    $v1, 0x60($sp)
/* 03DA98 7F008F68 8FA80064 */  lw    $t0, 0x64($sp)
/* 03DA9C 7F008F6C 3C028007 */  lui   $v0, %hi(dword_CODE_bss_80069554)
/* 03DAA0 7F008F70 24429554 */  addiu $v0, %lo(dword_CODE_bss_80069554) # addiu $v0, $v0, -0x6aac
/* 03DAA4 7F008F74 8E050000 */  lw    $a1, ($s0)
/* 03DAA8 7F008F78 AC430000 */  sw    $v1, ($v0)
/* 03DAAC 7F008F7C 3C018000 */  lui   $at, 0x8000
/* 03DAB0 7F008F80 24630100 */  addiu $v1, $v1, 0x100
/* 03DAB4 7F008F84 2509FF00 */  addiu $t1, $t0, -0x100
/* 03DAB8 7F008F88 AFA90064 */  sw    $t1, 0x64($sp)
/* 03DABC 7F008F8C AFA30060 */  sw    $v1, 0x60($sp)
/* 03DAC0 7F008F90 8C440000 */  lw    $a0, ($v0)
/* 03DAC4 7F008F94 2406001E */  li    $a2, 30
/* 03DAC8 7F008F98 0FC06FFE */  jal   sub_GAME_7F01BFF8
/* 03DACC 7F008F9C 00A12821 */   addu  $a1, $a1, $at
/* 03DAD0 7F008FA0 27A40060 */  addiu $a0, $sp, 0x60
/* 03DAD4 7F008FA4 0FC02379 */  jal   sub_GAME_7F008DE4
/* 03DAD8 7F008FA8 27A50064 */   addiu $a1, $sp, 0x64
/* 03DADC 7F008FAC 3C0B8003 */  lui   $t3, %hi(D_8002A8A8) 
/* 03DAE0 7F008FB0 256BA8A8 */  addiu $t3, %lo(D_8002A8A8) # addiu $t3, $t3, -0x5758
/* 03DAE4 7F008FB4 8D610000 */  lw    $at, ($t3)
/* 03DAE8 7F008FB8 27AA0050 */  addiu $t2, $sp, 0x50
/* 03DAEC 7F008FBC 8D6E0004 */  lw    $t6, 4($t3)
/* 03DAF0 7F008FC0 AD410000 */  sw    $at, ($t2)
/* 03DAF4 7F008FC4 8D610008 */  lw    $at, 8($t3)
/* 03DAF8 7F008FC8 3C110001 */  lui   $s1, (0x00012C00 >> 16) # lui $s1, 1
/* 03DAFC 7F008FCC 36312C00 */  ori   $s1, (0x00012C00 & 0xFFFF) # ori $s1, $s1, 0x2c00
/* 03DB00 7F008FD0 AD4E0004 */  sw    $t6, 4($t2)
/* 03DB04 7F008FD4 AD410008 */  sw    $at, 8($t2)
/* 03DB08 7F008FD8 8FA50060 */  lw    $a1, 0x60($sp)
/* 03DB0C 7F008FDC 02203025 */  move  $a2, $s1
/* 03DB10 7F008FE0 0FC32EBD */  jal   sub_GAME_7F0CBAF4
/* 03DB14 7F008FE4 27A40040 */   addiu $a0, $sp, 0x40
/* 03DB18 7F008FE8 8FA60060 */  lw    $a2, 0x60($sp)
/* 03DB1C 7F008FEC 8FA70064 */  lw    $a3, 0x64($sp)
/* 03DB20 7F008FF0 3C108004 */  lui   $s0, %hi(c_item_entries)
/* 03DB24 7F008FF4 2610DE10 */  addiu $s0, %lo(c_item_entries) # addiu $s0, $s0, -0x21f0
/* 03DB28 7F008FF8 27AF0040 */  addiu $t7, $sp, 0x40
/* 03DB2C 7F008FFC 00D13021 */  addu  $a2, $a2, $s1
/* 03DB30 7F009000 00F13823 */  subu  $a3, $a3, $s1
/* 03DB34 7F009004 AFA70064 */  sw    $a3, 0x64($sp)
/* 03DB38 7F009008 AFA60060 */  sw    $a2, 0x60($sp)
/* 03DB3C 7F00900C AFAF0010 */  sw    $t7, 0x10($sp)
/* 03DB40 7F009010 8E040064 */  lw    $a0, 0x64($s0)
/* 03DB44 7F009014 0FC1D929 */  jal   load_object_fill_header
/* 03DB48 7F009018 8E050068 */   lw    $a1, 0x68($s0)
/* 03DB4C 7F00901C 0FC2F462 */  jal   get_pc_buffer_remaining_value
/* 03DB50 7F009020 8E040068 */   lw    $a0, 0x68($s0)
/* 03DB54 7F009024 2443003F */  addiu $v1, $v0, 0x3f
/* 03DB58 7F009028 8FA60060 */  lw    $a2, 0x60($sp)
/* 03DB5C 7F00902C 8FA70064 */  lw    $a3, 0x64($sp)
/* 03DB60 7F009030 3478003F */  ori   $t8, $v1, 0x3f
/* 03DB64 7F009034 3B19003F */  xori  $t9, $t8, 0x3f
/* 03DB68 7F009038 27A80040 */  addiu $t0, $sp, 0x40
/* 03DB6C 7F00903C 00D93021 */  addu  $a2, $a2, $t9
/* 03DB70 7F009040 00F93823 */  subu  $a3, $a3, $t9
/* 03DB74 7F009044 AFA70064 */  sw    $a3, 0x64($sp)
/* 03DB78 7F009048 AFA60060 */  sw    $a2, 0x60($sp)
/* 03DB7C 7F00904C AFA80010 */  sw    $t0, 0x10($sp)
/* 03DB80 7F009050 8E040618 */  lw    $a0, 0x618($s0)
/* 03DB84 7F009054 0FC1D929 */  jal   load_object_fill_header
/* 03DB88 7F009058 8E05061C */   lw    $a1, 0x61c($s0)
/* 03DB8C 7F00905C 0FC2F462 */  jal   get_pc_buffer_remaining_value
/* 03DB90 7F009060 8E04061C */   lw    $a0, 0x61c($s0)
/* 03DB94 7F009064 2443003F */  addiu $v1, $v0, 0x3f
/* 03DB98 7F009068 8FAC0064 */  lw    $t4, 0x64($sp)
/* 03DB9C 7F00906C 8FAB0060 */  lw    $t3, 0x60($sp)
/* 03DBA0 7F009070 3469003F */  ori   $t1, $v1, 0x3f
/* 03DBA4 7F009074 392D003F */  xori  $t5, $t1, 0x3f
/* 03DBA8 7F009078 018D5023 */  subu  $t2, $t4, $t5
/* 03DBAC 7F00907C 016D7021 */  addu  $t6, $t3, $t5
/* 03DBB0 7F009080 AFAA0064 */  sw    $t2, 0x64($sp)
/* 03DBB4 7F009084 AFAE0060 */  sw    $t6, 0x60($sp)
/* 03DBB8 7F009088 24040005 */  li    $a0, 5
/* 03DBBC 7F00908C 2405004E */  li    $a1, 78
/* 03DBC0 7F009090 8E060064 */  lw    $a2, 0x64($s0)
/* 03DBC4 7F009094 8E070618 */  lw    $a3, 0x618($s0)
/* 03DBC8 7F009098 0FC08D2A */  jal   setup_chr_instance
/* 03DBCC 7F00909C AFA00010 */   sw    $zero, 0x10($sp)
/* 03DBD0 7F0090A0 3C118003 */  lui   $s1, %hi(D_8002A7F4)
/* 03DBD4 7F0090A4 2631A7F4 */  addiu $s1, %lo(D_8002A7F4) # addiu $s1, $s1, -0x580c
/* 03DBD8 7F0090A8 3C053E40 */  lui   $a1, (0x3E404CEC >> 16) # lui $a1, 0x3e40
/* 03DBDC 7F0090AC AE220000 */  sw    $v0, ($s1)
/* 03DBE0 7F0090B0 34A54CEC */  ori   $a1, (0x3E404CEC & 0xFFFF) # ori $a1, $a1, 0x4cec
/* 03DBE4 7F0090B4 0FC1B39E */  jal   modelSetScale
/* 03DBE8 7F0090B8 00402025 */   move  $a0, $v0
/* 03DBEC 7F0090BC 8E240000 */  lw    $a0, ($s1)
/* 03DBF0 7F0090C0 0FC1B3A1 */  jal   sub_GAME_7F06CE84
/* 03DBF4 7F0090C4 3C053F80 */   lui   $a1, 0x3f80
/* 03DBF8 7F0090C8 8E240000 */  lw    $a0, ($s1)
/* 03DBFC 7F0090CC 0FC1B303 */  jal   setsuboffset
/* 03DC00 7F0090D0 27A50050 */   addiu $a1, $sp, 0x50
/* 03DC04 7F0090D4 8E240000 */  lw    $a0, ($s1)
/* 03DC08 7F0090D8 0FC1B34F */  jal   setsubroty
/* 03DC0C 7F0090DC 24050000 */   li    $a1, 0
/* 03DC10 7F0090E0 8E240000 */  lw    $a0, ($s1)
/* 03DC14 7F0090E4 3C053F00 */  lui   $a1, 0x3f00
/* 03DC18 7F0090E8 0FC1BFC6 */  jal   sub_GAME_7F06FF18
/* 03DC1C 7F0090EC 24060000 */   li    $a2, 0
/* 03DC20 7F0090F0 3C0F8007 */  lui   $t7, %hi(ptr_animation_table) 
/* 03DC24 7F0090F4 8DEF9538 */  lw    $t7, %lo(ptr_animation_table)($t7)
/* 03DC28 7F0090F8 3C180000 */  lui   $t8, 0
/* 03DC2C 7F0090FC 27184144 */  addiu $t8, $t8, 0x4144
/* 03DC30 7F009100 01F82821 */  addu  $a1, $t7, $t8
/* 03DC34 7F009104 94A30004 */  lhu   $v1, 4($a1)
/* 03DC38 7F009108 2462FFBC */  addiu $v0, $v1, -0x44
/* 03DC3C 7F00910C 04430005 */  bgezl $v0, .L7F009124
/* 03DC40 7F009110 44822000 */   mtc1  $v0, $f4
/* 03DC44 7F009114 00431021 */  addu  $v0, $v0, $v1
.L7F009118:
/* 03DC48 7F009118 0442FFFF */  bltzl $v0, .L7F009118
/* 03DC4C 7F00911C 00431021 */   addu  $v0, $v0, $v1
/* 03DC50 7F009120 44822000 */  mtc1  $v0, $f4
.L7F009124:
/* 03DC54 7F009124 3C018005 */  lui   $at, %hi(D_8004F2DC)
/* 03DC58 7F009128 C426F2DC */  lwc1  $f6, %lo(D_8004F2DC)($at)
/* 03DC5C 7F00912C 46802120 */  cvt.s.w $f4, $f4
/* 03DC60 7F009130 44804000 */  mtc1  $zero, $f8
/* 03DC64 7F009134 8E240000 */  lw    $a0, ($s1)
/* 03DC68 7F009138 00003025 */  move  $a2, $zero
/* 03DC6C 7F00913C E7A60010 */  swc1  $f6, 0x10($sp)
/* 03DC70 7F009140 E7A80014 */  swc1  $f8, 0x14($sp)
/* 03DC74 7F009144 44072000 */  mfc1  $a3, $f4
/* 03DC78 7F009148 0FC1BF2A */  jal   modelSetAnimation
/* 03DC7C 7F00914C 00000000 */   nop   
/* 03DC80 7F009150 3C108004 */  lui   $s0, %hi(PitemZ_entries)
/* 03DC84 7F009154 2610A228 */  addiu $s0, %lo(PitemZ_entries) # addiu $s0, $s0, -0x5dd8
/* 03DC88 7F009158 27B90040 */  addiu $t9, $sp, 0x40
/* 03DC8C 7F00915C AFB90010 */  sw    $t9, 0x10($sp)
/* 03DC90 7F009160 8E0408F4 */  lw    $a0, 0x8f4($s0)
/* 03DC94 7F009164 8E0508F8 */  lw    $a1, 0x8f8($s0)
/* 03DC98 7F009168 8FA60060 */  lw    $a2, 0x60($sp)
/* 03DC9C 7F00916C 0FC1D929 */  jal   load_object_fill_header
/* 03DCA0 7F009170 8FA70064 */   lw    $a3, 0x64($sp)
/* 03DCA4 7F009174 0FC2F462 */  jal   get_pc_buffer_remaining_value
/* 03DCA8 7F009178 8E0408F8 */   lw    $a0, 0x8f8($s0)
/* 03DCAC 7F00917C 2443003F */  addiu $v1, $v0, 0x3f
/* 03DCB0 7F009180 8FAD0064 */  lw    $t5, 0x64($sp)
/* 03DCB4 7F009184 8FAA0060 */  lw    $t2, 0x60($sp)
/* 03DCB8 7F009188 3468003F */  ori   $t0, $v1, 0x3f
/* 03DCBC 7F00918C 3909003F */  xori  $t1, $t0, 0x3f
/* 03DCC0 7F009190 01A96023 */  subu  $t4, $t5, $t1
/* 03DCC4 7F009194 01495821 */  addu  $t3, $t2, $t1
/* 03DCC8 7F009198 AFAC0064 */  sw    $t4, 0x64($sp)
/* 03DCCC 7F00919C AFAB0060 */  sw    $t3, 0x60($sp)
/* 03DCD0 7F0091A0 0FC1D73D */  jal   modelCalculateRwDataLen
/* 03DCD4 7F0091A4 8E0408F4 */   lw    $a0, 0x8f4($s0)
/* 03DCD8 7F0091A8 0FC1B025 */  jal   get_obj_instance_controller_for_header
/* 03DCDC 7F0091AC 8E0408F4 */   lw    $a0, 0x8f4($s0)
/* 03DCE0 7F0091B0 3C108003 */  lui   $s0, %hi(D_8002A7F8)
/* 03DCE4 7F0091B4 2610A7F8 */  addiu $s0, %lo(D_8002A7F8) # addiu $s0, $s0, -0x5808
/* 03DCE8 7F0091B8 3C053E40 */  lui   $a1, (0x3E404CEC >> 16) # lui $a1, 0x3e40
/* 03DCEC 7F0091BC AE020000 */  sw    $v0, ($s0)
/* 03DCF0 7F0091C0 34A54CEC */  ori   $a1, (0x3E404CEC & 0xFFFF) # ori $a1, $a1, 0x4cec
/* 03DCF4 7F0091C4 0FC1B39E */  jal   modelSetScale
/* 03DCF8 7F0091C8 00402025 */   move  $a0, $v0
/* 03DCFC 7F0091CC 8E2E0000 */  lw    $t6, ($s1)
/* 03DD00 7F0091D0 8E0F0000 */  lw    $t7, ($s0)
/* 03DD04 7F0091D4 3C018007 */  lui   $at, %hi(dword_CODE_bss_80069594)
/* 03DD08 7F0091D8 ADEE0018 */  sw    $t6, 0x18($t7)
/* 03DD0C 7F0091DC 8E380000 */  lw    $t8, ($s1)
/* 03DD10 7F0091E0 8E0D0000 */  lw    $t5, ($s0)
/* 03DD14 7F0091E4 8F190008 */  lw    $t9, 8($t8)
/* 03DD18 7F0091E8 8F280008 */  lw    $t0, 8($t9)
/* 03DD1C 7F0091EC 8D09000C */  lw    $t1, 0xc($t0)
/* 03DD20 7F0091F0 ADA9001C */  sw    $t1, 0x1c($t5)
/* 03DD24 7F0091F4 8FBF002C */  lw    $ra, 0x2c($sp)
/* 03DD28 7F0091F8 8FB10028 */  lw    $s1, 0x28($sp)
/* 03DD2C 7F0091FC 8FB00024 */  lw    $s0, 0x24($sp)
/* 03DD30 7F009200 AC209594 */  sw    $zero, %lo(dword_CODE_bss_80069594)($at)
/* 03DD34 7F009204 03E00008 */  jr    $ra
/* 03DD38 7F009208 27BD0060 */   addiu $sp, $sp, 0x60
)
#endif
#ifdef VERSION_EU
GLOBAL_ASM(
.late_rodata
glabel eu_cdata_0x28ae0
.word 0x3f68f5c3 /* 0.910000026226 */
.text
glabel sub_GAME_7F008E80
/* 03B7F0 7F008E00 240E0002 */  li    $t6, 2
/* 03B7F4 7F008E04 3C018002 */  lui   $at, %hi(gunbarrel_mode) # $at, 0x8002
/* 03B7F8 7F008E08 A02E5D24 */  sb    $t6, %lo(gunbarrel_mode)($at)
/* 03B7FC 7F008E0C 3C014470 */  li    $at, 0x44700000 # 960.000000
/* 03B800 7F008E10 44812000 */  mtc1  $at, $f4
/* 03B804 7F008E14 27BDFFA0 */  addiu $sp, $sp, -0x60
/* 03B808 7F008E18 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 03B80C 7F008E1C 44813000 */  mtc1  $at, $f6
/* 03B810 7F008E20 44800000 */  mtc1  $zero, $f0
/* 03B814 7F008E24 3C014100 */  li    $at, 0x41000000 # 8.000000
/* 03B818 7F008E28 44814000 */  mtc1  $at, $f8
/* 03B81C 7F008E2C 3C014380 */  li    $at, 0x43800000 # 256.000000
/* 03B820 7F008E30 44815000 */  mtc1  $at, $f10
/* 03B824 7F008E34 AFA40060 */  sw    $a0, 0x60($sp)
/* 03B828 7F008E38 AFA50064 */  sw    $a1, 0x64($sp)
/* 03B82C 7F008E3C AFBF002C */  sw    $ra, 0x2c($sp)
/* 03B830 7F008E40 3C048006 */  lui   $a0, %hi(matrix_buffer_gunbarrel_0) # $a0, 0x8006
/* 03B834 7F008E44 44050000 */  mfc1  $a1, $f0
/* 03B838 7F008E48 44070000 */  mfc1  $a3, $f0
/* 03B83C 7F008E4C AFB10028 */  sw    $s1, 0x28($sp)
/* 03B840 7F008E50 AFB00024 */  sw    $s0, 0x24($sp)
/* 03B844 7F008E54 8C84849C */  lw    $a0, %lo(matrix_buffer_gunbarrel_0)($a0)
/* 03B848 7F008E58 3C0644A0 */  lui   $a2, 0x44a0
/* 03B84C 7F008E5C E7A40010 */  swc1  $f4, 0x10($sp)
/* 03B850 7F008E60 E7A60014 */  swc1  $f6, 0x14($sp)
/* 03B854 7F008E64 E7A80018 */  swc1  $f8, 0x18($sp)
/* 03B858 7F008E68 0C005899 */  jal   guOrtho
/* 03B85C 7F008E6C E7AA001C */   swc1  $f10, 0x1c($sp)
/* 03B860 7F008E70 3C0143F1 */  li    $at, 0x43F10000 # 482.000000
/* 03B864 7F008E74 44810000 */  mtc1  $at, $f0
/* 03B868 7F008E78 3C01C1F0 */  li    $at, 0xC1F00000 # -30.000000
/* 03B86C 7F008E7C 44818000 */  mtc1  $at, $f16
/* 03B870 7F008E80 3C018006 */  lui   $at, %hi(g_TitleX) # $at, 0x8006
/* 03B874 7F008E84 8FA20060 */  lw    $v0, 0x60($sp)
/* 03B878 7F008E88 E43084B4 */  swc1  $f16, %lo(g_TitleX)($at)
/* 03B87C 7F008E8C 3C018006 */  lui   $at, %hi(g_TitleY) # $at, 0x8006
/* 03B880 7F008E90 E42084B8 */  swc1  $f0, %lo(g_TitleY)($at)
/* 03B884 7F008E94 3C01C2C8 */  li    $at, 0xC2C80000 # -100.000000
/* 03B888 7F008E98 44819000 */  mtc1  $at, $f18
/* 03B88C 7F008E9C 3C018006 */  lui   $at, %hi(dword_CODE_bss_8006957C) # $at, 0x8006
/* 03B890 7F008EA0 8FB80064 */  lw    $t8, 0x64($sp)
/* 03B894 7F008EA4 E43284BC */  swc1  $f18, %lo(dword_CODE_bss_8006957C)($at)
/* 03B898 7F008EA8 3C018006 */  lui   $at, %hi(dword_CODE_bss_80069580) # $at, 0x8006
/* 03B89C 7F008EAC E42084C0 */  swc1  $f0, %lo(dword_CODE_bss_80069580)($at)
/* 03B8A0 7F008EB0 3C108006 */  lui   $s0, %hi(dword_CODE_bss_80069550) # $s0, 0x8006
/* 03B8A4 7F008EB4 3C018006 */  lui   $at, %hi(word_CODE_bss_80069584) # $at, 0x8006
/* 03B8A8 7F008EB8 240F0042 */  li    $t7, 66
/* 03B8AC 7F008EBC 26108490 */  addiu $s0, %lo(dword_CODE_bss_80069550) # addiu $s0, $s0, -0x7b70
/* 03B8B0 7F008EC0 A42F84C4 */  sh    $t7, %lo(word_CODE_bss_80069584)($at)
/* 03B8B4 7F008EC4 AE020000 */  sw    $v0, ($s0)
/* 03B8B8 7F008EC8 24420200 */  addiu $v0, $v0, 0x200
/* 03B8BC 7F008ECC 2719FE00 */  addiu $t9, $t8, -0x200
/* 03B8C0 7F008ED0 AFB90064 */  sw    $t9, 0x64($sp)
/* 03B8C4 7F008ED4 AFA20060 */  sw    $v0, 0x60($sp)
/* 03B8C8 7F008ED8 8E040000 */  lw    $a0, ($s0)
/* 03B8CC 7F008EDC 0FC06E50 */  jal   sub_GAME_7F01BAE0
/* 03B8D0 7F008EE0 2405001E */   li    $a1, 30
/* 03B8D4 7F008EE4 8FA30060 */  lw    $v1, 0x60($sp)
/* 03B8D8 7F008EE8 8FA80064 */  lw    $t0, 0x64($sp)
/* 03B8DC 7F008EEC 3C028006 */  lui   $v0, %hi(dword_CODE_bss_80069554) # $v0, 0x8006
/* 03B8E0 7F008EF0 24428494 */  addiu $v0, %lo(dword_CODE_bss_80069554) # addiu $v0, $v0, -0x7b6c
/* 03B8E4 7F008EF4 8E050000 */  lw    $a1, ($s0)
/* 03B8E8 7F008EF8 AC430000 */  sw    $v1, ($v0)
/* 03B8EC 7F008EFC 3C018000 */  lui   $at, 0x8000
/* 03B8F0 7F008F00 24630100 */  addiu $v1, $v1, 0x100
/* 03B8F4 7F008F04 2509FF00 */  addiu $t1, $t0, -0x100
/* 03B8F8 7F008F08 AFA90064 */  sw    $t1, 0x64($sp)
/* 03B8FC 7F008F0C AFA30060 */  sw    $v1, 0x60($sp)
/* 03B900 7F008F10 8C440000 */  lw    $a0, ($v0)
/* 03B904 7F008F14 2406001E */  li    $a2, 30
/* 03B908 7F008F18 0FC06F96 */  jal   sub_GAME_7F01BFF8
/* 03B90C 7F008F1C 00A12821 */   addu  $a1, $a1, $at
/* 03B910 7F008F20 27A40060 */  addiu $a0, $sp, 0x60
/* 03B914 7F008F24 0FC02359 */  jal   sub_GAME_7F008DE4
/* 03B918 7F008F28 27A50064 */   addiu $a1, $sp, 0x64
/* 03B91C 7F008F2C 3C0B8002 */  lui   $t3, %hi(D_8002A8A8) # $t3, 0x8002
/* 03B920 7F008F30 256B5DF8 */  addiu $t3, %lo(D_8002A8A8) # addiu $t3, $t3, 0x5df8
/* 03B924 7F008F34 8D610000 */  lw    $at, ($t3)
/* 03B928 7F008F38 27AA0050 */  addiu $t2, $sp, 0x50
/* 03B92C 7F008F3C 8D6E0004 */  lw    $t6, 4($t3)
/* 03B930 7F008F40 AD410000 */  sw    $at, ($t2)
/* 03B934 7F008F44 8D610008 */  lw    $at, 8($t3)
/* 03B938 7F008F48 3C110001 */  lui   $s1, (0x00012C00 >> 16) # lui $s1, 1
/* 03B93C 7F008F4C 36312C00 */  ori   $s1, (0x00012C00 & 0xFFFF) # ori $s1, $s1, 0x2c00
/* 03B940 7F008F50 AD4E0004 */  sw    $t6, 4($t2)
/* 03B944 7F008F54 AD410008 */  sw    $at, 8($t2)
/* 03B948 7F008F58 8FA50060 */  lw    $a1, 0x60($sp)
/* 03B94C 7F008F5C 02203025 */  move  $a2, $s1
/* 03B950 7F008F60 0FC32C05 */  jal   sub_GAME_7F0CBAF4
/* 03B954 7F008F64 27A40040 */   addiu $a0, $sp, 0x40
/* 03B958 7F008F68 8FA60060 */  lw    $a2, 0x60($sp)
/* 03B95C 7F008F6C 8FA70064 */  lw    $a3, 0x64($sp)
/* 03B960 7F008F70 3C108003 */  lui   $s0, %hi(c_item_entries) # $s0, 0x8003
/* 03B964 7F008F74 26107A60 */  addiu $s0, %lo(c_item_entries) # addiu $s0, $s0, 0x7a60
/* 03B968 7F008F78 27AF0040 */  addiu $t7, $sp, 0x40
/* 03B96C 7F008F7C 00D13021 */  addu  $a2, $a2, $s1
/* 03B970 7F008F80 00F13823 */  subu  $a3, $a3, $s1
/* 03B974 7F008F84 AFA70064 */  sw    $a3, 0x64($sp)
/* 03B978 7F008F88 AFA60060 */  sw    $a2, 0x60($sp)
/* 03B97C 7F008F8C AFAF0010 */  sw    $t7, 0x10($sp)
/* 03B980 7F008F90 8E040064 */  lw    $a0, 0x64($s0)
/* 03B984 7F008F94 0FC1D949 */  jal   load_object_fill_header
/* 03B988 7F008F98 8E050068 */   lw    $a1, 0x68($s0)
/* 03B98C 7F008F9C 0FC2F150 */  jal   get_pc_buffer_remaining_value
/* 03B990 7F008FA0 8E040068 */   lw    $a0, 0x68($s0)
/* 03B994 7F008FA4 2443003F */  addiu $v1, $v0, 0x3f
/* 03B998 7F008FA8 8FA60060 */  lw    $a2, 0x60($sp)
/* 03B99C 7F008FAC 8FA70064 */  lw    $a3, 0x64($sp)
/* 03B9A0 7F008FB0 3478003F */  ori   $t8, $v1, 0x3f
/* 03B9A4 7F008FB4 3B19003F */  xori  $t9, $t8, 0x3f
/* 03B9A8 7F008FB8 27A80040 */  addiu $t0, $sp, 0x40
/* 03B9AC 7F008FBC 00D93021 */  addu  $a2, $a2, $t9
/* 03B9B0 7F008FC0 00F93823 */  subu  $a3, $a3, $t9
/* 03B9B4 7F008FC4 AFA70064 */  sw    $a3, 0x64($sp)
/* 03B9B8 7F008FC8 AFA60060 */  sw    $a2, 0x60($sp)
/* 03B9BC 7F008FCC AFA80010 */  sw    $t0, 0x10($sp)
/* 03B9C0 7F008FD0 8E040618 */  lw    $a0, 0x618($s0)
/* 03B9C4 7F008FD4 0FC1D949 */  jal   load_object_fill_header
/* 03B9C8 7F008FD8 8E05061C */   lw    $a1, 0x61c($s0)
/* 03B9CC 7F008FDC 0FC2F150 */  jal   get_pc_buffer_remaining_value
/* 03B9D0 7F008FE0 8E04061C */   lw    $a0, 0x61c($s0)
/* 03B9D4 7F008FE4 2443003F */  addiu $v1, $v0, 0x3f
/* 03B9D8 7F008FE8 8FAC0064 */  lw    $t4, 0x64($sp)
/* 03B9DC 7F008FEC 8FAB0060 */  lw    $t3, 0x60($sp)
/* 03B9E0 7F008FF0 3469003F */  ori   $t1, $v1, 0x3f
/* 03B9E4 7F008FF4 392D003F */  xori  $t5, $t1, 0x3f
/* 03B9E8 7F008FF8 018D5023 */  subu  $t2, $t4, $t5
/* 03B9EC 7F008FFC 016D7021 */  addu  $t6, $t3, $t5
/* 03B9F0 7F009000 AFAA0064 */  sw    $t2, 0x64($sp)
/* 03B9F4 7F009004 AFAE0060 */  sw    $t6, 0x60($sp)
/* 03B9F8 7F009008 24040005 */  li    $a0, 5
/* 03B9FC 7F00900C 2405004E */  li    $a1, 78
/* 03BA00 7F009010 8E060064 */  lw    $a2, 0x64($s0)
/* 03BA04 7F009014 8E070618 */  lw    $a3, 0x618($s0)
/* 03BA08 7F009018 0FC08D22 */  jal   setup_chr_instance
/* 03BA0C 7F00901C AFA00010 */   sw    $zero, 0x10($sp)
/* 03BA10 7F009020 3C118002 */  lui   $s1, %hi(D_8002A7F4) # $s1, 0x8002
/* 03BA14 7F009024 26315D44 */  addiu $s1, %lo(D_8002A7F4) # addiu $s1, $s1, 0x5d44
/* 03BA18 7F009028 3C053E40 */  lui   $a1, (0x3E404CEC >> 16) # lui $a1, 0x3e40
/* 03BA1C 7F00902C AE220000 */  sw    $v0, ($s1)
/* 03BA20 7F009030 34A54CEC */  ori   $a1, (0x3E404CEC & 0xFFFF) # ori $a1, $a1, 0x4cec
/* 03BA24 7F009034 0FC1B4CF */  jal   modelSetScale
/* 03BA28 7F009038 00402025 */   move  $a0, $v0
/* 03BA2C 7F00903C 8E240000 */  lw    $a0, ($s1)
/* 03BA30 7F009040 0FC1B4D2 */  jal   sub_GAME_7F06CE84
/* 03BA34 7F009044 3C053F80 */   lui   $a1, 0x3f80
/* 03BA38 7F009048 8E240000 */  lw    $a0, ($s1)
/* 03BA3C 7F00904C 0FC1B480 */  jal   setsuboffset
/* 03BA40 7F009050 27A50050 */   addiu $a1, $sp, 0x50
/* 03BA44 7F009054 8E240000 */  lw    $a0, ($s1)
/* 03BA48 7F009058 0FC1B49D */  jal   setsubroty
/* 03BA4C 7F00905C 24050000 */   li    $a1, 0
/* 03BA50 7F009060 3C053F19 */  lui   $a1, (0x3F19999A >> 16) # lui $a1, 0x3f19
/* 03BA54 7F009064 34A5999A */  ori   $a1, (0x3F19999A & 0xFFFF) # ori $a1, $a1, 0x999a
/* 03BA58 7F009068 8E240000 */  lw    $a0, ($s1)
/* 03BA5C 7F00906C 0FC1C02E */  jal   sub_GAME_7F06FF18
/* 03BA60 7F009070 24060000 */   li    $a2, 0
/* 03BA64 7F009074 3C0F8006 */  lui   $t7, %hi(ptr_animation_table) # $t7, 0x8006
/* 03BA68 7F009078 8DEF8478 */  lw    $t7, %lo(ptr_animation_table)($t7)
/* 03BA6C 7F00907C 3C180000 */  lui   $t8, 0
/* 03BA70 7F009080 27184144 */  addiu $t8, $t8, 0x4144
/* 03BA74 7F009084 01F82821 */  addu  $a1, $t7, $t8
/* 03BA78 7F009088 94A30004 */  lhu   $v1, 4($a1)
/* 03BA7C 7F00908C 2462FFBC */  addiu $v0, $v1, -0x44
/* 03BA80 7F009090 04430005 */  bgezl $v0, .L7F0090A8
/* 03BA84 7F009094 44822000 */   mtc1  $v0, $f4
/* 03BA88 7F009098 00431021 */  addu  $v0, $v0, $v1
.L7F00909C:
/* 03BA8C 7F00909C 0442FFFF */  bltzl $v0, .L7F00909C
/* 03BA90 7F0090A0 00431021 */   addu  $v0, $v0, $v1
/* 03BA94 7F0090A4 44822000 */  mtc1  $v0, $f4
.L7F0090A8:
/* 03BA98 7F0090A8 3C018004 */  lui   $at, %hi(eu_cdata_0x28ae0) # $at, 0x8004
/* 03BA9C 7F0090AC C4267730 */  lwc1  $f6, %lo(eu_cdata_0x28ae0)($at)
/* 03BAA0 7F0090B0 46802120 */  cvt.s.w $f4, $f4
/* 03BAA4 7F0090B4 44804000 */  mtc1  $zero, $f8
/* 03BAA8 7F0090B8 8E240000 */  lw    $a0, ($s1)
/* 03BAAC 7F0090BC 00003025 */  move  $a2, $zero
/* 03BAB0 7F0090C0 E7A60010 */  swc1  $f6, 0x10($sp)
/* 03BAB4 7F0090C4 E7A80014 */  swc1  $f8, 0x14($sp)
/* 03BAB8 7F0090C8 44072000 */  mfc1  $a3, $f4
/* 03BABC 7F0090CC 0FC1BF92 */  jal   modelSetAnimation
/* 03BAC0 7F0090D0 00000000 */   nop   
/* 03BAC4 7F0090D4 3C108003 */  lui   $s0, %hi(PitemZ_entries) # $s0, 0x8003
/* 03BAC8 7F0090D8 26104D88 */  addiu $s0, %lo(PitemZ_entries) # addiu $s0, $s0, 0x4d88
/* 03BACC 7F0090DC 27B90040 */  addiu $t9, $sp, 0x40
/* 03BAD0 7F0090E0 AFB90010 */  sw    $t9, 0x10($sp)
/* 03BAD4 7F0090E4 8E0408F4 */  lw    $a0, 0x8f4($s0)
/* 03BAD8 7F0090E8 8E0508F8 */  lw    $a1, 0x8f8($s0)
/* 03BADC 7F0090EC 8FA60060 */  lw    $a2, 0x60($sp)
/* 03BAE0 7F0090F0 0FC1D949 */  jal   load_object_fill_header
/* 03BAE4 7F0090F4 8FA70064 */   lw    $a3, 0x64($sp)
/* 03BAE8 7F0090F8 0FC2F150 */  jal   get_pc_buffer_remaining_value
/* 03BAEC 7F0090FC 8E0408F8 */   lw    $a0, 0x8f8($s0)
/* 03BAF0 7F009100 2443003F */  addiu $v1, $v0, 0x3f
/* 03BAF4 7F009104 8FAD0064 */  lw    $t5, 0x64($sp)
/* 03BAF8 7F009108 8FAA0060 */  lw    $t2, 0x60($sp)
/* 03BAFC 7F00910C 3468003F */  ori   $t0, $v1, 0x3f
/* 03BB00 7F009110 3909003F */  xori  $t1, $t0, 0x3f
/* 03BB04 7F009114 01A96023 */  subu  $t4, $t5, $t1
/* 03BB08 7F009118 01495821 */  addu  $t3, $t2, $t1
/* 03BB0C 7F00911C AFAC0064 */  sw    $t4, 0x64($sp)
/* 03BB10 7F009120 AFAB0060 */  sw    $t3, 0x60($sp)
/* 03BB14 7F009124 0FC1D75F */  jal   modelCalculateRwDataLen
/* 03BB18 7F009128 8E0408F4 */   lw    $a0, 0x8f4($s0)
/* 03BB1C 7F00912C 0FC1B1F5 */  jal   get_obj_instance_controller_for_header
/* 03BB20 7F009130 8E0408F4 */   lw    $a0, 0x8f4($s0)
/* 03BB24 7F009134 3C108002 */  lui   $s0, %hi(D_8002A7F8) # $s0, 0x8002
/* 03BB28 7F009138 26105D48 */  addiu $s0, %lo(D_8002A7F8) # addiu $s0, $s0, 0x5d48
/* 03BB2C 7F00913C 3C053E40 */  lui   $a1, (0x3E404CEC >> 16) # lui $a1, 0x3e40
/* 03BB30 7F009140 AE020000 */  sw    $v0, ($s0)
/* 03BB34 7F009144 34A54CEC */  ori   $a1, (0x3E404CEC & 0xFFFF) # ori $a1, $a1, 0x4cec
/* 03BB38 7F009148 0FC1B4CF */  jal   modelSetScale
/* 03BB3C 7F00914C 00402025 */   move  $a0, $v0
/* 03BB40 7F009150 8E2E0000 */  lw    $t6, ($s1)
/* 03BB44 7F009154 8E0F0000 */  lw    $t7, ($s0)
/* 03BB48 7F009158 3C018006 */  lui   $at, %hi(dword_CODE_bss_80069594) # $at, 0x8006
/* 03BB4C 7F00915C ADEE0018 */  sw    $t6, 0x18($t7)
/* 03BB50 7F009160 8E380000 */  lw    $t8, ($s1)
/* 03BB54 7F009164 8E0D0000 */  lw    $t5, ($s0)
/* 03BB58 7F009168 8F190008 */  lw    $t9, 8($t8)
/* 03BB5C 7F00916C 8F280008 */  lw    $t0, 8($t9)
/* 03BB60 7F009170 8D09000C */  lw    $t1, 0xc($t0)
/* 03BB64 7F009174 ADA9001C */  sw    $t1, 0x1c($t5)
/* 03BB68 7F009178 8FBF002C */  lw    $ra, 0x2c($sp)
/* 03BB6C 7F00917C 8FB10028 */  lw    $s1, 0x28($sp)
/* 03BB70 7F009180 8FB00024 */  lw    $s0, 0x24($sp)
/* 03BB74 7F009184 AC2084D4 */  sw    $zero, %lo(dword_CODE_bss_80069594)($at)
/* 03BB78 7F009188 03E00008 */  jr    $ra
/* 03BB7C 7F00918C 27BD0060 */   addiu $sp, $sp, 0x60
)
#endif
#endif


void sub_GAME_7F00920C(void)
{
    if (D_8002A7F4)
    {
        set_aircraft_obj_inst_scale_to_zero(D_8002A7F4);
    }

    if (D_8002A7F8)
    {
        set_obj_instance_scale_to_zero(D_8002A7F8);
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
        gdl = something_with_gunbarrel_and_rareware_logo_matrix_manip(gdl);
        g_TitleX += XINC;
        if (word_CODE_bss_80069584 < 0) {
            word_CODE_bss_80069584 = 200;
            dword_CODE_bss_8006957C = (g_TitleX - XDEC);
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
        gSPDisplayList(gdl++, &fontDL_0x000);
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
        gdl = insert_bond_eye_intro(insert_sight_backdrop_eye_intro(insert_sniper_sight_eye_intro(gdl)));
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
        gdl = sub_GAME_7F01C400(insert_bond_eye_intro(insert_sight_backdrop_eye_intro(insert_sniper_sight_eye_intro(gdl))));
        if (intro_state_blood_animation != 0) {
            gunbarrel_mode++;
            word_CODE_bss_80069584 = 0;
            dword_CODE_bss_8006957C = g_TitleX;
            intro_eye_counter = 0;
        }
        break;

    case 4:
        word_CODE_bss_80069584 += INCVAL;
        intro_eye_counter++;
        g_TitleX = ((sins(word_CODE_bss_80069584) * 64.0f) / 32768.0f) + dword_CODE_bss_8006957C;
        gdl = sub_GAME_7F01CA18(insert_bond_eye_intro(insert_sight_backdrop_eye_intro(insert_sniper_sight_eye_intro(gdl))));
        if (intro_eye_counter >= INTRO_EYE_COUNTER_CASE_4)
        {
            intro_eye_counter = 0;
            gunbarrel_mode++;
        }
        break;

    case 5:
        word_CODE_bss_80069584 += INCVAL;
        g_TitleX = ((sins(word_CODE_bss_80069584) * 64.0f) / 32768.0f) + dword_CODE_bss_8006957C;
        gdl = sub_GAME_7F01CA18(insert_bond_eye_intro(insert_sight_backdrop_eye_intro(insert_sniper_sight_eye_intro(gdl))));
        
        intro_eye_counter += INTRO_EYE_COUNTER_CASE_5_ADD;
        
        gdl = sub_GAME_7F007E70(gdl, intro_eye_counter);
        if (intro_eye_counter >= 0xF7) {
            intro_eye_counter = 0;
            gunbarrel_mode++;                
        }
        break;

    case 6:
        gSPDisplayList(gdl++, &fontDL_0x000);
        gdl = insert_imageDL(gdl);
        if (intro_eye_counter++ >= INTRO_EYE_COUNTER_CASE_6) {
            intro_eye_counter = 0;
            gunbarrel_mode++;
        }
        break;
    };

    return gdl;
}

s32 sub_GAME_7F009744(void) {
    return (gunbarrel_mode == 9);
}
