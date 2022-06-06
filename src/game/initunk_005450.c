#include <ultra64.h>

#include "initunk_005450.h"

//called by stage load


#ifdef NONMATCHING
void sub_GAME_7F005450(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F005450
/* 039F80 7F005450 3C0A8007 */  lui   $t2, %hi(dword_CODE_bss_80076A50) 
/* 039F84 7F005454 254A6A50 */  addiu $t2, %lo(dword_CODE_bss_80076A50) # addiu $t2, $t2, 0x6a50
/* 039F88 7F005458 3C018003 */  lui   $at, %hi(D_80036060)
/* 039F8C 7F00545C 3C0B8007 */  lui   $t3, %hi(dword_CODE_bss_80076A64) 
/* 039F90 7F005460 AC2A6060 */  sw    $t2, %lo(D_80036060)($at)
/* 039F94 7F005464 256B6A64 */  addiu $t3, %lo(dword_CODE_bss_80076A64) # addiu $t3, $t3, 0x6a64
/* 039F98 7F005468 3C0E8007 */  lui   $t6, %hi(dword_CODE_bss_80076A78)
/* 039F9C 7F00546C AD4B000C */  sw    $t3, 0xc($t2)
/* 039FA0 7F005470 25C66A78 */  addiu $a2, $t6, %lo(dword_CODE_bss_80076A78)
/* 039FA4 7F005474 3C018007 */  lui   $at, %hi(dword_CODE_bss_80076A70)
/* 039FA8 7F005478 AC266A70 */  sw    $a2, %lo(dword_CODE_bss_80076A70)($at)
/* 039FAC 7F00547C 3C018007 */  lui   $at, %hi(dword_CODE_bss_80076A74)
/* 039FB0 7F005480 AC2A6A74 */  sw    $t2, %lo(dword_CODE_bss_80076A74)($at)
/* 039FB4 7F005484 3C0F8007 */  lui   $t7, %hi(dword_CODE_bss_80076A8C)
/* 039FB8 7F005488 25E46A8C */  addiu $a0, $t7, %lo(dword_CODE_bss_80076A8C)
/* 039FBC 7F00548C 3C018007 */  lui   $at, %hi(dword_CODE_bss_80076A84)
/* 039FC0 7F005490 AC246A84 */  sw    $a0, %lo(dword_CODE_bss_80076A84)($at)
/* 039FC4 7F005494 3C018007 */  lui   $at, %hi(dword_CODE_bss_80076A88)
/* 039FC8 7F005498 3C058007 */  lui   $a1, %hi(dword_CODE_bss_80076AA0)
/* 039FCC 7F00549C 3C078007 */  lui   $a3, %hi(dword_CODE_bss_80076AB4)
/* 039FD0 7F0054A0 3C088007 */  lui   $t0, %hi(dword_CODE_bss_80076AC8) 
/* 039FD4 7F0054A4 3C098007 */  lui   $t1, %hi(dword_CODE_bss_80076ADC) 
/* 039FD8 7F0054A8 3C028008 */  lui   $v0, %hi(flt_CODE_bss_8007996C)
/* 039FDC 7F0054AC 2442996C */  addiu $v0, %lo(flt_CODE_bss_8007996C) # addiu $v0, $v0, -0x6694
/* 039FE0 7F0054B0 25296ADC */  addiu $t1, %lo(dword_CODE_bss_80076ADC) # addiu $t1, $t1, 0x6adc
/* 039FE4 7F0054B4 25086AC8 */  addiu $t0, %lo(dword_CODE_bss_80076AC8) # addiu $t0, $t0, 0x6ac8
/* 039FE8 7F0054B8 24E76AB4 */  addiu $a3, %lo(dword_CODE_bss_80076AB4) # addiu $a3, $a3, 0x6ab4
/* 039FEC 7F0054BC 24A56AA0 */  addiu $a1, %lo(dword_CODE_bss_80076AA0) # addiu $a1, $a1, 0x6aa0
/* 039FF0 7F0054C0 AC2B6A88 */  sw    $t3, %lo(dword_CODE_bss_80076A88)($at)
/* 039FF4 7F0054C4 00801825 */  move  $v1, $a0
.L7F0054C8:
/* 039FF8 7F0054C8 AC690048 */  sw    $t1, 0x48($v1)
/* 039FFC 7F0054CC 25290050 */  addiu $t1, $t1, 0x50
/* 03A000 7F0054D0 AC670020 */  sw    $a3, 0x20($v1)
/* 03A004 7F0054D4 AC640024 */  sw    $a0, 0x24($v1)
/* 03A008 7F0054D8 AC680034 */  sw    $t0, 0x34($v1)
/* 03A00C 7F0054DC AC650038 */  sw    $a1, 0x38($v1)
/* 03A010 7F0054E0 AC67004C */  sw    $a3, 0x4c($v1)
/* 03A014 7F0054E4 AC65000C */  sw    $a1, 0xc($v1)
/* 03A018 7F0054E8 AC660010 */  sw    $a2, 0x10($v1)
/* 03A01C 7F0054EC 24C60050 */  addiu $a2, $a2, 0x50
/* 03A020 7F0054F0 24A50050 */  addiu $a1, $a1, 0x50
/* 03A024 7F0054F4 24E70050 */  addiu $a3, $a3, 0x50
/* 03A028 7F0054F8 25080050 */  addiu $t0, $t0, 0x50
/* 03A02C 7F0054FC 24840050 */  addiu $a0, $a0, 0x50
/* 03A030 7F005500 1522FFF1 */  bne   $t1, $v0, .L7F0054C8
/* 03A034 7F005504 24630050 */   addiu $v1, $v1, 0x50
/* 03A038 7F005508 3C188008 */  lui   $t8, %hi(dword_CODE_bss_80079908) 
/* 03A03C 7F00550C 27189908 */  addiu $t8, %lo(dword_CODE_bss_80079908) # addiu $t8, $t8, -0x66f8
/* 03A040 7F005510 03E00008 */  jr    $ra
/* 03A044 7F005514 AD582EDC */   sw    $t8, 0x2edc($t2)
)
#endif


