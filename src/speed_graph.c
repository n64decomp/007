#include <ultra64.h>
#include "unk_0C0A70.h"
#include "debugmenu.h"

/**
* Used in speedGraphDisplay to check if speedgraphframes and g_speedGraphCountAccumulator are
* over the threshold for output.
*/
#define COUNT_REQUIRED_FOR_OUTPUT 20

/**
 * Used in speedGraphDisplay to calculate display Hz.
 */
#ifdef REFRESH_PAL
#define VICLOCK 50
#else
#define VICLOCK 60
#endif

#if defined(LEFTOVERDEBUG)
s32 dword_CODE_bss_8005F3F0[3];
Gfx g_speedGraphDisplayList[2][266];
s32 g_speedGraphDisplayListBank;
u32 g_speedGraphLastOsCount;
u32 g_speedGraphCurrentOsCount;
u32 dword_CODE_bss_800604AC;
#endif

typedef struct {
    u32 unk0;
    u32 osCount;
} unknown_s;

#if defined(LEFTOVERDEBUG)
unknown_s dword_CODE_bss_800604B0[3][32];
s32 dword_CODE_bss_800607B0[3];
s32 dword_CODE_bss_800607C0[3];
s32 dword_CODE_bss_800607D0[3];

#endif
s32 D_800231D0 = 0;

typedef struct {
    s32 color;
    s32 unk4;
    s32 unk8;
    s32 unkC;
} s_800231D4;

#if defined(LEFTOVERDEBUG)
s_800231D4 D_800231D4[5] = {
    {0x00000000, 0x00000000, 0x00000002, 0x00000000},
    {0x00000001, 0x00000000, 0x00000002, 0x00000000},
    {0x00000002, 0xFF000000, 0x00000002, 0x00000000},
    {0x00000003, 0x00009200, 0x00000004, 0xFFFFFFFF},
    {0x00000004, 0xDB000000, 0x00000004, 0xFFFFFFFF}
};

/**
 * 80023224. Seems to accumulate speedgraphframes in speedGraphDisplay. Once above the threshold COUNT_REQUIRED_FOR_OUTPUT,
 * the value COUNT_REQUIRED_FOR_OUTPUT is repeatedly subtracted until below the threshold.
 */
u32 g_speedGraphCountAccumulator = 0;

/**
 * 80023228. Stores max value of speedgraphframes seen in speedGraphDisplay. Resets to zero once
 * output is rendered.
 */
s32 g_speedGraphMaxSeenCount = 0;

/**
 * 8002322C.
 */
s32 D_8002322C = 0;

/**
 * 80023230.
 */
u32 g_speedGraphCounterForFrames = 0;

/**
 * 80023234.
 */
s32 D_80023234 = 1;

#endif

// forward declarations
void speedGraphVideoRelated_2(void);

int sprintf(char *dst, const char *fmt, ...);
u32 *get_counters(void);
/////

void speedGraphDisplayListRelated(void)
{
    #if defined(LEFTOVERDEBUG)
    s32 i;

    gSPEndDisplayList(g_speedGraphDisplayList[0]);
    gSPEndDisplayList(g_speedGraphDisplayList[1]);
    g_speedGraphDisplayListBank = 0;

    for (i = 0; i < 3; i++)
    {
        dword_CODE_bss_800607B0[i] = 0;
        dword_CODE_bss_800607D0[i] = 1;
    }

    speedGraphVideoRelated_2();
    #endif
}

void speedGraphVideoRelated_1(void) {
    #if defined(LEFTOVERDEBUG)
    s32 i;

    g_speedGraphCurrentOsCount = osGetCount();

    for (i = 0; i < 3; i++)
    {        
        dword_CODE_bss_800607C0[i] = ((dword_CODE_bss_800607D0[i] + 31) % 32);
    }
    #endif
}

void speedGraphVideoRelated_2(void) {
    #if defined(LEFTOVERDEBUG)
    s32 i;

    g_speedGraphLastOsCount = g_speedGraphCurrentOsCount;

    for (i = 0; i < 3; i++)
    {
        dword_CODE_bss_800607B0[i] = dword_CODE_bss_800607C0[i];
    }
    #endif
}

#if defined(LEFTOVERDEBUG)
void profileSetMarker(s32 arg0)
{
    s32 index;
    s32 mf;
    OSIntMask mask;
    s32 index2;
    unknown_s *pp;

    index = arg0 & 0xFFFF;
    mask = osSetIntMask(OS_IM_NONE);
    mf = arg0 >> 16;
    index2 = dword_CODE_bss_800607D0[index];

    if (mf == 3)
    {
        // set highest bit
        mf = dword_CODE_bss_8005F3F0[index] | 0x8000;
    }
    else if (mf == 6)
    {
        // clear highest bit
        mf = dword_CODE_bss_8005F3F0[index] & 0x7FFF;
    }

    pp = &dword_CODE_bss_800604B0[index][index2];
    pp->unk0 = mf;
    pp->osCount = osGetCount();
    dword_CODE_bss_8005F3F0[index] = mf;

    index2++;
    
    if (index2 >= 32)
    {
        index2 = 0;
    }

    dword_CODE_bss_800607D0[index] = index2;

    osSetIntMask(mask);
}
#else
void profileSetMarker(void)
{
}
#endif

Gfx *speedGraphDisplay(Gfx *gdl)
{
    #if defined(LEFTOVERDEBUG)
    u32 *counters;
    u32 localCountAccumulator = g_speedGraphCountAccumulator;
    s32 *pmaxSeenCount = &g_speedGraphMaxSeenCount;
    char buffer[12];
    volatile u32 *pcountAccumulator = &g_speedGraphCountAccumulator;
    
    localCountAccumulator += speedgraphframes;

    if (*pmaxSeenCount < speedgraphframes)
    {
        *pmaxSeenCount = speedgraphframes;
    }

    *pcountAccumulator = localCountAccumulator;
    
    if (localCountAccumulator > COUNT_REQUIRED_FOR_OUTPUT)
    {
        *pcountAccumulator = localCountAccumulator;

        if (localCountAccumulator > COUNT_REQUIRED_FOR_OUTPUT)
        {
            do
            {
                localCountAccumulator -= COUNT_REQUIRED_FOR_OUTPUT;
            }
            while (localCountAccumulator > COUNT_REQUIRED_FOR_OUTPUT);

            *pcountAccumulator = localCountAccumulator;
        }
        
        counters = get_counters();

        debmenuSetFgColour(255, 255, 255, 255);
        debmenuSetEnvColor(0, 0, 0, 255);

        // utz %
        debmenuSetPos(8, 5);
        sprintf(buffer, "utz %2.0f%%\n", (((counters[1] - counters[3]) * 100.0f) / counters[0]));
        debmenuPrintString(buffer);

        // rsp %
        debmenuSetPos(8, 6);
        sprintf(buffer, "rsp %2.0f%%\n", (((counters[0] - counters[1]) * 100.0f) / counters[0]));
        debmenuPrintString(buffer);

        // tex %
        debmenuSetPos(8, 7);
        sprintf(buffer, "tex %2.0f%%", ((counters[3] * 100.0f) / counters[0]));
        debmenuPrintString(buffer);

        // hz (60 / framerate)
        // -- or 50 for PAL
        debmenuSetPos(28, 5);
        sprintf(buffer, "%2d hz", ((speedgraphframes == 0) ? 0 : (VICLOCK / speedgraphframes)));
        debmenuPrintString(buffer);

        // framerate
        debmenuSetPos(28, 6);
        sprintf(buffer, "%2d frames", speedgraphframes);
        debmenuPrintString(buffer);

        // (continues framerate output)
        if (speedgraphframes != g_speedGraphMaxSeenCount)
        {
            sprintf(buffer, " [%2d]", *pmaxSeenCount);
        }
        else
        {
            sprintf(buffer, "     ");
        }

        debmenuPrintString(buffer);
        
        g_speedGraphMaxSeenCount = 0;
    }

    gSPDisplayList(gdl++, g_speedGraphDisplayList[g_speedGraphDisplayListBank ^ 1]);

    return gdl;
    #endif
}

#ifdef NONMATCHING
Gfx *sub_GAME_7F0D1AC0(Gfx *gdl);
void sub_GAME_7F0D1DCC(f32 arg0);
Gfx *sub_GAME_7F0D1BD0(Gfx *gdl, f32 arg1, s32 r, s32 g, s32 b, s32 arg5, s32 arg6);
void sub_GAME_7F0D2320(void);
Gfx *sub_GAME_7F0D1E98(Gfx *gdl, s32 r, s32 g, s32 b);
void video_DL_related_4(void) {
    g_speedGraphCounterForFrames += speedgraphframes;
    if (g_speedGraphCounterForFrames > 200) {
        g_speedGraphCounterForFrames -= 200;
        D_80023234 ^= 1;
    }
    if (D_80023234 != (D_8002322C++ & 1)) {
        s32 spAC[3];
        s32 spA0[3];
        Gfx *gdl = sub_GAME_7F0D1AC0(g_speedGraphDisplayList[g_speedGraphDisplayListBank]);
        s32 i;
        for (i = 0; i < 3; i++) {
            spAC[i] = 0;
        }
        for (i = 0; i < 3; i++) {
            spA0[i] = g_speedGraphLastOsCount;
        }
        for (i = 0; i < 3; i++) {
            s32 var1 = dword_CODE_bss_800607B0[i];
            while (var1 != dword_CODE_bss_800607D0[i]) {
                s32 phi_v1;
                s32 phi_s2 = dword_CODE_bss_800604B0[i][var1].unk0;
                if (phi_s2 & 0x8000) {
                    phi_s2 = 3;
                }
                phi_v1 = spA0[i];
                if (spA0[i] < g_speedGraphLastOsCount) {
                    phi_v1 = g_speedGraphLastOsCount;
                }
                if (dword_CODE_bss_800604B0[i][var1].osCount >= g_speedGraphLastOsCount) {
                    if (dword_CODE_bss_800604B0[i][var1].osCount >= phi_v1) {
                        f32 temp_f12;
                        if ((spAC[i] != 1) && (spAC[i] != 3) && ((spAC[i] & 0x8000) == 0)) {
                            temp_f12 = (dword_CODE_bss_800604B0[i][var1].osCount - phi_v1) / 775875.0f;
                        }
                        if (spAC[i] == 1) {
                            sub_GAME_7F0D1DCC(temp_f12);
                        } else {
                            s_800231D4 *temp = &D_800231D4[spAC[i]];
                            sub_GAME_7F0D1BD0(gdl++, temp_f12, ((temp->color >> 0x18) & 0xFF), ((temp->color >> 0x10) & 0xFF), ((temp->color >> 0x8) & 0xFF), temp->unk8, temp->unkC);
                        }
                        gDPPipeSync(gdl++);
                    }
                }
                spAC[i] = phi_s2;
                spA0[i] = dword_CODE_bss_800604B0[i][var1].osCount;
                var1 = ((var1 + 1) % 32);
            }
            if (i < 2) {
                sub_GAME_7F0D2320();
            }
        }
        gdl = sub_GAME_7F0D1E98(gdl++, 0, 0, 0);
        gDPPipeSync(gdl++);
        gSPEndDisplayList(gdl);
        g_speedGraphDisplayListBank ^= 1;
    }
}
#else
#if defined(LEFTOVERDEBUG)
GLOBAL_ASM(
.late_rodata
glabel aIL0
/* "I=l0"; // 775875.0f */
.word 0x493d6c30
.word 0
.text
glabel video_DL_related_4
/* 0038D8 70002CD8 27BDFF30 */  addiu $sp, $sp, -0xd0
/* 0038DC 70002CDC 3C028002 */  lui   $v0, %hi(g_speedGraphCounterForFrames)
/* 0038E0 70002CE0 3C0E8005 */  lui   $t6, %hi(speedgraphframes) 
/* 0038E4 70002CE4 8C423230 */  lw    $v0, %lo(g_speedGraphCounterForFrames)($v0)
/* 0038E8 70002CE8 8DCE8498 */  lw    $t6, %lo(speedgraphframes)($t6)
/* 0038EC 70002CEC 3C018002 */  lui   $at, %hi(g_speedGraphCounterForFrames)
/* 0038F0 70002CF0 AFBF005C */  sw    $ra, 0x5c($sp)
/* 0038F4 70002CF4 004E1021 */  addu  $v0, $v0, $t6
/* 0038F8 70002CF8 AC223230 */  sw    $v0, %lo(g_speedGraphCounterForFrames)($at)
/* 0038FC 70002CFC 2C4100C9 */  sltiu $at, $v0, 0xc9
/* 003900 70002D00 AFBE0058 */  sw    $fp, 0x58($sp)
/* 003904 70002D04 AFB70054 */  sw    $s7, 0x54($sp)
/* 003908 70002D08 AFB60050 */  sw    $s6, 0x50($sp)
/* 00390C 70002D0C AFB5004C */  sw    $s5, 0x4c($sp)
/* 003910 70002D10 AFB40048 */  sw    $s4, 0x48($sp)
/* 003914 70002D14 AFB30044 */  sw    $s3, 0x44($sp)
/* 003918 70002D18 AFB20040 */  sw    $s2, 0x40($sp)
/* 00391C 70002D1C AFB1003C */  sw    $s1, 0x3c($sp)
/* 003920 70002D20 AFB00038 */  sw    $s0, 0x38($sp)
/* 003924 70002D24 F7B60030 */  sdc1  $f22, 0x30($sp)
/* 003928 70002D28 14200009 */  bnez  $at, .L70002D50
/* 00392C 70002D2C F7B40028 */   sdc1  $f20, 0x28($sp)
/* 003930 70002D30 3C0F8002 */  lui   $t7, %hi(D_80023234) 
/* 003934 70002D34 8DEF3234 */  lw    $t7, %lo(D_80023234)($t7)
/* 003938 70002D38 3C018002 */  lui   $at, %hi(D_80023234)
/* 00393C 70002D3C 2442FF38 */  addiu $v0, $v0, -0xc8
/* 003940 70002D40 39F80001 */  xori  $t8, $t7, 1
/* 003944 70002D44 AC383234 */  sw    $t8, %lo(D_80023234)($at)
/* 003948 70002D48 3C018002 */  lui   $at, %hi(g_speedGraphCounterForFrames)
/* 00394C 70002D4C AC223230 */  sw    $v0, %lo(g_speedGraphCounterForFrames)($at)
.L70002D50:
/* 003950 70002D50 3C038002 */  lui   $v1, %hi(D_8002322C)
/* 003954 70002D54 8C63322C */  lw    $v1, %lo(D_8002322C)($v1)
/* 003958 70002D58 3C198002 */  lui   $t9, %hi(D_80023234) 
/* 00395C 70002D5C 8F393234 */  lw    $t9, %lo(D_80023234)($t9)
/* 003960 70002D60 30690001 */  andi  $t1, $v1, 1
/* 003964 70002D64 3C018002 */  lui   $at, %hi(D_8002322C)
/* 003968 70002D68 24630001 */  addiu $v1, $v1, 1
/* 00396C 70002D6C 132900AD */  beq   $t9, $t1, .L70003024
/* 003970 70002D70 AC23322C */   sw    $v1, %lo(D_8002322C)($at)
/* 003974 70002D74 3C0A8006 */  lui   $t2, %hi(g_speedGraphDisplayListBank) 
/* 003978 70002D78 8D4A04A0 */  lw    $t2, %lo(g_speedGraphDisplayListBank)($t2)
/* 00397C 70002D7C 3C0C8006 */  lui   $t4, %hi(g_speedGraphDisplayList) 
/* 003980 70002D80 258CF400 */  addiu $t4, %lo(g_speedGraphDisplayList) # addiu $t4, $t4, -0xc00
/* 003984 70002D84 000A5940 */  sll   $t3, $t2, 5
/* 003988 70002D88 016A5821 */  addu  $t3, $t3, $t2
/* 00398C 70002D8C 000B5880 */  sll   $t3, $t3, 2
/* 003990 70002D90 016A5821 */  addu  $t3, $t3, $t2
/* 003994 70002D94 000B5900 */  sll   $t3, $t3, 4
/* 003998 70002D98 0FC346B0 */  jal   sub_GAME_7F0D1AC0
/* 00399C 70002D9C 016C2021 */   addu  $a0, $t3, $t4
/* 0039A0 70002DA0 00409825 */  move  $s3, $v0
/* 0039A4 70002DA4 27A200B8 */  addiu $v0, $sp, 0xb8
/* 0039A8 70002DA8 27B400AC */  addiu $s4, $sp, 0xac
.L70002DAC:
/* 0039AC 70002DAC 26940004 */  addiu $s4, $s4, 4
/* 0039B0 70002DB0 0282082B */  sltu  $at, $s4, $v0
/* 0039B4 70002DB4 1420FFFD */  bnez  $at, .L70002DAC
/* 0039B8 70002DB8 AE80FFFC */   sw    $zero, -4($s4)
/* 0039BC 70002DBC 3C048006 */  lui   $a0, %hi(g_speedGraphLastOsCount)
/* 0039C0 70002DC0 8C8404A4 */  lw    $a0, %lo(g_speedGraphLastOsCount)($a0)
/* 0039C4 70002DC4 27B500A0 */  addiu $s5, $sp, 0xa0
/* 0039C8 70002DC8 27A200AC */  addiu $v0, $sp, 0xac
.L70002DCC:
/* 0039CC 70002DCC 26B50004 */  addiu $s5, $s5, 4
/* 0039D0 70002DD0 02A2082B */  sltu  $at, $s5, $v0
/* 0039D4 70002DD4 1420FFFD */  bnez  $at, .L70002DCC
/* 0039D8 70002DD8 AEA4FFFC */   sw    $a0, -4($s5)
/* 0039DC 70002DDC 3C0D8006 */  lui   $t5, %hi(dword_CODE_bss_800607B0) 
/* 0039E0 70002DE0 25AD07B0 */  addiu $t5, %lo(dword_CODE_bss_800607B0) # addiu $t5, $t5, 0x7b0
/* 0039E4 70002DE4 3C1E8006 */  lui   $fp, %hi(dword_CODE_bss_800607D0) 
/* 0039E8 70002DE8 3C018003 */  lui   $at, %hi(aIL0)
/* 0039EC 70002DEC C4368470 */  lwc1  $f22, %lo(aIL0)($at)
/* 0039F0 70002DF0 27DE07D0 */  addiu $fp, %lo(dword_CODE_bss_800607D0) # addiu $fp, $fp, 0x7d0
/* 0039F4 70002DF4 AFAD0070 */  sw    $t5, 0x70($sp)
/* 0039F8 70002DF8 AFA000C8 */  sw    $zero, 0xc8($sp)
/* 0039FC 70002DFC AFA00080 */  sw    $zero, 0x80($sp)
/* 003A00 70002E00 24160001 */  li    $s6, 1
.L70002E04:
/* 003A04 70002E04 8FAE0070 */  lw    $t6, 0x70($sp)
/* 003A08 70002E08 8FC50000 */  lw    $a1, ($fp)
/* 003A0C 70002E0C 8FAF0080 */  lw    $t7, 0x80($sp)
/* 003A10 70002E10 8DD10000 */  lw    $s1, ($t6)
/* 003A14 70002E14 4480A000 */  mtc1  $zero, $f20
/* 003A18 70002E18 27B800AC */  addiu $t8, $sp, 0xac
/* 003A1C 70002E1C 1225005F */  beq   $s1, $a1, .L70002F9C
/* 003A20 70002E20 01F8A021 */   addu  $s4, $t7, $t8
/* 003A24 70002E24 8FA900C8 */  lw    $t1, 0xc8($sp)
/* 003A28 70002E28 3C0B8006 */  lui   $t3, %hi(dword_CODE_bss_800604B0) 
/* 003A2C 70002E2C 256B04B0 */  addiu $t3, %lo(dword_CODE_bss_800604B0) # addiu $t3, $t3, 0x4b0
/* 003A30 70002E30 27B900A0 */  addiu $t9, $sp, 0xa0
/* 003A34 70002E34 00095200 */  sll   $t2, $t1, 8
/* 003A38 70002E38 014BB821 */  addu  $s7, $t2, $t3
/* 003A3C 70002E3C 01F9A821 */  addu  $s5, $t7, $t9
.L70002E40:
/* 003A40 70002E40 001160C0 */  sll   $t4, $s1, 3
/* 003A44 70002E44 02EC1021 */  addu  $v0, $s7, $t4
/* 003A48 70002E48 8C520000 */  lw    $s2, ($v0)
/* 003A4C 70002E4C 3C048006 */  lui   $a0, %hi(g_speedGraphLastOsCount)
/* 003A50 70002E50 8C8404A4 */  lw    $a0, %lo(g_speedGraphLastOsCount)($a0)
/* 003A54 70002E54 324D8000 */  andi  $t5, $s2, 0x8000
/* 003A58 70002E58 51A00003 */  beql  $t5, $zero, .L70002E68
/* 003A5C 70002E5C 8EA30000 */   lw    $v1, ($s5)
/* 003A60 70002E60 24120003 */  li    $s2, 3
/* 003A64 70002E64 8EA30000 */  lw    $v1, ($s5)
.L70002E68:
/* 003A68 70002E68 8C500004 */  lw    $s0, 4($v0)
/* 003A6C 70002E6C 0064082B */  sltu  $at, $v1, $a0
/* 003A70 70002E70 50200003 */  beql  $at, $zero, .L70002E80
/* 003A74 70002E74 0204082B */   sltu  $at, $s0, $a0
/* 003A78 70002E78 00801825 */  move  $v1, $a0
/* 003A7C 70002E7C 0204082B */  sltu  $at, $s0, $a0
.L70002E80:
/* 003A80 70002E80 1420003C */  bnez  $at, .L70002F74
/* 003A84 70002E84 0203082B */   sltu  $at, $s0, $v1
/* 003A88 70002E88 1420003A */  bnez  $at, .L70002F74
/* 003A8C 70002E8C 3C198002 */   lui   $t9, %hi(D_800231D4) 
/* 003A90 70002E90 8E820000 */  lw    $v0, ($s4)
/* 003A94 70002E94 273931D4 */  addiu $t9, %lo(D_800231D4) # addiu $t9, $t9, 0x31d4
/* 003A98 70002E98 02034823 */  subu  $t1, $s0, $v1
/* 003A9C 70002E9C 12C2000F */  beq   $s6, $v0, .L70002EDC
/* 003AA0 70002EA0 00027900 */   sll   $t7, $v0, 4
/* 003AA4 70002EA4 24010003 */  li    $at, 3
/* 003AA8 70002EA8 1041000C */  beq   $v0, $at, .L70002EDC
/* 003AAC 70002EAC 304E8000 */   andi  $t6, $v0, 0x8000
/* 003AB0 70002EB0 15C0000A */  bnez  $t6, .L70002EDC
/* 003AB4 70002EB4 0203C023 */   subu  $t8, $s0, $v1
/* 003AB8 70002EB8 44982000 */  mtc1  $t8, $f4
/* 003ABC 70002EBC 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 003AC0 70002EC0 07010004 */  bgez  $t8, .L70002ED4
/* 003AC4 70002EC4 468021A0 */   cvt.s.w $f6, $f4
/* 003AC8 70002EC8 44814000 */  mtc1  $at, $f8
/* 003ACC 70002ECC 00000000 */  nop   
/* 003AD0 70002ED0 46083180 */  add.s $f6, $f6, $f8
.L70002ED4:
/* 003AD4 70002ED4 46163283 */  div.s $f10, $f6, $f22
/* 003AD8 70002ED8 460AA500 */  add.s $f20, $f20, $f10
.L70002EDC:
/* 003ADC 70002EDC 44898000 */  mtc1  $t1, $f16
/* 003AE0 70002EE0 01F94021 */  addu  $t0, $t7, $t9
/* 003AE4 70002EE4 05210005 */  bgez  $t1, .L70002EFC
/* 003AE8 70002EE8 468084A0 */   cvt.s.w $f18, $f16
/* 003AEC 70002EEC 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 003AF0 70002EF0 44812000 */  mtc1  $at, $f4
/* 003AF4 70002EF4 00000000 */  nop   
/* 003AF8 70002EF8 46049480 */  add.s $f18, $f18, $f4
.L70002EFC:
/* 003AFC 70002EFC 16C20005 */  bne   $s6, $v0, .L70002F14
/* 003B00 70002F00 46169303 */   div.s $f12, $f18, $f22
/* 003B04 70002F04 0FC34773 */  jal   sub_GAME_7F0D1DCC
/* 003B08 70002F08 00000000 */   nop   
/* 003B0C 70002F0C 10000014 */  b     .L70002F60
/* 003B10 70002F10 02601025 */   move  $v0, $s3
.L70002F14:
/* 003B14 70002F14 8D020004 */  lw    $v0, 4($t0)
/* 003B18 70002F18 44056000 */  mfc1  $a1, $f12
/* 003B1C 70002F1C 02602025 */  move  $a0, $s3
/* 003B20 70002F20 00026203 */  sra   $t4, $v0, 8
/* 003B24 70002F24 318D00FF */  andi  $t5, $t4, 0xff
/* 003B28 70002F28 AFAD0010 */  sw    $t5, 0x10($sp)
/* 003B2C 70002F2C 8D0E0008 */  lw    $t6, 8($t0)
/* 003B30 70002F30 00023603 */  sra   $a2, $v0, 0x18
/* 003B34 70002F34 00023C03 */  sra   $a3, $v0, 0x10
/* 003B38 70002F38 AFAE0014 */  sw    $t6, 0x14($sp)
/* 003B3C 70002F3C 8D18000C */  lw    $t8, 0xc($t0)
/* 003B40 70002F40 30EB00FF */  andi  $t3, $a3, 0xff
/* 003B44 70002F44 30CA00FF */  andi  $t2, $a2, 0xff
/* 003B48 70002F48 01403025 */  move  $a2, $t2
/* 003B4C 70002F4C 01603825 */  move  $a3, $t3
/* 003B50 70002F50 0FC346F4 */  jal   sub_GAME_7F0D1BD0
/* 003B54 70002F54 AFB80018 */   sw    $t8, 0x18($sp)
/* 003B58 70002F58 00409825 */  move  $s3, $v0
/* 003B5C 70002F5C 02601025 */  move  $v0, $s3
.L70002F60:
/* 003B60 70002F60 3C0FE700 */  lui   $t7, 0xe700
/* 003B64 70002F64 AC4F0000 */  sw    $t7, ($v0)
/* 003B68 70002F68 AC400004 */  sw    $zero, 4($v0)
/* 003B6C 70002F6C 26730008 */  addiu $s3, $s3, 8
/* 003B70 70002F70 8FC50000 */  lw    $a1, ($fp)
.L70002F74:
/* 003B74 70002F74 26310001 */  addiu $s1, $s1, 1
/* 003B78 70002F78 AE920000 */  sw    $s2, ($s4)
/* 003B7C 70002F7C AEB00000 */  sw    $s0, ($s5)
/* 003B80 70002F80 06210004 */  bgez  $s1, .L70002F94
/* 003B84 70002F84 3239001F */   andi  $t9, $s1, 0x1f
/* 003B88 70002F88 13200002 */  beqz  $t9, .L70002F94
/* 003B8C 70002F8C 00000000 */   nop   
/* 003B90 70002F90 2739FFE0 */  addiu $t9, $t9, -0x20
.L70002F94:
/* 003B94 70002F94 1725FFAA */  bne   $t9, $a1, .L70002E40
/* 003B98 70002F98 03208825 */   move  $s1, $t9
.L70002F9C:
/* 003B9C 70002F9C 8FA900C8 */  lw    $t1, 0xc8($sp)
/* 003BA0 70002FA0 29210002 */  slti  $at, $t1, 2
/* 003BA4 70002FA4 50200004 */  beql  $at, $zero, .L70002FB8
/* 003BA8 70002FA8 8FAA00C8 */   lw    $t2, 0xc8($sp)
/* 003BAC 70002FAC 0FC348C8 */  jal   sub_GAME_7F0D2320
/* 003BB0 70002FB0 00000000 */   nop   
/* 003BB4 70002FB4 8FAA00C8 */  lw    $t2, 0xc8($sp)
.L70002FB8:
/* 003BB8 70002FB8 8FAC0080 */  lw    $t4, 0x80($sp)
/* 003BBC 70002FBC 8FAE0070 */  lw    $t6, 0x70($sp)
/* 003BC0 70002FC0 24010003 */  li    $at, 3
/* 003BC4 70002FC4 254B0001 */  addiu $t3, $t2, 1
/* 003BC8 70002FC8 258D0004 */  addiu $t5, $t4, 4
/* 003BCC 70002FCC 25D80004 */  addiu $t8, $t6, 4
/* 003BD0 70002FD0 AFB80070 */  sw    $t8, 0x70($sp)
/* 003BD4 70002FD4 AFAD0080 */  sw    $t5, 0x80($sp)
/* 003BD8 70002FD8 AFAB00C8 */  sw    $t3, 0xc8($sp)
/* 003BDC 70002FDC 1561FF89 */  bne   $t3, $at, .L70002E04
/* 003BE0 70002FE0 27DE0004 */   addiu $fp, $fp, 4
/* 003BE4 70002FE4 02602025 */  move  $a0, $s3
/* 003BE8 70002FE8 00002825 */  move  $a1, $zero
/* 003BEC 70002FEC 00003025 */  move  $a2, $zero
/* 003BF0 70002FF0 0FC347A6 */  jal   sub_GAME_7F0D1E98
/* 003BF4 70002FF4 00003825 */   move  $a3, $zero
/* 003BF8 70002FF8 3C038006 */  lui   $v1, %hi(g_speedGraphDisplayListBank)
/* 003BFC 70002FFC 3C0FE700 */  lui   $t7, 0xe700
/* 003C00 70003000 3C19B800 */  lui   $t9, 0xb800
/* 003C04 70003004 246304A0 */  addiu $v1, %lo(g_speedGraphDisplayListBank) # addiu $v1, $v1, 0x4a0
/* 003C08 70003008 AC4F0000 */  sw    $t7, ($v0)
/* 003C0C 7000300C AC400004 */  sw    $zero, 4($v0)
/* 003C10 70003010 AC590008 */  sw    $t9, 8($v0)
/* 003C14 70003014 AC40000C */  sw    $zero, 0xc($v0)
/* 003C18 70003018 8C690000 */  lw    $t1, ($v1)
/* 003C1C 7000301C 392A0001 */  xori  $t2, $t1, 1
/* 003C20 70003020 AC6A0000 */  sw    $t2, ($v1)
.L70003024:
/* 003C24 70003024 8FBF005C */  lw    $ra, 0x5c($sp)
/* 003C28 70003028 D7B40028 */  ldc1  $f20, 0x28($sp)
/* 003C2C 7000302C D7B60030 */  ldc1  $f22, 0x30($sp)
/* 003C30 70003030 8FB00038 */  lw    $s0, 0x38($sp)
/* 003C34 70003034 8FB1003C */  lw    $s1, 0x3c($sp)
/* 003C38 70003038 8FB20040 */  lw    $s2, 0x40($sp)
/* 003C3C 7000303C 8FB30044 */  lw    $s3, 0x44($sp)
/* 003C40 70003040 8FB40048 */  lw    $s4, 0x48($sp)
/* 003C44 70003044 8FB5004C */  lw    $s5, 0x4c($sp)
/* 003C48 70003048 8FB60050 */  lw    $s6, 0x50($sp)
/* 003C4C 7000304C 8FB70054 */  lw    $s7, 0x54($sp)
/* 003C50 70003050 8FBE0058 */  lw    $fp, 0x58($sp)
/* 003C54 70003054 03E00008 */  jr    $ra
/* 003C58 70003058 27BD00D0 */   addiu $sp, $sp, 0xd0
)
#else
Gfx* video_DL_related_4(Gfx* param_1)
{
  return param_1;
}
#endif
#endif
