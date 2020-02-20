# assembler directives
.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches
.set gp=64

.include "macros.inc"


.section .text, "ax" 

glabel alUnlink
/* 00F690 7000EA90 8C820000 */  lw    $v0, ($a0)
/* 00F694 7000EA94 50400004 */  beql  $v0, $zero, .L7000EAA8
/* 00F698 7000EA98 8C820004 */   lw    $v0, 4($a0)
/* 00F69C 7000EA9C 8C8E0004 */  lw    $t6, 4($a0)
/* 00F6A0 7000EAA0 AC4E0004 */  sw    $t6, 4($v0)
/* 00F6A4 7000EAA4 8C820004 */  lw    $v0, 4($a0)
.L7000EAA8:
/* 00F6A8 7000EAA8 10400003 */  beqz  $v0, .L7000EAB8
/* 00F6AC 7000EAAC 00000000 */   nop   
/* 00F6B0 7000EAB0 8C8F0000 */  lw    $t7, ($a0)
/* 00F6B4 7000EAB4 AC4F0000 */  sw    $t7, ($v0)
.L7000EAB8:
/* 00F6B8 7000EAB8 03E00008 */  jr    $ra
/* 00F6BC 7000EABC 00000000 */   nop   

glabel alLink
/* 00F6C0 7000EAC0 8CAE0000 */  lw    $t6, ($a1)
/* 00F6C4 7000EAC4 AC850004 */  sw    $a1, 4($a0)
/* 00F6C8 7000EAC8 AC8E0000 */  sw    $t6, ($a0)
/* 00F6CC 7000EACC 8CA20000 */  lw    $v0, ($a1)
/* 00F6D0 7000EAD0 10400002 */  beqz  $v0, .L7000EADC
/* 00F6D4 7000EAD4 00000000 */   nop   
/* 00F6D8 7000EAD8 AC440004 */  sw    $a0, 4($v0)
.L7000EADC:
/* 00F6DC 7000EADC 03E00008 */  jr    $ra
/* 00F6E0 7000EAE0 ACA40000 */   sw    $a0, ($a1)

glabel alClose
/* 00F6E4 7000EAE4 3C0E8002 */  lui   $t6, %hi(alGlobals) 
/* 00F6E8 7000EAE8 8DCE76E0 */  lw    $t6, %lo(alGlobals)($t6)
/* 00F6EC 7000EAEC 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 00F6F0 7000EAF0 AFBF0014 */  sw    $ra, 0x14($sp)
/* 00F6F4 7000EAF4 51C00006 */  beql  $t6, $zero, .L7000EB10
/* 00F6F8 7000EAF8 8FBF0014 */   lw    $ra, 0x14($sp)
/* 00F6FC 7000EAFC 0C006438 */  jal   alSynDelete
/* 00F700 7000EB00 00000000 */   nop   
/* 00F704 7000EB04 3C018002 */  lui   $at, %hi(alGlobals)
/* 00F708 7000EB08 AC2076E0 */  sw    $zero, %lo(alGlobals)($at)
/* 00F70C 7000EB0C 8FBF0014 */  lw    $ra, 0x14($sp)
.L7000EB10:
/* 00F710 7000EB10 27BD0018 */  addiu $sp, $sp, 0x18
/* 00F714 7000EB14 03E00008 */  jr    $ra
/* 00F718 7000EB18 00000000 */   nop   

glabel alInit
/* 00F71C 7000EB1C 3C028002 */  lui   $v0, %hi(alGlobals)
/* 00F720 7000EB20 244276E0 */  addiu $v0, %lo(alGlobals) # addiu $v0, $v0, 0x76e0
/* 00F724 7000EB24 8C4E0000 */  lw    $t6, ($v0)
/* 00F728 7000EB28 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 00F72C 7000EB2C AFBF0014 */  sw    $ra, 0x14($sp)
/* 00F730 7000EB30 55C00004 */  bnezl $t6, .L7000EB44
/* 00F734 7000EB34 8FBF0014 */   lw    $ra, 0x14($sp)
/* 00F738 7000EB38 0C003CE8 */  jal   alSynNew
/* 00F73C 7000EB3C AC440000 */   sw    $a0, ($v0)
/* 00F740 7000EB40 8FBF0014 */  lw    $ra, 0x14($sp)
.L7000EB44:
/* 00F744 7000EB44 27BD0018 */  addiu $sp, $sp, 0x18
/* 00F748 7000EB48 03E00008 */  jr    $ra
/* 00F74C 7000EB4C 00000000 */   nop   

.section .data
glabel alGlobals
 .word 0
.align 4

.section .text
glabel alHeapDBAlloc
/* 00F750 7000EB50 8FAE0010 */  lw    $t6, 0x10($sp)
/* 00F754 7000EB54 AFA40000 */  sw    $a0, ($sp)
/* 00F758 7000EB58 AFA50004 */  sw    $a1, 4($sp)
/* 00F75C 7000EB5C 00EE0019 */  multu $a3, $t6
/* 00F760 7000EB60 8CD90008 */  lw    $t9, 8($a2)
/* 00F764 7000EB64 8CD80000 */  lw    $t8, ($a2)
/* 00F768 7000EB68 8CC40004 */  lw    $a0, 4($a2)
/* 00F76C 7000EB6C 2401FFF0 */  li    $at, -16
/* 00F770 7000EB70 03194021 */  addu  $t0, $t8, $t9
/* 00F774 7000EB74 00001825 */  move  $v1, $zero
/* 00F778 7000EB78 00001012 */  mflo  $v0
/* 00F77C 7000EB7C 2442000F */  addiu $v0, $v0, 0xf
/* 00F780 7000EB80 00417824 */  and   $t7, $v0, $at
/* 00F784 7000EB84 008F4821 */  addu  $t1, $a0, $t7
/* 00F788 7000EB88 0109082B */  sltu  $at, $t0, $t1
/* 00F78C 7000EB8C 14200003 */  bnez  $at, .L7000EB9C
/* 00F790 7000EB90 008F5021 */   addu  $t2, $a0, $t7
/* 00F794 7000EB94 00801825 */  move  $v1, $a0
/* 00F798 7000EB98 ACCA0004 */  sw    $t2, 4($a2)
.L7000EB9C:
/* 00F79C 7000EB9C 03E00008 */  jr    $ra
/* 00F7A0 7000EBA0 00601025 */   move  $v0, $v1

