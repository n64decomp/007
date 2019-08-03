#include "ultra64.h"
/**
 * @file speed_graph.c
 * This file contains code to draw speedgraph. 
 * 
 */


/*   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
    | Snippet of building glist buffers   |
    |_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _|

== H file ==
#define	GLIST_LEN	2048 // GE seems to be 266

/*
 * Layout of dynamic data.
 *
 * This structure holds the things which change per frame. It is advantageous
 * to keep dynamic data together so that we may selectively write back dirty
 * data cache lines to DRAM prior to processing by the RCP.
 *
 * /
typedef struct {
	Mtx	projection;
	Mtx	modeling;
	Mtx	modeling2;
	Mtx	viewing;
	LookAt	lookat;
	Hilite	hilite;
	Lightsn	light;          //Oh interesting, since we found this and LookAt, it seems dynamic gfx should astart right after.
	Gfx	glist[GLIST_LEN];
} Dynamic;

extern Dynamic	dynamic;

== H file End ==

/*
 * global variables
 *
Gfx		*glistp;	/* RSP display list pointer * /
//Dynamic		dynamic;	/* dynamic data * /
/ *
 * Double-buffered dynamic segments
 * /
Dynamic	dynamic[2];
...

// some function()
{
    ...
    int		current = 0;
    dynamicp = &dynamic[current];
    glistp = dynamicp->glist;
    //example gfx build
    gSPSegment(glistp++, 0, 0x0); // glist++ ready for next instruction (held in dynamic 1 or 2)
}
*/
    
/* tempory types confirm me */
s32 dword_CODE_bss_8005F3F0[4]; //Gfx Tiles_Setup? oh... unless thats what the next 2 are... the first command I recognised did start at 8005f400...
// dynamic glist, though it lacks the format above...
Gfx displaylist_0[266];
Gfx displaylist_1[266];
s32 displaylist_bank; //0 or 1? current?
s32 dword_CODE_bss_800604A4;
u32 dword_CODE_bss_800604A8;
u32 dword_CODE_bss_800604AC;
s32 dword_CODE_bss_800604B0[0xC0];
s32 dword_CODE_bss_800607B0;
s32 dword_CODE_bss_800607B4;
s32 dword_CODE_bss_800607B8;
s32 dword_CODE_bss_800607BC;
s32 dword_CODE_bss_800607C0;
s32 dword_CODE_bss_800607C4;
s32 dword_CODE_bss_800607C8;
s32 dword_CODE_bss_800607CC;
s32 dword_CODE_bss_800607D0;
s32 dword_CODE_bss_800607D4;
s32 dword_CODE_bss_800607D8;
s32 dword_CODE_bss_800607DC;

s32 D_800231D0 = 0;
s32 D_800231D4[] = { 0, 0, 2, 0, 1, 0, 2, 0, 2, 0xFF000000, 2, 0, 3, 0x9200, 4, 0xFFFFFFFF, 4, 0xDB000000, 4, 0xFFFFFFFF };

s32 D_80023224 = 0;
s32 D_80023228 = 0;
s32 D_8002322C = 0;
s32 counterforframes = 0;
s32 D_80023234 = 1;


//GLOBAL_ASM(
/*    .rodata*/
const char aUtz2_0f[] = "utz %2.0f%%\n";
const char aRsp2_0f[] = "rsp %2.0f%%\n";
const char aTex2_0f[] = "tex %2.0f%%";
const char a2dHz[] = "%2d hz";
const char a2dFrames[] = "%2d frames";
const char a2d[] = " [%2d]";
const char asc_D_80028468[] = "     ";
const char aIL0[] = "I=l0";
//)


/**
 * 3330	70002730	(DL generator)
 */
#ifdef NONMATCHING
void displaylist_related(void)
{
    void *temp_v0;
    void *temp_v1;
    void *phi_v1;
    void *phi_v0;

    gSPEndDisplayList(displaylist_0++);
    displaylist_0.unk850 = 0xb800000000000000; //? is this not dlist2?
    displaylist_bank = 0;
    phi_v1 = &dword_CODE_bss_800607B0;
    phi_v0 = &dword_CODE_bss_800607D0;
block_1:
    temp_v0 = (phi_v0 + 4);
    temp_v1 = (phi_v1 + 4);
    temp_v1->unk-4 = 0;
    temp_v0->unk-4 = 1;
    phi_v1 = temp_v1;
    phi_v0 = temp_v0;
    if (temp_v0 != &dword_CODE_bss_800607DC)
    {
        goto block_1;
    }
    video_related_2(1, &dword_CODE_bss_800607DC, 0xb8000000);
}
#else
GLOBAL_ASM(
.text
glabel displaylist_related
/* 003330 70002730 3C048006 */  lui   $a0, %hi(displaylist_0) # $a0, 0x8006
/* 003334 70002734 2484F400 */  addiu $a0, %lo(displaylist_0) # addiu $a0, $a0, -0xc00
/* 003338 70002738 3C06B800 */  lui   $a2, 0xb800
/* 00333C 7000273C AC860000 */  sw    $a2, ($a0)
/* 003340 70002740 AC800004 */  sw    $zero, 4($a0)
/* 003344 70002744 AC860850 */  sw    $a2, 0x850($a0)
/* 003348 70002748 AC800854 */  sw    $zero, 0x854($a0)
/* 00334C 7000274C 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 003350 70002750 3C018006 */  lui   $at, %hi(displaylist_bank) # $at, 0x8006
/* 003354 70002754 3C038006 */  lui   $v1, %hi(dword_CODE_bss_800607B0) # $v1, 0x8006
/* 003358 70002758 3C028006 */  lui   $v0, %hi(dword_CODE_bss_800607D0) # $v0, 0x8006
/* 00335C 7000275C 3C058006 */  lui   $a1, %hi(dword_CODE_bss_800607DC) # $a1, 0x8006
/* 003360 70002760 AFBF0014 */  sw    $ra, 0x14($sp)
/* 003364 70002764 AC2004A0 */  sw    $zero, %lo(displaylist_bank)($at)
/* 003368 70002768 24A507DC */  addiu $a1, %lo(dword_CODE_bss_800607DC) # addiu $a1, $a1, 0x7dc
/* 00336C 7000276C 244207D0 */  addiu $v0, %lo(dword_CODE_bss_800607D0) # addiu $v0, $v0, 0x7d0
/* 003370 70002770 246307B0 */  addiu $v1, %lo(dword_CODE_bss_800607B0) # addiu $v1, $v1, 0x7b0
/* 003374 70002774 24040001 */  li    $a0, 1
.L70002778:
/* 003378 70002778 24420004 */  addiu $v0, $v0, 4
/* 00337C 7000277C 24630004 */  addiu $v1, $v1, 4
/* 003380 70002780 AC60FFFC */  sw    $zero, -4($v1)
/* 003384 70002784 1445FFFC */  bne   $v0, $a1, .L70002778
/* 003388 70002788 AC44FFFC */   sw    $a0, -4($v0)
/* 00338C 7000278C 0C000A04 */  jal   video_related_2
/* 003390 70002790 00000000 */   nop   
/* 003394 70002794 8FBF0014 */  lw    $ra, 0x14($sp)
/* 003398 70002798 27BD0018 */  addiu $sp, $sp, 0x18
/* 00339C 7000279C 03E00008 */  jr    $ra
/* 0033A0 700027A0 00000000 */   nop   
)
#endif



/**
 * 33A4	700027A4
 */
#ifdef NONMATCHING
void *video_related_1(void)
{
    void *temp_v1;
    void *temp_a0;
    s32 temp_t7;
    s32 temp_t8;
    void *phi_v1;
    s32 phi_t8;
    void *phi_a0;

    dword_CODE_bss_800604A8 = osGetCount();
    phi_v1 = &dword_CODE_bss_800607D0;
    phi_a0 = &dword_CODE_bss_800607C0;
block_1:
    temp_v1 = (phi_v1 + 4);
    temp_a0 = (phi_a0 + 4);
    temp_t7 = (*phi_v1 + 0x1f);
    temp_t8 = (temp_t7 & 0x1f);
    phi_t8 = temp_t8;
    if (temp_t7 < 0)
    {
        phi_t8 = temp_t8;
        if (temp_t8 != 0)
        {
            phi_t8 = (temp_t8 + -0x20);
        }
    }
    temp_a0->unk-4 = (s32) phi_t8;
    phi_v1 = temp_v1;
    phi_a0 = temp_a0;
    if (temp_v1 != &dword_CODE_bss_800607DC)
    {
        goto block_1;
    }
    return &dword_CODE_bss_800607DC;
}
#else
GLOBAL_ASM(
.text
glabel video_related_1
/* 0033A4 700027A4 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0033A8 700027A8 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0033AC 700027AC 0C003638 */  jal   osGetCount
/* 0033B0 700027B0 00000000 */   nop   
/* 0033B4 700027B4 3C018006 */  lui   $at, %hi(dword_CODE_bss_800604A8) # $at, 0x8006
/* 0033B8 700027B8 AC2204A8 */  sw    $v0, %lo(dword_CODE_bss_800604A8)($at)
/* 0033BC 700027BC 3C028006 */  lui   $v0, %hi(dword_CODE_bss_800607DC) # $v0, 0x8006
/* 0033C0 700027C0 3C048006 */  lui   $a0, %hi(dword_CODE_bss_800607C0) # $a0, 0x8006
/* 0033C4 700027C4 3C038006 */  lui   $v1, %hi(dword_CODE_bss_800607D0) # $v1, 0x8006
/* 0033C8 700027C8 246307D0 */  addiu $v1, %lo(dword_CODE_bss_800607D0) # addiu $v1, $v1, 0x7d0
/* 0033CC 700027CC 248407C0 */  addiu $a0, %lo(dword_CODE_bss_800607C0) # addiu $a0, $a0, 0x7c0
/* 0033D0 700027D0 244207DC */  addiu $v0, %lo(dword_CODE_bss_800607DC) # addiu $v0, $v0, 0x7dc
.L700027D4:
/* 0033D4 700027D4 8C6E0000 */  lw    $t6, ($v1)
/* 0033D8 700027D8 24630004 */  addiu $v1, $v1, 4
/* 0033DC 700027DC 24840004 */  addiu $a0, $a0, 4
/* 0033E0 700027E0 25CF001F */  addiu $t7, $t6, 0x1f
/* 0033E4 700027E4 05E10004 */  bgez  $t7, .L700027F8
/* 0033E8 700027E8 31F8001F */   andi  $t8, $t7, 0x1f
/* 0033EC 700027EC 13000002 */  beqz  $t8, .L700027F8
/* 0033F0 700027F0 00000000 */   nop   
/* 0033F4 700027F4 2718FFE0 */  addiu $t8, $t8, -0x20
.L700027F8:
/* 0033F8 700027F8 1462FFF6 */  bne   $v1, $v0, .L700027D4
/* 0033FC 700027FC AC98FFFC */   sw    $t8, -4($a0)
/* 003400 70002800 8FBF0014 */  lw    $ra, 0x14($sp)
/* 003404 70002804 27BD0018 */  addiu $sp, $sp, 0x18
/* 003408 70002808 03E00008 */  jr    $ra
/* 00340C 7000280C 00000000 */   nop   
)
#endif


/**
 * 3410	70002810
 */
#ifdef NONMATCHING
void *video_related_2(void)
{
    void *temp_a0;
    void *temp_v1;
    void *phi_a0;
    void *phi_v1;

    dword_CODE_bss_800604A4 = (?32) dword_CODE_bss_800604A8;
    phi_a0 = &dword_CODE_bss_800607C0;
    phi_v1 = &dword_CODE_bss_800607B0;
block_1:
    temp_a0 = (phi_a0 + 4);
    temp_v1 = (phi_v1 + 4);
    temp_v1->unk-4 = (?32) *phi_a0;
    phi_a0 = temp_a0;
    phi_v1 = temp_v1;
    if (temp_a0 != &dword_CODE_bss_800607CC)
    {
        goto block_1;
    }
    return &dword_CODE_bss_800607CC;
}
#else
GLOBAL_ASM(
.text
glabel video_related_2
/* 003410 70002810 3C0E8006 */  lui   $t6, %hi(dword_CODE_bss_800604A8) # $t6, 0x8006
/* 003414 70002814 8DCE04A8 */  lw    $t6, %lo(dword_CODE_bss_800604A8)($t6)
/* 003418 70002818 3C018006 */  lui   $at, %hi(dword_CODE_bss_800604A4) # $at, 0x8006
/* 00341C 7000281C 3C038006 */  lui   $v1, %hi(dword_CODE_bss_800607B0) # $v1, 0x8006
/* 003420 70002820 3C048006 */  lui   $a0, %hi(dword_CODE_bss_800607C0) # $a0, 0x8006
/* 003424 70002824 3C028006 */  lui   $v0, %hi(dword_CODE_bss_800607CC) # $v0, 0x8006
/* 003428 70002828 244207CC */  addiu $v0, %lo(dword_CODE_bss_800607CC) # addiu $v0, $v0, 0x7cc
/* 00342C 7000282C 248407C0 */  addiu $a0, %lo(dword_CODE_bss_800607C0) # addiu $a0, $a0, 0x7c0
/* 003430 70002830 246307B0 */  addiu $v1, %lo(dword_CODE_bss_800607B0) # addiu $v1, $v1, 0x7b0
/* 003434 70002834 AC2E04A4 */  sw    $t6, %lo(dword_CODE_bss_800604A4)($at)
.L70002838:
/* 003438 70002838 8C8F0000 */  lw    $t7, ($a0)
/* 00343C 7000283C 24840004 */  addiu $a0, $a0, 4
/* 003440 70002840 24630004 */  addiu $v1, $v1, 4
/* 003444 70002844 1482FFFC */  bne   $a0, $v0, .L70002838
/* 003448 70002848 AC6FFFFC */   sw    $t7, -4($v1)
/* 00344C 7000284C 03E00008 */  jr    $ra
/* 003450 70002850 00000000 */   nop   
)
#endif


/**
 * 3454	70002854
 */
#ifdef NONMATCHING
void video_related_3(s32 arg0)
{
    s32 sp34;
    void *sp2C;
    void *sp24;
    void *sp1C;
    s32 temp_a3;
    s32 temp_v1;
    void *temp_t0;
    s32 temp_a0;
    void *temp_v0;
    s32 temp_a1;
    s32 phi_a2;
    s32 phi_a1;

    temp_a3 = (arg0 & 0xffff);
    temp_v1 = (temp_a3 * 4);
    temp_t0 = (temp_v1 + &dword_CODE_bss_800607D0);
    temp_a0 = (arg0 >> 0x10);
    sp34 = osSetIntMask(1);
    if (temp_a0 == 3)
    {
        phi_a2 = ((0x80060000 + temp_v1)->unk-C10 | 0x8000);
    }
    else
    {
        phi_a2 = temp_a0;
        if (temp_a0 == 6)
        {
            phi_a2 = ((0x80060000 + temp_v1)->unk-C10 & 0x7fff);
        }
    }
    temp_v0 = (((temp_a3 << 8) + (*temp_t0 * 8)) + &dword_CODE_bss_800604B0);
    sp2C = temp_v0;
    *temp_v0 = (s32) phi_a2;
    sp24 = (void *) (temp_v1 + &dword_CODE_bss_8005F3F0);
    sp1C = temp_t0;
    sp2C->unk4 = osGetCount(temp_a0, *temp_t0, phi_a2, temp_a3);
    temp_a1 = (sp30 + 1);
    *sp24 = sp38;
    phi_a1 = temp_a1;
    if (temp_a1 >= 0x20)
    {
        phi_a1 = 0;
    }
    *temp_t0 = (s32) phi_a1;
    osSetIntMask(sp34, phi_a1, sp38);
}
#else
GLOBAL_ASM(
.text
glabel video_related_3
/* 003454 70002854 27BDFFC0 */  addiu $sp, $sp, -0x40
/* 003458 70002858 AFBF0014 */  sw    $ra, 0x14($sp)
/* 00345C 7000285C AFA40040 */  sw    $a0, 0x40($sp)
/* 003460 70002860 0C00374C */  jal   osSetIntMask
/* 003464 70002864 24040001 */   li    $a0, 1
/* 003468 70002868 8FA90040 */  lw    $t1, 0x40($sp)
/* 00346C 7000286C 3C0E8006 */  lui   $t6, %hi(dword_CODE_bss_800607D0) # $t6, 0x8006
/* 003470 70002870 25CE07D0 */  addiu $t6, %lo(dword_CODE_bss_800607D0) # addiu $t6, $t6, 0x7d0
/* 003474 70002874 3127FFFF */  andi  $a3, $t1, 0xffff
/* 003478 70002878 00071880 */  sll   $v1, $a3, 2
/* 00347C 7000287C 006E4021 */  addu  $t0, $v1, $t6
/* 003480 70002880 24010003 */  li    $at, 3
/* 003484 70002884 00092403 */  sra   $a0, $t1, 0x10
/* 003488 70002888 AFA20034 */  sw    $v0, 0x34($sp)
/* 00348C 7000288C 00803025 */  move  $a2, $a0
/* 003490 70002890 14810007 */  bne   $a0, $at, .L700028B0
/* 003494 70002894 8D050000 */   lw    $a1, ($t0)
/* 003498 70002898 3C068006 */  lui   $a2, %hi(dword_CODE_bss_8005F3F0)
/* 00349C 7000289C 00C33021 */  addu  $a2, $a2, $v1
/* 0034A0 700028A0 8CC6F3F0 */  lw    $a2, %lo(dword_CODE_bss_8005F3F0)($a2)
/* 0034A4 700028A4 34CF8000 */  ori   $t7, $a2, 0x8000
/* 0034A8 700028A8 10000009 */  b     .L700028D0
/* 0034AC 700028AC 01E03025 */   move  $a2, $t7
.L700028B0:
/* 0034B0 700028B0 24010006 */  li    $at, 6
/* 0034B4 700028B4 54810007 */  bnel  $a0, $at, .L700028D4
/* 0034B8 700028B8 0007CA00 */   sll   $t9, $a3, 8
/* 0034BC 700028BC 3C068006 */  lui   $a2, %hi(dword_CODE_bss_8005F3F0)
/* 0034C0 700028C0 00C33021 */  addu  $a2, $a2, $v1
/* 0034C4 700028C4 8CC6F3F0 */  lw    $a2, %lo(dword_CODE_bss_8005F3F0)($a2)
/* 0034C8 700028C8 30D87FFF */  andi  $t8, $a2, 0x7fff
/* 0034CC 700028CC 03003025 */  move  $a2, $t8
.L700028D0:
/* 0034D0 700028D0 0007CA00 */  sll   $t9, $a3, 8
.L700028D4:
/* 0034D4 700028D4 000550C0 */  sll   $t2, $a1, 3
/* 0034D8 700028D8 3C0C8006 */  lui   $t4, %hi(dword_CODE_bss_800604B0) # $t4, 0x8006
/* 0034DC 700028DC 3C0D8006 */  lui   $t5, %hi(dword_CODE_bss_8005F3F0) # $t5, 0x8006
/* 0034E0 700028E0 258C04B0 */  addiu $t4, %lo(dword_CODE_bss_800604B0) # addiu $t4, $t4, 0x4b0
/* 0034E4 700028E4 032A5821 */  addu  $t3, $t9, $t2
/* 0034E8 700028E8 25ADF3F0 */  addiu $t5, %lo(dword_CODE_bss_8005F3F0) # addiu $t5, $t5, -0xc10
/* 0034EC 700028EC 016C1021 */  addu  $v0, $t3, $t4
/* 0034F0 700028F0 006D7021 */  addu  $t6, $v1, $t5
/* 0034F4 700028F4 AFA2002C */  sw    $v0, 0x2c($sp)
/* 0034F8 700028F8 AC460000 */  sw    $a2, ($v0)
/* 0034FC 700028FC AFAE0024 */  sw    $t6, 0x24($sp)
/* 003500 70002900 AFA50030 */  sw    $a1, 0x30($sp)
/* 003504 70002904 AFA60038 */  sw    $a2, 0x38($sp)
/* 003508 70002908 0C003638 */  jal   osGetCount
/* 00350C 7000290C AFA8001C */   sw    $t0, 0x1c($sp)
/* 003510 70002910 8FAF002C */  lw    $t7, 0x2c($sp)
/* 003514 70002914 8FA50030 */  lw    $a1, 0x30($sp)
/* 003518 70002918 8FA60038 */  lw    $a2, 0x38($sp)
/* 00351C 7000291C 8FA8001C */  lw    $t0, 0x1c($sp)
/* 003520 70002920 ADE20004 */  sw    $v0, 4($t7)
/* 003524 70002924 8FB80024 */  lw    $t8, 0x24($sp)
/* 003528 70002928 24A50001 */  addiu $a1, $a1, 1
/* 00352C 7000292C 28A10020 */  slti  $at, $a1, 0x20
/* 003530 70002930 14200002 */  bnez  $at, .L7000293C
/* 003534 70002934 AF060000 */   sw    $a2, ($t8)
/* 003538 70002938 00002825 */  move  $a1, $zero
.L7000293C:
/* 00353C 7000293C AD050000 */  sw    $a1, ($t0)
/* 003540 70002940 0C00374C */  jal   osSetIntMask
/* 003544 70002944 8FA40034 */   lw    $a0, 0x34($sp)
/* 003548 70002948 8FBF0014 */  lw    $ra, 0x14($sp)
/* 00354C 7000294C 27BD0040 */  addiu $sp, $sp, 0x40
/* 003550 70002950 03E00008 */  jr    $ra
/* 003554 70002954 00000000 */   nop   
)
#endif


/**
 * 3558	70002958	draw "display speed" display
 *     accepts: A0=p->display list
 */
#ifdef NONMATCHING
void display_speed_graph(void) {

}
#else
GLOBAL_ASM(
.text
glabel display_speed_graph
/* 003558 70002958 3C038005 */  lui   $v1, %hi(D_80048498) # $v1, 0x8005
/* 00355C 7000295C 3C0E8002 */  lui   $t6, %hi(D_80023228) # $t6, 0x8002
/* 003560 70002960 8C638498 */  lw    $v1, %lo(D_80048498)($v1)
/* 003564 70002964 8DCE3228 */  lw    $t6, %lo(D_80023228)($t6)
/* 003568 70002968 3C028002 */  lui   $v0, %hi(D_80023224) # $v0, 0x8002
/* 00356C 7000296C 8C423224 */  lw    $v0, %lo(D_80023224)($v0)
/* 003570 70002970 27BDFFB8 */  addiu $sp, $sp, -0x48
/* 003574 70002974 01C3082A */  slt   $at, $t6, $v1
/* 003578 70002978 AFBF001C */  sw    $ra, 0x1c($sp)
/* 00357C 7000297C AFB00018 */  sw    $s0, 0x18($sp)
/* 003580 70002980 10200003 */  beqz  $at, .L70002990
/* 003584 70002984 00431021 */   addu  $v0, $v0, $v1
/* 003588 70002988 3C018002 */  lui   $at, %hi(D_80023228) # $at, 0x8002
/* 00358C 7000298C AC233228 */  sw    $v1, %lo(D_80023228)($at)
.L70002990:
/* 003590 70002990 3C018002 */  lui   $at, %hi(D_80023224) # $at, 0x8002
/* 003594 70002994 AC223224 */  sw    $v0, %lo(D_80023224)($at)
/* 003598 70002998 2C410015 */  sltiu $at, $v0, 0x15
/* 00359C 7000299C 142000BB */  bnez  $at, .L70002C8C
/* 0035A0 700029A0 3C018002 */   lui   $at, %hi(D_80023224) # $at, 0x8002
/* 0035A4 700029A4 AC223224 */  sw    $v0, %lo(D_80023224)($at)
/* 0035A8 700029A8 2C410015 */  sltiu $at, $v0, 0x15
/* 0035AC 700029AC 14200006 */  bnez  $at, .L700029C8
/* 0035B0 700029B0 2442FFEC */   addiu $v0, $v0, -0x14
.L700029B4:
/* 0035B4 700029B4 2C410015 */  sltiu $at, $v0, 0x15
/* 0035B8 700029B8 5020FFFE */  beql  $at, $zero, .L700029B4
/* 0035BC 700029BC 2442FFEC */   addiu $v0, $v0, -0x14
/* 0035C0 700029C0 3C018002 */  lui   $at, %hi(D_80023224) # $at, 0x8002
/* 0035C4 700029C4 AC223224 */  sw    $v0, %lo(D_80023224)($at)
.L700029C8:
/* 0035C8 700029C8 0C000447 */  jal   get_counters
/* 0035CC 700029CC AFA40048 */   sw    $a0, 0x48($sp)
/* 0035D0 700029D0 AFA20044 */  sw    $v0, 0x44($sp)
/* 0035D4 700029D4 240400FF */  li    $a0, 255
/* 0035D8 700029D8 240500FF */  li    $a1, 255
/* 0035DC 700029DC 240600FF */  li    $a2, 255
/* 0035E0 700029E0 0C002C1B */  jal   set_debug_text_color
/* 0035E4 700029E4 240700FF */   li    $a3, 255
/* 0035E8 700029E8 00002025 */  move  $a0, $zero
/* 0035EC 700029EC 00002825 */  move  $a1, $zero
/* 0035F0 700029F0 00003025 */  move  $a2, $zero
/* 0035F4 700029F4 0C002C26 */  jal   set_color_speedgraph
/* 0035F8 700029F8 240700FF */   li    $a3, 255
/* 0035FC 700029FC 24040008 */  li    $a0, 8
/* 003600 70002A00 0C002C10 */  jal   set_final_debug_text_positions
/* 003604 70002A04 24050005 */   li    $a1, 5
/* 003608 70002A08 8FA20044 */  lw    $v0, 0x44($sp)
/* 00360C 70002A0C 27B00030 */  addiu $s0, $sp, 0x30
/* 003610 70002A10 3C058003 */  lui   $a1, %hi(aUtz2_0f) # $a1, 0x8003
/* 003614 70002A14 8C4F0004 */  lw    $t7, 4($v0)
/* 003618 70002A18 8C58000C */  lw    $t8, 0xc($v0)
/* 00361C 70002A1C 24A58420 */  addiu $a1, %lo(aUtz2_0f) # addiu $a1, $a1, -0x7be0
/* 003620 70002A20 02002025 */  move  $a0, $s0
/* 003624 70002A24 01F8C823 */  subu  $t9, $t7, $t8
/* 003628 70002A28 44992000 */  mtc1  $t9, $f4
/* 00362C 70002A2C 07210005 */  bgez  $t9, .L70002A44
/* 003630 70002A30 468021A0 */   cvt.s.w $f6, $f4
/* 003634 70002A34 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 003638 70002A38 44814000 */  mtc1  $at, $f8
/* 00363C 70002A3C 00000000 */  nop   
/* 003640 70002A40 46083180 */  add.s $f6, $f6, $f8
.L70002A44:
/* 003644 70002A44 8C480000 */  lw    $t0, ($v0)
/* 003648 70002A48 3C0142C8 */  li    $at, 0x42C80000 # 100.000000
/* 00364C 70002A4C 44815000 */  mtc1  $at, $f10
/* 003650 70002A50 44889000 */  mtc1  $t0, $f18
/* 003654 70002A54 460A3402 */  mul.s $f16, $f6, $f10
/* 003658 70002A58 05010005 */  bgez  $t0, .L70002A70
/* 00365C 70002A5C 46809120 */   cvt.s.w $f4, $f18
/* 003660 70002A60 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 003664 70002A64 44814000 */  mtc1  $at, $f8
/* 003668 70002A68 00000000 */  nop   
/* 00366C 70002A6C 46082100 */  add.s $f4, $f4, $f8
.L70002A70:
/* 003670 70002A70 46048183 */  div.s $f6, $f16, $f4
/* 003674 70002A74 460032A1 */  cvt.d.s $f10, $f6
/* 003678 70002A78 44075000 */  mfc1  $a3, $f10
/* 00367C 70002A7C 44065800 */  mfc1  $a2, $f11
/* 003680 70002A80 0C002B25 */  jal   sprintf
/* 003684 70002A84 00000000 */   nop   
/* 003688 70002A88 0C002C7A */  jal   write_string_stdout
/* 00368C 70002A8C 02002025 */   move  $a0, $s0
/* 003690 70002A90 24040008 */  li    $a0, 8
/* 003694 70002A94 0C002C10 */  jal   set_final_debug_text_positions
/* 003698 70002A98 24050006 */   li    $a1, 6
/* 00369C 70002A9C 8FA30044 */  lw    $v1, 0x44($sp)
/* 0036A0 70002AA0 3C058003 */  lui   $a1, %hi(aRsp2_0f) # $a1, 0x8003
/* 0036A4 70002AA4 24A58430 */  addiu $a1, %lo(aRsp2_0f) # addiu $a1, $a1, -0x7bd0
/* 0036A8 70002AA8 8C620000 */  lw    $v0, ($v1)
/* 0036AC 70002AAC 8C690004 */  lw    $t1, 4($v1)
/* 0036B0 70002AB0 02002025 */  move  $a0, $s0
/* 0036B4 70002AB4 44825000 */  mtc1  $v0, $f10
/* 0036B8 70002AB8 00495023 */  subu  $t2, $v0, $t1
/* 0036BC 70002ABC 448A9000 */  mtc1  $t2, $f18
/* 0036C0 70002AC0 05410005 */  bgez  $t2, .L70002AD8
/* 0036C4 70002AC4 46809220 */   cvt.s.w $f8, $f18
/* 0036C8 70002AC8 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0036CC 70002ACC 44818000 */  mtc1  $at, $f16
/* 0036D0 70002AD0 00000000 */  nop   
/* 0036D4 70002AD4 46104200 */  add.s $f8, $f8, $f16
.L70002AD8:
/* 0036D8 70002AD8 3C0142C8 */  li    $at, 0x42C80000 # 100.000000
/* 0036DC 70002ADC 44812000 */  mtc1  $at, $f4
/* 0036E0 70002AE0 468054A0 */  cvt.s.w $f18, $f10
/* 0036E4 70002AE4 46044182 */  mul.s $f6, $f8, $f4
/* 0036E8 70002AE8 04410004 */  bgez  $v0, .L70002AFC
/* 0036EC 70002AEC 3C014F80 */   li    $at, 0x4F800000 # 4294967296.000000
/* 0036F0 70002AF0 44818000 */  mtc1  $at, $f16
/* 0036F4 70002AF4 00000000 */  nop   
/* 0036F8 70002AF8 46109480 */  add.s $f18, $f18, $f16
.L70002AFC:
/* 0036FC 70002AFC 46123203 */  div.s $f8, $f6, $f18
/* 003700 70002B00 46004121 */  cvt.d.s $f4, $f8
/* 003704 70002B04 44072000 */  mfc1  $a3, $f4
/* 003708 70002B08 44062800 */  mfc1  $a2, $f5
/* 00370C 70002B0C 0C002B25 */  jal   sprintf
/* 003710 70002B10 00000000 */   nop   
/* 003714 70002B14 0C002C7A */  jal   write_string_stdout
/* 003718 70002B18 02002025 */   move  $a0, $s0
/* 00371C 70002B1C 24040008 */  li    $a0, 8
/* 003720 70002B20 0C002C10 */  jal   set_final_debug_text_positions
/* 003724 70002B24 24050007 */   li    $a1, 7
/* 003728 70002B28 8FAB0044 */  lw    $t3, 0x44($sp)
/* 00372C 70002B2C 3C058003 */  lui   $a1, %hi(aTex2_0f) # $a1, 0x8003
/* 003730 70002B30 24A58440 */  addiu $a1, %lo(aTex2_0f) # addiu $a1, $a1, -0x7bc0
/* 003734 70002B34 8D6C000C */  lw    $t4, 0xc($t3)
/* 003738 70002B38 02002025 */  move  $a0, $s0
/* 00373C 70002B3C 448C5000 */  mtc1  $t4, $f10
/* 003740 70002B40 05810005 */  bgez  $t4, .L70002B58
/* 003744 70002B44 46805420 */   cvt.s.w $f16, $f10
/* 003748 70002B48 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 00374C 70002B4C 44813000 */  mtc1  $at, $f6
/* 003750 70002B50 00000000 */  nop   
/* 003754 70002B54 46068400 */  add.s $f16, $f16, $f6
.L70002B58:
/* 003758 70002B58 8D6D0000 */  lw    $t5, ($t3)
/* 00375C 70002B5C 3C0142C8 */  li    $at, 0x42C80000 # 100.000000
/* 003760 70002B60 44819000 */  mtc1  $at, $f18
/* 003764 70002B64 448D2000 */  mtc1  $t5, $f4
/* 003768 70002B68 46128202 */  mul.s $f8, $f16, $f18
/* 00376C 70002B6C 05A10005 */  bgez  $t5, .L70002B84
/* 003770 70002B70 468022A0 */   cvt.s.w $f10, $f4
/* 003774 70002B74 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 003778 70002B78 44813000 */  mtc1  $at, $f6
/* 00377C 70002B7C 00000000 */  nop   
/* 003780 70002B80 46065280 */  add.s $f10, $f10, $f6
.L70002B84:
/* 003784 70002B84 460A4403 */  div.s $f16, $f8, $f10
/* 003788 70002B88 460084A1 */  cvt.d.s $f18, $f16
/* 00378C 70002B8C 44079000 */  mfc1  $a3, $f18
/* 003790 70002B90 44069800 */  mfc1  $a2, $f19
/* 003794 70002B94 0C002B25 */  jal   sprintf
/* 003798 70002B98 00000000 */   nop   
/* 00379C 70002B9C 0C002C7A */  jal   write_string_stdout
/* 0037A0 70002BA0 02002025 */   move  $a0, $s0
/* 0037A4 70002BA4 2404001C */  li    $a0, 28
/* 0037A8 70002BA8 0C002C10 */  jal   set_final_debug_text_positions
/* 0037AC 70002BAC 24050005 */   li    $a1, 5
/* 0037B0 70002BB0 3C038005 */  lui   $v1, %hi(D_80048498) # $v1, 0x8005
/* 0037B4 70002BB4 8C638498 */  lw    $v1, %lo(D_80048498)($v1)
/* 0037B8 70002BB8 02002025 */  move  $a0, $s0
/* 0037BC 70002BBC 3C058003 */  lui   $a1, %hi(a2dHz) # $a1, 0x8003
/* 0037C0 70002BC0 14600003 */  bnez  $v1, .L70002BD0
/* 0037C4 70002BC4 240E003C */   li    $t6, 60
/* 0037C8 70002BC8 1000000C */  b     .L70002BFC
/* 0037CC 70002BCC 00003025 */   move  $a2, $zero
.L70002BD0:
/* 0037D0 70002BD0 01C3001A */  div   $zero, $t6, $v1
/* 0037D4 70002BD4 00003012 */  mflo  $a2
/* 0037D8 70002BD8 14600002 */  bnez  $v1, .L70002BE4
/* 0037DC 70002BDC 00000000 */   nop   
/* 0037E0 70002BE0 0007000D */  break 7
.L70002BE4:
/* 0037E4 70002BE4 2401FFFF */  li    $at, -1
/* 0037E8 70002BE8 14610004 */  bne   $v1, $at, .L70002BFC
/* 0037EC 70002BEC 3C018000 */   lui   $at, 0x8000
/* 0037F0 70002BF0 15C10002 */  bne   $t6, $at, .L70002BFC
/* 0037F4 70002BF4 00000000 */   nop   
/* 0037F8 70002BF8 0006000D */  break 6
.L70002BFC:
/* 0037FC 70002BFC 0C002B25 */  jal   sprintf
/* 003800 70002C00 24A5844C */   addiu $a1, %lo(a2dHz) # addiu $a1, $a1, -0x7bb4
/* 003804 70002C04 0C002C7A */  jal   write_string_stdout
/* 003808 70002C08 02002025 */   move  $a0, $s0
/* 00380C 70002C0C 2404001C */  li    $a0, 28
/* 003810 70002C10 0C002C10 */  jal   set_final_debug_text_positions
/* 003814 70002C14 24050006 */   li    $a1, 6
/* 003818 70002C18 3C058003 */  lui   $a1, %hi(a2dFrames) # $a1, 0x8003
/* 00381C 70002C1C 3C068005 */  lui   $a2, %hi(D_80048498) # $a2, 0x8005
/* 003820 70002C20 8CC68498 */  lw    $a2, %lo(D_80048498)($a2)
/* 003824 70002C24 24A58454 */  addiu $a1, %lo(a2dFrames) # addiu $a1, $a1, -0x7bac
/* 003828 70002C28 0C002B25 */  jal   sprintf
/* 00382C 70002C2C 02002025 */   move  $a0, $s0
/* 003830 70002C30 0C002C7A */  jal   write_string_stdout
/* 003834 70002C34 02002025 */   move  $a0, $s0
/* 003838 70002C38 3C0F8002 */  lui   $t7, %hi(D_80023228) # $t7, 0x8002
/* 00383C 70002C3C 3C188005 */  lui   $t8, %hi(D_80048498) # $t8, 0x8005
/* 003840 70002C40 8F188498 */  lw    $t8, %lo(D_80048498)($t8)
/* 003844 70002C44 8DEF3228 */  lw    $t7, %lo(D_80023228)($t7)
/* 003848 70002C48 02002025 */  move  $a0, $s0
/* 00384C 70002C4C 3C058003 */  lui   $a1, %hi(asc_D_80028468)
/* 003850 70002C50 11F80007 */  beq   $t7, $t8, .L70002C70
/* 003854 70002C54 01E03025 */   move  $a2, $t7
/* 003858 70002C58 3C058003 */  lui   $a1, %hi(a2d) # $a1, 0x8003
/* 00385C 70002C5C 24A58460 */  addiu $a1, %lo(a2d) # addiu $a1, $a1, -0x7ba0
/* 003860 70002C60 0C002B25 */  jal   sprintf
/* 003864 70002C64 02002025 */   move  $a0, $s0
/* 003868 70002C68 10000003 */  b     .L70002C78
/* 00386C 70002C6C 00000000 */   nop   
.L70002C70:
/* 003870 70002C70 0C002B25 */  jal   sprintf
/* 003874 70002C74 24A58468 */   addiu $a1, $a1, %lo(asc_D_80028468)
.L70002C78:
/* 003878 70002C78 0C002C7A */  jal   write_string_stdout
/* 00387C 70002C7C 02002025 */   move  $a0, $s0
/* 003880 70002C80 3C018002 */  lui   $at, %hi(D_80023228) # $at, 0x8002
/* 003884 70002C84 AC203228 */  sw    $zero, %lo(D_80023228)($at)
/* 003888 70002C88 8FA40048 */  lw    $a0, 0x48($sp)
.L70002C8C:
/* 00388C 70002C8C 3C190600 */  lui   $t9, 0x600
/* 003890 70002C90 AC990000 */  sw    $t9, ($a0)
/* 003894 70002C94 3C088006 */  lui   $t0, %hi(displaylist_bank) # $t0, 0x8006
/* 003898 70002C98 8D0804A0 */  lw    $t0, %lo(displaylist_bank)($t0)
/* 00389C 70002C9C 3C0C8006 */  lui   $t4, %hi(displaylist_0) # $t4, 0x8006
/* 0038A0 70002CA0 258CF400 */  addiu $t4, %lo(displaylist_0) # addiu $t4, $t4, -0xc00
/* 0038A4 70002CA4 39090001 */  xori  $t1, $t0, 1
/* 0038A8 70002CA8 00095140 */  sll   $t2, $t1, 5
/* 0038AC 70002CAC 01495021 */  addu  $t2, $t2, $t1
/* 0038B0 70002CB0 000A5080 */  sll   $t2, $t2, 2
/* 0038B4 70002CB4 01495021 */  addu  $t2, $t2, $t1
/* 0038B8 70002CB8 000A5100 */  sll   $t2, $t2, 4
/* 0038BC 70002CBC 014C5821 */  addu  $t3, $t2, $t4
/* 0038C0 70002CC0 AC8B0004 */  sw    $t3, 4($a0)
/* 0038C4 70002CC4 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0038C8 70002CC8 8FB00018 */  lw    $s0, 0x18($sp)
/* 0038CC 70002CCC 24820008 */  addiu $v0, $a0, 8
/* 0038D0 70002CD0 03E00008 */  jr    $ra
/* 0038D4 70002CD4 27BD0048 */   addiu $sp, $sp, 0x48
)
#endif


/**
 * 38D8	70002CD8
 */
#ifdef NONMATCHING
u32 video_DL_related_4(void)
{
    s32 spC8;
    ? spB8;
    ? spAC;
    ? spA0;
    s32 sp80;
    void *sp70;
    u32 temp_v0;
    u32 temp_s4;
    u32 temp_s5;
    void *temp_s4_2;
    void *temp_s5_2;
    void *temp_v0_2;
    void *temp_t0;
    f32 temp_f12;
    s32 temp_s3;
    s32 temp_s1;
    s32 temp_t9;
    s32 temp_t3;
    u32 temp_ret;
    u32 phi_s4;
    u32 phi_s5;
    s32 phi_s1;
    u32 phi_v1;
    s32 phi_a1;
    void *phi_s3;
    void *phi_v0;
    s32 phi_s2;
    s32 phi_t9;
    s32 phi_a1_2;
    s32 phi_a1_3;
    void *phi_s3_2;
    u32 phi_return;
    void *phi_s3_3;
    void *phi_s3_4;
    s32 phi_s3_5;

    temp_v0 = (counterforframes + D_80048498);
    counterforframes = temp_v0;
    if (temp_v0 >= 0xc9U)
    {
        D_80023234 = (s32) (D_80023234 ^ 1);
        counterforframes = (u32) (temp_v0 + -0xc8);
    }
    D_8002322C = (s32) (D_8002322C + 1);
    phi_return = temp_v0;
    if (D_80023234 != (D_8002322C & 1))
    {
        phi_s4 = &spAC;
block_4:
        temp_s4 = (phi_s4 + 4);
        temp_s4->unk-4 = 0;
        phi_s4 = temp_s4;
        if (temp_s4 < &spB8)
        {
            goto block_4;
        }
        phi_s5 = &spA0;
block_6:
        temp_s5 = (phi_s5 + 4);
        temp_s5->unk-4 = (u32) dword_CODE_bss_800604A4;
        phi_s5 = temp_s5;
        if (temp_s5 < &spAC)
        {
            goto block_6;
        }
        sp70 = &dword_CODE_bss_800607B0;
        spC8 = 0;
        sp80 = 0;
        phi_s3_4 = sub_GAME_7F0D1AC0(((displaylist_bank * 0x850) + &displaylist_0));
block_8:
        temp_s4_2 = (sp80 + &spAC);
        phi_a1_3 = subroutine_arg0;
        phi_s3_2 = phi_s3_4;
        if (*sp70 != subroutine_arg0)
        {
            temp_s5_2 = (sp80 + &spA0);
            phi_s1 = *sp70;
            phi_a1 = subroutine_arg0;
            phi_s3 = phi_s3_4;
block_10:
            temp_v0_2 = (((spC8 << 8) + &dword_CODE_bss_800604B0) + (phi_s1 * 8));
            phi_s2 = *temp_v0_2;
            if ((*temp_v0_2 & 0x8000) != 0)
            {
                phi_s2 = 3;
            }
            phi_v1 = *temp_s5_2;
            if ((u32) *temp_s5_2 < (u32) dword_CODE_bss_800604A4)
            {
                phi_v1 = dword_CODE_bss_800604A4;
            }
            phi_a1_2 = phi_a1;
            phi_s3_3 = phi_s3;
            if ((u32) temp_v0_2->unk4 >= (u32) dword_CODE_bss_800604A4)
            {
                phi_a1_2 = phi_a1;
                phi_s3_3 = phi_s3;
                if ((u32) temp_v0_2->unk4 >= (u32) phi_v1)
                {
                    if (1 != *temp_s4_2)
                    {
                        if (*temp_s4_2 != 3)
                        {
                            if ((*temp_s4_2 & 0x8000) == 0)
                            {
                                if ((temp_v0_2->unk4 - phi_v1) < 0)
                                {

                                }
                            }
                        }
                    }
                    temp_t0 = ((*temp_s4_2 * 0x10) + &D_800231D4+4);
                    temp_f12 = ((f32) (u32) (temp_v0_2->unk4 - phi_v1) / aIL0);
                    if (1 == *temp_s4_2)
                    {
                        sub_GAME_7F0D1DCC(temp_f12, dword_CODE_bss_800604A4, phi_a1);
                        phi_v0 = phi_s3;
                        phi_s3_5 = (s32) phi_s3;
                    }
                    else
                    {
                        temp_s3 = sub_GAME_7F0D1BD0(temp_f12, phi_s3, temp_f12, (((s32) temp_t0->unk4 >> 0x18) & 0xff), (((s32) temp_t0->unk4 >> 0x10) & 0xff), (s32) (((s32) temp_t0->unk4 >> 8) & 0xff), (?32) temp_t0->unk8, (?32) temp_t0->unkC);
                        phi_v0 = temp_s3;
                        phi_s3_5 = temp_s3;
                    }
                    *phi_v0 = 0xe7000000;
                    phi_v0->unk4 = 0;
                    phi_a1_2 = subroutine_arg0;
                    phi_s3_3 = (phi_s3_5 + 8);
                }
            }
            temp_s1 = (phi_s1 + 1);
            *temp_s4_2 = (s32) phi_s2;
            *temp_s5_2 = (u32) temp_v0_2->unk4;
            temp_t9 = (temp_s1 & 0x1f);
            phi_t9 = temp_t9;
            if (temp_s1 < 0)
            {
                phi_t9 = temp_t9;
                if (temp_t9 != 0)
                {
                    phi_t9 = (temp_t9 + -0x20);
                }
            }
            phi_s1 = phi_t9;
            phi_a1 = phi_a1_2;
            phi_s3 = phi_s3_3;
            phi_a1_3 = phi_a1_2;
            phi_s3_2 = phi_s3_3;
            if (phi_t9 != phi_a1_2)
            {
                goto block_10;
            }
        }
        if (spC8 < 2)
        {
            sub_GAME_7F0D2320(phi_a1_3);
        }
        temp_t3 = (spC8 + 1);
        sp70 = (void *) (sp70 + 4);
        sp80 = (s32) (sp80 + 4);
        spC8 = temp_t3;
        phi_s3_4 = phi_s3_2;
        if (temp_t3 != 3)
        {
            goto block_8;
        }
        temp_ret = sub_GAME_7F0D1E98(phi_s3_2, 0, 0, 0);
        *temp_ret = 0xe7000000;
        temp_ret->unk4 = 0;
        temp_ret->unk8 = 0xb8000000;
        temp_ret->unkC = 0;
        displaylist_bank = (s32) (displaylist_bank ^ 1);
        phi_return = temp_ret;
    }
    return phi_return;
}
#else
GLOBAL_ASM(
.text
glabel video_DL_related_4
/* 0038D8 70002CD8 27BDFF30 */  addiu $sp, $sp, -0xd0
/* 0038DC 70002CDC 3C028002 */  lui   $v0, %hi(counterforframes) # $v0, 0x8002
/* 0038E0 70002CE0 3C0E8005 */  lui   $t6, %hi(D_80048498) # $t6, 0x8005
/* 0038E4 70002CE4 8C423230 */  lw    $v0, %lo(counterforframes)($v0)
/* 0038E8 70002CE8 8DCE8498 */  lw    $t6, %lo(D_80048498)($t6)
/* 0038EC 70002CEC 3C018002 */  lui   $at, %hi(counterforframes) # $at, 0x8002
/* 0038F0 70002CF0 AFBF005C */  sw    $ra, 0x5c($sp)
/* 0038F4 70002CF4 004E1021 */  addu  $v0, $v0, $t6
/* 0038F8 70002CF8 AC223230 */  sw    $v0, %lo(counterforframes)($at)
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
/* 003930 70002D30 3C0F8002 */  lui   $t7, %hi(D_80023234) # $t7, 0x8002
/* 003934 70002D34 8DEF3234 */  lw    $t7, %lo(D_80023234)($t7)
/* 003938 70002D38 3C018002 */  lui   $at, %hi(D_80023234) # $at, 0x8002
/* 00393C 70002D3C 2442FF38 */  addiu $v0, $v0, -0xc8
/* 003940 70002D40 39F80001 */  xori  $t8, $t7, 1
/* 003944 70002D44 AC383234 */  sw    $t8, %lo(D_80023234)($at)
/* 003948 70002D48 3C018002 */  lui   $at, %hi(counterforframes) # $at, 0x8002
/* 00394C 70002D4C AC223230 */  sw    $v0, %lo(counterforframes)($at)
.L70002D50:
/* 003950 70002D50 3C038002 */  lui   $v1, %hi(D_8002322C) # $v1, 0x8002
/* 003954 70002D54 8C63322C */  lw    $v1, %lo(D_8002322C)($v1)
/* 003958 70002D58 3C198002 */  lui   $t9, %hi(D_80023234) # $t9, 0x8002
/* 00395C 70002D5C 8F393234 */  lw    $t9, %lo(D_80023234)($t9)
/* 003960 70002D60 30690001 */  andi  $t1, $v1, 1
/* 003964 70002D64 3C018002 */  lui   $at, %hi(D_8002322C) # $at, 0x8002
/* 003968 70002D68 24630001 */  addiu $v1, $v1, 1
/* 00396C 70002D6C 132900AD */  beq   $t9, $t1, .L70003024
/* 003970 70002D70 AC23322C */   sw    $v1, %lo(D_8002322C)($at)
/* 003974 70002D74 3C0A8006 */  lui   $t2, %hi(displaylist_bank) # $t2, 0x8006
/* 003978 70002D78 8D4A04A0 */  lw    $t2, %lo(displaylist_bank)($t2)
/* 00397C 70002D7C 3C0C8006 */  lui   $t4, %hi(displaylist_0) # $t4, 0x8006
/* 003980 70002D80 258CF400 */  addiu $t4, %lo(displaylist_0) # addiu $t4, $t4, -0xc00
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
/* 0039BC 70002DBC 3C048006 */  lui   $a0, %hi(dword_CODE_bss_800604A4) # $a0, 0x8006
/* 0039C0 70002DC0 8C8404A4 */  lw    $a0, %lo(dword_CODE_bss_800604A4)($a0)
/* 0039C4 70002DC4 27B500A0 */  addiu $s5, $sp, 0xa0
/* 0039C8 70002DC8 27A200AC */  addiu $v0, $sp, 0xac
.L70002DCC:
/* 0039CC 70002DCC 26B50004 */  addiu $s5, $s5, 4
/* 0039D0 70002DD0 02A2082B */  sltu  $at, $s5, $v0
/* 0039D4 70002DD4 1420FFFD */  bnez  $at, .L70002DCC
/* 0039D8 70002DD8 AEA4FFFC */   sw    $a0, -4($s5)
/* 0039DC 70002DDC 3C0D8006 */  lui   $t5, %hi(dword_CODE_bss_800607B0) # $t5, 0x8006
/* 0039E0 70002DE0 25AD07B0 */  addiu $t5, %lo(dword_CODE_bss_800607B0) # addiu $t5, $t5, 0x7b0
/* 0039E4 70002DE4 3C1E8006 */  lui   $fp, %hi(dword_CODE_bss_800607D0) # $fp, 0x8006
/* 0039E8 70002DE8 3C018003 */  lui   $at, %hi(aIL0) # $at, 0x8003
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
/* 003A28 70002E28 3C0B8006 */  lui   $t3, %hi(dword_CODE_bss_800604B0) # $t3, 0x8006
/* 003A2C 70002E2C 256B04B0 */  addiu $t3, %lo(dword_CODE_bss_800604B0) # addiu $t3, $t3, 0x4b0
/* 003A30 70002E30 27B900A0 */  addiu $t9, $sp, 0xa0
/* 003A34 70002E34 00095200 */  sll   $t2, $t1, 8
/* 003A38 70002E38 014BB821 */  addu  $s7, $t2, $t3
/* 003A3C 70002E3C 01F9A821 */  addu  $s5, $t7, $t9
.L70002E40:
/* 003A40 70002E40 001160C0 */  sll   $t4, $s1, 3
/* 003A44 70002E44 02EC1021 */  addu  $v0, $s7, $t4
/* 003A48 70002E48 8C520000 */  lw    $s2, ($v0)
/* 003A4C 70002E4C 3C048006 */  lui   $a0, %hi(dword_CODE_bss_800604A4) # $a0, 0x8006
/* 003A50 70002E50 8C8404A4 */  lw    $a0, %lo(dword_CODE_bss_800604A4)($a0)
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
/* 003A8C 70002E8C 3C198002 */   lui   $t9, %hi(D_800231D4) # $t9, 0x8002
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
/* 003BF8 70002FF8 3C038006 */  lui   $v1, %hi(displaylist_bank) # $v1, 0x8006
/* 003BFC 70002FFC 3C0FE700 */  lui   $t7, 0xe700
/* 003C00 70003000 3C19B800 */  lui   $t9, 0xb800
/* 003C04 70003004 246304A0 */  addiu $v1, %lo(displaylist_bank) # addiu $v1, $v1, 0x4a0
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
#endif
