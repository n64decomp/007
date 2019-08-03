#include "ultra64.h"

#ifdef NONMATCHING
void osDpSetStatus(u32 data){
    DPC_STATUS_REG = data;
}
#else
GLOBAL_ASM(
.text
glabel osDpSetStatus
/* 00F0E0 7000E4E0 3C0EA410 */  lui   $t6, %hi(DPC_STATUS_REG)
/* 00F0E4 7000E4E4 03E00008 */  jr    $ra
/* 00F0E8 7000E4E8 ADC4000C */   sw    $a0, %lo(DPC_STATUS_REG)($t6)
)
#endif