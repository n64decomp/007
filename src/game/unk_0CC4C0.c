#include "ultra64.h"
#include "game/lvl.h"
#include "game/image.h"
#include "game/unk_0CC4C0.h"

// bss
//8008D140
s32 dword_CODE_bss_8008D140;
//8008D144
s32 dword_CODE_bss_8008D144;
//8008D148
char dword_CODE_bss_8008D148[0x160];
//8008D2A8
char dword_CODE_bss_8008D2A8[0xA0];
//8008D348
s32 dword_CODE_bss_8008D348;


// data
//D:8004E760
u16 D_8004E760[] = {0xD0, 0xD1};
//D:8004E764
u8 D_8004E764[] = {0x7, 0x0, 0x0, 0x0};
//D:8004E768
struct image_sound isnd_default = {&D_8004E760, &D_8004E764, 0x0, 0x1};

//D:8004E774
u16 D_8004E774[] = {0xD0, 0xD1};
//D:8004E778
u8 D_8004E778[] = {0x1, 0x0, 0x0, 0x0};
//D:8004E77C
struct image_sound isnd_stone = {&D_8004E774, &D_8004E778, 0x2, 0x1};

//D:8004E788
u16 D_8004E788[] = {0x4B, 0xD9};
//D:8004E78C
u8 D_8004E78C[] = {0x1, 0x0, 0x0, 0x0};
//D:8004E790
struct image_sound isnd_wood = {&D_8004E788, &D_8004E78C, 0x2, 0x1};

//D:8004E79C
u16 D_8004E79C[] = {0x48, 0xF0, 0xEF, 0x00};
//D:8004E7A4
u8 D_8004E7A4[] = {0x7, 0x0, 0x0, 0x0};
//D:8004E7A8
struct image_sound isnd_metal = {&D_8004E79C, &D_8004E7A4, 0x3, 0x1};

//D:8004E7B4
u16 D_8004E7B4[] = {0x46, 0x00};
//D:8004E7B8
u8 D_8004E7B8[] = {0x4, 0x5, 0x6, 0x0};
//D:8004E7BC
struct image_sound isnd_glass = {&D_8004E7B4, &D_8004E7B8, 0x1, 0x3};

//D:8004E7C8
u16 D_8004E7C8[] = {0x4C, 0x00};
//D:8004E7CC
u8 D_8004E7CC[] = {0, 0, 0, 0};
//D:8004E7D0
struct image_sound isnd_water = {&D_8004E7C8, &D_8004E7CC, 0x1, 0x0};

//D:8004E7DC
u16 D_8004E7DC[] = {0x4A, 0x00};
//D:8004E7E0
u8 D_8004E7E0[] = {0x1, 0x0, 0x0, 0x0};
//D:8004E7E4
struct image_sound isnd_snow = {&D_8004E7DC, &D_8004E7E0, 0x1, 0x1};

//D:8004E7F0
u16 D_8004E7F0[] = {0xDC, 0xB9};
//D:8004E7F4
u8 D_8004E7F4[] = {0x2, 0x0, 0x0, 0x0};
//D:8004E7F8
struct image_sound isnd_dirt = {&D_8004E7F0, &D_8004E7F4, 0x2, 0x1};

//D:8004E804
u16 D_8004E804[] = {0xE7, 0xE6, 0xE0, 0x00};
//D:8004E80C
u8 D_8004E80C[] = {0x2, 0x0, 0x0, 0x0};
//D:8004E810
struct image_sound isnd_mud = {&D_8004E804, &D_8004E80C, 0x3, 0x1};

//D:8004E81C
u16 D_8004E81C[] = {0xD4, 0x00};
//D:8004E820
u8 D_8004E820[] = {0x1, 0x0, 0x0, 0x0};
//D:8004E824
struct image_sound isnd_tile = {&D_8004E81C, &D_8004E820, 0x1, 0x1};

//D:8004E830
u16 D_8004E830[] = {0x78, 0xDD};
//D:8004E834
u8 D_8004E834[] = {0x1, 0x7, 0x0, 0x0};
//D:8004E838
struct image_sound isnd_metalobj = {&D_8004E830, &D_8004E834, 0x2, 0x2};

//D:8004E844
u16 D_8004E844[] = {0x45, 0x00};
//D:8004E848
u8 D_8004E848[] = {0x2, 0x0, 0x0, 0x0};
//D:8004E84C
struct image_sound isnd_chr = {&D_8004E844, &D_8004E848, 0x1, 0x1};

//D:8004E858
u16 D_8004E858[] = {0x46, 0x00};
//D:8004E85C
u8 D_8004E85C[] = {0x11, 0x12, 0x13, 0x0};
//D:8004E860
struct image_sound isnd_glass_xlu = {&D_8004E858, &D_8004E85C, 0x1, 0x3};

//D:8004E86C
u32 *D_8004E86C[] = { 
    &isnd_default,
    &isnd_stone,
    &isnd_wood,
    &isnd_metal,
    &isnd_glass,
    &isnd_water,
    &isnd_snow,
    &isnd_dirt,
    &isnd_mud,
    &isnd_tile,
    &isnd_metalobj,
    &isnd_chr,
    &isnd_glass_xlu,
    "HIT_DEFAULT",
    "HIT_STONE",
    "HIT_WOOD",
    "HIT_METAL",
    "HIT_GLASS",
    "HIT_WATER",
    "HIT_SNOW",
    "HIT_DIRT",
    "HIT_MUD",
    "HIT_TILE",
    "HIT_METALOBJ",
    "HIT_CHR",
    "HIT_GLASS_XLU"
};



void nullsub_47(void) {
    return;
}





#ifdef NONMATCHING
void *sub_GAME_7F0CC4C8(void) {
    void *temp_a0;
    void *temp_v1;
    void *phi_v1;
    void *phi_a0;

    // Node 0
    phi_v1 = &dword_CODE_bss_8008D148;
    phi_a0 = &dword_CODE_bss_8008D2A8;
    // Node 1
    temp_a0 = (phi_a0 + 0x50);
    phi_v1->unk2C = 0;
    temp_a0->unk-3C = 0;
    phi_v1->unk58 = 0;
    temp_a0->unk-28 = 0;
    phi_v1->unk84 = 0;
    temp_a0->unk-14 = 0;
    temp_v1 = (phi_v1 + 0xb0);
    temp_v1->unk-B0 = 0;
    temp_a0->unk-50 = 0;
    phi_v1 = temp_v1;
    phi_a0 = temp_a0;
    if (temp_a0 != &dword_CODE_bss_8008D348)
    {
        goto loop_1;
    }
    // Node 2
    (void *)0x80090000->unk-2EC0 = -1;
    return &dword_CODE_bss_8008D348;
}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0CC4C8
/* 100FF8 7F0CC4C8 3C038009 */  lui   $v1, %hi(dword_CODE_bss_8008D148) # $v1, 0x8009
/* 100FFC 7F0CC4CC 3C048009 */  lui   $a0, %hi(dword_CODE_bss_8008D2A8) # $a0, 0x8009
/* 101000 7F0CC4D0 3C028009 */  lui   $v0, %hi(dword_CODE_bss_8008D348) # $v0, 0x8009
/* 101004 7F0CC4D4 2442D348 */  addiu $v0, %lo(dword_CODE_bss_8008D348) # addiu $v0, $v0, -0x2cb8
/* 101008 7F0CC4D8 2484D2A8 */  addiu $a0, %lo(dword_CODE_bss_8008D2A8) # addiu $a0, $a0, -0x2d58
/* 10100C 7F0CC4DC 2463D148 */  addiu $v1, %lo(dword_CODE_bss_8008D148) # addiu $v1, $v1, -0x2eb8
.L7F0CC4E0:
/* 101010 7F0CC4E0 24840050 */  addiu $a0, $a0, 0x50
/* 101014 7F0CC4E4 AC60002C */  sw    $zero, 0x2c($v1)
/* 101018 7F0CC4E8 AC80FFC4 */  sw    $zero, -0x3c($a0)
/* 10101C 7F0CC4EC AC600058 */  sw    $zero, 0x58($v1)
/* 101020 7F0CC4F0 AC80FFD8 */  sw    $zero, -0x28($a0)
/* 101024 7F0CC4F4 AC600084 */  sw    $zero, 0x84($v1)
/* 101028 7F0CC4F8 AC80FFEC */  sw    $zero, -0x14($a0)
/* 10102C 7F0CC4FC 246300B0 */  addiu $v1, $v1, 0xb0
/* 101030 7F0CC500 AC60FF50 */  sw    $zero, -0xb0($v1)
/* 101034 7F0CC504 1482FFF6 */  bne   $a0, $v0, .L7F0CC4E0
/* 101038 7F0CC508 AC80FFB0 */   sw    $zero, -0x50($a0)
/* 10103C 7F0CC50C 240EFFFF */  li    $t6, -1
/* 101040 7F0CC510 3C018009 */  lui   $at, %hi(dword_CODE_bss_8008D140)
/* 101044 7F0CC514 03E00008 */  jr    $ra
/* 101048 7F0CC518 AC2ED140 */   sw    $t6, %lo(dword_CODE_bss_8008D140)($at)
)
#endif





#ifdef NONMATCHING
s32 sub_GAME_7F0CC51C(void *arg0, s32 arg1, void *arg2) {
    s32 temp_a1;
    void *temp_v1;
    void *phi_v0;
    void *phi_v1;
    s32 phi_a1;
    void *phi_v1_2;

    // Node 0
    phi_v0 = arg0;
    phi_v1 = arg2;
    phi_a1 = arg1;
    phi_v1_2 = arg2;
    if (arg1 > 0)
    {
        loop_1:
        // Node 1
        temp_a1 = (phi_a1 + -1);
        temp_v1 = (phi_v1 + 1);
        temp_v1->unk-1 = (s8) *phi_v0;
        phi_v0 = (phi_v0 + 1);
        phi_v1 = temp_v1;
        phi_a1 = temp_a1;
        phi_v1_2 = temp_v1;
        if (temp_a1 > 0)
        {
            goto loop_1;
        }
    }
    // Node 2
    return (phi_v1_2 - arg2);
}

#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0CC51C
/* 10104C 7F0CC51C 00801025 */  move  $v0, $a0
/* 101050 7F0CC520 18A00007 */  blez  $a1, .L7F0CC540
/* 101054 7F0CC524 00C01825 */   move  $v1, $a2
.L7F0CC528:
/* 101058 7F0CC528 904E0000 */  lbu   $t6, ($v0)
/* 10105C 7F0CC52C 24A5FFFF */  addiu $a1, $a1, -1
/* 101060 7F0CC530 24630001 */  addiu $v1, $v1, 1
/* 101064 7F0CC534 24420001 */  addiu $v0, $v0, 1
/* 101068 7F0CC538 1CA0FFFB */  bgtz  $a1, .L7F0CC528
/* 10106C 7F0CC53C A06EFFFF */   sb    $t6, -1($v1)
.L7F0CC540:
/* 101070 7F0CC540 03E00008 */  jr    $ra
/* 101074 7F0CC544 00661023 */   subu  $v0, $v1, $a2
)
#endif





u32 sub_GAME_7F0CC548(s32 arg0) {
    if (arg0 == dword_CODE_bss_8008D140) {
        return 0;
    }
    dword_CODE_bss_8008D140 = arg0;
    return 1;
}






#ifdef NONMATCHING
void sub_GAME_7F0CC574(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9, s32 argA) {
    void *temp_v0;
    ? phi_v1;

    // Node 0
    temp_v0 = ((arg0 * 0x2c) + &dword_CODE_bss_8008D148);
    if (((((((((((*temp_v0 == 0) || (arg1 != temp_v0->unk4)) || (arg2 != temp_v0->unk8)) || (arg3 != temp_v0->unkC)) || (arg4 != temp_v0->unk10)) || (arg5 != temp_v0->unk14)) || (arg6 != temp_v0->unk18)) || (arg7 != temp_v0->unk1C)) || (arg8 != temp_v0->unk20)) || (arg9 != temp_v0->unk24)) || (argA != temp_v0->unk28))
    {
        // Node 11
        *temp_v0 = 1;
        temp_v0->unk4 = arg1;
        temp_v0->unk8 = arg2;
        temp_v0->unkC = arg3;
        temp_v0->unk10 = arg4;
        temp_v0->unk14 = arg5;
        temp_v0->unk18 = arg6;
        temp_v0->unk1C = arg7;
        temp_v0->unk20 = arg8;
        temp_v0->unk24 = arg9;
        temp_v0->unk28 = argA;
        phi_v1 = 1;
    }
    else
    {

    }
    // Node 12
    return phi_v1;
}

#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0CC574
/* 1010A4 7F0CC574 00047080 */  sll   $t6, $a0, 2
/* 1010A8 7F0CC578 01C47023 */  subu  $t6, $t6, $a0
/* 1010AC 7F0CC57C 000E7080 */  sll   $t6, $t6, 2
/* 1010B0 7F0CC580 01C47023 */  subu  $t6, $t6, $a0
/* 1010B4 7F0CC584 3C0F8009 */  lui   $t7, %hi(dword_CODE_bss_8008D148) # $t7, 0x8009
/* 1010B8 7F0CC588 25EFD148 */  addiu $t7, %lo(dword_CODE_bss_8008D148) # addiu $t7, $t7, -0x2eb8
/* 1010BC 7F0CC58C 000E7080 */  sll   $t6, $t6, 2
/* 1010C0 7F0CC590 01CF1021 */  addu  $v0, $t6, $t7
/* 1010C4 7F0CC594 8C580000 */  lw    $t8, ($v0)
/* 1010C8 7F0CC598 00001825 */  move  $v1, $zero
/* 1010CC 7F0CC59C 53000027 */  beql  $t8, $zero, .L7F0CC63C
/* 1010D0 7F0CC5A0 8FAF0010 */   lw    $t7, 0x10($sp)
/* 1010D4 7F0CC5A4 8C590004 */  lw    $t9, 4($v0)
/* 1010D8 7F0CC5A8 54B90024 */  bnel  $a1, $t9, .L7F0CC63C
/* 1010DC 7F0CC5AC 8FAF0010 */   lw    $t7, 0x10($sp)
/* 1010E0 7F0CC5B0 8C480008 */  lw    $t0, 8($v0)
/* 1010E4 7F0CC5B4 54C80021 */  bnel  $a2, $t0, .L7F0CC63C
/* 1010E8 7F0CC5B8 8FAF0010 */   lw    $t7, 0x10($sp)
/* 1010EC 7F0CC5BC 8C49000C */  lw    $t1, 0xc($v0)
/* 1010F0 7F0CC5C0 8FAA0010 */  lw    $t2, 0x10($sp)
/* 1010F4 7F0CC5C4 54E9001D */  bnel  $a3, $t1, .L7F0CC63C
/* 1010F8 7F0CC5C8 8FAF0010 */   lw    $t7, 0x10($sp)
/* 1010FC 7F0CC5CC 8C4B0010 */  lw    $t3, 0x10($v0)
/* 101100 7F0CC5D0 8FAC0014 */  lw    $t4, 0x14($sp)
/* 101104 7F0CC5D4 554B0019 */  bnel  $t2, $t3, .L7F0CC63C
/* 101108 7F0CC5D8 8FAF0010 */   lw    $t7, 0x10($sp)
/* 10110C 7F0CC5DC 8C4D0014 */  lw    $t5, 0x14($v0)
/* 101110 7F0CC5E0 8FAE0018 */  lw    $t6, 0x18($sp)
/* 101114 7F0CC5E4 558D0015 */  bnel  $t4, $t5, .L7F0CC63C
/* 101118 7F0CC5E8 8FAF0010 */   lw    $t7, 0x10($sp)
/* 10111C 7F0CC5EC 8C4F0018 */  lw    $t7, 0x18($v0)
/* 101120 7F0CC5F0 8FB8001C */  lw    $t8, 0x1c($sp)
/* 101124 7F0CC5F4 55CF0011 */  bnel  $t6, $t7, .L7F0CC63C
/* 101128 7F0CC5F8 8FAF0010 */   lw    $t7, 0x10($sp)
/* 10112C 7F0CC5FC 8C59001C */  lw    $t9, 0x1c($v0)
/* 101130 7F0CC600 8FA80020 */  lw    $t0, 0x20($sp)
/* 101134 7F0CC604 5719000D */  bnel  $t8, $t9, .L7F0CC63C
/* 101138 7F0CC608 8FAF0010 */   lw    $t7, 0x10($sp)
/* 10113C 7F0CC60C 8C490020 */  lw    $t1, 0x20($v0)
/* 101140 7F0CC610 8FAA0024 */  lw    $t2, 0x24($sp)
/* 101144 7F0CC614 55090009 */  bnel  $t0, $t1, .L7F0CC63C
/* 101148 7F0CC618 8FAF0010 */   lw    $t7, 0x10($sp)
/* 10114C 7F0CC61C 8C4B0024 */  lw    $t3, 0x24($v0)
/* 101150 7F0CC620 8FAC0028 */  lw    $t4, 0x28($sp)
/* 101154 7F0CC624 554B0005 */  bnel  $t2, $t3, .L7F0CC63C
/* 101158 7F0CC628 8FAF0010 */   lw    $t7, 0x10($sp)
/* 10115C 7F0CC62C 8C4D0028 */  lw    $t5, 0x28($v0)
/* 101160 7F0CC630 118D0015 */  beq   $t4, $t5, .L7F0CC688
/* 101164 7F0CC634 00000000 */   nop   
/* 101168 7F0CC638 8FAF0010 */  lw    $t7, 0x10($sp)
.L7F0CC63C:
/* 10116C 7F0CC63C 8FB80014 */  lw    $t8, 0x14($sp)
/* 101170 7F0CC640 8FB90018 */  lw    $t9, 0x18($sp)
/* 101174 7F0CC644 8FA8001C */  lw    $t0, 0x1c($sp)
/* 101178 7F0CC648 8FA90020 */  lw    $t1, 0x20($sp)
/* 10117C 7F0CC64C 8FAA0024 */  lw    $t2, 0x24($sp)
/* 101180 7F0CC650 8FAB0028 */  lw    $t3, 0x28($sp)
/* 101184 7F0CC654 240E0001 */  li    $t6, 1
/* 101188 7F0CC658 24030001 */  li    $v1, 1
/* 10118C 7F0CC65C AC4E0000 */  sw    $t6, ($v0)
/* 101190 7F0CC660 AC450004 */  sw    $a1, 4($v0)
/* 101194 7F0CC664 AC460008 */  sw    $a2, 8($v0)
/* 101198 7F0CC668 AC47000C */  sw    $a3, 0xc($v0)
/* 10119C 7F0CC66C AC4F0010 */  sw    $t7, 0x10($v0)
/* 1011A0 7F0CC670 AC580014 */  sw    $t8, 0x14($v0)
/* 1011A4 7F0CC674 AC590018 */  sw    $t9, 0x18($v0)
/* 1011A8 7F0CC678 AC48001C */  sw    $t0, 0x1c($v0)
/* 1011AC 7F0CC67C AC490020 */  sw    $t1, 0x20($v0)
/* 1011B0 7F0CC680 AC4A0024 */  sw    $t2, 0x24($v0)
/* 1011B4 7F0CC684 AC4B0028 */  sw    $t3, 0x28($v0)
.L7F0CC688:
/* 1011B8 7F0CC688 03E00008 */  jr    $ra
/* 1011BC 7F0CC68C 00601025 */   move  $v0, $v1
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0CC690(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    void *temp_v0;
    ? phi_v1;

    // Node 0
    temp_v0 = ((arg0 * 0x14) + &dword_CODE_bss_8008D2A8);
    if (((((*temp_v0 == 0) || (arg1 != temp_v0->unk4)) || (arg2 != temp_v0->unk8)) || (arg3 != temp_v0->unkC)) || (arg4 != temp_v0->unk10))
    {
        // Node 5
        *temp_v0 = 1;
        temp_v0->unk4 = arg1;
        temp_v0->unk8 = arg2;
        temp_v0->unkC = arg3;
        temp_v0->unk10 = arg4;
        phi_v1 = 1;
    }
    else
    {

    }
    // Node 6
    return phi_v1;
}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0CC690
/* 1011C0 7F0CC690 00047080 */  sll   $t6, $a0, 2
/* 1011C4 7F0CC694 01C47021 */  addu  $t6, $t6, $a0
/* 1011C8 7F0CC698 3C0F8009 */  lui   $t7, %hi(dword_CODE_bss_8008D2A8) # $t7, 0x8009
/* 1011CC 7F0CC69C 25EFD2A8 */  addiu $t7, %lo(dword_CODE_bss_8008D2A8) # addiu $t7, $t7, -0x2d58
/* 1011D0 7F0CC6A0 000E7080 */  sll   $t6, $t6, 2
/* 1011D4 7F0CC6A4 01CF1021 */  addu  $v0, $t6, $t7
/* 1011D8 7F0CC6A8 8C580000 */  lw    $t8, ($v0)
/* 1011DC 7F0CC6AC 00001825 */  move  $v1, $zero
/* 1011E0 7F0CC6B0 240C0001 */  li    $t4, 1
/* 1011E4 7F0CC6B4 5300000F */  beql  $t8, $zero, .L7F0CC6F4
/* 1011E8 7F0CC6B8 8FAD0010 */   lw    $t5, 0x10($sp)
/* 1011EC 7F0CC6BC 8C590004 */  lw    $t9, 4($v0)
/* 1011F0 7F0CC6C0 54B9000C */  bnel  $a1, $t9, .L7F0CC6F4
/* 1011F4 7F0CC6C4 8FAD0010 */   lw    $t5, 0x10($sp)
/* 1011F8 7F0CC6C8 8C480008 */  lw    $t0, 8($v0)
/* 1011FC 7F0CC6CC 54C80009 */  bnel  $a2, $t0, .L7F0CC6F4
/* 101200 7F0CC6D0 8FAD0010 */   lw    $t5, 0x10($sp)
/* 101204 7F0CC6D4 8C49000C */  lw    $t1, 0xc($v0)
/* 101208 7F0CC6D8 8FAA0010 */  lw    $t2, 0x10($sp)
/* 10120C 7F0CC6DC 54E90005 */  bnel  $a3, $t1, .L7F0CC6F4
/* 101210 7F0CC6E0 8FAD0010 */   lw    $t5, 0x10($sp)
/* 101214 7F0CC6E4 8C4B0010 */  lw    $t3, 0x10($v0)
/* 101218 7F0CC6E8 114B0008 */  beq   $t2, $t3, .L7F0CC70C
/* 10121C 7F0CC6EC 00000000 */   nop   
/* 101220 7F0CC6F0 8FAD0010 */  lw    $t5, 0x10($sp)
.L7F0CC6F4:
/* 101224 7F0CC6F4 24030001 */  li    $v1, 1
/* 101228 7F0CC6F8 AC4C0000 */  sw    $t4, ($v0)
/* 10122C 7F0CC6FC AC450004 */  sw    $a1, 4($v0)
/* 101230 7F0CC700 AC460008 */  sw    $a2, 8($v0)
/* 101234 7F0CC704 AC47000C */  sw    $a3, 0xc($v0)
/* 101238 7F0CC708 AC4D0010 */  sw    $t5, 0x10($v0)
.L7F0CC70C:
/* 10123C 7F0CC70C 03E00008 */  jr    $ra
/* 101240 7F0CC710 00601025 */   move  $v0, $v1
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0CC714(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0CC714
/* 101244 7F0CC714 14A00003 */  bnez  $a1, .L7F0CC724
/* 101248 7F0CC718 90830008 */   lbu   $v1, 8($a0)
/* 10124C 7F0CC71C 03E00008 */  jr    $ra
/* 101250 7F0CC720 00601025 */   move  $v0, $v1

.L7F0CC724:
/* 101254 7F0CC724 8C8E000C */  lw    $t6, 0xc($a0)
/* 101258 7F0CC728 3C028009 */  lui   $v0, %hi(dword_CODE_bss_8008D090) # $v0, 0x8009
/* 10125C 7F0CC72C 000EC080 */  sll   $t8, $t6, 2
/* 101260 7F0CC730 07010018 */  bgez  $t8, .L7F0CC794
/* 101264 7F0CC734 00000000 */   nop   
/* 101268 7F0CC738 8C42D090 */  lw    $v0, %lo(dword_CODE_bss_8008D090)($v0)
/* 10126C 7F0CC73C 00003025 */  move  $a2, $zero
/* 101270 7F0CC740 18400012 */  blez  $v0, .L7F0CC78C
/* 101274 7F0CC744 00000000 */   nop   
/* 101278 7F0CC748 8C830000 */  lw    $v1, ($a0)
/* 10127C 7F0CC74C 3C078009 */  lui   $a3, %hi(word_CODE_bss_8008C730) # $a3, 0x8009
/* 101280 7F0CC750 24E7C730 */  addiu $a3, %lo(word_CODE_bss_8008C730) # addiu $a3, $a3, -0x38d0
/* 101284 7F0CC754 0003CD02 */  srl   $t9, $v1, 0x14
/* 101288 7F0CC758 03201825 */  move  $v1, $t9
.L7F0CC75C:
/* 10128C 7F0CC75C 84E80000 */  lh    $t0, ($a3)
/* 101290 7F0CC760 14680006 */  bne   $v1, $t0, .L7F0CC77C
/* 101294 7F0CC764 00064900 */   sll   $t1, $a2, 4
/* 101298 7F0CC768 01255021 */  addu  $t2, $t1, $a1
/* 10129C 7F0CC76C 3C028009 */  lui   $v0, %hi(word_CODE_bss_8008C730+1)
/* 1012A0 7F0CC770 004A1021 */  addu  $v0, $v0, $t2
/* 1012A4 7F0CC774 03E00008 */  jr    $ra
/* 1012A8 7F0CC778 9042C731 */   lbu   $v0, %lo(word_CODE_bss_8008C730+1)($v0)

.L7F0CC77C:
/* 1012AC 7F0CC77C 24C60001 */  addiu $a2, $a2, 1
/* 1012B0 7F0CC780 00C2082A */  slt   $at, $a2, $v0
/* 1012B4 7F0CC784 1420FFF5 */  bnez  $at, .L7F0CC75C
/* 1012B8 7F0CC788 24E70010 */   addiu $a3, $a3, 0x10
.L7F0CC78C:
/* 1012BC 7F0CC78C 03E00008 */  jr    $ra
/* 1012C0 7F0CC790 24020001 */   li    $v0, 1

.L7F0CC794:
/* 1012C4 7F0CC794 18A00016 */  blez  $a1, .L7F0CC7F0
/* 1012C8 7F0CC798 00003025 */   move  $a2, $zero
/* 1012CC 7F0CC79C 30A40003 */  andi  $a0, $a1, 3
/* 1012D0 7F0CC7A0 10800008 */  beqz  $a0, .L7F0CC7C4
/* 1012D4 7F0CC7A4 00801025 */   move  $v0, $a0
.L7F0CC7A8:
/* 1012D8 7F0CC7A8 24630001 */  addiu $v1, $v1, 1
/* 1012DC 7F0CC7AC 00035843 */  sra   $t3, $v1, 1
/* 1012E0 7F0CC7B0 24C60001 */  addiu $a2, $a2, 1
/* 1012E4 7F0CC7B4 1446FFFC */  bne   $v0, $a2, .L7F0CC7A8
/* 1012E8 7F0CC7B8 01601825 */   move  $v1, $t3
/* 1012EC 7F0CC7BC 50C5000D */  beql  $a2, $a1, .L7F0CC7F4
/* 1012F0 7F0CC7C0 00601025 */   move  $v0, $v1
.L7F0CC7C4:
/* 1012F4 7F0CC7C4 24630001 */  addiu $v1, $v1, 1
/* 1012F8 7F0CC7C8 00036043 */  sra   $t4, $v1, 1
/* 1012FC 7F0CC7CC 25830001 */  addiu $v1, $t4, 1
/* 101300 7F0CC7D0 00036843 */  sra   $t5, $v1, 1
/* 101304 7F0CC7D4 25A30001 */  addiu $v1, $t5, 1
/* 101308 7F0CC7D8 00037043 */  sra   $t6, $v1, 1
/* 10130C 7F0CC7DC 25C30001 */  addiu $v1, $t6, 1
/* 101310 7F0CC7E0 00037843 */  sra   $t7, $v1, 1
/* 101314 7F0CC7E4 24C60004 */  addiu $a2, $a2, 4
/* 101318 7F0CC7E8 14C5FFF6 */  bne   $a2, $a1, .L7F0CC7C4
/* 10131C 7F0CC7EC 01E01825 */   move  $v1, $t7
.L7F0CC7F0:
/* 101320 7F0CC7F0 00601025 */  move  $v0, $v1
.L7F0CC7F4:
/* 101324 7F0CC7F4 03E00008 */  jr    $ra
/* 101328 7F0CC7F8 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0CC7FC(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0CC7FC
/* 10132C 7F0CC7FC 14A00003 */  bnez  $a1, .L7F0CC80C
/* 101330 7F0CC800 90830009 */   lbu   $v1, 9($a0)
/* 101334 7F0CC804 03E00008 */  jr    $ra
/* 101338 7F0CC808 00601025 */   move  $v0, $v1

.L7F0CC80C:
/* 10133C 7F0CC80C 8C8E000C */  lw    $t6, 0xc($a0)
/* 101340 7F0CC810 3C028009 */  lui   $v0, %hi(dword_CODE_bss_8008D090) # $v0, 0x8009
/* 101344 7F0CC814 000EC080 */  sll   $t8, $t6, 2
/* 101348 7F0CC818 07010018 */  bgez  $t8, .L7F0CC87C
/* 10134C 7F0CC81C 00000000 */   nop   
/* 101350 7F0CC820 8C42D090 */  lw    $v0, %lo(dword_CODE_bss_8008D090)($v0)
/* 101354 7F0CC824 00003025 */  move  $a2, $zero
/* 101358 7F0CC828 18400012 */  blez  $v0, .L7F0CC874
/* 10135C 7F0CC82C 00000000 */   nop   
/* 101360 7F0CC830 8C830000 */  lw    $v1, ($a0)
/* 101364 7F0CC834 3C078009 */  lui   $a3, %hi(word_CODE_bss_8008C730) # $a3, 0x8009
/* 101368 7F0CC838 24E7C730 */  addiu $a3, %lo(word_CODE_bss_8008C730) # addiu $a3, $a3, -0x38d0
/* 10136C 7F0CC83C 0003CD02 */  srl   $t9, $v1, 0x14
/* 101370 7F0CC840 03201825 */  move  $v1, $t9
.L7F0CC844:
/* 101374 7F0CC844 84E80000 */  lh    $t0, ($a3)
/* 101378 7F0CC848 14680006 */  bne   $v1, $t0, .L7F0CC864
/* 10137C 7F0CC84C 00064900 */   sll   $t1, $a2, 4
/* 101380 7F0CC850 01255021 */  addu  $t2, $t1, $a1
/* 101384 7F0CC854 3C028009 */  lui   $v0, %hi(word_CODE_bss_8008C730+8)
/* 101388 7F0CC858 004A1021 */  addu  $v0, $v0, $t2
/* 10138C 7F0CC85C 03E00008 */  jr    $ra
/* 101390 7F0CC860 9042C738 */   lbu   $v0, %lo(word_CODE_bss_8008C730+8)($v0)

.L7F0CC864:
/* 101394 7F0CC864 24C60001 */  addiu $a2, $a2, 1
/* 101398 7F0CC868 00C2082A */  slt   $at, $a2, $v0
/* 10139C 7F0CC86C 1420FFF5 */  bnez  $at, .L7F0CC844
/* 1013A0 7F0CC870 24E70010 */   addiu $a3, $a3, 0x10
.L7F0CC874:
/* 1013A4 7F0CC874 03E00008 */  jr    $ra
/* 1013A8 7F0CC878 24020001 */   li    $v0, 1

.L7F0CC87C:
/* 1013AC 7F0CC87C 18A00016 */  blez  $a1, .L7F0CC8D8
/* 1013B0 7F0CC880 00003025 */   move  $a2, $zero
/* 1013B4 7F0CC884 30A40003 */  andi  $a0, $a1, 3
/* 1013B8 7F0CC888 10800008 */  beqz  $a0, .L7F0CC8AC
/* 1013BC 7F0CC88C 00801025 */   move  $v0, $a0
.L7F0CC890:
/* 1013C0 7F0CC890 24630001 */  addiu $v1, $v1, 1
/* 1013C4 7F0CC894 00035843 */  sra   $t3, $v1, 1
/* 1013C8 7F0CC898 24C60001 */  addiu $a2, $a2, 1
/* 1013CC 7F0CC89C 1446FFFC */  bne   $v0, $a2, .L7F0CC890
/* 1013D0 7F0CC8A0 01601825 */   move  $v1, $t3
/* 1013D4 7F0CC8A4 50C5000D */  beql  $a2, $a1, .L7F0CC8DC
/* 1013D8 7F0CC8A8 00601025 */   move  $v0, $v1
.L7F0CC8AC:
/* 1013DC 7F0CC8AC 24630001 */  addiu $v1, $v1, 1
/* 1013E0 7F0CC8B0 00036043 */  sra   $t4, $v1, 1
/* 1013E4 7F0CC8B4 25830001 */  addiu $v1, $t4, 1
/* 1013E8 7F0CC8B8 00036843 */  sra   $t5, $v1, 1
/* 1013EC 7F0CC8BC 25A30001 */  addiu $v1, $t5, 1
/* 1013F0 7F0CC8C0 00037043 */  sra   $t6, $v1, 1
/* 1013F4 7F0CC8C4 25C30001 */  addiu $v1, $t6, 1
/* 1013F8 7F0CC8C8 00037843 */  sra   $t7, $v1, 1
/* 1013FC 7F0CC8CC 24C60004 */  addiu $a2, $a2, 4
/* 101400 7F0CC8D0 14C5FFF6 */  bne   $a2, $a1, .L7F0CC8AC
/* 101404 7F0CC8D4 01E01825 */   move  $v1, $t7
.L7F0CC8D8:
/* 101408 7F0CC8D8 00601025 */  move  $v0, $v1
.L7F0CC8DC:
/* 10140C 7F0CC8DC 03E00008 */  jr    $ra
/* 101410 7F0CC8E0 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0CC8E4(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0CC8E4
/* 101414 7F0CC8E4 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 101418 7F0CC8E8 AFBF0014 */  sw    $ra, 0x14($sp)
/* 10141C 7F0CC8EC 8C830008 */  lw    $v1, 8($a0)
/* 101420 7F0CC8F0 306E0003 */  andi  $t6, $v1, 3
/* 101424 7F0CC8F4 0FC331C5 */  jal   sub_GAME_7F0CC714
/* 101428 7F0CC8F8 AFAE001C */   sw    $t6, 0x1c($sp)
/* 10142C 7F0CC8FC 8FA3001C */  lw    $v1, 0x1c($sp)
/* 101430 7F0CC900 24010003 */  li    $at, 3
/* 101434 7F0CC904 00402025 */  move  $a0, $v0
/* 101438 7F0CC908 14610008 */  bne   $v1, $at, .L7F0CC92C
/* 10143C 7F0CC90C 8FBF0014 */   lw    $ra, 0x14($sp)
/* 101440 7F0CC910 24420003 */  addiu $v0, $v0, 3
/* 101444 7F0CC914 04410003 */  bgez  $v0, .L7F0CC924
/* 101448 7F0CC918 00027883 */   sra   $t7, $v0, 2
/* 10144C 7F0CC91C 24410003 */  addiu $at, $v0, 3
/* 101450 7F0CC920 00017883 */  sra   $t7, $at, 2
.L7F0CC924:
/* 101454 7F0CC924 10000019 */  b     .L7F0CC98C
/* 101458 7F0CC928 01E01025 */   move  $v0, $t7
.L7F0CC92C:
/* 10145C 7F0CC92C 24010002 */  li    $at, 2
/* 101460 7F0CC930 14610007 */  bne   $v1, $at, .L7F0CC950
/* 101464 7F0CC934 24820003 */   addiu $v0, $a0, 3
/* 101468 7F0CC938 04410003 */  bgez  $v0, .L7F0CC948
/* 10146C 7F0CC93C 0002C083 */   sra   $t8, $v0, 2
/* 101470 7F0CC940 24410003 */  addiu $at, $v0, 3
/* 101474 7F0CC944 0001C083 */  sra   $t8, $at, 2
.L7F0CC948:
/* 101478 7F0CC948 10000010 */  b     .L7F0CC98C
/* 10147C 7F0CC94C 03001025 */   move  $v0, $t8
.L7F0CC950:
/* 101480 7F0CC950 24010001 */  li    $at, 1
/* 101484 7F0CC954 14610008 */  bne   $v1, $at, .L7F0CC978
/* 101488 7F0CC958 2482000F */   addiu $v0, $a0, 0xf
/* 10148C 7F0CC95C 24820007 */  addiu $v0, $a0, 7
/* 101490 7F0CC960 04410003 */  bgez  $v0, .L7F0CC970
/* 101494 7F0CC964 0002C8C3 */   sra   $t9, $v0, 3
/* 101498 7F0CC968 24410007 */  addiu $at, $v0, 7
/* 10149C 7F0CC96C 0001C8C3 */  sra   $t9, $at, 3
.L7F0CC970:
/* 1014A0 7F0CC970 10000006 */  b     .L7F0CC98C
/* 1014A4 7F0CC974 03201025 */   move  $v0, $t9
.L7F0CC978:
/* 1014A8 7F0CC978 04410003 */  bgez  $v0, .L7F0CC988
/* 1014AC 7F0CC97C 00024103 */   sra   $t0, $v0, 4
/* 1014B0 7F0CC980 2441000F */  addiu $at, $v0, 0xf
/* 1014B4 7F0CC984 00014103 */  sra   $t0, $at, 4
.L7F0CC988:
/* 1014B8 7F0CC988 01001025 */  move  $v0, $t0
.L7F0CC98C:
/* 1014BC 7F0CC98C 03E00008 */  jr    $ra
/* 1014C0 7F0CC990 27BD0020 */   addiu $sp, $sp, 0x20
)
#endif





#ifdef NONMATCHING
s32 sub_GAME_7F0CC994(s32 arg0, s32 arg1) {
    s32 sp1C;

    // Node 0
    sp1C = sub_GAME_7F0CC7FC();
    return (sub_GAME_7F0CC8E4(arg0, arg1) * sp1C);
}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0CC994
/* 1014C4 7F0CC994 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 1014C8 7F0CC998 AFBF0014 */  sw    $ra, 0x14($sp)
/* 1014CC 7F0CC99C AFA40020 */  sw    $a0, 0x20($sp)
/* 1014D0 7F0CC9A0 0FC331FF */  jal   sub_GAME_7F0CC7FC
/* 1014D4 7F0CC9A4 AFA50024 */   sw    $a1, 0x24($sp)
/* 1014D8 7F0CC9A8 AFA2001C */  sw    $v0, 0x1c($sp)
/* 1014DC 7F0CC9AC 8FA40020 */  lw    $a0, 0x20($sp)
/* 1014E0 7F0CC9B0 0FC33239 */  jal   sub_GAME_7F0CC8E4
/* 1014E4 7F0CC9B4 8FA50024 */   lw    $a1, 0x24($sp)
/* 1014E8 7F0CC9B8 8FAE001C */  lw    $t6, 0x1c($sp)
/* 1014EC 7F0CC9BC 8FBF0014 */  lw    $ra, 0x14($sp)
/* 1014F0 7F0CC9C0 27BD0020 */  addiu $sp, $sp, 0x20
/* 1014F4 7F0CC9C4 004E0019 */  multu $v0, $t6
/* 1014F8 7F0CC9C8 00001012 */  mflo  $v0
/* 1014FC 7F0CC9CC 03E00008 */  jr    $ra
/* 101500 7F0CC9D0 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
s32 sub_GAME_7F0CC9D4(void *arg0, void *arg1, void *arg2) {
    s32 temp_t6;
    u32 temp_t7;
    s32 temp_ret;
    s32 temp_s0;
    u32 phi_s2;
    s32 phi_s0;
    s32 phi_return;

    // Node 0
    temp_t6 = (arg0->unk8 & 3);
    temp_t7 = ((u32) arg0->unkB >> 5);
    if (temp_t7 != 0)
    {
        // Node 1
        phi_s2 = temp_t7;
    }
    else
    {
        // Node 2
        phi_s2 = 1U;
    }
    // Node 3
    *arg2 = 0;
    if (temp_t6 == 3)
    {
        // Node 4
        *arg1 = 3;
    }
    else
    {
        // Node 5
        if (temp_t6 == 2)
        {
            // Node 6
            *arg1 = 2;
        }
        else
        {
            // Node 7
            if (temp_t6 == 1)
            {
                // Node 8
                *arg1 = 2;
            }
            else
            {
                // Node 9
                *arg1 = 2;
            }
        }
    }
    // Node 10
    phi_s0 = 0;
    phi_return = 3;
    if (phi_s2 > 0)
    {
loop_11:
        // Node 11
        temp_ret = sub_GAME_7F0CC994(arg0, phi_s0);
        temp_s0 = (phi_s0 + 1);
        *arg2 = (s32) (*arg2 + (temp_ret * 4));
        phi_s0 = temp_s0;
        phi_return = temp_ret;
        if (temp_s0 != phi_s2)
        {
            goto loop_11;
        }
    }
    // Node 12
    return phi_return;
}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0CC9D4
/* 101504 7F0CC9D4 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 101508 7F0CC9D8 AFBF0024 */  sw    $ra, 0x24($sp)
/* 10150C 7F0CC9DC AFB30020 */  sw    $s3, 0x20($sp)
/* 101510 7F0CC9E0 AFB2001C */  sw    $s2, 0x1c($sp)
/* 101514 7F0CC9E4 AFB10018 */  sw    $s1, 0x18($sp)
/* 101518 7F0CC9E8 AFB00014 */  sw    $s0, 0x14($sp)
/* 10151C 7F0CC9EC 8C830008 */  lw    $v1, 8($a0)
/* 101520 7F0CC9F0 9082000B */  lbu   $v0, 0xb($a0)
/* 101524 7F0CC9F4 00C08825 */  move  $s1, $a2
/* 101528 7F0CC9F8 306E0003 */  andi  $t6, $v1, 3
/* 10152C 7F0CC9FC 00027942 */  srl   $t7, $v0, 5
/* 101530 7F0CCA00 00809825 */  move  $s3, $a0
/* 101534 7F0CCA04 11E00003 */  beqz  $t7, .L7F0CCA14
/* 101538 7F0CCA08 01C01825 */   move  $v1, $t6
/* 10153C 7F0CCA0C 10000002 */  b     .L7F0CCA18
/* 101540 7F0CCA10 01E09025 */   move  $s2, $t7
.L7F0CCA14:
/* 101544 7F0CCA14 24120001 */  li    $s2, 1
.L7F0CCA18:
/* 101548 7F0CCA18 24020003 */  li    $v0, 3
/* 10154C 7F0CCA1C 14620003 */  bne   $v1, $v0, .L7F0CCA2C
/* 101550 7F0CCA20 AE200000 */   sw    $zero, ($s1)
/* 101554 7F0CCA24 1000000B */  b     .L7F0CCA54
/* 101558 7F0CCA28 ACA20000 */   sw    $v0, ($a1)
.L7F0CCA2C:
/* 10155C 7F0CCA2C 24020002 */  li    $v0, 2
/* 101560 7F0CCA30 14620003 */  bne   $v1, $v0, .L7F0CCA40
/* 101564 7F0CCA34 24010001 */   li    $at, 1
/* 101568 7F0CCA38 10000006 */  b     .L7F0CCA54
/* 10156C 7F0CCA3C ACA20000 */   sw    $v0, ($a1)
.L7F0CCA40:
/* 101570 7F0CCA40 54610004 */  bnel  $v1, $at, .L7F0CCA54
/* 101574 7F0CCA44 ACA20000 */   sw    $v0, ($a1)
/* 101578 7F0CCA48 10000002 */  b     .L7F0CCA54
/* 10157C 7F0CCA4C ACA20000 */   sw    $v0, ($a1)
/* 101580 7F0CCA50 ACA20000 */  sw    $v0, ($a1)
.L7F0CCA54:
/* 101584 7F0CCA54 1A40000A */  blez  $s2, .L7F0CCA80
/* 101588 7F0CCA58 00008025 */   move  $s0, $zero
.L7F0CCA5C:
/* 10158C 7F0CCA5C 02602025 */  move  $a0, $s3
/* 101590 7F0CCA60 0FC33265 */  jal   sub_GAME_7F0CC994
/* 101594 7F0CCA64 02002825 */   move  $a1, $s0
/* 101598 7F0CCA68 8E380000 */  lw    $t8, ($s1)
/* 10159C 7F0CCA6C 0002C880 */  sll   $t9, $v0, 2
/* 1015A0 7F0CCA70 26100001 */  addiu $s0, $s0, 1
/* 1015A4 7F0CCA74 03194021 */  addu  $t0, $t8, $t9
/* 1015A8 7F0CCA78 1612FFF8 */  bne   $s0, $s2, .L7F0CCA5C
/* 1015AC 7F0CCA7C AE280000 */   sw    $t0, ($s1)
.L7F0CCA80:
/* 1015B0 7F0CCA80 8FBF0024 */  lw    $ra, 0x24($sp)
/* 1015B4 7F0CCA84 8FB00014 */  lw    $s0, 0x14($sp)
/* 1015B8 7F0CCA88 8FB10018 */  lw    $s1, 0x18($sp)
/* 1015BC 7F0CCA8C 8FB2001C */  lw    $s2, 0x1c($sp)
/* 1015C0 7F0CCA90 8FB30020 */  lw    $s3, 0x20($sp)
/* 1015C4 7F0CCA94 03E00008 */  jr    $ra
/* 1015C8 7F0CCA98 27BD0028 */   addiu $sp, $sp, 0x28
)
#endif





#ifdef NONMATCHING
s32 sub_GAME_7F0CCA9C(s32 arg0) {
    s32 temp_a0;
    s32 temp_t6;
    s32 temp_v1;
    s32 phi_a0;
    s32 phi_v1;
    s32 phi_v1_2;

    // Node 0
    temp_a0 = (arg0 + -1);
    phi_v1_2 = 0;
    if (temp_a0 > 0)
    {
        // Node 1
        phi_a0 = temp_a0;
        phi_v1 = 0;
loop_2:
        // Node 2
        temp_t6 = ((s32) phi_a0 >> 1);
        temp_v1 = (phi_v1 + 1);
        phi_v1_2 = temp_v1;
        if (temp_t6 > 0)
        {
            // Node 3
            phi_a0 = temp_t6;
            phi_v1 = temp_v1;
            phi_v1_2 = temp_v1;
            if (temp_v1 != 8)
            {
                goto loop_2;
            }
        }
    }
    // Node 4
    return phi_v1_2;
}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0CCA9C
/* 1015CC 7F0CCA9C 2484FFFF */  addiu $a0, $a0, -1
/* 1015D0 7F0CCAA0 18800008 */  blez  $a0, .L7F0CCAC4
/* 1015D4 7F0CCAA4 00001825 */   move  $v1, $zero
/* 1015D8 7F0CCAA8 24020008 */  li    $v0, 8
/* 1015DC 7F0CCAAC 00047043 */  sra   $t6, $a0, 1
.L7F0CCAB0:
/* 1015E0 7F0CCAB0 01C02025 */  move  $a0, $t6
/* 1015E4 7F0CCAB4 19C00003 */  blez  $t6, .L7F0CCAC4
/* 1015E8 7F0CCAB8 24630001 */   addiu $v1, $v1, 1
/* 1015EC 7F0CCABC 5462FFFC */  bnel  $v1, $v0, .L7F0CCAB0
/* 1015F0 7F0CCAC0 00047043 */   sra   $t6, $a0, 1
.L7F0CCAC4:
/* 1015F4 7F0CCAC4 03E00008 */  jr    $ra
/* 1015F8 7F0CCAC8 00601025 */   move  $v0, $v1
)
#endif





u32 sub_GAME_7F0CCACC(s32 arg0) {
    if (arg0 == 1) {
        return 2;
    }
    if (arg0 == 2) {
        return 1;
    }
    return 0;
}





#ifdef NONMATCHING
void sub_GAME_7F0CCAFC(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0CCAFC
/* 10162C 7F0CCAFC 4600610D */  trunc.w.s $f4, $f12
/* 101630 7F0CCB00 44022000 */  mfc1  $v0, $f4
/* 101634 7F0CCB04 00000000 */  nop   
/* 101638 7F0CCB08 44823000 */  mtc1  $v0, $f6
/* 10163C 7F0CCB0C 00401825 */  move  $v1, $v0
/* 101640 7F0CCB10 46803220 */  cvt.s.w $f8, $f6
/* 101644 7F0CCB14 460C403C */  c.lt.s $f8, $f12
/* 101648 7F0CCB18 00000000 */  nop   
/* 10164C 7F0CCB1C 45000004 */  bc1f  .L7F0CCB30
/* 101650 7F0CCB20 00000000 */   nop   
/* 101654 7F0CCB24 24430001 */  addiu $v1, $v0, 1
/* 101658 7F0CCB28 03E00008 */  jr    $ra
/* 10165C 7F0CCB2C 00601025 */   move  $v0, $v1

.L7F0CCB30:
/* 101660 7F0CCB30 03E00008 */  jr    $ra
/* 101664 7F0CCB34 00601025 */   move  $v0, $v1
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0CCB38(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0CCB38
/* 101668 7F0CCB38 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 10166C 7F0CCB3C AFBF0014 */  sw    $ra, 0x14($sp)
/* 101670 7F0CCB40 AFA40018 */  sw    $a0, 0x18($sp)
/* 101674 7F0CCB44 0FC33239 */  jal   sub_GAME_7F0CC8E4
/* 101678 7F0CCB48 00002825 */   move  $a1, $zero
/* 10167C 7F0CCB4C 8FAE0018 */  lw    $t6, 0x18($sp)
/* 101680 7F0CCB50 24010003 */  li    $at, 3
/* 101684 7F0CCB54 00402025 */  move  $a0, $v0
/* 101688 7F0CCB58 8DC30008 */  lw    $v1, 8($t6)
/* 10168C 7F0CCB5C 0002C080 */  sll   $t8, $v0, 2
/* 101690 7F0CCB60 306F0003 */  andi  $t7, $v1, 3
/* 101694 7F0CCB64 15E1000D */  bne   $t7, $at, .L7F0CCB9C
/* 101698 7F0CCB68 01E01825 */   move  $v1, $t7
/* 10169C 7F0CCB6C 44983000 */  mtc1  $t8, $f6
/* 1016A0 7F0CCB70 3C014000 */  li    $at, 0x40000000 # 2.000000
/* 1016A4 7F0CCB74 44812000 */  mtc1  $at, $f4
/* 1016A8 7F0CCB78 46803220 */  cvt.s.w $f8, $f6
/* 1016AC 7F0CCB7C 3C014500 */  li    $at, 0x45000000 # 2048.000000
/* 1016B0 7F0CCB80 44818000 */  mtc1  $at, $f16
/* 1016B4 7F0CCB84 46082283 */  div.s $f10, $f4, $f8
/* 1016B8 7F0CCB88 46105302 */  mul.s $f12, $f10, $f16
/* 1016BC 7F0CCB8C 0FC332BF */  jal   sub_GAME_7F0CCAFC
/* 1016C0 7F0CCB90 00000000 */   nop   
/* 1016C4 7F0CCB94 1000002B */  b     .L7F0CCC44
/* 1016C8 7F0CCB98 8FBF0014 */   lw    $ra, 0x14($sp)
.L7F0CCB9C:
/* 1016CC 7F0CCB9C 24010002 */  li    $at, 2
/* 1016D0 7F0CCBA0 1461000D */  bne   $v1, $at, .L7F0CCBD8
/* 1016D4 7F0CCBA4 0004C880 */   sll   $t9, $a0, 2
/* 1016D8 7F0CCBA8 44993000 */  mtc1  $t9, $f6
/* 1016DC 7F0CCBAC 3C014080 */  li    $at, 0x40800000 # 4.000000
/* 1016E0 7F0CCBB0 44819000 */  mtc1  $at, $f18
/* 1016E4 7F0CCBB4 46803120 */  cvt.s.w $f4, $f6
/* 1016E8 7F0CCBB8 3C014500 */  li    $at, 0x45000000 # 2048.000000
/* 1016EC 7F0CCBBC 44815000 */  mtc1  $at, $f10
/* 1016F0 7F0CCBC0 46049203 */  div.s $f8, $f18, $f4
/* 1016F4 7F0CCBC4 460A4302 */  mul.s $f12, $f8, $f10
/* 1016F8 7F0CCBC8 0FC332BF */  jal   sub_GAME_7F0CCAFC
/* 1016FC 7F0CCBCC 00000000 */   nop   
/* 101700 7F0CCBD0 1000001C */  b     .L7F0CCC44
/* 101704 7F0CCBD4 8FBF0014 */   lw    $ra, 0x14($sp)
.L7F0CCBD8:
/* 101708 7F0CCBD8 24010001 */  li    $at, 1
/* 10170C 7F0CCBDC 1461000E */  bne   $v1, $at, .L7F0CCC18
/* 101710 7F0CCBE0 00044900 */   sll   $t1, $a0, 4
/* 101714 7F0CCBE4 000440C0 */  sll   $t0, $a0, 3
/* 101718 7F0CCBE8 44883000 */  mtc1  $t0, $f6
/* 10171C 7F0CCBEC 3C014100 */  li    $at, 0x41000000 # 8.000000
/* 101720 7F0CCBF0 44818000 */  mtc1  $at, $f16
/* 101724 7F0CCBF4 468034A0 */  cvt.s.w $f18, $f6
/* 101728 7F0CCBF8 3C014500 */  li    $at, 0x45000000 # 2048.000000
/* 10172C 7F0CCBFC 44814000 */  mtc1  $at, $f8
/* 101730 7F0CCC00 46128103 */  div.s $f4, $f16, $f18
/* 101734 7F0CCC04 46082302 */  mul.s $f12, $f4, $f8
/* 101738 7F0CCC08 0FC332BF */  jal   sub_GAME_7F0CCAFC
/* 10173C 7F0CCC0C 00000000 */   nop   
/* 101740 7F0CCC10 1000000C */  b     .L7F0CCC44
/* 101744 7F0CCC14 8FBF0014 */   lw    $ra, 0x14($sp)
.L7F0CCC18:
/* 101748 7F0CCC18 44893000 */  mtc1  $t1, $f6
/* 10174C 7F0CCC1C 3C014180 */  li    $at, 0x41800000 # 16.000000
/* 101750 7F0CCC20 44815000 */  mtc1  $at, $f10
/* 101754 7F0CCC24 46803420 */  cvt.s.w $f16, $f6
/* 101758 7F0CCC28 3C014500 */  li    $at, 0x45000000 # 2048.000000
/* 10175C 7F0CCC2C 44812000 */  mtc1  $at, $f4
/* 101760 7F0CCC30 46105483 */  div.s $f18, $f10, $f16
/* 101764 7F0CCC34 46049302 */  mul.s $f12, $f18, $f4
/* 101768 7F0CCC38 0FC332BF */  jal   sub_GAME_7F0CCAFC
/* 10176C 7F0CCC3C 00000000 */   nop   
/* 101770 7F0CCC40 8FBF0014 */  lw    $ra, 0x14($sp)
.L7F0CCC44:
/* 101774 7F0CCC44 27BD0018 */  addiu $sp, $sp, 0x18
/* 101778 7F0CCC48 03E00008 */  jr    $ra
/* 10177C 7F0CCC4C 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0CCC50(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0CCC50
/* 101780 7F0CCC50 27BDFF70 */  addiu $sp, $sp, -0x90
/* 101784 7F0CCC54 AFBF0044 */  sw    $ra, 0x44($sp)
/* 101788 7F0CCC58 AFB20040 */  sw    $s2, 0x40($sp)
/* 10178C 7F0CCC5C AFB1003C */  sw    $s1, 0x3c($sp)
/* 101790 7F0CCC60 AFB00038 */  sw    $s0, 0x38($sp)
/* 101794 7F0CCC64 AFA60098 */  sw    $a2, 0x98($sp)
/* 101798 7F0CCC68 AFA7009C */  sw    $a3, 0x9c($sp)
/* 10179C 7F0CCC6C 8CAE0000 */  lw    $t6, ($a1)
/* 1017A0 7F0CCC70 3C198005 */  lui   $t9, %hi(image_entries) # $t9, 0x8005
/* 1017A4 7F0CCC74 00809025 */  move  $s2, $a0
/* 1017A8 7F0CCC78 000E7D02 */  srl   $t7, $t6, 0x14
/* 1017AC 7F0CCC7C 000FC0C0 */  sll   $t8, $t7, 3
/* 1017B0 7F0CCC80 27399300 */  addiu $t9, %lo(image_entries) # addiu $t9, $t9, -0x6d00
/* 1017B4 7F0CCC84 00A08825 */  move  $s1, $a1
/* 1017B8 7F0CCC88 03198021 */  addu  $s0, $t8, $t9
/* 1017BC 7F0CCC8C 0FC332A7 */  jal   sub_GAME_7F0CCA9C
/* 1017C0 7F0CCC90 90A40008 */   lbu   $a0, 8($a1)
/* 1017C4 7F0CCC94 AFA20088 */  sw    $v0, 0x88($sp)
/* 1017C8 7F0CCC98 0FC332A7 */  jal   sub_GAME_7F0CCA9C
/* 1017CC 7F0CCC9C 92240009 */   lbu   $a0, 9($s1)
/* 1017D0 7F0CCCA0 AFA20084 */  sw    $v0, 0x84($sp)
/* 1017D4 7F0CCCA4 02202025 */  move  $a0, $s1
/* 1017D8 7F0CCCA8 0FC33239 */  jal   sub_GAME_7F0CC8E4
/* 1017DC 7F0CCCAC 00002825 */   move  $a1, $zero
/* 1017E0 7F0CCCB0 8FA800A4 */  lw    $t0, 0xa4($sp)
/* 1017E4 7F0CCCB4 02401825 */  move  $v1, $s2
/* 1017E8 7F0CCCB8 3C01FA00 */  lui   $at, 0xfa00
/* 1017EC 7F0CCCBC 310900FF */  andi  $t1, $t0, 0xff
/* 1017F0 7F0CCCC0 00095200 */  sll   $t2, $t1, 8
/* 1017F4 7F0CCCC4 01415825 */  or    $t3, $t2, $at
/* 1017F8 7F0CCCC8 240CFFFF */  li    $t4, -1
/* 1017FC 7F0CCCCC AC6C0004 */  sw    $t4, 4($v1)
/* 101800 7F0CCCD0 AC6B0000 */  sw    $t3, ($v1)
/* 101804 7F0CCCD4 8E24000C */  lw    $a0, 0xc($s1)
/* 101808 7F0CCCD8 26520008 */  addiu $s2, $s2, 8
/* 10180C 7F0CCCDC AFA20080 */  sw    $v0, 0x80($sp)
/* 101810 7F0CCCE0 00046F82 */  srl   $t5, $a0, 0x1e
/* 101814 7F0CCCE4 0FC33152 */  jal   sub_GAME_7F0CC548
/* 101818 7F0CCCE8 000D2380 */   sll   $a0, $t5, 0xe
/* 10181C 7F0CCCEC 1040000A */  beqz  $v0, .L7F0CCD18
/* 101820 7F0CCCF0 8FA70080 */   lw    $a3, 0x80($sp)
/* 101824 7F0CCCF4 3C0FBA00 */  lui   $t7, (0xBA000E02 >> 16) # lui $t7, 0xba00
/* 101828 7F0CCCF8 35EF0E02 */  ori   $t7, (0xBA000E02 & 0xFFFF) # ori $t7, $t7, 0xe02
/* 10182C 7F0CCCFC 02401025 */  move  $v0, $s2
/* 101830 7F0CCD00 AC4F0000 */  sw    $t7, ($v0)
/* 101834 7F0CCD04 8E38000C */  lw    $t8, 0xc($s1)
/* 101838 7F0CCD08 26520008 */  addiu $s2, $s2, 8
/* 10183C 7F0CCD0C 0018CF82 */  srl   $t9, $t8, 0x1e
/* 101840 7F0CCD10 00194380 */  sll   $t0, $t9, 0xe
/* 101844 7F0CCD14 AC480004 */  sw    $t0, 4($v0)
.L7F0CCD18:
/* 101848 7F0CCD18 920C0004 */  lbu   $t4, 4($s0)
/* 10184C 7F0CCD1C 8E0A0004 */  lw    $t2, 4($s0)
/* 101850 7F0CCD20 8E220008 */  lw    $v0, 8($s1)
/* 101854 7F0CCD24 318D000F */  andi  $t5, $t4, 0xf
/* 101858 7F0CCD28 00ED0019 */  multu $a3, $t5
/* 10185C 7F0CCD2C 000A5F02 */  srl   $t3, $t2, 0x1c
/* 101860 7F0CCD30 AFA00018 */  sw    $zero, 0x18($sp)
/* 101864 7F0CCD34 AFA00014 */  sw    $zero, 0x14($sp)
/* 101868 7F0CCD38 8FB80088 */  lw    $t8, 0x88($sp)
/* 10186C 7F0CCD3C 00022EC0 */  sll   $a1, $v0, 0x1b
/* 101870 7F0CCD40 00054F42 */  srl   $t1, $a1, 0x1d
/* 101874 7F0CCD44 01202825 */  move  $a1, $t1
/* 101878 7F0CCD48 8FAA0084 */  lw    $t2, 0x84($sp)
/* 10187C 7F0CCD4C 00002025 */  move  $a0, $zero
/* 101880 7F0CCD50 00007012 */  mflo  $t6
/* 101884 7F0CCD54 016E7821 */  addu  $t7, $t3, $t6
/* 101888 7F0CCD58 AFAF0010 */  sw    $t7, 0x10($sp)
/* 10188C 7F0CCD5C 92190005 */  lbu   $t9, 5($s0)
/* 101890 7F0CCD60 8FAF00A0 */  lw    $t7, 0xa0($sp)
/* 101894 7F0CCD64 8FAE009C */  lw    $t6, 0x9c($sp)
/* 101898 7F0CCD68 00194102 */  srl   $t0, $t9, 4
/* 10189C 7F0CCD6C 03084823 */  subu  $t1, $t8, $t0
/* 1018A0 7F0CCD70 AFA9001C */  sw    $t1, 0x1c($sp)
/* 1018A4 7F0CCD74 960C0004 */  lhu   $t4, 4($s0)
/* 1018A8 7F0CCD78 AFA70080 */  sw    $a3, 0x80($sp)
/* 1018AC 7F0CCD7C 30460003 */  andi  $a2, $v0, 3
/* 1018B0 7F0CCD80 318D000F */  andi  $t5, $t4, 0xf
/* 1018B4 7F0CCD84 014D5823 */  subu  $t3, $t2, $t5
/* 1018B8 7F0CCD88 AFAB0020 */  sw    $t3, 0x20($sp)
/* 1018BC 7F0CCD8C AFAF0028 */  sw    $t7, 0x28($sp)
/* 1018C0 7F0CCD90 0FC3315D */  jal   sub_GAME_7F0CC574
/* 1018C4 7F0CCD94 AFAE0024 */   sw    $t6, 0x24($sp)
/* 1018C8 7F0CCD98 1040003C */  beqz  $v0, .L7F0CCE8C
/* 1018CC 7F0CCD9C 8FA70080 */   lw    $a3, 0x80($sp)
/* 1018D0 7F0CCDA0 8E2A0008 */  lw    $t2, 8($s1)
/* 1018D4 7F0CCDA4 3C01F500 */  lui   $at, 0xf500
/* 1018D8 7F0CCDA8 30EF01FF */  andi  $t7, $a3, 0x1ff
/* 1018DC 7F0CCDAC 000ACEC0 */  sll   $t9, $t2, 0x1b
/* 1018E0 7F0CCDB0 314D0003 */  andi  $t5, $t2, 3
/* 1018E4 7F0CCDB4 920A0004 */  lbu   $t2, 4($s0)
/* 1018E8 7F0CCDB8 000D5CC0 */  sll   $t3, $t5, 0x13
/* 1018EC 7F0CCDBC 0019C742 */  srl   $t8, $t9, 0x1d
/* 1018F0 7F0CCDC0 314D000F */  andi  $t5, $t2, 0xf
/* 1018F4 7F0CCDC4 00ED0019 */  multu $a3, $t5
/* 1018F8 7F0CCDC8 33080007 */  andi  $t0, $t8, 7
/* 1018FC 7F0CCDCC 00084D40 */  sll   $t1, $t0, 0x15
/* 101900 7F0CCDD0 8E080004 */  lw    $t0, 4($s0)
/* 101904 7F0CCDD4 01216025 */  or    $t4, $t1, $at
/* 101908 7F0CCDD8 018B7025 */  or    $t6, $t4, $t3
/* 10190C 7F0CCDDC 000FCA40 */  sll   $t9, $t7, 9
/* 101910 7F0CCDE0 00084F02 */  srl   $t1, $t0, 0x1c
/* 101914 7F0CCDE4 01D9C025 */  or    $t8, $t6, $t9
/* 101918 7F0CCDE8 02401825 */  move  $v1, $s2
/* 10191C 7F0CCDEC 00006012 */  mflo  $t4
/* 101920 7F0CCDF0 012C5821 */  addu  $t3, $t1, $t4
/* 101924 7F0CCDF4 316F01FF */  andi  $t7, $t3, 0x1ff
/* 101928 7F0CCDF8 030F7025 */  or    $t6, $t8, $t7
/* 10192C 7F0CCDFC AC6E0000 */  sw    $t6, ($v1)
/* 101930 7F0CCE00 AFA30054 */  sw    $v1, 0x54($sp)
/* 101934 7F0CCE04 26520008 */  addiu $s2, $s2, 8
/* 101938 7F0CCE08 0FC332B3 */  jal   sub_GAME_7F0CCACC
/* 10193C 7F0CCE0C 00002025 */   move  $a0, $zero
/* 101940 7F0CCE10 00002025 */  move  $a0, $zero
/* 101944 7F0CCE14 0FC332B3 */  jal   sub_GAME_7F0CCACC
/* 101948 7F0CCE18 AFA2004C */   sw    $v0, 0x4c($sp)
/* 10194C 7F0CCE1C 8FA3004C */  lw    $v1, 0x4c($sp)
/* 101950 7F0CCE20 8FAC0084 */  lw    $t4, 0x84($sp)
/* 101954 7F0CCE24 96180004 */  lhu   $t8, 4($s0)
/* 101958 7F0CCE28 30590003 */  andi  $t9, $v0, 3
/* 10195C 7F0CCE2C 306A0003 */  andi  $t2, $v1, 3
/* 101960 7F0CCE30 000A6C80 */  sll   $t5, $t2, 0x12
/* 101964 7F0CCE34 00194200 */  sll   $t0, $t9, 8
/* 101968 7F0CCE38 010D4825 */  or    $t1, $t0, $t5
/* 10196C 7F0CCE3C 01987823 */  subu  $t7, $t4, $t8
/* 101970 7F0CCE40 8FA800A0 */  lw    $t0, 0xa0($sp)
/* 101974 7F0CCE44 31EE000F */  andi  $t6, $t7, 0xf
/* 101978 7F0CCE48 920F0005 */  lbu   $t7, 5($s0)
/* 10197C 7F0CCE4C 000ECB80 */  sll   $t9, $t6, 0xe
/* 101980 7F0CCE50 8FB80088 */  lw    $t8, 0x88($sp)
/* 101984 7F0CCE54 01395025 */  or    $t2, $t1, $t9
/* 101988 7F0CCE58 310D000F */  andi  $t5, $t0, 0xf
/* 10198C 7F0CCE5C 000D5A80 */  sll   $t3, $t5, 0xa
/* 101990 7F0CCE60 014B6025 */  or    $t4, $t2, $t3
/* 101994 7F0CCE64 000F7102 */  srl   $t6, $t7, 4
/* 101998 7F0CCE68 8FAA009C */  lw    $t2, 0x9c($sp)
/* 10199C 7F0CCE6C 030E4823 */  subu  $t1, $t8, $t6
/* 1019A0 7F0CCE70 3139000F */  andi  $t9, $t1, 0xf
/* 1019A4 7F0CCE74 8FB80054 */  lw    $t8, 0x54($sp)
/* 1019A8 7F0CCE78 00194100 */  sll   $t0, $t9, 4
/* 1019AC 7F0CCE7C 01886825 */  or    $t5, $t4, $t0
/* 1019B0 7F0CCE80 314B000F */  andi  $t3, $t2, 0xf
/* 1019B4 7F0CCE84 01AB7825 */  or    $t7, $t5, $t3
/* 1019B8 7F0CCE88 AF0F0004 */  sw    $t7, 4($t8)
.L7F0CCE8C:
/* 1019BC 7F0CCE8C 8FA40098 */  lw    $a0, 0x98($sp)
/* 1019C0 7F0CCE90 24020002 */  li    $v0, 2
/* 1019C4 7F0CCE94 00001825 */  move  $v1, $zero
/* 1019C8 7F0CCE98 14820007 */  bne   $a0, $v0, .L7F0CCEB8
/* 1019CC 7F0CCE9C 00000000 */   nop   
/* 1019D0 7F0CCEA0 8E2E000C */  lw    $t6, 0xc($s1)
/* 1019D4 7F0CCEA4 000EC880 */  sll   $t9, $t6, 2
/* 1019D8 7F0CCEA8 07200003 */  bltz  $t9, .L7F0CCEB8
/* 1019DC 7F0CCEAC 00000000 */   nop   
/* 1019E0 7F0CCEB0 10000001 */  b     .L7F0CCEB8
/* 1019E4 7F0CCEB4 00401825 */   move  $v1, $v0
.L7F0CCEB8:
/* 1019E8 7F0CCEB8 14820007 */  bne   $a0, $v0, .L7F0CCED8
/* 1019EC 7F0CCEBC 00602825 */   move  $a1, $v1
/* 1019F0 7F0CCEC0 8E2C000C */  lw    $t4, 0xc($s1)
/* 1019F4 7F0CCEC4 000C5080 */  sll   $t2, $t4, 2
/* 1019F8 7F0CCEC8 05420004 */  bltzl $t2, .L7F0CCEDC
/* 1019FC 7F0CCECC 00001825 */   move  $v1, $zero
/* 101A00 7F0CCED0 10000002 */  b     .L7F0CCEDC
/* 101A04 7F0CCED4 00401825 */   move  $v1, $v0
.L7F0CCED8:
/* 101A08 7F0CCED8 00001825 */  move  $v1, $zero
.L7F0CCEDC:
/* 101A0C 7F0CCEDC 14820007 */  bne   $a0, $v0, .L7F0CCEFC
/* 101A10 7F0CCEE0 00603025 */   move  $a2, $v1
/* 101A14 7F0CCEE4 8E2D000C */  lw    $t5, 0xc($s1)
/* 101A18 7F0CCEE8 000D7880 */  sll   $t7, $t5, 2
/* 101A1C 7F0CCEEC 05E20004 */  bltzl $t7, .L7F0CCF00
/* 101A20 7F0CCEF0 00001825 */   move  $v1, $zero
/* 101A24 7F0CCEF4 10000002 */  b     .L7F0CCF00
/* 101A28 7F0CCEF8 00401825 */   move  $v1, $v0
.L7F0CCEFC:
/* 101A2C 7F0CCEFC 00001825 */  move  $v1, $zero
.L7F0CCF00:
/* 101A30 7F0CCF00 92380008 */  lbu   $t8, 8($s1)
/* 101A34 7F0CCF04 270EFFFF */  addiu $t6, $t8, -1
/* 101A38 7F0CCF08 000E4880 */  sll   $t1, $t6, 2
/* 101A3C 7F0CCF0C 14820007 */  bne   $a0, $v0, .L7F0CCF2C
/* 101A40 7F0CCF10 00693821 */   addu  $a3, $v1, $t1
/* 101A44 7F0CCF14 8E39000C */  lw    $t9, 0xc($s1)
/* 101A48 7F0CCF18 00194080 */  sll   $t0, $t9, 2
/* 101A4C 7F0CCF1C 05020004 */  bltzl $t0, .L7F0CCF30
/* 101A50 7F0CCF20 00001825 */   move  $v1, $zero
/* 101A54 7F0CCF24 10000002 */  b     .L7F0CCF30
/* 101A58 7F0CCF28 24030002 */   li    $v1, 2
.L7F0CCF2C:
/* 101A5C 7F0CCF2C 00001825 */  move  $v1, $zero
.L7F0CCF30:
/* 101A60 7F0CCF30 922A0009 */  lbu   $t2, 9($s1)
/* 101A64 7F0CCF34 AFA70064 */  sw    $a3, 0x64($sp)
/* 101A68 7F0CCF38 AFA60068 */  sw    $a2, 0x68($sp)
/* 101A6C 7F0CCF3C 254DFFFF */  addiu $t5, $t2, -1
/* 101A70 7F0CCF40 000D5880 */  sll   $t3, $t5, 2
/* 101A74 7F0CCF44 006B8021 */  addu  $s0, $v1, $t3
/* 101A78 7F0CCF48 AFB00010 */  sw    $s0, 0x10($sp)
/* 101A7C 7F0CCF4C AFA5006C */  sw    $a1, 0x6c($sp)
/* 101A80 7F0CCF50 0FC331A4 */  jal   sub_GAME_7F0CC690
/* 101A84 7F0CCF54 00002025 */   move  $a0, $zero
/* 101A88 7F0CCF58 8FA5006C */  lw    $a1, 0x6c($sp)
/* 101A8C 7F0CCF5C 8FA60068 */  lw    $a2, 0x68($sp)
/* 101A90 7F0CCF60 1040000F */  beqz  $v0, .L7F0CCFA0
/* 101A94 7F0CCF64 8FA70064 */   lw    $a3, 0x64($sp)
/* 101A98 7F0CCF68 30AF0FFF */  andi  $t7, $a1, 0xfff
/* 101A9C 7F0CCF6C 000FC300 */  sll   $t8, $t7, 0xc
/* 101AA0 7F0CCF70 02401025 */  move  $v0, $s2
/* 101AA4 7F0CCF74 3C01F200 */  lui   $at, 0xf200
/* 101AA8 7F0CCF78 30EC0FFF */  andi  $t4, $a3, 0xfff
/* 101AAC 7F0CCF7C 000C4300 */  sll   $t0, $t4, 0xc
/* 101AB0 7F0CCF80 03017025 */  or    $t6, $t8, $at
/* 101AB4 7F0CCF84 30C90FFF */  andi  $t1, $a2, 0xfff
/* 101AB8 7F0CCF88 320A0FFF */  andi  $t2, $s0, 0xfff
/* 101ABC 7F0CCF8C 010A6825 */  or    $t5, $t0, $t2
/* 101AC0 7F0CCF90 01C9C825 */  or    $t9, $t6, $t1
/* 101AC4 7F0CCF94 AC590000 */  sw    $t9, ($v0)
/* 101AC8 7F0CCF98 AC4D0004 */  sw    $t5, 4($v0)
/* 101ACC 7F0CCF9C 26520008 */  addiu $s2, $s2, 8
.L7F0CCFA0:
/* 101AD0 7F0CCFA0 8FBF0044 */  lw    $ra, 0x44($sp)
/* 101AD4 7F0CCFA4 02401025 */  move  $v0, $s2
/* 101AD8 7F0CCFA8 8FB20040 */  lw    $s2, 0x40($sp)
/* 101ADC 7F0CCFAC 8FB00038 */  lw    $s0, 0x38($sp)
/* 101AE0 7F0CCFB0 8FB1003C */  lw    $s1, 0x3c($sp)
/* 101AE4 7F0CCFB4 03E00008 */  jr    $ra
/* 101AE8 7F0CCFB8 27BD0090 */   addiu $sp, $sp, 0x90
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0CCFBC(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0CCFBC
/* 101AEC 7F0CCFBC 27BDFFF8 */  addiu $sp, $sp, -8
/* 101AF0 7F0CCFC0 AFB00004 */  sw    $s0, 4($sp)
/* 101AF4 7F0CCFC4 90C2000B */  lbu   $v0, 0xb($a2)
/* 101AF8 7F0CCFC8 00808025 */  move  $s0, $a0
/* 101AFC 7F0CCFCC 00001825 */  move  $v1, $zero
/* 101B00 7F0CCFD0 00027142 */  srl   $t6, $v0, 5
/* 101B04 7F0CCFD4 11C00003 */  beqz  $t6, .L7F0CCFE4
/* 101B08 7F0CCFD8 00000000 */   nop   
/* 101B0C 7F0CCFDC 10000001 */  b     .L7F0CCFE4
/* 101B10 7F0CCFE0 25C3FFFF */   addiu $v1, $t6, -1
.L7F0CCFE4:
/* 101B14 7F0CCFE4 50E0001A */  beql  $a3, $zero, .L7F0CD050
/* 101B18 7F0CCFE8 8CAD0000 */   lw    $t5, ($a1)
/* 101B1C 7F0CCFEC 10A0000D */  beqz  $a1, .L7F0CD024
/* 101B20 7F0CCFF0 02001025 */   move  $v0, $s0
/* 101B24 7F0CCFF4 8CA40000 */  lw    $a0, ($a1)
/* 101B28 7F0CCFF8 2401C7FF */  li    $at, -14337
/* 101B2C 7F0CCFFC 0003C2C0 */  sll   $t8, $v1, 0xb
/* 101B30 7F0CD000 00817824 */  and   $t7, $a0, $at
/* 101B34 7F0CD004 01F81025 */  or    $v0, $t7, $t8
/* 101B38 7F0CD008 50440018 */  beql  $v0, $a0, .L7F0CD06C
/* 101B3C 7F0CD00C 02001025 */   move  $v0, $s0
/* 101B40 7F0CD010 AE020000 */  sw    $v0, ($s0)
/* 101B44 7F0CD014 8CB90004 */  lw    $t9, 4($a1)
/* 101B48 7F0CD018 26100008 */  addiu $s0, $s0, 8
/* 101B4C 7F0CD01C 10000012 */  b     .L7F0CD068
/* 101B50 7F0CD020 AE19FFFC */   sw    $t9, -4($s0)
.L7F0CD024:
/* 101B54 7F0CD024 30680007 */  andi  $t0, $v1, 7
/* 101B58 7F0CD028 00084AC0 */  sll   $t1, $t0, 0xb
/* 101B5C 7F0CD02C 3C01BB00 */  lui   $at, 0xbb00
/* 101B60 7F0CD030 01215025 */  or    $t2, $t1, $at
/* 101B64 7F0CD034 354B0001 */  ori   $t3, $t2, 1
/* 101B68 7F0CD038 240CFFFF */  li    $t4, -1
/* 101B6C 7F0CD03C AC4C0004 */  sw    $t4, 4($v0)
/* 101B70 7F0CD040 AC4B0000 */  sw    $t3, ($v0)
/* 101B74 7F0CD044 10000008 */  b     .L7F0CD068
/* 101B78 7F0CD048 26100008 */   addiu $s0, $s0, 8
/* 101B7C 7F0CD04C 8CAD0000 */  lw    $t5, ($a1)
.L7F0CD050:
/* 101B80 7F0CD050 2401C7FF */  li    $at, -14337
/* 101B84 7F0CD054 0003C2C0 */  sll   $t8, $v1, 0xb
/* 101B88 7F0CD058 01A17024 */  and   $t6, $t5, $at
/* 101B8C 7F0CD05C ACAE0000 */  sw    $t6, ($a1)
/* 101B90 7F0CD060 01D8C825 */  or    $t9, $t6, $t8
/* 101B94 7F0CD064 ACB90000 */  sw    $t9, ($a1)
.L7F0CD068:
/* 101B98 7F0CD068 02001025 */  move  $v0, $s0
.L7F0CD06C:
/* 101B9C 7F0CD06C 8FB00004 */  lw    $s0, 4($sp)
/* 101BA0 7F0CD070 03E00008 */  jr    $ra
/* 101BA4 7F0CD074 27BD0008 */   addiu $sp, $sp, 8
)
#endif





#ifdef NONMATCHING
void expland_c0_DL_psuedocommands(void) {

}
#else
GLOBAL_ASM(
.text
glabel expland_c0_DL_psuedocommands
/* 101BA8 7F0CD078 27BDFF70 */  addiu $sp, $sp, -0x90
/* 101BAC 7F0CD07C AFB00034 */  sw    $s0, 0x34($sp)
/* 101BB0 7F0CD080 00808025 */  move  $s0, $a0
/* 101BB4 7F0CD084 AFB10038 */  sw    $s1, 0x38($sp)
/* 101BB8 7F0CD088 00A08825 */  move  $s1, $a1
/* 101BBC 7F0CD08C AFBF003C */  sw    $ra, 0x3c($sp)
/* 101BC0 7F0CD090 AFA60098 */  sw    $a2, 0x98($sp)
/* 101BC4 7F0CD094 00A02025 */  move  $a0, $a1
/* 101BC8 7F0CD098 27A5008C */  addiu $a1, $sp, 0x8c
/* 101BCC 7F0CD09C 0FC33275 */  jal   sub_GAME_7F0CC9D4
/* 101BD0 7F0CD0A0 27A60088 */   addiu $a2, $sp, 0x88
/* 101BD4 7F0CD0A4 8E2E000C */  lw    $t6, 0xc($s1)
/* 101BD8 7F0CD0A8 24040007 */  li    $a0, 7
/* 101BDC 7F0CD0AC 02001025 */  move  $v0, $s0
/* 101BE0 7F0CD0B0 000E7F82 */  srl   $t7, $t6, 0x1e
/* 101BE4 7F0CD0B4 15E0004E */  bnez  $t7, .L7F0CD1F0
/* 101BE8 7F0CD0B8 3C01FD00 */   lui   $at, 0xfd00
/* 101BEC 7F0CD0BC 8E380008 */  lw    $t8, 8($s1)
/* 101BF0 7F0CD0C0 8FAF008C */  lw    $t7, 0x8c($sp)
/* 101BF4 7F0CD0C4 3C01FD00 */  lui   $at, 0xfd00
/* 101BF8 7F0CD0C8 0018CEC0 */  sll   $t9, $t8, 0x1b
/* 101BFC 7F0CD0CC 00195F42 */  srl   $t3, $t9, 0x1d
/* 101C00 7F0CD0D0 316C0007 */  andi  $t4, $t3, 7
/* 101C04 7F0CD0D4 000C6D40 */  sll   $t5, $t4, 0x15
/* 101C08 7F0CD0D8 31F80003 */  andi  $t8, $t7, 3
/* 101C0C 7F0CD0DC 0018CCC0 */  sll   $t9, $t8, 0x13
/* 101C10 7F0CD0E0 01A17025 */  or    $t6, $t5, $at
/* 101C14 7F0CD0E4 01D95825 */  or    $t3, $t6, $t9
/* 101C18 7F0CD0E8 02001025 */  move  $v0, $s0
/* 101C1C 7F0CD0EC AC4B0000 */  sw    $t3, ($v0)
/* 101C20 7F0CD0F0 8E2C0004 */  lw    $t4, 4($s1)
/* 101C24 7F0CD0F4 26100008 */  addiu $s0, $s0, 8
/* 101C28 7F0CD0F8 00003825 */  move  $a3, $zero
/* 101C2C 7F0CD0FC AC4C0004 */  sw    $t4, 4($v0)
/* 101C30 7F0CD100 8E250008 */  lw    $a1, 8($s1)
/* 101C34 7F0CD104 8FB80098 */  lw    $t8, 0x98($sp)
/* 101C38 7F0CD108 AFA00028 */  sw    $zero, 0x28($sp)
/* 101C3C 7F0CD10C 00056EC0 */  sll   $t5, $a1, 0x1b
/* 101C40 7F0CD110 000D2F42 */  srl   $a1, $t5, 0x1d
/* 101C44 7F0CD114 AFA00024 */  sw    $zero, 0x24($sp)
/* 101C48 7F0CD118 AFA00020 */  sw    $zero, 0x20($sp)
/* 101C4C 7F0CD11C AFA0001C */  sw    $zero, 0x1c($sp)
/* 101C50 7F0CD120 AFA00018 */  sw    $zero, 0x18($sp)
/* 101C54 7F0CD124 AFA00014 */  sw    $zero, 0x14($sp)
/* 101C58 7F0CD128 8FA6008C */  lw    $a2, 0x8c($sp)
/* 101C5C 7F0CD12C 0FC3315D */  jal   sub_GAME_7F0CC574
/* 101C60 7F0CD130 AFB80010 */   sw    $t8, 0x10($sp)
/* 101C64 7F0CD134 10400013 */  beqz  $v0, .L7F0CD184
/* 101C68 7F0CD138 3C0A0700 */   lui   $t2, 0x700
/* 101C6C 7F0CD13C 8E2E0008 */  lw    $t6, 8($s1)
/* 101C70 7F0CD140 8FB8008C */  lw    $t8, 0x8c($sp)
/* 101C74 7F0CD144 3C01F500 */  lui   $at, 0xf500
/* 101C78 7F0CD148 000ECEC0 */  sll   $t9, $t6, 0x1b
/* 101C7C 7F0CD14C 00195F42 */  srl   $t3, $t9, 0x1d
/* 101C80 7F0CD150 316C0007 */  andi  $t4, $t3, 7
/* 101C84 7F0CD154 000C6D40 */  sll   $t5, $t4, 0x15
/* 101C88 7F0CD158 8FAC0098 */  lw    $t4, 0x98($sp)
/* 101C8C 7F0CD15C 01A17825 */  or    $t7, $t5, $at
/* 101C90 7F0CD160 330E0003 */  andi  $t6, $t8, 3
/* 101C94 7F0CD164 000ECCC0 */  sll   $t9, $t6, 0x13
/* 101C98 7F0CD168 02001025 */  move  $v0, $s0
/* 101C9C 7F0CD16C 01F95825 */  or    $t3, $t7, $t9
/* 101CA0 7F0CD170 318D01FF */  andi  $t5, $t4, 0x1ff
/* 101CA4 7F0CD174 016DC025 */  or    $t8, $t3, $t5
/* 101CA8 7F0CD178 AC580000 */  sw    $t8, ($v0)
/* 101CAC 7F0CD17C AC4A0004 */  sw    $t2, 4($v0)
/* 101CB0 7F0CD180 26100008 */  addiu $s0, $s0, 8
.L7F0CD184:  /*LoadTexture(){gDPLoadSync(); gDPLoadBlock();}*/
/* 101CB4 7F0CD184 02001025 */  move  $v0, $s0
/* 101CB8 7F0CD188 26100008 */  addiu $s0, $s0, 8
/* 101CBC 7F0CD18C 3C0EE600 */  lui   $t6, 0xe600
/* 101CC0 7F0CD190 AC4E0000 */  sw    $t6, ($v0)
/* 101CC4 7F0CD194 AC400004 */  sw    $zero, 4($v0)
/* 101CC8 7F0CD198 02002825 */  move  $a1, $s0
/* 101CCC 7F0CD19C 3C0FF300 */  lui   $t7, 0xf300
/* 101CD0 7F0CD1A0 ACAF0000 */  sw    $t7, ($a1)
/* 101CD4 7F0CD1A4 8FA30088 */  lw    $v1, 0x88($sp)
/* 101CD8 7F0CD1A8 26100008 */  addiu $s0, $s0, 8
/* 101CDC 7F0CD1AC 3C0A0700 */  lui   $t2, 0x700
/* 101CE0 7F0CD1B0 2463FFFF */  addiu $v1, $v1, -1
/* 101CE4 7F0CD1B4 286107FF */  slti  $at, $v1, 0x7ff
/* 101CE8 7F0CD1B8 10200003 */  beqz  $at, .L7F0CD1C8
/* 101CEC 7F0CD1BC 02001025 */   move  $v0, $s0
/* 101CF0 7F0CD1C0 10000002 */  b     .L7F0CD1CC
/* 101CF4 7F0CD1C4 00602025 */   move  $a0, $v1
.L7F0CD1C8:
/* 101CF8 7F0CD1C8 240407FF */  li    $a0, 2047
.L7F0CD1CC:
/* 101CFC 7F0CD1CC 30990FFF */  andi  $t9, $a0, 0xfff
/* 101D00 7F0CD1D0 00196300 */  sll   $t4, $t9, 0xc
/* 101D04 7F0CD1D4 018A5825 */  or    $t3, $t4, $t2
/* 101D08 7F0CD1D8 ACAB0004 */  sw    $t3, 4($a1)
/* 101D0C 7F0CD1DC 3C0DE700 */  lui   $t5, 0xe700
/* 101D10 7F0CD1E0 AC4D0000 */  sw    $t5, ($v0)
/* 101D14 7F0CD1E4 AC400004 */  sw    $zero, 4($v0)
/* 101D18 7F0CD1E8 1000008B */  b     .L7F0CD418
/* 101D1C 7F0CD1EC 26100008 */   addiu $s0, $s0, 8
.L7F0CD1F0:
/* 101D20 7F0CD1F0 8E380008 */  lw    $t8, 8($s1)
/* 101D24 7F0CD1F4 8FAD008C */  lw    $t5, 0x8c($sp)
/* 101D28 7F0CD1F8 26100008 */  addiu $s0, $s0, 8
/* 101D2C 7F0CD1FC 001876C0 */  sll   $t6, $t8, 0x1b
/* 101D30 7F0CD200 000E7F42 */  srl   $t7, $t6, 0x1d
/* 101D34 7F0CD204 31F90007 */  andi  $t9, $t7, 7
/* 101D38 7F0CD208 00196540 */  sll   $t4, $t9, 0x15
/* 101D3C 7F0CD20C 31B80003 */  andi  $t8, $t5, 3
/* 101D40 7F0CD210 001874C0 */  sll   $t6, $t8, 0x13
/* 101D44 7F0CD214 01815825 */  or    $t3, $t4, $at
/* 101D48 7F0CD218 016E7825 */  or    $t7, $t3, $t6
/* 101D4C 7F0CD21C AC4F0000 */  sw    $t7, ($v0)
/* 101D50 7F0CD220 8E390004 */  lw    $t9, 4($s1)
/* 101D54 7F0CD224 24040007 */  li    $a0, 7
/* 101D58 7F0CD228 00003825 */  move  $a3, $zero
/* 101D5C 7F0CD22C AC590004 */  sw    $t9, 4($v0)
/* 101D60 7F0CD230 8E250008 */  lw    $a1, 8($s1)
/* 101D64 7F0CD234 8FB80098 */  lw    $t8, 0x98($sp)
/* 101D68 7F0CD238 AFA00028 */  sw    $zero, 0x28($sp)
/* 101D6C 7F0CD23C 000566C0 */  sll   $t4, $a1, 0x1b
/* 101D70 7F0CD240 000C2F42 */  srl   $a1, $t4, 0x1d
/* 101D74 7F0CD244 AFA00024 */  sw    $zero, 0x24($sp)
/* 101D78 7F0CD248 AFA00020 */  sw    $zero, 0x20($sp)
/* 101D7C 7F0CD24C AFA0001C */  sw    $zero, 0x1c($sp)
/* 101D80 7F0CD250 AFA00018 */  sw    $zero, 0x18($sp)
/* 101D84 7F0CD254 AFA00014 */  sw    $zero, 0x14($sp)
/* 101D88 7F0CD258 8FA6008C */  lw    $a2, 0x8c($sp)
/* 101D8C 7F0CD25C 0FC3315D */  jal   sub_GAME_7F0CC574
/* 101D90 7F0CD260 AFB80010 */   sw    $t8, 0x10($sp)
/* 101D94 7F0CD264 10400014 */  beqz  $v0, .L7F0CD2B8
/* 101D98 7F0CD268 00003025 */   move  $a2, $zero
/* 101D9C 7F0CD26C 8E2B0008 */  lw    $t3, 8($s1)
/* 101DA0 7F0CD270 8FB8008C */  lw    $t8, 0x8c($sp)
/* 101DA4 7F0CD274 3C01F500 */  lui   $at, 0xf500
/* 101DA8 7F0CD278 000B76C0 */  sll   $t6, $t3, 0x1b
/* 101DAC 7F0CD27C 000E7F42 */  srl   $t7, $t6, 0x1d
/* 101DB0 7F0CD280 31F90007 */  andi  $t9, $t7, 7
/* 101DB4 7F0CD284 00196540 */  sll   $t4, $t9, 0x15
/* 101DB8 7F0CD288 8FB90098 */  lw    $t9, 0x98($sp)
/* 101DBC 7F0CD28C 01816825 */  or    $t5, $t4, $at
/* 101DC0 7F0CD290 330B0003 */  andi  $t3, $t8, 3
/* 101DC4 7F0CD294 000B74C0 */  sll   $t6, $t3, 0x13
/* 101DC8 7F0CD298 02001025 */  move  $v0, $s0
/* 101DCC 7F0CD29C 01AE7825 */  or    $t7, $t5, $t6
/* 101DD0 7F0CD2A0 332C01FF */  andi  $t4, $t9, 0x1ff
/* 101DD4 7F0CD2A4 3C0A0700 */  lui   $t2, 0x700
/* 101DD8 7F0CD2A8 01ECC025 */  or    $t8, $t7, $t4
/* 101DDC 7F0CD2AC AC580000 */  sw    $t8, ($v0)
/* 101DE0 7F0CD2B0 AC4A0004 */  sw    $t2, 4($v0)
/* 101DE4 7F0CD2B4 26100008 */  addiu $s0, $s0, 8
.L7F0CD2B8:
/* 101DE8 7F0CD2B8 02001025 */  move  $v0, $s0
/* 101DEC 7F0CD2BC 26100008 */  addiu $s0, $s0, 8
/* 101DF0 7F0CD2C0 3C0BE600 */  lui   $t3, 0xe600
/* 101DF4 7F0CD2C4 AC4B0000 */  sw    $t3, ($v0)
/* 101DF8 7F0CD2C8 AC400004 */  sw    $zero, 4($v0)
/* 101DFC 7F0CD2CC 02002825 */  move  $a1, $s0
/* 101E00 7F0CD2D0 3C0DF300 */  lui   $t5, 0xf300
/* 101E04 7F0CD2D4 ACAD0000 */  sw    $t5, ($a1)
/* 101E08 7F0CD2D8 8FA30088 */  lw    $v1, 0x88($sp)
/* 101E0C 7F0CD2DC 26100008 */  addiu $s0, $s0, 8
/* 101E10 7F0CD2E0 3C0A0700 */  lui   $t2, 0x700
/* 101E14 7F0CD2E4 2463FFFF */  addiu $v1, $v1, -1
/* 101E18 7F0CD2E8 286107FF */  slti  $at, $v1, 0x7ff
/* 101E1C 7F0CD2EC 10200003 */  beqz  $at, .L7F0CD2FC
/* 101E20 7F0CD2F0 02001025 */   move  $v0, $s0
/* 101E24 7F0CD2F4 10000002 */  b     .L7F0CD300
/* 101E28 7F0CD2F8 00602025 */   move  $a0, $v1
.L7F0CD2FC:
/* 101E2C 7F0CD2FC 240407FF */  li    $a0, 2047
.L7F0CD300:
/* 101E30 7F0CD300 308E0FFF */  andi  $t6, $a0, 0xfff
/* 101E34 7F0CD304 000ECB00 */  sll   $t9, $t6, 0xc
/* 101E38 7F0CD308 032A7825 */  or    $t7, $t9, $t2
/* 101E3C 7F0CD30C ACAF0004 */  sw    $t7, 4($a1)
/* 101E40 7F0CD310 3C0CE700 */  lui   $t4, 0xe700
/* 101E44 7F0CD314 AC4C0000 */  sw    $t4, ($v0)
/* 101E48 7F0CD318 AC400004 */  sw    $zero, 4($v0)
/* 101E4C 7F0CD31C 9238000A */  lbu   $t8, 0xa($s1)
/* 101E50 7F0CD320 8FA80088 */  lw    $t0, 0x88($sp)
/* 101E54 7F0CD324 240B03FF */  li    $t3, 1023
/* 101E58 7F0CD328 01781823 */  subu  $v1, $t3, $t8
/* 101E5C 7F0CD32C 0068082B */  sltu  $at, $v1, $t0
/* 101E60 7F0CD330 10200003 */  beqz  $at, .L7F0CD340
/* 101E64 7F0CD334 26100008 */   addiu $s0, $s0, 8
/* 101E68 7F0CD338 10000002 */  b     .L7F0CD344
/* 101E6C 7F0CD33C 00604825 */   move  $t1, $v1
.L7F0CD340:
/* 101E70 7F0CD340 00004825 */  move  $t1, $zero
.L7F0CD344:
/* 101E74 7F0CD344 01094023 */  subu  $t0, $t0, $t1
/* 101E78 7F0CD348 240E0100 */  li    $t6, 256
/* 101E7C 7F0CD34C AFAE0010 */  sw    $t6, 0x10($sp)
/* 101E80 7F0CD350 AFA80070 */  sw    $t0, 0x70($sp)
/* 101E84 7F0CD354 24040007 */  li    $a0, 7
/* 101E88 7F0CD358 00002825 */  move  $a1, $zero
/* 101E8C 7F0CD35C 24070001 */  li    $a3, 1
/* 101E90 7F0CD360 AFA00014 */  sw    $zero, 0x14($sp)
/* 101E94 7F0CD364 AFA00018 */  sw    $zero, 0x18($sp)
/* 101E98 7F0CD368 AFA0001C */  sw    $zero, 0x1c($sp)
/* 101E9C 7F0CD36C AFA00020 */  sw    $zero, 0x20($sp)
/* 101EA0 7F0CD370 AFA00024 */  sw    $zero, 0x24($sp)
/* 101EA4 7F0CD374 AFA00028 */  sw    $zero, 0x28($sp)
/* 101EA8 7F0CD378 0FC3315D */  jal   sub_GAME_7F0CC574
/* 101EAC 7F0CD37C AFA9006C */   sw    $t1, 0x6c($sp)
/* 101EB0 7F0CD380 8FA80070 */  lw    $t0, 0x70($sp)
/* 101EB4 7F0CD384 8FA9006C */  lw    $t1, 0x6c($sp)
/* 101EB8 7F0CD388 10400007 */  beqz  $v0, .L7F0CD3A8
/* 101EBC 7F0CD38C 3C0A0700 */   lui   $t2, 0x700
/* 101EC0 7F0CD390 02001025 */  move  $v0, $s0
/* 101EC4 7F0CD394 3C19F500 */  lui   $t9, (0xF5000300 >> 16) # lui $t9, 0xf500
/* 101EC8 7F0CD398 37390300 */  ori   $t9, (0xF5000300 & 0xFFFF) # ori $t9, $t9, 0x300
/* 101ECC 7F0CD39C AC590000 */  sw    $t9, ($v0)
/* 101ED0 7F0CD3A0 AC4A0004 */  sw    $t2, 4($v0)
/* 101ED4 7F0CD3A4 26100008 */  addiu $s0, $s0, 8
.L7F0CD3A8:
/* 101ED8 7F0CD3A8 02001025 */  move  $v0, $s0
/* 101EDC 7F0CD3AC 310B03FF */  andi  $t3, $t0, 0x3ff
/* 101EE0 7F0CD3B0 000BC380 */  sll   $t8, $t3, 0xe
/* 101EE4 7F0CD3B4 312403FF */  andi  $a0, $t1, 0x3ff
/* 101EE8 7F0CD3B8 3C01F000 */  lui   $at, 0xf000
/* 101EEC 7F0CD3BC 26100008 */  addiu $s0, $s0, 8
/* 101EF0 7F0CD3C0 3C0FE600 */  lui   $t7, 0xe600
/* 101EF4 7F0CD3C4 03016825 */  or    $t5, $t8, $at
/* 101EF8 7F0CD3C8 00046080 */  sll   $t4, $a0, 2
/* 101EFC 7F0CD3CC AC4F0000 */  sw    $t7, ($v0)
/* 101F00 7F0CD3D0 AC400004 */  sw    $zero, 4($v0)
/* 101F04 7F0CD3D4 01AC7025 */  or    $t6, $t5, $t4
/* 101F08 7F0CD3D8 02001825 */  move  $v1, $s0
/* 101F0C 7F0CD3DC AC6E0000 */  sw    $t6, ($v1)
/* 101F10 7F0CD3E0 9239000A */  lbu   $t9, 0xa($s1)
/* 101F14 7F0CD3E4 01802025 */  move  $a0, $t4
/* 101F18 7F0CD3E8 26100008 */  addiu $s0, $s0, 8
/* 101F1C 7F0CD3EC 03287821 */  addu  $t7, $t9, $t0
/* 101F20 7F0CD3F0 31EC03FF */  andi  $t4, $t7, 0x3ff
/* 101F24 7F0CD3F4 000C5B80 */  sll   $t3, $t4, 0xe
/* 101F28 7F0CD3F8 016AC025 */  or    $t8, $t3, $t2
/* 101F2C 7F0CD3FC 03046825 */  or    $t5, $t8, $a0
/* 101F30 7F0CD400 02002825 */  move  $a1, $s0
/* 101F34 7F0CD404 AC6D0004 */  sw    $t5, 4($v1)
/* 101F38 7F0CD408 3C0EE700 */  lui   $t6, 0xe700
/* 101F3C 7F0CD40C ACAE0000 */  sw    $t6, ($a1)
/* 101F40 7F0CD410 ACA00004 */  sw    $zero, 4($a1)
/* 101F44 7F0CD414 26100008 */  addiu $s0, $s0, 8
.L7F0CD418:
/* 101F48 7F0CD418 8FBF003C */  lw    $ra, 0x3c($sp)
/* 101F4C 7F0CD41C 02001025 */  move  $v0, $s0
/* 101F50 7F0CD420 8FB00034 */  lw    $s0, 0x34($sp)
/* 101F54 7F0CD424 8FB10038 */  lw    $s1, 0x38($sp)
/* 101F58 7F0CD428 03E00008 */  jr    $ra
/* 101F5C 7F0CD42C 27BD0090 */   addiu $sp, $sp, 0x90
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0CD430(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0CD430
/* 101F60 7F0CD430 27BDFF48 */  addiu $sp, $sp, -0xb8
/* 101F64 7F0CD434 8FAE00D0 */  lw    $t6, 0xd0($sp)
/* 101F68 7F0CD438 AFBF005C */  sw    $ra, 0x5c($sp)
/* 101F6C 7F0CD43C AFBE0058 */  sw    $fp, 0x58($sp)
/* 101F70 7F0CD440 AFB70054 */  sw    $s7, 0x54($sp)
/* 101F74 7F0CD444 AFB60050 */  sw    $s6, 0x50($sp)
/* 101F78 7F0CD448 AFB5004C */  sw    $s5, 0x4c($sp)
/* 101F7C 7F0CD44C AFB40048 */  sw    $s4, 0x48($sp)
/* 101F80 7F0CD450 AFB30044 */  sw    $s3, 0x44($sp)
/* 101F84 7F0CD454 AFB20040 */  sw    $s2, 0x40($sp)
/* 101F88 7F0CD458 AFB1003C */  sw    $s1, 0x3c($sp)
/* 101F8C 7F0CD45C AFB00038 */  sw    $s0, 0x38($sp)
/* 101F90 7F0CD460 AFA600C0 */  sw    $a2, 0xc0($sp)
/* 101F94 7F0CD464 AFA700C4 */  sw    $a3, 0xc4($sp)
/* 101F98 7F0CD468 AFAE00B4 */  sw    $t6, 0xb4($sp)
/* 101F9C 7F0CD46C 90A2000B */  lbu   $v0, 0xb($a1)
/* 101FA0 7F0CD470 8FB000CC */  lw    $s0, 0xcc($sp)
/* 101FA4 7F0CD474 00A0A825 */  move  $s5, $a1
/* 101FA8 7F0CD478 00027942 */  srl   $t7, $v0, 5
/* 101FAC 7F0CD47C 01F04021 */  addu  $t0, $t7, $s0
/* 101FB0 7F0CD480 0208082A */  slt   $at, $s0, $t0
/* 101FB4 7F0CD484 102000BC */  beqz  $at, .L7F0CD778
/* 101FB8 7F0CD488 0080B025 */   move  $s6, $a0
/* 101FBC 7F0CD48C 02109023 */  subu  $s2, $s0, $s0
/* 101FC0 7F0CD490 AFB000AC */  sw    $s0, 0xac($sp)
/* 101FC4 7F0CD494 AFA80064 */  sw    $t0, 0x64($sp)
.L7F0CD498:
/* 101FC8 7F0CD498 02A02025 */  move  $a0, $s5
/* 101FCC 7F0CD49C 0FC331C5 */  jal   sub_GAME_7F0CC714
/* 101FD0 7F0CD4A0 02402825 */   move  $a1, $s2
/* 101FD4 7F0CD4A4 0FC332A7 */  jal   sub_GAME_7F0CCA9C
/* 101FD8 7F0CD4A8 00402025 */   move  $a0, $v0
/* 101FDC 7F0CD4AC 00409825 */  move  $s3, $v0
/* 101FE0 7F0CD4B0 02A02025 */  move  $a0, $s5
/* 101FE4 7F0CD4B4 0FC331FF */  jal   sub_GAME_7F0CC7FC
/* 101FE8 7F0CD4B8 02402825 */   move  $a1, $s2
/* 101FEC 7F0CD4BC 0FC332A7 */  jal   sub_GAME_7F0CCA9C
/* 101FF0 7F0CD4C0 00402025 */   move  $a0, $v0
/* 101FF4 7F0CD4C4 0040A025 */  move  $s4, $v0
/* 101FF8 7F0CD4C8 02A02025 */  move  $a0, $s5
/* 101FFC 7F0CD4CC 0FC33239 */  jal   sub_GAME_7F0CC8E4
/* 102000 7F0CD4D0 02402825 */   move  $a1, $s2
/* 102004 7F0CD4D4 00408025 */  move  $s0, $v0
/* 102008 7F0CD4D8 02A02025 */  move  $a0, $s5
/* 10200C 7F0CD4DC 0FC33265 */  jal   sub_GAME_7F0CC994
/* 102010 7F0CD4E0 02402825 */   move  $a1, $s2
/* 102014 7F0CD4E4 AFA20080 */  sw    $v0, 0x80($sp)
/* 102018 7F0CD4E8 8EA3000C */  lw    $v1, 0xc($s5)
/* 10201C 7F0CD4EC 0003F080 */  sll   $fp, $v1, 2
/* 102020 7F0CD4F0 00032782 */  srl   $a0, $v1, 0x1e
/* 102024 7F0CD4F4 001EC7C2 */  srl   $t8, $fp, 0x1f
/* 102028 7F0CD4F8 0004CB80 */  sll   $t9, $a0, 0xe
/* 10202C 7F0CD4FC 0300F025 */  move  $fp, $t8
/* 102030 7F0CD500 0FC33152 */  jal   sub_GAME_7F0CC548
/* 102034 7F0CD504 03202025 */   move  $a0, $t9
/* 102038 7F0CD508 1040000A */  beqz  $v0, .L7F0CD534
/* 10203C 7F0CD50C 02003825 */   move  $a3, $s0
/* 102040 7F0CD510 3C09BA00 */  lui   $t1, (0xBA000E02 >> 16) # lui $t1, 0xba00
/* 102044 7F0CD514 35290E02 */  ori   $t1, (0xBA000E02 & 0xFFFF) # ori $t1, $t1, 0xe02
/* 102048 7F0CD518 02C01025 */  move  $v0, $s6
/* 10204C 7F0CD51C AC490000 */  sw    $t1, ($v0)
/* 102050 7F0CD520 8EAA000C */  lw    $t2, 0xc($s5)
/* 102054 7F0CD524 26D60008 */  addiu $s6, $s6, 8
/* 102058 7F0CD528 000A5F82 */  srl   $t3, $t2, 0x1e
/* 10205C 7F0CD52C 000B6380 */  sll   $t4, $t3, 0xe
/* 102060 7F0CD530 AC4C0004 */  sw    $t4, 4($v0)
.L7F0CD534:
/* 102064 7F0CD534 8EA20008 */  lw    $v0, 8($s5)
/* 102068 7F0CD538 8FAE00B4 */  lw    $t6, 0xb4($sp)
/* 10206C 7F0CD53C 8FAF00C0 */  lw    $t7, 0xc0($sp)
/* 102070 7F0CD540 8FB800C4 */  lw    $t8, 0xc4($sp)
/* 102074 7F0CD544 00022EC0 */  sll   $a1, $v0, 0x1b
/* 102078 7F0CD548 00056F42 */  srl   $t5, $a1, 0x1d
/* 10207C 7F0CD54C 01A02825 */  move  $a1, $t5
/* 102080 7F0CD550 AFB20028 */  sw    $s2, 0x28($sp)
/* 102084 7F0CD554 AFB20024 */  sw    $s2, 0x24($sp)
/* 102088 7F0CD558 AFB40020 */  sw    $s4, 0x20($sp)
/* 10208C 7F0CD55C AFB3001C */  sw    $s3, 0x1c($sp)
/* 102090 7F0CD560 8FA400AC */  lw    $a0, 0xac($sp)
/* 102094 7F0CD564 30460003 */  andi  $a2, $v0, 3
/* 102098 7F0CD568 AFAE0010 */  sw    $t6, 0x10($sp)
/* 10209C 7F0CD56C AFAF0014 */  sw    $t7, 0x14($sp)
/* 1020A0 7F0CD570 0FC3315D */  jal   sub_GAME_7F0CC574
/* 1020A4 7F0CD574 AFB80018 */   sw    $t8, 0x18($sp)
/* 1020A8 7F0CD578 1040002D */  beqz  $v0, .L7F0CD630
/* 1020AC 7F0CD57C 02C08825 */   move  $s1, $s6
/* 1020B0 7F0CD580 8EAD0008 */  lw    $t5, 8($s5)
/* 1020B4 7F0CD584 3C01F500 */  lui   $at, 0xf500
/* 1020B8 7F0CD588 26D60008 */  addiu $s6, $s6, 8
/* 1020BC 7F0CD58C 000DCEC0 */  sll   $t9, $t5, 0x1b
/* 1020C0 7F0CD590 00194F42 */  srl   $t1, $t9, 0x1d
/* 1020C4 7F0CD594 312A0007 */  andi  $t2, $t1, 7
/* 1020C8 7F0CD598 000A5D40 */  sll   $t3, $t2, 0x15
/* 1020CC 7F0CD59C 01616025 */  or    $t4, $t3, $at
/* 1020D0 7F0CD5A0 8FAB00B4 */  lw    $t3, 0xb4($sp)
/* 1020D4 7F0CD5A4 31AE0003 */  andi  $t6, $t5, 3
/* 1020D8 7F0CD5A8 000E7CC0 */  sll   $t7, $t6, 0x13
/* 1020DC 7F0CD5AC 321901FF */  andi  $t9, $s0, 0x1ff
/* 1020E0 7F0CD5B0 00194A40 */  sll   $t1, $t9, 9
/* 1020E4 7F0CD5B4 018FC025 */  or    $t8, $t4, $t7
/* 1020E8 7F0CD5B8 03095025 */  or    $t2, $t8, $t1
/* 1020EC 7F0CD5BC 316D01FF */  andi  $t5, $t3, 0x1ff
/* 1020F0 7F0CD5C0 014D7025 */  or    $t6, $t2, $t5
/* 1020F4 7F0CD5C4 AE2E0000 */  sw    $t6, ($s1)
/* 1020F8 7F0CD5C8 0FC332B3 */  jal   sub_GAME_7F0CCACC
/* 1020FC 7F0CD5CC 8FA400C4 */   lw    $a0, 0xc4($sp)
/* 102100 7F0CD5D0 00408025 */  move  $s0, $v0
/* 102104 7F0CD5D4 0FC332B3 */  jal   sub_GAME_7F0CCACC
/* 102108 7F0CD5D8 8FA400C0 */   lw    $a0, 0xc0($sp)
/* 10210C 7F0CD5DC 8FB900AC */  lw    $t9, 0xac($sp)
/* 102110 7F0CD5E0 304C0003 */  andi  $t4, $v0, 3
/* 102114 7F0CD5E4 000C7A00 */  sll   $t7, $t4, 8
/* 102118 7F0CD5E8 33380007 */  andi  $t8, $t9, 7
/* 10211C 7F0CD5EC 00184E00 */  sll   $t1, $t8, 0x18
/* 102120 7F0CD5F0 01E95825 */  or    $t3, $t7, $t1
/* 102124 7F0CD5F4 320A0003 */  andi  $t2, $s0, 3
/* 102128 7F0CD5F8 000A6C80 */  sll   $t5, $t2, 0x12
/* 10212C 7F0CD5FC 016D7025 */  or    $t6, $t3, $t5
/* 102130 7F0CD600 328C000F */  andi  $t4, $s4, 0xf
/* 102134 7F0CD604 000CCB80 */  sll   $t9, $t4, 0xe
/* 102138 7F0CD608 324F000F */  andi  $t7, $s2, 0xf
/* 10213C 7F0CD60C 000F4A80 */  sll   $t1, $t7, 0xa
/* 102140 7F0CD610 01D9C025 */  or    $t8, $t6, $t9
/* 102144 7F0CD614 326B000F */  andi  $t3, $s3, 0xf
/* 102148 7F0CD618 000B6900 */  sll   $t5, $t3, 4
/* 10214C 7F0CD61C 03095025 */  or    $t2, $t8, $t1
/* 102150 7F0CD620 014D6025 */  or    $t4, $t2, $t5
/* 102154 7F0CD624 324E000F */  andi  $t6, $s2, 0xf
/* 102158 7F0CD628 018EC825 */  or    $t9, $t4, $t6
/* 10215C 7F0CD62C AE390004 */  sw    $t9, 4($s1)
.L7F0CD630:
/* 102160 7F0CD630 8FA200C8 */  lw    $v0, 0xc8($sp)
/* 102164 7F0CD634 24030002 */  li    $v1, 2
/* 102168 7F0CD638 02A02025 */  move  $a0, $s5
/* 10216C 7F0CD63C 14430005 */  bne   $v0, $v1, .L7F0CD654
/* 102170 7F0CD640 02402825 */   move  $a1, $s2
/* 102174 7F0CD644 57C00004 */  bnezl $fp, .L7F0CD658
/* 102178 7F0CD648 00008025 */   move  $s0, $zero
/* 10217C 7F0CD64C 10000002 */  b     .L7F0CD658
/* 102180 7F0CD650 00608025 */   move  $s0, $v1
.L7F0CD654:
/* 102184 7F0CD654 00008025 */  move  $s0, $zero
.L7F0CD658:
/* 102188 7F0CD658 14430005 */  bne   $v0, $v1, .L7F0CD670
/* 10218C 7F0CD65C AFB00090 */   sw    $s0, 0x90($sp)
/* 102190 7F0CD660 57C00004 */  bnezl $fp, .L7F0CD674
/* 102194 7F0CD664 00008025 */   move  $s0, $zero
/* 102198 7F0CD668 10000002 */  b     .L7F0CD674
/* 10219C 7F0CD66C 00608025 */   move  $s0, $v1
.L7F0CD670:
/* 1021A0 7F0CD670 00008025 */  move  $s0, $zero
.L7F0CD674:
/* 1021A4 7F0CD674 0FC331C5 */  jal   sub_GAME_7F0CC714
/* 1021A8 7F0CD678 0200B825 */   move  $s7, $s0
/* 1021AC 7F0CD67C 8FAF00C8 */  lw    $t7, 0xc8($sp)
/* 1021B0 7F0CD680 00409825 */  move  $s3, $v0
/* 1021B4 7F0CD684 24010002 */  li    $at, 2
/* 1021B8 7F0CD688 15E10005 */  bne   $t7, $at, .L7F0CD6A0
/* 1021BC 7F0CD68C 2678FFFF */   addiu $t8, $s3, -1
/* 1021C0 7F0CD690 57C00004 */  bnezl $fp, .L7F0CD6A4
/* 1021C4 7F0CD694 00008025 */   move  $s0, $zero
/* 1021C8 7F0CD698 10000002 */  b     .L7F0CD6A4
/* 1021CC 7F0CD69C 24100002 */   li    $s0, 2
.L7F0CD6A0:
/* 1021D0 7F0CD6A0 00008025 */  move  $s0, $zero
.L7F0CD6A4:
/* 1021D4 7F0CD6A4 00184880 */  sll   $t1, $t8, 2
/* 1021D8 7F0CD6A8 0209A021 */  addu  $s4, $s0, $t1
/* 1021DC 7F0CD6AC 02A02025 */  move  $a0, $s5
/* 1021E0 7F0CD6B0 0FC331FF */  jal   sub_GAME_7F0CC7FC
/* 1021E4 7F0CD6B4 02402825 */   move  $a1, $s2
/* 1021E8 7F0CD6B8 8FAB00C8 */  lw    $t3, 0xc8($sp)
/* 1021EC 7F0CD6BC 24010002 */  li    $at, 2
/* 1021F0 7F0CD6C0 00409825 */  move  $s3, $v0
/* 1021F4 7F0CD6C4 15610005 */  bne   $t3, $at, .L7F0CD6DC
/* 1021F8 7F0CD6C8 8FA400AC */   lw    $a0, 0xac($sp)
/* 1021FC 7F0CD6CC 57C00004 */  bnezl $fp, .L7F0CD6E0
/* 102200 7F0CD6D0 00008025 */   move  $s0, $zero
/* 102204 7F0CD6D4 10000002 */  b     .L7F0CD6E0
/* 102208 7F0CD6D8 24100002 */   li    $s0, 2
.L7F0CD6DC:
/* 10220C 7F0CD6DC 00008025 */  move  $s0, $zero
.L7F0CD6E0:
/* 102210 7F0CD6E0 266AFFFF */  addiu $t2, $s3, -1
/* 102214 7F0CD6E4 000A6880 */  sll   $t5, $t2, 2
/* 102218 7F0CD6E8 020D8821 */  addu  $s1, $s0, $t5
/* 10221C 7F0CD6EC AFB10010 */  sw    $s1, 0x10($sp)
/* 102220 7F0CD6F0 8FA50090 */  lw    $a1, 0x90($sp)
/* 102224 7F0CD6F4 02E03025 */  move  $a2, $s7
/* 102228 7F0CD6F8 0FC331A4 */  jal   sub_GAME_7F0CC690
/* 10222C 7F0CD6FC 02803825 */   move  $a3, $s4
/* 102230 7F0CD700 10400014 */  beqz  $v0, .L7F0CD754
/* 102234 7F0CD704 26520001 */   addiu $s2, $s2, 1
/* 102238 7F0CD708 8FAC0090 */  lw    $t4, 0x90($sp)
/* 10223C 7F0CD70C 3C01F200 */  lui   $at, 0xf200
/* 102240 7F0CD710 32F80FFF */  andi  $t8, $s7, 0xfff
/* 102244 7F0CD714 318E0FFF */  andi  $t6, $t4, 0xfff
/* 102248 7F0CD718 000ECB00 */  sll   $t9, $t6, 0xc
/* 10224C 7F0CD71C 03217825 */  or    $t7, $t9, $at
/* 102250 7F0CD720 01F84825 */  or    $t1, $t7, $t8
/* 102254 7F0CD724 02C01025 */  move  $v0, $s6
/* 102258 7F0CD728 AC490000 */  sw    $t1, ($v0)
/* 10225C 7F0CD72C 8FAB00AC */  lw    $t3, 0xac($sp)
/* 102260 7F0CD730 328C0FFF */  andi  $t4, $s4, 0xfff
/* 102264 7F0CD734 000C7300 */  sll   $t6, $t4, 0xc
/* 102268 7F0CD738 316A0007 */  andi  $t2, $t3, 7
/* 10226C 7F0CD73C 000A6E00 */  sll   $t5, $t2, 0x18
/* 102270 7F0CD740 01AEC825 */  or    $t9, $t5, $t6
/* 102274 7F0CD744 322F0FFF */  andi  $t7, $s1, 0xfff
/* 102278 7F0CD748 032FC025 */  or    $t8, $t9, $t7
/* 10227C 7F0CD74C AC580004 */  sw    $t8, 4($v0)
/* 102280 7F0CD750 26D60008 */  addiu $s6, $s6, 8
.L7F0CD754:
/* 102284 7F0CD754 8FAC00AC */  lw    $t4, 0xac($sp)
/* 102288 7F0CD758 8FA900B4 */  lw    $t1, 0xb4($sp)
/* 10228C 7F0CD75C 8FAB0080 */  lw    $t3, 0x80($sp)
/* 102290 7F0CD760 8FAE0064 */  lw    $t6, 0x64($sp)
/* 102294 7F0CD764 258D0001 */  addiu $t5, $t4, 1
/* 102298 7F0CD768 012B5021 */  addu  $t2, $t1, $t3
/* 10229C 7F0CD76C AFAD00AC */  sw    $t5, 0xac($sp)
/* 1022A0 7F0CD770 15AEFF49 */  bne   $t5, $t6, .L7F0CD498
/* 1022A4 7F0CD774 AFAA00B4 */   sw    $t2, 0xb4($sp)
.L7F0CD778:
/* 1022A8 7F0CD778 8FBF005C */  lw    $ra, 0x5c($sp)
/* 1022AC 7F0CD77C 02C01025 */  move  $v0, $s6
/* 1022B0 7F0CD780 8FB60050 */  lw    $s6, 0x50($sp)
/* 1022B4 7F0CD784 8FB00038 */  lw    $s0, 0x38($sp)
/* 1022B8 7F0CD788 8FB1003C */  lw    $s1, 0x3c($sp)
/* 1022BC 7F0CD78C 8FB20040 */  lw    $s2, 0x40($sp)
/* 1022C0 7F0CD790 8FB30044 */  lw    $s3, 0x44($sp)
/* 1022C4 7F0CD794 8FB40048 */  lw    $s4, 0x48($sp)
/* 1022C8 7F0CD798 8FB5004C */  lw    $s5, 0x4c($sp)
/* 1022CC 7F0CD79C 8FB70054 */  lw    $s7, 0x54($sp)
/* 1022D0 7F0CD7A0 8FBE0058 */  lw    $fp, 0x58($sp)
/* 1022D4 7F0CD7A4 03E00008 */  jr    $ra
/* 1022D8 7F0CD7A8 27BD00B8 */   addiu $sp, $sp, 0xb8
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0CD7AC(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0CD7AC
/* 1022DC 7F0CD7AC 27BDFF68 */  addiu $sp, $sp, -0x98
/* 1022E0 7F0CD7B0 AFB00034 */  sw    $s0, 0x34($sp)
/* 1022E4 7F0CD7B4 00808025 */  move  $s0, $a0
/* 1022E8 7F0CD7B8 AFBF003C */  sw    $ra, 0x3c($sp)
/* 1022EC 7F0CD7BC AFB10038 */  sw    $s1, 0x38($sp)
/* 1022F0 7F0CD7C0 00A08825 */  move  $s1, $a1
/* 1022F4 7F0CD7C4 0FC332CE */  jal   sub_GAME_7F0CCB38
/* 1022F8 7F0CD7C8 00A02025 */   move  $a0, $a1
/* 1022FC 7F0CD7CC AFA2008C */  sw    $v0, 0x8c($sp)
/* 102300 7F0CD7D0 02202025 */  move  $a0, $s1
/* 102304 7F0CD7D4 27A50094 */  addiu $a1, $sp, 0x94
/* 102308 7F0CD7D8 0FC33275 */  jal   sub_GAME_7F0CC9D4
/* 10230C 7F0CD7DC 27A60090 */   addiu $a2, $sp, 0x90
/* 102310 7F0CD7E0 8E2E000C */  lw    $t6, 0xc($s1)
/* 102314 7F0CD7E4 24040007 */  li    $a0, 7
/* 102318 7F0CD7E8 02001025 */  move  $v0, $s0
/* 10231C 7F0CD7EC 000E7F82 */  srl   $t7, $t6, 0x1e
/* 102320 7F0CD7F0 15E0004D */  bnez  $t7, .L7F0CD928
/* 102324 7F0CD7F4 3C01FD00 */   lui   $at, 0xfd00
/* 102328 7F0CD7F8 8E380008 */  lw    $t8, 8($s1)
/* 10232C 7F0CD7FC 8FAF0094 */  lw    $t7, 0x94($sp)
/* 102330 7F0CD800 3C01FD00 */  lui   $at, 0xfd00
/* 102334 7F0CD804 0018CEC0 */  sll   $t9, $t8, 0x1b
/* 102338 7F0CD808 00195F42 */  srl   $t3, $t9, 0x1d
/* 10233C 7F0CD80C 316C0007 */  andi  $t4, $t3, 7
/* 102340 7F0CD810 000C6D40 */  sll   $t5, $t4, 0x15
/* 102344 7F0CD814 31F80003 */  andi  $t8, $t7, 3
/* 102348 7F0CD818 0018CCC0 */  sll   $t9, $t8, 0x13
/* 10234C 7F0CD81C 01A17025 */  or    $t6, $t5, $at
/* 102350 7F0CD820 01D95825 */  or    $t3, $t6, $t9
/* 102354 7F0CD824 02001025 */  move  $v0, $s0
/* 102358 7F0CD828 AC4B0000 */  sw    $t3, ($v0)
/* 10235C 7F0CD82C 8E2C0004 */  lw    $t4, 4($s1)
/* 102360 7F0CD830 26100008 */  addiu $s0, $s0, 8
/* 102364 7F0CD834 00003825 */  move  $a3, $zero
/* 102368 7F0CD838 AC4C0004 */  sw    $t4, 4($v0)
/* 10236C 7F0CD83C 8E250008 */  lw    $a1, 8($s1)
/* 102370 7F0CD840 AFA00028 */  sw    $zero, 0x28($sp)
/* 102374 7F0CD844 AFA00024 */  sw    $zero, 0x24($sp)
/* 102378 7F0CD848 00056EC0 */  sll   $t5, $a1, 0x1b
/* 10237C 7F0CD84C 000D2F42 */  srl   $a1, $t5, 0x1d
/* 102380 7F0CD850 AFA00020 */  sw    $zero, 0x20($sp)
/* 102384 7F0CD854 AFA0001C */  sw    $zero, 0x1c($sp)
/* 102388 7F0CD858 AFA00018 */  sw    $zero, 0x18($sp)
/* 10238C 7F0CD85C AFA00014 */  sw    $zero, 0x14($sp)
/* 102390 7F0CD860 AFA00010 */  sw    $zero, 0x10($sp)
/* 102394 7F0CD864 0FC3315D */  jal   sub_GAME_7F0CC574
/* 102398 7F0CD868 8FA60094 */   lw    $a2, 0x94($sp)
/* 10239C 7F0CD86C 10400010 */  beqz  $v0, .L7F0CD8B0
/* 1023A0 7F0CD870 3C0A0700 */   lui   $t2, 0x700
/* 1023A4 7F0CD874 8E380008 */  lw    $t8, 8($s1)
/* 1023A8 7F0CD878 8FAF0094 */  lw    $t7, 0x94($sp)
/* 1023AC 7F0CD87C 02001025 */  move  $v0, $s0
/* 1023B0 7F0CD880 001876C0 */  sll   $t6, $t8, 0x1b
/* 1023B4 7F0CD884 000ECF42 */  srl   $t9, $t6, 0x1d
/* 1023B8 7F0CD888 332B0007 */  andi  $t3, $t9, 7
/* 1023BC 7F0CD88C 000B6540 */  sll   $t4, $t3, 0x15
/* 1023C0 7F0CD890 3C01F500 */  lui   $at, 0xf500
/* 1023C4 7F0CD894 31F80003 */  andi  $t8, $t7, 3
/* 1023C8 7F0CD898 001874C0 */  sll   $t6, $t8, 0x13
/* 1023CC 7F0CD89C 01816825 */  or    $t5, $t4, $at
/* 1023D0 7F0CD8A0 01AEC825 */  or    $t9, $t5, $t6
/* 1023D4 7F0CD8A4 AC590000 */  sw    $t9, ($v0)
/* 1023D8 7F0CD8A8 AC4A0004 */  sw    $t2, 4($v0)
/* 1023DC 7F0CD8AC 26100008 */  addiu $s0, $s0, 8
.L7F0CD8B0:
/* 1023E0 7F0CD8B0 02001025 */  move  $v0, $s0
/* 1023E4 7F0CD8B4 26100008 */  addiu $s0, $s0, 8
/* 1023E8 7F0CD8B8 3C0BE600 */  lui   $t3, 0xe600
/* 1023EC 7F0CD8BC AC4B0000 */  sw    $t3, ($v0)
/* 1023F0 7F0CD8C0 AC400004 */  sw    $zero, 4($v0)
/* 1023F4 7F0CD8C4 02002825 */  move  $a1, $s0
/* 1023F8 7F0CD8C8 3C0CF300 */  lui   $t4, 0xf300
/* 1023FC 7F0CD8CC ACAC0000 */  sw    $t4, ($a1)
/* 102400 7F0CD8D0 8FA30090 */  lw    $v1, 0x90($sp)
/* 102404 7F0CD8D4 3C0A0700 */  lui   $t2, 0x700
/* 102408 7F0CD8D8 8FAE008C */  lw    $t6, 0x8c($sp)
/* 10240C 7F0CD8DC 2463FFFF */  addiu $v1, $v1, -1
/* 102410 7F0CD8E0 286107FF */  slti  $at, $v1, 0x7ff
/* 102414 7F0CD8E4 10200003 */  beqz  $at, .L7F0CD8F4
/* 102418 7F0CD8E8 26100008 */   addiu $s0, $s0, 8
/* 10241C 7F0CD8EC 10000002 */  b     .L7F0CD8F8
/* 102420 7F0CD8F0 00602025 */   move  $a0, $v1
.L7F0CD8F4:
/* 102424 7F0CD8F4 240407FF */  li    $a0, 2047
.L7F0CD8F8:
/* 102428 7F0CD8F8 308F0FFF */  andi  $t7, $a0, 0xfff
/* 10242C 7F0CD8FC 000FC300 */  sll   $t8, $t7, 0xc
/* 102430 7F0CD900 030A6825 */  or    $t5, $t8, $t2
/* 102434 7F0CD904 31D90FFF */  andi  $t9, $t6, 0xfff
/* 102438 7F0CD908 01B95825 */  or    $t3, $t5, $t9
/* 10243C 7F0CD90C 02001025 */  move  $v0, $s0
/* 102440 7F0CD910 ACAB0004 */  sw    $t3, 4($a1)
/* 102444 7F0CD914 3C0CE700 */  lui   $t4, 0xe700
/* 102448 7F0CD918 AC4C0000 */  sw    $t4, ($v0)
/* 10244C 7F0CD91C AC400004 */  sw    $zero, 4($v0)
/* 102450 7F0CD920 1000008A */  b     .L7F0CDB4C
/* 102454 7F0CD924 26100008 */   addiu $s0, $s0, 8
.L7F0CD928:
/* 102458 7F0CD928 8E2F0008 */  lw    $t7, 8($s1)
/* 10245C 7F0CD92C 8FAC0094 */  lw    $t4, 0x94($sp)
/* 102460 7F0CD930 26100008 */  addiu $s0, $s0, 8
/* 102464 7F0CD934 000FC6C0 */  sll   $t8, $t7, 0x1b
/* 102468 7F0CD938 00187742 */  srl   $t6, $t8, 0x1d
/* 10246C 7F0CD93C 31CD0007 */  andi  $t5, $t6, 7
/* 102470 7F0CD940 000DCD40 */  sll   $t9, $t5, 0x15
/* 102474 7F0CD944 318F0003 */  andi  $t7, $t4, 3
/* 102478 7F0CD948 000FC4C0 */  sll   $t8, $t7, 0x13
/* 10247C 7F0CD94C 03215825 */  or    $t3, $t9, $at
/* 102480 7F0CD950 01787025 */  or    $t6, $t3, $t8
/* 102484 7F0CD954 AC4E0000 */  sw    $t6, ($v0)
/* 102488 7F0CD958 8E2D0004 */  lw    $t5, 4($s1)
/* 10248C 7F0CD95C 24040007 */  li    $a0, 7
/* 102490 7F0CD960 00003825 */  move  $a3, $zero
/* 102494 7F0CD964 AC4D0004 */  sw    $t5, 4($v0)
/* 102498 7F0CD968 8E250008 */  lw    $a1, 8($s1)
/* 10249C 7F0CD96C AFA00028 */  sw    $zero, 0x28($sp)
/* 1024A0 7F0CD970 AFA00024 */  sw    $zero, 0x24($sp)
/* 1024A4 7F0CD974 0005CEC0 */  sll   $t9, $a1, 0x1b
/* 1024A8 7F0CD978 00192F42 */  srl   $a1, $t9, 0x1d
/* 1024AC 7F0CD97C AFA00020 */  sw    $zero, 0x20($sp)
/* 1024B0 7F0CD980 AFA0001C */  sw    $zero, 0x1c($sp)
/* 1024B4 7F0CD984 AFA00018 */  sw    $zero, 0x18($sp)
/* 1024B8 7F0CD988 AFA00014 */  sw    $zero, 0x14($sp)
/* 1024BC 7F0CD98C AFA00010 */  sw    $zero, 0x10($sp)
/* 1024C0 7F0CD990 0FC3315D */  jal   sub_GAME_7F0CC574
/* 1024C4 7F0CD994 8FA60094 */   lw    $a2, 0x94($sp)
/* 1024C8 7F0CD998 10400011 */  beqz  $v0, .L7F0CD9E0
/* 1024CC 7F0CD99C 00003025 */   move  $a2, $zero
/* 1024D0 7F0CD9A0 8E2F0008 */  lw    $t7, 8($s1)
/* 1024D4 7F0CD9A4 8FAC0094 */  lw    $t4, 0x94($sp)
/* 1024D8 7F0CD9A8 02001025 */  move  $v0, $s0
/* 1024DC 7F0CD9AC 000F5EC0 */  sll   $t3, $t7, 0x1b
/* 1024E0 7F0CD9B0 000BC742 */  srl   $t8, $t3, 0x1d
/* 1024E4 7F0CD9B4 330E0007 */  andi  $t6, $t8, 7
/* 1024E8 7F0CD9B8 000E6D40 */  sll   $t5, $t6, 0x15
/* 1024EC 7F0CD9BC 3C01F500 */  lui   $at, 0xf500
/* 1024F0 7F0CD9C0 318F0003 */  andi  $t7, $t4, 3
/* 1024F4 7F0CD9C4 000F5CC0 */  sll   $t3, $t7, 0x13
/* 1024F8 7F0CD9C8 01A1C825 */  or    $t9, $t5, $at
/* 1024FC 7F0CD9CC 3C0A0700 */  lui   $t2, 0x700
/* 102500 7F0CD9D0 032BC025 */  or    $t8, $t9, $t3
/* 102504 7F0CD9D4 AC580000 */  sw    $t8, ($v0)
/* 102508 7F0CD9D8 AC4A0004 */  sw    $t2, 4($v0)
/* 10250C 7F0CD9DC 26100008 */  addiu $s0, $s0, 8
.L7F0CD9E0:
/* 102510 7F0CD9E0 02001025 */  move  $v0, $s0
/* 102514 7F0CD9E4 26100008 */  addiu $s0, $s0, 8
/* 102518 7F0CD9E8 3C0EE600 */  lui   $t6, 0xe600
/* 10251C 7F0CD9EC AC4E0000 */  sw    $t6, ($v0)
/* 102520 7F0CD9F0 AC400004 */  sw    $zero, 4($v0)
/* 102524 7F0CD9F4 02002825 */  move  $a1, $s0
/* 102528 7F0CD9F8 3C0DF300 */  lui   $t5, 0xf300
/* 10252C 7F0CD9FC ACAD0000 */  sw    $t5, ($a1)
/* 102530 7F0CDA00 8FA30090 */  lw    $v1, 0x90($sp)
/* 102534 7F0CDA04 3C0A0700 */  lui   $t2, 0x700
/* 102538 7F0CDA08 8FAB008C */  lw    $t3, 0x8c($sp)
/* 10253C 7F0CDA0C 2463FFFF */  addiu $v1, $v1, -1
/* 102540 7F0CDA10 286107FF */  slti  $at, $v1, 0x7ff
/* 102544 7F0CDA14 10200003 */  beqz  $at, .L7F0CDA24
/* 102548 7F0CDA18 26100008 */   addiu $s0, $s0, 8
/* 10254C 7F0CDA1C 10000002 */  b     .L7F0CDA28
/* 102550 7F0CDA20 00602025 */   move  $a0, $v1
.L7F0CDA24:
/* 102554 7F0CDA24 240407FF */  li    $a0, 2047
.L7F0CDA28:
/* 102558 7F0CDA28 308C0FFF */  andi  $t4, $a0, 0xfff
/* 10255C 7F0CDA2C 000C7B00 */  sll   $t7, $t4, 0xc
/* 102560 7F0CDA30 01EAC825 */  or    $t9, $t7, $t2
/* 102564 7F0CDA34 31780FFF */  andi  $t8, $t3, 0xfff
/* 102568 7F0CDA38 03387025 */  or    $t6, $t9, $t8
/* 10256C 7F0CDA3C ACAE0004 */  sw    $t6, 4($a1)
/* 102570 7F0CDA40 02001025 */  move  $v0, $s0
/* 102574 7F0CDA44 3C0DE700 */  lui   $t5, 0xe700
/* 102578 7F0CDA48 AC4D0000 */  sw    $t5, ($v0)
/* 10257C 7F0CDA4C AC400004 */  sw    $zero, 4($v0)
/* 102580 7F0CDA50 922C000A */  lbu   $t4, 0xa($s1)
/* 102584 7F0CDA54 8FA80090 */  lw    $t0, 0x90($sp)
/* 102588 7F0CDA58 240F03FF */  li    $t7, 1023
/* 10258C 7F0CDA5C 01EC1823 */  subu  $v1, $t7, $t4
/* 102590 7F0CDA60 0068082B */  sltu  $at, $v1, $t0
/* 102594 7F0CDA64 10200003 */  beqz  $at, .L7F0CDA74
/* 102598 7F0CDA68 26100008 */   addiu $s0, $s0, 8
/* 10259C 7F0CDA6C 10000002 */  b     .L7F0CDA78
/* 1025A0 7F0CDA70 00604825 */   move  $t1, $v1
.L7F0CDA74:
/* 1025A4 7F0CDA74 00004825 */  move  $t1, $zero
.L7F0CDA78:
/* 1025A8 7F0CDA78 01094023 */  subu  $t0, $t0, $t1
/* 1025AC 7F0CDA7C 24190100 */  li    $t9, 256
/* 1025B0 7F0CDA80 AFB90010 */  sw    $t9, 0x10($sp)
/* 1025B4 7F0CDA84 AFA80074 */  sw    $t0, 0x74($sp)
/* 1025B8 7F0CDA88 24040007 */  li    $a0, 7
/* 1025BC 7F0CDA8C 00002825 */  move  $a1, $zero
/* 1025C0 7F0CDA90 24070001 */  li    $a3, 1
/* 1025C4 7F0CDA94 AFA00014 */  sw    $zero, 0x14($sp)
/* 1025C8 7F0CDA98 AFA00018 */  sw    $zero, 0x18($sp)
/* 1025CC 7F0CDA9C AFA0001C */  sw    $zero, 0x1c($sp)
/* 1025D0 7F0CDAA0 AFA00020 */  sw    $zero, 0x20($sp)
/* 1025D4 7F0CDAA4 AFA00024 */  sw    $zero, 0x24($sp)
/* 1025D8 7F0CDAA8 AFA00028 */  sw    $zero, 0x28($sp)
/* 1025DC 7F0CDAAC 0FC3315D */  jal   sub_GAME_7F0CC574
/* 1025E0 7F0CDAB0 AFA90070 */   sw    $t1, 0x70($sp)
/* 1025E4 7F0CDAB4 8FA80074 */  lw    $t0, 0x74($sp)
/* 1025E8 7F0CDAB8 8FA90070 */  lw    $t1, 0x70($sp)
/* 1025EC 7F0CDABC 10400007 */  beqz  $v0, .L7F0CDADC
/* 1025F0 7F0CDAC0 3C0A0700 */   lui   $t2, 0x700
/* 1025F4 7F0CDAC4 02001025 */  move  $v0, $s0
/* 1025F8 7F0CDAC8 3C18F500 */  lui   $t8, (0xF5000300 >> 16) # lui $t8, 0xf500
/* 1025FC 7F0CDACC 37180300 */  ori   $t8, (0xF5000300 & 0xFFFF) # ori $t8, $t8, 0x300
/* 102600 7F0CDAD0 AC580000 */  sw    $t8, ($v0)
/* 102604 7F0CDAD4 AC4A0004 */  sw    $t2, 4($v0)
/* 102608 7F0CDAD8 26100008 */  addiu $s0, $s0, 8
.L7F0CDADC:
/* 10260C 7F0CDADC 02001025 */  move  $v0, $s0
/* 102610 7F0CDAE0 310F03FF */  andi  $t7, $t0, 0x3ff
/* 102614 7F0CDAE4 000F6380 */  sll   $t4, $t7, 0xe
/* 102618 7F0CDAE8 312403FF */  andi  $a0, $t1, 0x3ff
/* 10261C 7F0CDAEC 3C01F000 */  lui   $at, 0xf000
/* 102620 7F0CDAF0 26100008 */  addiu $s0, $s0, 8
/* 102624 7F0CDAF4 3C0EE600 */  lui   $t6, 0xe600
/* 102628 7F0CDAF8 01815825 */  or    $t3, $t4, $at
/* 10262C 7F0CDAFC 00046880 */  sll   $t5, $a0, 2
/* 102630 7F0CDB00 AC4E0000 */  sw    $t6, ($v0)
/* 102634 7F0CDB04 AC400004 */  sw    $zero, 4($v0)
/* 102638 7F0CDB08 016DC825 */  or    $t9, $t3, $t5
/* 10263C 7F0CDB0C 02001825 */  move  $v1, $s0
/* 102640 7F0CDB10 AC790000 */  sw    $t9, ($v1)
/* 102644 7F0CDB14 9238000A */  lbu   $t8, 0xa($s1)
/* 102648 7F0CDB18 01A02025 */  move  $a0, $t5
/* 10264C 7F0CDB1C 26100008 */  addiu $s0, $s0, 8
/* 102650 7F0CDB20 03087021 */  addu  $t6, $t8, $t0
/* 102654 7F0CDB24 31CD03FF */  andi  $t5, $t6, 0x3ff
/* 102658 7F0CDB28 000D7B80 */  sll   $t7, $t5, 0xe
/* 10265C 7F0CDB2C 01EA6025 */  or    $t4, $t7, $t2
/* 102660 7F0CDB30 01845825 */  or    $t3, $t4, $a0
/* 102664 7F0CDB34 02002825 */  move  $a1, $s0
/* 102668 7F0CDB38 AC6B0004 */  sw    $t3, 4($v1)
/* 10266C 7F0CDB3C 3C19E700 */  lui   $t9, 0xe700
/* 102670 7F0CDB40 ACB90000 */  sw    $t9, ($a1)
/* 102674 7F0CDB44 ACA00004 */  sw    $zero, 4($a1)
/* 102678 7F0CDB48 26100008 */  addiu $s0, $s0, 8
.L7F0CDB4C:
/* 10267C 7F0CDB4C 8FBF003C */  lw    $ra, 0x3c($sp)
/* 102680 7F0CDB50 02001025 */  move  $v0, $s0
/* 102684 7F0CDB54 8FB00034 */  lw    $s0, 0x34($sp)
/* 102688 7F0CDB58 8FB10038 */  lw    $s1, 0x38($sp)
/* 10268C 7F0CDB5C 03E00008 */  jr    $ra
/* 102690 7F0CDB60 27BD0098 */   addiu $sp, $sp, 0x98
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0CDB64(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0CDB64
/* 102694 7F0CDB64 27BDFF90 */  addiu $sp, $sp, -0x70
/* 102698 7F0CDB68 AFB10038 */  sw    $s1, 0x38($sp)
/* 10269C 7F0CDB6C 00808825 */  move  $s1, $a0
/* 1026A0 7F0CDB70 AFBF003C */  sw    $ra, 0x3c($sp)
/* 1026A4 7F0CDB74 AFB00034 */  sw    $s0, 0x34($sp)
/* 1026A8 7F0CDB78 AFA60078 */  sw    $a2, 0x78($sp)
/* 1026AC 7F0CDB7C AFA7007C */  sw    $a3, 0x7c($sp)
/* 1026B0 7F0CDB80 00A08025 */  move  $s0, $a1
/* 1026B4 7F0CDB84 0FC332A7 */  jal   sub_GAME_7F0CCA9C
/* 1026B8 7F0CDB88 90A40008 */   lbu   $a0, 8($a1)
/* 1026BC 7F0CDB8C AFA2006C */  sw    $v0, 0x6c($sp)
/* 1026C0 7F0CDB90 0FC332A7 */  jal   sub_GAME_7F0CCA9C
/* 1026C4 7F0CDB94 92040009 */   lbu   $a0, 9($s0)
/* 1026C8 7F0CDB98 AFA20068 */  sw    $v0, 0x68($sp)
/* 1026CC 7F0CDB9C 02002025 */  move  $a0, $s0
/* 1026D0 7F0CDBA0 0FC33239 */  jal   sub_GAME_7F0CC8E4
/* 1026D4 7F0CDBA4 00002825 */   move  $a1, $zero
/* 1026D8 7F0CDBA8 AFA20064 */  sw    $v0, 0x64($sp)
/* 1026DC 7F0CDBAC 8E03000C */  lw    $v1, 0xc($s0)
/* 1026E0 7F0CDBB0 00037080 */  sll   $t6, $v1, 2
/* 1026E4 7F0CDBB4 00032782 */  srl   $a0, $v1, 0x1e
/* 1026E8 7F0CDBB8 000E7FC2 */  srl   $t7, $t6, 0x1f
/* 1026EC 7F0CDBBC 0004C380 */  sll   $t8, $a0, 0xe
/* 1026F0 7F0CDBC0 AFAF0050 */  sw    $t7, 0x50($sp)
/* 1026F4 7F0CDBC4 0FC33152 */  jal   sub_GAME_7F0CC548
/* 1026F8 7F0CDBC8 03002025 */   move  $a0, $t8
/* 1026FC 7F0CDBCC 10400009 */  beqz  $v0, .L7F0CDBF4
/* 102700 7F0CDBD0 3C19BA00 */   lui   $t9, (0xBA000E02 >> 16) # lui $t9, 0xba00
/* 102704 7F0CDBD4 02201025 */  move  $v0, $s1
/* 102708 7F0CDBD8 37390E02 */  ori   $t9, (0xBA000E02 & 0xFFFF) # ori $t9, $t9, 0xe02
/* 10270C 7F0CDBDC AC590000 */  sw    $t9, ($v0)
/* 102710 7F0CDBE0 8E09000C */  lw    $t1, 0xc($s0)
/* 102714 7F0CDBE4 26310008 */  addiu $s1, $s1, 8
/* 102718 7F0CDBE8 00095782 */  srl   $t2, $t1, 0x1e
/* 10271C 7F0CDBEC 000A5B80 */  sll   $t3, $t2, 0xe
/* 102720 7F0CDBF0 AC4B0004 */  sw    $t3, 4($v0)
.L7F0CDBF4:
/* 102724 7F0CDBF4 8E020008 */  lw    $v0, 8($s0)
/* 102728 7F0CDBF8 8FAD0078 */  lw    $t5, 0x78($sp)
/* 10272C 7F0CDBFC 8FAE007C */  lw    $t6, 0x7c($sp)
/* 102730 7F0CDC00 8FAF006C */  lw    $t7, 0x6c($sp)
/* 102734 7F0CDC04 8FB80068 */  lw    $t8, 0x68($sp)
/* 102738 7F0CDC08 00022EC0 */  sll   $a1, $v0, 0x1b
/* 10273C 7F0CDC0C 00056742 */  srl   $t4, $a1, 0x1d
/* 102740 7F0CDC10 01802825 */  move  $a1, $t4
/* 102744 7F0CDC14 AFA00028 */  sw    $zero, 0x28($sp)
/* 102748 7F0CDC18 AFA00024 */  sw    $zero, 0x24($sp)
/* 10274C 7F0CDC1C AFA00010 */  sw    $zero, 0x10($sp)
/* 102750 7F0CDC20 8FA40084 */  lw    $a0, 0x84($sp)
/* 102754 7F0CDC24 8FA70064 */  lw    $a3, 0x64($sp)
/* 102758 7F0CDC28 30460003 */  andi  $a2, $v0, 3
/* 10275C 7F0CDC2C AFAD0014 */  sw    $t5, 0x14($sp)
/* 102760 7F0CDC30 AFAE0018 */  sw    $t6, 0x18($sp)
/* 102764 7F0CDC34 AFAF001C */  sw    $t7, 0x1c($sp)
/* 102768 7F0CDC38 0FC3315D */  jal   sub_GAME_7F0CC574
/* 10276C 7F0CDC3C AFB80020 */   sw    $t8, 0x20($sp)
/* 102770 7F0CDC40 1040002B */  beqz  $v0, .L7F0CDCF0
/* 102774 7F0CDC44 02201825 */   move  $v1, $s1
/* 102778 7F0CDC48 8E0D0008 */  lw    $t5, 8($s0)
/* 10277C 7F0CDC4C 3C01F500 */  lui   $at, 0xf500
/* 102780 7F0CDC50 26310008 */  addiu $s1, $s1, 8
/* 102784 7F0CDC54 000DCEC0 */  sll   $t9, $t5, 0x1b
/* 102788 7F0CDC58 00194F42 */  srl   $t1, $t9, 0x1d
/* 10278C 7F0CDC5C 8FB90064 */  lw    $t9, 0x64($sp)
/* 102790 7F0CDC60 312A0007 */  andi  $t2, $t1, 7
/* 102794 7F0CDC64 000A5D40 */  sll   $t3, $t2, 0x15
/* 102798 7F0CDC68 31AE0003 */  andi  $t6, $t5, 3
/* 10279C 7F0CDC6C 000E7CC0 */  sll   $t7, $t6, 0x13
/* 1027A0 7F0CDC70 01616025 */  or    $t4, $t3, $at
/* 1027A4 7F0CDC74 332901FF */  andi  $t1, $t9, 0x1ff
/* 1027A8 7F0CDC78 00095240 */  sll   $t2, $t1, 9
/* 1027AC 7F0CDC7C 018FC025 */  or    $t8, $t4, $t7
/* 1027B0 7F0CDC80 030A5825 */  or    $t3, $t8, $t2
/* 1027B4 7F0CDC84 AC6B0000 */  sw    $t3, ($v1)
/* 1027B8 7F0CDC88 AFA30048 */  sw    $v1, 0x48($sp)
/* 1027BC 7F0CDC8C 0FC332B3 */  jal   sub_GAME_7F0CCACC
/* 1027C0 7F0CDC90 8FA4007C */   lw    $a0, 0x7c($sp)
/* 1027C4 7F0CDC94 8FA40078 */  lw    $a0, 0x78($sp)
/* 1027C8 7F0CDC98 0FC332B3 */  jal   sub_GAME_7F0CCACC
/* 1027CC 7F0CDC9C AFA20040 */   sw    $v0, 0x40($sp)
/* 1027D0 7F0CDCA0 8FAC0084 */  lw    $t4, 0x84($sp)
/* 1027D4 7F0CDCA4 304D0003 */  andi  $t5, $v0, 3
/* 1027D8 7F0CDCA8 8FA30040 */  lw    $v1, 0x40($sp)
/* 1027DC 7F0CDCAC 000D7200 */  sll   $t6, $t5, 8
/* 1027E0 7F0CDCB0 318F0007 */  andi  $t7, $t4, 7
/* 1027E4 7F0CDCB4 8FAD0068 */  lw    $t5, 0x68($sp)
/* 1027E8 7F0CDCB8 000FCE00 */  sll   $t9, $t7, 0x18
/* 1027EC 7F0CDCBC 01D94825 */  or    $t1, $t6, $t9
/* 1027F0 7F0CDCC0 8FB9006C */  lw    $t9, 0x6c($sp)
/* 1027F4 7F0CDCC4 30780003 */  andi  $t8, $v1, 3
/* 1027F8 7F0CDCC8 00185480 */  sll   $t2, $t8, 0x12
/* 1027FC 7F0CDCCC 31AC000F */  andi  $t4, $t5, 0xf
/* 102800 7F0CDCD0 012A5825 */  or    $t3, $t1, $t2
/* 102804 7F0CDCD4 8FAD0048 */  lw    $t5, 0x48($sp)
/* 102808 7F0CDCD8 000C7B80 */  sll   $t7, $t4, 0xe
/* 10280C 7F0CDCDC 3338000F */  andi  $t8, $t9, 0xf
/* 102810 7F0CDCE0 00184900 */  sll   $t1, $t8, 4
/* 102814 7F0CDCE4 016F7025 */  or    $t6, $t3, $t7
/* 102818 7F0CDCE8 01C95025 */  or    $t2, $t6, $t1
/* 10281C 7F0CDCEC ADAA0004 */  sw    $t2, 4($t5)
.L7F0CDCF0:
/* 102820 7F0CDCF0 8FA20080 */  lw    $v0, 0x80($sp)
/* 102824 7F0CDCF4 24040002 */  li    $a0, 2
/* 102828 7F0CDCF8 8FA80050 */  lw    $t0, 0x50($sp)
/* 10282C 7F0CDCFC 14440005 */  bne   $v0, $a0, .L7F0CDD14
/* 102830 7F0CDD00 00001825 */   move  $v1, $zero
/* 102834 7F0CDD04 55000004 */  bnezl $t0, .L7F0CDD18
/* 102838 7F0CDD08 8FA80050 */   lw    $t0, 0x50($sp)
/* 10283C 7F0CDD0C 10000002 */  b     .L7F0CDD18
/* 102840 7F0CDD10 00801825 */   move  $v1, $a0
.L7F0CDD14:
/* 102844 7F0CDD14 8FA80050 */  lw    $t0, 0x50($sp)
.L7F0CDD18:
/* 102848 7F0CDD18 14440005 */  bne   $v0, $a0, .L7F0CDD30
/* 10284C 7F0CDD1C 00602825 */   move  $a1, $v1
/* 102850 7F0CDD20 55000004 */  bnezl $t0, .L7F0CDD34
/* 102854 7F0CDD24 00001825 */   move  $v1, $zero
/* 102858 7F0CDD28 10000002 */  b     .L7F0CDD34
/* 10285C 7F0CDD2C 00801825 */   move  $v1, $a0
.L7F0CDD30:
/* 102860 7F0CDD30 00001825 */  move  $v1, $zero
.L7F0CDD34:
/* 102864 7F0CDD34 14440005 */  bne   $v0, $a0, .L7F0CDD4C
/* 102868 7F0CDD38 00603025 */   move  $a2, $v1
/* 10286C 7F0CDD3C 55000004 */  bnezl $t0, .L7F0CDD50
/* 102870 7F0CDD40 00001825 */   move  $v1, $zero
/* 102874 7F0CDD44 10000002 */  b     .L7F0CDD50
/* 102878 7F0CDD48 00801825 */   move  $v1, $a0
.L7F0CDD4C:
/* 10287C 7F0CDD4C 00001825 */  move  $v1, $zero
.L7F0CDD50:
/* 102880 7F0CDD50 920C0008 */  lbu   $t4, 8($s0)
/* 102884 7F0CDD54 258BFFFF */  addiu $t3, $t4, -1
/* 102888 7F0CDD58 000B7880 */  sll   $t7, $t3, 2
/* 10288C 7F0CDD5C 14440005 */  bne   $v0, $a0, .L7F0CDD74
/* 102890 7F0CDD60 006F3821 */   addu  $a3, $v1, $t7
/* 102894 7F0CDD64 55000004 */  bnezl $t0, .L7F0CDD78
/* 102898 7F0CDD68 00001825 */   move  $v1, $zero
/* 10289C 7F0CDD6C 10000002 */  b     .L7F0CDD78
/* 1028A0 7F0CDD70 24030002 */   li    $v1, 2
.L7F0CDD74:
/* 1028A4 7F0CDD74 00001825 */  move  $v1, $zero
.L7F0CDD78:
/* 1028A8 7F0CDD78 92190009 */  lbu   $t9, 9($s0)
/* 1028AC 7F0CDD7C AFA70058 */  sw    $a3, 0x58($sp)
/* 1028B0 7F0CDD80 AFA6005C */  sw    $a2, 0x5c($sp)
/* 1028B4 7F0CDD84 2738FFFF */  addiu $t8, $t9, -1
/* 1028B8 7F0CDD88 00187080 */  sll   $t6, $t8, 2
/* 1028BC 7F0CDD8C 006E4021 */  addu  $t0, $v1, $t6
/* 1028C0 7F0CDD90 AFA80010 */  sw    $t0, 0x10($sp)
/* 1028C4 7F0CDD94 AFA80054 */  sw    $t0, 0x54($sp)
/* 1028C8 7F0CDD98 AFA50060 */  sw    $a1, 0x60($sp)
/* 1028CC 7F0CDD9C 0FC331A4 */  jal   sub_GAME_7F0CC690
/* 1028D0 7F0CDDA0 8FA40084 */   lw    $a0, 0x84($sp)
/* 1028D4 7F0CDDA4 8FA50060 */  lw    $a1, 0x60($sp)
/* 1028D8 7F0CDDA8 8FA6005C */  lw    $a2, 0x5c($sp)
/* 1028DC 7F0CDDAC 8FA70058 */  lw    $a3, 0x58($sp)
/* 1028E0 7F0CDDB0 10400013 */  beqz  $v0, .L7F0CDE00
/* 1028E4 7F0CDDB4 8FA80054 */   lw    $t0, 0x54($sp)
/* 1028E8 7F0CDDB8 30A90FFF */  andi  $t1, $a1, 0xfff
/* 1028EC 7F0CDDBC 00095300 */  sll   $t2, $t1, 0xc
/* 1028F0 7F0CDDC0 3C01F200 */  lui   $at, 0xf200
/* 1028F4 7F0CDDC4 01416825 */  or    $t5, $t2, $at
/* 1028F8 7F0CDDC8 30CC0FFF */  andi  $t4, $a2, 0xfff
/* 1028FC 7F0CDDCC 01AC5825 */  or    $t3, $t5, $t4
/* 102900 7F0CDDD0 02201025 */  move  $v0, $s1
/* 102904 7F0CDDD4 AC4B0000 */  sw    $t3, ($v0)
/* 102908 7F0CDDD8 8FAF0084 */  lw    $t7, 0x84($sp)
/* 10290C 7F0CDDDC 30EE0FFF */  andi  $t6, $a3, 0xfff
/* 102910 7F0CDDE0 000E4B00 */  sll   $t1, $t6, 0xc
/* 102914 7F0CDDE4 31F90007 */  andi  $t9, $t7, 7
/* 102918 7F0CDDE8 0019C600 */  sll   $t8, $t9, 0x18
/* 10291C 7F0CDDEC 03095025 */  or    $t2, $t8, $t1
/* 102920 7F0CDDF0 310D0FFF */  andi  $t5, $t0, 0xfff
/* 102924 7F0CDDF4 014D6025 */  or    $t4, $t2, $t5
/* 102928 7F0CDDF8 AC4C0004 */  sw    $t4, 4($v0)
/* 10292C 7F0CDDFC 26310008 */  addiu $s1, $s1, 8
.L7F0CDE00:
/* 102930 7F0CDE00 8FBF003C */  lw    $ra, 0x3c($sp)
/* 102934 7F0CDE04 02201025 */  move  $v0, $s1
/* 102938 7F0CDE08 8FB10038 */  lw    $s1, 0x38($sp)
/* 10293C 7F0CDE0C 8FB00034 */  lw    $s0, 0x34($sp)
/* 102940 7F0CDE10 03E00008 */  jr    $ra
/* 102944 7F0CDE14 27BD0070 */   addiu $sp, $sp, 0x70
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0CDE18(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0CDE18
/* 102948 7F0CDE18 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 10294C 7F0CDE1C AFBF0024 */  sw    $ra, 0x24($sp)
/* 102950 7F0CDE20 AFA60030 */  sw    $a2, 0x30($sp)
/* 102954 7F0CDE24 AFA5002C */  sw    $a1, 0x2c($sp)
/* 102958 7F0CDE28 AFA70034 */  sw    $a3, 0x34($sp)
/* 10295C 7F0CDE2C 0FC3341E */  jal   expland_c0_DL_psuedocommands
/* 102960 7F0CDE30 00003025 */   move  $a2, $zero
/* 102964 7F0CDE34 8FAE0038 */  lw    $t6, 0x38($sp)
/* 102968 7F0CDE38 00402025 */  move  $a0, $v0
/* 10296C 7F0CDE3C 8FA5002C */  lw    $a1, 0x2c($sp)
/* 102970 7F0CDE40 8FA60030 */  lw    $a2, 0x30($sp)
/* 102974 7F0CDE44 8FA70034 */  lw    $a3, 0x34($sp)
/* 102978 7F0CDE48 AFA00014 */  sw    $zero, 0x14($sp)
/* 10297C 7F0CDE4C AFA00018 */  sw    $zero, 0x18($sp)
/* 102980 7F0CDE50 0FC3350C */  jal   sub_GAME_7F0CD430
/* 102984 7F0CDE54 AFAE0010 */   sw    $t6, 0x10($sp)
/* 102988 7F0CDE58 8FA5002C */  lw    $a1, 0x2c($sp)
/* 10298C 7F0CDE5C 24010001 */  li    $at, 1
/* 102990 7F0CDE60 00402025 */  move  $a0, $v0
/* 102994 7F0CDE64 90AF000B */  lbu   $t7, 0xb($a1)
/* 102998 7F0CDE68 8FA60030 */  lw    $a2, 0x30($sp)
/* 10299C 7F0CDE6C 8FA70034 */  lw    $a3, 0x34($sp)
/* 1029A0 7F0CDE70 000FC142 */  srl   $t8, $t7, 5
/* 1029A4 7F0CDE74 17010007 */  bne   $t8, $at, .L7F0CDE94
/* 1029A8 7F0CDE78 8FB90038 */   lw    $t9, 0x38($sp)
/* 1029AC 7F0CDE7C 24080001 */  li    $t0, 1
/* 1029B0 7F0CDE80 AFA80014 */  sw    $t0, 0x14($sp)
/* 1029B4 7F0CDE84 AFB90010 */  sw    $t9, 0x10($sp)
/* 1029B8 7F0CDE88 0FC3350C */  jal   sub_GAME_7F0CD430
/* 1029BC 7F0CDE8C AFA00018 */   sw    $zero, 0x18($sp)
/* 1029C0 7F0CDE90 00402025 */  move  $a0, $v0
.L7F0CDE94:
/* 1029C4 7F0CDE94 8FBF0024 */  lw    $ra, 0x24($sp)
/* 1029C8 7F0CDE98 27BD0028 */  addiu $sp, $sp, 0x28
/* 1029CC 7F0CDE9C 00801025 */  move  $v0, $a0
/* 1029D0 7F0CDEA0 03E00008 */  jr    $ra
/* 1029D4 7F0CDEA4 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0CDEA8(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0CDEA8
/* 1029D8 7F0CDEA8 27BDFFC8 */  addiu $sp, $sp, -0x38
/* 1029DC 7F0CDEAC AFB00028 */  sw    $s0, 0x28($sp)
/* 1029E0 7F0CDEB0 00808025 */  move  $s0, $a0
/* 1029E4 7F0CDEB4 AFBF002C */  sw    $ra, 0x2c($sp)
/* 1029E8 7F0CDEB8 AFA5003C */  sw    $a1, 0x3c($sp)
/* 1029EC 7F0CDEBC AFA60040 */  sw    $a2, 0x40($sp)
/* 1029F0 7F0CDEC0 AFA70044 */  sw    $a3, 0x44($sp)
/* 1029F4 7F0CDEC4 00002825 */  move  $a1, $zero
/* 1029F8 7F0CDEC8 0FC33265 */  jal   sub_GAME_7F0CC994
/* 1029FC 7F0CDECC 8FA4004C */   lw    $a0, 0x4c($sp)
/* 102A00 7F0CDED0 AFA20034 */  sw    $v0, 0x34($sp)
/* 102A04 7F0CDED4 02002025 */  move  $a0, $s0
/* 102A08 7F0CDED8 0FC335EB */  jal   sub_GAME_7F0CD7AC
/* 102A0C 7F0CDEDC 8FA5004C */   lw    $a1, 0x4c($sp)
/* 102A10 7F0CDEE0 3C0EE800 */  lui   $t6, 0xe800
/* 102A14 7F0CDEE4 AC4E0000 */  sw    $t6, ($v0)
/* 102A18 7F0CDEE8 AC400004 */  sw    $zero, 4($v0)
/* 102A1C 7F0CDEEC 8FA60034 */  lw    $a2, 0x34($sp)
/* 102A20 7F0CDEF0 8FA5003C */  lw    $a1, 0x3c($sp)
/* 102A24 7F0CDEF4 0FC3341E */  jal   expland_c0_DL_psuedocommands
/* 102A28 7F0CDEF8 24440008 */   addiu $a0, $v0, 8
/* 102A2C 7F0CDEFC 8FAF0054 */  lw    $t7, 0x54($sp)
/* 102A30 7F0CDF00 8FB80058 */  lw    $t8, 0x58($sp)
/* 102A34 7F0CDF04 00402025 */  move  $a0, $v0
/* 102A38 7F0CDF08 8FA5004C */  lw    $a1, 0x4c($sp)
/* 102A3C 7F0CDF0C 8FA60048 */  lw    $a2, 0x48($sp)
/* 102A40 7F0CDF10 8FA70050 */  lw    $a3, 0x50($sp)
/* 102A44 7F0CDF14 AFAF0010 */  sw    $t7, 0x10($sp)
/* 102A48 7F0CDF18 0FC33314 */  jal   sub_GAME_7F0CCC50
/* 102A4C 7F0CDF1C AFB80014 */   sw    $t8, 0x14($sp)
/* 102A50 7F0CDF20 8FB90048 */  lw    $t9, 0x48($sp)
/* 102A54 7F0CDF24 8FA90034 */  lw    $t1, 0x34($sp)
/* 102A58 7F0CDF28 24080001 */  li    $t0, 1
/* 102A5C 7F0CDF2C AFA80014 */  sw    $t0, 0x14($sp)
/* 102A60 7F0CDF30 00402025 */  move  $a0, $v0
/* 102A64 7F0CDF34 8FA5003C */  lw    $a1, 0x3c($sp)
/* 102A68 7F0CDF38 8FA60040 */  lw    $a2, 0x40($sp)
/* 102A6C 7F0CDF3C 8FA70044 */  lw    $a3, 0x44($sp)
/* 102A70 7F0CDF40 AFB90010 */  sw    $t9, 0x10($sp)
/* 102A74 7F0CDF44 0FC3350C */  jal   sub_GAME_7F0CD430
/* 102A78 7F0CDF48 AFA90018 */   sw    $t1, 0x18($sp)
/* 102A7C 7F0CDF4C 8FAA003C */  lw    $t2, 0x3c($sp)
/* 102A80 7F0CDF50 24010001 */  li    $at, 1
/* 102A84 7F0CDF54 00408025 */  move  $s0, $v0
/* 102A88 7F0CDF58 914B000B */  lbu   $t3, 0xb($t2)
/* 102A8C 7F0CDF5C 00402025 */  move  $a0, $v0
/* 102A90 7F0CDF60 8FA60040 */  lw    $a2, 0x40($sp)
/* 102A94 7F0CDF64 000B6142 */  srl   $t4, $t3, 5
/* 102A98 7F0CDF68 1581000A */  bne   $t4, $at, .L7F0CDF94
/* 102A9C 7F0CDF6C 01402825 */   move  $a1, $t2
/* 102AA0 7F0CDF70 8FAD0048 */  lw    $t5, 0x48($sp)
/* 102AA4 7F0CDF74 8FAF0034 */  lw    $t7, 0x34($sp)
/* 102AA8 7F0CDF78 240E0002 */  li    $t6, 2
/* 102AAC 7F0CDF7C AFAE0014 */  sw    $t6, 0x14($sp)
/* 102AB0 7F0CDF80 8FA70044 */  lw    $a3, 0x44($sp)
/* 102AB4 7F0CDF84 AFAD0010 */  sw    $t5, 0x10($sp)
/* 102AB8 7F0CDF88 0FC3350C */  jal   sub_GAME_7F0CD430
/* 102ABC 7F0CDF8C AFAF0018 */   sw    $t7, 0x18($sp)
/* 102AC0 7F0CDF90 00408025 */  move  $s0, $v0
.L7F0CDF94:
/* 102AC4 7F0CDF94 8FBF002C */  lw    $ra, 0x2c($sp)
/* 102AC8 7F0CDF98 02001025 */  move  $v0, $s0
/* 102ACC 7F0CDF9C 8FB00028 */  lw    $s0, 0x28($sp)
/* 102AD0 7F0CDFA0 03E00008 */  jr    $ra
/* 102AD4 7F0CDFA4 27BD0038 */   addiu $sp, $sp, 0x38
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0CDFA8(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0CDFA8
/* 102AD8 7F0CDFA8 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 102ADC 7F0CDFAC AFBF002C */  sw    $ra, 0x2c($sp)
/* 102AE0 7F0CDFB0 AFB00028 */  sw    $s0, 0x28($sp)
/* 102AE4 7F0CDFB4 AFA60038 */  sw    $a2, 0x38($sp)
/* 102AE8 7F0CDFB8 00A08025 */  move  $s0, $a1
/* 102AEC 7F0CDFBC AFA7003C */  sw    $a3, 0x3c($sp)
/* 102AF0 7F0CDFC0 0FC3341E */  jal   expland_c0_DL_psuedocommands
/* 102AF4 7F0CDFC4 00003025 */   move  $a2, $zero
/* 102AF8 7F0CDFC8 8FAE0048 */  lw    $t6, 0x48($sp)
/* 102AFC 7F0CDFCC 8FAF004C */  lw    $t7, 0x4c($sp)
/* 102B00 7F0CDFD0 00402025 */  move  $a0, $v0
/* 102B04 7F0CDFD4 02002825 */  move  $a1, $s0
/* 102B08 7F0CDFD8 8FA60040 */  lw    $a2, 0x40($sp)
/* 102B0C 7F0CDFDC 8FA70044 */  lw    $a3, 0x44($sp)
/* 102B10 7F0CDFE0 AFAE0010 */  sw    $t6, 0x10($sp)
/* 102B14 7F0CDFE4 0FC33314 */  jal   sub_GAME_7F0CCC50
/* 102B18 7F0CDFE8 AFAF0014 */   sw    $t7, 0x14($sp)
/* 102B1C 7F0CDFEC 8FB80040 */  lw    $t8, 0x40($sp)
/* 102B20 7F0CDFF0 24190001 */  li    $t9, 1
/* 102B24 7F0CDFF4 AFB90014 */  sw    $t9, 0x14($sp)
/* 102B28 7F0CDFF8 00402025 */  move  $a0, $v0
/* 102B2C 7F0CDFFC 02002825 */  move  $a1, $s0
/* 102B30 7F0CE000 8FA60038 */  lw    $a2, 0x38($sp)
/* 102B34 7F0CE004 8FA7003C */  lw    $a3, 0x3c($sp)
/* 102B38 7F0CE008 AFA00018 */  sw    $zero, 0x18($sp)
/* 102B3C 7F0CE00C 0FC3350C */  jal   sub_GAME_7F0CD430
/* 102B40 7F0CE010 AFB80010 */   sw    $t8, 0x10($sp)
/* 102B44 7F0CE014 9208000B */  lbu   $t0, 0xb($s0)
/* 102B48 7F0CE018 24010001 */  li    $at, 1
/* 102B4C 7F0CE01C 00402025 */  move  $a0, $v0
/* 102B50 7F0CE020 00084942 */  srl   $t1, $t0, 5
/* 102B54 7F0CE024 1521000A */  bne   $t1, $at, .L7F0CE050
/* 102B58 7F0CE028 02002825 */   move  $a1, $s0
/* 102B5C 7F0CE02C 8FAA0040 */  lw    $t2, 0x40($sp)
/* 102B60 7F0CE030 240B0002 */  li    $t3, 2
/* 102B64 7F0CE034 AFAB0014 */  sw    $t3, 0x14($sp)
/* 102B68 7F0CE038 8FA60038 */  lw    $a2, 0x38($sp)
/* 102B6C 7F0CE03C 8FA7003C */  lw    $a3, 0x3c($sp)
/* 102B70 7F0CE040 AFA00018 */  sw    $zero, 0x18($sp)
/* 102B74 7F0CE044 0FC3350C */  jal   sub_GAME_7F0CD430
/* 102B78 7F0CE048 AFAA0010 */   sw    $t2, 0x10($sp)
/* 102B7C 7F0CE04C 00402025 */  move  $a0, $v0
.L7F0CE050:
/* 102B80 7F0CE050 8FBF002C */  lw    $ra, 0x2c($sp)
/* 102B84 7F0CE054 8FB00028 */  lw    $s0, 0x28($sp)
/* 102B88 7F0CE058 27BD0030 */  addiu $sp, $sp, 0x30
/* 102B8C 7F0CE05C 03E00008 */  jr    $ra
/* 102B90 7F0CE060 00801025 */   move  $v0, $a0
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0CE064(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0CE064
/* 102B94 7F0CE064 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 102B98 7F0CE068 AFBF001C */  sw    $ra, 0x1c($sp)
/* 102B9C 7F0CE06C AFA50024 */  sw    $a1, 0x24($sp)
/* 102BA0 7F0CE070 AFA60028 */  sw    $a2, 0x28($sp)
/* 102BA4 7F0CE074 0FC335EB */  jal   sub_GAME_7F0CD7AC
/* 102BA8 7F0CE078 AFA7002C */   sw    $a3, 0x2c($sp)
/* 102BAC 7F0CE07C 8FAE0030 */  lw    $t6, 0x30($sp)
/* 102BB0 7F0CE080 00402025 */  move  $a0, $v0
/* 102BB4 7F0CE084 8FA50024 */  lw    $a1, 0x24($sp)
/* 102BB8 7F0CE088 8FA60028 */  lw    $a2, 0x28($sp)
/* 102BBC 7F0CE08C 8FA7002C */  lw    $a3, 0x2c($sp)
/* 102BC0 7F0CE090 AFA00014 */  sw    $zero, 0x14($sp)
/* 102BC4 7F0CE094 0FC336D9 */  jal   sub_GAME_7F0CDB64
/* 102BC8 7F0CE098 AFAE0010 */   sw    $t6, 0x10($sp)
/* 102BCC 7F0CE09C 8FBF001C */  lw    $ra, 0x1c($sp)
/* 102BD0 7F0CE0A0 27BD0020 */  addiu $sp, $sp, 0x20
/* 102BD4 7F0CE0A4 03E00008 */  jr    $ra
/* 102BD8 7F0CE0A8 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0CE0AC(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0CE0AC
/* 102BDC 7F0CE0AC 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 102BE0 7F0CE0B0 AFBF001C */  sw    $ra, 0x1c($sp)
/* 102BE4 7F0CE0B4 AFA50024 */  sw    $a1, 0x24($sp)
/* 102BE8 7F0CE0B8 AFA60028 */  sw    $a2, 0x28($sp)
/* 102BEC 7F0CE0BC 0FC335EB */  jal   sub_GAME_7F0CD7AC
/* 102BF0 7F0CE0C0 AFA7002C */   sw    $a3, 0x2c($sp)
/* 102BF4 7F0CE0C4 8FAE0030 */  lw    $t6, 0x30($sp)
/* 102BF8 7F0CE0C8 00402025 */  move  $a0, $v0
/* 102BFC 7F0CE0CC 8FA50024 */  lw    $a1, 0x24($sp)
/* 102C00 7F0CE0D0 8FA60028 */  lw    $a2, 0x28($sp)
/* 102C04 7F0CE0D4 8FA7002C */  lw    $a3, 0x2c($sp)
/* 102C08 7F0CE0D8 AFA00014 */  sw    $zero, 0x14($sp)
/* 102C0C 7F0CE0DC 0FC336D9 */  jal   sub_GAME_7F0CDB64
/* 102C10 7F0CE0E0 AFAE0010 */   sw    $t6, 0x10($sp)
/* 102C14 7F0CE0E4 8FAF0030 */  lw    $t7, 0x30($sp)
/* 102C18 7F0CE0E8 24180001 */  li    $t8, 1
/* 102C1C 7F0CE0EC AFB80014 */  sw    $t8, 0x14($sp)
/* 102C20 7F0CE0F0 00402025 */  move  $a0, $v0
/* 102C24 7F0CE0F4 8FA50024 */  lw    $a1, 0x24($sp)
/* 102C28 7F0CE0F8 8FA60028 */  lw    $a2, 0x28($sp)
/* 102C2C 7F0CE0FC 8FA7002C */  lw    $a3, 0x2c($sp)
/* 102C30 7F0CE100 0FC336D9 */  jal   sub_GAME_7F0CDB64
/* 102C34 7F0CE104 AFAF0010 */   sw    $t7, 0x10($sp)
/* 102C38 7F0CE108 8FBF001C */  lw    $ra, 0x1c($sp)
/* 102C3C 7F0CE10C 27BD0020 */  addiu $sp, $sp, 0x20
/* 102C40 7F0CE110 03E00008 */  jr    $ra
/* 102C44 7F0CE114 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void process_microcode_sort_display_modes_expand_image_calls(void) {

}
#else
GLOBAL_ASM(
.late_rodata
glabel PADDINGHACKING
.word 0
/*D:8005BF20*/
glabel tlb_ptr_DL_type_B1toC0
.word .L7F0CE66C
.word .L7F0CE720
.word .L7F0CE720
.word .L7F0CE720
.word .L7F0CE720
.word .L7F0CE720
.word .L7F0CE720
.word .L7F0CE720
.word .L7F0CE720
.word .L7F0CE6B8
.word .L7F0CE694
.word .L7F0CE720
.word .L7F0CE720
.word .L7F0CE720
.word .L7F0CE66C
.word .L7F0CE1D8

/*D:8005BF60*/
glabel tlb_ptr_C0_image_recall_types
.word .L7F0CE2BC
.word .L7F0CE428
.word .L7F0CE4B8
.word .L7F0CE584
.word .L7F0CE5BC
.text
glabel process_microcode_sort_display_modes_expand_image_calls
/* 102C48 7F0CE118 27BDFF68 */  addiu $sp, $sp, -0x98
/* 102C4C 7F0CE11C AFB20038 */  sw    $s2, 0x38($sp)
/* 102C50 7F0CE120 AFBF0054 */  sw    $ra, 0x54($sp)
/* 102C54 7F0CE124 AFBE0050 */  sw    $fp, 0x50($sp)
/* 102C58 7F0CE128 AFB60048 */  sw    $s6, 0x48($sp)
/* 102C5C 7F0CE12C AFB40040 */  sw    $s4, 0x40($sp)
/* 102C60 7F0CE130 AFB10034 */  sw    $s1, 0x34($sp)
/* 102C64 7F0CE134 AFB00030 */  sw    $s0, 0x30($sp)
/* 102C68 7F0CE138 240E0001 */  li    $t6, 1
/* 102C6C 7F0CE13C 000590C3 */  sra   $s2, $a1, 3
/* 102C70 7F0CE140 00E0B025 */  move  $s6, $a3
/* 102C74 7F0CE144 AFB7004C */  sw    $s7, 0x4c($sp)
/* 102C78 7F0CE148 AFB50044 */  sw    $s5, 0x44($sp)
/* 102C7C 7F0CE14C AFB3003C */  sw    $s3, 0x3c($sp)
/* 102C80 7F0CE150 AFA600A0 */  sw    $a2, 0xa0($sp)
/* 102C84 7F0CE154 AFA0008C */  sw    $zero, 0x8c($sp)
/* 102C88 7F0CE158 0000A025 */  move  $s4, $zero
/* 102C8C 7F0CE15C 0000F025 */  move  $fp, $zero
/* 102C90 7F0CE160 AFAE005C */  sw    $t6, 0x5c($sp)
/* 102C94 7F0CE164 AFA00058 */  sw    $zero, 0x58($sp)
/* 102C98 7F0CE168 00808825 */  move  $s1, $a0
/* 102C9C 7F0CE16C 00C08025 */  move  $s0, $a2
/* 102CA0 7F0CE170 0FC33132 */  jal   sub_GAME_7F0CC4C8
/* 102CA4 7F0CE174 AFB20088 */   sw    $s2, 0x88($sp)
/* 102CA8 7F0CE178 16C00003 */  bnez  $s6, .L7F0CE188
/* 102CAC 7F0CE17C 2417000F */   li    $s7, 15
/* 102CB0 7F0CE180 3C168009 */  lui   $s6, %hi(ptr_texture_alloc_start) # $s6, 0x8009
/* 102CB4 7F0CE184 26D6C720 */  addiu $s6, %lo(ptr_texture_alloc_start) # addiu $s6, $s6, -0x38e0
.L7F0CE188:
/* 102CB8 7F0CE188 1A40016F */  blez  $s2, .L7F0CE748
/* 102CBC 7F0CE18C 3C158005 */   lui   $s5, %hi(D_800483C8) # $s5, 0x8005
/* 102CC0 7F0CE190 26B583C8 */  addiu $s5, %lo(D_800483C8) # addiu $s5, $s5, -0x7c38
.L7F0CE194:
/* 102CC4 7F0CE194 92220000 */  lbu   $v0, ($s1)
/* 102CC8 7F0CE198 284100C1 */  slti  $at, $v0, 0xc1
/* 102CCC 7F0CE19C 14200006 */  bnez  $at, .L7F0CE1B8
/* 102CD0 7F0CE1A0 244FFF4F */   addiu $t7, $v0, -0xb1
/* 102CD4 7F0CE1A4 240100E7 */  li    $at, 231
/* 102CD8 7F0CE1A8 50410129 */  beql  $v0, $at, .L7F0CE650
/* 102CDC 7F0CE1AC 8E210000 */   lw    $at, ($s1)
/* 102CE0 7F0CE1B0 1000015C */  b     .L7F0CE724
/* 102CE4 7F0CE1B4 8E210000 */   lw    $at, ($s1)
.L7F0CE1B8:
/* 102CE8 7F0CE1B8 2DE10010 */  sltiu $at, $t7, 0x10
/* 102CEC 7F0CE1BC 10200158 */  beqz  $at, .L7F0CE720
/* 102CF0 7F0CE1C0 000F7880 */   sll   $t7, $t7, 2
/* 102CF4 7F0CE1C4 3C018006 */  lui   $at, %hi(tlb_ptr_DL_type_B1toC0)
/* 102CF8 7F0CE1C8 002F0821 */  addu  $at, $at, $t7
/* 102CFC 7F0CE1CC 8C2FBF20 */  lw    $t7, %lo(tlb_ptr_DL_type_B1toC0)($at)
/* 102D00 7F0CE1D0 01E00008 */  jr    $t7
/* 102D04 7F0CE1D4 00000000 */   nop   
.L7F0CE1D8:
/* 102D08 7F0CE1D8 17C00006 */  bnez  $fp, .L7F0CE1F4
/* 102D0C 7F0CE1DC 02001025 */   move  $v0, $s0
/* 102D10 7F0CE1E0 3C18E700 */  lui   $t8, 0xe700
/* 102D14 7F0CE1E4 AC580000 */  sw    $t8, ($v0)
/* 102D18 7F0CE1E8 26100008 */  addiu $s0, $s0, 8
/* 102D1C 7F0CE1EC AC400004 */  sw    $zero, 4($v0)
/* 102D20 7F0CE1F0 241E0001 */  li    $fp, 1
.L7F0CE1F4:
/* 102D24 7F0CE1F4 8FB90058 */  lw    $t9, 0x58($sp)
/* 102D28 7F0CE1F8 02002025 */  move  $a0, $s0
/* 102D2C 7F0CE1FC 53200004 */  beql  $t9, $zero, .L7F0CE210
/* 102D30 7F0CE200 8E330004 */   lw    $s3, 4($s1)
/* 102D34 7F0CE204 0FC2ED80 */  jal   save_ptrDL_enpoint_to_current_init_lightfixture_table
/* 102D38 7F0CE208 AFA00058 */   sw    $zero, 0x58($sp)
/* 102D3C 7F0CE20C 8E330004 */  lw    $s3, 4($s1)
.L7F0CE210:
/* 102D40 7F0CE210 3C0E8005 */  lui   $t6, %hi(D_800483C4) # $t6, 0x8005
/* 102D44 7F0CE214 8DCE83C4 */  lw    $t6, %lo(D_800483C4)($t6)
/* 102D48 7F0CE218 326D0FFF */  andi  $t5, $s3, 0xfff
/* 102D4C 7F0CE21C 01A09825 */  move  $s3, $t5
/* 102D50 7F0CE220 15AE000D */  bne   $t5, $t6, .L7F0CE258
/* 102D54 7F0CE224 02C02825 */   move  $a1, $s6
/* 102D58 7F0CE228 8EA40000 */  lw    $a0, ($s5)
/* 102D5C 7F0CE22C 000D7880 */  sll   $t7, $t5, 2
/* 102D60 7F0CE230 10800009 */  beqz  $a0, .L7F0CE258
/* 102D64 7F0CE234 008FC021 */   addu  $t8, $a0, $t7
/* 102D68 7F0CE238 93190000 */  lbu   $t9, ($t8)
/* 102D6C 7F0CE23C 2F2100FF */  sltiu $at, $t9, 0xff
/* 102D70 7F0CE240 10200003 */  beqz  $at, .L7F0CE250
/* 102D74 7F0CE244 00000000 */   nop   
/* 102D78 7F0CE248 10000004 */  b     .L7F0CE25C
/* 102D7C 7F0CE24C 24140001 */   li    $s4, 1
.L7F0CE250:
/* 102D80 7F0CE250 10000002 */  b     .L7F0CE25C
/* 102D84 7F0CE254 0000A025 */   move  $s4, $zero
.L7F0CE258:
/* 102D88 7F0CE258 0000A025 */  move  $s4, $zero
.L7F0CE25C:
/* 102D8C 7F0CE25C 0FC32FBA */  jal   sub_GAME_7F0CBEE8
/* 102D90 7F0CE260 02602025 */   move  $a0, $s3
/* 102D94 7F0CE264 02602025 */  move  $a0, $s3
/* 102D98 7F0CE268 0FC32EC3 */  jal   sub_GAME_7F0CBB0C
/* 102D9C 7F0CE26C 02C02825 */   move  $a1, $s6
/* 102DA0 7F0CE270 104000F4 */  beqz  $v0, .L7F0CE644
/* 102DA4 7F0CE274 00409025 */   move  $s2, $v0
/* 102DA8 7F0CE278 8FA7005C */  lw    $a3, 0x5c($sp)
/* 102DAC 7F0CE27C AFA0005C */  sw    $zero, 0x5c($sp)
/* 102DB0 7F0CE280 02002025 */  move  $a0, $s0
/* 102DB4 7F0CE284 8FA5008C */  lw    $a1, 0x8c($sp)
/* 102DB8 7F0CE288 0FC333EF */  jal   sub_GAME_7F0CCFBC
/* 102DBC 7F0CE28C 00403025 */   move  $a2, $v0
/* 102DC0 7F0CE290 8E230000 */  lw    $v1, ($s1)
/* 102DC4 7F0CE294 00408025 */  move  $s0, $v0
/* 102DC8 7F0CE298 306D0007 */  andi  $t5, $v1, 7
/* 102DCC 7F0CE29C 2DA10005 */  sltiu $at, $t5, 5
/* 102DD0 7F0CE2A0 102000D3 */  beqz  $at, .L7F0CE5F0
/* 102DD4 7F0CE2A4 000D6880 */   sll   $t5, $t5, 2
/* 102DD8 7F0CE2A8 3C018006 */  lui   $at, %hi(tlb_ptr_C0_image_recall_types)
/* 102DDC 7F0CE2AC 002D0821 */  addu  $at, $at, $t5
/* 102DE0 7F0CE2B0 8C2DBF60 */  lw    $t5, %lo(tlb_ptr_C0_image_recall_types)($at)
/* 102DE4 7F0CE2B4 01A00008 */  jr    $t5
/* 102DE8 7F0CE2B8 00000000 */   nop   
.L7F0CE2BC:
/* 102DEC 7F0CE2BC 8E290004 */  lw    $t1, 4($s1)
/* 102DF0 7F0CE2C0 8EA40000 */  lw    $a0, ($s5)
/* 102DF4 7F0CE2C4 00033582 */  srl   $a2, $v1, 0x16
/* 102DF8 7F0CE2C8 00097602 */  srl   $t6, $t1, 0x18
/* 102DFC 7F0CE2CC 31C900FF */  andi  $t1, $t6, 0xff
/* 102E00 7F0CE2D0 00033D02 */  srl   $a3, $v1, 0x14
/* 102E04 7F0CE2D4 00034482 */  srl   $t0, $v1, 0x12
/* 102E08 7F0CE2D8 00035382 */  srl   $t2, $v1, 0xe
/* 102E0C 7F0CE2DC 00035A82 */  srl   $t3, $v1, 0xa
/* 102E10 7F0CE2E0 30D80003 */  andi  $t8, $a2, 3
/* 102E14 7F0CE2E4 30F90003 */  andi  $t9, $a3, 3
/* 102E18 7F0CE2E8 310D0003 */  andi  $t5, $t0, 3
/* 102E1C 7F0CE2EC 314E000F */  andi  $t6, $t2, 0xf
/* 102E20 7F0CE2F0 316F000F */  andi  $t7, $t3, 0xf
/* 102E24 7F0CE2F4 03003025 */  move  $a2, $t8
/* 102E28 7F0CE2F8 03203825 */  move  $a3, $t9
/* 102E2C 7F0CE2FC 01A04025 */  move  $t0, $t5
/* 102E30 7F0CE300 01C05025 */  move  $t2, $t6
/* 102E34 7F0CE304 1080001B */  beqz  $a0, .L7F0CE374
/* 102E38 7F0CE308 01E05825 */   move  $t3, $t7
/* 102E3C 7F0CE30C 00131880 */  sll   $v1, $s3, 2
/* 102E40 7F0CE310 00831021 */  addu  $v0, $a0, $v1
/* 102E44 7F0CE314 90580000 */  lbu   $t8, ($v0)
/* 102E48 7F0CE318 240100FF */  li    $at, 255
/* 102E4C 7F0CE31C 17010015 */  bne   $t8, $at, .L7F0CE374
/* 102E50 7F0CE320 00000000 */   nop   
/* 102E54 7F0CE324 A0490000 */  sb    $t1, ($v0)
/* 102E58 7F0CE328 8EB90000 */  lw    $t9, ($s5)
/* 102E5C 7F0CE32C 2404000F */  li    $a0, 15
/* 102E60 7F0CE330 008E6823 */  subu  $t5, $a0, $t6
/* 102E64 7F0CE334 03231021 */  addu  $v0, $t9, $v1
/* 102E68 7F0CE338 90590001 */  lbu   $t9, 1($v0)
/* 102E6C 7F0CE33C 01A07025 */  move  $t6, $t5
/* 102E70 7F0CE340 000EC140 */  sll   $t8, $t6, 5
/* 102E74 7F0CE344 332DFF1F */  andi  $t5, $t9, 0xff1f
/* 102E78 7F0CE348 030D7025 */  or    $t6, $t8, $t5
/* 102E7C 7F0CE34C A04E0001 */  sb    $t6, 1($v0)
/* 102E80 7F0CE350 8EAF0000 */  lw    $t7, ($s5)
/* 102E84 7F0CE354 008BC023 */  subu  $t8, $a0, $t3
/* 102E88 7F0CE358 00186880 */  sll   $t5, $t8, 2
/* 102E8C 7F0CE35C 01E31021 */  addu  $v0, $t7, $v1
/* 102E90 7F0CE360 904F0001 */  lbu   $t7, 1($v0)
/* 102E94 7F0CE364 31AE001C */  andi  $t6, $t5, 0x1c
/* 102E98 7F0CE368 31F9FFE3 */  andi  $t9, $t7, 0xffe3
/* 102E9C 7F0CE36C 01D9C025 */  or    $t8, $t6, $t9
/* 102EA0 7F0CE370 A0580001 */  sb    $t8, 1($v0)
.L7F0CE374:
/* 102EA4 7F0CE374 12800024 */  beqz  $s4, .L7F0CE408
/* 102EA8 7F0CE378 02002025 */   move  $a0, $s0
/* 102EAC 7F0CE37C 8EAD0000 */  lw    $t5, ($s5)
/* 102EB0 7F0CE380 00137880 */  sll   $t7, $s3, 2
/* 102EB4 7F0CE384 AFA80010 */  sw    $t0, 0x10($sp)
/* 102EB8 7F0CE388 01AF1021 */  addu  $v0, $t5, $t7
/* 102EBC 7F0CE38C 904E0001 */  lbu   $t6, 1($v0)
/* 102EC0 7F0CE390 02002025 */  move  $a0, $s0
/* 102EC4 7F0CE394 02402825 */  move  $a1, $s2
/* 102EC8 7F0CE398 000EC942 */  srl   $t9, $t6, 5
/* 102ECC 7F0CE39C 02F9C023 */  subu  $t8, $s7, $t9
/* 102ED0 7F0CE3A0 AFB80014 */  sw    $t8, 0x14($sp)
/* 102ED4 7F0CE3A4 8C4D0000 */  lw    $t5, ($v0)
/* 102ED8 7F0CE3A8 000D7AC0 */  sll   $t7, $t5, 0xb
/* 102EDC 7F0CE3AC 000F7742 */  srl   $t6, $t7, 0x1d
/* 102EE0 7F0CE3B0 02EEC823 */  subu  $t9, $s7, $t6
/* 102EE4 7F0CE3B4 AFB90018 */  sw    $t9, 0x18($sp)
/* 102EE8 7F0CE3B8 90580000 */  lbu   $t8, ($v0)
/* 102EEC 7F0CE3BC 0FC337EA */  jal   sub_GAME_7F0CDFA8
/* 102EF0 7F0CE3C0 AFB8001C */   sw    $t8, 0x1c($sp)
/* 102EF4 7F0CE3C4 3C0DBA00 */  lui   $t5, (0xBA001402 >> 16) # lui $t5, 0xba00
/* 102EF8 7F0CE3C8 35AD1402 */  ori   $t5, (0xBA001402 & 0xFFFF) # ori $t5, $t5, 0x1402
/* 102EFC 7F0CE3CC AC4D0000 */  sw    $t5, ($v0)
/* 102F00 7F0CE3D0 3C0EBA00 */  lui   $t6, (0xBA001001 >> 16) # lui $t6, 0xba00
/* 102F04 7F0CE3D4 3C18BA00 */  lui   $t8, (0xBA001102 >> 16) # lui $t8, 0xba00
/* 102F08 7F0CE3D8 3C0F0010 */  lui   $t7, 0x10
/* 102F0C 7F0CE3DC 35CE1001 */  ori   $t6, (0xBA001001 & 0xFFFF) # ori $t6, $t6, 0x1001
/* 102F10 7F0CE3E0 3C190001 */  lui   $t9, 1
/* 102F14 7F0CE3E4 37181102 */  ori   $t8, (0xBA001102 & 0xFFFF) # ori $t8, $t8, 0x1102
/* 102F18 7F0CE3E8 3C0D0004 */  lui   $t5, 4
/* 102F1C 7F0CE3EC AC4F0004 */  sw    $t7, 4($v0)
/* 102F20 7F0CE3F0 AC59000C */  sw    $t9, 0xc($v0)
/* 102F24 7F0CE3F4 AC4E0008 */  sw    $t6, 8($v0)
/* 102F28 7F0CE3F8 AC4D0014 */  sw    $t5, 0x14($v0)
/* 102F2C 7F0CE3FC AC580010 */  sw    $t8, 0x10($v0)
/* 102F30 7F0CE400 1000007B */  b     .L7F0CE5F0
/* 102F34 7F0CE404 24500018 */   addiu $s0, $v0, 0x18
.L7F0CE408:
/* 102F38 7F0CE408 02402825 */  move  $a1, $s2
/* 102F3C 7F0CE40C AFA80010 */  sw    $t0, 0x10($sp)
/* 102F40 7F0CE410 AFAA0014 */  sw    $t2, 0x14($sp)
/* 102F44 7F0CE414 AFAB0018 */  sw    $t3, 0x18($sp)
/* 102F48 7F0CE418 0FC337EA */  jal   sub_GAME_7F0CDFA8
/* 102F4C 7F0CE41C AFA9001C */   sw    $t1, 0x1c($sp)
/* 102F50 7F0CE420 10000073 */  b     .L7F0CE5F0
/* 102F54 7F0CE424 00408025 */   move  $s0, $v0
.L7F0CE428:
/* 102F58 7F0CE428 8E240004 */  lw    $a0, 4($s1)
/* 102F5C 7F0CE42C 02C02825 */  move  $a1, $s6
/* 102F60 7F0CE430 00047B02 */  srl   $t7, $a0, 0xc
/* 102F64 7F0CE434 31E40FFF */  andi  $a0, $t7, 0xfff
/* 102F68 7F0CE438 0FC32FBA */  jal   sub_GAME_7F0CBEE8
/* 102F6C 7F0CE43C AFA40080 */   sw    $a0, 0x80($sp)
/* 102F70 7F0CE440 8FA40080 */  lw    $a0, 0x80($sp)
/* 102F74 7F0CE444 0FC32EC3 */  jal   sub_GAME_7F0CBB0C
/* 102F78 7F0CE448 02C02825 */   move  $a1, $s6
/* 102F7C 7F0CE44C 10400068 */  beqz  $v0, .L7F0CE5F0
/* 102F80 7F0CE450 02002025 */   move  $a0, $s0
/* 102F84 7F0CE454 8E230000 */  lw    $v1, ($s1)
/* 102F88 7F0CE458 8E290004 */  lw    $t1, 4($s1)
/* 102F8C 7F0CE45C AFA20014 */  sw    $v0, 0x14($sp)
/* 102F90 7F0CE460 00033582 */  srl   $a2, $v1, 0x16
/* 102F94 7F0CE464 0009CE02 */  srl   $t9, $t1, 0x18
/* 102F98 7F0CE468 332900FF */  andi  $t1, $t9, 0xff
/* 102F9C 7F0CE46C 00033D02 */  srl   $a3, $v1, 0x14
/* 102FA0 7F0CE470 00034482 */  srl   $t0, $v1, 0x12
/* 102FA4 7F0CE474 00035382 */  srl   $t2, $v1, 0xe
/* 102FA8 7F0CE478 00035A82 */  srl   $t3, $v1, 0xa
/* 102FAC 7F0CE47C 30CD0003 */  andi  $t5, $a2, 3
/* 102FB0 7F0CE480 30EF0003 */  andi  $t7, $a3, 3
/* 102FB4 7F0CE484 310E0003 */  andi  $t6, $t0, 3
/* 102FB8 7F0CE488 3159000F */  andi  $t9, $t2, 0xf
/* 102FBC 7F0CE48C 3178000F */  andi  $t8, $t3, 0xf
/* 102FC0 7F0CE490 01A03025 */  move  $a2, $t5
/* 102FC4 7F0CE494 01E03825 */  move  $a3, $t7
/* 102FC8 7F0CE498 AFB8001C */  sw    $t8, 0x1c($sp)
/* 102FCC 7F0CE49C AFB90018 */  sw    $t9, 0x18($sp)
/* 102FD0 7F0CE4A0 AFAE0010 */  sw    $t6, 0x10($sp)
/* 102FD4 7F0CE4A4 AFA90020 */  sw    $t1, 0x20($sp)
/* 102FD8 7F0CE4A8 0FC337AA */  jal   sub_GAME_7F0CDEA8
/* 102FDC 7F0CE4AC 02402825 */   move  $a1, $s2
/* 102FE0 7F0CE4B0 1000004F */  b     .L7F0CE5F0
/* 102FE4 7F0CE4B4 00408025 */   move  $s0, $v0
.L7F0CE4B8:
/* 102FE8 7F0CE4B8 00033582 */  srl   $a2, $v1, 0x16
/* 102FEC 7F0CE4BC 00033D02 */  srl   $a3, $v1, 0x14
/* 102FF0 7F0CE4C0 00034482 */  srl   $t0, $v1, 0x12
/* 102FF4 7F0CE4C4 30CD0003 */  andi  $t5, $a2, 3
/* 102FF8 7F0CE4C8 30EF0003 */  andi  $t7, $a3, 3
/* 102FFC 7F0CE4CC 310E0003 */  andi  $t6, $t0, 3
/* 103000 7F0CE4D0 01A03025 */  move  $a2, $t5
/* 103004 7F0CE4D4 01E03825 */  move  $a3, $t7
/* 103008 7F0CE4D8 12800024 */  beqz  $s4, .L7F0CE56C
/* 10300C 7F0CE4DC 01C04025 */   move  $t0, $t6
/* 103010 7F0CE4E0 8EB90000 */  lw    $t9, ($s5)
/* 103014 7F0CE4E4 0013C080 */  sll   $t8, $s3, 2
/* 103018 7F0CE4E8 AFAE0010 */  sw    $t6, 0x10($sp)
/* 10301C 7F0CE4EC 03381021 */  addu  $v0, $t9, $t8
/* 103020 7F0CE4F0 904D0001 */  lbu   $t5, 1($v0)
/* 103024 7F0CE4F4 02002025 */  move  $a0, $s0
/* 103028 7F0CE4F8 02402825 */  move  $a1, $s2
/* 10302C 7F0CE4FC 000D7942 */  srl   $t7, $t5, 5
/* 103030 7F0CE500 02EF7023 */  subu  $t6, $s7, $t7
/* 103034 7F0CE504 AFAE0014 */  sw    $t6, 0x14($sp)
/* 103038 7F0CE508 8C590000 */  lw    $t9, ($v0)
/* 10303C 7F0CE50C 0019C2C0 */  sll   $t8, $t9, 0xb
/* 103040 7F0CE510 00186F42 */  srl   $t5, $t8, 0x1d
/* 103044 7F0CE514 02ED7823 */  subu  $t7, $s7, $t5
/* 103048 7F0CE518 AFAF0018 */  sw    $t7, 0x18($sp)
/* 10304C 7F0CE51C 904E0000 */  lbu   $t6, ($v0)
/* 103050 7F0CE520 0FC337EA */  jal   sub_GAME_7F0CDFA8
/* 103054 7F0CE524 AFAE001C */   sw    $t6, 0x1c($sp)
/* 103058 7F0CE528 3C19BA00 */  lui   $t9, (0xBA001402 >> 16) # lui $t9, 0xba00
/* 10305C 7F0CE52C 37391402 */  ori   $t9, (0xBA001402 & 0xFFFF) # ori $t9, $t9, 0x1402
/* 103060 7F0CE530 AC590000 */  sw    $t9, ($v0)
/* 103064 7F0CE534 3C0DBA00 */  lui   $t5, (0xBA001001 >> 16) # lui $t5, 0xba00
/* 103068 7F0CE538 3C0EBA00 */  lui   $t6, (0xBA001102 >> 16) # lui $t6, 0xba00
/* 10306C 7F0CE53C 3C180010 */  lui   $t8, 0x10
/* 103070 7F0CE540 35AD1001 */  ori   $t5, (0xBA001001 & 0xFFFF) # ori $t5, $t5, 0x1001
/* 103074 7F0CE544 3C0F0001 */  lui   $t7, 1
/* 103078 7F0CE548 35CE1102 */  ori   $t6, (0xBA001102 & 0xFFFF) # ori $t6, $t6, 0x1102
/* 10307C 7F0CE54C 3C190004 */  lui   $t9, 4
/* 103080 7F0CE550 AC580004 */  sw    $t8, 4($v0)
/* 103084 7F0CE554 AC4F000C */  sw    $t7, 0xc($v0)
/* 103088 7F0CE558 AC4D0008 */  sw    $t5, 8($v0)
/* 10308C 7F0CE55C AC590014 */  sw    $t9, 0x14($v0)
/* 103090 7F0CE560 AC4E0010 */  sw    $t6, 0x10($v0)
/* 103094 7F0CE564 10000022 */  b     .L7F0CE5F0
/* 103098 7F0CE568 24500018 */   addiu $s0, $v0, 0x18
.L7F0CE56C:
/* 10309C 7F0CE56C 02002025 */  move  $a0, $s0
/* 1030A0 7F0CE570 02402825 */  move  $a1, $s2
/* 1030A4 7F0CE574 0FC33786 */  jal   sub_GAME_7F0CDE18
/* 1030A8 7F0CE578 AFA80010 */   sw    $t0, 0x10($sp)
/* 1030AC 7F0CE57C 1000001C */  b     .L7F0CE5F0
/* 1030B0 7F0CE580 00408025 */   move  $s0, $v0
.L7F0CE584:
/* 1030B4 7F0CE584 00033582 */  srl   $a2, $v1, 0x16
/* 1030B8 7F0CE588 00033D02 */  srl   $a3, $v1, 0x14
/* 1030BC 7F0CE58C 00034482 */  srl   $t0, $v1, 0x12
/* 1030C0 7F0CE590 30D80003 */  andi  $t8, $a2, 3
/* 1030C4 7F0CE594 30ED0003 */  andi  $t5, $a3, 3
/* 1030C8 7F0CE598 310F0003 */  andi  $t7, $t0, 3
/* 1030CC 7F0CE59C 03003025 */  move  $a2, $t8
/* 1030D0 7F0CE5A0 01A03825 */  move  $a3, $t5
/* 1030D4 7F0CE5A4 AFAF0010 */  sw    $t7, 0x10($sp)
/* 1030D8 7F0CE5A8 02002025 */  move  $a0, $s0
/* 1030DC 7F0CE5AC 0FC3382B */  jal   sub_GAME_7F0CE0AC
/* 1030E0 7F0CE5B0 02402825 */   move  $a1, $s2
/* 1030E4 7F0CE5B4 1000000E */  b     .L7F0CE5F0
/* 1030E8 7F0CE5B8 00408025 */   move  $s0, $v0
.L7F0CE5BC:
/* 1030EC 7F0CE5BC 00033582 */  srl   $a2, $v1, 0x16
/* 1030F0 7F0CE5C0 00033D02 */  srl   $a3, $v1, 0x14
/* 1030F4 7F0CE5C4 00034482 */  srl   $t0, $v1, 0x12
/* 1030F8 7F0CE5C8 30CE0003 */  andi  $t6, $a2, 3
/* 1030FC 7F0CE5CC 30F90003 */  andi  $t9, $a3, 3
/* 103100 7F0CE5D0 31180003 */  andi  $t8, $t0, 3
/* 103104 7F0CE5D4 01C03025 */  move  $a2, $t6
/* 103108 7F0CE5D8 03203825 */  move  $a3, $t9
/* 10310C 7F0CE5DC AFB80010 */  sw    $t8, 0x10($sp)
/* 103110 7F0CE5E0 02002025 */  move  $a0, $s0
/* 103114 7F0CE5E4 0FC33819 */  jal   sub_GAME_7F0CE064
/* 103118 7F0CE5E8 02402825 */   move  $a1, $s2
/* 10311C 7F0CE5EC 00408025 */  move  $s0, $v0
def_7F0CE2B4:
.L7F0CE5F0:
/* 103120 7F0CE5F0 240105E4 */  li    $at, 1508
/* 103124 7F0CE5F4 16610005 */  bne   $s3, $at, .L7F0CE60C
/* 103128 7F0CE5F8 02002025 */   move  $a0, $s0
/* 10312C 7F0CE5FC 0FC24D0F */  jal   sub_GAME_7F09343C
/* 103130 7F0CE600 24050001 */   li    $a1, 1
/* 103134 7F0CE604 0FC33132 */  jal   sub_GAME_7F0CC4C8
/* 103138 7F0CE608 00408025 */   move  $s0, $v0
.L7F0CE60C:
/* 10313C 7F0CE60C 240105E7 */  li    $at, 1511
/* 103140 7F0CE610 16610005 */  bne   $s3, $at, .L7F0CE628
/* 103144 7F0CE614 02002025 */   move  $a0, $s0
/* 103148 7F0CE618 0FC24D97 */  jal   sub_GAME_7F09365C
/* 10314C 7F0CE61C 24050001 */   li    $a1, 1
/* 103150 7F0CE620 0FC33132 */  jal   sub_GAME_7F0CC4C8
/* 103154 7F0CE624 00408025 */   move  $s0, $v0
.L7F0CE628:
/* 103158 7F0CE628 0FC2ED8C */  jal   check_if_imageID_is_light
/* 10315C 7F0CE62C 02602025 */   move  $a0, $s3
/* 103160 7F0CE630 10400004 */  beqz  $v0, .L7F0CE644
/* 103164 7F0CE634 02002025 */   move  $a0, $s0
/* 103168 7F0CE638 240D0001 */  li    $t5, 1
/* 10316C 7F0CE63C 0FC2ED67 */  jal   add_entry_to_init_lightfixture_table
/* 103170 7F0CE640 AFAD0058 */   sw    $t5, 0x58($sp)
.L7F0CE644:
/* 103174 7F0CE644 1000003C */  b     .L7F0CE738
/* 103178 7F0CE648 26310008 */   addiu $s1, $s1, 8
/* 10317C 7F0CE64C 8E210000 */  lw    $at, ($s1)
.L7F0CE650:
/* 103180 7F0CE650 241E0001 */  li    $fp, 1
/* 103184 7F0CE654 26100008 */  addiu $s0, $s0, 8
/* 103188 7F0CE658 AE01FFF8 */  sw    $at, -8($s0)
/* 10318C 7F0CE65C 8E390004 */  lw    $t9, 4($s1)
/* 103190 7F0CE660 26310008 */  addiu $s1, $s1, 8
/* 103194 7F0CE664 10000034 */  b     .L7F0CE738
/* 103198 7F0CE668 AE19FFFC */   sw    $t9, -4($s0)
.L7F0CE66C:
/* 10319C 7F0CE66C 24180001 */  li    $t8, 1
/* 1031A0 7F0CE670 AFB8005C */  sw    $t8, 0x5c($sp)
/* 1031A4 7F0CE674 8E210000 */  lw    $at, ($s1)
/* 1031A8 7F0CE678 0000F025 */  move  $fp, $zero
/* 1031AC 7F0CE67C 26100008 */  addiu $s0, $s0, 8
/* 1031B0 7F0CE680 AE01FFF8 */  sw    $at, -8($s0)
/* 1031B4 7F0CE684 8E2F0004 */  lw    $t7, 4($s1)
/* 1031B8 7F0CE688 26310008 */  addiu $s1, $s1, 8
/* 1031BC 7F0CE68C 1000002A */  b     .L7F0CE738
/* 1031C0 7F0CE690 AE0FFFFC */   sw    $t7, -4($s0)
.L7F0CE694:
/* 1031C4 7F0CE694 AFB0008C */  sw    $s0, 0x8c($sp)
/* 1031C8 7F0CE698 AFA0005C */  sw    $zero, 0x5c($sp)
/* 1031CC 7F0CE69C 8E210000 */  lw    $at, ($s1)
/* 1031D0 7F0CE6A0 26100008 */  addiu $s0, $s0, 8
/* 1031D4 7F0CE6A4 26310008 */  addiu $s1, $s1, 8
/* 1031D8 7F0CE6A8 AE01FFF8 */  sw    $at, -8($s0)
/* 1031DC 7F0CE6AC 8E2EFFFC */  lw    $t6, -4($s1)
/* 1031E0 7F0CE6B0 10000021 */  b     .L7F0CE738
/* 1031E4 7F0CE6B4 AE0EFFFC */   sw    $t6, -4($s0)
.L7F0CE6B8:
/* 1031E8 7F0CE6B8 52800013 */  beql  $s4, $zero, .L7F0CE708
/* 1031EC 7F0CE6BC 8E210000 */   lw    $at, ($s1)
/* 1031F0 7F0CE6C0 82220002 */  lb    $v0, 2($s1)
/* 1031F4 7F0CE6C4 24010011 */  li    $at, 17
/* 1031F8 7F0CE6C8 10410005 */  beq   $v0, $at, .L7F0CE6E0
/* 1031FC 7F0CE6CC 24010014 */   li    $at, 20
/* 103200 7F0CE6D0 10410003 */  beq   $v0, $at, .L7F0CE6E0
/* 103204 7F0CE6D4 24010010 */   li    $at, 16
/* 103208 7F0CE6D8 54410004 */  bnel  $v0, $at, .L7F0CE6EC
/* 10320C 7F0CE6DC 8E210000 */   lw    $at, ($s1)
.L7F0CE6E0:
/* 103210 7F0CE6E0 10000015 */  b     .L7F0CE738
/* 103214 7F0CE6E4 26310008 */   addiu $s1, $s1, 8
/* 103218 7F0CE6E8 8E210000 */  lw    $at, ($s1)
.L7F0CE6EC:
/* 10321C 7F0CE6EC 26100008 */  addiu $s0, $s0, 8
/* 103220 7F0CE6F0 26310008 */  addiu $s1, $s1, 8
/* 103224 7F0CE6F4 AE01FFF8 */  sw    $at, -8($s0)
/* 103228 7F0CE6F8 8E2FFFFC */  lw    $t7, -4($s1)
/* 10322C 7F0CE6FC 1000000E */  b     .L7F0CE738
/* 103230 7F0CE700 AE0FFFFC */   sw    $t7, -4($s0)
/* 103234 7F0CE704 8E210000 */  lw    $at, ($s1)
.L7F0CE708:
/* 103238 7F0CE708 26100008 */  addiu $s0, $s0, 8
/* 10323C 7F0CE70C 26310008 */  addiu $s1, $s1, 8
/* 103240 7F0CE710 AE01FFF8 */  sw    $at, -8($s0)
/* 103244 7F0CE714 8E39FFFC */  lw    $t9, -4($s1)
/* 103248 7F0CE718 10000007 */  b     .L7F0CE738
/* 10324C 7F0CE71C AE19FFFC */   sw    $t9, -4($s0)
.L7F0CE720:
/* 103250 7F0CE720 8E210000 */  lw    $at, ($s1)
.L7F0CE724:
/* 103254 7F0CE724 26100008 */  addiu $s0, $s0, 8
/* 103258 7F0CE728 26310008 */  addiu $s1, $s1, 8
/* 10325C 7F0CE72C AE01FFF8 */  sw    $at, -8($s0)
/* 103260 7F0CE730 8E2DFFFC */  lw    $t5, -4($s1)
/* 103264 7F0CE734 AE0DFFFC */  sw    $t5, -4($s0)
.L7F0CE738:
/* 103268 7F0CE738 8FAF0088 */  lw    $t7, 0x88($sp)
/* 10326C 7F0CE73C 25F8FFFF */  addiu $t8, $t7, -1
/* 103270 7F0CE740 1F00FE94 */  bgtz  $t8, .L7F0CE194
/* 103274 7F0CE744 AFB80088 */   sw    $t8, 0x88($sp)
.L7F0CE748:
/* 103278 7F0CE748 8FB90058 */  lw    $t9, 0x58($sp)
/* 10327C 7F0CE74C 53200004 */  beql  $t9, $zero, .L7F0CE760
/* 103280 7F0CE750 8FAE00A0 */   lw    $t6, 0xa0($sp)
/* 103284 7F0CE754 0FC2ED80 */  jal   save_ptrDL_enpoint_to_current_init_lightfixture_table
/* 103288 7F0CE758 02002025 */   move  $a0, $s0
/* 10328C 7F0CE75C 8FAE00A0 */  lw    $t6, 0xa0($sp)
.L7F0CE760:
/* 103290 7F0CE760 8FBF0054 */  lw    $ra, 0x54($sp)
/* 103294 7F0CE764 8FB10034 */  lw    $s1, 0x34($sp)
/* 103298 7F0CE768 020E1023 */  subu  $v0, $s0, $t6
/* 10329C 7F0CE76C 8FB00030 */  lw    $s0, 0x30($sp)
/* 1032A0 7F0CE770 8FB20038 */  lw    $s2, 0x38($sp)
/* 1032A4 7F0CE774 8FB3003C */  lw    $s3, 0x3c($sp)
/* 1032A8 7F0CE778 8FB40040 */  lw    $s4, 0x40($sp)
/* 1032AC 7F0CE77C 8FB50044 */  lw    $s5, 0x44($sp)
/* 1032B0 7F0CE780 8FB60048 */  lw    $s6, 0x48($sp)
/* 1032B4 7F0CE784 8FB7004C */  lw    $s7, 0x4c($sp)
/* 1032B8 7F0CE788 8FBE0050 */  lw    $fp, 0x50($sp)
/* 1032BC 7F0CE78C 03E00008 */  jr    $ra
/* 1032C0 7F0CE790 27BD0098 */   addiu $sp, $sp, 0x98
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0CE794(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0CE794
/* 1032C4 7F0CE794 000670C3 */  sra   $t6, $a2, 3
/* 1032C8 7F0CE798 25C2FFFF */  addiu $v0, $t6, -1
/* 1032CC 7F0CE79C 01C03025 */  move  $a2, $t6
/* 1032D0 7F0CE7A0 000218C0 */  sll   $v1, $v0, 3
/* 1032D4 7F0CE7A4 00642021 */  addu  $a0, $v1, $a0
/* 1032D8 7F0CE7A8 00652821 */  addu  $a1, $v1, $a1
/* 1032DC 7F0CE7AC 01C03825 */  move  $a3, $t6
/* 1032E0 7F0CE7B0 10C0000A */  beqz  $a2, .L7F0CE7DC
/* 1032E4 7F0CE7B4 00403025 */   move  $a2, $v0
.L7F0CE7B8:
/* 1032E8 7F0CE7B8 8C980000 */  lw    $t8, ($a0)
/* 1032EC 7F0CE7BC 8C990004 */  lw    $t9, 4($a0)
/* 1032F0 7F0CE7C0 00C03825 */  move  $a3, $a2
/* 1032F4 7F0CE7C4 24A5FFF8 */  addiu $a1, $a1, -8
/* 1032F8 7F0CE7C8 2484FFF8 */  addiu $a0, $a0, -8
/* 1032FC 7F0CE7CC ACB80008 */  sw    $t8, 8($a1)
/* 103300 7F0CE7D0 ACB9000C */  sw    $t9, 0xc($a1)
/* 103304 7F0CE7D4 14C0FFF8 */  bnez  $a2, .L7F0CE7B8
/* 103308 7F0CE7D8 24C6FFFF */   addiu $a2, $a2, -1
.L7F0CE7DC:
/* 10330C 7F0CE7DC 03E00008 */  jr    $ra
/* 103310 7F0CE7E0 00000000 */   nop   
)
#endif




