# assembler directives
.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches
.set gp=64

.include "macros.inc"


.section .text, "ax" 

glabel osAiGetLength
/* 00FBB0 7000EFB0 3C0EA450 */  lui   $t6, 0xa450
/* 00FBB4 7000EFB4 03E00008 */  jr    $ra
/* 00FBB8 7000EFB8 8DC20004 */   lw    $v0, 4($t6)

