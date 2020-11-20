#include "ultra64.h"
#include "pi.h"
#include "snd.h"
#include "game/lvl_text.h"


//OSMesg boot_token_from_indy[160];
char boot_token_from_indy[0x280];
s32 strstr_numstings = 1;
s32 strstr_ptrcurrent_string = 0;
u32 D_80024478[34] = {0};


//const char str_empty[] = "";






#ifdef NONMATCHING
void *check_string_something(void *arg0)
{
    s32 temp_v0;
    s32 temp_v0_2;
    void *temp_a0;
    void *temp_a0_2;
    s32 phi_v0;
    void *phi_a0;
    void *phi_a0_2;
    void *phi_a0_3;
    s32 phi_v0_2;
    void *phi_a0_4;
    void *phi_a0_5;
    void *phi_a0_6;

    strstr_ptrcurrent_string = &str_empty;
    strstr_numstings = 1;
    phi_v0 = *arg0;
    phi_a0_4 = arg0;
    phi_a0_5 = arg0;
    if (*arg0 != 0)
    {
loop_1:
        phi_a0 = phi_a0_5;
        phi_a0_2 = phi_a0_5;
        if (0x20 == phi_v0)
        {
loop_2:
            phi_a0->unk0 = (u8)0;
            temp_a0 = phi_a0 + 1;
            phi_a0 = temp_a0;
            phi_a0_2 = temp_a0;
            if (0x20 == phi_a0->unk1)
            {
                goto loop_2;
            }
        }
        *(&strstr_ptrcurrent_string + (strstr_numstings * 4)) = (void *) phi_a0_2;
        strstr_numstings = (s32) (strstr_numstings + 1);
        temp_v0 = *phi_a0_2;
        phi_a0_3 = phi_a0_2;
        phi_v0_2 = temp_v0;
        phi_a0_6 = phi_a0_2;
        if (temp_v0 >= 0x21)
        {
loop_4:
            temp_v0_2 = phi_a0_3->unk1;
            temp_a0_2 = phi_a0_3 + 1;
            phi_a0_3 = temp_a0_2;
            phi_v0_2 = temp_v0_2;
            phi_a0_6 = temp_a0_2;
            if (temp_v0_2 >= 0x21)
            {
                goto loop_4;
            }
        }
        phi_v0 = phi_v0_2;
        phi_a0_4 = phi_a0_6;
        phi_a0_5 = phi_a0_6;
        if (phi_v0_2 != 0)
        {
            goto loop_1;
        }
    }
    return phi_a0_4;
}
#else
GLOBAL_ASM(
.late_rodata
glabel str_empty
.word 0x0
.text
glabel check_string_something
/* 00B0F0 7000A4F0 3C058002 */  lui   $a1, %hi(strstr_ptrcurrent_string)
/* 00B0F4 7000A4F4 3C068002 */  lui   $a2, %hi(strstr_numstings)
/* 00B0F8 7000A4F8 3C0E8003 */  lui   $t6, %hi(str_empty) 
/* 00B0FC 7000A4FC 24C64470 */  addiu $a2, %lo(strstr_numstings) # addiu $a2, $a2, 0x4470
/* 00B100 7000A500 24A54474 */  addiu $a1, %lo(strstr_ptrcurrent_string) # addiu $a1, $a1, 0x4474
/* 00B104 7000A504 25CE91F0 */  addiu $t6, %lo(str_empty) # addiu $t6, $t6, -0x6e10
/* 00B108 7000A508 240F0001 */  li    $t7, 1
/* 00B10C 7000A50C ACAE0000 */  sw    $t6, ($a1)
/* 00B110 7000A510 ACCF0000 */  sw    $t7, ($a2)
/* 00B114 7000A514 90820000 */  lbu   $v0, ($a0)
/* 00B118 7000A518 24070020 */  li    $a3, 32
/* 00B11C 7000A51C 10400019 */  beqz  $v0, .L7000A584
/* 00B120 7000A520 00000000 */   nop   
.L7000A524:
/* 00B124 7000A524 54E20007 */  bnel  $a3, $v0, .L7000A544
/* 00B128 7000A528 8CC30000 */   lw    $v1, ($a2)
/* 00B12C 7000A52C 90980001 */  lbu   $t8, 1($a0)
.L7000A530:
/* 00B130 7000A530 A0800000 */  sb    $zero, ($a0)
/* 00B134 7000A534 24840001 */  addiu $a0, $a0, 1
/* 00B138 7000A538 50F8FFFD */  beql  $a3, $t8, .L7000A530
/* 00B13C 7000A53C 90980001 */   lbu   $t8, 1($a0)
/* 00B140 7000A540 8CC30000 */  lw    $v1, ($a2)
.L7000A544:
/* 00B144 7000A544 0003C880 */  sll   $t9, $v1, 2
/* 00B148 7000A548 00B94021 */  addu  $t0, $a1, $t9
/* 00B14C 7000A54C AD040000 */  sw    $a0, ($t0)
/* 00B150 7000A550 24690001 */  addiu $t1, $v1, 1
/* 00B154 7000A554 ACC90000 */  sw    $t1, ($a2)
/* 00B158 7000A558 90820000 */  lbu   $v0, ($a0)
/* 00B15C 7000A55C 28410021 */  slti  $at, $v0, 0x21
/* 00B160 7000A560 14200006 */  bnez  $at, .L7000A57C
/* 00B164 7000A564 00000000 */   nop   
/* 00B168 7000A568 90820001 */  lbu   $v0, 1($a0)
.L7000A56C:
/* 00B16C 7000A56C 24840001 */  addiu $a0, $a0, 1
/* 00B170 7000A570 28410021 */  slti  $at, $v0, 0x21
/* 00B174 7000A574 5020FFFD */  beql  $at, $zero, .L7000A56C
/* 00B178 7000A578 90820001 */   lbu   $v0, 1($a0)
.L7000A57C:
/* 00B17C 7000A57C 1440FFE9 */  bnez  $v0, .L7000A524
/* 00B180 7000A580 00000000 */   nop   
.L7000A584:
/* 00B184 7000A584 03E00008 */  jr    $ra
/* 00B188 7000A588 00801025 */   move  $v0, $a0
)
#endif


void strtok(s32 arg0) {
    textpointer_load_parse_something(&boot_token_from_indy, arg0);
    check_string_something(&boot_token_from_indy);
}

//const char aD_6[] = "-d";
//const char aS_2[] = "-s";
//const char aJ[] = "-j";

#ifdef NONMATCHING
s32 check_boot_switches(void)
{
    s32 is_debug;
    s32 devAddr;
    u32 *data;

    is_debug = 0;
    if (rmon_debug_is_final_build() != 0)
    {
        boot_token_from_indy[0] = 0;
    }
    else
    {
        for (devAddr = 0xffb000, data = &boot_token_from_indy; data != &piCmdBuf; data += 4, devAddr += 4)
        {
            osPiReadIo(devAddr, data);
        }
    }
    check_string_something(&boot_token_from_indy);

    is_debug = (check_token(1, "-d") != 0);

    if (check_token(1, "-s") != 0) {
        bootswitch_sound = 1;
    }

    if (check_token(1, "-j") != 0) {
        j_text_trigger = 1;
    }

    return is_debug;
}
#else
GLOBAL_ASM(
.late_rodata
glabel aD_6
.word 0x2d640000
glabel aS_2
.word 0x2d730000
glabel aJ
.word 0x2d6a0000
.text
glabel check_boot_switches
/* 00B1C0 7000A5C0 27BDFFC8 */  addiu $sp, $sp, -0x38
/* 00B1C4 7000A5C4 AFB1001C */  sw    $s1, 0x1c($sp)
/* 00B1C8 7000A5C8 AFBF0024 */  sw    $ra, 0x24($sp)
/* 00B1CC 7000A5CC 3C1100FF */  lui   $s1, 0xff
/* 00B1D0 7000A5D0 AFB20020 */  sw    $s2, 0x20($sp)
/* 00B1D4 7000A5D4 AFB00018 */  sw    $s0, 0x18($sp)
/* 00B1D8 7000A5D8 AFA00028 */  sw    $zero, 0x28($sp)
/* 00B1DC 7000A5DC 0C0033AA */  jal   rmon_debug_is_final_build
/* 00B1E0 7000A5E0 3631B000 */   ori $s1, $s1, 0xb000
/* 00B1E4 7000A5E4 10400004 */  beqz  $v0, .L7000A5F8
/* 00B1E8 7000A5E8 3C108006 */   lui   $s0, %hi(boot_token_from_indy)
/* 00B1EC 7000A5EC 3C018006 */  lui   $at, %hi(boot_token_from_indy)
/* 00B1F0 7000A5F0 1000000A */  b     .L7000A61C
/* 00B1F4 7000A5F4 AC204C30 */   sw    $zero, %lo(boot_token_from_indy)($at)
.L7000A5F8:
/* 00B1F8 7000A5F8 3C128006 */  lui   $s2, %hi(piCmdBuf)
/* 00B1FC 7000A5FC 26524EB0 */  addiu $s2, %lo(piCmdBuf) # addiu $s2, $s2, 0x4eb0
/* 00B200 7000A600 26104C30 */  addiu $s0, %lo(boot_token_from_indy) # addiu $s0, $s0, 0x4c30
.L7000A604:
/* 00B204 7000A604 02202025 */  move  $a0, $s1
/* 00B208 7000A608 0C004E04 */  jal   osPiReadIo
/* 00B20C 7000A60C 02002825 */   move  $a1, $s0
/* 00B210 7000A610 26100004 */  addiu $s0, $s0, 4
/* 00B214 7000A614 1612FFFB */  bne   $s0, $s2, .L7000A604
/* 00B218 7000A618 26310004 */   addiu $s1, $s1, 4
.L7000A61C:
/* 00B21C 7000A61C 3C048006 */  lui   $a0, %hi(boot_token_from_indy)
/* 00B220 7000A620 0C00293C */  jal   check_string_something
/* 00B224 7000A624 24844C30 */   addiu $a0, %lo(boot_token_from_indy) # addiu $a0, $a0, 0x4c30
/* 00B228 7000A628 3C058003 */  lui   $a1, %hi(aD_6)
/* 00B22C 7000A62C 24A591F4 */  addiu $a1, %lo(aD_6) # addiu $a1, $a1, -0x6e0c
/* 00B230 7000A630 0C0029A8 */  jal   check_token
/* 00B234 7000A634 24040001 */   li    $a0, 1
/* 00B238 7000A638 10400003 */  beqz  $v0, .L7000A648
/* 00B23C 7000A63C 24040001 */   li    $a0, 1
/* 00B240 7000A640 240E0001 */  li    $t6, 1
/* 00B244 7000A644 AFAE0028 */  sw    $t6, 0x28($sp)
.L7000A648:
/* 00B248 7000A648 3C058003 */  lui   $a1, %hi(aS_2)
/* 00B24C 7000A64C 0C0029A8 */  jal   check_token
/* 00B250 7000A650 24A591F8 */   addiu $a1, %lo(aS_2) # addiu $a1, $a1, -0x6e08
/* 00B254 7000A654 10400004 */  beqz  $v0, .L7000A668
/* 00B258 7000A658 24040001 */   li    $a0, 1
/* 00B25C 7000A65C 240F0001 */  li    $t7, 1
/* 00B260 7000A660 3C018002 */  lui   $at, %hi(bootswitch_sound)
/* 00B264 7000A664 A02F43F8 */  sb    $t7, %lo(bootswitch_sound)($at)
.L7000A668:
/* 00B268 7000A668 3C058003 */  lui   $a1, %hi(aJ)
/* 00B26C 7000A66C 0C0029A8 */  jal   check_token
/* 00B270 7000A670 24A591FC */   addiu $a1, %lo(aJ) # addiu $a1, $a1, -0x6e04
/* 00B274 7000A674 10400003 */  beqz  $v0, .L7000A684
/* 00B278 7000A678 24180001 */   li    $t8, 1
/* 00B27C 7000A67C 3C018005 */  lui   $at, %hi(j_text_trigger)
/* 00B280 7000A680 AC3884D0 */  sw    $t8, %lo(j_text_trigger)($at)
.L7000A684:
/* 00B284 7000A684 8FBF0024 */  lw    $ra, 0x24($sp)
/* 00B288 7000A688 8FA20028 */  lw    $v0, 0x28($sp)
/* 00B28C 7000A68C 8FB00018 */  lw    $s0, 0x18($sp)
/* 00B290 7000A690 8FB1001C */  lw    $s1, 0x1c($sp)
/* 00B294 7000A694 8FB20020 */  lw    $s2, 0x20($sp)
/* 00B298 7000A698 03E00008 */  jr    $ra
/* 00B29C 7000A69C 27BD0038 */   addiu $sp, $sp, 0x38
)
#endif



#ifdef NONMATCHING
s32 check_token(s32 arg0, s32 arg1)
{
    s32 temp_s1;
    s32 temp_s2;
    s32 temp_s3;
    void *phi_s0;
    s32 phi_s2;
    s32 phi_s1;

    temp_s3 = strlen(arg1);
    if (strstr_numstings >= 2)
    {
        phi_s0 = &D_80024478;
        phi_s2 = arg0;
        phi_s1 = 1;
loop_2:
        phi_s2 = phi_s2;
        if (string_related(arg1, *phi_s0, temp_s3) == 0)
        {
            temp_s2 = phi_s2 + -1;
            phi_s2 = temp_s2;
            if (temp_s2 == 0)
            {
                return *phi_s0 + temp_s3;
            }
        }
        temp_s1 = phi_s1 + 1;
        phi_s0 = phi_s0 + 4;
        phi_s1 = temp_s1;
        if (temp_s1 < strstr_numstings)
        {
            goto loop_2;
        }
    }
    return 0;
}
#else
GLOBAL_ASM(
.text
glabel check_token
/* 00B2A0 7000A6A0 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 00B2A4 7000A6A4 AFB2001C */  sw    $s2, 0x1c($sp)
/* 00B2A8 7000A6A8 00809025 */  move  $s2, $a0
/* 00B2AC 7000A6AC AFBF002C */  sw    $ra, 0x2c($sp)
/* 00B2B0 7000A6B0 AFB40024 */  sw    $s4, 0x24($sp)
/* 00B2B4 7000A6B4 00A0A025 */  move  $s4, $a1
/* 00B2B8 7000A6B8 AFB50028 */  sw    $s5, 0x28($sp)
/* 00B2BC 7000A6BC AFB30020 */  sw    $s3, 0x20($sp)
/* 00B2C0 7000A6C0 AFB10018 */  sw    $s1, 0x18($sp)
/* 00B2C4 7000A6C4 AFB00014 */  sw    $s0, 0x14($sp)
/* 00B2C8 7000A6C8 0C004E1F */  jal   strlen
/* 00B2CC 7000A6CC 00A02025 */   move  $a0, $a1
/* 00B2D0 7000A6D0 3C158002 */  lui   $s5, %hi(strstr_numstings)
/* 00B2D4 7000A6D4 26B54470 */  addiu $s5, %lo(strstr_numstings) # addiu $s5, $s5, 0x4470
/* 00B2D8 7000A6D8 8EAE0000 */  lw    $t6, ($s5)
/* 00B2DC 7000A6DC 00409825 */  move  $s3, $v0
/* 00B2E0 7000A6E0 24110001 */  li    $s1, 1
/* 00B2E4 7000A6E4 29C10002 */  slti  $at, $t6, 2
/* 00B2E8 7000A6E8 14200014 */  bnez  $at, .L7000A73C
/* 00B2EC 7000A6EC 3C108002 */   lui   $s0, %hi(D_80024478)
/* 00B2F0 7000A6F0 26104478 */  addiu $s0, %lo(D_80024478) # addiu $s0, $s0, 0x4478
/* 00B2F4 7000A6F4 02802025 */  move  $a0, $s4
.L7000A6F8:
/* 00B2F8 7000A6F8 8E050000 */  lw    $a1, ($s0)
/* 00B2FC 7000A6FC 0C002A26 */  jal   string_related
/* 00B300 7000A700 02603025 */   move  $a2, $s3
/* 00B304 7000A704 54400008 */  bnezl $v0, .L7000A728
/* 00B308 7000A708 8EB80000 */   lw    $t8, ($s5)
/* 00B30C 7000A70C 2652FFFF */  addiu $s2, $s2, -1
/* 00B310 7000A710 56400005 */  bnezl $s2, .L7000A728
/* 00B314 7000A714 8EB80000 */   lw    $t8, ($s5)
/* 00B318 7000A718 8E0F0000 */  lw    $t7, ($s0)
/* 00B31C 7000A71C 10000008 */  b     .L7000A740
/* 00B320 7000A720 01F31021 */   addu  $v0, $t7, $s3
/* 00B324 7000A724 8EB80000 */  lw    $t8, ($s5)
.L7000A728:
/* 00B328 7000A728 26310001 */  addiu $s1, $s1, 1
/* 00B32C 7000A72C 26100004 */  addiu $s0, $s0, 4
/* 00B330 7000A730 0238082A */  slt   $at, $s1, $t8
/* 00B334 7000A734 5420FFF0 */  bnezl $at, .L7000A6F8
/* 00B338 7000A738 02802025 */   move  $a0, $s4
.L7000A73C:
/* 00B33C 7000A73C 00001025 */  move  $v0, $zero
.L7000A740:
/* 00B340 7000A740 8FBF002C */  lw    $ra, 0x2c($sp)
/* 00B344 7000A744 8FB00014 */  lw    $s0, 0x14($sp)
/* 00B348 7000A748 8FB10018 */  lw    $s1, 0x18($sp)
/* 00B34C 7000A74C 8FB2001C */  lw    $s2, 0x1c($sp)
/* 00B350 7000A750 8FB30020 */  lw    $s3, 0x20($sp)
/* 00B354 7000A754 8FB40024 */  lw    $s4, 0x24($sp)
/* 00B358 7000A758 8FB50028 */  lw    $s5, 0x28($sp)
/* 00B35C 7000A75C 03E00008 */  jr    $ra
/* 00B360 7000A760 27BD0030 */   addiu $sp, $sp, 0x30
)
#endif


