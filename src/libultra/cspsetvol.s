# assembler directives
.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches
.set gp=64

.include "macros.inc"


.section .text, "ax"

glabel alCSPSetVol
/* 0139A0 70012DA0 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 0139A4 70012DA4 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0139A8 70012DA8 AFA5002C */  sw    $a1, 0x2c($sp)
/* 0139AC 70012DAC 00A07025 */  move  $t6, $a1
/* 0139B0 70012DB0 240F000A */  li    $t7, 10
/* 0139B4 70012DB4 A7AF0018 */  sh    $t7, 0x18($sp)
/* 0139B8 70012DB8 A7AE001C */  sh    $t6, 0x1c($sp)
/* 0139BC 70012DBC 27A50018 */  addiu $a1, $sp, 0x18
/* 0139C0 70012DC0 24840048 */  addiu $a0, $a0, 0x48
/* 0139C4 70012DC4 0C004BBF */  jal   alEvtqPostEvent
/* 0139C8 70012DC8 00003025 */   move  $a2, $zero
/* 0139CC 70012DCC 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0139D0 70012DD0 27BD0028 */  addiu $sp, $sp, 0x28
/* 0139D4 70012DD4 03E00008 */  jr    $ra
/* 0139D8 70012DD8 00000000 */   nop   
