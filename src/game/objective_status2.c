#include <ultra64.h>

//D:80032300
u32 D_80032300 = 0;
//D:80032304
u32 D_80032304 = 0;
//D:80032308
u32 D_80032308 = 0;

#ifdef NONMATCHING
void sub_GAME_7F057AC0(float *param_1)
{
    float firstrandfinal;
    float secondrandfinal;
    float thirdrandfinal;
    
    firstrandfinal = D_80032300;
    secondrandfinal = D_80032304;
    thirdrandfinal = D_80032308;
    firstrandfinal = randomGetNext() * 0.00000000 * 6.28318548 * 0.03125000 - 0.09817477;
    secondrandfinal = randomGetNext() * 0.00000000 * 6.28318548 * 0.03125000 - 0.09817477;
    thirdrandfinal = randomGetNext() * 0.00000000 * 6.28318548 * 0.03125000 - 0.09817477;
    matrix_4x4_set_rotation_around_xyz(&firstrandfinal,param_1);
    return;
}
#else

#if defined(LEFTOVERDEBUG)

GLOBAL_ASM(
.late_rodata
glabel D_80053690
.word 0x40c90fdb /*6.2831855*/
glabel D_80053694
.word 0x3dc90fdb /*0.098174773*/
glabel D_80053698
.word 0x40c90fdb /*6.2831855*/
glabel D_8005369C
.word 0x3dc90fdb /*0.098174773*/
glabel D_800536A0
.word 0x40c90fdb /*6.2831855*/
glabel D_800536A4
.word 0x3dc90fdb /*0.098174773*/
.text
glabel sub_GAME_7F057AC0
/* 08C5F0 7F057AC0 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 08C5F4 7F057AC4 3C0F8003 */  lui   $t7, %hi(D_80032300) 
/* 08C5F8 7F057AC8 AFBF0014 */  sw    $ra, 0x14($sp)
/* 08C5FC 7F057ACC AFA40028 */  sw    $a0, 0x28($sp)
/* 08C600 7F057AD0 25EF2300 */  addiu $t7, %lo(D_80032300) # addiu $t7, $t7, 0x2300
/* 08C604 7F057AD4 8DE10000 */  lw    $at, ($t7)
/* 08C608 7F057AD8 27AE001C */  addiu $t6, $sp, 0x1c
/* 08C60C 7F057ADC 8DE80004 */  lw    $t0, 4($t7)
/* 08C610 7F057AE0 ADC10000 */  sw    $at, ($t6)
/* 08C614 7F057AE4 8DE10008 */  lw    $at, 8($t7)
/* 08C618 7F057AE8 ADC80004 */  sw    $t0, 4($t6)
/* 08C61C 7F057AEC 0C002914 */  jal   randomGetNext
/* 08C620 7F057AF0 ADC10008 */   sw    $at, 8($t6)
/* 08C624 7F057AF4 44822000 */  mtc1  $v0, $f4
/* 08C628 7F057AF8 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 08C62C 7F057AFC 04410004 */  bgez  $v0, .L7F057B10
/* 08C630 7F057B00 468021A0 */   cvt.s.w $f6, $f4
/* 08C634 7F057B04 44814000 */  mtc1  $at, $f8
/* 08C638 7F057B08 00000000 */  nop   
/* 08C63C 7F057B0C 46083180 */  add.s $f6, $f6, $f8
.L7F057B10:
/* 08C640 7F057B10 3C012F80 */  li    $at, 0x2F800000 # 0.000000
/* 08C644 7F057B14 44815000 */  mtc1  $at, $f10
/* 08C648 7F057B18 3C018005 */  lui   $at, %hi(D_80053690)
/* 08C64C 7F057B1C C4323690 */  lwc1  $f18, %lo(D_80053690)($at)
/* 08C650 7F057B20 460A3402 */  mul.s $f16, $f6, $f10
/* 08C654 7F057B24 3C013D00 */  li    $at, 0x3D000000 # 0.031250
/* 08C658 7F057B28 44814000 */  mtc1  $at, $f8
/* 08C65C 7F057B2C 3C018005 */  lui   $at, %hi(D_80053694)
/* 08C660 7F057B30 C42A3694 */  lwc1  $f10, %lo(D_80053694)($at)
/* 08C664 7F057B34 46128102 */  mul.s $f4, $f16, $f18
/* 08C668 7F057B38 00000000 */  nop   
/* 08C66C 7F057B3C 46082182 */  mul.s $f6, $f4, $f8
/* 08C670 7F057B40 460A3401 */  sub.s $f16, $f6, $f10
/* 08C674 7F057B44 0C002914 */  jal   randomGetNext
/* 08C678 7F057B48 E7B0001C */   swc1  $f16, 0x1c($sp)
/* 08C67C 7F057B4C 44829000 */  mtc1  $v0, $f18
/* 08C680 7F057B50 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 08C684 7F057B54 04410004 */  bgez  $v0, .L7F057B68
/* 08C688 7F057B58 46809120 */   cvt.s.w $f4, $f18
/* 08C68C 7F057B5C 44814000 */  mtc1  $at, $f8
/* 08C690 7F057B60 00000000 */  nop   
/* 08C694 7F057B64 46082100 */  add.s $f4, $f4, $f8
.L7F057B68:
/* 08C698 7F057B68 3C012F80 */  li    $at, 0x2F800000 # 0.000000
/* 08C69C 7F057B6C 44813000 */  mtc1  $at, $f6
/* 08C6A0 7F057B70 3C018005 */  lui   $at, %hi(D_80053698)
/* 08C6A4 7F057B74 C4303698 */  lwc1  $f16, %lo(D_80053698)($at)
/* 08C6A8 7F057B78 46062282 */  mul.s $f10, $f4, $f6
/* 08C6AC 7F057B7C 3C013D00 */  li    $at, 0x3D000000 # 0.031250
/* 08C6B0 7F057B80 44814000 */  mtc1  $at, $f8
/* 08C6B4 7F057B84 3C018005 */  lui   $at, %hi(D_8005369C)
/* 08C6B8 7F057B88 C426369C */  lwc1  $f6, %lo(D_8005369C)($at)
/* 08C6BC 7F057B8C 46105482 */  mul.s $f18, $f10, $f16
/* 08C6C0 7F057B90 00000000 */  nop   
/* 08C6C4 7F057B94 46089102 */  mul.s $f4, $f18, $f8
/* 08C6C8 7F057B98 46062281 */  sub.s $f10, $f4, $f6
/* 08C6CC 7F057B9C 0C002914 */  jal   randomGetNext
/* 08C6D0 7F057BA0 E7AA0020 */   swc1  $f10, 0x20($sp)
/* 08C6D4 7F057BA4 44828000 */  mtc1  $v0, $f16
/* 08C6D8 7F057BA8 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 08C6DC 7F057BAC 04410004 */  bgez  $v0, .L7F057BC0
/* 08C6E0 7F057BB0 468084A0 */   cvt.s.w $f18, $f16
/* 08C6E4 7F057BB4 44814000 */  mtc1  $at, $f8
/* 08C6E8 7F057BB8 00000000 */  nop   
/* 08C6EC 7F057BBC 46089480 */  add.s $f18, $f18, $f8
.L7F057BC0:
/* 08C6F0 7F057BC0 3C012F80 */  li    $at, 0x2F800000 # 0.000000
/* 08C6F4 7F057BC4 44812000 */  mtc1  $at, $f4
/* 08C6F8 7F057BC8 3C018005 */  lui   $at, %hi(D_800536A0)
/* 08C6FC 7F057BCC C42A36A0 */  lwc1  $f10, %lo(D_800536A0)($at)
/* 08C700 7F057BD0 46049182 */  mul.s $f6, $f18, $f4
/* 08C704 7F057BD4 3C013D00 */  li    $at, 0x3D000000 # 0.031250
/* 08C708 7F057BD8 44814000 */  mtc1  $at, $f8
/* 08C70C 7F057BDC 3C018005 */  lui   $at, %hi(D_800536A4)
/* 08C710 7F057BE0 C42436A4 */  lwc1  $f4, %lo(D_800536A4)($at)
/* 08C714 7F057BE4 27A4001C */  addiu $a0, $sp, 0x1c
/* 08C718 7F057BE8 8FA50028 */  lw    $a1, 0x28($sp)
/* 08C71C 7F057BEC 460A3402 */  mul.s $f16, $f6, $f10
/* 08C720 7F057BF0 00000000 */  nop   
/* 08C724 7F057BF4 46088482 */  mul.s $f18, $f16, $f8
/* 08C728 7F057BF8 46049181 */  sub.s $f6, $f18, $f4
/* 08C72C 7F057BFC 0FC161C5 */  jal   matrix_4x4_set_rotation_around_xyz
/* 08C730 7F057C00 E7A60024 */   swc1  $f6, 0x24($sp)
/* 08C734 7F057C04 8FBF0014 */  lw    $ra, 0x14($sp)
/* 08C738 7F057C08 27BD0028 */  addiu $sp, $sp, 0x28
/* 08C73C 7F057C0C 03E00008 */  jr    $ra
/* 08C740 7F057C10 00000000 */   nop   
)
#endif

#if !defined(LEFTOVERDEBUG)

/* same asm, different float .rodata */

GLOBAL_ASM(
.late_rodata
glabel D_80053690
.word 0x40f1463a /* 6.2831855 * 1.2 = 7.53982257843 */
glabel D_80053694
.word 0x3df1463a /* 0.117809727788 */
glabel D_80053698
.word 0x40f1463a /* 6.2831855 * 1.2 = 7.53982257843 */
glabel D_8005369C
.word 0x3df1463a /* 0.117809727788 */
glabel D_800536A0
.word 0x40f1463a /* 6.2831855 * 1.2 = 7.53982257843 */
glabel D_800536A4
.word 0x3df1463a /* 0.117809727788 */
.text
glabel sub_GAME_7F057AC0
/* 08C5F0 7F057AC0 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 08C5F4 7F057AC4 3C0F8003 */  lui   $t7, %hi(D_80032300) 
/* 08C5F8 7F057AC8 AFBF0014 */  sw    $ra, 0x14($sp)
/* 08C5FC 7F057ACC AFA40028 */  sw    $a0, 0x28($sp)
/* 08C600 7F057AD0 25EF2300 */  addiu $t7, %lo(D_80032300) # addiu $t7, $t7, 0x2300
/* 08C604 7F057AD4 8DE10000 */  lw    $at, ($t7)
/* 08C608 7F057AD8 27AE001C */  addiu $t6, $sp, 0x1c
/* 08C60C 7F057ADC 8DE80004 */  lw    $t0, 4($t7)
/* 08C610 7F057AE0 ADC10000 */  sw    $at, ($t6)
/* 08C614 7F057AE4 8DE10008 */  lw    $at, 8($t7)
/* 08C618 7F057AE8 ADC80004 */  sw    $t0, 4($t6)
/* 08C61C 7F057AEC 0C002914 */  jal   randomGetNext
/* 08C620 7F057AF0 ADC10008 */   sw    $at, 8($t6)
/* 08C624 7F057AF4 44822000 */  mtc1  $v0, $f4
/* 08C628 7F057AF8 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 08C62C 7F057AFC 04410004 */  bgez  $v0, .L7F057B10
/* 08C630 7F057B00 468021A0 */   cvt.s.w $f6, $f4
/* 08C634 7F057B04 44814000 */  mtc1  $at, $f8
/* 08C638 7F057B08 00000000 */  nop   
/* 08C63C 7F057B0C 46083180 */  add.s $f6, $f6, $f8
.L7F057B10:
/* 08C640 7F057B10 3C012F80 */  li    $at, 0x2F800000 # 0.000000
/* 08C644 7F057B14 44815000 */  mtc1  $at, $f10
/* 08C648 7F057B18 3C018005 */  lui   $at, %hi(D_80053690)
/* 08C64C 7F057B1C C4323690 */  lwc1  $f18, %lo(D_80053690)($at)
/* 08C650 7F057B20 460A3402 */  mul.s $f16, $f6, $f10
/* 08C654 7F057B24 3C013D00 */  li    $at, 0x3D000000 # 0.031250
/* 08C658 7F057B28 44814000 */  mtc1  $at, $f8
/* 08C65C 7F057B2C 3C018005 */  lui   $at, %hi(D_80053694)
/* 08C660 7F057B30 C42A3694 */  lwc1  $f10, %lo(D_80053694)($at)
/* 08C664 7F057B34 46128102 */  mul.s $f4, $f16, $f18
/* 08C668 7F057B38 00000000 */  nop   
/* 08C66C 7F057B3C 46082182 */  mul.s $f6, $f4, $f8
/* 08C670 7F057B40 460A3401 */  sub.s $f16, $f6, $f10
/* 08C674 7F057B44 0C002914 */  jal   randomGetNext
/* 08C678 7F057B48 E7B0001C */   swc1  $f16, 0x1c($sp)
/* 08C67C 7F057B4C 44829000 */  mtc1  $v0, $f18
/* 08C680 7F057B50 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 08C684 7F057B54 04410004 */  bgez  $v0, .L7F057B68
/* 08C688 7F057B58 46809120 */   cvt.s.w $f4, $f18
/* 08C68C 7F057B5C 44814000 */  mtc1  $at, $f8
/* 08C690 7F057B60 00000000 */  nop   
/* 08C694 7F057B64 46082100 */  add.s $f4, $f4, $f8
.L7F057B68:
/* 08C698 7F057B68 3C012F80 */  li    $at, 0x2F800000 # 0.000000
/* 08C69C 7F057B6C 44813000 */  mtc1  $at, $f6
/* 08C6A0 7F057B70 3C018005 */  lui   $at, %hi(D_80053698)
/* 08C6A4 7F057B74 C4303698 */  lwc1  $f16, %lo(D_80053698)($at)
/* 08C6A8 7F057B78 46062282 */  mul.s $f10, $f4, $f6
/* 08C6AC 7F057B7C 3C013D00 */  li    $at, 0x3D000000 # 0.031250
/* 08C6B0 7F057B80 44814000 */  mtc1  $at, $f8
/* 08C6B4 7F057B84 3C018005 */  lui   $at, %hi(D_8005369C)
/* 08C6B8 7F057B88 C426369C */  lwc1  $f6, %lo(D_8005369C)($at)
/* 08C6BC 7F057B8C 46105482 */  mul.s $f18, $f10, $f16
/* 08C6C0 7F057B90 00000000 */  nop   
/* 08C6C4 7F057B94 46089102 */  mul.s $f4, $f18, $f8
/* 08C6C8 7F057B98 46062281 */  sub.s $f10, $f4, $f6
/* 08C6CC 7F057B9C 0C002914 */  jal   randomGetNext
/* 08C6D0 7F057BA0 E7AA0020 */   swc1  $f10, 0x20($sp)
/* 08C6D4 7F057BA4 44828000 */  mtc1  $v0, $f16
/* 08C6D8 7F057BA8 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 08C6DC 7F057BAC 04410004 */  bgez  $v0, .L7F057BC0
/* 08C6E0 7F057BB0 468084A0 */   cvt.s.w $f18, $f16
/* 08C6E4 7F057BB4 44814000 */  mtc1  $at, $f8
/* 08C6E8 7F057BB8 00000000 */  nop   
/* 08C6EC 7F057BBC 46089480 */  add.s $f18, $f18, $f8
.L7F057BC0:
/* 08C6F0 7F057BC0 3C012F80 */  li    $at, 0x2F800000 # 0.000000
/* 08C6F4 7F057BC4 44812000 */  mtc1  $at, $f4
/* 08C6F8 7F057BC8 3C018005 */  lui   $at, %hi(D_800536A0)
/* 08C6FC 7F057BCC C42A36A0 */  lwc1  $f10, %lo(D_800536A0)($at)
/* 08C700 7F057BD0 46049182 */  mul.s $f6, $f18, $f4
/* 08C704 7F057BD4 3C013D00 */  li    $at, 0x3D000000 # 0.031250
/* 08C708 7F057BD8 44814000 */  mtc1  $at, $f8
/* 08C70C 7F057BDC 3C018005 */  lui   $at, %hi(D_800536A4)
/* 08C710 7F057BE0 C42436A4 */  lwc1  $f4, %lo(D_800536A4)($at)
/* 08C714 7F057BE4 27A4001C */  addiu $a0, $sp, 0x1c
/* 08C718 7F057BE8 8FA50028 */  lw    $a1, 0x28($sp)
/* 08C71C 7F057BEC 460A3402 */  mul.s $f16, $f6, $f10
/* 08C720 7F057BF0 00000000 */  nop   
/* 08C724 7F057BF4 46088482 */  mul.s $f18, $f16, $f8
/* 08C728 7F057BF8 46049181 */  sub.s $f6, $f18, $f4
/* 08C72C 7F057BFC 0FC161C5 */  jal   matrix_4x4_set_rotation_around_xyz
/* 08C730 7F057C00 E7A60024 */   swc1  $f6, 0x24($sp)
/* 08C734 7F057C04 8FBF0014 */  lw    $ra, 0x14($sp)
/* 08C738 7F057C08 27BD0028 */  addiu $sp, $sp, 0x28
/* 08C73C 7F057C0C 03E00008 */  jr    $ra
/* 08C740 7F057C10 00000000 */   nop   
)
#endif

#endif





#ifdef NONMATCHING
void sub_GAME_7F057C14(void) {

}
#else
GLOBAL_ASM(
.late_rodata
glabel D_800536A8
.word 0x3fd55555 /*1.6666666*/
glabel D_800536AC
.word 0x40555555 /*3.3333333*/
glabel D_800536B0
.word 0x3fd55555 /*1.6666666*/
glabel D_800536B4
.word 0x3fd55555 /*1.6666666*/
glabel D_800536B8
.word 0x40555555 /*3.3333333*/
.text
glabel sub_GAME_7F057C14
/* 08C744 7F057C14 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 08C748 7F057C18 AFBF0014 */  sw    $ra, 0x14($sp)
/* 08C74C 7F057C1C AFA40018 */  sw    $a0, 0x18($sp)
/* 08C750 7F057C20 0C002914 */  jal   randomGetNext
/* 08C754 7F057C24 AFA5001C */   sw    $a1, 0x1c($sp)
/* 08C758 7F057C28 44822000 */  mtc1  $v0, $f4
/* 08C75C 7F057C2C 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 08C760 7F057C30 04410004 */  bgez  $v0, .L7F057C44
/* 08C764 7F057C34 468021A0 */   cvt.s.w $f6, $f4
/* 08C768 7F057C38 44814000 */  mtc1  $at, $f8
/* 08C76C 7F057C3C 00000000 */  nop   
/* 08C770 7F057C40 46083180 */  add.s $f6, $f6, $f8
.L7F057C44:
/* 08C774 7F057C44 3C012F80 */  li    $at, 0x2F800000 # 0.000000
/* 08C778 7F057C48 44815000 */  mtc1  $at, $f10
/* 08C77C 7F057C4C 3C018005 */  lui   $at, %hi(D_800536A8)
/* 08C780 7F057C50 C43236A8 */  lwc1  $f18, %lo(D_800536A8)($at)
/* 08C784 7F057C54 460A3402 */  mul.s $f16, $f6, $f10
/* 08C788 7F057C58 3C014080 */  li    $at, 0x40800000 # 4.000000
/* 08C78C 7F057C5C 44814000 */  mtc1  $at, $f8
/* 08C790 7F057C60 3C018005 */  lui   $at, %hi(D_800536AC)
/* 08C794 7F057C64 C42A36AC */  lwc1  $f10, %lo(D_800536AC)($at)
/* 08C798 7F057C68 8FAE0018 */  lw    $t6, 0x18($sp)
/* 08C79C 7F057C6C 46128102 */  mul.s $f4, $f16, $f18
/* 08C7A0 7F057C70 00000000 */  nop   
/* 08C7A4 7F057C74 46082182 */  mul.s $f6, $f4, $f8
/* 08C7A8 7F057C78 460A3401 */  sub.s $f16, $f6, $f10
/* 08C7AC 7F057C7C 0C002914 */  jal   randomGetNext
/* 08C7B0 7F057C80 E5D00000 */   swc1  $f16, ($t6)
/* 08C7B4 7F057C84 44829000 */  mtc1  $v0, $f18
/* 08C7B8 7F057C88 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 08C7BC 7F057C8C 04410004 */  bgez  $v0, .L7F057CA0
/* 08C7C0 7F057C90 46809120 */   cvt.s.w $f4, $f18
/* 08C7C4 7F057C94 44814000 */  mtc1  $at, $f8
/* 08C7C8 7F057C98 00000000 */  nop   
/* 08C7CC 7F057C9C 46082100 */  add.s $f4, $f4, $f8
.L7F057CA0:
/* 08C7D0 7F057CA0 3C012F80 */  li    $at, 0x2F800000 # 0.000000
/* 08C7D4 7F057CA4 44813000 */  mtc1  $at, $f6
/* 08C7D8 7F057CA8 3C018005 */  lui   $at, %hi(D_800536B0)
/* 08C7DC 7F057CAC C43036B0 */  lwc1  $f16, %lo(D_800536B0)($at)
/* 08C7E0 7F057CB0 46062282 */  mul.s $f10, $f4, $f6
/* 08C7E4 7F057CB4 3C014080 */  li    $at, 0x40800000 # 4.000000
/* 08C7E8 7F057CB8 44814000 */  mtc1  $at, $f8
/* 08C7EC 7F057CBC 8FAF0018 */  lw    $t7, 0x18($sp)
/* 08C7F0 7F057CC0 46105482 */  mul.s $f18, $f10, $f16
/* 08C7F4 7F057CC4 00000000 */  nop   
/* 08C7F8 7F057CC8 46089102 */  mul.s $f4, $f18, $f8
/* 08C7FC 7F057CCC 0C002914 */  jal   randomGetNext
/* 08C800 7F057CD0 E5E40004 */   swc1  $f4, 4($t7)
/* 08C804 7F057CD4 44823000 */  mtc1  $v0, $f6
/* 08C808 7F057CD8 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 08C80C 7F057CDC 04410004 */  bgez  $v0, .L7F057CF0
/* 08C810 7F057CE0 468032A0 */   cvt.s.w $f10, $f6
/* 08C814 7F057CE4 44818000 */  mtc1  $at, $f16
/* 08C818 7F057CE8 00000000 */  nop   
/* 08C81C 7F057CEC 46105280 */  add.s $f10, $f10, $f16
.L7F057CF0:
/* 08C820 7F057CF0 3C012F80 */  li    $at, 0x2F800000 # 0.000000
/* 08C824 7F057CF4 44819000 */  mtc1  $at, $f18
/* 08C828 7F057CF8 3C018005 */  lui   $at, %hi(D_800536B4)
/* 08C82C 7F057CFC C42436B4 */  lwc1  $f4, %lo(D_800536B4)($at)
/* 08C830 7F057D00 46125202 */  mul.s $f8, $f10, $f18
/* 08C834 7F057D04 3C014080 */  li    $at, 0x40800000 # 4.000000
/* 08C838 7F057D08 44818000 */  mtc1  $at, $f16
/* 08C83C 7F057D0C 3C018005 */  lui   $at, %hi(D_800536B8)
/* 08C840 7F057D10 C43236B8 */  lwc1  $f18, %lo(D_800536B8)($at)
/* 08C844 7F057D14 8FB80018 */  lw    $t8, 0x18($sp)
/* 08C848 7F057D18 46044182 */  mul.s $f6, $f8, $f4
/* 08C84C 7F057D1C 00000000 */  nop   
/* 08C850 7F057D20 46103282 */  mul.s $f10, $f6, $f16
/* 08C854 7F057D24 46125201 */  sub.s $f8, $f10, $f18
/* 08C858 7F057D28 E7080008 */  swc1  $f8, 8($t8)
/* 08C85C 7F057D2C 0FC15EB0 */  jal   sub_GAME_7F057AC0
/* 08C860 7F057D30 8FA4001C */   lw    $a0, 0x1c($sp)
/* 08C864 7F057D34 8FBF0014 */  lw    $ra, 0x14($sp)
/* 08C868 7F057D38 27BD0018 */  addiu $sp, $sp, 0x18
/* 08C86C 7F057D3C 03E00008 */  jr    $ra
/* 08C870 7F057D40 00000000 */   nop   
)
#endif



void sub_GAME_7F057D44(f32* arg0, f32* arg1, f32 arg2)
{
    f32 temp_f0;
    f32 temp_f2;
    temp_f0 = *arg1;
    temp_f2 = temp_f0;
    temp_f0 = temp_f2 - (arg2 * 0.2777778f);
    *arg0 += (arg2 * (temp_f2 + temp_f0)) * 0.5f;
    *arg1 = temp_f0;
}


void sub_GAME_7F057D88(f32* arg0, f32* arg1, f32 arg2)
{
    sub_GAME_7F057D44(arg0 + 1, arg1 + 1, arg2);
    arg0[0] += (arg2 * arg1[0]);
    arg0[2] += (arg2 * arg1[2]);
}


void sub_GAME_7F057DF8(struct Mtxf *arg0, struct Mtxf *arg1, s32 count)
{
    s32 i;

    for (i = 0; i < count; i++) {
        matrix_4x4_multiply_homogeneous_in_place(arg1, arg0);
    }
}


void sub_GAME_7F057E58(f32* arg0, f32* arg1, struct Mtxf* arg2, struct Mtxf* arg3, s32 arg4)
{
    sub_GAME_7F057D88(arg0, arg1, (f32) arg4);
    sub_GAME_7F057DF8(arg2, arg3, arg4);
}