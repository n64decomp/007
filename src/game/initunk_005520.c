#include "ultra64.h"


extern s32 D_80036070;
extern s32 D_80036074;
extern s32 D_80036078;



void zero_contents_of_80036070_74(void) {
    D_80036070 = 0;
    D_80036074 = 0;
}

void set_contents_of_80036078(s32 arg0) {
    D_80036078 = arg0;
}

//this may be a file split

#ifdef NONMATCHING
void sub_GAME_7F005540(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F005540
/* 03A070 7F005540 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 03A074 7F005544 AFB40024 */  sw    $s4, 0x24($sp)
/* 03A078 7F005548 3C148003 */  lui   $s4, %hi(D_80036074) # $s4, 0x8003
/* 03A07C 7F00554C AFB50028 */  sw    $s5, 0x28($sp)
/* 03A080 7F005550 0080A825 */  move  $s5, $a0
/* 03A084 7F005554 26946074 */  addiu $s4, %lo(D_80036074) # addiu $s4, $s4, 0x6074
/* 03A088 7F005558 AFBF002C */  sw    $ra, 0x2c($sp)
/* 03A08C 7F00555C 248E001E */  addiu $t6, $a0, 0x1e
/* 03A090 7F005560 AFB30020 */  sw    $s3, 0x20($sp)
/* 03A094 7F005564 AFB2001C */  sw    $s2, 0x1c($sp)
/* 03A098 7F005568 AFB10018 */  sw    $s1, 0x18($sp)
/* 03A09C 7F00556C AFB00014 */  sw    $s0, 0x14($sp)
/* 03A0A0 7F005570 AE8E0000 */  sw    $t6, ($s4)
/* 03A0A4 7F005574 000E2140 */  sll   $a0, $t6, 5
/* 03A0A8 7F005578 0C0025C8 */  jal   allocate_bytes_in_bank
/* 03A0AC 7F00557C 24050004 */   li    $a1, 4
/* 03A0B0 7F005580 8E980000 */  lw    $t8, ($s4)
/* 03A0B4 7F005584 3C128008 */  lui   $s2, %hi(ptr_allocation_1) # $s2, 0x8008
/* 03A0B8 7F005588 26529934 */  addiu $s2, %lo(ptr_allocation_1) # addiu $s2, $s2, -0x66cc
/* 03A0BC 7F00558C AE420000 */  sw    $v0, ($s2)
/* 03A0C0 7F005590 1B00001B */  blez  $t8, .L7F005600
/* 03A0C4 7F005594 00008825 */   move  $s1, $zero
/* 03A0C8 7F005598 00008025 */  move  $s0, $zero
/* 03A0CC 7F00559C 24130014 */  li    $s3, 20
/* 03A0D0 7F0055A0 8E590000 */  lw    $t9, ($s2)
.L7F0055A4:
/* 03A0D4 7F0055A4 0235082A */  slt   $at, $s1, $s5
/* 03A0D8 7F0055A8 24040050 */  li    $a0, 80
/* 03A0DC 7F0055AC 03304021 */  addu  $t0, $t9, $s0
/* 03A0E0 7F0055B0 10200005 */  beqz  $at, .L7F0055C8
/* 03A0E4 7F0055B4 AD000008 */   sw    $zero, 8($t0)
/* 03A0E8 7F0055B8 8E490000 */  lw    $t1, ($s2)
/* 03A0EC 7F0055BC 01305021 */  addu  $t2, $t1, $s0
/* 03A0F0 7F0055C0 10000009 */  b     .L7F0055E8
/* 03A0F4 7F0055C4 AD400010 */   sw    $zero, 0x10($t2)
.L7F0055C8:
/* 03A0F8 7F0055C8 0C0025C8 */  jal   allocate_bytes_in_bank
/* 03A0FC 7F0055CC 24050004 */   li    $a1, 4
/* 03A100 7F0055D0 8E4B0000 */  lw    $t3, ($s2)
/* 03A104 7F0055D4 01706021 */  addu  $t4, $t3, $s0
/* 03A108 7F0055D8 AD820010 */  sw    $v0, 0x10($t4)
/* 03A10C 7F0055DC 8E4D0000 */  lw    $t5, ($s2)
/* 03A110 7F0055E0 01B07021 */  addu  $t6, $t5, $s0
/* 03A114 7F0055E4 A5D30002 */  sh    $s3, 2($t6)
.L7F0055E8:
/* 03A118 7F0055E8 8E8F0000 */  lw    $t7, ($s4)
/* 03A11C 7F0055EC 26310001 */  addiu $s1, $s1, 1
/* 03A120 7F0055F0 26100020 */  addiu $s0, $s0, 0x20
/* 03A124 7F0055F4 022F082A */  slt   $at, $s1, $t7
/* 03A128 7F0055F8 5420FFEA */  bnezl $at, .L7F0055A4
/* 03A12C 7F0055FC 8E590000 */   lw    $t9, ($s2)
.L7F005600:
/* 03A130 7F005600 8FBF002C */  lw    $ra, 0x2c($sp)
/* 03A134 7F005604 8FB00014 */  lw    $s0, 0x14($sp)
/* 03A138 7F005608 8FB10018 */  lw    $s1, 0x18($sp)
/* 03A13C 7F00560C 8FB2001C */  lw    $s2, 0x1c($sp)
/* 03A140 7F005610 8FB30020 */  lw    $s3, 0x20($sp)
/* 03A144 7F005614 8FB40024 */  lw    $s4, 0x24($sp)
/* 03A148 7F005618 8FB50028 */  lw    $s5, 0x28($sp)
/* 03A14C 7F00561C 03E00008 */  jr    $ra
/* 03A150 7F005620 27BD0030 */   addiu $sp, $sp, 0x30
)
#endif


#ifdef NONMATCHING
void sub_GAME_7F005624(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F005624
/* 03A154 7F005624 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 03A158 7F005628 AFB40024 */  sw    $s4, 0x24($sp)
/* 03A15C 7F00562C 248E000A */  addiu $t6, $a0, 0xa
/* 03A160 7F005630 3C148003 */  lui   $s4, %hi(D_80036070) # $s4, 0x8003
/* 03A164 7F005634 AFB50028 */  sw    $s5, 0x28($sp)
/* 03A168 7F005638 000E7880 */  sll   $t7, $t6, 2
/* 03A16C 7F00563C 0080A825 */  move  $s5, $a0
/* 03A170 7F005640 26946070 */  addiu $s4, %lo(D_80036070) # addiu $s4, $s4, 0x6070
/* 03A174 7F005644 AFBF002C */  sw    $ra, 0x2c($sp)
/* 03A178 7F005648 01EE7823 */  subu  $t7, $t7, $t6
/* 03A17C 7F00564C AFB30020 */  sw    $s3, 0x20($sp)
/* 03A180 7F005650 AFB2001C */  sw    $s2, 0x1c($sp)
/* 03A184 7F005654 AFB10018 */  sw    $s1, 0x18($sp)
/* 03A188 7F005658 AFB00014 */  sw    $s0, 0x14($sp)
/* 03A18C 7F00565C AE8E0000 */  sw    $t6, ($s4)
/* 03A190 7F005660 000F2180 */  sll   $a0, $t7, 6
/* 03A194 7F005664 0C0025C8 */  jal   allocate_bytes_in_bank
/* 03A198 7F005668 24050004 */   li    $a1, 4
/* 03A19C 7F00566C 8E980000 */  lw    $t8, ($s4)
/* 03A1A0 7F005670 3C128008 */  lui   $s2, %hi(ptr_allocation_0) # $s2, 0x8008
/* 03A1A4 7F005674 26529930 */  addiu $s2, %lo(ptr_allocation_0) # addiu $s2, $s2, -0x66d0
/* 03A1A8 7F005678 AE420000 */  sw    $v0, ($s2)
/* 03A1AC 7F00567C 1B00001B */  blez  $t8, .L7F0056EC
/* 03A1B0 7F005680 00008825 */   move  $s1, $zero
/* 03A1B4 7F005684 00008025 */  move  $s0, $zero
/* 03A1B8 7F005688 2413008C */  li    $s3, 140
/* 03A1BC 7F00568C 8E590000 */  lw    $t9, ($s2)
.L7F005690:
/* 03A1C0 7F005690 0235082A */  slt   $at, $s1, $s5
/* 03A1C4 7F005694 24040230 */  li    $a0, 560
/* 03A1C8 7F005698 03304021 */  addu  $t0, $t9, $s0
/* 03A1CC 7F00569C 10200005 */  beqz  $at, .L7F0056B4
/* 03A1D0 7F0056A0 AD000008 */   sw    $zero, 8($t0)
/* 03A1D4 7F0056A4 8E490000 */  lw    $t1, ($s2)
/* 03A1D8 7F0056A8 01305021 */  addu  $t2, $t1, $s0
/* 03A1DC 7F0056AC 10000009 */  b     .L7F0056D4
/* 03A1E0 7F0056B0 AD400010 */   sw    $zero, 0x10($t2)
.L7F0056B4:
/* 03A1E4 7F0056B4 0C0025C8 */  jal   allocate_bytes_in_bank
/* 03A1E8 7F0056B8 24050004 */   li    $a1, 4
/* 03A1EC 7F0056BC 8E4B0000 */  lw    $t3, ($s2)
/* 03A1F0 7F0056C0 01706021 */  addu  $t4, $t3, $s0
/* 03A1F4 7F0056C4 AD820010 */  sw    $v0, 0x10($t4)
/* 03A1F8 7F0056C8 8E4D0000 */  lw    $t5, ($s2)
/* 03A1FC 7F0056CC 01B07021 */  addu  $t6, $t5, $s0
/* 03A200 7F0056D0 A5D30002 */  sh    $s3, 2($t6)
.L7F0056D4:
/* 03A204 7F0056D4 8E8F0000 */  lw    $t7, ($s4)
/* 03A208 7F0056D8 26310001 */  addiu $s1, $s1, 1
/* 03A20C 7F0056DC 261000BC */  addiu $s0, $s0, 0xbc
/* 03A210 7F0056E0 022F082A */  slt   $at, $s1, $t7
/* 03A214 7F0056E4 5420FFEA */  bnezl $at, .L7F005690
/* 03A218 7F0056E8 8E590000 */   lw    $t9, ($s2)
.L7F0056EC:
/* 03A21C 7F0056EC 8FBF002C */  lw    $ra, 0x2c($sp)
/* 03A220 7F0056F0 8FB00014 */  lw    $s0, 0x14($sp)
/* 03A224 7F0056F4 8FB10018 */  lw    $s1, 0x18($sp)
/* 03A228 7F0056F8 8FB2001C */  lw    $s2, 0x1c($sp)
/* 03A22C 7F0056FC 8FB30020 */  lw    $s3, 0x20($sp)
/* 03A230 7F005700 8FB40024 */  lw    $s4, 0x24($sp)
/* 03A234 7F005704 8FB50028 */  lw    $s5, 0x28($sp)
/* 03A238 7F005708 03E00008 */  jr    $ra
/* 03A23C 7F00570C 27BD0030 */   addiu $sp, $sp, 0x30
)
#endif


