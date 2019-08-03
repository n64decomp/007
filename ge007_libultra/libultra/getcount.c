#include "ultra64.h"

#ifdef NONMATCHING
u32 osGetCount(void){

}
#else
GLOBAL_ASM(
.text
glabel osGetCount
/* 00E4E0 7000D8E0 40024800 */  mfc0  $v0, $9
/* 00E4E4 7000D8E4 03E00008 */  jr    $ra
/* 00E4E8 7000D8E8 00000000 */   nop   
)
#endif