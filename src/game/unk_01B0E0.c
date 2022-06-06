#include <ultra64.h>



#ifdef NONMATCHING
void sub_GAME_7F01B0E0(void) {
    s32 temp_a2;
    u8 *temp_a1;
    u8 temp_v0;
    void *phi_a3;
    u8 *phi_a1;
    s32 phi_v0;
    s32 phi_a2;

    phi_a3 = arg0 + 0xA;
    phi_a2 = arg0->unk0 * arg0->unk2;
    phi_a1 = arg1;
    do {
        temp_v0 = phi_a3->unk0;
        temp_a2 = phi_a2 - temp_v0;
        phi_a3 += 2;
        phi_v0 = temp_v0 - 1;
        phi_a2 = temp_a2;
loop_2:
        *phi_a1 = phi_a3->unk1;
        temp_a1 = phi_a1 + 1;
        phi_a1 = temp_a1;
        phi_v0 += -1;
        phi_a1 = temp_a1;
        if (phi_v0 > 0) {
            goto loop_2;
        }
    } while (temp_a2 > 0);

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F01B0E0
/* 04FC10 7F01B0E0 94820000 */  lhu   $v0, ($a0)
/* 04FC14 7F01B0E4 94830002 */  lhu   $v1, 2($a0)
/* 04FC18 7F01B0E8 2487000A */  addiu $a3, $a0, 0xa
/* 04FC1C 7F01B0EC 00430019 */  multu $v0, $v1
/* 04FC20 7F01B0F0 00003012 */  mflo  $a2
/* 04FC24 7F01B0F4 00000000 */  nop   
/* 04FC28 7F01B0F8 00000000 */  nop   
/* 04FC2C 7F01B0FC 90E20000 */  lbu   $v0, ($a3)
.L7F01B100:
/* 04FC30 7F01B100 90E30001 */  lbu   $v1, 1($a3)
/* 04FC34 7F01B104 24E70002 */  addiu $a3, $a3, 2
/* 04FC38 7F01B108 00C23023 */  subu  $a2, $a2, $v0
/* 04FC3C 7F01B10C 2442FFFF */  addiu $v0, $v0, -1
.L7F01B110:
/* 04FC40 7F01B110 0002202A */  slt   $a0, $zero, $v0
/* 04FC44 7F01B114 2442FFFF */  addiu $v0, $v0, -1
/* 04FC48 7F01B118 A0A30000 */  sb    $v1, ($a1)
/* 04FC4C 7F01B11C 1480FFFC */  bnez  $a0, .L7F01B110
/* 04FC50 7F01B120 24A50001 */   addiu $a1, $a1, 1
/* 04FC54 7F01B124 5CC0FFF6 */  bgtzl $a2, .L7F01B100
/* 04FC58 7F01B128 90E20000 */   lbu   $v0, ($a3)
/* 04FC5C 7F01B12C 03E00008 */  jr    $ra
/* 04FC60 7F01B130 00000000 */   nop   
)
#endif



#ifdef NONMATCHING
void sub_GAME_7F01B134(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F01B134
/* 04FC64 7F01B134 27BDFFF8 */  addiu $sp, $sp, -8
/* 04FC68 7F01B138 AFB00004 */  sw    $s0, 4($sp)
/* 04FC6C 7F01B13C 94820000 */  lhu   $v0, ($a0)
/* 04FC70 7F01B140 94830002 */  lhu   $v1, 2($a0)
/* 04FC74 7F01B144 00A08025 */  move  $s0, $a1
/* 04FC78 7F01B148 2487000A */  addiu $a3, $a0, 0xa
/* 04FC7C 7F01B14C 00430019 */  multu $v0, $v1
/* 04FC80 7F01B150 00003012 */  mflo  $a2
/* 04FC84 7F01B154 00000000 */  nop   
/* 04FC88 7F01B158 00000000 */  nop   
/* 04FC8C 7F01B15C 90E40002 */  lbu   $a0, 2($a3)
.L7F01B160:
/* 04FC90 7F01B160 90E50003 */  lbu   $a1, 3($a3)
/* 04FC94 7F01B164 90E30001 */  lbu   $v1, 1($a3)
/* 04FC98 7F01B168 0004C0C3 */  sra   $t8, $a0, 3
/* 04FC9C 7F01B16C 000570C3 */  sra   $t6, $a1, 3
/* 04FCA0 7F01B170 90E20000 */  lbu   $v0, ($a3)
/* 04FCA4 7F01B174 000E7AC0 */  sll   $t7, $t6, 0xb
/* 04FCA8 7F01B178 0018C980 */  sll   $t9, $t8, 6
/* 04FCAC 7F01B17C 000350C3 */  sra   $t2, $v1, 3
/* 04FCB0 7F01B180 000A5840 */  sll   $t3, $t2, 1
/* 04FCB4 7F01B184 01F94825 */  or    $t1, $t7, $t9
/* 04FCB8 7F01B188 012B4025 */  or    $t0, $t1, $t3
/* 04FCBC 7F01B18C 350C0001 */  ori   $t4, $t0, 1
/* 04FCC0 7F01B190 00C23023 */  subu  $a2, $a2, $v0
/* 04FCC4 7F01B194 24E70004 */  addiu $a3, $a3, 4
/* 04FCC8 7F01B198 01804025 */  move  $t0, $t4
/* 04FCCC 7F01B19C 2442FFFF */  addiu $v0, $v0, -1
.L7F01B1A0:
/* 04FCD0 7F01B1A0 0002182A */  slt   $v1, $zero, $v0
/* 04FCD4 7F01B1A4 2442FFFF */  addiu $v0, $v0, -1
/* 04FCD8 7F01B1A8 A6080000 */  sh    $t0, ($s0)
/* 04FCDC 7F01B1AC 1460FFFC */  bnez  $v1, .L7F01B1A0
/* 04FCE0 7F01B1B0 26100002 */   addiu $s0, $s0, 2
/* 04FCE4 7F01B1B4 5CC0FFEA */  bgtzl $a2, .L7F01B160
/* 04FCE8 7F01B1B8 90E40002 */   lbu   $a0, 2($a3)
/* 04FCEC 7F01B1BC 8FB00004 */  lw    $s0, 4($sp)
/* 04FCF0 7F01B1C0 03E00008 */  jr    $ra
/* 04FCF4 7F01B1C4 27BD0008 */   addiu $sp, $sp, 8
)
#endif



#ifdef NONMATCHING
void sub_GAME_7F01B1C8(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F01B1C8
/* 04FCF8 7F01B1C8 94830000 */  lhu   $v1, ($a0)
/* 04FCFC 7F01B1CC 94860002 */  lhu   $a2, 2($a0)
/* 04FD00 7F01B1D0 00A01025 */  move  $v0, $a1
/* 04FD04 7F01B1D4 2488000A */  addiu $t0, $a0, 0xa
/* 04FD08 7F01B1D8 00660019 */  multu $v1, $a2
/* 04FD0C 7F01B1DC 240A00FF */  li    $t2, 255
/* 04FD10 7F01B1E0 00003812 */  mflo  $a3
/* 04FD14 7F01B1E4 00000000 */  nop   
/* 04FD18 7F01B1E8 00000000 */  nop   
/* 04FD1C 7F01B1EC 91030000 */  lbu   $v1, ($t0)
.L7F01B1F0:
/* 04FD20 7F01B1F0 91040001 */  lbu   $a0, 1($t0)
/* 04FD24 7F01B1F4 91050002 */  lbu   $a1, 2($t0)
/* 04FD28 7F01B1F8 00E33823 */  subu  $a3, $a3, $v1
/* 04FD2C 7F01B1FC 91060003 */  lbu   $a2, 3($t0)
/* 04FD30 7F01B200 25080004 */  addiu $t0, $t0, 4
/* 04FD34 7F01B204 2463FFFF */  addiu $v1, $v1, -1
.L7F01B208:
/* 04FD38 7F01B208 0003482A */  slt   $t1, $zero, $v1
/* 04FD3C 7F01B20C A0460000 */  sb    $a2, ($v0)
/* 04FD40 7F01B210 A0450001 */  sb    $a1, 1($v0)
/* 04FD44 7F01B214 A0440002 */  sb    $a0, 2($v0)
/* 04FD48 7F01B218 A04A0003 */  sb    $t2, 3($v0)
/* 04FD4C 7F01B21C 2463FFFF */  addiu $v1, $v1, -1
/* 04FD50 7F01B220 1520FFF9 */  bnez  $t1, .L7F01B208
/* 04FD54 7F01B224 24420004 */   addiu $v0, $v0, 4
/* 04FD58 7F01B228 5CE0FFF1 */  bgtzl $a3, .L7F01B1F0
/* 04FD5C 7F01B22C 91030000 */   lbu   $v1, ($t0)
/* 04FD60 7F01B230 03E00008 */  jr    $ra
/* 04FD64 7F01B234 00000000 */   nop   
)
#endif


