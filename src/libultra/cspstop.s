# assembler directives
.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches
.set gp=64

.include "macros.inc"


.section .text, "ax"

glabel alCSPStop
/* 013970 70012D70 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 013974 70012D74 AFBF0014 */  sw    $ra, 0x14($sp)
/* 013978 70012D78 240E0011 */  li    $t6, 17
/* 01397C 70012D7C A7AE0018 */  sh    $t6, 0x18($sp)
/* 013980 70012D80 27A50018 */  addiu $a1, $sp, 0x18
/* 013984 70012D84 24840048 */  addiu $a0, $a0, 0x48
/* 013988 70012D88 0C004BBF */  jal   alEvtqPostEvent
/* 01398C 70012D8C 00003025 */   move  $a2, $zero
/* 013990 70012D90 8FBF0014 */  lw    $ra, 0x14($sp)
/* 013994 70012D94 27BD0028 */  addiu $sp, $sp, 0x28
/* 013998 70012D98 03E00008 */  jr    $ra
/* 01399C 70012D9C 00000000 */   nop   
