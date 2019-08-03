#include "ultra64.h"
#include "memp.h"
/**
 * @file memp.c
 * This file contains code for memp.
 */

char memory_bank_ptrs[0x8];
char D_80063BB8[0x8];
char D_80063BC0[0x4];
char D_80063BC4[0x4];
char D_80063BC8[0x8];
char D_80063BD0[0x4];
char D_80063BD4[0x4];
char D_80063BD8[0x8];
char D_80063BE0[4];
char D_80063BE4[4];
char D_80063BE8[8];
u32 *ptr_model_room_buf_pri;
char dword_CODE_bss_80063BF8[0x24];
s32 dword_CODE_bss_80063C1C;

void *ptr_memp_c_debug_debug_notice_list = 0;
s32 tied_to_mem_management[] = {0, 0, 0, 0};
s32 D_80024414 = 2;
s32 D_80024418 = 0;
s32 D_8002441C = 4;
s32 D_80024420 = 0x52;
s32 D_80024424 = 6;
s32 D_80024428 = 0xF;
s32 D_8002442C = 0;
s32 D_80024430 = 0;
s32 D_80024434 = 0;
s32 D_80024438 = 0;
s32 D_8002443C = 0;
s32 D_80024440 = 0;
s32 D_80024444 = 0;
s32 D_80024448 = 0;
s32 D_8002444C = 0;

const char aMemp_c_debug[] = "memp_c_debug";
const char aMf[] = "-mf";
const char aMf_0[] = "-mf";
const char aMl[] = "-ml";
const char aMl_0[] = "-ml";
const char aMe[] = "-me";
const char aMe_0[] = "-me";




/**
 * 9F80	70009380
 *     V0=p->debug.notice.list entry for memp_c_debug
 */
void something_with_memp_c_debug(void) {

    get_ptr_debug_notice_list_entry(&ptr_memp_c_debug_debug_notice_list, &aMemp_c_debug); //should be "memp_c_debug"
}






/**
 * 9FAC	700093AC
 *     initialize memory allocation table and set font and text bank sizes
 *     accepts: A0=p->buffer, A1=size
 *     uses "-mf", "-ml", "-me" strings
 */
#ifdef NONMATCHING
void check_memflag_tokens(s32 arg0, s32 arg1, s32 arg11) {
    ? sp20;
    s32 sp24;
    s32 sp2C;
    s32 sp34;
    s32 temp_v1;

    // Node 0
    memory_bank_ptrs = arg0;
    memory_bank_ptrs.unk8 = (s32) (arg0 + arg1);
    sp20 = (?32) D_80024414;
    sp20.unk4 = (?32) D_80024414.unk4;
    sp20.unkC = (?32) D_80024414.unkC;
    sp20.unk8 = (?32) D_80024414.unk8;
    sp20.unk10 = (?32) D_80024414.unk10;
    sp20.unk14 = (?32) D_80024414.unk14;
    sp20.unk1C = (?32) D_80024414.unk1C;
    sp20.unk18 = (?32) D_80024414.unk18;
    if (check_token(1, &aMf) != 0)
    {
        // Node 1
        sp24 = strtol(check_token(1, &aMf_0), 0, 0);
    }
    // Node 2
    if (check_token(1, &aMl) != 0)
    {
        // Node 3
        sp2C = strtol(check_token(1, &aMl_0), 0, 0);
    }
    // Node 4
    if (check_token(1, &aMe) != 0)
    {
        // Node 5
        sp34 = strtol(check_token(1, &aMe_0), 0, 0);
    }
    // Node 6
    if (sp34 == 0)
    {
        // Node 7
        sp24 = 0;
        if (j_text_trigger != 0)
        {
            // Node 8
        }
        // Node 9
        temp_v1 = (0x128 << 0xa);
        sp2C = (s32) (arg11 - temp_v1);
        sp34 = temp_v1;
    }
    // Node 10
    memp_related_0(&sp20);
    return;
    // (possible return value: memp_related_0(&sp20))
}
#else
GLOBAL_ASM(
.text
glabel check_memflag_tokens
/* 009FAC 700093AC 3C028006 */  lui   $v0, %hi(memory_bank_ptrs) # $v0, 0x8006
/* 009FB0 700093B0 24423BB0 */  addiu $v0, %lo(memory_bank_ptrs) # addiu $v0, $v0, 0x3bb0
/* 009FB4 700093B4 27BDFFC0 */  addiu $sp, $sp, -0x40
/* 009FB8 700093B8 00857821 */  addu  $t7, $a0, $a1
/* 009FBC 700093BC 3C198002 */  lui   $t9, %hi(D_80024414) # $t9, 0x8002
/* 009FC0 700093C0 AFBF0014 */  sw    $ra, 0x14($sp)
/* 009FC4 700093C4 AFA50044 */  sw    $a1, 0x44($sp)
/* 009FC8 700093C8 AC440000 */  sw    $a0, ($v0)
/* 009FCC 700093CC AC4F0008 */  sw    $t7, 8($v0)
/* 009FD0 700093D0 27394414 */  addiu $t9, %lo(D_80024414) # addiu $t9, $t9, 0x4414
/* 009FD4 700093D4 8F210000 */  lw    $at, ($t9)
/* 009FD8 700093D8 8F290004 */  lw    $t1, 4($t9)
/* 009FDC 700093DC 27B80020 */  addiu $t8, $sp, 0x20
/* 009FE0 700093E0 AF010000 */  sw    $at, ($t8)
/* 009FE4 700093E4 AF090004 */  sw    $t1, 4($t8)
/* 009FE8 700093E8 8F29000C */  lw    $t1, 0xc($t9)
/* 009FEC 700093EC 8F210008 */  lw    $at, 8($t9)
/* 009FF0 700093F0 3C058003 */  lui   $a1, %hi(aMf) # $a1, 0x8003
/* 009FF4 700093F4 AF09000C */  sw    $t1, 0xc($t8)
/* 009FF8 700093F8 AF010008 */  sw    $at, 8($t8)
/* 009FFC 700093FC 8F210010 */  lw    $at, 0x10($t9)
/* 00A000 70009400 8F290014 */  lw    $t1, 0x14($t9)
/* 00A004 70009404 24A591B0 */  addiu $a1, %lo(aMf) # addiu $a1, $a1, -0x6e50
/* 00A008 70009408 AF010010 */  sw    $at, 0x10($t8)
/* 00A00C 7000940C AF090014 */  sw    $t1, 0x14($t8)
/* 00A010 70009410 8F29001C */  lw    $t1, 0x1c($t9)
/* 00A014 70009414 8F210018 */  lw    $at, 0x18($t9)
/* 00A018 70009418 24040001 */  li    $a0, 1
/* 00A01C 7000941C AF09001C */  sw    $t1, 0x1c($t8)
/* 00A020 70009420 0C0029A8 */  jal   check_token
/* 00A024 70009424 AF010018 */   sw    $at, 0x18($t8)
/* 00A028 70009428 10400009 */  beqz  $v0, .L70009450
/* 00A02C 7000942C 24040001 */   li    $a0, 1
/* 00A030 70009430 3C058003 */  lui   $a1, %hi(aMf_0) # $a1, 0x8003
/* 00A034 70009434 0C0029A8 */  jal   check_token
/* 00A038 70009438 24A591B4 */   addiu $a1, %lo(aMf_0) # addiu $a1, $a1, -0x6e4c
/* 00A03C 7000943C 00402025 */  move  $a0, $v0
/* 00A040 70009440 00002825 */  move  $a1, $zero
/* 00A044 70009444 0C002A78 */  jal   strtol
/* 00A048 70009448 00003025 */   move  $a2, $zero
/* 00A04C 7000944C AFA20024 */  sw    $v0, 0x24($sp)
.L70009450:
/* 00A050 70009450 3C058003 */  lui   $a1, %hi(aMl) # $a1, 0x8003
/* 00A054 70009454 24A591B8 */  addiu $a1, %lo(aMl) # addiu $a1, $a1, -0x6e48
/* 00A058 70009458 0C0029A8 */  jal   check_token
/* 00A05C 7000945C 24040001 */   li    $a0, 1
/* 00A060 70009460 10400009 */  beqz  $v0, .L70009488
/* 00A064 70009464 24040001 */   li    $a0, 1
/* 00A068 70009468 3C058003 */  lui   $a1, %hi(aMl_0) # $a1, 0x8003
/* 00A06C 7000946C 0C0029A8 */  jal   check_token
/* 00A070 70009470 24A591BC */   addiu $a1, %lo(aMl_0) # addiu $a1, $a1, -0x6e44
/* 00A074 70009474 00402025 */  move  $a0, $v0
/* 00A078 70009478 00002825 */  move  $a1, $zero
/* 00A07C 7000947C 0C002A78 */  jal   strtol
/* 00A080 70009480 00003025 */   move  $a2, $zero
/* 00A084 70009484 AFA2002C */  sw    $v0, 0x2c($sp)
.L70009488:
/* 00A088 70009488 3C058003 */  lui   $a1, %hi(aMe) # $a1, 0x8003
/* 00A08C 7000948C 24A591C0 */  addiu $a1, %lo(aMe) # addiu $a1, $a1, -0x6e40
/* 00A090 70009490 0C0029A8 */  jal   check_token
/* 00A094 70009494 24040001 */   li    $a0, 1
/* 00A098 70009498 10400009 */  beqz  $v0, .L700094C0
/* 00A09C 7000949C 24040001 */   li    $a0, 1
/* 00A0A0 700094A0 3C058003 */  lui   $a1, %hi(aMe_0) # $a1, 0x8003
/* 00A0A4 700094A4 0C0029A8 */  jal   check_token
/* 00A0A8 700094A8 24A591C4 */   addiu $a1, %lo(aMe_0) # addiu $a1, $a1, -0x6e3c
/* 00A0AC 700094AC 00402025 */  move  $a0, $v0
/* 00A0B0 700094B0 00002825 */  move  $a1, $zero
/* 00A0B4 700094B4 0C002A78 */  jal   strtol
/* 00A0B8 700094B8 00003025 */   move  $a2, $zero
/* 00A0BC 700094BC AFA20034 */  sw    $v0, 0x34($sp)
.L700094C0:
/* 00A0C0 700094C0 8FA30034 */  lw    $v1, 0x34($sp)
/* 00A0C4 700094C4 3C0A8005 */  lui   $t2, %hi(j_text_trigger) # $t2, 0x8005
/* 00A0C8 700094C8 1460000C */  bnez  $v1, .L700094FC
/* 00A0CC 700094CC 00000000 */   nop   
/* 00A0D0 700094D0 8D4A84D0 */  lw    $t2, %lo(j_text_trigger)($t2)
/* 00A0D4 700094D4 AFA00024 */  sw    $zero, 0x24($sp)
/* 00A0D8 700094D8 24020128 */  li    $v0, 296
/* 00A0DC 700094DC 11400003 */  beqz  $t2, .L700094EC
/* 00A0E0 700094E0 8FAB0044 */   lw    $t3, 0x44($sp)
/* 00A0E4 700094E4 10000001 */  b     .L700094EC
/* 00A0E8 700094E8 24020134 */   li    $v0, 308
.L700094EC:
/* 00A0EC 700094EC 00021A80 */  sll   $v1, $v0, 0xa
/* 00A0F0 700094F0 01636023 */  subu  $t4, $t3, $v1
/* 00A0F4 700094F4 AFAC002C */  sw    $t4, 0x2c($sp)
/* 00A0F8 700094F8 AFA30034 */  sw    $v1, 0x34($sp)
.L700094FC:
/* 00A0FC 700094FC 0C002545 */  jal   memp_related_0
/* 00A100 70009500 27A40020 */   addiu $a0, $sp, 0x20
/* 00A104 70009504 8FBF0014 */  lw    $ra, 0x14($sp)
/* 00A108 70009508 27BD0040 */  addiu $sp, $sp, 0x40
/* 00A10C 7000950C 03E00008 */  jr    $ra
/* 00A110 70009510 00000000 */   nop   
)
#endif





/**
 * A114	70009514
 *     initialize allocations using table A0
 *     accepts: A0=p->allocation sizes
 */
#ifdef NONMATCHING
void *memp_related_0(void *arg0) {
    s32 sp30;
    s32 sp34;
    s32 sp38;
    s32 sp3C;
    s32 sp60;
    s32 sp78;
    ? sp7C;
    u32 temp_s0;
    s32 temp_v1;
    ? temp_ret;
    u32 temp_s0_2;
    u32 temp_s0_3;
    s32 temp_v0;
    void *temp_v0_2;
    void *temp_s0_4;
    s32 temp_a0;
    s32 temp_a1;
    s32 temp_v1_2;

    // Node 0
    sp60 = (s32) D_80024434;
    sp60.unk4 = (s32) D_80024434.unk4;
    sp60.unk8 = (?32) D_80024434.unk8;
    sp60.unkC = (?32) D_80024434.unkC;
    sp60.unk10 = (?32) D_80024434.unk10;
    sp60.unk14 = (?32) D_80024434.unk14;
    sp60.unk18 = (?32) D_80024434.unk18;
    // Node 1
    *(&sp60 + (*arg0 * 4)) = (?32) arg0->unk4;
    if (arg0->unk8 != 0)
    {
        goto loop_1;
    }
    // Node 2
    // Node 3
    temp_s0 = (&sp60 + 4);
    *temp_s0 = (s32) (sp60.unk4 + sp60);
    if (temp_s0 < &sp78)
    {
        goto loop_3;
    }
    // Node 4
    temp_v1 = (memory_bank_ptrs.unk8 - memory_bank_ptrs);
    sp30 = (s32) (sp78 >> 0x1f);
    sp38 = (s32) (temp_v1 >> 0x1f);
    sp3C = temp_v1;
    sp34 = sp78;
    // Node 5
    temp_ret = __ll_mul(((s32) sp60 >> 0x1f), sp60, sp38, sp3C);
    temp_s0_2 = (&sp60 + 4);
    temp_s0_2->unk-4 = (u64) __ll_div(temp_ret, temp_ret, sp30, sp34);
    if (temp_s0_2 < &sp7C)
    {
        goto loop_5;
    }
    // Node 6
    // Node 7
    temp_s0_3 = (&sp60 + 4);
    temp_s0_3->unk-4 = (s32) ((sp60 | 0xf) ^ 0xf);
    if (temp_s0_3 < &sp7C)
    {
        goto loop_7;
    }
    // Node 8
    D_80063BC4 = (s32) (sp60 + memory_bank_ptrs);
    D_80063BC4 = 0;
    temp_v0 = (sp64 + memory_bank_ptrs);
    D_80063BC8 = temp_v0;
    D_80063BD4 = temp_v0;
    D_80063BD4 = 0;
    D_80063BD8 = (s32) (sp68 + memory_bank_ptrs);
    temp_v0_2 = (&memory_bank_ptrs + (2 * 0x10));
    temp_s0_4 = (&sp60 + (2 * 4));
    temp_a0 = (temp_s0_4->unk8 + memory_bank_ptrs);
    temp_a1 = (temp_s0_4->unkC + memory_bank_ptrs);
    temp_v1_2 = (temp_s0_4->unk4 + memory_bank_ptrs);
    temp_v0_2->unk48 = (s32) (temp_s0_4->unk10 + memory_bank_ptrs);
    temp_v0_2->unk20 = temp_v1_2;
    temp_v0_2->unk38 = temp_a1;
    temp_v0_2->unk40 = temp_a1;
    temp_v0_2->unk28 = temp_a0;
    temp_v0_2->unk30 = temp_a0;
    temp_v0_2->unk24 = 0;
    temp_v0_2->unk34 = 0;
    temp_v0_2->unk44 = 0;
    temp_v0_2->unk10 = (s32) (*temp_s0_4 + memory_bank_ptrs);
    temp_v0_2->unk14 = 0;
    temp_v0_2->unk18 = temp_v1_2;
    return;
    // (possible return value: temp_v0_2)
}
#else
GLOBAL_ASM(
.text
glabel memp_related_0
/* 00A114 70009514 27BDFF80 */  addiu $sp, $sp, -0x80
/* 00A118 70009518 3C0E8002 */  lui   $t6, %hi(D_80024434) # $t6, 0x8002
/* 00A11C 7000951C AFBF0024 */  sw    $ra, 0x24($sp)
/* 00A120 70009520 AFB30020 */  sw    $s3, 0x20($sp)
/* 00A124 70009524 AFB2001C */  sw    $s2, 0x1c($sp)
/* 00A128 70009528 AFB10018 */  sw    $s1, 0x18($sp)
/* 00A12C 7000952C AFB00014 */  sw    $s0, 0x14($sp)
/* 00A130 70009530 25CE4434 */  addiu $t6, %lo(D_80024434) # addiu $t6, $t6, 0x4434
/* 00A134 70009534 8DC10000 */  lw    $at, ($t6)
/* 00A138 70009538 27B20060 */  addiu $s2, $sp, 0x60
/* 00A13C 7000953C 3C138006 */  lui   $s3, %hi(memory_bank_ptrs) # $s3, 0x8006
/* 00A140 70009540 AE410000 */  sw    $at, ($s2)
/* 00A144 70009544 8DD90004 */  lw    $t9, 4($t6)
/* 00A148 70009548 00801025 */  move  $v0, $a0
/* 00A14C 7000954C 26733BB0 */  addiu $s3, %lo(memory_bank_ptrs) # addiu $s3, $s3, 0x3bb0
/* 00A150 70009550 AE590004 */  sw    $t9, 4($s2)
/* 00A154 70009554 8DC10008 */  lw    $at, 8($t6)
/* 00A158 70009558 27B00060 */  addiu $s0, $sp, 0x60
/* 00A15C 7000955C 27B1007C */  addiu $s1, $sp, 0x7c
/* 00A160 70009560 AE410008 */  sw    $at, 8($s2)
/* 00A164 70009564 8DD9000C */  lw    $t9, 0xc($t6)
/* 00A168 70009568 AE59000C */  sw    $t9, 0xc($s2)
/* 00A16C 7000956C 8DC10010 */  lw    $at, 0x10($t6)
/* 00A170 70009570 AE410010 */  sw    $at, 0x10($s2)
/* 00A174 70009574 8DD90014 */  lw    $t9, 0x14($t6)
/* 00A178 70009578 AE590014 */  sw    $t9, 0x14($s2)
/* 00A17C 7000957C 8DC10018 */  lw    $at, 0x18($t6)
/* 00A180 70009580 AE410018 */  sw    $at, 0x18($s2)
/* 00A184 70009584 8C830000 */  lw    $v1, ($a0)
/* 00A188 70009588 8C480004 */  lw    $t0, 4($v0)
.L7000958C:
/* 00A18C 7000958C 00034880 */  sll   $t1, $v1, 2
/* 00A190 70009590 02495021 */  addu  $t2, $s2, $t1
/* 00A194 70009594 AD480000 */  sw    $t0, ($t2)
/* 00A198 70009598 8C430008 */  lw    $v1, 8($v0)
/* 00A19C 7000959C 24420008 */  addiu $v0, $v0, 8
/* 00A1A0 700095A0 5460FFFA */  bnezl $v1, .L7000958C
/* 00A1A4 700095A4 8C480004 */   lw    $t0, 4($v0)
/* 00A1A8 700095A8 8E030000 */  lw    $v1, ($s0)
/* 00A1AC 700095AC 27A40078 */  addiu $a0, $sp, 0x78
.L700095B0:
/* 00A1B0 700095B0 8E0C0004 */  lw    $t4, 4($s0)
/* 00A1B4 700095B4 26100004 */  addiu $s0, $s0, 4
/* 00A1B8 700095B8 0204082B */  sltu  $at, $s0, $a0
/* 00A1BC 700095BC 01831021 */  addu  $v0, $t4, $v1
/* 00A1C0 700095C0 00401825 */  move  $v1, $v0
/* 00A1C4 700095C4 1420FFFA */  bnez  $at, .L700095B0
/* 00A1C8 700095C8 AE020000 */   sw    $v0, ($s0)
/* 00A1CC 700095CC 8E6D0008 */  lw    $t5, 8($s3)
/* 00A1D0 700095D0 8E780000 */  lw    $t8, ($s3)
/* 00A1D4 700095D4 8FA20078 */  lw    $v0, 0x78($sp)
/* 00A1D8 700095D8 27B00060 */  addiu $s0, $sp, 0x60
/* 00A1DC 700095DC 01B81823 */  subu  $v1, $t5, $t8
/* 00A1E0 700095E0 000377C3 */  sra   $t6, $v1, 0x1f
/* 00A1E4 700095E4 000247C3 */  sra   $t0, $v0, 0x1f
/* 00A1E8 700095E8 AFA80030 */  sw    $t0, 0x30($sp)
/* 00A1EC 700095EC AFAE0038 */  sw    $t6, 0x38($sp)
/* 00A1F0 700095F0 AFA3003C */  sw    $v1, 0x3c($sp)
/* 00A1F4 700095F4 AFA20034 */  sw    $v0, 0x34($sp)
.L700095F8:
/* 00A1F8 700095F8 8E050000 */  lw    $a1, ($s0)
/* 00A1FC 700095FC 8FA60038 */  lw    $a2, 0x38($sp)
/* 00A200 70009600 8FA7003C */  lw    $a3, 0x3c($sp)
/* 00A204 70009604 0C003B6A */  jal   __ll_mul
/* 00A208 70009608 000527C3 */   sra   $a0, $a1, 0x1f
/* 00A20C 7000960C 00402025 */  move  $a0, $v0
/* 00A210 70009610 00602825 */  move  $a1, $v1
/* 00A214 70009614 8FA60030 */  lw    $a2, 0x30($sp)
/* 00A218 70009618 0C003B53 */  jal   __ll_div
/* 00A21C 7000961C 8FA70034 */   lw    $a3, 0x34($sp)
/* 00A220 70009620 26100004 */  addiu $s0, $s0, 4
/* 00A224 70009624 0211082B */  sltu  $at, $s0, $s1
/* 00A228 70009628 1420FFF3 */  bnez  $at, .L700095F8
/* 00A22C 7000962C AE03FFFC */   sw    $v1, -4($s0)
/* 00A230 70009630 27B00060 */  addiu $s0, $sp, 0x60
/* 00A234 70009634 27A2007C */  addiu $v0, $sp, 0x7c
.L70009638:
/* 00A238 70009638 8E0B0000 */  lw    $t3, ($s0)
/* 00A23C 7000963C 26100004 */  addiu $s0, $s0, 4
/* 00A240 70009640 0202082B */  sltu  $at, $s0, $v0
/* 00A244 70009644 356C000F */  ori   $t4, $t3, 0xf
/* 00A248 70009648 398D000F */  xori  $t5, $t4, 0xf
/* 00A24C 7000964C 1420FFFA */  bnez  $at, .L70009638
/* 00A250 70009650 AE0DFFFC */   sw    $t5, -4($s0)
/* 00A254 70009654 8E660000 */  lw    $a2, ($s3)
/* 00A258 70009658 8FB80060 */  lw    $t8, 0x60($sp)
/* 00A25C 7000965C 8FAF0064 */  lw    $t7, 0x64($sp)
/* 00A260 70009660 3C018006 */  lui   $at, %hi(D_80063BC4) # $at, 0x8006
/* 00A264 70009664 03067021 */  addu  $t6, $t8, $a2
/* 00A268 70009668 AC2E3BC0 */  sw    $t6, %lo(D_80063BC0)($at)
/* 00A26C 7000966C AC203BC4 */  sw    $zero, %lo(D_80063BC4)($at)
/* 00A270 70009670 3C018006 */  lui   $at, %hi(D_80063BC8) # $at, 0x8006
/* 00A274 70009674 01E61021 */  addu  $v0, $t7, $a2
/* 00A278 70009678 AC223BC8 */  sw    $v0, %lo(D_80063BC8)($at)
/* 00A27C 7000967C 8FA80068 */  lw    $t0, 0x68($sp)
/* 00A280 70009680 3C018006 */  lui   $at, %hi(D_80063BD4) # $at, 0x8006
/* 00A284 70009684 AC223BD0 */  sw    $v0, %lo(D_80063BD0)($at)
/* 00A288 70009688 AC203BD4 */  sw    $zero, %lo(D_80063BD4)($at)
/* 00A28C 7000968C 3C018006 */  lui   $at, %hi(D_80063BD8) # $at, 0x8006
/* 00A290 70009690 01064821 */  addu  $t1, $t0, $a2
/* 00A294 70009694 AC293BD8 */  sw    $t1, %lo(D_80063BD8)($at)
/* 00A298 70009698 24070002 */  li    $a3, 2
/* 00A29C 7000969C 0007C900 */  sll   $t9, $a3, 4
/* 00A2A0 700096A0 02791021 */  addu  $v0, $s3, $t9
/* 00A2A4 700096A4 00075080 */  sll   $t2, $a3, 2
/* 00A2A8 700096A8 024A8021 */  addu  $s0, $s2, $t2
/* 00A2AC 700096AC 8E180008 */  lw    $t8, 8($s0)
/* 00A2B0 700096B0 8E0E000C */  lw    $t6, 0xc($s0)
/* 00A2B4 700096B4 8E0D0004 */  lw    $t5, 4($s0)
/* 00A2B8 700096B8 8E0F0010 */  lw    $t7, 0x10($s0)
/* 00A2BC 700096BC 8E0B0000 */  lw    $t3, ($s0)
/* 00A2C0 700096C0 03062021 */  addu  $a0, $t8, $a2
/* 00A2C4 700096C4 01C62821 */  addu  $a1, $t6, $a2
/* 00A2C8 700096C8 01A61821 */  addu  $v1, $t5, $a2
/* 00A2CC 700096CC 01E64021 */  addu  $t0, $t7, $a2
/* 00A2D0 700096D0 01666021 */  addu  $t4, $t3, $a2
/* 00A2D4 700096D4 AC480048 */  sw    $t0, 0x48($v0)
/* 00A2D8 700096D8 AC430020 */  sw    $v1, 0x20($v0)
/* 00A2DC 700096DC AC450038 */  sw    $a1, 0x38($v0)
/* 00A2E0 700096E0 AC450040 */  sw    $a1, 0x40($v0)
/* 00A2E4 700096E4 AC440028 */  sw    $a0, 0x28($v0)
/* 00A2E8 700096E8 AC440030 */  sw    $a0, 0x30($v0)
/* 00A2EC 700096EC AC400024 */  sw    $zero, 0x24($v0)
/* 00A2F0 700096F0 AC400034 */  sw    $zero, 0x34($v0)
/* 00A2F4 700096F4 AC400044 */  sw    $zero, 0x44($v0)
/* 00A2F8 700096F8 AC4C0010 */  sw    $t4, 0x10($v0)
/* 00A2FC 700096FC AC400014 */  sw    $zero, 0x14($v0)
/* 00A300 70009700 AC430018 */  sw    $v1, 0x18($v0)
/* 00A304 70009704 8FBF0024 */  lw    $ra, 0x24($sp)
/* 00A308 70009708 8FB30020 */  lw    $s3, 0x20($sp)
/* 00A30C 7000970C 8FB2001C */  lw    $s2, 0x1c($sp)
/* 00A310 70009710 8FB10018 */  lw    $s1, 0x18($sp)
/* 00A314 70009714 8FB00014 */  lw    $s0, 0x14($sp)
/* 00A318 70009718 03E00008 */  jr    $ra
/* 00A31C 7000971C 27BD0080 */   addiu $sp, $sp, 0x80
)
#endif



/**
 * A320	70009720
 *     V0=p->A0 bytes of memory allocated in bank A1; fries: AT,V0,V1,A0,A1,A2,A3,T0,T2,T5,T6,T7,T8,T9
 *     accepts: A0=size, A1=bank
 */
#ifdef NONMATCHING
void allocate_bytes_in_bank(void) {

}
#else
GLOBAL_ASM(
.text
glabel allocate_bytes_in_bank
/* 00A320 70009720 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 00A324 70009724 AFA5001C */  sw    $a1, 0x1c($sp)
/* 00A328 70009728 30A700FF */  andi  $a3, $a1, 0xff
/* 00A32C 7000972C 3C058006 */  lui   $a1, %hi(memory_bank_ptrs) # $a1, 0x8006
/* 00A330 70009730 3C0A8002 */  lui   $t2, %hi(tied_to_mem_management) # $t2, 0x8002
/* 00A334 70009734 254A4404 */  addiu $t2, %lo(tied_to_mem_management) # addiu $t2, $t2, 0x4404
/* 00A338 70009738 24A53BB0 */  addiu $a1, %lo(memory_bank_ptrs) # addiu $a1, $a1, 0x3bb0
/* 00A33C 7000973C AFBF0014 */  sw    $ra, 0x14($sp)
/* 00A340 70009740 00803025 */  move  $a2, $a0
/* 00A344 70009744 0007C100 */  sll   $t8, $a3, 4
.L70009748:
/* 00A348 70009748 00B81821 */  addu  $v1, $a1, $t8
/* 00A34C 7000974C 8C620004 */  lw    $v0, 4($v1)
/* 00A350 70009750 14400006 */  bnez  $v0, .L7000976C
/* 00A354 70009754 00404025 */   move  $t0, $v0
/* 00A358 70009758 24190001 */  li    $t9, 1
/* 00A35C 7000975C 3C018002 */  lui   $at, %hi(tied_to_mem_management) # $at, 0x8002
/* 00A360 70009760 AC394404 */  sw    $t9, %lo(tied_to_mem_management)($at)
.L70009764:
/* 00A364 70009764 1000FFFF */  b     .L70009764
/* 00A368 70009768 00000000 */   nop   
.L7000976C:
/* 00A36C 7000976C 8C640008 */  lw    $a0, 8($v1)
/* 00A370 70009770 00466821 */  addu  $t5, $v0, $a2
/* 00A374 70009774 0082082B */  sltu  $at, $a0, $v0
/* 00A378 70009778 50200006 */  beql  $at, $zero, .L70009794
/* 00A37C 7000977C 008D082B */   sltu  $at, $a0, $t5
/* 00A380 70009780 0C00263C */  jal   nulled_list_all8_mem_alloc_banks_sizes
/* 00A384 70009784 24070006 */   li    $a3, 6
.L70009788:
/* 00A388 70009788 1000FFFF */  b     .L70009788
/* 00A38C 7000978C 00000000 */   nop   
/* 00A390 70009790 008D082B */  sltu  $at, $a0, $t5
.L70009794:
/* 00A394 70009794 50200014 */  beql  $at, $zero, .L700097E8
/* 00A398 70009798 00466821 */   addu  $t5, $v0, $a2
/* 00A39C 7000979C 8CAF0064 */  lw    $t7, 0x64($a1)
/* 00A3A0 700097A0 8CAE0068 */  lw    $t6, 0x68($a1)
/* 00A3A4 700097A4 24070006 */  li    $a3, 6
/* 00A3A8 700097A8 01E6C021 */  addu  $t8, $t7, $a2
/* 00A3AC 700097AC 01D8082B */  sltu  $at, $t6, $t8
/* 00A3B0 700097B0 14200008 */  bnez  $at, .L700097D4
/* 00A3B4 700097B4 00000000 */   nop   
/* 00A3B8 700097B8 8D420000 */  lw    $v0, ($t2)
/* 00A3BC 700097BC 24190001 */  li    $t9, 1
/* 00A3C0 700097C0 AD590000 */  sw    $t9, ($t2)
/* 00A3C4 700097C4 5440FFE0 */  bnezl $v0, .L70009748
/* 00A3C8 700097C8 0007C100 */   sll   $t8, $a3, 4
/* 00A3CC 700097CC 1000FFDE */  b     .L70009748
/* 00A3D0 700097D0 0007C100 */   sll   $t8, $a3, 4
.L700097D4:
/* 00A3D4 700097D4 0C00263C */  jal   nulled_list_all8_mem_alloc_banks_sizes
/* 00A3D8 700097D8 00000000 */   nop   
.L700097DC:
/* 00A3DC 700097DC 1000FFFF */  b     .L700097DC
/* 00A3E0 700097E0 00000000 */   nop   
/* 00A3E4 700097E4 00466821 */  addu  $t5, $v0, $a2
.L700097E8:
/* 00A3E8 700097E8 AC6D0004 */  sw    $t5, 4($v1)
/* 00A3EC 700097EC AC68000C */  sw    $t0, 0xc($v1)
/* 00A3F0 700097F0 8FBF0014 */  lw    $ra, 0x14($sp)
/* 00A3F4 700097F4 27BD0018 */  addiu $sp, $sp, 0x18
/* 00A3F8 700097F8 01001025 */  move  $v0, $t0
/* 00A3FC 700097FC 03E00008 */  jr    $ra
/* 00A400 70009800 00000000 */   nop   
)
#endif



/**
 * A404	70009804
 *     ???; updates bank A2 size registry in light of entry at A0 of size A1
 *     accepts: A0=p->allocated data, A1=size of data, A2=bank#
 */
#ifdef NONMATCHING
void memp_related_1(void) {

}
#else
GLOBAL_ASM(
.text
glabel memp_related_1
/* 00A404 70009804 3C0F8002 */  lui   $t7, %hi(tied_to_mem_management) # $t7, 0x8002
/* 00A408 70009808 8DEF4404 */  lw    $t7, %lo(tied_to_mem_management)($t7)
/* 00A40C 7000980C 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 00A410 70009810 AFA60020 */  sw    $a2, 0x20($sp)
/* 00A414 70009814 30CE00FF */  andi  $t6, $a2, 0xff
/* 00A418 70009818 01C03025 */  move  $a2, $t6
/* 00A41C 7000981C AFBF0014 */  sw    $ra, 0x14($sp)
/* 00A420 70009820 AFA5001C */  sw    $a1, 0x1c($sp)
/* 00A424 70009824 11E00006 */  beqz  $t7, .L70009840
/* 00A428 70009828 00803825 */   move  $a3, $a0
/* 00A42C 7000982C 3C188006 */  lui   $t8, %hi(dword_CODE_bss_80063C1C) # $t8, 0x8006
/* 00A430 70009830 8F183C1C */  lw    $t8, %lo(dword_CODE_bss_80063C1C)($t8)
/* 00A434 70009834 14980002 */  bne   $a0, $t8, .L70009840
/* 00A438 70009838 00000000 */   nop   
/* 00A43C 7000983C 24060006 */  li    $a2, 6
.L70009840:
/* 00A440 70009840 3C0A8006 */  lui   $t2, %hi(memory_bank_ptrs) # $t2, 0x8006
/* 00A444 70009844 254A3BB0 */  addiu $t2, %lo(memory_bank_ptrs) # addiu $t2, $t2, 0x3bb0
/* 00A448 70009848 0006C900 */  sll   $t9, $a2, 4
/* 00A44C 7000984C 032A2821 */  addu  $a1, $t9, $t2
/* 00A450 70009850 8CA40004 */  lw    $a0, 4($a1)
/* 00A454 70009854 54800004 */  bnezl $a0, .L70009868
/* 00A458 70009858 8CA6000C */   lw    $a2, 0xc($a1)
.L7000985C:
/* 00A45C 7000985C 1000FFFF */  b     .L7000985C
/* 00A460 70009860 00000000 */   nop   
/* 00A464 70009864 8CA6000C */  lw    $a2, 0xc($a1)
.L70009868:
/* 00A468 70009868 8FAB001C */  lw    $t3, 0x1c($sp)
/* 00A46C 7000986C 50E60004 */  beql  $a3, $a2, .L70009880
/* 00A470 70009870 00861023 */   subu  $v0, $a0, $a2
/* 00A474 70009874 1000001A */  b     .L700098E0
/* 00A478 70009878 24020002 */   li    $v0, 2
/* 00A47C 7000987C 00861023 */  subu  $v0, $a0, $a2
.L70009880:
/* 00A480 70009880 01621823 */  subu  $v1, $t3, $v0
/* 00A484 70009884 1C600004 */  bgtz  $v1, .L70009898
/* 00A488 70009888 00836021 */   addu  $t4, $a0, $v1
/* 00A48C 7000988C ACAC0004 */  sw    $t4, 4($a1)
/* 00A490 70009890 10000013 */  b     .L700098E0
/* 00A494 70009894 24020001 */   li    $v0, 1
.L70009898:
/* 00A498 70009898 8CA20008 */  lw    $v0, 8($a1)
/* 00A49C 7000989C 00836821 */  addu  $t5, $a0, $v1
/* 00A4A0 700098A0 0044082B */  sltu  $at, $v0, $a0
/* 00A4A4 700098A4 50200006 */  beql  $at, $zero, .L700098C0
/* 00A4A8 700098A8 004D082B */   sltu  $at, $v0, $t5
/* 00A4AC 700098AC 0C00263C */  jal   nulled_list_all8_mem_alloc_banks_sizes
/* 00A4B0 700098B0 24060006 */   li    $a2, 6
.L700098B4:
/* 00A4B4 700098B4 1000FFFF */  b     .L700098B4
/* 00A4B8 700098B8 00000000 */   nop   
/* 00A4BC 700098BC 004D082B */  sltu  $at, $v0, $t5
.L700098C0:
/* 00A4C0 700098C0 10200005 */  beqz  $at, .L700098D8
/* 00A4C4 700098C4 00837021 */   addu  $t6, $a0, $v1
/* 00A4C8 700098C8 0C00263C */  jal   nulled_list_all8_mem_alloc_banks_sizes
/* 00A4CC 700098CC 24060006 */   li    $a2, 6
.L700098D0:
/* 00A4D0 700098D0 1000FFFF */  b     .L700098D0
/* 00A4D4 700098D4 00000000 */   nop   
.L700098D8:
/* 00A4D8 700098D8 ACAE0004 */  sw    $t6, 4($a1)
/* 00A4DC 700098DC 24020001 */  li    $v0, 1
.L700098E0:
/* 00A4E0 700098E0 8FBF0014 */  lw    $ra, 0x14($sp)
/* 00A4E4 700098E4 27BD0018 */  addiu $sp, $sp, 0x18
/* 00A4E8 700098E8 03E00008 */  jr    $ra
/* 00A4EC 700098EC 00000000 */   nop   
)
#endif



/**
 * A4F0	700098F0
 *     V0=8 -- loop eight times, needlessly; fries AT,T6
 *     used by "show mem use", step 1; probably originally listed all eight memory allocations
 */
#ifdef NONMATCHING
s32 nulled_list_all8_mem_alloc_banks_sizes(void) {
    // Node 0
    // Node 1
    if (((1 + 1) & 0xff) < 7)
    {
        goto loop_1;
    }
    // (possible return value: ((1 + 1) & 0xff))
}

#else
GLOBAL_ASM(
.text
glabel nulled_list_all8_mem_alloc_banks_sizes
/* 00A4F0 700098F0 24020001 */  li    $v0, 1
.L700098F4:
/* 00A4F4 700098F4 24420001 */  addiu $v0, $v0, 1
/* 00A4F8 700098F8 304E00FF */  andi  $t6, $v0, 0xff
/* 00A4FC 700098FC 29C10007 */  slti  $at, $t6, 7
/* 00A500 70009900 1420FFFC */  bnez  $at, .L700098F4
/* 00A504 70009904 01C01025 */   move  $v0, $t6
/* 00A508 70009908 03E00008 */  jr    $ra
/* 00A50C 7000990C 00000000 */   nop   
)
#endif



/**
 * A510	70009910
 *     V0= total allocated size of bank A0
 *     accepts: A0=bank#
 */
#ifdef NONMATCHING
s32 memp_related_3(s32 arg0) {
    // Node 0
    if (tied_to_mem_management != 0)
    {
        // Node 1
    }
    // Node 2
    if ((arg0 & 0xff) == 4)
    {
        // Node 3
        if (memory_bank_ptrs.unk40 == memory_bank_ptrs.unk48)
        {
            // Node 4
            return;
            // (possible return value: ((&memory_bank_ptrs + ((arg0 & 0xff) * 0x10))->unk8 - (&memory_bank_ptrs + ((arg0 & 0xff) * 0x10))->unk4))
        }
    }
    // (possible return value: ((&memory_bank_ptrs + ((arg0 & 0xff) * 0x10))->unk8 - (&memory_bank_ptrs + ((arg0 & 0xff) * 0x10))->unk4))
}
#else
GLOBAL_ASM(
.text
glabel memp_related_3
/* 00A510 70009910 3C0F8002 */  lui   $t7, %hi(tied_to_mem_management) # $t7, 0x8002
/* 00A514 70009914 8DEF4404 */  lw    $t7, %lo(tied_to_mem_management)($t7)
/* 00A518 70009918 AFA40000 */  sw    $a0, ($sp)
/* 00A51C 7000991C 308E00FF */  andi  $t6, $a0, 0xff
/* 00A520 70009920 11E00002 */  beqz  $t7, .L7000992C
/* 00A524 70009924 01C02025 */   move  $a0, $t6
/* 00A528 70009928 24040006 */  li    $a0, 6
.L7000992C:
/* 00A52C 7000992C 24010004 */  li    $at, 4
/* 00A530 70009930 14810007 */  bne   $a0, $at, .L70009950
/* 00A534 70009934 3C058006 */   lui   $a1, %hi(memory_bank_ptrs) # $a1, 0x8006
/* 00A538 70009938 24A53BB0 */  addiu $a1, %lo(memory_bank_ptrs) # addiu $a1, $a1, 0x3bb0
/* 00A53C 7000993C 8CB80040 */  lw    $t8, 0x40($a1)
/* 00A540 70009940 8CB90048 */  lw    $t9, 0x48($a1)
/* 00A544 70009944 17190002 */  bne   $t8, $t9, .L70009950
/* 00A548 70009948 00000000 */   nop   
/* 00A54C 7000994C 24040006 */  li    $a0, 6
.L70009950:
/* 00A550 70009950 3C058006 */  lui   $a1, %hi(memory_bank_ptrs) # $a1, 0x8006
/* 00A554 70009954 24A53BB0 */  addiu $a1, %lo(memory_bank_ptrs) # addiu $a1, $a1, 0x3bb0
/* 00A558 70009958 00044100 */  sll   $t0, $a0, 4
/* 00A55C 7000995C 00A81821 */  addu  $v1, $a1, $t0
/* 00A560 70009960 8C690008 */  lw    $t1, 8($v1)
/* 00A564 70009964 8C6A0004 */  lw    $t2, 4($v1)
/* 00A568 70009968 03E00008 */  jr    $ra
/* 00A56C 7000996C 012A1023 */   subu  $v0, $t1, $t2
)
#endif





/**
 * A570	70009970
 *     allocate A0 coded #bytes in bank
 *     accepts: A0=size/bank# entry (ssssssss ssssssss sssssssss sssssbbb)
 */
#ifdef NONMATCHING
void memp_related_4(u32 arg0) {
    // Node 0
    allocate_bytes_in_bank((arg0 >> 3), (arg0 & 7));
    return;
    // (possible return value: allocate_bytes_in_bank((arg0 >> 3), (arg0 & 7)))
}
#else
GLOBAL_ASM(
.text
glabel memp_related_4
/* 00A570 70009970 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 00A574 70009974 00802825 */  move  $a1, $a0
/* 00A578 70009978 AFBF0014 */  sw    $ra, 0x14($sp)
/* 00A57C 7000997C 30AE0007 */  andi  $t6, $a1, 7
/* 00A580 70009980 01C02825 */  move  $a1, $t6
/* 00A584 70009984 0C0025C8 */  jal   allocate_bytes_in_bank
/* 00A588 70009988 000420C2 */   srl   $a0, $a0, 3
/* 00A58C 7000998C 8FBF0014 */  lw    $ra, 0x14($sp)
/* 00A590 70009990 27BD0018 */  addiu $sp, $sp, 0x18
/* 00A594 70009994 03E00008 */  jr    $ra
/* 00A598 70009998 00000000 */   nop   
)
#endif





/**
 * A59C	7000999C
 *     reset memory bank A0 [0-6]
 *     copies base address for memory bank A0 to +4, fry +C
 */
#ifdef NONMATCHING
void *reset_mem_bank_a0(s32 arg0) {
    void *temp_v0;

    // Node 0
    temp_v0 = (((arg0 & 0xff) * 0x10) + &memory_bank_ptrs);
    temp_v0->unkC = 0;
    temp_v0->unk4 = (?32) *temp_v0;
    return;
    // (possible return value: temp_v0)
}
#else
GLOBAL_ASM(
.text
glabel reset_mem_bank_a0
/* 00A59C 7000999C 308E00FF */  andi  $t6, $a0, 0xff
/* 00A5A0 700099A0 3C188006 */  lui   $t8, %hi(memory_bank_ptrs) # $t8, 0x8006
/* 00A5A4 700099A4 27183BB0 */  addiu $t8, %lo(memory_bank_ptrs) # addiu $t8, $t8, 0x3bb0
/* 00A5A8 700099A8 000E7900 */  sll   $t7, $t6, 4
/* 00A5AC 700099AC 01F81021 */  addu  $v0, $t7, $t8
/* 00A5B0 700099B0 8C590000 */  lw    $t9, ($v0)
/* 00A5B4 700099B4 AFA40000 */  sw    $a0, ($sp)
/* 00A5B8 700099B8 AC40000C */  sw    $zero, 0xc($v0)
/* 00A5BC 700099BC 03E00008 */  jr    $ra
/* 00A5C0 700099C0 AC590004 */   sw    $t9, 4($v0)
)
#endif





/**
 * A5C4	700099C4
 *     accepts: A0=bank#
 */
#ifdef NONMATCHING
void *memp_related_6(s32 arg0, s32 arg_unaligned3) {
    void *temp_v0;

    // Node 0
    nulled_list_all8_mem_alloc_banks_sizes();
    temp_v0 = ((arg_unaligned3 * 0x10) + &memory_bank_ptrs);
    if (temp_v0->unk4 != 0)
    {
        // Node 1
        temp_v0->unk4 = 0;
    }
    // Node 2
    return temp_v0;
}
#else
GLOBAL_ASM(
.text
glabel memp_related_6
/* 00A5C4 700099C4 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 00A5C8 700099C8 AFBF0014 */  sw    $ra, 0x14($sp)
/* 00A5CC 700099CC 0C00263C */  jal   nulled_list_all8_mem_alloc_banks_sizes
/* 00A5D0 700099D0 AFA40018 */   sw    $a0, 0x18($sp)
/* 00A5D4 700099D4 93AE001B */  lbu   $t6, 0x1b($sp)
/* 00A5D8 700099D8 3C188006 */  lui   $t8, %hi(memory_bank_ptrs) # $t8, 0x8006
/* 00A5DC 700099DC 27183BB0 */  addiu $t8, %lo(memory_bank_ptrs) # addiu $t8, $t8, 0x3bb0
/* 00A5E0 700099E0 000E7900 */  sll   $t7, $t6, 4
/* 00A5E4 700099E4 01F81021 */  addu  $v0, $t7, $t8
/* 00A5E8 700099E8 8C590004 */  lw    $t9, 4($v0)
/* 00A5EC 700099EC 53200003 */  beql  $t9, $zero, .L700099FC
/* 00A5F0 700099F0 8FBF0014 */   lw    $ra, 0x14($sp)
/* 00A5F4 700099F4 AC400004 */  sw    $zero, 4($v0)
/* 00A5F8 700099F8 8FBF0014 */  lw    $ra, 0x14($sp)
.L700099FC:
/* 00A5FC 700099FC 27BD0018 */  addiu $sp, $sp, 0x18
/* 00A600 70009A00 03E00008 */  jr    $ra
/* 00A604 70009A04 00000000 */   nop   
)
#endif




