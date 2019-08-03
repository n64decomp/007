//FIXME i still need data/bss love.
#include "ultra64.h"
#include "sched.h"
#include "audi.h"

/**
 * @file audi.c
 * This file contains audio code.
 */

u32 D_800230F0 = 0;
u32 audFrameCt = 0;
u32 nextDMA = 0;
u32 curAcmdList = 0;
u64 D_80023100[]= {
 {0x000600001900},
 {0x0000000000A0},
 {0x2666FFFFD99A},
 {0x000000000000},
 {0x000000000000},
 {0x00A000000140},
 {0x2666FFFFD99A},
 {0x2B8400000000},
 {0x000000002500},
 {0x032000000A00},
 {0x4000FFFFC000},
 {0x11EB00000000},
 {0x000000003000},
 {0x0C80000015E0},
 {0x4000FFFFC000},
 {0x11EB00000000},
 {0x000000003500},
 {0x0D20000012C0},
 {0x2000FFFFE000},
 {0x000000000000},
 {0x000000004000},
 {0x000000001720},
 {0x32C8FFFFCD38},
 {0x00000000017C},
 {0x000A00004500},
};

s32 firstTime = 1;


/*bss needs fixing */
s32 dword_CODE_bss_8005E4B0[2];
s32 dword_CODE_bss_8005E4B8[2];
s32 dword_CODE_bss_8005E4C0;
s32 dword_CODE_bss_8005E4C4;
s32 dword_CODE_bss_8005E4C8;
s32 dword_CODE_bss_8005E4CC;
s32 dword_CODE_bss_8005E4D0[2];
s32 dword_CODE_bss_8005E4D8[2];
char dword_CODE_bss_8005E4E0[0x38];
//8005e518
char _am[0x284];






//8005e7a0
OSScClient audi_client[2];
//8005e7b0
s32 dmaState_initialized;
s32 dmaState_firstUsed;
s32 dmaState_firstFree[2];
char dmaBuffs[0x500];
s32 minFrameSize;
s32 frameSize;
s32 maxFrameSize;
s32 cmdLen;

OSIoMesg audDMAIOMesgBuf[0x40];
OSMesgQueue audDMAMessageQ;
char audDMAMessageBuf[0x108];


/**
 * 29D0	70001BD0
 */
#ifdef NONMATCHING
void amCreateAudioMgr(void *arg0)
{
    ? sp48;
    f32 temp_f0;
    s32 temp_ret;
    s32 temp_s2;
    u32 temp_s0;
    u32 temp_t0;
    u32 temp_t9;
    u32 temp_v1;
    void *temp_s0_2;
    void *temp_s1;
    void *temp_t0_2;
    void *temp_t7;
    u32 phi_v1;
    u32 phi_v1_2;
    void *phi_t7;
    void *phi_t0;
    void *phi_s0;
    s32 phi_s0_2;
    void *phi_s1;
    s32 phi_s2;
    void *phi_s0_3;

    arg0->unk10 = &__amDmaNew;
    temp_ret = osAiSetFrequency(0x5622);
    arg0->unk18 = temp_ret;
    temp_f0 = (f32) (temp_ret * 2) / 60.0f;
    temp_t9 = (u32) temp_f0;
    frameSize = temp_t9;
    temp_t0 = temp_t9 + 1;
    phi_v1 = temp_t9;
    if ((f32) temp_t9 < temp_f0)
    {
        frameSize = temp_t0;
        phi_v1 = temp_t0;
    }
    phi_v1_2 = phi_v1;
    if ((phi_v1 & 0xf) != 0)
    {
        temp_v1 = (phi_v1 & -0x10) + 0x10;
        frameSize = temp_v1;
        phi_v1_2 = temp_v1;
    }
    minFrameSize = (s32) (phi_v1_2 + -0x10);
    maxFrameSize = (s32) (phi_v1_2 + 0x35);
    if (arg0->unk1C == 6)
    {
        phi_t7 = &D_80023100;
        phi_t0 = &sp48;
loop_6:
        temp_t7 = phi_t7 + 0xc;
        temp_t0_2 = phi_t0 + 0xc;
        temp_t0_2->unk-C = (?32) *phi_t7;
        temp_t0_2->unk-8 = (?32) temp_t7->unk-8;
        temp_t0_2->unk-4 = (?32) temp_t7->unk-4;
        phi_t7 = temp_t7;
        phi_t0 = temp_t0_2;
        if (temp_t7 != (&D_80023100 + 0xc0))
        {
            goto loop_6;
        }
        temp_t0_2->unk0 = (?32) temp_t7->unk0;
        temp_t0_2->unk4 = (?32) temp_t7->unk4;
        arg0->unk20 = &sp48;
        alInit(&_am+0x238, arg0);
    }
    else
    {
        alInit(&_am+0x238, arg0);
    }
    phi_s0 = &_am;
loop_10:
    phi_s0->unk8 = alHeapDBAlloc(0, 0, arg0->unk14, 1, 0x60);
    temp_s0 = phi_s0 + 4;
    *phi_s0->unk8 = alHeapDBAlloc(0, 0, arg0->unk14, 1, (s32) (maxFrameSize * 4));
    phi_s0 = temp_s0;
    if (temp_s0 < &_am+0xC)
    {
        goto loop_10;
    }
    osCreateMesgQueue(&_am+0x200, &_am+0x218, 8);
    osCreateMesgQueue(&_am+0x1C8, &_am+0x1E0, 8);
    osCreateMesgQueue(&audDMAMessageQ, &audDMAMessageBuf, 0x40);
    dmaBuffs.unk4 = 0;
    dmaBuffs.unk0 = 0;
    phi_s0_2 = dmaBuffs + 0xe;
    phi_s1 = &dmaBuffs;
    phi_s2 = 0;
loop_12:
    alLink(phi_s0_2, phi_s1);
    temp_s2 = phi_s2 + 1;
    temp_s1 = phi_s1 + 0x14;
    temp_s1->unk-4 = alHeapDBAlloc(0, 0, arg0->unk14, 1, 0x200);
    phi_s0_2 = phi_s0_2 + 0x14;
    phi_s1 = temp_s1;
    phi_s2 = temp_s2;
    if (temp_s2 < 0x3f)
    {
        goto loop_12;
    }
    temp_s1->unk10 = alHeapDBAlloc(0, 0, arg0->unk14, 1, 0x200);
    phi_s0_3 = &_am;
loop_14:
    temp_s0_2 = phi_s0_3 + 4;
    temp_s0_2->unk-4 = alHeapDBAlloc(0, 0, arg0->unk14, 1, 0x5dc0);
    phi_s0_3 = temp_s0_2;
    if (temp_s0_2 != &_am+0x8)
    {
        goto loop_14;
    }
    osCreateThread(&_am+0x18, 4, &_amMain, 0, set_stack_entry(&sp_audi, 0x1000), 0x14);
}
#else
GLOBAL_ASM(
.text
glabel amCreateAudioMgr
/* 0027D0 70001BD0 27BDFEE8 */  addiu $sp, $sp, -0x118
/* 0027D4 70001BD4 AFB3002C */  sw    $s3, 0x2c($sp)
/* 0027D8 70001BD8 3C0E7000 */  lui   $t6, %hi(__amDmaNew) # $t6, 0x7000
/* 0027DC 70001BDC AFBF0034 */  sw    $ra, 0x34($sp)
/* 0027E0 70001BE0 AFB40030 */  sw    $s4, 0x30($sp)
/* 0027E4 70001BE4 AFB20028 */  sw    $s2, 0x28($sp)
/* 0027E8 70001BE8 AFB10024 */  sw    $s1, 0x24($sp)
/* 0027EC 70001BEC AFB00020 */  sw    $s0, 0x20($sp)
/* 0027F0 70001BF0 25CE25D8 */  addiu $t6, %lo(__amDmaNew) # addiu $t6, $t6, 0x25d8
/* 0027F4 70001BF4 00809825 */  move  $s3, $a0
/* 0027F8 70001BF8 AC8E0010 */  sw    $t6, 0x10($a0)
/* 0027FC 70001BFC 0C003A4C */  jal   osAiSetFrequency
/* 002800 70001C00 24045622 */   li    $a0, 22050
/* 002804 70001C04 00027840 */  sll   $t7, $v0, 1
/* 002808 70001C08 448F2000 */  mtc1  $t7, $f4
/* 00280C 70001C0C 3C014270 */  li    $at, 0x42700000 # 60.000000
/* 002810 70001C10 44814000 */  mtc1  $at, $f8
/* 002814 70001C14 468021A0 */  cvt.s.w $f6, $f4
/* 002818 70001C18 24190001 */  li    $t9, 1
/* 00281C 70001C1C 3C048006 */  lui   $a0, %hi(frameSize) # $a0, 0x8006
/* 002820 70001C20 3C148006 */  lui   $s4, %hi(maxFrameSize) # $s4, 0x8006
/* 002824 70001C24 2484ECC4 */  addiu $a0, %lo(frameSize) # addiu $a0, $a0, -0x133c
/* 002828 70001C28 AE620018 */  sw    $v0, 0x18($s3)
/* 00282C 70001C2C 46083003 */  div.s $f0, $f6, $f8
/* 002830 70001C30 2694ECC8 */  addiu $s4, %lo(maxFrameSize) # addiu $s4, $s4, -0x1338
/* 002834 70001C34 4458F800 */  cfc1  $t8, $31
/* 002838 70001C38 44D9F800 */  ctc1  $t9, $31
/* 00283C 70001C3C 00000000 */  nop   
/* 002840 70001C40 460002A4 */  cvt.w.s $f10, $f0
/* 002844 70001C44 4459F800 */  cfc1  $t9, $31
/* 002848 70001C48 00000000 */  nop   
/* 00284C 70001C4C 33390078 */  andi  $t9, $t9, 0x78
/* 002850 70001C50 13200012 */  beqz  $t9, .L70001C9C
/* 002854 70001C54 3C014F00 */   li    $at, 0x4F000000 # 2147483648.000000
/* 002858 70001C58 44815000 */  mtc1  $at, $f10
/* 00285C 70001C5C 24190001 */  li    $t9, 1
/* 002860 70001C60 460A0281 */  sub.s $f10, $f0, $f10
/* 002864 70001C64 44D9F800 */  ctc1  $t9, $31
/* 002868 70001C68 00000000 */  nop   
/* 00286C 70001C6C 460052A4 */  cvt.w.s $f10, $f10
/* 002870 70001C70 4459F800 */  cfc1  $t9, $31
/* 002874 70001C74 00000000 */  nop   
/* 002878 70001C78 33390078 */  andi  $t9, $t9, 0x78
/* 00287C 70001C7C 17200005 */  bnez  $t9, .L70001C94
/* 002880 70001C80 00000000 */   nop   
/* 002884 70001C84 44195000 */  mfc1  $t9, $f10
/* 002888 70001C88 3C018000 */  lui   $at, 0x8000
/* 00288C 70001C8C 10000007 */  b     .L70001CAC
/* 002890 70001C90 0321C825 */   or    $t9, $t9, $at
.L70001C94:
/* 002894 70001C94 10000005 */  b     .L70001CAC
/* 002898 70001C98 2419FFFF */   li    $t9, -1
.L70001C9C:
/* 00289C 70001C9C 44195000 */  mfc1  $t9, $f10
/* 0028A0 70001CA0 00000000 */  nop   
/* 0028A4 70001CA4 0720FFFB */  bltz  $t9, .L70001C94
/* 0028A8 70001CA8 00000000 */   nop   
.L70001CAC:
/* 0028AC 70001CAC 03201825 */  move  $v1, $t9
/* 0028B0 70001CB0 44D8F800 */  ctc1  $t8, $31
/* 0028B4 70001CB4 44838000 */  mtc1  $v1, $f16
/* 0028B8 70001CB8 AC990000 */  sw    $t9, ($a0)
/* 0028BC 70001CBC 07210005 */  bgez  $t9, .L70001CD4
/* 0028C0 70001CC0 468084A0 */   cvt.s.w $f18, $f16
/* 0028C4 70001CC4 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0028C8 70001CC8 44812000 */  mtc1  $at, $f4
/* 0028CC 70001CCC 00000000 */  nop   
/* 0028D0 70001CD0 46049480 */  add.s $f18, $f18, $f4
.L70001CD4:
/* 0028D4 70001CD4 4600903C */  c.lt.s $f18, $f0
/* 0028D8 70001CD8 00000000 */  nop   
/* 0028DC 70001CDC 45000003 */  bc1f  .L70001CEC
/* 0028E0 70001CE0 24680001 */   addiu $t0, $v1, 1
/* 0028E4 70001CE4 AC880000 */  sw    $t0, ($a0)
/* 0028E8 70001CE8 01001825 */  move  $v1, $t0
.L70001CEC:
/* 0028EC 70001CEC 3069000F */  andi  $t1, $v1, 0xf
/* 0028F0 70001CF0 11200004 */  beqz  $t1, .L70001D04
/* 0028F4 70001CF4 2401FFF0 */   li    $at, -16
/* 0028F8 70001CF8 00615024 */  and   $t2, $v1, $at
/* 0028FC 70001CFC 25430010 */  addiu $v1, $t2, 0x10
/* 002900 70001D00 AC830000 */  sw    $v1, ($a0)
.L70001D04:
/* 002904 70001D04 246CFFF0 */  addiu $t4, $v1, -0x10
/* 002908 70001D08 3C018006 */  lui   $at, %hi(minFrameSize) # $at, 0x8006
/* 00290C 70001D0C AC2CECC0 */  sw    $t4, %lo(minFrameSize)($at)
/* 002910 70001D10 246D0035 */  addiu $t5, $v1, 0x35
/* 002914 70001D14 AE8D0000 */  sw    $t5, ($s4)
/* 002918 70001D18 926E001C */  lbu   $t6, 0x1c($s3)
/* 00291C 70001D1C 24010006 */  li    $at, 6
/* 002920 70001D20 3C048006 */  lui   $a0, %hi(_am+0x238) # $a0, 0x8006
/* 002924 70001D24 15C1001A */  bne   $t6, $at, .L70001D90
/* 002928 70001D28 2484E750 */   addiu $a0, %lo(_am+0x238) # addiu $a0, $a0, -0x18b0
/* 00292C 70001D2C 3C0F8002 */  lui   $t7, %hi(D_80023100) # $t7, 0x8002
/* 002930 70001D30 27A20048 */  addiu $v0, $sp, 0x48
/* 002934 70001D34 25EF3100 */  addiu $t7, %lo(D_80023100) # addiu $t7, $t7, 0x3100
/* 002938 70001D38 25F900C0 */  addiu $t9, $t7, 0xc0
/* 00293C 70001D3C 00404025 */  move  $t0, $v0
.L70001D40:
/* 002940 70001D40 8DE10000 */  lw    $at, ($t7)
/* 002944 70001D44 25EF000C */  addiu $t7, $t7, 0xc
/* 002948 70001D48 2508000C */  addiu $t0, $t0, 0xc
/* 00294C 70001D4C AD01FFF4 */  sw    $at, -0xc($t0)
/* 002950 70001D50 8DE1FFF8 */  lw    $at, -8($t7)
/* 002954 70001D54 AD01FFF8 */  sw    $at, -8($t0)
/* 002958 70001D58 8DE1FFFC */  lw    $at, -4($t7)
/* 00295C 70001D5C 15F9FFF8 */  bne   $t7, $t9, .L70001D40
/* 002960 70001D60 AD01FFFC */   sw    $at, -4($t0)
/* 002964 70001D64 8DE10000 */  lw    $at, ($t7)
/* 002968 70001D68 3C048006 */  lui   $a0, %hi(_am+0x238) # $a0, 0x8006
/* 00296C 70001D6C 2484E750 */  addiu $a0, %lo(_am+0x238) # addiu $a0, $a0, -0x18b0
/* 002970 70001D70 AD010000 */  sw    $at, ($t0)
/* 002974 70001D74 8DF90004 */  lw    $t9, 4($t7)
/* 002978 70001D78 02602825 */  move  $a1, $s3
/* 00297C 70001D7C AD190004 */  sw    $t9, 4($t0)
/* 002980 70001D80 0C003AC7 */  jal   alInit
/* 002984 70001D84 AE620020 */   sw    $v0, 0x20($s3)
/* 002988 70001D88 10000003 */  b     .L70001D98
/* 00298C 70001D8C 00000000 */   nop   
.L70001D90:
/* 002990 70001D90 0C003AC7 */  jal   alInit
/* 002994 70001D94 02602825 */   move  $a1, $s3
.L70001D98:
/* 002998 70001D98 3C108006 */  lui   $s0, %hi(_am) # $s0, 0x8006
/* 00299C 70001D9C 3C118006 */  lui   $s1, %hi(_am+0xC) # $s1, 0x8006
/* 0029A0 70001DA0 2631E524 */  addiu $s1, %lo(_am+0xC) # addiu $s1, $s1, -0x1adc
/* 0029A4 70001DA4 2610E518 */  addiu $s0, %lo(_am) # addiu $s0, $s0, -0x1ae8
.L70001DA8:
/* 0029A8 70001DA8 8E660014 */  lw    $a2, 0x14($s3)
/* 0029AC 70001DAC 24090060 */  li    $t1, 96
/* 0029B0 70001DB0 AFA90010 */  sw    $t1, 0x10($sp)
/* 0029B4 70001DB4 00002025 */  move  $a0, $zero
/* 0029B8 70001DB8 00002825 */  move  $a1, $zero
/* 0029BC 70001DBC 0C003AD4 */  jal   alHeapDBAlloc
/* 0029C0 70001DC0 24070001 */   li    $a3, 1
/* 0029C4 70001DC4 8E8A0000 */  lw    $t2, ($s4)
/* 0029C8 70001DC8 AE020008 */  sw    $v0, 8($s0)
/* 0029CC 70001DCC 8E660014 */  lw    $a2, 0x14($s3)
/* 0029D0 70001DD0 000A5880 */  sll   $t3, $t2, 2
/* 0029D4 70001DD4 AFAB0010 */  sw    $t3, 0x10($sp)
/* 0029D8 70001DD8 00002025 */  move  $a0, $zero
/* 0029DC 70001DDC 00002825 */  move  $a1, $zero
/* 0029E0 70001DE0 0C003AD4 */  jal   alHeapDBAlloc
/* 0029E4 70001DE4 24070001 */   li    $a3, 1
/* 0029E8 70001DE8 8E0C0008 */  lw    $t4, 8($s0)
/* 0029EC 70001DEC 26100004 */  addiu $s0, $s0, 4
/* 0029F0 70001DF0 0211082B */  sltu  $at, $s0, $s1
/* 0029F4 70001DF4 1420FFEC */  bnez  $at, .L70001DA8
/* 0029F8 70001DF8 AD820000 */   sw    $v0, ($t4)
/* 0029FC 70001DFC 3C048006 */  lui   $a0, %hi(_am+0x200) # $a0, 0x8006
/* 002A00 70001E00 3C058006 */  lui   $a1, %hi(_am+0x218) # $a1, 0x8006
/* 002A04 70001E04 24A5E730 */  addiu $a1, %lo(_am+0x218) # addiu $a1, $a1, -0x18d0
/* 002A08 70001E08 2484E718 */  addiu $a0, %lo(_am+0x200) # addiu $a0, $a0, -0x18e8
/* 002A0C 70001E0C 0C0035B4 */  jal   osCreateMesgQueue
/* 002A10 70001E10 24060008 */   li    $a2, 8
/* 002A14 70001E14 3C048006 */  lui   $a0, %hi(_am+0x1C8) # $a0, 0x8006
/* 002A18 70001E18 3C058006 */  lui   $a1, %hi(_am+0x1E0) # $a1, 0x8006
/* 002A1C 70001E1C 24A5E6F8 */  addiu $a1, %lo(_am+0x1E0) # addiu $a1, $a1, -0x1908
/* 002A20 70001E20 2484E6E0 */  addiu $a0, %lo(_am+0x1C8) # addiu $a0, $a0, -0x1920
/* 002A24 70001E24 0C0035B4 */  jal   osCreateMesgQueue
/* 002A28 70001E28 24060008 */   li    $a2, 8
/* 002A2C 70001E2C 3C048006 */  lui   $a0, %hi(audDMAMessageQ) # $a0, 0x8006
/* 002A30 70001E30 3C058006 */  lui   $a1, %hi(audDMAMessageBuf) # $a1, 0x8006
/* 002A34 70001E34 24A5F2E8 */  addiu $a1, %lo(audDMAMessageBuf) # addiu $a1, $a1, -0xd18
/* 002A38 70001E38 2484F2D0 */  addiu $a0, %lo(audDMAMessageQ) # addiu $a0, $a0, -0xd30
/* 002A3C 70001E3C 0C0035B4 */  jal   osCreateMesgQueue
/* 002A40 70001E40 24060040 */   li    $a2, 64
/* 002A44 70001E44 3C028006 */  lui   $v0, %hi(dmaBuffs) # $v0, 0x8006
/* 002A48 70001E48 2442E7C0 */  addiu $v0, %lo(dmaBuffs) # addiu $v0, $v0, -0x1840
/* 002A4C 70001E4C 3C118006 */  lui   $s1, %hi(dmaBuffs) # $s1, 0x8006
/* 002A50 70001E50 3C108006 */  lui   $s0, %hi(dmaBuffs+20)
/* 002A54 70001E54 AC400004 */  sw    $zero, 4($v0)
/* 002A58 70001E58 AC400000 */  sw    $zero, ($v0)
/* 002A5C 70001E5C 2610E7D4 */  addiu $s0, $s0, %lo(dmaBuffs+20)
/* 002A60 70001E60 2631E7C0 */  addiu $s1, %lo(dmaBuffs) # addiu $s1, $s1, -0x1840
/* 002A64 70001E64 00009025 */  move  $s2, $zero
.L70001E68:
/* 002A68 70001E68 02002025 */  move  $a0, $s0
/* 002A6C 70001E6C 0C003AB0 */  jal   alLink
/* 002A70 70001E70 02202825 */   move  $a1, $s1
/* 002A74 70001E74 8E660014 */  lw    $a2, 0x14($s3)
/* 002A78 70001E78 240D0200 */  li    $t5, 512
/* 002A7C 70001E7C AFAD0010 */  sw    $t5, 0x10($sp)
/* 002A80 70001E80 00002025 */  move  $a0, $zero
/* 002A84 70001E84 00002825 */  move  $a1, $zero
/* 002A88 70001E88 0C003AD4 */  jal   alHeapDBAlloc
/* 002A8C 70001E8C 24070001 */   li    $a3, 1
/* 002A90 70001E90 26520001 */  addiu $s2, $s2, 1
/* 002A94 70001E94 2A41003F */  slti  $at, $s2, 0x3f
/* 002A98 70001E98 26310014 */  addiu $s1, $s1, 0x14
/* 002A9C 70001E9C 26100014 */  addiu $s0, $s0, 0x14
/* 002AA0 70001EA0 1420FFF1 */  bnez  $at, .L70001E68
/* 002AA4 70001EA4 AE22FFFC */   sw    $v0, -4($s1)
/* 002AA8 70001EA8 8E660014 */  lw    $a2, 0x14($s3)
/* 002AAC 70001EAC 240E0200 */  li    $t6, 512
/* 002AB0 70001EB0 AFAE0010 */  sw    $t6, 0x10($sp)
/* 002AB4 70001EB4 00002025 */  move  $a0, $zero
/* 002AB8 70001EB8 00002825 */  move  $a1, $zero
/* 002ABC 70001EBC 0C003AD4 */  jal   alHeapDBAlloc
/* 002AC0 70001EC0 24070001 */   li    $a3, 1
/* 002AC4 70001EC4 AE220010 */  sw    $v0, 0x10($s1)
/* 002AC8 70001EC8 3C118006 */  lui   $s1, %hi(_am+0x8) # $s1, 0x8006
/* 002ACC 70001ECC 3C108006 */  lui   $s0, %hi(_am) # $s0, 0x8006
/* 002AD0 70001ED0 2610E518 */  addiu $s0, %lo(_am) # addiu $s0, $s0, -0x1ae8
/* 002AD4 70001ED4 2631E520 */  addiu $s1, %lo(_am+0x8) # addiu $s1, $s1, -0x1ae0
.L70001ED8:
/* 002AD8 70001ED8 8E660014 */  lw    $a2, 0x14($s3)
/* 002ADC 70001EDC 24185DC0 */  li    $t8, 24000
/* 002AE0 70001EE0 AFB80010 */  sw    $t8, 0x10($sp)
/* 002AE4 70001EE4 00002025 */  move  $a0, $zero
/* 002AE8 70001EE8 00002825 */  move  $a1, $zero
/* 002AEC 70001EEC 0C003AD4 */  jal   alHeapDBAlloc
/* 002AF0 70001EF0 24070001 */   li    $a3, 1
/* 002AF4 70001EF4 26100004 */  addiu $s0, $s0, 4
/* 002AF8 70001EF8 1611FFF7 */  bne   $s0, $s1, .L70001ED8
/* 002AFC 70001EFC AE02FFFC */   sw    $v0, -4($s0)
/* 002B00 70001F00 3C04803B */  lui   $a0, %hi(sp_audi) # $a0, 0x803b
/* 002B04 70001F04 24843950 */  addiu $a0, %lo(sp_audi) # addiu $a0, $a0, 0x3950
/* 002B08 70001F08 0C0001BC */  jal   set_stack_entry
/* 002B0C 70001F0C 24051000 */   li    $a1, 4096
/* 002B10 70001F10 3C048006 */  lui   $a0, %hi(_am+0x18) # $a0, 0x8006
/* 002B14 70001F14 3C067000 */  lui   $a2, %hi(_amMain) # $a2, 0x7000
/* 002B18 70001F18 24190014 */  li    $t9, 20
/* 002B1C 70001F1C AFB90014 */  sw    $t9, 0x14($sp)
/* 002B20 70001F20 24C61F7C */  addiu $a2, %lo(_amMain) # addiu $a2, $a2, 0x1f7c
/* 002B24 70001F24 2484E530 */  addiu $a0, %lo(_am+0x18) # addiu $a0, $a0, -0x1ad0
/* 002B28 70001F28 24050004 */  li    $a1, 4
/* 002B2C 70001F2C 00003825 */  move  $a3, $zero
/* 002B30 70001F30 0C00350C */  jal   osCreateThread
/* 002B34 70001F34 AFA20010 */   sw    $v0, 0x10($sp)
/* 002B38 70001F38 8FBF0034 */  lw    $ra, 0x34($sp)
/* 002B3C 70001F3C 8FB00020 */  lw    $s0, 0x20($sp)
/* 002B40 70001F40 8FB10024 */  lw    $s1, 0x24($sp)
/* 002B44 70001F44 8FB20028 */  lw    $s2, 0x28($sp)
/* 002B48 70001F48 8FB3002C */  lw    $s3, 0x2c($sp)
/* 002B4C 70001F4C 8FB40030 */  lw    $s4, 0x30($sp)
/* 002B50 70001F50 03E00008 */  jr    $ra
/* 002B54 70001F54 27BD0118 */   addiu $sp, $sp, 0x118
)
#endif

/**
 * 2B58	70001F58
 * insert sound manager thread
 *	redirect to 7000D580: A0=8005E530
 */
#ifdef NONMATCHING
void startaudiThread(void) {
    osStartThread(&_am+0x18);
}
#else
GLOBAL_ASM(
glabel startaudiThread
/* 002B58 70001F58 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 002B5C 70001F5C AFBF0014 */  sw    $ra, 0x14($sp)
/* 002B60 70001F60 3C048006 */  lui   $a0, %hi(_am+0x18)
/* 002B64 70001F64 0C003560 */  jal   osStartThread
/* 002B68 70001F68 2484E530 */  addiu $a0, $a0, %lo(_am+0x18)
/* 002B6C 70001F6C 8FBF0014 */  lw    $ra, 0x14($sp)
/* 002B70 70001F70 27BD0018 */  addiu $sp, $sp, 0x18
/* 002B74 70001F74 03E00008 */  jr    $ra
/* 002B78 70001F78 00000000 */  nop   
)
#endif

/**
 * 2B7C	70001F7C
 */
#ifdef NONMATCHING
void _amMain(s32 arg0)
{
    void *sp64;
    ?32 sp60;
    u32 sp54;
    s32 sp50;
    u32 sp4C;
    s32 sp48;
    u32 sp44;
    u32 sp40;
    ? temp_ret;
    s32 temp_s1;
    ? temp_ret_2;
    u32 temp_t8;
    u32 temp_t9;
    ? temp_ret_3;
    u32 temp_t7;
    s32 phi_s1;
    s32 phi_s2;
    s32 phi_s2_2;

    sp64 = NULL;
    sp60 = 0;
    osScAddClient(&sc, &audi_client, &_am+0x1C8, 1);
    phi_s1 = 0;
    phi_s2_2 = 0;
loop_1:
    osRecvMesg(&_am+0x1C8, &sp64, 1);
    if (*sp64 != 1)
    {
        if (*sp64 != 5)
        {
            if (*sp64 != 0xa)
            {
                phi_s2 = phi_s2_2;
                phi_s1 = phi_s1;
            }
            else
            {
                phi_s2 = 1;
                phi_s1 = phi_s1;
            }
        }
        else
        {
            phi_s2 = 1;
            phi_s1 = phi_s1;
        }
    }
    else
    {
        temp_ret = osGetTime(*sp64);
        dword_CODE_bss_8005E4D8 = temp_ret;
        dword_CODE_bss_8005E4D8.unk4 = temp_ret;
        video_related_3(0x30000);
        _amHandleFrameMsg((0x80060000 + (((u32) audFrameCt % 3U) * 4))->unk-1AE0, sp60);
        temp_s1 = (phi_s1 + 1);
        video_related_3(0x60000);
        temp_ret_2 = osGetTime();
        dword_CODE_bss_8005E4E0 = temp_ret_2;
        temp_t8 = ((temp_ret_2 - dword_CODE_bss_8005E4D8) - (temp_ret_2 < (u32) dword_CODE_bss_8005E4D8.unk4));
        dword_CODE_bss_8005E4E0.unk4 = temp_ret_2;
        temp_t9 = (temp_ret_2 - dword_CODE_bss_8005E4D8.unk4);
        dword_CODE_bss_8005E4C0 = temp_t9;
        dword_CODE_bss_8005E4C0 = temp_t8;
        sp44 = temp_t9;
        sp40 = temp_t8;
        sp50 = temp_ret_2;
        sp54 = temp_ret_2;
        sp48 = (s32) dword_CODE_bss_8005E4D8;
        sp4C = (u32) dword_CODE_bss_8005E4D8.unk4;
        if ((temp_s1 % 0xf0) == 0)
        {
            temp_ret_3 = ull_div(dword_CODE_bss_8005E4D0, dword_CODE_bss_8005E4D0.unk4, 0, 0xf0);
            dword_CODE_bss_8005E4CC = temp_ret_3;
            dword_CODE_bss_8005E4CC = temp_ret_3;
            sp44 = (u32) (dword_CODE_bss_8005E4E0.unk4 - dword_CODE_bss_8005E4D8.unk4);
            dword_CODE_bss_8005E4B8.unk4 = 0U;
            dword_CODE_bss_8005E4B8 = 0U;
            dword_CODE_bss_8005E4D0.unk4 = 0;
            sp40 = (u32) ((dword_CODE_bss_8005E4E0 - dword_CODE_bss_8005E4D8) - ((u32) dword_CODE_bss_8005E4E0.unk4 < (u32) dword_CODE_bss_8005E4D8.unk4));
            dword_CODE_bss_8005E4D0 = 0;
        }
        else
        {
            temp_t7 = (dword_CODE_bss_8005E4D0.unk4 + sp54);
            dword_CODE_bss_8005E4D0.unk4 = (s32) (temp_t7 - sp4C);
            dword_CODE_bss_8005E4D0 = (s32) (((((temp_t7 < sp54) + dword_CODE_bss_8005E4D0) + sp50) - sp48) - (temp_t7 < sp4C));
        }
        if (sp40 >= (u32) dword_CODE_bss_8005E4B8)
        {
            if (((u32) dword_CODE_bss_8005E4B8 < sp40) || ((u32) dword_CODE_bss_8005E4B8.unk4 < sp44))
            {
                dword_CODE_bss_8005E4B8 = sp40;
                dword_CODE_bss_8005E4B8.unk4 = sp44;
            }
            else
            {

            }
        }
        osRecvMesg(&_am+0x200, &sp60, 1);
        __amHandleDoneMsg(sp60);
        phi_s2 = phi_s2_2;
        phi_s1 = temp_s1;
    }
    phi_s2_2 = phi_s2;
    if (phi_s2 == 0)
    {
        goto loop_1;
    }
    alClose(&_am+0x238);
}
#else
GLOBAL_ASM(
.text
glabel _amMain
/* 002B7C 70001F7C 27BDFF90 */  addiu $sp, $sp, -0x70
/* 002B80 70001F80 AFB60030 */  sw    $s6, 0x30($sp)
/* 002B84 70001F84 3C168006 */  lui   $s6, %hi(_am+0x1C8) # $s6, 0x8006
/* 002B88 70001F88 AFA40070 */  sw    $a0, 0x70($sp)
/* 002B8C 70001F8C 26D6E6E0 */  addiu $s6, %lo(_am+0x1C8) # addiu $s6, $s6, -0x1920
/* 002B90 70001F90 AFBF003C */  sw    $ra, 0x3c($sp)
/* 002B94 70001F94 AFB20020 */  sw    $s2, 0x20($sp)
/* 002B98 70001F98 AFB1001C */  sw    $s1, 0x1c($sp)
/* 002B9C 70001F9C 3C048006 */  lui   $a0, %hi(sc) # $a0, 0x8006
/* 002BA0 70001FA0 3C058006 */  lui   $a1, %hi(audi_client) # $a1, 0x8006
/* 002BA4 70001FA4 AFBE0038 */  sw    $fp, 0x38($sp)
/* 002BA8 70001FA8 AFB70034 */  sw    $s7, 0x34($sp)
/* 002BAC 70001FAC AFB5002C */  sw    $s5, 0x2c($sp)
/* 002BB0 70001FB0 AFB40028 */  sw    $s4, 0x28($sp)
/* 002BB4 70001FB4 AFB30024 */  sw    $s3, 0x24($sp)
/* 002BB8 70001FB8 AFB00018 */  sw    $s0, 0x18($sp)
/* 002BBC 70001FBC 00008825 */  move  $s1, $zero
/* 002BC0 70001FC0 00009025 */  move  $s2, $zero
/* 002BC4 70001FC4 AFA00064 */  sw    $zero, 0x64($sp)
/* 002BC8 70001FC8 AFA00060 */  sw    $zero, 0x60($sp)
/* 002BCC 70001FCC 24A5E7A0 */  addiu $a1, %lo(audi_client) # addiu $a1, $a1, -0x1860
/* 002BD0 70001FD0 2484DA40 */  addiu $a0, %lo(sc) # addiu $a0, $a0, -0x25c0
/* 002BD4 70001FD4 02C03025 */  move  $a2, $s6
/* 002BD8 70001FD8 0C000305 */  jal   osScAddClient
/* 002BDC 70001FDC 24070001 */   li    $a3, 1
/* 002BE0 70001FE0 3C158006 */  lui   $s5, %hi(dword_CODE_bss_8005E4E0) # $s5, 0x8006
/* 002BE4 70001FE4 3C148006 */  lui   $s4, %hi(dword_CODE_bss_8005E4D8) # $s4, 0x8006
/* 002BE8 70001FE8 3C138006 */  lui   $s3, %hi(dword_CODE_bss_8005E4B8) # $s3, 0x8006
/* 002BEC 70001FEC 3C108006 */  lui   $s0, %hi(dword_CODE_bss_8005E4D0) # $s0, 0x8006
/* 002BF0 70001FF0 2610E4D0 */  addiu $s0, %lo(dword_CODE_bss_8005E4D0) # addiu $s0, $s0, -0x1b30
/* 002BF4 70001FF4 2673E4B8 */  addiu $s3, %lo(dword_CODE_bss_8005E4B8) # addiu $s3, $s3, -0x1b48
/* 002BF8 70001FF8 2694E4D8 */  addiu $s4, %lo(dword_CODE_bss_8005E4D8) # addiu $s4, $s4, -0x1b28
/* 002BFC 70001FFC 26B5E4E0 */  addiu $s5, %lo(dword_CODE_bss_8005E4E0) # addiu $s5, $s5, -0x1b20
/* 002C00 70002000 241E0001 */  li    $fp, 1
/* 002C04 70002004 27B70064 */  addiu $s7, $sp, 0x64
/* 002C08 70002008 02C02025 */  move  $a0, $s6
.L7000200C:
/* 002C0C 7000200C 02E02825 */  move  $a1, $s7
/* 002C10 70002010 0C003774 */  jal   osRecvMesg
/* 002C14 70002014 03C03025 */   move  $a2, $fp
/* 002C18 70002018 8FAE0064 */  lw    $t6, 0x64($sp)
/* 002C1C 7000201C 24010005 */  li    $at, 5
/* 002C20 70002020 85C40000 */  lh    $a0, ($t6)
/* 002C24 70002024 109E0007 */  beq   $a0, $fp, .L70002044
/* 002C28 70002028 00000000 */   nop   
/* 002C2C 7000202C 10810071 */  beq   $a0, $at, .L700021F4
/* 002C30 70002030 2401000A */   li    $at, 10
/* 002C34 70002034 50810072 */  beql  $a0, $at, .L70002200
/* 002C38 70002038 03C09025 */   move  $s2, $fp
/* 002C3C 7000203C 10000070 */  b     .L70002200
/* 002C40 70002040 00000000 */   nop   
.L70002044:
/* 002C44 70002044 0C003AEC */  jal   osGetTime
/* 002C48 70002048 00000000 */   nop   
/* 002C4C 7000204C AE820000 */  sw    $v0, ($s4)
/* 002C50 70002050 AE830004 */  sw    $v1, 4($s4)
/* 002C54 70002054 0C000A15 */  jal   video_related_3
/* 002C58 70002058 3C040003 */   lui   $a0, 3
/* 002C5C 7000205C 3C0F8002 */  lui   $t7, %hi(audFrameCt) # $t7, 0x8002
/* 002C60 70002060 8DEF30F4 */  lw    $t7, %lo(audFrameCt)($t7)
/* 002C64 70002064 24010003 */  li    $at, 3
/* 002C68 70002068 3C048006 */  lui   $a0, %hi(_am+8)
/* 002C6C 7000206C 01E1001B */  divu  $zero, $t7, $at
/* 002C70 70002070 0000C010 */  mfhi  $t8
/* 002C74 70002074 0018C880 */  sll   $t9, $t8, 2
/* 002C78 70002078 00992021 */  addu  $a0, $a0, $t9
/* 002C7C 7000207C 8C84E520 */  lw    $a0, %lo(_am+8)($a0)
/* 002C80 70002080 0C000891 */  jal   _amHandleFrameMsg
/* 002C84 70002084 8FA50060 */   lw    $a1, 0x60($sp)
/* 002C88 70002088 26310001 */  addiu $s1, $s1, 1
/* 002C8C 7000208C 0C000A15 */  jal   video_related_3
/* 002C90 70002090 3C040006 */   lui   $a0, 6
/* 002C94 70002094 0C003AEC */  jal   osGetTime
/* 002C98 70002098 00000000 */   nop   
/* 002C9C 7000209C 8E8A0000 */  lw    $t2, ($s4)
/* 002CA0 700020A0 8E8B0004 */  lw    $t3, 4($s4)
/* 002CA4 700020A4 AEA20000 */  sw    $v0, ($s5)
/* 002CA8 700020A8 004AC023 */  subu  $t8, $v0, $t2
/* 002CAC 700020AC 006B082B */  sltu  $at, $v1, $t3
/* 002CB0 700020B0 0301C023 */  subu  $t8, $t8, $at
/* 002CB4 700020B4 AEA30004 */  sw    $v1, 4($s5)
/* 002CB8 700020B8 3C018006 */  lui   $at, %hi(dword_CODE_bss_8005E4C0) # $at, 0x8006
/* 002CBC 700020BC 006BC823 */  subu  $t9, $v1, $t3
/* 002CC0 700020C0 AC39E4C4 */  sw    $t9, %lo(dword_CODE_bss_8005E4C4)($at)
/* 002CC4 700020C4 AC38E4C0 */  sw    $t8, %lo(dword_CODE_bss_8005E4C0)($at)
/* 002CC8 700020C8 240100F0 */  li    $at, 240
/* 002CCC 700020CC 0221001A */  div   $zero, $s1, $at
/* 002CD0 700020D0 00004010 */  mfhi  $t0
/* 002CD4 700020D4 AFB90044 */  sw    $t9, 0x44($sp)
/* 002CD8 700020D8 AFB80040 */  sw    $t8, 0x40($sp)
/* 002CDC 700020DC AFA20050 */  sw    $v0, 0x50($sp)
/* 002CE0 700020E0 AFA30054 */  sw    $v1, 0x54($sp)
/* 002CE4 700020E4 AFAA0048 */  sw    $t2, 0x48($sp)
/* 002CE8 700020E8 1500001C */  bnez  $t0, .L7000215C
/* 002CEC 700020EC AFAB004C */   sw    $t3, 0x4c($sp)
/* 002CF0 700020F0 8E040000 */  lw    $a0, ($s0)
/* 002CF4 700020F4 8E050004 */  lw    $a1, 4($s0)
/* 002CF8 700020F8 24060000 */  li    $a2, 0
/* 002CFC 700020FC 0C003B2A */  jal   ull_div
/* 002D00 70002100 240700F0 */   li    $a3, 240
/* 002D04 70002104 3C018006 */  lui   $at, %hi(dword_CODE_bss_8005E4CC) # $at, 0x8006
/* 002D08 70002108 AC22E4C8 */  sw    $v0, %lo(dword_CODE_bss_8005E4C8)($at)
/* 002D0C 7000210C AC23E4CC */  sw    $v1, %lo(dword_CODE_bss_8005E4CC)($at)
/* 002D10 70002110 8E990004 */  lw    $t9, 4($s4)
/* 002D14 70002114 8E980000 */  lw    $t8, ($s4)
/* 002D18 70002118 8EAF0004 */  lw    $t7, 4($s5)
/* 002D1C 7000211C 8EAE0000 */  lw    $t6, ($s5)
/* 002D20 70002120 240A0000 */  li    $t2, 0
/* 002D24 70002124 01F9082B */  sltu  $at, $t7, $t9
/* 002D28 70002128 01D84023 */  subu  $t0, $t6, $t8
/* 002D2C 7000212C 01014023 */  subu  $t0, $t0, $at
/* 002D30 70002130 240B0000 */  li    $t3, 0
/* 002D34 70002134 240C0000 */  li    $t4, 0
/* 002D38 70002138 240D0000 */  li    $t5, 0
/* 002D3C 7000213C 01F94823 */  subu  $t1, $t7, $t9
/* 002D40 70002140 AFA90044 */  sw    $t1, 0x44($sp)
/* 002D44 70002144 AE6D0004 */  sw    $t5, 4($s3)
/* 002D48 70002148 AE6C0000 */  sw    $t4, ($s3)
/* 002D4C 7000214C AE0B0004 */  sw    $t3, 4($s0)
/* 002D50 70002150 AFA80040 */  sw    $t0, 0x40($sp)
/* 002D54 70002154 10000011 */  b     .L7000219C
/* 002D58 70002158 AE0A0000 */   sw    $t2, ($s0)
.L7000215C:
/* 002D5C 7000215C 8E0B0004 */  lw    $t3, 4($s0)
/* 002D60 70002160 8FAD0054 */  lw    $t5, 0x54($sp)
/* 002D64 70002164 8E0A0000 */  lw    $t2, ($s0)
/* 002D68 70002168 8FAC0050 */  lw    $t4, 0x50($sp)
/* 002D6C 7000216C 016D7821 */  addu  $t7, $t3, $t5
/* 002D70 70002170 8FB80048 */  lw    $t8, 0x48($sp)
/* 002D74 70002174 8FB9004C */  lw    $t9, 0x4c($sp)
/* 002D78 70002178 01ED082B */  sltu  $at, $t7, $t5
/* 002D7C 7000217C 002A7021 */  addu  $t6, $at, $t2
/* 002D80 70002180 01CC7021 */  addu  $t6, $t6, $t4
/* 002D84 70002184 01D84023 */  subu  $t0, $t6, $t8
/* 002D88 70002188 01F9082B */  sltu  $at, $t7, $t9
/* 002D8C 7000218C 01014023 */  subu  $t0, $t0, $at
/* 002D90 70002190 01F94823 */  subu  $t1, $t7, $t9
/* 002D94 70002194 AE090004 */  sw    $t1, 4($s0)
/* 002D98 70002198 AE080000 */  sw    $t0, ($s0)
.L7000219C:
/* 002D9C 7000219C 8E6A0000 */  lw    $t2, ($s3)
/* 002DA0 700021A0 8FAC0040 */  lw    $t4, 0x40($sp)
/* 002DA4 700021A4 8E6B0004 */  lw    $t3, 4($s3)
/* 002DA8 700021A8 8FAD0044 */  lw    $t5, 0x44($sp)
/* 002DAC 700021AC 018A082B */  sltu  $at, $t4, $t2
/* 002DB0 700021B0 14200008 */  bnez  $at, .L700021D4
/* 002DB4 700021B4 3C048006 */   lui   $a0, %hi(_am+0x200) # $a0, 0x8006
/* 002DB8 700021B8 014C082B */  sltu  $at, $t2, $t4
/* 002DBC 700021BC 14200003 */  bnez  $at, .L700021CC
/* 002DC0 700021C0 016D082B */   sltu  $at, $t3, $t5
/* 002DC4 700021C4 10200003 */  beqz  $at, .L700021D4
/* 002DC8 700021C8 00000000 */   nop   
.L700021CC:
/* 002DCC 700021CC AE6C0000 */  sw    $t4, ($s3)
/* 002DD0 700021D0 AE6D0004 */  sw    $t5, 4($s3)
.L700021D4:
/* 002DD4 700021D4 2484E718 */  addiu $a0, %lo(_am+0x200) # addiu $a0, $a0, -0x18e8
/* 002DD8 700021D8 27A50060 */  addiu $a1, $sp, 0x60
/* 002DDC 700021DC 0C003774 */  jal   osRecvMesg
/* 002DE0 700021E0 03C03025 */   move  $a2, $fp
/* 002DE4 700021E4 0C0008F9 */  jal   __amHandleDoneMsg
/* 002DE8 700021E8 8FA40060 */   lw    $a0, 0x60($sp)
/* 002DEC 700021EC 10000004 */  b     .L70002200
/* 002DF0 700021F0 00000000 */   nop   
.L700021F4:
/* 002DF4 700021F4 10000002 */  b     .L70002200
/* 002DF8 700021F8 03C09025 */   move  $s2, $fp
/* 002DFC 700021FC 03C09025 */  move  $s2, $fp
.L70002200:
/* 002E00 70002200 5240FF82 */  beql  $s2, $zero, .L7000200C
/* 002E04 70002204 02C02025 */   move  $a0, $s6
/* 002E08 70002208 3C048006 */  lui   $a0, %hi(_am+0x238) # $a0, 0x8006
/* 002E0C 7000220C 0C003AB9 */  jal   alClose
/* 002E10 70002210 2484E750 */   addiu $a0, %lo(_am+0x238) # addiu $a0, $a0, -0x18b0
/* 002E14 70002214 8FBF003C */  lw    $ra, 0x3c($sp)
/* 002E18 70002218 8FB00018 */  lw    $s0, 0x18($sp)
/* 002E1C 7000221C 8FB1001C */  lw    $s1, 0x1c($sp)
/* 002E20 70002220 8FB20020 */  lw    $s2, 0x20($sp)
/* 002E24 70002224 8FB30024 */  lw    $s3, 0x24($sp)
/* 002E28 70002228 8FB40028 */  lw    $s4, 0x28($sp)
/* 002E2C 7000222C 8FB5002C */  lw    $s5, 0x2c($sp)
/* 002E30 70002230 8FB60030 */  lw    $s6, 0x30($sp)
/* 002E34 70002234 8FB70034 */  lw    $s7, 0x34($sp)
/* 002E38 70002238 8FBE0038 */  lw    $fp, 0x38($sp)
/* 002E3C 7000223C 03E00008 */  jr    $ra
/* 002E40 70002240 27BD0070 */   addiu $sp, $sp, 0x70
)
#endif

/**
 * 2E44	70002244
 *	accepts: A0=, A1=p->audio packet
 */
#ifdef NONMATCHING
void _amHandleFrameMsg(void *arg0, s32 arg1, void *argB) {
    s32 sp24;

    // Node 0
    __clearAudioDMA();
    sp24 = osVirtualToPhysical(*arg0);
    if (argB != 0)
    {
        // Node 1
        osAiSetNextBuffer(*argB, (argB->unk4 * 4));
    }
    // Node 2
    arg0->unk4 = (s16) (((frameSize - (osAiGetLength() >> 2)) + 0x35) & 0xfff0);
    if (arg0->unk4 < ((s32) (minFrameSize << 0x10) >> 0x10))
    {
        // Node 3
        arg0->unk4 = (s16) minFrameSize;
    }
    // Node 4
    arg0->unk8 = 0;
    arg0->unk58 = &_am+0x200;
    arg0->unk5C = arg0;
    arg0->unk10 = 2;
    arg0->unk48 = (?32) *(&_am + (curAcmdList * 4));
    arg0->unk4C = (s32) (((s32) (alAudioFrame((0x80060000 + (curAcmdList * 4))->unk-1AE8, &cmdLen, sp24, arg0->unk4) - *(&_am + (curAcmdList * 4))) >> 3) * 8);
    arg0->unk18 = 2;
    arg0->unk20 = &rspbootTextStart;
    arg0->unk24 = (s32) (&gsp3DTextStart - &rspbootTextStart);
    arg0->unk1C = 0;
    arg0->unk28 = &aspMainTextStart;
    arg0->unk30 = &aspMainDataStart;
    arg0->unk34 = 0x800;
    arg0->unk50 = 0;
    arg0->unk54 = 0;
    osSendMesg(osScGetCmdQ(&sc, &rspbootTextStart, &curAcmdList, &_am), (arg0 + 8), 0);
    curAcmdList = (s32) (curAcmdList ^ 1);
    return;
    // (possible return value: osSendMesg(osScGetCmdQ(&sc, &rspbootTextStart, &curAcmdList, &_am), (arg0 + 8), 0))
}
#else
GLOBAL_ASM(
.text
glabel _amHandleFrameMsg
/* 002E44 70002244 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 002E48 70002248 AFBF001C */  sw    $ra, 0x1c($sp)
/* 002E4C 7000224C AFB00018 */  sw    $s0, 0x18($sp)
/* 002E50 70002250 00808025 */  move  $s0, $a0
/* 002E54 70002254 0C000984 */  jal   __clearAudioDMA
/* 002E58 70002258 AFA5002C */   sw    $a1, 0x2c($sp)
/* 002E5C 7000225C 0C003A2C */  jal   osVirtualToPhysical
/* 002E60 70002260 8E040000 */   lw    $a0, ($s0)
/* 002E64 70002264 8FA3002C */  lw    $v1, 0x2c($sp)
/* 002E68 70002268 AFA20024 */  sw    $v0, 0x24($sp)
/* 002E6C 7000226C 10600006 */  beqz  $v1, .L70002288
/* 002E70 70002270 00000000 */   nop   
/* 002E74 70002274 84650004 */  lh    $a1, 4($v1)
/* 002E78 70002278 8C640000 */  lw    $a0, ($v1)
/* 002E7C 7000227C 00057080 */  sll   $t6, $a1, 2
/* 002E80 70002280 0C003BC0 */  jal   osAiSetNextBuffer
/* 002E84 70002284 01C02825 */   move  $a1, $t6
.L70002288:
/* 002E88 70002288 0C003BEC */  jal   osAiGetLength
/* 002E8C 7000228C 00000000 */   nop   
/* 002E90 70002290 3C0F8006 */  lui   $t7, %hi(frameSize) # $t7, 0x8006
/* 002E94 70002294 8DEFECC4 */  lw    $t7, %lo(frameSize)($t7)
/* 002E98 70002298 0002C082 */  srl   $t8, $v0, 2
/* 002E9C 7000229C 3C038006 */  lui   $v1, %hi(minFrameSize) # $v1, 0x8006
/* 002EA0 700022A0 01F8C823 */  subu  $t9, $t7, $t8
/* 002EA4 700022A4 27280035 */  addiu $t0, $t9, 0x35
/* 002EA8 700022A8 3109FFF0 */  andi  $t1, $t0, 0xfff0
/* 002EAC 700022AC A6090004 */  sh    $t1, 4($s0)
/* 002EB0 700022B0 8C63ECC0 */  lw    $v1, %lo(minFrameSize)($v1)
/* 002EB4 700022B4 86070004 */  lh    $a3, 4($s0)
/* 002EB8 700022B8 3C0C8002 */  lui   $t4, %hi(curAcmdList) # $t4, 0x8002
/* 002EBC 700022BC 00035400 */  sll   $t2, $v1, 0x10
/* 002EC0 700022C0 000A5C03 */  sra   $t3, $t2, 0x10
/* 002EC4 700022C4 00EB082A */  slt   $at, $a3, $t3
/* 002EC8 700022C8 10200003 */  beqz  $at, .L700022D8
/* 002ECC 700022CC 3C048006 */   lui   $a0, %hi(_am)
/* 002ED0 700022D0 A6030004 */  sh    $v1, 4($s0)
/* 002ED4 700022D4 86070004 */  lh    $a3, 4($s0)
.L700022D8:
/* 002ED8 700022D8 8D8C30FC */  lw    $t4, %lo(curAcmdList)($t4)
/* 002EDC 700022DC 3C058006 */  lui   $a1, %hi(cmdLen) # $a1, 0x8006
/* 002EE0 700022E0 24A5ECCC */  addiu $a1, %lo(cmdLen) # addiu $a1, $a1, -0x1334
/* 002EE4 700022E4 000C6880 */  sll   $t5, $t4, 2
/* 002EE8 700022E8 008D2021 */  addu  $a0, $a0, $t5
/* 002EEC 700022EC 8C84E518 */  lw    $a0, %lo(_am)($a0)
/* 002EF0 700022F0 0C003C42 */  jal   alAudioFrame
/* 002EF4 700022F4 8FA60024 */   lw    $a2, 0x24($sp)
/* 002EF8 700022F8 3C0E8006 */  lui   $t6, %hi(_am+0x200) # $t6, 0x8006
/* 002EFC 700022FC 24030002 */  li    $v1, 2
/* 002F00 70002300 3C068002 */  lui   $a2, %hi(curAcmdList) # $a2, 0x8002
/* 002F04 70002304 25CEE718 */  addiu $t6, %lo(_am+0x200) # addiu $t6, $t6, -0x18e8
/* 002F08 70002308 24C630FC */  addiu $a2, %lo(curAcmdList) # addiu $a2, $a2, 0x30fc
/* 002F0C 7000230C AE000008 */  sw    $zero, 8($s0)
/* 002F10 70002310 AE0E0058 */  sw    $t6, 0x58($s0)
/* 002F14 70002314 AE10005C */  sw    $s0, 0x5c($s0)
/* 002F18 70002318 AE030010 */  sw    $v1, 0x10($s0)
/* 002F1C 7000231C 8CCF0000 */  lw    $t7, ($a2)
/* 002F20 70002320 3C078006 */  lui   $a3, %hi(_am) # $a3, 0x8006
/* 002F24 70002324 24E7E518 */  addiu $a3, %lo(_am) # addiu $a3, $a3, -0x1ae8
/* 002F28 70002328 000FC080 */  sll   $t8, $t7, 2
/* 002F2C 7000232C 00F8C821 */  addu  $t9, $a3, $t8
/* 002F30 70002330 8F280000 */  lw    $t0, ($t9)
/* 002F34 70002334 3C058002 */  lui   $a1, %hi(rspbootTextStart) # $a1, 0x8002
/* 002F38 70002338 3C188002 */  lui   $t8, %hi(gsp3DTextStart) # $t8, 0x8002
/* 002F3C 7000233C AE080048 */  sw    $t0, 0x48($s0)
/* 002F40 70002340 8CC90000 */  lw    $t1, ($a2)
/* 002F44 70002344 24A50D90 */  addiu $a1, %lo(rspbootTextStart) # addiu $a1, $a1, 0xd90
/* 002F48 70002348 27180E60 */  addiu $t8, %lo(gsp3DTextStart) # addiu $t8, $t8, 0xe60
/* 002F4C 7000234C 00095080 */  sll   $t2, $t1, 2
/* 002F50 70002350 00EA5821 */  addu  $t3, $a3, $t2
/* 002F54 70002354 8D6C0000 */  lw    $t4, ($t3)
/* 002F58 70002358 3C088002 */  lui   $t0, %hi(aspMainTextStart) # $t0, 0x8002
/* 002F5C 7000235C 3C098006 */  lui   $t1, %hi(aspMainDataStart) # $t1, 0x8006
/* 002F60 70002360 004C6823 */  subu  $t5, $v0, $t4
/* 002F64 70002364 000D70C3 */  sra   $t6, $t5, 3
/* 002F68 70002368 000E78C0 */  sll   $t7, $t6, 3
/* 002F6C 7000236C 0305C823 */  subu  $t9, $t8, $a1
/* 002F70 70002370 25082280 */  addiu $t0, %lo(aspMainTextStart) # addiu $t0, $t0, 0x2280
/* 002F74 70002374 2529D020 */  addiu $t1, %lo(aspMainDataStart) # addiu $t1, $t1, -0x2fe0
/* 002F78 70002378 240A0800 */  li    $t2, 2048
/* 002F7C 7000237C 3C048006 */  lui   $a0, %hi(sc) # $a0, 0x8006
/* 002F80 70002380 AE0F004C */  sw    $t7, 0x4c($s0)
/* 002F84 70002384 AE030018 */  sw    $v1, 0x18($s0)
/* 002F88 70002388 AE050020 */  sw    $a1, 0x20($s0)
/* 002F8C 7000238C AE190024 */  sw    $t9, 0x24($s0)
/* 002F90 70002390 AE00001C */  sw    $zero, 0x1c($s0)
/* 002F94 70002394 AE080028 */  sw    $t0, 0x28($s0)
/* 002F98 70002398 AE090030 */  sw    $t1, 0x30($s0)
/* 002F9C 7000239C AE0A0034 */  sw    $t2, 0x34($s0)
/* 002FA0 700023A0 AE000050 */  sw    $zero, 0x50($s0)
/* 002FA4 700023A4 AE000054 */  sw    $zero, 0x54($s0)
/* 002FA8 700023A8 0C00033E */  jal   osScGetCmdQ
/* 002FAC 700023AC 2484DA40 */   addiu $a0, %lo(sc) # addiu $a0, $a0, -0x25c0
/* 002FB0 700023B0 00402025 */  move  $a0, $v0
/* 002FB4 700023B4 26050008 */  addiu $a1, $s0, 8
/* 002FB8 700023B8 0C0037C4 */  jal   osSendMesg
/* 002FBC 700023BC 00003025 */   move  $a2, $zero
/* 002FC0 700023C0 3C038002 */  lui   $v1, %hi(curAcmdList) # $v1, 0x8002
/* 002FC4 700023C4 246330FC */  addiu $v1, %lo(curAcmdList) # addiu $v1, $v1, 0x30fc
/* 002FC8 700023C8 8C6B0000 */  lw    $t3, ($v1)
/* 002FCC 700023CC 8FBF001C */  lw    $ra, 0x1c($sp)
/* 002FD0 700023D0 8FB00018 */  lw    $s0, 0x18($sp)
/* 002FD4 700023D4 396C0001 */  xori  $t4, $t3, 1
/* 002FD8 700023D8 AC6C0000 */  sw    $t4, ($v1)
/* 002FDC 700023DC 03E00008 */  jr    $ra
/* 002FE0 700023E0 27BD0028 */   addiu $sp, $sp, 0x28
)
#endif

/**
 * 2FE4	700023E4
 */
#ifdef NONMATCHING
void __amHandleDoneMsg(AudioInfo *info) {
  int samplesLeft;
  
  samplesLeft = osAiGetLength();
  if ((samplesLeft >> 2 == 0) && (firstTime == 0)) {
    firstTime = 0;
  }
}
#else
GLOBAL_ASM(
.text
glabel __amHandleDoneMsg
/* 002FE4 700023E4 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 002FE8 700023E8 AFBF0014 */  sw    $ra, 0x14($sp)
/* 002FEC 700023EC 0C003BEC */  jal   osAiGetLength
/* 002FF0 700023F0 AFA40018 */   sw    $a0, 0x18($sp)
/* 002FF4 700023F4 00027083 */  sra   $t6, $v0, 2
/* 002FF8 700023F8 15C00006 */  bnez  $t6, .L70002414
/* 002FFC 700023FC 3C0F8002 */   lui   $t7, %hi(firstTime) # $t7, 0x8002
/* 003000 70002400 8DEF31C8 */  lw    $t7, %lo(firstTime)($t7)
/* 003004 70002404 3C018002 */  lui   $at, %hi(firstTime) # $at, 0x8002
/* 003008 70002408 55E00003 */  bnezl $t7, .L70002418
/* 00300C 7000240C 8FBF0014 */   lw    $ra, 0x14($sp)
/* 003010 70002410 AC2031C8 */  sw    $zero, %lo(firstTime)($at)
.L70002414:
/* 003014 70002414 8FBF0014 */  lw    $ra, 0x14($sp)
.L70002418:
/* 003018 70002418 27BD0018 */  addiu $sp, $sp, 0x18
/* 00301C 7000241C 03E00008 */  jr    $ra
/* 003020 70002420 00000000 */   nop   
)
#endif

/**
 * 3024	70002424
 */
#ifdef NONMATCHING
s32 __amDMA(u32 arg0, s32 arg1, ? arg2, s32 arg14) {
    s32 sp30;
    s32 sp48;
    ?32 sp4C;
    s32 temp_t2;
    s32 temp_a3;

    // Node 0
    temp_t2 = (arg0 & 1);
    sp48 = temp_t2;
    if (dmaState_initialized.unk4 != 0)
    {
        loop_1:
        // Node 1
        if (arg0 >= (u32) dmaState_initialized.unk4->unk8)
        {
            // Node 2
            if ((dmaState_initialized.unk4->unk8 + 0x200) >= (arg0 + arg1))
            {
                // Node 3
                dmaState_initialized.unk4->unkC = (?32) audFrameCt;
                osVirtualToPhysical(((dmaState_initialized.unk4->unk10 + arg0) - dmaState_initialized.unk4->unk8), dmaState_initialized.unk4, arg0);
                return;
                // (possible return value: osVirtualToPhysical(((dmaState_initialized.unk4->unk10 + arg0) - dmaState_initialized.unk4->unk8), dmaState_initialized.unk4, arg0))
            }
            // Node 4
            if (*dmaState_initialized.unk4 != 0)
            {
                goto loop_1;
            }
        }
    }
    // Node 5
    if (dmaState_initialized.unk8 == 0)
    {
        // Node 6
        if (NULL == 0)
        {
            // Node 7
        }
        // Node 8
        sp30 = temp_t2;
        osVirtualToPhysical(NULL->unk10, NULL, arg0);
    }
    else
    {
        // Node 9
        dmaState_initialized.unk8 = (void *) *dmaState_initialized.unk8;
        alUnlink(dmaState_initialized.unk8, NULL, arg0);
        if (sp38 != 0)
        {
            // Node 10
            alLink(dmaState_initialized.unk8, sp38, sp38, arg14);
        }
        else
        {
            // Node 11
            if (dmaState_initialized.unk4 != 0)
            {
                // Node 12
                dmaState_initialized.unk4 = (void *) dmaState_initialized.unk8;
                *dmaState_initialized.unk8 = (void *) dmaState_initialized.unk4;
                dmaState_initialized.unk8->unk4 = 0;
                dmaState_initialized.unk4->unk4 = (void *) dmaState_initialized.unk8;
            }
            else
            {
                // Node 13
                dmaState_initialized.unk4 = (void *) dmaState_initialized.unk8;
                *dmaState_initialized.unk8 = NULL;
                dmaState_initialized.unk8->unk4 = 0;
            }
        }
        // Node 14
        temp_a3 = (arg14 - sp48);
        dmaState_initialized.unk8->unk8 = temp_a3;
        dmaState_initialized.unk8->unkC = (?32) audFrameCt;
        nextDMA = (s32) (nextDMA + 1);
        sp4C = (?32) dmaState_initialized.unk8->unk10;
        osPiStartDma(((nextDMA * 0x18) + &audDMAIOMesgBuf), 1, 0, temp_a3, (?32) dmaState_initialized.unk8->unk10, 0x200, &audDMAMessageQ);
        osVirtualToPhysical(sp4C);
    }
    // Node 15
    return;
    // (possible return value: (osVirtualToPhysical(sp4C) + sp48))
}
#else
GLOBAL_ASM(
.text
glabel __amDMA
/* 003024 70002424 3C098006 */  lui   $t1, %hi(dmaState_initialized) # $t1, 0x8006
/* 003028 70002428 2529E7B0 */  addiu $t1, %lo(dmaState_initialized) # addiu $t1, $t1, -0x1850
/* 00302C 7000242C 8D280004 */  lw    $t0, 4($t1)
/* 003030 70002430 27BDFFB0 */  addiu $sp, $sp, -0x50
/* 003034 70002434 AFB00028 */  sw    $s0, 0x28($sp)
/* 003038 70002438 AFA60058 */  sw    $a2, 0x58($sp)
/* 00303C 7000243C 308A0001 */  andi  $t2, $a0, 1
/* 003040 70002440 AFBF002C */  sw    $ra, 0x2c($sp)
/* 003044 70002444 00803825 */  move  $a3, $a0
/* 003048 70002448 00003025 */  move  $a2, $zero
/* 00304C 7000244C AFAA0048 */  sw    $t2, 0x48($sp)
/* 003050 70002450 11000015 */  beqz  $t0, .L700024A8
/* 003054 70002454 01008025 */   move  $s0, $t0
/* 003058 70002458 8E020008 */  lw    $v0, 8($s0)
.L7000245C:
/* 00305C 7000245C 00E57021 */  addu  $t6, $a3, $a1
/* 003060 70002460 00E2082B */  sltu  $at, $a3, $v0
/* 003064 70002464 14200010 */  bnez  $at, .L700024A8
/* 003068 70002468 24430200 */   addiu $v1, $v0, 0x200
/* 00306C 7000246C 006E082A */  slt   $at, $v1, $t6
/* 003070 70002470 1420000A */  bnez  $at, .L7000249C
/* 003074 70002474 02003025 */   move  $a2, $s0
/* 003078 70002478 8E180010 */  lw    $t8, 0x10($s0)
/* 00307C 7000247C 3C0F8002 */  lui   $t7, %hi(audFrameCt) # $t7, 0x8002
/* 003080 70002480 8DEF30F4 */  lw    $t7, %lo(audFrameCt)($t7)
/* 003084 70002484 0307C821 */  addu  $t9, $t8, $a3
/* 003088 70002488 03222023 */  subu  $a0, $t9, $v0
/* 00308C 7000248C 0C003A2C */  jal   osVirtualToPhysical
/* 003090 70002490 AE0F000C */   sw    $t7, 0xc($s0)
/* 003094 70002494 1000004C */  b     .L700025C8
/* 003098 70002498 8FBF002C */   lw    $ra, 0x2c($sp)
.L7000249C:
/* 00309C 7000249C 8E100000 */  lw    $s0, ($s0)
/* 0030A0 700024A0 5600FFEE */  bnezl $s0, .L7000245C
/* 0030A4 700024A4 8E020008 */   lw    $v0, 8($s0)
.L700024A8:
/* 0030A8 700024A8 8D300008 */  lw    $s0, 8($t1)
/* 0030AC 700024AC 1600000A */  bnez  $s0, .L700024D8
/* 0030B0 700024B0 02002025 */   move  $a0, $s0
/* 0030B4 700024B4 54C00003 */  bnezl $a2, .L700024C4
/* 0030B8 700024B8 8CC40010 */   lw    $a0, 0x10($a2)
/* 0030BC 700024BC 01003025 */  move  $a2, $t0
/* 0030C0 700024C0 8CC40010 */  lw    $a0, 0x10($a2)
.L700024C4:
/* 0030C4 700024C4 0C003A2C */  jal   osVirtualToPhysical
/* 0030C8 700024C8 AFAA0030 */   sw    $t2, 0x30($sp)
/* 0030CC 700024CC 8FAA0030 */  lw    $t2, 0x30($sp)
/* 0030D0 700024D0 1000003C */  b     .L700025C4
/* 0030D4 700024D4 004A1021 */   addu  $v0, $v0, $t2
.L700024D8:
/* 0030D8 700024D8 8E0B0000 */  lw    $t3, ($s0)
/* 0030DC 700024DC AFA70050 */  sw    $a3, 0x50($sp)
/* 0030E0 700024E0 AFA60038 */  sw    $a2, 0x38($sp)
/* 0030E4 700024E4 0C003AA4 */  jal   alUnlink
/* 0030E8 700024E8 AD2B0008 */   sw    $t3, 8($t1)
/* 0030EC 700024EC 8FA60038 */  lw    $a2, 0x38($sp)
/* 0030F0 700024F0 3C098006 */  lui   $t1, %hi(dmaState_initialized) # $t1, 0x8006
/* 0030F4 700024F4 2529E7B0 */  addiu $t1, %lo(dmaState_initialized) # addiu $t1, $t1, -0x1850
/* 0030F8 700024F8 10C00007 */  beqz  $a2, .L70002518
/* 0030FC 700024FC 8FA70050 */   lw    $a3, 0x50($sp)
/* 003100 70002500 02002025 */  move  $a0, $s0
/* 003104 70002504 00C02825 */  move  $a1, $a2
/* 003108 70002508 0C003AB0 */  jal   alLink
/* 00310C 7000250C AFA70050 */   sw    $a3, 0x50($sp)
/* 003110 70002510 1000000C */  b     .L70002544
/* 003114 70002514 8FA70050 */   lw    $a3, 0x50($sp)
.L70002518:
/* 003118 70002518 8D280004 */  lw    $t0, 4($t1)
/* 00311C 7000251C 51000007 */  beql  $t0, $zero, .L7000253C
/* 003120 70002520 AD300004 */   sw    $s0, 4($t1)
/* 003124 70002524 AD300004 */  sw    $s0, 4($t1)
/* 003128 70002528 AE080000 */  sw    $t0, ($s0)
/* 00312C 7000252C AE000004 */  sw    $zero, 4($s0)
/* 003130 70002530 10000004 */  b     .L70002544
/* 003134 70002534 AD100004 */   sw    $s0, 4($t0)
/* 003138 70002538 AD300004 */  sw    $s0, 4($t1)
.L7000253C:
/* 00313C 7000253C AE000000 */  sw    $zero, ($s0)
/* 003140 70002540 AE000004 */  sw    $zero, 4($s0)
.L70002544:
/* 003144 70002544 8FAC0048 */  lw    $t4, 0x48($sp)
/* 003148 70002548 3C0D8002 */  lui   $t5, %hi(audFrameCt) # $t5, 0x8002
/* 00314C 7000254C 3C088002 */  lui   $t0, %hi(nextDMA) # $t0, 0x8002
/* 003150 70002550 00EC3823 */  subu  $a3, $a3, $t4
/* 003154 70002554 AE070008 */  sw    $a3, 8($s0)
/* 003158 70002558 8DAD30F4 */  lw    $t5, %lo(audFrameCt)($t5)
/* 00315C 7000255C 250830F8 */  addiu $t0, %lo(nextDMA) # addiu $t0, $t0, 0x30f8
/* 003160 70002560 8E030010 */  lw    $v1, 0x10($s0)
/* 003164 70002564 AE0D000C */  sw    $t5, 0xc($s0)
/* 003168 70002568 8D020000 */  lw    $v0, ($t0)
/* 00316C 7000256C 3C0F8006 */  lui   $t7, %hi(audDMAIOMesgBuf) # $t7, 0x8006
/* 003170 70002570 3C198006 */  lui   $t9, %hi(audDMAMessageQ) # $t9, 0x8006
/* 003174 70002574 00027080 */  sll   $t6, $v0, 2
/* 003178 70002578 01C27023 */  subu  $t6, $t6, $v0
/* 00317C 7000257C 000E70C0 */  sll   $t6, $t6, 3
/* 003180 70002580 2739F2D0 */  addiu $t9, %lo(audDMAMessageQ) # addiu $t9, $t9, -0xd30
/* 003184 70002584 25EFECD0 */  addiu $t7, %lo(audDMAIOMesgBuf) # addiu $t7, $t7, -0x1330
/* 003188 70002588 24180200 */  li    $t8, 512
/* 00318C 7000258C 244B0001 */  addiu $t3, $v0, 1
/* 003190 70002590 AD0B0000 */  sw    $t3, ($t0)
/* 003194 70002594 AFB80014 */  sw    $t8, 0x14($sp)
/* 003198 70002598 01CF2021 */  addu  $a0, $t6, $t7
/* 00319C 7000259C AFB90018 */  sw    $t9, 0x18($sp)
/* 0031A0 700025A0 24050001 */  li    $a1, 1
/* 0031A4 700025A4 00003025 */  move  $a2, $zero
/* 0031A8 700025A8 AFA3004C */  sw    $v1, 0x4c($sp)
/* 0031AC 700025AC 0C003DA8 */  jal   osPiStartDma
/* 0031B0 700025B0 AFA30010 */   sw    $v1, 0x10($sp)
/* 0031B4 700025B4 0C003A2C */  jal   osVirtualToPhysical
/* 0031B8 700025B8 8FA4004C */   lw    $a0, 0x4c($sp)
/* 0031BC 700025BC 8FAC0048 */  lw    $t4, 0x48($sp)
/* 0031C0 700025C0 004C1021 */  addu  $v0, $v0, $t4
.L700025C4:
/* 0031C4 700025C4 8FBF002C */  lw    $ra, 0x2c($sp)
.L700025C8:
/* 0031C8 700025C8 8FB00028 */  lw    $s0, 0x28($sp)
/* 0031CC 700025CC 27BD0050 */  addiu $sp, $sp, 0x50
/* 0031D0 700025D0 03E00008 */  jr    $ra
/* 0031D4 700025D4 00000000 */   nop   
)
#endif

/**
 * 31D8	700025D8
 */
#ifdef NONMATCHING
void *__amDmaNew(void *arg0) {
    // Node 0
    if (dmaState_initialized == 0)
    {
        // Node 1
        dmaState_initialized.unk4 = 0;
        dmaState_initialized.unk8 = &dmaBuffs;
        dmaState_initialized = (u8)1;
    }
    // Node 2
    *arg0 = &dmaState_initialized;
    return;
    // (possible return value: &__amDMA)
}
#else
GLOBAL_ASM(
.text
glabel __amDmaNew
/* 0031D8 700025D8 3C038006 */  lui   $v1, %hi(dmaState_initialized) # $v1, 0x8006
/* 0031DC 700025DC 2463E7B0 */  addiu $v1, %lo(dmaState_initialized) # addiu $v1, $v1, -0x1850
/* 0031E0 700025E0 906E0000 */  lbu   $t6, ($v1)
/* 0031E4 700025E4 3C027000 */  lui   $v0, %hi(__amDMA) # $v0, 0x7000
/* 0031E8 700025E8 3C0F8006 */  lui   $t7, %hi(dmaBuffs) # $t7, 0x8006
/* 0031EC 700025EC 15C00006 */  bnez  $t6, .L70002608
/* 0031F0 700025F0 24422424 */   addiu $v0, %lo(__amDMA) # addiu $v0, $v0, 0x2424
/* 0031F4 700025F4 25EFE7C0 */  addiu $t7, %lo(dmaBuffs) # addiu $t7, $t7, -0x1840
/* 0031F8 700025F8 24180001 */  li    $t8, 1
/* 0031FC 700025FC AC600004 */  sw    $zero, 4($v1)
/* 003200 70002600 AC6F0008 */  sw    $t7, 8($v1)
/* 003204 70002604 A0780000 */  sb    $t8, ($v1)
.L70002608:
/* 003208 70002608 03E00008 */  jr    $ra
/* 00320C 7000260C AC830000 */   sw    $v1, ($a0)
)
#endif

/**
 *  3210	70002610
 */
#ifdef NONMATCHING
void __clearAudioDMA(void) {
    ?32 sp40;

    // Node 0
    sp40 = 0;
    if (nextDMA != 0)
    {
        // Node 1
        // Node 2
        osRecvMesg(&audDMAMessageQ, &sp40, 0);
        if ((u32) (0 + 1) < (u32) nextDMA)
        {
            goto loop_2;
        }
    }
    // Node 3
    if (dmaState_initialized.unk4 != 0)
    {
        loop_4:
        // Node 4
        if ((u32) (dmaState_initialized.unk4->unkC + 1) < (u32) audFrameCt)
        {
            // Node 5
            if (dmaState_initialized.unk4 == dmaState_initialized.unk4)
            {
                // Node 6
                dmaState_initialized.unk4 = (void *) *dmaState_initialized.unk4;
            }
            // Node 7
            alUnlink(dmaState_initialized.unk4);
            if (dmaState_initialized.unk8 != 0)
            {
                // Node 8
                alLink(dmaState_initialized.unk4, dmaState_initialized.unk8);
            }
            else
            {
                // Node 9
                dmaState_initialized.unk8 = (void *) dmaState_initialized.unk4;
                *dmaState_initialized.unk4 = NULL;
                dmaState_initialized.unk4->unk4 = 0;
            }
        }
        // Node 10
        if (*dmaState_initialized.unk4 != 0)
        {
            goto loop_4;
        }
    }
    // Node 11
    nextDMA = 0U;
    audFrameCt = (u32) (audFrameCt + 1);
    return;
    // (function likely void)
}
#else
GLOBAL_ASM(
.text
glabel __clearAudioDMA
/* 003210 70002610 27BDFFB8 */  addiu $sp, $sp, -0x48
/* 003214 70002614 AFB40028 */  sw    $s4, 0x28($sp)
/* 003218 70002618 3C148002 */  lui   $s4, %hi(nextDMA) # $s4, 0x8002
/* 00321C 7000261C 269430F8 */  addiu $s4, %lo(nextDMA) # addiu $s4, $s4, 0x30f8
/* 003220 70002620 8E8E0000 */  lw    $t6, ($s4)
/* 003224 70002624 AFB00018 */  sw    $s0, 0x18($sp)
/* 003228 70002628 AFBF002C */  sw    $ra, 0x2c($sp)
/* 00322C 7000262C AFB30024 */  sw    $s3, 0x24($sp)
/* 003230 70002630 AFB20020 */  sw    $s2, 0x20($sp)
/* 003234 70002634 AFB1001C */  sw    $s1, 0x1c($sp)
/* 003238 70002638 AFA00040 */  sw    $zero, 0x40($sp)
/* 00323C 7000263C 11C0000D */  beqz  $t6, .L70002674
/* 003240 70002640 00008025 */   move  $s0, $zero
/* 003244 70002644 3C118006 */  lui   $s1, %hi(audDMAMessageQ) # $s1, 0x8006
/* 003248 70002648 2631F2D0 */  addiu $s1, %lo(audDMAMessageQ) # addiu $s1, $s1, -0xd30
/* 00324C 7000264C 27B20040 */  addiu $s2, $sp, 0x40
/* 003250 70002650 02202025 */  move  $a0, $s1
.L70002654:
/* 003254 70002654 02402825 */  move  $a1, $s2
/* 003258 70002658 0C003774 */  jal   osRecvMesg
/* 00325C 7000265C 00003025 */   move  $a2, $zero
/* 003260 70002660 8E8F0000 */  lw    $t7, ($s4)
/* 003264 70002664 26100001 */  addiu $s0, $s0, 1
/* 003268 70002668 020F082B */  sltu  $at, $s0, $t7
/* 00326C 7000266C 5420FFF9 */  bnezl $at, .L70002654
/* 003270 70002670 02202025 */   move  $a0, $s1
.L70002674:
/* 003274 70002674 3C128006 */  lui   $s2, %hi(dmaState_initialized) # $s2, 0x8006
/* 003278 70002678 2652E7B0 */  addiu $s2, %lo(dmaState_initialized) # addiu $s2, $s2, -0x1850
/* 00327C 7000267C 8E500004 */  lw    $s0, 4($s2)
/* 003280 70002680 3C138002 */  lui   $s3, %hi(audFrameCt) # $s3, 0x8002
/* 003284 70002684 267330F4 */  addiu $s3, %lo(audFrameCt) # addiu $s3, $s3, 0x30f4
/* 003288 70002688 1200001A */  beqz  $s0, .L700026F4
/* 00328C 7000268C 00000000 */   nop   
.L70002690:
/* 003290 70002690 8E19000C */  lw    $t9, 0xc($s0)
/* 003294 70002694 8E780000 */  lw    $t8, ($s3)
/* 003298 70002698 8E020000 */  lw    $v0, ($s0)
/* 00329C 7000269C 27280001 */  addiu $t0, $t9, 1
/* 0032A0 700026A0 0118082B */  sltu  $at, $t0, $t8
/* 0032A4 700026A4 10200011 */  beqz  $at, .L700026EC
/* 0032A8 700026A8 00408825 */   move  $s1, $v0
/* 0032AC 700026AC 8E490004 */  lw    $t1, 4($s2)
/* 0032B0 700026B0 16090002 */  bne   $s0, $t1, .L700026BC
/* 0032B4 700026B4 00000000 */   nop   
/* 0032B8 700026B8 AE420004 */  sw    $v0, 4($s2)
.L700026BC:
/* 0032BC 700026BC 0C003AA4 */  jal   alUnlink
/* 0032C0 700026C0 02002025 */   move  $a0, $s0
/* 0032C4 700026C4 8E450008 */  lw    $a1, 8($s2)
/* 0032C8 700026C8 50A00006 */  beql  $a1, $zero, .L700026E4
/* 0032CC 700026CC AE500008 */   sw    $s0, 8($s2)
/* 0032D0 700026D0 0C003AB0 */  jal   alLink
/* 0032D4 700026D4 02002025 */   move  $a0, $s0
/* 0032D8 700026D8 10000004 */  b     .L700026EC
/* 0032DC 700026DC 00000000 */   nop   
/* 0032E0 700026E0 AE500008 */  sw    $s0, 8($s2)
.L700026E4:
/* 0032E4 700026E4 AE000000 */  sw    $zero, ($s0)
/* 0032E8 700026E8 AE000004 */  sw    $zero, 4($s0)
.L700026EC:
/* 0032EC 700026EC 1620FFE8 */  bnez  $s1, .L70002690
/* 0032F0 700026F0 02208025 */   move  $s0, $s1
.L700026F4:
/* 0032F4 700026F4 3C138002 */  lui   $s3, %hi(audFrameCt) # $s3, 0x8002
/* 0032F8 700026F8 267330F4 */  addiu $s3, %lo(audFrameCt) # addiu $s3, $s3, 0x30f4
/* 0032FC 700026FC 8E6A0000 */  lw    $t2, ($s3)
/* 003300 70002700 8FBF002C */  lw    $ra, 0x2c($sp)
/* 003304 70002704 AE800000 */  sw    $zero, ($s4)
/* 003308 70002708 254B0001 */  addiu $t3, $t2, 1
/* 00330C 7000270C AE6B0000 */  sw    $t3, ($s3)
/* 003310 70002710 8FB30024 */  lw    $s3, 0x24($sp)
/* 003314 70002714 8FB40028 */  lw    $s4, 0x28($sp)
/* 003318 70002718 8FB00018 */  lw    $s0, 0x18($sp)
/* 00331C 7000271C 8FB1001C */  lw    $s1, 0x1c($sp)
/* 003320 70002720 8FB20020 */  lw    $s2, 0x20($sp)
/* 003324 70002724 03E00008 */  jr    $ra
/* 003328 70002728 27BD0048 */   addiu $sp, $sp, 0x48
)
#endif

