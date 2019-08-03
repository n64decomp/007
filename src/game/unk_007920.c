#include "ultra64.h"



#ifdef NONMATCHING
s32 sub_GAME_7F007920(void) {
    s32 temp_v0;
    s32 phi_v1;
    s32 phi_v0;

    // Node 0
    if (dword_CODE_bss_8007A160 > 0)
    {
        // Node 1
        phi_v1 = 0;
        phi_v0 = 0;
loop_2:
        // Node 2
        temp_v0 = (phi_v0 + 1);
        *(dword_CODE_bss_8007A164 + phi_v1) = 0;
        phi_v1 = (phi_v1 + 0x68);
        phi_v0 = temp_v0;
        if (temp_v0 < dword_CODE_bss_8007A160)
        {
            goto loop_2;
        }
    }
    // Node 3
    return 0;
}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F007920
/* 03C450 7F007920 3C048008 */  lui   $a0, %hi(dword_CODE_bss_8007A160) # $a0, 0x8008
/* 03C454 7F007924 2484A160 */  addiu $a0, %lo(dword_CODE_bss_8007A160) # addiu $a0, $a0, -0x5ea0
/* 03C458 7F007928 8C8E0000 */  lw    $t6, ($a0)
/* 03C45C 7F00792C 00001025 */  move  $v0, $zero
/* 03C460 7F007930 00001825 */  move  $v1, $zero
/* 03C464 7F007934 19C0000B */  blez  $t6, .L7F007964
/* 03C468 7F007938 3C058008 */   lui   $a1, %hi(dword_CODE_bss_8007A164) # $a1, 0x8008
/* 03C46C 7F00793C 24A5A164 */  addiu $a1, %lo(dword_CODE_bss_8007A164) # addiu $a1, $a1, -0x5e9c
/* 03C470 7F007940 8CAF0000 */  lw    $t7, ($a1)
.L7F007944:
/* 03C474 7F007944 24420001 */  addiu $v0, $v0, 1
/* 03C478 7F007948 01E3C021 */  addu  $t8, $t7, $v1
/* 03C47C 7F00794C AF000000 */  sw    $zero, ($t8)
/* 03C480 7F007950 8C990000 */  lw    $t9, ($a0)
/* 03C484 7F007954 24630068 */  addiu $v1, $v1, 0x68
/* 03C488 7F007958 0059082A */  slt   $at, $v0, $t9
/* 03C48C 7F00795C 5420FFF9 */  bnezl $at, .L7F007944
/* 03C490 7F007960 8CAF0000 */   lw    $t7, ($a1)
.L7F007964:
/* 03C494 7F007964 03E00008 */  jr    $ra
/* 03C498 7F007968 00000000 */   nop   
)
#endif

