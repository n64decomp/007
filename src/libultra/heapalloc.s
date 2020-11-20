# assembler directives
.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches
.set gp=64

.include "macros.inc"


.section .text, "ax" 
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
