#include "ultra64.h"




#ifdef NONMATCHING
void cleanupObjectives(s32 stage) {

}
#else
GLOBAL_ASM(
.text
glabel cleanupObjectives
/* 03C0C0 7F007590 3C028007 */  lui   $v0, %hi(objective_ptrs) # $v0, 0x8007
/* 03C0C4 7F007594 8C425D30 */  lw    $v0, %lo(objective_ptrs)($v0)
/* 03C0C8 7F007598 3C048007 */  lui   $a0, %hi(objective_ptrs+8) # $a0, 0x8007
/* 03C0CC 7F00759C 24845D38 */  addiu $a0, %lo(objective_ptrs+8) # addiu $a0, $a0, 0x5d38
/* 03C0D0 7F0075A0 1040000C */  beqz  $v0, .L7F0075D4
/* 03C0D4 7F0075A4 24030008 */   li    $v1, 8
/* 03C0D8 7F0075A8 904E000E */  lbu   $t6, 0xe($v0)
/* 03C0DC 7F0075AC 3C188007 */  lui   $t8, %hi(dword_CODE_bss_80075D58) # $t8, 0x8007
/* 03C0E0 7F0075B0 31CF0001 */  andi  $t7, $t6, 1
/* 03C0E4 7F0075B4 11E00007 */  beqz  $t7, .L7F0075D4
/* 03C0E8 7F0075B8 00000000 */   nop   
/* 03C0EC 7F0075BC 8F185D58 */  lw    $t8, %lo(dword_CODE_bss_80075D58)($t8)
/* 03C0F0 7F0075C0 24050002 */  li    $a1, 2
/* 03C0F4 7F0075C4 24190001 */  li    $t9, 1
/* 03C0F8 7F0075C8 10B80002 */  beq   $a1, $t8, .L7F0075D4
/* 03C0FC 7F0075CC 3C018007 */   lui   $at, %hi(dword_CODE_bss_80075D58) # $at, 0x8007
/* 03C100 7F0075D0 AC395D58 */  sw    $t9, %lo(dword_CODE_bss_80075D58)($at)
.L7F0075D4:
/* 03C104 7F0075D4 3C028007 */  lui   $v0, %hi(objective_ptrs+4) # $v0, 0x8007
/* 03C108 7F0075D8 8C425D34 */  lw    $v0, %lo(objective_ptrs+4)($v0)
/* 03C10C 7F0075DC 3C088007 */  lui   $t0, %hi(dword_CODE_bss_80075D58) # $t0, 0x8007
/* 03C110 7F0075E0 25085D58 */  addiu $t0, %lo(dword_CODE_bss_80075D58) # addiu $t0, $t0, 0x5d58
/* 03C114 7F0075E4 1040000C */  beqz  $v0, .L7F007618
/* 03C118 7F0075E8 24050002 */   li    $a1, 2
/* 03C11C 7F0075EC 9049000E */  lbu   $t1, 0xe($v0)
/* 03C120 7F0075F0 3C0B8007 */  lui   $t3, %hi(dword_CODE_bss_80075D5C) # $t3, 0x8007
/* 03C124 7F0075F4 312A0001 */  andi  $t2, $t1, 1
/* 03C128 7F0075F8 11400007 */  beqz  $t2, .L7F007618
/* 03C12C 7F0075FC 00000000 */   nop   
/* 03C130 7F007600 8D6B5D5C */  lw    $t3, %lo(dword_CODE_bss_80075D5C)($t3)
/* 03C134 7F007604 240C0001 */  li    $t4, 1
/* 03C138 7F007608 3C018007 */  lui   $at, %hi(dword_CODE_bss_80075D5C) # $at, 0x8007
/* 03C13C 7F00760C 10AB0002 */  beq   $a1, $t3, .L7F007618
/* 03C140 7F007610 00000000 */   nop   
/* 03C144 7F007614 AC2C5D5C */  sw    $t4, %lo(dword_CODE_bss_80075D5C)($at)
.L7F007618:
/* 03C148 7F007618 3C068007 */  lui   $a2, %hi(dword_CODE_bss_80075D58) # $a2, 0x8007
/* 03C14C 7F00761C 24C65D58 */  addiu $a2, %lo(dword_CODE_bss_80075D58) # addiu $a2, $a2, 0x5d58
/* 03C150 7F007620 24070001 */  li    $a3, 1
.L7F007624:
/* 03C154 7F007624 8C820000 */  lw    $v0, ($a0)
/* 03C158 7F007628 5040000B */  beql  $v0, $zero, .L7F007658
/* 03C15C 7F00762C 8C820004 */   lw    $v0, 4($a0)
/* 03C160 7F007630 904D000E */  lbu   $t5, 0xe($v0)
/* 03C164 7F007634 00C31021 */  addu  $v0, $a2, $v1
/* 03C168 7F007638 31AE0001 */  andi  $t6, $t5, 1
/* 03C16C 7F00763C 51C00006 */  beql  $t6, $zero, .L7F007658
/* 03C170 7F007640 8C820004 */   lw    $v0, 4($a0)
/* 03C174 7F007644 8C4F0000 */  lw    $t7, ($v0)
/* 03C178 7F007648 50AF0003 */  beql  $a1, $t7, .L7F007658
/* 03C17C 7F00764C 8C820004 */   lw    $v0, 4($a0)
/* 03C180 7F007650 AC470000 */  sw    $a3, ($v0)
/* 03C184 7F007654 8C820004 */  lw    $v0, 4($a0)
.L7F007658:
/* 03C188 7F007658 5040000B */  beql  $v0, $zero, .L7F007688
/* 03C18C 7F00765C 8C820008 */   lw    $v0, 8($a0)
/* 03C190 7F007660 9058000E */  lbu   $t8, 0xe($v0)
/* 03C194 7F007664 00C31021 */  addu  $v0, $a2, $v1
/* 03C198 7F007668 33190001 */  andi  $t9, $t8, 1
/* 03C19C 7F00766C 53200006 */  beql  $t9, $zero, .L7F007688
/* 03C1A0 7F007670 8C820008 */   lw    $v0, 8($a0)
/* 03C1A4 7F007674 8C490004 */  lw    $t1, 4($v0)
/* 03C1A8 7F007678 50A90003 */  beql  $a1, $t1, .L7F007688
/* 03C1AC 7F00767C 8C820008 */   lw    $v0, 8($a0)
/* 03C1B0 7F007680 AC470004 */  sw    $a3, 4($v0)
/* 03C1B4 7F007684 8C820008 */  lw    $v0, 8($a0)
.L7F007688:
/* 03C1B8 7F007688 5040000B */  beql  $v0, $zero, .L7F0076B8
/* 03C1BC 7F00768C 8C82000C */   lw    $v0, 0xc($a0)
/* 03C1C0 7F007690 904A000E */  lbu   $t2, 0xe($v0)
/* 03C1C4 7F007694 00C31021 */  addu  $v0, $a2, $v1
/* 03C1C8 7F007698 314B0001 */  andi  $t3, $t2, 1
/* 03C1CC 7F00769C 51600006 */  beql  $t3, $zero, .L7F0076B8
/* 03C1D0 7F0076A0 8C82000C */   lw    $v0, 0xc($a0)
/* 03C1D4 7F0076A4 8C4C0008 */  lw    $t4, 8($v0)
/* 03C1D8 7F0076A8 50AC0003 */  beql  $a1, $t4, .L7F0076B8
/* 03C1DC 7F0076AC 8C82000C */   lw    $v0, 0xc($a0)
/* 03C1E0 7F0076B0 AC470008 */  sw    $a3, 8($v0)
/* 03C1E4 7F0076B4 8C82000C */  lw    $v0, 0xc($a0)
.L7F0076B8:
/* 03C1E8 7F0076B8 24840010 */  addiu $a0, $a0, 0x10
/* 03C1EC 7F0076BC 1040000A */  beqz  $v0, .L7F0076E8
/* 03C1F0 7F0076C0 00000000 */   nop   
/* 03C1F4 7F0076C4 904D000E */  lbu   $t5, 0xe($v0)
/* 03C1F8 7F0076C8 00C31021 */  addu  $v0, $a2, $v1
/* 03C1FC 7F0076CC 31AE0001 */  andi  $t6, $t5, 1
/* 03C200 7F0076D0 11C00005 */  beqz  $t6, .L7F0076E8
/* 03C204 7F0076D4 00000000 */   nop   
/* 03C208 7F0076D8 8C4F000C */  lw    $t7, 0xc($v0)
/* 03C20C 7F0076DC 10AF0002 */  beq   $a1, $t7, .L7F0076E8
/* 03C210 7F0076E0 00000000 */   nop   
/* 03C214 7F0076E4 AC47000C */  sw    $a3, 0xc($v0)
.L7F0076E8:
/* 03C218 7F0076E8 1488FFCE */  bne   $a0, $t0, .L7F007624
/* 03C21C 7F0076EC 24630010 */   addiu $v1, $v1, 0x10
/* 03C220 7F0076F0 03E00008 */  jr    $ra
/* 03C224 7F0076F4 00000000 */   nop   
)
#endif

