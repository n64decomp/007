# assembler directives
.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches
.set gp=64

.include "macros.inc"


.section .text, "ax" 

glabel osCreateMesgQueue
/* 00E2D0 7000D6D0 3C0E8002 */  lui   $t6, %hi(__osThreadTail) 
/* 00E2D4 7000D6D4 3C0F8002 */  lui   $t7, %hi(__osThreadTail) 
/* 00E2D8 7000D6D8 25CE7720 */  addiu $t6, %lo(__osThreadTail) # addiu $t6, $t6, 0x7720
/* 00E2DC 7000D6DC 25EF7720 */  addiu $t7, %lo(__osThreadTail) # addiu $t7, $t7, 0x7720
/* 00E2E0 7000D6E0 AC8E0000 */  sw    $t6, ($a0)
/* 00E2E4 7000D6E4 AC8F0004 */  sw    $t7, 4($a0)
/* 00E2E8 7000D6E8 AC800008 */  sw    $zero, 8($a0)
/* 00E2EC 7000D6EC AC80000C */  sw    $zero, 0xc($a0)
/* 00E2F0 7000D6F0 AC860010 */  sw    $a2, 0x10($a0)
/* 00E2F4 7000D6F4 03E00008 */  jr    $ra
/* 00E2F8 7000D6F8 AC850014 */   sw    $a1, 0x14($a0)

#wtf why do these exist, figure out
/* 00E2FC 7000D6FC 00000000 */  nop   
/* 00E300 7000D700 00000000 */  nop   
/* 00E304 7000D704 00000000 */  nop   
/* 00E308 7000D708 00000000 */  nop   
/* 00E30C 7000D70C 00000000 */  nop   
/* 00E310 7000D710 00000000 */  nop   
/* 00E314 7000D714 00000000 */  nop   
/* 00E318 7000D718 00000000 */  nop   
/* 00E31C 7000D71C 00000000 */  nop   
/* 00E320 7000D720 00000000 */  nop   
/* 00E324 7000D724 00000000 */  nop   
/* 00E328 7000D728 00000000 */  nop   
/* 00E32C 7000D72C 00000000 */  nop   
/* 00E330 7000D730 00000000 */  nop   
/* 00E334 7000D734 00000000 */  nop   
/* 00E338 7000D738 00000000 */  nop   
/* 00E33C 7000D73C 00000000 */  nop   
