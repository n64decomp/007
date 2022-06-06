#include <ultra64.h>
#include <limits.h>
#include <assets/animationtable_data.h>
#include <random.h>
#include "bondview.h"
#include "chrai.h"
#include "initanitable.h"
#include "lvl.h"
#include "matrixmath.h"
#include "objecthandler.h"
#include "player.h"
#include "bondhead.h"


/**
 * Address 0x80036AD0.
*/
struct init_bond_anim_unk g_BondMoveAnimationSetup[2] = {
    // address 0x80036AD0 = g_BondMoveAnimationSetup + 0
    {PTR_ANIM_bond_eye_walk, 9.5f, 27.0f, 0.0f, 0.0f, 1.5f},
    // address 0x80036AE8 = g_BondMoveAnimationSetup + 24
    {PTR_ANIM_sprinting, 7.5f, 17.0f, 0.0f, 1.5f, 100.0f}
};

/**
 * Address 0x80036B00.
*/
coord3d D_80036B00 = { 0.0f, 0.0f, 0.0f };

/**
 * Address 0x80036B0C.
*/
coord3d D_80036B0C = { 0.0f, 0.0f, 1.0f };

/**
 * Address 0x80036B18.
*/
coord3d D_80036B18 = { 0.0f, 1.0f, 0.0f };

/**
 * Address 0x80036B24.
*/
struct unk_joint_list D_80036B24 = {NULL, 1, 3, NULL, NULL, 0, 0, 0, 0, 0, 0, 0, 0, 0, {0, 0, 0, 0}, 0};

/**
 * Address 0x80036B64.
*/
coord3d D_80036B64 = { 0.0f, 0.0f, 0.0f };





// forward declarations

void bheadUpdatePos(coord3d *vel);
void bheadUpdateRot(coord3d *lookvel, coord3d *upvel);
void bheadSetdamp(f32 headdamp);

// end forward declarations





void bheadFlipAnimation()
{
    g_CurrentPlayer->field_5BC = !g_CurrentPlayer->field_5BC;
}

void bheadUpdateIdleRoll()
{
    f32 mult = 1.0f / UINT_MAX;

	g_CurrentPlayer->standlook[g_CurrentPlayer->standcnt][0] = ((f32)randomGetNext() * mult - 0.5f) * 0.02f;
	g_CurrentPlayer->standlook[g_CurrentPlayer->standcnt][2] = 1;
	g_CurrentPlayer->standup[g_CurrentPlayer->standcnt][0] = ((f32)randomGetNext() * mult - 0.5f) * 0.02f;
	g_CurrentPlayer->standup[g_CurrentPlayer->standcnt][1] = 1;

	if (g_CurrentPlayer->standcnt)
    {
		g_CurrentPlayer->standlook[g_CurrentPlayer->standcnt][1] = (f32)randomGetNext() * mult * 0.01f;
		g_CurrentPlayer->standup[g_CurrentPlayer->standcnt][2] = (f32)randomGetNext() * mult * -0.01f;
	}
    else
    {
		g_CurrentPlayer->standlook[g_CurrentPlayer->standcnt][1] = (f32)randomGetNext() * mult * -0.01f;
		g_CurrentPlayer->standup[g_CurrentPlayer->standcnt][2] = (f32)randomGetNext() * mult * 0.01f;
	}

	g_CurrentPlayer->standcnt = 1 - g_CurrentPlayer->standcnt;
}

void bheadUpdatePos(coord3d *vel)
{
#if defined(VERSION_EU)
#define CURRENTPLAYERUPDATEHEADPOS_SCALE 0.916599988937f
#else
#define CURRENTPLAYERUPDATEHEADPOS_SCALE 0.93f
#endif
    s32 i;

    if (g_CurrentPlayer->resetheadpos)
    {
        g_CurrentPlayer->headpossum[0] = 0.0f;
        g_CurrentPlayer->headpossum[1] = (vel->f[1] / (1.0f - CURRENTPLAYERUPDATEHEADPOS_SCALE));
        g_CurrentPlayer->headpossum[2] = 0.0f;

        g_CurrentPlayer->resetheadpos = FALSE;
    }

    for (i = 0; i < g_ClockTimer; i++)
    {
        g_CurrentPlayer->headpossum[0] = ((CURRENTPLAYERUPDATEHEADPOS_SCALE * g_CurrentPlayer->headpossum[0]) + vel->f[0]);
        g_CurrentPlayer->headpossum[1] = ((CURRENTPLAYERUPDATEHEADPOS_SCALE * g_CurrentPlayer->headpossum[1]) + vel->f[1]);
        g_CurrentPlayer->headpossum[2] = ((CURRENTPLAYERUPDATEHEADPOS_SCALE * g_CurrentPlayer->headpossum[2]) + vel->f[2]);
    }

    g_CurrentPlayer->headpos[0] = (g_CurrentPlayer->headpossum[0] * (1.0f - CURRENTPLAYERUPDATEHEADPOS_SCALE));
    g_CurrentPlayer->headpos[1] = (g_CurrentPlayer->headpossum[1] * (1.0f - CURRENTPLAYERUPDATEHEADPOS_SCALE));
    g_CurrentPlayer->headpos[2] = (g_CurrentPlayer->headpossum[2] * (1.0f - CURRENTPLAYERUPDATEHEADPOS_SCALE));
#undef CURRENTPLAYERUPDATEHEADPOS_SCALE
}

void bheadUpdateRot(coord3d *lookvel, coord3d *upvel)
{
	s32 i;

	if (g_CurrentPlayer->resetheadrot)
    {
		g_CurrentPlayer->headlooksum[0] = lookvel->f[0] / (1.0f - g_CurrentPlayer->headdamp);
		g_CurrentPlayer->headlooksum[1] = lookvel->f[1] / (1.0f - g_CurrentPlayer->headdamp);
		g_CurrentPlayer->headlooksum[2] = lookvel->f[2] / (1.0f - g_CurrentPlayer->headdamp);
		g_CurrentPlayer->headupsum[0] = upvel->f[0] / (1.0f - g_CurrentPlayer->headdamp);
		g_CurrentPlayer->headupsum[1] = upvel->f[1] / (1.0f - g_CurrentPlayer->headdamp);
		g_CurrentPlayer->headupsum[2] = upvel->f[2] / (1.0f - g_CurrentPlayer->headdamp);

		g_CurrentPlayer->resetheadrot = FALSE;
	}

	for (i = 0; i < g_ClockTimer; i++)
    {
		g_CurrentPlayer->headlooksum[0] = g_CurrentPlayer->headdamp * g_CurrentPlayer->headlooksum[0] + lookvel->f[0];
		g_CurrentPlayer->headlooksum[1] = g_CurrentPlayer->headdamp * g_CurrentPlayer->headlooksum[1] + lookvel->f[1];
		g_CurrentPlayer->headlooksum[2] = g_CurrentPlayer->headdamp * g_CurrentPlayer->headlooksum[2] + lookvel->f[2];
		g_CurrentPlayer->headupsum[0] = g_CurrentPlayer->headdamp * g_CurrentPlayer->headupsum[0] + upvel->f[0];
		g_CurrentPlayer->headupsum[1] = g_CurrentPlayer->headdamp * g_CurrentPlayer->headupsum[1] + upvel->f[1];
		g_CurrentPlayer->headupsum[2] = g_CurrentPlayer->headdamp * g_CurrentPlayer->headupsum[2] + upvel->f[2];
	}

	g_CurrentPlayer->headlook[0] = g_CurrentPlayer->headlooksum[0] * (1.0f - g_CurrentPlayer->headdamp);
	g_CurrentPlayer->headlook[1] = g_CurrentPlayer->headlooksum[1] * (1.0f - g_CurrentPlayer->headdamp);
	g_CurrentPlayer->headlook[2] = g_CurrentPlayer->headlooksum[2] * (1.0f - g_CurrentPlayer->headdamp);
	g_CurrentPlayer->headup[0] = g_CurrentPlayer->headupsum[0] * (1.0f - g_CurrentPlayer->headdamp);
	g_CurrentPlayer->headup[1] = g_CurrentPlayer->headupsum[1] * (1.0f - g_CurrentPlayer->headdamp);
	g_CurrentPlayer->headup[2] = g_CurrentPlayer->headupsum[2] * (1.0f - g_CurrentPlayer->headdamp);
}

void bheadSetdamp(f32 headdamp)
{
	if (headdamp != g_CurrentPlayer->headdamp)
    {
		f32 divisor = 1.0f - headdamp;
		g_CurrentPlayer->headlooksum[0] = (g_CurrentPlayer->headlooksum[0] * (1.0f - g_CurrentPlayer->headdamp)) / divisor;
		g_CurrentPlayer->headlooksum[1] = (g_CurrentPlayer->headlooksum[1] * (1.0f - g_CurrentPlayer->headdamp)) / divisor;
		g_CurrentPlayer->headlooksum[2] = (g_CurrentPlayer->headlooksum[2] * (1.0f - g_CurrentPlayer->headdamp)) / divisor;
		g_CurrentPlayer->headupsum[0] = (g_CurrentPlayer->headupsum[0] * (1.0f - g_CurrentPlayer->headdamp)) / divisor;
		g_CurrentPlayer->headupsum[1] = (g_CurrentPlayer->headupsum[1] * (1.0f - g_CurrentPlayer->headdamp)) / divisor;
		g_CurrentPlayer->headupsum[2] = (g_CurrentPlayer->headupsum[2] * (1.0f - g_CurrentPlayer->headdamp)) / divisor;
		g_CurrentPlayer->headdamp = headdamp;
	}
}

void bheadUpdate(f32 arg0, f32 arg1)
{
    coord3d headpos;
    coord3d lookvel;
    coord3d upvel;
    f32 spC0;
    struct unk_joint_list sp80;
    Mtxf sp40;
    coord3d sp34;
    u32 sp30;

    headpos = D_80036B00;
    lookvel = D_80036B0C;
    upvel = D_80036B18;

    spC0 = modelGetAbsAnimSpeed(&g_CurrentPlayer->model);

    if (g_CurrentPlayer->headanim == 0)
    {
        if (spC0 > 0.7f)
        {
            g_CurrentPlayer->headamplitude = 1.0f;
        }
        else if (spC0 > 0.1f)
        {
            g_CurrentPlayer->headamplitude = (((spC0 - 0.1f) * 0.6f) / 0.59999996f) + 0.4f;
        }
        else
        {
            g_CurrentPlayer->headamplitude = 0.4f;
        }

        g_CurrentPlayer->sideamplitude = g_CurrentPlayer->headamplitude;
    }
    else if (g_CurrentPlayer->headanim == 1)
    {
        g_CurrentPlayer->headamplitude = 0.9f;
        g_CurrentPlayer->sideamplitude = 0.5f;
    }
    else
    {
        g_CurrentPlayer->headamplitude = 1.0f;
        g_CurrentPlayer->sideamplitude = g_CurrentPlayer->headamplitude;
    }

    sp80 = D_80036B24;

    sp34 = D_80036B64;

    sp30 = sub_GAME_7F0701E0();

    g_CurrentPlayer->resetheadtick = 0;

    sub_GAME_7F0701D4(0);
    sub_GAME_7F070AEC(&g_CurrentPlayer->model, g_ClockTimer, 1);
    sub_GAME_7F0701D4((s32) sp30);

    subcalcpos(&g_CurrentPlayer->model);
    matrix_4x4_set_identity(&sp40);

    sp80.unk_matrix = &sp40;
    sp80.mtxlist = &g_CurrentPlayer->field_6D0;

    subcalcmatrices(&sp80, &g_CurrentPlayer->model);

    g_CurrentPlayer->headbodyoffset[0] = g_CurrentPlayer->standbodyoffset.x;
    g_CurrentPlayer->headbodyoffset[1] = g_CurrentPlayer->standbodyoffset.y;
    g_CurrentPlayer->headbodyoffset[2] = g_CurrentPlayer->standbodyoffset.z;

    getsuboffset(&g_CurrentPlayer->model, (struct float3 *) &sp34);

    sp34.f[0] -= g_CurrentPlayer->field_700;
    sp34.f[2] -= g_CurrentPlayer->field_708;
    
    setsuboffset(&g_CurrentPlayer->model, (coord3d *) &sp34);

    if (spC0 > 0.0f)
    {
        g_CurrentPlayer->field_700 += arg1;
        g_CurrentPlayer->field_708 *= arg0;

        if (g_ClockTimer > 0)
        {
            g_CurrentPlayer->field_700 /= g_GlobalTimerDelta;
            g_CurrentPlayer->field_708 /= g_GlobalTimerDelta;
        }

        headpos.f[0] = g_CurrentPlayer->field_700 * g_CurrentPlayer->headamplitude;
        headpos.f[1] = ((g_CurrentPlayer->field_704 - g_CurrentPlayer->standheight) * g_CurrentPlayer->headamplitude) + g_CurrentPlayer->standheight;
        headpos.f[2] = g_CurrentPlayer->field_708 * g_CurrentPlayer->headamplitude;

        if (g_CurrentPlayer->headanim >= 0)
        {
            lookvel.f[0] = g_CurrentPlayer->field_6F0 * g_CurrentPlayer->sideamplitude;
            lookvel.f[1] = g_CurrentPlayer->field_6F4 * g_CurrentPlayer->headamplitude;
            lookvel.f[2] = ((g_CurrentPlayer->field_6F8 - 1.0f) * g_CurrentPlayer->headamplitude) + 1.0f;

            upvel.f[0] = g_CurrentPlayer->field_6E0 * g_CurrentPlayer->headamplitude;
            upvel.f[1] = ((g_CurrentPlayer->field_6E4 - 1.0f) * g_CurrentPlayer->headamplitude) + 1.0f;
            upvel.f[2] = g_CurrentPlayer->field_6E8 * g_CurrentPlayer->headamplitude;

            g_CurrentPlayer->headwalkingtime60 += g_ClockTimer;

#if defined(VERSION_EU)
            if (g_CurrentPlayer->headwalkingtime60 >= 0x33)
            {
                bheadSetdamp(0.916599988937f);
            }
            else
            {
                bheadSetdamp(0.987999975681f);
            }
#else
            if (g_CurrentPlayer->headwalkingtime60 >= 0x3D)
            {
                bheadSetdamp(0.93f);
            }
            else
            {
                bheadSetdamp(0.99f);
            }
#endif
        }
        else
        {
            lookvel.f[0] = g_CurrentPlayer->field_6F0;
            lookvel.f[1] = g_CurrentPlayer->field_6F4;
            lookvel.f[2] = g_CurrentPlayer->field_6F8;

            upvel.f[0] = g_CurrentPlayer->field_6E0;
            upvel.f[1] = g_CurrentPlayer->field_6E4;
            upvel.f[2] = g_CurrentPlayer->field_6E8;

            bheadSetdamp(0.85f);
        }
    }
    else
    {
        g_CurrentPlayer->headbodyoffset[0] = g_CurrentPlayer->standbodyoffset.x;
        g_CurrentPlayer->headbodyoffset[1] = g_CurrentPlayer->standbodyoffset.y;
        g_CurrentPlayer->headbodyoffset[2] = g_CurrentPlayer->standbodyoffset.z;

        headpos.f[0] = 0.0f;
        headpos.f[1] = g_CurrentPlayer->standheight;
        headpos.f[2] = 0.0f;

        g_CurrentPlayer->headwalkingtime60 = 0;
#if defined(VERSION_EU)
        bheadSetdamp(0.987999975681f);
#else
        bheadSetdamp(0.99f);
#endif
        g_CurrentPlayer->standfrac += (0.008333334f + (0.025000002f * bondviewGetBondBreathing())) * g_GlobalTimerDelta;

        if (g_CurrentPlayer->standfrac >= 1.0f)
        {
            bheadUpdateIdleRoll();
            g_CurrentPlayer->standfrac -= 1.0f;
        }

        sub_GAME_7F05AE00(
            &g_CurrentPlayer->standlook[g_CurrentPlayer->standcnt][0],
            &g_CurrentPlayer->standlook[1 - g_CurrentPlayer->standcnt][0],
            g_CurrentPlayer->standfrac,
            &lookvel);

        lookvel.f[0] *= (1.0f + (5.0f * bondviewGetBondBreathing()));
        lookvel.f[1] *= (1.0f + (5.0f * bondviewGetBondBreathing()));

        sub_GAME_7F05AE00(
            &g_CurrentPlayer->standup[g_CurrentPlayer->standcnt][0],
            &g_CurrentPlayer->standup[1 - g_CurrentPlayer->standcnt][0],
            g_CurrentPlayer->standfrac,
            &upvel);

        upvel.f[0] *= (1.0f + (5.0f * bondviewGetBondBreathing()));
        upvel.f[2] *= (1.0f + (5.0f * bondviewGetBondBreathing()));
    }

    bheadUpdatePos(&headpos);
    bheadUpdateRot(&lookvel, &upvel);
}



/**
 * Address 0x7F08E8BC.
*/
void bheadAdjustAnimation(f32 speed)
{
    s32 i;
    f32 startframe;
    
    speed *= g_BondMoveAnimationSetup[1].unk0C;

    for (i=0; i<2; i++)
    {
        if (speed <= g_BondMoveAnimationSetup[i].unk14 * g_BondMoveAnimationSetup[i].unk0C)
        {
            if (i != g_CurrentPlayer->headanim)
            {
                startframe = 0.0f;

                if (g_CurrentPlayer->headanim >= 0)
                {
                    startframe = (g_CurrentPlayer->field_5C0 - g_BondMoveAnimationSetup[g_CurrentPlayer->headanim].unk04)
                        / (g_BondMoveAnimationSetup[g_CurrentPlayer->headanim].unk08 - g_BondMoveAnimationSetup[g_CurrentPlayer->headanim].unk04);

                    startframe = g_BondMoveAnimationSetup[i].unk04 + ((g_BondMoveAnimationSetup[i].unk08 - g_BondMoveAnimationSetup[i].unk04) * startframe);
                }

                modelSetAnimation(
                    &g_CurrentPlayer->model,
                    // match hack: addu address backwards
                    (struct ModelAnimation *) ((s32)g_BondMoveAnimationSetup[i].anim_id + (s32)&ptr_animation_table->data),
                    (s32) g_CurrentPlayer->field_5BC,
                    startframe,
                    0.5f,
                    12.0f);

                modelSetAnimLooping(&g_CurrentPlayer->model, g_BondMoveAnimationSetup[i].unk04, 0.0f);
                modelSetAnimEndFrame(&g_CurrentPlayer->model, g_BondMoveAnimationSetup[i].unk08);
                modelSetAnimFlipFunction(&g_CurrentPlayer->model, bheadFlipAnimation);
                g_CurrentPlayer->headanim = i;
            }

            speed /= g_BondMoveAnimationSetup[i].unk0C;

            modelSetAnimSpeed(&g_CurrentPlayer->model, speed * 0.5f, 0.0f);
            return;
        }
    }
}





/**
 * Address 0x7F08EA48.
*/
void bheadStartDeathAnimation(struct ModelAnimation *animnum, s32 flip, f32 fstarttime, f32 speed)
{
    modelSetAnimation(&g_CurrentPlayer->model, animnum, flip, fstarttime, speed * 0.5f, 12.0f);
    g_CurrentPlayer->headanim = -1;
}






/**
 * Address 0x7F08EAB8.
*/
void bheadSetSpeed(f32 speed)
{
    modelSetAnimSpeed(&g_CurrentPlayer->model, speed * 0.5f, 0.0f);
}




#ifdef NONMATCHING
f32 bheadGetBreathingValue(void) {

}
#else
GLOBAL_ASM(
.late_rodata
glabel D_80055338
.word 0x3c4cccce /*0.012500001*/
glabel D_8005533C
.word 0x3b888889 /*0.0041666669*/
.text
glabel bheadGetBreathingValue
/* 0C3628 7F08EAF8 3C0E8008 */  lui   $t6, %hi(g_CurrentPlayer) 
/* 0C362C 7F08EAFC 8DCEA0B0 */  lw    $t6, %lo(g_CurrentPlayer)($t6)
/* 0C3630 7F08EB00 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0C3634 7F08EB04 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0C3638 7F08EB08 8DCF04E8 */  lw    $t7, 0x4e8($t6)
/* 0C363C 7F08EB0C 05E2002B */  bltzl $t7, .L7F08EBBC
/* 0C3640 7F08EB10 44800000 */   mtc1  $zero, $f0
/* 0C3644 7F08EB14 0FC227B5 */  jal   bondviewGetBondBreathing
/* 0C3648 7F08EB18 00000000 */   nop   
/* 0C364C 7F08EB1C 3C018005 */  lui   $at, %hi(D_80055338)
/* 0C3650 7F08EB20 C4245338 */  lwc1  $f4, %lo(D_80055338)($at)
/* 0C3654 7F08EB24 3C018005 */  lui   $at, %hi(D_8005533C)
/* 0C3658 7F08EB28 C428533C */  lwc1  $f8, %lo(D_8005533C)($at)
/* 0C365C 7F08EB2C 46040182 */  mul.s $f6, $f0, $f4
/* 0C3660 7F08EB30 3C048008 */  lui   $a0, %hi(g_CurrentPlayer)
/* 0C3664 7F08EB34 8C84A0B0 */  lw    $a0, %lo(g_CurrentPlayer)($a0)
/* 0C3668 7F08EB38 24840598 */  addiu $a0, $a0, 0x598
/* 0C366C 7F08EB3C 46083080 */  add.s $f2, $f6, $f8
/* 0C3670 7F08EB40 0FC1BD86 */  jal   modelGetAbsAnimSpeed
/* 0C3674 7F08EB44 E7A2001C */   swc1  $f2, 0x1c($sp)
/* 0C3678 7F08EB48 44805000 */  mtc1  $zero, $f10
/* 0C367C 7F08EB4C C7A2001C */  lwc1  $f2, 0x1c($sp)
/* 0C3680 7F08EB50 3C188008 */  lui   $t8, %hi(g_CurrentPlayer) 
/* 0C3684 7F08EB54 4600503C */  c.lt.s $f10, $f0
/* 0C3688 7F08EB58 00000000 */  nop   
/* 0C368C 7F08EB5C 45000014 */  bc1f  .L7F08EBB0
/* 0C3690 7F08EB60 00000000 */   nop   
/* 0C3694 7F08EB64 8F18A0B0 */  lw    $t8, %lo(g_CurrentPlayer)($t8)
/* 0C3698 7F08EB68 3C098003 */  lui   $t1, %hi(g_BondMoveAnimationSetup) 
/* 0C369C 7F08EB6C 25296AD0 */  addiu $t1, %lo(g_BondMoveAnimationSetup) # addiu $t1, $t1, 0x6ad0
/* 0C36A0 7F08EB70 8F1904E8 */  lw    $t9, 0x4e8($t8)
/* 0C36A4 7F08EB74 00194080 */  sll   $t0, $t9, 2
/* 0C36A8 7F08EB78 01194023 */  subu  $t0, $t0, $t9
/* 0C36AC 7F08EB7C 000840C0 */  sll   $t0, $t0, 3
/* 0C36B0 7F08EB80 01091021 */  addu  $v0, $t0, $t1
/* 0C36B4 7F08EB84 C4500008 */  lwc1  $f16, 8($v0)
/* 0C36B8 7F08EB88 C4520004 */  lwc1  $f18, 4($v0)
/* 0C36BC 7F08EB8C 46128101 */  sub.s $f4, $f16, $f18
/* 0C36C0 7F08EB90 46040303 */  div.s $f12, $f0, $f4
/* 0C36C4 7F08EB94 4602603C */  c.lt.s $f12, $f2
/* 0C36C8 7F08EB98 00000000 */  nop   
/* 0C36CC 7F08EB9C 45000002 */  bc1f  .L7F08EBA8
/* 0C36D0 7F08EBA0 00000000 */   nop   
/* 0C36D4 7F08EBA4 46001306 */  mov.s $f12, $f2
.L7F08EBA8:
/* 0C36D8 7F08EBA8 10000005 */  b     .L7F08EBC0
/* 0C36DC 7F08EBAC 46006006 */   mov.s $f0, $f12
.L7F08EBB0:
/* 0C36E0 7F08EBB0 10000003 */  b     .L7F08EBC0
/* 0C36E4 7F08EBB4 46001006 */   mov.s $f0, $f2
/* 0C36E8 7F08EBB8 44800000 */  mtc1  $zero, $f0
.L7F08EBBC:
/* 0C36EC 7F08EBBC 00000000 */  nop   
.L7F08EBC0:
/* 0C36F0 7F08EBC0 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0C36F4 7F08EBC4 27BD0020 */  addiu $sp, $sp, 0x20
/* 0C36F8 7F08EBC8 03E00008 */  jr    $ra
/* 0C36FC 7F08EBCC 00000000 */   nop   
)
#endif






