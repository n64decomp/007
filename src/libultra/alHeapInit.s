# assembler directives
.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches
.set gp=64

.include "macros.inc"


.section .text, "ax" 
glabel alHeapInit
/* 011930 70010D30 24030010 */  li    $v1, 16
/* 011934 70010D34 30AE000F */  andi  $t6, $a1, 0xf
/* 011938 70010D38 006E1023 */  subu  $v0, $v1, $t6
/* 01193C 70010D3C 10620003 */  beq   $v1, $v0, .L70010D4C
/* 011940 70010D40 00A27821 */   addu  $t7, $a1, $v0
/* 011944 70010D44 10000002 */  b     .L70010D50
/* 011948 70010D48 AC8F0000 */   sw    $t7, ($a0)
.L70010D4C:
/* 01194C 70010D4C AC850000 */  sw    $a1, ($a0)
.L70010D50:
/* 011950 70010D50 8C980000 */  lw    $t8, ($a0)
/* 011954 70010D54 AC860008 */  sw    $a2, 8($a0)
/* 011958 70010D58 AC80000C */  sw    $zero, 0xc($a0)
/* 01195C 70010D5C 03E00008 */  jr    $ra
/* 011960 70010D60 AC980004 */   sw    $t8, 4($a0)
