#include "ultra64.h"



#ifdef NONMATCHING
void sub_GAME_7F007290(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F007290
/* 03BDC0 7F007290 44800000 */  mtc1  $zero, $f0
/* 03BDC4 7F007294 3C018008 */  lui   $at, %hi(flt_CODE_bss_80079E80) # $at, 0x8008
/* 03BDC8 7F007298 E4209E80 */  swc1  $f0, %lo(flt_CODE_bss_80079E80)($at)
/* 03BDCC 7F00729C 3C018008 */  lui   $at, %hi(flt_CODE_bss_80079E84) # $at, 0x8008
/* 03BDD0 7F0072A0 E4209E84 */  swc1  $f0, %lo(flt_CODE_bss_80079E84)($at)
/* 03BDD4 7F0072A4 3C018008 */  lui   $at, %hi(flt_CODE_bss_80079E88)
/* 03BDD8 7F0072A8 03E00008 */  jr    $ra
/* 03BDDC 7F0072AC E4209E88 */   swc1  $f0, %lo(flt_CODE_bss_80079E88)($at)
)
#endif


