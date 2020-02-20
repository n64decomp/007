# assembler directives
.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches
.set gp=64

.include "macros.inc"


.section .text, "ax"
glabel alCSPPlay
/* 013940 70012D40 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 013944 70012D44 AFBF0014 */  sw    $ra, 0x14($sp)
/* 013948 70012D48 240E000F */  li    $t6, 15
/* 01394C 70012D4C A7AE0018 */  sh    $t6, 0x18($sp)
/* 013950 70012D50 27A50018 */  addiu $a1, $sp, 0x18
/* 013954 70012D54 24840048 */  addiu $a0, $a0, 0x48
/* 013958 70012D58 0C004BBF */  jal   alEvtqPostEvent
/* 01395C 70012D5C 00003025 */   move  $a2, $zero
/* 013960 70012D60 8FBF0014 */  lw    $ra, 0x14($sp)
/* 013964 70012D64 27BD0028 */  addiu $sp, $sp, 0x28
/* 013968 70012D68 03E00008 */  jr    $ra
/* 01396C 70012D6C 00000000 */   nop   
