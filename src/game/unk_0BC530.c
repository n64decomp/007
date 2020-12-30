#include "ultra64.h"
#include "game/unk_093880.h"

// bss
char dword_CODE_bss_80083320[0x130];
char dword_CODE_bss_80083450[0x4B0];
char dword_CODE_bss_80083900[0x4B0];
char dword_CODE_bss_80083DB0[0x4B00];



#ifdef NONMATCHING
void sub_GAME_7F0BC530(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0BC530
/* 0F1060 7F0BC530 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 0F1064 7F0BC534 AFBF0024 */  sw    $ra, 0x24($sp)
/* 0F1068 7F0BC538 AFB00018 */  sw    $s0, 0x18($sp)
/* 0F106C 7F0BC53C AFB20020 */  sw    $s2, 0x20($sp)
/* 0F1070 7F0BC540 AFB1001C */  sw    $s1, 0x1c($sp)
/* 0F1074 7F0BC544 0FC26919 */  jal   getPlayerCount
/* 0F1078 7F0BC548 00008025 */   move  $s0, $zero
/* 0F107C 7F0BC54C 1840000D */  blez  $v0, .L7F0BC584
/* 0F1080 7F0BC550 00107080 */   sll   $t6, $s0, 2
/* 0F1084 7F0BC554 3C0F8008 */  lui   $t7, %hi(players) 
/* 0F1088 7F0BC558 25EF9EE0 */  addiu $t7, %lo(players) # addiu $t7, $t7, -0x6120
/* 0F108C 7F0BC55C 01CF8821 */  addu  $s1, $t6, $t7
/* 0F1090 7F0BC560 2412FFFF */  li    $s2, -1
/* 0F1094 7F0BC564 8E380000 */  lw    $t8, ($s1)
.L7F0BC568:
/* 0F1098 7F0BC568 26100001 */  addiu $s0, $s0, 1
/* 0F109C 7F0BC56C 26310004 */  addiu $s1, $s1, 4
/* 0F10A0 7F0BC570 0FC26919 */  jal   getPlayerCount
/* 0F10A4 7F0BC574 AF12108C */   sw    $s2, 0x108c($t8)
/* 0F10A8 7F0BC578 0202082A */  slt   $at, $s0, $v0
/* 0F10AC 7F0BC57C 5420FFFA */  bnezl $at, .L7F0BC568
/* 0F10B0 7F0BC580 8E380000 */   lw    $t8, ($s1)
.L7F0BC584:
/* 0F10B4 7F0BC584 3C038008 */  lui   $v1, %hi(dword_CODE_bss_80083450)
/* 0F10B8 7F0BC588 3C048008 */  lui   $a0, %hi(dword_CODE_bss_80083320)
/* 0F10BC 7F0BC58C 3C028008 */  lui   $v0, %hi(dword_CODE_bss_80083900)
/* 0F10C0 7F0BC590 3C068008 */  lui   $a2, %hi(dword_CODE_bss_80083DB0)
/* 0F10C4 7F0BC594 2412FFFF */  li    $s2, -1
/* 0F10C8 7F0BC598 24C63DB0 */  addiu $a2, %lo(dword_CODE_bss_80083DB0) # addiu $a2, $a2, 0x3db0
/* 0F10CC 7F0BC59C 24423900 */  addiu $v0, %lo(dword_CODE_bss_80083900) # addiu $v0, $v0, 0x3900
/* 0F10D0 7F0BC5A0 24843320 */  addiu $a0, %lo(dword_CODE_bss_80083320) # addiu $a0, $a0, 0x3320
/* 0F10D4 7F0BC5A4 24633450 */  addiu $v1, %lo(dword_CODE_bss_80083450) # addiu $v1, $v1, 0x3450
/* 0F10D8 7F0BC5A8 24050002 */  li    $a1, 2
.L7F0BC5AC:
/* 0F10DC 7F0BC5AC 24420004 */  addiu $v0, $v0, 4
/* 0F10E0 7F0BC5B0 0046082B */  sltu  $at, $v0, $a2
/* 0F10E4 7F0BC5B4 24630004 */  addiu $v1, $v1, 4
/* 0F10E8 7F0BC5B8 24840001 */  addiu $a0, $a0, 1
/* 0F10EC 7F0BC5BC AC72FFFC */  sw    $s2, -4($v1)
/* 0F10F0 7F0BC5C0 A085FFFF */  sb    $a1, -1($a0)
/* 0F10F4 7F0BC5C4 1420FFF9 */  bnez  $at, .L7F0BC5AC
/* 0F10F8 7F0BC5C8 AC52FFFC */   sw    $s2, -4($v0)
/* 0F10FC 7F0BC5CC 0FC2D791 */  jal   getMaxNumRooms
/* 0F1100 7F0BC5D0 00008025 */   move  $s0, $zero
/* 0F1104 7F0BC5D4 1840000D */  blez  $v0, .L7F0BC60C
/* 0F1108 7F0BC5D8 0010C880 */   sll   $t9, $s0, 2
/* 0F110C 7F0BC5DC 0330C821 */  addu  $t9, $t9, $s0
/* 0F1110 7F0BC5E0 3C088004 */  lui   $t0, %hi(array_room_info) 
/* 0F1114 7F0BC5E4 25081414 */  addiu $t0, %lo(array_room_info) # addiu $t0, $t0, 0x1414
/* 0F1118 7F0BC5E8 0019C900 */  sll   $t9, $t9, 4
/* 0F111C 7F0BC5EC 03288821 */  addu  $s1, $t9, $t0
/* 0F1120 7F0BC5F0 26100001 */  addiu $s0, $s0, 1
.L7F0BC5F4:
/* 0F1124 7F0BC5F4 26310050 */  addiu $s1, $s1, 0x50
/* 0F1128 7F0BC5F8 0FC2D791 */  jal   getMaxNumRooms
/* 0F112C 7F0BC5FC A632FFE6 */   sh    $s2, -0x1a($s1)
/* 0F1130 7F0BC600 0202082A */  slt   $at, $s0, $v0
/* 0F1134 7F0BC604 5420FFFB */  bnezl $at, .L7F0BC5F4
/* 0F1138 7F0BC608 26100001 */   addiu $s0, $s0, 1
.L7F0BC60C:
/* 0F113C 7F0BC60C 8FBF0024 */  lw    $ra, 0x24($sp)
/* 0F1140 7F0BC610 8FB00018 */  lw    $s0, 0x18($sp)
/* 0F1144 7F0BC614 8FB1001C */  lw    $s1, 0x1c($sp)
/* 0F1148 7F0BC618 8FB20020 */  lw    $s2, 0x20($sp)
/* 0F114C 7F0BC61C 03E00008 */  jr    $ra
/* 0F1150 7F0BC620 27BD0028 */   addiu $sp, $sp, 0x28
)
#endif






void sub_GAME_7F0BC624(s32 param_1) {
  pPlayer->field_108C = param_1;
}






#ifdef NONMATCHING
void sub_GAME_7F0BC634(s16 param_1,int param_2)
{
    roominformationblock[param_2].field_36 = param_1;
    (&dword_CODE_bss_80083450)[param_1] = param_2;
    return;
}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0BC634
/* 0F1164 7F0BC634 00057080 */  sll   $t6, $a1, 2
/* 0F1168 7F0BC638 01C57021 */  addu  $t6, $t6, $a1
/* 0F116C 7F0BC63C 000E7100 */  sll   $t6, $t6, 4
/* 0F1170 7F0BC640 3C018004 */  lui   $at, %hi(array_room_info + 0x10 +38)
/* 0F1174 7F0BC644 002E0821 */  addu  $at, $at, $t6
/* 0F1178 7F0BC648 A424144A */  sh    $a0, %lo(array_room_info + 0x10 +38)($at)
/* 0F117C 7F0BC64C 3C018008 */  lui   $at, %hi(dword_CODE_bss_80083450)
/* 0F1180 7F0BC650 00047880 */  sll   $t7, $a0, 2
/* 0F1184 7F0BC654 002F0821 */  addu  $at, $at, $t7
/* 0F1188 7F0BC658 03E00008 */  jr    $ra
/* 0F118C 7F0BC65C AC253450 */   sw    $a1, %lo(dword_CODE_bss_80083450)($at)
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0BC660(int param_1,int param_2)
{
    roominformationblock[param_2].field_36 = -1;
    (&dword_CODE_bss_80083450)[param_1] = 0xffffffff;
    return;
}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0BC660
/* 0F1190 7F0BC660 00057080 */  sll   $t6, $a1, 2
/* 0F1194 7F0BC664 01C57021 */  addu  $t6, $t6, $a1
/* 0F1198 7F0BC668 000E7100 */  sll   $t6, $t6, 4
/* 0F119C 7F0BC66C 3C018004 */  lui   $at, %hi(array_room_info + 0x10 +38)
/* 0F11A0 7F0BC670 2402FFFF */  li    $v0, -1
/* 0F11A4 7F0BC674 002E0821 */  addu  $at, $at, $t6
/* 0F11A8 7F0BC678 A422144A */  sh    $v0, %lo(array_room_info + 0x10 +38)($at)
/* 0F11AC 7F0BC67C 3C018008 */  lui   $at, %hi(dword_CODE_bss_80083450)
/* 0F11B0 7F0BC680 00047880 */  sll   $t7, $a0, 2
/* 0F11B4 7F0BC684 002F0821 */  addu  $at, $at, $t7
/* 0F11B8 7F0BC688 03E00008 */  jr    $ra
/* 0F11BC 7F0BC68C AC223450 */   sw    $v0, %lo(dword_CODE_bss_80083450)($at)
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0BC690(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0BC690
/* 0F11C0 7F0BC690 00041080 */  sll   $v0, $a0, 2
/* 0F11C4 7F0BC694 3C058008 */  lui   $a1, %hi(dword_CODE_bss_80083450)
/* 0F11C8 7F0BC698 00A22821 */  addu  $a1, $a1, $v0
/* 0F11CC 7F0BC69C 8CA53450 */  lw    $a1, %lo(dword_CODE_bss_80083450)($a1)
/* 0F11D0 7F0BC6A0 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0F11D4 7F0BC6A4 2401FFFF */  li    $at, -1
/* 0F11D8 7F0BC6A8 10A10006 */  beq   $a1, $at, .L7F0BC6C4
/* 0F11DC 7F0BC6AC AFBF0014 */   sw    $ra, 0x14($sp)
/* 0F11E0 7F0BC6B0 AFA2001C */  sw    $v0, 0x1c($sp)
/* 0F11E4 7F0BC6B4 0FC2F198 */  jal   sub_GAME_7F0BC660
/* 0F11E8 7F0BC6B8 AFA40020 */   sw    $a0, 0x20($sp)
/* 0F11EC 7F0BC6BC 8FA2001C */  lw    $v0, 0x1c($sp)
/* 0F11F0 7F0BC6C0 8FA40020 */  lw    $a0, 0x20($sp)
.L7F0BC6C4:
/* 0F11F4 7F0BC6C4 3C018008 */  lui   $at, %hi(dword_CODE_bss_80083320)
/* 0F11F8 7F0BC6C8 00240821 */  addu  $at, $at, $a0
/* 0F11FC 7F0BC6CC 240E0002 */  li    $t6, 2
/* 0F1200 7F0BC6D0 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0F1204 7F0BC6D4 A02E3320 */  sb    $t6, %lo(dword_CODE_bss_80083320)($at)
/* 0F1208 7F0BC6D8 3C018008 */  lui   $at, %hi(dword_CODE_bss_80083900)
/* 0F120C 7F0BC6DC 00220821 */  addu  $at, $at, $v0
/* 0F1210 7F0BC6E0 240FFFFF */  li    $t7, -1
/* 0F1214 7F0BC6E4 AC2F3900 */  sw    $t7, %lo(dword_CODE_bss_80083900)($at)
/* 0F1218 7F0BC6E8 03E00008 */  jr    $ra
/* 0F121C 7F0BC6EC 27BD0020 */   addiu $sp, $sp, 0x20
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0BC6F0(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0BC6F0
/* 0F1220 7F0BC6F0 3C028008 */  lui   $v0, %hi(dword_CODE_bss_80083320)
/* 0F1224 7F0BC6F4 3C058008 */  lui   $a1, %hi(dword_CODE_bss_80083900)
/* 0F1228 7F0BC6F8 24A53900 */  addiu $a1, %lo(dword_CODE_bss_80083900) # addiu $a1, $a1, 0x3900
/* 0F122C 7F0BC6FC 24423320 */  addiu $v0, %lo(dword_CODE_bss_80083320) # addiu $v0, $v0, 0x3320
/* 0F1230 7F0BC700 00001825 */  move  $v1, $zero
/* 0F1234 7F0BC704 2406012C */  li    $a2, 300
/* 0F1238 7F0BC708 2404FFFF */  li    $a0, -1
.L7F0BC70C:
/* 0F123C 7F0BC70C 904E0000 */  lbu   $t6, ($v0)
/* 0F1240 7F0BC710 00037880 */  sll   $t7, $v1, 2
/* 0F1244 7F0BC714 00AFC021 */  addu  $t8, $a1, $t7
/* 0F1248 7F0BC718 29C10002 */  slti  $at, $t6, 2
/* 0F124C 7F0BC71C 54200007 */  bnezl $at, .L7F0BC73C
/* 0F1250 7F0BC720 90480001 */   lbu   $t0, 1($v0)
/* 0F1254 7F0BC724 8F190000 */  lw    $t9, ($t8)
/* 0F1258 7F0BC728 54990004 */  bnel  $a0, $t9, .L7F0BC73C
/* 0F125C 7F0BC72C 90480001 */   lbu   $t0, 1($v0)
/* 0F1260 7F0BC730 03E00008 */  jr    $ra
/* 0F1264 7F0BC734 00601025 */   move  $v0, $v1

/* 0F1268 7F0BC738 90480001 */  lbu   $t0, 1($v0)
.L7F0BC73C:
/* 0F126C 7F0BC73C 00034880 */  sll   $t1, $v1, 2
/* 0F1270 7F0BC740 00A95021 */  addu  $t2, $a1, $t1
/* 0F1274 7F0BC744 29010002 */  slti  $at, $t0, 2
/* 0F1278 7F0BC748 54200007 */  bnezl $at, .L7F0BC768
/* 0F127C 7F0BC74C 904C0002 */   lbu   $t4, 2($v0)
/* 0F1280 7F0BC750 8D4B0004 */  lw    $t3, 4($t2)
/* 0F1284 7F0BC754 548B0004 */  bnel  $a0, $t3, .L7F0BC768
/* 0F1288 7F0BC758 904C0002 */   lbu   $t4, 2($v0)
/* 0F128C 7F0BC75C 03E00008 */  jr    $ra
/* 0F1290 7F0BC760 24620001 */   addiu $v0, $v1, 1

/* 0F1294 7F0BC764 904C0002 */  lbu   $t4, 2($v0)
.L7F0BC768:
/* 0F1298 7F0BC768 00036880 */  sll   $t5, $v1, 2
/* 0F129C 7F0BC76C 00AD7021 */  addu  $t6, $a1, $t5
/* 0F12A0 7F0BC770 29810002 */  slti  $at, $t4, 2
/* 0F12A4 7F0BC774 54200007 */  bnezl $at, .L7F0BC794
/* 0F12A8 7F0BC778 90580003 */   lbu   $t8, 3($v0)
/* 0F12AC 7F0BC77C 8DCF0008 */  lw    $t7, 8($t6)
/* 0F12B0 7F0BC780 548F0004 */  bnel  $a0, $t7, .L7F0BC794
/* 0F12B4 7F0BC784 90580003 */   lbu   $t8, 3($v0)
/* 0F12B8 7F0BC788 03E00008 */  jr    $ra
/* 0F12BC 7F0BC78C 24620002 */   addiu $v0, $v1, 2

/* 0F12C0 7F0BC790 90580003 */  lbu   $t8, 3($v0)
.L7F0BC794:
/* 0F12C4 7F0BC794 0003C880 */  sll   $t9, $v1, 2
/* 0F12C8 7F0BC798 00B94021 */  addu  $t0, $a1, $t9
/* 0F12CC 7F0BC79C 2B010002 */  slti  $at, $t8, 2
/* 0F12D0 7F0BC7A0 54200007 */  bnezl $at, .L7F0BC7C0
/* 0F12D4 7F0BC7A4 24630004 */   addiu $v1, $v1, 4
/* 0F12D8 7F0BC7A8 8D09000C */  lw    $t1, 0xc($t0)
/* 0F12DC 7F0BC7AC 54890004 */  bnel  $a0, $t1, .L7F0BC7C0
/* 0F12E0 7F0BC7B0 24630004 */   addiu $v1, $v1, 4
/* 0F12E4 7F0BC7B4 03E00008 */  jr    $ra
/* 0F12E8 7F0BC7B8 24620003 */   addiu $v0, $v1, 3

/* 0F12EC 7F0BC7BC 24630004 */  addiu $v1, $v1, 4
.L7F0BC7C0:
/* 0F12F0 7F0BC7C0 1466FFD2 */  bne   $v1, $a2, .L7F0BC70C
/* 0F12F4 7F0BC7C4 24420004 */   addiu $v0, $v0, 4
/* 0F12F8 7F0BC7C8 00001025 */  move  $v0, $zero
/* 0F12FC 7F0BC7CC 03E00008 */  jr    $ra
/* 0F1300 7F0BC7D0 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0BC7D4(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0BC7D4
/* 0F1304 7F0BC7D4 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 0F1308 7F0BC7D8 AFB2001C */  sw    $s2, 0x1c($sp)
/* 0F130C 7F0BC7DC AFB10018 */  sw    $s1, 0x18($sp)
/* 0F1310 7F0BC7E0 AFB30020 */  sw    $s3, 0x20($sp)
/* 0F1314 7F0BC7E4 AFB00014 */  sw    $s0, 0x14($sp)
/* 0F1318 7F0BC7E8 3C118008 */  lui   $s1, %hi(dword_CODE_bss_80083900)
/* 0F131C 7F0BC7EC 3C128008 */  lui   $s2, %hi(dword_CODE_bss_80083320)
/* 0F1320 7F0BC7F0 AFBF0024 */  sw    $ra, 0x24($sp)
/* 0F1324 7F0BC7F4 26523320 */  addiu $s2, %lo(dword_CODE_bss_80083320) # addiu $s2, $s2, 0x3320
/* 0F1328 7F0BC7F8 26313900 */  addiu $s1, %lo(dword_CODE_bss_80083900) # addiu $s1, $s1, 0x3900
/* 0F132C 7F0BC7FC 00008025 */  move  $s0, $zero
/* 0F1330 7F0BC800 2413012C */  li    $s3, 300
.L7F0BC804:
/* 0F1334 7F0BC804 8E2E0000 */  lw    $t6, ($s1)
/* 0F1338 7F0BC808 02501021 */  addu  $v0, $s2, $s0
/* 0F133C 7F0BC80C 05C2000A */  bltzl $t6, .L7F0BC838
/* 0F1340 7F0BC810 26100001 */   addiu $s0, $s0, 1
/* 0F1344 7F0BC814 904F0000 */  lbu   $t7, ($v0)
/* 0F1348 7F0BC818 25F80001 */  addiu $t8, $t7, 1
/* 0F134C 7F0BC81C 331900FF */  andi  $t9, $t8, 0xff
/* 0F1350 7F0BC820 2B210002 */  slti  $at, $t9, 2
/* 0F1354 7F0BC824 14200003 */  bnez  $at, .L7F0BC834
/* 0F1358 7F0BC828 A0580000 */   sb    $t8, ($v0)
/* 0F135C 7F0BC82C 0FC2F1A4 */  jal   sub_GAME_7F0BC690
/* 0F1360 7F0BC830 02002025 */   move  $a0, $s0
.L7F0BC834:
/* 0F1364 7F0BC834 26100001 */  addiu $s0, $s0, 1
.L7F0BC838:
/* 0F1368 7F0BC838 1613FFF2 */  bne   $s0, $s3, .L7F0BC804
/* 0F136C 7F0BC83C 26310004 */   addiu $s1, $s1, 4
/* 0F1370 7F0BC840 8FBF0024 */  lw    $ra, 0x24($sp)
/* 0F1374 7F0BC844 8FB00014 */  lw    $s0, 0x14($sp)
/* 0F1378 7F0BC848 8FB10018 */  lw    $s1, 0x18($sp)
/* 0F137C 7F0BC84C 8FB2001C */  lw    $s2, 0x1c($sp)
/* 0F1380 7F0BC850 8FB30020 */  lw    $s3, 0x20($sp)
/* 0F1384 7F0BC854 03E00008 */  jr    $ra
/* 0F1388 7F0BC858 27BD0028 */   addiu $sp, $sp, 0x28
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0BC85C(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0BC85C
/* 0F138C 7F0BC85C 27BDFF90 */  addiu $sp, $sp, -0x70
/* 0F1390 7F0BC860 00047880 */  sll   $t7, $a0, 2
/* 0F1394 7F0BC864 AFB00018 */  sw    $s0, 0x18($sp)
/* 0F1398 7F0BC868 01E47821 */  addu  $t7, $t7, $a0
/* 0F139C 7F0BC86C 000F7900 */  sll   $t7, $t7, 4
/* 0F13A0 7F0BC870 3C108004 */  lui   $s0, %hi(array_room_info + 0x10 +38)
/* 0F13A4 7F0BC874 020F8021 */  addu  $s0, $s0, $t7
/* 0F13A8 7F0BC878 8610144A */  lh    $s0, %lo(array_room_info + 0x10 +38)($s0)
/* 0F13AC 7F0BC87C 2402FFFF */  li    $v0, -1
/* 0F13B0 7F0BC880 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0F13B4 7F0BC884 1202000C */  beq   $s0, $v0, .L7F0BC8B8
/* 0F13B8 7F0BC888 AFA40070 */   sw    $a0, 0x70($sp)
/* 0F13BC 7F0BC88C 3C188008 */  lui   $t8, %hi(pPlayer) 
/* 0F13C0 7F0BC890 8F18A0B0 */  lw    $t8, %lo(pPlayer)($t8)
/* 0F13C4 7F0BC894 00104080 */  sll   $t0, $s0, 2
/* 0F13C8 7F0BC898 3C098008 */  lui   $t1, %hi(dword_CODE_bss_80083900)
/* 0F13CC 7F0BC89C 01284821 */  addu  $t1, $t1, $t0
/* 0F13D0 7F0BC8A0 8D293900 */  lw    $t1, %lo(dword_CODE_bss_80083900)($t1)
/* 0F13D4 7F0BC8A4 8F19108C */  lw    $t9, 0x108c($t8)
/* 0F13D8 7F0BC8A8 3C018008 */  lui   $at, %hi(dword_CODE_bss_80083320)
/* 0F13DC 7F0BC8AC 00300821 */  addu  $at, $at, $s0
/* 0F13E0 7F0BC8B0 1329000F */  beq   $t9, $t1, .L7F0BC8F0
/* 0F13E4 7F0BC8B4 00000000 */   nop   
.L7F0BC8B8:
/* 0F13E8 7F0BC8B8 12020003 */  beq   $s0, $v0, .L7F0BC8C8
/* 0F13EC 7F0BC8BC 02002025 */   move  $a0, $s0
/* 0F13F0 7F0BC8C0 0FC2F198 */  jal   sub_GAME_7F0BC660
/* 0F13F4 7F0BC8C4 8FA50070 */   lw    $a1, 0x70($sp)
.L7F0BC8C8:
/* 0F13F8 7F0BC8C8 0FC2F1BC */  jal   sub_GAME_7F0BC6F0
/* 0F13FC 7F0BC8CC 00000000 */   nop   
/* 0F1400 7F0BC8D0 00408025 */  move  $s0, $v0
/* 0F1404 7F0BC8D4 00402025 */  move  $a0, $v0
/* 0F1408 7F0BC8D8 0FC2F18D */  jal   sub_GAME_7F0BC634
/* 0F140C 7F0BC8DC 8FA50070 */   lw    $a1, 0x70($sp)
/* 0F1410 7F0BC8E0 3C018008 */  lui   $at, %hi(dword_CODE_bss_80083320)
/* 0F1414 7F0BC8E4 00300821 */  addu  $at, $at, $s0
/* 0F1418 7F0BC8E8 10000004 */  b     .L7F0BC8FC
/* 0F141C 7F0BC8EC A0203320 */   sb    $zero, %lo(dword_CODE_bss_80083320)($at)
.L7F0BC8F0:
/* 0F1420 7F0BC8F0 A0203320 */  sb    $zero, %lo(dword_CODE_bss_80083320)($at)
/* 0F1424 7F0BC8F4 1000002E */  b     .L7F0BC9B0
/* 0F1428 7F0BC8F8 02001025 */   move  $v0, $s0
.L7F0BC8FC:
/* 0F142C 7F0BC8FC 3C0A8008 */  lui   $t2, %hi(pPlayer) 
/* 0F1430 7F0BC900 8D4AA0B0 */  lw    $t2, %lo(pPlayer)($t2)
/* 0F1434 7F0BC904 00106080 */  sll   $t4, $s0, 2
/* 0F1438 7F0BC908 3C018008 */  lui   $at, %hi(dword_CODE_bss_80083900)
/* 0F143C 7F0BC90C 8D4B108C */  lw    $t3, 0x108c($t2)
/* 0F1440 7F0BC910 002C0821 */  addu  $at, $at, $t4
/* 0F1444 7F0BC914 27A4002C */  addiu $a0, $sp, 0x2c
/* 0F1448 7F0BC918 0FC15FF4 */  jal   matrix_4x4_set_identity
/* 0F144C 7F0BC91C AC2B3900 */   sw    $t3, %lo(dword_CODE_bss_80083900)($at)
/* 0F1450 7F0BC920 8FAE0070 */  lw    $t6, 0x70($sp)
/* 0F1454 7F0BC924 3C018004 */  lui   $at, %hi(room_data_float2)
/* 0F1458 7F0BC928 C42013F8 */  lwc1  $f0, %lo(room_data_float2)($at)
/* 0F145C 7F0BC92C 3C0D8008 */  lui   $t5, %hi(ptr_bgdata_room_fileposition_list) 
/* 0F1460 7F0BC930 8DADFF8C */  lw    $t5, %lo(ptr_bgdata_room_fileposition_list)($t5)
/* 0F1464 7F0BC934 000E7880 */  sll   $t7, $t6, 2
/* 0F1468 7F0BC938 01EE7823 */  subu  $t7, $t7, $t6
/* 0F146C 7F0BC93C 000F78C0 */  sll   $t7, $t7, 3
/* 0F1470 7F0BC940 E7A0002C */  swc1  $f0, 0x2c($sp)
/* 0F1474 7F0BC944 E7A00040 */  swc1  $f0, 0x40($sp)
/* 0F1478 7F0BC948 E7A00054 */  swc1  $f0, 0x54($sp)
/* 0F147C 7F0BC94C 01AF1821 */  addu  $v1, $t5, $t7
/* 0F1480 7F0BC950 C464000C */  lwc1  $f4, 0xc($v1)
/* 0F1484 7F0BC954 3C028008 */  lui   $v0, %hi(pPlayer)
/* 0F1488 7F0BC958 8C42A0B0 */  lw    $v0, %lo(pPlayer)($v0)
/* 0F148C 7F0BC95C 46002182 */  mul.s $f6, $f4, $f0
/* 0F1490 7F0BC960 3C088008 */  lui   $t0, %hi(dword_CODE_bss_80083DB0) 
/* 0F1494 7F0BC964 C4480038 */  lwc1  $f8, 0x38($v0)
/* 0F1498 7F0BC968 25083DB0 */  addiu $t0, %lo(dword_CODE_bss_80083DB0) # addiu $t0, $t0, 0x3db0
/* 0F149C 7F0BC96C 0010C180 */  sll   $t8, $s0, 6
/* 0F14A0 7F0BC970 03082821 */  addu  $a1, $t8, $t0
/* 0F14A4 7F0BC974 27A4002C */  addiu $a0, $sp, 0x2c
/* 0F14A8 7F0BC978 46083281 */  sub.s $f10, $f6, $f8
/* 0F14AC 7F0BC97C E7AA005C */  swc1  $f10, 0x5c($sp)
/* 0F14B0 7F0BC980 C4700010 */  lwc1  $f16, 0x10($v1)
/* 0F14B4 7F0BC984 C444003C */  lwc1  $f4, 0x3c($v0)
/* 0F14B8 7F0BC988 46008482 */  mul.s $f18, $f16, $f0
/* 0F14BC 7F0BC98C 46049181 */  sub.s $f6, $f18, $f4
/* 0F14C0 7F0BC990 E7A60060 */  swc1  $f6, 0x60($sp)
/* 0F14C4 7F0BC994 C4680014 */  lwc1  $f8, 0x14($v1)
/* 0F14C8 7F0BC998 C4500040 */  lwc1  $f16, 0x40($v0)
/* 0F14CC 7F0BC99C 46004282 */  mul.s $f10, $f8, $f0
/* 0F14D0 7F0BC9A0 46105481 */  sub.s $f18, $f10, $f16
/* 0F14D4 7F0BC9A4 0FC16327 */  jal   sub_GAME_7F058C9C
/* 0F14D8 7F0BC9A8 E7B20064 */   swc1  $f18, 0x64($sp)
/* 0F14DC 7F0BC9AC 02001025 */  move  $v0, $s0
.L7F0BC9B0:
/* 0F14E0 7F0BC9B0 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0F14E4 7F0BC9B4 8FB00018 */  lw    $s0, 0x18($sp)
/* 0F14E8 7F0BC9B8 27BD0070 */  addiu $sp, $sp, 0x70
/* 0F14EC 7F0BC9BC 03E00008 */  jr    $ra
/* 0F14F0 7F0BC9C0 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0BC9C4(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0BC9C4
/* 0F14F4 7F0BC9C4 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0F14F8 7F0BC9C8 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0F14FC 7F0BC9CC 00803025 */  move  $a2, $a0
/* 0F1500 7F0BC9D0 AFA60018 */  sw    $a2, 0x18($sp)
/* 0F1504 7F0BC9D4 0FC2F217 */  jal   sub_GAME_7F0BC85C
/* 0F1508 7F0BC9D8 00A02025 */   move  $a0, $a1
/* 0F150C 7F0BC9DC 8FA30018 */  lw    $v1, 0x18($sp)
/* 0F1510 7F0BC9E0 3C188008 */  lui   $t8, %hi(dword_CODE_bss_80083DB0) 
/* 0F1514 7F0BC9E4 27183DB0 */  addiu $t8, %lo(dword_CODE_bss_80083DB0) # addiu $t8, $t8, 0x3db0
/* 0F1518 7F0BC9E8 3C0E0102 */  lui   $t6, (0x01020040 >> 16) # lui $t6, 0x102
/* 0F151C 7F0BC9EC 00027980 */  sll   $t7, $v0, 6
/* 0F1520 7F0BC9F0 01F8C821 */  addu  $t9, $t7, $t8
/* 0F1524 7F0BC9F4 35CE0040 */  ori   $t6, (0x01020040 & 0xFFFF) # ori $t6, $t6, 0x40
/* 0F1528 7F0BC9F8 AC6E0000 */  sw    $t6, ($v1)
/* 0F152C 7F0BC9FC AC790004 */  sw    $t9, 4($v1)
/* 0F1530 7F0BCA00 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0F1534 7F0BCA04 24660008 */  addiu $a2, $v1, 8
/* 0F1538 7F0BCA08 00C01025 */  move  $v0, $a2
/* 0F153C 7F0BCA0C 03E00008 */  jr    $ra
/* 0F1540 7F0BCA10 27BD0018 */   addiu $sp, $sp, 0x18
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0BCA14(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0BCA14
/* 0F1544 7F0BCA14 3C0F8008 */  lui   $t7, %hi(ptr_bgdata_room_fileposition_list) 
/* 0F1548 7F0BCA18 8DEFFF8C */  lw    $t7, %lo(ptr_bgdata_room_fileposition_list)($t7)
/* 0F154C 7F0BCA1C 00047080 */  sll   $t6, $a0, 2
/* 0F1550 7F0BCA20 01C47023 */  subu  $t6, $t6, $a0
/* 0F1554 7F0BCA24 000E70C0 */  sll   $t6, $t6, 3
/* 0F1558 7F0BCA28 01CF1021 */  addu  $v0, $t6, $t7
/* 0F155C 7F0BCA2C 03E00008 */  jr    $ra
/* 0F1560 7F0BCA30 2442000C */   addiu $v0, $v0, 0xc
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0BCA34(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0BCA34
/* 0F1564 7F0BCA34 3C038008 */  lui   $v1, %hi(ptr_bgdata_room_fileposition_list)
/* 0F1568 7F0BCA38 2463FF8C */  addiu $v1, %lo(ptr_bgdata_room_fileposition_list) # addiu $v1, $v1, -0x74
/* 0F156C 7F0BCA3C 8C6E0000 */  lw    $t6, ($v1)
/* 0F1570 7F0BCA40 00041080 */  sll   $v0, $a0, 2
/* 0F1574 7F0BCA44 00441023 */  subu  $v0, $v0, $a0
/* 0F1578 7F0BCA48 3C068004 */  lui   $a2, %hi(room_data_float2)
/* 0F157C 7F0BCA4C 000210C0 */  sll   $v0, $v0, 3
/* 0F1580 7F0BCA50 24C613F8 */  addiu $a2, %lo(room_data_float2) # addiu $a2, $a2, 0x13f8
/* 0F1584 7F0BCA54 01C27821 */  addu  $t7, $t6, $v0
/* 0F1588 7F0BCA58 C5E4000C */  lwc1  $f4, 0xc($t7)
/* 0F158C 7F0BCA5C C4C60000 */  lwc1  $f6, ($a2)
/* 0F1590 7F0BCA60 46062202 */  mul.s $f8, $f4, $f6
/* 0F1594 7F0BCA64 E4A80000 */  swc1  $f8, ($a1)
/* 0F1598 7F0BCA68 8C780000 */  lw    $t8, ($v1)
/* 0F159C 7F0BCA6C C4D00000 */  lwc1  $f16, ($a2)
/* 0F15A0 7F0BCA70 0302C821 */  addu  $t9, $t8, $v0
/* 0F15A4 7F0BCA74 C72A0010 */  lwc1  $f10, 0x10($t9)
/* 0F15A8 7F0BCA78 46105482 */  mul.s $f18, $f10, $f16
/* 0F15AC 7F0BCA7C E4B20004 */  swc1  $f18, 4($a1)
/* 0F15B0 7F0BCA80 8C680000 */  lw    $t0, ($v1)
/* 0F15B4 7F0BCA84 C4C60000 */  lwc1  $f6, ($a2)
/* 0F15B8 7F0BCA88 01024821 */  addu  $t1, $t0, $v0
/* 0F15BC 7F0BCA8C C5240014 */  lwc1  $f4, 0x14($t1)
/* 0F15C0 7F0BCA90 46062202 */  mul.s $f8, $f4, $f6
/* 0F15C4 7F0BCA94 03E00008 */  jr    $ra
/* 0F15C8 7F0BCA98 E4A80008 */   swc1  $f8, 8($a1)
)
#endif


