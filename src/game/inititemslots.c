#include "ultra64.h"





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


#ifdef NONMATCHING
void alloc_additional_item_slots(s32 arg0) {
    // Node 0
    pPlayer->unk11E8 = (s32) (arg0 + 0x1e);
    pPlayer->unk11E4 = mempAllocBytesInBank(((((pPlayer->unk11E8 * 0x14) + 0xf) | 0xf) ^ 0xf), 4);
    reinit_BONDdata_inventory();
}

#else
GLOBAL_ASM(
.text
glabel alloc_additional_item_slots
/* 03AD8C 7F00625C 3C028008 */  lui   $v0, %hi(pPlayer)
/* 03AD90 7F006260 2442A0B0 */  addiu $v0, %lo(pPlayer) # addiu $v0, $v0, -0x5f50
/* 03AD94 7F006264 8C4F0000 */  lw    $t7, ($v0)
/* 03AD98 7F006268 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 03AD9C 7F00626C AFBF0014 */  sw    $ra, 0x14($sp)
/* 03ADA0 7F006270 248E001E */  addiu $t6, $a0, 0x1e
/* 03ADA4 7F006274 ADEE11E8 */  sw    $t6, 0x11e8($t7)
/* 03ADA8 7F006278 8C580000 */  lw    $t8, ($v0)
/* 03ADAC 7F00627C 24050004 */  li    $a1, 4
/* 03ADB0 7F006280 8F0411E8 */  lw    $a0, 0x11e8($t8)
/* 03ADB4 7F006284 0004C880 */  sll   $t9, $a0, 2
/* 03ADB8 7F006288 0324C821 */  addu  $t9, $t9, $a0
/* 03ADBC 7F00628C 0019C880 */  sll   $t9, $t9, 2
/* 03ADC0 7F006290 2724000F */  addiu $a0, $t9, 0xf
/* 03ADC4 7F006294 3488000F */  ori   $t0, $a0, 0xf
/* 03ADC8 7F006298 0C0025C8 */  jal   mempAllocBytesInBank
/* 03ADCC 7F00629C 3904000F */   xori  $a0, $t0, 0xf
/* 03ADD0 7F0062A0 3C0A8008 */  lui   $t2, %hi(pPlayer) 
/* 03ADD4 7F0062A4 8D4AA0B0 */  lw    $t2, %lo(pPlayer)($t2)
/* 03ADD8 7F0062A8 0FC22FFC */  jal   reinit_BONDdata_inventory
/* 03ADDC 7F0062AC AD4211E4 */   sw    $v0, 0x11e4($t2)
/* 03ADE0 7F0062B0 8FBF0014 */  lw    $ra, 0x14($sp)
/* 03ADE4 7F0062B4 27BD0018 */  addiu $sp, $sp, 0x18
/* 03ADE8 7F0062B8 03E00008 */  jr    $ra
/* 03ADEC 7F0062BC 00000000 */   nop
)
#endif


