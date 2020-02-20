# assembler directives
.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches
.set gp=64

.include "macros.inc"


.section .text, "ax"
glabel alSynAddPlayer
/* 013D20 70013120 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 013D24 70013124 AFBF0014 */  sw    $ra, 0x14($sp)
/* 013D28 70013128 00803025 */  move  $a2, $a0
/* 013D2C 7001312C AFA60018 */  sw    $a2, 0x18($sp)
/* 013D30 70013130 24040001 */  li    $a0, 1
/* 013D34 70013134 0C00374C */  jal   osSetIntMask
/* 013D38 70013138 AFA5001C */   sw    $a1, 0x1c($sp)
/* 013D3C 7001313C 8FA60018 */  lw    $a2, 0x18($sp)
/* 013D40 70013140 8FA5001C */  lw    $a1, 0x1c($sp)
/* 013D44 70013144 00402025 */  move  $a0, $v0
/* 013D48 70013148 8CCE0020 */  lw    $t6, 0x20($a2)
/* 013D4C 7001314C ACAE0010 */  sw    $t6, 0x10($a1)
/* 013D50 70013150 8CCF0000 */  lw    $t7, ($a2)
/* 013D54 70013154 ACAF0000 */  sw    $t7, ($a1)
/* 013D58 70013158 0C00374C */  jal   osSetIntMask
/* 013D5C 7001315C ACC50000 */   sw    $a1, ($a2)
/* 013D60 70013160 8FBF0014 */  lw    $ra, 0x14($sp)
/* 013D64 70013164 27BD0018 */  addiu $sp, $sp, 0x18
/* 013D68 70013168 03E00008 */  jr    $ra
/* 013D6C 7001316C 00000000 */   nop 
