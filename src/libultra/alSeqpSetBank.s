# assembler directives
.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches
.set gp=64

.include "macros.inc"


.section .text, "ax"
glabel alSeqpSetBank
/* 012DF0 700121F0 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 012DF4 700121F4 AFBF0014 */  sw    $ra, 0x14($sp)
/* 012DF8 700121F8 240E000E */  li    $t6, 14
/* 012DFC 700121FC AFA5001C */  sw    $a1, 0x1c($sp)
/* 012E00 70012200 A7AE0018 */  sh    $t6, 0x18($sp)
/* 012E04 70012204 27A50018 */  addiu $a1, $sp, 0x18
/* 012E08 70012208 24840048 */  addiu $a0, $a0, 0x48
/* 012E0C 7001220C 0C004BBF */  jal   alEvtqPostEvent
/* 012E10 70012210 00003025 */   move  $a2, $zero
/* 012E14 70012214 8FBF0014 */  lw    $ra, 0x14($sp)
/* 012E18 70012218 27BD0028 */  addiu $sp, $sp, 0x28
/* 012E1C 7001221C 03E00008 */  jr    $ra
/* 012E20 70012220 00000000 */   nop   
