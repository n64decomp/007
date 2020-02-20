# assembler directives
.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches
.set gp=64

.include "macros.inc"


.section .text, "ax" 

glabel osDpSetStatus
/* 00F0E0 7000E4E0 3C0EA410 */  lui   $t6, 0xa410
/* 00F0E4 7000E4E4 03E00008 */  jr    $ra
/* 00F0E8 7000E4E8 ADC4000C */   sw    $a0, 0xc($t6)
