#include "ultra64.h"

#ifdef NONMATCHING
void osDpGetCounters(void *arg0) {
    void *temp_a0;
    void *temp_a0_2;

    // Node 0
    *arg0 = (?32) DPC_CLOCK_REG;
    temp_a0 = (arg0 + 4);
    *temp_a0 = (?32) DPC_BUFBUSY_REG;
    temp_a0_2 = ((temp_a0 + 4) + 4);
    temp_a0_2->unk-4 = (?32) DPC_PIPEBUSY_REG;
    (temp_a0_2 + 4)->unk-4 = (?32) DPC_TMEM_REG;
    return;
    // (function likely void)
}
#else
GLOBAL_ASM(
.text
glabel osDpGetCounters
/* 00EFC0 7000E3C0 3C0EA410 */  lui   $t6, %hi(DPC_CLOCK_REG) # $t6, 0xa410
/* 00EFC4 7000E3C4 8DCF0010 */  lw    $t7, %lo(DPC_CLOCK_REG)($t6)
/* 00EFC8 7000E3C8 3C18A410 */  lui   $t8, %hi(DPC_BUFBUSY_REG) # $t8, 0xa410
/* 00EFCC 7000E3CC 3C08A410 */  lui   $t0, %hi(DPC_PIPEBUSY_REG) # $t0, 0xa410
/* 00EFD0 7000E3D0 AC8F0000 */  sw    $t7, ($a0)
/* 00EFD4 7000E3D4 8F190014 */  lw    $t9, %lo(DPC_BUFBUSY_REG)($t8)
/* 00EFD8 7000E3D8 24840004 */  addiu $a0, $a0, 4
/* 00EFDC 7000E3DC 3C0AA410 */  lui   $t2, %hi(DPC_TMEM_REG) # $t2, 0xa410
/* 00EFE0 7000E3E0 AC990000 */  sw    $t9, ($a0)
/* 00EFE4 7000E3E4 8D090018 */  lw    $t1, %lo(DPC_PIPEBUSY_REG)($t0)
/* 00EFE8 7000E3E8 24840004 */  addiu $a0, $a0, 4
/* 00EFEC 7000E3EC 24840004 */  addiu $a0, $a0, 4
/* 00EFF0 7000E3F0 AC89FFFC */  sw    $t1, -4($a0)
/* 00EFF4 7000E3F4 8D4B001C */  lw    $t3, %lo(DPC_TMEM_REG)($t2)
/* 00EFF8 7000E3F8 24840004 */  addiu $a0, $a0, 4
/* 00EFFC 7000E3FC 03E00008 */  jr    $ra
/* 00F000 7000E400 AC8BFFFC */   sw    $t3, -4($a0)
)
#endif

