#include <ultra64.h>
#include "player.h"
#include "bg.h"
#include "unk_0BC530.h"

#ifdef VERSION_EU
#define AMT300 100
#else
#define AMT300 300 
#endif

// bss
/**
 * EU .bss 8007DC90
*/
u8 dword_CODE_bss_80083320[AMT300];

s32 dword_CODE_bss_80083450[AMT300];
s32 dword_CODE_bss_80083900[AMT300];
Mtx mtx_array_bss_80083DB0[AMT300];


void sub_GAME_7F0BC530(void) 
{
    int i;
      
    for (i=0; i<getPlayerCount(); i++)
    {
        g_playerPointers[i]->field_108C = -1;
    }

    for (i=0; i<AMT300; i++)
    {
      dword_CODE_bss_80083450[i] = -1;
      dword_CODE_bss_80083320[i] = 2;
      
      dword_CODE_bss_80083900[i] = -1;
      
      
    }

    for (i=0; i<getMaxNumRooms(); ++i)
    {
        array_room_info[i].field_36 = -1;
    }
}


void sub_GAME_7F0BC624(s32 param_1) {
  g_CurrentPlayer->field_108C = param_1;
}


void sub_GAME_7F0BC634(int param_1,int param_2)
{
    array_room_info[param_2].field_36 = param_1;
    dword_CODE_bss_80083450[param_1] = param_2;
}


void sub_GAME_7F0BC660(int param_1,int param_2)
{
    array_room_info[param_2].field_36 = -1;
    dword_CODE_bss_80083450[param_1] = -1;
}


void sub_GAME_7F0BC690(int index)
{
    if (dword_CODE_bss_80083450[index] != -1) {
        sub_GAME_7F0BC660(index,dword_CODE_bss_80083450[index]);
    }
    dword_CODE_bss_80083320[index] = 2;
    dword_CODE_bss_80083900[index] = -1;
}


s32 sub_GAME_7F0BC6F0(void)
{
    s32 i;

    for (i = 0; i<AMT300; i++)
    {
        if (((s32) dword_CODE_bss_80083320[i] >= 2) && (dword_CODE_bss_80083900[i] == -1))
        {
            return i;
        }
    }
    return 0;
}



#ifdef NONMATCHING
void sub_GAME_7F0BC7D4(void)
{
    s32 i;

    for(i = 0; i<AMT300; ++i)
    {
        if (dword_CODE_bss_80083900[i] > -1)
        {
            //needed to get close, still wrong temp usage, starts with t8 instead of t7
            dword_CODE_bss_80083320[i] = dword_CODE_bss_80083320[i];
            if ((dword_CODE_bss_80083320[i]+1 & 0xFF) > 1)
            {
                sub_GAME_7F0BC690(i);
            }
            
        } 
    }
}
#else

#if defined(LEFTOVERDEBUG)
GLOBAL_ASM(
.text
glabel sub_GAME_7F0BC7D4
/* 0F1304 7F0BC7D4 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 0F1308 7F0BC7D8 AFB2001C */  sw    $s2, 0x1c($sp)
/* 0F130C 7F0BC7DC AFB10018 */  sw    $s1, 0x18($sp)
/* 0F1310 7F0BC7E0 AFB30020 */  sw    $s3, 0x20($sp)
/* 0F1314 7F0BC7E4 AFB00014 */  sw    $s0, 0x14($sp)
/* 0F1318 7F0BC7E8 3C118008 */  lui   $s1, %hi(dword_CODE_bss_80083900)
/* 0F131C 7F0BC7EC 3C128008 */  lui   $s2, %hi(dword_CODE_bss_80083320)
/* 0F1320 7F0BC7F0 AFBF0024 */  sw    $ra, 0x24($sp)
/* 0F1324 7F0BC7F4 26523320 */  addiu $s2, %lo(dword_CODE_bss_80083320) # addiu $s2, $s2, 0x3320
/* 0F1328 7F0BC7F8 26313900 */  addiu $s1, %lo(dword_CODE_bss_80083900) # addiu $s1, $s1, 0x3900
/* 0F132C 7F0BC7FC 00008025 */  move  $s0, $zero
/* 0F1330 7F0BC800 2413012C */  li    $s3, 300
.L7F0BC804:
/* 0F1334 7F0BC804 8E2E0000 */  lw    $t6, ($s1)
/* 0F1338 7F0BC808 02501021 */  addu  $v0, $s2, $s0
/* 0F133C 7F0BC80C 05C2000A */  bltzl $t6, .L7F0BC838
/* 0F1340 7F0BC810 26100001 */   addiu $s0, $s0, 1
/* 0F1344 7F0BC814 904F0000 */  lbu   $t7, ($v0)
/* 0F1348 7F0BC818 25F80001 */  addiu $t8, $t7, 1
/* 0F134C 7F0BC81C 331900FF */  andi  $t9, $t8, 0xff
/* 0F1350 7F0BC820 2B210002 */  slti  $at, $t9, 2
/* 0F1354 7F0BC824 14200003 */  bnez  $at, .L7F0BC834
/* 0F1358 7F0BC828 A0580000 */   sb    $t8, ($v0)
/* 0F135C 7F0BC82C 0FC2F1A4 */  jal   sub_GAME_7F0BC690
/* 0F1360 7F0BC830 02002025 */   move  $a0, $s0
.L7F0BC834:
/* 0F1364 7F0BC834 26100001 */  addiu $s0, $s0, 1
.L7F0BC838:
/* 0F1368 7F0BC838 1613FFF2 */  bne   $s0, $s3, .L7F0BC804
/* 0F136C 7F0BC83C 26310004 */   addiu $s1, $s1, 4
/* 0F1370 7F0BC840 8FBF0024 */  lw    $ra, 0x24($sp)
/* 0F1374 7F0BC844 8FB00014 */  lw    $s0, 0x14($sp)
/* 0F1378 7F0BC848 8FB10018 */  lw    $s1, 0x18($sp)
/* 0F137C 7F0BC84C 8FB2001C */  lw    $s2, 0x1c($sp)
/* 0F1380 7F0BC850 8FB30020 */  lw    $s3, 0x20($sp)
/* 0F1384 7F0BC854 03E00008 */  jr    $ra
/* 0F1388 7F0BC858 27BD0028 */   addiu $sp, $sp, 0x28
)
#endif

#if !defined(LEFTOVERDEBUG)
GLOBAL_ASM(
.text
glabel sub_GAME_7F0BC7D4
/* 0EE5C4 7F0BBBD4 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 0EE5C8 7F0BBBD8 AFB2001C */  sw    $s2, 0x1c($sp)
/* 0EE5CC 7F0BBBDC AFB10018 */  sw    $s1, 0x18($sp)
/* 0EE5D0 7F0BBBE0 AFB30020 */  sw    $s3, 0x20($sp)
/* 0EE5D4 7F0BBBE4 AFB00014 */  sw    $s0, 0x14($sp)
/* 0EE5D8 7F0BBBE8 3C118007 */  lui   $s1, %hi(dword_CODE_bss_80083900) # $s1, 0x8007
/* 0EE5DC 7F0BBBEC 3C128007 */  lui   $s2, %hi(dword_CODE_bss_80083320) # $s2, 0x8007
/* 0EE5E0 7F0BBBF0 AFBF0024 */  sw    $ra, 0x24($sp)
/* 0EE5E4 7F0BBBF4 2652DC90 */  addiu $s2, %lo(dword_CODE_bss_80083320) # addiu $s2, $s2, -0x2370
/* 0EE5E8 7F0BBBF8 2631DE88 */  addiu $s1, %lo(dword_CODE_bss_80083900) # addiu $s1, $s1, -0x2178
/* 0EE5EC 7F0BBBFC 00008025 */  move  $s0, $zero
/* 0EE5F0 7F0BBC00 24130064 */  li    $s3, 100
.L7F0BBC04:
/* 0EE5F4 7F0BBC04 8E2E0000 */  lw    $t6, ($s1)
/* 0EE5F8 7F0BBC08 02501021 */  addu  $v0, $s2, $s0
/* 0EE5FC 7F0BBC0C 05C2000A */  bltzl $t6, .L7F0BBC38
/* 0EE600 7F0BBC10 26100001 */   addiu $s0, $s0, 1
/* 0EE604 7F0BBC14 904F0000 */  lbu   $t7, ($v0)
/* 0EE608 7F0BBC18 25F80001 */  addiu $t8, $t7, 1
/* 0EE60C 7F0BBC1C 331900FF */  andi  $t9, $t8, 0xff
/* 0EE610 7F0BBC20 2B210002 */  slti  $at, $t9, 2
/* 0EE614 7F0BBC24 14200003 */  bnez  $at, .L7F0BBC34
/* 0EE618 7F0BBC28 A0580000 */   sb    $t8, ($v0)
/* 0EE61C 7F0BBC2C 0FC2EEA4 */  jal   sub_GAME_7F0BC690
/* 0EE620 7F0BBC30 02002025 */   move  $a0, $s0
.L7F0BBC34:
/* 0EE624 7F0BBC34 26100001 */  addiu $s0, $s0, 1
.L7F0BBC38:
/* 0EE628 7F0BBC38 1613FFF2 */  bne   $s0, $s3, .L7F0BBC04
/* 0EE62C 7F0BBC3C 26310004 */   addiu $s1, $s1, 4
/* 0EE630 7F0BBC40 8FBF0024 */  lw    $ra, 0x24($sp)
/* 0EE634 7F0BBC44 8FB00014 */  lw    $s0, 0x14($sp)
/* 0EE638 7F0BBC48 8FB10018 */  lw    $s1, 0x18($sp)
/* 0EE63C 7F0BBC4C 8FB2001C */  lw    $s2, 0x1c($sp)
/* 0EE640 7F0BBC50 8FB30020 */  lw    $s3, 0x20($sp)
/* 0EE644 7F0BBC54 03E00008 */  jr    $ra
/* 0EE648 7F0BBC58 27BD0028 */   addiu $sp, $sp, 0x28
)
#endif
#endif





#ifdef NONMATCHING
s32 sub_GAME_7F0BC85C(s32 index)

{
  s32 iVar2;
  bg_room_data *room;
  float mtx [4] [4];
  
  iVar2 = array_room_info[index].field_36;
  if ((iVar2 == -1) || (g_CurrentPlayer->field_108C != dword_CODE_bss_80083900[iVar2])) {
    if (iVar2 != -1) {
      sub_GAME_7F0BC660(iVar2,index);
    }
    iVar2 = sub_GAME_7F0BC6F0();
    sub_GAME_7F0BC634(iVar2,index);
    dword_CODE_bss_80083320[iVar2] = 0;
    dword_CODE_bss_80083900[iVar2] = g_CurrentPlayer->field_108C;
    matrix_4x4_set_identity(mtx);
    mtx[0][0] = room_data_float2;
    mtx[1][1] = room_data_float2;
    mtx[2][2] = room_data_float2;
    room = &ptr_bgdata_room_fileposition_list[index];
    mtx[3][0] = (room->pos).x * room_data_float2 - g_CurrentPlayer->current_model_pos.f[0];
    mtx[3][1] = (room->pos).y * room_data_float2 - g_CurrentPlayer->current_model_pos.f[1];
    mtx[3][2] = (room->pos).z * room_data_float2 - g_CurrentPlayer->current_model_pos.f[2];
    matrix_4x4_f32_to_s32(mtx,mtx_array_bss_80083DB0[iVar2]);
  }
  else {
    dword_CODE_bss_80083320[iVar2] = 0;
  }
  return iVar2;
}
#else

#if defined(LEFTOVERDEBUG)
GLOBAL_ASM(
.text
glabel sub_GAME_7F0BC85C
/* 0F138C 7F0BC85C 27BDFF90 */  addiu $sp, $sp, -0x70
/* 0F1390 7F0BC860 00047880 */  sll   $t7, $a0, 2
/* 0F1394 7F0BC864 AFB00018 */  sw    $s0, 0x18($sp)
/* 0F1398 7F0BC868 01E47821 */  addu  $t7, $t7, $a0
/* 0F139C 7F0BC86C 000F7900 */  sll   $t7, $t7, 4
/* 0F13A0 7F0BC870 3C108004 */  lui   $s0, %hi(array_room_info + 0x10 +38)
/* 0F13A4 7F0BC874 020F8021 */  addu  $s0, $s0, $t7
/* 0F13A8 7F0BC878 8610144A */  lh    $s0, %lo(array_room_info + 0x10 +38)($s0)
/* 0F13AC 7F0BC87C 2402FFFF */  li    $v0, -1
/* 0F13B0 7F0BC880 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0F13B4 7F0BC884 1202000C */  beq   $s0, $v0, .L7F0BC8B8
/* 0F13B8 7F0BC888 AFA40070 */   sw    $a0, 0x70($sp)
/* 0F13BC 7F0BC88C 3C188008 */  lui   $t8, %hi(g_CurrentPlayer) 
/* 0F13C0 7F0BC890 8F18A0B0 */  lw    $t8, %lo(g_CurrentPlayer)($t8)
/* 0F13C4 7F0BC894 00104080 */  sll   $t0, $s0, 2
/* 0F13C8 7F0BC898 3C098008 */  lui   $t1, %hi(dword_CODE_bss_80083900)
/* 0F13CC 7F0BC89C 01284821 */  addu  $t1, $t1, $t0
/* 0F13D0 7F0BC8A0 8D293900 */  lw    $t1, %lo(dword_CODE_bss_80083900)($t1)
/* 0F13D4 7F0BC8A4 8F19108C */  lw    $t9, 0x108c($t8)
/* 0F13D8 7F0BC8A8 3C018008 */  lui   $at, %hi(dword_CODE_bss_80083320)
/* 0F13DC 7F0BC8AC 00300821 */  addu  $at, $at, $s0
/* 0F13E0 7F0BC8B0 1329000F */  beq   $t9, $t1, .L7F0BC8F0
/* 0F13E4 7F0BC8B4 00000000 */   nop   
.L7F0BC8B8:
/* 0F13E8 7F0BC8B8 12020003 */  beq   $s0, $v0, .L7F0BC8C8
/* 0F13EC 7F0BC8BC 02002025 */   move  $a0, $s0
/* 0F13F0 7F0BC8C0 0FC2F198 */  jal   sub_GAME_7F0BC660
/* 0F13F4 7F0BC8C4 8FA50070 */   lw    $a1, 0x70($sp)
.L7F0BC8C8:
/* 0F13F8 7F0BC8C8 0FC2F1BC */  jal   sub_GAME_7F0BC6F0
/* 0F13FC 7F0BC8CC 00000000 */   nop   
/* 0F1400 7F0BC8D0 00408025 */  move  $s0, $v0
/* 0F1404 7F0BC8D4 00402025 */  move  $a0, $v0
/* 0F1408 7F0BC8D8 0FC2F18D */  jal   sub_GAME_7F0BC634
/* 0F140C 7F0BC8DC 8FA50070 */   lw    $a1, 0x70($sp)
/* 0F1410 7F0BC8E0 3C018008 */  lui   $at, %hi(dword_CODE_bss_80083320)
/* 0F1414 7F0BC8E4 00300821 */  addu  $at, $at, $s0
/* 0F1418 7F0BC8E8 10000004 */  b     .L7F0BC8FC
/* 0F141C 7F0BC8EC A0203320 */   sb    $zero, %lo(dword_CODE_bss_80083320)($at)
.L7F0BC8F0:
/* 0F1420 7F0BC8F0 A0203320 */  sb    $zero, %lo(dword_CODE_bss_80083320)($at)
/* 0F1424 7F0BC8F4 1000002E */  b     .L7F0BC9B0
/* 0F1428 7F0BC8F8 02001025 */   move  $v0, $s0
.L7F0BC8FC:
/* 0F142C 7F0BC8FC 3C0A8008 */  lui   $t2, %hi(g_CurrentPlayer) 
/* 0F1430 7F0BC900 8D4AA0B0 */  lw    $t2, %lo(g_CurrentPlayer)($t2)
/* 0F1434 7F0BC904 00106080 */  sll   $t4, $s0, 2
/* 0F1438 7F0BC908 3C018008 */  lui   $at, %hi(dword_CODE_bss_80083900)
/* 0F143C 7F0BC90C 8D4B108C */  lw    $t3, 0x108c($t2)
/* 0F1440 7F0BC910 002C0821 */  addu  $at, $at, $t4
/* 0F1444 7F0BC914 27A4002C */  addiu $a0, $sp, 0x2c
/* 0F1448 7F0BC918 0FC15FF4 */  jal   matrix_4x4_set_identity
/* 0F144C 7F0BC91C AC2B3900 */   sw    $t3, %lo(dword_CODE_bss_80083900)($at)
/* 0F1450 7F0BC920 8FAE0070 */  lw    $t6, 0x70($sp)
/* 0F1454 7F0BC924 3C018004 */  lui   $at, %hi(room_data_float2)
/* 0F1458 7F0BC928 C42013F8 */  lwc1  $f0, %lo(room_data_float2)($at)
/* 0F145C 7F0BC92C 3C0D8008 */  lui   $t5, %hi(ptr_bgdata_room_fileposition_list) 
/* 0F1460 7F0BC930 8DADFF8C */  lw    $t5, %lo(ptr_bgdata_room_fileposition_list)($t5)
/* 0F1464 7F0BC934 000E7880 */  sll   $t7, $t6, 2
/* 0F1468 7F0BC938 01EE7823 */  subu  $t7, $t7, $t6
/* 0F146C 7F0BC93C 000F78C0 */  sll   $t7, $t7, 3
/* 0F1470 7F0BC940 E7A0002C */  swc1  $f0, 0x2c($sp)
/* 0F1474 7F0BC944 E7A00040 */  swc1  $f0, 0x40($sp)
/* 0F1478 7F0BC948 E7A00054 */  swc1  $f0, 0x54($sp)
/* 0F147C 7F0BC94C 01AF1821 */  addu  $v1, $t5, $t7
/* 0F1480 7F0BC950 C464000C */  lwc1  $f4, 0xc($v1)
/* 0F1484 7F0BC954 3C028008 */  lui   $v0, %hi(g_CurrentPlayer)
/* 0F1488 7F0BC958 8C42A0B0 */  lw    $v0, %lo(g_CurrentPlayer)($v0)
/* 0F148C 7F0BC95C 46002182 */  mul.s $f6, $f4, $f0
/* 0F1490 7F0BC960 3C088008 */  lui   $t0, %hi(mtx_array_bss_80083DB0) 
/* 0F1494 7F0BC964 C4480038 */  lwc1  $f8, 0x38($v0)
/* 0F1498 7F0BC968 25083DB0 */  addiu $t0, %lo(mtx_array_bss_80083DB0) # addiu $t0, $t0, 0x3db0
/* 0F149C 7F0BC96C 0010C180 */  sll   $t8, $s0, 6
/* 0F14A0 7F0BC970 03082821 */  addu  $a1, $t8, $t0
/* 0F14A4 7F0BC974 27A4002C */  addiu $a0, $sp, 0x2c
/* 0F14A8 7F0BC978 46083281 */  sub.s $f10, $f6, $f8
/* 0F14AC 7F0BC97C E7AA005C */  swc1  $f10, 0x5c($sp)
/* 0F14B0 7F0BC980 C4700010 */  lwc1  $f16, 0x10($v1)
/* 0F14B4 7F0BC984 C444003C */  lwc1  $f4, 0x3c($v0)
/* 0F14B8 7F0BC988 46008482 */  mul.s $f18, $f16, $f0
/* 0F14BC 7F0BC98C 46049181 */  sub.s $f6, $f18, $f4
/* 0F14C0 7F0BC990 E7A60060 */  swc1  $f6, 0x60($sp)
/* 0F14C4 7F0BC994 C4680014 */  lwc1  $f8, 0x14($v1)
/* 0F14C8 7F0BC998 C4500040 */  lwc1  $f16, 0x40($v0)
/* 0F14CC 7F0BC99C 46004282 */  mul.s $f10, $f8, $f0
/* 0F14D0 7F0BC9A0 46105481 */  sub.s $f18, $f10, $f16
/* 0F14D4 7F0BC9A4 0FC16327 */  jal   matrix_4x4_f32_to_s32
/* 0F14D8 7F0BC9A8 E7B20064 */   swc1  $f18, 0x64($sp)
/* 0F14DC 7F0BC9AC 02001025 */  move  $v0, $s0
.L7F0BC9B0:
/* 0F14E0 7F0BC9B0 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0F14E4 7F0BC9B4 8FB00018 */  lw    $s0, 0x18($sp)
/* 0F14E8 7F0BC9B8 27BD0070 */  addiu $sp, $sp, 0x70
/* 0F14EC 7F0BC9BC 03E00008 */  jr    $ra
/* 0F14F0 7F0BC9C0 00000000 */   nop   
)
#endif

#if !defined(LEFTOVERDEBUG)
GLOBAL_ASM(
.text
glabel sub_GAME_7F0BC85C
/* 0EE64C 7F0BBC5C 27BDFF90 */  addiu $sp, $sp, -0x70
/* 0EE650 7F0BBC60 00047880 */  sll   $t7, $a0, 2
/* 0EE654 7F0BBC64 AFB00018 */  sw    $s0, 0x18($sp)
/* 0EE658 7F0BBC68 01E47821 */  addu  $t7, $t7, $a0
/* 0EE65C 7F0BBC6C 000F7900 */  sll   $t7, $t7, 4
/* 0EE660 7F0BBC70 3C108004 */  lui   $s0, %hi(array_room_info + 0x10 +38)
/* 0EE664 7F0BBC74 020F8021 */  addu  $s0, $s0, $t7
/* 0EE668 7F0BBC78 8610AC9A */  lh    $s0, %lo(array_room_info + 0x10 +38)($s0)
/* 0EE66C 7F0BBC7C 2402FFFF */  li    $v0, -1
/* 0EE670 7F0BBC80 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0EE674 7F0BBC84 1202000C */  beq   $s0, $v0, .L7F0BBCB8
/* 0EE678 7F0BBC88 AFA40070 */   sw    $a0, 0x70($sp)
/* 0EE67C 7F0BBC8C 3C188007 */  lui   $t8, %hi(g_CurrentPlayer) # $t8, 0x8007
/* 0EE680 7F0BBC90 8F188BC0 */  lw    $t8, %lo(g_CurrentPlayer)($t8)
/* 0EE684 7F0BBC94 00104080 */  sll   $t0, $s0, 2
/* 0EE688 7F0BBC98 3C098007 */  lui   $t1, %hi(dword_CODE_bss_80083900)
/* 0EE68C 7F0BBC9C 01284821 */  addu  $t1, $t1, $t0
/* 0EE690 7F0BBCA0 8D29DE88 */  lw    $t1, %lo(dword_CODE_bss_80083900)($t1)
/* 0EE694 7F0BBCA4 8F191084 */  lw    $t9, 0x1084($t8)
/* 0EE698 7F0BBCA8 3C018007 */  lui   $at, %hi(dword_CODE_bss_80083320)
/* 0EE69C 7F0BBCAC 00300821 */  addu  $at, $at, $s0
/* 0EE6A0 7F0BBCB0 1329000F */  beq   $t9, $t1, .L7F0BBCF0
/* 0EE6A4 7F0BBCB4 00000000 */   nop   
.L7F0BBCB8:
/* 0EE6A8 7F0BBCB8 12020003 */  beq   $s0, $v0, .L7F0BBCC8
/* 0EE6AC 7F0BBCBC 02002025 */   move  $a0, $s0
/* 0EE6B0 7F0BBCC0 0FC2EE98 */  jal   sub_GAME_7F0BC660
/* 0EE6B4 7F0BBCC4 8FA50070 */   lw    $a1, 0x70($sp)
.L7F0BBCC8:
/* 0EE6B8 7F0BBCC8 0FC2EEBC */  jal   sub_GAME_7F0BC6F0
/* 0EE6BC 7F0BBCCC 00000000 */   nop   
/* 0EE6C0 7F0BBCD0 00408025 */  move  $s0, $v0
/* 0EE6C4 7F0BBCD4 00402025 */  move  $a0, $v0
/* 0EE6C8 7F0BBCD8 0FC2EE8D */  jal   sub_GAME_7F0BC634
/* 0EE6CC 7F0BBCDC 8FA50070 */   lw    $a1, 0x70($sp)
/* 0EE6D0 7F0BBCE0 3C018007 */  lui   $at, %hi(dword_CODE_bss_80083320)
/* 0EE6D4 7F0BBCE4 00300821 */  addu  $at, $at, $s0
/* 0EE6D8 7F0BBCE8 10000004 */  b     .L7F0BBCFC
/* 0EE6DC 7F0BBCEC A020DC90 */   sb    $zero, %lo(dword_CODE_bss_80083320)($at)
.L7F0BBCF0:
/* 0EE6E0 7F0BBCF0 A020DC90 */  sb    $zero, %lo(dword_CODE_bss_80083320)($at)
/* 0EE6E4 7F0BBCF4 1000002E */  b     .L7F0BBDB0
/* 0EE6E8 7F0BBCF8 02001025 */   move  $v0, $s0
.L7F0BBCFC:
/* 0EE6EC 7F0BBCFC 3C0A8007 */  lui   $t2, %hi(g_CurrentPlayer) # $t2, 0x8007
/* 0EE6F0 7F0BBD00 8D4A8BC0 */  lw    $t2, %lo(g_CurrentPlayer)($t2)
/* 0EE6F4 7F0BBD04 00106080 */  sll   $t4, $s0, 2
/* 0EE6F8 7F0BBD08 3C018007 */  lui   $at, %hi(dword_CODE_bss_80083900)
/* 0EE6FC 7F0BBD0C 8D4B1084 */  lw    $t3, 0x1084($t2)
/* 0EE700 7F0BBD10 002C0821 */  addu  $at, $at, $t4
/* 0EE704 7F0BBD14 27A4002C */  addiu $a0, $sp, 0x2c
/* 0EE708 7F0BBD18 0FC1611E */  jal   matrix_4x4_set_identity
/* 0EE70C 7F0BBD1C AC2BDE88 */   sw    $t3, %lo(dword_CODE_bss_80083900)($at)
/* 0EE710 7F0BBD20 8FAE0070 */  lw    $t6, 0x70($sp)
/* 0EE714 7F0BBD24 3C018004 */  lui   $at, %hi(room_data_float2) # $at, 0x8004
/* 0EE718 7F0BBD28 C420AC48 */  lwc1  $f0, %lo(room_data_float2)($at)
/* 0EE71C 7F0BBD2C 3C0D8007 */  lui   $t5, %hi(ptr_bgdata_room_fileposition_list) # $t5, 0x8007
/* 0EE720 7F0BBD30 8DADB3D4 */  lw    $t5, %lo(ptr_bgdata_room_fileposition_list)($t5)
/* 0EE724 7F0BBD34 000E7880 */  sll   $t7, $t6, 2
/* 0EE728 7F0BBD38 01EE7823 */  subu  $t7, $t7, $t6
/* 0EE72C 7F0BBD3C 000F78C0 */  sll   $t7, $t7, 3
/* 0EE730 7F0BBD40 E7A0002C */  swc1  $f0, 0x2c($sp)
/* 0EE734 7F0BBD44 E7A00040 */  swc1  $f0, 0x40($sp)
/* 0EE738 7F0BBD48 E7A00054 */  swc1  $f0, 0x54($sp)
/* 0EE73C 7F0BBD4C 01AF1821 */  addu  $v1, $t5, $t7
/* 0EE740 7F0BBD50 C464000C */  lwc1  $f4, 0xc($v1)
/* 0EE744 7F0BBD54 3C028007 */  lui   $v0, %hi(g_CurrentPlayer) # $v0, 0x8007
/* 0EE748 7F0BBD58 8C428BC0 */  lw    $v0, %lo(g_CurrentPlayer)($v0)
/* 0EE74C 7F0BBD5C 46002182 */  mul.s $f6, $f4, $f0
/* 0EE750 7F0BBD60 3C088007 */  lui   $t0, %hi(mtx_array_bss_80083DB0) # $t0, 0x8007
/* 0EE754 7F0BBD64 C4480038 */  lwc1  $f8, 0x38($v0)
/* 0EE758 7F0BBD68 2508E018 */  addiu $t0, %lo(mtx_array_bss_80083DB0) # addiu $t0, $t0, -0x1fe8
/* 0EE75C 7F0BBD6C 0010C180 */  sll   $t8, $s0, 6
/* 0EE760 7F0BBD70 03082821 */  addu  $a1, $t8, $t0
/* 0EE764 7F0BBD74 27A4002C */  addiu $a0, $sp, 0x2c
/* 0EE768 7F0BBD78 46083281 */  sub.s $f10, $f6, $f8
/* 0EE76C 7F0BBD7C E7AA005C */  swc1  $f10, 0x5c($sp)
/* 0EE770 7F0BBD80 C4700010 */  lwc1  $f16, 0x10($v1)
/* 0EE774 7F0BBD84 C444003C */  lwc1  $f4, 0x3c($v0)
/* 0EE778 7F0BBD88 46008482 */  mul.s $f18, $f16, $f0
/* 0EE77C 7F0BBD8C 46049181 */  sub.s $f6, $f18, $f4
/* 0EE780 7F0BBD90 E7A60060 */  swc1  $f6, 0x60($sp)
/* 0EE784 7F0BBD94 C4680014 */  lwc1  $f8, 0x14($v1)
/* 0EE788 7F0BBD98 C4500040 */  lwc1  $f16, 0x40($v0)
/* 0EE78C 7F0BBD9C 46004282 */  mul.s $f10, $f8, $f0
/* 0EE790 7F0BBDA0 46105481 */  sub.s $f18, $f10, $f16
/* 0EE794 7F0BBDA4 0FC16451 */  jal   matrix_4x4_f32_to_s32
/* 0EE798 7F0BBDA8 E7B20064 */   swc1  $f18, 0x64($sp)
/* 0EE79C 7F0BBDAC 02001025 */  move  $v0, $s0
.L7F0BBDB0:
/* 0EE7A0 7F0BBDB0 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0EE7A4 7F0BBDB4 8FB00018 */  lw    $s0, 0x18($sp)
/* 0EE7A8 7F0BBDB8 27BD0070 */  addiu $sp, $sp, 0x70
/* 0EE7AC 7F0BBDBC 03E00008 */  jr    $ra
/* 0EE7B0 7F0BBDC0 00000000 */   nop   
)
#endif
#endif





Gfx * sub_GAME_7F0BC9C4(Gfx *DL,int index)
{
    s32 i;
    
    i = sub_GAME_7F0BC85C(index);
    gSPMatrix(DL++, &mtx_array_bss_80083DB0[i], G_MTX_MODELVIEW|G_MTX_LOAD|G_MTX_NOPUSH);
    return DL;
}


s32 getRoomIndexPOS(s32 index)
{
    return &ptr_bgdata_room_fileposition_list[index].pos;
}


void sub_GAME_7F0BCA34(s32 index, coord3d *param_2)
{
    param_2->x = ptr_bgdata_room_fileposition_list[index].pos.x * room_data_float2;
    param_2->y = ptr_bgdata_room_fileposition_list[index].pos.y * room_data_float2;
    param_2->z = ptr_bgdata_room_fileposition_list[index].pos.z * room_data_float2;
}

