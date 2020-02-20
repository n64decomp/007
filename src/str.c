#include "ultra64.h"





#ifdef NONMATCHING
void *textpointer_load_parse_something(void *arg0, void *arg1) {
    void *temp_a1;

    // Node 0
    temp_a1 = (arg1 + 1);
    *arg0 = (s8) *arg1;
    if (*arg1 != 0)
    {
        loop_1:
        // Node 1
        ((arg0 + 1) + 1)->unk-1 = (s8) *temp_a1;
        if (*temp_a1 != 0)
        {
            goto loop_1;
        }
    }
    // (possible return value: arg0)
}

#else
GLOBAL_ASM(
.text
glabel textpointer_load_parse_something
/* 00B370 7000A770 90A20000 */  lbu   $v0, ($a1)
/* 00B374 7000A774 24830001 */  addiu $v1, $a0, 1
/* 00B378 7000A778 24A50001 */  addiu $a1, $a1, 1
/* 00B37C 7000A77C 10400006 */  beqz  $v0, .L7000A798
/* 00B380 7000A780 A0820000 */   sb    $v0, ($a0)
.L7000A784:
/* 00B384 7000A784 90A20000 */  lbu   $v0, ($a1)
/* 00B388 7000A788 24630001 */  addiu $v1, $v1, 1
/* 00B38C 7000A78C 24A50001 */  addiu $a1, $a1, 1
/* 00B390 7000A790 1440FFFC */  bnez  $v0, .L7000A784
/* 00B394 7000A794 A062FFFF */   sb    $v0, -1($v1)
.L7000A798:
/* 00B398 7000A798 03E00008 */  jr    $ra
/* 00B39C 7000A79C 00801025 */   move  $v0, $a0
)
#endif



#ifdef NONMATCHING
void *something_with_strings(void *arg0, void *arg1, s32 arg2) {
    void *temp_v1;
    void *temp_a1;
    s32 temp_a2;

    // Node 0
    temp_v1 = (arg0 + 1);
    temp_a1 = (arg1 + 1);
    *arg0 = (s8) *arg1;
    if (*arg1 != 0)
    {
        loop_1:
        // Node 1
        if ((arg2 + -1) != 0)
        {
            // Node 2
            (temp_v1 + 1)->unk-1 = (s8) *temp_a1;
            if (*temp_a1 != 0)
            {
                goto loop_1;
            }
        }
    }
    // Node 3
    temp_a2 = (arg2 + -1);
    if (temp_a2 != 0)
    {
        loop_4:
        // Node 4
        *temp_v1 = (u8)0;
        if ((temp_a2 + -1) != 0)
        {
            goto loop_4;
        }
    }
    // (possible return value: arg0)
}

#else
GLOBAL_ASM(
.text
glabel something_with_strings
/* 00B3A0 7000A7A0 90A20000 */  lbu   $v0, ($a1)
/* 00B3A4 7000A7A4 24830001 */  addiu $v1, $a0, 1
/* 00B3A8 7000A7A8 24A50001 */  addiu $a1, $a1, 1
/* 00B3AC 7000A7AC 10400009 */  beqz  $v0, .L7000A7D4
/* 00B3B0 7000A7B0 A0820000 */   sb    $v0, ($a0)
.L7000A7B4:
/* 00B3B4 7000A7B4 24C6FFFF */  addiu $a2, $a2, -1
/* 00B3B8 7000A7B8 50C00007 */  beql  $a2, $zero, .L7000A7D8
/* 00B3BC 7000A7BC 00C01025 */   move  $v0, $a2
/* 00B3C0 7000A7C0 90A20000 */  lbu   $v0, ($a1)
/* 00B3C4 7000A7C4 24630001 */  addiu $v1, $v1, 1
/* 00B3C8 7000A7C8 24A50001 */  addiu $a1, $a1, 1
/* 00B3CC 7000A7CC 1440FFF9 */  bnez  $v0, .L7000A7B4
/* 00B3D0 7000A7D0 A062FFFF */   sb    $v0, -1($v1)
.L7000A7D4:
/* 00B3D4 7000A7D4 00C01025 */  move  $v0, $a2
.L7000A7D8:
/* 00B3D8 7000A7D8 10C00006 */  beqz  $a2, .L7000A7F4
/* 00B3DC 7000A7DC 24C6FFFF */   addiu $a2, $a2, -1
.L7000A7E0:
/* 00B3E0 7000A7E0 00C01025 */  move  $v0, $a2
/* 00B3E4 7000A7E4 A0600000 */  sb    $zero, ($v1)
/* 00B3E8 7000A7E8 24630001 */  addiu $v1, $v1, 1
/* 00B3EC 7000A7EC 14C0FFFC */  bnez  $a2, .L7000A7E0
/* 00B3F0 7000A7F0 24C6FFFF */   addiu $a2, $a2, -1
.L7000A7F4:
/* 00B3F4 7000A7F4 03E00008 */  jr    $ra
/* 00B3F8 7000A7F8 00801025 */   move  $v0, $a0
)
#endif



#ifdef NONMATCHING
void *string_append_from_obseg_textbank(void *arg0, void *arg1) {
    void *temp_v0;
    void *temp_a1;

    // Node 0
    if (*arg0 != 0)
    {
        loop_1:
        // Node 1
        if (arg0->unk1 != 0)
        {
            goto loop_1;
        }
    }
    // Node 2
    temp_v0 = (arg0 + 1);
    temp_a1 = (arg1 + 1);
    temp_v0->unk-1 = (s8) *arg1;
    if (*arg1 != 0)
    {
        loop_3:
        // Node 3
        (temp_v0 + 1)->unk-1 = (s8) *temp_a1;
        if (*temp_a1 != 0)
        {
            goto loop_3;
        }
    }
    // (possible return value: arg0)
}

#else
GLOBAL_ASM(
.text
glabel string_append_from_obseg_textbank
/* 00B3FC 7000A7FC 908E0000 */  lbu   $t6, ($a0)
/* 00B400 7000A800 00801025 */  move  $v0, $a0
/* 00B404 7000A804 51C00006 */  beql  $t6, $zero, .L7000A820
/* 00B408 7000A808 90A30000 */   lbu   $v1, ($a1)
/* 00B40C 7000A80C 904F0001 */  lbu   $t7, 1($v0)
.L7000A810:
/* 00B410 7000A810 24420001 */  addiu $v0, $v0, 1
/* 00B414 7000A814 55E0FFFE */  bnezl $t7, .L7000A810
/* 00B418 7000A818 904F0001 */   lbu   $t7, 1($v0)
/* 00B41C 7000A81C 90A30000 */  lbu   $v1, ($a1)
.L7000A820:
/* 00B420 7000A820 24420001 */  addiu $v0, $v0, 1
/* 00B424 7000A824 24A50001 */  addiu $a1, $a1, 1
/* 00B428 7000A828 10600006 */  beqz  $v1, .L7000A844
/* 00B42C 7000A82C A043FFFF */   sb    $v1, -1($v0)
.L7000A830:
/* 00B430 7000A830 90A30000 */  lbu   $v1, ($a1)
/* 00B434 7000A834 24420001 */  addiu $v0, $v0, 1
/* 00B438 7000A838 24A50001 */  addiu $a1, $a1, 1
/* 00B43C 7000A83C 1460FFFC */  bnez  $v1, .L7000A830
/* 00B440 7000A840 A043FFFF */   sb    $v1, -1($v0)
.L7000A844:
/* 00B444 7000A844 03E00008 */  jr    $ra
/* 00B448 7000A848 00801025 */   move  $v0, $a0
)
#endif



#ifdef NONMATCHING
void something_with_strings_0(void) {

}
#else
GLOBAL_ASM(
.text
glabel something_with_strings_0
.L7000A84C:
/* 00B44C 7000A84C 90820000 */  lbu   $v0, ($a0)
/* 00B450 7000A850 90A30000 */  lbu   $v1, ($a1)
/* 00B454 7000A854 24840001 */  addiu $a0, $a0, 1
/* 00B458 7000A858 10430007 */  beq   $v0, $v1, .L7000A878
/* 00B45C 7000A85C 0043082A */   slt   $at, $v0, $v1
/* 00B460 7000A860 10200003 */  beqz  $at, .L7000A870
/* 00B464 7000A864 00000000 */   nop   
/* 00B468 7000A868 03E00008 */  jr    $ra
/* 00B46C 7000A86C 2402FFFF */   li    $v0, -1

.L7000A870:
/* 00B470 7000A870 03E00008 */  jr    $ra
/* 00B474 7000A874 24020001 */   li    $v0, 1

.L7000A878:
/* 00B478 7000A878 14400003 */  bnez  $v0, .L7000A888
/* 00B47C 7000A87C 00000000 */   nop   
/* 00B480 7000A880 03E00008 */  jr    $ra
/* 00B484 7000A884 00001025 */   move  $v0, $zero

.L7000A888:
/* 00B488 7000A888 1000FFF0 */  b     .L7000A84C
/* 00B48C 7000A88C 24A50001 */   addiu $a1, $a1, 1
/* 00B490 7000A890 03E00008 */  jr    $ra
/* 00B494 7000A894 00000000 */   nop   
)
#endif



#ifdef NONMATCHING
void string_related(void) {

}
#else
GLOBAL_ASM(
.text
glabel string_related
.L7000A898:
/* 00B498 7000A898 54C00004 */  bnezl $a2, .L7000A8AC
/* 00B49C 7000A89C 90820000 */   lbu   $v0, ($a0)
/* 00B4A0 7000A8A0 03E00008 */  jr    $ra
/* 00B4A4 7000A8A4 00001025 */   move  $v0, $zero

/* 00B4A8 7000A8A8 90820000 */  lbu   $v0, ($a0)
.L7000A8AC:
/* 00B4AC 7000A8AC 90A30000 */  lbu   $v1, ($a1)
/* 00B4B0 7000A8B0 24C6FFFF */  addiu $a2, $a2, -1
/* 00B4B4 7000A8B4 24840001 */  addiu $a0, $a0, 1
/* 00B4B8 7000A8B8 10430007 */  beq   $v0, $v1, .L7000A8D8
/* 00B4BC 7000A8BC 0043082A */   slt   $at, $v0, $v1
/* 00B4C0 7000A8C0 10200003 */  beqz  $at, .L7000A8D0
/* 00B4C4 7000A8C4 00000000 */   nop   
/* 00B4C8 7000A8C8 03E00008 */  jr    $ra
/* 00B4CC 7000A8CC 2402FFFF */   li    $v0, -1

.L7000A8D0:
/* 00B4D0 7000A8D0 03E00008 */  jr    $ra
/* 00B4D4 7000A8D4 24020001 */   li    $v0, 1

.L7000A8D8:
/* 00B4D8 7000A8D8 14400003 */  bnez  $v0, .L7000A8E8
/* 00B4DC 7000A8DC 00000000 */   nop   
/* 00B4E0 7000A8E0 03E00008 */  jr    $ra
/* 00B4E4 7000A8E4 00001025 */   move  $v0, $zero

.L7000A8E8:
/* 00B4E8 7000A8E8 1000FFEB */  b     .L7000A898
/* 00B4EC 7000A8EC 24A50001 */   addiu $a1, $a1, 1
/* 00B4F0 7000A8F0 03E00008 */  jr    $ra
/* 00B4F4 7000A8F4 00000000 */   nop   
)
#endif



#ifdef NONMATCHING
s32 strtol_related(s32 arg0) {
    s32 temp_t6;

    // Node 0
    temp_t6 = (arg0 & 0xff);
    if (temp_t6 >= 0x61)
    {
        // Node 1
        if (temp_t6 < 0x7b)
        {
            // Node 2
            return;
            // (possible return value: temp_t6)
        }
    }
    // (possible return value: temp_t6)
}
#else
GLOBAL_ASM(
.text
glabel strtol_related
/* 00B4F8 7000A8F8 308E00FF */  andi  $t6, $a0, 0xff
/* 00B4FC 7000A8FC AFA40000 */  sw    $a0, ($sp)
/* 00B500 7000A900 29C10061 */  slti  $at, $t6, 0x61
/* 00B504 7000A904 14200007 */  bnez  $at, .L7000A924
/* 00B508 7000A908 01C02025 */   move  $a0, $t6
/* 00B50C 7000A90C 29C1007B */  slti  $at, $t6, 0x7b
/* 00B510 7000A910 10200004 */  beqz  $at, .L7000A924
/* 00B514 7000A914 25C2FFE0 */   addiu $v0, $t6, -0x20
/* 00B518 7000A918 304F00FF */  andi  $t7, $v0, 0xff
/* 00B51C 7000A91C 03E00008 */  jr    $ra
/* 00B520 7000A920 01E01025 */   move  $v0, $t7

.L7000A924:
/* 00B524 7000A924 00801025 */  move  $v0, $a0
/* 00B528 7000A928 03E00008 */  jr    $ra
/* 00B52C 7000A92C 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
s32 strtol_related_0(s32 arg0) {
    // Node 0
    if ((((arg0 & 0xff) < 0x30) ^ 1) != 0)
    {
        // Node 1
        return;
        // (possible return value: ((arg0 & 0xff) < 0x3a))
    }
    // (possible return value: (((arg0 & 0xff) < 0x30) ^ 1))
}
#else
GLOBAL_ASM(
.text
glabel strtol_related_0
/* 00B530 7000A930 308E00FF */  andi  $t6, $a0, 0xff
/* 00B534 7000A934 29C20030 */  slti  $v0, $t6, 0x30
/* 00B538 7000A938 38420001 */  xori  $v0, $v0, 1
/* 00B53C 7000A93C 10400002 */  beqz  $v0, .L7000A948
/* 00B540 7000A940 AFA40000 */   sw    $a0, ($sp)
/* 00B544 7000A944 29C2003A */  slti  $v0, $t6, 0x3a
.L7000A948:
/* 00B548 7000A948 03E00008 */  jr    $ra
/* 00B54C 7000A94C 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
s32 strtol_related_1(s32 arg0) {
    s32 temp_t6;

    // Node 0
    temp_t6 = (arg0 & 0xff);
    if ((temp_t6 < 0x61) || (temp_t6 >= 0x7b))
    {
        // Node 2
        if (((temp_t6 < 0x41) ^ 1) != 0)
        {
            // Node 3
            return;
            // (possible return value: (temp_t6 < 0x5b))
        }
    }
    else
    {

    }
    // (possible return value: ((temp_t6 < 0x41) ^ 1))
}
#else
GLOBAL_ASM(
.text
glabel strtol_related_1
/* 00B550 7000A950 308E00FF */  andi  $t6, $a0, 0xff
/* 00B554 7000A954 29C20061 */  slti  $v0, $t6, 0x61
/* 00B558 7000A958 AFA40000 */  sw    $a0, ($sp)
/* 00B55C 7000A95C 14400004 */  bnez  $v0, .L7000A970
/* 00B560 7000A960 01C01825 */   move  $v1, $t6
/* 00B564 7000A964 29C2007B */  slti  $v0, $t6, 0x7b
/* 00B568 7000A968 14400006 */  bnez  $v0, .L7000A984
/* 00B56C 7000A96C 00000000 */   nop   
.L7000A970:
/* 00B570 7000A970 28620041 */  slti  $v0, $v1, 0x41
/* 00B574 7000A974 38420001 */  xori  $v0, $v0, 1
/* 00B578 7000A978 10400002 */  beqz  $v0, .L7000A984
/* 00B57C 7000A97C 00000000 */   nop   
/* 00B580 7000A980 2862005B */  slti  $v0, $v1, 0x5b
.L7000A984:
/* 00B584 7000A984 03E00008 */  jr    $ra
/* 00B588 7000A988 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
s32 strtol_related_2(s32 arg0) {
    s32 temp_t6;

    // Node 0
    temp_t6 = (arg0 & 0xff);
    if ((u32) (temp_t6 ^ 0x20) >= 1U)
    {
        // Node 1
        if ((u32) (temp_t6 ^ 9) >= 1U)
        {
            // Node 2
            if ((u32) (temp_t6 ^ 0xa) >= 1U)
            {
                // Node 3
                if ((u32) (temp_t6 ^ 0xc) >= 1U)
                {
                    // Node 4
                    return;
                    // (possible return value: ((u32) (temp_t6 ^ 0xb) < 1U))
                }
            }
        }
    }
    // (possible return value: ((u32) (temp_t6 ^ 0x20) < 1U))
}
#else
GLOBAL_ASM(
.text
glabel strtol_related_2
/* 00B58C 7000A98C 308E00FF */  andi  $t6, $a0, 0xff
/* 00B590 7000A990 39C20020 */  xori  $v0, $t6, 0x20
/* 00B594 7000A994 2C420001 */  sltiu $v0, $v0, 1
/* 00B598 7000A998 1440000F */  bnez  $v0, .L7000A9D8
/* 00B59C 7000A99C AFA40000 */   sw    $a0, ($sp)
/* 00B5A0 7000A9A0 39C20009 */  xori  $v0, $t6, 9
/* 00B5A4 7000A9A4 2C420001 */  sltiu $v0, $v0, 1
/* 00B5A8 7000A9A8 1440000B */  bnez  $v0, .L7000A9D8
/* 00B5AC 7000A9AC 00000000 */   nop   
/* 00B5B0 7000A9B0 39C2000A */  xori  $v0, $t6, 0xa
/* 00B5B4 7000A9B4 2C420001 */  sltiu $v0, $v0, 1
/* 00B5B8 7000A9B8 14400007 */  bnez  $v0, .L7000A9D8
/* 00B5BC 7000A9BC 00000000 */   nop   
/* 00B5C0 7000A9C0 39C2000C */  xori  $v0, $t6, 0xc
/* 00B5C4 7000A9C4 2C420001 */  sltiu $v0, $v0, 1
/* 00B5C8 7000A9C8 14400003 */  bnez  $v0, .L7000A9D8
/* 00B5CC 7000A9CC 00000000 */   nop   
/* 00B5D0 7000A9D0 39C2000B */  xori  $v0, $t6, 0xb
/* 00B5D4 7000A9D4 2C420001 */  sltiu $v0, $v0, 1
.L7000A9D8:
/* 00B5D8 7000A9D8 03E00008 */  jr    $ra
/* 00B5DC 7000A9DC 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void strtol(void) {

}
#else
GLOBAL_ASM(
.text
glabel strtol
/* 00B5E0 7000A9E0 27BDFFA0 */  addiu $sp, $sp, -0x60
/* 00B5E4 7000A9E4 AFB30024 */  sw    $s3, 0x24($sp)
/* 00B5E8 7000A9E8 00C09825 */  move  $s3, $a2
/* 00B5EC 7000A9EC AFBF002C */  sw    $ra, 0x2c($sp)
/* 00B5F0 7000A9F0 AFB40028 */  sw    $s4, 0x28($sp)
/* 00B5F4 7000A9F4 AFB20020 */  sw    $s2, 0x20($sp)
/* 00B5F8 7000A9F8 AFB1001C */  sw    $s1, 0x1c($sp)
/* 00B5FC 7000A9FC AFB00018 */  sw    $s0, 0x18($sp)
/* 00B600 7000AA00 AFA50064 */  sw    $a1, 0x64($sp)
/* 00B604 7000AA04 04C00006 */  bltz  $a2, .L7000AA20
/* 00B608 7000AA08 00803825 */   move  $a3, $a0
/* 00B60C 7000AA0C 24010001 */  li    $at, 1
/* 00B610 7000AA10 10C10003 */  beq   $a2, $at, .L7000AA20
/* 00B614 7000AA14 28C10025 */   slti  $at, $a2, 0x25
/* 00B618 7000AA18 54200003 */  bnezl $at, .L7000AA28
/* 00B61C 7000AA1C 90E40000 */   lbu   $a0, ($a3)
.L7000AA20:
/* 00B620 7000AA20 2413000A */  li    $s3, 10
/* 00B624 7000AA24 90E40000 */  lbu   $a0, ($a3)
.L7000AA28:
/* 00B628 7000AA28 00E09025 */  move  $s2, $a3
/* 00B62C 7000AA2C 0C002A63 */  jal   strtol_related_2
/* 00B630 7000AA30 AFA70060 */   sw    $a3, 0x60($sp)
/* 00B634 7000AA34 50400007 */  beql  $v0, $zero, .L7000AA54
/* 00B638 7000AA38 92420000 */   lbu   $v0, ($s2)
/* 00B63C 7000AA3C 26520001 */  addiu $s2, $s2, 1
.L7000AA40:
/* 00B640 7000AA40 0C002A63 */  jal   strtol_related_2
/* 00B644 7000AA44 92440000 */   lbu   $a0, ($s2)
/* 00B648 7000AA48 5440FFFD */  bnezl $v0, .L7000AA40
/* 00B64C 7000AA4C 26520001 */   addiu $s2, $s2, 1
/* 00B650 7000AA50 92420000 */  lbu   $v0, ($s2)
.L7000AA54:
/* 00B654 7000AA54 2401002D */  li    $at, 45
/* 00B658 7000AA58 50400075 */  beql  $v0, $zero, .L7000AC30
/* 00B65C 7000AA5C 8FA20064 */   lw    $v0, 0x64($sp)
/* 00B660 7000AA60 14410004 */  bne   $v0, $at, .L7000AA74
/* 00B664 7000AA64 240E0001 */   li    $t6, 1
/* 00B668 7000AA68 AFAE005C */  sw    $t6, 0x5c($sp)
/* 00B66C 7000AA6C 10000008 */  b     .L7000AA90
/* 00B670 7000AA70 26520001 */   addiu $s2, $s2, 1
.L7000AA74:
/* 00B674 7000AA74 2401002B */  li    $at, 43
/* 00B678 7000AA78 54410005 */  bnel  $v0, $at, .L7000AA90
/* 00B67C 7000AA7C AFA0005C */   sw    $zero, 0x5c($sp)
/* 00B680 7000AA80 AFA0005C */  sw    $zero, 0x5c($sp)
/* 00B684 7000AA84 10000002 */  b     .L7000AA90
/* 00B688 7000AA88 26520001 */   addiu $s2, $s2, 1
/* 00B68C 7000AA8C AFA0005C */  sw    $zero, 0x5c($sp)
.L7000AA90:
/* 00B690 7000AA90 24010010 */  li    $at, 16
/* 00B694 7000AA94 1661000B */  bne   $s3, $at, .L7000AAC4
/* 00B698 7000AA98 00000000 */   nop   
/* 00B69C 7000AA9C 924F0000 */  lbu   $t7, ($s2)
/* 00B6A0 7000AAA0 24010030 */  li    $at, 48
/* 00B6A4 7000AAA4 15E10007 */  bne   $t7, $at, .L7000AAC4
/* 00B6A8 7000AAA8 00000000 */   nop   
/* 00B6AC 7000AAAC 0C002A3E */  jal   strtol_related
/* 00B6B0 7000AAB0 92440001 */   lbu   $a0, 1($s2)
/* 00B6B4 7000AAB4 24010058 */  li    $at, 88
/* 00B6B8 7000AAB8 14410002 */  bne   $v0, $at, .L7000AAC4
/* 00B6BC 7000AABC 00000000 */   nop   
/* 00B6C0 7000AAC0 26520002 */  addiu $s2, $s2, 2
.L7000AAC4:
/* 00B6C4 7000AAC4 1660000E */  bnez  $s3, .L7000AB00
/* 00B6C8 7000AAC8 92420000 */   lbu   $v0, ($s2)
/* 00B6CC 7000AACC 24010030 */  li    $at, 48
/* 00B6D0 7000AAD0 1441000B */  bne   $v0, $at, .L7000AB00
/* 00B6D4 7000AAD4 2413000A */   li    $s3, 10
/* 00B6D8 7000AAD8 0C002A3E */  jal   strtol_related
/* 00B6DC 7000AADC 92440001 */   lbu   $a0, 1($s2)
/* 00B6E0 7000AAE0 24010058 */  li    $at, 88
/* 00B6E4 7000AAE4 14410004 */  bne   $v0, $at, .L7000AAF8
/* 00B6E8 7000AAE8 24130008 */   li    $s3, 8
/* 00B6EC 7000AAEC 26520002 */  addiu $s2, $s2, 2
/* 00B6F0 7000AAF0 10000001 */  b     .L7000AAF8
/* 00B6F4 7000AAF4 24130010 */   li    $s3, 16
.L7000AAF8:
/* 00B6F8 7000AAF8 10000001 */  b     .L7000AB00
/* 00B6FC 7000AAFC 92420000 */   lbu   $v0, ($s2)
.L7000AB00:
/* 00B700 7000AB00 305000FF */  andi  $s0, $v0, 0xff
/* 00B704 7000AB04 AFB20044 */  sw    $s2, 0x44($sp)
/* 00B708 7000AB08 AFA00040 */  sw    $zero, 0x40($sp)
/* 00B70C 7000AB0C 00008825 */  move  $s1, $zero
/* 00B710 7000AB10 12000033 */  beqz  $s0, .L7000ABE0
/* 00B714 7000AB14 02001825 */   move  $v1, $s0
/* 00B718 7000AB18 2414FFFF */  li    $s4, -1
.L7000AB1C:
/* 00B71C 7000AB1C 320400FF */  andi  $a0, $s0, 0xff
/* 00B720 7000AB20 0C002A4C */  jal   strtol_related_0
/* 00B724 7000AB24 AFA30034 */   sw    $v1, 0x34($sp)
/* 00B728 7000AB28 10400005 */  beqz  $v0, .L7000AB40
/* 00B72C 7000AB2C 8FA30034 */   lw    $v1, 0x34($sp)
/* 00B730 7000AB30 2470FFD0 */  addiu $s0, $v1, -0x30
/* 00B734 7000AB34 321800FF */  andi  $t8, $s0, 0xff
/* 00B738 7000AB38 1000000A */  b     .L7000AB64
/* 00B73C 7000AB3C 03008025 */   move  $s0, $t8
.L7000AB40:
/* 00B740 7000AB40 0C002A54 */  jal   strtol_related_1
/* 00B744 7000AB44 320400FF */   andi  $a0, $s0, 0xff
/* 00B748 7000AB48 50400026 */  beql  $v0, $zero, .L7000ABE4
/* 00B74C 7000AB4C 8FAA0044 */   lw    $t2, 0x44($sp)
/* 00B750 7000AB50 0C002A3E */  jal   strtol_related
/* 00B754 7000AB54 320400FF */   andi  $a0, $s0, 0xff
/* 00B758 7000AB58 2450FFC9 */  addiu $s0, $v0, -0x37
/* 00B75C 7000AB5C 321900FF */  andi  $t9, $s0, 0xff
/* 00B760 7000AB60 03208025 */  move  $s0, $t9
.L7000AB64:
/* 00B764 7000AB64 0213082A */  slt   $at, $s0, $s3
/* 00B768 7000AB68 1020001D */  beqz  $at, .L7000ABE0
/* 00B76C 7000AB6C 24090001 */   li    $t1, 1
/* 00B770 7000AB70 0293001B */  divu  $zero, $s4, $s3
/* 00B774 7000AB74 00001012 */  mflo  $v0
/* 00B778 7000AB78 0051082B */  sltu  $at, $v0, $s1
/* 00B77C 7000AB7C 16600002 */  bnez  $s3, .L7000AB88
/* 00B780 7000AB80 00000000 */   nop   
/* 00B784 7000AB84 0007000D */  break 7
.L7000AB88:
/* 00B788 7000AB88 1420000B */  bnez  $at, .L7000ABB8
/* 00B78C 7000AB8C 00000000 */   nop   
/* 00B790 7000AB90 1622000B */  bne   $s1, $v0, .L7000ABC0
/* 00B794 7000AB94 00000000 */   nop   
/* 00B798 7000AB98 0293001B */  divu  $zero, $s4, $s3
/* 00B79C 7000AB9C 00004010 */  mfhi  $t0
/* 00B7A0 7000ABA0 0110082B */  sltu  $at, $t0, $s0
/* 00B7A4 7000ABA4 16600002 */  bnez  $s3, .L7000ABB0
/* 00B7A8 7000ABA8 00000000 */   nop   
/* 00B7AC 7000ABAC 0007000D */  break 7
.L7000ABB0:
/* 00B7B0 7000ABB0 10200003 */  beqz  $at, .L7000ABC0
/* 00B7B4 7000ABB4 00000000 */   nop   
.L7000ABB8:
/* 00B7B8 7000ABB8 10000005 */  b     .L7000ABD0
/* 00B7BC 7000ABBC AFA90040 */   sw    $t1, 0x40($sp)
.L7000ABC0:
/* 00B7C0 7000ABC0 02330019 */  multu $s1, $s3
/* 00B7C4 7000ABC4 00008812 */  mflo  $s1
/* 00B7C8 7000ABC8 02308821 */  addu  $s1, $s1, $s0
/* 00B7CC 7000ABCC 00000000 */  nop   
.L7000ABD0:
/* 00B7D0 7000ABD0 92500001 */  lbu   $s0, 1($s2)
/* 00B7D4 7000ABD4 26520001 */  addiu $s2, $s2, 1
/* 00B7D8 7000ABD8 1600FFD0 */  bnez  $s0, .L7000AB1C
/* 00B7DC 7000ABDC 02001825 */   move  $v1, $s0
.L7000ABE0:
/* 00B7E0 7000ABE0 8FAA0044 */  lw    $t2, 0x44($sp)
.L7000ABE4:
/* 00B7E4 7000ABE4 8FA20064 */  lw    $v0, 0x64($sp)
/* 00B7E8 7000ABE8 524A0011 */  beql  $s2, $t2, .L7000AC30
/* 00B7EC 7000ABEC 8FA20064 */   lw    $v0, 0x64($sp)
/* 00B7F0 7000ABF0 50400003 */  beql  $v0, $zero, .L7000AC00
/* 00B7F4 7000ABF4 8FAB0040 */   lw    $t3, 0x40($sp)
/* 00B7F8 7000ABF8 AC520000 */  sw    $s2, ($v0)
/* 00B7FC 7000ABFC 8FAB0040 */  lw    $t3, 0x40($sp)
.L7000AC00:
/* 00B800 7000AC00 8FAC005C */  lw    $t4, 0x5c($sp)
/* 00B804 7000AC04 11600003 */  beqz  $t3, .L7000AC14
/* 00B808 7000AC08 00000000 */   nop   
/* 00B80C 7000AC0C 1000000D */  b     .L7000AC44
/* 00B810 7000AC10 2402FFFF */   li    $v0, -1
.L7000AC14:
/* 00B814 7000AC14 11800003 */  beqz  $t4, .L7000AC24
/* 00B818 7000AC18 02201825 */   move  $v1, $s1
/* 00B81C 7000AC1C 10000009 */  b     .L7000AC44
/* 00B820 7000AC20 00111023 */   negu  $v0, $s1
.L7000AC24:
/* 00B824 7000AC24 10000007 */  b     .L7000AC44
/* 00B828 7000AC28 00601025 */   move  $v0, $v1
/* 00B82C 7000AC2C 8FA20064 */  lw    $v0, 0x64($sp)
.L7000AC30:
/* 00B830 7000AC30 8FAD0060 */  lw    $t5, 0x60($sp)
/* 00B834 7000AC34 50400003 */  beql  $v0, $zero, .L7000AC44
/* 00B838 7000AC38 00001025 */   move  $v0, $zero
/* 00B83C 7000AC3C AC4D0000 */  sw    $t5, ($v0)
/* 00B840 7000AC40 00001025 */  move  $v0, $zero
.L7000AC44:
/* 00B844 7000AC44 8FBF002C */  lw    $ra, 0x2c($sp)
/* 00B848 7000AC48 8FB00018 */  lw    $s0, 0x18($sp)
/* 00B84C 7000AC4C 8FB1001C */  lw    $s1, 0x1c($sp)
/* 00B850 7000AC50 8FB20020 */  lw    $s2, 0x20($sp)
/* 00B854 7000AC54 8FB30024 */  lw    $s3, 0x24($sp)
/* 00B858 7000AC58 8FB40028 */  lw    $s4, 0x28($sp)
/* 00B85C 7000AC5C 03E00008 */  jr    $ra
/* 00B860 7000AC60 27BD0060 */   addiu $sp, $sp, 0x60
)
#endif
