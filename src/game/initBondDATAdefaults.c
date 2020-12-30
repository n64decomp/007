#include "ultra64.h"


//data
s32 D_8002A790[] = { 0, 1, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };





#ifdef NONMATCHING
void sub_GAME_7F0062C0(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0062C0
/* 03ADF0 7F0062C0 27BDFFB8 */  addiu $sp, $sp, -0x48
/* 03ADF4 7F0062C4 AFB30028 */  sw    $s3, 0x28($sp)
/* 03ADF8 7F0062C8 AFB20024 */  sw    $s2, 0x24($sp)
/* 03ADFC 7F0062CC AFB10020 */  sw    $s1, 0x20($sp)
/* 03AE00 7F0062D0 AFB0001C */  sw    $s0, 0x1c($sp)
/* 03AE04 7F0062D4 AFBF0034 */  sw    $ra, 0x34($sp)
/* 03AE08 7F0062D8 AFB50030 */  sw    $s5, 0x30($sp)
/* 03AE0C 7F0062DC AFB4002C */  sw    $s4, 0x2c($sp)
/* 03AE10 7F0062E0 00A6082A */  slt   $at, $a1, $a2
/* 03AE14 7F0062E4 00E08025 */  move  $s0, $a3
/* 03AE18 7F0062E8 00A08825 */  move  $s1, $a1
/* 03AE1C 7F0062EC 00C09025 */  move  $s2, $a2
/* 03AE20 7F0062F0 00809825 */  move  $s3, $a0
/* 03AE24 7F0062F4 ACE00000 */  sw    $zero, ($a3)
/* 03AE28 7F0062F8 ACE00004 */  sw    $zero, 4($a3)
/* 03AE2C 7F0062FC 1020001A */  beqz  $at, .L7F006368
/* 03AE30 7F006300 ACE00008 */   sw    $zero, 8($a3)
/* 03AE34 7F006304 3C148004 */  lui   $s4, %hi(model_guard_character)
/* 03AE38 7F006308 2694D400 */  addiu $s4, %lo(model_guard_character) # addiu $s4, $s4, -0x2c00
/* 03AE3C 7F00630C 27B50040 */  addiu $s5, $sp, 0x40
.L7F006310:
/* 03AE40 7F006310 00002025 */  move  $a0, $zero
/* 03AE44 7F006314 00002825 */  move  $a1, $zero
/* 03AE48 7F006318 02803025 */  move  $a2, $s4
/* 03AE4C 7F00631C 02603825 */  move  $a3, $s3
/* 03AE50 7F006320 AFB10010 */  sw    $s1, 0x10($sp)
/* 03AE54 7F006324 0FC1B4B9 */  jal   sub_GAME_7F06D2E4
/* 03AE58 7F006328 AFB50014 */   sw    $s5, 0x14($sp)
/* 03AE5C 7F00632C 8E0E0000 */  lw    $t6, ($s0)
/* 03AE60 7F006330 87AF0040 */  lh    $t7, 0x40($sp)
/* 03AE64 7F006334 8E190004 */  lw    $t9, 4($s0)
/* 03AE68 7F006338 8E0A0008 */  lw    $t2, 8($s0)
/* 03AE6C 7F00633C 01CFC021 */  addu  $t8, $t6, $t7
/* 03AE70 7F006340 AE180000 */  sw    $t8, ($s0)
/* 03AE74 7F006344 87A80042 */  lh    $t0, 0x42($sp)
/* 03AE78 7F006348 26310001 */  addiu $s1, $s1, 1
/* 03AE7C 7F00634C 0232082A */  slt   $at, $s1, $s2
/* 03AE80 7F006350 03284821 */  addu  $t1, $t9, $t0
/* 03AE84 7F006354 AE090004 */  sw    $t1, 4($s0)
/* 03AE88 7F006358 87AB0044 */  lh    $t3, 0x44($sp)
/* 03AE8C 7F00635C 014B6021 */  addu  $t4, $t2, $t3
/* 03AE90 7F006360 1420FFEB */  bnez  $at, .L7F006310
/* 03AE94 7F006364 AE0C0008 */   sw    $t4, 8($s0)
.L7F006368:
/* 03AE98 7F006368 8FBF0034 */  lw    $ra, 0x34($sp)
/* 03AE9C 7F00636C 8FB0001C */  lw    $s0, 0x1c($sp)
/* 03AEA0 7F006370 8FB10020 */  lw    $s1, 0x20($sp)
/* 03AEA4 7F006374 8FB20024 */  lw    $s2, 0x24($sp)
/* 03AEA8 7F006378 8FB30028 */  lw    $s3, 0x28($sp)
/* 03AEAC 7F00637C 8FB4002C */  lw    $s4, 0x2c($sp)
/* 03AEB0 7F006380 8FB50030 */  lw    $s5, 0x30($sp)
/* 03AEB4 7F006384 03E00008 */  jr    $ra
/* 03AEB8 7F006388 27BD0048 */   addiu $sp, $sp, 0x48
)
#endif



#ifdef NONMATCHING
void sets_a_bunch_of_BONDdata_values_to_default(void) {

}
#else

#ifdef VERSION_US
GLOBAL_ASM(
.late_rodata
glabel D_8004F1F0
.word 0x3dccccce
glabel D_8004F1F4
.word 0x4164924b
glabel D_8004F1F8
.word 0x3f6e147b
.text
glabel sets_a_bunch_of_BONDdata_values_to_default
/* 03AEBC 7F00638C 27BDFF20 */  addiu $sp, $sp, -0xe0
/* 03AEC0 7F006390 AFB20038 */  sw    $s2, 0x38($sp)
/* 03AEC4 7F006394 3C128004 */  lui   $s2, %hi(player_gait_object)
/* 03AEC8 7F006398 2652C650 */  addiu $s2, %lo(player_gait_object) # addiu $s2, $s2, -0x39b0
/* 03AECC 7F00639C 864E0014 */  lh    $t6, 0x14($s2)
/* 03AED0 7F0063A0 AFBF0044 */  sw    $ra, 0x44($sp)
/* 03AED4 7F0063A4 AFB40040 */  sw    $s4, 0x40($sp)
/* 03AED8 7F0063A8 29C1001F */  slti  $at, $t6, 0x1f
/* 03AEDC 7F0063AC AFB3003C */  sw    $s3, 0x3c($sp)
/* 03AEE0 7F0063B0 AFB10034 */  sw    $s1, 0x34($sp)
/* 03AEE4 7F0063B4 AFB00030 */  sw    $s0, 0x30($sp)
/* 03AEE8 7F0063B8 F7B60028 */  sdc1  $f22, 0x28($sp)
/* 03AEEC 7F0063BC 14200003 */  bnez  $at, .L7F0063CC
/* 03AEF0 7F0063C0 F7B40020 */   sdc1  $f20, 0x20($sp)
/* 03AEF4 7F0063C4 0FC1B11B */  jal   return_null
/* 03AEF8 7F0063C8 00000000 */   nop   
.L7F0063CC:
/* 03AEFC 7F0063CC 3C118008 */  lui   $s1, %hi(pPlayer)
/* 03AF00 7F0063D0 2631A0B0 */  addiu $s1, %lo(pPlayer) # addiu $s1, $s1, -0x5f50
/* 03AF04 7F0063D4 8E300000 */  lw    $s0, ($s1)
/* 03AF08 7F0063D8 02402825 */  move  $a1, $s2
/* 03AF0C 7F0063DC 26040598 */  addiu $a0, $s0, 0x598
/* 03AF10 7F0063E0 0FC1D7EB */  jal   sub_GAME_7F075FAC
/* 03AF14 7F0063E4 26060654 */   addiu $a2, $s0, 0x654
/* 03AF18 7F0063E8 3C018005 */  lui   $at, %hi(D_8004F1F0)
/* 03AF1C 7F0063EC C436F1F0 */  lwc1  $f22, %lo(D_8004F1F0)($at)
/* 03AF20 7F0063F0 8E240000 */  lw    $a0, ($s1)
/* 03AF24 7F0063F4 4405B000 */  mfc1  $a1, $f22
/* 03AF28 7F0063F8 0FC1B39E */  jal   set_obj_instance_controller_scale
/* 03AF2C 7F0063FC 24840598 */   addiu $a0, $a0, 0x598
/* 03AF30 7F006400 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 03AF34 7F006404 44810000 */  mtc1  $at, $f0
/* 03AF38 7F006408 8E2F0000 */  lw    $t7, ($s1)
/* 03AF3C 7F00640C 3C018005 */  lui   $at, %hi(D_8004F1F4)
/* 03AF40 7F006410 C422F1F4 */  lwc1  $f2, %lo(D_8004F1F4)($at)
/* 03AF44 7F006414 ADE004E8 */  sw    $zero, 0x4e8($t7)
/* 03AF48 7F006418 3C018005 */  lui   $at, %hi(D_8004F1F8)
/* 03AF4C 7F00641C C424F1F8 */  lwc1  $f4, %lo(D_8004F1F8)($at)
/* 03AF50 7F006420 8E380000 */  lw    $t8, ($s1)
/* 03AF54 7F006424 4480A000 */  mtc1  $zero, $f20
/* 03AF58 7F006428 24020001 */  li    $v0, 1
/* 03AF5C 7F00642C E70404EC */  swc1  $f4, 0x4ec($t8)
/* 03AF60 7F006430 8E390000 */  lw    $t9, ($s1)
/* 03AF64 7F006434 3C108003 */  lui   $s0, %hi(D_80036AD0)
/* 03AF68 7F006438 3C148007 */  lui   $s4, %hi(ptr_animation_table)
/* 03AF6C 7F00643C AF2004F0 */  sw    $zero, 0x4f0($t9)
/* 03AF70 7F006440 8E280000 */  lw    $t0, ($s1)
/* 03AF74 7F006444 3C138003 */  lui   $s3, %hi(D_80036B00)
/* 03AF78 7F006448 26736B00 */  addiu $s3, %lo(D_80036B00) # addiu $s3, $s3, 0x6b00
/* 03AF7C 7F00644C E50004F4 */  swc1  $f0, 0x4f4($t0)
/* 03AF80 7F006450 8E290000 */  lw    $t1, ($s1)
/* 03AF84 7F006454 26949538 */  addiu $s4, %lo(ptr_animation_table) # addiu $s4, $s4, -0x6ac8
/* 03AF88 7F006458 26106AD0 */  addiu $s0, %lo(D_80036AD0) # addiu $s0, $s0, 0x6ad0
/* 03AF8C 7F00645C E52004F8 */  swc1  $f0, 0x4f8($t1)
/* 03AF90 7F006460 8E2A0000 */  lw    $t2, ($s1)
/* 03AF94 7F006464 27B200D0 */  addiu $s2, $sp, 0xd0
/* 03AF98 7F006468 E55404FC */  swc1  $f20, 0x4fc($t2)
/* 03AF9C 7F00646C 8E2B0000 */  lw    $t3, ($s1)
/* 03AFA0 7F006470 E5740500 */  swc1  $f20, 0x500($t3)
/* 03AFA4 7F006474 8E2C0000 */  lw    $t4, ($s1)
/* 03AFA8 7F006478 E5940504 */  swc1  $f20, 0x504($t4)
/* 03AFAC 7F00647C 8E2D0000 */  lw    $t5, ($s1)
/* 03AFB0 7F006480 E5B40508 */  swc1  $f20, 0x508($t5)
/* 03AFB4 7F006484 8E2E0000 */  lw    $t6, ($s1)
/* 03AFB8 7F006488 E5D4050C */  swc1  $f20, 0x50c($t6)
/* 03AFBC 7F00648C 8E2F0000 */  lw    $t7, ($s1)
/* 03AFC0 7F006490 E5F40510 */  swc1  $f20, 0x510($t7)
/* 03AFC4 7F006494 8E380000 */  lw    $t8, ($s1)
/* 03AFC8 7F006498 E7140514 */  swc1  $f20, 0x514($t8)
/* 03AFCC 7F00649C 8E390000 */  lw    $t9, ($s1)
/* 03AFD0 7F0064A0 E7340518 */  swc1  $f20, 0x518($t9)
/* 03AFD4 7F0064A4 8E280000 */  lw    $t0, ($s1)
/* 03AFD8 7F0064A8 E514051C */  swc1  $f20, 0x51c($t0)
/* 03AFDC 7F0064AC 8E290000 */  lw    $t1, ($s1)
/* 03AFE0 7F0064B0 E5340520 */  swc1  $f20, 0x520($t1)
/* 03AFE4 7F0064B4 8E2A0000 */  lw    $t2, ($s1)
/* 03AFE8 7F0064B8 E5540524 */  swc1  $f20, 0x524($t2)
/* 03AFEC 7F0064BC 8E2B0000 */  lw    $t3, ($s1)
/* 03AFF0 7F0064C0 E5740528 */  swc1  $f20, 0x528($t3)
/* 03AFF4 7F0064C4 8E2C0000 */  lw    $t4, ($s1)
/* 03AFF8 7F0064C8 E594052C */  swc1  $f20, 0x52c($t4)
/* 03AFFC 7F0064CC 8E2D0000 */  lw    $t5, ($s1)
/* 03B000 7F0064D0 E5B40530 */  swc1  $f20, 0x530($t5)
/* 03B004 7F0064D4 8E2E0000 */  lw    $t6, ($s1)
/* 03B008 7F0064D8 E5C20534 */  swc1  $f2, 0x534($t6)
/* 03B00C 7F0064DC 8E2F0000 */  lw    $t7, ($s1)
/* 03B010 7F0064E0 E5F40538 */  swc1  $f20, 0x538($t7)
/* 03B014 7F0064E4 8E380000 */  lw    $t8, ($s1)
/* 03B018 7F0064E8 E702053C */  swc1  $f2, 0x53c($t8)
/* 03B01C 7F0064EC 8E390000 */  lw    $t9, ($s1)
/* 03B020 7F0064F0 E7340540 */  swc1  $f20, 0x540($t9)
/* 03B024 7F0064F4 8E280000 */  lw    $t0, ($s1)
/* 03B028 7F0064F8 AD0204DC */  sw    $v0, 0x4dc($t0)
/* 03B02C 7F0064FC 8E290000 */  lw    $t1, ($s1)
/* 03B030 7F006500 AD2204E0 */  sw    $v0, 0x4e0($t1)
/* 03B034 7F006504 8E2A0000 */  lw    $t2, ($s1)
/* 03B038 7F006508 AD4204E4 */  sw    $v0, 0x4e4($t2)
/* 03B03C 7F00650C 8E2B0000 */  lw    $t3, ($s1)
/* 03B040 7F006510 E5740544 */  swc1  $f20, 0x544($t3)
/* 03B044 7F006514 8E2C0000 */  lw    $t4, ($s1)
/* 03B048 7F006518 E5940548 */  swc1  $f20, 0x548($t4)
/* 03B04C 7F00651C 8E2D0000 */  lw    $t5, ($s1)
/* 03B050 7F006520 E5B4054C */  swc1  $f20, 0x54c($t5)
/* 03B054 7F006524 8E2E0000 */  lw    $t6, ($s1)
/* 03B058 7F006528 E5D40550 */  swc1  $f20, 0x550($t6)
/* 03B05C 7F00652C 8E2F0000 */  lw    $t7, ($s1)
/* 03B060 7F006530 E5F40554 */  swc1  $f20, 0x554($t7)
/* 03B064 7F006534 8E380000 */  lw    $t8, ($s1)
/* 03B068 7F006538 E7140558 */  swc1  $f20, 0x558($t8)
/* 03B06C 7F00653C 8E390000 */  lw    $t9, ($s1)
/* 03B070 7F006540 E734055C */  swc1  $f20, 0x55c($t9)
/* 03B074 7F006544 8E280000 */  lw    $t0, ($s1)
/* 03B078 7F006548 E5140560 */  swc1  $f20, 0x560($t0)
/* 03B07C 7F00654C 8E290000 */  lw    $t1, ($s1)
/* 03B080 7F006550 E5340564 */  swc1  $f20, 0x564($t1)
/* 03B084 7F006554 8E2A0000 */  lw    $t2, ($s1)
/* 03B088 7F006558 E5540568 */  swc1  $f20, 0x568($t2)
/* 03B08C 7F00655C 8E2B0000 */  lw    $t3, ($s1)
/* 03B090 7F006560 E560056C */  swc1  $f0, 0x56c($t3)
/* 03B094 7F006564 8E2C0000 */  lw    $t4, ($s1)
/* 03B098 7F006568 E5940570 */  swc1  $f20, 0x570($t4)
/* 03B09C 7F00656C 8E2D0000 */  lw    $t5, ($s1)
/* 03B0A0 7F006570 E5B40574 */  swc1  $f20, 0x574($t5)
/* 03B0A4 7F006574 8E2E0000 */  lw    $t6, ($s1)
/* 03B0A8 7F006578 E5C00578 */  swc1  $f0, 0x578($t6)
/* 03B0AC 7F00657C 8E2F0000 */  lw    $t7, ($s1)
/* 03B0B0 7F006580 E5F4057C */  swc1  $f20, 0x57c($t7)
/* 03B0B4 7F006584 8E380000 */  lw    $t8, ($s1)
/* 03B0B8 7F006588 E7000580 */  swc1  $f0, 0x580($t8)
/* 03B0BC 7F00658C 8E390000 */  lw    $t9, ($s1)
/* 03B0C0 7F006590 E7340584 */  swc1  $f20, 0x584($t9)
/* 03B0C4 7F006594 8E280000 */  lw    $t0, ($s1)
/* 03B0C8 7F006598 E5140588 */  swc1  $f20, 0x588($t0)
/* 03B0CC 7F00659C 8E290000 */  lw    $t1, ($s1)
/* 03B0D0 7F0065A0 E520058C */  swc1  $f0, 0x58c($t1)
/* 03B0D4 7F0065A4 8E2A0000 */  lw    $t2, ($s1)
/* 03B0D8 7F0065A8 E5540590 */  swc1  $f20, 0x590($t2)
/* 03B0DC 7F0065AC 8E2B0000 */  lw    $t3, ($s1)
/* 03B0E0 7F0065B0 AD600594 */  sw    $zero, 0x594($t3)
.L7F0065B4:
/* 03B0E4 7F0065B4 C6060004 */  lwc1  $f6, 4($s0)
/* 03B0E8 7F0065B8 C60A0008 */  lwc1  $f10, 8($s0)
/* 03B0EC 7F0065BC 8E0C0000 */  lw    $t4, ($s0)
/* 03B0F0 7F0065C0 4600320D */  trunc.w.s $f8, $f6
/* 03B0F4 7F0065C4 8E8D0000 */  lw    $t5, ($s4)
/* 03B0F8 7F0065C8 02403825 */  move  $a3, $s2
/* 03B0FC 7F0065CC 4600540D */  trunc.w.s $f16, $f10
/* 03B100 7F0065D0 44054000 */  mfc1  $a1, $f8
/* 03B104 7F0065D4 018D2021 */  addu  $a0, $t4, $t5
/* 03B108 7F0065D8 44068000 */  mfc1  $a2, $f16
/* 03B10C 7F0065DC 0FC018B0 */  jal   sub_GAME_7F0062C0
/* 03B110 7F0065E0 00000000 */   nop   
/* 03B114 7F0065E4 8FB800D8 */  lw    $t8, 0xd8($sp)
/* 03B118 7F0065E8 C6120008 */  lwc1  $f18, 8($s0)
/* 03B11C 7F0065EC C6040004 */  lwc1  $f4, 4($s0)
/* 03B120 7F0065F0 44984000 */  mtc1  $t8, $f8
/* 03B124 7F0065F4 26100018 */  addiu $s0, $s0, 0x18
/* 03B128 7F0065F8 46049181 */  sub.s $f6, $f18, $f4
/* 03B12C 7F0065FC 468042A0 */  cvt.s.w $f10, $f8
/* 03B130 7F006600 46165402 */  mul.s $f16, $f10, $f22
/* 03B134 7F006604 46068483 */  div.s $f18, $f16, $f6
/* 03B138 7F006608 1613FFEA */  bne   $s0, $s3, .L7F0065B4
/* 03B13C 7F00660C E612FFF4 */   swc1  $f18, -0xc($s0)
/* 03B140 7F006610 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 03B144 7F006614 3C198003 */  lui   $t9, %hi(D_8002A790) 
/* 03B148 7F006618 27B20090 */  addiu $s2, $sp, 0x90
/* 03B14C 7F00661C 2739A790 */  addiu $t9, %lo(D_8002A790) # addiu $t9, $t9, -0x5870
/* 03B150 7F006620 4481B000 */  mtc1  $at, $f22
/* 03B154 7F006624 2729003C */  addiu $t1, $t9, 0x3c
/* 03B158 7F006628 02405025 */  move  $t2, $s2
.L7F00662C:
/* 03B15C 7F00662C 8F210000 */  lw    $at, ($t9)
/* 03B160 7F006630 2739000C */  addiu $t9, $t9, 0xc
/* 03B164 7F006634 254A000C */  addiu $t2, $t2, 0xc
/* 03B168 7F006638 AD41FFF4 */  sw    $at, -0xc($t2)
/* 03B16C 7F00663C 8F21FFF8 */  lw    $at, -8($t9)
/* 03B170 7F006640 AD41FFF8 */  sw    $at, -8($t2)
/* 03B174 7F006644 8F21FFFC */  lw    $at, -4($t9)
/* 03B178 7F006648 1729FFF8 */  bne   $t9, $t1, .L7F00662C
/* 03B17C 7F00664C AD41FFFC */   sw    $at, -4($t2)
/* 03B180 7F006650 8F210000 */  lw    $at, ($t9)
/* 03B184 7F006654 3C0C0000 */  lui   $t4, %hi(0x0000001C) # $t4, 0
/* 03B188 7F006658 258C001C */  addiu $t4, %lo(0x0000001C) # addiu $t4, $t4, 0x1c
/* 03B18C 7F00665C AD410000 */  sw    $at, ($t2)
/* 03B190 7F006660 8E8B0000 */  lw    $t3, ($s4)
/* 03B194 7F006664 8E240000 */  lw    $a0, ($s1)
/* 03B198 7F006668 4407A000 */  mfc1  $a3, $f20
/* 03B19C 7F00666C E7B40014 */  swc1  $f20, 0x14($sp)
/* 03B1A0 7F006670 E7B60010 */  swc1  $f22, 0x10($sp)
/* 03B1A4 7F006674 00003025 */  move  $a2, $zero
/* 03B1A8 7F006678 016C2821 */  addu  $a1, $t3, $t4
/* 03B1AC 7F00667C 0FC1BF2A */  jal   sub_GAME_7F06FCA8
/* 03B1B0 7F006680 24840598 */   addiu $a0, $a0, 0x598
/* 03B1B4 7F006684 8E240000 */  lw    $a0, ($s1)
/* 03B1B8 7F006688 0FC1B5AC */  jal   subcalcpos
/* 03B1BC 7F00668C 24840598 */   addiu $a0, $a0, 0x598
/* 03B1C0 7F006690 27B30050 */  addiu $s3, $sp, 0x50
/* 03B1C4 7F006694 0FC15FF4 */  jal   matrix_4x4_set_identity
/* 03B1C8 7F006698 02602025 */   move  $a0, $s3
/* 03B1CC 7F00669C 8E300000 */  lw    $s0, ($s1)
/* 03B1D0 7F0066A0 AFB30090 */  sw    $s3, 0x90($sp)
/* 03B1D4 7F0066A4 02402025 */  move  $a0, $s2
/* 03B1D8 7F0066A8 260D06D0 */  addiu $t5, $s0, 0x6d0
/* 03B1DC 7F0066AC AFAD00A0 */  sw    $t5, 0xa0($sp)
/* 03B1E0 7F0066B0 0FC1BCBE */  jal   subcalcmatrices
/* 03B1E4 7F0066B4 26050598 */   addiu $a1, $s0, 0x598
/* 03B1E8 7F0066B8 8E300000 */  lw    $s0, ($s1)
/* 03B1EC 7F0066BC 24130018 */  li    $s3, 24
/* 03B1F0 7F0066C0 3C128003 */  lui   $s2, %hi(D_80036AD0)
/* 03B1F4 7F0066C4 C6040704 */  lwc1  $f4, 0x704($s0)
/* 03B1F8 7F0066C8 26526AD0 */  addiu $s2, %lo(D_80036AD0) # addiu $s2, $s2, 0x6ad0
/* 03B1FC 7F0066CC 00003025 */  move  $a2, $zero
/* 03B200 7F0066D0 E6040550 */  swc1  $f4, 0x550($s0)
/* 03B204 7F0066D4 8E2E0000 */  lw    $t6, ($s1)
/* 03B208 7F0066D8 E5D40554 */  swc1  $f20, 0x554($t6)
/* 03B20C 7F0066DC 8E300000 */  lw    $s0, ($s1)
/* 03B210 7F0066E0 C6080744 */  lwc1  $f8, 0x744($s0)
/* 03B214 7F0066E4 C60A0704 */  lwc1  $f10, 0x704($s0)
/* 03B218 7F0066E8 460A4401 */  sub.s $f16, $f8, $f10
/* 03B21C 7F0066EC E6100558 */  swc1  $f16, 0x558($s0)
/* 03B220 7F0066F0 8E300000 */  lw    $s0, ($s1)
/* 03B224 7F0066F4 C6060748 */  lwc1  $f6, 0x748($s0)
/* 03B228 7F0066F8 C6120708 */  lwc1  $f18, 0x708($s0)
/* 03B22C 7F0066FC 46123101 */  sub.s $f4, $f6, $f18
/* 03B230 7F006700 E604055C */  swc1  $f4, 0x55c($s0)
/* 03B234 7F006704 8E300000 */  lw    $s0, ($s1)
/* 03B238 7F006708 8E890000 */  lw    $t1, ($s4)
/* 03B23C 7F00670C 8E0F04E8 */  lw    $t7, 0x4e8($s0)
/* 03B240 7F006710 E7B40014 */  swc1  $f20, 0x14($sp)
/* 03B244 7F006714 E7B60010 */  swc1  $f22, 0x10($sp)
/* 03B248 7F006718 01F30019 */  multu $t7, $s3
/* 03B24C 7F00671C 26040598 */  addiu $a0, $s0, 0x598
/* 03B250 7F006720 0000C012 */  mflo  $t8
/* 03B254 7F006724 02581021 */  addu  $v0, $s2, $t8
/* 03B258 7F006728 8C480000 */  lw    $t0, ($v0)
/* 03B25C 7F00672C 8C470004 */  lw    $a3, 4($v0)
/* 03B260 7F006730 0FC1BF2A */  jal   sub_GAME_7F06FCA8
/* 03B264 7F006734 01092821 */   addu  $a1, $t0, $t1
/* 03B268 7F006738 8E300000 */  lw    $s0, ($s1)
/* 03B26C 7F00673C 4406A000 */  mfc1  $a2, $f20
/* 03B270 7F006740 8E1904E8 */  lw    $t9, 0x4e8($s0)
/* 03B274 7F006744 26040598 */  addiu $a0, $s0, 0x598
/* 03B278 7F006748 03330019 */  multu $t9, $s3
/* 03B27C 7F00674C 00005012 */  mflo  $t2
/* 03B280 7F006750 024A5821 */  addu  $t3, $s2, $t2
/* 03B284 7F006754 0FC1BF73 */  jal   sub_GAME_7F06FDCC
/* 03B288 7F006758 8D650004 */   lw    $a1, 4($t3)
/* 03B28C 7F00675C 8E300000 */  lw    $s0, ($s1)
/* 03B290 7F006760 8E0C04E8 */  lw    $t4, 0x4e8($s0)
/* 03B294 7F006764 26040598 */  addiu $a0, $s0, 0x598
/* 03B298 7F006768 01930019 */  multu $t4, $s3
/* 03B29C 7F00676C 00006812 */  mflo  $t5
/* 03B2A0 7F006770 024D7021 */  addu  $t6, $s2, $t5
/* 03B2A4 7F006774 0FC1BF7A */  jal   sub_GAME_7F06FDE8
/* 03B2A8 7F006778 8DC50008 */   lw    $a1, 8($t6)
/* 03B2AC 7F00677C 8E240000 */  lw    $a0, ($s1)
/* 03B2B0 7F006780 3C057F09 */  lui   $a1, %hi(currentPlayerToggle5BC) # $a1, 0x7f09
/* 03B2B4 7F006784 24A5DBB0 */  addiu $a1, %lo(currentPlayerToggle5BC) # addiu $a1, $a1, -0x2450
/* 03B2B8 7F006788 0FC1BF8F */  jal   sub_GAME_7F06FE3C
/* 03B2BC 7F00678C 24840598 */   addiu $a0, $a0, 0x598
/* 03B2C0 7F006790 0FC236F2 */  jal   currentPlayerUpdateIdleHeadRoll
/* 03B2C4 7F006794 00000000 */   nop   
/* 03B2C8 7F006798 8FBF0044 */  lw    $ra, 0x44($sp)
/* 03B2CC 7F00679C D7B40020 */  ldc1  $f20, 0x20($sp)
/* 03B2D0 7F0067A0 D7B60028 */  ldc1  $f22, 0x28($sp)
/* 03B2D4 7F0067A4 8FB00030 */  lw    $s0, 0x30($sp)
/* 03B2D8 7F0067A8 8FB10034 */  lw    $s1, 0x34($sp)
/* 03B2DC 7F0067AC 8FB20038 */  lw    $s2, 0x38($sp)
/* 03B2E0 7F0067B0 8FB3003C */  lw    $s3, 0x3c($sp)
/* 03B2E4 7F0067B4 8FB40040 */  lw    $s4, 0x40($sp)
/* 03B2E8 7F0067B8 03E00008 */  jr    $ra
/* 03B2EC 7F0067BC 27BD00E0 */   addiu $sp, $sp, 0xe0
)
#endif

#ifdef VERSION_JP
GLOBAL_ASM(
.late_rodata
glabel D_8004F1F0
.word 0x3dccccce
glabel D_8004F1F4
.word 0x4164924b
glabel D_8004F1F8
.word 0x3f6e147b
.text
glabel sets_a_bunch_of_BONDdata_values_to_default
/* 03AEFC 7F00638C 27BDFF20 */  addiu $sp, $sp, -0xe0
/* 03AF00 7F006390 AFB20038 */  sw    $s2, 0x38($sp)
/* 03AF04 7F006394 3C128004 */  lui   $s2, %hi(player_gait_object) # $s2, 0x8004
/* 03AF08 7F006398 2652C680 */  addiu $s2, %lo(player_gait_object) # addiu $s2, $s2, -0x3980
/* 03AF0C 7F00639C 864E0014 */  lh    $t6, 0x14($s2)
/* 03AF10 7F0063A0 AFBF0044 */  sw    $ra, 0x44($sp)
/* 03AF14 7F0063A4 AFB40040 */  sw    $s4, 0x40($sp)
/* 03AF18 7F0063A8 29C1001F */  slti  $at, $t6, 0x1f
/* 03AF1C 7F0063AC AFB3003C */  sw    $s3, 0x3c($sp)
/* 03AF20 7F0063B0 AFB10034 */  sw    $s1, 0x34($sp)
/* 03AF24 7F0063B4 AFB00030 */  sw    $s0, 0x30($sp)
/* 03AF28 7F0063B8 F7B60028 */  sdc1  $f22, 0x28($sp)
/* 03AF2C 7F0063BC 14200003 */  bnez  $at, .L7F0063CC
/* 03AF30 7F0063C0 F7B40020 */   sdc1  $f20, 0x20($sp)
/* 03AF34 7F0063C4 0FC1B297 */  jal   return_null
/* 03AF38 7F0063C8 00000000 */   nop   
.L7F0063CC:
/* 03AF3C 7F0063CC 3C118008 */  lui   $s1, %hi(pPlayer) # $s1, 0x8008
/* 03AF40 7F0063D0 2631A120 */  addiu $s1, %lo(pPlayer) # addiu $s1, $s1, -0x5ee0
/* 03AF44 7F0063D4 8E300000 */  lw    $s0, ($s1)
/* 03AF48 7F0063D8 02402825 */  move  $a1, $s2
/* 03AF4C 7F0063DC 26040598 */  addiu $a0, $s0, 0x598
/* 03AF50 7F0063E0 0FC1D967 */  jal   sub_GAME_7F075FAC
/* 03AF54 7F0063E4 26060654 */   addiu $a2, $s0, 0x654
/* 03AF58 7F0063E8 3C018005 */  lui   $at, %hi(D_8004F1F0) # $at, 0x8005
/* 03AF5C 7F0063EC C436F220 */  lwc1  $f22, %lo(D_8004F1F0)($at)
/* 03AF60 7F0063F0 8E240000 */  lw    $a0, ($s1)
/* 03AF64 7F0063F4 4405B000 */  mfc1  $a1, $f22
/* 03AF68 7F0063F8 0FC1B51A */  jal   set_obj_instance_controller_scale
/* 03AF6C 7F0063FC 24840598 */   addiu $a0, $a0, 0x598
/* 03AF70 7F006400 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 03AF74 7F006404 44810000 */  mtc1  $at, $f0
/* 03AF78 7F006408 4480A000 */  mtc1  $zero, $f20
/* 03AF7C 7F00640C 8E240000 */  lw    $a0, ($s1)
/* 03AF80 7F006410 44050000 */  mfc1  $a1, $f0
/* 03AF84 7F006414 4406A000 */  mfc1  $a2, $f20
/* 03AF88 7F006418 0FC1C142 */  jal   sub_GAME_7F06FF18
/* 03AF8C 7F00641C 24840598 */   addiu $a0, $a0, 0x598
/* 03AF90 7F006420 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 03AF94 7F006424 44810000 */  mtc1  $at, $f0
/* 03AF98 7F006428 8E2F0000 */  lw    $t7, ($s1)
/* 03AF9C 7F00642C 3C018005 */  lui   $at, %hi(D_8004F1F4) # $at, 0x8005
/* 03AFA0 7F006430 C422F224 */  lwc1  $f2, %lo(D_8004F1F4)($at)
/* 03AFA4 7F006434 ADE004E8 */  sw    $zero, 0x4e8($t7)
/* 03AFA8 7F006438 3C018005 */  lui   $at, %hi(D_8004F1F8) # $at, 0x8005
/* 03AFAC 7F00643C C424F228 */  lwc1  $f4, %lo(D_8004F1F8)($at)
/* 03AFB0 7F006440 8E380000 */  lw    $t8, ($s1)
/* 03AFB4 7F006444 24020001 */  li    $v0, 1
/* 03AFB8 7F006448 3C108003 */  lui   $s0, %hi(D_80036AD0) # $s0, 0x8003
/* 03AFBC 7F00644C E70404EC */  swc1  $f4, 0x4ec($t8)
/* 03AFC0 7F006450 8E390000 */  lw    $t9, ($s1)
/* 03AFC4 7F006454 3C148007 */  lui   $s4, %hi(ptr_animation_table) # $s4, 0x8007
/* 03AFC8 7F006458 3C138003 */  lui   $s3, %hi(D_80036B00) # $s3, 0x8003
/* 03AFCC 7F00645C AF2004F0 */  sw    $zero, 0x4f0($t9)
/* 03AFD0 7F006460 8E280000 */  lw    $t0, ($s1)
/* 03AFD4 7F006464 26736B30 */  addiu $s3, %lo(D_80036B00) # addiu $s3, $s3, 0x6b30
/* 03AFD8 7F006468 26949578 */  addiu $s4, %lo(ptr_animation_table) # addiu $s4, $s4, -0x6a88
/* 03AFDC 7F00646C E50004F4 */  swc1  $f0, 0x4f4($t0)
/* 03AFE0 7F006470 8E290000 */  lw    $t1, ($s1)
/* 03AFE4 7F006474 26106B00 */  addiu $s0, %lo(D_80036AD0) # addiu $s0, $s0, 0x6b00
/* 03AFE8 7F006478 27B200D0 */  addiu $s2, $sp, 0xd0
/* 03AFEC 7F00647C E52004F8 */  swc1  $f0, 0x4f8($t1)
/* 03AFF0 7F006480 8E2A0000 */  lw    $t2, ($s1)
/* 03AFF4 7F006484 E55404FC */  swc1  $f20, 0x4fc($t2)
/* 03AFF8 7F006488 8E2B0000 */  lw    $t3, ($s1)
/* 03AFFC 7F00648C E5740500 */  swc1  $f20, 0x500($t3)
/* 03B000 7F006490 8E2C0000 */  lw    $t4, ($s1)
/* 03B004 7F006494 E5940504 */  swc1  $f20, 0x504($t4)
/* 03B008 7F006498 8E2D0000 */  lw    $t5, ($s1)
/* 03B00C 7F00649C E5B40508 */  swc1  $f20, 0x508($t5)
/* 03B010 7F0064A0 8E2E0000 */  lw    $t6, ($s1)
/* 03B014 7F0064A4 E5D4050C */  swc1  $f20, 0x50c($t6)
/* 03B018 7F0064A8 8E2F0000 */  lw    $t7, ($s1)
/* 03B01C 7F0064AC E5F40510 */  swc1  $f20, 0x510($t7)
/* 03B020 7F0064B0 8E380000 */  lw    $t8, ($s1)
/* 03B024 7F0064B4 E7140514 */  swc1  $f20, 0x514($t8)
/* 03B028 7F0064B8 8E390000 */  lw    $t9, ($s1)
/* 03B02C 7F0064BC E7340518 */  swc1  $f20, 0x518($t9)
/* 03B030 7F0064C0 8E280000 */  lw    $t0, ($s1)
/* 03B034 7F0064C4 E514051C */  swc1  $f20, 0x51c($t0)
/* 03B038 7F0064C8 8E290000 */  lw    $t1, ($s1)
/* 03B03C 7F0064CC E5340520 */  swc1  $f20, 0x520($t1)
/* 03B040 7F0064D0 8E2A0000 */  lw    $t2, ($s1)
/* 03B044 7F0064D4 E5540524 */  swc1  $f20, 0x524($t2)
/* 03B048 7F0064D8 8E2B0000 */  lw    $t3, ($s1)
/* 03B04C 7F0064DC E5740528 */  swc1  $f20, 0x528($t3)
/* 03B050 7F0064E0 8E2C0000 */  lw    $t4, ($s1)
/* 03B054 7F0064E4 E594052C */  swc1  $f20, 0x52c($t4)
/* 03B058 7F0064E8 8E2D0000 */  lw    $t5, ($s1)
/* 03B05C 7F0064EC E5B40530 */  swc1  $f20, 0x530($t5)
/* 03B060 7F0064F0 8E2E0000 */  lw    $t6, ($s1)
/* 03B064 7F0064F4 E5C20534 */  swc1  $f2, 0x534($t6)
/* 03B068 7F0064F8 8E2F0000 */  lw    $t7, ($s1)
/* 03B06C 7F0064FC E5F40538 */  swc1  $f20, 0x538($t7)
/* 03B070 7F006500 8E380000 */  lw    $t8, ($s1)
/* 03B074 7F006504 E702053C */  swc1  $f2, 0x53c($t8)
/* 03B078 7F006508 8E390000 */  lw    $t9, ($s1)
/* 03B07C 7F00650C E7340540 */  swc1  $f20, 0x540($t9)
/* 03B080 7F006510 8E280000 */  lw    $t0, ($s1)
/* 03B084 7F006514 AD0204DC */  sw    $v0, 0x4dc($t0)
/* 03B088 7F006518 8E290000 */  lw    $t1, ($s1)
/* 03B08C 7F00651C AD2204E0 */  sw    $v0, 0x4e0($t1)
/* 03B090 7F006520 8E2A0000 */  lw    $t2, ($s1)
/* 03B094 7F006524 AD4204E4 */  sw    $v0, 0x4e4($t2)
/* 03B098 7F006528 8E2B0000 */  lw    $t3, ($s1)
/* 03B09C 7F00652C E5740544 */  swc1  $f20, 0x544($t3)
/* 03B0A0 7F006530 8E2C0000 */  lw    $t4, ($s1)
/* 03B0A4 7F006534 E5940548 */  swc1  $f20, 0x548($t4)
/* 03B0A8 7F006538 8E2D0000 */  lw    $t5, ($s1)
/* 03B0AC 7F00653C E5B4054C */  swc1  $f20, 0x54c($t5)
/* 03B0B0 7F006540 8E2E0000 */  lw    $t6, ($s1)
/* 03B0B4 7F006544 E5D40550 */  swc1  $f20, 0x550($t6)
/* 03B0B8 7F006548 8E2F0000 */  lw    $t7, ($s1)
/* 03B0BC 7F00654C E5F40554 */  swc1  $f20, 0x554($t7)
/* 03B0C0 7F006550 8E380000 */  lw    $t8, ($s1)
/* 03B0C4 7F006554 E7140558 */  swc1  $f20, 0x558($t8)
/* 03B0C8 7F006558 8E390000 */  lw    $t9, ($s1)
/* 03B0CC 7F00655C E734055C */  swc1  $f20, 0x55c($t9)
/* 03B0D0 7F006560 8E280000 */  lw    $t0, ($s1)
/* 03B0D4 7F006564 E5140560 */  swc1  $f20, 0x560($t0)
/* 03B0D8 7F006568 8E290000 */  lw    $t1, ($s1)
/* 03B0DC 7F00656C E5340564 */  swc1  $f20, 0x564($t1)
/* 03B0E0 7F006570 8E2A0000 */  lw    $t2, ($s1)
/* 03B0E4 7F006574 E5540568 */  swc1  $f20, 0x568($t2)
/* 03B0E8 7F006578 8E2B0000 */  lw    $t3, ($s1)
/* 03B0EC 7F00657C E560056C */  swc1  $f0, 0x56c($t3)
/* 03B0F0 7F006580 8E2C0000 */  lw    $t4, ($s1)
/* 03B0F4 7F006584 E5940570 */  swc1  $f20, 0x570($t4)
/* 03B0F8 7F006588 8E2D0000 */  lw    $t5, ($s1)
/* 03B0FC 7F00658C E5B40574 */  swc1  $f20, 0x574($t5)
/* 03B100 7F006590 8E2E0000 */  lw    $t6, ($s1)
/* 03B104 7F006594 E5C00578 */  swc1  $f0, 0x578($t6)
/* 03B108 7F006598 8E2F0000 */  lw    $t7, ($s1)
/* 03B10C 7F00659C E5F4057C */  swc1  $f20, 0x57c($t7)
/* 03B110 7F0065A0 8E380000 */  lw    $t8, ($s1)
/* 03B114 7F0065A4 E7000580 */  swc1  $f0, 0x580($t8)
/* 03B118 7F0065A8 8E390000 */  lw    $t9, ($s1)
/* 03B11C 7F0065AC E7340584 */  swc1  $f20, 0x584($t9)
/* 03B120 7F0065B0 8E280000 */  lw    $t0, ($s1)
/* 03B124 7F0065B4 E5140588 */  swc1  $f20, 0x588($t0)
/* 03B128 7F0065B8 8E290000 */  lw    $t1, ($s1)
/* 03B12C 7F0065BC E520058C */  swc1  $f0, 0x58c($t1)
/* 03B130 7F0065C0 8E2A0000 */  lw    $t2, ($s1)
/* 03B134 7F0065C4 E5540590 */  swc1  $f20, 0x590($t2)
/* 03B138 7F0065C8 8E2B0000 */  lw    $t3, ($s1)
/* 03B13C 7F0065CC AD600594 */  sw    $zero, 0x594($t3)
.L7F0065D0:
/* 03B140 7F0065D0 C6060004 */  lwc1  $f6, 4($s0)
/* 03B144 7F0065D4 C60A0008 */  lwc1  $f10, 8($s0)
/* 03B148 7F0065D8 8E0C0000 */  lw    $t4, ($s0)
/* 03B14C 7F0065DC 4600320D */  trunc.w.s $f8, $f6
/* 03B150 7F0065E0 8E8D0000 */  lw    $t5, ($s4)
/* 03B154 7F0065E4 02403825 */  move  $a3, $s2
/* 03B158 7F0065E8 4600540D */  trunc.w.s $f16, $f10
/* 03B15C 7F0065EC 44054000 */  mfc1  $a1, $f8
/* 03B160 7F0065F0 018D2021 */  addu  $a0, $t4, $t5
/* 03B164 7F0065F4 44068000 */  mfc1  $a2, $f16
/* 03B168 7F0065F8 0FC018B0 */  jal   sub_GAME_7F0062C0
/* 03B16C 7F0065FC 00000000 */   nop   
/* 03B170 7F006600 8FB800D8 */  lw    $t8, 0xd8($sp)
/* 03B174 7F006604 C6120008 */  lwc1  $f18, 8($s0)
/* 03B178 7F006608 C6040004 */  lwc1  $f4, 4($s0)
/* 03B17C 7F00660C 44984000 */  mtc1  $t8, $f8
/* 03B180 7F006610 26100018 */  addiu $s0, $s0, 0x18
/* 03B184 7F006614 46049181 */  sub.s $f6, $f18, $f4
/* 03B188 7F006618 468042A0 */  cvt.s.w $f10, $f8
/* 03B18C 7F00661C 46165402 */  mul.s $f16, $f10, $f22
/* 03B190 7F006620 46068483 */  div.s $f18, $f16, $f6
/* 03B194 7F006624 1613FFEA */  bne   $s0, $s3, .L7F0065D0
/* 03B198 7F006628 E612FFF4 */   swc1  $f18, -0xc($s0)
/* 03B19C 7F00662C 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 03B1A0 7F006630 3C198003 */  lui   $t9, %hi(D_8002A790) # $t9, 0x8003
/* 03B1A4 7F006634 27B20090 */  addiu $s2, $sp, 0x90
/* 03B1A8 7F006638 2739A7D0 */  addiu $t9, %lo(D_8002A790) # addiu $t9, $t9, -0x5830
/* 03B1AC 7F00663C 4481B000 */  mtc1  $at, $f22
/* 03B1B0 7F006640 2729003C */  addiu $t1, $t9, 0x3c
/* 03B1B4 7F006644 02405025 */  move  $t2, $s2
.L7F006648:
/* 03B1B8 7F006648 8F210000 */  lw    $at, ($t9)
/* 03B1BC 7F00664C 2739000C */  addiu $t9, $t9, 0xc
/* 03B1C0 7F006650 254A000C */  addiu $t2, $t2, 0xc
/* 03B1C4 7F006654 AD41FFF4 */  sw    $at, -0xc($t2)
/* 03B1C8 7F006658 8F21FFF8 */  lw    $at, -8($t9)
/* 03B1CC 7F00665C AD41FFF8 */  sw    $at, -8($t2)
/* 03B1D0 7F006660 8F21FFFC */  lw    $at, -4($t9)
/* 03B1D4 7F006664 1729FFF8 */  bne   $t9, $t1, .L7F006648
/* 03B1D8 7F006668 AD41FFFC */   sw    $at, -4($t2)
/* 03B1DC 7F00666C 8F210000 */  lw    $at, ($t9)
/* 03B1E0 7F006670 3C0C0000 */  lui   $t4, %hi(0x0000001C) # $t4, 0
/* 03B1E4 7F006674 258C001C */  addiu $t4, %lo(0x0000001C) # addiu $t4, $t4, 0x1c
/* 03B1E8 7F006678 AD410000 */  sw    $at, ($t2)
/* 03B1EC 7F00667C 8E8B0000 */  lw    $t3, ($s4)
/* 03B1F0 7F006680 8E240000 */  lw    $a0, ($s1)
/* 03B1F4 7F006684 4407A000 */  mfc1  $a3, $f20
/* 03B1F8 7F006688 E7B40014 */  swc1  $f20, 0x14($sp)
/* 03B1FC 7F00668C E7B60010 */  swc1  $f22, 0x10($sp)
/* 03B200 7F006690 00003025 */  move  $a2, $zero
/* 03B204 7F006694 016C2821 */  addu  $a1, $t3, $t4
/* 03B208 7F006698 0FC1C0A6 */  jal   sub_GAME_7F06FCA8
/* 03B20C 7F00669C 24840598 */   addiu $a0, $a0, 0x598
/* 03B210 7F0066A0 8E240000 */  lw    $a0, ($s1)
/* 03B214 7F0066A4 0FC1B728 */  jal   subcalcpos
/* 03B218 7F0066A8 24840598 */   addiu $a0, $a0, 0x598
/* 03B21C 7F0066AC 27B30050 */  addiu $s3, $sp, 0x50
/* 03B220 7F0066B0 0FC1613C */  jal   matrix_4x4_set_identity
/* 03B224 7F0066B4 02602025 */   move  $a0, $s3
/* 03B228 7F0066B8 8E300000 */  lw    $s0, ($s1)
/* 03B22C 7F0066BC AFB30090 */  sw    $s3, 0x90($sp)
/* 03B230 7F0066C0 02402025 */  move  $a0, $s2
/* 03B234 7F0066C4 260D06D0 */  addiu $t5, $s0, 0x6d0
/* 03B238 7F0066C8 AFAD00A0 */  sw    $t5, 0xa0($sp)
/* 03B23C 7F0066CC 0FC1BE3A */  jal   subcalcmatrices
/* 03B240 7F0066D0 26050598 */   addiu $a1, $s0, 0x598
/* 03B244 7F0066D4 8E300000 */  lw    $s0, ($s1)
/* 03B248 7F0066D8 24130018 */  li    $s3, 24
/* 03B24C 7F0066DC 3C128003 */  lui   $s2, %hi(D_80036AD0) # $s2, 0x8003
/* 03B250 7F0066E0 C6040704 */  lwc1  $f4, 0x704($s0)
/* 03B254 7F0066E4 26526B00 */  addiu $s2, %lo(D_80036AD0) # addiu $s2, $s2, 0x6b00
/* 03B258 7F0066E8 00003025 */  move  $a2, $zero
/* 03B25C 7F0066EC E6040550 */  swc1  $f4, 0x550($s0)
/* 03B260 7F0066F0 8E2E0000 */  lw    $t6, ($s1)
/* 03B264 7F0066F4 E5D40554 */  swc1  $f20, 0x554($t6)
/* 03B268 7F0066F8 8E300000 */  lw    $s0, ($s1)
/* 03B26C 7F0066FC C6080744 */  lwc1  $f8, 0x744($s0)
/* 03B270 7F006700 C60A0704 */  lwc1  $f10, 0x704($s0)
/* 03B274 7F006704 460A4401 */  sub.s $f16, $f8, $f10
/* 03B278 7F006708 E6100558 */  swc1  $f16, 0x558($s0)
/* 03B27C 7F00670C 8E300000 */  lw    $s0, ($s1)
/* 03B280 7F006710 C6060748 */  lwc1  $f6, 0x748($s0)
/* 03B284 7F006714 C6120708 */  lwc1  $f18, 0x708($s0)
/* 03B288 7F006718 46123101 */  sub.s $f4, $f6, $f18
/* 03B28C 7F00671C E604055C */  swc1  $f4, 0x55c($s0)
/* 03B290 7F006720 8E300000 */  lw    $s0, ($s1)
/* 03B294 7F006724 8E890000 */  lw    $t1, ($s4)
/* 03B298 7F006728 8E0F04E8 */  lw    $t7, 0x4e8($s0)
/* 03B29C 7F00672C E7B40014 */  swc1  $f20, 0x14($sp)
/* 03B2A0 7F006730 E7B60010 */  swc1  $f22, 0x10($sp)
/* 03B2A4 7F006734 01F30019 */  multu $t7, $s3
/* 03B2A8 7F006738 26040598 */  addiu $a0, $s0, 0x598
/* 03B2AC 7F00673C 0000C012 */  mflo  $t8
/* 03B2B0 7F006740 02581021 */  addu  $v0, $s2, $t8
/* 03B2B4 7F006744 8C480000 */  lw    $t0, ($v0)
/* 03B2B8 7F006748 8C470004 */  lw    $a3, 4($v0)
/* 03B2BC 7F00674C 0FC1C0A6 */  jal   sub_GAME_7F06FCA8
/* 03B2C0 7F006750 01092821 */   addu  $a1, $t0, $t1
/* 03B2C4 7F006754 8E300000 */  lw    $s0, ($s1)
/* 03B2C8 7F006758 4406A000 */  mfc1  $a2, $f20
/* 03B2CC 7F00675C 8E1904E8 */  lw    $t9, 0x4e8($s0)
/* 03B2D0 7F006760 26040598 */  addiu $a0, $s0, 0x598
/* 03B2D4 7F006764 03330019 */  multu $t9, $s3
/* 03B2D8 7F006768 00005012 */  mflo  $t2
/* 03B2DC 7F00676C 024A5821 */  addu  $t3, $s2, $t2
/* 03B2E0 7F006770 0FC1C0EF */  jal   sub_GAME_7F06FDCC
/* 03B2E4 7F006774 8D650004 */   lw    $a1, 4($t3)
/* 03B2E8 7F006778 8E300000 */  lw    $s0, ($s1)
/* 03B2EC 7F00677C 8E0C04E8 */  lw    $t4, 0x4e8($s0)
/* 03B2F0 7F006780 26040598 */  addiu $a0, $s0, 0x598
/* 03B2F4 7F006784 01930019 */  multu $t4, $s3
/* 03B2F8 7F006788 00006812 */  mflo  $t5
/* 03B2FC 7F00678C 024D7021 */  addu  $t6, $s2, $t5
/* 03B300 7F006790 0FC1C0F6 */  jal   sub_GAME_7F06FDE8
/* 03B304 7F006794 8DC50008 */   lw    $a1, 8($t6)
/* 03B308 7F006798 8E240000 */  lw    $a0, ($s1)
/* 03B30C 7F00679C 3C057F09 */  lui   $a1, %hi(currentPlayerToggle5BC) # $a1, 0x7f09
/* 03B310 7F0067A0 24A5E690 */  addiu $a1, %lo(currentPlayerToggle5BC) # addiu $a1, $a1, -0x1970
/* 03B314 7F0067A4 0FC1C10B */  jal   sub_GAME_7F06FE3C
/* 03B318 7F0067A8 24840598 */   addiu $a0, $a0, 0x598
/* 03B31C 7F0067AC 0FC239AA */  jal   currentPlayerUpdateIdleHeadRoll
/* 03B320 7F0067B0 00000000 */   nop   
/* 03B324 7F0067B4 8FBF0044 */  lw    $ra, 0x44($sp)
/* 03B328 7F0067B8 D7B40020 */  ldc1  $f20, 0x20($sp)
/* 03B32C 7F0067BC D7B60028 */  ldc1  $f22, 0x28($sp)
/* 03B330 7F0067C0 8FB00030 */  lw    $s0, 0x30($sp)
/* 03B334 7F0067C4 8FB10034 */  lw    $s1, 0x34($sp)
/* 03B338 7F0067C8 8FB20038 */  lw    $s2, 0x38($sp)
/* 03B33C 7F0067CC 8FB3003C */  lw    $s3, 0x3c($sp)
/* 03B340 7F0067D0 8FB40040 */  lw    $s4, 0x40($sp)
/* 03B344 7F0067D4 03E00008 */  jr    $ra
/* 03B348 7F0067D8 27BD00E0 */   addiu $sp, $sp, 0xe0
)
#endif

#endif

