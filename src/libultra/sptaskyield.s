# assembler directives
.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches
.set gp=64

.include "macros.inc"


.section .text, "ax" 
glabel osSpTaskYield
/* 00F460 7000E860 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 00F464 7000E864 AFBF0014 */  sw    $ra, 0x14($sp)
/* 00F468 7000E868 0C0063B8 */  jal   __osSpSetStatus
/* 00F46C 7000E86C 24040400 */   li    $a0, 1024
/* 00F470 7000E870 8FBF0014 */  lw    $ra, 0x14($sp)
/* 00F474 7000E874 27BD0018 */  addiu $sp, $sp, 0x18
/* 00F478 7000E878 03E00008 */  jr    $ra
/* 00F47C 7000E87C 00000000 */   nop 
