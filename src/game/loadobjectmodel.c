#include "ultra64.h"

#ifdef NONMATCHING
void sub_GAME_7F056850(void) {

}
#else
GLOBAL_ASM(
.late_rodata
/*D:80053490*/
glabel jpt_object_setup_size
.word object_size_type_01
.word object_size_type_02
.word object_size_type_03
.word object_size_type_04
.word object_size_type_05
.word object_size_type_06
.word object_size_type_07
.word object_size_type_08
.word object_size_type_09
.word object_size_type_0A
.word object_size_type_0B
.word object_size_type_0C
.word object_size_type_0D
/*.word object_size_type_0E*/
/*.word object_size_type_default*/
/*.word object_size_type_default*/
.text
glabel sub_GAME_7F056850
/* 08B380 7F056850 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 08B384 7F056854 AFBF002C */  sw    $ra, 0x2c($sp)
/* 08B388 7F056858 AFB00028 */  sw    $s0, 0x28($sp)
/* 08B38C 7F05685C C4840000 */  lwc1  $f4, ($a0)
/* 08B390 7F056860 44866000 */  mtc1  $a2, $f12
/* 08B394 7F056864 00E08025 */  move  $s0, $a3
/* 08B398 7F056868 E4E40000 */  swc1  $f4, ($a3)
/* 08B39C 7F05686C C4860004 */  lwc1  $f6, 4($a0)
/* 08B3A0 7F056870 E4E60004 */  swc1  $f6, 4($a3)
/* 08B3A4 7F056874 C4880008 */  lwc1  $f8, 8($a0)
/* 08B3A8 7F056878 E4E80008 */  swc1  $f8, 8($a3)
/* 08B3AC 7F05687C 8FAE0040 */  lw    $t6, 0x40($sp)
/* 08B3B0 7F056880 14A00003 */  bnez  $a1, .L7F056890
/* 08B3B4 7F056884 ADC50000 */   sw    $a1, ($t6)
/* 08B3B8 7F056888 10000015 */  b     .L7F0568E0
/* 08B3BC 7F05688C 00001025 */   move  $v0, $zero
.L7F056890:
/* 08B3C0 7F056890 44800000 */  mtc1  $zero, $f0
/* 08B3C4 7F056894 8FA40040 */  lw    $a0, 0x40($sp)
/* 08B3C8 7F056898 240F001F */  li    $t7, 31
/* 08B3CC 7F05689C 460C003C */  c.lt.s $f0, $f12
/* 08B3D0 7F0568A0 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 08B3D4 7F0568A4 4502000E */  bc1fl .L7F0568E0
/* 08B3D8 7F0568A8 24020001 */   li    $v0, 1
/* 08B3DC 7F0568AC 44815000 */  mtc1  $at, $f10
/* 08B3E0 7F0568B0 8E050000 */  lw    $a1, ($s0)
/* 08B3E4 7F0568B4 8E060008 */  lw    $a2, 8($s0)
/* 08B3E8 7F0568B8 44076000 */  mfc1  $a3, $f12
/* 08B3EC 7F0568BC E7A00014 */  swc1  $f0, 0x14($sp)
/* 08B3F0 7F0568C0 AFAF0010 */  sw    $t7, 0x10($sp)
/* 08B3F4 7F0568C4 0FC2C62E */  jal   sub_GAME_7F0B18B8
/* 08B3F8 7F0568C8 E7AA0018 */   swc1  $f10, 0x18($sp)
/* 08B3FC 7F0568CC 04420004 */  bltzl $v0, .L7F0568E0
/* 08B400 7F0568D0 24020001 */   li    $v0, 1
/* 08B404 7F0568D4 10000002 */  b     .L7F0568E0
/* 08B408 7F0568D8 00001025 */   move  $v0, $zero
/* 08B40C 7F0568DC 24020001 */  li    $v0, 1
.L7F0568E0:
/* 08B410 7F0568E0 8FBF002C */  lw    $ra, 0x2c($sp)
/* 08B414 7F0568E4 8FB00028 */  lw    $s0, 0x28($sp)
/* 08B418 7F0568E8 27BD0030 */  addiu $sp, $sp, 0x30
/* 08B41C 7F0568EC 03E00008 */  jr    $ra
/* 08B420 7F0568F0 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
s16 get_size_of_setup_object_type(void) {

}
#else
GLOBAL_ASM(
.late_rodata
/*D:80053490*/
/*glabel jpt_object_setup_size*/
/*.word object_size_type_01*/
/*.word object_size_type_02*/
/*.word object_size_type_03*/
/*.word object_size_type_04*/
/*.word object_size_type_05*/
/*.word object_size_type_06*/
/*.word object_size_type_07*/
/*.word object_size_type_08*/
/*.word object_size_type_09*/
/*.word object_size_type_0A*/
/*.word object_size_type_0B*/
/*.word object_size_type_0C*/
/*.word object_size_type_0D*/
.word object_size_type_0E
.word object_size_type_default
.word object_size_type_default
.word object_size_type_11
.word object_size_type_12
.word object_size_type_13
.word object_size_type_14
.word object_size_type_15
.word object_size_type_16
.word object_size_type_17
.word object_size_type_18
.word object_size_type_19
.word object_size_type_1A
.word object_size_type_1B
.word object_size_type_1C
.word object_size_type_1D
.word object_size_type_1E
.word object_size_type_1F
.word object_size_type_20
.word object_size_type_21
.word object_size_type_22
.word object_size_type_23
.word object_size_type_24
.word object_size_type_25
.word object_size_type_26
.word object_size_type_27
.word object_size_type_28
.word object_size_type_default
.word object_size_type_2A
.word object_size_type_2B
.word object_size_type_2C
.word object_size_type_2D
.word object_size_type_2E
/*.word object_size_type_2F*/

.text
glabel get_size_of_setup_object_type
/* 08B424 7F0568F4 908E0003 */  lbu   $t6, 3($a0)
/* 08B428 7F0568F8 25CFFFFF */  addiu $t7, $t6, -1
/* 08B42C 7F0568FC 2DE1002F */  sltiu $at, $t7, 0x2f
/* 08B430 7F056900 1020005E */  beqz  $at, .L7F056A7C
/* 08B434 7F056904 000F7880 */   sll   $t7, $t7, 2
/* 08B438 7F056908 3C018005 */  lui   $at, %hi(jpt_object_setup_size)
/* 08B43C 7F05690C 002F0821 */  addu  $at, $at, $t7
/* 08B440 7F056910 8C2F3490 */  lw    $t7, %lo(jpt_object_setup_size)($at)
/* 08B444 7F056914 01E00008 */  jr    $t7
/* 08B448 7F056918 00000000 */   nop   
object_size_type_09:
/* 08B44C 7F05691C 03E00008 */  jr    $ra
/* 08B450 7F056920 24020007 */   li    $v0, 7

object_size_type_01:
/* 08B454 7F056924 03E00008 */  jr    $ra
/* 08B458 7F056928 24020040 */   li    $v0, 64

object_size_type_02:
/* 08B45C 7F05692C 03E00008 */  jr    $ra
/* 08B460 7F056930 24020002 */   li    $v0, 2

object_size_type_03:
/* 08B464 7F056934 03E00008 */  jr    $ra
/* 08B468 7F056938 24020020 */   li    $v0, 32

object_size_type_2A:
/* 08B46C 7F05693C 03E00008 */  jr    $ra
/* 08B470 7F056940 24020020 */   li    $v0, 32

object_size_type_2F:
/* 08B474 7F056944 03E00008 */  jr    $ra
/* 08B478 7F056948 24020025 */   li    $v0, 37

object_size_type_2B:
/* 08B47C 7F05694C 03E00008 */  jr    $ra
/* 08B480 7F056950 24020020 */   li    $v0, 32

object_size_type_24:
/* 08B484 7F056954 03E00008 */  jr    $ra
/* 08B488 7F056958 24020020 */   li    $v0, 32

object_size_type_04:
/* 08B48C 7F05695C 03E00008 */  jr    $ra
/* 08B490 7F056960 24020021 */   li    $v0, 33

object_size_type_05:
/* 08B494 7F056964 03E00008 */  jr    $ra
/* 08B498 7F056968 24020020 */   li    $v0, 32

object_size_type_06:
/* 08B49C 7F05696C 03E00008 */  jr    $ra
/* 08B4A0 7F056970 2402003B */   li    $v0, 59

object_size_type_07:
/* 08B4A4 7F056974 03E00008 */  jr    $ra
/* 08B4A8 7F056978 24020021 */   li    $v0, 33

object_size_type_08:
/* 08B4AC 7F05697C 03E00008 */  jr    $ra
/* 08B4B0 7F056980 24020022 */   li    $v0, 34

object_size_type_0A:
/* 08B4B4 7F056984 03E00008 */  jr    $ra
/* 08B4B8 7F056988 24020040 */   li    $v0, 64

object_size_type_0B:
/* 08B4BC 7F05698C 03E00008 */  jr    $ra
/* 08B4C0 7F056990 24020095 */   li    $v0, 149

object_size_type_0C:
/* 08B4C4 7F056994 03E00008 */  jr    $ra
/* 08B4C8 7F056998 24020020 */   li    $v0, 32

object_size_type_0D:
/* 08B4CC 7F05699C 03E00008 */  jr    $ra
/* 08B4D0 7F0569A0 24020036 */   li    $v0, 54

object_size_type_0E:
/* 08B4D4 7F0569A4 03E00008 */  jr    $ra
/* 08B4D8 7F0569A8 24020003 */   li    $v0, 3

object_size_type_11:
/* 08B4DC 7F0569AC 03E00008 */  jr    $ra
/* 08B4E0 7F0569B0 24020020 */   li    $v0, 32

object_size_type_12:
/* 08B4E4 7F0569B4 03E00008 */  jr    $ra
/* 08B4E8 7F0569B8 24020003 */   li    $v0, 3

object_size_type_13:
/* 08B4EC 7F0569BC 03E00008 */  jr    $ra
/* 08B4F0 7F0569C0 24020004 */   li    $v0, 4

object_size_type_2C:
/* 08B4F4 7F0569C4 03E00008 */  jr    $ra
/* 08B4F8 7F0569C8 24020005 */   li    $v0, 5

object_size_type_14:
/* 08B4FC 7F0569CC 03E00008 */  jr    $ra
/* 08B500 7F0569D0 2402002D */   li    $v0, 45

object_size_type_15:
/* 08B504 7F0569D4 03E00008 */  jr    $ra
/* 08B508 7F0569D8 24020022 */   li    $v0, 34

object_size_type_16:
/* 08B50C 7F0569DC 03E00008 */  jr    $ra
/* 08B510 7F0569E0 24020004 */   li    $v0, 4

object_size_type_25:
/* 08B514 7F0569E4 03E00008 */  jr    $ra
/* 08B518 7F0569E8 2402000A */   li    $v0, 10

object_size_type_17:
/* 08B51C 7F0569EC 03E00008 */  jr    $ra
/* 08B520 7F0569F0 24020004 */   li    $v0, 4

object_size_type_18:
/* 08B524 7F0569F4 03E00008 */  jr    $ra
/* 08B528 7F0569F8 24020001 */   li    $v0, 1

object_size_type_19:
/* 08B52C 7F0569FC 03E00008 */  jr    $ra
/* 08B530 7F056A00 24020002 */   li    $v0, 2

object_size_type_1A:
/* 08B534 7F056A04 03E00008 */  jr    $ra
/* 08B538 7F056A08 24020002 */   li    $v0, 2

object_size_type_1B:
/* 08B53C 7F056A0C 03E00008 */  jr    $ra
/* 08B540 7F056A10 24020002 */   li    $v0, 2

object_size_type_1C:
/* 08B544 7F056A14 03E00008 */  jr    $ra
/* 08B548 7F056A18 24020002 */   li    $v0, 2

object_size_type_1D:
/* 08B54C 7F056A1C 03E00008 */  jr    $ra
/* 08B550 7F056A20 24020002 */   li    $v0, 2

object_size_type_1E:
/* 08B554 7F056A24 03E00008 */  jr    $ra
/* 08B558 7F056A28 24020004 */   li    $v0, 4

object_size_type_1F:
/* 08B55C 7F056A2C 03E00008 */  jr    $ra
/* 08B560 7F056A30 24020001 */   li    $v0, 1

object_size_type_20:
/* 08B564 7F056A34 03E00008 */  jr    $ra
/* 08B568 7F056A38 24020004 */   li    $v0, 4

object_size_type_21:
/* 08B56C 7F056A3C 03E00008 */  jr    $ra
/* 08B570 7F056A40 24020005 */   li    $v0, 5

object_size_type_22:
/* 08B574 7F056A44 03E00008 */  jr    $ra
/* 08B578 7F056A48 24020001 */   li    $v0, 1

object_size_type_23:
/* 08B57C 7F056A4C 03E00008 */  jr    $ra
/* 08B580 7F056A50 24020004 */   li    $v0, 4

object_size_type_26:
/* 08B584 7F056A54 03E00008 */  jr    $ra
/* 08B588 7F056A58 24020004 */   li    $v0, 4

object_size_type_27:
/* 08B58C 7F056A5C 03E00008 */  jr    $ra
/* 08B590 7F056A60 2402002C */   li    $v0, 44

object_size_type_28:
/* 08B594 7F056A64 03E00008 */  jr    $ra
/* 08B598 7F056A68 2402002D */   li    $v0, 45

object_size_type_2D:
/* 08B59C 7F056A6C 03E00008 */  jr    $ra
/* 08B5A0 7F056A70 24020038 */   li    $v0, 56

object_size_type_2E:
/* 08B5A4 7F056A74 03E00008 */  jr    $ra
/* 08B5A8 7F056A78 24020007 */   li    $v0, 7

object_size_type_default:
.L7F056A7C:
/* 08B5AC 7F056A7C 24020001 */  li    $v0, 1
/* 08B5B0 7F056A80 03E00008 */  jr    $ra
/* 08B5B4 7F056A84 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F056A88(void) {

}
#else
GLOBAL_ASM(
.late_rodata
/*hack for above*/
.word object_size_type_2F

.text
glabel sub_GAME_7F056A88
/* 08B5B8 7F056A88 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 08B5BC 7F056A8C AFB10018 */  sw    $s1, 0x18($sp)
/* 08B5C0 7F056A90 AFB30020 */  sw    $s3, 0x20($sp)
/* 08B5C4 7F056A94 3C118007 */  lui   $s1, %hi(ptr_setup_objects)
/* 08B5C8 7F056A98 00809825 */  move  $s3, $a0
/* 08B5CC 7F056A9C AFBF0024 */  sw    $ra, 0x24($sp)
/* 08B5D0 7F056AA0 AFB2001C */  sw    $s2, 0x1c($sp)
/* 08B5D4 7F056AA4 AFB00014 */  sw    $s0, 0x14($sp)
/* 08B5D8 7F056AA8 04800014 */  bltz  $a0, .L7F056AFC
/* 08B5DC 7F056AAC 8E315D0C */   lw    $s1, %lo(ptr_setup_objects)($s1)
/* 08B5E0 7F056AB0 52200013 */  beql  $s1, $zero, .L7F056B00
/* 08B5E4 7F056AB4 00001025 */   move  $v0, $zero
/* 08B5E8 7F056AB8 922E0003 */  lbu   $t6, 3($s1)
/* 08B5EC 7F056ABC 24120030 */  li    $s2, 48
/* 08B5F0 7F056AC0 00008025 */  move  $s0, $zero
/* 08B5F4 7F056AC4 524E000E */  beql  $s2, $t6, .L7F056B00
/* 08B5F8 7F056AC8 00001025 */   move  $v0, $zero
.L7F056ACC:
/* 08B5FC 7F056ACC 16130003 */  bne   $s0, $s3, .L7F056ADC
/* 08B600 7F056AD0 00000000 */   nop   
/* 08B604 7F056AD4 1000000A */  b     .L7F056B00
/* 08B608 7F056AD8 02201025 */   move  $v0, $s1
.L7F056ADC:
/* 08B60C 7F056ADC 0FC15A3D */  jal   get_size_of_setup_object_type
/* 08B610 7F056AE0 02202025 */   move  $a0, $s1
/* 08B614 7F056AE4 00027880 */  sll   $t7, $v0, 2
/* 08B618 7F056AE8 01F18821 */  addu  $s1, $t7, $s1
/* 08B61C 7F056AEC 92380003 */  lbu   $t8, 3($s1)
/* 08B620 7F056AF0 26100001 */  addiu $s0, $s0, 1
/* 08B624 7F056AF4 1658FFF5 */  bne   $s2, $t8, .L7F056ACC
/* 08B628 7F056AF8 00000000 */   nop   
.L7F056AFC:
/* 08B62C 7F056AFC 00001025 */  move  $v0, $zero
.L7F056B00:
/* 08B630 7F056B00 8FBF0024 */  lw    $ra, 0x24($sp)
/* 08B634 7F056B04 8FB00014 */  lw    $s0, 0x14($sp)
/* 08B638 7F056B08 8FB10018 */  lw    $s1, 0x18($sp)
/* 08B63C 7F056B0C 8FB2001C */  lw    $s2, 0x1c($sp)
/* 08B640 7F056B10 8FB30020 */  lw    $s3, 0x20($sp)
/* 08B644 7F056B14 03E00008 */  jr    $ra
/* 08B648 7F056B18 27BD0028 */   addiu $sp, $sp, 0x28
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F056B1C(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F056B1C
/* 08B64C 7F056B1C 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 08B650 7F056B20 AFB00014 */  sw    $s0, 0x14($sp)
/* 08B654 7F056B24 3C108007 */  lui   $s0, %hi(ptr_setup_objects)
/* 08B658 7F056B28 8E105D0C */  lw    $s0, %lo(ptr_setup_objects)($s0)
/* 08B65C 7F056B2C AFB30020 */  sw    $s3, 0x20($sp)
/* 08B660 7F056B30 00809825 */  move  $s3, $a0
/* 08B664 7F056B34 AFBF0024 */  sw    $ra, 0x24($sp)
/* 08B668 7F056B38 AFB2001C */  sw    $s2, 0x1c($sp)
/* 08B66C 7F056B3C 12000012 */  beqz  $s0, .L7F056B88
/* 08B670 7F056B40 AFB10018 */   sw    $s1, 0x18($sp)
/* 08B674 7F056B44 920E0003 */  lbu   $t6, 3($s0)
/* 08B678 7F056B48 24120030 */  li    $s2, 48
/* 08B67C 7F056B4C 00008825 */  move  $s1, $zero
/* 08B680 7F056B50 524E000E */  beql  $s2, $t6, .L7F056B8C
/* 08B684 7F056B54 2402FFFF */   li    $v0, -1
.L7F056B58:
/* 08B688 7F056B58 16130003 */  bne   $s0, $s3, .L7F056B68
/* 08B68C 7F056B5C 00000000 */   nop   
/* 08B690 7F056B60 1000000A */  b     .L7F056B8C
/* 08B694 7F056B64 02201025 */   move  $v0, $s1
.L7F056B68:
/* 08B698 7F056B68 0FC15A3D */  jal   get_size_of_setup_object_type
/* 08B69C 7F056B6C 02002025 */   move  $a0, $s0
/* 08B6A0 7F056B70 00027880 */  sll   $t7, $v0, 2
/* 08B6A4 7F056B74 01F08021 */  addu  $s0, $t7, $s0
/* 08B6A8 7F056B78 92180003 */  lbu   $t8, 3($s0)
/* 08B6AC 7F056B7C 26310001 */  addiu $s1, $s1, 1
/* 08B6B0 7F056B80 1658FFF5 */  bne   $s2, $t8, .L7F056B58
/* 08B6B4 7F056B84 00000000 */   nop   
.L7F056B88:
/* 08B6B8 7F056B88 2402FFFF */  li    $v0, -1
.L7F056B8C:
/* 08B6BC 7F056B8C 8FBF0024 */  lw    $ra, 0x24($sp)
/* 08B6C0 7F056B90 8FB00014 */  lw    $s0, 0x14($sp)
/* 08B6C4 7F056B94 8FB10018 */  lw    $s1, 0x18($sp)
/* 08B6C8 7F056B98 8FB2001C */  lw    $s2, 0x1c($sp)
/* 08B6CC 7F056B9C 8FB30020 */  lw    $s3, 0x20($sp)
/* 08B6D0 7F056BA0 03E00008 */  jr    $ra
/* 08B6D4 7F056BA4 27BD0028 */   addiu $sp, $sp, 0x28
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F056BA8(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F056BA8
/* 08B6D8 7F056BA8 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 08B6DC 7F056BAC AFB00014 */  sw    $s0, 0x14($sp)
/* 08B6E0 7F056BB0 3C108007 */  lui   $s0, %hi(ptr_setup_objects)
/* 08B6E4 7F056BB4 8E105D0C */  lw    $s0, %lo(ptr_setup_objects)($s0)
/* 08B6E8 7F056BB8 AFB30020 */  sw    $s3, 0x20($sp)
/* 08B6EC 7F056BBC 00809825 */  move  $s3, $a0
/* 08B6F0 7F056BC0 AFBF0024 */  sw    $ra, 0x24($sp)
/* 08B6F4 7F056BC4 AFB2001C */  sw    $s2, 0x1c($sp)
/* 08B6F8 7F056BC8 12000013 */  beqz  $s0, .L7F056C18
/* 08B6FC 7F056BCC AFB10018 */   sw    $s1, 0x18($sp)
/* 08B700 7F056BD0 920E0003 */  lbu   $t6, 3($s0)
/* 08B704 7F056BD4 24120030 */  li    $s2, 48
/* 08B708 7F056BD8 00008825 */  move  $s1, $zero
/* 08B70C 7F056BDC 524E000F */  beql  $s2, $t6, .L7F056C1C
/* 08B710 7F056BE0 2402FFFF */   li    $v0, -1
/* 08B714 7F056BE4 8E0F0010 */  lw    $t7, 0x10($s0)
.L7F056BE8:
/* 08B718 7F056BE8 166F0003 */  bne   $s3, $t7, .L7F056BF8
/* 08B71C 7F056BEC 00000000 */   nop   
/* 08B720 7F056BF0 1000000A */  b     .L7F056C1C
/* 08B724 7F056BF4 02201025 */   move  $v0, $s1
.L7F056BF8:
/* 08B728 7F056BF8 0FC15A3D */  jal   get_size_of_setup_object_type
/* 08B72C 7F056BFC 02002025 */   move  $a0, $s0
/* 08B730 7F056C00 0002C080 */  sll   $t8, $v0, 2
/* 08B734 7F056C04 03108021 */  addu  $s0, $t8, $s0
/* 08B738 7F056C08 92190003 */  lbu   $t9, 3($s0)
/* 08B73C 7F056C0C 26310001 */  addiu $s1, $s1, 1
/* 08B740 7F056C10 5659FFF5 */  bnel  $s2, $t9, .L7F056BE8
/* 08B744 7F056C14 8E0F0010 */   lw    $t7, 0x10($s0)
.L7F056C18:
/* 08B748 7F056C18 2402FFFF */  li    $v0, -1
.L7F056C1C:
/* 08B74C 7F056C1C 8FBF0024 */  lw    $ra, 0x24($sp)
/* 08B750 7F056C20 8FB00014 */  lw    $s0, 0x14($sp)
/* 08B754 7F056C24 8FB10018 */  lw    $s1, 0x18($sp)
/* 08B758 7F056C28 8FB2001C */  lw    $s2, 0x1c($sp)
/* 08B75C 7F056C2C 8FB30020 */  lw    $s3, 0x20($sp)
/* 08B760 7F056C30 03E00008 */  jr    $ra
/* 08B764 7F056C34 27BD0028 */   addiu $sp, $sp, 0x28
)
#endif





#ifdef NONMATCHING
void load_model(void) {

}
#else
GLOBAL_ASM(
.text
glabel load_model
/* 08B768 7F056C38 00047080 */  sll   $t6, $a0, 2
/* 08B76C 7F056C3C 01C47023 */  subu  $t6, $t6, $a0
/* 08B770 7F056C40 3C0F8004 */  lui   $t7, %hi(PitemZ_entries) 
/* 08B774 7F056C44 25EFA228 */  addiu $t7, %lo(PitemZ_entries) # addiu $t7, $t7, -0x5dd8
/* 08B778 7F056C48 000E7080 */  sll   $t6, $t6, 2
/* 08B77C 7F056C4C 01CF1021 */  addu  $v0, $t6, $t7
/* 08B780 7F056C50 8C460000 */  lw    $a2, ($v0)
/* 08B784 7F056C54 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 08B788 7F056C58 AFBF0014 */  sw    $ra, 0x14($sp)
/* 08B78C 7F056C5C 8CD80000 */  lw    $t8, ($a2)
/* 08B790 7F056C60 00C02025 */  move  $a0, $a2
/* 08B794 7F056C64 5700000A */  bnezl $t8, .L7F056C90
/* 08B798 7F056C68 00001025 */   move  $v0, $zero
/* 08B79C 7F056C6C 8C450004 */  lw    $a1, 4($v0)
/* 08B7A0 7F056C70 0FC1D953 */  jal   load_object_into_memory
/* 08B7A4 7F056C74 AFA2001C */   sw    $v0, 0x1c($sp)
/* 08B7A8 7F056C78 8FA2001C */  lw    $v0, 0x1c($sp)
/* 08B7AC 7F056C7C 0FC1D73D */  jal   set_objuse_flag_compute_grp_nums_set_obj_loaded
/* 08B7B0 7F056C80 8C440000 */   lw    $a0, ($v0)
/* 08B7B4 7F056C84 10000002 */  b     .L7F056C90
/* 08B7B8 7F056C88 24020001 */   li    $v0, 1
/* 08B7BC 7F056C8C 00001025 */  move  $v0, $zero
.L7F056C90:
/* 08B7C0 7F056C90 8FBF0014 */  lw    $ra, 0x14($sp)
/* 08B7C4 7F056C94 27BD0020 */  addiu $sp, $sp, 0x20
/* 08B7C8 7F056C98 03E00008 */  jr    $ra
/* 08B7CC 7F056C9C 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F056CA0(void) {

}
#else
GLOBAL_ASM(
.late_rodata
/*hack for below*/
glabel jpt_8005354C
.word .L7F056EE4
.word .L7F056EEC
.word .L7F056EE4
.word .L7F056EE4
.word .L7F056EE4
.word .L7F056EE4
.word .L7F056EE4
.word .L7F056EE4
.word .L7F056EEC
.word .L7F056EE4
.word .L7F056EE4
.word .L7F056EE4
.word .L7F056EE4
.word .L7F056EEC
.word .L7F056EF4
.word .L7F056EF4
.word .L7F056EE4
.word .L7F056EEC
.word .L7F056EEC
.word .L7F056EE4
.word .L7F056EE4
.word .L7F056EEC
.word .L7F056EEC
.word .L7F056EEC
.word .L7F056EEC
.word .L7F056EEC
.word .L7F056EEC
.word .L7F056EEC
.word .L7F056EEC
.word .L7F056EEC
.word .L7F056EEC
.word .L7F056EEC
.word .L7F056EEC
.word .L7F056EEC
.word .L7F056EEC
.word .L7F056EE4
.word .L7F056EEC
.word .L7F056EEC
.word .L7F056EE4

.text
glabel sub_GAME_7F056CA0
/* 08B7D0 7F056CA0 27BDFFB0 */  addiu $sp, $sp, -0x50
/* 08B7D4 7F056CA4 AFBF0024 */  sw    $ra, 0x24($sp)
/* 08B7D8 7F056CA8 AFB10020 */  sw    $s1, 0x20($sp)
/* 08B7DC 7F056CAC AFB0001C */  sw    $s0, 0x1c($sp)
/* 08B7E0 7F056CB0 F7B40010 */  sdc1  $f20, 0x10($sp)
/* 08B7E4 7F056CB4 8C910010 */  lw    $s1, 0x10($a0)
/* 08B7E8 7F056CB8 00808025 */  move  $s0, $a0
/* 08B7EC 7F056CBC 4480A000 */  mtc1  $zero, $f20
/* 08B7F0 7F056CC0 0FC0F863 */  jal   sub_GAME_7F03E18C
/* 08B7F4 7F056CC4 02202025 */   move  $a0, $s1
/* 08B7F8 7F056CC8 8E0E000C */  lw    $t6, 0xc($s0)
/* 08B7FC 7F056CCC 000E7B80 */  sll   $t7, $t6, 0xe
/* 08B800 7F056CD0 05E1000C */  bgez  $t7, .L7F056D04
/* 08B804 7F056CD4 00000000 */   nop   
/* 08B808 7F056CD8 8E220014 */  lw    $v0, 0x14($s1)
/* 08B80C 7F056CDC 241900FF */  li    $t9, 255
/* 08B810 7F056CE0 240800FF */  li    $t0, 255
/* 08B814 7F056CE4 10400005 */  beqz  $v0, .L7F056CFC
/* 08B818 7F056CE8 00000000 */   nop   
/* 08B81C 7F056CEC 90580003 */  lbu   $t8, 3($v0)
/* 08B820 7F056CF0 A239002D */  sb    $t9, 0x2d($s1)
/* 08B824 7F056CF4 10000062 */  b     .L7F056E80
/* 08B828 7F056CF8 A238002C */   sb    $t8, 0x2c($s1)
.L7F056CFC:
/* 08B82C 7F056CFC 10000060 */  b     .L7F056E80
/* 08B830 7F056D00 A228002C */   sb    $t0, 0x2c($s1)
.L7F056D04:
/* 08B834 7F056D04 0FC1001E */  jal   sub_GAME_7F040078
/* 08B838 7F056D08 02002025 */   move  $a0, $s0
/* 08B83C 7F056D0C 1040005C */  beqz  $v0, .L7F056E80
/* 08B840 7F056D10 00402025 */   move  $a0, $v0
/* 08B844 7F056D14 26050018 */  addiu $a1, $s0, 0x18
/* 08B848 7F056D18 AFA50028 */  sw    $a1, 0x28($sp)
/* 08B84C 7F056D1C 0FC0FA1F */  jal   sub_GAME_7F03E87C
/* 08B850 7F056D20 AFA20030 */   sw    $v0, 0x30($sp)
/* 08B854 7F056D24 3C0141F0 */  li    $at, 0x41F00000 # 30.000000
/* 08B858 7F056D28 44812000 */  mtc1  $at, $f4
/* 08B85C 7F056D2C 8FA40030 */  lw    $a0, 0x30($sp)
/* 08B860 7F056D30 8FA50028 */  lw    $a1, 0x28($sp)
/* 08B864 7F056D34 46040181 */  sub.s $f6, $f0, $f4
/* 08B868 7F056D38 0FC0FA6F */  jal   sub_GAME_7F03E9BC
/* 08B86C 7F056D3C E7A60040 */   swc1  $f6, 0x40($sp)
/* 08B870 7F056D40 E7A00044 */  swc1  $f0, 0x44($sp)
/* 08B874 7F056D44 8FA40030 */  lw    $a0, 0x30($sp)
/* 08B878 7F056D48 0FC0FABF */  jal   sub_GAME_7F03EAFC
/* 08B87C 7F056D4C 8FA50028 */   lw    $a1, 0x28($sp)
/* 08B880 7F056D50 3C0141F0 */  li    $at, 0x41F00000 # 30.000000
/* 08B884 7F056D54 44814000 */  mtc1  $at, $f8
/* 08B888 7F056D58 8FA40030 */  lw    $a0, 0x30($sp)
/* 08B88C 7F056D5C 8FA50028 */  lw    $a1, 0x28($sp)
/* 08B890 7F056D60 46080281 */  sub.s $f10, $f0, $f8
/* 08B894 7F056D64 0FC0FA47 */  jal   sub_GAME_7F03E91C
/* 08B898 7F056D68 E7AA0048 */   swc1  $f10, 0x48($sp)
/* 08B89C 7F056D6C 3C0141F0 */  li    $at, 0x41F00000 # 30.000000
/* 08B8A0 7F056D70 44818000 */  mtc1  $at, $f16
/* 08B8A4 7F056D74 8FA40030 */  lw    $a0, 0x30($sp)
/* 08B8A8 7F056D78 8FA50028 */  lw    $a1, 0x28($sp)
/* 08B8AC 7F056D7C 46100480 */  add.s $f18, $f0, $f16
/* 08B8B0 7F056D80 0FC0FA97 */  jal   sub_GAME_7F03EA5C
/* 08B8B4 7F056D84 E7B20034 */   swc1  $f18, 0x34($sp)
/* 08B8B8 7F056D88 E7A00038 */  swc1  $f0, 0x38($sp)
/* 08B8BC 7F056D8C 8FA40030 */  lw    $a0, 0x30($sp)
/* 08B8C0 7F056D90 0FC0FAE7 */  jal   sub_GAME_7F03EB9C
/* 08B8C4 7F056D94 8FA50028 */   lw    $a1, 0x28($sp)
/* 08B8C8 7F056D98 C7A20040 */  lwc1  $f2, 0x40($sp)
/* 08B8CC 7F056D9C 44803000 */  mtc1  $zero, $f6
/* 08B8D0 7F056DA0 3C0141F0 */  li    $at, 0x41F00000 # 30.000000
/* 08B8D4 7F056DA4 46001087 */  neg.s $f2, $f2
/* 08B8D8 7F056DA8 44812000 */  mtc1  $at, $f4
/* 08B8DC 7F056DAC 4602303C */  c.lt.s $f6, $f2
/* 08B8E0 7F056DB0 C7A80034 */  lwc1  $f8, 0x34($sp)
/* 08B8E4 7F056DB4 46040300 */  add.s $f12, $f0, $f4
/* 08B8E8 7F056DB8 C7A00048 */  lwc1  $f0, 0x48($sp)
/* 08B8EC 7F056DBC 45020003 */  bc1fl .L7F056DCC
/* 08B8F0 7F056DC0 46000007 */   neg.s $f0, $f0
/* 08B8F4 7F056DC4 46001506 */  mov.s $f20, $f2
/* 08B8F8 7F056DC8 46000007 */  neg.s $f0, $f0
.L7F056DCC:
/* 08B8FC 7F056DCC 4600A03C */  c.lt.s $f20, $f0
/* 08B900 7F056DD0 00000000 */  nop   
/* 08B904 7F056DD4 45020003 */  bc1fl .L7F056DE4
/* 08B908 7F056DD8 4608A03C */   c.lt.s $f20, $f8
/* 08B90C 7F056DDC 46000506 */  mov.s $f20, $f0
/* 08B910 7F056DE0 4608A03C */  c.lt.s $f20, $f8
.L7F056DE4:
/* 08B914 7F056DE4 00000000 */  nop   
/* 08B918 7F056DE8 45020003 */  bc1fl .L7F056DF8
/* 08B91C 7F056DEC 460CA03C */   c.lt.s $f20, $f12
/* 08B920 7F056DF0 46004506 */  mov.s $f20, $f8
/* 08B924 7F056DF4 460CA03C */  c.lt.s $f20, $f12
.L7F056DF8:
/* 08B928 7F056DF8 E7AC003C */  swc1  $f12, 0x3c($sp)
/* 08B92C 7F056DFC 45020004 */  bc1fl .L7F056E10
/* 08B930 7F056E00 C7AA0040 */   lwc1  $f10, 0x40($sp)
/* 08B934 7F056E04 46006506 */  mov.s $f20, $f12
/* 08B938 7F056E08 E7AC003C */  swc1  $f12, 0x3c($sp)
/* 08B93C 7F056E0C C7AA0040 */  lwc1  $f10, 0x40($sp)
.L7F056E10:
/* 08B940 7F056E10 C6100058 */  lwc1  $f16, 0x58($s0)
/* 08B944 7F056E14 C7A40044 */  lwc1  $f4, 0x44($sp)
/* 08B948 7F056E18 4407A000 */  mfc1  $a3, $f20
/* 08B94C 7F056E1C 46105480 */  add.s $f18, $f10, $f16
/* 08B950 7F056E20 C7AA0048 */  lwc1  $f10, 0x48($sp)
/* 08B954 7F056E24 02202025 */  move  $a0, $s1
/* 08B958 7F056E28 27A50040 */  addiu $a1, $sp, 0x40
/* 08B95C 7F056E2C E7B20040 */  swc1  $f18, 0x40($sp)
/* 08B960 7F056E30 C606005C */  lwc1  $f6, 0x5c($s0)
/* 08B964 7F056E34 27A60034 */  addiu $a2, $sp, 0x34
/* 08B968 7F056E38 46062200 */  add.s $f8, $f4, $f6
/* 08B96C 7F056E3C C7A40034 */  lwc1  $f4, 0x34($sp)
/* 08B970 7F056E40 E7A80044 */  swc1  $f8, 0x44($sp)
/* 08B974 7F056E44 C6100060 */  lwc1  $f16, 0x60($s0)
/* 08B978 7F056E48 46105480 */  add.s $f18, $f10, $f16
/* 08B97C 7F056E4C C7AA0038 */  lwc1  $f10, 0x38($sp)
/* 08B980 7F056E50 E7B20048 */  swc1  $f18, 0x48($sp)
/* 08B984 7F056E54 C6060058 */  lwc1  $f6, 0x58($s0)
/* 08B988 7F056E58 46062200 */  add.s $f8, $f4, $f6
/* 08B98C 7F056E5C C7A4003C */  lwc1  $f4, 0x3c($sp)
/* 08B990 7F056E60 E7A80034 */  swc1  $f8, 0x34($sp)
/* 08B994 7F056E64 C610005C */  lwc1  $f16, 0x5c($s0)
/* 08B998 7F056E68 46105480 */  add.s $f18, $f10, $f16
/* 08B99C 7F056E6C E7B20038 */  swc1  $f18, 0x38($sp)
/* 08B9A0 7F056E70 C6060060 */  lwc1  $f6, 0x60($s0)
/* 08B9A4 7F056E74 46062200 */  add.s $f8, $f4, $f6
/* 08B9A8 7F056E78 0FC0F89F */  jal   sub_GAME_7F03E27C
/* 08B9AC 7F056E7C E7A8003C */   swc1  $f8, 0x3c($sp)
.L7F056E80:
/* 08B9B0 7F056E80 0FC0F884 */  jal   sub_GAME_7F03E210
/* 08B9B4 7F056E84 02202025 */   move  $a0, $s1
/* 08B9B8 7F056E88 8FBF0024 */  lw    $ra, 0x24($sp)
/* 08B9BC 7F056E8C D7B40010 */  ldc1  $f20, 0x10($sp)
/* 08B9C0 7F056E90 8FB0001C */  lw    $s0, 0x1c($sp)
/* 08B9C4 7F056E94 8FB10020 */  lw    $s1, 0x20($sp)
/* 08B9C8 7F056E98 03E00008 */  jr    $ra
/* 08B9CC 7F056E9C 27BD0050 */   addiu $sp, $sp, 0x50
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F056EA0(void) {

}
#else
GLOBAL_ASM(
.late_rodata
/*D:8005354C*/
/*glabel jpt_8005354C*/
/*.word .L7F056EE4*/
/*.word .L7F056EEC*/
/*.word .L7F056EE4*/
/*.word .L7F056EE4*/
/*.word .L7F056EE4*/
/*.word .L7F056EE4*/
/*.word .L7F056EE4*/
/*.word .L7F056EE4*/
/*.word .L7F056EEC*/
/*.word .L7F056EE4*/
/*.word .L7F056EE4*/
/*.word .L7F056EE4*/
/*.word .L7F056EE4*/
/*.word .L7F056EEC*/
/*.word .L7F056EDC*/
/*.word .L7F056EDC*/
/*.word .L7F056EE4*/
/*.word .L7F056EEC*/
/*.word .L7F056EEC*/
/*.word .L7F056EE4*/
/*.word .L7F056EE4*/
/*.word .L7F056EEC*/
/*.word .L7F056EEC*/
/*.word .L7F056EEC*/
/*.word .L7F056EEC*/
/*.word .L7F056EEC*/
/*.word .L7F056EEC*/
/*.word .L7F056EEC*/
/*.word .L7F056EEC*/
/*.word .L7F056EEC*/
/*.word .L7F056EEC*/
/*.word .L7F056EEC*/
/*.word .L7F056EEC*/
/*.word .L7F056EEC*/
/*.word .L7F056EEC*/
/*.word .L7F056EE4*/
/*.word .L7F056EEC*/
/*.word .L7F056EEC*/
/*.word .L7F056EE4*/
.word .L7F056EE4
.word .L7F056EE4
.word .L7F056EE4
.word .L7F056EE4
.word .L7F056EEC
.word .L7F056EE4
.word .L7F056EEC
.word .L7F056EE4

/*D:80053608                     .align 4*/
.text
glabel sub_GAME_7F056EA0
/* 08B9D0 7F056EA0 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 08B9D4 7F056EA4 AFBF0014 */  sw    $ra, 0x14($sp)
/* 08B9D8 7F056EA8 AFA40018 */  sw    $a0, 0x18($sp)
/* 08B9DC 7F056EAC 0FC15AA2 */  jal   sub_GAME_7F056A88
/* 08B9E0 7F056EB0 00A02025 */   move  $a0, $a1
/* 08B9E4 7F056EB4 1040000F */  beqz  $v0, .L7F056EF4
/* 08B9E8 7F056EB8 00401825 */   move  $v1, $v0
/* 08B9EC 7F056EBC 904E0003 */  lbu   $t6, 3($v0)
/* 08B9F0 7F056EC0 25CFFFFF */  addiu $t7, $t6, -1
/* 08B9F4 7F056EC4 2DE1002F */  sltiu $at, $t7, 0x2f
/* 08B9F8 7F056EC8 1020000A */  beqz  $at, .L7F056EF4
/* 08B9FC 7F056ECC 000F7880 */   sll   $t7, $t7, 2
/* 08BA00 7F056ED0 3C018005 */  lui   $at, %hi(jpt_8005354C)
/* 08BA04 7F056ED4 002F0821 */  addu  $at, $at, $t7
/* 08BA08 7F056ED8 8C2F354C */  lw    $t7, %lo(jpt_8005354C)($at)
.L7F056EDC:
/* 08BA0C 7F056EDC 01E00008 */  jr    $t7
/* 08BA10 7F056EE0 00000000 */   nop   
.L7F056EE4:
/* 08BA14 7F056EE4 10000004 */  b     .L7F056EF8
/* 08BA18 7F056EE8 00601025 */   move  $v0, $v1
.L7F056EEC:
/* 08BA1C 7F056EEC 10000002 */  b     .L7F056EF8
/* 08BA20 7F056EF0 00001025 */   move  $v0, $zero
def_7F056EDC:
.L7F056EF4:
/* 08BA24 7F056EF4 00601025 */  move  $v0, $v1
.L7F056EF8:
/* 08BA28 7F056EF8 8FBF0014 */  lw    $ra, 0x14($sp)
/* 08BA2C 7F056EFC 27BD0018 */  addiu $sp, $sp, 0x18
/* 08BA30 7F056F00 03E00008 */  jr    $ra
/* 08BA34 7F056F04 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F056F08(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F056F08
/* 08BA38 7F056F08 27BDFFC0 */  addiu $sp, $sp, -0x40
/* 08BA3C 7F056F0C AFB00018 */  sw    $s0, 0x18($sp)
/* 08BA40 7F056F10 3C108007 */  lui   $s0, %hi(ptr_setup_objects)
/* 08BA44 7F056F14 8E105D0C */  lw    $s0, %lo(ptr_setup_objects)($s0)
/* 08BA48 7F056F18 AFBE0038 */  sw    $fp, 0x38($sp)
/* 08BA4C 7F056F1C AFB70034 */  sw    $s7, 0x34($sp)
/* 08BA50 7F056F20 AFB30024 */  sw    $s3, 0x24($sp)
/* 08BA54 7F056F24 AFB20020 */  sw    $s2, 0x20($sp)
/* 08BA58 7F056F28 0080B825 */  move  $s7, $a0
/* 08BA5C 7F056F2C 00E0F025 */  move  $fp, $a3
/* 08BA60 7F056F30 AFBF003C */  sw    $ra, 0x3c($sp)
/* 08BA64 7F056F34 AFB60030 */  sw    $s6, 0x30($sp)
/* 08BA68 7F056F38 AFB5002C */  sw    $s5, 0x2c($sp)
/* 08BA6C 7F056F3C AFB40028 */  sw    $s4, 0x28($sp)
/* 08BA70 7F056F40 AFB1001C */  sw    $s1, 0x1c($sp)
/* 08BA74 7F056F44 AFA50044 */  sw    $a1, 0x44($sp)
/* 08BA78 7F056F48 AFA60048 */  sw    $a2, 0x48($sp)
/* 08BA7C 7F056F4C 00009025 */  move  $s2, $zero
/* 08BA80 7F056F50 12000039 */  beqz  $s0, .L7F057038
/* 08BA84 7F056F54 00009825 */   move  $s3, $zero
/* 08BA88 7F056F58 92030003 */  lbu   $v1, 3($s0)
/* 08BA8C 7F056F5C 24010030 */  li    $at, 48
/* 08BA90 7F056F60 309400FF */  andi  $s4, $a0, 0xff
/* 08BA94 7F056F64 10610034 */  beq   $v1, $at, .L7F057038
/* 08BA98 7F056F68 24160008 */   li    $s6, 8
/* 08BA9C 7F056F6C 8FB50054 */  lw    $s5, 0x54($sp)
/* 08BAA0 7F056F70 8FB10050 */  lw    $s1, 0x50($sp)
.L7F056F74:
/* 08BAA4 7F056F74 16830028 */  bne   $s4, $v1, .L7F057018
/* 08BAA8 7F056F78 00000000 */   nop   
/* 08BAAC 7F056F7C 8E020010 */  lw    $v0, 0x10($s0)
/* 08BAB0 7F056F80 14400007 */  bnez  $v0, .L7F056FA0
/* 08BAB4 7F056F84 00000000 */   nop   
/* 08BAB8 7F056F88 17C00023 */  bnez  $fp, .L7F057018
/* 08BABC 7F056F8C 00000000 */   nop   
/* 08BAC0 7F056F90 16200021 */  bnez  $s1, .L7F057018
/* 08BAC4 7F056F94 00000000 */   nop   
/* 08BAC8 7F056F98 1000002C */  b     .L7F05704C
/* 08BACC 7F056F9C 02001025 */   move  $v0, $s0
.L7F056FA0:
/* 08BAD0 7F056FA0 12F6001D */  beq   $s7, $s6, .L7F057018
/* 08BAD4 7F056FA4 00000000 */   nop   
/* 08BAD8 7F056FA8 8E0E0064 */  lw    $t6, 0x64($s0)
/* 08BADC 7F056FAC 31CF0080 */  andi  $t7, $t6, 0x80
/* 08BAE0 7F056FB0 15E00019 */  bnez  $t7, .L7F057018
/* 08BAE4 7F056FB4 00000000 */   nop   
/* 08BAE8 7F056FB8 92180002 */  lbu   $t8, 2($s0)
/* 08BAEC 7F056FBC 33190004 */  andi  $t9, $t8, 4
/* 08BAF0 7F056FC0 17200015 */  bnez  $t9, .L7F057018
/* 08BAF4 7F056FC4 00000000 */   nop   
/* 08BAF8 7F056FC8 8C48001C */  lw    $t0, 0x1c($v0)
/* 08BAFC 7F056FCC 15000012 */  bnez  $t0, .L7F057018
/* 08BB00 7F056FD0 00000000 */   nop   
/* 08BB04 7F056FD4 12200005 */  beqz  $s1, .L7F056FEC
/* 08BB08 7F056FD8 02A02825 */   move  $a1, $s5
/* 08BB0C 7F056FDC 0FC1B018 */  jal   sub_GAME_7F06C060
/* 08BB10 7F056FE0 8E040014 */   lw    $a0, 0x14($s0)
/* 08BB14 7F056FE4 1040000C */  beqz  $v0, .L7F057018
/* 08BB18 7F056FE8 00000000 */   nop   
.L7F056FEC:
/* 08BB1C 7F056FEC 16400007 */  bnez  $s2, .L7F05700C
/* 08BB20 7F056FF0 00000000 */   nop   
/* 08BB24 7F056FF4 8E090010 */  lw    $t1, 0x10($s0)
/* 08BB28 7F056FF8 912A0001 */  lbu   $t2, 1($t1)
/* 08BB2C 7F056FFC 314B0002 */  andi  $t3, $t2, 2
/* 08BB30 7F057000 15600002 */  bnez  $t3, .L7F05700C
/* 08BB34 7F057004 00000000 */   nop   
/* 08BB38 7F057008 02009025 */  move  $s2, $s0
.L7F05700C:
/* 08BB3C 7F05700C 16600002 */  bnez  $s3, .L7F057018
/* 08BB40 7F057010 00000000 */   nop   
/* 08BB44 7F057014 02009825 */  move  $s3, $s0
.L7F057018:
/* 08BB48 7F057018 0FC15A3D */  jal   get_size_of_setup_object_type
/* 08BB4C 7F05701C 02002025 */   move  $a0, $s0
/* 08BB50 7F057020 00026080 */  sll   $t4, $v0, 2
/* 08BB54 7F057024 01908021 */  addu  $s0, $t4, $s0
/* 08BB58 7F057028 92030003 */  lbu   $v1, 3($s0)
/* 08BB5C 7F05702C 24010030 */  li    $at, 48
/* 08BB60 7F057030 1461FFD0 */  bne   $v1, $at, .L7F056F74
/* 08BB64 7F057034 00000000 */   nop   
.L7F057038:
/* 08BB68 7F057038 8FAD0044 */  lw    $t5, 0x44($sp)
/* 08BB6C 7F05703C 00001025 */  move  $v0, $zero
/* 08BB70 7F057040 ADB20000 */  sw    $s2, ($t5)
/* 08BB74 7F057044 8FAE0048 */  lw    $t6, 0x48($sp)
/* 08BB78 7F057048 ADD30000 */  sw    $s3, ($t6)
.L7F05704C:
/* 08BB7C 7F05704C 8FBF003C */  lw    $ra, 0x3c($sp)
/* 08BB80 7F057050 8FB00018 */  lw    $s0, 0x18($sp)
/* 08BB84 7F057054 8FB1001C */  lw    $s1, 0x1c($sp)
/* 08BB88 7F057058 8FB20020 */  lw    $s2, 0x20($sp)
/* 08BB8C 7F05705C 8FB30024 */  lw    $s3, 0x24($sp)
/* 08BB90 7F057060 8FB40028 */  lw    $s4, 0x28($sp)
/* 08BB94 7F057064 8FB5002C */  lw    $s5, 0x2c($sp)
/* 08BB98 7F057068 8FB60030 */  lw    $s6, 0x30($sp)
/* 08BB9C 7F05706C 8FB70034 */  lw    $s7, 0x34($sp)
/* 08BBA0 7F057070 8FBE0038 */  lw    $fp, 0x38($sp)
/* 08BBA4 7F057074 03E00008 */  jr    $ra
/* 08BBA8 7F057078 27BD0040 */   addiu $sp, $sp, 0x40
)
#endif



