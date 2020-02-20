#include "ultra64.h"
#include "joy.h"
const char aJoy_c_debug[] = "joy_c_debug";


char controller_input_index[0x1E0];
s32 dword_CODE_bss_80065110;
s32 dword_CODE_bss_80065114;
s32 dword_CODE_bss_80065118;
s32 dword_CODE_bss_8006511C;
s32 dword_CODE_bss_80065120;
s32 dword_CODE_bss_80065124;
s32 dword_CODE_bss_80065128;
s32 dword_CODE_bss_8006512C;
s32 dword_code_bss_80065130[0x76];
s32 dword_CODE_bss_80065308;
s32 dword_CODE_bss_8006530C;
s32 dword_CODE_bss_80065310;
s32 dword_CODE_bss_80065314;
s32 dword_CODE_bss_80065318;
s32 dword_CODE_bss_8006531C;
s32 dword_CODE_bss_80065320;
s32 dword_CODE_bss_80065324;
//80065328
char contdemoMesg[0x28];
//80065350
OSMesgQueue contdemoMesgMQ;

//80065368
OSMesg cont1Mesg;
OSMesgQueue cont1MesgMQ;

//80065388
OSMesg cont2Mesg;
OSMesgQueue cont2MesgMQ;

//800653a8
OSMesg cont3Mesg;
OSMesgQueue cont3MesgMQ;

//800653c8
OSMesg cont4Mesg;
OSMesgQueue cont4MesgMQ;

//800653e8
s32 player1_controllerstatus;
s32 player2_controllerstatus;
s32 player3_controllerstatus;
s32 player4_controllerstatus;

char player1_controller_packet[0x1A8];


s32 D_800268C0 = 0;
void *ptr_current_point_in_controller_input_index = controller_input_index;
s32 D_800268C8 = 0;
s32 D_800268CC = 0;
u8 num_controller_plugged_in_flags = 0;
s32 num_controller_plugged_in_flags_0 = 0;
s32 controller_1_rumble_inserted = 0;
s32 controller_2_rumble_inserted = 0;
s32 controller_3_rumble_inserted = 0;
s32 controller_4_rumble_inserted = 0;
s32 controller_1_rumble_state = 0;
s32 controller_2_rumble_state = 0;
s32 controller_3_rumble_state = 0;
s32 controller_4_rumble_state = 0;
s32 controller_1_rumble_duration = 0;
s32 controller_2_rumble_duration = 0;
s32 controller_3_rumble_duration = 0;
s32 controller_4_rumble_duration = 0;
s32 controller_1_rumble_pulse = 0;
s32 controller_2_rumble_pulse = 0;
s32 controller_3_rumble_pulse = 0;
s32 controller_4_rumble_pulse = 0;
s32 enableControllers = 0;
s32 D_8002691C = 0;
s32 D_80026920 = 0;
s32 disable_all_rumble = 0;
s32 ptr_to_tlb_ramrom_record = 0;
s32 D_8002692C = 1;
s32 pl1_controller_failure_lr = 0;
s32 pl2_controller_failure_lr = 0;
s32 pl3_controller_failure_lr = 0;
s32 pl4_controller_failure_lr = 0;
s32 pl1_controller_failure_ud = 0;
s32 pl2_controller_failure_ud = 0;
s32 pl3_controller_failure_ud = 0;
s32 pl4_controller_failure_ud = 0;
s32 pl1_controller_failure_held = 0;
s32 pl2_controller_failure_held = 0;
s32 pl3_controller_failure_held = 0;
s32 pl4_controller_failure_held = 0;
s32 pl1_controller_failure_pressed = 0;
s32 pl2_controller_failure_pressed = 0;
s32 pl3_controller_failure_pressed = 0;
s32 pl4_controller_failure_pressed = 0;
s32 D_80026970 = 0;








#ifdef NONMATCHING
void *something_with_joy_c_debug(void) {
    void *temp_v0;
    void *temp_v0_2;

    // Node 0
    get_ptr_debug_notice_list_entry(&D_800268C0, &aJoy_c_debug);
    osCreateMesgQueue(&cont1MesgMQ, &cont1Mesg, 1);
    osCreateMesgQueue(&cont2MesgMQ, &cont2Mesg, 1);
    osCreateMesgQueue(&cont3MesgMQ, &cont3Mesg, 1);
    osCreateMesgQueue(&cont4MesgMQ, &cont4Mesg, 1);
    osCreateMesgQueue(&contdemoMesgMQ, &contdemoMesg, 0xa);
    osSetEventMesg(5, &contdemoMesgMQ, 0);
    enableControllers = 1;
    disable_all_rumble = 0;
    temp_v0 = (0x80060000 + 0x4f30);
    ptr_to_tlb_ramrom_record = 0;
    // Node 1
    temp_v0->unk1E0 = 0;
    temp_v0->unk1E4 = 0;
    temp_v0->unk1E8 = 0;
    temp_v0->unk1EC = 0;
    temp_v0->unk1F8 = -1;
    temp_v0_2 = (temp_v0 + 0x1fc);
    temp_v0_2->unk-1E6 = (u8)0;
    temp_v0_2->unk-1E7 = (u8)0;
    temp_v0_2->unk-1E8 = (u8)0;
    temp_v0_2->unk-1EA = (u16)0;
    temp_v0_2->unk-1EC = (u8)0;
    temp_v0_2->unk-1ED = (u8)0;
    temp_v0_2->unk-1EE = (u8)0;
    temp_v0_2->unk-1F0 = (u16)0;
    temp_v0_2->unk-1F2 = (u8)0;
    temp_v0_2->unk-1F3 = (u8)0;
    temp_v0_2->unk-1F4 = (u8)0;
    temp_v0_2->unk-1F6 = (u16)0;
    temp_v0_2->unk-1FC = (u16)0;
    temp_v0_2->unk-1FA = (u8)0;
    temp_v0_2->unk-1F9 = (u8)0;
    temp_v0_2->unk-1F8 = (u8)0;
    if (temp_v0_2 != &contdemoMesg)
    {
        goto loop_1;
    }
    // (possible return value: temp_v0_2)
}
#else
GLOBAL_ASM(
.text
glabel something_with_joy_c_debug
/* 00C160 7000B560 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 00C164 7000B564 AFBF0014 */  sw    $ra, 0x14($sp)
/* 00C168 7000B568 3C048002 */  lui   $a0, %hi(D_800268C0)
/* 00C16C 7000B56C 3C058003 */  lui   $a1, %hi(aJoy_c_debug)
/* 00C170 7000B570 24A59390 */  addiu $a1, %lo(aJoy_c_debug) # addiu $a1, $a1, -0x6c70
/* 00C174 7000B574 0C001398 */  jal   get_ptr_debug_notice_list_entry
/* 00C178 7000B578 248468C0 */   addiu $a0, %lo(D_800268C0) # addiu $a0, $a0, 0x68c0
/* 00C17C 7000B57C 3C048006 */  lui   $a0, %hi(cont1MesgMQ)
/* 00C180 7000B580 3C058006 */  lui   $a1, %hi(cont1Mesg)
/* 00C184 7000B584 24A55368 */  addiu $a1, %lo(cont1Mesg) # addiu $a1, $a1, 0x5368
/* 00C188 7000B588 24845370 */  addiu $a0, %lo(cont1MesgMQ) # addiu $a0, $a0, 0x5370
/* 00C18C 7000B58C 0C0035B4 */  jal   osCreateMesgQueue
/* 00C190 7000B590 24060001 */   li    $a2, 1
/* 00C194 7000B594 3C048006 */  lui   $a0, %hi(cont2MesgMQ)
/* 00C198 7000B598 3C058006 */  lui   $a1, %hi(cont2Mesg)
/* 00C19C 7000B59C 24A55388 */  addiu $a1, %lo(cont2Mesg) # addiu $a1, $a1, 0x5388
/* 00C1A0 7000B5A0 24845390 */  addiu $a0, %lo(cont2MesgMQ) # addiu $a0, $a0, 0x5390
/* 00C1A4 7000B5A4 0C0035B4 */  jal   osCreateMesgQueue
/* 00C1A8 7000B5A8 24060001 */   li    $a2, 1
/* 00C1AC 7000B5AC 3C048006 */  lui   $a0, %hi(cont3MesgMQ)
/* 00C1B0 7000B5B0 3C058006 */  lui   $a1, %hi(cont3Mesg)
/* 00C1B4 7000B5B4 24A553A8 */  addiu $a1, %lo(cont3Mesg) # addiu $a1, $a1, 0x53a8
/* 00C1B8 7000B5B8 248453B0 */  addiu $a0, %lo(cont3MesgMQ) # addiu $a0, $a0, 0x53b0
/* 00C1BC 7000B5BC 0C0035B4 */  jal   osCreateMesgQueue
/* 00C1C0 7000B5C0 24060001 */   li    $a2, 1
/* 00C1C4 7000B5C4 3C048006 */  lui   $a0, %hi(cont4MesgMQ)
/* 00C1C8 7000B5C8 3C058006 */  lui   $a1, %hi(cont4Mesg)
/* 00C1CC 7000B5CC 24A553C8 */  addiu $a1, %lo(cont4Mesg) # addiu $a1, $a1, 0x53c8
/* 00C1D0 7000B5D0 248453D0 */  addiu $a0, %lo(cont4MesgMQ) # addiu $a0, $a0, 0x53d0
/* 00C1D4 7000B5D4 0C0035B4 */  jal   osCreateMesgQueue
/* 00C1D8 7000B5D8 24060001 */   li    $a2, 1
/* 00C1DC 7000B5DC 3C048006 */  lui   $a0, %hi(contdemoMesgMQ)
/* 00C1E0 7000B5E0 3C058006 */  lui   $a1, %hi(contdemoMesg)
/* 00C1E4 7000B5E4 24A55328 */  addiu $a1, %lo(contdemoMesg) # addiu $a1, $a1, 0x5328
/* 00C1E8 7000B5E8 24845350 */  addiu $a0, %lo(contdemoMesgMQ) # addiu $a0, $a0, 0x5350
/* 00C1EC 7000B5EC 0C0035B4 */  jal   osCreateMesgQueue
/* 00C1F0 7000B5F0 2406000A */   li    $a2, 10
/* 00C1F4 7000B5F4 3C058006 */  lui   $a1, %hi(contdemoMesgMQ)
/* 00C1F8 7000B5F8 24A55350 */  addiu $a1, %lo(contdemoMesgMQ) # addiu $a1, $a1, 0x5350
/* 00C1FC 7000B5FC 24040005 */  li    $a0, 5
/* 00C200 7000B600 0C003714 */  jal   osSetEventMesg
/* 00C204 7000B604 00003025 */   move  $a2, $zero
/* 00C208 7000B608 240E0001 */  li    $t6, 1
/* 00C20C 7000B60C 3C018002 */  lui   $at, %hi(enableControllers)
/* 00C210 7000B610 AC2E6918 */  sw    $t6, %lo(enableControllers)($at)
/* 00C214 7000B614 3C018002 */  lui   $at, %hi(disable_all_rumble)
/* 00C218 7000B618 AC206924 */  sw    $zero, %lo(disable_all_rumble)($at)
/* 00C21C 7000B61C 3C0F8006 */  lui   $t7, %hi(controller_input_index)
/* 00C220 7000B620 3C018002 */  lui   $at, %hi(ptr_to_tlb_ramrom_record)
/* 00C224 7000B624 25E24F30 */  addiu $v0, $t7, %lo(controller_input_index)
/* 00C228 7000B628 3C058006 */  lui   $a1, %hi(contdemoMesg)
/* 00C22C 7000B62C AC206928 */  sw    $zero, %lo(ptr_to_tlb_ramrom_record)($at)
/* 00C230 7000B630 24A55328 */  addiu $a1, %lo(contdemoMesg) # addiu $a1, $a1, 0x5328
/* 00C234 7000B634 00401825 */  move  $v1, $v0
/* 00C238 7000B638 2404FFFF */  li    $a0, -1
.L7000B63C:
/* 00C23C 7000B63C AC6001E0 */  sw    $zero, 0x1e0($v1)
/* 00C240 7000B640 AC6001E4 */  sw    $zero, 0x1e4($v1)
/* 00C244 7000B644 AC6001E8 */  sw    $zero, 0x1e8($v1)
/* 00C248 7000B648 AC6001EC */  sw    $zero, 0x1ec($v1)
/* 00C24C 7000B64C AC6401F8 */  sw    $a0, 0x1f8($v1)
/* 00C250 7000B650 244201FC */  addiu $v0, $v0, 0x1fc
/* 00C254 7000B654 246301FC */  addiu $v1, $v1, 0x1fc
/* 00C258 7000B658 A040FE1A */  sb    $zero, -0x1e6($v0)
/* 00C25C 7000B65C A040FE19 */  sb    $zero, -0x1e7($v0)
/* 00C260 7000B660 A040FE18 */  sb    $zero, -0x1e8($v0)
/* 00C264 7000B664 A440FE16 */  sh    $zero, -0x1ea($v0)
/* 00C268 7000B668 A040FE14 */  sb    $zero, -0x1ec($v0)
/* 00C26C 7000B66C A040FE13 */  sb    $zero, -0x1ed($v0)
/* 00C270 7000B670 A040FE12 */  sb    $zero, -0x1ee($v0)
/* 00C274 7000B674 A440FE10 */  sh    $zero, -0x1f0($v0)
/* 00C278 7000B678 A040FE0E */  sb    $zero, -0x1f2($v0)
/* 00C27C 7000B67C A040FE0D */  sb    $zero, -0x1f3($v0)
/* 00C280 7000B680 A040FE0C */  sb    $zero, -0x1f4($v0)
/* 00C284 7000B684 A440FE0A */  sh    $zero, -0x1f6($v0)
/* 00C288 7000B688 A440FE04 */  sh    $zero, -0x1fc($v0)
/* 00C28C 7000B68C A040FE06 */  sb    $zero, -0x1fa($v0)
/* 00C290 7000B690 A040FE07 */  sb    $zero, -0x1f9($v0)
/* 00C294 7000B694 1445FFE9 */  bne   $v0, $a1, .L7000B63C
/* 00C298 7000B698 A040FE08 */   sb    $zero, -0x1f8($v0)
/* 00C29C 7000B69C 8FBF0014 */  lw    $ra, 0x14($sp)
/* 00C2A0 7000B6A0 27BD0018 */  addiu $sp, $sp, 0x18
/* 00C2A4 7000B6A4 03E00008 */  jr    $ra
/* 00C2A8 7000B6A8 00000000 */   nop   
)
#endif




void test_controller_presence(void)
{
    OSMesg  sp1C;

    if (enableControllers != 0)
    {
        osSendMesg(&cont1MesgMQ, &sp1C, 0);
        osRecvMesg(&cont2MesgMQ, &sp1C, 1);
        controller_check_for_rumble_maybe();
        osSendMesg(&cont3MesgMQ, &sp1C, 0);
        osRecvMesg(&cont4MesgMQ, &sp1C, 1);
    }
}

s32 osPfsChecker(u32 *param_1) //OSPfs *param_1
{
    return 3;
}






#ifdef NONMATCHING
s32 controller_7000B734(s32 arg0)
{
    s32 temp_ret;
    s32 temp_ret_2;
    s32 temp_v0;
    void *temp_a3;
    void *temp_v1;
    s32 phi_return;

    temp_v0 = arg0 * 4;
    temp_a3 = temp_v0 + &controller_1_rumble_inserted;
    phi_return = temp_v0;
    if (*temp_a3 >= 0)
    {
        temp_v1 = temp_v0 + &player1_controllerstatus;
        phi_return = temp_v0;
        if ((temp_v1->unk0 & 4) != 0)
        {
            phi_return = temp_v0;
            if ((temp_v1->unk2 & 1) != 0)
            {
                temp_ret = osPfsInit(&contdemoMesgMQ, (arg0 * 0x68) + &player1_controller_packet, arg0, temp_a3);
                if ((temp_ret == 0xa) || (temp_ret == 0xb))
                {
                    temp_ret_2 = controller_7000CD38(&contdemoMesgMQ, sp20, arg0, sp1C);
                    if (temp_ret_2 == 0)
                    {
                        *sp1C = 1;
                        return temp_ret_2;
                    }
                    *sp1C = -1;
                    phi_return = temp_ret_2;
                }
                else
                {

                }
            }
        }
    }
    return phi_return;
}
#else
GLOBAL_ASM(
.text
glabel controller_7000B734
/* 00C334 7000B734 3C0E8002 */  lui   $t6, %hi(controller_1_rumble_inserted) 
/* 00C338 7000B738 25CE68D8 */  addiu $t6, %lo(controller_1_rumble_inserted) # addiu $t6, $t6, 0x68d8
/* 00C33C 7000B73C 00041080 */  sll   $v0, $a0, 2
/* 00C340 7000B740 004E3821 */  addu  $a3, $v0, $t6
/* 00C344 7000B744 8CEF0000 */  lw    $t7, ($a3)
/* 00C348 7000B748 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 00C34C 7000B74C AFBF0014 */  sw    $ra, 0x14($sp)
/* 00C350 7000B750 05E0002B */  bltz  $t7, .L7000B800
/* 00C354 7000B754 00803025 */   move  $a2, $a0
/* 00C358 7000B758 3C188006 */  lui   $t8, %hi(player1_controllerstatus) 
/* 00C35C 7000B75C 271853E8 */  addiu $t8, %lo(player1_controllerstatus) # addiu $t8, $t8, 0x53e8
/* 00C360 7000B760 00581821 */  addu  $v1, $v0, $t8
/* 00C364 7000B764 94790000 */  lhu   $t9, ($v1)
/* 00C368 7000B768 33280004 */  andi  $t0, $t9, 4
/* 00C36C 7000B76C 51000025 */  beql  $t0, $zero, .L7000B804
/* 00C370 7000B770 8FBF0014 */   lw    $ra, 0x14($sp)
/* 00C374 7000B774 90690002 */  lbu   $t1, 2($v1)
/* 00C378 7000B778 3C048006 */  lui   $a0, %hi(contdemoMesgMQ)
/* 00C37C 7000B77C 24845350 */  addiu $a0, %lo(contdemoMesgMQ) # addiu $a0, $a0, 0x5350
/* 00C380 7000B780 312A0001 */  andi  $t2, $t1, 1
/* 00C384 7000B784 1140001E */  beqz  $t2, .L7000B800
/* 00C388 7000B788 00065880 */   sll   $t3, $a2, 2
/* 00C38C 7000B78C 01665823 */  subu  $t3, $t3, $a2
/* 00C390 7000B790 000B5880 */  sll   $t3, $t3, 2
/* 00C394 7000B794 01665821 */  addu  $t3, $t3, $a2
/* 00C398 7000B798 3C0C8006 */  lui   $t4, %hi(player1_controller_packet) 
/* 00C39C 7000B79C 258C53F8 */  addiu $t4, %lo(player1_controller_packet) # addiu $t4, $t4, 0x53f8
/* 00C3A0 7000B7A0 000B58C0 */  sll   $t3, $t3, 3
/* 00C3A4 7000B7A4 016C2821 */  addu  $a1, $t3, $t4
/* 00C3A8 7000B7A8 AFA50020 */  sw    $a1, 0x20($sp)
/* 00C3AC 7000B7AC AFA60028 */  sw    $a2, 0x28($sp)
/* 00C3B0 7000B7B0 0C0051D0 */  jal   osPfsInit
/* 00C3B4 7000B7B4 AFA7001C */   sw    $a3, 0x1c($sp)
/* 00C3B8 7000B7B8 2401000A */  li    $at, 10
/* 00C3BC 7000B7BC 8FA50020 */  lw    $a1, 0x20($sp)
/* 00C3C0 7000B7C0 8FA60028 */  lw    $a2, 0x28($sp)
/* 00C3C4 7000B7C4 10410003 */  beq   $v0, $at, .L7000B7D4
/* 00C3C8 7000B7C8 8FA7001C */   lw    $a3, 0x1c($sp)
/* 00C3CC 7000B7CC 2401000B */  li    $at, 11
/* 00C3D0 7000B7D0 1441000B */  bne   $v0, $at, .L7000B800
.L7000B7D4:
/* 00C3D4 7000B7D4 3C048006 */   lui   $a0, %hi(contdemoMesgMQ)
/* 00C3D8 7000B7D8 24845350 */  addiu $a0, %lo(contdemoMesgMQ) # addiu $a0, $a0, 0x5350
/* 00C3DC 7000B7DC 0C00334E */  jal   controller_7000CD38
/* 00C3E0 7000B7E0 AFA7001C */   sw    $a3, 0x1c($sp)
/* 00C3E4 7000B7E4 14400004 */  bnez  $v0, .L7000B7F8
/* 00C3E8 7000B7E8 8FA7001C */   lw    $a3, 0x1c($sp)
/* 00C3EC 7000B7EC 240D0001 */  li    $t5, 1
/* 00C3F0 7000B7F0 10000003 */  b     .L7000B800
/* 00C3F4 7000B7F4 ACED0000 */   sw    $t5, ($a3)
.L7000B7F8:
/* 00C3F8 7000B7F8 240EFFFF */  li    $t6, -1
/* 00C3FC 7000B7FC ACEE0000 */  sw    $t6, ($a3)
.L7000B800:
/* 00C400 7000B800 8FBF0014 */  lw    $ra, 0x14($sp)
.L7000B804:
/* 00C404 7000B804 27BD0028 */  addiu $sp, $sp, 0x28
/* 00C408 7000B808 03E00008 */  jr    $ra
/* 00C40C 7000B80C 00000000 */   nop   
)
#endif



#ifdef NONMATCHING
s32 controller_check_for_rumble_maybe(void)
{
    s32 temp_a0;
    s32 temp_a1;
    s32 temp_s0;
    s32 temp_s0_2;
    s32 temp_v0_2;
    u32 temp_v1;
    void *temp_v0;
    s8 phi_s0;
    s32 phi_s0_2;
    s32 phi_s0_3;
    void *phi_a3;
    void *phi_a2;
    u32 phi_v1;
    s32 phi_a1;
    void *phi_a3_2;
    s32 phi_return;
    s8 phi_s0_4;
    s32 phi_return_2;
    s8 phi_s0_5;
    s8 phi_s0_6;

    if (D_8002692C != 0)
    {
        D_8002692C = 0;
        D_8002691C = 1;
        phi_return_2 = osContInit(&contdemoMesgMQ, &num_controller_plugged_in_flags, &player1_controllerstatus);
    }
    else
    {
        osContStartQuery(&contdemoMesgMQ);
        osRecvMesg(&contdemoMesgMQ, 0, 1);
        phi_s0_6 = (u8)0xf;
        if ((*(player1_controllerstatus + 3) & 8) != 0)
        {
            phi_s0_6 = (u8)0xe;
        }
        phi_s0_5 = phi_s0_6;
        if ((*(player2_controllerstatus + 3) & 8) != 0)
        {
            phi_s0_5 = phi_s0_6 + -2;
        }
        phi_s0_4 = phi_s0_5;
        if ((*(player3_controllerstatus + 3) & 8) != 0)
        {
            phi_s0_4 = phi_s0_5 + -4;
        }
        phi_s0 = phi_s0_4;
        if ((*(player4_controllerstatus + 3) & 8) != 0)
        {
            phi_s0 = phi_s0_4 + -8;
        }
        num_controller_plugged_in_flags = (s8) phi_s0;
        phi_return_2 = osContGetQuery(&player1_controllerstatus);
    }
    phi_s0_2 = 0;
loop_12:
    temp_s0 = (s32) ((phi_s0_2 + 1) << 0x18) >> 0x18;
    phi_s0_2 = temp_s0;
    if (temp_s0 < 4)
    {
        goto loop_12;
    }
    phi_s0_3 = 0;
    phi_a3 = &num_controller_plugged_in_flags_0;
    phi_a2 = &controller_1_rumble_inserted;
loop_14:
    temp_a1 = 1 << phi_s0_3;
    temp_v1 = *phi_a3;
    if ((((num_controller_plugged_in_flags & temp_a1) != 0) && ((temp_v0->unk0 & 3) != 0)) && (temp_v0->unk3 == 0))
    {
        if (((temp_v0_2 & temp_a1) != 0) || (*(phi_a2 + temp_a0) <= 0))
        {
            phi_v1 = num_controller_plugged_in_flags_0;
            phi_a1 = sp24;
            phi_a3_2 = &num_controller_plugged_in_flags_0;
            phi_return = controller_7000B734(phi_s0_3, temp_a1, phi_a2, phi_a3);
            phi_a2 = &controller_1_rumble_inserted;
        }
        else
        {

        }
        *phi_a3_2 = (s8) (phi_v1 | phi_a1);
        phi_a3 = phi_a3_2;
    }
    else
    {
        phi_return = phi_return_2;
        phi_a3 = phi_a3;
        phi_a2 = phi_a2;
        if ((temp_v1 & temp_a1) != 0)
        {
            *phi_a3 = (s8) (temp_v1 ^ temp_a1);
            *(phi_a2 + (phi_s0_3 * 4)) = 0;
            phi_return = phi_return_2;
            phi_a3 = phi_a3;
            phi_a2 = phi_a2;
        }
    }
    temp_s0_2 = (s32) ((phi_s0_3 + 1) << 0x18) >> 0x18;
    phi_s0_3 = temp_s0_2;
    phi_return_2 = phi_return;
    if (temp_s0_2 < 4)
    {
        goto loop_14;
    }
    return phi_return;
}
#else
GLOBAL_ASM(
.text
glabel controller_check_for_rumble_maybe
/* 00C410 7000B810 3C028002 */  lui   $v0, %hi(D_8002692C)
/* 00C414 7000B814 2442692C */  addiu $v0, %lo(D_8002692C) # addiu $v0, $v0, 0x692c
/* 00C418 7000B818 8C4E0000 */  lw    $t6, ($v0)
/* 00C41C 7000B81C 27BDFFC8 */  addiu $sp, $sp, -0x38
/* 00C420 7000B820 AFBF001C */  sw    $ra, 0x1c($sp)
/* 00C424 7000B824 11C0000D */  beqz  $t6, .L7000B85C
/* 00C428 7000B828 AFB00018 */   sw    $s0, 0x18($sp)
/* 00C42C 7000B82C 3C048006 */  lui   $a0, %hi(contdemoMesgMQ)
/* 00C430 7000B830 3C058002 */  lui   $a1, %hi(num_controller_plugged_in_flags)
/* 00C434 7000B834 3C068006 */  lui   $a2, %hi(player1_controllerstatus)
/* 00C438 7000B838 AC400000 */  sw    $zero, ($v0)
/* 00C43C 7000B83C 24C653E8 */  addiu $a2, %lo(player1_controllerstatus) # addiu $a2, $a2, 0x53e8
/* 00C440 7000B840 24A568D0 */  addiu $a1, %lo(num_controller_plugged_in_flags) # addiu $a1, $a1, 0x68d0
/* 00C444 7000B844 0C005240 */  jal   osContInit
/* 00C448 7000B848 24845350 */   addiu $a0, %lo(contdemoMesgMQ) # addiu $a0, $a0, 0x5350
/* 00C44C 7000B84C 240F0001 */  li    $t7, 1
/* 00C450 7000B850 3C018002 */  lui   $at, %hi(D_8002691C)
/* 00C454 7000B854 10000026 */  b     .L7000B8F0
/* 00C458 7000B858 AC2F691C */   sw    $t7, %lo(D_8002691C)($at)
.L7000B85C:
/* 00C45C 7000B85C 3C048006 */  lui   $a0, %hi(contdemoMesgMQ)
/* 00C460 7000B860 2410000F */  li    $s0, 15
/* 00C464 7000B864 0C005330 */  jal   osContStartQuery
/* 00C468 7000B868 24845350 */   addiu $a0, %lo(contdemoMesgMQ) # addiu $a0, $a0, 0x5350
/* 00C46C 7000B86C 3C048006 */  lui   $a0, %hi(contdemoMesgMQ)
/* 00C470 7000B870 24845350 */  addiu $a0, %lo(contdemoMesgMQ) # addiu $a0, $a0, 0x5350
/* 00C474 7000B874 00002825 */  move  $a1, $zero
/* 00C478 7000B878 0C003774 */  jal   osRecvMesg
/* 00C47C 7000B87C 24060001 */   li    $a2, 1
/* 00C480 7000B880 3C048006 */  lui   $a0, %hi(player1_controllerstatus)
/* 00C484 7000B884 0C005351 */  jal   osContGetQuery
/* 00C488 7000B888 248453E8 */   addiu $a0, %lo(player1_controllerstatus) # addiu $a0, $a0, 0x53e8
/* 00C48C 7000B88C 3C188006 */  lui   $t8, %hi(player1_controllerstatus+3) 
/* 00C490 7000B890 931853EB */  lbu   $t8, %lo(player1_controllerstatus+3)($t8)
/* 00C494 7000B894 3C088006 */  lui   $t0, %hi(player2_controllerstatus+3) 
/* 00C498 7000B898 3C0A8006 */  lui   $t2, %hi(player3_controllerstatus+3) 
/* 00C49C 7000B89C 33190008 */  andi  $t9, $t8, 8
/* 00C4A0 7000B8A0 13200002 */  beqz  $t9, .L7000B8AC
/* 00C4A4 7000B8A4 3C0C8006 */   lui   $t4, %hi(player4_controllerstatus+3) 
/* 00C4A8 7000B8A8 2410000E */  li    $s0, 14
.L7000B8AC:
/* 00C4AC 7000B8AC 910853EF */  lbu   $t0, %lo(player2_controllerstatus+3)($t0)
/* 00C4B0 7000B8B0 3C018002 */  lui   $at, %hi(num_controller_plugged_in_flags)
/* 00C4B4 7000B8B4 31090008 */  andi  $t1, $t0, 8
/* 00C4B8 7000B8B8 11200002 */  beqz  $t1, .L7000B8C4
/* 00C4BC 7000B8BC 00000000 */   nop   
/* 00C4C0 7000B8C0 2610FFFE */  addiu $s0, $s0, -2
.L7000B8C4:
/* 00C4C4 7000B8C4 914A53F3 */  lbu   $t2, %lo(player3_controllerstatus+3)($t2)
/* 00C4C8 7000B8C8 314B0008 */  andi  $t3, $t2, 8
/* 00C4CC 7000B8CC 11600002 */  beqz  $t3, .L7000B8D8
/* 00C4D0 7000B8D0 00000000 */   nop   
/* 00C4D4 7000B8D4 2610FFFC */  addiu $s0, $s0, -4
.L7000B8D8:
/* 00C4D8 7000B8D8 918C53F7 */  lbu   $t4, %lo(player4_controllerstatus+3)($t4)
/* 00C4DC 7000B8DC 318D0008 */  andi  $t5, $t4, 8
/* 00C4E0 7000B8E0 11A00002 */  beqz  $t5, .L7000B8EC
/* 00C4E4 7000B8E4 00000000 */   nop   
/* 00C4E8 7000B8E8 2610FFF8 */  addiu $s0, $s0, -8
.L7000B8EC:
/* 00C4EC 7000B8EC A03068D0 */  sb    $s0, %lo(num_controller_plugged_in_flags)($at)
.L7000B8F0:
/* 00C4F0 7000B8F0 00008025 */  move  $s0, $zero
/* 00C4F4 7000B8F4 26100001 */  addiu $s0, $s0, 1
.L7000B8F8:
/* 00C4F8 7000B8F8 00107600 */  sll   $t6, $s0, 0x18
/* 00C4FC 7000B8FC 000E8603 */  sra   $s0, $t6, 0x18
/* 00C500 7000B900 2A010004 */  slti  $at, $s0, 4
/* 00C504 7000B904 5420FFFC */  bnezl $at, .L7000B8F8
/* 00C508 7000B908 26100001 */   addiu $s0, $s0, 1
/* 00C50C 7000B90C 3C078002 */  lui   $a3, %hi(num_controller_plugged_in_flags_0)
/* 00C510 7000B910 3C068002 */  lui   $a2, %hi(controller_1_rumble_inserted)
/* 00C514 7000B914 24C668D8 */  addiu $a2, %lo(controller_1_rumble_inserted) # addiu $a2, $a2, 0x68d8
/* 00C518 7000B918 24E768D4 */  addiu $a3, %lo(num_controller_plugged_in_flags_0) # addiu $a3, $a3, 0x68d4
/* 00C51C 7000B91C 00008025 */  move  $s0, $zero
.L7000B920:
/* 00C520 7000B920 3C198002 */  lui   $t9, %hi(num_controller_plugged_in_flags) 
/* 00C524 7000B924 933968D0 */  lbu   $t9, %lo(num_controller_plugged_in_flags)($t9)
/* 00C528 7000B928 24180001 */  li    $t8, 1
/* 00C52C 7000B92C 02182804 */  sllv  $a1, $t8, $s0
/* 00C530 7000B930 03254024 */  and   $t0, $t9, $a1
/* 00C534 7000B934 1100001E */  beqz  $t0, .L7000B9B0
/* 00C538 7000B938 90E30000 */   lbu   $v1, ($a3)
/* 00C53C 7000B93C 3C098006 */  lui   $t1, %hi(player1_controllerstatus) 
/* 00C540 7000B940 252953E8 */  addiu $t1, %lo(player1_controllerstatus) # addiu $t1, $t1, 0x53e8
/* 00C544 7000B944 00102080 */  sll   $a0, $s0, 2
/* 00C548 7000B948 00891021 */  addu  $v0, $a0, $t1
/* 00C54C 7000B94C 944A0000 */  lhu   $t2, ($v0)
/* 00C550 7000B950 314B0003 */  andi  $t3, $t2, 3
/* 00C554 7000B954 51600017 */  beql  $t3, $zero, .L7000B9B4
/* 00C558 7000B958 0065C824 */   and   $t9, $v1, $a1
/* 00C55C 7000B95C 904C0003 */  lbu   $t4, 3($v0)
/* 00C560 7000B960 2C620001 */  sltiu $v0, $v1, 1
/* 00C564 7000B964 00456824 */  and   $t5, $v0, $a1
/* 00C568 7000B968 55800012 */  bnezl $t4, .L7000B9B4
/* 00C56C 7000B96C 0065C824 */   and   $t9, $v1, $a1
/* 00C570 7000B970 15A00003 */  bnez  $t5, .L7000B980
/* 00C574 7000B974 00C47021 */   addu  $t6, $a2, $a0
/* 00C578 7000B978 8DCF0000 */  lw    $t7, ($t6)
/* 00C57C 7000B97C 1DE00009 */  bgtz  $t7, .L7000B9A4
.L7000B980:
/* 00C580 7000B980 02002025 */   move  $a0, $s0
/* 00C584 7000B984 0C002DCD */  jal   controller_7000B734
/* 00C588 7000B988 AFA50024 */   sw    $a1, 0x24($sp)
/* 00C58C 7000B98C 3C078002 */  lui   $a3, %hi(num_controller_plugged_in_flags_0)
/* 00C590 7000B990 24E768D4 */  addiu $a3, %lo(num_controller_plugged_in_flags_0) # addiu $a3, $a3, 0x68d4
/* 00C594 7000B994 3C068002 */  lui   $a2, %hi(controller_1_rumble_inserted)
/* 00C598 7000B998 24C668D8 */  addiu $a2, %lo(controller_1_rumble_inserted) # addiu $a2, $a2, 0x68d8
/* 00C59C 7000B99C 90E30000 */  lbu   $v1, ($a3)
/* 00C5A0 7000B9A0 8FA50024 */  lw    $a1, 0x24($sp)
.L7000B9A4:
/* 00C5A4 7000B9A4 0065C025 */  or    $t8, $v1, $a1
/* 00C5A8 7000B9A8 10000008 */  b     .L7000B9CC
/* 00C5AC 7000B9AC A0F80000 */   sb    $t8, ($a3)
.L7000B9B0:
/* 00C5B0 7000B9B0 0065C824 */  and   $t9, $v1, $a1
.L7000B9B4:
/* 00C5B4 7000B9B4 13200005 */  beqz  $t9, .L7000B9CC
/* 00C5B8 7000B9B8 00654026 */   xor   $t0, $v1, $a1
/* 00C5BC 7000B9BC 00104880 */  sll   $t1, $s0, 2
/* 00C5C0 7000B9C0 00C95021 */  addu  $t2, $a2, $t1
/* 00C5C4 7000B9C4 A0E80000 */  sb    $t0, ($a3)
/* 00C5C8 7000B9C8 AD400000 */  sw    $zero, ($t2)
.L7000B9CC:
/* 00C5CC 7000B9CC 26100001 */  addiu $s0, $s0, 1
/* 00C5D0 7000B9D0 00105E00 */  sll   $t3, $s0, 0x18
/* 00C5D4 7000B9D4 000B8603 */  sra   $s0, $t3, 0x18
/* 00C5D8 7000B9D8 2A010004 */  slti  $at, $s0, 4
/* 00C5DC 7000B9DC 1420FFD0 */  bnez  $at, .L7000B920
/* 00C5E0 7000B9E0 00000000 */   nop   
/* 00C5E4 7000B9E4 8FBF001C */  lw    $ra, 0x1c($sp)
/* 00C5E8 7000B9E8 8FB00018 */  lw    $s0, 0x18($sp)
/* 00C5EC 7000B9EC 27BD0038 */  addiu $sp, $sp, 0x38
/* 00C5F0 7000B9F0 03E00008 */  jr    $ra
/* 00C5F4 7000B9F4 00000000 */   nop   
)
#endif



#ifdef NONMATCHING
s32 get_attached_controller_count(void)
{
    if (ptr_current_point_in_controller_input_index->unk1F8 >= 0)
    {
        return (s32) (ptr_current_point_in_controller_input_index->unk1F8 << 0x18) >> 0x18;
    }
    if (((void *)0x80020000->unk68D0 & 1) == 0)
    {
        return 0;
    }
    if (((void *)0x80020000->unk68D0 & 2) == 0)
    {
        return 1;
    }
    if (((void *)0x80020000->unk68D0 & 4) == 0)
    {
        return 2;
    }
    if (((void *)0x80020000->unk68D0 & 8) == 0)
    {
        return 3;
    }
    return 4;
}
#else
GLOBAL_ASM(
.text
glabel get_attached_controller_count
/* 00C5F8 7000B9F8 3C0E8002 */  lui   $t6, %hi(ptr_current_point_in_controller_input_index) 
/* 00C5FC 7000B9FC 8DCE68C4 */  lw    $t6, %lo(ptr_current_point_in_controller_input_index)($t6)
/* 00C600 7000BA00 3C028002 */  lui   $v0, %hi(num_controller_plugged_in_flags)
/* 00C604 7000BA04 8DC301F8 */  lw    $v1, 0x1f8($t6)
/* 00C608 7000BA08 04600005 */  bltz  $v1, .L7000BA20
/* 00C60C 7000BA0C 00000000 */   nop   
/* 00C610 7000BA10 00031600 */  sll   $v0, $v1, 0x18
/* 00C614 7000BA14 00027E03 */  sra   $t7, $v0, 0x18
/* 00C618 7000BA18 03E00008 */  jr    $ra
/* 00C61C 7000BA1C 01E01025 */   move  $v0, $t7

.L7000BA20:
/* 00C620 7000BA20 904268D0 */  lbu   $v0, %lo(num_controller_plugged_in_flags)($v0)
/* 00C624 7000BA24 30580001 */  andi  $t8, $v0, 1
/* 00C628 7000BA28 17000003 */  bnez  $t8, .L7000BA38
/* 00C62C 7000BA2C 30590002 */   andi  $t9, $v0, 2
/* 00C630 7000BA30 03E00008 */  jr    $ra
/* 00C634 7000BA34 00001025 */   move  $v0, $zero

.L7000BA38:
/* 00C638 7000BA38 17200003 */  bnez  $t9, .L7000BA48
/* 00C63C 7000BA3C 30480004 */   andi  $t0, $v0, 4
/* 00C640 7000BA40 03E00008 */  jr    $ra
/* 00C644 7000BA44 24020001 */   li    $v0, 1

.L7000BA48:
/* 00C648 7000BA48 15000003 */  bnez  $t0, .L7000BA58
/* 00C64C 7000BA4C 30490008 */   andi  $t1, $v0, 8
/* 00C650 7000BA50 03E00008 */  jr    $ra
/* 00C654 7000BA54 24020002 */   li    $v0, 2

.L7000BA58:
/* 00C658 7000BA58 15200003 */  bnez  $t1, .L7000BA68
/* 00C65C 7000BA5C 24020004 */   li    $v0, 4
/* 00C660 7000BA60 03E00008 */  jr    $ra
/* 00C664 7000BA64 24020003 */   li    $v0, 3

.L7000BA68:
/* 00C668 7000BA68 03E00008 */  jr    $ra
/* 00C66C 7000BA6C 00000000 */   nop   
)
#endif






u8 get_num_controllers_plugged_in(void)
{
    return num_controller_plugged_in_flags;
}







#ifdef NONMATCHING
s32 controller_rumble_related(void) {
    s32 temp_t1;
    s32 temp_a0;

    // Node 0
    // Node 1
    if (controller_1_rumble_state != controller_1_rumble_pulse)
    {
        // Node 2
        temp_a0 = ((0 * 0x68) + &player1_controller_packet);
        if (1 == controller_1_rumble_pulse)
        {
            // Node 3
            if (controller_7000CAAC(temp_a0) == 0)
            {
                // Node 4
                controller_1_rumble_state = 1;
            }
            else
            {
                // Node 5
                *(0 + &controller_1_rumble_inserted) = 0;
            }
        }
        else
        {
            // Node 6
            if (send_rumble_off_to_PIF(temp_a0) == 0)
            {
                // Node 7
                controller_1_rumble_state = 0;
            }
            else
            {
                // Node 8
                *(0 + &controller_1_rumble_inserted) = 0;
            }
        }
    }
    // Node 9
    if (controller_1_rumble_duration <= 0)
    {
        // Node 10
        controller_1_rumble_duration = 0;
    }
    else
    {
        // Node 11
        temp_t1 = (controller_1_rumble_duration + -1);
        controller_1_rumble_duration = temp_t1;
        if (temp_t1 <= 0)
        {
            // Node 12
            controller_1_rumble_duration = 0;
            controller_1_rumble_pulse = 0;
        }
    }
    // Node 13
    if ((0 + 1) != 4)
    {
        goto loop_1;
    }
    // (possible return value: controller_1_rumble_duration)
}
#endif

#ifdef VERSION_US
GLOBAL_ASM(
.text
glabel controller_rumble_related
/* 00C67C 7000BA7C 27BDFFC8 */  addiu $sp, $sp, -0x38
/* 00C680 7000BA80 AFB40028 */  sw    $s4, 0x28($sp)
/* 00C684 7000BA84 AFB1001C */  sw    $s1, 0x1c($sp)
/* 00C688 7000BA88 AFB00018 */  sw    $s0, 0x18($sp)
/* 00C68C 7000BA8C AFB60030 */  sw    $s6, 0x30($sp)
/* 00C690 7000BA90 AFB5002C */  sw    $s5, 0x2c($sp)
/* 00C694 7000BA94 AFB30024 */  sw    $s3, 0x24($sp)
/* 00C698 7000BA98 AFB20020 */  sw    $s2, 0x20($sp)
/* 00C69C 7000BA9C 3C108002 */  lui   $s0, %hi(controller_1_rumble_duration)
/* 00C6A0 7000BAA0 3C118002 */  lui   $s1, %hi(controller_1_rumble_state)
/* 00C6A4 7000BAA4 3C148002 */  lui   $s4, %hi(controller_1_rumble_pulse)
/* 00C6A8 7000BAA8 AFBF0034 */  sw    $ra, 0x34($sp)
/* 00C6AC 7000BAAC 26946908 */  addiu $s4, %lo(controller_1_rumble_pulse) # addiu $s4, $s4, 0x6908
/* 00C6B0 7000BAB0 263168E8 */  addiu $s1, %lo(controller_1_rumble_state) # addiu $s1, $s1, 0x68e8
/* 00C6B4 7000BAB4 261068F8 */  addiu $s0, %lo(controller_1_rumble_duration) # addiu $s0, $s0, 0x68f8
/* 00C6B8 7000BAB8 00009025 */  move  $s2, $zero
/* 00C6BC 7000BABC 00009825 */  move  $s3, $zero
/* 00C6C0 7000BAC0 24150001 */  li    $s5, 1
/* 00C6C4 7000BAC4 24160004 */  li    $s6, 4
.L7000BAC8:
/* 00C6C8 7000BAC8 8E820000 */  lw    $v0, ($s4)
/* 00C6CC 7000BACC 8E2E0000 */  lw    $t6, ($s1)
/* 00C6D0 7000BAD0 00127880 */  sll   $t7, $s2, 2
/* 00C6D4 7000BAD4 01F27823 */  subu  $t7, $t7, $s2
/* 00C6D8 7000BAD8 11C2001A */  beq   $t6, $v0, .L7000BB44
/* 00C6DC 7000BADC 000F7880 */   sll   $t7, $t7, 2
/* 00C6E0 7000BAE0 01F27821 */  addu  $t7, $t7, $s2
/* 00C6E4 7000BAE4 3C188006 */  lui   $t8, %hi(player1_controller_packet) 
/* 00C6E8 7000BAE8 271853F8 */  addiu $t8, %lo(player1_controller_packet) # addiu $t8, $t8, 0x53f8
/* 00C6EC 7000BAEC 000F78C0 */  sll   $t7, $t7, 3
/* 00C6F0 7000BAF0 16A2000B */  bne   $s5, $v0, .L7000BB20
/* 00C6F4 7000BAF4 01F82021 */   addu  $a0, $t7, $t8
/* 00C6F8 7000BAF8 0C0032AB */  jal   controller_7000CAAC
/* 00C6FC 7000BAFC 00000000 */   nop   
/* 00C700 7000BB00 14400003 */  bnez  $v0, .L7000BB10
/* 00C704 7000BB04 3C198002 */   lui   $t9, %hi(controller_1_rumble_inserted) 
/* 00C708 7000BB08 1000000E */  b     .L7000BB44
/* 00C70C 7000BB0C AE350000 */   sw    $s5, ($s1)
.L7000BB10:
/* 00C710 7000BB10 273968D8 */  addiu $t9, %lo(controller_1_rumble_inserted) # addiu $t9, $t9, 0x68d8
/* 00C714 7000BB14 02791021 */  addu  $v0, $s3, $t9
/* 00C718 7000BB18 1000000A */  b     .L7000BB44
/* 00C71C 7000BB1C AC400000 */   sw    $zero, ($v0)
.L7000BB20:
/* 00C720 7000BB20 0C003260 */  jal   send_rumble_off_to_PIF
/* 00C724 7000BB24 00000000 */   nop   
/* 00C728 7000BB28 14400003 */  bnez  $v0, .L7000BB38
/* 00C72C 7000BB2C 3C088002 */   lui   $t0, %hi(controller_1_rumble_inserted) 
/* 00C730 7000BB30 10000004 */  b     .L7000BB44
/* 00C734 7000BB34 AE200000 */   sw    $zero, ($s1)
.L7000BB38:
/* 00C738 7000BB38 250868D8 */  addiu $t0, %lo(controller_1_rumble_inserted) # addiu $t0, $t0, 0x68d8
/* 00C73C 7000BB3C 02681021 */  addu  $v0, $s3, $t0
/* 00C740 7000BB40 AC400000 */  sw    $zero, ($v0)
.L7000BB44:
/* 00C744 7000BB44 8E020000 */  lw    $v0, ($s0)
/* 00C748 7000BB48 26520001 */  addiu $s2, $s2, 1
/* 00C74C 7000BB4C 26730004 */  addiu $s3, $s3, 4
/* 00C750 7000BB50 1C400003 */  bgtz  $v0, .L7000BB60
/* 00C754 7000BB54 26310004 */   addiu $s1, $s1, 4
/* 00C758 7000BB58 10000006 */  b     .L7000BB74
/* 00C75C 7000BB5C AE000000 */   sw    $zero, ($s0)
.L7000BB60:
/* 00C760 7000BB60 2449FFFF */  addiu $t1, $v0, -1
/* 00C764 7000BB64 1D200003 */  bgtz  $t1, .L7000BB74
/* 00C768 7000BB68 AE090000 */   sw    $t1, ($s0)
/* 00C76C 7000BB6C AE000000 */  sw    $zero, ($s0)
/* 00C770 7000BB70 AE800000 */  sw    $zero, ($s4)
.L7000BB74:
/* 00C774 7000BB74 26940004 */  addiu $s4, $s4, 4
/* 00C778 7000BB78 1656FFD3 */  bne   $s2, $s6, .L7000BAC8
/* 00C77C 7000BB7C 26100004 */   addiu $s0, $s0, 4
/* 00C780 7000BB80 8FBF0034 */  lw    $ra, 0x34($sp)
/* 00C784 7000BB84 8FB00018 */  lw    $s0, 0x18($sp)
/* 00C788 7000BB88 8FB1001C */  lw    $s1, 0x1c($sp)
/* 00C78C 7000BB8C 8FB20020 */  lw    $s2, 0x20($sp)
/* 00C790 7000BB90 8FB30024 */  lw    $s3, 0x24($sp)
/* 00C794 7000BB94 8FB40028 */  lw    $s4, 0x28($sp)
/* 00C798 7000BB98 8FB5002C */  lw    $s5, 0x2c($sp)
/* 00C79C 7000BB9C 8FB60030 */  lw    $s6, 0x30($sp)
/* 00C7A0 7000BBA0 03E00008 */  jr    $ra
/* 00C7A4 7000BBA4 27BD0038 */   addiu $sp, $sp, 0x38
)
#endif

#ifdef VERSION_JP
GLOBAL_ASM(
.text
glabel controller_rumble_related
/* 00C68C 7000BA8C 27BDFFC0 */  addiu $sp, $sp, -0x40
/* 00C690 7000BA90 AFB5002C */  sw    $s5, 0x2c($sp)
/* 00C694 7000BA94 AFB20020 */  sw    $s2, 0x20($sp)
/* 00C698 7000BA98 AFB1001C */  sw    $s1, 0x1c($sp)
/* 00C69C 7000BA9C AFBE0038 */  sw    $fp, 0x38($sp)
/* 00C6A0 7000BAA0 AFB70034 */  sw    $s7, 0x34($sp)
/* 00C6A4 7000BAA4 AFB60030 */  sw    $s6, 0x30($sp)
/* 00C6A8 7000BAA8 AFB40028 */  sw    $s4, 0x28($sp)
/* 00C6AC 7000BAAC AFB30024 */  sw    $s3, 0x24($sp)
/* 00C6B0 7000BAB0 3C118002 */  lui   $s1, %hi(controller_1_rumble_duration) # $s1, 0x8002
/* 00C6B4 7000BAB4 3C128002 */  lui   $s2, %hi(controller_1_rumble_state) # $s2, 0x8002
/* 00C6B8 7000BAB8 3C158002 */  lui   $s5, %hi(controller_1_rumble_pulse) # $s5, 0x8002
/* 00C6BC 7000BABC AFBF003C */  sw    $ra, 0x3c($sp)
/* 00C6C0 7000BAC0 AFB00018 */  sw    $s0, 0x18($sp)
/* 00C6C4 7000BAC4 26B56948 */  addiu $s5, %lo(controller_1_rumble_pulse) # addiu $s5, $s5, 0x6948
/* 00C6C8 7000BAC8 26526928 */  addiu $s2, %lo(controller_1_rumble_state) # addiu $s2, $s2, 0x6928
/* 00C6CC 7000BACC 26316938 */  addiu $s1, %lo(controller_1_rumble_duration) # addiu $s1, $s1, 0x6938
/* 00C6D0 7000BAD0 00009825 */  move  $s3, $zero
/* 00C6D4 7000BAD4 0000A025 */  move  $s4, $zero
/* 00C6D8 7000BAD8 24160001 */  li    $s6, 1
/* 00C6DC 7000BADC 24170004 */  li    $s7, 4
/* 00C6E0 7000BAE0 241E0002 */  li    $fp, 2
.Ljp7000BAE4:
/* 00C6E4 7000BAE4 8EA20000 */  lw    $v0, ($s5)
/* 00C6E8 7000BAE8 8E4E0000 */  lw    $t6, ($s2)
/* 00C6EC 7000BAEC 00137880 */  sll   $t7, $s3, 2
/* 00C6F0 7000BAF0 01F37823 */  subu  $t7, $t7, $s3
/* 00C6F4 7000BAF4 11C2002A */  beq   $t6, $v0, .Ljp7000BBA0
/* 00C6F8 7000BAF8 000F7880 */   sll   $t7, $t7, 2
/* 00C6FC 7000BAFC 01F37821 */  addu  $t7, $t7, $s3
/* 00C700 7000BB00 3C188006 */  lui   $t8, %hi(player1_controller_packet) # $t8, 0x8006
/* 00C704 7000BB04 27185438 */  addiu $t8, %lo(player1_controller_packet) # addiu $t8, $t8, 0x5438
/* 00C708 7000BB08 000F78C0 */  sll   $t7, $t7, 3
/* 00C70C 7000BB0C 16C2000B */  bne   $s6, $v0, .Ljp7000BB3C
/* 00C710 7000BB10 01F88021 */   addu  $s0, $t7, $t8
/* 00C714 7000BB14 0C0032BB */  jal   controller_7000CAAC
/* 00C718 7000BB18 02002025 */   move  $a0, $s0
/* 00C71C 7000BB1C 14400003 */  bnez  $v0, .Ljp7000BB2C
/* 00C720 7000BB20 3C198002 */   lui   $t9, %hi(controller_1_rumble_inserted) # $t9, 0x8002
/* 00C724 7000BB24 1000001E */  b     .Ljp7000BBA0
/* 00C728 7000BB28 AE560000 */   sw    $s6, ($s2)
.Ljp7000BB2C:
/* 00C72C 7000BB2C 27396918 */  addiu $t9, %lo(controller_1_rumble_inserted) # addiu $t9, $t9, 0x6918
/* 00C730 7000BB30 02991021 */  addu  $v0, $s4, $t9
/* 00C734 7000BB34 1000001A */  b     .Ljp7000BBA0
/* 00C738 7000BB38 AC400000 */   sw    $zero, ($v0)
.Ljp7000BB3C:
/* 00C73C 7000BB3C 17C2000F */  bne   $fp, $v0, .Ljp7000BB7C
/* 00C740 7000BB40 3C048006 */   lui   $a0, %hi(contdemoMesgMQ) # $a0, 0x8006
/* 00C744 7000BB44 24845390 */  addiu $a0, %lo(contdemoMesgMQ) # addiu $a0, $a0, 0x5390
/* 00C748 7000BB48 02002825 */  move  $a1, $s0
/* 00C74C 7000BB4C 0C00335E */  jal   controller_7000CD38
/* 00C750 7000BB50 02603025 */   move  $a2, $s3
/* 00C754 7000BB54 10400004 */  beqz  $v0, .Ljp7000BB68
/* 00C758 7000BB58 3C088002 */   lui   $t0, %hi(controller_1_rumble_inserted) # $t0, 0x8002
/* 00C75C 7000BB5C 25086918 */  addiu $t0, %lo(controller_1_rumble_inserted) # addiu $t0, $t0, 0x6918
/* 00C760 7000BB60 02881021 */  addu  $v0, $s4, $t0
/* 00C764 7000BB64 AC400000 */  sw    $zero, ($v0)
.Ljp7000BB68:
/* 00C768 7000BB68 0C003270 */  jal   send_rumble_off_to_PIF
/* 00C76C 7000BB6C 02002025 */   move  $a0, $s0
/* 00C770 7000BB70 AE400000 */  sw    $zero, ($s2)
/* 00C774 7000BB74 1000000A */  b     .Ljp7000BBA0
/* 00C778 7000BB78 AEA00000 */   sw    $zero, ($s5)
.Ljp7000BB7C:
/* 00C77C 7000BB7C 0C003270 */  jal   send_rumble_off_to_PIF
/* 00C780 7000BB80 02002025 */   move  $a0, $s0
/* 00C784 7000BB84 14400003 */  bnez  $v0, .Ljp7000BB94
/* 00C788 7000BB88 3C098002 */   lui   $t1, %hi(controller_1_rumble_inserted) # $t1, 0x8002
/* 00C78C 7000BB8C 10000004 */  b     .Ljp7000BBA0
/* 00C790 7000BB90 AE400000 */   sw    $zero, ($s2)
.Ljp7000BB94:
/* 00C794 7000BB94 25296918 */  addiu $t1, %lo(controller_1_rumble_inserted) # addiu $t1, $t1, 0x6918
/* 00C798 7000BB98 02891021 */  addu  $v0, $s4, $t1
/* 00C79C 7000BB9C AC400000 */  sw    $zero, ($v0)
.Ljp7000BBA0:
/* 00C7A0 7000BBA0 8E220000 */  lw    $v0, ($s1)
/* 00C7A4 7000BBA4 26730001 */  addiu $s3, $s3, 1
/* 00C7A8 7000BBA8 26940004 */  addiu $s4, $s4, 4
/* 00C7AC 7000BBAC 1C400003 */  bgtz  $v0, .Ljp7000BBBC
/* 00C7B0 7000BBB0 26520004 */   addiu $s2, $s2, 4
/* 00C7B4 7000BBB4 10000006 */  b     .Ljp7000BBD0
/* 00C7B8 7000BBB8 AE200000 */   sw    $zero, ($s1)
.Ljp7000BBBC:
/* 00C7BC 7000BBBC 244AFFFF */  addiu $t2, $v0, -1
/* 00C7C0 7000BBC0 1D400003 */  bgtz  $t2, .Ljp7000BBD0
/* 00C7C4 7000BBC4 AE2A0000 */   sw    $t2, ($s1)
/* 00C7C8 7000BBC8 AE200000 */  sw    $zero, ($s1)
/* 00C7CC 7000BBCC AEA00000 */  sw    $zero, ($s5)
.Ljp7000BBD0:
/* 00C7D0 7000BBD0 26B50004 */  addiu $s5, $s5, 4
/* 00C7D4 7000BBD4 1677FFC3 */  bne   $s3, $s7, .Ljp7000BAE4
/* 00C7D8 7000BBD8 26310004 */   addiu $s1, $s1, 4
/* 00C7DC 7000BBDC 8FBF003C */  lw    $ra, 0x3c($sp)
/* 00C7E0 7000BBE0 8FB00018 */  lw    $s0, 0x18($sp)
/* 00C7E4 7000BBE4 8FB1001C */  lw    $s1, 0x1c($sp)
/* 00C7E8 7000BBE8 8FB20020 */  lw    $s2, 0x20($sp)
/* 00C7EC 7000BBEC 8FB30024 */  lw    $s3, 0x24($sp)
/* 00C7F0 7000BBF0 8FB40028 */  lw    $s4, 0x28($sp)
/* 00C7F4 7000BBF4 8FB5002C */  lw    $s5, 0x2c($sp)
/* 00C7F8 7000BBF8 8FB60030 */  lw    $s6, 0x30($sp)
/* 00C7FC 7000BBFC 8FB70034 */  lw    $s7, 0x34($sp)
/* 00C800 7000BC00 8FBE0038 */  lw    $fp, 0x38($sp)
/* 00C804 7000BC04 03E00008 */  jr    $ra
/* 00C808 7000BC08 27BD0040 */   addiu $sp, $sp, 0x40
)
#endif





void set_disable_all_rumble_and_something(s32 arg0, s32 arg1) {
    disable_all_rumble = arg0;
    dword_CODE_bss_80065324 = arg1;
}

void set_ptr_tlb_ramrom_record(s32 arg0)
{
    ptr_to_tlb_ramrom_record = arg0;
}






#ifdef NONMATCHING
void probably_ramrom_related(void) {

}
#else
GLOBAL_ASM(
.text
glabel probably_ramrom_related
/* 00C7C8 7000BBC8 8C8E01E0 */  lw    $t6, 0x1e0($a0)
/* 00C7CC 7000BBCC 8C8F01E8 */  lw    $t7, 0x1e8($a0)
/* 00C7D0 7000BBD0 00001025 */  move  $v0, $zero
/* 00C7D4 7000BBD4 24090014 */  li    $t1, 20
/* 00C7D8 7000BBD8 AC8E01E4 */  sw    $t6, 0x1e4($a0)
/* 00C7DC 7000BBDC AC8F01E0 */  sw    $t7, 0x1e0($a0)
/* 00C7E0 7000BBE0 0002C040 */  sll   $t8, $v0, 1
.L7000BBE4:
/* 00C7E4 7000BBE4 00981821 */  addu  $v1, $a0, $t8
/* 00C7E8 7000BBE8 A46001F0 */  sh    $zero, 0x1f0($v1)
/* 00C7EC 7000BBEC 8C9901E0 */  lw    $t9, 0x1e0($a0)
/* 00C7F0 7000BBF0 8C8501E4 */  lw    $a1, 0x1e4($a0)
/* 00C7F4 7000BBF4 10B9003D */  beq   $a1, $t9, .L7000BCEC
/* 00C7F8 7000BBF8 24AA0001 */   addiu $t2, $a1, 1
/* 00C7FC 7000BBFC 0149001A */  div   $zero, $t2, $t1
/* 00C800 7000BC00 00023880 */  sll   $a3, $v0, 2
/* 00C804 7000BC04 00003010 */  mfhi  $a2
/* 00C808 7000BC08 00E23823 */  subu  $a3, $a3, $v0
/* 00C80C 7000BC0C 00073840 */  sll   $a3, $a3, 1
/* 00C810 7000BC10 15200002 */  bnez  $t1, .L7000BC1C
/* 00C814 7000BC14 00000000 */   nop   
/* 00C818 7000BC18 0007000D */  break 7
.L7000BC1C:
/* 00C81C 7000BC1C 2401FFFF */  li    $at, -1
/* 00C820 7000BC20 15210004 */  bne   $t1, $at, .L7000BC34
/* 00C824 7000BC24 3C018000 */   lui   $at, 0x8000
/* 00C828 7000BC28 15410002 */  bne   $t2, $at, .L7000BC34
/* 00C82C 7000BC2C 00000000 */   nop   
/* 00C830 7000BC30 0006000D */  break 6
.L7000BC34:
/* 00C834 7000BC34 24CE0013 */  addiu $t6, $a2, 0x13
.L7000BC38:
/* 00C838 7000BC38 01C9001A */  div   $zero, $t6, $t1
/* 00C83C 7000BC3C 00007810 */  mfhi  $t7
/* 00C840 7000BC40 000FC080 */  sll   $t8, $t7, 2
/* 00C844 7000BC44 00065880 */  sll   $t3, $a2, 2
/* 00C848 7000BC48 030FC023 */  subu  $t8, $t8, $t7
/* 00C84C 7000BC4C 01665823 */  subu  $t3, $t3, $a2
/* 00C850 7000BC50 0018C0C0 */  sll   $t8, $t8, 3
/* 00C854 7000BC54 000B58C0 */  sll   $t3, $t3, 3
/* 00C858 7000BC58 0098C821 */  addu  $t9, $a0, $t8
/* 00C85C 7000BC5C 008B6021 */  addu  $t4, $a0, $t3
/* 00C860 7000BC60 03275021 */  addu  $t2, $t9, $a3
/* 00C864 7000BC64 95480000 */  lhu   $t0, ($t2)
/* 00C868 7000BC68 01876821 */  addu  $t5, $t4, $a3
/* 00C86C 7000BC6C 95A50000 */  lhu   $a1, ($t5)
/* 00C870 7000BC70 946B01F0 */  lhu   $t3, 0x1f0($v1)
/* 00C874 7000BC74 01006027 */  not   $t4, $t0
/* 00C878 7000BC78 15200002 */  bnez  $t1, .L7000BC84
/* 00C87C 7000BC7C 00000000 */   nop   
/* 00C880 7000BC80 0007000D */  break 7
.L7000BC84:
/* 00C884 7000BC84 2401FFFF */  li    $at, -1
/* 00C888 7000BC88 15210004 */  bne   $t1, $at, .L7000BC9C
/* 00C88C 7000BC8C 3C018000 */   lui   $at, 0x8000
/* 00C890 7000BC90 15C10002 */  bne   $t6, $at, .L7000BC9C
/* 00C894 7000BC94 00000000 */   nop   
/* 00C898 7000BC98 0006000D */  break 6
.L7000BC9C:
/* 00C89C 7000BC9C 00AC6824 */  and   $t5, $a1, $t4
/* 00C8A0 7000BCA0 016D7025 */  or    $t6, $t3, $t5
/* 00C8A4 7000BCA4 A46E01F0 */  sh    $t6, 0x1f0($v1)
/* 00C8A8 7000BCA8 8C8F01E0 */  lw    $t7, 0x1e0($a0)
/* 00C8AC 7000BCAC 24D80001 */  addiu $t8, $a2, 1
/* 00C8B0 7000BCB0 50CF000F */  beql  $a2, $t7, .L7000BCF0
/* 00C8B4 7000BCB4 24420001 */   addiu $v0, $v0, 1
/* 00C8B8 7000BCB8 0309001A */  div   $zero, $t8, $t1
/* 00C8BC 7000BCBC 00003010 */  mfhi  $a2
/* 00C8C0 7000BCC0 15200002 */  bnez  $t1, .L7000BCCC
/* 00C8C4 7000BCC4 00000000 */   nop   
/* 00C8C8 7000BCC8 0007000D */  break 7
.L7000BCCC:
/* 00C8CC 7000BCCC 2401FFFF */  li    $at, -1
/* 00C8D0 7000BCD0 15210004 */  bne   $t1, $at, .L7000BCE4
/* 00C8D4 7000BCD4 3C018000 */   lui   $at, 0x8000
/* 00C8D8 7000BCD8 17010002 */  bne   $t8, $at, .L7000BCE4
/* 00C8DC 7000BCDC 00000000 */   nop   
/* 00C8E0 7000BCE0 0006000D */  break 6
.L7000BCE4:
/* 00C8E4 7000BCE4 1000FFD4 */  b     .L7000BC38
/* 00C8E8 7000BCE8 24CE0013 */   addiu $t6, $a2, 0x13
.L7000BCEC:
/* 00C8EC 7000BCEC 24420001 */  addiu $v0, $v0, 1
.L7000BCF0:
/* 00C8F0 7000BCF0 0002CE00 */  sll   $t9, $v0, 0x18
/* 00C8F4 7000BCF4 00191603 */  sra   $v0, $t9, 0x18
/* 00C8F8 7000BCF8 28410004 */  slti  $at, $v0, 4
/* 00C8FC 7000BCFC 5420FFB9 */  bnezl $at, .L7000BBE4
/* 00C900 7000BD00 0002C040 */   sll   $t8, $v0, 1
/* 00C904 7000BD04 03E00008 */  jr    $ra
/* 00C908 7000BD08 00000000 */   nop   
)
#endif



#ifdef NONMATCHING
s32 redirect_to_ramrom_replay_and_record_handlers_if_set(void) {
    // Node 0
    if (disable_all_rumble != 0)
    {
        // Node 1
        // Error: I don't know how to handle jalr!
    }
    // Node 2
    probably_ramrom_related(&controller_input_index);
    if (ptr_to_tlb_ramrom_record != 0)
    {
        // Node 3
        // Error: I don't know how to handle jalr!
        return;
        // (function likely void)
    }
    // (possible return value: ptr_to_tlb_ramrom_record)
}
#else
GLOBAL_ASM(
.text
glabel redirect_to_ramrom_replay_and_record_handlers_if_set
/* 00C90C 7000BD0C 3C028002 */  lui   $v0, %hi(disable_all_rumble)
/* 00C910 7000BD10 8C426924 */  lw    $v0, %lo(disable_all_rumble)($v0)
/* 00C914 7000BD14 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 00C918 7000BD18 AFBF0014 */  sw    $ra, 0x14($sp)
/* 00C91C 7000BD1C 1040000A */  beqz  $v0, .L7000BD48
/* 00C920 7000BD20 3C048006 */   lui   $a0, %hi(dword_CODE_bss_8006512C)
/* 00C924 7000BD24 3C058006 */  lui   $a1, %hi(dword_CODE_bss_8006530C)
/* 00C928 7000BD28 8CA5530C */  lw    $a1, %lo(dword_CODE_bss_8006530C)($a1)
/* 00C92C 7000BD2C 0040F809 */  jalr  $v0
/* 00C930 7000BD30 2484512C */  addiu $a0, %lo(dword_CODE_bss_8006512C) # addiu $a0, $a0, 0x512c
/* 00C934 7000BD34 3C018006 */  lui   $at, %hi(dword_CODE_bss_80065314)
/* 00C938 7000BD38 3C048006 */  lui   $a0, %hi(dword_CODE_bss_8006512C)
/* 00C93C 7000BD3C AC225314 */  sw    $v0, %lo(dword_CODE_bss_80065314)($at)
/* 00C940 7000BD40 0C002EF2 */  jal   probably_ramrom_related
/* 00C944 7000BD44 2484512C */   addiu $a0, %lo(dword_CODE_bss_8006512C) # addiu $a0, $a0, 0x512c
.L7000BD48:
/* 00C948 7000BD48 3C048006 */  lui   $a0, %hi(controller_input_index)
/* 00C94C 7000BD4C 0C002EF2 */  jal   probably_ramrom_related
/* 00C950 7000BD50 24844F30 */   addiu $a0, %lo(controller_input_index) # addiu $a0, $a0, 0x4f30
/* 00C954 7000BD54 3C028002 */  lui   $v0, %hi(ptr_to_tlb_ramrom_record)
/* 00C958 7000BD58 8C426928 */  lw    $v0, %lo(ptr_to_tlb_ramrom_record)($v0)
/* 00C95C 7000BD5C 3C048006 */  lui   $a0, %hi(controller_input_index)
/* 00C960 7000BD60 24844F30 */  addiu $a0, %lo(controller_input_index) # addiu $a0, $a0, 0x4f30
/* 00C964 7000BD64 50400005 */  beql  $v0, $zero, .L7000BD7C
/* 00C968 7000BD68 8FBF0014 */   lw    $ra, 0x14($sp)
/* 00C96C 7000BD6C 8C8501E4 */  lw    $a1, 0x1e4($a0)
/* 00C970 7000BD70 0040F809 */  jalr  $v0
/* 00C974 7000BD74 8C8601E0 */  lw    $a2, 0x1e0($a0)
/* 00C978 7000BD78 8FBF0014 */  lw    $ra, 0x14($sp)
.L7000BD7C:
/* 00C97C 7000BD7C 27BD0018 */  addiu $sp, $sp, 0x18
/* 00C980 7000BD80 03E00008 */  jr    $ra
/* 00C984 7000BD84 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void controllerSchedulerRelated(void)
{
    ? sp4C;
    s32 sp40;
    s32 temp_a0;
    s32 temp_a0_2;
    s32 temp_a2;
    s32 temp_hi;
    s32 temp_lo;
    s32 temp_t6;
    s32 temp_t8;
    s32 temp_v1;
    void *temp_t3;
    void *temp_v1_2;
    s32 phi_v1;
    s32 phi_v0;
    s32 phi_a0;
    s32 phi_a0_2;
    void *phi_t1;
    void *phi_a0_3;
    void *phi_a1;
    void *phi_v1_2;

    if (osRecvMesg(&cont1MesgMQ, &sp4C, 0) == 0)
    {
        if (D_800268C8 != 0)
        {
            osRecvMesg(&contdemoMesgMQ, &sp4C, 1);
            D_800268C8 = 0;
        }
        osSendMesg(&cont2MesgMQ, &sp4C, 0);
        D_800268CC = (s32) (D_800268CC + 1);
        return;
    }
    if (osRecvMesg(&cont3MesgMQ, &sp4C, 0) == 0)
    {
        osContStartReadData(&contdemoMesgMQ);
        D_800268C8 = 1;
        osSendMesg(&cont4MesgMQ, &sp4C, 0);
        D_800268CC = (s32) (D_800268CC + -1);
        return;
    }
    if (D_800268CC == 0)
    {
        if (D_8002691C != 0)
        {
            if (osRecvMesg(&contdemoMesgMQ, &sp4C, 0) == 0)
            {
                D_800268C8 = 0;
                temp_hi = (s32) (controller_input_index.unk1E8 + 1) % 0x14;
                phi_v1 = temp_hi;
                if (temp_hi == controller_input_index.unk1E4)
                {
                    phi_v1 = controller_input_index.unk1E8;
                }
                sp40 = (s32) phi_v1;
                osContGetReadData(&controller_input_index + (((phi_v1 * 4) - phi_v1) * 8), &controller_input_index);
                temp_t6 = D_80026920 + 1;
                temp_t8 = temp_t6 % 0x78;
                controller_input_index.unk1EC = (s32) ((s32) (sp40 + 0x13) % 0x14);
                D_80026920 = temp_t6;
                controller_input_index.unk1E8 = sp40;
                phi_v0 = sp40;
                if (temp_t8 == 0)
                {
                    controller_check_for_rumble_maybe(&D_80026920, &controller_input_index);
                    phi_v0 = controller_input_index.unk1E8;
                }
                temp_a2 = &controller_input_index + (((phi_v0 * 4) - phi_v0) * 8);
                phi_a0 = 0;
loop_14:
                temp_lo = phi_a0 * 6;
                temp_t3 = temp_a2 + temp_lo;
                if ((temp_t3->unk4 != 0) || (((&controller_input_index + (&controller_input_index->unk1EC * 0x18)) + temp_lo)->unk4 == 0))
                {
                    temp_a0 = phi_a0 + 1;
                    if ((temp_t3->unk4 != 0) && (((&controller_input_index + (&controller_input_index->unk1EC * 0x18)) + temp_lo)->unk4 == 0))
                    {
block_18:
                        controller_check_for_rumble_maybe(phi_a0_2, &controller_input_index, temp_a2, 6);
                    }
                    else
                    {
                        temp_a0_2 = (s32) (temp_a0 << 0x18) >> 0x18;
                        phi_a0 = temp_a0_2;
                        if (temp_a0_2 < 4)
                        {
                            goto loop_14;
                        }
                    }
                }
                else
                {
                    goto block_18;
                }
                controller_rumble_related();
                osContStartReadData(&contdemoMesgMQ);
                D_800268C8 = 1;
                temp_v1 = D_80026970 + 1;
                D_80026970 = temp_v1;
                if (temp_v1 >= 0x3c)
                {
                    phi_t1 = &pl1_controller_failure_lr;
                    phi_a0_3 = &pl1_controller_failure_ud;
                    phi_a1 = &pl1_controller_failure_held;
                    phi_v1_2 = &pl1_controller_failure_pressed;
loop_22:
                    if ((((phi_t1->unk0 != 0) || (phi_a0_3->unk0 != 0)) || (phi_a1->unk0 != 0)) || (phi_v1_2->unk0 != 0))
                    {
                        phi_t1->unk0 = 0;
                        phi_a0_3->unk0 = 0;
                        phi_a1->unk0 = 0;
                        phi_v1_2->unk0 = 0;
                    }
                    else
                    {

                    }
                    if ((((phi_t1->unk4 != 0) || (phi_a0_3->unk4 != 0)) || (phi_a1->unk4 != 0)) || (phi_v1_2->unk4 != 0))
                    {
                        phi_t1->unk4 = 0;
                        phi_a0_3->unk4 = 0;
                        phi_a1->unk4 = 0;
                        phi_v1_2->unk4 = 0;
                    }
                    else
                    {

                    }
                    temp_v1_2 = phi_v1_2 + 8;
                    phi_t1 = phi_t1 + 8;
                    phi_a0_3 = phi_a0_3 + 8;
                    phi_a1 = phi_a1 + 8;
                    phi_v1_2 = temp_v1_2;
                    if (temp_v1_2 != &D_80026970)
                    {
                        goto loop_22;
                    }
                    D_80026970 = 0;
                }
            }
        }
    }
}
#else
GLOBAL_ASM(
.text
glabel controllerSchedulerRelated
/* 00C988 7000BD88 27BDFFB0 */  addiu $sp, $sp, -0x50
/* 00C98C 7000BD8C AFBF0014 */  sw    $ra, 0x14($sp)
/* 00C990 7000BD90 3C048006 */  lui   $a0, %hi(cont1MesgMQ)
/* 00C994 7000BD94 24845370 */  addiu $a0, %lo(cont1MesgMQ) # addiu $a0, $a0, 0x5370
/* 00C998 7000BD98 27A5004C */  addiu $a1, $sp, 0x4c
/* 00C99C 7000BD9C 0C003774 */  jal   osRecvMesg
/* 00C9A0 7000BDA0 00003025 */   move  $a2, $zero
/* 00C9A4 7000BDA4 14400015 */  bnez  $v0, .L7000BDFC
/* 00C9A8 7000BDA8 3C0E8002 */   lui   $t6, %hi(D_800268C8) 
/* 00C9AC 7000BDAC 8DCE68C8 */  lw    $t6, %lo(D_800268C8)($t6)
/* 00C9B0 7000BDB0 3C048006 */  lui   $a0, %hi(contdemoMesgMQ)
/* 00C9B4 7000BDB4 24845350 */  addiu $a0, %lo(contdemoMesgMQ) # addiu $a0, $a0, 0x5350
/* 00C9B8 7000BDB8 11C00005 */  beqz  $t6, .L7000BDD0
/* 00C9BC 7000BDBC 27A5004C */   addiu $a1, $sp, 0x4c
/* 00C9C0 7000BDC0 0C003774 */  jal   osRecvMesg
/* 00C9C4 7000BDC4 24060001 */   li    $a2, 1
/* 00C9C8 7000BDC8 3C018002 */  lui   $at, %hi(D_800268C8)
/* 00C9CC 7000BDCC AC2068C8 */  sw    $zero, %lo(D_800268C8)($at)
.L7000BDD0:
/* 00C9D0 7000BDD0 3C048006 */  lui   $a0, %hi(cont2MesgMQ)
/* 00C9D4 7000BDD4 24845390 */  addiu $a0, %lo(cont2MesgMQ) # addiu $a0, $a0, 0x5390
/* 00C9D8 7000BDD8 27A5004C */  addiu $a1, $sp, 0x4c
/* 00C9DC 7000BDDC 0C0037C4 */  jal   osSendMesg
/* 00C9E0 7000BDE0 00003025 */   move  $a2, $zero
/* 00C9E4 7000BDE4 3C038002 */  lui   $v1, %hi(D_800268CC)
/* 00C9E8 7000BDE8 246368CC */  addiu $v1, %lo(D_800268CC) # addiu $v1, $v1, 0x68cc
/* 00C9EC 7000BDEC 8C6F0000 */  lw    $t7, ($v1)
/* 00C9F0 7000BDF0 25F80001 */  addiu $t8, $t7, 1
/* 00C9F4 7000BDF4 100000B9 */  b     .L7000C0DC
/* 00C9F8 7000BDF8 AC780000 */   sw    $t8, ($v1)
.L7000BDFC:
/* 00C9FC 7000BDFC 3C048006 */  lui   $a0, %hi(cont3MesgMQ)
/* 00CA00 7000BE00 248453B0 */  addiu $a0, %lo(cont3MesgMQ) # addiu $a0, $a0, 0x53b0
/* 00CA04 7000BE04 27A5004C */  addiu $a1, $sp, 0x4c
/* 00CA08 7000BE08 0C003774 */  jal   osRecvMesg
/* 00CA0C 7000BE0C 00003025 */   move  $a2, $zero
/* 00CA10 7000BE10 14400011 */  bnez  $v0, .L7000BE58
/* 00CA14 7000BE14 3C048006 */   lui   $a0, %hi(contdemoMesgMQ)
/* 00CA18 7000BE18 0C00535C */  jal   osContStartReadData
/* 00CA1C 7000BE1C 24845350 */   addiu $a0, %lo(contdemoMesgMQ) # addiu $a0, $a0, 0x5350
/* 00CA20 7000BE20 24190001 */  li    $t9, 1
/* 00CA24 7000BE24 3C018002 */  lui   $at, %hi(D_800268C8)
/* 00CA28 7000BE28 3C048006 */  lui   $a0, %hi(cont4MesgMQ)
/* 00CA2C 7000BE2C AC3968C8 */  sw    $t9, %lo(D_800268C8)($at)
/* 00CA30 7000BE30 248453D0 */  addiu $a0, %lo(cont4MesgMQ) # addiu $a0, $a0, 0x53d0
/* 00CA34 7000BE34 27A5004C */  addiu $a1, $sp, 0x4c
/* 00CA38 7000BE38 0C0037C4 */  jal   osSendMesg
/* 00CA3C 7000BE3C 00003025 */   move  $a2, $zero
/* 00CA40 7000BE40 3C038002 */  lui   $v1, %hi(D_800268CC)
/* 00CA44 7000BE44 246368CC */  addiu $v1, %lo(D_800268CC) # addiu $v1, $v1, 0x68cc
/* 00CA48 7000BE48 8C6B0000 */  lw    $t3, ($v1)
/* 00CA4C 7000BE4C 256CFFFF */  addiu $t4, $t3, -1
/* 00CA50 7000BE50 100000A2 */  b     .L7000C0DC
/* 00CA54 7000BE54 AC6C0000 */   sw    $t4, ($v1)
.L7000BE58:
/* 00CA58 7000BE58 3C038002 */  lui   $v1, %hi(D_800268CC)
/* 00CA5C 7000BE5C 246368CC */  addiu $v1, %lo(D_800268CC) # addiu $v1, $v1, 0x68cc
/* 00CA60 7000BE60 8C6D0000 */  lw    $t5, ($v1)
/* 00CA64 7000BE64 3C0E8002 */  lui   $t6, %hi(D_8002691C) 
/* 00CA68 7000BE68 55A0009D */  bnezl $t5, .L7000C0E0
/* 00CA6C 7000BE6C 8FBF0014 */   lw    $ra, 0x14($sp)
/* 00CA70 7000BE70 8DCE691C */  lw    $t6, %lo(D_8002691C)($t6)
/* 00CA74 7000BE74 3C048006 */  lui   $a0, %hi(contdemoMesgMQ)
/* 00CA78 7000BE78 24845350 */  addiu $a0, %lo(contdemoMesgMQ) # addiu $a0, $a0, 0x5350
/* 00CA7C 7000BE7C 11C00097 */  beqz  $t6, .L7000C0DC
/* 00CA80 7000BE80 27A5004C */   addiu $a1, $sp, 0x4c
/* 00CA84 7000BE84 0C003774 */  jal   osRecvMesg
/* 00CA88 7000BE88 00003025 */   move  $a2, $zero
/* 00CA8C 7000BE8C 14400093 */  bnez  $v0, .L7000C0DC
/* 00CA90 7000BE90 3C058006 */   lui   $a1, %hi(controller_input_index)
/* 00CA94 7000BE94 3C018002 */  lui   $at, %hi(D_800268C8)
/* 00CA98 7000BE98 24A54F30 */  addiu $a1, %lo(controller_input_index) # addiu $a1, $a1, 0x4f30
/* 00CA9C 7000BE9C AC2068C8 */  sw    $zero, %lo(D_800268C8)($at)
/* 00CAA0 7000BEA0 8CA201E8 */  lw    $v0, 0x1e8($a1)
/* 00CAA4 7000BEA4 24010014 */  li    $at, 20
/* 00CAA8 7000BEA8 8CB801E4 */  lw    $t8, 0x1e4($a1)
/* 00CAAC 7000BEAC 24430001 */  addiu $v1, $v0, 1
/* 00CAB0 7000BEB0 0061001A */  div   $zero, $v1, $at
/* 00CAB4 7000BEB4 00001810 */  mfhi  $v1
/* 00CAB8 7000BEB8 54780003 */  bnel  $v1, $t8, .L7000BEC8
/* 00CABC 7000BEBC 0003C880 */   sll   $t9, $v1, 2
/* 00CAC0 7000BEC0 00401825 */  move  $v1, $v0
/* 00CAC4 7000BEC4 0003C880 */  sll   $t9, $v1, 2
.L7000BEC8:
/* 00CAC8 7000BEC8 0323C823 */  subu  $t9, $t9, $v1
/* 00CACC 7000BECC 0019C8C0 */  sll   $t9, $t9, 3
/* 00CAD0 7000BED0 00B92021 */  addu  $a0, $a1, $t9
/* 00CAD4 7000BED4 0C00538D */  jal   osContGetReadData
/* 00CAD8 7000BED8 AFA30040 */   sw    $v1, 0x40($sp)
/* 00CADC 7000BEDC 8FA20040 */  lw    $v0, 0x40($sp)
/* 00CAE0 7000BEE0 24010014 */  li    $at, 20
/* 00CAE4 7000BEE4 3C048002 */  lui   $a0, %hi(D_80026920)
/* 00CAE8 7000BEE8 244B0013 */  addiu $t3, $v0, 0x13
/* 00CAEC 7000BEEC 0161001A */  div   $zero, $t3, $at
/* 00CAF0 7000BEF0 24846920 */  addiu $a0, %lo(D_80026920) # addiu $a0, $a0, 0x6920
/* 00CAF4 7000BEF4 8C8D0000 */  lw    $t5, ($a0)
/* 00CAF8 7000BEF8 00006010 */  mfhi  $t4
/* 00CAFC 7000BEFC 24010078 */  li    $at, 120
/* 00CB00 7000BF00 25AE0001 */  addiu $t6, $t5, 1
/* 00CB04 7000BF04 01C1001A */  div   $zero, $t6, $at
/* 00CB08 7000BF08 3C058006 */  lui   $a1, %hi(controller_input_index)
/* 00CB0C 7000BF0C 24A54F30 */  addiu $a1, %lo(controller_input_index) # addiu $a1, $a1, 0x4f30
/* 00CB10 7000BF10 0000C010 */  mfhi  $t8
/* 00CB14 7000BF14 ACAC01EC */  sw    $t4, 0x1ec($a1)
/* 00CB18 7000BF18 AC8E0000 */  sw    $t6, ($a0)
/* 00CB1C 7000BF1C 17000006 */  bnez  $t8, .L7000BF38
/* 00CB20 7000BF20 ACA201E8 */   sw    $v0, 0x1e8($a1)
/* 00CB24 7000BF24 0C002E04 */  jal   controller_check_for_rumble_maybe
/* 00CB28 7000BF28 00000000 */   nop   
/* 00CB2C 7000BF2C 3C058006 */  lui   $a1, %hi(controller_input_index)
/* 00CB30 7000BF30 24A54F30 */  addiu $a1, %lo(controller_input_index) # addiu $a1, $a1, 0x4f30
/* 00CB34 7000BF34 8CA201E8 */  lw    $v0, 0x1e8($a1)
.L7000BF38:
/* 00CB38 7000BF38 0002C880 */  sll   $t9, $v0, 2
/* 00CB3C 7000BF3C 0322C823 */  subu  $t9, $t9, $v0
/* 00CB40 7000BF40 0019C8C0 */  sll   $t9, $t9, 3
/* 00CB44 7000BF44 00B93021 */  addu  $a2, $a1, $t9
/* 00CB48 7000BF48 00002025 */  move  $a0, $zero
/* 00CB4C 7000BF4C 24070006 */  li    $a3, 6
.L7000BF50:
/* 00CB50 7000BF50 00870019 */  multu $a0, $a3
/* 00CB54 7000BF54 00001012 */  mflo  $v0
/* 00CB58 7000BF58 00C25821 */  addu  $t3, $a2, $v0
/* 00CB5C 7000BF5C 91630004 */  lbu   $v1, 4($t3)
/* 00CB60 7000BF60 1460000A */  bnez  $v1, .L7000BF8C
/* 00CB64 7000BF64 00000000 */   nop   
/* 00CB68 7000BF68 8CAC01EC */  lw    $t4, 0x1ec($a1)
/* 00CB6C 7000BF6C 000C6880 */  sll   $t5, $t4, 2
/* 00CB70 7000BF70 01AC6823 */  subu  $t5, $t5, $t4
/* 00CB74 7000BF74 000D68C0 */  sll   $t5, $t5, 3
/* 00CB78 7000BF78 00AD7021 */  addu  $t6, $a1, $t5
/* 00CB7C 7000BF7C 01C27821 */  addu  $t7, $t6, $v0
/* 00CB80 7000BF80 91F80004 */  lbu   $t8, 4($t7)
/* 00CB84 7000BF84 1700000C */  bnez  $t8, .L7000BFB8
/* 00CB88 7000BF88 00000000 */   nop   
.L7000BF8C:
/* 00CB8C 7000BF8C 1060000E */  beqz  $v1, .L7000BFC8
/* 00CB90 7000BF90 24840001 */   addiu $a0, $a0, 1
/* 00CB94 7000BF94 8CB901EC */  lw    $t9, 0x1ec($a1)
/* 00CB98 7000BF98 00195880 */  sll   $t3, $t9, 2
/* 00CB9C 7000BF9C 01795823 */  subu  $t3, $t3, $t9
/* 00CBA0 7000BFA0 000B58C0 */  sll   $t3, $t3, 3
/* 00CBA4 7000BFA4 00AB6021 */  addu  $t4, $a1, $t3
/* 00CBA8 7000BFA8 01826821 */  addu  $t5, $t4, $v0
/* 00CBAC 7000BFAC 91AE0004 */  lbu   $t6, 4($t5)
/* 00CBB0 7000BFB0 55C00006 */  bnezl $t6, .L7000BFCC
/* 00CBB4 7000BFB4 00047E00 */   sll   $t7, $a0, 0x18
.L7000BFB8:
/* 00CBB8 7000BFB8 0C002E04 */  jal   controller_check_for_rumble_maybe
/* 00CBBC 7000BFBC 00000000 */   nop   
/* 00CBC0 7000BFC0 10000006 */  b     .L7000BFDC
/* 00CBC4 7000BFC4 00000000 */   nop   
.L7000BFC8:
/* 00CBC8 7000BFC8 00047E00 */  sll   $t7, $a0, 0x18
.L7000BFCC:
/* 00CBCC 7000BFCC 000F2603 */  sra   $a0, $t7, 0x18
/* 00CBD0 7000BFD0 28810004 */  slti  $at, $a0, 4
/* 00CBD4 7000BFD4 1420FFDE */  bnez  $at, .L7000BF50
/* 00CBD8 7000BFD8 00000000 */   nop   
.L7000BFDC:
/* 00CBDC 7000BFDC 0C002E9F */  jal   controller_rumble_related
/* 00CBE0 7000BFE0 00000000 */   nop   
/* 00CBE4 7000BFE4 3C048006 */  lui   $a0, %hi(contdemoMesgMQ)
/* 00CBE8 7000BFE8 0C00535C */  jal   osContStartReadData
/* 00CBEC 7000BFEC 24845350 */   addiu $a0, %lo(contdemoMesgMQ) # addiu $a0, $a0, 0x5350
/* 00CBF0 7000BFF0 3C038002 */  lui   $v1, %hi(D_80026970)
/* 00CBF4 7000BFF4 8C636970 */  lw    $v1, %lo(D_80026970)($v1)
/* 00CBF8 7000BFF8 24190001 */  li    $t9, 1
/* 00CBFC 7000BFFC 3C018002 */  lui   $at, %hi(D_800268C8)
/* 00CC00 7000C000 AC3968C8 */  sw    $t9, %lo(D_800268C8)($at)
/* 00CC04 7000C004 3C018002 */  lui   $at, %hi(D_80026970)
/* 00CC08 7000C008 24630001 */  addiu $v1, $v1, 1
/* 00CC0C 7000C00C AC236970 */  sw    $v1, %lo(D_80026970)($at)
/* 00CC10 7000C010 2861003C */  slti  $at, $v1, 0x3c
/* 00CC14 7000C014 14200031 */  bnez  $at, .L7000C0DC
/* 00CC18 7000C018 3C098002 */   lui   $t1, %hi(pl1_controller_failure_lr) 
/* 00CC1C 7000C01C 3C048002 */  lui   $a0, %hi(pl1_controller_failure_ud)
/* 00CC20 7000C020 3C058002 */  lui   $a1, %hi(pl1_controller_failure_held)
/* 00CC24 7000C024 3C038002 */  lui   $v1, %hi(pl1_controller_failure_pressed)
/* 00CC28 7000C028 3C0A8002 */  lui   $t2, %hi(D_80026970) 
/* 00CC2C 7000C02C 254A6970 */  addiu $t2, %lo(D_80026970) # addiu $t2, $t2, 0x6970
/* 00CC30 7000C030 24636960 */  addiu $v1, %lo(pl1_controller_failure_pressed) # addiu $v1, $v1, 0x6960
/* 00CC34 7000C034 24A56950 */  addiu $a1, %lo(pl1_controller_failure_held) # addiu $a1, $a1, 0x6950
/* 00CC38 7000C038 24846940 */  addiu $a0, %lo(pl1_controller_failure_ud) # addiu $a0, $a0, 0x6940
/* 00CC3C 7000C03C 25296930 */  addiu $t1, %lo(pl1_controller_failure_lr) # addiu $t1, $t1, 0x6930
.L7000C040:
/* 00CC40 7000C040 8D220000 */  lw    $v0, ($t1)
/* 00CC44 7000C044 5440000B */  bnezl $v0, .L7000C074
/* 00CC48 7000C048 AD200000 */   sw    $zero, ($t1)
/* 00CC4C 7000C04C 8C8B0000 */  lw    $t3, ($a0)
/* 00CC50 7000C050 55600008 */  bnezl $t3, .L7000C074
/* 00CC54 7000C054 AD200000 */   sw    $zero, ($t1)
/* 00CC58 7000C058 8CAC0000 */  lw    $t4, ($a1)
/* 00CC5C 7000C05C 55800005 */  bnezl $t4, .L7000C074
/* 00CC60 7000C060 AD200000 */   sw    $zero, ($t1)
/* 00CC64 7000C064 8C6D0000 */  lw    $t5, ($v1)
/* 00CC68 7000C068 51A00006 */  beql  $t5, $zero, .L7000C084
/* 00CC6C 7000C06C 8D220004 */   lw    $v0, 4($t1)
/* 00CC70 7000C070 AD200000 */  sw    $zero, ($t1)
.L7000C074:
/* 00CC74 7000C074 AC800000 */  sw    $zero, ($a0)
/* 00CC78 7000C078 ACA00000 */  sw    $zero, ($a1)
/* 00CC7C 7000C07C AC600000 */  sw    $zero, ($v1)
/* 00CC80 7000C080 8D220004 */  lw    $v0, 4($t1)
.L7000C084:
/* 00CC84 7000C084 5440000B */  bnezl $v0, .L7000C0B4
/* 00CC88 7000C088 AD200004 */   sw    $zero, 4($t1)
/* 00CC8C 7000C08C 8C8E0004 */  lw    $t6, 4($a0)
/* 00CC90 7000C090 55C00008 */  bnezl $t6, .L7000C0B4
/* 00CC94 7000C094 AD200004 */   sw    $zero, 4($t1)
/* 00CC98 7000C098 8CAF0004 */  lw    $t7, 4($a1)
/* 00CC9C 7000C09C 55E00005 */  bnezl $t7, .L7000C0B4
/* 00CCA0 7000C0A0 AD200004 */   sw    $zero, 4($t1)
/* 00CCA4 7000C0A4 8C780004 */  lw    $t8, 4($v1)
/* 00CCA8 7000C0A8 53000006 */  beql  $t8, $zero, .L7000C0C4
/* 00CCAC 7000C0AC 24630008 */   addiu $v1, $v1, 8
/* 00CCB0 7000C0B0 AD200004 */  sw    $zero, 4($t1)
.L7000C0B4:
/* 00CCB4 7000C0B4 AC800004 */  sw    $zero, 4($a0)
/* 00CCB8 7000C0B8 ACA00004 */  sw    $zero, 4($a1)
/* 00CCBC 7000C0BC AC600004 */  sw    $zero, 4($v1)
/* 00CCC0 7000C0C0 24630008 */  addiu $v1, $v1, 8
.L7000C0C4:
/* 00CCC4 7000C0C4 25290008 */  addiu $t1, $t1, 8
/* 00CCC8 7000C0C8 24840008 */  addiu $a0, $a0, 8
/* 00CCCC 7000C0CC 146AFFDC */  bne   $v1, $t2, .L7000C040
/* 00CCD0 7000C0D0 24A50008 */   addiu $a1, $a1, 8
/* 00CCD4 7000C0D4 3C018002 */  lui   $at, %hi(D_80026970)
/* 00CCD8 7000C0D8 AC206970 */  sw    $zero, %lo(D_80026970)($at)
.L7000C0DC:
/* 00CCDC 7000C0DC 8FBF0014 */  lw    $ra, 0x14($sp)
.L7000C0E0:
/* 00CCE0 7000C0E0 27BD0050 */  addiu $sp, $sp, 0x50
/* 00CCE4 7000C0E4 03E00008 */  jr    $ra
/* 00CCE8 7000C0E8 00000000 */   nop   
)
#endif



#ifdef NONMATCHING
? get_cur_controller_horz_stick_pos(s32 arg0)
{
    s32 temp_t7;
    void *temp_v1;

    temp_t7 = (s32) (arg0 << 0x18) >> 0x18;
    if (ptr_current_point_in_controller_input_index->unk1F8 < 0)
    {
        if ((((s32) num_controller_plugged_in_flags >> temp_t7) & 1) == 0)
        {
            temp_v1 = (temp_t7 * 4) + &pl1_controller_failure_lr;
            *temp_v1 = (s32) (*temp_v1 + 1);
            return 0;
        }
    }
    return ((ptr_current_point_in_controller_input_index + (ptr_current_point_in_controller_input_index->unk1E0 * 0x18)) + (temp_t7 * 6))->unk2;
}
#else
GLOBAL_ASM(
.text
glabel get_cur_controller_horz_stick_pos
/* 00CCEC 7000C0EC 3C038002 */  lui   $v1, %hi(ptr_current_point_in_controller_input_index)
/* 00CCF0 7000C0F0 8C6368C4 */  lw    $v1, %lo(ptr_current_point_in_controller_input_index)($v1)
/* 00CCF4 7000C0F4 AFA40000 */  sw    $a0, ($sp)
/* 00CCF8 7000C0F8 00047600 */  sll   $t6, $a0, 0x18
/* 00CCFC 7000C0FC 8C7801F8 */  lw    $t8, 0x1f8($v1)
/* 00CD00 7000C100 000E7E03 */  sra   $t7, $t6, 0x18
/* 00CD04 7000C104 01E02025 */  move  $a0, $t7
/* 00CD08 7000C108 0701000E */  bgez  $t8, .L7000C144
/* 00CD0C 7000C10C 3C198002 */   lui   $t9, %hi(num_controller_plugged_in_flags) 
/* 00CD10 7000C110 933968D0 */  lbu   $t9, %lo(num_controller_plugged_in_flags)($t9)
/* 00CD14 7000C114 3C0B8002 */  lui   $t3, %hi(pl1_controller_failure_lr) 
/* 00CD18 7000C118 256B6930 */  addiu $t3, %lo(pl1_controller_failure_lr) # addiu $t3, $t3, 0x6930
/* 00CD1C 7000C11C 01F94007 */  srav  $t0, $t9, $t7
/* 00CD20 7000C120 31090001 */  andi  $t1, $t0, 1
/* 00CD24 7000C124 15200007 */  bnez  $t1, .L7000C144
/* 00CD28 7000C128 000F5080 */   sll   $t2, $t7, 2
/* 00CD2C 7000C12C 014B1821 */  addu  $v1, $t2, $t3
/* 00CD30 7000C130 8C6C0000 */  lw    $t4, ($v1)
/* 00CD34 7000C134 00001025 */  move  $v0, $zero
/* 00CD38 7000C138 258D0001 */  addiu $t5, $t4, 1
/* 00CD3C 7000C13C 03E00008 */  jr    $ra
/* 00CD40 7000C140 AC6D0000 */   sw    $t5, ($v1)

.L7000C144:
/* 00CD44 7000C144 8C6E01E0 */  lw    $t6, 0x1e0($v1)
/* 00CD48 7000C148 0004C880 */  sll   $t9, $a0, 2
/* 00CD4C 7000C14C 0324C823 */  subu  $t9, $t9, $a0
/* 00CD50 7000C150 000E7880 */  sll   $t7, $t6, 2
/* 00CD54 7000C154 01EE7823 */  subu  $t7, $t7, $t6
/* 00CD58 7000C158 000F78C0 */  sll   $t7, $t7, 3
/* 00CD5C 7000C15C 006FC021 */  addu  $t8, $v1, $t7
/* 00CD60 7000C160 0019C840 */  sll   $t9, $t9, 1
/* 00CD64 7000C164 03194021 */  addu  $t0, $t8, $t9
/* 00CD68 7000C168 81020002 */  lb    $v0, 2($t0)
/* 00CD6C 7000C16C 03E00008 */  jr    $ra
/* 00CD70 7000C170 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void controller_7000C174(s32 arg0) {
    s32 temp_t7;
    void *temp_v1;

    // Node 0
    temp_t7 = ((s32) (arg0 << 0x18) >> 0x18);
    if (ptr_current_point_in_controller_input_index->unk1F8 < 0)
    {
        // Node 1
        if ((((s32) num_controller_plugged_in_flags >> temp_t7) & 1) == 0)
        {
            // Node 2
            temp_v1 = ((temp_t7 * 4) + &pl1_controller_failure_lr);
            *temp_v1 = (s32) (*temp_v1 + 1);
            return;
            // (possible return value: ((ptr_current_point_in_controller_input_index + (ptr_current_point_in_controller_input_index->unk1E4 * 0x18)) + (temp_t7 * 6))->unk2)
        }
    }
    // (possible return value: ((ptr_current_point_in_controller_input_index + (ptr_current_point_in_controller_input_index->unk1E4 * 0x18)) + (temp_t7 * 6))->unk2)
}
#else
GLOBAL_ASM(
.text
glabel controller_7000C174
/* 00CD74 7000C174 3C038002 */  lui   $v1, %hi(ptr_current_point_in_controller_input_index)
/* 00CD78 7000C178 8C6368C4 */  lw    $v1, %lo(ptr_current_point_in_controller_input_index)($v1)
/* 00CD7C 7000C17C AFA40000 */  sw    $a0, ($sp)
/* 00CD80 7000C180 00047600 */  sll   $t6, $a0, 0x18
/* 00CD84 7000C184 8C7801F8 */  lw    $t8, 0x1f8($v1)
/* 00CD88 7000C188 000E7E03 */  sra   $t7, $t6, 0x18
/* 00CD8C 7000C18C 01E02025 */  move  $a0, $t7
/* 00CD90 7000C190 0701000E */  bgez  $t8, .L7000C1CC
/* 00CD94 7000C194 3C198002 */   lui   $t9, %hi(num_controller_plugged_in_flags) 
/* 00CD98 7000C198 933968D0 */  lbu   $t9, %lo(num_controller_plugged_in_flags)($t9)
/* 00CD9C 7000C19C 3C0B8002 */  lui   $t3, %hi(pl1_controller_failure_lr) 
/* 00CDA0 7000C1A0 256B6930 */  addiu $t3, %lo(pl1_controller_failure_lr) # addiu $t3, $t3, 0x6930
/* 00CDA4 7000C1A4 01F94007 */  srav  $t0, $t9, $t7
/* 00CDA8 7000C1A8 31090001 */  andi  $t1, $t0, 1
/* 00CDAC 7000C1AC 15200007 */  bnez  $t1, .L7000C1CC
/* 00CDB0 7000C1B0 000F5080 */   sll   $t2, $t7, 2
/* 00CDB4 7000C1B4 014B1821 */  addu  $v1, $t2, $t3
/* 00CDB8 7000C1B8 8C6C0000 */  lw    $t4, ($v1)
/* 00CDBC 7000C1BC 00001025 */  move  $v0, $zero
/* 00CDC0 7000C1C0 258D0001 */  addiu $t5, $t4, 1
/* 00CDC4 7000C1C4 03E00008 */  jr    $ra
/* 00CDC8 7000C1C8 AC6D0000 */   sw    $t5, ($v1)

.L7000C1CC:
/* 00CDCC 7000C1CC 8C6E01E4 */  lw    $t6, 0x1e4($v1)
/* 00CDD0 7000C1D0 0004C880 */  sll   $t9, $a0, 2
/* 00CDD4 7000C1D4 0324C823 */  subu  $t9, $t9, $a0
/* 00CDD8 7000C1D8 000E7880 */  sll   $t7, $t6, 2
/* 00CDDC 7000C1DC 01EE7823 */  subu  $t7, $t7, $t6
/* 00CDE0 7000C1E0 000F78C0 */  sll   $t7, $t7, 3
/* 00CDE4 7000C1E4 006FC021 */  addu  $t8, $v1, $t7
/* 00CDE8 7000C1E8 0019C840 */  sll   $t9, $t9, 1
/* 00CDEC 7000C1EC 03194021 */  addu  $t0, $t8, $t9
/* 00CDF0 7000C1F0 81020002 */  lb    $v0, 2($t0)
/* 00CDF4 7000C1F4 03E00008 */  jr    $ra
/* 00CDF8 7000C1F8 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void get_cur_controller_vert_stick_pos(s32 arg0) {
    s32 temp_t7;
    void *temp_v1;

    // Node 0
    temp_t7 = ((s32) (arg0 << 0x18) >> 0x18);
    if (ptr_current_point_in_controller_input_index->unk1F8 < 0)
    {
        // Node 1
        if ((((s32) num_controller_plugged_in_flags >> temp_t7) & 1) == 0)
        {
            // Node 2
            temp_v1 = ((temp_t7 * 4) + &pl1_controller_failure_ud);
            *temp_v1 = (s32) (*temp_v1 + 1);
            return;
            // (possible return value: ((ptr_current_point_in_controller_input_index + (ptr_current_point_in_controller_input_index->unk1E0 * 0x18)) + (temp_t7 * 6))->unk3)
        }
    }
    // (possible return value: ((ptr_current_point_in_controller_input_index + (ptr_current_point_in_controller_input_index->unk1E0 * 0x18)) + (temp_t7 * 6))->unk3)
}
#else
GLOBAL_ASM(
.text
glabel get_cur_controller_vert_stick_pos
/* 00CDFC 7000C1FC 3C038002 */  lui   $v1, %hi(ptr_current_point_in_controller_input_index)
/* 00CE00 7000C200 8C6368C4 */  lw    $v1, %lo(ptr_current_point_in_controller_input_index)($v1)
/* 00CE04 7000C204 AFA40000 */  sw    $a0, ($sp)
/* 00CE08 7000C208 00047600 */  sll   $t6, $a0, 0x18
/* 00CE0C 7000C20C 8C7801F8 */  lw    $t8, 0x1f8($v1)
/* 00CE10 7000C210 000E7E03 */  sra   $t7, $t6, 0x18
/* 00CE14 7000C214 01E02025 */  move  $a0, $t7
/* 00CE18 7000C218 0701000E */  bgez  $t8, .L7000C254
/* 00CE1C 7000C21C 3C198002 */   lui   $t9, %hi(num_controller_plugged_in_flags) 
/* 00CE20 7000C220 933968D0 */  lbu   $t9, %lo(num_controller_plugged_in_flags)($t9)
/* 00CE24 7000C224 3C0B8002 */  lui   $t3, %hi(pl1_controller_failure_ud) 
/* 00CE28 7000C228 256B6940 */  addiu $t3, %lo(pl1_controller_failure_ud) # addiu $t3, $t3, 0x6940
/* 00CE2C 7000C22C 01F94007 */  srav  $t0, $t9, $t7
/* 00CE30 7000C230 31090001 */  andi  $t1, $t0, 1
/* 00CE34 7000C234 15200007 */  bnez  $t1, .L7000C254
/* 00CE38 7000C238 000F5080 */   sll   $t2, $t7, 2
/* 00CE3C 7000C23C 014B1821 */  addu  $v1, $t2, $t3
/* 00CE40 7000C240 8C6C0000 */  lw    $t4, ($v1)
/* 00CE44 7000C244 00001025 */  move  $v0, $zero
/* 00CE48 7000C248 258D0001 */  addiu $t5, $t4, 1
/* 00CE4C 7000C24C 03E00008 */  jr    $ra
/* 00CE50 7000C250 AC6D0000 */   sw    $t5, ($v1)

.L7000C254:
/* 00CE54 7000C254 8C6E01E0 */  lw    $t6, 0x1e0($v1)
/* 00CE58 7000C258 0004C880 */  sll   $t9, $a0, 2
/* 00CE5C 7000C25C 0324C823 */  subu  $t9, $t9, $a0
/* 00CE60 7000C260 000E7880 */  sll   $t7, $t6, 2
/* 00CE64 7000C264 01EE7823 */  subu  $t7, $t7, $t6
/* 00CE68 7000C268 000F78C0 */  sll   $t7, $t7, 3
/* 00CE6C 7000C26C 006FC021 */  addu  $t8, $v1, $t7
/* 00CE70 7000C270 0019C840 */  sll   $t9, $t9, 1
/* 00CE74 7000C274 03194021 */  addu  $t0, $t8, $t9
/* 00CE78 7000C278 81020003 */  lb    $v0, 3($t0)
/* 00CE7C 7000C27C 03E00008 */  jr    $ra
/* 00CE80 7000C280 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void controller_7000C284(s32 arg0) {
    s32 temp_t7;
    void *temp_v1;

    // Node 0
    temp_t7 = ((s32) (arg0 << 0x18) >> 0x18);
    if (ptr_current_point_in_controller_input_index->unk1F8 < 0)
    {
        // Node 1
        if ((((s32) num_controller_plugged_in_flags >> temp_t7) & 1) == 0)
        {
            // Node 2
            temp_v1 = ((temp_t7 * 4) + &pl1_controller_failure_ud);
            *temp_v1 = (s32) (*temp_v1 + 1);
            return;
            // (possible return value: ((ptr_current_point_in_controller_input_index + (ptr_current_point_in_controller_input_index->unk1E4 * 0x18)) + (temp_t7 * 6))->unk3)
        }
    }
    // (possible return value: ((ptr_current_point_in_controller_input_index + (ptr_current_point_in_controller_input_index->unk1E4 * 0x18)) + (temp_t7 * 6))->unk3)
}
#else
GLOBAL_ASM(
.text
glabel controller_7000C284
/* 00CE84 7000C284 3C038002 */  lui   $v1, %hi(ptr_current_point_in_controller_input_index)
/* 00CE88 7000C288 8C6368C4 */  lw    $v1, %lo(ptr_current_point_in_controller_input_index)($v1)
/* 00CE8C 7000C28C AFA40000 */  sw    $a0, ($sp)
/* 00CE90 7000C290 00047600 */  sll   $t6, $a0, 0x18
/* 00CE94 7000C294 8C7801F8 */  lw    $t8, 0x1f8($v1)
/* 00CE98 7000C298 000E7E03 */  sra   $t7, $t6, 0x18
/* 00CE9C 7000C29C 01E02025 */  move  $a0, $t7
/* 00CEA0 7000C2A0 0701000E */  bgez  $t8, .L7000C2DC
/* 00CEA4 7000C2A4 3C198002 */   lui   $t9, %hi(num_controller_plugged_in_flags) 
/* 00CEA8 7000C2A8 933968D0 */  lbu   $t9, %lo(num_controller_plugged_in_flags)($t9)
/* 00CEAC 7000C2AC 3C0B8002 */  lui   $t3, %hi(pl1_controller_failure_ud) 
/* 00CEB0 7000C2B0 256B6940 */  addiu $t3, %lo(pl1_controller_failure_ud) # addiu $t3, $t3, 0x6940
/* 00CEB4 7000C2B4 01F94007 */  srav  $t0, $t9, $t7
/* 00CEB8 7000C2B8 31090001 */  andi  $t1, $t0, 1
/* 00CEBC 7000C2BC 15200007 */  bnez  $t1, .L7000C2DC
/* 00CEC0 7000C2C0 000F5080 */   sll   $t2, $t7, 2
/* 00CEC4 7000C2C4 014B1821 */  addu  $v1, $t2, $t3
/* 00CEC8 7000C2C8 8C6C0000 */  lw    $t4, ($v1)
/* 00CECC 7000C2CC 00001025 */  move  $v0, $zero
/* 00CED0 7000C2D0 258D0001 */  addiu $t5, $t4, 1
/* 00CED4 7000C2D4 03E00008 */  jr    $ra
/* 00CED8 7000C2D8 AC6D0000 */   sw    $t5, ($v1)

.L7000C2DC:
/* 00CEDC 7000C2DC 8C6E01E4 */  lw    $t6, 0x1e4($v1)
/* 00CEE0 7000C2E0 0004C880 */  sll   $t9, $a0, 2
/* 00CEE4 7000C2E4 0324C823 */  subu  $t9, $t9, $a0
/* 00CEE8 7000C2E8 000E7880 */  sll   $t7, $t6, 2
/* 00CEEC 7000C2EC 01EE7823 */  subu  $t7, $t7, $t6
/* 00CEF0 7000C2F0 000F78C0 */  sll   $t7, $t7, 3
/* 00CEF4 7000C2F4 006FC021 */  addu  $t8, $v1, $t7
/* 00CEF8 7000C2F8 0019C840 */  sll   $t9, $t9, 1
/* 00CEFC 7000C2FC 03194021 */  addu  $t0, $t8, $t9
/* 00CF00 7000C300 81020003 */  lb    $v0, 3($t0)
/* 00CF04 7000C304 03E00008 */  jr    $ra
/* 00CF08 7000C308 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
s32 get_controller_buttons_held(s32 arg0, s32 arg1) {
    s32 temp_t7;
    void *temp_v1;

    // Node 0
    temp_t7 = ((s32) (arg0 << 0x18) >> 0x18);
    if (ptr_current_point_in_controller_input_index->unk1F8 < 0)
    {
        // Node 1
        if ((((s32) num_controller_plugged_in_flags >> temp_t7) & 1) == 0)
        {
            // Node 2
            temp_v1 = ((temp_t7 * 4) + &pl1_controller_failure_held);
            *temp_v1 = (s32) (*temp_v1 + 1);
            return;
            // (possible return value: ((*((ptr_current_point_in_controller_input_index + (ptr_current_point_in_controller_input_index->unk1E0 * 0x18)) + (temp_t7 * 6)) & (arg1 & 0xffff)) & 0xffff))
        }
    }
    // (possible return value: ((*((ptr_current_point_in_controller_input_index + (ptr_current_point_in_controller_input_index->unk1E0 * 0x18)) + (temp_t7 * 6)) & (arg1 & 0xffff)) & 0xffff))
}
#else
GLOBAL_ASM(
.text
glabel get_controller_buttons_held
/* 00CF0C 7000C30C 3C038002 */  lui   $v1, %hi(ptr_current_point_in_controller_input_index)
/* 00CF10 7000C310 8C6368C4 */  lw    $v1, %lo(ptr_current_point_in_controller_input_index)($v1)
/* 00CF14 7000C314 AFA40000 */  sw    $a0, ($sp)
/* 00CF18 7000C318 AFA50004 */  sw    $a1, 4($sp)
/* 00CF1C 7000C31C 8C7901F8 */  lw    $t9, 0x1f8($v1)
/* 00CF20 7000C320 00047600 */  sll   $t6, $a0, 0x18
/* 00CF24 7000C324 000E7E03 */  sra   $t7, $t6, 0x18
/* 00CF28 7000C328 30B8FFFF */  andi  $t8, $a1, 0xffff
/* 00CF2C 7000C32C 03002825 */  move  $a1, $t8
/* 00CF30 7000C330 0721000F */  bgez  $t9, .L7000C370
/* 00CF34 7000C334 01E02025 */   move  $a0, $t7
/* 00CF38 7000C338 3C088002 */  lui   $t0, %hi(num_controller_plugged_in_flags) 
/* 00CF3C 7000C33C 910868D0 */  lbu   $t0, %lo(num_controller_plugged_in_flags)($t0)
/* 00CF40 7000C340 3C0C8002 */  lui   $t4, %hi(pl1_controller_failure_held) 
/* 00CF44 7000C344 258C6950 */  addiu $t4, %lo(pl1_controller_failure_held) # addiu $t4, $t4, 0x6950
/* 00CF48 7000C348 01E84807 */  srav  $t1, $t0, $t7
/* 00CF4C 7000C34C 312A0001 */  andi  $t2, $t1, 1
/* 00CF50 7000C350 15400007 */  bnez  $t2, .L7000C370
/* 00CF54 7000C354 000F5880 */   sll   $t3, $t7, 2
/* 00CF58 7000C358 016C1821 */  addu  $v1, $t3, $t4
/* 00CF5C 7000C35C 8C6D0000 */  lw    $t5, ($v1)
/* 00CF60 7000C360 00001025 */  move  $v0, $zero
/* 00CF64 7000C364 25AE0001 */  addiu $t6, $t5, 1
/* 00CF68 7000C368 03E00008 */  jr    $ra
/* 00CF6C 7000C36C AC6E0000 */   sw    $t6, ($v1)

.L7000C370:
/* 00CF70 7000C370 8C6F01E0 */  lw    $t7, 0x1e0($v1)
/* 00CF74 7000C374 00044080 */  sll   $t0, $a0, 2
/* 00CF78 7000C378 01044023 */  subu  $t0, $t0, $a0
/* 00CF7C 7000C37C 000FC080 */  sll   $t8, $t7, 2
/* 00CF80 7000C380 030FC023 */  subu  $t8, $t8, $t7
/* 00CF84 7000C384 0018C0C0 */  sll   $t8, $t8, 3
/* 00CF88 7000C388 0078C821 */  addu  $t9, $v1, $t8
/* 00CF8C 7000C38C 00084040 */  sll   $t0, $t0, 1
/* 00CF90 7000C390 03284821 */  addu  $t1, $t9, $t0
/* 00CF94 7000C394 952A0000 */  lhu   $t2, ($t1)
/* 00CF98 7000C398 01451024 */  and   $v0, $t2, $a1
/* 00CF9C 7000C39C 304BFFFF */  andi  $t3, $v0, 0xffff
/* 00CFA0 7000C3A0 01601025 */  move  $v0, $t3
/* 00CFA4 7000C3A4 03E00008 */  jr    $ra
/* 00CFA8 7000C3A8 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
s32 get_controller_buttons_pressed(s32 arg0, s32 arg1) {
    s32 temp_t7;
    void *temp_v1;

    // Node 0
    temp_t7 = ((s32) (arg0 << 0x18) >> 0x18);
    if (ptr_current_point_in_controller_input_index->unk1F8 < 0)
    {
        // Node 1
        if ((((s32) num_controller_plugged_in_flags >> temp_t7) & 1) == 0)
        {
            // Node 2
            temp_v1 = ((temp_t7 * 4) + &pl1_controller_failure_pressed);
            *temp_v1 = (s32) (*temp_v1 + 1);
            return;
            // (possible return value: (((ptr_current_point_in_controller_input_index + (temp_t7 * 2))->unk1F0 & (arg1 & 0xffff)) & 0xffff))
        }
    }
    // (possible return value: (((ptr_current_point_in_controller_input_index + (temp_t7 * 2))->unk1F0 & (arg1 & 0xffff)) & 0xffff))
}
#else
GLOBAL_ASM(
.text
glabel get_controller_buttons_pressed
/* 00CFAC 7000C3AC 3C038002 */  lui   $v1, %hi(ptr_current_point_in_controller_input_index)
/* 00CFB0 7000C3B0 8C6368C4 */  lw    $v1, %lo(ptr_current_point_in_controller_input_index)($v1)
/* 00CFB4 7000C3B4 AFA40000 */  sw    $a0, ($sp)
/* 00CFB8 7000C3B8 AFA50004 */  sw    $a1, 4($sp)
/* 00CFBC 7000C3BC 8C7901F8 */  lw    $t9, 0x1f8($v1)
/* 00CFC0 7000C3C0 00047600 */  sll   $t6, $a0, 0x18
/* 00CFC4 7000C3C4 000E7E03 */  sra   $t7, $t6, 0x18
/* 00CFC8 7000C3C8 30B8FFFF */  andi  $t8, $a1, 0xffff
/* 00CFCC 7000C3CC 03002825 */  move  $a1, $t8
/* 00CFD0 7000C3D0 0721000F */  bgez  $t9, .L7000C410
/* 00CFD4 7000C3D4 01E02025 */   move  $a0, $t7
/* 00CFD8 7000C3D8 3C088002 */  lui   $t0, %hi(num_controller_plugged_in_flags) 
/* 00CFDC 7000C3DC 910868D0 */  lbu   $t0, %lo(num_controller_plugged_in_flags)($t0)
/* 00CFE0 7000C3E0 3C0C8002 */  lui   $t4, %hi(pl1_controller_failure_pressed) 
/* 00CFE4 7000C3E4 258C6960 */  addiu $t4, %lo(pl1_controller_failure_pressed) # addiu $t4, $t4, 0x6960
/* 00CFE8 7000C3E8 01E84807 */  srav  $t1, $t0, $t7
/* 00CFEC 7000C3EC 312A0001 */  andi  $t2, $t1, 1
/* 00CFF0 7000C3F0 15400007 */  bnez  $t2, .L7000C410
/* 00CFF4 7000C3F4 000F5880 */   sll   $t3, $t7, 2
/* 00CFF8 7000C3F8 016C1821 */  addu  $v1, $t3, $t4
/* 00CFFC 7000C3FC 8C6D0000 */  lw    $t5, ($v1)
/* 00D000 7000C400 00001025 */  move  $v0, $zero
/* 00D004 7000C404 25AE0001 */  addiu $t6, $t5, 1
/* 00D008 7000C408 03E00008 */  jr    $ra
/* 00D00C 7000C40C AC6E0000 */   sw    $t6, ($v1)

.L7000C410:
/* 00D010 7000C410 00047840 */  sll   $t7, $a0, 1
/* 00D014 7000C414 006FC021 */  addu  $t8, $v1, $t7
/* 00D018 7000C418 971901F0 */  lhu   $t9, 0x1f0($t8)
/* 00D01C 7000C41C 03251024 */  and   $v0, $t9, $a1
/* 00D020 7000C420 3048FFFF */  andi  $t0, $v0, 0xffff
/* 00D024 7000C424 01001025 */  move  $v0, $t0
/* 00D028 7000C428 03E00008 */  jr    $ra
/* 00D02C 7000C42C 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
s32 controller_7000C430(s32 arg0, s32 arg1) {
    // Node 0
    // Node 1
    (arg0 + 1)->unk-1 = (s8) (((0 < (((s32) (arg1 & 0xffff) >> 0xf) & 1)) * 0x11) + 0x20);
    if ((0xf + -1) >= 0)
    {
        goto loop_1;
    }
    // (possible return value: (0xf + -1))
}

#else
GLOBAL_ASM(
.text
glabel controller_7000C430
/* 00D030 7000C430 AFA50004 */  sw    $a1, 4($sp)
/* 00D034 7000C434 30A3FFFF */  andi  $v1, $a1, 0xffff
/* 00D038 7000C438 24050011 */  li    $a1, 17
/* 00D03C 7000C43C 2402000F */  li    $v0, 15
.L7000C440:
/* 00D040 7000C440 00437807 */  srav  $t7, $v1, $v0
/* 00D044 7000C444 31F80001 */  andi  $t8, $t7, 1
/* 00D048 7000C448 0018C82A */  slt   $t9, $zero, $t8
/* 00D04C 7000C44C 03250019 */  multu $t9, $a1
/* 00D050 7000C450 2442FFFF */  addiu $v0, $v0, -1
/* 00D054 7000C454 24840001 */  addiu $a0, $a0, 1
/* 00D058 7000C458 00004012 */  mflo  $t0
/* 00D05C 7000C45C 25090020 */  addiu $t1, $t0, 0x20
/* 00D060 7000C460 0441FFF7 */  bgez  $v0, .L7000C440
/* 00D064 7000C464 A089FFFF */   sb    $t1, -1($a0)
/* 00D068 7000C468 03E00008 */  jr    $ra
/* 00D06C 7000C46C 00000000 */   nop   
)
#endif



#ifdef NONMATCHING
void controller_7000C470(void) {
    // Node 0
    if (get_attached_controller_count() > 0)
    {
        loop_1:
        // Node 1
        if ((0 + 1) < get_attached_controller_count())
        {
            goto loop_1;
        }
    }
    // (possible return value: get_attached_controller_count())
}

#else
GLOBAL_ASM(
.text
glabel controller_7000C470
/* 00D070 7000C470 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 00D074 7000C474 AFBF001C */  sw    $ra, 0x1c($sp)
/* 00D078 7000C478 AFB00018 */  sw    $s0, 0x18($sp)
/* 00D07C 7000C47C 0C002E7E */  jal   get_attached_controller_count
/* 00D080 7000C480 00008025 */   move  $s0, $zero
/* 00D084 7000C484 58400007 */  blezl $v0, .L7000C4A4
/* 00D088 7000C488 8FBF001C */   lw    $ra, 0x1c($sp)
.L7000C48C:
/* 00D08C 7000C48C 0C002E7E */  jal   get_attached_controller_count
/* 00D090 7000C490 26100001 */   addiu $s0, $s0, 1
/* 00D094 7000C494 0202082A */  slt   $at, $s0, $v0
/* 00D098 7000C498 1420FFFC */  bnez  $at, .L7000C48C
/* 00D09C 7000C49C 00000000 */   nop   
/* 00D0A0 7000C4A0 8FBF001C */  lw    $ra, 0x1c($sp)
.L7000C4A4:
/* 00D0A4 7000C4A4 8FB00018 */  lw    $s0, 0x18($sp)
/* 00D0A8 7000C4A8 27BD0020 */  addiu $sp, $sp, 0x20
/* 00D0AC 7000C4AC 03E00008 */  jr    $ra
/* 00D0B0 7000C4B0 00000000 */   nop   
)
#endif



#ifdef NONMATCHING
s32 get_controller_3dstick_L_R(s32 arg0, s32 arg1, ? arg2, s32 arg7, s32 arg8) {
    s32 temp_a0;

    // Node 0
    temp_a0 = (get_cur_controller_horz_stick_pos(((s32) (arg0 << 0x18) >> 0x18)) + 0x3c);
    if (temp_a0 >= 0x79)
    {
        // Node 1
    }
    // Node 2
    if (temp_a0 < 0)
    {
        // Node 3
        return;
        // (possible return value: (((s32) (temp_a0 * (arg8 - arg7)) / 0x78) + arg7))
    }
    // (possible return value: (((s32) (temp_a0 * (arg8 - arg7)) / 0x78) + arg7))
}
#else
GLOBAL_ASM(
.text
glabel get_controller_3dstick_L_R
/* 00D0B4 7000C4B4 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 00D0B8 7000C4B8 AFBF0014 */  sw    $ra, 0x14($sp)
/* 00D0BC 7000C4BC AFA40018 */  sw    $a0, 0x18($sp)
/* 00D0C0 7000C4C0 00047600 */  sll   $t6, $a0, 0x18
/* 00D0C4 7000C4C4 000E2603 */  sra   $a0, $t6, 0x18
/* 00D0C8 7000C4C8 AFA5001C */  sw    $a1, 0x1c($sp)
/* 00D0CC 7000C4CC 0C00303B */  jal   get_cur_controller_horz_stick_pos
/* 00D0D0 7000C4D0 AFA60020 */   sw    $a2, 0x20($sp)
/* 00D0D4 7000C4D4 2444003C */  addiu $a0, $v0, 0x3c
/* 00D0D8 7000C4D8 28810079 */  slti  $at, $a0, 0x79
/* 00D0DC 7000C4DC 14200002 */  bnez  $at, .L7000C4E8
/* 00D0E0 7000C4E0 8FA5001C */   lw    $a1, 0x1c($sp)
/* 00D0E4 7000C4E4 24040078 */  li    $a0, 120
.L7000C4E8:
/* 00D0E8 7000C4E8 04810002 */  bgez  $a0, .L7000C4F4
/* 00D0EC 7000C4EC 8FB80020 */   lw    $t8, 0x20($sp)
/* 00D0F0 7000C4F0 00002025 */  move  $a0, $zero
.L7000C4F4:
/* 00D0F4 7000C4F4 0305C823 */  subu  $t9, $t8, $a1
/* 00D0F8 7000C4F8 00990019 */  multu $a0, $t9
/* 00D0FC 7000C4FC 24010078 */  li    $at, 120
/* 00D100 7000C500 8FBF0014 */  lw    $ra, 0x14($sp)
/* 00D104 7000C504 27BD0018 */  addiu $sp, $sp, 0x18
/* 00D108 7000C508 00004012 */  mflo  $t0
/* 00D10C 7000C50C 00000000 */  nop   
/* 00D110 7000C510 00000000 */  nop   
/* 00D114 7000C514 0101001A */  div   $zero, $t0, $at
/* 00D118 7000C518 00004812 */  mflo  $t1
/* 00D11C 7000C51C 01251021 */  addu  $v0, $t1, $a1
/* 00D120 7000C520 03E00008 */  jr    $ra
/* 00D124 7000C524 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
s32 get_controller_3dstick_U_D(s32 arg0, s32 arg1, ? arg2, s32 arg7, s32 arg8) {
    s32 temp_a0;

    // Node 0
    temp_a0 = (get_cur_controller_vert_stick_pos(((s32) (arg0 << 0x18) >> 0x18)) + 0x3c);
    if (temp_a0 >= 0x79)
    {
        // Node 1
    }
    // Node 2
    if (temp_a0 < 0)
    {
        // Node 3
        return;
        // (possible return value: (((s32) (temp_a0 * (arg8 - arg7)) / 0x78) + arg7))
    }
    // (possible return value: (((s32) (temp_a0 * (arg8 - arg7)) / 0x78) + arg7))
}
#else
GLOBAL_ASM(
.text
glabel get_controller_3dstick_U_D
/* 00D128 7000C528 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 00D12C 7000C52C AFBF0014 */  sw    $ra, 0x14($sp)
/* 00D130 7000C530 AFA40018 */  sw    $a0, 0x18($sp)
/* 00D134 7000C534 00047600 */  sll   $t6, $a0, 0x18
/* 00D138 7000C538 000E2603 */  sra   $a0, $t6, 0x18
/* 00D13C 7000C53C AFA5001C */  sw    $a1, 0x1c($sp)
/* 00D140 7000C540 0C00307F */  jal   get_cur_controller_vert_stick_pos
/* 00D144 7000C544 AFA60020 */   sw    $a2, 0x20($sp)
/* 00D148 7000C548 2444003C */  addiu $a0, $v0, 0x3c
/* 00D14C 7000C54C 28810079 */  slti  $at, $a0, 0x79
/* 00D150 7000C550 14200002 */  bnez  $at, .L7000C55C
/* 00D154 7000C554 8FA5001C */   lw    $a1, 0x1c($sp)
/* 00D158 7000C558 24040078 */  li    $a0, 120
.L7000C55C:
/* 00D15C 7000C55C 04810002 */  bgez  $a0, .L7000C568
/* 00D160 7000C560 8FB80020 */   lw    $t8, 0x20($sp)
/* 00D164 7000C564 00002025 */  move  $a0, $zero
.L7000C568:
/* 00D168 7000C568 0305C823 */  subu  $t9, $t8, $a1
/* 00D16C 7000C56C 00990019 */  multu $a0, $t9
/* 00D170 7000C570 24010078 */  li    $at, 120
/* 00D174 7000C574 8FBF0014 */  lw    $ra, 0x14($sp)
/* 00D178 7000C578 27BD0018 */  addiu $sp, $sp, 0x18
/* 00D17C 7000C57C 00004012 */  mflo  $t0
/* 00D180 7000C580 00000000 */  nop   
/* 00D184 7000C584 00000000 */  nop   
/* 00D188 7000C588 0101001A */  div   $zero, $t0, $at
/* 00D18C 7000C58C 00004812 */  mflo  $t1
/* 00D190 7000C590 01251021 */  addu  $v0, $t1, $a1
/* 00D194 7000C594 03E00008 */  jr    $ra
/* 00D198 7000C598 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
f32 controller_7000C59C(s32 arg0, s32 arg1, ? arg2, f32 arg7, f32 arg8) {
    s32 temp_a0;

    // Node 0
    temp_a0 = (get_cur_controller_horz_stick_pos(((s32) (arg0 << 0x18) >> 0x18)) + 0x3c);
    if (temp_a0 >= 0x79)
    {
        // Node 1
    }
    // Node 2
    if (temp_a0 < 0)
    {
        // Node 3
        return;
        // (possible return value: ((((f32) temp_a0 / 120.0f) * (arg8 - arg7)) + arg7))
    }
    // (possible return value: ((((f32) temp_a0 / 120.0f) * (arg8 - arg7)) + arg7))
}
#else
GLOBAL_ASM(
.text
glabel controller_7000C59C
/* 00D19C 7000C59C 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 00D1A0 7000C5A0 AFBF0014 */  sw    $ra, 0x14($sp)
/* 00D1A4 7000C5A4 AFA40018 */  sw    $a0, 0x18($sp)
/* 00D1A8 7000C5A8 00047600 */  sll   $t6, $a0, 0x18
/* 00D1AC 7000C5AC 000E2603 */  sra   $a0, $t6, 0x18
/* 00D1B0 7000C5B0 AFA5001C */  sw    $a1, 0x1c($sp)
/* 00D1B4 7000C5B4 0C00303B */  jal   get_cur_controller_horz_stick_pos
/* 00D1B8 7000C5B8 AFA60020 */   sw    $a2, 0x20($sp)
/* 00D1BC 7000C5BC 2444003C */  addiu $a0, $v0, 0x3c
/* 00D1C0 7000C5C0 28810079 */  slti  $at, $a0, 0x79
/* 00D1C4 7000C5C4 14200002 */  bnez  $at, .L7000C5D0
/* 00D1C8 7000C5C8 C7A2001C */   lwc1  $f2, 0x1c($sp)
/* 00D1CC 7000C5CC 24040078 */  li    $a0, 120
.L7000C5D0:
/* 00D1D0 7000C5D0 04830003 */  bgezl $a0, .L7000C5E0
/* 00D1D4 7000C5D4 44842000 */   mtc1  $a0, $f4
/* 00D1D8 7000C5D8 00002025 */  move  $a0, $zero
/* 00D1DC 7000C5DC 44842000 */  mtc1  $a0, $f4
.L7000C5E0:
/* 00D1E0 7000C5E0 3C0142F0 */  li    $at, 0x42F00000 # 120.000000
/* 00D1E4 7000C5E4 44814000 */  mtc1  $at, $f8
/* 00D1E8 7000C5E8 468021A0 */  cvt.s.w $f6, $f4
/* 00D1EC 7000C5EC C7B00020 */  lwc1  $f16, 0x20($sp)
/* 00D1F0 7000C5F0 8FBF0014 */  lw    $ra, 0x14($sp)
/* 00D1F4 7000C5F4 27BD0018 */  addiu $sp, $sp, 0x18
/* 00D1F8 7000C5F8 46028481 */  sub.s $f18, $f16, $f2
/* 00D1FC 7000C5FC 46083283 */  div.s $f10, $f6, $f8
/* 00D200 7000C600 46125102 */  mul.s $f4, $f10, $f18
/* 00D204 7000C604 03E00008 */  jr    $ra
/* 00D208 7000C608 46022000 */   add.s $f0, $f4, $f2
)
#endif





#ifdef NONMATCHING
f32 controller_7000C60C(s32 arg0, s32 arg1, ? arg2, f32 arg7, f32 arg8) {
    s32 temp_a0;

    // Node 0
    temp_a0 = (get_cur_controller_vert_stick_pos(((s32) (arg0 << 0x18) >> 0x18)) + 0x3c);
    if (temp_a0 >= 0x79)
    {
        // Node 1
    }
    // Node 2
    if (temp_a0 < 0)
    {
        // Node 3
        return;
        // (possible return value: ((((f32) temp_a0 / 120.0f) * (arg8 - arg7)) + arg7))
    }
    // (possible return value: ((((f32) temp_a0 / 120.0f) * (arg8 - arg7)) + arg7))
}
#else
GLOBAL_ASM(
.text
glabel controller_7000C60C
/* 00D20C 7000C60C 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 00D210 7000C610 AFBF0014 */  sw    $ra, 0x14($sp)
/* 00D214 7000C614 AFA40018 */  sw    $a0, 0x18($sp)
/* 00D218 7000C618 00047600 */  sll   $t6, $a0, 0x18
/* 00D21C 7000C61C 000E2603 */  sra   $a0, $t6, 0x18
/* 00D220 7000C620 AFA5001C */  sw    $a1, 0x1c($sp)
/* 00D224 7000C624 0C00307F */  jal   get_cur_controller_vert_stick_pos
/* 00D228 7000C628 AFA60020 */   sw    $a2, 0x20($sp)
/* 00D22C 7000C62C 2444003C */  addiu $a0, $v0, 0x3c
/* 00D230 7000C630 28810079 */  slti  $at, $a0, 0x79
/* 00D234 7000C634 14200002 */  bnez  $at, .L7000C640
/* 00D238 7000C638 C7A2001C */   lwc1  $f2, 0x1c($sp)
/* 00D23C 7000C63C 24040078 */  li    $a0, 120
.L7000C640:
/* 00D240 7000C640 04830003 */  bgezl $a0, .L7000C650
/* 00D244 7000C644 44842000 */   mtc1  $a0, $f4
/* 00D248 7000C648 00002025 */  move  $a0, $zero
/* 00D24C 7000C64C 44842000 */  mtc1  $a0, $f4
.L7000C650:
/* 00D250 7000C650 3C0142F0 */  li    $at, 0x42F00000 # 120.000000
/* 00D254 7000C654 44814000 */  mtc1  $at, $f8
/* 00D258 7000C658 468021A0 */  cvt.s.w $f6, $f4
/* 00D25C 7000C65C C7B00020 */  lwc1  $f16, 0x20($sp)
/* 00D260 7000C660 8FBF0014 */  lw    $ra, 0x14($sp)
/* 00D264 7000C664 27BD0018 */  addiu $sp, $sp, 0x18
/* 00D268 7000C668 46028481 */  sub.s $f18, $f16, $f2
/* 00D26C 7000C66C 46083283 */  div.s $f10, $f6, $f8
/* 00D270 7000C670 46125102 */  mul.s $f4, $f10, $f18
/* 00D274 7000C674 03E00008 */  jr    $ra
/* 00D278 7000C678 46022000 */   add.s $f0, $f4, $f2
)
#endif





#ifdef NONMATCHING
void controller_7000C67C(void) {
    ? sp1C;

    // Node 0
    osSendMesg(&cont1MesgMQ, &sp1C, 0);
    osRecvMesg(&cont2MesgMQ, &sp1C, 1);
    return;
    // (possible return value: osRecvMesg(&cont2MesgMQ, &sp1C, 1))
}
#else
GLOBAL_ASM(
.text
glabel controller_7000C67C
/* 00D27C 7000C67C 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 00D280 7000C680 AFBF0014 */  sw    $ra, 0x14($sp)
/* 00D284 7000C684 3C048006 */  lui   $a0, %hi(cont1MesgMQ)
/* 00D288 7000C688 24845370 */  addiu $a0, %lo(cont1MesgMQ) # addiu $a0, $a0, 0x5370
/* 00D28C 7000C68C 27A5001C */  addiu $a1, $sp, 0x1c
/* 00D290 7000C690 0C0037C4 */  jal   osSendMesg
/* 00D294 7000C694 00003025 */   move  $a2, $zero
/* 00D298 7000C698 3C048006 */  lui   $a0, %hi(cont2MesgMQ)
/* 00D29C 7000C69C 24845390 */  addiu $a0, %lo(cont2MesgMQ) # addiu $a0, $a0, 0x5390
/* 00D2A0 7000C6A0 27A5001C */  addiu $a1, $sp, 0x1c
/* 00D2A4 7000C6A4 0C003774 */  jal   osRecvMesg
/* 00D2A8 7000C6A8 24060001 */   li    $a2, 1
/* 00D2AC 7000C6AC 8FBF0014 */  lw    $ra, 0x14($sp)
/* 00D2B0 7000C6B0 27BD0020 */  addiu $sp, $sp, 0x20
/* 00D2B4 7000C6B4 03E00008 */  jr    $ra
/* 00D2B8 7000C6B8 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void controller_7000C6BC(void) {
    ? sp1C;

    // Node 0
    osSendMesg(&cont3MesgMQ, &sp1C, 0);
    osRecvMesg(&cont4MesgMQ, &sp1C, 1);
    return;
    // (possible return value: osRecvMesg(&cont4MesgMQ, &sp1C, 1))
}
#else
GLOBAL_ASM(
.text
glabel controller_7000C6BC
/* 00D2BC 7000C6BC 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 00D2C0 7000C6C0 AFBF0014 */  sw    $ra, 0x14($sp)
/* 00D2C4 7000C6C4 3C048006 */  lui   $a0, %hi(cont3MesgMQ)
/* 00D2C8 7000C6C8 248453B0 */  addiu $a0, %lo(cont3MesgMQ) # addiu $a0, $a0, 0x53b0
/* 00D2CC 7000C6CC 27A5001C */  addiu $a1, $sp, 0x1c
/* 00D2D0 7000C6D0 0C0037C4 */  jal   osSendMesg
/* 00D2D4 7000C6D4 00003025 */   move  $a2, $zero
/* 00D2D8 7000C6D8 3C048006 */  lui   $a0, %hi(cont4MesgMQ)
/* 00D2DC 7000C6DC 248453D0 */  addiu $a0, %lo(cont4MesgMQ) # addiu $a0, $a0, 0x53d0
/* 00D2E0 7000C6E0 27A5001C */  addiu $a1, $sp, 0x1c
/* 00D2E4 7000C6E4 0C003774 */  jal   osRecvMesg
/* 00D2E8 7000C6E8 24060001 */   li    $a2, 1
/* 00D2EC 7000C6EC 8FBF0014 */  lw    $ra, 0x14($sp)
/* 00D2F0 7000C6F0 27BD0020 */  addiu $sp, $sp, 0x20
/* 00D2F4 7000C6F4 03E00008 */  jr    $ra
/* 00D2F8 7000C6F8 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
s32 save_7000C6FC(void) {
    s32 sp1C;

    // Node 0
    controller_7000C67C();
    sp1C = osEepromProbe(&contdemoMesgMQ);
    controller_7000C6BC();
    return;
    // (possible return value: sp1C)
}
#else
GLOBAL_ASM(
.text
glabel save_7000C6FC
/* 00D2FC 7000C6FC 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 00D300 7000C700 AFBF0014 */  sw    $ra, 0x14($sp)
/* 00D304 7000C704 0C00319F */  jal   controller_7000C67C
/* 00D308 7000C708 00000000 */   nop   
/* 00D30C 7000C70C 3C048006 */  lui   $a0, %hi(contdemoMesgMQ)
/* 00D310 7000C710 0C0053F4 */  jal   osEepromProbe
/* 00D314 7000C714 24845350 */   addiu $a0, %lo(contdemoMesgMQ) # addiu $a0, $a0, 0x5350
/* 00D318 7000C718 0C0031AF */  jal   controller_7000C6BC
/* 00D31C 7000C71C AFA2001C */   sw    $v0, 0x1c($sp)
/* 00D320 7000C720 8FBF0014 */  lw    $ra, 0x14($sp)
/* 00D324 7000C724 8FA2001C */  lw    $v0, 0x1c($sp)
/* 00D328 7000C728 27BD0020 */  addiu $sp, $sp, 0x20
/* 00D32C 7000C72C 03E00008 */  jr    $ra
/* 00D330 7000C730 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
s32 save_7000C734(s32 arg0, s32 arg1, ? arg8, ? arg9) {
    s32 sp1C;

    // Node 0
    controller_7000C67C();
    sp1C = osEepromRead(&contdemoMesgMQ, arg8, arg9);
    controller_7000C6BC();
    return;
    // (possible return value: sp1C)
}
#else
GLOBAL_ASM(
.text
glabel save_7000C734
/* 00D334 7000C734 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 00D338 7000C738 AFBF0014 */  sw    $ra, 0x14($sp)
/* 00D33C 7000C73C AFA40020 */  sw    $a0, 0x20($sp)
/* 00D340 7000C740 0C00319F */  jal   controller_7000C67C
/* 00D344 7000C744 AFA50024 */   sw    $a1, 0x24($sp)
/* 00D348 7000C748 3C048006 */  lui   $a0, %hi(contdemoMesgMQ)
/* 00D34C 7000C74C 24845350 */  addiu $a0, %lo(contdemoMesgMQ) # addiu $a0, $a0, 0x5350
/* 00D350 7000C750 93A50023 */  lbu   $a1, 0x23($sp)
/* 00D354 7000C754 0C005410 */  jal   osEepromRead
/* 00D358 7000C758 8FA60024 */   lw    $a2, 0x24($sp)
/* 00D35C 7000C75C 0C0031AF */  jal   controller_7000C6BC
/* 00D360 7000C760 AFA2001C */   sw    $v0, 0x1c($sp)
/* 00D364 7000C764 8FBF0014 */  lw    $ra, 0x14($sp)
/* 00D368 7000C768 8FA2001C */  lw    $v0, 0x1c($sp)
/* 00D36C 7000C76C 27BD0020 */  addiu $sp, $sp, 0x20
/* 00D370 7000C770 03E00008 */  jr    $ra
/* 00D374 7000C774 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
s32 save_7000C778(s32 arg0, s32 arg1, ? arg8, ? arg9) {
    s32 sp1C;

    // Node 0
    controller_7000C67C();
    sp1C = osEepromWrite(&contdemoMesgMQ, arg8, arg9);
    controller_7000C6BC();
    return;
    // (possible return value: sp1C)
}
#else
GLOBAL_ASM(
.text
glabel save_7000C778
/* 00D378 7000C778 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 00D37C 7000C77C AFBF0014 */  sw    $ra, 0x14($sp)
/* 00D380 7000C780 AFA40020 */  sw    $a0, 0x20($sp)
/* 00D384 7000C784 0C00319F */  jal   controller_7000C67C
/* 00D388 7000C788 AFA50024 */   sw    $a1, 0x24($sp)
/* 00D38C 7000C78C 3C048006 */  lui   $a0, %hi(contdemoMesgMQ)
/* 00D390 7000C790 24845350 */  addiu $a0, %lo(contdemoMesgMQ) # addiu $a0, $a0, 0x5350
/* 00D394 7000C794 93A50023 */  lbu   $a1, 0x23($sp)
/* 00D398 7000C798 0C0054D0 */  jal   osEepromWrite
/* 00D39C 7000C79C 8FA60024 */   lw    $a2, 0x24($sp)
/* 00D3A0 7000C7A0 0C0031AF */  jal   controller_7000C6BC
/* 00D3A4 7000C7A4 AFA2001C */   sw    $v0, 0x1c($sp)
/* 00D3A8 7000C7A8 8FBF0014 */  lw    $ra, 0x14($sp)
/* 00D3AC 7000C7AC 8FA2001C */  lw    $v0, 0x1c($sp)
/* 00D3B0 7000C7B0 27BD0020 */  addiu $sp, $sp, 0x20
/* 00D3B4 7000C7B4 03E00008 */  jr    $ra
/* 00D3B8 7000C7B8 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
s32 save_7000C7BC(s32 arg0, s32 arg1, ? arg2, ? arg8, ? arg9, ? argA) {
    s32 sp1C;

    // Node 0
    controller_7000C67C();
    sp1C = osEepromLongRead(&contdemoMesgMQ, arg8, arg9, argA);
    controller_7000C6BC();
    return;
    // (possible return value: sp1C)
}
#else
GLOBAL_ASM(
.text
glabel save_7000C7BC
/* 00D3BC 7000C7BC 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 00D3C0 7000C7C0 AFBF0014 */  sw    $ra, 0x14($sp)
/* 00D3C4 7000C7C4 AFA40020 */  sw    $a0, 0x20($sp)
/* 00D3C8 7000C7C8 AFA50024 */  sw    $a1, 0x24($sp)
/* 00D3CC 7000C7CC 0C00319F */  jal   controller_7000C67C
/* 00D3D0 7000C7D0 AFA60028 */   sw    $a2, 0x28($sp)
/* 00D3D4 7000C7D4 3C048006 */  lui   $a0, %hi(contdemoMesgMQ)
/* 00D3D8 7000C7D8 24845350 */  addiu $a0, %lo(contdemoMesgMQ) # addiu $a0, $a0, 0x5350
/* 00D3DC 7000C7DC 93A50023 */  lbu   $a1, 0x23($sp)
/* 00D3E0 7000C7E0 8FA60024 */  lw    $a2, 0x24($sp)
/* 00D3E4 7000C7E4 0C005608 */  jal   osEepromLongRead
/* 00D3E8 7000C7E8 8FA70028 */   lw    $a3, 0x28($sp)
/* 00D3EC 7000C7EC 0C0031AF */  jal   controller_7000C6BC
/* 00D3F0 7000C7F0 AFA2001C */   sw    $v0, 0x1c($sp)
/* 00D3F4 7000C7F4 8FBF0014 */  lw    $ra, 0x14($sp)
/* 00D3F8 7000C7F8 8FA2001C */  lw    $v0, 0x1c($sp)
/* 00D3FC 7000C7FC 27BD0020 */  addiu $sp, $sp, 0x20
/* 00D400 7000C800 03E00008 */  jr    $ra
/* 00D404 7000C804 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
s32 save_7000C808(s32 arg0, s32 arg1, ? arg2, ? arg8, ? arg9, ? argA) {
    s32 sp1C;

    // Node 0
    controller_7000C67C();
    sp1C = osEepromLongWrite(&contdemoMesgMQ, arg8, arg9, argA);
    controller_7000C6BC();
    return;
    // (possible return value: sp1C)
}
#else
GLOBAL_ASM(
.text
glabel save_7000C808
/* 00D408 7000C808 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 00D40C 7000C80C AFBF0014 */  sw    $ra, 0x14($sp)
/* 00D410 7000C810 AFA40020 */  sw    $a0, 0x20($sp)
/* 00D414 7000C814 AFA50024 */  sw    $a1, 0x24($sp)
/* 00D418 7000C818 0C00319F */  jal   controller_7000C67C
/* 00D41C 7000C81C AFA60028 */   sw    $a2, 0x28($sp)
/* 00D420 7000C820 3C048006 */  lui   $a0, %hi(contdemoMesgMQ)
/* 00D424 7000C824 24845350 */  addiu $a0, %lo(contdemoMesgMQ) # addiu $a0, $a0, 0x5350
/* 00D428 7000C828 93A50023 */  lbu   $a1, 0x23($sp)
/* 00D42C 7000C82C 8FA60024 */  lw    $a2, 0x24($sp)
/* 00D430 7000C830 0C005658 */  jal   osEepromLongWrite
/* 00D434 7000C834 8FA70028 */   lw    $a3, 0x28($sp)
/* 00D438 7000C838 0C0031AF */  jal   controller_7000C6BC
/* 00D43C 7000C83C AFA2001C */   sw    $v0, 0x1c($sp)
/* 00D440 7000C840 8FBF0014 */  lw    $ra, 0x14($sp)
/* 00D444 7000C844 8FA2001C */  lw    $v0, 0x1c($sp)
/* 00D448 7000C848 27BD0020 */  addiu $sp, $sp, 0x20
/* 00D44C 7000C84C 03E00008 */  jr    $ra
/* 00D450 7000C850 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
s32 controller_7000C854(s32 arg0, s32 arg1) {
    s32 temp_v1;
    void *temp_a0;
    s32 temp_f8;

    // Node 0
    temp_v1 = (arg0 * 4);
    if (disable_all_rumble == 0)
    {
        // Node 1
        if (*(&controller_1_rumble_inserted + temp_v1) > 0)
        {
            // Node 2
            temp_a0 = (temp_v1 + &controller_1_rumble_duration);
            temp_f8 = (s32) (arg1 * 60.0f);
            if (*temp_a0 < temp_f8)
            {
                // Node 3
                *temp_a0 = temp_f8;
            }
            // Node 4
            if (*(&controller_1_rumble_state + temp_v1) == 0)
            {
                // Node 5
                *(&controller_1_rumble_pulse + temp_v1) = 1;
                return;
                // (possible return value: temp_f8)
            }
        }
    }
    // (function likely void)
}

#else
GLOBAL_ASM(
.text
glabel controller_7000C854
/* 00D454 7000C854 3C0E8002 */  lui   $t6, %hi(disable_all_rumble) 
/* 00D458 7000C858 8DCE6924 */  lw    $t6, %lo(disable_all_rumble)($t6)
/* 00D45C 7000C85C 44856000 */  mtc1  $a1, $f12
/* 00D460 7000C860 00041880 */  sll   $v1, $a0, 2
/* 00D464 7000C864 15C0001B */  bnez  $t6, .L7000C8D4
/* 00D468 7000C868 3C0F8002 */   lui   $t7, %hi(controller_1_rumble_inserted)
/* 00D46C 7000C86C 01E37821 */  addu  $t7, $t7, $v1
/* 00D470 7000C870 8DEF68D8 */  lw    $t7, %lo(controller_1_rumble_inserted)($t7)
/* 00D474 7000C874 3C098002 */  lui   $t1, %hi(controller_1_rumble_state)
/* 00D478 7000C878 3C014270 */  li    $at, 0x42700000 # 60.000000
/* 00D47C 7000C87C 19E00015 */  blez  $t7, .L7000C8D4
/* 00D480 7000C880 01234821 */   addu  $t1, $t1, $v1
/* 00D484 7000C884 44812000 */  mtc1  $at, $f4
/* 00D488 7000C888 3C188002 */  lui   $t8, %hi(controller_1_rumble_duration) 
/* 00D48C 7000C88C 271868F8 */  addiu $t8, %lo(controller_1_rumble_duration) # addiu $t8, $t8, 0x68f8
/* 00D490 7000C890 46046182 */  mul.s $f6, $f12, $f4
/* 00D494 7000C894 00782021 */  addu  $a0, $v1, $t8
/* 00D498 7000C898 8C880000 */  lw    $t0, ($a0)
/* 00D49C 7000C89C 240A0001 */  li    $t2, 1
/* 00D4A0 7000C8A0 4600320D */  trunc.w.s $f8, $f6
/* 00D4A4 7000C8A4 44024000 */  mfc1  $v0, $f8
/* 00D4A8 7000C8A8 00000000 */  nop   
/* 00D4AC 7000C8AC 0102082A */  slt   $at, $t0, $v0
/* 00D4B0 7000C8B0 10200002 */  beqz  $at, .L7000C8BC
/* 00D4B4 7000C8B4 00000000 */   nop   
/* 00D4B8 7000C8B8 AC820000 */  sw    $v0, ($a0)
.L7000C8BC:
/* 00D4BC 7000C8BC 8D2968E8 */  lw    $t1, %lo(controller_1_rumble_state)($t1)
/* 00D4C0 7000C8C0 3C018002 */  lui   $at, %hi(controller_1_rumble_pulse)
/* 00D4C4 7000C8C4 00230821 */  addu  $at, $at, $v1
/* 00D4C8 7000C8C8 15200002 */  bnez  $t1, .L7000C8D4
/* 00D4CC 7000C8CC 00000000 */   nop   
/* 00D4D0 7000C8D0 AC2A6908 */  sw    $t2, %lo(controller_1_rumble_pulse)($at)
.L7000C8D4:
/* 00D4D4 7000C8D4 03E00008 */  jr    $ra
/* 00D4D8 7000C8D8 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void reset_cont_rumble_detect(void) {
    controller_1_rumble_state = 1;
    controller_1_rumble_pulse = 0;
    controller_2_rumble_state = 1;
    controller_2_rumble_pulse = 0;
    controller_3_rumble_state = 1;
    controller_3_rumble_pulse = 0;
    controller_4_rumble_state = 1;
    controller_4_rumble_pulse = 0;
}
#else
#ifdef VERSION_US
GLOBAL_ASM(
.text
glabel reset_cont_rumble_detect
/* 00D4DC 7000C8DC 240E0001 */  li    $t6, 1
/* 00D4E0 7000C8E0 3C018002 */  lui   $at, %hi(controller_1_rumble_state)
/* 00D4E4 7000C8E4 AC2E68E8 */  sw    $t6, %lo(controller_1_rumble_state)($at)
/* 00D4E8 7000C8E8 3C018002 */  lui   $at, %hi(controller_1_rumble_pulse)
/* 00D4EC 7000C8EC AC206908 */  sw    $zero, %lo(controller_1_rumble_pulse)($at)
/* 00D4F0 7000C8F0 3C018002 */  lui   $at, %hi(controller_2_rumble_state)
/* 00D4F4 7000C8F4 240F0001 */  li    $t7, 1
/* 00D4F8 7000C8F8 AC2F68EC */  sw    $t7, %lo(controller_2_rumble_state)($at)
/* 00D4FC 7000C8FC 3C018002 */  lui   $at, %hi(controller_2_rumble_pulse)
/* 00D500 7000C900 AC20690C */  sw    $zero, %lo(controller_2_rumble_pulse)($at)
/* 00D504 7000C904 3C018002 */  lui   $at, %hi(controller_3_rumble_state)
/* 00D508 7000C908 24180001 */  li    $t8, 1
/* 00D50C 7000C90C AC3868F0 */  sw    $t8, %lo(controller_3_rumble_state)($at)
/* 00D510 7000C910 3C018002 */  lui   $at, %hi(controller_3_rumble_pulse)
/* 00D514 7000C914 AC206910 */  sw    $zero, %lo(controller_3_rumble_pulse)($at)
/* 00D518 7000C918 3C018002 */  lui   $at, %hi(controller_4_rumble_state)
/* 00D51C 7000C91C 24190001 */  li    $t9, 1
/* 00D520 7000C920 AC3968F4 */  sw    $t9, %lo(controller_4_rumble_state)($at)
/* 00D524 7000C924 3C018002 */  lui   $at, %hi( controller_4_rumble_pulse)
/* 00D528 7000C928 03E00008 */  jr    $ra
/* 00D52C 7000C92C AC206914 */   sw    $zero, %lo( controller_4_rumble_pulse)($at)
)
#endif

#ifdef VERSION_JP
GLOBAL_ASM(
.text
glabel reset_cont_rumble_detect
/* 00D4E8 7000C8E8 3C018002 */  lui   $at, %hi(controller_1_rumble_pulse)
/* 00D4F4 7000C8F4 240F0001 */  li    $t7, 2
/* 00D4DC 7000C8DC 240E0001 */  li    $t6, 2
/* 00D500 7000C900 AC20690C */  sw    $t7, %lo(controller_2_rumble_pulse)($at)
/* 00D4EC 7000C8EC AC206908 */  sw    $t6, %lo(controller_1_rumble_pulse)($at)
/* 00D510 7000C910 3C018002 */  lui   $at, %hi(controller_3_rumble_pulse)
/* 00D508 7000C908 24180001 */  li    $t8, 2
/* 00D51C 7000C91C 24190001 */  li    $t9, 2
/* 00D514 7000C914 AC206910 */  sw    $t9, %lo(controller_4_rumble_pulse)($at)
/* 00D528 7000C928 03E00008 */  jr    $ra
/* 00D52C 7000C92C AC206914 */   sw    $t8, %lo( controller_3_rumble_pulse)($at)
)
#endif

#endif





#ifdef NONMATCHING
void controller_7000C930(s32 arg0) {
    // Node 0
    (void *)0x80020000->unk68C4 = (s32) ((arg0 * 0x1fc) + &controller_input_index);
    return;
    // (function likely void)
}
#else
GLOBAL_ASM(
.text
glabel controller_7000C930
/* 00D530 7000C930 000471C0 */  sll   $t6, $a0, 7
/* 00D534 7000C934 01C47023 */  subu  $t6, $t6, $a0
/* 00D538 7000C938 3C0F8006 */  lui   $t7, %hi(controller_input_index) 
/* 00D53C 7000C93C 25EF4F30 */  addiu $t7, %lo(controller_input_index) # addiu $t7, $t7, 0x4f30
/* 00D540 7000C940 000E7080 */  sll   $t6, $t6, 2
/* 00D544 7000C944 01CFC021 */  addu  $t8, $t6, $t7
/* 00D548 7000C948 3C018002 */  lui   $at, %hi(ptr_current_point_in_controller_input_index)
/* 00D54C 7000C94C 03E00008 */  jr    $ra
/* 00D550 7000C950 AC3868C4 */   sw    $t8, %lo(ptr_current_point_in_controller_input_index)($at)
)
#endif





#ifdef NONMATCHING
s32 controller_7000C954(void) {
    // (possible return value: ((s32) (ptr_current_point_in_controller_input_index - &controller_input_index) / 0x1fc))
}
#else
GLOBAL_ASM(
.text
glabel controller_7000C954
/* 00D554 7000C954 3C0E8002 */  lui   $t6, %hi(ptr_current_point_in_controller_input_index) 
/* 00D558 7000C958 8DCE68C4 */  lw    $t6, %lo(ptr_current_point_in_controller_input_index)($t6)
/* 00D55C 7000C95C 3C0F8006 */  lui   $t7, %hi(controller_input_index) 
/* 00D560 7000C960 25EF4F30 */  addiu $t7, %lo(controller_input_index) # addiu $t7, $t7, 0x4f30
/* 00D564 7000C964 240101FC */  li    $at, 508
/* 00D568 7000C968 01CF1023 */  subu  $v0, $t6, $t7
/* 00D56C 7000C96C 0041001A */  div   $zero, $v0, $at
/* 00D570 7000C970 00001012 */  mflo  $v0
/* 00D574 7000C974 03E00008 */  jr    $ra
/* 00D578 7000C978 00000000 */   nop   
)  
#endif




