#include "ultra64.h"
#include "game/unk_093880.h"
#include "game/unk_092E50.h"
#include "game/bond.h"
#include "game/lvl.h"

// bss
s32 copyof_stagenum;
s32 dword_CODE_bss_80079E94;
char dword_CODE_bss_80079E98[0x48];
struct player *players[4];

struct player_data player1_player_data;
struct player_data player2_player_data;
struct player_data player3_player_data;
struct player_data player4_player_data;

struct player *pPlayer;
struct player_data *pPlayersPerm;
s32 player_num;
s32 random_byte;
s32 dword_CODE_bss_8007A0C0;
s32 dword_CODE_bss_8007A0C4;
s32 dword_CODE_bss_8007A0C8;
s32 dword_CODE_bss_8007A0CC;




#ifdef NONMATCHING
void sub_GAME_7F093880(f32 arg0, f32 arg1, ? arg2) {
    f32 sp18;
    f32 sp1C;
    f32 sp20;
    s32 sp24;

    // Node 0
    sp24 = currentPlayerGetMatrix10D4();
    sp1C = (f32) (getPlayer_c_screenleft() + arg0);
    sp18 = getPlayer_c_screentop();
    sp20 = (f32) (get_ptr_currentdata()->unk38 + (arg1 + sp18));
    sub_GAME_7F077EEC(&sp1C, arg2, 0x42c80000);
    return matrix_4x4_rotate_vector_in_place(sp24, arg2);
}

#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F093880
/* 0C83B0 7F093880 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 0C83B4 7F093884 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0C83B8 7F093888 E7AC0028 */  swc1  $f12, 0x28($sp)
/* 0C83BC 7F09388C E7AE002C */  swc1  $f14, 0x2c($sp)
/* 0C83C0 7F093890 0FC1E111 */  jal   currentPlayerGetMatrix10D4
/* 0C83C4 7F093894 AFA60030 */   sw    $a2, 0x30($sp)
/* 0C83C8 7F093898 0FC1E131 */  jal   getPlayer_c_screenleft
/* 0C83CC 7F09389C AFA20024 */   sw    $v0, 0x24($sp)
/* 0C83D0 7F0938A0 C7A40028 */  lwc1  $f4, 0x28($sp)
/* 0C83D4 7F0938A4 46040180 */  add.s $f6, $f0, $f4
/* 0C83D8 7F0938A8 0FC1E135 */  jal   getPlayer_c_screentop
/* 0C83DC 7F0938AC E7A6001C */   swc1  $f6, 0x1c($sp)
/* 0C83E0 7F0938B0 0FC2E9CB */  jal   get_ptr_currentdata
/* 0C83E4 7F0938B4 E7A00018 */   swc1  $f0, 0x18($sp)
/* 0C83E8 7F0938B8 C7A8002C */  lwc1  $f8, 0x2c($sp)
/* 0C83EC 7F0938BC C7AA0018 */  lwc1  $f10, 0x18($sp)
/* 0C83F0 7F0938C0 C4520038 */  lwc1  $f18, 0x38($v0)
/* 0C83F4 7F0938C4 27A4001C */  addiu $a0, $sp, 0x1c
/* 0C83F8 7F0938C8 460A4400 */  add.s $f16, $f8, $f10
/* 0C83FC 7F0938CC 8FA50030 */  lw    $a1, 0x30($sp)
/* 0C8400 7F0938D0 3C0642C8 */  lui   $a2, 0x42c8
/* 0C8404 7F0938D4 46109100 */  add.s $f4, $f18, $f16
/* 0C8408 7F0938D8 0FC1DFBB */  jal   sub_GAME_7F077EEC
/* 0C840C 7F0938DC E7A40020 */   swc1  $f4, 0x20($sp)
/* 0C8410 7F0938E0 8FA40024 */  lw    $a0, 0x24($sp)
/* 0C8414 7F0938E4 0FC160F6 */  jal   matrix_4x4_rotate_vector_in_place
/* 0C8418 7F0938E8 8FA50030 */   lw    $a1, 0x30($sp)
/* 0C841C 7F0938EC 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0C8420 7F0938F0 27BD0028 */  addiu $sp, $sp, 0x28
/* 0C8424 7F0938F4 03E00008 */  jr    $ra
/* 0C8428 7F0938F8 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
f32 sub_GAME_7F0938FC(void *arg0, void *arg1, void *arg2) {
    f32 sp24;
    f32 sp2C;
    s32 temp_s1;
    f32 temp_f12;
    f32 temp_f2;
    f32 temp_f12_2;
    f32 phi_f12;
    f32 phi_f16;
    f32 phi_f2;
    f32 phi_return;

    // Node 0
    temp_s1 = get_BONDdata_position();
    temp_f12 = ((arg0->unk4 + arg0->unk4) / sqrtf((((arg0->unk8 * arg0->unk8) + (*arg0 * *arg0)) + D_80057520), *arg0));
    phi_f12 = temp_f12;
    if (1.0f < temp_f12)
    {
        // Node 1
        phi_f12 = 1.0f;
    }
    // Node 2
    *arg2 = (f32) (1.0f - phi_f12);
    if (0.0f == arg0->unk4)
    {
        // Node 3
        phi_f16 = D_80057524;
    }
    else
    {
        // Node 4
        phi_f16 = arg0->unk4;
    }
    // Node 5
    phi_return = 0.0f;
    if (0.0f < phi_f16)
    {
        // Node 6
        sp24 = (f32) phi_f16;
        temp_f2 = ((get_ptr_currentdata(phi_f12, 1.0f)->unkC - temp_s1->unk4) / phi_f16);
        sp2C = temp_f2;
        temp_f12_2 = (sqrtf(((arg0->unk8 * arg0->unk8) + (*arg0 * *arg0)), *arg0) * temp_f2);
        phi_f2 = temp_f2;
        if (D_80057528 < temp_f12_2)
        {
            // Node 7
            phi_f2 = (temp_f2 * (D_80057528 / temp_f12_2));
        }
        // Node 8
        *arg1 = (f32) ((*arg0 * phi_f2) + *temp_s1);
        arg1->unk4 = (f32) (temp_s1->unk4 + (phi_f2 * phi_f16));
        arg1->unk8 = (f32) ((arg0->unk8 * phi_f2) + temp_s1->unk8);
        phi_return = 1.401298464324817e-45f;
    }
    // Node 9
    return phi_return;
}
#else
GLOBAL_ASM(
.late_rodata
glabel D_80057520
.word 0x38d1b717 /*0.000099999997*/
glabel D_80057524
.word 0x3c23d70a /*0.0099999998*/
glabel D_80057528
.word 0x48927c00 /*300000.0*/
.text
glabel sub_GAME_7F0938FC
/* 0C842C 7F0938FC 27BDFFC8 */  addiu $sp, $sp, -0x38
/* 0C8430 7F093900 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0C8434 7F093904 AFB00014 */  sw    $s0, 0x14($sp)
/* 0C8438 7F093908 00808025 */  move  $s0, $a0
/* 0C843C 7F09390C AFB10018 */  sw    $s1, 0x18($sp)
/* 0C8440 7F093910 AFA5003C */  sw    $a1, 0x3c($sp)
/* 0C8444 7F093914 0FC227F5 */  jal   get_BONDdata_position
/* 0C8448 7F093918 AFA60040 */   sw    $a2, 0x40($sp)
/* 0C844C 7F09391C C6000008 */  lwc1  $f0, 8($s0)
/* 0C8450 7F093920 C60E0000 */  lwc1  $f14, ($s0)
/* 0C8454 7F093924 3C018005 */  lui   $at, %hi(D_80057520)
/* 0C8458 7F093928 46000102 */  mul.s $f4, $f0, $f0
/* 0C845C 7F09392C C42A7520 */  lwc1  $f10, %lo(D_80057520)($at)
/* 0C8460 7F093930 00408825 */  move  $s1, $v0
/* 0C8464 7F093934 460E7182 */  mul.s $f6, $f14, $f14
/* 0C8468 7F093938 46062200 */  add.s $f8, $f4, $f6
/* 0C846C 7F09393C 0C007DF8 */  jal   sqrtf
/* 0C8470 7F093940 460A4300 */   add.s $f12, $f8, $f10
/* 0C8474 7F093944 C6020004 */  lwc1  $f2, 4($s0)
/* 0C8478 7F093948 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0C847C 7F09394C 44817000 */  mtc1  $at, $f14
/* 0C8480 7F093950 46021100 */  add.s $f4, $f2, $f2
/* 0C8484 7F093954 3C018005 */  lui   $at, %hi(D_80057524)
/* 0C8488 7F093958 00001025 */  move  $v0, $zero
/* 0C848C 7F09395C 46002303 */  div.s $f12, $f4, $f0
/* 0C8490 7F093960 460C703C */  c.lt.s $f14, $f12
/* 0C8494 7F093964 00000000 */  nop   
/* 0C8498 7F093968 45020003 */  bc1fl .L7F093978
/* 0C849C 7F09396C 460C7181 */   sub.s $f6, $f14, $f12
/* 0C84A0 7F093970 46007306 */  mov.s $f12, $f14
/* 0C84A4 7F093974 460C7181 */  sub.s $f6, $f14, $f12
.L7F093978:
/* 0C84A8 7F093978 8FAE0040 */  lw    $t6, 0x40($sp)
/* 0C84AC 7F09397C 44800000 */  mtc1  $zero, $f0
/* 0C84B0 7F093980 E5C60000 */  swc1  $f6, ($t6)
/* 0C84B4 7F093984 C6020004 */  lwc1  $f2, 4($s0)
/* 0C84B8 7F093988 46020032 */  c.eq.s $f0, $f2
/* 0C84BC 7F09398C 00000000 */  nop   
/* 0C84C0 7F093990 45020004 */  bc1fl .L7F0939A4
/* 0C84C4 7F093994 46001406 */   mov.s $f16, $f2
/* 0C84C8 7F093998 10000002 */  b     .L7F0939A4
/* 0C84CC 7F09399C C4307524 */   lwc1  $f16, %lo(D_80057524)($at)
/* 0C84D0 7F0939A0 46001406 */  mov.s $f16, $f2
.L7F0939A4:
/* 0C84D4 7F0939A4 4610003C */  c.lt.s $f0, $f16
/* 0C84D8 7F0939A8 00000000 */  nop   
/* 0C84DC 7F0939AC 4500002D */  bc1f  .L7F093A64
/* 0C84E0 7F0939B0 00000000 */   nop   
/* 0C84E4 7F0939B4 0FC2E9CB */  jal   get_ptr_currentdata
/* 0C84E8 7F0939B8 E7B00024 */   swc1  $f16, 0x24($sp)
/* 0C84EC 7F0939BC C448000C */  lwc1  $f8, 0xc($v0)
/* 0C84F0 7F0939C0 C62A0004 */  lwc1  $f10, 4($s1)
/* 0C84F4 7F0939C4 C7B00024 */  lwc1  $f16, 0x24($sp)
/* 0C84F8 7F0939C8 C6000008 */  lwc1  $f0, 8($s0)
/* 0C84FC 7F0939CC 460A4101 */  sub.s $f4, $f8, $f10
/* 0C8500 7F0939D0 C60E0000 */  lwc1  $f14, ($s0)
/* 0C8504 7F0939D4 46000182 */  mul.s $f6, $f0, $f0
/* 0C8508 7F0939D8 00000000 */  nop   
/* 0C850C 7F0939DC 460E7202 */  mul.s $f8, $f14, $f14
/* 0C8510 7F0939E0 46102083 */  div.s $f2, $f4, $f16
/* 0C8514 7F0939E4 46083300 */  add.s $f12, $f6, $f8
/* 0C8518 7F0939E8 0C007DF8 */  jal   sqrtf
/* 0C851C 7F0939EC E7A2002C */   swc1  $f2, 0x2c($sp)
/* 0C8520 7F0939F0 C7A2002C */  lwc1  $f2, 0x2c($sp)
/* 0C8524 7F0939F4 3C018005 */  lui   $at, %hi(D_80057528)
/* 0C8528 7F0939F8 C4327528 */  lwc1  $f18, %lo(D_80057528)($at)
/* 0C852C 7F0939FC 46020302 */  mul.s $f12, $f0, $f2
/* 0C8530 7F093A00 C7B00024 */  lwc1  $f16, 0x24($sp)
/* 0C8534 7F093A04 460C903C */  c.lt.s $f18, $f12
/* 0C8538 7F093A08 00000000 */  nop   
/* 0C853C 7F093A0C 45020005 */  bc1fl .L7F093A24
/* 0C8540 7F093A10 C6040000 */   lwc1  $f4, ($s0)
/* 0C8544 7F093A14 460C9283 */  div.s $f10, $f18, $f12
/* 0C8548 7F093A18 460A1082 */  mul.s $f2, $f2, $f10
/* 0C854C 7F093A1C 00000000 */  nop   
/* 0C8550 7F093A20 C6040000 */  lwc1  $f4, ($s0)
.L7F093A24:
/* 0C8554 7F093A24 C6280000 */  lwc1  $f8, ($s1)
/* 0C8558 7F093A28 8FA3003C */  lw    $v1, 0x3c($sp)
/* 0C855C 7F093A2C 46022182 */  mul.s $f6, $f4, $f2
/* 0C8560 7F093A30 24020001 */  li    $v0, 1
/* 0C8564 7F093A34 46083280 */  add.s $f10, $f6, $f8
/* 0C8568 7F093A38 46101182 */  mul.s $f6, $f2, $f16
/* 0C856C 7F093A3C E46A0000 */  swc1  $f10, ($v1)
/* 0C8570 7F093A40 C6240004 */  lwc1  $f4, 4($s1)
/* 0C8574 7F093A44 46062200 */  add.s $f8, $f4, $f6
/* 0C8578 7F093A48 E4680004 */  swc1  $f8, 4($v1)
/* 0C857C 7F093A4C C60A0008 */  lwc1  $f10, 8($s0)
/* 0C8580 7F093A50 C6260008 */  lwc1  $f6, 8($s1)
/* 0C8584 7F093A54 46025102 */  mul.s $f4, $f10, $f2
/* 0C8588 7F093A58 46062200 */  add.s $f8, $f4, $f6
/* 0C858C 7F093A5C 10000001 */  b     .L7F093A64
/* 0C8590 7F093A60 E4680008 */   swc1  $f8, 8($v1)
.L7F093A64:
/* 0C8594 7F093A64 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0C8598 7F093A68 8FB00014 */  lw    $s0, 0x14($sp)
/* 0C859C 7F093A6C 8FB10018 */  lw    $s1, 0x18($sp)
/* 0C85A0 7F093A70 03E00008 */  jr    $ra
/* 0C85A4 7F093A74 27BD0038 */   addiu $sp, $sp, 0x38
)
#endif





#ifdef NONMATCHING
f32 sub_GAME_7F093A78(void *arg0, void *arg1, void *arg2) {
    f32 sp24;
    f32 sp2C;
    s32 temp_s1;
    f32 temp_f2_2;
    f32 temp_f2;
    f32 temp_f12;
    f32 phi_f2;
    f32 phi_f16;
    f32 phi_f2_2;
    f32 phi_return;

    // Node 0
    temp_s1 = get_BONDdata_position();
    temp_f2_2 = ((-2.0f * arg0->unk4) / sqrtf((((arg0->unk8 * arg0->unk8) + (*arg0 * *arg0)) + D_8005752C), *arg0));
    phi_f2 = temp_f2_2;
    if (1.0f < temp_f2_2)
    {
        // Node 1
        phi_f2 = 1.0f;
    }
    // Node 2
    *arg2 = (f32) (1.0f - phi_f2);
    if (0.0f == arg0->unk4)
    {
        // Node 3
        phi_f16 = D_80057530;
    }
    else
    {
        // Node 4
        phi_f16 = arg0->unk4;
    }
    // Node 5
    phi_return = arg0->unk4;
    if (phi_f16 < 0.0f)
    {
        // Node 6
        sp24 = (f32) phi_f16;
        temp_f2 = ((get_ptr_currentdata(1.0f, 0.0f)->unk24 - temp_s1->unk4) / phi_f16);
        sp2C = temp_f2;
        temp_f12 = (sqrtf(((arg0->unk8 * arg0->unk8) + (*arg0 * *arg0)), *arg0) * temp_f2);
        phi_f2_2 = temp_f2;
        if (D_80057534 < temp_f12)
        {
            // Node 7
            phi_f2_2 = (temp_f2 * (D_80057534 / temp_f12));
        }
        // Node 8
        *arg1 = (f32) ((*arg0 * phi_f2_2) + *temp_s1);
        arg1->unk4 = (f32) (temp_s1->unk4 + (phi_f2_2 * phi_f16));
        arg1->unk8 = (f32) ((arg0->unk8 * phi_f2_2) + temp_s1->unk8);
        phi_return = 1.401298464324817e-45f;
    }
    // Node 9
    return phi_return;
}
#else
GLOBAL_ASM(
.late_rodata
glabel D_8005752C
.word 0x38d1b717 /*0.000099999997*/
glabel D_80057530
.word 0xbc23d70a /*-0.01*/
glabel D_80057534
.word 0x48927c00 /*300000.0*/
.text
glabel sub_GAME_7F093A78
/* 0C85A8 7F093A78 27BDFFC8 */  addiu $sp, $sp, -0x38
/* 0C85AC 7F093A7C AFBF001C */  sw    $ra, 0x1c($sp)
/* 0C85B0 7F093A80 AFB00014 */  sw    $s0, 0x14($sp)
/* 0C85B4 7F093A84 00808025 */  move  $s0, $a0
/* 0C85B8 7F093A88 AFB10018 */  sw    $s1, 0x18($sp)
/* 0C85BC 7F093A8C AFA5003C */  sw    $a1, 0x3c($sp)
/* 0C85C0 7F093A90 0FC227F5 */  jal   get_BONDdata_position
/* 0C85C4 7F093A94 AFA60040 */   sw    $a2, 0x40($sp)
/* 0C85C8 7F093A98 C6000008 */  lwc1  $f0, 8($s0)
/* 0C85CC 7F093A9C C60E0000 */  lwc1  $f14, ($s0)
/* 0C85D0 7F093AA0 3C018005 */  lui   $at, %hi(D_8005752C)
/* 0C85D4 7F093AA4 46000102 */  mul.s $f4, $f0, $f0
/* 0C85D8 7F093AA8 C42A752C */  lwc1  $f10, %lo(D_8005752C)($at)
/* 0C85DC 7F093AAC 00408825 */  move  $s1, $v0
/* 0C85E0 7F093AB0 460E7182 */  mul.s $f6, $f14, $f14
/* 0C85E4 7F093AB4 46062200 */  add.s $f8, $f4, $f6
/* 0C85E8 7F093AB8 0C007DF8 */  jal   sqrtf
/* 0C85EC 7F093ABC 460A4300 */   add.s $f12, $f8, $f10
/* 0C85F0 7F093AC0 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0C85F4 7F093AC4 44816000 */  mtc1  $at, $f12
/* 0C85F8 7F093AC8 3C01C000 */  li    $at, 0xC0000000 # -2.000000
/* 0C85FC 7F093ACC 44812000 */  mtc1  $at, $f4
/* 0C8600 7F093AD0 C6060004 */  lwc1  $f6, 4($s0)
/* 0C8604 7F093AD4 3C018005 */  lui   $at, %hi(D_80057530)
/* 0C8608 7F093AD8 00001025 */  move  $v0, $zero
/* 0C860C 7F093ADC 46062202 */  mul.s $f8, $f4, $f6
/* 0C8610 7F093AE0 46004083 */  div.s $f2, $f8, $f0
/* 0C8614 7F093AE4 4602603C */  c.lt.s $f12, $f2
/* 0C8618 7F093AE8 00000000 */  nop   
/* 0C861C 7F093AEC 45020003 */  bc1fl .L7F093AFC
/* 0C8620 7F093AF0 46026281 */   sub.s $f10, $f12, $f2
/* 0C8624 7F093AF4 46006086 */  mov.s $f2, $f12
/* 0C8628 7F093AF8 46026281 */  sub.s $f10, $f12, $f2
.L7F093AFC:
/* 0C862C 7F093AFC 8FAE0040 */  lw    $t6, 0x40($sp)
/* 0C8630 7F093B00 44807000 */  mtc1  $zero, $f14
/* 0C8634 7F093B04 E5CA0000 */  swc1  $f10, ($t6)
/* 0C8638 7F093B08 C6000004 */  lwc1  $f0, 4($s0)
/* 0C863C 7F093B0C 46007032 */  c.eq.s $f14, $f0
/* 0C8640 7F093B10 00000000 */  nop   
/* 0C8644 7F093B14 45020004 */  bc1fl .L7F093B28
/* 0C8648 7F093B18 46000406 */   mov.s $f16, $f0
/* 0C864C 7F093B1C 10000002 */  b     .L7F093B28
/* 0C8650 7F093B20 C4307530 */   lwc1  $f16, %lo(D_80057530)($at)
/* 0C8654 7F093B24 46000406 */  mov.s $f16, $f0
.L7F093B28:
/* 0C8658 7F093B28 460E803C */  c.lt.s $f16, $f14
/* 0C865C 7F093B2C 00000000 */  nop   
/* 0C8660 7F093B30 4500002D */  bc1f  .L7F093BE8
/* 0C8664 7F093B34 00000000 */   nop   
/* 0C8668 7F093B38 0FC2E9CB */  jal   get_ptr_currentdata
/* 0C866C 7F093B3C E7B00024 */   swc1  $f16, 0x24($sp)
/* 0C8670 7F093B40 C4440024 */  lwc1  $f4, 0x24($v0)
/* 0C8674 7F093B44 C6260004 */  lwc1  $f6, 4($s1)
/* 0C8678 7F093B48 C7B00024 */  lwc1  $f16, 0x24($sp)
/* 0C867C 7F093B4C C6000008 */  lwc1  $f0, 8($s0)
/* 0C8680 7F093B50 46062201 */  sub.s $f8, $f4, $f6
/* 0C8684 7F093B54 C60E0000 */  lwc1  $f14, ($s0)
/* 0C8688 7F093B58 46000282 */  mul.s $f10, $f0, $f0
/* 0C868C 7F093B5C 00000000 */  nop   
/* 0C8690 7F093B60 460E7102 */  mul.s $f4, $f14, $f14
/* 0C8694 7F093B64 46104083 */  div.s $f2, $f8, $f16
/* 0C8698 7F093B68 46045300 */  add.s $f12, $f10, $f4
/* 0C869C 7F093B6C 0C007DF8 */  jal   sqrtf
/* 0C86A0 7F093B70 E7A2002C */   swc1  $f2, 0x2c($sp)
/* 0C86A4 7F093B74 C7A2002C */  lwc1  $f2, 0x2c($sp)
/* 0C86A8 7F093B78 3C018005 */  lui   $at, %hi(D_80057534)
/* 0C86AC 7F093B7C C4327534 */  lwc1  $f18, %lo(D_80057534)($at)
/* 0C86B0 7F093B80 46020302 */  mul.s $f12, $f0, $f2
/* 0C86B4 7F093B84 C7B00024 */  lwc1  $f16, 0x24($sp)
/* 0C86B8 7F093B88 460C903C */  c.lt.s $f18, $f12
/* 0C86BC 7F093B8C 00000000 */  nop   
/* 0C86C0 7F093B90 45020005 */  bc1fl .L7F093BA8
/* 0C86C4 7F093B94 C6080000 */   lwc1  $f8, ($s0)
/* 0C86C8 7F093B98 460C9183 */  div.s $f6, $f18, $f12
/* 0C86CC 7F093B9C 46061082 */  mul.s $f2, $f2, $f6
/* 0C86D0 7F093BA0 00000000 */  nop   
/* 0C86D4 7F093BA4 C6080000 */  lwc1  $f8, ($s0)
.L7F093BA8:
/* 0C86D8 7F093BA8 C6240000 */  lwc1  $f4, ($s1)
/* 0C86DC 7F093BAC 8FA3003C */  lw    $v1, 0x3c($sp)
/* 0C86E0 7F093BB0 46024282 */  mul.s $f10, $f8, $f2
/* 0C86E4 7F093BB4 24020001 */  li    $v0, 1
/* 0C86E8 7F093BB8 46045180 */  add.s $f6, $f10, $f4
/* 0C86EC 7F093BBC 46101282 */  mul.s $f10, $f2, $f16
/* 0C86F0 7F093BC0 E4660000 */  swc1  $f6, ($v1)
/* 0C86F4 7F093BC4 C6280004 */  lwc1  $f8, 4($s1)
/* 0C86F8 7F093BC8 460A4100 */  add.s $f4, $f8, $f10
/* 0C86FC 7F093BCC E4640004 */  swc1  $f4, 4($v1)
/* 0C8700 7F093BD0 C6060008 */  lwc1  $f6, 8($s0)
/* 0C8704 7F093BD4 C62A0008 */  lwc1  $f10, 8($s1)
/* 0C8708 7F093BD8 46023202 */  mul.s $f8, $f6, $f2
/* 0C870C 7F093BDC 460A4100 */  add.s $f4, $f8, $f10
/* 0C8710 7F093BE0 10000001 */  b     .L7F093BE8
/* 0C8714 7F093BE4 E4640008 */   swc1  $f4, 8($v1)
.L7F093BE8:
/* 0C8718 7F093BE8 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0C871C 7F093BEC 8FB00014 */  lw    $s0, 0x14($sp)
/* 0C8720 7F093BF0 8FB10018 */  lw    $s1, 0x18($sp)
/* 0C8724 7F093BF4 03E00008 */  jr    $ra
/* 0C8728 7F093BF8 27BD0038 */   addiu $sp, $sp, 0x38
)
#endif





#ifdef NONMATCHING
f32 sub_GAME_7F093BFC(void *arg0, void *arg1, void *arg2) {
    f32 temp_f0;

    // Node 0
    arg2->unk4 = 0.0f;
    temp_f0 = (arg0->unk4 / (arg0->unk4 - arg1->unk4));
    *arg2 = (f32) (((*arg1 - *arg0) * temp_f0) + *arg0);
    arg2->unk8 = (f32) (((arg1->unk8 - arg0->unk8) * temp_f0) + arg0->unk8);
    return temp_f0;
}

#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F093BFC
/* 0C872C 7F093BFC C4820004 */  lwc1  $f2, 4($a0)
/* 0C8730 7F093C00 C4A40004 */  lwc1  $f4, 4($a1)
/* 0C8734 7F093C04 C48C0000 */  lwc1  $f12, ($a0)
/* 0C8738 7F093C08 C4A80000 */  lwc1  $f8, ($a1)
/* 0C873C 7F093C0C 46041181 */  sub.s $f6, $f2, $f4
/* 0C8740 7F093C10 44802000 */  mtc1  $zero, $f4
/* 0C8744 7F093C14 460C4281 */  sub.s $f10, $f8, $f12
/* 0C8748 7F093C18 E4C40004 */  swc1  $f4, 4($a2)
/* 0C874C 7F093C1C 46061003 */  div.s $f0, $f2, $f6
/* 0C8750 7F093C20 46005402 */  mul.s $f16, $f10, $f0
/* 0C8754 7F093C24 460C8480 */  add.s $f18, $f16, $f12
/* 0C8758 7F093C28 E4D20000 */  swc1  $f18, ($a2)
/* 0C875C 7F093C2C C4A60008 */  lwc1  $f6, 8($a1)
/* 0C8760 7F093C30 C48E0008 */  lwc1  $f14, 8($a0)
/* 0C8764 7F093C34 460E3201 */  sub.s $f8, $f6, $f14
/* 0C8768 7F093C38 46004282 */  mul.s $f10, $f8, $f0
/* 0C876C 7F093C3C 460E5400 */  add.s $f16, $f10, $f14
/* 0C8770 7F093C40 03E00008 */  jr    $ra
/* 0C8774 7F093C44 E4D00008 */   swc1  $f16, 8($a2)
)
#endif






f32 sub_GAME_7F093C48(f32 a, f32 b, f32 c)
{
    if (a < b)
    {
        return b;
    }
    if (c < a)
    {
        return c;
    }
    return a;
}



f32 addpoint5tofloat(f32 arg0) {
    return (f32) (s32) (arg0 + 0.5f);
}





#ifdef NONMATCHING
void sub_GAME_7F093CB0(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F093CB0
/* 0C87E0 7F093CB0 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 0C87E4 7F093CB4 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0C87E8 7F093CB8 AFA40030 */  sw    $a0, 0x30($sp)
/* 0C87EC 7F093CBC 0FC2E9CB */  jal   get_ptr_currentdata
/* 0C87F0 7F093CC0 AFA50034 */   sw    $a1, 0x34($sp)
/* 0C87F4 7F093CC4 904E0008 */  lbu   $t6, 8($v0)
/* 0C87F8 7F093CC8 448E2000 */  mtc1  $t6, $f4
/* 0C87FC 7F093CCC 05C10005 */  bgez  $t6, .L7F093CE4
/* 0C8800 7F093CD0 468021A0 */   cvt.s.w $f6, $f4
/* 0C8804 7F093CD4 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0C8808 7F093CD8 44814000 */  mtc1  $at, $f8
/* 0C880C 7F093CDC 00000000 */  nop   
/* 0C8810 7F093CE0 46083180 */  add.s $f6, $f6, $f8
.L7F093CE4:
/* 0C8814 7F093CE4 0FC2E9CB */  jal   get_ptr_currentdata
/* 0C8818 7F093CE8 E7A6002C */   swc1  $f6, 0x2c($sp)
/* 0C881C 7F093CEC 904F0009 */  lbu   $t7, 9($v0)
/* 0C8820 7F093CF0 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0C8824 7F093CF4 448F5000 */  mtc1  $t7, $f10
/* 0C8828 7F093CF8 05E10004 */  bgez  $t7, .L7F093D0C
/* 0C882C 7F093CFC 46805420 */   cvt.s.w $f16, $f10
/* 0C8830 7F093D00 44819000 */  mtc1  $at, $f18
/* 0C8834 7F093D04 00000000 */  nop   
/* 0C8838 7F093D08 46128400 */  add.s $f16, $f16, $f18
.L7F093D0C:
/* 0C883C 7F093D0C 0FC2E9CB */  jal   get_ptr_currentdata
/* 0C8840 7F093D10 E7B00028 */   swc1  $f16, 0x28($sp)
/* 0C8844 7F093D14 9058000A */  lbu   $t8, 0xa($v0)
/* 0C8848 7F093D18 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0C884C 7F093D1C 44982000 */  mtc1  $t8, $f4
/* 0C8850 7F093D20 07010004 */  bgez  $t8, .L7F093D34
/* 0C8854 7F093D24 46802220 */   cvt.s.w $f8, $f4
/* 0C8858 7F093D28 44813000 */  mtc1  $at, $f6
/* 0C885C 7F093D2C 00000000 */  nop   
/* 0C8860 7F093D30 46064200 */  add.s $f8, $f8, $f6
.L7F093D34:
/* 0C8864 7F093D34 0FC2E9CB */  jal   get_ptr_currentdata
/* 0C8868 7F093D38 E7A80024 */   swc1  $f8, 0x24($sp)
/* 0C886C 7F093D3C 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0C8870 7F093D40 44811000 */  mtc1  $at, $f2
/* 0C8874 7F093D44 3C01437F */  li    $at, 0x437F0000 # 255.000000
/* 0C8878 7F093D48 44818000 */  mtc1  $at, $f16
/* 0C887C 7F093D4C C7AC002C */  lwc1  $f12, 0x2c($sp)
/* 0C8880 7F093D50 C4520014 */  lwc1  $f18, 0x14($v0)
/* 0C8884 7F093D54 C7AA0034 */  lwc1  $f10, 0x34($sp)
/* 0C8888 7F093D58 46106103 */  div.s $f4, $f12, $f16
/* 0C888C 7F093D5C 24080001 */  li    $t0, 1
/* 0C8890 7F093D60 3C014F00 */  li    $at, 0x4F000000 # 2147483648.000000
/* 0C8894 7F093D64 8FA90030 */  lw    $t1, 0x30($sp)
/* 0C8898 7F093D68 460A1001 */  sub.s $f0, $f2, $f10
/* 0C889C 7F093D6C 46041181 */  sub.s $f6, $f2, $f4
/* 0C88A0 7F093D70 46069202 */  mul.s $f8, $f18, $f6
/* 0C88A4 7F093D74 00000000 */  nop   
/* 0C88A8 7F093D78 46004282 */  mul.s $f10, $f8, $f0
/* 0C88AC 7F093D7C 460C5400 */  add.s $f16, $f10, $f12
/* 0C88B0 7F093D80 4459F800 */  cfc1  $t9, $31
/* 0C88B4 7F093D84 44C8F800 */  ctc1  $t0, $31
/* 0C88B8 7F093D88 00000000 */  nop   
/* 0C88BC 7F093D8C 46008124 */  cvt.w.s $f4, $f16
/* 0C88C0 7F093D90 4448F800 */  cfc1  $t0, $31
/* 0C88C4 7F093D94 00000000 */  nop   
/* 0C88C8 7F093D98 31080078 */  andi  $t0, $t0, 0x78
/* 0C88CC 7F093D9C 11000012 */  beqz  $t0, .L7F093DE8
/* 0C88D0 7F093DA0 00000000 */   nop   
/* 0C88D4 7F093DA4 44812000 */  mtc1  $at, $f4
/* 0C88D8 7F093DA8 24080001 */  li    $t0, 1
/* 0C88DC 7F093DAC 46048101 */  sub.s $f4, $f16, $f4
/* 0C88E0 7F093DB0 44C8F800 */  ctc1  $t0, $31
/* 0C88E4 7F093DB4 00000000 */  nop   
/* 0C88E8 7F093DB8 46002124 */  cvt.w.s $f4, $f4
/* 0C88EC 7F093DBC 4448F800 */  cfc1  $t0, $31
/* 0C88F0 7F093DC0 00000000 */  nop   
/* 0C88F4 7F093DC4 31080078 */  andi  $t0, $t0, 0x78
/* 0C88F8 7F093DC8 15000005 */  bnez  $t0, .L7F093DE0
/* 0C88FC 7F093DCC 00000000 */   nop   
/* 0C8900 7F093DD0 44082000 */  mfc1  $t0, $f4
/* 0C8904 7F093DD4 3C018000 */  lui   $at, 0x8000
/* 0C8908 7F093DD8 10000007 */  b     .L7F093DF8
/* 0C890C 7F093DDC 01014025 */   or    $t0, $t0, $at
.L7F093DE0:
/* 0C8910 7F093DE0 10000005 */  b     .L7F093DF8
/* 0C8914 7F093DE4 2408FFFF */   li    $t0, -1
.L7F093DE8:
/* 0C8918 7F093DE8 44082000 */  mfc1  $t0, $f4
/* 0C891C 7F093DEC 00000000 */  nop   
/* 0C8920 7F093DF0 0500FFFB */  bltz  $t0, .L7F093DE0
/* 0C8924 7F093DF4 00000000 */   nop   
.L7F093DF8:
/* 0C8928 7F093DF8 44D9F800 */  ctc1  $t9, $31
/* 0C892C 7F093DFC A1280014 */  sb    $t0, 0x14($t1)
/* 0C8930 7F093E00 0FC2E9CB */  jal   get_ptr_currentdata
/* 0C8934 7F093E04 E7A0001C */   swc1  $f0, 0x1c($sp)
/* 0C8938 7F093E08 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0C893C 7F093E0C 44819000 */  mtc1  $at, $f18
/* 0C8940 7F093E10 3C01437F */  li    $at, 0x437F0000 # 255.000000
/* 0C8944 7F093E14 44813000 */  mtc1  $at, $f6
/* 0C8948 7F093E18 C7A00028 */  lwc1  $f0, 0x28($sp)
/* 0C894C 7F093E1C C4500018 */  lwc1  $f16, 0x18($v0)
/* 0C8950 7F093E20 240B0001 */  li    $t3, 1
/* 0C8954 7F093E24 46060203 */  div.s $f8, $f0, $f6
/* 0C8958 7F093E28 C7A6001C */  lwc1  $f6, 0x1c($sp)
/* 0C895C 7F093E2C 3C014F00 */  li    $at, 0x4F000000 # 2147483648.000000
/* 0C8960 7F093E30 8FAC0030 */  lw    $t4, 0x30($sp)
/* 0C8964 7F093E34 46089281 */  sub.s $f10, $f18, $f8
/* 0C8968 7F093E38 460A8102 */  mul.s $f4, $f16, $f10
/* 0C896C 7F093E3C 00000000 */  nop   
/* 0C8970 7F093E40 46062482 */  mul.s $f18, $f4, $f6
/* 0C8974 7F093E44 46009200 */  add.s $f8, $f18, $f0
/* 0C8978 7F093E48 444AF800 */  cfc1  $t2, $31
/* 0C897C 7F093E4C 44CBF800 */  ctc1  $t3, $31
/* 0C8980 7F093E50 00000000 */  nop   
/* 0C8984 7F093E54 46004424 */  cvt.w.s $f16, $f8
/* 0C8988 7F093E58 444BF800 */  cfc1  $t3, $31
/* 0C898C 7F093E5C 00000000 */  nop   
/* 0C8990 7F093E60 316B0078 */  andi  $t3, $t3, 0x78
/* 0C8994 7F093E64 11600012 */  beqz  $t3, .L7F093EB0
/* 0C8998 7F093E68 00000000 */   nop   
/* 0C899C 7F093E6C 44818000 */  mtc1  $at, $f16
/* 0C89A0 7F093E70 240B0001 */  li    $t3, 1
/* 0C89A4 7F093E74 46104401 */  sub.s $f16, $f8, $f16
/* 0C89A8 7F093E78 44CBF800 */  ctc1  $t3, $31
/* 0C89AC 7F093E7C 00000000 */  nop   
/* 0C89B0 7F093E80 46008424 */  cvt.w.s $f16, $f16
/* 0C89B4 7F093E84 444BF800 */  cfc1  $t3, $31
/* 0C89B8 7F093E88 00000000 */  nop   
/* 0C89BC 7F093E8C 316B0078 */  andi  $t3, $t3, 0x78
/* 0C89C0 7F093E90 15600005 */  bnez  $t3, .L7F093EA8
/* 0C89C4 7F093E94 00000000 */   nop   
/* 0C89C8 7F093E98 440B8000 */  mfc1  $t3, $f16
/* 0C89CC 7F093E9C 3C018000 */  lui   $at, 0x8000
/* 0C89D0 7F093EA0 10000007 */  b     .L7F093EC0
/* 0C89D4 7F093EA4 01615825 */   or    $t3, $t3, $at
.L7F093EA8:
/* 0C89D8 7F093EA8 10000005 */  b     .L7F093EC0
/* 0C89DC 7F093EAC 240BFFFF */   li    $t3, -1
.L7F093EB0:
/* 0C89E0 7F093EB0 440B8000 */  mfc1  $t3, $f16
/* 0C89E4 7F093EB4 00000000 */  nop   
/* 0C89E8 7F093EB8 0560FFFB */  bltz  $t3, .L7F093EA8
/* 0C89EC 7F093EBC 00000000 */   nop   
.L7F093EC0:
/* 0C89F0 7F093EC0 44CAF800 */  ctc1  $t2, $31
/* 0C89F4 7F093EC4 0FC2E9CB */  jal   get_ptr_currentdata
/* 0C89F8 7F093EC8 A18B0015 */   sb    $t3, 0x15($t4)
/* 0C89FC 7F093ECC 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0C8A00 7F093ED0 44815000 */  mtc1  $at, $f10
/* 0C8A04 7F093ED4 3C01437F */  li    $at, 0x437F0000 # 255.000000
/* 0C8A08 7F093ED8 44812000 */  mtc1  $at, $f4
/* 0C8A0C 7F093EDC C7A00024 */  lwc1  $f0, 0x24($sp)
/* 0C8A10 7F093EE0 C448001C */  lwc1  $f8, 0x1c($v0)
/* 0C8A14 7F093EE4 240E0001 */  li    $t6, 1
/* 0C8A18 7F093EE8 46040183 */  div.s $f6, $f0, $f4
/* 0C8A1C 7F093EEC C7A4001C */  lwc1  $f4, 0x1c($sp)
/* 0C8A20 7F093EF0 3C014F00 */  li    $at, 0x4F000000 # 2147483648.000000
/* 0C8A24 7F093EF4 8FAF0030 */  lw    $t7, 0x30($sp)
/* 0C8A28 7F093EF8 241800FF */  li    $t8, 255
/* 0C8A2C 7F093EFC 46065481 */  sub.s $f18, $f10, $f6
/* 0C8A30 7F093F00 46124402 */  mul.s $f16, $f8, $f18
/* 0C8A34 7F093F04 00000000 */  nop   
/* 0C8A38 7F093F08 46048282 */  mul.s $f10, $f16, $f4
/* 0C8A3C 7F093F0C 46005180 */  add.s $f6, $f10, $f0
/* 0C8A40 7F093F10 444DF800 */  cfc1  $t5, $31
/* 0C8A44 7F093F14 44CEF800 */  ctc1  $t6, $31
/* 0C8A48 7F093F18 00000000 */  nop   
/* 0C8A4C 7F093F1C 46003224 */  cvt.w.s $f8, $f6
/* 0C8A50 7F093F20 444EF800 */  cfc1  $t6, $31
/* 0C8A54 7F093F24 00000000 */  nop   
/* 0C8A58 7F093F28 31CE0078 */  andi  $t6, $t6, 0x78
/* 0C8A5C 7F093F2C 11C00012 */  beqz  $t6, .L7F093F78
/* 0C8A60 7F093F30 00000000 */   nop   
/* 0C8A64 7F093F34 44814000 */  mtc1  $at, $f8
/* 0C8A68 7F093F38 240E0001 */  li    $t6, 1
/* 0C8A6C 7F093F3C 46083201 */  sub.s $f8, $f6, $f8
/* 0C8A70 7F093F40 44CEF800 */  ctc1  $t6, $31
/* 0C8A74 7F093F44 00000000 */  nop   
/* 0C8A78 7F093F48 46004224 */  cvt.w.s $f8, $f8
/* 0C8A7C 7F093F4C 444EF800 */  cfc1  $t6, $31
/* 0C8A80 7F093F50 00000000 */  nop   
/* 0C8A84 7F093F54 31CE0078 */  andi  $t6, $t6, 0x78
/* 0C8A88 7F093F58 15C00005 */  bnez  $t6, .L7F093F70
/* 0C8A8C 7F093F5C 00000000 */   nop   
/* 0C8A90 7F093F60 440E4000 */  mfc1  $t6, $f8
/* 0C8A94 7F093F64 3C018000 */  lui   $at, 0x8000
/* 0C8A98 7F093F68 10000007 */  b     .L7F093F88
/* 0C8A9C 7F093F6C 01C17025 */   or    $t6, $t6, $at
.L7F093F70:
/* 0C8AA0 7F093F70 10000005 */  b     .L7F093F88
/* 0C8AA4 7F093F74 240EFFFF */   li    $t6, -1
.L7F093F78:
/* 0C8AA8 7F093F78 440E4000 */  mfc1  $t6, $f8
/* 0C8AAC 7F093F7C 00000000 */  nop   
/* 0C8AB0 7F093F80 05C0FFFB */  bltz  $t6, .L7F093F70
/* 0C8AB4 7F093F84 00000000 */   nop   
.L7F093F88:
/* 0C8AB8 7F093F88 A1EE0016 */  sb    $t6, 0x16($t7)
/* 0C8ABC 7F093F8C A1F80017 */  sb    $t8, 0x17($t7)
/* 0C8AC0 7F093F90 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0C8AC4 7F093F94 44CDF800 */  ctc1  $t5, $31
/* 0C8AC8 7F093F98 27BD0030 */  addiu $sp, $sp, 0x30
/* 0C8ACC 7F093F9C 03E00008 */  jr    $ra
/* 0C8AD0 7F093FA0 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F093FA4(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F093FA4
/* 0C8AD4 7F093FA4 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 0C8AD8 7F093FA8 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0C8ADC 7F093FAC AFA40030 */  sw    $a0, 0x30($sp)
/* 0C8AE0 7F093FB0 0FC2E9CB */  jal   get_ptr_currentdata
/* 0C8AE4 7F093FB4 AFA50034 */   sw    $a1, 0x34($sp)
/* 0C8AE8 7F093FB8 904E0008 */  lbu   $t6, 8($v0)
/* 0C8AEC 7F093FBC 448E2000 */  mtc1  $t6, $f4
/* 0C8AF0 7F093FC0 05C10005 */  bgez  $t6, .L7F093FD8
/* 0C8AF4 7F093FC4 468021A0 */   cvt.s.w $f6, $f4
/* 0C8AF8 7F093FC8 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0C8AFC 7F093FCC 44814000 */  mtc1  $at, $f8
/* 0C8B00 7F093FD0 00000000 */  nop   
/* 0C8B04 7F093FD4 46083180 */  add.s $f6, $f6, $f8
.L7F093FD8:
/* 0C8B08 7F093FD8 0FC2E9CB */  jal   get_ptr_currentdata
/* 0C8B0C 7F093FDC E7A6002C */   swc1  $f6, 0x2c($sp)
/* 0C8B10 7F093FE0 904F0009 */  lbu   $t7, 9($v0)
/* 0C8B14 7F093FE4 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0C8B18 7F093FE8 448F5000 */  mtc1  $t7, $f10
/* 0C8B1C 7F093FEC 05E10004 */  bgez  $t7, .L7F094000
/* 0C8B20 7F093FF0 46805420 */   cvt.s.w $f16, $f10
/* 0C8B24 7F093FF4 44819000 */  mtc1  $at, $f18
/* 0C8B28 7F093FF8 00000000 */  nop   
/* 0C8B2C 7F093FFC 46128400 */  add.s $f16, $f16, $f18
.L7F094000:
/* 0C8B30 7F094000 0FC2E9CB */  jal   get_ptr_currentdata
/* 0C8B34 7F094004 E7B00028 */   swc1  $f16, 0x28($sp)
/* 0C8B38 7F094008 9058000A */  lbu   $t8, 0xa($v0)
/* 0C8B3C 7F09400C 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0C8B40 7F094010 44982000 */  mtc1  $t8, $f4
/* 0C8B44 7F094014 07010004 */  bgez  $t8, .L7F094028
/* 0C8B48 7F094018 46802220 */   cvt.s.w $f8, $f4
/* 0C8B4C 7F09401C 44813000 */  mtc1  $at, $f6
/* 0C8B50 7F094020 00000000 */  nop   
/* 0C8B54 7F094024 46064200 */  add.s $f8, $f8, $f6
.L7F094028:
/* 0C8B58 7F094028 0FC2E9CB */  jal   get_ptr_currentdata
/* 0C8B5C 7F09402C E7A80024 */   swc1  $f8, 0x24($sp)
/* 0C8B60 7F094030 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0C8B64 7F094034 44811000 */  mtc1  $at, $f2
/* 0C8B68 7F094038 3C01437F */  li    $at, 0x437F0000 # 255.000000
/* 0C8B6C 7F09403C 44818000 */  mtc1  $at, $f16
/* 0C8B70 7F094040 C7AC002C */  lwc1  $f12, 0x2c($sp)
/* 0C8B74 7F094044 C452002C */  lwc1  $f18, 0x2c($v0)
/* 0C8B78 7F094048 C7AA0034 */  lwc1  $f10, 0x34($sp)
/* 0C8B7C 7F09404C 46106103 */  div.s $f4, $f12, $f16
/* 0C8B80 7F094050 24080001 */  li    $t0, 1
/* 0C8B84 7F094054 3C014F00 */  li    $at, 0x4F000000 # 2147483648.000000
/* 0C8B88 7F094058 8FA90030 */  lw    $t1, 0x30($sp)
/* 0C8B8C 7F09405C 460A1001 */  sub.s $f0, $f2, $f10
/* 0C8B90 7F094060 46041181 */  sub.s $f6, $f2, $f4
/* 0C8B94 7F094064 46069202 */  mul.s $f8, $f18, $f6
/* 0C8B98 7F094068 00000000 */  nop   
/* 0C8B9C 7F09406C 46004282 */  mul.s $f10, $f8, $f0
/* 0C8BA0 7F094070 460C5400 */  add.s $f16, $f10, $f12
/* 0C8BA4 7F094074 4459F800 */  cfc1  $t9, $31
/* 0C8BA8 7F094078 44C8F800 */  ctc1  $t0, $31
/* 0C8BAC 7F09407C 00000000 */  nop   
/* 0C8BB0 7F094080 46008124 */  cvt.w.s $f4, $f16
/* 0C8BB4 7F094084 4448F800 */  cfc1  $t0, $31
/* 0C8BB8 7F094088 00000000 */  nop   
/* 0C8BBC 7F09408C 31080078 */  andi  $t0, $t0, 0x78
/* 0C8BC0 7F094090 11000012 */  beqz  $t0, .L7F0940DC
/* 0C8BC4 7F094094 00000000 */   nop   
/* 0C8BC8 7F094098 44812000 */  mtc1  $at, $f4
/* 0C8BCC 7F09409C 24080001 */  li    $t0, 1
/* 0C8BD0 7F0940A0 46048101 */  sub.s $f4, $f16, $f4
/* 0C8BD4 7F0940A4 44C8F800 */  ctc1  $t0, $31
/* 0C8BD8 7F0940A8 00000000 */  nop   
/* 0C8BDC 7F0940AC 46002124 */  cvt.w.s $f4, $f4
/* 0C8BE0 7F0940B0 4448F800 */  cfc1  $t0, $31
/* 0C8BE4 7F0940B4 00000000 */  nop   
/* 0C8BE8 7F0940B8 31080078 */  andi  $t0, $t0, 0x78
/* 0C8BEC 7F0940BC 15000005 */  bnez  $t0, .L7F0940D4
/* 0C8BF0 7F0940C0 00000000 */   nop   
/* 0C8BF4 7F0940C4 44082000 */  mfc1  $t0, $f4
/* 0C8BF8 7F0940C8 3C018000 */  lui   $at, 0x8000
/* 0C8BFC 7F0940CC 10000007 */  b     .L7F0940EC
/* 0C8C00 7F0940D0 01014025 */   or    $t0, $t0, $at
.L7F0940D4:
/* 0C8C04 7F0940D4 10000005 */  b     .L7F0940EC
/* 0C8C08 7F0940D8 2408FFFF */   li    $t0, -1
.L7F0940DC:
/* 0C8C0C 7F0940DC 44082000 */  mfc1  $t0, $f4
/* 0C8C10 7F0940E0 00000000 */  nop   
/* 0C8C14 7F0940E4 0500FFFB */  bltz  $t0, .L7F0940D4
/* 0C8C18 7F0940E8 00000000 */   nop   
.L7F0940EC:
/* 0C8C1C 7F0940EC 44D9F800 */  ctc1  $t9, $31
/* 0C8C20 7F0940F0 A1280014 */  sb    $t0, 0x14($t1)
/* 0C8C24 7F0940F4 0FC2E9CB */  jal   get_ptr_currentdata
/* 0C8C28 7F0940F8 E7A0001C */   swc1  $f0, 0x1c($sp)
/* 0C8C2C 7F0940FC 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0C8C30 7F094100 44819000 */  mtc1  $at, $f18
/* 0C8C34 7F094104 3C01437F */  li    $at, 0x437F0000 # 255.000000
/* 0C8C38 7F094108 44813000 */  mtc1  $at, $f6
/* 0C8C3C 7F09410C C7A00028 */  lwc1  $f0, 0x28($sp)
/* 0C8C40 7F094110 C4500030 */  lwc1  $f16, 0x30($v0)
/* 0C8C44 7F094114 240B0001 */  li    $t3, 1
/* 0C8C48 7F094118 46060203 */  div.s $f8, $f0, $f6
/* 0C8C4C 7F09411C C7A6001C */  lwc1  $f6, 0x1c($sp)
/* 0C8C50 7F094120 3C014F00 */  li    $at, 0x4F000000 # 2147483648.000000
/* 0C8C54 7F094124 8FAC0030 */  lw    $t4, 0x30($sp)
/* 0C8C58 7F094128 46089281 */  sub.s $f10, $f18, $f8
/* 0C8C5C 7F09412C 460A8102 */  mul.s $f4, $f16, $f10
/* 0C8C60 7F094130 00000000 */  nop   
/* 0C8C64 7F094134 46062482 */  mul.s $f18, $f4, $f6
/* 0C8C68 7F094138 46009200 */  add.s $f8, $f18, $f0
/* 0C8C6C 7F09413C 444AF800 */  cfc1  $t2, $31
/* 0C8C70 7F094140 44CBF800 */  ctc1  $t3, $31
/* 0C8C74 7F094144 00000000 */  nop   
/* 0C8C78 7F094148 46004424 */  cvt.w.s $f16, $f8
/* 0C8C7C 7F09414C 444BF800 */  cfc1  $t3, $31
/* 0C8C80 7F094150 00000000 */  nop   
/* 0C8C84 7F094154 316B0078 */  andi  $t3, $t3, 0x78
/* 0C8C88 7F094158 11600012 */  beqz  $t3, .L7F0941A4
/* 0C8C8C 7F09415C 00000000 */   nop   
/* 0C8C90 7F094160 44818000 */  mtc1  $at, $f16
/* 0C8C94 7F094164 240B0001 */  li    $t3, 1
/* 0C8C98 7F094168 46104401 */  sub.s $f16, $f8, $f16
/* 0C8C9C 7F09416C 44CBF800 */  ctc1  $t3, $31
/* 0C8CA0 7F094170 00000000 */  nop   
/* 0C8CA4 7F094174 46008424 */  cvt.w.s $f16, $f16
/* 0C8CA8 7F094178 444BF800 */  cfc1  $t3, $31
/* 0C8CAC 7F09417C 00000000 */  nop   
/* 0C8CB0 7F094180 316B0078 */  andi  $t3, $t3, 0x78
/* 0C8CB4 7F094184 15600005 */  bnez  $t3, .L7F09419C
/* 0C8CB8 7F094188 00000000 */   nop   
/* 0C8CBC 7F09418C 440B8000 */  mfc1  $t3, $f16
/* 0C8CC0 7F094190 3C018000 */  lui   $at, 0x8000
/* 0C8CC4 7F094194 10000007 */  b     .L7F0941B4
/* 0C8CC8 7F094198 01615825 */   or    $t3, $t3, $at
.L7F09419C:
/* 0C8CCC 7F09419C 10000005 */  b     .L7F0941B4
/* 0C8CD0 7F0941A0 240BFFFF */   li    $t3, -1
.L7F0941A4:
/* 0C8CD4 7F0941A4 440B8000 */  mfc1  $t3, $f16
/* 0C8CD8 7F0941A8 00000000 */  nop   
/* 0C8CDC 7F0941AC 0560FFFB */  bltz  $t3, .L7F09419C
/* 0C8CE0 7F0941B0 00000000 */   nop   
.L7F0941B4:
/* 0C8CE4 7F0941B4 44CAF800 */  ctc1  $t2, $31
/* 0C8CE8 7F0941B8 0FC2E9CB */  jal   get_ptr_currentdata
/* 0C8CEC 7F0941BC A18B0015 */   sb    $t3, 0x15($t4)
/* 0C8CF0 7F0941C0 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0C8CF4 7F0941C4 44815000 */  mtc1  $at, $f10
/* 0C8CF8 7F0941C8 3C01437F */  li    $at, 0x437F0000 # 255.000000
/* 0C8CFC 7F0941CC 44812000 */  mtc1  $at, $f4
/* 0C8D00 7F0941D0 C7A00024 */  lwc1  $f0, 0x24($sp)
/* 0C8D04 7F0941D4 C4480034 */  lwc1  $f8, 0x34($v0)
/* 0C8D08 7F0941D8 240E0001 */  li    $t6, 1
/* 0C8D0C 7F0941DC 46040183 */  div.s $f6, $f0, $f4
/* 0C8D10 7F0941E0 C7A4001C */  lwc1  $f4, 0x1c($sp)
/* 0C8D14 7F0941E4 3C014F00 */  li    $at, 0x4F000000 # 2147483648.000000
/* 0C8D18 7F0941E8 8FAF0030 */  lw    $t7, 0x30($sp)
/* 0C8D1C 7F0941EC 241800FF */  li    $t8, 255
/* 0C8D20 7F0941F0 46065481 */  sub.s $f18, $f10, $f6
/* 0C8D24 7F0941F4 46124402 */  mul.s $f16, $f8, $f18
/* 0C8D28 7F0941F8 00000000 */  nop   
/* 0C8D2C 7F0941FC 46048282 */  mul.s $f10, $f16, $f4
/* 0C8D30 7F094200 46005180 */  add.s $f6, $f10, $f0
/* 0C8D34 7F094204 444DF800 */  cfc1  $t5, $31
/* 0C8D38 7F094208 44CEF800 */  ctc1  $t6, $31
/* 0C8D3C 7F09420C 00000000 */  nop   
/* 0C8D40 7F094210 46003224 */  cvt.w.s $f8, $f6
/* 0C8D44 7F094214 444EF800 */  cfc1  $t6, $31
/* 0C8D48 7F094218 00000000 */  nop   
/* 0C8D4C 7F09421C 31CE0078 */  andi  $t6, $t6, 0x78
/* 0C8D50 7F094220 11C00012 */  beqz  $t6, .L7F09426C
/* 0C8D54 7F094224 00000000 */   nop   
/* 0C8D58 7F094228 44814000 */  mtc1  $at, $f8
/* 0C8D5C 7F09422C 240E0001 */  li    $t6, 1
/* 0C8D60 7F094230 46083201 */  sub.s $f8, $f6, $f8
/* 0C8D64 7F094234 44CEF800 */  ctc1  $t6, $31
/* 0C8D68 7F094238 00000000 */  nop   
/* 0C8D6C 7F09423C 46004224 */  cvt.w.s $f8, $f8
/* 0C8D70 7F094240 444EF800 */  cfc1  $t6, $31
/* 0C8D74 7F094244 00000000 */  nop   
/* 0C8D78 7F094248 31CE0078 */  andi  $t6, $t6, 0x78
/* 0C8D7C 7F09424C 15C00005 */  bnez  $t6, .L7F094264
/* 0C8D80 7F094250 00000000 */   nop   
/* 0C8D84 7F094254 440E4000 */  mfc1  $t6, $f8
/* 0C8D88 7F094258 3C018000 */  lui   $at, 0x8000
/* 0C8D8C 7F09425C 10000007 */  b     .L7F09427C
/* 0C8D90 7F094260 01C17025 */   or    $t6, $t6, $at
.L7F094264:
/* 0C8D94 7F094264 10000005 */  b     .L7F09427C
/* 0C8D98 7F094268 240EFFFF */   li    $t6, -1
.L7F09426C:
/* 0C8D9C 7F09426C 440E4000 */  mfc1  $t6, $f8
/* 0C8DA0 7F094270 00000000 */  nop   
/* 0C8DA4 7F094274 05C0FFFB */  bltz  $t6, .L7F094264
/* 0C8DA8 7F094278 00000000 */   nop   
.L7F09427C:
/* 0C8DAC 7F09427C A1EE0016 */  sb    $t6, 0x16($t7)
/* 0C8DB0 7F094280 A1F80017 */  sb    $t8, 0x17($t7)
/* 0C8DB4 7F094284 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0C8DB8 7F094288 44CDF800 */  ctc1  $t5, $31
/* 0C8DBC 7F09428C 27BD0030 */  addiu $sp, $sp, 0x30
/* 0C8DC0 7F094290 03E00008 */  jr    $ra
/* 0C8DC4 7F094294 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F094298(void) {

}
#else
GLOBAL_ASM(
.late_rodata
glabel D_80057538
.word 0x46ffffcd /*32767.9*/
glabel D_8005753C
.word 0xc6ffffcd /*-32767.9*/

.text
glabel sub_GAME_7F094298
/* 0C8DC8 7F094298 3C018005 */  lui   $at, %hi(D_80057538)
/* 0C8DCC 7F09429C C4207538 */  lwc1  $f0, %lo(D_80057538)($at)
/* 0C8DD0 7F0942A0 44802000 */  mtc1  $zero, $f4
/* 0C8DD4 7F0942A4 3C018005 */  lui   $at, %hi(D_8005753C)
/* 0C8DD8 7F0942A8 460C003C */  c.lt.s $f0, $f12
/* 0C8DDC 7F0942AC 00000000 */  nop   
/* 0C8DE0 7F0942B0 45000002 */  bc1f  .L7F0942BC
/* 0C8DE4 7F0942B4 00000000 */   nop   
/* 0C8DE8 7F0942B8 46000306 */  mov.s $f12, $f0
.L7F0942BC:
/* 0C8DEC 7F0942BC C420753C */  lwc1  $f0, %lo(D_8005753C)($at)
/* 0C8DF0 7F0942C0 3C014780 */  li    $at, 0x47800000 # 65536.000000
/* 0C8DF4 7F0942C4 4600603C */  c.lt.s $f12, $f0
/* 0C8DF8 7F0942C8 00000000 */  nop   
/* 0C8DFC 7F0942CC 45020003 */  bc1fl .L7F0942DC
/* 0C8E00 7F0942D0 4604603C */   c.lt.s $f12, $f4
/* 0C8E04 7F0942D4 46000306 */  mov.s $f12, $f0
/* 0C8E08 7F0942D8 4604603C */  c.lt.s $f12, $f4
.L7F0942DC:
/* 0C8E0C 7F0942DC 00000000 */  nop   
/* 0C8E10 7F0942E0 4502002C */  bc1fl .L7F094394
/* 0C8E14 7F0942E4 44818000 */   mtc1  $at, $f16
/* 0C8E18 7F0942E8 3C01C780 */  li    $at, 0xC7800000 # -65536.000000
/* 0C8E1C 7F0942EC 44813000 */  mtc1  $at, $f6
/* 0C8E20 7F0942F0 24030001 */  li    $v1, 1
/* 0C8E24 7F0942F4 3C014F00 */  li    $at, 0x4F000000 # 2147483648.000000
/* 0C8E28 7F0942F8 46066202 */  mul.s $f8, $f12, $f6
/* 0C8E2C 7F0942FC 444EF800 */  cfc1  $t6, $31
/* 0C8E30 7F094300 44C3F800 */  ctc1  $v1, $31
/* 0C8E34 7F094304 00000000 */  nop   
/* 0C8E38 7F094308 460042A4 */  cvt.w.s $f10, $f8
/* 0C8E3C 7F09430C 4443F800 */  cfc1  $v1, $31
/* 0C8E40 7F094310 00000000 */  nop   
/* 0C8E44 7F094314 30630078 */  andi  $v1, $v1, 0x78
/* 0C8E48 7F094318 50600017 */  beql  $v1, $zero, .L7F094378
/* 0C8E4C 7F09431C 44035000 */   mfc1  $v1, $f10
/* 0C8E50 7F094320 44815000 */  mtc1  $at, $f10
/* 0C8E54 7F094324 24030001 */  li    $v1, 1
/* 0C8E58 7F094328 460A4281 */  sub.s $f10, $f8, $f10
/* 0C8E5C 7F09432C 44C3F800 */  ctc1  $v1, $31
/* 0C8E60 7F094330 00000000 */  nop   
/* 0C8E64 7F094334 460052A4 */  cvt.w.s $f10, $f10
/* 0C8E68 7F094338 4443F800 */  cfc1  $v1, $31
/* 0C8E6C 7F09433C 00000000 */  nop   
/* 0C8E70 7F094340 30630078 */  andi  $v1, $v1, 0x78
/* 0C8E74 7F094344 54600008 */  bnezl $v1, .L7F094368
/* 0C8E78 7F094348 2403FFFF */   li    $v1, -1
/* 0C8E7C 7F09434C 44035000 */  mfc1  $v1, $f10
/* 0C8E80 7F094350 3C018000 */  lui   $at, 0x8000
/* 0C8E84 7F094354 44CEF800 */  ctc1  $t6, $31
/* 0C8E88 7F094358 00611825 */  or    $v1, $v1, $at
/* 0C8E8C 7F09435C 03E00008 */  jr    $ra
/* 0C8E90 7F094360 00031023 */   negu  $v0, $v1

/* 0C8E94 7F094364 2403FFFF */  li    $v1, -1
.L7F094368:
/* 0C8E98 7F094368 44CEF800 */  ctc1  $t6, $31
/* 0C8E9C 7F09436C 03E00008 */  jr    $ra
/* 0C8EA0 7F094370 00031023 */   negu  $v0, $v1

/* 0C8EA4 7F094374 44035000 */  mfc1  $v1, $f10
.L7F094378:
/* 0C8EA8 7F094378 00000000 */  nop   
/* 0C8EAC 7F09437C 0462FFFA */  bltzl $v1, .L7F094368
/* 0C8EB0 7F094380 2403FFFF */   li    $v1, -1
/* 0C8EB4 7F094384 44CEF800 */  ctc1  $t6, $31
/* 0C8EB8 7F094388 03E00008 */  jr    $ra
/* 0C8EBC 7F09438C 00031023 */   negu  $v0, $v1

/* 0C8EC0 7F094390 44818000 */  mtc1  $at, $f16
.L7F094394:
/* 0C8EC4 7F094394 24030001 */  li    $v1, 1
/* 0C8EC8 7F094398 3C014F00 */  li    $at, 0x4F000000 # 2147483648.000000
/* 0C8ECC 7F09439C 460C8482 */  mul.s $f18, $f16, $f12
/* 0C8ED0 7F0943A0 444FF800 */  cfc1  $t7, $31
/* 0C8ED4 7F0943A4 44C3F800 */  ctc1  $v1, $31
/* 0C8ED8 7F0943A8 00000000 */  nop   
/* 0C8EDC 7F0943AC 46009124 */  cvt.w.s $f4, $f18
/* 0C8EE0 7F0943B0 4443F800 */  cfc1  $v1, $31
/* 0C8EE4 7F0943B4 00000000 */  nop   
/* 0C8EE8 7F0943B8 30630078 */  andi  $v1, $v1, 0x78
/* 0C8EEC 7F0943BC 50600013 */  beql  $v1, $zero, .L7F09440C
/* 0C8EF0 7F0943C0 44032000 */   mfc1  $v1, $f4
/* 0C8EF4 7F0943C4 44812000 */  mtc1  $at, $f4
/* 0C8EF8 7F0943C8 24030001 */  li    $v1, 1
/* 0C8EFC 7F0943CC 46049101 */  sub.s $f4, $f18, $f4
/* 0C8F00 7F0943D0 44C3F800 */  ctc1  $v1, $31
/* 0C8F04 7F0943D4 00000000 */  nop   
/* 0C8F08 7F0943D8 46002124 */  cvt.w.s $f4, $f4
/* 0C8F0C 7F0943DC 4443F800 */  cfc1  $v1, $31
/* 0C8F10 7F0943E0 00000000 */  nop   
/* 0C8F14 7F0943E4 30630078 */  andi  $v1, $v1, 0x78
/* 0C8F18 7F0943E8 14600005 */  bnez  $v1, .L7F094400
/* 0C8F1C 7F0943EC 00000000 */   nop   
/* 0C8F20 7F0943F0 44032000 */  mfc1  $v1, $f4
/* 0C8F24 7F0943F4 3C018000 */  lui   $at, 0x8000
/* 0C8F28 7F0943F8 10000007 */  b     .L7F094418
/* 0C8F2C 7F0943FC 00611825 */   or    $v1, $v1, $at
.L7F094400:
/* 0C8F30 7F094400 10000005 */  b     .L7F094418
/* 0C8F34 7F094404 2403FFFF */   li    $v1, -1
/* 0C8F38 7F094408 44032000 */  mfc1  $v1, $f4
.L7F09440C:
/* 0C8F3C 7F09440C 00000000 */  nop   
/* 0C8F40 7F094410 0460FFFB */  bltz  $v1, .L7F094400
/* 0C8F44 7F094414 00000000 */   nop   
.L7F094418:
/* 0C8F48 7F094418 44CFF800 */  ctc1  $t7, $31
/* 0C8F4C 7F09441C 00000000 */  nop   
/* 0C8F50 7F094420 00000000 */  nop   
/* 0C8F54 7F094424 03E00008 */  jr    $ra
/* 0C8F58 7F094428 00601025 */   move  $v0, $v1
)
#endif





void store_stagenum_to_copyof_stagenum(s32 stagenum) {
  copyof_stagenum = stagenum;
}

void sub_GAME_7F094438(void)
{
    D_8003FD94[0] = (clock_timer + D_8003FD94[0]);
    if ( D_8003FD94[0] > 4096.0f)
    {
        D_8003FD94[0] -= 4096.0f;
    }
}





#ifdef NONMATCHING
void sub_GAME_7F094488(void) {

}
#else
GLOBAL_ASM(
.late_rodata
glabel D_80057540
.word 0x3dcccccd /*0.1*/
/*D:80057544*/
glabel jpt_80057544
.word .L7F094A48
.word .L7F095284
.word .L7F0953CC
.word .L7F094B4C
.word .L7F095514
.word .L7F094E60
.word .L7F0957A4
.word .L7F0951BC
.word .L7F09565C
.word .L7F0957A4
.word .L7F094D5C
.word .L7F0950F4
.word .L7F094C50
.word .L7F09502C
.word .L7F094F64
.word .L7F094A40

glabel D_80057584
.word 0x477fff00 /*65535.0*/
glabel D_80057588
.word 0x449fe000 /*1279.0*/
glabel D_8005758C
.word 0x446fc000 /*959.0*/

/*D:80057590*/
glabel jpt_80057590
.word .L7F095E14
.word .L7F09643C
.word .L7F09652C
.word .L7F096094
.word .L7F09661C
.word .L7F0961CC
.word .L7F096E20
.word .L7F096C98
.word .L7F09670C
.word .L7F096E20
.word .L7F096304
.word .L7F096B10
.word .L7F095F58
.word .L7F096984
.word .L7F0967FC
.word .L7F095E1C

glabel D_800575D0
.word 0x477fff00 /*65535.0*/
glabel D_800575D4
.word 0x46fffe00 /*32767.0*/
glabel D_800575D8
.word 0x46fffe00 /*32767.0*/
glabel D_800575DC
.word 0x43ff8000 /*511.0*/
glabel D_800575E0
.word 0xc57fa000 /*-4090.0*/
glabel D_800575E4
.word 0xc57fa000 /*-4090.0*/
.text
glabel sub_GAME_7F094488
/* 0C8FB8 7F094488 27BDF950 */  addiu $sp, $sp, -0x6b0
/* 0C8FBC 7F09448C AFBF004C */  sw    $ra, 0x4c($sp)
/* 0C8FC0 7F094490 AFB10048 */  sw    $s1, 0x48($sp)
/* 0C8FC4 7F094494 AFB00044 */  sw    $s0, 0x44($sp)
/* 0C8FC8 7F094498 F7BC0038 */  sdc1  $f28, 0x38($sp)
/* 0C8FCC 7F09449C F7BA0030 */  sdc1  $f26, 0x30($sp)
/* 0C8FD0 7F0944A0 F7B80028 */  sdc1  $f24, 0x28($sp)
/* 0C8FD4 7F0944A4 F7B60020 */  sdc1  $f22, 0x20($sp)
/* 0C8FD8 7F0944A8 F7B40018 */  sdc1  $f20, 0x18($sp)
/* 0C8FDC 7F0944AC 0FC2D20F */  jal   get_room_data_float1
/* 0C8FE0 7F0944B0 AFA406B0 */   sw    $a0, 0x6b0($sp)
/* 0C8FE4 7F0944B4 3C0141F0 */  li    $at, 0x41F00000 # 30.000000
/* 0C8FE8 7F0944B8 44812000 */  mtc1  $at, $f4
/* 0C8FEC 7F0944BC AFA00430 */  sw    $zero, 0x430($sp)
/* 0C8FF0 7F0944C0 0FC2E9CB */  jal   get_ptr_currentdata
/* 0C8FF4 7F0944C4 46040603 */   div.s $f24, $f0, $f4
/* 0C8FF8 7F0944C8 0FC2E9CB */  jal   get_ptr_currentdata
/* 0C8FFC 7F0944CC 00408025 */   move  $s0, $v0
/* 0C9000 7F0944D0 904E000B */  lbu   $t6, 0xb($v0)
/* 0C9004 7F0944D4 8FA406B0 */  lw    $a0, 0x6b0($sp)
/* 0C9008 7F0944D8 55C0007B */  bnezl $t6, .L7F0946C8
/* 0C900C 7F0944DC 92050008 */   lbu   $a1, 8($s0)
/* 0C9010 7F0944E0 0FC26919 */  jal   getPlayerCount
/* 0C9014 7F0944E4 00000000 */   nop   
/* 0C9018 7F0944E8 24010001 */  li    $at, 1
/* 0C901C 7F0944EC 1441003B */  bne   $v0, $at, .L7F0945DC
/* 0C9020 7F0944F0 3C088008 */   lui   $t0, %hi(pPlayer) 
/* 0C9024 7F0944F4 8FAF06B0 */  lw    $t7, 0x6b0($sp)
/* 0C9028 7F0944F8 3C19BA00 */  lui   $t9, (0xBA001402 >> 16) # lui $t9, 0xba00
/* 0C902C 7F0944FC 37391402 */  ori   $t9, (0xBA001402 & 0xFFFF) # ori $t9, $t9, 0x1402
/* 0C9030 7F094500 25F80008 */  addiu $t8, $t7, 8
/* 0C9034 7F094504 AFB806B0 */  sw    $t8, 0x6b0($sp)
/* 0C9038 7F094508 3C0A0030 */  lui   $t2, 0x30
/* 0C903C 7F09450C ADEA0004 */  sw    $t2, 4($t7)
/* 0C9040 7F094510 ADF90000 */  sw    $t9, ($t7)
/* 0C9044 7F094514 9207000A */  lbu   $a3, 0xa($s0)
/* 0C9048 7F094518 92060009 */  lbu   $a2, 9($s0)
/* 0C904C 7F09451C 92050008 */  lbu   $a1, 8($s0)
/* 0C9050 7F094520 0C0011B4 */  jal   set_setfillcolor
/* 0C9054 7F094524 8FA406B0 */   lw    $a0, 0x6b0($sp)
/* 0C9058 7F094528 244B0008 */  addiu $t3, $v0, 8
/* 0C905C 7F09452C AFAB06B0 */  sw    $t3, 0x6b0($sp)
/* 0C9060 7F094530 0C001127 */  jal   viGetViewWidth
/* 0C9064 7F094534 00408825 */   move  $s1, $v0
/* 0C9068 7F094538 0C001145 */  jal   viGetViewLeft
/* 0C906C 7F09453C A7A2007A */   sh    $v0, 0x7a($sp)
/* 0C9070 7F094540 0C001149 */  jal   viGetViewTop
/* 0C9074 7F094544 A7A2007C */   sh    $v0, 0x7c($sp)
/* 0C9078 7F094548 00028400 */  sll   $s0, $v0, 0x10
/* 0C907C 7F09454C 00106403 */  sra   $t4, $s0, 0x10
/* 0C9080 7F094550 0C00112B */  jal   viGetViewHeight
/* 0C9084 7F094554 01808025 */   move  $s0, $t4
/* 0C9088 7F094558 87AD007C */  lh    $t5, 0x7c($sp)
/* 0C908C 7F09455C 87AE007A */  lh    $t6, 0x7a($sp)
/* 0C9090 7F094560 00505821 */  addu  $t3, $v0, $s0
/* 0C9094 7F094564 256CFFFF */  addiu $t4, $t3, -1
/* 0C9098 7F094568 01AE7821 */  addu  $t7, $t5, $t6
/* 0C909C 7F09456C 25F8FFFF */  addiu $t8, $t7, -1
/* 0C90A0 7F094570 318D03FF */  andi  $t5, $t4, 0x3ff
/* 0C90A4 7F094574 000D7080 */  sll   $t6, $t5, 2
/* 0C90A8 7F094578 331903FF */  andi  $t9, $t8, 0x3ff
/* 0C90AC 7F09457C 3C01F600 */  lui   $at, 0xf600
/* 0C90B0 7F094580 01C17825 */  or    $t7, $t6, $at
/* 0C90B4 7F094584 00195380 */  sll   $t2, $t9, 0xe
/* 0C90B8 7F094588 01EAC025 */  or    $t8, $t7, $t2
/* 0C90BC 7F09458C 0C001145 */  jal   viGetViewLeft
/* 0C90C0 7F094590 AE380000 */   sw    $t8, ($s1)
/* 0C90C4 7F094594 00028400 */  sll   $s0, $v0, 0x10
/* 0C90C8 7F094598 0010CC03 */  sra   $t9, $s0, 0x10
/* 0C90CC 7F09459C 0C001149 */  jal   viGetViewTop
/* 0C90D0 7F0945A0 03208025 */   move  $s0, $t9
/* 0C90D4 7F0945A4 304B03FF */  andi  $t3, $v0, 0x3ff
/* 0C90D8 7F0945A8 320D03FF */  andi  $t5, $s0, 0x3ff
/* 0C90DC 7F0945AC 000D7380 */  sll   $t6, $t5, 0xe
/* 0C90E0 7F0945B0 000B6080 */  sll   $t4, $t3, 2
/* 0C90E4 7F0945B4 018E7825 */  or    $t7, $t4, $t6
/* 0C90E8 7F0945B8 AE2F0004 */  sw    $t7, 4($s1)
/* 0C90EC 7F0945BC 8FAA06B0 */  lw    $t2, 0x6b0($sp)
/* 0C90F0 7F0945C0 3C19E700 */  lui   $t9, 0xe700
/* 0C90F4 7F0945C4 25580008 */  addiu $t8, $t2, 8
/* 0C90F8 7F0945C8 AFB806B0 */  sw    $t8, 0x6b0($sp)
/* 0C90FC 7F0945CC AD400004 */  sw    $zero, 4($t2)
/* 0C9100 7F0945D0 AD590000 */  sw    $t9, ($t2)
/* 0C9104 7F0945D4 10000B62 */  b     .L7F097360
/* 0C9108 7F0945D8 8FA206B0 */   lw    $v0, 0x6b0($sp)
.L7F0945DC:
/* 0C910C 7F0945DC 8FAB06B0 */  lw    $t3, 0x6b0($sp)
/* 0C9110 7F0945E0 3C09E700 */  lui   $t1, 0xe700
/* 0C9114 7F0945E4 3C0FBA00 */  lui   $t7, (0xBA001402 >> 16) # lui $t7, 0xba00
/* 0C9118 7F0945E8 256D0008 */  addiu $t5, $t3, 8
/* 0C911C 7F0945EC AFAD06B0 */  sw    $t5, 0x6b0($sp)
/* 0C9120 7F0945F0 AD600004 */  sw    $zero, 4($t3)
/* 0C9124 7F0945F4 AD690000 */  sw    $t1, ($t3)
/* 0C9128 7F0945F8 8FAC06B0 */  lw    $t4, 0x6b0($sp)
/* 0C912C 7F0945FC 35EF1402 */  ori   $t7, (0xBA001402 & 0xFFFF) # ori $t7, $t7, 0x1402
/* 0C9130 7F094600 3C0A0030 */  lui   $t2, 0x30
/* 0C9134 7F094604 258E0008 */  addiu $t6, $t4, 8
/* 0C9138 7F094608 AFAE06B0 */  sw    $t6, 0x6b0($sp)
/* 0C913C 7F09460C AD8A0004 */  sw    $t2, 4($t4)
/* 0C9140 7F094610 AD8F0000 */  sw    $t7, ($t4)
/* 0C9144 7F094614 8FB806B0 */  lw    $t8, 0x6b0($sp)
/* 0C9148 7F094618 3C0BB900 */  lui   $t3, (0xB900031D >> 16) # lui $t3, 0xb900
/* 0C914C 7F09461C 356B031D */  ori   $t3, (0xB900031D & 0xFFFF) # ori $t3, $t3, 0x31d
/* 0C9150 7F094620 27190008 */  addiu $t9, $t8, 8
/* 0C9154 7F094624 AFB906B0 */  sw    $t9, 0x6b0($sp)
/* 0C9158 7F094628 AF000004 */  sw    $zero, 4($t8)
/* 0C915C 7F09462C AF0B0000 */  sw    $t3, ($t8)
/* 0C9160 7F094630 8FA606B0 */  lw    $a2, 0x6b0($sp)
/* 0C9164 7F094634 2508A0B0 */  addiu $t0, %lo(pPlayer) # addiu $t0, $t0, -0x5f50
/* 0C9168 7F094638 8D020000 */  lw    $v0, ($t0)
/* 0C916C 7F09463C 24CC0008 */  addiu $t4, $a2, 8
/* 0C9170 7F094640 AFAC06B0 */  sw    $t4, 0x6b0($sp)
/* 0C9174 7F094644 844E07F4 */  lh    $t6, 0x7f4($v0)
/* 0C9178 7F094648 844F07F0 */  lh    $t7, 0x7f0($v0)
/* 0C917C 7F09464C 844C07F6 */  lh    $t4, 0x7f6($v0)
/* 0C9180 7F094650 3C01F600 */  lui   $at, 0xf600
/* 0C9184 7F094654 01CF5021 */  addu  $t2, $t6, $t7
/* 0C9188 7F094658 844E07F2 */  lh    $t6, 0x7f2($v0)
/* 0C918C 7F09465C 2558FFFF */  addiu $t8, $t2, -1
/* 0C9190 7F094660 331903FF */  andi  $t9, $t8, 0x3ff
/* 0C9194 7F094664 018E7821 */  addu  $t7, $t4, $t6
/* 0C9198 7F094668 25EAFFFF */  addiu $t2, $t7, -1
/* 0C919C 7F09466C 00195B80 */  sll   $t3, $t9, 0xe
/* 0C91A0 7F094670 315803FF */  andi  $t8, $t2, 0x3ff
/* 0C91A4 7F094674 0018C880 */  sll   $t9, $t8, 2
/* 0C91A8 7F094678 01616825 */  or    $t5, $t3, $at
/* 0C91AC 7F09467C 01B95825 */  or    $t3, $t5, $t9
/* 0C91B0 7F094680 ACCB0000 */  sw    $t3, ($a2)
/* 0C91B4 7F094684 8D020000 */  lw    $v0, ($t0)
/* 0C91B8 7F094688 844C07F4 */  lh    $t4, 0x7f4($v0)
/* 0C91BC 7F09468C 844A07F6 */  lh    $t2, 0x7f6($v0)
/* 0C91C0 7F094690 318E03FF */  andi  $t6, $t4, 0x3ff
/* 0C91C4 7F094694 315803FF */  andi  $t8, $t2, 0x3ff
/* 0C91C8 7F094698 00186880 */  sll   $t5, $t8, 2
/* 0C91CC 7F09469C 000E7B80 */  sll   $t7, $t6, 0xe
/* 0C91D0 7F0946A0 01EDC825 */  or    $t9, $t7, $t5
/* 0C91D4 7F0946A4 ACD90004 */  sw    $t9, 4($a2)
/* 0C91D8 7F0946A8 8FAB06B0 */  lw    $t3, 0x6b0($sp)
/* 0C91DC 7F0946AC 256C0008 */  addiu $t4, $t3, 8
/* 0C91E0 7F0946B0 AFAC06B0 */  sw    $t4, 0x6b0($sp)
/* 0C91E4 7F0946B4 AD600004 */  sw    $zero, 4($t3)
/* 0C91E8 7F0946B8 AD690000 */  sw    $t1, ($t3)
/* 0C91EC 7F0946BC 10000B28 */  b     .L7F097360
/* 0C91F0 7F0946C0 8FA206B0 */   lw    $v0, 0x6b0($sp)
/* 0C91F4 7F0946C4 92050008 */  lbu   $a1, 8($s0)
.L7F0946C8:
/* 0C91F8 7F0946C8 92060009 */  lbu   $a2, 9($s0)
/* 0C91FC 7F0946CC 0C0011B4 */  jal   set_setfillcolor
/* 0C9200 7F0946D0 9207000A */   lbu   $a3, 0xa($s0)
/* 0C9204 7F0946D4 44806000 */  mtc1  $zero, $f12
/* 0C9208 7F0946D8 27B106A4 */  addiu $s1, $sp, 0x6a4
/* 0C920C 7F0946DC AFA206B0 */  sw    $v0, 0x6b0($sp)
/* 0C9210 7F0946E0 02203025 */  move  $a2, $s1
/* 0C9214 7F0946E4 0FC24E20 */  jal   sub_GAME_7F093880
/* 0C9218 7F0946E8 46006386 */   mov.s $f14, $f12
/* 0C921C 7F0946EC 0FC1E129 */  jal   getPlayer_c_screenwidth
/* 0C9220 7F0946F0 00000000 */   nop   
/* 0C9224 7F0946F4 3C018005 */  lui   $at, %hi(D_80057540)
/* 0C9228 7F0946F8 C43C7540 */  lwc1  $f28, %lo(D_80057540)($at)
/* 0C922C 7F0946FC 44807000 */  mtc1  $zero, $f14
/* 0C9230 7F094700 27A60698 */  addiu $a2, $sp, 0x698
/* 0C9234 7F094704 0FC24E20 */  jal   sub_GAME_7F093880
/* 0C9238 7F094708 461C0301 */   sub.s $f12, $f0, $f28
/* 0C923C 7F09470C 0FC1E12D */  jal   getPlayer_c_screenheight
/* 0C9240 7F094710 00000000 */   nop   
/* 0C9244 7F094714 44806000 */  mtc1  $zero, $f12
/* 0C9248 7F094718 461C0381 */  sub.s $f14, $f0, $f28
/* 0C924C 7F09471C 0FC24E20 */  jal   sub_GAME_7F093880
/* 0C9250 7F094720 27A6068C */   addiu $a2, $sp, 0x68c
/* 0C9254 7F094724 0FC1E129 */  jal   getPlayer_c_screenwidth
/* 0C9258 7F094728 00000000 */   nop   
/* 0C925C 7F09472C 0FC1E12D */  jal   getPlayer_c_screenheight
/* 0C9260 7F094730 46000586 */   mov.s $f22, $f0
/* 0C9264 7F094734 461CB301 */  sub.s $f12, $f22, $f28
/* 0C9268 7F094738 27A60680 */  addiu $a2, $sp, 0x680
/* 0C926C 7F09473C 0FC24E20 */  jal   sub_GAME_7F093880
/* 0C9270 7F094740 461C0381 */   sub.s $f14, $f0, $f28
/* 0C9274 7F094744 02202025 */  move  $a0, $s1
/* 0C9278 7F094748 27A50644 */  addiu $a1, $sp, 0x644
/* 0C927C 7F09474C 0FC24E3F */  jal   sub_GAME_7F0938FC
/* 0C9280 7F094750 27A6058C */   addiu $a2, $sp, 0x58c
/* 0C9284 7F094754 AFA20538 */  sw    $v0, 0x538($sp)
/* 0C9288 7F094758 27A40698 */  addiu $a0, $sp, 0x698
/* 0C928C 7F09475C 27A50638 */  addiu $a1, $sp, 0x638
/* 0C9290 7F094760 0FC24E3F */  jal   sub_GAME_7F0938FC
/* 0C9294 7F094764 27A60588 */   addiu $a2, $sp, 0x588
/* 0C9298 7F094768 AFA20534 */  sw    $v0, 0x534($sp)
/* 0C929C 7F09476C 27A4068C */  addiu $a0, $sp, 0x68c
/* 0C92A0 7F094770 27A5062C */  addiu $a1, $sp, 0x62c
/* 0C92A4 7F094774 0FC24E3F */  jal   sub_GAME_7F0938FC
/* 0C92A8 7F094778 27A60584 */   addiu $a2, $sp, 0x584
/* 0C92AC 7F09477C AFA20530 */  sw    $v0, 0x530($sp)
/* 0C92B0 7F094780 27A40680 */  addiu $a0, $sp, 0x680
/* 0C92B4 7F094784 27A50620 */  addiu $a1, $sp, 0x620
/* 0C92B8 7F094788 0FC24E3F */  jal   sub_GAME_7F0938FC
/* 0C92BC 7F09478C 27A60580 */   addiu $a2, $sp, 0x580
/* 0C92C0 7F094790 AFA2052C */  sw    $v0, 0x52c($sp)
/* 0C92C4 7F094794 02202025 */  move  $a0, $s1
/* 0C92C8 7F094798 27A505E4 */  addiu $a1, $sp, 0x5e4
/* 0C92CC 7F09479C 0FC24E9E */  jal   sub_GAME_7F093A78
/* 0C92D0 7F0947A0 27A6056C */   addiu $a2, $sp, 0x56c
/* 0C92D4 7F0947A4 27A40698 */  addiu $a0, $sp, 0x698
/* 0C92D8 7F0947A8 27A505D8 */  addiu $a1, $sp, 0x5d8
/* 0C92DC 7F0947AC 0FC24E9E */  jal   sub_GAME_7F093A78
/* 0C92E0 7F0947B0 27A60568 */   addiu $a2, $sp, 0x568
/* 0C92E4 7F0947B4 27A4068C */  addiu $a0, $sp, 0x68c
/* 0C92E8 7F0947B8 27A505CC */  addiu $a1, $sp, 0x5cc
/* 0C92EC 7F0947BC 0FC24E9E */  jal   sub_GAME_7F093A78
/* 0C92F0 7F0947C0 27A60564 */   addiu $a2, $sp, 0x564
/* 0C92F4 7F0947C4 27A40680 */  addiu $a0, $sp, 0x680
/* 0C92F8 7F0947C8 27A505C0 */  addiu $a1, $sp, 0x5c0
/* 0C92FC 7F0947CC 0FC24E9E */  jal   sub_GAME_7F093A78
/* 0C9300 7F0947D0 27A60560 */   addiu $a2, $sp, 0x560
/* 0C9304 7F0947D4 8FAE0538 */  lw    $t6, 0x538($sp)
/* 0C9308 7F0947D8 8FAA0530 */  lw    $t2, 0x530($sp)
/* 0C930C 7F0947DC 51CA001F */  beql  $t6, $t2, .L7F09485C
/* 0C9310 7F0947E0 44802000 */   mtc1  $zero, $f4
/* 0C9314 7F0947E4 0FC1E135 */  jal   getPlayer_c_screentop
/* 0C9318 7F0947E8 00000000 */   nop   
/* 0C931C 7F0947EC 0FC1E12D */  jal   getPlayer_c_screenheight
/* 0C9320 7F0947F0 46000586 */   mov.s $f22, $f0
/* 0C9324 7F0947F4 C7A206A8 */  lwc1  $f2, 0x6a8($sp)
/* 0C9328 7F0947F8 C7B00690 */  lwc1  $f16, 0x690($sp)
/* 0C932C 7F0947FC 27B0065C */  addiu $s0, $sp, 0x65c
/* 0C9330 7F094800 44806000 */  mtc1  $zero, $f12
/* 0C9334 7F094804 46101181 */  sub.s $f6, $f2, $f16
/* 0C9338 7F094808 02003025 */  move  $a2, $s0
/* 0C933C 7F09480C 46061203 */  div.s $f8, $f2, $f6
/* 0C9340 7F094810 46004282 */  mul.s $f10, $f8, $f0
/* 0C9344 7F094814 46165380 */  add.s $f14, $f10, $f22
/* 0C9348 7F094818 0FC24E20 */  jal   sub_GAME_7F093880
/* 0C934C 7F09481C E7AE054C */   swc1  $f14, 0x54c($sp)
/* 0C9350 7F094820 02202025 */  move  $a0, $s1
/* 0C9354 7F094824 27A5068C */  addiu $a1, $sp, 0x68c
/* 0C9358 7F094828 0FC24EFF */  jal   sub_GAME_7F093BFC
/* 0C935C 7F09482C 02003025 */   move  $a2, $s0
/* 0C9360 7F094830 02002025 */  move  $a0, $s0
/* 0C9364 7F094834 27A505FC */  addiu $a1, $sp, 0x5fc
/* 0C9368 7F094838 0FC24E3F */  jal   sub_GAME_7F0938FC
/* 0C936C 7F09483C 27A60574 */   addiu $a2, $sp, 0x574
/* 0C9370 7F094840 02002025 */  move  $a0, $s0
/* 0C9374 7F094844 27A5059C */  addiu $a1, $sp, 0x59c
/* 0C9378 7F094848 0FC24E9E */  jal   sub_GAME_7F093A78
/* 0C937C 7F09484C 27A60554 */   addiu $a2, $sp, 0x554
/* 0C9380 7F094850 10000005 */  b     .L7F094868
/* 0C9384 7F094854 8FB80534 */   lw    $t8, 0x534($sp)
/* 0C9388 7F094858 44802000 */  mtc1  $zero, $f4
.L7F09485C:
/* 0C938C 7F09485C 00000000 */  nop   
/* 0C9390 7F094860 E7A4054C */  swc1  $f4, 0x54c($sp)
/* 0C9394 7F094864 8FB80534 */  lw    $t8, 0x534($sp)
.L7F094868:
/* 0C9398 7F094868 8FAF052C */  lw    $t7, 0x52c($sp)
/* 0C939C 7F09486C 530F0021 */  beql  $t8, $t7, .L7F0948F4
/* 0C93A0 7F094870 44804000 */   mtc1  $zero, $f8
/* 0C93A4 7F094874 0FC1E135 */  jal   getPlayer_c_screentop
/* 0C93A8 7F094878 00000000 */   nop   
/* 0C93AC 7F09487C 0FC1E12D */  jal   getPlayer_c_screenheight
/* 0C93B0 7F094880 46000586 */   mov.s $f22, $f0
/* 0C93B4 7F094884 C7B0069C */  lwc1  $f16, 0x69c($sp)
/* 0C93B8 7F094888 C7A60684 */  lwc1  $f6, 0x684($sp)
/* 0C93BC 7F09488C 46068201 */  sub.s $f8, $f16, $f6
/* 0C93C0 7F094890 46088283 */  div.s $f10, $f16, $f8
/* 0C93C4 7F094894 46005102 */  mul.s $f4, $f10, $f0
/* 0C93C8 7F094898 46162180 */  add.s $f6, $f4, $f22
/* 0C93CC 7F09489C 0FC1E129 */  jal   getPlayer_c_screenwidth
/* 0C93D0 7F0948A0 E7A60548 */   swc1  $f6, 0x548($sp)
/* 0C93D4 7F0948A4 27B00650 */  addiu $s0, $sp, 0x650
/* 0C93D8 7F0948A8 02003025 */  move  $a2, $s0
/* 0C93DC 7F0948AC 461C0301 */  sub.s $f12, $f0, $f28
/* 0C93E0 7F0948B0 0FC24E20 */  jal   sub_GAME_7F093880
/* 0C93E4 7F0948B4 C7AE0548 */   lwc1  $f14, 0x548($sp)
/* 0C93E8 7F0948B8 27A40698 */  addiu $a0, $sp, 0x698
/* 0C93EC 7F0948BC 27A50680 */  addiu $a1, $sp, 0x680
/* 0C93F0 7F0948C0 0FC24EFF */  jal   sub_GAME_7F093BFC
/* 0C93F4 7F0948C4 02003025 */   move  $a2, $s0
/* 0C93F8 7F0948C8 02002025 */  move  $a0, $s0
/* 0C93FC 7F0948CC 27A505F0 */  addiu $a1, $sp, 0x5f0
/* 0C9400 7F0948D0 0FC24E3F */  jal   sub_GAME_7F0938FC
/* 0C9404 7F0948D4 27A60570 */   addiu $a2, $sp, 0x570
/* 0C9408 7F0948D8 02002025 */  move  $a0, $s0
/* 0C940C 7F0948DC 27A50590 */  addiu $a1, $sp, 0x590
/* 0C9410 7F0948E0 0FC24E9E */  jal   sub_GAME_7F093A78
/* 0C9414 7F0948E4 27A60550 */   addiu $a2, $sp, 0x550
/* 0C9418 7F0948E8 10000005 */  b     .L7F094900
/* 0C941C 7F0948EC 8FAD0538 */   lw    $t5, 0x538($sp)
/* 0C9420 7F0948F0 44804000 */  mtc1  $zero, $f8
.L7F0948F4:
/* 0C9424 7F0948F4 00000000 */  nop   
/* 0C9428 7F0948F8 E7A80548 */  swc1  $f8, 0x548($sp)
/* 0C942C 7F0948FC 8FAD0538 */  lw    $t5, 0x538($sp)
.L7F094900:
/* 0C9430 7F094900 8FB90534 */  lw    $t9, 0x534($sp)
/* 0C9434 7F094904 51B9001C */  beql  $t5, $t9, .L7F094978
/* 0C9438 7F094908 8FAB0530 */   lw    $t3, 0x530($sp)
/* 0C943C 7F09490C 0FC1E131 */  jal   getPlayer_c_screenleft
/* 0C9440 7F094910 00000000 */   nop   
/* 0C9444 7F094914 0FC1E129 */  jal   getPlayer_c_screenwidth
/* 0C9448 7F094918 46000586 */   mov.s $f22, $f0
/* 0C944C 7F09491C C7A206A8 */  lwc1  $f2, 0x6a8($sp)
/* 0C9450 7F094920 C7B0069C */  lwc1  $f16, 0x69c($sp)
/* 0C9454 7F094924 27B00674 */  addiu $s0, $sp, 0x674
/* 0C9458 7F094928 44807000 */  mtc1  $zero, $f14
/* 0C945C 7F09492C 46101281 */  sub.s $f10, $f2, $f16
/* 0C9460 7F094930 02003025 */  move  $a2, $s0
/* 0C9464 7F094934 460A1103 */  div.s $f4, $f2, $f10
/* 0C9468 7F094938 46002182 */  mul.s $f6, $f4, $f0
/* 0C946C 7F09493C 0FC24E20 */  jal   sub_GAME_7F093880
/* 0C9470 7F094940 46163300 */   add.s $f12, $f6, $f22
/* 0C9474 7F094944 02202025 */  move  $a0, $s1
/* 0C9478 7F094948 27A50698 */  addiu $a1, $sp, 0x698
/* 0C947C 7F09494C 0FC24EFF */  jal   sub_GAME_7F093BFC
/* 0C9480 7F094950 02003025 */   move  $a2, $s0
/* 0C9484 7F094954 02002025 */  move  $a0, $s0
/* 0C9488 7F094958 27A50614 */  addiu $a1, $sp, 0x614
/* 0C948C 7F09495C 0FC24E3F */  jal   sub_GAME_7F0938FC
/* 0C9490 7F094960 27A6057C */   addiu $a2, $sp, 0x57c
/* 0C9494 7F094964 02002025 */  move  $a0, $s0
/* 0C9498 7F094968 27A505B4 */  addiu $a1, $sp, 0x5b4
/* 0C949C 7F09496C 0FC24E9E */  jal   sub_GAME_7F093A78
/* 0C94A0 7F094970 27A6055C */   addiu $a2, $sp, 0x55c
/* 0C94A4 7F094974 8FAB0530 */  lw    $t3, 0x530($sp)
.L7F094978:
/* 0C94A8 7F094978 8FAC052C */  lw    $t4, 0x52c($sp)
/* 0C94AC 7F09497C 516C001E */  beql  $t3, $t4, .L7F0949F8
/* 0C94B0 7F094980 8FAE0538 */   lw    $t6, 0x538($sp)
/* 0C94B4 7F094984 0FC1E131 */  jal   getPlayer_c_screenleft
/* 0C94B8 7F094988 00000000 */   nop   
/* 0C94BC 7F09498C 0FC1E129 */  jal   getPlayer_c_screenwidth
/* 0C94C0 7F094990 46000586 */   mov.s $f22, $f0
/* 0C94C4 7F094994 C7B00690 */  lwc1  $f16, 0x690($sp)
/* 0C94C8 7F094998 C7A80684 */  lwc1  $f8, 0x684($sp)
/* 0C94CC 7F09499C 46088281 */  sub.s $f10, $f16, $f8
/* 0C94D0 7F0949A0 460A8103 */  div.s $f4, $f16, $f10
/* 0C94D4 7F0949A4 46002182 */  mul.s $f6, $f4, $f0
/* 0C94D8 7F0949A8 0FC1E12D */  jal   getPlayer_c_screenheight
/* 0C94DC 7F0949AC 46163500 */   add.s $f20, $f6, $f22
/* 0C94E0 7F0949B0 27B00668 */  addiu $s0, $sp, 0x668
/* 0C94E4 7F0949B4 02003025 */  move  $a2, $s0
/* 0C94E8 7F0949B8 4600A306 */  mov.s $f12, $f20
/* 0C94EC 7F0949BC 0FC24E20 */  jal   sub_GAME_7F093880
/* 0C94F0 7F0949C0 461C0381 */   sub.s $f14, $f0, $f28
/* 0C94F4 7F0949C4 27A4068C */  addiu $a0, $sp, 0x68c
/* 0C94F8 7F0949C8 27A50680 */  addiu $a1, $sp, 0x680
/* 0C94FC 7F0949CC 0FC24EFF */  jal   sub_GAME_7F093BFC
/* 0C9500 7F0949D0 02003025 */   move  $a2, $s0
/* 0C9504 7F0949D4 02002025 */  move  $a0, $s0
/* 0C9508 7F0949D8 27A50608 */  addiu $a1, $sp, 0x608
/* 0C950C 7F0949DC 0FC24E3F */  jal   sub_GAME_7F0938FC
/* 0C9510 7F0949E0 27A60578 */   addiu $a2, $sp, 0x578
/* 0C9514 7F0949E4 02002025 */  move  $a0, $s0
/* 0C9518 7F0949E8 27A505A8 */  addiu $a1, $sp, 0x5a8
/* 0C951C 7F0949EC 0FC24E9E */  jal   sub_GAME_7F093A78
/* 0C9520 7F0949F0 27A60558 */   addiu $a2, $sp, 0x558
/* 0C9524 7F0949F4 8FAE0538 */  lw    $t6, 0x538($sp)
.L7F0949F8:
/* 0C9528 7F0949F8 8FB80534 */  lw    $t8, 0x534($sp)
/* 0C952C 7F0949FC 8FB90530 */  lw    $t9, 0x530($sp)
/* 0C9530 7F094A00 000E50C0 */  sll   $t2, $t6, 3
/* 0C9534 7F094A04 8FAE052C */  lw    $t6, 0x52c($sp)
/* 0C9538 7F094A08 00187880 */  sll   $t7, $t8, 2
/* 0C953C 7F094A0C 014F6825 */  or    $t5, $t2, $t7
/* 0C9540 7F094A10 00195840 */  sll   $t3, $t9, 1
/* 0C9544 7F094A14 01AB6025 */  or    $t4, $t5, $t3
/* 0C9548 7F094A18 018EC025 */  or    $t8, $t4, $t6
/* 0C954C 7F094A1C 2F010010 */  sltiu $at, $t8, 0x10
/* 0C9550 7F094A20 10200360 */  beqz  $at, .L7F0957A4
/* 0C9554 7F094A24 AFB8005C */   sw    $t8, 0x5c($sp)
/* 0C9558 7F094A28 00185080 */  sll   $t2, $t8, 2
/* 0C955C 7F094A2C 3C018005 */  lui   $at, %hi(jpt_80057544)
/* 0C9560 7F094A30 002A0821 */  addu  $at, $at, $t2
/* 0C9564 7F094A34 8C2A7544 */  lw    $t2, %lo(jpt_80057544)($at)
.L7F094A38:
/* 0C9568 7F094A38 01400008 */  jr    $t2
/* 0C956C 7F094A3C 00000000 */   nop   
.L7F094A40:
/* 0C9570 7F094A40 1000035A */  b     .L7F0957AC
/* 0C9574 7F094A44 00008825 */   move  $s1, $zero
.L7F094A48:
/* 0C9578 7F094A48 C7A205E4 */  lwc1  $f2, 0x5e4($sp)
/* 0C957C 7F094A4C C7AA05E8 */  lwc1  $f10, 0x5e8($sp)
/* 0C9580 7F094A50 C7AC05EC */  lwc1  $f12, 0x5ec($sp)
/* 0C9584 7F094A54 46181202 */  mul.s $f8, $f2, $f24
/* 0C9588 7F094A58 C7AE05D8 */  lwc1  $f14, 0x5d8($sp)
/* 0C958C 7F094A5C C7B005E0 */  lwc1  $f16, 0x5e0($sp)
/* 0C9590 7F094A60 46185102 */  mul.s $f4, $f10, $f24
/* 0C9594 7F094A64 C7AA05DC */  lwc1  $f10, 0x5dc($sp)
/* 0C9598 7F094A68 C7B205CC */  lwc1  $f18, 0x5cc($sp)
/* 0C959C 7F094A6C 46186182 */  mul.s $f6, $f12, $f24
/* 0C95A0 7F094A70 E7A8043C */  swc1  $f8, 0x43c($sp)
/* 0C95A4 7F094A74 C7B405D4 */  lwc1  $f20, 0x5d4($sp)
/* 0C95A8 7F094A78 46187202 */  mul.s $f8, $f14, $f24
/* 0C95AC 7F094A7C E7A40440 */  swc1  $f4, 0x440($sp)
/* 0C95B0 7F094A80 C7B605C0 */  lwc1  $f22, 0x5c0($sp)
/* 0C95B4 7F094A84 46185102 */  mul.s $f4, $f10, $f24
/* 0C95B8 7F094A88 E7A60444 */  swc1  $f6, 0x444($sp)
/* 0C95BC 7F094A8C C7AA05D0 */  lwc1  $f10, 0x5d0($sp)
/* 0C95C0 7F094A90 46188182 */  mul.s $f6, $f16, $f24
/* 0C95C4 7F094A94 E7A80454 */  swc1  $f8, 0x454($sp)
/* 0C95C8 7F094A98 C7BA05C8 */  lwc1  $f26, 0x5c8($sp)
/* 0C95CC 7F094A9C 46189202 */  mul.s $f8, $f18, $f24
/* 0C95D0 7F094AA0 E7A40458 */  swc1  $f4, 0x458($sp)
/* 0C95D4 7F094AA4 3C018004 */  lui   $at, %hi(D_8003FD94)
/* 0C95D8 7F094AA8 46185102 */  mul.s $f4, $f10, $f24
/* 0C95DC 7F094AAC E7A6045C */  swc1  $f6, 0x45c($sp)
/* 0C95E0 7F094AB0 C7AA05C4 */  lwc1  $f10, 0x5c4($sp)
/* 0C95E4 7F094AB4 4618A182 */  mul.s $f6, $f20, $f24
/* 0C95E8 7F094AB8 E7A8046C */  swc1  $f8, 0x46c($sp)
/* 0C95EC 7F094ABC C420FD94 */  lwc1  $f0, %lo(D_8003FD94)($at)
/* 0C95F0 7F094AC0 4618B202 */  mul.s $f8, $f22, $f24
/* 0C95F4 7F094AC4 E7A40470 */  swc1  $f4, 0x470($sp)
/* 0C95F8 7F094AC8 24110004 */  li    $s1, 4
/* 0C95FC 7F094ACC 46185102 */  mul.s $f4, $f10, $f24
/* 0C9600 7F094AD0 E7A60474 */  swc1  $f6, 0x474($sp)
/* 0C9604 7F094AD4 46008280 */  add.s $f10, $f16, $f0
/* 0C9608 7F094AD8 4618D182 */  mul.s $f6, $f26, $f24
/* 0C960C 7F094ADC E7A80484 */  swc1  $f8, 0x484($sp)
/* 0C9610 7F094AE0 46006200 */  add.s $f8, $f12, $f0
/* 0C9614 7F094AE4 E7AA0464 */  swc1  $f10, 0x464($sp)
/* 0C9618 7F094AE8 E7A40488 */  swc1  $f4, 0x488($sp)
/* 0C961C 7F094AEC 4600A100 */  add.s $f4, $f20, $f0
/* 0C9620 7F094AF0 E7A8044C */  swc1  $f8, 0x44c($sp)
/* 0C9624 7F094AF4 E7A6048C */  swc1  $f6, 0x48c($sp)
/* 0C9628 7F094AF8 4600D180 */  add.s $f6, $f26, $f0
/* 0C962C 7F094AFC E7A4047C */  swc1  $f4, 0x47c($sp)
/* 0C9630 7F094B00 27A4043C */  addiu $a0, $sp, 0x43c
/* 0C9634 7F094B04 8FA5056C */  lw    $a1, 0x56c($sp)
/* 0C9638 7F094B08 E7A60494 */  swc1  $f6, 0x494($sp)
/* 0C963C 7F094B0C E7A20448 */  swc1  $f2, 0x448($sp)
/* 0C9640 7F094B10 E7AE0460 */  swc1  $f14, 0x460($sp)
/* 0C9644 7F094B14 E7B20478 */  swc1  $f18, 0x478($sp)
/* 0C9648 7F094B18 0FC24FE9 */  jal   sub_GAME_7F093FA4
/* 0C964C 7F094B1C E7B60490 */   swc1  $f22, 0x490($sp)
/* 0C9650 7F094B20 27A40454 */  addiu $a0, $sp, 0x454
/* 0C9654 7F094B24 0FC24FE9 */  jal   sub_GAME_7F093FA4
/* 0C9658 7F094B28 8FA50568 */   lw    $a1, 0x568($sp)
/* 0C965C 7F094B2C 27A4046C */  addiu $a0, $sp, 0x46c
/* 0C9660 7F094B30 0FC24FE9 */  jal   sub_GAME_7F093FA4
/* 0C9664 7F094B34 8FA50564 */   lw    $a1, 0x564($sp)
/* 0C9668 7F094B38 27A40484 */  addiu $a0, $sp, 0x484
/* 0C966C 7F094B3C 0FC24FE9 */  jal   sub_GAME_7F093FA4
/* 0C9670 7F094B40 8FA50560 */   lw    $a1, 0x560($sp)
/* 0C9674 7F094B44 10000319 */  b     .L7F0957AC
/* 0C9678 7F094B48 00000000 */   nop   
.L7F094B4C:
/* 0C967C 7F094B4C C7A205E4 */  lwc1  $f2, 0x5e4($sp)
/* 0C9680 7F094B50 C7AA05E8 */  lwc1  $f10, 0x5e8($sp)
/* 0C9684 7F094B54 C7AC05EC */  lwc1  $f12, 0x5ec($sp)
/* 0C9688 7F094B58 46181202 */  mul.s $f8, $f2, $f24
/* 0C968C 7F094B5C C7AE05D8 */  lwc1  $f14, 0x5d8($sp)
/* 0C9690 7F094B60 C7B005E0 */  lwc1  $f16, 0x5e0($sp)
/* 0C9694 7F094B64 46185102 */  mul.s $f4, $f10, $f24
/* 0C9698 7F094B68 C7AA05DC */  lwc1  $f10, 0x5dc($sp)
/* 0C969C 7F094B6C C7B2059C */  lwc1  $f18, 0x59c($sp)
/* 0C96A0 7F094B70 46186182 */  mul.s $f6, $f12, $f24
/* 0C96A4 7F094B74 E7A8043C */  swc1  $f8, 0x43c($sp)
/* 0C96A8 7F094B78 C7B405A4 */  lwc1  $f20, 0x5a4($sp)
/* 0C96AC 7F094B7C 46187202 */  mul.s $f8, $f14, $f24
/* 0C96B0 7F094B80 E7A40440 */  swc1  $f4, 0x440($sp)
/* 0C96B4 7F094B84 C7B60590 */  lwc1  $f22, 0x590($sp)
/* 0C96B8 7F094B88 46185102 */  mul.s $f4, $f10, $f24
/* 0C96BC 7F094B8C E7A60444 */  swc1  $f6, 0x444($sp)
/* 0C96C0 7F094B90 C7AA05A0 */  lwc1  $f10, 0x5a0($sp)
/* 0C96C4 7F094B94 46188182 */  mul.s $f6, $f16, $f24
/* 0C96C8 7F094B98 E7A80454 */  swc1  $f8, 0x454($sp)
/* 0C96CC 7F094B9C C7BA0598 */  lwc1  $f26, 0x598($sp)
/* 0C96D0 7F094BA0 46189202 */  mul.s $f8, $f18, $f24
/* 0C96D4 7F094BA4 E7A40458 */  swc1  $f4, 0x458($sp)
/* 0C96D8 7F094BA8 3C018004 */  lui   $at, %hi(D_8003FD94)
/* 0C96DC 7F094BAC 46185102 */  mul.s $f4, $f10, $f24
/* 0C96E0 7F094BB0 E7A6045C */  swc1  $f6, 0x45c($sp)
/* 0C96E4 7F094BB4 C7AA0594 */  lwc1  $f10, 0x594($sp)
/* 0C96E8 7F094BB8 4618A182 */  mul.s $f6, $f20, $f24
/* 0C96EC 7F094BBC E7A8046C */  swc1  $f8, 0x46c($sp)
/* 0C96F0 7F094BC0 C420FD94 */  lwc1  $f0, %lo(D_8003FD94)($at)
/* 0C96F4 7F094BC4 4618B202 */  mul.s $f8, $f22, $f24
/* 0C96F8 7F094BC8 E7A40470 */  swc1  $f4, 0x470($sp)
/* 0C96FC 7F094BCC 24110004 */  li    $s1, 4
/* 0C9700 7F094BD0 46185102 */  mul.s $f4, $f10, $f24
/* 0C9704 7F094BD4 E7A60474 */  swc1  $f6, 0x474($sp)
/* 0C9708 7F094BD8 46008280 */  add.s $f10, $f16, $f0
/* 0C970C 7F094BDC 4618D182 */  mul.s $f6, $f26, $f24
/* 0C9710 7F094BE0 E7A80484 */  swc1  $f8, 0x484($sp)
/* 0C9714 7F094BE4 46006200 */  add.s $f8, $f12, $f0
/* 0C9718 7F094BE8 E7AA0464 */  swc1  $f10, 0x464($sp)
/* 0C971C 7F094BEC E7A40488 */  swc1  $f4, 0x488($sp)
/* 0C9720 7F094BF0 4600A100 */  add.s $f4, $f20, $f0
/* 0C9724 7F094BF4 E7A8044C */  swc1  $f8, 0x44c($sp)
/* 0C9728 7F094BF8 E7A6048C */  swc1  $f6, 0x48c($sp)
/* 0C972C 7F094BFC 4600D180 */  add.s $f6, $f26, $f0
/* 0C9730 7F094C00 E7A4047C */  swc1  $f4, 0x47c($sp)
/* 0C9734 7F094C04 27A4043C */  addiu $a0, $sp, 0x43c
/* 0C9738 7F094C08 8FA5056C */  lw    $a1, 0x56c($sp)
/* 0C973C 7F094C0C E7A60494 */  swc1  $f6, 0x494($sp)
/* 0C9740 7F094C10 E7A20448 */  swc1  $f2, 0x448($sp)
/* 0C9744 7F094C14 E7AE0460 */  swc1  $f14, 0x460($sp)
/* 0C9748 7F094C18 E7B20478 */  swc1  $f18, 0x478($sp)
/* 0C974C 7F094C1C 0FC24FE9 */  jal   sub_GAME_7F093FA4
/* 0C9750 7F094C20 E7B60490 */   swc1  $f22, 0x490($sp)
/* 0C9754 7F094C24 27A40454 */  addiu $a0, $sp, 0x454
/* 0C9758 7F094C28 0FC24FE9 */  jal   sub_GAME_7F093FA4
/* 0C975C 7F094C2C 8FA50568 */   lw    $a1, 0x568($sp)
/* 0C9760 7F094C30 27A4046C */  addiu $a0, $sp, 0x46c
/* 0C9764 7F094C34 0FC24FE9 */  jal   sub_GAME_7F093FA4
/* 0C9768 7F094C38 8FA50554 */   lw    $a1, 0x554($sp)
/* 0C976C 7F094C3C 27A40484 */  addiu $a0, $sp, 0x484
/* 0C9770 7F094C40 0FC24FE9 */  jal   sub_GAME_7F093FA4
/* 0C9774 7F094C44 8FA50550 */   lw    $a1, 0x550($sp)
/* 0C9778 7F094C48 100002D8 */  b     .L7F0957AC
/* 0C977C 7F094C4C 00000000 */   nop   
.L7F094C50:
/* 0C9780 7F094C50 C7B605C0 */  lwc1  $f22, 0x5c0($sp)
/* 0C9784 7F094C54 C7AA05C4 */  lwc1  $f10, 0x5c4($sp)
/* 0C9788 7F094C58 C7BA05C8 */  lwc1  $f26, 0x5c8($sp)
/* 0C978C 7F094C5C 4618B202 */  mul.s $f8, $f22, $f24
/* 0C9790 7F094C60 C7B205CC */  lwc1  $f18, 0x5cc($sp)
/* 0C9794 7F094C64 C7B405D4 */  lwc1  $f20, 0x5d4($sp)
/* 0C9798 7F094C68 46185102 */  mul.s $f4, $f10, $f24
/* 0C979C 7F094C6C C7AA05D0 */  lwc1  $f10, 0x5d0($sp)
/* 0C97A0 7F094C70 C7AE0590 */  lwc1  $f14, 0x590($sp)
/* 0C97A4 7F094C74 4618D182 */  mul.s $f6, $f26, $f24
/* 0C97A8 7F094C78 E7A8043C */  swc1  $f8, 0x43c($sp)
/* 0C97AC 7F094C7C C7B00598 */  lwc1  $f16, 0x598($sp)
/* 0C97B0 7F094C80 46189202 */  mul.s $f8, $f18, $f24
/* 0C97B4 7F094C84 E7A40440 */  swc1  $f4, 0x440($sp)
/* 0C97B8 7F094C88 C7A2059C */  lwc1  $f2, 0x59c($sp)
/* 0C97BC 7F094C8C 46185102 */  mul.s $f4, $f10, $f24
/* 0C97C0 7F094C90 E7A60444 */  swc1  $f6, 0x444($sp)
/* 0C97C4 7F094C94 C7AA0594 */  lwc1  $f10, 0x594($sp)
/* 0C97C8 7F094C98 4618A182 */  mul.s $f6, $f20, $f24
/* 0C97CC 7F094C9C E7A80454 */  swc1  $f8, 0x454($sp)
/* 0C97D0 7F094CA0 C7AC05A4 */  lwc1  $f12, 0x5a4($sp)
/* 0C97D4 7F094CA4 46187202 */  mul.s $f8, $f14, $f24
/* 0C97D8 7F094CA8 E7A40458 */  swc1  $f4, 0x458($sp)
/* 0C97DC 7F094CAC 3C018004 */  lui   $at, %hi(D_8003FD94)
/* 0C97E0 7F094CB0 46185102 */  mul.s $f4, $f10, $f24
/* 0C97E4 7F094CB4 E7A6045C */  swc1  $f6, 0x45c($sp)
/* 0C97E8 7F094CB8 C7AA05A0 */  lwc1  $f10, 0x5a0($sp)
/* 0C97EC 7F094CBC 46188182 */  mul.s $f6, $f16, $f24
/* 0C97F0 7F094CC0 E7A8046C */  swc1  $f8, 0x46c($sp)
/* 0C97F4 7F094CC4 C420FD94 */  lwc1  $f0, %lo(D_8003FD94)($at)
/* 0C97F8 7F094CC8 46181202 */  mul.s $f8, $f2, $f24
/* 0C97FC 7F094CCC E7A40470 */  swc1  $f4, 0x470($sp)
/* 0C9800 7F094CD0 240F0001 */  li    $t7, 1
/* 0C9804 7F094CD4 46185102 */  mul.s $f4, $f10, $f24
/* 0C9808 7F094CD8 E7A60474 */  swc1  $f6, 0x474($sp)
/* 0C980C 7F094CDC 4600A280 */  add.s $f10, $f20, $f0
/* 0C9810 7F094CE0 46186182 */  mul.s $f6, $f12, $f24
/* 0C9814 7F094CE4 E7A80484 */  swc1  $f8, 0x484($sp)
/* 0C9818 7F094CE8 4600D200 */  add.s $f8, $f26, $f0
/* 0C981C 7F094CEC 24110004 */  li    $s1, 4
/* 0C9820 7F094CF0 E7A40488 */  swc1  $f4, 0x488($sp)
/* 0C9824 7F094CF4 46008100 */  add.s $f4, $f16, $f0
/* 0C9828 7F094CF8 AFAF0430 */  sw    $t7, 0x430($sp)
/* 0C982C 7F094CFC E7A6048C */  swc1  $f6, 0x48c($sp)
/* 0C9830 7F094D00 46006180 */  add.s $f6, $f12, $f0
/* 0C9834 7F094D04 E7A8044C */  swc1  $f8, 0x44c($sp)
/* 0C9838 7F094D08 E7AA0464 */  swc1  $f10, 0x464($sp)
/* 0C983C 7F094D0C E7A4047C */  swc1  $f4, 0x47c($sp)
/* 0C9840 7F094D10 E7A60494 */  swc1  $f6, 0x494($sp)
/* 0C9844 7F094D14 27A4043C */  addiu $a0, $sp, 0x43c
/* 0C9848 7F094D18 8FA50560 */  lw    $a1, 0x560($sp)
/* 0C984C 7F094D1C E7B60448 */  swc1  $f22, 0x448($sp)
/* 0C9850 7F094D20 E7B20460 */  swc1  $f18, 0x460($sp)
/* 0C9854 7F094D24 E7AE0478 */  swc1  $f14, 0x478($sp)
/* 0C9858 7F094D28 0FC24FE9 */  jal   sub_GAME_7F093FA4
/* 0C985C 7F094D2C E7A20490 */   swc1  $f2, 0x490($sp)
/* 0C9860 7F094D30 27A40454 */  addiu $a0, $sp, 0x454
/* 0C9864 7F094D34 0FC24FE9 */  jal   sub_GAME_7F093FA4
/* 0C9868 7F094D38 8FA50564 */   lw    $a1, 0x564($sp)
/* 0C986C 7F094D3C 27A4046C */  addiu $a0, $sp, 0x46c
/* 0C9870 7F094D40 0FC24FE9 */  jal   sub_GAME_7F093FA4
/* 0C9874 7F094D44 8FA50550 */   lw    $a1, 0x550($sp)
/* 0C9878 7F094D48 27A40484 */  addiu $a0, $sp, 0x484
/* 0C987C 7F094D4C 0FC24FE9 */  jal   sub_GAME_7F093FA4
/* 0C9880 7F094D50 8FA50554 */   lw    $a1, 0x554($sp)
/* 0C9884 7F094D54 10000295 */  b     .L7F0957AC
/* 0C9888 7F094D58 00000000 */   nop   
.L7F094D5C:
/* 0C988C 7F094D5C C7AE05D8 */  lwc1  $f14, 0x5d8($sp)
/* 0C9890 7F094D60 C7AA05DC */  lwc1  $f10, 0x5dc($sp)
/* 0C9894 7F094D64 C7B005E0 */  lwc1  $f16, 0x5e0($sp)
/* 0C9898 7F094D68 46187202 */  mul.s $f8, $f14, $f24
/* 0C989C 7F094D6C C7B605C0 */  lwc1  $f22, 0x5c0($sp)
/* 0C98A0 7F094D70 C7BA05C8 */  lwc1  $f26, 0x5c8($sp)
/* 0C98A4 7F094D74 46185102 */  mul.s $f4, $f10, $f24
/* 0C98A8 7F094D78 C7AA05C4 */  lwc1  $f10, 0x5c4($sp)
/* 0C98AC 7F094D7C C7A205B4 */  lwc1  $f2, 0x5b4($sp)
/* 0C98B0 7F094D80 46188182 */  mul.s $f6, $f16, $f24
/* 0C98B4 7F094D84 E7A8043C */  swc1  $f8, 0x43c($sp)
/* 0C98B8 7F094D88 C7AC05BC */  lwc1  $f12, 0x5bc($sp)
/* 0C98BC 7F094D8C 4618B202 */  mul.s $f8, $f22, $f24
/* 0C98C0 7F094D90 E7A40440 */  swc1  $f4, 0x440($sp)
/* 0C98C4 7F094D94 C7B205A8 */  lwc1  $f18, 0x5a8($sp)
/* 0C98C8 7F094D98 46185102 */  mul.s $f4, $f10, $f24
/* 0C98CC 7F094D9C E7A60444 */  swc1  $f6, 0x444($sp)
/* 0C98D0 7F094DA0 C7AA05B8 */  lwc1  $f10, 0x5b8($sp)
/* 0C98D4 7F094DA4 4618D182 */  mul.s $f6, $f26, $f24
/* 0C98D8 7F094DA8 E7A80454 */  swc1  $f8, 0x454($sp)
/* 0C98DC 7F094DAC C7B405B0 */  lwc1  $f20, 0x5b0($sp)
/* 0C98E0 7F094DB0 46181202 */  mul.s $f8, $f2, $f24
/* 0C98E4 7F094DB4 E7A40458 */  swc1  $f4, 0x458($sp)
/* 0C98E8 7F094DB8 3C018004 */  lui   $at, %hi(D_8003FD94)
/* 0C98EC 7F094DBC 46185102 */  mul.s $f4, $f10, $f24
/* 0C98F0 7F094DC0 E7A6045C */  swc1  $f6, 0x45c($sp)
/* 0C98F4 7F094DC4 C7AA05AC */  lwc1  $f10, 0x5ac($sp)
/* 0C98F8 7F094DC8 46186182 */  mul.s $f6, $f12, $f24
/* 0C98FC 7F094DCC E7A8046C */  swc1  $f8, 0x46c($sp)
/* 0C9900 7F094DD0 C420FD94 */  lwc1  $f0, %lo(D_8003FD94)($at)
/* 0C9904 7F094DD4 46189202 */  mul.s $f8, $f18, $f24
/* 0C9908 7F094DD8 E7A40470 */  swc1  $f4, 0x470($sp)
/* 0C990C 7F094DDC 24110004 */  li    $s1, 4
/* 0C9910 7F094DE0 46185102 */  mul.s $f4, $f10, $f24
/* 0C9914 7F094DE4 E7A60474 */  swc1  $f6, 0x474($sp)
/* 0C9918 7F094DE8 4600D280 */  add.s $f10, $f26, $f0
/* 0C991C 7F094DEC 4618A182 */  mul.s $f6, $f20, $f24
/* 0C9920 7F094DF0 E7A80484 */  swc1  $f8, 0x484($sp)
/* 0C9924 7F094DF4 46008200 */  add.s $f8, $f16, $f0
/* 0C9928 7F094DF8 E7AA0464 */  swc1  $f10, 0x464($sp)
/* 0C992C 7F094DFC E7A40488 */  swc1  $f4, 0x488($sp)
/* 0C9930 7F094E00 46006100 */  add.s $f4, $f12, $f0
/* 0C9934 7F094E04 E7A8044C */  swc1  $f8, 0x44c($sp)
/* 0C9938 7F094E08 E7A6048C */  swc1  $f6, 0x48c($sp)
/* 0C993C 7F094E0C 4600A180 */  add.s $f6, $f20, $f0
/* 0C9940 7F094E10 E7A4047C */  swc1  $f4, 0x47c($sp)
/* 0C9944 7F094E14 27A4043C */  addiu $a0, $sp, 0x43c
/* 0C9948 7F094E18 8FA50568 */  lw    $a1, 0x568($sp)
/* 0C994C 7F094E1C E7A60494 */  swc1  $f6, 0x494($sp)
/* 0C9950 7F094E20 E7AE0448 */  swc1  $f14, 0x448($sp)
/* 0C9954 7F094E24 E7B60460 */  swc1  $f22, 0x460($sp)
/* 0C9958 7F094E28 E7A20478 */  swc1  $f2, 0x478($sp)
/* 0C995C 7F094E2C 0FC24FE9 */  jal   sub_GAME_7F093FA4
/* 0C9960 7F094E30 E7B20490 */   swc1  $f18, 0x490($sp)
/* 0C9964 7F094E34 27A40454 */  addiu $a0, $sp, 0x454
/* 0C9968 7F094E38 0FC24FE9 */  jal   sub_GAME_7F093FA4
/* 0C996C 7F094E3C 8FA50560 */   lw    $a1, 0x560($sp)
/* 0C9970 7F094E40 27A4046C */  addiu $a0, $sp, 0x46c
/* 0C9974 7F094E44 0FC24FE9 */  jal   sub_GAME_7F093FA4
/* 0C9978 7F094E48 8FA5055C */   lw    $a1, 0x55c($sp)
/* 0C997C 7F094E4C 27A40484 */  addiu $a0, $sp, 0x484
/* 0C9980 7F094E50 0FC24FE9 */  jal   sub_GAME_7F093FA4
/* 0C9984 7F094E54 8FA50558 */   lw    $a1, 0x558($sp)
/* 0C9988 7F094E58 10000254 */  b     .L7F0957AC
/* 0C998C 7F094E5C 00000000 */   nop   
.L7F094E60:
/* 0C9990 7F094E60 C7B205CC */  lwc1  $f18, 0x5cc($sp)
/* 0C9994 7F094E64 C7AA05D0 */  lwc1  $f10, 0x5d0($sp)
/* 0C9998 7F094E68 C7B405D4 */  lwc1  $f20, 0x5d4($sp)
/* 0C999C 7F094E6C 46189202 */  mul.s $f8, $f18, $f24
/* 0C99A0 7F094E70 C7A205E4 */  lwc1  $f2, 0x5e4($sp)
/* 0C99A4 7F094E74 C7AC05EC */  lwc1  $f12, 0x5ec($sp)
/* 0C99A8 7F094E78 46185102 */  mul.s $f4, $f10, $f24
/* 0C99AC 7F094E7C C7AA05E8 */  lwc1  $f10, 0x5e8($sp)
/* 0C99B0 7F094E80 C7B605A8 */  lwc1  $f22, 0x5a8($sp)
/* 0C99B4 7F094E84 4618A182 */  mul.s $f6, $f20, $f24
/* 0C99B8 7F094E88 E7A8043C */  swc1  $f8, 0x43c($sp)
/* 0C99BC 7F094E8C C7BA05B0 */  lwc1  $f26, 0x5b0($sp)
/* 0C99C0 7F094E90 46181202 */  mul.s $f8, $f2, $f24
/* 0C99C4 7F094E94 E7A40440 */  swc1  $f4, 0x440($sp)
/* 0C99C8 7F094E98 C7AE05B4 */  lwc1  $f14, 0x5b4($sp)
/* 0C99CC 7F094E9C 46185102 */  mul.s $f4, $f10, $f24
/* 0C99D0 7F094EA0 E7A60444 */  swc1  $f6, 0x444($sp)
/* 0C99D4 7F094EA4 C7AA05AC */  lwc1  $f10, 0x5ac($sp)
/* 0C99D8 7F094EA8 46186182 */  mul.s $f6, $f12, $f24
/* 0C99DC 7F094EAC E7A80454 */  swc1  $f8, 0x454($sp)
/* 0C99E0 7F094EB0 C7B005BC */  lwc1  $f16, 0x5bc($sp)
/* 0C99E4 7F094EB4 4618B202 */  mul.s $f8, $f22, $f24
/* 0C99E8 7F094EB8 E7A40458 */  swc1  $f4, 0x458($sp)
/* 0C99EC 7F094EBC 3C018004 */  lui   $at, %hi(D_8003FD94)
/* 0C99F0 7F094EC0 46185102 */  mul.s $f4, $f10, $f24
/* 0C99F4 7F094EC4 E7A6045C */  swc1  $f6, 0x45c($sp)
/* 0C99F8 7F094EC8 C7AA05B8 */  lwc1  $f10, 0x5b8($sp)
/* 0C99FC 7F094ECC 4618D182 */  mul.s $f6, $f26, $f24
/* 0C9A00 7F094ED0 E7A8046C */  swc1  $f8, 0x46c($sp)
/* 0C9A04 7F094ED4 C420FD94 */  lwc1  $f0, %lo(D_8003FD94)($at)
/* 0C9A08 7F094ED8 46187202 */  mul.s $f8, $f14, $f24
/* 0C9A0C 7F094EDC E7A40470 */  swc1  $f4, 0x470($sp)
/* 0C9A10 7F094EE0 24110004 */  li    $s1, 4
/* 0C9A14 7F094EE4 46185102 */  mul.s $f4, $f10, $f24
/* 0C9A18 7F094EE8 E7A60474 */  swc1  $f6, 0x474($sp)
/* 0C9A1C 7F094EEC 46006280 */  add.s $f10, $f12, $f0
/* 0C9A20 7F094EF0 46188182 */  mul.s $f6, $f16, $f24
/* 0C9A24 7F094EF4 E7A80484 */  swc1  $f8, 0x484($sp)
/* 0C9A28 7F094EF8 4600A200 */  add.s $f8, $f20, $f0
/* 0C9A2C 7F094EFC E7AA0464 */  swc1  $f10, 0x464($sp)
/* 0C9A30 7F094F00 E7A40488 */  swc1  $f4, 0x488($sp)
/* 0C9A34 7F094F04 4600D100 */  add.s $f4, $f26, $f0
/* 0C9A38 7F094F08 E7A8044C */  swc1  $f8, 0x44c($sp)
/* 0C9A3C 7F094F0C E7A6048C */  swc1  $f6, 0x48c($sp)
/* 0C9A40 7F094F10 46008180 */  add.s $f6, $f16, $f0
/* 0C9A44 7F094F14 E7A4047C */  swc1  $f4, 0x47c($sp)
/* 0C9A48 7F094F18 27A4043C */  addiu $a0, $sp, 0x43c
/* 0C9A4C 7F094F1C 8FA50564 */  lw    $a1, 0x564($sp)
/* 0C9A50 7F094F20 E7A60494 */  swc1  $f6, 0x494($sp)
/* 0C9A54 7F094F24 E7B20448 */  swc1  $f18, 0x448($sp)
/* 0C9A58 7F094F28 E7A20460 */  swc1  $f2, 0x460($sp)
/* 0C9A5C 7F094F2C E7B60478 */  swc1  $f22, 0x478($sp)
/* 0C9A60 7F094F30 0FC24FE9 */  jal   sub_GAME_7F093FA4
/* 0C9A64 7F094F34 E7AE0490 */   swc1  $f14, 0x490($sp)
/* 0C9A68 7F094F38 27A40454 */  addiu $a0, $sp, 0x454
/* 0C9A6C 7F094F3C 0FC24FE9 */  jal   sub_GAME_7F093FA4
/* 0C9A70 7F094F40 8FA5056C */   lw    $a1, 0x56c($sp)
/* 0C9A74 7F094F44 27A4046C */  addiu $a0, $sp, 0x46c
/* 0C9A78 7F094F48 0FC24FE9 */  jal   sub_GAME_7F093FA4
/* 0C9A7C 7F094F4C 8FA50558 */   lw    $a1, 0x558($sp)
/* 0C9A80 7F094F50 27A40484 */  addiu $a0, $sp, 0x484
/* 0C9A84 7F094F54 0FC24FE9 */  jal   sub_GAME_7F093FA4
/* 0C9A88 7F094F58 8FA5055C */   lw    $a1, 0x55c($sp)
/* 0C9A8C 7F094F5C 10000213 */  b     .L7F0957AC
/* 0C9A90 7F094F60 00000000 */   nop   
.L7F094F64:
/* 0C9A94 7F094F64 C7B605C0 */  lwc1  $f22, 0x5c0($sp)
/* 0C9A98 7F094F68 C7AA05C4 */  lwc1  $f10, 0x5c4($sp)
/* 0C9A9C 7F094F6C C7BA05C8 */  lwc1  $f26, 0x5c8($sp)
/* 0C9AA0 7F094F70 4618B202 */  mul.s $f8, $f22, $f24
/* 0C9AA4 7F094F74 C7AE05A8 */  lwc1  $f14, 0x5a8($sp)
/* 0C9AA8 7F094F78 C7B005B0 */  lwc1  $f16, 0x5b0($sp)
/* 0C9AAC 7F094F7C 46185102 */  mul.s $f4, $f10, $f24
/* 0C9AB0 7F094F80 C7AA05AC */  lwc1  $f10, 0x5ac($sp)
/* 0C9AB4 7F094F84 C7A20590 */  lwc1  $f2, 0x590($sp)
/* 0C9AB8 7F094F88 4618D182 */  mul.s $f6, $f26, $f24
/* 0C9ABC 7F094F8C E7A8043C */  swc1  $f8, 0x43c($sp)
/* 0C9AC0 7F094F90 C7AC0598 */  lwc1  $f12, 0x598($sp)
/* 0C9AC4 7F094F94 46187202 */  mul.s $f8, $f14, $f24
/* 0C9AC8 7F094F98 E7A40440 */  swc1  $f4, 0x440($sp)
/* 0C9ACC 7F094F9C 3C018004 */  lui   $at, %hi(D_8003FD94)
/* 0C9AD0 7F094FA0 46185102 */  mul.s $f4, $f10, $f24
/* 0C9AD4 7F094FA4 E7A60444 */  swc1  $f6, 0x444($sp)
/* 0C9AD8 7F094FA8 C7AA0594 */  lwc1  $f10, 0x594($sp)
/* 0C9ADC 7F094FAC 46188182 */  mul.s $f6, $f16, $f24
/* 0C9AE0 7F094FB0 E7A80454 */  swc1  $f8, 0x454($sp)
/* 0C9AE4 7F094FB4 C420FD94 */  lwc1  $f0, %lo(D_8003FD94)($at)
/* 0C9AE8 7F094FB8 46181202 */  mul.s $f8, $f2, $f24
/* 0C9AEC 7F094FBC E7A40458 */  swc1  $f4, 0x458($sp)
/* 0C9AF0 7F094FC0 24110003 */  li    $s1, 3
/* 0C9AF4 7F094FC4 46185102 */  mul.s $f4, $f10, $f24
/* 0C9AF8 7F094FC8 E7A6045C */  swc1  $f6, 0x45c($sp)
/* 0C9AFC 7F094FCC 46008280 */  add.s $f10, $f16, $f0
/* 0C9B00 7F094FD0 46186182 */  mul.s $f6, $f12, $f24
/* 0C9B04 7F094FD4 E7A8046C */  swc1  $f8, 0x46c($sp)
/* 0C9B08 7F094FD8 4600D200 */  add.s $f8, $f26, $f0
/* 0C9B0C 7F094FDC E7AA0464 */  swc1  $f10, 0x464($sp)
/* 0C9B10 7F094FE0 E7A40470 */  swc1  $f4, 0x470($sp)
/* 0C9B14 7F094FE4 46006100 */  add.s $f4, $f12, $f0
/* 0C9B18 7F094FE8 E7A8044C */  swc1  $f8, 0x44c($sp)
/* 0C9B1C 7F094FEC E7A60474 */  swc1  $f6, 0x474($sp)
/* 0C9B20 7F094FF0 27A4043C */  addiu $a0, $sp, 0x43c
/* 0C9B24 7F094FF4 E7A4047C */  swc1  $f4, 0x47c($sp)
/* 0C9B28 7F094FF8 8FA50560 */  lw    $a1, 0x560($sp)
/* 0C9B2C 7F094FFC E7B60448 */  swc1  $f22, 0x448($sp)
/* 0C9B30 7F095000 E7AE0460 */  swc1  $f14, 0x460($sp)
/* 0C9B34 7F095004 0FC24FE9 */  jal   sub_GAME_7F093FA4
/* 0C9B38 7F095008 E7A20478 */   swc1  $f2, 0x478($sp)
/* 0C9B3C 7F09500C 27A40454 */  addiu $a0, $sp, 0x454
/* 0C9B40 7F095010 0FC24FE9 */  jal   sub_GAME_7F093FA4
/* 0C9B44 7F095014 8FA50558 */   lw    $a1, 0x558($sp)
/* 0C9B48 7F095018 27A4046C */  addiu $a0, $sp, 0x46c
/* 0C9B4C 7F09501C 0FC24FE9 */  jal   sub_GAME_7F093FA4
/* 0C9B50 7F095020 8FA50550 */   lw    $a1, 0x550($sp)
/* 0C9B54 7F095024 100001E1 */  b     .L7F0957AC
/* 0C9B58 7F095028 00000000 */   nop   
.L7F09502C:
/* 0C9B5C 7F09502C C7B205CC */  lwc1  $f18, 0x5cc($sp)
/* 0C9B60 7F095030 C7A805D0 */  lwc1  $f8, 0x5d0($sp)
/* 0C9B64 7F095034 C7B405D4 */  lwc1  $f20, 0x5d4($sp)
/* 0C9B68 7F095038 46189182 */  mul.s $f6, $f18, $f24
/* 0C9B6C 7F09503C C7A2059C */  lwc1  $f2, 0x59c($sp)
/* 0C9B70 7F095040 C7AC05A4 */  lwc1  $f12, 0x5a4($sp)
/* 0C9B74 7F095044 46184282 */  mul.s $f10, $f8, $f24
/* 0C9B78 7F095048 C7A805A0 */  lwc1  $f8, 0x5a0($sp)
/* 0C9B7C 7F09504C C7AE05A8 */  lwc1  $f14, 0x5a8($sp)
/* 0C9B80 7F095050 4618A102 */  mul.s $f4, $f20, $f24
/* 0C9B84 7F095054 E7A6043C */  swc1  $f6, 0x43c($sp)
/* 0C9B88 7F095058 C7B005B0 */  lwc1  $f16, 0x5b0($sp)
/* 0C9B8C 7F09505C 46181182 */  mul.s $f6, $f2, $f24
/* 0C9B90 7F095060 E7AA0440 */  swc1  $f10, 0x440($sp)
/* 0C9B94 7F095064 3C018004 */  lui   $at, %hi(D_8003FD94)
/* 0C9B98 7F095068 46184282 */  mul.s $f10, $f8, $f24
/* 0C9B9C 7F09506C E7A40444 */  swc1  $f4, 0x444($sp)
/* 0C9BA0 7F095070 C7A805AC */  lwc1  $f8, 0x5ac($sp)
/* 0C9BA4 7F095074 46186102 */  mul.s $f4, $f12, $f24
/* 0C9BA8 7F095078 E7A60454 */  swc1  $f6, 0x454($sp)
/* 0C9BAC 7F09507C C420FD94 */  lwc1  $f0, %lo(D_8003FD94)($at)
/* 0C9BB0 7F095080 46187182 */  mul.s $f6, $f14, $f24
/* 0C9BB4 7F095084 E7AA0458 */  swc1  $f10, 0x458($sp)
/* 0C9BB8 7F095088 24110003 */  li    $s1, 3
/* 0C9BBC 7F09508C 46184282 */  mul.s $f10, $f8, $f24
/* 0C9BC0 7F095090 E7A4045C */  swc1  $f4, 0x45c($sp)
/* 0C9BC4 7F095094 46006200 */  add.s $f8, $f12, $f0
/* 0C9BC8 7F095098 46188102 */  mul.s $f4, $f16, $f24
/* 0C9BCC 7F09509C E7A6046C */  swc1  $f6, 0x46c($sp)
/* 0C9BD0 7F0950A0 4600A180 */  add.s $f6, $f20, $f0
/* 0C9BD4 7F0950A4 E7A80464 */  swc1  $f8, 0x464($sp)
/* 0C9BD8 7F0950A8 E7AA0470 */  swc1  $f10, 0x470($sp)
/* 0C9BDC 7F0950AC 46008280 */  add.s $f10, $f16, $f0
/* 0C9BE0 7F0950B0 E7A6044C */  swc1  $f6, 0x44c($sp)
/* 0C9BE4 7F0950B4 E7A40474 */  swc1  $f4, 0x474($sp)
/* 0C9BE8 7F0950B8 27A4043C */  addiu $a0, $sp, 0x43c
/* 0C9BEC 7F0950BC E7AA047C */  swc1  $f10, 0x47c($sp)
/* 0C9BF0 7F0950C0 8FA50564 */  lw    $a1, 0x564($sp)
/* 0C9BF4 7F0950C4 E7B20448 */  swc1  $f18, 0x448($sp)
/* 0C9BF8 7F0950C8 E7A20460 */  swc1  $f2, 0x460($sp)
/* 0C9BFC 7F0950CC 0FC24FE9 */  jal   sub_GAME_7F093FA4
/* 0C9C00 7F0950D0 E7AE0478 */   swc1  $f14, 0x478($sp)
/* 0C9C04 7F0950D4 27A40454 */  addiu $a0, $sp, 0x454
/* 0C9C08 7F0950D8 0FC24FE9 */  jal   sub_GAME_7F093FA4
/* 0C9C0C 7F0950DC 8FA50554 */   lw    $a1, 0x554($sp)
/* 0C9C10 7F0950E0 27A4046C */  addiu $a0, $sp, 0x46c
/* 0C9C14 7F0950E4 0FC24FE9 */  jal   sub_GAME_7F093FA4
/* 0C9C18 7F0950E8 8FA50558 */   lw    $a1, 0x558($sp)
/* 0C9C1C 7F0950EC 100001AF */  b     .L7F0957AC
/* 0C9C20 7F0950F0 00000000 */   nop   
.L7F0950F4:
/* 0C9C24 7F0950F4 C7AE05D8 */  lwc1  $f14, 0x5d8($sp)
/* 0C9C28 7F0950F8 C7A605DC */  lwc1  $f6, 0x5dc($sp)
/* 0C9C2C 7F0950FC C7B005E0 */  lwc1  $f16, 0x5e0($sp)
/* 0C9C30 7F095100 46187102 */  mul.s $f4, $f14, $f24
/* 0C9C34 7F095104 C7B20590 */  lwc1  $f18, 0x590($sp)
/* 0C9C38 7F095108 C7B40598 */  lwc1  $f20, 0x598($sp)
/* 0C9C3C 7F09510C 46183202 */  mul.s $f8, $f6, $f24
/* 0C9C40 7F095110 C7A60594 */  lwc1  $f6, 0x594($sp)
/* 0C9C44 7F095114 C7A205B4 */  lwc1  $f2, 0x5b4($sp)
/* 0C9C48 7F095118 46188282 */  mul.s $f10, $f16, $f24
/* 0C9C4C 7F09511C E7A4043C */  swc1  $f4, 0x43c($sp)
/* 0C9C50 7F095120 C7AC05BC */  lwc1  $f12, 0x5bc($sp)
/* 0C9C54 7F095124 46189102 */  mul.s $f4, $f18, $f24
/* 0C9C58 7F095128 E7A80440 */  swc1  $f8, 0x440($sp)
/* 0C9C5C 7F09512C 3C018004 */  lui   $at, %hi(D_8003FD94)
/* 0C9C60 7F095130 46183202 */  mul.s $f8, $f6, $f24
/* 0C9C64 7F095134 E7AA0444 */  swc1  $f10, 0x444($sp)
/* 0C9C68 7F095138 C7A605B8 */  lwc1  $f6, 0x5b8($sp)
/* 0C9C6C 7F09513C 4618A282 */  mul.s $f10, $f20, $f24
/* 0C9C70 7F095140 E7A40454 */  swc1  $f4, 0x454($sp)
/* 0C9C74 7F095144 C420FD94 */  lwc1  $f0, %lo(D_8003FD94)($at)
/* 0C9C78 7F095148 46181102 */  mul.s $f4, $f2, $f24
/* 0C9C7C 7F09514C E7A80458 */  swc1  $f8, 0x458($sp)
/* 0C9C80 7F095150 24110003 */  li    $s1, 3
/* 0C9C84 7F095154 46183202 */  mul.s $f8, $f6, $f24
/* 0C9C88 7F095158 E7AA045C */  swc1  $f10, 0x45c($sp)
/* 0C9C8C 7F09515C 4600A180 */  add.s $f6, $f20, $f0
/* 0C9C90 7F095160 46186282 */  mul.s $f10, $f12, $f24
/* 0C9C94 7F095164 E7A4046C */  swc1  $f4, 0x46c($sp)
/* 0C9C98 7F095168 46008100 */  add.s $f4, $f16, $f0
/* 0C9C9C 7F09516C E7A60464 */  swc1  $f6, 0x464($sp)
/* 0C9CA0 7F095170 E7A80470 */  swc1  $f8, 0x470($sp)
/* 0C9CA4 7F095174 46006200 */  add.s $f8, $f12, $f0
/* 0C9CA8 7F095178 E7A4044C */  swc1  $f4, 0x44c($sp)
/* 0C9CAC 7F09517C E7AA0474 */  swc1  $f10, 0x474($sp)
/* 0C9CB0 7F095180 27A4043C */  addiu $a0, $sp, 0x43c
/* 0C9CB4 7F095184 E7A8047C */  swc1  $f8, 0x47c($sp)
/* 0C9CB8 7F095188 8FA50568 */  lw    $a1, 0x568($sp)
/* 0C9CBC 7F09518C E7AE0448 */  swc1  $f14, 0x448($sp)
/* 0C9CC0 7F095190 E7B20460 */  swc1  $f18, 0x460($sp)
/* 0C9CC4 7F095194 0FC24FE9 */  jal   sub_GAME_7F093FA4
/* 0C9CC8 7F095198 E7A20478 */   swc1  $f2, 0x478($sp)
/* 0C9CCC 7F09519C 27A40454 */  addiu $a0, $sp, 0x454
/* 0C9CD0 7F0951A0 0FC24FE9 */  jal   sub_GAME_7F093FA4
/* 0C9CD4 7F0951A4 8FA50550 */   lw    $a1, 0x550($sp)
/* 0C9CD8 7F0951A8 27A4046C */  addiu $a0, $sp, 0x46c
/* 0C9CDC 7F0951AC 0FC24FE9 */  jal   sub_GAME_7F093FA4
/* 0C9CE0 7F0951B0 8FA5055C */   lw    $a1, 0x55c($sp)
/* 0C9CE4 7F0951B4 1000017D */  b     .L7F0957AC
/* 0C9CE8 7F0951B8 00000000 */   nop   
.L7F0951BC:
/* 0C9CEC 7F0951BC C7A205E4 */  lwc1  $f2, 0x5e4($sp)
/* 0C9CF0 7F0951C0 C7A405E8 */  lwc1  $f4, 0x5e8($sp)
/* 0C9CF4 7F0951C4 C7AC05EC */  lwc1  $f12, 0x5ec($sp)
/* 0C9CF8 7F0951C8 46181282 */  mul.s $f10, $f2, $f24
/* 0C9CFC 7F0951CC C7AE05B4 */  lwc1  $f14, 0x5b4($sp)
/* 0C9D00 7F0951D0 C7B005BC */  lwc1  $f16, 0x5bc($sp)
/* 0C9D04 7F0951D4 46182182 */  mul.s $f6, $f4, $f24
/* 0C9D08 7F0951D8 C7A405B8 */  lwc1  $f4, 0x5b8($sp)
/* 0C9D0C 7F0951DC C7B2059C */  lwc1  $f18, 0x59c($sp)
/* 0C9D10 7F0951E0 46186202 */  mul.s $f8, $f12, $f24
/* 0C9D14 7F0951E4 E7AA043C */  swc1  $f10, 0x43c($sp)
/* 0C9D18 7F0951E8 C7B405A4 */  lwc1  $f20, 0x5a4($sp)
/* 0C9D1C 7F0951EC 46187282 */  mul.s $f10, $f14, $f24
/* 0C9D20 7F0951F0 E7A60440 */  swc1  $f6, 0x440($sp)
/* 0C9D24 7F0951F4 3C018004 */  lui   $at, %hi(D_8003FD94)
/* 0C9D28 7F0951F8 46182182 */  mul.s $f6, $f4, $f24
/* 0C9D2C 7F0951FC E7A80444 */  swc1  $f8, 0x444($sp)
/* 0C9D30 7F095200 C7A405A0 */  lwc1  $f4, 0x5a0($sp)
/* 0C9D34 7F095204 46188202 */  mul.s $f8, $f16, $f24
/* 0C9D38 7F095208 E7AA0454 */  swc1  $f10, 0x454($sp)
/* 0C9D3C 7F09520C C420FD94 */  lwc1  $f0, %lo(D_8003FD94)($at)
/* 0C9D40 7F095210 46189282 */  mul.s $f10, $f18, $f24
/* 0C9D44 7F095214 E7A60458 */  swc1  $f6, 0x458($sp)
/* 0C9D48 7F095218 24110003 */  li    $s1, 3
/* 0C9D4C 7F09521C 46182182 */  mul.s $f6, $f4, $f24
/* 0C9D50 7F095220 E7A8045C */  swc1  $f8, 0x45c($sp)
/* 0C9D54 7F095224 46008100 */  add.s $f4, $f16, $f0
/* 0C9D58 7F095228 4618A202 */  mul.s $f8, $f20, $f24
/* 0C9D5C 7F09522C E7AA046C */  swc1  $f10, 0x46c($sp)
/* 0C9D60 7F095230 46006280 */  add.s $f10, $f12, $f0
/* 0C9D64 7F095234 E7A40464 */  swc1  $f4, 0x464($sp)
/* 0C9D68 7F095238 E7A60470 */  swc1  $f6, 0x470($sp)
/* 0C9D6C 7F09523C 4600A180 */  add.s $f6, $f20, $f0
/* 0C9D70 7F095240 E7AA044C */  swc1  $f10, 0x44c($sp)
/* 0C9D74 7F095244 E7A80474 */  swc1  $f8, 0x474($sp)
/* 0C9D78 7F095248 27A4043C */  addiu $a0, $sp, 0x43c
/* 0C9D7C 7F09524C E7A6047C */  swc1  $f6, 0x47c($sp)
/* 0C9D80 7F095250 8FA5056C */  lw    $a1, 0x56c($sp)
/* 0C9D84 7F095254 E7A20448 */  swc1  $f2, 0x448($sp)
/* 0C9D88 7F095258 E7AE0460 */  swc1  $f14, 0x460($sp)
/* 0C9D8C 7F09525C 0FC24FE9 */  jal   sub_GAME_7F093FA4
/* 0C9D90 7F095260 E7B20478 */   swc1  $f18, 0x478($sp)
/* 0C9D94 7F095264 27A40454 */  addiu $a0, $sp, 0x454
/* 0C9D98 7F095268 0FC24FE9 */  jal   sub_GAME_7F093FA4
/* 0C9D9C 7F09526C 8FA5055C */   lw    $a1, 0x55c($sp)
/* 0C9DA0 7F095270 27A4046C */  addiu $a0, $sp, 0x46c
/* 0C9DA4 7F095274 0FC24FE9 */  jal   sub_GAME_7F093FA4
/* 0C9DA8 7F095278 8FA50554 */   lw    $a1, 0x554($sp)
/* 0C9DAC 7F09527C 1000014B */  b     .L7F0957AC
/* 0C9DB0 7F095280 00000000 */   nop   
.L7F095284:
/* 0C9DB4 7F095284 C7B205CC */  lwc1  $f18, 0x5cc($sp)
/* 0C9DB8 7F095288 C7AA05D0 */  lwc1  $f10, 0x5d0($sp)
/* 0C9DBC 7F09528C C7B405D4 */  lwc1  $f20, 0x5d4($sp)
/* 0C9DC0 7F095290 46189202 */  mul.s $f8, $f18, $f24
/* 0C9DC4 7F095294 C7A205E4 */  lwc1  $f2, 0x5e4($sp)
/* 0C9DC8 7F095298 C7AC05EC */  lwc1  $f12, 0x5ec($sp)
/* 0C9DCC 7F09529C 46185102 */  mul.s $f4, $f10, $f24
/* 0C9DD0 7F0952A0 C7AA05E8 */  lwc1  $f10, 0x5e8($sp)
/* 0C9DD4 7F0952A4 C7AE05D8 */  lwc1  $f14, 0x5d8($sp)
/* 0C9DD8 7F0952A8 4618A182 */  mul.s $f6, $f20, $f24
/* 0C9DDC 7F0952AC E7A8043C */  swc1  $f8, 0x43c($sp)
/* 0C9DE0 7F0952B0 C7B005E0 */  lwc1  $f16, 0x5e0($sp)
/* 0C9DE4 7F0952B4 46181202 */  mul.s $f8, $f2, $f24
/* 0C9DE8 7F0952B8 E7A40440 */  swc1  $f4, 0x440($sp)
/* 0C9DEC 7F0952BC C7B60590 */  lwc1  $f22, 0x590($sp)
/* 0C9DF0 7F0952C0 46185102 */  mul.s $f4, $f10, $f24
/* 0C9DF4 7F0952C4 E7A60444 */  swc1  $f6, 0x444($sp)
/* 0C9DF8 7F0952C8 C7AA05DC */  lwc1  $f10, 0x5dc($sp)
/* 0C9DFC 7F0952CC 46186182 */  mul.s $f6, $f12, $f24
/* 0C9E00 7F0952D0 E7A80454 */  swc1  $f8, 0x454($sp)
/* 0C9E04 7F0952D4 C7BA0598 */  lwc1  $f26, 0x598($sp)
/* 0C9E08 7F0952D8 46187202 */  mul.s $f8, $f14, $f24
/* 0C9E0C 7F0952DC E7A40458 */  swc1  $f4, 0x458($sp)
/* 0C9E10 7F0952E0 3C018004 */  lui   $at, %hi(D_8003FD94)
/* 0C9E14 7F0952E4 46185102 */  mul.s $f4, $f10, $f24
/* 0C9E18 7F0952E8 E7A6045C */  swc1  $f6, 0x45c($sp)
/* 0C9E1C 7F0952EC C7AA0594 */  lwc1  $f10, 0x594($sp)
/* 0C9E20 7F0952F0 46188182 */  mul.s $f6, $f16, $f24
/* 0C9E24 7F0952F4 E7A8046C */  swc1  $f8, 0x46c($sp)
/* 0C9E28 7F0952F8 C420FD94 */  lwc1  $f0, %lo(D_8003FD94)($at)
/* 0C9E2C 7F0952FC 4618B202 */  mul.s $f8, $f22, $f24
/* 0C9E30 7F095300 E7A40470 */  swc1  $f4, 0x470($sp)
/* 0C9E34 7F095304 24110005 */  li    $s1, 5
/* 0C9E38 7F095308 46185102 */  mul.s $f4, $f10, $f24
/* 0C9E3C 7F09530C E7A60474 */  swc1  $f6, 0x474($sp)
/* 0C9E40 7F095310 27A4043C */  addiu $a0, $sp, 0x43c
/* 0C9E44 7F095314 4618D182 */  mul.s $f6, $f26, $f24
/* 0C9E48 7F095318 E7A80484 */  swc1  $f8, 0x484($sp)
/* 0C9E4C 7F09531C C7A805A8 */  lwc1  $f8, 0x5a8($sp)
/* 0C9E50 7F095320 8FA50564 */  lw    $a1, 0x564($sp)
/* 0C9E54 7F095324 E7A40488 */  swc1  $f4, 0x488($sp)
/* 0C9E58 7F095328 46184282 */  mul.s $f10, $f8, $f24
/* 0C9E5C 7F09532C C7A405AC */  lwc1  $f4, 0x5ac($sp)
/* 0C9E60 7F095330 E7A6048C */  swc1  $f6, 0x48c($sp)
/* 0C9E64 7F095334 C7A805B0 */  lwc1  $f8, 0x5b0($sp)
/* 0C9E68 7F095338 46182182 */  mul.s $f6, $f4, $f24
/* 0C9E6C 7F09533C 4600A100 */  add.s $f4, $f20, $f0
/* 0C9E70 7F095340 E7B20448 */  swc1  $f18, 0x448($sp)
/* 0C9E74 7F095344 E7AA049C */  swc1  $f10, 0x49c($sp)
/* 0C9E78 7F095348 46184282 */  mul.s $f10, $f8, $f24
/* 0C9E7C 7F09534C 46008200 */  add.s $f8, $f16, $f0
/* 0C9E80 7F095350 E7A4044C */  swc1  $f4, 0x44c($sp)
/* 0C9E84 7F095354 E7A604A0 */  swc1  $f6, 0x4a0($sp)
/* 0C9E88 7F095358 C7A405A8 */  lwc1  $f4, 0x5a8($sp)
/* 0C9E8C 7F09535C 46006180 */  add.s $f6, $f12, $f0
/* 0C9E90 7F095360 E7A8047C */  swc1  $f8, 0x47c($sp)
/* 0C9E94 7F095364 E7AA04A4 */  swc1  $f10, 0x4a4($sp)
/* 0C9E98 7F095368 4600D280 */  add.s $f10, $f26, $f0
/* 0C9E9C 7F09536C E7A60464 */  swc1  $f6, 0x464($sp)
/* 0C9EA0 7F095370 C7A605B0 */  lwc1  $f6, 0x5b0($sp)
/* 0C9EA4 7F095374 E7A20460 */  swc1  $f2, 0x460($sp)
/* 0C9EA8 7F095378 E7AA0494 */  swc1  $f10, 0x494($sp)
/* 0C9EAC 7F09537C 46003200 */  add.s $f8, $f6, $f0
/* 0C9EB0 7F095380 E7AE0478 */  swc1  $f14, 0x478($sp)
/* 0C9EB4 7F095384 E7B60490 */  swc1  $f22, 0x490($sp)
/* 0C9EB8 7F095388 E7A404A8 */  swc1  $f4, 0x4a8($sp)
/* 0C9EBC 7F09538C 0FC24FE9 */  jal   sub_GAME_7F093FA4
/* 0C9EC0 7F095390 E7A804AC */   swc1  $f8, 0x4ac($sp)
/* 0C9EC4 7F095394 27A40454 */  addiu $a0, $sp, 0x454
/* 0C9EC8 7F095398 0FC24FE9 */  jal   sub_GAME_7F093FA4
/* 0C9ECC 7F09539C 8FA5056C */   lw    $a1, 0x56c($sp)
/* 0C9ED0 7F0953A0 27A4046C */  addiu $a0, $sp, 0x46c
/* 0C9ED4 7F0953A4 0FC24FE9 */  jal   sub_GAME_7F093FA4
/* 0C9ED8 7F0953A8 8FA50568 */   lw    $a1, 0x568($sp)
/* 0C9EDC 7F0953AC 27A40484 */  addiu $a0, $sp, 0x484
/* 0C9EE0 7F0953B0 0FC24FE9 */  jal   sub_GAME_7F093FA4
/* 0C9EE4 7F0953B4 8FA50550 */   lw    $a1, 0x550($sp)
/* 0C9EE8 7F0953B8 27A4049C */  addiu $a0, $sp, 0x49c
/* 0C9EEC 7F0953BC 0FC24FE9 */  jal   sub_GAME_7F093FA4
/* 0C9EF0 7F0953C0 8FA50558 */   lw    $a1, 0x558($sp)
/* 0C9EF4 7F0953C4 100000F9 */  b     .L7F0957AC
/* 0C9EF8 7F0953C8 00000000 */   nop   
.L7F0953CC:
/* 0C9EFC 7F0953CC C7BA05E4 */  lwc1  $f26, 0x5e4($sp)
/* 0C9F00 7F0953D0 C7B605EC */  lwc1  $f22, 0x5ec($sp)
/* 0C9F04 7F0953D4 C7B405D8 */  lwc1  $f20, 0x5d8($sp)
/* 0C9F08 7F0953D8 4618D482 */  mul.s $f18, $f26, $f24
/* 0C9F0C 7F0953DC C7B005E0 */  lwc1  $f16, 0x5e0($sp)
/* 0C9F10 7F0953E0 C7AE05C0 */  lwc1  $f14, 0x5c0($sp)
/* 0C9F14 7F0953E4 4618B302 */  mul.s $f12, $f22, $f24
/* 0C9F18 7F0953E8 C7AA059C */  lwc1  $f10, 0x59c($sp)
/* 0C9F1C 7F0953EC C7A805E8 */  lwc1  $f8, 0x5e8($sp)
/* 0C9F20 7F0953F0 4618A182 */  mul.s $f6, $f20, $f24
/* 0C9F24 7F0953F4 C7A405C8 */  lwc1  $f4, 0x5c8($sp)
/* 0C9F28 7F0953F8 C7A205A4 */  lwc1  $f2, 0x5a4($sp)
/* 0C9F2C 7F0953FC 46184202 */  mul.s $f8, $f8, $f24
/* 0C9F30 7F095400 C7A005DC */  lwc1  $f0, 0x5dc($sp)
/* 0C9F34 7F095404 3C018004 */  lui   $at, %hi(D_8003FD94)
/* 0C9F38 7F095408 E7B2043C */  swc1  $f18, 0x43c($sp)
/* 0C9F3C 7F09540C 46180002 */  mul.s $f0, $f0, $f24
/* 0C9F40 7F095410 C7B205C4 */  lwc1  $f18, 0x5c4($sp)
/* 0C9F44 7F095414 E7AC0444 */  swc1  $f12, 0x444($sp)
/* 0C9F48 7F095418 46188302 */  mul.s $f12, $f16, $f24
/* 0C9F4C 7F09541C E7A80440 */  swc1  $f8, 0x440($sp)
/* 0C9F50 7F095420 C7A805A8 */  lwc1  $f8, 0x5a8($sp)
/* 0C9F54 7F095424 46189482 */  mul.s $f18, $f18, $f24
/* 0C9F58 7F095428 E7A60454 */  swc1  $f6, 0x454($sp)
/* 0C9F5C 7F09542C C7A605AC */  lwc1  $f6, 0x5ac($sp)
/* 0C9F60 7F095430 46184202 */  mul.s $f8, $f8, $f24
/* 0C9F64 7F095434 E7A00458 */  swc1  $f0, 0x458($sp)
/* 0C9F68 7F095438 C7A005B0 */  lwc1  $f0, 0x5b0($sp)
/* 0C9F6C 7F09543C 24110005 */  li    $s1, 5
/* 0C9F70 7F095440 E7AC045C */  swc1  $f12, 0x45c($sp)
/* 0C9F74 7F095444 46187302 */  mul.s $f12, $f14, $f24
/* 0C9F78 7F095448 E7B20470 */  swc1  $f18, 0x470($sp)
/* 0C9F7C 7F09544C C7B205A0 */  lwc1  $f18, 0x5a0($sp)
/* 0C9F80 7F095450 46180002 */  mul.s $f0, $f0, $f24
/* 0C9F84 7F095454 E7A80484 */  swc1  $f8, 0x484($sp)
/* 0C9F88 7F095458 C428FD94 */  lwc1  $f8, %lo(D_8003FD94)($at)
/* 0C9F8C 7F09545C 46189482 */  mul.s $f18, $f18, $f24
/* 0C9F90 7F095460 E7AC046C */  swc1  $f12, 0x46c($sp)
/* 0C9F94 7F095464 46082300 */  add.s $f12, $f4, $f8
/* 0C9F98 7F095468 46182102 */  mul.s $f4, $f4, $f24
/* 0C9F9C 7F09546C E7A0048C */  swc1  $f0, 0x48c($sp)
/* 0C9FA0 7F095470 46081000 */  add.s $f0, $f2, $f8
/* 0C9FA4 7F095474 46183182 */  mul.s $f6, $f6, $f24
/* 0C9FA8 7F095478 E7B204A0 */  swc1  $f18, 0x4a0($sp)
/* 0C9FAC 7F09547C 46088400 */  add.s $f16, $f16, $f8
/* 0C9FB0 7F095480 46181082 */  mul.s $f2, $f2, $f24
/* 0C9FB4 7F095484 C7B205B0 */  lwc1  $f18, 0x5b0($sp)
/* 0C9FB8 7F095488 E7A40474 */  swc1  $f4, 0x474($sp)
/* 0C9FBC 7F09548C 46185102 */  mul.s $f4, $f10, $f24
/* 0C9FC0 7F095490 E7A60488 */  swc1  $f6, 0x488($sp)
/* 0C9FC4 7F095494 4608B580 */  add.s $f22, $f22, $f8
/* 0C9FC8 7F095498 C7A605A8 */  lwc1  $f6, 0x5a8($sp)
/* 0C9FCC 7F09549C E7A204A4 */  swc1  $f2, 0x4a4($sp)
/* 0C9FD0 7F0954A0 46089200 */  add.s $f8, $f18, $f8
/* 0C9FD4 7F0954A4 E7BA0448 */  swc1  $f26, 0x448($sp)
/* 0C9FD8 7F0954A8 E7A4049C */  swc1  $f4, 0x49c($sp)
/* 0C9FDC 7F0954AC E7B6044C */  swc1  $f22, 0x44c($sp)
/* 0C9FE0 7F0954B0 E7B40460 */  swc1  $f20, 0x460($sp)
/* 0C9FE4 7F0954B4 E7B00464 */  swc1  $f16, 0x464($sp)
/* 0C9FE8 7F0954B8 E7AE0478 */  swc1  $f14, 0x478($sp)
/* 0C9FEC 7F0954BC E7AC047C */  swc1  $f12, 0x47c($sp)
/* 0C9FF0 7F0954C0 E7A60490 */  swc1  $f6, 0x490($sp)
/* 0C9FF4 7F0954C4 E7A80494 */  swc1  $f8, 0x494($sp)
/* 0C9FF8 7F0954C8 E7AA04A8 */  swc1  $f10, 0x4a8($sp)
/* 0C9FFC 7F0954CC E7A004AC */  swc1  $f0, 0x4ac($sp)
/* 0CA000 7F0954D0 27A4043C */  addiu $a0, $sp, 0x43c
/* 0CA004 7F0954D4 0FC24FE9 */  jal   sub_GAME_7F093FA4
/* 0CA008 7F0954D8 8FA5056C */   lw    $a1, 0x56c($sp)
/* 0CA00C 7F0954DC 27A40454 */  addiu $a0, $sp, 0x454
/* 0CA010 7F0954E0 0FC24FE9 */  jal   sub_GAME_7F093FA4
/* 0CA014 7F0954E4 8FA50568 */   lw    $a1, 0x568($sp)
/* 0CA018 7F0954E8 27A4046C */  addiu $a0, $sp, 0x46c
/* 0CA01C 7F0954EC 0FC24FE9 */  jal   sub_GAME_7F093FA4
/* 0CA020 7F0954F0 8FA50560 */   lw    $a1, 0x560($sp)
/* 0CA024 7F0954F4 27A40484 */  addiu $a0, $sp, 0x484
/* 0CA028 7F0954F8 0FC24FE9 */  jal   sub_GAME_7F093FA4
/* 0CA02C 7F0954FC 8FA50558 */   lw    $a1, 0x558($sp)
/* 0CA030 7F095500 27A4049C */  addiu $a0, $sp, 0x49c
/* 0CA034 7F095504 0FC24FE9 */  jal   sub_GAME_7F093FA4
/* 0CA038 7F095508 8FA50554 */   lw    $a1, 0x554($sp)
/* 0CA03C 7F09550C 100000A7 */  b     .L7F0957AC
/* 0CA040 7F095510 00000000 */   nop   
.L7F095514:
/* 0CA044 7F095514 C7B605C0 */  lwc1  $f22, 0x5c0($sp)
/* 0CA048 7F095518 C7A605C4 */  lwc1  $f6, 0x5c4($sp)
/* 0CA04C 7F09551C C7BA05C8 */  lwc1  $f26, 0x5c8($sp)
/* 0CA050 7F095520 4618B102 */  mul.s $f4, $f22, $f24
/* 0CA054 7F095524 C7B205CC */  lwc1  $f18, 0x5cc($sp)
/* 0CA058 7F095528 C7B405D4 */  lwc1  $f20, 0x5d4($sp)
/* 0CA05C 7F09552C 46183202 */  mul.s $f8, $f6, $f24
/* 0CA060 7F095530 C7A605D0 */  lwc1  $f6, 0x5d0($sp)
/* 0CA064 7F095534 C7A205E4 */  lwc1  $f2, 0x5e4($sp)
/* 0CA068 7F095538 4618D282 */  mul.s $f10, $f26, $f24
/* 0CA06C 7F09553C E7A4043C */  swc1  $f4, 0x43c($sp)
/* 0CA070 7F095540 C7AC05EC */  lwc1  $f12, 0x5ec($sp)
/* 0CA074 7F095544 46189102 */  mul.s $f4, $f18, $f24
/* 0CA078 7F095548 E7A80440 */  swc1  $f8, 0x440($sp)
/* 0CA07C 7F09554C C7AE05B4 */  lwc1  $f14, 0x5b4($sp)
/* 0CA080 7F095550 46183202 */  mul.s $f8, $f6, $f24
/* 0CA084 7F095554 E7AA0444 */  swc1  $f10, 0x444($sp)
/* 0CA088 7F095558 C7A605E8 */  lwc1  $f6, 0x5e8($sp)
/* 0CA08C 7F09555C 4618A282 */  mul.s $f10, $f20, $f24
/* 0CA090 7F095560 E7A40454 */  swc1  $f4, 0x454($sp)
/* 0CA094 7F095564 C7B005BC */  lwc1  $f16, 0x5bc($sp)
/* 0CA098 7F095568 46181102 */  mul.s $f4, $f2, $f24
/* 0CA09C 7F09556C E7A80458 */  swc1  $f8, 0x458($sp)
/* 0CA0A0 7F095570 3C018004 */  lui   $at, %hi(D_8003FD94)
/* 0CA0A4 7F095574 46183202 */  mul.s $f8, $f6, $f24
/* 0CA0A8 7F095578 E7AA045C */  swc1  $f10, 0x45c($sp)
/* 0CA0AC 7F09557C C7A605B8 */  lwc1  $f6, 0x5b8($sp)
/* 0CA0B0 7F095580 46186282 */  mul.s $f10, $f12, $f24
/* 0CA0B4 7F095584 E7A4046C */  swc1  $f4, 0x46c($sp)
/* 0CA0B8 7F095588 C420FD94 */  lwc1  $f0, %lo(D_8003FD94)($at)
/* 0CA0BC 7F09558C 46187102 */  mul.s $f4, $f14, $f24
/* 0CA0C0 7F095590 E7A80470 */  swc1  $f8, 0x470($sp)
/* 0CA0C4 7F095594 24110005 */  li    $s1, 5
/* 0CA0C8 7F095598 46183202 */  mul.s $f8, $f6, $f24
/* 0CA0CC 7F09559C E7AA0474 */  swc1  $f10, 0x474($sp)
/* 0CA0D0 7F0955A0 27A4043C */  addiu $a0, $sp, 0x43c
/* 0CA0D4 7F0955A4 46188282 */  mul.s $f10, $f16, $f24
/* 0CA0D8 7F0955A8 E7A40484 */  swc1  $f4, 0x484($sp)
/* 0CA0DC 7F0955AC C7A40590 */  lwc1  $f4, 0x590($sp)
/* 0CA0E0 7F0955B0 8FA50560 */  lw    $a1, 0x560($sp)
/* 0CA0E4 7F0955B4 E7A80488 */  swc1  $f8, 0x488($sp)
/* 0CA0E8 7F0955B8 46182182 */  mul.s $f6, $f4, $f24
/* 0CA0EC 7F0955BC C7A80594 */  lwc1  $f8, 0x594($sp)
/* 0CA0F0 7F0955C0 E7AA048C */  swc1  $f10, 0x48c($sp)
/* 0CA0F4 7F0955C4 C7A40598 */  lwc1  $f4, 0x598($sp)
/* 0CA0F8 7F0955C8 46184282 */  mul.s $f10, $f8, $f24
/* 0CA0FC 7F0955CC 4600D200 */  add.s $f8, $f26, $f0
/* 0CA100 7F0955D0 E7B60448 */  swc1  $f22, 0x448($sp)
/* 0CA104 7F0955D4 E7A6049C */  swc1  $f6, 0x49c($sp)
/* 0CA108 7F0955D8 46182182 */  mul.s $f6, $f4, $f24
/* 0CA10C 7F0955DC 46006100 */  add.s $f4, $f12, $f0
/* 0CA110 7F0955E0 E7A8044C */  swc1  $f8, 0x44c($sp)
/* 0CA114 7F0955E4 E7AA04A0 */  swc1  $f10, 0x4a0($sp)
/* 0CA118 7F0955E8 C7A80590 */  lwc1  $f8, 0x590($sp)
/* 0CA11C 7F0955EC 4600A280 */  add.s $f10, $f20, $f0
/* 0CA120 7F0955F0 E7A4047C */  swc1  $f4, 0x47c($sp)
/* 0CA124 7F0955F4 E7A604A4 */  swc1  $f6, 0x4a4($sp)
/* 0CA128 7F0955F8 46008180 */  add.s $f6, $f16, $f0
/* 0CA12C 7F0955FC E7AA0464 */  swc1  $f10, 0x464($sp)
/* 0CA130 7F095600 C7AA0598 */  lwc1  $f10, 0x598($sp)
/* 0CA134 7F095604 E7B20460 */  swc1  $f18, 0x460($sp)
/* 0CA138 7F095608 E7A60494 */  swc1  $f6, 0x494($sp)
/* 0CA13C 7F09560C 46005100 */  add.s $f4, $f10, $f0
/* 0CA140 7F095610 E7A20478 */  swc1  $f2, 0x478($sp)
/* 0CA144 7F095614 E7AE0490 */  swc1  $f14, 0x490($sp)
/* 0CA148 7F095618 E7A804A8 */  swc1  $f8, 0x4a8($sp)
/* 0CA14C 7F09561C 0FC24FE9 */  jal   sub_GAME_7F093FA4
/* 0CA150 7F095620 E7A404AC */   swc1  $f4, 0x4ac($sp)
/* 0CA154 7F095624 27A40454 */  addiu $a0, $sp, 0x454
/* 0CA158 7F095628 0FC24FE9 */  jal   sub_GAME_7F093FA4
/* 0CA15C 7F09562C 8FA50564 */   lw    $a1, 0x564($sp)
/* 0CA160 7F095630 27A4046C */  addiu $a0, $sp, 0x46c
/* 0CA164 7F095634 0FC24FE9 */  jal   sub_GAME_7F093FA4
/* 0CA168 7F095638 8FA5056C */   lw    $a1, 0x56c($sp)
/* 0CA16C 7F09563C 27A40484 */  addiu $a0, $sp, 0x484
/* 0CA170 7F095640 0FC24FE9 */  jal   sub_GAME_7F093FA4
/* 0CA174 7F095644 8FA5055C */   lw    $a1, 0x55c($sp)
/* 0CA178 7F095648 27A4049C */  addiu $a0, $sp, 0x49c
/* 0CA17C 7F09564C 0FC24FE9 */  jal   sub_GAME_7F093FA4
/* 0CA180 7F095650 8FA50550 */   lw    $a1, 0x550($sp)
/* 0CA184 7F095654 10000055 */  b     .L7F0957AC
/* 0CA188 7F095658 00000000 */   nop   
.L7F09565C:
/* 0CA18C 7F09565C C7AE05D8 */  lwc1  $f14, 0x5d8($sp)
/* 0CA190 7F095660 C7A805DC */  lwc1  $f8, 0x5dc($sp)
/* 0CA194 7F095664 C7B005E0 */  lwc1  $f16, 0x5e0($sp)
/* 0CA198 7F095668 46187182 */  mul.s $f6, $f14, $f24
/* 0CA19C 7F09566C C7B605C0 */  lwc1  $f22, 0x5c0($sp)
/* 0CA1A0 7F095670 C7BA05C8 */  lwc1  $f26, 0x5c8($sp)
/* 0CA1A4 7F095674 46184282 */  mul.s $f10, $f8, $f24
/* 0CA1A8 7F095678 C7A805C4 */  lwc1  $f8, 0x5c4($sp)
/* 0CA1AC 7F09567C C7B205CC */  lwc1  $f18, 0x5cc($sp)
/* 0CA1B0 7F095680 46188102 */  mul.s $f4, $f16, $f24
/* 0CA1B4 7F095684 E7A6043C */  swc1  $f6, 0x43c($sp)
/* 0CA1B8 7F095688 C7B405D4 */  lwc1  $f20, 0x5d4($sp)
/* 0CA1BC 7F09568C 4618B182 */  mul.s $f6, $f22, $f24
/* 0CA1C0 7F095690 E7AA0440 */  swc1  $f10, 0x440($sp)
/* 0CA1C4 7F095694 C7A2059C */  lwc1  $f2, 0x59c($sp)
/* 0CA1C8 7F095698 46184282 */  mul.s $f10, $f8, $f24
/* 0CA1CC 7F09569C E7A40444 */  swc1  $f4, 0x444($sp)
/* 0CA1D0 7F0956A0 C7A805D0 */  lwc1  $f8, 0x5d0($sp)
/* 0CA1D4 7F0956A4 4618D102 */  mul.s $f4, $f26, $f24
/* 0CA1D8 7F0956A8 E7A60454 */  swc1  $f6, 0x454($sp)
/* 0CA1DC 7F0956AC C7AC05A4 */  lwc1  $f12, 0x5a4($sp)
/* 0CA1E0 7F0956B0 46189182 */  mul.s $f6, $f18, $f24
/* 0CA1E4 7F0956B4 E7AA0458 */  swc1  $f10, 0x458($sp)
/* 0CA1E8 7F0956B8 3C018004 */  lui   $at, %hi(D_8003FD94)
/* 0CA1EC 7F0956BC 46184282 */  mul.s $f10, $f8, $f24
/* 0CA1F0 7F0956C0 E7A4045C */  swc1  $f4, 0x45c($sp)
/* 0CA1F4 7F0956C4 C7A805A0 */  lwc1  $f8, 0x5a0($sp)
/* 0CA1F8 7F0956C8 4618A102 */  mul.s $f4, $f20, $f24
/* 0CA1FC 7F0956CC E7A6046C */  swc1  $f6, 0x46c($sp)
/* 0CA200 7F0956D0 C420FD94 */  lwc1  $f0, %lo(D_8003FD94)($at)
/* 0CA204 7F0956D4 46181182 */  mul.s $f6, $f2, $f24
/* 0CA208 7F0956D8 E7AA0470 */  swc1  $f10, 0x470($sp)
/* 0CA20C 7F0956DC 24110005 */  li    $s1, 5
/* 0CA210 7F0956E0 46184282 */  mul.s $f10, $f8, $f24
/* 0CA214 7F0956E4 E7A40474 */  swc1  $f4, 0x474($sp)
/* 0CA218 7F0956E8 27A4043C */  addiu $a0, $sp, 0x43c
/* 0CA21C 7F0956EC 46186102 */  mul.s $f4, $f12, $f24
/* 0CA220 7F0956F0 E7A60484 */  swc1  $f6, 0x484($sp)
/* 0CA224 7F0956F4 C7A605B4 */  lwc1  $f6, 0x5b4($sp)
/* 0CA228 7F0956F8 8FA50568 */  lw    $a1, 0x568($sp)
/* 0CA22C 7F0956FC E7AA0488 */  swc1  $f10, 0x488($sp)
/* 0CA230 7F095700 46183202 */  mul.s $f8, $f6, $f24
/* 0CA234 7F095704 C7AA05B8 */  lwc1  $f10, 0x5b8($sp)
/* 0CA238 7F095708 E7A4048C */  swc1  $f4, 0x48c($sp)
/* 0CA23C 7F09570C C7A605BC */  lwc1  $f6, 0x5bc($sp)
/* 0CA240 7F095710 46185102 */  mul.s $f4, $f10, $f24
/* 0CA244 7F095714 46008280 */  add.s $f10, $f16, $f0
/* 0CA248 7F095718 E7AE0448 */  swc1  $f14, 0x448($sp)
/* 0CA24C 7F09571C E7A8049C */  swc1  $f8, 0x49c($sp)
/* 0CA250 7F095720 46183202 */  mul.s $f8, $f6, $f24
/* 0CA254 7F095724 4600A180 */  add.s $f6, $f20, $f0
/* 0CA258 7F095728 E7AA044C */  swc1  $f10, 0x44c($sp)
/* 0CA25C 7F09572C E7A404A0 */  swc1  $f4, 0x4a0($sp)
/* 0CA260 7F095730 C7AA05B4 */  lwc1  $f10, 0x5b4($sp)
/* 0CA264 7F095734 4600D100 */  add.s $f4, $f26, $f0
/* 0CA268 7F095738 E7A6047C */  swc1  $f6, 0x47c($sp)
/* 0CA26C 7F09573C E7A804A4 */  swc1  $f8, 0x4a4($sp)
/* 0CA270 7F095740 46006200 */  add.s $f8, $f12, $f0
/* 0CA274 7F095744 E7A40464 */  swc1  $f4, 0x464($sp)
/* 0CA278 7F095748 C7A405BC */  lwc1  $f4, 0x5bc($sp)
/* 0CA27C 7F09574C E7B60460 */  swc1  $f22, 0x460($sp)
/* 0CA280 7F095750 E7A80494 */  swc1  $f8, 0x494($sp)
/* 0CA284 7F095754 46002180 */  add.s $f6, $f4, $f0
/* 0CA288 7F095758 E7B20478 */  swc1  $f18, 0x478($sp)
/* 0CA28C 7F09575C E7A20490 */  swc1  $f2, 0x490($sp)
/* 0CA290 7F095760 E7AA04A8 */  swc1  $f10, 0x4a8($sp)
/* 0CA294 7F095764 0FC24FE9 */  jal   sub_GAME_7F093FA4
/* 0CA298 7F095768 E7A604AC */   swc1  $f6, 0x4ac($sp)
/* 0CA29C 7F09576C 27A40454 */  addiu $a0, $sp, 0x454
/* 0CA2A0 7F095770 0FC24FE9 */  jal   sub_GAME_7F093FA4
/* 0CA2A4 7F095774 8FA50560 */   lw    $a1, 0x560($sp)
/* 0CA2A8 7F095778 27A4046C */  addiu $a0, $sp, 0x46c
/* 0CA2AC 7F09577C 0FC24FE9 */  jal   sub_GAME_7F093FA4
/* 0CA2B0 7F095780 8FA50564 */   lw    $a1, 0x564($sp)
/* 0CA2B4 7F095784 27A40484 */  addiu $a0, $sp, 0x484
/* 0CA2B8 7F095788 0FC24FE9 */  jal   sub_GAME_7F093FA4
/* 0CA2BC 7F09578C 8FA50554 */   lw    $a1, 0x554($sp)
/* 0CA2C0 7F095790 27A4049C */  addiu $a0, $sp, 0x49c
/* 0CA2C4 7F095794 0FC24FE9 */  jal   sub_GAME_7F093FA4
/* 0CA2C8 7F095798 8FA5055C */   lw    $a1, 0x55c($sp)
/* 0CA2CC 7F09579C 10000003 */  b     .L7F0957AC
/* 0CA2D0 7F0957A0 00000000 */   nop   
def_7F094A38:
.L7F0957A4:
/* 0CA2D4 7F0957A4 100006EE */  b     .L7F097360
/* 0CA2D8 7F0957A8 8FA206B0 */   lw    $v0, 0x6b0($sp)
.L7F0957AC:
/* 0CA2DC 7F0957AC 5A20018E */  blezl $s1, .L7F095DE8
/* 0CA2E0 7F0957B0 8FAA005C */   lw    $t2, 0x5c($sp)
/* 0CA2E4 7F0957B4 0FC1E0F9 */  jal   currentPlayerGetProjectionMatrixF
/* 0CA2E8 7F0957B8 00000000 */   nop   
/* 0CA2EC 7F0957BC 0FC1E0F1 */  jal   currentPlayerGetMatrix10CC
/* 0CA2F0 7F0957C0 00408025 */   move  $s0, $v0
/* 0CA2F4 7F0957C4 02002025 */  move  $a0, $s0
/* 0CA2F8 7F0957C8 00402825 */  move  $a1, $v0
/* 0CA2FC 7F0957CC 0FC16032 */  jal   matrix_4x4_multiply
/* 0CA300 7F0957D0 27A603CC */   addiu $a2, $sp, 0x3cc
/* 0CA304 7F0957D4 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0CA308 7F0957D8 44814000 */  mtc1  $at, $f8
/* 0CA30C 7F0957DC 3C048008 */  lui   $a0, %hi(dword_CODE_bss_80079E98)
/* 0CA310 7F0957E0 24849E98 */  addiu $a0, %lo(dword_CODE_bss_80079E98) # addiu $a0, $a0, -0x6168
/* 0CA314 7F0957E4 46184003 */  div.s $f0, $f8, $f24
/* 0CA318 7F0957E8 44050000 */  mfc1  $a1, $f0
/* 0CA31C 7F0957EC 44060000 */  mfc1  $a2, $f0
/* 0CA320 7F0957F0 44070000 */  mfc1  $a3, $f0
/* 0CA324 7F0957F4 0C005BA4 */  jal   guScaleF
/* 0CA328 7F0957F8 00000000 */   nop   
/* 0CA32C 7F0957FC 3C058008 */  lui   $a1, %hi(dword_CODE_bss_80079E98)
/* 0CA330 7F095800 24A59E98 */  addiu $a1, %lo(dword_CODE_bss_80079E98) # addiu $a1, $a1, -0x6168
/* 0CA334 7F095804 27A403CC */  addiu $a0, $sp, 0x3cc
/* 0CA338 7F095808 0FC16032 */  jal   matrix_4x4_multiply
/* 0CA33C 7F09580C 27A6038C */   addiu $a2, $sp, 0x38c
/* 0CA340 7F095810 1A20004E */  blez  $s1, .L7F09594C
/* 0CA344 7F095814 AFA00270 */   sw    $zero, 0x270($sp)
/* 0CA348 7F095818 3C014080 */  li    $at, 0x40800000 # 4.000000
/* 0CA34C 7F09581C 27A4043C */  addiu $a0, $sp, 0x43c
/* 0CA350 7F095820 4481D000 */  mtc1  $at, $f26
/* 0CA354 7F095824 AFA40058 */  sw    $a0, 0x58($sp)
/* 0CA358 7F095828 27B00274 */  addiu $s0, $sp, 0x274
.L7F09582C:
/* 0CA35C 7F09582C 3C018005 */  lui   $at, %hi(D_80057584)
/* 0CA360 7F095830 C4207584 */  lwc1  $f0, %lo(D_80057584)($at)
/* 0CA364 7F095834 8FA40058 */  lw    $a0, 0x58($sp)
/* 0CA368 7F095838 27A5038C */  addiu $a1, $sp, 0x38c
/* 0CA36C 7F09583C 44070000 */  mfc1  $a3, $f0
/* 0CA370 7F095840 24060082 */  li    $a2, 130
/* 0CA374 7F095844 AFB00014 */  sw    $s0, 0x14($sp)
/* 0CA378 7F095848 0FC25CE2 */  jal   sub_GAME_7F097388
/* 0CA37C 7F09584C E7A00010 */   swc1  $f0, 0x10($sp)
/* 0CA380 7F095850 0FC1E131 */  jal   getPlayer_c_screenleft
/* 0CA384 7F095854 00000000 */   nop   
/* 0CA388 7F095858 0FC1E131 */  jal   getPlayer_c_screenleft
/* 0CA38C 7F09585C 46000506 */   mov.s $f20, $f0
/* 0CA390 7F095860 0FC1E129 */  jal   getPlayer_c_screenwidth
/* 0CA394 7F095864 46000586 */   mov.s $f22, $f0
/* 0CA398 7F095868 46160280 */  add.s $f10, $f0, $f22
/* 0CA39C 7F09586C 461AA382 */  mul.s $f14, $f20, $f26
/* 0CA3A0 7F095870 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0CA3A4 7F095874 44813000 */  mtc1  $at, $f6
/* 0CA3A8 7F095878 461A5102 */  mul.s $f4, $f10, $f26
/* 0CA3AC 7F09587C C60C0028 */  lwc1  $f12, 0x28($s0)
/* 0CA3B0 7F095880 46062201 */  sub.s $f8, $f4, $f6
/* 0CA3B4 7F095884 44064000 */  mfc1  $a2, $f8
/* 0CA3B8 7F095888 0FC24F12 */  jal   sub_GAME_7F093C48
/* 0CA3BC 7F09588C 00000000 */   nop   
/* 0CA3C0 7F095890 0FC1E135 */  jal   getPlayer_c_screentop
/* 0CA3C4 7F095894 E6000028 */   swc1  $f0, 0x28($s0)
/* 0CA3C8 7F095898 0FC1E135 */  jal   getPlayer_c_screentop
/* 0CA3CC 7F09589C 46000506 */   mov.s $f20, $f0
/* 0CA3D0 7F0958A0 0FC1E12D */  jal   getPlayer_c_screenheight
/* 0CA3D4 7F0958A4 46000586 */   mov.s $f22, $f0
/* 0CA3D8 7F0958A8 46160280 */  add.s $f10, $f0, $f22
/* 0CA3DC 7F0958AC 461AA382 */  mul.s $f14, $f20, $f26
/* 0CA3E0 7F0958B0 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0CA3E4 7F0958B4 44813000 */  mtc1  $at, $f6
/* 0CA3E8 7F0958B8 461A5102 */  mul.s $f4, $f10, $f26
/* 0CA3EC 7F0958BC C60C002C */  lwc1  $f12, 0x2c($s0)
/* 0CA3F0 7F0958C0 46062201 */  sub.s $f8, $f4, $f6
/* 0CA3F4 7F0958C4 44064000 */  mfc1  $a2, $f8
/* 0CA3F8 7F0958C8 0FC24F12 */  jal   sub_GAME_7F093C48
/* 0CA3FC 7F0958CC 00000000 */   nop   
/* 0CA400 7F0958D0 0FC1E135 */  jal   getPlayer_c_screentop
/* 0CA404 7F0958D4 E600002C */   swc1  $f0, 0x2c($s0)
/* 0CA408 7F0958D8 461A0282 */  mul.s $f10, $f0, $f26
/* 0CA40C 7F0958DC C606002C */  lwc1  $f6, 0x2c($s0)
/* 0CA410 7F0958E0 461A5100 */  add.s $f4, $f10, $f26
/* 0CA414 7F0958E4 4606203C */  c.lt.s $f4, $f6
/* 0CA418 7F0958E8 00000000 */  nop   
/* 0CA41C 7F0958EC 45020010 */  bc1fl .L7F095930
/* 0CA420 7F0958F0 8FB90058 */   lw    $t9, 0x58($sp)
/* 0CA424 7F0958F4 0FC1E135 */  jal   getPlayer_c_screentop
/* 0CA428 7F0958F8 00000000 */   nop   
/* 0CA42C 7F0958FC 0FC1E12D */  jal   getPlayer_c_screenheight
/* 0CA430 7F095900 46000506 */   mov.s $f20, $f0
/* 0CA434 7F095904 46140200 */  add.s $f8, $f0, $f20
/* 0CA438 7F095908 C602002C */  lwc1  $f2, 0x2c($s0)
/* 0CA43C 7F09590C 461A4282 */  mul.s $f10, $f8, $f26
/* 0CA440 7F095910 461A5101 */  sub.s $f4, $f10, $f26
/* 0CA444 7F095914 4604103C */  c.lt.s $f2, $f4
/* 0CA448 7F095918 00000000 */  nop   
/* 0CA44C 7F09591C 45020004 */  bc1fl .L7F095930
/* 0CA450 7F095920 8FB90058 */   lw    $t9, 0x58($sp)
/* 0CA454 7F095924 461A1181 */  sub.s $f6, $f2, $f26
/* 0CA458 7F095928 E606002C */  swc1  $f6, 0x2c($s0)
/* 0CA45C 7F09592C 8FB90058 */  lw    $t9, 0x58($sp)
.L7F095930:
/* 0CA460 7F095930 8FA20270 */  lw    $v0, 0x270($sp)
/* 0CA464 7F095934 26100038 */  addiu $s0, $s0, 0x38
/* 0CA468 7F095938 272D0018 */  addiu $t5, $t9, 0x18
/* 0CA46C 7F09593C 24420001 */  addiu $v0, $v0, 1
/* 0CA470 7F095940 AFA20270 */  sw    $v0, 0x270($sp)
/* 0CA474 7F095944 1451FFB9 */  bne   $v0, $s1, .L7F09582C
/* 0CA478 7F095948 AFAD0058 */   sw    $t5, 0x58($sp)
.L7F09594C:
/* 0CA47C 7F09594C 0FC2E9CB */  jal   get_ptr_currentdata
/* 0CA480 7F095950 00000000 */   nop   
/* 0CA484 7F095954 904B0020 */  lbu   $t3, 0x20($v0)
/* 0CA488 7F095958 8FAE06B0 */  lw    $t6, 0x6b0($sp)
/* 0CA48C 7F09595C 3C0FE700 */  lui   $t7, 0xe700
/* 0CA490 7F095960 156000A6 */  bnez  $t3, .L7F095BFC
/* 0CA494 7F095964 25CA0008 */   addiu $t2, $t6, 8
/* 0CA498 7F095968 3C018005 */  lui   $at, %hi(D_80057588)
/* 0CA49C 7F09596C C4327588 */  lwc1  $f18, %lo(D_80057588)($at)
/* 0CA4A0 7F095970 3C018005 */  lui   $at, %hi(D_8005758C)
/* 0CA4A4 7F095974 C434758C */  lwc1  $f20, %lo(D_8005758C)($at)
/* 0CA4A8 7F095978 44808000 */  mtc1  $zero, $f16
/* 0CA4AC 7F09597C 00001825 */  move  $v1, $zero
/* 0CA4B0 7F095980 46009086 */  mov.s $f2, $f18
/* 0CA4B4 7F095984 4600A386 */  mov.s $f14, $f20
/* 0CA4B8 7F095988 1A200054 */  blez  $s1, .L7F095ADC
/* 0CA4BC 7F09598C 46008306 */   mov.s $f12, $f16
/* 0CA4C0 7F095990 32220001 */  andi  $v0, $s1, 1
/* 0CA4C4 7F095994 10400019 */  beqz  $v0, .L7F0959FC
/* 0CA4C8 7F095998 C7A0029C */   lwc1  $f0, 0x29c($sp)
/* 0CA4CC 7F09599C 4612003C */  c.lt.s $f0, $f18
/* 0CA4D0 7F0959A0 44804000 */  mtc1  $zero, $f8
/* 0CA4D4 7F0959A4 44805000 */  mtc1  $zero, $f10
/* 0CA4D8 7F0959A8 24030001 */  li    $v1, 1
/* 0CA4DC 7F0959AC 45020003 */  bc1fl .L7F0959BC
/* 0CA4E0 7F0959B0 4600403C */   c.lt.s $f8, $f0
/* 0CA4E4 7F0959B4 46000086 */  mov.s $f2, $f0
/* 0CA4E8 7F0959B8 4600403C */  c.lt.s $f8, $f0
.L7F0959BC:
/* 0CA4EC 7F0959BC 00000000 */  nop   
/* 0CA4F0 7F0959C0 45020003 */  bc1fl .L7F0959D0
/* 0CA4F4 7F0959C4 C7A002A0 */   lwc1  $f0, 0x2a0($sp)
/* 0CA4F8 7F0959C8 46000306 */  mov.s $f12, $f0
/* 0CA4FC 7F0959CC C7A002A0 */  lwc1  $f0, 0x2a0($sp)
.L7F0959D0:
/* 0CA500 7F0959D0 4614003C */  c.lt.s $f0, $f20
/* 0CA504 7F0959D4 00000000 */  nop   
/* 0CA508 7F0959D8 45020003 */  bc1fl .L7F0959E8
/* 0CA50C 7F0959DC 4600503C */   c.lt.s $f10, $f0
/* 0CA510 7F0959E0 46000386 */  mov.s $f14, $f0
/* 0CA514 7F0959E4 4600503C */  c.lt.s $f10, $f0
.L7F0959E8:
/* 0CA518 7F0959E8 00000000 */  nop   
/* 0CA51C 7F0959EC 45000002 */  bc1f  .L7F0959F8
/* 0CA520 7F0959F0 00000000 */   nop   
/* 0CA524 7F0959F4 46000406 */  mov.s $f16, $f0
.L7F0959F8:
/* 0CA528 7F0959F8 10710038 */  beq   $v1, $s1, .L7F095ADC
.L7F0959FC:
/* 0CA52C 7F0959FC 000360C0 */   sll   $t4, $v1, 3
/* 0CA530 7F095A00 0011C0C0 */  sll   $t8, $s1, 3
/* 0CA534 7F095A04 0311C023 */  subu  $t8, $t8, $s1
/* 0CA538 7F095A08 01836023 */  subu  $t4, $t4, $v1
/* 0CA53C 7F095A0C 27AE0274 */  addiu $t6, $sp, 0x274
/* 0CA540 7F095A10 000C60C0 */  sll   $t4, $t4, 3
/* 0CA544 7F095A14 0018C0C0 */  sll   $t8, $t8, 3
/* 0CA548 7F095A18 030E2021 */  addu  $a0, $t8, $t6
/* 0CA54C 7F095A1C 018E1021 */  addu  $v0, $t4, $t6
/* 0CA550 7F095A20 C4400028 */  lwc1  $f0, 0x28($v0)
.L7F095A24:
/* 0CA554 7F095A24 4602003C */  c.lt.s $f0, $f2
/* 0CA558 7F095A28 00000000 */  nop   
/* 0CA55C 7F095A2C 45020003 */  bc1fl .L7F095A3C
/* 0CA560 7F095A30 4600603C */   c.lt.s $f12, $f0
/* 0CA564 7F095A34 46000086 */  mov.s $f2, $f0
/* 0CA568 7F095A38 4600603C */  c.lt.s $f12, $f0
.L7F095A3C:
/* 0CA56C 7F095A3C 00000000 */  nop   
/* 0CA570 7F095A40 45020003 */  bc1fl .L7F095A50
/* 0CA574 7F095A44 C440002C */   lwc1  $f0, 0x2c($v0)
/* 0CA578 7F095A48 46000306 */  mov.s $f12, $f0
/* 0CA57C 7F095A4C C440002C */  lwc1  $f0, 0x2c($v0)
.L7F095A50:
/* 0CA580 7F095A50 460E003C */  c.lt.s $f0, $f14
/* 0CA584 7F095A54 00000000 */  nop   
/* 0CA588 7F095A58 45020003 */  bc1fl .L7F095A68
/* 0CA58C 7F095A5C 4600803C */   c.lt.s $f16, $f0
/* 0CA590 7F095A60 46000386 */  mov.s $f14, $f0
/* 0CA594 7F095A64 4600803C */  c.lt.s $f16, $f0
.L7F095A68:
/* 0CA598 7F095A68 00000000 */  nop   
/* 0CA59C 7F095A6C 45020003 */  bc1fl .L7F095A7C
/* 0CA5A0 7F095A70 C4400060 */   lwc1  $f0, 0x60($v0)
/* 0CA5A4 7F095A74 46000406 */  mov.s $f16, $f0
/* 0CA5A8 7F095A78 C4400060 */  lwc1  $f0, 0x60($v0)
.L7F095A7C:
/* 0CA5AC 7F095A7C 4602003C */  c.lt.s $f0, $f2
/* 0CA5B0 7F095A80 00000000 */  nop   
/* 0CA5B4 7F095A84 45020003 */  bc1fl .L7F095A94
/* 0CA5B8 7F095A88 4600603C */   c.lt.s $f12, $f0
/* 0CA5BC 7F095A8C 46000086 */  mov.s $f2, $f0
/* 0CA5C0 7F095A90 4600603C */  c.lt.s $f12, $f0
.L7F095A94:
/* 0CA5C4 7F095A94 00000000 */  nop   
/* 0CA5C8 7F095A98 45020003 */  bc1fl .L7F095AA8
/* 0CA5CC 7F095A9C C4400064 */   lwc1  $f0, 0x64($v0)
/* 0CA5D0 7F095AA0 46000306 */  mov.s $f12, $f0
/* 0CA5D4 7F095AA4 C4400064 */  lwc1  $f0, 0x64($v0)
.L7F095AA8:
/* 0CA5D8 7F095AA8 24420070 */  addiu $v0, $v0, 0x70
/* 0CA5DC 7F095AAC 460E003C */  c.lt.s $f0, $f14
/* 0CA5E0 7F095AB0 00000000 */  nop   
/* 0CA5E4 7F095AB4 45020003 */  bc1fl .L7F095AC4
/* 0CA5E8 7F095AB8 4600803C */   c.lt.s $f16, $f0
/* 0CA5EC 7F095ABC 46000386 */  mov.s $f14, $f0
/* 0CA5F0 7F095AC0 4600803C */  c.lt.s $f16, $f0
.L7F095AC4:
/* 0CA5F4 7F095AC4 00000000 */  nop   
/* 0CA5F8 7F095AC8 45000002 */  bc1f  .L7F095AD4
/* 0CA5FC 7F095ACC 00000000 */   nop   
/* 0CA600 7F095AD0 46000406 */  mov.s $f16, $f0
.L7F095AD4:
/* 0CA604 7F095AD4 5444FFD3 */  bnel  $v0, $a0, .L7F095A24
/* 0CA608 7F095AD8 C4400028 */   lwc1  $f0, 0x28($v0)
.L7F095ADC:
/* 0CA60C 7F095ADC 8FAA06B0 */  lw    $t2, 0x6b0($sp)
/* 0CA610 7F095AE0 3C19E700 */  lui   $t9, 0xe700
/* 0CA614 7F095AE4 3C013E80 */  li    $at, 0x3E800000 # 0.250000
/* 0CA618 7F095AE8 254F0008 */  addiu $t7, $t2, 8
/* 0CA61C 7F095AEC AFAF06B0 */  sw    $t7, 0x6b0($sp)
/* 0CA620 7F095AF0 AD400004 */  sw    $zero, 4($t2)
/* 0CA624 7F095AF4 AD590000 */  sw    $t9, ($t2)
/* 0CA628 7F095AF8 8FAD06B0 */  lw    $t5, 0x6b0($sp)
/* 0CA62C 7F095AFC 44810000 */  mtc1  $at, $f0
/* 0CA630 7F095B00 3C0CBA00 */  lui   $t4, (0xBA001402 >> 16) # lui $t4, 0xba00
/* 0CA634 7F095B04 25AB0008 */  addiu $t3, $t5, 8
/* 0CA638 7F095B08 AFAB06B0 */  sw    $t3, 0x6b0($sp)
/* 0CA63C 7F095B0C 358C1402 */  ori   $t4, (0xBA001402 & 0xFFFF) # ori $t4, $t4, 0x1402
/* 0CA640 7F095B10 3C180030 */  lui   $t8, 0x30
/* 0CA644 7F095B14 46006102 */  mul.s $f4, $f12, $f0
/* 0CA648 7F095B18 ADB80004 */  sw    $t8, 4($t5)
/* 0CA64C 7F095B1C ADAC0000 */  sw    $t4, ($t5)
/* 0CA650 7F095B20 8FAE06B0 */  lw    $t6, 0x6b0($sp)
/* 0CA654 7F095B24 46008202 */  mul.s $f8, $f16, $f0
/* 0CA658 7F095B28 3C0FB900 */  lui   $t7, (0xB900031D >> 16) # lui $t7, 0xb900
/* 0CA65C 7F095B2C 25CA0008 */  addiu $t2, $t6, 8
/* 0CA660 7F095B30 AFAA06B0 */  sw    $t2, 0x6b0($sp)
/* 0CA664 7F095B34 35EF031D */  ori   $t7, (0xB900031D & 0xFFFF) # ori $t7, $t7, 0x31d
/* 0CA668 7F095B38 ADCF0000 */  sw    $t7, ($t6)
/* 0CA66C 7F095B3C ADC00004 */  sw    $zero, 4($t6)
/* 0CA670 7F095B40 4600218D */  trunc.w.s $f6, $f4
/* 0CA674 7F095B44 8FB906B0 */  lw    $t9, 0x6b0($sp)
/* 0CA678 7F095B48 46001102 */  mul.s $f4, $f2, $f0
/* 0CA67C 7F095B4C 4600428D */  trunc.w.s $f10, $f8
/* 0CA680 7F095B50 272D0008 */  addiu $t5, $t9, 8
/* 0CA684 7F095B54 46007202 */  mul.s $f8, $f14, $f0
/* 0CA688 7F095B58 3C07BA00 */  lui   $a3, (0xBA001301 >> 16) # lui $a3, 0xba00
/* 0CA68C 7F095B5C AFAD06B0 */  sw    $t5, 0x6b0($sp)
/* 0CA690 7F095B60 34E71301 */  ori   $a3, (0xBA001301 & 0xFFFF) # ori $a3, $a3, 0x1301
/* 0CA694 7F095B64 AF270000 */  sw    $a3, ($t9)
/* 0CA698 7F095B68 AF200004 */  sw    $zero, 4($t9)
/* 0CA69C 7F095B6C 8FA606B0 */  lw    $a2, 0x6b0($sp)
/* 0CA6A0 7F095B70 440E3000 */  mfc1  $t6, $f6
/* 0CA6A4 7F095B74 440B5000 */  mfc1  $t3, $f10
/* 0CA6A8 7F095B78 24CC0008 */  addiu $t4, $a2, 8
/* 0CA6AC 7F095B7C 31CA03FF */  andi  $t2, $t6, 0x3ff
/* 0CA6B0 7F095B80 4600428D */  trunc.w.s $f10, $f8
/* 0CA6B4 7F095B84 000A7B80 */  sll   $t7, $t2, 0xe
/* 0CA6B8 7F095B88 AFAC06B0 */  sw    $t4, 0x6b0($sp)
/* 0CA6BC 7F095B8C 4600218D */  trunc.w.s $f6, $f4
/* 0CA6C0 7F095B90 3C01F600 */  lui   $at, 0xf600
/* 0CA6C4 7F095B94 01E1C825 */  or    $t9, $t7, $at
/* 0CA6C8 7F095B98 316C03FF */  andi  $t4, $t3, 0x3ff
/* 0CA6CC 7F095B9C 000CC080 */  sll   $t8, $t4, 2
/* 0CA6D0 7F095BA0 03387025 */  or    $t6, $t9, $t8
/* 0CA6D4 7F095BA4 44195000 */  mfc1  $t9, $f10
/* 0CA6D8 7F095BA8 440F3000 */  mfc1  $t7, $f6
/* 0CA6DC 7F095BAC ACCE0000 */  sw    $t6, ($a2)
/* 0CA6E0 7F095BB0 333803FF */  andi  $t8, $t9, 0x3ff
/* 0CA6E4 7F095BB4 31ED03FF */  andi  $t5, $t7, 0x3ff
/* 0CA6E8 7F095BB8 000D5B80 */  sll   $t3, $t5, 0xe
/* 0CA6EC 7F095BBC 00187080 */  sll   $t6, $t8, 2
/* 0CA6F0 7F095BC0 016E5025 */  or    $t2, $t3, $t6
/* 0CA6F4 7F095BC4 ACCA0004 */  sw    $t2, 4($a2)
/* 0CA6F8 7F095BC8 8FAF06B0 */  lw    $t7, 0x6b0($sp)
/* 0CA6FC 7F095BCC 3C0CE700 */  lui   $t4, 0xe700
/* 0CA700 7F095BD0 3C0B0008 */  lui   $t3, 8
/* 0CA704 7F095BD4 25ED0008 */  addiu $t5, $t7, 8
/* 0CA708 7F095BD8 AFAD06B0 */  sw    $t5, 0x6b0($sp)
/* 0CA70C 7F095BDC ADE00004 */  sw    $zero, 4($t7)
/* 0CA710 7F095BE0 ADEC0000 */  sw    $t4, ($t7)
/* 0CA714 7F095BE4 8FB906B0 */  lw    $t9, 0x6b0($sp)
/* 0CA718 7F095BE8 27380008 */  addiu $t8, $t9, 8
/* 0CA71C 7F095BEC AFB806B0 */  sw    $t8, 0x6b0($sp)
/* 0CA720 7F095BF0 AF2B0004 */  sw    $t3, 4($t9)
/* 0CA724 7F095BF4 1000007B */  b     .L7F095DE4
/* 0CA728 7F095BF8 AF270000 */   sw    $a3, ($t9)
.L7F095BFC:
/* 0CA72C 7F095BFC AFAA06B0 */  sw    $t2, 0x6b0($sp)
/* 0CA730 7F095C00 ADC00004 */  sw    $zero, 4($t6)
/* 0CA734 7F095C04 0FC2E9CB */  jal   get_ptr_currentdata
/* 0CA738 7F095C08 ADCF0000 */   sw    $t7, ($t6)
/* 0CA73C 7F095C0C 844D0028 */  lh    $t5, 0x28($v0)
/* 0CA740 7F095C10 3C198009 */  lui   $t9, %hi(skywaterimages) 
/* 0CA744 7F095C14 8F39D124 */  lw    $t9, %lo(skywaterimages)($t9)
/* 0CA748 7F095C18 000D6080 */  sll   $t4, $t5, 2
/* 0CA74C 7F095C1C 018D6023 */  subu  $t4, $t4, $t5
/* 0CA750 7F095C20 000C6080 */  sll   $t4, $t4, 2
/* 0CA754 7F095C24 24180002 */  li    $t8, 2
/* 0CA758 7F095C28 AFB80010 */  sw    $t8, 0x10($sp)
/* 0CA75C 7F095C2C 27A406B0 */  addiu $a0, $sp, 0x6b0
/* 0CA760 7F095C30 24060001 */  li    $a2, 1
/* 0CA764 7F095C34 00003825 */  move  $a3, $zero
/* 0CA768 7F095C38 0FC1DB5A */  jal   likely_generate_DL_for_image_declaration
/* 0CA76C 7F095C3C 01992821 */   addu  $a1, $t4, $t9
/* 0CA770 7F095C40 8FA406B0 */  lw    $a0, 0x6b0($sp)
/* 0CA774 7F095C44 0FC24D0F */  jal   sub_GAME_7F09343C
/* 0CA778 7F095C48 00002825 */   move  $a1, $zero
/* 0CA77C 7F095C4C 244B0008 */  addiu $t3, $v0, 8
/* 0CA780 7F095C50 3C0EB900 */  lui   $t6, (0xB900031D >> 16) # lui $t6, 0xb900
/* 0CA784 7F095C54 3C0A0F0A */  lui   $t2, (0x0F0A4000 >> 16) # lui $t2, 0xf0a
/* 0CA788 7F095C58 354A4000 */  ori   $t2, (0x0F0A4000 & 0xFFFF) # ori $t2, $t2, 0x4000
/* 0CA78C 7F095C5C 35CE031D */  ori   $t6, (0xB900031D & 0xFFFF) # ori $t6, $t6, 0x31d
/* 0CA790 7F095C60 AFAB06B0 */  sw    $t3, 0x6b0($sp)
/* 0CA794 7F095C64 24010004 */  li    $at, 4
/* 0CA798 7F095C68 AC4A0004 */  sw    $t2, 4($v0)
/* 0CA79C 7F095C6C 1621002A */  bne   $s1, $at, .L7F095D18
/* 0CA7A0 7F095C70 AC4E0000 */   sw    $t6, ($v0)
/* 0CA7A4 7F095C74 3C014302 */  li    $at, 0x43020000 # 130.000000
/* 0CA7A8 7F095C78 44812000 */  mtc1  $at, $f4
/* 0CA7AC 7F095C7C 27B00274 */  addiu $s0, $sp, 0x274
/* 0CA7B0 7F095C80 27B1031C */  addiu $s1, $sp, 0x31c
/* 0CA7B4 7F095C84 240F0001 */  li    $t7, 1
/* 0CA7B8 7F095C88 AFAF0014 */  sw    $t7, 0x14($sp)
/* 0CA7BC 7F095C8C 02203825 */  move  $a3, $s1
/* 0CA7C0 7F095C90 02002825 */  move  $a1, $s0
/* 0CA7C4 7F095C94 8FA406B0 */  lw    $a0, 0x6b0($sp)
/* 0CA7C8 7F095C98 27A602AC */  addiu $a2, $sp, 0x2ac
/* 0CA7CC 7F095C9C 0FC25E06 */  jal   sub_GAME_7F097818
/* 0CA7D0 7F095CA0 E7A40010 */   swc1  $f4, 0x10($sp)
/* 0CA7D4 7F095CA4 8FAD0430 */  lw    $t5, 0x430($sp)
/* 0CA7D8 7F095CA8 00402025 */  move  $a0, $v0
/* 0CA7DC 7F095CAC 02202825 */  move  $a1, $s1
/* 0CA7E0 7F095CB0 11A0000F */  beqz  $t5, .L7F095CF0
/* 0CA7E4 7F095CB4 27A602E4 */   addiu $a2, $sp, 0x2e4
/* 0CA7E8 7F095CB8 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0CA7EC 7F095CBC 44811000 */  mtc1  $at, $f2
/* 0CA7F0 7F095CC0 C7A602D8 */  lwc1  $f6, 0x2d8($sp)
/* 0CA7F4 7F095CC4 C7A002A0 */  lwc1  $f0, 0x2a0($sp)
/* 0CA7F8 7F095CC8 C7AA0310 */  lwc1  $f10, 0x310($sp)
/* 0CA7FC 7F095CCC 46023200 */  add.s $f8, $f6, $f2
/* 0CA800 7F095CD0 C7A60348 */  lwc1  $f6, 0x348($sp)
/* 0CA804 7F095CD4 46020000 */  add.s $f0, $f0, $f2
/* 0CA808 7F095CD8 E7A802D8 */  swc1  $f8, 0x2d8($sp)
/* 0CA80C 7F095CDC 46025100 */  add.s $f4, $f10, $f2
/* 0CA810 7F095CE0 E7A002A0 */  swc1  $f0, 0x2a0($sp)
/* 0CA814 7F095CE4 46023200 */  add.s $f8, $f6, $f2
/* 0CA818 7F095CE8 E7A40310 */  swc1  $f4, 0x310($sp)
/* 0CA81C 7F095CEC E7A80348 */  swc1  $f8, 0x348($sp)
.L7F095CF0:
/* 0CA820 7F095CF0 3C014302 */  li    $at, 0x43020000 # 130.000000
/* 0CA824 7F095CF4 44815000 */  mtc1  $at, $f10
/* 0CA828 7F095CF8 240C0001 */  li    $t4, 1
/* 0CA82C 7F095CFC AFAC0014 */  sw    $t4, 0x14($sp)
/* 0CA830 7F095D00 02003825 */  move  $a3, $s0
/* 0CA834 7F095D04 AFA406B0 */  sw    $a0, 0x6b0($sp)
/* 0CA838 7F095D08 0FC25E06 */  jal   sub_GAME_7F097818
/* 0CA83C 7F095D0C E7AA0010 */   swc1  $f10, 0x10($sp)
/* 0CA840 7F095D10 10000034 */  b     .L7F095DE4
/* 0CA844 7F095D14 AFA206B0 */   sw    $v0, 0x6b0($sp)
.L7F095D18:
/* 0CA848 7F095D18 24010005 */  li    $at, 5
/* 0CA84C 7F095D1C 16210024 */  bne   $s1, $at, .L7F095DB0
/* 0CA850 7F095D20 27B00274 */   addiu $s0, $sp, 0x274
/* 0CA854 7F095D24 3C014302 */  li    $at, 0x43020000 # 130.000000
/* 0CA858 7F095D28 44812000 */  mtc1  $at, $f4
/* 0CA85C 7F095D2C 24190001 */  li    $t9, 1
/* 0CA860 7F095D30 AFB90014 */  sw    $t9, 0x14($sp)
/* 0CA864 7F095D34 8FA406B0 */  lw    $a0, 0x6b0($sp)
/* 0CA868 7F095D38 02002825 */  move  $a1, $s0
/* 0CA86C 7F095D3C 27A602AC */  addiu $a2, $sp, 0x2ac
/* 0CA870 7F095D40 27A702E4 */  addiu $a3, $sp, 0x2e4
/* 0CA874 7F095D44 0FC25E06 */  jal   sub_GAME_7F097818
/* 0CA878 7F095D48 E7A40010 */   swc1  $f4, 0x10($sp)
/* 0CA87C 7F095D4C 3C014302 */  li    $at, 0x43020000 # 130.000000
/* 0CA880 7F095D50 44813000 */  mtc1  $at, $f6
/* 0CA884 7F095D54 27B1031C */  addiu $s1, $sp, 0x31c
/* 0CA888 7F095D58 24180001 */  li    $t8, 1
/* 0CA88C 7F095D5C AFA206B0 */  sw    $v0, 0x6b0($sp)
/* 0CA890 7F095D60 AFB80014 */  sw    $t8, 0x14($sp)
/* 0CA894 7F095D64 02203825 */  move  $a3, $s1
/* 0CA898 7F095D68 00402025 */  move  $a0, $v0
/* 0CA89C 7F095D6C 02002825 */  move  $a1, $s0
/* 0CA8A0 7F095D70 27A602E4 */  addiu $a2, $sp, 0x2e4
/* 0CA8A4 7F095D74 0FC25E06 */  jal   sub_GAME_7F097818
/* 0CA8A8 7F095D78 E7A60010 */   swc1  $f6, 0x10($sp)
/* 0CA8AC 7F095D7C 3C014302 */  li    $at, 0x43020000 # 130.000000
/* 0CA8B0 7F095D80 44814000 */  mtc1  $at, $f8
/* 0CA8B4 7F095D84 240B0001 */  li    $t3, 1
/* 0CA8B8 7F095D88 AFA206B0 */  sw    $v0, 0x6b0($sp)
/* 0CA8BC 7F095D8C AFAB0014 */  sw    $t3, 0x14($sp)
/* 0CA8C0 7F095D90 00402025 */  move  $a0, $v0
/* 0CA8C4 7F095D94 02002825 */  move  $a1, $s0
/* 0CA8C8 7F095D98 02203025 */  move  $a2, $s1
/* 0CA8CC 7F095D9C 27A70354 */  addiu $a3, $sp, 0x354
/* 0CA8D0 7F095DA0 0FC25E06 */  jal   sub_GAME_7F097818
/* 0CA8D4 7F095DA4 E7A80010 */   swc1  $f8, 0x10($sp)
/* 0CA8D8 7F095DA8 1000000E */  b     .L7F095DE4
/* 0CA8DC 7F095DAC AFA206B0 */   sw    $v0, 0x6b0($sp)
.L7F095DB0:
/* 0CA8E0 7F095DB0 24010003 */  li    $at, 3
/* 0CA8E4 7F095DB4 1621000B */  bne   $s1, $at, .L7F095DE4
/* 0CA8E8 7F095DB8 27A50274 */   addiu $a1, $sp, 0x274
/* 0CA8EC 7F095DBC 3C014302 */  li    $at, 0x43020000 # 130.000000
/* 0CA8F0 7F095DC0 44815000 */  mtc1  $at, $f10
/* 0CA8F4 7F095DC4 240E0001 */  li    $t6, 1
/* 0CA8F8 7F095DC8 AFAE0014 */  sw    $t6, 0x14($sp)
/* 0CA8FC 7F095DCC 8FA406B0 */  lw    $a0, 0x6b0($sp)
/* 0CA900 7F095DD0 27A602AC */  addiu $a2, $sp, 0x2ac
/* 0CA904 7F095DD4 27A702E4 */  addiu $a3, $sp, 0x2e4
/* 0CA908 7F095DD8 0FC25E06 */  jal   sub_GAME_7F097818
/* 0CA90C 7F095DDC E7AA0010 */   swc1  $f10, 0x10($sp)
/* 0CA910 7F095DE0 AFA206B0 */  sw    $v0, 0x6b0($sp)
.L7F095DE4:
/* 0CA914 7F095DE4 8FAA005C */  lw    $t2, 0x5c($sp)
.L7F095DE8:
/* 0CA918 7F095DE8 3C014080 */  li    $at, 0x40800000 # 4.000000
/* 0CA91C 7F095DEC 4481D000 */  mtc1  $at, $f26
/* 0CA920 7F095DF0 2D410010 */  sltiu $at, $t2, 0x10
/* 0CA924 7F095DF4 1020040A */  beqz  $at, .L7F096E20
/* 0CA928 7F095DF8 8FA306B0 */   lw    $v1, 0x6b0($sp)
/* 0CA92C 7F095DFC 000A5080 */  sll   $t2, $t2, 2
/* 0CA930 7F095E00 3C018005 */  lui   $at, %hi(jpt_80057590)
/* 0CA934 7F095E04 002A0821 */  addu  $at, $at, $t2
/* 0CA938 7F095E08 8C2A7590 */  lw    $t2, %lo(jpt_80057590)($at)
.L7F095E0C:
/* 0CA93C 7F095E0C 01400008 */  jr    $t2
/* 0CA940 7F095E10 00000000 */   nop   
.L7F095E14:
/* 0CA944 7F095E14 10000552 */  b     .L7F097360
/* 0CA948 7F095E18 00601025 */   move  $v0, $v1
.L7F095E1C:
/* 0CA94C 7F095E1C C7A20644 */  lwc1  $f2, 0x644($sp)
/* 0CA950 7F095E20 C7A60648 */  lwc1  $f6, 0x648($sp)
/* 0CA954 7F095E24 C7AC064C */  lwc1  $f12, 0x64c($sp)
/* 0CA958 7F095E28 46181102 */  mul.s $f4, $f2, $f24
/* 0CA95C 7F095E2C C7AE0638 */  lwc1  $f14, 0x638($sp)
/* 0CA960 7F095E30 C7B00640 */  lwc1  $f16, 0x640($sp)
/* 0CA964 7F095E34 46183202 */  mul.s $f8, $f6, $f24
/* 0CA968 7F095E38 C7A6063C */  lwc1  $f6, 0x63c($sp)
/* 0CA96C 7F095E3C C7B2062C */  lwc1  $f18, 0x62c($sp)
/* 0CA970 7F095E40 46186282 */  mul.s $f10, $f12, $f24
/* 0CA974 7F095E44 E7A404B4 */  swc1  $f4, 0x4b4($sp)
/* 0CA978 7F095E48 C7B40634 */  lwc1  $f20, 0x634($sp)
/* 0CA97C 7F095E4C 46187102 */  mul.s $f4, $f14, $f24
/* 0CA980 7F095E50 E7A804B8 */  swc1  $f8, 0x4b8($sp)
/* 0CA984 7F095E54 C7B60620 */  lwc1  $f22, 0x620($sp)
/* 0CA988 7F095E58 46183202 */  mul.s $f8, $f6, $f24
/* 0CA98C 7F095E5C E7AA04BC */  swc1  $f10, 0x4bc($sp)
/* 0CA990 7F095E60 C7A60630 */  lwc1  $f6, 0x630($sp)
/* 0CA994 7F095E64 46188282 */  mul.s $f10, $f16, $f24
/* 0CA998 7F095E68 E7A404CC */  swc1  $f4, 0x4cc($sp)
/* 0CA99C 7F095E6C 3C018004 */  lui   $at, %hi(D_8003FD94)
/* 0CA9A0 7F095E70 46189102 */  mul.s $f4, $f18, $f24
/* 0CA9A4 7F095E74 E7A804D0 */  swc1  $f8, 0x4d0($sp)
/* 0CA9A8 7F095E78 C420FD94 */  lwc1  $f0, %lo(D_8003FD94)($at)
/* 0CA9AC 7F095E7C 46183202 */  mul.s $f8, $f6, $f24
/* 0CA9B0 7F095E80 E7AA04D4 */  swc1  $f10, 0x4d4($sp)
/* 0CA9B4 7F095E84 C7A60624 */  lwc1  $f6, 0x624($sp)
/* 0CA9B8 7F095E88 4618A282 */  mul.s $f10, $f20, $f24
/* 0CA9BC 7F095E8C E7A404E4 */  swc1  $f4, 0x4e4($sp)
/* 0CA9C0 7F095E90 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0CA9C4 7F095E94 4618B102 */  mul.s $f4, $f22, $f24
/* 0CA9C8 7F095E98 E7A804E8 */  swc1  $f8, 0x4e8($sp)
/* 0CA9CC 7F095E9C 24110004 */  li    $s1, 4
/* 0CA9D0 7F095EA0 46183202 */  mul.s $f8, $f6, $f24
/* 0CA9D4 7F095EA4 E7AA04EC */  swc1  $f10, 0x4ec($sp)
/* 0CA9D8 7F095EA8 C7AA0628 */  lwc1  $f10, 0x628($sp)
/* 0CA9DC 7F095EAC 27A404B4 */  addiu $a0, $sp, 0x4b4
/* 0CA9E0 7F095EB0 E7A404FC */  swc1  $f4, 0x4fc($sp)
/* 0CA9E4 7F095EB4 46185102 */  mul.s $f4, $f10, $f24
/* 0CA9E8 7F095EB8 8FA5058C */  lw    $a1, 0x58c($sp)
/* 0CA9EC 7F095EBC E7A80500 */  swc1  $f8, 0x500($sp)
/* 0CA9F0 7F095EC0 461C1182 */  mul.s $f6, $f2, $f28
/* 0CA9F4 7F095EC4 00000000 */  nop   
/* 0CA9F8 7F095EC8 461C6202 */  mul.s $f8, $f12, $f28
/* 0CA9FC 7F095ECC E7A40504 */  swc1  $f4, 0x504($sp)
/* 0CAA00 7F095ED0 461C7102 */  mul.s $f4, $f14, $f28
/* 0CAA04 7F095ED4 E7A604C0 */  swc1  $f6, 0x4c0($sp)
/* 0CAA08 7F095ED8 461C8182 */  mul.s $f6, $f16, $f28
/* 0CAA0C 7F095EDC 46004280 */  add.s $f10, $f8, $f0
/* 0CAA10 7F095EE0 E7A404D8 */  swc1  $f4, 0x4d8($sp)
/* 0CAA14 7F095EE4 E7AA04C4 */  swc1  $f10, 0x4c4($sp)
/* 0CAA18 7F095EE8 461C9282 */  mul.s $f10, $f18, $f28
/* 0CAA1C 7F095EEC 46003200 */  add.s $f8, $f6, $f0
/* 0CAA20 7F095EF0 461CA102 */  mul.s $f4, $f20, $f28
/* 0CAA24 7F095EF4 E7A804DC */  swc1  $f8, 0x4dc($sp)
/* 0CAA28 7F095EF8 461CB202 */  mul.s $f8, $f22, $f28
/* 0CAA2C 7F095EFC E7AA04F0 */  swc1  $f10, 0x4f0($sp)
/* 0CAA30 7F095F00 C7AA0628 */  lwc1  $f10, 0x628($sp)
/* 0CAA34 7F095F04 46002180 */  add.s $f6, $f4, $f0
/* 0CAA38 7F095F08 461C5102 */  mul.s $f4, $f10, $f28
/* 0CAA3C 7F095F0C E7A80508 */  swc1  $f8, 0x508($sp)
/* 0CAA40 7F095F10 44814000 */  mtc1  $at, $f8
/* 0CAA44 7F095F14 E7A604F4 */  swc1  $f6, 0x4f4($sp)
/* 0CAA48 7F095F18 46184283 */  div.s $f10, $f8, $f24
/* 0CAA4C 7F095F1C 46002180 */  add.s $f6, $f4, $f0
/* 0CAA50 7F095F20 E7A6050C */  swc1  $f6, 0x50c($sp)
/* 0CAA54 7F095F24 0FC24F2C */  jal   sub_GAME_7F093CB0
/* 0CAA58 7F095F28 E7AA0058 */   swc1  $f10, 0x58($sp)
/* 0CAA5C 7F095F2C 27A404CC */  addiu $a0, $sp, 0x4cc
/* 0CAA60 7F095F30 0FC24F2C */  jal   sub_GAME_7F093CB0
/* 0CAA64 7F095F34 8FA50588 */   lw    $a1, 0x588($sp)
/* 0CAA68 7F095F38 27A404E4 */  addiu $a0, $sp, 0x4e4
/* 0CAA6C 7F095F3C 0FC24F2C */  jal   sub_GAME_7F093CB0
/* 0CAA70 7F095F40 8FA50584 */   lw    $a1, 0x584($sp)
/* 0CAA74 7F095F44 27A404FC */  addiu $a0, $sp, 0x4fc
/* 0CAA78 7F095F48 0FC24F2C */  jal   sub_GAME_7F093CB0
/* 0CAA7C 7F095F4C 8FA50580 */   lw    $a1, 0x580($sp)
/* 0CAA80 7F095F50 100003B6 */  b     .L7F096E2C
/* 0CAA84 7F095F54 8FAF06B0 */   lw    $t7, 0x6b0($sp)
.L7F095F58:
/* 0CAA88 7F095F58 C7A20644 */  lwc1  $f2, 0x644($sp)
/* 0CAA8C 7F095F5C C7A60648 */  lwc1  $f6, 0x648($sp)
/* 0CAA90 7F095F60 C7AC064C */  lwc1  $f12, 0x64c($sp)
/* 0CAA94 7F095F64 46181102 */  mul.s $f4, $f2, $f24
/* 0CAA98 7F095F68 C7AE0638 */  lwc1  $f14, 0x638($sp)
/* 0CAA9C 7F095F6C C7B00640 */  lwc1  $f16, 0x640($sp)
/* 0CAAA0 7F095F70 46183202 */  mul.s $f8, $f6, $f24
/* 0CAAA4 7F095F74 C7A6063C */  lwc1  $f6, 0x63c($sp)
/* 0CAAA8 7F095F78 C7B205FC */  lwc1  $f18, 0x5fc($sp)
/* 0CAAAC 7F095F7C 46186282 */  mul.s $f10, $f12, $f24
/* 0CAAB0 7F095F80 E7A404B4 */  swc1  $f4, 0x4b4($sp)
/* 0CAAB4 7F095F84 C7B40604 */  lwc1  $f20, 0x604($sp)
/* 0CAAB8 7F095F88 46187102 */  mul.s $f4, $f14, $f24
/* 0CAABC 7F095F8C E7A804B8 */  swc1  $f8, 0x4b8($sp)
/* 0CAAC0 7F095F90 C7B605F0 */  lwc1  $f22, 0x5f0($sp)
/* 0CAAC4 7F095F94 46183202 */  mul.s $f8, $f6, $f24
/* 0CAAC8 7F095F98 E7AA04BC */  swc1  $f10, 0x4bc($sp)
/* 0CAACC 7F095F9C C7A60600 */  lwc1  $f6, 0x600($sp)
/* 0CAAD0 7F095FA0 46188282 */  mul.s $f10, $f16, $f24
/* 0CAAD4 7F095FA4 E7A404CC */  swc1  $f4, 0x4cc($sp)
/* 0CAAD8 7F095FA8 3C018004 */  lui   $at, %hi(D_8003FD94)
/* 0CAADC 7F095FAC 46189102 */  mul.s $f4, $f18, $f24
/* 0CAAE0 7F095FB0 E7A804D0 */  swc1  $f8, 0x4d0($sp)
/* 0CAAE4 7F095FB4 C420FD94 */  lwc1  $f0, %lo(D_8003FD94)($at)
/* 0CAAE8 7F095FB8 46183202 */  mul.s $f8, $f6, $f24
/* 0CAAEC 7F095FBC E7AA04D4 */  swc1  $f10, 0x4d4($sp)
/* 0CAAF0 7F095FC0 C7A605F4 */  lwc1  $f6, 0x5f4($sp)
/* 0CAAF4 7F095FC4 4618A282 */  mul.s $f10, $f20, $f24
/* 0CAAF8 7F095FC8 E7A404E4 */  swc1  $f4, 0x4e4($sp)
/* 0CAAFC 7F095FCC 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0CAB00 7F095FD0 4618B102 */  mul.s $f4, $f22, $f24
/* 0CAB04 7F095FD4 E7A804E8 */  swc1  $f8, 0x4e8($sp)
/* 0CAB08 7F095FD8 24110004 */  li    $s1, 4
/* 0CAB0C 7F095FDC 46183202 */  mul.s $f8, $f6, $f24
/* 0CAB10 7F095FE0 E7AA04EC */  swc1  $f10, 0x4ec($sp)
/* 0CAB14 7F095FE4 C7AA05F8 */  lwc1  $f10, 0x5f8($sp)
/* 0CAB18 7F095FE8 27A404B4 */  addiu $a0, $sp, 0x4b4
/* 0CAB1C 7F095FEC E7A404FC */  swc1  $f4, 0x4fc($sp)
/* 0CAB20 7F095FF0 46185102 */  mul.s $f4, $f10, $f24
/* 0CAB24 7F095FF4 8FA5058C */  lw    $a1, 0x58c($sp)
/* 0CAB28 7F095FF8 E7A80500 */  swc1  $f8, 0x500($sp)
/* 0CAB2C 7F095FFC 461C1182 */  mul.s $f6, $f2, $f28
/* 0CAB30 7F096000 00000000 */  nop   
/* 0CAB34 7F096004 461C6202 */  mul.s $f8, $f12, $f28
/* 0CAB38 7F096008 E7A40504 */  swc1  $f4, 0x504($sp)
/* 0CAB3C 7F09600C 461C7102 */  mul.s $f4, $f14, $f28
/* 0CAB40 7F096010 E7A604C0 */  swc1  $f6, 0x4c0($sp)
/* 0CAB44 7F096014 461C8182 */  mul.s $f6, $f16, $f28
/* 0CAB48 7F096018 46004280 */  add.s $f10, $f8, $f0
/* 0CAB4C 7F09601C E7A404D8 */  swc1  $f4, 0x4d8($sp)
/* 0CAB50 7F096020 E7AA04C4 */  swc1  $f10, 0x4c4($sp)
/* 0CAB54 7F096024 461C9282 */  mul.s $f10, $f18, $f28
/* 0CAB58 7F096028 46003200 */  add.s $f8, $f6, $f0
/* 0CAB5C 7F09602C 461CA102 */  mul.s $f4, $f20, $f28
/* 0CAB60 7F096030 E7A804DC */  swc1  $f8, 0x4dc($sp)
/* 0CAB64 7F096034 461CB202 */  mul.s $f8, $f22, $f28
/* 0CAB68 7F096038 E7AA04F0 */  swc1  $f10, 0x4f0($sp)
/* 0CAB6C 7F09603C C7AA05F8 */  lwc1  $f10, 0x5f8($sp)
/* 0CAB70 7F096040 46002180 */  add.s $f6, $f4, $f0
/* 0CAB74 7F096044 461C5102 */  mul.s $f4, $f10, $f28
/* 0CAB78 7F096048 E7A80508 */  swc1  $f8, 0x508($sp)
/* 0CAB7C 7F09604C 44814000 */  mtc1  $at, $f8
/* 0CAB80 7F096050 E7A604F4 */  swc1  $f6, 0x4f4($sp)
/* 0CAB84 7F096054 46184283 */  div.s $f10, $f8, $f24
/* 0CAB88 7F096058 46002180 */  add.s $f6, $f4, $f0
/* 0CAB8C 7F09605C E7A6050C */  swc1  $f6, 0x50c($sp)
/* 0CAB90 7F096060 0FC24F2C */  jal   sub_GAME_7F093CB0
/* 0CAB94 7F096064 E7AA0058 */   swc1  $f10, 0x58($sp)
/* 0CAB98 7F096068 27A404CC */  addiu $a0, $sp, 0x4cc
/* 0CAB9C 7F09606C 0FC24F2C */  jal   sub_GAME_7F093CB0
/* 0CABA0 7F096070 8FA50588 */   lw    $a1, 0x588($sp)
/* 0CABA4 7F096074 27A404E4 */  addiu $a0, $sp, 0x4e4
/* 0CABA8 7F096078 0FC24F2C */  jal   sub_GAME_7F093CB0
/* 0CABAC 7F09607C 8FA50574 */   lw    $a1, 0x574($sp)
/* 0CABB0 7F096080 27A404FC */  addiu $a0, $sp, 0x4fc
/* 0CABB4 7F096084 0FC24F2C */  jal   sub_GAME_7F093CB0
/* 0CABB8 7F096088 8FA50570 */   lw    $a1, 0x570($sp)
/* 0CABBC 7F09608C 10000367 */  b     .L7F096E2C
/* 0CABC0 7F096090 8FAF06B0 */   lw    $t7, 0x6b0($sp)
.L7F096094:
/* 0CABC4 7F096094 C7B60620 */  lwc1  $f22, 0x620($sp)
/* 0CABC8 7F096098 C7A60624 */  lwc1  $f6, 0x624($sp)
/* 0CABCC 7F09609C C7A20628 */  lwc1  $f2, 0x628($sp)
/* 0CABD0 7F0960A0 4618B102 */  mul.s $f4, $f22, $f24
/* 0CABD4 7F0960A4 C7B2062C */  lwc1  $f18, 0x62c($sp)
/* 0CABD8 7F0960A8 C7B40634 */  lwc1  $f20, 0x634($sp)
/* 0CABDC 7F0960AC 46183202 */  mul.s $f8, $f6, $f24
/* 0CABE0 7F0960B0 C7A60630 */  lwc1  $f6, 0x630($sp)
/* 0CABE4 7F0960B4 C7B005F0 */  lwc1  $f16, 0x5f0($sp)
/* 0CABE8 7F0960B8 46181282 */  mul.s $f10, $f2, $f24
/* 0CABEC 7F0960BC E7A404B4 */  swc1  $f4, 0x4b4($sp)
/* 0CABF0 7F0960C0 C7AC05FC */  lwc1  $f12, 0x5fc($sp)
/* 0CABF4 7F0960C4 46189102 */  mul.s $f4, $f18, $f24
/* 0CABF8 7F0960C8 E7A804B8 */  swc1  $f8, 0x4b8($sp)
/* 0CABFC 7F0960CC C7AE0604 */  lwc1  $f14, 0x604($sp)
/* 0CAC00 7F0960D0 46183202 */  mul.s $f8, $f6, $f24
/* 0CAC04 7F0960D4 E7AA04BC */  swc1  $f10, 0x4bc($sp)
/* 0CAC08 7F0960D8 C7A605F4 */  lwc1  $f6, 0x5f4($sp)
/* 0CAC0C 7F0960DC 4618A282 */  mul.s $f10, $f20, $f24
/* 0CAC10 7F0960E0 E7A404CC */  swc1  $f4, 0x4cc($sp)
/* 0CAC14 7F0960E4 3C018004 */  lui   $at, %hi(D_8003FD94)
/* 0CAC18 7F0960E8 46188102 */  mul.s $f4, $f16, $f24
/* 0CAC1C 7F0960EC E7A804D0 */  swc1  $f8, 0x4d0($sp)
/* 0CAC20 7F0960F0 C420FD94 */  lwc1  $f0, %lo(D_8003FD94)($at)
/* 0CAC24 7F0960F4 46183202 */  mul.s $f8, $f6, $f24
/* 0CAC28 7F0960F8 E7AA04D4 */  swc1  $f10, 0x4d4($sp)
/* 0CAC2C 7F0960FC C7AA05F8 */  lwc1  $f10, 0x5f8($sp)
/* 0CAC30 7F096100 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0CAC34 7F096104 E7A404E4 */  swc1  $f4, 0x4e4($sp)
/* 0CAC38 7F096108 46185102 */  mul.s $f4, $f10, $f24
/* 0CAC3C 7F09610C 24110004 */  li    $s1, 4
/* 0CAC40 7F096110 E7A804E8 */  swc1  $f8, 0x4e8($sp)
/* 0CAC44 7F096114 46186182 */  mul.s $f6, $f12, $f24
/* 0CAC48 7F096118 C7A80600 */  lwc1  $f8, 0x600($sp)
/* 0CAC4C 7F09611C 27A404B4 */  addiu $a0, $sp, 0x4b4
/* 0CAC50 7F096120 8FA50580 */  lw    $a1, 0x580($sp)
/* 0CAC54 7F096124 46184282 */  mul.s $f10, $f8, $f24
/* 0CAC58 7F096128 E7A404EC */  swc1  $f4, 0x4ec($sp)
/* 0CAC5C 7F09612C 46187102 */  mul.s $f4, $f14, $f24
/* 0CAC60 7F096130 E7A604FC */  swc1  $f6, 0x4fc($sp)
/* 0CAC64 7F096134 461CB182 */  mul.s $f6, $f22, $f28
/* 0CAC68 7F096138 E7AA0500 */  swc1  $f10, 0x500($sp)
/* 0CAC6C 7F09613C 461C1202 */  mul.s $f8, $f2, $f28
/* 0CAC70 7F096140 E7A40504 */  swc1  $f4, 0x504($sp)
/* 0CAC74 7F096144 461C9102 */  mul.s $f4, $f18, $f28
/* 0CAC78 7F096148 E7A604C0 */  swc1  $f6, 0x4c0($sp)
/* 0CAC7C 7F09614C 461CA182 */  mul.s $f6, $f20, $f28
/* 0CAC80 7F096150 46004280 */  add.s $f10, $f8, $f0
/* 0CAC84 7F096154 E7A404D8 */  swc1  $f4, 0x4d8($sp)
/* 0CAC88 7F096158 C7A405F8 */  lwc1  $f4, 0x5f8($sp)
/* 0CAC8C 7F09615C E7AA04C4 */  swc1  $f10, 0x4c4($sp)
/* 0CAC90 7F096160 461C8282 */  mul.s $f10, $f16, $f28
/* 0CAC94 7F096164 46003200 */  add.s $f8, $f6, $f0
/* 0CAC98 7F096168 461C2182 */  mul.s $f6, $f4, $f28
/* 0CAC9C 7F09616C E7A804DC */  swc1  $f8, 0x4dc($sp)
/* 0CACA0 7F096170 E7AA04F0 */  swc1  $f10, 0x4f0($sp)
/* 0CACA4 7F096174 461C6282 */  mul.s $f10, $f12, $f28
/* 0CACA8 7F096178 46003200 */  add.s $f8, $f6, $f0
/* 0CACAC 7F09617C 461C7102 */  mul.s $f4, $f14, $f28
/* 0CACB0 7F096180 E7A804F4 */  swc1  $f8, 0x4f4($sp)
/* 0CACB4 7F096184 44814000 */  mtc1  $at, $f8
/* 0CACB8 7F096188 E7AA0508 */  swc1  $f10, 0x508($sp)
/* 0CACBC 7F09618C 46184283 */  div.s $f10, $f8, $f24
/* 0CACC0 7F096190 46002180 */  add.s $f6, $f4, $f0
/* 0CACC4 7F096194 E7A6050C */  swc1  $f6, 0x50c($sp)
/* 0CACC8 7F096198 0FC24F2C */  jal   sub_GAME_7F093CB0
/* 0CACCC 7F09619C E7AA0058 */   swc1  $f10, 0x58($sp)
/* 0CACD0 7F0961A0 27A404CC */  addiu $a0, $sp, 0x4cc
/* 0CACD4 7F0961A4 0FC24F2C */  jal   sub_GAME_7F093CB0
/* 0CACD8 7F0961A8 8FA50584 */   lw    $a1, 0x584($sp)
/* 0CACDC 7F0961AC 27A404E4 */  addiu $a0, $sp, 0x4e4
/* 0CACE0 7F0961B0 0FC24F2C */  jal   sub_GAME_7F093CB0
/* 0CACE4 7F0961B4 8FA50570 */   lw    $a1, 0x570($sp)
/* 0CACE8 7F0961B8 27A404FC */  addiu $a0, $sp, 0x4fc
/* 0CACEC 7F0961BC 0FC24F2C */  jal   sub_GAME_7F093CB0
/* 0CACF0 7F0961C0 8FA50574 */   lw    $a1, 0x574($sp)
/* 0CACF4 7F0961C4 10000319 */  b     .L7F096E2C
/* 0CACF8 7F0961C8 8FAF06B0 */   lw    $t7, 0x6b0($sp)
.L7F0961CC:
/* 0CACFC 7F0961CC C7AE0638 */  lwc1  $f14, 0x638($sp)
/* 0CAD00 7F0961D0 C7A6063C */  lwc1  $f6, 0x63c($sp)
/* 0CAD04 7F0961D4 C7B00640 */  lwc1  $f16, 0x640($sp)
/* 0CAD08 7F0961D8 46187102 */  mul.s $f4, $f14, $f24
/* 0CAD0C 7F0961DC C7B60620 */  lwc1  $f22, 0x620($sp)
/* 0CAD10 7F0961E0 C7A20628 */  lwc1  $f2, 0x628($sp)
/* 0CAD14 7F0961E4 46183202 */  mul.s $f8, $f6, $f24
/* 0CAD18 7F0961E8 C7A60624 */  lwc1  $f6, 0x624($sp)
/* 0CAD1C 7F0961EC C7B40614 */  lwc1  $f20, 0x614($sp)
/* 0CAD20 7F0961F0 46188282 */  mul.s $f10, $f16, $f24
/* 0CAD24 7F0961F4 E7A404B4 */  swc1  $f4, 0x4b4($sp)
/* 0CAD28 7F0961F8 C7AC0608 */  lwc1  $f12, 0x608($sp)
/* 0CAD2C 7F0961FC 4618B102 */  mul.s $f4, $f22, $f24
/* 0CAD30 7F096200 E7A804B8 */  swc1  $f8, 0x4b8($sp)
/* 0CAD34 7F096204 C7B20610 */  lwc1  $f18, 0x610($sp)
/* 0CAD38 7F096208 46183202 */  mul.s $f8, $f6, $f24
/* 0CAD3C 7F09620C E7AA04BC */  swc1  $f10, 0x4bc($sp)
/* 0CAD40 7F096210 C7A60618 */  lwc1  $f6, 0x618($sp)
/* 0CAD44 7F096214 46181282 */  mul.s $f10, $f2, $f24
/* 0CAD48 7F096218 E7A404CC */  swc1  $f4, 0x4cc($sp)
/* 0CAD4C 7F09621C 3C018004 */  lui   $at, %hi(D_8003FD94)
/* 0CAD50 7F096220 4618A102 */  mul.s $f4, $f20, $f24
/* 0CAD54 7F096224 E7A804D0 */  swc1  $f8, 0x4d0($sp)
/* 0CAD58 7F096228 C420FD94 */  lwc1  $f0, %lo(D_8003FD94)($at)
/* 0CAD5C 7F09622C 46183202 */  mul.s $f8, $f6, $f24
/* 0CAD60 7F096230 E7AA04D4 */  swc1  $f10, 0x4d4($sp)
/* 0CAD64 7F096234 C7AA061C */  lwc1  $f10, 0x61c($sp)
/* 0CAD68 7F096238 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0CAD6C 7F09623C E7A404E4 */  swc1  $f4, 0x4e4($sp)
/* 0CAD70 7F096240 46185102 */  mul.s $f4, $f10, $f24
/* 0CAD74 7F096244 24110004 */  li    $s1, 4
/* 0CAD78 7F096248 E7A804E8 */  swc1  $f8, 0x4e8($sp)
/* 0CAD7C 7F09624C 46186182 */  mul.s $f6, $f12, $f24
/* 0CAD80 7F096250 C7A8060C */  lwc1  $f8, 0x60c($sp)
/* 0CAD84 7F096254 27A404B4 */  addiu $a0, $sp, 0x4b4
/* 0CAD88 7F096258 8FA50588 */  lw    $a1, 0x588($sp)
/* 0CAD8C 7F09625C 46184282 */  mul.s $f10, $f8, $f24
/* 0CAD90 7F096260 E7A404EC */  swc1  $f4, 0x4ec($sp)
/* 0CAD94 7F096264 46189102 */  mul.s $f4, $f18, $f24
/* 0CAD98 7F096268 E7A604FC */  swc1  $f6, 0x4fc($sp)
/* 0CAD9C 7F09626C 461C7182 */  mul.s $f6, $f14, $f28
/* 0CADA0 7F096270 E7AA0500 */  swc1  $f10, 0x500($sp)
/* 0CADA4 7F096274 461C8202 */  mul.s $f8, $f16, $f28
/* 0CADA8 7F096278 E7A40504 */  swc1  $f4, 0x504($sp)
/* 0CADAC 7F09627C 461CB102 */  mul.s $f4, $f22, $f28
/* 0CADB0 7F096280 E7A604C0 */  swc1  $f6, 0x4c0($sp)
/* 0CADB4 7F096284 461C1182 */  mul.s $f6, $f2, $f28
/* 0CADB8 7F096288 46004280 */  add.s $f10, $f8, $f0
/* 0CADBC 7F09628C E7A404D8 */  swc1  $f4, 0x4d8($sp)
/* 0CADC0 7F096290 C7A4061C */  lwc1  $f4, 0x61c($sp)
/* 0CADC4 7F096294 E7AA04C4 */  swc1  $f10, 0x4c4($sp)
/* 0CADC8 7F096298 461CA282 */  mul.s $f10, $f20, $f28
/* 0CADCC 7F09629C 46003200 */  add.s $f8, $f6, $f0
/* 0CADD0 7F0962A0 461C2182 */  mul.s $f6, $f4, $f28
/* 0CADD4 7F0962A4 E7A804DC */  swc1  $f8, 0x4dc($sp)
/* 0CADD8 7F0962A8 E7AA04F0 */  swc1  $f10, 0x4f0($sp)
/* 0CADDC 7F0962AC 461C6282 */  mul.s $f10, $f12, $f28
/* 0CADE0 7F0962B0 46003200 */  add.s $f8, $f6, $f0
/* 0CADE4 7F0962B4 461C9102 */  mul.s $f4, $f18, $f28
/* 0CADE8 7F0962B8 E7A804F4 */  swc1  $f8, 0x4f4($sp)
/* 0CADEC 7F0962BC 44814000 */  mtc1  $at, $f8
/* 0CADF0 7F0962C0 E7AA0508 */  swc1  $f10, 0x508($sp)
/* 0CADF4 7F0962C4 46184283 */  div.s $f10, $f8, $f24
/* 0CADF8 7F0962C8 46002180 */  add.s $f6, $f4, $f0
/* 0CADFC 7F0962CC E7A6050C */  swc1  $f6, 0x50c($sp)
/* 0CAE00 7F0962D0 0FC24F2C */  jal   sub_GAME_7F093CB0
/* 0CAE04 7F0962D4 E7AA0058 */   swc1  $f10, 0x58($sp)
/* 0CAE08 7F0962D8 27A404CC */  addiu $a0, $sp, 0x4cc
/* 0CAE0C 7F0962DC 0FC24F2C */  jal   sub_GAME_7F093CB0
/* 0CAE10 7F0962E0 8FA50580 */   lw    $a1, 0x580($sp)
/* 0CAE14 7F0962E4 27A404E4 */  addiu $a0, $sp, 0x4e4
/* 0CAE18 7F0962E8 0FC24F2C */  jal   sub_GAME_7F093CB0
/* 0CAE1C 7F0962EC 8FA5057C */   lw    $a1, 0x57c($sp)
/* 0CAE20 7F0962F0 27A404FC */  addiu $a0, $sp, 0x4fc
/* 0CAE24 7F0962F4 0FC24F2C */  jal   sub_GAME_7F093CB0
/* 0CAE28 7F0962F8 8FA50578 */   lw    $a1, 0x578($sp)
/* 0CAE2C 7F0962FC 100002CB */  b     .L7F096E2C
/* 0CAE30 7F096300 8FAF06B0 */   lw    $t7, 0x6b0($sp)
.L7F096304:
/* 0CAE34 7F096304 C7B2062C */  lwc1  $f18, 0x62c($sp)
/* 0CAE38 7F096308 C7A60630 */  lwc1  $f6, 0x630($sp)
/* 0CAE3C 7F09630C C7B40634 */  lwc1  $f20, 0x634($sp)
/* 0CAE40 7F096310 46189102 */  mul.s $f4, $f18, $f24
/* 0CAE44 7F096314 C7A20644 */  lwc1  $f2, 0x644($sp)
/* 0CAE48 7F096318 C7AC064C */  lwc1  $f12, 0x64c($sp)
/* 0CAE4C 7F09631C 46183202 */  mul.s $f8, $f6, $f24
/* 0CAE50 7F096320 C7A60648 */  lwc1  $f6, 0x648($sp)
/* 0CAE54 7F096324 C7B60608 */  lwc1  $f22, 0x608($sp)
/* 0CAE58 7F096328 4618A282 */  mul.s $f10, $f20, $f24
/* 0CAE5C 7F09632C E7A404B4 */  swc1  $f4, 0x4b4($sp)
/* 0CAE60 7F096330 C7AE0614 */  lwc1  $f14, 0x614($sp)
/* 0CAE64 7F096334 46181102 */  mul.s $f4, $f2, $f24
/* 0CAE68 7F096338 E7A804B8 */  swc1  $f8, 0x4b8($sp)
/* 0CAE6C 7F09633C C7B0061C */  lwc1  $f16, 0x61c($sp)
/* 0CAE70 7F096340 46183202 */  mul.s $f8, $f6, $f24
/* 0CAE74 7F096344 E7AA04BC */  swc1  $f10, 0x4bc($sp)
/* 0CAE78 7F096348 C7A6060C */  lwc1  $f6, 0x60c($sp)
/* 0CAE7C 7F09634C 46186282 */  mul.s $f10, $f12, $f24
/* 0CAE80 7F096350 E7A404CC */  swc1  $f4, 0x4cc($sp)
/* 0CAE84 7F096354 3C018004 */  lui   $at, %hi(D_8003FD94)
/* 0CAE88 7F096358 4618B102 */  mul.s $f4, $f22, $f24
/* 0CAE8C 7F09635C E7A804D0 */  swc1  $f8, 0x4d0($sp)
/* 0CAE90 7F096360 C420FD94 */  lwc1  $f0, %lo(D_8003FD94)($at)
/* 0CAE94 7F096364 46183202 */  mul.s $f8, $f6, $f24
/* 0CAE98 7F096368 E7AA04D4 */  swc1  $f10, 0x4d4($sp)
/* 0CAE9C 7F09636C C7AA0610 */  lwc1  $f10, 0x610($sp)
/* 0CAEA0 7F096370 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0CAEA4 7F096374 E7A404E4 */  swc1  $f4, 0x4e4($sp)
/* 0CAEA8 7F096378 46185102 */  mul.s $f4, $f10, $f24
/* 0CAEAC 7F09637C 24110004 */  li    $s1, 4
/* 0CAEB0 7F096380 E7A804E8 */  swc1  $f8, 0x4e8($sp)
/* 0CAEB4 7F096384 46187182 */  mul.s $f6, $f14, $f24
/* 0CAEB8 7F096388 C7A80618 */  lwc1  $f8, 0x618($sp)
/* 0CAEBC 7F09638C 27A404B4 */  addiu $a0, $sp, 0x4b4
/* 0CAEC0 7F096390 8FA50584 */  lw    $a1, 0x584($sp)
/* 0CAEC4 7F096394 46184282 */  mul.s $f10, $f8, $f24
/* 0CAEC8 7F096398 E7A404EC */  swc1  $f4, 0x4ec($sp)
/* 0CAECC 7F09639C 46188102 */  mul.s $f4, $f16, $f24
/* 0CAED0 7F0963A0 E7A604FC */  swc1  $f6, 0x4fc($sp)
/* 0CAED4 7F0963A4 461C9182 */  mul.s $f6, $f18, $f28
/* 0CAED8 7F0963A8 E7AA0500 */  swc1  $f10, 0x500($sp)
/* 0CAEDC 7F0963AC 461CA202 */  mul.s $f8, $f20, $f28
/* 0CAEE0 7F0963B0 E7A40504 */  swc1  $f4, 0x504($sp)
/* 0CAEE4 7F0963B4 461C1102 */  mul.s $f4, $f2, $f28
/* 0CAEE8 7F0963B8 E7A604C0 */  swc1  $f6, 0x4c0($sp)
/* 0CAEEC 7F0963BC 461C6182 */  mul.s $f6, $f12, $f28
/* 0CAEF0 7F0963C0 46004280 */  add.s $f10, $f8, $f0
/* 0CAEF4 7F0963C4 E7A404D8 */  swc1  $f4, 0x4d8($sp)
/* 0CAEF8 7F0963C8 C7A40610 */  lwc1  $f4, 0x610($sp)
/* 0CAEFC 7F0963CC E7AA04C4 */  swc1  $f10, 0x4c4($sp)
/* 0CAF00 7F0963D0 461CB282 */  mul.s $f10, $f22, $f28
/* 0CAF04 7F0963D4 46003200 */  add.s $f8, $f6, $f0
/* 0CAF08 7F0963D8 461C2182 */  mul.s $f6, $f4, $f28
/* 0CAF0C 7F0963DC E7A804DC */  swc1  $f8, 0x4dc($sp)
/* 0CAF10 7F0963E0 E7AA04F0 */  swc1  $f10, 0x4f0($sp)
/* 0CAF14 7F0963E4 461C7282 */  mul.s $f10, $f14, $f28
/* 0CAF18 7F0963E8 46003200 */  add.s $f8, $f6, $f0
/* 0CAF1C 7F0963EC 461C8102 */  mul.s $f4, $f16, $f28
/* 0CAF20 7F0963F0 E7A804F4 */  swc1  $f8, 0x4f4($sp)
/* 0CAF24 7F0963F4 44814000 */  mtc1  $at, $f8
/* 0CAF28 7F0963F8 E7AA0508 */  swc1  $f10, 0x508($sp)
/* 0CAF2C 7F0963FC 46184283 */  div.s $f10, $f8, $f24
/* 0CAF30 7F096400 46002180 */  add.s $f6, $f4, $f0
/* 0CAF34 7F096404 E7A6050C */  swc1  $f6, 0x50c($sp)
/* 0CAF38 7F096408 0FC24F2C */  jal   sub_GAME_7F093CB0
/* 0CAF3C 7F09640C E7AA0058 */   swc1  $f10, 0x58($sp)
/* 0CAF40 7F096410 27A404CC */  addiu $a0, $sp, 0x4cc
/* 0CAF44 7F096414 0FC24F2C */  jal   sub_GAME_7F093CB0
/* 0CAF48 7F096418 8FA5058C */   lw    $a1, 0x58c($sp)
/* 0CAF4C 7F09641C 27A404E4 */  addiu $a0, $sp, 0x4e4
/* 0CAF50 7F096420 0FC24F2C */  jal   sub_GAME_7F093CB0
/* 0CAF54 7F096424 8FA50578 */   lw    $a1, 0x578($sp)
/* 0CAF58 7F096428 27A404FC */  addiu $a0, $sp, 0x4fc
/* 0CAF5C 7F09642C 0FC24F2C */  jal   sub_GAME_7F093CB0
/* 0CAF60 7F096430 8FA5057C */   lw    $a1, 0x57c($sp)
/* 0CAF64 7F096434 1000027D */  b     .L7F096E2C
/* 0CAF68 7F096438 8FAF06B0 */   lw    $t7, 0x6b0($sp)
.L7F09643C:
/* 0CAF6C 7F09643C C7B60620 */  lwc1  $f22, 0x620($sp)
/* 0CAF70 7F096440 C7A60624 */  lwc1  $f6, 0x624($sp)
/* 0CAF74 7F096444 C7A20628 */  lwc1  $f2, 0x628($sp)
/* 0CAF78 7F096448 4618B102 */  mul.s $f4, $f22, $f24
/* 0CAF7C 7F09644C C7AE0608 */  lwc1  $f14, 0x608($sp)
/* 0CAF80 7F096450 C7B20610 */  lwc1  $f18, 0x610($sp)
/* 0CAF84 7F096454 46183202 */  mul.s $f8, $f6, $f24
/* 0CAF88 7F096458 C7A6060C */  lwc1  $f6, 0x60c($sp)
/* 0CAF8C 7F09645C C7B005F0 */  lwc1  $f16, 0x5f0($sp)
/* 0CAF90 7F096460 46181282 */  mul.s $f10, $f2, $f24
/* 0CAF94 7F096464 E7A404B4 */  swc1  $f4, 0x4b4($sp)
/* 0CAF98 7F096468 C7AC05F8 */  lwc1  $f12, 0x5f8($sp)
/* 0CAF9C 7F09646C 46187102 */  mul.s $f4, $f14, $f24
/* 0CAFA0 7F096470 E7A804B8 */  swc1  $f8, 0x4b8($sp)
/* 0CAFA4 7F096474 3C018004 */  lui   $at, %hi(D_8003FD94)
/* 0CAFA8 7F096478 46183202 */  mul.s $f8, $f6, $f24
/* 0CAFAC 7F09647C E7AA04BC */  swc1  $f10, 0x4bc($sp)
/* 0CAFB0 7F096480 C7A605F4 */  lwc1  $f6, 0x5f4($sp)
/* 0CAFB4 7F096484 46189282 */  mul.s $f10, $f18, $f24
/* 0CAFB8 7F096488 E7A404CC */  swc1  $f4, 0x4cc($sp)
/* 0CAFBC 7F09648C C420FD94 */  lwc1  $f0, %lo(D_8003FD94)($at)
/* 0CAFC0 7F096490 46188102 */  mul.s $f4, $f16, $f24
/* 0CAFC4 7F096494 E7A804D0 */  swc1  $f8, 0x4d0($sp)
/* 0CAFC8 7F096498 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0CAFCC 7F09649C 46183202 */  mul.s $f8, $f6, $f24
/* 0CAFD0 7F0964A0 E7AA04D4 */  swc1  $f10, 0x4d4($sp)
/* 0CAFD4 7F0964A4 24110003 */  li    $s1, 3
/* 0CAFD8 7F0964A8 46186282 */  mul.s $f10, $f12, $f24
/* 0CAFDC 7F0964AC E7A404E4 */  swc1  $f4, 0x4e4($sp)
/* 0CAFE0 7F0964B0 27A404B4 */  addiu $a0, $sp, 0x4b4
/* 0CAFE4 7F0964B4 461CB102 */  mul.s $f4, $f22, $f28
/* 0CAFE8 7F0964B8 E7A804E8 */  swc1  $f8, 0x4e8($sp)
/* 0CAFEC 7F0964BC 8FA50580 */  lw    $a1, 0x580($sp)
/* 0CAFF0 7F0964C0 461C1182 */  mul.s $f6, $f2, $f28
/* 0CAFF4 7F0964C4 E7AA04EC */  swc1  $f10, 0x4ec($sp)
/* 0CAFF8 7F0964C8 461C7282 */  mul.s $f10, $f14, $f28
/* 0CAFFC 7F0964CC E7A404C0 */  swc1  $f4, 0x4c0($sp)
/* 0CB000 7F0964D0 461C9102 */  mul.s $f4, $f18, $f28
/* 0CB004 7F0964D4 46003200 */  add.s $f8, $f6, $f0
/* 0CB008 7F0964D8 E7AA04D8 */  swc1  $f10, 0x4d8($sp)
/* 0CB00C 7F0964DC E7A804C4 */  swc1  $f8, 0x4c4($sp)
/* 0CB010 7F0964E0 461C8202 */  mul.s $f8, $f16, $f28
/* 0CB014 7F0964E4 46002180 */  add.s $f6, $f4, $f0
/* 0CB018 7F0964E8 461C6282 */  mul.s $f10, $f12, $f28
/* 0CB01C 7F0964EC E7A604DC */  swc1  $f6, 0x4dc($sp)
/* 0CB020 7F0964F0 44813000 */  mtc1  $at, $f6
/* 0CB024 7F0964F4 E7A804F0 */  swc1  $f8, 0x4f0($sp)
/* 0CB028 7F0964F8 46183203 */  div.s $f8, $f6, $f24
/* 0CB02C 7F0964FC 46005100 */  add.s $f4, $f10, $f0
/* 0CB030 7F096500 E7A404F4 */  swc1  $f4, 0x4f4($sp)
/* 0CB034 7F096504 0FC24F2C */  jal   sub_GAME_7F093CB0
/* 0CB038 7F096508 E7A80058 */   swc1  $f8, 0x58($sp)
/* 0CB03C 7F09650C 27A404CC */  addiu $a0, $sp, 0x4cc
/* 0CB040 7F096510 0FC24F2C */  jal   sub_GAME_7F093CB0
/* 0CB044 7F096514 8FA50578 */   lw    $a1, 0x578($sp)
/* 0CB048 7F096518 27A404E4 */  addiu $a0, $sp, 0x4e4
/* 0CB04C 7F09651C 0FC24F2C */  jal   sub_GAME_7F093CB0
/* 0CB050 7F096520 8FA50570 */   lw    $a1, 0x570($sp)
/* 0CB054 7F096524 10000241 */  b     .L7F096E2C
/* 0CB058 7F096528 8FAF06B0 */   lw    $t7, 0x6b0($sp)
.L7F09652C:
/* 0CB05C 7F09652C C7B2062C */  lwc1  $f18, 0x62c($sp)
/* 0CB060 7F096530 C7A40630 */  lwc1  $f4, 0x630($sp)
/* 0CB064 7F096534 C7B40634 */  lwc1  $f20, 0x634($sp)
/* 0CB068 7F096538 46189282 */  mul.s $f10, $f18, $f24
/* 0CB06C 7F09653C C7AC05FC */  lwc1  $f12, 0x5fc($sp)
/* 0CB070 7F096540 C7AE0604 */  lwc1  $f14, 0x604($sp)
/* 0CB074 7F096544 46182182 */  mul.s $f6, $f4, $f24
/* 0CB078 7F096548 C7A40600 */  lwc1  $f4, 0x600($sp)
/* 0CB07C 7F09654C C7A20608 */  lwc1  $f2, 0x608($sp)
/* 0CB080 7F096550 4618A202 */  mul.s $f8, $f20, $f24
/* 0CB084 7F096554 E7AA04B4 */  swc1  $f10, 0x4b4($sp)
/* 0CB088 7F096558 C7B00610 */  lwc1  $f16, 0x610($sp)
/* 0CB08C 7F09655C 46186282 */  mul.s $f10, $f12, $f24
/* 0CB090 7F096560 E7A604B8 */  swc1  $f6, 0x4b8($sp)
/* 0CB094 7F096564 3C018004 */  lui   $at, %hi(D_8003FD94)
/* 0CB098 7F096568 46182182 */  mul.s $f6, $f4, $f24
/* 0CB09C 7F09656C E7A804BC */  swc1  $f8, 0x4bc($sp)
/* 0CB0A0 7F096570 C7A4060C */  lwc1  $f4, 0x60c($sp)
/* 0CB0A4 7F096574 46187202 */  mul.s $f8, $f14, $f24
/* 0CB0A8 7F096578 E7AA04CC */  swc1  $f10, 0x4cc($sp)
/* 0CB0AC 7F09657C C420FD94 */  lwc1  $f0, %lo(D_8003FD94)($at)
/* 0CB0B0 7F096580 46181282 */  mul.s $f10, $f2, $f24
/* 0CB0B4 7F096584 E7A604D0 */  swc1  $f6, 0x4d0($sp)
/* 0CB0B8 7F096588 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0CB0BC 7F09658C 46182182 */  mul.s $f6, $f4, $f24
/* 0CB0C0 7F096590 E7A804D4 */  swc1  $f8, 0x4d4($sp)
/* 0CB0C4 7F096594 24110003 */  li    $s1, 3
/* 0CB0C8 7F096598 46188202 */  mul.s $f8, $f16, $f24
/* 0CB0CC 7F09659C E7AA04E4 */  swc1  $f10, 0x4e4($sp)
/* 0CB0D0 7F0965A0 27A404B4 */  addiu $a0, $sp, 0x4b4
/* 0CB0D4 7F0965A4 461C9282 */  mul.s $f10, $f18, $f28
/* 0CB0D8 7F0965A8 E7A604E8 */  swc1  $f6, 0x4e8($sp)
/* 0CB0DC 7F0965AC 8FA50584 */  lw    $a1, 0x584($sp)
/* 0CB0E0 7F0965B0 461CA102 */  mul.s $f4, $f20, $f28
/* 0CB0E4 7F0965B4 E7A804EC */  swc1  $f8, 0x4ec($sp)
/* 0CB0E8 7F0965B8 461C6202 */  mul.s $f8, $f12, $f28
/* 0CB0EC 7F0965BC E7AA04C0 */  swc1  $f10, 0x4c0($sp)
/* 0CB0F0 7F0965C0 461C7282 */  mul.s $f10, $f14, $f28
/* 0CB0F4 7F0965C4 46002180 */  add.s $f6, $f4, $f0
/* 0CB0F8 7F0965C8 E7A804D8 */  swc1  $f8, 0x4d8($sp)
/* 0CB0FC 7F0965CC E7A604C4 */  swc1  $f6, 0x4c4($sp)
/* 0CB100 7F0965D0 461C1182 */  mul.s $f6, $f2, $f28
/* 0CB104 7F0965D4 46005100 */  add.s $f4, $f10, $f0
/* 0CB108 7F0965D8 461C8202 */  mul.s $f8, $f16, $f28
/* 0CB10C 7F0965DC E7A404DC */  swc1  $f4, 0x4dc($sp)
/* 0CB110 7F0965E0 44812000 */  mtc1  $at, $f4
/* 0CB114 7F0965E4 E7A604F0 */  swc1  $f6, 0x4f0($sp)
/* 0CB118 7F0965E8 46182183 */  div.s $f6, $f4, $f24
/* 0CB11C 7F0965EC 46004280 */  add.s $f10, $f8, $f0
/* 0CB120 7F0965F0 E7AA04F4 */  swc1  $f10, 0x4f4($sp)
/* 0CB124 7F0965F4 0FC24F2C */  jal   sub_GAME_7F093CB0
/* 0CB128 7F0965F8 E7A60058 */   swc1  $f6, 0x58($sp)
/* 0CB12C 7F0965FC 27A404CC */  addiu $a0, $sp, 0x4cc
/* 0CB130 7F096600 0FC24F2C */  jal   sub_GAME_7F093CB0
/* 0CB134 7F096604 8FA50574 */   lw    $a1, 0x574($sp)
/* 0CB138 7F096608 27A404E4 */  addiu $a0, $sp, 0x4e4
/* 0CB13C 7F09660C 0FC24F2C */  jal   sub_GAME_7F093CB0
/* 0CB140 7F096610 8FA50578 */   lw    $a1, 0x578($sp)
/* 0CB144 7F096614 10000205 */  b     .L7F096E2C
/* 0CB148 7F096618 8FAF06B0 */   lw    $t7, 0x6b0($sp)
.L7F09661C:
/* 0CB14C 7F09661C C7AE0638 */  lwc1  $f14, 0x638($sp)
/* 0CB150 7F096620 C7AA063C */  lwc1  $f10, 0x63c($sp)
/* 0CB154 7F096624 C7B00640 */  lwc1  $f16, 0x640($sp)
/* 0CB158 7F096628 46187202 */  mul.s $f8, $f14, $f24
/* 0CB15C 7F09662C C7A205F0 */  lwc1  $f2, 0x5f0($sp)
/* 0CB160 7F096630 C7AC05F8 */  lwc1  $f12, 0x5f8($sp)
/* 0CB164 7F096634 46185102 */  mul.s $f4, $f10, $f24
/* 0CB168 7F096638 C7AA05F4 */  lwc1  $f10, 0x5f4($sp)
/* 0CB16C 7F09663C C7B40614 */  lwc1  $f20, 0x614($sp)
/* 0CB170 7F096640 46188182 */  mul.s $f6, $f16, $f24
/* 0CB174 7F096644 E7A804B4 */  swc1  $f8, 0x4b4($sp)
/* 0CB178 7F096648 C7B2061C */  lwc1  $f18, 0x61c($sp)
/* 0CB17C 7F09664C 46181202 */  mul.s $f8, $f2, $f24
/* 0CB180 7F096650 E7A404B8 */  swc1  $f4, 0x4b8($sp)
/* 0CB184 7F096654 3C018004 */  lui   $at, %hi(D_8003FD94)
/* 0CB188 7F096658 46185102 */  mul.s $f4, $f10, $f24
/* 0CB18C 7F09665C E7A604BC */  swc1  $f6, 0x4bc($sp)
/* 0CB190 7F096660 C7AA0618 */  lwc1  $f10, 0x618($sp)
/* 0CB194 7F096664 46186182 */  mul.s $f6, $f12, $f24
/* 0CB198 7F096668 E7A804CC */  swc1  $f8, 0x4cc($sp)
/* 0CB19C 7F09666C C420FD94 */  lwc1  $f0, %lo(D_8003FD94)($at)
/* 0CB1A0 7F096670 4618A202 */  mul.s $f8, $f20, $f24
/* 0CB1A4 7F096674 E7A404D0 */  swc1  $f4, 0x4d0($sp)
/* 0CB1A8 7F096678 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0CB1AC 7F09667C 46185102 */  mul.s $f4, $f10, $f24
/* 0CB1B0 7F096680 E7A604D4 */  swc1  $f6, 0x4d4($sp)
/* 0CB1B4 7F096684 24110003 */  li    $s1, 3
/* 0CB1B8 7F096688 46189182 */  mul.s $f6, $f18, $f24
/* 0CB1BC 7F09668C E7A804E4 */  swc1  $f8, 0x4e4($sp)
/* 0CB1C0 7F096690 27A404B4 */  addiu $a0, $sp, 0x4b4
/* 0CB1C4 7F096694 461C7202 */  mul.s $f8, $f14, $f28
/* 0CB1C8 7F096698 E7A404E8 */  swc1  $f4, 0x4e8($sp)
/* 0CB1CC 7F09669C 8FA50588 */  lw    $a1, 0x588($sp)
/* 0CB1D0 7F0966A0 461C8282 */  mul.s $f10, $f16, $f28
/* 0CB1D4 7F0966A4 E7A604EC */  swc1  $f6, 0x4ec($sp)
/* 0CB1D8 7F0966A8 461C1182 */  mul.s $f6, $f2, $f28
/* 0CB1DC 7F0966AC E7A804C0 */  swc1  $f8, 0x4c0($sp)
/* 0CB1E0 7F0966B0 461C6202 */  mul.s $f8, $f12, $f28
/* 0CB1E4 7F0966B4 46005100 */  add.s $f4, $f10, $f0
/* 0CB1E8 7F0966B8 E7A604D8 */  swc1  $f6, 0x4d8($sp)
/* 0CB1EC 7F0966BC E7A404C4 */  swc1  $f4, 0x4c4($sp)
/* 0CB1F0 7F0966C0 461CA102 */  mul.s $f4, $f20, $f28
/* 0CB1F4 7F0966C4 46004280 */  add.s $f10, $f8, $f0
/* 0CB1F8 7F0966C8 461C9182 */  mul.s $f6, $f18, $f28
/* 0CB1FC 7F0966CC E7AA04DC */  swc1  $f10, 0x4dc($sp)
/* 0CB200 7F0966D0 44815000 */  mtc1  $at, $f10
/* 0CB204 7F0966D4 E7A404F0 */  swc1  $f4, 0x4f0($sp)
/* 0CB208 7F0966D8 46185103 */  div.s $f4, $f10, $f24
/* 0CB20C 7F0966DC 46003200 */  add.s $f8, $f6, $f0
/* 0CB210 7F0966E0 E7A804F4 */  swc1  $f8, 0x4f4($sp)
/* 0CB214 7F0966E4 0FC24F2C */  jal   sub_GAME_7F093CB0
/* 0CB218 7F0966E8 E7A40058 */   swc1  $f4, 0x58($sp)
/* 0CB21C 7F0966EC 27A404CC */  addiu $a0, $sp, 0x4cc
/* 0CB220 7F0966F0 0FC24F2C */  jal   sub_GAME_7F093CB0
/* 0CB224 7F0966F4 8FA50570 */   lw    $a1, 0x570($sp)
/* 0CB228 7F0966F8 27A404E4 */  addiu $a0, $sp, 0x4e4
/* 0CB22C 7F0966FC 0FC24F2C */  jal   sub_GAME_7F093CB0
/* 0CB230 7F096700 8FA5057C */   lw    $a1, 0x57c($sp)
/* 0CB234 7F096704 100001C9 */  b     .L7F096E2C
/* 0CB238 7F096708 8FAF06B0 */   lw    $t7, 0x6b0($sp)
.L7F09670C:
/* 0CB23C 7F09670C C7A20644 */  lwc1  $f2, 0x644($sp)
/* 0CB240 7F096710 C7A80648 */  lwc1  $f8, 0x648($sp)
/* 0CB244 7F096714 C7AC064C */  lwc1  $f12, 0x64c($sp)
/* 0CB248 7F096718 46181182 */  mul.s $f6, $f2, $f24
/* 0CB24C 7F09671C C7B20614 */  lwc1  $f18, 0x614($sp)
/* 0CB250 7F096720 C7B4061C */  lwc1  $f20, 0x61c($sp)
/* 0CB254 7F096724 46184282 */  mul.s $f10, $f8, $f24
/* 0CB258 7F096728 C7A80618 */  lwc1  $f8, 0x618($sp)
/* 0CB25C 7F09672C C7AE05FC */  lwc1  $f14, 0x5fc($sp)
/* 0CB260 7F096730 46186102 */  mul.s $f4, $f12, $f24
/* 0CB264 7F096734 E7A604B4 */  swc1  $f6, 0x4b4($sp)
/* 0CB268 7F096738 C7B00604 */  lwc1  $f16, 0x604($sp)
/* 0CB26C 7F09673C 46189182 */  mul.s $f6, $f18, $f24
/* 0CB270 7F096740 E7AA04B8 */  swc1  $f10, 0x4b8($sp)
/* 0CB274 7F096744 3C018004 */  lui   $at, %hi(D_8003FD94)
/* 0CB278 7F096748 46184282 */  mul.s $f10, $f8, $f24
/* 0CB27C 7F09674C E7A404BC */  swc1  $f4, 0x4bc($sp)
/* 0CB280 7F096750 C7A80600 */  lwc1  $f8, 0x600($sp)
/* 0CB284 7F096754 4618A102 */  mul.s $f4, $f20, $f24
/* 0CB288 7F096758 E7A604CC */  swc1  $f6, 0x4cc($sp)
/* 0CB28C 7F09675C C420FD94 */  lwc1  $f0, %lo(D_8003FD94)($at)
/* 0CB290 7F096760 46187182 */  mul.s $f6, $f14, $f24
/* 0CB294 7F096764 E7AA04D0 */  swc1  $f10, 0x4d0($sp)
/* 0CB298 7F096768 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0CB29C 7F09676C 46184282 */  mul.s $f10, $f8, $f24
/* 0CB2A0 7F096770 E7A404D4 */  swc1  $f4, 0x4d4($sp)
/* 0CB2A4 7F096774 24110003 */  li    $s1, 3
/* 0CB2A8 7F096778 46188102 */  mul.s $f4, $f16, $f24
/* 0CB2AC 7F09677C E7A604E4 */  swc1  $f6, 0x4e4($sp)
/* 0CB2B0 7F096780 27A404B4 */  addiu $a0, $sp, 0x4b4
/* 0CB2B4 7F096784 461C1182 */  mul.s $f6, $f2, $f28
/* 0CB2B8 7F096788 E7AA04E8 */  swc1  $f10, 0x4e8($sp)
/* 0CB2BC 7F09678C 8FA5058C */  lw    $a1, 0x58c($sp)
/* 0CB2C0 7F096790 461C6202 */  mul.s $f8, $f12, $f28
/* 0CB2C4 7F096794 E7A404EC */  swc1  $f4, 0x4ec($sp)
/* 0CB2C8 7F096798 461C9102 */  mul.s $f4, $f18, $f28
/* 0CB2CC 7F09679C E7A604C0 */  swc1  $f6, 0x4c0($sp)
/* 0CB2D0 7F0967A0 461CA182 */  mul.s $f6, $f20, $f28
/* 0CB2D4 7F0967A4 46004280 */  add.s $f10, $f8, $f0
/* 0CB2D8 7F0967A8 E7A404D8 */  swc1  $f4, 0x4d8($sp)
/* 0CB2DC 7F0967AC E7AA04C4 */  swc1  $f10, 0x4c4($sp)
/* 0CB2E0 7F0967B0 461C7282 */  mul.s $f10, $f14, $f28
/* 0CB2E4 7F0967B4 46003200 */  add.s $f8, $f6, $f0
/* 0CB2E8 7F0967B8 461C8102 */  mul.s $f4, $f16, $f28
/* 0CB2EC 7F0967BC E7A804DC */  swc1  $f8, 0x4dc($sp)
/* 0CB2F0 7F0967C0 44814000 */  mtc1  $at, $f8
/* 0CB2F4 7F0967C4 E7AA04F0 */  swc1  $f10, 0x4f0($sp)
/* 0CB2F8 7F0967C8 46184283 */  div.s $f10, $f8, $f24
/* 0CB2FC 7F0967CC 46002180 */  add.s $f6, $f4, $f0
/* 0CB300 7F0967D0 E7A604F4 */  swc1  $f6, 0x4f4($sp)
/* 0CB304 7F0967D4 0FC24F2C */  jal   sub_GAME_7F093CB0
/* 0CB308 7F0967D8 E7AA0058 */   swc1  $f10, 0x58($sp)
/* 0CB30C 7F0967DC 27A404CC */  addiu $a0, $sp, 0x4cc
/* 0CB310 7F0967E0 0FC24F2C */  jal   sub_GAME_7F093CB0
/* 0CB314 7F0967E4 8FA5057C */   lw    $a1, 0x57c($sp)
/* 0CB318 7F0967E8 27A404E4 */  addiu $a0, $sp, 0x4e4
/* 0CB31C 7F0967EC 0FC24F2C */  jal   sub_GAME_7F093CB0
/* 0CB320 7F0967F0 8FA50574 */   lw    $a1, 0x574($sp)
/* 0CB324 7F0967F4 1000018D */  b     .L7F096E2C
/* 0CB328 7F0967F8 8FAF06B0 */   lw    $t7, 0x6b0($sp)
.L7F0967FC:
/* 0CB32C 7F0967FC C7B2062C */  lwc1  $f18, 0x62c($sp)
/* 0CB330 7F096800 C7A60630 */  lwc1  $f6, 0x630($sp)
/* 0CB334 7F096804 C7B40634 */  lwc1  $f20, 0x634($sp)
/* 0CB338 7F096808 46189102 */  mul.s $f4, $f18, $f24
/* 0CB33C 7F09680C C7A20644 */  lwc1  $f2, 0x644($sp)
/* 0CB340 7F096810 C7AC064C */  lwc1  $f12, 0x64c($sp)
/* 0CB344 7F096814 46183202 */  mul.s $f8, $f6, $f24
/* 0CB348 7F096818 C7A60648 */  lwc1  $f6, 0x648($sp)
/* 0CB34C 7F09681C C7AE0638 */  lwc1  $f14, 0x638($sp)
/* 0CB350 7F096820 4618A282 */  mul.s $f10, $f20, $f24
/* 0CB354 7F096824 E7A404B4 */  swc1  $f4, 0x4b4($sp)
/* 0CB358 7F096828 C7B00640 */  lwc1  $f16, 0x640($sp)
/* 0CB35C 7F09682C 46181102 */  mul.s $f4, $f2, $f24
/* 0CB360 7F096830 E7A804B8 */  swc1  $f8, 0x4b8($sp)
/* 0CB364 7F096834 C7B605F0 */  lwc1  $f22, 0x5f0($sp)
/* 0CB368 7F096838 46183202 */  mul.s $f8, $f6, $f24
/* 0CB36C 7F09683C E7AA04BC */  swc1  $f10, 0x4bc($sp)
/* 0CB370 7F096840 C7A6063C */  lwc1  $f6, 0x63c($sp)
/* 0CB374 7F096844 46186282 */  mul.s $f10, $f12, $f24
/* 0CB378 7F096848 E7A404CC */  swc1  $f4, 0x4cc($sp)
/* 0CB37C 7F09684C 3C018004 */  lui   $at, %hi(D_8003FD94)
/* 0CB380 7F096850 46187102 */  mul.s $f4, $f14, $f24
/* 0CB384 7F096854 E7A804D0 */  swc1  $f8, 0x4d0($sp)
/* 0CB388 7F096858 C420FD94 */  lwc1  $f0, %lo(D_8003FD94)($at)
/* 0CB38C 7F09685C 46183202 */  mul.s $f8, $f6, $f24
/* 0CB390 7F096860 E7AA04D4 */  swc1  $f10, 0x4d4($sp)
/* 0CB394 7F096864 C7A605F4 */  lwc1  $f6, 0x5f4($sp)
/* 0CB398 7F096868 46188282 */  mul.s $f10, $f16, $f24
/* 0CB39C 7F09686C E7A404E4 */  swc1  $f4, 0x4e4($sp)
/* 0CB3A0 7F096870 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0CB3A4 7F096874 4618B102 */  mul.s $f4, $f22, $f24
/* 0CB3A8 7F096878 E7A804E8 */  swc1  $f8, 0x4e8($sp)
/* 0CB3AC 7F09687C 24110005 */  li    $s1, 5
/* 0CB3B0 7F096880 46183202 */  mul.s $f8, $f6, $f24
/* 0CB3B4 7F096884 E7AA04EC */  swc1  $f10, 0x4ec($sp)
/* 0CB3B8 7F096888 C7AA05F8 */  lwc1  $f10, 0x5f8($sp)
/* 0CB3BC 7F09688C C7A60608 */  lwc1  $f6, 0x608($sp)
/* 0CB3C0 7F096890 E7A404FC */  swc1  $f4, 0x4fc($sp)
/* 0CB3C4 7F096894 46185102 */  mul.s $f4, $f10, $f24
/* 0CB3C8 7F096898 C7AA060C */  lwc1  $f10, 0x60c($sp)
/* 0CB3CC 7F09689C E7A80500 */  swc1  $f8, 0x500($sp)
/* 0CB3D0 7F0968A0 46183202 */  mul.s $f8, $f6, $f24
/* 0CB3D4 7F0968A4 C7A60610 */  lwc1  $f6, 0x610($sp)
/* 0CB3D8 7F0968A8 27A404B4 */  addiu $a0, $sp, 0x4b4
/* 0CB3DC 7F0968AC 8FA50584 */  lw    $a1, 0x584($sp)
/* 0CB3E0 7F0968B0 E7A40504 */  swc1  $f4, 0x504($sp)
/* 0CB3E4 7F0968B4 46185102 */  mul.s $f4, $f10, $f24
/* 0CB3E8 7F0968B8 E7A80514 */  swc1  $f8, 0x514($sp)
/* 0CB3EC 7F0968BC 46183202 */  mul.s $f8, $f6, $f24
/* 0CB3F0 7F0968C0 00000000 */  nop   
/* 0CB3F4 7F0968C4 461C9282 */  mul.s $f10, $f18, $f28
/* 0CB3F8 7F0968C8 E7A40518 */  swc1  $f4, 0x518($sp)
/* 0CB3FC 7F0968CC 461CA102 */  mul.s $f4, $f20, $f28
/* 0CB400 7F0968D0 E7A8051C */  swc1  $f8, 0x51c($sp)
/* 0CB404 7F0968D4 461C1202 */  mul.s $f8, $f2, $f28
/* 0CB408 7F0968D8 E7AA04C0 */  swc1  $f10, 0x4c0($sp)
/* 0CB40C 7F0968DC 461C6282 */  mul.s $f10, $f12, $f28
/* 0CB410 7F0968E0 46002180 */  add.s $f6, $f4, $f0
/* 0CB414 7F0968E4 E7A804D8 */  swc1  $f8, 0x4d8($sp)
/* 0CB418 7F0968E8 E7A604C4 */  swc1  $f6, 0x4c4($sp)
/* 0CB41C 7F0968EC 461C7182 */  mul.s $f6, $f14, $f28
/* 0CB420 7F0968F0 46005100 */  add.s $f4, $f10, $f0
/* 0CB424 7F0968F4 461C8202 */  mul.s $f8, $f16, $f28
/* 0CB428 7F0968F8 E7A404DC */  swc1  $f4, 0x4dc($sp)
/* 0CB42C 7F0968FC 461CB102 */  mul.s $f4, $f22, $f28
/* 0CB430 7F096900 E7A604F0 */  swc1  $f6, 0x4f0($sp)
/* 0CB434 7F096904 C7A605F8 */  lwc1  $f6, 0x5f8($sp)
/* 0CB438 7F096908 46004280 */  add.s $f10, $f8, $f0
/* 0CB43C 7F09690C 461C3202 */  mul.s $f8, $f6, $f28
/* 0CB440 7F096910 E7A40508 */  swc1  $f4, 0x508($sp)
/* 0CB444 7F096914 C7A40608 */  lwc1  $f4, 0x608($sp)
/* 0CB448 7F096918 E7AA04F4 */  swc1  $f10, 0x4f4($sp)
/* 0CB44C 7F09691C 461C2182 */  mul.s $f6, $f4, $f28
/* 0CB450 7F096920 46004280 */  add.s $f10, $f8, $f0
/* 0CB454 7F096924 C7A80610 */  lwc1  $f8, 0x610($sp)
/* 0CB458 7F096928 E7AA050C */  swc1  $f10, 0x50c($sp)
/* 0CB45C 7F09692C E7A60520 */  swc1  $f6, 0x520($sp)
/* 0CB460 7F096930 44813000 */  mtc1  $at, $f6
/* 0CB464 7F096934 461C4282 */  mul.s $f10, $f8, $f28
/* 0CB468 7F096938 46183203 */  div.s $f8, $f6, $f24
/* 0CB46C 7F09693C 46005100 */  add.s $f4, $f10, $f0
/* 0CB470 7F096940 E7A40524 */  swc1  $f4, 0x524($sp)
/* 0CB474 7F096944 0FC24F2C */  jal   sub_GAME_7F093CB0
/* 0CB478 7F096948 E7A80058 */   swc1  $f8, 0x58($sp)
/* 0CB47C 7F09694C 27A404CC */  addiu $a0, $sp, 0x4cc
/* 0CB480 7F096950 0FC24F2C */  jal   sub_GAME_7F093CB0
/* 0CB484 7F096954 8FA5058C */   lw    $a1, 0x58c($sp)
/* 0CB488 7F096958 27A404E4 */  addiu $a0, $sp, 0x4e4
/* 0CB48C 7F09695C 0FC24F2C */  jal   sub_GAME_7F093CB0
/* 0CB490 7F096960 8FA50588 */   lw    $a1, 0x588($sp)
/* 0CB494 7F096964 27A404FC */  addiu $a0, $sp, 0x4fc
/* 0CB498 7F096968 0FC24F2C */  jal   sub_GAME_7F093CB0
/* 0CB49C 7F09696C 8FA50570 */   lw    $a1, 0x570($sp)
/* 0CB4A0 7F096970 27A40514 */  addiu $a0, $sp, 0x514
/* 0CB4A4 7F096974 0FC24F2C */  jal   sub_GAME_7F093CB0
/* 0CB4A8 7F096978 8FA50578 */   lw    $a1, 0x578($sp)
/* 0CB4AC 7F09697C 1000012B */  b     .L7F096E2C
/* 0CB4B0 7F096980 8FAF06B0 */   lw    $t7, 0x6b0($sp)
.L7F096984:
/* 0CB4B4 7F096984 C7A20644 */  lwc1  $f2, 0x644($sp)
/* 0CB4B8 7F096988 C7A40648 */  lwc1  $f4, 0x648($sp)
/* 0CB4BC 7F09698C C7AC064C */  lwc1  $f12, 0x64c($sp)
/* 0CB4C0 7F096990 46181282 */  mul.s $f10, $f2, $f24
/* 0CB4C4 7F096994 C7AE0638 */  lwc1  $f14, 0x638($sp)
/* 0CB4C8 7F096998 C7B00640 */  lwc1  $f16, 0x640($sp)
/* 0CB4CC 7F09699C 46182182 */  mul.s $f6, $f4, $f24
/* 0CB4D0 7F0969A0 C7A4063C */  lwc1  $f4, 0x63c($sp)
/* 0CB4D4 7F0969A4 C7B60620 */  lwc1  $f22, 0x620($sp)
/* 0CB4D8 7F0969A8 46186202 */  mul.s $f8, $f12, $f24
/* 0CB4DC 7F0969AC E7AA04B4 */  swc1  $f10, 0x4b4($sp)
/* 0CB4E0 7F0969B0 C7B205FC */  lwc1  $f18, 0x5fc($sp)
/* 0CB4E4 7F0969B4 46187282 */  mul.s $f10, $f14, $f24
/* 0CB4E8 7F0969B8 E7A604B8 */  swc1  $f6, 0x4b8($sp)
/* 0CB4EC 7F0969BC C7B40604 */  lwc1  $f20, 0x604($sp)
/* 0CB4F0 7F0969C0 46182182 */  mul.s $f6, $f4, $f24
/* 0CB4F4 7F0969C4 E7A804BC */  swc1  $f8, 0x4bc($sp)
/* 0CB4F8 7F0969C8 C7A40624 */  lwc1  $f4, 0x624($sp)
/* 0CB4FC 7F0969CC 46188202 */  mul.s $f8, $f16, $f24
/* 0CB500 7F0969D0 E7AA04CC */  swc1  $f10, 0x4cc($sp)
/* 0CB504 7F0969D4 3C018004 */  lui   $at, %hi(D_8003FD94)
/* 0CB508 7F0969D8 4618B282 */  mul.s $f10, $f22, $f24
/* 0CB50C 7F0969DC E7A604D0 */  swc1  $f6, 0x4d0($sp)
/* 0CB510 7F0969E0 C420FD94 */  lwc1  $f0, %lo(D_8003FD94)($at)
/* 0CB514 7F0969E4 46182182 */  mul.s $f6, $f4, $f24
/* 0CB518 7F0969E8 E7A804D4 */  swc1  $f8, 0x4d4($sp)
/* 0CB51C 7F0969EC C7A80628 */  lwc1  $f8, 0x628($sp)
/* 0CB520 7F0969F0 C7A40608 */  lwc1  $f4, 0x608($sp)
/* 0CB524 7F0969F4 E7AA04E4 */  swc1  $f10, 0x4e4($sp)
/* 0CB528 7F0969F8 46184282 */  mul.s $f10, $f8, $f24
/* 0CB52C 7F0969FC C7A8060C */  lwc1  $f8, 0x60c($sp)
/* 0CB530 7F096A00 E7A604E8 */  swc1  $f6, 0x4e8($sp)
/* 0CB534 7F096A04 46182182 */  mul.s $f6, $f4, $f24
/* 0CB538 7F096A08 C7A40610 */  lwc1  $f4, 0x610($sp)
/* 0CB53C 7F096A0C 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0CB540 7F096A10 24110005 */  li    $s1, 5
/* 0CB544 7F096A14 E7AA04EC */  swc1  $f10, 0x4ec($sp)
/* 0CB548 7F096A18 46184282 */  mul.s $f10, $f8, $f24
/* 0CB54C 7F096A1C 27A404B4 */  addiu $a0, $sp, 0x4b4
/* 0CB550 7F096A20 E7A604FC */  swc1  $f6, 0x4fc($sp)
/* 0CB554 7F096A24 46182182 */  mul.s $f6, $f4, $f24
/* 0CB558 7F096A28 8FA5058C */  lw    $a1, 0x58c($sp)
/* 0CB55C 7F096A2C 46189202 */  mul.s $f8, $f18, $f24
/* 0CB560 7F096A30 E7AA0500 */  swc1  $f10, 0x500($sp)
/* 0CB564 7F096A34 C7AA0600 */  lwc1  $f10, 0x600($sp)
/* 0CB568 7F096A38 E7A60504 */  swc1  $f6, 0x504($sp)
/* 0CB56C 7F096A3C 46185102 */  mul.s $f4, $f10, $f24
/* 0CB570 7F096A40 E7A80514 */  swc1  $f8, 0x514($sp)
/* 0CB574 7F096A44 4618A182 */  mul.s $f6, $f20, $f24
/* 0CB578 7F096A48 00000000 */  nop   
/* 0CB57C 7F096A4C 461C1202 */  mul.s $f8, $f2, $f28
/* 0CB580 7F096A50 E7A40518 */  swc1  $f4, 0x518($sp)
/* 0CB584 7F096A54 461C6282 */  mul.s $f10, $f12, $f28
/* 0CB588 7F096A58 E7A6051C */  swc1  $f6, 0x51c($sp)
/* 0CB58C 7F096A5C 461C7182 */  mul.s $f6, $f14, $f28
/* 0CB590 7F096A60 E7A804C0 */  swc1  $f8, 0x4c0($sp)
/* 0CB594 7F096A64 461C8202 */  mul.s $f8, $f16, $f28
/* 0CB598 7F096A68 46005100 */  add.s $f4, $f10, $f0
/* 0CB59C 7F096A6C E7A604D8 */  swc1  $f6, 0x4d8($sp)
/* 0CB5A0 7F096A70 C7A60628 */  lwc1  $f6, 0x628($sp)
/* 0CB5A4 7F096A74 E7A404C4 */  swc1  $f4, 0x4c4($sp)
/* 0CB5A8 7F096A78 461CB102 */  mul.s $f4, $f22, $f28
/* 0CB5AC 7F096A7C 46004280 */  add.s $f10, $f8, $f0
/* 0CB5B0 7F096A80 461C3202 */  mul.s $f8, $f6, $f28
/* 0CB5B4 7F096A84 E7AA04DC */  swc1  $f10, 0x4dc($sp)
/* 0CB5B8 7F096A88 E7A404F0 */  swc1  $f4, 0x4f0($sp)
/* 0CB5BC 7F096A8C C7A40608 */  lwc1  $f4, 0x608($sp)
/* 0CB5C0 7F096A90 46004280 */  add.s $f10, $f8, $f0
/* 0CB5C4 7F096A94 461C2182 */  mul.s $f6, $f4, $f28
/* 0CB5C8 7F096A98 C7A80610 */  lwc1  $f8, 0x610($sp)
/* 0CB5CC 7F096A9C E7AA04F4 */  swc1  $f10, 0x4f4($sp)
/* 0CB5D0 7F096AA0 461C4282 */  mul.s $f10, $f8, $f28
/* 0CB5D4 7F096AA4 E7A60508 */  swc1  $f6, 0x508($sp)
/* 0CB5D8 7F096AA8 461C9182 */  mul.s $f6, $f18, $f28
/* 0CB5DC 7F096AAC 46005100 */  add.s $f4, $f10, $f0
/* 0CB5E0 7F096AB0 461CA202 */  mul.s $f8, $f20, $f28
/* 0CB5E4 7F096AB4 E7A60520 */  swc1  $f6, 0x520($sp)
/* 0CB5E8 7F096AB8 E7A4050C */  swc1  $f4, 0x50c($sp)
/* 0CB5EC 7F096ABC 44812000 */  mtc1  $at, $f4
/* 0CB5F0 7F096AC0 00000000 */  nop   
/* 0CB5F4 7F096AC4 46182183 */  div.s $f6, $f4, $f24
/* 0CB5F8 7F096AC8 46004280 */  add.s $f10, $f8, $f0
/* 0CB5FC 7F096ACC E7AA0524 */  swc1  $f10, 0x524($sp)
/* 0CB600 7F096AD0 0FC24F2C */  jal   sub_GAME_7F093CB0
/* 0CB604 7F096AD4 E7A60058 */   swc1  $f6, 0x58($sp)
/* 0CB608 7F096AD8 27A404CC */  addiu $a0, $sp, 0x4cc
/* 0CB60C 7F096ADC 0FC24F2C */  jal   sub_GAME_7F093CB0
/* 0CB610 7F096AE0 8FA50588 */   lw    $a1, 0x588($sp)
/* 0CB614 7F096AE4 27A404E4 */  addiu $a0, $sp, 0x4e4
/* 0CB618 7F096AE8 0FC24F2C */  jal   sub_GAME_7F093CB0
/* 0CB61C 7F096AEC 8FA50580 */   lw    $a1, 0x580($sp)
/* 0CB620 7F096AF0 27A404FC */  addiu $a0, $sp, 0x4fc
/* 0CB624 7F096AF4 0FC24F2C */  jal   sub_GAME_7F093CB0
/* 0CB628 7F096AF8 8FA50578 */   lw    $a1, 0x578($sp)
/* 0CB62C 7F096AFC 27A40514 */  addiu $a0, $sp, 0x514
/* 0CB630 7F096B00 0FC24F2C */  jal   sub_GAME_7F093CB0
/* 0CB634 7F096B04 8FA50574 */   lw    $a1, 0x574($sp)
/* 0CB638 7F096B08 100000C8 */  b     .L7F096E2C
/* 0CB63C 7F096B0C 8FAF06B0 */   lw    $t7, 0x6b0($sp)
.L7F096B10:
/* 0CB640 7F096B10 C7B60620 */  lwc1  $f22, 0x620($sp)
/* 0CB644 7F096B14 C7AA0624 */  lwc1  $f10, 0x624($sp)
/* 0CB648 7F096B18 C7A60628 */  lwc1  $f6, 0x628($sp)
/* 0CB64C 7F096B1C 4618B202 */  mul.s $f8, $f22, $f24
/* 0CB650 7F096B20 C7B2062C */  lwc1  $f18, 0x62c($sp)
/* 0CB654 7F096B24 C7B40634 */  lwc1  $f20, 0x634($sp)
/* 0CB658 7F096B28 46185102 */  mul.s $f4, $f10, $f24
/* 0CB65C 7F096B2C C7A20644 */  lwc1  $f2, 0x644($sp)
/* 0CB660 7F096B30 C7AC064C */  lwc1  $f12, 0x64c($sp)
/* 0CB664 7F096B34 C7AE0614 */  lwc1  $f14, 0x614($sp)
/* 0CB668 7F096B38 E7A804B4 */  swc1  $f8, 0x4b4($sp)
/* 0CB66C 7F096B3C 46183202 */  mul.s $f8, $f6, $f24
/* 0CB670 7F096B40 C7B0061C */  lwc1  $f16, 0x61c($sp)
/* 0CB674 7F096B44 E7A404B8 */  swc1  $f4, 0x4b8($sp)
/* 0CB678 7F096B48 46189282 */  mul.s $f10, $f18, $f24
/* 0CB67C 7F096B4C C7A40630 */  lwc1  $f4, 0x630($sp)
/* 0CB680 7F096B50 3C018004 */  lui   $at, %hi(D_8003FD94)
/* 0CB684 7F096B54 C420FD94 */  lwc1  $f0, %lo(D_8003FD94)($at)
/* 0CB688 7F096B58 E7A804BC */  swc1  $f8, 0x4bc($sp)
/* 0CB68C 7F096B5C 46182202 */  mul.s $f8, $f4, $f24
/* 0CB690 7F096B60 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0CB694 7F096B64 E7AA04CC */  swc1  $f10, 0x4cc($sp)
/* 0CB698 7F096B68 4618A282 */  mul.s $f10, $f20, $f24
/* 0CB69C 7F096B6C 24110005 */  li    $s1, 5
/* 0CB6A0 7F096B70 27A404B4 */  addiu $a0, $sp, 0x4b4
/* 0CB6A4 7F096B74 46181102 */  mul.s $f4, $f2, $f24
/* 0CB6A8 7F096B78 E7A804D0 */  swc1  $f8, 0x4d0($sp)
/* 0CB6AC 7F096B7C C7A80648 */  lwc1  $f8, 0x648($sp)
/* 0CB6B0 7F096B80 8FA50580 */  lw    $a1, 0x580($sp)
/* 0CB6B4 7F096B84 E7AA04D4 */  swc1  $f10, 0x4d4($sp)
/* 0CB6B8 7F096B88 46184282 */  mul.s $f10, $f8, $f24
/* 0CB6BC 7F096B8C E7A404E4 */  swc1  $f4, 0x4e4($sp)
/* 0CB6C0 7F096B90 46186102 */  mul.s $f4, $f12, $f24
/* 0CB6C4 7F096B94 E7AA04E8 */  swc1  $f10, 0x4e8($sp)
/* 0CB6C8 7F096B98 46187202 */  mul.s $f8, $f14, $f24
/* 0CB6CC 7F096B9C C7AA0618 */  lwc1  $f10, 0x618($sp)
/* 0CB6D0 7F096BA0 E7A404EC */  swc1  $f4, 0x4ec($sp)
/* 0CB6D4 7F096BA4 46185102 */  mul.s $f4, $f10, $f24
/* 0CB6D8 7F096BA8 C7AA05F0 */  lwc1  $f10, 0x5f0($sp)
/* 0CB6DC 7F096BAC E7A804FC */  swc1  $f8, 0x4fc($sp)
/* 0CB6E0 7F096BB0 46188202 */  mul.s $f8, $f16, $f24
/* 0CB6E4 7F096BB4 E7A40500 */  swc1  $f4, 0x500($sp)
/* 0CB6E8 7F096BB8 46185102 */  mul.s $f4, $f10, $f24
/* 0CB6EC 7F096BBC E7A80504 */  swc1  $f8, 0x504($sp)
/* 0CB6F0 7F096BC0 C7A805F4 */  lwc1  $f8, 0x5f4($sp)
/* 0CB6F4 7F096BC4 46184282 */  mul.s $f10, $f8, $f24
/* 0CB6F8 7F096BC8 E7A40514 */  swc1  $f4, 0x514($sp)
/* 0CB6FC 7F096BCC C7A405F8 */  lwc1  $f4, 0x5f8($sp)
/* 0CB700 7F096BD0 46182202 */  mul.s $f8, $f4, $f24
/* 0CB704 7F096BD4 E7AA0518 */  swc1  $f10, 0x518($sp)
/* 0CB708 7F096BD8 461CB282 */  mul.s $f10, $f22, $f28
/* 0CB70C 7F096BDC 00000000 */  nop   
/* 0CB710 7F096BE0 461C3102 */  mul.s $f4, $f6, $f28
/* 0CB714 7F096BE4 E7A8051C */  swc1  $f8, 0x51c($sp)
/* 0CB718 7F096BE8 E7AA04C0 */  swc1  $f10, 0x4c0($sp)
/* 0CB71C 7F096BEC 461C9282 */  mul.s $f10, $f18, $f28
/* 0CB720 7F096BF0 46002200 */  add.s $f8, $f4, $f0
/* 0CB724 7F096BF4 461CA182 */  mul.s $f6, $f20, $f28
/* 0CB728 7F096BF8 E7A804C4 */  swc1  $f8, 0x4c4($sp)
/* 0CB72C 7F096BFC 461C1202 */  mul.s $f8, $f2, $f28
/* 0CB730 7F096C00 E7AA04D8 */  swc1  $f10, 0x4d8($sp)
/* 0CB734 7F096C04 461C6282 */  mul.s $f10, $f12, $f28
/* 0CB738 7F096C08 46003100 */  add.s $f4, $f6, $f0
/* 0CB73C 7F096C0C E7A804F0 */  swc1  $f8, 0x4f0($sp)
/* 0CB740 7F096C10 E7A404DC */  swc1  $f4, 0x4dc($sp)
/* 0CB744 7F096C14 461C7102 */  mul.s $f4, $f14, $f28
/* 0CB748 7F096C18 46005180 */  add.s $f6, $f10, $f0
/* 0CB74C 7F096C1C 461C8202 */  mul.s $f8, $f16, $f28
/* 0CB750 7F096C20 E7A604F4 */  swc1  $f6, 0x4f4($sp)
/* 0CB754 7F096C24 C7A605F0 */  lwc1  $f6, 0x5f0($sp)
/* 0CB758 7F096C28 E7A40508 */  swc1  $f4, 0x508($sp)
/* 0CB75C 7F096C2C 461C3102 */  mul.s $f4, $f6, $f28
/* 0CB760 7F096C30 46004280 */  add.s $f10, $f8, $f0
/* 0CB764 7F096C34 C7A805F8 */  lwc1  $f8, 0x5f8($sp)
/* 0CB768 7F096C38 E7AA050C */  swc1  $f10, 0x50c($sp)
/* 0CB76C 7F096C3C 461C4282 */  mul.s $f10, $f8, $f28
/* 0CB770 7F096C40 E7A40520 */  swc1  $f4, 0x520($sp)
/* 0CB774 7F096C44 44812000 */  mtc1  $at, $f4
/* 0CB778 7F096C48 00000000 */  nop   
/* 0CB77C 7F096C4C 46182203 */  div.s $f8, $f4, $f24
/* 0CB780 7F096C50 46005180 */  add.s $f6, $f10, $f0
/* 0CB784 7F096C54 E7A60524 */  swc1  $f6, 0x524($sp)
/* 0CB788 7F096C58 0FC24F2C */  jal   sub_GAME_7F093CB0
/* 0CB78C 7F096C5C E7A80058 */   swc1  $f8, 0x58($sp)
/* 0CB790 7F096C60 27A404CC */  addiu $a0, $sp, 0x4cc
/* 0CB794 7F096C64 0FC24F2C */  jal   sub_GAME_7F093CB0
/* 0CB798 7F096C68 8FA50584 */   lw    $a1, 0x584($sp)
/* 0CB79C 7F096C6C 27A404E4 */  addiu $a0, $sp, 0x4e4
/* 0CB7A0 7F096C70 0FC24F2C */  jal   sub_GAME_7F093CB0
/* 0CB7A4 7F096C74 8FA5058C */   lw    $a1, 0x58c($sp)
/* 0CB7A8 7F096C78 27A404FC */  addiu $a0, $sp, 0x4fc
/* 0CB7AC 7F096C7C 0FC24F2C */  jal   sub_GAME_7F093CB0
/* 0CB7B0 7F096C80 8FA5057C */   lw    $a1, 0x57c($sp)
/* 0CB7B4 7F096C84 27A40514 */  addiu $a0, $sp, 0x514
/* 0CB7B8 7F096C88 0FC24F2C */  jal   sub_GAME_7F093CB0
/* 0CB7BC 7F096C8C 8FA50570 */   lw    $a1, 0x570($sp)
/* 0CB7C0 7F096C90 10000066 */  b     .L7F096E2C
/* 0CB7C4 7F096C94 8FAF06B0 */   lw    $t7, 0x6b0($sp)
.L7F096C98:
/* 0CB7C8 7F096C98 C7AE0638 */  lwc1  $f14, 0x638($sp)
/* 0CB7CC 7F096C9C C7A6063C */  lwc1  $f6, 0x63c($sp)
/* 0CB7D0 7F096CA0 C7B00640 */  lwc1  $f16, 0x640($sp)
/* 0CB7D4 7F096CA4 46187282 */  mul.s $f10, $f14, $f24
/* 0CB7D8 7F096CA8 C7B60620 */  lwc1  $f22, 0x620($sp)
/* 0CB7DC 7F096CAC C7A20628 */  lwc1  $f2, 0x628($sp)
/* 0CB7E0 7F096CB0 46183102 */  mul.s $f4, $f6, $f24
/* 0CB7E4 7F096CB4 C7A60624 */  lwc1  $f6, 0x624($sp)
/* 0CB7E8 7F096CB8 C7B2062C */  lwc1  $f18, 0x62c($sp)
/* 0CB7EC 7F096CBC 46188202 */  mul.s $f8, $f16, $f24
/* 0CB7F0 7F096CC0 E7AA04B4 */  swc1  $f10, 0x4b4($sp)
/* 0CB7F4 7F096CC4 C7B40634 */  lwc1  $f20, 0x634($sp)
/* 0CB7F8 7F096CC8 4618B282 */  mul.s $f10, $f22, $f24
/* 0CB7FC 7F096CCC E7A404B8 */  swc1  $f4, 0x4b8($sp)
/* 0CB800 7F096CD0 C7AC05FC */  lwc1  $f12, 0x5fc($sp)
/* 0CB804 7F096CD4 46183102 */  mul.s $f4, $f6, $f24
/* 0CB808 7F096CD8 E7A804BC */  swc1  $f8, 0x4bc($sp)
/* 0CB80C 7F096CDC C7A60630 */  lwc1  $f6, 0x630($sp)
/* 0CB810 7F096CE0 46181202 */  mul.s $f8, $f2, $f24
/* 0CB814 7F096CE4 E7AA04CC */  swc1  $f10, 0x4cc($sp)
/* 0CB818 7F096CE8 3C018004 */  lui   $at, %hi(D_8003FD94)
/* 0CB81C 7F096CEC 46189282 */  mul.s $f10, $f18, $f24
/* 0CB820 7F096CF0 E7A404D0 */  swc1  $f4, 0x4d0($sp)
/* 0CB824 7F096CF4 C420FD94 */  lwc1  $f0, %lo(D_8003FD94)($at)
/* 0CB828 7F096CF8 46183102 */  mul.s $f4, $f6, $f24
/* 0CB82C 7F096CFC E7A804D4 */  swc1  $f8, 0x4d4($sp)
/* 0CB830 7F096D00 C7A60600 */  lwc1  $f6, 0x600($sp)
/* 0CB834 7F096D04 4618A202 */  mul.s $f8, $f20, $f24
/* 0CB838 7F096D08 E7AA04E4 */  swc1  $f10, 0x4e4($sp)
/* 0CB83C 7F096D0C 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0CB840 7F096D10 46186282 */  mul.s $f10, $f12, $f24
/* 0CB844 7F096D14 E7A404E8 */  swc1  $f4, 0x4e8($sp)
/* 0CB848 7F096D18 24110005 */  li    $s1, 5
/* 0CB84C 7F096D1C 46183102 */  mul.s $f4, $f6, $f24
/* 0CB850 7F096D20 E7A804EC */  swc1  $f8, 0x4ec($sp)
/* 0CB854 7F096D24 C7A80604 */  lwc1  $f8, 0x604($sp)
/* 0CB858 7F096D28 C7A60614 */  lwc1  $f6, 0x614($sp)
/* 0CB85C 7F096D2C E7AA04FC */  swc1  $f10, 0x4fc($sp)
/* 0CB860 7F096D30 46184282 */  mul.s $f10, $f8, $f24
/* 0CB864 7F096D34 C7A80618 */  lwc1  $f8, 0x618($sp)
/* 0CB868 7F096D38 E7A40500 */  swc1  $f4, 0x500($sp)
/* 0CB86C 7F096D3C 46183102 */  mul.s $f4, $f6, $f24
/* 0CB870 7F096D40 C7A6061C */  lwc1  $f6, 0x61c($sp)
/* 0CB874 7F096D44 27A404B4 */  addiu $a0, $sp, 0x4b4
/* 0CB878 7F096D48 8FA50588 */  lw    $a1, 0x588($sp)
/* 0CB87C 7F096D4C E7AA0504 */  swc1  $f10, 0x504($sp)
/* 0CB880 7F096D50 46184282 */  mul.s $f10, $f8, $f24
/* 0CB884 7F096D54 E7A40514 */  swc1  $f4, 0x514($sp)
/* 0CB888 7F096D58 46183102 */  mul.s $f4, $f6, $f24
/* 0CB88C 7F096D5C 00000000 */  nop   
/* 0CB890 7F096D60 461C7202 */  mul.s $f8, $f14, $f28
/* 0CB894 7F096D64 E7AA0518 */  swc1  $f10, 0x518($sp)
/* 0CB898 7F096D68 461C8282 */  mul.s $f10, $f16, $f28
/* 0CB89C 7F096D6C E7A4051C */  swc1  $f4, 0x51c($sp)
/* 0CB8A0 7F096D70 461CB102 */  mul.s $f4, $f22, $f28
/* 0CB8A4 7F096D74 E7A804C0 */  swc1  $f8, 0x4c0($sp)
/* 0CB8A8 7F096D78 461C1202 */  mul.s $f8, $f2, $f28
/* 0CB8AC 7F096D7C 46005180 */  add.s $f6, $f10, $f0
/* 0CB8B0 7F096D80 E7A404D8 */  swc1  $f4, 0x4d8($sp)
/* 0CB8B4 7F096D84 E7A604C4 */  swc1  $f6, 0x4c4($sp)
/* 0CB8B8 7F096D88 461C9182 */  mul.s $f6, $f18, $f28
/* 0CB8BC 7F096D8C 46004280 */  add.s $f10, $f8, $f0
/* 0CB8C0 7F096D90 461CA102 */  mul.s $f4, $f20, $f28
/* 0CB8C4 7F096D94 E7AA04DC */  swc1  $f10, 0x4dc($sp)
/* 0CB8C8 7F096D98 461C6282 */  mul.s $f10, $f12, $f28
/* 0CB8CC 7F096D9C E7A604F0 */  swc1  $f6, 0x4f0($sp)
/* 0CB8D0 7F096DA0 C7A60604 */  lwc1  $f6, 0x604($sp)
/* 0CB8D4 7F096DA4 46002200 */  add.s $f8, $f4, $f0
/* 0CB8D8 7F096DA8 461C3102 */  mul.s $f4, $f6, $f28
/* 0CB8DC 7F096DAC E7AA0508 */  swc1  $f10, 0x508($sp)
/* 0CB8E0 7F096DB0 C7AA0614 */  lwc1  $f10, 0x614($sp)
/* 0CB8E4 7F096DB4 E7A804F4 */  swc1  $f8, 0x4f4($sp)
/* 0CB8E8 7F096DB8 461C5182 */  mul.s $f6, $f10, $f28
/* 0CB8EC 7F096DBC 46002200 */  add.s $f8, $f4, $f0
/* 0CB8F0 7F096DC0 C7A4061C */  lwc1  $f4, 0x61c($sp)
/* 0CB8F4 7F096DC4 E7A8050C */  swc1  $f8, 0x50c($sp)
/* 0CB8F8 7F096DC8 E7A60520 */  swc1  $f6, 0x520($sp)
/* 0CB8FC 7F096DCC 44813000 */  mtc1  $at, $f6
/* 0CB900 7F096DD0 461C2202 */  mul.s $f8, $f4, $f28
/* 0CB904 7F096DD4 46183103 */  div.s $f4, $f6, $f24
/* 0CB908 7F096DD8 46004280 */  add.s $f10, $f8, $f0
/* 0CB90C 7F096DDC E7AA0524 */  swc1  $f10, 0x524($sp)
/* 0CB910 7F096DE0 0FC24F2C */  jal   sub_GAME_7F093CB0
/* 0CB914 7F096DE4 E7A40058 */   swc1  $f4, 0x58($sp)
/* 0CB918 7F096DE8 27A404CC */  addiu $a0, $sp, 0x4cc
/* 0CB91C 7F096DEC 0FC24F2C */  jal   sub_GAME_7F093CB0
/* 0CB920 7F096DF0 8FA50580 */   lw    $a1, 0x580($sp)
/* 0CB924 7F096DF4 27A404E4 */  addiu $a0, $sp, 0x4e4
/* 0CB928 7F096DF8 0FC24F2C */  jal   sub_GAME_7F093CB0
/* 0CB92C 7F096DFC 8FA50584 */   lw    $a1, 0x584($sp)
/* 0CB930 7F096E00 27A404FC */  addiu $a0, $sp, 0x4fc
/* 0CB934 7F096E04 0FC24F2C */  jal   sub_GAME_7F093CB0
/* 0CB938 7F096E08 8FA50574 */   lw    $a1, 0x574($sp)
/* 0CB93C 7F096E0C 27A40514 */  addiu $a0, $sp, 0x514
/* 0CB940 7F096E10 0FC24F2C */  jal   sub_GAME_7F093CB0
/* 0CB944 7F096E14 8FA5057C */   lw    $a1, 0x57c($sp)
/* 0CB948 7F096E18 10000004 */  b     .L7F096E2C
/* 0CB94C 7F096E1C 8FAF06B0 */   lw    $t7, 0x6b0($sp)
def_7F095E0C:
.L7F096E20:
/* 0CB950 7F096E20 1000014F */  b     .L7F097360
/* 0CB954 7F096E24 00601025 */   move  $v0, $v1
/* 0CB958 7F096E28 8FAF06B0 */  lw    $t7, 0x6b0($sp)
.L7F096E2C:
/* 0CB95C 7F096E2C 3C0CE700 */  lui   $t4, 0xe700
/* 0CB960 7F096E30 25ED0008 */  addiu $t5, $t7, 8
/* 0CB964 7F096E34 AFAD06B0 */  sw    $t5, 0x6b0($sp)
/* 0CB968 7F096E38 ADE00004 */  sw    $zero, 4($t7)
/* 0CB96C 7F096E3C 0FC2E9CB */  jal   get_ptr_currentdata
/* 0CB970 7F096E40 ADEC0000 */   sw    $t4, ($t7)
/* 0CB974 7F096E44 84590010 */  lh    $t9, 0x10($v0)
/* 0CB978 7F096E48 3C0B8009 */  lui   $t3, %hi(skywaterimages) 
/* 0CB97C 7F096E4C 8D6BD124 */  lw    $t3, %lo(skywaterimages)($t3)
/* 0CB980 7F096E50 0019C080 */  sll   $t8, $t9, 2
/* 0CB984 7F096E54 0319C023 */  subu  $t8, $t8, $t9
/* 0CB988 7F096E58 0018C080 */  sll   $t8, $t8, 2
/* 0CB98C 7F096E5C 240E0002 */  li    $t6, 2
/* 0CB990 7F096E60 AFAE0010 */  sw    $t6, 0x10($sp)
/* 0CB994 7F096E64 27A406B0 */  addiu $a0, $sp, 0x6b0
/* 0CB998 7F096E68 24060001 */  li    $a2, 1
/* 0CB99C 7F096E6C 00003825 */  move  $a3, $zero
/* 0CB9A0 7F096E70 0FC1DB5A */  jal   likely_generate_DL_for_image_declaration
/* 0CB9A4 7F096E74 030B2821 */   addu  $a1, $t8, $t3
/* 0CB9A8 7F096E78 8FAA06B0 */  lw    $t2, 0x6b0($sp)
/* 0CB9AC 7F096E7C 3C0DFB00 */  lui   $t5, 0xfb00
/* 0CB9B0 7F096E80 254F0008 */  addiu $t7, $t2, 8
/* 0CB9B4 7F096E84 AFAF06B0 */  sw    $t7, 0x6b0($sp)
/* 0CB9B8 7F096E88 AD4D0000 */  sw    $t5, ($t2)
/* 0CB9BC 7F096E8C 0FC2E9CB */  jal   get_ptr_currentdata
/* 0CB9C0 7F096E90 AFAA0228 */   sw    $t2, 0x228($sp)
/* 0CB9C4 7F096E94 0FC2E9CB */  jal   get_ptr_currentdata
/* 0CB9C8 7F096E98 00408025 */   move  $s0, $v0
/* 0CB9CC 7F096E9C 0FC2E9CB */  jal   get_ptr_currentdata
/* 0CB9D0 7F096EA0 AFA2006C */   sw    $v0, 0x6c($sp)
/* 0CB9D4 7F096EA4 8FAB006C */  lw    $t3, 0x6c($sp)
/* 0CB9D8 7F096EA8 9059000A */  lbu   $t9, 0xa($v0)
/* 0CB9DC 7F096EAC 916A0008 */  lbu   $t2, 8($t3)
/* 0CB9E0 7F096EB0 0019C200 */  sll   $t8, $t9, 8
/* 0CB9E4 7F096EB4 92190009 */  lbu   $t9, 9($s0)
/* 0CB9E8 7F096EB8 000A7E00 */  sll   $t7, $t2, 0x18
/* 0CB9EC 7F096EBC 030F6825 */  or    $t5, $t8, $t7
/* 0CB9F0 7F096EC0 8FB80228 */  lw    $t8, 0x228($sp)
/* 0CB9F4 7F096EC4 00195C00 */  sll   $t3, $t9, 0x10
/* 0CB9F8 7F096EC8 01AB7025 */  or    $t6, $t5, $t3
/* 0CB9FC 7F096ECC 35CA00FF */  ori   $t2, $t6, 0xff
/* 0CBA00 7F096ED0 AF0A0004 */  sw    $t2, 4($t8)
/* 0CBA04 7F096ED4 8FAF06B0 */  lw    $t7, 0x6b0($sp)
/* 0CBA08 7F096ED8 3C0D55FE */  lui   $t5, (0x55FEF97C >> 16) # lui $t5, 0x55fe
/* 0CBA0C 7F096EDC 3C19FC40 */  lui   $t9, (0xFC40FE81 >> 16) # lui $t9, 0xfc40
/* 0CBA10 7F096EE0 25EC0008 */  addiu $t4, $t7, 8
/* 0CBA14 7F096EE4 AFAC06B0 */  sw    $t4, 0x6b0($sp)
/* 0CBA18 7F096EE8 3739FE81 */  ori   $t9, (0xFC40FE81 & 0xFFFF) # ori $t9, $t9, 0xfe81
/* 0CBA1C 7F096EEC 35ADF97C */  ori   $t5, (0x55FEF97C & 0xFFFF) # ori $t5, $t5, 0xf97c
/* 0CBA20 7F096EF0 ADED0004 */  sw    $t5, 4($t7)
/* 0CBA24 7F096EF4 0FC1E0F9 */  jal   currentPlayerGetProjectionMatrixF
/* 0CBA28 7F096EF8 ADF90000 */   sw    $t9, ($t7)
/* 0CBA2C 7F096EFC 0FC1E0F1 */  jal   currentPlayerGetMatrix10CC
/* 0CBA30 7F096F00 00408025 */   move  $s0, $v0
/* 0CBA34 7F096F04 02002025 */  move  $a0, $s0
/* 0CBA38 7F096F08 00402825 */  move  $a1, $v0
/* 0CBA3C 7F096F0C 0FC16032 */  jal   matrix_4x4_multiply
/* 0CBA40 7F096F10 27A601E4 */   addiu $a2, $sp, 0x1e4
/* 0CBA44 7F096F14 C7A80058 */  lwc1  $f8, 0x58($sp)
/* 0CBA48 7F096F18 3C048008 */  lui   $a0, %hi(dword_CODE_bss_80079E98)
/* 0CBA4C 7F096F1C 24849E98 */  addiu $a0, %lo(dword_CODE_bss_80079E98) # addiu $a0, $a0, -0x6168
/* 0CBA50 7F096F20 44054000 */  mfc1  $a1, $f8
/* 0CBA54 7F096F24 44064000 */  mfc1  $a2, $f8
/* 0CBA58 7F096F28 44074000 */  mfc1  $a3, $f8
/* 0CBA5C 7F096F2C 0C005BA4 */  jal   guScaleF
/* 0CBA60 7F096F30 00000000 */   nop   
/* 0CBA64 7F096F34 3C058008 */  lui   $a1, %hi(dword_CODE_bss_80079E98)
/* 0CBA68 7F096F38 24A59E98 */  addiu $a1, %lo(dword_CODE_bss_80079E98) # addiu $a1, $a1, -0x6168
/* 0CBA6C 7F096F3C 27A401E4 */  addiu $a0, $sp, 0x1e4
/* 0CBA70 7F096F40 0FC16032 */  jal   matrix_4x4_multiply
/* 0CBA74 7F096F44 27A601A4 */   addiu $a2, $sp, 0x1a4
/* 0CBA78 7F096F48 1A200036 */  blez  $s1, .L7F097024
/* 0CBA7C 7F096F4C AFA00088 */   sw    $zero, 0x88($sp)
/* 0CBA80 7F096F50 27A404B4 */  addiu $a0, $sp, 0x4b4
/* 0CBA84 7F096F54 AFA40058 */  sw    $a0, 0x58($sp)
/* 0CBA88 7F096F58 27B0008C */  addiu $s0, $sp, 0x8c
.L7F096F5C:
/* 0CBA8C 7F096F5C 3C018005 */  lui   $at, %hi(D_800575D0)
/* 0CBA90 7F096F60 C42075D0 */  lwc1  $f0, %lo(D_800575D0)($at)
/* 0CBA94 7F096F64 8FA40058 */  lw    $a0, 0x58($sp)
/* 0CBA98 7F096F68 27A501A4 */  addiu $a1, $sp, 0x1a4
/* 0CBA9C 7F096F6C 44070000 */  mfc1  $a3, $f0
/* 0CBAA0 7F096F70 24060082 */  li    $a2, 130
/* 0CBAA4 7F096F74 AFB00014 */  sw    $s0, 0x14($sp)
/* 0CBAA8 7F096F78 0FC25CE2 */  jal   sub_GAME_7F097388
/* 0CBAAC 7F096F7C E7A00010 */   swc1  $f0, 0x10($sp)
/* 0CBAB0 7F096F80 0FC1E131 */  jal   getPlayer_c_screenleft
/* 0CBAB4 7F096F84 00000000 */   nop   
/* 0CBAB8 7F096F88 0FC1E131 */  jal   getPlayer_c_screenleft
/* 0CBABC 7F096F8C 46000506 */   mov.s $f20, $f0
/* 0CBAC0 7F096F90 0FC1E129 */  jal   getPlayer_c_screenwidth
/* 0CBAC4 7F096F94 46000586 */   mov.s $f22, $f0
/* 0CBAC8 7F096F98 46160280 */  add.s $f10, $f0, $f22
/* 0CBACC 7F096F9C 461AA382 */  mul.s $f14, $f20, $f26
/* 0CBAD0 7F096FA0 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0CBAD4 7F096FA4 44812000 */  mtc1  $at, $f4
/* 0CBAD8 7F096FA8 461A5182 */  mul.s $f6, $f10, $f26
/* 0CBADC 7F096FAC C60C0028 */  lwc1  $f12, 0x28($s0)
/* 0CBAE0 7F096FB0 46043201 */  sub.s $f8, $f6, $f4
/* 0CBAE4 7F096FB4 44064000 */  mfc1  $a2, $f8
/* 0CBAE8 7F096FB8 0FC24F12 */  jal   sub_GAME_7F093C48
/* 0CBAEC 7F096FBC 00000000 */   nop   
/* 0CBAF0 7F096FC0 0FC1E135 */  jal   getPlayer_c_screentop
/* 0CBAF4 7F096FC4 E6000028 */   swc1  $f0, 0x28($s0)
/* 0CBAF8 7F096FC8 0FC1E135 */  jal   getPlayer_c_screentop
/* 0CBAFC 7F096FCC 46000506 */   mov.s $f20, $f0
/* 0CBB00 7F096FD0 0FC1E12D */  jal   getPlayer_c_screenheight
/* 0CBB04 7F096FD4 46000586 */   mov.s $f22, $f0
/* 0CBB08 7F096FD8 46160280 */  add.s $f10, $f0, $f22
/* 0CBB0C 7F096FDC 461AA382 */  mul.s $f14, $f20, $f26
/* 0CBB10 7F096FE0 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0CBB14 7F096FE4 44812000 */  mtc1  $at, $f4
/* 0CBB18 7F096FE8 461A5182 */  mul.s $f6, $f10, $f26
/* 0CBB1C 7F096FEC C60C002C */  lwc1  $f12, 0x2c($s0)
/* 0CBB20 7F096FF0 46043201 */  sub.s $f8, $f6, $f4
/* 0CBB24 7F096FF4 44064000 */  mfc1  $a2, $f8
/* 0CBB28 7F096FF8 0FC24F12 */  jal   sub_GAME_7F093C48
/* 0CBB2C 7F096FFC 00000000 */   nop   
/* 0CBB30 7F097000 8FA20088 */  lw    $v0, 0x88($sp)
/* 0CBB34 7F097004 E600002C */  swc1  $f0, 0x2c($s0)
/* 0CBB38 7F097008 8FAB0058 */  lw    $t3, 0x58($sp)
/* 0CBB3C 7F09700C 24420001 */  addiu $v0, $v0, 1
/* 0CBB40 7F097010 AFA20088 */  sw    $v0, 0x88($sp)
/* 0CBB44 7F097014 256E0018 */  addiu $t6, $t3, 0x18
/* 0CBB48 7F097018 AFAE0058 */  sw    $t6, 0x58($sp)
/* 0CBB4C 7F09701C 1451FFCF */  bne   $v0, $s1, .L7F096F5C
/* 0CBB50 7F097020 26100038 */   addiu $s0, $s0, 0x38
.L7F097024:
/* 0CBB54 7F097024 24010004 */  li    $at, 4
/* 0CBB58 7F097028 16210099 */  bne   $s1, $at, .L7F097290
/* 0CBB5C 7F09702C 8FAA005C */   lw    $t2, 0x5c($sp)
/* 0CBB60 7F097030 2401000C */  li    $at, 12
/* 0CBB64 7F097034 1541007E */  bne   $t2, $at, .L7F097230
/* 0CBB68 7F097038 27B0008C */   addiu $s0, $sp, 0x8c
/* 0CBB6C 7F09703C C7AA0548 */  lwc1  $f10, 0x548($sp)
/* 0CBB70 7F097040 C7A6054C */  lwc1  $f6, 0x54c($sp)
/* 0CBB74 7F097044 C7A800F0 */  lwc1  $f8, 0xf0($sp)
/* 0CBB78 7F097048 4606503C */  c.lt.s $f10, $f6
/* 0CBB7C 7F09704C C7AA00B8 */  lwc1  $f10, 0xb8($sp)
/* 0CBB80 7F097050 4502003D */  bc1fl .L7F097148
/* 0CBB84 7F097054 461A5180 */   add.s $f6, $f10, $f26
/* 0CBB88 7F097058 461A4280 */  add.s $f10, $f8, $f26
/* 0CBB8C 7F09705C C7A40160 */  lwc1  $f4, 0x160($sp)
/* 0CBB90 7F097060 27A5008C */  addiu $a1, $sp, 0x8c
/* 0CBB94 7F097064 8FA406B0 */  lw    $a0, 0x6b0($sp)
/* 0CBB98 7F097068 4604503E */  c.le.s $f10, $f4
/* 0CBB9C 7F09706C 27A600C4 */  addiu $a2, $sp, 0xc4
/* 0CBBA0 7F097070 27A700FC */  addiu $a3, $sp, 0xfc
/* 0CBBA4 7F097074 3C014302 */  li    $at, 0x43020000 # 130.000000
/* 0CBBA8 7F097078 4500002C */  bc1f  .L7F09712C
/* 0CBBAC 7F09707C 24180001 */   li    $t8, 1
/* 0CBBB0 7F097080 0FC1E131 */  jal   getPlayer_c_screenleft
/* 0CBBB4 7F097084 00000000 */   nop   
/* 0CBBB8 7F097088 461A0182 */  mul.s $f6, $f0, $f26
/* 0CBBBC 7F09708C 0FC1E135 */  jal   getPlayer_c_screentop
/* 0CBBC0 7F097090 E7A600B4 */   swc1  $f6, 0xb4($sp)
/* 0CBBC4 7F097094 461A0202 */  mul.s $f8, $f0, $f26
/* 0CBBC8 7F097098 0FC1E131 */  jal   getPlayer_c_screenleft
/* 0CBBCC 7F09709C E7A800B8 */   swc1  $f8, 0xb8($sp)
/* 0CBBD0 7F0970A0 0FC1E129 */  jal   getPlayer_c_screenwidth
/* 0CBBD4 7F0970A4 46000506 */   mov.s $f20, $f0
/* 0CBBD8 7F0970A8 46140100 */  add.s $f4, $f0, $f20
/* 0CBBDC 7F0970AC 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0CBBE0 7F0970B0 44813000 */  mtc1  $at, $f6
/* 0CBBE4 7F0970B4 461A2282 */  mul.s $f10, $f4, $f26
/* 0CBBE8 7F0970B8 46065201 */  sub.s $f8, $f10, $f6
/* 0CBBEC 7F0970BC 0FC1E135 */  jal   getPlayer_c_screentop
/* 0CBBF0 7F0970C0 E7A800EC */   swc1  $f8, 0xec($sp)
/* 0CBBF4 7F0970C4 461A0102 */  mul.s $f4, $f0, $f26
/* 0CBBF8 7F0970C8 0FC1E131 */  jal   getPlayer_c_screenleft
/* 0CBBFC 7F0970CC E7A400F0 */   swc1  $f4, 0xf0($sp)
/* 0CBC00 7F0970D0 461A0282 */  mul.s $f10, $f0, $f26
/* 0CBC04 7F0970D4 0FC1E131 */  jal   getPlayer_c_screenleft
/* 0CBC08 7F0970D8 E7AA0124 */   swc1  $f10, 0x124($sp)
/* 0CBC0C 7F0970DC 0FC1E129 */  jal   getPlayer_c_screenwidth
/* 0CBC10 7F0970E0 46000506 */   mov.s $f20, $f0
/* 0CBC14 7F0970E4 46140180 */  add.s $f6, $f0, $f20
/* 0CBC18 7F0970E8 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0CBC1C 7F0970EC 44812000 */  mtc1  $at, $f4
/* 0CBC20 7F0970F0 3C014302 */  li    $at, 0x43020000 # 130.000000
/* 0CBC24 7F0970F4 461A3202 */  mul.s $f8, $f6, $f26
/* 0CBC28 7F0970F8 44813000 */  mtc1  $at, $f6
/* 0CBC2C 7F0970FC 27B10134 */  addiu $s1, $sp, 0x134
/* 0CBC30 7F097100 27A5008C */  addiu $a1, $sp, 0x8c
/* 0CBC34 7F097104 AFB10010 */  sw    $s1, 0x10($sp)
/* 0CBC38 7F097108 8FA406B0 */  lw    $a0, 0x6b0($sp)
/* 0CBC3C 7F09710C 27A600C4 */  addiu $a2, $sp, 0xc4
/* 0CBC40 7F097110 46044281 */  sub.s $f10, $f8, $f4
/* 0CBC44 7F097114 27A700FC */  addiu $a3, $sp, 0xfc
/* 0CBC48 7F097118 E7A60014 */  swc1  $f6, 0x14($sp)
/* 0CBC4C 7F09711C 0FC2628B */  jal   sub_GAME_7F098A2C
/* 0CBC50 7F097120 E7AA015C */   swc1  $f10, 0x15c($sp)
/* 0CBC54 7F097124 1000008D */  b     .L7F09735C
/* 0CBC58 7F097128 AFA206B0 */   sw    $v0, 0x6b0($sp)
.L7F09712C:
/* 0CBC5C 7F09712C 44814000 */  mtc1  $at, $f8
/* 0CBC60 7F097130 AFB80014 */  sw    $t8, 0x14($sp)
/* 0CBC64 7F097134 0FC25E06 */  jal   sub_GAME_7F097818
/* 0CBC68 7F097138 E7A80010 */   swc1  $f8, 0x10($sp)
/* 0CBC6C 7F09713C 10000087 */  b     .L7F09735C
/* 0CBC70 7F097140 AFA206B0 */   sw    $v0, 0x6b0($sp)
/* 0CBC74 7F097144 461A5180 */  add.s $f6, $f10, $f26
.L7F097148:
/* 0CBC78 7F097148 C7A40128 */  lwc1  $f4, 0x128($sp)
/* 0CBC7C 7F09714C 27A6008C */  addiu $a2, $sp, 0x8c
/* 0CBC80 7F097150 27A70134 */  addiu $a3, $sp, 0x134
/* 0CBC84 7F097154 4604303E */  c.le.s $f6, $f4
/* 0CBC88 7F097158 8FA406B0 */  lw    $a0, 0x6b0($sp)
/* 0CBC8C 7F09715C 27A500C4 */  addiu $a1, $sp, 0xc4
/* 0CBC90 7F097160 3C014302 */  li    $at, 0x43020000 # 130.000000
/* 0CBC94 7F097164 4500002C */  bc1f  .L7F097218
/* 0CBC98 7F097168 240C0001 */   li    $t4, 1
/* 0CBC9C 7F09716C 0FC1E131 */  jal   getPlayer_c_screenleft
/* 0CBCA0 7F097170 00000000 */   nop   
/* 0CBCA4 7F097174 461A0202 */  mul.s $f8, $f0, $f26
/* 0CBCA8 7F097178 0FC1E135 */  jal   getPlayer_c_screentop
/* 0CBCAC 7F09717C E7A800B4 */   swc1  $f8, 0xb4($sp)
/* 0CBCB0 7F097180 461A0282 */  mul.s $f10, $f0, $f26
/* 0CBCB4 7F097184 0FC1E131 */  jal   getPlayer_c_screenleft
/* 0CBCB8 7F097188 E7AA00B8 */   swc1  $f10, 0xb8($sp)
/* 0CBCBC 7F09718C 0FC1E129 */  jal   getPlayer_c_screenwidth
/* 0CBCC0 7F097190 46000506 */   mov.s $f20, $f0
/* 0CBCC4 7F097194 46140100 */  add.s $f4, $f0, $f20
/* 0CBCC8 7F097198 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0CBCCC 7F09719C 44814000 */  mtc1  $at, $f8
/* 0CBCD0 7F0971A0 461A2182 */  mul.s $f6, $f4, $f26
/* 0CBCD4 7F0971A4 46083281 */  sub.s $f10, $f6, $f8
/* 0CBCD8 7F0971A8 0FC1E135 */  jal   getPlayer_c_screentop
/* 0CBCDC 7F0971AC E7AA00EC */   swc1  $f10, 0xec($sp)
/* 0CBCE0 7F0971B0 461A0102 */  mul.s $f4, $f0, $f26
/* 0CBCE4 7F0971B4 0FC1E131 */  jal   getPlayer_c_screenleft
/* 0CBCE8 7F0971B8 E7A400F0 */   swc1  $f4, 0xf0($sp)
/* 0CBCEC 7F0971BC 461A0182 */  mul.s $f6, $f0, $f26
/* 0CBCF0 7F0971C0 0FC1E131 */  jal   getPlayer_c_screenleft
/* 0CBCF4 7F0971C4 E7A60124 */   swc1  $f6, 0x124($sp)
/* 0CBCF8 7F0971C8 0FC1E129 */  jal   getPlayer_c_screenwidth
/* 0CBCFC 7F0971CC 46000506 */   mov.s $f20, $f0
/* 0CBD00 7F0971D0 46140200 */  add.s $f8, $f0, $f20
/* 0CBD04 7F0971D4 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0CBD08 7F0971D8 44812000 */  mtc1  $at, $f4
/* 0CBD0C 7F0971DC 3C014302 */  li    $at, 0x43020000 # 130.000000
/* 0CBD10 7F0971E0 461A4282 */  mul.s $f10, $f8, $f26
/* 0CBD14 7F0971E4 44814000 */  mtc1  $at, $f8
/* 0CBD18 7F0971E8 27AF00FC */  addiu $t7, $sp, 0xfc
/* 0CBD1C 7F0971EC 27A6008C */  addiu $a2, $sp, 0x8c
/* 0CBD20 7F0971F0 27A70134 */  addiu $a3, $sp, 0x134
/* 0CBD24 7F0971F4 AFAF0010 */  sw    $t7, 0x10($sp)
/* 0CBD28 7F0971F8 8FA406B0 */  lw    $a0, 0x6b0($sp)
/* 0CBD2C 7F0971FC 46045181 */  sub.s $f6, $f10, $f4
/* 0CBD30 7F097200 27A500C4 */  addiu $a1, $sp, 0xc4
/* 0CBD34 7F097204 E7A80014 */  swc1  $f8, 0x14($sp)
/* 0CBD38 7F097208 0FC2628B */  jal   sub_GAME_7F098A2C
/* 0CBD3C 7F09720C E7A6015C */   swc1  $f6, 0x15c($sp)
/* 0CBD40 7F097210 10000052 */  b     .L7F09735C
/* 0CBD44 7F097214 AFA206B0 */   sw    $v0, 0x6b0($sp)
.L7F097218:
/* 0CBD48 7F097218 44815000 */  mtc1  $at, $f10
/* 0CBD4C 7F09721C AFAC0014 */  sw    $t4, 0x14($sp)
/* 0CBD50 7F097220 0FC25E06 */  jal   sub_GAME_7F097818
/* 0CBD54 7F097224 E7AA0010 */   swc1  $f10, 0x10($sp)
/* 0CBD58 7F097228 1000004C */  b     .L7F09735C
/* 0CBD5C 7F09722C AFA206B0 */   sw    $v0, 0x6b0($sp)
.L7F097230:
/* 0CBD60 7F097230 3C014302 */  li    $at, 0x43020000 # 130.000000
/* 0CBD64 7F097234 44812000 */  mtc1  $at, $f4
/* 0CBD68 7F097238 27B10134 */  addiu $s1, $sp, 0x134
/* 0CBD6C 7F09723C 24190001 */  li    $t9, 1
/* 0CBD70 7F097240 AFB90014 */  sw    $t9, 0x14($sp)
/* 0CBD74 7F097244 02203825 */  move  $a3, $s1
/* 0CBD78 7F097248 8FA406B0 */  lw    $a0, 0x6b0($sp)
/* 0CBD7C 7F09724C 02002825 */  move  $a1, $s0
/* 0CBD80 7F097250 27A600C4 */  addiu $a2, $sp, 0xc4
/* 0CBD84 7F097254 0FC25E06 */  jal   sub_GAME_7F097818
/* 0CBD88 7F097258 E7A40010 */   swc1  $f4, 0x10($sp)
/* 0CBD8C 7F09725C 3C014302 */  li    $at, 0x43020000 # 130.000000
/* 0CBD90 7F097260 44813000 */  mtc1  $at, $f6
/* 0CBD94 7F097264 240D0001 */  li    $t5, 1
/* 0CBD98 7F097268 AFA206B0 */  sw    $v0, 0x6b0($sp)
/* 0CBD9C 7F09726C AFAD0014 */  sw    $t5, 0x14($sp)
/* 0CBDA0 7F097270 00402025 */  move  $a0, $v0
/* 0CBDA4 7F097274 02202825 */  move  $a1, $s1
/* 0CBDA8 7F097278 27A600FC */  addiu $a2, $sp, 0xfc
/* 0CBDAC 7F09727C 02003825 */  move  $a3, $s0
/* 0CBDB0 7F097280 0FC25E06 */  jal   sub_GAME_7F097818
/* 0CBDB4 7F097284 E7A60010 */   swc1  $f6, 0x10($sp)
/* 0CBDB8 7F097288 10000034 */  b     .L7F09735C
/* 0CBDBC 7F09728C AFA206B0 */   sw    $v0, 0x6b0($sp)
.L7F097290:
/* 0CBDC0 7F097290 24010005 */  li    $at, 5
/* 0CBDC4 7F097294 16210024 */  bne   $s1, $at, .L7F097328
/* 0CBDC8 7F097298 27B0008C */   addiu $s0, $sp, 0x8c
/* 0CBDCC 7F09729C 3C014302 */  li    $at, 0x43020000 # 130.000000
/* 0CBDD0 7F0972A0 44814000 */  mtc1  $at, $f8
/* 0CBDD4 7F0972A4 240B0001 */  li    $t3, 1
/* 0CBDD8 7F0972A8 AFAB0014 */  sw    $t3, 0x14($sp)
/* 0CBDDC 7F0972AC 8FA406B0 */  lw    $a0, 0x6b0($sp)
/* 0CBDE0 7F0972B0 02002825 */  move  $a1, $s0
/* 0CBDE4 7F0972B4 27A600C4 */  addiu $a2, $sp, 0xc4
/* 0CBDE8 7F0972B8 27A700FC */  addiu $a3, $sp, 0xfc
/* 0CBDEC 7F0972BC 0FC25E06 */  jal   sub_GAME_7F097818
/* 0CBDF0 7F0972C0 E7A80010 */   swc1  $f8, 0x10($sp)
/* 0CBDF4 7F0972C4 3C014302 */  li    $at, 0x43020000 # 130.000000
/* 0CBDF8 7F0972C8 44815000 */  mtc1  $at, $f10
/* 0CBDFC 7F0972CC 27B10134 */  addiu $s1, $sp, 0x134
/* 0CBE00 7F0972D0 240E0001 */  li    $t6, 1
/* 0CBE04 7F0972D4 AFA206B0 */  sw    $v0, 0x6b0($sp)
/* 0CBE08 7F0972D8 AFAE0014 */  sw    $t6, 0x14($sp)
/* 0CBE0C 7F0972DC 02203825 */  move  $a3, $s1
/* 0CBE10 7F0972E0 00402025 */  move  $a0, $v0
/* 0CBE14 7F0972E4 02002825 */  move  $a1, $s0
/* 0CBE18 7F0972E8 27A600FC */  addiu $a2, $sp, 0xfc
/* 0CBE1C 7F0972EC 0FC25E06 */  jal   sub_GAME_7F097818
/* 0CBE20 7F0972F0 E7AA0010 */   swc1  $f10, 0x10($sp)
/* 0CBE24 7F0972F4 3C014302 */  li    $at, 0x43020000 # 130.000000
/* 0CBE28 7F0972F8 44812000 */  mtc1  $at, $f4
/* 0CBE2C 7F0972FC 240A0001 */  li    $t2, 1
/* 0CBE30 7F097300 AFA206B0 */  sw    $v0, 0x6b0($sp)
/* 0CBE34 7F097304 AFAA0014 */  sw    $t2, 0x14($sp)
/* 0CBE38 7F097308 00402025 */  move  $a0, $v0
/* 0CBE3C 7F09730C 02002825 */  move  $a1, $s0
/* 0CBE40 7F097310 02203025 */  move  $a2, $s1
/* 0CBE44 7F097314 27A7016C */  addiu $a3, $sp, 0x16c
/* 0CBE48 7F097318 0FC25E06 */  jal   sub_GAME_7F097818
/* 0CBE4C 7F09731C E7A40010 */   swc1  $f4, 0x10($sp)
/* 0CBE50 7F097320 1000000E */  b     .L7F09735C
/* 0CBE54 7F097324 AFA206B0 */   sw    $v0, 0x6b0($sp)
.L7F097328:
/* 0CBE58 7F097328 24010003 */  li    $at, 3
/* 0CBE5C 7F09732C 1621000B */  bne   $s1, $at, .L7F09735C
/* 0CBE60 7F097330 27A5008C */   addiu $a1, $sp, 0x8c
/* 0CBE64 7F097334 3C014302 */  li    $at, 0x43020000 # 130.000000
/* 0CBE68 7F097338 44813000 */  mtc1  $at, $f6
/* 0CBE6C 7F09733C 24180001 */  li    $t8, 1
/* 0CBE70 7F097340 AFB80014 */  sw    $t8, 0x14($sp)
/* 0CBE74 7F097344 8FA406B0 */  lw    $a0, 0x6b0($sp)
/* 0CBE78 7F097348 27A600C4 */  addiu $a2, $sp, 0xc4
/* 0CBE7C 7F09734C 27A700FC */  addiu $a3, $sp, 0xfc
/* 0CBE80 7F097350 0FC25E06 */  jal   sub_GAME_7F097818
/* 0CBE84 7F097354 E7A60010 */   swc1  $f6, 0x10($sp)
/* 0CBE88 7F097358 AFA206B0 */  sw    $v0, 0x6b0($sp)
.L7F09735C:
/* 0CBE8C 7F09735C 8FA206B0 */  lw    $v0, 0x6b0($sp)
.L7F097360:
/* 0CBE90 7F097360 8FBF004C */  lw    $ra, 0x4c($sp)
/* 0CBE94 7F097364 D7B40018 */  ldc1  $f20, 0x18($sp)
/* 0CBE98 7F097368 D7B60020 */  ldc1  $f22, 0x20($sp)
/* 0CBE9C 7F09736C D7B80028 */  ldc1  $f24, 0x28($sp)
/* 0CBEA0 7F097370 D7BA0030 */  ldc1  $f26, 0x30($sp)
/* 0CBEA4 7F097374 D7BC0038 */  ldc1  $f28, 0x38($sp)
/* 0CBEA8 7F097378 8FB00044 */  lw    $s0, 0x44($sp)
/* 0CBEAC 7F09737C 8FB10048 */  lw    $s1, 0x48($sp)
/* 0CBEB0 7F097380 03E00008 */  jr    $ra
/* 0CBEB4 7F097384 27BD06B0 */   addiu $sp, $sp, 0x6b0
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F097388(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F097388
/* 0CBEB8 7F097388 27BDFF88 */  addiu $sp, $sp, -0x78
/* 0CBEBC 7F09738C 30CEFFFF */  andi  $t6, $a2, 0xffff
/* 0CBEC0 7F097390 448E2000 */  mtc1  $t6, $f4
/* 0CBEC4 7F097394 3C014780 */  li    $at, 0x47800000 # 65536.000000
/* 0CBEC8 7F097398 44816000 */  mtc1  $at, $f12
/* 0CBECC 7F09739C AFB00020 */  sw    $s0, 0x20($sp)
/* 0CBED0 7F0973A0 44877000 */  mtc1  $a3, $f14
/* 0CBED4 7F0973A4 00808025 */  move  $s0, $a0
/* 0CBED8 7F0973A8 AFBF0024 */  sw    $ra, 0x24($sp)
/* 0CBEDC 7F0973AC F7B40018 */  sdc1  $f20, 0x18($sp)
/* 0CBEE0 7F0973B0 AFA60080 */  sw    $a2, 0x80($sp)
/* 0CBEE4 7F0973B4 05C10005 */  bgez  $t6, .L7F0973CC
/* 0CBEE8 7F0973B8 468021A0 */   cvt.s.w $f6, $f4
/* 0CBEEC 7F0973BC 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0CBEF0 7F0973C0 44814000 */  mtc1  $at, $f8
/* 0CBEF4 7F0973C4 00000000 */  nop   
/* 0CBEF8 7F0973C8 46083180 */  add.s $f6, $f6, $f8
.L7F0973CC:
/* 0CBEFC 7F0973CC C60A0000 */  lwc1  $f10, ($s0)
/* 0CBF00 7F0973D0 C4B20000 */  lwc1  $f18, ($a1)
/* 0CBF04 7F0973D4 460C3003 */  div.s $f0, $f6, $f12
/* 0CBF08 7F0973D8 C4A60010 */  lwc1  $f6, 0x10($a1)
/* 0CBF0C 7F0973DC C6080004 */  lwc1  $f8, 4($s0)
/* 0CBF10 7F0973E0 44808000 */  mtc1  $zero, $f16
/* 0CBF14 7F0973E4 46125102 */  mul.s $f4, $f10, $f18
/* 0CBF18 7F0973E8 00000000 */  nop   
/* 0CBF1C 7F0973EC 46064282 */  mul.s $f10, $f8, $f6
/* 0CBF20 7F0973F0 C4A60020 */  lwc1  $f6, 0x20($a1)
/* 0CBF24 7F0973F4 C6080008 */  lwc1  $f8, 8($s0)
/* 0CBF28 7F0973F8 460A2480 */  add.s $f18, $f4, $f10
/* 0CBF2C 7F0973FC 46064102 */  mul.s $f4, $f8, $f6
/* 0CBF30 7F097400 C4A80030 */  lwc1  $f8, 0x30($a1)
/* 0CBF34 7F097404 46000086 */  mov.s $f2, $f0
/* 0CBF38 7F097408 46049280 */  add.s $f10, $f18, $f4
/* 0CBF3C 7F09740C 460A4180 */  add.s $f6, $f8, $f10
/* 0CBF40 7F097410 E7A60068 */  swc1  $f6, 0x68($sp)
/* 0CBF44 7F097414 C6120000 */  lwc1  $f18, ($s0)
/* 0CBF48 7F097418 C4A40004 */  lwc1  $f4, 4($a1)
/* 0CBF4C 7F09741C C60A0004 */  lwc1  $f10, 4($s0)
/* 0CBF50 7F097420 C4A60014 */  lwc1  $f6, 0x14($a1)
/* 0CBF54 7F097424 46049202 */  mul.s $f8, $f18, $f4
/* 0CBF58 7F097428 00000000 */  nop   
/* 0CBF5C 7F09742C 46065482 */  mul.s $f18, $f10, $f6
/* 0CBF60 7F097430 C4A60024 */  lwc1  $f6, 0x24($a1)
/* 0CBF64 7F097434 C60A0008 */  lwc1  $f10, 8($s0)
/* 0CBF68 7F097438 46124100 */  add.s $f4, $f8, $f18
/* 0CBF6C 7F09743C 46065202 */  mul.s $f8, $f10, $f6
/* 0CBF70 7F097440 C4AA0034 */  lwc1  $f10, 0x34($a1)
/* 0CBF74 7F097444 46082480 */  add.s $f18, $f4, $f8
/* 0CBF78 7F097448 46125180 */  add.s $f6, $f10, $f18
/* 0CBF7C 7F09744C E7A6006C */  swc1  $f6, 0x6c($sp)
/* 0CBF80 7F097450 C6040000 */  lwc1  $f4, ($s0)
/* 0CBF84 7F097454 C4A80008 */  lwc1  $f8, 8($a1)
/* 0CBF88 7F097458 C6120004 */  lwc1  $f18, 4($s0)
/* 0CBF8C 7F09745C C4A60018 */  lwc1  $f6, 0x18($a1)
/* 0CBF90 7F097460 46082282 */  mul.s $f10, $f4, $f8
/* 0CBF94 7F097464 00000000 */  nop   
/* 0CBF98 7F097468 46069102 */  mul.s $f4, $f18, $f6
/* 0CBF9C 7F09746C C4A60028 */  lwc1  $f6, 0x28($a1)
/* 0CBFA0 7F097470 C6120008 */  lwc1  $f18, 8($s0)
/* 0CBFA4 7F097474 46045200 */  add.s $f8, $f10, $f4
/* 0CBFA8 7F097478 46069282 */  mul.s $f10, $f18, $f6
/* 0CBFAC 7F09747C C4B20038 */  lwc1  $f18, 0x38($a1)
/* 0CBFB0 7F097480 460A4100 */  add.s $f4, $f8, $f10
/* 0CBFB4 7F097484 46049180 */  add.s $f6, $f18, $f4
/* 0CBFB8 7F097488 E7A60070 */  swc1  $f6, 0x70($sp)
/* 0CBFBC 7F09748C C4AA000C */  lwc1  $f10, 0xc($a1)
/* 0CBFC0 7F097490 C6080000 */  lwc1  $f8, ($s0)
/* 0CBFC4 7F097494 C4A6001C */  lwc1  $f6, 0x1c($a1)
/* 0CBFC8 7F097498 C6040004 */  lwc1  $f4, 4($s0)
/* 0CBFCC 7F09749C 460A4482 */  mul.s $f18, $f8, $f10
/* 0CBFD0 7F0974A0 00000000 */  nop   
/* 0CBFD4 7F0974A4 46062202 */  mul.s $f8, $f4, $f6
/* 0CBFD8 7F0974A8 C4A6002C */  lwc1  $f6, 0x2c($a1)
/* 0CBFDC 7F0974AC C6040008 */  lwc1  $f4, 8($s0)
/* 0CBFE0 7F0974B0 46089280 */  add.s $f10, $f18, $f8
/* 0CBFE4 7F0974B4 46062482 */  mul.s $f18, $f4, $f6
/* 0CBFE8 7F0974B8 C4A4003C */  lwc1  $f4, 0x3c($a1)
/* 0CBFEC 7F0974BC 46125200 */  add.s $f8, $f10, $f18
/* 0CBFF0 7F0974C0 460C7483 */  div.s $f18, $f14, $f12
/* 0CBFF4 7F0974C4 46082180 */  add.s $f6, $f4, $f8
/* 0CBFF8 7F0974C8 E7A60074 */  swc1  $f6, 0x74($sp)
/* 0CBFFC 7F0974CC C60A000C */  lwc1  $f10, 0xc($s0)
/* 0CC000 7F0974D0 C7A60088 */  lwc1  $f6, 0x88($sp)
/* 0CC004 7F0974D4 46125102 */  mul.s $f4, $f10, $f18
/* 0CC008 7F0974D8 460C3283 */  div.s $f10, $f6, $f12
/* 0CC00C 7F0974DC E7A40060 */  swc1  $f4, 0x60($sp)
/* 0CC010 7F0974E0 C6080010 */  lwc1  $f8, 0x10($s0)
/* 0CC014 7F0974E4 C7A40074 */  lwc1  $f4, 0x74($sp)
/* 0CC018 7F0974E8 46048032 */  c.eq.s $f16, $f4
/* 0CC01C 7F0974EC 460A4482 */  mul.s $f18, $f8, $f10
/* 0CC020 7F0974F0 E7B20064 */  swc1  $f18, 0x64($sp)
/* 0CC024 7F0974F4 45000004 */  bc1f  .L7F097508
/* 0CC028 7F0974F8 C7B20068 */   lwc1  $f18, 0x68($sp)
/* 0CC02C 7F0974FC 3C018005 */  lui   $at, %hi(D_800575D4)
/* 0CC030 7F097500 10000006 */  b     .L7F09751C
/* 0CC034 7F097504 C43475D4 */   lwc1  $f20, %lo(D_800575D4)($at)
.L7F097508:
/* 0CC038 7F097508 C7A80074 */  lwc1  $f8, 0x74($sp)
/* 0CC03C 7F09750C 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0CC040 7F097510 44813000 */  mtc1  $at, $f6
/* 0CC044 7F097514 46004282 */  mul.s $f10, $f8, $f0
/* 0CC048 7F097518 460A3503 */  div.s $f20, $f6, $f10
.L7F09751C:
/* 0CC04C 7F09751C 4610A03C */  c.lt.s $f20, $f16
/* 0CC050 7F097520 4600A006 */  mov.s $f0, $f20
/* 0CC054 7F097524 45000002 */  bc1f  .L7F097530
/* 0CC058 7F097528 3C018005 */   lui   $at, %hi(D_800575D8)
/* 0CC05C 7F09752C C42075D8 */  lwc1  $f0, %lo(D_800575D8)($at)
.L7F097530:
/* 0CC060 7F097530 46009102 */  mul.s $f4, $f18, $f0
/* 0CC064 7F097534 C7A6006C */  lwc1  $f6, 0x6c($sp)
/* 0CC068 7F097538 46022202 */  mul.s $f8, $f4, $f2
/* 0CC06C 7F09753C C7A40070 */  lwc1  $f4, 0x70($sp)
/* 0CC070 7F097540 46003282 */  mul.s $f10, $f6, $f0
/* 0CC074 7F097544 E7A80048 */  swc1  $f8, 0x48($sp)
/* 0CC078 7F097548 46025482 */  mul.s $f18, $f10, $f2
/* 0CC07C 7F09754C C7AA0074 */  lwc1  $f10, 0x74($sp)
/* 0CC080 7F097550 46002202 */  mul.s $f8, $f4, $f0
/* 0CC084 7F097554 E7B2004C */  swc1  $f18, 0x4c($sp)
/* 0CC088 7F097558 46024182 */  mul.s $f6, $f8, $f2
/* 0CC08C 7F09755C 00000000 */  nop   
/* 0CC090 7F097560 46005482 */  mul.s $f18, $f10, $f0
/* 0CC094 7F097564 E7A60050 */  swc1  $f6, 0x50($sp)
/* 0CC098 7F097568 46029102 */  mul.s $f4, $f18, $f2
/* 0CC09C 7F09756C 0FC1E129 */  jal   getPlayer_c_screenwidth
/* 0CC0A0 7F097570 E7A40054 */   swc1  $f4, 0x54($sp)
/* 0CC0A4 7F097574 0FC1E129 */  jal   getPlayer_c_screenwidth
/* 0CC0A8 7F097578 E7A0002C */   swc1  $f0, 0x2c($sp)
/* 0CC0AC 7F09757C 0FC1E131 */  jal   getPlayer_c_screenleft
/* 0CC0B0 7F097580 E7A00030 */   swc1  $f0, 0x30($sp)
/* 0CC0B4 7F097584 3C014000 */  li    $at, 0x40000000 # 2.000000
/* 0CC0B8 7F097588 44811000 */  mtc1  $at, $f2
/* 0CC0BC 7F09758C 3C014080 */  li    $at, 0x40800000 # 4.000000
/* 0CC0C0 7F097590 44814000 */  mtc1  $at, $f8
/* 0CC0C4 7F097594 C7AA0030 */  lwc1  $f10, 0x30($sp)
/* 0CC0C8 7F097598 46080182 */  mul.s $f6, $f0, $f8
/* 0CC0CC 7F09759C C7A80048 */  lwc1  $f8, 0x48($sp)
/* 0CC0D0 7F0975A0 46025482 */  mul.s $f18, $f10, $f2
/* 0CC0D4 7F0975A4 C7AA002C */  lwc1  $f10, 0x2c($sp)
/* 0CC0D8 7F0975A8 46123100 */  add.s $f4, $f6, $f18
/* 0CC0DC 7F0975AC 46025182 */  mul.s $f6, $f10, $f2
/* 0CC0E0 7F0975B0 00000000 */  nop   
/* 0CC0E4 7F0975B4 46064482 */  mul.s $f18, $f8, $f6
/* 0CC0E8 7F0975B8 46122280 */  add.s $f10, $f4, $f18
/* 0CC0EC 7F0975BC 0FC1E12D */  jal   getPlayer_c_screenheight
/* 0CC0F0 7F0975C0 E7AA0038 */   swc1  $f10, 0x38($sp)
/* 0CC0F4 7F0975C4 0FC1E12D */  jal   getPlayer_c_screenheight
/* 0CC0F8 7F0975C8 E7A0002C */   swc1  $f0, 0x2c($sp)
/* 0CC0FC 7F0975CC 0FC1E135 */  jal   getPlayer_c_screentop
/* 0CC100 7F0975D0 E7A00030 */   swc1  $f0, 0x30($sp)
/* 0CC104 7F0975D4 3C018005 */  lui   $at, %hi(D_800575DC)
/* 0CC108 7F0975D8 C42275DC */  lwc1  $f2, %lo(D_800575DC)($at)
/* 0CC10C 7F0975DC 3C014000 */  li    $at, 0x40000000 # 2.000000
/* 0CC110 7F0975E0 44818000 */  mtc1  $at, $f16
/* 0CC114 7F0975E4 3C014080 */  li    $at, 0x40800000 # 4.000000
/* 0CC118 7F0975E8 44814000 */  mtc1  $at, $f8
/* 0CC11C 7F0975EC C7A40030 */  lwc1  $f4, 0x30($sp)
/* 0CC120 7F0975F0 3C018005 */  lui   $at, %hi(D_800575E0)
/* 0CC124 7F0975F4 46080182 */  mul.s $f6, $f0, $f8
/* 0CC128 7F0975F8 C7A8004C */  lwc1  $f8, 0x4c($sp)
/* 0CC12C 7F0975FC 3C06457F */  lui   $a2, (0x457FA000 >> 16) # lui $a2, 0x457f
/* 0CC130 7F097600 46102482 */  mul.s $f18, $f4, $f16
/* 0CC134 7F097604 46004107 */  neg.s $f4, $f8
/* 0CC138 7F097608 34C6A000 */  ori   $a2, (0x457FA000 & 0xFFFF) # ori $a2, $a2, 0xa000
/* 0CC13C 7F09760C C42E75E0 */  lwc1  $f14, %lo(D_800575E0)($at)
/* 0CC140 7F097610 C7AC0038 */  lwc1  $f12, 0x38($sp)
/* 0CC144 7F097614 46123280 */  add.s $f10, $f6, $f18
/* 0CC148 7F097618 C7A6002C */  lwc1  $f6, 0x2c($sp)
/* 0CC14C 7F09761C 46103482 */  mul.s $f18, $f6, $f16
/* 0CC150 7F097620 00000000 */  nop   
/* 0CC154 7F097624 46122202 */  mul.s $f8, $f4, $f18
/* 0CC158 7F097628 C7A40050 */  lwc1  $f4, 0x50($sp)
/* 0CC15C 7F09762C 46022482 */  mul.s $f18, $f4, $f2
/* 0CC160 7F097630 46085180 */  add.s $f6, $f10, $f8
/* 0CC164 7F097634 C7A80054 */  lwc1  $f8, 0x54($sp)
/* 0CC168 7F097638 46029280 */  add.s $f10, $f18, $f2
/* 0CC16C 7F09763C E7A6003C */  swc1  $f6, 0x3c($sp)
/* 0CC170 7F097640 44803000 */  mtc1  $zero, $f6
/* 0CC174 7F097644 E7AA0040 */  swc1  $f10, 0x40($sp)
/* 0CC178 7F097648 46064102 */  mul.s $f4, $f8, $f6
/* 0CC17C 7F09764C 0FC24F12 */  jal   sub_GAME_7F093C48
/* 0CC180 7F097650 E7A40044 */   swc1  $f4, 0x44($sp)
/* 0CC184 7F097654 3C018005 */  lui   $at, %hi(D_800575E4)
/* 0CC188 7F097658 3C06457F */  lui   $a2, (0x457FA000 >> 16) # lui $a2, 0x457f
/* 0CC18C 7F09765C E7A00038 */  swc1  $f0, 0x38($sp)
/* 0CC190 7F097660 34C6A000 */  ori   $a2, (0x457FA000 & 0xFFFF) # ori $a2, $a2, 0xa000
/* 0CC194 7F097664 C42E75E4 */  lwc1  $f14, %lo(D_800575E4)($at)
/* 0CC198 7F097668 0FC24F12 */  jal   sub_GAME_7F093C48
/* 0CC19C 7F09766C C7AC003C */   lwc1  $f12, 0x3c($sp)
/* 0CC1A0 7F097670 44807000 */  mtc1  $zero, $f14
/* 0CC1A4 7F097674 3C0646FF */  lui   $a2, (0x46FFFE00 >> 16) # lui $a2, 0x46ff
/* 0CC1A8 7F097678 E7A0003C */  swc1  $f0, 0x3c($sp)
/* 0CC1AC 7F09767C 34C6FE00 */  ori   $a2, (0x46FFFE00 & 0xFFFF) # ori $a2, $a2, 0xfe00
/* 0CC1B0 7F097680 0FC24F12 */  jal   sub_GAME_7F093C48
/* 0CC1B4 7F097684 C7AC0040 */   lwc1  $f12, 0x40($sp)
/* 0CC1B8 7F097688 44807000 */  mtc1  $zero, $f14
/* 0CC1BC 7F09768C 3C0646FF */  lui   $a2, (0x46FFFE00 >> 16) # lui $a2, 0x46ff
/* 0CC1C0 7F097690 E7A00040 */  swc1  $f0, 0x40($sp)
/* 0CC1C4 7F097694 34C6FE00 */  ori   $a2, (0x46FFFE00 & 0xFFFF) # ori $a2, $a2, 0xfe00
/* 0CC1C8 7F097698 0FC24F12 */  jal   sub_GAME_7F093C48
/* 0CC1CC 7F09769C C7AC0044 */   lwc1  $f12, 0x44($sp)
/* 0CC1D0 7F0976A0 8FA3008C */  lw    $v1, 0x8c($sp)
/* 0CC1D4 7F0976A4 C7B20068 */  lwc1  $f18, 0x68($sp)
/* 0CC1D8 7F0976A8 E7A00044 */  swc1  $f0, 0x44($sp)
/* 0CC1DC 7F0976AC E4720000 */  swc1  $f18, ($v1)
/* 0CC1E0 7F0976B0 C7AA006C */  lwc1  $f10, 0x6c($sp)
/* 0CC1E4 7F0976B4 E46A0004 */  swc1  $f10, 4($v1)
/* 0CC1E8 7F0976B8 C7A80070 */  lwc1  $f8, 0x70($sp)
/* 0CC1EC 7F0976BC E4680008 */  swc1  $f8, 8($v1)
/* 0CC1F0 7F0976C0 C7A60074 */  lwc1  $f6, 0x74($sp)
/* 0CC1F4 7F0976C4 E466000C */  swc1  $f6, 0xc($v1)
/* 0CC1F8 7F0976C8 C7A40060 */  lwc1  $f4, 0x60($sp)
/* 0CC1FC 7F0976CC E4640020 */  swc1  $f4, 0x20($v1)
/* 0CC200 7F0976D0 C7B20064 */  lwc1  $f18, 0x64($sp)
/* 0CC204 7F0976D4 E4720024 */  swc1  $f18, 0x24($v1)
/* 0CC208 7F0976D8 C7AA0038 */  lwc1  $f10, 0x38($sp)
/* 0CC20C 7F0976DC 0FC2E9CB */  jal   get_ptr_currentdata
/* 0CC210 7F0976E0 E46A0028 */   swc1  $f10, 0x28($v1)
/* 0CC214 7F0976E4 3C014080 */  li    $at, 0x40800000 # 4.000000
/* 0CC218 7F0976E8 44813000 */  mtc1  $at, $f6
/* 0CC21C 7F0976EC C4480038 */  lwc1  $f8, 0x38($v0)
/* 0CC220 7F0976F0 C7B2003C */  lwc1  $f18, 0x3c($sp)
/* 0CC224 7F0976F4 8FA3008C */  lw    $v1, 0x8c($sp)
/* 0CC228 7F0976F8 46064102 */  mul.s $f4, $f8, $f6
/* 0CC22C 7F0976FC 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0CC230 7F097700 46049281 */  sub.s $f10, $f18, $f4
/* 0CC234 7F097704 E46A002C */  swc1  $f10, 0x2c($v1)
/* 0CC238 7F097708 C7A80040 */  lwc1  $f8, 0x40($sp)
/* 0CC23C 7F09770C E4740034 */  swc1  $f20, 0x34($v1)
/* 0CC240 7F097710 E4680030 */  swc1  $f8, 0x30($v1)
/* 0CC244 7F097714 920F0014 */  lbu   $t7, 0x14($s0)
/* 0CC248 7F097718 448F3000 */  mtc1  $t7, $f6
/* 0CC24C 7F09771C 05E10004 */  bgez  $t7, .L7F097730
/* 0CC250 7F097720 468034A0 */   cvt.s.w $f18, $f6
/* 0CC254 7F097724 44812000 */  mtc1  $at, $f4
/* 0CC258 7F097728 00000000 */  nop   
/* 0CC25C 7F09772C 46049480 */  add.s $f18, $f18, $f4
.L7F097730:
/* 0CC260 7F097730 E4720010 */  swc1  $f18, 0x10($v1)
/* 0CC264 7F097734 92180015 */  lbu   $t8, 0x15($s0)
/* 0CC268 7F097738 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0CC26C 7F09773C 44985000 */  mtc1  $t8, $f10
/* 0CC270 7F097740 07010004 */  bgez  $t8, .L7F097754
/* 0CC274 7F097744 46805220 */   cvt.s.w $f8, $f10
/* 0CC278 7F097748 44813000 */  mtc1  $at, $f6
/* 0CC27C 7F09774C 00000000 */  nop   
/* 0CC280 7F097750 46064200 */  add.s $f8, $f8, $f6
.L7F097754:
/* 0CC284 7F097754 E4680014 */  swc1  $f8, 0x14($v1)
/* 0CC288 7F097758 92190016 */  lbu   $t9, 0x16($s0)
/* 0CC28C 7F09775C 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0CC290 7F097760 44992000 */  mtc1  $t9, $f4
/* 0CC294 7F097764 07210004 */  bgez  $t9, .L7F097778
/* 0CC298 7F097768 468024A0 */   cvt.s.w $f18, $f4
/* 0CC29C 7F09776C 44815000 */  mtc1  $at, $f10
/* 0CC2A0 7F097770 00000000 */  nop   
/* 0CC2A4 7F097774 460A9480 */  add.s $f18, $f18, $f10
.L7F097778:
/* 0CC2A8 7F097778 E4720018 */  swc1  $f18, 0x18($v1)
/* 0CC2AC 7F09777C 92080017 */  lbu   $t0, 0x17($s0)
/* 0CC2B0 7F097780 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0CC2B4 7F097784 44883000 */  mtc1  $t0, $f6
/* 0CC2B8 7F097788 05010004 */  bgez  $t0, .L7F09779C
/* 0CC2BC 7F09778C 46803220 */   cvt.s.w $f8, $f6
/* 0CC2C0 7F097790 44812000 */  mtc1  $at, $f4
/* 0CC2C4 7F097794 00000000 */  nop   
/* 0CC2C8 7F097798 46044200 */  add.s $f8, $f8, $f4
.L7F09779C:
/* 0CC2CC 7F09779C E468001C */  swc1  $f8, 0x1c($v1)
/* 0CC2D0 7F0977A0 8FBF0024 */  lw    $ra, 0x24($sp)
/* 0CC2D4 7F0977A4 8FB00020 */  lw    $s0, 0x20($sp)
/* 0CC2D8 7F0977A8 D7B40018 */  ldc1  $f20, 0x18($sp)
/* 0CC2DC 7F0977AC 03E00008 */  jr    $ra
/* 0CC2E0 7F0977B0 27BD0078 */   addiu $sp, $sp, 0x78
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0977B4(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0977B4
/* 0CC2E4 7F0977B4 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0CC2E8 7F0977B8 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0CC2EC 7F0977BC C4A60028 */  lwc1  $f6, 0x28($a1)
/* 0CC2F0 7F0977C0 C4840028 */  lwc1  $f4, 0x28($a0)
/* 0CC2F4 7F0977C4 C4AA002C */  lwc1  $f10, 0x2c($a1)
/* 0CC2F8 7F0977C8 C488002C */  lwc1  $f8, 0x2c($a0)
/* 0CC2FC 7F0977CC 46062001 */  sub.s $f0, $f4, $f6
/* 0CC300 7F0977D0 460A4081 */  sub.s $f2, $f8, $f10
/* 0CC304 7F0977D4 46000402 */  mul.s $f16, $f0, $f0
/* 0CC308 7F0977D8 00000000 */  nop   
/* 0CC30C 7F0977DC 46021482 */  mul.s $f18, $f2, $f2
/* 0CC310 7F0977E0 0C007DF8 */  jal   sqrtf
/* 0CC314 7F0977E4 46128300 */   add.s $f12, $f16, $f18
/* 0CC318 7F0977E8 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0CC31C 7F0977EC 44812000 */  mtc1  $at, $f4
/* 0CC320 7F0977F0 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0CC324 7F0977F4 27BD0018 */  addiu $sp, $sp, 0x18
/* 0CC328 7F0977F8 4604003C */  c.lt.s $f0, $f4
/* 0CC32C 7F0977FC 00001825 */  move  $v1, $zero
/* 0CC330 7F097800 45000003 */  bc1f  .L7F097810
/* 0CC334 7F097804 00000000 */   nop   
/* 0CC338 7F097808 10000001 */  b     .L7F097810
/* 0CC33C 7F09780C 24030001 */   li    $v1, 1
.L7F097810:
/* 0CC340 7F097810 03E00008 */  jr    $ra
/* 0CC344 7F097814 00601025 */   move  $v0, $v1
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F097818(void) {

}
#else
GLOBAL_ASM(
.late_rodata
glabel D_800575E8
.word 0xc4eac000 /*-1878.0*/
glabel D_800575EC
.word 0xc4eac000 /*-1878.0*/
glabel D_800575F0
.word 0xc4eac000 /*-1878.0*/
glabel D_800575F4
.word 0x46fffe00 /*32767.0*/
.text
glabel sub_GAME_7F097818
/* 0CC348 7F097818 27BDFB78 */  addiu $sp, $sp, -0x488
/* 0CC34C 7F09781C AFB00020 */  sw    $s0, 0x20($sp)
/* 0CC350 7F097820 00808025 */  move  $s0, $a0
/* 0CC354 7F097824 AFBF0024 */  sw    $ra, 0x24($sp)
/* 0CC358 7F097828 AFA5048C */  sw    $a1, 0x48c($sp)
/* 0CC35C 7F09782C 00A02025 */  move  $a0, $a1
/* 0CC360 7F097830 F7B40018 */  sdc1  $f20, 0x18($sp)
/* 0CC364 7F097834 00C02825 */  move  $a1, $a2
/* 0CC368 7F097838 AFA60490 */  sw    $a2, 0x490($sp)
/* 0CC36C 7F09783C 0FC25DED */  jal   sub_GAME_7F0977B4
/* 0CC370 7F097840 AFA70494 */   sw    $a3, 0x494($sp)
/* 0CC374 7F097844 8FA60490 */  lw    $a2, 0x490($sp)
/* 0CC378 7F097848 14400013 */  bnez  $v0, .L7F097898
/* 0CC37C 7F09784C 8FA70494 */   lw    $a3, 0x494($sp)
/* 0CC380 7F097850 00C02025 */  move  $a0, $a2
/* 0CC384 7F097854 00E02825 */  move  $a1, $a3
/* 0CC388 7F097858 AFA60490 */  sw    $a2, 0x490($sp)
/* 0CC38C 7F09785C 0FC25DED */  jal   sub_GAME_7F0977B4
/* 0CC390 7F097860 AFA70494 */   sw    $a3, 0x494($sp)
/* 0CC394 7F097864 8FAF048C */  lw    $t7, 0x48c($sp)
/* 0CC398 7F097868 8FA60490 */  lw    $a2, 0x490($sp)
/* 0CC39C 7F09786C 1440000A */  bnez  $v0, .L7F097898
/* 0CC3A0 7F097870 8FA70494 */   lw    $a3, 0x494($sp)
/* 0CC3A4 7F097874 00E02025 */  move  $a0, $a3
/* 0CC3A8 7F097878 01E02825 */  move  $a1, $t7
/* 0CC3AC 7F09787C AFA60490 */  sw    $a2, 0x490($sp)
/* 0CC3B0 7F097880 0FC25DED */  jal   sub_GAME_7F0977B4
/* 0CC3B4 7F097884 AFA70494 */   sw    $a3, 0x494($sp)
/* 0CC3B8 7F097888 8FA3048C */  lw    $v1, 0x48c($sp)
/* 0CC3BC 7F09788C 8FA60490 */  lw    $a2, 0x490($sp)
/* 0CC3C0 7F097890 10400003 */  beqz  $v0, .L7F0978A0
/* 0CC3C4 7F097894 8FA70494 */   lw    $a3, 0x494($sp)
.L7F097898:
/* 0CC3C8 7F097898 1000045F */  b     .L7F098A18
/* 0CC3CC 7F09789C 02001025 */   move  $v0, $s0
.L7F0978A0:
/* 0CC3D0 7F0978A0 3C014780 */  li    $at, 0x47800000 # 65536.000000
/* 0CC3D4 7F0978A4 44812000 */  mtc1  $at, $f4
/* 0CC3D8 7F0978A8 C7A80498 */  lwc1  $f8, 0x498($sp)
/* 0CC3DC 7F0978AC 4480A000 */  mtc1  $zero, $f20
/* 0CC3E0 7F0978B0 46044183 */  div.s $f6, $f8, $f4
/* 0CC3E4 7F0978B4 E7A60378 */  swc1  $f6, 0x378($sp)
/* 0CC3E8 7F0978B8 C4C8002C */  lwc1  $f8, 0x2c($a2)
/* 0CC3EC 7F0978BC C4CA0028 */  lwc1  $f10, 0x28($a2)
/* 0CC3F0 7F0978C0 C4600028 */  lwc1  $f0, 0x28($v1)
/* 0CC3F4 7F0978C4 E7A8005C */  swc1  $f8, 0x5c($sp)
/* 0CC3F8 7F0978C8 C4E60028 */  lwc1  $f6, 0x28($a3)
/* 0CC3FC 7F0978CC 46005301 */  sub.s $f12, $f10, $f0
/* 0CC400 7F0978D0 C46E002C */  lwc1  $f14, 0x2c($v1)
/* 0CC404 7F0978D4 C7A4005C */  lwc1  $f4, 0x5c($sp)
/* 0CC408 7F0978D8 46003281 */  sub.s $f10, $f6, $f0
/* 0CC40C 7F0978DC 460E2401 */  sub.s $f16, $f4, $f14
/* 0CC410 7F0978E0 E7AA046C */  swc1  $f10, 0x46c($sp)
/* 0CC414 7F0978E4 C4E8002C */  lwc1  $f8, 0x2c($a3)
/* 0CC418 7F0978E8 C7A6046C */  lwc1  $f6, 0x46c($sp)
/* 0CC41C 7F0978EC E7A80054 */  swc1  $f8, 0x54($sp)
/* 0CC420 7F0978F0 C7A40054 */  lwc1  $f4, 0x54($sp)
/* 0CC424 7F0978F4 46103282 */  mul.s $f10, $f6, $f16
/* 0CC428 7F0978F8 44813000 */  mtc1  $at, $f6
/* 0CC42C 7F0978FC 460E2481 */  sub.s $f18, $f4, $f14
/* 0CC430 7F097900 46126202 */  mul.s $f8, $f12, $f18
/* 0CC434 7F097904 46085101 */  sub.s $f4, $f10, $f8
/* 0CC438 7F097908 C7A8005C */  lwc1  $f8, 0x5c($sp)
/* 0CC43C 7F09790C 46062083 */  div.s $f2, $f4, $f6
/* 0CC440 7F097910 4602A032 */  c.eq.s $f20, $f2
/* 0CC444 7F097914 E7A20444 */  swc1  $f2, 0x444($sp)
/* 0CC448 7F097918 45020004 */  bc1fl .L7F09792C
/* 0CC44C 7F09791C 460E403C */   c.lt.s $f8, $f14
/* 0CC450 7F097920 1000043D */  b     .L7F098A18
/* 0CC454 7F097924 02001025 */   move  $v0, $s0
/* 0CC458 7F097928 460E403C */  c.lt.s $f8, $f14
.L7F09792C:
/* 0CC45C 7F09792C 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0CC460 7F097930 44815000 */  mtc1  $at, $f10
/* 0CC464 7F097934 00604825 */  move  $t1, $v1
/* 0CC468 7F097938 00C04025 */  move  $t0, $a2
/* 0CC46C 7F09793C 00E05825 */  move  $t3, $a3
/* 0CC470 7F097940 45000009 */  bc1f  .L7F097968
/* 0CC474 7F097944 46025403 */   div.s $f16, $f10, $f2
/* 0CC478 7F097948 3C01BF80 */  li    $at, 0xBF800000 # -1.000000
/* 0CC47C 7F09794C 44816000 */  mtc1  $at, $f12
/* 0CC480 7F097950 00604025 */  move  $t0, $v1
/* 0CC484 7F097954 00C04825 */  move  $t1, $a2
/* 0CC488 7F097958 460C1382 */  mul.s $f14, $f2, $f12
/* 0CC48C 7F09795C E7AE0444 */  swc1  $f14, 0x444($sp)
/* 0CC490 7F097960 460C8402 */  mul.s $f16, $f16, $f12
/* 0CC494 7F097964 00000000 */  nop   
.L7F097968:
/* 0CC498 7F097968 C500002C */  lwc1  $f0, 0x2c($t0)
/* 0CC49C 7F09796C C7A40054 */  lwc1  $f4, 0x54($sp)
/* 0CC4A0 7F097970 3C01BF80 */  li    $at, 0xBF800000 # -1.000000
/* 0CC4A4 7F097974 44816000 */  mtc1  $at, $f12
/* 0CC4A8 7F097978 4600203C */  c.lt.s $f4, $f0
/* 0CC4AC 7F09797C C7AE0444 */  lwc1  $f14, 0x444($sp)
/* 0CC4B0 7F097980 3C013E80 */  li    $at, 0x3E800000 # 0.250000
/* 0CC4B4 7F097984 45020007 */  bc1fl .L7F0979A4
/* 0CC4B8 7F097988 E7AE0444 */   swc1  $f14, 0x444($sp)
/* 0CC4BC 7F09798C 460C7382 */  mul.s $f14, $f14, $f12
/* 0CC4C0 7F097990 01005825 */  move  $t3, $t0
/* 0CC4C4 7F097994 00E04025 */  move  $t0, $a3
/* 0CC4C8 7F097998 460C8402 */  mul.s $f16, $f16, $f12
/* 0CC4CC 7F09799C C4E0002C */  lwc1  $f0, 0x2c($a3)
/* 0CC4D0 7F0979A0 E7AE0444 */  swc1  $f14, 0x444($sp)
.L7F0979A4:
/* 0CC4D4 7F0979A4 E7B00440 */  swc1  $f16, 0x440($sp)
/* 0CC4D8 7F0979A8 C526002C */  lwc1  $f6, 0x2c($t1)
/* 0CC4DC 7F0979AC 4606003C */  c.lt.s $f0, $f6
/* 0CC4E0 7F0979B0 44810000 */  mtc1  $at, $f0
/* 0CC4E4 7F0979B4 3C014080 */  li    $at, 0x40800000 # 4.000000
/* 0CC4E8 7F0979B8 44811000 */  mtc1  $at, $f2
/* 0CC4EC 7F0979BC 45000008 */  bc1f  .L7F0979E0
/* 0CC4F0 7F0979C0 3C013E80 */   li    $at, 0x3E800000 # 0.250000
/* 0CC4F4 7F0979C4 460C7382 */  mul.s $f14, $f14, $f12
/* 0CC4F8 7F0979C8 01001025 */  move  $v0, $t0
/* 0CC4FC 7F0979CC 01204025 */  move  $t0, $t1
/* 0CC500 7F0979D0 460C8402 */  mul.s $f16, $f16, $f12
/* 0CC504 7F0979D4 00404825 */  move  $t1, $v0
/* 0CC508 7F0979D8 E7AE0444 */  swc1  $f14, 0x444($sp)
/* 0CC50C 7F0979DC E7B00440 */  swc1  $f16, 0x440($sp)
.L7F0979E0:
/* 0CC510 7F0979E0 C50A0028 */  lwc1  $f10, 0x28($t0)
/* 0CC514 7F0979E4 44814000 */  mtc1  $at, $f8
/* 0CC518 7F0979E8 E7B40424 */  swc1  $f20, 0x424($sp)
/* 0CC51C 7F0979EC 3C0644EA */  lui   $a2, (0x44EAA000 >> 16) # lui $a2, 0x44ea
/* 0CC520 7F0979F0 46085102 */  mul.s $f4, $f10, $f8
/* 0CC524 7F0979F4 44815000 */  mtc1  $at, $f10
/* 0CC528 7F0979F8 34C6A000 */  ori   $a2, (0x44EAA000 & 0xFFFF) # ori $a2, $a2, 0xa000
/* 0CC52C 7F0979FC E7A40420 */  swc1  $f4, 0x420($sp)
/* 0CC530 7F097A00 C5260028 */  lwc1  $f6, 0x28($t1)
/* 0CC534 7F097A04 E7B4042C */  swc1  $f20, 0x42c($sp)
/* 0CC538 7F097A08 460A3202 */  mul.s $f8, $f6, $f10
/* 0CC53C 7F097A0C 44813000 */  mtc1  $at, $f6
/* 0CC540 7F097A10 3C018005 */  lui   $at, %hi(D_800575E8)
/* 0CC544 7F097A14 E7A80428 */  swc1  $f8, 0x428($sp)
/* 0CC548 7F097A18 C5240028 */  lwc1  $f4, 0x28($t1)
/* 0CC54C 7F097A1C E7B40434 */  swc1  $f20, 0x434($sp)
/* 0CC550 7F097A20 E7B4043C */  swc1  $f20, 0x43c($sp)
/* 0CC554 7F097A24 46062282 */  mul.s $f10, $f4, $f6
/* 0CC558 7F097A28 E7B40438 */  swc1  $f20, 0x438($sp)
/* 0CC55C 7F097A2C E7AA0430 */  swc1  $f10, 0x430($sp)
/* 0CC560 7F097A30 C5680028 */  lwc1  $f8, 0x28($t3)
/* 0CC564 7F097A34 E7A80448 */  swc1  $f8, 0x448($sp)
/* 0CC568 7F097A38 C564002C */  lwc1  $f4, 0x2c($t3)
/* 0CC56C 7F097A3C E7A4044C */  swc1  $f4, 0x44c($sp)
/* 0CC570 7F097A40 C5060028 */  lwc1  $f6, 0x28($t0)
/* 0CC574 7F097A44 E7A60450 */  swc1  $f6, 0x450($sp)
/* 0CC578 7F097A48 C50A002C */  lwc1  $f10, 0x2c($t0)
/* 0CC57C 7F097A4C C7A60450 */  lwc1  $f6, 0x450($sp)
/* 0CC580 7F097A50 E7AA0454 */  swc1  $f10, 0x454($sp)
/* 0CC584 7F097A54 C5280028 */  lwc1  $f8, 0x28($t1)
/* 0CC588 7F097A58 E7A80458 */  swc1  $f8, 0x458($sp)
/* 0CC58C 7F097A5C C7AA0458 */  lwc1  $f10, 0x458($sp)
/* 0CC590 7F097A60 C524002C */  lwc1  $f4, 0x2c($t1)
/* 0CC594 7F097A64 E7A60028 */  swc1  $f6, 0x28($sp)
/* 0CC598 7F097A68 460A3201 */  sub.s $f8, $f6, $f10
/* 0CC59C 7F097A6C E7A4045C */  swc1  $f4, 0x45c($sp)
/* 0CC5A0 7F097A70 C7A40454 */  lwc1  $f4, 0x454($sp)
/* 0CC5A4 7F097A74 C7A6045C */  lwc1  $f6, 0x45c($sp)
/* 0CC5A8 7F097A78 E7A80474 */  swc1  $f8, 0x474($sp)
/* 0CC5AC 7F097A7C E7A80030 */  swc1  $f8, 0x30($sp)
/* 0CC5B0 7F097A80 E7AA002C */  swc1  $f10, 0x2c($sp)
/* 0CC5B4 7F097A84 C7A8002C */  lwc1  $f8, 0x2c($sp)
/* 0CC5B8 7F097A88 46062401 */  sub.s $f16, $f4, $f6
/* 0CC5BC 7F097A8C E7A4002C */  swc1  $f4, 0x2c($sp)
/* 0CC5C0 7F097A90 C7A4044C */  lwc1  $f4, 0x44c($sp)
/* 0CC5C4 7F097A94 C7AA0448 */  lwc1  $f10, 0x448($sp)
/* 0CC5C8 7F097A98 E7B403FC */  swc1  $f20, 0x3fc($sp)
/* 0CC5CC 7F097A9C 46062481 */  sub.s $f18, $f4, $f6
/* 0CC5D0 7F097AA0 C7A60028 */  lwc1  $f6, 0x28($sp)
/* 0CC5D4 7F097AA4 E7B403F8 */  swc1  $f20, 0x3f8($sp)
/* 0CC5D8 7F097AA8 46085201 */  sub.s $f8, $f10, $f8
/* 0CC5DC 7F097AAC E7B403DC */  swc1  $f20, 0x3dc($sp)
/* 0CC5E0 7F097AB0 E7B403D8 */  swc1  $f20, 0x3d8($sp)
/* 0CC5E4 7F097AB4 46065301 */  sub.s $f12, $f10, $f6
/* 0CC5E8 7F097AB8 C7AA002C */  lwc1  $f10, 0x2c($sp)
/* 0CC5EC 7F097ABC E7A8046C */  swc1  $f8, 0x46c($sp)
/* 0CC5F0 7F097AC0 E7B403A0 */  swc1  $f20, 0x3a0($sp)
/* 0CC5F4 7F097AC4 46006182 */  mul.s $f6, $f12, $f0
/* 0CC5F8 7F097AC8 460A2381 */  sub.s $f14, $f4, $f10
/* 0CC5FC 7F097ACC C7AA0030 */  lwc1  $f10, 0x30($sp)
/* 0CC600 7F097AD0 E7AC0464 */  swc1  $f12, 0x464($sp)
/* 0CC604 7F097AD4 E7B403A8 */  swc1  $f20, 0x3a8($sp)
/* 0CC608 7F097AD8 46007102 */  mul.s $f4, $f14, $f0
/* 0CC60C 7F097ADC E7AE0460 */  swc1  $f14, 0x460($sp)
/* 0CC610 7F097AE0 E7A603E0 */  swc1  $f6, 0x3e0($sp)
/* 0CC614 7F097AE4 46005182 */  mul.s $f6, $f10, $f0
/* 0CC618 7F097AE8 E7B403B0 */  swc1  $f20, 0x3b0($sp)
/* 0CC61C 7F097AEC E7B403BC */  swc1  $f20, 0x3bc($sp)
/* 0CC620 7F097AF0 E7B403B8 */  swc1  $f20, 0x3b8($sp)
/* 0CC624 7F097AF4 E7A403E4 */  swc1  $f4, 0x3e4($sp)
/* 0CC628 7F097AF8 46008102 */  mul.s $f4, $f16, $f0
/* 0CC62C 7F097AFC E7B40380 */  swc1  $f20, 0x380($sp)
/* 0CC630 7F097B00 E7A603E8 */  swc1  $f6, 0x3e8($sp)
/* 0CC634 7F097B04 46004182 */  mul.s $f6, $f8, $f0
/* 0CC638 7F097B08 E7B40388 */  swc1  $f20, 0x388($sp)
/* 0CC63C 7F097B0C E7B40390 */  swc1  $f20, 0x390($sp)
/* 0CC640 7F097B10 E7B4039C */  swc1  $f20, 0x39c($sp)
/* 0CC644 7F097B14 E7A403EC */  swc1  $f4, 0x3ec($sp)
/* 0CC648 7F097B18 46009102 */  mul.s $f4, $f18, $f0
/* 0CC64C 7F097B1C C7A00460 */  lwc1  $f0, 0x460($sp)
/* 0CC650 7F097B20 E7A603F0 */  swc1  $f6, 0x3f0($sp)
/* 0CC654 7F097B24 46026182 */  mul.s $f6, $f12, $f2
/* 0CC658 7F097B28 E7B40398 */  swc1  $f20, 0x398($sp)
/* 0CC65C 7F097B2C AFAB047C */  sw    $t3, 0x47c($sp)
/* 0CC660 7F097B30 AFA90484 */  sw    $t1, 0x484($sp)
/* 0CC664 7F097B34 E7A403F4 */  swc1  $f4, 0x3f4($sp)
/* 0CC668 7F097B38 46027102 */  mul.s $f4, $f14, $f2
/* 0CC66C 7F097B3C C42E75E8 */  lwc1  $f14, %lo(D_800575E8)($at)
/* 0CC670 7F097B40 E7A603C0 */  swc1  $f6, 0x3c0($sp)
/* 0CC674 7F097B44 46025182 */  mul.s $f6, $f10, $f2
/* 0CC678 7F097B48 AFA80480 */  sw    $t0, 0x480($sp)
/* 0CC67C 7F097B4C E7A403C4 */  swc1  $f4, 0x3c4($sp)
/* 0CC680 7F097B50 46028102 */  mul.s $f4, $f16, $f2
/* 0CC684 7F097B54 E7A603C8 */  swc1  $f6, 0x3c8($sp)
/* 0CC688 7F097B58 46024182 */  mul.s $f6, $f8, $f2
/* 0CC68C 7F097B5C E7A403CC */  swc1  $f4, 0x3cc($sp)
/* 0CC690 7F097B60 46029102 */  mul.s $f4, $f18, $f2
/* 0CC694 7F097B64 E7A603D0 */  swc1  $f6, 0x3d0($sp)
/* 0CC698 7F097B68 46001183 */  div.s $f6, $f2, $f0
/* 0CC69C 7F097B6C E7A403D4 */  swc1  $f4, 0x3d4($sp)
/* 0CC6A0 7F097B70 46101103 */  div.s $f4, $f2, $f16
/* 0CC6A4 7F097B74 E7A603A4 */  swc1  $f6, 0x3a4($sp)
/* 0CC6A8 7F097B78 46121183 */  div.s $f6, $f2, $f18
/* 0CC6AC 7F097B7C E7A403AC */  swc1  $f4, 0x3ac($sp)
/* 0CC6B0 7F097B80 C7A40464 */  lwc1  $f4, 0x464($sp)
/* 0CC6B4 7F097B84 46002303 */  div.s $f12, $f4, $f0
/* 0CC6B8 7F097B88 E7A603B4 */  swc1  $f6, 0x3b4($sp)
/* 0CC6BC 7F097B8C 46124103 */  div.s $f4, $f8, $f18
/* 0CC6C0 7F097B90 E7AC0384 */  swc1  $f12, 0x384($sp)
/* 0CC6C4 7F097B94 46105183 */  div.s $f6, $f10, $f16
/* 0CC6C8 7F097B98 E7A40394 */  swc1  $f4, 0x394($sp)
/* 0CC6CC 7F097B9C 0FC24F12 */  jal   sub_GAME_7F093C48
/* 0CC6D0 7F097BA0 E7A6038C */   swc1  $f6, 0x38c($sp)
/* 0CC6D4 7F097BA4 3C018005 */  lui   $at, %hi(D_800575EC)
/* 0CC6D8 7F097BA8 3C0644EA */  lui   $a2, (0x44EAA000 >> 16) # lui $a2, 0x44ea
/* 0CC6DC 7F097BAC E7A00384 */  swc1  $f0, 0x384($sp)
/* 0CC6E0 7F097BB0 34C6A000 */  ori   $a2, (0x44EAA000 & 0xFFFF) # ori $a2, $a2, 0xa000
/* 0CC6E4 7F097BB4 C42E75EC */  lwc1  $f14, %lo(D_800575EC)($at)
/* 0CC6E8 7F097BB8 0FC24F12 */  jal   sub_GAME_7F093C48
/* 0CC6EC 7F097BBC C7AC038C */   lwc1  $f12, 0x38c($sp)
/* 0CC6F0 7F097BC0 3C018005 */  lui   $at, %hi(D_800575F0)
/* 0CC6F4 7F097BC4 3C0644EA */  lui   $a2, (0x44EAA000 >> 16) # lui $a2, 0x44ea
/* 0CC6F8 7F097BC8 E7A0038C */  swc1  $f0, 0x38c($sp)
/* 0CC6FC 7F097BCC 34C6A000 */  ori   $a2, (0x44EAA000 & 0xFFFF) # ori $a2, $a2, 0xa000
/* 0CC700 7F097BD0 C42E75F0 */  lwc1  $f14, %lo(D_800575F0)($at)
/* 0CC704 7F097BD4 0FC24F12 */  jal   sub_GAME_7F093C48
/* 0CC708 7F097BD8 C7AC0394 */   lwc1  $f12, 0x394($sp)
/* 0CC70C 7F097BDC 8FA90484 */  lw    $t1, 0x484($sp)
/* 0CC710 7F097BE0 E7A00394 */  swc1  $f0, 0x394($sp)
/* 0CC714 7F097BE4 3C013E80 */  li    $at, 0x3E800000 # 0.250000
/* 0CC718 7F097BE8 44813000 */  mtc1  $at, $f6
/* 0CC71C 7F097BEC C52A002C */  lwc1  $f10, 0x2c($t1)
/* 0CC720 7F097BF0 3C014600 */  li    $at, 0x46000000 # 8192.000000
/* 0CC724 7F097BF4 46065082 */  mul.s $f2, $f10, $f6
/* 0CC728 7F097BF8 4600120D */  trunc.w.s $f8, $f2
/* 0CC72C 7F097BFC 44194000 */  mfc1  $t9, $f8
/* 0CC730 7F097C00 C7A8038C */  lwc1  $f8, 0x38c($sp)
/* 0CC734 7F097C04 44992000 */  mtc1  $t9, $f4
/* 0CC738 7F097C08 00000000 */  nop   
/* 0CC73C 7F097C0C 468022A0 */  cvt.s.w $f10, $f4
/* 0CC740 7F097C10 44812000 */  mtc1  $at, $f4
/* 0CC744 7F097C14 00000000 */  nop   
/* 0CC748 7F097C18 46044302 */  mul.s $f12, $f8, $f4
/* 0CC74C 7F097C1C 460A1181 */  sub.s $f6, $f2, $f10
/* 0CC750 7F097C20 0FC24F22 */  jal   addpoint5tofloat
/* 0CC754 7F097C24 E7A6037C */   swc1  $f6, 0x37c($sp)
/* 0CC758 7F097C28 3C013900 */  li    $at, 0x39000000 # 0.000122
/* 0CC75C 7F097C2C 44815000 */  mtc1  $at, $f10
/* 0CC760 7F097C30 C7A8037C */  lwc1  $f8, 0x37c($sp)
/* 0CC764 7F097C34 3C014600 */  li    $at, 0x46000000 # 8192.000000
/* 0CC768 7F097C38 460A0182 */  mul.s $f6, $f0, $f10
/* 0CC76C 7F097C3C C7AA0428 */  lwc1  $f10, 0x428($sp)
/* 0CC770 7F097C40 46083102 */  mul.s $f4, $f6, $f8
/* 0CC774 7F097C44 C7A80394 */  lwc1  $f8, 0x394($sp)
/* 0CC778 7F097C48 46045181 */  sub.s $f6, $f10, $f4
/* 0CC77C 7F097C4C 44815000 */  mtc1  $at, $f10
/* 0CC780 7F097C50 00000000 */  nop   
/* 0CC784 7F097C54 460A4302 */  mul.s $f12, $f8, $f10
/* 0CC788 7F097C58 0FC24F22 */  jal   addpoint5tofloat
/* 0CC78C 7F097C5C E7A60408 */   swc1  $f6, 0x408($sp)
/* 0CC790 7F097C60 3C013900 */  li    $at, 0x39000000 # 0.000122
/* 0CC794 7F097C64 44812000 */  mtc1  $at, $f4
/* 0CC798 7F097C68 C7A8037C */  lwc1  $f8, 0x37c($sp)
/* 0CC79C 7F097C6C 3C07B400 */  lui   $a3, 0xb400
/* 0CC7A0 7F097C70 46040182 */  mul.s $f6, $f0, $f4
/* 0CC7A4 7F097C74 C7A40430 */  lwc1  $f4, 0x430($sp)
/* 0CC7A8 7F097C78 8FA80480 */  lw    $t0, 0x480($sp)
/* 0CC7AC 7F097C7C 8FA90484 */  lw    $t1, 0x484($sp)
/* 0CC7B0 7F097C80 8FAB047C */  lw    $t3, 0x47c($sp)
/* 0CC7B4 7F097C84 02002825 */  move  $a1, $s0
/* 0CC7B8 7F097C88 26100008 */  addiu $s0, $s0, 8
/* 0CC7BC 7F097C8C 46083282 */  mul.s $f10, $f6, $f8
/* 0CC7C0 7F097C90 3C06C800 */  lui   $a2, 0xc800
/* 0CC7C4 7F097C94 00001825 */  move  $v1, $zero
/* 0CC7C8 7F097C98 460A2181 */  sub.s $f6, $f4, $f10
/* 0CC7CC 7F097C9C E7A60410 */  swc1  $f6, 0x410($sp)
/* 0CC7D0 7F097CA0 ACA70000 */  sw    $a3, ($a1)
/* 0CC7D4 7F097CA4 8FB8049C */  lw    $t8, 0x49c($sp)
/* 0CC7D8 7F097CA8 C7A80444 */  lwc1  $f8, 0x444($sp)
/* 0CC7DC 7F097CAC 13000003 */  beqz  $t8, .L7F097CBC
/* 0CC7E0 7F097CB0 00000000 */   nop   
/* 0CC7E4 7F097CB4 10000001 */  b     .L7F097CBC
/* 0CC7E8 7F097CB8 3C06CE00 */   lui   $a2, 0xce00
.L7F097CBC:
/* 0CC7EC 7F097CBC 4614403C */  c.lt.s $f8, $f20
/* 0CC7F0 7F097CC0 00000000 */  nop   
/* 0CC7F4 7F097CC4 45000003 */  bc1f  .L7F097CD4
/* 0CC7F8 7F097CC8 00000000 */   nop   
/* 0CC7FC 7F097CCC 10000001 */  b     .L7F097CD4
/* 0CC800 7F097CD0 3C030080 */   lui   $v1, 0x80
.L7F097CD4:
/* 0CC804 7F097CD4 C564002C */  lwc1  $f4, 0x2c($t3)
/* 0CC808 7F097CD8 00667825 */  or    $t7, $v1, $a2
/* 0CC80C 7F097CDC 02001025 */  move  $v0, $s0
/* 0CC810 7F097CE0 4600228D */  trunc.w.s $f10, $f4
/* 0CC814 7F097CE4 3C0EB200 */  lui   $t6, 0xb200
/* 0CC818 7F097CE8 26100008 */  addiu $s0, $s0, 8
/* 0CC81C 7F097CEC 02002025 */  move  $a0, $s0
/* 0CC820 7F097CF0 44195000 */  mfc1  $t9, $f10
/* 0CC824 7F097CF4 3C013E80 */  li    $at, 0x3E800000 # 0.250000
/* 0CC828 7F097CF8 26100008 */  addiu $s0, $s0, 8
/* 0CC82C 7F097CFC 01F9C025 */  or    $t8, $t7, $t9
/* 0CC830 7F097D00 ACB80004 */  sw    $t8, 4($a1)
/* 0CC834 7F097D04 AC4E0000 */  sw    $t6, ($v0)
/* 0CC838 7F097D08 C506002C */  lwc1  $f6, 0x2c($t0)
/* 0CC83C 7F097D0C C524002C */  lwc1  $f4, 0x2c($t1)
/* 0CC840 7F097D10 4600320D */  trunc.w.s $f8, $f6
/* 0CC844 7F097D14 4600228D */  trunc.w.s $f10, $f4
/* 0CC848 7F097D18 44194000 */  mfc1  $t9, $f8
/* 0CC84C 7F097D1C 44814000 */  mtc1  $at, $f8
/* 0CC850 7F097D20 440F5000 */  mfc1  $t7, $f10
/* 0CC854 7F097D24 0019C400 */  sll   $t8, $t9, 0x10
/* 0CC858 7F097D28 030FC825 */  or    $t9, $t8, $t7
/* 0CC85C 7F097D2C AC590004 */  sw    $t9, 4($v0)
/* 0CC860 7F097D30 AC870000 */  sw    $a3, ($a0)
/* 0CC864 7F097D34 C5060028 */  lwc1  $f6, 0x28($t0)
/* 0CC868 7F097D38 AFAB047C */  sw    $t3, 0x47c($sp)
/* 0CC86C 7F097D3C AFA90484 */  sw    $t1, 0x484($sp)
/* 0CC870 7F097D40 46083302 */  mul.s $f12, $f6, $f8
/* 0CC874 7F097D44 AFA80480 */  sw    $t0, 0x480($sp)
/* 0CC878 7F097D48 0FC250A6 */  jal   sub_GAME_7F094298
/* 0CC87C 7F097D4C AFA40180 */   sw    $a0, 0x180($sp)
/* 0CC880 7F097D50 8FA40180 */  lw    $a0, 0x180($sp)
/* 0CC884 7F097D54 02001825 */  move  $v1, $s0
/* 0CC888 7F097D58 3C0EB200 */  lui   $t6, 0xb200
/* 0CC88C 7F097D5C AC820004 */  sw    $v0, 4($a0)
/* 0CC890 7F097D60 AC6E0000 */  sw    $t6, ($v1)
/* 0CC894 7F097D64 AFA3017C */  sw    $v1, 0x17c($sp)
/* 0CC898 7F097D68 C7AC0384 */  lwc1  $f12, 0x384($sp)
/* 0CC89C 7F097D6C 0FC250A6 */  jal   sub_GAME_7F094298
/* 0CC8A0 7F097D70 26100008 */   addiu $s0, $s0, 8
/* 0CC8A4 7F097D74 8FA3017C */  lw    $v1, 0x17c($sp)
/* 0CC8A8 7F097D78 02002025 */  move  $a0, $s0
/* 0CC8AC 7F097D7C 3C18B400 */  lui   $t8, 0xb400
/* 0CC8B0 7F097D80 AC620004 */  sw    $v0, 4($v1)
/* 0CC8B4 7F097D84 AC980000 */  sw    $t8, ($a0)
/* 0CC8B8 7F097D88 AFA40178 */  sw    $a0, 0x178($sp)
/* 0CC8BC 7F097D8C C7AC0410 */  lwc1  $f12, 0x410($sp)
/* 0CC8C0 7F097D90 0FC250A6 */  jal   sub_GAME_7F094298
/* 0CC8C4 7F097D94 26100008 */   addiu $s0, $s0, 8
/* 0CC8C8 7F097D98 8FA40178 */  lw    $a0, 0x178($sp)
/* 0CC8CC 7F097D9C 02001825 */  move  $v1, $s0
/* 0CC8D0 7F097DA0 3C0FB200 */  lui   $t7, 0xb200
/* 0CC8D4 7F097DA4 AC820004 */  sw    $v0, 4($a0)
/* 0CC8D8 7F097DA8 AC6F0000 */  sw    $t7, ($v1)
/* 0CC8DC 7F097DAC AFA30174 */  sw    $v1, 0x174($sp)
/* 0CC8E0 7F097DB0 C7AC0394 */  lwc1  $f12, 0x394($sp)
/* 0CC8E4 7F097DB4 0FC250A6 */  jal   sub_GAME_7F094298
/* 0CC8E8 7F097DB8 26100008 */   addiu $s0, $s0, 8
/* 0CC8EC 7F097DBC 8FA30174 */  lw    $v1, 0x174($sp)
/* 0CC8F0 7F097DC0 02002025 */  move  $a0, $s0
/* 0CC8F4 7F097DC4 3C19B400 */  lui   $t9, 0xb400
/* 0CC8F8 7F097DC8 AC620004 */  sw    $v0, 4($v1)
/* 0CC8FC 7F097DCC AC990000 */  sw    $t9, ($a0)
/* 0CC900 7F097DD0 AFA40170 */  sw    $a0, 0x170($sp)
/* 0CC904 7F097DD4 C7AC0408 */  lwc1  $f12, 0x408($sp)
/* 0CC908 7F097DD8 0FC250A6 */  jal   sub_GAME_7F094298
/* 0CC90C 7F097DDC 26100008 */   addiu $s0, $s0, 8
/* 0CC910 7F097DE0 8FA40170 */  lw    $a0, 0x170($sp)
/* 0CC914 7F097DE4 02001825 */  move  $v1, $s0
/* 0CC918 7F097DE8 3C0EB200 */  lui   $t6, 0xb200
/* 0CC91C 7F097DEC AC820004 */  sw    $v0, 4($a0)
/* 0CC920 7F097DF0 AC6E0000 */  sw    $t6, ($v1)
/* 0CC924 7F097DF4 AFA3016C */  sw    $v1, 0x16c($sp)
/* 0CC928 7F097DF8 C7AC038C */  lwc1  $f12, 0x38c($sp)
/* 0CC92C 7F097DFC 0FC250A6 */  jal   sub_GAME_7F094298
/* 0CC930 7F097E00 26100008 */   addiu $s0, $s0, 8
/* 0CC934 7F097E04 8FA3016C */  lw    $v1, 0x16c($sp)
/* 0CC938 7F097E08 8FA80480 */  lw    $t0, 0x480($sp)
/* 0CC93C 7F097E0C 8FA90484 */  lw    $t1, 0x484($sp)
/* 0CC940 7F097E10 8FAB047C */  lw    $t3, 0x47c($sp)
/* 0CC944 7F097E14 AC620004 */  sw    $v0, 4($v1)
/* 0CC948 7F097E18 8FB8049C */  lw    $t8, 0x49c($sp)
/* 0CC94C 7F097E1C C7A00378 */  lwc1  $f0, 0x378($sp)
/* 0CC950 7F097E20 3C018005 */  lui    $at, %hi(D_800575F4)
/* 0CC954 7F097E24 57000004 */  bnezl $t8, .L7F097E38
/* 0CC958 7F097E28 C524000C */   lwc1  $f4, 0xc($t1)
/* 0CC95C 7F097E2C 100002FA */  b     .L7F098A18
/* 0CC960 7F097E30 02001025 */   move  $v0, $s0
/* 0CC964 7F097E34 C524000C */  lwc1  $f4, 0xc($t1)
.L7F097E38:
/* 0CC968 7F097E38 46002282 */  mul.s $f10, $f4, $f0
/* 0CC96C 7F097E3C E7AA036C */  swc1  $f10, 0x36c($sp)
/* 0CC970 7F097E40 C506000C */  lwc1  $f6, 0xc($t0)
/* 0CC974 7F097E44 C7B2036C */  lwc1  $f18, 0x36c($sp)
/* 0CC978 7F097E48 46003202 */  mul.s $f8, $f6, $f0
/* 0CC97C 7F097E4C E7A80370 */  swc1  $f8, 0x370($sp)
/* 0CC980 7F097E50 C564000C */  lwc1  $f4, 0xc($t3)
/* 0CC984 7F097E54 C7A60370 */  lwc1  $f6, 0x370($sp)
/* 0CC988 7F097E58 46002282 */  mul.s $f10, $f4, $f0
/* 0CC98C 7F097E5C 4612303C */  c.lt.s $f6, $f18
/* 0CC990 7F097E60 E7AA0374 */  swc1  $f10, 0x374($sp)
/* 0CC994 7F097E64 45000002 */  bc1f  .L7F097E70
/* 0CC998 7F097E68 C7A00374 */   lwc1  $f0, 0x374($sp)
/* 0CC99C 7F097E6C 46003486 */  mov.s $f18, $f6
.L7F097E70:
/* 0CC9A0 7F097E70 4612003C */  c.lt.s $f0, $f18
/* 0CC9A4 7F097E74 00000000 */  nop   
/* 0CC9A8 7F097E78 45000002 */  bc1f  .L7F097E84
/* 0CC9AC 7F097E7C 00000000 */   nop   
/* 0CC9B0 7F097E80 46000486 */  mov.s $f18, $f0
.L7F097E84:
/* 0CC9B4 7F097E84 C42075F4 */  lwc1  $f0, %lo(D_800575F4)($at)
/* 0CC9B8 7F097E88 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 0CC9BC 7F097E8C 44811000 */  mtc1  $at, $f2
/* 0CC9C0 7F097E90 C5280034 */  lwc1  $f8, 0x34($t1)
/* 0CC9C4 7F097E94 46029482 */  mul.s $f18, $f18, $f2
/* 0CC9C8 7F097E98 00000000 */  nop   
/* 0CC9CC 7F097E9C 46124102 */  mul.s $f4, $f8, $f18
/* 0CC9D0 7F097EA0 E7A4035C */  swc1  $f4, 0x35c($sp)
/* 0CC9D4 7F097EA4 C50A0034 */  lwc1  $f10, 0x34($t0)
/* 0CC9D8 7F097EA8 46125182 */  mul.s $f6, $f10, $f18
/* 0CC9DC 7F097EAC C7AA035C */  lwc1  $f10, 0x35c($sp)
/* 0CC9E0 7F097EB0 E7A60360 */  swc1  $f6, 0x360($sp)
/* 0CC9E4 7F097EB4 C5680034 */  lwc1  $f8, 0x34($t3)
/* 0CC9E8 7F097EB8 46124102 */  mul.s $f4, $f8, $f18
/* 0CC9EC 7F097EBC E7A40364 */  swc1  $f4, 0x364($sp)
/* 0CC9F0 7F097EC0 C5260020 */  lwc1  $f6, 0x20($t1)
/* 0CC9F4 7F097EC4 46065202 */  mul.s $f8, $f10, $f6
/* 0CC9F8 7F097EC8 E7A80338 */  swc1  $f8, 0x338($sp)
/* 0CC9FC 7F097ECC C5240024 */  lwc1  $f4, 0x24($t1)
/* 0CCA00 7F097ED0 4608A03E */  c.le.s $f20, $f8
/* 0CCA04 7F097ED4 46045182 */  mul.s $f6, $f10, $f4
/* 0CCA08 7F097ED8 00000000 */  nop   
/* 0CCA0C 7F097EDC 46005102 */  mul.s $f4, $f10, $f0
/* 0CCA10 7F097EE0 E7A6033C */  swc1  $f6, 0x33c($sp)
/* 0CCA14 7F097EE4 C7A60360 */  lwc1  $f6, 0x360($sp)
/* 0CCA18 7F097EE8 E7A40340 */  swc1  $f4, 0x340($sp)
/* 0CCA1C 7F097EEC C50A0020 */  lwc1  $f10, 0x20($t0)
/* 0CCA20 7F097EF0 460A3102 */  mul.s $f4, $f6, $f10
/* 0CCA24 7F097EF4 E7A40344 */  swc1  $f4, 0x344($sp)
/* 0CCA28 7F097EF8 C50A0024 */  lwc1  $f10, 0x24($t0)
/* 0CCA2C 7F097EFC 460A3102 */  mul.s $f4, $f6, $f10
/* 0CCA30 7F097F00 00000000 */  nop   
/* 0CCA34 7F097F04 46003282 */  mul.s $f10, $f6, $f0
/* 0CCA38 7F097F08 E7A40348 */  swc1  $f4, 0x348($sp)
/* 0CCA3C 7F097F0C C7A40364 */  lwc1  $f4, 0x364($sp)
/* 0CCA40 7F097F10 E7AA034C */  swc1  $f10, 0x34c($sp)
/* 0CCA44 7F097F14 C5660020 */  lwc1  $f6, 0x20($t3)
/* 0CCA48 7F097F18 46062282 */  mul.s $f10, $f4, $f6
/* 0CCA4C 7F097F1C E7AA0350 */  swc1  $f10, 0x350($sp)
/* 0CCA50 7F097F20 C5660024 */  lwc1  $f6, 0x24($t3)
/* 0CCA54 7F097F24 46062282 */  mul.s $f10, $f4, $f6
/* 0CCA58 7F097F28 00000000 */  nop   
/* 0CCA5C 7F097F2C 46002182 */  mul.s $f6, $f4, $f0
/* 0CCA60 7F097F30 C7A0033C */  lwc1  $f0, 0x33c($sp)
/* 0CCA64 7F097F34 E7AA0354 */  swc1  $f10, 0x354($sp)
/* 0CCA68 7F097F38 45000003 */  bc1f  .L7F097F48
/* 0CCA6C 7F097F3C E7A60358 */   swc1  $f6, 0x358($sp)
/* 0CCA70 7F097F40 10000003 */  b     .L7F097F50
/* 0CCA74 7F097F44 46004386 */   mov.s $f14, $f8
.L7F097F48:
/* 0CCA78 7F097F48 C7AE0338 */  lwc1  $f14, 0x338($sp)
/* 0CCA7C 7F097F4C 46007387 */  neg.s $f14, $f14
.L7F097F50:
/* 0CCA80 7F097F50 4600A03E */  c.le.s $f20, $f0
/* 0CCA84 7F097F54 00000000 */  nop   
/* 0CCA88 7F097F58 45020004 */  bc1fl .L7F097F6C
/* 0CCA8C 7F097F5C 46000407 */   neg.s $f16, $f0
/* 0CCA90 7F097F60 10000002 */  b     .L7F097F6C
/* 0CCA94 7F097F64 46000406 */   mov.s $f16, $f0
/* 0CCA98 7F097F68 46000407 */  neg.s $f16, $f0
.L7F097F6C:
/* 0CCA9C 7F097F6C C7A00344 */  lwc1  $f0, 0x344($sp)
/* 0CCAA0 7F097F70 4600A03E */  c.le.s $f20, $f0
/* 0CCAA4 7F097F74 00000000 */  nop   
/* 0CCAA8 7F097F78 45020004 */  bc1fl .L7F097F8C
/* 0CCAAC 7F097F7C 46000307 */   neg.s $f12, $f0
/* 0CCAB0 7F097F80 10000002 */  b     .L7F097F8C
/* 0CCAB4 7F097F84 46000306 */   mov.s $f12, $f0
/* 0CCAB8 7F097F88 46000307 */  neg.s $f12, $f0
.L7F097F8C:
/* 0CCABC 7F097F8C 460C703C */  c.lt.s $f14, $f12
/* 0CCAC0 7F097F90 00000000 */  nop   
/* 0CCAC4 7F097F94 45020009 */  bc1fl .L7F097FBC
/* 0CCAC8 7F097F98 C7A00348 */   lwc1  $f0, 0x348($sp)
/* 0CCACC 7F097F9C 4600A03E */  c.le.s $f20, $f0
/* 0CCAD0 7F097FA0 00000000 */  nop   
/* 0CCAD4 7F097FA4 45020004 */  bc1fl .L7F097FB8
/* 0CCAD8 7F097FA8 46000387 */   neg.s $f14, $f0
/* 0CCADC 7F097FAC 10000002 */  b     .L7F097FB8
/* 0CCAE0 7F097FB0 46000386 */   mov.s $f14, $f0
/* 0CCAE4 7F097FB4 46000387 */  neg.s $f14, $f0
.L7F097FB8:
/* 0CCAE8 7F097FB8 C7A00348 */  lwc1  $f0, 0x348($sp)
.L7F097FBC:
/* 0CCAEC 7F097FBC 4600A03E */  c.le.s $f20, $f0
/* 0CCAF0 7F097FC0 00000000 */  nop   
/* 0CCAF4 7F097FC4 45020004 */  bc1fl .L7F097FD8
/* 0CCAF8 7F097FC8 46000307 */   neg.s $f12, $f0
/* 0CCAFC 7F097FCC 10000002 */  b     .L7F097FD8
/* 0CCB00 7F097FD0 46000306 */   mov.s $f12, $f0
/* 0CCB04 7F097FD4 46000307 */  neg.s $f12, $f0
.L7F097FD8:
/* 0CCB08 7F097FD8 460C803C */  c.lt.s $f16, $f12
/* 0CCB0C 7F097FDC E7B20368 */  swc1  $f18, 0x368($sp)
/* 0CCB10 7F097FE0 4502000B */  bc1fl .L7F098010
/* 0CCB14 7F097FE4 C7A00350 */   lwc1  $f0, 0x350($sp)
/* 0CCB18 7F097FE8 4600A03E */  c.le.s $f20, $f0
/* 0CCB1C 7F097FEC 00000000 */  nop   
/* 0CCB20 7F097FF0 45020005 */  bc1fl .L7F098008
/* 0CCB24 7F097FF4 46000407 */   neg.s $f16, $f0
/* 0CCB28 7F097FF8 46000406 */  mov.s $f16, $f0
/* 0CCB2C 7F097FFC 10000003 */  b     .L7F09800C
/* 0CCB30 7F098000 E7B20368 */   swc1  $f18, 0x368($sp)
/* 0CCB34 7F098004 46000407 */  neg.s $f16, $f0
.L7F098008:
/* 0CCB38 7F098008 E7B20368 */  swc1  $f18, 0x368($sp)
.L7F09800C:
/* 0CCB3C 7F09800C C7A00350 */  lwc1  $f0, 0x350($sp)
.L7F098010:
/* 0CCB40 7F098010 4600A03E */  c.le.s $f20, $f0
/* 0CCB44 7F098014 00000000 */  nop   
/* 0CCB48 7F098018 45020004 */  bc1fl .L7F09802C
/* 0CCB4C 7F09801C 46000307 */   neg.s $f12, $f0
/* 0CCB50 7F098020 10000002 */  b     .L7F09802C
/* 0CCB54 7F098024 46000306 */   mov.s $f12, $f0
/* 0CCB58 7F098028 46000307 */  neg.s $f12, $f0
.L7F09802C:
/* 0CCB5C 7F09802C 460C703C */  c.lt.s $f14, $f12
/* 0CCB60 7F098030 E7AE0330 */  swc1  $f14, 0x330($sp)
/* 0CCB64 7F098034 4502000A */  bc1fl .L7F098060
/* 0CCB68 7F098038 C7A00354 */   lwc1  $f0, 0x354($sp)
/* 0CCB6C 7F09803C 4600A03E */  c.le.s $f20, $f0
/* 0CCB70 7F098040 00000000 */  nop   
/* 0CCB74 7F098044 45020004 */  bc1fl .L7F098058
/* 0CCB78 7F098048 46000387 */   neg.s $f14, $f0
/* 0CCB7C 7F09804C 10000003 */  b     .L7F09805C
/* 0CCB80 7F098050 E7A00330 */   swc1  $f0, 0x330($sp)
/* 0CCB84 7F098054 46000387 */  neg.s $f14, $f0
.L7F098058:
/* 0CCB88 7F098058 E7AE0330 */  swc1  $f14, 0x330($sp)
.L7F09805C:
/* 0CCB8C 7F09805C C7A00354 */  lwc1  $f0, 0x354($sp)
.L7F098060:
/* 0CCB90 7F098060 4600A03E */  c.le.s $f20, $f0
/* 0CCB94 7F098064 00000000 */  nop   
/* 0CCB98 7F098068 45020004 */  bc1fl .L7F09807C
/* 0CCB9C 7F09806C 46000307 */   neg.s $f12, $f0
/* 0CCBA0 7F098070 10000002 */  b     .L7F09807C
/* 0CCBA4 7F098074 46000306 */   mov.s $f12, $f0
/* 0CCBA8 7F098078 46000307 */  neg.s $f12, $f0
.L7F09807C:
/* 0CCBAC 7F09807C 460C803C */  c.lt.s $f16, $f12
/* 0CCBB0 7F098080 E7B00334 */  swc1  $f16, 0x334($sp)
/* 0CCBB4 7F098084 4502000A */  bc1fl .L7F0980B0
/* 0CCBB8 7F098088 C52A0010 */   lwc1  $f10, 0x10($t1)
/* 0CCBBC 7F09808C 4600A03E */  c.le.s $f20, $f0
/* 0CCBC0 7F098090 00000000 */  nop   
/* 0CCBC4 7F098094 45020004 */  bc1fl .L7F0980A8
/* 0CCBC8 7F098098 46000407 */   neg.s $f16, $f0
/* 0CCBCC 7F09809C 10000003 */  b     .L7F0980AC
/* 0CCBD0 7F0980A0 E7A00334 */   swc1  $f0, 0x334($sp)
/* 0CCBD4 7F0980A4 46000407 */  neg.s $f16, $f0
.L7F0980A8:
/* 0CCBD8 7F0980A8 E7B00334 */  swc1  $f16, 0x334($sp)
.L7F0980AC:
/* 0CCBDC 7F0980AC C52A0010 */  lwc1  $f10, 0x10($t1)
.L7F0980B0:
/* 0CCBE0 7F0980B0 27A402B0 */  addiu $a0, $sp, 0x2b0
/* 0CCBE4 7F0980B4 27A602F0 */  addiu $a2, $sp, 0x2f0
/* 0CCBE8 7F0980B8 46025100 */  add.s $f4, $f10, $f2
/* 0CCBEC 7F0980BC 27A20310 */  addiu $v0, $sp, 0x310
/* 0CCBF0 7F0980C0 27A30290 */  addiu $v1, $sp, 0x290
/* 0CCBF4 7F0980C4 27A502D0 */  addiu $a1, $sp, 0x2d0
/* 0CCBF8 7F0980C8 E7A40310 */  swc1  $f4, 0x310($sp)
/* 0CCBFC 7F0980CC C5260014 */  lwc1  $f6, 0x14($t1)
/* 0CCC00 7F0980D0 27A702F0 */  addiu $a3, $sp, 0x2f0
/* 0CCC04 7F0980D4 46023200 */  add.s $f8, $f6, $f2
/* 0CCC08 7F0980D8 E7A80314 */  swc1  $f8, 0x314($sp)
/* 0CCC0C 7F0980DC C52A0018 */  lwc1  $f10, 0x18($t1)
/* 0CCC10 7F0980E0 46025100 */  add.s $f4, $f10, $f2
/* 0CCC14 7F0980E4 E7A40318 */  swc1  $f4, 0x318($sp)
/* 0CCC18 7F0980E8 C526001C */  lwc1  $f6, 0x1c($t1)
/* 0CCC1C 7F0980EC 46023200 */  add.s $f8, $f6, $f2
/* 0CCC20 7F0980F0 E7A8031C */  swc1  $f8, 0x31c($sp)
/* 0CCC24 7F0980F4 C50A0010 */  lwc1  $f10, 0x10($t0)
/* 0CCC28 7F0980F8 46025100 */  add.s $f4, $f10, $f2
/* 0CCC2C 7F0980FC E7A402F0 */  swc1  $f4, 0x2f0($sp)
/* 0CCC30 7F098100 C5060014 */  lwc1  $f6, 0x14($t0)
/* 0CCC34 7F098104 46023200 */  add.s $f8, $f6, $f2
/* 0CCC38 7F098108 E7A802F4 */  swc1  $f8, 0x2f4($sp)
/* 0CCC3C 7F09810C C50A0018 */  lwc1  $f10, 0x18($t0)
/* 0CCC40 7F098110 46025100 */  add.s $f4, $f10, $f2
/* 0CCC44 7F098114 E7A402F8 */  swc1  $f4, 0x2f8($sp)
/* 0CCC48 7F098118 C506001C */  lwc1  $f6, 0x1c($t0)
/* 0CCC4C 7F09811C 46023200 */  add.s $f8, $f6, $f2
/* 0CCC50 7F098120 E7A802FC */  swc1  $f8, 0x2fc($sp)
/* 0CCC54 7F098124 C56A0010 */  lwc1  $f10, 0x10($t3)
/* 0CCC58 7F098128 46025100 */  add.s $f4, $f10, $f2
/* 0CCC5C 7F09812C E7A402D0 */  swc1  $f4, 0x2d0($sp)
/* 0CCC60 7F098130 C5660014 */  lwc1  $f6, 0x14($t3)
/* 0CCC64 7F098134 46023200 */  add.s $f8, $f6, $f2
/* 0CCC68 7F098138 E7A802D4 */  swc1  $f8, 0x2d4($sp)
/* 0CCC6C 7F09813C C56A0018 */  lwc1  $f10, 0x18($t3)
/* 0CCC70 7F098140 46025100 */  add.s $f4, $f10, $f2
/* 0CCC74 7F098144 C7AA0338 */  lwc1  $f10, 0x338($sp)
/* 0CCC78 7F098148 E7A402D8 */  swc1  $f4, 0x2d8($sp)
/* 0CCC7C 7F09814C C566001C */  lwc1  $f6, 0x1c($t3)
/* 0CCC80 7F098150 E7AA0320 */  swc1  $f10, 0x320($sp)
/* 0CCC84 7F098154 C7A4033C */  lwc1  $f4, 0x33c($sp)
/* 0CCC88 7F098158 46023200 */  add.s $f8, $f6, $f2
/* 0CCC8C 7F09815C C7A60340 */  lwc1  $f6, 0x340($sp)
/* 0CCC90 7F098160 C7AA0348 */  lwc1  $f10, 0x348($sp)
/* 0CCC94 7F098164 E7A40324 */  swc1  $f4, 0x324($sp)
/* 0CCC98 7F098168 E7A802DC */  swc1  $f8, 0x2dc($sp)
/* 0CCC9C 7F09816C C7A80344 */  lwc1  $f8, 0x344($sp)
/* 0CCCA0 7F098170 E7A60328 */  swc1  $f6, 0x328($sp)
/* 0CCCA4 7F098174 E7AA0304 */  swc1  $f10, 0x304($sp)
/* 0CCCA8 7F098178 E7A80300 */  swc1  $f8, 0x300($sp)
/* 0CCCAC 7F09817C C7A4034C */  lwc1  $f4, 0x34c($sp)
/* 0CCCB0 7F098180 C7A80354 */  lwc1  $f8, 0x354($sp)
/* 0CCCB4 7F098184 C7AA0358 */  lwc1  $f10, 0x358($sp)
/* 0CCCB8 7F098188 C7A60350 */  lwc1  $f6, 0x350($sp)
/* 0CCCBC 7F09818C E7A40308 */  swc1  $f4, 0x308($sp)
/* 0CCCC0 7F098190 E7A802E4 */  swc1  $f8, 0x2e4($sp)
/* 0CCCC4 7F098194 E7AA02E8 */  swc1  $f10, 0x2e8($sp)
/* 0CCCC8 7F098198 E7A602E0 */  swc1  $f6, 0x2e0($sp)
/* 0CCCCC 7F09819C C5240030 */  lwc1  $f4, 0x30($t1)
/* 0CCCD0 7F0981A0 27A90230 */  addiu $t1, $sp, 0x230
/* 0CCCD4 7F0981A4 E7A4032C */  swc1  $f4, 0x32c($sp)
/* 0CCCD8 7F0981A8 C5060030 */  lwc1  $f6, 0x30($t0)
/* 0CCCDC 7F0981AC 27A80230 */  addiu $t0, $sp, 0x230
/* 0CCCE0 7F0981B0 E7A6030C */  swc1  $f6, 0x30c($sp)
/* 0CCCE4 7F0981B4 C5680030 */  lwc1  $f8, 0x30($t3)
/* 0CCCE8 7F0981B8 E7A802EC */  swc1  $f8, 0x2ec($sp)
.L7F0981BC:
/* 0CCCEC 7F0981BC C4400000 */  lwc1  $f0, ($v0)
/* 0CCCF0 7F0981C0 C4CA0000 */  lwc1  $f10, ($a2)
/* 0CCCF4 7F0981C4 C4A60000 */  lwc1  $f6, ($a1)
/* 0CCCF8 7F0981C8 24A50004 */  addiu $a1, $a1, 4
/* 0CCCFC 7F0981CC 46005101 */  sub.s $f4, $f10, $f0
/* 0CCD00 7F0981D0 00A7082B */  sltu  $at, $a1, $a3
/* 0CCD04 7F0981D4 24840004 */  addiu $a0, $a0, 4
/* 0CCD08 7F0981D8 46003201 */  sub.s $f8, $f6, $f0
/* 0CCD0C 7F0981DC 24C60004 */  addiu $a2, $a2, 4
/* 0CCD10 7F0981E0 24420004 */  addiu $v0, $v0, 4
/* 0CCD14 7F0981E4 24630004 */  addiu $v1, $v1, 4
/* 0CCD18 7F0981E8 E484FFFC */  swc1  $f4, -4($a0)
/* 0CCD1C 7F0981EC 1420FFF3 */  bnez  $at, .L7F0981BC
/* 0CCD20 7F0981F0 E468FFFC */   swc1  $f8, -4($v1)
/* 0CCD24 7F0981F4 27A402B0 */  addiu $a0, $sp, 0x2b0
/* 0CCD28 7F0981F8 27A20310 */  addiu $v0, $sp, 0x310
/* 0CCD2C 7F0981FC 27A30290 */  addiu $v1, $sp, 0x290
/* 0CCD30 7F098200 27A70250 */  addiu $a3, $sp, 0x250
/* 0CCD34 7F098204 27A50270 */  addiu $a1, $sp, 0x270
/* 0CCD38 7F098208 27A60210 */  addiu $a2, $sp, 0x210
/* 0CCD3C 7F09820C C7B203C8 */  lwc1  $f18, 0x3c8($sp)
.L7F098210:
/* 0CCD40 7F098210 C4600000 */  lwc1  $f0, ($v1)
/* 0CCD44 7F098214 C7AA03CC */  lwc1  $f10, 0x3cc($sp)
/* 0CCD48 7F098218 C4820000 */  lwc1  $f2, ($a0)
/* 0CCD4C 7F09821C C7A603D4 */  lwc1  $f6, 0x3d4($sp)
/* 0CCD50 7F098220 460A0102 */  mul.s $f4, $f0, $f10
/* 0CCD54 7F098224 3C014780 */  li    $at, 0x47800000 # 65536.000000
/* 0CCD58 7F098228 24C60004 */  addiu $a2, $a2, 4
/* 0CCD5C 7F09822C 46023202 */  mul.s $f8, $f6, $f2
/* 0CCD60 7F098230 44813000 */  mtc1  $at, $f6
/* 0CCD64 7F098234 24840004 */  addiu $a0, $a0, 4
/* 0CCD68 7F098238 24420004 */  addiu $v0, $v0, 4
/* 0CCD6C 7F09823C 24630004 */  addiu $v1, $v1, 4
/* 0CCD70 7F098240 24E70004 */  addiu $a3, $a3, 4
/* 0CCD74 7F098244 24A50004 */  addiu $a1, $a1, 4
/* 0CCD78 7F098248 46082281 */  sub.s $f10, $f4, $f8
/* 0CCD7C 7F09824C 25080004 */  addiu $t0, $t0, 4
/* 0CCD80 7F098250 46065303 */  div.s $f12, $f10, $f6
/* 0CCD84 7F098254 E4ECFFFC */  swc1  $f12, -4($a3)
/* 0CCD88 7F098258 C7A403D0 */  lwc1  $f4, 0x3d0($sp)
/* 0CCD8C 7F09825C 46041202 */  mul.s $f8, $f2, $f4
/* 0CCD90 7F098260 44812000 */  mtc1  $at, $f4
/* 0CCD94 7F098264 00C9082B */  sltu  $at, $a2, $t1
/* 0CCD98 7F098268 46009282 */  mul.s $f10, $f18, $f0
/* 0CCD9C 7F09826C 460A4181 */  sub.s $f6, $f8, $f10
/* 0CCDA0 7F098270 46043203 */  div.s $f8, $f6, $f4
/* 0CCDA4 7F098274 E4A8FFFC */  swc1  $f8, -4($a1)
/* 0CCDA8 7F098278 C7AA0440 */  lwc1  $f10, 0x440($sp)
/* 0CCDAC 7F09827C C4A4FFFC */  lwc1  $f4, -4($a1)
/* 0CCDB0 7F098280 460A6182 */  mul.s $f6, $f12, $f10
/* 0CCDB4 7F098284 E466FFFC */  swc1  $f6, -4($v1)
/* 0CCDB8 7F098288 C7A80440 */  lwc1  $f8, 0x440($sp)
/* 0CCDBC 7F09828C C466FFFC */  lwc1  $f6, -4($v1)
/* 0CCDC0 7F098290 46082382 */  mul.s $f14, $f4, $f8
/* 0CCDC4 7F098294 C448FFFC */  lwc1  $f8, -4($v0)
/* 0CCDC8 7F098298 E48EFFFC */  swc1  $f14, -4($a0)
/* 0CCDCC 7F09829C C7AA0394 */  lwc1  $f10, 0x394($sp)
/* 0CCDD0 7F0982A0 46065102 */  mul.s $f4, $f10, $f6
/* 0CCDD4 7F0982A4 460E2400 */  add.s $f16, $f4, $f14
/* 0CCDD8 7F0982A8 E510FFFC */  swc1  $f16, -4($t0)
/* 0CCDDC 7F0982AC C7AA037C */  lwc1  $f10, 0x37c($sp)
/* 0CCDE0 7F0982B0 460A8182 */  mul.s $f6, $f16, $f10
/* 0CCDE4 7F0982B4 46064101 */  sub.s $f4, $f8, $f6
/* 0CCDE8 7F0982B8 1420FFD5 */  bnez  $at, .L7F098210
/* 0CCDEC 7F0982BC E4C4FFFC */   swc1  $f4, -4($a2)
/* 0CCDF0 7F0982C0 0FC250A6 */  jal   sub_GAME_7F094298
/* 0CCDF4 7F0982C4 C7AC0210 */   lwc1  $f12, 0x210($sp)
/* 0CCDF8 7F0982C8 AFA20168 */  sw    $v0, 0x168($sp)
/* 0CCDFC 7F0982CC 0FC250A6 */  jal   sub_GAME_7F094298
/* 0CCE00 7F0982D0 C7AC0214 */   lwc1  $f12, 0x214($sp)
/* 0CCE04 7F0982D4 AFA20164 */  sw    $v0, 0x164($sp)
/* 0CCE08 7F0982D8 0FC250A6 */  jal   sub_GAME_7F094298
/* 0CCE0C 7F0982DC C7AC0218 */   lwc1  $f12, 0x218($sp)
/* 0CCE10 7F0982E0 AFA20160 */  sw    $v0, 0x160($sp)
/* 0CCE14 7F0982E4 0FC250A6 */  jal   sub_GAME_7F094298
/* 0CCE18 7F0982E8 C7AC021C */   lwc1  $f12, 0x21c($sp)
/* 0CCE1C 7F0982EC AFA2015C */  sw    $v0, 0x15c($sp)
/* 0CCE20 7F0982F0 0FC250A6 */  jal   sub_GAME_7F094298
/* 0CCE24 7F0982F4 C7AC0290 */   lwc1  $f12, 0x290($sp)
/* 0CCE28 7F0982F8 AFA20158 */  sw    $v0, 0x158($sp)
/* 0CCE2C 7F0982FC 0FC250A6 */  jal   sub_GAME_7F094298
/* 0CCE30 7F098300 C7AC0294 */   lwc1  $f12, 0x294($sp)
/* 0CCE34 7F098304 AFA20154 */  sw    $v0, 0x154($sp)
/* 0CCE38 7F098308 0FC250A6 */  jal   sub_GAME_7F094298
/* 0CCE3C 7F09830C C7AC0298 */   lwc1  $f12, 0x298($sp)
/* 0CCE40 7F098310 AFA20150 */  sw    $v0, 0x150($sp)
/* 0CCE44 7F098314 0FC250A6 */  jal   sub_GAME_7F094298
/* 0CCE48 7F098318 C7AC029C */   lwc1  $f12, 0x29c($sp)
/* 0CCE4C 7F09831C AFA2014C */  sw    $v0, 0x14c($sp)
/* 0CCE50 7F098320 0FC250A6 */  jal   sub_GAME_7F094298
/* 0CCE54 7F098324 C7AC02B0 */   lwc1  $f12, 0x2b0($sp)
/* 0CCE58 7F098328 AFA20138 */  sw    $v0, 0x138($sp)
/* 0CCE5C 7F09832C 0FC250A6 */  jal   sub_GAME_7F094298
/* 0CCE60 7F098330 C7AC02B4 */   lwc1  $f12, 0x2b4($sp)
/* 0CCE64 7F098334 AFA20134 */  sw    $v0, 0x134($sp)
/* 0CCE68 7F098338 0FC250A6 */  jal   sub_GAME_7F094298
/* 0CCE6C 7F09833C C7AC02B8 */   lwc1  $f12, 0x2b8($sp)
/* 0CCE70 7F098340 AFA20130 */  sw    $v0, 0x130($sp)
/* 0CCE74 7F098344 0FC250A6 */  jal   sub_GAME_7F094298
/* 0CCE78 7F098348 C7AC02BC */   lwc1  $f12, 0x2bc($sp)
/* 0CCE7C 7F09834C AFA2012C */  sw    $v0, 0x12c($sp)
/* 0CCE80 7F098350 0FC250A6 */  jal   sub_GAME_7F094298
/* 0CCE84 7F098354 C7AC0230 */   lwc1  $f12, 0x230($sp)
/* 0CCE88 7F098358 AFA20148 */  sw    $v0, 0x148($sp)
/* 0CCE8C 7F09835C 0FC250A6 */  jal   sub_GAME_7F094298
/* 0CCE90 7F098360 C7AC0234 */   lwc1  $f12, 0x234($sp)
/* 0CCE94 7F098364 AFA20144 */  sw    $v0, 0x144($sp)
/* 0CCE98 7F098368 0FC250A6 */  jal   sub_GAME_7F094298
/* 0CCE9C 7F09836C C7AC0238 */   lwc1  $f12, 0x238($sp)
/* 0CCEA0 7F098370 C7AC023C */  lwc1  $f12, 0x23c($sp)
/* 0CCEA4 7F098374 0FC250A6 */  jal   sub_GAME_7F094298
/* 0CCEA8 7F098378 AFA20140 */   sw    $v0, 0x140($sp)
/* 0CCEAC 7F09837C 8FAC0140 */  lw    $t4, 0x140($sp)
/* 0CCEB0 7F098380 8FAD015C */  lw    $t5, 0x15c($sp)
/* 0CCEB4 7F098384 8FBF0168 */  lw    $ra, 0x168($sp)
/* 0CCEB8 7F098388 3C08B400 */  lui   $t0, 0xb400
/* 0CCEBC 7F09838C 02001825 */  move  $v1, $s0
/* 0CCEC0 7F098390 AC680000 */  sw    $t0, ($v1)
/* 0CCEC4 7F098394 8FB90164 */  lw    $t9, 0x164($sp)
/* 0CCEC8 7F098398 3C09FFFF */  lui   $t1, 0xffff
/* 0CCECC 7F09839C 03E97824 */  and   $t7, $ra, $t1
/* 0CCED0 7F0983A0 03297024 */  and   $t6, $t9, $t1
/* 0CCED4 7F0983A4 000EC402 */  srl   $t8, $t6, 0x10
/* 0CCED8 7F0983A8 01F8C825 */  or    $t9, $t7, $t8
/* 0CCEDC 7F0983AC 26100008 */  addiu $s0, $s0, 8
/* 0CCEE0 7F0983B0 3C0AB200 */  lui   $t2, 0xb200
/* 0CCEE4 7F0983B4 AC790004 */  sw    $t9, 4($v1)
/* 0CCEE8 7F0983B8 02002025 */  move  $a0, $s0
/* 0CCEEC 7F0983BC AC8A0000 */  sw    $t2, ($a0)
/* 0CCEF0 7F0983C0 8FAE0160 */  lw    $t6, 0x160($sp)
/* 0CCEF4 7F0983C4 01A9C024 */  and   $t8, $t5, $t1
/* 0CCEF8 7F0983C8 0018CC02 */  srl   $t9, $t8, 0x10
/* 0CCEFC 7F0983CC 01C97824 */  and   $t7, $t6, $t1
/* 0CCF00 7F0983D0 01F97025 */  or    $t6, $t7, $t9
/* 0CCF04 7F0983D4 26100008 */  addiu $s0, $s0, 8
/* 0CCF08 7F0983D8 AC8E0004 */  sw    $t6, 4($a0)
/* 0CCF0C 7F0983DC 02002825 */  move  $a1, $s0
/* 0CCF10 7F0983E0 ACA80000 */  sw    $t0, ($a1)
/* 0CCF14 7F0983E4 8FB90154 */  lw    $t9, 0x154($sp)
/* 0CCF18 7F0983E8 8FB80158 */  lw    $t8, 0x158($sp)
/* 0CCF1C 7F0983EC 26100008 */  addiu $s0, $s0, 8
/* 0CCF20 7F0983F0 03297024 */  and   $t6, $t9, $t1
/* 0CCF24 7F0983F4 03097824 */  and   $t7, $t8, $t1
/* 0CCF28 7F0983F8 000EC402 */  srl   $t8, $t6, 0x10
/* 0CCF2C 7F0983FC 01F8C825 */  or    $t9, $t7, $t8
/* 0CCF30 7F098400 ACB90004 */  sw    $t9, 4($a1)
/* 0CCF34 7F098404 8FAB014C */  lw    $t3, 0x14c($sp)
/* 0CCF38 7F098408 02003025 */  move  $a2, $s0
/* 0CCF3C 7F09840C ACCA0000 */  sw    $t2, ($a2)
/* 0CCF40 7F098410 8FAE0150 */  lw    $t6, 0x150($sp)
/* 0CCF44 7F098414 0169C024 */  and   $t8, $t3, $t1
/* 0CCF48 7F098418 0018CC02 */  srl   $t9, $t8, 0x10
/* 0CCF4C 7F09841C 01C97824 */  and   $t7, $t6, $t1
/* 0CCF50 7F098420 01F97025 */  or    $t6, $t7, $t9
/* 0CCF54 7F098424 26100008 */  addiu $s0, $s0, 8
/* 0CCF58 7F098428 ACCE0004 */  sw    $t6, 4($a2)
/* 0CCF5C 7F09842C 02001825 */  move  $v1, $s0
/* 0CCF60 7F098430 AC680000 */  sw    $t0, ($v1)
/* 0CCF64 7F098434 8FB90164 */  lw    $t9, 0x164($sp)
/* 0CCF68 7F098438 001F7C00 */  sll   $t7, $ra, 0x10
/* 0CCF6C 7F09843C 26100008 */  addiu $s0, $s0, 8
/* 0CCF70 7F098440 332EFFFF */  andi  $t6, $t9, 0xffff
/* 0CCF74 7F098444 01EEC025 */  or    $t8, $t7, $t6
/* 0CCF78 7F098448 AC780004 */  sw    $t8, 4($v1)
/* 0CCF7C 7F09844C 02002025 */  move  $a0, $s0
/* 0CCF80 7F098450 AC8A0000 */  sw    $t2, ($a0)
/* 0CCF84 7F098454 8FAF0160 */  lw    $t7, 0x160($sp)
/* 0CCF88 7F098458 31B8FFFF */  andi  $t8, $t5, 0xffff
/* 0CCF8C 7F09845C 26100008 */  addiu $s0, $s0, 8
/* 0CCF90 7F098460 000F7400 */  sll   $t6, $t7, 0x10
/* 0CCF94 7F098464 01D8C825 */  or    $t9, $t6, $t8
/* 0CCF98 7F098468 AC990004 */  sw    $t9, 4($a0)
/* 0CCF9C 7F09846C 02003825 */  move  $a3, $s0
/* 0CCFA0 7F098470 ACE80000 */  sw    $t0, ($a3)
/* 0CCFA4 7F098474 8FB90154 */  lw    $t9, 0x154($sp)
/* 0CCFA8 7F098478 8FAE0158 */  lw    $t6, 0x158($sp)
/* 0CCFAC 7F09847C 8FA80148 */  lw    $t0, 0x148($sp)
/* 0CCFB0 7F098480 332FFFFF */  andi  $t7, $t9, 0xffff
/* 0CCFB4 7F098484 000EC400 */  sll   $t8, $t6, 0x10
/* 0CCFB8 7F098488 8FA60144 */  lw    $a2, 0x144($sp)
/* 0CCFBC 7F09848C 030F7025 */  or    $t6, $t8, $t7
/* 0CCFC0 7F098490 26100008 */  addiu $s0, $s0, 8
/* 0CCFC4 7F098494 ACEE0004 */  sw    $t6, 4($a3)
/* 0CCFC8 7F098498 02001825 */  move  $v1, $s0
/* 0CCFCC 7F09849C AC6A0000 */  sw    $t2, ($v1)
/* 0CCFD0 7F0984A0 8FB80150 */  lw    $t8, 0x150($sp)
/* 0CCFD4 7F0984A4 316EFFFF */  andi  $t6, $t3, 0xffff
/* 0CCFD8 7F0984A8 26100008 */  addiu $s0, $s0, 8
/* 0CCFDC 7F0984AC 00187C00 */  sll   $t7, $t8, 0x10
/* 0CCFE0 7F0984B0 01EEC825 */  or    $t9, $t7, $t6
/* 0CCFE4 7F0984B4 AC790004 */  sw    $t9, 4($v1)
/* 0CCFE8 7F0984B8 3C18B400 */  lui   $t8, 0xb400
/* 0CCFEC 7F0984BC 02002025 */  move  $a0, $s0
/* 0CCFF0 7F0984C0 00C97024 */  and   $t6, $a2, $t1
/* 0CCFF4 7F0984C4 000ECC02 */  srl   $t9, $t6, 0x10
/* 0CCFF8 7F0984C8 AC980000 */  sw    $t8, ($a0)
/* 0CCFFC 7F0984CC 01097824 */  and   $t7, $t0, $t1
/* 0CD000 7F0984D0 01F9C025 */  or    $t8, $t7, $t9
/* 0CD004 7F0984D4 26100008 */  addiu $s0, $s0, 8
/* 0CD008 7F0984D8 AC980004 */  sw    $t8, 4($a0)
/* 0CD00C 7F0984DC 02002825 */  move  $a1, $s0
/* 0CD010 7F0984E0 00497824 */  and   $t7, $v0, $t1
/* 0CD014 7F0984E4 000FCC02 */  srl   $t9, $t7, 0x10
/* 0CD018 7F0984E8 01897024 */  and   $t6, $t4, $t1
/* 0CD01C 7F0984EC 01D9C025 */  or    $t8, $t6, $t9
/* 0CD020 7F0984F0 ACB80004 */  sw    $t8, 4($a1)
/* 0CD024 7F0984F4 ACAA0000 */  sw    $t2, ($a1)
/* 0CD028 7F0984F8 26100008 */  addiu $s0, $s0, 8
/* 0CD02C 7F0984FC 8FAD0130 */  lw    $t5, 0x130($sp)
/* 0CD030 7F098500 3C07B400 */  lui   $a3, %hi(0xB4000004) # $a3, 0xb400
/* 0CD034 7F098504 02001825 */  move  $v1, $s0
/* 0CD038 7F098508 AC670000 */  sw    $a3, ($v1)
/* 0CD03C 7F09850C 8FB90134 */  lw    $t9, 0x134($sp)
/* 0CD040 7F098510 8FAF0138 */  lw    $t7, 0x138($sp)
/* 0CD044 7F098514 26100008 */  addiu $s0, $s0, 8
/* 0CD048 7F098518 0329C024 */  and   $t8, $t9, $t1
/* 0CD04C 7F09851C 01E97024 */  and   $t6, $t7, $t1
/* 0CD050 7F098520 00187C02 */  srl   $t7, $t8, 0x10
/* 0CD054 7F098524 01CFC825 */  or    $t9, $t6, $t7
/* 0CD058 7F098528 AC790004 */  sw    $t9, 4($v1)
/* 0CD05C 7F09852C 3C18B200 */  lui   $t8, 0xb200
/* 0CD060 7F098530 02002025 */  move  $a0, $s0
/* 0CD064 7F098534 AC980000 */  sw    $t8, ($a0)
/* 0CD068 7F098538 8FAF012C */  lw    $t7, 0x12c($sp)
/* 0CD06C 7F09853C 01A97024 */  and   $t6, $t5, $t1
/* 0CD070 7F098540 26100008 */  addiu $s0, $s0, 8
/* 0CD074 7F098544 01E9C824 */  and   $t9, $t7, $t1
/* 0CD078 7F098548 0019C402 */  srl   $t8, $t9, 0x10
/* 0CD07C 7F09854C 01D87825 */  or    $t7, $t6, $t8
/* 0CD080 7F098550 AC8F0004 */  sw    $t7, 4($a0)
/* 0CD084 7F098554 02002825 */  move  $a1, $s0
/* 0CD088 7F098558 00087400 */  sll   $t6, $t0, 0x10
/* 0CD08C 7F09855C 30D8FFFF */  andi  $t8, $a2, 0xffff
/* 0CD090 7F098560 01D87825 */  or    $t7, $t6, $t8
/* 0CD094 7F098564 26100008 */  addiu $s0, $s0, 8
/* 0CD098 7F098568 ACAF0004 */  sw    $t7, 4($a1)
/* 0CD09C 7F09856C ACA70000 */  sw    $a3, ($a1)
/* 0CD0A0 7F098570 02005825 */  move  $t3, $s0
/* 0CD0A4 7F098574 3058FFFF */  andi  $t8, $v0, 0xffff
/* 0CD0A8 7F098578 000C7400 */  sll   $t6, $t4, 0x10
/* 0CD0AC 7F09857C 01D87825 */  or    $t7, $t6, $t8
/* 0CD0B0 7F098580 26100008 */  addiu $s0, $s0, 8
/* 0CD0B4 7F098584 3C1FB200 */  lui   $ra, 0xb200
/* 0CD0B8 7F098588 AD7F0000 */  sw    $ra, ($t3)
/* 0CD0BC 7F09858C AD6F0004 */  sw    $t7, 4($t3)
/* 0CD0C0 7F098590 02003825 */  move  $a3, $s0
/* 0CD0C4 7F098594 3C19B400 */  lui   $t9, 0xb400
/* 0CD0C8 7F098598 ACF90000 */  sw    $t9, ($a3)
/* 0CD0CC 7F09859C 8FB90134 */  lw    $t9, 0x134($sp)
/* 0CD0D0 7F0985A0 8FB80138 */  lw    $t8, 0x138($sp)
/* 0CD0D4 7F0985A4 26100008 */  addiu $s0, $s0, 8
/* 0CD0D8 7F0985A8 332EFFFF */  andi  $t6, $t9, 0xffff
/* 0CD0DC 7F0985AC 00187C00 */  sll   $t7, $t8, 0x10
/* 0CD0E0 7F0985B0 01EEC025 */  or    $t8, $t7, $t6
/* 0CD0E4 7F0985B4 ACF80004 */  sw    $t8, %lo(0xB4000004)($a3)
/* 0CD0E8 7F0985B8 02004025 */  move  $t0, $s0
/* 0CD0EC 7F0985BC AD1F0000 */  sw    $ra, ($t0)
/* 0CD0F0 7F0985C0 8FAE012C */  lw    $t6, 0x12c($sp)
/* 0CD0F4 7F0985C4 000D7C00 */  sll   $t7, $t5, 0x10
/* 0CD0F8 7F0985C8 3C013D00 */  li    $at, 0x3D000000 # 0.031250
/* 0CD0FC 7F0985CC 31D8FFFF */  andi  $t8, $t6, 0xffff
/* 0CD100 7F0985D0 01F8C825 */  or    $t9, $t7, $t8
/* 0CD104 7F0985D4 AD190004 */  sw    $t9, 4($t0)
/* 0CD108 7F0985D8 44817000 */  mtc1  $at, $f14
/* 0CD10C 7F0985DC C7AA0330 */  lwc1  $f10, 0x330($sp)
/* 0CD110 7F0985E0 C7A60334 */  lwc1  $f6, 0x334($sp)
/* 0CD114 7F0985E4 26100008 */  addiu $s0, $s0, 8
/* 0CD118 7F0985E8 460E5202 */  mul.s $f8, $f10, $f14
/* 0CD11C 7F0985EC C7AA0368 */  lwc1  $f10, 0x368($sp)
/* 0CD120 7F0985F0 3C014000 */  li    $at, 0x40000000 # 2.000000
/* 0CD124 7F0985F4 460E3102 */  mul.s $f4, $f6, $f14
/* 0CD128 7F0985F8 27A201D0 */  addiu $v0, $sp, 0x1d0
/* 0CD12C 7F0985FC 27A501B0 */  addiu $a1, $sp, 0x1b0
/* 0CD130 7F098600 27A601D0 */  addiu $a2, $sp, 0x1d0
/* 0CD134 7F098604 E7A80200 */  swc1  $f8, 0x200($sp)
/* 0CD138 7F098608 460E5202 */  mul.s $f8, $f10, $f14
/* 0CD13C 7F09860C 27A402B0 */  addiu $a0, $sp, 0x2b0
/* 0CD140 7F098610 E7A40204 */  swc1  $f4, 0x204($sp)
/* 0CD144 7F098614 27A30290 */  addiu $v1, $sp, 0x290
/* 0CD148 7F098618 E7A80208 */  swc1  $f8, 0x208($sp)
.L7F09861C:
/* 0CD14C 7F09861C C4600000 */  lwc1  $f0, ($v1)
/* 0CD150 7F098620 4600A03E */  c.le.s $f20, $f0
/* 0CD154 7F098624 00000000 */  nop   
/* 0CD158 7F098628 45020004 */  bc1fl .L7F09863C
/* 0CD15C 7F09862C 46000307 */   neg.s $f12, $f0
/* 0CD160 7F098630 10000002 */  b     .L7F09863C
/* 0CD164 7F098634 46000306 */   mov.s $f12, $f0
/* 0CD168 7F098638 46000307 */  neg.s $f12, $f0
.L7F09863C:
/* 0CD16C 7F09863C C4820000 */  lwc1  $f2, ($a0)
/* 0CD170 7F098640 460E6182 */  mul.s $f6, $f12, $f14
/* 0CD174 7F098644 4602A03E */  c.le.s $f20, $f2
/* 0CD178 7F098648 00000000 */  nop   
/* 0CD17C 7F09864C 45000003 */  bc1f  .L7F09865C
/* 0CD180 7F098650 E4C60000 */   swc1  $f6, ($a2)
/* 0CD184 7F098654 10000002 */  b     .L7F098660
/* 0CD188 7F098658 46001306 */   mov.s $f12, $f2
.L7F09865C:
/* 0CD18C 7F09865C 46001307 */  neg.s $f12, $f2
.L7F098660:
/* 0CD190 7F098660 460E6102 */  mul.s $f4, $f12, $f14
/* 0CD194 7F098664 24A50004 */  addiu $a1, $a1, 4
/* 0CD198 7F098668 24840004 */  addiu $a0, $a0, 4
/* 0CD19C 7F09866C 24630004 */  addiu $v1, $v1, 4
/* 0CD1A0 7F098670 24C60004 */  addiu $a2, $a2, 4
/* 0CD1A4 7F098674 14A2FFE9 */  bne   $a1, $v0, .L7F09861C
/* 0CD1A8 7F098678 E4A4FFFC */   swc1  $f4, -4($a1)
/* 0CD1AC 7F09867C 44811000 */  mtc1  $at, $f2
/* 0CD1B0 7F098680 C7A801E0 */  lwc1  $f8, 0x1e0($sp)
/* 0CD1B4 7F098684 C7AA0200 */  lwc1  $f10, 0x200($sp)
/* 0CD1B8 7F098688 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0CD1BC 7F09868C 46081182 */  mul.s $f6, $f2, $f8
/* 0CD1C0 7F098690 C7A801C0 */  lwc1  $f8, 0x1c0($sp)
/* 0CD1C4 7F098694 46065100 */  add.s $f4, $f10, $f6
/* 0CD1C8 7F098698 C7A601E4 */  lwc1  $f6, 0x1e4($sp)
/* 0CD1CC 7F09869C C7AA0204 */  lwc1  $f10, 0x204($sp)
/* 0CD1D0 7F0986A0 46044000 */  add.s $f0, $f8, $f4
/* 0CD1D4 7F0986A4 46061202 */  mul.s $f8, $f2, $f6
/* 0CD1D8 7F0986A8 C7A601C4 */  lwc1  $f6, 0x1c4($sp)
/* 0CD1DC 7F0986AC 46085100 */  add.s $f4, $f10, $f8
/* 0CD1E0 7F0986B0 C7A801E8 */  lwc1  $f8, 0x1e8($sp)
/* 0CD1E4 7F0986B4 C7AA0208 */  lwc1  $f10, 0x208($sp)
/* 0CD1E8 7F0986B8 46043300 */  add.s $f12, $f6, $f4
/* 0CD1EC 7F0986BC 46081182 */  mul.s $f6, $f2, $f8
/* 0CD1F0 7F0986C0 44811000 */  mtc1  $at, $f2
/* 0CD1F4 7F0986C4 C7A801C8 */  lwc1  $f8, 0x1c8($sp)
/* 0CD1F8 7F0986C8 460C003C */  c.lt.s $f0, $f12
/* 0CD1FC 7F0986CC 3C013A80 */  li    $at, 0x3A800000 # 0.000977
/* 0CD200 7F0986D0 E7AC01A4 */  swc1  $f12, 0x1a4($sp)
/* 0CD204 7F0986D4 46065100 */  add.s $f4, $f10, $f6
/* 0CD208 7F0986D8 44815000 */  mtc1  $at, $f10
/* 0CD20C 7F0986DC 45000003 */  bc1f  .L7F0986EC
/* 0CD210 7F0986E0 46044380 */   add.s $f14, $f8, $f4
/* 0CD214 7F0986E4 46006006 */  mov.s $f0, $f12
/* 0CD218 7F0986E8 E7AC01A4 */  swc1  $f12, 0x1a4($sp)
.L7F0986EC:
/* 0CD21C 7F0986EC 460E003C */  c.lt.s $f0, $f14
/* 0CD220 7F0986F0 E7AE01A8 */  swc1  $f14, 0x1a8($sp)
/* 0CD224 7F0986F4 45000003 */  bc1f  .L7F098704
/* 0CD228 7F0986F8 00000000 */   nop   
/* 0CD22C 7F0986FC 46007006 */  mov.s $f0, $f14
/* 0CD230 7F098700 E7AE01A8 */  swc1  $f14, 0x1a8($sp)
.L7F098704:
/* 0CD234 7F098704 460A0002 */  mul.s $f0, $f0, $f10
/* 0CD238 7F098708 4600103C */  c.lt.s $f2, $f0
/* 0CD23C 7F09870C 00000000 */  nop   
/* 0CD240 7F098710 45020005 */  bc1fl .L7F098728
/* 0CD244 7F098714 E7A001A0 */   swc1  $f0, 0x1a0($sp)
/* 0CD248 7F098718 46001503 */  div.s $f20, $f2, $f0
/* 0CD24C 7F09871C 10000003 */  b     .L7F09872C
/* 0CD250 7F098720 E7A001A0 */   swc1  $f0, 0x1a0($sp)
/* 0CD254 7F098724 E7A001A0 */  swc1  $f0, 0x1a0($sp)
.L7F098728:
/* 0CD258 7F098728 46001506 */  mov.s $f20, $f2
.L7F09872C:
/* 0CD25C 7F09872C C7A60220 */  lwc1  $f6, 0x220($sp)
/* 0CD260 7F098730 E7B40190 */  swc1  $f20, 0x190($sp)
/* 0CD264 7F098734 4606A302 */  mul.s $f12, $f20, $f6
/* 0CD268 7F098738 0FC250A6 */  jal   sub_GAME_7F094298
/* 0CD26C 7F09873C 00000000 */   nop   
/* 0CD270 7F098740 C7B40190 */  lwc1  $f20, 0x190($sp)
/* 0CD274 7F098744 C7A80224 */  lwc1  $f8, 0x224($sp)
/* 0CD278 7F098748 AFA200E8 */  sw    $v0, 0xe8($sp)
/* 0CD27C 7F09874C 4608A302 */  mul.s $f12, $f20, $f8
/* 0CD280 7F098750 0FC250A6 */  jal   sub_GAME_7F094298
/* 0CD284 7F098754 00000000 */   nop   
/* 0CD288 7F098758 C7B40190 */  lwc1  $f20, 0x190($sp)
/* 0CD28C 7F09875C C7A40228 */  lwc1  $f4, 0x228($sp)
/* 0CD290 7F098760 AFA200E4 */  sw    $v0, 0xe4($sp)
/* 0CD294 7F098764 4604A302 */  mul.s $f12, $f20, $f4
/* 0CD298 7F098768 0FC250A6 */  jal   sub_GAME_7F094298
/* 0CD29C 7F09876C 00000000 */   nop   
/* 0CD2A0 7F098770 C7B40190 */  lwc1  $f20, 0x190($sp)
/* 0CD2A4 7F098774 C7AA02A0 */  lwc1  $f10, 0x2a0($sp)
/* 0CD2A8 7F098778 AFA200E0 */  sw    $v0, 0xe0($sp)
/* 0CD2AC 7F09877C 460AA302 */  mul.s $f12, $f20, $f10
/* 0CD2B0 7F098780 0FC250A6 */  jal   sub_GAME_7F094298
/* 0CD2B4 7F098784 00000000 */   nop   
/* 0CD2B8 7F098788 C7B40190 */  lwc1  $f20, 0x190($sp)
/* 0CD2BC 7F09878C C7A602A4 */  lwc1  $f6, 0x2a4($sp)
/* 0CD2C0 7F098790 AFA200D8 */  sw    $v0, 0xd8($sp)
/* 0CD2C4 7F098794 4606A302 */  mul.s $f12, $f20, $f6
/* 0CD2C8 7F098798 0FC250A6 */  jal   sub_GAME_7F094298
/* 0CD2CC 7F09879C 00000000 */   nop   
/* 0CD2D0 7F0987A0 C7B40190 */  lwc1  $f20, 0x190($sp)
/* 0CD2D4 7F0987A4 C7A802A8 */  lwc1  $f8, 0x2a8($sp)
/* 0CD2D8 7F0987A8 AFA200D4 */  sw    $v0, 0xd4($sp)
/* 0CD2DC 7F0987AC 4608A302 */  mul.s $f12, $f20, $f8
/* 0CD2E0 7F0987B0 0FC250A6 */  jal   sub_GAME_7F094298
/* 0CD2E4 7F0987B4 00000000 */   nop   
/* 0CD2E8 7F0987B8 C7B40190 */  lwc1  $f20, 0x190($sp)
/* 0CD2EC 7F0987BC C7A402C0 */  lwc1  $f4, 0x2c0($sp)
/* 0CD2F0 7F0987C0 AFA200D0 */  sw    $v0, 0xd0($sp)
/* 0CD2F4 7F0987C4 4604A302 */  mul.s $f12, $f20, $f4
/* 0CD2F8 7F0987C8 0FC250A6 */  jal   sub_GAME_7F094298
/* 0CD2FC 7F0987CC 00000000 */   nop   
/* 0CD300 7F0987D0 C7B40190 */  lwc1  $f20, 0x190($sp)
/* 0CD304 7F0987D4 C7AA02C4 */  lwc1  $f10, 0x2c4($sp)
/* 0CD308 7F0987D8 AFA200B8 */  sw    $v0, 0xb8($sp)
/* 0CD30C 7F0987DC 460AA302 */  mul.s $f12, $f20, $f10
/* 0CD310 7F0987E0 0FC250A6 */  jal   sub_GAME_7F094298
/* 0CD314 7F0987E4 00000000 */   nop   
/* 0CD318 7F0987E8 C7B40190 */  lwc1  $f20, 0x190($sp)
/* 0CD31C 7F0987EC C7A602C8 */  lwc1  $f6, 0x2c8($sp)
/* 0CD320 7F0987F0 AFA200B4 */  sw    $v0, 0xb4($sp)
/* 0CD324 7F0987F4 4606A302 */  mul.s $f12, $f20, $f6
/* 0CD328 7F0987F8 0FC250A6 */  jal   sub_GAME_7F094298
/* 0CD32C 7F0987FC 00000000 */   nop   
/* 0CD330 7F098800 C7B40190 */  lwc1  $f20, 0x190($sp)
/* 0CD334 7F098804 C7A80240 */  lwc1  $f8, 0x240($sp)
/* 0CD338 7F098808 AFA200B0 */  sw    $v0, 0xb0($sp)
/* 0CD33C 7F09880C 4608A302 */  mul.s $f12, $f20, $f8
/* 0CD340 7F098810 0FC250A6 */  jal   sub_GAME_7F094298
/* 0CD344 7F098814 00000000 */   nop   
/* 0CD348 7F098818 C7B40190 */  lwc1  $f20, 0x190($sp)
/* 0CD34C 7F09881C C7A40244 */  lwc1  $f4, 0x244($sp)
/* 0CD350 7F098820 AFA200C8 */  sw    $v0, 0xc8($sp)
/* 0CD354 7F098824 4604A302 */  mul.s $f12, $f20, $f4
/* 0CD358 7F098828 0FC250A6 */  jal   sub_GAME_7F094298
/* 0CD35C 7F09882C 00000000 */   nop   
/* 0CD360 7F098830 C7B40190 */  lwc1  $f20, 0x190($sp)
/* 0CD364 7F098834 C7AA0248 */  lwc1  $f10, 0x248($sp)
/* 0CD368 7F098838 AFA200C4 */  sw    $v0, 0xc4($sp)
/* 0CD36C 7F09883C 460AA302 */  mul.s $f12, $f20, $f10
/* 0CD370 7F098840 0FC250A6 */  jal   sub_GAME_7F094298
/* 0CD374 7F098844 00000000 */   nop   
/* 0CD378 7F098848 8FAD00E4 */  lw    $t5, 0xe4($sp)
/* 0CD37C 7F09884C 8FAC00E8 */  lw    $t4, 0xe8($sp)
/* 0CD380 7F098850 3C09FFFF */  lui   $t1, 0xffff
/* 0CD384 7F098854 8FA600C4 */  lw    $a2, 0xc4($sp)
/* 0CD388 7F098858 8FBF00E0 */  lw    $ra, 0xe0($sp)
/* 0CD38C 7F09885C 3C0EB400 */  lui   $t6, 0xb400
/* 0CD390 7F098860 01A9C024 */  and   $t8, $t5, $t1
/* 0CD394 7F098864 0018CC02 */  srl   $t9, $t8, 0x10
/* 0CD398 7F098868 AE0E0000 */  sw    $t6, ($s0)
/* 0CD39C 7F09886C 01897824 */  and   $t7, $t4, $t1
/* 0CD3A0 7F098870 01F97025 */  or    $t6, $t7, $t9
/* 0CD3A4 7F098874 26040008 */  addiu $a0, $s0, 8
/* 0CD3A8 7F098878 AE0E0004 */  sw    $t6, 4($s0)
/* 0CD3AC 7F09887C 3C18B200 */  lui   $t8, 0xb200
/* 0CD3B0 7F098880 03E97824 */  and   $t7, $ra, $t1
/* 0CD3B4 7F098884 AC8F0004 */  sw    $t7, 4($a0)
/* 0CD3B8 7F098888 AC980000 */  sw    $t8, ($a0)
/* 0CD3BC 7F09888C 24850008 */  addiu $a1, $a0, 8
/* 0CD3C0 7F098890 3C19B400 */  lui   $t9, 0xb400
/* 0CD3C4 7F098894 ACB90000 */  sw    $t9, ($a1)
/* 0CD3C8 7F098898 8FAF00D4 */  lw    $t7, 0xd4($sp)
/* 0CD3CC 7F09889C 8FAE00D8 */  lw    $t6, 0xd8($sp)
/* 0CD3D0 7F0988A0 24A70008 */  addiu $a3, $a1, 8
/* 0CD3D4 7F0988A4 01E9C824 */  and   $t9, $t7, $t1
/* 0CD3D8 7F0988A8 01C9C024 */  and   $t8, $t6, $t1
/* 0CD3DC 7F0988AC 00197402 */  srl   $t6, $t9, 0x10
/* 0CD3E0 7F0988B0 030E7825 */  or    $t7, $t8, $t6
/* 0CD3E4 7F0988B4 ACAF0004 */  sw    $t7, 4($a1)
/* 0CD3E8 7F0988B8 8FAB00D0 */  lw    $t3, 0xd0($sp)
/* 0CD3EC 7F0988BC 3C19B200 */  lui   $t9, 0xb200
/* 0CD3F0 7F0988C0 ACF90000 */  sw    $t9, ($a3)
/* 0CD3F4 7F0988C4 0169C024 */  and   $t8, $t3, $t1
/* 0CD3F8 7F0988C8 ACF80004 */  sw    $t8, 4($a3)
/* 0CD3FC 7F0988CC 24E30008 */  addiu $v1, $a3, 8
/* 0CD400 7F0988D0 3C0EB400 */  lui   $t6, 0xb400
/* 0CD404 7F0988D4 AC6E0000 */  sw    $t6, ($v1)
/* 0CD408 7F0988D8 31B8FFFF */  andi  $t8, $t5, 0xffff
/* 0CD40C 7F0988DC 000CCC00 */  sll   $t9, $t4, 0x10
/* 0CD410 7F0988E0 03387025 */  or    $t6, $t9, $t8
/* 0CD414 7F0988E4 AC6E0004 */  sw    $t6, 4($v1)
/* 0CD418 7F0988E8 24700008 */  addiu $s0, $v1, 8
/* 0CD41C 7F0988EC 3C0FB200 */  lui   $t7, 0xb200
/* 0CD420 7F0988F0 001FC400 */  sll   $t8, $ra, 0x10
/* 0CD424 7F0988F4 AE180004 */  sw    $t8, 4($s0)
/* 0CD428 7F0988F8 AE0F0000 */  sw    $t7, ($s0)
/* 0CD42C 7F0988FC 26080008 */  addiu $t0, $s0, 8
/* 0CD430 7F098900 3C0EB400 */  lui   $t6, 0xb400
/* 0CD434 7F098904 AD0E0000 */  sw    $t6, ($t0)
/* 0CD438 7F098908 8FAE00D4 */  lw    $t6, 0xd4($sp)
/* 0CD43C 7F09890C 8FB900D8 */  lw    $t9, 0xd8($sp)
/* 0CD440 7F098910 8FA700C8 */  lw    $a3, 0xc8($sp)
/* 0CD444 7F098914 31CFFFFF */  andi  $t7, $t6, 0xffff
/* 0CD448 7F098918 0019C400 */  sll   $t8, $t9, 0x10
/* 0CD44C 7F09891C 030FC825 */  or    $t9, $t8, $t7
/* 0CD450 7F098920 AD190004 */  sw    $t9, 4($t0)
/* 0CD454 7F098924 25030008 */  addiu $v1, $t0, 8
/* 0CD458 7F098928 3C0EB200 */  lui   $t6, 0xb200
/* 0CD45C 7F09892C 000B7C00 */  sll   $t7, $t3, 0x10
/* 0CD460 7F098930 AC6F0004 */  sw    $t7, 4($v1)
/* 0CD464 7F098934 AC6E0000 */  sw    $t6, ($v1)
/* 0CD468 7F098938 24640008 */  addiu $a0, $v1, 8
/* 0CD46C 7F09893C 3C19B400 */  lui   $t9, 0xb400
/* 0CD470 7F098940 00C9C024 */  and   $t8, $a2, $t1
/* 0CD474 7F098944 00187C02 */  srl   $t7, $t8, 0x10
/* 0CD478 7F098948 AC990000 */  sw    $t9, ($a0)
/* 0CD47C 7F09894C 00E97024 */  and   $t6, $a3, $t1
/* 0CD480 7F098950 01CFC825 */  or    $t9, $t6, $t7
/* 0CD484 7F098954 AC990004 */  sw    $t9, 4($a0)
/* 0CD488 7F098958 24850008 */  addiu $a1, $a0, 8
/* 0CD48C 7F09895C 00497024 */  and   $t6, $v0, $t1
/* 0CD490 7F098960 3C18B200 */  lui   $t8, 0xb200
/* 0CD494 7F098964 ACB80000 */  sw    $t8, ($a1)
/* 0CD498 7F098968 ACAE0004 */  sw    $t6, 4($a1)
/* 0CD49C 7F09896C 8FA800B4 */  lw    $t0, 0xb4($sp)
/* 0CD4A0 7F098970 8FAC00B8 */  lw    $t4, 0xb8($sp)
/* 0CD4A4 7F098974 00405025 */  move  $t2, $v0
/* 0CD4A8 7F098978 24B00008 */  addiu $s0, $a1, 8
/* 0CD4AC 7F09897C 8FAB00B0 */  lw    $t3, 0xb0($sp)
/* 0CD4B0 7F098980 02001025 */  move  $v0, $s0
/* 0CD4B4 7F098984 3C0FB400 */  lui   $t7, 0xb400
/* 0CD4B8 7F098988 0109C024 */  and   $t8, $t0, $t1
/* 0CD4BC 7F09898C 00187402 */  srl   $t6, $t8, 0x10
/* 0CD4C0 7F098990 AC4F0000 */  sw    $t7, ($v0)
/* 0CD4C4 7F098994 0189C824 */  and   $t9, $t4, $t1
/* 0CD4C8 7F098998 032E7825 */  or    $t7, $t9, $t6
/* 0CD4CC 7F09899C AC4F0004 */  sw    $t7, 4($v0)
/* 0CD4D0 7F0989A0 26030008 */  addiu $v1, $s0, 8
/* 0CD4D4 7F0989A4 3C18B200 */  lui   $t8, 0xb200
/* 0CD4D8 7F0989A8 0169C824 */  and   $t9, $t3, $t1
/* 0CD4DC 7F0989AC AC790004 */  sw    $t9, 4($v1)
/* 0CD4E0 7F0989B0 AC780000 */  sw    $t8, ($v1)
/* 0CD4E4 7F0989B4 24700008 */  addiu $s0, $v1, 8
/* 0CD4E8 7F0989B8 3C0EB400 */  lui   $t6, 0xb400
/* 0CD4EC 7F0989BC AE0E0000 */  sw    $t6, ($s0)
/* 0CD4F0 7F0989C0 30D9FFFF */  andi  $t9, $a2, 0xffff
/* 0CD4F4 7F0989C4 0007C400 */  sll   $t8, $a3, 0x10
/* 0CD4F8 7F0989C8 03197025 */  or    $t6, $t8, $t9
/* 0CD4FC 7F0989CC AE0E0004 */  sw    $t6, 4($s0)
/* 0CD500 7F0989D0 26050008 */  addiu $a1, $s0, 8
/* 0CD504 7F0989D4 000ACC00 */  sll   $t9, $t2, 0x10
/* 0CD508 7F0989D8 ACB90004 */  sw    $t9, 4($a1)
/* 0CD50C 7F0989DC 3C0FB200 */  lui   $t7, 0xb200
/* 0CD510 7F0989E0 ACAF0000 */  sw    $t7, ($a1)
/* 0CD514 7F0989E4 24A30008 */  addiu $v1, $a1, 8
/* 0CD518 7F0989E8 3C0EB400 */  lui   $t6, 0xb400
/* 0CD51C 7F0989EC AC6E0000 */  sw    $t6, ($v1)
/* 0CD520 7F0989F0 3119FFFF */  andi  $t9, $t0, 0xffff
/* 0CD524 7F0989F4 000CC400 */  sll   $t8, $t4, 0x10
/* 0CD528 7F0989F8 03197025 */  or    $t6, $t8, $t9
/* 0CD52C 7F0989FC 24640008 */  addiu $a0, $v1, 8
/* 0CD530 7F098A00 AC6E0004 */  sw    $t6, 4($v1)
/* 0CD534 7F098A04 3C0FB300 */  lui   $t7, 0xb300
/* 0CD538 7F098A08 000BCC00 */  sll   $t9, $t3, 0x10
/* 0CD53C 7F098A0C AC990004 */  sw    $t9, 4($a0)
/* 0CD540 7F098A10 AC8F0000 */  sw    $t7, ($a0)
/* 0CD544 7F098A14 24820008 */  addiu $v0, $a0, 8
.L7F098A18:
/* 0CD548 7F098A18 8FBF0024 */  lw    $ra, 0x24($sp)
/* 0CD54C 7F098A1C D7B40018 */  ldc1  $f20, 0x18($sp)
/* 0CD550 7F098A20 8FB00020 */  lw    $s0, 0x20($sp)
/* 0CD554 7F098A24 03E00008 */  jr    $ra
/* 0CD558 7F098A28 27BD0488 */   addiu $sp, $sp, 0x488
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F098A2C(void) {

}
#else
GLOBAL_ASM(
.late_rodata
glabel D_800575F8
.word 0xc4eac000 /*-1878.0*/
glabel D_800575FC
.word 0xc4eac000 /*-1878.0*/
glabel D_80057600
.word 0xc4eac000 /*-1878.0*/
glabel D_80057604
.word 0xc4eac000 /*-1878.0*/
glabel D_80057608
.word 0x44eaa000 /*1877.0*/
glabel D_8005760C
.word 0x46fffe00 /*32767.0*/
.text
glabel sub_GAME_7F098A2C
/* 0CD55C 7F098A2C 27BDFB30 */  addiu $sp, $sp, -0x4d0
/* 0CD560 7F098A30 AFB00020 */  sw    $s0, 0x20($sp)
/* 0CD564 7F098A34 00808025 */  move  $s0, $a0
/* 0CD568 7F098A38 AFBF0024 */  sw    $ra, 0x24($sp)
/* 0CD56C 7F098A3C AFA504D4 */  sw    $a1, 0x4d4($sp)
/* 0CD570 7F098A40 00A02025 */  move  $a0, $a1
/* 0CD574 7F098A44 F7B40018 */  sdc1  $f20, 0x18($sp)
/* 0CD578 7F098A48 AFA604D8 */  sw    $a2, 0x4d8($sp)
/* 0CD57C 7F098A4C AFA704DC */  sw    $a3, 0x4dc($sp)
/* 0CD580 7F098A50 0FC25DED */  jal   sub_GAME_7F0977B4
/* 0CD584 7F098A54 00C02825 */   move  $a1, $a2
/* 0CD588 7F098A58 14400015 */  bnez  $v0, .L7F098AB0
/* 0CD58C 7F098A5C 8FA404D8 */   lw    $a0, 0x4d8($sp)
/* 0CD590 7F098A60 0FC25DED */  jal   sub_GAME_7F0977B4
/* 0CD594 7F098A64 8FA504DC */   lw    $a1, 0x4dc($sp)
/* 0CD598 7F098A68 14400011 */  bnez  $v0, .L7F098AB0
/* 0CD59C 7F098A6C 8FA404DC */   lw    $a0, 0x4dc($sp)
/* 0CD5A0 7F098A70 0FC25DED */  jal   sub_GAME_7F0977B4
/* 0CD5A4 7F098A74 8FA504D4 */   lw    $a1, 0x4d4($sp)
/* 0CD5A8 7F098A78 1440000D */  bnez  $v0, .L7F098AB0
/* 0CD5AC 7F098A7C 8FA404E0 */   lw    $a0, 0x4e0($sp)
/* 0CD5B0 7F098A80 0FC25DED */  jal   sub_GAME_7F0977B4
/* 0CD5B4 7F098A84 8FA504D4 */   lw    $a1, 0x4d4($sp)
/* 0CD5B8 7F098A88 14400009 */  bnez  $v0, .L7F098AB0
/* 0CD5BC 7F098A8C 8FA404E0 */   lw    $a0, 0x4e0($sp)
/* 0CD5C0 7F098A90 0FC25DED */  jal   sub_GAME_7F0977B4
/* 0CD5C4 7F098A94 8FA504D8 */   lw    $a1, 0x4d8($sp)
/* 0CD5C8 7F098A98 14400005 */  bnez  $v0, .L7F098AB0
/* 0CD5CC 7F098A9C 8FA404E0 */   lw    $a0, 0x4e0($sp)
/* 0CD5D0 7F098AA0 0FC25DED */  jal   sub_GAME_7F0977B4
/* 0CD5D4 7F098AA4 8FA504DC */   lw    $a1, 0x4dc($sp)
/* 0CD5D8 7F098AA8 10400003 */  beqz  $v0, .L7F098AB8
/* 0CD5DC 7F098AAC C7A404E4 */   lwc1  $f4, 0x4e4($sp)
.L7F098AB0:
/* 0CD5E0 7F098AB0 10000606 */  b     .L7F09A2CC
/* 0CD5E4 7F098AB4 02001025 */   move  $v0, $s0
.L7F098AB8:
/* 0CD5E8 7F098AB8 3C014780 */  li    $at, 0x47800000 # 65536.000000
/* 0CD5EC 7F098ABC 44813000 */  mtc1  $at, $f6
/* 0CD5F0 7F098AC0 8FA304D4 */  lw    $v1, 0x4d4($sp)
/* 0CD5F4 7F098AC4 8FA404DC */  lw    $a0, 0x4dc($sp)
/* 0CD5F8 7F098AC8 46062203 */  div.s $f8, $f4, $f6
/* 0CD5FC 7F098ACC 8FA904D8 */  lw    $t1, 0x4d8($sp)
/* 0CD600 7F098AD0 00603825 */  move  $a3, $v1
/* 0CD604 7F098AD4 00804025 */  move  $t0, $a0
/* 0CD608 7F098AD8 01202825 */  move  $a1, $t1
/* 0CD60C 7F098ADC E7A803C0 */  swc1  $f8, 0x3c0($sp)
/* 0CD610 7F098AE0 C46C0028 */  lwc1  $f12, 0x28($v1)
/* 0CD614 7F098AE4 C4840028 */  lwc1  $f4, 0x28($a0)
/* 0CD618 7F098AE8 C460002C */  lwc1  $f0, 0x2c($v1)
/* 0CD61C 7F098AEC C52E002C */  lwc1  $f14, 0x2c($t1)
/* 0CD620 7F098AF0 460C2181 */  sub.s $f6, $f4, $f12
/* 0CD624 7F098AF4 C52A0028 */  lwc1  $f10, 0x28($t1)
/* 0CD628 7F098AF8 46007081 */  sub.s $f2, $f14, $f0
/* 0CD62C 7F098AFC E7A604B0 */  swc1  $f6, 0x4b0($sp)
/* 0CD630 7F098B00 C494002C */  lwc1  $f20, 0x2c($a0)
/* 0CD634 7F098B04 C7A804B0 */  lwc1  $f8, 0x4b0($sp)
/* 0CD638 7F098B08 460C5481 */  sub.s $f18, $f10, $f12
/* 0CD63C 7F098B0C 46024282 */  mul.s $f10, $f8, $f2
/* 0CD640 7F098B10 4600A401 */  sub.s $f16, $f20, $f0
/* 0CD644 7F098B14 44814000 */  mtc1  $at, $f8
/* 0CD648 7F098B18 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0CD64C 7F098B1C 46109102 */  mul.s $f4, $f18, $f16
/* 0CD650 7F098B20 4600703C */  c.lt.s $f14, $f0
/* 0CD654 7F098B24 46045181 */  sub.s $f6, $f10, $f4
/* 0CD658 7F098B28 44812000 */  mtc1  $at, $f4
/* 0CD65C 7F098B2C 46083283 */  div.s $f10, $f6, $f8
/* 0CD660 7F098B30 460A2183 */  div.s $f6, $f4, $f10
/* 0CD664 7F098B34 E7AA0054 */  swc1  $f10, 0x54($sp)
/* 0CD668 7F098B38 E7AA0488 */  swc1  $f10, 0x488($sp)
/* 0CD66C 7F098B3C E7A60050 */  swc1  $f6, 0x50($sp)
/* 0CD670 7F098B40 4500000A */  bc1f  .L7F098B6C
/* 0CD674 7F098B44 E7A60484 */   swc1  $f6, 0x484($sp)
/* 0CD678 7F098B48 3C01BF80 */  li    $at, 0xBF800000 # -1.000000
/* 0CD67C 7F098B4C 44811000 */  mtc1  $at, $f2
/* 0CD680 7F098B50 00602825 */  move  $a1, $v1
/* 0CD684 7F098B54 01203825 */  move  $a3, $t1
/* 0CD688 7F098B58 46025302 */  mul.s $f12, $f10, $f2
/* 0CD68C 7F098B5C 00000000 */  nop   
/* 0CD690 7F098B60 46023382 */  mul.s $f14, $f6, $f2
/* 0CD694 7F098B64 E7AC0488 */  swc1  $f12, 0x488($sp)
/* 0CD698 7F098B68 E7AE0484 */  swc1  $f14, 0x484($sp)
.L7F098B6C:
/* 0CD69C 7F098B6C C4A0002C */  lwc1  $f0, 0x2c($a1)
/* 0CD6A0 7F098B70 3C01BF80 */  li    $at, 0xBF800000 # -1.000000
/* 0CD6A4 7F098B74 44811000 */  mtc1  $at, $f2
/* 0CD6A8 7F098B78 4600A03C */  c.lt.s $f20, $f0
/* 0CD6AC 7F098B7C C7AC0488 */  lwc1  $f12, 0x488($sp)
/* 0CD6B0 7F098B80 C7AE0484 */  lwc1  $f14, 0x484($sp)
/* 0CD6B4 7F098B84 3C014080 */  li    $at, 0x40800000 # 4.000000
/* 0CD6B8 7F098B88 45020006 */  bc1fl .L7F098BA4
/* 0CD6BC 7F098B8C E7AE0484 */   swc1  $f14, 0x484($sp)
/* 0CD6C0 7F098B90 00A04025 */  move  $t0, $a1
/* 0CD6C4 7F098B94 46027382 */  mul.s $f14, $f14, $f2
/* 0CD6C8 7F098B98 00802825 */  move  $a1, $a0
/* 0CD6CC 7F098B9C C480002C */  lwc1  $f0, 0x2c($a0)
/* 0CD6D0 7F098BA0 E7AE0484 */  swc1  $f14, 0x484($sp)
.L7F098BA4:
/* 0CD6D4 7F098BA4 C4E8002C */  lwc1  $f8, 0x2c($a3)
/* 0CD6D8 7F098BA8 4608003C */  c.lt.s $f0, $f8
/* 0CD6DC 7F098BAC 44810000 */  mtc1  $at, $f0
/* 0CD6E0 7F098BB0 3C013E80 */  li    $at, 0x3E800000 # 0.250000
/* 0CD6E4 7F098BB4 44815000 */  mtc1  $at, $f10
/* 0CD6E8 7F098BB8 45020007 */  bc1fl .L7F098BD8
/* 0CD6EC 7F098BBC C4A40028 */   lwc1  $f4, 0x28($a1)
/* 0CD6F0 7F098BC0 46027382 */  mul.s $f14, $f14, $f2
/* 0CD6F4 7F098BC4 00A01025 */  move  $v0, $a1
/* 0CD6F8 7F098BC8 00E02825 */  move  $a1, $a3
/* 0CD6FC 7F098BCC 00403825 */  move  $a3, $v0
/* 0CD700 7F098BD0 E7AE0484 */  swc1  $f14, 0x484($sp)
/* 0CD704 7F098BD4 C4A40028 */  lwc1  $f4, 0x28($a1)
.L7F098BD8:
/* 0CD708 7F098BD8 4480A000 */  mtc1  $zero, $f20
/* 0CD70C 7F098BDC 3C0644EA */  lui   $a2, (0x44EAA000 >> 16) # lui $a2, 0x44ea
/* 0CD710 7F098BE0 460A2182 */  mul.s $f6, $f4, $f10
/* 0CD714 7F098BE4 E7B40468 */  swc1  $f20, 0x468($sp)
/* 0CD718 7F098BE8 44812000 */  mtc1  $at, $f4
/* 0CD71C 7F098BEC 34C6A000 */  ori   $a2, (0x44EAA000 & 0xFFFF) # ori $a2, $a2, 0xa000
/* 0CD720 7F098BF0 E7A60464 */  swc1  $f6, 0x464($sp)
/* 0CD724 7F098BF4 C4E80028 */  lwc1  $f8, 0x28($a3)
/* 0CD728 7F098BF8 E7B40470 */  swc1  $f20, 0x470($sp)
/* 0CD72C 7F098BFC 46044282 */  mul.s $f10, $f8, $f4
/* 0CD730 7F098C00 44814000 */  mtc1  $at, $f8
/* 0CD734 7F098C04 E7AA046C */  swc1  $f10, 0x46c($sp)
/* 0CD738 7F098C08 C4E60028 */  lwc1  $f6, 0x28($a3)
/* 0CD73C 7F098C0C E7B40478 */  swc1  $f20, 0x478($sp)
/* 0CD740 7F098C10 E7B40480 */  swc1  $f20, 0x480($sp)
/* 0CD744 7F098C14 46083102 */  mul.s $f4, $f6, $f8
/* 0CD748 7F098C18 E7B4047C */  swc1  $f20, 0x47c($sp)
/* 0CD74C 7F098C1C E7A40474 */  swc1  $f4, 0x474($sp)
/* 0CD750 7F098C20 C50A0028 */  lwc1  $f10, 0x28($t0)
/* 0CD754 7F098C24 E7AA048C */  swc1  $f10, 0x48c($sp)
/* 0CD758 7F098C28 C506002C */  lwc1  $f6, 0x2c($t0)
/* 0CD75C 7F098C2C E7A60490 */  swc1  $f6, 0x490($sp)
/* 0CD760 7F098C30 C4A80028 */  lwc1  $f8, 0x28($a1)
/* 0CD764 7F098C34 E7A80494 */  swc1  $f8, 0x494($sp)
/* 0CD768 7F098C38 C4A4002C */  lwc1  $f4, 0x2c($a1)
/* 0CD76C 7F098C3C C7A80494 */  lwc1  $f8, 0x494($sp)
/* 0CD770 7F098C40 E7A40498 */  swc1  $f4, 0x498($sp)
/* 0CD774 7F098C44 C4EA0028 */  lwc1  $f10, 0x28($a3)
/* 0CD778 7F098C48 E7AA049C */  swc1  $f10, 0x49c($sp)
/* 0CD77C 7F098C4C C4E6002C */  lwc1  $f6, 0x2c($a3)
/* 0CD780 7F098C50 C7AA0498 */  lwc1  $f10, 0x498($sp)
/* 0CD784 7F098C54 C7A4049C */  lwc1  $f4, 0x49c($sp)
/* 0CD788 7F098C58 E7A604A0 */  swc1  $f6, 0x4a0($sp)
/* 0CD78C 7F098C5C C7A604A0 */  lwc1  $f6, 0x4a0($sp)
/* 0CD790 7F098C60 E7AA002C */  swc1  $f10, 0x2c($sp)
/* 0CD794 7F098C64 E7A80028 */  swc1  $f8, 0x28($sp)
/* 0CD798 7F098C68 46065081 */  sub.s $f2, $f10, $f6
/* 0CD79C 7F098C6C C7AA0490 */  lwc1  $f10, 0x490($sp)
/* 0CD7A0 7F098C70 AFA804C4 */  sw    $t0, 0x4c4($sp)
/* 0CD7A4 7F098C74 46044481 */  sub.s $f18, $f8, $f4
/* 0CD7A8 7F098C78 C7A8048C */  lwc1  $f8, 0x48c($sp)
/* 0CD7AC 7F098C7C AFA704CC */  sw    $a3, 0x4cc($sp)
/* 0CD7B0 7F098C80 46065401 */  sub.s $f16, $f10, $f6
/* 0CD7B4 7F098C84 C7A60028 */  lwc1  $f6, 0x28($sp)
/* 0CD7B8 7F098C88 AFA504C8 */  sw    $a1, 0x4c8($sp)
/* 0CD7BC 7F098C8C 46044101 */  sub.s $f4, $f8, $f4
/* 0CD7C0 7F098C90 E7B40440 */  swc1  $f20, 0x440($sp)
/* 0CD7C4 7F098C94 E7B4043C */  swc1  $f20, 0x43c($sp)
/* 0CD7C8 7F098C98 46064301 */  sub.s $f12, $f8, $f6
/* 0CD7CC 7F098C9C C7A8002C */  lwc1  $f8, 0x2c($sp)
/* 0CD7D0 7F098CA0 44813000 */  mtc1  $at, $f6
/* 0CD7D4 7F098CA4 E7A404B0 */  swc1  $f4, 0x4b0($sp)
/* 0CD7D8 7F098CA8 46085381 */  sub.s $f14, $f10, $f8
/* 0CD7DC 7F098CAC 46066282 */  mul.s $f10, $f12, $f6
/* 0CD7E0 7F098CB0 44814000 */  mtc1  $at, $f8
/* 0CD7E4 7F098CB4 E7AC04A8 */  swc1  $f12, 0x4a8($sp)
/* 0CD7E8 7F098CB8 E7AE04A4 */  swc1  $f14, 0x4a4($sp)
/* 0CD7EC 7F098CBC 46087182 */  mul.s $f6, $f14, $f8
/* 0CD7F0 7F098CC0 E7B40420 */  swc1  $f20, 0x420($sp)
/* 0CD7F4 7F098CC4 E7B4041C */  swc1  $f20, 0x41c($sp)
/* 0CD7F8 7F098CC8 E7AA0424 */  swc1  $f10, 0x424($sp)
/* 0CD7FC 7F098CCC 44815000 */  mtc1  $at, $f10
/* 0CD800 7F098CD0 E7B403E4 */  swc1  $f20, 0x3e4($sp)
/* 0CD804 7F098CD4 E7B403EC */  swc1  $f20, 0x3ec($sp)
/* 0CD808 7F098CD8 460A9202 */  mul.s $f8, $f18, $f10
/* 0CD80C 7F098CDC E7A60428 */  swc1  $f6, 0x428($sp)
/* 0CD810 7F098CE0 44813000 */  mtc1  $at, $f6
/* 0CD814 7F098CE4 E7B403F4 */  swc1  $f20, 0x3f4($sp)
/* 0CD818 7F098CE8 E7B40400 */  swc1  $f20, 0x400($sp)
/* 0CD81C 7F098CEC 46061282 */  mul.s $f10, $f2, $f6
/* 0CD820 7F098CF0 E7B403FC */  swc1  $f20, 0x3fc($sp)
/* 0CD824 7F098CF4 E7A8042C */  swc1  $f8, 0x42c($sp)
/* 0CD828 7F098CF8 44814000 */  mtc1  $at, $f8
/* 0CD82C 7F098CFC E7B403C4 */  swc1  $f20, 0x3c4($sp)
/* 0CD830 7F098D00 E7B403CC */  swc1  $f20, 0x3cc($sp)
/* 0CD834 7F098D04 46082182 */  mul.s $f6, $f4, $f8
/* 0CD838 7F098D08 E7AA0430 */  swc1  $f10, 0x430($sp)
/* 0CD83C 7F098D0C 44815000 */  mtc1  $at, $f10
/* 0CD840 7F098D10 3C018005 */  lui   $at, %hi(D_800575F8)
/* 0CD844 7F098D14 E7B403D4 */  swc1  $f20, 0x3d4($sp)
/* 0CD848 7F098D18 460A8202 */  mul.s $f8, $f16, $f10
/* 0CD84C 7F098D1C E7B403E0 */  swc1  $f20, 0x3e0($sp)
/* 0CD850 7F098D20 E7A60434 */  swc1  $f6, 0x434($sp)
/* 0CD854 7F098D24 46006182 */  mul.s $f6, $f12, $f0
/* 0CD858 7F098D28 E7B403DC */  swc1  $f20, 0x3dc($sp)
/* 0CD85C 7F098D2C 46007282 */  mul.s $f10, $f14, $f0
/* 0CD860 7F098D30 E7A80438 */  swc1  $f8, 0x438($sp)
/* 0CD864 7F098D34 C42E75F8 */  lwc1  $f14, %lo(D_800575F8)($at)
/* 0CD868 7F098D38 46009202 */  mul.s $f8, $f18, $f0
/* 0CD86C 7F098D3C E7A60404 */  swc1  $f6, 0x404($sp)
/* 0CD870 7F098D40 46001182 */  mul.s $f6, $f2, $f0
/* 0CD874 7F098D44 E7AA0408 */  swc1  $f10, 0x408($sp)
/* 0CD878 7F098D48 46002282 */  mul.s $f10, $f4, $f0
/* 0CD87C 7F098D4C E7A8040C */  swc1  $f8, 0x40c($sp)
/* 0CD880 7F098D50 46008202 */  mul.s $f8, $f16, $f0
/* 0CD884 7F098D54 E7A60410 */  swc1  $f6, 0x410($sp)
/* 0CD888 7F098D58 C7A604A4 */  lwc1  $f6, 0x4a4($sp)
/* 0CD88C 7F098D5C E7AA0414 */  swc1  $f10, 0x414($sp)
/* 0CD890 7F098D60 46060283 */  div.s $f10, $f0, $f6
/* 0CD894 7F098D64 E7A80418 */  swc1  $f8, 0x418($sp)
/* 0CD898 7F098D68 46020203 */  div.s $f8, $f0, $f2
/* 0CD89C 7F098D6C E7AA03E8 */  swc1  $f10, 0x3e8($sp)
/* 0CD8A0 7F098D70 46100283 */  div.s $f10, $f0, $f16
/* 0CD8A4 7F098D74 E7A803F0 */  swc1  $f8, 0x3f0($sp)
/* 0CD8A8 7F098D78 C7A804A8 */  lwc1  $f8, 0x4a8($sp)
/* 0CD8AC 7F098D7C 46064303 */  div.s $f12, $f8, $f6
/* 0CD8B0 7F098D80 E7AA03F8 */  swc1  $f10, 0x3f8($sp)
/* 0CD8B4 7F098D84 46029283 */  div.s $f10, $f18, $f2
/* 0CD8B8 7F098D88 E7AC03C8 */  swc1  $f12, 0x3c8($sp)
/* 0CD8BC 7F098D8C 46102203 */  div.s $f8, $f4, $f16
/* 0CD8C0 7F098D90 E7AA03D0 */  swc1  $f10, 0x3d0($sp)
/* 0CD8C4 7F098D94 0FC24F12 */  jal   sub_GAME_7F093C48
/* 0CD8C8 7F098D98 E7A803D8 */   swc1  $f8, 0x3d8($sp)
/* 0CD8CC 7F098D9C 3C018005 */  lui   $at, %hi(D_800575FC)
/* 0CD8D0 7F098DA0 3C0644EA */  lui   $a2, (0x44EAA000 >> 16) # lui $a2, 0x44ea
/* 0CD8D4 7F098DA4 E7A003C8 */  swc1  $f0, 0x3c8($sp)
/* 0CD8D8 7F098DA8 34C6A000 */  ori   $a2, (0x44EAA000 & 0xFFFF) # ori $a2, $a2, 0xa000
/* 0CD8DC 7F098DAC C42E75FC */  lwc1  $f14, %lo(D_800575FC)($at)
/* 0CD8E0 7F098DB0 0FC24F12 */  jal   sub_GAME_7F093C48
/* 0CD8E4 7F098DB4 C7AC03D0 */   lwc1  $f12, 0x3d0($sp)
/* 0CD8E8 7F098DB8 3C018005 */  lui   $at, %hi(D_80057600)
/* 0CD8EC 7F098DBC 3C0644EA */  lui   $a2, (0x44EAA000 >> 16) # lui $a2, 0x44ea
/* 0CD8F0 7F098DC0 E7A003D0 */  swc1  $f0, 0x3d0($sp)
/* 0CD8F4 7F098DC4 34C6A000 */  ori   $a2, (0x44EAA000 & 0xFFFF) # ori $a2, $a2, 0xa000
/* 0CD8F8 7F098DC8 C42E7600 */  lwc1  $f14, %lo(D_80057600)($at)
/* 0CD8FC 7F098DCC 0FC24F12 */  jal   sub_GAME_7F093C48
/* 0CD900 7F098DD0 C7AC03D8 */   lwc1  $f12, 0x3d8($sp)
/* 0CD904 7F098DD4 C7A6046C */  lwc1  $f6, 0x46c($sp)
/* 0CD908 7F098DD8 C7AA0474 */  lwc1  $f10, 0x474($sp)
/* 0CD90C 7F098DDC 8FAE04D4 */  lw    $t6, 0x4d4($sp)
/* 0CD910 7F098DE0 8FB804D8 */  lw    $t8, 0x4d8($sp)
/* 0CD914 7F098DE4 E7A003D8 */  swc1  $f0, 0x3d8($sp)
/* 0CD918 7F098DE8 E7A6044C */  swc1  $f6, 0x44c($sp)
/* 0CD91C 7F098DEC E7AA0454 */  swc1  $f10, 0x454($sp)
/* 0CD920 7F098DF0 C5C40028 */  lwc1  $f4, 0x28($t6)
/* 0CD924 7F098DF4 C7080028 */  lwc1  $f8, 0x28($t8)
/* 0CD928 7F098DF8 4608203C */  c.lt.s $f4, $f8
/* 0CD92C 7F098DFC 00000000 */  nop   
/* 0CD930 7F098E00 45020081 */  bc1fl .L7F099008
/* 0CD934 7F098E04 8FAE04DC */   lw    $t6, 0x4dc($sp)
/* 0CD938 7F098E08 8FB904DC */  lw    $t9, 0x4dc($sp)
/* 0CD93C 7F098E0C 8FAF04E0 */  lw    $t7, 0x4e0($sp)
/* 0CD940 7F098E10 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0CD944 7F098E14 C726002C */  lwc1  $f6, 0x2c($t9)
/* 0CD948 7F098E18 C5EA002C */  lwc1  $f10, 0x2c($t7)
/* 0CD94C 7F098E1C 44814000 */  mtc1  $at, $f8
/* 0CD950 7F098E20 460A3101 */  sub.s $f4, $f6, $f10
/* 0CD954 7F098E24 4608203C */  c.lt.s $f4, $f8
/* 0CD958 7F098E28 00000000 */  nop   
/* 0CD95C 7F098E2C 45000004 */  bc1f  .L7F098E40
/* 0CD960 7F098E30 3C018005 */   lui    $at, %hi(D_80057604)
/* 0CD964 7F098E34 C4267604 */  lwc1  $f6, %lo(D_80057604)($at)
/* 0CD968 7F098E38 10000010 */  b     .L7F098E7C
/* 0CD96C 7F098E3C E7A601BC */   swc1  $f6, 0x1bc($sp)
.L7F098E40:
/* 0CD970 7F098E40 0FC1E129 */  jal   getPlayer_c_screenwidth
/* 0CD974 7F098E44 00000000 */   nop   
/* 0CD978 7F098E48 8FAE04DC */  lw    $t6, 0x4dc($sp)
/* 0CD97C 7F098E4C 8FB804E0 */  lw    $t8, 0x4e0($sp)
/* 0CD980 7F098E50 3C013E80 */  li    $at, 0x3E800000 # 0.250000
/* 0CD984 7F098E54 C5CA002C */  lwc1  $f10, 0x2c($t6)
/* 0CD988 7F098E58 C704002C */  lwc1  $f4, 0x2c($t8)
/* 0CD98C 7F098E5C 44813000 */  mtc1  $at, $f6
/* 0CD990 7F098E60 46045201 */  sub.s $f8, $f10, $f4
/* 0CD994 7F098E64 44812000 */  mtc1  $at, $f4
/* 0CD998 7F098E68 46064282 */  mul.s $f10, $f8, $f6
/* 0CD99C 7F098E6C 46040201 */  sub.s $f8, $f0, $f4
/* 0CD9A0 7F098E70 46004187 */  neg.s $f6, $f8
/* 0CD9A4 7F098E74 460A3103 */  div.s $f4, $f6, $f10
/* 0CD9A8 7F098E78 E7A401BC */  swc1  $f4, 0x1bc($sp)
.L7F098E7C:
/* 0CD9AC 7F098E7C 3C05B400 */  lui   $a1, 0xb400
/* 0CD9B0 7F098E80 02001025 */  move  $v0, $s0
/* 0CD9B4 7F098E84 AC450000 */  sw    $a1, ($v0)
/* 0CD9B8 7F098E88 8FB904DC */  lw    $t9, 0x4dc($sp)
/* 0CD9BC 7F098E8C 3C01CE80 */  lui   $at, 0xce80
/* 0CD9C0 7F098E90 26100008 */  addiu $s0, $s0, 8
/* 0CD9C4 7F098E94 C728002C */  lwc1  $f8, 0x2c($t9)
/* 0CD9C8 7F098E98 3C19B200 */  lui   $t9, 0xb200
/* 0CD9CC 7F098E9C 02001825 */  move  $v1, $s0
/* 0CD9D0 7F098EA0 4600418D */  trunc.w.s $f6, $f8
/* 0CD9D4 7F098EA4 26100008 */  addiu $s0, $s0, 8
/* 0CD9D8 7F098EA8 02002025 */  move  $a0, $s0
/* 0CD9DC 7F098EAC 26100008 */  addiu $s0, $s0, 8
/* 0CD9E0 7F098EB0 440E3000 */  mfc1  $t6, $f6
/* 0CD9E4 7F098EB4 00000000 */  nop   
/* 0CD9E8 7F098EB8 01C1C025 */  or    $t8, $t6, $at
/* 0CD9EC 7F098EBC AC580004 */  sw    $t8, 4($v0)
/* 0CD9F0 7F098EC0 AC790000 */  sw    $t9, ($v1)
/* 0CD9F4 7F098EC4 8FAF04E0 */  lw    $t7, 0x4e0($sp)
/* 0CD9F8 7F098EC8 C5EA002C */  lwc1  $f10, 0x2c($t7)
/* 0CD9FC 7F098ECC 8FAF04D4 */  lw    $t7, 0x4d4($sp)
/* 0CDA00 7F098ED0 4600510D */  trunc.w.s $f4, $f10
/* 0CDA04 7F098ED4 C5E8002C */  lwc1  $f8, 0x2c($t7)
/* 0CDA08 7F098ED8 4600418D */  trunc.w.s $f6, $f8
/* 0CDA0C 7F098EDC 44182000 */  mfc1  $t8, $f4
/* 0CDA10 7F098EE0 00000000 */  nop   
/* 0CDA14 7F098EE4 0018CC00 */  sll   $t9, $t8, 0x10
/* 0CDA18 7F098EE8 44183000 */  mfc1  $t8, $f6
/* 0CDA1C 7F098EEC 00000000 */  nop   
/* 0CDA20 7F098EF0 03387825 */  or    $t7, $t9, $t8
/* 0CDA24 7F098EF4 AC6F0004 */  sw    $t7, 4($v1)
/* 0CDA28 7F098EF8 AC850000 */  sw    $a1, ($a0)
/* 0CDA2C 7F098EFC 0FC1E131 */  jal   getPlayer_c_screenleft
/* 0CDA30 7F098F00 AFA401B0 */   sw    $a0, 0x1b0($sp)
/* 0CDA34 7F098F04 0FC1E129 */  jal   getPlayer_c_screenwidth
/* 0CDA38 7F098F08 E7A0005C */   swc1  $f0, 0x5c($sp)
/* 0CDA3C 7F098F0C C7AA005C */  lwc1  $f10, 0x5c($sp)
/* 0CDA40 7F098F10 3C013E80 */  li    $at, 0x3E800000 # 0.250000
/* 0CDA44 7F098F14 44814000 */  mtc1  $at, $f8
/* 0CDA48 7F098F18 460A0100 */  add.s $f4, $f0, $f10
/* 0CDA4C 7F098F1C 0FC250A6 */  jal   sub_GAME_7F094298
/* 0CDA50 7F098F20 46082301 */   sub.s $f12, $f4, $f8
/* 0CDA54 7F098F24 8FAE01B0 */  lw    $t6, 0x1b0($sp)
/* 0CDA58 7F098F28 02001825 */  move  $v1, $s0
/* 0CDA5C 7F098F2C 3C19B200 */  lui   $t9, 0xb200
/* 0CDA60 7F098F30 ADC20004 */  sw    $v0, 4($t6)
/* 0CDA64 7F098F34 AC790000 */  sw    $t9, ($v1)
/* 0CDA68 7F098F38 AFA301AC */  sw    $v1, 0x1ac($sp)
/* 0CDA6C 7F098F3C C7AC01BC */  lwc1  $f12, 0x1bc($sp)
/* 0CDA70 7F098F40 0FC250A6 */  jal   sub_GAME_7F094298
/* 0CDA74 7F098F44 26100008 */   addiu $s0, $s0, 8
/* 0CDA78 7F098F48 8FA301AC */  lw    $v1, 0x1ac($sp)
/* 0CDA7C 7F098F4C 02002025 */  move  $a0, $s0
/* 0CDA80 7F098F50 3C18B400 */  lui   $t8, 0xb400
/* 0CDA84 7F098F54 AC620004 */  sw    $v0, 4($v1)
/* 0CDA88 7F098F58 AC980000 */  sw    $t8, ($a0)
/* 0CDA8C 7F098F5C AFA401A8 */  sw    $a0, 0x1a8($sp)
/* 0CDA90 7F098F60 0FC1E131 */  jal   getPlayer_c_screenleft
/* 0CDA94 7F098F64 26100008 */   addiu $s0, $s0, 8
/* 0CDA98 7F098F68 0FC250A6 */  jal   sub_GAME_7F094298
/* 0CDA9C 7F098F6C 46000306 */   mov.s $f12, $f0
/* 0CDAA0 7F098F70 8FAF01A8 */  lw    $t7, 0x1a8($sp)
/* 0CDAA4 7F098F74 02001825 */  move  $v1, $s0
/* 0CDAA8 7F098F78 3C0EB200 */  lui   $t6, 0xb200
/* 0CDAAC 7F098F7C ADE20004 */  sw    $v0, 4($t7)
/* 0CDAB0 7F098F80 AC6E0000 */  sw    $t6, ($v1)
/* 0CDAB4 7F098F84 AFA301A4 */  sw    $v1, 0x1a4($sp)
/* 0CDAB8 7F098F88 26100008 */  addiu $s0, $s0, 8
/* 0CDABC 7F098F8C 0FC250A6 */  jal   sub_GAME_7F094298
/* 0CDAC0 7F098F90 4600A306 */   mov.s $f12, $f20
/* 0CDAC4 7F098F94 8FA301A4 */  lw    $v1, 0x1a4($sp)
/* 0CDAC8 7F098F98 02002025 */  move  $a0, $s0
/* 0CDACC 7F098F9C 3C19B400 */  lui   $t9, 0xb400
/* 0CDAD0 7F098FA0 AC620004 */  sw    $v0, 4($v1)
/* 0CDAD4 7F098FA4 AC990000 */  sw    $t9, ($a0)
/* 0CDAD8 7F098FA8 AFA401A0 */  sw    $a0, 0x1a0($sp)
/* 0CDADC 7F098FAC 0FC1E131 */  jal   getPlayer_c_screenleft
/* 0CDAE0 7F098FB0 26100008 */   addiu $s0, $s0, 8
/* 0CDAE4 7F098FB4 0FC1E129 */  jal   getPlayer_c_screenwidth
/* 0CDAE8 7F098FB8 E7A0005C */   swc1  $f0, 0x5c($sp)
/* 0CDAEC 7F098FBC C7A6005C */  lwc1  $f6, 0x5c($sp)
/* 0CDAF0 7F098FC0 3C013E80 */  li    $at, 0x3E800000 # 0.250000
/* 0CDAF4 7F098FC4 44812000 */  mtc1  $at, $f4
/* 0CDAF8 7F098FC8 46060280 */  add.s $f10, $f0, $f6
/* 0CDAFC 7F098FCC 0FC250A6 */  jal   sub_GAME_7F094298
/* 0CDB00 7F098FD0 46045301 */   sub.s $f12, $f10, $f4
/* 0CDB04 7F098FD4 8FB801A0 */  lw    $t8, 0x1a0($sp)
/* 0CDB08 7F098FD8 02001825 */  move  $v1, $s0
/* 0CDB0C 7F098FDC 3C0FB200 */  lui   $t7, 0xb200
/* 0CDB10 7F098FE0 AF020004 */  sw    $v0, 4($t8)
/* 0CDB14 7F098FE4 AC6F0000 */  sw    $t7, ($v1)
/* 0CDB18 7F098FE8 AFA3019C */  sw    $v1, 0x19c($sp)
/* 0CDB1C 7F098FEC 26100008 */  addiu $s0, $s0, 8
/* 0CDB20 7F098FF0 0FC250A6 */  jal   sub_GAME_7F094298
/* 0CDB24 7F098FF4 4600A306 */   mov.s $f12, $f20
/* 0CDB28 7F098FF8 8FA3019C */  lw    $v1, 0x19c($sp)
/* 0CDB2C 7F098FFC 10000078 */  b     .L7F0991E0
/* 0CDB30 7F099000 AC620004 */   sw    $v0, 4($v1)
/* 0CDB34 7F099004 8FAE04DC */  lw    $t6, 0x4dc($sp)
.L7F099008:
/* 0CDB38 7F099008 8FB904E0 */  lw    $t9, 0x4e0($sp)
/* 0CDB3C 7F09900C 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0CDB40 7F099010 C5C8002C */  lwc1  $f8, 0x2c($t6)
/* 0CDB44 7F099014 C726002C */  lwc1  $f6, 0x2c($t9)
/* 0CDB48 7F099018 44812000 */  mtc1  $at, $f4
/* 0CDB4C 7F09901C 46064281 */  sub.s $f10, $f8, $f6
/* 0CDB50 7F099020 4604503C */  c.lt.s $f10, $f4
/* 0CDB54 7F099024 00000000 */  nop   
/* 0CDB58 7F099028 45000003 */  bc1f  .L7F099038
/* 0CDB5C 7F09902C 3C018005 */   lui    $at, %hi(D_80057608)
/* 0CDB60 7F099030 1000000E */  b     .L7F09906C
/* 0CDB64 7F099034 C42E7608 */   lwc1  $f14, %lo(D_80057608)($at)
.L7F099038:
/* 0CDB68 7F099038 0FC1E129 */  jal   getPlayer_c_screenwidth
/* 0CDB6C 7F09903C 00000000 */   nop   
/* 0CDB70 7F099040 8FB804DC */  lw    $t8, 0x4dc($sp)
/* 0CDB74 7F099044 8FAF04E0 */  lw    $t7, 0x4e0($sp)
/* 0CDB78 7F099048 3C013E80 */  li    $at, 0x3E800000 # 0.250000
/* 0CDB7C 7F09904C C708002C */  lwc1  $f8, 0x2c($t8)
/* 0CDB80 7F099050 C5E6002C */  lwc1  $f6, 0x2c($t7)
/* 0CDB84 7F099054 44812000 */  mtc1  $at, $f4
/* 0CDB88 7F099058 46064281 */  sub.s $f10, $f8, $f6
/* 0CDB8C 7F09905C 44813000 */  mtc1  $at, $f6
/* 0CDB90 7F099060 46045202 */  mul.s $f8, $f10, $f4
/* 0CDB94 7F099064 46060281 */  sub.s $f10, $f0, $f6
/* 0CDB98 7F099068 46085383 */  div.s $f14, $f10, $f8
.L7F09906C:
/* 0CDB9C 7F09906C 02001025 */  move  $v0, $s0
/* 0CDBA0 7F099070 3C0EB400 */  lui   $t6, 0xb400
/* 0CDBA4 7F099074 AC4E0000 */  sw    $t6, ($v0)
/* 0CDBA8 7F099078 8FB904DC */  lw    $t9, 0x4dc($sp)
/* 0CDBAC 7F09907C 3C01CE00 */  lui   $at, 0xce00
/* 0CDBB0 7F099080 26100008 */  addiu $s0, $s0, 8
/* 0CDBB4 7F099084 C724002C */  lwc1  $f4, 0x2c($t9)
/* 0CDBB8 7F099088 3C19B200 */  lui   $t9, 0xb200
/* 0CDBBC 7F09908C 02001825 */  move  $v1, $s0
/* 0CDBC0 7F099090 4600218D */  trunc.w.s $f6, $f4
/* 0CDBC4 7F099094 26100008 */  addiu $s0, $s0, 8
/* 0CDBC8 7F099098 02002025 */  move  $a0, $s0
/* 0CDBCC 7F09909C 26100008 */  addiu $s0, $s0, 8
/* 0CDBD0 7F0990A0 440F3000 */  mfc1  $t7, $f6
/* 0CDBD4 7F0990A4 00000000 */  nop   
/* 0CDBD8 7F0990A8 01E17025 */  or    $t6, $t7, $at
/* 0CDBDC 7F0990AC AC4E0004 */  sw    $t6, 4($v0)
/* 0CDBE0 7F0990B0 AC790000 */  sw    $t9, ($v1)
/* 0CDBE4 7F0990B4 8FB804E0 */  lw    $t8, 0x4e0($sp)
/* 0CDBE8 7F0990B8 3C0FB400 */  lui   $t7, 0xb400
/* 0CDBEC 7F0990BC C70A002C */  lwc1  $f10, 0x2c($t8)
/* 0CDBF0 7F0990C0 8FB804D4 */  lw    $t8, 0x4d4($sp)
/* 0CDBF4 7F0990C4 4600520D */  trunc.w.s $f8, $f10
/* 0CDBF8 7F0990C8 C704002C */  lwc1  $f4, 0x2c($t8)
/* 0CDBFC 7F0990CC 4600218D */  trunc.w.s $f6, $f4
/* 0CDC00 7F0990D0 440E4000 */  mfc1  $t6, $f8
/* 0CDC04 7F0990D4 00000000 */  nop   
/* 0CDC08 7F0990D8 000ECC00 */  sll   $t9, $t6, 0x10
/* 0CDC0C 7F0990DC 440E3000 */  mfc1  $t6, $f6
/* 0CDC10 7F0990E0 00000000 */  nop   
/* 0CDC14 7F0990E4 032EC025 */  or    $t8, $t9, $t6
/* 0CDC18 7F0990E8 AC780004 */  sw    $t8, 4($v1)
/* 0CDC1C 7F0990EC AC8F0000 */  sw    $t7, ($a0)
/* 0CDC20 7F0990F0 E7AE0198 */  swc1  $f14, 0x198($sp)
/* 0CDC24 7F0990F4 0FC1E131 */  jal   getPlayer_c_screenleft
/* 0CDC28 7F0990F8 AFA4018C */   sw    $a0, 0x18c($sp)
/* 0CDC2C 7F0990FC 0FC250A6 */  jal   sub_GAME_7F094298
/* 0CDC30 7F099100 46000306 */   mov.s $f12, $f0
/* 0CDC34 7F099104 8FB9018C */  lw    $t9, 0x18c($sp)
/* 0CDC38 7F099108 C7AC0198 */  lwc1  $f12, 0x198($sp)
/* 0CDC3C 7F09910C 02001825 */  move  $v1, $s0
/* 0CDC40 7F099110 3C0EB200 */  lui   $t6, 0xb200
/* 0CDC44 7F099114 AF220004 */  sw    $v0, 4($t9)
/* 0CDC48 7F099118 AC6E0000 */  sw    $t6, ($v1)
/* 0CDC4C 7F09911C AFA30188 */  sw    $v1, 0x188($sp)
/* 0CDC50 7F099120 0FC250A6 */  jal   sub_GAME_7F094298
/* 0CDC54 7F099124 26100008 */   addiu $s0, $s0, 8
/* 0CDC58 7F099128 8FA30188 */  lw    $v1, 0x188($sp)
/* 0CDC5C 7F09912C 02002025 */  move  $a0, $s0
/* 0CDC60 7F099130 3C18B400 */  lui   $t8, 0xb400
/* 0CDC64 7F099134 AC620004 */  sw    $v0, 4($v1)
/* 0CDC68 7F099138 AC980000 */  sw    $t8, ($a0)
/* 0CDC6C 7F09913C AFA40184 */  sw    $a0, 0x184($sp)
/* 0CDC70 7F099140 0FC1E131 */  jal   getPlayer_c_screenleft
/* 0CDC74 7F099144 26100008 */   addiu $s0, $s0, 8
/* 0CDC78 7F099148 0FC1E129 */  jal   getPlayer_c_screenwidth
/* 0CDC7C 7F09914C E7A0005C */   swc1  $f0, 0x5c($sp)
/* 0CDC80 7F099150 C7AA005C */  lwc1  $f10, 0x5c($sp)
/* 0CDC84 7F099154 3C013E80 */  li    $at, 0x3E800000 # 0.250000
/* 0CDC88 7F099158 44812000 */  mtc1  $at, $f4
/* 0CDC8C 7F09915C 460A0200 */  add.s $f8, $f0, $f10
/* 0CDC90 7F099160 0FC250A6 */  jal   sub_GAME_7F094298
/* 0CDC94 7F099164 46044301 */   sub.s $f12, $f8, $f4
/* 0CDC98 7F099168 8FAF0184 */  lw    $t7, 0x184($sp)
/* 0CDC9C 7F09916C 02001825 */  move  $v1, $s0
/* 0CDCA0 7F099170 3C19B200 */  lui   $t9, 0xb200
/* 0CDCA4 7F099174 ADE20004 */  sw    $v0, 4($t7)
/* 0CDCA8 7F099178 AC790000 */  sw    $t9, ($v1)
/* 0CDCAC 7F09917C AFA30180 */  sw    $v1, 0x180($sp)
/* 0CDCB0 7F099180 26100008 */  addiu $s0, $s0, 8
/* 0CDCB4 7F099184 0FC250A6 */  jal   sub_GAME_7F094298
/* 0CDCB8 7F099188 4600A306 */   mov.s $f12, $f20
/* 0CDCBC 7F09918C 8FA30180 */  lw    $v1, 0x180($sp)
/* 0CDCC0 7F099190 02002025 */  move  $a0, $s0
/* 0CDCC4 7F099194 3C0EB400 */  lui   $t6, 0xb400
/* 0CDCC8 7F099198 AC620004 */  sw    $v0, 4($v1)
/* 0CDCCC 7F09919C AC8E0000 */  sw    $t6, ($a0)
/* 0CDCD0 7F0991A0 AFA4017C */  sw    $a0, 0x17c($sp)
/* 0CDCD4 7F0991A4 0FC1E131 */  jal   getPlayer_c_screenleft
/* 0CDCD8 7F0991A8 26100008 */   addiu $s0, $s0, 8
/* 0CDCDC 7F0991AC 0FC250A6 */  jal   sub_GAME_7F094298
/* 0CDCE0 7F0991B0 46000306 */   mov.s $f12, $f0
/* 0CDCE4 7F0991B4 8FB8017C */  lw    $t8, 0x17c($sp)
/* 0CDCE8 7F0991B8 02001825 */  move  $v1, $s0
/* 0CDCEC 7F0991BC 3C0FB200 */  lui   $t7, 0xb200
/* 0CDCF0 7F0991C0 AF020004 */  sw    $v0, 4($t8)
/* 0CDCF4 7F0991C4 AC6F0000 */  sw    $t7, ($v1)
/* 0CDCF8 7F0991C8 AFA30178 */  sw    $v1, 0x178($sp)
/* 0CDCFC 7F0991CC 26100008 */  addiu $s0, $s0, 8
/* 0CDD00 7F0991D0 0FC250A6 */  jal   sub_GAME_7F094298
/* 0CDD04 7F0991D4 4600A306 */   mov.s $f12, $f20
/* 0CDD08 7F0991D8 8FA30178 */  lw    $v1, 0x178($sp)
/* 0CDD0C 7F0991DC AC620004 */  sw    $v0, 4($v1)
.L7F0991E0:
/* 0CDD10 7F0991E0 8FA804CC */  lw    $t0, 0x4cc($sp)
/* 0CDD14 7F0991E4 C7A003C0 */  lwc1  $f0, 0x3c0($sp)
/* 0CDD18 7F0991E8 8FA704C8 */  lw    $a3, 0x4c8($sp)
/* 0CDD1C 7F0991EC C506000C */  lwc1  $f6, 0xc($t0)
/* 0CDD20 7F0991F0 8FA904C4 */  lw    $t1, 0x4c4($sp)
/* 0CDD24 7F0991F4 8FAB04E0 */  lw    $t3, 0x4e0($sp)
/* 0CDD28 7F0991F8 46003282 */  mul.s $f10, $f6, $f0
/* 0CDD2C 7F0991FC 3C018005 */  lui    $at, %hi(D_8005760C)
/* 0CDD30 7F099200 E7AA03B0 */  swc1  $f10, 0x3b0($sp)
/* 0CDD34 7F099204 C4E8000C */  lwc1  $f8, 0xc($a3)
/* 0CDD38 7F099208 C7B003B0 */  lwc1  $f16, 0x3b0($sp)
/* 0CDD3C 7F09920C 46004102 */  mul.s $f4, $f8, $f0
/* 0CDD40 7F099210 E7A403B4 */  swc1  $f4, 0x3b4($sp)
/* 0CDD44 7F099214 C526000C */  lwc1  $f6, 0xc($t1)
/* 0CDD48 7F099218 46003282 */  mul.s $f10, $f6, $f0
/* 0CDD4C 7F09921C C7A603B4 */  lwc1  $f6, 0x3b4($sp)
/* 0CDD50 7F099220 4610303C */  c.lt.s $f6, $f16
/* 0CDD54 7F099224 E7AA03B8 */  swc1  $f10, 0x3b8($sp)
/* 0CDD58 7F099228 C568000C */  lwc1  $f8, 0xc($t3)
/* 0CDD5C 7F09922C 46004102 */  mul.s $f4, $f8, $f0
/* 0CDD60 7F099230 C7A003B8 */  lwc1  $f0, 0x3b8($sp)
/* 0CDD64 7F099234 45000002 */  bc1f  .L7F099240
/* 0CDD68 7F099238 E7A403BC */   swc1  $f4, 0x3bc($sp)
/* 0CDD6C 7F09923C 46003406 */  mov.s $f16, $f6
.L7F099240:
/* 0CDD70 7F099240 4610003C */  c.lt.s $f0, $f16
/* 0CDD74 7F099244 00000000 */  nop   
/* 0CDD78 7F099248 45020003 */  bc1fl .L7F099258
/* 0CDD7C 7F09924C C7A003BC */   lwc1  $f0, 0x3bc($sp)
/* 0CDD80 7F099250 46000406 */  mov.s $f16, $f0
/* 0CDD84 7F099254 C7A003BC */  lwc1  $f0, 0x3bc($sp)
.L7F099258:
/* 0CDD88 7F099258 4610003C */  c.lt.s $f0, $f16
/* 0CDD8C 7F09925C 00000000 */  nop   
/* 0CDD90 7F099260 45000002 */  bc1f  .L7F09926C
/* 0CDD94 7F099264 00000000 */   nop   
/* 0CDD98 7F099268 46000406 */  mov.s $f16, $f0
.L7F09926C:
/* 0CDD9C 7F09926C C420760C */  lwc1  $f0, %lo(D_8005760C)($at)
/* 0CDDA0 7F099270 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 0CDDA4 7F099274 44815000 */  mtc1  $at, $f10
/* 0CDDA8 7F099278 C5080034 */  lwc1  $f8, 0x34($t0)
/* 0CDDAC 7F09927C 460A8402 */  mul.s $f16, $f16, $f10
/* 0CDDB0 7F099280 00000000 */  nop   
/* 0CDDB4 7F099284 46104102 */  mul.s $f4, $f8, $f16
/* 0CDDB8 7F099288 E7A4039C */  swc1  $f4, 0x39c($sp)
/* 0CDDBC 7F09928C C4E60034 */  lwc1  $f6, 0x34($a3)
/* 0CDDC0 7F099290 46103282 */  mul.s $f10, $f6, $f16
/* 0CDDC4 7F099294 E7AA03A0 */  swc1  $f10, 0x3a0($sp)
/* 0CDDC8 7F099298 C5280034 */  lwc1  $f8, 0x34($t1)
/* 0CDDCC 7F09929C 46104102 */  mul.s $f4, $f8, $f16
/* 0CDDD0 7F0992A0 C7A8039C */  lwc1  $f8, 0x39c($sp)
/* 0CDDD4 7F0992A4 E7A403A4 */  swc1  $f4, 0x3a4($sp)
/* 0CDDD8 7F0992A8 C5660034 */  lwc1  $f6, 0x34($t3)
/* 0CDDDC 7F0992AC 46103282 */  mul.s $f10, $f6, $f16
/* 0CDDE0 7F0992B0 E7AA03A8 */  swc1  $f10, 0x3a8($sp)
/* 0CDDE4 7F0992B4 C5040020 */  lwc1  $f4, 0x20($t0)
/* 0CDDE8 7F0992B8 46044182 */  mul.s $f6, $f8, $f4
/* 0CDDEC 7F0992BC E7A6036C */  swc1  $f6, 0x36c($sp)
/* 0CDDF0 7F0992C0 C50A0024 */  lwc1  $f10, 0x24($t0)
/* 0CDDF4 7F0992C4 4606A03E */  c.le.s $f20, $f6
/* 0CDDF8 7F0992C8 460A4102 */  mul.s $f4, $f8, $f10
/* 0CDDFC 7F0992CC 00000000 */  nop   
/* 0CDE00 7F0992D0 46004282 */  mul.s $f10, $f8, $f0
/* 0CDE04 7F0992D4 E7A40370 */  swc1  $f4, 0x370($sp)
/* 0CDE08 7F0992D8 C7A403A0 */  lwc1  $f4, 0x3a0($sp)
/* 0CDE0C 7F0992DC E7AA0374 */  swc1  $f10, 0x374($sp)
/* 0CDE10 7F0992E0 C4E80020 */  lwc1  $f8, 0x20($a3)
/* 0CDE14 7F0992E4 46082282 */  mul.s $f10, $f4, $f8
/* 0CDE18 7F0992E8 E7AA0378 */  swc1  $f10, 0x378($sp)
/* 0CDE1C 7F0992EC C4E80024 */  lwc1  $f8, 0x24($a3)
/* 0CDE20 7F0992F0 46082282 */  mul.s $f10, $f4, $f8
/* 0CDE24 7F0992F4 00000000 */  nop   
/* 0CDE28 7F0992F8 46002202 */  mul.s $f8, $f4, $f0
/* 0CDE2C 7F0992FC E7AA037C */  swc1  $f10, 0x37c($sp)
/* 0CDE30 7F099300 C7AA03A4 */  lwc1  $f10, 0x3a4($sp)
/* 0CDE34 7F099304 E7A80380 */  swc1  $f8, 0x380($sp)
/* 0CDE38 7F099308 C5240020 */  lwc1  $f4, 0x20($t1)
/* 0CDE3C 7F09930C 46045202 */  mul.s $f8, $f10, $f4
/* 0CDE40 7F099310 E7A80384 */  swc1  $f8, 0x384($sp)
/* 0CDE44 7F099314 C5240024 */  lwc1  $f4, 0x24($t1)
/* 0CDE48 7F099318 46045202 */  mul.s $f8, $f10, $f4
/* 0CDE4C 7F09931C 00000000 */  nop   
/* 0CDE50 7F099320 46005102 */  mul.s $f4, $f10, $f0
/* 0CDE54 7F099324 E7A80388 */  swc1  $f8, 0x388($sp)
/* 0CDE58 7F099328 C7A803A8 */  lwc1  $f8, 0x3a8($sp)
/* 0CDE5C 7F09932C E7A4038C */  swc1  $f4, 0x38c($sp)
/* 0CDE60 7F099330 C56A0020 */  lwc1  $f10, 0x20($t3)
/* 0CDE64 7F099334 460A4102 */  mul.s $f4, $f8, $f10
/* 0CDE68 7F099338 C7A803A8 */  lwc1  $f8, 0x3a8($sp)
/* 0CDE6C 7F09933C E7A40390 */  swc1  $f4, 0x390($sp)
/* 0CDE70 7F099340 C56A0024 */  lwc1  $f10, 0x24($t3)
/* 0CDE74 7F099344 460A4102 */  mul.s $f4, $f8, $f10
/* 0CDE78 7F099348 C7A803A8 */  lwc1  $f8, 0x3a8($sp)
/* 0CDE7C 7F09934C 46004282 */  mul.s $f10, $f8, $f0
/* 0CDE80 7F099350 C7A00370 */  lwc1  $f0, 0x370($sp)
/* 0CDE84 7F099354 E7A40394 */  swc1  $f4, 0x394($sp)
/* 0CDE88 7F099358 45000003 */  bc1f  .L7F099368
/* 0CDE8C 7F09935C E7AA0398 */   swc1  $f10, 0x398($sp)
/* 0CDE90 7F099360 10000003 */  b     .L7F099370
/* 0CDE94 7F099364 46003086 */   mov.s $f2, $f6
.L7F099368:
/* 0CDE98 7F099368 C7A2036C */  lwc1  $f2, 0x36c($sp)
/* 0CDE9C 7F09936C 46001087 */  neg.s $f2, $f2
.L7F099370:
/* 0CDEA0 7F099370 4600A03E */  c.le.s $f20, $f0
/* 0CDEA4 7F099374 00000000 */  nop   
/* 0CDEA8 7F099378 45020004 */  bc1fl .L7F09938C
/* 0CDEAC 7F09937C 46000387 */   neg.s $f14, $f0
/* 0CDEB0 7F099380 10000002 */  b     .L7F09938C
/* 0CDEB4 7F099384 46000386 */   mov.s $f14, $f0
/* 0CDEB8 7F099388 46000387 */  neg.s $f14, $f0
.L7F09938C:
/* 0CDEBC 7F09938C C7A00378 */  lwc1  $f0, 0x378($sp)
/* 0CDEC0 7F099390 4600A03E */  c.le.s $f20, $f0
/* 0CDEC4 7F099394 00000000 */  nop   
/* 0CDEC8 7F099398 45020004 */  bc1fl .L7F0993AC
/* 0CDECC 7F09939C 46000307 */   neg.s $f12, $f0
/* 0CDED0 7F0993A0 10000002 */  b     .L7F0993AC
/* 0CDED4 7F0993A4 46000306 */   mov.s $f12, $f0
/* 0CDED8 7F0993A8 46000307 */  neg.s $f12, $f0
.L7F0993AC:
/* 0CDEDC 7F0993AC 460C103C */  c.lt.s $f2, $f12
/* 0CDEE0 7F0993B0 00000000 */  nop   
/* 0CDEE4 7F0993B4 45020009 */  bc1fl .L7F0993DC
/* 0CDEE8 7F0993B8 C7A0037C */   lwc1  $f0, 0x37c($sp)
/* 0CDEEC 7F0993BC 4600A03E */  c.le.s $f20, $f0
/* 0CDEF0 7F0993C0 00000000 */  nop   
/* 0CDEF4 7F0993C4 45020004 */  bc1fl .L7F0993D8
/* 0CDEF8 7F0993C8 46000087 */   neg.s $f2, $f0
/* 0CDEFC 7F0993CC 10000002 */  b     .L7F0993D8
/* 0CDF00 7F0993D0 46000086 */   mov.s $f2, $f0
/* 0CDF04 7F0993D4 46000087 */  neg.s $f2, $f0
.L7F0993D8:
/* 0CDF08 7F0993D8 C7A0037C */  lwc1  $f0, 0x37c($sp)
.L7F0993DC:
/* 0CDF0C 7F0993DC 4600A03E */  c.le.s $f20, $f0
/* 0CDF10 7F0993E0 00000000 */  nop   
/* 0CDF14 7F0993E4 45020004 */  bc1fl .L7F0993F8
/* 0CDF18 7F0993E8 46000307 */   neg.s $f12, $f0
/* 0CDF1C 7F0993EC 10000002 */  b     .L7F0993F8
/* 0CDF20 7F0993F0 46000306 */   mov.s $f12, $f0
/* 0CDF24 7F0993F4 46000307 */  neg.s $f12, $f0
.L7F0993F8:
/* 0CDF28 7F0993F8 460C703C */  c.lt.s $f14, $f12
/* 0CDF2C 7F0993FC E7B003AC */  swc1  $f16, 0x3ac($sp)
/* 0CDF30 7F099400 4502000B */  bc1fl .L7F099430
/* 0CDF34 7F099404 C7A00384 */   lwc1  $f0, 0x384($sp)
/* 0CDF38 7F099408 4600A03E */  c.le.s $f20, $f0
/* 0CDF3C 7F09940C 00000000 */  nop   
/* 0CDF40 7F099410 45020005 */  bc1fl .L7F099428
/* 0CDF44 7F099414 46000387 */   neg.s $f14, $f0
/* 0CDF48 7F099418 46000386 */  mov.s $f14, $f0
/* 0CDF4C 7F09941C 10000003 */  b     .L7F09942C
/* 0CDF50 7F099420 E7B003AC */   swc1  $f16, 0x3ac($sp)
/* 0CDF54 7F099424 46000387 */  neg.s $f14, $f0
.L7F099428:
/* 0CDF58 7F099428 E7B003AC */  swc1  $f16, 0x3ac($sp)
.L7F09942C:
/* 0CDF5C 7F09942C C7A00384 */  lwc1  $f0, 0x384($sp)
.L7F099430:
/* 0CDF60 7F099430 4600A03E */  c.le.s $f20, $f0
/* 0CDF64 7F099434 00000000 */  nop   
/* 0CDF68 7F099438 45020004 */  bc1fl .L7F09944C
/* 0CDF6C 7F09943C 46000307 */   neg.s $f12, $f0
/* 0CDF70 7F099440 10000002 */  b     .L7F09944C
/* 0CDF74 7F099444 46000306 */   mov.s $f12, $f0
/* 0CDF78 7F099448 46000307 */  neg.s $f12, $f0
.L7F09944C:
/* 0CDF7C 7F09944C 460C103C */  c.lt.s $f2, $f12
/* 0CDF80 7F099450 00000000 */  nop   
/* 0CDF84 7F099454 45020009 */  bc1fl .L7F09947C
/* 0CDF88 7F099458 C7A00388 */   lwc1  $f0, 0x388($sp)
/* 0CDF8C 7F09945C 4600A03E */  c.le.s $f20, $f0
/* 0CDF90 7F099460 00000000 */  nop   
/* 0CDF94 7F099464 45020004 */  bc1fl .L7F099478
/* 0CDF98 7F099468 46000087 */   neg.s $f2, $f0
/* 0CDF9C 7F09946C 10000002 */  b     .L7F099478
/* 0CDFA0 7F099470 46000086 */   mov.s $f2, $f0
/* 0CDFA4 7F099474 46000087 */  neg.s $f2, $f0
.L7F099478:
/* 0CDFA8 7F099478 C7A00388 */  lwc1  $f0, 0x388($sp)
.L7F09947C:
/* 0CDFAC 7F09947C 4600A03E */  c.le.s $f20, $f0
/* 0CDFB0 7F099480 00000000 */  nop   
/* 0CDFB4 7F099484 45020004 */  bc1fl .L7F099498
/* 0CDFB8 7F099488 46000307 */   neg.s $f12, $f0
/* 0CDFBC 7F09948C 10000002 */  b     .L7F099498
/* 0CDFC0 7F099490 46000306 */   mov.s $f12, $f0
/* 0CDFC4 7F099494 46000307 */  neg.s $f12, $f0
.L7F099498:
/* 0CDFC8 7F099498 460C703C */  c.lt.s $f14, $f12
/* 0CDFCC 7F09949C 00000000 */  nop   
/* 0CDFD0 7F0994A0 45020009 */  bc1fl .L7F0994C8
/* 0CDFD4 7F0994A4 C7A00390 */   lwc1  $f0, 0x390($sp)
/* 0CDFD8 7F0994A8 4600A03E */  c.le.s $f20, $f0
/* 0CDFDC 7F0994AC 00000000 */  nop   
/* 0CDFE0 7F0994B0 45020004 */  bc1fl .L7F0994C4
/* 0CDFE4 7F0994B4 46000387 */   neg.s $f14, $f0
/* 0CDFE8 7F0994B8 10000002 */  b     .L7F0994C4
/* 0CDFEC 7F0994BC 46000386 */   mov.s $f14, $f0
/* 0CDFF0 7F0994C0 46000387 */  neg.s $f14, $f0
.L7F0994C4:
/* 0CDFF4 7F0994C4 C7A00390 */  lwc1  $f0, 0x390($sp)
.L7F0994C8:
/* 0CDFF8 7F0994C8 4600A03E */  c.le.s $f20, $f0
/* 0CDFFC 7F0994CC 00000000 */  nop   
/* 0CE000 7F0994D0 45020004 */  bc1fl .L7F0994E4
/* 0CE004 7F0994D4 46000307 */   neg.s $f12, $f0
/* 0CE008 7F0994D8 10000002 */  b     .L7F0994E4
/* 0CE00C 7F0994DC 46000306 */   mov.s $f12, $f0
/* 0CE010 7F0994E0 46000307 */  neg.s $f12, $f0
.L7F0994E4:
/* 0CE014 7F0994E4 460C103C */  c.lt.s $f2, $f12
/* 0CE018 7F0994E8 E7A20364 */  swc1  $f2, 0x364($sp)
/* 0CE01C 7F0994EC 4502000A */  bc1fl .L7F099518
/* 0CE020 7F0994F0 C7A00394 */   lwc1  $f0, 0x394($sp)
/* 0CE024 7F0994F4 4600A03E */  c.le.s $f20, $f0
/* 0CE028 7F0994F8 00000000 */  nop   
/* 0CE02C 7F0994FC 45020004 */  bc1fl .L7F099510
/* 0CE030 7F099500 46000087 */   neg.s $f2, $f0
/* 0CE034 7F099504 10000003 */  b     .L7F099514
/* 0CE038 7F099508 E7A00364 */   swc1  $f0, 0x364($sp)
/* 0CE03C 7F09950C 46000087 */  neg.s $f2, $f0
.L7F099510:
/* 0CE040 7F099510 E7A20364 */  swc1  $f2, 0x364($sp)
.L7F099514:
/* 0CE044 7F099514 C7A00394 */  lwc1  $f0, 0x394($sp)
.L7F099518:
/* 0CE048 7F099518 4600A03E */  c.le.s $f20, $f0
/* 0CE04C 7F09951C 00000000 */  nop   
/* 0CE050 7F099520 45020004 */  bc1fl .L7F099534
/* 0CE054 7F099524 46000307 */   neg.s $f12, $f0
/* 0CE058 7F099528 10000002 */  b     .L7F099534
/* 0CE05C 7F09952C 46000306 */   mov.s $f12, $f0
/* 0CE060 7F099530 46000307 */  neg.s $f12, $f0
.L7F099534:
/* 0CE064 7F099534 460C703C */  c.lt.s $f14, $f12
/* 0CE068 7F099538 E7AE0368 */  swc1  $f14, 0x368($sp)
/* 0CE06C 7F09953C 4502000A */  bc1fl .L7F099568
/* 0CE070 7F099540 C7A4036C */   lwc1  $f4, 0x36c($sp)
/* 0CE074 7F099544 4600A03E */  c.le.s $f20, $f0
/* 0CE078 7F099548 00000000 */  nop   
/* 0CE07C 7F09954C 45020004 */  bc1fl .L7F099560
/* 0CE080 7F099550 46000387 */   neg.s $f14, $f0
/* 0CE084 7F099554 10000003 */  b     .L7F099564
/* 0CE088 7F099558 E7A00368 */   swc1  $f0, 0x368($sp)
/* 0CE08C 7F09955C 46000387 */  neg.s $f14, $f0
.L7F099560:
/* 0CE090 7F099560 E7AE0368 */  swc1  $f14, 0x368($sp)
.L7F099564:
/* 0CE094 7F099564 C7A4036C */  lwc1  $f4, 0x36c($sp)
.L7F099568:
/* 0CE098 7F099568 C7A80370 */  lwc1  $f8, 0x370($sp)
/* 0CE09C 7F09956C C7AA0374 */  lwc1  $f10, 0x374($sp)
/* 0CE0A0 7F099570 E7A40354 */  swc1  $f4, 0x354($sp)
/* 0CE0A4 7F099574 C7A4037C */  lwc1  $f4, 0x37c($sp)
/* 0CE0A8 7F099578 C7A60378 */  lwc1  $f6, 0x378($sp)
/* 0CE0AC 7F09957C E7A80358 */  swc1  $f8, 0x358($sp)
/* 0CE0B0 7F099580 E7AA035C */  swc1  $f10, 0x35c($sp)
/* 0CE0B4 7F099584 E7A40338 */  swc1  $f4, 0x338($sp)
/* 0CE0B8 7F099588 E7A60334 */  swc1  $f6, 0x334($sp)
/* 0CE0BC 7F09958C C7A80380 */  lwc1  $f8, 0x380($sp)
/* 0CE0C0 7F099590 C7A60388 */  lwc1  $f6, 0x388($sp)
/* 0CE0C4 7F099594 C7A4038C */  lwc1  $f4, 0x38c($sp)
/* 0CE0C8 7F099598 C7AA0384 */  lwc1  $f10, 0x384($sp)
/* 0CE0CC 7F09959C E7A8033C */  swc1  $f8, 0x33c($sp)
/* 0CE0D0 7F0995A0 E7A60318 */  swc1  $f6, 0x318($sp)
/* 0CE0D4 7F0995A4 E7A4031C */  swc1  $f4, 0x31c($sp)
/* 0CE0D8 7F0995A8 E7AA0314 */  swc1  $f10, 0x314($sp)
/* 0CE0DC 7F0995AC C5080030 */  lwc1  $f8, 0x30($t0)
/* 0CE0E0 7F0995B0 27A302F4 */  addiu $v1, $sp, 0x2f4
/* 0CE0E4 7F0995B4 27A60334 */  addiu $a2, $sp, 0x334
/* 0CE0E8 7F0995B8 E7A80360 */  swc1  $f8, 0x360($sp)
/* 0CE0EC 7F0995BC C4EA0030 */  lwc1  $f10, 0x30($a3)
/* 0CE0F0 7F0995C0 27A70324 */  addiu $a3, $sp, 0x324
/* 0CE0F4 7F0995C4 27A20354 */  addiu $v0, $sp, 0x354
/* 0CE0F8 7F0995C8 E7AA0340 */  swc1  $f10, 0x340($sp)
/* 0CE0FC 7F0995CC C5260030 */  lwc1  $f6, 0x30($t1)
/* 0CE100 7F0995D0 27A402D4 */  addiu $a0, $sp, 0x2d4
/* 0CE104 7F0995D4 27A50314 */  addiu $a1, $sp, 0x314
/* 0CE108 7F0995D8 E7A60320 */  swc1  $f6, 0x320($sp)
.L7F0995DC:
/* 0CE10C 7F0995DC C4400000 */  lwc1  $f0, ($v0)
/* 0CE110 7F0995E0 C4C40000 */  lwc1  $f4, ($a2)
/* 0CE114 7F0995E4 C4AA0000 */  lwc1  $f10, ($a1)
/* 0CE118 7F0995E8 24A50004 */  addiu $a1, $a1, 4
/* 0CE11C 7F0995EC 46002201 */  sub.s $f8, $f4, $f0
/* 0CE120 7F0995F0 00A7082B */  sltu  $at, $a1, $a3
/* 0CE124 7F0995F4 24630004 */  addiu $v1, $v1, 4
/* 0CE128 7F0995F8 46005181 */  sub.s $f6, $f10, $f0
/* 0CE12C 7F0995FC 24C60004 */  addiu $a2, $a2, 4
/* 0CE130 7F099600 24420004 */  addiu $v0, $v0, 4
/* 0CE134 7F099604 24840004 */  addiu $a0, $a0, 4
/* 0CE138 7F099608 E468FFFC */  swc1  $f8, -4($v1)
/* 0CE13C 7F09960C 1420FFF3 */  bnez  $at, .L7F0995DC
/* 0CE140 7F099610 E486FFFC */   swc1  $f6, -4($a0)
/* 0CE144 7F099614 27A302F4 */  addiu $v1, $sp, 0x2f4
/* 0CE148 7F099618 27A20354 */  addiu $v0, $sp, 0x354
/* 0CE14C 7F09961C 27A402D4 */  addiu $a0, $sp, 0x2d4
/* 0CE150 7F099620 27A70294 */  addiu $a3, $sp, 0x294
/* 0CE154 7F099624 27A502B4 */  addiu $a1, $sp, 0x2b4
/* 0CE158 7F099628 27A80274 */  addiu $t0, $sp, 0x274
/* 0CE15C 7F09962C 27A60254 */  addiu $a2, $sp, 0x254
/* 0CE160 7F099630 C7B20410 */  lwc1  $f18, 0x410($sp)
/* 0CE164 7F099634 C7B0040C */  lwc1  $f16, 0x40c($sp)
/* 0CE168 7F099638 27A90264 */  addiu $t1, $sp, 0x264
.L7F09963C:
/* 0CE16C 7F09963C C4800000 */  lwc1  $f0, ($a0)
/* 0CE170 7F099640 C4620000 */  lwc1  $f2, ($v1)
/* 0CE174 7F099644 C7A80418 */  lwc1  $f8, 0x418($sp)
/* 0CE178 7F099648 46120102 */  mul.s $f4, $f0, $f18
/* 0CE17C 7F09964C 3C014780 */  li    $at, 0x47800000 # 65536.000000
/* 0CE180 7F099650 24C60004 */  addiu $a2, $a2, 4
/* 0CE184 7F099654 46024282 */  mul.s $f10, $f8, $f2
/* 0CE188 7F099658 44814000 */  mtc1  $at, $f8
/* 0CE18C 7F09965C 24630004 */  addiu $v1, $v1, 4
/* 0CE190 7F099660 24420004 */  addiu $v0, $v0, 4
/* 0CE194 7F099664 24840004 */  addiu $a0, $a0, 4
/* 0CE198 7F099668 24E70004 */  addiu $a3, $a3, 4
/* 0CE19C 7F09966C 24A50004 */  addiu $a1, $a1, 4
/* 0CE1A0 7F099670 460A2181 */  sub.s $f6, $f4, $f10
/* 0CE1A4 7F099674 25080004 */  addiu $t0, $t0, 4
/* 0CE1A8 7F099678 46083303 */  div.s $f12, $f6, $f8
/* 0CE1AC 7F09967C E4ECFFFC */  swc1  $f12, -4($a3)
/* 0CE1B0 7F099680 C7A40414 */  lwc1  $f4, 0x414($sp)
/* 0CE1B4 7F099684 46041282 */  mul.s $f10, $f2, $f4
/* 0CE1B8 7F099688 44812000 */  mtc1  $at, $f4
/* 0CE1BC 7F09968C 00C9082B */  sltu  $at, $a2, $t1
/* 0CE1C0 7F099690 46008182 */  mul.s $f6, $f16, $f0
/* 0CE1C4 7F099694 46065201 */  sub.s $f8, $f10, $f6
/* 0CE1C8 7F099698 46044283 */  div.s $f10, $f8, $f4
/* 0CE1CC 7F09969C E4AAFFFC */  swc1  $f10, -4($a1)
/* 0CE1D0 7F0996A0 C7A60484 */  lwc1  $f6, 0x484($sp)
/* 0CE1D4 7F0996A4 C4A4FFFC */  lwc1  $f4, -4($a1)
/* 0CE1D8 7F0996A8 46066202 */  mul.s $f8, $f12, $f6
/* 0CE1DC 7F0996AC C446FFFC */  lwc1  $f6, -4($v0)
/* 0CE1E0 7F0996B0 E488FFFC */  swc1  $f8, -4($a0)
/* 0CE1E4 7F0996B4 C7AA0484 */  lwc1  $f10, 0x484($sp)
/* 0CE1E8 7F0996B8 E4C6FFFC */  swc1  $f6, -4($a2)
/* 0CE1EC 7F0996BC 460A2382 */  mul.s $f14, $f4, $f10
/* 0CE1F0 7F0996C0 E46EFFFC */  swc1  $f14, -4($v1)
/* 0CE1F4 7F0996C4 1420FFDD */  bnez  $at, .L7F09963C
/* 0CE1F8 7F0996C8 E50EFFFC */   swc1  $f14, -4($t0)
/* 0CE1FC 7F0996CC 8FA304DC */  lw    $v1, 0x4dc($sp)
/* 0CE200 7F0996D0 C568002C */  lwc1  $f8, 0x2c($t3)
/* 0CE204 7F0996D4 8FA204D4 */  lw    $v0, 0x4d4($sp)
/* 0CE208 7F0996D8 C464002C */  lwc1  $f4, 0x2c($v1)
/* 0CE20C 7F0996DC C4660010 */  lwc1  $f6, 0x10($v1)
/* 0CE210 7F0996E0 C44E0010 */  lwc1  $f14, 0x10($v0)
/* 0CE214 7F0996E4 46044003 */  div.s $f0, $f8, $f4
/* 0CE218 7F0996E8 C56A0010 */  lwc1  $f10, 0x10($t3)
/* 0CE21C 7F0996EC 3C014780 */  li    $at, 0x47800000 # 65536.000000
/* 0CE220 7F0996F0 240E0001 */  li    $t6, 1
/* 0CE224 7F0996F4 46067201 */  sub.s $f8, $f14, $f6
/* 0CE228 7F0996F8 46004102 */  mul.s $f4, $f8, $f0
/* 0CE22C 7F0996FC 46045180 */  add.s $f6, $f10, $f4
/* 0CE230 7F099700 E7A60170 */  swc1  $f6, 0x170($sp)
/* 0CE234 7F099704 C46A0014 */  lwc1  $f10, 0x14($v1)
/* 0CE238 7F099708 C4420014 */  lwc1  $f2, 0x14($v0)
/* 0CE23C 7F09970C C5680014 */  lwc1  $f8, 0x14($t3)
/* 0CE240 7F099710 460A1101 */  sub.s $f4, $f2, $f10
/* 0CE244 7F099714 46002182 */  mul.s $f6, $f4, $f0
/* 0CE248 7F099718 46064280 */  add.s $f10, $f8, $f6
/* 0CE24C 7F09971C E7AA016C */  swc1  $f10, 0x16c($sp)
/* 0CE250 7F099720 C4680018 */  lwc1  $f8, 0x18($v1)
/* 0CE254 7F099724 C4500018 */  lwc1  $f16, 0x18($v0)
/* 0CE258 7F099728 C5640018 */  lwc1  $f4, 0x18($t3)
/* 0CE25C 7F09972C 46088181 */  sub.s $f6, $f16, $f8
/* 0CE260 7F099730 46003282 */  mul.s $f10, $f6, $f0
/* 0CE264 7F099734 460A2200 */  add.s $f8, $f4, $f10
/* 0CE268 7F099738 E7A80168 */  swc1  $f8, 0x168($sp)
/* 0CE26C 7F09973C C464001C */  lwc1  $f4, 0x1c($v1)
/* 0CE270 7F099740 C452001C */  lwc1  $f18, 0x1c($v0)
/* 0CE274 7F099744 C566001C */  lwc1  $f6, 0x1c($t3)
/* 0CE278 7F099748 46049281 */  sub.s $f10, $f18, $f4
/* 0CE27C 7F09974C 46005202 */  mul.s $f8, $f10, $f0
/* 0CE280 7F099750 44815000 */  mtc1  $at, $f10
/* 0CE284 7F099754 46083100 */  add.s $f4, $f6, $f8
/* 0CE288 7F099758 460A7182 */  mul.s $f6, $f14, $f10
/* 0CE28C 7F09975C E7A40164 */  swc1  $f4, 0x164($sp)
/* 0CE290 7F099760 4459F800 */  cfc1  $t9, $31
/* 0CE294 7F099764 44CEF800 */  ctc1  $t6, $31
/* 0CE298 7F099768 00000000 */  nop   
/* 0CE29C 7F09976C 46003224 */  cvt.w.s $f8, $f6
/* 0CE2A0 7F099770 444EF800 */  cfc1  $t6, $31
/* 0CE2A4 7F099774 00000000 */  nop   
/* 0CE2A8 7F099778 31CE0078 */  andi  $t6, $t6, 0x78
/* 0CE2AC 7F09977C 11C00012 */  beqz  $t6, .L7F0997C8
/* 0CE2B0 7F099780 3C014F00 */   li    $at, 0x4F000000 # 2147483648.000000
/* 0CE2B4 7F099784 44814000 */  mtc1  $at, $f8
/* 0CE2B8 7F099788 240E0001 */  li    $t6, 1
/* 0CE2BC 7F09978C 46083201 */  sub.s $f8, $f6, $f8
/* 0CE2C0 7F099790 44CEF800 */  ctc1  $t6, $31
/* 0CE2C4 7F099794 00000000 */  nop   
/* 0CE2C8 7F099798 46004224 */  cvt.w.s $f8, $f8
/* 0CE2CC 7F09979C 444EF800 */  cfc1  $t6, $31
/* 0CE2D0 7F0997A0 00000000 */  nop   
/* 0CE2D4 7F0997A4 31CE0078 */  andi  $t6, $t6, 0x78
/* 0CE2D8 7F0997A8 15C00005 */  bnez  $t6, .L7F0997C0
/* 0CE2DC 7F0997AC 00000000 */   nop   
/* 0CE2E0 7F0997B0 440E4000 */  mfc1  $t6, $f8
/* 0CE2E4 7F0997B4 3C018000 */  lui   $at, 0x8000
/* 0CE2E8 7F0997B8 10000007 */  b     .L7F0997D8
/* 0CE2EC 7F0997BC 01C17025 */   or    $t6, $t6, $at
.L7F0997C0:
/* 0CE2F0 7F0997C0 10000005 */  b     .L7F0997D8
/* 0CE2F4 7F0997C4 240EFFFF */   li    $t6, -1
.L7F0997C8:
/* 0CE2F8 7F0997C8 440E4000 */  mfc1  $t6, $f8
/* 0CE2FC 7F0997CC 00000000 */  nop   
/* 0CE300 7F0997D0 05C0FFFB */  bltz  $t6, .L7F0997C0
/* 0CE304 7F0997D4 00000000 */   nop   
.L7F0997D8:
/* 0CE308 7F0997D8 3C014780 */  li    $at, 0x47800000 # 65536.000000
/* 0CE30C 7F0997DC 44D9F800 */  ctc1  $t9, $31
/* 0CE310 7F0997E0 44812000 */  mtc1  $at, $f4
/* 0CE314 7F0997E4 240F0001 */  li    $t7, 1
/* 0CE318 7F0997E8 AFAE0160 */  sw    $t6, 0x160($sp)
/* 0CE31C 7F0997EC 46041282 */  mul.s $f10, $f2, $f4
/* 0CE320 7F0997F0 4458F800 */  cfc1  $t8, $31
/* 0CE324 7F0997F4 44CFF800 */  ctc1  $t7, $31
/* 0CE328 7F0997F8 00000000 */  nop   
/* 0CE32C 7F0997FC 460051A4 */  cvt.w.s $f6, $f10
/* 0CE330 7F099800 444FF800 */  cfc1  $t7, $31
/* 0CE334 7F099804 00000000 */  nop   
/* 0CE338 7F099808 31EF0078 */  andi  $t7, $t7, 0x78
/* 0CE33C 7F09980C 11E00012 */  beqz  $t7, .L7F099858
/* 0CE340 7F099810 3C014F00 */   li    $at, 0x4F000000 # 2147483648.000000
/* 0CE344 7F099814 44813000 */  mtc1  $at, $f6
/* 0CE348 7F099818 240F0001 */  li    $t7, 1
/* 0CE34C 7F09981C 46065181 */  sub.s $f6, $f10, $f6
/* 0CE350 7F099820 44CFF800 */  ctc1  $t7, $31
/* 0CE354 7F099824 00000000 */  nop   
/* 0CE358 7F099828 460031A4 */  cvt.w.s $f6, $f6
/* 0CE35C 7F09982C 444FF800 */  cfc1  $t7, $31
/* 0CE360 7F099830 00000000 */  nop   
/* 0CE364 7F099834 31EF0078 */  andi  $t7, $t7, 0x78
/* 0CE368 7F099838 15E00005 */  bnez  $t7, .L7F099850
/* 0CE36C 7F09983C 00000000 */   nop   
/* 0CE370 7F099840 440F3000 */  mfc1  $t7, $f6
/* 0CE374 7F099844 3C018000 */  lui   $at, 0x8000
/* 0CE378 7F099848 10000007 */  b     .L7F099868
/* 0CE37C 7F09984C 01E17825 */   or    $t7, $t7, $at
.L7F099850:
/* 0CE380 7F099850 10000005 */  b     .L7F099868
/* 0CE384 7F099854 240FFFFF */   li    $t7, -1
.L7F099858:
/* 0CE388 7F099858 440F3000 */  mfc1  $t7, $f6
/* 0CE38C 7F09985C 00000000 */  nop   
/* 0CE390 7F099860 05E0FFFB */  bltz  $t7, .L7F099850
/* 0CE394 7F099864 00000000 */   nop   
.L7F099868:
/* 0CE398 7F099868 3C014780 */  li    $at, 0x47800000 # 65536.000000
/* 0CE39C 7F09986C 44D8F800 */  ctc1  $t8, $31
/* 0CE3A0 7F099870 44814000 */  mtc1  $at, $f8
/* 0CE3A4 7F099874 240E0001 */  li    $t6, 1
/* 0CE3A8 7F099878 AFAF015C */  sw    $t7, 0x15c($sp)
/* 0CE3AC 7F09987C 46088102 */  mul.s $f4, $f16, $f8
/* 0CE3B0 7F099880 4459F800 */  cfc1  $t9, $31
/* 0CE3B4 7F099884 44CEF800 */  ctc1  $t6, $31
/* 0CE3B8 7F099888 00000000 */  nop   
/* 0CE3BC 7F09988C 460022A4 */  cvt.w.s $f10, $f4
/* 0CE3C0 7F099890 444EF800 */  cfc1  $t6, $31
/* 0CE3C4 7F099894 00000000 */  nop   
/* 0CE3C8 7F099898 31CE0078 */  andi  $t6, $t6, 0x78
/* 0CE3CC 7F09989C 11C00012 */  beqz  $t6, .L7F0998E8
/* 0CE3D0 7F0998A0 3C014F00 */   li    $at, 0x4F000000 # 2147483648.000000
/* 0CE3D4 7F0998A4 44815000 */  mtc1  $at, $f10
/* 0CE3D8 7F0998A8 240E0001 */  li    $t6, 1
/* 0CE3DC 7F0998AC 460A2281 */  sub.s $f10, $f4, $f10
/* 0CE3E0 7F0998B0 44CEF800 */  ctc1  $t6, $31
/* 0CE3E4 7F0998B4 00000000 */  nop   
/* 0CE3E8 7F0998B8 460052A4 */  cvt.w.s $f10, $f10
/* 0CE3EC 7F0998BC 444EF800 */  cfc1  $t6, $31
/* 0CE3F0 7F0998C0 00000000 */  nop   
/* 0CE3F4 7F0998C4 31CE0078 */  andi  $t6, $t6, 0x78
/* 0CE3F8 7F0998C8 15C00005 */  bnez  $t6, .L7F0998E0
/* 0CE3FC 7F0998CC 00000000 */   nop   
/* 0CE400 7F0998D0 440E5000 */  mfc1  $t6, $f10
/* 0CE404 7F0998D4 3C018000 */  lui   $at, 0x8000
/* 0CE408 7F0998D8 10000007 */  b     .L7F0998F8
/* 0CE40C 7F0998DC 01C17025 */   or    $t6, $t6, $at
.L7F0998E0:
/* 0CE410 7F0998E0 10000005 */  b     .L7F0998F8
/* 0CE414 7F0998E4 240EFFFF */   li    $t6, -1
.L7F0998E8:
/* 0CE418 7F0998E8 440E5000 */  mfc1  $t6, $f10
/* 0CE41C 7F0998EC 00000000 */  nop   
/* 0CE420 7F0998F0 05C0FFFB */  bltz  $t6, .L7F0998E0
/* 0CE424 7F0998F4 00000000 */   nop   
.L7F0998F8:
/* 0CE428 7F0998F8 3C014780 */  li    $at, 0x47800000 # 65536.000000
/* 0CE42C 7F0998FC 44D9F800 */  ctc1  $t9, $31
/* 0CE430 7F099900 44813000 */  mtc1  $at, $f6
/* 0CE434 7F099904 240F0001 */  li    $t7, 1
/* 0CE438 7F099908 AFAE0158 */  sw    $t6, 0x158($sp)
/* 0CE43C 7F09990C 46069202 */  mul.s $f8, $f18, $f6
/* 0CE440 7F099910 4458F800 */  cfc1  $t8, $31
/* 0CE444 7F099914 44CFF800 */  ctc1  $t7, $31
/* 0CE448 7F099918 00000000 */  nop   
/* 0CE44C 7F09991C 46004124 */  cvt.w.s $f4, $f8
/* 0CE450 7F099920 444FF800 */  cfc1  $t7, $31
/* 0CE454 7F099924 00000000 */  nop   
/* 0CE458 7F099928 31EF0078 */  andi  $t7, $t7, 0x78
/* 0CE45C 7F09992C 11E00012 */  beqz  $t7, .L7F099978
/* 0CE460 7F099930 3C014F00 */   li    $at, 0x4F000000 # 2147483648.000000
/* 0CE464 7F099934 44812000 */  mtc1  $at, $f4
/* 0CE468 7F099938 240F0001 */  li    $t7, 1
/* 0CE46C 7F09993C 46044101 */  sub.s $f4, $f8, $f4
/* 0CE470 7F099940 44CFF800 */  ctc1  $t7, $31
/* 0CE474 7F099944 00000000 */  nop   
/* 0CE478 7F099948 46002124 */  cvt.w.s $f4, $f4
/* 0CE47C 7F09994C 444FF800 */  cfc1  $t7, $31
/* 0CE480 7F099950 00000000 */  nop   
/* 0CE484 7F099954 31EF0078 */  andi  $t7, $t7, 0x78
/* 0CE488 7F099958 15E00005 */  bnez  $t7, .L7F099970
/* 0CE48C 7F09995C 00000000 */   nop   
/* 0CE490 7F099960 440F2000 */  mfc1  $t7, $f4
/* 0CE494 7F099964 3C018000 */  lui   $at, 0x8000
/* 0CE498 7F099968 10000007 */  b     .L7F099988
/* 0CE49C 7F09996C 01E17825 */   or    $t7, $t7, $at
.L7F099970:
/* 0CE4A0 7F099970 10000005 */  b     .L7F099988
/* 0CE4A4 7F099974 240FFFFF */   li    $t7, -1
.L7F099978:
/* 0CE4A8 7F099978 440F2000 */  mfc1  $t7, $f4
/* 0CE4AC 7F09997C 00000000 */  nop   
/* 0CE4B0 7F099980 05E0FFFB */  bltz  $t7, .L7F099970
/* 0CE4B4 7F099984 00000000 */   nop   
.L7F099988:
/* 0CE4B8 7F099988 8FB904D8 */  lw    $t9, 0x4d8($sp)
/* 0CE4BC 7F09998C AFAF0154 */  sw    $t7, 0x154($sp)
/* 0CE4C0 7F099990 44D8F800 */  ctc1  $t8, $31
/* 0CE4C4 7F099994 C4460028 */  lwc1  $f6, 0x28($v0)
/* 0CE4C8 7F099998 C72A0028 */  lwc1  $f10, 0x28($t9)
/* 0CE4CC 7F09999C 3C013E80 */  li    $at, 0x3E800000 # 0.250000
/* 0CE4D0 7F0999A0 44812000 */  mtc1  $at, $f4
/* 0CE4D4 7F0999A4 46065201 */  sub.s $f8, $f10, $f6
/* 0CE4D8 7F0999A8 C7A60170 */  lwc1  $f6, 0x170($sp)
/* 0CE4DC 7F0999AC 46044282 */  mul.s $f10, $f8, $f4
/* 0CE4E0 7F0999B0 460E3201 */  sub.s $f8, $f6, $f14
/* 0CE4E4 7F0999B4 0FC250A6 */  jal   sub_GAME_7F094298
/* 0CE4E8 7F0999B8 460A4303 */   div.s $f12, $f8, $f10
/* 0CE4EC 7F0999BC 8FA304D4 */  lw    $v1, 0x4d4($sp)
/* 0CE4F0 7F0999C0 AFA20150 */  sw    $v0, 0x150($sp)
/* 0CE4F4 7F0999C4 C7A4016C */  lwc1  $f4, 0x16c($sp)
/* 0CE4F8 7F0999C8 C4660014 */  lwc1  $f6, 0x14($v1)
/* 0CE4FC 7F0999CC 8FAE04D8 */  lw    $t6, 0x4d8($sp)
/* 0CE500 7F0999D0 3C013E80 */  li    $at, 0x3E800000 # 0.250000
/* 0CE504 7F0999D4 46062201 */  sub.s $f8, $f4, $f6
/* 0CE508 7F0999D8 C4640028 */  lwc1  $f4, 0x28($v1)
/* 0CE50C 7F0999DC C5CA0028 */  lwc1  $f10, 0x28($t6)
/* 0CE510 7F0999E0 46045181 */  sub.s $f6, $f10, $f4
/* 0CE514 7F0999E4 44815000 */  mtc1  $at, $f10
/* 0CE518 7F0999E8 00000000 */  nop   
/* 0CE51C 7F0999EC 460A3102 */  mul.s $f4, $f6, $f10
/* 0CE520 7F0999F0 0FC250A6 */  jal   sub_GAME_7F094298
/* 0CE524 7F0999F4 46044303 */   div.s $f12, $f8, $f4
/* 0CE528 7F0999F8 8FA304D4 */  lw    $v1, 0x4d4($sp)
/* 0CE52C 7F0999FC AFA2014C */  sw    $v0, 0x14c($sp)
/* 0CE530 7F099A00 C7A60168 */  lwc1  $f6, 0x168($sp)
/* 0CE534 7F099A04 C46A0018 */  lwc1  $f10, 0x18($v1)
/* 0CE538 7F099A08 8FB804D8 */  lw    $t8, 0x4d8($sp)
/* 0CE53C 7F099A0C 3C013E80 */  li    $at, 0x3E800000 # 0.250000
/* 0CE540 7F099A10 460A3201 */  sub.s $f8, $f6, $f10
/* 0CE544 7F099A14 C4660028 */  lwc1  $f6, 0x28($v1)
/* 0CE548 7F099A18 C7040028 */  lwc1  $f4, 0x28($t8)
/* 0CE54C 7F099A1C 46062281 */  sub.s $f10, $f4, $f6
/* 0CE550 7F099A20 44812000 */  mtc1  $at, $f4
/* 0CE554 7F099A24 00000000 */  nop   
/* 0CE558 7F099A28 46045182 */  mul.s $f6, $f10, $f4
/* 0CE55C 7F099A2C 0FC250A6 */  jal   sub_GAME_7F094298
/* 0CE560 7F099A30 46064303 */   div.s $f12, $f8, $f6
/* 0CE564 7F099A34 8FA304D4 */  lw    $v1, 0x4d4($sp)
/* 0CE568 7F099A38 AFA20148 */  sw    $v0, 0x148($sp)
/* 0CE56C 7F099A3C C7AA0164 */  lwc1  $f10, 0x164($sp)
/* 0CE570 7F099A40 C464001C */  lwc1  $f4, 0x1c($v1)
/* 0CE574 7F099A44 8FAF04D8 */  lw    $t7, 0x4d8($sp)
/* 0CE578 7F099A48 3C013E80 */  li    $at, 0x3E800000 # 0.250000
/* 0CE57C 7F099A4C 46045201 */  sub.s $f8, $f10, $f4
/* 0CE580 7F099A50 C46A0028 */  lwc1  $f10, 0x28($v1)
/* 0CE584 7F099A54 C5E60028 */  lwc1  $f6, 0x28($t7)
/* 0CE588 7F099A58 460A3101 */  sub.s $f4, $f6, $f10
/* 0CE58C 7F099A5C 44813000 */  mtc1  $at, $f6
/* 0CE590 7F099A60 00000000 */  nop   
/* 0CE594 7F099A64 46062282 */  mul.s $f10, $f4, $f6
/* 0CE598 7F099A68 0FC250A6 */  jal   sub_GAME_7F094298
/* 0CE59C 7F099A6C 460A4303 */   div.s $f12, $f8, $f10
/* 0CE5A0 7F099A70 8FA304DC */  lw    $v1, 0x4dc($sp)
/* 0CE5A4 7F099A74 8FB904D4 */  lw    $t9, 0x4d4($sp)
/* 0CE5A8 7F099A78 AFA20144 */  sw    $v0, 0x144($sp)
/* 0CE5AC 7F099A7C C4640010 */  lwc1  $f4, 0x10($v1)
/* 0CE5B0 7F099A80 C7260010 */  lwc1  $f6, 0x10($t9)
/* 0CE5B4 7F099A84 C46A002C */  lwc1  $f10, 0x2c($v1)
/* 0CE5B8 7F099A88 3C013E80 */  li    $at, 0x3E800000 # 0.250000
/* 0CE5BC 7F099A8C 46062201 */  sub.s $f8, $f4, $f6
/* 0CE5C0 7F099A90 C724002C */  lwc1  $f4, 0x2c($t9)
/* 0CE5C4 7F099A94 46045181 */  sub.s $f6, $f10, $f4
/* 0CE5C8 7F099A98 44815000 */  mtc1  $at, $f10
/* 0CE5CC 7F099A9C 00000000 */  nop   
/* 0CE5D0 7F099AA0 460A3102 */  mul.s $f4, $f6, $f10
/* 0CE5D4 7F099AA4 0FC250A6 */  jal   sub_GAME_7F094298
/* 0CE5D8 7F099AA8 46044303 */   div.s $f12, $f8, $f4
/* 0CE5DC 7F099AAC 8FA304DC */  lw    $v1, 0x4dc($sp)
/* 0CE5E0 7F099AB0 8FAE04D4 */  lw    $t6, 0x4d4($sp)
/* 0CE5E4 7F099AB4 AFA20130 */  sw    $v0, 0x130($sp)
/* 0CE5E8 7F099AB8 AFA20140 */  sw    $v0, 0x140($sp)
/* 0CE5EC 7F099ABC C4660014 */  lwc1  $f6, 0x14($v1)
/* 0CE5F0 7F099AC0 C5CA0014 */  lwc1  $f10, 0x14($t6)
/* 0CE5F4 7F099AC4 C464002C */  lwc1  $f4, 0x2c($v1)
/* 0CE5F8 7F099AC8 3C013E80 */  li    $at, 0x3E800000 # 0.250000
/* 0CE5FC 7F099ACC 460A3201 */  sub.s $f8, $f6, $f10
/* 0CE600 7F099AD0 C5C6002C */  lwc1  $f6, 0x2c($t6)
/* 0CE604 7F099AD4 46062281 */  sub.s $f10, $f4, $f6
/* 0CE608 7F099AD8 44812000 */  mtc1  $at, $f4
/* 0CE60C 7F099ADC 00000000 */  nop   
/* 0CE610 7F099AE0 46045182 */  mul.s $f6, $f10, $f4
/* 0CE614 7F099AE4 0FC250A6 */  jal   sub_GAME_7F094298
/* 0CE618 7F099AE8 46064303 */   div.s $f12, $f8, $f6
/* 0CE61C 7F099AEC 8FB804DC */  lw    $t8, 0x4dc($sp)
/* 0CE620 7F099AF0 8FAF04D4 */  lw    $t7, 0x4d4($sp)
/* 0CE624 7F099AF4 AFA2012C */  sw    $v0, 0x12c($sp)
/* 0CE628 7F099AF8 AFA2013C */  sw    $v0, 0x13c($sp)
/* 0CE62C 7F099AFC C70A0018 */  lwc1  $f10, 0x18($t8)
/* 0CE630 7F099B00 C5E40018 */  lwc1  $f4, 0x18($t7)
/* 0CE634 7F099B04 C706002C */  lwc1  $f6, 0x2c($t8)
/* 0CE638 7F099B08 3C013E80 */  li    $at, 0x3E800000 # 0.250000
/* 0CE63C 7F099B0C 46045201 */  sub.s $f8, $f10, $f4
/* 0CE640 7F099B10 C5EA002C */  lwc1  $f10, 0x2c($t7)
/* 0CE644 7F099B14 460A3101 */  sub.s $f4, $f6, $f10
/* 0CE648 7F099B18 44813000 */  mtc1  $at, $f6
/* 0CE64C 7F099B1C 00000000 */  nop   
/* 0CE650 7F099B20 46062282 */  mul.s $f10, $f4, $f6
/* 0CE654 7F099B24 0FC250A6 */  jal   sub_GAME_7F094298
/* 0CE658 7F099B28 460A4303 */   div.s $f12, $f8, $f10
/* 0CE65C 7F099B2C 8FB904DC */  lw    $t9, 0x4dc($sp)
/* 0CE660 7F099B30 8FAE04D4 */  lw    $t6, 0x4d4($sp)
/* 0CE664 7F099B34 3C013E80 */  li    $at, 0x3E800000 # 0.250000
/* 0CE668 7F099B38 C724001C */  lwc1  $f4, 0x1c($t9)
/* 0CE66C 7F099B3C C5C6001C */  lwc1  $f6, 0x1c($t6)
/* 0CE670 7F099B40 C72A002C */  lwc1  $f10, 0x2c($t9)
/* 0CE674 7F099B44 46062201 */  sub.s $f8, $f4, $f6
/* 0CE678 7F099B48 C5C4002C */  lwc1  $f4, 0x2c($t6)
/* 0CE67C 7F099B4C AFA20138 */  sw    $v0, 0x138($sp)
/* 0CE680 7F099B50 AFA20128 */  sw    $v0, 0x128($sp)
/* 0CE684 7F099B54 46045181 */  sub.s $f6, $f10, $f4
/* 0CE688 7F099B58 44815000 */  mtc1  $at, $f10
/* 0CE68C 7F099B5C 00000000 */  nop   
/* 0CE690 7F099B60 460A3102 */  mul.s $f4, $f6, $f10
/* 0CE694 7F099B64 0FC250A6 */  jal   sub_GAME_7F094298
/* 0CE698 7F099B68 46044303 */   div.s $f12, $f8, $f4
/* 0CE69C 7F099B6C 8FAB015C */  lw    $t3, 0x15c($sp)
/* 0CE6A0 7F099B70 8FAA0160 */  lw    $t2, 0x160($sp)
/* 0CE6A4 7F099B74 3C09FFFF */  lui   $t1, 0xffff
/* 0CE6A8 7F099B78 02001825 */  move  $v1, $s0
/* 0CE6AC 7F099B7C 01697824 */  and   $t7, $t3, $t1
/* 0CE6B0 7F099B80 8FAC0128 */  lw    $t4, 0x128($sp)
/* 0CE6B4 7F099B84 8FAD0138 */  lw    $t5, 0x138($sp)
/* 0CE6B8 7F099B88 8FBF0158 */  lw    $ra, 0x158($sp)
/* 0CE6BC 7F099B8C 000FCC02 */  srl   $t9, $t7, 0x10
/* 0CE6C0 7F099B90 0149C024 */  and   $t8, $t2, $t1
/* 0CE6C4 7F099B94 3C08B400 */  lui   $t0, 0xb400
/* 0CE6C8 7F099B98 03197025 */  or    $t6, $t8, $t9
/* 0CE6CC 7F099B9C 26100008 */  addiu $s0, $s0, 8
/* 0CE6D0 7F099BA0 AC6E0004 */  sw    $t6, 4($v1)
/* 0CE6D4 7F099BA4 AC680000 */  sw    $t0, ($v1)
/* 0CE6D8 7F099BA8 02002025 */  move  $a0, $s0
/* 0CE6DC 7F099BAC 3C0FB200 */  lui   $t7, 0xb200
/* 0CE6E0 7F099BB0 AC8F0000 */  sw    $t7, ($a0)
/* 0CE6E4 7F099BB4 8FB90154 */  lw    $t9, 0x154($sp)
/* 0CE6E8 7F099BB8 03E9C024 */  and   $t8, $ra, $t1
/* 0CE6EC 7F099BBC 26100008 */  addiu $s0, $s0, 8
/* 0CE6F0 7F099BC0 03297024 */  and   $t6, $t9, $t1
/* 0CE6F4 7F099BC4 000E7C02 */  srl   $t7, $t6, 0x10
/* 0CE6F8 7F099BC8 030FC825 */  or    $t9, $t8, $t7
/* 0CE6FC 7F099BCC AC990004 */  sw    $t9, 4($a0)
/* 0CE700 7F099BD0 02002825 */  move  $a1, $s0
/* 0CE704 7F099BD4 ACA80000 */  sw    $t0, ($a1)
/* 0CE708 7F099BD8 8FAF014C */  lw    $t7, 0x14c($sp)
/* 0CE70C 7F099BDC 8FAE0150 */  lw    $t6, 0x150($sp)
/* 0CE710 7F099BE0 26100008 */  addiu $s0, $s0, 8
/* 0CE714 7F099BE4 01E9C824 */  and   $t9, $t7, $t1
/* 0CE718 7F099BE8 01C9C024 */  and   $t8, $t6, $t1
/* 0CE71C 7F099BEC 00197402 */  srl   $t6, $t9, 0x10
/* 0CE720 7F099BF0 030E7825 */  or    $t7, $t8, $t6
/* 0CE724 7F099BF4 ACAF0004 */  sw    $t7, 4($a1)
/* 0CE728 7F099BF8 3C05B200 */  lui   $a1, %hi(0xB2000004) # $a1, 0xb200
/* 0CE72C 7F099BFC 02003025 */  move  $a2, $s0
/* 0CE730 7F099C00 ACC50000 */  sw    $a1, ($a2)
/* 0CE734 7F099C04 8FAE0144 */  lw    $t6, 0x144($sp)
/* 0CE738 7F099C08 8FB90148 */  lw    $t9, 0x148($sp)
/* 0CE73C 7F099C0C 26100008 */  addiu $s0, $s0, 8
/* 0CE740 7F099C10 01C97824 */  and   $t7, $t6, $t1
/* 0CE744 7F099C14 0329C024 */  and   $t8, $t9, $t1
/* 0CE748 7F099C18 000FCC02 */  srl   $t9, $t7, 0x10
/* 0CE74C 7F099C1C 03197025 */  or    $t6, $t8, $t9
/* 0CE750 7F099C20 ACCE0004 */  sw    $t6, 4($a2)
/* 0CE754 7F099C24 02001825 */  move  $v1, $s0
/* 0CE758 7F099C28 3179FFFF */  andi  $t9, $t3, 0xffff
/* 0CE75C 7F099C2C 000AC400 */  sll   $t8, $t2, 0x10
/* 0CE760 7F099C30 03197025 */  or    $t6, $t8, $t9
/* 0CE764 7F099C34 26100008 */  addiu $s0, $s0, 8
/* 0CE768 7F099C38 AC6E0004 */  sw    $t6, 4($v1)
/* 0CE76C 7F099C3C AC680000 */  sw    $t0, ($v1)
/* 0CE770 7F099C40 02002025 */  move  $a0, $s0
/* 0CE774 7F099C44 AC850000 */  sw    $a1, ($a0)
/* 0CE778 7F099C48 8FB90154 */  lw    $t9, 0x154($sp)
/* 0CE77C 7F099C4C 001FC400 */  sll   $t8, $ra, 0x10
/* 0CE780 7F099C50 26100008 */  addiu $s0, $s0, 8
/* 0CE784 7F099C54 332EFFFF */  andi  $t6, $t9, 0xffff
/* 0CE788 7F099C58 030E7825 */  or    $t7, $t8, $t6
/* 0CE78C 7F099C5C AC8F0004 */  sw    $t7, 4($a0)
/* 0CE790 7F099C60 02003825 */  move  $a3, $s0
/* 0CE794 7F099C64 ACE80000 */  sw    $t0, ($a3)
/* 0CE798 7F099C68 8FAF014C */  lw    $t7, 0x14c($sp)
/* 0CE79C 7F099C6C 8FB80150 */  lw    $t8, 0x150($sp)
/* 0CE7A0 7F099C70 8FAA0140 */  lw    $t2, 0x140($sp)
/* 0CE7A4 7F099C74 31F9FFFF */  andi  $t9, $t7, 0xffff
/* 0CE7A8 7F099C78 00187400 */  sll   $t6, $t8, 0x10
/* 0CE7AC 7F099C7C 8FA8013C */  lw    $t0, 0x13c($sp)
/* 0CE7B0 7F099C80 01D9C025 */  or    $t8, $t6, $t9
/* 0CE7B4 7F099C84 26100008 */  addiu $s0, $s0, 8
/* 0CE7B8 7F099C88 ACF80004 */  sw    $t8, 4($a3)
/* 0CE7BC 7F099C8C 02001825 */  move  $v1, $s0
/* 0CE7C0 7F099C90 3C0FB200 */  lui   $t7, 0xb200
/* 0CE7C4 7F099C94 AC6F0000 */  sw    $t7, ($v1)
/* 0CE7C8 7F099C98 8FAF0144 */  lw    $t7, 0x144($sp)
/* 0CE7CC 7F099C9C 8FB90148 */  lw    $t9, 0x148($sp)
/* 0CE7D0 7F099CA0 26100008 */  addiu $s0, $s0, 8
/* 0CE7D4 7F099CA4 31EEFFFF */  andi  $t6, $t7, 0xffff
/* 0CE7D8 7F099CA8 0019C400 */  sll   $t8, $t9, 0x10
/* 0CE7DC 7F099CAC 030EC825 */  or    $t9, $t8, $t6
/* 0CE7E0 7F099CB0 0109C024 */  and   $t8, $t0, $t1
/* 0CE7E4 7F099CB4 AC790004 */  sw    $t9, 4($v1)
/* 0CE7E8 7F099CB8 00187402 */  srl   $t6, $t8, 0x10
/* 0CE7EC 7F099CBC 01497824 */  and   $t7, $t2, $t1
/* 0CE7F0 7F099CC0 01EEC825 */  or    $t9, $t7, $t6
/* 0CE7F4 7F099CC4 02002025 */  move  $a0, $s0
/* 0CE7F8 7F099CC8 26100008 */  addiu $s0, $s0, 8
/* 0CE7FC 7F099CCC 3C1FB400 */  lui   $ra, 0xb400
/* 0CE800 7F099CD0 AC990004 */  sw    $t9, 4($a0)
/* 0CE804 7F099CD4 02002825 */  move  $a1, $s0
/* 0CE808 7F099CD8 00493024 */  and   $a2, $v0, $t1
/* 0CE80C 7F099CDC AC9F0000 */  sw    $ra, ($a0)
/* 0CE810 7F099CE0 00067C02 */  srl   $t7, $a2, 0x10
/* 0CE814 7F099CE4 01A97024 */  and   $t6, $t5, $t1
/* 0CE818 7F099CE8 01CFC825 */  or    $t9, $t6, $t7
/* 0CE81C 7F099CEC 26100008 */  addiu $s0, $s0, 8
/* 0CE820 7F099CF0 3C18B200 */  lui   $t8, 0xb200
/* 0CE824 7F099CF4 ACB80000 */  sw    $t8, ($a1)
/* 0CE828 7F099CF8 ACB90004 */  sw    $t9, %lo(0xB2000004)($a1)
/* 0CE82C 7F099CFC 02001825 */  move  $v1, $s0
/* 0CE830 7F099D00 AC7F0000 */  sw    $ra, ($v1)
/* 0CE834 7F099D04 8FAE012C */  lw    $t6, 0x12c($sp)
/* 0CE838 7F099D08 8FB80130 */  lw    $t8, 0x130($sp)
/* 0CE83C 7F099D0C 01E03025 */  move  $a2, $t7
/* 0CE840 7F099D10 01C9C824 */  and   $t9, $t6, $t1
/* 0CE844 7F099D14 03097824 */  and   $t7, $t8, $t1
/* 0CE848 7F099D18 0019C402 */  srl   $t8, $t9, 0x10
/* 0CE84C 7F099D1C 01F87025 */  or    $t6, $t7, $t8
/* 0CE850 7F099D20 26100008 */  addiu $s0, $s0, 8
/* 0CE854 7F099D24 02002025 */  move  $a0, $s0
/* 0CE858 7F099D28 01897824 */  and   $t7, $t4, $t1
/* 0CE85C 7F099D2C AC6E0004 */  sw    $t6, 4($v1)
/* 0CE860 7F099D30 01E6C025 */  or    $t8, $t7, $a2
/* 0CE864 7F099D34 3C19B200 */  lui   $t9, 0xb200
/* 0CE868 7F099D38 AC990000 */  sw    $t9, ($a0)
/* 0CE86C 7F099D3C 26100008 */  addiu $s0, $s0, 8
/* 0CE870 7F099D40 AC980004 */  sw    $t8, 4($a0)
/* 0CE874 7F099D44 02002825 */  move  $a1, $s0
/* 0CE878 7F099D48 000ACC00 */  sll   $t9, $t2, 0x10
/* 0CE87C 7F099D4C 310FFFFF */  andi  $t7, $t0, 0xffff
/* 0CE880 7F099D50 032FC025 */  or    $t8, $t9, $t7
/* 0CE884 7F099D54 26100008 */  addiu $s0, $s0, 8
/* 0CE888 7F099D58 ACB80004 */  sw    $t8, %lo(0xB2000004)($a1)
/* 0CE88C 7F099D5C ACBF0000 */  sw    $ra, ($a1)
/* 0CE890 7F099D60 02005825 */  move  $t3, $s0
/* 0CE894 7F099D64 304FFFFF */  andi  $t7, $v0, 0xffff
/* 0CE898 7F099D68 000DCC00 */  sll   $t9, $t5, 0x10
/* 0CE89C 7F099D6C 032FC025 */  or    $t8, $t9, $t7
/* 0CE8A0 7F099D70 26100008 */  addiu $s0, $s0, 8
/* 0CE8A4 7F099D74 3C1FB200 */  lui   $ra, 0xb200
/* 0CE8A8 7F099D78 AD7F0000 */  sw    $ra, ($t3)
/* 0CE8AC 7F099D7C AD780004 */  sw    $t8, 4($t3)
/* 0CE8B0 7F099D80 02003825 */  move  $a3, $s0
/* 0CE8B4 7F099D84 3C0EB400 */  lui   $t6, 0xb400
/* 0CE8B8 7F099D88 ACEE0000 */  sw    $t6, ($a3)
/* 0CE8BC 7F099D8C 8FAE012C */  lw    $t6, 0x12c($sp)
/* 0CE8C0 7F099D90 8FAF0130 */  lw    $t7, 0x130($sp)
/* 0CE8C4 7F099D94 26100008 */  addiu $s0, $s0, 8
/* 0CE8C8 7F099D98 31D9FFFF */  andi  $t9, $t6, 0xffff
/* 0CE8CC 7F099D9C 000FC400 */  sll   $t8, $t7, 0x10
/* 0CE8D0 7F099DA0 03197825 */  or    $t7, $t8, $t9
/* 0CE8D4 7F099DA4 ACEF0004 */  sw    $t7, 4($a3)
/* 0CE8D8 7F099DA8 3059FFFF */  andi  $t9, $v0, 0xffff
/* 0CE8DC 7F099DAC 02004025 */  move  $t0, $s0
/* 0CE8E0 7F099DB0 000CC400 */  sll   $t8, $t4, 0x10
/* 0CE8E4 7F099DB4 03197825 */  or    $t7, $t8, $t9
/* 0CE8E8 7F099DB8 3C013D00 */  li    $at, 0x3D000000 # 0.031250
/* 0CE8EC 7F099DBC AD0F0004 */  sw    $t7, 4($t0)
/* 0CE8F0 7F099DC0 AD1F0000 */  sw    $ra, ($t0)
/* 0CE8F4 7F099DC4 44817000 */  mtc1  $at, $f14
/* 0CE8F8 7F099DC8 C7A60364 */  lwc1  $f6, 0x364($sp)
/* 0CE8FC 7F099DCC C7A80368 */  lwc1  $f8, 0x368($sp)
/* 0CE900 7F099DD0 26100008 */  addiu $s0, $s0, 8
/* 0CE904 7F099DD4 460E3282 */  mul.s $f10, $f6, $f14
/* 0CE908 7F099DD8 C7A603AC */  lwc1  $f6, 0x3ac($sp)
/* 0CE90C 7F099DDC 3C014000 */  li    $at, 0x40000000 # 2.000000
/* 0CE910 7F099DE0 460E4102 */  mul.s $f4, $f8, $f14
/* 0CE914 7F099DE4 27A20204 */  addiu $v0, $sp, 0x204
/* 0CE918 7F099DE8 27A501F4 */  addiu $a1, $sp, 0x1f4
/* 0CE91C 7F099DEC 27A402D4 */  addiu $a0, $sp, 0x2d4
/* 0CE920 7F099DF0 E7AA0234 */  swc1  $f10, 0x234($sp)
/* 0CE924 7F099DF4 460E3282 */  mul.s $f10, $f6, $f14
/* 0CE928 7F099DF8 27A60214 */  addiu $a2, $sp, 0x214
/* 0CE92C 7F099DFC E7A40238 */  swc1  $f4, 0x238($sp)
/* 0CE930 7F099E00 27A302F4 */  addiu $v1, $sp, 0x2f4
/* 0CE934 7F099E04 E7AA023C */  swc1  $f10, 0x23c($sp)
.L7F099E08:
/* 0CE938 7F099E08 C4800000 */  lwc1  $f0, ($a0)
/* 0CE93C 7F099E0C 4600A03E */  c.le.s $f20, $f0
/* 0CE940 7F099E10 00000000 */  nop   
/* 0CE944 7F099E14 45020004 */  bc1fl .L7F099E28
/* 0CE948 7F099E18 46000307 */   neg.s $f12, $f0
/* 0CE94C 7F099E1C 10000002 */  b     .L7F099E28
/* 0CE950 7F099E20 46000306 */   mov.s $f12, $f0
/* 0CE954 7F099E24 46000307 */  neg.s $f12, $f0
.L7F099E28:
/* 0CE958 7F099E28 C4620000 */  lwc1  $f2, ($v1)
/* 0CE95C 7F099E2C 460E6202 */  mul.s $f8, $f12, $f14
/* 0CE960 7F099E30 4602A03E */  c.le.s $f20, $f2
/* 0CE964 7F099E34 00000000 */  nop   
/* 0CE968 7F099E38 45000003 */  bc1f  .L7F099E48
/* 0CE96C 7F099E3C E4C80000 */   swc1  $f8, ($a2)
/* 0CE970 7F099E40 10000002 */  b     .L7F099E4C
/* 0CE974 7F099E44 46001306 */   mov.s $f12, $f2
.L7F099E48:
/* 0CE978 7F099E48 46001307 */  neg.s $f12, $f2
.L7F099E4C:
/* 0CE97C 7F099E4C 460E6102 */  mul.s $f4, $f12, $f14
/* 0CE980 7F099E50 24A50004 */  addiu $a1, $a1, 4
/* 0CE984 7F099E54 24630004 */  addiu $v1, $v1, 4
/* 0CE988 7F099E58 24840004 */  addiu $a0, $a0, 4
/* 0CE98C 7F099E5C 24C60004 */  addiu $a2, $a2, 4
/* 0CE990 7F099E60 14A2FFE9 */  bne   $a1, $v0, .L7F099E08
/* 0CE994 7F099E64 E4A4FFFC */   swc1  $f4, -4($a1)
/* 0CE998 7F099E68 44811000 */  mtc1  $at, $f2
/* 0CE99C 7F099E6C C7AA0214 */  lwc1  $f10, 0x214($sp)
/* 0CE9A0 7F099E70 C7A60234 */  lwc1  $f6, 0x234($sp)
/* 0CE9A4 7F099E74 3C013A80 */  li    $at, 0x3A800000 # 0.000977
/* 0CE9A8 7F099E78 460A1202 */  mul.s $f8, $f2, $f10
/* 0CE9AC 7F099E7C C7AA01F4 */  lwc1  $f10, 0x1f4($sp)
/* 0CE9B0 7F099E80 46083100 */  add.s $f4, $f6, $f8
/* 0CE9B4 7F099E84 C7A80218 */  lwc1  $f8, 0x218($sp)
/* 0CE9B8 7F099E88 C7A60238 */  lwc1  $f6, 0x238($sp)
/* 0CE9BC 7F099E8C 46045000 */  add.s $f0, $f10, $f4
/* 0CE9C0 7F099E90 46081282 */  mul.s $f10, $f2, $f8
/* 0CE9C4 7F099E94 C7A801F8 */  lwc1  $f8, 0x1f8($sp)
/* 0CE9C8 7F099E98 460A3100 */  add.s $f4, $f6, $f10
/* 0CE9CC 7F099E9C C7AA021C */  lwc1  $f10, 0x21c($sp)
/* 0CE9D0 7F099EA0 C7A6023C */  lwc1  $f6, 0x23c($sp)
/* 0CE9D4 7F099EA4 46044300 */  add.s $f12, $f8, $f4
/* 0CE9D8 7F099EA8 460A1202 */  mul.s $f8, $f2, $f10
/* 0CE9DC 7F099EAC C7AA01FC */  lwc1  $f10, 0x1fc($sp)
/* 0CE9E0 7F099EB0 460C003C */  c.lt.s $f0, $f12
/* 0CE9E4 7F099EB4 E7AC01D8 */  swc1  $f12, 0x1d8($sp)
/* 0CE9E8 7F099EB8 46083100 */  add.s $f4, $f6, $f8
/* 0CE9EC 7F099EBC 44813000 */  mtc1  $at, $f6
/* 0CE9F0 7F099EC0 45000003 */  bc1f  .L7F099ED0
/* 0CE9F4 7F099EC4 46045380 */   add.s $f14, $f10, $f4
/* 0CE9F8 7F099EC8 46006006 */  mov.s $f0, $f12
/* 0CE9FC 7F099ECC E7AC01D8 */  swc1  $f12, 0x1d8($sp)
.L7F099ED0:
/* 0CEA00 7F099ED0 460E003C */  c.lt.s $f0, $f14
/* 0CEA04 7F099ED4 E7AE01DC */  swc1  $f14, 0x1dc($sp)
/* 0CEA08 7F099ED8 45000003 */  bc1f  .L7F099EE8
/* 0CEA0C 7F099EDC 00000000 */   nop   
/* 0CEA10 7F099EE0 46007006 */  mov.s $f0, $f14
/* 0CEA14 7F099EE4 E7AE01DC */  swc1  $f14, 0x1dc($sp)
.L7F099EE8:
/* 0CEA18 7F099EE8 46060002 */  mul.s $f0, $f0, $f6
/* 0CEA1C 7F099EEC 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0CEA20 7F099EF0 44814000 */  mtc1  $at, $f8
/* 0CEA24 7F099EF4 00000000 */  nop   
/* 0CEA28 7F099EF8 4600403C */  c.lt.s $f8, $f0
/* 0CEA2C 7F099EFC 00000000 */  nop   
/* 0CEA30 7F099F00 45000005 */  bc1f  .L7F099F18
/* 0CEA34 7F099F04 3C013F80 */   li    $at, 0x3F800000 # 1.000000
/* 0CEA38 7F099F08 44815000 */  mtc1  $at, $f10
/* 0CEA3C 7F099F0C E7A001D4 */  swc1  $f0, 0x1d4($sp)
/* 0CEA40 7F099F10 10000004 */  b     .L7F099F24
/* 0CEA44 7F099F14 46005503 */   div.s $f20, $f10, $f0
.L7F099F18:
/* 0CEA48 7F099F18 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0CEA4C 7F099F1C 4481A000 */  mtc1  $at, $f20
/* 0CEA50 7F099F20 E7A001D4 */  swc1  $f0, 0x1d4($sp)
.L7F099F24:
/* 0CEA54 7F099F24 C7A40254 */  lwc1  $f4, 0x254($sp)
/* 0CEA58 7F099F28 E7B401C4 */  swc1  $f20, 0x1c4($sp)
/* 0CEA5C 7F099F2C 4604A302 */  mul.s $f12, $f20, $f4
/* 0CEA60 7F099F30 0FC250A6 */  jal   sub_GAME_7F094298
/* 0CEA64 7F099F34 00000000 */   nop   
/* 0CEA68 7F099F38 C7B401C4 */  lwc1  $f20, 0x1c4($sp)
/* 0CEA6C 7F099F3C C7A60258 */  lwc1  $f6, 0x258($sp)
/* 0CEA70 7F099F40 AFA200E0 */  sw    $v0, 0xe0($sp)
/* 0CEA74 7F099F44 4606A302 */  mul.s $f12, $f20, $f6
/* 0CEA78 7F099F48 0FC250A6 */  jal   sub_GAME_7F094298
/* 0CEA7C 7F099F4C 00000000 */   nop   
/* 0CEA80 7F099F50 C7B401C4 */  lwc1  $f20, 0x1c4($sp)
/* 0CEA84 7F099F54 C7A8025C */  lwc1  $f8, 0x25c($sp)
/* 0CEA88 7F099F58 AFA200DC */  sw    $v0, 0xdc($sp)
/* 0CEA8C 7F099F5C 4608A302 */  mul.s $f12, $f20, $f8
/* 0CEA90 7F099F60 0FC250A6 */  jal   sub_GAME_7F094298
/* 0CEA94 7F099F64 00000000 */   nop   
/* 0CEA98 7F099F68 C7B401C4 */  lwc1  $f20, 0x1c4($sp)
/* 0CEA9C 7F099F6C C7AA0260 */  lwc1  $f10, 0x260($sp)
/* 0CEAA0 7F099F70 AFA200D8 */  sw    $v0, 0xd8($sp)
/* 0CEAA4 7F099F74 460AA302 */  mul.s $f12, $f20, $f10
/* 0CEAA8 7F099F78 0FC250A6 */  jal   sub_GAME_7F094298
/* 0CEAAC 7F099F7C 00000000 */   nop   
/* 0CEAB0 7F099F80 C7B401C4 */  lwc1  $f20, 0x1c4($sp)
/* 0CEAB4 7F099F84 C7A402D4 */  lwc1  $f4, 0x2d4($sp)
/* 0CEAB8 7F099F88 AFA200D4 */  sw    $v0, 0xd4($sp)
/* 0CEABC 7F099F8C 4604A302 */  mul.s $f12, $f20, $f4
/* 0CEAC0 7F099F90 0FC250A6 */  jal   sub_GAME_7F094298
/* 0CEAC4 7F099F94 00000000 */   nop   
/* 0CEAC8 7F099F98 C7B401C4 */  lwc1  $f20, 0x1c4($sp)
/* 0CEACC 7F099F9C C7A602D8 */  lwc1  $f6, 0x2d8($sp)
/* 0CEAD0 7F099FA0 AFA200D0 */  sw    $v0, 0xd0($sp)
/* 0CEAD4 7F099FA4 4606A302 */  mul.s $f12, $f20, $f6
/* 0CEAD8 7F099FA8 0FC250A6 */  jal   sub_GAME_7F094298
/* 0CEADC 7F099FAC 00000000 */   nop   
/* 0CEAE0 7F099FB0 C7B401C4 */  lwc1  $f20, 0x1c4($sp)
/* 0CEAE4 7F099FB4 C7A802DC */  lwc1  $f8, 0x2dc($sp)
/* 0CEAE8 7F099FB8 AFA200CC */  sw    $v0, 0xcc($sp)
/* 0CEAEC 7F099FBC 4608A302 */  mul.s $f12, $f20, $f8
/* 0CEAF0 7F099FC0 0FC250A6 */  jal   sub_GAME_7F094298
/* 0CEAF4 7F099FC4 00000000 */   nop   
/* 0CEAF8 7F099FC8 C7B401C4 */  lwc1  $f20, 0x1c4($sp)
/* 0CEAFC 7F099FCC C7AA02E0 */  lwc1  $f10, 0x2e0($sp)
/* 0CEB00 7F099FD0 AFA200C8 */  sw    $v0, 0xc8($sp)
/* 0CEB04 7F099FD4 460AA302 */  mul.s $f12, $f20, $f10
/* 0CEB08 7F099FD8 0FC250A6 */  jal   sub_GAME_7F094298
/* 0CEB0C 7F099FDC 00000000 */   nop   
/* 0CEB10 7F099FE0 C7B401C4 */  lwc1  $f20, 0x1c4($sp)
/* 0CEB14 7F099FE4 C7A402F4 */  lwc1  $f4, 0x2f4($sp)
/* 0CEB18 7F099FE8 AFA200C4 */  sw    $v0, 0xc4($sp)
/* 0CEB1C 7F099FEC 4604A302 */  mul.s $f12, $f20, $f4
/* 0CEB20 7F099FF0 0FC250A6 */  jal   sub_GAME_7F094298
/* 0CEB24 7F099FF4 00000000 */   nop   
/* 0CEB28 7F099FF8 C7B401C4 */  lwc1  $f20, 0x1c4($sp)
/* 0CEB2C 7F099FFC C7A602F8 */  lwc1  $f6, 0x2f8($sp)
/* 0CEB30 7F09A000 AFA200B0 */  sw    $v0, 0xb0($sp)
/* 0CEB34 7F09A004 4606A302 */  mul.s $f12, $f20, $f6
/* 0CEB38 7F09A008 0FC250A6 */  jal   sub_GAME_7F094298
/* 0CEB3C 7F09A00C 00000000 */   nop   
/* 0CEB40 7F09A010 C7B401C4 */  lwc1  $f20, 0x1c4($sp)
/* 0CEB44 7F09A014 C7A802FC */  lwc1  $f8, 0x2fc($sp)
/* 0CEB48 7F09A018 AFA200AC */  sw    $v0, 0xac($sp)
/* 0CEB4C 7F09A01C 4608A302 */  mul.s $f12, $f20, $f8
/* 0CEB50 7F09A020 0FC250A6 */  jal   sub_GAME_7F094298
/* 0CEB54 7F09A024 00000000 */   nop   
/* 0CEB58 7F09A028 C7B401C4 */  lwc1  $f20, 0x1c4($sp)
/* 0CEB5C 7F09A02C C7AA0300 */  lwc1  $f10, 0x300($sp)
/* 0CEB60 7F09A030 AFA200A8 */  sw    $v0, 0xa8($sp)
/* 0CEB64 7F09A034 460AA302 */  mul.s $f12, $f20, $f10
/* 0CEB68 7F09A038 0FC250A6 */  jal   sub_GAME_7F094298
/* 0CEB6C 7F09A03C 00000000 */   nop   
/* 0CEB70 7F09A040 C7B401C4 */  lwc1  $f20, 0x1c4($sp)
/* 0CEB74 7F09A044 C7A40274 */  lwc1  $f4, 0x274($sp)
/* 0CEB78 7F09A048 AFA200A4 */  sw    $v0, 0xa4($sp)
/* 0CEB7C 7F09A04C 4604A302 */  mul.s $f12, $f20, $f4
/* 0CEB80 7F09A050 0FC250A6 */  jal   sub_GAME_7F094298
/* 0CEB84 7F09A054 00000000 */   nop   
/* 0CEB88 7F09A058 C7B401C4 */  lwc1  $f20, 0x1c4($sp)
/* 0CEB8C 7F09A05C C7A60278 */  lwc1  $f6, 0x278($sp)
/* 0CEB90 7F09A060 AFA200C0 */  sw    $v0, 0xc0($sp)
/* 0CEB94 7F09A064 4606A302 */  mul.s $f12, $f20, $f6
/* 0CEB98 7F09A068 0FC250A6 */  jal   sub_GAME_7F094298
/* 0CEB9C 7F09A06C 00000000 */   nop   
/* 0CEBA0 7F09A070 C7B401C4 */  lwc1  $f20, 0x1c4($sp)
/* 0CEBA4 7F09A074 C7A8027C */  lwc1  $f8, 0x27c($sp)
/* 0CEBA8 7F09A078 AFA200BC */  sw    $v0, 0xbc($sp)
/* 0CEBAC 7F09A07C 4608A302 */  mul.s $f12, $f20, $f8
/* 0CEBB0 7F09A080 0FC250A6 */  jal   sub_GAME_7F094298
/* 0CEBB4 7F09A084 00000000 */   nop   
/* 0CEBB8 7F09A088 C7B401C4 */  lwc1  $f20, 0x1c4($sp)
/* 0CEBBC 7F09A08C C7AA0280 */  lwc1  $f10, 0x280($sp)
/* 0CEBC0 7F09A090 AFA200B8 */  sw    $v0, 0xb8($sp)
/* 0CEBC4 7F09A094 460AA302 */  mul.s $f12, $f20, $f10
/* 0CEBC8 7F09A098 0FC250A6 */  jal   sub_GAME_7F094298
/* 0CEBCC 7F09A09C 00000000 */   nop   
/* 0CEBD0 7F09A0A0 8FA800B8 */  lw    $t0, 0xb8($sp)
/* 0CEBD4 7F09A0A4 8FAB00D4 */  lw    $t3, 0xd4($sp)
/* 0CEBD8 7F09A0A8 8FBF00E0 */  lw    $ra, 0xe0($sp)
/* 0CEBDC 7F09A0AC 3C0DB400 */  lui   $t5, 0xb400
/* 0CEBE0 7F09A0B0 AE0D0000 */  sw    $t5, ($s0)
/* 0CEBE4 7F09A0B4 8FB800DC */  lw    $t8, 0xdc($sp)
/* 0CEBE8 7F09A0B8 3C09FFFF */  lui   $t1, 0xffff
/* 0CEBEC 7F09A0BC 03E97024 */  and   $t6, $ra, $t1
/* 0CEBF0 7F09A0C0 0309C824 */  and   $t9, $t8, $t1
/* 0CEBF4 7F09A0C4 00197C02 */  srl   $t7, $t9, 0x10
/* 0CEBF8 7F09A0C8 01CFC025 */  or    $t8, $t6, $t7
/* 0CEBFC 7F09A0CC AE180004 */  sw    $t8, 4($s0)
/* 0CEC00 7F09A0D0 26040008 */  addiu $a0, $s0, 8
/* 0CEC04 7F09A0D4 3C19B200 */  lui   $t9, 0xb200
/* 0CEC08 7F09A0D8 AC990000 */  sw    $t9, ($a0)
/* 0CEC0C 7F09A0DC 8FAE00D8 */  lw    $t6, 0xd8($sp)
/* 0CEC10 7F09A0E0 0169C024 */  and   $t8, $t3, $t1
/* 0CEC14 7F09A0E4 0018CC02 */  srl   $t9, $t8, 0x10
/* 0CEC18 7F09A0E8 01C97824 */  and   $t7, $t6, $t1
/* 0CEC1C 7F09A0EC 01F97025 */  or    $t6, $t7, $t9
/* 0CEC20 7F09A0F0 AC8E0004 */  sw    $t6, 4($a0)
/* 0CEC24 7F09A0F4 24850008 */  addiu $a1, $a0, 8
/* 0CEC28 7F09A0F8 ACAD0000 */  sw    $t5, ($a1)
/* 0CEC2C 7F09A0FC 8FB900CC */  lw    $t9, 0xcc($sp)
/* 0CEC30 7F09A100 8FB800D0 */  lw    $t8, 0xd0($sp)
/* 0CEC34 7F09A104 24A60008 */  addiu $a2, $a1, 8
/* 0CEC38 7F09A108 03297024 */  and   $t6, $t9, $t1
/* 0CEC3C 7F09A10C 03097824 */  and   $t7, $t8, $t1
/* 0CEC40 7F09A110 000EC402 */  srl   $t8, $t6, 0x10
/* 0CEC44 7F09A114 01F8C825 */  or    $t9, $t7, $t8
/* 0CEC48 7F09A118 ACB90004 */  sw    $t9, 4($a1)
/* 0CEC4C 7F09A11C 8FAC00C4 */  lw    $t4, 0xc4($sp)
/* 0CEC50 7F09A120 3C0EB200 */  lui   $t6, 0xb200
/* 0CEC54 7F09A124 ACCE0000 */  sw    $t6, ($a2)
/* 0CEC58 7F09A128 8FAF00C8 */  lw    $t7, 0xc8($sp)
/* 0CEC5C 7F09A12C 0189C824 */  and   $t9, $t4, $t1
/* 0CEC60 7F09A130 00197402 */  srl   $t6, $t9, 0x10
/* 0CEC64 7F09A134 01E9C024 */  and   $t8, $t7, $t1
/* 0CEC68 7F09A138 030E7825 */  or    $t7, $t8, $t6
/* 0CEC6C 7F09A13C ACCF0004 */  sw    $t7, 4($a2)
/* 0CEC70 7F09A140 24C30008 */  addiu $v1, $a2, 8
/* 0CEC74 7F09A144 AC6D0000 */  sw    $t5, ($v1)
/* 0CEC78 7F09A148 8FAE00DC */  lw    $t6, 0xdc($sp)
/* 0CEC7C 7F09A14C 001FC400 */  sll   $t8, $ra, 0x10
/* 0CEC80 7F09A150 24700008 */  addiu $s0, $v1, 8
/* 0CEC84 7F09A154 31CFFFFF */  andi  $t7, $t6, 0xffff
/* 0CEC88 7F09A158 030FC825 */  or    $t9, $t8, $t7
/* 0CEC8C 7F09A15C AC790004 */  sw    $t9, 4($v1)
/* 0CEC90 7F09A160 3C0EB200 */  lui   $t6, 0xb200
/* 0CEC94 7F09A164 AE0E0000 */  sw    $t6, ($s0)
/* 0CEC98 7F09A168 8FAF00D8 */  lw    $t7, 0xd8($sp)
/* 0CEC9C 7F09A16C 316EFFFF */  andi  $t6, $t3, 0xffff
/* 0CECA0 7F09A170 26070008 */  addiu $a3, $s0, 8
/* 0CECA4 7F09A174 000FCC00 */  sll   $t9, $t7, 0x10
/* 0CECA8 7F09A178 032EC025 */  or    $t8, $t9, $t6
/* 0CECAC 7F09A17C AE180004 */  sw    $t8, 4($s0)
/* 0CECB0 7F09A180 ACED0000 */  sw    $t5, ($a3)
/* 0CECB4 7F09A184 8FB800CC */  lw    $t8, 0xcc($sp)
/* 0CECB8 7F09A188 8FB900D0 */  lw    $t9, 0xd0($sp)
/* 0CECBC 7F09A18C 8FAB00C0 */  lw    $t3, 0xc0($sp)
/* 0CECC0 7F09A190 330FFFFF */  andi  $t7, $t8, 0xffff
/* 0CECC4 7F09A194 00197400 */  sll   $t6, $t9, 0x10
/* 0CECC8 7F09A198 8FA600BC */  lw    $a2, 0xbc($sp)
/* 0CECCC 7F09A19C 01CFC825 */  or    $t9, $t6, $t7
/* 0CECD0 7F09A1A0 ACF90004 */  sw    $t9, 4($a3)
/* 0CECD4 7F09A1A4 3C0DB200 */  lui   $t5, 0xb200
/* 0CECD8 7F09A1A8 24E30008 */  addiu $v1, $a3, 8
/* 0CECDC 7F09A1AC AC6D0000 */  sw    $t5, ($v1)
/* 0CECE0 7F09A1B0 8FAE00C8 */  lw    $t6, 0xc8($sp)
/* 0CECE4 7F09A1B4 3199FFFF */  andi  $t9, $t4, 0xffff
/* 0CECE8 7F09A1B8 24640008 */  addiu $a0, $v1, 8
/* 0CECEC 7F09A1BC 000E7C00 */  sll   $t7, $t6, 0x10
/* 0CECF0 7F09A1C0 01F9C025 */  or    $t8, $t7, $t9
/* 0CECF4 7F09A1C4 AC780004 */  sw    $t8, 4($v1)
/* 0CECF8 7F09A1C8 3C0EB400 */  lui   $t6, 0xb400
/* 0CECFC 7F09A1CC 00C9C824 */  and   $t9, $a2, $t1
/* 0CED00 7F09A1D0 0019C402 */  srl   $t8, $t9, 0x10
/* 0CED04 7F09A1D4 AC8E0000 */  sw    $t6, ($a0)
/* 0CED08 7F09A1D8 01697824 */  and   $t7, $t3, $t1
/* 0CED0C 7F09A1DC 01F87025 */  or    $t6, $t7, $t8
/* 0CED10 7F09A1E0 00497824 */  and   $t7, $v0, $t1
/* 0CED14 7F09A1E4 AC8E0004 */  sw    $t6, 4($a0)
/* 0CED18 7F09A1E8 000FC402 */  srl   $t8, $t7, 0x10
/* 0CED1C 7F09A1EC 0109C824 */  and   $t9, $t0, $t1
/* 0CED20 7F09A1F0 24850008 */  addiu $a1, $a0, 8
/* 0CED24 7F09A1F4 03387025 */  or    $t6, $t9, $t8
/* 0CED28 7F09A1F8 ACAE0004 */  sw    $t6, 4($a1)
/* 0CED2C 7F09A1FC ACAD0000 */  sw    $t5, ($a1)
/* 0CED30 7F09A200 8FBF00AC */  lw    $ra, 0xac($sp)
/* 0CED34 7F09A204 8FAD00B0 */  lw    $t5, 0xb0($sp)
/* 0CED38 7F09A208 00405025 */  move  $t2, $v0
/* 0CED3C 7F09A20C 24B00008 */  addiu $s0, $a1, 8
/* 0CED40 7F09A210 8FAC00A8 */  lw    $t4, 0xa8($sp)
/* 0CED44 7F09A214 8FA700A4 */  lw    $a3, 0xa4($sp)
/* 0CED48 7F09A218 02001025 */  move  $v0, $s0
/* 0CED4C 7F09A21C 3C0FB400 */  lui   $t7, 0xb400
/* 0CED50 7F09A220 03E9C024 */  and   $t8, $ra, $t1
/* 0CED54 7F09A224 00187402 */  srl   $t6, $t8, 0x10
/* 0CED58 7F09A228 AC4F0000 */  sw    $t7, ($v0)
/* 0CED5C 7F09A22C 01A9C824 */  and   $t9, $t5, $t1
/* 0CED60 7F09A230 032E7825 */  or    $t7, $t9, $t6
/* 0CED64 7F09A234 AC4F0004 */  sw    $t7, 4($v0)
/* 0CED68 7F09A238 26030008 */  addiu $v1, $s0, 8
/* 0CED6C 7F09A23C 3C18B200 */  lui   $t8, 0xb200
/* 0CED70 7F09A240 00E97024 */  and   $t6, $a3, $t1
/* 0CED74 7F09A244 000E7C02 */  srl   $t7, $t6, 0x10
/* 0CED78 7F09A248 AC780000 */  sw    $t8, ($v1)
/* 0CED7C 7F09A24C 0189C824 */  and   $t9, $t4, $t1
/* 0CED80 7F09A250 032FC025 */  or    $t8, $t9, $t7
/* 0CED84 7F09A254 AC780004 */  sw    $t8, 4($v1)
/* 0CED88 7F09A258 24700008 */  addiu $s0, $v1, 8
/* 0CED8C 7F09A25C 3C0EB400 */  lui   $t6, 0xb400
/* 0CED90 7F09A260 AE0E0000 */  sw    $t6, ($s0)
/* 0CED94 7F09A264 000B7C00 */  sll   $t7, $t3, 0x10
/* 0CED98 7F09A268 30D8FFFF */  andi  $t8, $a2, 0xffff
/* 0CED9C 7F09A26C 01F87025 */  or    $t6, $t7, $t8
/* 0CEDA0 7F09A270 AE0E0004 */  sw    $t6, 4($s0)
/* 0CEDA4 7F09A274 26050008 */  addiu $a1, $s0, 8
/* 0CEDA8 7F09A278 3C19B200 */  lui   $t9, 0xb200
/* 0CEDAC 7F09A27C ACB90000 */  sw    $t9, ($a1)
/* 0CEDB0 7F09A280 314EFFFF */  andi  $t6, $t2, 0xffff
/* 0CEDB4 7F09A284 0008C400 */  sll   $t8, $t0, 0x10
/* 0CEDB8 7F09A288 030EC825 */  or    $t9, $t8, $t6
/* 0CEDBC 7F09A28C ACB90004 */  sw    $t9, 4($a1)
/* 0CEDC0 7F09A290 24A30008 */  addiu $v1, $a1, 8
/* 0CEDC4 7F09A294 3C0FB400 */  lui   $t7, 0xb400
/* 0CEDC8 7F09A298 AC6F0000 */  sw    $t7, ($v1)
/* 0CEDCC 7F09A29C 33F9FFFF */  andi  $t9, $ra, 0xffff
/* 0CEDD0 7F09A2A0 000D7400 */  sll   $t6, $t5, 0x10
/* 0CEDD4 7F09A2A4 01D97825 */  or    $t7, $t6, $t9
/* 0CEDD8 7F09A2A8 AC6F0004 */  sw    $t7, 4($v1)
/* 0CEDDC 7F09A2AC 24640008 */  addiu $a0, $v1, 8
/* 0CEDE0 7F09A2B0 3C18B300 */  lui   $t8, 0xb300
/* 0CEDE4 7F09A2B4 AC980000 */  sw    $t8, ($a0)
/* 0CEDE8 7F09A2B8 000CCC00 */  sll   $t9, $t4, 0x10
/* 0CEDEC 7F09A2BC 30EFFFFF */  andi  $t7, $a3, 0xffff
/* 0CEDF0 7F09A2C0 032FC025 */  or    $t8, $t9, $t7
/* 0CEDF4 7F09A2C4 AC980004 */  sw    $t8, 4($a0)
/* 0CEDF8 7F09A2C8 24820008 */  addiu $v0, $a0, 8
.L7F09A2CC:
/* 0CEDFC 7F09A2CC 8FBF0024 */  lw    $ra, 0x24($sp)
/* 0CEE00 7F09A2D0 D7B40018 */  ldc1  $f20, 0x18($sp)
/* 0CEE04 7F09A2D4 8FB00020 */  lw    $s0, 0x20($sp)
/* 0CEE08 7F09A2D8 03E00008 */  jr    $ra
/* 0CEE0C 7F09A2DC 27BD04D0 */   addiu $sp, $sp, 0x4d0
)
#endif





#ifdef NONMATCHING
void default_player_perspective_and_height(void)
{
    player1_playerdata[0].handicap = 1.00000000;
    player1_playerdata[0].player_perspective_height = 1.00000000;
    player1_playerdata[1].handicap = 1.00000000;
    player1_playerdata[1].player_perspective_height = 1.00000000;
    player1_playerdata[2].handicap = 1.00000000;
    player1_playerdata[2].player_perspective_height = 1.00000000;
    player1_playerdata[3].handicap = 1.00000000;
    player1_playerdata[3].player_perspective_height = 1.00000000;
}
#else
GLOBAL_ASM(
.text
glabel default_player_perspective_and_height
/* 0CEE10 7F09A2E0 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0CEE14 7F09A2E4 44810000 */  mtc1  $at, $f0
/* 0CEE18 7F09A2E8 3C018008 */  lui   $at, %hi(player1_player_data+0x64)
/* 0CEE1C 7F09A2EC E4209F54 */  swc1  $f0, %lo(player1_player_data+0x64)($at)
/* 0CEE20 7F09A2F0 3C018008 */  lui   $at, %hi(player1_player_data+0x5c)
/* 0CEE24 7F09A2F4 E4209F4C */  swc1  $f0, %lo(player1_player_data+0x5c)($at)
/* 0CEE28 7F09A2F8 3C018008 */  lui   $at, %hi(player2_player_data+0x64)
/* 0CEE2C 7F09A2FC E4209FC4 */  swc1  $f0, %lo(player2_player_data+0x64)($at)
/* 0CEE30 7F09A300 3C018008 */  lui   $at, %hi(player2_player_data+0x5C)
/* 0CEE34 7F09A304 E4209FBC */  swc1  $f0, %lo(player2_player_data+0x5C)($at)
/* 0CEE38 7F09A308 3C018008 */  lui   $at, %hi(player3_player_data+0x64)
/* 0CEE3C 7F09A30C E420A034 */  swc1  $f0, %lo(player3_player_data+0x64)($at)
/* 0CEE40 7F09A310 3C018008 */  lui   $at, %hi(player3_player_data+0x5C)
/* 0CEE44 7F09A314 E420A02C */  swc1  $f0, %lo(player3_player_data+0x5C)($at)
/* 0CEE48 7F09A318 3C018008 */  lui   $at, %hi(player4_player_data+0x64)
/* 0CEE4C 7F09A31C E420A0A4 */  swc1  $f0, %lo(player4_player_data+0x64)($at)
/* 0CEE50 7F09A320 3C018008 */  lui   $at, %hi(player4_player_data+92)
/* 0CEE54 7F09A324 03E00008 */  jr    $ra
/* 0CEE58 7F09A328 E420A09C */   swc1  $f0, %lo(player4_player_data+92)($at)
)
#endif





#ifdef NONMATCHING
void reset_play_data_ptrs(void)
{
    players[0] = NULL;
    players[1] = NULL;
    players[2] = NULL;
    players[3] = NULL;
    pPlayer = NULL;
    pPlayersPerm = NULL;
    player_num = 0;
    random_byte = 0;
    DAT_8007a0c0 = 0;
    DAT_8007a0c4 = 1;
    DAT_8007a0c8 = 2;
    DAT_8007a0cc = 3;
}
#else
GLOBAL_ASM(
.text
glabel reset_play_data_ptrs
/* 0CEE5C 7F09A32C 3C028008 */  lui   $v0, %hi(players)
/* 0CEE60 7F09A330 24429EE0 */  addiu $v0, %lo(players) # addiu $v0, $v0, -0x6120
/* 0CEE64 7F09A334 AC400000 */  sw    $zero, ($v0)
/* 0CEE68 7F09A338 AC400004 */  sw    $zero, 4($v0)
/* 0CEE6C 7F09A33C AC400008 */  sw    $zero, 8($v0)
/* 0CEE70 7F09A340 AC40000C */  sw    $zero, 0xc($v0)
/* 0CEE74 7F09A344 3C018008 */  lui   $at, %hi(pPlayer)
/* 0CEE78 7F09A348 AC20A0B0 */  sw    $zero, %lo(pPlayer)($at)
/* 0CEE7C 7F09A34C 3C018008 */  lui   $at, %hi(pPlayersPerm)
/* 0CEE80 7F09A350 AC20A0B4 */  sw    $zero, %lo(pPlayersPerm)($at)
/* 0CEE84 7F09A354 3C018008 */  lui   $at, %hi(player_num)
/* 0CEE88 7F09A358 AC20A0B8 */  sw    $zero, %lo(player_num)($at)
/* 0CEE8C 7F09A35C 3C038008 */  lui   $v1, %hi(dword_CODE_bss_8007A0C0)
/* 0CEE90 7F09A360 3C018008 */  lui   $at, %hi(random_byte)
/* 0CEE94 7F09A364 2463A0C0 */  addiu $v1, %lo(dword_CODE_bss_8007A0C0) # addiu $v1, $v1, -0x5f40
/* 0CEE98 7F09A368 AC20A0BC */  sw    $zero, %lo(random_byte)($at)
/* 0CEE9C 7F09A36C 240E0001 */  li    $t6, 1
/* 0CEEA0 7F09A370 240F0002 */  li    $t7, 2
/* 0CEEA4 7F09A374 24180003 */  li    $t8, 3
/* 0CEEA8 7F09A378 AC600000 */  sw    $zero, ($v1)
/* 0CEEAC 7F09A37C AC6E0004 */  sw    $t6, 4($v1)
/* 0CEEB0 7F09A380 AC6F0008 */  sw    $t7, 8($v1)
/* 0CEEB4 7F09A384 03E00008 */  jr    $ra
/* 0CEEB8 7F09A388 AC78000C */   sw    $t8, 0xc($v1)
)
#endif




#ifdef NONMATCHING
void init_player_data_ptrs_construct_viewports(int playercount)
{
    int player;
    
    players[0] = NULL;
    players[1] = NULL;
    players[2] = NULL;
    players[3] = NULL;

    random_byte = get_random_value() & 0xff;
    if (playercount < 1) {
        initBONDdataforPlayer(0);
        set_cur_player(0);
        set_cur_player_screen_size( viGetViewWidth(), viGetViewHeight() );
        set_cur_player_viewport_size( viGetViewLeft(), viGetViewTop() );
    }
    else {
        for (player = 0; player != playercount; player++)
        {
            initBONDdataforPlayer(player);
        }
        set_cur_player(0);
    }
    return;
}
#else
GLOBAL_ASM(
.text
glabel init_player_data_ptrs_construct_viewports
/* 0CEEBC 7F09A38C 3C028008 */  lui   $v0, %hi(players)
/* 0CEEC0 7F09A390 24429EE0 */  addiu $v0, %lo(players) # addiu $v0, $v0, -0x6120
/* 0CEEC4 7F09A394 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0CEEC8 7F09A398 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0CEECC 7F09A39C AFB10018 */  sw    $s1, 0x18($sp)
/* 0CEED0 7F09A3A0 00808825 */  move  $s1, $a0
/* 0CEED4 7F09A3A4 AFB00014 */  sw    $s0, 0x14($sp)
/* 0CEED8 7F09A3A8 AC400000 */  sw    $zero, ($v0)
/* 0CEEDC 7F09A3AC AC400004 */  sw    $zero, 4($v0)
/* 0CEEE0 7F09A3B0 AC400008 */  sw    $zero, 8($v0)
/* 0CEEE4 7F09A3B4 0C002914 */  jal   get_random_value
/* 0CEEE8 7F09A3B8 AC40000C */   sw    $zero, 0xc($v0)
/* 0CEEEC 7F09A3BC 304E00FF */  andi  $t6, $v0, 0xff
/* 0CEEF0 7F09A3C0 3C018008 */  lui   $at, %hi(random_byte)
/* 0CEEF4 7F09A3C4 1A20000C */  blez  $s1, .L7F09A3F8
/* 0CEEF8 7F09A3C8 AC2EA0BC */   sw    $t6, %lo(random_byte)($at)
/* 0CEEFC 7F09A3CC 1A200006 */  blez  $s1, .L7F09A3E8
/* 0CEF00 7F09A3D0 00008025 */   move  $s0, $zero
.L7F09A3D4:
/* 0CEF04 7F09A3D4 0FC2692F */  jal   initBONDdataforPlayer
/* 0CEF08 7F09A3D8 02002025 */   move  $a0, $s0
/* 0CEF0C 7F09A3DC 26100001 */  addiu $s0, $s0, 1
/* 0CEF10 7F09A3E0 1611FFFC */  bne   $s0, $s1, .L7F09A3D4
/* 0CEF14 7F09A3E4 00000000 */   nop   
.L7F09A3E8:
/* 0CEF18 7F09A3E8 0FC26C43 */  jal   set_cur_player
/* 0CEF1C 7F09A3EC 00002025 */   move  $a0, $zero
/* 0CEF20 7F09A3F0 10000018 */  b     .L7F09A454
/* 0CEF24 7F09A3F4 8FBF001C */   lw    $ra, 0x1c($sp)
.L7F09A3F8:
/* 0CEF28 7F09A3F8 0FC2692F */  jal   initBONDdataforPlayer
/* 0CEF2C 7F09A3FC 00002025 */   move  $a0, $zero
/* 0CEF30 7F09A400 0FC26C43 */  jal   set_cur_player
/* 0CEF34 7F09A404 00002025 */   move  $a0, $zero
/* 0CEF38 7F09A408 0C001127 */  jal   viGetViewWidth
/* 0CEF3C 7F09A40C 00000000 */   nop   
/* 0CEF40 7F09A410 00028400 */  sll   $s0, $v0, 0x10
/* 0CEF44 7F09A414 00107C03 */  sra   $t7, $s0, 0x10
/* 0CEF48 7F09A418 0C00112B */  jal   viGetViewHeight
/* 0CEF4C 7F09A41C 01E08025 */   move  $s0, $t7
/* 0CEF50 7F09A420 02002025 */  move  $a0, $s0
/* 0CEF54 7F09A424 0FC26C77 */  jal   set_cur_player_screen_size
/* 0CEF58 7F09A428 00402825 */   move  $a1, $v0
/* 0CEF5C 7F09A42C 0C001145 */  jal   viGetViewLeft
/* 0CEF60 7F09A430 00000000 */   nop   
/* 0CEF64 7F09A434 00028400 */  sll   $s0, $v0, 0x10
/* 0CEF68 7F09A438 0010C403 */  sra   $t8, $s0, 0x10
/* 0CEF6C 7F09A43C 0C001149 */  jal   viGetViewTop
/* 0CEF70 7F09A440 03008025 */   move  $s0, $t8
/* 0CEF74 7F09A444 02002025 */  move  $a0, $s0
/* 0CEF78 7F09A448 0FC26C7E */  jal   set_cur_player_viewport_size
/* 0CEF7C 7F09A44C 00402825 */   move  $a1, $v0
/* 0CEF80 7F09A450 8FBF001C */  lw    $ra, 0x1c($sp)
.L7F09A454:
/* 0CEF84 7F09A454 8FB00014 */  lw    $s0, 0x14($sp)
/* 0CEF88 7F09A458 8FB10018 */  lw    $s1, 0x18($sp)
/* 0CEF8C 7F09A45C 03E00008 */  jr    $ra
/* 0CEF90 7F09A460 27BD0020 */   addiu $sp, $sp, 0x20
)
#endif

s32 getPlayerCount(void)
{
    s32 count = 0;
    s32 i;
    for (i = 0; i < 4; i++) {
        if (players[i] != NULL) {
            count++;
        }
    }
    return count;
}

#ifdef NONMATCHING
void initBONDdataforPlayer(PLAYER_ID player)
{
    int iVar1;
    int iVar2;
    player **ppPVar3;
    int *dest;
    int *src;
    int *src_next;
    player *pPVar4;
    int array234undefined4 [234];
    int iStack4;
    f32 temp_3f36e15f8e;
    
    src = init_BONDdata_related_8003fda0;
    dest = array234undefined4;
    do {
        src_next = src + 3;
        *dest = *src;
        dest[1] = src[1];
        dest[2] = src[2];
        src = src_next;
        dest = dest + 3;
    } while (src_next != (int *)0x80040148);
    pPVar4 = (player *)mempAllocBytesInBank(0x2a80,4);
    ppPVar3 = players + player;
    *ppPVar3 = pPVar4;
    pPVar4->unknown = 0;
    (*ppPVar3)->xpos = 0.00000000;
    (*ppPVar3)->ypos = 0.00000000;
    (*ppPVar3)->zpos = 0.00000000;
    (*ppPVar3)->xpos2 = 0.00000000;
    (*ppPVar3)->ypos2 = 0.00000000;
    (*ppPVar3)->zpos2 = 1.00000000;
    (*ppPVar3)->xoffset = 0.00000000;
    (*ppPVar3)->yoffset = 1.00000000;
    (*ppPVar3)->zoffset = 0.00000000;
    (*ppPVar3)->xpos3 = 0.00000000;
    (*ppPVar3)->ypos3 = 0.00000000;
    (*ppPVar3)->zpos3 = 0.00000000;
    (*ppPVar3)->room_pointer = 0;
    (*ppPVar3)->current_model_xpos = 0.00000000;
    (*ppPVar3)->current_model_ypos = 0.00000000;
    (*ppPVar3)->current_model_zpos = 0.00000000;
    (*ppPVar3)->previous_model_xpos = 0.00000000;
    (*ppPVar3)->previous_model_ypos = 0.00000000;
    (*ppPVar3)->previous_model_zpos = 0.00000000;
    (*ppPVar3)->current_room_xpos = 0.00000000;
    (*ppPVar3)->current_room_ypos = 0.00000000;
    (*ppPVar3)->current_room_zpos = 0.00000000;
    (*ppPVar3)->field_6C = 0.00000000;
    (*ppPVar3)->field_70 = 0.00000000;
    (*ppPVar3)->clipping_height = 0.00000000;
    (*ppPVar3)->field_78 = 0.00000000;
    (*ppPVar3)->field_7C = 0.00000000;
    (*ppPVar3)->field_80 = 0.00000000;
    (*ppPVar3)->field_84 = 0.00000000;
    (*ppPVar3)->field_88 = 0.00000000;
    (*ppPVar3)->field_8C = 0;
    (*ppPVar3)->field_90 = 0.00000000;
    (*ppPVar3)->field_94 = 0;
    (*ppPVar3)->field_98 = 0.00000000;
    (*ppPVar3)->swaytarget = 0.00000000;
    (*ppPVar3)->field_1278 = 0.00000000;
    (*ppPVar3)->field_127C = 0.00000000;
    (*ppPVar3)->crouchpos = 2;
    (*ppPVar3)->autocrouchpos = 2;
    (*ppPVar3)->ducking_height_offset = 0.00000000;
    (*ppPVar3)->field_A4 = 0.00000000;
    (*ppPVar3)->prop = 0;
    (*ppPVar3)->field_AC = 1;
    (*ppPVar3)->field_D0 = 0;
    (*ppPVar3)->ptr_char_objectinstance = 0;
    (*ppPVar3)->bonddead = 0;
    (*ppPVar3)->bondhealth = 1.00000000;
    (*ppPVar3)->bondarmour = 0.00000000;
    (*ppPVar3)->oldhealth = 1.00000000;
    (*ppPVar3)->oldarmour = 0.00000000;
    (*ppPVar3)->apparenthealth = 1.00000000;
    (*ppPVar3)->apparentarmour = 0.00000000;
    (*ppPVar3)->damageshowtime = -1;
    (*ppPVar3)->healthshowtime = -1;
    (*ppPVar3)->field_104 = 0;
    (*ppPVar3)->field_108 = 0;
    (*ppPVar3)->field_10C = 0;
    (*ppPVar3)->movecentrerelease = 0;
    (*ppPVar3)->lookaheadcentreenabled = 1;
    (*ppPVar3)->automovecentreenabled = 1;
    (*ppPVar3)->fastmovecentreenabled = 0;
    (*ppPVar3)->automovecentre = 1;
    (*ppPVar3)->insightaimmode = 0;
    (*ppPVar3)->autoyaimenabled = 1;
    (*ppPVar3)->autoaimy = 0.00000000;
    (*ppPVar3)->autoyaimtime = 0;
    (*ppPVar3)->autoyaimtime60 = -1;
    (*ppPVar3)->autoxaimenabled = 1;
    (*ppPVar3)->autoaimx = 0.00000000;
    (*ppPVar3)->autoxaimtime = 0;
    (*ppPVar3)->autoxaimtime60 = -1;
    (*ppPVar3)->vv_theta = 0.00000000;
    (*ppPVar3)->speedtheta = 0.00000000;
    (*ppPVar3)->vv_costheta = 1.00000000;
    (*ppPVar3)->vv_sintheta = 0.00000000;
    (*ppPVar3)->vv_verta = -4.00000000;
    (*ppPVar3)->vv_verta360 = -229.18310547;
    (*ppPVar3)->speedverta = 0.00000000;
    (*ppPVar3)->vv_cosverta = 1.00000000;
    (*ppPVar3)->vv_sinverta = 0.00000000;
    (*ppPVar3)->speedsideways = 0.00000000;
    (*ppPVar3)->speedstrafe = 0.00000000;
    (*ppPVar3)->speedforwards = 0.00000000;
    (*ppPVar3)->field_2A4C = 0.00000000;
    (*ppPVar3)->speedboost = 1.00000000;
    (*ppPVar3)->boost_factor_x = 0.00000000;
    (*ppPVar3)->boost_factor_y = 0.00000000;
    (*ppPVar3)->boost_factor_z = 0.00000000;
    (*ppPVar3)->bondfadetime60 = -1.00000000;
    (*ppPVar3)->bondfadetimemax60 = -1.00000000;
    (*ppPVar3)->bondfadefracold = 0.00000000;
    (*ppPVar3)->bondfadefracnew = 0.00000000;
    (*ppPVar3)->field_19C = 0.00000000;
    (*ppPVar3)->field_1A0 = 0;
    (*ppPVar3)->field_1C0 = 0;
    (*ppPVar3)->field_1C4 = 0;
    (*ppPVar3)->pause_animation_state = 0;
    (*ppPVar3)->paused_flag = 1;
    (*ppPVar3)->open_close_solo_watch_menu = 0;
    (*ppPVar3)->field_1D4 = 0.00000000;
    (*ppPVar3)->field_1D8 = 0.00000000;
    (*ppPVar3)->pause_watch_position = -25.00000000;
    (*ppPVar3)->field_1E0 = 0.00000000;
    (*ppPVar3)->field_1E4 = 1.00000000;
    (*ppPVar3)->field_1E8 = 0.00000000;
    (*ppPVar3)->field_1EC = 0.00000000;
    (*ppPVar3)->field_1F0 = 0.00000000;
    (*ppPVar3)->field_1F4 = 1.00000000;
    (*ppPVar3)->pausing_flag = 0;
    (*ppPVar3)->pause_starting_angle = 0.00000000;
    (*ppPVar3)->field_208 = 0.00000000;
    (*ppPVar3)->pause_target_angle = 0.00000000;
    (*ppPVar3)->field_210 = 0.00000000;
    (*ppPVar3)->field_214 = 0.00000000;
    (*ppPVar3)->field_218 = 0;
    (*ppPVar3)->field_21C = 1;
    (*ppPVar3)->step_in_view_watch_animation = 0;
    (*ppPVar3)->pause_animation_counter = 0.00000000;
    (*ppPVar3)->field_3B4 = 0;
    (*ppPVar3)->field_3B6 = 0;
    (*ppPVar3)->field_3B8 = 0.00000000;
    (*ppPVar3)->field_3BC = 0.00000000;
    *(float *)&(*ppPVar3)->field_3C0 = 9.99999809;
    (*ppPVar3)->field_3C4 = 0.00000000;
    (*ppPVar3)->field_3C8 = 0.00000000;
    (*ppPVar3)->field_3CC = 1.00000000;
    (*ppPVar3)->colourscreenred = 0xff;
    (*ppPVar3)->colourscreengreen = 0xff;
    (*ppPVar3)->colourscreenblue = 0xff;
    (*ppPVar3)->colourscreenfrac = 0.00000000;
    (*ppPVar3)->field_3E0 = -1.00000000;
    (*ppPVar3)->timer_for_fade = -1.00000000;
    (*ppPVar3)->colourfaderedold = 0xff;
    (*ppPVar3)->colourfaderednew = 0xff;
    (*ppPVar3)->colourfadegreenold = 0xff;
    (*ppPVar3)->colourfadegreennew = 0xff;
    (*ppPVar3)->colourfadeblueold = 0xff;
    (*ppPVar3)->colourfadebluenew = 0xff;
    (*ppPVar3)->colourfadefracold = 0.00000000;
    (*ppPVar3)->colourfadefracnew = 0.00000000;
    (*ppPVar3)->cuff_value = CUFF_BLUE;
    (*ppPVar3)->field_420 = 1;
    (*ppPVar3)->field_424 = 0;
    (*ppPVar3)->field_428 = 0;
    (*ppPVar3)->field_42C = 2;
    (*ppPVar3)->controlstyle = 0;
    (*ppPVar3)->field_4DC = 1;
    (*ppPVar3)->field_4E0 = 1;
    (*ppPVar3)->field_4E4 = 1;
    (*ppPVar3)->field_4E8 = 0;
    (*ppPVar3)->field_4EC = 0.93000001;
    (*ppPVar3)->field_4F0 = 0;
    (*ppPVar3)->field_4F4 = 1.00000000;
    (*ppPVar3)->field_4F8 = 1.00000000;
    (*ppPVar3)->headpos = 0.00000000;
    (*ppPVar3)->field_500 = 0.00000000;
    (*ppPVar3)->field_504 = 0.00000000;
    (*ppPVar3)->field_508 = 0.00000000;
    (*ppPVar3)->field_50C = 0.00000000;
    (*ppPVar3)->field_510 = 1.00000000;
    (*ppPVar3)->field_514 = 0.00000000;
    (*ppPVar3)->field_518 = 1.00000000;
    (*ppPVar3)->field_51C = 0.00000000;
    (*ppPVar3)->headpossum = 0.00000000;
    (*ppPVar3)->field_524 = 0.00000000;
    (*ppPVar3)->field_528 = 0.00000000;
    (*ppPVar3)->field_52C = 0.00000000;
    (*ppPVar3)->field_530 = 0.00000000;
    *(f32 *)&(*ppPVar3)->field_534 = 14.28571606;
    (*ppPVar3)->field_538 = 0;
    (*ppPVar3)->field_53C = 14.28571606;
    (*ppPVar3)->field_540 = 0.00000000;
    (*ppPVar3)->field_544 = 0.00000000;
    (*ppPVar3)->field_548 = 0.00000000;
    (*ppPVar3)->field_54C = 0.00000000;
    (*ppPVar3)->stationary_ground_offset = 0.00000000;
    (*ppPVar3)->field_554 = 0.00000000;
    (*ppPVar3)->field_558 = 0.00000000;
    (*ppPVar3)->field_55C = 0.00000000;
    (*ppPVar3)->field_560 = 0.00000000;
    (*ppPVar3)->field_564 = 0.00000000;
    (*ppPVar3)->field_568 = 0.00000000;
    (*ppPVar3)->field_56C = 1.00000000;
    (*ppPVar3)->field_570 = 0.00000000;
    (*ppPVar3)->field_574 = 0.00000000;
    (*ppPVar3)->field_578 = 1.00000000;
    (*ppPVar3)->field_57C = 0.00000000;
    (*ppPVar3)->field_580 = 1.00000000;
    (*ppPVar3)->field_584 = 0.00000000;
    (*ppPVar3)->field_588 = 0.00000000;
    (*ppPVar3)->field_58C = 1.00000000;
    (*ppPVar3)->field_590 = 0.00000000;
    (*ppPVar3)->standcnt = 0;
    iVar1 = 0;
    do {
        *(undefined2 *)((int)&((*ppPVar3)->field_7D0).field_7D0 + iVar1) = 0x280;
        *(undefined2 *)((int)&((*ppPVar3)->field_7D0).field_7D2 + iVar1) = 0x1e0;
        *(undefined2 *)((int)&((*ppPVar3)->field_7D0).field_7D4 + iVar1) = 0x1ff;
        *(undefined2 *)((int)&((*ppPVar3)->field_7D0).field_7D6 + iVar1) = 0;
        *(undefined2 *)((int)&((*ppPVar3)->field_7D0).field_7D8 + iVar1) = 0x280;
        *(undefined2 *)((int)&((*ppPVar3)->field_7D0).field_7DA + iVar1) = 0x1e0;
        *(undefined2 *)((int)&((*ppPVar3)->field_7D0).field_7DC + iVar1) = 0x1ff;
        iVar2 = iVar1 + 0x10;
        *(undefined2 *)((int)&((*ppPVar3)->field_7D0).field_7DE + iVar1) = 0;
        iVar1 = iVar2;
    } while (iVar2 != 0x20);
    (*ppPVar3)->viewx = 100;
    (*ppPVar3)->viewy = 100;
    (*ppPVar3)->viewleft = 0;
    (*ppPVar3)->viewtop = 0;
    (*ppPVar3)->hand_invisible[0] = 0;
    (*ppPVar3)->hand_invisible[1] = 0;
    (*ppPVar3)->hand_item[0] = ITEM_UNARMED;
    (*ppPVar3)->hand_item[1] = ITEM_UNARMED;
    (*ppPVar3)->field_2A44[0] = -1;
    (*ppPVar3)->field_2A44[1] = -1;
    (*ppPVar3)->lock_hand_model[0] = 0;
    (*ppPVar3)->lock_hand_model[1] = 0;
    (*ppPVar3)->ptr_hand_weapon_buffer[0] = NULL;
    (*ppPVar3)->ptr_hand_weapon_buffer[1] = NULL;
    pPVar4 = *ppPVar3;
    src = array234undefined4;
    do {
        dest = src + 3;
        pPVar4->right_weapon = *src;
        pPVar4->right_weapon_attack = src[1];
        pPVar4->previous_right_weapon = src[2];
        pPVar4 = (player *)&pPVar4->zpos;
        src = dest;
    } while (dest != &iStack4);
    src = array234undefined4;
    pPVar4 = *ppPVar3;
    do {
        dest = src + 3;
        pPVar4->left_weapon = *src;
        pPVar4->left_weapon_attack = src[1];
        pPVar4->left_weapon_previous = src[2];
        src = dest;
        pPVar4 = (player *)&pPVar4->zpos;
    } while (dest != &iStack4);
    (*ppPVar3)->field_FC0 = 1.00000000;
    (*ppPVar3)->field_FC4 = 1.00000000;
    (*ppPVar3)->field_FC8 = 0;
    (*ppPVar3)->field_FCC = 0;
    (*ppPVar3)->field_FD0 = 0;
    (*ppPVar3)->field_FD4 = 0;
    (*ppPVar3)->field_FD8 = 0;
    (*ppPVar3)->field_FDC = -1;
    (*ppPVar3)->field_FDD = -1;
    (*ppPVar3)->field_FDE = -1;
    (*ppPVar3)->field_FDF = '\0';
    (*ppPVar3)->field_FE0 = 1;
    (*ppPVar3)->field_FE4 = 0;
    (*ppPVar3)->field_FE8 = 0.00000000;
    (*ppPVar3)->field_FEC = 0.00000000;
    (*ppPVar3)->field_FF0 = 0.00000000;
    (*ppPVar3)->field_FF4 = 0.00000000;
    (*ppPVar3)->field_FF8 = 0.89999998;
    (*ppPVar3)->field_FFC = 0.00000000;
    (*ppPVar3)->field_1000 = 0.00000000;
    (*ppPVar3)->field_1004 = 0.00000000;
    (*ppPVar3)->field_1008 = 0.00000000;
    (*ppPVar3)->field_100C = 0.89999998;
    (*ppPVar3)->field_1010 = 0.00000000;
    (*ppPVar3)->holds_neg_pi = -3.14159274;
    (*ppPVar3)->field_1018 = 0.00000000;
    (*ppPVar3)->field_105C = 0;
    (*ppPVar3)->copiedgoldeneye = 0;
    (*ppPVar3)->somekinda_flags = 0;
    (*ppPVar3)->field_106C = 0.00000000;
    (*ppPVar3)->field_1070 = 0.00000000;
    (*ppPVar3)->field_1074 = 0.00000000;
    (*ppPVar3)->field_1078 = 0;
    (*ppPVar3)->field_107C = 0.00000000;
    (*ppPVar3)->field_1080 = 0.00000000;
    (*ppPVar3)->sniper_zoom = 60.00000000;
    (*ppPVar3)->camera_zoom = 60.00000000;
    (*ppPVar3)->field_108C = -1;
    (*ppPVar3)->c_screenwidth = 320.00000000;
    (*ppPVar3)->c_screenheight = 240.00000000;
    (*ppPVar3)->c_screenleft = 0.00000000;
    (*ppPVar3)->c_screentop = 0.00000000;
    (*ppPVar3)->c_perspnear = 10.00000000;
    (*ppPVar3)->c_perspfovy = 46.00000000;
    (*ppPVar3)->c_perspaspect = 1.00000000;
    (*ppPVar3)->c_halfwidth = 160.00000000;
    (*ppPVar3)->c_halfheight = 120.00000000;
    (*ppPVar3)->c_scalex = 1.00000000;
    (*ppPVar3)->c_scaley = 1.00000000;
    (*ppPVar3)->c_recipscalex = 1.00000000;
    (*ppPVar3)->c_recipscaley = 1.00000000;
    (*ppPVar3)->field_10C4 = 0;
    (*ppPVar3)->field_10C8 = 0;
    (*ppPVar3)->field_10CC = 0;
    (*ppPVar3)->field_10D0 = 0;
    (*ppPVar3)->field_10D4 = 0;
    (*ppPVar3)->projmatrix = 0;
    (*ppPVar3)->projmatrixf = 0;
    (*ppPVar3)->field_10E0 = 0;
    (*ppPVar3)->field_10E4 = 0;
    (*ppPVar3)->field_10E8 = 0;
    (*ppPVar3)->field_10EC = 0;
    (*ppPVar3)->c_scalelod60 = 1.00000000;
    (*ppPVar3)->c_scalelod = 1.00000000;
    (*ppPVar3)->c_lodscalez = 1.00000000;
    (*ppPVar3)->c_lodscalezu32 = 0x10000;
    (*ppPVar3)->screenxminf = 0.00000000;
    (*ppPVar3)->screenyminf = 0.00000000;
    (*ppPVar3)->screenxmaxf = 320.00000000;
    (*ppPVar3)->screenymaxf = 240.00000000;
    (*ppPVar3)->somekinda_bitflags = 0;
    (*ppPVar3)->field_11B0 = 0;
    (*ppPVar3)->field_11B4 = 0;
    (*ppPVar3)->field_11B8 = 0;
    (*ppPVar3)->zoomintime = 0.00000000;
    (*ppPVar3)->zoomintimemax = 0.00000000;
    (*ppPVar3)->zoominfovy = 60.00000000;
    (*ppPVar3)->zoominfovyold = 60.00000000;
    (*ppPVar3)->zoominfovynew = 60.00000000;
    (*ppPVar3)->fovy = 60.00000000;
    (*ppPVar3)->aspect = 1.33333337;
    (*ppPVar3)->hudmessoff = 0;
    (*ppPVar3)->bondmesscnt = -1;
    (*ppPVar3)->ptr_inventory_first_in_cycle = 0;
    (*ppPVar3)->p_itemcur = 0;
    (*ppPVar3)->equipmaxitems = 0;
    (*ppPVar3)->equipallguns = 0;
    (*ppPVar3)->field_11F0 = 0;
    (*ppPVar3)->field_11F4 = 0;
    (*ppPVar3)->field_1280 = 0;
    (*ppPVar3)->players_cur_animation = 0;
    (*ppPVar3)->field_1288 = 0.00000000;
    (*ppPVar3)->bondinvincible = '\0';
    (*ppPVar3)->field_29B8 = 7;
    (*ppPVar3)->field_29BC = 1.00000000;
    (*ppPVar3)->field_29C0 = 0.00000000;
    (*ppPVar3)->mpmenuon = 0;
    (*ppPVar3)->damagetype = 7;
    (*ppPVar3)->deathcount = 0;
    (*ppPVar3)->field_29E0 = random_byte;
    random_byte = random_byte + 1;
    (*ppPVar3)->field_29E4 = -1;
    (*ppPVar3)->field_29E8 = -1;
    (*ppPVar3)->field_29EC = -1;
    (*ppPVar3)->field_29F0 = -1;
    (*ppPVar3)->healthdisplaytime = 0;
    (*ppPVar3)->field_2A30 = 0;
    (*ppPVar3)->field_2A34 = 0;
    (*ppPVar3)->cur_item_weapon_getname = 1;
    (*ppPVar3)->actual_health = 1.00000000;
    (*ppPVar3)->actual_armor = 1.00000000;
    (*ppPVar3)->cur_player_control_type_0 = 0;
    (*ppPVar3)->cur_player_control_type_1 = 0;
    (*ppPVar3)->cur_player_control_type_2 = 0.00000000;
    (*ppPVar3)->neg_vspacing_for_control_type_entry = 0;
    (*ppPVar3)->has_set_control_type_data = 1;
    (*ppPVar3)->field_2A6C = 0;
    (*ppPVar3)->field_2A70 = 0;
    visible_to_guards_flag = TRUE;
    obj_collision_flag = TRUE;
}
#else
#ifdef VERSION_US
GLOBAL_ASM(
.late_rodata
glabel D_80057610
.word 0xc3652ee0 /*-229.18311*/
glabel D_80057614
.word 0x411ffffe /*9.9999981*/
glabel D_80057618
.word 0x3f6e147b /*0.93000001*/
glabel D_8005761C
.word 0x4164924b /*14.285716*/
glabel D_80057620
.word 0x3f666666 /*0.89999998*/
glabel D_80057624
.word 0xc0490fdb /*-3.1415927*/
glabel D_80057628
.word 0x3faaaaab /*1.3333334*/
.text
glabel initBONDdataforPlayer
/* 0CEFEC 7F09A4BC 27BDFC30 */  addiu $sp, $sp, -0x3d0
/* 0CEFF0 7F09A4C0 3C0F8004 */  lui   $t7, %hi(D_8003FD94+0xC) 
/* 0CEFF4 7F09A4C4 25EFFDA0 */  addiu $t7, %lo(D_8003FD94+0xC) # addiu $t7, $t7, -0x260
/* 0CEFF8 7F09A4C8 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0CEFFC 7F09A4CC AFA403D0 */  sw    $a0, 0x3d0($sp)
/* 0CF000 7F09A4D0 25EB03A8 */  addiu $t3, $t7, 0x3a8
/* 0CF004 7F09A4D4 27AE0024 */  addiu $t6, $sp, 0x24
.L7F09A4D8:
/* 0CF008 7F09A4D8 8DE10000 */  lw    $at, ($t7)
/* 0CF00C 7F09A4DC 25EF000C */  addiu $t7, $t7, 0xc
/* 0CF010 7F09A4E0 25CE000C */  addiu $t6, $t6, 0xc
/* 0CF014 7F09A4E4 ADC1FFF4 */  sw    $at, -0xc($t6)
/* 0CF018 7F09A4E8 8DE1FFF8 */  lw    $at, -8($t7)
/* 0CF01C 7F09A4EC ADC1FFF8 */  sw    $at, -8($t6)
/* 0CF020 7F09A4F0 8DE1FFFC */  lw    $at, -4($t7)
/* 0CF024 7F09A4F4 15EBFFF8 */  bne   $t7, $t3, .L7F09A4D8
/* 0CF028 7F09A4F8 ADC1FFFC */   sw    $at, -4($t6)
/* 0CF02C 7F09A4FC 24042A80 */  li    $a0, 10880
/* 0CF030 7F09A500 0C0025C8 */  jal   mempAllocBytesInBank
/* 0CF034 7F09A504 24050004 */   li    $a1, 4
/* 0CF038 7F09A508 8FAC03D0 */  lw    $t4, 0x3d0($sp)
/* 0CF03C 7F09A50C 3C198008 */  lui   $t9, %hi(players) 
/* 0CF040 7F09A510 27399EE0 */  addiu $t9, %lo(players) # addiu $t9, $t9, -0x6120
/* 0CF044 7F09A514 000C6880 */  sll   $t5, $t4, 2
/* 0CF048 7F09A518 01B91821 */  addu  $v1, $t5, $t9
/* 0CF04C 7F09A51C AC620000 */  sw    $v0, ($v1)
/* 0CF050 7F09A520 AC400000 */  sw    $zero, ($v0)
/* 0CF054 7F09A524 44800000 */  mtc1  $zero, $f0
/* 0CF058 7F09A528 8C780000 */  lw    $t8, ($v1)
/* 0CF05C 7F09A52C 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0CF060 7F09A530 44811000 */  mtc1  $at, $f2
/* 0CF064 7F09A534 E7000004 */  swc1  $f0, 4($t8)
/* 0CF068 7F09A538 8C6B0000 */  lw    $t3, ($v1)
/* 0CF06C 7F09A53C 24040002 */  li    $a0, 2
/* 0CF070 7F09A540 24080001 */  li    $t0, 1
/* 0CF074 7F09A544 E5600008 */  swc1  $f0, 8($t3)
/* 0CF078 7F09A548 8C6F0000 */  lw    $t7, ($v1)
/* 0CF07C 7F09A54C 2409FFFF */  li    $t1, -1
/* 0CF080 7F09A550 3C01C080 */  li    $at, 0xC0800000 # -4.000000
/* 0CF084 7F09A554 E5E0000C */  swc1  $f0, 0xc($t7)
/* 0CF088 7F09A558 8C6E0000 */  lw    $t6, ($v1)
/* 0CF08C 7F09A55C 44812000 */  mtc1  $at, $f4
/* 0CF090 7F09A560 3C018005 */  lui   $at, %hi(D_80057610)
/* 0CF094 7F09A564 E5C00010 */  swc1  $f0, 0x10($t6)
/* 0CF098 7F09A568 8C6C0000 */  lw    $t4, ($v1)
/* 0CF09C 7F09A56C 240200FF */  li    $v0, 255
/* 0CF0A0 7F09A570 27AA0024 */  addiu $t2, $sp, 0x24
/* 0CF0A4 7F09A574 E5800014 */  swc1  $f0, 0x14($t4)
/* 0CF0A8 7F09A578 8C6D0000 */  lw    $t5, ($v1)
/* 0CF0AC 7F09A57C E5A20018 */  swc1  $f2, 0x18($t5)
/* 0CF0B0 7F09A580 8C790000 */  lw    $t9, ($v1)
/* 0CF0B4 7F09A584 E720001C */  swc1  $f0, 0x1c($t9)
/* 0CF0B8 7F09A588 8C780000 */  lw    $t8, ($v1)
/* 0CF0BC 7F09A58C E7020020 */  swc1  $f2, 0x20($t8)
/* 0CF0C0 7F09A590 8C6B0000 */  lw    $t3, ($v1)
/* 0CF0C4 7F09A594 E5600024 */  swc1  $f0, 0x24($t3)
/* 0CF0C8 7F09A598 8C6F0000 */  lw    $t7, ($v1)
/* 0CF0CC 7F09A59C E5E00028 */  swc1  $f0, 0x28($t7)
/* 0CF0D0 7F09A5A0 8C6E0000 */  lw    $t6, ($v1)
/* 0CF0D4 7F09A5A4 E5C0002C */  swc1  $f0, 0x2c($t6)
/* 0CF0D8 7F09A5A8 8C6C0000 */  lw    $t4, ($v1)
/* 0CF0DC 7F09A5AC E5800030 */  swc1  $f0, 0x30($t4)
/* 0CF0E0 7F09A5B0 8C6D0000 */  lw    $t5, ($v1)
/* 0CF0E4 7F09A5B4 ADA00034 */  sw    $zero, 0x34($t5)
/* 0CF0E8 7F09A5B8 8C790000 */  lw    $t9, ($v1)
/* 0CF0EC 7F09A5BC E7200038 */  swc1  $f0, 0x38($t9)
/* 0CF0F0 7F09A5C0 8C780000 */  lw    $t8, ($v1)
/* 0CF0F4 7F09A5C4 E700003C */  swc1  $f0, 0x3c($t8)
/* 0CF0F8 7F09A5C8 8C6B0000 */  lw    $t3, ($v1)
/* 0CF0FC 7F09A5CC E5600040 */  swc1  $f0, 0x40($t3)
/* 0CF100 7F09A5D0 8C6F0000 */  lw    $t7, ($v1)
/* 0CF104 7F09A5D4 E5E00044 */  swc1  $f0, 0x44($t7)
/* 0CF108 7F09A5D8 8C6E0000 */  lw    $t6, ($v1)
/* 0CF10C 7F09A5DC E5C00048 */  swc1  $f0, 0x48($t6)
/* 0CF110 7F09A5E0 8C6C0000 */  lw    $t4, ($v1)
/* 0CF114 7F09A5E4 E580004C */  swc1  $f0, 0x4c($t4)
/* 0CF118 7F09A5E8 8C6D0000 */  lw    $t5, ($v1)
/* 0CF11C 7F09A5EC E5A00050 */  swc1  $f0, 0x50($t5)
/* 0CF120 7F09A5F0 8C790000 */  lw    $t9, ($v1)
/* 0CF124 7F09A5F4 E7200054 */  swc1  $f0, 0x54($t9)
/* 0CF128 7F09A5F8 8C780000 */  lw    $t8, ($v1)
/* 0CF12C 7F09A5FC E7000058 */  swc1  $f0, 0x58($t8)
/* 0CF130 7F09A600 8C6B0000 */  lw    $t3, ($v1)
/* 0CF134 7F09A604 E560006C */  swc1  $f0, 0x6c($t3)
/* 0CF138 7F09A608 8C6F0000 */  lw    $t7, ($v1)
/* 0CF13C 7F09A60C E5E00070 */  swc1  $f0, 0x70($t7)
/* 0CF140 7F09A610 8C6E0000 */  lw    $t6, ($v1)
/* 0CF144 7F09A614 E5C00074 */  swc1  $f0, 0x74($t6)
/* 0CF148 7F09A618 8C6C0000 */  lw    $t4, ($v1)
/* 0CF14C 7F09A61C E5800078 */  swc1  $f0, 0x78($t4)
/* 0CF150 7F09A620 8C6D0000 */  lw    $t5, ($v1)
/* 0CF154 7F09A624 E5A0007C */  swc1  $f0, 0x7c($t5)
/* 0CF158 7F09A628 8C790000 */  lw    $t9, ($v1)
/* 0CF15C 7F09A62C E7200080 */  swc1  $f0, 0x80($t9)
/* 0CF160 7F09A630 8C780000 */  lw    $t8, ($v1)
/* 0CF164 7F09A634 E7000084 */  swc1  $f0, 0x84($t8)
/* 0CF168 7F09A638 8C6B0000 */  lw    $t3, ($v1)
/* 0CF16C 7F09A63C E5600088 */  swc1  $f0, 0x88($t3)
/* 0CF170 7F09A640 8C6F0000 */  lw    $t7, ($v1)
/* 0CF174 7F09A644 ADE0008C */  sw    $zero, 0x8c($t7)
/* 0CF178 7F09A648 8C6E0000 */  lw    $t6, ($v1)
/* 0CF17C 7F09A64C E5C00090 */  swc1  $f0, 0x90($t6)
/* 0CF180 7F09A650 8C6C0000 */  lw    $t4, ($v1)
/* 0CF184 7F09A654 AD800094 */  sw    $zero, 0x94($t4)
/* 0CF188 7F09A658 8C6D0000 */  lw    $t5, ($v1)
/* 0CF18C 7F09A65C E5A00098 */  swc1  $f0, 0x98($t5)
/* 0CF190 7F09A660 8C790000 */  lw    $t9, ($v1)
/* 0CF194 7F09A664 E7201274 */  swc1  $f0, 0x1274($t9)
/* 0CF198 7F09A668 8C780000 */  lw    $t8, ($v1)
/* 0CF19C 7F09A66C E7001278 */  swc1  $f0, 0x1278($t8)
/* 0CF1A0 7F09A670 8C6B0000 */  lw    $t3, ($v1)
/* 0CF1A4 7F09A674 E560127C */  swc1  $f0, 0x127c($t3)
/* 0CF1A8 7F09A678 8C6F0000 */  lw    $t7, ($v1)
/* 0CF1AC 7F09A67C ADE4009C */  sw    $a0, 0x9c($t7)
/* 0CF1B0 7F09A680 8C6E0000 */  lw    $t6, ($v1)
/* 0CF1B4 7F09A684 ADC429FC */  sw    $a0, 0x29fc($t6)
/* 0CF1B8 7F09A688 8C6C0000 */  lw    $t4, ($v1)
/* 0CF1BC 7F09A68C E58000A0 */  swc1  $f0, 0xa0($t4)
/* 0CF1C0 7F09A690 8C6D0000 */  lw    $t5, ($v1)
/* 0CF1C4 7F09A694 E5A000A4 */  swc1  $f0, 0xa4($t5)
/* 0CF1C8 7F09A698 8C790000 */  lw    $t9, ($v1)
/* 0CF1CC 7F09A69C AF2000A8 */  sw    $zero, 0xa8($t9)
/* 0CF1D0 7F09A6A0 8C780000 */  lw    $t8, ($v1)
/* 0CF1D4 7F09A6A4 AF0800AC */  sw    $t0, 0xac($t8)
/* 0CF1D8 7F09A6A8 8C6B0000 */  lw    $t3, ($v1)
/* 0CF1DC 7F09A6AC AD6000D0 */  sw    $zero, 0xd0($t3)
/* 0CF1E0 7F09A6B0 8C6F0000 */  lw    $t7, ($v1)
/* 0CF1E4 7F09A6B4 ADE000D4 */  sw    $zero, 0xd4($t7)
/* 0CF1E8 7F09A6B8 8C6E0000 */  lw    $t6, ($v1)
/* 0CF1EC 7F09A6BC ADC000D8 */  sw    $zero, 0xd8($t6)
/* 0CF1F0 7F09A6C0 8C6C0000 */  lw    $t4, ($v1)
/* 0CF1F4 7F09A6C4 E58200DC */  swc1  $f2, 0xdc($t4)
/* 0CF1F8 7F09A6C8 8C6D0000 */  lw    $t5, ($v1)
/* 0CF1FC 7F09A6CC E5A000E0 */  swc1  $f0, 0xe0($t5)
/* 0CF200 7F09A6D0 8C790000 */  lw    $t9, ($v1)
/* 0CF204 7F09A6D4 E72200E4 */  swc1  $f2, 0xe4($t9)
/* 0CF208 7F09A6D8 8C780000 */  lw    $t8, ($v1)
/* 0CF20C 7F09A6DC E70000E8 */  swc1  $f0, 0xe8($t8)
/* 0CF210 7F09A6E0 8C6B0000 */  lw    $t3, ($v1)
/* 0CF214 7F09A6E4 E56200EC */  swc1  $f2, 0xec($t3)
/* 0CF218 7F09A6E8 8C6F0000 */  lw    $t7, ($v1)
/* 0CF21C 7F09A6EC E5E000F0 */  swc1  $f0, 0xf0($t7)
/* 0CF220 7F09A6F0 8C6E0000 */  lw    $t6, ($v1)
/* 0CF224 7F09A6F4 ADC900F4 */  sw    $t1, 0xf4($t6)
/* 0CF228 7F09A6F8 8C6C0000 */  lw    $t4, ($v1)
/* 0CF22C 7F09A6FC AD8900F8 */  sw    $t1, 0xf8($t4)
/* 0CF230 7F09A700 8C6D0000 */  lw    $t5, ($v1)
/* 0CF234 7F09A704 ADA00104 */  sw    $zero, 0x104($t5)
/* 0CF238 7F09A708 8C790000 */  lw    $t9, ($v1)
/* 0CF23C 7F09A70C AF200108 */  sw    $zero, 0x108($t9)
/* 0CF240 7F09A710 8C780000 */  lw    $t8, ($v1)
/* 0CF244 7F09A714 AF00010C */  sw    $zero, 0x10c($t8)
/* 0CF248 7F09A718 8C6B0000 */  lw    $t3, ($v1)
/* 0CF24C 7F09A71C AD600110 */  sw    $zero, 0x110($t3)
/* 0CF250 7F09A720 8C6F0000 */  lw    $t7, ($v1)
/* 0CF254 7F09A724 ADE80114 */  sw    $t0, 0x114($t7)
/* 0CF258 7F09A728 8C6E0000 */  lw    $t6, ($v1)
/* 0CF25C 7F09A72C ADC80118 */  sw    $t0, 0x118($t6)
/* 0CF260 7F09A730 8C6C0000 */  lw    $t4, ($v1)
/* 0CF264 7F09A734 AD80011C */  sw    $zero, 0x11c($t4)
/* 0CF268 7F09A738 8C6D0000 */  lw    $t5, ($v1)
/* 0CF26C 7F09A73C ADA80120 */  sw    $t0, 0x120($t5)
/* 0CF270 7F09A740 8C790000 */  lw    $t9, ($v1)
/* 0CF274 7F09A744 AF200124 */  sw    $zero, 0x124($t9)
/* 0CF278 7F09A748 8C780000 */  lw    $t8, ($v1)
/* 0CF27C 7F09A74C AF080128 */  sw    $t0, 0x128($t8)
/* 0CF280 7F09A750 8C6B0000 */  lw    $t3, ($v1)
/* 0CF284 7F09A754 E560012C */  swc1  $f0, 0x12c($t3)
/* 0CF288 7F09A758 8C6F0000 */  lw    $t7, ($v1)
/* 0CF28C 7F09A75C ADE00130 */  sw    $zero, 0x130($t7)
/* 0CF290 7F09A760 8C6E0000 */  lw    $t6, ($v1)
/* 0CF294 7F09A764 ADC90134 */  sw    $t1, 0x134($t6)
/* 0CF298 7F09A768 8C6C0000 */  lw    $t4, ($v1)
/* 0CF29C 7F09A76C AD880138 */  sw    $t0, 0x138($t4)
/* 0CF2A0 7F09A770 8C6D0000 */  lw    $t5, ($v1)
/* 0CF2A4 7F09A774 E5A0013C */  swc1  $f0, 0x13c($t5)
/* 0CF2A8 7F09A778 8C790000 */  lw    $t9, ($v1)
/* 0CF2AC 7F09A77C AF200140 */  sw    $zero, 0x140($t9)
/* 0CF2B0 7F09A780 8C780000 */  lw    $t8, ($v1)
/* 0CF2B4 7F09A784 AF090144 */  sw    $t1, 0x144($t8)
/* 0CF2B8 7F09A788 8C6B0000 */  lw    $t3, ($v1)
/* 0CF2BC 7F09A78C E5600148 */  swc1  $f0, 0x148($t3)
/* 0CF2C0 7F09A790 8C6F0000 */  lw    $t7, ($v1)
/* 0CF2C4 7F09A794 E5E0014C */  swc1  $f0, 0x14c($t7)
/* 0CF2C8 7F09A798 8C6E0000 */  lw    $t6, ($v1)
/* 0CF2CC 7F09A79C E5C20150 */  swc1  $f2, 0x150($t6)
/* 0CF2D0 7F09A7A0 8C6C0000 */  lw    $t4, ($v1)
/* 0CF2D4 7F09A7A4 E5800154 */  swc1  $f0, 0x154($t4)
/* 0CF2D8 7F09A7A8 8C6D0000 */  lw    $t5, ($v1)
/* 0CF2DC 7F09A7AC E5A40158 */  swc1  $f4, 0x158($t5)
/* 0CF2E0 7F09A7B0 8C790000 */  lw    $t9, ($v1)
/* 0CF2E4 7F09A7B4 C4267610 */  lwc1  $f6, %lo(D_80057610)($at)
/* 0CF2E8 7F09A7B8 3C01BF80 */  li    $at, 0xBF800000 # -1.000000
/* 0CF2EC 7F09A7BC 44816000 */  mtc1  $at, $f12
/* 0CF2F0 7F09A7C0 E726015C */  swc1  $f6, 0x15c($t9)
/* 0CF2F4 7F09A7C4 8C780000 */  lw    $t8, ($v1)
/* 0CF2F8 7F09A7C8 3C01C1C8 */  li    $at, 0xC1C80000 # -25.000000
/* 0CF2FC 7F09A7CC 44814000 */  mtc1  $at, $f8
/* 0CF300 7F09A7D0 E7000160 */  swc1  $f0, 0x160($t8)
/* 0CF304 7F09A7D4 8C6B0000 */  lw    $t3, ($v1)
/* 0CF308 7F09A7D8 3C018005 */  lui   $at, %hi(D_80057614)
/* 0CF30C 7F09A7DC E5620164 */  swc1  $f2, 0x164($t3)
/* 0CF310 7F09A7E0 8C6F0000 */  lw    $t7, ($v1)
/* 0CF314 7F09A7E4 E5E00168 */  swc1  $f0, 0x168($t7)
/* 0CF318 7F09A7E8 8C6E0000 */  lw    $t6, ($v1)
/* 0CF31C 7F09A7EC E5C0016C */  swc1  $f0, 0x16c($t6)
/* 0CF320 7F09A7F0 8C6C0000 */  lw    $t4, ($v1)
/* 0CF324 7F09A7F4 E5800170 */  swc1  $f0, 0x170($t4)
/* 0CF328 7F09A7F8 8C6D0000 */  lw    $t5, ($v1)
/* 0CF32C 7F09A7FC E5A00174 */  swc1  $f0, 0x174($t5)
/* 0CF330 7F09A800 8C790000 */  lw    $t9, ($v1)
/* 0CF334 7F09A804 E7202A4C */  swc1  $f0, 0x2a4c($t9)
/* 0CF338 7F09A808 8C780000 */  lw    $t8, ($v1)
/* 0CF33C 7F09A80C E7020178 */  swc1  $f2, 0x178($t8)
/* 0CF340 7F09A810 8C6B0000 */  lw    $t3, ($v1)
/* 0CF344 7F09A814 E5600180 */  swc1  $f0, 0x180($t3)
/* 0CF348 7F09A818 8C6F0000 */  lw    $t7, ($v1)
/* 0CF34C 7F09A81C E5E00184 */  swc1  $f0, 0x184($t7)
/* 0CF350 7F09A820 8C6E0000 */  lw    $t6, ($v1)
/* 0CF354 7F09A824 E5C00188 */  swc1  $f0, 0x188($t6)
/* 0CF358 7F09A828 8C6C0000 */  lw    $t4, ($v1)
/* 0CF35C 7F09A82C E58C018C */  swc1  $f12, 0x18c($t4)
/* 0CF360 7F09A830 8C6D0000 */  lw    $t5, ($v1)
/* 0CF364 7F09A834 E5AC0190 */  swc1  $f12, 0x190($t5)
/* 0CF368 7F09A838 8C790000 */  lw    $t9, ($v1)
/* 0CF36C 7F09A83C E7200194 */  swc1  $f0, 0x194($t9)
/* 0CF370 7F09A840 8C780000 */  lw    $t8, ($v1)
/* 0CF374 7F09A844 E7000198 */  swc1  $f0, 0x198($t8)
/* 0CF378 7F09A848 8C6B0000 */  lw    $t3, ($v1)
/* 0CF37C 7F09A84C E560019C */  swc1  $f0, 0x19c($t3)
/* 0CF380 7F09A850 8C6F0000 */  lw    $t7, ($v1)
/* 0CF384 7F09A854 ADE001A0 */  sw    $zero, 0x1a0($t7)
/* 0CF388 7F09A858 8C6E0000 */  lw    $t6, ($v1)
/* 0CF38C 7F09A85C ADC001C0 */  sw    $zero, 0x1c0($t6)
/* 0CF390 7F09A860 8C6C0000 */  lw    $t4, ($v1)
/* 0CF394 7F09A864 AD8001C4 */  sw    $zero, 0x1c4($t4)
/* 0CF398 7F09A868 8C6D0000 */  lw    $t5, ($v1)
/* 0CF39C 7F09A86C ADA001C8 */  sw    $zero, 0x1c8($t5)
/* 0CF3A0 7F09A870 8C790000 */  lw    $t9, ($v1)
/* 0CF3A4 7F09A874 AF2801CC */  sw    $t0, 0x1cc($t9)
/* 0CF3A8 7F09A878 8C780000 */  lw    $t8, ($v1)
/* 0CF3AC 7F09A87C AF0001D0 */  sw    $zero, 0x1d0($t8)
/* 0CF3B0 7F09A880 8C6B0000 */  lw    $t3, ($v1)
/* 0CF3B4 7F09A884 E56001D4 */  swc1  $f0, 0x1d4($t3)
/* 0CF3B8 7F09A888 8C6F0000 */  lw    $t7, ($v1)
/* 0CF3BC 7F09A88C E5E001D8 */  swc1  $f0, 0x1d8($t7)
/* 0CF3C0 7F09A890 8C6E0000 */  lw    $t6, ($v1)
/* 0CF3C4 7F09A894 E5C801DC */  swc1  $f8, 0x1dc($t6)
/* 0CF3C8 7F09A898 8C6C0000 */  lw    $t4, ($v1)
/* 0CF3CC 7F09A89C E58001E0 */  swc1  $f0, 0x1e0($t4)
/* 0CF3D0 7F09A8A0 8C6D0000 */  lw    $t5, ($v1)
/* 0CF3D4 7F09A8A4 E5A201E4 */  swc1  $f2, 0x1e4($t5)
/* 0CF3D8 7F09A8A8 8C790000 */  lw    $t9, ($v1)
/* 0CF3DC 7F09A8AC E72001E8 */  swc1  $f0, 0x1e8($t9)
/* 0CF3E0 7F09A8B0 8C780000 */  lw    $t8, ($v1)
/* 0CF3E4 7F09A8B4 E70001EC */  swc1  $f0, 0x1ec($t8)
/* 0CF3E8 7F09A8B8 8C6B0000 */  lw    $t3, ($v1)
/* 0CF3EC 7F09A8BC E56001F0 */  swc1  $f0, 0x1f0($t3)
/* 0CF3F0 7F09A8C0 8C6F0000 */  lw    $t7, ($v1)
/* 0CF3F4 7F09A8C4 E5E201F4 */  swc1  $f2, 0x1f4($t7)
/* 0CF3F8 7F09A8C8 8C6E0000 */  lw    $t6, ($v1)
/* 0CF3FC 7F09A8CC ADC00200 */  sw    $zero, 0x200($t6)
/* 0CF400 7F09A8D0 8C6C0000 */  lw    $t4, ($v1)
/* 0CF404 7F09A8D4 E5800204 */  swc1  $f0, 0x204($t4)
/* 0CF408 7F09A8D8 8C6D0000 */  lw    $t5, ($v1)
/* 0CF40C 7F09A8DC E5A00208 */  swc1  $f0, 0x208($t5)
/* 0CF410 7F09A8E0 8C790000 */  lw    $t9, ($v1)
/* 0CF414 7F09A8E4 E720020C */  swc1  $f0, 0x20c($t9)
/* 0CF418 7F09A8E8 8C780000 */  lw    $t8, ($v1)
/* 0CF41C 7F09A8EC E7000210 */  swc1  $f0, 0x210($t8)
/* 0CF420 7F09A8F0 8C6B0000 */  lw    $t3, ($v1)
/* 0CF424 7F09A8F4 E5600214 */  swc1  $f0, 0x214($t3)
/* 0CF428 7F09A8F8 8C6F0000 */  lw    $t7, ($v1)
/* 0CF42C 7F09A8FC ADE00218 */  sw    $zero, 0x218($t7)
/* 0CF430 7F09A900 8C6E0000 */  lw    $t6, ($v1)
/* 0CF434 7F09A904 ADC8021C */  sw    $t0, 0x21c($t6)
/* 0CF438 7F09A908 8C6C0000 */  lw    $t4, ($v1)
/* 0CF43C 7F09A90C AD800220 */  sw    $zero, 0x220($t4)
/* 0CF440 7F09A910 8C6D0000 */  lw    $t5, ($v1)
/* 0CF444 7F09A914 E5A00224 */  swc1  $f0, 0x224($t5)
/* 0CF448 7F09A918 8C790000 */  lw    $t9, ($v1)
/* 0CF44C 7F09A91C A72003B4 */  sh    $zero, 0x3b4($t9)
/* 0CF450 7F09A920 8C780000 */  lw    $t8, ($v1)
/* 0CF454 7F09A924 A70003B6 */  sh    $zero, 0x3b6($t8)
/* 0CF458 7F09A928 8C6B0000 */  lw    $t3, ($v1)
/* 0CF45C 7F09A92C E56003B8 */  swc1  $f0, 0x3b8($t3)
/* 0CF460 7F09A930 8C6F0000 */  lw    $t7, ($v1)
/* 0CF464 7F09A934 E5E003BC */  swc1  $f0, 0x3bc($t7)
/* 0CF468 7F09A938 8C6E0000 */  lw    $t6, ($v1)
/* 0CF46C 7F09A93C C42A7614 */  lwc1  $f10, %lo(D_80057614)($at)
/* 0CF470 7F09A940 E5CA03C0 */  swc1  $f10, 0x3c0($t6)
/* 0CF474 7F09A944 8C6C0000 */  lw    $t4, ($v1)
/* 0CF478 7F09A948 E58003C4 */  swc1  $f0, 0x3c4($t4)
/* 0CF47C 7F09A94C 8C6D0000 */  lw    $t5, ($v1)
/* 0CF480 7F09A950 E5A003C8 */  swc1  $f0, 0x3c8($t5)
/* 0CF484 7F09A954 8C790000 */  lw    $t9, ($v1)
/* 0CF488 7F09A958 E72203CC */  swc1  $f2, 0x3cc($t9)
/* 0CF48C 7F09A95C 8C780000 */  lw    $t8, ($v1)
/* 0CF490 7F09A960 AF0203D0 */  sw    $v0, 0x3d0($t8)
/* 0CF494 7F09A964 8C6B0000 */  lw    $t3, ($v1)
/* 0CF498 7F09A968 AD6203D4 */  sw    $v0, 0x3d4($t3)
/* 0CF49C 7F09A96C 8C6F0000 */  lw    $t7, ($v1)
/* 0CF4A0 7F09A970 3C018005 */  lui   $at, %hi(D_80057618)
/* 0CF4A4 7F09A974 24070020 */  li    $a3, 32
/* 0CF4A8 7F09A978 ADE203D8 */  sw    $v0, 0x3d8($t7)
/* 0CF4AC 7F09A97C 8C6E0000 */  lw    $t6, ($v1)
/* 0CF4B0 7F09A980 240601FF */  li    $a2, 511
/* 0CF4B4 7F09A984 240501E0 */  li    $a1, 480
/* 0CF4B8 7F09A988 E5C003DC */  swc1  $f0, 0x3dc($t6)
/* 0CF4BC 7F09A98C 8C6C0000 */  lw    $t4, ($v1)
/* 0CF4C0 7F09A990 E58C03E0 */  swc1  $f12, 0x3e0($t4)
/* 0CF4C4 7F09A994 8C6D0000 */  lw    $t5, ($v1)
/* 0CF4C8 7F09A998 E5AC03E4 */  swc1  $f12, 0x3e4($t5)
/* 0CF4CC 7F09A99C 8C790000 */  lw    $t9, ($v1)
/* 0CF4D0 7F09A9A0 AF2203E8 */  sw    $v0, 0x3e8($t9)
/* 0CF4D4 7F09A9A4 8C780000 */  lw    $t8, ($v1)
/* 0CF4D8 7F09A9A8 AF0203EC */  sw    $v0, 0x3ec($t8)
/* 0CF4DC 7F09A9AC 8C6B0000 */  lw    $t3, ($v1)
/* 0CF4E0 7F09A9B0 AD6203F0 */  sw    $v0, 0x3f0($t3)
/* 0CF4E4 7F09A9B4 8C6F0000 */  lw    $t7, ($v1)
/* 0CF4E8 7F09A9B8 ADE203F4 */  sw    $v0, 0x3f4($t7)
/* 0CF4EC 7F09A9BC 8C6E0000 */  lw    $t6, ($v1)
/* 0CF4F0 7F09A9C0 ADC203F8 */  sw    $v0, 0x3f8($t6)
/* 0CF4F4 7F09A9C4 8C6C0000 */  lw    $t4, ($v1)
/* 0CF4F8 7F09A9C8 AD8203FC */  sw    $v0, 0x3fc($t4)
/* 0CF4FC 7F09A9CC 8C6D0000 */  lw    $t5, ($v1)
/* 0CF500 7F09A9D0 00001025 */  move  $v0, $zero
/* 0CF504 7F09A9D4 E5A00400 */  swc1  $f0, 0x400($t5)
/* 0CF508 7F09A9D8 8C790000 */  lw    $t9, ($v1)
/* 0CF50C 7F09A9DC E7200404 */  swc1  $f0, 0x404($t9)
/* 0CF510 7F09A9E0 8C780000 */  lw    $t8, ($v1)
/* 0CF514 7F09A9E4 AF00041C */  sw    $zero, 0x41c($t8)
/* 0CF518 7F09A9E8 8C6B0000 */  lw    $t3, ($v1)
/* 0CF51C 7F09A9EC AD680420 */  sw    $t0, 0x420($t3)
/* 0CF520 7F09A9F0 8C6F0000 */  lw    $t7, ($v1)
/* 0CF524 7F09A9F4 ADE00424 */  sw    $zero, 0x424($t7)
/* 0CF528 7F09A9F8 8C6E0000 */  lw    $t6, ($v1)
/* 0CF52C 7F09A9FC ADC00428 */  sw    $zero, 0x428($t6)
/* 0CF530 7F09AA00 8C6C0000 */  lw    $t4, ($v1)
/* 0CF534 7F09AA04 AD84042C */  sw    $a0, 0x42c($t4)
/* 0CF538 7F09AA08 8C6D0000 */  lw    $t5, ($v1)
/* 0CF53C 7F09AA0C 24040280 */  li    $a0, 640
/* 0CF540 7F09AA10 ADA00430 */  sw    $zero, 0x430($t5)
/* 0CF544 7F09AA14 8C790000 */  lw    $t9, ($v1)
/* 0CF548 7F09AA18 AF2804DC */  sw    $t0, 0x4dc($t9)
/* 0CF54C 7F09AA1C 8C780000 */  lw    $t8, ($v1)
/* 0CF550 7F09AA20 AF0804E0 */  sw    $t0, 0x4e0($t8)
/* 0CF554 7F09AA24 8C6B0000 */  lw    $t3, ($v1)
/* 0CF558 7F09AA28 AD6804E4 */  sw    $t0, 0x4e4($t3)
/* 0CF55C 7F09AA2C 8C6F0000 */  lw    $t7, ($v1)
/* 0CF560 7F09AA30 ADE004E8 */  sw    $zero, 0x4e8($t7)
/* 0CF564 7F09AA34 8C6E0000 */  lw    $t6, ($v1)
/* 0CF568 7F09AA38 C4327618 */  lwc1  $f18, %lo(D_80057618)($at)
/* 0CF56C 7F09AA3C 3C018005 */  lui   $at, %hi(D_8005761C)
/* 0CF570 7F09AA40 E5D204EC */  swc1  $f18, 0x4ec($t6)
/* 0CF574 7F09AA44 8C6C0000 */  lw    $t4, ($v1)
/* 0CF578 7F09AA48 AD8004F0 */  sw    $zero, 0x4f0($t4)
/* 0CF57C 7F09AA4C 8C6D0000 */  lw    $t5, ($v1)
/* 0CF580 7F09AA50 E5A204F4 */  swc1  $f2, 0x4f4($t5)
/* 0CF584 7F09AA54 8C790000 */  lw    $t9, ($v1)
/* 0CF588 7F09AA58 E72204F8 */  swc1  $f2, 0x4f8($t9)
/* 0CF58C 7F09AA5C 8C780000 */  lw    $t8, ($v1)
/* 0CF590 7F09AA60 E70004FC */  swc1  $f0, 0x4fc($t8)
/* 0CF594 7F09AA64 8C6B0000 */  lw    $t3, ($v1)
/* 0CF598 7F09AA68 E5600500 */  swc1  $f0, 0x500($t3)
/* 0CF59C 7F09AA6C 8C6F0000 */  lw    $t7, ($v1)
/* 0CF5A0 7F09AA70 E5E00504 */  swc1  $f0, 0x504($t7)
/* 0CF5A4 7F09AA74 8C6E0000 */  lw    $t6, ($v1)
/* 0CF5A8 7F09AA78 C42C761C */  lwc1  $f12, %lo(D_8005761C)($at)
/* 0CF5AC 7F09AA7C E5C00508 */  swc1  $f0, 0x508($t6)
/* 0CF5B0 7F09AA80 8C6C0000 */  lw    $t4, ($v1)
/* 0CF5B4 7F09AA84 E580050C */  swc1  $f0, 0x50c($t4)
/* 0CF5B8 7F09AA88 8C6D0000 */  lw    $t5, ($v1)
/* 0CF5BC 7F09AA8C E5A20510 */  swc1  $f2, 0x510($t5)
/* 0CF5C0 7F09AA90 8C790000 */  lw    $t9, ($v1)
/* 0CF5C4 7F09AA94 E7200514 */  swc1  $f0, 0x514($t9)
/* 0CF5C8 7F09AA98 8C780000 */  lw    $t8, ($v1)
/* 0CF5CC 7F09AA9C E7020518 */  swc1  $f2, 0x518($t8)
/* 0CF5D0 7F09AAA0 8C6B0000 */  lw    $t3, ($v1)
/* 0CF5D4 7F09AAA4 E560051C */  swc1  $f0, 0x51c($t3)
/* 0CF5D8 7F09AAA8 8C6F0000 */  lw    $t7, ($v1)
/* 0CF5DC 7F09AAAC E5E00520 */  swc1  $f0, 0x520($t7)
/* 0CF5E0 7F09AAB0 8C6E0000 */  lw    $t6, ($v1)
/* 0CF5E4 7F09AAB4 E5C00524 */  swc1  $f0, 0x524($t6)
/* 0CF5E8 7F09AAB8 8C6C0000 */  lw    $t4, ($v1)
/* 0CF5EC 7F09AABC E5800528 */  swc1  $f0, 0x528($t4)
/* 0CF5F0 7F09AAC0 8C6D0000 */  lw    $t5, ($v1)
/* 0CF5F4 7F09AAC4 E5A0052C */  swc1  $f0, 0x52c($t5)
/* 0CF5F8 7F09AAC8 8C790000 */  lw    $t9, ($v1)
/* 0CF5FC 7F09AACC E7200530 */  swc1  $f0, 0x530($t9)
/* 0CF600 7F09AAD0 8C780000 */  lw    $t8, ($v1)
/* 0CF604 7F09AAD4 E70C0534 */  swc1  $f12, 0x534($t8)
/* 0CF608 7F09AAD8 8C6B0000 */  lw    $t3, ($v1)
/* 0CF60C 7F09AADC E5600538 */  swc1  $f0, 0x538($t3)
/* 0CF610 7F09AAE0 8C6F0000 */  lw    $t7, ($v1)
/* 0CF614 7F09AAE4 E5EC053C */  swc1  $f12, 0x53c($t7)
/* 0CF618 7F09AAE8 8C6E0000 */  lw    $t6, ($v1)
/* 0CF61C 7F09AAEC E5C00540 */  swc1  $f0, 0x540($t6)
/* 0CF620 7F09AAF0 8C6C0000 */  lw    $t4, ($v1)
/* 0CF624 7F09AAF4 E5800544 */  swc1  $f0, 0x544($t4)
/* 0CF628 7F09AAF8 8C6D0000 */  lw    $t5, ($v1)
/* 0CF62C 7F09AAFC E5A00548 */  swc1  $f0, 0x548($t5)
/* 0CF630 7F09AB00 8C790000 */  lw    $t9, ($v1)
/* 0CF634 7F09AB04 E720054C */  swc1  $f0, 0x54c($t9)
/* 0CF638 7F09AB08 8C780000 */  lw    $t8, ($v1)
/* 0CF63C 7F09AB0C E7000550 */  swc1  $f0, 0x550($t8)
/* 0CF640 7F09AB10 8C6B0000 */  lw    $t3, ($v1)
/* 0CF644 7F09AB14 E5600554 */  swc1  $f0, 0x554($t3)
/* 0CF648 7F09AB18 8C6F0000 */  lw    $t7, ($v1)
/* 0CF64C 7F09AB1C E5E00558 */  swc1  $f0, 0x558($t7)
/* 0CF650 7F09AB20 8C6E0000 */  lw    $t6, ($v1)
/* 0CF654 7F09AB24 E5C0055C */  swc1  $f0, 0x55c($t6)
/* 0CF658 7F09AB28 8C6C0000 */  lw    $t4, ($v1)
/* 0CF65C 7F09AB2C E5800560 */  swc1  $f0, 0x560($t4)
/* 0CF660 7F09AB30 8C6D0000 */  lw    $t5, ($v1)
/* 0CF664 7F09AB34 E5A00564 */  swc1  $f0, 0x564($t5)
/* 0CF668 7F09AB38 8C790000 */  lw    $t9, ($v1)
/* 0CF66C 7F09AB3C E7200568 */  swc1  $f0, 0x568($t9)
/* 0CF670 7F09AB40 8C780000 */  lw    $t8, ($v1)
/* 0CF674 7F09AB44 E702056C */  swc1  $f2, 0x56c($t8)
/* 0CF678 7F09AB48 8C6B0000 */  lw    $t3, ($v1)
/* 0CF67C 7F09AB4C E5600570 */  swc1  $f0, 0x570($t3)
/* 0CF680 7F09AB50 8C6F0000 */  lw    $t7, ($v1)
/* 0CF684 7F09AB54 E5E00574 */  swc1  $f0, 0x574($t7)
/* 0CF688 7F09AB58 8C6E0000 */  lw    $t6, ($v1)
/* 0CF68C 7F09AB5C E5C20578 */  swc1  $f2, 0x578($t6)
/* 0CF690 7F09AB60 8C6C0000 */  lw    $t4, ($v1)
/* 0CF694 7F09AB64 E580057C */  swc1  $f0, 0x57c($t4)
/* 0CF698 7F09AB68 8C6D0000 */  lw    $t5, ($v1)
/* 0CF69C 7F09AB6C E5A20580 */  swc1  $f2, 0x580($t5)
/* 0CF6A0 7F09AB70 8C790000 */  lw    $t9, ($v1)
/* 0CF6A4 7F09AB74 E7200584 */  swc1  $f0, 0x584($t9)
/* 0CF6A8 7F09AB78 8C780000 */  lw    $t8, ($v1)
/* 0CF6AC 7F09AB7C E7000588 */  swc1  $f0, 0x588($t8)
/* 0CF6B0 7F09AB80 8C6B0000 */  lw    $t3, ($v1)
/* 0CF6B4 7F09AB84 E562058C */  swc1  $f2, 0x58c($t3)
/* 0CF6B8 7F09AB88 8C6F0000 */  lw    $t7, ($v1)
/* 0CF6BC 7F09AB8C E5E00590 */  swc1  $f0, 0x590($t7)
/* 0CF6C0 7F09AB90 8C6E0000 */  lw    $t6, ($v1)
/* 0CF6C4 7F09AB94 ADC00594 */  sw    $zero, 0x594($t6)
.L7F09AB98:
/* 0CF6C8 7F09AB98 8C6C0000 */  lw    $t4, ($v1)
/* 0CF6CC 7F09AB9C 01826821 */  addu  $t5, $t4, $v0
/* 0CF6D0 7F09ABA0 A5A407D0 */  sh    $a0, 0x7d0($t5)
/* 0CF6D4 7F09ABA4 8C790000 */  lw    $t9, ($v1)
/* 0CF6D8 7F09ABA8 0322C021 */  addu  $t8, $t9, $v0
/* 0CF6DC 7F09ABAC A70507D2 */  sh    $a1, 0x7d2($t8)
/* 0CF6E0 7F09ABB0 8C6B0000 */  lw    $t3, ($v1)
/* 0CF6E4 7F09ABB4 01627821 */  addu  $t7, $t3, $v0
/* 0CF6E8 7F09ABB8 A5E607D4 */  sh    $a2, 0x7d4($t7)
/* 0CF6EC 7F09ABBC 8C6E0000 */  lw    $t6, ($v1)
/* 0CF6F0 7F09ABC0 01C26021 */  addu  $t4, $t6, $v0
/* 0CF6F4 7F09ABC4 A58007D6 */  sh    $zero, 0x7d6($t4)
/* 0CF6F8 7F09ABC8 8C6D0000 */  lw    $t5, ($v1)
/* 0CF6FC 7F09ABCC 01A2C821 */  addu  $t9, $t5, $v0
/* 0CF700 7F09ABD0 A72407D8 */  sh    $a0, 0x7d8($t9)
/* 0CF704 7F09ABD4 8C780000 */  lw    $t8, ($v1)
/* 0CF708 7F09ABD8 03025821 */  addu  $t3, $t8, $v0
/* 0CF70C 7F09ABDC A56507DA */  sh    $a1, 0x7da($t3)
/* 0CF710 7F09ABE0 8C6F0000 */  lw    $t7, ($v1)
/* 0CF714 7F09ABE4 01E27021 */  addu  $t6, $t7, $v0
/* 0CF718 7F09ABE8 A5C607DC */  sh    $a2, 0x7dc($t6)
/* 0CF71C 7F09ABEC 8C6C0000 */  lw    $t4, ($v1)
/* 0CF720 7F09ABF0 01826821 */  addu  $t5, $t4, $v0
/* 0CF724 7F09ABF4 24420010 */  addiu $v0, $v0, 0x10
/* 0CF728 7F09ABF8 1447FFE7 */  bne   $v0, $a3, .L7F09AB98
/* 0CF72C 7F09ABFC A5A007DE */   sh    $zero, 0x7de($t5)
/* 0CF730 7F09AC00 8C790000 */  lw    $t9, ($v1)
/* 0CF734 7F09AC04 24020064 */  li    $v0, 100
/* 0CF738 7F09AC08 A72207F0 */  sh    $v0, 0x7f0($t9)
/* 0CF73C 7F09AC0C 8C780000 */  lw    $t8, ($v1)
/* 0CF740 7F09AC10 A70207F2 */  sh    $v0, 0x7f2($t8)
/* 0CF744 7F09AC14 8C6B0000 */  lw    $t3, ($v1)
/* 0CF748 7F09AC18 A56007F4 */  sh    $zero, 0x7f4($t3)
/* 0CF74C 7F09AC1C 8C6F0000 */  lw    $t7, ($v1)
/* 0CF750 7F09AC20 A5E007F6 */  sh    $zero, 0x7f6($t7)
/* 0CF754 7F09AC24 8C6E0000 */  lw    $t6, ($v1)
/* 0CF758 7F09AC28 ADC007F8 */  sw    $zero, 0x7f8($t6)
/* 0CF75C 7F09AC2C 8C6C0000 */  lw    $t4, ($v1)
/* 0CF760 7F09AC30 AD8007FC */  sw    $zero, 0x7fc($t4)
/* 0CF764 7F09AC34 8C6D0000 */  lw    $t5, ($v1)
/* 0CF768 7F09AC38 ADA00800 */  sw    $zero, 0x800($t5)
/* 0CF76C 7F09AC3C 8C790000 */  lw    $t9, ($v1)
/* 0CF770 7F09AC40 AF200804 */  sw    $zero, 0x804($t9)
/* 0CF774 7F09AC44 8C780000 */  lw    $t8, ($v1)
/* 0CF778 7F09AC48 AF092A44 */  sw    $t1, 0x2a44($t8)
/* 0CF77C 7F09AC4C 8C6B0000 */  lw    $t3, ($v1)
/* 0CF780 7F09AC50 0140C025 */  move  $t8, $t2
/* 0CF784 7F09AC54 AD692A48 */  sw    $t1, 0x2a48($t3)
/* 0CF788 7F09AC58 8C6F0000 */  lw    $t7, ($v1)
/* 0CF78C 7F09AC5C 254B03A8 */  addiu $t3, $t2, 0x3a8
/* 0CF790 7F09AC60 ADE02A50 */  sw    $zero, 0x2a50($t7)
/* 0CF794 7F09AC64 8C6E0000 */  lw    $t6, ($v1)
/* 0CF798 7F09AC68 01407825 */  move  $t7, $t2
/* 0CF79C 7F09AC6C ADC02A54 */  sw    $zero, 0x2a54($t6)
/* 0CF7A0 7F09AC70 8C6C0000 */  lw    $t4, ($v1)
/* 0CF7A4 7F09AC74 AD800808 */  sw    $zero, 0x808($t4)
/* 0CF7A8 7F09AC78 8C6D0000 */  lw    $t5, ($v1)
/* 0CF7AC 7F09AC7C ADA0080C */  sw    $zero, 0x80c($t5)
/* 0CF7B0 7F09AC80 8C790000 */  lw    $t9, ($v1)
.L7F09AC84:
/* 0CF7B4 7F09AC84 8DE10000 */  lw    $at, ($t7)
/* 0CF7B8 7F09AC88 25EF000C */  addiu $t7, $t7, 0xc
/* 0CF7BC 7F09AC8C 2739000C */  addiu $t9, $t9, 0xc
/* 0CF7C0 7F09AC90 AF210864 */  sw    $at, 0x864($t9)
/* 0CF7C4 7F09AC94 8DE1FFF8 */  lw    $at, -8($t7)
/* 0CF7C8 7F09AC98 AF210868 */  sw    $at, 0x868($t9)
/* 0CF7CC 7F09AC9C 8DE1FFFC */  lw    $at, -4($t7)
/* 0CF7D0 7F09ACA0 15EBFFF8 */  bne   $t7, $t3, .L7F09AC84
/* 0CF7D4 7F09ACA4 AF21086C */   sw    $at, 0x86c($t9)
/* 0CF7D8 7F09ACA8 8C6E0000 */  lw    $t6, ($v1)
/* 0CF7DC 7F09ACAC 254D03A8 */  addiu $t5, $t2, 0x3a8
.L7F09ACB0:
/* 0CF7E0 7F09ACB0 8F010000 */  lw    $at, ($t8)
/* 0CF7E4 7F09ACB4 2718000C */  addiu $t8, $t8, 0xc
/* 0CF7E8 7F09ACB8 25CE000C */  addiu $t6, $t6, 0xc
/* 0CF7EC 7F09ACBC ADC10C0C */  sw    $at, 0xc0c($t6)
/* 0CF7F0 7F09ACC0 8F01FFF8 */  lw    $at, -8($t8)
/* 0CF7F4 7F09ACC4 ADC10C10 */  sw    $at, 0xc10($t6)
/* 0CF7F8 7F09ACC8 8F01FFFC */  lw    $at, -4($t8)
/* 0CF7FC 7F09ACCC 170DFFF8 */  bne   $t8, $t5, .L7F09ACB0
/* 0CF800 7F09ACD0 ADC10C14 */   sw    $at, 0xc14($t6)
/* 0CF804 7F09ACD4 8C6B0000 */  lw    $t3, ($v1)
/* 0CF808 7F09ACD8 3C018005 */  lui   $at, %hi(D_80057620)
/* 0CF80C 7F09ACDC 240200FF */  li    $v0, 255
/* 0CF810 7F09ACE0 E5620FC0 */  swc1  $f2, 0xfc0($t3)
/* 0CF814 7F09ACE4 8C6F0000 */  lw    $t7, ($v1)
/* 0CF818 7F09ACE8 24040007 */  li    $a0, 7
/* 0CF81C 7F09ACEC E5E20FC4 */  swc1  $f2, 0xfc4($t7)
/* 0CF820 7F09ACF0 8C790000 */  lw    $t9, ($v1)
/* 0CF824 7F09ACF4 AF200FC8 */  sw    $zero, 0xfc8($t9)
/* 0CF828 7F09ACF8 8C6C0000 */  lw    $t4, ($v1)
/* 0CF82C 7F09ACFC AD800FCC */  sw    $zero, 0xfcc($t4)
/* 0CF830 7F09AD00 8C6D0000 */  lw    $t5, ($v1)
/* 0CF834 7F09AD04 C42C7620 */  lwc1  $f12, %lo(D_80057620)($at)
/* 0CF838 7F09AD08 3C014270 */  li    $at, 0x42700000 # 60.000000
/* 0CF83C 7F09AD0C ADA00FD0 */  sw    $zero, 0xfd0($t5)
/* 0CF840 7F09AD10 8C780000 */  lw    $t8, ($v1)
/* 0CF844 7F09AD14 AF000FD4 */  sw    $zero, 0xfd4($t8)
/* 0CF848 7F09AD18 8C6E0000 */  lw    $t6, ($v1)
/* 0CF84C 7F09AD1C ADC00FD8 */  sw    $zero, 0xfd8($t6)
/* 0CF850 7F09AD20 8C6B0000 */  lw    $t3, ($v1)
/* 0CF854 7F09AD24 A1620FDC */  sb    $v0, 0xfdc($t3)
/* 0CF858 7F09AD28 8C6F0000 */  lw    $t7, ($v1)
/* 0CF85C 7F09AD2C A1E20FDD */  sb    $v0, 0xfdd($t7)
/* 0CF860 7F09AD30 8C790000 */  lw    $t9, ($v1)
/* 0CF864 7F09AD34 A3220FDE */  sb    $v0, 0xfde($t9)
/* 0CF868 7F09AD38 8C6C0000 */  lw    $t4, ($v1)
/* 0CF86C 7F09AD3C 3C028008 */  lui   $v0, %hi(random_byte)
/* 0CF870 7F09AD40 2442A0BC */  addiu $v0, %lo(random_byte) # addiu $v0, $v0, -0x5f44
/* 0CF874 7F09AD44 A1800FDF */  sb    $zero, 0xfdf($t4)
/* 0CF878 7F09AD48 8C6D0000 */  lw    $t5, ($v1)
/* 0CF87C 7F09AD4C ADA80FE0 */  sw    $t0, 0xfe0($t5)
/* 0CF880 7F09AD50 8C780000 */  lw    $t8, ($v1)
/* 0CF884 7F09AD54 AF000FE4 */  sw    $zero, 0xfe4($t8)
/* 0CF888 7F09AD58 8C6E0000 */  lw    $t6, ($v1)
/* 0CF88C 7F09AD5C E5C00FE8 */  swc1  $f0, 0xfe8($t6)
/* 0CF890 7F09AD60 8C6B0000 */  lw    $t3, ($v1)
/* 0CF894 7F09AD64 E5600FEC */  swc1  $f0, 0xfec($t3)
/* 0CF898 7F09AD68 8C6F0000 */  lw    $t7, ($v1)
/* 0CF89C 7F09AD6C E5E00FF0 */  swc1  $f0, 0xff0($t7)
/* 0CF8A0 7F09AD70 8C790000 */  lw    $t9, ($v1)
/* 0CF8A4 7F09AD74 E7200FF4 */  swc1  $f0, 0xff4($t9)
/* 0CF8A8 7F09AD78 8C6C0000 */  lw    $t4, ($v1)
/* 0CF8AC 7F09AD7C E58C0FF8 */  swc1  $f12, 0xff8($t4)
/* 0CF8B0 7F09AD80 8C6D0000 */  lw    $t5, ($v1)
/* 0CF8B4 7F09AD84 E5A00FFC */  swc1  $f0, 0xffc($t5)
/* 0CF8B8 7F09AD88 8C780000 */  lw    $t8, ($v1)
/* 0CF8BC 7F09AD8C E7001000 */  swc1  $f0, 0x1000($t8)
/* 0CF8C0 7F09AD90 8C6E0000 */  lw    $t6, ($v1)
/* 0CF8C4 7F09AD94 E5C01004 */  swc1  $f0, 0x1004($t6)
/* 0CF8C8 7F09AD98 8C6B0000 */  lw    $t3, ($v1)
/* 0CF8CC 7F09AD9C E5601008 */  swc1  $f0, 0x1008($t3)
/* 0CF8D0 7F09ADA0 8C6F0000 */  lw    $t7, ($v1)
/* 0CF8D4 7F09ADA4 E5EC100C */  swc1  $f12, 0x100c($t7)
/* 0CF8D8 7F09ADA8 44816000 */  mtc1  $at, $f12
/* 0CF8DC 7F09ADAC 8C790000 */  lw    $t9, ($v1)
/* 0CF8E0 7F09ADB0 3C0143A0 */  li    $at, 0x43A00000 # 320.000000
/* 0CF8E4 7F09ADB4 44817000 */  mtc1  $at, $f14
/* 0CF8E8 7F09ADB8 3C014370 */  li    $at, 0x43700000 # 240.000000
/* 0CF8EC 7F09ADBC 44818000 */  mtc1  $at, $f16
/* 0CF8F0 7F09ADC0 E7201010 */  swc1  $f0, 0x1010($t9)
/* 0CF8F4 7F09ADC4 3C018005 */  lui   $at, %hi(D_80057624)
/* 0CF8F8 7F09ADC8 C4247624 */  lwc1  $f4, %lo(D_80057624)($at)
/* 0CF8FC 7F09ADCC 8C6C0000 */  lw    $t4, ($v1)
/* 0CF900 7F09ADD0 3C014120 */  li    $at, 0x41200000 # 10.000000
/* 0CF904 7F09ADD4 44813000 */  mtc1  $at, $f6
/* 0CF908 7F09ADD8 E5841014 */  swc1  $f4, 0x1014($t4)
/* 0CF90C 7F09ADDC 8C6D0000 */  lw    $t5, ($v1)
/* 0CF910 7F09ADE0 3C014238 */  li    $at, 0x42380000 # 46.000000
/* 0CF914 7F09ADE4 44814000 */  mtc1  $at, $f8
/* 0CF918 7F09ADE8 E5A01018 */  swc1  $f0, 0x1018($t5)
/* 0CF91C 7F09ADEC 8C780000 */  lw    $t8, ($v1)
/* 0CF920 7F09ADF0 3C014320 */  li    $at, 0x43200000 # 160.000000
/* 0CF924 7F09ADF4 44815000 */  mtc1  $at, $f10
/* 0CF928 7F09ADF8 AF00105C */  sw    $zero, 0x105c($t8)
/* 0CF92C 7F09ADFC 8C6E0000 */  lw    $t6, ($v1)
/* 0CF930 7F09AE00 3C0142F0 */  li    $at, 0x42F00000 # 120.000000
/* 0CF934 7F09AE04 44819000 */  mtc1  $at, $f18
/* 0CF938 7F09AE08 ADC01060 */  sw    $zero, 0x1060($t6)
/* 0CF93C 7F09AE0C 8C6B0000 */  lw    $t3, ($v1)
/* 0CF940 7F09AE10 3C018005 */  lui   $at, %hi(D_80057628)
/* 0CF944 7F09AE14 AD601064 */  sw    $zero, 0x1064($t3)
/* 0CF948 7F09AE18 8C6F0000 */  lw    $t7, ($v1)
/* 0CF94C 7F09AE1C E5E0106C */  swc1  $f0, 0x106c($t7)
/* 0CF950 7F09AE20 8C790000 */  lw    $t9, ($v1)
/* 0CF954 7F09AE24 E7201070 */  swc1  $f0, 0x1070($t9)
/* 0CF958 7F09AE28 8C6C0000 */  lw    $t4, ($v1)
/* 0CF95C 7F09AE2C E5801074 */  swc1  $f0, 0x1074($t4)
/* 0CF960 7F09AE30 8C6D0000 */  lw    $t5, ($v1)
/* 0CF964 7F09AE34 ADA01078 */  sw    $zero, 0x1078($t5)
/* 0CF968 7F09AE38 8C780000 */  lw    $t8, ($v1)
/* 0CF96C 7F09AE3C E700107C */  swc1  $f0, 0x107c($t8)
/* 0CF970 7F09AE40 8C6E0000 */  lw    $t6, ($v1)
/* 0CF974 7F09AE44 E5C01080 */  swc1  $f0, 0x1080($t6)
/* 0CF978 7F09AE48 8C6B0000 */  lw    $t3, ($v1)
/* 0CF97C 7F09AE4C E56C1084 */  swc1  $f12, 0x1084($t3)
/* 0CF980 7F09AE50 8C6F0000 */  lw    $t7, ($v1)
/* 0CF984 7F09AE54 E5EC1088 */  swc1  $f12, 0x1088($t7)
/* 0CF988 7F09AE58 8C790000 */  lw    $t9, ($v1)
/* 0CF98C 7F09AE5C AF29108C */  sw    $t1, 0x108c($t9)
/* 0CF990 7F09AE60 8C6C0000 */  lw    $t4, ($v1)
/* 0CF994 7F09AE64 E58E1090 */  swc1  $f14, 0x1090($t4)
/* 0CF998 7F09AE68 8C6D0000 */  lw    $t5, ($v1)
/* 0CF99C 7F09AE6C E5B01094 */  swc1  $f16, 0x1094($t5)
/* 0CF9A0 7F09AE70 8C780000 */  lw    $t8, ($v1)
/* 0CF9A4 7F09AE74 E7001098 */  swc1  $f0, 0x1098($t8)
/* 0CF9A8 7F09AE78 8C6E0000 */  lw    $t6, ($v1)
/* 0CF9AC 7F09AE7C E5C0109C */  swc1  $f0, 0x109c($t6)
/* 0CF9B0 7F09AE80 8C6B0000 */  lw    $t3, ($v1)
/* 0CF9B4 7F09AE84 E56610A0 */  swc1  $f6, 0x10a0($t3)
/* 0CF9B8 7F09AE88 8C6F0000 */  lw    $t7, ($v1)
/* 0CF9BC 7F09AE8C E5E810A4 */  swc1  $f8, 0x10a4($t7)
/* 0CF9C0 7F09AE90 8C790000 */  lw    $t9, ($v1)
/* 0CF9C4 7F09AE94 E72210A8 */  swc1  $f2, 0x10a8($t9)
/* 0CF9C8 7F09AE98 8C6C0000 */  lw    $t4, ($v1)
/* 0CF9CC 7F09AE9C E58A10AC */  swc1  $f10, 0x10ac($t4)
/* 0CF9D0 7F09AEA0 8C6D0000 */  lw    $t5, ($v1)
/* 0CF9D4 7F09AEA4 E5B210B0 */  swc1  $f18, 0x10b0($t5)
/* 0CF9D8 7F09AEA8 8C780000 */  lw    $t8, ($v1)
/* 0CF9DC 7F09AEAC E70210B4 */  swc1  $f2, 0x10b4($t8)
/* 0CF9E0 7F09AEB0 8C6E0000 */  lw    $t6, ($v1)
/* 0CF9E4 7F09AEB4 E5C210B8 */  swc1  $f2, 0x10b8($t6)
/* 0CF9E8 7F09AEB8 8C6B0000 */  lw    $t3, ($v1)
/* 0CF9EC 7F09AEBC E56210BC */  swc1  $f2, 0x10bc($t3)
/* 0CF9F0 7F09AEC0 8C6F0000 */  lw    $t7, ($v1)
/* 0CF9F4 7F09AEC4 E5E210C0 */  swc1  $f2, 0x10c0($t7)
/* 0CF9F8 7F09AEC8 8C790000 */  lw    $t9, ($v1)
/* 0CF9FC 7F09AECC AF2010C4 */  sw    $zero, 0x10c4($t9)
/* 0CFA00 7F09AED0 8C6C0000 */  lw    $t4, ($v1)
/* 0CFA04 7F09AED4 AD8010C8 */  sw    $zero, 0x10c8($t4)
/* 0CFA08 7F09AED8 8C6D0000 */  lw    $t5, ($v1)
/* 0CFA0C 7F09AEDC ADA010CC */  sw    $zero, 0x10cc($t5)
/* 0CFA10 7F09AEE0 8C780000 */  lw    $t8, ($v1)
/* 0CFA14 7F09AEE4 AF0010D0 */  sw    $zero, 0x10d0($t8)
/* 0CFA18 7F09AEE8 8C6E0000 */  lw    $t6, ($v1)
/* 0CFA1C 7F09AEEC ADC010D4 */  sw    $zero, 0x10d4($t6)
/* 0CFA20 7F09AEF0 8C6B0000 */  lw    $t3, ($v1)
/* 0CFA24 7F09AEF4 AD6010D8 */  sw    $zero, 0x10d8($t3)
/* 0CFA28 7F09AEF8 8C6F0000 */  lw    $t7, ($v1)
/* 0CFA2C 7F09AEFC ADE010DC */  sw    $zero, 0x10dc($t7)
/* 0CFA30 7F09AF00 8C790000 */  lw    $t9, ($v1)
/* 0CFA34 7F09AF04 AF2010E0 */  sw    $zero, 0x10e0($t9)
/* 0CFA38 7F09AF08 8C6C0000 */  lw    $t4, ($v1)
/* 0CFA3C 7F09AF0C 3C190001 */  lui   $t9, 1
/* 0CFA40 7F09AF10 AD8010E4 */  sw    $zero, 0x10e4($t4)
/* 0CFA44 7F09AF14 8C6D0000 */  lw    $t5, ($v1)
/* 0CFA48 7F09AF18 ADA010E8 */  sw    $zero, 0x10e8($t5)
/* 0CFA4C 7F09AF1C 8C780000 */  lw    $t8, ($v1)
/* 0CFA50 7F09AF20 AF0010EC */  sw    $zero, 0x10ec($t8)
/* 0CFA54 7F09AF24 8C6E0000 */  lw    $t6, ($v1)
/* 0CFA58 7F09AF28 E5C210F0 */  swc1  $f2, 0x10f0($t6)
/* 0CFA5C 7F09AF2C 8C6B0000 */  lw    $t3, ($v1)
/* 0CFA60 7F09AF30 E56210F4 */  swc1  $f2, 0x10f4($t3)
/* 0CFA64 7F09AF34 8C6F0000 */  lw    $t7, ($v1)
/* 0CFA68 7F09AF38 E5E210F8 */  swc1  $f2, 0x10f8($t7)
/* 0CFA6C 7F09AF3C 8C6C0000 */  lw    $t4, ($v1)
/* 0CFA70 7F09AF40 AD9910FC */  sw    $t9, 0x10fc($t4)
/* 0CFA74 7F09AF44 8C6D0000 */  lw    $t5, ($v1)
/* 0CFA78 7F09AF48 E5A01118 */  swc1  $f0, 0x1118($t5)
/* 0CFA7C 7F09AF4C 8C780000 */  lw    $t8, ($v1)
/* 0CFA80 7F09AF50 E700111C */  swc1  $f0, 0x111c($t8)
/* 0CFA84 7F09AF54 8C6E0000 */  lw    $t6, ($v1)
/* 0CFA88 7F09AF58 E5CE1120 */  swc1  $f14, 0x1120($t6)
/* 0CFA8C 7F09AF5C 8C6B0000 */  lw    $t3, ($v1)
/* 0CFA90 7F09AF60 E5701124 */  swc1  $f16, 0x1124($t3)
/* 0CFA94 7F09AF64 8C6F0000 */  lw    $t7, ($v1)
/* 0CFA98 7F09AF68 ADE01128 */  sw    $zero, 0x1128($t7)
/* 0CFA9C 7F09AF6C 8C790000 */  lw    $t9, ($v1)
/* 0CFAA0 7F09AF70 AF2011B0 */  sw    $zero, 0x11b0($t9)
/* 0CFAA4 7F09AF74 8C6C0000 */  lw    $t4, ($v1)
/* 0CFAA8 7F09AF78 AD8011B4 */  sw    $zero, 0x11b4($t4)
/* 0CFAAC 7F09AF7C 8C6D0000 */  lw    $t5, ($v1)
/* 0CFAB0 7F09AF80 ADA011B8 */  sw    $zero, 0x11b8($t5)
/* 0CFAB4 7F09AF84 8C780000 */  lw    $t8, ($v1)
/* 0CFAB8 7F09AF88 E70011BC */  swc1  $f0, 0x11bc($t8)
/* 0CFABC 7F09AF8C 8C6E0000 */  lw    $t6, ($v1)
/* 0CFAC0 7F09AF90 E5C011C0 */  swc1  $f0, 0x11c0($t6)
/* 0CFAC4 7F09AF94 8C6B0000 */  lw    $t3, ($v1)
/* 0CFAC8 7F09AF98 E56C11C4 */  swc1  $f12, 0x11c4($t3)
/* 0CFACC 7F09AF9C 8C6F0000 */  lw    $t7, ($v1)
/* 0CFAD0 7F09AFA0 E5EC11C8 */  swc1  $f12, 0x11c8($t7)
/* 0CFAD4 7F09AFA4 8C790000 */  lw    $t9, ($v1)
/* 0CFAD8 7F09AFA8 E72C11CC */  swc1  $f12, 0x11cc($t9)
/* 0CFADC 7F09AFAC 8C6C0000 */  lw    $t4, ($v1)
/* 0CFAE0 7F09AFB0 E58C11D0 */  swc1  $f12, 0x11d0($t4)
/* 0CFAE4 7F09AFB4 8C6D0000 */  lw    $t5, ($v1)
/* 0CFAE8 7F09AFB8 C4247628 */  lwc1  $f4, %lo(D_80057628)($at)
/* 0CFAEC 7F09AFBC 3C018003 */  lui   $at, %hi(invisible_to_guards_flag)
/* 0CFAF0 7F09AFC0 E5A411D4 */  swc1  $f4, 0x11d4($t5)
/* 0CFAF4 7F09AFC4 8C780000 */  lw    $t8, ($v1)
/* 0CFAF8 7F09AFC8 AF0011D8 */  sw    $zero, 0x11d8($t8)
/* 0CFAFC 7F09AFCC 8C6E0000 */  lw    $t6, ($v1)
/* 0CFB00 7F09AFD0 ADC911DC */  sw    $t1, 0x11dc($t6)
/* 0CFB04 7F09AFD4 8C6B0000 */  lw    $t3, ($v1)
/* 0CFB08 7F09AFD8 AD6011E0 */  sw    $zero, 0x11e0($t3)
/* 0CFB0C 7F09AFDC 8C6F0000 */  lw    $t7, ($v1)
/* 0CFB10 7F09AFE0 ADE011E4 */  sw    $zero, 0x11e4($t7)
/* 0CFB14 7F09AFE4 8C790000 */  lw    $t9, ($v1)
/* 0CFB18 7F09AFE8 AF2011E8 */  sw    $zero, 0x11e8($t9)
/* 0CFB1C 7F09AFEC 8C6C0000 */  lw    $t4, ($v1)
/* 0CFB20 7F09AFF0 AD8011EC */  sw    $zero, 0x11ec($t4)
/* 0CFB24 7F09AFF4 8C6D0000 */  lw    $t5, ($v1)
/* 0CFB28 7F09AFF8 ADA011F0 */  sw    $zero, 0x11f0($t5)
/* 0CFB2C 7F09AFFC 8C780000 */  lw    $t8, ($v1)
/* 0CFB30 7F09B000 AF0011F4 */  sw    $zero, 0x11f4($t8)
/* 0CFB34 7F09B004 8C6E0000 */  lw    $t6, ($v1)
/* 0CFB38 7F09B008 E5C01280 */  swc1  $f0, 0x1280($t6)
/* 0CFB3C 7F09B00C 8C6B0000 */  lw    $t3, ($v1)
/* 0CFB40 7F09B010 AD601284 */  sw    $zero, 0x1284($t3)
/* 0CFB44 7F09B014 8C6F0000 */  lw    $t7, ($v1)
/* 0CFB48 7F09B018 E5E01288 */  swc1  $f0, 0x1288($t7)
/* 0CFB4C 7F09B01C 8C790000 */  lw    $t9, ($v1)
/* 0CFB50 7F09B020 A32012B6 */  sb    $zero, 0x12b6($t9)
/* 0CFB54 7F09B024 8C6C0000 */  lw    $t4, ($v1)
/* 0CFB58 7F09B028 AD8429B8 */  sw    $a0, 0x29b8($t4)
/* 0CFB5C 7F09B02C 8C6D0000 */  lw    $t5, ($v1)
/* 0CFB60 7F09B030 E5A229BC */  swc1  $f2, 0x29bc($t5)
/* 0CFB64 7F09B034 8C780000 */  lw    $t8, ($v1)
/* 0CFB68 7F09B038 E70029C0 */  swc1  $f0, 0x29c0($t8)
/* 0CFB6C 7F09B03C 8C6E0000 */  lw    $t6, ($v1)
/* 0CFB70 7F09B040 ADC029C4 */  sw    $zero, 0x29c4($t6)
/* 0CFB74 7F09B044 8C6B0000 */  lw    $t3, ($v1)
/* 0CFB78 7F09B048 AD6429D4 */  sw    $a0, 0x29d4($t3)
/* 0CFB7C 7F09B04C 8C6F0000 */  lw    $t7, ($v1)
/* 0CFB80 7F09B050 ADE029D8 */  sw    $zero, 0x29d8($t7)
/* 0CFB84 7F09B054 8C6C0000 */  lw    $t4, ($v1)
/* 0CFB88 7F09B058 8C590000 */  lw    $t9, ($v0)
/* 0CFB8C 7F09B05C AD9929E0 */  sw    $t9, 0x29e0($t4)
/* 0CFB90 7F09B060 8C4D0000 */  lw    $t5, ($v0)
/* 0CFB94 7F09B064 8C6E0000 */  lw    $t6, ($v1)
/* 0CFB98 7F09B068 25B80001 */  addiu $t8, $t5, 1
/* 0CFB9C 7F09B06C AC580000 */  sw    $t8, ($v0)
/* 0CFBA0 7F09B070 ADC929E4 */  sw    $t1, 0x29e4($t6)
/* 0CFBA4 7F09B074 8C6B0000 */  lw    $t3, ($v1)
/* 0CFBA8 7F09B078 AD6929E8 */  sw    $t1, 0x29e8($t3)
/* 0CFBAC 7F09B07C 8C6F0000 */  lw    $t7, ($v1)
/* 0CFBB0 7F09B080 ADE929EC */  sw    $t1, 0x29ec($t7)
/* 0CFBB4 7F09B084 8C790000 */  lw    $t9, ($v1)
/* 0CFBB8 7F09B088 AF2929F0 */  sw    $t1, 0x29f0($t9)
/* 0CFBBC 7F09B08C 8C6C0000 */  lw    $t4, ($v1)
/* 0CFBC0 7F09B090 AD802A00 */  sw    $zero, 0x2a00($t4)
/* 0CFBC4 7F09B094 8C6D0000 */  lw    $t5, ($v1)
/* 0CFBC8 7F09B098 ADA02A30 */  sw    $zero, 0x2a30($t5)
/* 0CFBCC 7F09B09C 8C780000 */  lw    $t8, ($v1)
/* 0CFBD0 7F09B0A0 AF002A34 */  sw    $zero, 0x2a34($t8)
/* 0CFBD4 7F09B0A4 8C6E0000 */  lw    $t6, ($v1)
/* 0CFBD8 7F09B0A8 ADC82A38 */  sw    $t0, 0x2a38($t6)
/* 0CFBDC 7F09B0AC 8C6B0000 */  lw    $t3, ($v1)
/* 0CFBE0 7F09B0B0 E5622A3C */  swc1  $f2, 0x2a3c($t3)
/* 0CFBE4 7F09B0B4 8C6F0000 */  lw    $t7, ($v1)
/* 0CFBE8 7F09B0B8 E5E22A40 */  swc1  $f2, 0x2a40($t7)
/* 0CFBEC 7F09B0BC 8C790000 */  lw    $t9, ($v1)
/* 0CFBF0 7F09B0C0 AF202A58 */  sw    $zero, 0x2a58($t9)
/* 0CFBF4 7F09B0C4 8C6C0000 */  lw    $t4, ($v1)
/* 0CFBF8 7F09B0C8 AD802A5C */  sw    $zero, 0x2a5c($t4)
/* 0CFBFC 7F09B0CC 8C6D0000 */  lw    $t5, ($v1)
/* 0CFC00 7F09B0D0 E5A02A60 */  swc1  $f0, 0x2a60($t5)
/* 0CFC04 7F09B0D4 8C780000 */  lw    $t8, ($v1)
/* 0CFC08 7F09B0D8 AF002A64 */  sw    $zero, 0x2a64($t8)
/* 0CFC0C 7F09B0DC 8C6E0000 */  lw    $t6, ($v1)
/* 0CFC10 7F09B0E0 ADC82A68 */  sw    $t0, 0x2a68($t6)
/* 0CFC14 7F09B0E4 8C6B0000 */  lw    $t3, ($v1)
/* 0CFC18 7F09B0E8 AD602A6C */  sw    $zero, 0x2a6c($t3)
/* 0CFC1C 7F09B0EC 8C6F0000 */  lw    $t7, ($v1)
/* 0CFC20 7F09B0F0 ADE02A70 */  sw    $zero, 0x2a70($t7)
/* 0CFC24 7F09B0F4 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0CFC28 7F09B0F8 AC2864C4 */  sw    $t0, %lo(invisible_to_guards_flag)($at)
/* 0CFC2C 7F09B0FC 3C018003 */  lui   $at, %hi(obj_collision_flag)
/* 0CFC30 7F09B100 AC2864C8 */  sw    $t0, %lo(obj_collision_flag)($at)
/* 0CFC34 7F09B104 03E00008 */  jr    $ra
/* 0CFC38 7F09B108 27BD03D0 */   addiu $sp, $sp, 0x3d0
)
#endif

#ifdef VERSION_JP
GLOBAL_ASM(
.late_rodata
glabel D_80057610
.word 0xc3652ee0 /*-229.18311*/
glabel D_80057614
.word 0x411ffffe /*9.9999981*/
glabel D_80057618
.word 0x3f6e147b /*0.93000001*/
glabel D_8005761C
.word 0x4164924b /*14.285716*/
glabel D_80057620
.word 0x3f666666 /*0.89999998*/
glabel D_80057624
.word 0xc0490fdb /*-3.1415927*/
glabel D_80057628
.word 0x3faaaaab /*1.3333334*/
.text
glabel initBONDdataforPlayer
/* 0CFBCC 7F09B05C 27BDFC30 */  addiu $sp, $sp, -0x3d0
/* 0CFBD0 7F09B060 3C0F8004 */  lui   $t7, %hi(D_8003FD94+0xC) # $t7, 0x8004
/* 0CFBD4 7F09B064 25EFFDD0 */  addiu $t7, %lo(D_8003FD94+0xC) # addiu $t7, $t7, -0x230
/* 0CFBD8 7F09B068 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0CFBDC 7F09B06C AFA403D0 */  sw    $a0, 0x3d0($sp)
/* 0CFBE0 7F09B070 25EB03A8 */  addiu $t3, $t7, 0x3a8
/* 0CFBE4 7F09B074 27AE0024 */  addiu $t6, $sp, 0x24
.L7F09B078:
/* 0CFBE8 7F09B078 8DE10000 */  lw    $at, ($t7)
/* 0CFBEC 7F09B07C 25EF000C */  addiu $t7, $t7, 0xc
/* 0CFBF0 7F09B080 25CE000C */  addiu $t6, $t6, 0xc
/* 0CFBF4 7F09B084 ADC1FFF4 */  sw    $at, -0xc($t6)
/* 0CFBF8 7F09B088 8DE1FFF8 */  lw    $at, -8($t7)
/* 0CFBFC 7F09B08C ADC1FFF8 */  sw    $at, -8($t6)
/* 0CFC00 7F09B090 8DE1FFFC */  lw    $at, -4($t7)
/* 0CFC04 7F09B094 15EBFFF8 */  bne   $t7, $t3, .L7F09B078
/* 0CFC08 7F09B098 ADC1FFFC */   sw    $at, -4($t6)
/* 0CFC0C 7F09B09C 24042A80 */  li    $a0, 10880
/* 0CFC10 7F09B0A0 0C0025CC */  jal   mempAllocBytesInBank
/* 0CFC14 7F09B0A4 24050004 */   li    $a1, 4
/* 0CFC18 7F09B0A8 8FAC03D0 */  lw    $t4, 0x3d0($sp)
/* 0CFC1C 7F09B0AC 3C198008 */  lui   $t9, %hi(players) # $t9, 0x8008
/* 0CFC20 7F09B0B0 27399F50 */  addiu $t9, %lo(players) # addiu $t9, $t9, -0x60b0
/* 0CFC24 7F09B0B4 000C6880 */  sll   $t5, $t4, 2
/* 0CFC28 7F09B0B8 01B91821 */  addu  $v1, $t5, $t9
/* 0CFC2C 7F09B0BC AC620000 */  sw    $v0, ($v1)
/* 0CFC30 7F09B0C0 AC400000 */  sw    $zero, ($v0)
/* 0CFC34 7F09B0C4 44800000 */  mtc1  $zero, $f0
/* 0CFC38 7F09B0C8 8C780000 */  lw    $t8, ($v1)
/* 0CFC3C 7F09B0CC 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0CFC40 7F09B0D0 44811000 */  mtc1  $at, $f2
/* 0CFC44 7F09B0D4 E7000004 */  swc1  $f0, 4($t8)
/* 0CFC48 7F09B0D8 8C6B0000 */  lw    $t3, ($v1)
/* 0CFC4C 7F09B0DC 24040002 */  li    $a0, 2
/* 0CFC50 7F09B0E0 24080001 */  li    $t0, 1
/* 0CFC54 7F09B0E4 E5600008 */  swc1  $f0, 8($t3)
/* 0CFC58 7F09B0E8 8C6F0000 */  lw    $t7, ($v1)
/* 0CFC5C 7F09B0EC 3C01BF80 */  li    $at, 0xBF800000 # -1.000000
/* 0CFC60 7F09B0F0 44816000 */  mtc1  $at, $f12
/* 0CFC64 7F09B0F4 E5E0000C */  swc1  $f0, 0xc($t7)
/* 0CFC68 7F09B0F8 8C6E0000 */  lw    $t6, ($v1)
/* 0CFC6C 7F09B0FC 2409FFFF */  li    $t1, -1
/* 0CFC70 7F09B100 3C01C080 */  li    $at, 0xC0800000 # -4.000000
/* 0CFC74 7F09B104 E5C00010 */  swc1  $f0, 0x10($t6)
/* 0CFC78 7F09B108 8C6C0000 */  lw    $t4, ($v1)
/* 0CFC7C 7F09B10C 44812000 */  mtc1  $at, $f4
/* 0CFC80 7F09B110 3C018005 */  lui   $at, %hi(D_80057610)
/* 0CFC84 7F09B114 E5800014 */  swc1  $f0, 0x14($t4)
/* 0CFC88 7F09B118 8C6D0000 */  lw    $t5, ($v1)
/* 0CFC8C 7F09B11C 240200FF */  li    $v0, 255
/* 0CFC90 7F09B120 27AA0024 */  addiu $t2, $sp, 0x24
/* 0CFC94 7F09B124 E5A20018 */  swc1  $f2, 0x18($t5)
/* 0CFC98 7F09B128 8C790000 */  lw    $t9, ($v1)
/* 0CFC9C 7F09B12C E720001C */  swc1  $f0, 0x1c($t9)
/* 0CFCA0 7F09B130 8C780000 */  lw    $t8, ($v1)
/* 0CFCA4 7F09B134 E7020020 */  swc1  $f2, 0x20($t8)
/* 0CFCA8 7F09B138 8C6B0000 */  lw    $t3, ($v1)
/* 0CFCAC 7F09B13C E5600024 */  swc1  $f0, 0x24($t3)
/* 0CFCB0 7F09B140 8C6F0000 */  lw    $t7, ($v1)
/* 0CFCB4 7F09B144 E5E00028 */  swc1  $f0, 0x28($t7)
/* 0CFCB8 7F09B148 8C6E0000 */  lw    $t6, ($v1)
/* 0CFCBC 7F09B14C E5C0002C */  swc1  $f0, 0x2c($t6)
/* 0CFCC0 7F09B150 8C6C0000 */  lw    $t4, ($v1)
/* 0CFCC4 7F09B154 E5800030 */  swc1  $f0, 0x30($t4)
/* 0CFCC8 7F09B158 8C6D0000 */  lw    $t5, ($v1)
/* 0CFCCC 7F09B15C ADA00034 */  sw    $zero, 0x34($t5)
/* 0CFCD0 7F09B160 8C790000 */  lw    $t9, ($v1)
/* 0CFCD4 7F09B164 E7200038 */  swc1  $f0, 0x38($t9)
/* 0CFCD8 7F09B168 8C780000 */  lw    $t8, ($v1)
/* 0CFCDC 7F09B16C E700003C */  swc1  $f0, 0x3c($t8)
/* 0CFCE0 7F09B170 8C6B0000 */  lw    $t3, ($v1)
/* 0CFCE4 7F09B174 E5600040 */  swc1  $f0, 0x40($t3)
/* 0CFCE8 7F09B178 8C6F0000 */  lw    $t7, ($v1)
/* 0CFCEC 7F09B17C E5E00044 */  swc1  $f0, 0x44($t7)
/* 0CFCF0 7F09B180 8C6E0000 */  lw    $t6, ($v1)
/* 0CFCF4 7F09B184 E5C00048 */  swc1  $f0, 0x48($t6)
/* 0CFCF8 7F09B188 8C6C0000 */  lw    $t4, ($v1)
/* 0CFCFC 7F09B18C E580004C */  swc1  $f0, 0x4c($t4)
/* 0CFD00 7F09B190 8C6D0000 */  lw    $t5, ($v1)
/* 0CFD04 7F09B194 E5A00050 */  swc1  $f0, 0x50($t5)
/* 0CFD08 7F09B198 8C790000 */  lw    $t9, ($v1)
/* 0CFD0C 7F09B19C E7200054 */  swc1  $f0, 0x54($t9)
/* 0CFD10 7F09B1A0 8C780000 */  lw    $t8, ($v1)
/* 0CFD14 7F09B1A4 E7000058 */  swc1  $f0, 0x58($t8)
/* 0CFD18 7F09B1A8 8C6B0000 */  lw    $t3, ($v1)
/* 0CFD1C 7F09B1AC E560006C */  swc1  $f0, 0x6c($t3)
/* 0CFD20 7F09B1B0 8C6F0000 */  lw    $t7, ($v1)
/* 0CFD24 7F09B1B4 E5E00070 */  swc1  $f0, 0x70($t7)
/* 0CFD28 7F09B1B8 8C6E0000 */  lw    $t6, ($v1)
/* 0CFD2C 7F09B1BC E5C00074 */  swc1  $f0, 0x74($t6)
/* 0CFD30 7F09B1C0 8C6C0000 */  lw    $t4, ($v1)
/* 0CFD34 7F09B1C4 E5800078 */  swc1  $f0, 0x78($t4)
/* 0CFD38 7F09B1C8 8C6D0000 */  lw    $t5, ($v1)
/* 0CFD3C 7F09B1CC E5A0007C */  swc1  $f0, 0x7c($t5)
/* 0CFD40 7F09B1D0 8C790000 */  lw    $t9, ($v1)
/* 0CFD44 7F09B1D4 E7200080 */  swc1  $f0, 0x80($t9)
/* 0CFD48 7F09B1D8 8C780000 */  lw    $t8, ($v1)
/* 0CFD4C 7F09B1DC E7000084 */  swc1  $f0, 0x84($t8)
/* 0CFD50 7F09B1E0 8C6B0000 */  lw    $t3, ($v1)
/* 0CFD54 7F09B1E4 E5600088 */  swc1  $f0, 0x88($t3)
/* 0CFD58 7F09B1E8 8C6F0000 */  lw    $t7, ($v1)
/* 0CFD5C 7F09B1EC ADE0008C */  sw    $zero, 0x8c($t7)
/* 0CFD60 7F09B1F0 8C6E0000 */  lw    $t6, ($v1)
/* 0CFD64 7F09B1F4 E5C00090 */  swc1  $f0, 0x90($t6)
/* 0CFD68 7F09B1F8 8C6C0000 */  lw    $t4, ($v1)
/* 0CFD6C 7F09B1FC AD800094 */  sw    $zero, 0x94($t4)
/* 0CFD70 7F09B200 8C6D0000 */  lw    $t5, ($v1)
/* 0CFD74 7F09B204 E5A00098 */  swc1  $f0, 0x98($t5)
/* 0CFD78 7F09B208 8C790000 */  lw    $t9, ($v1)
/* 0CFD7C 7F09B20C E7201274 */  swc1  $f0, 0x1274($t9)
/* 0CFD80 7F09B210 8C780000 */  lw    $t8, ($v1)
/* 0CFD84 7F09B214 E7001278 */  swc1  $f0, 0x1278($t8)
/* 0CFD88 7F09B218 8C6B0000 */  lw    $t3, ($v1)
/* 0CFD8C 7F09B21C E560127C */  swc1  $f0, 0x127c($t3)
/* 0CFD90 7F09B220 8C6F0000 */  lw    $t7, ($v1)
/* 0CFD94 7F09B224 ADE4009C */  sw    $a0, 0x9c($t7)
/* 0CFD98 7F09B228 8C6E0000 */  lw    $t6, ($v1)
/* 0CFD9C 7F09B22C ADC429FC */  sw    $a0, 0x29fc($t6)
/* 0CFDA0 7F09B230 8C6C0000 */  lw    $t4, ($v1)
/* 0CFDA4 7F09B234 E58000A0 */  swc1  $f0, 0xa0($t4)
/* 0CFDA8 7F09B238 8C6D0000 */  lw    $t5, ($v1)
/* 0CFDAC 7F09B23C E5A000A4 */  swc1  $f0, 0xa4($t5)
/* 0CFDB0 7F09B240 8C790000 */  lw    $t9, ($v1)
/* 0CFDB4 7F09B244 AF2000A8 */  sw    $zero, 0xa8($t9)
/* 0CFDB8 7F09B248 8C780000 */  lw    $t8, ($v1)
/* 0CFDBC 7F09B24C AF0800AC */  sw    $t0, 0xac($t8)
/* 0CFDC0 7F09B250 8C6B0000 */  lw    $t3, ($v1)
/* 0CFDC4 7F09B254 AD6000D0 */  sw    $zero, 0xd0($t3)
/* 0CFDC8 7F09B258 8C6F0000 */  lw    $t7, ($v1)
/* 0CFDCC 7F09B25C ADE000D4 */  sw    $zero, 0xd4($t7)
/* 0CFDD0 7F09B260 8C6E0000 */  lw    $t6, ($v1)
/* 0CFDD4 7F09B264 ADC000D8 */  sw    $zero, 0xd8($t6)
/* 0CFDD8 7F09B268 8C6C0000 */  lw    $t4, ($v1)
/* 0CFDDC 7F09B26C E58200DC */  swc1  $f2, 0xdc($t4)
/* 0CFDE0 7F09B270 8C6D0000 */  lw    $t5, ($v1)
/* 0CFDE4 7F09B274 E5A000E0 */  swc1  $f0, 0xe0($t5)
/* 0CFDE8 7F09B278 8C790000 */  lw    $t9, ($v1)
/* 0CFDEC 7F09B27C E72200E4 */  swc1  $f2, 0xe4($t9)
/* 0CFDF0 7F09B280 8C780000 */  lw    $t8, ($v1)
/* 0CFDF4 7F09B284 E70000E8 */  swc1  $f0, 0xe8($t8)
/* 0CFDF8 7F09B288 8C6B0000 */  lw    $t3, ($v1)
/* 0CFDFC 7F09B28C E56200EC */  swc1  $f2, 0xec($t3)
/* 0CFE00 7F09B290 8C6F0000 */  lw    $t7, ($v1)
/* 0CFE04 7F09B294 E5E000F0 */  swc1  $f0, 0xf0($t7)
/* 0CFE08 7F09B298 8C6E0000 */  lw    $t6, ($v1)
/* 0CFE0C 7F09B29C E5CC00F4 */  swc1  $f12, 0xf4($t6)
/* 0CFE10 7F09B2A0 8C6C0000 */  lw    $t4, ($v1)
/* 0CFE14 7F09B2A4 E58C00F8 */  swc1  $f12, 0xf8($t4)
/* 0CFE18 7F09B2A8 8C6D0000 */  lw    $t5, ($v1)
/* 0CFE1C 7F09B2AC ADA00104 */  sw    $zero, 0x104($t5)
/* 0CFE20 7F09B2B0 8C790000 */  lw    $t9, ($v1)
/* 0CFE24 7F09B2B4 AF200108 */  sw    $zero, 0x108($t9)
/* 0CFE28 7F09B2B8 8C780000 */  lw    $t8, ($v1)
/* 0CFE2C 7F09B2BC AF00010C */  sw    $zero, 0x10c($t8)
/* 0CFE30 7F09B2C0 8C6B0000 */  lw    $t3, ($v1)
/* 0CFE34 7F09B2C4 AD600110 */  sw    $zero, 0x110($t3)
/* 0CFE38 7F09B2C8 8C6F0000 */  lw    $t7, ($v1)
/* 0CFE3C 7F09B2CC ADE80114 */  sw    $t0, 0x114($t7)
/* 0CFE40 7F09B2D0 8C6E0000 */  lw    $t6, ($v1)
/* 0CFE44 7F09B2D4 ADC80118 */  sw    $t0, 0x118($t6)
/* 0CFE48 7F09B2D8 8C6C0000 */  lw    $t4, ($v1)
/* 0CFE4C 7F09B2DC AD80011C */  sw    $zero, 0x11c($t4)
/* 0CFE50 7F09B2E0 8C6D0000 */  lw    $t5, ($v1)
/* 0CFE54 7F09B2E4 ADA80120 */  sw    $t0, 0x120($t5)
/* 0CFE58 7F09B2E8 8C790000 */  lw    $t9, ($v1)
/* 0CFE5C 7F09B2EC AF200124 */  sw    $zero, 0x124($t9)
/* 0CFE60 7F09B2F0 8C780000 */  lw    $t8, ($v1)
/* 0CFE64 7F09B2F4 AF080128 */  sw    $t0, 0x128($t8)
/* 0CFE68 7F09B2F8 8C6B0000 */  lw    $t3, ($v1)
/* 0CFE6C 7F09B2FC E560012C */  swc1  $f0, 0x12c($t3)
/* 0CFE70 7F09B300 8C6F0000 */  lw    $t7, ($v1)
/* 0CFE74 7F09B304 ADE00130 */  sw    $zero, 0x130($t7)
/* 0CFE78 7F09B308 8C6E0000 */  lw    $t6, ($v1)
/* 0CFE7C 7F09B30C ADC90134 */  sw    $t1, 0x134($t6)
/* 0CFE80 7F09B310 8C6C0000 */  lw    $t4, ($v1)
/* 0CFE84 7F09B314 AD880138 */  sw    $t0, 0x138($t4)
/* 0CFE88 7F09B318 8C6D0000 */  lw    $t5, ($v1)
/* 0CFE8C 7F09B31C E5A0013C */  swc1  $f0, 0x13c($t5)
/* 0CFE90 7F09B320 8C790000 */  lw    $t9, ($v1)
/* 0CFE94 7F09B324 AF200140 */  sw    $zero, 0x140($t9)
/* 0CFE98 7F09B328 8C780000 */  lw    $t8, ($v1)
/* 0CFE9C 7F09B32C AF090144 */  sw    $t1, 0x144($t8)
/* 0CFEA0 7F09B330 8C6B0000 */  lw    $t3, ($v1)
/* 0CFEA4 7F09B334 E5600148 */  swc1  $f0, 0x148($t3)
/* 0CFEA8 7F09B338 8C6F0000 */  lw    $t7, ($v1)
/* 0CFEAC 7F09B33C E5E0014C */  swc1  $f0, 0x14c($t7)
/* 0CFEB0 7F09B340 8C6E0000 */  lw    $t6, ($v1)
/* 0CFEB4 7F09B344 E5C20150 */  swc1  $f2, 0x150($t6)
/* 0CFEB8 7F09B348 8C6C0000 */  lw    $t4, ($v1)
/* 0CFEBC 7F09B34C E5800154 */  swc1  $f0, 0x154($t4)
/* 0CFEC0 7F09B350 8C6D0000 */  lw    $t5, ($v1)
/* 0CFEC4 7F09B354 E5A40158 */  swc1  $f4, 0x158($t5)
/* 0CFEC8 7F09B358 8C790000 */  lw    $t9, ($v1)
/* 0CFECC 7F09B35C C4267640 */  lwc1  $f6, %lo(D_80057610)($at)
/* 0CFED0 7F09B360 3C01C1C8 */  li    $at, 0xC1C80000 # -25.000000
/* 0CFED4 7F09B364 44814000 */  mtc1  $at, $f8
/* 0CFED8 7F09B368 E726015C */  swc1  $f6, 0x15c($t9)
/* 0CFEDC 7F09B36C 8C780000 */  lw    $t8, ($v1)
/* 0CFEE0 7F09B370 3C018005 */  lui   $at, %hi(D_80057614) # $at, 0x8005
/* 0CFEE4 7F09B374 E7000160 */  swc1  $f0, 0x160($t8)
/* 0CFEE8 7F09B378 8C6B0000 */  lw    $t3, ($v1)
/* 0CFEEC 7F09B37C E5620164 */  swc1  $f2, 0x164($t3)
/* 0CFEF0 7F09B380 8C6F0000 */  lw    $t7, ($v1)
/* 0CFEF4 7F09B384 E5E00168 */  swc1  $f0, 0x168($t7)
/* 0CFEF8 7F09B388 8C6E0000 */  lw    $t6, ($v1)
/* 0CFEFC 7F09B38C E5C0016C */  swc1  $f0, 0x16c($t6)
/* 0CFF00 7F09B390 8C6C0000 */  lw    $t4, ($v1)
/* 0CFF04 7F09B394 E5800170 */  swc1  $f0, 0x170($t4)
/* 0CFF08 7F09B398 8C6D0000 */  lw    $t5, ($v1)
/* 0CFF0C 7F09B39C E5A00174 */  swc1  $f0, 0x174($t5)
/* 0CFF10 7F09B3A0 8C790000 */  lw    $t9, ($v1)
/* 0CFF14 7F09B3A4 E7202A4C */  swc1  $f0, 0x2a4c($t9)
/* 0CFF18 7F09B3A8 8C780000 */  lw    $t8, ($v1)
/* 0CFF1C 7F09B3AC E7020178 */  swc1  $f2, 0x178($t8)
/* 0CFF20 7F09B3B0 8C6B0000 */  lw    $t3, ($v1)
/* 0CFF24 7F09B3B4 E5600180 */  swc1  $f0, 0x180($t3)
/* 0CFF28 7F09B3B8 8C6F0000 */  lw    $t7, ($v1)
/* 0CFF2C 7F09B3BC E5E00184 */  swc1  $f0, 0x184($t7)
/* 0CFF30 7F09B3C0 8C6E0000 */  lw    $t6, ($v1)
/* 0CFF34 7F09B3C4 E5C00188 */  swc1  $f0, 0x188($t6)
/* 0CFF38 7F09B3C8 8C6C0000 */  lw    $t4, ($v1)
/* 0CFF3C 7F09B3CC E58C018C */  swc1  $f12, 0x18c($t4)
/* 0CFF40 7F09B3D0 8C6D0000 */  lw    $t5, ($v1)
/* 0CFF44 7F09B3D4 E5AC0190 */  swc1  $f12, 0x190($t5)
/* 0CFF48 7F09B3D8 8C790000 */  lw    $t9, ($v1)
/* 0CFF4C 7F09B3DC E7200194 */  swc1  $f0, 0x194($t9)
/* 0CFF50 7F09B3E0 8C780000 */  lw    $t8, ($v1)
/* 0CFF54 7F09B3E4 E7000198 */  swc1  $f0, 0x198($t8)
/* 0CFF58 7F09B3E8 8C6B0000 */  lw    $t3, ($v1)
/* 0CFF5C 7F09B3EC E560019C */  swc1  $f0, 0x19c($t3)
/* 0CFF60 7F09B3F0 8C6F0000 */  lw    $t7, ($v1)
/* 0CFF64 7F09B3F4 ADE001A0 */  sw    $zero, 0x1a0($t7)
/* 0CFF68 7F09B3F8 8C6E0000 */  lw    $t6, ($v1)
/* 0CFF6C 7F09B3FC ADC001C0 */  sw    $zero, 0x1c0($t6)
/* 0CFF70 7F09B400 8C6C0000 */  lw    $t4, ($v1)
/* 0CFF74 7F09B404 AD8001C4 */  sw    $zero, 0x1c4($t4)
/* 0CFF78 7F09B408 8C6D0000 */  lw    $t5, ($v1)
/* 0CFF7C 7F09B40C ADA001C8 */  sw    $zero, 0x1c8($t5)
/* 0CFF80 7F09B410 8C790000 */  lw    $t9, ($v1)
/* 0CFF84 7F09B414 AF2801CC */  sw    $t0, 0x1cc($t9)
/* 0CFF88 7F09B418 8C780000 */  lw    $t8, ($v1)
/* 0CFF8C 7F09B41C AF0001D0 */  sw    $zero, 0x1d0($t8)
/* 0CFF90 7F09B420 8C6B0000 */  lw    $t3, ($v1)
/* 0CFF94 7F09B424 E56001D4 */  swc1  $f0, 0x1d4($t3)
/* 0CFF98 7F09B428 8C6F0000 */  lw    $t7, ($v1)
/* 0CFF9C 7F09B42C E5E001D8 */  swc1  $f0, 0x1d8($t7)
/* 0CFFA0 7F09B430 8C6E0000 */  lw    $t6, ($v1)
/* 0CFFA4 7F09B434 E5C801DC */  swc1  $f8, 0x1dc($t6)
/* 0CFFA8 7F09B438 8C6C0000 */  lw    $t4, ($v1)
/* 0CFFAC 7F09B43C E58001E0 */  swc1  $f0, 0x1e0($t4)
/* 0CFFB0 7F09B440 8C6D0000 */  lw    $t5, ($v1)
/* 0CFFB4 7F09B444 E5A201E4 */  swc1  $f2, 0x1e4($t5)
/* 0CFFB8 7F09B448 8C790000 */  lw    $t9, ($v1)
/* 0CFFBC 7F09B44C E72001E8 */  swc1  $f0, 0x1e8($t9)
/* 0CFFC0 7F09B450 8C780000 */  lw    $t8, ($v1)
/* 0CFFC4 7F09B454 E70001EC */  swc1  $f0, 0x1ec($t8)
/* 0CFFC8 7F09B458 8C6B0000 */  lw    $t3, ($v1)
/* 0CFFCC 7F09B45C E56001F0 */  swc1  $f0, 0x1f0($t3)
/* 0CFFD0 7F09B460 8C6F0000 */  lw    $t7, ($v1)
/* 0CFFD4 7F09B464 E5E201F4 */  swc1  $f2, 0x1f4($t7)
/* 0CFFD8 7F09B468 8C6E0000 */  lw    $t6, ($v1)
/* 0CFFDC 7F09B46C ADC00200 */  sw    $zero, 0x200($t6)
/* 0CFFE0 7F09B470 8C6C0000 */  lw    $t4, ($v1)
/* 0CFFE4 7F09B474 E5800204 */  swc1  $f0, 0x204($t4)
/* 0CFFE8 7F09B478 8C6D0000 */  lw    $t5, ($v1)
/* 0CFFEC 7F09B47C E5A00208 */  swc1  $f0, 0x208($t5)
/* 0CFFF0 7F09B480 8C790000 */  lw    $t9, ($v1)
/* 0CFFF4 7F09B484 E720020C */  swc1  $f0, 0x20c($t9)
/* 0CFFF8 7F09B488 8C780000 */  lw    $t8, ($v1)
/* 0CFFFC 7F09B48C E7000210 */  swc1  $f0, 0x210($t8)
/* 0D0000 7F09B490 8C6B0000 */  lw    $t3, ($v1)
/* 0D0004 7F09B494 E5600214 */  swc1  $f0, 0x214($t3)
/* 0D0008 7F09B498 8C6F0000 */  lw    $t7, ($v1)
/* 0D000C 7F09B49C ADE00218 */  sw    $zero, 0x218($t7)
/* 0D0010 7F09B4A0 8C6E0000 */  lw    $t6, ($v1)
/* 0D0014 7F09B4A4 ADC8021C */  sw    $t0, 0x21c($t6)
/* 0D0018 7F09B4A8 8C6C0000 */  lw    $t4, ($v1)
/* 0D001C 7F09B4AC AD800220 */  sw    $zero, 0x220($t4)
/* 0D0020 7F09B4B0 8C6D0000 */  lw    $t5, ($v1)
/* 0D0024 7F09B4B4 E5A00224 */  swc1  $f0, 0x224($t5)
/* 0D0028 7F09B4B8 8C790000 */  lw    $t9, ($v1)
/* 0D002C 7F09B4BC A72003B4 */  sh    $zero, 0x3b4($t9)
/* 0D0030 7F09B4C0 8C780000 */  lw    $t8, ($v1)
/* 0D0034 7F09B4C4 A70003B6 */  sh    $zero, 0x3b6($t8)
/* 0D0038 7F09B4C8 8C6B0000 */  lw    $t3, ($v1)
/* 0D003C 7F09B4CC E56003B8 */  swc1  $f0, 0x3b8($t3)
/* 0D0040 7F09B4D0 8C6F0000 */  lw    $t7, ($v1)
/* 0D0044 7F09B4D4 E5E003BC */  swc1  $f0, 0x3bc($t7)
/* 0D0048 7F09B4D8 8C6E0000 */  lw    $t6, ($v1)
/* 0D004C 7F09B4DC C42A7644 */  lwc1  $f10, %lo(D_80057614)($at)
/* 0D0050 7F09B4E0 E5CA03C0 */  swc1  $f10, 0x3c0($t6)
/* 0D0054 7F09B4E4 8C6C0000 */  lw    $t4, ($v1)
/* 0D0058 7F09B4E8 E58003C4 */  swc1  $f0, 0x3c4($t4)
/* 0D005C 7F09B4EC 8C6D0000 */  lw    $t5, ($v1)
/* 0D0060 7F09B4F0 E5A003C8 */  swc1  $f0, 0x3c8($t5)
/* 0D0064 7F09B4F4 8C790000 */  lw    $t9, ($v1)
/* 0D0068 7F09B4F8 E72203CC */  swc1  $f2, 0x3cc($t9)
/* 0D006C 7F09B4FC 8C780000 */  lw    $t8, ($v1)
/* 0D0070 7F09B500 AF0203D0 */  sw    $v0, 0x3d0($t8)
/* 0D0074 7F09B504 8C6B0000 */  lw    $t3, ($v1)
/* 0D0078 7F09B508 AD6203D4 */  sw    $v0, 0x3d4($t3)
/* 0D007C 7F09B50C 8C6F0000 */  lw    $t7, ($v1)
/* 0D0080 7F09B510 3C018005 */  lui   $at, %hi(D_80057618) # $at, 0x8005
/* 0D0084 7F09B514 24070020 */  li    $a3, 32
/* 0D0088 7F09B518 ADE203D8 */  sw    $v0, 0x3d8($t7)
/* 0D008C 7F09B51C 8C6E0000 */  lw    $t6, ($v1)
/* 0D0090 7F09B520 240601FF */  li    $a2, 511
/* 0D0094 7F09B524 240501E0 */  li    $a1, 480
/* 0D0098 7F09B528 E5C003DC */  swc1  $f0, 0x3dc($t6)
/* 0D009C 7F09B52C 8C6C0000 */  lw    $t4, ($v1)
/* 0D00A0 7F09B530 E58C03E0 */  swc1  $f12, 0x3e0($t4)
/* 0D00A4 7F09B534 8C6D0000 */  lw    $t5, ($v1)
/* 0D00A8 7F09B538 E5AC03E4 */  swc1  $f12, 0x3e4($t5)
/* 0D00AC 7F09B53C 8C790000 */  lw    $t9, ($v1)
/* 0D00B0 7F09B540 AF2203E8 */  sw    $v0, 0x3e8($t9)
/* 0D00B4 7F09B544 8C780000 */  lw    $t8, ($v1)
/* 0D00B8 7F09B548 AF0203EC */  sw    $v0, 0x3ec($t8)
/* 0D00BC 7F09B54C 8C6B0000 */  lw    $t3, ($v1)
/* 0D00C0 7F09B550 AD6203F0 */  sw    $v0, 0x3f0($t3)
/* 0D00C4 7F09B554 8C6F0000 */  lw    $t7, ($v1)
/* 0D00C8 7F09B558 ADE203F4 */  sw    $v0, 0x3f4($t7)
/* 0D00CC 7F09B55C 8C6E0000 */  lw    $t6, ($v1)
/* 0D00D0 7F09B560 ADC203F8 */  sw    $v0, 0x3f8($t6)
/* 0D00D4 7F09B564 8C6C0000 */  lw    $t4, ($v1)
/* 0D00D8 7F09B568 AD8203FC */  sw    $v0, 0x3fc($t4)
/* 0D00DC 7F09B56C 8C6D0000 */  lw    $t5, ($v1)
/* 0D00E0 7F09B570 00001025 */  move  $v0, $zero
/* 0D00E4 7F09B574 E5A00400 */  swc1  $f0, 0x400($t5)
/* 0D00E8 7F09B578 8C790000 */  lw    $t9, ($v1)
/* 0D00EC 7F09B57C E7200404 */  swc1  $f0, 0x404($t9)
/* 0D00F0 7F09B580 8C780000 */  lw    $t8, ($v1)
/* 0D00F4 7F09B584 AF00041C */  sw    $zero, 0x41c($t8)
/* 0D00F8 7F09B588 8C6B0000 */  lw    $t3, ($v1)
/* 0D00FC 7F09B58C AD680420 */  sw    $t0, 0x420($t3)
/* 0D0100 7F09B590 8C6F0000 */  lw    $t7, ($v1)
/* 0D0104 7F09B594 ADE00424 */  sw    $zero, 0x424($t7)
/* 0D0108 7F09B598 8C6E0000 */  lw    $t6, ($v1)
/* 0D010C 7F09B59C ADC00428 */  sw    $zero, 0x428($t6)
/* 0D0110 7F09B5A0 8C6C0000 */  lw    $t4, ($v1)
/* 0D0114 7F09B5A4 AD84042C */  sw    $a0, 0x42c($t4)
/* 0D0118 7F09B5A8 8C6D0000 */  lw    $t5, ($v1)
/* 0D011C 7F09B5AC 24040280 */  li    $a0, 640
/* 0D0120 7F09B5B0 ADA00430 */  sw    $zero, 0x430($t5)
/* 0D0124 7F09B5B4 8C790000 */  lw    $t9, ($v1)
/* 0D0128 7F09B5B8 AF2804DC */  sw    $t0, 0x4dc($t9)
/* 0D012C 7F09B5BC 8C780000 */  lw    $t8, ($v1)
/* 0D0130 7F09B5C0 AF0804E0 */  sw    $t0, 0x4e0($t8)
/* 0D0134 7F09B5C4 8C6B0000 */  lw    $t3, ($v1)
/* 0D0138 7F09B5C8 AD6804E4 */  sw    $t0, 0x4e4($t3)
/* 0D013C 7F09B5CC 8C6F0000 */  lw    $t7, ($v1)
/* 0D0140 7F09B5D0 ADE004E8 */  sw    $zero, 0x4e8($t7)
/* 0D0144 7F09B5D4 8C6E0000 */  lw    $t6, ($v1)
/* 0D0148 7F09B5D8 C4327648 */  lwc1  $f18, %lo(D_80057618)($at)
/* 0D014C 7F09B5DC 3C018005 */  lui   $at, %hi(D_8005761C) # $at, 0x8005
/* 0D0150 7F09B5E0 E5D204EC */  swc1  $f18, 0x4ec($t6)
/* 0D0154 7F09B5E4 8C6C0000 */  lw    $t4, ($v1)
/* 0D0158 7F09B5E8 AD8004F0 */  sw    $zero, 0x4f0($t4)
/* 0D015C 7F09B5EC 8C6D0000 */  lw    $t5, ($v1)
/* 0D0160 7F09B5F0 E5A204F4 */  swc1  $f2, 0x4f4($t5)
/* 0D0164 7F09B5F4 8C790000 */  lw    $t9, ($v1)
/* 0D0168 7F09B5F8 E72204F8 */  swc1  $f2, 0x4f8($t9)
/* 0D016C 7F09B5FC 8C780000 */  lw    $t8, ($v1)
/* 0D0170 7F09B600 E70004FC */  swc1  $f0, 0x4fc($t8)
/* 0D0174 7F09B604 8C6B0000 */  lw    $t3, ($v1)
/* 0D0178 7F09B608 E5600500 */  swc1  $f0, 0x500($t3)
/* 0D017C 7F09B60C 8C6F0000 */  lw    $t7, ($v1)
/* 0D0180 7F09B610 E5E00504 */  swc1  $f0, 0x504($t7)
/* 0D0184 7F09B614 8C6E0000 */  lw    $t6, ($v1)
/* 0D0188 7F09B618 C42C764C */  lwc1  $f12, %lo(D_8005761C)($at)
/* 0D018C 7F09B61C E5C00508 */  swc1  $f0, 0x508($t6)
/* 0D0190 7F09B620 8C6C0000 */  lw    $t4, ($v1)
/* 0D0194 7F09B624 E580050C */  swc1  $f0, 0x50c($t4)
/* 0D0198 7F09B628 8C6D0000 */  lw    $t5, ($v1)
/* 0D019C 7F09B62C E5A20510 */  swc1  $f2, 0x510($t5)
/* 0D01A0 7F09B630 8C790000 */  lw    $t9, ($v1)
/* 0D01A4 7F09B634 E7200514 */  swc1  $f0, 0x514($t9)
/* 0D01A8 7F09B638 8C780000 */  lw    $t8, ($v1)
/* 0D01AC 7F09B63C E7020518 */  swc1  $f2, 0x518($t8)
/* 0D01B0 7F09B640 8C6B0000 */  lw    $t3, ($v1)
/* 0D01B4 7F09B644 E560051C */  swc1  $f0, 0x51c($t3)
/* 0D01B8 7F09B648 8C6F0000 */  lw    $t7, ($v1)
/* 0D01BC 7F09B64C E5E00520 */  swc1  $f0, 0x520($t7)
/* 0D01C0 7F09B650 8C6E0000 */  lw    $t6, ($v1)
/* 0D01C4 7F09B654 E5C00524 */  swc1  $f0, 0x524($t6)
/* 0D01C8 7F09B658 8C6C0000 */  lw    $t4, ($v1)
/* 0D01CC 7F09B65C E5800528 */  swc1  $f0, 0x528($t4)
/* 0D01D0 7F09B660 8C6D0000 */  lw    $t5, ($v1)
/* 0D01D4 7F09B664 E5A0052C */  swc1  $f0, 0x52c($t5)
/* 0D01D8 7F09B668 8C790000 */  lw    $t9, ($v1)
/* 0D01DC 7F09B66C E7200530 */  swc1  $f0, 0x530($t9)
/* 0D01E0 7F09B670 8C780000 */  lw    $t8, ($v1)
/* 0D01E4 7F09B674 E70C0534 */  swc1  $f12, 0x534($t8)
/* 0D01E8 7F09B678 8C6B0000 */  lw    $t3, ($v1)
/* 0D01EC 7F09B67C E5600538 */  swc1  $f0, 0x538($t3)
/* 0D01F0 7F09B680 8C6F0000 */  lw    $t7, ($v1)
/* 0D01F4 7F09B684 E5EC053C */  swc1  $f12, 0x53c($t7)
/* 0D01F8 7F09B688 8C6E0000 */  lw    $t6, ($v1)
/* 0D01FC 7F09B68C E5C00540 */  swc1  $f0, 0x540($t6)
/* 0D0200 7F09B690 8C6C0000 */  lw    $t4, ($v1)
/* 0D0204 7F09B694 E5800544 */  swc1  $f0, 0x544($t4)
/* 0D0208 7F09B698 8C6D0000 */  lw    $t5, ($v1)
/* 0D020C 7F09B69C E5A00548 */  swc1  $f0, 0x548($t5)
/* 0D0210 7F09B6A0 8C790000 */  lw    $t9, ($v1)
/* 0D0214 7F09B6A4 E720054C */  swc1  $f0, 0x54c($t9)
/* 0D0218 7F09B6A8 8C780000 */  lw    $t8, ($v1)
/* 0D021C 7F09B6AC E7000550 */  swc1  $f0, 0x550($t8)
/* 0D0220 7F09B6B0 8C6B0000 */  lw    $t3, ($v1)
/* 0D0224 7F09B6B4 E5600554 */  swc1  $f0, 0x554($t3)
/* 0D0228 7F09B6B8 8C6F0000 */  lw    $t7, ($v1)
/* 0D022C 7F09B6BC E5E00558 */  swc1  $f0, 0x558($t7)
/* 0D0230 7F09B6C0 8C6E0000 */  lw    $t6, ($v1)
/* 0D0234 7F09B6C4 E5C0055C */  swc1  $f0, 0x55c($t6)
/* 0D0238 7F09B6C8 8C6C0000 */  lw    $t4, ($v1)
/* 0D023C 7F09B6CC E5800560 */  swc1  $f0, 0x560($t4)
/* 0D0240 7F09B6D0 8C6D0000 */  lw    $t5, ($v1)
/* 0D0244 7F09B6D4 E5A00564 */  swc1  $f0, 0x564($t5)
/* 0D0248 7F09B6D8 8C790000 */  lw    $t9, ($v1)
/* 0D024C 7F09B6DC E7200568 */  swc1  $f0, 0x568($t9)
/* 0D0250 7F09B6E0 8C780000 */  lw    $t8, ($v1)
/* 0D0254 7F09B6E4 E702056C */  swc1  $f2, 0x56c($t8)
/* 0D0258 7F09B6E8 8C6B0000 */  lw    $t3, ($v1)
/* 0D025C 7F09B6EC E5600570 */  swc1  $f0, 0x570($t3)
/* 0D0260 7F09B6F0 8C6F0000 */  lw    $t7, ($v1)
/* 0D0264 7F09B6F4 E5E00574 */  swc1  $f0, 0x574($t7)
/* 0D0268 7F09B6F8 8C6E0000 */  lw    $t6, ($v1)
/* 0D026C 7F09B6FC E5C20578 */  swc1  $f2, 0x578($t6)
/* 0D0270 7F09B700 8C6C0000 */  lw    $t4, ($v1)
/* 0D0274 7F09B704 E580057C */  swc1  $f0, 0x57c($t4)
/* 0D0278 7F09B708 8C6D0000 */  lw    $t5, ($v1)
/* 0D027C 7F09B70C E5A20580 */  swc1  $f2, 0x580($t5)
/* 0D0280 7F09B710 8C790000 */  lw    $t9, ($v1)
/* 0D0284 7F09B714 E7200584 */  swc1  $f0, 0x584($t9)
/* 0D0288 7F09B718 8C780000 */  lw    $t8, ($v1)
/* 0D028C 7F09B71C E7000588 */  swc1  $f0, 0x588($t8)
/* 0D0290 7F09B720 8C6B0000 */  lw    $t3, ($v1)
/* 0D0294 7F09B724 E562058C */  swc1  $f2, 0x58c($t3)
/* 0D0298 7F09B728 8C6F0000 */  lw    $t7, ($v1)
/* 0D029C 7F09B72C E5E00590 */  swc1  $f0, 0x590($t7)
/* 0D02A0 7F09B730 8C6E0000 */  lw    $t6, ($v1)
/* 0D02A4 7F09B734 ADC00594 */  sw    $zero, 0x594($t6)
.L7F09B738:
/* 0D02A8 7F09B738 8C6C0000 */  lw    $t4, ($v1)
/* 0D02AC 7F09B73C 01826821 */  addu  $t5, $t4, $v0
/* 0D02B0 7F09B740 A5A407D0 */  sh    $a0, 0x7d0($t5)
/* 0D02B4 7F09B744 8C790000 */  lw    $t9, ($v1)
/* 0D02B8 7F09B748 0322C021 */  addu  $t8, $t9, $v0
/* 0D02BC 7F09B74C A70507D2 */  sh    $a1, 0x7d2($t8)
/* 0D02C0 7F09B750 8C6B0000 */  lw    $t3, ($v1)
/* 0D02C4 7F09B754 01627821 */  addu  $t7, $t3, $v0
/* 0D02C8 7F09B758 A5E607D4 */  sh    $a2, 0x7d4($t7)
/* 0D02CC 7F09B75C 8C6E0000 */  lw    $t6, ($v1)
/* 0D02D0 7F09B760 01C26021 */  addu  $t4, $t6, $v0
/* 0D02D4 7F09B764 A58007D6 */  sh    $zero, 0x7d6($t4)
/* 0D02D8 7F09B768 8C6D0000 */  lw    $t5, ($v1)
/* 0D02DC 7F09B76C 01A2C821 */  addu  $t9, $t5, $v0
/* 0D02E0 7F09B770 A72407D8 */  sh    $a0, 0x7d8($t9)
/* 0D02E4 7F09B774 8C780000 */  lw    $t8, ($v1)
/* 0D02E8 7F09B778 03025821 */  addu  $t3, $t8, $v0
/* 0D02EC 7F09B77C A56507DA */  sh    $a1, 0x7da($t3)
/* 0D02F0 7F09B780 8C6F0000 */  lw    $t7, ($v1)
/* 0D02F4 7F09B784 01E27021 */  addu  $t6, $t7, $v0
/* 0D02F8 7F09B788 A5C607DC */  sh    $a2, 0x7dc($t6)
/* 0D02FC 7F09B78C 8C6C0000 */  lw    $t4, ($v1)
/* 0D0300 7F09B790 01826821 */  addu  $t5, $t4, $v0
/* 0D0304 7F09B794 24420010 */  addiu $v0, $v0, 0x10
/* 0D0308 7F09B798 1447FFE7 */  bne   $v0, $a3, .L7F09B738
/* 0D030C 7F09B79C A5A007DE */   sh    $zero, 0x7de($t5)
/* 0D0310 7F09B7A0 8C790000 */  lw    $t9, ($v1)
/* 0D0314 7F09B7A4 24020064 */  li    $v0, 100
/* 0D0318 7F09B7A8 A72207F0 */  sh    $v0, 0x7f0($t9)
/* 0D031C 7F09B7AC 8C780000 */  lw    $t8, ($v1)
/* 0D0320 7F09B7B0 A70207F2 */  sh    $v0, 0x7f2($t8)
/* 0D0324 7F09B7B4 8C6B0000 */  lw    $t3, ($v1)
/* 0D0328 7F09B7B8 A56007F4 */  sh    $zero, 0x7f4($t3)
/* 0D032C 7F09B7BC 8C6F0000 */  lw    $t7, ($v1)
/* 0D0330 7F09B7C0 A5E007F6 */  sh    $zero, 0x7f6($t7)
/* 0D0334 7F09B7C4 8C6E0000 */  lw    $t6, ($v1)
/* 0D0338 7F09B7C8 ADC007F8 */  sw    $zero, 0x7f8($t6)
/* 0D033C 7F09B7CC 8C6C0000 */  lw    $t4, ($v1)
/* 0D0340 7F09B7D0 AD8007FC */  sw    $zero, 0x7fc($t4)
/* 0D0344 7F09B7D4 8C6D0000 */  lw    $t5, ($v1)
/* 0D0348 7F09B7D8 ADA00800 */  sw    $zero, 0x800($t5)
/* 0D034C 7F09B7DC 8C790000 */  lw    $t9, ($v1)
/* 0D0350 7F09B7E0 AF200804 */  sw    $zero, 0x804($t9)
/* 0D0354 7F09B7E4 8C780000 */  lw    $t8, ($v1)
/* 0D0358 7F09B7E8 AF092A44 */  sw    $t1, 0x2a44($t8)
/* 0D035C 7F09B7EC 8C6B0000 */  lw    $t3, ($v1)
/* 0D0360 7F09B7F0 0140C025 */  move  $t8, $t2
/* 0D0364 7F09B7F4 AD692A48 */  sw    $t1, 0x2a48($t3)
/* 0D0368 7F09B7F8 8C6F0000 */  lw    $t7, ($v1)
/* 0D036C 7F09B7FC 254B03A8 */  addiu $t3, $t2, 0x3a8
/* 0D0370 7F09B800 ADE02A50 */  sw    $zero, 0x2a50($t7)
/* 0D0374 7F09B804 8C6E0000 */  lw    $t6, ($v1)
/* 0D0378 7F09B808 01407825 */  move  $t7, $t2
/* 0D037C 7F09B80C ADC02A54 */  sw    $zero, 0x2a54($t6)
/* 0D0380 7F09B810 8C6C0000 */  lw    $t4, ($v1)
/* 0D0384 7F09B814 AD800808 */  sw    $zero, 0x808($t4)
/* 0D0388 7F09B818 8C6D0000 */  lw    $t5, ($v1)
/* 0D038C 7F09B81C ADA0080C */  sw    $zero, 0x80c($t5)
/* 0D0390 7F09B820 8C790000 */  lw    $t9, ($v1)
.L7F09B824:
/* 0D0394 7F09B824 8DE10000 */  lw    $at, ($t7)
/* 0D0398 7F09B828 25EF000C */  addiu $t7, $t7, 0xc
/* 0D039C 7F09B82C 2739000C */  addiu $t9, $t9, 0xc
/* 0D03A0 7F09B830 AF210864 */  sw    $at, 0x864($t9)
/* 0D03A4 7F09B834 8DE1FFF8 */  lw    $at, -8($t7)
/* 0D03A8 7F09B838 AF210868 */  sw    $at, 0x868($t9)
/* 0D03AC 7F09B83C 8DE1FFFC */  lw    $at, -4($t7)
/* 0D03B0 7F09B840 15EBFFF8 */  bne   $t7, $t3, .L7F09B824
/* 0D03B4 7F09B844 AF21086C */   sw    $at, 0x86c($t9)
/* 0D03B8 7F09B848 8C6E0000 */  lw    $t6, ($v1)
/* 0D03BC 7F09B84C 254D03A8 */  addiu $t5, $t2, 0x3a8
.L7F09B850:
/* 0D03C0 7F09B850 8F010000 */  lw    $at, ($t8)
/* 0D03C4 7F09B854 2718000C */  addiu $t8, $t8, 0xc
/* 0D03C8 7F09B858 25CE000C */  addiu $t6, $t6, 0xc
/* 0D03CC 7F09B85C ADC10C0C */  sw    $at, 0xc0c($t6)
/* 0D03D0 7F09B860 8F01FFF8 */  lw    $at, -8($t8)
/* 0D03D4 7F09B864 ADC10C10 */  sw    $at, 0xc10($t6)
/* 0D03D8 7F09B868 8F01FFFC */  lw    $at, -4($t8)
/* 0D03DC 7F09B86C 170DFFF8 */  bne   $t8, $t5, .L7F09B850
/* 0D03E0 7F09B870 ADC10C14 */   sw    $at, 0xc14($t6)
/* 0D03E4 7F09B874 8C6B0000 */  lw    $t3, ($v1)
/* 0D03E8 7F09B878 3C018005 */  lui   $at, %hi(D_80057620) # $at, 0x8005
/* 0D03EC 7F09B87C 240200FF */  li    $v0, 255
/* 0D03F0 7F09B880 E5620FC0 */  swc1  $f2, 0xfc0($t3)
/* 0D03F4 7F09B884 8C6F0000 */  lw    $t7, ($v1)
/* 0D03F8 7F09B888 24040007 */  li    $a0, 7
/* 0D03FC 7F09B88C E5E20FC4 */  swc1  $f2, 0xfc4($t7)
/* 0D0400 7F09B890 8C790000 */  lw    $t9, ($v1)
/* 0D0404 7F09B894 AF200FC8 */  sw    $zero, 0xfc8($t9)
/* 0D0408 7F09B898 8C6C0000 */  lw    $t4, ($v1)
/* 0D040C 7F09B89C AD800FCC */  sw    $zero, 0xfcc($t4)
/* 0D0410 7F09B8A0 8C6D0000 */  lw    $t5, ($v1)
/* 0D0414 7F09B8A4 C42C7650 */  lwc1  $f12, %lo(D_80057620)($at)
/* 0D0418 7F09B8A8 3C014270 */  li    $at, 0x42700000 # 60.000000
/* 0D041C 7F09B8AC ADA00FD0 */  sw    $zero, 0xfd0($t5)
/* 0D0420 7F09B8B0 8C780000 */  lw    $t8, ($v1)
/* 0D0424 7F09B8B4 AF000FD4 */  sw    $zero, 0xfd4($t8)
/* 0D0428 7F09B8B8 8C6E0000 */  lw    $t6, ($v1)
/* 0D042C 7F09B8BC ADC00FD8 */  sw    $zero, 0xfd8($t6)
/* 0D0430 7F09B8C0 8C6B0000 */  lw    $t3, ($v1)
/* 0D0434 7F09B8C4 A1620FDC */  sb    $v0, 0xfdc($t3)
/* 0D0438 7F09B8C8 8C6F0000 */  lw    $t7, ($v1)
/* 0D043C 7F09B8CC A1E20FDD */  sb    $v0, 0xfdd($t7)
/* 0D0440 7F09B8D0 8C790000 */  lw    $t9, ($v1)
/* 0D0444 7F09B8D4 A3220FDE */  sb    $v0, 0xfde($t9)
/* 0D0448 7F09B8D8 8C6C0000 */  lw    $t4, ($v1)
/* 0D044C 7F09B8DC 3C028008 */  lui   $v0, %hi(random_byte) # $v0, 0x8008
/* 0D0450 7F09B8E0 2442A12C */  addiu $v0, %lo(random_byte) # addiu $v0, $v0, -0x5ed4
/* 0D0454 7F09B8E4 A1800FDF */  sb    $zero, 0xfdf($t4)
/* 0D0458 7F09B8E8 8C6D0000 */  lw    $t5, ($v1)
/* 0D045C 7F09B8EC ADA80FE0 */  sw    $t0, 0xfe0($t5)
/* 0D0460 7F09B8F0 8C780000 */  lw    $t8, ($v1)
/* 0D0464 7F09B8F4 AF000FE4 */  sw    $zero, 0xfe4($t8)
/* 0D0468 7F09B8F8 8C6E0000 */  lw    $t6, ($v1)
/* 0D046C 7F09B8FC E5C00FE8 */  swc1  $f0, 0xfe8($t6)
/* 0D0470 7F09B900 8C6B0000 */  lw    $t3, ($v1)
/* 0D0474 7F09B904 E5600FEC */  swc1  $f0, 0xfec($t3)
/* 0D0478 7F09B908 8C6F0000 */  lw    $t7, ($v1)
/* 0D047C 7F09B90C E5E00FF0 */  swc1  $f0, 0xff0($t7)
/* 0D0480 7F09B910 8C790000 */  lw    $t9, ($v1)
/* 0D0484 7F09B914 E7200FF4 */  swc1  $f0, 0xff4($t9)
/* 0D0488 7F09B918 8C6C0000 */  lw    $t4, ($v1)
/* 0D048C 7F09B91C E58C0FF8 */  swc1  $f12, 0xff8($t4)
/* 0D0490 7F09B920 8C6D0000 */  lw    $t5, ($v1)
/* 0D0494 7F09B924 E5A00FFC */  swc1  $f0, 0xffc($t5)
/* 0D0498 7F09B928 8C780000 */  lw    $t8, ($v1)
/* 0D049C 7F09B92C E7001000 */  swc1  $f0, 0x1000($t8)
/* 0D04A0 7F09B930 8C6E0000 */  lw    $t6, ($v1)
/* 0D04A4 7F09B934 E5C01004 */  swc1  $f0, 0x1004($t6)
/* 0D04A8 7F09B938 8C6B0000 */  lw    $t3, ($v1)
/* 0D04AC 7F09B93C E5601008 */  swc1  $f0, 0x1008($t3)
/* 0D04B0 7F09B940 8C6F0000 */  lw    $t7, ($v1)
/* 0D04B4 7F09B944 E5EC100C */  swc1  $f12, 0x100c($t7)
/* 0D04B8 7F09B948 44816000 */  mtc1  $at, $f12
/* 0D04BC 7F09B94C 8C790000 */  lw    $t9, ($v1)
/* 0D04C0 7F09B950 3C0143A0 */  li    $at, 0x43A00000 # 320.000000
/* 0D04C4 7F09B954 44817000 */  mtc1  $at, $f14
/* 0D04C8 7F09B958 3C014370 */  li    $at, 0x43700000 # 240.000000
/* 0D04CC 7F09B95C 44818000 */  mtc1  $at, $f16
/* 0D04D0 7F09B960 E7201010 */  swc1  $f0, 0x1010($t9)
/* 0D04D4 7F09B964 3C018005 */  lui   $at, %hi(D_80057624) # $at, 0x8005
/* 0D04D8 7F09B968 C4247654 */  lwc1  $f4, %lo(D_80057624)($at)
/* 0D04DC 7F09B96C 8C6C0000 */  lw    $t4, ($v1)
/* 0D04E0 7F09B970 3C014120 */  li    $at, 0x41200000 # 10.000000
/* 0D04E4 7F09B974 44813000 */  mtc1  $at, $f6
/* 0D04E8 7F09B978 E5841014 */  swc1  $f4, 0x1014($t4)
/* 0D04EC 7F09B97C 8C6D0000 */  lw    $t5, ($v1)
/* 0D04F0 7F09B980 3C014238 */  li    $at, 0x42380000 # 46.000000
/* 0D04F4 7F09B984 44814000 */  mtc1  $at, $f8
/* 0D04F8 7F09B988 E5A01018 */  swc1  $f0, 0x1018($t5)
/* 0D04FC 7F09B98C 8C780000 */  lw    $t8, ($v1)
/* 0D0500 7F09B990 3C014320 */  li    $at, 0x43200000 # 160.000000
/* 0D0504 7F09B994 44815000 */  mtc1  $at, $f10
/* 0D0508 7F09B998 AF00105C */  sw    $zero, 0x105c($t8)
/* 0D050C 7F09B99C 8C6E0000 */  lw    $t6, ($v1)
/* 0D0510 7F09B9A0 3C0142F0 */  li    $at, 0x42F00000 # 120.000000
/* 0D0514 7F09B9A4 44819000 */  mtc1  $at, $f18
/* 0D0518 7F09B9A8 ADC01060 */  sw    $zero, 0x1060($t6)
/* 0D051C 7F09B9AC 8C6B0000 */  lw    $t3, ($v1)
/* 0D0520 7F09B9B0 3C018005 */  lui   $at, %hi(D_80057628) # $at, 0x8005
/* 0D0524 7F09B9B4 AD601064 */  sw    $zero, 0x1064($t3)
/* 0D0528 7F09B9B8 8C6F0000 */  lw    $t7, ($v1)
/* 0D052C 7F09B9BC E5E0106C */  swc1  $f0, 0x106c($t7)
/* 0D0530 7F09B9C0 8C790000 */  lw    $t9, ($v1)
/* 0D0534 7F09B9C4 E7201070 */  swc1  $f0, 0x1070($t9)
/* 0D0538 7F09B9C8 8C6C0000 */  lw    $t4, ($v1)
/* 0D053C 7F09B9CC E5801074 */  swc1  $f0, 0x1074($t4)
/* 0D0540 7F09B9D0 8C6D0000 */  lw    $t5, ($v1)
/* 0D0544 7F09B9D4 ADA01078 */  sw    $zero, 0x1078($t5)
/* 0D0548 7F09B9D8 8C780000 */  lw    $t8, ($v1)
/* 0D054C 7F09B9DC E700107C */  swc1  $f0, 0x107c($t8)
/* 0D0550 7F09B9E0 8C6E0000 */  lw    $t6, ($v1)
/* 0D0554 7F09B9E4 E5C01080 */  swc1  $f0, 0x1080($t6)
/* 0D0558 7F09B9E8 8C6B0000 */  lw    $t3, ($v1)
/* 0D055C 7F09B9EC E56C1084 */  swc1  $f12, 0x1084($t3)
/* 0D0560 7F09B9F0 8C6F0000 */  lw    $t7, ($v1)
/* 0D0564 7F09B9F4 E5EC1088 */  swc1  $f12, 0x1088($t7)
/* 0D0568 7F09B9F8 8C790000 */  lw    $t9, ($v1)
/* 0D056C 7F09B9FC AF29108C */  sw    $t1, 0x108c($t9)
/* 0D0570 7F09BA00 8C6C0000 */  lw    $t4, ($v1)
/* 0D0574 7F09BA04 E58E1090 */  swc1  $f14, 0x1090($t4)
/* 0D0578 7F09BA08 8C6D0000 */  lw    $t5, ($v1)
/* 0D057C 7F09BA0C E5B01094 */  swc1  $f16, 0x1094($t5)
/* 0D0580 7F09BA10 8C780000 */  lw    $t8, ($v1)
/* 0D0584 7F09BA14 E7001098 */  swc1  $f0, 0x1098($t8)
/* 0D0588 7F09BA18 8C6E0000 */  lw    $t6, ($v1)
/* 0D058C 7F09BA1C E5C0109C */  swc1  $f0, 0x109c($t6)
/* 0D0590 7F09BA20 8C6B0000 */  lw    $t3, ($v1)
/* 0D0594 7F09BA24 E56610A0 */  swc1  $f6, 0x10a0($t3)
/* 0D0598 7F09BA28 8C6F0000 */  lw    $t7, ($v1)
/* 0D059C 7F09BA2C E5E810A4 */  swc1  $f8, 0x10a4($t7)
/* 0D05A0 7F09BA30 8C790000 */  lw    $t9, ($v1)
/* 0D05A4 7F09BA34 E72210A8 */  swc1  $f2, 0x10a8($t9)
/* 0D05A8 7F09BA38 8C6C0000 */  lw    $t4, ($v1)
/* 0D05AC 7F09BA3C E58A10AC */  swc1  $f10, 0x10ac($t4)
/* 0D05B0 7F09BA40 8C6D0000 */  lw    $t5, ($v1)
/* 0D05B4 7F09BA44 E5B210B0 */  swc1  $f18, 0x10b0($t5)
/* 0D05B8 7F09BA48 8C780000 */  lw    $t8, ($v1)
/* 0D05BC 7F09BA4C E70210B4 */  swc1  $f2, 0x10b4($t8)
/* 0D05C0 7F09BA50 8C6E0000 */  lw    $t6, ($v1)
/* 0D05C4 7F09BA54 E5C210B8 */  swc1  $f2, 0x10b8($t6)
/* 0D05C8 7F09BA58 8C6B0000 */  lw    $t3, ($v1)
/* 0D05CC 7F09BA5C E56210BC */  swc1  $f2, 0x10bc($t3)
/* 0D05D0 7F09BA60 8C6F0000 */  lw    $t7, ($v1)
/* 0D05D4 7F09BA64 E5E210C0 */  swc1  $f2, 0x10c0($t7)
/* 0D05D8 7F09BA68 8C790000 */  lw    $t9, ($v1)
/* 0D05DC 7F09BA6C AF2010C4 */  sw    $zero, 0x10c4($t9)
/* 0D05E0 7F09BA70 8C6C0000 */  lw    $t4, ($v1)
/* 0D05E4 7F09BA74 AD8010C8 */  sw    $zero, 0x10c8($t4)
/* 0D05E8 7F09BA78 8C6D0000 */  lw    $t5, ($v1)
/* 0D05EC 7F09BA7C ADA010CC */  sw    $zero, 0x10cc($t5)
/* 0D05F0 7F09BA80 8C780000 */  lw    $t8, ($v1)
/* 0D05F4 7F09BA84 AF0010D0 */  sw    $zero, 0x10d0($t8)
/* 0D05F8 7F09BA88 8C6E0000 */  lw    $t6, ($v1)
/* 0D05FC 7F09BA8C ADC010D4 */  sw    $zero, 0x10d4($t6)
/* 0D0600 7F09BA90 8C6B0000 */  lw    $t3, ($v1)
/* 0D0604 7F09BA94 AD6010D8 */  sw    $zero, 0x10d8($t3)
/* 0D0608 7F09BA98 8C6F0000 */  lw    $t7, ($v1)
/* 0D060C 7F09BA9C ADE010DC */  sw    $zero, 0x10dc($t7)
/* 0D0610 7F09BAA0 8C790000 */  lw    $t9, ($v1)
/* 0D0614 7F09BAA4 AF2010E0 */  sw    $zero, 0x10e0($t9)
/* 0D0618 7F09BAA8 8C6C0000 */  lw    $t4, ($v1)
/* 0D061C 7F09BAAC 3C190001 */  lui   $t9, 1
/* 0D0620 7F09BAB0 AD8010E4 */  sw    $zero, 0x10e4($t4)
/* 0D0624 7F09BAB4 8C6D0000 */  lw    $t5, ($v1)
/* 0D0628 7F09BAB8 ADA010E8 */  sw    $zero, 0x10e8($t5)
/* 0D062C 7F09BABC 8C780000 */  lw    $t8, ($v1)
/* 0D0630 7F09BAC0 AF0010EC */  sw    $zero, 0x10ec($t8)
/* 0D0634 7F09BAC4 8C6E0000 */  lw    $t6, ($v1)
/* 0D0638 7F09BAC8 E5C210F0 */  swc1  $f2, 0x10f0($t6)
/* 0D063C 7F09BACC 8C6B0000 */  lw    $t3, ($v1)
/* 0D0640 7F09BAD0 E56210F4 */  swc1  $f2, 0x10f4($t3)
/* 0D0644 7F09BAD4 8C6F0000 */  lw    $t7, ($v1)
/* 0D0648 7F09BAD8 E5E210F8 */  swc1  $f2, 0x10f8($t7)
/* 0D064C 7F09BADC 8C6C0000 */  lw    $t4, ($v1)
/* 0D0650 7F09BAE0 AD9910FC */  sw    $t9, 0x10fc($t4)
/* 0D0654 7F09BAE4 8C6D0000 */  lw    $t5, ($v1)
/* 0D0658 7F09BAE8 E5A01118 */  swc1  $f0, 0x1118($t5)
/* 0D065C 7F09BAEC 8C780000 */  lw    $t8, ($v1)
/* 0D0660 7F09BAF0 E700111C */  swc1  $f0, 0x111c($t8)
/* 0D0664 7F09BAF4 8C6E0000 */  lw    $t6, ($v1)
/* 0D0668 7F09BAF8 E5CE1120 */  swc1  $f14, 0x1120($t6)
/* 0D066C 7F09BAFC 8C6B0000 */  lw    $t3, ($v1)
/* 0D0670 7F09BB00 E5701124 */  swc1  $f16, 0x1124($t3)
/* 0D0674 7F09BB04 8C6F0000 */  lw    $t7, ($v1)
/* 0D0678 7F09BB08 ADE01128 */  sw    $zero, 0x1128($t7)
/* 0D067C 7F09BB0C 8C790000 */  lw    $t9, ($v1)
/* 0D0680 7F09BB10 AF2011B0 */  sw    $zero, 0x11b0($t9)
/* 0D0684 7F09BB14 8C6C0000 */  lw    $t4, ($v1)
/* 0D0688 7F09BB18 AD8011B4 */  sw    $zero, 0x11b4($t4)
/* 0D068C 7F09BB1C 8C6D0000 */  lw    $t5, ($v1)
/* 0D0690 7F09BB20 ADA011B8 */  sw    $zero, 0x11b8($t5)
/* 0D0694 7F09BB24 8C780000 */  lw    $t8, ($v1)
/* 0D0698 7F09BB28 E70011BC */  swc1  $f0, 0x11bc($t8)
/* 0D069C 7F09BB2C 8C6E0000 */  lw    $t6, ($v1)
/* 0D06A0 7F09BB30 E5C011C0 */  swc1  $f0, 0x11c0($t6)
/* 0D06A4 7F09BB34 8C6B0000 */  lw    $t3, ($v1)
/* 0D06A8 7F09BB38 E56C11C4 */  swc1  $f12, 0x11c4($t3)
/* 0D06AC 7F09BB3C 8C6F0000 */  lw    $t7, ($v1)
/* 0D06B0 7F09BB40 E5EC11C8 */  swc1  $f12, 0x11c8($t7)
/* 0D06B4 7F09BB44 8C790000 */  lw    $t9, ($v1)
/* 0D06B8 7F09BB48 E72C11CC */  swc1  $f12, 0x11cc($t9)
/* 0D06BC 7F09BB4C 8C6C0000 */  lw    $t4, ($v1)
/* 0D06C0 7F09BB50 E58C11D0 */  swc1  $f12, 0x11d0($t4)
/* 0D06C4 7F09BB54 8C6D0000 */  lw    $t5, ($v1)
/* 0D06C8 7F09BB58 C4247658 */  lwc1  $f4, %lo(D_80057628)($at)
/* 0D06CC 7F09BB5C 3C018003 */  lui   $at, %hi(invisible_to_guards_flag) # $at, 0x8003
/* 0D06D0 7F09BB60 E5A411D4 */  swc1  $f4, 0x11d4($t5)
/* 0D06D4 7F09BB64 8C780000 */  lw    $t8, ($v1)
/* 0D06D8 7F09BB68 AF0011D8 */  sw    $zero, 0x11d8($t8)
/* 0D06DC 7F09BB6C 8C6E0000 */  lw    $t6, ($v1)
/* 0D06E0 7F09BB70 ADC911DC */  sw    $t1, 0x11dc($t6)
/* 0D06E4 7F09BB74 8C6B0000 */  lw    $t3, ($v1)
/* 0D06E8 7F09BB78 AD6011E0 */  sw    $zero, 0x11e0($t3)
/* 0D06EC 7F09BB7C 8C6F0000 */  lw    $t7, ($v1)
/* 0D06F0 7F09BB80 ADE011E4 */  sw    $zero, 0x11e4($t7)
/* 0D06F4 7F09BB84 8C790000 */  lw    $t9, ($v1)
/* 0D06F8 7F09BB88 AF2011E8 */  sw    $zero, 0x11e8($t9)
/* 0D06FC 7F09BB8C 8C6C0000 */  lw    $t4, ($v1)
/* 0D0700 7F09BB90 AD8011EC */  sw    $zero, 0x11ec($t4)
/* 0D0704 7F09BB94 8C6D0000 */  lw    $t5, ($v1)
/* 0D0708 7F09BB98 ADA011F0 */  sw    $zero, 0x11f0($t5)
/* 0D070C 7F09BB9C 8C780000 */  lw    $t8, ($v1)
/* 0D0710 7F09BBA0 AF0011F4 */  sw    $zero, 0x11f4($t8)
/* 0D0714 7F09BBA4 8C6E0000 */  lw    $t6, ($v1)
/* 0D0718 7F09BBA8 E5C01280 */  swc1  $f0, 0x1280($t6)
/* 0D071C 7F09BBAC 8C6B0000 */  lw    $t3, ($v1)
/* 0D0720 7F09BBB0 AD601284 */  sw    $zero, 0x1284($t3)
/* 0D0724 7F09BBB4 8C6F0000 */  lw    $t7, ($v1)
/* 0D0728 7F09BBB8 E5E01288 */  swc1  $f0, 0x1288($t7)
/* 0D072C 7F09BBBC 8C790000 */  lw    $t9, ($v1)
/* 0D0730 7F09BBC0 A32012B6 */  sb    $zero, 0x12b6($t9)
/* 0D0734 7F09BBC4 8C6C0000 */  lw    $t4, ($v1)
/* 0D0738 7F09BBC8 AD8429B8 */  sw    $a0, 0x29b8($t4)
/* 0D073C 7F09BBCC 8C6D0000 */  lw    $t5, ($v1)
/* 0D0740 7F09BBD0 E5A229BC */  swc1  $f2, 0x29bc($t5)
/* 0D0744 7F09BBD4 8C780000 */  lw    $t8, ($v1)
/* 0D0748 7F09BBD8 E70029C0 */  swc1  $f0, 0x29c0($t8)
/* 0D074C 7F09BBDC 8C6E0000 */  lw    $t6, ($v1)
/* 0D0750 7F09BBE0 ADC029C4 */  sw    $zero, 0x29c4($t6)
/* 0D0754 7F09BBE4 8C6B0000 */  lw    $t3, ($v1)
/* 0D0758 7F09BBE8 AD6429D4 */  sw    $a0, 0x29d4($t3)
/* 0D075C 7F09BBEC 8C6F0000 */  lw    $t7, ($v1)
/* 0D0760 7F09BBF0 ADE029D8 */  sw    $zero, 0x29d8($t7)
/* 0D0764 7F09BBF4 8C6C0000 */  lw    $t4, ($v1)
/* 0D0768 7F09BBF8 8C590000 */  lw    $t9, ($v0)
/* 0D076C 7F09BBFC AD9929E0 */  sw    $t9, 0x29e0($t4)
/* 0D0770 7F09BC00 8C4D0000 */  lw    $t5, ($v0)
/* 0D0774 7F09BC04 8C6E0000 */  lw    $t6, ($v1)
/* 0D0778 7F09BC08 25B80001 */  addiu $t8, $t5, 1
/* 0D077C 7F09BC0C AC580000 */  sw    $t8, ($v0)
/* 0D0780 7F09BC10 ADC929E4 */  sw    $t1, 0x29e4($t6)
/* 0D0784 7F09BC14 8C6B0000 */  lw    $t3, ($v1)
/* 0D0788 7F09BC18 AD6929E8 */  sw    $t1, 0x29e8($t3)
/* 0D078C 7F09BC1C 8C6F0000 */  lw    $t7, ($v1)
/* 0D0790 7F09BC20 ADE929EC */  sw    $t1, 0x29ec($t7)
/* 0D0794 7F09BC24 8C790000 */  lw    $t9, ($v1)
/* 0D0798 7F09BC28 AF2929F0 */  sw    $t1, 0x29f0($t9)
/* 0D079C 7F09BC2C 8C6C0000 */  lw    $t4, ($v1)
/* 0D07A0 7F09BC30 AD802A00 */  sw    $zero, 0x2a00($t4)
/* 0D07A4 7F09BC34 8C6D0000 */  lw    $t5, ($v1)
/* 0D07A8 7F09BC38 ADA02A30 */  sw    $zero, 0x2a30($t5)
/* 0D07AC 7F09BC3C 8C780000 */  lw    $t8, ($v1)
/* 0D07B0 7F09BC40 AF002A34 */  sw    $zero, 0x2a34($t8)
/* 0D07B4 7F09BC44 8C6E0000 */  lw    $t6, ($v1)
/* 0D07B8 7F09BC48 ADC82A38 */  sw    $t0, 0x2a38($t6)
/* 0D07BC 7F09BC4C 8C6B0000 */  lw    $t3, ($v1)
/* 0D07C0 7F09BC50 E5622A3C */  swc1  $f2, 0x2a3c($t3)
/* 0D07C4 7F09BC54 8C6F0000 */  lw    $t7, ($v1)
/* 0D07C8 7F09BC58 E5E22A40 */  swc1  $f2, 0x2a40($t7)
/* 0D07CC 7F09BC5C 8C790000 */  lw    $t9, ($v1)
/* 0D07D0 7F09BC60 AF202A58 */  sw    $zero, 0x2a58($t9)
/* 0D07D4 7F09BC64 8C6C0000 */  lw    $t4, ($v1)
/* 0D07D8 7F09BC68 AD802A5C */  sw    $zero, 0x2a5c($t4)
/* 0D07DC 7F09BC6C 8C6D0000 */  lw    $t5, ($v1)
/* 0D07E0 7F09BC70 E5A02A60 */  swc1  $f0, 0x2a60($t5)
/* 0D07E4 7F09BC74 8C780000 */  lw    $t8, ($v1)
/* 0D07E8 7F09BC78 AF002A64 */  sw    $zero, 0x2a64($t8)
/* 0D07EC 7F09BC7C 8C6E0000 */  lw    $t6, ($v1)
/* 0D07F0 7F09BC80 ADC82A68 */  sw    $t0, 0x2a68($t6)
/* 0D07F4 7F09BC84 8C6B0000 */  lw    $t3, ($v1)
/* 0D07F8 7F09BC88 AD602A6C */  sw    $zero, 0x2a6c($t3)
/* 0D07FC 7F09BC8C 8C6F0000 */  lw    $t7, ($v1)
/* 0D0800 7F09BC90 ADE02A70 */  sw    $zero, 0x2a70($t7)
/* 0D0804 7F09BC94 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0D0808 7F09BC98 AC286504 */  sw    $t0, %lo(invisible_to_guards_flag)($at)
/* 0D080C 7F09BC9C 3C018003 */  lui   $at, %hi(obj_collision_flag) # $at, 0x8003
/* 0D0810 7F09BCA0 AC286508 */  sw    $t0, %lo(obj_collision_flag)($at)
/* 0D0814 7F09BCA4 03E00008 */  jr    $ra
/* 0D0818 7F09BCA8 27BD03D0 */   addiu $sp, $sp, 0x3d0  
)
#endif

#endif



#ifdef NONMATCHING
void set_cur_player(PLAYER_ID playernum)
{
    pPlayer = players[playernum];
    pPlayersPerm = player1_playerdata[playernum];
    player_num = playernum;
    return;
}
#else
GLOBAL_ASM(
.text
glabel set_cur_player
/* 0CFC3C 7F09B10C 00047080 */  sll   $t6, $a0, 2
/* 0CFC40 7F09B110 3C0F8008 */  lui   $t7, %hi(players)
/* 0CFC44 7F09B114 01EE7821 */  addu  $t7, $t7, $t6
/* 0CFC48 7F09B118 8DEF9EE0 */  lw    $t7, %lo(players)($t7)
/* 0CFC4C 7F09B11C 3C018008 */  lui   $at, %hi(player_num)
/* 0CFC50 7F09B120 AC24A0B8 */  sw    $a0, %lo(player_num)($at)
/* 0CFC54 7F09B124 0004C0C0 */  sll   $t8, $a0, 3
/* 0CFC58 7F09B128 3C018008 */  lui   $at, %hi(pPlayer)
/* 0CFC5C 7F09B12C 0304C023 */  subu  $t8, $t8, $a0
/* 0CFC60 7F09B130 3C198008 */  lui   $t9, %hi(player1_player_data) 
/* 0CFC64 7F09B134 27399EF0 */  addiu $t9, %lo(player1_player_data) # addiu $t9, $t9, -0x6110
/* 0CFC68 7F09B138 0018C100 */  sll   $t8, $t8, 4
/* 0CFC6C 7F09B13C AC2FA0B0 */  sw    $t7, %lo(pPlayer)($at)
/* 0CFC70 7F09B140 3C018008 */  lui   $at, %hi(pPlayersPerm)
/* 0CFC74 7F09B144 03194021 */  addu  $t0, $t8, $t9
/* 0CFC78 7F09B148 03E00008 */  jr    $ra
/* 0CFC7C 7F09B14C AC28A0B4 */   sw    $t0, %lo(pPlayersPerm)($at)
)
#endif




s32 get_cur_playernum(void) {
    return player_num;
}






#ifdef NONMATCHING
void proc_7F09B15C(int prop)
{
    player *pPVar1;
    s32 numplayers;
    player **ppPVar2;
    int i;
    
    i = 0;
    numplayers = getPlayerCount();
    if (0 < numplayers) {
        ppPVar2 = players;
        pPVar1 = players[0];
        while (ppPVar2 = ppPVar2 + 1, prop != pPVar1->prop) {
            i = i + 1;
            numplayers = getPlayerCount();
            if (numplayers <= i) {
                return;
            }
            pPVar1 = *ppPVar2;
        }
    }
    return;
}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F09B15C
/* 0CFC8C 7F09B15C 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 0CFC90 7F09B160 AFBF0024 */  sw    $ra, 0x24($sp)
/* 0CFC94 7F09B164 AFB20020 */  sw    $s2, 0x20($sp)
/* 0CFC98 7F09B168 AFB1001C */  sw    $s1, 0x1c($sp)
/* 0CFC9C 7F09B16C 00809025 */  move  $s2, $a0
/* 0CFCA0 7F09B170 AFB00018 */  sw    $s0, 0x18($sp)
/* 0CFCA4 7F09B174 0FC26919 */  jal   getPlayerCount
/* 0CFCA8 7F09B178 00008825 */   move  $s1, $zero
/* 0CFCAC 7F09B17C 18400010 */  blez  $v0, .L7F09B1C0
/* 0CFCB0 7F09B180 00117080 */   sll   $t6, $s1, 2
/* 0CFCB4 7F09B184 3C0F8008 */  lui   $t7, %hi(players) 
/* 0CFCB8 7F09B188 25EF9EE0 */  addiu $t7, %lo(players) # addiu $t7, $t7, -0x6120
/* 0CFCBC 7F09B18C 01CF8021 */  addu  $s0, $t6, $t7
/* 0CFCC0 7F09B190 8E180000 */  lw    $t8, ($s0)
.L7F09B194:
/* 0CFCC4 7F09B194 26100004 */  addiu $s0, $s0, 4
/* 0CFCC8 7F09B198 8F1900A8 */  lw    $t9, 0xa8($t8)
/* 0CFCCC 7F09B19C 16590003 */  bne   $s2, $t9, .L7F09B1AC
/* 0CFCD0 7F09B1A0 00000000 */   nop   
/* 0CFCD4 7F09B1A4 10000007 */  b     .L7F09B1C4
/* 0CFCD8 7F09B1A8 02201025 */   move  $v0, $s1
.L7F09B1AC:
/* 0CFCDC 7F09B1AC 0FC26919 */  jal   getPlayerCount
/* 0CFCE0 7F09B1B0 26310001 */   addiu $s1, $s1, 1
/* 0CFCE4 7F09B1B4 0222082A */  slt   $at, $s1, $v0
/* 0CFCE8 7F09B1B8 5420FFF6 */  bnezl $at, .L7F09B194
/* 0CFCEC 7F09B1BC 8E180000 */   lw    $t8, ($s0)
.L7F09B1C0:
/* 0CFCF0 7F09B1C0 2402FFFF */  li    $v0, -1
.L7F09B1C4:
/* 0CFCF4 7F09B1C4 8FBF0024 */  lw    $ra, 0x24($sp)
/* 0CFCF8 7F09B1C8 8FB00018 */  lw    $s0, 0x18($sp)
/* 0CFCFC 7F09B1CC 8FB1001C */  lw    $s1, 0x1c($sp)
/* 0CFD00 7F09B1D0 8FB20020 */  lw    $s2, 0x20($sp)
/* 0CFD04 7F09B1D4 03E00008 */  jr    $ra
/* 0CFD08 7F09B1D8 27BD0028 */   addiu $sp, $sp, 0x28
)
#endif





void set_cur_player_screen_size(u32 width, u32 height) {
  pPlayer->viewx = width;
  pPlayer->viewy = height;
}

void set_cur_player_viewport_size(u32 ulx, u32 uly) {
  pPlayer->viewleft = ulx;
  pPlayer->viewtop = uly;
}

void set_cur_player_fovy(f32 fovy) {
    pPlayer->fovy = fovy;
}

void set_cur_player_aspect(f32 aspect) {
    pPlayer->aspect = aspect;
}

f32 get_cur_player_fovy(void) {
    return pPlayer->fovy;
}






#ifdef NONMATCHING
void sub_GAME_7F09B244(void) {

}
#else
GLOBAL_ASM(
.late_rodata
/*D:8005762C*/
glabel jpt_weapon_multi
.word weapon_multi_none
.word weapon_multi_none
.word weapon_multi_hunting_knife
.word weapon_multi_throwing_knife
.word weapon_multi_pp7
.word weapon_multi_pp7_silent
.word weapon_multi_dd44
.word weapon_multi_klobb
.word weapon_multi_kf7
.word weapon_multi_zmg
.word weapon_multi_d5k
.word weapon_multi_d5k_silent
.word weapon_multi_phantom
.word weapon_multi_ar33
.word weapon_multi_rcp90
.word weapon_multi_shotgun
.word weapon_multi_auto_shot
.word weapon_multi_sniper
.word weapon_multi_cougar
.word weapon_multi_goldengun
.word weapon_multi_pp7_special1
.word weapon_multi_pp7_special2
.word weapon_multi_moonraker
/*.word weapon_multi_none*/
/*.word weapon_multi_grenade_laun*/
/*.word weapon_multi_rocket_launch*/
/*.word weapon_multi_hand*/
/*.word weapon_multi_timed*/
/*.word weapon_multi_prox*/
/*.word weapon_multi_remote*/
/*.word weapon_multi_none*/
/*.word weapon_multi_none*/

.text
glabel sub_GAME_7F09B244
/* 0CFD74 7F09B244 28810020 */  slti  $at, $a0, 0x20
/* 0CFD78 7F09B248 14200006 */  bnez  $at, .L7F09B264
/* 0CFD7C 7F09B24C 2403FFFF */   li    $v1, -1
/* 0CFD80 7F09B250 24010058 */  li    $at, 88
/* 0CFD84 7F09B254 50810042 */  beql  $a0, $at, .L7F09B360
/* 0CFD88 7F09B258 2403014D */   li    $v1, 333
/* 0CFD8C 7F09B25C 03E00008 */  jr    $ra
/* 0CFD90 7F09B260 00601025 */   move  $v0, $v1

.L7F09B264:
/* 0CFD94 7F09B264 2C810020 */  sltiu $at, $a0, 0x20
/* 0CFD98 7F09B268 1020003D */  beqz  $at, .L7F09B360
/* 0CFD9C 7F09B26C 00047080 */   sll   $t6, $a0, 2
/* 0CFDA0 7F09B270 3C018005 */  lui   $at, %hi(jpt_weapon_multi)
/* 0CFDA4 7F09B274 002E0821 */  addu  $at, $at, $t6
/* 0CFDA8 7F09B278 8C2E762C */  lw    $t6, %lo(jpt_weapon_multi)($at)
/* 0CFDAC 7F09B27C 01C00008 */  jr    $t6
/* 0CFDB0 7F09B280 00000000 */   nop   
weapon_multi_hunting_knife:
/* 0CFDB4 7F09B284 03E00008 */  jr    $ra
/* 0CFDB8 7F09B288 240200BA */   li    $v0, 186

weapon_multi_pp7:
/* 0CFDBC 7F09B28C 03E00008 */  jr    $ra
/* 0CFDC0 7F09B290 240200BF */   li    $v0, 191

weapon_multi_klobb:
/* 0CFDC4 7F09B294 03E00008 */  jr    $ra
/* 0CFDC8 7F09B298 240200C1 */   li    $v0, 193

weapon_multi_kf7:
/* 0CFDCC 7F09B29C 03E00008 */  jr    $ra
/* 0CFDD0 7F09B2A0 240200B8 */   li    $v0, 184

weapon_multi_zmg:
/* 0CFDD4 7F09B2A4 03E00008 */  jr    $ra
/* 0CFDD8 7F09B2A8 240200C3 */   li    $v0, 195

weapon_multi_d5k:
/* 0CFDDC 7F09B2AC 03E00008 */  jr    $ra
/* 0CFDE0 7F09B2B0 240200BD */   li    $v0, 189

weapon_multi_phantom:
/* 0CFDE4 7F09B2B4 03E00008 */  jr    $ra
/* 0CFDE8 7F09B2B8 240200C2 */   li    $v0, 194

weapon_multi_ar33:
/* 0CFDEC 7F09B2BC 03E00008 */  jr    $ra
/* 0CFDF0 7F09B2C0 240200BC */   li    $v0, 188

weapon_multi_rcp90:
/* 0CFDF4 7F09B2C4 03E00008 */  jr    $ra
/* 0CFDF8 7F09B2C8 240200C5 */   li    $v0, 197

weapon_multi_shotgun:
/* 0CFDFC 7F09B2CC 03E00008 */  jr    $ra
/* 0CFE00 7F09B2D0 240200C0 */   li    $v0, 192

weapon_multi_grenade_laun:
/* 0CFE04 7F09B2D4 03E00008 */  jr    $ra
/* 0CFE08 7F09B2D8 240200B9 */   li    $v0, 185

weapon_multi_hand:
/* 0CFE0C 7F09B2DC 03E00008 */  jr    $ra
/* 0CFE10 7F09B2E0 240200C4 */   li    $v0, 196

weapon_multi_remote:
/* 0CFE14 7F09B2E4 03E00008 */  jr    $ra
/* 0CFE18 7F09B2E8 240200C7 */   li    $v0, 199

weapon_multi_prox:
/* 0CFE1C 7F09B2EC 03E00008 */  jr    $ra
/* 0CFE20 7F09B2F0 240200C8 */   li    $v0, 200

weapon_multi_timed:
/* 0CFE24 7F09B2F4 03E00008 */  jr    $ra
/* 0CFE28 7F09B2F8 240200C9 */   li    $v0, 201

weapon_multi_cougar:
/* 0CFE2C 7F09B2FC 03E00008 */  jr    $ra
/* 0CFE30 7F09B300 240200BE */   li    $v0, 190

weapon_multi_moonraker:
/* 0CFE34 7F09B304 03E00008 */  jr    $ra
/* 0CFE38 7F09B308 240200BB */   li    $v0, 187

weapon_multi_sniper:
/* 0CFE3C 7F09B30C 03E00008 */  jr    $ra
/* 0CFE40 7F09B310 240200D2 */   li    $v0, 210

weapon_multi_d5k_silent:
/* 0CFE44 7F09B314 03E00008 */  jr    $ra
/* 0CFE48 7F09B318 240200CE */   li    $v0, 206

weapon_multi_dd44:
/* 0CFE4C 7F09B31C 03E00008 */  jr    $ra
/* 0CFE50 7F09B320 240200CD */   li    $v0, 205

weapon_multi_pp7_silent:
/* 0CFE54 7F09B324 03E00008 */  jr    $ra
/* 0CFE58 7F09B328 240200CC */   li    $v0, 204

weapon_multi_throwing_knife:
/* 0CFE5C 7F09B32C 03E00008 */  jr    $ra
/* 0CFE60 7F09B330 240200D1 */   li    $v0, 209

weapon_multi_auto_shot:
/* 0CFE64 7F09B334 03E00008 */  jr    $ra
/* 0CFE68 7F09B338 240200CF */   li    $v0, 207

weapon_multi_rocket_launch:
/* 0CFE6C 7F09B33C 03E00008 */  jr    $ra
/* 0CFE70 7F09B340 240200D3 */   li    $v0, 211

weapon_multi_goldengun:
/* 0CFE74 7F09B344 03E00008 */  jr    $ra
/* 0CFE78 7F09B348 240200D0 */   li    $v0, 208

weapon_multi_pp7_special1:
/* 0CFE7C 7F09B34C 03E00008 */  jr    $ra
/* 0CFE80 7F09B350 240200BF */   li    $v0, 191

weapon_multi_pp7_special2:
/* 0CFE84 7F09B354 03E00008 */  jr    $ra
/* 0CFE88 7F09B358 240200BF */   li    $v0, 191

/* 0CFE8C 7F09B35C 2403014D */  li    $v1, 333
weapon_multi_none:
.L7F09B360:
/* 0CFE90 7F09B360 03E00008 */  jr    $ra
/* 0CFE94 7F09B364 00601025 */   move  $v0, $v1
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F09B368(s32 arg0) {
    // Node 0
    return set_0x4_in_runtime_flags_for_item_in_guards_hand(pPlayer->unkA8->unk4, arg0);
}

#else
GLOBAL_ASM(
.late_rodata
/*hack for jtbl*/
.word weapon_multi_none
.word weapon_multi_grenade_laun
.word weapon_multi_rocket_launch
/*.word weapon_multi_hand*/
/*.word weapon_multi_timed*/
/*.word weapon_multi_prox*/
/*.word weapon_multi_remote*/
/*.word weapon_multi_none*/
/*.word weapon_multi_none*/
.text
glabel sub_GAME_7F09B368
/* 0CFE98 7F09B368 3C0E8008 */  lui   $t6, %hi(pPlayer) 
/* 0CFE9C 7F09B36C 8DCEA0B0 */  lw    $t6, %lo(pPlayer)($t6)
/* 0CFEA0 7F09B370 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0CFEA4 7F09B374 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0CFEA8 7F09B378 8DCF00A8 */  lw    $t7, 0xa8($t6)
/* 0CFEAC 7F09B37C 00802825 */  move  $a1, $a0
/* 0CFEB0 7F09B380 0FC1487A */  jal   set_0x4_in_runtime_flags_for_item_in_guards_hand
/* 0CFEB4 7F09B384 8DE40004 */   lw    $a0, 4($t7)
/* 0CFEB8 7F09B388 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0CFEBC 7F09B38C 27BD0018 */  addiu $sp, $sp, 0x18
/* 0CFEC0 7F09B390 03E00008 */  jr    $ra
/* 0CFEC4 7F09B394 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
s32 sub_GAME_7F09B398(s32 arg0) {
    s32 sp24;
    s32 sp30;
    s32 sp34;
    s32 temp_v1;
    ? temp_ret;
    s32 temp_ret_2;
    ? phi_a3;
    s32 phi_return;

    // Node 0
    temp_v1 = (arg0 * 4);
    phi_return = pPlayer->unkA8->unk4;
    if ((pPlayer->unkA8->unk4 + temp_v1)->unk160 == 0)
    {
        // Node 1
        sp34 = (s32) pPlayer->unkA8->unk4;
        sp24 = temp_v1;
        temp_ret = get_item_in_hand();
        sp30 = temp_ret;
        temp_ret_2 = sub_GAME_7F09B244(temp_ret);
        phi_return = temp_ret_2;
        if (temp_ret_2 >= 0)
        {
            // Node 2
            if (temp_v1 == 0)
            {
                // Node 3
                phi_a3 = 0;
            }
            else
            {
                // Node 4
                phi_a3 = 0x10000000;
            }
            // Node 5
            phi_return = something_with_generating_object(sp34, temp_ret_2, sp30, phi_a3, 0, 0);
        }
    }
    // Node 6
    return phi_return;
}
#else
GLOBAL_ASM(
.late_rodata
/*hack for jtbl*/
.word weapon_multi_hand
.word weapon_multi_timed
.word weapon_multi_prox
.word weapon_multi_remote
.word weapon_multi_none
.word weapon_multi_none

.text
glabel sub_GAME_7F09B398
/* 0CFEC8 7F09B398 3C0E8008 */  lui   $t6, %hi(pPlayer) 
/* 0CFECC 7F09B39C 8DCEA0B0 */  lw    $t6, %lo(pPlayer)($t6)
/* 0CFED0 7F09B3A0 27BDFFC8 */  addiu $sp, $sp, -0x38
/* 0CFED4 7F09B3A4 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0CFED8 7F09B3A8 8DCF00A8 */  lw    $t7, 0xa8($t6)
/* 0CFEDC 7F09B3AC 00041880 */  sll   $v1, $a0, 2
/* 0CFEE0 7F09B3B0 8DE20004 */  lw    $v0, 4($t7)
/* 0CFEE4 7F09B3B4 0043C021 */  addu  $t8, $v0, $v1
/* 0CFEE8 7F09B3B8 8F190160 */  lw    $t9, 0x160($t8)
/* 0CFEEC 7F09B3BC 57200014 */  bnezl $t9, .L7F09B410
/* 0CFEF0 7F09B3C0 8FBF001C */   lw    $ra, 0x1c($sp)
/* 0CFEF4 7F09B3C4 AFA20034 */  sw    $v0, 0x34($sp)
/* 0CFEF8 7F09B3C8 0FC17674 */  jal   get_item_in_hand
/* 0CFEFC 7F09B3CC AFA30024 */   sw    $v1, 0x24($sp)
/* 0CFF00 7F09B3D0 AFA20030 */  sw    $v0, 0x30($sp)
/* 0CFF04 7F09B3D4 0FC26C91 */  jal   sub_GAME_7F09B244
/* 0CFF08 7F09B3D8 00402025 */   move  $a0, $v0
/* 0CFF0C 7F09B3DC 8FA30024 */  lw    $v1, 0x24($sp)
/* 0CFF10 7F09B3E0 0440000A */  bltz  $v0, .L7F09B40C
/* 0CFF14 7F09B3E4 00402825 */   move  $a1, $v0
/* 0CFF18 7F09B3E8 14600003 */  bnez  $v1, .L7F09B3F8
/* 0CFF1C 7F09B3EC 8FA40034 */   lw    $a0, 0x34($sp)
/* 0CFF20 7F09B3F0 10000002 */  b     .L7F09B3FC
/* 0CFF24 7F09B3F4 00003825 */   move  $a3, $zero
.L7F09B3F8:
/* 0CFF28 7F09B3F8 3C071000 */  lui   $a3, 0x1000
.L7F09B3FC:
/* 0CFF2C 7F09B3FC 8FA60030 */  lw    $a2, 0x30($sp)
/* 0CFF30 7F09B400 AFA00010 */  sw    $zero, 0x10($sp)
/* 0CFF34 7F09B404 0FC14885 */  jal   something_with_generating_object
/* 0CFF38 7F09B408 AFA00014 */   sw    $zero, 0x14($sp)
.L7F09B40C:
/* 0CFF3C 7F09B40C 8FBF001C */  lw    $ra, 0x1c($sp)
.L7F09B410:
/* 0CFF40 7F09B410 27BD0038 */  addiu $sp, $sp, 0x38
/* 0CFF44 7F09B414 03E00008 */  jr    $ra
/* 0CFF48 7F09B418 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F09B41C(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F09B41C
/* 0CFF4C 7F09B41C 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 0CFF50 7F09B420 AFB1001C */  sw    $s1, 0x1c($sp)
/* 0CFF54 7F09B424 AFB00018 */  sw    $s0, 0x18($sp)
/* 0CFF58 7F09B428 3C118008 */  lui   $s1, %hi(dword_CODE_bss_8007A0C0)
/* 0CFF5C 7F09B42C AFBF002C */  sw    $ra, 0x2c($sp)
/* 0CFF60 7F09B430 AFB40028 */  sw    $s4, 0x28($sp)
/* 0CFF64 7F09B434 AFB30024 */  sw    $s3, 0x24($sp)
/* 0CFF68 7F09B438 AFB20020 */  sw    $s2, 0x20($sp)
/* 0CFF6C 7F09B43C 2631A0C0 */  addiu $s1, %lo(dword_CODE_bss_8007A0C0) # addiu $s1, $s1, -0x5f40
/* 0CFF70 7F09B440 00008025 */  move  $s0, $zero
.L7F09B444:
/* 0CFF74 7F09B444 AE300000 */  sw    $s0, ($s1)
/* 0CFF78 7F09B448 26100001 */  addiu $s0, $s0, 1
/* 0CFF7C 7F09B44C 2A010004 */  slti  $at, $s0, 4
/* 0CFF80 7F09B450 1420FFFC */  bnez  $at, .L7F09B444
/* 0CFF84 7F09B454 26310004 */   addiu $s1, $s1, 4
/* 0CFF88 7F09B458 3C0E8008 */  lui   $t6, %hi(dword_CODE_bss_8007A0C0)
/* 0CFF8C 7F09B45C 25D2A0C0 */  addiu $s2, $t6, %lo(dword_CODE_bss_8007A0C0)
/* 0CFF90 7F09B460 02408825 */  move  $s1, $s2
/* 0CFF94 7F09B464 00008025 */  move  $s0, $zero
/* 0CFF98 7F09B468 24140003 */  li    $s4, 3
/* 0CFF9C 7F09B46C 24130004 */  li    $s3, 4
.L7F09B470:
/* 0CFFA0 7F09B470 0C002914 */  jal   get_random_value
/* 0CFFA4 7F09B474 00000000 */   nop   
/* 0CFFA8 7F09B478 02707823 */  subu  $t7, $s3, $s0
/* 0CFFAC 7F09B47C 004F001B */  divu  $zero, $v0, $t7
/* 0CFFB0 7F09B480 0000C010 */  mfhi  $t8
/* 0CFFB4 7F09B484 0018C880 */  sll   $t9, $t8, 2
/* 0CFFB8 7F09B488 02591821 */  addu  $v1, $s2, $t9
/* 0CFFBC 7F09B48C 8C680000 */  lw    $t0, ($v1)
/* 0CFFC0 7F09B490 8E240000 */  lw    $a0, ($s1)
/* 0CFFC4 7F09B494 26100001 */  addiu $s0, $s0, 1
/* 0CFFC8 7F09B498 15E00002 */  bnez  $t7, .L7F09B4A4
/* 0CFFCC 7F09B49C 00000000 */   nop   
/* 0CFFD0 7F09B4A0 0007000D */  break 7
.L7F09B4A4:
/* 0CFFD4 7F09B4A4 AE280000 */  sw    $t0, ($s1)
/* 0CFFD8 7F09B4A8 26520004 */  addiu $s2, $s2, 4
/* 0CFFDC 7F09B4AC 26310004 */  addiu $s1, $s1, 4
/* 0CFFE0 7F09B4B0 1614FFEF */  bne   $s0, $s4, .L7F09B470
/* 0CFFE4 7F09B4B4 AC640000 */   sw    $a0, ($v1)
/* 0CFFE8 7F09B4B8 8FBF002C */  lw    $ra, 0x2c($sp)
/* 0CFFEC 7F09B4BC 8FB00018 */  lw    $s0, 0x18($sp)
/* 0CFFF0 7F09B4C0 8FB1001C */  lw    $s1, 0x1c($sp)
/* 0CFFF4 7F09B4C4 8FB20020 */  lw    $s2, 0x20($sp)
/* 0CFFF8 7F09B4C8 8FB30024 */  lw    $s3, 0x24($sp)
/* 0CFFFC 7F09B4CC 8FB40028 */  lw    $s4, 0x28($sp)
/* 0D0000 7F09B4D0 03E00008 */  jr    $ra
/* 0D0004 7F09B4D4 27BD0030 */   addiu $sp, $sp, 0x30
)
#endif





#ifdef NONMATCHING
s32 sub_GAME_7F09B4D8(s32 arg0) {
    s32 temp_v0;
    void *temp_a1;
    void *phi_a1;
    s32 phi_v1;
    s32 phi_v1_2;
    s32 phi_v1_3;

    // Node 0
    phi_a1 = &dword_CODE_bss_8007A0C0;
    phi_v1_3 = 0;
loop_1:
    // Node 1
    temp_v0 = *phi_a1;
    temp_a1 = (phi_a1 + 4);
    phi_v1 = phi_v1_3;
    if (arg0 != temp_v0)
    {
        // Node 2
        phi_v1_2 = phi_v1_3;
        if (*(&players + (temp_v0 * 4)) != 0)
        {
            // Node 3
            phi_v1_2 = (phi_v1_3 + 1);
        }
        // Node 4
        phi_a1 = temp_a1;
        phi_v1 = phi_v1_2;
        phi_v1_3 = phi_v1_2;
        if (temp_a1 != &dword_CODE_bss_8007A0D0)
        {
            goto loop_1;
        }
    }
    // Node 5
    return phi_v1;
}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F09B4D8
/* 0D0008 7F09B4D8 3C058008 */  lui   $a1, %hi(dword_CODE_bss_8007A0C0)
/* 0D000C 7F09B4DC 3C078008 */  lui   $a3, %hi(dword_CODE_bss_8007A0D0)
/* 0D0010 7F09B4E0 3C068008 */  lui   $a2, %hi(players)
/* 0D0014 7F09B4E4 00001825 */  move  $v1, $zero
/* 0D0018 7F09B4E8 24C69EE0 */  addiu $a2, %lo(players) # addiu $a2, $a2, -0x6120
/* 0D001C 7F09B4EC 24E7A0D0 */  addiu $a3, %lo(dword_CODE_bss_8007A0D0) # addiu $a3, $a3, -0x5f30
/* 0D0020 7F09B4F0 24A5A0C0 */  addiu $a1, %lo(dword_CODE_bss_8007A0C0) # addiu $a1, $a1, -0x5f40
/* 0D0024 7F09B4F4 8CA20000 */  lw    $v0, ($a1)
.L7F09B4F8:
/* 0D0028 7F09B4F8 24A50004 */  addiu $a1, $a1, 4
/* 0D002C 7F09B4FC 10820008 */  beq   $a0, $v0, .L7F09B520
/* 0D0030 7F09B500 00027080 */   sll   $t6, $v0, 2
/* 0D0034 7F09B504 00CE7821 */  addu  $t7, $a2, $t6
/* 0D0038 7F09B508 8DF80000 */  lw    $t8, ($t7)
/* 0D003C 7F09B50C 13000002 */  beqz  $t8, .L7F09B518
/* 0D0040 7F09B510 00000000 */   nop   
/* 0D0044 7F09B514 24630001 */  addiu $v1, $v1, 1
.L7F09B518:
/* 0D0048 7F09B518 54A7FFF7 */  bnel  $a1, $a3, .L7F09B4F8
/* 0D004C 7F09B51C 8CA20000 */   lw    $v0, ($a1)
.L7F09B520:
/* 0D0050 7F09B520 03E00008 */  jr    $ra
/* 0D0054 7F09B524 00601025 */   move  $v0, $v1
)
#endif





#ifdef NONMATCHING
int proc_7F09B528(int param_1)
{
    if (players[dword_CODE_bss_8007A0C0] != NULL) {
        if (param_1 == 0) {
            return dword_CODE_bss_8007A0C0;
        }
        param_1--;
    }
    if (players[dword_CODE_bss_8007A0C4] != NULL) {
        if (param_1 == 0) {
            return dword_CODE_bss_8007A0C4;
        }
        param_1--;
    }
    if (players[dword_CODE_bss_8007A0C8] != NULL) {
        if (param_1 == 0) {
            return dword_CODE_bss_8007A0C8;
        }
        param_1--;
    }
    if ((players[dword_CODE_bss_8007A0CC] != NULL) && (param_1 == 0)) {
        return dword_CODE_bss_8007A0CC;
    }
    return 0;
}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F09B528
/* 0D0058 7F09B528 3C038008 */  lui   $v1, %hi(dword_CODE_bss_8007A0C0)
/* 0D005C 7F09B52C 8C63A0C0 */  lw    $v1, %lo(dword_CODE_bss_8007A0C0)($v1)
/* 0D0060 7F09B530 3C028008 */  lui   $v0, %hi(players)
/* 0D0064 7F09B534 24429EE0 */  addiu $v0, %lo(players) # addiu $v0, $v0, -0x6120
/* 0D0068 7F09B538 00037080 */  sll   $t6, $v1, 2
/* 0D006C 7F09B53C 004E7821 */  addu  $t7, $v0, $t6
/* 0D0070 7F09B540 8DF80000 */  lw    $t8, ($t7)
/* 0D0074 7F09B544 13000006 */  beqz  $t8, .L7F09B560
/* 0D0078 7F09B548 00000000 */   nop   
/* 0D007C 7F09B54C 54800004 */  bnezl $a0, .L7F09B560
/* 0D0080 7F09B550 2484FFFF */   addiu $a0, $a0, -1
/* 0D0084 7F09B554 03E00008 */  jr    $ra
/* 0D0088 7F09B558 00601025 */   move  $v0, $v1

/* 0D008C 7F09B55C 2484FFFF */  addiu $a0, $a0, -1
.L7F09B560:
/* 0D0090 7F09B560 3C038008 */  lui   $v1, %hi(dword_CODE_bss_8007A0C4)
/* 0D0094 7F09B564 8C63A0C4 */  lw    $v1, %lo(dword_CODE_bss_8007A0C4)($v1)
/* 0D0098 7F09B568 0003C880 */  sll   $t9, $v1, 2
/* 0D009C 7F09B56C 00594021 */  addu  $t0, $v0, $t9
/* 0D00A0 7F09B570 8D090000 */  lw    $t1, ($t0)
/* 0D00A4 7F09B574 11200006 */  beqz  $t1, .L7F09B590
/* 0D00A8 7F09B578 00000000 */   nop   
/* 0D00AC 7F09B57C 54800004 */  bnezl $a0, .L7F09B590
/* 0D00B0 7F09B580 2484FFFF */   addiu $a0, $a0, -1
/* 0D00B4 7F09B584 03E00008 */  jr    $ra
/* 0D00B8 7F09B588 00601025 */   move  $v0, $v1

/* 0D00BC 7F09B58C 2484FFFF */  addiu $a0, $a0, -1
.L7F09B590:
/* 0D00C0 7F09B590 3C038008 */  lui   $v1, %hi(dword_CODE_bss_8007A0C8)
/* 0D00C4 7F09B594 8C63A0C8 */  lw    $v1, %lo(dword_CODE_bss_8007A0C8)($v1)
/* 0D00C8 7F09B598 00035080 */  sll   $t2, $v1, 2
/* 0D00CC 7F09B59C 004A5821 */  addu  $t3, $v0, $t2
/* 0D00D0 7F09B5A0 8D6C0000 */  lw    $t4, ($t3)
/* 0D00D4 7F09B5A4 11800006 */  beqz  $t4, .L7F09B5C0
/* 0D00D8 7F09B5A8 00000000 */   nop   
/* 0D00DC 7F09B5AC 54800004 */  bnezl $a0, .L7F09B5C0
/* 0D00E0 7F09B5B0 2484FFFF */   addiu $a0, $a0, -1
/* 0D00E4 7F09B5B4 03E00008 */  jr    $ra
/* 0D00E8 7F09B5B8 00601025 */   move  $v0, $v1

/* 0D00EC 7F09B5BC 2484FFFF */  addiu $a0, $a0, -1
.L7F09B5C0:
/* 0D00F0 7F09B5C0 3C038008 */  lui   $v1, %hi(dword_CODE_bss_8007A0CC)
/* 0D00F4 7F09B5C4 8C63A0CC */  lw    $v1, %lo(dword_CODE_bss_8007A0CC)($v1)
/* 0D00F8 7F09B5C8 00036880 */  sll   $t5, $v1, 2
/* 0D00FC 7F09B5CC 004D7021 */  addu  $t6, $v0, $t5
/* 0D0100 7F09B5D0 8DCF0000 */  lw    $t7, ($t6)
/* 0D0104 7F09B5D4 00001025 */  move  $v0, $zero
/* 0D0108 7F09B5D8 11E00005 */  beqz  $t7, .L7F09B5F0
/* 0D010C 7F09B5DC 00000000 */   nop   
/* 0D0110 7F09B5E0 14800003 */  bnez  $a0, .L7F09B5F0
/* 0D0114 7F09B5E4 00000000 */   nop   
/* 0D0118 7F09B5E8 03E00008 */  jr    $ra
/* 0D011C 7F09B5EC 00601025 */   move  $v0, $v1

.L7F09B5F0:
/* 0D0120 7F09B5F0 03E00008 */  jr    $ra
/* 0D0124 7F09B5F4 00000000 */   nop   
)
#endif



