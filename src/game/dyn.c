#include "ultra64.h"

// bss
//CODE.bss:8008C230
s32 *ptr_mgfx0_alloc_start;
//CODE.bss:8008C234
s32 *ptr_mgfx1_alloc_start;
//CODE.bss:8008C238
s32 *ptr_mgfx_end;
//CODE.bss:8008C23C
s32 D_8008C23C;
//CODE.bss:8008C240
s32 *ptr_mvtx0_alloc_start;
//CODE.bss:8008C244
s32 *ptr_mvtx1_alloc_start;
//CODE.bss:8008C248
s32 *ptr_mvtx_end;
//CODE.bss:8008C24C
s32 *ptr_mvtx_cur_pos;
//CODE.bss:8008C250
s32 bank_in_mgfx_alloc_table;
//CODE.bss:8008C254
s32 dword_CODE_bss_8008C254;


// data
//D:800482E0
s32 D_800482E0 = 0;
//D:800482E4
s32 D_800482E4[] = {0x10000, 0x18000, 0x20000};
//D:800482F0
s32 D_800482F0[] = {0x28000, 0x10000, 0x18000, 0x20000, 0x28000};

//D:80048304
char membars_string1[] = ">>>>>>>>>>>>>>>>>>>>>>>>>";
//D:80048320
char membars_string2[] = "=========================";
//D:8004833C
char membars_string3[] = "-------------------------";


//rodata

void something_with_dyn_c_debug(void) {
    get_ptr_debug_notice_list_entry(&D_800482E0, "dyn_c_debug");
}

#ifdef NONMATCHING
void set_vtx_gfx_mem_alloc(void) {
    s32 sp18;
    ? temp_ret;

    // Node 0
    if (check_token(1, "-mgfx") != 0)
    {
        // Node 1
        sp18 = get_num_players();
        (0x80050000 + (sp18 * 4))->unk-7D20 = (s32) (strtol(check_token(1, "-mgfx"), 0, 0) << 0xa);
    }
    // Node 2
    if (check_token(1, "-mvtx") != 0)
    {
        // Node 3
        sp18 = get_num_players();
        (0x80050000 + (sp18 * 4))->unk-7D10 = (s32) (strtol(check_token(1, "-mvtx"), 0, 0) << 0xa);
    }
    // Node 4
    ptr_mgfx0_alloc_start = allocate_bytes_in_bank(((0x80050000 + (get_num_players() * 4))->unk-7D20 * 2), 4);
    ptr_mgfx0_alloc_start.unk4 = (s32) ((0x80050000 + (get_num_players() * 4))->unk-7D20 + ptr_mgfx0_alloc_start);
    ptr_mgfx0_alloc_start.unk8 = (s32) ((0x80050000 + (get_num_players() * 4))->unk-7D20 + ptr_mgfx0_alloc_start.unk4);
    ptr_mvtx0_alloc_start = allocate_bytes_in_bank(((0x80050000 + (get_num_players() * 4))->unk-7D10 * 2), 4);
    ptr_mvtx0_alloc_start.unk4 = (s32) ((0x80050000 + (get_num_players() * 4))->unk-7D10 + ptr_mvtx0_alloc_start);
    temp_ret = get_num_players();
    ptr_mvtx0_alloc_start.unk8 = (s32) ((0x80050000 + (temp_ret * 4))->unk-7D10 + ptr_mvtx0_alloc_start.unk4);
    bank_in_mgfx_alloc_table = (u8)0;
    dword_CODE_bss_8008C254 = 0;
    (void *)0x80090000->unk-3DB4 = (s32) ptr_mvtx0_alloc_start;
    return temp_ret;
}
#else
GLOBAL_ASM(
.rdata
/*D:8005B68C*/
glabel aMgfx
/*"-mgfx"*/
.word 0x2D6D6766, 0x78000000

/*D:8005B694*/
glabel aMgfx_1
 /*"-mgfx"*/
.word 0x2D6D6766, 0x78000000

/*D:8005B69C*/
glabel aMvtx
 /*"-mvtx"*/
.word 0x2D6D7674, 0x78000000

/*D:8005B6A4*/
glabel aMvtx_0
 /*"-mvtx"*/
.word 0x2D6D7674, 0x78000000

.text
glabel set_vtx_gfx_mem_alloc
/* 0F1FBC 7F0BD48C 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0F1FC0 7F0BD490 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0F1FC4 7F0BD494 3C058006 */  lui   $a1, %hi(aMgfx)
/* 0F1FC8 7F0BD498 24A5B68C */  addiu $a1, %lo(aMgfx) # addiu $a1, $a1, -0x4974
/* 0F1FCC 7F0BD49C 0C0029A8 */  jal   check_token
/* 0F1FD0 7F0BD4A0 24040001 */   li    $a0, 1
/* 0F1FD4 7F0BD4A4 10400012 */  beqz  $v0, .L7F0BD4F0
/* 0F1FD8 7F0BD4A8 00000000 */   nop   
/* 0F1FDC 7F0BD4AC 0FC26919 */  jal   get_num_players
/* 0F1FE0 7F0BD4B0 00000000 */   nop   
/* 0F1FE4 7F0BD4B4 3C058006 */  lui   $a1, %hi(aMgfx_1)
/* 0F1FE8 7F0BD4B8 24A5B694 */  addiu $a1, %lo(aMgfx_1) # addiu $a1, $a1, -0x496c
/* 0F1FEC 7F0BD4BC AFA20018 */  sw    $v0, 0x18($sp)
/* 0F1FF0 7F0BD4C0 0C0029A8 */  jal   check_token
/* 0F1FF4 7F0BD4C4 24040001 */   li    $a0, 1
/* 0F1FF8 7F0BD4C8 00402025 */  move  $a0, $v0
/* 0F1FFC 7F0BD4CC 00002825 */  move  $a1, $zero
/* 0F2000 7F0BD4D0 0C002A78 */  jal   strtol
/* 0F2004 7F0BD4D4 00003025 */   move  $a2, $zero
/* 0F2008 7F0BD4D8 8FAF0018 */  lw    $t7, 0x18($sp)
/* 0F200C 7F0BD4DC 3C018005 */  lui   $at, %hi(D_800482E0)
/* 0F2010 7F0BD4E0 00027280 */  sll   $t6, $v0, 0xa
/* 0F2014 7F0BD4E4 000FC080 */  sll   $t8, $t7, 2
/* 0F2018 7F0BD4E8 00380821 */  addu  $at, $at, $t8
/* 0F201C 7F0BD4EC AC2E82E0 */  sw    $t6, %lo(D_800482E0)($at)
.L7F0BD4F0:
/* 0F2020 7F0BD4F0 3C058006 */  lui   $a1, %hi(aMvtx)
/* 0F2024 7F0BD4F4 24A5B69C */  addiu $a1, %lo(aMvtx) # addiu $a1, $a1, -0x4964
/* 0F2028 7F0BD4F8 0C0029A8 */  jal   check_token
/* 0F202C 7F0BD4FC 24040001 */   li    $a0, 1
/* 0F2030 7F0BD500 10400012 */  beqz  $v0, .L7F0BD54C
/* 0F2034 7F0BD504 00000000 */   nop   
/* 0F2038 7F0BD508 0FC26919 */  jal   get_num_players
/* 0F203C 7F0BD50C 00000000 */   nop   
/* 0F2040 7F0BD510 3C058006 */  lui   $a1, %hi(aMvtx_0)
/* 0F2044 7F0BD514 24A5B6A4 */  addiu $a1, %lo(aMvtx_0) # addiu $a1, $a1, -0x495c
/* 0F2048 7F0BD518 AFA20018 */  sw    $v0, 0x18($sp)
/* 0F204C 7F0BD51C 0C0029A8 */  jal   check_token
/* 0F2050 7F0BD520 24040001 */   li    $a0, 1
/* 0F2054 7F0BD524 00402025 */  move  $a0, $v0
/* 0F2058 7F0BD528 00002825 */  move  $a1, $zero
/* 0F205C 7F0BD52C 0C002A78 */  jal   strtol
/* 0F2060 7F0BD530 00003025 */   move  $a2, $zero
/* 0F2064 7F0BD534 8FA80018 */  lw    $t0, 0x18($sp)
/* 0F2068 7F0BD538 3C018005 */  lui   $at, %hi(D_800482F0)
/* 0F206C 7F0BD53C 0002CA80 */  sll   $t9, $v0, 0xa
/* 0F2070 7F0BD540 00084880 */  sll   $t1, $t0, 2
/* 0F2074 7F0BD544 00290821 */  addu  $at, $at, $t1
/* 0F2078 7F0BD548 AC3982F0 */  sw    $t9, %lo(D_800482F0)($at)
.L7F0BD54C:
/* 0F207C 7F0BD54C 0FC26919 */  jal   get_num_players
/* 0F2080 7F0BD550 00000000 */   nop   
/* 0F2084 7F0BD554 00025080 */  sll   $t2, $v0, 2
/* 0F2088 7F0BD558 3C048005 */  lui   $a0, %hi(D_800482E0)
/* 0F208C 7F0BD55C 008A2021 */  addu  $a0, $a0, $t2
/* 0F2090 7F0BD560 8C8482E0 */  lw    $a0, %lo(D_800482E0)($a0)
/* 0F2094 7F0BD564 24050004 */  li    $a1, 4
/* 0F2098 7F0BD568 00045840 */  sll   $t3, $a0, 1
/* 0F209C 7F0BD56C 0C0025C8 */  jal   allocate_bytes_in_bank
/* 0F20A0 7F0BD570 01602025 */   move  $a0, $t3
/* 0F20A4 7F0BD574 3C018009 */  lui   $at, %hi(ptr_mgfx0_alloc_start)
/* 0F20A8 7F0BD578 0FC26919 */  jal   get_num_players
/* 0F20AC 7F0BD57C AC22C230 */   sw    $v0, %lo(ptr_mgfx0_alloc_start)($at)
/* 0F20B0 7F0BD580 3C038009 */  lui   $v1, %hi(ptr_mgfx0_alloc_start)
/* 0F20B4 7F0BD584 00026080 */  sll   $t4, $v0, 2
/* 0F20B8 7F0BD588 3C0D8005 */  lui   $t5, %hi(D_800482E0)
/* 0F20BC 7F0BD58C 01AC6821 */  addu  $t5, $t5, $t4
/* 0F20C0 7F0BD590 2463C230 */  addiu $v1, %lo(ptr_mgfx0_alloc_start) # addiu $v1, $v1, -0x3dd0
/* 0F20C4 7F0BD594 8C6F0000 */  lw    $t7, ($v1)
/* 0F20C8 7F0BD598 8DAD82E0 */  lw    $t5, %lo(D_800482E0)($t5)
/* 0F20CC 7F0BD59C 01AF7021 */  addu  $t6, $t5, $t7
/* 0F20D0 7F0BD5A0 0FC26919 */  jal   get_num_players
/* 0F20D4 7F0BD5A4 AC6E0004 */   sw    $t6, 4($v1)
/* 0F20D8 7F0BD5A8 3C038009 */  lui   $v1, %hi(ptr_mgfx0_alloc_start)
/* 0F20DC 7F0BD5AC 0002C080 */  sll   $t8, $v0, 2
/* 0F20E0 7F0BD5B0 3C088005 */  lui   $t0, %hi(D_800482E0)
/* 0F20E4 7F0BD5B4 01184021 */  addu  $t0, $t0, $t8
/* 0F20E8 7F0BD5B8 2463C230 */  addiu $v1, %lo(ptr_mgfx0_alloc_start) # addiu $v1, $v1, -0x3dd0
/* 0F20EC 7F0BD5BC 8C790004 */  lw    $t9, 4($v1)
/* 0F20F0 7F0BD5C0 8D0882E0 */  lw    $t0, %lo(D_800482E0)($t0)
/* 0F20F4 7F0BD5C4 01194821 */  addu  $t1, $t0, $t9
/* 0F20F8 7F0BD5C8 0FC26919 */  jal   get_num_players
/* 0F20FC 7F0BD5CC AC690008 */   sw    $t1, 8($v1)
/* 0F2100 7F0BD5D0 00025080 */  sll   $t2, $v0, 2
/* 0F2104 7F0BD5D4 3C048005 */  lui   $a0, %hi(D_800482F0)
/* 0F2108 7F0BD5D8 008A2021 */  addu  $a0, $a0, $t2
/* 0F210C 7F0BD5DC 8C8482F0 */  lw    $a0, %lo(D_800482F0)($a0)
/* 0F2110 7F0BD5E0 24050004 */  li    $a1, 4
/* 0F2114 7F0BD5E4 00045840 */  sll   $t3, $a0, 1
/* 0F2118 7F0BD5E8 0C0025C8 */  jal   allocate_bytes_in_bank
/* 0F211C 7F0BD5EC 01602025 */   move  $a0, $t3
/* 0F2120 7F0BD5F0 3C038009 */  lui   $v1, %hi(ptr_mvtx0_alloc_start)
/* 0F2124 7F0BD5F4 2463C240 */  addiu $v1, %lo(ptr_mvtx0_alloc_start) # addiu $v1, $v1, -0x3dc0
/* 0F2128 7F0BD5F8 0FC26919 */  jal   get_num_players
/* 0F212C 7F0BD5FC AC620000 */   sw    $v0, ($v1)
/* 0F2130 7F0BD600 3C038009 */  lui   $v1, %hi(ptr_mvtx0_alloc_start)
/* 0F2134 7F0BD604 00026080 */  sll   $t4, $v0, 2
/* 0F2138 7F0BD608 3C0D8005 */  lui   $t5, %hi(D_800482F0)
/* 0F213C 7F0BD60C 01AC6821 */  addu  $t5, $t5, $t4
/* 0F2140 7F0BD610 2463C240 */  addiu $v1, %lo(ptr_mvtx0_alloc_start) # addiu $v1, $v1, -0x3dc0
/* 0F2144 7F0BD614 8C6F0000 */  lw    $t7, ($v1)
/* 0F2148 7F0BD618 8DAD82F0 */  lw    $t5, %lo(D_800482F0)($t5)
/* 0F214C 7F0BD61C 01AF7021 */  addu  $t6, $t5, $t7
/* 0F2150 7F0BD620 0FC26919 */  jal   get_num_players
/* 0F2154 7F0BD624 AC6E0004 */   sw    $t6, 4($v1)
/* 0F2158 7F0BD628 3C038009 */  lui   $v1, %hi(ptr_mvtx0_alloc_start)
/* 0F215C 7F0BD62C 0002C080 */  sll   $t8, $v0, 2
/* 0F2160 7F0BD630 3C088005 */  lui   $t0, %hi(D_800482F0)
/* 0F2164 7F0BD634 01184021 */  addu  $t0, $t0, $t8
/* 0F2168 7F0BD638 2463C240 */  addiu $v1, %lo(ptr_mvtx0_alloc_start) # addiu $v1, $v1, -0x3dc0
/* 0F216C 7F0BD63C 8C790004 */  lw    $t9, 4($v1)
/* 0F2170 7F0BD640 8D0882F0 */  lw    $t0, %lo(D_800482F0)($t0)
/* 0F2174 7F0BD644 3C018009 */  lui   $at, %hi(bank_in_mgfx_alloc_table)
/* 0F2178 7F0BD648 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0F217C 7F0BD64C 01194821 */  addu  $t1, $t0, $t9
/* 0F2180 7F0BD650 AC690008 */  sw    $t1, 8($v1)
/* 0F2184 7F0BD654 A020C250 */  sb    $zero, %lo(bank_in_mgfx_alloc_table)($at)
/* 0F2188 7F0BD658 3C018009 */  lui   $at, %hi(dword_CODE_bss_8008C254)
/* 0F218C 7F0BD65C AC20C254 */  sw    $zero, %lo(dword_CODE_bss_8008C254)($at)
/* 0F2190 7F0BD660 8C6A0000 */  lw    $t2, ($v1)
/* 0F2194 7F0BD664 3C018009 */  lui   $at, %hi(ptr_mvtx_cur_pos)
/* 0F2198 7F0BD668 27BD0020 */  addiu $sp, $sp, 0x20
/* 0F219C 7F0BD66C 03E00008 */  jr    $ra
/* 0F21A0 7F0BD670 AC2AC24C */   sw    $t2, %lo(ptr_mvtx_cur_pos)($at)
)
#endif





#ifdef NONMATCHING
void get_ptr_displaylist(void) {

}
#else
GLOBAL_ASM(
.text
glabel get_ptr_displaylist
/* 0F21A4 7F0BD674 3C0F8009 */  lui   $t7, %hi(bank_in_mgfx_alloc_table) 
/* 0F21A8 7F0BD678 91EFC250 */  lbu   $t7, %lo(bank_in_mgfx_alloc_table)($t7)
/* 0F21AC 7F0BD67C 3C028009 */  lui   $v0, %hi(ptr_mgfx0_alloc_start)
/* 0F21B0 7F0BD680 240E0001 */  li    $t6, 1
/* 0F21B4 7F0BD684 000FC080 */  sll   $t8, $t7, 2
/* 0F21B8 7F0BD688 3C018009 */  lui   $at, %hi(dword_CODE_bss_8008C254)
/* 0F21BC 7F0BD68C 00581021 */  addu  $v0, $v0, $t8
/* 0F21C0 7F0BD690 AC2EC254 */  sw    $t6, %lo(dword_CODE_bss_8008C254)($at)
/* 0F21C4 7F0BD694 03E00008 */  jr    $ra
/* 0F21C8 7F0BD698 8C42C230 */   lw    $v0, %lo(ptr_mgfx0_alloc_start)($v0)
)
#endif





#ifdef NONMATCHING
void allocate_something_in_mgfx(void) {

}
#else
GLOBAL_ASM(
.text
glabel allocate_something_in_mgfx
/* 0F21CC 7F0BD69C 3C0E8009 */  lui   $t6, %hi(bank_in_mgfx_alloc_table) 
/* 0F21D0 7F0BD6A0 91CEC250 */  lbu   $t6, %lo(bank_in_mgfx_alloc_table)($t6)
/* 0F21D4 7F0BD6A4 3C188009 */  lui   $t8, %hi(ptr_mgfx1_alloc_start)
/* 0F21D8 7F0BD6A8 000E7880 */  sll   $t7, $t6, 2
/* 0F21DC 7F0BD6AC 030FC021 */  addu  $t8, $t8, $t7
/* 0F21E0 7F0BD6B0 8F18C234 */  lw    $t8, %lo(ptr_mgfx1_alloc_start)($t8)
/* 0F21E4 7F0BD6B4 03041023 */  subu  $v0, $t8, $a0
/* 0F21E8 7F0BD6B8 0002C8C3 */  sra   $t9, $v0, 3
/* 0F21EC 7F0BD6BC 03E00008 */  jr    $ra
/* 0F21F0 7F0BD6C0 03201025 */   move  $v0, $t9
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0BD6C4(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0BD6C4
/* 0F21F4 7F0BD6C4 3C068009 */  lui   $a2, %hi(ptr_mvtx_cur_pos)
/* 0F21F8 7F0BD6C8 24C6C24C */  addiu $a2, %lo(ptr_mvtx_cur_pos) # addiu $a2, $a2, -0x3db4
/* 0F21FC 7F0BD6CC 8CC20000 */  lw    $v0, ($a2)
/* 0F2200 7F0BD6D0 00047100 */  sll   $t6, $a0, 4
/* 0F2204 7F0BD6D4 004E7821 */  addu  $t7, $v0, $t6
/* 0F2208 7F0BD6D8 03E00008 */  jr    $ra
/* 0F220C 7F0BD6DC ACCF0000 */   sw    $t7, ($a2)
)
#endif





#ifdef NONMATCHING
s32 sub_GAME_7F0BD6E0(void) {
    // Node 0
    ptr_mvtx_cur_pos = (s32) (ptr_mvtx_cur_pos + 0x40);
    return ptr_mvtx_cur_pos;
}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0BD6E0
/* 0F2210 7F0BD6E0 3C058009 */  lui   $a1, %hi(ptr_mvtx_cur_pos)
/* 0F2214 7F0BD6E4 24A5C24C */  addiu $a1, %lo(ptr_mvtx_cur_pos) # addiu $a1, $a1, -0x3db4
/* 0F2218 7F0BD6E8 8CA20000 */  lw    $v0, ($a1)
/* 0F221C 7F0BD6EC 244E0040 */  addiu $t6, $v0, 0x40
/* 0F2220 7F0BD6F0 03E00008 */  jr    $ra
/* 0F2224 7F0BD6F4 ACAE0000 */   sw    $t6, ($a1)
)
#endif





#ifdef NONMATCHING
s32 sub_GAME_7F0BD6F8(s32 arg0) {
    // Node 0
    ptr_mvtx_cur_pos = (s32) (ptr_mvtx_cur_pos + (arg0 * 0x10));
    return ptr_mvtx_cur_pos;
}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0BD6F8
/* 0F2228 7F0BD6F8 3C068009 */  lui   $a2, %hi(ptr_mvtx_cur_pos)
/* 0F222C 7F0BD6FC 24C6C24C */  addiu $a2, %lo(ptr_mvtx_cur_pos) # addiu $a2, $a2, -0x3db4
/* 0F2230 7F0BD700 8CC20000 */  lw    $v0, ($a2)
/* 0F2234 7F0BD704 00047100 */  sll   $t6, $a0, 4
/* 0F2238 7F0BD708 004E7821 */  addu  $t7, $v0, $t6
/* 0F223C 7F0BD70C 03E00008 */  jr    $ra
/* 0F2240 7F0BD710 ACCF0000 */   sw    $t7, ($a2)
)
#endif





#ifdef NONMATCHING
s32 sub_GAME_7F0BD714(s32 arg0) {
    // Node 0
    ptr_mvtx_cur_pos = (s32) (ptr_mvtx_cur_pos + (((arg0 + 0xf) | 0xf) ^ 0xf));
    return ptr_mvtx_cur_pos;
}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0BD714
/* 0F2244 7F0BD714 3C068009 */  lui   $a2, %hi(ptr_mvtx_cur_pos)
/* 0F2248 7F0BD718 24C6C24C */  addiu $a2, %lo(ptr_mvtx_cur_pos) # addiu $a2, $a2, -0x3db4
/* 0F224C 7F0BD71C 8CC20000 */  lw    $v0, ($a2)
/* 0F2250 7F0BD720 2484000F */  addiu $a0, $a0, 0xf
/* 0F2254 7F0BD724 348E000F */  ori   $t6, $a0, 0xf
/* 0F2258 7F0BD728 39CF000F */  xori  $t7, $t6, 0xf
/* 0F225C 7F0BD72C 004FC021 */  addu  $t8, $v0, $t7
/* 0F2260 7F0BD730 03E00008 */  jr    $ra
/* 0F2264 7F0BD734 ACD80000 */   sw    $t8, ($a2)
)
#endif





#ifdef NONMATCHING
void *allocate_something_in_mvtx(void) {
    // Node 0
    bank_in_mgfx_alloc_table = (s8) (bank_in_mgfx_alloc_table ^ 1);
    dword_CODE_bss_8008C254 = 0;
    ptr_mvtx_cur_pos = (?32) (0x80090000 + (bank_in_mgfx_alloc_table * 4))->unk-3DC0;
    return &bank_in_mgfx_alloc_table;
}
#else
GLOBAL_ASM(
.text
glabel allocate_something_in_mvtx
/* 0F2268 7F0BD738 3C028009 */  lui   $v0, %hi(bank_in_mgfx_alloc_table)
/* 0F226C 7F0BD73C 2442C250 */  addiu $v0, %lo(bank_in_mgfx_alloc_table) # addiu $v0, $v0, -0x3db0
/* 0F2270 7F0BD740 904E0000 */  lbu   $t6, ($v0)
/* 0F2274 7F0BD744 3C018009 */  lui   $at, %hi(dword_CODE_bss_8008C254)
/* 0F2278 7F0BD748 3C088009 */  lui   $t0, %hi(ptr_mvtx0_alloc_start)
/* 0F227C 7F0BD74C 39CF0001 */  xori  $t7, $t6, 1
/* 0F2280 7F0BD750 A04F0000 */  sb    $t7, ($v0)
/* 0F2284 7F0BD754 AC20C254 */  sw    $zero, %lo(dword_CODE_bss_8008C254)($at)
/* 0F2288 7F0BD758 90580000 */  lbu   $t8, ($v0)
/* 0F228C 7F0BD75C 3C018009 */  lui   $at, %hi(ptr_mvtx_cur_pos)
/* 0F2290 7F0BD760 0018C880 */  sll   $t9, $t8, 2
/* 0F2294 7F0BD764 01194021 */  addu  $t0, $t0, $t9
/* 0F2298 7F0BD768 8D08C240 */  lw    $t0, %lo(ptr_mvtx0_alloc_start)($t0)
/* 0F229C 7F0BD76C 03E00008 */  jr    $ra
/* 0F22A0 7F0BD770 AC28C24C */   sw    $t0, %lo(ptr_mvtx_cur_pos)($at)
)
#endif





void removed_debug_routine(s32 arg0) {
    return;
}






#ifdef NONMATCHING
s32 num_microcode_cmds_that_fit(s32 arg0) {
    // Node 0
    return ((s32) ((0x80090000 + (bank_in_mgfx_alloc_table * 4))->unk-3DCC - arg0) >> 3);
}
#else
GLOBAL_ASM(
.text
glabel num_microcode_cmds_that_fit
/* 0F22AC 7F0BD77C 3C0E8009 */  lui   $t6, %hi(bank_in_mgfx_alloc_table) 
/* 0F22B0 7F0BD780 91CEC250 */  lbu   $t6, %lo(bank_in_mgfx_alloc_table)($t6)
/* 0F22B4 7F0BD784 3C188009 */  lui   $t8, %hi(ptr_mgfx1_alloc_start)
/* 0F22B8 7F0BD788 000E7880 */  sll   $t7, $t6, 2
/* 0F22BC 7F0BD78C 030FC021 */  addu  $t8, $t8, $t7
/* 0F22C0 7F0BD790 8F18C234 */  lw    $t8, %lo(ptr_mgfx1_alloc_start)($t8)
/* 0F22C4 7F0BD794 03041023 */  subu  $v0, $t8, $a0
/* 0F22C8 7F0BD798 0002C8C3 */  sra   $t9, $v0, 3
/* 0F22CC 7F0BD79C 03E00008 */  jr    $ra
/* 0F22D0 7F0BD7A0 03201025 */   move  $v0, $t9
)
#endif





#ifdef NONMATCHING
s32 sub_GAME_7F0BD7A4(void) {
    // Node 0
    return ((0x80090000 + (bank_in_mgfx_alloc_table * 4))->unk-3DBC - ptr_mvtx_cur_pos);
}

#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0BD7A4
/* 0F22D4 7F0BD7A4 3C0E8009 */  lui   $t6, %hi(bank_in_mgfx_alloc_table) 
/* 0F22D8 7F0BD7A8 91CEC250 */  lbu   $t6, %lo(bank_in_mgfx_alloc_table)($t6)
/* 0F22DC 7F0BD7AC 3C188009 */  lui   $t8, %hi(ptr_mvtx1_alloc_start)
/* 0F22E0 7F0BD7B0 3C198009 */  lui   $t9, %hi(ptr_mvtx_cur_pos) 
/* 0F22E4 7F0BD7B4 000E7880 */  sll   $t7, $t6, 2
/* 0F22E8 7F0BD7B8 030FC021 */  addu  $t8, $t8, $t7
/* 0F22EC 7F0BD7BC 8F18C244 */  lw    $t8, %lo(ptr_mvtx1_alloc_start)($t8)
/* 0F22F0 7F0BD7C0 8F39C24C */  lw    $t9, %lo(ptr_mvtx_cur_pos)($t9)
/* 0F22F4 7F0BD7C4 03E00008 */  jr    $ra
/* 0F22F8 7F0BD7C8 03191023 */   subu  $v0, $t8, $t9
)
#endif





#ifdef NONMATCHING
void compute_membar_display_string(void) {

}
#else
GLOBAL_ASM(
.text
glabel compute_membar_display_string
/* 0F22FC 7F0BD7CC 44856000 */  mtc1  $a1, $f12
/* 0F2300 7F0BD7D0 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0F2304 7F0BD7D4 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0F2308 7F0BD7D8 AFA60020 */  sw    $a2, 0x20($sp)
/* 0F230C 7F0BD7DC 0C004E1F */  jal   strlen
/* 0F2310 7F0BD7E0 E7AC001C */   swc1  $f12, 0x1c($sp)
/* 0F2314 7F0BD7E4 C7AC001C */  lwc1  $f12, 0x1c($sp)
/* 0F2318 7F0BD7E8 C7A40020 */  lwc1  $f4, 0x20($sp)
/* 0F231C 7F0BD7EC 44800000 */  mtc1  $zero, $f0
/* 0F2320 7F0BD7F0 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0F2324 7F0BD7F4 46046303 */  div.s $f12, $f12, $f4
/* 0F2328 7F0BD7F8 4600603C */  c.lt.s $f12, $f0
/* 0F232C 7F0BD7FC 00000000 */  nop   
/* 0F2330 7F0BD800 45000001 */  bc1f  .L7F0BD808
/* 0F2334 7F0BD804 00000000 */   nop   
.L7F0BD808:
/* 0F2338 7F0BD808 03E00008 */  jr    $ra
/* 0F233C 7F0BD80C 27BD0018 */   addiu $sp, $sp, 0x18
)
#endif





#ifdef NONMATCHING
void draw_membars(s32 arg0) {
    void *temp_t7;
    void *temp_t7_2;

    // Node 0
    temp_t7 = (&ptr_mgfx0_alloc_start + (bank_in_mgfx_alloc_table * 4));
    compute_membar_display_string(&membars_string2, (f32) ((s32) (temp_t7->unk4 - arg0) >> 3), (f32) ((s32) (temp_t7->unk4 - *(&ptr_mgfx0_alloc_start + (bank_in_mgfx_alloc_table * 4))) >> 3), arg0);
    temp_t7_2 = (&ptr_mvtx0_alloc_start + (bank_in_mgfx_alloc_table * 4));
    return compute_membar_display_string(&membars_string2, (f32) (temp_t7_2->unk4 - ptr_mvtx_cur_pos), (f32) (temp_t7_2->unk4 - *(&ptr_mvtx0_alloc_start + (bank_in_mgfx_alloc_table * 4))), &ptr_mvtx0_alloc_start);
}
#else
GLOBAL_ASM(
.text
glabel draw_membars
/* 0F2340 7F0BD810 3C028009 */  lui   $v0, %hi(bank_in_mgfx_alloc_table)
/* 0F2344 7F0BD814 9042C250 */  lbu   $v0, %lo(bank_in_mgfx_alloc_table)($v0)
/* 0F2348 7F0BD818 3C088009 */  lui   $t0, %hi(ptr_mgfx0_alloc_start) 
/* 0F234C 7F0BD81C 2508C230 */  addiu $t0, %lo(ptr_mgfx0_alloc_start) # addiu $t0, $t0, -0x3dd0
/* 0F2350 7F0BD820 00027080 */  sll   $t6, $v0, 2
/* 0F2354 7F0BD824 010E7821 */  addu  $t7, $t0, $t6
/* 0F2358 7F0BD828 00024880 */  sll   $t1, $v0, 2
/* 0F235C 7F0BD82C 8DE30004 */  lw    $v1, 4($t7)
/* 0F2360 7F0BD830 01095021 */  addu  $t2, $t0, $t1
/* 0F2364 7F0BD834 8D4B0000 */  lw    $t3, ($t2)
/* 0F2368 7F0BD838 00803825 */  move  $a3, $a0
/* 0F236C 7F0BD83C 0067C023 */  subu  $t8, $v1, $a3
/* 0F2370 7F0BD840 006B6023 */  subu  $t4, $v1, $t3
/* 0F2374 7F0BD844 000C68C3 */  sra   $t5, $t4, 3
/* 0F2378 7F0BD848 0018C8C3 */  sra   $t9, $t8, 3
/* 0F237C 7F0BD84C 44992000 */  mtc1  $t9, $f4
/* 0F2380 7F0BD850 448D3000 */  mtc1  $t5, $f6
/* 0F2384 7F0BD854 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0F2388 7F0BD858 46802120 */  cvt.s.w $f4, $f4
/* 0F238C 7F0BD85C AFBF0014 */  sw    $ra, 0x14($sp)
/* 0F2390 7F0BD860 3C048005 */  lui   $a0, %hi(membars_string2)
/* 0F2394 7F0BD864 24848320 */  addiu $a0, %lo(membars_string2) # addiu $a0, $a0, -0x7ce0
/* 0F2398 7F0BD868 468031A0 */  cvt.s.w $f6, $f6
/* 0F239C 7F0BD86C 44052000 */  mfc1  $a1, $f4
/* 0F23A0 7F0BD870 44063000 */  mfc1  $a2, $f6
/* 0F23A4 7F0BD874 0FC2F5F3 */  jal   compute_membar_display_string
/* 0F23A8 7F0BD878 00000000 */   nop   
/* 0F23AC 7F0BD87C 3C028009 */  lui   $v0, %hi(bank_in_mgfx_alloc_table)
/* 0F23B0 7F0BD880 9042C250 */  lbu   $v0, %lo(bank_in_mgfx_alloc_table)($v0)
/* 0F23B4 7F0BD884 3C078009 */  lui   $a3, %hi(ptr_mvtx0_alloc_start)
/* 0F23B8 7F0BD888 24E7C240 */  addiu $a3, %lo(ptr_mvtx0_alloc_start) # addiu $a3, $a3, -0x3dc0
/* 0F23BC 7F0BD88C 00027080 */  sll   $t6, $v0, 2
/* 0F23C0 7F0BD890 00EE7821 */  addu  $t7, $a3, $t6
/* 0F23C4 7F0BD894 00024880 */  sll   $t1, $v0, 2
/* 0F23C8 7F0BD898 8DE30004 */  lw    $v1, 4($t7)
/* 0F23CC 7F0BD89C 00E95021 */  addu  $t2, $a3, $t1
/* 0F23D0 7F0BD8A0 3C188009 */  lui   $t8, %hi(ptr_mvtx_cur_pos) 
/* 0F23D4 7F0BD8A4 8F18C24C */  lw    $t8, %lo(ptr_mvtx_cur_pos)($t8)
/* 0F23D8 7F0BD8A8 8D4B0000 */  lw    $t3, ($t2)
/* 0F23DC 7F0BD8AC 3C048005 */  lui   $a0, %hi(membars_string2)
/* 0F23E0 7F0BD8B0 0078C823 */  subu  $t9, $v1, $t8
/* 0F23E4 7F0BD8B4 006B6023 */  subu  $t4, $v1, $t3
/* 0F23E8 7F0BD8B8 448C5000 */  mtc1  $t4, $f10
/* 0F23EC 7F0BD8BC 44994000 */  mtc1  $t9, $f8
/* 0F23F0 7F0BD8C0 24848320 */  addiu $a0, %lo(membars_string2) # addiu $a0, $a0, -0x7ce0
/* 0F23F4 7F0BD8C4 468052A0 */  cvt.s.w $f10, $f10
/* 0F23F8 7F0BD8C8 46804220 */  cvt.s.w $f8, $f8
/* 0F23FC 7F0BD8CC 44065000 */  mfc1  $a2, $f10
/* 0F2400 7F0BD8D0 44054000 */  mfc1  $a1, $f8
/* 0F2404 7F0BD8D4 0FC2F5F3 */  jal   compute_membar_display_string
/* 0F2408 7F0BD8D8 00000000 */   nop   
/* 0F240C 7F0BD8DC 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0F2410 7F0BD8E0 27BD0018 */  addiu $sp, $sp, 0x18
/* 0F2414 7F0BD8E4 03E00008 */  jr    $ra
/* 0F2418 7F0BD8E8 00000000 */   nop   
)
#endif


