# assembler directives
.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches
.set gp=64

.include "macros.inc"


.section .text, "ax" 
glabel osYieldThread
/* 0116D0 70010AD0 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 0116D4 70010AD4 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0116D8 70010AD8 0C00617C */  jal   __osDisableInt
/* 0116DC 70010ADC AFB00018 */   sw    $s0, 0x18($sp)
/* 0116E0 70010AE0 3C0F8002 */  lui   $t7, %hi(__osRunningThread) 
/* 0116E4 70010AE4 8DEF7730 */  lw    $t7, %lo(__osRunningThread)($t7)
/* 0116E8 70010AE8 240E0002 */  li    $t6, 2
/* 0116EC 70010AEC 3C048002 */  lui   $a0, %hi(__osRunQueue)
/* 0116F0 70010AF0 00408025 */  move  $s0, $v0
/* 0116F4 70010AF4 24847728 */  addiu $a0, %lo(__osRunQueue) # addiu $a0, $a0, 0x7728
/* 0116F8 70010AF8 0C0041EB */  jal   __osEnqueueAndYield
/* 0116FC 70010AFC A5EE0010 */   sh    $t6, 0x10($t7)
/* 011700 70010B00 0C006184 */  jal   __osRestoreInt
/* 011704 70010B04 02002025 */   move  $a0, $s0
/* 011708 70010B08 8FBF001C */  lw    $ra, 0x1c($sp)
/* 01170C 70010B0C 8FB00018 */  lw    $s0, 0x18($sp)
/* 011710 70010B10 27BD0028 */  addiu $sp, $sp, 0x28
/* 011714 70010B14 03E00008 */  jr    $ra
/* 011718 70010B18 00000000 */   nop   
