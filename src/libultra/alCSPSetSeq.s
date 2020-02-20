# assembler directives
.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches
.set gp=64

.include "macros.inc"


.section .text, "ax"
glabel alCSPSetSeq
/* 013900 70012D00 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 013904 70012D04 AFBF0014 */  sw    $ra, 0x14($sp)
/* 013908 70012D08 240E000D */  li    $t6, 13
/* 01390C 70012D0C AFA5001C */  sw    $a1, 0x1c($sp)
/* 013910 70012D10 A7AE0018 */  sh    $t6, 0x18($sp)
/* 013914 70012D14 27A50018 */  addiu $a1, $sp, 0x18
/* 013918 70012D18 24840048 */  addiu $a0, $a0, 0x48
/* 01391C 70012D1C 0C004BBF */  jal   alEvtqPostEvent
/* 013920 70012D20 00003025 */   move  $a2, $zero
/* 013924 70012D24 8FBF0014 */  lw    $ra, 0x14($sp)
/* 013928 70012D28 27BD0028 */  addiu $sp, $sp, 0x28
/* 01392C 70012D2C 03E00008 */  jr    $ra
/* 013930 70012D30 00000000 */   nop   
