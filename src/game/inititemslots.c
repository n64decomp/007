#include "ultra64.h"
#include "game/unk_093880.h"
#include "game/bondinv.h"




#ifdef NONMATCHING
void sub_GAME_7F0061F0(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0061F0
/* 03AD20 7F0061F0 3C048008 */  lui   $a0, %hi(pPlayer)
/* 03AD24 7F0061F4 2484A0B0 */  addiu $a0, %lo(pPlayer) # addiu $a0, $a0, -0x5f50
/* 03AD28 7F0061F8 8C8E0000 */  lw    $t6, ($a0)
/* 03AD2C 7F0061FC 2405FFFF */  li    $a1, -1
/* 03AD30 7F006200 24030018 */  li    $v1, 24
/* 03AD34 7F006204 ADC011EC */  sw    $zero, 0x11ec($t6)
/* 03AD38 7F006208 8C8F0000 */  lw    $t7, ($a0)
/* 03AD3C 7F00620C 24020078 */  li    $v0, 120
/* 03AD40 7F006210 ADE51200 */  sw    $a1, 0x1200($t7)
/* 03AD44 7F006214 8C980000 */  lw    $t8, ($a0)
/* 03AD48 7F006218 AF05120C */  sw    $a1, 0x120c($t8)
.L7F00621C:
/* 03AD4C 7F00621C 8C990000 */  lw    $t9, ($a0)
/* 03AD50 7F006220 03234021 */  addu  $t0, $t9, $v1
/* 03AD54 7F006224 AD051200 */  sw    $a1, 0x1200($t0)
/* 03AD58 7F006228 8C890000 */  lw    $t1, ($a0)
/* 03AD5C 7F00622C 01235021 */  addu  $t2, $t1, $v1
/* 03AD60 7F006230 AD45120C */  sw    $a1, 0x120c($t2)
/* 03AD64 7F006234 8C8B0000 */  lw    $t3, ($a0)
/* 03AD68 7F006238 01636021 */  addu  $t4, $t3, $v1
/* 03AD6C 7F00623C AD851218 */  sw    $a1, 0x1218($t4)
/* 03AD70 7F006240 8C8D0000 */  lw    $t5, ($a0)
/* 03AD74 7F006244 01A37021 */  addu  $t6, $t5, $v1
/* 03AD78 7F006248 24630030 */  addiu $v1, $v1, 0x30
/* 03AD7C 7F00624C 1462FFF3 */  bne   $v1, $v0, .L7F00621C
/* 03AD80 7F006250 ADC51224 */   sw    $a1, 0x1224($t6)
/* 03AD84 7F006254 03E00008 */  jr    $ra
/* 03AD88 7F006258 00000000 */   nop   
)
#endif



void alloc_additional_item_slots(s32 additionalentries)
{
  pPlayer->equipmaxitems = additionalentries + 0x1e;
  pPlayer->p_itemcur = mempAllocBytesInBank((pPlayer->equipmaxitems * 0x14 + 0xfU | 0xf) ^ 0xf,'\x04');
  reinit_BONDdata_inventory();
}
