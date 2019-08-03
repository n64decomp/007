#include "ultra64.h"

// bss
//CODE.bss:80075DA0
f32 flt_CODE_bss_80075DA0;


// data
//D:80032310     
f32 D_80032310 = 65536.0;
//D:80032314     
f32 D_80032314 = 65536.0;


// rodata
//D:800536F0





#ifdef NONMATCHING
void init_0x40_bytes_data_at_address_last_word_1_0(void) {

}
#else
GLOBAL_ASM(
.text
glabel init_0x40_bytes_data_at_address_last_word_1_0
/* 08CB00 7F057FD0 44801000 */  mtc1  $zero, $f2
/* 08CB04 7F057FD4 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 08CB08 7F057FD8 44810000 */  mtc1  $at, $f0
/* 08CB0C 7F057FDC E4820004 */  swc1  $f2, 4($a0)
/* 08CB10 7F057FE0 E4820008 */  swc1  $f2, 8($a0)
/* 08CB14 7F057FE4 E482000C */  swc1  $f2, 0xc($a0)
/* 08CB18 7F057FE8 E4820010 */  swc1  $f2, 0x10($a0)
/* 08CB1C 7F057FEC E4820018 */  swc1  $f2, 0x18($a0)
/* 08CB20 7F057FF0 E482001C */  swc1  $f2, 0x1c($a0)
/* 08CB24 7F057FF4 E4820020 */  swc1  $f2, 0x20($a0)
/* 08CB28 7F057FF8 E4820024 */  swc1  $f2, 0x24($a0)
/* 08CB2C 7F057FFC E482002C */  swc1  $f2, 0x2c($a0)
/* 08CB30 7F058000 E4820030 */  swc1  $f2, 0x30($a0)
/* 08CB34 7F058004 E4820034 */  swc1  $f2, 0x34($a0)
/* 08CB38 7F058008 E4820038 */  swc1  $f2, 0x38($a0)
/* 08CB3C 7F05800C E4800000 */  swc1  $f0, ($a0)
/* 08CB40 7F058010 E4800014 */  swc1  $f0, 0x14($a0)
/* 08CB44 7F058014 E4800028 */  swc1  $f0, 0x28($a0)
/* 08CB48 7F058018 03E00008 */  jr    $ra
/* 08CB4C 7F05801C E480003C */   swc1  $f0, 0x3c($a0)
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F058020(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F058020
/* 08CB50 7F058020 00803025 */  move  $a2, $a0
/* 08CB54 7F058024 24040004 */  li    $a0, 4
/* 08CB58 7F058028 00001025 */  move  $v0, $zero
/* 08CB5C 7F05802C 00A01825 */  move  $v1, $a1
.L7F058030:
/* 08CB60 7F058030 C4C40000 */  lwc1  $f4, ($a2)
/* 08CB64 7F058034 24420001 */  addiu $v0, $v0, 1
/* 08CB68 7F058038 24630010 */  addiu $v1, $v1, 0x10
/* 08CB6C 7F05803C E464FFF0 */  swc1  $f4, -0x10($v1)
/* 08CB70 7F058040 C4C60004 */  lwc1  $f6, 4($a2)
/* 08CB74 7F058044 24C60010 */  addiu $a2, $a2, 0x10
/* 08CB78 7F058048 E466FFF4 */  swc1  $f6, -0xc($v1)
/* 08CB7C 7F05804C C4C8FFF8 */  lwc1  $f8, -8($a2)
/* 08CB80 7F058050 E468FFF8 */  swc1  $f8, -8($v1)
/* 08CB84 7F058054 C4CAFFFC */  lwc1  $f10, -4($a2)
/* 08CB88 7F058058 1444FFF5 */  bne   $v0, $a0, .L7F058030
/* 08CB8C 7F05805C E46AFFFC */   swc1  $f10, -4($v1)
/* 08CB90 7F058060 03E00008 */  jr    $ra
/* 08CB94 7F058064 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F058068(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F058068
/* 08CB98 7F058068 27BDFFA8 */  addiu $sp, $sp, -0x58
/* 08CB9C 7F05806C AFBF0014 */  sw    $ra, 0x14($sp)
/* 08CBA0 7F058070 AFA5005C */  sw    $a1, 0x5c($sp)
/* 08CBA4 7F058074 0FC16032 */  jal   sub_GAME_7F0580C8
/* 08CBA8 7F058078 27A60018 */   addiu $a2, $sp, 0x18
/* 08CBAC 7F05807C 27A40018 */  addiu $a0, $sp, 0x18
/* 08CBB0 7F058080 0FC16008 */  jal   sub_GAME_7F058020
/* 08CBB4 7F058084 8FA5005C */   lw    $a1, 0x5c($sp)
/* 08CBB8 7F058088 8FBF0014 */  lw    $ra, 0x14($sp)
/* 08CBBC 7F05808C 27BD0058 */  addiu $sp, $sp, 0x58
/* 08CBC0 7F058090 03E00008 */  jr    $ra
/* 08CBC4 7F058094 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F058098(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F058098
/* 08CBC8 7F058098 27BDFFA8 */  addiu $sp, $sp, -0x58
/* 08CBCC 7F05809C AFBF0014 */  sw    $ra, 0x14($sp)
/* 08CBD0 7F0580A0 AFA5005C */  sw    $a1, 0x5c($sp)
/* 08CBD4 7F0580A4 0FC16063 */  jal   sub_GAME_7F05818C
/* 08CBD8 7F0580A8 27A60018 */   addiu $a2, $sp, 0x18
/* 08CBDC 7F0580AC 27A40018 */  addiu $a0, $sp, 0x18
/* 08CBE0 7F0580B0 0FC16008 */  jal   sub_GAME_7F058020
/* 08CBE4 7F0580B4 8FA5005C */   lw    $a1, 0x5c($sp)
/* 08CBE8 7F0580B8 8FBF0014 */  lw    $ra, 0x14($sp)
/* 08CBEC 7F0580BC 27BD0058 */  addiu $sp, $sp, 0x58
/* 08CBF0 7F0580C0 03E00008 */  jr    $ra
/* 08CBF4 7F0580C4 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
s32 sub_GAME_7F0580C8(void *arg0, void *arg1, s32 arg2) {
    s32 temp_v0;
    void *temp_a0;
    void *temp_a3;
    s32 temp_v1;
    void *phi_a3;
    void *phi_t0;
    void *phi_a0;
    s32 phi_v0;
    s32 phi_v1;

    // Node 0
    phi_t0 = arg0;
    phi_v1 = 0;
loop_1:
    // Node 1
    phi_a3 = arg1;
    phi_a0 = (arg2 + phi_v1);
    phi_v0 = 0;
loop_2:
    // Node 2
    temp_v0 = (phi_v0 + 2);
    temp_a0 = (phi_a0 + 0x20);
    temp_a3 = (phi_a3 + 0x20);
    temp_a0->unk-20 = (f32) ((phi_a3->unkC * phi_t0->unk30) + (((*phi_t0 * *phi_a3) + (phi_t0->unk10 * phi_a3->unk4)) + (phi_t0->unk20 * phi_a3->unk8)));
    temp_a0->unk-10 = (f32) ((temp_a3->unk-4 * phi_t0->unk30) + (((*phi_t0 * temp_a3->unk-10) + (phi_t0->unk10 * temp_a3->unk-C)) + (phi_t0->unk20 * temp_a3->unk-8)));
    phi_a3 = temp_a3;
    phi_a0 = temp_a0;
    phi_v0 = temp_v0;
    if (temp_v0 != 4)
    {
        goto loop_2;
    }
    // Node 3
    temp_v1 = (phi_v1 + 4);
    phi_t0 = (phi_t0 + 4);
    phi_v1 = temp_v1;
    if (temp_v1 != 0x10)
    {
        goto loop_1;
    }
    // Node 4
    return temp_v0;
}

#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0580C8
/* 08CBF8 7F0580C8 00001825 */  move  $v1, $zero
/* 08CBFC 7F0580CC 00804025 */  move  $t0, $a0
/* 08CC00 7F0580D0 240A0010 */  li    $t2, 16
/* 08CC04 7F0580D4 24090004 */  li    $t1, 4
.L7F0580D8:
/* 08CC08 7F0580D8 00001025 */  move  $v0, $zero
/* 08CC0C 7F0580DC 00C32021 */  addu  $a0, $a2, $v1
/* 08CC10 7F0580E0 00A03825 */  move  $a3, $a1
.L7F0580E4:
/* 08CC14 7F0580E4 C5120000 */  lwc1  $f18, ($t0)
/* 08CC18 7F0580E8 C4F00000 */  lwc1  $f16, ($a3)
/* 08CC1C 7F0580EC C50E0010 */  lwc1  $f14, 0x10($t0)
/* 08CC20 7F0580F0 C4EC0004 */  lwc1  $f12, 4($a3)
/* 08CC24 7F0580F4 46109402 */  mul.s $f16, $f18, $f16
/* 08CC28 7F0580F8 C5120020 */  lwc1  $f18, 0x20($t0)
/* 08CC2C 7F0580FC C4EA0008 */  lwc1  $f10, 8($a3)
/* 08CC30 7F058100 460C7302 */  mul.s $f12, $f14, $f12
/* 08CC34 7F058104 C4EE000C */  lwc1  $f14, 0xc($a3)
/* 08CC38 7F058108 C5080030 */  lwc1  $f8, 0x30($t0)
/* 08CC3C 7F05810C 460A9282 */  mul.s $f10, $f18, $f10
/* 08CC40 7F058110 24420002 */  addiu $v0, $v0, 2
/* 08CC44 7F058114 24840020 */  addiu $a0, $a0, 0x20
/* 08CC48 7F058118 46087202 */  mul.s $f8, $f14, $f8
/* 08CC4C 7F05811C 24E70020 */  addiu $a3, $a3, 0x20
/* 08CC50 7F058120 460C8300 */  add.s $f12, $f16, $f12
/* 08CC54 7F058124 460A6280 */  add.s $f10, $f12, $f10
/* 08CC58 7F058128 460A4280 */  add.s $f10, $f8, $f10
/* 08CC5C 7F05812C E48AFFE0 */  swc1  $f10, -0x20($a0)
/* 08CC60 7F058130 C50A0000 */  lwc1  $f10, ($t0)
/* 08CC64 7F058134 C4E8FFF0 */  lwc1  $f8, -0x10($a3)
/* 08CC68 7F058138 C50C0010 */  lwc1  $f12, 0x10($t0)
/* 08CC6C 7F05813C C4F0FFF4 */  lwc1  $f16, -0xc($a3)
/* 08CC70 7F058140 46085202 */  mul.s $f8, $f10, $f8
/* 08CC74 7F058144 C50A0020 */  lwc1  $f10, 0x20($t0)
/* 08CC78 7F058148 C4EEFFF8 */  lwc1  $f14, -8($a3)
/* 08CC7C 7F05814C 46106402 */  mul.s $f16, $f12, $f16
/* 08CC80 7F058150 C4ECFFFC */  lwc1  $f12, -4($a3)
/* 08CC84 7F058154 C5120030 */  lwc1  $f18, 0x30($t0)
/* 08CC88 7F058158 460E5382 */  mul.s $f14, $f10, $f14
/* 08CC8C 7F05815C 00000000 */  nop   
/* 08CC90 7F058160 46126482 */  mul.s $f18, $f12, $f18
/* 08CC94 7F058164 46104400 */  add.s $f16, $f8, $f16
/* 08CC98 7F058168 460E8380 */  add.s $f14, $f16, $f14
/* 08CC9C 7F05816C 460E9380 */  add.s $f14, $f18, $f14
/* 08CCA0 7F058170 1449FFDC */  bne   $v0, $t1, .L7F0580E4
/* 08CCA4 7F058174 E48EFFF0 */   swc1  $f14, -0x10($a0)
/* 08CCA8 7F058178 24630004 */  addiu $v1, $v1, 4
/* 08CCAC 7F05817C 146AFFD6 */  bne   $v1, $t2, .L7F0580D8
/* 08CCB0 7F058180 25080004 */   addiu $t0, $t0, 4
/* 08CCB4 7F058184 03E00008 */  jr    $ra
/* 08CCB8 7F058188 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F05818C(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F05818C
/* 08CCBC 7F05818C 00001825 */  move  $v1, $zero
/* 08CCC0 7F058190 00804025 */  move  $t0, $a0
/* 08CCC4 7F058194 240C000C */  li    $t4, 12
/* 08CCC8 7F058198 240B0004 */  li    $t3, 4
/* 08CCCC 7F05819C 240A0002 */  li    $t2, 2
/* 08CCD0 7F0581A0 24090003 */  li    $t1, 3
.L7F0581A4:
/* 08CCD4 7F0581A4 00001025 */  move  $v0, $zero
/* 08CCD8 7F0581A8 00C32021 */  addu  $a0, $a2, $v1
/* 08CCDC 7F0581AC 00A03825 */  move  $a3, $a1
.L7F0581B0:
/* 08CCE0 7F0581B0 C5040000 */  lwc1  $f4, ($t0)
/* 08CCE4 7F0581B4 C4E60000 */  lwc1  $f6, ($a3)
/* 08CCE8 7F0581B8 C50A0010 */  lwc1  $f10, 0x10($t0)
/* 08CCEC 7F0581BC C4F00004 */  lwc1  $f16, 4($a3)
/* 08CCF0 7F0581C0 46062202 */  mul.s $f8, $f4, $f6
/* 08CCF4 7F0581C4 C4E60008 */  lwc1  $f6, 8($a3)
/* 08CCF8 7F0581C8 46105482 */  mul.s $f18, $f10, $f16
/* 08CCFC 7F0581CC C50A0020 */  lwc1  $f10, 0x20($t0)
/* 08CD00 7F0581D0 460A3402 */  mul.s $f16, $f6, $f10
/* 08CD04 7F0581D4 46124100 */  add.s $f4, $f8, $f18
/* 08CD08 7F0581D8 46048200 */  add.s $f8, $f16, $f4
/* 08CD0C 7F0581DC 14490005 */  bne   $v0, $t1, .L7F0581F4
/* 08CD10 7F0581E0 E4880000 */   swc1  $f8, ($a0)
/* 08CD14 7F0581E4 C4920000 */  lwc1  $f18, ($a0)
/* 08CD18 7F0581E8 C5060030 */  lwc1  $f6, 0x30($t0)
/* 08CD1C 7F0581EC 46069280 */  add.s $f10, $f18, $f6
/* 08CD20 7F0581F0 E48A0000 */  swc1  $f10, ($a0)
.L7F0581F4:
/* 08CD24 7F0581F4 C5100000 */  lwc1  $f16, ($t0)
/* 08CD28 7F0581F8 C4E40010 */  lwc1  $f4, 0x10($a3)
/* 08CD2C 7F0581FC C5120010 */  lwc1  $f18, 0x10($t0)
/* 08CD30 7F058200 C4E60014 */  lwc1  $f6, 0x14($a3)
/* 08CD34 7F058204 46048202 */  mul.s $f8, $f16, $f4
/* 08CD38 7F058208 C4E40018 */  lwc1  $f4, 0x18($a3)
/* 08CD3C 7F05820C 24E70020 */  addiu $a3, $a3, 0x20
/* 08CD40 7F058210 46069282 */  mul.s $f10, $f18, $f6
/* 08CD44 7F058214 C5120020 */  lwc1  $f18, 0x20($t0)
/* 08CD48 7F058218 46122182 */  mul.s $f6, $f4, $f18
/* 08CD4C 7F05821C 460A4400 */  add.s $f16, $f8, $f10
/* 08CD50 7F058220 46103200 */  add.s $f8, $f6, $f16
/* 08CD54 7F058224 144A0005 */  bne   $v0, $t2, .L7F05823C
/* 08CD58 7F058228 E4880010 */   swc1  $f8, 0x10($a0)
/* 08CD5C 7F05822C C48A0010 */  lwc1  $f10, 0x10($a0)
/* 08CD60 7F058230 C5040030 */  lwc1  $f4, 0x30($t0)
/* 08CD64 7F058234 46045480 */  add.s $f18, $f10, $f4
/* 08CD68 7F058238 E4920010 */  swc1  $f18, 0x10($a0)
.L7F05823C:
/* 08CD6C 7F05823C 24420002 */  addiu $v0, $v0, 2
/* 08CD70 7F058240 144BFFDB */  bne   $v0, $t3, .L7F0581B0
/* 08CD74 7F058244 24840020 */   addiu $a0, $a0, 0x20
/* 08CD78 7F058248 24630004 */  addiu $v1, $v1, 4
/* 08CD7C 7F05824C 146CFFD5 */  bne   $v1, $t4, .L7F0581A4
/* 08CD80 7F058250 25080004 */   addiu $t0, $t0, 4
/* 08CD84 7F058254 44800000 */  mtc1  $zero, $f0
/* 08CD88 7F058258 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 08CD8C 7F05825C 44813000 */  mtc1  $at, $f6
/* 08CD90 7F058260 E4C0000C */  swc1  $f0, 0xc($a2)
/* 08CD94 7F058264 E4C0001C */  swc1  $f0, 0x1c($a2)
/* 08CD98 7F058268 E4C0002C */  swc1  $f0, 0x2c($a2)
/* 08CD9C 7F05826C 03E00008 */  jr    $ra
/* 08CDA0 7F058270 E4C6003C */   swc1  $f6, 0x3c($a2)
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F058274(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F058274
/* 08CDA4 7F058274 C4A40000 */  lwc1  $f4, ($a1)
/* 08CDA8 7F058278 C4860000 */  lwc1  $f6, ($a0)
/* 08CDAC 7F05827C 46062202 */  mul.s $f8, $f4, $f6
/* 08CDB0 7F058280 E4C80000 */  swc1  $f8, ($a2)
/* 08CDB4 7F058284 C4900000 */  lwc1  $f16, ($a0)
/* 08CDB8 7F058288 C4AA0010 */  lwc1  $f10, 0x10($a1)
/* 08CDBC 7F05828C 46105482 */  mul.s $f18, $f10, $f16
/* 08CDC0 7F058290 E4D20010 */  swc1  $f18, 0x10($a2)
/* 08CDC4 7F058294 C4860000 */  lwc1  $f6, ($a0)
/* 08CDC8 7F058298 C4A40020 */  lwc1  $f4, 0x20($a1)
/* 08CDCC 7F05829C 46062202 */  mul.s $f8, $f4, $f6
/* 08CDD0 7F0582A0 E4C80020 */  swc1  $f8, 0x20($a2)
/* 08CDD4 7F0582A4 C4900000 */  lwc1  $f16, ($a0)
/* 08CDD8 7F0582A8 C4AA0030 */  lwc1  $f10, 0x30($a1)
/* 08CDDC 7F0582AC 46105482 */  mul.s $f18, $f10, $f16
/* 08CDE0 7F0582B0 E4D20030 */  swc1  $f18, 0x30($a2)
/* 08CDE4 7F0582B4 C4860014 */  lwc1  $f6, 0x14($a0)
/* 08CDE8 7F0582B8 C4A40004 */  lwc1  $f4, 4($a1)
/* 08CDEC 7F0582BC 46062202 */  mul.s $f8, $f4, $f6
/* 08CDF0 7F0582C0 E4C80004 */  swc1  $f8, 4($a2)
/* 08CDF4 7F0582C4 C4900014 */  lwc1  $f16, 0x14($a0)
/* 08CDF8 7F0582C8 C4AA0014 */  lwc1  $f10, 0x14($a1)
/* 08CDFC 7F0582CC 46105482 */  mul.s $f18, $f10, $f16
/* 08CE00 7F0582D0 E4D20014 */  swc1  $f18, 0x14($a2)
/* 08CE04 7F0582D4 C4860014 */  lwc1  $f6, 0x14($a0)
/* 08CE08 7F0582D8 C4A40024 */  lwc1  $f4, 0x24($a1)
/* 08CE0C 7F0582DC 46062202 */  mul.s $f8, $f4, $f6
/* 08CE10 7F0582E0 E4C80024 */  swc1  $f8, 0x24($a2)
/* 08CE14 7F0582E4 C4900014 */  lwc1  $f16, 0x14($a0)
/* 08CE18 7F0582E8 C4AA0034 */  lwc1  $f10, 0x34($a1)
/* 08CE1C 7F0582EC 46105482 */  mul.s $f18, $f10, $f16
/* 08CE20 7F0582F0 E4D20034 */  swc1  $f18, 0x34($a2)
/* 08CE24 7F0582F4 C4A40008 */  lwc1  $f4, 8($a1)
/* 08CE28 7F0582F8 C4860028 */  lwc1  $f6, 0x28($a0)
/* 08CE2C 7F0582FC 46062202 */  mul.s $f8, $f4, $f6
/* 08CE30 7F058300 E4C80008 */  swc1  $f8, 8($a2)
/* 08CE34 7F058304 C4AA0018 */  lwc1  $f10, 0x18($a1)
/* 08CE38 7F058308 C4900028 */  lwc1  $f16, 0x28($a0)
/* 08CE3C 7F05830C 46105482 */  mul.s $f18, $f10, $f16
/* 08CE40 7F058310 E4D20018 */  swc1  $f18, 0x18($a2)
/* 08CE44 7F058314 C4A40028 */  lwc1  $f4, 0x28($a1)
/* 08CE48 7F058318 C4860028 */  lwc1  $f6, 0x28($a0)
/* 08CE4C 7F05831C 46062202 */  mul.s $f8, $f4, $f6
/* 08CE50 7F058320 E4C80028 */  swc1  $f8, 0x28($a2)
/* 08CE54 7F058324 C4B00038 */  lwc1  $f16, 0x38($a1)
/* 08CE58 7F058328 C48A0028 */  lwc1  $f10, 0x28($a0)
/* 08CE5C 7F05832C C4840038 */  lwc1  $f4, 0x38($a0)
/* 08CE60 7F058330 46105482 */  mul.s $f18, $f10, $f16
/* 08CE64 7F058334 46122180 */  add.s $f6, $f4, $f18
/* 08CE68 7F058338 E4C60038 */  swc1  $f6, 0x38($a2)
/* 08CE6C 7F05833C C48A002C */  lwc1  $f10, 0x2c($a0)
/* 08CE70 7F058340 C4A80008 */  lwc1  $f8, 8($a1)
/* 08CE74 7F058344 460A4402 */  mul.s $f16, $f8, $f10
/* 08CE78 7F058348 E4D0000C */  swc1  $f16, 0xc($a2)
/* 08CE7C 7F05834C C492002C */  lwc1  $f18, 0x2c($a0)
/* 08CE80 7F058350 C4A40018 */  lwc1  $f4, 0x18($a1)
/* 08CE84 7F058354 46122182 */  mul.s $f6, $f4, $f18
/* 08CE88 7F058358 E4C6001C */  swc1  $f6, 0x1c($a2)
/* 08CE8C 7F05835C C48A002C */  lwc1  $f10, 0x2c($a0)
/* 08CE90 7F058360 C4A80028 */  lwc1  $f8, 0x28($a1)
/* 08CE94 7F058364 460A4402 */  mul.s $f16, $f8, $f10
/* 08CE98 7F058368 E4D0002C */  swc1  $f16, 0x2c($a2)
/* 08CE9C 7F05836C C492002C */  lwc1  $f18, 0x2c($a0)
/* 08CEA0 7F058370 C4A40038 */  lwc1  $f4, 0x38($a1)
/* 08CEA4 7F058374 46122182 */  mul.s $f6, $f4, $f18
/* 08CEA8 7F058378 03E00008 */  jr    $ra
/* 08CEAC 7F05837C E4C6003C */   swc1  $f6, 0x3c($a2)
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F058380(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F058380
/* 08CEB0 7F058380 00803825 */  move  $a3, $a0
/* 08CEB4 7F058384 24040003 */  li    $a0, 3
/* 08CEB8 7F058388 00001025 */  move  $v0, $zero
/* 08CEBC 7F05838C 00C01825 */  move  $v1, $a2
.L7F058390:
/* 08CEC0 7F058390 C4F20000 */  lwc1  $f18, ($a3)
/* 08CEC4 7F058394 C4B00000 */  lwc1  $f16, ($a1)
/* 08CEC8 7F058398 C4EE0010 */  lwc1  $f14, 0x10($a3)
/* 08CECC 7F05839C C4AC0004 */  lwc1  $f12, 4($a1)
/* 08CED0 7F0583A0 46109402 */  mul.s $f16, $f18, $f16
/* 08CED4 7F0583A4 C4B20008 */  lwc1  $f18, 8($a1)
/* 08CED8 7F0583A8 C4EA0020 */  lwc1  $f10, 0x20($a3)
/* 08CEDC 7F0583AC 460C7302 */  mul.s $f12, $f14, $f12
/* 08CEE0 7F0583B0 24420001 */  addiu $v0, $v0, 1
/* 08CEE4 7F0583B4 24630004 */  addiu $v1, $v1, 4
/* 08CEE8 7F0583B8 460A9282 */  mul.s $f10, $f18, $f10
/* 08CEEC 7F0583BC 24E70004 */  addiu $a3, $a3, 4
/* 08CEF0 7F0583C0 460C8300 */  add.s $f12, $f16, $f12
/* 08CEF4 7F0583C4 460C5300 */  add.s $f12, $f10, $f12
/* 08CEF8 7F0583C8 1444FFF1 */  bne   $v0, $a0, .L7F058390
/* 08CEFC 7F0583CC E46CFFFC */   swc1  $f12, -4($v1)
/* 08CF00 7F0583D0 03E00008 */  jr    $ra
/* 08CF04 7F0583D4 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0583D8(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0583D8
/* 08CF08 7F0583D8 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 08CF0C 7F0583DC AFBF0014 */  sw    $ra, 0x14($sp)
/* 08CF10 7F0583E0 27A6001C */  addiu $a2, $sp, 0x1c
/* 08CF14 7F0583E4 0FC160E0 */  jal   sub_GAME_7F058380
/* 08CF18 7F0583E8 AFA5002C */   sw    $a1, 0x2c($sp)
/* 08CF1C 7F0583EC 8FA5002C */  lw    $a1, 0x2c($sp)
/* 08CF20 7F0583F0 C7A4001C */  lwc1  $f4, 0x1c($sp)
/* 08CF24 7F0583F4 E4A40000 */  swc1  $f4, ($a1)
/* 08CF28 7F0583F8 C7A60020 */  lwc1  $f6, 0x20($sp)
/* 08CF2C 7F0583FC E4A60004 */  swc1  $f6, 4($a1)
/* 08CF30 7F058400 C7A80024 */  lwc1  $f8, 0x24($sp)
/* 08CF34 7F058404 E4A80008 */  swc1  $f8, 8($a1)
/* 08CF38 7F058408 8FBF0014 */  lw    $ra, 0x14($sp)
/* 08CF3C 7F05840C 27BD0028 */  addiu $sp, $sp, 0x28
/* 08CF40 7F058410 03E00008 */  jr    $ra
/* 08CF44 7F058414 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F058418(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F058418
/* 08CF48 7F058418 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 08CF4C 7F05841C AFBF0014 */  sw    $ra, 0x14($sp)
/* 08CF50 7F058420 AFA40018 */  sw    $a0, 0x18($sp)
/* 08CF54 7F058424 0FC160E0 */  jal   sub_GAME_7F058380
/* 08CF58 7F058428 AFA60020 */   sw    $a2, 0x20($sp)
/* 08CF5C 7F05842C 8FA40018 */  lw    $a0, 0x18($sp)
/* 08CF60 7F058430 8FA60020 */  lw    $a2, 0x20($sp)
/* 08CF64 7F058434 C4860030 */  lwc1  $f6, 0x30($a0)
/* 08CF68 7F058438 C4C40000 */  lwc1  $f4, ($a2)
/* 08CF6C 7F05843C C4CA0004 */  lwc1  $f10, 4($a2)
/* 08CF70 7F058440 46062200 */  add.s $f8, $f4, $f6
/* 08CF74 7F058444 C4C40008 */  lwc1  $f4, 8($a2)
/* 08CF78 7F058448 E4C80000 */  swc1  $f8, ($a2)
/* 08CF7C 7F05844C C4900034 */  lwc1  $f16, 0x34($a0)
/* 08CF80 7F058450 46105480 */  add.s $f18, $f10, $f16
/* 08CF84 7F058454 E4D20004 */  swc1  $f18, 4($a2)
/* 08CF88 7F058458 C4860038 */  lwc1  $f6, 0x38($a0)
/* 08CF8C 7F05845C 46062200 */  add.s $f8, $f4, $f6
/* 08CF90 7F058460 E4C80008 */  swc1  $f8, 8($a2)
/* 08CF94 7F058464 8FBF0014 */  lw    $ra, 0x14($sp)
/* 08CF98 7F058468 27BD0018 */  addiu $sp, $sp, 0x18
/* 08CF9C 7F05846C 03E00008 */  jr    $ra
/* 08CFA0 7F058470 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F058474(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F058474
/* 08CFA4 7F058474 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 08CFA8 7F058478 AFBF0014 */  sw    $ra, 0x14($sp)
/* 08CFAC 7F05847C AFA40018 */  sw    $a0, 0x18($sp)
/* 08CFB0 7F058480 0FC160F6 */  jal   sub_GAME_7F0583D8
/* 08CFB4 7F058484 AFA5001C */   sw    $a1, 0x1c($sp)
/* 08CFB8 7F058488 8FA40018 */  lw    $a0, 0x18($sp)
/* 08CFBC 7F05848C 8FA5001C */  lw    $a1, 0x1c($sp)
/* 08CFC0 7F058490 C4860030 */  lwc1  $f6, 0x30($a0)
/* 08CFC4 7F058494 C4A40000 */  lwc1  $f4, ($a1)
/* 08CFC8 7F058498 C4AA0004 */  lwc1  $f10, 4($a1)
/* 08CFCC 7F05849C 46062200 */  add.s $f8, $f4, $f6
/* 08CFD0 7F0584A0 C4A40008 */  lwc1  $f4, 8($a1)
/* 08CFD4 7F0584A4 E4A80000 */  swc1  $f8, ($a1)
/* 08CFD8 7F0584A8 C4900034 */  lwc1  $f16, 0x34($a0)
/* 08CFDC 7F0584AC 46105480 */  add.s $f18, $f10, $f16
/* 08CFE0 7F0584B0 E4B20004 */  swc1  $f18, 4($a1)
/* 08CFE4 7F0584B4 C4860038 */  lwc1  $f6, 0x38($a0)
/* 08CFE8 7F0584B8 46062200 */  add.s $f8, $f4, $f6
/* 08CFEC 7F0584BC E4A80008 */  swc1  $f8, 8($a1)
/* 08CFF0 7F0584C0 8FBF0014 */  lw    $ra, 0x14($sp)
/* 08CFF4 7F0584C4 27BD0018 */  addiu $sp, $sp, 0x18
/* 08CFF8 7F0584C8 03E00008 */  jr    $ra
/* 08CFFC 7F0584CC 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0584D0(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0584D0
/* 08D000 7F0584D0 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 08D004 7F0584D4 AFBF0014 */  sw    $ra, 0x14($sp)
/* 08D008 7F0584D8 AFA50024 */  sw    $a1, 0x24($sp)
/* 08D00C 7F0584DC AFA40020 */  sw    $a0, 0x20($sp)
/* 08D010 7F0584E0 C7AC0024 */  lwc1  $f12, 0x24($sp)
/* 08D014 7F0584E4 0FC15FA8 */  jal   cosf
/* 08D018 7F0584E8 AFA60028 */   sw    $a2, 0x28($sp)
/* 08D01C 7F0584EC C7AC0024 */  lwc1  $f12, 0x24($sp)
/* 08D020 7F0584F0 0FC15FAB */  jal   sinf
/* 08D024 7F0584F4 E7A0001C */   swc1  $f0, 0x1c($sp)
/* 08D028 7F0584F8 8FA60028 */  lw    $a2, 0x28($sp)
/* 08D02C 7F0584FC 8FA20020 */  lw    $v0, 0x20($sp)
/* 08D030 7F058500 C7AE001C */  lwc1  $f14, 0x1c($sp)
/* 08D034 7F058504 44801000 */  mtc1  $zero, $f2
/* 08D038 7F058508 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 08D03C 7F05850C 44816000 */  mtc1  $at, $f12
/* 08D040 7F058510 46000107 */  neg.s $f4, $f0
/* 08D044 7F058514 E4C00020 */  swc1  $f0, 0x20($a2)
/* 08D048 7F058518 E4C40008 */  swc1  $f4, 8($a2)
/* 08D04C 7F05851C E4CE0000 */  swc1  $f14, ($a2)
/* 08D050 7F058520 E4CE0028 */  swc1  $f14, 0x28($a2)
/* 08D054 7F058524 E4C20004 */  swc1  $f2, 4($a2)
/* 08D058 7F058528 E4C2000C */  swc1  $f2, 0xc($a2)
/* 08D05C 7F05852C E4C20010 */  swc1  $f2, 0x10($a2)
/* 08D060 7F058530 E4C20018 */  swc1  $f2, 0x18($a2)
/* 08D064 7F058534 E4C2001C */  swc1  $f2, 0x1c($a2)
/* 08D068 7F058538 E4C20024 */  swc1  $f2, 0x24($a2)
/* 08D06C 7F05853C E4C2002C */  swc1  $f2, 0x2c($a2)
/* 08D070 7F058540 E4CC0014 */  swc1  $f12, 0x14($a2)
/* 08D074 7F058544 C4460000 */  lwc1  $f6, ($v0)
/* 08D078 7F058548 E4C60030 */  swc1  $f6, 0x30($a2)
/* 08D07C 7F05854C C4480004 */  lwc1  $f8, 4($v0)
/* 08D080 7F058550 E4C80034 */  swc1  $f8, 0x34($a2)
/* 08D084 7F058554 C44A0008 */  lwc1  $f10, 8($v0)
/* 08D088 7F058558 E4CC003C */  swc1  $f12, 0x3c($a2)
/* 08D08C 7F05855C E4CA0038 */  swc1  $f10, 0x38($a2)
/* 08D090 7F058560 8FBF0014 */  lw    $ra, 0x14($sp)
/* 08D094 7F058564 27BD0020 */  addiu $sp, $sp, 0x20
/* 08D098 7F058568 03E00008 */  jr    $ra
/* 08D09C 7F05856C 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F058570(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F058570
/* 08D0A0 7F058570 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 08D0A4 7F058574 AFBF0014 */  sw    $ra, 0x14($sp)
/* 08D0A8 7F058578 E7AC0020 */  swc1  $f12, 0x20($sp)
/* 08D0AC 7F05857C C7AC0020 */  lwc1  $f12, 0x20($sp)
/* 08D0B0 7F058580 0FC15FA8 */  jal   cosf
/* 08D0B4 7F058584 AFA50024 */   sw    $a1, 0x24($sp)
/* 08D0B8 7F058588 C7AC0020 */  lwc1  $f12, 0x20($sp)
/* 08D0BC 7F05858C 0FC15FAB */  jal   sinf
/* 08D0C0 7F058590 E7A0001C */   swc1  $f0, 0x1c($sp)
/* 08D0C4 7F058594 8FA50024 */  lw    $a1, 0x24($sp)
/* 08D0C8 7F058598 C7AE001C */  lwc1  $f14, 0x1c($sp)
/* 08D0CC 7F05859C 44801000 */  mtc1  $zero, $f2
/* 08D0D0 7F0585A0 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 08D0D4 7F0585A4 44816000 */  mtc1  $at, $f12
/* 08D0D8 7F0585A8 46000107 */  neg.s $f4, $f0
/* 08D0DC 7F0585AC E4A00018 */  swc1  $f0, 0x18($a1)
/* 08D0E0 7F0585B0 E4A40024 */  swc1  $f4, 0x24($a1)
/* 08D0E4 7F0585B4 E4AE0014 */  swc1  $f14, 0x14($a1)
/* 08D0E8 7F0585B8 E4AE0028 */  swc1  $f14, 0x28($a1)
/* 08D0EC 7F0585BC E4A20004 */  swc1  $f2, 4($a1)
/* 08D0F0 7F0585C0 E4A20008 */  swc1  $f2, 8($a1)
/* 08D0F4 7F0585C4 E4A2000C */  swc1  $f2, 0xc($a1)
/* 08D0F8 7F0585C8 E4A20010 */  swc1  $f2, 0x10($a1)
/* 08D0FC 7F0585CC E4A2001C */  swc1  $f2, 0x1c($a1)
/* 08D100 7F0585D0 E4A20020 */  swc1  $f2, 0x20($a1)
/* 08D104 7F0585D4 E4A2002C */  swc1  $f2, 0x2c($a1)
/* 08D108 7F0585D8 E4A20030 */  swc1  $f2, 0x30($a1)
/* 08D10C 7F0585DC E4A20034 */  swc1  $f2, 0x34($a1)
/* 08D110 7F0585E0 E4A20038 */  swc1  $f2, 0x38($a1)
/* 08D114 7F0585E4 E4AC0000 */  swc1  $f12, ($a1)
/* 08D118 7F0585E8 E4AC003C */  swc1  $f12, 0x3c($a1)
/* 08D11C 7F0585EC 8FBF0014 */  lw    $ra, 0x14($sp)
/* 08D120 7F0585F0 27BD0020 */  addiu $sp, $sp, 0x20
/* 08D124 7F0585F4 03E00008 */  jr    $ra
/* 08D128 7F0585F8 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0585FC(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0585FC
/* 08D12C 7F0585FC 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 08D130 7F058600 AFBF0014 */  sw    $ra, 0x14($sp)
/* 08D134 7F058604 E7AC0020 */  swc1  $f12, 0x20($sp)
/* 08D138 7F058608 C7AC0020 */  lwc1  $f12, 0x20($sp)
/* 08D13C 7F05860C 0FC15FA8 */  jal   cosf
/* 08D140 7F058610 AFA50024 */   sw    $a1, 0x24($sp)
/* 08D144 7F058614 C7AC0020 */  lwc1  $f12, 0x20($sp)
/* 08D148 7F058618 0FC15FAB */  jal   sinf
/* 08D14C 7F05861C E7A0001C */   swc1  $f0, 0x1c($sp)
/* 08D150 7F058620 8FA50024 */  lw    $a1, 0x24($sp)
/* 08D154 7F058624 C7AE001C */  lwc1  $f14, 0x1c($sp)
/* 08D158 7F058628 44801000 */  mtc1  $zero, $f2
/* 08D15C 7F05862C 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 08D160 7F058630 44816000 */  mtc1  $at, $f12
/* 08D164 7F058634 46000107 */  neg.s $f4, $f0
/* 08D168 7F058638 E4A00020 */  swc1  $f0, 0x20($a1)
/* 08D16C 7F05863C E4A40008 */  swc1  $f4, 8($a1)
/* 08D170 7F058640 E4AE0000 */  swc1  $f14, ($a1)
/* 08D174 7F058644 E4AE0028 */  swc1  $f14, 0x28($a1)
/* 08D178 7F058648 E4A20004 */  swc1  $f2, 4($a1)
/* 08D17C 7F05864C E4A2000C */  swc1  $f2, 0xc($a1)
/* 08D180 7F058650 E4A20010 */  swc1  $f2, 0x10($a1)
/* 08D184 7F058654 E4A20018 */  swc1  $f2, 0x18($a1)
/* 08D188 7F058658 E4A2001C */  swc1  $f2, 0x1c($a1)
/* 08D18C 7F05865C E4A20024 */  swc1  $f2, 0x24($a1)
/* 08D190 7F058660 E4A2002C */  swc1  $f2, 0x2c($a1)
/* 08D194 7F058664 E4A20030 */  swc1  $f2, 0x30($a1)
/* 08D198 7F058668 E4A20034 */  swc1  $f2, 0x34($a1)
/* 08D19C 7F05866C E4A20038 */  swc1  $f2, 0x38($a1)
/* 08D1A0 7F058670 E4AC0014 */  swc1  $f12, 0x14($a1)
/* 08D1A4 7F058674 E4AC003C */  swc1  $f12, 0x3c($a1)
/* 08D1A8 7F058678 8FBF0014 */  lw    $ra, 0x14($sp)
/* 08D1AC 7F05867C 27BD0020 */  addiu $sp, $sp, 0x20
/* 08D1B0 7F058680 03E00008 */  jr    $ra
/* 08D1B4 7F058684 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F058688(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F058688
/* 08D1B8 7F058688 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 08D1BC 7F05868C AFBF0014 */  sw    $ra, 0x14($sp)
/* 08D1C0 7F058690 E7AC0020 */  swc1  $f12, 0x20($sp)
/* 08D1C4 7F058694 C7AC0020 */  lwc1  $f12, 0x20($sp)
/* 08D1C8 7F058698 0FC15FA8 */  jal   cosf
/* 08D1CC 7F05869C AFA50024 */   sw    $a1, 0x24($sp)
/* 08D1D0 7F0586A0 C7AC0020 */  lwc1  $f12, 0x20($sp)
/* 08D1D4 7F0586A4 0FC15FAB */  jal   sinf
/* 08D1D8 7F0586A8 E7A0001C */   swc1  $f0, 0x1c($sp)
/* 08D1DC 7F0586AC 8FA50024 */  lw    $a1, 0x24($sp)
/* 08D1E0 7F0586B0 C7AE001C */  lwc1  $f14, 0x1c($sp)
/* 08D1E4 7F0586B4 44801000 */  mtc1  $zero, $f2
/* 08D1E8 7F0586B8 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 08D1EC 7F0586BC 44816000 */  mtc1  $at, $f12
/* 08D1F0 7F0586C0 46000107 */  neg.s $f4, $f0
/* 08D1F4 7F0586C4 E4A00004 */  swc1  $f0, 4($a1)
/* 08D1F8 7F0586C8 E4A40010 */  swc1  $f4, 0x10($a1)
/* 08D1FC 7F0586CC E4AE0000 */  swc1  $f14, ($a1)
/* 08D200 7F0586D0 E4AE0014 */  swc1  $f14, 0x14($a1)
/* 08D204 7F0586D4 E4A20008 */  swc1  $f2, 8($a1)
/* 08D208 7F0586D8 E4A2000C */  swc1  $f2, 0xc($a1)
/* 08D20C 7F0586DC E4A20018 */  swc1  $f2, 0x18($a1)
/* 08D210 7F0586E0 E4A2001C */  swc1  $f2, 0x1c($a1)
/* 08D214 7F0586E4 E4A20020 */  swc1  $f2, 0x20($a1)
/* 08D218 7F0586E8 E4A20024 */  swc1  $f2, 0x24($a1)
/* 08D21C 7F0586EC E4A2002C */  swc1  $f2, 0x2c($a1)
/* 08D220 7F0586F0 E4A20030 */  swc1  $f2, 0x30($a1)
/* 08D224 7F0586F4 E4A20034 */  swc1  $f2, 0x34($a1)
/* 08D228 7F0586F8 E4A20038 */  swc1  $f2, 0x38($a1)
/* 08D22C 7F0586FC E4AC0028 */  swc1  $f12, 0x28($a1)
/* 08D230 7F058700 E4AC003C */  swc1  $f12, 0x3c($a1)
/* 08D234 7F058704 8FBF0014 */  lw    $ra, 0x14($sp)
/* 08D238 7F058708 27BD0020 */  addiu $sp, $sp, 0x20
/* 08D23C 7F05870C 03E00008 */  jr    $ra
/* 08D240 7F058710 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F058714(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F058714
/* 08D244 7F058714 27BDFFA8 */  addiu $sp, $sp, -0x58
/* 08D248 7F058718 AFBF001C */  sw    $ra, 0x1c($sp)
/* 08D24C 7F05871C AFB10018 */  sw    $s1, 0x18($sp)
/* 08D250 7F058720 AFB00014 */  sw    $s0, 0x14($sp)
/* 08D254 7F058724 00A08025 */  move  $s0, $a1
/* 08D258 7F058728 00808825 */  move  $s1, $a0
/* 08D25C 7F05872C 0FC15FA8 */  jal   cosf
/* 08D260 7F058730 C48C0000 */   lwc1  $f12, ($a0)
/* 08D264 7F058734 E7A00054 */  swc1  $f0, 0x54($sp)
/* 08D268 7F058738 0FC15FAB */  jal   sinf
/* 08D26C 7F05873C C62C0000 */   lwc1  $f12, ($s1)
/* 08D270 7F058740 E7A00050 */  swc1  $f0, 0x50($sp)
/* 08D274 7F058744 0FC15FA8 */  jal   cosf
/* 08D278 7F058748 C62C0004 */   lwc1  $f12, 4($s1)
/* 08D27C 7F05874C C62C0004 */  lwc1  $f12, 4($s1)
/* 08D280 7F058750 0FC15FAB */  jal   sinf
/* 08D284 7F058754 E7A0004C */   swc1  $f0, 0x4c($sp)
/* 08D288 7F058758 C62C0008 */  lwc1  $f12, 8($s1)
/* 08D28C 7F05875C 0FC15FA8 */  jal   cosf
/* 08D290 7F058760 E7A00048 */   swc1  $f0, 0x48($sp)
/* 08D294 7F058764 C62C0008 */  lwc1  $f12, 8($s1)
/* 08D298 7F058768 0FC15FAB */  jal   sinf
/* 08D29C 7F05876C E7A00044 */   swc1  $f0, 0x44($sp)
/* 08D2A0 7F058770 C7AE004C */  lwc1  $f14, 0x4c($sp)
/* 08D2A4 7F058774 C7B00044 */  lwc1  $f16, 0x44($sp)
/* 08D2A8 7F058778 C7A20048 */  lwc1  $f2, 0x48($sp)
/* 08D2AC 7F05877C 44806000 */  mtc1  $zero, $f12
/* 08D2B0 7F058780 46107102 */  mul.s $f4, $f14, $f16
/* 08D2B4 7F058784 46001207 */  neg.s $f8, $f2
/* 08D2B8 7F058788 E60C000C */  swc1  $f12, 0xc($s0)
/* 08D2BC 7F05878C 46007182 */  mul.s $f6, $f14, $f0
/* 08D2C0 7F058790 E6080008 */  swc1  $f8, 8($s0)
/* 08D2C4 7F058794 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 08D2C8 7F058798 E6040000 */  swc1  $f4, ($s0)
/* 08D2CC 7F05879C E6060004 */  swc1  $f6, 4($s0)
/* 08D2D0 7F0587A0 C7AA0050 */  lwc1  $f10, 0x50($sp)
/* 08D2D4 7F0587A4 C7A60054 */  lwc1  $f6, 0x54($sp)
/* 08D2D8 7F0587A8 46105102 */  mul.s $f4, $f10, $f16
/* 08D2DC 7F0587AC 00000000 */  nop   
/* 08D2E0 7F0587B0 46003202 */  mul.s $f8, $f6, $f0
/* 08D2E4 7F0587B4 00000000 */  nop   
/* 08D2E8 7F0587B8 46022282 */  mul.s $f10, $f4, $f2
/* 08D2EC 7F0587BC E7A40024 */  swc1  $f4, 0x24($sp)
/* 08D2F0 7F0587C0 E7A80028 */  swc1  $f8, 0x28($sp)
/* 08D2F4 7F0587C4 46085181 */  sub.s $f6, $f10, $f8
/* 08D2F8 7F0587C8 E6060010 */  swc1  $f6, 0x10($s0)
/* 08D2FC 7F0587CC C7A40050 */  lwc1  $f4, 0x50($sp)
/* 08D300 7F0587D0 C7AA0054 */  lwc1  $f10, 0x54($sp)
/* 08D304 7F0587D4 46002482 */  mul.s $f18, $f4, $f0
/* 08D308 7F0587D8 00000000 */  nop   
/* 08D30C 7F0587DC 46105202 */  mul.s $f8, $f10, $f16
/* 08D310 7F0587E0 00000000 */  nop   
/* 08D314 7F0587E4 46029182 */  mul.s $f6, $f18, $f2
/* 08D318 7F0587E8 E7A80020 */  swc1  $f8, 0x20($sp)
/* 08D31C 7F0587EC 46083100 */  add.s $f4, $f6, $f8
/* 08D320 7F0587F0 E6040014 */  swc1  $f4, 0x14($s0)
/* 08D324 7F0587F4 C7AA0050 */  lwc1  $f10, 0x50($sp)
/* 08D328 7F0587F8 E60C001C */  swc1  $f12, 0x1c($s0)
/* 08D32C 7F0587FC 460E5182 */  mul.s $f6, $f10, $f14
/* 08D330 7F058800 E6060018 */  swc1  $f6, 0x18($s0)
/* 08D334 7F058804 C7A80020 */  lwc1  $f8, 0x20($sp)
/* 08D338 7F058808 46024102 */  mul.s $f4, $f8, $f2
/* 08D33C 7F05880C 46122280 */  add.s $f10, $f4, $f18
/* 08D340 7F058810 E60A0020 */  swc1  $f10, 0x20($s0)
/* 08D344 7F058814 C7A60028 */  lwc1  $f6, 0x28($sp)
/* 08D348 7F058818 C7A40024 */  lwc1  $f4, 0x24($sp)
/* 08D34C 7F05881C 46023202 */  mul.s $f8, $f6, $f2
/* 08D350 7F058820 46044281 */  sub.s $f10, $f8, $f4
/* 08D354 7F058824 44812000 */  mtc1  $at, $f4
/* 08D358 7F058828 E60A0024 */  swc1  $f10, 0x24($s0)
/* 08D35C 7F05882C C7A60054 */  lwc1  $f6, 0x54($sp)
/* 08D360 7F058830 E60C002C */  swc1  $f12, 0x2c($s0)
/* 08D364 7F058834 E60C0030 */  swc1  $f12, 0x30($s0)
/* 08D368 7F058838 460E3202 */  mul.s $f8, $f6, $f14
/* 08D36C 7F05883C E60C0034 */  swc1  $f12, 0x34($s0)
/* 08D370 7F058840 E60C0038 */  swc1  $f12, 0x38($s0)
/* 08D374 7F058844 E604003C */  swc1  $f4, 0x3c($s0)
/* 08D378 7F058848 E6080028 */  swc1  $f8, 0x28($s0)
/* 08D37C 7F05884C 8FBF001C */  lw    $ra, 0x1c($sp)
/* 08D380 7F058850 8FB10018 */  lw    $s1, 0x18($sp)
/* 08D384 7F058854 8FB00014 */  lw    $s0, 0x14($sp)
/* 08D388 7F058858 03E00008 */  jr    $ra
/* 08D38C 7F05885C 27BD0058 */   addiu $sp, $sp, 0x58
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F058860(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F058860
/* 08D390 7F058860 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 08D394 7F058864 AFBF001C */  sw    $ra, 0x1c($sp)
/* 08D398 7F058868 AFB10018 */  sw    $s1, 0x18($sp)
/* 08D39C 7F05886C AFB00014 */  sw    $s0, 0x14($sp)
/* 08D3A0 7F058870 C4800018 */  lwc1  $f0, 0x18($a0)
/* 08D3A4 7F058874 C4820028 */  lwc1  $f2, 0x28($a0)
/* 08D3A8 7F058878 00808025 */  move  $s0, $a0
/* 08D3AC 7F05887C 46000102 */  mul.s $f4, $f0, $f0
/* 08D3B0 7F058880 00A08825 */  move  $s1, $a1
/* 08D3B4 7F058884 46021182 */  mul.s $f6, $f2, $f2
/* 08D3B8 7F058888 0C007DF8 */  jal   sqrtf
/* 08D3BC 7F05888C 46062300 */   add.s $f12, $f4, $f6
/* 08D3C0 7F058890 3C013600 */  li    $at, 0x36000000 # 0.000002
/* 08D3C4 7F058894 44814000 */  mtc1  $at, $f8
/* 08D3C8 7F058898 E7A00024 */  swc1  $f0, 0x24($sp)
/* 08D3CC 7F05889C 4600403C */  c.lt.s $f8, $f0
/* 08D3D0 7F0588A0 00000000 */  nop   
/* 08D3D4 7F0588A4 45020010 */  bc1fl .L7F0588E8
/* 08D3D8 7F0588A8 44805000 */   mtc1  $zero, $f10
/* 08D3DC 7F0588AC C60C0018 */  lwc1  $f12, 0x18($s0)
/* 08D3E0 7F0588B0 0FC16A8C */  jal   convert_angle_using_inverse
/* 08D3E4 7F0588B4 C60E0028 */   lwc1  $f14, 0x28($s0)
/* 08D3E8 7F0588B8 E6200000 */  swc1  $f0, ($s1)
/* 08D3EC 7F0588BC C60C0008 */  lwc1  $f12, 8($s0)
/* 08D3F0 7F0588C0 C7AE0024 */  lwc1  $f14, 0x24($sp)
/* 08D3F4 7F0588C4 0FC16A8C */  jal   convert_angle_using_inverse
/* 08D3F8 7F0588C8 46006307 */   neg.s $f12, $f12
/* 08D3FC 7F0588CC E6200004 */  swc1  $f0, 4($s1)
/* 08D400 7F0588D0 C60E0000 */  lwc1  $f14, ($s0)
/* 08D404 7F0588D4 0FC16A8C */  jal   convert_angle_using_inverse
/* 08D408 7F0588D8 C60C0004 */   lwc1  $f12, 4($s0)
/* 08D40C 7F0588DC 1000000E */  b     .L7F058918
/* 08D410 7F0588E0 E6200008 */   swc1  $f0, 8($s1)
/* 08D414 7F0588E4 44805000 */  mtc1  $zero, $f10
.L7F0588E8:
/* 08D418 7F0588E8 00000000 */  nop   
/* 08D41C 7F0588EC E62A0000 */  swc1  $f10, ($s1)
/* 08D420 7F0588F0 C60C0008 */  lwc1  $f12, 8($s0)
/* 08D424 7F0588F4 C7AE0024 */  lwc1  $f14, 0x24($sp)
/* 08D428 7F0588F8 0FC16A8C */  jal   convert_angle_using_inverse
/* 08D42C 7F0588FC 46006307 */   neg.s $f12, $f12
/* 08D430 7F058900 E6200004 */  swc1  $f0, 4($s1)
/* 08D434 7F058904 C60C0010 */  lwc1  $f12, 0x10($s0)
/* 08D438 7F058908 C60E0014 */  lwc1  $f14, 0x14($s0)
/* 08D43C 7F05890C 0FC16A8C */  jal   convert_angle_using_inverse
/* 08D440 7F058910 46006307 */   neg.s $f12, $f12
/* 08D444 7F058914 E6200008 */  swc1  $f0, 8($s1)
.L7F058918:
/* 08D448 7F058918 8FBF001C */  lw    $ra, 0x1c($sp)
/* 08D44C 7F05891C 8FB00014 */  lw    $s0, 0x14($sp)
/* 08D450 7F058920 8FB10018 */  lw    $s1, 0x18($sp)
/* 08D454 7F058924 03E00008 */  jr    $ra
/* 08D458 7F058928 27BD0028 */   addiu $sp, $sp, 0x28
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F05892C(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F05892C
/* 08D45C 7F05892C 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 08D460 7F058930 AFA40018 */  sw    $a0, 0x18($sp)
/* 08D464 7F058934 AFBF0014 */  sw    $ra, 0x14($sp)
/* 08D468 7F058938 00A02025 */  move  $a0, $a1
/* 08D46C 7F05893C AFA60020 */  sw    $a2, 0x20($sp)
/* 08D470 7F058940 0FC161C5 */  jal   sub_GAME_7F058714
/* 08D474 7F058944 00C02825 */   move  $a1, $a2
/* 08D478 7F058948 8FA40018 */  lw    $a0, 0x18($sp)
/* 08D47C 7F05894C 0FC16266 */  jal   copies_first_3_floats_from_a0_to_a1_plus_0x30
/* 08D480 7F058950 8FA50020 */   lw    $a1, 0x20($sp)
/* 08D484 7F058954 8FBF0014 */  lw    $ra, 0x14($sp)
/* 08D488 7F058958 27BD0018 */  addiu $sp, $sp, 0x18
/* 08D48C 7F05895C 03E00008 */  jr    $ra
/* 08D490 7F058960 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void init_something_copy_posdata_to_it(void) {

}
#else
GLOBAL_ASM(
.text
glabel init_something_copy_posdata_to_it
/* 08D494 7F058964 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 08D498 7F058968 AFBF0014 */  sw    $ra, 0x14($sp)
/* 08D49C 7F05896C AFA40018 */  sw    $a0, 0x18($sp)
/* 08D4A0 7F058970 AFA5001C */  sw    $a1, 0x1c($sp)
/* 08D4A4 7F058974 0FC15FF4 */  jal   init_0x40_bytes_data_at_address_last_word_1_0
/* 08D4A8 7F058978 00A02025 */   move  $a0, $a1
/* 08D4AC 7F05897C 8FA40018 */  lw    $a0, 0x18($sp)
/* 08D4B0 7F058980 0FC16266 */  jal   copies_first_3_floats_from_a0_to_a1_plus_0x30
/* 08D4B4 7F058984 8FA5001C */   lw    $a1, 0x1c($sp)
/* 08D4B8 7F058988 8FBF0014 */  lw    $ra, 0x14($sp)
/* 08D4BC 7F05898C 27BD0018 */  addiu $sp, $sp, 0x18
/* 08D4C0 7F058990 03E00008 */  jr    $ra
/* 08D4C4 7F058994 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void copies_first_3_floats_from_a0_to_a1_plus_0x30(void) {

}
#else
GLOBAL_ASM(
.text
glabel copies_first_3_floats_from_a0_to_a1_plus_0x30
/* 08D4C8 7F058998 C4840000 */  lwc1  $f4, ($a0)
/* 08D4CC 7F05899C E4A40030 */  swc1  $f4, 0x30($a1)
/* 08D4D0 7F0589A0 C4860004 */  lwc1  $f6, 4($a0)
/* 08D4D4 7F0589A4 E4A60034 */  swc1  $f6, 0x34($a1)
/* 08D4D8 7F0589A8 C4880008 */  lwc1  $f8, 8($a0)
/* 08D4DC 7F0589AC 03E00008 */  jr    $ra
/* 08D4E0 7F0589B0 E4A80038 */   swc1  $f8, 0x38($a1)
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0589B4(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0589B4
/* 08D4E4 7F0589B4 C4A40000 */  lwc1  $f4, ($a1)
/* 08D4E8 7F0589B8 C4A80004 */  lwc1  $f8, 4($a1)
/* 08D4EC 7F0589BC C4B00008 */  lwc1  $f16, 8($a1)
/* 08D4F0 7F0589C0 460C2182 */  mul.s $f6, $f4, $f12
/* 08D4F4 7F0589C4 00000000 */  nop   
/* 08D4F8 7F0589C8 460C4282 */  mul.s $f10, $f8, $f12
/* 08D4FC 7F0589CC 00000000 */  nop   
/* 08D500 7F0589D0 460C8482 */  mul.s $f18, $f16, $f12
/* 08D504 7F0589D4 E4A60000 */  swc1  $f6, ($a1)
/* 08D508 7F0589D8 E4AA0004 */  swc1  $f10, 4($a1)
/* 08D50C 7F0589DC 03E00008 */  jr    $ra
/* 08D510 7F0589E0 E4B20008 */   swc1  $f18, 8($a1)
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0589E4(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0589E4
/* 08D514 7F0589E4 C4A40010 */  lwc1  $f4, 0x10($a1)
/* 08D518 7F0589E8 C4A80014 */  lwc1  $f8, 0x14($a1)
/* 08D51C 7F0589EC C4B00018 */  lwc1  $f16, 0x18($a1)
/* 08D520 7F0589F0 460C2182 */  mul.s $f6, $f4, $f12
/* 08D524 7F0589F4 00000000 */  nop   
/* 08D528 7F0589F8 460C4282 */  mul.s $f10, $f8, $f12
/* 08D52C 7F0589FC 00000000 */  nop   
/* 08D530 7F058A00 460C8482 */  mul.s $f18, $f16, $f12
/* 08D534 7F058A04 E4A60010 */  swc1  $f6, 0x10($a1)
/* 08D538 7F058A08 E4AA0014 */  swc1  $f10, 0x14($a1)
/* 08D53C 7F058A0C 03E00008 */  jr    $ra
/* 08D540 7F058A10 E4B20018 */   swc1  $f18, 0x18($a1)
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F058A14(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F058A14
/* 08D544 7F058A14 C4A40020 */  lwc1  $f4, 0x20($a1)
/* 08D548 7F058A18 C4A80024 */  lwc1  $f8, 0x24($a1)
/* 08D54C 7F058A1C C4B00028 */  lwc1  $f16, 0x28($a1)
/* 08D550 7F058A20 460C2182 */  mul.s $f6, $f4, $f12
/* 08D554 7F058A24 C4A4002C */  lwc1  $f4, 0x2c($a1)
/* 08D558 7F058A28 460C4282 */  mul.s $f10, $f8, $f12
/* 08D55C 7F058A2C 00000000 */  nop   
/* 08D560 7F058A30 460C8482 */  mul.s $f18, $f16, $f12
/* 08D564 7F058A34 E4A60020 */  swc1  $f6, 0x20($a1)
/* 08D568 7F058A38 460C2182 */  mul.s $f6, $f4, $f12
/* 08D56C 7F058A3C E4AA0024 */  swc1  $f10, 0x24($a1)
/* 08D570 7F058A40 E4B20028 */  swc1  $f18, 0x28($a1)
/* 08D574 7F058A44 03E00008 */  jr    $ra
/* 08D578 7F058A48 E4A6002C */   swc1  $f6, 0x2c($a1)
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F058A4C(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F058A4C
/* 08D57C 7F058A4C C4A40020 */  lwc1  $f4, 0x20($a1)
/* 08D580 7F058A50 C4A80024 */  lwc1  $f8, 0x24($a1)
/* 08D584 7F058A54 C4B00028 */  lwc1  $f16, 0x28($a1)
/* 08D588 7F058A58 460C2182 */  mul.s $f6, $f4, $f12
/* 08D58C 7F058A5C 00000000 */  nop   
/* 08D590 7F058A60 460C4282 */  mul.s $f10, $f8, $f12
/* 08D594 7F058A64 00000000 */  nop   
/* 08D598 7F058A68 460C8482 */  mul.s $f18, $f16, $f12
/* 08D59C 7F058A6C E4A60020 */  swc1  $f6, 0x20($a1)
/* 08D5A0 7F058A70 E4AA0024 */  swc1  $f10, 0x24($a1)
/* 08D5A4 7F058A74 03E00008 */  jr    $ra
/* 08D5A8 7F058A78 E4B20028 */   swc1  $f18, 0x28($a1)
)
#endif





#ifdef NONMATCHING
void matrix_multiply_A1_by_F12(void) {

}
#else
GLOBAL_ASM(
.text
glabel matrix_multiply_A1_by_F12
/* 08D5AC 7F058A7C C4A40000 */  lwc1  $f4, ($a1)
/* 08D5B0 7F058A80 C4A80004 */  lwc1  $f8, 4($a1)
/* 08D5B4 7F058A84 C4B00008 */  lwc1  $f16, 8($a1)
/* 08D5B8 7F058A88 460C2182 */  mul.s $f6, $f4, $f12
/* 08D5BC 7F058A8C C4A4000C */  lwc1  $f4, 0xc($a1)
/* 08D5C0 7F058A90 460C4282 */  mul.s $f10, $f8, $f12
/* 08D5C4 7F058A94 C4A80010 */  lwc1  $f8, 0x10($a1)
/* 08D5C8 7F058A98 460C8482 */  mul.s $f18, $f16, $f12
/* 08D5CC 7F058A9C E4A60000 */  swc1  $f6, ($a1)
/* 08D5D0 7F058AA0 C4B00014 */  lwc1  $f16, 0x14($a1)
/* 08D5D4 7F058AA4 460C2182 */  mul.s $f6, $f4, $f12
/* 08D5D8 7F058AA8 E4AA0004 */  swc1  $f10, 4($a1)
/* 08D5DC 7F058AAC C4A40018 */  lwc1  $f4, 0x18($a1)
/* 08D5E0 7F058AB0 460C4282 */  mul.s $f10, $f8, $f12
/* 08D5E4 7F058AB4 E4B20008 */  swc1  $f18, 8($a1)
/* 08D5E8 7F058AB8 C4A8001C */  lwc1  $f8, 0x1c($a1)
/* 08D5EC 7F058ABC 460C8482 */  mul.s $f18, $f16, $f12
/* 08D5F0 7F058AC0 E4A6000C */  swc1  $f6, 0xc($a1)
/* 08D5F4 7F058AC4 C4B00020 */  lwc1  $f16, 0x20($a1)
/* 08D5F8 7F058AC8 460C2182 */  mul.s $f6, $f4, $f12
/* 08D5FC 7F058ACC E4AA0010 */  swc1  $f10, 0x10($a1)
/* 08D600 7F058AD0 C4A40024 */  lwc1  $f4, 0x24($a1)
/* 08D604 7F058AD4 460C4282 */  mul.s $f10, $f8, $f12
/* 08D608 7F058AD8 E4B20014 */  swc1  $f18, 0x14($a1)
/* 08D60C 7F058ADC C4A80028 */  lwc1  $f8, 0x28($a1)
/* 08D610 7F058AE0 460C8482 */  mul.s $f18, $f16, $f12
/* 08D614 7F058AE4 E4A60018 */  swc1  $f6, 0x18($a1)
/* 08D618 7F058AE8 C4B0002C */  lwc1  $f16, 0x2c($a1)
/* 08D61C 7F058AEC 460C2182 */  mul.s $f6, $f4, $f12
/* 08D620 7F058AF0 E4AA001C */  swc1  $f10, 0x1c($a1)
/* 08D624 7F058AF4 460C4282 */  mul.s $f10, $f8, $f12
/* 08D628 7F058AF8 E4B20020 */  swc1  $f18, 0x20($a1)
/* 08D62C 7F058AFC 460C8482 */  mul.s $f18, $f16, $f12
/* 08D630 7F058B00 E4A60024 */  swc1  $f6, 0x24($a1)
/* 08D634 7F058B04 E4AA0028 */  swc1  $f10, 0x28($a1)
/* 08D638 7F058B08 03E00008 */  jr    $ra
/* 08D63C 7F058B0C E4B2002C */   swc1  $f18, 0x2c($a1)
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F058B10(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F058B10
/* 08D640 7F058B10 C4A40000 */  lwc1  $f4, ($a1)
/* 08D644 7F058B14 C4A80004 */  lwc1  $f8, 4($a1)
/* 08D648 7F058B18 C4B00008 */  lwc1  $f16, 8($a1)
/* 08D64C 7F058B1C 460C2182 */  mul.s $f6, $f4, $f12
/* 08D650 7F058B20 C4A40010 */  lwc1  $f4, 0x10($a1)
/* 08D654 7F058B24 460C4282 */  mul.s $f10, $f8, $f12
/* 08D658 7F058B28 C4A80014 */  lwc1  $f8, 0x14($a1)
/* 08D65C 7F058B2C 460C8482 */  mul.s $f18, $f16, $f12
/* 08D660 7F058B30 E4A60000 */  swc1  $f6, ($a1)
/* 08D664 7F058B34 C4B00018 */  lwc1  $f16, 0x18($a1)
/* 08D668 7F058B38 460C2182 */  mul.s $f6, $f4, $f12
/* 08D66C 7F058B3C E4AA0004 */  swc1  $f10, 4($a1)
/* 08D670 7F058B40 C4A40020 */  lwc1  $f4, 0x20($a1)
/* 08D674 7F058B44 460C4282 */  mul.s $f10, $f8, $f12
/* 08D678 7F058B48 E4B20008 */  swc1  $f18, 8($a1)
/* 08D67C 7F058B4C C4A80024 */  lwc1  $f8, 0x24($a1)
/* 08D680 7F058B50 460C8482 */  mul.s $f18, $f16, $f12
/* 08D684 7F058B54 E4A60010 */  swc1  $f6, 0x10($a1)
/* 08D688 7F058B58 C4B00028 */  lwc1  $f16, 0x28($a1)
/* 08D68C 7F058B5C 460C2182 */  mul.s $f6, $f4, $f12
/* 08D690 7F058B60 E4AA0014 */  swc1  $f10, 0x14($a1)
/* 08D694 7F058B64 460C4282 */  mul.s $f10, $f8, $f12
/* 08D698 7F058B68 E4B20018 */  swc1  $f18, 0x18($a1)
/* 08D69C 7F058B6C 460C8482 */  mul.s $f18, $f16, $f12
/* 08D6A0 7F058B70 E4A60020 */  swc1  $f6, 0x20($a1)
/* 08D6A4 7F058B74 E4AA0024 */  swc1  $f10, 0x24($a1)
/* 08D6A8 7F058B78 03E00008 */  jr    $ra
/* 08D6AC 7F058B7C E4B20028 */   swc1  $f18, 0x28($a1)
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F058B80(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F058B80
/* 08D6B0 7F058B80 C4A40008 */  lwc1  $f4, 8($a1)
/* 08D6B4 7F058B84 C4A80018 */  lwc1  $f8, 0x18($a1)
/* 08D6B8 7F058B88 C4B00028 */  lwc1  $f16, 0x28($a1)
/* 08D6BC 7F058B8C 460C2182 */  mul.s $f6, $f4, $f12
/* 08D6C0 7F058B90 C4A40038 */  lwc1  $f4, 0x38($a1)
/* 08D6C4 7F058B94 460C4282 */  mul.s $f10, $f8, $f12
/* 08D6C8 7F058B98 00000000 */  nop   
/* 08D6CC 7F058B9C 460C8482 */  mul.s $f18, $f16, $f12
/* 08D6D0 7F058BA0 E4A60008 */  swc1  $f6, 8($a1)
/* 08D6D4 7F058BA4 460C2182 */  mul.s $f6, $f4, $f12
/* 08D6D8 7F058BA8 E4AA0018 */  swc1  $f10, 0x18($a1)
/* 08D6DC 7F058BAC E4B20028 */  swc1  $f18, 0x28($a1)
/* 08D6E0 7F058BB0 03E00008 */  jr    $ra
/* 08D6E4 7F058BB4 E4A60038 */   swc1  $f6, 0x38($a1)
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F058BB8(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F058BB8
/* 08D6E8 7F058BB8 C4A40000 */  lwc1  $f4, ($a1)
/* 08D6EC 7F058BBC C4A80010 */  lwc1  $f8, 0x10($a1)
/* 08D6F0 7F058BC0 C4B00020 */  lwc1  $f16, 0x20($a1)
/* 08D6F4 7F058BC4 460C2182 */  mul.s $f6, $f4, $f12
/* 08D6F8 7F058BC8 C4A40030 */  lwc1  $f4, 0x30($a1)
/* 08D6FC 7F058BCC 460C4282 */  mul.s $f10, $f8, $f12
/* 08D700 7F058BD0 C4A80004 */  lwc1  $f8, 4($a1)
/* 08D704 7F058BD4 460C8482 */  mul.s $f18, $f16, $f12
/* 08D708 7F058BD8 E4A60000 */  swc1  $f6, ($a1)
/* 08D70C 7F058BDC C4B00014 */  lwc1  $f16, 0x14($a1)
/* 08D710 7F058BE0 460C2182 */  mul.s $f6, $f4, $f12
/* 08D714 7F058BE4 E4AA0010 */  swc1  $f10, 0x10($a1)
/* 08D718 7F058BE8 C4A40024 */  lwc1  $f4, 0x24($a1)
/* 08D71C 7F058BEC 460C4282 */  mul.s $f10, $f8, $f12
/* 08D720 7F058BF0 E4B20020 */  swc1  $f18, 0x20($a1)
/* 08D724 7F058BF4 C4A80034 */  lwc1  $f8, 0x34($a1)
/* 08D728 7F058BF8 460C8482 */  mul.s $f18, $f16, $f12
/* 08D72C 7F058BFC E4A60030 */  swc1  $f6, 0x30($a1)
/* 08D730 7F058C00 C4B00008 */  lwc1  $f16, 8($a1)
/* 08D734 7F058C04 460C2182 */  mul.s $f6, $f4, $f12
/* 08D738 7F058C08 E4AA0004 */  swc1  $f10, 4($a1)
/* 08D73C 7F058C0C C4A40018 */  lwc1  $f4, 0x18($a1)
/* 08D740 7F058C10 460C4282 */  mul.s $f10, $f8, $f12
/* 08D744 7F058C14 E4B20014 */  swc1  $f18, 0x14($a1)
/* 08D748 7F058C18 C4A80028 */  lwc1  $f8, 0x28($a1)
/* 08D74C 7F058C1C 460C8482 */  mul.s $f18, $f16, $f12
/* 08D750 7F058C20 E4A60024 */  swc1  $f6, 0x24($a1)
/* 08D754 7F058C24 C4B00038 */  lwc1  $f16, 0x38($a1)
/* 08D758 7F058C28 460C2182 */  mul.s $f6, $f4, $f12
/* 08D75C 7F058C2C E4AA0034 */  swc1  $f10, 0x34($a1)
/* 08D760 7F058C30 460C4282 */  mul.s $f10, $f8, $f12
/* 08D764 7F058C34 E4B20008 */  swc1  $f18, 8($a1)
/* 08D768 7F058C38 460C8482 */  mul.s $f18, $f16, $f12
/* 08D76C 7F058C3C E4A60018 */  swc1  $f6, 0x18($a1)
/* 08D770 7F058C40 E4AA0028 */  swc1  $f10, 0x28($a1)
/* 08D774 7F058C44 03E00008 */  jr    $ra
/* 08D778 7F058C48 E4B20038 */   swc1  $f18, 0x38($a1)
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F058C4C(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F058C4C
/* 08D77C 7F058C4C 3C014780 */  li    $at, 0x47800000 # 65536.000000
/* 08D780 7F058C50 44812000 */  mtc1  $at, $f4
/* 08D784 7F058C54 3C018003 */  lui   $at, %hi(D_80032310)
/* 08D788 7F058C58 460C2182 */  mul.s $f6, $f4, $f12
/* 08D78C 7F058C5C 03E00008 */  jr    $ra
/* 08D790 7F058C60 E4262310 */   swc1  $f6, %lo(D_80032310)($at)
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F058C64(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F058C64
/* 08D794 7F058C64 3C028003 */  lui   $v0, %hi(D_80032310) # $v0, 0x8003
/* 08D798 7F058C68 24422310 */  addiu $v0, %lo(D_80032310) # addiu $v0, $v0, 0x2310
/* 08D79C 7F058C6C C4440000 */  lwc1  $f4, ($v0)
/* 08D7A0 7F058C70 3C018007 */  lui   $at, %hi(flt_CODE_bss_80075DA0) # $at, 0x8007
/* 08D7A4 7F058C74 E4245DA0 */  swc1  $f4, %lo(flt_CODE_bss_80075DA0)($at)
/* 08D7A8 7F058C78 3C014780 */  li    $at, 0x47800000 # 65536.000000
/* 08D7AC 7F058C7C 44813000 */  mtc1  $at, $f6
/* 08D7B0 7F058C80 03E00008 */  jr    $ra
/* 08D7B4 7F058C84 E4460000 */   swc1  $f6, ($v0)
)
#endif





void sub_GAME_7F058C88(void) {
    D_80032310 = flt_CODE_bss_80075DA0;
}





#ifdef NONMATCHING
void sub_GAME_7F058C9C(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F058C9C
/* 08D7CC 7F058C9C 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 08D7D0 7F058CA0 AFB1000C */  sw    $s1, 0xc($sp)
/* 08D7D4 7F058CA4 AFB30014 */  sw    $s3, 0x14($sp)
/* 08D7D8 7F058CA8 AFB20010 */  sw    $s2, 0x10($sp)
/* 08D7DC 7F058CAC 3C118003 */  lui   $s1, %hi(D_80032310) # $s1, 0x8003
/* 08D7E0 7F058CB0 AFB00008 */  sw    $s0, 8($sp)
/* 08D7E4 7F058CB4 26312310 */  addiu $s1, %lo(D_80032310) # addiu $s1, $s1, 0x2310
/* 08D7E8 7F058CB8 3C12FFFF */  lui   $s2, 0xffff
/* 08D7EC 7F058CBC 24130008 */  li    $s3, 8
/* 08D7F0 7F058CC0 00001025 */  move  $v0, $zero
/* 08D7F4 7F058CC4 00A05825 */  move  $t3, $a1
.L7F058CC8:
/* 08D7F8 7F058CC8 C6320000 */  lwc1  $f18, ($s1)
/* 08D7FC 7F058CCC 000278C0 */  sll   $t7, $v0, 3
/* 08D800 7F058CD0 008F5021 */  addu  $t2, $a0, $t7
/* 08D804 7F058CD4 C5500000 */  lwc1  $f16, ($t2)
/* 08D808 7F058CD8 C54E0004 */  lwc1  $f14, 4($t2)
/* 08D80C 7F058CDC 30590001 */  andi  $t9, $v0, 1
/* 08D810 7F058CE0 46109402 */  mul.s $f16, $f18, $f16
/* 08D814 7F058CE4 00197080 */  sll   $t6, $t9, 2
/* 08D818 7F058CE8 022E7821 */  addu  $t7, $s1, $t6
/* 08D81C 7F058CEC C5F20000 */  lwc1  $f18, ($t7)
/* 08D820 7F058CF0 24470001 */  addiu $a3, $v0, 1
/* 08D824 7F058CF4 24480002 */  addiu $t0, $v0, 2
/* 08D828 7F058CF8 460E9382 */  mul.s $f14, $f18, $f14
/* 08D82C 7F058CFC 4600840D */  trunc.w.s $f16, $f16
/* 08D830 7F058D00 24490003 */  addiu $t1, $v0, 3
/* 08D834 7F058D04 24420004 */  addiu $v0, $v0, 4
/* 08D838 7F058D08 256B0010 */  addiu $t3, $t3, 0x10
/* 08D83C 7F058D0C 44038000 */  mfc1  $v1, $f16
/* 08D840 7F058D10 4600738D */  trunc.w.s $f14, $f14
/* 08D844 7F058D14 0072C824 */  and   $t9, $v1, $s2
/* 08D848 7F058D18 0003C400 */  sll   $t8, $v1, 0x10
/* 08D84C 7F058D1C 44067000 */  mfc1  $a2, $f14
/* 08D850 7F058D20 00000000 */  nop   
/* 08D854 7F058D24 00067402 */  srl   $t6, $a2, 0x10
/* 08D858 7F058D28 032E7825 */  or    $t7, $t9, $t6
/* 08D85C 7F058D2C AD6FFFF0 */  sw    $t7, -0x10($t3)
/* 08D860 7F058D30 30D9FFFF */  andi  $t9, $a2, 0xffff
/* 08D864 7F058D34 03197025 */  or    $t6, $t8, $t9
/* 08D868 7F058D38 AD6E0010 */  sw    $t6, 0x10($t3)
/* 08D86C 7F058D3C C62E0000 */  lwc1  $f14, ($s1)
/* 08D870 7F058D40 0007C0C0 */  sll   $t8, $a3, 3
/* 08D874 7F058D44 00986021 */  addu  $t4, $a0, $t8
/* 08D878 7F058D48 C5900000 */  lwc1  $f16, ($t4)
/* 08D87C 7F058D4C C5920004 */  lwc1  $f18, 4($t4)
/* 08D880 7F058D50 30EE0001 */  andi  $t6, $a3, 1
/* 08D884 7F058D54 46107402 */  mul.s $f16, $f14, $f16
/* 08D888 7F058D58 000E7880 */  sll   $t7, $t6, 2
/* 08D88C 7F058D5C 022FC021 */  addu  $t8, $s1, $t7
/* 08D890 7F058D60 C70E0000 */  lwc1  $f14, ($t8)
/* 08D894 7F058D64 46127482 */  mul.s $f18, $f14, $f18
/* 08D898 7F058D68 4600840D */  trunc.w.s $f16, $f16
/* 08D89C 7F058D6C 44038000 */  mfc1  $v1, $f16
/* 08D8A0 7F058D70 4600948D */  trunc.w.s $f18, $f18
/* 08D8A4 7F058D74 00727024 */  and   $t6, $v1, $s2
/* 08D8A8 7F058D78 0003CC00 */  sll   $t9, $v1, 0x10
/* 08D8AC 7F058D7C 44069000 */  mfc1  $a2, $f18
/* 08D8B0 7F058D80 00000000 */  nop   
/* 08D8B4 7F058D84 00067C02 */  srl   $t7, $a2, 0x10
/* 08D8B8 7F058D88 01CFC025 */  or    $t8, $t6, $t7
/* 08D8BC 7F058D8C AD78FFF4 */  sw    $t8, -0xc($t3)
/* 08D8C0 7F058D90 30CEFFFF */  andi  $t6, $a2, 0xffff
/* 08D8C4 7F058D94 032E7825 */  or    $t7, $t9, $t6
/* 08D8C8 7F058D98 AD6F0014 */  sw    $t7, 0x14($t3)
/* 08D8CC 7F058D9C C6320000 */  lwc1  $f18, ($s1)
/* 08D8D0 7F058DA0 0008C8C0 */  sll   $t9, $t0, 3
/* 08D8D4 7F058DA4 00996821 */  addu  $t5, $a0, $t9
/* 08D8D8 7F058DA8 C5B00000 */  lwc1  $f16, ($t5)
/* 08D8DC 7F058DAC C5AE0004 */  lwc1  $f14, 4($t5)
/* 08D8E0 7F058DB0 310F0001 */  andi  $t7, $t0, 1
/* 08D8E4 7F058DB4 46109402 */  mul.s $f16, $f18, $f16
/* 08D8E8 7F058DB8 000FC080 */  sll   $t8, $t7, 2
/* 08D8EC 7F058DBC 0238C821 */  addu  $t9, $s1, $t8
/* 08D8F0 7F058DC0 C7320000 */  lwc1  $f18, ($t9)
/* 08D8F4 7F058DC4 460E9382 */  mul.s $f14, $f18, $f14
/* 08D8F8 7F058DC8 4600840D */  trunc.w.s $f16, $f16
/* 08D8FC 7F058DCC 44038000 */  mfc1  $v1, $f16
/* 08D900 7F058DD0 4600738D */  trunc.w.s $f14, $f14
/* 08D904 7F058DD4 00727824 */  and   $t7, $v1, $s2
/* 08D908 7F058DD8 00037400 */  sll   $t6, $v1, 0x10
/* 08D90C 7F058DDC 44067000 */  mfc1  $a2, $f14
/* 08D910 7F058DE0 00000000 */  nop   
/* 08D914 7F058DE4 0006C402 */  srl   $t8, $a2, 0x10
/* 08D918 7F058DE8 01F8C825 */  or    $t9, $t7, $t8
/* 08D91C 7F058DEC 30CFFFFF */  andi  $t7, $a2, 0xffff
/* 08D920 7F058DF0 AD79FFF8 */  sw    $t9, -8($t3)
/* 08D924 7F058DF4 01CFC025 */  or    $t8, $t6, $t7
/* 08D928 7F058DF8 AD780018 */  sw    $t8, 0x18($t3)
/* 08D92C 7F058DFC C62E0000 */  lwc1  $f14, ($s1)
/* 08D930 7F058E00 000970C0 */  sll   $t6, $t1, 3
/* 08D934 7F058E04 008E8021 */  addu  $s0, $a0, $t6
/* 08D938 7F058E08 C6100000 */  lwc1  $f16, ($s0)
/* 08D93C 7F058E0C C6120004 */  lwc1  $f18, 4($s0)
/* 08D940 7F058E10 31380001 */  andi  $t8, $t1, 1
/* 08D944 7F058E14 46107402 */  mul.s $f16, $f14, $f16
/* 08D948 7F058E18 0018C880 */  sll   $t9, $t8, 2
/* 08D94C 7F058E1C 02397021 */  addu  $t6, $s1, $t9
/* 08D950 7F058E20 C5CE0000 */  lwc1  $f14, ($t6)
/* 08D954 7F058E24 46127482 */  mul.s $f18, $f14, $f18
/* 08D958 7F058E28 4600840D */  trunc.w.s $f16, $f16
/* 08D95C 7F058E2C 44038000 */  mfc1  $v1, $f16
/* 08D960 7F058E30 4600948D */  trunc.w.s $f18, $f18
/* 08D964 7F058E34 0072C024 */  and   $t8, $v1, $s2
/* 08D968 7F058E38 00037C00 */  sll   $t7, $v1, 0x10
/* 08D96C 7F058E3C 44069000 */  mfc1  $a2, $f18
/* 08D970 7F058E40 00000000 */  nop   
/* 08D974 7F058E44 0006CC02 */  srl   $t9, $a2, 0x10
/* 08D978 7F058E48 03197025 */  or    $t6, $t8, $t9
/* 08D97C 7F058E4C 30D8FFFF */  andi  $t8, $a2, 0xffff
/* 08D980 7F058E50 01F8C825 */  or    $t9, $t7, $t8
/* 08D984 7F058E54 AD6EFFFC */  sw    $t6, -4($t3)
/* 08D988 7F058E58 1453FF9B */  bne   $v0, $s3, .L7F058CC8
/* 08D98C 7F058E5C AD79001C */   sw    $t9, 0x1c($t3)
/* 08D990 7F058E60 8FB00008 */  lw    $s0, 8($sp)
/* 08D994 7F058E64 8FB1000C */  lw    $s1, 0xc($sp)
/* 08D998 7F058E68 8FB20010 */  lw    $s2, 0x10($sp)
/* 08D99C 7F058E6C 8FB30014 */  lw    $s3, 0x14($sp)
/* 08D9A0 7F058E70 03E00008 */  jr    $ra
/* 08D9A4 7F058E74 27BD0018 */   addiu $sp, $sp, 0x18
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F058E78(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F058E78
/* 08D9A8 7F058E78 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 08D9AC 7F058E7C AFB20010 */  sw    $s2, 0x10($sp)
/* 08D9B0 7F058E80 AFB30014 */  sw    $s3, 0x14($sp)
/* 08D9B4 7F058E84 AFB1000C */  sw    $s1, 0xc($sp)
/* 08D9B8 7F058E88 3C128003 */  lui   $s2, %hi(D_80032310) # $s2, 0x8003
/* 08D9BC 7F058E8C AFB00008 */  sw    $s0, 8($sp)
/* 08D9C0 7F058E90 26522310 */  addiu $s2, %lo(D_80032310) # addiu $s2, $s2, 0x2310
/* 08D9C4 7F058E94 3C11FFFF */  lui   $s1, 0xffff
/* 08D9C8 7F058E98 24130008 */  li    $s3, 8
/* 08D9CC 7F058E9C 00001025 */  move  $v0, $zero
/* 08D9D0 7F058EA0 00805025 */  move  $t2, $a0
.L7F058EA4:
/* 08D9D4 7F058EA4 8D430000 */  lw    $v1, ($t2)
/* 08D9D8 7F058EA8 8D460020 */  lw    $a2, 0x20($t2)
/* 08D9DC 7F058EAC C6480000 */  lwc1  $f8, ($s2)
/* 08D9E0 7F058EB0 0071C024 */  and   $t8, $v1, $s1
/* 08D9E4 7F058EB4 0006CC02 */  srl   $t9, $a2, 0x10
/* 08D9E8 7F058EB8 03197025 */  or    $t6, $t8, $t9
/* 08D9EC 7F058EBC 448E2000 */  mtc1  $t6, $f4
/* 08D9F0 7F058EC0 000278C0 */  sll   $t7, $v0, 3
/* 08D9F4 7F058EC4 00AF5821 */  addu  $t3, $a1, $t7
/* 08D9F8 7F058EC8 468021A0 */  cvt.s.w $f6, $f4
/* 08D9FC 7F058ECC 00037C00 */  sll   $t7, $v1, 0x10
/* 08DA00 7F058ED0 30D8FFFF */  andi  $t8, $a2, 0xffff
/* 08DA04 7F058ED4 01F8C825 */  or    $t9, $t7, $t8
/* 08DA08 7F058ED8 44998000 */  mtc1  $t9, $f16
/* 08DA0C 7F058EDC 304E0001 */  andi  $t6, $v0, 1
/* 08DA10 7F058EE0 46083283 */  div.s $f10, $f6, $f8
/* 08DA14 7F058EE4 000E7880 */  sll   $t7, $t6, 2
/* 08DA18 7F058EE8 024FC021 */  addu  $t8, $s2, $t7
/* 08DA1C 7F058EEC 24470001 */  addiu $a3, $v0, 1
/* 08DA20 7F058EF0 468084A0 */  cvt.s.w $f18, $f16
/* 08DA24 7F058EF4 000770C0 */  sll   $t6, $a3, 3
/* 08DA28 7F058EF8 00AE6021 */  addu  $t4, $a1, $t6
/* 08DA2C 7F058EFC 24480002 */  addiu $t0, $v0, 2
/* 08DA30 7F058F00 24490003 */  addiu $t1, $v0, 3
/* 08DA34 7F058F04 24420004 */  addiu $v0, $v0, 4
/* 08DA38 7F058F08 254A0010 */  addiu $t2, $t2, 0x10
/* 08DA3C 7F058F0C E56A0000 */  swc1  $f10, ($t3)
/* 08DA40 7F058F10 C7040000 */  lwc1  $f4, ($t8)
/* 08DA44 7F058F14 46049183 */  div.s $f6, $f18, $f4
/* 08DA48 7F058F18 E5660004 */  swc1  $f6, 4($t3)
/* 08DA4C 7F058F1C 8D460014 */  lw    $a2, 0x14($t2)
/* 08DA50 7F058F20 8D43FFF4 */  lw    $v1, -0xc($t2)
/* 08DA54 7F058F24 C6500000 */  lwc1  $f16, ($s2)
/* 08DA58 7F058F28 0006C402 */  srl   $t8, $a2, 0x10
/* 08DA5C 7F058F2C 00717824 */  and   $t7, $v1, $s1
/* 08DA60 7F058F30 01F8C825 */  or    $t9, $t7, $t8
/* 08DA64 7F058F34 44994000 */  mtc1  $t9, $f8
/* 08DA68 7F058F38 30CFFFFF */  andi  $t7, $a2, 0xffff
/* 08DA6C 7F058F3C 00037400 */  sll   $t6, $v1, 0x10
/* 08DA70 7F058F40 468042A0 */  cvt.s.w $f10, $f8
/* 08DA74 7F058F44 01CFC025 */  or    $t8, $t6, $t7
/* 08DA78 7F058F48 44982000 */  mtc1  $t8, $f4
/* 08DA7C 7F058F4C 30F90001 */  andi  $t9, $a3, 1
/* 08DA80 7F058F50 00197080 */  sll   $t6, $t9, 2
/* 08DA84 7F058F54 468021A0 */  cvt.s.w $f6, $f4
/* 08DA88 7F058F58 024E7821 */  addu  $t7, $s2, $t6
/* 08DA8C 7F058F5C 0008C8C0 */  sll   $t9, $t0, 3
/* 08DA90 7F058F60 00B96821 */  addu  $t5, $a1, $t9
/* 08DA94 7F058F64 46105483 */  div.s $f18, $f10, $f16
/* 08DA98 7F058F68 E5920000 */  swc1  $f18, ($t4)
/* 08DA9C 7F058F6C C5E80000 */  lwc1  $f8, ($t7)
/* 08DAA0 7F058F70 46083283 */  div.s $f10, $f6, $f8
/* 08DAA4 7F058F74 E58A0004 */  swc1  $f10, 4($t4)
/* 08DAA8 7F058F78 8D460018 */  lw    $a2, 0x18($t2)
/* 08DAAC 7F058F7C 8D43FFF8 */  lw    $v1, -8($t2)
/* 08DAB0 7F058F80 C6440000 */  lwc1  $f4, ($s2)
/* 08DAB4 7F058F84 00067C02 */  srl   $t7, $a2, 0x10
/* 08DAB8 7F058F88 00717024 */  and   $t6, $v1, $s1
/* 08DABC 7F058F8C 01CFC025 */  or    $t8, $t6, $t7
/* 08DAC0 7F058F90 44988000 */  mtc1  $t8, $f16
/* 08DAC4 7F058F94 30CEFFFF */  andi  $t6, $a2, 0xffff
/* 08DAC8 7F058F98 0003CC00 */  sll   $t9, $v1, 0x10
/* 08DACC 7F058F9C 468084A0 */  cvt.s.w $f18, $f16
/* 08DAD0 7F058FA0 032E7825 */  or    $t7, $t9, $t6
/* 08DAD4 7F058FA4 448F4000 */  mtc1  $t7, $f8
/* 08DAD8 7F058FA8 31180001 */  andi  $t8, $t0, 1
/* 08DADC 7F058FAC 0018C880 */  sll   $t9, $t8, 2
/* 08DAE0 7F058FB0 468042A0 */  cvt.s.w $f10, $f8
/* 08DAE4 7F058FB4 02597021 */  addu  $t6, $s2, $t9
/* 08DAE8 7F058FB8 0009C0C0 */  sll   $t8, $t1, 3
/* 08DAEC 7F058FBC 00B88021 */  addu  $s0, $a1, $t8
/* 08DAF0 7F058FC0 46049183 */  div.s $f6, $f18, $f4
/* 08DAF4 7F058FC4 E5A60000 */  swc1  $f6, ($t5)
/* 08DAF8 7F058FC8 C5D00000 */  lwc1  $f16, ($t6)
/* 08DAFC 7F058FCC 46105483 */  div.s $f18, $f10, $f16
/* 08DB00 7F058FD0 E5B20004 */  swc1  $f18, 4($t5)
/* 08DB04 7F058FD4 8D46001C */  lw    $a2, 0x1c($t2)
/* 08DB08 7F058FD8 8D43FFFC */  lw    $v1, -4($t2)
/* 08DB0C 7F058FDC C6480000 */  lwc1  $f8, ($s2)
/* 08DB10 7F058FE0 00067402 */  srl   $t6, $a2, 0x10
/* 08DB14 7F058FE4 0071C824 */  and   $t9, $v1, $s1
/* 08DB18 7F058FE8 032E7825 */  or    $t7, $t9, $t6
/* 08DB1C 7F058FEC 448F2000 */  mtc1  $t7, $f4
/* 08DB20 7F058FF0 30D9FFFF */  andi  $t9, $a2, 0xffff
/* 08DB24 7F058FF4 0003C400 */  sll   $t8, $v1, 0x10
/* 08DB28 7F058FF8 468021A0 */  cvt.s.w $f6, $f4
/* 08DB2C 7F058FFC 03197025 */  or    $t6, $t8, $t9
/* 08DB30 7F059000 448E8000 */  mtc1  $t6, $f16
/* 08DB34 7F059004 312F0001 */  andi  $t7, $t1, 1
/* 08DB38 7F059008 000FC080 */  sll   $t8, $t7, 2
/* 08DB3C 7F05900C 468084A0 */  cvt.s.w $f18, $f16
/* 08DB40 7F059010 0258C821 */  addu  $t9, $s2, $t8
/* 08DB44 7F059014 46083283 */  div.s $f10, $f6, $f8
/* 08DB48 7F059018 E60A0000 */  swc1  $f10, ($s0)
/* 08DB4C 7F05901C C7240000 */  lwc1  $f4, ($t9)
/* 08DB50 7F059020 46049183 */  div.s $f6, $f18, $f4
/* 08DB54 7F059024 1453FF9F */  bne   $v0, $s3, .L7F058EA4
/* 08DB58 7F059028 E6060004 */   swc1  $f6, 4($s0)
/* 08DB5C 7F05902C 8FB00008 */  lw    $s0, 8($sp)
/* 08DB60 7F059030 8FB1000C */  lw    $s1, 0xc($sp)
/* 08DB64 7F059034 8FB20010 */  lw    $s2, 0x10($sp)
/* 08DB68 7F059038 8FB30014 */  lw    $s3, 0x14($sp)
/* 08DB6C 7F05903C 03E00008 */  jr    $ra
/* 08DB70 7F059040 27BD0018 */   addiu $sp, $sp, 0x18
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F059044(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F059044
/* 08DB74 7F059044 3C014780 */  li    $at, 0x47800000 # 65536.000000
/* 08DB78 7F059048 00803025 */  move  $a2, $a0
/* 08DB7C 7F05904C 44810000 */  mtc1  $at, $f0
/* 08DB80 7F059050 24040004 */  li    $a0, 4
/* 08DB84 7F059054 00001025 */  move  $v0, $zero
/* 08DB88 7F059058 00A01825 */  move  $v1, $a1
/* 08DB8C 7F05905C C4D00000 */  lwc1  $f16, ($a2)
/* 08DB90 7F059060 24420001 */  addiu $v0, $v0, 1
/* 08DB94 7F059064 46008482 */  mul.s $f18, $f16, $f0
/* 08DB98 7F059068 5044001F */  beql  $v0, $a0, .L7F0590E8
/* 08DB9C 7F05906C 4600940D */   trunc.w.s $f16, $f18
/* 08DBA0 7F059070 4600940D */  trunc.w.s $f16, $f18
.L7F059074:
/* 08DBA4 7F059074 24420001 */  addiu $v0, $v0, 1
/* 08DBA8 7F059078 24630010 */  addiu $v1, $v1, 0x10
/* 08DBAC 7F05907C 24C60010 */  addiu $a2, $a2, 0x10
/* 08DBB0 7F059080 440F8000 */  mfc1  $t7, $f16
/* 08DBB4 7F059084 00000000 */  nop   
/* 08DBB8 7F059088 AC6FFFF0 */  sw    $t7, -0x10($v1)
/* 08DBBC 7F05908C C4D0FFF4 */  lwc1  $f16, -0xc($a2)
/* 08DBC0 7F059090 46008402 */  mul.s $f16, $f16, $f0
/* 08DBC4 7F059094 4600840D */  trunc.w.s $f16, $f16
/* 08DBC8 7F059098 44198000 */  mfc1  $t9, $f16
/* 08DBCC 7F05909C 00000000 */  nop   
/* 08DBD0 7F0590A0 AC79FFF4 */  sw    $t9, -0xc($v1)
/* 08DBD4 7F0590A4 C4D0FFF8 */  lwc1  $f16, -8($a2)
/* 08DBD8 7F0590A8 46008402 */  mul.s $f16, $f16, $f0
/* 08DBDC 7F0590AC 4600840D */  trunc.w.s $f16, $f16
/* 08DBE0 7F0590B0 44098000 */  mfc1  $t1, $f16
/* 08DBE4 7F0590B4 00000000 */  nop   
/* 08DBE8 7F0590B8 AC69FFF8 */  sw    $t1, -8($v1)
/* 08DBEC 7F0590BC C4D0FFFC */  lwc1  $f16, -4($a2)
/* 08DBF0 7F0590C0 46008402 */  mul.s $f16, $f16, $f0
/* 08DBF4 7F0590C4 4600840D */  trunc.w.s $f16, $f16
/* 08DBF8 7F0590C8 440B8000 */  mfc1  $t3, $f16
/* 08DBFC 7F0590CC 00000000 */  nop   
/* 08DC00 7F0590D0 AC6BFFFC */  sw    $t3, -4($v1)
/* 08DC04 7F0590D4 C4D00000 */  lwc1  $f16, ($a2)
/* 08DC08 7F0590D8 46008482 */  mul.s $f18, $f16, $f0
/* 08DC0C 7F0590DC 5444FFE5 */  bnel  $v0, $a0, .L7F059074
/* 08DC10 7F0590E0 4600940D */   trunc.w.s $f16, $f18
/* 08DC14 7F0590E4 4600940D */  trunc.w.s $f16, $f18
.L7F0590E8:
/* 08DC18 7F0590E8 24630010 */  addiu $v1, $v1, 0x10
/* 08DC1C 7F0590EC 24C60010 */  addiu $a2, $a2, 0x10
/* 08DC20 7F0590F0 440F8000 */  mfc1  $t7, $f16
/* 08DC24 7F0590F4 00000000 */  nop   
/* 08DC28 7F0590F8 AC6FFFF0 */  sw    $t7, -0x10($v1)
/* 08DC2C 7F0590FC C4D0FFF4 */  lwc1  $f16, -0xc($a2)
/* 08DC30 7F059100 46008402 */  mul.s $f16, $f16, $f0
/* 08DC34 7F059104 4600840D */  trunc.w.s $f16, $f16
/* 08DC38 7F059108 44198000 */  mfc1  $t9, $f16
/* 08DC3C 7F05910C 00000000 */  nop   
/* 08DC40 7F059110 AC79FFF4 */  sw    $t9, -0xc($v1)
/* 08DC44 7F059114 C4D0FFF8 */  lwc1  $f16, -8($a2)
/* 08DC48 7F059118 46008402 */  mul.s $f16, $f16, $f0
/* 08DC4C 7F05911C 4600840D */  trunc.w.s $f16, $f16
/* 08DC50 7F059120 44098000 */  mfc1  $t1, $f16
/* 08DC54 7F059124 00000000 */  nop   
/* 08DC58 7F059128 AC69FFF8 */  sw    $t1, -8($v1)
/* 08DC5C 7F05912C C4D0FFFC */  lwc1  $f16, -4($a2)
/* 08DC60 7F059130 46008402 */  mul.s $f16, $f16, $f0
/* 08DC64 7F059134 4600840D */  trunc.w.s $f16, $f16
/* 08DC68 7F059138 440B8000 */  mfc1  $t3, $f16
/* 08DC6C 7F05913C 00000000 */  nop   
/* 08DC70 7F059140 AC6BFFFC */  sw    $t3, -4($v1)
/* 08DC74 7F059144 03E00008 */  jr    $ra
/* 08DC78 7F059148 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F05914C(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F05914C
/* 08DC7C 7F05914C 3C014780 */  li    $at, 0x47800000 # 65536.000000
/* 08DC80 7F059150 00803025 */  move  $a2, $a0
/* 08DC84 7F059154 44810000 */  mtc1  $at, $f0
/* 08DC88 7F059158 24040004 */  li    $a0, 4
/* 08DC8C 7F05915C 00001025 */  move  $v0, $zero
/* 08DC90 7F059160 00A01825 */  move  $v1, $a1
/* 08DC94 7F059164 24420001 */  addiu $v0, $v0, 1
/* 08DC98 7F059168 1044001C */  beq   $v0, $a0, .L7F0591DC
/* 08DC9C 7F05916C 8CCE0000 */   lw    $t6, ($a2)
.L7F059170:
/* 08DCA0 7F059170 448E9000 */  mtc1  $t6, $f18
/* 08DCA4 7F059174 24420001 */  addiu $v0, $v0, 1
/* 08DCA8 7F059178 24630010 */  addiu $v1, $v1, 0x10
/* 08DCAC 7F05917C 468094A0 */  cvt.s.w $f18, $f18
/* 08DCB0 7F059180 24C60010 */  addiu $a2, $a2, 0x10
/* 08DCB4 7F059184 46009483 */  div.s $f18, $f18, $f0
/* 08DCB8 7F059188 E472FFF0 */  swc1  $f18, -0x10($v1)
/* 08DCBC 7F05918C 8CCFFFF4 */  lw    $t7, -0xc($a2)
/* 08DCC0 7F059190 448F9000 */  mtc1  $t7, $f18
/* 08DCC4 7F059194 00000000 */  nop   
/* 08DCC8 7F059198 468094A0 */  cvt.s.w $f18, $f18
/* 08DCCC 7F05919C 46009483 */  div.s $f18, $f18, $f0
/* 08DCD0 7F0591A0 E472FFF4 */  swc1  $f18, -0xc($v1)
/* 08DCD4 7F0591A4 8CD8FFF8 */  lw    $t8, -8($a2)
/* 08DCD8 7F0591A8 44989000 */  mtc1  $t8, $f18
/* 08DCDC 7F0591AC 00000000 */  nop   
/* 08DCE0 7F0591B0 468094A0 */  cvt.s.w $f18, $f18
/* 08DCE4 7F0591B4 46009483 */  div.s $f18, $f18, $f0
/* 08DCE8 7F0591B8 E472FFF8 */  swc1  $f18, -8($v1)
/* 08DCEC 7F0591BC 8CD9FFFC */  lw    $t9, -4($a2)
/* 08DCF0 7F0591C0 44999000 */  mtc1  $t9, $f18
/* 08DCF4 7F0591C4 00000000 */  nop   
/* 08DCF8 7F0591C8 468094A0 */  cvt.s.w $f18, $f18
/* 08DCFC 7F0591CC 46009483 */  div.s $f18, $f18, $f0
/* 08DD00 7F0591D0 E472FFFC */  swc1  $f18, -4($v1)
/* 08DD04 7F0591D4 1444FFE6 */  bne   $v0, $a0, .L7F059170
/* 08DD08 7F0591D8 8CCE0000 */   lw    $t6, ($a2)
.L7F0591DC:
/* 08DD0C 7F0591DC 448E9000 */  mtc1  $t6, $f18
/* 08DD10 7F0591E0 24630010 */  addiu $v1, $v1, 0x10
/* 08DD14 7F0591E4 24C60010 */  addiu $a2, $a2, 0x10
/* 08DD18 7F0591E8 468094A0 */  cvt.s.w $f18, $f18
/* 08DD1C 7F0591EC 46009483 */  div.s $f18, $f18, $f0
/* 08DD20 7F0591F0 E472FFF0 */  swc1  $f18, -0x10($v1)
/* 08DD24 7F0591F4 8CCFFFF4 */  lw    $t7, -0xc($a2)
/* 08DD28 7F0591F8 448F9000 */  mtc1  $t7, $f18
/* 08DD2C 7F0591FC 00000000 */  nop   
/* 08DD30 7F059200 468094A0 */  cvt.s.w $f18, $f18
/* 08DD34 7F059204 46009483 */  div.s $f18, $f18, $f0
/* 08DD38 7F059208 E472FFF4 */  swc1  $f18, -0xc($v1)
/* 08DD3C 7F05920C 8CD8FFF8 */  lw    $t8, -8($a2)
/* 08DD40 7F059210 44989000 */  mtc1  $t8, $f18
/* 08DD44 7F059214 00000000 */  nop   
/* 08DD48 7F059218 468094A0 */  cvt.s.w $f18, $f18
/* 08DD4C 7F05921C 46009483 */  div.s $f18, $f18, $f0
/* 08DD50 7F059220 E472FFF8 */  swc1  $f18, -8($v1)
/* 08DD54 7F059224 8CD9FFFC */  lw    $t9, -4($a2)
/* 08DD58 7F059228 44999000 */  mtc1  $t9, $f18
/* 08DD5C 7F05922C 00000000 */  nop   
/* 08DD60 7F059230 468094A0 */  cvt.s.w $f18, $f18
/* 08DD64 7F059234 46009483 */  div.s $f18, $f18, $f0
/* 08DD68 7F059238 E472FFFC */  swc1  $f18, -4($v1)
/* 08DD6C 7F05923C 03E00008 */  jr    $ra
/* 08DD70 7F059240 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F059244(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F059244
/* 08DD74 7F059244 00001025 */  move  $v0, $zero
/* 08DD78 7F059248 00A04025 */  move  $t0, $a1
/* 08DD7C 7F05924C 240D0008 */  li    $t5, 8
/* 08DD80 7F059250 3C0CFFFF */  lui   $t4, 0xffff
.L7F059254:
/* 08DD84 7F059254 000278C0 */  sll   $t7, $v0, 3
/* 08DD88 7F059258 008F3821 */  addu  $a3, $a0, $t7
/* 08DD8C 7F05925C 8CE30000 */  lw    $v1, ($a3)
/* 08DD90 7F059260 8CE60004 */  lw    $a2, 4($a3)
/* 08DD94 7F059264 25080010 */  addiu $t0, $t0, 0x10
/* 08DD98 7F059268 006CC024 */  and   $t8, $v1, $t4
/* 08DD9C 7F05926C 0006CC02 */  srl   $t9, $a2, 0x10
/* 08DDA0 7F059270 03197025 */  or    $t6, $t8, $t9
/* 08DDA4 7F059274 00037C00 */  sll   $t7, $v1, 0x10
/* 08DDA8 7F059278 30D8FFFF */  andi  $t8, $a2, 0xffff
/* 08DDAC 7F05927C 01F8C825 */  or    $t9, $t7, $t8
/* 08DDB0 7F059280 244F0001 */  addiu $t7, $v0, 1
/* 08DDB4 7F059284 000FC0C0 */  sll   $t8, $t7, 3
/* 08DDB8 7F059288 00984821 */  addu  $t1, $a0, $t8
/* 08DDBC 7F05928C AD0EFFF0 */  sw    $t6, -0x10($t0)
/* 08DDC0 7F059290 AD190010 */  sw    $t9, 0x10($t0)
/* 08DDC4 7F059294 8D260004 */  lw    $a2, 4($t1)
/* 08DDC8 7F059298 8D230000 */  lw    $v1, ($t1)
/* 08DDCC 7F05929C 00067402 */  srl   $t6, $a2, 0x10
/* 08DDD0 7F0592A0 006CC824 */  and   $t9, $v1, $t4
/* 08DDD4 7F0592A4 032E7825 */  or    $t7, $t9, $t6
/* 08DDD8 7F0592A8 30D9FFFF */  andi  $t9, $a2, 0xffff
/* 08DDDC 7F0592AC 0003C400 */  sll   $t8, $v1, 0x10
/* 08DDE0 7F0592B0 03197025 */  or    $t6, $t8, $t9
/* 08DDE4 7F0592B4 24580002 */  addiu $t8, $v0, 2
/* 08DDE8 7F0592B8 0018C8C0 */  sll   $t9, $t8, 3
/* 08DDEC 7F0592BC 00995021 */  addu  $t2, $a0, $t9
/* 08DDF0 7F0592C0 AD0E0014 */  sw    $t6, 0x14($t0)
/* 08DDF4 7F0592C4 AD0FFFF4 */  sw    $t7, -0xc($t0)
/* 08DDF8 7F0592C8 8D460004 */  lw    $a2, 4($t2)
/* 08DDFC 7F0592CC 8D430000 */  lw    $v1, ($t2)
/* 08DE00 7F0592D0 00067C02 */  srl   $t7, $a2, 0x10
/* 08DE04 7F0592D4 006C7024 */  and   $t6, $v1, $t4
/* 08DE08 7F0592D8 01CFC025 */  or    $t8, $t6, $t7
/* 08DE0C 7F0592DC 30CEFFFF */  andi  $t6, $a2, 0xffff
/* 08DE10 7F0592E0 0003CC00 */  sll   $t9, $v1, 0x10
/* 08DE14 7F0592E4 032E7825 */  or    $t7, $t9, $t6
/* 08DE18 7F0592E8 24590003 */  addiu $t9, $v0, 3
/* 08DE1C 7F0592EC 001970C0 */  sll   $t6, $t9, 3
/* 08DE20 7F0592F0 008E5821 */  addu  $t3, $a0, $t6
/* 08DE24 7F0592F4 AD0F0018 */  sw    $t7, 0x18($t0)
/* 08DE28 7F0592F8 AD18FFF8 */  sw    $t8, -8($t0)
/* 08DE2C 7F0592FC 8D660004 */  lw    $a2, 4($t3)
/* 08DE30 7F059300 8D630000 */  lw    $v1, ($t3)
/* 08DE34 7F059304 24420004 */  addiu $v0, $v0, 4
/* 08DE38 7F059308 0006C402 */  srl   $t8, $a2, 0x10
/* 08DE3C 7F05930C 006C7824 */  and   $t7, $v1, $t4
/* 08DE40 7F059310 01F8C825 */  or    $t9, $t7, $t8
/* 08DE44 7F059314 30CFFFFF */  andi  $t7, $a2, 0xffff
/* 08DE48 7F059318 00037400 */  sll   $t6, $v1, 0x10
/* 08DE4C 7F05931C 01CFC025 */  or    $t8, $t6, $t7
/* 08DE50 7F059320 AD18001C */  sw    $t8, 0x1c($t0)
/* 08DE54 7F059324 144DFFCB */  bne   $v0, $t5, .L7F059254
/* 08DE58 7F059328 AD19FFFC */   sw    $t9, -4($t0)
/* 08DE5C 7F05932C 03E00008 */  jr    $ra
/* 08DE60 7F059330 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F059334(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F059334
/* 08DE64 7F059334 00001025 */  move  $v0, $zero
/* 08DE68 7F059338 00803825 */  move  $a3, $a0
/* 08DE6C 7F05933C 240D0008 */  li    $t5, 8
/* 08DE70 7F059340 3C0CFFFF */  lui   $t4, 0xffff
.L7F059344:
/* 08DE74 7F059344 8CE30000 */  lw    $v1, ($a3)
/* 08DE78 7F059348 8CE60020 */  lw    $a2, 0x20($a3)
/* 08DE7C 7F05934C 000278C0 */  sll   $t7, $v0, 3
/* 08DE80 7F059350 006CC024 */  and   $t8, $v1, $t4
/* 08DE84 7F059354 0006CC02 */  srl   $t9, $a2, 0x10
/* 08DE88 7F059358 03197025 */  or    $t6, $t8, $t9
/* 08DE8C 7F05935C 00AF4021 */  addu  $t0, $a1, $t7
/* 08DE90 7F059360 00037C00 */  sll   $t7, $v1, 0x10
/* 08DE94 7F059364 30D8FFFF */  andi  $t8, $a2, 0xffff
/* 08DE98 7F059368 01F8C825 */  or    $t9, $t7, $t8
/* 08DE9C 7F05936C AD0E0000 */  sw    $t6, ($t0)
/* 08DEA0 7F059370 AD190004 */  sw    $t9, 4($t0)
/* 08DEA4 7F059374 8CE60024 */  lw    $a2, 0x24($a3)
/* 08DEA8 7F059378 8CE30004 */  lw    $v1, 4($a3)
/* 08DEAC 7F05937C 244F0001 */  addiu $t7, $v0, 1
/* 08DEB0 7F059380 000FC0C0 */  sll   $t8, $t7, 3
/* 08DEB4 7F059384 00067402 */  srl   $t6, $a2, 0x10
/* 08DEB8 7F059388 006CC824 */  and   $t9, $v1, $t4
/* 08DEBC 7F05938C 032E7825 */  or    $t7, $t9, $t6
/* 08DEC0 7F059390 00B84821 */  addu  $t1, $a1, $t8
/* 08DEC4 7F059394 30D9FFFF */  andi  $t9, $a2, 0xffff
/* 08DEC8 7F059398 0003C400 */  sll   $t8, $v1, 0x10
/* 08DECC 7F05939C 03197025 */  or    $t6, $t8, $t9
/* 08DED0 7F0593A0 AD2E0004 */  sw    $t6, 4($t1)
/* 08DED4 7F0593A4 AD2F0000 */  sw    $t7, ($t1)
/* 08DED8 7F0593A8 8CE60028 */  lw    $a2, 0x28($a3)
/* 08DEDC 7F0593AC 8CE30008 */  lw    $v1, 8($a3)
/* 08DEE0 7F0593B0 24580002 */  addiu $t8, $v0, 2
/* 08DEE4 7F0593B4 0018C8C0 */  sll   $t9, $t8, 3
/* 08DEE8 7F0593B8 00067C02 */  srl   $t7, $a2, 0x10
/* 08DEEC 7F0593BC 006C7024 */  and   $t6, $v1, $t4
/* 08DEF0 7F0593C0 01CFC025 */  or    $t8, $t6, $t7
/* 08DEF4 7F0593C4 00B95021 */  addu  $t2, $a1, $t9
/* 08DEF8 7F0593C8 30CEFFFF */  andi  $t6, $a2, 0xffff
/* 08DEFC 7F0593CC 0003CC00 */  sll   $t9, $v1, 0x10
/* 08DF00 7F0593D0 032E7825 */  or    $t7, $t9, $t6
/* 08DF04 7F0593D4 AD4F0004 */  sw    $t7, 4($t2)
/* 08DF08 7F0593D8 AD580000 */  sw    $t8, ($t2)
/* 08DF0C 7F0593DC 8CE6002C */  lw    $a2, 0x2c($a3)
/* 08DF10 7F0593E0 8CE3000C */  lw    $v1, 0xc($a3)
/* 08DF14 7F0593E4 24590003 */  addiu $t9, $v0, 3
/* 08DF18 7F0593E8 001970C0 */  sll   $t6, $t9, 3
/* 08DF1C 7F0593EC 0006C402 */  srl   $t8, $a2, 0x10
/* 08DF20 7F0593F0 006C7824 */  and   $t7, $v1, $t4
/* 08DF24 7F0593F4 01F8C825 */  or    $t9, $t7, $t8
/* 08DF28 7F0593F8 00AE5821 */  addu  $t3, $a1, $t6
/* 08DF2C 7F0593FC 30CFFFFF */  andi  $t7, $a2, 0xffff
/* 08DF30 7F059400 00037400 */  sll   $t6, $v1, 0x10
/* 08DF34 7F059404 01CFC025 */  or    $t8, $t6, $t7
/* 08DF38 7F059408 24420004 */  addiu $v0, $v0, 4
/* 08DF3C 7F05940C AD780004 */  sw    $t8, 4($t3)
/* 08DF40 7F059410 AD790000 */  sw    $t9, ($t3)
/* 08DF44 7F059414 144DFFCB */  bne   $v0, $t5, .L7F059344
/* 08DF48 7F059418 24E70010 */   addiu $a3, $a3, 0x10
/* 08DF4C 7F05941C 03E00008 */  jr    $ra
/* 08DF50 7F059420 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F059424(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F059424
/* 08DF54 7F059424 27BDFFB8 */  addiu $sp, $sp, -0x48
/* 08DF58 7F059428 F7B40010 */  sdc1  $f20, 0x10($sp)
/* 08DF5C 7F05942C C7B40058 */  lwc1  $f20, 0x58($sp)
/* 08DF60 7F059430 F7B60018 */  sdc1  $f22, 0x18($sp)
/* 08DF64 7F059434 C7B6005C */  lwc1  $f22, 0x5c($sp)
/* 08DF68 7F059438 4614A102 */  mul.s $f4, $f20, $f20
/* 08DF6C 7F05943C F7B80020 */  sdc1  $f24, 0x20($sp)
/* 08DF70 7F059440 C7B80060 */  lwc1  $f24, 0x60($sp)
/* 08DF74 7F059444 4616B182 */  mul.s $f6, $f22, $f22
/* 08DF78 7F059448 AFBF0044 */  sw    $ra, 0x44($sp)
/* 08DF7C 7F05944C F7BE0038 */  sdc1  $f30, 0x38($sp)
/* 08DF80 7F059450 4618C282 */  mul.s $f10, $f24, $f24
/* 08DF84 7F059454 F7BC0030 */  sdc1  $f28, 0x30($sp)
/* 08DF88 7F059458 F7BA0028 */  sdc1  $f26, 0x28($sp)
/* 08DF8C 7F05945C AFA5004C */  sw    $a1, 0x4c($sp)
/* 08DF90 7F059460 AFA60050 */  sw    $a2, 0x50($sp)
/* 08DF94 7F059464 46062200 */  add.s $f8, $f4, $f6
/* 08DF98 7F059468 AFA70054 */  sw    $a3, 0x54($sp)
/* 08DF9C 7F05946C AFA40048 */  sw    $a0, 0x48($sp)
/* 08DFA0 7F059470 0C007DF8 */  jal   sqrtf
/* 08DFA4 7F059474 460A4300 */   add.s $f12, $f8, $f10
/* 08DFA8 7F059478 3C01BF80 */  li    $at, 0xBF800000 # -1.000000
/* 08DFAC 7F05947C 44812000 */  mtc1  $at, $f4
/* 08DFB0 7F059480 C7A60068 */  lwc1  $f6, 0x68($sp)
/* 08DFB4 7F059484 C7AA006C */  lwc1  $f10, 0x6c($sp)
/* 08DFB8 7F059488 46002083 */  div.s $f2, $f4, $f0
/* 08DFBC 7F05948C 4602A502 */  mul.s $f20, $f20, $f2
/* 08DFC0 7F059490 00000000 */  nop   
/* 08DFC4 7F059494 4602B582 */  mul.s $f22, $f22, $f2
/* 08DFC8 7F059498 00000000 */  nop   
/* 08DFCC 7F05949C 4602C602 */  mul.s $f24, $f24, $f2
/* 08DFD0 7F0594A0 00000000 */  nop   
/* 08DFD4 7F0594A4 46183202 */  mul.s $f8, $f6, $f24
/* 08DFD8 7F0594A8 00000000 */  nop   
/* 08DFDC 7F0594AC 46165102 */  mul.s $f4, $f10, $f22
/* 08DFE0 7F0594B0 46044681 */  sub.s $f26, $f8, $f4
/* 08DFE4 7F0594B4 46145202 */  mul.s $f8, $f10, $f20
/* 08DFE8 7F0594B8 C7A40064 */  lwc1  $f4, 0x64($sp)
/* 08DFEC 7F0594BC 46182282 */  mul.s $f10, $f4, $f24
/* 08DFF0 7F0594C0 460A4701 */  sub.s $f28, $f8, $f10
/* 08DFF4 7F0594C4 46162202 */  mul.s $f8, $f4, $f22
/* 08DFF8 7F0594C8 00000000 */  nop   
/* 08DFFC 7F0594CC 46143282 */  mul.s $f10, $f6, $f20
/* 08E000 7F0594D0 460A4781 */  sub.s $f30, $f8, $f10
/* 08E004 7F0594D4 461AD102 */  mul.s $f4, $f26, $f26
/* 08E008 7F0594D8 00000000 */  nop   
/* 08E00C 7F0594DC 461CE182 */  mul.s $f6, $f28, $f28
/* 08E010 7F0594E0 46062200 */  add.s $f8, $f4, $f6
/* 08E014 7F0594E4 461EF282 */  mul.s $f10, $f30, $f30
/* 08E018 7F0594E8 0C007DF8 */  jal   sqrtf
/* 08E01C 7F0594EC 460A4300 */   add.s $f12, $f8, $f10
/* 08E020 7F0594F0 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 08E024 7F0594F4 44812000 */  mtc1  $at, $f4
/* 08E028 7F0594F8 00000000 */  nop   
/* 08E02C 7F0594FC 46002083 */  div.s $f2, $f4, $f0
/* 08E030 7F059500 4602D682 */  mul.s $f26, $f26, $f2
/* 08E034 7F059504 00000000 */  nop   
/* 08E038 7F059508 4602E702 */  mul.s $f28, $f28, $f2
/* 08E03C 7F05950C 00000000 */  nop   
/* 08E040 7F059510 4602F782 */  mul.s $f30, $f30, $f2
/* 08E044 7F059514 00000000 */  nop   
/* 08E048 7F059518 461EB182 */  mul.s $f6, $f22, $f30
/* 08E04C 7F05951C 00000000 */  nop   
/* 08E050 7F059520 461CC202 */  mul.s $f8, $f24, $f28
/* 08E054 7F059524 00000000 */  nop   
/* 08E058 7F059528 461AC282 */  mul.s $f10, $f24, $f26
/* 08E05C 7F05952C 00000000 */  nop   
/* 08E060 7F059530 461EA102 */  mul.s $f4, $f20, $f30
/* 08E064 7F059534 46083381 */  sub.s $f14, $f6, $f8
/* 08E068 7F059538 461CA182 */  mul.s $f6, $f20, $f28
/* 08E06C 7F05953C 00000000 */  nop   
/* 08E070 7F059540 461AB202 */  mul.s $f8, $f22, $f26
/* 08E074 7F059544 E7AE0064 */  swc1  $f14, 0x64($sp)
/* 08E078 7F059548 46045401 */  sub.s $f16, $f10, $f4
/* 08E07C 7F05954C 460E7282 */  mul.s $f10, $f14, $f14
/* 08E080 7F059550 00000000 */  nop   
/* 08E084 7F059554 46108102 */  mul.s $f4, $f16, $f16
/* 08E088 7F059558 E7B00068 */  swc1  $f16, 0x68($sp)
/* 08E08C 7F05955C 46083481 */  sub.s $f18, $f6, $f8
/* 08E090 7F059560 46129202 */  mul.s $f8, $f18, $f18
/* 08E094 7F059564 46045180 */  add.s $f6, $f10, $f4
/* 08E098 7F059568 E7B2006C */  swc1  $f18, 0x6c($sp)
/* 08E09C 7F05956C 0C007DF8 */  jal   sqrtf
/* 08E0A0 7F059570 46083300 */   add.s $f12, $f6, $f8
/* 08E0A4 7F059574 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 08E0A8 7F059578 44815000 */  mtc1  $at, $f10
/* 08E0AC 7F05957C C7AE0064 */  lwc1  $f14, 0x64($sp)
/* 08E0B0 7F059580 C7AC0068 */  lwc1  $f12, 0x68($sp)
/* 08E0B4 7F059584 46005083 */  div.s $f2, $f10, $f0
/* 08E0B8 7F059588 C7A4006C */  lwc1  $f4, 0x6c($sp)
/* 08E0BC 7F05958C 8FA40048 */  lw    $a0, 0x48($sp)
/* 08E0C0 7F059590 46027382 */  mul.s $f14, $f14, $f2
/* 08E0C4 7F059594 00000000 */  nop   
/* 08E0C8 7F059598 46026302 */  mul.s $f12, $f12, $f2
/* 08E0CC 7F05959C 00000000 */  nop   
/* 08E0D0 7F0595A0 46022182 */  mul.s $f6, $f4, $f2
/* 08E0D4 7F0595A4 E7A6006C */  swc1  $f6, 0x6c($sp)
/* 08E0D8 7F0595A8 E49A0000 */  swc1  $f26, ($a0)
/* 08E0DC 7F0595AC E49C0010 */  swc1  $f28, 0x10($a0)
/* 08E0E0 7F0595B0 E49E0020 */  swc1  $f30, 0x20($a0)
/* 08E0E4 7F0595B4 C7A8004C */  lwc1  $f8, 0x4c($sp)
/* 08E0E8 7F0595B8 C7A40050 */  lwc1  $f4, 0x50($sp)
/* 08E0EC 7F0595BC 461A4282 */  mul.s $f10, $f8, $f26
/* 08E0F0 7F0595C0 00000000 */  nop   
/* 08E0F4 7F0595C4 461C2182 */  mul.s $f6, $f4, $f28
/* 08E0F8 7F0595C8 C7A40054 */  lwc1  $f4, 0x54($sp)
/* 08E0FC 7F0595CC E48E0004 */  swc1  $f14, 4($a0)
/* 08E100 7F0595D0 E48C0014 */  swc1  $f12, 0x14($a0)
/* 08E104 7F0595D4 46065200 */  add.s $f8, $f10, $f6
/* 08E108 7F0595D8 461E2282 */  mul.s $f10, $f4, $f30
/* 08E10C 7F0595DC 460A4180 */  add.s $f6, $f8, $f10
/* 08E110 7F0595E0 46003107 */  neg.s $f4, $f6
/* 08E114 7F0595E4 E4840030 */  swc1  $f4, 0x30($a0)
/* 08E118 7F0595E8 E7AE0064 */  swc1  $f14, 0x64($sp)
/* 08E11C 7F0595EC C7AE006C */  lwc1  $f14, 0x6c($sp)
/* 08E120 7F0595F0 E7AC0068 */  swc1  $f12, 0x68($sp)
/* 08E124 7F0595F4 C7AC004C */  lwc1  $f12, 0x4c($sp)
/* 08E128 7F0595F8 C7A20050 */  lwc1  $f2, 0x50($sp)
/* 08E12C 7F0595FC C7A00054 */  lwc1  $f0, 0x54($sp)
/* 08E130 7F059600 E48E0024 */  swc1  $f14, 0x24($a0)
/* 08E134 7F059604 C7A80064 */  lwc1  $f8, 0x64($sp)
/* 08E138 7F059608 C7A60068 */  lwc1  $f6, 0x68($sp)
/* 08E13C 7F05960C E4940008 */  swc1  $f20, 8($a0)
/* 08E140 7F059610 46086282 */  mul.s $f10, $f12, $f8
/* 08E144 7F059614 E4960018 */  swc1  $f22, 0x18($a0)
/* 08E148 7F059618 E4980028 */  swc1  $f24, 0x28($a0)
/* 08E14C 7F05961C 46061102 */  mul.s $f4, $f2, $f6
/* 08E150 7F059620 46045200 */  add.s $f8, $f10, $f4
/* 08E154 7F059624 460E0182 */  mul.s $f6, $f0, $f14
/* 08E158 7F059628 46064280 */  add.s $f10, $f8, $f6
/* 08E15C 7F05962C 46146202 */  mul.s $f8, $f12, $f20
/* 08E160 7F059630 00000000 */  nop   
/* 08E164 7F059634 46161182 */  mul.s $f6, $f2, $f22
/* 08E168 7F059638 46005107 */  neg.s $f4, $f10
/* 08E16C 7F05963C E4840034 */  swc1  $f4, 0x34($a0)
/* 08E170 7F059640 46180102 */  mul.s $f4, $f0, $f24
/* 08E174 7F059644 44800000 */  mtc1  $zero, $f0
/* 08E178 7F059648 00000000 */  nop   
/* 08E17C 7F05964C E480000C */  swc1  $f0, 0xc($a0)
/* 08E180 7F059650 46064280 */  add.s $f10, $f8, $f6
/* 08E184 7F059654 E480001C */  swc1  $f0, 0x1c($a0)
/* 08E188 7F059658 E480002C */  swc1  $f0, 0x2c($a0)
/* 08E18C 7F05965C 46045200 */  add.s $f8, $f10, $f4
/* 08E190 7F059660 44815000 */  mtc1  $at, $f10
/* 08E194 7F059664 46004187 */  neg.s $f6, $f8
/* 08E198 7F059668 E48A003C */  swc1  $f10, 0x3c($a0)
/* 08E19C 7F05966C E4860038 */  swc1  $f6, 0x38($a0)
/* 08E1A0 7F059670 8FBF0044 */  lw    $ra, 0x44($sp)
/* 08E1A4 7F059674 D7BE0038 */  ldc1  $f30, 0x38($sp)
/* 08E1A8 7F059678 D7BC0030 */  ldc1  $f28, 0x30($sp)
/* 08E1AC 7F05967C D7BA0028 */  ldc1  $f26, 0x28($sp)
/* 08E1B0 7F059680 D7B80020 */  ldc1  $f24, 0x20($sp)
/* 08E1B4 7F059684 D7B60018 */  ldc1  $f22, 0x18($sp)
/* 08E1B8 7F059688 D7B40010 */  ldc1  $f20, 0x10($sp)
/* 08E1BC 7F05968C 03E00008 */  jr    $ra
/* 08E1C0 7F059690 27BD0048 */   addiu $sp, $sp, 0x48
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F059694(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F059694
/* 08E1C4 7F059694 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 08E1C8 7F059698 44856000 */  mtc1  $a1, $f12
/* 08E1CC 7F05969C 44867000 */  mtc1  $a2, $f14
/* 08E1D0 7F0596A0 C7A60040 */  lwc1  $f6, 0x40($sp)
/* 08E1D4 7F0596A4 C7AA0044 */  lwc1  $f10, 0x44($sp)
/* 08E1D8 7F0596A8 AFA7003C */  sw    $a3, 0x3c($sp)
/* 08E1DC 7F0596AC 460C3201 */  sub.s $f8, $f6, $f12
/* 08E1E0 7F0596B0 C7A4003C */  lwc1  $f4, 0x3c($sp)
/* 08E1E4 7F0596B4 C7B20048 */  lwc1  $f18, 0x48($sp)
/* 08E1E8 7F0596B8 460E5401 */  sub.s $f16, $f10, $f14
/* 08E1EC 7F0596BC E7A80010 */  swc1  $f8, 0x10($sp)
/* 08E1F0 7F0596C0 C7A8004C */  lwc1  $f8, 0x4c($sp)
/* 08E1F4 7F0596C4 46049181 */  sub.s $f6, $f18, $f4
/* 08E1F8 7F0596C8 E7B00014 */  swc1  $f16, 0x14($sp)
/* 08E1FC 7F0596CC C7B00054 */  lwc1  $f16, 0x54($sp)
/* 08E200 7F0596D0 C7AA0050 */  lwc1  $f10, 0x50($sp)
/* 08E204 7F0596D4 AFBF002C */  sw    $ra, 0x2c($sp)
/* 08E208 7F0596D8 44056000 */  mfc1  $a1, $f12
/* 08E20C 7F0596DC 44067000 */  mfc1  $a2, $f14
/* 08E210 7F0596E0 44072000 */  mfc1  $a3, $f4
/* 08E214 7F0596E4 E7A60018 */  swc1  $f6, 0x18($sp)
/* 08E218 7F0596E8 E7A8001C */  swc1  $f8, 0x1c($sp)
/* 08E21C 7F0596EC E7B00024 */  swc1  $f16, 0x24($sp)
/* 08E220 7F0596F0 0FC16509 */  jal   sub_GAME_7F059424
/* 08E224 7F0596F4 E7AA0020 */   swc1  $f10, 0x20($sp)
/* 08E228 7F0596F8 8FBF002C */  lw    $ra, 0x2c($sp)
/* 08E22C 7F0596FC 27BD0030 */  addiu $sp, $sp, 0x30
/* 08E230 7F059700 03E00008 */  jr    $ra
/* 08E234 7F059704 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F059708(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F059708
/* 08E238 7F059708 27BDFFB8 */  addiu $sp, $sp, -0x48
/* 08E23C 7F05970C F7B40010 */  sdc1  $f20, 0x10($sp)
/* 08E240 7F059710 C7B40058 */  lwc1  $f20, 0x58($sp)
/* 08E244 7F059714 F7B60018 */  sdc1  $f22, 0x18($sp)
/* 08E248 7F059718 C7B6005C */  lwc1  $f22, 0x5c($sp)
/* 08E24C 7F05971C 4614A102 */  mul.s $f4, $f20, $f20
/* 08E250 7F059720 F7B80020 */  sdc1  $f24, 0x20($sp)
/* 08E254 7F059724 C7B80060 */  lwc1  $f24, 0x60($sp)
/* 08E258 7F059728 4616B182 */  mul.s $f6, $f22, $f22
/* 08E25C 7F05972C AFBF0044 */  sw    $ra, 0x44($sp)
/* 08E260 7F059730 F7BE0038 */  sdc1  $f30, 0x38($sp)
/* 08E264 7F059734 4618C282 */  mul.s $f10, $f24, $f24
/* 08E268 7F059738 F7BC0030 */  sdc1  $f28, 0x30($sp)
/* 08E26C 7F05973C F7BA0028 */  sdc1  $f26, 0x28($sp)
/* 08E270 7F059740 AFA5004C */  sw    $a1, 0x4c($sp)
/* 08E274 7F059744 AFA60050 */  sw    $a2, 0x50($sp)
/* 08E278 7F059748 46062200 */  add.s $f8, $f4, $f6
/* 08E27C 7F05974C AFA70054 */  sw    $a3, 0x54($sp)
/* 08E280 7F059750 AFA40048 */  sw    $a0, 0x48($sp)
/* 08E284 7F059754 0C007DF8 */  jal   sqrtf
/* 08E288 7F059758 460A4300 */   add.s $f12, $f8, $f10
/* 08E28C 7F05975C 3C01BF80 */  li    $at, 0xBF800000 # -1.000000
/* 08E290 7F059760 44812000 */  mtc1  $at, $f4
/* 08E294 7F059764 C7A60068 */  lwc1  $f6, 0x68($sp)
/* 08E298 7F059768 C7AA006C */  lwc1  $f10, 0x6c($sp)
/* 08E29C 7F05976C 46002083 */  div.s $f2, $f4, $f0
/* 08E2A0 7F059770 4602A502 */  mul.s $f20, $f20, $f2
/* 08E2A4 7F059774 00000000 */  nop   
/* 08E2A8 7F059778 4602B582 */  mul.s $f22, $f22, $f2
/* 08E2AC 7F05977C 00000000 */  nop   
/* 08E2B0 7F059780 4602C602 */  mul.s $f24, $f24, $f2
/* 08E2B4 7F059784 00000000 */  nop   
/* 08E2B8 7F059788 46183202 */  mul.s $f8, $f6, $f24
/* 08E2BC 7F05978C 00000000 */  nop   
/* 08E2C0 7F059790 46165102 */  mul.s $f4, $f10, $f22
/* 08E2C4 7F059794 46044681 */  sub.s $f26, $f8, $f4
/* 08E2C8 7F059798 46145202 */  mul.s $f8, $f10, $f20
/* 08E2CC 7F05979C C7A40064 */  lwc1  $f4, 0x64($sp)
/* 08E2D0 7F0597A0 46182282 */  mul.s $f10, $f4, $f24
/* 08E2D4 7F0597A4 460A4701 */  sub.s $f28, $f8, $f10
/* 08E2D8 7F0597A8 46162202 */  mul.s $f8, $f4, $f22
/* 08E2DC 7F0597AC 00000000 */  nop   
/* 08E2E0 7F0597B0 46143282 */  mul.s $f10, $f6, $f20
/* 08E2E4 7F0597B4 460A4781 */  sub.s $f30, $f8, $f10
/* 08E2E8 7F0597B8 461AD102 */  mul.s $f4, $f26, $f26
/* 08E2EC 7F0597BC 00000000 */  nop   
/* 08E2F0 7F0597C0 461CE182 */  mul.s $f6, $f28, $f28
/* 08E2F4 7F0597C4 46062200 */  add.s $f8, $f4, $f6
/* 08E2F8 7F0597C8 461EF282 */  mul.s $f10, $f30, $f30
/* 08E2FC 7F0597CC 0C007DF8 */  jal   sqrtf
/* 08E300 7F0597D0 460A4300 */   add.s $f12, $f8, $f10
/* 08E304 7F0597D4 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 08E308 7F0597D8 44812000 */  mtc1  $at, $f4
/* 08E30C 7F0597DC 00000000 */  nop   
/* 08E310 7F0597E0 46002083 */  div.s $f2, $f4, $f0
/* 08E314 7F0597E4 4602D682 */  mul.s $f26, $f26, $f2
/* 08E318 7F0597E8 00000000 */  nop   
/* 08E31C 7F0597EC 4602E702 */  mul.s $f28, $f28, $f2
/* 08E320 7F0597F0 00000000 */  nop   
/* 08E324 7F0597F4 4602F782 */  mul.s $f30, $f30, $f2
/* 08E328 7F0597F8 00000000 */  nop   
/* 08E32C 7F0597FC 461EB182 */  mul.s $f6, $f22, $f30
/* 08E330 7F059800 00000000 */  nop   
/* 08E334 7F059804 461CC202 */  mul.s $f8, $f24, $f28
/* 08E338 7F059808 00000000 */  nop   
/* 08E33C 7F05980C 461AC282 */  mul.s $f10, $f24, $f26
/* 08E340 7F059810 00000000 */  nop   
/* 08E344 7F059814 461EA102 */  mul.s $f4, $f20, $f30
/* 08E348 7F059818 46083381 */  sub.s $f14, $f6, $f8
/* 08E34C 7F05981C 461CA182 */  mul.s $f6, $f20, $f28
/* 08E350 7F059820 00000000 */  nop   
/* 08E354 7F059824 461AB202 */  mul.s $f8, $f22, $f26
/* 08E358 7F059828 E7AE0064 */  swc1  $f14, 0x64($sp)
/* 08E35C 7F05982C 46045401 */  sub.s $f16, $f10, $f4
/* 08E360 7F059830 460E7282 */  mul.s $f10, $f14, $f14
/* 08E364 7F059834 00000000 */  nop   
/* 08E368 7F059838 46108102 */  mul.s $f4, $f16, $f16
/* 08E36C 7F05983C E7B00068 */  swc1  $f16, 0x68($sp)
/* 08E370 7F059840 46083481 */  sub.s $f18, $f6, $f8
/* 08E374 7F059844 46129202 */  mul.s $f8, $f18, $f18
/* 08E378 7F059848 46045180 */  add.s $f6, $f10, $f4
/* 08E37C 7F05984C E7B2006C */  swc1  $f18, 0x6c($sp)
/* 08E380 7F059850 0C007DF8 */  jal   sqrtf
/* 08E384 7F059854 46083300 */   add.s $f12, $f6, $f8
/* 08E388 7F059858 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 08E38C 7F05985C 44815000 */  mtc1  $at, $f10
/* 08E390 7F059860 C7AE0064 */  lwc1  $f14, 0x64($sp)
/* 08E394 7F059864 C7AC0068 */  lwc1  $f12, 0x68($sp)
/* 08E398 7F059868 46005083 */  div.s $f2, $f10, $f0
/* 08E39C 7F05986C C7A4006C */  lwc1  $f4, 0x6c($sp)
/* 08E3A0 7F059870 8FA40048 */  lw    $a0, 0x48($sp)
/* 08E3A4 7F059874 44800000 */  mtc1  $zero, $f0
/* 08E3A8 7F059878 46027382 */  mul.s $f14, $f14, $f2
/* 08E3AC 7F05987C 00000000 */  nop   
/* 08E3B0 7F059880 46026302 */  mul.s $f12, $f12, $f2
/* 08E3B4 7F059884 00000000 */  nop   
/* 08E3B8 7F059888 46022182 */  mul.s $f6, $f4, $f2
/* 08E3BC 7F05988C E7A6006C */  swc1  $f6, 0x6c($sp)
/* 08E3C0 7F059890 E49A0000 */  swc1  $f26, ($a0)
/* 08E3C4 7F059894 E48E0010 */  swc1  $f14, 0x10($a0)
/* 08E3C8 7F059898 E4940020 */  swc1  $f20, 0x20($a0)
/* 08E3CC 7F05989C C7A8004C */  lwc1  $f8, 0x4c($sp)
/* 08E3D0 7F0598A0 E49C0004 */  swc1  $f28, 4($a0)
/* 08E3D4 7F0598A4 E48C0014 */  swc1  $f12, 0x14($a0)
/* 08E3D8 7F0598A8 E4960024 */  swc1  $f22, 0x24($a0)
/* 08E3DC 7F0598AC E4880030 */  swc1  $f8, 0x30($a0)
/* 08E3E0 7F0598B0 C7AA0050 */  lwc1  $f10, 0x50($sp)
/* 08E3E4 7F0598B4 E49E0008 */  swc1  $f30, 8($a0)
/* 08E3E8 7F0598B8 44814000 */  mtc1  $at, $f8
/* 08E3EC 7F0598BC E48A0034 */  swc1  $f10, 0x34($a0)
/* 08E3F0 7F0598C0 C7A4006C */  lwc1  $f4, 0x6c($sp)
/* 08E3F4 7F0598C4 E4980028 */  swc1  $f24, 0x28($a0)
/* 08E3F8 7F0598C8 E4840018 */  swc1  $f4, 0x18($a0)
/* 08E3FC 7F0598CC C7A60054 */  lwc1  $f6, 0x54($sp)
/* 08E400 7F0598D0 E480000C */  swc1  $f0, 0xc($a0)
/* 08E404 7F0598D4 E480001C */  swc1  $f0, 0x1c($a0)
/* 08E408 7F0598D8 E480002C */  swc1  $f0, 0x2c($a0)
/* 08E40C 7F0598DC E488003C */  swc1  $f8, 0x3c($a0)
/* 08E410 7F0598E0 E4860038 */  swc1  $f6, 0x38($a0)
/* 08E414 7F0598E4 8FBF0044 */  lw    $ra, 0x44($sp)
/* 08E418 7F0598E8 D7BE0038 */  ldc1  $f30, 0x38($sp)
/* 08E41C 7F0598EC D7BC0030 */  ldc1  $f28, 0x30($sp)
/* 08E420 7F0598F0 D7BA0028 */  ldc1  $f26, 0x28($sp)
/* 08E424 7F0598F4 D7B80020 */  ldc1  $f24, 0x20($sp)
/* 08E428 7F0598F8 D7B60018 */  ldc1  $f22, 0x18($sp)
/* 08E42C 7F0598FC D7B40010 */  ldc1  $f20, 0x10($sp)
/* 08E430 7F059900 03E00008 */  jr    $ra
/* 08E434 7F059904 27BD0048 */   addiu $sp, $sp, 0x48
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F059908(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F059908
/* 08E438 7F059908 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 08E43C 7F05990C 44856000 */  mtc1  $a1, $f12
/* 08E440 7F059910 44867000 */  mtc1  $a2, $f14
/* 08E444 7F059914 C7A60040 */  lwc1  $f6, 0x40($sp)
/* 08E448 7F059918 C7AA0044 */  lwc1  $f10, 0x44($sp)
/* 08E44C 7F05991C AFA7003C */  sw    $a3, 0x3c($sp)
/* 08E450 7F059920 460C3201 */  sub.s $f8, $f6, $f12
/* 08E454 7F059924 C7A4003C */  lwc1  $f4, 0x3c($sp)
/* 08E458 7F059928 C7B20048 */  lwc1  $f18, 0x48($sp)
/* 08E45C 7F05992C 460E5401 */  sub.s $f16, $f10, $f14
/* 08E460 7F059930 E7A80010 */  swc1  $f8, 0x10($sp)
/* 08E464 7F059934 C7A8004C */  lwc1  $f8, 0x4c($sp)
/* 08E468 7F059938 46049181 */  sub.s $f6, $f18, $f4
/* 08E46C 7F05993C E7B00014 */  swc1  $f16, 0x14($sp)
/* 08E470 7F059940 C7B00054 */  lwc1  $f16, 0x54($sp)
/* 08E474 7F059944 C7AA0050 */  lwc1  $f10, 0x50($sp)
/* 08E478 7F059948 AFBF002C */  sw    $ra, 0x2c($sp)
/* 08E47C 7F05994C 44056000 */  mfc1  $a1, $f12
/* 08E480 7F059950 44067000 */  mfc1  $a2, $f14
/* 08E484 7F059954 44072000 */  mfc1  $a3, $f4
/* 08E488 7F059958 E7A60018 */  swc1  $f6, 0x18($sp)
/* 08E48C 7F05995C E7A8001C */  swc1  $f8, 0x1c($sp)
/* 08E490 7F059960 E7B00024 */  swc1  $f16, 0x24($sp)
/* 08E494 7F059964 0FC165C2 */  jal   sub_GAME_7F059708
/* 08E498 7F059968 E7AA0020 */   swc1  $f10, 0x20($sp)
/* 08E49C 7F05996C 8FBF002C */  lw    $ra, 0x2c($sp)
/* 08E4A0 7F059970 27BD0030 */  addiu $sp, $sp, 0x30
/* 08E4A4 7F059974 03E00008 */  jr    $ra
/* 08E4A8 7F059978 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F05997C(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F05997C
/* 08E4AC 7F05997C 460E6000 */  add.s $f0, $f12, $f14
/* 08E4B0 7F059980 3C014000 */  li    $at, 0x40000000 # 2.000000
/* 08E4B4 7F059984 44812000 */  mtc1  $at, $f4
/* 08E4B8 7F059988 3C014800 */  li    $at, 0x48000000 # 131072.000000
/* 08E4BC 7F05998C 4604003E */  c.le.s $f0, $f4
/* 08E4C0 7F059990 00000000 */  nop   
/* 08E4C4 7F059994 45020004 */  bc1fl .L7F0599A8
/* 08E4C8 7F059998 44813000 */   mtc1  $at, $f6
/* 08E4CC 7F05999C 03E00008 */  jr    $ra
/* 08E4D0 7F0599A0 3402FFFF */   li    $v0, 65535

/* 08E4D4 7F0599A4 44813000 */  mtc1  $at, $f6
.L7F0599A8:
/* 08E4D8 7F0599A8 24020001 */  li    $v0, 1
/* 08E4DC 7F0599AC 3C014F00 */  li    $at, 0x4F000000 # 2147483648.000000
/* 08E4E0 7F0599B0 46003203 */  div.s $f8, $f6, $f0
/* 08E4E4 7F0599B4 444EF800 */  cfc1  $t6, $31
/* 08E4E8 7F0599B8 44C2F800 */  ctc1  $v0, $31
/* 08E4EC 7F0599BC 00000000 */  nop   
/* 08E4F0 7F0599C0 460042A4 */  cvt.w.s $f10, $f8
/* 08E4F4 7F0599C4 4442F800 */  cfc1  $v0, $31
/* 08E4F8 7F0599C8 00000000 */  nop   
/* 08E4FC 7F0599CC 30420078 */  andi  $v0, $v0, 0x78
/* 08E500 7F0599D0 50400013 */  beql  $v0, $zero, .L7F059A20
/* 08E504 7F0599D4 44025000 */   mfc1  $v0, $f10
/* 08E508 7F0599D8 44815000 */  mtc1  $at, $f10
/* 08E50C 7F0599DC 24020001 */  li    $v0, 1
/* 08E510 7F0599E0 460A4281 */  sub.s $f10, $f8, $f10
/* 08E514 7F0599E4 44C2F800 */  ctc1  $v0, $31
/* 08E518 7F0599E8 00000000 */  nop   
/* 08E51C 7F0599EC 460052A4 */  cvt.w.s $f10, $f10
/* 08E520 7F0599F0 4442F800 */  cfc1  $v0, $31
/* 08E524 7F0599F4 00000000 */  nop   
/* 08E528 7F0599F8 30420078 */  andi  $v0, $v0, 0x78
/* 08E52C 7F0599FC 14400005 */  bnez  $v0, .L7F059A14
/* 08E530 7F059A00 00000000 */   nop   
/* 08E534 7F059A04 44025000 */  mfc1  $v0, $f10
/* 08E538 7F059A08 3C018000 */  lui   $at, 0x8000
/* 08E53C 7F059A0C 10000007 */  b     .L7F059A2C
/* 08E540 7F059A10 00411025 */   or    $v0, $v0, $at
.L7F059A14:
/* 08E544 7F059A14 10000005 */  b     .L7F059A2C
/* 08E548 7F059A18 2402FFFF */   li    $v0, -1
/* 08E54C 7F059A1C 44025000 */  mfc1  $v0, $f10
.L7F059A20:
/* 08E550 7F059A20 00000000 */  nop   
/* 08E554 7F059A24 0440FFFB */  bltz  $v0, .L7F059A14
/* 08E558 7F059A28 00000000 */   nop   
.L7F059A2C:
/* 08E55C 7F059A2C 44CEF800 */  ctc1  $t6, $31
/* 08E560 7F059A30 304FFFFF */  andi  $t7, $v0, 0xffff
/* 08E564 7F059A34 1DE00002 */  bgtz  $t7, .L7F059A40
/* 08E568 7F059A38 3043FFFF */   andi  $v1, $v0, 0xffff
/* 08E56C 7F059A3C 24030001 */  li    $v1, 1
.L7F059A40:
/* 08E570 7F059A40 03E00008 */  jr    $ra
/* 08E574 7F059A44 00601025 */   move  $v0, $v1
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F059A48(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F059A48
/* 08E578 7F059A48 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 08E57C 7F059A4C 44867000 */  mtc1  $a2, $f14
/* 08E580 7F059A50 44812000 */  mtc1  $at, $f4
/* 08E584 7F059A54 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 08E588 7F059A58 AFBF0014 */  sw    $ra, 0x14($sp)
/* 08E58C 7F059A5C 46047302 */  mul.s $f12, $f14, $f4
/* 08E590 7F059A60 AFA5002C */  sw    $a1, 0x2c($sp)
/* 08E594 7F059A64 AFA70034 */  sw    $a3, 0x34($sp)
/* 08E598 7F059A68 AFA40028 */  sw    $a0, 0x28($sp)
/* 08E59C 7F059A6C 0FC15FA8 */  jal   cosf
/* 08E5A0 7F059A70 E7AC001C */   swc1  $f12, 0x1c($sp)
/* 08E5A4 7F059A74 C7AC001C */  lwc1  $f12, 0x1c($sp)
/* 08E5A8 7F059A78 0FC15FAB */  jal   sinf
/* 08E5AC 7F059A7C E7A00020 */   swc1  $f0, 0x20($sp)
/* 08E5B0 7F059A80 C7A80020 */  lwc1  $f8, 0x20($sp)
/* 08E5B4 7F059A84 C7AA0034 */  lwc1  $f10, 0x34($sp)
/* 08E5B8 7F059A88 3C014780 */  li    $at, 0x47800000 # 65536.000000
/* 08E5BC 7F059A8C 46004303 */  div.s $f12, $f8, $f0
/* 08E5C0 7F059A90 C7AE0040 */  lwc1  $f14, 0x40($sp)
/* 08E5C4 7F059A94 44813000 */  mtc1  $at, $f6
/* 08E5C8 7F059A98 8FA40028 */  lw    $a0, 0x28($sp)
/* 08E5CC 7F059A9C 44801000 */  mtc1  $zero, $f2
/* 08E5D0 7F059AA0 46067382 */  mul.s $f14, $f14, $f6
/* 08E5D4 7F059AA4 E4820010 */  swc1  $f2, 0x10($a0)
/* 08E5D8 7F059AA8 E4820020 */  swc1  $f2, 0x20($a0)
/* 08E5DC 7F059AAC E4820030 */  swc1  $f2, 0x30($a0)
/* 08E5E0 7F059AB0 E4820004 */  swc1  $f2, 4($a0)
/* 08E5E4 7F059AB4 E4820024 */  swc1  $f2, 0x24($a0)
/* 08E5E8 7F059AB8 E4820034 */  swc1  $f2, 0x34($a0)
/* 08E5EC 7F059ABC E4820008 */  swc1  $f2, 8($a0)
/* 08E5F0 7F059AC0 E4820018 */  swc1  $f2, 0x18($a0)
/* 08E5F4 7F059AC4 460A6483 */  div.s $f18, $f12, $f10
/* 08E5F8 7F059AC8 460E9102 */  mul.s $f4, $f18, $f14
/* 08E5FC 7F059ACC 00000000 */  nop   
/* 08E600 7F059AD0 460E6182 */  mul.s $f6, $f12, $f14
/* 08E604 7F059AD4 E4840000 */  swc1  $f4, ($a0)
/* 08E608 7F059AD8 E4860014 */  swc1  $f6, 0x14($a0)
/* 08E60C 7F059ADC C7A80038 */  lwc1  $f8, 0x38($sp)
/* 08E610 7F059AE0 C7AA003C */  lwc1  $f10, 0x3c($sp)
/* 08E614 7F059AE4 460A4401 */  sub.s $f16, $f8, $f10
/* 08E618 7F059AE8 460A4480 */  add.s $f18, $f8, $f10
/* 08E61C 7F059AEC 46109103 */  div.s $f4, $f18, $f16
/* 08E620 7F059AF0 460E2182 */  mul.s $f6, $f4, $f14
/* 08E624 7F059AF4 E4860028 */  swc1  $f6, 0x28($a0)
/* 08E628 7F059AF8 C7A80038 */  lwc1  $f8, 0x38($sp)
/* 08E62C 7F059AFC C7B2003C */  lwc1  $f18, 0x3c($sp)
/* 08E630 7F059B00 E482000C */  swc1  $f2, 0xc($a0)
/* 08E634 7F059B04 46084280 */  add.s $f10, $f8, $f8
/* 08E638 7F059B08 E482001C */  swc1  $f2, 0x1c($a0)
/* 08E63C 7F059B0C E482003C */  swc1  $f2, 0x3c($a0)
/* 08E640 7F059B10 46125102 */  mul.s $f4, $f10, $f18
/* 08E644 7F059B14 46007287 */  neg.s $f10, $f14
/* 08E648 7F059B18 E48A002C */  swc1  $f10, 0x2c($a0)
/* 08E64C 7F059B1C 46102183 */  div.s $f6, $f4, $f16
/* 08E650 7F059B20 460E3202 */  mul.s $f8, $f6, $f14
/* 08E654 7F059B24 E4880038 */  swc1  $f8, 0x38($a0)
/* 08E658 7F059B28 8FAE002C */  lw    $t6, 0x2c($sp)
/* 08E65C 7F059B2C C7AC0038 */  lwc1  $f12, 0x38($sp)
/* 08E660 7F059B30 11C00005 */  beqz  $t6, .L7F059B48
/* 08E664 7F059B34 00000000 */   nop   
/* 08E668 7F059B38 0FC1665F */  jal   sub_GAME_7F05997C
/* 08E66C 7F059B3C C7AE003C */   lwc1  $f14, 0x3c($sp)
/* 08E670 7F059B40 8FAF002C */  lw    $t7, 0x2c($sp)
/* 08E674 7F059B44 A5E20000 */  sh    $v0, ($t7)
.L7F059B48:
/* 08E678 7F059B48 8FBF0014 */  lw    $ra, 0x14($sp)
/* 08E67C 7F059B4C 27BD0028 */  addiu $sp, $sp, 0x28
/* 08E680 7F059B50 03E00008 */  jr    $ra
/* 08E684 7F059B54 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F059B58(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F059B58
/* 08E688 7F059B58 27BDFFB8 */  addiu $sp, $sp, -0x48
/* 08E68C 7F059B5C AFB00020 */  sw    $s0, 0x20($sp)
/* 08E690 7F059B60 F7B40018 */  sdc1  $f20, 0x18($sp)
/* 08E694 7F059B64 4485A000 */  mtc1  $a1, $f20
/* 08E698 7F059B68 00808025 */  move  $s0, $a0
/* 08E69C 7F059B6C AFBF0024 */  sw    $ra, 0x24($sp)
/* 08E6A0 7F059B70 AFA60050 */  sw    $a2, 0x50($sp)
/* 08E6A4 7F059B74 AFA70054 */  sw    $a3, 0x54($sp)
/* 08E6A8 7F059B78 27A60058 */  addiu $a2, $sp, 0x58
/* 08E6AC 7F059B7C 27A40050 */  addiu $a0, $sp, 0x50
/* 08E6B0 7F059B80 0C007DD4 */  jal   guNormalize
/* 08E6B4 7F059B84 27A50054 */   addiu $a1, $sp, 0x54
/* 08E6B8 7F059B88 0FC15FAB */  jal   sinf
/* 08E6BC 7F059B8C 4600A306 */   mov.s $f12, $f20
/* 08E6C0 7F059B90 E7A00044 */  swc1  $f0, 0x44($sp)
/* 08E6C4 7F059B94 0FC15FA8 */  jal   cosf
/* 08E6C8 7F059B98 4600A306 */   mov.s $f12, $f20
/* 08E6CC 7F059B9C C7A20050 */  lwc1  $f2, 0x50($sp)
/* 08E6D0 7F059BA0 C7AE0058 */  lwc1  $f14, 0x58($sp)
/* 08E6D4 7F059BA4 E7A00040 */  swc1  $f0, 0x40($sp)
/* 08E6D8 7F059BA8 46021102 */  mul.s $f4, $f2, $f2
/* 08E6DC 7F059BAC 00000000 */  nop   
/* 08E6E0 7F059BB0 460E7182 */  mul.s $f6, $f14, $f14
/* 08E6E4 7F059BB4 0C007DF8 */  jal   sqrtf
/* 08E6E8 7F059BB8 46062300 */   add.s $f12, $f4, $f6
/* 08E6EC 7F059BBC 4480A000 */  mtc1  $zero, $f20
/* 08E6F0 7F059BC0 C7A80050 */  lwc1  $f8, 0x50($sp)
/* 08E6F4 7F059BC4 C7AA0040 */  lwc1  $f10, 0x40($sp)
/* 08E6F8 7F059BC8 46140032 */  c.eq.s $f0, $f20
/* 08E6FC 7F059BCC C7A40044 */  lwc1  $f4, 0x44($sp)
/* 08E700 7F059BD0 4501003E */  bc1t  .L7F059CCC
/* 08E704 7F059BD4 00000000 */   nop   
/* 08E708 7F059BD8 460A4302 */  mul.s $f12, $f8, $f10
/* 08E70C 7F059BDC 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 08E710 7F059BE0 C7A60058 */  lwc1  $f6, 0x58($sp)
/* 08E714 7F059BE4 46044382 */  mul.s $f14, $f8, $f4
/* 08E718 7F059BE8 44814000 */  mtc1  $at, $f8
/* 08E71C 7F059BEC 460A3402 */  mul.s $f16, $f6, $f10
/* 08E720 7F059BF0 00000000 */  nop   
/* 08E724 7F059BF4 46043482 */  mul.s $f18, $f6, $f4
/* 08E728 7F059BF8 C7A60054 */  lwc1  $f6, 0x54($sp)
/* 08E72C 7F059BFC E7AE0030 */  swc1  $f14, 0x30($sp)
/* 08E730 7F059C00 460E3102 */  mul.s $f4, $f6, $f14
/* 08E734 7F059C04 E7B0002C */  swc1  $f16, 0x2c($sp)
/* 08E738 7F059C08 46008287 */  neg.s $f10, $f16
/* 08E73C 7F059C0C 46004083 */  div.s $f2, $f8, $f0
/* 08E740 7F059C10 46045201 */  sub.s $f8, $f10, $f4
/* 08E744 7F059C14 46024182 */  mul.s $f6, $f8, $f2
/* 08E748 7F059C18 E7A20038 */  swc1  $f2, 0x38($sp)
/* 08E74C 7F059C1C E6060000 */  swc1  $f6, ($s0)
/* 08E750 7F059C20 C7AA0044 */  lwc1  $f10, 0x44($sp)
/* 08E754 7F059C24 46005102 */  mul.s $f4, $f10, $f0
/* 08E758 7F059C28 E6040010 */  swc1  $f4, 0x10($s0)
/* 08E75C 7F059C2C C7A80054 */  lwc1  $f8, 0x54($sp)
/* 08E760 7F059C30 E6140030 */  swc1  $f20, 0x30($s0)
/* 08E764 7F059C34 46124182 */  mul.s $f6, $f8, $f18
/* 08E768 7F059C38 46066281 */  sub.s $f10, $f12, $f6
/* 08E76C 7F059C3C 46025102 */  mul.s $f4, $f10, $f2
/* 08E770 7F059C40 E6040020 */  swc1  $f4, 0x20($s0)
/* 08E774 7F059C44 C7A80054 */  lwc1  $f8, 0x54($sp)
/* 08E778 7F059C48 460C4182 */  mul.s $f6, $f8, $f12
/* 08E77C 7F059C4C 46069281 */  sub.s $f10, $f18, $f6
/* 08E780 7F059C50 46025102 */  mul.s $f4, $f10, $f2
/* 08E784 7F059C54 E6040004 */  swc1  $f4, 4($s0)
/* 08E788 7F059C58 C7A80040 */  lwc1  $f8, 0x40($sp)
/* 08E78C 7F059C5C 46004182 */  mul.s $f6, $f8, $f0
/* 08E790 7F059C60 E6060014 */  swc1  $f6, 0x14($s0)
/* 08E794 7F059C64 C7AA0054 */  lwc1  $f10, 0x54($sp)
/* 08E798 7F059C68 C7A4002C */  lwc1  $f4, 0x2c($sp)
/* 08E79C 7F059C6C C7A60030 */  lwc1  $f6, 0x30($sp)
/* 08E7A0 7F059C70 46045202 */  mul.s $f8, $f10, $f4
/* 08E7A4 7F059C74 46003287 */  neg.s $f10, $f6
/* 08E7A8 7F059C78 C7A60038 */  lwc1  $f6, 0x38($sp)
/* 08E7AC 7F059C7C E6140034 */  swc1  $f20, 0x34($s0)
/* 08E7B0 7F059C80 46085101 */  sub.s $f4, $f10, $f8
/* 08E7B4 7F059C84 46062282 */  mul.s $f10, $f4, $f6
/* 08E7B8 7F059C88 E60A0024 */  swc1  $f10, 0x24($s0)
/* 08E7BC 7F059C8C C7A80050 */  lwc1  $f8, 0x50($sp)
/* 08E7C0 7F059C90 46004107 */  neg.s $f4, $f8
/* 08E7C4 7F059C94 E6040008 */  swc1  $f4, 8($s0)
/* 08E7C8 7F059C98 C7A60054 */  lwc1  $f6, 0x54($sp)
/* 08E7CC 7F059C9C 46003287 */  neg.s $f10, $f6
/* 08E7D0 7F059CA0 44813000 */  mtc1  $at, $f6
/* 08E7D4 7F059CA4 E60A0018 */  swc1  $f10, 0x18($s0)
/* 08E7D8 7F059CA8 C7A80058 */  lwc1  $f8, 0x58($sp)
/* 08E7DC 7F059CAC E6140038 */  swc1  $f20, 0x38($s0)
/* 08E7E0 7F059CB0 E614000C */  swc1  $f20, 0xc($s0)
/* 08E7E4 7F059CB4 46004107 */  neg.s $f4, $f8
/* 08E7E8 7F059CB8 E614001C */  swc1  $f20, 0x1c($s0)
/* 08E7EC 7F059CBC E6040028 */  swc1  $f4, 0x28($s0)
/* 08E7F0 7F059CC0 E614002C */  swc1  $f20, 0x2c($s0)
/* 08E7F4 7F059CC4 10000003 */  b     .L7F059CD4
/* 08E7F8 7F059CC8 E606003C */   swc1  $f6, 0x3c($s0)
.L7F059CCC:
/* 08E7FC 7F059CCC 0FC15FF4 */  jal   init_0x40_bytes_data_at_address_last_word_1_0
/* 08E800 7F059CD0 02002025 */   move  $a0, $s0
.L7F059CD4:
/* 08E804 7F059CD4 8FBF0024 */  lw    $ra, 0x24($sp)
/* 08E808 7F059CD8 D7B40018 */  ldc1  $f20, 0x18($sp)
/* 08E80C 7F059CDC 8FB00020 */  lw    $s0, 0x20($sp)
/* 08E810 7F059CE0 03E00008 */  jr    $ra
/* 08E814 7F059CE4 27BD0048 */   addiu $sp, $sp, 0x48
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F059CE8(void) {

}
#else
GLOBAL_ASM(
.late_rodata
glabel D_800536F0
.word 0x42652ee0 /*57.295776*/
.text
glabel sub_GAME_7F059CE8
/* 08E818 7F059CE8 3C018005 */  lui   $at, %hi(D_800536F0) # $at, 0x8005
/* 08E81C 7F059CEC 44856000 */  mtc1  $a1, $f12
/* 08E820 7F059CF0 C42436F0 */  lwc1  $f4, %lo(D_800536F0)($at)
/* 08E824 7F059CF4 44867000 */  mtc1  $a2, $f14
/* 08E828 7F059CF8 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 08E82C 7F059CFC 46046302 */  mul.s $f12, $f12, $f4
/* 08E830 7F059D00 C7A60030 */  lwc1  $f6, 0x30($sp)
/* 08E834 7F059D04 AFBF001C */  sw    $ra, 0x1c($sp)
/* 08E838 7F059D08 44067000 */  mfc1  $a2, $f14
/* 08E83C 7F059D0C AFA7002C */  sw    $a3, 0x2c($sp)
/* 08E840 7F059D10 E7A60010 */  swc1  $f6, 0x10($sp)
/* 08E844 7F059D14 44056000 */  mfc1  $a1, $f12
/* 08E848 7F059D18 0C005A18 */  jal   guAlignF
/* 08E84C 7F059D1C 00000000 */   nop   
/* 08E850 7F059D20 8FBF001C */  lw    $ra, 0x1c($sp)
/* 08E854 7F059D24 27BD0020 */  addiu $sp, $sp, 0x20
/* 08E858 7F059D28 03E00008 */  jr    $ra
/* 08E85C 7F059D2C 00000000 */   nop   
)
#endif





void sub_GAME_7F059D30(u32 arg0) {
    return;
}






#ifdef NONMATCHING
void sub_GAME_7F059D38(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F059D38
/* 08E868 7F059D38 C4840000 */  lwc1  $f4, ($a0)
/* 08E86C 7F059D3C 44800000 */  mtc1  $zero, $f0
/* 08E870 7F059D40 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 08E874 7F059D44 E4A40000 */  swc1  $f4, ($a1)
/* 08E878 7F059D48 C4860010 */  lwc1  $f6, 0x10($a0)
/* 08E87C 7F059D4C E4A60004 */  swc1  $f6, 4($a1)
/* 08E880 7F059D50 C4880020 */  lwc1  $f8, 0x20($a0)
/* 08E884 7F059D54 E4A80008 */  swc1  $f8, 8($a1)
/* 08E888 7F059D58 C48A0004 */  lwc1  $f10, 4($a0)
/* 08E88C 7F059D5C E4AA0010 */  swc1  $f10, 0x10($a1)
/* 08E890 7F059D60 C4900014 */  lwc1  $f16, 0x14($a0)
/* 08E894 7F059D64 44815000 */  mtc1  $at, $f10
/* 08E898 7F059D68 E4B00014 */  swc1  $f16, 0x14($a1)
/* 08E89C 7F059D6C C4920024 */  lwc1  $f18, 0x24($a0)
/* 08E8A0 7F059D70 E4B20018 */  swc1  $f18, 0x18($a1)
/* 08E8A4 7F059D74 C4840008 */  lwc1  $f4, 8($a0)
/* 08E8A8 7F059D78 E4A40020 */  swc1  $f4, 0x20($a1)
/* 08E8AC 7F059D7C C4860018 */  lwc1  $f6, 0x18($a0)
/* 08E8B0 7F059D80 E4A60024 */  swc1  $f6, 0x24($a1)
/* 08E8B4 7F059D84 C4880028 */  lwc1  $f8, 0x28($a0)
/* 08E8B8 7F059D88 E4A00030 */  swc1  $f0, 0x30($a1)
/* 08E8BC 7F059D8C E4A00034 */  swc1  $f0, 0x34($a1)
/* 08E8C0 7F059D90 E4A00038 */  swc1  $f0, 0x38($a1)
/* 08E8C4 7F059D94 E4A0000C */  swc1  $f0, 0xc($a1)
/* 08E8C8 7F059D98 E4A0001C */  swc1  $f0, 0x1c($a1)
/* 08E8CC 7F059D9C E4A0002C */  swc1  $f0, 0x2c($a1)
/* 08E8D0 7F059DA0 E4AA003C */  swc1  $f10, 0x3c($a1)
/* 08E8D4 7F059DA4 03E00008 */  jr    $ra
/* 08E8D8 7F059DA8 E4A80028 */   swc1  $f8, 0x28($a1)
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F059DAC(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F059DAC
/* 08E8DC 7F059DAC C48C0000 */  lwc1  $f12, ($a0)
/* 08E8E0 7F059DB0 C48E0010 */  lwc1  $f14, 0x10($a0)
/* 08E8E4 7F059DB4 C4820020 */  lwc1  $f2, 0x20($a0)
/* 08E8E8 7F059DB8 460C6102 */  mul.s $f4, $f12, $f12
/* 08E8EC 7F059DBC 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 08E8F0 7F059DC0 44818000 */  mtc1  $at, $f16
/* 08E8F4 7F059DC4 460E7182 */  mul.s $f6, $f14, $f14
/* 08E8F8 7F059DC8 46062200 */  add.s $f8, $f4, $f6
/* 08E8FC 7F059DCC 46021282 */  mul.s $f10, $f2, $f2
/* 08E900 7F059DD0 44801000 */  mtc1  $zero, $f2
/* 08E904 7F059DD4 46085000 */  add.s $f0, $f10, $f8
/* 08E908 7F059DD8 46008003 */  div.s $f0, $f16, $f0
/* 08E90C 7F059DDC 46006482 */  mul.s $f18, $f12, $f0
/* 08E910 7F059DE0 E4B20000 */  swc1  $f18, ($a1)
/* 08E914 7F059DE4 C4840010 */  lwc1  $f4, 0x10($a0)
/* 08E918 7F059DE8 46002182 */  mul.s $f6, $f4, $f0
/* 08E91C 7F059DEC E4A60004 */  swc1  $f6, 4($a1)
/* 08E920 7F059DF0 C48A0020 */  lwc1  $f10, 0x20($a0)
/* 08E924 7F059DF4 46005202 */  mul.s $f8, $f10, $f0
/* 08E928 7F059DF8 E4A80008 */  swc1  $f8, 8($a1)
/* 08E92C 7F059DFC C4920004 */  lwc1  $f18, 4($a0)
/* 08E930 7F059E00 46009102 */  mul.s $f4, $f18, $f0
/* 08E934 7F059E04 E4A40010 */  swc1  $f4, 0x10($a1)
/* 08E938 7F059E08 C4860014 */  lwc1  $f6, 0x14($a0)
/* 08E93C 7F059E0C 46003282 */  mul.s $f10, $f6, $f0
/* 08E940 7F059E10 E4AA0014 */  swc1  $f10, 0x14($a1)
/* 08E944 7F059E14 C4880024 */  lwc1  $f8, 0x24($a0)
/* 08E948 7F059E18 46004482 */  mul.s $f18, $f8, $f0
/* 08E94C 7F059E1C E4B20018 */  swc1  $f18, 0x18($a1)
/* 08E950 7F059E20 C4840008 */  lwc1  $f4, 8($a0)
/* 08E954 7F059E24 46002182 */  mul.s $f6, $f4, $f0
/* 08E958 7F059E28 E4A60020 */  swc1  $f6, 0x20($a1)
/* 08E95C 7F059E2C C48A0018 */  lwc1  $f10, 0x18($a0)
/* 08E960 7F059E30 46005202 */  mul.s $f8, $f10, $f0
/* 08E964 7F059E34 E4A80024 */  swc1  $f8, 0x24($a1)
/* 08E968 7F059E38 C4920028 */  lwc1  $f18, 0x28($a0)
/* 08E96C 7F059E3C E4B0003C */  swc1  $f16, 0x3c($a1)
/* 08E970 7F059E40 E4A20030 */  swc1  $f2, 0x30($a1)
/* 08E974 7F059E44 46009102 */  mul.s $f4, $f18, $f0
/* 08E978 7F059E48 E4A20034 */  swc1  $f2, 0x34($a1)
/* 08E97C 7F059E4C E4A20038 */  swc1  $f2, 0x38($a1)
/* 08E980 7F059E50 E4A2000C */  swc1  $f2, 0xc($a1)
/* 08E984 7F059E54 E4A2001C */  swc1  $f2, 0x1c($a1)
/* 08E988 7F059E58 E4A2002C */  swc1  $f2, 0x2c($a1)
/* 08E98C 7F059E5C 03E00008 */  jr    $ra
/* 08E990 7F059E60 E4A40028 */   swc1  $f4, 0x28($a1)
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F059E64(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F059E64
/* 08E994 7F059E64 C48C0000 */  lwc1  $f12, ($a0)
/* 08E998 7F059E68 C48E0010 */  lwc1  $f14, 0x10($a0)
/* 08E99C 7F059E6C C4820020 */  lwc1  $f2, 0x20($a0)
/* 08E9A0 7F059E70 460C6102 */  mul.s $f4, $f12, $f12
/* 08E9A4 7F059E74 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 08E9A8 7F059E78 44818000 */  mtc1  $at, $f16
/* 08E9AC 7F059E7C 460E7182 */  mul.s $f6, $f14, $f14
/* 08E9B0 7F059E80 46062200 */  add.s $f8, $f4, $f6
/* 08E9B4 7F059E84 46021282 */  mul.s $f10, $f2, $f2
/* 08E9B8 7F059E88 46085000 */  add.s $f0, $f10, $f8
/* 08E9BC 7F059E8C 46008003 */  div.s $f0, $f16, $f0
/* 08E9C0 7F059E90 46006482 */  mul.s $f18, $f12, $f0
/* 08E9C4 7F059E94 E4B20000 */  swc1  $f18, ($a1)
/* 08E9C8 7F059E98 C4840010 */  lwc1  $f4, 0x10($a0)
/* 08E9CC 7F059E9C 46002182 */  mul.s $f6, $f4, $f0
/* 08E9D0 7F059EA0 E4A60004 */  swc1  $f6, 4($a1)
/* 08E9D4 7F059EA4 C48A0020 */  lwc1  $f10, 0x20($a0)
/* 08E9D8 7F059EA8 46005202 */  mul.s $f8, $f10, $f0
/* 08E9DC 7F059EAC E4A80008 */  swc1  $f8, 8($a1)
/* 08E9E0 7F059EB0 C4920004 */  lwc1  $f18, 4($a0)
/* 08E9E4 7F059EB4 46009102 */  mul.s $f4, $f18, $f0
/* 08E9E8 7F059EB8 E4A40010 */  swc1  $f4, 0x10($a1)
/* 08E9EC 7F059EBC C4860014 */  lwc1  $f6, 0x14($a0)
/* 08E9F0 7F059EC0 46003282 */  mul.s $f10, $f6, $f0
/* 08E9F4 7F059EC4 E4AA0014 */  swc1  $f10, 0x14($a1)
/* 08E9F8 7F059EC8 C4880024 */  lwc1  $f8, 0x24($a0)
/* 08E9FC 7F059ECC 46004482 */  mul.s $f18, $f8, $f0
/* 08EA00 7F059ED0 E4B20018 */  swc1  $f18, 0x18($a1)
/* 08EA04 7F059ED4 C4840008 */  lwc1  $f4, 8($a0)
/* 08EA08 7F059ED8 46002182 */  mul.s $f6, $f4, $f0
/* 08EA0C 7F059EDC E4A60020 */  swc1  $f6, 0x20($a1)
/* 08EA10 7F059EE0 C48A0018 */  lwc1  $f10, 0x18($a0)
/* 08EA14 7F059EE4 C4A60000 */  lwc1  $f6, ($a1)
/* 08EA18 7F059EE8 46005202 */  mul.s $f8, $f10, $f0
/* 08EA1C 7F059EEC E4A80024 */  swc1  $f8, 0x24($a1)
/* 08EA20 7F059EF0 C4920028 */  lwc1  $f18, 0x28($a0)
/* 08EA24 7F059EF4 46009102 */  mul.s $f4, $f18, $f0
/* 08EA28 7F059EF8 C4B20010 */  lwc1  $f18, 0x10($a1)
/* 08EA2C 7F059EFC 44800000 */  mtc1  $zero, $f0
/* 08EA30 7F059F00 E4A40028 */  swc1  $f4, 0x28($a1)
/* 08EA34 7F059F04 C48A0030 */  lwc1  $f10, 0x30($a0)
/* 08EA38 7F059F08 C4840034 */  lwc1  $f4, 0x34($a0)
/* 08EA3C 7F059F0C 460A3202 */  mul.s $f8, $f6, $f10
/* 08EA40 7F059F10 00000000 */  nop   
/* 08EA44 7F059F14 46049182 */  mul.s $f6, $f18, $f4
/* 08EA48 7F059F18 C4A40020 */  lwc1  $f4, 0x20($a1)
/* 08EA4C 7F059F1C C4920038 */  lwc1  $f18, 0x38($a0)
/* 08EA50 7F059F20 46064280 */  add.s $f10, $f8, $f6
/* 08EA54 7F059F24 46049202 */  mul.s $f8, $f18, $f4
/* 08EA58 7F059F28 C4A40004 */  lwc1  $f4, 4($a1)
/* 08EA5C 7F059F2C 460A4180 */  add.s $f6, $f8, $f10
/* 08EA60 7F059F30 46003487 */  neg.s $f18, $f6
/* 08EA64 7F059F34 C4A60014 */  lwc1  $f6, 0x14($a1)
/* 08EA68 7F059F38 E4B20030 */  swc1  $f18, 0x30($a1)
/* 08EA6C 7F059F3C C4880030 */  lwc1  $f8, 0x30($a0)
/* 08EA70 7F059F40 C4920034 */  lwc1  $f18, 0x34($a0)
/* 08EA74 7F059F44 46082282 */  mul.s $f10, $f4, $f8
/* 08EA78 7F059F48 00000000 */  nop   
/* 08EA7C 7F059F4C 46123102 */  mul.s $f4, $f6, $f18
/* 08EA80 7F059F50 C4B20024 */  lwc1  $f18, 0x24($a1)
/* 08EA84 7F059F54 C4860038 */  lwc1  $f6, 0x38($a0)
/* 08EA88 7F059F58 46045200 */  add.s $f8, $f10, $f4
/* 08EA8C 7F059F5C 46123282 */  mul.s $f10, $f6, $f18
/* 08EA90 7F059F60 C4B20008 */  lwc1  $f18, 8($a1)
/* 08EA94 7F059F64 46085100 */  add.s $f4, $f10, $f8
/* 08EA98 7F059F68 46002187 */  neg.s $f6, $f4
/* 08EA9C 7F059F6C C4A40018 */  lwc1  $f4, 0x18($a1)
/* 08EAA0 7F059F70 E4A60034 */  swc1  $f6, 0x34($a1)
/* 08EAA4 7F059F74 C48A0030 */  lwc1  $f10, 0x30($a0)
/* 08EAA8 7F059F78 C4860034 */  lwc1  $f6, 0x34($a0)
/* 08EAAC 7F059F7C 460A9202 */  mul.s $f8, $f18, $f10
/* 08EAB0 7F059F80 00000000 */  nop   
/* 08EAB4 7F059F84 46062482 */  mul.s $f18, $f4, $f6
/* 08EAB8 7F059F88 C4A60028 */  lwc1  $f6, 0x28($a1)
/* 08EABC 7F059F8C C4840038 */  lwc1  $f4, 0x38($a0)
/* 08EAC0 7F059F90 E4B0003C */  swc1  $f16, 0x3c($a1)
/* 08EAC4 7F059F94 E4A0000C */  swc1  $f0, 0xc($a1)
/* 08EAC8 7F059F98 E4A0001C */  swc1  $f0, 0x1c($a1)
/* 08EACC 7F059F9C E4A0002C */  swc1  $f0, 0x2c($a1)
/* 08EAD0 7F059FA0 46124280 */  add.s $f10, $f8, $f18
/* 08EAD4 7F059FA4 46062202 */  mul.s $f8, $f4, $f6
/* 08EAD8 7F059FA8 460A4480 */  add.s $f18, $f8, $f10
/* 08EADC 7F059FAC 46009107 */  neg.s $f4, $f18
/* 08EAE0 7F059FB0 03E00008 */  jr    $ra
/* 08EAE4 7F059FB4 E4A40038 */   swc1  $f4, 0x38($a1)
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F059FB8(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F059FB8
/* 08EAE8 7F059FB8 C4820000 */  lwc1  $f2, ($a0)
/* 08EAEC 7F059FBC C48C0014 */  lwc1  $f12, 0x14($a0)
/* 08EAF0 7F059FC0 C48E0028 */  lwc1  $f14, 0x28($a0)
/* 08EAF4 7F059FC4 C4900004 */  lwc1  $f16, 4($a0)
/* 08EAF8 7F059FC8 460C1102 */  mul.s $f4, $f2, $f12
/* 08EAFC 7F059FCC C4920018 */  lwc1  $f18, 0x18($a0)
/* 08EB00 7F059FD0 C48A0020 */  lwc1  $f10, 0x20($a0)
/* 08EB04 7F059FD4 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 08EB08 7F059FD8 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 08EB0C 7F059FDC E7AA0010 */  swc1  $f10, 0x10($sp)
/* 08EB10 7F059FE0 C7A80010 */  lwc1  $f8, 0x10($sp)
/* 08EB14 7F059FE4 460E2002 */  mul.s $f0, $f4, $f14
/* 08EB18 7F059FE8 C48A0008 */  lwc1  $f10, 8($a0)
/* 08EB1C 7F059FEC 46128182 */  mul.s $f6, $f16, $f18
/* 08EB20 7F059FF0 E7AA000C */  swc1  $f10, 0xc($sp)
/* 08EB24 7F059FF4 C7AA000C */  lwc1  $f10, 0xc($sp)
/* 08EB28 7F059FF8 46083102 */  mul.s $f4, $f6, $f8
/* 08EB2C 7F059FFC C4860010 */  lwc1  $f6, 0x10($a0)
/* 08EB30 7F05A000 E7A60008 */  swc1  $f6, 8($sp)
/* 08EB34 7F05A004 C7A60008 */  lwc1  $f6, 8($sp)
/* 08EB38 7F05A008 46040000 */  add.s $f0, $f0, $f4
/* 08EB3C 7F05A00C C4840024 */  lwc1  $f4, 0x24($a0)
/* 08EB40 7F05A010 E7A80000 */  swc1  $f8, ($sp)
/* 08EB44 7F05A014 E7A4001C */  swc1  $f4, 0x1c($sp)
/* 08EB48 7F05A018 46065102 */  mul.s $f4, $f10, $f6
/* 08EB4C 7F05A01C C7A8001C */  lwc1  $f8, 0x1c($sp)
/* 08EB50 7F05A020 46082102 */  mul.s $f4, $f4, $f8
/* 08EB54 7F05A024 46040000 */  add.s $f0, $f0, $f4
/* 08EB58 7F05A028 460C5102 */  mul.s $f4, $f10, $f12
/* 08EB5C 7F05A02C C7AA0000 */  lwc1  $f10, ($sp)
/* 08EB60 7F05A030 460A2102 */  mul.s $f4, $f4, $f10
/* 08EB64 7F05A034 00000000 */  nop   
/* 08EB68 7F05A038 46068282 */  mul.s $f10, $f16, $f6
/* 08EB6C 7F05A03C 46040001 */  sub.s $f0, $f0, $f4
/* 08EB70 7F05A040 460E5102 */  mul.s $f4, $f10, $f14
/* 08EB74 7F05A044 00000000 */  nop   
/* 08EB78 7F05A048 46121182 */  mul.s $f6, $f2, $f18
/* 08EB7C 7F05A04C 44811000 */  mtc1  $at, $f2
/* 08EB80 7F05A050 46040001 */  sub.s $f0, $f0, $f4
/* 08EB84 7F05A054 46083282 */  mul.s $f10, $f6, $f8
/* 08EB88 7F05A058 460A0001 */  sub.s $f0, $f0, $f10
/* 08EB8C 7F05A05C 460E6102 */  mul.s $f4, $f12, $f14
/* 08EB90 7F05A060 00000000 */  nop   
/* 08EB94 7F05A064 46124182 */  mul.s $f6, $f8, $f18
/* 08EB98 7F05A068 46001003 */  div.s $f0, $f2, $f0
/* 08EB9C 7F05A06C 46062281 */  sub.s $f10, $f4, $f6
/* 08EBA0 7F05A070 46005202 */  mul.s $f8, $f10, $f0
/* 08EBA4 7F05A074 E4A80000 */  swc1  $f8, ($a1)
/* 08EBA8 7F05A078 C4840018 */  lwc1  $f4, 0x18($a0)
/* 08EBAC 7F05A07C C4860020 */  lwc1  $f6, 0x20($a0)
/* 08EBB0 7F05A080 C4880028 */  lwc1  $f8, 0x28($a0)
/* 08EBB4 7F05A084 46062282 */  mul.s $f10, $f4, $f6
/* 08EBB8 7F05A088 C4840010 */  lwc1  $f4, 0x10($a0)
/* 08EBBC 7F05A08C 46044182 */  mul.s $f6, $f8, $f4
/* 08EBC0 7F05A090 46065201 */  sub.s $f8, $f10, $f6
/* 08EBC4 7F05A094 46004102 */  mul.s $f4, $f8, $f0
/* 08EBC8 7F05A098 E4A40010 */  swc1  $f4, 0x10($a1)
/* 08EBCC 7F05A09C C48A0010 */  lwc1  $f10, 0x10($a0)
/* 08EBD0 7F05A0A0 C4860024 */  lwc1  $f6, 0x24($a0)
/* 08EBD4 7F05A0A4 C4840020 */  lwc1  $f4, 0x20($a0)
/* 08EBD8 7F05A0A8 46065202 */  mul.s $f8, $f10, $f6
/* 08EBDC 7F05A0AC C48A0014 */  lwc1  $f10, 0x14($a0)
/* 08EBE0 7F05A0B0 460A2182 */  mul.s $f6, $f4, $f10
/* 08EBE4 7F05A0B4 46064101 */  sub.s $f4, $f8, $f6
/* 08EBE8 7F05A0B8 46002282 */  mul.s $f10, $f4, $f0
/* 08EBEC 7F05A0BC E4AA0020 */  swc1  $f10, 0x20($a1)
/* 08EBF0 7F05A0C0 C4880008 */  lwc1  $f8, 8($a0)
/* 08EBF4 7F05A0C4 C4860024 */  lwc1  $f6, 0x24($a0)
/* 08EBF8 7F05A0C8 C48A0028 */  lwc1  $f10, 0x28($a0)
/* 08EBFC 7F05A0CC 46064102 */  mul.s $f4, $f8, $f6
/* 08EC00 7F05A0D0 C4880004 */  lwc1  $f8, 4($a0)
/* 08EC04 7F05A0D4 46085182 */  mul.s $f6, $f10, $f8
/* 08EC08 7F05A0D8 46062281 */  sub.s $f10, $f4, $f6
/* 08EC0C 7F05A0DC 46005202 */  mul.s $f8, $f10, $f0
/* 08EC10 7F05A0E0 E4A80004 */  swc1  $f8, 4($a1)
/* 08EC14 7F05A0E4 C4840000 */  lwc1  $f4, ($a0)
/* 08EC18 7F05A0E8 C4860028 */  lwc1  $f6, 0x28($a0)
/* 08EC1C 7F05A0EC C4880020 */  lwc1  $f8, 0x20($a0)
/* 08EC20 7F05A0F0 46062282 */  mul.s $f10, $f4, $f6
/* 08EC24 7F05A0F4 C4840008 */  lwc1  $f4, 8($a0)
/* 08EC28 7F05A0F8 46044182 */  mul.s $f6, $f8, $f4
/* 08EC2C 7F05A0FC 46065201 */  sub.s $f8, $f10, $f6
/* 08EC30 7F05A100 46004102 */  mul.s $f4, $f8, $f0
/* 08EC34 7F05A104 E4A40014 */  swc1  $f4, 0x14($a1)
/* 08EC38 7F05A108 C48A0004 */  lwc1  $f10, 4($a0)
/* 08EC3C 7F05A10C C4860020 */  lwc1  $f6, 0x20($a0)
/* 08EC40 7F05A110 C4840024 */  lwc1  $f4, 0x24($a0)
/* 08EC44 7F05A114 46065202 */  mul.s $f8, $f10, $f6
/* 08EC48 7F05A118 C48A0000 */  lwc1  $f10, ($a0)
/* 08EC4C 7F05A11C 460A2182 */  mul.s $f6, $f4, $f10
/* 08EC50 7F05A120 46064101 */  sub.s $f4, $f8, $f6
/* 08EC54 7F05A124 46002282 */  mul.s $f10, $f4, $f0
/* 08EC58 7F05A128 E4AA0024 */  swc1  $f10, 0x24($a1)
/* 08EC5C 7F05A12C C4880004 */  lwc1  $f8, 4($a0)
/* 08EC60 7F05A130 C4860018 */  lwc1  $f6, 0x18($a0)
/* 08EC64 7F05A134 C48A0014 */  lwc1  $f10, 0x14($a0)
/* 08EC68 7F05A138 46064102 */  mul.s $f4, $f8, $f6
/* 08EC6C 7F05A13C C4880008 */  lwc1  $f8, 8($a0)
/* 08EC70 7F05A140 46085182 */  mul.s $f6, $f10, $f8
/* 08EC74 7F05A144 46062281 */  sub.s $f10, $f4, $f6
/* 08EC78 7F05A148 46005202 */  mul.s $f8, $f10, $f0
/* 08EC7C 7F05A14C E4A80008 */  swc1  $f8, 8($a1)
/* 08EC80 7F05A150 C4860010 */  lwc1  $f6, 0x10($a0)
/* 08EC84 7F05A154 C4840008 */  lwc1  $f4, 8($a0)
/* 08EC88 7F05A158 C4880018 */  lwc1  $f8, 0x18($a0)
/* 08EC8C 7F05A15C 46062282 */  mul.s $f10, $f4, $f6
/* 08EC90 7F05A160 C4840000 */  lwc1  $f4, ($a0)
/* 08EC94 7F05A164 46044182 */  mul.s $f6, $f8, $f4
/* 08EC98 7F05A168 46065201 */  sub.s $f8, $f10, $f6
/* 08EC9C 7F05A16C 46004102 */  mul.s $f4, $f8, $f0
/* 08ECA0 7F05A170 E4A40018 */  swc1  $f4, 0x18($a1)
/* 08ECA4 7F05A174 C4860014 */  lwc1  $f6, 0x14($a0)
/* 08ECA8 7F05A178 C48A0000 */  lwc1  $f10, ($a0)
/* 08ECAC 7F05A17C C4840010 */  lwc1  $f4, 0x10($a0)
/* 08ECB0 7F05A180 46065202 */  mul.s $f8, $f10, $f6
/* 08ECB4 7F05A184 C48A0004 */  lwc1  $f10, 4($a0)
/* 08ECB8 7F05A188 460A2182 */  mul.s $f6, $f4, $f10
/* 08ECBC 7F05A18C 46064101 */  sub.s $f4, $f8, $f6
/* 08ECC0 7F05A190 C4A60000 */  lwc1  $f6, ($a1)
/* 08ECC4 7F05A194 46002282 */  mul.s $f10, $f4, $f0
/* 08ECC8 7F05A198 44800000 */  mtc1  $zero, $f0
/* 08ECCC 7F05A19C E4AA0028 */  swc1  $f10, 0x28($a1)
/* 08ECD0 7F05A1A0 C4880030 */  lwc1  $f8, 0x30($a0)
/* 08ECD4 7F05A1A4 C48A0034 */  lwc1  $f10, 0x34($a0)
/* 08ECD8 7F05A1A8 46064102 */  mul.s $f4, $f8, $f6
/* 08ECDC 7F05A1AC C4A80010 */  lwc1  $f8, 0x10($a1)
/* 08ECE0 7F05A1B0 46085182 */  mul.s $f6, $f10, $f8
/* 08ECE4 7F05A1B4 C4A80020 */  lwc1  $f8, 0x20($a1)
/* 08ECE8 7F05A1B8 46062280 */  add.s $f10, $f4, $f6
/* 08ECEC 7F05A1BC C4840038 */  lwc1  $f4, 0x38($a0)
/* 08ECF0 7F05A1C0 46044182 */  mul.s $f6, $f8, $f4
/* 08ECF4 7F05A1C4 460A3200 */  add.s $f8, $f6, $f10
/* 08ECF8 7F05A1C8 C4AA0004 */  lwc1  $f10, 4($a1)
/* 08ECFC 7F05A1CC 46004107 */  neg.s $f4, $f8
/* 08ED00 7F05A1D0 E4A40030 */  swc1  $f4, 0x30($a1)
/* 08ED04 7F05A1D4 C4860030 */  lwc1  $f6, 0x30($a0)
/* 08ED08 7F05A1D8 C4840034 */  lwc1  $f4, 0x34($a0)
/* 08ED0C 7F05A1DC 460A3202 */  mul.s $f8, $f6, $f10
/* 08ED10 7F05A1E0 C4A60014 */  lwc1  $f6, 0x14($a1)
/* 08ED14 7F05A1E4 46062282 */  mul.s $f10, $f4, $f6
/* 08ED18 7F05A1E8 C4A60024 */  lwc1  $f6, 0x24($a1)
/* 08ED1C 7F05A1EC 460A4100 */  add.s $f4, $f8, $f10
/* 08ED20 7F05A1F0 C4880038 */  lwc1  $f8, 0x38($a0)
/* 08ED24 7F05A1F4 46083282 */  mul.s $f10, $f6, $f8
/* 08ED28 7F05A1F8 46045180 */  add.s $f6, $f10, $f4
/* 08ED2C 7F05A1FC C4A40008 */  lwc1  $f4, 8($a1)
/* 08ED30 7F05A200 46003207 */  neg.s $f8, $f6
/* 08ED34 7F05A204 E4A80034 */  swc1  $f8, 0x34($a1)
/* 08ED38 7F05A208 C48A0030 */  lwc1  $f10, 0x30($a0)
/* 08ED3C 7F05A20C C4880034 */  lwc1  $f8, 0x34($a0)
/* 08ED40 7F05A210 46045182 */  mul.s $f6, $f10, $f4
/* 08ED44 7F05A214 C4AA0018 */  lwc1  $f10, 0x18($a1)
/* 08ED48 7F05A218 460A4102 */  mul.s $f4, $f8, $f10
/* 08ED4C 7F05A21C C4AA0028 */  lwc1  $f10, 0x28($a1)
/* 08ED50 7F05A220 46043200 */  add.s $f8, $f6, $f4
/* 08ED54 7F05A224 C4860038 */  lwc1  $f6, 0x38($a0)
/* 08ED58 7F05A228 27BD0030 */  addiu $sp, $sp, 0x30
/* 08ED5C 7F05A22C E4A2003C */  swc1  $f2, 0x3c($a1)
/* 08ED60 7F05A230 46065102 */  mul.s $f4, $f10, $f6
/* 08ED64 7F05A234 E4A0000C */  swc1  $f0, 0xc($a1)
/* 08ED68 7F05A238 E4A0001C */  swc1  $f0, 0x1c($a1)
/* 08ED6C 7F05A23C E4A0002C */  swc1  $f0, 0x2c($a1)
/* 08ED70 7F05A240 46082280 */  add.s $f10, $f4, $f8
/* 08ED74 7F05A244 46005187 */  neg.s $f6, $f10
/* 08ED78 7F05A248 03E00008 */  jr    $ra
/* 08ED7C 7F05A24C E4A60038 */   swc1  $f6, 0x38($a1)
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F05A250(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F05A250
/* 08ED80 7F05A250 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 08ED84 7F05A254 AFBF0014 */  sw    $ra, 0x14($sp)
/* 08ED88 7F05A258 AFA40018 */  sw    $a0, 0x18($sp)
/* 08ED8C 7F05A25C 0FC168C4 */  jal   sub_GAME_7F05A310
/* 08ED90 7F05A260 AFA5001C */   sw    $a1, 0x1c($sp)
/* 08ED94 7F05A264 0FC169DD */  jal   sub_GAME_7F05A774
/* 08ED98 7F05A268 8FA40018 */   lw    $a0, 0x18($sp)
/* 08ED9C 7F05A26C 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 08EDA0 7F05A270 44812000 */  mtc1  $at, $f4
/* 08EDA4 7F05A274 00001825 */  move  $v1, $zero
/* 08EDA8 7F05A278 8FA2001C */  lw    $v0, 0x1c($sp)
/* 08EDAC 7F05A27C 24040004 */  li    $a0, 4
/* 08EDB0 7F05A280 46002083 */  div.s $f2, $f4, $f0
/* 08EDB4 7F05A284 C4480000 */  lwc1  $f8, ($v0)
/* 08EDB8 7F05A288 24630001 */  addiu $v1, $v1, 1
/* 08EDBC 7F05A28C C44E0004 */  lwc1  $f14, 4($v0)
/* 08EDC0 7F05A290 46024402 */  mul.s $f16, $f8, $f2
/* 08EDC4 7F05A294 C44C0008 */  lwc1  $f12, 8($v0)
/* 08EDC8 7F05A298 10640010 */  beq   $v1, $a0, .L7F05A2DC
/* 08EDCC 7F05A29C C452000C */   lwc1  $f18, 0xc($v0)
.L7F05A2A0:
/* 08EDD0 7F05A2A0 46027282 */  mul.s $f10, $f14, $f2
/* 08EDD4 7F05A2A4 C4480010 */  lwc1  $f8, 0x10($v0)
/* 08EDD8 7F05A2A8 C44E0014 */  lwc1  $f14, 0x14($v0)
/* 08EDDC 7F05A2AC 46026182 */  mul.s $f6, $f12, $f2
/* 08EDE0 7F05A2B0 C44C0018 */  lwc1  $f12, 0x18($v0)
/* 08EDE4 7F05A2B4 24630001 */  addiu $v1, $v1, 1
/* 08EDE8 7F05A2B8 46029102 */  mul.s $f4, $f18, $f2
/* 08EDEC 7F05A2BC C452001C */  lwc1  $f18, 0x1c($v0)
/* 08EDF0 7F05A2C0 E4500000 */  swc1  $f16, ($v0)
/* 08EDF4 7F05A2C4 46024402 */  mul.s $f16, $f8, $f2
/* 08EDF8 7F05A2C8 E44A0004 */  swc1  $f10, 4($v0)
/* 08EDFC 7F05A2CC E4460008 */  swc1  $f6, 8($v0)
/* 08EE00 7F05A2D0 24420010 */  addiu $v0, $v0, 0x10
/* 08EE04 7F05A2D4 1464FFF2 */  bne   $v1, $a0, .L7F05A2A0
/* 08EE08 7F05A2D8 E444FFFC */   swc1  $f4, -4($v0)
.L7F05A2DC:
/* 08EE0C 7F05A2DC 46027282 */  mul.s $f10, $f14, $f2
/* 08EE10 7F05A2E0 24420010 */  addiu $v0, $v0, 0x10
/* 08EE14 7F05A2E4 E450FFF0 */  swc1  $f16, -0x10($v0)
/* 08EE18 7F05A2E8 46026182 */  mul.s $f6, $f12, $f2
/* 08EE1C 7F05A2EC 00000000 */  nop   
/* 08EE20 7F05A2F0 46029102 */  mul.s $f4, $f18, $f2
/* 08EE24 7F05A2F4 E44AFFF4 */  swc1  $f10, -0xc($v0)
/* 08EE28 7F05A2F8 E446FFF8 */  swc1  $f6, -8($v0)
/* 08EE2C 7F05A2FC E444FFFC */  swc1  $f4, -4($v0)
/* 08EE30 7F05A300 8FBF0014 */  lw    $ra, 0x14($sp)
/* 08EE34 7F05A304 27BD0018 */  addiu $sp, $sp, 0x18
/* 08EE38 7F05A308 03E00008 */  jr    $ra
/* 08EE3C 7F05A30C 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F05A310(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F05A310
/* 08EE40 7F05A310 27BDFF58 */  addiu $sp, $sp, -0xa8
/* 08EE44 7F05A314 AFBF0064 */  sw    $ra, 0x64($sp)
/* 08EE48 7F05A318 AFB00060 */  sw    $s0, 0x60($sp)
/* 08EE4C 7F05A31C F7BE0058 */  sdc1  $f30, 0x58($sp)
/* 08EE50 7F05A320 F7BC0050 */  sdc1  $f28, 0x50($sp)
/* 08EE54 7F05A324 F7BA0048 */  sdc1  $f26, 0x48($sp)
/* 08EE58 7F05A328 F7B80040 */  sdc1  $f24, 0x40($sp)
/* 08EE5C 7F05A32C F7B60038 */  sdc1  $f22, 0x38($sp)
/* 08EE60 7F05A330 F7B40030 */  sdc1  $f20, 0x30($sp)
/* 08EE64 7F05A334 C4840008 */  lwc1  $f4, 8($a0)
/* 08EE68 7F05A338 C49E0004 */  lwc1  $f30, 4($a0)
/* 08EE6C 7F05A33C C49C0000 */  lwc1  $f28, ($a0)
/* 08EE70 7F05A340 E7A40084 */  swc1  $f4, 0x84($sp)
/* 08EE74 7F05A344 C486000C */  lwc1  $f6, 0xc($a0)
/* 08EE78 7F05A348 00A08025 */  move  $s0, $a1
/* 08EE7C 7F05A34C E7A60074 */  swc1  $f6, 0x74($sp)
/* 08EE80 7F05A350 C4880010 */  lwc1  $f8, 0x10($a0)
/* 08EE84 7F05A354 E7A800A0 */  swc1  $f8, 0xa0($sp)
/* 08EE88 7F05A358 C48A0020 */  lwc1  $f10, 0x20($a0)
/* 08EE8C 7F05A35C C48C0014 */  lwc1  $f12, 0x14($a0)
/* 08EE90 7F05A360 C482001C */  lwc1  $f2, 0x1c($a0)
/* 08EE94 7F05A364 C4800018 */  lwc1  $f0, 0x18($a0)
/* 08EE98 7F05A368 E7AA009C */  swc1  $f10, 0x9c($sp)
/* 08EE9C 7F05A36C C4960034 */  lwc1  $f22, 0x34($a0)
/* 08EEA0 7F05A370 C48E0024 */  lwc1  $f14, 0x24($a0)
/* 08EEA4 7F05A374 C492002C */  lwc1  $f18, 0x2c($a0)
/* 08EEA8 7F05A378 C4900028 */  lwc1  $f16, 0x28($a0)
/* 08EEAC 7F05A37C C49A003C */  lwc1  $f26, 0x3c($a0)
/* 08EEB0 7F05A380 C4980038 */  lwc1  $f24, 0x38($a0)
/* 08EEB4 7F05A384 C4940030 */  lwc1  $f20, 0x30($a0)
/* 08EEB8 7F05A388 44070000 */  mfc1  $a3, $f0
/* 08EEBC 7F05A38C 4406B000 */  mfc1  $a2, $f22
/* 08EEC0 7F05A390 E7AC0090 */  swc1  $f12, 0x90($sp)
/* 08EEC4 7F05A394 E7A20070 */  swc1  $f2, 0x70($sp)
/* 08EEC8 7F05A398 E7A20018 */  swc1  $f2, 0x18($sp)
/* 08EECC 7F05A39C E7A00080 */  swc1  $f0, 0x80($sp)
/* 08EED0 7F05A3A0 E7AE008C */  swc1  $f14, 0x8c($sp)
/* 08EED4 7F05A3A4 E7B2006C */  swc1  $f18, 0x6c($sp)
/* 08EED8 7F05A3A8 E7B2001C */  swc1  $f18, 0x1c($sp)
/* 08EEDC 7F05A3AC E7B0007C */  swc1  $f16, 0x7c($sp)
/* 08EEE0 7F05A3B0 E7B00010 */  swc1  $f16, 0x10($sp)
/* 08EEE4 7F05A3B4 E7BA0020 */  swc1  $f26, 0x20($sp)
/* 08EEE8 7F05A3B8 0FC16A4A */  jal   sub_GAME_7F05A928
/* 08EEEC 7F05A3BC E7B80014 */   swc1  $f24, 0x14($sp)
/* 08EEF0 7F05A3C0 E6000000 */  swc1  $f0, ($s0)
/* 08EEF4 7F05A3C4 C7A8006C */  lwc1  $f8, 0x6c($sp)
/* 08EEF8 7F05A3C8 C7A60070 */  lwc1  $f6, 0x70($sp)
/* 08EEFC 7F05A3CC C7A4007C */  lwc1  $f4, 0x7c($sp)
/* 08EF00 7F05A3D0 4406A000 */  mfc1  $a2, $f20
/* 08EF04 7F05A3D4 E7BA0020 */  swc1  $f26, 0x20($sp)
/* 08EF08 7F05A3D8 E7B80014 */  swc1  $f24, 0x14($sp)
/* 08EF0C 7F05A3DC 8FA70080 */  lw    $a3, 0x80($sp)
/* 08EF10 7F05A3E0 C7AE009C */  lwc1  $f14, 0x9c($sp)
/* 08EF14 7F05A3E4 C7AC00A0 */  lwc1  $f12, 0xa0($sp)
/* 08EF18 7F05A3E8 E7A8001C */  swc1  $f8, 0x1c($sp)
/* 08EF1C 7F05A3EC E7A60018 */  swc1  $f6, 0x18($sp)
/* 08EF20 7F05A3F0 0FC16A4A */  jal   sub_GAME_7F05A928
/* 08EF24 7F05A3F4 E7A40010 */   swc1  $f4, 0x10($sp)
/* 08EF28 7F05A3F8 46000287 */  neg.s $f10, $f0
/* 08EF2C 7F05A3FC 4406A000 */  mfc1  $a2, $f20
/* 08EF30 7F05A400 E60A0010 */  swc1  $f10, 0x10($s0)
/* 08EF34 7F05A404 C7A8006C */  lwc1  $f8, 0x6c($sp)
/* 08EF38 7F05A408 C7A60070 */  lwc1  $f6, 0x70($sp)
/* 08EF3C 7F05A40C C7A4008C */  lwc1  $f4, 0x8c($sp)
/* 08EF40 7F05A410 E7BA0020 */  swc1  $f26, 0x20($sp)
/* 08EF44 7F05A414 E7B60014 */  swc1  $f22, 0x14($sp)
/* 08EF48 7F05A418 8FA70090 */  lw    $a3, 0x90($sp)
/* 08EF4C 7F05A41C C7AE009C */  lwc1  $f14, 0x9c($sp)
/* 08EF50 7F05A420 C7AC00A0 */  lwc1  $f12, 0xa0($sp)
/* 08EF54 7F05A424 E7A8001C */  swc1  $f8, 0x1c($sp)
/* 08EF58 7F05A428 E7A60018 */  swc1  $f6, 0x18($sp)
/* 08EF5C 7F05A42C 0FC16A4A */  jal   sub_GAME_7F05A928
/* 08EF60 7F05A430 E7A40010 */   swc1  $f4, 0x10($sp)
/* 08EF64 7F05A434 E6000020 */  swc1  $f0, 0x20($s0)
/* 08EF68 7F05A438 C7A6007C */  lwc1  $f6, 0x7c($sp)
/* 08EF6C 7F05A43C C7A40080 */  lwc1  $f4, 0x80($sp)
/* 08EF70 7F05A440 C7AA008C */  lwc1  $f10, 0x8c($sp)
/* 08EF74 7F05A444 4406A000 */  mfc1  $a2, $f20
/* 08EF78 7F05A448 E7B80020 */  swc1  $f24, 0x20($sp)
/* 08EF7C 7F05A44C E7B60014 */  swc1  $f22, 0x14($sp)
/* 08EF80 7F05A450 8FA70090 */  lw    $a3, 0x90($sp)
/* 08EF84 7F05A454 C7AE009C */  lwc1  $f14, 0x9c($sp)
/* 08EF88 7F05A458 C7AC00A0 */  lwc1  $f12, 0xa0($sp)
/* 08EF8C 7F05A45C E7A6001C */  swc1  $f6, 0x1c($sp)
/* 08EF90 7F05A460 E7A40018 */  swc1  $f4, 0x18($sp)
/* 08EF94 7F05A464 0FC16A4A */  jal   sub_GAME_7F05A928
/* 08EF98 7F05A468 E7AA0010 */   swc1  $f10, 0x10($sp)
/* 08EF9C 7F05A46C 46000207 */  neg.s $f8, $f0
/* 08EFA0 7F05A470 4406B000 */  mfc1  $a2, $f22
/* 08EFA4 7F05A474 E6080030 */  swc1  $f8, 0x30($s0)
/* 08EFA8 7F05A478 C7A6006C */  lwc1  $f6, 0x6c($sp)
/* 08EFAC 7F05A47C C7A40074 */  lwc1  $f4, 0x74($sp)
/* 08EFB0 7F05A480 C7AA007C */  lwc1  $f10, 0x7c($sp)
/* 08EFB4 7F05A484 E7BA0020 */  swc1  $f26, 0x20($sp)
/* 08EFB8 7F05A488 E7B80014 */  swc1  $f24, 0x14($sp)
/* 08EFBC 7F05A48C 8FA70084 */  lw    $a3, 0x84($sp)
/* 08EFC0 7F05A490 C7AE008C */  lwc1  $f14, 0x8c($sp)
/* 08EFC4 7F05A494 4600F306 */  mov.s $f12, $f30
/* 08EFC8 7F05A498 E7A6001C */  swc1  $f6, 0x1c($sp)
/* 08EFCC 7F05A49C E7A40018 */  swc1  $f4, 0x18($sp)
/* 08EFD0 7F05A4A0 0FC16A4A */  jal   sub_GAME_7F05A928
/* 08EFD4 7F05A4A4 E7AA0010 */   swc1  $f10, 0x10($sp)
/* 08EFD8 7F05A4A8 46000207 */  neg.s $f8, $f0
/* 08EFDC 7F05A4AC 4406A000 */  mfc1  $a2, $f20
/* 08EFE0 7F05A4B0 E6080004 */  swc1  $f8, 4($s0)
/* 08EFE4 7F05A4B4 C7A6006C */  lwc1  $f6, 0x6c($sp)
/* 08EFE8 7F05A4B8 C7A40074 */  lwc1  $f4, 0x74($sp)
/* 08EFEC 7F05A4BC C7AA007C */  lwc1  $f10, 0x7c($sp)
/* 08EFF0 7F05A4C0 E7BA0020 */  swc1  $f26, 0x20($sp)
/* 08EFF4 7F05A4C4 E7B80014 */  swc1  $f24, 0x14($sp)
/* 08EFF8 7F05A4C8 8FA70084 */  lw    $a3, 0x84($sp)
/* 08EFFC 7F05A4CC C7AE009C */  lwc1  $f14, 0x9c($sp)
/* 08F000 7F05A4D0 4600E306 */  mov.s $f12, $f28
/* 08F004 7F05A4D4 E7A6001C */  swc1  $f6, 0x1c($sp)
/* 08F008 7F05A4D8 E7A40018 */  swc1  $f4, 0x18($sp)
/* 08F00C 7F05A4DC 0FC16A4A */  jal   sub_GAME_7F05A928
/* 08F010 7F05A4E0 E7AA0010 */   swc1  $f10, 0x10($sp)
/* 08F014 7F05A4E4 E6000014 */  swc1  $f0, 0x14($s0)
/* 08F018 7F05A4E8 C7A4006C */  lwc1  $f4, 0x6c($sp)
/* 08F01C 7F05A4EC C7AA0074 */  lwc1  $f10, 0x74($sp)
/* 08F020 7F05A4F0 C7A8008C */  lwc1  $f8, 0x8c($sp)
/* 08F024 7F05A4F4 4406A000 */  mfc1  $a2, $f20
/* 08F028 7F05A4F8 4407F000 */  mfc1  $a3, $f30
/* 08F02C 7F05A4FC E7BA0020 */  swc1  $f26, 0x20($sp)
/* 08F030 7F05A500 E7B60014 */  swc1  $f22, 0x14($sp)
/* 08F034 7F05A504 C7AE009C */  lwc1  $f14, 0x9c($sp)
/* 08F038 7F05A508 4600E306 */  mov.s $f12, $f28
/* 08F03C 7F05A50C E7A4001C */  swc1  $f4, 0x1c($sp)
/* 08F040 7F05A510 E7AA0018 */  swc1  $f10, 0x18($sp)
/* 08F044 7F05A514 0FC16A4A */  jal   sub_GAME_7F05A928
/* 08F048 7F05A518 E7A80010 */   swc1  $f8, 0x10($sp)
/* 08F04C 7F05A51C 46000187 */  neg.s $f6, $f0
/* 08F050 7F05A520 4406A000 */  mfc1  $a2, $f20
/* 08F054 7F05A524 E6060024 */  swc1  $f6, 0x24($s0)
/* 08F058 7F05A528 C7A4007C */  lwc1  $f4, 0x7c($sp)
/* 08F05C 7F05A52C C7AA0084 */  lwc1  $f10, 0x84($sp)
/* 08F060 7F05A530 C7A8008C */  lwc1  $f8, 0x8c($sp)
/* 08F064 7F05A534 4407F000 */  mfc1  $a3, $f30
/* 08F068 7F05A538 E7B80020 */  swc1  $f24, 0x20($sp)
/* 08F06C 7F05A53C E7B60014 */  swc1  $f22, 0x14($sp)
/* 08F070 7F05A540 C7AE009C */  lwc1  $f14, 0x9c($sp)
/* 08F074 7F05A544 4600E306 */  mov.s $f12, $f28
/* 08F078 7F05A548 E7A4001C */  swc1  $f4, 0x1c($sp)
/* 08F07C 7F05A54C E7AA0018 */  swc1  $f10, 0x18($sp)
/* 08F080 7F05A550 0FC16A4A */  jal   sub_GAME_7F05A928
/* 08F084 7F05A554 E7A80010 */   swc1  $f8, 0x10($sp)
/* 08F088 7F05A558 E6000034 */  swc1  $f0, 0x34($s0)
/* 08F08C 7F05A55C C7AA0070 */  lwc1  $f10, 0x70($sp)
/* 08F090 7F05A560 C7A80074 */  lwc1  $f8, 0x74($sp)
/* 08F094 7F05A564 C7A60080 */  lwc1  $f6, 0x80($sp)
/* 08F098 7F05A568 4406B000 */  mfc1  $a2, $f22
/* 08F09C 7F05A56C E7BA0020 */  swc1  $f26, 0x20($sp)
/* 08F0A0 7F05A570 E7B80014 */  swc1  $f24, 0x14($sp)
/* 08F0A4 7F05A574 8FA70084 */  lw    $a3, 0x84($sp)
/* 08F0A8 7F05A578 C7AE0090 */  lwc1  $f14, 0x90($sp)
/* 08F0AC 7F05A57C 4600F306 */  mov.s $f12, $f30
/* 08F0B0 7F05A580 E7AA001C */  swc1  $f10, 0x1c($sp)
/* 08F0B4 7F05A584 E7A80018 */  swc1  $f8, 0x18($sp)
/* 08F0B8 7F05A588 0FC16A4A */  jal   sub_GAME_7F05A928
/* 08F0BC 7F05A58C E7A60010 */   swc1  $f6, 0x10($sp)
/* 08F0C0 7F05A590 E6000008 */  swc1  $f0, 8($s0)
/* 08F0C4 7F05A594 C7A80070 */  lwc1  $f8, 0x70($sp)
/* 08F0C8 7F05A598 C7A60074 */  lwc1  $f6, 0x74($sp)
/* 08F0CC 7F05A59C C7A40080 */  lwc1  $f4, 0x80($sp)
/* 08F0D0 7F05A5A0 4406A000 */  mfc1  $a2, $f20
/* 08F0D4 7F05A5A4 E7BA0020 */  swc1  $f26, 0x20($sp)
/* 08F0D8 7F05A5A8 E7B80014 */  swc1  $f24, 0x14($sp)
/* 08F0DC 7F05A5AC 8FA70084 */  lw    $a3, 0x84($sp)
/* 08F0E0 7F05A5B0 C7AE00A0 */  lwc1  $f14, 0xa0($sp)
/* 08F0E4 7F05A5B4 4600E306 */  mov.s $f12, $f28
/* 08F0E8 7F05A5B8 E7A8001C */  swc1  $f8, 0x1c($sp)
/* 08F0EC 7F05A5BC E7A60018 */  swc1  $f6, 0x18($sp)
/* 08F0F0 7F05A5C0 0FC16A4A */  jal   sub_GAME_7F05A928
/* 08F0F4 7F05A5C4 E7A40010 */   swc1  $f4, 0x10($sp)
/* 08F0F8 7F05A5C8 46000287 */  neg.s $f10, $f0
/* 08F0FC 7F05A5CC 4406A000 */  mfc1  $a2, $f20
/* 08F100 7F05A5D0 E60A0018 */  swc1  $f10, 0x18($s0)
/* 08F104 7F05A5D4 C7A80070 */  lwc1  $f8, 0x70($sp)
/* 08F108 7F05A5D8 C7A60074 */  lwc1  $f6, 0x74($sp)
/* 08F10C 7F05A5DC C7A40090 */  lwc1  $f4, 0x90($sp)
/* 08F110 7F05A5E0 4407F000 */  mfc1  $a3, $f30
/* 08F114 7F05A5E4 E7BA0020 */  swc1  $f26, 0x20($sp)
/* 08F118 7F05A5E8 E7B60014 */  swc1  $f22, 0x14($sp)
/* 08F11C 7F05A5EC C7AE00A0 */  lwc1  $f14, 0xa0($sp)
/* 08F120 7F05A5F0 4600E306 */  mov.s $f12, $f28
/* 08F124 7F05A5F4 E7A8001C */  swc1  $f8, 0x1c($sp)
/* 08F128 7F05A5F8 E7A60018 */  swc1  $f6, 0x18($sp)
/* 08F12C 7F05A5FC 0FC16A4A */  jal   sub_GAME_7F05A928
/* 08F130 7F05A600 E7A40010 */   swc1  $f4, 0x10($sp)
/* 08F134 7F05A604 E6000028 */  swc1  $f0, 0x28($s0)
/* 08F138 7F05A608 C7A60080 */  lwc1  $f6, 0x80($sp)
/* 08F13C 7F05A60C C7A40084 */  lwc1  $f4, 0x84($sp)
/* 08F140 7F05A610 C7AA0090 */  lwc1  $f10, 0x90($sp)
/* 08F144 7F05A614 4406A000 */  mfc1  $a2, $f20
/* 08F148 7F05A618 4407F000 */  mfc1  $a3, $f30
/* 08F14C 7F05A61C E7B80020 */  swc1  $f24, 0x20($sp)
/* 08F150 7F05A620 E7B60014 */  swc1  $f22, 0x14($sp)
/* 08F154 7F05A624 C7AE00A0 */  lwc1  $f14, 0xa0($sp)
/* 08F158 7F05A628 4600E306 */  mov.s $f12, $f28
/* 08F15C 7F05A62C E7A6001C */  swc1  $f6, 0x1c($sp)
/* 08F160 7F05A630 E7A40018 */  swc1  $f4, 0x18($sp)
/* 08F164 7F05A634 0FC16A4A */  jal   sub_GAME_7F05A928
/* 08F168 7F05A638 E7AA0010 */   swc1  $f10, 0x10($sp)
/* 08F16C 7F05A63C 46000207 */  neg.s $f8, $f0
/* 08F170 7F05A640 4600F306 */  mov.s $f12, $f30
/* 08F174 7F05A644 E6080038 */  swc1  $f8, 0x38($s0)
/* 08F178 7F05A648 C7AA0080 */  lwc1  $f10, 0x80($sp)
/* 08F17C 7F05A64C C7A80070 */  lwc1  $f8, 0x70($sp)
/* 08F180 7F05A650 C7A60074 */  lwc1  $f6, 0x74($sp)
/* 08F184 7F05A654 E7AA0010 */  swc1  $f10, 0x10($sp)
/* 08F188 7F05A658 C7AA006C */  lwc1  $f10, 0x6c($sp)
/* 08F18C 7F05A65C C7A4007C */  lwc1  $f4, 0x7c($sp)
/* 08F190 7F05A660 8FA70084 */  lw    $a3, 0x84($sp)
/* 08F194 7F05A664 8FA6008C */  lw    $a2, 0x8c($sp)
/* 08F198 7F05A668 C7AE0090 */  lwc1  $f14, 0x90($sp)
/* 08F19C 7F05A66C E7A8001C */  swc1  $f8, 0x1c($sp)
/* 08F1A0 7F05A670 E7A60018 */  swc1  $f6, 0x18($sp)
/* 08F1A4 7F05A674 E7AA0020 */  swc1  $f10, 0x20($sp)
/* 08F1A8 7F05A678 0FC16A4A */  jal   sub_GAME_7F05A928
/* 08F1AC 7F05A67C E7A40014 */   swc1  $f4, 0x14($sp)
/* 08F1B0 7F05A680 46000107 */  neg.s $f4, $f0
/* 08F1B4 7F05A684 4600E306 */  mov.s $f12, $f28
/* 08F1B8 7F05A688 E604000C */  swc1  $f4, 0xc($s0)
/* 08F1BC 7F05A68C C7A60080 */  lwc1  $f6, 0x80($sp)
/* 08F1C0 7F05A690 C7A40070 */  lwc1  $f4, 0x70($sp)
/* 08F1C4 7F05A694 C7AA0074 */  lwc1  $f10, 0x74($sp)
/* 08F1C8 7F05A698 E7A60010 */  swc1  $f6, 0x10($sp)
/* 08F1CC 7F05A69C C7A6006C */  lwc1  $f6, 0x6c($sp)
/* 08F1D0 7F05A6A0 C7A8007C */  lwc1  $f8, 0x7c($sp)
/* 08F1D4 7F05A6A4 8FA70084 */  lw    $a3, 0x84($sp)
/* 08F1D8 7F05A6A8 8FA6009C */  lw    $a2, 0x9c($sp)
/* 08F1DC 7F05A6AC C7AE00A0 */  lwc1  $f14, 0xa0($sp)
/* 08F1E0 7F05A6B0 E7A4001C */  swc1  $f4, 0x1c($sp)
/* 08F1E4 7F05A6B4 E7AA0018 */  swc1  $f10, 0x18($sp)
/* 08F1E8 7F05A6B8 E7A60020 */  swc1  $f6, 0x20($sp)
/* 08F1EC 7F05A6BC 0FC16A4A */  jal   sub_GAME_7F05A928
/* 08F1F0 7F05A6C0 E7A80014 */   swc1  $f8, 0x14($sp)
/* 08F1F4 7F05A6C4 E600001C */  swc1  $f0, 0x1c($s0)
/* 08F1F8 7F05A6C8 C7A80090 */  lwc1  $f8, 0x90($sp)
/* 08F1FC 7F05A6CC C7A60070 */  lwc1  $f6, 0x70($sp)
/* 08F200 7F05A6D0 C7A40074 */  lwc1  $f4, 0x74($sp)
/* 08F204 7F05A6D4 E7A80010 */  swc1  $f8, 0x10($sp)
/* 08F208 7F05A6D8 C7A8006C */  lwc1  $f8, 0x6c($sp)
/* 08F20C 7F05A6DC C7AA008C */  lwc1  $f10, 0x8c($sp)
/* 08F210 7F05A6E0 4407F000 */  mfc1  $a3, $f30
/* 08F214 7F05A6E4 8FA6009C */  lw    $a2, 0x9c($sp)
/* 08F218 7F05A6E8 C7AE00A0 */  lwc1  $f14, 0xa0($sp)
/* 08F21C 7F05A6EC 4600E306 */  mov.s $f12, $f28
/* 08F220 7F05A6F0 E7A6001C */  swc1  $f6, 0x1c($sp)
/* 08F224 7F05A6F4 E7A40018 */  swc1  $f4, 0x18($sp)
/* 08F228 7F05A6F8 E7A80020 */  swc1  $f8, 0x20($sp)
/* 08F22C 7F05A6FC 0FC16A4A */  jal   sub_GAME_7F05A928
/* 08F230 7F05A700 E7AA0014 */   swc1  $f10, 0x14($sp)
/* 08F234 7F05A704 46000287 */  neg.s $f10, $f0
/* 08F238 7F05A708 4407F000 */  mfc1  $a3, $f30
/* 08F23C 7F05A70C E60A002C */  swc1  $f10, 0x2c($s0)
/* 08F240 7F05A710 C7A40090 */  lwc1  $f4, 0x90($sp)
/* 08F244 7F05A714 C7AA0080 */  lwc1  $f10, 0x80($sp)
/* 08F248 7F05A718 C7A80084 */  lwc1  $f8, 0x84($sp)
/* 08F24C 7F05A71C E7A40010 */  swc1  $f4, 0x10($sp)
/* 08F250 7F05A720 C7A4007C */  lwc1  $f4, 0x7c($sp)
/* 08F254 7F05A724 C7A6008C */  lwc1  $f6, 0x8c($sp)
/* 08F258 7F05A728 8FA6009C */  lw    $a2, 0x9c($sp)
/* 08F25C 7F05A72C C7AE00A0 */  lwc1  $f14, 0xa0($sp)
/* 08F260 7F05A730 4600E306 */  mov.s $f12, $f28
/* 08F264 7F05A734 E7AA001C */  swc1  $f10, 0x1c($sp)
/* 08F268 7F05A738 E7A80018 */  swc1  $f8, 0x18($sp)
/* 08F26C 7F05A73C E7A40020 */  swc1  $f4, 0x20($sp)
/* 08F270 7F05A740 0FC16A4A */  jal   sub_GAME_7F05A928
/* 08F274 7F05A744 E7A60014 */   swc1  $f6, 0x14($sp)
/* 08F278 7F05A748 E600003C */  swc1  $f0, 0x3c($s0)
/* 08F27C 7F05A74C 8FBF0064 */  lw    $ra, 0x64($sp)
/* 08F280 7F05A750 8FB00060 */  lw    $s0, 0x60($sp)
/* 08F284 7F05A754 D7BE0058 */  ldc1  $f30, 0x58($sp)
/* 08F288 7F05A758 D7BC0050 */  ldc1  $f28, 0x50($sp)
/* 08F28C 7F05A75C D7BA0048 */  ldc1  $f26, 0x48($sp)
/* 08F290 7F05A760 D7B80040 */  ldc1  $f24, 0x40($sp)
/* 08F294 7F05A764 D7B60038 */  ldc1  $f22, 0x38($sp)
/* 08F298 7F05A768 D7B40030 */  ldc1  $f20, 0x30($sp)
/* 08F29C 7F05A76C 03E00008 */  jr    $ra
/* 08F2A0 7F05A770 27BD00A8 */   addiu $sp, $sp, 0xa8
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F05A774(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F05A774
/* 08F2A4 7F05A774 27BDFF80 */  addiu $sp, $sp, -0x80
/* 08F2A8 7F05A778 AFBF002C */  sw    $ra, 0x2c($sp)
/* 08F2AC 7F05A77C C4840000 */  lwc1  $f4, ($a0)
/* 08F2B0 7F05A780 E7A40078 */  swc1  $f4, 0x78($sp)
/* 08F2B4 7F05A784 C4860004 */  lwc1  $f6, 4($a0)
/* 08F2B8 7F05A788 E7A60068 */  swc1  $f6, 0x68($sp)
/* 08F2BC 7F05A78C C4880008 */  lwc1  $f8, 8($a0)
/* 08F2C0 7F05A790 E7A80058 */  swc1  $f8, 0x58($sp)
/* 08F2C4 7F05A794 C48A000C */  lwc1  $f10, 0xc($a0)
/* 08F2C8 7F05A798 E7AA0048 */  swc1  $f10, 0x48($sp)
/* 08F2CC 7F05A79C C4840018 */  lwc1  $f4, 0x18($a0)
/* 08F2D0 7F05A7A0 C4800014 */  lwc1  $f0, 0x14($a0)
/* 08F2D4 7F05A7A4 C48C0010 */  lwc1  $f12, 0x10($a0)
/* 08F2D8 7F05A7A8 E7A40054 */  swc1  $f4, 0x54($sp)
/* 08F2DC 7F05A7AC C4860028 */  lwc1  $f6, 0x28($a0)
/* 08F2E0 7F05A7B0 C482001C */  lwc1  $f2, 0x1c($a0)
/* 08F2E4 7F05A7B4 C4900024 */  lwc1  $f16, 0x24($a0)
/* 08F2E8 7F05A7B8 C48E0020 */  lwc1  $f14, 0x20($a0)
/* 08F2EC 7F05A7BC E7A60050 */  swc1  $f6, 0x50($sp)
/* 08F2F0 7F05A7C0 C4880030 */  lwc1  $f8, 0x30($a0)
/* 08F2F4 7F05A7C4 C492002C */  lwc1  $f18, 0x2c($a0)
/* 08F2F8 7F05A7C8 44070000 */  mfc1  $a3, $f0
/* 08F2FC 7F05A7CC E7A8006C */  swc1  $f8, 0x6c($sp)
/* 08F300 7F05A7D0 C48A0034 */  lwc1  $f10, 0x34($a0)
/* 08F304 7F05A7D4 8FA6006C */  lw    $a2, 0x6c($sp)
/* 08F308 7F05A7D8 E7AA005C */  swc1  $f10, 0x5c($sp)
/* 08F30C 7F05A7DC C4840038 */  lwc1  $f4, 0x38($a0)
/* 08F310 7F05A7E0 C7A8005C */  lwc1  $f8, 0x5c($sp)
/* 08F314 7F05A7E4 E7A4004C */  swc1  $f4, 0x4c($sp)
/* 08F318 7F05A7E8 C486003C */  lwc1  $f6, 0x3c($a0)
/* 08F31C 7F05A7EC E7A00064 */  swc1  $f0, 0x64($sp)
/* 08F320 7F05A7F0 E7AC0074 */  swc1  $f12, 0x74($sp)
/* 08F324 7F05A7F4 E7A6003C */  swc1  $f6, 0x3c($sp)
/* 08F328 7F05A7F8 C7AA003C */  lwc1  $f10, 0x3c($sp)
/* 08F32C 7F05A7FC E7A20044 */  swc1  $f2, 0x44($sp)
/* 08F330 7F05A800 E7A20018 */  swc1  $f2, 0x18($sp)
/* 08F334 7F05A804 E7B00060 */  swc1  $f16, 0x60($sp)
/* 08F338 7F05A808 E7B00010 */  swc1  $f16, 0x10($sp)
/* 08F33C 7F05A80C E7AE0070 */  swc1  $f14, 0x70($sp)
/* 08F340 7F05A810 E7B20040 */  swc1  $f18, 0x40($sp)
/* 08F344 7F05A814 E7B2001C */  swc1  $f18, 0x1c($sp)
/* 08F348 7F05A818 E7A80014 */  swc1  $f8, 0x14($sp)
/* 08F34C 7F05A81C 0FC16A4A */  jal   sub_GAME_7F05A928
/* 08F350 7F05A820 E7AA0020 */   swc1  $f10, 0x20($sp)
/* 08F354 7F05A824 C7A40050 */  lwc1  $f4, 0x50($sp)
/* 08F358 7F05A828 C7A6004C */  lwc1  $f6, 0x4c($sp)
/* 08F35C 7F05A82C C7A80044 */  lwc1  $f8, 0x44($sp)
/* 08F360 7F05A830 E7A40010 */  swc1  $f4, 0x10($sp)
/* 08F364 7F05A834 C7A4003C */  lwc1  $f4, 0x3c($sp)
/* 08F368 7F05A838 C7AA0040 */  lwc1  $f10, 0x40($sp)
/* 08F36C 7F05A83C E7A00030 */  swc1  $f0, 0x30($sp)
/* 08F370 7F05A840 C7AC0074 */  lwc1  $f12, 0x74($sp)
/* 08F374 7F05A844 C7AE0070 */  lwc1  $f14, 0x70($sp)
/* 08F378 7F05A848 8FA6006C */  lw    $a2, 0x6c($sp)
/* 08F37C 7F05A84C 8FA70054 */  lw    $a3, 0x54($sp)
/* 08F380 7F05A850 E7A60014 */  swc1  $f6, 0x14($sp)
/* 08F384 7F05A854 E7A80018 */  swc1  $f8, 0x18($sp)
/* 08F388 7F05A858 E7A40020 */  swc1  $f4, 0x20($sp)
/* 08F38C 7F05A85C 0FC16A4A */  jal   sub_GAME_7F05A928
/* 08F390 7F05A860 E7AA001C */   swc1  $f10, 0x1c($sp)
/* 08F394 7F05A864 C7A60050 */  lwc1  $f6, 0x50($sp)
/* 08F398 7F05A868 C7A8004C */  lwc1  $f8, 0x4c($sp)
/* 08F39C 7F05A86C C7AA0044 */  lwc1  $f10, 0x44($sp)
/* 08F3A0 7F05A870 E7A60010 */  swc1  $f6, 0x10($sp)
/* 08F3A4 7F05A874 C7A6003C */  lwc1  $f6, 0x3c($sp)
/* 08F3A8 7F05A878 C7A40040 */  lwc1  $f4, 0x40($sp)
/* 08F3AC 7F05A87C E7A00034 */  swc1  $f0, 0x34($sp)
/* 08F3B0 7F05A880 C7AC0064 */  lwc1  $f12, 0x64($sp)
/* 08F3B4 7F05A884 C7AE0060 */  lwc1  $f14, 0x60($sp)
/* 08F3B8 7F05A888 8FA6005C */  lw    $a2, 0x5c($sp)
/* 08F3BC 7F05A88C 8FA70054 */  lw    $a3, 0x54($sp)
/* 08F3C0 7F05A890 E7A80014 */  swc1  $f8, 0x14($sp)
/* 08F3C4 7F05A894 E7AA0018 */  swc1  $f10, 0x18($sp)
/* 08F3C8 7F05A898 E7A60020 */  swc1  $f6, 0x20($sp)
/* 08F3CC 7F05A89C 0FC16A4A */  jal   sub_GAME_7F05A928
/* 08F3D0 7F05A8A0 E7A4001C */   swc1  $f4, 0x1c($sp)
/* 08F3D4 7F05A8A4 C7A80060 */  lwc1  $f8, 0x60($sp)
/* 08F3D8 7F05A8A8 C7AA005C */  lwc1  $f10, 0x5c($sp)
/* 08F3DC 7F05A8AC C7A40054 */  lwc1  $f4, 0x54($sp)
/* 08F3E0 7F05A8B0 E7A80010 */  swc1  $f8, 0x10($sp)
/* 08F3E4 7F05A8B4 C7A8004C */  lwc1  $f8, 0x4c($sp)
/* 08F3E8 7F05A8B8 C7A60050 */  lwc1  $f6, 0x50($sp)
/* 08F3EC 7F05A8BC E7A00038 */  swc1  $f0, 0x38($sp)
/* 08F3F0 7F05A8C0 C7AC0074 */  lwc1  $f12, 0x74($sp)
/* 08F3F4 7F05A8C4 C7AE0070 */  lwc1  $f14, 0x70($sp)
/* 08F3F8 7F05A8C8 8FA6006C */  lw    $a2, 0x6c($sp)
/* 08F3FC 7F05A8CC 8FA70064 */  lw    $a3, 0x64($sp)
/* 08F400 7F05A8D0 E7AA0014 */  swc1  $f10, 0x14($sp)
/* 08F404 7F05A8D4 E7A40018 */  swc1  $f4, 0x18($sp)
/* 08F408 7F05A8D8 E7A80020 */  swc1  $f8, 0x20($sp)
/* 08F40C 7F05A8DC 0FC16A4A */  jal   sub_GAME_7F05A928
/* 08F410 7F05A8E0 E7A6001C */   swc1  $f6, 0x1c($sp)
/* 08F414 7F05A8E4 C7AA0078 */  lwc1  $f10, 0x78($sp)
/* 08F418 7F05A8E8 C7A40038 */  lwc1  $f4, 0x38($sp)
/* 08F41C 7F05A8EC C7A80068 */  lwc1  $f8, 0x68($sp)
/* 08F420 7F05A8F0 8FBF002C */  lw    $ra, 0x2c($sp)
/* 08F424 7F05A8F4 46045182 */  mul.s $f6, $f10, $f4
/* 08F428 7F05A8F8 C7AA0034 */  lwc1  $f10, 0x34($sp)
/* 08F42C 7F05A8FC 460A4102 */  mul.s $f4, $f8, $f10
/* 08F430 7F05A900 C7AA0058 */  lwc1  $f10, 0x58($sp)
/* 08F434 7F05A904 46043201 */  sub.s $f8, $f6, $f4
/* 08F438 7F05A908 C7A60030 */  lwc1  $f6, 0x30($sp)
/* 08F43C 7F05A90C 46065102 */  mul.s $f4, $f10, $f6
/* 08F440 7F05A910 C7A60048 */  lwc1  $f6, 0x48($sp)
/* 08F444 7F05A914 27BD0080 */  addiu $sp, $sp, 0x80
/* 08F448 7F05A918 46044280 */  add.s $f10, $f8, $f4
/* 08F44C 7F05A91C 46060202 */  mul.s $f8, $f0, $f6
/* 08F450 7F05A920 03E00008 */  jr    $ra
/* 08F454 7F05A924 46085001 */   sub.s $f0, $f10, $f8
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F05A928(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F05A928
/* 08F458 7F05A928 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 08F45C 7F05A92C AFBF0014 */  sw    $ra, 0x14($sp)
/* 08F460 7F05A930 E7AC0028 */  swc1  $f12, 0x28($sp)
/* 08F464 7F05A934 E7AE002C */  swc1  $f14, 0x2c($sp)
/* 08F468 7F05A938 AFA60030 */  sw    $a2, 0x30($sp)
/* 08F46C 7F05A93C AFA70034 */  sw    $a3, 0x34($sp)
/* 08F470 7F05A940 8FA70048 */  lw    $a3, 0x48($sp)
/* 08F474 7F05A944 C7AE0030 */  lwc1  $f14, 0x30($sp)
/* 08F478 7F05A948 8FA60044 */  lw    $a2, 0x44($sp)
/* 08F47C 7F05A94C 0FC16A6E */  jal   sub_GAME_7F05A9B8
/* 08F480 7F05A950 C7AC002C */   lwc1  $f12, 0x2c($sp)
/* 08F484 7F05A954 E7A0001C */  swc1  $f0, 0x1c($sp)
/* 08F488 7F05A958 C7AC0038 */  lwc1  $f12, 0x38($sp)
/* 08F48C 7F05A95C C7AE003C */  lwc1  $f14, 0x3c($sp)
/* 08F490 7F05A960 8FA60044 */  lw    $a2, 0x44($sp)
/* 08F494 7F05A964 0FC16A6E */  jal   sub_GAME_7F05A9B8
/* 08F498 7F05A968 8FA70048 */   lw    $a3, 0x48($sp)
/* 08F49C 7F05A96C E7A00020 */  swc1  $f0, 0x20($sp)
/* 08F4A0 7F05A970 C7AC002C */  lwc1  $f12, 0x2c($sp)
/* 08F4A4 7F05A974 C7AE0030 */  lwc1  $f14, 0x30($sp)
/* 08F4A8 7F05A978 8FA60038 */  lw    $a2, 0x38($sp)
/* 08F4AC 7F05A97C 0FC16A6E */  jal   sub_GAME_7F05A9B8
/* 08F4B0 7F05A980 8FA7003C */   lw    $a3, 0x3c($sp)
/* 08F4B4 7F05A984 C7A40028 */  lwc1  $f4, 0x28($sp)
/* 08F4B8 7F05A988 C7A60020 */  lwc1  $f6, 0x20($sp)
/* 08F4BC 7F05A98C C7AA0034 */  lwc1  $f10, 0x34($sp)
/* 08F4C0 7F05A990 C7B0001C */  lwc1  $f16, 0x1c($sp)
/* 08F4C4 7F05A994 46062202 */  mul.s $f8, $f4, $f6
/* 08F4C8 7F05A998 C7A60040 */  lwc1  $f6, 0x40($sp)
/* 08F4CC 7F05A99C 8FBF0014 */  lw    $ra, 0x14($sp)
/* 08F4D0 7F05A9A0 46105482 */  mul.s $f18, $f10, $f16
/* 08F4D4 7F05A9A4 27BD0028 */  addiu $sp, $sp, 0x28
/* 08F4D8 7F05A9A8 46060282 */  mul.s $f10, $f0, $f6
/* 08F4DC 7F05A9AC 46124101 */  sub.s $f4, $f8, $f18
/* 08F4E0 7F05A9B0 03E00008 */  jr    $ra
/* 08F4E4 7F05A9B4 46045000 */   add.s $f0, $f10, $f4
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F05A9B8(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F05A9B8
/* 08F4E8 7F05A9B8 AFA7000C */  sw    $a3, 0xc($sp)
/* 08F4EC 7F05A9BC C7A4000C */  lwc1  $f4, 0xc($sp)
/* 08F4F0 7F05A9C0 AFA60008 */  sw    $a2, 8($sp)
/* 08F4F4 7F05A9C4 C7A80008 */  lwc1  $f8, 8($sp)
/* 08F4F8 7F05A9C8 46046182 */  mul.s $f6, $f12, $f4
/* 08F4FC 7F05A9CC 00000000 */  nop   
/* 08F500 7F05A9D0 46087282 */  mul.s $f10, $f14, $f8
/* 08F504 7F05A9D4 03E00008 */  jr    $ra
/* 08F508 7F05A9D8 460A3001 */   sub.s $f0, $f6, $f10
)
#endif
 

