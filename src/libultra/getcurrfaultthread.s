# assembler directives
.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches
.set gp=64

.include "macros.inc"


.section .text, "ax" 
glabel __osGetCurrFaultedThread
/* 010D80 70010180 3C028002 */  lui   $v0, %hi(__osFaultedThread)
/* 010D84 70010184 03E00008 */  jr    $ra
/* 010D88 70010188 8C427734 */   lw    $v0, %lo(__osFaultedThread)($v0)

