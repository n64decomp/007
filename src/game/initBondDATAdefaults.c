#include <ultra64.h>
#include <math.h>
#include <bondtypes.h>
#include "chr.h"
#include "chrobjdata.h"
#include "initanitable.h"
#include "initBondDATAdefaults.h"
#include "objecthandler.h"
#include "player.h"
#include "bondhead.h"


//data
struct unk_joint_list D_8002A790 = {NULL, 1, 3, NULL, NULL, 0, 0, 0, 0, 0, 0, 0, 0, 0, {0, 0, 0, 0}, 0};

// forward declarations

void sub_GAME_7F0062C0(void *anim, s32 arg1, s32 arg2, s32 *arg3);

// end forward declarations





/**
 * @param anim:
 * @param arg1:
 * @param arg2:
 * @param arg3: unknown type.
 * 
 * Address 0x7F0062C0.
*/
void sub_GAME_7F0062C0(void *anim, s32 arg1, s32 arg2, s32 *arg3)
{
    // todo: is this a struct? see: sub_GAME_7F06D2E4
    s16 sp40[6];

    arg3[0] = 0;
    arg3[1] = 0;
    arg3[2] = 0;

    for (; arg1<arg2; arg1++)
    {
        sub_GAME_7F06D2E4(0, 0, &skeleton_guard, anim, arg1, &sp40[2]);
        arg3[0] += sp40[2];
        arg3[1] += sp40[3];
        arg3[2] += sp40[4];
    }
}



#ifdef REFRESH_PAL
#define ANIMRATE 1.2f
#define DAMPVAL 0.9166f
#define HEADSUM 11.990406f
#else
#define ANIMRATE 1.0f
#define DAMPVAL 0.93f
#define HEADSUM 14.285716f
#endif


void sets_a_bunch_of_BONDdata_values_to_default(void)
{
    s32 i;
    s32 spD0[3];
    struct unk_joint_list sp90;
    Mtxf sp50;

#ifdef LEFTOVERDEBUG
    if ((s32) player_gait_object_header.numRecords >= 0x1F)
    {
        return_null();
    }
#endif

    sub_GAME_7F075FAC(&g_CurrentPlayer->model, &player_gait_object_header, &g_CurrentPlayer->field_654);
    modelSetScale(&g_CurrentPlayer->model, IDO_POINT_ONE);

#if defined (BUGFIX_R1)
    modelSetAnimRateForDuration(&g_CurrentPlayer->model, ANIMRATE, 0.0f);
#endif

    g_CurrentPlayer->headanim = 0;

    g_CurrentPlayer->headdamp = DAMPVAL;

    g_CurrentPlayer->headwalkingtime60 = 0;
    g_CurrentPlayer->headamplitude = 1.0f;
    g_CurrentPlayer->sideamplitude = 1.0f;
    g_CurrentPlayer->headpos[0] = 0.0f;
    g_CurrentPlayer->headpos[1] = 0.0f;
    g_CurrentPlayer->headpos[2] = 0.0f;
    g_CurrentPlayer->headlook[0] = 0.0f;
    g_CurrentPlayer->headlook[1] = 0.0f;
    g_CurrentPlayer->headlook[2] = 0.0f;
    g_CurrentPlayer->headup[0] = 0.0f;
    g_CurrentPlayer->headup[1] = 0.0f;
    g_CurrentPlayer->headup[2] = 0.0f;
    g_CurrentPlayer->headpossum[0] = 0.0f;
    g_CurrentPlayer->headpossum[1] = 0.0f;
    g_CurrentPlayer->headpossum[2] = 0.0f;
    g_CurrentPlayer->headlooksum[0] = 0.0f;
    g_CurrentPlayer->headlooksum[1] = 0.0f;


    g_CurrentPlayer->headlooksum[2] = HEADSUM;


    g_CurrentPlayer->headupsum[0] = 0.0f;


    g_CurrentPlayer->headupsum[1] = HEADSUM;


    g_CurrentPlayer->headupsum[2] = 0.0f;
    g_CurrentPlayer->resetheadpos = 1;
    g_CurrentPlayer->resetheadrot = 1;
    g_CurrentPlayer->resetheadtick = 1;
    g_CurrentPlayer->headbodyoffset[0] = 0.0f;
    g_CurrentPlayer->headbodyoffset[1] = 0.0f;
    g_CurrentPlayer->headbodyoffset[2] = 0.0f;
    g_CurrentPlayer->standheight = 0.0f;
    g_CurrentPlayer->standbodyoffset.x = 0.0f;
    g_CurrentPlayer->standbodyoffset.y = 0.0f;
    g_CurrentPlayer->standbodyoffset.z = 0.0f;
    g_CurrentPlayer->standfrac = 0.0f;
    g_CurrentPlayer->standlook[0][0] = 0.0f;
    g_CurrentPlayer->standlook[0][1] = 0.0f;
    g_CurrentPlayer->standlook[0][2] = 1.0f;
    g_CurrentPlayer->standlook[1][0] = 0.0f;
    g_CurrentPlayer->standlook[1][1] = 0.0f;
    g_CurrentPlayer->standlook[1][2] = 1.0f;
    g_CurrentPlayer->standup[0][0] = 0.0f;
    g_CurrentPlayer->standup[0][1] = 1.0f;
    g_CurrentPlayer->standup[0][2] = 0.0f;
    g_CurrentPlayer->standup[1][0] = 0.0f;
    g_CurrentPlayer->standup[1][1] = 1.0f;
    g_CurrentPlayer->standup[1][2] = 0.0f;
    g_CurrentPlayer->standcnt = 0;

    for (i=0; i<2; i++)
    {
        sub_GAME_7F0062C0(
            // match hack: addu address calculated backwards
            (void*)((s32)g_BondMoveAnimationSetup[i].anim_id + (s32)&ptr_animation_table->data),
            (s32)g_BondMoveAnimationSetup[i].loopframe,
            (s32)g_BondMoveAnimationSetup[i].endframe,
            &spD0);

        g_BondMoveAnimationSetup[i].unk0C = (f32) (((f32) spD0[2] * IDO_POINT_ONE) / (g_BondMoveAnimationSetup[i].endframe - g_BondMoveAnimationSetup[i].loopframe));
    }

    sp90 = D_8002A790;

    modelSetAnimation(&g_CurrentPlayer->model, (struct ModelAnimation *)&ptr_animation_table->data[(s32)&ANIM_DATA_idle], 0, 0.0f, 0.5f, 0.0f);

    subcalcpos(&g_CurrentPlayer->model);
    matrix_4x4_set_identity(&sp50);

    sp90.unk_matrix = &sp50;
    sp90.mtxlist = &g_CurrentPlayer->bondheadmatrices[0];

    subcalcmatrices(&sp90, &g_CurrentPlayer->model);

    g_CurrentPlayer->standheight = g_CurrentPlayer->bondheadmatrices[0].m[3][1];
    g_CurrentPlayer->standbodyoffset.x = 0.0f;
    g_CurrentPlayer->standbodyoffset.y = g_CurrentPlayer->bondheadmatrices[1].m[3][1] - g_CurrentPlayer->bondheadmatrices[0].m[3][1];
    g_CurrentPlayer->standbodyoffset.z = g_CurrentPlayer->bondheadmatrices[1].m[3][2] - g_CurrentPlayer->bondheadmatrices[0].m[3][2];

    modelSetAnimation(
        &g_CurrentPlayer->model,
        // match hack: addu address calculated backwards
        (struct ModelAnimation *) ((s32)g_BondMoveAnimationSetup[g_CurrentPlayer->headanim].anim_id + (s32)&ptr_animation_table->data),
        0,
        g_BondMoveAnimationSetup[g_CurrentPlayer->headanim].loopframe,
        0.5f,
        0.0f);

    modelSetAnimLooping(&g_CurrentPlayer->model, g_BondMoveAnimationSetup[g_CurrentPlayer->headanim].loopframe, 0.0f);
    modelSetAnimEndFrame(&g_CurrentPlayer->model, g_BondMoveAnimationSetup[g_CurrentPlayer->headanim].endframe);
    modelSetAnimFlipFunction(&g_CurrentPlayer->model, bheadFlipAnimation);

    bheadUpdateIdleRoll();
}
