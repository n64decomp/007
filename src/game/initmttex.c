#include "ultra64.h"



#ifdef NONMATCHING
void set_mt_tex_alloc(void) {

}
#else
GLOBAL_ASM(
.late_rodata
glabel str_Mt
.word 0x2d6d7400 /*-mt*/
glabel str_Mt_0
.word 0x2d6d7400 /*-mt*/
.text
glabel set_mt_tex_alloc
/* 03BE50 7F007320 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 03BE54 7F007324 AFBF0014 */  sw    $ra, 0x14($sp)
/* 03BE58 7F007328 3C018009 */  lui   $at, %hi(dword_CODE_bss_8008D090)
/* 03BE5C 7F00732C 3C058005 */  lui   $a1, %hi(str_Mt)
/* 03BE60 7F007330 AC20D090 */  sw    $zero, %lo(dword_CODE_bss_8008D090)($at)
/* 03BE64 7F007334 24A5F200 */  addiu $a1, %lo(str_Mt) # addiu $a1, $a1, -0xe00
/* 03BE68 7F007338 0C0029A8 */  jal   check_token
/* 03BE6C 7F00733C 24040001 */   li    $a0, 1
/* 03BE70 7F007340 1040000B */  beqz  $v0, .L7F007370
/* 03BE74 7F007344 24040001 */   li    $a0, 1
/* 03BE78 7F007348 3C058005 */  lui   $a1, %hi(str_Mt_0)
/* 03BE7C 7F00734C 0C0029A8 */  jal   check_token
/* 03BE80 7F007350 24A5F204 */   addiu $a1, %lo(str_Mt_0) # addiu $a1, $a1, -0xdfc
/* 03BE84 7F007354 00402025 */  move  $a0, $v0
/* 03BE88 7F007358 00002825 */  move  $a1, $zero
/* 03BE8C 7F00735C 0C002A78 */  jal   strtol
/* 03BE90 7F007360 00003025 */   move  $a2, $zero
/* 03BE94 7F007364 00027280 */  sll   $t6, $v0, 0xa
/* 03BE98 7F007368 3C018005 */  lui   $at, %hi(bytes)
/* 03BE9C 7F00736C AC2E9170 */  sw    $t6, %lo(bytes)($at)
.L7F007370:
/* 03BEA0 7F007370 3C048005 */  lui   $a0, %hi(bytes)
/* 03BEA4 7F007374 8C849170 */  lw    $a0, %lo(bytes)($a0)
/* 03BEA8 7F007378 0C0025C8 */  jal   allocate_bytes_in_bank
/* 03BEAC 7F00737C 24050004 */   li    $a1, 4
/* 03BEB0 7F007380 3C048009 */  lui   $a0, %hi(ptr_texture_alloc_start)
/* 03BEB4 7F007384 3C068005 */  lui   $a2, %hi(bytes)
/* 03BEB8 7F007388 8CC69170 */  lw    $a2, %lo(bytes)($a2)
/* 03BEBC 7F00738C 2484C720 */  addiu $a0, %lo(ptr_texture_alloc_start) # addiu $a0, $a0, -0x38e0
/* 03BEC0 7F007390 0FC32EBD */  jal   sub_GAME_7F0CBAF4
/* 03BEC4 7F007394 00402825 */   move  $a1, $v0
/* 03BEC8 7F007398 8FBF0014 */  lw    $ra, 0x14($sp)
/* 03BECC 7F00739C 27BD0018 */  addiu $sp, $sp, 0x18
/* 03BED0 7F0073A0 03E00008 */  jr    $ra
/* 03BED4 7F0073A4 00000000 */   nop   
)
#endif



