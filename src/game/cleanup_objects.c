#include "ultra64.h"


#ifdef NONMATCHING
void cleanupObjects(s32 stage) {

}
#else
GLOBAL_ASM(
.rdata
glabel jpt_8004F210
    .word .L7F007550
    .word .L7F00755C
    .word .L7F007550
    .word .L7F007550
    .word .L7F007550
    .word .L7F007550
    .word .L7F007550
    .word .L7F007550
    .word .L7F00755C
    .word .L7F007550
    .word .L7F007550
    .word .L7F007550
    .word .L7F007550
    .word .L7F00755C
    .word .L7F00755C
    .word .L7F00755C
    .word .L7F007550
    .word .L7F00755C
    .word .L7F00755C
    .word .L7F007550
    .word .L7F007550
    .word .L7F00755C
    .word .L7F00755C
    .word .L7F00755C
    .word .L7F00755C
    .word .L7F00755C
    .word .L7F00755C
    .word .L7F00755C
    .word .L7F00755C
    .word .L7F00755C
    .word .L7F00755C
    .word .L7F00755C
    .word .L7F00755C
    .word .L7F00755C
    .word .L7F00755C
    .word .L7F007550
    .word .L7F00755C
    .word .L7F00755C
    .word .L7F007550
    .word .L7F007550
    .word .L7F007550
    .word .L7F007550
    .word .L7F007550
    .word .L7F00755C
    .word .L7F007550
    .word .L7F00755C
    .word .L7F007550
.text
glabel cleanupObjects
/* 03C030 7F007500 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 03C034 7F007504 AFB00018 */  sw    $s0, 0x18($sp)
/* 03C038 7F007508 3C108007 */  lui   $s0, %hi(ptr_setup_objects)
/* 03C03C 7F00750C 8E105D0C */  lw    $s0, %lo(ptr_setup_objects)($s0)
/* 03C040 7F007510 AFBF001C */  sw    $ra, 0x1c($sp)
/* 03C044 7F007514 AFA40020 */  sw    $a0, 0x20($sp)
/* 03C048 7F007518 52000019 */  beql  $s0, $zero, .L7F007580
/* 03C04C 7F00751C 8FBF001C */   lw    $ra, 0x1c($sp)
/* 03C050 7F007520 92030003 */  lbu   $v1, 3($s0)
/* 03C054 7F007524 24010030 */  li    $at, 48
/* 03C058 7F007528 10610014 */  beq   $v1, $at, .L7F00757C
/* 03C05C 7F00752C 246EFFFF */   addiu $t6, $v1, -1
.L7F007530:
/* 03C060 7F007530 2DC1002F */  sltiu $at, $t6, 0x2f
/* 03C064 7F007534 10200009 */  beqz  $at, .L7F00755C
/* 03C068 7F007538 000E7080 */   sll   $t6, $t6, 2
/* 03C06C 7F00753C 3C018005 */  lui   $at, %hi(jpt_8004F210)
/* 03C070 7F007540 002E0821 */  addu  $at, $at, $t6
/* 03C074 7F007544 8C2EF210 */  lw    $t6, %lo(jpt_8004F210)($at)
/* 03C078 7F007548 01C00008 */  jr    $t6
/* 03C07C 7F00754C 00000000 */   nop 
.L7F007550:
/* 03C080 7F007550 02002025 */  move  $a0, $s0
/* 03C084 7F007554 0FC10409 */  jal   sub_GAME_7F041024
/* 03C088 7F007558 24050001 */   li    $a1, 1
.L7F00755C:
/* 03C08C 7F00755C 0FC15A3D */  jal   get_size_of_setup_object_type
/* 03C090 7F007560 02002025 */   move  $a0, $s0
/* 03C094 7F007564 00027880 */  sll   $t7, $v0, 2
/* 03C098 7F007568 01F08021 */  addu  $s0, $t7, $s0
/* 03C09C 7F00756C 92030003 */  lbu   $v1, 3($s0)
/* 03C0A0 7F007570 24010030 */  li    $at, 48
/* 03C0A4 7F007574 5461FFEE */  bnel  $v1, $at, .L7F007530
/* 03C0A8 7F007578 246EFFFF */   addiu $t6, $v1, -1
.L7F00757C:
/* 03C0AC 7F00757C 8FBF001C */  lw    $ra, 0x1c($sp)
.L7F007580:
/* 03C0B0 7F007580 8FB00018 */  lw    $s0, 0x18($sp)
/* 03C0B4 7F007584 27BD0020 */  addiu $sp, $sp, 0x20
/* 03C0B8 7F007588 03E00008 */  jr    $ra
/* 03C0BC 7F00758C 00000000 */   nop   
)
#endif




