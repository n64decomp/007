# assembler directives
.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches
.set gp=64

.include "macros.inc"


.section .text, "ax"  
glabel alCSPGetState
/* 012E30 70012230 03E00008 */  jr    $ra
/* 012E34 70012234 8C82002C */   lw    $v0, 0x2c($a0)
