#include <ultra64.h>
#include <ramrom.h>
#include <memp.h>
#include "image_bank.h"

// bss
//8008D0A0
u8* img_curpos;
//8008D0A4
u32 img_curdatatable;
//8008D0A8
s32 img_bitcount;
//8008D0AC
s32 dword_CODE_bss_8008D0AC;
//8008D0B0;
s32 globalbank_rdram_offset;
//8008D0B4;
s32 *pGlobalimagetable;
//8008D0B8;
struct sImageTableEntry *genericimage;
//8008D0BC
struct sImageTableEntry *impactimages;
//8008D0C0
struct sImageTableEntry *explosion_smokeimages;
//8008D0C4
struct sImageTableEntry *scattered_explosions;
//8008D0C8
struct sImageTableEntry *flareimage1;
//8008D0CC
struct sImageTableEntry *flareimage2;
//8008D0D0
struct sImageTableEntry *flareimage3;
//8008D0D4
struct sImageTableEntry *flareimage4;
//8008D0D8
struct sImageTableEntry *flareimage5;
//8008D0DC
struct sImageTableEntry *ammo9mmimage;
//8008D0E0
struct sImageTableEntry *rifleammoimage;
//8008D0E4
struct sImageTableEntry *shotgunammoimage;
//8008D0E8
struct sImageTableEntry *knifeammoimage;
//8008D0EC
struct sImageTableEntry *glaunchammoimage;
//8008D0F0
struct sImageTableEntry *rocketammoimage;
//8008D0F4
struct sImageTableEntry *genericmineammoimage;
//8008D0F8
struct sImageTableEntry *grenadeammoimage;
//8008D0FC
struct sImageTableEntry *magnumammoimage;
//8008D100
struct sImageTableEntry *goldengunammoimage;
//8008D104
struct sImageTableEntry *remotemineammoimage;
//8008D108
struct sImageTableEntry *timedmineammoimage;
//8008D10C
struct sImageTableEntry *proxmineammoimage;
//8008D110
struct sImageTableEntry *tankammoimage;
//8008D114;
struct sImageTableEntry *crosshairimage;
//8008D118
struct sImageTableEntry *betacrosshairimage;
//8008D11C
struct sImageTableEntry *glassoverlayimage;
//8008D120
struct sImageTableEntry *monitorimages;
//8008D124
struct sImageTableEntry *skywaterimages;
//8008D128
struct sImageTableEntry *mainfolderimages;
//8008D12C
struct sImageTableEntry *mpradarimages;
//8008D130
struct sImageTableEntry *mpcharselimages;
//8008D134
struct sImageTableEntry *mpstageselimages;


extern u8* _GlobalimagetableSegmentRomStart;


void makeemptyimageatpos(s32 pos) {
    img_curpos = pos;
    img_curdatatable = 0;
    img_bitcount = 0;
}



u32 extractImageBitCount(s32 bitCount)
{
    if (img_bitcount < bitCount)
    {
        do
        {
            img_curdatatable = (*img_curpos | (img_curdatatable << 8));
            img_curpos++;
            img_bitcount = img_bitcount + 8;
        } while (img_bitcount < bitCount);
    }
    
    img_bitcount -= bitCount;
    return (img_curdatatable >> img_bitcount) & ((1 << bitCount) - 1);
}



extern u32* _GlobalimagetableSegmentStart;
extern u32* _GlobalimagetableSegmentEnd;
extern void* s_genericimage;
extern void* s_impactimages;
extern void* s_explosion_smokeimages;
extern void* s_scattered_explosions;
extern void* s_flareimage1;
extern void* s_flareimage2;
extern void* s_flareimage3;
extern void* s_flareimage4;
extern void* s_flareimage5;
extern void* s_ammo9mmimage;
extern void* s_rifleammoimage;
extern void* s_shotgunammoimage;
extern void* s_knifeammoimage;
extern void* s_glammoimage;
extern void* s_rocketammoimage;
extern void* s_genericmineammoimage;
extern void* s_grenadeammoimage;
extern void* s_magnumammoimage;
extern void* s_goldengunammoimage;
extern void* s_remotemineammoimage;
extern void* s_timedmineammoimage;
extern void* s_proxmineammoimage;
extern void* s_tankammoimage;
extern void* s_crosshairimage;
extern void* s_betacrosshairimage;
extern void* s_glassoverlayimage;
extern void* s_monitorimages;
extern void* s_skywaterimages;
extern void* s_mainfolderimages;
extern void* s_mpradarimages;
extern void* s_mpcharselimages;
extern void* s_mpstageselimages;

extern Gfx* globalDL_0x000;
extern Gfx* globalDL_0x078;
extern Gfx* globalDL_0x120;
extern Gfx* globalDL_0x1c8;
extern Gfx* globalDL_0x270;
extern Gfx* globalDL_0x318;
extern Gfx* globalDL_0x3c0;
extern Gfx* globalDL_0x468;
extern Gfx* globalDL_0x510;
extern Gfx* globalDL_0x5b8;
extern Gfx* globalDL_0x660;
extern Gfx* globalDL_0x708;
extern Gfx* globalDL_0x7b0;
extern Gfx* globalDL_0x858;
extern Gfx* globalDL_0x900;
extern Gfx* globalDL_0x9a8;
extern Gfx* globalDL_0xa50;

#ifdef NONMATCHING
void load_prepare_global_image_bank(void)
{

    s32 size;
    s32 i;

    size = &_GlobalimagetableSegmentEnd - &_GlobalimagetableSegmentStart;
    pGlobalimagetable = ((mempAllocBytesInBank((size + 0x1000), 4) + 0xfff) & -0x1000);
    romCopy(pGlobalimagetable, &_GlobalimagetableSegmentRomStart, size);
    globalbank_rdram_offset = pGlobalimagetable + 0xFE000000;;
    genericimage = (void *) (globalbank_rdram_offset + &s_genericimage);
    impactimages = (void *) (globalbank_rdram_offset + &s_impactimages);
    explosion_smokeimages = (void *) (globalbank_rdram_offset + &s_explosion_smokeimages);
    scattered_explosions = (void *) (globalbank_rdram_offset + &s_scattered_explosions);
    flareimage1 = (void *) (globalbank_rdram_offset + &s_flareimage1);
    flareimage2 = (void *) (globalbank_rdram_offset + &s_flareimage2);
    flareimage3 = (void *) (globalbank_rdram_offset + &s_flareimage3);
    flareimage4 = (void *) (globalbank_rdram_offset + &s_flareimage4);
    flareimage5 = (void *) (globalbank_rdram_offset + &s_flareimage5);
    ammo9mmimage = (void *) (globalbank_rdram_offset + &s_ammo9mmimage);
    rifleammoimage = (void *) (globalbank_rdram_offset + &s_rifleammoimage);
    shotgunammoimage = (void *) (globalbank_rdram_offset + &s_shotgunammoimage);
    knifeammoimage = (void *) (globalbank_rdram_offset + &s_knifeammoimage);
    glaunchammoimage = (void *) (globalbank_rdram_offset + &s_glammoimage);
    rocketammoimage = (void *) (globalbank_rdram_offset + &s_rocketammoimage);
    genericmineammoimage = (void *) (globalbank_rdram_offset + &s_genericmineammoimage);
    grenadeammoimage = (void *) (globalbank_rdram_offset + &s_grenadeammoimage);
    magnumammoimage = (void *) (globalbank_rdram_offset + &s_magnumammoimage);
    goldengunammoimage = (void *) (globalbank_rdram_offset + &s_goldengunammoimage);
    remotemineammoimage = (void *) (globalbank_rdram_offset + &s_remotemineammoimage);
    timedmineammoimage = (void *) (globalbank_rdram_offset + &s_timedmineammoimage);
    proxmineammoimage = (void *) (globalbank_rdram_offset + &s_proxmineammoimage);
    tankammoimage = (void *) (globalbank_rdram_offset + &s_tankammoimage);
    crosshairimage = (void *) (globalbank_rdram_offset + &s_crosshairimage);
    betacrosshairimage = (void *) (globalbank_rdram_offset + &s_betacrosshairimage);
    glassoverlayimage = (void *) (globalbank_rdram_offset + &s_glassoverlayimage);
    monitorimages = (void *) (globalbank_rdram_offset + &s_monitorimages);
    skywaterimages = (void *) (globalbank_rdram_offset + &s_skywaterimages);
    mainfolderimages = (void *) (globalbank_rdram_offset + &s_mainfolderimages);
    mpradarimages = (void *) (globalbank_rdram_offset + &s_mpradarimages);
    mpcharselimages = (void *) (globalbank_rdram_offset + &s_mpcharselimages);
    mpstageselimages = (void *) (globalbank_rdram_offset + &s_mpstageselimages);
    check_load_image_to_buffer(globalbank_rdram_offset + &globalDL_0x000, 0);
    check_load_image_to_buffer(globalbank_rdram_offset + &globalDL_0x078, 0);
    check_load_image_to_buffer(globalbank_rdram_offset + &globalDL_0x120, 0);
    check_load_image_to_buffer(globalbank_rdram_offset + &globalDL_0x1c8, 0);
    check_load_image_to_buffer(globalbank_rdram_offset + &globalDL_0x270, 0);
    check_load_image_to_buffer(globalbank_rdram_offset + &globalDL_0x318, 0);
    check_load_image_to_buffer(globalbank_rdram_offset + &globalDL_0x3c0, 0);
    check_load_image_to_buffer(globalbank_rdram_offset + &globalDL_0x468, 0);
    check_load_image_to_buffer(globalbank_rdram_offset + &globalDL_0x510, 0);
    check_load_image_to_buffer(globalbank_rdram_offset + &globalDL_0x5b8, 0);
    check_load_image_to_buffer(globalbank_rdram_offset + &globalDL_0x660, 0);
    check_load_image_to_buffer(globalbank_rdram_offset + &globalDL_0x708, 0);
    check_load_image_to_buffer(globalbank_rdram_offset + &globalDL_0x7b0, 0);
    check_load_image_to_buffer(globalbank_rdram_offset + &globalDL_0x858, 0);
    check_load_image_to_buffer(globalbank_rdram_offset + &globalDL_0x900, 0);
    check_load_image_to_buffer(globalbank_rdram_offset + &globalDL_0x9a8, 0);
    check_load_image_to_buffer(globalbank_rdram_offset + &globalDL_0xa50, 0);
    load_image_to_buffer(genericimage, 0);

    for (i=0; i<0x48; i+=0xC)
    {
        load_image_to_buffer(&explosion_smokeimages+i, 0);
    }
    for (i=0; i<0x48; i+=0xC)
    {
        load_image_to_buffer(&scattered_explosions+i, 0);
    }
}
#else
GLOBAL_ASM(
.text
glabel load_prepare_global_image_bank
/* 100AE0 7F0CBFB0 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 100AE4 7F0CBFB4 3C0E0200 */  lui   $t6, %hi(_GlobalimagetableSegmentEnd) # $t6, 0x200
/* 100AE8 7F0CBFB8 3C0F0200 */  lui   $t7, %hi(_GlobalimagetableSegmentStart) # $t7, 0x200
/* 100AEC 7F0CBFBC AFB00014 */  sw    $s0, 0x14($sp)
/* 100AF0 7F0CBFC0 25EF0000 */  addiu $t7, %lo(_GlobalimagetableSegmentStart) # addiu $t7, $t7, 0
/* 100AF4 7F0CBFC4 25CE1400 */  addiu $t6, %lo(_GlobalimagetableSegmentEnd) # addiu $t6, $t6, 0x1400
/* 100AF8 7F0CBFC8 AFBF0024 */  sw    $ra, 0x24($sp)
/* 100AFC 7F0CBFCC 01CF8023 */  subu  $s0, $t6, $t7
/* 100B00 7F0CBFD0 AFB30020 */  sw    $s3, 0x20($sp)
/* 100B04 7F0CBFD4 AFB2001C */  sw    $s2, 0x1c($sp)
/* 100B08 7F0CBFD8 AFB10018 */  sw    $s1, 0x18($sp)
/* 100B0C 7F0CBFDC 26041000 */  addiu $a0, $s0, 0x1000
/* 100B10 7F0CBFE0 0C0025C8 */  jal   mempAllocBytesInBank
/* 100B14 7F0CBFE4 24050004 */   li    $a1, 4
/* 100B18 7F0CBFE8 3C118009 */  lui   $s1, %hi(pGlobalimagetable)
/* 100B1C 7F0CBFEC 2631D0B4 */  addiu $s1, %lo(pGlobalimagetable) # addiu $s1, $s1, -0x2f4c
/* 100B20 7F0CBFF0 24590FFF */  addiu $t9, $v0, 0xfff
/* 100B24 7F0CBFF4 2401F000 */  li    $at, -4096
/* 100B28 7F0CBFF8 AE220000 */  sw    $v0, ($s1)
/* 100B2C 7F0CBFFC 03212024 */  and   $a0, $t9, $at
/* 100B30 7F0CC000 3C05002A */  lui   $a1, %hi(_GlobalimagetableSegmentRomStart) # $a1, 0x2a
/* 100B34 7F0CC004 AE240000 */  sw    $a0, ($s1)
/* 100B38 7F0CC008 24A5D160 */  addiu $a1, %lo(_GlobalimagetableSegmentRomStart) # addiu $a1, $a1, -0x2ea0
/* 100B3C 7F0CC00C 0C001707 */  jal   romCopy
/* 100B40 7F0CC010 02003025 */   move  $a2, $s0
/* 100B44 7F0CC014 8E290000 */  lw    $t1, ($s1)
/* 100B48 7F0CC018 3C01FE00 */  lui   $at, 0xfe00
/* 100B4C 7F0CC01C 3C108009 */  lui   $s0, %hi(globalbank_rdram_offset)
/* 100B50 7F0CC020 01211021 */  addu  $v0, $t1, $at
/* 100B54 7F0CC024 3C0B0200 */  lui   $t3, %hi(s_genericimage) # $t3, 0x200
/* 100B58 7F0CC028 2610D0B0 */  addiu $s0, %lo(globalbank_rdram_offset) # addiu $s0, $s0, -0x2f50
/* 100B5C 7F0CC02C 256B0AC8 */  addiu $t3, %lo(s_genericimage) # addiu $t3, $t3, 0xac8
/* 100B60 7F0CC030 AE020000 */  sw    $v0, ($s0)
/* 100B64 7F0CC034 004B6021 */  addu  $t4, $v0, $t3
/* 100B68 7F0CC038 3C018009 */  lui   $at, %hi(genericimage)
/* 100B6C 7F0CC03C 3C0D0200 */  lui   $t5, %hi(s_impactimages) # $t5, 0x200
/* 100B70 7F0CC040 AC2CD0B8 */  sw    $t4, %lo(genericimage)($at)
/* 100B74 7F0CC044 25AD0AD4 */  addiu $t5, %lo(s_impactimages) # addiu $t5, $t5, 0xad4
/* 100B78 7F0CC048 004D7021 */  addu  $t6, $v0, $t5
/* 100B7C 7F0CC04C 3C018009 */  lui   $at, %hi(impactimages)
/* 100B80 7F0CC050 AC2ED0BC */  sw    $t6, %lo(impactimages)($at)
/* 100B84 7F0CC054 3C0F0200 */  lui   $t7, %hi(s_explosion_smokeimages) # $t7, 0x200
/* 100B88 7F0CC058 3C190200 */  lui   $t9, %hi(s_scattered_explosions) # $t9, 0x200
/* 100B8C 7F0CC05C 3C128009 */  lui   $s2, %hi(explosion_smokeimages)
/* 100B90 7F0CC060 3C138009 */  lui   $s3, %hi(scattered_explosions)
/* 100B94 7F0CC064 25EF0BC4 */  addiu $t7, %lo(s_explosion_smokeimages) # addiu $t7, $t7, 0xbc4
/* 100B98 7F0CC068 27390C0C */  addiu $t9, %lo(s_scattered_explosions) # addiu $t9, $t9, 0xc0c
/* 100B9C 7F0CC06C 3C090200 */  lui   $t1, %hi(s_flareimage1) # $t1, 0x200
/* 100BA0 7F0CC070 2673D0C4 */  addiu $s3, %lo(scattered_explosions) # addiu $s3, $s3, -0x2f3c
/* 100BA4 7F0CC074 2652D0C0 */  addiu $s2, %lo(explosion_smokeimages) # addiu $s2, $s2, -0x2f40
/* 100BA8 7F0CC078 004FC021 */  addu  $t8, $v0, $t7
/* 100BAC 7F0CC07C 00594021 */  addu  $t0, $v0, $t9
/* 100BB0 7F0CC080 25290C48 */  addiu $t1, %lo(s_flareimage1) # addiu $t1, $t1, 0xc48
/* 100BB4 7F0CC084 AE580000 */  sw    $t8, ($s2)
/* 100BB8 7F0CC088 AE680000 */  sw    $t0, ($s3)
/* 100BBC 7F0CC08C 00495021 */  addu  $t2, $v0, $t1
/* 100BC0 7F0CC090 3C018009 */  lui   $at, %hi(flareimage1)
/* 100BC4 7F0CC094 3C0B0200 */  lui   $t3, %hi(s_flareimage2) # $t3, 0x200
/* 100BC8 7F0CC098 AC2AD0C8 */  sw    $t2, %lo(flareimage1)($at)
/* 100BCC 7F0CC09C 256B0C54 */  addiu $t3, %lo(s_flareimage2) # addiu $t3, $t3, 0xc54
/* 100BD0 7F0CC0A0 004B6021 */  addu  $t4, $v0, $t3
/* 100BD4 7F0CC0A4 3C018009 */  lui   $at, %hi(flareimage2)
/* 100BD8 7F0CC0A8 3C0D0200 */  lui   $t5, %hi(s_flareimage3) # $t5, 0x200
/* 100BDC 7F0CC0AC AC2CD0CC */  sw    $t4, %lo(flareimage2)($at)
/* 100BE0 7F0CC0B0 25AD0C60 */  addiu $t5, %lo(s_flareimage3) # addiu $t5, $t5, 0xc60
/* 100BE4 7F0CC0B4 004D7021 */  addu  $t6, $v0, $t5
/* 100BE8 7F0CC0B8 3C018009 */  lui   $at, %hi(flareimage3)
/* 100BEC 7F0CC0BC 3C0F0200 */  lui   $t7, %hi(s_flareimage4) # $t7, 0x200
/* 100BF0 7F0CC0C0 AC2ED0D0 */  sw    $t6, %lo(flareimage3)($at)
/* 100BF4 7F0CC0C4 25EF0C6C */  addiu $t7, %lo(s_flareimage4) # addiu $t7, $t7, 0xc6c
/* 100BF8 7F0CC0C8 004FC021 */  addu  $t8, $v0, $t7
/* 100BFC 7F0CC0CC 3C018009 */  lui   $at, %hi(flareimage4)
/* 100C00 7F0CC0D0 3C190200 */  lui   $t9, %hi(s_flareimage5) # $t9, 0x200
/* 100C04 7F0CC0D4 AC38D0D4 */  sw    $t8, %lo(flareimage4)($at)
/* 100C08 7F0CC0D8 27390C78 */  addiu $t9, %lo(s_flareimage5) # addiu $t9, $t9, 0xc78
/* 100C0C 7F0CC0DC 00594021 */  addu  $t0, $v0, $t9
/* 100C10 7F0CC0E0 3C018009 */  lui   $at, %hi(flareimage5)
/* 100C14 7F0CC0E4 3C090200 */  lui   $t1, %hi(s_ammo9mmimage) # $t1, 0x200
/* 100C18 7F0CC0E8 AC28D0D8 */  sw    $t0, %lo(flareimage5)($at)
/* 100C1C 7F0CC0EC 25290C84 */  addiu $t1, %lo(s_ammo9mmimage) # addiu $t1, $t1, 0xc84
/* 100C20 7F0CC0F0 00495021 */  addu  $t2, $v0, $t1
/* 100C24 7F0CC0F4 3C018009 */  lui   $at, %hi(ammo9mmimage)
/* 100C28 7F0CC0F8 3C0B0200 */  lui   $t3, %hi(s_rifleammoimage) # $t3, 0x200
/* 100C2C 7F0CC0FC AC2AD0DC */  sw    $t2, %lo(ammo9mmimage)($at)
/* 100C30 7F0CC100 256B0C90 */  addiu $t3, %lo(s_rifleammoimage) # addiu $t3, $t3, 0xc90
/* 100C34 7F0CC104 004B6021 */  addu  $t4, $v0, $t3
/* 100C38 7F0CC108 3C018009 */  lui   $at, %hi(rifleammoimage)
/* 100C3C 7F0CC10C 3C0D0200 */  lui   $t5, %hi(s_shotgunammoimage) # $t5, 0x200
/* 100C40 7F0CC110 AC2CD0E0 */  sw    $t4, %lo(rifleammoimage)($at)
/* 100C44 7F0CC114 25AD0C9C */  addiu $t5, %lo(s_shotgunammoimage) # addiu $t5, $t5, 0xc9c
/* 100C48 7F0CC118 004D7021 */  addu  $t6, $v0, $t5
/* 100C4C 7F0CC11C 3C018009 */  lui   $at, %hi(shotgunammoimage)
/* 100C50 7F0CC120 3C0F0200 */  lui   $t7, %hi(s_knifeammoimage) # $t7, 0x200
/* 100C54 7F0CC124 AC2ED0E4 */  sw    $t6, %lo(shotgunammoimage)($at)
/* 100C58 7F0CC128 25EF0CA8 */  addiu $t7, %lo(s_knifeammoimage) # addiu $t7, $t7, 0xca8
/* 100C5C 7F0CC12C 004FC021 */  addu  $t8, $v0, $t7
/* 100C60 7F0CC130 3C018009 */  lui   $at, %hi(knifeammoimage)
/* 100C64 7F0CC134 3C190200 */  lui   $t9, %hi(s_glammoimage) # $t9, 0x200
/* 100C68 7F0CC138 AC38D0E8 */  sw    $t8, %lo(knifeammoimage)($at)
/* 100C6C 7F0CC13C 27390CB4 */  addiu $t9, %lo(s_glammoimage) # addiu $t9, $t9, 0xcb4
/* 100C70 7F0CC140 00594021 */  addu  $t0, $v0, $t9
/* 100C74 7F0CC144 3C018009 */  lui   $at, %hi(glaunchammoimage)
/* 100C78 7F0CC148 3C090200 */  lui   $t1, %hi(s_rocketammoimage) # $t1, 0x200
/* 100C7C 7F0CC14C AC28D0EC */  sw    $t0, %lo(glaunchammoimage)($at)
/* 100C80 7F0CC150 25290CC0 */  addiu $t1, %lo(s_rocketammoimage) # addiu $t1, $t1, 0xcc0
/* 100C84 7F0CC154 00495021 */  addu  $t2, $v0, $t1
/* 100C88 7F0CC158 3C018009 */  lui   $at, %hi(rocketammoimage)
/* 100C8C 7F0CC15C 3C0B0200 */  lui   $t3, %hi(s_genericmineammoimage) # $t3, 0x200
/* 100C90 7F0CC160 AC2AD0F0 */  sw    $t2, %lo(rocketammoimage)($at)
/* 100C94 7F0CC164 256B0CCC */  addiu $t3, %lo(s_genericmineammoimage) # addiu $t3, $t3, 0xccc
/* 100C98 7F0CC168 004B6021 */  addu  $t4, $v0, $t3
/* 100C9C 7F0CC16C 3C018009 */  lui   $at, %hi(genericmineammoimage)
/* 100CA0 7F0CC170 3C0D0200 */  lui   $t5, %hi(s_grenadeammoimage) # $t5, 0x200
/* 100CA4 7F0CC174 AC2CD0F4 */  sw    $t4, %lo(genericmineammoimage)($at)
/* 100CA8 7F0CC178 25AD0CD8 */  addiu $t5, %lo(s_grenadeammoimage) # addiu $t5, $t5, 0xcd8
/* 100CAC 7F0CC17C 004D7021 */  addu  $t6, $v0, $t5
/* 100CB0 7F0CC180 3C018009 */  lui   $at, %hi(grenadeammoimage)
/* 100CB4 7F0CC184 3C0F0200 */  lui   $t7, %hi(s_magnumammoimage) # $t7, 0x200
/* 100CB8 7F0CC188 AC2ED0F8 */  sw    $t6, %lo(grenadeammoimage)($at)
/* 100CBC 7F0CC18C 25EF0CE4 */  addiu $t7, %lo(s_magnumammoimage) # addiu $t7, $t7, 0xce4
/* 100CC0 7F0CC190 004FC021 */  addu  $t8, $v0, $t7
/* 100CC4 7F0CC194 3C018009 */  lui   $at, %hi(magnumammoimage)
/* 100CC8 7F0CC198 3C190200 */  lui   $t9, %hi(s_goldengunammoimage) # $t9, 0x200
/* 100CCC 7F0CC19C AC38D0FC */  sw    $t8, %lo(magnumammoimage)($at)
/* 100CD0 7F0CC1A0 27390CF0 */  addiu $t9, %lo(s_goldengunammoimage) # addiu $t9, $t9, 0xcf0
/* 100CD4 7F0CC1A4 00594021 */  addu  $t0, $v0, $t9
/* 100CD8 7F0CC1A8 3C018009 */  lui   $at, %hi(goldengunammoimage)
/* 100CDC 7F0CC1AC 3C090200 */  lui   $t1, %hi(s_remotemineammoimage) # $t1, 0x200
/* 100CE0 7F0CC1B0 AC28D100 */  sw    $t0, %lo(goldengunammoimage)($at)
/* 100CE4 7F0CC1B4 25290CFC */  addiu $t1, %lo(s_remotemineammoimage) # addiu $t1, $t1, 0xcfc
/* 100CE8 7F0CC1B8 00495021 */  addu  $t2, $v0, $t1
/* 100CEC 7F0CC1BC 3C018009 */  lui   $at, %hi(remotemineammoimage)
/* 100CF0 7F0CC1C0 3C0B0200 */  lui   $t3, %hi(s_timedmineammoimage) # $t3, 0x200
/* 100CF4 7F0CC1C4 AC2AD104 */  sw    $t2, %lo(remotemineammoimage)($at)
/* 100CF8 7F0CC1C8 256B0D08 */  addiu $t3, %lo(s_timedmineammoimage) # addiu $t3, $t3, 0xd08
/* 100CFC 7F0CC1CC 004B6021 */  addu  $t4, $v0, $t3
/* 100D00 7F0CC1D0 3C018009 */  lui   $at, %hi(timedmineammoimage)
/* 100D04 7F0CC1D4 3C0D0200 */  lui   $t5, %hi(s_proxmineammoimage) # $t5, 0x200
/* 100D08 7F0CC1D8 AC2CD108 */  sw    $t4, %lo(timedmineammoimage)($at)
/* 100D0C 7F0CC1DC 25AD0D14 */  addiu $t5, %lo(s_proxmineammoimage) # addiu $t5, $t5, 0xd14
/* 100D10 7F0CC1E0 004D7021 */  addu  $t6, $v0, $t5
/* 100D14 7F0CC1E4 3C018009 */  lui   $at, %hi(proxmineammoimage)
/* 100D18 7F0CC1E8 3C0F0200 */  lui   $t7, %hi(s_tankammoimage) # $t7, 0x200
/* 100D1C 7F0CC1EC AC2ED10C */  sw    $t6, %lo(proxmineammoimage)($at)
/* 100D20 7F0CC1F0 25EF0D20 */  addiu $t7, %lo(s_tankammoimage) # addiu $t7, $t7, 0xd20
/* 100D24 7F0CC1F4 004FC021 */  addu  $t8, $v0, $t7
/* 100D28 7F0CC1F8 3C018009 */  lui   $at, %hi(tankammoimage)
/* 100D2C 7F0CC1FC 3C190200 */  lui   $t9, %hi(s_crosshairimage) # $t9, 0x200
/* 100D30 7F0CC200 AC38D110 */  sw    $t8, %lo(tankammoimage)($at)
/* 100D34 7F0CC204 27390D2C */  addiu $t9, %lo(s_crosshairimage) # addiu $t9, $t9, 0xd2c
/* 100D38 7F0CC208 00594021 */  addu  $t0, $v0, $t9
/* 100D3C 7F0CC20C 3C018009 */  lui   $at, %hi(crosshairimage)
/* 100D40 7F0CC210 3C090200 */  lui   $t1, %hi(s_betacrosshairimage) # $t1, 0x200
/* 100D44 7F0CC214 AC28D114 */  sw    $t0, %lo(crosshairimage)($at)
/* 100D48 7F0CC218 25290D38 */  addiu $t1, %lo(s_betacrosshairimage) # addiu $t1, $t1, 0xd38
/* 100D4C 7F0CC21C 00495021 */  addu  $t2, $v0, $t1
/* 100D50 7F0CC220 3C018009 */  lui   $at, %hi(betacrosshairimage)
/* 100D54 7F0CC224 3C0B0200 */  lui   $t3, %hi(s_glassoverlayimage) # $t3, 0x200
/* 100D58 7F0CC228 AC2AD118 */  sw    $t2, %lo(betacrosshairimage)($at)
/* 100D5C 7F0CC22C 256B0D44 */  addiu $t3, %lo(s_glassoverlayimage) # addiu $t3, $t3, 0xd44
/* 100D60 7F0CC230 004B6021 */  addu  $t4, $v0, $t3
/* 100D64 7F0CC234 3C018009 */  lui   $at, %hi(glassoverlayimage)
/* 100D68 7F0CC238 3C0D0200 */  lui   $t5, %hi(s_monitorimages) # $t5, 0x200
/* 100D6C 7F0CC23C AC2CD11C */  sw    $t4, %lo(glassoverlayimage)($at)
/* 100D70 7F0CC240 25AD0D5C */  addiu $t5, %lo(s_monitorimages) # addiu $t5, $t5, 0xd5c
/* 100D74 7F0CC244 004D7021 */  addu  $t6, $v0, $t5
/* 100D78 7F0CC248 3C018009 */  lui   $at, %hi(monitorimages)
/* 100D7C 7F0CC24C 3C0F0200 */  lui   $t7, %hi(s_skywaterimages) # $t7, 0x200
/* 100D80 7F0CC250 AC2ED120 */  sw    $t6, %lo(monitorimages)($at)
/* 100D84 7F0CC254 25EF0FB4 */  addiu $t7, %lo(s_skywaterimages) # addiu $t7, $t7, 0xfb4
/* 100D88 7F0CC258 004FC021 */  addu  $t8, $v0, $t7
/* 100D8C 7F0CC25C 3C018009 */  lui   $at, %hi(skywaterimages)
/* 100D90 7F0CC260 3C190200 */  lui   $t9, %hi(s_mainfolderimages) # $t9, 0x200
/* 100D94 7F0CC264 AC38D124 */  sw    $t8, %lo(skywaterimages)($at)
/* 100D98 7F0CC268 27390FD8 */  addiu $t9, %lo(s_mainfolderimages) # addiu $t9, $t9, 0xfd8
/* 100D9C 7F0CC26C 00594021 */  addu  $t0, $v0, $t9
/* 100DA0 7F0CC270 3C018009 */  lui   $at, %hi(mainfolderimages)
/* 100DA4 7F0CC274 3C090200 */  lui   $t1, %hi(s_mpradarimages) # $t1, 0x200
/* 100DA8 7F0CC278 AC28D128 */  sw    $t0, %lo(mainfolderimages)($at)
/* 100DAC 7F0CC27C 25291020 */  addiu $t1, %lo(s_mpradarimages) # addiu $t1, $t1, 0x1020
/* 100DB0 7F0CC280 00495021 */  addu  $t2, $v0, $t1
/* 100DB4 7F0CC284 3C018009 */  lui   $at, %hi(mpradarimages)
/* 100DB8 7F0CC288 3C0B0200 */  lui   $t3, %hi(s_mpcharselimages) # $t3, 0x200
/* 100DBC 7F0CC28C AC2AD12C */  sw    $t2, %lo(mpradarimages)($at)
/* 100DC0 7F0CC290 256B102C */  addiu $t3, %lo(s_mpcharselimages) # addiu $t3, $t3, 0x102c
/* 100DC4 7F0CC294 004B6021 */  addu  $t4, $v0, $t3
/* 100DC8 7F0CC298 3C018009 */  lui   $at, %hi(mpcharselimages)
/* 100DCC 7F0CC29C 3C0D0200 */  lui   $t5, %hi(s_mpstageselimages) # $t5, 0x200
/* 100DD0 7F0CC2A0 AC2CD130 */  sw    $t4, %lo(mpcharselimages)($at)
/* 100DD4 7F0CC2A4 25AD132C */  addiu $t5, %lo(s_mpstageselimages) # addiu $t5, $t5, 0x132c
/* 100DD8 7F0CC2A8 3C0F0200 */  lui   $t7, 0x200
/* 100DDC 7F0CC2AC 004D7021 */  addu  $t6, $v0, $t5
/* 100DE0 7F0CC2B0 3C018009 */  lui   $at, %hi(mpstageselimages)
/* 100DE4 7F0CC2B4 25EF0000 */  addiu $t7, $t7, 0
/* 100DE8 7F0CC2B8 AC2ED134 */  sw    $t6, %lo(mpstageselimages)($at)
/* 100DEC 7F0CC2BC 004F2021 */  addu  $a0, $v0, $t7
/* 100DF0 7F0CC2C0 0FC32EDD */  jal   check_load_image_to_buffer
/* 100DF4 7F0CC2C4 00002825 */   move  $a1, $zero
/* 100DF8 7F0CC2C8 8E180000 */  lw    $t8, ($s0)
/* 100DFC 7F0CC2CC 3C190200 */  lui   $t9, %hi(globalDL_0x078) # $t9, 0x200
/* 100E00 7F0CC2D0 27390078 */  addiu $t9, %lo(globalDL_0x078) # addiu $t9, $t9, 0x78
/* 100E04 7F0CC2D4 00002825 */  move  $a1, $zero
/* 100E08 7F0CC2D8 0FC32EDD */  jal   check_load_image_to_buffer
/* 100E0C 7F0CC2DC 03192021 */   addu  $a0, $t8, $t9
/* 100E10 7F0CC2E0 8E080000 */  lw    $t0, ($s0)
/* 100E14 7F0CC2E4 3C090200 */  lui   $t1, %hi(globalDL_0x120) # $t1, 0x200
/* 100E18 7F0CC2E8 25290120 */  addiu $t1, %lo(globalDL_0x120) # addiu $t1, $t1, 0x120
/* 100E1C 7F0CC2EC 00002825 */  move  $a1, $zero
/* 100E20 7F0CC2F0 0FC32EDD */  jal   check_load_image_to_buffer
/* 100E24 7F0CC2F4 01092021 */   addu  $a0, $t0, $t1
/* 100E28 7F0CC2F8 8E0A0000 */  lw    $t2, ($s0)
/* 100E2C 7F0CC2FC 3C0B0200 */  lui   $t3, %hi(globalDL_0x1c8) # $t3, 0x200
/* 100E30 7F0CC300 256B01C8 */  addiu $t3, %lo(globalDL_0x1c8) # addiu $t3, $t3, 0x1c8
/* 100E34 7F0CC304 00002825 */  move  $a1, $zero
/* 100E38 7F0CC308 0FC32EDD */  jal   check_load_image_to_buffer
/* 100E3C 7F0CC30C 014B2021 */   addu  $a0, $t2, $t3
/* 100E40 7F0CC310 8E0C0000 */  lw    $t4, ($s0)
/* 100E44 7F0CC314 3C0D0200 */  lui   $t5, %hi(globalDL_0x270) # $t5, 0x200
/* 100E48 7F0CC318 25AD0270 */  addiu $t5, %lo(globalDL_0x270) # addiu $t5, $t5, 0x270
/* 100E4C 7F0CC31C 00002825 */  move  $a1, $zero
/* 100E50 7F0CC320 0FC32EDD */  jal   check_load_image_to_buffer
/* 100E54 7F0CC324 018D2021 */   addu  $a0, $t4, $t5
/* 100E58 7F0CC328 8E0E0000 */  lw    $t6, ($s0)
/* 100E5C 7F0CC32C 3C0F0200 */  lui   $t7, %hi(globalDL_0x318) # $t7, 0x200
/* 100E60 7F0CC330 25EF0318 */  addiu $t7, %lo(globalDL_0x318) # addiu $t7, $t7, 0x318
/* 100E64 7F0CC334 00002825 */  move  $a1, $zero
/* 100E68 7F0CC338 0FC32EDD */  jal   check_load_image_to_buffer
/* 100E6C 7F0CC33C 01CF2021 */   addu  $a0, $t6, $t7
/* 100E70 7F0CC340 8E180000 */  lw    $t8, ($s0)
/* 100E74 7F0CC344 3C190200 */  lui   $t9, %hi(globalDL_0x3c0) # $t9, 0x200
/* 100E78 7F0CC348 273903C0 */  addiu $t9, %lo(globalDL_0x3c0) # addiu $t9, $t9, 0x3c0
/* 100E7C 7F0CC34C 00002825 */  move  $a1, $zero
/* 100E80 7F0CC350 0FC32EDD */  jal   check_load_image_to_buffer
/* 100E84 7F0CC354 03192021 */   addu  $a0, $t8, $t9
/* 100E88 7F0CC358 8E080000 */  lw    $t0, ($s0)
/* 100E8C 7F0CC35C 3C090200 */  lui   $t1, %hi(globalDL_0x468) # $t1, 0x200
/* 100E90 7F0CC360 25290468 */  addiu $t1, %lo(globalDL_0x468) # addiu $t1, $t1, 0x468
/* 100E94 7F0CC364 00002825 */  move  $a1, $zero
/* 100E98 7F0CC368 0FC32EDD */  jal   check_load_image_to_buffer
/* 100E9C 7F0CC36C 01092021 */   addu  $a0, $t0, $t1
/* 100EA0 7F0CC370 8E0A0000 */  lw    $t2, ($s0)
/* 100EA4 7F0CC374 3C0B0200 */  lui   $t3, %hi(globalDL_0x510) # $t3, 0x200
/* 100EA8 7F0CC378 256B0510 */  addiu $t3, %lo(globalDL_0x510) # addiu $t3, $t3, 0x510
/* 100EAC 7F0CC37C 00002825 */  move  $a1, $zero
/* 100EB0 7F0CC380 0FC32EDD */  jal   check_load_image_to_buffer
/* 100EB4 7F0CC384 014B2021 */   addu  $a0, $t2, $t3
/* 100EB8 7F0CC388 8E0C0000 */  lw    $t4, ($s0)
/* 100EBC 7F0CC38C 3C0D0200 */  lui   $t5, %hi(globalDL_0x5b8) # $t5, 0x200
/* 100EC0 7F0CC390 25AD05B8 */  addiu $t5, %lo(globalDL_0x5b8) # addiu $t5, $t5, 0x5b8
/* 100EC4 7F0CC394 00002825 */  move  $a1, $zero
/* 100EC8 7F0CC398 0FC32EDD */  jal   check_load_image_to_buffer
/* 100ECC 7F0CC39C 018D2021 */   addu  $a0, $t4, $t5
/* 100ED0 7F0CC3A0 8E0E0000 */  lw    $t6, ($s0)
/* 100ED4 7F0CC3A4 3C0F0200 */  lui   $t7, %hi(globalDL_0x660) # $t7, 0x200
/* 100ED8 7F0CC3A8 25EF0660 */  addiu $t7, %lo(globalDL_0x660) # addiu $t7, $t7, 0x660
/* 100EDC 7F0CC3AC 00002825 */  move  $a1, $zero
/* 100EE0 7F0CC3B0 0FC32EDD */  jal   check_load_image_to_buffer
/* 100EE4 7F0CC3B4 01CF2021 */   addu  $a0, $t6, $t7
/* 100EE8 7F0CC3B8 8E180000 */  lw    $t8, ($s0)
/* 100EEC 7F0CC3BC 3C190200 */  lui   $t9, %hi(globalDL_0x708) # $t9, 0x200
/* 100EF0 7F0CC3C0 27390708 */  addiu $t9, %lo(globalDL_0x708) # addiu $t9, $t9, 0x708
/* 100EF4 7F0CC3C4 00002825 */  move  $a1, $zero
/* 100EF8 7F0CC3C8 0FC32EDD */  jal   check_load_image_to_buffer
/* 100EFC 7F0CC3CC 03192021 */   addu  $a0, $t8, $t9
/* 100F00 7F0CC3D0 8E080000 */  lw    $t0, ($s0)
/* 100F04 7F0CC3D4 3C090200 */  lui   $t1, %hi(globalDL_0x7b0) # $t1, 0x200
/* 100F08 7F0CC3D8 252907B0 */  addiu $t1, %lo(globalDL_0x7b0) # addiu $t1, $t1, 0x7b0
/* 100F0C 7F0CC3DC 00002825 */  move  $a1, $zero
/* 100F10 7F0CC3E0 0FC32EDD */  jal   check_load_image_to_buffer
/* 100F14 7F0CC3E4 01092021 */   addu  $a0, $t0, $t1
/* 100F18 7F0CC3E8 8E0A0000 */  lw    $t2, ($s0)
/* 100F1C 7F0CC3EC 3C0B0200 */  lui   $t3, %hi(globalDL_0x858) # $t3, 0x200
/* 100F20 7F0CC3F0 256B0858 */  addiu $t3, %lo(globalDL_0x858) # addiu $t3, $t3, 0x858
/* 100F24 7F0CC3F4 00002825 */  move  $a1, $zero
/* 100F28 7F0CC3F8 0FC32EDD */  jal   check_load_image_to_buffer
/* 100F2C 7F0CC3FC 014B2021 */   addu  $a0, $t2, $t3
/* 100F30 7F0CC400 8E0C0000 */  lw    $t4, ($s0)
/* 100F34 7F0CC404 3C0D0200 */  lui   $t5, %hi(globalDL_0x900) # $t5, 0x200
/* 100F38 7F0CC408 25AD0900 */  addiu $t5, %lo(globalDL_0x900) # addiu $t5, $t5, 0x900
/* 100F3C 7F0CC40C 00002825 */  move  $a1, $zero
/* 100F40 7F0CC410 0FC32EDD */  jal   check_load_image_to_buffer
/* 100F44 7F0CC414 018D2021 */   addu  $a0, $t4, $t5
/* 100F48 7F0CC418 8E0E0000 */  lw    $t6, ($s0)
/* 100F4C 7F0CC41C 3C0F0200 */  lui   $t7, %hi(globalDL_0x9a8) # $t7, 0x200
/* 100F50 7F0CC420 25EF09A8 */  addiu $t7, %lo(globalDL_0x9a8) # addiu $t7, $t7, 0x9a8
/* 100F54 7F0CC424 00002825 */  move  $a1, $zero
/* 100F58 7F0CC428 0FC32EDD */  jal   check_load_image_to_buffer
/* 100F5C 7F0CC42C 01CF2021 */   addu  $a0, $t6, $t7
/* 100F60 7F0CC430 8E180000 */  lw    $t8, ($s0)
/* 100F64 7F0CC434 3C190200 */  lui   $t9, %hi(globalDL_0xa50) # $t9, 0x200
/* 100F68 7F0CC438 27390A50 */  addiu $t9, %lo(globalDL_0xa50) # addiu $t9, $t9, 0xa50
/* 100F6C 7F0CC43C 00002825 */  move  $a1, $zero
/* 100F70 7F0CC440 0FC32EDD */  jal   check_load_image_to_buffer
/* 100F74 7F0CC444 03192021 */   addu  $a0, $t8, $t9
/* 100F78 7F0CC448 3C048009 */  lui   $a0, %hi(genericimage)
/* 100F7C 7F0CC44C 8C84D0B8 */  lw    $a0, %lo(genericimage)($a0)
/* 100F80 7F0CC450 0FC32F06 */  jal   load_image_to_buffer
/* 100F84 7F0CC454 00002825 */   move  $a1, $zero
/* 100F88 7F0CC458 00008025 */  move  $s0, $zero
/* 100F8C 7F0CC45C 8E480000 */  lw    $t0, ($s2)
.L7F0CC460:
/* 100F90 7F0CC460 00002825 */  move  $a1, $zero
/* 100F94 7F0CC464 0FC32F06 */  jal   load_image_to_buffer
/* 100F98 7F0CC468 02082021 */   addu  $a0, $s0, $t0
/* 100F9C 7F0CC46C 2610000C */  addiu $s0, $s0, 0xc
/* 100FA0 7F0CC470 2A010048 */  slti  $at, $s0, 0x48
/* 100FA4 7F0CC474 5420FFFA */  bnezl $at, .L7F0CC460
/* 100FA8 7F0CC478 8E480000 */   lw    $t0, ($s2)
/* 100FAC 7F0CC47C 00008025 */  move  $s0, $zero
/* 100FB0 7F0CC480 2411003C */  li    $s1, 60
/* 100FB4 7F0CC484 8E690000 */  lw    $t1, ($s3)
.L7F0CC488:
/* 100FB8 7F0CC488 00002825 */  move  $a1, $zero
/* 100FBC 7F0CC48C 0FC32F06 */  jal   load_image_to_buffer
/* 100FC0 7F0CC490 02092021 */   addu  $a0, $s0, $t1
/* 100FC4 7F0CC494 2610000C */  addiu $s0, $s0, 0xc
/* 100FC8 7F0CC498 5611FFFB */  bnel  $s0, $s1, .L7F0CC488
/* 100FCC 7F0CC49C 8E690000 */   lw    $t1, ($s3)
/* 100FD0 7F0CC4A0 8FBF0024 */  lw    $ra, 0x24($sp)
/* 100FD4 7F0CC4A4 8FB00014 */  lw    $s0, 0x14($sp)
/* 100FD8 7F0CC4A8 8FB10018 */  lw    $s1, 0x18($sp)
/* 100FDC 7F0CC4AC 8FB2001C */  lw    $s2, 0x1c($sp)
/* 100FE0 7F0CC4B0 8FB30020 */  lw    $s3, 0x20($sp)
/* 100FE4 7F0CC4B4 03E00008 */  jr    $ra
/* 100FE8 7F0CC4B8 27BD0028 */   addiu $sp, $sp, 0x28
)
#endif


