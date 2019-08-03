#include "ultra64.h"

// bss
char dword_CODE_bss_8008D370[0x400];
char dword_CODE_bss_8008D770[0xBA0];



s32 D_8004E9E0 = 0;
s32 D_8004E9E4 = 0;
s32 D_8004E9E8 = 0;
s32 D_8004E9EC = 0;
//make me a struct
//D:8004E9F0
u32 fast3d_related_0[] = {
    0, 0, 0, 0, 1, 2, 0, 0, 0, 0x1000, 0, 0x800, dword_CODE_bss_8008D370,0x400, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};

//im another instance of above struct
//D:8004EA50
u32 fast3d_related_1[] = {
    0, 0, 0, 0, 1, 2, 0, 0, 0, 0x1000, 0, 0x800, dword_CODE_bss_8008D370,0x400, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};

//D:8004EAB0
u32 *fast3d_related_array = &fast3d_related_0;




void something_with_rsp_c_debug(void) {
    get_ptr_debug_notice_list_entry(&D_8004E9E0, "rsp_c_debug");
}






#ifdef NONMATCHING
void allocate_init_rsp_buffers(void) {
    ? temp_ret;

    // Node 0
    temp_ret = allocate_bytes_in_bank(0xa000, 6);
    D_8004E9E8 = temp_ret;
    D_8004E9E4 = (s32) (temp_ret + 0xa000);
    return;
    // (possible return value: temp_ret)
}

#else
GLOBAL_ASM(
.text
glabel allocate_init_rsp_buffers
/* 10490C 7F0CFDDC 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 104910 7F0CFDE0 AFBF0014 */  sw    $ra, 0x14($sp)
/* 104914 7F0CFDE4 3404A000 */  li    $a0, 40960
/* 104918 7F0CFDE8 0C0025C8 */  jal   allocate_bytes_in_bank
/* 10491C 7F0CFDEC 24050006 */   li    $a1, 6
/* 104920 7F0CFDF0 8FBF0014 */  lw    $ra, 0x14($sp)
/* 104924 7F0CFDF4 3C038005 */  lui   $v1, %hi(D_8004E9E8) # $v1, 0x8005
/* 104928 7F0CFDF8 3401A000 */  li    $at, 40960
/* 10492C 7F0CFDFC 2463E9E8 */  addiu $v1, %lo(D_8004E9E8) # addiu $v1, $v1, -0x1618
/* 104930 7F0CFE00 00417821 */  addu  $t7, $v0, $at
/* 104934 7F0CFE04 AC620000 */  sw    $v0, ($v1)
/* 104938 7F0CFE08 3C018005 */  lui   $at, %hi(D_8004E9E4) # $at, 0x8005
/* 10493C 7F0CFE0C AC2FE9E4 */  sw    $t7, %lo(D_8004E9E4)($at)
/* 104940 7F0CFE10 03E00008 */  jr    $ra
/* 104944 7F0CFE14 27BD0018 */   addiu $sp, $sp, 0x18
)
#endif





#ifdef NONMATCHING
void *load_rsp_microcode(s32 arg0, s32 arg1, ? arg2, ?32 arg3) {
    void *temp_v0;

    // Node 0
    fast3d_related_array->unk18 = &rspbootTextStart;
    fast3d_related_array->unk1C = (s32) (&gsp3DTextStart - &rspbootTextStart);
    temp_v0 = (fast3d_related_array + 0x10);
    temp_v0->unk10 = &gsp3DTextStart;
    temp_v0->unk18 = &gsp3DDataStart;
    temp_v0->unk28 = (?32) D_8004E9E8;
    temp_v0->unk30 = arg0;
    temp_v0->unk34 = (s32) (((s32) (arg1 - arg0) >> 3) * 8);
    temp_v0->unk38 = &dword_CODE_bss_8008D770;
    temp_v0->unk3C = 0xba0;
    temp_v0->unk2C = (?32) D_8004E9E4;
    *fast3d_related_array = 0;
    fast3d_related_array->unk8 = 0x63;
    fast3d_related_array->unk50 = &gfxFrameMsgQ;
    fast3d_related_array->unk54 = arg3;
    fast3d_related_array->unkC = (?32) fast3d_related_array->unk58;
    osWritebackDCacheAll();
    osSendMesg(mq, fast3d_related_array, 1);
    fast3d_related_array = (void *) (((s32) fast3d_related_array ^ &fast3d_related_0) ^ &fast3d_related_1);
    return;
    // (possible return value: &fast3d_related_array)
}

#else
GLOBAL_ASM(
.text
glabel load_rsp_microcode
/* 104948 7F0CFE18 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 10494C 7F0CFE1C 3C038005 */  lui   $v1, %hi(fast3d_related_array) # $v1, 0x8005
/* 104950 7F0CFE20 2463EAB0 */  addiu $v1, %lo(fast3d_related_array) # addiu $v1, $v1, -0x1550
/* 104954 7F0CFE24 AFB00018 */  sw    $s0, 0x18($sp)
/* 104958 7F0CFE28 8C700000 */  lw    $s0, ($v1)
/* 10495C 7F0CFE2C 3C028002 */  lui   $v0, %hi(rspbootTextStart) # $v0, 0x8002
/* 104960 7F0CFE30 3C0E8002 */  lui   $t6, %hi(gsp3DTextStart) # $t6, 0x8002
/* 104964 7F0CFE34 24420D90 */  addiu $v0, %lo(rspbootTextStart) # addiu $v0, $v0, 0xd90
/* 104968 7F0CFE38 25CE0E60 */  addiu $t6, %lo(gsp3DTextStart) # addiu $t6, $t6, 0xe60
/* 10496C 7F0CFE3C AFBF001C */  sw    $ra, 0x1c($sp)
/* 104970 7F0CFE40 AFA60028 */  sw    $a2, 0x28($sp)
/* 104974 7F0CFE44 01C27823 */  subu  $t7, $t6, $v0
/* 104978 7F0CFE48 AE020018 */  sw    $v0, 0x18($s0)
/* 10497C 7F0CFE4C 3C188002 */  lui   $t8, %hi(gsp3DTextStart) # $t8, 0x8002
/* 104980 7F0CFE50 3C198006 */  lui   $t9, %hi(gsp3DDataStart) # $t9, 0x8006
/* 104984 7F0CFE54 AE0F001C */  sw    $t7, 0x1c($s0)
/* 104988 7F0CFE58 26020010 */  addiu $v0, $s0, 0x10
/* 10498C 7F0CFE5C 27180E60 */  addiu $t8, %lo(gsp3DTextStart) # addiu $t8, $t8, 0xe60
/* 104990 7F0CFE60 2739C820 */  addiu $t9, %lo(gsp3DDataStart) # addiu $t9, $t9, -0x37e0
/* 104994 7F0CFE64 AC580010 */  sw    $t8, 0x10($v0)
/* 104998 7F0CFE68 AC590018 */  sw    $t9, 0x18($v0)
/* 10499C 7F0CFE6C 3C088005 */  lui   $t0, %hi(D_8004E9E8) # $t0, 0x8005
/* 1049A0 7F0CFE70 8D08E9E8 */  lw    $t0, %lo(D_8004E9E8)($t0)
/* 1049A4 7F0CFE74 3C098005 */  lui   $t1, %hi(D_8004E9E4) # $t1, 0x8005
/* 1049A8 7F0CFE78 00A45023 */  subu  $t2, $a1, $a0
/* 1049AC 7F0CFE7C AC480028 */  sw    $t0, 0x28($v0)
/* 1049B0 7F0CFE80 8D29E9E4 */  lw    $t1, %lo(D_8004E9E4)($t1)
/* 1049B4 7F0CFE84 000A58C3 */  sra   $t3, $t2, 3
/* 1049B8 7F0CFE88 3C0D8009 */  lui   $t5, %hi(dword_CODE_bss_8008D770) # $t5, 0x8009
/* 1049BC 7F0CFE8C 000B60C0 */  sll   $t4, $t3, 3
/* 1049C0 7F0CFE90 25ADD770 */  addiu $t5, %lo(dword_CODE_bss_8008D770) # addiu $t5, $t5, -0x2890
/* 1049C4 7F0CFE94 240E0BA0 */  li    $t6, 2976
/* 1049C8 7F0CFE98 AC440030 */  sw    $a0, 0x30($v0)
/* 1049CC 7F0CFE9C AC4C0034 */  sw    $t4, 0x34($v0)
/* 1049D0 7F0CFEA0 AC4D0038 */  sw    $t5, 0x38($v0)
/* 1049D4 7F0CFEA4 AC4E003C */  sw    $t6, 0x3c($v0)
/* 1049D8 7F0CFEA8 AC49002C */  sw    $t1, 0x2c($v0)
/* 1049DC 7F0CFEAC 3C188006 */  lui   $t8, %hi(gfxFrameMsgQ) # $t8, 0x8006
/* 1049E0 7F0CFEB0 240F0063 */  li    $t7, 99
/* 1049E4 7F0CFEB4 2718D9A0 */  addiu $t8, %lo(gfxFrameMsgQ) # addiu $t8, $t8, -0x2660
/* 1049E8 7F0CFEB8 AE000000 */  sw    $zero, ($s0)
/* 1049EC 7F0CFEBC AE0F0008 */  sw    $t7, 8($s0)
/* 1049F0 7F0CFEC0 AE180050 */  sw    $t8, 0x50($s0)
/* 1049F4 7F0CFEC4 AE070054 */  sw    $a3, 0x54($s0)
/* 1049F8 7F0CFEC8 8C790000 */  lw    $t9, ($v1)
/* 1049FC 7F0CFECC 8F280058 */  lw    $t0, 0x58($t9)
/* 104A00 7F0CFED0 0C0034C8 */  jal   osWritebackDCacheAll
/* 104A04 7F0CFED4 AE08000C */   sw    $t0, 0xc($s0)
/* 104A08 7F0CFED8 3C048006 */  lui   $a0, %hi(sched_cmdQ) # $a0, 0x8006
/* 104A0C 7F0CFEDC 8C84DA38 */  lw    $a0, %lo(sched_cmdQ)($a0)
/* 104A10 7F0CFEE0 02002825 */  move  $a1, $s0
/* 104A14 7F0CFEE4 0C0037C4 */  jal   osSendMesg
/* 104A18 7F0CFEE8 24060001 */   li    $a2, 1
/* 104A1C 7F0CFEEC 3C028005 */  lui   $v0, %hi(fast3d_related_array) # $v0, 0x8005
/* 104A20 7F0CFEF0 2442EAB0 */  addiu $v0, %lo(fast3d_related_array) # addiu $v0, $v0, -0x1550
/* 104A24 7F0CFEF4 8C490000 */  lw    $t1, ($v0)
/* 104A28 7F0CFEF8 3C0A8005 */  lui   $t2, %hi(fast3d_related_0) # $t2, 0x8005
/* 104A2C 7F0CFEFC 8FBF001C */  lw    $ra, 0x1c($sp)
/* 104A30 7F0CFF00 254AE9F0 */  addiu $t2, %lo(fast3d_related_0) # addiu $t2, $t2, -0x1610
/* 104A34 7F0CFF04 3C0C8005 */  lui   $t4, %hi(fast3d_related_1) # $t4, 0x8005
/* 104A38 7F0CFF08 258CEA50 */  addiu $t4, %lo(fast3d_related_1) # addiu $t4, $t4, -0x15b0
/* 104A3C 7F0CFF0C 012A5826 */  xor   $t3, $t1, $t2
/* 104A40 7F0CFF10 016C6826 */  xor   $t5, $t3, $t4
/* 104A44 7F0CFF14 8FB00018 */  lw    $s0, 0x18($sp)
/* 104A48 7F0CFF18 AC4D0000 */  sw    $t5, ($v0)
/* 104A4C 7F0CFF1C 03E00008 */  jr    $ra
/* 104A50 7F0CFF20 27BD0020 */   addiu $sp, $sp, 0x20
)
#endif




