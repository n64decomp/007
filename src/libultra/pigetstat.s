# assembler directives
.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches
.set gp=64

.include "macros.inc"


.section .text, "ax"

glabel osPiGetStatus
/* 00DC70 7000D070 3C0EA460 */  lui   $t6, 0xa460
/* 00DC74 7000D074 03E00008 */  jr    $ra
/* 00DC78 7000D078 8DC20010 */   lw    $v0, 0x10($t6)
