# asm file.

# assembler directives
.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches
.set gp=64

.include "macros.inc"


.section .text, "ax" 
glabel osInvalICache
/* 00DF50 7000D350 18A00011 */  blez  $a1, .L7000D398
/* 00DF54 7000D354 00000000 */   nop   
/* 00DF58 7000D358 240B4000 */  li    $t3, 16384
/* 00DF5C 7000D35C 00AB082B */  sltu  $at, $a1, $t3
/* 00DF60 7000D360 1020000F */  beqz  $at, .L7000D3A0
/* 00DF64 7000D364 00000000 */   nop   
/* 00DF68 7000D368 00804025 */  move  $t0, $a0
/* 00DF6C 7000D36C 00854821 */  addu  $t1, $a0, $a1
/* 00DF70 7000D370 0109082B */  sltu  $at, $t0, $t1
/* 00DF74 7000D374 10200008 */  beqz  $at, .L7000D398
/* 00DF78 7000D378 00000000 */   nop   
/* 00DF7C 7000D37C 310A001F */  andi  $t2, $t0, 0x1f
/* 00DF80 7000D380 2529FFE0 */  addiu $t1, $t1, -0x20
/* 00DF84 7000D384 010A4023 */  subu  $t0, $t0, $t2
.L7000D388:
/* 00DF88 7000D388 BD100000 */  cache 0x10, ($t0)
/* 00DF8C 7000D38C 0109082B */  sltu  $at, $t0, $t1
/* 00DF90 7000D390 1420FFFD */  bnez  $at, .L7000D388
/* 00DF94 7000D394 25080020 */   addiu $t0, $t0, 0x20
.L7000D398:
/* 00DF98 7000D398 03E00008 */  jr    $ra
/* 00DF9C 7000D39C 00000000 */   nop   

.L7000D3A0:
/* 00DFA0 7000D3A0 3C088000 */  lui   $t0, 0x8000
/* 00DFA4 7000D3A4 010B4821 */  addu  $t1, $t0, $t3
/* 00DFA8 7000D3A8 2529FFE0 */  addiu $t1, $t1, -0x20
.L7000D3AC:
/* 00DFAC 7000D3AC BD000000 */  cache 0, ($t0)
/* 00DFB0 7000D3B0 0109082B */  sltu  $at, $t0, $t1
/* 00DFB4 7000D3B4 1420FFFD */  bnez  $at, .L7000D3AC
/* 00DFB8 7000D3B8 25080020 */   addiu $t0, $t0, 0x20
/* 00DFBC 7000D3BC 03E00008 */  jr    $ra
/* 00DFC0 7000D3C0 00000000 */   nop   
