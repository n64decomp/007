#include "ultra64.h"
#include "game/indy_0D0180.h"
#include "game/indy_comms.h"

s32 init_indy_if_not_ready(void) {
    if (indy_ready != 1)
    {
        indy_ready = 1;
        init_indy_if_ready();
    }
}

void nullsub_48(void) {
    return;
}

void init_indy_if_ready(void) {
    if (indy_ready != 0)
    {
        post_indy__res_cmd_initialize();
    }
}


#ifdef NONMATCHING
void load_resource_on_indy(s32 arg1) {
    ? sp18;
    ? sp1C;
    ? sp20;

    // Node 0
    if (indy_ready != 0)
    {
        // Node 1
        sub_GAME_7F0D0BA4(0x400000);
        sub_GAME_7F0D17FC(&sp20, &sp1C, &sp18, arg1);
    }
    // Node 2
    return;
}
#else
GLOBAL_ASM(
.text
glabel load_resource_on_indy
/* 104ACC 7F0CFF9C 3C0E8005 */  lui   $t6, %hi(indy_ready) # $t6, 0x8005
/* 104AD0 7F0CFFA0 8DCEEAC8 */  lw    $t6, %lo(indy_ready)($t6)
/* 104AD4 7F0CFFA4 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 104AD8 7F0CFFA8 AFBF0014 */  sw    $ra, 0x14($sp)
/* 104ADC 7F0CFFAC 11C00008 */  beqz  $t6, .L7F0CFFD0
/* 104AE0 7F0CFFB0 AFA5002C */   sw    $a1, 0x2c($sp)
/* 104AE4 7F0CFFB4 0FC342E9 */  jal   sub_GAME_7F0D0BA4
/* 104AE8 7F0CFFB8 3C050040 */   lui   $a1, 0x40
/* 104AEC 7F0CFFBC 27A40020 */  addiu $a0, $sp, 0x20
/* 104AF0 7F0CFFC0 27A5001C */  addiu $a1, $sp, 0x1c
/* 104AF4 7F0CFFC4 27A60018 */  addiu $a2, $sp, 0x18
/* 104AF8 7F0CFFC8 0FC345FF */  jal   sub_GAME_7F0D17FC
/* 104AFC 7F0CFFCC 8FA7002C */   lw    $a3, 0x2c($sp)
.L7F0CFFD0:
/* 104B00 7F0CFFD0 8FBF0014 */  lw    $ra, 0x14($sp)
/* 104B04 7F0CFFD4 27BD0028 */  addiu $sp, $sp, 0x28
/* 104B08 7F0CFFD8 03E00008 */  jr    $ra
/* 104B0C 7F0CFFDC 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void indy_send_capture_data(s32 arg1, ? arg2) {
    ? sp1C;

    // Node 0
    if (indy_ready != 0)
    {
        // Node 1
        post_indy__res_cmd_send_capture_data(arg2, arg1);
        sub_GAME_7F0D1864(&sp1C);
    }
    // Node 2
    return;
}
#else
GLOBAL_ASM(
.text
glabel indy_send_capture_data
/* 104B10 7F0CFFE0 3C0E8005 */  lui   $t6, %hi(indy_ready) # $t6, 0x8005
/* 104B14 7F0CFFE4 8DCEEAC8 */  lw    $t6, %lo(indy_ready)($t6)
/* 104B18 7F0CFFE8 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 104B1C 7F0CFFEC AFBF0014 */  sw    $ra, 0x14($sp)
/* 104B20 7F0CFFF0 11C00006 */  beqz  $t6, .L7F0D000C
/* 104B24 7F0CFFF4 AFA50024 */   sw    $a1, 0x24($sp)
/* 104B28 7F0CFFF8 00C02825 */  move  $a1, $a2
/* 104B2C 7F0CFFFC 0FC3431A */  jal   post_indy__res_cmd_send_capture_data
/* 104B30 7F0D0000 8FA60024 */   lw    $a2, 0x24($sp)
/* 104B34 7F0D0004 0FC34619 */  jal   sub_GAME_7F0D1864
/* 104B38 7F0D0008 27A4001C */   addiu $a0, $sp, 0x1c
.L7F0D000C:
/* 104B3C 7F0D000C 8FBF0014 */  lw    $ra, 0x14($sp)
/* 104B40 7F0D0010 27BD0020 */  addiu $sp, $sp, 0x20
/* 104B44 7F0D0014 03E00008 */  jr    $ra
/* 104B48 7F0D0018 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void indy_loadfile(void) {
    ? sp1C;
    ? sp20;
    ? sp24;

    // Node 0
    if (indy_ready != 0)
    {
        // Node 1
        post_indy__res_cmd_request_ramrom_file();
        sub_GAME_7F0D18AC(&sp24, &sp20, &sp1C);
    }
    // Node 2
    return;
}
#else
GLOBAL_ASM(
.text
glabel indy_loadfile
/* 104B4C 7F0D001C 3C0E8005 */  lui   $t6, %hi(indy_ready) # $t6, 0x8005
/* 104B50 7F0D0020 8DCEEAC8 */  lw    $t6, %lo(indy_ready)($t6)
/* 104B54 7F0D0024 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 104B58 7F0D0028 AFBF0014 */  sw    $ra, 0x14($sp)
/* 104B5C 7F0D002C 51C00008 */  beql  $t6, $zero, .L7F0D0050
/* 104B60 7F0D0030 8FBF0014 */   lw    $ra, 0x14($sp)
/* 104B64 7F0D0034 0FC34346 */  jal   post_indy__res_cmd_request_ramrom_file
/* 104B68 7F0D0038 00000000 */   nop   
/* 104B6C 7F0D003C 27A40024 */  addiu $a0, $sp, 0x24
/* 104B70 7F0D0040 27A50020 */  addiu $a1, $sp, 0x20
/* 104B74 7F0D0044 0FC3462B */  jal   sub_GAME_7F0D18AC
/* 104B78 7F0D0048 27A6001C */   addiu $a2, $sp, 0x1c
/* 104B7C 7F0D004C 8FBF0014 */  lw    $ra, 0x14($sp)
.L7F0D0050:
/* 104B80 7F0D0050 27BD0028 */  addiu $sp, $sp, 0x28
/* 104B84 7F0D0054 03E00008 */  jr    $ra
/* 104B88 7F0D0058 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void check_file_exported(s32 arg1, ? arg2) {
    ? sp1C;

    // Node 0
    if (indy_ready != 0)
    {
        // Node 1
        sub_GAME_7F0D0DD0(arg2, arg1);
        sub_GAME_7F0D1908(&sp1C);
    }
    // Node 2
    return;
}
#else
GLOBAL_ASM(
.text
glabel check_file_exported
/* 104B8C 7F0D005C 3C0E8005 */  lui   $t6, %hi(indy_ready) # $t6, 0x8005
/* 104B90 7F0D0060 8DCEEAC8 */  lw    $t6, %lo(indy_ready)($t6)
/* 104B94 7F0D0064 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 104B98 7F0D0068 AFBF0014 */  sw    $ra, 0x14($sp)
/* 104B9C 7F0D006C 11C00006 */  beqz  $t6, .L7F0D0088
/* 104BA0 7F0D0070 AFA50024 */   sw    $a1, 0x24($sp)
/* 104BA4 7F0D0074 00C02825 */  move  $a1, $a2
/* 104BA8 7F0D0078 0FC34374 */  jal   sub_GAME_7F0D0DD0
/* 104BAC 7F0D007C 8FA60024 */   lw    $a2, 0x24($sp)
/* 104BB0 7F0D0080 0FC34642 */  jal   sub_GAME_7F0D1908
/* 104BB4 7F0D0084 27A4001C */   addiu $a0, $sp, 0x1c
.L7F0D0088:
/* 104BB8 7F0D0088 8FBF0014 */  lw    $ra, 0x14($sp)
/* 104BBC 7F0D008C 27BD0020 */  addiu $sp, $sp, 0x20
/* 104BC0 7F0D0090 03E00008 */  jr    $ra
/* 104BC4 7F0D0094 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void check_file_found_on_indy(void) {

}
#else
GLOBAL_ASM(
.text
glabel check_file_found_on_indy
/* 104BC8 7F0D0098 3C0E8005 */  lui   $t6, %hi(indy_ready) # $t6, 0x8005
/* 104BCC 7F0D009C 8DCEEAC8 */  lw    $t6, %lo(indy_ready)($t6)
/* 104BD0 7F0D00A0 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 104BD4 7F0D00A4 AFBF0014 */  sw    $ra, 0x14($sp)
/* 104BD8 7F0D00A8 15C00003 */  bnez  $t6, .L7F0D00B8
/* 104BDC 7F0D00AC AFA50024 */   sw    $a1, 0x24($sp)
/* 104BE0 7F0D00B0 10000007 */  b     .L7F0D00D0
/* 104BE4 7F0D00B4 00001025 */   move  $v0, $zero
.L7F0D00B8:
/* 104BE8 7F0D00B8 0FC342C3 */  jal   sub_GAME_7F0D0B0C
/* 104BEC 7F0D00BC 00000000 */   nop   
/* 104BF0 7F0D00C0 27A4001C */  addiu $a0, $sp, 0x1c
/* 104BF4 7F0D00C4 0FC345EB */  jal   sub_GAME_7F0D17AC
/* 104BF8 7F0D00C8 8FA50024 */   lw    $a1, 0x24($sp)
/* 104BFC 7F0D00CC 8FA2001C */  lw    $v0, 0x1c($sp)
.L7F0D00D0:
/* 104C00 7F0D00D0 8FBF0014 */  lw    $ra, 0x14($sp)
/* 104C04 7F0D00D4 27BD0020 */  addiu $sp, $sp, 0x20
/* 104C08 7F0D00D8 03E00008 */  jr    $ra
/* 104C0C 7F0D00DC 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void response_from_command_string(void) {

}
#else
GLOBAL_ASM(
.text
glabel response_from_command_string
/* 104C10 7F0D00E0 3C0E8005 */  lui   $t6, %hi(indy_ready) # $t6, 0x8005
/* 104C14 7F0D00E4 8DCEEAC8 */  lw    $t6, %lo(indy_ready)($t6)
/* 104C18 7F0D00E8 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 104C1C 7F0D00EC AFBF0014 */  sw    $ra, 0x14($sp)
/* 104C20 7F0D00F0 15C00003 */  bnez  $t6, .L7F0D0100
/* 104C24 7F0D00F4 00000000 */   nop   
/* 104C28 7F0D00F8 10000006 */  b     .L7F0D0114
/* 104C2C 7F0D00FC 00001025 */   move  $v0, $zero
.L7F0D0100:
/* 104C30 7F0D0100 0FC3439D */  jal   sub_GAME_7F0D0E74
/* 104C34 7F0D0104 00000000 */   nop   
/* 104C38 7F0D0108 0FC34654 */  jal   sub_GAME_7F0D1950
/* 104C3C 7F0D010C 27A4001C */   addiu $a0, $sp, 0x1c
/* 104C40 7F0D0110 8FA2001C */  lw    $v0, 0x1c($sp)
.L7F0D0114:
/* 104C44 7F0D0114 8FBF0014 */  lw    $ra, 0x14($sp)
/* 104C48 7F0D0118 27BD0020 */  addiu $sp, $sp, 0x20
/* 104C4C 7F0D011C 03E00008 */  jr    $ra
/* 104C50 7F0D0120 00000000 */   nop   
)
#endif


void sub_GAME_7F0D0124(void) {
    if (indy_ready != 0)
    {
        rmon_debug_returns_neg_1();
    }
    return;
}

void send_indy_close_port_cmd(void) {
    response_from_command_string("sleep 5; /etc/killall ghost gload");
}




