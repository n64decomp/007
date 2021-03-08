//FIXME i still need all sorts of love
#include "ultra64.h"
#include "vi.h"
#include "video.h"
#include "bondgame.h"
#include "unk_093880.h" // pPlayer
#include "sched.h"
#include "rsp.h"
#include "libultra/os.h"

/**
 * @file video.c
 * This file contains video handling code. 
 */


//data
u32 D_80023240 = 0;
struct video_settings video1_settings[] = 
{
    {0, 0, 0, 0, 320, 240, 60.0f, 1.3333334f, 30.0f, 10000.0f, 320, 240, 320, 240, 0, 0, 1, 0},
    {0, 0, 0, 0, 320, 240, 60.0f, 1.3333334f, 30.0f, 10000.0f, 320, 240, 320, 240, 0, 0, 1, 0}
};
s32 D_8002329C = 0;
s32 D_800232A0 = 0;
video_settings *ptr_video_settings1 = &video1_settings[0];
video_settings *ptr_video_settings2 = &video1_settings[0];
s32 coloroutputmode = 1;
s32 D_800232B0 = 1;
s32 D_800232B4 = 0;
s32 D_800232B8 = 0;
s32 D_800232BC = 3;
s32 D_800232C0 = 0;
s32 jpg_16bit_grabnum = 1;
s32 jpg_32bit_grabnum = 1;
s32 rgb_16bit_grabnum = 1;
s32 rgb_32bit_grabnum = 1;

//rodata

//bss
f32 projectionMatrixF[4][4];
Mtx *projectionMatrix;
u16 perspNorm;
OSViMode dword_CODE_bss_80060828;
u8 off_CODE_bss_80060878;
u8 off_CODE_bss_80060879;
OSViMode *viMode;
u32 dword_CODE_bss_80060880;
u32 dword_CODE_bss_80060884;
u32 dword_CODE_bss_80060888;
s32 dword_CODE_bss_8006088C;
/**
 * 3C60	70003060
 */
#ifdef NONMATCHING
// regalloc
void init_video_settings(void)
{
    video_settings* v1;
    video_settings* v2;
    off_CODE_bss_80060878 = 0;
    off_CODE_bss_80060879 = 1;
    v1 = &video1_settings[off_CODE_bss_80060878];
    ptr_video_settings1 = v1;
    ptr_video_settings1->framebuf = cfb_16[off_CODE_bss_80060878];    
    v2 = &video1_settings[off_CODE_bss_80060879];
    ptr_video_settings2 = v2;
    ptr_video_settings2->framebuf = cfb_16[off_CODE_bss_80060879];
    D_8002329C = 0;
    D_800232A0 = 0;
}
#else
GLOBAL_ASM(
.text
glabel init_video_settings
/* 003C60 70003060 2408002C */  li    $t0, 44
/* 003C64 70003064 300200FF */  andi  $v0, $zero, 0xff
/* 003C68 70003068 00480019 */  multu $v0, $t0
/* 003C6C 7000306C 0002C880 */  sll   $t9, $v0, 2
/* 003C70 70003070 0322C821 */  addu  $t9, $t9, $v0
/* 003C74 70003074 0019C880 */  sll   $t9, $t9, 2
/* 003C78 70003078 0322C823 */  subu  $t9, $t9, $v0
/* 003C7C 7000307C 3C078002 */  lui   $a3, %hi(video1_settings)
/* 003C80 70003080 0019C880 */  sll   $t9, $t9, 2
/* 003C84 70003084 24E73244 */  addiu $a3, %lo(video1_settings) # addiu $a3, $a3, 0x3244
/* 003C88 70003088 3C048006 */  lui   $a0, %hi(off_CODE_bss_80060878)
/* 003C8C 7000308C 3C058006 */  lui   $a1, %hi(off_CODE_bss_80060879)
/* 003C90 70003090 00007812 */  mflo  $t7
/* 003C94 70003094 3C068002 */  lui   $a2, %hi(ptr_video_settings1)
/* 003C98 70003098 3C09803B */  lui   $t1, %hi(cfb_16) # $t1, 0x803b
/* 003C9C 7000309C 0322C823 */  subu  $t9, $t9, $v0
/* 003CA0 700030A0 25295000 */  addiu $t1, %lo(cfb_16) # addiu $t1, $t1, 0x5000
/* 003CA4 700030A4 24C632A4 */  addiu $a2, %lo(ptr_video_settings1) # addiu $a2, $a2, 0x32a4
/* 003CA8 700030A8 24A50879 */  addiu $a1, %lo(off_CODE_bss_80060879) # addiu $a1, $a1, 0x879
/* 003CAC 700030AC 24840878 */  addiu $a0, %lo(off_CODE_bss_80060878) # addiu $a0, $a0, 0x878
/* 003CB0 700030B0 240E0001 */  li    $t6, 1
/* 003CB4 700030B4 00EFC021 */  addu  $t8, $a3, $t7
/* 003CB8 700030B8 0019CAC0 */  sll   $t9, $t9, 0xb
/* 003CBC 700030BC A0800000 */  sb    $zero, ($a0)
/* 003CC0 700030C0 A0AE0000 */  sb    $t6, ($a1)
/* 003CC4 700030C4 ACD80000 */  sw    $t8, ($a2)
/* 003CC8 700030C8 01395821 */  addu  $t3, $t1, $t9
/* 003CCC 700030CC AF0B0028 */  sw    $t3, 0x28($t8)
/* 003CD0 700030D0 90A30000 */  lbu   $v1, ($a1)
/* 003CD4 700030D4 3C0A8002 */  lui   $t2, %hi(ptr_video_settings2) 
/* 003CD8 700030D8 254A32A8 */  addiu $t2, %lo(ptr_video_settings2) # addiu $t2, $t2, 0x32a8
/* 003CDC 700030DC 00680019 */  multu $v1, $t0
/* 003CE0 700030E0 00037880 */  sll   $t7, $v1, 2
/* 003CE4 700030E4 01E37821 */  addu  $t7, $t7, $v1
/* 003CE8 700030E8 000F7880 */  sll   $t7, $t7, 2
/* 003CEC 700030EC 01E37823 */  subu  $t7, $t7, $v1
/* 003CF0 700030F0 000F7880 */  sll   $t7, $t7, 2
/* 003CF4 700030F4 01E37823 */  subu  $t7, $t7, $v1
/* 003CF8 700030F8 000F7AC0 */  sll   $t7, $t7, 0xb
/* 003CFC 700030FC 012FC021 */  addu  $t8, $t1, $t7
/* 003D00 70003100 3C018002 */  lui   $at, %hi(D_8002329C)
/* 003D04 70003104 00006812 */  mflo  $t5
/* 003D08 70003108 00ED7021 */  addu  $t6, $a3, $t5
/* 003D0C 7000310C AD4E0000 */  sw    $t6, ($t2)
/* 003D10 70003110 ADD80028 */  sw    $t8, 0x28($t6)
/* 003D14 70003114 AC20329C */  sw    $zero, %lo(D_8002329C)($at)
/* 003D18 70003118 3C018002 */  lui   $at, %hi(D_800232A0)
/* 003D1C 7000311C 03E00008 */  jr    $ra
/* 003D20 70003120 AC2032A0 */   sw    $zero, %lo(D_800232A0)($at)
)
#endif

void viInitBuffers(void)
{
    s32 i;
    u8* p1 = cfb_16[0];
    u8* p2 = cfb_16[1];
    zbufDeallocate();
    for (i = 0; i < 320*240*2; i++) {
        p1[i] = 0;
        p2[i] = 0;
    }
}

void viSet800232BC(s32 arg0)
{
    arg0 += 2;
    D_800232BC = arg0;
}

/**
 * 3DA0	700031A0
 */
#ifdef NONMATCHING
// regalloc
void video_related_7(void) {
    s32 temp_lo;
    if (D_800232B8 != 0) {
        D_800232B8--;
        if (D_800232B8 == 0) {
            D_800232B4 = 0;
        }
    }
    temp_lo = D_800232B0 * D_800232B4;
    viMode->fldRegs[0].vStart = (((dword_CODE_bss_80060884 >> 16) + temp_lo) << 16) | ((dword_CODE_bss_80060884 + temp_lo) & 0xffff);
    viMode->fldRegs[1].vStart = (((dword_CODE_bss_80060888 >> 16) + temp_lo) << 16) | ((dword_CODE_bss_80060888 + temp_lo) & 0xffff);
    osViSetMode(viMode);
    osViBlack(D_800232BC);
    if (D_800232BC != 0) {
        if (D_800232BC < 3) {
            D_800232BC--;
        }
    }
    osViSetSpecialFeatures(OS_VI_DITHER_FILTER_ON | OS_VI_GAMMA_OFF);
    D_800232B0 = -D_800232B0;
}
#else
GLOBAL_ASM(
.text
glabel video_related_7
/* 003DA0 700031A0 3C038002 */  lui   $v1, %hi(D_800232B8)
/* 003DA4 700031A4 246332B8 */  addiu $v1, %lo(D_800232B8) # addiu $v1, $v1, 0x32b8
/* 003DA8 700031A8 8C620000 */  lw    $v0, ($v1)
/* 003DAC 700031AC 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 003DB0 700031B0 AFBF0014 */  sw    $ra, 0x14($sp)
/* 003DB4 700031B4 10400006 */  beqz  $v0, .L700031D0
/* 003DB8 700031B8 3C188002 */   lui   $t8, %hi(D_800232B0) 
/* 003DBC 700031BC 244EFFFF */  addiu $t6, $v0, -1
/* 003DC0 700031C0 15C00003 */  bnez  $t6, .L700031D0
/* 003DC4 700031C4 AC6E0000 */   sw    $t6, ($v1)
/* 003DC8 700031C8 3C018002 */  lui   $at, %hi(D_800232B4)
/* 003DCC 700031CC AC2032B4 */  sw    $zero, %lo(D_800232B4)($at)
.L700031D0:
/* 003DD0 700031D0 3C198002 */  lui   $t9, %hi(D_800232B4) 
/* 003DD4 700031D4 8F3932B4 */  lw    $t9, %lo(D_800232B4)($t9)
/* 003DD8 700031D8 8F1832B0 */  lw    $t8, %lo(D_800232B0)($t8)
/* 003DDC 700031DC 3C028006 */  lui   $v0, %hi(viMode+0x8)
/* 003DE0 700031E0 8C4D0884 */  lw    $t5, %lo(viMode+0x8)($v0)
/* 003DE4 700031E4 03190019 */  multu $t8, $t9
/* 003DE8 700031E8 3C058006 */  lui   $a1, %hi(viMode)
/* 003DEC 700031EC 24A5087C */  addiu $a1, %lo(viMode) # addiu $a1, $a1, 0x87c
/* 003DF0 700031F0 000D4C03 */  sra   $t1, $t5, 0x10
/* 003DF4 700031F4 8CB90000 */  lw    $t9, ($a1)
/* 003DF8 700031F8 3C028006 */  lui   $v0, %hi(viMode+0xC)
/* 003DFC 700031FC 00001812 */  mflo  $v1
/* 003E00 70003200 01235821 */  addu  $t3, $t1, $v1
/* 003E04 70003204 01A37021 */  addu  $t6, $t5, $v1
/* 003E08 70003208 31CFFFFF */  andi  $t7, $t6, 0xffff
/* 003E0C 7000320C 000B6400 */  sll   $t4, $t3, 0x10
/* 003E10 70003210 018FC025 */  or    $t8, $t4, $t7
/* 003E14 70003214 AF380030 */  sw    $t8, 0x30($t9)
/* 003E18 70003218 8C4E0888 */  lw    $t6, %lo(viMode+0xC)($v0)
/* 003E1C 7000321C 8CB90000 */  lw    $t9, ($a1)
/* 003E20 70003220 000E4C03 */  sra   $t1, $t6, 0x10
/* 003E24 70003224 01235821 */  addu  $t3, $t1, $v1
/* 003E28 70003228 01C36021 */  addu  $t4, $t6, $v1
/* 003E2C 7000322C 318FFFFF */  andi  $t7, $t4, 0xffff
/* 003E30 70003230 000B6C00 */  sll   $t5, $t3, 0x10
/* 003E34 70003234 01AFC025 */  or    $t8, $t5, $t7
/* 003E38 70003238 AF380044 */  sw    $t8, 0x44($t9)
/* 003E3C 7000323C 0C003818 */  jal   osViSetMode
/* 003E40 70003240 8CA40000 */   lw    $a0, ($a1)
/* 003E44 70003244 3C048002 */  lui   $a0, %hi(D_800232BC + 3)
/* 003E48 70003248 0C0038B4 */  jal   osViBlack
/* 003E4C 7000324C 908432BF */   lbu   $a0, %lo(D_800232BC + 3)($a0)
/* 003E50 70003250 3C038002 */  lui   $v1, %hi(D_800232BC)
/* 003E54 70003254 246332BC */  addiu $v1, %lo(D_800232BC) # addiu $v1, $v1, 0x32bc
/* 003E58 70003258 8C620000 */  lw    $v0, ($v1)
/* 003E5C 7000325C 10400004 */  beqz  $v0, .L70003270
/* 003E60 70003260 28410003 */   slti  $at, $v0, 3
/* 003E64 70003264 10200002 */  beqz  $at, .L70003270
/* 003E68 70003268 2448FFFF */   addiu $t0, $v0, -1
/* 003E6C 7000326C AC680000 */  sw    $t0, ($v1)
.L70003270:
/* 003E70 70003270 0C003DEC */  jal   osViSetSpecialFeatures
/* 003E74 70003274 24040042 */   li    $a0, 66
/* 003E78 70003278 3C028002 */  lui   $v0, %hi(D_800232B0)
/* 003E7C 7000327C 244232B0 */  addiu $v0, %lo(D_800232B0) # addiu $v0, $v0, 0x32b0
/* 003E80 70003280 8C490000 */  lw    $t1, ($v0)
/* 003E84 70003284 8FBF0014 */  lw    $ra, 0x14($sp)
/* 003E88 70003288 27BD0018 */  addiu $sp, $sp, 0x18
/* 003E8C 7000328C 00095023 */  negu  $t2, $t1
/* 003E90 70003290 03E00008 */  jr    $ra
/* 003E94 70003294 AC4A0000 */   sw    $t2, ($v0)
)
#endif

#ifdef NONMATCHING
// First half matching very well, second half less so.
void osViSetYScale(f32);
void video_related_8(void) {
    f32 var1;
    f32 var1_5;
    OSViMode *viModeTmp;
    s32 var2;
    s32 var3;
    s32 var4;
    s32 var5;
    s32 var6;
    s32 var7;
    s32 var8;
    s32 var9;
    s32 varA;
    video_settings *settings;
    if (ptr_video_settings2->mode != ptr_video_settings1->mode) {
        switch (ptr_video_settings2->mode)
        {
            case 0: {
                osViSetYScale(1.0f);
                osViBlack(TRUE);

                break;
            }

            case 1: {
                if (coloroutputmode != COLORMODE_32BIT) {
                    if (osTvType == TV_TYPE_MPAL) {
                        dword_CODE_bss_80060828 = osViModeTable[OS_VI_MPAL_LAN1];
                    } else {
                        dword_CODE_bss_80060828 = osViModeTable[OS_VI_NTSC_LAN1];
                    }
                } else {
                    if (osTvType == TV_TYPE_MPAL) {
                        dword_CODE_bss_80060828 = osViModeTable[34/*OS_VI_MPAL_LAN2*/];
                    } else {
                        dword_CODE_bss_80060828 = osViModeTable[OS_VI_NTSC_LAN2];
                    }
                }

                viMode = &dword_CODE_bss_80060828;

                dword_CODE_bss_80060880 = viMode->comRegs.hStart;
                dword_CODE_bss_80060884 = viMode->fldRegs[0].vStart;
                dword_CODE_bss_80060888 = viMode->fldRegs[1].vStart;

                viSet800232BC(0);

                break;
            }

            case 2: {
                if (osTvType == TV_TYPE_MPAL) {
                    viMode = &osViModeTable[39/*OS_VI_MPAL_HAF1*/];
                } else {
                    viMode = &osViModeTable[OS_VI_NTSC_HAF1];
                }
                
                dword_CODE_bss_80060880 = viMode->comRegs.hStart;
                dword_CODE_bss_80060884 = viMode->fldRegs[0].vStart;
                dword_CODE_bss_80060888 = viMode->fldRegs[1].vStart;

                osViBlack(FALSE);

                break;
            }
        };

        osViSetSpecialFeatures(OS_VI_DITHER_FILTER_ON | OS_VI_GAMMA_OFF);
    }
    var1 = (f32)ptr_video_settings2->y / (f32)ptr_video_settings2->bufy;
    var1_5 = (f32)ptr_video_settings2->x / (f32)ptr_video_settings2->bufx;
    if (ptr_video_settings2->mode == 0) {
        var1 = 1.0f;
    }
    g_ViXScales[D_800232C0] = var1_5;
    g_ViYScales[D_800232C0] = var1;
    if (ptr_video_settings2->mode == 1) {
        g_ViModePtrs[D_800232C0] = &dword_CODE_bss_80060828;
        if (coloroutputmode != COLORMODE_32BIT) {
            if (osTvType == TV_TYPE_MPAL) {
                g_ViModes[D_800232C0] = osViModeTable[OS_VI_MPAL_LAN1];
            } else {
                g_ViModes[D_800232C0] = osViModeTable[OS_VI_NTSC_LAN1];
            }
        } else {
            if (osTvType == TV_TYPE_MPAL) {
                g_ViModes[D_800232C0] = osViModeTable[34/*OS_VI_MPAL_LAN2*/];
            } else {                
                g_ViModes[D_800232C0] = osViModeTable[OS_VI_NTSC_LAN2];
            }
        }

        viModeTmp = &g_ViModes[D_800232C0];

        viModeTmp->comRegs.width = ptr_video_settings2->bufx;
        viModeTmp->comRegs.xScale = ((ptr_video_settings2->bufx << 10) / 640);
        viModeTmp->fldRegs[0].yScale = ((ptr_video_settings2->bufy << 11) / 480);
        viModeTmp->fldRegs[1].yScale = ((ptr_video_settings2->bufy << 11) / 480);
        viModeTmp->fldRegs[0].origin = (ptr_video_settings2->bufx * 2);
        viModeTmp->fldRegs[1].origin = (ptr_video_settings2->bufx * 2);
        var2 = viModeTmp->comRegs.hStart;
        var2 = (((((var2 >> 16) & 0xffff) + D_8002329C) % 0xffff) << 16) | (((var2 & 0xffff) + D_8002329C) % 0xffff);
        viModeTmp->comRegs.hStart = var2;
        dword_CODE_bss_80060880 = var2;
        var3 = viModeTmp->fldRegs[0].vStart;
        var3 = (((((var3 >> 16) & 0xffff) + D_800232A0) % 0xffff) << 16) | (((var3 & 0xffff) + D_800232A0) % 0xffff);
        viModeTmp->fldRegs[0].vStart = var3;
        dword_CODE_bss_80060884 = var3;
        var4 = viModeTmp->fldRegs[1].vStart;
        var4 = (((((var4 >> 16) & 0xffff) + D_800232A0) % 0xffff) << 16) | (((var4 & 0xffff) + D_800232A0) % 0xffff);
        viModeTmp->fldRegs[1].vStart = var4;
        dword_CODE_bss_80060888 = var4;
        something_with_osVI_14[D_800232C0] = 1;
    } else {
        something_with_osVI_14[D_800232C0] = 0;
    }
    var5 = (D_800232C0 + 1);
    var6 = (var5 & 1);
    if (var5 < 0) {
        if (var6 != 0) {
            var6 -= 2;
        }
    }
    D_800232C0 = var6;
    if (coloroutputmode != COLORMODE_32BIT) {
        (*fast3d_related_array)[22] = ptr_video_settings2->framebuf;
    } else {
        (*fast3d_related_array)[22] = cfb_16[0];
    }
    var7 = (off_CODE_bss_80060878 + 1);
    var8 = (off_CODE_bss_80060879 + 1);
    var9 = (var7 & 1);
    if (var7 < 0) {
        if (var9 != 0) {
            var9 -= 2;
        }
    }
    off_CODE_bss_80060878 = var9;
    varA = (var8 & 1);
    if (var8 < 0) {
        if (varA != 0) {
            varA -= 2;
        }
    }
    off_CODE_bss_80060879 = varA;
    settings = ptr_video_settings2;
    ptr_video_settings1 = &video1_settings[off_CODE_bss_80060878];
    ptr_video_settings2 = &video1_settings[off_CODE_bss_80060879];
    bcopy(settings, ptr_video_settings2, sizeof(video_settings));
    ptr_video_settings2->framebuf = cfb_16[off_CODE_bss_80060879];
}
#else
GLOBAL_ASM(
.text
glabel video_related_8
/* 003E98 70003298 3C0D8002 */  lui   $t5, %hi(ptr_video_settings2) 
/* 003E9C 7000329C 25AD32A8 */  addiu $t5, %lo(ptr_video_settings2) # addiu $t5, $t5, 0x32a8
/* 003EA0 700032A0 3C0E8002 */  lui   $t6, %hi(ptr_video_settings1) 
/* 003EA4 700032A4 8DCE32A4 */  lw    $t6, %lo(ptr_video_settings1)($t6)
/* 003EA8 700032A8 8DA80000 */  lw    $t0, ($t5)
/* 003EAC 700032AC 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 003EB0 700032B0 AFBF0014 */  sw    $ra, 0x14($sp)
/* 003EB4 700032B4 91CF0000 */  lbu   $t7, ($t6)
/* 003EB8 700032B8 91020000 */  lbu   $v0, ($t0)
/* 003EBC 700032BC 504F009B */  beql  $v0, $t7, .L7000352C
/* 003EC0 700032C0 850F0004 */   lh    $t7, 4($t0)
/* 003EC4 700032C4 10400009 */  beqz  $v0, .L700032EC
/* 003EC8 700032C8 3C013F80 */   li    $at, 0x3F800000 # 1.000000
/* 003ECC 700032CC 24010001 */  li    $at, 1
/* 003ED0 700032D0 1041000D */  beq   $v0, $at, .L70003308
/* 003ED4 700032D4 3C188002 */   lui   $t8, %hi(coloroutputmode) 
/* 003ED8 700032D8 24010002 */  li    $at, 2
/* 003EDC 700032DC 10410071 */  beq   $v0, $at, .L700034A4
/* 003EE0 700032E0 3C198000 */   lui   $t9, 0x8000
/* 003EE4 700032E4 10000089 */  b     .L7000350C
/* 003EE8 700032E8 00000000 */   nop   
.L700032EC:
/* 003EEC 700032EC 44816000 */  mtc1  $at, $f12
/* 003EF0 700032F0 0C003880 */  jal   osViSetYScale
/* 003EF4 700032F4 00000000 */   nop   
/* 003EF8 700032F8 0C0038B4 */  jal   osViBlack
/* 003EFC 700032FC 24040001 */   li    $a0, 1
/* 003F00 70003300 10000082 */  b     .L7000350C
/* 003F04 70003304 00000000 */   nop   
.L70003308:
/* 003F08 70003308 8F1832AC */  lw    $t8, %lo(coloroutputmode)($t8)
/* 003F0C 7000330C 3C038006 */  lui   $v1, %hi(viMode)
/* 003F10 70003310 3C0F8000 */  lui   $t7, 0x8000
/* 003F14 70003314 1300002B */  beqz  $t8, .L700033C4
/* 003F18 70003318 2463087C */   addiu $v1, %lo(viMode) # addiu $v1, $v1, 0x87c
/* 003F1C 7000331C 3C198000 */  lui   $t9, %hi(osTvType) 
/* 003F20 70003320 8F390300 */  lw    $t9, %lo(osTvType)($t9)
/* 003F24 70003324 24010002 */  li    $at, 2
/* 003F28 70003328 3C188006 */  lui   $t8, %hi(dword_CODE_bss_80060828) 
/* 003F2C 7000332C 17210014 */  bne   $t9, $at, .L70003380
/* 003F30 70003330 27180828 */   addiu $t8, %lo(dword_CODE_bss_80060828) # addiu $t8, $t8, 0x828
/* 003F34 70003334 3C0F8002 */  lui   $t7, %hi(osViModeTable_osViModeMpalLan1) 
/* 003F38 70003338 25EF7320 */  addiu $t7, %lo(osViModeTable_osViModeMpalLan1) # addiu $t7, $t7, 0x7320
/* 003F3C 7000333C 3C0E8006 */  lui   $t6, %hi(dword_CODE_bss_80060828) 
/* 003F40 70003340 25CE0828 */  addiu $t6, %lo(dword_CODE_bss_80060828) # addiu $t6, $t6, 0x828
/* 003F44 70003344 25F90048 */  addiu $t9, $t7, 0x48
.L70003348:
/* 003F48 70003348 8DE10000 */  lw    $at, ($t7)
/* 003F4C 7000334C 25EF000C */  addiu $t7, $t7, 0xc
/* 003F50 70003350 25CE000C */  addiu $t6, $t6, 0xc
/* 003F54 70003354 ADC1FFF4 */  sw    $at, -0xc($t6)
/* 003F58 70003358 8DE1FFF8 */  lw    $at, -8($t7)
/* 003F5C 7000335C ADC1FFF8 */  sw    $at, -8($t6)
/* 003F60 70003360 8DE1FFFC */  lw    $at, -4($t7)
/* 003F64 70003364 15F9FFF8 */  bne   $t7, $t9, .L70003348
/* 003F68 70003368 ADC1FFFC */   sw    $at, -4($t6)
/* 003F6C 7000336C 8DE10000 */  lw    $at, ($t7)
/* 003F70 70003370 8DF90004 */  lw    $t9, 4($t7)
/* 003F74 70003374 ADC10000 */  sw    $at, ($t6)
/* 003F78 70003378 1000003A */  b     .L70003464
/* 003F7C 7000337C ADD90004 */   sw    $t9, 4($t6)
.L70003380:
/* 003F80 70003380 3C198002 */  lui   $t9, %hi(osViModeTable_osViModeNtscLan1) 
/* 003F84 70003384 27396A60 */  addiu $t9, %lo(osViModeTable_osViModeNtscLan1) # addiu $t9, $t9, 0x6a60
/* 003F88 70003388 272E0048 */  addiu $t6, $t9, 0x48
.L7000338C:
/* 003F8C 7000338C 8F210000 */  lw    $at, ($t9)
/* 003F90 70003390 2739000C */  addiu $t9, $t9, 0xc
/* 003F94 70003394 2718000C */  addiu $t8, $t8, 0xc
/* 003F98 70003398 AF01FFF4 */  sw    $at, -0xc($t8)
/* 003F9C 7000339C 8F21FFF8 */  lw    $at, -8($t9)
/* 003FA0 700033A0 AF01FFF8 */  sw    $at, -8($t8)
/* 003FA4 700033A4 8F21FFFC */  lw    $at, -4($t9)
/* 003FA8 700033A8 172EFFF8 */  bne   $t9, $t6, .L7000338C
/* 003FAC 700033AC AF01FFFC */   sw    $at, -4($t8)
/* 003FB0 700033B0 8F210000 */  lw    $at, ($t9)
/* 003FB4 700033B4 8F2E0004 */  lw    $t6, 4($t9)
/* 003FB8 700033B8 AF010000 */  sw    $at, ($t8)
/* 003FBC 700033BC 10000029 */  b     .L70003464
/* 003FC0 700033C0 AF0E0004 */   sw    $t6, 4($t8)
.L700033C4:
/* 003FC4 700033C4 8DEF0300 */  lw    $t7, 0x300($t7)
/* 003FC8 700033C8 24010002 */  li    $at, 2
/* 003FCC 700033CC 3C188006 */  lui   $t8, %hi(dword_CODE_bss_80060828) 
/* 003FD0 700033D0 15E10014 */  bne   $t7, $at, .L70003424
/* 003FD4 700033D4 27180828 */   addiu $t8, %lo(dword_CODE_bss_80060828) # addiu $t8, $t8, 0x828
/* 003FD8 700033D8 3C198002 */  lui   $t9, %hi(osViModeTable_osViModeMpalLan2) 
/* 003FDC 700033DC 27397460 */  addiu $t9, %lo(osViModeTable_osViModeMpalLan2) # addiu $t9, $t9, 0x7460
/* 003FE0 700033E0 3C0E8006 */  lui   $t6, %hi(dword_CODE_bss_80060828) 
/* 003FE4 700033E4 25CE0828 */  addiu $t6, %lo(dword_CODE_bss_80060828) # addiu $t6, $t6, 0x828
/* 003FE8 700033E8 272F0048 */  addiu $t7, $t9, 0x48
.L700033EC:
/* 003FEC 700033EC 8F210000 */  lw    $at, ($t9)
/* 003FF0 700033F0 2739000C */  addiu $t9, $t9, 0xc
/* 003FF4 700033F4 25CE000C */  addiu $t6, $t6, 0xc
/* 003FF8 700033F8 ADC1FFF4 */  sw    $at, -0xc($t6)
/* 003FFC 700033FC 8F21FFF8 */  lw    $at, -8($t9)
/* 004000 70003400 ADC1FFF8 */  sw    $at, -8($t6)
/* 004004 70003404 8F21FFFC */  lw    $at, -4($t9)
/* 004008 70003408 172FFFF8 */  bne   $t9, $t7, .L700033EC
/* 00400C 7000340C ADC1FFFC */   sw    $at, -4($t6)
/* 004010 70003410 8F210000 */  lw    $at, ($t9)
/* 004014 70003414 8F2F0004 */  lw    $t7, 4($t9)
/* 004018 70003418 ADC10000 */  sw    $at, ($t6)
/* 00401C 7000341C 10000011 */  b     .L70003464
/* 004020 70003420 ADCF0004 */   sw    $t7, 4($t6)
.L70003424:
/* 004024 70003424 3C0F8002 */  lui   $t7, %hi(osViModeTable_osViModeNtscLan2) 
/* 004028 70003428 25EF6BA0 */  addiu $t7, %lo(osViModeTable_osViModeNtscLan2) # addiu $t7, $t7, 0x6ba0
/* 00402C 7000342C 25EE0048 */  addiu $t6, $t7, 0x48
.L70003430:
/* 004030 70003430 8DE10000 */  lw    $at, ($t7)
/* 004034 70003434 25EF000C */  addiu $t7, $t7, 0xc
/* 004038 70003438 2718000C */  addiu $t8, $t8, 0xc
/* 00403C 7000343C AF01FFF4 */  sw    $at, -0xc($t8)
/* 004040 70003440 8DE1FFF8 */  lw    $at, -8($t7)
/* 004044 70003444 AF01FFF8 */  sw    $at, -8($t8)
/* 004048 70003448 8DE1FFFC */  lw    $at, -4($t7)
/* 00404C 7000344C 15EEFFF8 */  bne   $t7, $t6, .L70003430
/* 004050 70003450 AF01FFFC */   sw    $at, -4($t8)
/* 004054 70003454 8DE10000 */  lw    $at, ($t7)
/* 004058 70003458 8DEE0004 */  lw    $t6, 4($t7)
/* 00405C 7000345C AF010000 */  sw    $at, ($t8)
/* 004060 70003460 AF0E0004 */  sw    $t6, 4($t8)
.L70003464:
/* 004064 70003464 3C198006 */  lui   $t9, %hi(dword_CODE_bss_80060828) 
/* 004068 70003468 27390828 */  addiu $t9, %lo(dword_CODE_bss_80060828) # addiu $t9, $t9, 0x828
/* 00406C 7000346C AC790000 */  sw    $t9, ($v1)
/* 004070 70003470 8F2E001C */  lw    $t6, 0x1c($t9)
/* 004074 70003474 3C018006 */  lui   $at, %hi(viMode+0x4)
/* 004078 70003478 00002025 */  move  $a0, $zero
/* 00407C 7000347C AC2E0880 */  sw    $t6, %lo(viMode+0x4)($at)
/* 004080 70003480 8F2F0030 */  lw    $t7, 0x30($t9)
/* 004084 70003484 3C018006 */  lui   $at, %hi(viMode+0x8)
/* 004088 70003488 AC2F0884 */  sw    $t7, %lo(viMode+0x8)($at)
/* 00408C 7000348C 8F380044 */  lw    $t8, 0x44($t9)
/* 004090 70003490 3C018006 */  lui   $at, %hi(viMode+0xC)
/* 004094 70003494 0C000C64 */  jal   viSet800232BC
/* 004098 70003498 AC380888 */   sw    $t8, %lo(viMode+0xC)($at)
/* 00409C 7000349C 1000001B */  b     .L7000350C
/* 0040A0 700034A0 00000000 */   nop   
.L700034A4:
/* 0040A4 700034A4 8F390300 */  lw    $t9, 0x300($t9)
/* 0040A8 700034A8 24010002 */  li    $at, 2
/* 0040AC 700034AC 3C038006 */  lui   $v1, %hi(viMode)
/* 0040B0 700034B0 17210007 */  bne   $t9, $at, .L700034D0
/* 0040B4 700034B4 2463087C */   addiu $v1, %lo(viMode) # addiu $v1, $v1, 0x87c
/* 0040B8 700034B8 3C038006 */  lui   $v1, %hi(viMode)
/* 0040BC 700034BC 3C0E8002 */  lui   $t6, %hi(osViModeTable_osViModeMpalHaf1) 
/* 0040C0 700034C0 2463087C */  addiu $v1, %lo(viMode) # addiu $v1, $v1, 0x87c
/* 0040C4 700034C4 25CE75F0 */  addiu $t6, %lo(osViModeTable_osViModeMpalHaf1) # addiu $t6, $t6, 0x75f0
/* 0040C8 700034C8 10000004 */  b     .L700034DC
/* 0040CC 700034CC AC6E0000 */   sw    $t6, ($v1)
.L700034D0:
/* 0040D0 700034D0 3C0F8002 */  lui   $t7, %hi(osViModeTable_osViModeNtscHaf1) 
/* 0040D4 700034D4 25EF6D30 */  addiu $t7, %lo(osViModeTable_osViModeNtscHaf1) # addiu $t7, $t7, 0x6d30
/* 0040D8 700034D8 AC6F0000 */  sw    $t7, ($v1)
.L700034DC:
/* 0040DC 700034DC 8C620000 */  lw    $v0, ($v1)
/* 0040E0 700034E0 3C018006 */  lui   $at, %hi(viMode+0x4)
/* 0040E4 700034E4 00002025 */  move  $a0, $zero
/* 0040E8 700034E8 8C58001C */  lw    $t8, 0x1c($v0)
/* 0040EC 700034EC AC380880 */  sw    $t8, %lo(viMode+0x4)($at)
/* 0040F0 700034F0 8C590030 */  lw    $t9, 0x30($v0)
/* 0040F4 700034F4 3C018006 */  lui   $at, %hi(viMode+0x8)
/* 0040F8 700034F8 AC390884 */  sw    $t9, %lo(viMode+0x8)($at)
/* 0040FC 700034FC 8C4E0044 */  lw    $t6, 0x44($v0)
/* 004100 70003500 3C018006 */  lui   $at, %hi(viMode+0xC)
/* 004104 70003504 0C0038B4 */  jal   osViBlack
/* 004108 70003508 AC2E0888 */   sw    $t6, %lo(viMode+0xC)($at)
.L7000350C:
/* 00410C 7000350C 0C003DEC */  jal   osViSetSpecialFeatures
/* 004110 70003510 24040042 */   li    $a0, 66
/* 004114 70003514 3C088002 */  lui   $t0, %hi(ptr_video_settings2) 
/* 004118 70003518 8D0832A8 */  lw    $t0, %lo(ptr_video_settings2)($t0)
/* 00411C 7000351C 3C0D8002 */  lui   $t5, %hi(ptr_video_settings2) 
/* 004120 70003520 25AD32A8 */  addiu $t5, %lo(ptr_video_settings2) # addiu $t5, $t5, 0x32a8
/* 004124 70003524 91020000 */  lbu   $v0, ($t0)
/* 004128 70003528 850F0004 */  lh    $t7, 4($t0)
.L7000352C:
/* 00412C 7000352C 85180018 */  lh    $t8, 0x18($t0)
/* 004130 70003530 85190006 */  lh    $t9, 6($t0)
/* 004134 70003534 448F2000 */  mtc1  $t7, $f4
/* 004138 70003538 850E001A */  lh    $t6, 0x1a($t0)
/* 00413C 7000353C 44984000 */  mtc1  $t8, $f8
/* 004140 70003540 468021A0 */  cvt.s.w $f6, $f4
/* 004144 70003544 44998000 */  mtc1  $t9, $f16
/* 004148 70003548 448E2000 */  mtc1  $t6, $f4
/* 00414C 7000354C 3C188006 */  lui   $t8, %hi(dword_CODE_bss_80060828) 
/* 004150 70003550 3C0A8002 */  lui   $t2, %hi(D_800232C0) 
/* 004154 70003554 468042A0 */  cvt.s.w $f10, $f8
/* 004158 70003558 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 00415C 7000355C 27180828 */  addiu $t8, %lo(dword_CODE_bss_80060828) # addiu $t8, $t8, 0x828
/* 004160 70003560 3C0B8002 */  lui   $t3, %hi(coloroutputmode) 
/* 004164 70003564 468084A0 */  cvt.s.w $f18, $f16
/* 004168 70003568 46802220 */  cvt.s.w $f8, $f4
/* 00416C 7000356C 460A3083 */  div.s $f2, $f6, $f10
/* 004170 70003570 14400003 */  bnez  $v0, .L70003580
/* 004174 70003574 46089003 */   div.s $f0, $f18, $f8
/* 004178 70003578 44810000 */  mtc1  $at, $f0
/* 00417C 7000357C 00000000 */  nop   
.L70003580:
/* 004180 70003580 8D4A32C0 */  lw    $t2, %lo(D_800232C0)($t2)
/* 004184 70003584 3C018002 */  lui   $at, %hi(g_ViXScales)
/* 004188 70003588 000A4880 */  sll   $t1, $t2, 2
/* 00418C 7000358C 00290821 */  addu  $at, $at, $t1
/* 004190 70003590 E42230B4 */  swc1  $f2, %lo(g_ViXScales)($at)
/* 004194 70003594 3C018002 */  lui   $at, %hi(g_ViYScales)
/* 004198 70003598 00290821 */  addu  $at, $at, $t1
/* 00419C 7000359C E42030BC */  swc1  $f0, %lo(g_ViYScales)($at)
/* 0041A0 700035A0 910F0000 */  lbu   $t7, ($t0)
/* 0041A4 700035A4 24010001 */  li    $at, 1
/* 0041A8 700035A8 15E10105 */  bne   $t7, $at, .L700039C0
/* 0041AC 700035AC 00000000 */   nop   
/* 0041B0 700035B0 8D6B32AC */  lw    $t3, %lo(coloroutputmode)($t3)
/* 0041B4 700035B4 3C018006 */  lui   $at, %hi(g_ViModePtrs)
/* 0041B8 700035B8 00290821 */  addu  $at, $at, $t1
/* 0041BC 700035BC 11600035 */  beqz  $t3, .L70003694
/* 0041C0 700035C0 AC38DBE0 */   sw    $t8, %lo(g_ViModePtrs)($at)
/* 0041C4 700035C4 3C198000 */  lui   $t9, %hi(osTvType) 
/* 0041C8 700035C8 8F390300 */  lw    $t9, %lo(osTvType)($t9)
/* 0041CC 700035CC 24010002 */  li    $at, 2
/* 0041D0 700035D0 3C0E8006 */  lui   $t6, %hi(g_ViModes) 
/* 0041D4 700035D4 17210019 */  bne   $t9, $at, .L7000363C
/* 0041D8 700035D8 25CEDB40 */   addiu $t6, %lo(g_ViModes) # addiu $t6, $t6, -0x24c0
/* 0041DC 700035DC 000A7080 */  sll   $t6, $t2, 2
/* 0041E0 700035E0 01CA7021 */  addu  $t6, $t6, $t2
/* 0041E4 700035E4 3C0F8006 */  lui   $t7, %hi(g_ViModes) 
/* 0041E8 700035E8 25EFDB40 */  addiu $t7, %lo(g_ViModes) # addiu $t7, $t7, -0x24c0
/* 0041EC 700035EC 000E7100 */  sll   $t6, $t6, 4
/* 0041F0 700035F0 01CF1821 */  addu  $v1, $t6, $t7
/* 0041F4 700035F4 3C188002 */  lui   $t8, %hi(osViModeTable_osViModeMpalLan1) 
/* 0041F8 700035F8 27187320 */  addiu $t8, %lo(osViModeTable_osViModeMpalLan1) # addiu $t8, $t8, 0x7320
/* 0041FC 700035FC 270E0048 */  addiu $t6, $t8, 0x48
/* 004200 70003600 00607825 */  move  $t7, $v1
.L70003604:
/* 004204 70003604 8F010000 */  lw    $at, ($t8)
/* 004208 70003608 2718000C */  addiu $t8, $t8, 0xc
/* 00420C 7000360C 25EF000C */  addiu $t7, $t7, 0xc
/* 004210 70003610 ADE1FFF4 */  sw    $at, -0xc($t7)
/* 004214 70003614 8F01FFF8 */  lw    $at, -8($t8)
/* 004218 70003618 ADE1FFF8 */  sw    $at, -8($t7)
/* 00421C 7000361C 8F01FFFC */  lw    $at, -4($t8)
/* 004220 70003620 170EFFF8 */  bne   $t8, $t6, .L70003604
/* 004224 70003624 ADE1FFFC */   sw    $at, -4($t7)
/* 004228 70003628 8F010000 */  lw    $at, ($t8)
/* 00422C 7000362C ADE10000 */  sw    $at, ($t7)
/* 004230 70003630 8F0E0004 */  lw    $t6, 4($t8)
/* 004234 70003634 1000004A */  b     .L70003760
/* 004238 70003638 ADEE0004 */   sw    $t6, 4($t7)
.L7000363C:
/* 00423C 7000363C 000AC880 */  sll   $t9, $t2, 2
/* 004240 70003640 032AC821 */  addu  $t9, $t9, $t2
/* 004244 70003644 0019C900 */  sll   $t9, $t9, 4
/* 004248 70003648 032E1821 */  addu  $v1, $t9, $t6
/* 00424C 7000364C 3C188002 */  lui   $t8, %hi(osViModeTable_osViModeNtscLan1) 
/* 004250 70003650 27186A60 */  addiu $t8, %lo(osViModeTable_osViModeNtscLan1) # addiu $t8, $t8, 0x6a60
/* 004254 70003654 27190048 */  addiu $t9, $t8, 0x48
/* 004258 70003658 00607025 */  move  $t6, $v1
.L7000365C:
/* 00425C 7000365C 8F010000 */  lw    $at, ($t8)
/* 004260 70003660 2718000C */  addiu $t8, $t8, 0xc
/* 004264 70003664 25CE000C */  addiu $t6, $t6, 0xc
/* 004268 70003668 ADC1FFF4 */  sw    $at, -0xc($t6)
/* 00426C 7000366C 8F01FFF8 */  lw    $at, -8($t8)
/* 004270 70003670 ADC1FFF8 */  sw    $at, -8($t6)
/* 004274 70003674 8F01FFFC */  lw    $at, -4($t8)
/* 004278 70003678 1719FFF8 */  bne   $t8, $t9, .L7000365C
/* 00427C 7000367C ADC1FFFC */   sw    $at, -4($t6)
/* 004280 70003680 8F010000 */  lw    $at, ($t8)
/* 004284 70003684 ADC10000 */  sw    $at, ($t6)
/* 004288 70003688 8F190004 */  lw    $t9, 4($t8)
/* 00428C 7000368C 10000034 */  b     .L70003760
/* 004290 70003690 ADD90004 */   sw    $t9, 4($t6)
.L70003694:
/* 004294 70003694 3C0F8000 */  lui   $t7, %hi(osTvType) 
/* 004298 70003698 8DEF0300 */  lw    $t7, %lo(osTvType)($t7)
/* 00429C 7000369C 24010002 */  li    $at, 2
/* 0042A0 700036A0 15E10018 */  bne   $t7, $at, .L70003704
/* 0042A4 700036A4 000AC880 */   sll   $t9, $t2, 2
/* 0042A8 700036A8 032AC821 */  addu  $t9, $t9, $t2
/* 0042AC 700036AC 3C188006 */  lui   $t8, %hi(g_ViModes) 
/* 0042B0 700036B0 2718DB40 */  addiu $t8, %lo(g_ViModes) # addiu $t8, $t8, -0x24c0
/* 0042B4 700036B4 0019C900 */  sll   $t9, $t9, 4
/* 0042B8 700036B8 03381821 */  addu  $v1, $t9, $t8
/* 0042BC 700036BC 3C0E8002 */  lui   $t6, %hi(osViModeTable_osViModeMpalLan2) 
/* 0042C0 700036C0 25CE7460 */  addiu $t6, %lo(osViModeTable_osViModeMpalLan2) # addiu $t6, $t6, 0x7460
/* 0042C4 700036C4 25D90048 */  addiu $t9, $t6, 0x48
/* 0042C8 700036C8 0060C025 */  move  $t8, $v1
.L700036CC:
/* 0042CC 700036CC 8DC10000 */  lw    $at, ($t6)
/* 0042D0 700036D0 25CE000C */  addiu $t6, $t6, 0xc
/* 0042D4 700036D4 2718000C */  addiu $t8, $t8, 0xc
/* 0042D8 700036D8 AF01FFF4 */  sw    $at, -0xc($t8)
/* 0042DC 700036DC 8DC1FFF8 */  lw    $at, -8($t6)
/* 0042E0 700036E0 AF01FFF8 */  sw    $at, -8($t8)
/* 0042E4 700036E4 8DC1FFFC */  lw    $at, -4($t6)
/* 0042E8 700036E8 15D9FFF8 */  bne   $t6, $t9, .L700036CC
/* 0042EC 700036EC AF01FFFC */   sw    $at, -4($t8)
/* 0042F0 700036F0 8DC10000 */  lw    $at, ($t6)
/* 0042F4 700036F4 AF010000 */  sw    $at, ($t8)
/* 0042F8 700036F8 8DD90004 */  lw    $t9, 4($t6)
/* 0042FC 700036FC 10000018 */  b     .L70003760
/* 004300 70003700 AF190004 */   sw    $t9, 4($t8)
.L70003704:
/* 004304 70003704 000A7880 */  sll   $t7, $t2, 2
/* 004308 70003708 01EA7821 */  addu  $t7, $t7, $t2
/* 00430C 7000370C 3C198006 */  lui   $t9, %hi(g_ViModes) 
/* 004310 70003710 2739DB40 */  addiu $t9, %lo(g_ViModes) # addiu $t9, $t9, -0x24c0
/* 004314 70003714 000F7900 */  sll   $t7, $t7, 4
/* 004318 70003718 01F91821 */  addu  $v1, $t7, $t9
/* 00431C 7000371C 3C0E8002 */  lui   $t6, %hi(osViModeTable_osViModeNtscLan2) 
/* 004320 70003720 25CE6BA0 */  addiu $t6, %lo(osViModeTable_osViModeNtscLan2) # addiu $t6, $t6, 0x6ba0
/* 004324 70003724 25CF0048 */  addiu $t7, $t6, 0x48
/* 004328 70003728 0060C825 */  move  $t9, $v1
.L7000372C:
/* 00432C 7000372C 8DC10000 */  lw    $at, ($t6)
/* 004330 70003730 25CE000C */  addiu $t6, $t6, 0xc
/* 004334 70003734 2739000C */  addiu $t9, $t9, 0xc
/* 004338 70003738 AF21FFF4 */  sw    $at, -0xc($t9)
/* 00433C 7000373C 8DC1FFF8 */  lw    $at, -8($t6)
/* 004340 70003740 AF21FFF8 */  sw    $at, -8($t9)
/* 004344 70003744 8DC1FFFC */  lw    $at, -4($t6)
/* 004348 70003748 15CFFFF8 */  bne   $t6, $t7, .L7000372C
/* 00434C 7000374C AF21FFFC */   sw    $at, -4($t9)
/* 004350 70003750 8DC10000 */  lw    $at, ($t6)
/* 004354 70003754 AF210000 */  sw    $at, ($t9)
/* 004358 70003758 8DCF0004 */  lw    $t7, 4($t6)
/* 00435C 7000375C AF2F0004 */  sw    $t7, 4($t9)
.L70003760:
/* 004360 70003760 85180018 */  lh    $t8, 0x18($t0)
/* 004364 70003764 24010280 */  li    $at, 640
/* 004368 70003768 240C01E0 */  li    $t4, 480
/* 00436C 7000376C AC780008 */  sw    $t8, 8($v1)
/* 004370 70003770 850F0018 */  lh    $t7, 0x18($t0)
/* 004374 70003774 8C62001C */  lw    $v0, 0x1c($v1)
/* 004378 70003778 3C078002 */  lui   $a3, %hi(D_8002329C)
/* 00437C 7000377C 000F7280 */  sll   $t6, $t7, 0xa
/* 004380 70003780 01C1001A */  div   $zero, $t6, $at
/* 004384 70003784 0000C812 */  mflo  $t9
/* 004388 70003788 AC790020 */  sw    $t9, 0x20($v1)
/* 00438C 7000378C 8518001A */  lh    $t8, 0x1a($t0)
/* 004390 70003790 3406FFFF */  li    $a2, 65535
/* 004394 70003794 3C058002 */  lui   $a1, %hi(D_800232A0)
/* 004398 70003798 00187AC0 */  sll   $t7, $t8, 0xb
/* 00439C 7000379C 01EC001A */  div   $zero, $t7, $t4
/* 0043A0 700037A0 00007012 */  mflo  $t6
/* 0043A4 700037A4 AC6E002C */  sw    $t6, 0x2c($v1)
/* 0043A8 700037A8 8519001A */  lh    $t9, 0x1a($t0)
/* 0043AC 700037AC 15800002 */  bnez  $t4, .L700037B8
/* 0043B0 700037B0 00000000 */   nop   
/* 0043B4 700037B4 0007000D */  break 7
.L700037B8:
/* 0043B8 700037B8 2401FFFF */  li    $at, -1
/* 0043BC 700037BC 15810004 */  bne   $t4, $at, .L700037D0
/* 0043C0 700037C0 3C018000 */   lui   $at, 0x8000
/* 0043C4 700037C4 15E10002 */  bne   $t7, $at, .L700037D0
/* 0043C8 700037C8 00000000 */   nop   
/* 0043CC 700037CC 0006000D */  break 6
.L700037D0:
/* 0043D0 700037D0 0019C2C0 */  sll   $t8, $t9, 0xb
/* 0043D4 700037D4 030C001A */  div   $zero, $t8, $t4
/* 0043D8 700037D8 00007812 */  mflo  $t7
/* 0043DC 700037DC AC6F0040 */  sw    $t7, 0x40($v1)
/* 0043E0 700037E0 850E0018 */  lh    $t6, 0x18($t0)
/* 0043E4 700037E4 15800002 */  bnez  $t4, .L700037F0
/* 0043E8 700037E8 00000000 */   nop   
/* 0043EC 700037EC 0007000D */  break 7
.L700037F0:
/* 0043F0 700037F0 2401FFFF */  li    $at, -1
/* 0043F4 700037F4 15810004 */  bne   $t4, $at, .L70003808
/* 0043F8 700037F8 3C018000 */   lui   $at, 0x8000
/* 0043FC 700037FC 17010002 */  bne   $t8, $at, .L70003808
/* 004400 70003800 00000000 */   nop   
/* 004404 70003804 0006000D */  break 6
.L70003808:
/* 004408 70003808 000EC840 */  sll   $t9, $t6, 1
/* 00440C 7000380C AC790028 */  sw    $t9, 0x28($v1)
/* 004410 70003810 85180018 */  lh    $t8, 0x18($t0)
/* 004414 70003814 00027403 */  sra   $t6, $v0, 0x10
/* 004418 70003818 31D9FFFF */  andi  $t9, $t6, 0xffff
/* 00441C 7000381C 00187840 */  sll   $t7, $t8, 1
/* 004420 70003820 AC6F003C */  sw    $t7, 0x3c($v1)
/* 004424 70003824 8CE7329C */  lw    $a3, %lo(D_8002329C)($a3)
/* 004428 70003828 0327C021 */  addu  $t8, $t9, $a3
/* 00442C 7000382C 0306001A */  div   $zero, $t8, $a2
/* 004430 70003830 14C00002 */  bnez  $a2, .L7000383C
/* 004434 70003834 00000000 */   nop   
/* 004438 70003838 0007000D */  break 7
.L7000383C:
/* 00443C 7000383C 2401FFFF */  li    $at, -1
/* 004440 70003840 14C10004 */  bne   $a2, $at, .L70003854
/* 004444 70003844 3C018000 */   lui   $at, 0x8000
/* 004448 70003848 17010002 */  bne   $t8, $at, .L70003854
/* 00444C 7000384C 00000000 */   nop   
/* 004450 70003850 0006000D */  break 6
.L70003854:
/* 004454 70003854 3059FFFF */  andi  $t9, $v0, 0xffff
/* 004458 70003858 00007810 */  mfhi  $t7
/* 00445C 7000385C 0327C021 */  addu  $t8, $t9, $a3
/* 004460 70003860 000F7400 */  sll   $t6, $t7, 0x10
/* 004464 70003864 0306001A */  div   $zero, $t8, $a2
/* 004468 70003868 14C00002 */  bnez  $a2, .L70003874
/* 00446C 7000386C 00000000 */   nop   
/* 004470 70003870 0007000D */  break 7
.L70003874:
/* 004474 70003874 2401FFFF */  li    $at, -1
/* 004478 70003878 14C10004 */  bne   $a2, $at, .L7000388C
/* 00447C 7000387C 3C018000 */   lui   $at, 0x8000
/* 004480 70003880 17010002 */  bne   $t8, $at, .L7000388C
/* 004484 70003884 00000000 */   nop   
/* 004488 70003888 0006000D */  break 6
.L7000388C:
/* 00448C 7000388C 00007810 */  mfhi  $t7
/* 004490 70003890 01CF2025 */  or    $a0, $t6, $t7
/* 004494 70003894 AC64001C */  sw    $a0, 0x1c($v1)
/* 004498 70003898 3C018006 */  lui   $at, %hi(viMode+0x4)
/* 00449C 7000389C AC240880 */  sw    $a0, %lo(viMode+0x4)($at)
/* 0044A0 700038A0 8C620030 */  lw    $v0, 0x30($v1)
/* 0044A4 700038A4 8CA532A0 */  lw    $a1, %lo(D_800232A0)($a1)
/* 0044A8 700038A8 0002CC03 */  sra   $t9, $v0, 0x10
/* 0044AC 700038AC 3338FFFF */  andi  $t8, $t9, 0xffff
/* 0044B0 700038B0 03057021 */  addu  $t6, $t8, $a1
/* 0044B4 700038B4 01C6001A */  div   $zero, $t6, $a2
/* 0044B8 700038B8 14C00002 */  bnez  $a2, .L700038C4
/* 0044BC 700038BC 00000000 */   nop   
/* 0044C0 700038C0 0007000D */  break 7
.L700038C4:
/* 0044C4 700038C4 2401FFFF */  li    $at, -1
/* 0044C8 700038C8 14C10004 */  bne   $a2, $at, .L700038DC
/* 0044CC 700038CC 3C018000 */   lui   $at, 0x8000
/* 0044D0 700038D0 15C10002 */  bne   $t6, $at, .L700038DC
/* 0044D4 700038D4 00000000 */   nop   
/* 0044D8 700038D8 0006000D */  break 6
.L700038DC:
/* 0044DC 700038DC 3058FFFF */  andi  $t8, $v0, 0xffff
/* 0044E0 700038E0 00007810 */  mfhi  $t7
/* 0044E4 700038E4 03057021 */  addu  $t6, $t8, $a1
/* 0044E8 700038E8 000FCC00 */  sll   $t9, $t7, 0x10
/* 0044EC 700038EC 01C6001A */  div   $zero, $t6, $a2
/* 0044F0 700038F0 14C00002 */  bnez  $a2, .L700038FC
/* 0044F4 700038F4 00000000 */   nop   
/* 0044F8 700038F8 0007000D */  break 7
.L700038FC:
/* 0044FC 700038FC 2401FFFF */  li    $at, -1
/* 004500 70003900 14C10004 */  bne   $a2, $at, .L70003914
/* 004504 70003904 3C018000 */   lui   $at, 0x8000
/* 004508 70003908 15C10002 */  bne   $t6, $at, .L70003914
/* 00450C 7000390C 00000000 */   nop   
/* 004510 70003910 0006000D */  break 6
.L70003914:
/* 004514 70003914 00007810 */  mfhi  $t7
/* 004518 70003918 032F2025 */  or    $a0, $t9, $t7
/* 00451C 7000391C AC640030 */  sw    $a0, 0x30($v1)
/* 004520 70003920 3C018006 */  lui   $at, %hi(viMode+0x8)
/* 004524 70003924 AC240884 */  sw    $a0, %lo(viMode+0x8)($at)
/* 004528 70003928 8C620044 */  lw    $v0, 0x44($v1)
/* 00452C 7000392C 0002C403 */  sra   $t8, $v0, 0x10
/* 004530 70003930 330EFFFF */  andi  $t6, $t8, 0xffff
/* 004534 70003934 01C5C821 */  addu  $t9, $t6, $a1
/* 004538 70003938 0326001A */  div   $zero, $t9, $a2
/* 00453C 7000393C 14C00002 */  bnez  $a2, .L70003948
/* 004540 70003940 00000000 */   nop   
/* 004544 70003944 0007000D */  break 7
.L70003948:
/* 004548 70003948 2401FFFF */  li    $at, -1
/* 00454C 7000394C 14C10004 */  bne   $a2, $at, .L70003960
/* 004550 70003950 3C018000 */   lui   $at, 0x8000
/* 004554 70003954 17210002 */  bne   $t9, $at, .L70003960
/* 004558 70003958 00000000 */   nop   
/* 00455C 7000395C 0006000D */  break 6
.L70003960:
/* 004560 70003960 304EFFFF */  andi  $t6, $v0, 0xffff
/* 004564 70003964 01C5C821 */  addu  $t9, $t6, $a1
/* 004568 70003968 00007810 */  mfhi  $t7
/* 00456C 7000396C 000FC400 */  sll   $t8, $t7, 0x10
/* 004570 70003970 240E0001 */  li    $t6, 1
/* 004574 70003974 0326001A */  div   $zero, $t9, $a2
/* 004578 70003978 14C00002 */  bnez  $a2, .L70003984
/* 00457C 7000397C 00000000 */   nop   
/* 004580 70003980 0007000D */  break 7
.L70003984:
/* 004584 70003984 2401FFFF */  li    $at, -1
/* 004588 70003988 14C10004 */  bne   $a2, $at, .L7000399C
/* 00458C 7000398C 3C018000 */   lui   $at, 0x8000
/* 004590 70003990 17210002 */  bne   $t9, $at, .L7000399C
/* 004594 70003994 00000000 */   nop   
/* 004598 70003998 0006000D */  break 6
.L7000399C:
/* 00459C 7000399C 00007810 */  mfhi  $t7
/* 0045A0 700039A0 030F2025 */  or    $a0, $t8, $t7
/* 0045A4 700039A4 AC640044 */  sw    $a0, 0x44($v1)
/* 0045A8 700039A8 3C018006 */  lui   $at, %hi(viMode+0xC)
/* 0045AC 700039AC AC240888 */  sw    $a0, %lo(viMode+0xC)($at)
/* 0045B0 700039B0 3C018002 */  lui   $at, %hi(something_with_osVI_14)
/* 0045B4 700039B4 00290821 */  addu  $at, $at, $t1
/* 0045B8 700039B8 10000006 */  b     .L700039D4
/* 0045BC 700039BC AC2E30C4 */   sw    $t6, %lo(something_with_osVI_14)($at)
.L700039C0:
/* 0045C0 700039C0 3C018002 */  lui   $at, %hi(something_with_osVI_14)
/* 0045C4 700039C4 00290821 */  addu  $at, $at, $t1
/* 0045C8 700039C8 3C0B8002 */  lui   $t3, %hi(coloroutputmode) 
/* 0045CC 700039CC 8D6B32AC */  lw    $t3, %lo(coloroutputmode)($t3)
/* 0045D0 700039D0 AC2030C4 */  sw    $zero, %lo(something_with_osVI_14)($at)
.L700039D4:
/* 0045D4 700039D4 254A0001 */  addiu $t2, $t2, 1
/* 0045D8 700039D8 05410004 */  bgez  $t2, .L700039EC
/* 0045DC 700039DC 31590001 */   andi  $t9, $t2, 1
/* 0045E0 700039E0 13200002 */  beqz  $t9, .L700039EC
/* 0045E4 700039E4 00000000 */   nop   
/* 0045E8 700039E8 2739FFFE */  addiu $t9, $t9, -2
.L700039EC:
/* 0045EC 700039EC 3C018002 */  lui   $at, %hi(D_800232C0)
/* 0045F0 700039F0 11600006 */  beqz  $t3, .L70003A0C
/* 0045F4 700039F4 AC3932C0 */   sw    $t9, %lo(D_800232C0)($at)
/* 0045F8 700039F8 3C0F8005 */  lui   $t7, %hi(fast3d_related_array) 
/* 0045FC 700039FC 8DEFEAB0 */  lw    $t7, %lo(fast3d_related_array)($t7)
/* 004600 70003A00 8D180028 */  lw    $t8, 0x28($t0)
/* 004604 70003A04 10000006 */  b     .L70003A20
/* 004608 70003A08 ADF80058 */   sw    $t8, 0x58($t7)
.L70003A0C:
/* 00460C 70003A0C 3C198005 */  lui   $t9, %hi(fast3d_related_array) 
/* 004610 70003A10 8F39EAB0 */  lw    $t9, %lo(fast3d_related_array)($t9)
/* 004614 70003A14 3C0E803B */  lui   $t6, %hi(cfb_16) # $t6, 0x803b
/* 004618 70003A18 25CE5000 */  addiu $t6, %lo(cfb_16) # addiu $t6, $t6, 0x5000
/* 00461C 70003A1C AF2E0058 */  sw    $t6, 0x58($t9)
.L70003A20:
/* 004620 70003A20 3C028006 */  lui   $v0, %hi(off_CODE_bss_80060878)
/* 004624 70003A24 24420878 */  addiu $v0, %lo(off_CODE_bss_80060878) # addiu $v0, $v0, 0x878
/* 004628 70003A28 90580000 */  lbu   $t8, ($v0)
/* 00462C 70003A2C 3C038006 */  lui   $v1, %hi(off_CODE_bss_80060879)
/* 004630 70003A30 2408002C */  li    $t0, 44
/* 004634 70003A34 270F0001 */  addiu $t7, $t8, 1
/* 004638 70003A38 24630879 */  addiu $v1, %lo(off_CODE_bss_80060879) # addiu $v1, $v1, 0x879
/* 00463C 70003A3C 90790000 */  lbu   $t9, ($v1)
/* 004640 70003A40 3C078002 */  lui   $a3, %hi(video1_settings)
/* 004644 70003A44 24E73244 */  addiu $a3, %lo(video1_settings) # addiu $a3, $a3, 0x3244
/* 004648 70003A48 27380001 */  addiu $t8, $t9, 1
/* 00464C 70003A4C 8DA40000 */  lw    $a0, ($t5)
/* 004650 70003A50 05E10004 */  bgez  $t7, .L70003A64
/* 004654 70003A54 31EE0001 */   andi  $t6, $t7, 1
/* 004658 70003A58 11C00002 */  beqz  $t6, .L70003A64
/* 00465C 70003A5C 00000000 */   nop   
/* 004660 70003A60 25CEFFFE */  addiu $t6, $t6, -2
.L70003A64:
/* 004664 70003A64 A04E0000 */  sb    $t6, ($v0)
/* 004668 70003A68 904E0000 */  lbu   $t6, ($v0)
/* 00466C 70003A6C 07010004 */  bgez  $t8, .L70003A80
/* 004670 70003A70 330F0001 */   andi  $t7, $t8, 1
/* 004674 70003A74 11E00002 */  beqz  $t7, .L70003A80
/* 004678 70003A78 00000000 */   nop   
/* 00467C 70003A7C 25EFFFFE */  addiu $t7, $t7, -2
.L70003A80:
/* 004680 70003A80 01C80019 */  multu $t6, $t0
/* 004684 70003A84 A06F0000 */  sb    $t7, ($v1)
/* 004688 70003A88 3C018002 */  lui   $at, %hi(ptr_video_settings1)
/* 00468C 70003A8C 2406002C */  li    $a2, 44
/* 004690 70003A90 0000C812 */  mflo  $t9
/* 004694 70003A94 00F9C021 */  addu  $t8, $a3, $t9
/* 004698 70003A98 AC3832A4 */  sw    $t8, %lo(ptr_video_settings1)($at)
/* 00469C 70003A9C 906F0000 */  lbu   $t7, ($v1)
/* 0046A0 70003AA0 01E80019 */  multu $t7, $t0
/* 0046A4 70003AA4 00007012 */  mflo  $t6
/* 0046A8 70003AA8 00EE2821 */  addu  $a1, $a3, $t6
/* 0046AC 70003AAC 0C003E5C */  jal   bcopy
/* 0046B0 70003AB0 ADA50000 */   sw    $a1, ($t5)
/* 0046B4 70003AB4 3C038006 */  lui   $v1, %hi(off_CODE_bss_80060879)
/* 0046B8 70003AB8 24630879 */  addiu $v1, %lo(off_CODE_bss_80060879) # addiu $v1, $v1, 0x879
/* 0046BC 70003ABC 90780000 */  lbu   $t8, ($v1)
/* 0046C0 70003AC0 3C0E803B */  lui   $t6, %hi(cfb_16) # $t6, 0x803b
/* 0046C4 70003AC4 25CE5000 */  addiu $t6, %lo(cfb_16) # addiu $t6, $t6, 0x5000
/* 0046C8 70003AC8 00187880 */  sll   $t7, $t8, 2
/* 0046CC 70003ACC 01F87821 */  addu  $t7, $t7, $t8
/* 0046D0 70003AD0 000F7880 */  sll   $t7, $t7, 2
/* 0046D4 70003AD4 01F87823 */  subu  $t7, $t7, $t8
/* 0046D8 70003AD8 000F7880 */  sll   $t7, $t7, 2
/* 0046DC 70003ADC 01F87823 */  subu  $t7, $t7, $t8
/* 0046E0 70003AE0 3C188002 */  lui   $t8, %hi(ptr_video_settings2) 
/* 0046E4 70003AE4 8F1832A8 */  lw    $t8, %lo(ptr_video_settings2)($t8)
/* 0046E8 70003AE8 000F7AC0 */  sll   $t7, $t7, 0xb
/* 0046EC 70003AEC 01EEC821 */  addu  $t9, $t7, $t6
/* 0046F0 70003AF0 AF190028 */  sw    $t9, 0x28($t8)
/* 0046F4 70003AF4 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0046F8 70003AF8 27BD0018 */  addiu $sp, $sp, 0x18
/* 0046FC 70003AFC 03E00008 */  jr    $ra
/* 004700 70003B00 00000000 */   nop   
)
#endif

void viSet800232B4(f32 param_1)
{
    if (param_1 > 14.0f) {
        param_1 = 14.0f;
    }
    if (param_1 < 0.0f) {
        param_1 = 0.0f;
    }
    D_800232B4 = param_1;
    D_800232B8 = 10;
}

void viRecvMesg(int count) {
    do {
        osRecvMesg(&vi_c_debug_MQ, NULL, 1);
        count--;
    } while (count > 0);
}

const s16 widths_80028480[] = {320, 320, 640};
const s16 heights_80028488[] = {240, 240, 480};
void viSetVideoMode(s32 videomode)
{
    ptr_video_settings2->mode = videomode;
    ptr_video_settings2->x = ptr_video_settings2->bufx = widths_80028480[videomode];
    ptr_video_settings2->y = ptr_video_settings2->bufy = heights_80028488[videomode];
}

void viSetColorMode16Bit(void)
{
    coloroutputmode = COLORMODE_16BIT;
}

void viSetColorMode32Bit(void)
{
    coloroutputmode = COLORMODE_32BIT;
}

u8 *viGetFrameBuf2(void)
{
    return ptr_video_settings2->framebuf;
}

u8 *viGetFrameBuf1(void)
{
    return ptr_video_settings1->framebuf;
}

void viSetFrameBuf2(u8 *buf)
{
    ptr_video_settings2->framebuf = buf;
}

u16 viGetPerspNorm(void) {
    return perspNorm;
}

Gfx *video_related_F(Gfx *gdl) {
    if (pPlayer != NULL) {
        pPlayer->viewports[off_CODE_bss_80060879].vp.vscale[0] = (ptr_video_settings2->viewx * 2);
        pPlayer->viewports[off_CODE_bss_80060879].vp.vtrans[0] = (ptr_video_settings2->viewx * 2) + (ptr_video_settings2->viewleft * 4);
        pPlayer->viewports[off_CODE_bss_80060879].vp.vscale[1] = (ptr_video_settings2->viewy * 2);
        pPlayer->viewports[off_CODE_bss_80060879].vp.vtrans[1] = (ptr_video_settings2->viewy * 2) + (ptr_video_settings2->viewtop * 4);
    }

    gSPViewport(gdl++, OS_K0_TO_PHYSICAL(&pPlayer->viewports[off_CODE_bss_80060879]));

    projectionMatrix = dynAllocateMatrix();    
    guPerspectiveF(projectionMatrixF, &perspNorm, ptr_video_settings2->fovy, ptr_video_settings2->aspect, ptr_video_settings2->znear, ptr_video_settings2->zfar, 1.0f);
    guMtxF2L(projectionMatrixF, projectionMatrix);
    gSPMatrix(gdl++, OS_K0_TO_PHYSICAL(projectionMatrix), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gSPPerspNormalize(gdl++, perspNorm);
    currentPlayerSetProjectionMatrix(projectionMatrix);
    currentPlayerSetProjectionMatrixF(projectionMatrixF);
    if (coloroutputmode != COLORMODE_32BIT) {
        gDPSetColorImage(gdl++, G_IM_FMT_RGBA, G_IM_SIZ_16b, ptr_video_settings2->bufx, OS_K0_TO_PHYSICAL(ptr_video_settings2->framebuf));
    }
    else {
        gDPSetColorImage(gdl++, G_IM_FMT_RGBA, G_IM_SIZ_32b, ptr_video_settings2->bufx, OS_K0_TO_PHYSICAL(cfb_16[0]));
    }

    return gdl;
}

Gfx *zbufClearCurrentPlayer(Gfx *gdl);
Gfx *zbufInit(Gfx *gdl);
Gfx *viClearZBufCurrentPlayer(Gfx *gdl) {
    if (ptr_video_settings2->usezbuf != 0) {
        gdl = zbufClearCurrentPlayer(zbufInit(gdl));
    }    
    return gdl;
}

Gfx *viFillScreen(Gfx *gdl) {	
	gDPSetCycleType(gdl++, G_CYC_FILL);
	gDPFillRectangle(gdl++, 0, 0, (ptr_video_settings2->bufx - 1), (ptr_video_settings2->bufy - 1));
	gDPPipeSync(gdl++);

    return gdl;
}

Gfx *setupscreensfornumplayers(Gfx *gdl) {
    gDPSetCycleType(gdl++, G_CYC_FILL);
    gDPSetScissor(gdl++, G_SC_NON_INTERLACE, 0, 0, viGetX(), viGetY());
    gDPSetFillColor(gdl++, ((GPACK_RGBA5551(0,0,0,1) << 16) | GPACK_RGBA5551(0,0,0,1)));

    if (viGetViewTop() > 0) {
        if (sub_GAME_7F09B4D8(get_cur_playernum()) == 0) {
            gDPFillRectangle(gdl++, 0, 0, (viGetX() - 1), (viGetViewTop() - 1));
            gDPPipeSync(gdl++);
        }
    }

    if (getPlayerCount() == 1) {
        if ((viGetViewTop() + viGetViewHeight()) < viGetY()) {
            gDPFillRectangle(gdl++, 0, (viGetViewTop() + viGetViewHeight()), (viGetX() - 1), (viGetY() - 1));
            gDPPipeSync(gdl++);
        }
    } else {
        if (sub_GAME_7F09B4D8(get_cur_playernum()) == 0) {
            if ((viGetViewTop() + viGetViewHeight() + viGetViewHeight()) < viGetY()) {
                gDPFillRectangle(gdl++, 0, (viGetViewTop() + viGetViewHeight() + viGetViewHeight()), (viGetX() - 1), (viGetY() - 1));
                gDPPipeSync(gdl++);
            }

            gDPFillRectangle(gdl++, 0, ((240 / 2) - 1), (viGetX() - 1), (240 / 2));
            gDPPipeSync(gdl++);

            if (getPlayerCount() >= 3) {
                gDPFillRectangle(gdl++, ((320 / 2) - 1), 0, (320 / 2), (viGetY() - 1));
                gDPPipeSync(gdl++);
            }

            if (getPlayerCount() == 3) {
                gDPFillRectangle(gdl++, ((320 / 2) + 1), ((240 / 2) + 1), (viGetX() - 1), (viGetY() - 1));
                gDPPipeSync(gdl++);
            }
        }
    }

    return gdl;
}

void viSet800232A0(s32 arg0) {
    D_800232A0 = arg0;
}

s32 viGet800232A0(void) {
    return D_800232A0;
}

void viSet8002329C(s32 arg0) {
    D_8002329C = arg0;
}

s32 viGet8002329C(void) {
    return D_8002329C;
}

void viSetBuf(s16 x, s16 y) {
    ptr_video_settings2->bufx = x;
    ptr_video_settings2->bufy = y;
}

s16 viGetBufX(void) {
    return ptr_video_settings2->bufx;
}

s16 viGetBufY(void) {
    return ptr_video_settings2->bufy;
}

void viSetXY(s16 x, s16 y) {
    ptr_video_settings2->x = x;
    ptr_video_settings2->y = y;
}

s16 viGetX(void) {
    return ptr_video_settings2->x;
}

s16 viGetY(void) {
    return ptr_video_settings2->y;
}

void currentPlayerSetScreenSize(f32 width, f32 height);
void currentPlayerSetCameraScale(void);
void viSetViewSize(s16 x, s16 y) {
    ptr_video_settings2->viewx = x;
    ptr_video_settings2->viewy = y;
    currentPlayerSetScreenSize(ptr_video_settings2->viewx, ptr_video_settings2->viewy);
    currentPlayerSetCameraScale();
}

s16 viGetViewWidth(void) {
    return ptr_video_settings2->viewx;
}

s16 viGetViewHeight(void) {
    return ptr_video_settings2->viewy;
}

void currentPlayerSetScreenPosition(f32 left, f32 top);
void viSetViewPosition(s16 left, s16 top) {
    ptr_video_settings2->viewleft = left;
    ptr_video_settings2->viewtop = top;
    currentPlayerSetScreenPosition(ptr_video_settings2->viewleft, ptr_video_settings2->viewtop);
}

s16 viGetViewLeft(void) {
    return ptr_video_settings2->viewleft;
}

s16 viGetViewTop(void) {
    return ptr_video_settings2->viewtop;
}

void viSetUseZBuf(s32 usezbuf) {
  ptr_video_settings2->usezbuf = usezbuf;
}

void currentPlayerSetPerspective(f32 znear, f32 fovy, f32 aspect);
void viSetFovY(f32 fovy) {
    ptr_video_settings2->fovy = fovy;
    currentPlayerSetPerspective(ptr_video_settings2->znear, ptr_video_settings2->fovy, ptr_video_settings2->aspect);
    currentPlayerSetCameraScale();
}

void viSetAspect(f32 aspect) {
    ptr_video_settings2->aspect = aspect;
    currentPlayerSetPerspective(ptr_video_settings2->znear, ptr_video_settings2->fovy, ptr_video_settings2->aspect);
    currentPlayerSetCameraScale();
}

f32 viGetFovY(void) {
    return ptr_video_settings2->fovy;
}

void viSetFov(f32 fovx, f32 fovy) {
    ptr_video_settings2->fovy = fovy;
    ptr_video_settings2->aspect = (f32) (fovx / fovy);
    currentPlayerSetPerspective(ptr_video_settings2->znear, ptr_video_settings2->fovy, ptr_video_settings2->aspect);
    currentPlayerSetCameraScale();
}

void viSetZRange(f32 near, f32 far) {
    ptr_video_settings2->znear = near;
    ptr_video_settings2->zfar = far;
    currentPlayerSetPerspective(ptr_video_settings2->znear, ptr_video_settings2->fovy, ptr_video_settings2->aspect);
    currentPlayerSetCameraScale();
}

void viGetZRange(f32 *zrange) {
    zrange[0] = ptr_video_settings2->znear;
    zrange[1] = ptr_video_settings2->zfar;
}

Gfx *viSetFillColor(Gfx *gdl, s32 r, s32 g, s32 b) {
    if (coloroutputmode != COLORMODE_32BIT) {
        gDPSetFillColor(gdl++, ((GPACK_RGBA5551(r, g, b, 1) << 16) | GPACK_RGBA5551(r, g, b, 1)));
    } else {
        gDPSetFillColor(gdl++, ((r << 24) | (g << 16) | (b << 8) | 0xFF));
    }
    
    return gdl;
}

/**
 * 5358	70004758
 *     image capture routine, jpeg 16bit colour
 */
#ifdef NONMATCHING
s32 check_file_found_on_indy(s32, s32);
void indy_send_capture_data(s32, s32, s32);
s32 send_command_string(s32);
int sprintf(char *str, const char *fmt, ...);
void indy_grab_jpg_16bit(void)
{
    char buffer[256];
    u32 bufferSize;
    
    while(TRUE) {
        sprintf(buffer, "grab.%d.jpeg", jpg_16bit_grabnum);
        if (check_file_found_on_indy(buffer, &bufferSize) == 0) break;
        jpg_16bit_grabnum++;
    }
    sprintf(buffer, "grab.%d.temp.uix", jpg_16bit_grabnum);
    indy_send_capture_data(buffer, ptr_video_settings2->framebuf, (viGetY() * viGetX() * 2));
    sprintf(buffer, "uix2pix grab.%d.temp.uix", jpg_16bit_grabnum);
    send_command_string(buffer);
    sprintf(buffer, "fromalias grab.%d.temp.pix grab.%d.temp.rgb", jpg_16bit_grabnum, jpg_16bit_grabnum);
    send_command_string(buffer);
    sprintf(buffer, "imgcopy -fjfif grab.%d.temp.rgb grab.%d.jpeg", jpg_16bit_grabnum, jpg_16bit_grabnum);
    send_command_string(buffer);
    sprintf(buffer, "rm grab.%d.temp.uix grab.%d.temp.pix grab.%d.temp.rgb", jpg_16bit_grabnum, jpg_16bit_grabnum, jpg_16bit_grabnum);
    send_command_string(buffer);
    sprintf(buffer, "imgview grab.%d.jpeg", jpg_16bit_grabnum);
    send_command_string(buffer);
}
#else
const char aGrab_D_jpeg_1[] = "grab.%d.jpeg";
const char aGrab_D_temp_uix[] = "grab.%d.temp.uix";
const char aUix2pixGrab_D_temp_uix[] = "uix2pix grab.%d.temp.uix";
const char aFromaliasGrab_D_temp_pixGrab_D_tem[] = "fromalias grab.%d.temp.pix grab.%d.temp.rgb";
const char aImgcopyFjfifGrab_D_temp_rgbGrab_D_[] = "imgcopy -fjfif grab.%d.temp.rgb grab.%d.jpeg";
const char aRmGrab_D_temp_uixGrab_D_temp_pixGr[] = "rm grab.%d.temp.uix grab.%d.temp.pix grab.%d.temp.rgb";
const char aImgviewGrab_D_jpeg[] = "imgview grab.%d.jpeg";
GLOBAL_ASM(
.text
glabel indy_grab_jpg_16bit
/* 005358 70004758 27BDFEC8 */  addiu $sp, $sp, -0x138
/* 00535C 7000475C AFB10024 */  sw    $s1, 0x24($sp)
/* 005360 70004760 AFB20028 */  sw    $s2, 0x28($sp)
/* 005364 70004764 AFB00020 */  sw    $s0, 0x20($sp)
/* 005368 70004768 3C118003 */  lui   $s1, %hi(aGrab_D_jpeg_1)
/* 00536C 7000476C AFBF002C */  sw    $ra, 0x2c($sp)
/* 005370 70004770 26318490 */  addiu $s1, %lo(aGrab_D_jpeg_1) # addiu $s1, $s1, -0x7b70
/* 005374 70004774 27B00038 */  addiu $s0, $sp, 0x38
/* 005378 70004778 27B20034 */  addiu $s2, $sp, 0x34
.L7000477C:
/* 00537C 7000477C 3C068002 */  lui   $a2, %hi(jpg_16bit_grabnum)
/* 005380 70004780 8CC632C4 */  lw    $a2, %lo(jpg_16bit_grabnum)($a2)
/* 005384 70004784 02002025 */  move  $a0, $s0
/* 005388 70004788 0C002B25 */  jal   sprintf
/* 00538C 7000478C 02202825 */   move  $a1, $s1
/* 005390 70004790 02002025 */  move  $a0, $s0
/* 005394 70004794 0FC34026 */  jal   check_file_found_on_indy
/* 005398 70004798 02402825 */   move  $a1, $s2
/* 00539C 7000479C 10400006 */  beqz  $v0, .L700047B8
/* 0053A0 700047A0 3C068002 */   lui   $a2, %hi(jpg_16bit_grabnum)
/* 0053A4 700047A4 8CC632C4 */  lw    $a2, %lo(jpg_16bit_grabnum)($a2)
/* 0053A8 700047A8 3C018002 */  lui   $at, %hi(jpg_16bit_grabnum)
/* 0053AC 700047AC 24C60001 */  addiu $a2, $a2, 1
/* 0053B0 700047B0 1000FFF2 */  b     .L7000477C
/* 0053B4 700047B4 AC2632C4 */   sw    $a2, %lo(jpg_16bit_grabnum)($at)
.L700047B8:
/* 0053B8 700047B8 3C068002 */  lui   $a2, %hi(jpg_16bit_grabnum)
/* 0053BC 700047BC 3C058003 */  lui   $a1, %hi(aGrab_D_temp_uix)
/* 0053C0 700047C0 8CC632C4 */  lw    $a2, %lo(jpg_16bit_grabnum)($a2)
/* 0053C4 700047C4 24A584A0 */  addiu $a1, %lo(aGrab_D_temp_uix) # addiu $a1, $a1, -0x7b60
/* 0053C8 700047C8 0C002B25 */  jal   sprintf
/* 0053CC 700047CC 02002025 */   move  $a0, $s0
/* 0053D0 700047D0 0C001107 */  jal   viGetX
/* 0053D4 700047D4 00000000 */   nop   
/* 0053D8 700047D8 00028C00 */  sll   $s1, $v0, 0x10
/* 0053DC 700047DC 00117403 */  sra   $t6, $s1, 0x10
/* 0053E0 700047E0 0C00110B */  jal   viGetY
/* 0053E4 700047E4 01C08825 */   move  $s1, $t6
/* 0053E8 700047E8 00510019 */  multu $v0, $s1
/* 0053EC 700047EC 3C0F8002 */  lui   $t7, %hi(ptr_video_settings2) 
/* 0053F0 700047F0 8DEF32A8 */  lw    $t7, %lo(ptr_video_settings2)($t7)
/* 0053F4 700047F4 02002025 */  move  $a0, $s0
/* 0053F8 700047F8 8DE50028 */  lw    $a1, 0x28($t7)
/* 0053FC 700047FC 00003012 */  mflo  $a2
/* 005400 70004800 0006C040 */  sll   $t8, $a2, 1
/* 005404 70004804 0FC33FF8 */  jal   indy_send_capture_data
/* 005408 70004808 03003025 */   move  $a2, $t8
/* 00540C 7000480C 3C068002 */  lui   $a2, %hi(jpg_16bit_grabnum)
/* 005410 70004810 3C058003 */  lui   $a1, %hi(aUix2pixGrab_D_temp_uix)
/* 005414 70004814 8CC632C4 */  lw    $a2, %lo(jpg_16bit_grabnum)($a2)
/* 005418 70004818 24A584B4 */  addiu $a1, %lo(aUix2pixGrab_D_temp_uix) # addiu $a1, $a1, -0x7b4c
/* 00541C 7000481C 0C002B25 */  jal   sprintf
/* 005420 70004820 02002025 */   move  $a0, $s0
/* 005424 70004824 0FC34038 */  jal   send_command_string
/* 005428 70004828 02002025 */   move  $a0, $s0
/* 00542C 7000482C 3C068002 */  lui   $a2, %hi(jpg_16bit_grabnum)
/* 005430 70004830 8CC632C4 */  lw    $a2, %lo(jpg_16bit_grabnum)($a2)
/* 005434 70004834 3C058003 */  lui   $a1, %hi(aFromaliasGrab_D_temp_pixGrab_D_tem)
/* 005438 70004838 24A584D0 */  addiu $a1, %lo(aFromaliasGrab_D_temp_pixGrab_D_tem) # addiu $a1, $a1, -0x7b30
/* 00543C 7000483C 02002025 */  move  $a0, $s0
/* 005440 70004840 0C002B25 */  jal   sprintf
/* 005444 70004844 00C03825 */   move  $a3, $a2
/* 005448 70004848 0FC34038 */  jal   send_command_string
/* 00544C 7000484C 02002025 */   move  $a0, $s0
/* 005450 70004850 3C068002 */  lui   $a2, %hi(jpg_16bit_grabnum)
/* 005454 70004854 8CC632C4 */  lw    $a2, %lo(jpg_16bit_grabnum)($a2)
/* 005458 70004858 3C058003 */  lui   $a1, %hi(aImgcopyFjfifGrab_D_temp_rgbGrab_D_)
/* 00545C 7000485C 24A584FC */  addiu $a1, %lo(aImgcopyFjfifGrab_D_temp_rgbGrab_D_) # addiu $a1, $a1, -0x7b04
/* 005460 70004860 02002025 */  move  $a0, $s0
/* 005464 70004864 0C002B25 */  jal   sprintf
/* 005468 70004868 00C03825 */   move  $a3, $a2
/* 00546C 7000486C 0FC34038 */  jal   send_command_string
/* 005470 70004870 02002025 */   move  $a0, $s0
/* 005474 70004874 3C068002 */  lui   $a2, %hi(jpg_16bit_grabnum)
/* 005478 70004878 8CC632C4 */  lw    $a2, %lo(jpg_16bit_grabnum)($a2)
/* 00547C 7000487C 3C058003 */  lui   $a1, %hi(aRmGrab_D_temp_uixGrab_D_temp_pixGr)
/* 005480 70004880 24A5852C */  addiu $a1, %lo(aRmGrab_D_temp_uixGrab_D_temp_pixGr) # addiu $a1, $a1, -0x7ad4
/* 005484 70004884 02002025 */  move  $a0, $s0
/* 005488 70004888 00C03825 */  move  $a3, $a2
/* 00548C 7000488C 0C002B25 */  jal   sprintf
/* 005490 70004890 AFA60010 */   sw    $a2, 0x10($sp)
/* 005494 70004894 0FC34038 */  jal   send_command_string
/* 005498 70004898 02002025 */   move  $a0, $s0
/* 00549C 7000489C 3C068002 */  lui   $a2, %hi(jpg_16bit_grabnum)
/* 0054A0 700048A0 3C058003 */  lui   $a1, %hi(aImgviewGrab_D_jpeg)
/* 0054A4 700048A4 8CC632C4 */  lw    $a2, %lo(jpg_16bit_grabnum)($a2)
/* 0054A8 700048A8 24A58564 */  addiu $a1, %lo(aImgviewGrab_D_jpeg) # addiu $a1, $a1, -0x7a9c
/* 0054AC 700048AC 0C002B25 */  jal   sprintf
/* 0054B0 700048B0 02002025 */   move  $a0, $s0
/* 0054B4 700048B4 0FC34038 */  jal   send_command_string
/* 0054B8 700048B8 02002025 */   move  $a0, $s0
/* 0054BC 700048BC 8FBF002C */  lw    $ra, 0x2c($sp)
/* 0054C0 700048C0 8FB00020 */  lw    $s0, 0x20($sp)
/* 0054C4 700048C4 8FB10024 */  lw    $s1, 0x24($sp)
/* 0054C8 700048C8 8FB20028 */  lw    $s2, 0x28($sp)
/* 0054CC 700048CC 03E00008 */  jr    $ra
/* 0054D0 700048D0 27BD0138 */   addiu $sp, $sp, 0x138
)
#endif

/**
 * 54D4	700048D4
 *     image capture routine, jpeg 32bit colour
 */
#ifdef NONMATCHING
void indy_grab_jpg_32bit(void)
{
    char buffer [256];
    ? sp34;

loop_1:
    sprintf(&buffer, "grab.%d.jpeg", jpg_32bit_grabnum);
    if (check_file_found_on_indy(&buffer, &sp34) != 0)
    {
        jpg_32bit_grabnum = (s32) (jpg_32bit_grabnum + 1);
        goto loop_1;
    }
    sprintf(&buffer, "grab.%d.temp.Uix", jpg_32bit_grabnum);
    indy_send_capture_data(&buffer, &cfb_16, (viGetY() * ((s32) (viGetX() << 0x10) >> 0x10)) * 4);
    sprintf(&buffer, "Uix2pix -xs%d grab.%d.temp.Uix", viGetX(), jpg_32bit_grabnum);
    send_command_string(&buffer);
    sprintf(&buffer, "fromalias grab.%d.temp.pix grab.%d.temp.rgb", jpg_32bit_grabnum, jpg_32bit_grabnum);
    send_command_string(&buffer);
    sprintf(&buffer, "imgcopy -fjfif grab.%d.temp.rgb grab.%d.jpeg", jpg_32bit_grabnum, jpg_32bit_grabnum);
    send_command_string(&buffer);
    sprintf(&buffer, "rm grab.%d.temp.Uix grab.%d.temp.pix grab.%d.temp.rgb", jpg_32bit_grabnum, jpg_32bit_grabnum);
    send_command_string(&buffer);
    sprintf(&buffer, "imgview grab.%d.jpeg", jpg_32bit_grabnum);
    send_command_string(&buffer);
}
#else
const char aGrab_D_jpeg[] = "grab.%d.jpeg";
const char aGrab_D_temp_uix_0[] = "grab.%d.temp.Uix";
const char aUix2pixXsDGrab_D_temp_uix[] = "Uix2pix -xs%d grab.%d.temp.Uix";
const char aFromaliasGrab_D_temp_pixGrab_D_t_0[] = "fromalias grab.%d.temp.pix grab.%d.temp.rgb";
const char aImgcopyFjfifGrab_D_temp_rgbGrab__0[] = "imgcopy -fjfif grab.%d.temp.rgb grab.%d.jpeg";
const char aRmGrab_D_temp_uixGrab_D_temp_pix_0[] = "rm grab.%d.temp.Uix grab.%d.temp.pix grab.%d.temp.rgb";
const char aImgviewGrab_D_jpeg_0[] = "imgview grab.%d.jpeg";
GLOBAL_ASM(
.text
glabel indy_grab_jpg_32bit
/* 0054D4 700048D4 27BDFEC8 */  addiu $sp, $sp, -0x138
/* 0054D8 700048D8 AFB10020 */  sw    $s1, 0x20($sp)
/* 0054DC 700048DC AFB20024 */  sw    $s2, 0x24($sp)
/* 0054E0 700048E0 AFB0001C */  sw    $s0, 0x1c($sp)
/* 0054E4 700048E4 3C118003 */  lui   $s1, %hi(aGrab_D_jpeg)
/* 0054E8 700048E8 AFBF002C */  sw    $ra, 0x2c($sp)
/* 0054EC 700048EC AFB30028 */  sw    $s3, 0x28($sp)
/* 0054F0 700048F0 2631857C */  addiu $s1, %lo(aGrab_D_jpeg) # addiu $s1, $s1, -0x7a84
/* 0054F4 700048F4 27B00038 */  addiu $s0, $sp, 0x38
/* 0054F8 700048F8 27B20034 */  addiu $s2, $sp, 0x34
.L700048FC:
/* 0054FC 700048FC 3C138002 */  lui   $s3, %hi(jpg_32bit_grabnum)
/* 005500 70004900 8E6632C8 */  lw    $a2, %lo(jpg_32bit_grabnum)($s3)
/* 005504 70004904 02002025 */  move  $a0, $s0
/* 005508 70004908 0C002B25 */  jal   sprintf
/* 00550C 7000490C 02202825 */   move  $a1, $s1
/* 005510 70004910 02002025 */  move  $a0, $s0
/* 005514 70004914 0FC34026 */  jal   check_file_found_on_indy
/* 005518 70004918 02402825 */   move  $a1, $s2
/* 00551C 7000491C 10400006 */  beqz  $v0, .L70004938
/* 005520 70004920 3C138002 */   lui   $s3, %hi(jpg_32bit_grabnum)
/* 005524 70004924 8E7332C8 */  lw    $s3, %lo(jpg_32bit_grabnum)($s3)
/* 005528 70004928 3C018002 */  lui   $at, %hi(jpg_32bit_grabnum)
/* 00552C 7000492C 26730001 */  addiu $s3, $s3, 1
/* 005530 70004930 1000FFF2 */  b     .L700048FC
/* 005534 70004934 AC3332C8 */   sw    $s3, %lo(jpg_32bit_grabnum)($at)
.L70004938:
/* 005538 70004938 3C138002 */  lui   $s3, %hi(jpg_32bit_grabnum)
/* 00553C 7000493C 3C058003 */  lui   $a1, %hi(aGrab_D_temp_uix_0)
/* 005540 70004940 8E6632C8 */  lw    $a2, %lo(jpg_32bit_grabnum)($s3)
/* 005544 70004944 24A5858C */  addiu $a1, %lo(aGrab_D_temp_uix_0) # addiu $a1, $a1, -0x7a74
/* 005548 70004948 0C002B25 */  jal   sprintf
/* 00554C 7000494C 02002025 */   move  $a0, $s0
/* 005550 70004950 0C001107 */  jal   viGetX
/* 005554 70004954 00000000 */   nop   
/* 005558 70004958 00028C00 */  sll   $s1, $v0, 0x10
/* 00555C 7000495C 00117403 */  sra   $t6, $s1, 0x10
/* 005560 70004960 0C00110B */  jal   viGetY
/* 005564 70004964 01C08825 */   move  $s1, $t6
/* 005568 70004968 00510019 */  multu $v0, $s1
/* 00556C 7000496C 3C05803B */  lui   $a1, %hi(cfb_16) # $a1, 0x803b
/* 005570 70004970 24A55000 */  addiu $a1, %lo(cfb_16) # addiu $a1, $a1, 0x5000
/* 005574 70004974 02002025 */  move  $a0, $s0
/* 005578 70004978 00003012 */  mflo  $a2
/* 00557C 7000497C 00067880 */  sll   $t7, $a2, 2
/* 005580 70004980 0FC33FF8 */  jal   indy_send_capture_data
/* 005584 70004984 01E03025 */   move  $a2, $t7
/* 005588 70004988 0C001107 */  jal   viGetX
/* 00558C 7000498C 00000000 */   nop   
/* 005590 70004990 3C138002 */  lui   $s3, %hi(jpg_32bit_grabnum)
/* 005594 70004994 3C058003 */  lui   $a1, %hi(aUix2pixXsDGrab_D_temp_uix)
/* 005598 70004998 24A585A0 */  addiu $a1, %lo(aUix2pixXsDGrab_D_temp_uix) # addiu $a1, $a1, -0x7a60
/* 00559C 7000499C 8E6732C8 */  lw    $a3, %lo(jpg_32bit_grabnum)($s3)
/* 0055A0 700049A0 02002025 */  move  $a0, $s0
/* 0055A4 700049A4 0C002B25 */  jal   sprintf
/* 0055A8 700049A8 00403025 */   move  $a2, $v0
/* 0055AC 700049AC 0FC34038 */  jal   send_command_string
/* 0055B0 700049B0 02002025 */   move  $a0, $s0
/* 0055B4 700049B4 3C138002 */  lui   $s3, %hi(jpg_32bit_grabnum)
/* 0055B8 700049B8 8E6732C8 */  lw    $a3, %lo(jpg_32bit_grabnum)($s3)
/* 0055BC 700049BC 3C058003 */  lui   $a1, %hi(aFromaliasGrab_D_temp_pixGrab_D_t_0)
/* 0055C0 700049C0 24A585C0 */  addiu $a1, %lo(aFromaliasGrab_D_temp_pixGrab_D_t_0) # addiu $a1, $a1, -0x7a40
/* 0055C4 700049C4 02002025 */  move  $a0, $s0
/* 0055C8 700049C8 0C002B25 */  jal   sprintf
/* 0055CC 700049CC 00E03025 */   move  $a2, $a3
/* 0055D0 700049D0 0FC34038 */  jal   send_command_string
/* 0055D4 700049D4 02002025 */   move  $a0, $s0
/* 0055D8 700049D8 3C138002 */  lui   $s3, %hi(jpg_32bit_grabnum)
/* 0055DC 700049DC 8E6732C8 */  lw    $a3, %lo(jpg_32bit_grabnum)($s3)
/* 0055E0 700049E0 3C058003 */  lui   $a1, %hi(aImgcopyFjfifGrab_D_temp_rgbGrab__0)
/* 0055E4 700049E4 24A585EC */  addiu $a1, %lo(aImgcopyFjfifGrab_D_temp_rgbGrab__0) # addiu $a1, $a1, -0x7a14
/* 0055E8 700049E8 02002025 */  move  $a0, $s0
/* 0055EC 700049EC 0C002B25 */  jal   sprintf
/* 0055F0 700049F0 00E03025 */   move  $a2, $a3
/* 0055F4 700049F4 0FC34038 */  jal   send_command_string
/* 0055F8 700049F8 02002025 */   move  $a0, $s0
/* 0055FC 700049FC 3C138002 */  lui   $s3, %hi(jpg_32bit_grabnum)
/* 005600 70004A00 8E6732C8 */  lw    $a3, %lo(jpg_32bit_grabnum)($s3)
/* 005604 70004A04 3C058003 */  lui   $a1, %hi(aRmGrab_D_temp_uixGrab_D_temp_pix_0)
/* 005608 70004A08 24A5861C */  addiu $a1, %lo(aRmGrab_D_temp_uixGrab_D_temp_pix_0) # addiu $a1, $a1, -0x79e4
/* 00560C 70004A0C 02002025 */  move  $a0, $s0
/* 005610 70004A10 00E03025 */  move  $a2, $a3
/* 005614 70004A14 0C002B25 */  jal   sprintf
/* 005618 70004A18 AFA70010 */   sw    $a3, 0x10($sp)
/* 00561C 70004A1C 0FC34038 */  jal   send_command_string
/* 005620 70004A20 02002025 */   move  $a0, $s0
/* 005624 70004A24 3C138002 */  lui   $s3, %hi(jpg_32bit_grabnum)
/* 005628 70004A28 3C058003 */  lui   $a1, %hi(aImgviewGrab_D_jpeg_0)
/* 00562C 70004A2C 8E6632C8 */  lw    $a2, %lo(jpg_32bit_grabnum)($s3)
/* 005630 70004A30 24A58654 */  addiu $a1, %lo(aImgviewGrab_D_jpeg_0) # addiu $a1, $a1, -0x79ac
/* 005634 70004A34 0C002B25 */  jal   sprintf
/* 005638 70004A38 02002025 */   move  $a0, $s0
/* 00563C 70004A3C 0FC34038 */  jal   send_command_string
/* 005640 70004A40 02002025 */   move  $a0, $s0
/* 005644 70004A44 8FBF002C */  lw    $ra, 0x2c($sp)
/* 005648 70004A48 8FB0001C */  lw    $s0, 0x1c($sp)
/* 00564C 70004A4C 8FB10020 */  lw    $s1, 0x20($sp)
/* 005650 70004A50 8FB20024 */  lw    $s2, 0x24($sp)
/* 005654 70004A54 8FB30028 */  lw    $s3, 0x28($sp)
/* 005658 70004A58 03E00008 */  jr    $ra
/* 00565C 70004A5C 27BD0138 */   addiu $sp, $sp, 0x138
)
#endif

/**
 * 5660	70004A60
 *     image capture routine, rgb 16bit colour
 */
#ifdef NONMATCHING
void indy_grab_rgb_16bit(void)
{
    ? sp30;
    ? sp2C;

loop_1:
    sprintf(&sp30, "grab.%d.rgb", rgb_16bit_grabnum);
    if (check_file_found_on_indy(&sp30, &sp2C) != 0)
    {
        rgb_16bit_grabnum = (s32) (rgb_16bit_grabnum + 1);
        goto loop_1;
    }
    sprintf(&sp30, "grab.%d.temp.uix", rgb_16bit_grabnum);
    indy_send_capture_data(&sp30, ptr_video_settings2->framebuf, (viGetY() * ((s32) (viGetX() << 0x10) >> 0x10)) * 2);
    sprintf(&sp30, "uix2pix grab.%d.temp.uix", rgb_16bit_grabnum);
    send_command_string(&sp30);
    sprintf(&sp30, "fromalias grab.%d.temp.pix grab.%d.rgb", rgb_16bit_grabnum, rgb_16bit_grabnum);
    send_command_string(&sp30);
    sprintf(&sp30, "rm grab.%d.temp.uix grab.%d.temp.pix", rgb_16bit_grabnum, rgb_16bit_grabnum);
    send_command_string(&sp30);
    sprintf(&sp30, "imgview grab.%d.rgb", rgb_16bit_grabnum);
    send_command_string(&sp30);
}
#else
const char aGrab_D_rgb[] = "grab.%d.rgb";
const char aGrab_D_temp_uix_1[] = "grab.%d.temp.uix";
const char aUix2pixGrab_D_temp_uix_0[] = "uix2pix grab.%d.temp.uix";
const char aFromaliasGrab_D_temp_pixGrab_D_rgb[] = "fromalias grab.%d.temp.pix grab.%d.rgb";
const char aRmGrab_D_temp_uixGrab_D_temp_pix[] = "rm grab.%d.temp.uix grab.%d.temp.pix";
const char aImgviewGrab_D_rgb[] = "imgview grab.%d.rgb";
GLOBAL_ASM(
.text
glabel indy_grab_rgb_16bit
/* 005660 70004A60 27BDFED0 */  addiu $sp, $sp, -0x130
/* 005664 70004A64 AFB1001C */  sw    $s1, 0x1c($sp)
/* 005668 70004A68 AFB20020 */  sw    $s2, 0x20($sp)
/* 00566C 70004A6C AFB00018 */  sw    $s0, 0x18($sp)
/* 005670 70004A70 3C118003 */  lui   $s1, %hi(aGrab_D_rgb)
/* 005674 70004A74 AFBF0024 */  sw    $ra, 0x24($sp)
/* 005678 70004A78 2631866C */  addiu $s1, %lo(aGrab_D_rgb) # addiu $s1, $s1, -0x7994
/* 00567C 70004A7C 27B00030 */  addiu $s0, $sp, 0x30
/* 005680 70004A80 27B2002C */  addiu $s2, $sp, 0x2c
.L70004A84:
/* 005684 70004A84 3C068002 */  lui   $a2, %hi(rgb_16bit_grabnum)
/* 005688 70004A88 8CC632CC */  lw    $a2, %lo(rgb_16bit_grabnum)($a2)
/* 00568C 70004A8C 02002025 */  move  $a0, $s0
/* 005690 70004A90 0C002B25 */  jal   sprintf
/* 005694 70004A94 02202825 */   move  $a1, $s1
/* 005698 70004A98 02002025 */  move  $a0, $s0
/* 00569C 70004A9C 0FC34026 */  jal   check_file_found_on_indy
/* 0056A0 70004AA0 02402825 */   move  $a1, $s2
/* 0056A4 70004AA4 10400006 */  beqz  $v0, .L70004AC0
/* 0056A8 70004AA8 3C068002 */   lui   $a2, %hi(rgb_16bit_grabnum)
/* 0056AC 70004AAC 8CC632CC */  lw    $a2, %lo(rgb_16bit_grabnum)($a2)
/* 0056B0 70004AB0 3C018002 */  lui   $at, %hi(rgb_16bit_grabnum)
/* 0056B4 70004AB4 24C60001 */  addiu $a2, $a2, 1
/* 0056B8 70004AB8 1000FFF2 */  b     .L70004A84
/* 0056BC 70004ABC AC2632CC */   sw    $a2, %lo(rgb_16bit_grabnum)($at)
.L70004AC0:
/* 0056C0 70004AC0 3C068002 */  lui   $a2, %hi(rgb_16bit_grabnum)
/* 0056C4 70004AC4 3C058003 */  lui   $a1, %hi(aGrab_D_temp_uix_1)
/* 0056C8 70004AC8 8CC632CC */  lw    $a2, %lo(rgb_16bit_grabnum)($a2)
/* 0056CC 70004ACC 24A58678 */  addiu $a1, %lo(aGrab_D_temp_uix_1) # addiu $a1, $a1, -0x7988
/* 0056D0 70004AD0 0C002B25 */  jal   sprintf
/* 0056D4 70004AD4 02002025 */   move  $a0, $s0
/* 0056D8 70004AD8 0C001107 */  jal   viGetX
/* 0056DC 70004ADC 00000000 */   nop   
/* 0056E0 70004AE0 00028C00 */  sll   $s1, $v0, 0x10
/* 0056E4 70004AE4 00117403 */  sra   $t6, $s1, 0x10
/* 0056E8 70004AE8 0C00110B */  jal   viGetY
/* 0056EC 70004AEC 01C08825 */   move  $s1, $t6
/* 0056F0 70004AF0 00510019 */  multu $v0, $s1
/* 0056F4 70004AF4 3C0F8002 */  lui   $t7, %hi(ptr_video_settings2) 
/* 0056F8 70004AF8 8DEF32A8 */  lw    $t7, %lo(ptr_video_settings2)($t7)
/* 0056FC 70004AFC 02002025 */  move  $a0, $s0
/* 005700 70004B00 8DE50028 */  lw    $a1, 0x28($t7)
/* 005704 70004B04 00003012 */  mflo  $a2
/* 005708 70004B08 0006C040 */  sll   $t8, $a2, 1
/* 00570C 70004B0C 0FC33FF8 */  jal   indy_send_capture_data
/* 005710 70004B10 03003025 */   move  $a2, $t8
/* 005714 70004B14 3C068002 */  lui   $a2, %hi(rgb_16bit_grabnum)
/* 005718 70004B18 3C058003 */  lui   $a1, %hi(aUix2pixGrab_D_temp_uix_0)
/* 00571C 70004B1C 8CC632CC */  lw    $a2, %lo(rgb_16bit_grabnum)($a2)
/* 005720 70004B20 24A5868C */  addiu $a1, %lo(aUix2pixGrab_D_temp_uix_0) # addiu $a1, $a1, -0x7974
/* 005724 70004B24 0C002B25 */  jal   sprintf
/* 005728 70004B28 02002025 */   move  $a0, $s0
/* 00572C 70004B2C 0FC34038 */  jal   send_command_string
/* 005730 70004B30 02002025 */   move  $a0, $s0
/* 005734 70004B34 3C068002 */  lui   $a2, %hi(rgb_16bit_grabnum)
/* 005738 70004B38 8CC632CC */  lw    $a2, %lo(rgb_16bit_grabnum)($a2)
/* 00573C 70004B3C 3C058003 */  lui   $a1, %hi(aFromaliasGrab_D_temp_pixGrab_D_rgb)
/* 005740 70004B40 24A586A8 */  addiu $a1, %lo(aFromaliasGrab_D_temp_pixGrab_D_rgb) # addiu $a1, $a1, -0x7958
/* 005744 70004B44 02002025 */  move  $a0, $s0
/* 005748 70004B48 0C002B25 */  jal   sprintf
/* 00574C 70004B4C 00C03825 */   move  $a3, $a2
/* 005750 70004B50 0FC34038 */  jal   send_command_string
/* 005754 70004B54 02002025 */   move  $a0, $s0
/* 005758 70004B58 3C068002 */  lui   $a2, %hi(rgb_16bit_grabnum)
/* 00575C 70004B5C 8CC632CC */  lw    $a2, %lo(rgb_16bit_grabnum)($a2)
/* 005760 70004B60 3C058003 */  lui   $a1, %hi(aRmGrab_D_temp_uixGrab_D_temp_pix)
/* 005764 70004B64 24A586D0 */  addiu $a1, %lo(aRmGrab_D_temp_uixGrab_D_temp_pix) # addiu $a1, $a1, -0x7930
/* 005768 70004B68 02002025 */  move  $a0, $s0
/* 00576C 70004B6C 0C002B25 */  jal   sprintf
/* 005770 70004B70 00C03825 */   move  $a3, $a2
/* 005774 70004B74 0FC34038 */  jal   send_command_string
/* 005778 70004B78 02002025 */   move  $a0, $s0
/* 00577C 70004B7C 3C068002 */  lui   $a2, %hi(rgb_16bit_grabnum)
/* 005780 70004B80 3C058003 */  lui   $a1, %hi(aImgviewGrab_D_rgb)
/* 005784 70004B84 8CC632CC */  lw    $a2, %lo(rgb_16bit_grabnum)($a2)
/* 005788 70004B88 24A586F8 */  addiu $a1, %lo(aImgviewGrab_D_rgb) # addiu $a1, $a1, -0x7908
/* 00578C 70004B8C 0C002B25 */  jal   sprintf
/* 005790 70004B90 02002025 */   move  $a0, $s0
/* 005794 70004B94 0FC34038 */  jal   send_command_string
/* 005798 70004B98 02002025 */   move  $a0, $s0
/* 00579C 70004B9C 8FBF0024 */  lw    $ra, 0x24($sp)
/* 0057A0 70004BA0 8FB00018 */  lw    $s0, 0x18($sp)
/* 0057A4 70004BA4 8FB1001C */  lw    $s1, 0x1c($sp)
/* 0057A8 70004BA8 8FB20020 */  lw    $s2, 0x20($sp)
/* 0057AC 70004BAC 03E00008 */  jr    $ra
/* 0057B0 70004BB0 27BD0130 */   addiu $sp, $sp, 0x130
)
#endif

/**
 * 57B4	70004BB4
 *     image capture routine, rgb 32bit colour
 */
#ifdef NONMATCHING
void indy_grab_rgb_32bit(void)
{
    ? sp30;
    ? sp2C;

loop_1:
    sprintf(&sp30, "grab.%d.rgb", rgb_32bit_grabnum);
    if (check_file_found_on_indy(&sp30, &sp2C) != 0)
    {
        rgb_32bit_grabnum = (s32) (rgb_32bit_grabnum + 1);
        goto loop_1;
    }
    sprintf(&sp30, "grab.%d.temp.Uix", rgb_32bit_grabnum);
    indy_send_capture_data(&sp30, &cfb_16, (viGetY() * ((s32) (viGetX() << 0x10) >> 0x10)) * 4);
    sprintf(&sp30, "Uix2pix -xs%d grab.%d.temp.Uix", viGetX(), rgb_32bit_grabnum);
    send_command_string(&sp30);
    sprintf(&sp30, "fromalias grab.%d.temp.pix grab.%d.rgb", rgb_32bit_grabnum, rgb_32bit_grabnum);
    send_command_string(&sp30);
    sprintf(&sp30, "rm grab.%d.temp.Uix grab.%d.temp.pix", rgb_32bit_grabnum, rgb_32bit_grabnum);
    send_command_string(&sp30);
    sprintf(&sp30, "imgview grab.%d.rgb", rgb_32bit_grabnum);
    send_command_string(&sp30);
}
#else
const char aGrab_D_rgb_0[] = "grab.%d.rgb";
const char aGrab_D_temp_uix_2[] = "grab.%d.temp.Uix";
const char aUix2pixXsDGrab_D_temp_uix_0[] = "Uix2pix -xs%d grab.%d.temp.Uix";
const char aFromaliasGrab_D_temp_pixGrab_D_r_0[] = "fromalias grab.%d.temp.pix grab.%d.rgb";
const char aRmGrab_D_temp_uixGrab_D_temp_pix_1[] = "rm grab.%d.temp.Uix grab.%d.temp.pix";
const char aImgviewGrab_D_rgb_0[] = "imgview grab.%d.rgb";
GLOBAL_ASM(
.text
glabel indy_grab_rgb_32bit
/* 0057B4 70004BB4 27BDFED0 */  addiu $sp, $sp, -0x130
/* 0057B8 70004BB8 AFB10018 */  sw    $s1, 0x18($sp)
/* 0057BC 70004BBC AFB2001C */  sw    $s2, 0x1c($sp)
/* 0057C0 70004BC0 AFB00014 */  sw    $s0, 0x14($sp)
/* 0057C4 70004BC4 3C118003 */  lui   $s1, %hi(aGrab_D_rgb_0)
/* 0057C8 70004BC8 AFBF0024 */  sw    $ra, 0x24($sp)
/* 0057CC 70004BCC AFB30020 */  sw    $s3, 0x20($sp)
/* 0057D0 70004BD0 2631870C */  addiu $s1, %lo(aGrab_D_rgb_0) # addiu $s1, $s1, -0x78f4
/* 0057D4 70004BD4 27B00030 */  addiu $s0, $sp, 0x30
/* 0057D8 70004BD8 27B2002C */  addiu $s2, $sp, 0x2c
.L70004BDC:
/* 0057DC 70004BDC 3C138002 */  lui   $s3, %hi(rgb_32bit_grabnum)
/* 0057E0 70004BE0 8E6632D0 */  lw    $a2, %lo(rgb_32bit_grabnum)($s3)
/* 0057E4 70004BE4 02002025 */  move  $a0, $s0
/* 0057E8 70004BE8 0C002B25 */  jal   sprintf
/* 0057EC 70004BEC 02202825 */   move  $a1, $s1
/* 0057F0 70004BF0 02002025 */  move  $a0, $s0
/* 0057F4 70004BF4 0FC34026 */  jal   check_file_found_on_indy
/* 0057F8 70004BF8 02402825 */   move  $a1, $s2
/* 0057FC 70004BFC 10400006 */  beqz  $v0, .L70004C18
/* 005800 70004C00 3C138002 */   lui   $s3, %hi(rgb_32bit_grabnum)
/* 005804 70004C04 8E7332D0 */  lw    $s3, %lo(rgb_32bit_grabnum)($s3)
/* 005808 70004C08 3C018002 */  lui   $at, %hi(rgb_32bit_grabnum)
/* 00580C 70004C0C 26730001 */  addiu $s3, $s3, 1
/* 005810 70004C10 1000FFF2 */  b     .L70004BDC
/* 005814 70004C14 AC3332D0 */   sw    $s3, %lo(rgb_32bit_grabnum)($at)
.L70004C18:
/* 005818 70004C18 3C138002 */  lui   $s3, %hi(rgb_32bit_grabnum)
/* 00581C 70004C1C 3C058003 */  lui   $a1, %hi(aGrab_D_temp_uix_2)
/* 005820 70004C20 8E6632D0 */  lw    $a2, %lo(rgb_32bit_grabnum)($s3)
/* 005824 70004C24 24A58718 */  addiu $a1, %lo(aGrab_D_temp_uix_2) # addiu $a1, $a1, -0x78e8
/* 005828 70004C28 0C002B25 */  jal   sprintf
/* 00582C 70004C2C 02002025 */   move  $a0, $s0
/* 005830 70004C30 0C001107 */  jal   viGetX
/* 005834 70004C34 00000000 */   nop   
/* 005838 70004C38 00028C00 */  sll   $s1, $v0, 0x10
/* 00583C 70004C3C 00117403 */  sra   $t6, $s1, 0x10
/* 005840 70004C40 0C00110B */  jal   viGetY
/* 005844 70004C44 01C08825 */   move  $s1, $t6
/* 005848 70004C48 00510019 */  multu $v0, $s1
/* 00584C 70004C4C 3C05803B */  lui   $a1, %hi(cfb_16) # $a1, 0x803b
/* 005850 70004C50 24A55000 */  addiu $a1, %lo(cfb_16) # addiu $a1, $a1, 0x5000
/* 005854 70004C54 02002025 */  move  $a0, $s0
/* 005858 70004C58 00003012 */  mflo  $a2
/* 00585C 70004C5C 00067880 */  sll   $t7, $a2, 2
/* 005860 70004C60 0FC33FF8 */  jal   indy_send_capture_data
/* 005864 70004C64 01E03025 */   move  $a2, $t7
/* 005868 70004C68 0C001107 */  jal   viGetX
/* 00586C 70004C6C 00000000 */   nop   
/* 005870 70004C70 3C138002 */  lui   $s3, %hi(rgb_32bit_grabnum)
/* 005874 70004C74 3C058003 */  lui   $a1, %hi(aUix2pixXsDGrab_D_temp_uix_0)
/* 005878 70004C78 24A5872C */  addiu $a1, %lo(aUix2pixXsDGrab_D_temp_uix_0) # addiu $a1, $a1, -0x78d4
/* 00587C 70004C7C 8E6732D0 */  lw    $a3, %lo(rgb_32bit_grabnum)($s3)
/* 005880 70004C80 02002025 */  move  $a0, $s0
/* 005884 70004C84 0C002B25 */  jal   sprintf
/* 005888 70004C88 00403025 */   move  $a2, $v0
/* 00588C 70004C8C 0FC34038 */  jal   send_command_string
/* 005890 70004C90 02002025 */   move  $a0, $s0
/* 005894 70004C94 3C138002 */  lui   $s3, %hi(rgb_32bit_grabnum)
/* 005898 70004C98 8E6732D0 */  lw    $a3, %lo(rgb_32bit_grabnum)($s3)
/* 00589C 70004C9C 3C058003 */  lui   $a1, %hi(aFromaliasGrab_D_temp_pixGrab_D_r_0)
/* 0058A0 70004CA0 24A5874C */  addiu $a1, %lo(aFromaliasGrab_D_temp_pixGrab_D_r_0) # addiu $a1, $a1, -0x78b4
/* 0058A4 70004CA4 02002025 */  move  $a0, $s0
/* 0058A8 70004CA8 0C002B25 */  jal   sprintf
/* 0058AC 70004CAC 00E03025 */   move  $a2, $a3
/* 0058B0 70004CB0 0FC34038 */  jal   send_command_string
/* 0058B4 70004CB4 02002025 */   move  $a0, $s0
/* 0058B8 70004CB8 3C138002 */  lui   $s3, %hi(rgb_32bit_grabnum)
/* 0058BC 70004CBC 8E6732D0 */  lw    $a3, %lo(rgb_32bit_grabnum)($s3)
/* 0058C0 70004CC0 3C058003 */  lui   $a1, %hi(aRmGrab_D_temp_uixGrab_D_temp_pix_1)
/* 0058C4 70004CC4 24A58774 */  addiu $a1, %lo(aRmGrab_D_temp_uixGrab_D_temp_pix_1) # addiu $a1, $a1, -0x788c
/* 0058C8 70004CC8 02002025 */  move  $a0, $s0
/* 0058CC 70004CCC 0C002B25 */  jal   sprintf
/* 0058D0 70004CD0 00E03025 */   move  $a2, $a3
/* 0058D4 70004CD4 0FC34038 */  jal   send_command_string
/* 0058D8 70004CD8 02002025 */   move  $a0, $s0
/* 0058DC 70004CDC 3C138002 */  lui   $s3, %hi(rgb_32bit_grabnum)
/* 0058E0 70004CE0 3C058003 */  lui   $a1, %hi(aImgviewGrab_D_rgb_0)
/* 0058E4 70004CE4 8E6632D0 */  lw    $a2, %lo(rgb_32bit_grabnum)($s3)
/* 0058E8 70004CE8 24A5879C */  addiu $a1, %lo(aImgviewGrab_D_rgb_0) # addiu $a1, $a1, -0x7864
/* 0058EC 70004CEC 0C002B25 */  jal   sprintf
/* 0058F0 70004CF0 02002025 */   move  $a0, $s0
/* 0058F4 70004CF4 0FC34038 */  jal   send_command_string
/* 0058F8 70004CF8 02002025 */   move  $a0, $s0
/* 0058FC 70004CFC 8FBF0024 */  lw    $ra, 0x24($sp)
/* 005900 70004D00 8FB00014 */  lw    $s0, 0x14($sp)
/* 005904 70004D04 8FB10018 */  lw    $s1, 0x18($sp)
/* 005908 70004D08 8FB2001C */  lw    $s2, 0x1c($sp)
/* 00590C 70004D0C 8FB30020 */  lw    $s3, 0x20($sp)
/* 005910 70004D10 03E00008 */  jr    $ra
/* 005914 70004D14 27BD0130 */   addiu $sp, $sp, 0x130
)
#endif
