#include "ultra64.h"



#ifdef NONMATCHING
void set_gu_scale(void) {

    guScale(&dword_CODE_bss_8007A100, default_gu_scale, default_gu_scale, default_gu_scale);

}

#else
GLOBAL_ASM(
.late_rodata
/*8004ed80*/
glabel default_gu_scale
.word 0x3dcccccd
.text
glabel set_gu_scale
/* 0356B0 7F000B80 3C018005 */  lui   $at, %hi(default_gu_scale) # $at, 0x8005
/* 0356B4 7F000B84 C420ED80 */  lwc1  $f0, %lo(default_gu_scale)($at)
/* 0356B8 7F000B88 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0356BC 7F000B8C AFBF0014 */  sw    $ra, 0x14($sp)
/* 0356C0 7F000B90 3C048008 */  lui   $a0, %hi(dword_CODE_bss_8007A100) # $a0, 0x8008
/* 0356C4 7F000B94 44050000 */  mfc1  $a1, $f0
/* 0356C8 7F000B98 44060000 */  mfc1  $a2, $f0
/* 0356CC 7F000B9C 44070000 */  mfc1  $a3, $f0
/* 0356D0 7F000BA0 0C005BB9 */  jal   guScale
/* 0356D4 7F000BA4 2484A100 */   addiu $a0, %lo(dword_CODE_bss_8007A100) # addiu $a0, $a0, -0x5f00
/* 0356D8 7F000BA8 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0356DC 7F000BAC 27BD0018 */  addiu $sp, $sp, 0x18
/* 0356E0 7F000BB0 03E00008 */  jr    $ra
/* 0356E4 7F000BB4 00000000 */   nop   
)
#endif
