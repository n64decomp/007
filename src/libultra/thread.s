# assembler directives
.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches
.set gp=64

.include "macros.inc"


.section .text, "ax" 
glabel __osDequeueThread
/* 011690 70010A90 00803025 */  move  $a2, $a0
/* 011694 70010A94 8CC70000 */  lw    $a3, ($a2)
/* 011698 70010A98 27BDFFF8 */  addiu $sp, $sp, -8
/* 01169C 70010A9C 10E0000A */  beqz  $a3, .L70010AC8
/* 0116A0 70010AA0 00000000 */   nop   
.L70010AA4:
/* 0116A4 70010AA4 14E50004 */  bne   $a3, $a1, .L70010AB8
/* 0116A8 70010AA8 00000000 */   nop   
/* 0116AC 70010AAC 8CAE0000 */  lw    $t6, ($a1)
/* 0116B0 70010AB0 10000005 */  b     .L70010AC8
/* 0116B4 70010AB4 ACCE0000 */   sw    $t6, ($a2)
.L70010AB8:
/* 0116B8 70010AB8 00E03025 */  move  $a2, $a3
/* 0116BC 70010ABC 8CC70000 */  lw    $a3, ($a2)
/* 0116C0 70010AC0 14E0FFF8 */  bnez  $a3, .L70010AA4
/* 0116C4 70010AC4 00000000 */   nop   
.L70010AC8:
/* 0116C8 70010AC8 03E00008 */  jr    $ra
/* 0116CC 70010ACC 27BD0008 */   addiu $sp, $sp, 8

.section .data
glabel __osThreadTail
.word 0, 0xFFFFFFFF
glabel __osRunQueue
 .word __osThreadTail
glabel __osActiveQueue
.word __osThreadTail
glabel __osRunningThread
.word 0
glabel __osFaultedThread
.word 0
