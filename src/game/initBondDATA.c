#include <ultra64.h>
#include <memp.h>
#include "initBondDATA.h"


#ifdef REFRESH_PAL
#define VALUENAME 16.750415802f
#else
#define VALUENAME 19.999996
#endif
struct  BONDdata_item_control_blocks hand_data_dummy = {        
0, 0xFFFFFFFF, 0, 0x100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1.0, 0, 0, 0, 0, 1.0, 0, 0, 0, 0, 1.0, 0, 
0, 0, 0, 1.0, 0, 0, 0, 0, 0, 0, -1.0, 0, 1.0, 0, 0, 0, 0, 0, 0, -VALUENAME, 0, 
VALUENAME, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1.0, 0, 0, -1.0, 0, 0,
-1.0, 0, 0, -1.0, 0, 1.0, 0, 0, 1.0, 0, 0, 1.0, 0, 0, 1.0, 0, 0, 0, 1.0, 1.0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1000.0, 0, 0, 0, 0, 0xFF000000, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0
};







#ifdef NONMATCHING
void init_player_BONDdata_stats(void) {
        s32 sp24;
    s32 temp_v0;
    s32 temp_v0_2;
    s32* temp_t0;
    s32* temp_t4;
    s32* temp_t6;
    s32* temp_t7;
    void* temp_t1;
    void* temp_t5;
    s32* phi_t7;
    s32* phi_t6;
    s32* phi_t4;
    void* phi_t1;
    s32* phi_t0;
    void* phi_t5;
    s32 phi_v0;

    phi_t7 = &BONDdata_item_control_blocks_initdata;
    phi_t6 = &sp24;
    do {
        temp_t7 = phi_t7 + 0xC;
        temp_t6 = phi_t6 + 0xC;
        temp_t6->unk-C = (s32) *phi_t7;
        temp_t6->unk-8 = (s32) temp_t7->unk-8;
        temp_t6->unk-4 = (s32) temp_t7->unk-4;
        phi_t7 = temp_t7;
        phi_t6 = temp_t6;
    } while (temp_t7 != (&BONDdata_item_control_blocks_initdata + 0x3A8));
    g_CurrentPlayer->hand_item[0] = mempAllocBytesInBank(size_item_buffer, 4);
    if (getPlayerCount() == 1) {
        g_CurrentPlayer->hand_item[1] = mempAllocBytesInBank(*(&size_item_buffer + 4), 4);
    }
    g_CurrentPlayer->hand_invisible[0] = 0;
    g_CurrentPlayer->hand_invisible[1] = 0;
    g_CurrentPlayer->hand_item[0] = 0;
    g_CurrentPlayer->hand_item[1] = 0;
    g_CurrentPlayer->field_2A44[0] = -1;
    g_CurrentPlayer->field_2A44[1] = -1;
    g_CurrentPlayer->lock_hand_model[0] = 0;
    g_CurrentPlayer->lock_hand_model[1] = 0;
    phi_t4 = &sp24;
    phi_t1 = g_CurrentPlayer;
    phi_t0 = &sp24;
    phi_v0 = 0;
    do {
        temp_t4 = phi_t4 + 0xC;
        temp_t1 = phi_t1 + 0xC;
        temp_t1->right_item_related1 = (s32) *phi_t4;
        temp_t1->right_item_related2 = (s32) temp_t4->unk-8;
        temp_t1->right_item_related3 = (s32) temp_t4->unk-4;
        phi_t4 = temp_t4;
        phi_t1 = temp_t1;
    } while (temp_t4 != (&sp24 + 0x3A8));
    phi_t5 = g_CurrentPlayer;
    do {
        temp_t0 = phi_t0 + 0xC;
        temp_t5 = phi_t5 + 0xC;
        temp_t5->item_related1 = (s32) *phi_t0;
        temp_t5->item_related2 = (s32) temp_t0->unk-8;
        temp_t5->item_related3 = (s32) temp_t0->unk-4;
        phi_t0 = temp_t0;
        phi_t5 = temp_t5;
    } while (temp_t0 != (&sp24 + 0x3A8));
    do {
        temp_v0 = phi_v0 + 4;
        (g_CurrentPlayer + phi_v0)->unk1130 = 0;
        phi_v0 = temp_v0;
    } while (temp_v0 < 0x78);
    temp_v0_2 = 3 * 4;
    g_playerPerm->pos[0] = 0;
    g_playerPerm->pos[1] = 0;
    g_playerPerm->pos[2] = 0;
    *(g_playerPerm + temp_v0_2) = 0;
    (g_playerPerm + temp_v0_2)->unk4 = 0;
    (g_playerPerm + temp_v0_2)->unk8 = 0;
    (g_playerPerm + temp_v0_2)->unkC = 0;
    g_playerPerm->field_6C = 0;
    g_playerPerm->unk1C = 0;
    g_playerPerm->unk20 = 0;
    g_CurrentPlayer->deathcount = 0;
    g_CurrentPlayer->num_suicides = 0;
    g_CurrentPlayer->gunposamplitude = 1;
    g_CurrentPlayer->gunxamplitude = 1;
    g_CurrentPlayer->field_FC8 = 0;
    g_CurrentPlayer->field_FCC = 0;
    g_CurrentPlayer->field_FD0 = 0;
    g_CurrentPlayer->z_trigger_timer = 0;
    g_CurrentPlayer->field_FD8 = 0;
    g_CurrentPlayer->field_FDC = 0xFF;
    g_CurrentPlayer->field_FDD = 0xFF;
    g_CurrentPlayer->field_FDE = 0xFF;
    g_CurrentPlayer->field_FDF = 0;
    g_CurrentPlayer->resetshadecol = 1;
    g_CurrentPlayer->field_FE4 = 0;
    g_CurrentPlayer->crosshair_angle[] = 0.0f;
    g_CurrentPlayer->crosshair_angle[] = 0.0f;
    g_CurrentPlayer->crosshair_x_pos = 0.0f;
    g_CurrentPlayer->crosshair_y_pos = 0.0f;
    g_CurrentPlayer->guncrossdamp = 0.9f;
    g_CurrentPlayer->field_FFC.x = 0.0f;
    g_CurrentPlayer->field_FFC.y = 0.0f;
    g_CurrentPlayer->gun_azimuth_angle = 0.0f;
    g_CurrentPlayer->gun_azimuth_turning = 0.0f;
    g_CurrentPlayer->gunaimdamp = 0.9f;
    g_CurrentPlayer->field_1010 = 0.0f;
    g_CurrentPlayer->holds_neg_pi = -3.1415927f;
    g_CurrentPlayer->unk1018 = 0.0f;
    g_CurrentPlayer->copiedgoldeneye = FALSE;
    g_CurrentPlayer->magnetattracttime = -1;
    g_CurrentPlayer->gunsync = 0.0f;
    g_CurrentPlayer->syncchange = 0.0f;
    g_CurrentPlayer->synccount = 0.0f;
    g_CurrentPlayer->syncoffset = 0;
    g_CurrentPlayer->field_107C = 0.0f;
    g_CurrentPlayer->field_1080 = 0.0f;
    bgunCalculateBlend(GUNRIGHT);
    bgunCalculateBlend(GUNRIGHT);
    bgunCalculateBlend(GUNRIGHT);
    bgunCalculateBlend(GUNLEFT);
    bgunCalculateBlend(GUNLEFT);
    bgunCalculateBlend(GUNLEFT);
    g_CurrentPlayer->gunammooff = 0;
    g_CurrentPlayer->gunsightmode = 2; //GUNSIGHTREASON_AIMING
    g_CurrentPlayer->sniper_zoom = sniperrifle_stats.Zoom;
    g_CurrentPlayer->camera_zoom = camera_stats.Zoom;
}
#else

#if defined(LEFTOVERDEBUG)
GLOBAL_ASM(
.late_rodata
glabel D_8004F0E0
.word 0x3f666666
glabel fl_neg_pi
.word 0xc0490fdb
.text
glabel init_player_BONDdata_stats
/* 039C00 7F0050D0 27BDFC30 */  addiu $sp, $sp, -0x3d0
/* 039C04 7F0050D4 3C0F8003 */  lui   $t7, %hi(hand_data_dummy) 
/* 039C08 7F0050D8 25EFA3D0 */  addiu $t7, %lo(hand_data_dummy) # addiu $t7, $t7, -0x5c30
/* 039C0C 7F0050DC AFBF001C */  sw    $ra, 0x1c($sp)
/* 039C10 7F0050E0 AFB00018 */  sw    $s0, 0x18($sp)
/* 039C14 7F0050E4 25E803A8 */  addiu $t0, $t7, 0x3a8
/* 039C18 7F0050E8 27AE0024 */  addiu $t6, $sp, 0x24
.L7F0050EC:
/* 039C1C 7F0050EC 8DE10000 */  lw    $at, ($t7)
/* 039C20 7F0050F0 25EF000C */  addiu $t7, $t7, 0xc
/* 039C24 7F0050F4 25CE000C */  addiu $t6, $t6, 0xc
/* 039C28 7F0050F8 ADC1FFF4 */  sw    $at, -0xc($t6)
/* 039C2C 7F0050FC 8DE1FFF8 */  lw    $at, -8($t7)
/* 039C30 7F005100 ADC1FFF8 */  sw    $at, -8($t6)
/* 039C34 7F005104 8DE1FFFC */  lw    $at, -4($t7)
/* 039C38 7F005108 15E8FFF8 */  bne   $t7, $t0, .L7F0050EC
/* 039C3C 7F00510C ADC1FFFC */   sw    $at, -4($t6)
/* 039C40 7F005110 3C048003 */  lui   $a0, %hi(size_item_buffer)
/* 039C44 7F005114 8C84245C */  lw    $a0, %lo(size_item_buffer)($a0)
/* 039C48 7F005118 0C0025C8 */  jal   mempAllocBytesInBank
/* 039C4C 7F00511C 24050004 */   li    $a1, 4
/* 039C50 7F005120 3C108008 */  lui   $s0, %hi(g_CurrentPlayer)
/* 039C54 7F005124 2610A0B0 */  addiu $s0, %lo(g_CurrentPlayer) # addiu $s0, $s0, -0x5f50
/* 039C58 7F005128 8E090000 */  lw    $t1, ($s0)
/* 039C5C 7F00512C 0FC26919 */  jal   getPlayerCount
/* 039C60 7F005130 AD220808 */   sw    $v0, 0x808($t1)
/* 039C64 7F005134 24010001 */  li    $at, 1
/* 039C68 7F005138 14410006 */  bne   $v0, $at, .L7F005154
/* 039C6C 7F00513C 3C048003 */   lui   $a0, %hi(size_item_buffer+0x4)
/* 039C70 7F005140 8C842460 */  lw    $a0, %lo(size_item_buffer+0x4)($a0)
/* 039C74 7F005144 0C0025C8 */  jal   mempAllocBytesInBank
/* 039C78 7F005148 24050004 */   li    $a1, 4
/* 039C7C 7F00514C 8E0A0000 */  lw    $t2, ($s0)
/* 039C80 7F005150 AD42080C */  sw    $v0, 0x80c($t2)
.L7F005154:
/* 039C84 7F005154 8E0B0000 */  lw    $t3, ($s0)
/* 039C88 7F005158 2405FFFF */  li    $a1, -1
/* 039C8C 7F00515C 27A30024 */  addiu $v1, $sp, 0x24
/* 039C90 7F005160 AD6007F8 */  sw    $zero, 0x7f8($t3)
/* 039C94 7F005164 8E0C0000 */  lw    $t4, ($s0)
/* 039C98 7F005168 246B03A8 */  addiu $t3, $v1, 0x3a8
/* 039C9C 7F00516C 00001025 */  move  $v0, $zero
/* 039CA0 7F005170 AD8007FC */  sw    $zero, 0x7fc($t4)
/* 039CA4 7F005174 8E0D0000 */  lw    $t5, ($s0)
/* 039CA8 7F005178 00606025 */  move  $t4, $v1
/* 039CAC 7F00517C ADA00800 */  sw    $zero, 0x800($t5)
/* 039CB0 7F005180 8E190000 */  lw    $t9, ($s0)
/* 039CB4 7F005184 AF200804 */  sw    $zero, 0x804($t9)
/* 039CB8 7F005188 8E180000 */  lw    $t8, ($s0)
/* 039CBC 7F00518C AF052A44 */  sw    $a1, 0x2a44($t8)
/* 039CC0 7F005190 8E080000 */  lw    $t0, ($s0)
/* 039CC4 7F005194 247803A8 */  addiu $t8, $v1, 0x3a8
/* 039CC8 7F005198 AD052A48 */  sw    $a1, 0x2a48($t0)
/* 039CCC 7F00519C 8E0F0000 */  lw    $t7, ($s0)
/* 039CD0 7F0051A0 00604025 */  move  $t0, $v1
/* 039CD4 7F0051A4 3C038008 */  lui   $v1, %hi(g_playerPerm)
/* 039CD8 7F0051A8 ADE02A50 */  sw    $zero, 0x2a50($t7)
/* 039CDC 7F0051AC 8E0E0000 */  lw    $t6, ($s0)
/* 039CE0 7F0051B0 2463A0B4 */  addiu $v1, %lo(g_playerPerm) # addiu $v1, $v1, -0x5f4c
/* 039CE4 7F0051B4 ADC02A54 */  sw    $zero, 0x2a54($t6)
/* 039CE8 7F0051B8 8E090000 */  lw    $t1, ($s0)
.L7F0051BC:
/* 039CEC 7F0051BC 8D810000 */  lw    $at, ($t4)
/* 039CF0 7F0051C0 258C000C */  addiu $t4, $t4, 0xc
/* 039CF4 7F0051C4 2529000C */  addiu $t1, $t1, 0xc
/* 039CF8 7F0051C8 AD210864 */  sw    $at, 0x864($t1)
/* 039CFC 7F0051CC 8D81FFF8 */  lw    $at, -8($t4)
/* 039D00 7F0051D0 AD210868 */  sw    $at, 0x868($t1)
/* 039D04 7F0051D4 8D81FFFC */  lw    $at, -4($t4)
/* 039D08 7F0051D8 158BFFF8 */  bne   $t4, $t3, .L7F0051BC
/* 039D0C 7F0051DC AD21086C */   sw    $at, 0x86c($t1)
/* 039D10 7F0051E0 8E0D0000 */  lw    $t5, ($s0)
.L7F0051E4:
/* 039D14 7F0051E4 8D010000 */  lw    $at, ($t0)
/* 039D18 7F0051E8 2508000C */  addiu $t0, $t0, 0xc
/* 039D1C 7F0051EC 25AD000C */  addiu $t5, $t5, 0xc
/* 039D20 7F0051F0 ADA10C0C */  sw    $at, 0xc0c($t5)
/* 039D24 7F0051F4 8D01FFF8 */  lw    $at, -8($t0)
/* 039D28 7F0051F8 ADA10C10 */  sw    $at, 0xc10($t5)
/* 039D2C 7F0051FC 8D01FFFC */  lw    $at, -4($t0)
/* 039D30 7F005200 1518FFF8 */  bne   $t0, $t8, .L7F0051E4
/* 039D34 7F005204 ADA10C14 */   sw    $at, 0xc14($t5)
.L7F005208:
/* 039D38 7F005208 8E0F0000 */  lw    $t7, ($s0)
/* 039D3C 7F00520C 01E27021 */  addu  $t6, $t7, $v0
/* 039D40 7F005210 24420004 */  addiu $v0, $v0, 4
/* 039D44 7F005214 28410078 */  slti  $at, $v0, 0x78
/* 039D48 7F005218 1420FFFB */  bnez  $at, .L7F005208
/* 039D4C 7F00521C ADC01130 */   sw    $zero, 0x1130($t6)
/* 039D50 7F005220 8C6A0000 */  lw    $t2, ($v1)
/* 039D54 7F005224 24040003 */  li    $a0, 3
/* 039D58 7F005228 00041080 */  sll   $v0, $a0, 2
/* 039D5C 7F00522C AD400000 */  sw    $zero, ($t2)
/* 039D60 7F005230 8C6B0000 */  lw    $t3, ($v1)
/* 039D64 7F005234 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 039D68 7F005238 44811000 */  mtc1  $at, $f2
/* 039D6C 7F00523C AD600004 */  sw    $zero, 4($t3)
/* 039D70 7F005240 8C6C0000 */  lw    $t4, ($v1)
/* 039D74 7F005244 3C018005 */  lui   $at, %hi(D_8004F0E0)
/* 039D78 7F005248 44800000 */  mtc1  $zero, $f0
/* 039D7C 7F00524C AD800008 */  sw    $zero, 8($t4)
/* 039D80 7F005250 8C690000 */  lw    $t1, ($v1)
/* 039D84 7F005254 00002025 */  move  $a0, $zero
/* 039D88 7F005258 0122C821 */  addu  $t9, $t1, $v0
/* 039D8C 7F00525C AF200000 */  sw    $zero, ($t9)
/* 039D90 7F005260 8C780000 */  lw    $t8, ($v1)
/* 039D94 7F005264 03024021 */  addu  $t0, $t8, $v0
/* 039D98 7F005268 AD000004 */  sw    $zero, 4($t0)
/* 039D9C 7F00526C 8C6D0000 */  lw    $t5, ($v1)
/* 039DA0 7F005270 01A27821 */  addu  $t7, $t5, $v0
/* 039DA4 7F005274 ADE00008 */  sw    $zero, 8($t7)
/* 039DA8 7F005278 8C6E0000 */  lw    $t6, ($v1)
/* 039DAC 7F00527C 01C25021 */  addu  $t2, $t6, $v0
/* 039DB0 7F005280 AD40000C */  sw    $zero, 0xc($t2)
/* 039DB4 7F005284 8C6B0000 */  lw    $t3, ($v1)
/* 039DB8 7F005288 C42CF0E0 */  lwc1  $f12, %lo(D_8004F0E0)($at)
/* 039DBC 7F00528C 240200FF */  li    $v0, 255
/* 039DC0 7F005290 AD60006C */  sw    $zero, 0x6c($t3)
/* 039DC4 7F005294 8C6C0000 */  lw    $t4, ($v1)
/* 039DC8 7F005298 3C018005 */  lui   $at, %hi(fl_neg_pi)
/* 039DCC 7F00529C AD80001C */  sw    $zero, 0x1c($t4)
/* 039DD0 7F0052A0 8C690000 */  lw    $t1, ($v1)
/* 039DD4 7F0052A4 AD200020 */  sw    $zero, 0x20($t1)
/* 039DD8 7F0052A8 8E190000 */  lw    $t9, ($s0)
/* 039DDC 7F0052AC AF2029D8 */  sw    $zero, 0x29d8($t9)
/* 039DE0 7F0052B0 8E180000 */  lw    $t8, ($s0)
/* 039DE4 7F0052B4 AF0029DC */  sw    $zero, 0x29dc($t8)
/* 039DE8 7F0052B8 8E080000 */  lw    $t0, ($s0)
/* 039DEC 7F0052BC E5020FC0 */  swc1  $f2, 0xfc0($t0)
/* 039DF0 7F0052C0 8E0D0000 */  lw    $t5, ($s0)
/* 039DF4 7F0052C4 E5A20FC4 */  swc1  $f2, 0xfc4($t5)
/* 039DF8 7F0052C8 8E0F0000 */  lw    $t7, ($s0)
/* 039DFC 7F0052CC 240D0001 */  li    $t5, 1
/* 039E00 7F0052D0 ADE00FC8 */  sw    $zero, 0xfc8($t7)
/* 039E04 7F0052D4 8E0E0000 */  lw    $t6, ($s0)
/* 039E08 7F0052D8 ADC00FCC */  sw    $zero, 0xfcc($t6)
/* 039E0C 7F0052DC 8E0A0000 */  lw    $t2, ($s0)
/* 039E10 7F0052E0 AD400FD0 */  sw    $zero, 0xfd0($t2)
/* 039E14 7F0052E4 8E0B0000 */  lw    $t3, ($s0)
/* 039E18 7F0052E8 AD600FD4 */  sw    $zero, 0xfd4($t3)
/* 039E1C 7F0052EC 8E0C0000 */  lw    $t4, ($s0)
/* 039E20 7F0052F0 AD800FD8 */  sw    $zero, 0xfd8($t4)
/* 039E24 7F0052F4 8E090000 */  lw    $t1, ($s0)
/* 039E28 7F0052F8 A1220FDC */  sb    $v0, 0xfdc($t1)
/* 039E2C 7F0052FC 8E190000 */  lw    $t9, ($s0)
/* 039E30 7F005300 A3220FDD */  sb    $v0, 0xfdd($t9)
/* 039E34 7F005304 8E180000 */  lw    $t8, ($s0)
/* 039E38 7F005308 A3020FDE */  sb    $v0, 0xfde($t8)
/* 039E3C 7F00530C 8E080000 */  lw    $t0, ($s0)
/* 039E40 7F005310 A1000FDF */  sb    $zero, 0xfdf($t0)
/* 039E44 7F005314 8E0F0000 */  lw    $t7, ($s0)
/* 039E48 7F005318 ADED0FE0 */  sw    $t5, 0xfe0($t7)
/* 039E4C 7F00531C 8E0E0000 */  lw    $t6, ($s0)
/* 039E50 7F005320 ADC00FE4 */  sw    $zero, 0xfe4($t6)
/* 039E54 7F005324 8E0A0000 */  lw    $t2, ($s0)
/* 039E58 7F005328 E5400FE8 */  swc1  $f0, 0xfe8($t2)
/* 039E5C 7F00532C 8E0B0000 */  lw    $t3, ($s0)
/* 039E60 7F005330 E5600FEC */  swc1  $f0, 0xfec($t3)
/* 039E64 7F005334 8E0C0000 */  lw    $t4, ($s0)
/* 039E68 7F005338 E5800FF0 */  swc1  $f0, 0xff0($t4)
/* 039E6C 7F00533C 8E090000 */  lw    $t1, ($s0)
/* 039E70 7F005340 E5200FF4 */  swc1  $f0, 0xff4($t1)
/* 039E74 7F005344 8E190000 */  lw    $t9, ($s0)
/* 039E78 7F005348 E72C0FF8 */  swc1  $f12, 0xff8($t9)
/* 039E7C 7F00534C 8E180000 */  lw    $t8, ($s0)
/* 039E80 7F005350 E7000FFC */  swc1  $f0, 0xffc($t8)
/* 039E84 7F005354 8E080000 */  lw    $t0, ($s0)
/* 039E88 7F005358 E5001000 */  swc1  $f0, 0x1000($t0)
/* 039E8C 7F00535C 8E0D0000 */  lw    $t5, ($s0)
/* 039E90 7F005360 E5A01004 */  swc1  $f0, 0x1004($t5)
/* 039E94 7F005364 8E0F0000 */  lw    $t7, ($s0)
/* 039E98 7F005368 E5E01008 */  swc1  $f0, 0x1008($t7)
/* 039E9C 7F00536C 8E0E0000 */  lw    $t6, ($s0)
/* 039EA0 7F005370 E5CC100C */  swc1  $f12, 0x100c($t6)
/* 039EA4 7F005374 8E0A0000 */  lw    $t2, ($s0)
/* 039EA8 7F005378 E5401010 */  swc1  $f0, 0x1010($t2)
/* 039EAC 7F00537C 8E0B0000 */  lw    $t3, ($s0)
/* 039EB0 7F005380 C424F0E4 */  lwc1  $f4, %lo(fl_neg_pi)($at)
/* 039EB4 7F005384 E5641014 */  swc1  $f4, 0x1014($t3)
/* 039EB8 7F005388 8E0C0000 */  lw    $t4, ($s0)
/* 039EBC 7F00538C E5801018 */  swc1  $f0, 0x1018($t4)
/* 039EC0 7F005390 8E090000 */  lw    $t1, ($s0)
/* 039EC4 7F005394 AD201060 */  sw    $zero, 0x1060($t1)
/* 039EC8 7F005398 8E190000 */  lw    $t9, ($s0)
/* 039ECC 7F00539C AF251270 */  sw    $a1, 0x1270($t9)
/* 039ED0 7F0053A0 8E180000 */  lw    $t8, ($s0)
/* 039ED4 7F0053A4 E700106C */  swc1  $f0, 0x106c($t8)
/* 039ED8 7F0053A8 8E080000 */  lw    $t0, ($s0)
/* 039EDC 7F0053AC E5001070 */  swc1  $f0, 0x1070($t0)
/* 039EE0 7F0053B0 8E0D0000 */  lw    $t5, ($s0)
/* 039EE4 7F0053B4 E5A01074 */  swc1  $f0, 0x1074($t5)
/* 039EE8 7F0053B8 8E0F0000 */  lw    $t7, ($s0)
/* 039EEC 7F0053BC ADE01078 */  sw    $zero, 0x1078($t7)
/* 039EF0 7F0053C0 8E0E0000 */  lw    $t6, ($s0)
/* 039EF4 7F0053C4 E5C0107C */  swc1  $f0, 0x107c($t6)
/* 039EF8 7F0053C8 8E0A0000 */  lw    $t2, ($s0)
/* 039EFC 7F0053CC 0FC17260 */  jal   bgunCalculateBlend
/* 039F00 7F0053D0 E5401080 */   swc1  $f0, 0x1080($t2)
/* 039F04 7F0053D4 0FC17260 */  jal   bgunCalculateBlend
/* 039F08 7F0053D8 00002025 */   move  $a0, $zero
/* 039F0C 7F0053DC 0FC17260 */  jal   bgunCalculateBlend
/* 039F10 7F0053E0 00002025 */   move  $a0, $zero
/* 039F14 7F0053E4 0FC17260 */  jal   bgunCalculateBlend
/* 039F18 7F0053E8 24040001 */   li    $a0, 1
/* 039F1C 7F0053EC 0FC17260 */  jal   bgunCalculateBlend
/* 039F20 7F0053F0 24040001 */   li    $a0, 1
/* 039F24 7F0053F4 0FC17260 */  jal   bgunCalculateBlend
/* 039F28 7F0053F8 24040001 */   li    $a0, 1
/* 039F2C 7F0053FC 8E0B0000 */  lw    $t3, ($s0)
/* 039F30 7F005400 240C0002 */  li    $t4, 2
/* 039F34 7F005404 3C018003 */  lui   $at, %hi(sniperrifle_stats+52)
/* 039F38 7F005408 AD601064 */  sw    $zero, 0x1064($t3)
/* 039F3C 7F00540C 8E090000 */  lw    $t1, ($s0)
/* 039F40 7F005410 AD2C1128 */  sw    $t4, 0x1128($t1)
/* 039F44 7F005414 8E190000 */  lw    $t9, ($s0)
/* 039F48 7F005418 C4262C38 */  lwc1  $f6, %lo(sniperrifle_stats+52)($at)
/* 039F4C 7F00541C 3C018003 */  lui   $at, %hi(camera_stats+52)
/* 039F50 7F005420 E7261084 */  swc1  $f6, 0x1084($t9)
/* 039F54 7F005424 8E180000 */  lw    $t8, ($s0)
/* 039F58 7F005428 C42836B8 */  lwc1  $f8, %lo(camera_stats+52)($at)
/* 039F5C 7F00542C E7081088 */  swc1  $f8, 0x1088($t8)
/* 039F60 7F005430 8FBF001C */  lw    $ra, 0x1c($sp)
/* 039F64 7F005434 8FB00018 */  lw    $s0, 0x18($sp)
/* 039F68 7F005438 27BD03D0 */  addiu $sp, $sp, 0x3d0
/* 039F6C 7F00543C 03E00008 */  jr    $ra
/* 039F70 7F005440 00000000 */   nop
)
#endif

#if !defined(LEFTOVERDEBUG)
GLOBAL_ASM(
.late_rodata
glabel D_8004F0E0
.word 0x3f666666
glabel fl_neg_pi
.word 0xc0490fdb

.text
glabel init_player_BONDdata_stats
/* 037A60 7F005070 27BDFC30 */  addiu $sp, $sp, -0x3d0
/* 037A64 7F005074 3C0F8002 */  lui   $t7, %hi(hand_data_dummy) # $t7, 0x8002
/* 037A68 7F005078 25EF5920 */  addiu $t7, %lo(hand_data_dummy) # addiu $t7, $t7, 0x5920
/* 037A6C 7F00507C AFBF001C */  sw    $ra, 0x1c($sp)
/* 037A70 7F005080 AFB00018 */  sw    $s0, 0x18($sp)
/* 037A74 7F005084 25E803A8 */  addiu $t0, $t7, 0x3a8
/* 037A78 7F005088 27AE0024 */  addiu $t6, $sp, 0x24
.L7F00508C:
/* 037A7C 7F00508C 8DE10000 */  lw    $at, ($t7)
/* 037A80 7F005090 25EF000C */  addiu $t7, $t7, 0xc
/* 037A84 7F005094 25CE000C */  addiu $t6, $t6, 0xc
/* 037A88 7F005098 ADC1FFF4 */  sw    $at, -0xc($t6)
/* 037A8C 7F00509C 8DE1FFF8 */  lw    $at, -8($t7)
/* 037A90 7F0050A0 ADC1FFF8 */  sw    $at, -8($t6)
/* 037A94 7F0050A4 8DE1FFFC */  lw    $at, -4($t7)
/* 037A98 7F0050A8 15E8FFF8 */  bne   $t7, $t0, .L7F00508C
/* 037A9C 7F0050AC ADC1FFFC */   sw    $at, -4($t6)
/* 037AA0 7F0050B0 3C048003 */  lui   $a0, %hi(size_item_buffer) # $a0, 0x8003
/* 037AA4 7F0050B4 8C84D9AC */  lw    $a0, %lo(size_item_buffer)($a0)
/* 037AA8 7F0050B8 0C0022E0 */  jal   mempAllocBytesInBank
/* 037AAC 7F0050BC 24050004 */   li    $a1, 4
/* 037AB0 7F0050C0 3C108007 */  lui   $s0, %hi(g_CurrentPlayer) # $s0, 0x8007
/* 037AB4 7F0050C4 26108BC0 */  addiu $s0, %lo(g_CurrentPlayer) # addiu $s0, $s0, -0x7440
/* 037AB8 7F0050C8 8E090000 */  lw    $t1, ($s0)
/* 037ABC 7F0050CC 0FC26669 */  jal   getPlayerCount
/* 037AC0 7F0050D0 AD220808 */   sw    $v0, 0x808($t1)
/* 037AC4 7F0050D4 24010001 */  li    $at, 1
/* 037AC8 7F0050D8 14410006 */  bne   $v0, $at, .L7F0050F4
/* 037ACC 7F0050DC 3C048003 */   lui   $a0, %hi(size_item_buffer+0x4) # $a0, 0x8003
/* 037AD0 7F0050E0 8C84D9B0 */  lw    $a0, %lo(size_item_buffer+0x4)($a0)
/* 037AD4 7F0050E4 0C0022E0 */  jal   mempAllocBytesInBank
/* 037AD8 7F0050E8 24050004 */   li    $a1, 4
/* 037ADC 7F0050EC 8E0A0000 */  lw    $t2, ($s0)
/* 037AE0 7F0050F0 AD42080C */  sw    $v0, 0x80c($t2)
.L7F0050F4:
/* 037AE4 7F0050F4 8E0B0000 */  lw    $t3, ($s0)
/* 037AE8 7F0050F8 2405FFFF */  li    $a1, -1
/* 037AEC 7F0050FC 27A30024 */  addiu $v1, $sp, 0x24
/* 037AF0 7F005100 AD6007F8 */  sw    $zero, 0x7f8($t3)
/* 037AF4 7F005104 8E0C0000 */  lw    $t4, ($s0)
/* 037AF8 7F005108 246B03A8 */  addiu $t3, $v1, 0x3a8
/* 037AFC 7F00510C 00001025 */  move  $v0, $zero
/* 037B00 7F005110 AD8007FC */  sw    $zero, 0x7fc($t4)
/* 037B04 7F005114 8E0D0000 */  lw    $t5, ($s0)
/* 037B08 7F005118 00606025 */  move  $t4, $v1
/* 037B0C 7F00511C ADA00800 */  sw    $zero, 0x800($t5)
/* 037B10 7F005120 8E190000 */  lw    $t9, ($s0)
/* 037B14 7F005124 AF200804 */  sw    $zero, 0x804($t9)
/* 037B18 7F005128 8E180000 */  lw    $t8, ($s0)
/* 037B1C 7F00512C AF052A3C */  sw    $a1, 0x2a3c($t8)
/* 037B20 7F005130 8E080000 */  lw    $t0, ($s0)
/* 037B24 7F005134 247803A8 */  addiu $t8, $v1, 0x3a8
/* 037B28 7F005138 AD052A40 */  sw    $a1, 0x2a40($t0)
/* 037B2C 7F00513C 8E0F0000 */  lw    $t7, ($s0)
/* 037B30 7F005140 00604025 */  move  $t0, $v1
/* 037B34 7F005144 3C038007 */  lui   $v1, %hi(g_playerPerm) # $v1, 0x8007
/* 037B38 7F005148 ADE02A48 */  sw    $zero, 0x2a48($t7)
/* 037B3C 7F00514C 8E0E0000 */  lw    $t6, ($s0)
/* 037B40 7F005150 24638BC4 */  addiu $v1, %lo(g_playerPerm) # addiu $v1, $v1, -0x743c
/* 037B44 7F005154 ADC02A4C */  sw    $zero, 0x2a4c($t6)
/* 037B48 7F005158 8E090000 */  lw    $t1, ($s0)
.L7F00515C:
/* 037B4C 7F00515C 8D810000 */  lw    $at, ($t4)
/* 037B50 7F005160 258C000C */  addiu $t4, $t4, 0xc
/* 037B54 7F005164 2529000C */  addiu $t1, $t1, 0xc
/* 037B58 7F005168 AD21085C */  sw    $at, 0x85c($t1)
/* 037B5C 7F00516C 8D81FFF8 */  lw    $at, -8($t4)
/* 037B60 7F005170 AD210860 */  sw    $at, 0x860($t1)
/* 037B64 7F005174 8D81FFFC */  lw    $at, -4($t4)
/* 037B68 7F005178 158BFFF8 */  bne   $t4, $t3, .L7F00515C
/* 037B6C 7F00517C AD210864 */   sw    $at, 0x864($t1)
/* 037B70 7F005180 8E0D0000 */  lw    $t5, ($s0)
.L7F005184:
/* 037B74 7F005184 8D010000 */  lw    $at, ($t0)
/* 037B78 7F005188 2508000C */  addiu $t0, $t0, 0xc
/* 037B7C 7F00518C 25AD000C */  addiu $t5, $t5, 0xc
/* 037B80 7F005190 ADA10C04 */  sw    $at, 0xc04($t5)
/* 037B84 7F005194 8D01FFF8 */  lw    $at, -8($t0)
/* 037B88 7F005198 ADA10C08 */  sw    $at, 0xc08($t5)
/* 037B8C 7F00519C 8D01FFFC */  lw    $at, -4($t0)
/* 037B90 7F0051A0 1518FFF8 */  bne   $t0, $t8, .L7F005184
/* 037B94 7F0051A4 ADA10C0C */   sw    $at, 0xc0c($t5)
.L7F0051A8:
/* 037B98 7F0051A8 8E0F0000 */  lw    $t7, ($s0)
/* 037B9C 7F0051AC 01E27021 */  addu  $t6, $t7, $v0
/* 037BA0 7F0051B0 24420004 */  addiu $v0, $v0, 4
/* 037BA4 7F0051B4 28410078 */  slti  $at, $v0, 0x78
/* 037BA8 7F0051B8 1420FFFB */  bnez  $at, .L7F0051A8
/* 037BAC 7F0051BC ADC01128 */   sw    $zero, 0x1128($t6)
/* 037BB0 7F0051C0 8C6A0000 */  lw    $t2, ($v1)
/* 037BB4 7F0051C4 24040003 */  li    $a0, 3
/* 037BB8 7F0051C8 00041080 */  sll   $v0, $a0, 2
/* 037BBC 7F0051CC AD400000 */  sw    $zero, ($t2)
/* 037BC0 7F0051D0 8C6B0000 */  lw    $t3, ($v1)
/* 037BC4 7F0051D4 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 037BC8 7F0051D8 44811000 */  mtc1  $at, $f2
/* 037BCC 7F0051DC AD600004 */  sw    $zero, 4($t3)
/* 037BD0 7F0051E0 8C6C0000 */  lw    $t4, ($v1)
/* 037BD4 7F0051E4 3C018004 */  lui   $at, %hi(D_8004F0E0) # $at, 0x8004
/* 037BD8 7F0051E8 44800000 */  mtc1  $zero, $f0
/* 037BDC 7F0051EC AD800008 */  sw    $zero, 8($t4)
/* 037BE0 7F0051F0 8C690000 */  lw    $t1, ($v1)
/* 037BE4 7F0051F4 00002025 */  move  $a0, $zero
/* 037BE8 7F0051F8 0122C821 */  addu  $t9, $t1, $v0
/* 037BEC 7F0051FC AF200000 */  sw    $zero, ($t9)
/* 037BF0 7F005200 8C780000 */  lw    $t8, ($v1)
/* 037BF4 7F005204 03024021 */  addu  $t0, $t8, $v0
/* 037BF8 7F005208 AD000004 */  sw    $zero, 4($t0)
/* 037BFC 7F00520C 8C6D0000 */  lw    $t5, ($v1)
/* 037C00 7F005210 01A27821 */  addu  $t7, $t5, $v0
/* 037C04 7F005214 ADE00008 */  sw    $zero, 8($t7)
/* 037C08 7F005218 8C6E0000 */  lw    $t6, ($v1)
/* 037C0C 7F00521C 01C25021 */  addu  $t2, $t6, $v0
/* 037C10 7F005220 AD40000C */  sw    $zero, 0xc($t2)
/* 037C14 7F005224 8C6B0000 */  lw    $t3, ($v1)
/* 037C18 7F005228 C42C7530 */  lwc1  $f12, %lo(D_8004F0E0)($at)
/* 037C1C 7F00522C 240200FF */  li    $v0, 255
/* 037C20 7F005230 AD60006C */  sw    $zero, 0x6c($t3)
/* 037C24 7F005234 8C6C0000 */  lw    $t4, ($v1)
/* 037C28 7F005238 3C018004 */  lui   $at, %hi(fl_neg_pi) # $at, 0x8004
/* 037C2C 7F00523C AD80001C */  sw    $zero, 0x1c($t4)
/* 037C30 7F005240 8C690000 */  lw    $t1, ($v1)
/* 037C34 7F005244 AD200020 */  sw    $zero, 0x20($t1)
/* 037C38 7F005248 8E190000 */  lw    $t9, ($s0)
/* 037C3C 7F00524C AF2029D0 */  sw    $zero, 0x29d0($t9)
/* 037C40 7F005250 8E180000 */  lw    $t8, ($s0)
/* 037C44 7F005254 AF0029D4 */  sw    $zero, 0x29d4($t8)
/* 037C48 7F005258 8E080000 */  lw    $t0, ($s0)
/* 037C4C 7F00525C E5020FB8 */  swc1  $f2, 0xfb8($t0)
/* 037C50 7F005260 8E0D0000 */  lw    $t5, ($s0)
/* 037C54 7F005264 E5A20FBC */  swc1  $f2, 0xfbc($t5)
/* 037C58 7F005268 8E0F0000 */  lw    $t7, ($s0)
/* 037C5C 7F00526C 240D0001 */  li    $t5, 1
/* 037C60 7F005270 ADE00FC0 */  sw    $zero, 0xfc0($t7)
/* 037C64 7F005274 8E0E0000 */  lw    $t6, ($s0)
/* 037C68 7F005278 ADC00FC4 */  sw    $zero, 0xfc4($t6)
/* 037C6C 7F00527C 8E0A0000 */  lw    $t2, ($s0)
/* 037C70 7F005280 AD400FC8 */  sw    $zero, 0xfc8($t2)
/* 037C74 7F005284 8E0B0000 */  lw    $t3, ($s0)
/* 037C78 7F005288 AD600FCC */  sw    $zero, 0xfcc($t3)
/* 037C7C 7F00528C 8E0C0000 */  lw    $t4, ($s0)
/* 037C80 7F005290 AD800FD0 */  sw    $zero, 0xfd0($t4)
/* 037C84 7F005294 8E090000 */  lw    $t1, ($s0)
/* 037C88 7F005298 A1220FD4 */  sb    $v0, 0xfd4($t1)
/* 037C8C 7F00529C 8E190000 */  lw    $t9, ($s0)
/* 037C90 7F0052A0 A3220FD5 */  sb    $v0, 0xfd5($t9)
/* 037C94 7F0052A4 8E180000 */  lw    $t8, ($s0)
/* 037C98 7F0052A8 A3020FD6 */  sb    $v0, 0xfd6($t8)
/* 037C9C 7F0052AC 8E080000 */  lw    $t0, ($s0)
/* 037CA0 7F0052B0 A1000FD7 */  sb    $zero, 0xfd7($t0)
/* 037CA4 7F0052B4 8E0F0000 */  lw    $t7, ($s0)
/* 037CA8 7F0052B8 ADED0FD8 */  sw    $t5, 0xfd8($t7)
/* 037CAC 7F0052BC 8E0E0000 */  lw    $t6, ($s0)
/* 037CB0 7F0052C0 ADC00FDC */  sw    $zero, 0xfdc($t6)
/* 037CB4 7F0052C4 8E0A0000 */  lw    $t2, ($s0)
/* 037CB8 7F0052C8 E5400FE0 */  swc1  $f0, 0xfe0($t2)
/* 037CBC 7F0052CC 8E0B0000 */  lw    $t3, ($s0)
/* 037CC0 7F0052D0 E5600FE4 */  swc1  $f0, 0xfe4($t3)
/* 037CC4 7F0052D4 8E0C0000 */  lw    $t4, ($s0)
/* 037CC8 7F0052D8 E5800FE8 */  swc1  $f0, 0xfe8($t4)
/* 037CCC 7F0052DC 8E090000 */  lw    $t1, ($s0)
/* 037CD0 7F0052E0 E5200FEC */  swc1  $f0, 0xfec($t1)
/* 037CD4 7F0052E4 8E190000 */  lw    $t9, ($s0)
/* 037CD8 7F0052E8 E72C0FF0 */  swc1  $f12, 0xff0($t9)
/* 037CDC 7F0052EC 8E180000 */  lw    $t8, ($s0)
/* 037CE0 7F0052F0 E7000FF4 */  swc1  $f0, 0xff4($t8)
/* 037CE4 7F0052F4 8E080000 */  lw    $t0, ($s0)
/* 037CE8 7F0052F8 E5000FF8 */  swc1  $f0, 0xff8($t0)
/* 037CEC 7F0052FC 8E0D0000 */  lw    $t5, ($s0)
/* 037CF0 7F005300 E5A00FFC */  swc1  $f0, 0xffc($t5)
/* 037CF4 7F005304 8E0F0000 */  lw    $t7, ($s0)
/* 037CF8 7F005308 E5E01000 */  swc1  $f0, 0x1000($t7)
/* 037CFC 7F00530C 8E0E0000 */  lw    $t6, ($s0)
/* 037D00 7F005310 E5CC1004 */  swc1  $f12, 0x1004($t6)
/* 037D04 7F005314 8E0A0000 */  lw    $t2, ($s0)
/* 037D08 7F005318 E5401008 */  swc1  $f0, 0x1008($t2)
/* 037D0C 7F00531C 8E0B0000 */  lw    $t3, ($s0)
/* 037D10 7F005320 C4247534 */  lwc1  $f4, %lo(fl_neg_pi)($at)
/* 037D14 7F005324 E564100C */  swc1  $f4, 0x100c($t3)
/* 037D18 7F005328 8E0C0000 */  lw    $t4, ($s0)
/* 037D1C 7F00532C E5801010 */  swc1  $f0, 0x1010($t4)
/* 037D20 7F005330 8E090000 */  lw    $t1, ($s0)
/* 037D24 7F005334 AD201058 */  sw    $zero, 0x1058($t1)
/* 037D28 7F005338 8E190000 */  lw    $t9, ($s0)
/* 037D2C 7F00533C AF251268 */  sw    $a1, 0x1268($t9)
/* 037D30 7F005340 8E180000 */  lw    $t8, ($s0)
/* 037D34 7F005344 E7001064 */  swc1  $f0, 0x1064($t8)
/* 037D38 7F005348 8E080000 */  lw    $t0, ($s0)
/* 037D3C 7F00534C E5001068 */  swc1  $f0, 0x1068($t0)
/* 037D40 7F005350 8E0D0000 */  lw    $t5, ($s0)
/* 037D44 7F005354 E5A0106C */  swc1  $f0, 0x106c($t5)
/* 037D48 7F005358 8E0F0000 */  lw    $t7, ($s0)
/* 037D4C 7F00535C ADE01070 */  sw    $zero, 0x1070($t7)
/* 037D50 7F005360 8E0E0000 */  lw    $t6, ($s0)
/* 037D54 7F005364 E5C01074 */  swc1  $f0, 0x1074($t6)
/* 037D58 7F005368 8E0A0000 */  lw    $t2, ($s0)
/* 037D5C 7F00536C 0FC1738C */  jal   bgunCalculateBlend
/* 037D60 7F005370 E5401078 */   swc1  $f0, 0x1078($t2)
/* 037D64 7F005374 0FC1738C */  jal   bgunCalculateBlend
/* 037D68 7F005378 00002025 */   move  $a0, $zero
/* 037D6C 7F00537C 0FC1738C */  jal   bgunCalculateBlend
/* 037D70 7F005380 00002025 */   move  $a0, $zero
/* 037D74 7F005384 0FC1738C */  jal   bgunCalculateBlend
/* 037D78 7F005388 24040001 */   li    $a0, 1
/* 037D7C 7F00538C 0FC1738C */  jal   bgunCalculateBlend
/* 037D80 7F005390 24040001 */   li    $a0, 1
/* 037D84 7F005394 0FC1738C */  jal   bgunCalculateBlend
/* 037D88 7F005398 24040001 */   li    $a0, 1
/* 037D8C 7F00539C 8E0B0000 */  lw    $t3, ($s0)
/* 037D90 7F0053A0 240C0002 */  li    $t4, 2
/* 037D94 7F0053A4 3C018003 */  lui   $at, %hi(sniperrifle_stats+52) # $at, 0x8003
/* 037D98 7F0053A8 AD60105C */  sw    $zero, 0x105c($t3)
/* 037D9C 7F0053AC 8E090000 */  lw    $t1, ($s0)
/* 037DA0 7F0053B0 AD2C1120 */  sw    $t4, 0x1120($t1)
/* 037DA4 7F0053B4 8E190000 */  lw    $t9, ($s0)
/* 037DA8 7F0053B8 C426E188 */  lwc1  $f6, %lo(sniperrifle_stats+52)($at)
/* 037DAC 7F0053BC 3C018003 */  lui   $at, %hi(camera_stats+52) # $at, 0x8003
/* 037DB0 7F0053C0 E726107C */  swc1  $f6, 0x107c($t9)
/* 037DB4 7F0053C4 8E180000 */  lw    $t8, ($s0)
/* 037DB8 7F0053C8 C428EC08 */  lwc1  $f8, %lo(camera_stats+52)($at)
/* 037DBC 7F0053CC E7081080 */  swc1  $f8, 0x1080($t8)
/* 037DC0 7F0053D0 8FBF001C */  lw    $ra, 0x1c($sp)
/* 037DC4 7F0053D4 8FB00018 */  lw    $s0, 0x18($sp)
/* 037DC8 7F0053D8 27BD03D0 */  addiu $sp, $sp, 0x3d0
/* 037DCC 7F0053DC 03E00008 */  jr    $ra
/* 037DD0 7F0053E0 00000000 */   nop   
)
#endif
#endif

