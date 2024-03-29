#include <ultra64.h>
#include <memp.h>
#include "stan.h"
#include "chrai.h"
#include "chrlv.h"
#include "chrobjhandler.h"
#include "game/mp_weapon.h"
#include "game/player_2.h"
#include "loadobjectmodel.h"
#include "math_atan2f.h"
#include "matrixmath.h"
#include "objecthandler.h"
#include "prop.h"
#include "bg.h"
#include "limits.h"

/**
 * EU .bss 0x80068480
*/
ITEM_IDS lastmpweaponnum;

//.section .rodata

const char aNochr[] = "-nochr";
const char aNoprop[] = "-noprop";
const char aNoobj[] = "-noobj";
const char aNoprop_0[] = "-noprop";

const u32 only_read_by_stageload[] = {
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};

const char aMp_[] = "mp_";


void sub_GAME_7F001BD4(struct BoundPadRecord *pad, struct coord3d *arg1);
void sub_GAME_7F00324C(struct BoundPadRecord *arg0, s32 *arg1, s32 *arg2, struct coord3d *arg3, struct coord3d *arg4);


s32 load_proptype(PROPDEF_TYPE type)
{
    PropDefHeaderRecord *propdef = (PropDefHeaderRecord *) g_CurrentSetup.propDefs;
    s32 count = 0;



    if (propdef != NULL)
    {
        while (propdef->type != PROPDEF_END)
        {
            if (propdef->type == (type & 0xFF))
            {
                count ++;
            }
            propdef = &propdef[sizepropdef((PropDefHeaderRecord* ) propdef)];
        }
    }
    return count;
}



#ifdef NONMATCHING

// decomp.me 72% https://decomp.me/scratch/ygs4O

// perfect dark padGetCentre (pad.c)
void sub_GAME_7F001BD4(struct pad3d *pad, struct coord3d *arg1)
{
    f32 temp_f12;
    f32 temp_f14;
    f32 temp_f16;

    struct coord3d normal;
    f32 scale;

    normal.f[0] = (pad->up.f[1] * pad->look.f[2]) - (pad->look.f[1] * pad->up.f[2]);
    normal.f[1] = (pad->up.f[2] * pad->look.f[0]) - (pad->look.f[2] * pad->up.f[0]);
    normal.f[2] = (pad->up.f[0] * pad->look.f[1]) - (pad->look.f[0] * pad->up.f[1]);

    scale = 1.0f / sqrtf((normal.f[0] * normal.f[0]) + ((normal.f[1] * normal.f[1]) + (normal.f[2] * normal.f[2])));

    normal.f[0] *= scale;
    normal.f[1] *= scale;
    normal.f[2] *= scale;

    temp_f16 = pad->bbox.xmin + pad->bbox.xmax;
    temp_f14 = pad->bbox.ymin + pad->bbox.ymax;
    temp_f12 = pad->bbox.zmin + pad->bbox.zmax;

    arg1->f[0] = pad->pos.f[0] + (
			(temp_f16) * normal.f[0] +
			(temp_f14) * pad->up.f[0] +
			(temp_f12) * pad->look.f[0]) * 0.5f;

	arg1->f[1] = pad->pos.f[1] + (
			(temp_f16) * normal.f[1] +
			(temp_f14) * pad->up.f[1] +
			(temp_f12) * pad->look.f[1]) * 0.5f;

	arg1->f[2] = pad->pos.f[2] + (
			(temp_f16) * normal.f[2] +
			(temp_f14) * pad->up.f[2] +
			(temp_f12) * pad->look.f[2]) * 0.5f;

}

#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F001BD4
/* 036704 7F001BD4 27BDFFB8 */  addiu $sp, $sp, -0x48
/* 036708 7F001BD8 AFBF0014 */  sw    $ra, 0x14($sp)
/* 03670C 7F001BDC C484002C */  lwc1  $f4, 0x2c($a0)
/* 036710 7F001BE0 E7A40034 */  swc1  $f4, 0x34($sp)
/* 036714 7F001BE4 C4860030 */  lwc1  $f6, 0x30($a0)
/* 036718 7F001BE8 E7A60030 */  swc1  $f6, 0x30($sp)
/* 03671C 7F001BEC C48A0034 */  lwc1  $f10, 0x34($a0)
/* 036720 7F001BF0 E7AA002C */  swc1  $f10, 0x2c($sp)
/* 036724 7F001BF4 C4880038 */  lwc1  $f8, 0x38($a0)
/* 036728 7F001BF8 E7A80028 */  swc1  $f8, 0x28($sp)
/* 03672C 7F001BFC C484003C */  lwc1  $f4, 0x3c($a0)
/* 036730 7F001C00 E7A40024 */  swc1  $f4, 0x24($sp)
/* 036734 7F001C04 C4860040 */  lwc1  $f6, 0x40($a0)
/* 036738 7F001C08 E7A60020 */  swc1  $f6, 0x20($sp)
/* 03673C 7F001C0C C48A0010 */  lwc1  $f10, 0x10($a0)
/* 036740 7F001C10 C4880020 */  lwc1  $f8, 0x20($a0)
/* 036744 7F001C14 C486001C */  lwc1  $f6, 0x1c($a0)
/* 036748 7F001C18 46085102 */  mul.s $f4, $f10, $f8
/* 03674C 7F001C1C C48A0014 */  lwc1  $f10, 0x14($a0)
/* 036750 7F001C20 460A3202 */  mul.s $f8, $f6, $f10
/* 036754 7F001C24 46082181 */  sub.s $f6, $f4, $f8
/* 036758 7F001C28 E7A6003C */  swc1  $f6, 0x3c($sp)
/* 03675C 7F001C2C C4840018 */  lwc1  $f4, 0x18($a0)
/* 036760 7F001C30 C48A0014 */  lwc1  $f10, 0x14($a0)
/* 036764 7F001C34 46045202 */  mul.s $f8, $f10, $f4
/* 036768 7F001C38 C484000C */  lwc1  $f4, 0xc($a0)
/* 03676C 7F001C3C C48A0020 */  lwc1  $f10, 0x20($a0)
/* 036770 7F001C40 46045282 */  mul.s $f10, $f10, $f4
/* 036774 7F001C44 460A4101 */  sub.s $f4, $f8, $f10
/* 036778 7F001C48 E7A40040 */  swc1  $f4, 0x40($sp)
/* 03677C 7F001C4C C48A001C */  lwc1  $f10, 0x1c($a0)
/* 036780 7F001C50 C488000C */  lwc1  $f8, 0xc($a0)
/* 036784 7F001C54 460A4202 */  mul.s $f8, $f8, $f10
/* 036788 7F001C58 C48A0018 */  lwc1  $f10, 0x18($a0)
/* 03678C 7F001C5C E7A60018 */  swc1  $f6, 0x18($sp)
/* 036790 7F001C60 C4860010 */  lwc1  $f6, 0x10($a0)
/* 036794 7F001C64 AFA5004C */  sw    $a1, 0x4c($sp)
/* 036798 7F001C68 AFA40048 */  sw    $a0, 0x48($sp)
/* 03679C 7F001C6C 46065282 */  mul.s $f10, $f10, $f6
/* 0367A0 7F001C70 460A4181 */  sub.s $f6, $f8, $f10
/* 0367A4 7F001C74 C7A80018 */  lwc1  $f8, 0x18($sp)
/* 0367A8 7F001C78 46084282 */  mul.s $f10, $f8, $f8
/* 0367AC 7F001C7C E7A60044 */  swc1  $f6, 0x44($sp)
/* 0367B0 7F001C80 46042202 */  mul.s $f8, $f4, $f4
/* 0367B4 7F001C84 46085100 */  add.s $f4, $f10, $f8
/* 0367B8 7F001C88 46063282 */  mul.s $f10, $f6, $f6
/* 0367BC 7F001C8C 0C007DF8 */  jal   sqrtf
/* 0367C0 7F001C90 46045300 */   add.s $f12, $f10, $f4
/* 0367C4 7F001C94 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 0367C8 7F001C98 44819000 */  mtc1  $at, $f18
/* 0367CC 7F001C9C 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0367D0 7F001CA0 44814000 */  mtc1  $at, $f8
/* 0367D4 7F001CA4 C7A6003C */  lwc1  $f6, 0x3c($sp)
/* 0367D8 7F001CA8 C7A40040 */  lwc1  $f4, 0x40($sp)
/* 0367DC 7F001CAC 46004083 */  div.s $f2, $f8, $f0
/* 0367E0 7F001CB0 8FA40048 */  lw    $a0, 0x48($sp)
/* 0367E4 7F001CB4 8FA5004C */  lw    $a1, 0x4c($sp)
/* 0367E8 7F001CB8 46023282 */  mul.s $f10, $f6, $f2
/* 0367EC 7F001CBC C7A60044 */  lwc1  $f6, 0x44($sp)
/* 0367F0 7F001CC0 46022202 */  mul.s $f8, $f4, $f2
/* 0367F4 7F001CC4 E7AA003C */  swc1  $f10, 0x3c($sp)
/* 0367F8 7F001CC8 46023102 */  mul.s $f4, $f6, $f2
/* 0367FC 7F001CCC C7A60020 */  lwc1  $f6, 0x20($sp)
/* 036800 7F001CD0 E7A80040 */  swc1  $f8, 0x40($sp)
/* 036804 7F001CD4 C7A80024 */  lwc1  $f8, 0x24($sp)
/* 036808 7F001CD8 46064300 */  add.s $f12, $f8, $f6
/* 03680C 7F001CDC E7A40044 */  swc1  $f4, 0x44($sp)
/* 036810 7F001CE0 C7A40034 */  lwc1  $f4, 0x34($sp)
/* 036814 7F001CE4 C7A80030 */  lwc1  $f8, 0x30($sp)
/* 036818 7F001CE8 C7A6002C */  lwc1  $f6, 0x2c($sp)
/* 03681C 7F001CEC 46082380 */  add.s $f14, $f4, $f8
/* 036820 7F001CF0 C7A40028 */  lwc1  $f4, 0x28($sp)
/* 036824 7F001CF4 46043400 */  add.s $f16, $f6, $f4
/* 036828 7F001CF8 460A7202 */  mul.s $f8, $f14, $f10
/* 03682C 7F001CFC C486000C */  lwc1  $f6, 0xc($a0)
/* 036830 7F001D00 46068102 */  mul.s $f4, $f16, $f6
/* 036834 7F001D04 C4860018 */  lwc1  $f6, 0x18($a0)
/* 036838 7F001D08 46044280 */  add.s $f10, $f8, $f4
/* 03683C 7F001D0C 460C3202 */  mul.s $f8, $f6, $f12
/* 036840 7F001D10 460A4100 */  add.s $f4, $f8, $f10
/* 036844 7F001D14 C4880000 */  lwc1  $f8, ($a0)
/* 036848 7F001D18 46122182 */  mul.s $f6, $f4, $f18
/* 03684C 7F001D1C 46083280 */  add.s $f10, $f6, $f8
/* 036850 7F001D20 E4AA0000 */  swc1  $f10, ($a1)
/* 036854 7F001D24 C7A40040 */  lwc1  $f4, 0x40($sp)
/* 036858 7F001D28 C4880010 */  lwc1  $f8, 0x10($a0)
/* 03685C 7F001D2C 46047182 */  mul.s $f6, $f14, $f4
/* 036860 7F001D30 00000000 */  nop   
/* 036864 7F001D34 46088282 */  mul.s $f10, $f16, $f8
/* 036868 7F001D38 C488001C */  lwc1  $f8, 0x1c($a0)
/* 03686C 7F001D3C 460A3100 */  add.s $f4, $f6, $f10
/* 036870 7F001D40 460C4182 */  mul.s $f6, $f8, $f12
/* 036874 7F001D44 46043280 */  add.s $f10, $f6, $f4
/* 036878 7F001D48 C4860004 */  lwc1  $f6, 4($a0)
/* 03687C 7F001D4C 46125202 */  mul.s $f8, $f10, $f18
/* 036880 7F001D50 46064100 */  add.s $f4, $f8, $f6
/* 036884 7F001D54 E4A40004 */  swc1  $f4, 4($a1)
/* 036888 7F001D58 C7AA0044 */  lwc1  $f10, 0x44($sp)
/* 03688C 7F001D5C C4860014 */  lwc1  $f6, 0x14($a0)
/* 036890 7F001D60 460A7202 */  mul.s $f8, $f14, $f10
/* 036894 7F001D64 00000000 */  nop   
/* 036898 7F001D68 46068102 */  mul.s $f4, $f16, $f6
/* 03689C 7F001D6C C4860020 */  lwc1  $f6, 0x20($a0)
/* 0368A0 7F001D70 46044280 */  add.s $f10, $f8, $f4
/* 0368A4 7F001D74 460C3202 */  mul.s $f8, $f6, $f12
/* 0368A8 7F001D78 460A4100 */  add.s $f4, $f8, $f10
/* 0368AC 7F001D7C C4880008 */  lwc1  $f8, 8($a0)
/* 0368B0 7F001D80 46122182 */  mul.s $f6, $f4, $f18
/* 0368B4 7F001D84 46083280 */  add.s $f10, $f6, $f8
/* 0368B8 7F001D88 E4AA0008 */  swc1  $f10, 8($a1)
/* 0368BC 7F001D8C 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0368C0 7F001D90 27BD0048 */  addiu $sp, $sp, 0x48
/* 0368C4 7F001D94 03E00008 */  jr    $ra
/* 0368C8 7F001D98 00000000 */   nop   
)
#endif


#ifdef NONMATCHING
// maybe domakedefaultobj
void domakedefaultobj(s32 arg0, ObjectRecord *arg1, s32 cmdindex)
{
    s32 spF0;
    ? spE0;
    StandTile * spDC;
    f32         spD8;
    f32         spD4;
    f32         spD0;
    StandTile * spCC;
    Mtxf        sp8C;
    f32         sp88;
    f32         sp84;
    f32         sp80;
    f32         sp78;
    s32         sp74;
    ChrRecord * sp6C;
    PadRecord * sp64;
    PropRecord *sp60;
    f32         sp58;
    f32         sp54;
    f32         sp50;
    f32         sp48;
    ChrRecord * temp_v0;
    Model *     monitor->model;
    Model *     temp_a0_3;
    Model *     temp_a0_5;
    Model *     temp_a0_6;
    PadRecord * temp_v0_2;
    StandTile **temp_a0_4;
    f32         temp_f0;
    f32         temp_f0_2;
    f32         temp_f0_3;
    f32         temp_f0_4;
    f32         temp_f0_5;
    f32         temp_f0_6;
    f32         temp_f12;
    f32         temp_f12_2;
    f32         temp_f12_3;
    f32         temp_f16;
    f32         temp_f18;
    f32         temp_f2;
    f32         temp_f2_2;
    f32         temp_f2_3;
    f32         temp_f2_4;
    f32         temp_f2_5;
    f32         temp_f2_6;
    f32         temp_f6;
    s16         temp_a0;
    s16         temp_v1_2;
    u16         temp_t6;
    u32         temp_v1;
    u32         temp_v1_3;
    u32         temp_v1_4;
    void *      temp_s0;
    void *      temp_v0_3;
    f32         phi_f6;
    s32         phi_v1;
    PropRecord *phi_v0;
    PropRecord *phi_v0_2;
    void *      phi_s0;
    f32         phi_f6_2;
    f32         phi_f16;
    f32         phi_f18;
    f32         phi_f0;
    f32         phi_f14;
    f32         phi_f12;
    f32         phi_f14_2;
    f32         phi_f16_2;
    f32         phi_f18_2;
    f32         phi_f16_3;
    f32         phi_f18_3;
    f32         phi_f12_2;
    f32         phi_f0_2;

    temp_a0 = arg1->obj;
    spF0    = temp_a0;
    load_model(temp_a0);
    temp_t6 = arg1->extrascale;
    temp_f6 = temp_t6;
    phi_f6  = temp_f6;
    phi_s0  = NULL;
    if (temp_t6 < 0)
    {
        phi_f6 = temp_f6 + 4294967296.0f;
    }
    sp78              = phi_f6 * 0.00390625f;
    arg1->mtx.m[1][3] = (bitwise s32)(arg1->mtx.m[1][3] / M_U16_MAX_VALUE_F);
    phi_v1            = 1;
    if (getPlayerCount() >= 2)
    {
        sp74 = 1;
        if ((get_scenario() == 2) && (arg1->obj == 0x14D))
        {
            goto block_8;
        }
        sp74 = 1;
        if ((get_scenario() == 3) && (arg1->obj == 0xD0))
        {
block_8:
            phi_v1 = 0;
        }
        if (phi_v1 != 0)
        {
            arg1->state |= 4;
        }
    }
    temp_v1 = arg1->flags;
    if ((temp_v1 & 0x8000) != 0)
    {
        if (arg1->type == 8)
        {
            sub_GAME_7F051DD8(arg1, PitemZ_entries[spF0].Header);
        }
        else
        {
            objInitWithModelDef(arg1, PitemZ_entries[spF0].Header);
        }
        monitor->model = arg1->model;
        modelSetScale(monitor->model, monitor->model->scale * sp78);
        return;
    }
    if ((temp_v1 & 0x4000) != 0)
    {
        temp_v0 = chrFindByLiteralId(arg1->pad);
        sp6C    = temp_v0;
        if ((temp_v0 != 0) && (temp_v0->prop != 0) && (temp_v0->model != 0))
        {
            if (arg1->Head.type == 8)
            {
                phi_v0 = sub_GAME_7F051DD8(arg1, PitemZ_entries[spF0].Header);
            }
            else
            {
                phi_v0 = objInitWithModelDef(arg1, PitemZ_entries[spF0].Header);
            }
            temp_a0_3 = arg1->model;
            modelSetScale(temp_a0_3, temp_a0_3->scale * sp78);
            attachNewChild(phi_v0, sp6C->prop);
        }
    }
    else
    {
        temp_v1_2 = arg1->pad;
        if (temp_v1_2 < 0x2710)
        {
            temp_v0_2 = &g_CurrentSetup.pads[temp_v1_2];
            sp64      = temp_v0_2;
            matrix_4x4_7F059908(&sp8C, 0.0f, 0.0f, 0.0f, -temp_v0_2->target.AsArray[0], -temp_v0_2->target.AsArray[1], -temp_v0_2->target.AsArray[2], temp_v0_2->up.AsArray[0], temp_v0_2->up.AsArray[1], temp_v0_2->up.AsArray[2]);
            spD0 = sp64->pos.AsArray[0];
            spD4 = sp64->pos.AsArray[1];
            spD8 = sp64->pos.AsArray[2];
            if ((arg1->flags & 2) != 0)
            {
                sp80 = sp64->pos.AsArray[0];
                sp84 = sp64->pos.AsArray[1];
                sp88 = sp64->pos.AsArray[2];
            }
            else
            {
                sp80 = sp64->pos.AsArray[0];
                sp84 = sp64->pos.AsArray[1];
                sp88 = sp64->pos.AsArray[2];
            }
            spCC = sp64->stan;
        }
        else
        {
            temp_s0 = &g_CurrentSetup.boundpads[temp_v1_2] + 0xFFF59FC0;
            matrix_4x4_7F059908(&sp8C, 0.0f, 0.0f, 0.0f, -temp_s0->unk18, -temp_s0->unk1C, -temp_s0->unk20, temp_s0->unkC, temp_s0->unk10, temp_s0->unk14);
            phi_s0 = temp_s0;
            if ((arg1->flags2 & 1) == 0)
            {
                sub_GAME_7F001BD4(temp_s0, &spD0);
                temp_a0_4 = &spCC;
                sp80      = (temp_s0->unkC * ((temp_s0->unk34 - temp_s0->unk38) * 0.5f)) + spD0;
                sp84      = (temp_s0->unk10 * ((temp_s0->unk34 - temp_s0->unk38) * 0.5f)) + spD4;
                sp88      = (temp_s0->unk14 * ((temp_s0->unk34 - temp_s0->unk38) * 0.5f)) + spD8;
                spCC      = temp_s0->unk28;
                if (walkTilesBetweenPoints_NoCallback(temp_a0_4, temp_s0->unk0, temp_s0->unk8, spD0, spD8) == 0)
                {
                    spD0      = temp_s0->unk0;
                    spD4      = temp_s0->unk4;
                    spD8      = temp_s0->unk8;
                    spCC      = temp_s0->unk28;
                    temp_v1_3 = arg1->flags;
                    if (((temp_v1_3 & 2) == 0) && ((temp_v1_3 & 0x1000) == 0))
                    {
                    }
                }
            }
            else
            {
                spD0 = temp_s0->unk0;
                spD4 = temp_s0->unk4;
                spD8 = temp_s0->unk8;
                spCC = temp_s0->unk28;
                sub_GAME_7F001BD4(temp_s0, &sp80);
                sp80 += (temp_s0->unk34 - temp_s0->unk38) * 0.5f * temp_s0->unkC;
                sp84 += (temp_s0->unk34 - temp_s0->unk38) * 0.5f * temp_s0->unk10;
                sp88 += (temp_s0->unk34 - temp_s0->unk38) * 0.5f * temp_s0->unk14;
            }
        }
        if (sub_GAME_7F056850(&spD0, spCC, 0, &spE0, &spDC) != 0)
        {
            if (arg1->Head.type == 8)
            {
                phi_v0_2 = sub_GAME_7F051DD8(arg1, PitemZ_entries[spF0].Header);
            }
            else
            {
                phi_v0_2 = objInitWithAutoModel(arg1);
            }
            sp60 = phi_v0_2;
            if (phi_s0 != 0)
            {
                temp_v0_3 = chrobjGetBboxFromObjectRecord(arg1);
                if (temp_v0_3 != 0)
                {
                    sp58      = 1.0f;
                    temp_v1_4 = arg1->flags;
                    phi_f16_3 = 1.0f;
                    phi_f18_3 = 1.0f;
                    phi_f16   = 1.0f;
                    phi_f18   = 1.0f;
                    if ((temp_v1_4 & 0x30) != 0)
                    {
                        temp_f2 = temp_v0_3->unk4;
                        temp_f0 = temp_v0_3->unk8;
                        if (temp_f2 < temp_f0)
                        {
                            if ((temp_v1_4 & 2) != 0)
                            {
                                phi_f6_2 = (phi_s0->unk30 - phi_s0->unk2C) / ((temp_f0 - temp_f2) * arg1->model->scale);
                            }
                            else
                            {
                                phi_f6_2 = (phi_s0->unk30 - phi_s0->unk2C) / ((temp_f0 - temp_f2) * arg1->model->scale);
                            }
                            sp58 = phi_f6_2;
                        }
                    }
                    if ((temp_v1_4 & 0x50) != 0)
                    {
                        temp_f2_2 = temp_v0_3->unkC;
                        temp_f0_2 = temp_v0_3->unk10;
                        if (temp_f2_2 < temp_f0_2)
                        {
                            temp_f12 = arg1->model->scale;
                            if ((temp_v1_4 & 2) != 0)
                            {
                                phi_f18 = (phi_s0->unk40 - phi_s0->unk3C) / ((temp_f0_2 - temp_f2_2) * temp_f12);
                            }
                            else
                            {
                                phi_f16 = (phi_s0->unk38 - phi_s0->unk34) / ((temp_f0_2 - temp_f2_2) * temp_f12);
                            }
                        }
                    }
                    if ((temp_v1_4 & 0x90) != 0)
                    {
                        temp_f2_3 = temp_v0_3->unk14;
                        temp_f0_3 = temp_v0_3->unk18;
                        if (temp_f2_3 < temp_f0_3)
                        {
                            temp_f12_2 = arg1->model->scale;
                            if ((temp_v1_4 & 2) != 0)
                            {
                                phi_f16 = (phi_s0->unk38 - phi_s0->unk34) / ((temp_f0_3 - temp_f2_3) * temp_f12_2);
                            }
                            else
                            {
                                phi_f18 = (phi_s0->unk40 - phi_s0->unk3C) / ((temp_f0_3 - temp_f2_3) * temp_f12_2);
                            }
                        }
                    }
                    phi_f0    = sp58;
                    phi_f12   = sp58;
                    phi_f16_2 = phi_f16;
                    phi_f18_2 = phi_f18;
                    if (phi_f16 < sp58)
                    {
                        phi_f0 = phi_f16;
                    }
                    phi_f0_2 = phi_f0;
                    if (phi_f18 < phi_f0)
                    {
                        phi_f0_2 = phi_f18;
                    }
                    phi_f14 = sp58;
                    if (sp58 < phi_f16)
                    {
                        phi_f14 = phi_f16;
                    }
                    phi_f14_2 = phi_f14;
                    if (phi_f14 < phi_f18)
                    {
                        phi_f14_2 = phi_f18;
                    }
                    if ((temp_v1_4 & 0x10) != 0)
                    {
                        phi_f12   = phi_f0_2;
                        phi_f16_2 = phi_f0_2;
                        phi_f18_2 = phi_f0_2;
                    }
                    else
                    {
                        if ((temp_v1_4 & 0x20) == 0)
                        {
                            temp_f0_4 = temp_v0_3->unk8;
                            temp_f2_4 = temp_v0_3->unk4;
                            if ((temp_v1_4 & 2) != 0)
                            {
                                if (temp_f2_4 == temp_f0_4)
                                {
                                    goto block_72;
                                }
                            }
                            else if (temp_f2_4 == temp_f0_4)
                            {
block_72:
                                phi_f12 = phi_f14_2;
                            }
                        }
                        if ((temp_v1_4 & 0x40) == 0)
                        {
                            temp_f0_5 = temp_v0_3->unk10;
                            temp_f2_5 = temp_v0_3->unkC;
                            if ((temp_v1_4 & 2) != 0)
                            {
                                if (temp_f2_5 == temp_f0_5)
                                {
                                    phi_f18_2 = phi_f14_2;
                                }
                            }
                            else if (temp_f2_5 == temp_f0_5)
                            {
                                phi_f16_2 = phi_f14_2;
                            }
                        }
                        if ((temp_v1_4 & 0x80) == 0)
                        {
                            temp_f0_6 = temp_v0_3->unk18;
                            temp_f2_6 = temp_v0_3->unk14;
                            if ((temp_v1_4 & 2) != 0)
                            {
                                if (temp_f2_6 == temp_f0_6)
                                {
                                    phi_f16_2 = phi_f14_2;
                                }
                            }
                            else if (temp_f2_6 == temp_f0_6)
                            {
                                phi_f18_2 = phi_f14_2;
                            }
                        }
                    }
                    temp_f12_3 = phi_f12 / phi_f14_2;
                    temp_f16   = phi_f16_2 / phi_f14_2;
                    temp_f18   = phi_f18_2 / phi_f14_2;
                    phi_f16_3  = temp_f16;
                    phi_f18_3  = temp_f18;
                    phi_f12_2  = temp_f12_3;
                    if ((temp_f12_3 <= 0.000001f) || (temp_f16 <= 0.000001f) || (temp_f18 <= 0.000001f))
                    {
                        phi_f12_2 = 1.0f;
                    }
                    sp48 = phi_f14_2;
                    sp54 = phi_f16_3;
                    sp50 = phi_f18_3;
                    matrix_column_1_scalar_multiply(phi_f12_2, phi_f14_2, &sp8C);
                    matrix_column_2_scalar_multiply(sp54, &sp8C);
                    matrix_column_3_scalar_multiply_2(sp50, &sp8C);
                    temp_a0_5 = arg1->model;
                    modelSetScale(temp_a0_5, temp_a0_5->scale * sp48);
                }
            }
            temp_a0_6 = arg1->model;
            modelSetScale(temp_a0_6, temp_a0_6->scale * sp78);
            matrix_scalar_multiply(arg1->model->scale, &sp8C);
            if ((arg1->flags & 2) != 0)
            {
                sub_GAME_7F040BA0(arg1, &spE0, &sp8C, spDC, &sp80);
            }
            else
            {
                sub_GAME_7F04088C(arg1, &spE0, &sp8C, spDC, &sp80);
            }
            setupUpdateObjectRoomPosition(arg1);
            set_current_objposdata_plus_0x28(sp60);
            set_stateflag_0x04_for_posdata(sp60);
        }
    }
}

#else
void domakedefaultobj(s32 arg0, ObjectRecord *arg1, s32 cmdindex);
GLOBAL_ASM(
.late_rodata
glabel D_8004EEB4
.word 0x358637bd
.text
glabel domakedefaultobj
/* 0368CC 7F001D9C 27BDFF08 */  addiu $sp, $sp, -0xf8
/* 0368D0 7F001DA0 AFBF0034 */  sw    $ra, 0x34($sp)
/* 0368D4 7F001DA4 AFB10030 */  sw    $s1, 0x30($sp)
/* 0368D8 7F001DA8 AFB0002C */  sw    $s0, 0x2c($sp)
/* 0368DC 7F001DAC AFA400F8 */  sw    $a0, 0xf8($sp)
/* 0368E0 7F001DB0 AFA60100 */  sw    $a2, 0x100($sp)
/* 0368E4 7F001DB4 84A40004 */  lh    $a0, 4($a1)
/* 0368E8 7F001DB8 00A08825 */  move  $s1, $a1
/* 0368EC 7F001DBC 00008025 */  move  $s0, $zero
/* 0368F0 7F001DC0 0FC15B0E */  jal   modelLoad
/* 0368F4 7F001DC4 AFA400F0 */   sw    $a0, 0xf0($sp)
/* 0368F8 7F001DC8 962E0000 */  lhu   $t6, ($s1)
/* 0368FC 7F001DCC 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 036900 7F001DD0 448E2000 */  mtc1  $t6, $f4
/* 036904 7F001DD4 05C10004 */  bgez  $t6, .L7F001DE8
/* 036908 7F001DD8 468021A0 */   cvt.s.w $f6, $f4
/* 03690C 7F001DDC 44814000 */  mtc1  $at, $f8
/* 036910 7F001DE0 00000000 */  nop   
/* 036914 7F001DE4 46083180 */  add.s $f6, $f6, $f8
.L7F001DE8:
/* 036918 7F001DE8 3C013B80 */  li    $at, 0x3B800000 # 0.003906
/* 03691C 7F001DEC 44815000 */  mtc1  $at, $f10
/* 036920 7F001DF0 3C014780 */  li    $at, 0x47800000 # 65536.000000
/* 036924 7F001DF4 460A3102 */  mul.s $f4, $f6, $f10
/* 036928 7F001DF8 44815000 */  mtc1  $at, $f10
/* 03692C 7F001DFC E7A40078 */  swc1  $f4, 0x78($sp)
/* 036930 7F001E00 8E2F0074 */  lw    $t7, 0x74($s1)
/* 036934 7F001E04 448F4000 */  mtc1  $t7, $f8
/* 036938 7F001E08 00000000 */  nop   
/* 03693C 7F001E0C 468041A0 */  cvt.s.w $f6, $f8
/* 036940 7F001E10 460A3103 */  div.s $f4, $f6, $f10
/* 036944 7F001E14 0FC26919 */  jal   getPlayerCount
/* 036948 7F001E18 E6240074 */   swc1  $f4, 0x74($s1)
/* 03694C 7F001E1C 28410002 */  slti  $at, $v0, 2
/* 036950 7F001E20 1420001B */  bnez  $at, .L7F001E90
/* 036954 7F001E24 24030001 */   li    $v1, 1
/* 036958 7F001E28 0FC051D6 */  jal   get_scenario
/* 03695C 7F001E2C AFA30074 */   sw    $v1, 0x74($sp)
/* 036960 7F001E30 24010002 */  li    $at, 2
/* 036964 7F001E34 14410007 */  bne   $v0, $at, .L7F001E54
/* 036968 7F001E38 8FA30074 */   lw    $v1, 0x74($sp)
/* 03696C 7F001E3C 86380004 */  lh    $t8, 4($s1)
/* 036970 7F001E40 2401014D */  li    $at, 333
/* 036974 7F001E44 17010003 */  bne   $t8, $at, .L7F001E54
/* 036978 7F001E48 00000000 */   nop   
/* 03697C 7F001E4C 1000000B */  b     .L7F001E7C
/* 036980 7F001E50 00001825 */   move  $v1, $zero
.L7F001E54:
/* 036984 7F001E54 0FC051D6 */  jal   get_scenario
/* 036988 7F001E58 AFA30074 */   sw    $v1, 0x74($sp)
/* 03698C 7F001E5C 24010003 */  li    $at, 3
/* 036990 7F001E60 14410006 */  bne   $v0, $at, .L7F001E7C
/* 036994 7F001E64 8FA30074 */   lw    $v1, 0x74($sp)
/* 036998 7F001E68 86390004 */  lh    $t9, 4($s1)
/* 03699C 7F001E6C 240100D0 */  li    $at, 208
/* 0369A0 7F001E70 17210002 */  bne   $t9, $at, .L7F001E7C
/* 0369A4 7F001E74 00000000 */   nop   
/* 0369A8 7F001E78 00001825 */  move  $v1, $zero
.L7F001E7C:
/* 0369AC 7F001E7C 50600005 */  beql  $v1, $zero, .L7F001E94
/* 0369B0 7F001E80 8E230008 */   lw    $v1, 8($s1)
/* 0369B4 7F001E84 92280002 */  lbu   $t0, 2($s1)
/* 0369B8 7F001E88 35090004 */  ori   $t1, $t0, 4
/* 0369BC 7F001E8C A2290002 */  sb    $t1, 2($s1)
.L7F001E90:
/* 0369C0 7F001E90 8E230008 */  lw    $v1, 8($s1)
.L7F001E94:
/* 0369C4 7F001E94 306A8000 */  andi  $t2, $v1, 0x8000
/* 0369C8 7F001E98 11400021 */  beqz  $t2, .L7F001F20
/* 0369CC 7F001E9C 30784000 */   andi  $t8, $v1, 0x4000
/* 0369D0 7F001EA0 922B0003 */  lbu   $t3, 3($s1)
/* 0369D4 7F001EA4 8FAE00F0 */  lw    $t6, 0xf0($sp)
/* 0369D8 7F001EA8 24010008 */  li    $at, 8
/* 0369DC 7F001EAC 1561000C */  bne   $t3, $at, .L7F001EE0
/* 0369E0 7F001EB0 000E7880 */   sll   $t7, $t6, 2
/* 0369E4 7F001EB4 8FAC00F0 */  lw    $t4, 0xf0($sp)
/* 0369E8 7F001EB8 3C058004 */  lui   $a1, %hi(PitemZ_entries)
/* 0369EC 7F001EBC 02202025 */  move  $a0, $s1
/* 0369F0 7F001EC0 000C6880 */  sll   $t5, $t4, 2
/* 0369F4 7F001EC4 01AC6823 */  subu  $t5, $t5, $t4
/* 0369F8 7F001EC8 000D6880 */  sll   $t5, $t5, 2
/* 0369FC 7F001ECC 00AD2821 */  addu  $a1, $a1, $t5
/* 036A00 7F001ED0 0FC14776 */  jal   sub_GAME_7F051DD8
/* 036A04 7F001ED4 8CA5A228 */   lw    $a1, %lo(PitemZ_entries)($a1)
/* 036A08 7F001ED8 10000009 */  b     .L7F001F00
/* 036A0C 7F001EDC 8E240014 */   lw    $a0, 0x14($s1)
.L7F001EE0:
/* 036A10 7F001EE0 01EE7823 */  subu  $t7, $t7, $t6
/* 036A14 7F001EE4 000F7880 */  sll   $t7, $t7, 2
/* 036A18 7F001EE8 3C058004 */  lui   $a1, %hi(PitemZ_entries)
/* 036A1C 7F001EEC 00AF2821 */  addu  $a1, $a1, $t7
/* 036A20 7F001EF0 8CA5A228 */  lw    $a1, %lo(PitemZ_entries)($a1)
/* 036A24 7F001EF4 0FC101BE */  jal   objInitWithModelDef
/* 036A28 7F001EF8 02202025 */   move  $a0, $s1
/* 036A2C 7F001EFC 8E240014 */  lw    $a0, 0x14($s1)
.L7F001F00:
/* 036A30 7F001F00 C7A60078 */  lwc1  $f6, 0x78($sp)
/* 036A34 7F001F04 C4880014 */  lwc1  $f8, 0x14($a0)
/* 036A38 7F001F08 46064282 */  mul.s $f10, $f8, $f6
/* 036A3C 7F001F0C 44055000 */  mfc1  $a1, $f10
/* 036A40 7F001F10 0FC1B39E */  jal   modelSetScale
/* 036A44 7F001F14 00000000 */   nop   
/* 036A48 7F001F18 10000203 */  b     .L7F002728
/* 036A4C 7F001F1C 8FBF0034 */   lw    $ra, 0x34($sp)
.L7F001F20:
/* 036A50 7F001F20 53000031 */  beql  $t8, $zero, .L7F001FE8
/* 036A54 7F001F24 86230006 */   lh    $v1, 6($s1)
/* 036A58 7F001F28 0FC08BF2 */  jal   chrFindByLiteralId
/* 036A5C 7F001F2C 86240006 */   lh    $a0, 6($s1)
/* 036A60 7F001F30 104001FC */  beqz  $v0, .L7F002724
/* 036A64 7F001F34 AFA2006C */   sw    $v0, 0x6c($sp)
/* 036A68 7F001F38 8C590018 */  lw    $t9, 0x18($v0)
/* 036A6C 7F001F3C 532001FA */  beql  $t9, $zero, .L7F002728
/* 036A70 7F001F40 8FBF0034 */   lw    $ra, 0x34($sp)
/* 036A74 7F001F44 8C48001C */  lw    $t0, 0x1c($v0)
/* 036A78 7F001F48 510001F7 */  beql  $t0, $zero, .L7F002728
/* 036A7C 7F001F4C 8FBF0034 */   lw    $ra, 0x34($sp)
/* 036A80 7F001F50 92290003 */  lbu   $t1, 3($s1)
/* 036A84 7F001F54 8FAC00F0 */  lw    $t4, 0xf0($sp)
/* 036A88 7F001F58 24010008 */  li    $at, 8
/* 036A8C 7F001F5C 1521000C */  bne   $t1, $at, .L7F001F90
/* 036A90 7F001F60 000C6880 */   sll   $t5, $t4, 2
/* 036A94 7F001F64 8FAA00F0 */  lw    $t2, 0xf0($sp)
/* 036A98 7F001F68 3C058004 */  lui   $a1, %hi(PitemZ_entries)
/* 036A9C 7F001F6C 02202025 */  move  $a0, $s1
/* 036AA0 7F001F70 000A5880 */  sll   $t3, $t2, 2
/* 036AA4 7F001F74 016A5823 */  subu  $t3, $t3, $t2
/* 036AA8 7F001F78 000B5880 */  sll   $t3, $t3, 2
/* 036AAC 7F001F7C 00AB2821 */  addu  $a1, $a1, $t3
/* 036AB0 7F001F80 0FC14776 */  jal   sub_GAME_7F051DD8
/* 036AB4 7F001F84 8CA5A228 */   lw    $a1, %lo(PitemZ_entries)($a1)
/* 036AB8 7F001F88 10000009 */  b     .L7F001FB0
/* 036ABC 7F001F8C 00408025 */   move  $s0, $v0
.L7F001F90:
/* 036AC0 7F001F90 01AC6823 */  subu  $t5, $t5, $t4
/* 036AC4 7F001F94 000D6880 */  sll   $t5, $t5, 2
/* 036AC8 7F001F98 3C058004 */  lui   $a1, %hi(PitemZ_entries)
/* 036ACC 7F001F9C 00AD2821 */  addu  $a1, $a1, $t5
/* 036AD0 7F001FA0 8CA5A228 */  lw    $a1, %lo(PitemZ_entries)($a1)
/* 036AD4 7F001FA4 0FC101BE */  jal   objInitWithModelDef
/* 036AD8 7F001FA8 02202025 */   move  $a0, $s1
/* 036ADC 7F001FAC 00408025 */  move  $s0, $v0
.L7F001FB0:
/* 036AE0 7F001FB0 8E240014 */  lw    $a0, 0x14($s1)
/* 036AE4 7F001FB4 C7A80078 */  lwc1  $f8, 0x78($sp)
/* 036AE8 7F001FB8 C4840014 */  lwc1  $f4, 0x14($a0)
/* 036AEC 7F001FBC 46082182 */  mul.s $f6, $f4, $f8
/* 036AF0 7F001FC0 44053000 */  mfc1  $a1, $f6
/* 036AF4 7F001FC4 0FC1B39E */  jal   modelSetScale
/* 036AF8 7F001FC8 00000000 */   nop   
/* 036AFC 7F001FCC 8FAE006C */  lw    $t6, 0x6c($sp)
/* 036B00 7F001FD0 02002025 */  move  $a0, $s0
/* 036B04 7F001FD4 0FC0E969 */  jal   chrpropReparent
/* 036B08 7F001FD8 8DC50018 */   lw    $a1, 0x18($t6)
/* 036B0C 7F001FDC 100001D2 */  b     .L7F002728
/* 036B10 7F001FE0 8FBF0034 */   lw    $ra, 0x34($sp)
/* 036B14 7F001FE4 86230006 */  lh    $v1, 6($s1)
.L7F001FE8:
/* 036B18 7F001FE8 3C188007 */  lui   $t8, %hi(g_CurrentSetup+0x18) 
/* 036B1C 7F001FEC 3C0B8007 */  lui   $t3, %hi(g_CurrentSetup+0x1C) 
/* 036B20 7F001FF0 28612710 */  slti  $at, $v1, 0x2710
/* 036B24 7F001FF4 10200039 */  beqz  $at, .L7F0020DC
/* 036B28 7F001FF8 00035100 */   sll   $t2, $v1, 4
/* 036B2C 7F001FFC 00037880 */  sll   $t7, $v1, 2
/* 036B30 7F002000 01E37823 */  subu  $t7, $t7, $v1
/* 036B34 7F002004 8F185D18 */  lw    $t8, %lo(g_CurrentSetup+0x18)($t8)
/* 036B38 7F002008 000F7880 */  sll   $t7, $t7, 2
/* 036B3C 7F00200C 01E37823 */  subu  $t7, $t7, $v1
/* 036B40 7F002010 000F7880 */  sll   $t7, $t7, 2
/* 036B44 7F002014 01F81021 */  addu  $v0, $t7, $t8
/* 036B48 7F002018 C44A0018 */  lwc1  $f10, 0x18($v0)
/* 036B4C 7F00201C 44800000 */  mtc1  $zero, $f0
/* 036B50 7F002020 27A4008C */  addiu $a0, $sp, 0x8c
/* 036B54 7F002024 46005107 */  neg.s $f4, $f10
/* 036B58 7F002028 44050000 */  mfc1  $a1, $f0
/* 036B5C 7F00202C E7A40010 */  swc1  $f4, 0x10($sp)
/* 036B60 7F002030 C448001C */  lwc1  $f8, 0x1c($v0)
/* 036B64 7F002034 44060000 */  mfc1  $a2, $f0
/* 036B68 7F002038 44070000 */  mfc1  $a3, $f0
/* 036B6C 7F00203C 46004187 */  neg.s $f6, $f8
/* 036B70 7F002040 E7A60014 */  swc1  $f6, 0x14($sp)
/* 036B74 7F002044 C44A0020 */  lwc1  $f10, 0x20($v0)
/* 036B78 7F002048 46005107 */  neg.s $f4, $f10
/* 036B7C 7F00204C E7A40018 */  swc1  $f4, 0x18($sp)
/* 036B80 7F002050 C448000C */  lwc1  $f8, 0xc($v0)
/* 036B84 7F002054 E7A8001C */  swc1  $f8, 0x1c($sp)
/* 036B88 7F002058 C4460010 */  lwc1  $f6, 0x10($v0)
/* 036B8C 7F00205C E7A60020 */  swc1  $f6, 0x20($sp)
/* 036B90 7F002060 C44A0014 */  lwc1  $f10, 0x14($v0)
/* 036B94 7F002064 AFA20064 */  sw    $v0, 0x64($sp)
/* 036B98 7F002068 0FC16642 */  jal   matrix_4x4_7F059908
/* 036B9C 7F00206C E7AA0024 */   swc1  $f10, 0x24($sp)
/* 036BA0 7F002070 8FA20064 */  lw    $v0, 0x64($sp)
/* 036BA4 7F002074 C4440000 */  lwc1  $f4, ($v0)
/* 036BA8 7F002078 E7A400D0 */  swc1  $f4, 0xd0($sp)
/* 036BAC 7F00207C C4480004 */  lwc1  $f8, 4($v0)
/* 036BB0 7F002080 E7A800D4 */  swc1  $f8, 0xd4($sp)
/* 036BB4 7F002084 C4460008 */  lwc1  $f6, 8($v0)
/* 036BB8 7F002088 E7A600D8 */  swc1  $f6, 0xd8($sp)
/* 036BBC 7F00208C 8E390008 */  lw    $t9, 8($s1)
/* 036BC0 7F002090 33280002 */  andi  $t0, $t9, 2
/* 036BC4 7F002094 51000009 */  beql  $t0, $zero, .L7F0020BC
/* 036BC8 7F002098 C4460000 */   lwc1  $f6, ($v0)
/* 036BCC 7F00209C C44A0000 */  lwc1  $f10, ($v0)
/* 036BD0 7F0020A0 E7AA0080 */  swc1  $f10, 0x80($sp)
/* 036BD4 7F0020A4 C4440004 */  lwc1  $f4, 4($v0)
/* 036BD8 7F0020A8 E7A40084 */  swc1  $f4, 0x84($sp)
/* 036BDC 7F0020AC C4480008 */  lwc1  $f8, 8($v0)
/* 036BE0 7F0020B0 10000007 */  b     .L7F0020D0
/* 036BE4 7F0020B4 E7A80088 */   swc1  $f8, 0x88($sp)
/* 036BE8 7F0020B8 C4460000 */  lwc1  $f6, ($v0)
.L7F0020BC:
/* 036BEC 7F0020BC E7A60080 */  swc1  $f6, 0x80($sp)
/* 036BF0 7F0020C0 C44A0004 */  lwc1  $f10, 4($v0)
/* 036BF4 7F0020C4 E7AA0084 */  swc1  $f10, 0x84($sp)
/* 036BF8 7F0020C8 C4440008 */  lwc1  $f4, 8($v0)
/* 036BFC 7F0020CC E7A40088 */  swc1  $f4, 0x88($sp)
.L7F0020D0:
/* 036C00 7F0020D0 8C490028 */  lw    $t1, 0x28($v0)
/* 036C04 7F0020D4 10000085 */  b     .L7F0022EC
/* 036C08 7F0020D8 AFA900CC */   sw    $t1, 0xcc($sp)
.L7F0020DC:
/* 036C0C 7F0020DC 8D6B5D1C */  lw    $t3, %lo(g_CurrentSetup+0x1C)($t3)
/* 036C10 7F0020E0 01435021 */  addu  $t2, $t2, $v1
/* 036C14 7F0020E4 000A5080 */  sll   $t2, $t2, 2
/* 036C18 7F0020E8 3C01FFF5 */  lui   $at, (0xFFF59FC0 >> 16) # lui $at, 0xfff5
/* 036C1C 7F0020EC 34219FC0 */  ori   $at, (0xFFF59FC0 & 0xFFFF) # ori $at, $at, 0x9fc0
/* 036C20 7F0020F0 014B8021 */  addu  $s0, $t2, $t3
/* 036C24 7F0020F4 02018021 */  addu  $s0, $s0, $at
/* 036C28 7F0020F8 C6080018 */  lwc1  $f8, 0x18($s0)
/* 036C2C 7F0020FC 44800000 */  mtc1  $zero, $f0
/* 036C30 7F002100 27A4008C */  addiu $a0, $sp, 0x8c
/* 036C34 7F002104 46004187 */  neg.s $f6, $f8
/* 036C38 7F002108 44050000 */  mfc1  $a1, $f0
/* 036C3C 7F00210C E7A60010 */  swc1  $f6, 0x10($sp)
/* 036C40 7F002110 C60A001C */  lwc1  $f10, 0x1c($s0)
/* 036C44 7F002114 44060000 */  mfc1  $a2, $f0
/* 036C48 7F002118 44070000 */  mfc1  $a3, $f0
/* 036C4C 7F00211C 46005107 */  neg.s $f4, $f10
/* 036C50 7F002120 E7A40014 */  swc1  $f4, 0x14($sp)
/* 036C54 7F002124 C6080020 */  lwc1  $f8, 0x20($s0)
/* 036C58 7F002128 46004187 */  neg.s $f6, $f8
/* 036C5C 7F00212C E7A60018 */  swc1  $f6, 0x18($sp)
/* 036C60 7F002130 C60A000C */  lwc1  $f10, 0xc($s0)
/* 036C64 7F002134 E7AA001C */  swc1  $f10, 0x1c($sp)
/* 036C68 7F002138 C6040010 */  lwc1  $f4, 0x10($s0)
/* 036C6C 7F00213C E7A40020 */  swc1  $f4, 0x20($sp)
/* 036C70 7F002140 C6080014 */  lwc1  $f8, 0x14($s0)
/* 036C74 7F002144 0FC16642 */  jal   matrix_4x4_7F059908
/* 036C78 7F002148 E7A80024 */   swc1  $f8, 0x24($sp)
/* 036C7C 7F00214C 8E2C000C */  lw    $t4, 0xc($s1)
/* 036C80 7F002150 02002025 */  move  $a0, $s0
/* 036C84 7F002154 318D0001 */  andi  $t5, $t4, 1
/* 036C88 7F002158 55A0003D */  bnezl $t5, .L7F002250
/* 036C8C 7F00215C C60A0000 */   lwc1  $f10, ($s0)
/* 036C90 7F002160 0FC006F5 */  jal   sub_GAME_7F001BD4
/* 036C94 7F002164 27A500D0 */   addiu $a1, $sp, 0xd0
/* 036C98 7F002168 C6060034 */  lwc1  $f6, 0x34($s0)
/* 036C9C 7F00216C C60A0038 */  lwc1  $f10, 0x38($s0)
/* 036CA0 7F002170 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 036CA4 7F002174 44810000 */  mtc1  $at, $f0
/* 036CA8 7F002178 460A3101 */  sub.s $f4, $f6, $f10
/* 036CAC 7F00217C C606000C */  lwc1  $f6, 0xc($s0)
/* 036CB0 7F002180 27A400CC */  addiu $a0, $sp, 0xcc
/* 036CB4 7F002184 46002202 */  mul.s $f8, $f4, $f0
/* 036CB8 7F002188 C7A400D0 */  lwc1  $f4, 0xd0($sp)
/* 036CBC 7F00218C 44072000 */  mfc1  $a3, $f4
/* 036CC0 7F002190 46083282 */  mul.s $f10, $f6, $f8
/* 036CC4 7F002194 46045180 */  add.s $f6, $f10, $f4
/* 036CC8 7F002198 E7A60080 */  swc1  $f6, 0x80($sp)
/* 036CCC 7F00219C C60A0038 */  lwc1  $f10, 0x38($s0)
/* 036CD0 7F0021A0 C6080034 */  lwc1  $f8, 0x34($s0)
/* 036CD4 7F0021A4 460A4181 */  sub.s $f6, $f8, $f10
/* 036CD8 7F0021A8 C60A0010 */  lwc1  $f10, 0x10($s0)
/* 036CDC 7F0021AC 46003202 */  mul.s $f8, $f6, $f0
/* 036CE0 7F0021B0 00000000 */  nop   
/* 036CE4 7F0021B4 46085182 */  mul.s $f6, $f10, $f8
/* 036CE8 7F0021B8 C7AA00D4 */  lwc1  $f10, 0xd4($sp)
/* 036CEC 7F0021BC 460A3200 */  add.s $f8, $f6, $f10
/* 036CF0 7F0021C0 E7A80084 */  swc1  $f8, 0x84($sp)
/* 036CF4 7F0021C4 C60A0038 */  lwc1  $f10, 0x38($s0)
/* 036CF8 7F0021C8 C6060034 */  lwc1  $f6, 0x34($s0)
/* 036CFC 7F0021CC 460A3201 */  sub.s $f8, $f6, $f10
/* 036D00 7F0021D0 C60A0014 */  lwc1  $f10, 0x14($s0)
/* 036D04 7F0021D4 46004182 */  mul.s $f6, $f8, $f0
/* 036D08 7F0021D8 00000000 */  nop   
/* 036D0C 7F0021DC 46065202 */  mul.s $f8, $f10, $f6
/* 036D10 7F0021E0 C7AA00D8 */  lwc1  $f10, 0xd8($sp)
/* 036D14 7F0021E4 460A4180 */  add.s $f6, $f8, $f10
/* 036D18 7F0021E8 E7A60088 */  swc1  $f6, 0x88($sp)
/* 036D1C 7F0021EC 8E0E0028 */  lw    $t6, 0x28($s0)
/* 036D20 7F0021F0 AFAE00CC */  sw    $t6, 0xcc($sp)
/* 036D24 7F0021F4 8E060008 */  lw    $a2, 8($s0)
/* 036D28 7F0021F8 8E050000 */  lw    $a1, ($s0)
/* 036D2C 7F0021FC 0FC2C2F9 */  jal   walkTilesBetweenPoints_NoCallback
/* 036D30 7F002200 E7AA0010 */   swc1  $f10, 0x10($sp)
/* 036D34 7F002204 5440003A */  bnezl $v0, .L7F0022F0
/* 036D38 7F002208 27A900DC */   addiu $t1, $sp, 0xdc
/* 036D3C 7F00220C C6080000 */  lwc1  $f8, ($s0)
/* 036D40 7F002210 E7A800D0 */  swc1  $f8, 0xd0($sp)
/* 036D44 7F002214 C6060004 */  lwc1  $f6, 4($s0)
/* 036D48 7F002218 E7A600D4 */  swc1  $f6, 0xd4($sp)
/* 036D4C 7F00221C C6040008 */  lwc1  $f4, 8($s0)
/* 036D50 7F002220 E7A400D8 */  swc1  $f4, 0xd8($sp)
/* 036D54 7F002224 8E0F0028 */  lw    $t7, 0x28($s0)
/* 036D58 7F002228 AFAF00CC */  sw    $t7, 0xcc($sp)
/* 036D5C 7F00222C 8E230008 */  lw    $v1, 8($s1)
/* 036D60 7F002230 30780002 */  andi  $t8, $v1, 2
/* 036D64 7F002234 1700002D */  bnez  $t8, .L7F0022EC
/* 036D68 7F002238 30791000 */   andi  $t9, $v1, 0x1000
/* 036D6C 7F00223C 5720002C */  bnezl $t9, .L7F0022F0
/* 036D70 7F002240 27A900DC */   addiu $t1, $sp, 0xdc
/* 036D74 7F002244 1000002A */  b     .L7F0022F0
/* 036D78 7F002248 27A900DC */   addiu $t1, $sp, 0xdc
/* 036D7C 7F00224C C60A0000 */  lwc1  $f10, ($s0)
.L7F002250:
/* 036D80 7F002250 02002025 */  move  $a0, $s0
/* 036D84 7F002254 27A50080 */  addiu $a1, $sp, 0x80
/* 036D88 7F002258 E7AA00D0 */  swc1  $f10, 0xd0($sp)
/* 036D8C 7F00225C C6080004 */  lwc1  $f8, 4($s0)
/* 036D90 7F002260 E7A800D4 */  swc1  $f8, 0xd4($sp)
/* 036D94 7F002264 C6060008 */  lwc1  $f6, 8($s0)
/* 036D98 7F002268 E7A600D8 */  swc1  $f6, 0xd8($sp)
/* 036D9C 7F00226C 8E080028 */  lw    $t0, 0x28($s0)
/* 036DA0 7F002270 0FC006F5 */  jal   sub_GAME_7F001BD4
/* 036DA4 7F002274 AFA800CC */   sw    $t0, 0xcc($sp)
/* 036DA8 7F002278 C6040034 */  lwc1  $f4, 0x34($s0)
/* 036DAC 7F00227C C60A0038 */  lwc1  $f10, 0x38($s0)
/* 036DB0 7F002280 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 036DB4 7F002284 44810000 */  mtc1  $at, $f0
/* 036DB8 7F002288 460A2201 */  sub.s $f8, $f4, $f10
/* 036DBC 7F00228C C604000C */  lwc1  $f4, 0xc($s0)
/* 036DC0 7F002290 46004182 */  mul.s $f6, $f8, $f0
/* 036DC4 7F002294 C7A80080 */  lwc1  $f8, 0x80($sp)
/* 036DC8 7F002298 46043282 */  mul.s $f10, $f6, $f4
/* 036DCC 7F00229C 460A4180 */  add.s $f6, $f8, $f10
/* 036DD0 7F0022A0 E7A60080 */  swc1  $f6, 0x80($sp)
/* 036DD4 7F0022A4 C6080038 */  lwc1  $f8, 0x38($s0)
/* 036DD8 7F0022A8 C6040034 */  lwc1  $f4, 0x34($s0)
/* 036DDC 7F0022AC 46082281 */  sub.s $f10, $f4, $f8
/* 036DE0 7F0022B0 C6040010 */  lwc1  $f4, 0x10($s0)
/* 036DE4 7F0022B4 46005182 */  mul.s $f6, $f10, $f0
/* 036DE8 7F0022B8 C7AA0084 */  lwc1  $f10, 0x84($sp)
/* 036DEC 7F0022BC 46043202 */  mul.s $f8, $f6, $f4
/* 036DF0 7F0022C0 46085180 */  add.s $f6, $f10, $f8
/* 036DF4 7F0022C4 E7A60084 */  swc1  $f6, 0x84($sp)
/* 036DF8 7F0022C8 C60A0038 */  lwc1  $f10, 0x38($s0)
/* 036DFC 7F0022CC C6040034 */  lwc1  $f4, 0x34($s0)
/* 036E00 7F0022D0 460A2201 */  sub.s $f8, $f4, $f10
/* 036E04 7F0022D4 C6040014 */  lwc1  $f4, 0x14($s0)
/* 036E08 7F0022D8 46004182 */  mul.s $f6, $f8, $f0
/* 036E0C 7F0022DC C7A80088 */  lwc1  $f8, 0x88($sp)
/* 036E10 7F0022E0 46043282 */  mul.s $f10, $f6, $f4
/* 036E14 7F0022E4 460A4180 */  add.s $f6, $f8, $f10
/* 036E18 7F0022E8 E7A60088 */  swc1  $f6, 0x88($sp)
.L7F0022EC:
/* 036E1C 7F0022EC 27A900DC */  addiu $t1, $sp, 0xdc
.L7F0022F0:
/* 036E20 7F0022F0 AFA90010 */  sw    $t1, 0x10($sp)
/* 036E24 7F0022F4 27A400D0 */  addiu $a0, $sp, 0xd0
/* 036E28 7F0022F8 8FA500CC */  lw    $a1, 0xcc($sp)
/* 036E2C 7F0022FC 24060000 */  li    $a2, 0
/* 036E30 7F002300 0FC15A14 */  jal   sub_GAME_7F056850
/* 036E34 7F002304 27A700E0 */   addiu $a3, $sp, 0xe0
/* 036E38 7F002308 50400107 */  beql  $v0, $zero, .L7F002728
/* 036E3C 7F00230C 8FBF0034 */   lw    $ra, 0x34($sp)
/* 036E40 7F002310 922A0003 */  lbu   $t2, 3($s1)
/* 036E44 7F002314 8FAB00F0 */  lw    $t3, 0xf0($sp)
/* 036E48 7F002318 24010008 */  li    $at, 8
/* 036E4C 7F00231C 1541000A */  bne   $t2, $at, .L7F002348
/* 036E50 7F002320 000B6080 */   sll   $t4, $t3, 2
/* 036E54 7F002324 018B6023 */  subu  $t4, $t4, $t3
/* 036E58 7F002328 000C6080 */  sll   $t4, $t4, 2
/* 036E5C 7F00232C 3C058004 */  lui   $a1, %hi(PitemZ_entries)
/* 036E60 7F002330 00AC2821 */  addu  $a1, $a1, $t4
/* 036E64 7F002334 8CA5A228 */  lw    $a1, %lo(PitemZ_entries)($a1)
/* 036E68 7F002338 0FC14776 */  jal   sub_GAME_7F051DD8
/* 036E6C 7F00233C 02202025 */   move  $a0, $s1
/* 036E70 7F002340 10000004 */  b     .L7F002354
/* 036E74 7F002344 AFA20060 */   sw    $v0, 0x60($sp)
.L7F002348:
/* 036E78 7F002348 0FC101C7 */  jal   objInitWithAutoModel
/* 036E7C 7F00234C 02202025 */   move  $a0, $s1
/* 036E80 7F002350 AFA20060 */  sw    $v0, 0x60($sp)
.L7F002354:
/* 036E84 7F002354 520000D0 */  beql  $s0, $zero, .L7F002698
/* 036E88 7F002358 8E240014 */   lw    $a0, 0x14($s1)
/* 036E8C 7F00235C 0FC1001E */  jal   chrobjGetBboxFromObjectRecord
/* 036E90 7F002360 02202025 */   move  $a0, $s1
/* 036E94 7F002364 104000CB */  beqz  $v0, .L7F002694
/* 036E98 7F002368 3C013F80 */   li    $at, 0x3F800000 # 1.000000
/* 036E9C 7F00236C 44819000 */  mtc1  $at, $f18
/* 036EA0 7F002370 27A5008C */  addiu $a1, $sp, 0x8c
/* 036EA4 7F002374 E7B20058 */  swc1  $f18, 0x58($sp)
/* 036EA8 7F002378 8E230008 */  lw    $v1, 8($s1)
/* 036EAC 7F00237C 46009406 */  mov.s $f16, $f18
/* 036EB0 7F002380 306D0030 */  andi  $t5, $v1, 0x30
/* 036EB4 7F002384 11A0001D */  beqz  $t5, .L7F0023FC
/* 036EB8 7F002388 30790050 */   andi  $t9, $v1, 0x50
/* 036EBC 7F00238C C4420004 */  lwc1  $f2, 4($v0)
/* 036EC0 7F002390 C4400008 */  lwc1  $f0, 8($v0)
/* 036EC4 7F002394 306E0002 */  andi  $t6, $v1, 2
/* 036EC8 7F002398 4600103C */  c.lt.s $f2, $f0
/* 036ECC 7F00239C 00000000 */  nop   
/* 036ED0 7F0023A0 45000016 */  bc1f  .L7F0023FC
/* 036ED4 7F0023A4 00000000 */   nop   
/* 036ED8 7F0023A8 51C0000C */  beql  $t6, $zero, .L7F0023DC
/* 036EDC 7F0023AC C6040030 */   lwc1  $f4, 0x30($s0)
/* 036EE0 7F0023B0 C6040030 */  lwc1  $f4, 0x30($s0)
/* 036EE4 7F0023B4 C608002C */  lwc1  $f8, 0x2c($s0)
/* 036EE8 7F0023B8 8E2F0014 */  lw    $t7, 0x14($s1)
/* 036EEC 7F0023BC 46020181 */  sub.s $f6, $f0, $f2
/* 036EF0 7F0023C0 46082281 */  sub.s $f10, $f4, $f8
/* 036EF4 7F0023C4 C5E40014 */  lwc1  $f4, 0x14($t7)
/* 036EF8 7F0023C8 46043202 */  mul.s $f8, $f6, $f4
/* 036EFC 7F0023CC 46085183 */  div.s $f6, $f10, $f8
/* 036F00 7F0023D0 1000000A */  b     .L7F0023FC
/* 036F04 7F0023D4 E7A60058 */   swc1  $f6, 0x58($sp)
/* 036F08 7F0023D8 C6040030 */  lwc1  $f4, 0x30($s0)
.L7F0023DC:
/* 036F0C 7F0023DC C60A002C */  lwc1  $f10, 0x2c($s0)
/* 036F10 7F0023E0 8E380014 */  lw    $t8, 0x14($s1)
/* 036F14 7F0023E4 46020181 */  sub.s $f6, $f0, $f2
/* 036F18 7F0023E8 460A2201 */  sub.s $f8, $f4, $f10
/* 036F1C 7F0023EC C7040014 */  lwc1  $f4, 0x14($t8)
/* 036F20 7F0023F0 46043282 */  mul.s $f10, $f6, $f4
/* 036F24 7F0023F4 460A4183 */  div.s $f6, $f8, $f10
/* 036F28 7F0023F8 E7A60058 */  swc1  $f6, 0x58($sp)
.L7F0023FC:
/* 036F2C 7F0023FC 13200018 */  beqz  $t9, .L7F002460
/* 036F30 7F002400 306A0090 */   andi  $t2, $v1, 0x90
/* 036F34 7F002404 C442000C */  lwc1  $f2, 0xc($v0)
/* 036F38 7F002408 C4400010 */  lwc1  $f0, 0x10($v0)
/* 036F3C 7F00240C 4600103C */  c.lt.s $f2, $f0
/* 036F40 7F002410 00000000 */  nop   
/* 036F44 7F002414 45000012 */  bc1f  .L7F002460
/* 036F48 7F002418 00000000 */   nop   
/* 036F4C 7F00241C 8E280014 */  lw    $t0, 0x14($s1)
/* 036F50 7F002420 30690002 */  andi  $t1, $v1, 2
/* 036F54 7F002424 11200008 */  beqz  $t1, .L7F002448
/* 036F58 7F002428 C50C0014 */   lwc1  $f12, 0x14($t0)
/* 036F5C 7F00242C 46020181 */  sub.s $f6, $f0, $f2
/* 036F60 7F002430 C6040040 */  lwc1  $f4, 0x40($s0)
/* 036F64 7F002434 C608003C */  lwc1  $f8, 0x3c($s0)
/* 036F68 7F002438 46082281 */  sub.s $f10, $f4, $f8
/* 036F6C 7F00243C 460C3102 */  mul.s $f4, $f6, $f12
/* 036F70 7F002440 10000007 */  b     .L7F002460
/* 036F74 7F002444 46045483 */   div.s $f18, $f10, $f4
.L7F002448:
/* 036F78 7F002448 46020101 */  sub.s $f4, $f0, $f2
/* 036F7C 7F00244C C6080038 */  lwc1  $f8, 0x38($s0)
/* 036F80 7F002450 C6060034 */  lwc1  $f6, 0x34($s0)
/* 036F84 7F002454 46064281 */  sub.s $f10, $f8, $f6
/* 036F88 7F002458 460C2202 */  mul.s $f8, $f4, $f12
/* 036F8C 7F00245C 46085403 */  div.s $f16, $f10, $f8
.L7F002460:
/* 036F90 7F002460 11400018 */  beqz  $t2, .L7F0024C4
/* 036F94 7F002464 306D0010 */   andi  $t5, $v1, 0x10
/* 036F98 7F002468 C4420014 */  lwc1  $f2, 0x14($v0)
/* 036F9C 7F00246C C4400018 */  lwc1  $f0, 0x18($v0)
/* 036FA0 7F002470 4600103C */  c.lt.s $f2, $f0
/* 036FA4 7F002474 00000000 */  nop   
/* 036FA8 7F002478 45020013 */  bc1fl .L7F0024C8
/* 036FAC 7F00247C C7A00058 */   lwc1  $f0, 0x58($sp)
/* 036FB0 7F002480 8E2B0014 */  lw    $t3, 0x14($s1)
/* 036FB4 7F002484 306C0002 */  andi  $t4, $v1, 2
/* 036FB8 7F002488 11800008 */  beqz  $t4, .L7F0024AC
/* 036FBC 7F00248C C56C0014 */   lwc1  $f12, 0x14($t3)
/* 036FC0 7F002490 46020201 */  sub.s $f8, $f0, $f2
/* 036FC4 7F002494 C6060038 */  lwc1  $f6, 0x38($s0)
/* 036FC8 7F002498 C6040034 */  lwc1  $f4, 0x34($s0)
/* 036FCC 7F00249C 46043281 */  sub.s $f10, $f6, $f4
/* 036FD0 7F0024A0 460C4182 */  mul.s $f6, $f8, $f12
/* 036FD4 7F0024A4 10000007 */  b     .L7F0024C4
/* 036FD8 7F0024A8 46065403 */   div.s $f16, $f10, $f6
.L7F0024AC:
/* 036FDC 7F0024AC 46020181 */  sub.s $f6, $f0, $f2
/* 036FE0 7F0024B0 C6040040 */  lwc1  $f4, 0x40($s0)
/* 036FE4 7F0024B4 C608003C */  lwc1  $f8, 0x3c($s0)
/* 036FE8 7F0024B8 46082281 */  sub.s $f10, $f4, $f8
/* 036FEC 7F0024BC 460C3102 */  mul.s $f4, $f6, $f12
/* 036FF0 7F0024C0 46045483 */  div.s $f18, $f10, $f4
.L7F0024C4:
/* 036FF4 7F0024C4 C7A00058 */  lwc1  $f0, 0x58($sp)
.L7F0024C8:
/* 036FF8 7F0024C8 C7AC0058 */  lwc1  $f12, 0x58($sp)
/* 036FFC 7F0024CC 4600803C */  c.lt.s $f16, $f0
/* 037000 7F0024D0 00000000 */  nop   
/* 037004 7F0024D4 45020003 */  bc1fl .L7F0024E4
/* 037008 7F0024D8 4600903C */   c.lt.s $f18, $f0
/* 03700C 7F0024DC 46008006 */  mov.s $f0, $f16
/* 037010 7F0024E0 4600903C */  c.lt.s $f18, $f0
.L7F0024E4:
/* 037014 7F0024E4 00000000 */  nop   
/* 037018 7F0024E8 45020003 */  bc1fl .L7F0024F8
/* 03701C 7F0024EC 4610603C */   c.lt.s $f12, $f16
/* 037020 7F0024F0 46009006 */  mov.s $f0, $f18
/* 037024 7F0024F4 4610603C */  c.lt.s $f12, $f16
.L7F0024F8:
/* 037028 7F0024F8 46006386 */  mov.s $f14, $f12
/* 03702C 7F0024FC 306E0020 */  andi  $t6, $v1, 0x20
/* 037030 7F002500 30780040 */  andi  $t8, $v1, 0x40
/* 037034 7F002504 45020003 */  bc1fl .L7F002514
/* 037038 7F002508 4612703C */   c.lt.s $f14, $f18
/* 03703C 7F00250C 46008386 */  mov.s $f14, $f16
/* 037040 7F002510 4612703C */  c.lt.s $f14, $f18
.L7F002514:
/* 037044 7F002514 30680080 */  andi  $t0, $v1, 0x80
/* 037048 7F002518 45000002 */  bc1f  .L7F002524
/* 03704C 7F00251C 00000000 */   nop   
/* 037050 7F002520 46009386 */  mov.s $f14, $f18
.L7F002524:
/* 037054 7F002524 11A00005 */  beqz  $t5, .L7F00253C
/* 037058 7F002528 00000000 */   nop   
/* 03705C 7F00252C 46000486 */  mov.s $f18, $f0
/* 037060 7F002530 46000406 */  mov.s $f16, $f0
/* 037064 7F002534 10000031 */  b     .L7F0025FC
/* 037068 7F002538 46000306 */   mov.s $f12, $f0
.L7F00253C:
/* 03706C 7F00253C 15C0000F */  bnez  $t6, .L7F00257C
/* 037070 7F002540 306F0002 */   andi  $t7, $v1, 2
/* 037074 7F002544 C4400008 */  lwc1  $f0, 8($v0)
/* 037078 7F002548 11E00007 */  beqz  $t7, .L7F002568
/* 03707C 7F00254C C4420004 */   lwc1  $f2, 4($v0)
/* 037080 7F002550 46001032 */  c.eq.s $f2, $f0
/* 037084 7F002554 00000000 */  nop   
/* 037088 7F002558 45000008 */  bc1f  .L7F00257C
/* 03708C 7F00255C 00000000 */   nop   
/* 037090 7F002560 10000006 */  b     .L7F00257C
/* 037094 7F002564 46007306 */   mov.s $f12, $f14
.L7F002568:
/* 037098 7F002568 46001032 */  c.eq.s $f2, $f0
/* 03709C 7F00256C 00000000 */  nop   
/* 0370A0 7F002570 45000002 */  bc1f  .L7F00257C
/* 0370A4 7F002574 00000000 */   nop   
/* 0370A8 7F002578 46007306 */  mov.s $f12, $f14
.L7F00257C:
/* 0370AC 7F00257C 1700000F */  bnez  $t8, .L7F0025BC
/* 0370B0 7F002580 30790002 */   andi  $t9, $v1, 2
/* 0370B4 7F002584 C4400010 */  lwc1  $f0, 0x10($v0)
/* 0370B8 7F002588 13200007 */  beqz  $t9, .L7F0025A8
/* 0370BC 7F00258C C442000C */   lwc1  $f2, 0xc($v0)
/* 0370C0 7F002590 46001032 */  c.eq.s $f2, $f0
/* 0370C4 7F002594 00000000 */  nop   
/* 0370C8 7F002598 45000008 */  bc1f  .L7F0025BC
/* 0370CC 7F00259C 00000000 */   nop   
/* 0370D0 7F0025A0 10000006 */  b     .L7F0025BC
/* 0370D4 7F0025A4 46007486 */   mov.s $f18, $f14
.L7F0025A8:
/* 0370D8 7F0025A8 46001032 */  c.eq.s $f2, $f0
/* 0370DC 7F0025AC 00000000 */  nop   
/* 0370E0 7F0025B0 45000002 */  bc1f  .L7F0025BC
/* 0370E4 7F0025B4 00000000 */   nop   
/* 0370E8 7F0025B8 46007406 */  mov.s $f16, $f14
.L7F0025BC:
/* 0370EC 7F0025BC 1500000F */  bnez  $t0, .L7F0025FC
/* 0370F0 7F0025C0 30690002 */   andi  $t1, $v1, 2
/* 0370F4 7F0025C4 C4400018 */  lwc1  $f0, 0x18($v0)
/* 0370F8 7F0025C8 11200007 */  beqz  $t1, .L7F0025E8
/* 0370FC 7F0025CC C4420014 */   lwc1  $f2, 0x14($v0)
/* 037100 7F0025D0 46001032 */  c.eq.s $f2, $f0
/* 037104 7F0025D4 00000000 */  nop   
/* 037108 7F0025D8 45020009 */  bc1fl .L7F002600
/* 03710C 7F0025DC 460E6303 */   div.s $f12, $f12, $f14
/* 037110 7F0025E0 10000006 */  b     .L7F0025FC
/* 037114 7F0025E4 46007406 */   mov.s $f16, $f14
.L7F0025E8:
/* 037118 7F0025E8 46001032 */  c.eq.s $f2, $f0
/* 03711C 7F0025EC 00000000 */  nop   
/* 037120 7F0025F0 45020003 */  bc1fl .L7F002600
/* 037124 7F0025F4 460E6303 */   div.s $f12, $f12, $f14
/* 037128 7F0025F8 46007486 */  mov.s $f18, $f14
.L7F0025FC:
/* 03712C 7F0025FC 460E6303 */  div.s $f12, $f12, $f14
.L7F002600:
/* 037130 7F002600 3C018005 */  lui    $at, %hi(D_8004EEB4)
/* 037134 7F002604 C420EEB4 */  lwc1  $f0, %lo(D_8004EEB4)($at)
/* 037138 7F002608 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 03713C 7F00260C 460E8403 */  div.s $f16, $f16, $f14
/* 037140 7F002610 4600603E */  c.le.s $f12, $f0
/* 037144 7F002614 00000000 */  nop   
/* 037148 7F002618 45010009 */  bc1t  .L7F002640
/* 03714C 7F00261C 460E9483 */   div.s $f18, $f18, $f14
/* 037150 7F002620 4600803E */  c.le.s $f16, $f0
/* 037154 7F002624 00000000 */  nop   
/* 037158 7F002628 45030006 */  bc1tl .L7F002644
/* 03715C 7F00262C 44816000 */   mtc1  $at, $f12
/* 037160 7F002630 4600903E */  c.le.s $f18, $f0
/* 037164 7F002634 00000000 */  nop   
/* 037168 7F002638 45020006 */  bc1fl .L7F002654
/* 03716C 7F00263C E7AE0048 */   swc1  $f14, 0x48($sp)
.L7F002640:
/* 037170 7F002640 44816000 */  mtc1  $at, $f12
.L7F002644:
/* 037174 7F002644 00000000 */  nop   
/* 037178 7F002648 46006486 */  mov.s $f18, $f12
/* 03717C 7F00264C 46006406 */  mov.s $f16, $f12
/* 037180 7F002650 E7AE0048 */  swc1  $f14, 0x48($sp)
.L7F002654:
/* 037184 7F002654 E7B00054 */  swc1  $f16, 0x54($sp)
/* 037188 7F002658 0FC1626D */  jal   matrix_column_1_scalar_multiply
/* 03718C 7F00265C E7B20050 */   swc1  $f18, 0x50($sp)
/* 037190 7F002660 C7AC0054 */  lwc1  $f12, 0x54($sp)
/* 037194 7F002664 0FC16279 */  jal   matrix_column_2_scalar_multiply
/* 037198 7F002668 27A5008C */   addiu $a1, $sp, 0x8c
/* 03719C 7F00266C C7AC0050 */  lwc1  $f12, 0x50($sp)
/* 0371A0 7F002670 0FC16293 */  jal   matrix_column_3_scalar_multiply_2
/* 0371A4 7F002674 27A5008C */   addiu $a1, $sp, 0x8c
/* 0371A8 7F002678 8E240014 */  lw    $a0, 0x14($s1)
/* 0371AC 7F00267C C7AE0048 */  lwc1  $f14, 0x48($sp)
/* 0371B0 7F002680 C4860014 */  lwc1  $f6, 0x14($a0)
/* 0371B4 7F002684 460E3282 */  mul.s $f10, $f6, $f14
/* 0371B8 7F002688 44055000 */  mfc1  $a1, $f10
/* 0371BC 7F00268C 0FC1B39E */  jal   modelSetScale
/* 0371C0 7F002690 00000000 */   nop   
.L7F002694:
/* 0371C4 7F002694 8E240014 */  lw    $a0, 0x14($s1)
.L7F002698:
/* 0371C8 7F002698 C7A80078 */  lwc1  $f8, 0x78($sp)
/* 0371CC 7F00269C C4840014 */  lwc1  $f4, 0x14($a0)
/* 0371D0 7F0026A0 46082182 */  mul.s $f6, $f4, $f8
/* 0371D4 7F0026A4 44053000 */  mfc1  $a1, $f6
/* 0371D8 7F0026A8 0FC1B39E */  jal   modelSetScale
/* 0371DC 7F0026AC 00000000 */   nop   
/* 0371E0 7F0026B0 8E2A0014 */  lw    $t2, 0x14($s1)
/* 0371E4 7F0026B4 27A5008C */  addiu $a1, $sp, 0x8c
/* 0371E8 7F0026B8 0FC1629F */  jal   matrix_scalar_multiply
/* 0371EC 7F0026BC C54C0014 */   lwc1  $f12, 0x14($t2)
/* 0371F0 7F0026C0 8E2B0008 */  lw    $t3, 8($s1)
/* 0371F4 7F0026C4 02202025 */  move  $a0, $s1
/* 0371F8 7F0026C8 27A500E0 */  addiu $a1, $sp, 0xe0
/* 0371FC 7F0026CC 316C0002 */  andi  $t4, $t3, 2
/* 037200 7F0026D0 1180000A */  beqz  $t4, .L7F0026FC
/* 037204 7F0026D4 27A6008C */   addiu $a2, $sp, 0x8c
/* 037208 7F0026D8 27AD0080 */  addiu $t5, $sp, 0x80
/* 03720C 7F0026DC AFAD0010 */  sw    $t5, 0x10($sp)
/* 037210 7F0026E0 02202025 */  move  $a0, $s1
/* 037214 7F0026E4 27A500E0 */  addiu $a1, $sp, 0xe0
/* 037218 7F0026E8 27A6008C */  addiu $a2, $sp, 0x8c
/* 03721C 7F0026EC 0FC102E8 */  jal   sub_GAME_7F040BA0
/* 037220 7F0026F0 8FA700DC */   lw    $a3, 0xdc($sp)
/* 037224 7F0026F4 10000005 */  b     .L7F00270C
/* 037228 7F0026F8 00000000 */   nop   
.L7F0026FC:
/* 03722C 7F0026FC 27AE0080 */  addiu $t6, $sp, 0x80
/* 037230 7F002700 AFAE0010 */  sw    $t6, 0x10($sp)
/* 037234 7F002704 0FC10223 */  jal   sub_GAME_7F04088C
/* 037238 7F002708 8FA700DC */   lw    $a3, 0xdc($sp)
.L7F00270C:
/* 03723C 7F00270C 0FC15B28 */  jal   setupUpdateObjectRoomPosition
/* 037240 7F002710 02202025 */   move  $a0, $s1
/* 037244 7F002714 0FC0E929 */  jal   chrpropActivate
/* 037248 7F002718 8FA40060 */   lw    $a0, 0x60($sp)
/* 03724C 7F00271C 0FC0E901 */  jal   chrpropEnable
/* 037250 7F002720 8FA40060 */   lw    $a0, 0x60($sp)
.L7F002724:
/* 037254 7F002724 8FBF0034 */  lw    $ra, 0x34($sp)
.L7F002728:
/* 037258 7F002728 8FB0002C */  lw    $s0, 0x2c($sp)
/* 03725C 7F00272C 8FB10030 */  lw    $s1, 0x30($sp)
/* 037260 7F002730 03E00008 */  jr    $ra
/* 037264 7F002734 27BD00F8 */   addiu $sp, $sp, 0xf8
)
#endif


#ifdef NONMATCHING
void weaponAssignToHome(s32 arg0, WeaponObjRecord* weapon, s32 cmdindex)
{
    if ((weapon->flags & PROPFLAG_ASSIGNEDTOCHR)) {
        
        ChrRecord* chr = chrFindByLiteralId(weapon->pad);
        
        if (chr && chr->prop && chr->model) {
            if (cheatIsActive(CHEAT_ENEMY_ROCKETS))
            {
                switch ((s8)weapon->weaponnum)
                {
                case ITEM_KNIFE:
                case ITEM_THROWKNIFE:
                case ITEM_WPPK:
                case ITEM_WPPKSIL:
                case ITEM_TT33:
                case ITEM_SKORPION:
                case ITEM_AK47:
                case ITEM_UZI:
                case ITEM_MP5K:
                case ITEM_MP5KSIL:
                case ITEM_SPECTRE:
                case ITEM_M16:
                case ITEM_FNP90:
                case ITEM_SHOTGUN:
                case ITEM_AUTOSHOT:
                case ITEM_SNIPERRIFLE:
                case ITEM_RUGER:
                case ITEM_GOLDENGUN:
                case ITEM_SILVERWPPK:
                case ITEM_GOLDWPPK:
                case ITEM_LASER:
                case ITEM_WATCHLASER:
                case ITEM_REMOTEMINE:
                case ITEM_TRIGGER:
                case ITEM_TASER:
                    weapon->weaponnum = ITEM_ROCKETLAUNCH; 
                    weapon->obj = PROP_CHRROCKETLAUNCH; 
                    weapon->extrascale = 256;
                    break;
                }
            }
            weaponLoadProjectileModels((s8)weapon->weaponnum);
            sub_GAME_7F052030(weapon, chr);
        }
    } else
    {
        bool hastoken = 1;
        bool giveweapon = 1;
        if (getPlayerCount() >= 2)
        {
            struct s_mp_weapon_set* mpweapon;
            
            *(&lastmpweaponnum) = -1;
            switch ((u8)weapon->weaponnum)
            {
            case ITEM_UNARMED + 0xF0:
            case ITEM_FIST + 0xF0:
            case ITEM_KNIFE + 0xF0:
            case ITEM_THROWKNIFE + 0xF0:
            case ITEM_WPPK + 0xF0:
            case ITEM_WPPKSIL + 0xF0:
            case ITEM_TT33 + 0xF0:
            case ITEM_SKORPION + 0xF0:
                mpweapon = getPtrMPWeaponSetData();
                *(&lastmpweaponnum) = (u8)weapon->weaponnum - 0xF0;
                
                mpweapon = &(mpweapon)[lastmpweaponnum];
                weapon->weaponnum = (u8)mpweapon->itemID;
                weapon->obj = (s16)mpweapon->propID;
                weapon->extrascale = (u16)(mpweapon->size * 256.0f);
                giveweapon = mpweapon->allowpickup;
                break;
            case ITEM_TOKEN:
                hastoken = 1;
                if (get_scenario() != SCENARIO_TLD)
                { 
                    giveweapon = 0;
                }
                break;
            }
        }
        if ((weapon->weaponnum != ITEM_UNARMED) && giveweapon)
        {
            weaponLoadProjectileModels(weapon->weaponnum);
            domakedefaultobj(arg0, weapon, cmdindex);
        }
    }
}

#else
#ifndef VERSION_EU
GLOBAL_ASM(
.late_rodata
glabel jpt_8004EEB8
.word .L7F0027C8
.word .L7F0027C8
.word .L7F0027C8
.word .L7F0027C8
.word .L7F0027C8
.word .L7F0027C8
.word .L7F0027C8
.word .L7F0027C8
.word .L7F0027C8
.word .L7F0027C8
.word .L7F0027C8
.word .L7F0027C8
.word .L7F0027C8
.word .L7F0027C8
.word .L7F0027C8
.word .L7F0027C8
.word .L7F0027C8
.word .L7F0027C8
.word .L7F0027C8
.word .L7F0027C8
.word .L7F0027C8
.word .L7F0027C8
.word .L7F0027E0
.word .L7F0027E0
.word .L7F0027E0
.word .L7F0027E0
.word .L7F0027E0
.word .L7F0027C8
.word .L7F0027C8
.word .L7F0027C8

glabel jpt_mp_ammo_crate_expansion
.word .L7F002870
.word .L7F002870
.word .L7F002870
.word .L7F002870
.word .L7F002870
.word .L7F002870
.word .L7F002870
.word .L7F002870
.text
glabel weaponAssignToHome
/* 037268 7F002738 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 03726C 7F00273C AFBF0014 */  sw    $ra, 0x14($sp)
/* 037270 7F002740 AFA40028 */  sw    $a0, 0x28($sp)
/* 037274 7F002744 AFA60030 */  sw    $a2, 0x30($sp)
/* 037278 7F002748 8CAE0008 */  lw    $t6, 8($a1)
/* 03727C 7F00274C 00A03825 */  move  $a3, $a1
/* 037280 7F002750 31CF4000 */  andi  $t7, $t6, 0x4000
/* 037284 7F002754 51E0002B */  beql  $t7, $zero, .L7F002804
/* 037288 7F002758 24050001 */   li    $a1, 1
/* 03728C 7F00275C 84A40006 */  lh    $a0, 6($a1)
/* 037290 7F002760 0FC08BF2 */  jal   chrFindByLiteralId
/* 037294 7F002764 AFA5002C */   sw    $a1, 0x2c($sp)
/* 037298 7F002768 8FA7002C */  lw    $a3, 0x2c($sp)
/* 03729C 7F00276C 1040008A */  beqz  $v0, .L7F002998
/* 0372A0 7F002770 AFA2001C */   sw    $v0, 0x1c($sp)
/* 0372A4 7F002774 8C580018 */  lw    $t8, 0x18($v0)
/* 0372A8 7F002778 53000088 */  beql  $t8, $zero, .L7F00299C
/* 0372AC 7F00277C 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0372B0 7F002780 8C59001C */  lw    $t9, 0x1c($v0)
/* 0372B4 7F002784 2404001C */  li    $a0, 28
/* 0372B8 7F002788 53200084 */  beql  $t9, $zero, .L7F00299C
/* 0372BC 7F00278C 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0372C0 7F002790 0FC249EF */  jal   cheatIsActive
/* 0372C4 7F002794 AFA7002C */   sw    $a3, 0x2c($sp)
/* 0372C8 7F002798 10400011 */  beqz  $v0, .L7F0027E0
/* 0372CC 7F00279C 8FA7002C */   lw    $a3, 0x2c($sp)
/* 0372D0 7F0027A0 80E80080 */  lb    $t0, 0x80($a3)
/* 0372D4 7F0027A4 2509FFFE */  addiu $t1, $t0, -2
/* 0372D8 7F0027A8 2D21001E */  sltiu $at, $t1, 0x1e
/* 0372DC 7F0027AC 1020000C */  beqz  $at, .L7F0027E0
/* 0372E0 7F0027B0 00094880 */   sll   $t1, $t1, 2
/* 0372E4 7F0027B4 3C018005 */  lui   $at, %hi(jpt_8004EEB8)
/* 0372E8 7F0027B8 00290821 */  addu  $at, $at, $t1
/* 0372EC 7F0027BC 8C29EEB8 */  lw    $t1, %lo(jpt_8004EEB8)($at)
/* 0372F0 7F0027C0 01200008 */  jr    $t1
/* 0372F4 7F0027C4 00000000 */   nop   
.L7F0027C8:
/* 0372F8 7F0027C8 240A0019 */  li    $t2, 25
/* 0372FC 7F0027CC 240B00D3 */  li    $t3, 211
/* 037300 7F0027D0 240C0100 */  li    $t4, 256
/* 037304 7F0027D4 A0EA0080 */  sb    $t2, 0x80($a3)
/* 037308 7F0027D8 A4EB0004 */  sh    $t3, 4($a3)
/* 03730C 7F0027DC A4EC0000 */  sh    $t4, ($a3)
.L7F0027E0:
/* 037310 7F0027E0 80E40080 */  lb    $a0, 0x80($a3)
/* 037314 7F0027E4 0FC015C4 */  jal   weaponLoadProjectileModels
/* 037318 7F0027E8 AFA7002C */   sw    $a3, 0x2c($sp)
/* 03731C 7F0027EC 8FA4002C */  lw    $a0, 0x2c($sp)
/* 037320 7F0027F0 0FC1480C */  jal   sub_GAME_7F052030
/* 037324 7F0027F4 8FA5001C */   lw    $a1, 0x1c($sp)
/* 037328 7F0027F8 10000068 */  b     .L7F00299C
/* 03732C 7F0027FC 8FBF0014 */   lw    $ra, 0x14($sp)
/* 037330 7F002800 24050001 */  li    $a1, 1
.L7F002804:
/* 037334 7F002804 AFA50018 */  sw    $a1, 0x18($sp)
/* 037338 7F002808 0FC26919 */  jal   getPlayerCount
/* 03733C 7F00280C AFA7002C */   sw    $a3, 0x2c($sp)
/* 037340 7F002810 28410002 */  slti  $at, $v0, 2
/* 037344 7F002814 8FA50018 */  lw    $a1, 0x18($sp)
/* 037348 7F002818 14200054 */  bnez  $at, .L7F00296C
/* 03734C 7F00281C 8FA7002C */   lw    $a3, 0x2c($sp)
/* 037350 7F002820 240DFFFF */  li    $t5, -1
/* 037354 7F002824 3C018007 */  lui   $at, %hi(lastmpweaponnum)
/* 037358 7F002828 AC2D9540 */  sw    $t5, %lo(lastmpweaponnum)($at)
/* 03735C 7F00282C 90E20080 */  lbu   $v0, 0x80($a3)
/* 037360 7F002830 28410059 */  slti  $at, $v0, 0x59
/* 037364 7F002834 14200009 */  bnez  $at, .L7F00285C
/* 037368 7F002838 244EFF10 */   addiu $t6, $v0, -0xf0
/* 03736C 7F00283C 2DC10008 */  sltiu $at, $t6, 8
/* 037370 7F002840 1020004A */  beqz  $at, .L7F00296C
/* 037374 7F002844 000E7080 */   sll   $t6, $t6, 2
/* 037378 7F002848 3C018005 */  lui   $at, %hi(jpt_mp_ammo_crate_expansion)
/* 03737C 7F00284C 002E0821 */  addu  $at, $at, $t6
/* 037380 7F002850 8C2EEF30 */  lw    $t6, %lo(jpt_mp_ammo_crate_expansion)($at)
/* 037384 7F002854 01C00008 */  jr    $t6
/* 037388 7F002858 00000000 */   nop   
.L7F00285C:
/* 03738C 7F00285C 24010058 */  li    $at, 88
/* 037390 7F002860 5041003B */  beql  $v0, $at, .L7F002950
/* 037394 7F002864 AFA50018 */   sw    $a1, 0x18($sp)
/* 037398 7F002868 10000041 */  b     .L7F002970
/* 03739C 7F00286C 80E40080 */   lb    $a0, 0x80($a3)
.L7F002870:
/* 0373A0 7F002870 0FC31985 */  jal   getPtrMPWeaponSetData
/* 0373A4 7F002874 AFA7002C */   sw    $a3, 0x2c($sp)
/* 0373A8 7F002878 8FA7002C */  lw    $a3, 0x2c($sp)
/* 0373AC 7F00287C 3C018007 */  lui   $at, %hi(lastmpweaponnum)
/* 0373B0 7F002880 24090001 */  li    $t1, 1
/* 0373B4 7F002884 90E40080 */  lbu   $a0, 0x80($a3)
/* 0373B8 7F002888 2484FF10 */  addiu $a0, $a0, -0xf0
/* 0373BC 7F00288C 00047880 */  sll   $t7, $a0, 2
/* 0373C0 7F002890 01E47823 */  subu  $t7, $t7, $a0
/* 0373C4 7F002894 000F78C0 */  sll   $t7, $t7, 3
/* 0373C8 7F002898 AC249540 */  sw    $a0, %lo(lastmpweaponnum)($at)
/* 0373CC 7F00289C 004F1821 */  addu  $v1, $v0, $t7
/* 0373D0 7F0028A0 8C780000 */  lw    $t8, ($v1)
/* 0373D4 7F0028A4 3C014380 */  li    $at, 0x43800000 # 256.000000
/* 0373D8 7F0028A8 44813000 */  mtc1  $at, $f6
/* 0373DC 7F0028AC A0F80080 */  sb    $t8, 0x80($a3)
/* 0373E0 7F0028B0 8C790004 */  lw    $t9, 4($v1)
/* 0373E4 7F0028B4 3C014F00 */  li    $at, 0x4F000000 # 2147483648.000000
/* 0373E8 7F0028B8 A4F90004 */  sh    $t9, 4($a3)
/* 0373EC 7F0028BC C4640008 */  lwc1  $f4, 8($v1)
/* 0373F0 7F0028C0 46062202 */  mul.s $f8, $f4, $f6
/* 0373F4 7F0028C4 4448F800 */  cfc1  $t0, $31
/* 0373F8 7F0028C8 44C9F800 */  ctc1  $t1, $31
/* 0373FC 7F0028CC 00000000 */  nop   
/* 037400 7F0028D0 460042A4 */  cvt.w.s $f10, $f8
/* 037404 7F0028D4 4449F800 */  cfc1  $t1, $31
/* 037408 7F0028D8 00000000 */  nop   
/* 03740C 7F0028DC 31290078 */  andi  $t1, $t1, 0x78
/* 037410 7F0028E0 51200013 */  beql  $t1, $zero, .L7F002930
/* 037414 7F0028E4 44095000 */   mfc1  $t1, $f10
/* 037418 7F0028E8 44815000 */  mtc1  $at, $f10
/* 03741C 7F0028EC 24090001 */  li    $t1, 1
/* 037420 7F0028F0 460A4281 */  sub.s $f10, $f8, $f10
/* 037424 7F0028F4 44C9F800 */  ctc1  $t1, $31
/* 037428 7F0028F8 00000000 */  nop   
/* 03742C 7F0028FC 460052A4 */  cvt.w.s $f10, $f10
/* 037430 7F002900 4449F800 */  cfc1  $t1, $31
/* 037434 7F002904 00000000 */  nop   
/* 037438 7F002908 31290078 */  andi  $t1, $t1, 0x78
/* 03743C 7F00290C 15200005 */  bnez  $t1, .L7F002924
/* 037440 7F002910 00000000 */   nop   
/* 037444 7F002914 44095000 */  mfc1  $t1, $f10
/* 037448 7F002918 3C018000 */  lui   $at, 0x8000
/* 03744C 7F00291C 10000007 */  b     .L7F00293C
/* 037450 7F002920 01214825 */   or    $t1, $t1, $at
.L7F002924:
/* 037454 7F002924 10000005 */  b     .L7F00293C
/* 037458 7F002928 2409FFFF */   li    $t1, -1
/* 03745C 7F00292C 44095000 */  mfc1  $t1, $f10
.L7F002930:
/* 037460 7F002930 00000000 */  nop   
/* 037464 7F002934 0520FFFB */  bltz  $t1, .L7F002924
/* 037468 7F002938 00000000 */   nop   
.L7F00293C:
/* 03746C 7F00293C 44C8F800 */  ctc1  $t0, $31
/* 037470 7F002940 A4E90000 */  sh    $t1, ($a3)
/* 037474 7F002944 10000009 */  b     .L7F00296C
/* 037478 7F002948 8C650014 */   lw    $a1, 0x14($v1)
/* 03747C 7F00294C AFA50018 */  sw    $a1, 0x18($sp)
.L7F002950:
/* 037480 7F002950 0FC051D6 */  jal   get_scenario
/* 037484 7F002954 AFA7002C */   sw    $a3, 0x2c($sp)
/* 037488 7F002958 24010002 */  li    $at, 2
/* 03748C 7F00295C 8FA50018 */  lw    $a1, 0x18($sp)
/* 037490 7F002960 10410002 */  beq   $v0, $at, .L7F00296C
/* 037494 7F002964 8FA7002C */   lw    $a3, 0x2c($sp)
/* 037498 7F002968 00002825 */  move  $a1, $zero
def_7F002854:
.L7F00296C:
/* 03749C 7F00296C 80E40080 */  lb    $a0, 0x80($a3)
.L7F002970:
/* 0374A0 7F002970 5080000A */  beql  $a0, $zero, .L7F00299C
/* 0374A4 7F002974 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0374A8 7F002978 50A00008 */  beql  $a1, $zero, .L7F00299C
/* 0374AC 7F00297C 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0374B0 7F002980 0FC015C4 */  jal   weaponLoadProjectileModels
/* 0374B4 7F002984 AFA7002C */   sw    $a3, 0x2c($sp)
/* 0374B8 7F002988 8FA5002C */  lw    $a1, 0x2c($sp)
/* 0374BC 7F00298C 8FA40028 */  lw    $a0, 0x28($sp)
/* 0374C0 7F002990 0FC00767 */  jal   domakedefaultobj
/* 0374C4 7F002994 8FA60030 */   lw    $a2, 0x30($sp)
.L7F002998:
/* 0374C8 7F002998 8FBF0014 */  lw    $ra, 0x14($sp)
.L7F00299C:
/* 0374CC 7F00299C 27BD0028 */  addiu $sp, $sp, 0x28
/* 0374D0 7F0029A0 03E00008 */  jr    $ra
/* 0374D4 7F0029A4 00000000 */   nop   
)
#endif
#ifdef VERSION_EU
GLOBAL_ASM(
.late_rodata
glabel jpt_8004EEB8
.word .L7F0027C8
.word .L7F0027C8
.word .L7F0027C8
.word .L7F0027C8
.word .L7F0027C8
.word .L7F0027C8
.word .L7F0027C8
.word .L7F0027C8
.word .L7F0027C8
.word .L7F0027C8
.word .L7F0027C8
.word .L7F0027C8
.word .L7F0027C8
.word .L7F0027C8
.word .L7F0027C8
.word .L7F0027C8
.word .L7F0027C8
.word .L7F0027C8
.word .L7F0027C8
.word .L7F0027C8
.word .L7F0027C8
.word .L7F0027C8
.word .L7F0027E0
.word .L7F0027E0
.word .L7F0027E0
.word .L7F0027E0
.word .L7F0027E0
.word .L7F0027C8
.word .L7F0027C8
.word .L7F0027C8
glabel jpt_mp_ammo_crate_expansion
.word .L7F002870
.word .L7F002870
.word .L7F002870
.word .L7F002870
.word .L7F002870
.word .L7F002870
.word .L7F002870
.word .L7F002870
.text
glabel weaponAssignToHome
/* 035128 7F002738 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 03512C 7F00273C AFBF0014 */  sw    $ra, 0x14($sp)
/* 035130 7F002740 AFA40028 */  sw    $a0, 0x28($sp)
/* 035134 7F002744 AFA60030 */  sw    $a2, 0x30($sp)
/* 035138 7F002748 8CAE0008 */  lw    $t6, 8($a1)
/* 03513C 7F00274C 00A03825 */  move  $a3, $a1
/* 035140 7F002750 31CF4000 */  andi  $t7, $t6, 0x4000
/* 035144 7F002754 51E0002B */  beql  $t7, $zero, .L7F002804
/* 035148 7F002758 24050001 */   li    $a1, 1
/* 03514C 7F00275C 84A40006 */  lh    $a0, 6($a1)
/* 035150 7F002760 0FC08BE4 */  jal   chrFindByLiteralId
/* 035154 7F002764 AFA5002C */   sw    $a1, 0x2c($sp)
/* 035158 7F002768 8FA7002C */  lw    $a3, 0x2c($sp)
/* 03515C 7F00276C 10400064 */  beqz  $v0, .L7F002900
/* 035160 7F002770 AFA2001C */   sw    $v0, 0x1c($sp)
/* 035164 7F002774 8C580018 */  lw    $t8, 0x18($v0)
/* 035168 7F002778 53000062 */  beql  $t8, $zero, .L7F002904
/* 03516C 7F00277C 8FBF0014 */   lw    $ra, 0x14($sp)
/* 035170 7F002780 8C59001C */  lw    $t9, 0x1c($v0)
/* 035174 7F002784 2404001C */  li    $a0, 28
/* 035178 7F002788 5320005E */  beql  $t9, $zero, .L7F002904
/* 03517C 7F00278C 8FBF0014 */   lw    $ra, 0x14($sp)
/* 035180 7F002790 0FC24737 */  jal   cheatIsActive
/* 035184 7F002794 AFA7002C */   sw    $a3, 0x2c($sp)
/* 035188 7F002798 10400011 */  beqz  $v0, .L7F0027E0
/* 03518C 7F00279C 8FA7002C */   lw    $a3, 0x2c($sp)
/* 035190 7F0027A0 80E80080 */  lb    $t0, 0x80($a3)
/* 035194 7F0027A4 2509FFFE */  addiu $t1, $t0, -2
/* 035198 7F0027A8 2D21001E */  sltiu $at, $t1, 0x1e
/* 03519C 7F0027AC 1020000C */  beqz  $at, .L7F0027E0
/* 0351A0 7F0027B0 00094880 */   sll   $t1, $t1, 2
/* 0351A4 7F0027B4 3C018004 */  lui   $at, %hi(jpt_8004EEB8)
/* 0351A8 7F0027B8 00290821 */  addu  $at, $at, $t1
/* 0351AC 7F0027BC 8C2972F8 */  lw    $t1, %lo(jpt_8004EEB8)($at)
/* 0351B0 7F0027C0 01200008 */  jr    $t1
/* 0351B4 7F0027C4 00000000 */   nop   
.L7F0027C8:
/* 0351B8 7F0027C8 240A0019 */  li    $t2, 25
/* 0351BC 7F0027CC 240B00D3 */  li    $t3, 211
/* 0351C0 7F0027D0 240C0100 */  li    $t4, 256
/* 0351C4 7F0027D4 A0EA0080 */  sb    $t2, 0x80($a3)
/* 0351C8 7F0027D8 A4EB0004 */  sh    $t3, 4($a3)
/* 0351CC 7F0027DC A4EC0000 */  sh    $t4, ($a3)
.L7F0027E0:
/* 0351D0 7F0027E0 80E40080 */  lb    $a0, 0x80($a3)
/* 0351D4 7F0027E4 0FC015AC */  jal   weaponLoadProjectileModels
/* 0351D8 7F0027E8 AFA7002C */   sw    $a3, 0x2c($sp)
/* 0351DC 7F0027EC 8FA4002C */  lw    $a0, 0x2c($sp)
/* 0351E0 7F0027F0 0FC148C4 */  jal   sub_GAME_7F052030
/* 0351E4 7F0027F4 8FA5001C */   lw    $a1, 0x1c($sp)
/* 0351E8 7F0027F8 10000042 */  b     .L7F002904
/* 0351EC 7F0027FC 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0351F0 7F002800 24050001 */  li    $a1, 1
.L7F002804:
/* 0351F4 7F002804 AFA50018 */  sw    $a1, 0x18($sp)
/* 0351F8 7F002808 0FC26669 */  jal   getPlayerCount
/* 0351FC 7F00280C AFA7002C */   sw    $a3, 0x2c($sp)
/* 035200 7F002810 28410002 */  slti  $at, $v0, 2
/* 035204 7F002814 8FA50018 */  lw    $a1, 0x18($sp)
/* 035208 7F002818 1420002E */  bnez  $at, .L7F0028D4
/* 03520C 7F00281C 8FA7002C */   lw    $a3, 0x2c($sp)
/* 035210 7F002820 240DFFFF */  li    $t5, -1
/* 035214 7F002824 3C018006 */  lui   $at, %hi(lastmpweaponnum) # $at, 0x8006
/* 035218 7F002828 AC2D8480 */  sw    $t5, %lo(lastmpweaponnum)($at)
/* 03521C 7F00282C 90E20080 */  lbu   $v0, 0x80($a3)
/* 035220 7F002830 28410059 */  slti  $at, $v0, 0x59
/* 035224 7F002834 14200009 */  bnez  $at, .L7F00285C
/* 035228 7F002838 244EFF10 */   addiu $t6, $v0, -0xf0
/* 03522C 7F00283C 2DC10008 */  sltiu $at, $t6, 8
/* 035230 7F002840 10200024 */  beqz  $at, .L7F0028D4
/* 035234 7F002844 000E7080 */   sll   $t6, $t6, 2
/* 035238 7F002848 3C018004 */  lui   $at, %hi(jpt_mp_ammo_crate_expansion)
/* 03523C 7F00284C 002E0821 */  addu  $at, $at, $t6
/* 035240 7F002850 8C2E7370 */  lw    $t6, %lo(jpt_mp_ammo_crate_expansion)($at)
/* 035244 7F002854 01C00008 */  jr    $t6
/* 035248 7F002858 00000000 */   nop   
.L7F00285C:
/* 03524C 7F00285C 24010058 */  li    $at, 88
/* 035250 7F002860 50410015 */  beql  $v0, $at, .L7F0028B8
/* 035254 7F002864 AFA50018 */   sw    $a1, 0x18($sp)
/* 035258 7F002868 1000001B */  b     .L7F0028D8
/* 03525C 7F00286C 80E40080 */   lb    $a0, 0x80($a3)
.L7F002870:
/* 035260 7F002870 0FC316CD */  jal   getPtrMPWeaponSetData
/* 035264 7F002874 AFA7002C */   sw    $a3, 0x2c($sp)
/* 035268 7F002878 8FA7002C */  lw    $a3, 0x2c($sp)
/* 03526C 7F00287C 3C018006 */  lui   $at, %hi(lastmpweaponnum) # $at, 0x8006
/* 035270 7F002880 90E40080 */  lbu   $a0, 0x80($a3)
/* 035274 7F002884 2484FF10 */  addiu $a0, $a0, -0xf0
/* 035278 7F002888 000478C0 */  sll   $t7, $a0, 3
/* 03527C 7F00288C AC248480 */  sw    $a0, %lo(lastmpweaponnum)($at)
/* 035280 7F002890 004F1821 */  addu  $v1, $v0, $t7
/* 035284 7F002894 80780000 */  lb    $t8, ($v1)
/* 035288 7F002898 A0F80080 */  sb    $t8, 0x80($a3)
/* 03528C 7F00289C 84790004 */  lh    $t9, 4($v1)
/* 035290 7F0028A0 A4F90004 */  sh    $t9, 4($a3)
/* 035294 7F0028A4 84680006 */  lh    $t0, 6($v1)
/* 035298 7F0028A8 A4E80000 */  sh    $t0, ($a3)
/* 03529C 7F0028AC 10000009 */  b     .L7F0028D4
/* 0352A0 7F0028B0 80650003 */   lb    $a1, 3($v1)
/* 0352A4 7F0028B4 AFA50018 */  sw    $a1, 0x18($sp)
.L7F0028B8:
/* 0352A8 7F0028B8 0FC051B2 */  jal   get_scenario
/* 0352AC 7F0028BC AFA7002C */   sw    $a3, 0x2c($sp)
/* 0352B0 7F0028C0 24010002 */  li    $at, 2
/* 0352B4 7F0028C4 8FA50018 */  lw    $a1, 0x18($sp)
/* 0352B8 7F0028C8 10410002 */  beq   $v0, $at, .L7F0028D4
/* 0352BC 7F0028CC 8FA7002C */   lw    $a3, 0x2c($sp)
/* 0352C0 7F0028D0 00002825 */  move  $a1, $zero
.L7F0028D4:
/* 0352C4 7F0028D4 80E40080 */  lb    $a0, 0x80($a3)
.L7F0028D8:
/* 0352C8 7F0028D8 5080000A */  beql  $a0, $zero, .L7F002904
/* 0352CC 7F0028DC 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0352D0 7F0028E0 50A00008 */  beql  $a1, $zero, .L7F002904
/* 0352D4 7F0028E4 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0352D8 7F0028E8 0FC015AC */  jal   weaponLoadProjectileModels
/* 0352DC 7F0028EC AFA7002C */   sw    $a3, 0x2c($sp)
/* 0352E0 7F0028F0 8FA5002C */  lw    $a1, 0x2c($sp)
/* 0352E4 7F0028F4 8FA40028 */  lw    $a0, 0x28($sp)
/* 0352E8 7F0028F8 0FC00767 */  jal   domakedefaultobj
/* 0352EC 7F0028FC 8FA60030 */   lw    $a2, 0x30($sp)
.L7F002900:
/* 0352F0 7F002900 8FBF0014 */  lw    $ra, 0x14($sp)
.L7F002904:
/* 0352F4 7F002904 27BD0028 */  addiu $sp, $sp, 0x28
/* 0352F8 7F002908 03E00008 */  jr    $ra
/* 0352FC 7F00290C 00000000 */   nop   
)
#endif
#endif

//i should be object hat
void setupHat(s32 arg0, ObjectRecord* hat, s32 cmdindex)
{
    if (hat->flags & PROPFLAG_ASSIGNEDTOCHR) {
        ChrRecord* chr = chrFindByLiteralId(hat->pad);
        if (chr && chr->prop && chr->model) {
            hatAssignToChr(hat, chr);
        }
    } else {
        domakedefaultobj(arg0, hat, cmdindex);
    }
}

//i should be object key
void setupKey(s32 arg0, ObjectRecord* key, s32 cmdindex)
{
    domakedefaultobj(arg0, key, cmdindex);
}



#ifdef NONMATCHING
void setupCctv(void) {

}
#else
GLOBAL_ASM(
.late_rodata
glabel D_8004EF50
.word 0x40c90fdb


.text
glabel setupCctv
/* 03756C 7F002A3C 27BDFFA8 */  addiu $sp, $sp, -0x58
/* 037570 7F002A40 AFBF0034 */  sw    $ra, 0x34($sp)
/* 037574 7F002A44 AFB00030 */  sw    $s0, 0x30($sp)
/* 037578 7F002A48 0FC00767 */  jal   domakedefaultobj
/* 03757C 7F002A4C 00A08025 */   move  $s0, $a1
/* 037580 7F002A50 8E020080 */  lw    $v0, 0x80($s0)
/* 037584 7F002A54 0442007C */  bltzl $v0, .L7F002C48
/* 037588 7F002A58 8FBF0034 */   lw    $ra, 0x34($sp)
/* 03758C 7F002A5C 8E0E0014 */  lw    $t6, 0x14($s0)
/* 037590 7F002A60 00025100 */  sll   $t2, $v0, 4
/* 037594 7F002A64 28412710 */  slti  $at, $v0, 0x2710
/* 037598 7F002A68 8DCF0008 */  lw    $t7, 8($t6)
/* 03759C 7F002A6C 00024080 */  sll   $t0, $v0, 2
/* 0375A0 7F002A70 01425021 */  addu  $t2, $t2, $v0
/* 0375A4 7F002A74 8DF80008 */  lw    $t8, 8($t7)
/* 0375A8 7F002A78 01024023 */  subu  $t0, $t0, $v0
/* 0375AC 7F002A7C 000A5080 */  sll   $t2, $t2, 2
/* 0375B0 7F002A80 8F190000 */  lw    $t9, ($t8)
/* 0375B4 7F002A84 3C0B8007 */  lui   $t3, %hi(g_CurrentSetup+0x1C) 
/* 0375B8 7F002A88 10200008 */  beqz  $at, .L7F002AAC
/* 0375BC 7F002A8C 8F260004 */   lw    $a2, 4($t9)
/* 0375C0 7F002A90 00084080 */  sll   $t0, $t0, 2
/* 0375C4 7F002A94 3C098007 */  lui   $t1, %hi(g_CurrentSetup+0x18) 
/* 0375C8 7F002A98 8D295D18 */  lw    $t1, %lo(g_CurrentSetup+0x18)($t1)
/* 0375CC 7F002A9C 01024023 */  subu  $t0, $t0, $v0
/* 0375D0 7F002AA0 00084080 */  sll   $t0, $t0, 2
/* 0375D4 7F002AA4 10000006 */  b     .L7F002AC0
/* 0375D8 7F002AA8 01091821 */   addu  $v1, $t0, $t1
.L7F002AAC:
/* 0375DC 7F002AAC 8D6B5D1C */  lw    $t3, %lo(g_CurrentSetup+0x1C)($t3)
/* 0375E0 7F002AB0 3C01FFF5 */  lui   $at, (0xFFF59FC0 >> 16) # lui $at, 0xfff5
/* 0375E4 7F002AB4 34219FC0 */  ori   $at, (0xFFF59FC0 & 0xFFFF) # ori $at, $at, 0x9fc0
/* 0375E8 7F002AB8 014B1821 */  addu  $v1, $t2, $t3
/* 0375EC 7F002ABC 00611821 */  addu  $v1, $v1, $at
.L7F002AC0:
/* 0375F0 7F002AC0 C4C40000 */  lwc1  $f4, ($a2)
/* 0375F4 7F002AC4 26040018 */  addiu $a0, $s0, 0x18
/* 0375F8 7F002AC8 27A50044 */  addiu $a1, $sp, 0x44
/* 0375FC 7F002ACC E7A40044 */  swc1  $f4, 0x44($sp)
/* 037600 7F002AD0 C4C60004 */  lwc1  $f6, 4($a2)
/* 037604 7F002AD4 E7A60048 */  swc1  $f6, 0x48($sp)
/* 037608 7F002AD8 C4C80008 */  lwc1  $f8, 8($a2)
/* 03760C 7F002ADC AFA30050 */  sw    $v1, 0x50($sp)
/* 037610 7F002AE0 0FC160F6 */  jal   mtx4RotateVecInPlace
/* 037614 7F002AE4 E7A8004C */   swc1  $f8, 0x4c($sp)
/* 037618 7F002AE8 8E0C0010 */  lw    $t4, 0x10($s0)
/* 03761C 7F002AEC C7AA0044 */  lwc1  $f10, 0x44($sp)
/* 037620 7F002AF0 C7A40048 */  lwc1  $f4, 0x48($sp)
/* 037624 7F002AF4 C5900008 */  lwc1  $f16, 8($t4)
/* 037628 7F002AF8 8FA30050 */  lw    $v1, 0x50($sp)
/* 03762C 7F002AFC 44800000 */  mtc1  $zero, $f0
/* 037630 7F002B00 46105480 */  add.s $f18, $f10, $f16
/* 037634 7F002B04 C7AA004C */  lwc1  $f10, 0x4c($sp)
/* 037638 7F002B08 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 03763C 7F002B0C 26040084 */  addiu $a0, $s0, 0x84
/* 037640 7F002B10 E7B20044 */  swc1  $f18, 0x44($sp)
/* 037644 7F002B14 8E0D0010 */  lw    $t5, 0x10($s0)
/* 037648 7F002B18 44050000 */  mfc1  $a1, $f0
/* 03764C 7F002B1C 44060000 */  mfc1  $a2, $f0
/* 037650 7F002B20 C5A6000C */  lwc1  $f6, 0xc($t5)
/* 037654 7F002B24 44070000 */  mfc1  $a3, $f0
/* 037658 7F002B28 46062200 */  add.s $f8, $f4, $f6
/* 03765C 7F002B2C E7A80048 */  swc1  $f8, 0x48($sp)
/* 037660 7F002B30 8E0E0010 */  lw    $t6, 0x10($s0)
/* 037664 7F002B34 C5D00010 */  lwc1  $f16, 0x10($t6)
/* 037668 7F002B38 46105100 */  add.s $f4, $f10, $f16
/* 03766C 7F002B3C E7A4004C */  swc1  $f4, 0x4c($sp)
/* 037670 7F002B40 C4660000 */  lwc1  $f6, ($v1)
/* 037674 7F002B44 46069281 */  sub.s $f10, $f18, $f6
/* 037678 7F002B48 E7AA0010 */  swc1  $f10, 0x10($sp)
/* 03767C 7F002B4C C4700004 */  lwc1  $f16, 4($v1)
/* 037680 7F002B50 46104481 */  sub.s $f18, $f8, $f16
/* 037684 7F002B54 44814000 */  mtc1  $at, $f8
/* 037688 7F002B58 E7B20014 */  swc1  $f18, 0x14($sp)
/* 03768C 7F002B5C C4660008 */  lwc1  $f6, 8($v1)
/* 037690 7F002B60 AFA4003C */  sw    $a0, 0x3c($sp)
/* 037694 7F002B64 E7A00024 */  swc1  $f0, 0x24($sp)
/* 037698 7F002B68 46062281 */  sub.s $f10, $f4, $f6
/* 03769C 7F002B6C E7A0001C */  swc1  $f0, 0x1c($sp)
/* 0376A0 7F002B70 E7A80020 */  swc1  $f8, 0x20($sp)
/* 0376A4 7F002B74 0FC16642 */  jal   matrix_4x4_7F059908
/* 0376A8 7F002B78 E7AA0018 */   swc1  $f10, 0x18($sp)
/* 0376AC 7F002B7C 8E0F0014 */  lw    $t7, 0x14($s0)
/* 0376B0 7F002B80 8FA5003C */  lw    $a1, 0x3c($sp)
/* 0376B4 7F002B84 0FC1629F */  jal   matrix_scalar_multiply
/* 0376B8 7F002B88 C5EC0014 */   lwc1  $f12, 0x14($t7)
/* 0376BC 7F002B8C 8E1800E4 */  lw    $t8, 0xe4($s0)
/* 0376C0 7F002B90 44800000 */  mtc1  $zero, $f0
/* 0376C4 7F002B94 8FA30050 */  lw    $v1, 0x50($sp)
/* 0376C8 7F002B98 5700001E */  bnezl $t8, .L7F002C14
/* 0376CC 7F002B9C C60400CC */   lwc1  $f4, 0xcc($s0)
/* 0376D0 7F002BA0 8E0800CC */  lw    $t0, 0xcc($s0)
/* 0376D4 7F002BA4 3C018005 */  lui   $at, %hi(D_8004EF50)
/* 0376D8 7F002BA8 C422EF50 */  lwc1  $f2, %lo(D_8004EF50)($at)
/* 0376DC 7F002BAC 44888000 */  mtc1  $t0, $f16
/* 0376E0 7F002BB0 3C014780 */  li    $at, 0x47800000 # 65536.000000
/* 0376E4 7F002BB4 44816000 */  mtc1  $at, $f12
/* 0376E8 7F002BB8 468084A0 */  cvt.s.w $f18, $f16
/* 0376EC 7F002BBC 8E0900D0 */  lw    $t1, 0xd0($s0)
/* 0376F0 7F002BC0 8E0A00DC */  lw    $t2, 0xdc($s0)
/* 0376F4 7F002BC4 8E0B00E8 */  lw    $t3, 0xe8($s0)
/* 0376F8 7F002BC8 44895000 */  mtc1  $t1, $f10
/* 0376FC 7F002BCC 24190001 */  li    $t9, 1
/* 037700 7F002BD0 46029102 */  mul.s $f4, $f18, $f2
/* 037704 7F002BD4 AE1900E4 */  sw    $t9, 0xe4($s0)
/* 037708 7F002BD8 46805220 */  cvt.s.w $f8, $f10
/* 03770C 7F002BDC 460C2183 */  div.s $f6, $f4, $f12
/* 037710 7F002BE0 448A2000 */  mtc1  $t2, $f4
/* 037714 7F002BE4 46024402 */  mul.s $f16, $f8, $f2
/* 037718 7F002BE8 460C8483 */  div.s $f18, $f16, $f12
/* 03771C 7F002BEC E60600CC */  swc1  $f6, 0xcc($s0)
/* 037720 7F002BF0 448B8000 */  mtc1  $t3, $f16
/* 037724 7F002BF4 468021A0 */  cvt.s.w $f6, $f4
/* 037728 7F002BF8 46023282 */  mul.s $f10, $f6, $f2
/* 03772C 7F002BFC E61200D0 */  swc1  $f18, 0xd0($s0)
/* 037730 7F002C00 468084A0 */  cvt.s.w $f18, $f16
/* 037734 7F002C04 460C5203 */  div.s $f8, $f10, $f12
/* 037738 7F002C08 E61200E8 */  swc1  $f18, 0xe8($s0)
/* 03773C 7F002C0C E60800DC */  swc1  $f8, 0xdc($s0)
/* 037740 7F002C10 C60400CC */  lwc1  $f4, 0xcc($s0)
.L7F002C14:
/* 037744 7F002C14 AE0000D4 */  sw    $zero, 0xd4($s0)
/* 037748 7F002C18 E60000D8 */  swc1  $f0, 0xd8($s0)
/* 03774C 7F002C1C E60400C8 */  swc1  $f4, 0xc8($s0)
/* 037750 7F002C20 C4700008 */  lwc1  $f16, 8($v1)
/* 037754 7F002C24 C7A8004C */  lwc1  $f8, 0x4c($sp)
/* 037758 7F002C28 C46A0000 */  lwc1  $f10, ($v1)
/* 03775C 7F002C2C C7A60044 */  lwc1  $f6, 0x44($sp)
/* 037760 7F002C30 46104381 */  sub.s $f14, $f8, $f16
/* 037764 7F002C34 0FC16A8C */  jal   atan2f
/* 037768 7F002C38 460A3301 */   sub.s $f12, $f6, $f10
/* 03776C 7F002C3C E60000C4 */  swc1  $f0, 0xc4($s0)
/* 037770 7F002C40 AE0000E0 */  sw    $zero, 0xe0($s0)
/* 037774 7F002C44 8FBF0034 */  lw    $ra, 0x34($sp)
.L7F002C48:
/* 037778 7F002C48 8FB00030 */  lw    $s0, 0x30($sp)
/* 03777C 7F002C4C 27BD0058 */  addiu $sp, $sp, 0x58
/* 037780 7F002C50 03E00008 */  jr    $ra
/* 037784 7F002C54 00000000 */   nop   
)
#endif

void setupAutogun(s32 stageID, AutogunRecord *autogun, s32 cmdindex)
{
    s8 *beam;

    domakedefaultobj(stageID, (ObjectRecord *) autogun, cmdindex);

#ifdef VERSION_EU
    autogun->speed = ((*((s32 *) (&autogun->speed))) * 7.5398226f) / 65536.0f;
    autogun->aimdist = ((*((s32 *) (&autogun->aimdist))) * 100.0f) / 65536.0f;
    autogun->unk88 = ((*((s32 *) (&autogun->unk88))) * M_TAU_F) / 65536.0f;
    autogun->unk8C = ((*((s32 *) (&autogun->unk8C))) * M_TAU_F) / 65536.0f;
#endif

    autogun->unkAC = 0;
    autogun->unkB8 = -1;
    autogun->unkBC = -1;
    autogun->unkC0 = -1;
    autogun->unkC4 = 0;
    autogun->unkC8 = 0;
    autogun->unk90 = 0.0f;
    autogun->unk94 = 0.0f;
    autogun->rot_related = 0.0f;
    autogun->unk9C = 0.0f;
    autogun->unkA0 = 0.0f;
    autogun->unk98 = 0.0f;
    autogun->unkB0 = 0.0f;
    autogun->unkB4 = 0.0f;

#ifndef VERSION_EU
    autogun->speed = ((*((s32 *) (&autogun->speed))) * M_TAU_F) / 65536.0f;
    autogun->aimdist = ((*((s32 *) (&autogun->aimdist))) * 100.0f) / 65536.0f;
    autogun->unk88 = ((*((s32 *) (&autogun->unk88))) * M_TAU_F) / 65536.0f;
    autogun->unk8C = ((*((s32 *) (&autogun->unk8C))) * M_TAU_F) / 65536.0f;
#endif

    beam = mempAllocBytesInBank(0x30U, 4U);
    autogun->beam = beam;
    *beam = -1;

    autogun->is_active = FALSE;
    autogun->unkD4 = 0.0f;

    if (autogun->padID >= 0)
    {
        s32 stack1;
        f32 xdiff;
        f32 ydiff;
        f32 zdiff;
        PadRecord *pad;
        PropRecord *prop;

        if (autogun->padID < 0x2710)
        {
            if (1);
            pad = &g_CurrentSetup.pads[autogun->padID];
        }
        else
        {
            pad = &g_CurrentSetup.boundpads[getBoundPadNum(autogun->padID)];
        }

        prop = autogun->prop;

        xdiff = pad->pos.x - prop->pos.x;
        ydiff = pad->pos.y - prop->pos.y;
        zdiff = pad->pos.z - prop->pos.z;

        autogun->rot_related = atan2f(xdiff, zdiff);
        autogun->unk98 = atan2f(ydiff, sqrtf((xdiff * xdiff) + (zdiff * zdiff)));
    }
}


//i should be object rack
void setupHangingMonitors(s32 arg0, ObjectRecord* rack, s32 cmdindex)
{
    domakedefaultobj(arg0, rack, cmdindex);
}


void setupSingleMonitor(s32 stageID, MonitorObjRecord *monitor, s32 cmdindex)
{
    MonitorRecord *record;
    s32 unused;
    s32 modelnum;
    ObjectRecord *owner;
    PropRecord *prop;
    f32 scale;

    monitor->Monitor = g_MonitorAnimController;
    record = &monitor->Monitor;
    monitorSetImageByNum(&monitor->Monitor, monitor->ImageNum);

    if (monitor->pad < 0 && (monitor->flags & PROPFLAG_INSIDEANOTHEROBJ) == 0)
    {
        modelnum = monitor->obj;
        owner = (struct ObjectRecord *)setupGetPtrToCommandByIndex(cmdindex + monitor->OwnerOffset);

        modelLoad(modelnum);

        scale = monitor->extrascale * (1.0f / 256.0f);
        monitor->damage = *(s32*)&monitor->damage / M_U16_MAX_VALUE_F;

        if (getPlayerCount() >= 2)
        {
            monitor->state |= PROPSTATE_RESPAWN;
        }

        prop = objInitWithAutoModel((ObjectRecord*)monitor);
        monitor->embedment = embedmentAllocate();

        if (prop && monitor->embedment)
        {
            monitor->runtime_bitflags |= RUNTIMEBITFLAG_EMBEDDED;
            modelSetScale(monitor->model, monitor->model->scale * scale);
            monitor->model->attachedto = owner->model;

            if (monitor->OwnerPart == 0)
            {
                monitor->model->attachedto_objinst = owner->model->obj->Switches[0];
            }
            else if (monitor->OwnerPart == 1)
            {
                monitor->model->attachedto_objinst = owner->model->obj->Switches[1];
            }
            else if (monitor->OwnerPart == 2)
            {
                monitor->model->attachedto_objinst = owner->model->obj->Switches[2];
            }
            else
            {
                monitor->model->attachedto_objinst = owner->model->obj->Switches[3];;
            }

            chrpropReparent(prop, owner->prop);
            matrix_4x4_set_rotation_around_x(0.36651915f, (Mtxf*)&monitor->embedment->matrix);
            matrix_scalar_multiply(monitor->model->scale / owner->model->scale, (f32*)&monitor->embedment->matrix);
        }
    }
    else
    {
        domakedefaultobj(stageID, (ObjectRecord*)monitor, cmdindex);
    }

    if ((monitor->flags & PROPFLAG_MONITOR_RENDERPOSTBG) && monitor->prop)
    {
        monitor->prop->flags |= PROPFLAG_RENDERPOSTBG;
    }
}


void setupMultiMonitor(s32 stageID, MultiMonitorObjRecord* monitor, s32 cmdindex)
{
    monitor->Monitor[0] = g_MonitorAnimController;
    monitorSetImageByNum(&monitor->Monitor[0], monitor->ImageNums[0]);

    monitor->Monitor[1] = g_MonitorAnimController;
    monitorSetImageByNum(&monitor->Monitor[1], monitor->ImageNums[1]);

    monitor->Monitor[2] = g_MonitorAnimController;
    monitorSetImageByNum(&monitor->Monitor[2], monitor->ImageNums[2]);

    monitor->Monitor[3] = g_MonitorAnimController;
    monitorSetImageByNum(&monitor->Monitor[3], monitor->ImageNums[3]);

    domakedefaultobj(stageID, monitor, cmdindex);
}

void sub_GAME_7F00324C(struct BoundPadRecord *arg0, s32 *arg1, s32 *arg2, struct coord3d *arg3, struct coord3d *arg4)
{
    StandTile *sp4C;
    struct coord3d normal;    
    s32 padding;
    struct coord3d center;
    StandTile *sp2C;
    f32 scale;

    sub_GAME_7F001BD4(arg0, &center);
    sp2C = (StandTile *)arg0->stan;
    
    if (walkTilesBetweenPoints_NoCallback(&sp2C, arg0->pos.f[0], arg0->pos.f[2], center.f[0], center.f[2]) == 0)
    {
        sp2C = (StandTile *)arg0->stan;
        center.f[0] = arg0->pos.f[0];
        center.f[1] = arg0->pos.f[1];
        center.f[2] = arg0->pos.f[2];
    }

    normal.f[0] = (arg0->up.f[1] * arg0->look.f[2]) - (arg0->up.f[2] * arg0->look.f[1]);
    normal.f[1] = (arg0->up.f[2] * arg0->look.f[0]) - (arg0->up.f[0] * arg0->look.f[2]);
    normal.f[2] = (arg0->up.f[0] * arg0->look.f[1]) - (arg0->up.f[1] * arg0->look.f[0]);

    scale = 1.0f / sqrtf(((normal.f[0] * normal.f[0]) + (normal.f[1] * normal.f[1])) + (normal.f[2] * normal.f[2]));
    sp4C = sp2C;
    
    normal.f[0] *= scale;
    normal.f[1] *= scale;
    normal.f[2] *= scale;
    
    arg3->f[0] = center.f[0] + (normal.f[0] * 50.0f);
    arg3->f[1] = center.f[1];
    arg3->f[2] = center.f[2] + (normal.f[2] * 50.0f);
    
    
    walkTilesBetweenPoints_NoCallback(&sp4C, center.f[0], center.f[2], arg3->f[0], arg3->f[2]);
    
    if (1);
    
    *arg1 = (s32) sp4C->room;
    sp4C = sp2C;
    
    arg4->f[0] = center.f[0] - (normal.f[0] * 50.0f);
    arg4->f[1] = center.f[1];
    arg4->f[2] = center.f[2] - (normal.f[2] * 50.0f);
    
    walkTilesBetweenPoints_NoCallback(&sp4C, center.f[0], center.f[2], arg4->f[0], arg4->f[2]);
    
    if (1);
    
    *arg2 = (s32) sp4C->room;
    
    if (*arg2 == *arg1)
    {
        *arg2 = -1;
    }
}


extern f32 g_DoorScale;
/**
 * 
 * NTSC ADDRESS: 7F003480
 * PAL ADDRESS: 7F0033F0
 * Perfect Dark: void setupCreateDoor(struct doorobj *door, s32 cmdindex)
*/
void setupDoor(s32 arg0, struct DoorRecord *door, s32 arg2)
{
    s32 padding; // no sp
    s32 modelnum;
    struct BoundPadRecord *pad;
    StandTile *sp1C8_stan;
    PropRecord *prop;
    struct coord3d sp1B8;
    s32 portalnum; //sp1b4
    s32 sp1B0;
    s32 sp1AC;
    struct coord3d sp1A0;
    struct coord3d sp194;
    struct PortalMetric sp180;
    struct ModelRoData_BoundingBoxRecord *temp_v0;
    struct coord3d sp170;
    StandTile *sp16C;
    Mtxf sp12C;
    f32 temp_f2; // no sp
    ModelFileHeader *sp124;
    struct coord3d sp118;                           /* compiler-managed */
    StandTile *sp114_stan;
    Mtxf spD4;
    struct coord3d spC8;
    Mtxf sp88;    
    struct coord3d sp7C;
    struct bbox bb2;
    f32 xscale;
    f32 yscale;
    f32 zscale;
    f32 scale;
    //StandTile *stan;
    u8 *padding2;

    modelnum = door->obj;
    
    portalnum = -1;
    sp1B0 = -1;
    sp1AC = -1;

    modelLoad(modelnum);

    pad = &(g_CurrentSetup.boundpads[door->pad]);
    
    if ((door->flags & PROPFLAG_CULL_BEHIND_DOOR) || (door->flags & PROPFLAG_NO_PORTAL_CLOSE))
    {
        sub_GAME_7F00324C(pad, &sp1B0, &sp1AC, &sp1A0, &sp194);
        
        if ((door->flags & PROPFLAG_CULL_BEHIND_DOOR) && (sp1B0 >= 0) && (sp1AC >= 0))
        {
            portalnum = sub_GAME_7F0B9CC8(sp1B0, sp1AC, &sp1A0, &sp194);
        }
    }
    
    if (g_DoorScale != 1.0f)
    {
        if (portalnum >= 0)
        {
            sub_GAME_7F0B96CC(portalnum, &sp180);
            sp180.min *= get_room_data_float2();
            
            temp_f2 = (pad->pos.f[0] * sp180.normal.f[0]) + (pad->pos.f[1] * sp180.normal.f[1]) + (pad->pos.f[2] * sp180.normal.f[2]);
            
            if (g_DoorScale < 1.0f)
            {
                temp_f2 = (temp_f2 - sp180.min) * (1.0f - g_DoorScale);
                sp170.f[0] = pad->pos.f[0] - (sp180.normal.f[0] * temp_f2);
                sp170.f[1] = pad->pos.f[1] - (sp180.normal.f[1] * temp_f2);
                sp170.f[2] = pad->pos.f[2] - (sp180.normal.f[2] * temp_f2);
            }
            else
            {
                temp_f2 = (temp_f2 - sp180.min) * (g_DoorScale - 1.0f);
                sp170.f[0] = pad->pos.f[0] + (sp180.normal.f[0] * temp_f2);
                sp170.f[1] = pad->pos.f[1] + (sp180.normal.f[1] * temp_f2);
                sp170.f[2] = pad->pos.f[2] + (sp180.normal.f[2] * temp_f2);
            }
            
            sp16C = pad->stan;
            if (walkTilesBetweenPoints_NoCallback(&sp16C, pad->pos.f[0], pad->pos.f[2], sp170.f[0], sp170.f[2]) != 0)
            {
                pad->stan = sp16C;
                pad->pos.f[0] = sp170.f[0];
                pad->pos.f[1] = sp170.f[1];
                pad->pos.f[2] = sp170.f[2];
                pad->bbox.xmin *= g_DoorScale;
                pad->bbox.xmax *= g_DoorScale;
            }
        }
        else
        {
            pad->bbox.xmin *= g_DoorScale;
            pad->bbox.xmax *= g_DoorScale;
        }
    }
    
    if (sub_GAME_7F056850((PadRecord *)pad, pad->stan, 0.0f, &sp1B8, &sp1C8_stan) != 0)
    {
        matrix_4x4_7F059908(&sp12C, 0, 0, 0, -pad->look.f[0], -pad->look.f[1], -pad->look.f[2], pad->up.f[0], pad->up.f[1], pad->up.f[2]);
        sp124 = PitemZ_entries[modelnum].header;
        sp114_stan = sp1C8_stan;

        bb2.zmax = pad->bbox.xmin;
        bb2.zmin = pad->bbox.xmax; //78
        bb2.ymax = pad->bbox.ymin; //74
        bb2.ymin = pad->bbox.ymax; //70
        bb2.xmax = pad->bbox.zmin; //6c
        bb2.xmin = pad->bbox.zmax; //68

        matrix_4x4_set_rotation_around_x(M_HALF_PI, &spD4);
        matrix_4x4_set_rotation_around_z(M_HALF_PI, &sp88);
        matrix_4x4_multiply_in_place(&sp88, &spD4);
        matrix_4x4_multiply_in_place(&sp12C, &spD4);
        sub_GAME_7F001BD4(pad, &sp118);

        temp_v0 = (struct ModelRoData_BoundingBoxRecord *)sp124->RootNode->Child->Data;

        xscale = (bb2.ymin - bb2.ymax) / (temp_v0->Bounds.xmax - temp_v0->Bounds.xmin);
        yscale = (bb2.xmin - bb2.xmax) / (temp_v0->Bounds.ymax - temp_v0->Bounds.ymin);
        zscale = (bb2.zmin - bb2.zmax) / (temp_v0->Bounds.zmax - temp_v0->Bounds.zmin);
        
        if ((xscale <= 0.000001f) || (yscale <= 0.000001f) || (zscale <= 0.000001f))
        {
            xscale = 
                yscale = 
                zscale = 1.0f;
        }

        matrix_column_1_scalar_multiply(xscale, spD4.m[0]);
        matrix_column_2_scalar_multiply(yscale, spD4.m[0]);
        matrix_column_3_scalar_multiply_2(zscale, spD4.m[0]);
        
        spC8.f[0] = sp118.f[0];
        spC8.f[1] = sp118.f[1];
        spC8.f[2] = sp118.f[2];
        
        if (!(door->flags2 & 1))
        {
            if (walkTilesBetweenPoints_NoCallback(&sp114_stan, sp1B8.f[0], sp1B8.f[2], sp118.f[0], sp118.f[2]) != 0)
            {
                sp1C8_stan = sp114_stan;
            }
            else
            {
                sp118.f[0] = sp1B8.f[0];
                sp118.f[2] = sp1B8.f[2];
                
                if (!(door->flags & 0x1000)) // prop flag PROPFLAG_00001000 "Absolute Position"
                {
                    //
                }
            }
        }
        else
        {
            sp118.f[0] = sp1B8.f[0];
            sp118.f[1] = sp1B8.f[1];
            sp118.f[2] = sp1B8.f[2];
        }

        if ((door->doorType == 4) || (door->doorType == 8))
        {
            sp7C.f[0] = pad->look.f[0] * (bb2.xmin - bb2.xmax);
            sp7C.f[1] = pad->look.f[1] * (bb2.xmin - bb2.xmax);
            sp7C.f[2] = pad->look.f[2] * (bb2.xmin - bb2.xmax);
        }
        else
        {
            sp7C.f[0] = pad->up.f[0] * (bb2.ymax - bb2.ymin);
            sp7C.f[1] = pad->up.f[1] * (bb2.ymax - bb2.ymin);
            sp7C.f[2] = pad->up.f[2] * (bb2.ymax - bb2.ymin);
        }

        // These values are stored in the setup files as integers, but at
		// runtime they are floats. Hence reading a "float" as an integer,
		// converting it to a float and writing it back to the same property.
		door->maxFrac = *(s32 *) &door->maxFrac / 65536.0f;
		door->perimFrac = *(s32 *) &door->perimFrac / 65536.0f;
#if defined(VERSION_EU)
        door->accel = (*(s32 *) &door->accel) * 1.2f / 65536.0f;
		door->decel = (*(s32 *) &door->decel) * 1.2f / 65536.0f;
		door->maxSpeed = (*(s32 *) &door->maxSpeed) * 1.2f / 65536.0f; 
#else
		door->accel = (*(s32 *) &door->accel) / 65536.0f;
		door->decel = (*(s32 *) &door->decel) / 65536.0f;
		door->maxSpeed = (*(s32 *) &door->maxSpeed) / 65536.0f; 
#endif
        
        prop = doorInit(door, &sp118, &spD4, sp1C8_stan, &sp7C, &spC8);
        if (door->flags & PROPFLAG_CULL_BEHIND_DOOR)
        {
            door->portalNumber = portalnum;
            if ((portalnum >= 0) && (door->openPosition == 0.0f))
            {
                doorDeactivatePortal(door);
            }
        }
        
        prop->rooms[0] = prop->stan->room;
        chrpropRegisterRoom(prop, prop->stan->room);
        prop->rooms[1] = 0xFFU;
        prop->rooms[2] = 0xFFU;

        if ((door->flags & PROPFLAG_CULL_BEHIND_DOOR) || (door->flags & PROPFLAG_NO_PORTAL_CLOSE))
        {
            if (sp1B0 != prop->stan->room)
            {
                if (sp1B0 >= 0)
                {
                    prop->rooms[1] = sp1B0;
                    chrpropRegisterRoom(prop, sp1B0);
                }
            }
            else if (sp1AC >= 0)
            {
                prop->rooms[1] = sp1AC;
                chrpropRegisterRoom(prop, sp1AC);
            }
            
            if (prop->rooms[1] != 0xff && 1)
            {
                if (prop->stan->room);
            }
        }
        
        if (door->model != NULL)
        {
            scale = xscale;
            
            if (scale < yscale)
            {
                scale = yscale;
            }

            if (scale < zscale)
            {
                scale = zscale;
            }
            
            modelSetScale(door->model, door->model->scale * scale);
        }
        
        chrpropActivate(prop);
        chrpropEnable(prop);

        if (door->linkedDoorOffset != 0)
        {
            door->linkedDoor = (struct DoorRecord *)setupGetPtrToCommandByIndex(door->linkedDoorOffset + arg2);
        }
    }
    else
    {
        door->prop = NULL;
    }

}



#ifdef NONMATCHING
// https://decomp.me/scratch/lwIUY 68.9%
void proplvreset2(void) {

}
#else

#ifdef VERSION_US
GLOBAL_ASM(
.late_rodata
glabel jpt_object_type_expansion
.word door_expand
.word door_scale_expand
.word obj_03_expand
.word key_expand
.word obj_03_expand
.word surv_camera_expand
.word obj_03_expand
.word item_expand
.word actor_expand
.word single_screen_display_expand
.word multi_screen_display_expand
.word rack_expand
.word autogun_expand
.word other_obj_expand
.word other_obj_expand
.word other_obj_expand
.word hat_expand
.word actor_attr_expand
.word other_obj_expand
.word ammo_box_expand
.word body_armor_expand
.word tag_expand
.word type17_objective_expand
.word other_obj_expand
.word other_obj_expand
.word other_obj_expand
.word other_obj_expand
.word other_obj_expand
.word other_obj_expand
.word type1E_subobjective_expand
.word other_obj_expand
.word type20_subobjective_expand
.word type21_subobjective_expand
.word other_obj_expand
.word type23_solo_brief_text
.word obj_03_expand
.word type25_rename
.word other_obj_expand
.word type27_wheeled_vehicle
.word type28_aircraft
.word obj_03_expand
.word obj_03_expand
.word obj_03_expand
.word other_obj_expand
.word type2D_tank
.word type2E_viewport_pos
.word type2F_tinted_glass

glabel D_8004F024
.word 0x40c90fdb
glabel D_8004F028
.word 0x3e2e147c

glabel jpt_8004F02C
.word .L7F004B6C
.word .L7F004B6C
.word .L7F004DE4
.word .L7F004DE4
.word .L7F004B6C
.word .L7F004B6C
.word .L7F004DE4
.word .L7F004B6C
.word .L7F004DE4
.word .L7F004DE4
.word .L7F004DE4
.word .L7F004BD8
.word .L7F004DE4
.word .L7F004DE4
.word .L7F004DE4
.word .L7F004DE4
.word .L7F004C2C
.word .L7F004B6C
.word .L7F004B6C
.word .L7F004DE4
.word .L7F004DE4
.word .L7F004DE4
.word .L7F004DE4
.word .L7F004DE4
.word .L7F004DE4
.word .L7F004DE4
.word .L7F004DE4
.word .L7F004DE4
.word .L7F004DE4
.word .L7F004DE4
.word .L7F004DE4
.word .L7F004DE4
.word .L7F004DE4
.word .L7F004B6C
.word .L7F004DE4
.word .L7F004D70
.word .L7F004DE4
.word .L7F004DE4
.word .L7F004B6C
.word .L7F004B6C
.word .L7F004B6C
.word .L7F004CA4
.word .L7F004DE4
.word .L7F004DE4
.word .L7F004B6C

.text
glabel proplvreset2
/* 038720 7F003BF0 27BDFD80 */  addiu $sp, $sp, -0x280
/* 038724 7F003BF4 AFB50034 */  sw    $s5, 0x34($sp)
/* 038728 7F003BF8 0080A825 */  move  $s5, $a0
/* 03872C 7F003BFC AFBF0044 */  sw    $ra, 0x44($sp)
/* 038730 7F003C00 3C058005 */  lui   $a1, %hi(aNochr)
/* 038734 7F003C04 AFBE0040 */  sw    $fp, 0x40($sp)
/* 038738 7F003C08 AFB7003C */  sw    $s7, 0x3c($sp)
/* 03873C 7F003C0C AFB60038 */  sw    $s6, 0x38($sp)
/* 038740 7F003C10 AFB40030 */  sw    $s4, 0x30($sp)
/* 038744 7F003C14 AFB3002C */  sw    $s3, 0x2c($sp)
/* 038748 7F003C18 AFB20028 */  sw    $s2, 0x28($sp)
/* 03874C 7F003C1C AFB10024 */  sw    $s1, 0x24($sp)
/* 038750 7F003C20 AFB00020 */  sw    $s0, 0x20($sp)
/* 038754 7F003C24 F7B40018 */  sdc1  $f20, 0x18($sp)
/* 038758 7F003C28 24A5ED90 */  addiu $a1, %lo(aNochr) # addiu $a1, $a1, -0x1270
/* 03875C 7F003C2C 0C0029A8 */  jal   tokenFind
/* 038760 7F003C30 24040001 */   li    $a0, 1
/* 038764 7F003C34 2C460001 */  sltiu $a2, $v0, 1
/* 038768 7F003C38 10C00005 */  beqz  $a2, .L7F003C50
/* 03876C 7F003C3C 24040001 */   li    $a0, 1
/* 038770 7F003C40 3C058005 */  lui   $a1, %hi(aNoprop)
/* 038774 7F003C44 0C0029A8 */  jal   tokenFind
/* 038778 7F003C48 24A5ED98 */   addiu $a1, %lo(aNoprop) # addiu $a1, $a1, -0x1268
/* 03877C 7F003C4C 2C460001 */  sltiu $a2, $v0, 1
.L7F003C50:
/* 038780 7F003C50 3C058005 */  lui   $a1, %hi(aNoobj)
/* 038784 7F003C54 AFA60278 */  sw    $a2, 0x278($sp)
/* 038788 7F003C58 24A5EDA0 */  addiu $a1, %lo(aNoobj) # addiu $a1, $a1, -0x1260
/* 03878C 7F003C5C 0C0029A8 */  jal   tokenFind
/* 038790 7F003C60 24040001 */   li    $a0, 1
/* 038794 7F003C64 2C430001 */  sltiu $v1, $v0, 1
/* 038798 7F003C68 10600005 */  beqz  $v1, .L7F003C80
/* 03879C 7F003C6C 24040001 */   li    $a0, 1
/* 0387A0 7F003C70 3C058005 */  lui   $a1, %hi(aNoprop_0)
/* 0387A4 7F003C74 0C0029A8 */  jal   tokenFind
/* 0387A8 7F003C78 24A5EDA8 */   addiu $a1, %lo(aNoprop_0) # addiu $a1, $a1, -0x1258
/* 0387AC 7F003C7C 2C430001 */  sltiu $v1, $v0, 1
.L7F003C80:
/* 0387B0 7F003C80 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0387B4 7F003C84 44812000 */  mtc1  $at, $f4
/* 0387B8 7F003C88 0060F025 */  move  $fp, $v1
/* 0387BC 7F003C8C 3C018003 */  lui   $at, %hi(g_DoorScale)
/* 0387C0 7F003C90 3C038004 */  lui   $v1, %hi(PitemZ_entries+0xFF0)
/* 0387C4 7F003C94 3C028004 */  lui   $v0, %hi(PitemZ_entries)
/* 0387C8 7F003C98 2442A228 */  addiu $v0, %lo(PitemZ_entries) # addiu $v0, $v0, -0x5dd8
/* 0387CC 7F003C9C 2463B218 */  addiu $v1, $v1, %lo(PitemZ_entries+0xFF0)
/* 0387D0 7F003CA0 E424A3C0 */  swc1  $f4, %lo(g_DoorScale)($at)
.L7F003CA4:
/* 0387D4 7F003CA4 8C4E0000 */  lw    $t6, ($v0)
/* 0387D8 7F003CA8 2442000C */  addiu $v0, $v0, 0xc
/* 0387DC 7F003CAC 0043082B */  sltu  $at, $v0, $v1
/* 0387E0 7F003CB0 1420FFFC */  bnez  $at, .L7F003CA4
/* 0387E4 7F003CB4 ADC00000 */   sw    $zero, ($t6)
/* 0387E8 7F003CB8 2AA1003B */  slti  $at, $s5, 0x3b
/* 0387EC 7F003CBC 10200454 */  beqz  $at, .L7F004E10
/* 0387F0 7F003CC0 00157880 */   sll   $t7, $s5, 2
/* 0387F4 7F003CC4 3C188003 */  lui   $t8, %hi(setup_text_pointers) 
/* 0387F8 7F003CC8 271874E4 */  addiu $t8, %lo(setup_text_pointers) # addiu $t8, $t8, 0x74e4
/* 0387FC 7F003CCC 01F88021 */  addu  $s0, $t7, $t8
/* 038800 7F003CD0 8E020000 */  lw    $v0, ($s0)
/* 038804 7F003CD4 3C198005 */  lui   $t9, %hi(only_read_by_stageload) 
/* 038808 7F003CD8 27B10174 */  addiu $s1, $sp, 0x174
/* 03880C 7F003CDC 1040044C */  beqz  $v0, .L7F004E10
/* 038810 7F003CE0 2739EDB0 */   addiu $t9, %lo(only_read_by_stageload) # addiu $t9, $t9, -0x1250
/* 038814 7F003CE4 02205025 */  move  $t2, $s1
/* 038818 7F003CE8 272900FC */  addiu $t1, $t9, 0xfc
.L7F003CEC:
/* 03881C 7F003CEC 8F210000 */  lw    $at, ($t9)
/* 038820 7F003CF0 2739000C */  addiu $t9, $t9, 0xc
/* 038824 7F003CF4 254A000C */  addiu $t2, $t2, 0xc
/* 038828 7F003CF8 AD41FFF4 */  sw    $at, -0xc($t2)
/* 03882C 7F003CFC 8F21FFF8 */  lw    $at, -8($t9)
/* 038830 7F003D00 AD41FFF8 */  sw    $at, -8($t2)
/* 038834 7F003D04 8F21FFFC */  lw    $at, -4($t9)
/* 038838 7F003D08 1729FFF8 */  bne   $t9, $t1, .L7F003CEC
/* 03883C 7F003D0C AD41FFFC */   sw    $at, -4($t2)
/* 038840 7F003D10 8F210000 */  lw    $at, ($t9)
/* 038844 7F003D14 0000A025 */  move  $s4, $zero
/* 038848 7F003D18 00009825 */  move  $s3, $zero
/* 03884C 7F003D1C AD410000 */  sw    $at, ($t2)
/* 038850 7F003D20 904B0000 */  lbu   $t3, ($v0)
/* 038854 7F003D24 A3A00175 */  sb    $zero, 0x175($sp)
/* 038858 7F003D28 0FC26919 */  jal   getPlayerCount
/* 03885C 7F003D2C A3AB0174 */   sb    $t3, 0x174($sp)
/* 038860 7F003D30 28410002 */  slti  $at, $v0, 2
/* 038864 7F003D34 14200004 */  bnez  $at, .L7F003D48
/* 038868 7F003D38 3C058005 */   lui   $a1, %hi(aMp_)
/* 03886C 7F003D3C 24A5EEB0 */  addiu $a1, %lo(aMp_) # addiu $a1, $a1, -0x1150
/* 038870 7F003D40 0C0029FF */  jal   strcat
/* 038874 7F003D44 02202025 */   move  $a0, $s1
.L7F003D48:
/* 038878 7F003D48 8E050000 */  lw    $a1, ($s0)
/* 03887C 7F003D4C 02202025 */  move  $a0, $s1
/* 038880 7F003D50 0C0029FF */  jal   strcat
/* 038884 7F003D54 24A50001 */   addiu $a1, $a1, 1
/* 038888 7F003D58 02202025 */  move  $a0, $s1
/* 03888C 7F003D5C 24050001 */  li    $a1, 1
/* 038890 7F003D60 24060100 */  li    $a2, 256
/* 038894 7F003D64 0FC2F341 */  jal   _fileNameLoadToBank
/* 038898 7F003D68 24070004 */   li    $a3, 4
/* 03889C 7F003D6C 3C038007 */  lui   $v1, %hi(g_ptrStageSetupFile)
/* 0388A0 7F003D70 24635D28 */  addiu $v1, %lo(g_ptrStageSetupFile) # addiu $v1, $v1, 0x5d28
/* 0388A4 7F003D74 AC620000 */  sw    $v0, ($v1)
/* 0388A8 7F003D78 00408825 */  move  $s1, $v0
/* 0388AC 7F003D7C 0FC30578 */  jal   langGetLangBankIndexFromStagenum
/* 0388B0 7F003D80 02A02025 */   move  $a0, $s5
/* 0388B4 7F003D84 0FC30742 */  jal   langLoadToAddr
/* 0388B8 7F003D88 00402025 */   move  $a0, $v0
/* 0388BC 7F003D8C 8E2C0000 */  lw    $t4, ($s1)
/* 0388C0 7F003D90 3C078007 */  lui   $a3, %hi(g_CurrentSetup+0)
/* 0388C4 7F003D94 24E75D00 */  addiu $a3, %lo(g_CurrentSetup+0) # addiu $a3, $a3, 0x5d00
/* 0388C8 7F003D98 022C6821 */  addu  $t5, $s1, $t4
/* 0388CC 7F003D9C ACED0000 */  sw    $t5, ($a3)
/* 0388D0 7F003DA0 8E2E0004 */  lw    $t6, 4($s1)
/* 0388D4 7F003DA4 022E7821 */  addu  $t7, $s1, $t6
/* 0388D8 7F003DA8 ACEF0004 */  sw    $t7, 4($a3)
/* 0388DC 7F003DAC 8E380008 */  lw    $t8, 8($s1)
/* 0388E0 7F003DB0 02384021 */  addu  $t0, $s1, $t8
/* 0388E4 7F003DB4 ACE80008 */  sw    $t0, 8($a3)
/* 0388E8 7F003DB8 8E29000C */  lw    $t1, 0xc($s1)
/* 0388EC 7F003DBC 0229C821 */  addu  $t9, $s1, $t1
/* 0388F0 7F003DC0 ACF9000C */  sw    $t9, 0xc($a3)
/* 0388F4 7F003DC4 8E2A0010 */  lw    $t2, 0x10($s1)
/* 0388F8 7F003DC8 022A5821 */  addu  $t3, $s1, $t2
/* 0388FC 7F003DCC ACEB0010 */  sw    $t3, 0x10($a3)
/* 038900 7F003DD0 8E2C0014 */  lw    $t4, 0x14($s1)
/* 038904 7F003DD4 022C6821 */  addu  $t5, $s1, $t4
/* 038908 7F003DD8 ACED0014 */  sw    $t5, 0x14($a3)
/* 03890C 7F003DDC 8E2E0018 */  lw    $t6, 0x18($s1)
/* 038910 7F003DE0 022E7821 */  addu  $t7, $s1, $t6
/* 038914 7F003DE4 ACEF0018 */  sw    $t7, 0x18($a3)
/* 038918 7F003DE8 8E38001C */  lw    $t8, 0x1c($s1)
/* 03891C 7F003DEC 02384021 */  addu  $t0, $s1, $t8
/* 038920 7F003DF0 ACE8001C */  sw    $t0, 0x1c($a3)
/* 038924 7F003DF4 8E220020 */  lw    $v0, 0x20($s1)
/* 038928 7F003DF8 10400003 */  beqz  $v0, .L7F003E08
/* 03892C 7F003DFC 02224821 */   addu  $t1, $s1, $v0
/* 038930 7F003E00 10000002 */  b     .L7F003E0C
/* 038934 7F003E04 ACE90020 */   sw    $t1, 0x20($a3)
.L7F003E08:
/* 038938 7F003E08 ACE00020 */  sw    $zero, 0x20($a3)
.L7F003E0C:
/* 03893C 7F003E0C 8E220024 */  lw    $v0, 0x24($s1)
/* 038940 7F003E10 10400003 */  beqz  $v0, .L7F003E20
/* 038944 7F003E14 0222C821 */   addu  $t9, $s1, $v0
/* 038948 7F003E18 10000002 */  b     .L7F003E24
/* 03894C 7F003E1C ACF90024 */   sw    $t9, 0x24($a3)
.L7F003E20:
/* 038950 7F003E20 ACE00024 */  sw    $zero, 0x24($a3)
.L7F003E24:
/* 038954 7F003E24 8CE50000 */  lw    $a1, ($a3)
/* 038958 7F003E28 50A00010 */  beql  $a1, $zero, .L7F003E6C
/* 03895C 7F003E2C 8CE50004 */   lw    $a1, 4($a3)
/* 038960 7F003E30 8CAA0000 */  lw    $t2, ($a1)
/* 038964 7F003E34 00001825 */  move  $v1, $zero
/* 038968 7F003E38 00A01025 */  move  $v0, $a1
/* 03896C 7F003E3C 0542000B */  bltzl $t2, .L7F003E6C
/* 038970 7F003E40 8CE50004 */   lw    $a1, 4($a3)
/* 038974 7F003E44 8C4B0004 */  lw    $t3, 4($v0)
.L7F003E48:
/* 038978 7F003E48 24630010 */  addiu $v1, $v1, 0x10
/* 03897C 7F003E4C 01716021 */  addu  $t4, $t3, $s1
/* 038980 7F003E50 AC4C0004 */  sw    $t4, 4($v0)
/* 038984 7F003E54 8CED0000 */  lw    $t5, ($a3)
/* 038988 7F003E58 01A31021 */  addu  $v0, $t5, $v1
/* 03898C 7F003E5C 8C4E0000 */  lw    $t6, ($v0)
/* 038990 7F003E60 05C3FFF9 */  bgezl $t6, .L7F003E48
/* 038994 7F003E64 8C4B0004 */   lw    $t3, 4($v0)
/* 038998 7F003E68 8CE50004 */  lw    $a1, 4($a3)
.L7F003E6C:
/* 03899C 7F003E6C 50A00015 */  beql  $a1, $zero, .L7F003EC4
/* 0389A0 7F003E70 8CE60014 */   lw    $a2, 0x14($a3)
/* 0389A4 7F003E74 8CAF0000 */  lw    $t7, ($a1)
/* 0389A8 7F003E78 00001825 */  move  $v1, $zero
/* 0389AC 7F003E7C 00A01025 */  move  $v0, $a1
/* 0389B0 7F003E80 51E00010 */  beql  $t7, $zero, .L7F003EC4
/* 0389B4 7F003E84 8CE60014 */   lw    $a2, 0x14($a3)
/* 0389B8 7F003E88 8CA40000 */  lw    $a0, ($a1)
/* 0389BC 7F003E8C 0091C021 */  addu  $t8, $a0, $s1
.L7F003E90:
/* 0389C0 7F003E90 AC580000 */  sw    $t8, ($v0)
/* 0389C4 7F003E94 8CE80004 */  lw    $t0, 4($a3)
/* 0389C8 7F003E98 01031021 */  addu  $v0, $t0, $v1
/* 0389CC 7F003E9C 8C490004 */  lw    $t1, 4($v0)
/* 0389D0 7F003EA0 2463000C */  addiu $v1, $v1, 0xc
/* 0389D4 7F003EA4 0131C821 */  addu  $t9, $t1, $s1
/* 0389D8 7F003EA8 AC590004 */  sw    $t9, 4($v0)
/* 0389DC 7F003EAC 8CEA0004 */  lw    $t2, 4($a3)
/* 0389E0 7F003EB0 01431021 */  addu  $v0, $t2, $v1
/* 0389E4 7F003EB4 8C440000 */  lw    $a0, ($v0)
/* 0389E8 7F003EB8 5480FFF5 */  bnezl $a0, .L7F003E90
/* 0389EC 7F003EBC 0091C021 */   addu  $t8, $a0, $s1
/* 0389F0 7F003EC0 8CE60014 */  lw    $a2, 0x14($a3)
.L7F003EC4:
/* 0389F4 7F003EC4 50C00010 */  beql  $a2, $zero, .L7F003F08
/* 0389F8 7F003EC8 8CE20010 */   lw    $v0, 0x10($a3)
/* 0389FC 7F003ECC 8CCB0000 */  lw    $t3, ($a2)
/* 038A00 7F003ED0 00002825 */  move  $a1, $zero
/* 038A04 7F003ED4 00C01025 */  move  $v0, $a2
/* 038A08 7F003ED8 5160000B */  beql  $t3, $zero, .L7F003F08
/* 038A0C 7F003EDC 8CE20010 */   lw    $v0, 0x10($a3)
/* 038A10 7F003EE0 8CC30000 */  lw    $v1, ($a2)
/* 038A14 7F003EE4 00716021 */  addu  $t4, $v1, $s1
.L7F003EE8:
/* 038A18 7F003EE8 AC4C0000 */  sw    $t4, ($v0)
/* 038A1C 7F003EEC 8CED0014 */  lw    $t5, 0x14($a3)
/* 038A20 7F003EF0 24A50008 */  addiu $a1, $a1, 8
/* 038A24 7F003EF4 01A51021 */  addu  $v0, $t5, $a1
/* 038A28 7F003EF8 8C430000 */  lw    $v1, ($v0)
/* 038A2C 7F003EFC 5460FFFA */  bnezl $v1, .L7F003EE8
/* 038A30 7F003F00 00716021 */   addu  $t4, $v1, $s1
/* 038A34 7F003F04 8CE20010 */  lw    $v0, 0x10($a3)
.L7F003F08:
/* 038A38 7F003F08 50400020 */  beql  $v0, $zero, .L7F003F8C
/* 038A3C 7F003F0C 8CEA0018 */   lw    $t2, 0x18($a3)
/* 038A40 7F003F10 8C4E0000 */  lw    $t6, ($v0)
/* 038A44 7F003F14 00002825 */  move  $a1, $zero
/* 038A48 7F003F18 00403025 */  move  $a2, $v0
/* 038A4C 7F003F1C 51C0001B */  beql  $t6, $zero, .L7F003F8C
/* 038A50 7F003F20 8CEA0018 */   lw    $t2, 0x18($a3)
/* 038A54 7F003F24 8C440000 */  lw    $a0, ($v0)
/* 038A58 7F003F28 00917821 */  addu  $t7, $a0, $s1
.L7F003F2C:
/* 038A5C 7F003F2C ACCF0000 */  sw    $t7, ($a2)
/* 038A60 7F003F30 8CF80010 */  lw    $t8, 0x10($a3)
/* 038A64 7F003F34 00001825 */  move  $v1, $zero
/* 038A68 7F003F38 03053021 */  addu  $a2, $t8, $a1
/* 038A6C 7F003F3C 8CC40000 */  lw    $a0, ($a2)
/* 038A70 7F003F40 8C880000 */  lw    $t0, ($a0)
/* 038A74 7F003F44 00801025 */  move  $v0, $a0
/* 038A78 7F003F48 05020009 */  bltzl $t0, .L7F003F70
/* 038A7C 7F003F4C A4C30006 */   sh    $v1, 6($a2)
/* 038A80 7F003F50 8C490004 */  lw    $t1, 4($v0)
.L7F003F54:
/* 038A84 7F003F54 24630001 */  addiu $v1, $v1, 1
/* 038A88 7F003F58 24420004 */  addiu $v0, $v0, 4
/* 038A8C 7F003F5C 0523FFFD */  bgezl $t1, .L7F003F54
/* 038A90 7F003F60 8C490004 */   lw    $t1, 4($v0)
/* 038A94 7F003F64 3C078007 */  lui   $a3, %hi(g_CurrentSetup+0)
/* 038A98 7F003F68 24E75D00 */  addiu $a3, %lo(g_CurrentSetup+0) # addiu $a3, $a3, 0x5d00
/* 038A9C 7F003F6C A4C30006 */  sh    $v1, 6($a2)
.L7F003F70:
/* 038AA0 7F003F70 8CF90010 */  lw    $t9, 0x10($a3)
/* 038AA4 7F003F74 24A50008 */  addiu $a1, $a1, 8
/* 038AA8 7F003F78 03253021 */  addu  $a2, $t9, $a1
/* 038AAC 7F003F7C 8CC40000 */  lw    $a0, ($a2)
/* 038AB0 7F003F80 5480FFEA */  bnezl $a0, .L7F003F2C
/* 038AB4 7F003F84 00917821 */   addu  $t7, $a0, $s1
/* 038AB8 7F003F88 8CEA0018 */  lw    $t2, 0x18($a3)
.L7F003F8C:
/* 038ABC 7F003F8C 1140001D */  beqz  $t2, .L7F004004
/* 038AC0 7F003F90 00000000 */   nop   
/* 038AC4 7F003F94 0FC2D20C */  jal   get_room_data_float2
/* 038AC8 7F003F98 00000000 */   nop   
/* 038ACC 7F003F9C 3C108007 */  lui   $s0, %hi(g_CurrentSetup+0x18)
/* 038AD0 7F003FA0 8E105D18 */  lw    $s0, %lo(g_CurrentSetup+0x18)($s0)
/* 038AD4 7F003FA4 46000086 */  mov.s $f2, $f0
/* 038AD8 7F003FA8 8E020024 */  lw    $v0, 0x24($s0)
/* 038ADC 7F003FAC 10400015 */  beqz  $v0, .L7F004004
/* 038AE0 7F003FB0 00000000 */   nop   
/* 038AE4 7F003FB4 C6060000 */  lwc1  $f6, ($s0)
.L7F003FB8:
/* 038AE8 7F003FB8 C60A0004 */  lwc1  $f10, 4($s0)
/* 038AEC 7F003FBC C6120008 */  lwc1  $f18, 8($s0)
/* 038AF0 7F003FC0 46023202 */  mul.s $f8, $f6, $f2
/* 038AF4 7F003FC4 02222821 */  addu  $a1, $s1, $v0
/* 038AF8 7F003FC8 AE050024 */  sw    $a1, 0x24($s0)
/* 038AFC 7F003FCC 46025402 */  mul.s $f16, $f10, $f2
/* 038B00 7F003FD0 02002025 */  move  $a0, $s0
/* 038B04 7F003FD4 26060028 */  addiu $a2, $s0, 0x28
/* 038B08 7F003FD8 46029102 */  mul.s $f4, $f18, $f2
/* 038B0C 7F003FDC E6080000 */  swc1  $f8, ($s0)
/* 038B10 7F003FE0 E6100004 */  swc1  $f16, 4($s0)
/* 038B14 7F003FE4 E6040008 */  swc1  $f4, 8($s0)
/* 038B18 7F003FE8 0FC019F0 */  jal   init_pathtable_something
/* 038B1C 7F003FEC E7A2015C */   swc1  $f2, 0x15c($sp)
/* 038B20 7F003FF0 8E020050 */  lw    $v0, 0x50($s0)
/* 038B24 7F003FF4 2610002C */  addiu $s0, $s0, 0x2c
/* 038B28 7F003FF8 C7A2015C */  lwc1  $f2, 0x15c($sp)
/* 038B2C 7F003FFC 5440FFEE */  bnezl $v0, .L7F003FB8
/* 038B30 7F004000 C6060000 */   lwc1  $f6, ($s0)
.L7F004004:
/* 038B34 7F004004 3C078007 */  lui   $a3, %hi(g_CurrentSetup+0)
/* 038B38 7F004008 24E75D00 */  addiu $a3, %lo(g_CurrentSetup+0) # addiu $a3, $a3, 0x5d00
/* 038B3C 7F00400C 8CEC001C */  lw    $t4, 0x1c($a3)
/* 038B40 7F004010 51800033 */  beql  $t4, $zero, .L7F0040E0
/* 038B44 7F004014 8CE50020 */   lw    $a1, 0x20($a3)
/* 038B48 7F004018 0FC2D20C */  jal   get_room_data_float2
/* 038B4C 7F00401C 00000000 */   nop   
/* 038B50 7F004020 3C078007 */  lui   $a3, %hi(g_CurrentSetup+0)
/* 038B54 7F004024 24E75D00 */  addiu $a3, %lo(g_CurrentSetup+0) # addiu $a3, $a3, 0x5d00
/* 038B58 7F004028 8CF0001C */  lw    $s0, 0x1c($a3)
/* 038B5C 7F00402C 46000086 */  mov.s $f2, $f0
/* 038B60 7F004030 8E020024 */  lw    $v0, 0x24($s0)
/* 038B64 7F004034 5040002A */  beql  $v0, $zero, .L7F0040E0
/* 038B68 7F004038 8CE50020 */   lw    $a1, 0x20($a3)
/* 038B6C 7F00403C C6060000 */  lwc1  $f6, ($s0)
.L7F004040:
/* 038B70 7F004040 C60A0004 */  lwc1  $f10, 4($s0)
/* 038B74 7F004044 C6120008 */  lwc1  $f18, 8($s0)
/* 038B78 7F004048 46023202 */  mul.s $f8, $f6, $f2
/* 038B7C 7F00404C C606002C */  lwc1  $f6, 0x2c($s0)
/* 038B80 7F004050 02222821 */  addu  $a1, $s1, $v0
/* 038B84 7F004054 46025402 */  mul.s $f16, $f10, $f2
/* 038B88 7F004058 C60A0030 */  lwc1  $f10, 0x30($s0)
/* 038B8C 7F00405C AE050024 */  sw    $a1, 0x24($s0)
/* 038B90 7F004060 46029102 */  mul.s $f4, $f18, $f2
/* 038B94 7F004064 E6080000 */  swc1  $f8, ($s0)
/* 038B98 7F004068 C6120034 */  lwc1  $f18, 0x34($s0)
/* 038B9C 7F00406C 46023202 */  mul.s $f8, $f6, $f2
/* 038BA0 7F004070 E6100004 */  swc1  $f16, 4($s0)
/* 038BA4 7F004074 C6060038 */  lwc1  $f6, 0x38($s0)
/* 038BA8 7F004078 46025402 */  mul.s $f16, $f10, $f2
/* 038BAC 7F00407C E6040008 */  swc1  $f4, 8($s0)
/* 038BB0 7F004080 C60A003C */  lwc1  $f10, 0x3c($s0)
/* 038BB4 7F004084 46029102 */  mul.s $f4, $f18, $f2
/* 038BB8 7F004088 E608002C */  swc1  $f8, 0x2c($s0)
/* 038BBC 7F00408C C6120040 */  lwc1  $f18, 0x40($s0)
/* 038BC0 7F004090 46023202 */  mul.s $f8, $f6, $f2
/* 038BC4 7F004094 E6100030 */  swc1  $f16, 0x30($s0)
/* 038BC8 7F004098 02002025 */  move  $a0, $s0
/* 038BCC 7F00409C 46025402 */  mul.s $f16, $f10, $f2
/* 038BD0 7F0040A0 E6040034 */  swc1  $f4, 0x34($s0)
/* 038BD4 7F0040A4 26060028 */  addiu $a2, $s0, 0x28
/* 038BD8 7F0040A8 46029102 */  mul.s $f4, $f18, $f2
/* 038BDC 7F0040AC E6080038 */  swc1  $f8, 0x38($s0)
/* 038BE0 7F0040B0 E610003C */  swc1  $f16, 0x3c($s0)
/* 038BE4 7F0040B4 E6040040 */  swc1  $f4, 0x40($s0)
/* 038BE8 7F0040B8 0FC019F0 */  jal   init_pathtable_something
/* 038BEC 7F0040BC E7A20150 */   swc1  $f2, 0x150($sp)
/* 038BF0 7F0040C0 8E020068 */  lw    $v0, 0x68($s0)
/* 038BF4 7F0040C4 26100044 */  addiu $s0, $s0, 0x44
/* 038BF8 7F0040C8 C7A20150 */  lwc1  $f2, 0x150($sp)
/* 038BFC 7F0040CC 5440FFDC */  bnezl $v0, .L7F004040
/* 038C00 7F0040D0 C6060000 */   lwc1  $f6, ($s0)
/* 038C04 7F0040D4 3C078007 */  lui   $a3, %hi(g_CurrentSetup+0)
/* 038C08 7F0040D8 24E75D00 */  addiu $a3, %lo(g_CurrentSetup+0) # addiu $a3, $a3, 0x5d00
/* 038C0C 7F0040DC 8CE50020 */  lw    $a1, 0x20($a3)
.L7F0040E0:
/* 038C10 7F0040E0 50A00010 */  beql  $a1, $zero, .L7F004124
/* 038C14 7F0040E4 8CE50024 */   lw    $a1, 0x24($a3)
/* 038C18 7F0040E8 8CAE0000 */  lw    $t6, ($a1)
/* 038C1C 7F0040EC 00001025 */  move  $v0, $zero
/* 038C20 7F0040F0 00A01825 */  move  $v1, $a1
/* 038C24 7F0040F4 51C0000B */  beql  $t6, $zero, .L7F004124
/* 038C28 7F0040F8 8CE50024 */   lw    $a1, 0x24($a3)
/* 038C2C 7F0040FC 8CA40000 */  lw    $a0, ($a1)
/* 038C30 7F004100 00917821 */  addu  $t7, $a0, $s1
.L7F004104:
/* 038C34 7F004104 AC6F0000 */  sw    $t7, ($v1)
/* 038C38 7F004108 8CF80020 */  lw    $t8, 0x20($a3)
/* 038C3C 7F00410C 24420004 */  addiu $v0, $v0, 4
/* 038C40 7F004110 03021821 */  addu  $v1, $t8, $v0
/* 038C44 7F004114 8C640000 */  lw    $a0, ($v1)
/* 038C48 7F004118 5480FFFA */  bnezl $a0, .L7F004104
/* 038C4C 7F00411C 00917821 */   addu  $t7, $a0, $s1
/* 038C50 7F004120 8CE50024 */  lw    $a1, 0x24($a3)
.L7F004124:
/* 038C54 7F004124 50A0000F */  beql  $a1, $zero, .L7F004164
/* 038C58 7F004128 8FAA0278 */   lw    $t2, 0x278($sp)
/* 038C5C 7F00412C 8CA80000 */  lw    $t0, ($a1)
/* 038C60 7F004130 00001025 */  move  $v0, $zero
/* 038C64 7F004134 00A01825 */  move  $v1, $a1
/* 038C68 7F004138 11000009 */  beqz  $t0, .L7F004160
/* 038C6C 7F00413C 01002025 */   move  $a0, $t0
/* 038C70 7F004140 00914821 */  addu  $t1, $a0, $s1
.L7F004144:
/* 038C74 7F004144 AC690000 */  sw    $t1, ($v1)
/* 038C78 7F004148 8CF90024 */  lw    $t9, 0x24($a3)
/* 038C7C 7F00414C 24420004 */  addiu $v0, $v0, 4
/* 038C80 7F004150 03221821 */  addu  $v1, $t9, $v0
/* 038C84 7F004154 8C640000 */  lw    $a0, ($v1)
/* 038C88 7F004158 5480FFFA */  bnezl $a0, .L7F004144
/* 038C8C 7F00415C 00914821 */   addu  $t1, $a0, $s1
.L7F004160:
/* 038C90 7F004160 8FAA0278 */  lw    $t2, 0x278($sp)
.L7F004164:
/* 038C94 7F004164 11400012 */  beqz  $t2, .L7F0041B0
/* 038C98 7F004168 00000000 */   nop   
/* 038C9C 7F00416C 0FC006D4 */  jal   load_proptype
/* 038CA0 7F004170 24040009 */   li    $a0, 9
/* 038CA4 7F004174 0FC003AE */  jal   alloc_init_GUARDdata_entries
/* 038CA8 7F004178 00402025 */   move  $a0, $v0
/* 038CAC 7F00417C 0FC006D4 */  jal   load_proptype
/* 038CB0 7F004180 24040009 */   li    $a0, 9
/* 038CB4 7F004184 0040A025 */  move  $s4, $v0
/* 038CB8 7F004188 0FC006D4 */  jal   load_proptype
/* 038CBC 7F00418C 24040008 */   li    $a0, 8
/* 038CC0 7F004190 00409825 */  move  $s3, $v0
/* 038CC4 7F004194 0FC006D4 */  jal   load_proptype
/* 038CC8 7F004198 24040004 */   li    $a0, 4
/* 038CCC 7F00419C 02629821 */  addu  $s3, $s3, $v0
/* 038CD0 7F0041A0 0FC006D4 */  jal   load_proptype
/* 038CD4 7F0041A4 24040011 */   li    $a0, 17
/* 038CD8 7F0041A8 10000003 */  b     .L7F0041B8
/* 038CDC 7F0041AC 02629821 */   addu  $s3, $s3, $v0
.L7F0041B0:
/* 038CE0 7F0041B0 0FC003AE */  jal   alloc_init_GUARDdata_entries
/* 038CE4 7F0041B4 00002025 */   move  $a0, $zero
.L7F0041B8:
/* 038CE8 7F0041B8 13C0003A */  beqz  $fp, .L7F0042A4
/* 038CEC 7F0041BC 00000000 */   nop   
/* 038CF0 7F0041C0 0FC006D4 */  jal   load_proptype
/* 038CF4 7F0041C4 24040001 */   li    $a0, 1
/* 038CF8 7F0041C8 02629821 */  addu  $s3, $s3, $v0
/* 038CFC 7F0041CC 0FC006D4 */  jal   load_proptype
/* 038D00 7F0041D0 24040006 */   li    $a0, 6
/* 038D04 7F0041D4 02629821 */  addu  $s3, $s3, $v0
/* 038D08 7F0041D8 0FC006D4 */  jal   load_proptype
/* 038D0C 7F0041DC 2404000D */   li    $a0, 13
/* 038D10 7F0041E0 02629821 */  addu  $s3, $s3, $v0
/* 038D14 7F0041E4 0FC006D4 */  jal   load_proptype
/* 038D18 7F0041E8 2404000C */   li    $a0, 12
/* 038D1C 7F0041EC 02629821 */  addu  $s3, $s3, $v0
/* 038D20 7F0041F0 0FC006D4 */  jal   load_proptype
/* 038D24 7F0041F4 2404000A */   li    $a0, 10
/* 038D28 7F0041F8 02629821 */  addu  $s3, $s3, $v0
/* 038D2C 7F0041FC 0FC006D4 */  jal   load_proptype
/* 038D30 7F004200 2404000B */   li    $a0, 11
/* 038D34 7F004204 02629821 */  addu  $s3, $s3, $v0
/* 038D38 7F004208 0FC006D4 */  jal   load_proptype
/* 038D3C 7F00420C 24040015 */   li    $a0, 21
/* 038D40 7F004210 02629821 */  addu  $s3, $s3, $v0
/* 038D44 7F004214 0FC006D4 */  jal   load_proptype
/* 038D48 7F004218 24040003 */   li    $a0, 3
/* 038D4C 7F00421C 02629821 */  addu  $s3, $s3, $v0
/* 038D50 7F004220 0FC006D4 */  jal   load_proptype
/* 038D54 7F004224 2404002A */   li    $a0, 42
/* 038D58 7F004228 02629821 */  addu  $s3, $s3, $v0
/* 038D5C 7F00422C 0FC006D4 */  jal   load_proptype
/* 038D60 7F004230 2404002F */   li    $a0, 47
/* 038D64 7F004234 02629821 */  addu  $s3, $s3, $v0
/* 038D68 7F004238 0FC006D4 */  jal   load_proptype
/* 038D6C 7F00423C 2404002B */   li    $a0, 43
/* 038D70 7F004240 02629821 */  addu  $s3, $s3, $v0
/* 038D74 7F004244 0FC006D4 */  jal   load_proptype
/* 038D78 7F004248 24040029 */   li    $a0, 41
/* 038D7C 7F00424C 02629821 */  addu  $s3, $s3, $v0
/* 038D80 7F004250 0FC006D4 */  jal   load_proptype
/* 038D84 7F004254 24040024 */   li    $a0, 36
/* 038D88 7F004258 02629821 */  addu  $s3, $s3, $v0
/* 038D8C 7F00425C 0FC006D4 */  jal   load_proptype
/* 038D90 7F004260 24040005 */   li    $a0, 5
/* 038D94 7F004264 02629821 */  addu  $s3, $s3, $v0
/* 038D98 7F004268 0FC006D4 */  jal   load_proptype
/* 038D9C 7F00426C 24040007 */   li    $a0, 7
/* 038DA0 7F004270 02629821 */  addu  $s3, $s3, $v0
/* 038DA4 7F004274 0FC006D4 */  jal   load_proptype
/* 038DA8 7F004278 24040014 */   li    $a0, 20
/* 038DAC 7F00427C 02629821 */  addu  $s3, $s3, $v0
/* 038DB0 7F004280 0FC006D4 */  jal   load_proptype
/* 038DB4 7F004284 24040027 */   li    $a0, 39
/* 038DB8 7F004288 02629821 */  addu  $s3, $s3, $v0
/* 038DBC 7F00428C 0FC006D4 */  jal   load_proptype
/* 038DC0 7F004290 2404002D */   li    $a0, 45
/* 038DC4 7F004294 02629821 */  addu  $s3, $s3, $v0
/* 038DC8 7F004298 0FC006D4 */  jal   load_proptype
/* 038DCC 7F00429C 24040028 */   li    $a0, 40
/* 038DD0 7F0042A0 0282A021 */  addu  $s4, $s4, $v0
.L7F0042A4:
/* 038DD4 7F0042A4 0FC01550 */  jal   sub_GAME_7F005540
/* 038DD8 7F0042A8 02602025 */   move  $a0, $s3
/* 038DDC 7F0042AC 0FC01589 */  jal   sub_GAME_7F005624
/* 038DE0 7F0042B0 02802025 */   move  $a0, $s4
/* 038DE4 7F0042B4 0FC26919 */  jal   getPlayerCount
/* 038DE8 7F0042B8 00008025 */   move  $s0, $zero
/* 038DEC 7F0042BC 1840000C */  blez  $v0, .L7F0042F0
/* 038DF0 7F0042C0 00000000 */   nop   
.L7F0042C4:
/* 038DF4 7F0042C4 0FC26C43 */  jal   set_cur_player
/* 038DF8 7F0042C8 02002025 */   move  $a0, $s0
/* 038DFC 7F0042CC 0FC006D4 */  jal   load_proptype
/* 038E00 7F0042D0 2404000E */   li    $a0, 14
/* 038E04 7F0042D4 0FC01897 */  jal   alloc_additional_item_slots
/* 038E08 7F0042D8 00402025 */   move  $a0, $v0
/* 038E0C 7F0042DC 0FC26919 */  jal   getPlayerCount
/* 038E10 7F0042E0 26100001 */   addiu $s0, $s0, 1
/* 038E14 7F0042E4 0202082A */  slt   $at, $s0, $v0
/* 038E18 7F0042E8 1420FFF6 */  bnez  $at, .L7F0042C4
/* 038E1C 7F0042EC 00000000 */   nop   
.L7F0042F0:
/* 038E20 7F0042F0 3C0B8007 */  lui   $t3, %hi(g_CurrentSetup+0x0c) 
/* 038E24 7F0042F4 8D6B5D0C */  lw    $t3, %lo(g_CurrentSetup+0x0c)($t3)
/* 038E28 7F0042F8 116002DF */  beqz  $t3, .L7F004E78
/* 038E2C 7F0042FC 00000000 */   nop   
/* 038E30 7F004300 0FC2FF04 */  jal   lvlGetSelectedDifficulty
/* 038E34 7F004304 00000000 */   nop   
/* 038E38 7F004308 244C0004 */  addiu $t4, $v0, 4
/* 038E3C 7F00430C 240D0001 */  li    $t5, 1
/* 038E40 7F004310 0FC26919 */  jal   getPlayerCount
/* 038E44 7F004314 018DA004 */   sllv  $s4, $t5, $t4
/* 038E48 7F004318 28410002 */  slti  $at, $v0, 2
/* 038E4C 7F00431C 14200007 */  bnez  $at, .L7F00433C
/* 038E50 7F004320 00000000 */   nop   
/* 038E54 7F004324 0FC26919 */  jal   getPlayerCount
/* 038E58 7F004328 00000000 */   nop   
/* 038E5C 7F00432C 244E0014 */  addiu $t6, $v0, 0x14
/* 038E60 7F004330 240F0001 */  li    $t7, 1
/* 038E64 7F004334 01CFC004 */  sllv  $t8, $t7, $t6
/* 038E68 7F004338 0298A025 */  or    $s4, $s4, $t8
.L7F00433C:
/* 038E6C 7F00433C 3C128007 */  lui   $s2, %hi(g_CurrentSetup+0x0c)
/* 038E70 7F004340 8E525D0C */  lw    $s2, %lo(g_CurrentSetup+0x0c)($s2)
/* 038E74 7F004344 24010030 */  li    $at, 48
/* 038E78 7F004348 00009825 */  move  $s3, $zero
/* 038E7C 7F00434C 92430003 */  lbu   $v1, 3($s2)
/* 038E80 7F004350 24170034 */  li    $s7, 52
/* 038E84 7F004354 506101F6 */  beql  $v1, $at, .L7F004B30
/* 038E88 7F004358 92430003 */   lbu   $v1, 3($s2)
/* 038E8C 7F00435C 4480A000 */  mtc1  $zero, $f20
/* 038E90 7F004360 3416FFFF */  li    $s6, 65535
/* 038E94 7F004364 2468FFFF */  addiu $t0, $v1, -1
.L7F004368:
/* 038E98 7F004368 2D01002F */  sltiu $at, $t0, 0x2f
/* 038E9C 7F00436C 102001E3 */  beqz  $at, other_obj_expand
/* 038EA0 7F004370 00084080 */   sll   $t0, $t0, 2
/* 038EA4 7F004374 3C018005 */  lui   $at, %hi(jpt_object_type_expansion)
/* 038EA8 7F004378 00280821 */  addu  $at, $at, $t0
/* 038EAC 7F00437C 8C28EF68 */  lw    $t0, %lo(jpt_object_type_expansion)($at)
/* 038EB0 7F004380 01000008 */  jr    $t0
/* 038EB4 7F004384 00000000 */   nop   
actor_attr_expand:
/* 038EB8 7F004388 9250000B */  lbu   $s0, 0xb($s2)
/* 038EBC 7F00438C 0FC08BF2 */  jal   chrFindByLiteralId
/* 038EC0 7F004390 8E440004 */   lw    $a0, 4($s2)
/* 038EC4 7F004394 104001D9 */  beqz  $v0, other_obj_expand
/* 038EC8 7F004398 00000000 */   nop   
/* 038ECC 7F00439C 8C490018 */  lw    $t1, 0x18($v0)
/* 038ED0 7F0043A0 112001D6 */  beqz  $t1, other_obj_expand
/* 038ED4 7F0043A4 00000000 */   nop   
/* 038ED8 7F0043A8 8C59001C */  lw    $t9, 0x1c($v0)
/* 038EDC 7F0043AC 132001D3 */  beqz  $t9, other_obj_expand
/* 038EE0 7F0043B0 00000000 */   nop   
/* 038EE4 7F0043B4 100001D1 */  b     other_obj_expand
/* 038EE8 7F0043B8 A0500010 */   sb    $s0, 0x10($v0)
actor_expand:
/* 038EEC 7F0043BC 8FAA0278 */  lw    $t2, 0x278($sp)
/* 038EF0 7F0043C0 02A02025 */  move  $a0, $s5
/* 038EF4 7F0043C4 02402825 */  move  $a1, $s2
/* 038EF8 7F0043C8 114001CC */  beqz  $t2, other_obj_expand
/* 038EFC 7F0043CC 00000000 */   nop   
/* 038F00 7F0043D0 0FC08DC3 */  jal   expand_09_characters
/* 038F04 7F0043D4 02603025 */   move  $a2, $s3
/* 038F08 7F0043D8 100001C8 */  b     other_obj_expand
/* 038F0C 7F0043DC 00000000 */   nop   
door_expand:
/* 038F10 7F0043E0 13C001C6 */  beqz  $fp, other_obj_expand
/* 038F14 7F0043E4 00000000 */   nop   
/* 038F18 7F0043E8 8E4B000C */  lw    $t3, 0xc($s2)
/* 038F1C 7F0043EC 02A02025 */  move  $a0, $s5
/* 038F20 7F0043F0 02402825 */  move  $a1, $s2
/* 038F24 7F0043F4 01746824 */  and   $t5, $t3, $s4
/* 038F28 7F0043F8 15A001C0 */  bnez  $t5, other_obj_expand
/* 038F2C 7F0043FC 00000000 */   nop   
/* 038F30 7F004400 0FC00D20 */  jal   setupDoor
/* 038F34 7F004404 02603025 */   move  $a2, $s3
/* 038F38 7F004408 100001BC */  b     other_obj_expand
/* 038F3C 7F00440C 00000000 */   nop   
door_scale_expand:
/* 038F40 7F004410 8E4C0004 */  lw    $t4, 4($s2)
/* 038F44 7F004414 3C014780 */  li    $at, 0x47800000 # 65536.000000
/* 038F48 7F004418 44815000 */  mtc1  $at, $f10
/* 038F4C 7F00441C 448C3000 */  mtc1  $t4, $f6
/* 038F50 7F004420 3C018003 */  lui   $at, %hi(g_DoorScale)
/* 038F54 7F004424 46803220 */  cvt.s.w $f8, $f6
/* 038F58 7F004428 460A4403 */  div.s $f16, $f8, $f10
/* 038F5C 7F00442C 100001B3 */  b     other_obj_expand
/* 038F60 7F004430 E430A3C0 */   swc1  $f16, %lo(g_DoorScale)($at)
item_expand:
/* 038F64 7F004434 8FAF0278 */  lw    $t7, 0x278($sp)
/* 038F68 7F004438 11E001B0 */  beqz  $t7, other_obj_expand
/* 038F6C 7F00443C 00000000 */   nop   
/* 038F70 7F004440 8E4E000C */  lw    $t6, 0xc($s2)
/* 038F74 7F004444 02A02025 */  move  $a0, $s5
/* 038F78 7F004448 02402825 */  move  $a1, $s2
/* 038F7C 7F00444C 01D4C024 */  and   $t8, $t6, $s4
/* 038F80 7F004450 170001AA */  bnez  $t8, other_obj_expand
/* 038F84 7F004454 00000000 */   nop   
/* 038F88 7F004458 0FC009CE */  jal   weaponAssignToHome
/* 038F8C 7F00445C 02603025 */   move  $a2, $s3
/* 038F90 7F004460 100001A6 */  b     other_obj_expand
/* 038F94 7F004464 00000000 */   nop   
key_expand:
/* 038F98 7F004468 8FA80278 */  lw    $t0, 0x278($sp)
/* 038F9C 7F00446C 110001A3 */  beqz  $t0, other_obj_expand
/* 038FA0 7F004470 00000000 */   nop   
/* 038FA4 7F004474 8E49000C */  lw    $t1, 0xc($s2)
/* 038FA8 7F004478 02A02025 */  move  $a0, $s5
/* 038FAC 7F00447C 02402825 */  move  $a1, $s2
/* 038FB0 7F004480 0134C824 */  and   $t9, $t1, $s4
/* 038FB4 7F004484 1720019D */  bnez  $t9, other_obj_expand
/* 038FB8 7F004488 00000000 */   nop   
/* 038FBC 7F00448C 0FC00A87 */  jal   setupKey
/* 038FC0 7F004490 02603025 */   move  $a2, $s3
/* 038FC4 7F004494 10000199 */  b     other_obj_expand
/* 038FC8 7F004498 00000000 */   nop   
hat_expand:
/* 038FCC 7F00449C 8FAA0278 */  lw    $t2, 0x278($sp)
/* 038FD0 7F0044A0 11400196 */  beqz  $t2, other_obj_expand
/* 038FD4 7F0044A4 00000000 */   nop   
/* 038FD8 7F0044A8 8E4B000C */  lw    $t3, 0xc($s2)
/* 038FDC 7F0044AC 02A02025 */  move  $a0, $s5
/* 038FE0 7F0044B0 02402825 */  move  $a1, $s2
/* 038FE4 7F0044B4 01746824 */  and   $t5, $t3, $s4
/* 038FE8 7F0044B8 15A00190 */  bnez  $t5, other_obj_expand
/* 038FEC 7F0044BC 00000000 */   nop   
/* 038FF0 7F0044C0 0FC00A6A */  jal   setupHat
/* 038FF4 7F0044C4 02603025 */   move  $a2, $s3
/* 038FF8 7F0044C8 1000018C */  b     other_obj_expand
/* 038FFC 7F0044CC 00000000 */   nop   
surv_camera_expand:
/* 039000 7F0044D0 13C0018A */  beqz  $fp, other_obj_expand
/* 039004 7F0044D4 00000000 */   nop   
/* 039008 7F0044D8 8E4C000C */  lw    $t4, 0xc($s2)
/* 03900C 7F0044DC 02A02025 */  move  $a0, $s5
/* 039010 7F0044E0 02402825 */  move  $a1, $s2
/* 039014 7F0044E4 01947824 */  and   $t7, $t4, $s4
/* 039018 7F0044E8 15E00184 */  bnez  $t7, other_obj_expand
/* 03901C 7F0044EC 00000000 */   nop   
/* 039020 7F0044F0 0FC00A8F */  jal   setupCctv
/* 039024 7F0044F4 02603025 */   move  $a2, $s3
/* 039028 7F0044F8 10000180 */  b     other_obj_expand
/* 03902C 7F0044FC 00000000 */   nop   
autogun_expand:
/* 039030 7F004500 13C0017E */  beqz  $fp, other_obj_expand
/* 039034 7F004504 00000000 */   nop   
/* 039038 7F004508 8E4E000C */  lw    $t6, 0xc($s2)
/* 03903C 7F00450C 02A02025 */  move  $a0, $s5
/* 039040 7F004510 02402825 */  move  $a1, $s2
/* 039044 7F004514 01D4C024 */  and   $t8, $t6, $s4
/* 039048 7F004518 17000178 */  bnez  $t8, other_obj_expand
/* 03904C 7F00451C 00000000 */   nop   
/* 039050 7F004520 0FC00B16 */  jal   setupAutogun
/* 039054 7F004524 02603025 */   move  $a2, $s3
/* 039058 7F004528 10000174 */  b     other_obj_expand
/* 03905C 7F00452C 00000000 */   nop   
rack_expand:
/* 039060 7F004530 13C00172 */  beqz  $fp, other_obj_expand
/* 039064 7F004534 00000000 */   nop   
/* 039068 7F004538 8E48000C */  lw    $t0, 0xc($s2)
/* 03906C 7F00453C 02A02025 */  move  $a0, $s5
/* 039070 7F004540 02402825 */  move  $a1, $s2
/* 039074 7F004544 01144824 */  and   $t1, $t0, $s4
/* 039078 7F004548 1520016C */  bnez  $t1, other_obj_expand
/* 03907C 7F00454C 00000000 */   nop   
/* 039080 7F004550 0FC00B87 */  jal   setupHangingMonitors
/* 039084 7F004554 02603025 */   move  $a2, $s3
/* 039088 7F004558 10000168 */  b     other_obj_expand
/* 03908C 7F00455C 00000000 */   nop   
single_screen_display_expand:
/* 039090 7F004560 13C00166 */  beqz  $fp, other_obj_expand
/* 039094 7F004564 00000000 */   nop   
/* 039098 7F004568 8E59000C */  lw    $t9, 0xc($s2)
/* 03909C 7F00456C 02A02025 */  move  $a0, $s5
/* 0390A0 7F004570 02402825 */  move  $a1, $s2
/* 0390A4 7F004574 03345024 */  and   $t2, $t9, $s4
/* 0390A8 7F004578 15400160 */  bnez  $t2, other_obj_expand
/* 0390AC 7F00457C 00000000 */   nop   
/* 0390B0 7F004580 0FC00B8F */  jal   setupSingleMonitor
/* 0390B4 7F004584 02603025 */   move  $a2, $s3
/* 0390B8 7F004588 1000015C */  b     other_obj_expand
/* 0390BC 7F00458C 00000000 */   nop   
multi_screen_display_expand:
/* 0390C0 7F004590 13C0015A */  beqz  $fp, other_obj_expand
/* 0390C4 7F004594 00000000 */   nop   
/* 0390C8 7F004598 8E4B000C */  lw    $t3, 0xc($s2)
/* 0390CC 7F00459C 02A02025 */  move  $a0, $s5
/* 0390D0 7F0045A0 02402825 */  move  $a1, $s2
/* 0390D4 7F0045A4 01746824 */  and   $t5, $t3, $s4
/* 0390D8 7F0045A8 15A00154 */  bnez  $t5, other_obj_expand
/* 0390DC 7F0045AC 00000000 */   nop   
/* 0390E0 7F0045B0 0FC00C34 */  jal   setupMultiMonitor
/* 0390E4 7F0045B4 02603025 */   move  $a2, $s3
/* 0390E8 7F0045B8 10000150 */  b     other_obj_expand
/* 0390EC 7F0045BC 00000000 */   nop   
body_armor_expand:
/* 0390F0 7F0045C0 13C0014E */  beqz  $fp, other_obj_expand
/* 0390F4 7F0045C4 00000000 */   nop   
/* 0390F8 7F0045C8 8E4C000C */  lw    $t4, 0xc($s2)
/* 0390FC 7F0045CC 01947824 */  and   $t7, $t4, $s4
/* 039100 7F0045D0 15E0014A */  bnez  $t7, other_obj_expand
/* 039104 7F0045D4 00000000 */   nop   
/* 039108 7F0045D8 8E4E0080 */  lw    $t6, 0x80($s2)
/* 03910C 7F0045DC 3C014780 */  li    $at, 0x47800000 # 65536.000000
/* 039110 7F0045E0 44813000 */  mtc1  $at, $f6
/* 039114 7F0045E4 448E9000 */  mtc1  $t6, $f18
/* 039118 7F0045E8 02A02025 */  move  $a0, $s5
/* 03911C 7F0045EC 02402825 */  move  $a1, $s2
/* 039120 7F0045F0 46809120 */  cvt.s.w $f4, $f18
/* 039124 7F0045F4 02603025 */  move  $a2, $s3
/* 039128 7F0045F8 46062203 */  div.s $f8, $f4, $f6
/* 03912C 7F0045FC E6480080 */  swc1  $f8, 0x80($s2)
/* 039130 7F004600 C64A0080 */  lwc1  $f10, 0x80($s2)
/* 039134 7F004604 0FC00767 */  jal   domakedefaultobj
/* 039138 7F004608 E64A0084 */   swc1  $f10, 0x84($s2)
/* 03913C 7F00460C 1000013B */  b     other_obj_expand
/* 039140 7F004610 00000000 */   nop   
type2F_tinted_glass:
/* 039144 7F004614 13C00139 */  beqz  $fp, other_obj_expand
/* 039148 7F004618 00000000 */   nop   
/* 03914C 7F00461C 8E58000C */  lw    $t8, 0xc($s2)
/* 039150 7F004620 03144024 */  and   $t0, $t8, $s4
/* 039154 7F004624 15000135 */  bnez  $t0, other_obj_expand
/* 039158 7F004628 00000000 */   nop   
/* 03915C 7F00462C 8E490008 */  lw    $t1, 8($s2)
/* 039160 7F004630 0009C8C0 */  sll   $t9, $t1, 3
/* 039164 7F004634 07230039 */  bgezl $t9, .L7F00471C
/* 039168 7F004638 02A02025 */   move  $a0, $s5
/* 03916C 7F00463C 86420006 */  lh    $v0, 6($s2)
/* 039170 7F004640 3C0B8007 */  lui   $t3, %hi(g_CurrentSetup+0x1C) 
/* 039174 7F004644 27A50118 */  addiu $a1, $sp, 0x118
/* 039178 7F004648 28412710 */  slti  $at, $v0, 0x2710
/* 03917C 7F00464C 14200032 */  bnez  $at, .L7F004718
/* 039180 7F004650 00025100 */   sll   $t2, $v0, 4
/* 039184 7F004654 8D6B5D1C */  lw    $t3, %lo(g_CurrentSetup+0x1C)($t3)
/* 039188 7F004658 01425021 */  addu  $t2, $t2, $v0
/* 03918C 7F00465C 000A5080 */  sll   $t2, $t2, 2
/* 039190 7F004660 3C01FFF5 */  lui   $at, (0xFFF59FC0 >> 16) # lui $at, 0xfff5
/* 039194 7F004664 34219FC0 */  ori   $at, (0xFFF59FC0 & 0xFFFF) # ori $at, $at, 0x9fc0
/* 039198 7F004668 014B8021 */  addu  $s0, $t2, $t3
/* 03919C 7F00466C 02018021 */  addu  $s0, $s0, $at
/* 0391A0 7F004670 0FC006F5 */  jal   sub_GAME_7F001BD4
/* 0391A4 7F004674 02002025 */   move  $a0, $s0
/* 0391A8 7F004678 3C014120 */  li    $at, 0x41200000 # 10.000000
/* 0391AC 7F00467C 44810000 */  mtc1  $at, $f0
/* 0391B0 7F004680 C610000C */  lwc1  $f16, 0xc($s0)
/* 0391B4 7F004684 C7A40118 */  lwc1  $f4, 0x118($sp)
/* 0391B8 7F004688 27A40118 */  addiu $a0, $sp, 0x118
/* 0391BC 7F00468C 46008482 */  mul.s $f18, $f16, $f0
/* 0391C0 7F004690 C7B0011C */  lwc1  $f16, 0x11c($sp)
/* 0391C4 7F004694 27A5010C */  addiu $a1, $sp, 0x10c
/* 0391C8 7F004698 46049180 */  add.s $f6, $f18, $f4
/* 0391CC 7F00469C E7A6010C */  swc1  $f6, 0x10c($sp)
/* 0391D0 7F0046A0 C6080010 */  lwc1  $f8, 0x10($s0)
/* 0391D4 7F0046A4 46004282 */  mul.s $f10, $f8, $f0
/* 0391D8 7F0046A8 46105480 */  add.s $f18, $f10, $f16
/* 0391DC 7F0046AC C7AA0120 */  lwc1  $f10, 0x120($sp)
/* 0391E0 7F0046B0 E7B20110 */  swc1  $f18, 0x110($sp)
/* 0391E4 7F0046B4 C6060014 */  lwc1  $f6, 0x14($s0)
/* 0391E8 7F0046B8 46003202 */  mul.s $f8, $f6, $f0
/* 0391EC 7F0046BC 460A4480 */  add.s $f18, $f8, $f10
/* 0391F0 7F0046C0 E7B20114 */  swc1  $f18, 0x114($sp)
/* 0391F4 7F0046C4 C606000C */  lwc1  $f6, 0xc($s0)
/* 0391F8 7F0046C8 46060202 */  mul.s $f8, $f0, $f6
/* 0391FC 7F0046CC 46082481 */  sub.s $f18, $f4, $f8
/* 039200 7F0046D0 E7B20118 */  swc1  $f18, 0x118($sp)
/* 039204 7F0046D4 C6060010 */  lwc1  $f6, 0x10($s0)
/* 039208 7F0046D8 46060102 */  mul.s $f4, $f0, $f6
/* 03920C 7F0046DC 46048201 */  sub.s $f8, $f16, $f4
/* 039210 7F0046E0 E7A8011C */  swc1  $f8, 0x11c($sp)
/* 039214 7F0046E4 C6120014 */  lwc1  $f18, 0x14($s0)
/* 039218 7F0046E8 46120182 */  mul.s $f6, $f0, $f18
/* 03921C 7F0046EC 46065401 */  sub.s $f16, $f10, $f6
/* 039220 7F0046F0 0FC2E781 */  jal   sub_GAME_7F0B9E04
/* 039224 7F0046F4 E7B00120 */   swc1  $f16, 0x120($sp)
/* 039228 7F0046F8 8E4D0090 */  lw    $t5, 0x90($s2)
/* 03922C 7F0046FC 3C014780 */  li    $at, 0x47800000 # 65536.000000
/* 039230 7F004700 44819000 */  mtc1  $at, $f18
/* 039234 7F004704 448D2000 */  mtc1  $t5, $f4
/* 039238 7F004708 AE42008C */  sw    $v0, 0x8c($s2)
/* 03923C 7F00470C 46802220 */  cvt.s.w $f8, $f4
/* 039240 7F004710 46124283 */  div.s $f10, $f8, $f18
/* 039244 7F004714 E64A0090 */  swc1  $f10, 0x90($s2)
.L7F004718:
/* 039248 7F004718 02A02025 */  move  $a0, $s5
.L7F00471C:
/* 03924C 7F00471C 02402825 */  move  $a1, $s2
/* 039250 7F004720 0FC00767 */  jal   domakedefaultobj
/* 039254 7F004724 02603025 */   move  $a2, $s3
/* 039258 7F004728 100000F4 */  b     other_obj_expand
/* 03925C 7F00472C 00000000 */   nop   
obj_03_expand:
/* 039260 7F004730 13C000F2 */  beqz  $fp, other_obj_expand
/* 039264 7F004734 00000000 */   nop   
/* 039268 7F004738 8E4C000C */  lw    $t4, 0xc($s2)
/* 03926C 7F00473C 02A02025 */  move  $a0, $s5
/* 039270 7F004740 02402825 */  move  $a1, $s2
/* 039274 7F004744 01947824 */  and   $t7, $t4, $s4
/* 039278 7F004748 15E000EC */  bnez  $t7, other_obj_expand
/* 03927C 7F00474C 00000000 */   nop   
/* 039280 7F004750 0FC00767 */  jal   domakedefaultobj
/* 039284 7F004754 02603025 */   move  $a2, $s3
/* 039288 7F004758 100000E8 */  b     other_obj_expand
/* 03928C 7F00475C 00000000 */   nop   
ammo_box_expand:
/* 039290 7F004760 0FC26919 */  jal   getPlayerCount
/* 039294 7F004764 24100001 */   li    $s0, 1
/* 039298 7F004768 28410002 */  slti  $at, $v0, 2
/* 03929C 7F00476C 1420000E */  bnez  $at, .L7F0047A8
/* 0392A0 7F004770 00000000 */   nop   
/* 0392A4 7F004774 0FC31985 */  jal   getPtrMPWeaponSetData
/* 0392A8 7F004778 00000000 */   nop   
/* 0392AC 7F00477C 3C0E8007 */  lui   $t6, %hi(lastmpweaponnum) 
/* 0392B0 7F004780 8DCE9540 */  lw    $t6, %lo(lastmpweaponnum)($t6)
/* 0392B4 7F004784 000EC080 */  sll   $t8, $t6, 2
/* 0392B8 7F004788 030EC023 */  subu  $t8, $t8, $t6
/* 0392BC 7F00478C 0018C0C0 */  sll   $t8, $t8, 3
/* 0392C0 7F004790 00581821 */  addu  $v1, $v0, $t8
/* 0392C4 7F004794 8C64000C */  lw    $a0, 0xc($v1)
/* 0392C8 7F004798 8C700010 */  lw    $s0, 0x10($v1)
/* 0392CC 7F00479C 00044080 */  sll   $t0, $a0, 2
/* 0392D0 7F0047A0 02484821 */  addu  $t1, $s2, $t0
/* 0392D4 7F0047A4 A530007E */  sh    $s0, 0x7e($t1)
.L7F0047A8:
/* 0392D8 7F0047A8 1A0000D4 */  blez  $s0, other_obj_expand
/* 0392DC 7F0047AC 00000000 */   nop   
/* 0392E0 7F0047B0 13C000D2 */  beqz  $fp, other_obj_expand
/* 0392E4 7F0047B4 00000000 */   nop   
/* 0392E8 7F0047B8 8E59000C */  lw    $t9, 0xc($s2)
/* 0392EC 7F0047BC 00008825 */  move  $s1, $zero
/* 0392F0 7F0047C0 02408025 */  move  $s0, $s2
/* 0392F4 7F0047C4 03345024 */  and   $t2, $t9, $s4
/* 0392F8 7F0047C8 154000CC */  bnez  $t2, other_obj_expand
/* 0392FC 7F0047CC 00000000 */   nop   
.L7F0047D0:
/* 039300 7F0047D0 960B0082 */  lhu   $t3, 0x82($s0)
/* 039304 7F0047D4 59600007 */  blezl $t3, .L7F0047F4
/* 039308 7F0047D8 26310004 */   addiu $s1, $s1, 4
/* 03930C 7F0047DC 96040080 */  lhu   $a0, 0x80($s0)
/* 039310 7F0047E0 52C40004 */  beql  $s6, $a0, .L7F0047F4
/* 039314 7F0047E4 26310004 */   addiu $s1, $s1, 4
/* 039318 7F0047E8 0FC15B0E */  jal   modelLoad
/* 03931C 7F0047EC 00000000 */   nop   
/* 039320 7F0047F0 26310004 */  addiu $s1, $s1, 4
.L7F0047F4:
/* 039324 7F0047F4 1637FFF6 */  bne   $s1, $s7, .L7F0047D0
/* 039328 7F0047F8 26100004 */   addiu $s0, $s0, 4
/* 03932C 7F0047FC 02A02025 */  move  $a0, $s5
/* 039330 7F004800 02402825 */  move  $a1, $s2
/* 039334 7F004804 0FC00767 */  jal   domakedefaultobj
/* 039338 7F004808 02603025 */   move  $a2, $s3
/* 03933C 7F00480C 100000BB */  b     other_obj_expand
/* 039340 7F004810 00000000 */   nop   
type2D_tank:
/* 039344 7F004814 13C000B9 */  beqz  $fp, other_obj_expand
/* 039348 7F004818 00000000 */   nop   
/* 03934C 7F00481C 8E4D000C */  lw    $t5, 0xc($s2)
/* 039350 7F004820 24040020 */  li    $a0, 32
/* 039354 7F004824 01B46024 */  and   $t4, $t5, $s4
/* 039358 7F004828 158000B4 */  bnez  $t4, other_obj_expand
/* 03935C 7F00482C 00000000 */   nop   
/* 039360 7F004830 0FC015C4 */  jal   weaponLoadProjectileModels
/* 039364 7F004834 E7B400E8 */   swc1  $f20, 0xe8($sp)
/* 039368 7F004838 02A02025 */  move  $a0, $s5
/* 03936C 7F00483C 02402825 */  move  $a1, $s2
/* 039370 7F004840 0FC00767 */  jal   domakedefaultobj
/* 039374 7F004844 02603025 */   move  $a2, $s3
/* 039378 7F004848 E65400C8 */  swc1  $f20, 0xc8($s2)
/* 03937C 7F00484C E65400CC */  swc1  $f20, 0xcc($s2)
/* 039380 7F004850 C64C0038 */  lwc1  $f12, 0x38($s2)
/* 039384 7F004854 0FC16A8C */  jal   atan2f
/* 039388 7F004858 C64E0040 */   lwc1  $f14, 0x40($s2)
/* 03938C 7F00485C 3C018005 */  lui   $at, %hi(D_8004F024)
/* 039390 7F004860 C426F024 */  lwc1  $f6, %lo(D_8004F024)($at)
/* 039394 7F004864 8E420010 */  lw    $v0, 0x10($s2)
/* 039398 7F004868 46003401 */  sub.s $f16, $f6, $f0
/* 03939C 7F00486C 10400006 */  beqz  $v0, .L7F004888
/* 0393A0 7F004870 E65000DC */   swc1  $f16, 0xdc($s2)
/* 0393A4 7F004874 8C440014 */  lw    $a0, 0x14($v0)
/* 0393A8 7F004878 8C450008 */  lw    $a1, 8($v0)
/* 0393AC 7F00487C 0FC2CA5C */  jal   stanGetPositionYValue
/* 0393B0 7F004880 8C460010 */   lw    $a2, 0x10($v0)
/* 0393B4 7F004884 E7A000E8 */  swc1  $f0, 0xe8($sp)
.L7F004888:
/* 0393B8 7F004888 C7A200E8 */  lwc1  $f2, 0xe8($sp)
/* 0393BC 7F00488C 3C018005 */  lui   $at, %hi(D_8004F028)
/* 0393C0 7F004890 E64200D4 */  swc1  $f2, 0xd4($s2)
/* 0393C4 7F004894 C424F028 */  lwc1  $f4, %lo(D_8004F028)($at)
/* 0393C8 7F004898 46041203 */  div.s $f8, $f2, $f4
/* 0393CC 7F00489C 10000097 */  b     other_obj_expand
/* 0393D0 7F0048A0 E64800D0 */   swc1  $f8, 0xd0($s2)
type27_wheeled_vehicle:
/* 0393D4 7F0048A4 13C00095 */  beqz  $fp, other_obj_expand
/* 0393D8 7F0048A8 00000000 */   nop   
/* 0393DC 7F0048AC 8E4F000C */  lw    $t7, 0xc($s2)
/* 0393E0 7F0048B0 02A02025 */  move  $a0, $s5
/* 0393E4 7F0048B4 02402825 */  move  $a1, $s2
/* 0393E8 7F0048B8 01F47024 */  and   $t6, $t7, $s4
/* 0393EC 7F0048BC 15C0008F */  bnez  $t6, other_obj_expand
/* 0393F0 7F0048C0 00000000 */   nop   
/* 0393F4 7F0048C4 0FC00767 */  jal   domakedefaultobj
/* 0393F8 7F0048C8 02603025 */   move  $a2, $s3
/* 0393FC 7F0048CC 8E440014 */  lw    $a0, 0x14($s2)
/* 039400 7F0048D0 5080000E */  beql  $a0, $zero, .L7F00490C
/* 039404 7F0048D4 3C01BF80 */   lui   $at, 0xbf80
/* 039408 7F0048D8 8C980008 */  lw    $t8, 8($a0)
/* 03940C 7F0048DC 8F080008 */  lw    $t0, 8($t8)
/* 039410 7F0048E0 8D050014 */  lw    $a1, 0x14($t0)
/* 039414 7F0048E4 50A00009 */  beql  $a1, $zero, .L7F00490C
/* 039418 7F0048E8 3C01BF80 */   lui   $at, 0xbf80
/* 03941C 7F0048EC 0FC1B1E7 */  jal   modelGetNodeRwData
/* 039420 7F0048F0 00000000 */   nop   
/* 039424 7F0048F4 8E490008 */  lw    $t1, 8($s2)
/* 039428 7F0048F8 3C011000 */  li    $at, 0x10000000 # 0.000000
/* 03942C 7F0048FC 0121C824 */  and   $t9, $t1, $at
/* 039430 7F004900 2F2A0001 */  sltiu $t2, $t9, 1
/* 039434 7F004904 AC4A0000 */  sw    $t2, ($v0)
/* 039438 7F004908 3C01BF80 */  li    $at, 0xBF800000 # -1.000000
.L7F00490C:
/* 03943C 7F00490C 44819000 */  mtc1  $at, $f18
/* 039440 7F004910 E6540088 */  swc1  $f20, 0x88($s2)
/* 039444 7F004914 E654008C */  swc1  $f20, 0x8c($s2)
/* 039448 7F004918 E6540090 */  swc1  $f20, 0x90($s2)
/* 03944C 7F00491C E6540094 */  swc1  $f20, 0x94($s2)
/* 039450 7F004920 E654009C */  swc1  $f20, 0x9c($s2)
/* 039454 7F004924 E65400A0 */  swc1  $f20, 0xa0($s2)
/* 039458 7F004928 8E440080 */  lw    $a0, 0x80($s2)
/* 03945C 7F00492C 0FC0D4E6 */  jal   ailistFindById
/* 039460 7F004930 E6520098 */   swc1  $f18, 0x98($s2)
/* 039464 7F004934 240BFFFF */  li    $t3, -1
/* 039468 7F004938 AE420080 */  sw    $v0, 0x80($s2)
/* 03946C 7F00493C A6400084 */  sh    $zero, 0x84($s2)
/* 039470 7F004940 A64B0086 */  sh    $t3, 0x86($s2)
/* 039474 7F004944 AE4000A4 */  sw    $zero, 0xa4($s2)
/* 039478 7F004948 AE4000A8 */  sw    $zero, 0xa8($s2)
/* 03947C 7F00494C 1000006B */  b     other_obj_expand
/* 039480 7F004950 AE4000AC */   sw    $zero, 0xac($s2)
type28_aircraft:
/* 039484 7F004954 13C00069 */  beqz  $fp, other_obj_expand
/* 039488 7F004958 00000000 */   nop   
/* 03948C 7F00495C 8E4D000C */  lw    $t5, 0xc($s2)
/* 039490 7F004960 02A02025 */  move  $a0, $s5
/* 039494 7F004964 02402825 */  move  $a1, $s2
/* 039498 7F004968 01B46024 */  and   $t4, $t5, $s4
/* 03949C 7F00496C 15800063 */  bnez  $t4, other_obj_expand
/* 0394A0 7F004970 00000000 */   nop   
/* 0394A4 7F004974 0FC00767 */  jal   domakedefaultobj
/* 0394A8 7F004978 02603025 */   move  $a2, $s3
/* 0394AC 7F00497C 3C01BF80 */  li    $at, 0xBF800000 # -1.000000
/* 0394B0 7F004980 44810000 */  mtc1  $at, $f0
/* 0394B4 7F004984 E6540098 */  swc1  $f20, 0x98($s2)
/* 0394B8 7F004988 E654009C */  swc1  $f20, 0x9c($s2)
/* 0394BC 7F00498C E6540088 */  swc1  $f20, 0x88($s2)
/* 0394C0 7F004990 E654008C */  swc1  $f20, 0x8c($s2)
/* 0394C4 7F004994 E6540090 */  swc1  $f20, 0x90($s2)
/* 0394C8 7F004998 E65400A4 */  swc1  $f20, 0xa4($s2)
/* 0394CC 7F00499C 8E440080 */  lw    $a0, 0x80($s2)
/* 0394D0 7F0049A0 E64000A0 */  swc1  $f0, 0xa0($s2)
/* 0394D4 7F0049A4 0FC0D4E6 */  jal   ailistFindById
/* 0394D8 7F0049A8 E6400094 */   swc1  $f0, 0x94($s2)
/* 0394DC 7F0049AC 240FFFFF */  li    $t7, -1
/* 0394E0 7F0049B0 AE420080 */  sw    $v0, 0x80($s2)
/* 0394E4 7F0049B4 A6400084 */  sh    $zero, 0x84($s2)
/* 0394E8 7F0049B8 A64F0086 */  sh    $t7, 0x86($s2)
/* 0394EC 7F0049BC AE4000A8 */  sw    $zero, 0xa8($s2)
/* 0394F0 7F0049C0 AE4000AC */  sw    $zero, 0xac($s2)
/* 0394F4 7F0049C4 1000004D */  b     other_obj_expand
/* 0394F8 7F0049C8 AE4000B0 */   sw    $zero, 0xb0($s2)
tag_expand:
/* 0394FC 7F0049CC 864E0006 */  lh    $t6, 6($s2)
/* 039500 7F0049D0 02A02025 */  move  $a0, $s5
/* 039504 7F0049D4 0FC15BA8 */  jal   setupCommandGetObject
/* 039508 7F0049D8 01D32821 */   addu  $a1, $t6, $s3
/* 03950C 7F0049DC 10400004 */  beqz  $v0, .L7F0049F0
/* 039510 7F0049E0 AE42000C */   sw    $v0, 0xc($s2)
/* 039514 7F0049E4 8C580064 */  lw    $t8, 0x64($v0)
/* 039518 7F0049E8 37080010 */  ori   $t0, $t8, 0x10
/* 03951C 7F0049EC AC480064 */  sw    $t0, 0x64($v0)
.L7F0049F0:
/* 039520 7F0049F0 0FC013E2 */  jal   set_parent_cur_tag_entry
/* 039524 7F0049F4 02402025 */   move  $a0, $s2
/* 039528 7F0049F8 10000040 */  b     other_obj_expand
/* 03952C 7F0049FC 00000000 */   nop   
type25_rename:
/* 039530 7F004A00 8E490004 */  lw    $t1, 4($s2)
/* 039534 7F004A04 02A02025 */  move  $a0, $s5
/* 039538 7F004A08 0FC15BA8 */  jal   setupCommandGetObject
/* 03953C 7F004A0C 01332821 */   addu  $a1, $t1, $s3
/* 039540 7F004A10 10400004 */  beqz  $v0, .L7F004A24
/* 039544 7F004A14 AE420024 */   sw    $v0, 0x24($s2)
/* 039548 7F004A18 8C590064 */  lw    $t9, 0x64($v0)
/* 03954C 7F004A1C 372A0400 */  ori   $t2, $t9, 0x400
/* 039550 7F004A20 AC4A0064 */  sw    $t2, 0x64($v0)
.L7F004A24:
/* 039554 7F004A24 0FC23628 */  jal   bondinvAddTextOverride
/* 039558 7F004A28 02402025 */   move  $a0, $s2
/* 03955C 7F004A2C 10000033 */  b     other_obj_expand
/* 039560 7F004A30 00000000 */   nop   
type23_solo_brief_text:
/* 039564 7F004A34 0FC013E8 */  jal   setup_briefing_text_entry_parent
/* 039568 7F004A38 02402025 */   move  $a0, $s2
/* 03956C 7F004A3C 1000002F */  b     other_obj_expand
/* 039570 7F004A40 00000000 */   nop   
type2E_viewport_pos:
/* 039574 7F004A44 8E4B0004 */  lw    $t3, 4($s2)
/* 039578 7F004A48 3C0142C8 */  li    $at, 0x42C80000 # 100.000000
/* 03957C 7F004A4C 44810000 */  mtc1  $at, $f0
/* 039580 7F004A50 448B5000 */  mtc1  $t3, $f10
/* 039584 7F004A54 8E4C000C */  lw    $t4, 0xc($s2)
/* 039588 7F004A58 8E4D0008 */  lw    $t5, 8($s2)
/* 03958C 7F004A5C 468051A0 */  cvt.s.w $f6, $f10
/* 039590 7F004A60 448C5000 */  mtc1  $t4, $f10
/* 039594 7F004A64 448D2000 */  mtc1  $t5, $f4
/* 039598 7F004A68 8E4F0010 */  lw    $t7, 0x10($s2)
/* 03959C 7F004A6C 8E4E0014 */  lw    $t6, 0x14($s2)
/* 0395A0 7F004A70 46802220 */  cvt.s.w $f8, $f4
/* 0395A4 7F004A74 448F2000 */  mtc1  $t7, $f4
/* 0395A8 7F004A78 3C014780 */  li    $at, 0x47800000 # 65536.000000
/* 0395AC 7F004A7C 46003403 */  div.s $f16, $f6, $f0
/* 0395B0 7F004A80 468051A0 */  cvt.s.w $f6, $f10
/* 0395B4 7F004A84 46004483 */  div.s $f18, $f8, $f0
/* 0395B8 7F004A88 E6500004 */  swc1  $f16, 4($s2)
/* 0395BC 7F004A8C 46802220 */  cvt.s.w $f8, $f4
/* 0395C0 7F004A90 44812000 */  mtc1  $at, $f4
/* 0395C4 7F004A94 46003403 */  div.s $f16, $f6, $f0
/* 0395C8 7F004A98 448E3000 */  mtc1  $t6, $f6
/* 0395CC 7F004A9C E6520008 */  swc1  $f18, 8($s2)
/* 0395D0 7F004AA0 44819000 */  mtc1  $at, $f18
/* 0395D4 7F004AA4 00000000 */  nop   
/* 0395D8 7F004AA8 46124283 */  div.s $f10, $f8, $f18
/* 0395DC 7F004AAC E650000C */  swc1  $f16, 0xc($s2)
/* 0395E0 7F004AB0 46803420 */  cvt.s.w $f16, $f6
/* 0395E4 7F004AB4 46048203 */  div.s $f8, $f16, $f4
/* 0395E8 7F004AB8 E64A0010 */  swc1  $f10, 0x10($s2)
/* 0395EC 7F004ABC 1000000F */  b     other_obj_expand
/* 0395F0 7F004AC0 E6480014 */   swc1  $f8, 0x14($s2)
type17_objective_expand:
/* 0395F4 7F004AC4 0FC013EE */  jal   add_ptr_to_objective
/* 0395F8 7F004AC8 02402025 */   move  $a0, $s2
/* 0395FC 7F004ACC 1000000B */  b     other_obj_expand
/* 039600 7F004AD0 00000000 */   nop   
type20_subobjective_expand:
/* 039604 7F004AD4 0FC013FD */  jal   set_parent_cur_obj_enter_room
/* 039608 7F004AD8 02402025 */   move  $a0, $s2
/* 03960C 7F004ADC 10000007 */  b     other_obj_expand
/* 039610 7F004AE0 00000000 */   nop   
type21_subobjective_expand:
/* 039614 7F004AE4 0FC01403 */  jal   set_parent_cur_obj_deposited_in_room
/* 039618 7F004AE8 02402025 */   move  $a0, $s2
/* 03961C 7F004AEC 10000003 */  b     other_obj_expand
/* 039620 7F004AF0 00000000 */   nop   
type1E_subobjective_expand:
/* 039624 7F004AF4 0FC01409 */  jal   set_parent_cur_obj_photograph
/* 039628 7F004AF8 02402025 */   move  $a0, $s2
other_obj_expand:
/* 03962C 7F004AFC 0FC15A3D */  jal   sizepropdef
/* 039630 7F004B00 02402025 */   move  $a0, $s2
/* 039634 7F004B04 0002C080 */  sll   $t8, $v0, 2
/* 039638 7F004B08 03129021 */  addu  $s2, $t8, $s2
/* 03963C 7F004B0C 92430003 */  lbu   $v1, 3($s2)
/* 039640 7F004B10 24010030 */  li    $at, 48
/* 039644 7F004B14 26730001 */  addiu $s3, $s3, 1
/* 039648 7F004B18 5461FE13 */  bnel  $v1, $at, .L7F004368
/* 03964C 7F004B1C 2468FFFF */   addiu $t0, $v1, -1
/* 039650 7F004B20 3C128007 */  lui   $s2, %hi(g_CurrentSetup+0x0c)
/* 039654 7F004B24 8E525D0C */  lw    $s2, %lo(g_CurrentSetup+0x0c)($s2)
/* 039658 7F004B28 00009825 */  move  $s3, $zero
/* 03965C 7F004B2C 92430003 */  lbu   $v1, 3($s2)
.L7F004B30:
/* 039660 7F004B30 24010030 */  li    $at, 48
/* 039664 7F004B34 3C170008 */  lui   $s7, 8
/* 039668 7F004B38 106100CF */  beq   $v1, $at, .L7F004E78
/* 03966C 7F004B3C 24160008 */   li    $s6, 8
/* 039670 7F004B40 241E002B */  li    $fp, 43
/* 039674 7F004B44 24140001 */  li    $s4, 1
/* 039678 7F004B48 2468FFFD */  addiu $t0, $v1, -3
.L7F004B4C:
/* 03967C 7F004B4C 2D01002D */  sltiu $at, $t0, 0x2d
/* 039680 7F004B50 102000A4 */  beqz  $at, .L7F004DE4
/* 039684 7F004B54 00084080 */   sll   $t0, $t0, 2
/* 039688 7F004B58 3C018005 */  lui   $at, %hi(jpt_8004F02C)
/* 03968C 7F004B5C 00280821 */  addu  $at, $at, $t0
/* 039690 7F004B60 8C28F02C */  lw    $t0, %lo(jpt_8004F02C)($at)
/* 039694 7F004B64 01000008 */  jr    $t0
/* 039698 7F004B68 00000000 */   nop   
.L7F004B6C:
/* 03969C 7F004B6C 8E490010 */  lw    $t1, 0x10($s2)
/* 0396A0 7F004B70 1120009C */  beqz  $t1, .L7F004DE4
/* 0396A4 7F004B74 00000000 */   nop   
/* 0396A8 7F004B78 8E590008 */  lw    $t9, 8($s2)
/* 0396AC 7F004B7C 332A8000 */  andi  $t2, $t9, 0x8000
/* 0396B0 7F004B80 11400098 */  beqz  $t2, .L7F004DE4
/* 0396B4 7F004B84 00000000 */   nop   
/* 0396B8 7F004B88 86420006 */  lh    $v0, 6($s2)
/* 0396BC 7F004B8C 02A02025 */  move  $a0, $s5
/* 0396C0 7F004B90 0FC15BA8 */  jal   setupCommandGetObject
/* 0396C4 7F004B94 02622821 */   addu  $a1, $s3, $v0
/* 0396C8 7F004B98 10400092 */  beqz  $v0, .L7F004DE4
/* 0396CC 7F004B9C 00408025 */   move  $s0, $v0
/* 0396D0 7F004BA0 8C4B0010 */  lw    $t3, 0x10($v0)
/* 0396D4 7F004BA4 1160008F */  beqz  $t3, .L7F004DE4
/* 0396D8 7F004BA8 00000000 */   nop   
/* 0396DC 7F004BAC 8E4D0064 */  lw    $t5, 0x64($s2)
/* 0396E0 7F004BB0 8E440014 */  lw    $a0, 0x14($s2)
/* 0396E4 7F004BB4 01B76025 */  or    $t4, $t5, $s7
/* 0396E8 7F004BB8 AE4C0064 */  sw    $t4, 0x64($s2)
/* 0396EC 7F004BBC 0FC1B39E */  jal   modelSetScale
/* 0396F0 7F004BC0 8C850014 */   lw    $a1, 0x14($a0)
/* 0396F4 7F004BC4 8E440010 */  lw    $a0, 0x10($s2)
/* 0396F8 7F004BC8 0FC0E969 */  jal   chrpropReparent
/* 0396FC 7F004BCC 8E050010 */   lw    $a1, 0x10($s0)
/* 039700 7F004BD0 10000084 */  b     .L7F004DE4
/* 039704 7F004BD4 00000000 */   nop   
.L7F004BD8:
/* 039708 7F004BD8 8E4F0004 */  lw    $t7, 4($s2)
/* 03970C 7F004BDC 0FC15AA2 */  jal   setupGetPtrToCommandByIndex
/* 039710 7F004BE0 01F32021 */   addu  $a0, $t7, $s3
/* 039714 7F004BE4 8E4E0008 */  lw    $t6, 8($s2)
/* 039718 7F004BE8 00408025 */  move  $s0, $v0
/* 03971C 7F004BEC 0FC15AA2 */  jal   setupGetPtrToCommandByIndex
/* 039720 7F004BF0 01D32021 */   addu  $a0, $t6, $s3
/* 039724 7F004BF4 1200007B */  beqz  $s0, .L7F004DE4
/* 039728 7F004BF8 00402825 */   move  $a1, $v0
/* 03972C 7F004BFC 10400079 */  beqz  $v0, .L7F004DE4
/* 039730 7F004C00 00000000 */   nop   
/* 039734 7F004C04 92180003 */  lbu   $t8, 3($s0)
/* 039738 7F004C08 16D80076 */  bne   $s6, $t8, .L7F004DE4
/* 03973C 7F004C0C 00000000 */   nop   
/* 039740 7F004C10 90480003 */  lbu   $t0, 3($v0)
/* 039744 7F004C14 16C80073 */  bne   $s6, $t0, .L7F004DE4
/* 039748 7F004C18 00000000 */   nop   
/* 03974C 7F004C1C 0FC1475D */  jal   propweaponSetDual
/* 039750 7F004C20 02002025 */   move  $a0, $s0
/* 039754 7F004C24 1000006F */  b     .L7F004DE4
/* 039758 7F004C28 00000000 */   nop   
.L7F004C2C:
/* 03975C 7F004C2C 8E420004 */  lw    $v0, 4($s2)
/* 039760 7F004C30 8E510008 */  lw    $s1, 8($s2)
/* 039764 7F004C34 02A02025 */  move  $a0, $s5
/* 039768 7F004C38 0FC15BA8 */  jal   setupCommandGetObject
/* 03976C 7F004C3C 02622821 */   addu  $a1, $s3, $v0
/* 039770 7F004C40 00408025 */  move  $s0, $v0
/* 039774 7F004C44 0FC15AA2 */  jal   setupGetPtrToCommandByIndex
/* 039778 7F004C48 02712021 */   addu  $a0, $s3, $s1
/* 03977C 7F004C4C 12000065 */  beqz  $s0, .L7F004DE4
/* 039780 7F004C50 00000000 */   nop   
/* 039784 7F004C54 8E030010 */  lw    $v1, 0x10($s0)
/* 039788 7F004C58 10600062 */  beqz  $v1, .L7F004DE4
/* 03978C 7F004C5C 00000000 */   nop   
/* 039790 7F004C60 10400060 */  beqz  $v0, .L7F004DE4
/* 039794 7F004C64 00000000 */   nop   
/* 039798 7F004C68 90490003 */  lbu   $t1, 3($v0)
/* 03979C 7F004C6C 1689005D */  bne   $s4, $t1, .L7F004DE4
/* 0397A0 7F004C70 00000000 */   nop   
/* 0397A4 7F004C74 8C590010 */  lw    $t9, 0x10($v0)
/* 0397A8 7F004C78 1320005A */  beqz  $t9, .L7F004DE4
/* 0397AC 7F004C7C 00000000 */   nop   
/* 0397B0 7F004C80 AE430004 */  sw    $v1, 4($s2)
/* 0397B4 7F004C84 8C4A0010 */  lw    $t2, 0x10($v0)
/* 0397B8 7F004C88 02402025 */  move  $a0, $s2
/* 0397BC 7F004C8C 0FC00644 */  jal   initSetLevelLoadPropSwitch
/* 0397C0 7F004C90 AE4A0008 */   sw    $t2, 8($s2)
/* 0397C4 7F004C94 8E0B0064 */  lw    $t3, 0x64($s0)
/* 0397C8 7F004C98 356D0001 */  ori   $t5, $t3, 1
/* 0397CC 7F004C9C 10000051 */  b     .L7F004DE4
/* 0397D0 7F004CA0 AE0D0064 */   sw    $t5, 0x64($s0)
.L7F004CA4:
/* 0397D4 7F004CA4 8E420004 */  lw    $v0, 4($s2)
/* 0397D8 7F004CA8 8E4C000C */  lw    $t4, 0xc($s2)
/* 0397DC 7F004CAC 8E510008 */  lw    $s1, 8($s2)
/* 0397E0 7F004CB0 02A02025 */  move  $a0, $s5
/* 0397E4 7F004CB4 02622821 */  addu  $a1, $s3, $v0
/* 0397E8 7F004CB8 0FC15BA8 */  jal   setupCommandGetObject
/* 0397EC 7F004CBC AFAC0080 */   sw    $t4, 0x80($sp)
/* 0397F0 7F004CC0 00408025 */  move  $s0, $v0
/* 0397F4 7F004CC4 02A02025 */  move  $a0, $s5
/* 0397F8 7F004CC8 0FC15BA8 */  jal   setupCommandGetObject
/* 0397FC 7F004CCC 02712821 */   addu  $a1, $s3, $s1
/* 039800 7F004CD0 8FAF0080 */  lw    $t7, 0x80($sp)
/* 039804 7F004CD4 00408825 */  move  $s1, $v0
/* 039808 7F004CD8 02A02025 */  move  $a0, $s5
/* 03980C 7F004CDC 0FC15BA8 */  jal   setupCommandGetObject
/* 039810 7F004CE0 026F2821 */   addu  $a1, $s3, $t7
/* 039814 7F004CE4 1200003F */  beqz  $s0, .L7F004DE4
/* 039818 7F004CE8 00000000 */   nop   
/* 03981C 7F004CEC 8E0E0010 */  lw    $t6, 0x10($s0)
/* 039820 7F004CF0 11C0003C */  beqz  $t6, .L7F004DE4
/* 039824 7F004CF4 00000000 */   nop   
/* 039828 7F004CF8 1220003A */  beqz  $s1, .L7F004DE4
/* 03982C 7F004CFC 00000000 */   nop   
/* 039830 7F004D00 8E380010 */  lw    $t8, 0x10($s1)
/* 039834 7F004D04 13000037 */  beqz  $t8, .L7F004DE4
/* 039838 7F004D08 00000000 */   nop   
/* 03983C 7F004D0C 92280003 */  lbu   $t0, 3($s1)
/* 039840 7F004D10 17C80034 */  bne   $fp, $t0, .L7F004DE4
/* 039844 7F004D14 00000000 */   nop   
/* 039848 7F004D18 10400032 */  beqz  $v0, .L7F004DE4
/* 03984C 7F004D1C 00000000 */   nop   
/* 039850 7F004D20 8C490010 */  lw    $t1, 0x10($v0)
/* 039854 7F004D24 1120002F */  beqz  $t1, .L7F004DE4
/* 039858 7F004D28 00000000 */   nop   
/* 03985C 7F004D2C 90590003 */  lbu   $t9, 3($v0)
/* 039860 7F004D30 02402025 */  move  $a0, $s2
/* 039864 7F004D34 1699002B */  bne   $s4, $t9, .L7F004DE4
/* 039868 7F004D38 00000000 */   nop   
/* 03986C 7F004D3C AE500004 */  sw    $s0, 4($s2)
/* 039870 7F004D40 AE510008 */  sw    $s1, 8($s2)
/* 039874 7F004D44 AE42000C */  sw    $v0, 0xc($s2)
/* 039878 7F004D48 0FC00650 */  jal   initSetLevelLoadPropSafeItem
/* 03987C 7F004D4C AFA20074 */   sw    $v0, 0x74($sp)
/* 039880 7F004D50 8E0A000C */  lw    $t2, 0xc($s0)
/* 039884 7F004D54 8FA30074 */  lw    $v1, 0x74($sp)
/* 039888 7F004D58 354B0400 */  ori   $t3, $t2, 0x400
/* 03988C 7F004D5C AE0B000C */  sw    $t3, 0xc($s0)
/* 039890 7F004D60 8C6D000C */  lw    $t5, 0xc($v1)
/* 039894 7F004D64 35AC0400 */  ori   $t4, $t5, 0x400
/* 039898 7F004D68 1000001E */  b     .L7F004DE4
/* 03989C 7F004D6C AC6C000C */   sw    $t4, 0xc($v1)
.L7F004D70:
/* 0398A0 7F004D70 8E420004 */  lw    $v0, 4($s2)
/* 0398A4 7F004D74 8E510008 */  lw    $s1, 8($s2)
/* 0398A8 7F004D78 02A02025 */  move  $a0, $s5
/* 0398AC 7F004D7C 0FC15BA8 */  jal   setupCommandGetObject
/* 0398B0 7F004D80 02622821 */   addu  $a1, $s3, $v0
/* 0398B4 7F004D84 00408025 */  move  $s0, $v0
/* 0398B8 7F004D88 02A02025 */  move  $a0, $s5
/* 0398BC 7F004D8C 0FC15BA8 */  jal   setupCommandGetObject
/* 0398C0 7F004D90 02712821 */   addu  $a1, $s3, $s1
/* 0398C4 7F004D94 12000013 */  beqz  $s0, .L7F004DE4
/* 0398C8 7F004D98 00000000 */   nop   
/* 0398CC 7F004D9C 8E0F0010 */  lw    $t7, 0x10($s0)
/* 0398D0 7F004DA0 11E00010 */  beqz  $t7, .L7F004DE4
/* 0398D4 7F004DA4 00000000 */   nop   
/* 0398D8 7F004DA8 1040000E */  beqz  $v0, .L7F004DE4
/* 0398DC 7F004DAC 00000000 */   nop   
/* 0398E0 7F004DB0 8C4E0010 */  lw    $t6, 0x10($v0)
/* 0398E4 7F004DB4 11C0000B */  beqz  $t6, .L7F004DE4
/* 0398E8 7F004DB8 00000000 */   nop   
/* 0398EC 7F004DBC 92180003 */  lbu   $t8, 3($s0)
/* 0398F0 7F004DC0 02402025 */  move  $a0, $s2
/* 0398F4 7F004DC4 16980007 */  bne   $s4, $t8, .L7F004DE4
/* 0398F8 7F004DC8 00000000 */   nop   
/* 0398FC 7F004DCC AE500004 */  sw    $s0, 4($s2)
/* 039900 7F004DD0 0FC0064A */  jal   initSetLevelLoadPropLockDoor
/* 039904 7F004DD4 AE420008 */   sw    $v0, 8($s2)
/* 039908 7F004DD8 8E080064 */  lw    $t0, 0x64($s0)
/* 03990C 7F004DDC 35092000 */  ori   $t1, $t0, 0x2000
/* 039910 7F004DE0 AE090064 */  sw    $t1, 0x64($s0)
.L7F004DE4:
/* 039914 7F004DE4 0FC15A3D */  jal   sizepropdef
/* 039918 7F004DE8 02402025 */   move  $a0, $s2
/* 03991C 7F004DEC 0002C880 */  sll   $t9, $v0, 2
/* 039920 7F004DF0 03329021 */  addu  $s2, $t9, $s2
/* 039924 7F004DF4 92430003 */  lbu   $v1, 3($s2)
/* 039928 7F004DF8 24010030 */  li    $at, 48
/* 03992C 7F004DFC 26730001 */  addiu $s3, $s3, 1
/* 039930 7F004E00 5461FF52 */  bnel  $v1, $at, .L7F004B4C
/* 039934 7F004E04 2468FFFD */   addiu $t0, $v1, -3
/* 039938 7F004E08 1000001B */  b     .L7F004E78
/* 03993C 7F004E0C 00000000 */   nop   
.L7F004E10:
/* 039940 7F004E10 3C018007 */  lui   $at, %hi(g_CurrentSetup+0)
/* 039944 7F004E14 AC205D00 */  sw    $zero, %lo(g_CurrentSetup+0)($at)
/* 039948 7F004E18 3C018007 */  lui   $at, %hi(g_CurrentSetup+4)
/* 03994C 7F004E1C AC205D04 */  sw    $zero, %lo(g_CurrentSetup+4)($at)
/* 039950 7F004E20 3C018007 */  lui   $at, %hi(g_CurrentSetup+8)
/* 039954 7F004E24 AC205D08 */  sw    $zero, %lo(g_CurrentSetup+8)($at)
/* 039958 7F004E28 3C018007 */  lui   $at, %hi(g_CurrentSetup+0x0c)
/* 03995C 7F004E2C AC205D0C */  sw    $zero, %lo(g_CurrentSetup+0x0c)($at)
/* 039960 7F004E30 3C018007 */  lui   $at, %hi(g_CurrentSetup+0x10)
/* 039964 7F004E34 AC205D10 */  sw    $zero, %lo(g_CurrentSetup+0x10)($at)
/* 039968 7F004E38 3C018007 */  lui   $at, %hi(g_CurrentSetup+0x14)
/* 03996C 7F004E3C AC205D14 */  sw    $zero, %lo(g_CurrentSetup+0x14)($at)
/* 039970 7F004E40 3C018007 */  lui   $at, %hi(g_CurrentSetup+0x18)
/* 039974 7F004E44 AC205D18 */  sw    $zero, %lo(g_CurrentSetup+0x18)($at)
/* 039978 7F004E48 3C018007 */  lui   $at, %hi(g_CurrentSetup+0x1C)
/* 03997C 7F004E4C AC205D1C */  sw    $zero, %lo(g_CurrentSetup+0x1C)($at)
/* 039980 7F004E50 3C018007 */  lui   $at, %hi(g_CurrentSetup+0x20)
/* 039984 7F004E54 AC205D20 */  sw    $zero, %lo(g_CurrentSetup+0x20)($at)
/* 039988 7F004E58 3C018007 */  lui   $at, %hi(g_CurrentSetup+0x24)
/* 03998C 7F004E5C AC205D24 */  sw    $zero, %lo(g_CurrentSetup+0x24)($at)
/* 039990 7F004E60 0FC003AE */  jal   alloc_init_GUARDdata_entries
/* 039994 7F004E64 00002025 */   move  $a0, $zero
/* 039998 7F004E68 0FC01550 */  jal   sub_GAME_7F005540
/* 03999C 7F004E6C 00002025 */   move  $a0, $zero
/* 0399A0 7F004E70 0FC01589 */  jal   sub_GAME_7F005624
/* 0399A4 7F004E74 00002025 */   move  $a0, $zero
.L7F004E78:
/* 0399A8 7F004E78 0FC00417 */  jal   alloc_false_GUARDdata_to_exec_global_action
/* 0399AC 7F004E7C 00000000 */   nop   
/* 0399B0 7F004E80 8FBF0044 */  lw    $ra, 0x44($sp)
/* 0399B4 7F004E84 D7B40018 */  ldc1  $f20, 0x18($sp)
/* 0399B8 7F004E88 8FB00020 */  lw    $s0, 0x20($sp)
/* 0399BC 7F004E8C 8FB10024 */  lw    $s1, 0x24($sp)
/* 0399C0 7F004E90 8FB20028 */  lw    $s2, 0x28($sp)
/* 0399C4 7F004E94 8FB3002C */  lw    $s3, 0x2c($sp)
/* 0399C8 7F004E98 8FB40030 */  lw    $s4, 0x30($sp)
/* 0399CC 7F004E9C 8FB50034 */  lw    $s5, 0x34($sp)
/* 0399D0 7F004EA0 8FB60038 */  lw    $s6, 0x38($sp)
/* 0399D4 7F004EA4 8FB7003C */  lw    $s7, 0x3c($sp)
/* 0399D8 7F004EA8 8FBE0040 */  lw    $fp, 0x40($sp)
/* 0399DC 7F004EAC 03E00008 */  jr    $ra
/* 0399E0 7F004EB0 27BD0280 */   addiu $sp, $sp, 0x280
)
#endif  

#ifdef VERSION_JP
 GLOBAL_ASM(
.late_rodata
glabel jpt_object_type_expansion
.word door_expand
.word door_scale_expand
.word obj_03_expand
.word key_expand
.word obj_03_expand
.word surv_camera_expand
.word obj_03_expand
.word item_expand
.word actor_expand
.word single_screen_display_expand
.word multi_screen_display_expand
.word rack_expand
.word autogun_expand
.word other_obj_expand
.word other_obj_expand
.word other_obj_expand
.word hat_expand
.word actor_attr_expand
.word other_obj_expand
.word ammo_box_expand
.word body_armor_expand
.word tag_expand
.word type17_objective_expand
.word other_obj_expand
.word other_obj_expand
.word other_obj_expand
.word other_obj_expand
.word other_obj_expand
.word other_obj_expand
.word type1E_subobjective_expand
.word other_obj_expand
.word type20_subobjective_expand
.word type21_subobjective_expand
.word other_obj_expand
.word type23_solo_brief_text
.word obj_03_expand
.word type25_rename
.word other_obj_expand
.word type27_wheeled_vehicle
.word type28_aircraft
.word obj_03_expand
.word obj_03_expand
.word obj_03_expand
.word other_obj_expand
.word type2D_tank
.word type2E_viewport_pos
.word type2F_tinted_glass

glabel D_8004F024
.word 0x40c90fdb
glabel D_8004F028
.word 0x3e2e147c

glabel jpt_8004F02C
.word .L7F004B7C
.word .L7F004B7C
.word .L7F004DF4
.word .L7F004DF4
.word .L7F004B7C
.word .L7F004B7C
.word .L7F004DF4
.word .L7F004B7C
.word .L7F004DF4
.word .L7F004DF4
.word .L7F004DF4
.word .L7F004BE8
.word .L7F004DF4
.word .L7F004DF4
.word .L7F004DF4
.word .L7F004DF4
.word .L7F004C3C
.word .L7F004B7C
.word .L7F004B7C
.word .L7F004DF4
.word .L7F004DF4
.word .L7F004DF4
.word .L7F004DF4
.word .L7F004DF4
.word .L7F004DF4
.word .L7F004DF4
.word .L7F004DF4
.word .L7F004DF4
.word .L7F004DF4
.word .L7F004DF4
.word .L7F004DF4
.word .L7F004DF4
.word .L7F004DF4
.word .L7F004B7C
.word .L7F004DF4
.word .L7F004D80
.word .L7F004DF4
.word .L7F004DF4
.word .L7F004B7C
.word .L7F004B7C
.word .L7F004B7C
.word .L7F004CB4
.word .L7F004DF4
.word .L7F004DF4
.word .L7F004B7C


  .text
  glabel proplvreset2
/* 038760 7F003BF0 27BDFD80 */  addiu $sp, $sp, -0x280
/* 038764 7F003BF4 AFB50034 */  sw    $s5, 0x34($sp)
/* 038768 7F003BF8 0080A825 */  move  $s5, $a0
/* 03876C 7F003BFC AFBF0044 */  sw    $ra, 0x44($sp)
/* 038770 7F003C00 3C058005 */  lui   $a1, %hi(aNochr) # $a1, 0x8005
/* 038774 7F003C04 AFBE0040 */  sw    $fp, 0x40($sp)
/* 038778 7F003C08 AFB7003C */  sw    $s7, 0x3c($sp)
/* 03877C 7F003C0C AFB60038 */  sw    $s6, 0x38($sp)
/* 038780 7F003C10 AFB40030 */  sw    $s4, 0x30($sp)
/* 038784 7F003C14 AFB3002C */  sw    $s3, 0x2c($sp)
/* 038788 7F003C18 AFB20028 */  sw    $s2, 0x28($sp)
/* 03878C 7F003C1C AFB10024 */  sw    $s1, 0x24($sp)
/* 038790 7F003C20 AFB00020 */  sw    $s0, 0x20($sp)
/* 038794 7F003C24 F7B40018 */  sdc1  $f20, 0x18($sp)
/* 038798 7F003C28 24A5EDC0 */  addiu $a1, %lo(aNochr) # addiu $a1, $a1, -0x1240
/* 03879C 7F003C2C 0C0029AC */  jal   tokenFind
/* 0387A0 7F003C30 24040001 */   li    $a0, 1
/* 0387A4 7F003C34 2C460001 */  sltiu $a2, $v0, 1
/* 0387A8 7F003C38 10C00005 */  beqz  $a2, .L7F003C50
/* 0387AC 7F003C3C 24040001 */   li    $a0, 1
/* 0387B0 7F003C40 3C058005 */  lui   $a1, %hi(aNoprop) # $a1, 0x8005
/* 0387B4 7F003C44 0C0029AC */  jal   tokenFind
/* 0387B8 7F003C48 24A5EDC8 */   addiu $a1, %lo(aNoprop) # addiu $a1, $a1, -0x1238
/* 0387BC 7F003C4C 2C460001 */  sltiu $a2, $v0, 1
.L7F003C50:
/* 0387C0 7F003C50 3C058005 */  lui   $a1, %hi(aNoobj) # $a1, 0x8005
/* 0387C4 7F003C54 AFA60278 */  sw    $a2, 0x278($sp)
/* 0387C8 7F003C58 24A5EDD0 */  addiu $a1, %lo(aNoobj) # addiu $a1, $a1, -0x1230
/* 0387CC 7F003C5C 0C0029AC */  jal   tokenFind
/* 0387D0 7F003C60 24040001 */   li    $a0, 1
/* 0387D4 7F003C64 2C430001 */  sltiu $v1, $v0, 1
/* 0387D8 7F003C68 10600005 */  beqz  $v1, .L7F003C80
/* 0387DC 7F003C6C 24040001 */   li    $a0, 1
/* 0387E0 7F003C70 3C058005 */  lui   $a1, %hi(aNoprop_0) # $a1, 0x8005
/* 0387E4 7F003C74 0C0029AC */  jal   tokenFind
/* 0387E8 7F003C78 24A5EDD8 */   addiu $a1, %lo(aNoprop_0) # addiu $a1, $a1, -0x1228
/* 0387EC 7F003C7C 2C430001 */  sltiu $v1, $v0, 1
.L7F003C80:
/* 0387F0 7F003C80 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0387F4 7F003C84 44812000 */  mtc1  $at, $f4
/* 0387F8 7F003C88 0060F025 */  move  $fp, $v1
/* 0387FC 7F003C8C 3C018003 */  lui   $at, %hi(g_DoorScale) # $at, 0x8003
/* 038800 7F003C90 3C038004 */  lui   $v1, %hi(PitemZ_entries+0xFF0) # $v1, 0x8004
/* 038804 7F003C94 3C028004 */  lui   $v0, %hi(PitemZ_entries) # $v0, 0x8004
/* 038808 7F003C98 2442A258 */  addiu $v0, %lo(PitemZ_entries) # addiu $v0, $v0, -0x5da8
/* 03880C 7F003C9C 2463B248 */  addiu $v1, %lo(PitemZ_entries+0xFF0) # addiu $v1, $v1, -0x4db8
/* 038810 7F003CA0 E424A400 */  swc1  $f4, %lo(g_DoorScale)($at)
.L7F003CA4:
/* 038814 7F003CA4 8C4E0000 */  lw    $t6, ($v0)
/* 038818 7F003CA8 2442000C */  addiu $v0, $v0, 0xc
/* 03881C 7F003CAC 0043082B */  sltu  $at, $v0, $v1
/* 038820 7F003CB0 1420FFFC */  bnez  $at, .L7F003CA4
/* 038824 7F003CB4 ADC00000 */   sw    $zero, ($t6)
/* 038828 7F003CB8 2AA1003B */  slti  $at, $s5, 0x3b
/* 03882C 7F003CBC 10200458 */  beqz  $at, .L7F004E20
/* 038830 7F003CC0 00157880 */   sll   $t7, $s5, 2
/* 038834 7F003CC4 3C188003 */  lui   $t8, %hi(setup_text_pointers) # $t8, 0x8003
/* 038838 7F003CC8 27187514 */  addiu $t8, %lo(setup_text_pointers) # addiu $t8, $t8, 0x7514
/* 03883C 7F003CCC 01F88021 */  addu  $s0, $t7, $t8
/* 038840 7F003CD0 8E020000 */  lw    $v0, ($s0)
/* 038844 7F003CD4 3C198005 */  lui   $t9, %hi(only_read_by_stageload) # $t9, 0x8005
/* 038848 7F003CD8 27B10174 */  addiu $s1, $sp, 0x174
/* 03884C 7F003CDC 10400450 */  beqz  $v0, .L7F004E20
/* 038850 7F003CE0 2739EDE0 */   addiu $t9, %lo(only_read_by_stageload) # addiu $t9, $t9, -0x1220
/* 038854 7F003CE4 02205025 */  move  $t2, $s1
/* 038858 7F003CE8 272900FC */  addiu $t1, $t9, 0xfc
.L7F003CEC:
/* 03885C 7F003CEC 8F210000 */  lw    $at, ($t9)
/* 038860 7F003CF0 2739000C */  addiu $t9, $t9, 0xc
/* 038864 7F003CF4 254A000C */  addiu $t2, $t2, 0xc
/* 038868 7F003CF8 AD41FFF4 */  sw    $at, -0xc($t2)
/* 03886C 7F003CFC 8F21FFF8 */  lw    $at, -8($t9)
/* 038870 7F003D00 AD41FFF8 */  sw    $at, -8($t2)
/* 038874 7F003D04 8F21FFFC */  lw    $at, -4($t9)
/* 038878 7F003D08 1729FFF8 */  bne   $t9, $t1, .L7F003CEC
/* 03887C 7F003D0C AD41FFFC */   sw    $at, -4($t2)
/* 038880 7F003D10 8F210000 */  lw    $at, ($t9)
/* 038884 7F003D14 0000A025 */  move  $s4, $zero
/* 038888 7F003D18 00009825 */  move  $s3, $zero
/* 03888C 7F003D1C AD410000 */  sw    $at, ($t2)
/* 038890 7F003D20 904B0000 */  lbu   $t3, ($v0)
/* 038894 7F003D24 A3A00175 */  sb    $zero, 0x175($sp)
/* 038898 7F003D28 0FC26C01 */  jal   getPlayerCount
/* 03889C 7F003D2C A3AB0174 */   sb    $t3, 0x174($sp)
/* 0388A0 7F003D30 28410002 */  slti  $at, $v0, 2
/* 0388A4 7F003D34 14200004 */  bnez  $at, .L7F003D48
/* 0388A8 7F003D38 3C058005 */   lui   $a1, %hi(aMp_) # $a1, 0x8005
/* 0388AC 7F003D3C 24A5EEE0 */  addiu $a1, %lo(aMp_) # addiu $a1, $a1, -0x1120
/* 0388B0 7F003D40 0C002A03 */  jal   strcat
/* 0388B4 7F003D44 02202025 */   move  $a0, $s1
.L7F003D48:
/* 0388B8 7F003D48 8E050000 */  lw    $a1, ($s0)
/* 0388BC 7F003D4C 02202025 */  move  $a0, $s1
/* 0388C0 7F003D50 0C002A03 */  jal   strcat
/* 0388C4 7F003D54 24A50001 */   addiu $a1, $a1, 1
/* 0388C8 7F003D58 02202025 */  move  $a0, $s1
/* 0388CC 7F003D5C 24050001 */  li    $a1, 1
/* 0388D0 7F003D60 24060100 */  li    $a2, 256
/* 0388D4 7F003D64 0FC2F62D */  jal   _fileNameLoadToBank
/* 0388D8 7F003D68 24070004 */   li    $a3, 4
/* 0388DC 7F003D6C 3C038007 */  lui   $v1, %hi(g_ptrStageSetupFile) # $v1, 0x8007
/* 0388E0 7F003D70 24635D68 */  addiu $v1, %lo(g_ptrStageSetupFile) # addiu $v1, $v1, 0x5d68
/* 0388E4 7F003D74 AC620000 */  sw    $v0, ($v1)
/* 0388E8 7F003D78 00408825 */  move  $s1, $v0
/* 0388EC 7F003D7C 0FC308A4 */  jal   langGetLangBankIndexFromStagenum
/* 0388F0 7F003D80 02A02025 */   move  $a0, $s5
/* 0388F4 7F003D84 0FC30A6E */  jal   langLoadToAddr
/* 0388F8 7F003D88 00402025 */   move  $a0, $v0
/* 0388FC 7F003D8C 8E2C0000 */  lw    $t4, ($s1)
/* 038900 7F003D90 3C078007 */  lui   $a3, %hi(g_CurrentSetup+0) # $a3, 0x8007
/* 038904 7F003D94 24E75D40 */  addiu $a3, %lo(g_CurrentSetup+0) # addiu $a3, $a3, 0x5d40
/* 038908 7F003D98 022C6821 */  addu  $t5, $s1, $t4
/* 03890C 7F003D9C ACED0000 */  sw    $t5, ($a3)
/* 038910 7F003DA0 8E2E0004 */  lw    $t6, 4($s1)
/* 038914 7F003DA4 022E7821 */  addu  $t7, $s1, $t6
/* 038918 7F003DA8 ACEF0004 */  sw    $t7, 4($a3)
/* 03891C 7F003DAC 8E380008 */  lw    $t8, 8($s1)
/* 038920 7F003DB0 02384021 */  addu  $t0, $s1, $t8
/* 038924 7F003DB4 ACE80008 */  sw    $t0, 8($a3)
/* 038928 7F003DB8 8E29000C */  lw    $t1, 0xc($s1)
/* 03892C 7F003DBC 0229C821 */  addu  $t9, $s1, $t1
/* 038930 7F003DC0 ACF9000C */  sw    $t9, 0xc($a3)
/* 038934 7F003DC4 8E2A0010 */  lw    $t2, 0x10($s1)
/* 038938 7F003DC8 022A5821 */  addu  $t3, $s1, $t2
/* 03893C 7F003DCC ACEB0010 */  sw    $t3, 0x10($a3)
/* 038940 7F003DD0 8E2C0014 */  lw    $t4, 0x14($s1)
/* 038944 7F003DD4 022C6821 */  addu  $t5, $s1, $t4
/* 038948 7F003DD8 ACED0014 */  sw    $t5, 0x14($a3)
/* 03894C 7F003DDC 8E2E0018 */  lw    $t6, 0x18($s1)
/* 038950 7F003DE0 022E7821 */  addu  $t7, $s1, $t6
/* 038954 7F003DE4 ACEF0018 */  sw    $t7, 0x18($a3)
/* 038958 7F003DE8 8E38001C */  lw    $t8, 0x1c($s1)
/* 03895C 7F003DEC 02384021 */  addu  $t0, $s1, $t8
/* 038960 7F003DF0 ACE8001C */  sw    $t0, 0x1c($a3)
/* 038964 7F003DF4 8E220020 */  lw    $v0, 0x20($s1)
/* 038968 7F003DF8 10400003 */  beqz  $v0, .L7F003E08
/* 03896C 7F003DFC 02224821 */   addu  $t1, $s1, $v0
/* 038970 7F003E00 10000002 */  b     .L7F003E0C
/* 038974 7F003E04 ACE90020 */   sw    $t1, 0x20($a3)
.L7F003E08:
/* 038978 7F003E08 ACE00020 */  sw    $zero, 0x20($a3)
.L7F003E0C:
/* 03897C 7F003E0C 8E220024 */  lw    $v0, 0x24($s1)
/* 038980 7F003E10 10400003 */  beqz  $v0, .L7F003E20
/* 038984 7F003E14 0222C821 */   addu  $t9, $s1, $v0
/* 038988 7F003E18 10000002 */  b     .L7F003E24
/* 03898C 7F003E1C ACF90024 */   sw    $t9, 0x24($a3)
.L7F003E20:
/* 038990 7F003E20 ACE00024 */  sw    $zero, 0x24($a3)
.L7F003E24:
/* 038994 7F003E24 8CE50000 */  lw    $a1, ($a3)
/* 038998 7F003E28 50A00010 */  beql  $a1, $zero, .L7F003E6C
/* 03899C 7F003E2C 8CE50004 */   lw    $a1, 4($a3)
/* 0389A0 7F003E30 8CAA0000 */  lw    $t2, ($a1)
/* 0389A4 7F003E34 00001825 */  move  $v1, $zero
/* 0389A8 7F003E38 00A01025 */  move  $v0, $a1
/* 0389AC 7F003E3C 0542000B */  bltzl $t2, .L7F003E6C
/* 0389B0 7F003E40 8CE50004 */   lw    $a1, 4($a3)
/* 0389B4 7F003E44 8C4B0004 */  lw    $t3, 4($v0)
.L7F003E48:
/* 0389B8 7F003E48 24630010 */  addiu $v1, $v1, 0x10
/* 0389BC 7F003E4C 01716021 */  addu  $t4, $t3, $s1
/* 0389C0 7F003E50 AC4C0004 */  sw    $t4, 4($v0)
/* 0389C4 7F003E54 8CED0000 */  lw    $t5, ($a3)
/* 0389C8 7F003E58 01A31021 */  addu  $v0, $t5, $v1
/* 0389CC 7F003E5C 8C4E0000 */  lw    $t6, ($v0)
/* 0389D0 7F003E60 05C3FFF9 */  bgezl $t6, .L7F003E48
/* 0389D4 7F003E64 8C4B0004 */   lw    $t3, 4($v0)
/* 0389D8 7F003E68 8CE50004 */  lw    $a1, 4($a3)
.L7F003E6C:
/* 0389DC 7F003E6C 50A00015 */  beql  $a1, $zero, .L7F003EC4
/* 0389E0 7F003E70 8CE60014 */   lw    $a2, 0x14($a3)
/* 0389E4 7F003E74 8CAF0000 */  lw    $t7, ($a1)
/* 0389E8 7F003E78 00001825 */  move  $v1, $zero
/* 0389EC 7F003E7C 00A01025 */  move  $v0, $a1
/* 0389F0 7F003E80 51E00010 */  beql  $t7, $zero, .L7F003EC4
/* 0389F4 7F003E84 8CE60014 */   lw    $a2, 0x14($a3)
/* 0389F8 7F003E88 8CA40000 */  lw    $a0, ($a1)
/* 0389FC 7F003E8C 0091C021 */  addu  $t8, $a0, $s1
.L7F003E90:
/* 038A00 7F003E90 AC580000 */  sw    $t8, ($v0)
/* 038A04 7F003E94 8CE80004 */  lw    $t0, 4($a3)
/* 038A08 7F003E98 01031021 */  addu  $v0, $t0, $v1
/* 038A0C 7F003E9C 8C490004 */  lw    $t1, 4($v0)
/* 038A10 7F003EA0 2463000C */  addiu $v1, $v1, 0xc
/* 038A14 7F003EA4 0131C821 */  addu  $t9, $t1, $s1
/* 038A18 7F003EA8 AC590004 */  sw    $t9, 4($v0)
/* 038A1C 7F003EAC 8CEA0004 */  lw    $t2, 4($a3)
/* 038A20 7F003EB0 01431021 */  addu  $v0, $t2, $v1
/* 038A24 7F003EB4 8C440000 */  lw    $a0, ($v0)
/* 038A28 7F003EB8 5480FFF5 */  bnezl $a0, .L7F003E90
/* 038A2C 7F003EBC 0091C021 */   addu  $t8, $a0, $s1
/* 038A30 7F003EC0 8CE60014 */  lw    $a2, 0x14($a3)
.L7F003EC4:
/* 038A34 7F003EC4 50C00010 */  beql  $a2, $zero, .L7F003F08
/* 038A38 7F003EC8 8CE20010 */   lw    $v0, 0x10($a3)
/* 038A3C 7F003ECC 8CCB0000 */  lw    $t3, ($a2)
/* 038A40 7F003ED0 00002825 */  move  $a1, $zero
/* 038A44 7F003ED4 00C01025 */  move  $v0, $a2
/* 038A48 7F003ED8 5160000B */  beql  $t3, $zero, .L7F003F08
/* 038A4C 7F003EDC 8CE20010 */   lw    $v0, 0x10($a3)
/* 038A50 7F003EE0 8CC30000 */  lw    $v1, ($a2)
/* 038A54 7F003EE4 00716021 */  addu  $t4, $v1, $s1
.L7F003EE8:
/* 038A58 7F003EE8 AC4C0000 */  sw    $t4, ($v0)
/* 038A5C 7F003EEC 8CED0014 */  lw    $t5, 0x14($a3)
/* 038A60 7F003EF0 24A50008 */  addiu $a1, $a1, 8
/* 038A64 7F003EF4 01A51021 */  addu  $v0, $t5, $a1
/* 038A68 7F003EF8 8C430000 */  lw    $v1, ($v0)
/* 038A6C 7F003EFC 5460FFFA */  bnezl $v1, .L7F003EE8
/* 038A70 7F003F00 00716021 */   addu  $t4, $v1, $s1
/* 038A74 7F003F04 8CE20010 */  lw    $v0, 0x10($a3)
.L7F003F08:
/* 038A78 7F003F08 50400020 */  beql  $v0, $zero, .L7F003F8C
/* 038A7C 7F003F0C 8CEA0018 */   lw    $t2, 0x18($a3)
/* 038A80 7F003F10 8C4E0000 */  lw    $t6, ($v0)
/* 038A84 7F003F14 00002825 */  move  $a1, $zero
/* 038A88 7F003F18 00403025 */  move  $a2, $v0
/* 038A8C 7F003F1C 51C0001B */  beql  $t6, $zero, .L7F003F8C
/* 038A90 7F003F20 8CEA0018 */   lw    $t2, 0x18($a3)
/* 038A94 7F003F24 8C440000 */  lw    $a0, ($v0)
/* 038A98 7F003F28 00917821 */  addu  $t7, $a0, $s1
.L7F003F2C:
/* 038A9C 7F003F2C ACCF0000 */  sw    $t7, ($a2)
/* 038AA0 7F003F30 8CF80010 */  lw    $t8, 0x10($a3)
/* 038AA4 7F003F34 00001825 */  move  $v1, $zero
/* 038AA8 7F003F38 03053021 */  addu  $a2, $t8, $a1
/* 038AAC 7F003F3C 8CC40000 */  lw    $a0, ($a2)
/* 038AB0 7F003F40 8C880000 */  lw    $t0, ($a0)
/* 038AB4 7F003F44 00801025 */  move  $v0, $a0
/* 038AB8 7F003F48 05020009 */  bltzl $t0, .L7F003F70
/* 038ABC 7F003F4C A4C30006 */   sh    $v1, 6($a2)
/* 038AC0 7F003F50 8C490004 */  lw    $t1, 4($v0)
.L7F003F54:
/* 038AC4 7F003F54 24630001 */  addiu $v1, $v1, 1
/* 038AC8 7F003F58 24420004 */  addiu $v0, $v0, 4
/* 038ACC 7F003F5C 0523FFFD */  bgezl $t1, .L7F003F54
/* 038AD0 7F003F60 8C490004 */   lw    $t1, 4($v0)
/* 038AD4 7F003F64 3C078007 */  lui   $a3, %hi(g_CurrentSetup+0) # $a3, 0x8007
/* 038AD8 7F003F68 24E75D40 */  addiu $a3, %lo(g_CurrentSetup+0) # addiu $a3, $a3, 0x5d40
/* 038ADC 7F003F6C A4C30006 */  sh    $v1, 6($a2)
.L7F003F70:
/* 038AE0 7F003F70 8CF90010 */  lw    $t9, 0x10($a3)
/* 038AE4 7F003F74 24A50008 */  addiu $a1, $a1, 8
/* 038AE8 7F003F78 03253021 */  addu  $a2, $t9, $a1
/* 038AEC 7F003F7C 8CC40000 */  lw    $a0, ($a2)
/* 038AF0 7F003F80 5480FFEA */  bnezl $a0, .L7F003F2C
/* 038AF4 7F003F84 00917821 */   addu  $t7, $a0, $s1
/* 038AF8 7F003F88 8CEA0018 */  lw    $t2, 0x18($a3)
.L7F003F8C:
/* 038AFC 7F003F8C 1140001D */  beqz  $t2, .L7F004004
/* 038B00 7F003F90 00000000 */   nop   
/* 038B04 7F003F94 0FC2D4F8 */  jal   get_room_data_float2
/* 038B08 7F003F98 00000000 */   nop   
/* 038B0C 7F003F9C 3C108007 */  lui   $s0, %hi(g_CurrentSetup+0x18) # $s0, 0x8007
/* 038B10 7F003FA0 8E105D58 */  lw    $s0, %lo(g_CurrentSetup+0x18)($s0)
/* 038B14 7F003FA4 46000086 */  mov.s $f2, $f0
/* 038B18 7F003FA8 8E020024 */  lw    $v0, 0x24($s0)
/* 038B1C 7F003FAC 10400015 */  beqz  $v0, .L7F004004
/* 038B20 7F003FB0 00000000 */   nop   
/* 038B24 7F003FB4 C6060000 */  lwc1  $f6, ($s0)
.L7F003FB8:
/* 038B28 7F003FB8 C60A0004 */  lwc1  $f10, 4($s0)
/* 038B2C 7F003FBC C6120008 */  lwc1  $f18, 8($s0)
/* 038B30 7F003FC0 46023202 */  mul.s $f8, $f6, $f2
/* 038B34 7F003FC4 02222821 */  addu  $a1, $s1, $v0
/* 038B38 7F003FC8 AE050024 */  sw    $a1, 0x24($s0)
/* 038B3C 7F003FCC 46025402 */  mul.s $f16, $f10, $f2
/* 038B40 7F003FD0 02002025 */  move  $a0, $s0
/* 038B44 7F003FD4 26060028 */  addiu $a2, $s0, 0x28
/* 038B48 7F003FD8 46029102 */  mul.s $f4, $f18, $f2
/* 038B4C 7F003FDC E6080000 */  swc1  $f8, ($s0)
/* 038B50 7F003FE0 E6100004 */  swc1  $f16, 4($s0)
/* 038B54 7F003FE4 E6040008 */  swc1  $f4, 8($s0)
/* 038B58 7F003FE8 0FC019F8 */  jal   init_pathtable_something
/* 038B5C 7F003FEC E7A2015C */   swc1  $f2, 0x15c($sp)
/* 038B60 7F003FF0 8E020050 */  lw    $v0, 0x50($s0)
/* 038B64 7F003FF4 2610002C */  addiu $s0, $s0, 0x2c
/* 038B68 7F003FF8 C7A2015C */  lwc1  $f2, 0x15c($sp)
/* 038B6C 7F003FFC 5440FFEE */  bnezl $v0, .L7F003FB8
/* 038B70 7F004000 C6060000 */   lwc1  $f6, ($s0)
.L7F004004:
/* 038B74 7F004004 3C078007 */  lui   $a3, %hi(g_CurrentSetup+0) # $a3, 0x8007
/* 038B78 7F004008 24E75D40 */  addiu $a3, %lo(g_CurrentSetup+0) # addiu $a3, $a3, 0x5d40
/* 038B7C 7F00400C 8CEC001C */  lw    $t4, 0x1c($a3)
/* 038B80 7F004010 51800033 */  beql  $t4, $zero, .L7F0040E0
/* 038B84 7F004014 8CE50020 */   lw    $a1, 0x20($a3)
/* 038B88 7F004018 0FC2D4F8 */  jal   get_room_data_float2
/* 038B8C 7F00401C 00000000 */   nop   
/* 038B90 7F004020 3C078007 */  lui   $a3, %hi(g_CurrentSetup+0) # $a3, 0x8007
/* 038B94 7F004024 24E75D40 */  addiu $a3, %lo(g_CurrentSetup+0) # addiu $a3, $a3, 0x5d40
/* 038B98 7F004028 8CF0001C */  lw    $s0, 0x1c($a3)
/* 038B9C 7F00402C 46000086 */  mov.s $f2, $f0
/* 038BA0 7F004030 8E020024 */  lw    $v0, 0x24($s0)
/* 038BA4 7F004034 5040002A */  beql  $v0, $zero, .L7F0040E0
/* 038BA8 7F004038 8CE50020 */   lw    $a1, 0x20($a3)
/* 038BAC 7F00403C C6060000 */  lwc1  $f6, ($s0)
.L7F004040:
/* 038BB0 7F004040 C60A0004 */  lwc1  $f10, 4($s0)
/* 038BB4 7F004044 C6120008 */  lwc1  $f18, 8($s0)
/* 038BB8 7F004048 46023202 */  mul.s $f8, $f6, $f2
/* 038BBC 7F00404C C606002C */  lwc1  $f6, 0x2c($s0)
/* 038BC0 7F004050 02222821 */  addu  $a1, $s1, $v0
/* 038BC4 7F004054 46025402 */  mul.s $f16, $f10, $f2
/* 038BC8 7F004058 C60A0030 */  lwc1  $f10, 0x30($s0)
/* 038BCC 7F00405C AE050024 */  sw    $a1, 0x24($s0)
/* 038BD0 7F004060 46029102 */  mul.s $f4, $f18, $f2
/* 038BD4 7F004064 E6080000 */  swc1  $f8, ($s0)
/* 038BD8 7F004068 C6120034 */  lwc1  $f18, 0x34($s0)
/* 038BDC 7F00406C 46023202 */  mul.s $f8, $f6, $f2
/* 038BE0 7F004070 E6100004 */  swc1  $f16, 4($s0)
/* 038BE4 7F004074 C6060038 */  lwc1  $f6, 0x38($s0)
/* 038BE8 7F004078 46025402 */  mul.s $f16, $f10, $f2
/* 038BEC 7F00407C E6040008 */  swc1  $f4, 8($s0)
/* 038BF0 7F004080 C60A003C */  lwc1  $f10, 0x3c($s0)
/* 038BF4 7F004084 46029102 */  mul.s $f4, $f18, $f2
/* 038BF8 7F004088 E608002C */  swc1  $f8, 0x2c($s0)
/* 038BFC 7F00408C C6120040 */  lwc1  $f18, 0x40($s0)
/* 038C00 7F004090 46023202 */  mul.s $f8, $f6, $f2
/* 038C04 7F004094 E6100030 */  swc1  $f16, 0x30($s0)
/* 038C08 7F004098 02002025 */  move  $a0, $s0
/* 038C0C 7F00409C 46025402 */  mul.s $f16, $f10, $f2
/* 038C10 7F0040A0 E6040034 */  swc1  $f4, 0x34($s0)
/* 038C14 7F0040A4 26060028 */  addiu $a2, $s0, 0x28
/* 038C18 7F0040A8 46029102 */  mul.s $f4, $f18, $f2
/* 038C1C 7F0040AC E6080038 */  swc1  $f8, 0x38($s0)
/* 038C20 7F0040B0 E610003C */  swc1  $f16, 0x3c($s0)
/* 038C24 7F0040B4 E6040040 */  swc1  $f4, 0x40($s0)
/* 038C28 7F0040B8 0FC019F8 */  jal   init_pathtable_something
/* 038C2C 7F0040BC E7A20150 */   swc1  $f2, 0x150($sp)
/* 038C30 7F0040C0 8E020068 */  lw    $v0, 0x68($s0)
/* 038C34 7F0040C4 26100044 */  addiu $s0, $s0, 0x44
/* 038C38 7F0040C8 C7A20150 */  lwc1  $f2, 0x150($sp)
/* 038C3C 7F0040CC 5440FFDC */  bnezl $v0, .L7F004040
/* 038C40 7F0040D0 C6060000 */   lwc1  $f6, ($s0)
/* 038C44 7F0040D4 3C078007 */  lui   $a3, %hi(g_CurrentSetup+0) # $a3, 0x8007
/* 038C48 7F0040D8 24E75D40 */  addiu $a3, %lo(g_CurrentSetup+0) # addiu $a3, $a3, 0x5d40
/* 038C4C 7F0040DC 8CE50020 */  lw    $a1, 0x20($a3)
.L7F0040E0:
/* 038C50 7F0040E0 50A00010 */  beql  $a1, $zero, .L7F004124
/* 038C54 7F0040E4 8CE50024 */   lw    $a1, 0x24($a3)
/* 038C58 7F0040E8 8CAE0000 */  lw    $t6, ($a1)
/* 038C5C 7F0040EC 00001025 */  move  $v0, $zero
/* 038C60 7F0040F0 00A01825 */  move  $v1, $a1
/* 038C64 7F0040F4 51C0000B */  beql  $t6, $zero, .L7F004124
/* 038C68 7F0040F8 8CE50024 */   lw    $a1, 0x24($a3)
/* 038C6C 7F0040FC 8CA40000 */  lw    $a0, ($a1)
/* 038C70 7F004100 00917821 */  addu  $t7, $a0, $s1
.L7F004104:
/* 038C74 7F004104 AC6F0000 */  sw    $t7, ($v1)
/* 038C78 7F004108 8CF80020 */  lw    $t8, 0x20($a3)
/* 038C7C 7F00410C 24420004 */  addiu $v0, $v0, 4
/* 038C80 7F004110 03021821 */  addu  $v1, $t8, $v0
/* 038C84 7F004114 8C640000 */  lw    $a0, ($v1)
/* 038C88 7F004118 5480FFFA */  bnezl $a0, .L7F004104
/* 038C8C 7F00411C 00917821 */   addu  $t7, $a0, $s1
/* 038C90 7F004120 8CE50024 */  lw    $a1, 0x24($a3)
.L7F004124:
/* 038C94 7F004124 50A0000F */  beql  $a1, $zero, .L7F004164
/* 038C98 7F004128 8FAA0278 */   lw    $t2, 0x278($sp)
/* 038C9C 7F00412C 8CA80000 */  lw    $t0, ($a1)
/* 038CA0 7F004130 00001025 */  move  $v0, $zero
/* 038CA4 7F004134 00A01825 */  move  $v1, $a1
/* 038CA8 7F004138 11000009 */  beqz  $t0, .L7F004160
/* 038CAC 7F00413C 01002025 */   move  $a0, $t0
/* 038CB0 7F004140 00914821 */  addu  $t1, $a0, $s1
.L7F004144:
/* 038CB4 7F004144 AC690000 */  sw    $t1, ($v1)
/* 038CB8 7F004148 8CF90024 */  lw    $t9, 0x24($a3)
/* 038CBC 7F00414C 24420004 */  addiu $v0, $v0, 4
/* 038CC0 7F004150 03221821 */  addu  $v1, $t9, $v0
/* 038CC4 7F004154 8C640000 */  lw    $a0, ($v1)
/* 038CC8 7F004158 5480FFFA */  bnezl $a0, .L7F004144
/* 038CCC 7F00415C 00914821 */   addu  $t1, $a0, $s1
.L7F004160:
/* 038CD0 7F004160 8FAA0278 */  lw    $t2, 0x278($sp)
.L7F004164:
/* 038CD4 7F004164 11400012 */  beqz  $t2, .L7F0041B0
/* 038CD8 7F004168 00000000 */   nop   
/* 038CDC 7F00416C 0FC006D4 */  jal   load_proptype
/* 038CE0 7F004170 24040009 */   li    $a0, 9
/* 038CE4 7F004174 0FC003AE */  jal   alloc_init_GUARDdata_entries
/* 038CE8 7F004178 00402025 */   move  $a0, $v0
/* 038CEC 7F00417C 0FC006D4 */  jal   load_proptype
/* 038CF0 7F004180 24040009 */   li    $a0, 9
/* 038CF4 7F004184 0040A025 */  move  $s4, $v0
/* 038CF8 7F004188 0FC006D4 */  jal   load_proptype
/* 038CFC 7F00418C 24040008 */   li    $a0, 8
/* 038D00 7F004190 00409825 */  move  $s3, $v0
/* 038D04 7F004194 0FC006D4 */  jal   load_proptype
/* 038D08 7F004198 24040004 */   li    $a0, 4
/* 038D0C 7F00419C 02629821 */  addu  $s3, $s3, $v0
/* 038D10 7F0041A0 0FC006D4 */  jal   load_proptype
/* 038D14 7F0041A4 24040011 */   li    $a0, 17
/* 038D18 7F0041A8 10000003 */  b     .L7F0041B8
/* 038D1C 7F0041AC 02629821 */   addu  $s3, $s3, $v0
.L7F0041B0:
/* 038D20 7F0041B0 0FC003AE */  jal   alloc_init_GUARDdata_entries
/* 038D24 7F0041B4 00002025 */   move  $a0, $zero
.L7F0041B8:
/* 038D28 7F0041B8 13C0003A */  beqz  $fp, .L7F0042A4
/* 038D2C 7F0041BC 00000000 */   nop   
/* 038D30 7F0041C0 0FC006D4 */  jal   load_proptype
/* 038D34 7F0041C4 24040001 */   li    $a0, 1
/* 038D38 7F0041C8 02629821 */  addu  $s3, $s3, $v0
/* 038D3C 7F0041CC 0FC006D4 */  jal   load_proptype
/* 038D40 7F0041D0 24040006 */   li    $a0, 6
/* 038D44 7F0041D4 02629821 */  addu  $s3, $s3, $v0
/* 038D48 7F0041D8 0FC006D4 */  jal   load_proptype
/* 038D4C 7F0041DC 2404000D */   li    $a0, 13
/* 038D50 7F0041E0 02629821 */  addu  $s3, $s3, $v0
/* 038D54 7F0041E4 0FC006D4 */  jal   load_proptype
/* 038D58 7F0041E8 2404000C */   li    $a0, 12
/* 038D5C 7F0041EC 02629821 */  addu  $s3, $s3, $v0
/* 038D60 7F0041F0 0FC006D4 */  jal   load_proptype
/* 038D64 7F0041F4 2404000A */   li    $a0, 10
/* 038D68 7F0041F8 02629821 */  addu  $s3, $s3, $v0
/* 038D6C 7F0041FC 0FC006D4 */  jal   load_proptype
/* 038D70 7F004200 2404000B */   li    $a0, 11
/* 038D74 7F004204 02629821 */  addu  $s3, $s3, $v0
/* 038D78 7F004208 0FC006D4 */  jal   load_proptype
/* 038D7C 7F00420C 24040015 */   li    $a0, 21
/* 038D80 7F004210 02629821 */  addu  $s3, $s3, $v0
/* 038D84 7F004214 0FC006D4 */  jal   load_proptype
/* 038D88 7F004218 24040003 */   li    $a0, 3
/* 038D8C 7F00421C 02629821 */  addu  $s3, $s3, $v0
/* 038D90 7F004220 0FC006D4 */  jal   load_proptype
/* 038D94 7F004224 2404002A */   li    $a0, 42
/* 038D98 7F004228 02629821 */  addu  $s3, $s3, $v0
/* 038D9C 7F00422C 0FC006D4 */  jal   load_proptype
/* 038DA0 7F004230 2404002F */   li    $a0, 47
/* 038DA4 7F004234 02629821 */  addu  $s3, $s3, $v0
/* 038DA8 7F004238 0FC006D4 */  jal   load_proptype
/* 038DAC 7F00423C 2404002B */   li    $a0, 43
/* 038DB0 7F004240 02629821 */  addu  $s3, $s3, $v0
/* 038DB4 7F004244 0FC006D4 */  jal   load_proptype
/* 038DB8 7F004248 24040029 */   li    $a0, 41
/* 038DBC 7F00424C 02629821 */  addu  $s3, $s3, $v0
/* 038DC0 7F004250 0FC006D4 */  jal   load_proptype
/* 038DC4 7F004254 24040024 */   li    $a0, 36
/* 038DC8 7F004258 02629821 */  addu  $s3, $s3, $v0
/* 038DCC 7F00425C 0FC006D4 */  jal   load_proptype
/* 038DD0 7F004260 24040005 */   li    $a0, 5
/* 038DD4 7F004264 02629821 */  addu  $s3, $s3, $v0
/* 038DD8 7F004268 0FC006D4 */  jal   load_proptype
/* 038DDC 7F00426C 24040007 */   li    $a0, 7
/* 038DE0 7F004270 02629821 */  addu  $s3, $s3, $v0
/* 038DE4 7F004274 0FC006D4 */  jal   load_proptype
/* 038DE8 7F004278 24040014 */   li    $a0, 20
/* 038DEC 7F00427C 02629821 */  addu  $s3, $s3, $v0
/* 038DF0 7F004280 0FC006D4 */  jal   load_proptype
/* 038DF4 7F004284 24040027 */   li    $a0, 39
/* 038DF8 7F004288 02629821 */  addu  $s3, $s3, $v0
/* 038DFC 7F00428C 0FC006D4 */  jal   load_proptype
/* 038E00 7F004290 2404002D */   li    $a0, 45
/* 038E04 7F004294 02629821 */  addu  $s3, $s3, $v0
/* 038E08 7F004298 0FC006D4 */  jal   load_proptype
/* 038E0C 7F00429C 24040028 */   li    $a0, 40
/* 038E10 7F0042A0 0282A021 */  addu  $s4, $s4, $v0
.L7F0042A4:
/* 038E14 7F0042A4 0FC01558 */  jal   sub_GAME_7F005540
/* 038E18 7F0042A8 02602025 */   move  $a0, $s3
/* 038E1C 7F0042AC 0FC01591 */  jal   sub_GAME_7F005624
/* 038E20 7F0042B0 02802025 */   move  $a0, $s4
/* 038E24 7F0042B4 0FC26C01 */  jal   getPlayerCount
/* 038E28 7F0042B8 00008025 */   move  $s0, $zero
/* 038E2C 7F0042BC 1840000C */  blez  $v0, .L7F0042F0
/* 038E30 7F0042C0 00000000 */   nop   
.L7F0042C4:
/* 038E34 7F0042C4 0FC26F2B */  jal   set_cur_player
/* 038E38 7F0042C8 02002025 */   move  $a0, $s0
/* 038E3C 7F0042CC 0FC006D4 */  jal   load_proptype
/* 038E40 7F0042D0 2404000E */   li    $a0, 14
/* 038E44 7F0042D4 0FC01897 */  jal   alloc_additional_item_slots
/* 038E48 7F0042D8 00402025 */   move  $a0, $v0
/* 038E4C 7F0042DC 0FC26C01 */  jal   getPlayerCount
/* 038E50 7F0042E0 26100001 */   addiu $s0, $s0, 1
/* 038E54 7F0042E4 0202082A */  slt   $at, $s0, $v0
/* 038E58 7F0042E8 1420FFF6 */  bnez  $at, .L7F0042C4
/* 038E5C 7F0042EC 00000000 */   nop   
.L7F0042F0:
/* 038E60 7F0042F0 3C0B8007 */  lui   $t3, %hi(g_CurrentSetup+0x0c) # $t3, 0x8007
/* 038E64 7F0042F4 8D6B5D4C */  lw    $t3, %lo(g_CurrentSetup+0x0c)($t3)
/* 038E68 7F0042F8 116002E3 */  beqz  $t3, .L7F004E88
/* 038E6C 7F0042FC 00000000 */   nop   
/* 038E70 7F004300 0FC3021E */  jal   lvlGetSelectedDifficulty
/* 038E74 7F004304 00000000 */   nop   
/* 038E78 7F004308 244C0004 */  addiu $t4, $v0, 4
/* 038E7C 7F00430C 240D0001 */  li    $t5, 1
/* 038E80 7F004310 0FC26C01 */  jal   getPlayerCount
/* 038E84 7F004314 018DA004 */   sllv  $s4, $t5, $t4
/* 038E88 7F004318 28410002 */  slti  $at, $v0, 2
/* 038E8C 7F00431C 14200007 */  bnez  $at, .L7F00433C
/* 038E90 7F004320 00000000 */   nop   
/* 038E94 7F004324 0FC26C01 */  jal   getPlayerCount
/* 038E98 7F004328 00000000 */   nop   
/* 038E9C 7F00432C 244E0014 */  addiu $t6, $v0, 0x14
/* 038EA0 7F004330 240F0001 */  li    $t7, 1
/* 038EA4 7F004334 01CFC004 */  sllv  $t8, $t7, $t6
/* 038EA8 7F004338 0298A025 */  or    $s4, $s4, $t8
.L7F00433C:
/* 038EAC 7F00433C 3C128007 */  lui   $s2, %hi(g_CurrentSetup+0x0c) # $s2, 0x8007
/* 038EB0 7F004340 8E525D4C */  lw    $s2, %lo(g_CurrentSetup+0x0c)($s2)
/* 038EB4 7F004344 24010030 */  li    $at, 48
/* 038EB8 7F004348 00009825 */  move  $s3, $zero
/* 038EBC 7F00434C 92430003 */  lbu   $v1, 3($s2)
/* 038EC0 7F004350 24170034 */  li    $s7, 52
/* 038EC4 7F004354 506101FA */  beql  $v1, $at, .L7F004B40
/* 038EC8 7F004358 92430003 */   lbu   $v1, 3($s2)
/* 038ECC 7F00435C 4480A000 */  mtc1  $zero, $f20
/* 038ED0 7F004360 3416FFFF */  li    $s6, 65535
/* 038ED4 7F004364 2468FFFF */  addiu $t0, $v1, -1
.L7F004368:
/* 038ED8 7F004368 2D01002F */  sltiu $at, $t0, 0x2f
/* 038EDC 7F00436C 102001E7 */  beqz  $at, other_obj_expand
/* 038EE0 7F004370 00084080 */   sll   $t0, $t0, 2
/* 038EE4 7F004374 3C018005 */  lui   $at, %hi(jpt_object_type_expansion)
/* 038EE8 7F004378 00280821 */  addu  $at, $at, $t0
/* 038EEC 7F00437C 8C28EF98 */  lw    $t0, %lo(jpt_object_type_expansion)($at)
/* 038EF0 7F004380 01000008 */  jr    $t0
/* 038EF4 7F004384 00000000 */   nop   
actor_attr_expand:
/* 038EF8 7F004388 9250000B */  lbu   $s0, 0xb($s2)
/* 038EFC 7F00438C 0FC08CAC */  jal   chrFindByLiteralId
/* 038F00 7F004390 8E440004 */   lw    $a0, 4($s2)
/* 038F04 7F004394 104001DD */  beqz  $v0, other_obj_expand
/* 038F08 7F004398 00000000 */   nop   
/* 038F0C 7F00439C 8C490018 */  lw    $t1, 0x18($v0)
/* 038F10 7F0043A0 112001DA */  beqz  $t1, other_obj_expand
/* 038F14 7F0043A4 00000000 */   nop   
/* 038F18 7F0043A8 8C59001C */  lw    $t9, 0x1c($v0)
/* 038F1C 7F0043AC 132001D7 */  beqz  $t9, other_obj_expand
/* 038F20 7F0043B0 00000000 */   nop   
/* 038F24 7F0043B4 100001D5 */  b     other_obj_expand
/* 038F28 7F0043B8 A0500010 */   sb    $s0, 0x10($v0)
actor_expand:
/* 038F2C 7F0043BC 8FAA0278 */  lw    $t2, 0x278($sp)
/* 038F30 7F0043C0 02A02025 */  move  $a0, $s5
/* 038F34 7F0043C4 02402825 */  move  $a1, $s2
/* 038F38 7F0043C8 114001D0 */  beqz  $t2, other_obj_expand
/* 038F3C 7F0043CC 00000000 */   nop   
/* 038F40 7F0043D0 0FC08E83 */  jal   expand_09_characters
/* 038F44 7F0043D4 02603025 */   move  $a2, $s3
/* 038F48 7F0043D8 100001CC */  b     other_obj_expand
/* 038F4C 7F0043DC 00000000 */   nop   
door_expand:
/* 038F50 7F0043E0 13C001CA */  beqz  $fp, other_obj_expand
/* 038F54 7F0043E4 00000000 */   nop   
/* 038F58 7F0043E8 8E4B000C */  lw    $t3, 0xc($s2)
/* 038F5C 7F0043EC 02A02025 */  move  $a0, $s5
/* 038F60 7F0043F0 02402825 */  move  $a1, $s2
/* 038F64 7F0043F4 01746824 */  and   $t5, $t3, $s4
/* 038F68 7F0043F8 15A001C4 */  bnez  $t5, other_obj_expand
/* 038F6C 7F0043FC 00000000 */   nop   
/* 038F70 7F004400 0FC00D20 */  jal   setupDoor
/* 038F74 7F004404 02603025 */   move  $a2, $s3
/* 038F78 7F004408 100001C0 */  b     other_obj_expand
/* 038F7C 7F00440C 00000000 */   nop   
door_scale_expand:
/* 038F80 7F004410 8E4C0004 */  lw    $t4, 4($s2)
/* 038F84 7F004414 3C014780 */  li    $at, 0x47800000 # 65536.000000
/* 038F88 7F004418 44815000 */  mtc1  $at, $f10
/* 038F8C 7F00441C 448C3000 */  mtc1  $t4, $f6
/* 038F90 7F004420 3C018003 */  lui   $at, %hi(g_DoorScale) # $at, 0x8003
/* 038F94 7F004424 46803220 */  cvt.s.w $f8, $f6
/* 038F98 7F004428 460A4403 */  div.s $f16, $f8, $f10
/* 038F9C 7F00442C 100001B7 */  b     other_obj_expand
/* 038FA0 7F004430 E430A400 */   swc1  $f16, %lo(g_DoorScale)($at)
item_expand:
/* 038FA4 7F004434 8FAF0278 */  lw    $t7, 0x278($sp)
/* 038FA8 7F004438 11E001B4 */  beqz  $t7, other_obj_expand
/* 038FAC 7F00443C 00000000 */   nop   
/* 038FB0 7F004440 8E4E000C */  lw    $t6, 0xc($s2)
/* 038FB4 7F004444 02A02025 */  move  $a0, $s5
/* 038FB8 7F004448 02402825 */  move  $a1, $s2
/* 038FBC 7F00444C 01D4C024 */  and   $t8, $t6, $s4
/* 038FC0 7F004450 170001AE */  bnez  $t8, other_obj_expand
/* 038FC4 7F004454 00000000 */   nop   
/* 038FC8 7F004458 0FC009CE */  jal   weaponAssignToHome
/* 038FCC 7F00445C 02603025 */   move  $a2, $s3
/* 038FD0 7F004460 100001AA */  b     other_obj_expand
/* 038FD4 7F004464 00000000 */   nop   
key_expand:
/* 038FD8 7F004468 8FA80278 */  lw    $t0, 0x278($sp)
/* 038FDC 7F00446C 110001A7 */  beqz  $t0, other_obj_expand
/* 038FE0 7F004470 00000000 */   nop   
/* 038FE4 7F004474 8E49000C */  lw    $t1, 0xc($s2)
/* 038FE8 7F004478 02A02025 */  move  $a0, $s5
/* 038FEC 7F00447C 02402825 */  move  $a1, $s2
/* 038FF0 7F004480 0134C824 */  and   $t9, $t1, $s4
/* 038FF4 7F004484 172001A1 */  bnez  $t9, other_obj_expand
/* 038FF8 7F004488 00000000 */   nop   
/* 038FFC 7F00448C 0FC00A87 */  jal   setupKey
/* 039000 7F004490 02603025 */   move  $a2, $s3
/* 039004 7F004494 1000019D */  b     other_obj_expand
/* 039008 7F004498 00000000 */   nop   
hat_expand:
/* 03900C 7F00449C 8FAA0278 */  lw    $t2, 0x278($sp)
/* 039010 7F0044A0 1140019A */  beqz  $t2, other_obj_expand
/* 039014 7F0044A4 00000000 */   nop   
/* 039018 7F0044A8 8E4B000C */  lw    $t3, 0xc($s2)
/* 03901C 7F0044AC 02A02025 */  move  $a0, $s5
/* 039020 7F0044B0 02402825 */  move  $a1, $s2
/* 039024 7F0044B4 01746824 */  and   $t5, $t3, $s4
/* 039028 7F0044B8 15A00194 */  bnez  $t5, other_obj_expand
/* 03902C 7F0044BC 00000000 */   nop   
/* 039030 7F0044C0 0FC00A6A */  jal   setupHat
/* 039034 7F0044C4 02603025 */   move  $a2, $s3
/* 039038 7F0044C8 10000190 */  b     other_obj_expand
/* 03903C 7F0044CC 00000000 */   nop   
surv_camera_expand:
/* 039040 7F0044D0 13C0018E */  beqz  $fp, other_obj_expand
/* 039044 7F0044D4 00000000 */   nop   
/* 039048 7F0044D8 8E4C000C */  lw    $t4, 0xc($s2)
/* 03904C 7F0044DC 02A02025 */  move  $a0, $s5
/* 039050 7F0044E0 02402825 */  move  $a1, $s2
/* 039054 7F0044E4 01947824 */  and   $t7, $t4, $s4
/* 039058 7F0044E8 15E00188 */  bnez  $t7, other_obj_expand
/* 03905C 7F0044EC 00000000 */   nop   
/* 039060 7F0044F0 0FC00A8F */  jal   setupCctv
/* 039064 7F0044F4 02603025 */   move  $a2, $s3
/* 039068 7F0044F8 10000184 */  b     other_obj_expand
/* 03906C 7F0044FC 00000000 */   nop   
autogun_expand:
/* 039070 7F004500 13C00182 */  beqz  $fp, other_obj_expand
/* 039074 7F004504 00000000 */   nop   
/* 039078 7F004508 8E4E000C */  lw    $t6, 0xc($s2)
/* 03907C 7F00450C 02A02025 */  move  $a0, $s5
/* 039080 7F004510 02402825 */  move  $a1, $s2
/* 039084 7F004514 01D4C024 */  and   $t8, $t6, $s4
/* 039088 7F004518 1700017C */  bnez  $t8, other_obj_expand
/* 03908C 7F00451C 00000000 */   nop   
/* 039090 7F004520 0FC00B16 */  jal   setupAutogun
/* 039094 7F004524 02603025 */   move  $a2, $s3
/* 039098 7F004528 10000178 */  b     other_obj_expand
/* 03909C 7F00452C 00000000 */   nop   
rack_expand:
/* 0390A0 7F004530 13C00176 */  beqz  $fp, other_obj_expand
/* 0390A4 7F004534 00000000 */   nop   
/* 0390A8 7F004538 8E48000C */  lw    $t0, 0xc($s2)
/* 0390AC 7F00453C 02A02025 */  move  $a0, $s5
/* 0390B0 7F004540 02402825 */  move  $a1, $s2
/* 0390B4 7F004544 01144824 */  and   $t1, $t0, $s4
/* 0390B8 7F004548 15200170 */  bnez  $t1, other_obj_expand
/* 0390BC 7F00454C 00000000 */   nop   
/* 0390C0 7F004550 0FC00B87 */  jal   setupHangingMonitors
/* 0390C4 7F004554 02603025 */   move  $a2, $s3
/* 0390C8 7F004558 1000016C */  b     other_obj_expand
/* 0390CC 7F00455C 00000000 */   nop   
single_screen_display_expand:
/* 0390D0 7F004560 13C0016A */  beqz  $fp, other_obj_expand
/* 0390D4 7F004564 00000000 */   nop   
/* 0390D8 7F004568 8E59000C */  lw    $t9, 0xc($s2)
/* 0390DC 7F00456C 02A02025 */  move  $a0, $s5
/* 0390E0 7F004570 02402825 */  move  $a1, $s2
/* 0390E4 7F004574 03345024 */  and   $t2, $t9, $s4
/* 0390E8 7F004578 15400164 */  bnez  $t2, other_obj_expand
/* 0390EC 7F00457C 00000000 */   nop   
/* 0390F0 7F004580 0FC00B8F */  jal   setupSingleMonitor
/* 0390F4 7F004584 02603025 */   move  $a2, $s3
/* 0390F8 7F004588 10000160 */  b     other_obj_expand
/* 0390FC 7F00458C 00000000 */   nop   
multi_screen_display_expand:
/* 039100 7F004590 13C0015E */  beqz  $fp, other_obj_expand
/* 039104 7F004594 00000000 */   nop   
/* 039108 7F004598 8E4B000C */  lw    $t3, 0xc($s2)
/* 03910C 7F00459C 02A02025 */  move  $a0, $s5
/* 039110 7F0045A0 02402825 */  move  $a1, $s2
/* 039114 7F0045A4 01746824 */  and   $t5, $t3, $s4
/* 039118 7F0045A8 15A00158 */  bnez  $t5, other_obj_expand
/* 03911C 7F0045AC 00000000 */   nop   
/* 039120 7F0045B0 0FC00C34 */  jal   setupMultiMonitor
/* 039124 7F0045B4 02603025 */   move  $a2, $s3
/* 039128 7F0045B8 10000154 */  b     other_obj_expand
/* 03912C 7F0045BC 00000000 */   nop   
body_armor_expand:
/* 039130 7F0045C0 13C00152 */  beqz  $fp, other_obj_expand
/* 039134 7F0045C4 00000000 */   nop   
/* 039138 7F0045C8 8E4C000C */  lw    $t4, 0xc($s2)
/* 03913C 7F0045CC 3C0E8005 */  lui   $t6, %hi(j_text_trigger) # $t6, 0x8005
/* 039140 7F0045D0 01947824 */  and   $t7, $t4, $s4
/* 039144 7F0045D4 51E00005 */  beql  $t7, $zero, .L7F0045EC
/* 039148 7F0045D8 8E580080 */   lw    $t8, 0x80($s2)
/* 03914C 7F0045DC 8DCE8500 */  lw    $t6, %lo(j_text_trigger)($t6)
/* 039150 7F0045E0 11C0014A */  beqz  $t6, other_obj_expand
/* 039154 7F0045E4 00000000 */   nop   
/* 039158 7F0045E8 8E580080 */  lw    $t8, 0x80($s2)
.L7F0045EC:
/* 03915C 7F0045EC 3C014780 */  li    $at, 0x47800000 # 65536.000000
/* 039160 7F0045F0 44813000 */  mtc1  $at, $f6
/* 039164 7F0045F4 44989000 */  mtc1  $t8, $f18
/* 039168 7F0045F8 02A02025 */  move  $a0, $s5
/* 03916C 7F0045FC 02402825 */  move  $a1, $s2
/* 039170 7F004600 46809120 */  cvt.s.w $f4, $f18
/* 039174 7F004604 02603025 */  move  $a2, $s3
/* 039178 7F004608 46062203 */  div.s $f8, $f4, $f6
/* 03917C 7F00460C E6480080 */  swc1  $f8, 0x80($s2)
/* 039180 7F004610 C64A0080 */  lwc1  $f10, 0x80($s2)
/* 039184 7F004614 0FC00767 */  jal   domakedefaultobj
/* 039188 7F004618 E64A0084 */   swc1  $f10, 0x84($s2)
/* 03918C 7F00461C 1000013B */  b     other_obj_expand
/* 039190 7F004620 00000000 */   nop   
type2F_tinted_glass:
/* 039194 7F004624 13C00139 */  beqz  $fp, other_obj_expand
/* 039198 7F004628 00000000 */   nop   
/* 03919C 7F00462C 8E48000C */  lw    $t0, 0xc($s2)
/* 0391A0 7F004630 01144824 */  and   $t1, $t0, $s4
/* 0391A4 7F004634 15200135 */  bnez  $t1, other_obj_expand
/* 0391A8 7F004638 00000000 */   nop   
/* 0391AC 7F00463C 8E590008 */  lw    $t9, 8($s2)
/* 0391B0 7F004640 001950C0 */  sll   $t2, $t9, 3
/* 0391B4 7F004644 05430039 */  bgezl $t2, .L7F00472C
/* 0391B8 7F004648 02A02025 */   move  $a0, $s5
/* 0391BC 7F00464C 86420006 */  lh    $v0, 6($s2)
/* 0391C0 7F004650 3C0D8007 */  lui   $t5, %hi(g_CurrentSetup+0x1C) # $t5, 0x8007
/* 0391C4 7F004654 27A50118 */  addiu $a1, $sp, 0x118
/* 0391C8 7F004658 28412710 */  slti  $at, $v0, 0x2710
/* 0391CC 7F00465C 14200032 */  bnez  $at, .L7F004728
/* 0391D0 7F004660 00025900 */   sll   $t3, $v0, 4
/* 0391D4 7F004664 8DAD5D5C */  lw    $t5, %lo(g_CurrentSetup+0x1C)($t5)
/* 0391D8 7F004668 01625821 */  addu  $t3, $t3, $v0
/* 0391DC 7F00466C 000B5880 */  sll   $t3, $t3, 2
/* 0391E0 7F004670 3C01FFF5 */  lui   $at, (0xFFF59FC0 >> 16) # lui $at, 0xfff5
/* 0391E4 7F004674 34219FC0 */  ori   $at, (0xFFF59FC0 & 0xFFFF) # ori $at, $at, 0x9fc0
/* 0391E8 7F004678 016D8021 */  addu  $s0, $t3, $t5
/* 0391EC 7F00467C 02018021 */  addu  $s0, $s0, $at
/* 0391F0 7F004680 0FC006F5 */  jal   sub_GAME_7F001BD4
/* 0391F4 7F004684 02002025 */   move  $a0, $s0
/* 0391F8 7F004688 3C014120 */  li    $at, 0x41200000 # 10.000000
/* 0391FC 7F00468C 44810000 */  mtc1  $at, $f0
/* 039200 7F004690 C610000C */  lwc1  $f16, 0xc($s0)
/* 039204 7F004694 C7A40118 */  lwc1  $f4, 0x118($sp)
/* 039208 7F004698 27A40118 */  addiu $a0, $sp, 0x118
/* 03920C 7F00469C 46008482 */  mul.s $f18, $f16, $f0
/* 039210 7F0046A0 C7B0011C */  lwc1  $f16, 0x11c($sp)
/* 039214 7F0046A4 27A5010C */  addiu $a1, $sp, 0x10c
/* 039218 7F0046A8 46049180 */  add.s $f6, $f18, $f4
/* 03921C 7F0046AC E7A6010C */  swc1  $f6, 0x10c($sp)
/* 039220 7F0046B0 C6080010 */  lwc1  $f8, 0x10($s0)
/* 039224 7F0046B4 46004282 */  mul.s $f10, $f8, $f0
/* 039228 7F0046B8 46105480 */  add.s $f18, $f10, $f16
/* 03922C 7F0046BC C7AA0120 */  lwc1  $f10, 0x120($sp)
/* 039230 7F0046C0 E7B20110 */  swc1  $f18, 0x110($sp)
/* 039234 7F0046C4 C6060014 */  lwc1  $f6, 0x14($s0)
/* 039238 7F0046C8 46003202 */  mul.s $f8, $f6, $f0
/* 03923C 7F0046CC 460A4480 */  add.s $f18, $f8, $f10
/* 039240 7F0046D0 E7B20114 */  swc1  $f18, 0x114($sp)
/* 039244 7F0046D4 C606000C */  lwc1  $f6, 0xc($s0)
/* 039248 7F0046D8 46060202 */  mul.s $f8, $f0, $f6
/* 03924C 7F0046DC 46082481 */  sub.s $f18, $f4, $f8
/* 039250 7F0046E0 E7B20118 */  swc1  $f18, 0x118($sp)
/* 039254 7F0046E4 C6060010 */  lwc1  $f6, 0x10($s0)
/* 039258 7F0046E8 46060102 */  mul.s $f4, $f0, $f6
/* 03925C 7F0046EC 46048201 */  sub.s $f8, $f16, $f4
/* 039260 7F0046F0 E7A8011C */  swc1  $f8, 0x11c($sp)
/* 039264 7F0046F4 C6120014 */  lwc1  $f18, 0x14($s0)
/* 039268 7F0046F8 46120182 */  mul.s $f6, $f0, $f18
/* 03926C 7F0046FC 46065401 */  sub.s $f16, $f10, $f6
/* 039270 7F004700 0FC2EA6D */  jal   sub_GAME_7F0B9E04
/* 039274 7F004704 E7B00120 */   swc1  $f16, 0x120($sp)
/* 039278 7F004708 8E4C0090 */  lw    $t4, 0x90($s2)
/* 03927C 7F00470C 3C014780 */  li    $at, 0x47800000 # 65536.000000
/* 039280 7F004710 44819000 */  mtc1  $at, $f18
/* 039284 7F004714 448C2000 */  mtc1  $t4, $f4
/* 039288 7F004718 AE42008C */  sw    $v0, 0x8c($s2)
/* 03928C 7F00471C 46802220 */  cvt.s.w $f8, $f4
/* 039290 7F004720 46124283 */  div.s $f10, $f8, $f18
/* 039294 7F004724 E64A0090 */  swc1  $f10, 0x90($s2)
.L7F004728:
/* 039298 7F004728 02A02025 */  move  $a0, $s5
.L7F00472C:
/* 03929C 7F00472C 02402825 */  move  $a1, $s2
/* 0392A0 7F004730 0FC00767 */  jal   domakedefaultobj
/* 0392A4 7F004734 02603025 */   move  $a2, $s3
/* 0392A8 7F004738 100000F4 */  b     other_obj_expand
/* 0392AC 7F00473C 00000000 */   nop   
obj_03_expand:
/* 0392B0 7F004740 13C000F2 */  beqz  $fp, other_obj_expand
/* 0392B4 7F004744 00000000 */   nop   
/* 0392B8 7F004748 8E4F000C */  lw    $t7, 0xc($s2)
/* 0392BC 7F00474C 02A02025 */  move  $a0, $s5
/* 0392C0 7F004750 02402825 */  move  $a1, $s2
/* 0392C4 7F004754 01F47024 */  and   $t6, $t7, $s4
/* 0392C8 7F004758 15C000EC */  bnez  $t6, other_obj_expand
/* 0392CC 7F00475C 00000000 */   nop   
/* 0392D0 7F004760 0FC00767 */  jal   domakedefaultobj
/* 0392D4 7F004764 02603025 */   move  $a2, $s3
/* 0392D8 7F004768 100000E8 */  b     other_obj_expand
/* 0392DC 7F00476C 00000000 */   nop   
ammo_box_expand:
/* 0392E0 7F004770 0FC26C01 */  jal   getPlayerCount
/* 0392E4 7F004774 24100001 */   li    $s0, 1
/* 0392E8 7F004778 28410002 */  slti  $at, $v0, 2
/* 0392EC 7F00477C 1420000E */  bnez  $at, .L7F0047B8
/* 0392F0 7F004780 00000000 */   nop   
/* 0392F4 7F004784 0FC31CBD */  jal   getPtrMPWeaponSetData
/* 0392F8 7F004788 00000000 */   nop   
/* 0392FC 7F00478C 3C188007 */  lui   $t8, %hi(lastmpweaponnum) # $t8, 0x8007
/* 039300 7F004790 8F189580 */  lw    $t8, %lo(lastmpweaponnum)($t8)
/* 039304 7F004794 00184080 */  sll   $t0, $t8, 2
/* 039308 7F004798 01184023 */  subu  $t0, $t0, $t8
/* 03930C 7F00479C 000840C0 */  sll   $t0, $t0, 3
/* 039310 7F0047A0 00481821 */  addu  $v1, $v0, $t0
/* 039314 7F0047A4 8C64000C */  lw    $a0, 0xc($v1)
/* 039318 7F0047A8 8C700010 */  lw    $s0, 0x10($v1)
/* 03931C 7F0047AC 00044880 */  sll   $t1, $a0, 2
/* 039320 7F0047B0 0249C821 */  addu  $t9, $s2, $t1
/* 039324 7F0047B4 A730007E */  sh    $s0, 0x7e($t9)
.L7F0047B8:
/* 039328 7F0047B8 1A0000D4 */  blez  $s0, other_obj_expand
/* 03932C 7F0047BC 00000000 */   nop   
/* 039330 7F0047C0 13C000D2 */  beqz  $fp, other_obj_expand
/* 039334 7F0047C4 00000000 */   nop   
/* 039338 7F0047C8 8E4A000C */  lw    $t2, 0xc($s2)
/* 03933C 7F0047CC 00008825 */  move  $s1, $zero
/* 039340 7F0047D0 02408025 */  move  $s0, $s2
/* 039344 7F0047D4 01545824 */  and   $t3, $t2, $s4
/* 039348 7F0047D8 156000CC */  bnez  $t3, other_obj_expand
/* 03934C 7F0047DC 00000000 */   nop   
.L7F0047E0:
/* 039350 7F0047E0 960D0082 */  lhu   $t5, 0x82($s0)
/* 039354 7F0047E4 59A00007 */  blezl $t5, .L7F004804
/* 039358 7F0047E8 26310004 */   addiu $s1, $s1, 4
/* 03935C 7F0047EC 96040080 */  lhu   $a0, 0x80($s0)
/* 039360 7F0047F0 52C40004 */  beql  $s6, $a0, .L7F004804
/* 039364 7F0047F4 26310004 */   addiu $s1, $s1, 4
/* 039368 7F0047F8 0FC15C4E */  jal   modelLoad
/* 03936C 7F0047FC 00000000 */   nop   
/* 039370 7F004800 26310004 */  addiu $s1, $s1, 4
.L7F004804:
/* 039374 7F004804 1637FFF6 */  bne   $s1, $s7, .L7F0047E0
/* 039378 7F004808 26100004 */   addiu $s0, $s0, 4
/* 03937C 7F00480C 02A02025 */  move  $a0, $s5
/* 039380 7F004810 02402825 */  move  $a1, $s2
/* 039384 7F004814 0FC00767 */  jal   domakedefaultobj
/* 039388 7F004818 02603025 */   move  $a2, $s3
/* 03938C 7F00481C 100000BB */  b     other_obj_expand
/* 039390 7F004820 00000000 */   nop   
type2D_tank:
/* 039394 7F004824 13C000B9 */  beqz  $fp, other_obj_expand
/* 039398 7F004828 00000000 */   nop   
/* 03939C 7F00482C 8E4C000C */  lw    $t4, 0xc($s2)
/* 0393A0 7F004830 24040020 */  li    $a0, 32
/* 0393A4 7F004834 01947824 */  and   $t7, $t4, $s4
/* 0393A8 7F004838 15E000B4 */  bnez  $t7, other_obj_expand
/* 0393AC 7F00483C 00000000 */   nop   
/* 0393B0 7F004840 0FC015CC */  jal   weaponLoadProjectileModels
/* 0393B4 7F004844 E7B400E8 */   swc1  $f20, 0xe8($sp)
/* 0393B8 7F004848 02A02025 */  move  $a0, $s5
/* 0393BC 7F00484C 02402825 */  move  $a1, $s2
/* 0393C0 7F004850 0FC00767 */  jal   domakedefaultobj
/* 0393C4 7F004854 02603025 */   move  $a2, $s3
/* 0393C8 7F004858 E65400C8 */  swc1  $f20, 0xc8($s2)
/* 0393CC 7F00485C E65400CC */  swc1  $f20, 0xcc($s2)
/* 0393D0 7F004860 C64C0038 */  lwc1  $f12, 0x38($s2)
/* 0393D4 7F004864 0FC16BD4 */  jal   atan2f
/* 0393D8 7F004868 C64E0040 */   lwc1  $f14, 0x40($s2)
/* 0393DC 7F00486C 3C018005 */  lui   $at, %hi(D_8004F024) # $at, 0x8005
/* 0393E0 7F004870 C426F054 */  lwc1  $f6, %lo(D_8004F024)($at)
/* 0393E4 7F004874 8E420010 */  lw    $v0, 0x10($s2)
/* 0393E8 7F004878 46003401 */  sub.s $f16, $f6, $f0
/* 0393EC 7F00487C 10400006 */  beqz  $v0, .L7F004898
/* 0393F0 7F004880 E65000DC */   swc1  $f16, 0xdc($s2)
/* 0393F4 7F004884 8C440014 */  lw    $a0, 0x14($v0)
/* 0393F8 7F004888 8C450008 */  lw    $a1, 8($v0)
/* 0393FC 7F00488C 0FC2CD48 */  jal   stanGetPositionYValue
/* 039400 7F004890 8C460010 */   lw    $a2, 0x10($v0)
/* 039404 7F004894 E7A000E8 */  swc1  $f0, 0xe8($sp)
.L7F004898:
/* 039408 7F004898 C7A200E8 */  lwc1  $f2, 0xe8($sp)
/* 03940C 7F00489C 3C018005 */  lui   $at, %hi(D_8004F028) # $at, 0x8005
/* 039410 7F0048A0 E64200D4 */  swc1  $f2, 0xd4($s2)
/* 039414 7F0048A4 C424F058 */  lwc1  $f4, %lo(D_8004F028)($at)
/* 039418 7F0048A8 46041203 */  div.s $f8, $f2, $f4
/* 03941C 7F0048AC 10000097 */  b     other_obj_expand
/* 039420 7F0048B0 E64800D0 */   swc1  $f8, 0xd0($s2)
type27_wheeled_vehicle:
/* 039424 7F0048B4 13C00095 */  beqz  $fp, other_obj_expand
/* 039428 7F0048B8 00000000 */   nop   
/* 03942C 7F0048BC 8E4E000C */  lw    $t6, 0xc($s2)
/* 039430 7F0048C0 02A02025 */  move  $a0, $s5
/* 039434 7F0048C4 02402825 */  move  $a1, $s2
/* 039438 7F0048C8 01D4C024 */  and   $t8, $t6, $s4
/* 03943C 7F0048CC 1700008F */  bnez  $t8, other_obj_expand
/* 039440 7F0048D0 00000000 */   nop   
/* 039444 7F0048D4 0FC00767 */  jal   domakedefaultobj
/* 039448 7F0048D8 02603025 */   move  $a2, $s3
/* 03944C 7F0048DC 8E440014 */  lw    $a0, 0x14($s2)
/* 039450 7F0048E0 5080000E */  beql  $a0, $zero, .L7F00491C
/* 039454 7F0048E4 3C01BF80 */   lui   $at, 0xbf80
/* 039458 7F0048E8 8C880008 */  lw    $t0, 8($a0)
/* 03945C 7F0048EC 8D090008 */  lw    $t1, 8($t0)
/* 039460 7F0048F0 8D250014 */  lw    $a1, 0x14($t1)
/* 039464 7F0048F4 50A00009 */  beql  $a1, $zero, .L7F00491C
/* 039468 7F0048F8 3C01BF80 */   lui   $at, 0xbf80
/* 03946C 7F0048FC 0FC1B363 */  jal   modelGetNodeRwData
/* 039470 7F004900 00000000 */   nop   
/* 039474 7F004904 8E590008 */  lw    $t9, 8($s2)
/* 039478 7F004908 3C011000 */  li    $at, 0x10000000 # 0.000000
/* 03947C 7F00490C 03215024 */  and   $t2, $t9, $at
/* 039480 7F004910 2D4B0001 */  sltiu $t3, $t2, 1
/* 039484 7F004914 AC4B0000 */  sw    $t3, ($v0)
/* 039488 7F004918 3C01BF80 */  li    $at, 0xBF800000 # -1.000000
.L7F00491C:
/* 03948C 7F00491C 44819000 */  mtc1  $at, $f18
/* 039490 7F004920 E6540088 */  swc1  $f20, 0x88($s2)
/* 039494 7F004924 E654008C */  swc1  $f20, 0x8c($s2)
/* 039498 7F004928 E6540090 */  swc1  $f20, 0x90($s2)
/* 03949C 7F00492C E6540094 */  swc1  $f20, 0x94($s2)
/* 0394A0 7F004930 E654009C */  swc1  $f20, 0x9c($s2)
/* 0394A4 7F004934 E65400A0 */  swc1  $f20, 0xa0($s2)
/* 0394A8 7F004938 8E440080 */  lw    $a0, 0x80($s2)
/* 0394AC 7F00493C 0FC0D5A6 */  jal   ailistFindById
/* 0394B0 7F004940 E6520098 */   swc1  $f18, 0x98($s2)
/* 0394B4 7F004944 240DFFFF */  li    $t5, -1
/* 0394B8 7F004948 AE420080 */  sw    $v0, 0x80($s2)
/* 0394BC 7F00494C A6400084 */  sh    $zero, 0x84($s2)
/* 0394C0 7F004950 A64D0086 */  sh    $t5, 0x86($s2)
/* 0394C4 7F004954 AE4000A4 */  sw    $zero, 0xa4($s2)
/* 0394C8 7F004958 AE4000A8 */  sw    $zero, 0xa8($s2)
/* 0394CC 7F00495C 1000006B */  b     other_obj_expand
/* 0394D0 7F004960 AE4000AC */   sw    $zero, 0xac($s2)
type28_aircraft:
/* 0394D4 7F004964 13C00069 */  beqz  $fp, other_obj_expand
/* 0394D8 7F004968 00000000 */   nop   
/* 0394DC 7F00496C 8E4C000C */  lw    $t4, 0xc($s2)
/* 0394E0 7F004970 02A02025 */  move  $a0, $s5
/* 0394E4 7F004974 02402825 */  move  $a1, $s2
/* 0394E8 7F004978 01947824 */  and   $t7, $t4, $s4
/* 0394EC 7F00497C 15E00063 */  bnez  $t7, other_obj_expand
/* 0394F0 7F004980 00000000 */   nop   
/* 0394F4 7F004984 0FC00767 */  jal   domakedefaultobj
/* 0394F8 7F004988 02603025 */   move  $a2, $s3
/* 0394FC 7F00498C 3C01BF80 */  li    $at, 0xBF800000 # -1.000000
/* 039500 7F004990 44810000 */  mtc1  $at, $f0
/* 039504 7F004994 E6540098 */  swc1  $f20, 0x98($s2)
/* 039508 7F004998 E654009C */  swc1  $f20, 0x9c($s2)
/* 03950C 7F00499C E6540088 */  swc1  $f20, 0x88($s2)
/* 039510 7F0049A0 E654008C */  swc1  $f20, 0x8c($s2)
/* 039514 7F0049A4 E6540090 */  swc1  $f20, 0x90($s2)
/* 039518 7F0049A8 E65400A4 */  swc1  $f20, 0xa4($s2)
/* 03951C 7F0049AC 8E440080 */  lw    $a0, 0x80($s2)
/* 039520 7F0049B0 E64000A0 */  swc1  $f0, 0xa0($s2)
/* 039524 7F0049B4 0FC0D5A6 */  jal   ailistFindById
/* 039528 7F0049B8 E6400094 */   swc1  $f0, 0x94($s2)
/* 03952C 7F0049BC 240EFFFF */  li    $t6, -1
/* 039530 7F0049C0 AE420080 */  sw    $v0, 0x80($s2)
/* 039534 7F0049C4 A6400084 */  sh    $zero, 0x84($s2)
/* 039538 7F0049C8 A64E0086 */  sh    $t6, 0x86($s2)
/* 03953C 7F0049CC AE4000A8 */  sw    $zero, 0xa8($s2)
/* 039540 7F0049D0 AE4000AC */  sw    $zero, 0xac($s2)
/* 039544 7F0049D4 1000004D */  b     other_obj_expand
/* 039548 7F0049D8 AE4000B0 */   sw    $zero, 0xb0($s2)
tag_expand:
/* 03954C 7F0049DC 86580006 */  lh    $t8, 6($s2)
/* 039550 7F0049E0 02A02025 */  move  $a0, $s5
/* 039554 7F0049E4 0FC15CE8 */  jal   setupCommandGetObject
/* 039558 7F0049E8 03132821 */   addu  $a1, $t8, $s3
/* 03955C 7F0049EC 10400004 */  beqz  $v0, .L7F004A00
/* 039560 7F0049F0 AE42000C */   sw    $v0, 0xc($s2)
/* 039564 7F0049F4 8C480064 */  lw    $t0, 0x64($v0)
/* 039568 7F0049F8 35090010 */  ori   $t1, $t0, 0x10
/* 03956C 7F0049FC AC490064 */  sw    $t1, 0x64($v0)
.L7F004A00:
/* 039570 7F004A00 0FC013E8 */  jal   set_parent_cur_tag_entry
/* 039574 7F004A04 02402025 */   move  $a0, $s2
/* 039578 7F004A08 10000040 */  b     other_obj_expand
/* 03957C 7F004A0C 00000000 */   nop   
type25_rename:
/* 039580 7F004A10 8E590004 */  lw    $t9, 4($s2)
/* 039584 7F004A14 02A02025 */  move  $a0, $s5
/* 039588 7F004A18 0FC15CE8 */  jal   setupCommandGetObject
/* 03958C 7F004A1C 03332821 */   addu  $a1, $t9, $s3
/* 039590 7F004A20 10400004 */  beqz  $v0, .L7F004A34
/* 039594 7F004A24 AE420024 */   sw    $v0, 0x24($s2)
/* 039598 7F004A28 8C4A0064 */  lw    $t2, 0x64($v0)
/* 03959C 7F004A2C 354B0400 */  ori   $t3, $t2, 0x400
/* 0395A0 7F004A30 AC4B0064 */  sw    $t3, 0x64($v0)
.L7F004A34:
/* 0395A4 7F004A34 0FC238E2 */  jal   bondinvAddTextOverride
/* 0395A8 7F004A38 02402025 */   move  $a0, $s2
/* 0395AC 7F004A3C 10000033 */  b     other_obj_expand
/* 0395B0 7F004A40 00000000 */   nop   
type23_solo_brief_text:
/* 0395B4 7F004A44 0FC013EE */  jal   setup_briefing_text_entry_parent
/* 0395B8 7F004A48 02402025 */   move  $a0, $s2
/* 0395BC 7F004A4C 1000002F */  b     other_obj_expand
/* 0395C0 7F004A50 00000000 */   nop   
type2E_viewport_pos:
/* 0395C4 7F004A54 8E4D0004 */  lw    $t5, 4($s2)
/* 0395C8 7F004A58 3C0142C8 */  li    $at, 0x42C80000 # 100.000000
/* 0395CC 7F004A5C 44810000 */  mtc1  $at, $f0
/* 0395D0 7F004A60 448D5000 */  mtc1  $t5, $f10
/* 0395D4 7F004A64 8E4F000C */  lw    $t7, 0xc($s2)
/* 0395D8 7F004A68 8E4C0008 */  lw    $t4, 8($s2)
/* 0395DC 7F004A6C 468051A0 */  cvt.s.w $f6, $f10
/* 0395E0 7F004A70 448F5000 */  mtc1  $t7, $f10
/* 0395E4 7F004A74 448C2000 */  mtc1  $t4, $f4
/* 0395E8 7F004A78 8E4E0010 */  lw    $t6, 0x10($s2)
/* 0395EC 7F004A7C 8E580014 */  lw    $t8, 0x14($s2)
/* 0395F0 7F004A80 46802220 */  cvt.s.w $f8, $f4
/* 0395F4 7F004A84 448E2000 */  mtc1  $t6, $f4
/* 0395F8 7F004A88 3C014780 */  li    $at, 0x47800000 # 65536.000000
/* 0395FC 7F004A8C 46003403 */  div.s $f16, $f6, $f0
/* 039600 7F004A90 468051A0 */  cvt.s.w $f6, $f10
/* 039604 7F004A94 46004483 */  div.s $f18, $f8, $f0
/* 039608 7F004A98 E6500004 */  swc1  $f16, 4($s2)
/* 03960C 7F004A9C 46802220 */  cvt.s.w $f8, $f4
/* 039610 7F004AA0 44812000 */  mtc1  $at, $f4
/* 039614 7F004AA4 46003403 */  div.s $f16, $f6, $f0
/* 039618 7F004AA8 44983000 */  mtc1  $t8, $f6
/* 03961C 7F004AAC E6520008 */  swc1  $f18, 8($s2)
/* 039620 7F004AB0 44819000 */  mtc1  $at, $f18
/* 039624 7F004AB4 00000000 */  nop   
/* 039628 7F004AB8 46124283 */  div.s $f10, $f8, $f18
/* 03962C 7F004ABC E650000C */  swc1  $f16, 0xc($s2)
/* 039630 7F004AC0 46803420 */  cvt.s.w $f16, $f6
/* 039634 7F004AC4 46048203 */  div.s $f8, $f16, $f4
/* 039638 7F004AC8 E64A0010 */  swc1  $f10, 0x10($s2)
/* 03963C 7F004ACC 1000000F */  b     other_obj_expand
/* 039640 7F004AD0 E6480014 */   swc1  $f8, 0x14($s2)
type17_objective_expand:
/* 039644 7F004AD4 0FC013F4 */  jal   add_ptr_to_objective
/* 039648 7F004AD8 02402025 */   move  $a0, $s2
/* 03964C 7F004ADC 1000000B */  b     other_obj_expand
/* 039650 7F004AE0 00000000 */   nop   
type20_subobjective_expand:
/* 039654 7F004AE4 0FC01403 */  jal   set_parent_cur_obj_enter_room
/* 039658 7F004AE8 02402025 */   move  $a0, $s2
/* 03965C 7F004AEC 10000007 */  b     other_obj_expand
/* 039660 7F004AF0 00000000 */   nop   
type21_subobjective_expand:
/* 039664 7F004AF4 0FC01409 */  jal   set_parent_cur_obj_deposited_in_room
/* 039668 7F004AF8 02402025 */   move  $a0, $s2
/* 03966C 7F004AFC 10000003 */  b     other_obj_expand
/* 039670 7F004B00 00000000 */   nop   
type1E_subobjective_expand:
/* 039674 7F004B04 0FC0140F */  jal   set_parent_cur_obj_photograph
/* 039678 7F004B08 02402025 */   move  $a0, $s2
other_obj_expand:
/* 03967C 7F004B0C 0FC15B7D */  jal   sizepropdef
/* 039680 7F004B10 02402025 */   move  $a0, $s2
/* 039684 7F004B14 00024080 */  sll   $t0, $v0, 2
/* 039688 7F004B18 01129021 */  addu  $s2, $t0, $s2
/* 03968C 7F004B1C 92430003 */  lbu   $v1, 3($s2)
/* 039690 7F004B20 24010030 */  li    $at, 48
/* 039694 7F004B24 26730001 */  addiu $s3, $s3, 1
/* 039698 7F004B28 5461FE0F */  bnel  $v1, $at, .L7F004368
/* 03969C 7F004B2C 2468FFFF */   addiu $t0, $v1, -1
/* 0396A0 7F004B30 3C128007 */  lui   $s2, %hi(g_CurrentSetup+0x0c) # $s2, 0x8007
/* 0396A4 7F004B34 8E525D4C */  lw    $s2, %lo(g_CurrentSetup+0x0c)($s2)
/* 0396A8 7F004B38 00009825 */  move  $s3, $zero
/* 0396AC 7F004B3C 92430003 */  lbu   $v1, 3($s2)
.L7F004B40:
/* 0396B0 7F004B40 24010030 */  li    $at, 48
/* 0396B4 7F004B44 3C170008 */  lui   $s7, 8
/* 0396B8 7F004B48 106100CF */  beq   $v1, $at, .L7F004E88
/* 0396BC 7F004B4C 24160008 */   li    $s6, 8
/* 0396C0 7F004B50 241E002B */  li    $fp, 43
/* 0396C4 7F004B54 24140001 */  li    $s4, 1
/* 0396C8 7F004B58 2469FFFD */  addiu $t1, $v1, -3
.L7F004B5C:
/* 0396CC 7F004B5C 2D21002D */  sltiu $at, $t1, 0x2d
/* 0396D0 7F004B60 102000A4 */  beqz  $at, .L7F004DF4
/* 0396D4 7F004B64 00094880 */   sll   $t1, $t1, 2
/* 0396D8 7F004B68 3C018005 */  lui   $at, %hi(jpt_8004F02C)
/* 0396DC 7F004B6C 00290821 */  addu  $at, $at, $t1
/* 0396E0 7F004B70 8C29F05C */  lw    $t1, %lo(jpt_8004F02C)($at)
/* 0396E4 7F004B74 01200008 */  jr    $t1
/* 0396E8 7F004B78 00000000 */   nop   
.L7F004B7C:
/* 0396EC 7F004B7C 8E590010 */  lw    $t9, 0x10($s2)
/* 0396F0 7F004B80 1320009C */  beqz  $t9, .L7F004DF4
/* 0396F4 7F004B84 00000000 */   nop   
/* 0396F8 7F004B88 8E4A0008 */  lw    $t2, 8($s2)
/* 0396FC 7F004B8C 314B8000 */  andi  $t3, $t2, 0x8000
/* 039700 7F004B90 11600098 */  beqz  $t3, .L7F004DF4
/* 039704 7F004B94 00000000 */   nop   
/* 039708 7F004B98 86420006 */  lh    $v0, 6($s2)
/* 03970C 7F004B9C 02A02025 */  move  $a0, $s5
/* 039710 7F004BA0 0FC15CE8 */  jal   setupCommandGetObject
/* 039714 7F004BA4 02622821 */   addu  $a1, $s3, $v0
/* 039718 7F004BA8 10400092 */  beqz  $v0, .L7F004DF4
/* 03971C 7F004BAC 00408025 */   move  $s0, $v0
/* 039720 7F004BB0 8C4D0010 */  lw    $t5, 0x10($v0)
/* 039724 7F004BB4 11A0008F */  beqz  $t5, .L7F004DF4
/* 039728 7F004BB8 00000000 */   nop   
/* 03972C 7F004BBC 8E4C0064 */  lw    $t4, 0x64($s2)
/* 039730 7F004BC0 8E440014 */  lw    $a0, 0x14($s2)
/* 039734 7F004BC4 01977825 */  or    $t7, $t4, $s7
/* 039738 7F004BC8 AE4F0064 */  sw    $t7, 0x64($s2)
/* 03973C 7F004BCC 0FC1B51A */  jal   modelSetScale
/* 039740 7F004BD0 8C850014 */   lw    $a1, 0x14($a0)
/* 039744 7F004BD4 8E440010 */  lw    $a0, 0x10($s2)
/* 039748 7F004BD8 0FC0EA29 */  jal   chrpropReparent
/* 03974C 7F004BDC 8E050010 */   lw    $a1, 0x10($s0)
/* 039750 7F004BE0 10000084 */  b     .L7F004DF4
/* 039754 7F004BE4 00000000 */   nop   
.L7F004BE8:
/* 039758 7F004BE8 8E4E0004 */  lw    $t6, 4($s2)
/* 03975C 7F004BEC 0FC15BE2 */  jal   setupGetPtrToCommandByIndex
/* 039760 7F004BF0 01D32021 */   addu  $a0, $t6, $s3
/* 039764 7F004BF4 8E580008 */  lw    $t8, 8($s2)
/* 039768 7F004BF8 00408025 */  move  $s0, $v0
/* 03976C 7F004BFC 0FC15BE2 */  jal   setupGetPtrToCommandByIndex
/* 039770 7F004C00 03132021 */   addu  $a0, $t8, $s3
/* 039774 7F004C04 1200007B */  beqz  $s0, .L7F004DF4
/* 039778 7F004C08 00402825 */   move  $a1, $v0
/* 03977C 7F004C0C 10400079 */  beqz  $v0, .L7F004DF4
/* 039780 7F004C10 00000000 */   nop   
/* 039784 7F004C14 92080003 */  lbu   $t0, 3($s0)
/* 039788 7F004C18 16C80076 */  bne   $s6, $t0, .L7F004DF4
/* 03978C 7F004C1C 00000000 */   nop   
/* 039790 7F004C20 90490003 */  lbu   $t1, 3($v0)
/* 039794 7F004C24 16C90073 */  bne   $s6, $t1, .L7F004DF4
/* 039798 7F004C28 00000000 */   nop   
/* 03979C 7F004C2C 0FC1489C */  jal   propweaponSetDual
/* 0397A0 7F004C30 02002025 */   move  $a0, $s0
/* 0397A4 7F004C34 1000006F */  b     .L7F004DF4
/* 0397A8 7F004C38 00000000 */   nop   
.L7F004C3C:
/* 0397AC 7F004C3C 8E420004 */  lw    $v0, 4($s2)
/* 0397B0 7F004C40 8E510008 */  lw    $s1, 8($s2)
/* 0397B4 7F004C44 02A02025 */  move  $a0, $s5
/* 0397B8 7F004C48 0FC15CE8 */  jal   setupCommandGetObject
/* 0397BC 7F004C4C 02622821 */   addu  $a1, $s3, $v0
/* 0397C0 7F004C50 00408025 */  move  $s0, $v0
/* 0397C4 7F004C54 0FC15BE2 */  jal   setupGetPtrToCommandByIndex
/* 0397C8 7F004C58 02712021 */   addu  $a0, $s3, $s1
/* 0397CC 7F004C5C 12000065 */  beqz  $s0, .L7F004DF4
/* 0397D0 7F004C60 00000000 */   nop   
/* 0397D4 7F004C64 8E030010 */  lw    $v1, 0x10($s0)
/* 0397D8 7F004C68 10600062 */  beqz  $v1, .L7F004DF4
/* 0397DC 7F004C6C 00000000 */   nop   
/* 0397E0 7F004C70 10400060 */  beqz  $v0, .L7F004DF4
/* 0397E4 7F004C74 00000000 */   nop   
/* 0397E8 7F004C78 90590003 */  lbu   $t9, 3($v0)
/* 0397EC 7F004C7C 1699005D */  bne   $s4, $t9, .L7F004DF4
/* 0397F0 7F004C80 00000000 */   nop   
/* 0397F4 7F004C84 8C4A0010 */  lw    $t2, 0x10($v0)
/* 0397F8 7F004C88 1140005A */  beqz  $t2, .L7F004DF4
/* 0397FC 7F004C8C 00000000 */   nop   
/* 039800 7F004C90 AE430004 */  sw    $v1, 4($s2)
/* 039804 7F004C94 8C4B0010 */  lw    $t3, 0x10($v0)
/* 039808 7F004C98 02402025 */  move  $a0, $s2
/* 03980C 7F004C9C 0FC00644 */  jal   initSetLevelLoadPropSwitch
/* 039810 7F004CA0 AE4B0008 */   sw    $t3, 8($s2)
/* 039814 7F004CA4 8E0D0064 */  lw    $t5, 0x64($s0)
/* 039818 7F004CA8 35AC0001 */  ori   $t4, $t5, 1
/* 03981C 7F004CAC 10000051 */  b     .L7F004DF4
/* 039820 7F004CB0 AE0C0064 */   sw    $t4, 0x64($s0)
.L7F004CB4:
/* 039824 7F004CB4 8E420004 */  lw    $v0, 4($s2)
/* 039828 7F004CB8 8E4F000C */  lw    $t7, 0xc($s2)
/* 03982C 7F004CBC 8E510008 */  lw    $s1, 8($s2)
/* 039830 7F004CC0 02A02025 */  move  $a0, $s5
/* 039834 7F004CC4 02622821 */  addu  $a1, $s3, $v0
/* 039838 7F004CC8 0FC15CE8 */  jal   setupCommandGetObject
/* 03983C 7F004CCC AFAF0080 */   sw    $t7, 0x80($sp)
/* 039840 7F004CD0 00408025 */  move  $s0, $v0
/* 039844 7F004CD4 02A02025 */  move  $a0, $s5
/* 039848 7F004CD8 0FC15CE8 */  jal   setupCommandGetObject
/* 03984C 7F004CDC 02712821 */   addu  $a1, $s3, $s1
/* 039850 7F004CE0 8FAE0080 */  lw    $t6, 0x80($sp)
/* 039854 7F004CE4 00408825 */  move  $s1, $v0
/* 039858 7F004CE8 02A02025 */  move  $a0, $s5
/* 03985C 7F004CEC 0FC15CE8 */  jal   setupCommandGetObject
/* 039860 7F004CF0 026E2821 */   addu  $a1, $s3, $t6
/* 039864 7F004CF4 1200003F */  beqz  $s0, .L7F004DF4
/* 039868 7F004CF8 00000000 */   nop   
/* 03986C 7F004CFC 8E180010 */  lw    $t8, 0x10($s0)
/* 039870 7F004D00 1300003C */  beqz  $t8, .L7F004DF4
/* 039874 7F004D04 00000000 */   nop   
/* 039878 7F004D08 1220003A */  beqz  $s1, .L7F004DF4
/* 03987C 7F004D0C 00000000 */   nop   
/* 039880 7F004D10 8E280010 */  lw    $t0, 0x10($s1)
/* 039884 7F004D14 11000037 */  beqz  $t0, .L7F004DF4
/* 039888 7F004D18 00000000 */   nop   
/* 03988C 7F004D1C 92290003 */  lbu   $t1, 3($s1)
/* 039890 7F004D20 17C90034 */  bne   $fp, $t1, .L7F004DF4
/* 039894 7F004D24 00000000 */   nop   
/* 039898 7F004D28 10400032 */  beqz  $v0, .L7F004DF4
/* 03989C 7F004D2C 00000000 */   nop   
/* 0398A0 7F004D30 8C590010 */  lw    $t9, 0x10($v0)
/* 0398A4 7F004D34 1320002F */  beqz  $t9, .L7F004DF4
/* 0398A8 7F004D38 00000000 */   nop   
/* 0398AC 7F004D3C 904A0003 */  lbu   $t2, 3($v0)
/* 0398B0 7F004D40 02402025 */  move  $a0, $s2
/* 0398B4 7F004D44 168A002B */  bne   $s4, $t2, .L7F004DF4
/* 0398B8 7F004D48 00000000 */   nop   
/* 0398BC 7F004D4C AE500004 */  sw    $s0, 4($s2)
/* 0398C0 7F004D50 AE510008 */  sw    $s1, 8($s2)
/* 0398C4 7F004D54 AE42000C */  sw    $v0, 0xc($s2)
/* 0398C8 7F004D58 0FC00650 */  jal   initSetLevelLoadPropSafeItem
/* 0398CC 7F004D5C AFA20074 */   sw    $v0, 0x74($sp)
/* 0398D0 7F004D60 8E0B000C */  lw    $t3, 0xc($s0)
/* 0398D4 7F004D64 8FA30074 */  lw    $v1, 0x74($sp)
/* 0398D8 7F004D68 356D0400 */  ori   $t5, $t3, 0x400
/* 0398DC 7F004D6C AE0D000C */  sw    $t5, 0xc($s0)
/* 0398E0 7F004D70 8C6C000C */  lw    $t4, 0xc($v1)
/* 0398E4 7F004D74 358F0400 */  ori   $t7, $t4, 0x400
/* 0398E8 7F004D78 1000001E */  b     .L7F004DF4
/* 0398EC 7F004D7C AC6F000C */   sw    $t7, 0xc($v1)
.L7F004D80:
/* 0398F0 7F004D80 8E420004 */  lw    $v0, 4($s2)
/* 0398F4 7F004D84 8E510008 */  lw    $s1, 8($s2)
/* 0398F8 7F004D88 02A02025 */  move  $a0, $s5
/* 0398FC 7F004D8C 0FC15CE8 */  jal   setupCommandGetObject
/* 039900 7F004D90 02622821 */   addu  $a1, $s3, $v0
/* 039904 7F004D94 00408025 */  move  $s0, $v0
/* 039908 7F004D98 02A02025 */  move  $a0, $s5
/* 03990C 7F004D9C 0FC15CE8 */  jal   setupCommandGetObject
/* 039910 7F004DA0 02712821 */   addu  $a1, $s3, $s1
/* 039914 7F004DA4 12000013 */  beqz  $s0, .L7F004DF4
/* 039918 7F004DA8 00000000 */   nop   
/* 03991C 7F004DAC 8E0E0010 */  lw    $t6, 0x10($s0)
/* 039920 7F004DB0 11C00010 */  beqz  $t6, .L7F004DF4
/* 039924 7F004DB4 00000000 */   nop   
/* 039928 7F004DB8 1040000E */  beqz  $v0, .L7F004DF4
/* 03992C 7F004DBC 00000000 */   nop   
/* 039930 7F004DC0 8C580010 */  lw    $t8, 0x10($v0)
/* 039934 7F004DC4 1300000B */  beqz  $t8, .L7F004DF4
/* 039938 7F004DC8 00000000 */   nop   
/* 03993C 7F004DCC 92080003 */  lbu   $t0, 3($s0)
/* 039940 7F004DD0 02402025 */  move  $a0, $s2
/* 039944 7F004DD4 16880007 */  bne   $s4, $t0, .L7F004DF4
/* 039948 7F004DD8 00000000 */   nop   
/* 03994C 7F004DDC AE500004 */  sw    $s0, 4($s2)
/* 039950 7F004DE0 0FC0064A */  jal   initSetLevelLoadPropLockDoor
/* 039954 7F004DE4 AE420008 */   sw    $v0, 8($s2)
/* 039958 7F004DE8 8E090064 */  lw    $t1, 0x64($s0)
/* 03995C 7F004DEC 35392000 */  ori   $t9, $t1, 0x2000
/* 039960 7F004DF0 AE190064 */  sw    $t9, 0x64($s0)
.L7F004DF4:
/* 039964 7F004DF4 0FC15B7D */  jal   sizepropdef
/* 039968 7F004DF8 02402025 */   move  $a0, $s2
/* 03996C 7F004DFC 00025080 */  sll   $t2, $v0, 2
/* 039970 7F004E00 01529021 */  addu  $s2, $t2, $s2
/* 039974 7F004E04 92430003 */  lbu   $v1, 3($s2)
/* 039978 7F004E08 24010030 */  li    $at, 48
/* 03997C 7F004E0C 26730001 */  addiu $s3, $s3, 1
/* 039980 7F004E10 5461FF52 */  bnel  $v1, $at, .L7F004B5C
/* 039984 7F004E14 2469FFFD */   addiu $t1, $v1, -3
/* 039988 7F004E18 1000001B */  b     .L7F004E88
/* 03998C 7F004E1C 00000000 */   nop   
.L7F004E20:
/* 039990 7F004E20 3C018007 */  lui   $at, %hi(g_CurrentSetup+0) # $at, 0x8007
/* 039994 7F004E24 AC205D40 */  sw    $zero, %lo(g_CurrentSetup+0)($at)
/* 039998 7F004E28 3C018007 */  lui   $at, %hi(g_CurrentSetup+4) # $at, 0x8007
/* 03999C 7F004E2C AC205D44 */  sw    $zero, %lo(g_CurrentSetup+4)($at)
/* 0399A0 7F004E30 3C018007 */  lui   $at, %hi(g_CurrentSetup+8) # $at, 0x8007
/* 0399A4 7F004E34 AC205D48 */  sw    $zero, %lo(g_CurrentSetup+8)($at)
/* 0399A8 7F004E38 3C018007 */  lui   $at, %hi(g_CurrentSetup+0x0c) # $at, 0x8007
/* 0399AC 7F004E3C AC205D4C */  sw    $zero, %lo(g_CurrentSetup+0x0c)($at)
/* 0399B0 7F004E40 3C018007 */  lui   $at, %hi(g_CurrentSetup+0x10) # $at, 0x8007
/* 0399B4 7F004E44 AC205D50 */  sw    $zero, %lo(g_CurrentSetup+0x10)($at)
/* 0399B8 7F004E48 3C018007 */  lui   $at, %hi(g_CurrentSetup+0x14) # $at, 0x8007
/* 0399BC 7F004E4C AC205D54 */  sw    $zero, %lo(g_CurrentSetup+0x14)($at)
/* 0399C0 7F004E50 3C018007 */  lui   $at, %hi(g_CurrentSetup+0x18) # $at, 0x8007
/* 0399C4 7F004E54 AC205D58 */  sw    $zero, %lo(g_CurrentSetup+0x18)($at)
/* 0399C8 7F004E58 3C018007 */  lui   $at, %hi(g_CurrentSetup+0x1C) # $at, 0x8007
/* 0399CC 7F004E5C AC205D5C */  sw    $zero, %lo(g_CurrentSetup+0x1C)($at)
/* 0399D0 7F004E60 3C018007 */  lui   $at, %hi(g_CurrentSetup+0x20) # $at, 0x8007
/* 0399D4 7F004E64 AC205D60 */  sw    $zero, %lo(g_CurrentSetup+0x20)($at)
/* 0399D8 7F004E68 3C018007 */  lui   $at, %hi(g_CurrentSetup+0x24) # $at, 0x8007
/* 0399DC 7F004E6C AC205D64 */  sw    $zero, %lo(g_CurrentSetup+0x24)($at)
/* 0399E0 7F004E70 0FC003AE */  jal   alloc_init_GUARDdata_entries
/* 0399E4 7F004E74 00002025 */   move  $a0, $zero
/* 0399E8 7F004E78 0FC01558 */  jal   sub_GAME_7F005540
/* 0399EC 7F004E7C 00002025 */   move  $a0, $zero
/* 0399F0 7F004E80 0FC01591 */  jal   sub_GAME_7F005624
/* 0399F4 7F004E84 00002025 */   move  $a0, $zero
.L7F004E88:
/* 0399F8 7F004E88 0FC00417 */  jal   alloc_false_GUARDdata_to_exec_global_action
/* 0399FC 7F004E8C 00000000 */   nop   
/* 039A00 7F004E90 8FBF0044 */  lw    $ra, 0x44($sp)
/* 039A04 7F004E94 D7B40018 */  ldc1  $f20, 0x18($sp)
/* 039A08 7F004E98 8FB00020 */  lw    $s0, 0x20($sp)
/* 039A0C 7F004E9C 8FB10024 */  lw    $s1, 0x24($sp)
/* 039A10 7F004EA0 8FB20028 */  lw    $s2, 0x28($sp)
/* 039A14 7F004EA4 8FB3002C */  lw    $s3, 0x2c($sp)
/* 039A18 7F004EA8 8FB40030 */  lw    $s4, 0x30($sp)
/* 039A1C 7F004EAC 8FB50034 */  lw    $s5, 0x34($sp)
/* 039A20 7F004EB0 8FB60038 */  lw    $s6, 0x38($sp)
/* 039A24 7F004EB4 8FB7003C */  lw    $s7, 0x3c($sp)
/* 039A28 7F004EB8 8FBE0040 */  lw    $fp, 0x40($sp)
/* 039A2C 7F004EBC 03E00008 */  jr    $ra
/* 039A30 7F004EC0 27BD0280 */   addiu $sp, $sp, 0x280
 )
#endif

#ifdef VERSION_EU
 GLOBAL_ASM(
.late_rodata
glabel jpt_object_type_expansion
.word door_expand
.word door_scale_expand
.word obj_03_expand
.word key_expand
.word obj_03_expand
.word surv_camera_expand
.word obj_03_expand
.word item_expand
.word actor_expand
.word single_screen_display_expand
.word multi_screen_display_expand
.word rack_expand
.word autogun_expand
.word other_obj_expand
.word other_obj_expand
.word other_obj_expand
.word hat_expand
.word actor_attr_expand
.word other_obj_expand
.word ammo_box_expand
.word .L7F00454C
.word tag_expand
.word type17_objective_expand
.word other_obj_expand
.word other_obj_expand
.word other_obj_expand
.word other_obj_expand
.word other_obj_expand
.word other_obj_expand
.word type1E_subobjective_expand
.word other_obj_expand
.word type20_subobjective_expand
.word type21_subobjective_expand
.word other_obj_expand
.word type23_solo_brief_text
.word obj_03_expand
.word type25_rename
.word other_obj_expand
.word type27_wheeled_vehicle
.word type28_aircraft
.word obj_03_expand
.word obj_03_expand
.word obj_03_expand
.word other_obj_expand
.word type2D_tank
.word type2E_viewport_pos
.word type2F_tinted_glass

glabel D_8004F024
.word 0x40c90fdb
glabel D_8004F028
.word 0x3e4d35a8

glabel jpt_8004F02C
.word .L7F004B7C
.word .L7F004B7C
.word .L7F004DF4
.word .L7F004DF4
.word .L7F004B7C
.word .L7F004B7C
.word .L7F004DF4
.word .L7F004B7C
.word .L7F004DF4
.word .L7F004DF4
.word .L7F004DF4
.word .L7F004BE8
.word .L7F004DF4
.word .L7F004DF4
.word .L7F004DF4
.word .L7F004DF4
.word .L7F004C3C
.word .L7F004B7C
.word .L7F004B7C
.word .L7F004DF4
.word .L7F004DF4
.word .L7F004DF4
.word .L7F004DF4
.word .L7F004DF4
.word .L7F004DF4
.word .L7F004DF4
.word .L7F004DF4
.word .L7F004DF4
.word .L7F004DF4
.word .L7F004DF4
.word .L7F004DF4
.word .L7F004DF4
.word .L7F004DF4
.word .L7F004B7C
.word .L7F004DF4
.word .L7F004D80
.word .L7F004DF4
.word .L7F004DF4
.word .L7F004B7C
.word .L7F004B7C
.word .L7F004B7C
.word .L7F004CB4
.word .L7F004DF4
.word .L7F004DF4
.word .L7F004B7C


  .text
glabel proplvreset2
/* 03656C 7F003B7C 27BDFD80 */  addiu $sp, $sp, -0x280
/* 036570 7F003B80 AFB50034 */  sw    $s5, 0x34($sp)
/* 036574 7F003B84 0080A825 */  move  $s5, $a0
/* 036578 7F003B88 AFBF0044 */  sw    $ra, 0x44($sp)
/* 03657C 7F003B8C 3C058004 */  lui   $a1, %hi(aNochr) # $a1, 0x8004
/* 036580 7F003B90 AFBE0040 */  sw    $fp, 0x40($sp)
/* 036584 7F003B94 AFB7003C */  sw    $s7, 0x3c($sp)
/* 036588 7F003B98 AFB60038 */  sw    $s6, 0x38($sp)
/* 03658C 7F003B9C AFB40030 */  sw    $s4, 0x30($sp)
/* 036590 7F003BA0 AFB3002C */  sw    $s3, 0x2c($sp)
/* 036594 7F003BA4 AFB20028 */  sw    $s2, 0x28($sp)
/* 036598 7F003BA8 AFB10024 */  sw    $s1, 0x24($sp)
/* 03659C 7F003BAC AFB00020 */  sw    $s0, 0x20($sp)
/* 0365A0 7F003BB0 F7B40018 */  sdc1  $f20, 0x18($sp)
/* 0365A4 7F003BB4 24A571D0 */  addiu $a1, %lo(aNochr) # addiu $a1, $a1, 0x71d0
/* 0365A8 7F003BB8 0C0026C0 */  jal   tokenFind
/* 0365AC 7F003BBC 24040001 */   li    $a0, 1
/* 0365B0 7F003BC0 2C460001 */  sltiu $a2, $v0, 1
/* 0365B4 7F003BC4 10C00005 */  beqz  $a2, .L7F003BDC
/* 0365B8 7F003BC8 24040001 */   li    $a0, 1
/* 0365BC 7F003BCC 3C058004 */  lui   $a1, %hi(aNoprop) # $a1, 0x8004
/* 0365C0 7F003BD0 0C0026C0 */  jal   tokenFind
/* 0365C4 7F003BD4 24A571D8 */   addiu $a1, %lo(aNoprop) # addiu $a1, $a1, 0x71d8
/* 0365C8 7F003BD8 2C460001 */  sltiu $a2, $v0, 1
.L7F003BDC:
/* 0365CC 7F003BDC 3C058004 */  lui   $a1, %hi(aNoobj) # $a1, 0x8004
/* 0365D0 7F003BE0 AFA60278 */  sw    $a2, 0x278($sp)
/* 0365D4 7F003BE4 24A571E0 */  addiu $a1, %lo(aNoobj) # addiu $a1, $a1, 0x71e0
/* 0365D8 7F003BE8 0C0026C0 */  jal   tokenFind
/* 0365DC 7F003BEC 24040001 */   li    $a0, 1
/* 0365E0 7F003BF0 2C430001 */  sltiu $v1, $v0, 1
/* 0365E4 7F003BF4 10600005 */  beqz  $v1, .L7F003C0C
/* 0365E8 7F003BF8 24040001 */   li    $a0, 1
/* 0365EC 7F003BFC 3C058004 */  lui   $a1, %hi(aNoprop_0) # $a1, 0x8004
/* 0365F0 7F003C00 0C0026C0 */  jal   tokenFind
/* 0365F4 7F003C04 24A571E8 */   addiu $a1, %lo(aNoprop_0) # addiu $a1, $a1, 0x71e8
/* 0365F8 7F003C08 2C430001 */  sltiu $v1, $v0, 1
.L7F003C0C:
/* 0365FC 7F003C0C 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 036600 7F003C10 44812000 */  mtc1  $at, $f4
/* 036604 7F003C14 0060F025 */  move  $fp, $v1
/* 036608 7F003C18 3C018002 */  lui   $at, %hi(g_DoorScale) # $at, 0x8002
/* 03660C 7F003C1C 3C038003 */  lui   $v1, %hi(PitemZ_entries+0xFF0) # $v1, 0x8003
/* 036610 7F003C20 3C028003 */  lui   $v0, %hi(PitemZ_entries) # $v0, 0x8003
/* 036614 7F003C24 24424D88 */  addiu $v0, %lo(PitemZ_entries) # addiu $v0, $v0, 0x4d88
/* 036618 7F003C28 24635D78 */  addiu $v1, %lo(PitemZ_entries+0xFF0) # addiu $v1, $v1, 0x5d78
/* 03661C 7F003C2C E4245910 */  swc1  $f4, %lo(g_DoorScale)($at)
.L7F003C30:
/* 036620 7F003C30 8C4E0000 */  lw    $t6, ($v0)
/* 036624 7F003C34 2442000C */  addiu $v0, $v0, 0xc
/* 036628 7F003C38 0043082B */  sltu  $at, $v0, $v1
/* 03662C 7F003C3C 1420FFFC */  bnez  $at, .L7F003C30
/* 036630 7F003C40 ADC00000 */   sw    $zero, ($t6)
/* 036634 7F003C44 2AA1003B */  slti  $at, $s5, 0x3b
/* 036638 7F003C48 10200456 */  beqz  $at, .L7F004E20
/* 03663C 7F003C4C 00157880 */   sll   $t7, $s5, 2
/* 036640 7F003C50 3C188003 */  lui   $t8, %hi(setup_text_pointers) # $t8, 0x8003
/* 036644 7F003C54 27182594 */  addiu $t8, %lo(setup_text_pointers) # addiu $t8, $t8, 0x2594
/* 036648 7F003C58 01F88021 */  addu  $s0, $t7, $t8
/* 03664C 7F003C5C 8E020000 */  lw    $v0, ($s0)
/* 036650 7F003C60 3C198004 */  lui   $t9, %hi(only_read_by_stageload) # $t9, 0x8004
/* 036654 7F003C64 27B10174 */  addiu $s1, $sp, 0x174
/* 036658 7F003C68 1040044E */  beqz  $v0, .L7F004E20
/* 03665C 7F003C6C 273971F0 */   addiu $t9, %lo(only_read_by_stageload) # addiu $t9, $t9, 0x71f0
/* 036660 7F003C70 02205025 */  move  $t2, $s1
/* 036664 7F003C74 272900FC */  addiu $t1, $t9, 0xfc
.L7F003C78:
/* 036668 7F003C78 8F210000 */  lw    $at, ($t9)
/* 03666C 7F003C7C 2739000C */  addiu $t9, $t9, 0xc
/* 036670 7F003C80 254A000C */  addiu $t2, $t2, 0xc
/* 036674 7F003C84 AD41FFF4 */  sw    $at, -0xc($t2)
/* 036678 7F003C88 8F21FFF8 */  lw    $at, -8($t9)
/* 03667C 7F003C8C AD41FFF8 */  sw    $at, -8($t2)
/* 036680 7F003C90 8F21FFFC */  lw    $at, -4($t9)
/* 036684 7F003C94 1729FFF8 */  bne   $t9, $t1, .L7F003C78
/* 036688 7F003C98 AD41FFFC */   sw    $at, -4($t2)
/* 03668C 7F003C9C 8F210000 */  lw    $at, ($t9)
/* 036690 7F003CA0 0000A025 */  move  $s4, $zero
/* 036694 7F003CA4 00009825 */  move  $s3, $zero
/* 036698 7F003CA8 AD410000 */  sw    $at, ($t2)
/* 03669C 7F003CAC 904B0000 */  lbu   $t3, ($v0)
/* 0366A0 7F003CB0 A3A00175 */  sb    $zero, 0x175($sp)
/* 0366A4 7F003CB4 0FC26669 */  jal   getPlayerCount
/* 0366A8 7F003CB8 A3AB0174 */   sb    $t3, 0x174($sp)
/* 0366AC 7F003CBC 28410002 */  slti  $at, $v0, 2
/* 0366B0 7F003CC0 14200004 */  bnez  $at, .L7F003CD4
/* 0366B4 7F003CC4 3C058004 */   lui   $a1, %hi(aMp_) # $a1, 0x8004
/* 0366B8 7F003CC8 24A572F0 */  addiu $a1, %lo(aMp_) # addiu $a1, $a1, 0x72f0
/* 0366BC 7F003CCC 0C002717 */  jal   strcat
/* 0366C0 7F003CD0 02202025 */   move  $a0, $s1
.L7F003CD4:
/* 0366C4 7F003CD4 8E050000 */  lw    $a1, ($s0)
/* 0366C8 7F003CD8 02202025 */  move  $a0, $s1
/* 0366CC 7F003CDC 0C002717 */  jal   strcat
/* 0366D0 7F003CE0 24A50001 */   addiu $a1, $a1, 1
/* 0366D4 7F003CE4 02202025 */  move  $a0, $s1
/* 0366D8 7F003CE8 24050001 */  li    $a1, 1
/* 0366DC 7F003CEC 24060100 */  li    $a2, 256
/* 0366E0 7F003CF0 0FC2F053 */  jal   _fileNameLoadToBank
/* 0366E4 7F003CF4 24070004 */   li    $a3, 4
/* 0366E8 7F003CF8 3C038006 */  lui   $v1, %hi(g_ptrStageSetupFile) # $v1, 0x8006
/* 0366EC 7F003CFC 24634C68 */  addiu $v1, %lo(g_ptrStageSetupFile) # addiu $v1, $v1, 0x4c68
/* 0366F0 7F003D00 AC620000 */  sw    $v0, ($v1)
/* 0366F4 7F003D04 00408825 */  move  $s1, $v0
/* 0366F8 7F003D08 0FC302B0 */  jal   langGetLangBankIndexFromStagenum
/* 0366FC 7F003D0C 02A02025 */   move  $a0, $s5
/* 036700 7F003D10 0FC3047A */  jal   langLoadToAddr
/* 036704 7F003D14 00402025 */   move  $a0, $v0
/* 036708 7F003D18 8E2C0000 */  lw    $t4, ($s1)
/* 03670C 7F003D1C 3C078006 */  lui   $a3, %hi(g_CurrentSetup+0) # $a3, 0x8006
/* 036710 7F003D20 24E74C40 */  addiu $a3, %lo(g_CurrentSetup+0) # addiu $a3, $a3, 0x4c40
/* 036714 7F003D24 022C6821 */  addu  $t5, $s1, $t4
/* 036718 7F003D28 ACED0000 */  sw    $t5, ($a3)
/* 03671C 7F003D2C 8E2E0004 */  lw    $t6, 4($s1)
/* 036720 7F003D30 022E7821 */  addu  $t7, $s1, $t6
/* 036724 7F003D34 ACEF0004 */  sw    $t7, 4($a3)
/* 036728 7F003D38 8E380008 */  lw    $t8, 8($s1)
/* 03672C 7F003D3C 02384021 */  addu  $t0, $s1, $t8
/* 036730 7F003D40 ACE80008 */  sw    $t0, 8($a3)
/* 036734 7F003D44 8E29000C */  lw    $t1, 0xc($s1)
/* 036738 7F003D48 0229C821 */  addu  $t9, $s1, $t1
/* 03673C 7F003D4C ACF9000C */  sw    $t9, 0xc($a3)
/* 036740 7F003D50 8E2A0010 */  lw    $t2, 0x10($s1)
/* 036744 7F003D54 022A5821 */  addu  $t3, $s1, $t2
/* 036748 7F003D58 ACEB0010 */  sw    $t3, 0x10($a3)
/* 03674C 7F003D5C 8E2C0014 */  lw    $t4, 0x14($s1)
/* 036750 7F003D60 022C6821 */  addu  $t5, $s1, $t4
/* 036754 7F003D64 ACED0014 */  sw    $t5, 0x14($a3)
/* 036758 7F003D68 8E2E0018 */  lw    $t6, 0x18($s1)
/* 03675C 7F003D6C 022E7821 */  addu  $t7, $s1, $t6
/* 036760 7F003D70 ACEF0018 */  sw    $t7, 0x18($a3)
/* 036764 7F003D74 8E38001C */  lw    $t8, 0x1c($s1)
/* 036768 7F003D78 02384021 */  addu  $t0, $s1, $t8
/* 03676C 7F003D7C ACE8001C */  sw    $t0, 0x1c($a3)
/* 036770 7F003D80 8E220020 */  lw    $v0, 0x20($s1)
/* 036774 7F003D84 10400003 */  beqz  $v0, .L7F003D94
/* 036778 7F003D88 02224821 */   addu  $t1, $s1, $v0
/* 03677C 7F003D8C 10000002 */  b     .L7F003D98
/* 036780 7F003D90 ACE90020 */   sw    $t1, 0x20($a3)
.L7F003D94:
/* 036784 7F003D94 ACE00020 */  sw    $zero, 0x20($a3)
.L7F003D98:
/* 036788 7F003D98 8E220024 */  lw    $v0, 0x24($s1)
/* 03678C 7F003D9C 10400003 */  beqz  $v0, .L7F003DAC
/* 036790 7F003DA0 0222C821 */   addu  $t9, $s1, $v0
/* 036794 7F003DA4 10000002 */  b     .L7F003DB0
/* 036798 7F003DA8 ACF90024 */   sw    $t9, 0x24($a3)
.L7F003DAC:
/* 03679C 7F003DAC ACE00024 */  sw    $zero, 0x24($a3)
.L7F003DB0:
/* 0367A0 7F003DB0 8CE50000 */  lw    $a1, ($a3)
/* 0367A4 7F003DB4 50A00010 */  beql  $a1, $zero, .L7F003DF8
/* 0367A8 7F003DB8 8CE50004 */   lw    $a1, 4($a3)
/* 0367AC 7F003DBC 8CAA0000 */  lw    $t2, ($a1)
/* 0367B0 7F003DC0 00001825 */  move  $v1, $zero
/* 0367B4 7F003DC4 00A01025 */  move  $v0, $a1
/* 0367B8 7F003DC8 0542000B */  bltzl $t2, .L7F003DF8
/* 0367BC 7F003DCC 8CE50004 */   lw    $a1, 4($a3)
/* 0367C0 7F003DD0 8C4B0004 */  lw    $t3, 4($v0)
.L7F003DD4:
/* 0367C4 7F003DD4 24630010 */  addiu $v1, $v1, 0x10
/* 0367C8 7F003DD8 01716021 */  addu  $t4, $t3, $s1
/* 0367CC 7F003DDC AC4C0004 */  sw    $t4, 4($v0)
/* 0367D0 7F003DE0 8CED0000 */  lw    $t5, ($a3)
/* 0367D4 7F003DE4 01A31021 */  addu  $v0, $t5, $v1
/* 0367D8 7F003DE8 8C4E0000 */  lw    $t6, ($v0)
/* 0367DC 7F003DEC 05C3FFF9 */  bgezl $t6, .L7F003DD4
/* 0367E0 7F003DF0 8C4B0004 */   lw    $t3, 4($v0)
/* 0367E4 7F003DF4 8CE50004 */  lw    $a1, 4($a3)
.L7F003DF8:
/* 0367E8 7F003DF8 50A00015 */  beql  $a1, $zero, .L7F003E50
/* 0367EC 7F003DFC 8CE60014 */   lw    $a2, 0x14($a3)
/* 0367F0 7F003E00 8CAF0000 */  lw    $t7, ($a1)
/* 0367F4 7F003E04 00001825 */  move  $v1, $zero
/* 0367F8 7F003E08 00A01025 */  move  $v0, $a1
/* 0367FC 7F003E0C 51E00010 */  beql  $t7, $zero, .L7F003E50
/* 036800 7F003E10 8CE60014 */   lw    $a2, 0x14($a3)
/* 036804 7F003E14 8CA40000 */  lw    $a0, ($a1)
/* 036808 7F003E18 0091C021 */  addu  $t8, $a0, $s1
.L7F003E1C:
/* 03680C 7F003E1C AC580000 */  sw    $t8, ($v0)
/* 036810 7F003E20 8CE80004 */  lw    $t0, 4($a3)
/* 036814 7F003E24 01031021 */  addu  $v0, $t0, $v1
/* 036818 7F003E28 8C490004 */  lw    $t1, 4($v0)
/* 03681C 7F003E2C 2463000C */  addiu $v1, $v1, 0xc
/* 036820 7F003E30 0131C821 */  addu  $t9, $t1, $s1
/* 036824 7F003E34 AC590004 */  sw    $t9, 4($v0)
/* 036828 7F003E38 8CEA0004 */  lw    $t2, 4($a3)
/* 03682C 7F003E3C 01431021 */  addu  $v0, $t2, $v1
/* 036830 7F003E40 8C440000 */  lw    $a0, ($v0)
/* 036834 7F003E44 5480FFF5 */  bnezl $a0, .L7F003E1C
/* 036838 7F003E48 0091C021 */   addu  $t8, $a0, $s1
/* 03683C 7F003E4C 8CE60014 */  lw    $a2, 0x14($a3)
.L7F003E50:
/* 036840 7F003E50 50C00010 */  beql  $a2, $zero, .L7F003E94
/* 036844 7F003E54 8CE20010 */   lw    $v0, 0x10($a3)
/* 036848 7F003E58 8CCB0000 */  lw    $t3, ($a2)
/* 03684C 7F003E5C 00002825 */  move  $a1, $zero
/* 036850 7F003E60 00C01025 */  move  $v0, $a2
/* 036854 7F003E64 5160000B */  beql  $t3, $zero, .L7F003E94
/* 036858 7F003E68 8CE20010 */   lw    $v0, 0x10($a3)
/* 03685C 7F003E6C 8CC30000 */  lw    $v1, ($a2)
/* 036860 7F003E70 00716021 */  addu  $t4, $v1, $s1
.L7F003E74:
/* 036864 7F003E74 AC4C0000 */  sw    $t4, ($v0)
/* 036868 7F003E78 8CED0014 */  lw    $t5, 0x14($a3)
/* 03686C 7F003E7C 24A50008 */  addiu $a1, $a1, 8
/* 036870 7F003E80 01A51021 */  addu  $v0, $t5, $a1
/* 036874 7F003E84 8C430000 */  lw    $v1, ($v0)
/* 036878 7F003E88 5460FFFA */  bnezl $v1, .L7F003E74
/* 03687C 7F003E8C 00716021 */   addu  $t4, $v1, $s1
/* 036880 7F003E90 8CE20010 */  lw    $v0, 0x10($a3)
.L7F003E94:
/* 036884 7F003E94 50400020 */  beql  $v0, $zero, .L7F003F18
/* 036888 7F003E98 8CEA0018 */   lw    $t2, 0x18($a3)
/* 03688C 7F003E9C 8C4E0000 */  lw    $t6, ($v0)
/* 036890 7F003EA0 00002825 */  move  $a1, $zero
/* 036894 7F003EA4 00403025 */  move  $a2, $v0
/* 036898 7F003EA8 51C0001B */  beql  $t6, $zero, .L7F003F18
/* 03689C 7F003EAC 8CEA0018 */   lw    $t2, 0x18($a3)
/* 0368A0 7F003EB0 8C440000 */  lw    $a0, ($v0)
/* 0368A4 7F003EB4 00917821 */  addu  $t7, $a0, $s1
.L7F003EB8:
/* 0368A8 7F003EB8 ACCF0000 */  sw    $t7, ($a2)
/* 0368AC 7F003EBC 8CF80010 */  lw    $t8, 0x10($a3)
/* 0368B0 7F003EC0 00001825 */  move  $v1, $zero
/* 0368B4 7F003EC4 03053021 */  addu  $a2, $t8, $a1
/* 0368B8 7F003EC8 8CC40000 */  lw    $a0, ($a2)
/* 0368BC 7F003ECC 8C880000 */  lw    $t0, ($a0)
/* 0368C0 7F003ED0 00801025 */  move  $v0, $a0
/* 0368C4 7F003ED4 05020009 */  bltzl $t0, .L7F003EFC
/* 0368C8 7F003ED8 A4C30006 */   sh    $v1, 6($a2)
/* 0368CC 7F003EDC 8C490004 */  lw    $t1, 4($v0)
.L7F003EE0:
/* 0368D0 7F003EE0 24630001 */  addiu $v1, $v1, 1
/* 0368D4 7F003EE4 24420004 */  addiu $v0, $v0, 4
/* 0368D8 7F003EE8 0523FFFD */  bgezl $t1, .L7F003EE0
/* 0368DC 7F003EEC 8C490004 */   lw    $t1, 4($v0)
/* 0368E0 7F003EF0 3C078006 */  lui   $a3, %hi(g_CurrentSetup+0) # $a3, 0x8006
/* 0368E4 7F003EF4 24E74C40 */  addiu $a3, %lo(g_CurrentSetup+0) # addiu $a3, $a3, 0x4c40
/* 0368E8 7F003EF8 A4C30006 */  sh    $v1, 6($a2)
.L7F003EFC:
/* 0368EC 7F003EFC 8CF90010 */  lw    $t9, 0x10($a3)
/* 0368F0 7F003F00 24A50008 */  addiu $a1, $a1, 8
/* 0368F4 7F003F04 03253021 */  addu  $a2, $t9, $a1
/* 0368F8 7F003F08 8CC40000 */  lw    $a0, ($a2)
/* 0368FC 7F003F0C 5480FFEA */  bnezl $a0, .L7F003EB8
/* 036900 7F003F10 00917821 */   addu  $t7, $a0, $s1
/* 036904 7F003F14 8CEA0018 */  lw    $t2, 0x18($a3)
.L7F003F18:
/* 036908 7F003F18 1140001D */  beqz  $t2, .L7F003F90
/* 03690C 7F003F1C 00000000 */   nop   
/* 036910 7F003F20 0FC2CEDB */  jal   get_room_data_float2
/* 036914 7F003F24 00000000 */   nop   
/* 036918 7F003F28 3C108006 */  lui   $s0, %hi(g_CurrentSetup+0x18) # $s0, 0x8006
/* 03691C 7F003F2C 8E104C58 */  lw    $s0, %lo(g_CurrentSetup+0x18)($s0)
/* 036920 7F003F30 46000086 */  mov.s $f2, $f0
/* 036924 7F003F34 8E020024 */  lw    $v0, 0x24($s0)
/* 036928 7F003F38 10400015 */  beqz  $v0, .L7F003F90
/* 03692C 7F003F3C 00000000 */   nop   
/* 036930 7F003F40 C6060000 */  lwc1  $f6, ($s0)
.L7F003F44:
/* 036934 7F003F44 C60A0004 */  lwc1  $f10, 4($s0)
/* 036938 7F003F48 C6120008 */  lwc1  $f18, 8($s0)
/* 03693C 7F003F4C 46023202 */  mul.s $f8, $f6, $f2
/* 036940 7F003F50 02222821 */  addu  $a1, $s1, $v0
/* 036944 7F003F54 AE050024 */  sw    $a1, 0x24($s0)
/* 036948 7F003F58 46025402 */  mul.s $f16, $f10, $f2
/* 03694C 7F003F5C 02002025 */  move  $a0, $s0
/* 036950 7F003F60 26060028 */  addiu $a2, $s0, 0x28
/* 036954 7F003F64 46029102 */  mul.s $f4, $f18, $f2
/* 036958 7F003F68 E6080000 */  swc1  $f8, ($s0)
/* 03695C 7F003F6C E6100004 */  swc1  $f16, 4($s0)
/* 036960 7F003F70 E6040008 */  swc1  $f4, 8($s0)
/* 036964 7F003F74 0FC019D0 */  jal   init_pathtable_something
/* 036968 7F003F78 E7A2015C */   swc1  $f2, 0x15c($sp)
/* 03696C 7F003F7C 8E020050 */  lw    $v0, 0x50($s0)
/* 036970 7F003F80 2610002C */  addiu $s0, $s0, 0x2c
/* 036974 7F003F84 C7A2015C */  lwc1  $f2, 0x15c($sp)
/* 036978 7F003F88 5440FFEE */  bnezl $v0, .L7F003F44
/* 03697C 7F003F8C C6060000 */   lwc1  $f6, ($s0)
.L7F003F90:
/* 036980 7F003F90 3C078006 */  lui   $a3, %hi(g_CurrentSetup+0) # $a3, 0x8006
/* 036984 7F003F94 24E74C40 */  addiu $a3, %lo(g_CurrentSetup+0) # addiu $a3, $a3, 0x4c40
/* 036988 7F003F98 8CEC001C */  lw    $t4, 0x1c($a3)
/* 03698C 7F003F9C 51800033 */  beql  $t4, $zero, .L7F00406C
/* 036990 7F003FA0 8CE50020 */   lw    $a1, 0x20($a3)
/* 036994 7F003FA4 0FC2CEDB */  jal   get_room_data_float2
/* 036998 7F003FA8 00000000 */   nop   
/* 03699C 7F003FAC 3C078006 */  lui   $a3, %hi(g_CurrentSetup+0) # $a3, 0x8006
/* 0369A0 7F003FB0 24E74C40 */  addiu $a3, %lo(g_CurrentSetup+0) # addiu $a3, $a3, 0x4c40
/* 0369A4 7F003FB4 8CF0001C */  lw    $s0, 0x1c($a3)
/* 0369A8 7F003FB8 46000086 */  mov.s $f2, $f0
/* 0369AC 7F003FBC 8E020024 */  lw    $v0, 0x24($s0)
/* 0369B0 7F003FC0 5040002A */  beql  $v0, $zero, .L7F00406C
/* 0369B4 7F003FC4 8CE50020 */   lw    $a1, 0x20($a3)
/* 0369B8 7F003FC8 C6060000 */  lwc1  $f6, ($s0)
.L7F003FCC:
/* 0369BC 7F003FCC C60A0004 */  lwc1  $f10, 4($s0)
/* 0369C0 7F003FD0 C6120008 */  lwc1  $f18, 8($s0)
/* 0369C4 7F003FD4 46023202 */  mul.s $f8, $f6, $f2
/* 0369C8 7F003FD8 C606002C */  lwc1  $f6, 0x2c($s0)
/* 0369CC 7F003FDC 02222821 */  addu  $a1, $s1, $v0
/* 0369D0 7F003FE0 46025402 */  mul.s $f16, $f10, $f2
/* 0369D4 7F003FE4 C60A0030 */  lwc1  $f10, 0x30($s0)
/* 0369D8 7F003FE8 AE050024 */  sw    $a1, 0x24($s0)
/* 0369DC 7F003FEC 46029102 */  mul.s $f4, $f18, $f2
/* 0369E0 7F003FF0 E6080000 */  swc1  $f8, ($s0)
/* 0369E4 7F003FF4 C6120034 */  lwc1  $f18, 0x34($s0)
/* 0369E8 7F003FF8 46023202 */  mul.s $f8, $f6, $f2
/* 0369EC 7F003FFC E6100004 */  swc1  $f16, 4($s0)
/* 0369F0 7F004000 C6060038 */  lwc1  $f6, 0x38($s0)
/* 0369F4 7F004004 46025402 */  mul.s $f16, $f10, $f2
/* 0369F8 7F004008 E6040008 */  swc1  $f4, 8($s0)
/* 0369FC 7F00400C C60A003C */  lwc1  $f10, 0x3c($s0)
/* 036A00 7F004010 46029102 */  mul.s $f4, $f18, $f2
/* 036A04 7F004014 E608002C */  swc1  $f8, 0x2c($s0)
/* 036A08 7F004018 C6120040 */  lwc1  $f18, 0x40($s0)
/* 036A0C 7F00401C 46023202 */  mul.s $f8, $f6, $f2
/* 036A10 7F004020 E6100030 */  swc1  $f16, 0x30($s0)
/* 036A14 7F004024 02002025 */  move  $a0, $s0
/* 036A18 7F004028 46025402 */  mul.s $f16, $f10, $f2
/* 036A1C 7F00402C E6040034 */  swc1  $f4, 0x34($s0)
/* 036A20 7F004030 26060028 */  addiu $a2, $s0, 0x28
/* 036A24 7F004034 46029102 */  mul.s $f4, $f18, $f2
/* 036A28 7F004038 E6080038 */  swc1  $f8, 0x38($s0)
/* 036A2C 7F00403C E610003C */  swc1  $f16, 0x3c($s0)
/* 036A30 7F004040 E6040040 */  swc1  $f4, 0x40($s0)
/* 036A34 7F004044 0FC019D0 */  jal   init_pathtable_something
/* 036A38 7F004048 E7A20150 */   swc1  $f2, 0x150($sp)
/* 036A3C 7F00404C 8E020068 */  lw    $v0, 0x68($s0)
/* 036A40 7F004050 26100044 */  addiu $s0, $s0, 0x44
/* 036A44 7F004054 C7A20150 */  lwc1  $f2, 0x150($sp)
/* 036A48 7F004058 5440FFDC */  bnezl $v0, .L7F003FCC
/* 036A4C 7F00405C C6060000 */   lwc1  $f6, ($s0)
/* 036A50 7F004060 3C078006 */  lui   $a3, %hi(g_CurrentSetup+0) # $a3, 0x8006
/* 036A54 7F004064 24E74C40 */  addiu $a3, %lo(g_CurrentSetup+0) # addiu $a3, $a3, 0x4c40
/* 036A58 7F004068 8CE50020 */  lw    $a1, 0x20($a3)
.L7F00406C:
/* 036A5C 7F00406C 50A00010 */  beql  $a1, $zero, .L7F0040B0
/* 036A60 7F004070 8CE50024 */   lw    $a1, 0x24($a3)
/* 036A64 7F004074 8CAE0000 */  lw    $t6, ($a1)
/* 036A68 7F004078 00001025 */  move  $v0, $zero
/* 036A6C 7F00407C 00A01825 */  move  $v1, $a1
/* 036A70 7F004080 51C0000B */  beql  $t6, $zero, .L7F0040B0
/* 036A74 7F004084 8CE50024 */   lw    $a1, 0x24($a3)
/* 036A78 7F004088 8CA40000 */  lw    $a0, ($a1)
/* 036A7C 7F00408C 00917821 */  addu  $t7, $a0, $s1
.L7F004090:
/* 036A80 7F004090 AC6F0000 */  sw    $t7, ($v1)
/* 036A84 7F004094 8CF80020 */  lw    $t8, 0x20($a3)
/* 036A88 7F004098 24420004 */  addiu $v0, $v0, 4
/* 036A8C 7F00409C 03021821 */  addu  $v1, $t8, $v0
/* 036A90 7F0040A0 8C640000 */  lw    $a0, ($v1)
/* 036A94 7F0040A4 5480FFFA */  bnezl $a0, .L7F004090
/* 036A98 7F0040A8 00917821 */   addu  $t7, $a0, $s1
/* 036A9C 7F0040AC 8CE50024 */  lw    $a1, 0x24($a3)
.L7F0040B0:
/* 036AA0 7F0040B0 50A0000F */  beql  $a1, $zero, .L7F0040F0
/* 036AA4 7F0040B4 8FAA0278 */   lw    $t2, 0x278($sp)
/* 036AA8 7F0040B8 8CA80000 */  lw    $t0, ($a1)
/* 036AAC 7F0040BC 00001025 */  move  $v0, $zero
/* 036AB0 7F0040C0 00A01825 */  move  $v1, $a1
/* 036AB4 7F0040C4 11000009 */  beqz  $t0, .L7F0040EC
/* 036AB8 7F0040C8 01002025 */   move  $a0, $t0
/* 036ABC 7F0040CC 00914821 */  addu  $t1, $a0, $s1
.L7F0040D0:
/* 036AC0 7F0040D0 AC690000 */  sw    $t1, ($v1)
/* 036AC4 7F0040D4 8CF90024 */  lw    $t9, 0x24($a3)
/* 036AC8 7F0040D8 24420004 */  addiu $v0, $v0, 4
/* 036ACC 7F0040DC 03221821 */  addu  $v1, $t9, $v0
/* 036AD0 7F0040E0 8C640000 */  lw    $a0, ($v1)
/* 036AD4 7F0040E4 5480FFFA */  bnezl $a0, .L7F0040D0
/* 036AD8 7F0040E8 00914821 */   addu  $t1, $a0, $s1
.L7F0040EC:
/* 036ADC 7F0040EC 8FAA0278 */  lw    $t2, 0x278($sp)
.L7F0040F0:
/* 036AE0 7F0040F0 11400012 */  beqz  $t2, .L7F00413C
/* 036AE4 7F0040F4 00000000 */   nop   
/* 036AE8 7F0040F8 0FC006D4 */  jal   load_proptype
/* 036AEC 7F0040FC 24040009 */   li    $a0, 9
/* 036AF0 7F004100 0FC003AE */  jal   alloc_init_GUARDdata_entries
/* 036AF4 7F004104 00402025 */   move  $a0, $v0
/* 036AF8 7F004108 0FC006D4 */  jal   load_proptype
/* 036AFC 7F00410C 24040009 */   li    $a0, 9
/* 036B00 7F004110 0040A025 */  move  $s4, $v0
/* 036B04 7F004114 0FC006D4 */  jal   load_proptype
/* 036B08 7F004118 24040008 */   li    $a0, 8
/* 036B0C 7F00411C 00409825 */  move  $s3, $v0
/* 036B10 7F004120 0FC006D4 */  jal   load_proptype
/* 036B14 7F004124 24040004 */   li    $a0, 4
/* 036B18 7F004128 02629821 */  addu  $s3, $s3, $v0
/* 036B1C 7F00412C 0FC006D4 */  jal   load_proptype
/* 036B20 7F004130 24040011 */   li    $a0, 17
/* 036B24 7F004134 10000003 */  b     .L7F004144
/* 036B28 7F004138 02629821 */   addu  $s3, $s3, $v0
.L7F00413C:
/* 036B2C 7F00413C 0FC003AE */  jal   alloc_init_GUARDdata_entries
/* 036B30 7F004140 00002025 */   move  $a0, $zero
.L7F004144:
/* 036B34 7F004144 13C0003A */  beqz  $fp, .L7F004230
/* 036B38 7F004148 00000000 */   nop   
/* 036B3C 7F00414C 0FC006D4 */  jal   load_proptype
/* 036B40 7F004150 24040001 */   li    $a0, 1
/* 036B44 7F004154 02629821 */  addu  $s3, $s3, $v0
/* 036B48 7F004158 0FC006D4 */  jal   load_proptype
/* 036B4C 7F00415C 24040006 */   li    $a0, 6
/* 036B50 7F004160 02629821 */  addu  $s3, $s3, $v0
/* 036B54 7F004164 0FC006D4 */  jal   load_proptype
/* 036B58 7F004168 2404000D */   li    $a0, 13
/* 036B5C 7F00416C 02629821 */  addu  $s3, $s3, $v0
/* 036B60 7F004170 0FC006D4 */  jal   load_proptype
/* 036B64 7F004174 2404000C */   li    $a0, 12
/* 036B68 7F004178 02629821 */  addu  $s3, $s3, $v0
/* 036B6C 7F00417C 0FC006D4 */  jal   load_proptype
/* 036B70 7F004180 2404000A */   li    $a0, 10
/* 036B74 7F004184 02629821 */  addu  $s3, $s3, $v0
/* 036B78 7F004188 0FC006D4 */  jal   load_proptype
/* 036B7C 7F00418C 2404000B */   li    $a0, 11
/* 036B80 7F004190 02629821 */  addu  $s3, $s3, $v0
/* 036B84 7F004194 0FC006D4 */  jal   load_proptype
/* 036B88 7F004198 24040015 */   li    $a0, 21
/* 036B8C 7F00419C 02629821 */  addu  $s3, $s3, $v0
/* 036B90 7F0041A0 0FC006D4 */  jal   load_proptype
/* 036B94 7F0041A4 24040003 */   li    $a0, 3
/* 036B98 7F0041A8 02629821 */  addu  $s3, $s3, $v0
/* 036B9C 7F0041AC 0FC006D4 */  jal   load_proptype
/* 036BA0 7F0041B0 2404002A */   li    $a0, 42
/* 036BA4 7F0041B4 02629821 */  addu  $s3, $s3, $v0
/* 036BA8 7F0041B8 0FC006D4 */  jal   load_proptype
/* 036BAC 7F0041BC 2404002F */   li    $a0, 47
/* 036BB0 7F0041C0 02629821 */  addu  $s3, $s3, $v0
/* 036BB4 7F0041C4 0FC006D4 */  jal   load_proptype
/* 036BB8 7F0041C8 2404002B */   li    $a0, 43
/* 036BBC 7F0041CC 02629821 */  addu  $s3, $s3, $v0
/* 036BC0 7F0041D0 0FC006D4 */  jal   load_proptype
/* 036BC4 7F0041D4 24040029 */   li    $a0, 41
/* 036BC8 7F0041D8 02629821 */  addu  $s3, $s3, $v0
/* 036BCC 7F0041DC 0FC006D4 */  jal   load_proptype
/* 036BD0 7F0041E0 24040024 */   li    $a0, 36
/* 036BD4 7F0041E4 02629821 */  addu  $s3, $s3, $v0
/* 036BD8 7F0041E8 0FC006D4 */  jal   load_proptype
/* 036BDC 7F0041EC 24040005 */   li    $a0, 5
/* 036BE0 7F0041F0 02629821 */  addu  $s3, $s3, $v0
/* 036BE4 7F0041F4 0FC006D4 */  jal   load_proptype
/* 036BE8 7F0041F8 24040007 */   li    $a0, 7
/* 036BEC 7F0041FC 02629821 */  addu  $s3, $s3, $v0
/* 036BF0 7F004200 0FC006D4 */  jal   load_proptype
/* 036BF4 7F004204 24040014 */   li    $a0, 20
/* 036BF8 7F004208 02629821 */  addu  $s3, $s3, $v0
/* 036BFC 7F00420C 0FC006D4 */  jal   load_proptype
/* 036C00 7F004210 24040027 */   li    $a0, 39
/* 036C04 7F004214 02629821 */  addu  $s3, $s3, $v0
/* 036C08 7F004218 0FC006D4 */  jal   load_proptype
/* 036C0C 7F00421C 2404002D */   li    $a0, 45
/* 036C10 7F004220 02629821 */  addu  $s3, $s3, $v0
/* 036C14 7F004224 0FC006D4 */  jal   load_proptype
/* 036C18 7F004228 24040028 */   li    $a0, 40
/* 036C1C 7F00422C 0282A021 */  addu  $s4, $s4, $v0
.L7F004230:
/* 036C20 7F004230 0FC01538 */  jal   sub_GAME_7F005540
/* 036C24 7F004234 02602025 */   move  $a0, $s3
/* 036C28 7F004238 0FC01571 */  jal   sub_GAME_7F005624
/* 036C2C 7F00423C 02802025 */   move  $a0, $s4
/* 036C30 7F004240 0FC26669 */  jal   getPlayerCount
/* 036C34 7F004244 00008025 */   move  $s0, $zero
/* 036C38 7F004248 1840000C */  blez  $v0, .L7F00427C
/* 036C3C 7F00424C 00000000 */   nop   
.L7F004250:
/* 036C40 7F004250 0FC26993 */  jal   set_cur_player
/* 036C44 7F004254 02002025 */   move  $a0, $s0
/* 036C48 7F004258 0FC006D4 */  jal   load_proptype
/* 036C4C 7F00425C 2404000E */   li    $a0, 14
/* 036C50 7F004260 0FC01877 */  jal   alloc_additional_item_slots
/* 036C54 7F004264 00402025 */   move  $a0, $v0
/* 036C58 7F004268 0FC26669 */  jal   getPlayerCount
/* 036C5C 7F00426C 26100001 */   addiu $s0, $s0, 1
/* 036C60 7F004270 0202082A */  slt   $at, $s0, $v0
/* 036C64 7F004274 1420FFF6 */  bnez  $at, .L7F004250
/* 036C68 7F004278 00000000 */   nop   
.L7F00427C:
/* 036C6C 7F00427C 3C0B8006 */  lui   $t3, %hi(g_CurrentSetup+0x0c) # $t3, 0x8006
/* 036C70 7F004280 8D6B4C4C */  lw    $t3, %lo(g_CurrentSetup+0x0c)($t3)
/* 036C74 7F004284 116002E1 */  beqz  $t3, .L7F004E88
/* 036C78 7F004288 00000000 */   nop   
/* 036C7C 7F00428C 0FC2FC21 */  jal   lvlGetSelectedDifficulty
/* 036C80 7F004290 00000000 */   nop   
/* 036C84 7F004294 244C0004 */  addiu $t4, $v0, 4
/* 036C88 7F004298 240D0001 */  li    $t5, 1
/* 036C8C 7F00429C 0FC26669 */  jal   getPlayerCount
/* 036C90 7F0042A0 018DA004 */   sllv  $s4, $t5, $t4
/* 036C94 7F0042A4 28410002 */  slti  $at, $v0, 2
/* 036C98 7F0042A8 14200007 */  bnez  $at, .L7F0042C8
/* 036C9C 7F0042AC 00000000 */   nop   
/* 036CA0 7F0042B0 0FC26669 */  jal   getPlayerCount
/* 036CA4 7F0042B4 00000000 */   nop   
/* 036CA8 7F0042B8 244E0014 */  addiu $t6, $v0, 0x14
/* 036CAC 7F0042BC 240F0001 */  li    $t7, 1
/* 036CB0 7F0042C0 01CFC004 */  sllv  $t8, $t7, $t6
/* 036CB4 7F0042C4 0298A025 */  or    $s4, $s4, $t8
.L7F0042C8:
/* 036CB8 7F0042C8 3C128006 */  lui   $s2, %hi(g_CurrentSetup+0x0c) # $s2, 0x8006
/* 036CBC 7F0042CC 8E524C4C */  lw    $s2, %lo(g_CurrentSetup+0x0c)($s2)
/* 036CC0 7F0042D0 24010030 */  li    $at, 48
/* 036CC4 7F0042D4 00009825 */  move  $s3, $zero
/* 036CC8 7F0042D8 92430003 */  lbu   $v1, 3($s2)
/* 036CCC 7F0042DC 24170034 */  li    $s7, 52
/* 036CD0 7F0042E0 506101F8 */  beql  $v1, $at, .L7F004B40
/* 036CD4 7F0042E4 92430003 */   lbu   $v1, 3($s2)
/* 036CD8 7F0042E8 4480A000 */  mtc1  $zero, $f20
/* 036CDC 7F0042EC 3416FFFF */  li    $s6, 65535
/* 036CE0 7F0042F0 2468FFFF */  addiu $t0, $v1, -1
.L7F0042F4:
/* 036CE4 7F0042F4 2D01002F */  sltiu $at, $t0, 0x2f
/* 036CE8 7F0042F8 102001E5 */  beqz  $at, other_obj_expand
/* 036CEC 7F0042FC 00084080 */   sll   $t0, $t0, 2
/* 036CF0 7F004300 3C018004 */  lui   $at, %hi(jpt_object_type_expansion)
/* 036CF4 7F004304 00280821 */  addu  $at, $at, $t0
/* 036CF8 7F004308 8C2873B0 */  lw    $t0, %lo(jpt_object_type_expansion)($at)
/* 036CFC 7F00430C 01000008 */  jr    $t0
/* 036D00 7F004310 00000000 */   nop   
actor_attr_expand:
/* 036D04 7F004314 9250000B */  lbu   $s0, 0xb($s2)
/* 036D08 7F004318 0FC08BE4 */  jal   chrFindByLiteralId
/* 036D0C 7F00431C 8E440004 */   lw    $a0, 4($s2)
/* 036D10 7F004320 104001DB */  beqz  $v0, other_obj_expand
/* 036D14 7F004324 00000000 */   nop   
/* 036D18 7F004328 8C490018 */  lw    $t1, 0x18($v0)
/* 036D1C 7F00432C 112001D8 */  beqz  $t1, other_obj_expand
/* 036D20 7F004330 00000000 */   nop   
/* 036D24 7F004334 8C59001C */  lw    $t9, 0x1c($v0)
/* 036D28 7F004338 132001D5 */  beqz  $t9, other_obj_expand
/* 036D2C 7F00433C 00000000 */   nop   
/* 036D30 7F004340 100001D3 */  b     other_obj_expand
/* 036D34 7F004344 A0500010 */   sb    $s0, 0x10($v0)
actor_expand:
/* 036D38 7F004348 8FAA0278 */  lw    $t2, 0x278($sp)
/* 036D3C 7F00434C 02A02025 */  move  $a0, $s5
/* 036D40 7F004350 02402825 */  move  $a1, $s2
/* 036D44 7F004354 114001CE */  beqz  $t2, other_obj_expand
/* 036D48 7F004358 00000000 */   nop   
/* 036D4C 7F00435C 0FC08DBB */  jal   expand_09_characters
/* 036D50 7F004360 02603025 */   move  $a2, $s3
/* 036D54 7F004364 100001CA */  b     other_obj_expand
/* 036D58 7F004368 00000000 */   nop   
door_expand:
/* 036D5C 7F00436C 13C001C8 */  beqz  $fp, other_obj_expand
/* 036D60 7F004370 00000000 */   nop   
/* 036D64 7F004374 8E4B000C */  lw    $t3, 0xc($s2)
/* 036D68 7F004378 02A02025 */  move  $a0, $s5
/* 036D6C 7F00437C 02402825 */  move  $a1, $s2
/* 036D70 7F004380 01746824 */  and   $t5, $t3, $s4
/* 036D74 7F004384 15A001C2 */  bnez  $t5, other_obj_expand
/* 036D78 7F004388 00000000 */   nop   
/* 036D7C 7F00438C 0FC00CFC */  jal   setupDoor
/* 036D80 7F004390 02603025 */   move  $a2, $s3
/* 036D84 7F004394 100001BE */  b     other_obj_expand
/* 036D88 7F004398 00000000 */   nop   
door_scale_expand:
/* 036D8C 7F00439C 8E4C0004 */  lw    $t4, 4($s2)
/* 036D90 7F0043A0 3C014780 */  li    $at, 0x47800000 # 65536.000000
/* 036D94 7F0043A4 44815000 */  mtc1  $at, $f10
/* 036D98 7F0043A8 448C3000 */  mtc1  $t4, $f6
/* 036D9C 7F0043AC 3C018002 */  lui   $at, %hi(g_DoorScale) # $at, 0x8002
/* 036DA0 7F0043B0 46803220 */  cvt.s.w $f8, $f6
/* 036DA4 7F0043B4 460A4403 */  div.s $f16, $f8, $f10
/* 036DA8 7F0043B8 100001B5 */  b     other_obj_expand
/* 036DAC 7F0043BC E4305910 */   swc1  $f16, %lo(g_DoorScale)($at)
item_expand:
/* 036DB0 7F0043C0 8FAF0278 */  lw    $t7, 0x278($sp)
/* 036DB4 7F0043C4 11E001B2 */  beqz  $t7, other_obj_expand
/* 036DB8 7F0043C8 00000000 */   nop   
/* 036DBC 7F0043CC 8E4E000C */  lw    $t6, 0xc($s2)
/* 036DC0 7F0043D0 02A02025 */  move  $a0, $s5
/* 036DC4 7F0043D4 02402825 */  move  $a1, $s2
/* 036DC8 7F0043D8 01D4C024 */  and   $t8, $t6, $s4
/* 036DCC 7F0043DC 170001AC */  bnez  $t8, other_obj_expand
/* 036DD0 7F0043E0 00000000 */   nop   
/* 036DD4 7F0043E4 0FC009CE */  jal   weaponAssignToHome
/* 036DD8 7F0043E8 02603025 */   move  $a2, $s3
/* 036DDC 7F0043EC 100001A8 */  b     other_obj_expand
/* 036DE0 7F0043F0 00000000 */   nop   
key_expand:
/* 036DE4 7F0043F4 8FA80278 */  lw    $t0, 0x278($sp)
/* 036DE8 7F0043F8 110001A5 */  beqz  $t0, other_obj_expand
/* 036DEC 7F0043FC 00000000 */   nop   
/* 036DF0 7F004400 8E49000C */  lw    $t1, 0xc($s2)
/* 036DF4 7F004404 02A02025 */  move  $a0, $s5
/* 036DF8 7F004408 02402825 */  move  $a1, $s2
/* 036DFC 7F00440C 0134C824 */  and   $t9, $t1, $s4
/* 036E00 7F004410 1720019F */  bnez  $t9, other_obj_expand
/* 036E04 7F004414 00000000 */   nop   
/* 036E08 7F004418 0FC00A61 */  jal   setupKey
/* 036E0C 7F00441C 02603025 */   move  $a2, $s3
/* 036E10 7F004420 1000019B */  b     other_obj_expand
/* 036E14 7F004424 00000000 */   nop   
hat_expand:
/* 036E18 7F004428 8FAA0278 */  lw    $t2, 0x278($sp)
/* 036E1C 7F00442C 11400198 */  beqz  $t2, other_obj_expand
/* 036E20 7F004430 00000000 */   nop   
/* 036E24 7F004434 8E4B000C */  lw    $t3, 0xc($s2)
/* 036E28 7F004438 02A02025 */  move  $a0, $s5
/* 036E2C 7F00443C 02402825 */  move  $a1, $s2
/* 036E30 7F004440 01746824 */  and   $t5, $t3, $s4
/* 036E34 7F004444 15A00192 */  bnez  $t5, other_obj_expand
/* 036E38 7F004448 00000000 */   nop   
/* 036E3C 7F00444C 0FC00A44 */  jal   setupHat
/* 036E40 7F004450 02603025 */   move  $a2, $s3
/* 036E44 7F004454 1000018E */  b     other_obj_expand
/* 036E48 7F004458 00000000 */   nop   
surv_camera_expand:
/* 036E4C 7F00445C 13C0018C */  beqz  $fp, other_obj_expand
/* 036E50 7F004460 00000000 */   nop   
/* 036E54 7F004464 8E4C000C */  lw    $t4, 0xc($s2)
/* 036E58 7F004468 02A02025 */  move  $a0, $s5
/* 036E5C 7F00446C 02402825 */  move  $a1, $s2
/* 036E60 7F004470 01947824 */  and   $t7, $t4, $s4
/* 036E64 7F004474 15E00186 */  bnez  $t7, other_obj_expand
/* 036E68 7F004478 00000000 */   nop   
/* 036E6C 7F00447C 0FC00A69 */  jal   setupCctv
/* 036E70 7F004480 02603025 */   move  $a2, $s3
/* 036E74 7F004484 10000182 */  b     other_obj_expand
/* 036E78 7F004488 00000000 */   nop   
autogun_expand:
/* 036E7C 7F00448C 13C00180 */  beqz  $fp, other_obj_expand
/* 036E80 7F004490 00000000 */   nop   
/* 036E84 7F004494 8E4E000C */  lw    $t6, 0xc($s2)
/* 036E88 7F004498 02A02025 */  move  $a0, $s5
/* 036E8C 7F00449C 02402825 */  move  $a1, $s2
/* 036E90 7F0044A0 01D4C024 */  and   $t8, $t6, $s4
/* 036E94 7F0044A4 1700017A */  bnez  $t8, other_obj_expand
/* 036E98 7F0044A8 00000000 */   nop   
/* 036E9C 7F0044AC 0FC00AF0 */  jal   setupAutogun
/* 036EA0 7F0044B0 02603025 */   move  $a2, $s3
/* 036EA4 7F0044B4 10000176 */  b     other_obj_expand
/* 036EA8 7F0044B8 00000000 */   nop   
rack_expand:
/* 036EAC 7F0044BC 13C00174 */  beqz  $fp, other_obj_expand
/* 036EB0 7F0044C0 00000000 */   nop   
/* 036EB4 7F0044C4 8E48000C */  lw    $t0, 0xc($s2)
/* 036EB8 7F0044C8 02A02025 */  move  $a0, $s5
/* 036EBC 7F0044CC 02402825 */  move  $a1, $s2
/* 036EC0 7F0044D0 01144824 */  and   $t1, $t0, $s4
/* 036EC4 7F0044D4 1520016E */  bnez  $t1, other_obj_expand
/* 036EC8 7F0044D8 00000000 */   nop   
/* 036ECC 7F0044DC 0FC00B63 */  jal   setupHangingMonitors
/* 036ED0 7F0044E0 02603025 */   move  $a2, $s3
/* 036ED4 7F0044E4 1000016A */  b     other_obj_expand
/* 036ED8 7F0044E8 00000000 */   nop   
single_screen_display_expand:
/* 036EDC 7F0044EC 13C00168 */  beqz  $fp, other_obj_expand
/* 036EE0 7F0044F0 00000000 */   nop   
/* 036EE4 7F0044F4 8E59000C */  lw    $t9, 0xc($s2)
/* 036EE8 7F0044F8 02A02025 */  move  $a0, $s5
/* 036EEC 7F0044FC 02402825 */  move  $a1, $s2
/* 036EF0 7F004500 03345024 */  and   $t2, $t9, $s4
/* 036EF4 7F004504 15400162 */  bnez  $t2, other_obj_expand
/* 036EF8 7F004508 00000000 */   nop   
/* 036EFC 7F00450C 0FC00B6B */  jal   setupSingleMonitor
/* 036F00 7F004510 02603025 */   move  $a2, $s3
/* 036F04 7F004514 1000015E */  b     other_obj_expand
/* 036F08 7F004518 00000000 */   nop   
multi_screen_display_expand:
/* 036F0C 7F00451C 13C0015C */  beqz  $fp, other_obj_expand
/* 036F10 7F004520 00000000 */   nop   
/* 036F14 7F004524 8E4B000C */  lw    $t3, 0xc($s2)
/* 036F18 7F004528 02A02025 */  move  $a0, $s5
/* 036F1C 7F00452C 02402825 */  move  $a1, $s2
/* 036F20 7F004530 01746824 */  and   $t5, $t3, $s4
/* 036F24 7F004534 15A00156 */  bnez  $t5, other_obj_expand
/* 036F28 7F004538 00000000 */   nop   
/* 036F2C 7F00453C 0FC00C10 */  jal   setupMultiMonitor
/* 036F30 7F004540 02603025 */   move  $a2, $s3
/* 036F34 7F004544 10000152 */  b     other_obj_expand
/* 036F38 7F004548 00000000 */   nop   
.L7F00454C:
/* 036F3C 7F00454C 13C00150 */  beqz  $fp, other_obj_expand
/* 036F40 7F004550 00000000 */   nop   
body_armor_expand:
/* 036F44 7F004554 8E4C000C */  lw    $t4, 0xc($s2)
/* 036F48 7F004558 3C0E8004 */  lui   $t6, %hi(j_text_trigger) # $t6, 0x8004
/* 036F4C 7F00455C 01947824 */  and   $t7, $t4, $s4
/* 036F50 7F004560 51E00005 */  beql  $t7, $zero, .L7F0045EC
/* 036F54 7F004564 8E580080 */   lw    $t8, 0x80($s2)
/* 036F58 7F004568 8DCE1150 */  lw    $t6, %lo(j_text_trigger)($t6)
/* 036F5C 7F00456C 11C00148 */  beqz  $t6, other_obj_expand
/* 036F60 7F004570 00000000 */   nop   
/* 036F64 7F004574 8E580080 */  lw    $t8, 0x80($s2)
.L7F0045EC:
/* 036F68 7F004578 3C014780 */  li    $at, 0x47800000 # 65536.000000
/* 036F6C 7F00457C 44813000 */  mtc1  $at, $f6
/* 036F70 7F004580 44989000 */  mtc1  $t8, $f18
/* 036F74 7F004584 02A02025 */  move  $a0, $s5
/* 036F78 7F004588 02402825 */  move  $a1, $s2
/* 036F7C 7F00458C 46809120 */  cvt.s.w $f4, $f18
/* 036F80 7F004590 02603025 */  move  $a2, $s3
/* 036F84 7F004594 46062203 */  div.s $f8, $f4, $f6
/* 036F88 7F004598 E6480080 */  swc1  $f8, 0x80($s2)
/* 036F8C 7F00459C C64A0080 */  lwc1  $f10, 0x80($s2)
/* 036F90 7F0045A0 0FC00767 */  jal   domakedefaultobj
/* 036F94 7F0045A4 E64A0084 */   swc1  $f10, 0x84($s2)
/* 036F98 7F0045A8 10000139 */  b     other_obj_expand
/* 036F9C 7F0045AC 00000000 */   nop   
type2F_tinted_glass:
/* 036FA0 7F0045B0 13C00137 */  beqz  $fp, other_obj_expand
/* 036FA4 7F0045B4 00000000 */   nop   
/* 036FA8 7F0045B8 8E48000C */  lw    $t0, 0xc($s2)
/* 036FAC 7F0045BC 01144824 */  and   $t1, $t0, $s4
/* 036FB0 7F0045C0 15200133 */  bnez  $t1, other_obj_expand
/* 036FB4 7F0045C4 00000000 */   nop   
/* 036FB8 7F0045C8 8E590008 */  lw    $t9, 8($s2)
/* 036FBC 7F0045CC 001950C0 */  sll   $t2, $t9, 3
/* 036FC0 7F0045D0 05430039 */  bgezl $t2, .L7F0046B8
/* 036FC4 7F0045D4 02A02025 */   move  $a0, $s5
/* 036FC8 7F0045D8 86420006 */  lh    $v0, 6($s2)
/* 036FCC 7F0045DC 3C0D8006 */  lui   $t5, %hi(g_CurrentSetup+0x1C) # $t5, 0x8006
/* 036FD0 7F0045E0 27A50118 */  addiu $a1, $sp, 0x118
/* 036FD4 7F0045E4 28412710 */  slti  $at, $v0, 0x2710
/* 036FD8 7F0045E8 14200032 */  bnez  $at, .L7F0046B4
/* 036FDC 7F0045EC 00025900 */   sll   $t3, $v0, 4
/* 036FE0 7F0045F0 8DAD4C5C */  lw    $t5, %lo(g_CurrentSetup+0x1C)($t5)
/* 036FE4 7F0045F4 01625821 */  addu  $t3, $t3, $v0
/* 036FE8 7F0045F8 000B5880 */  sll   $t3, $t3, 2
/* 036FEC 7F0045FC 3C01FFF5 */  lui   $at, (0xFFF59FC0 >> 16) # lui $at, 0xfff5
/* 036FF0 7F004600 34219FC0 */  ori   $at, (0xFFF59FC0 & 0xFFFF) # ori $at, $at, 0x9fc0
/* 036FF4 7F004604 016D8021 */  addu  $s0, $t3, $t5
/* 036FF8 7F004608 02018021 */  addu  $s0, $s0, $at
/* 036FFC 7F00460C 0FC006F5 */  jal   sub_GAME_7F001BD4
/* 037000 7F004610 02002025 */   move  $a0, $s0
/* 037004 7F004614 3C014120 */  li    $at, 0x41200000 # 10.000000
/* 037008 7F004618 44810000 */  mtc1  $at, $f0
/* 03700C 7F00461C C610000C */  lwc1  $f16, 0xc($s0)
/* 037010 7F004620 C7A40118 */  lwc1  $f4, 0x118($sp)
/* 037014 7F004624 27A40118 */  addiu $a0, $sp, 0x118
/* 037018 7F004628 46008482 */  mul.s $f18, $f16, $f0
/* 03701C 7F00462C C7B0011C */  lwc1  $f16, 0x11c($sp)
/* 037020 7F004630 27A5010C */  addiu $a1, $sp, 0x10c
/* 037024 7F004634 46049180 */  add.s $f6, $f18, $f4
/* 037028 7F004638 E7A6010C */  swc1  $f6, 0x10c($sp)
/* 03702C 7F00463C C6080010 */  lwc1  $f8, 0x10($s0)
/* 037030 7F004640 46004282 */  mul.s $f10, $f8, $f0
/* 037034 7F004644 46105480 */  add.s $f18, $f10, $f16
/* 037038 7F004648 C7AA0120 */  lwc1  $f10, 0x120($sp)
/* 03703C 7F00464C E7B20110 */  swc1  $f18, 0x110($sp)
/* 037040 7F004650 C6060014 */  lwc1  $f6, 0x14($s0)
/* 037044 7F004654 46003202 */  mul.s $f8, $f6, $f0
/* 037048 7F004658 460A4480 */  add.s $f18, $f8, $f10
/* 03704C 7F00465C E7B20114 */  swc1  $f18, 0x114($sp)
/* 037050 7F004660 C606000C */  lwc1  $f6, 0xc($s0)
/* 037054 7F004664 46060202 */  mul.s $f8, $f0, $f6
/* 037058 7F004668 46082481 */  sub.s $f18, $f4, $f8
/* 03705C 7F00466C E7B20118 */  swc1  $f18, 0x118($sp)
/* 037060 7F004670 C6060010 */  lwc1  $f6, 0x10($s0)
/* 037064 7F004674 46060102 */  mul.s $f4, $f0, $f6
/* 037068 7F004678 46048201 */  sub.s $f8, $f16, $f4
/* 03706C 7F00467C E7A8011C */  swc1  $f8, 0x11c($sp)
/* 037070 7F004680 C6120014 */  lwc1  $f18, 0x14($s0)
/* 037074 7F004684 46120182 */  mul.s $f6, $f0, $f18
/* 037078 7F004688 46065401 */  sub.s $f16, $f10, $f6
/* 03707C 7F00468C 0FC2E428 */  jal   sub_GAME_7F0B9E04
/* 037080 7F004690 E7B00120 */   swc1  $f16, 0x120($sp)
/* 037084 7F004694 8E4C0090 */  lw    $t4, 0x90($s2)
/* 037088 7F004698 3C014780 */  li    $at, 0x47800000 # 65536.000000
/* 03708C 7F00469C 44819000 */  mtc1  $at, $f18
/* 037090 7F0046A0 448C2000 */  mtc1  $t4, $f4
/* 037094 7F0046A4 AE42008C */  sw    $v0, 0x8c($s2)
/* 037098 7F0046A8 46802220 */  cvt.s.w $f8, $f4
/* 03709C 7F0046AC 46124283 */  div.s $f10, $f8, $f18
/* 0370A0 7F0046B0 E64A0090 */  swc1  $f10, 0x90($s2)
.L7F0046B4:
/* 0370A4 7F0046B4 02A02025 */  move  $a0, $s5
.L7F0046B8:
/* 0370A8 7F0046B8 02402825 */  move  $a1, $s2
/* 0370AC 7F0046BC 0FC00767 */  jal   domakedefaultobj
/* 0370B0 7F0046C0 02603025 */   move  $a2, $s3
/* 0370B4 7F0046C4 100000F2 */  b     other_obj_expand
/* 0370B8 7F0046C8 00000000 */   nop   
obj_03_expand:
/* 0370BC 7F0046CC 13C000F0 */  beqz  $fp, other_obj_expand
/* 0370C0 7F0046D0 00000000 */   nop   
/* 0370C4 7F0046D4 8E4F000C */  lw    $t7, 0xc($s2)
/* 0370C8 7F0046D8 02A02025 */  move  $a0, $s5
/* 0370CC 7F0046DC 02402825 */  move  $a1, $s2
/* 0370D0 7F0046E0 01F47024 */  and   $t6, $t7, $s4
/* 0370D4 7F0046E4 15C000EA */  bnez  $t6, other_obj_expand
/* 0370D8 7F0046E8 00000000 */   nop   
/* 0370DC 7F0046EC 0FC00767 */  jal   domakedefaultobj
/* 0370E0 7F0046F0 02603025 */   move  $a2, $s3
/* 0370E4 7F0046F4 100000E6 */  b     other_obj_expand
/* 0370E8 7F0046F8 00000000 */   nop   
ammo_box_expand:
/* 0370EC 7F0046FC 0FC26669 */  jal   getPlayerCount
/* 0370F0 7F004700 24100001 */   li    $s0, 1
/* 0370F4 7F004704 28410002 */  slti  $at, $v0, 2
/* 0370F8 7F004708 1420000C */  bnez  $at, .L7F0047B8
/* 0370FC 7F00470C 00000000 */   nop   
/* 037100 7F004710 0FC316CD */  jal   getPtrMPWeaponSetData
/* 037104 7F004714 00000000 */   nop   
/* 037108 7F004718 3C188006 */  lui   $t8, %hi(lastmpweaponnum) # $t8, 0x8006
/* 03710C 7F00471C 8F188480 */  lw    $t8, %lo(lastmpweaponnum)($t8)
/* 037110 7F004720 001840C0 */  sll   $t0, $t8, 3
/* 037114 7F004724 00481821 */  addu  $v1, $v0, $t0
/* 037118 7F004728 80640001 */  lb    $a0, 1($v1)
/* 03711C 7F00472C 80700002 */  lb    $s0, 2($v1)
/* 037120 7F004730 00044880 */  sll   $t1, $a0, 2
/* 037124 7F004734 0249C821 */  addu  $t9, $s2, $t1
/* 037128 7F004738 A730007E */  sh    $s0, 0x7e($t9)
.L7F0047B8:
/* 03712C 7F00473C 1A0000D4 */  blez  $s0, other_obj_expand
/* 037130 7F004740 00000000 */   nop   
/* 037134 7F004744 13C000D2 */  beqz  $fp, other_obj_expand
/* 037138 7F004748 00000000 */   nop   
/* 03713C 7F00474C 8E4A000C */  lw    $t2, 0xc($s2)
/* 037140 7F004750 00008825 */  move  $s1, $zero
/* 037144 7F004754 02408025 */  move  $s0, $s2
/* 037148 7F004758 01545824 */  and   $t3, $t2, $s4
/* 03714C 7F00475C 156000CC */  bnez  $t3, other_obj_expand
/* 037150 7F004760 00000000 */   nop   
.L7F0047E0:
/* 037154 7F004764 960D0082 */  lhu   $t5, 0x82($s0)
/* 037158 7F004768 59A00007 */  blezl $t5, .L7F004804
/* 03715C 7F00476C 26310004 */   addiu $s1, $s1, 4
/* 037160 7F004770 96040080 */  lhu   $a0, 0x80($s0)
/* 037164 7F004774 52C40004 */  beql  $s6, $a0, .L7F004804
/* 037168 7F004778 26310004 */   addiu $s1, $s1, 4
/* 03716C 7F00477C 0FC15BC6 */  jal   modelLoad
/* 037170 7F004780 00000000 */   nop   
/* 037174 7F004784 26310004 */  addiu $s1, $s1, 4
.L7F004804:
/* 037178 7F004788 1637FFF6 */  bne   $s1, $s7, .L7F0047E0
/* 03717C 7F00478C 26100004 */   addiu $s0, $s0, 4
/* 037180 7F004790 02A02025 */  move  $a0, $s5
/* 037184 7F004794 02402825 */  move  $a1, $s2
/* 037188 7F004798 0FC00767 */  jal   domakedefaultobj
/* 03718C 7F00479C 02603025 */   move  $a2, $s3
/* 037190 7F0047A0 100000BB */  b     other_obj_expand
/* 037194 7F0047A4 00000000 */   nop   
type2D_tank:
/* 037198 7F0047A8 13C000B9 */  beqz  $fp, other_obj_expand
/* 03719C 7F0047AC 00000000 */   nop   
/* 0371A0 7F0047B0 8E4C000C */  lw    $t4, 0xc($s2)
/* 0371A4 7F0047B4 24040020 */  li    $a0, 32
/* 0371A8 7F0047B8 01947824 */  and   $t7, $t4, $s4
/* 0371AC 7F0047BC 15E000B4 */  bnez  $t7, other_obj_expand
/* 0371B0 7F0047C0 00000000 */   nop   
/* 0371B4 7F0047C4 0FC015AC */  jal   weaponLoadProjectileModels
/* 0371B8 7F0047C8 E7B400E8 */   swc1  $f20, 0xe8($sp)
/* 0371BC 7F0047CC 02A02025 */  move  $a0, $s5
/* 0371C0 7F0047D0 02402825 */  move  $a1, $s2
/* 0371C4 7F0047D4 0FC00767 */  jal   domakedefaultobj
/* 0371C8 7F0047D8 02603025 */   move  $a2, $s3
/* 0371CC 7F0047DC E65400C8 */  swc1  $f20, 0xc8($s2)
/* 0371D0 7F0047E0 E65400CC */  swc1  $f20, 0xcc($s2)
/* 0371D4 7F0047E4 C64C0038 */  lwc1  $f12, 0x38($s2)
/* 0371D8 7F0047E8 0FC16BB8 */  jal   atan2f
/* 0371DC 7F0047EC C64E0040 */   lwc1  $f14, 0x40($s2)
/* 0371E0 7F0047F0 3C018004 */  lui   $at, %hi(D_8004F024) # $at, 0x8004
/* 0371E4 7F0047F4 C426746C */  lwc1  $f6, %lo(D_8004F024)($at)
/* 0371E8 7F0047F8 8E420010 */  lw    $v0, 0x10($s2)
/* 0371EC 7F0047FC 46003401 */  sub.s $f16, $f6, $f0
/* 0371F0 7F004800 10400006 */  beqz  $v0, .L7F004898
/* 0371F4 7F004804 E65000DC */   swc1  $f16, 0xdc($s2)
/* 0371F8 7F004808 8C440014 */  lw    $a0, 0x14($v0)
/* 0371FC 7F00480C 8C450008 */  lw    $a1, 8($v0)
/* 037200 7F004810 0FC2C70C */  jal   stanGetPositionYValue
/* 037204 7F004814 8C460010 */   lw    $a2, 0x10($v0)
/* 037208 7F004818 E7A000E8 */  swc1  $f0, 0xe8($sp)
.L7F004898:
/* 03720C 7F00481C C7A200E8 */  lwc1  $f2, 0xe8($sp)
/* 037210 7F004820 3C018004 */  lui   $at, %hi(D_8004F028) # $at, 0x8004
/* 037214 7F004824 E64200D4 */  swc1  $f2, 0xd4($s2)
/* 037218 7F004828 C4247470 */  lwc1  $f4, %lo(D_8004F028)($at)
/* 03721C 7F00482C 46041203 */  div.s $f8, $f2, $f4
/* 037220 7F004830 10000097 */  b     other_obj_expand
/* 037224 7F004834 E64800D0 */   swc1  $f8, 0xd0($s2)
type27_wheeled_vehicle:
/* 037228 7F004838 13C00095 */  beqz  $fp, other_obj_expand
/* 03722C 7F00483C 00000000 */   nop   
/* 037230 7F004840 8E4E000C */  lw    $t6, 0xc($s2)
/* 037234 7F004844 02A02025 */  move  $a0, $s5
/* 037238 7F004848 02402825 */  move  $a1, $s2
/* 03723C 7F00484C 01D4C024 */  and   $t8, $t6, $s4
/* 037240 7F004850 1700008F */  bnez  $t8, other_obj_expand
/* 037244 7F004854 00000000 */   nop   
/* 037248 7F004858 0FC00767 */  jal   domakedefaultobj
/* 03724C 7F00485C 02603025 */   move  $a2, $s3
/* 037250 7F004860 8E440014 */  lw    $a0, 0x14($s2)
/* 037254 7F004864 5080000E */  beql  $a0, $zero, .L7F00491C
/* 037258 7F004868 3C01BF80 */   lui   $at, 0xbf80
/* 03725C 7F00486C 8C880008 */  lw    $t0, 8($a0)
/* 037260 7F004870 8D090008 */  lw    $t1, 8($t0)
/* 037264 7F004874 8D250014 */  lw    $a1, 0x14($t1)
/* 037268 7F004878 50A00009 */  beql  $a1, $zero, .L7F00491C
/* 03726C 7F00487C 3C01BF80 */   lui   $at, 0xbf80
/* 037270 7F004880 0FC1B3A3 */  jal   modelGetNodeRwData
/* 037274 7F004884 00000000 */   nop   
/* 037278 7F004888 8E590008 */  lw    $t9, 8($s2)
/* 03727C 7F00488C 3C011000 */  li    $at, 0x10000000 # 0.000000
/* 037280 7F004890 03215024 */  and   $t2, $t9, $at
/* 037284 7F004894 2D4B0001 */  sltiu $t3, $t2, 1
/* 037288 7F004898 AC4B0000 */  sw    $t3, ($v0)
/* 03728C 7F00489C 3C01BF80 */  li    $at, 0xBF800000 # -1.000000
.L7F00491C:
/* 037290 7F0048A0 44819000 */  mtc1  $at, $f18
/* 037294 7F0048A4 E6540088 */  swc1  $f20, 0x88($s2)
/* 037298 7F0048A8 E654008C */  swc1  $f20, 0x8c($s2)
/* 03729C 7F0048AC E6540090 */  swc1  $f20, 0x90($s2)
/* 0372A0 7F0048B0 E6540094 */  swc1  $f20, 0x94($s2)
/* 0372A4 7F0048B4 E654009C */  swc1  $f20, 0x9c($s2)
/* 0372A8 7F0048B8 E65400A0 */  swc1  $f20, 0xa0($s2)
/* 0372AC 7F0048BC 8E440080 */  lw    $a0, 0x80($s2)
/* 0372B0 7F0048C0 0FC0D4F6 */  jal   ailistFindById
/* 0372B4 7F0048C4 E6520098 */   swc1  $f18, 0x98($s2)
/* 0372B8 7F0048C8 240DFFFF */  li    $t5, -1
/* 0372BC 7F0048CC AE420080 */  sw    $v0, 0x80($s2)
/* 0372C0 7F0048D0 A6400084 */  sh    $zero, 0x84($s2)
/* 0372C4 7F0048D4 A64D0086 */  sh    $t5, 0x86($s2)
/* 0372C8 7F0048D8 AE4000A4 */  sw    $zero, 0xa4($s2)
/* 0372CC 7F0048DC AE4000A8 */  sw    $zero, 0xa8($s2)
/* 0372D0 7F0048E0 1000006B */  b     other_obj_expand
/* 0372D4 7F0048E4 AE4000AC */   sw    $zero, 0xac($s2)
type28_aircraft:
/* 0372D8 7F0048E8 13C00069 */  beqz  $fp, other_obj_expand
/* 0372DC 7F0048EC 00000000 */   nop   
/* 0372E0 7F0048F0 8E4C000C */  lw    $t4, 0xc($s2)
/* 0372E4 7F0048F4 02A02025 */  move  $a0, $s5
/* 0372E8 7F0048F8 02402825 */  move  $a1, $s2
/* 0372EC 7F0048FC 01947824 */  and   $t7, $t4, $s4
/* 0372F0 7F004900 15E00063 */  bnez  $t7, other_obj_expand
/* 0372F4 7F004904 00000000 */   nop   
/* 0372F8 7F004908 0FC00767 */  jal   domakedefaultobj
/* 0372FC 7F00490C 02603025 */   move  $a2, $s3
/* 037300 7F004910 3C01BF80 */  li    $at, 0xBF800000 # -1.000000
/* 037304 7F004914 44810000 */  mtc1  $at, $f0
/* 037308 7F004918 E6540098 */  swc1  $f20, 0x98($s2)
/* 03730C 7F00491C E654009C */  swc1  $f20, 0x9c($s2)
/* 037310 7F004920 E6540088 */  swc1  $f20, 0x88($s2)
/* 037314 7F004924 E654008C */  swc1  $f20, 0x8c($s2)
/* 037318 7F004928 E6540090 */  swc1  $f20, 0x90($s2)
/* 03731C 7F00492C E65400A4 */  swc1  $f20, 0xa4($s2)
/* 037320 7F004930 8E440080 */  lw    $a0, 0x80($s2)
/* 037324 7F004934 E64000A0 */  swc1  $f0, 0xa0($s2)
/* 037328 7F004938 0FC0D4F6 */  jal   ailistFindById
/* 03732C 7F00493C E6400094 */   swc1  $f0, 0x94($s2)
/* 037330 7F004940 240EFFFF */  li    $t6, -1
/* 037334 7F004944 AE420080 */  sw    $v0, 0x80($s2)
/* 037338 7F004948 A6400084 */  sh    $zero, 0x84($s2)
/* 03733C 7F00494C A64E0086 */  sh    $t6, 0x86($s2)
/* 037340 7F004950 AE4000A8 */  sw    $zero, 0xa8($s2)
/* 037344 7F004954 AE4000AC */  sw    $zero, 0xac($s2)
/* 037348 7F004958 1000004D */  b     other_obj_expand
/* 03734C 7F00495C AE4000B0 */   sw    $zero, 0xb0($s2)
tag_expand:
/* 037350 7F004960 86580006 */  lh    $t8, 6($s2)
/* 037354 7F004964 02A02025 */  move  $a0, $s5
/* 037358 7F004968 0FC15C60 */  jal   setupCommandGetObject
/* 03735C 7F00496C 03132821 */   addu  $a1, $t8, $s3
/* 037360 7F004970 10400004 */  beqz  $v0, .L7F004A00
/* 037364 7F004974 AE42000C */   sw    $v0, 0xc($s2)
/* 037368 7F004978 8C480064 */  lw    $t0, 0x64($v0)
/* 03736C 7F00497C 35090010 */  ori   $t1, $t0, 0x10
/* 037370 7F004980 AC490064 */  sw    $t1, 0x64($v0)
.L7F004A00:
/* 037374 7F004984 0FC013C8 */  jal   set_parent_cur_tag_entry
/* 037378 7F004988 02402025 */   move  $a0, $s2
/* 03737C 7F00498C 10000040 */  b     other_obj_expand
/* 037380 7F004990 00000000 */   nop   
type25_rename:
/* 037384 7F004994 8E590004 */  lw    $t9, 4($s2)
/* 037388 7F004998 02A02025 */  move  $a0, $s5
/* 03738C 7F00499C 0FC15C60 */  jal   setupCommandGetObject
/* 037390 7F0049A0 03332821 */   addu  $a1, $t9, $s3
/* 037394 7F0049A4 10400004 */  beqz  $v0, .L7F004A34
/* 037398 7F0049A8 AE420024 */   sw    $v0, 0x24($s2)
/* 03739C 7F0049AC 8C4A0064 */  lw    $t2, 0x64($v0)
/* 0373A0 7F0049B0 354B0400 */  ori   $t3, $t2, 0x400
/* 0373A4 7F0049B4 AC4B0064 */  sw    $t3, 0x64($v0)
.L7F004A34:
/* 0373A8 7F0049B8 0FC23782 */  jal   bondinvAddTextOverride
/* 0373AC 7F0049BC 02402025 */   move  $a0, $s2
/* 0373B0 7F0049C0 10000033 */  b     other_obj_expand
/* 0373B4 7F0049C4 00000000 */   nop   
type23_solo_brief_text:
/* 0373B8 7F0049C8 0FC013CE */  jal   setup_briefing_text_entry_parent
/* 0373BC 7F0049CC 02402025 */   move  $a0, $s2
/* 0373C0 7F0049D0 1000002F */  b     other_obj_expand
/* 0373C4 7F0049D4 00000000 */   nop   
type2E_viewport_pos:
/* 0373C8 7F0049D8 8E4D0004 */  lw    $t5, 4($s2)
/* 0373CC 7F0049DC 3C0142C8 */  li    $at, 0x42C80000 # 100.000000
/* 0373D0 7F0049E0 44810000 */  mtc1  $at, $f0
/* 0373D4 7F0049E4 448D5000 */  mtc1  $t5, $f10
/* 0373D8 7F0049E8 8E4F000C */  lw    $t7, 0xc($s2)
/* 0373DC 7F0049EC 8E4C0008 */  lw    $t4, 8($s2)
/* 0373E0 7F0049F0 468051A0 */  cvt.s.w $f6, $f10
/* 0373E4 7F0049F4 448F5000 */  mtc1  $t7, $f10
/* 0373E8 7F0049F8 448C2000 */  mtc1  $t4, $f4
/* 0373EC 7F0049FC 8E4E0010 */  lw    $t6, 0x10($s2)
/* 0373F0 7F004A00 8E580014 */  lw    $t8, 0x14($s2)
/* 0373F4 7F004A04 46802220 */  cvt.s.w $f8, $f4
/* 0373F8 7F004A08 448E2000 */  mtc1  $t6, $f4
/* 0373FC 7F004A0C 3C014780 */  li    $at, 0x47800000 # 65536.000000
/* 037400 7F004A10 46003403 */  div.s $f16, $f6, $f0
/* 037404 7F004A14 468051A0 */  cvt.s.w $f6, $f10
/* 037408 7F004A18 46004483 */  div.s $f18, $f8, $f0
/* 03740C 7F004A1C E6500004 */  swc1  $f16, 4($s2)
/* 037410 7F004A20 46802220 */  cvt.s.w $f8, $f4
/* 037414 7F004A24 44812000 */  mtc1  $at, $f4
/* 037418 7F004A28 46003403 */  div.s $f16, $f6, $f0
/* 03741C 7F004A2C 44983000 */  mtc1  $t8, $f6
/* 037420 7F004A30 E6520008 */  swc1  $f18, 8($s2)
/* 037424 7F004A34 44819000 */  mtc1  $at, $f18
/* 037428 7F004A38 00000000 */  nop   
/* 03742C 7F004A3C 46124283 */  div.s $f10, $f8, $f18
/* 037430 7F004A40 E650000C */  swc1  $f16, 0xc($s2)
/* 037434 7F004A44 46803420 */  cvt.s.w $f16, $f6
/* 037438 7F004A48 46048203 */  div.s $f8, $f16, $f4
/* 03743C 7F004A4C E64A0010 */  swc1  $f10, 0x10($s2)
/* 037440 7F004A50 1000000F */  b     other_obj_expand
/* 037444 7F004A54 E6480014 */   swc1  $f8, 0x14($s2)
type17_objective_expand:
/* 037448 7F004A58 0FC013D4 */  jal   add_ptr_to_objective
/* 03744C 7F004A5C 02402025 */   move  $a0, $s2
/* 037450 7F004A60 1000000B */  b     other_obj_expand
/* 037454 7F004A64 00000000 */   nop   
type20_subobjective_expand:
/* 037458 7F004A68 0FC013E3 */  jal   set_parent_cur_obj_enter_room
/* 03745C 7F004A6C 02402025 */   move  $a0, $s2
/* 037460 7F004A70 10000007 */  b     other_obj_expand
/* 037464 7F004A74 00000000 */   nop   
type21_subobjective_expand:
/* 037468 7F004A78 0FC013E9 */  jal   set_parent_cur_obj_deposited_in_room
/* 03746C 7F004A7C 02402025 */   move  $a0, $s2
/* 037470 7F004A80 10000003 */  b     other_obj_expand
/* 037474 7F004A84 00000000 */   nop   
type1E_subobjective_expand:
/* 037478 7F004A88 0FC013EF */  jal   set_parent_cur_obj_photograph
/* 03747C 7F004A8C 02402025 */   move  $a0, $s2
other_obj_expand:
/* 037480 7F004A90 0FC15AF5 */  jal   sizepropdef
/* 037484 7F004A94 02402025 */   move  $a0, $s2
/* 037488 7F004A98 00024080 */  sll   $t0, $v0, 2
/* 03748C 7F004A9C 01129021 */  addu  $s2, $t0, $s2
/* 037490 7F004AA0 92430003 */  lbu   $v1, 3($s2)
/* 037494 7F004AA4 24010030 */  li    $at, 48
/* 037498 7F004AA8 26730001 */  addiu $s3, $s3, 1
/* 03749C 7F004AAC 5461FE11 */  bnel  $v1, $at, .L7F0042F4
/* 0374A0 7F004AB0 2468FFFF */   addiu $t0, $v1, -1
/* 0374A4 7F004AB4 3C128006 */  lui   $s2, %hi(g_CurrentSetup+0x0c) # $s2, 0x8006
/* 0374A8 7F004AB8 8E524C4C */  lw    $s2, %lo(g_CurrentSetup+0x0c)($s2)
/* 0374AC 7F004ABC 00009825 */  move  $s3, $zero
/* 0374B0 7F004AC0 92430003 */  lbu   $v1, 3($s2)
.L7F004B40:
/* 0374B4 7F004AC4 24010030 */  li    $at, 48
/* 0374B8 7F004AC8 3C170008 */  lui   $s7, 8
/* 0374BC 7F004ACC 106100CF */  beq   $v1, $at, .L7F004E88
/* 0374C0 7F004AD0 24160008 */   li    $s6, 8
/* 0374C4 7F004AD4 241E002B */  li    $fp, 43
/* 0374C8 7F004AD8 24140001 */  li    $s4, 1
/* 0374CC 7F004ADC 2469FFFD */  addiu $t1, $v1, -3
.L7F004B5C:
/* 0374D0 7F004AE0 2D21002D */  sltiu $at, $t1, 0x2d
/* 0374D4 7F004AE4 102000A4 */  beqz  $at, .L7F004DF4
/* 0374D8 7F004AE8 00094880 */   sll   $t1, $t1, 2
/* 0374DC 7F004AEC 3C018004 */  lui   $at, %hi(jpt_8004F02C)
/* 0374E0 7F004AF0 00290821 */  addu  $at, $at, $t1
/* 0374E4 7F004AF4 8C297474 */  lw    $t1, %lo(jpt_8004F02C)($at)
/* 0374E8 7F004AF8 01200008 */  jr    $t1
/* 0374EC 7F004AFC 00000000 */   nop   
.L7F004B7C:
/* 0374F0 7F004B00 8E590010 */  lw    $t9, 0x10($s2)
/* 0374F4 7F004B04 1320009C */  beqz  $t9, .L7F004DF4
/* 0374F8 7F004B08 00000000 */   nop   
/* 0374FC 7F004B0C 8E4A0008 */  lw    $t2, 8($s2)
/* 037500 7F004B10 314B8000 */  andi  $t3, $t2, 0x8000
/* 037504 7F004B14 11600098 */  beqz  $t3, .L7F004DF4
/* 037508 7F004B18 00000000 */   nop   
/* 03750C 7F004B1C 86420006 */  lh    $v0, 6($s2)
/* 037510 7F004B20 02A02025 */  move  $a0, $s5
/* 037514 7F004B24 0FC15C60 */  jal   setupCommandGetObject
/* 037518 7F004B28 02622821 */   addu  $a1, $s3, $v0
/* 03751C 7F004B2C 10400092 */  beqz  $v0, .L7F004DF4
/* 037520 7F004B30 00408025 */   move  $s0, $v0
/* 037524 7F004B34 8C4D0010 */  lw    $t5, 0x10($v0)
/* 037528 7F004B38 11A0008F */  beqz  $t5, .L7F004DF4
/* 03752C 7F004B3C 00000000 */   nop   
/* 037530 7F004B40 8E4C0064 */  lw    $t4, 0x64($s2)
/* 037534 7F004B44 8E440014 */  lw    $a0, 0x14($s2)
/* 037538 7F004B48 01977825 */  or    $t7, $t4, $s7
/* 03753C 7F004B4C AE4F0064 */  sw    $t7, 0x64($s2)
/* 037540 7F004B50 0FC1B4CF */  jal   modelSetScale
/* 037544 7F004B54 8C850014 */   lw    $a1, 0x14($a0)
/* 037548 7F004B58 8E440010 */  lw    $a0, 0x10($s2)
/* 03754C 7F004B5C 0FC0E999 */  jal   chrpropReparent
/* 037550 7F004B60 8E050010 */   lw    $a1, 0x10($s0)
/* 037554 7F004B64 10000084 */  b     .L7F004DF4
/* 037558 7F004B68 00000000 */   nop   
.L7F004BE8:
/* 03755C 7F004B6C 8E4E0004 */  lw    $t6, 4($s2)
/* 037560 7F004B70 0FC15B5A */  jal   setupGetPtrToCommandByIndex
/* 037564 7F004B74 01D32021 */   addu  $a0, $t6, $s3
/* 037568 7F004B78 8E580008 */  lw    $t8, 8($s2)
/* 03756C 7F004B7C 00408025 */  move  $s0, $v0
/* 037570 7F004B80 0FC15B5A */  jal   setupGetPtrToCommandByIndex
/* 037574 7F004B84 03132021 */   addu  $a0, $t8, $s3
/* 037578 7F004B88 1200007B */  beqz  $s0, .L7F004DF4
/* 03757C 7F004B8C 00402825 */   move  $a1, $v0
/* 037580 7F004B90 10400079 */  beqz  $v0, .L7F004DF4
/* 037584 7F004B94 00000000 */   nop   
/* 037588 7F004B98 92080003 */  lbu   $t0, 3($s0)
/* 03758C 7F004B9C 16C80076 */  bne   $s6, $t0, .L7F004DF4
/* 037590 7F004BA0 00000000 */   nop   
/* 037594 7F004BA4 90490003 */  lbu   $t1, 3($v0)
/* 037598 7F004BA8 16C90073 */  bne   $s6, $t1, .L7F004DF4
/* 03759C 7F004BAC 00000000 */   nop   
/* 0375A0 7F004BB0 0FC14815 */  jal   propweaponSetDual
/* 0375A4 7F004BB4 02002025 */   move  $a0, $s0
/* 0375A8 7F004BB8 1000006F */  b     .L7F004DF4
/* 0375AC 7F004BBC 00000000 */   nop   
.L7F004C3C:
/* 0375B0 7F004BC0 8E420004 */  lw    $v0, 4($s2)
/* 0375B4 7F004BC4 8E510008 */  lw    $s1, 8($s2)
/* 0375B8 7F004BC8 02A02025 */  move  $a0, $s5
/* 0375BC 7F004BCC 0FC15C60 */  jal   setupCommandGetObject
/* 0375C0 7F004BD0 02622821 */   addu  $a1, $s3, $v0
/* 0375C4 7F004BD4 00408025 */  move  $s0, $v0
/* 0375C8 7F004BD8 0FC15B5A */  jal   setupGetPtrToCommandByIndex
/* 0375CC 7F004BDC 02712021 */   addu  $a0, $s3, $s1
/* 0375D0 7F004BE0 12000065 */  beqz  $s0, .L7F004DF4
/* 0375D4 7F004BE4 00000000 */   nop   
/* 0375D8 7F004BE8 8E030010 */  lw    $v1, 0x10($s0)
/* 0375DC 7F004BEC 10600062 */  beqz  $v1, .L7F004DF4
/* 0375E0 7F004BF0 00000000 */   nop   
/* 0375E4 7F004BF4 10400060 */  beqz  $v0, .L7F004DF4
/* 0375E8 7F004BF8 00000000 */   nop   
/* 0375EC 7F004BFC 90590003 */  lbu   $t9, 3($v0)
/* 0375F0 7F004C00 1699005D */  bne   $s4, $t9, .L7F004DF4
/* 0375F4 7F004C04 00000000 */   nop   
/* 0375F8 7F004C08 8C4A0010 */  lw    $t2, 0x10($v0)
/* 0375FC 7F004C0C 1140005A */  beqz  $t2, .L7F004DF4
/* 037600 7F004C10 00000000 */   nop   
/* 037604 7F004C14 AE430004 */  sw    $v1, 4($s2)
/* 037608 7F004C18 8C4B0010 */  lw    $t3, 0x10($v0)
/* 03760C 7F004C1C 02402025 */  move  $a0, $s2
/* 037610 7F004C20 0FC00644 */  jal   initSetLevelLoadPropSwitch
/* 037614 7F004C24 AE4B0008 */   sw    $t3, 8($s2)
/* 037618 7F004C28 8E0D0064 */  lw    $t5, 0x64($s0)
/* 03761C 7F004C2C 35AC0001 */  ori   $t4, $t5, 1
/* 037620 7F004C30 10000051 */  b     .L7F004DF4
/* 037624 7F004C34 AE0C0064 */   sw    $t4, 0x64($s0)
.L7F004CB4:
/* 037628 7F004C38 8E420004 */  lw    $v0, 4($s2)
/* 03762C 7F004C3C 8E4F000C */  lw    $t7, 0xc($s2)
/* 037630 7F004C40 8E510008 */  lw    $s1, 8($s2)
/* 037634 7F004C44 02A02025 */  move  $a0, $s5
/* 037638 7F004C48 02622821 */  addu  $a1, $s3, $v0
/* 03763C 7F004C4C 0FC15C60 */  jal   setupCommandGetObject
/* 037640 7F004C50 AFAF0080 */   sw    $t7, 0x80($sp)
/* 037644 7F004C54 00408025 */  move  $s0, $v0
/* 037648 7F004C58 02A02025 */  move  $a0, $s5
/* 03764C 7F004C5C 0FC15C60 */  jal   setupCommandGetObject
/* 037650 7F004C60 02712821 */   addu  $a1, $s3, $s1
/* 037654 7F004C64 8FAE0080 */  lw    $t6, 0x80($sp)
/* 037658 7F004C68 00408825 */  move  $s1, $v0
/* 03765C 7F004C6C 02A02025 */  move  $a0, $s5
/* 037660 7F004C70 0FC15C60 */  jal   setupCommandGetObject
/* 037664 7F004C74 026E2821 */   addu  $a1, $s3, $t6
/* 037668 7F004C78 1200003F */  beqz  $s0, .L7F004DF4
/* 03766C 7F004C7C 00000000 */   nop   
/* 037670 7F004C80 8E180010 */  lw    $t8, 0x10($s0)
/* 037674 7F004C84 1300003C */  beqz  $t8, .L7F004DF4
/* 037678 7F004C88 00000000 */   nop   
/* 03767C 7F004C8C 1220003A */  beqz  $s1, .L7F004DF4
/* 037680 7F004C90 00000000 */   nop   
/* 037684 7F004C94 8E280010 */  lw    $t0, 0x10($s1)
/* 037688 7F004C98 11000037 */  beqz  $t0, .L7F004DF4
/* 03768C 7F004C9C 00000000 */   nop   
/* 037690 7F004CA0 92290003 */  lbu   $t1, 3($s1)
/* 037694 7F004CA4 17C90034 */  bne   $fp, $t1, .L7F004DF4
/* 037698 7F004CA8 00000000 */   nop   
/* 03769C 7F004CAC 10400032 */  beqz  $v0, .L7F004DF4
/* 0376A0 7F004CB0 00000000 */   nop   
/* 0376A4 7F004CB4 8C590010 */  lw    $t9, 0x10($v0)
/* 0376A8 7F004CB8 1320002F */  beqz  $t9, .L7F004DF4
/* 0376AC 7F004CBC 00000000 */   nop   
/* 0376B0 7F004CC0 904A0003 */  lbu   $t2, 3($v0)
/* 0376B4 7F004CC4 02402025 */  move  $a0, $s2
/* 0376B8 7F004CC8 168A002B */  bne   $s4, $t2, .L7F004DF4
/* 0376BC 7F004CCC 00000000 */   nop   
/* 0376C0 7F004CD0 AE500004 */  sw    $s0, 4($s2)
/* 0376C4 7F004CD4 AE510008 */  sw    $s1, 8($s2)
/* 0376C8 7F004CD8 AE42000C */  sw    $v0, 0xc($s2)
/* 0376CC 7F004CDC 0FC00650 */  jal   initSetLevelLoadPropSafeItem
/* 0376D0 7F004CE0 AFA20074 */   sw    $v0, 0x74($sp)
/* 0376D4 7F004CE4 8E0B000C */  lw    $t3, 0xc($s0)
/* 0376D8 7F004CE8 8FA30074 */  lw    $v1, 0x74($sp)
/* 0376DC 7F004CEC 356D0400 */  ori   $t5, $t3, 0x400
/* 0376E0 7F004CF0 AE0D000C */  sw    $t5, 0xc($s0)
/* 0376E4 7F004CF4 8C6C000C */  lw    $t4, 0xc($v1)
/* 0376E8 7F004CF8 358F0400 */  ori   $t7, $t4, 0x400
/* 0376EC 7F004CFC 1000001E */  b     .L7F004DF4
/* 0376F0 7F004D00 AC6F000C */   sw    $t7, 0xc($v1)
.L7F004D80:
/* 0376F4 7F004D04 8E420004 */  lw    $v0, 4($s2)
/* 0376F8 7F004D08 8E510008 */  lw    $s1, 8($s2)
/* 0376FC 7F004D0C 02A02025 */  move  $a0, $s5
/* 037700 7F004D10 0FC15C60 */  jal   setupCommandGetObject
/* 037704 7F004D14 02622821 */   addu  $a1, $s3, $v0
/* 037708 7F004D18 00408025 */  move  $s0, $v0
/* 03770C 7F004D1C 02A02025 */  move  $a0, $s5
/* 037710 7F004D20 0FC15C60 */  jal   setupCommandGetObject
/* 037714 7F004D24 02712821 */   addu  $a1, $s3, $s1
/* 037718 7F004D28 12000013 */  beqz  $s0, .L7F004DF4
/* 03771C 7F004D2C 00000000 */   nop   
/* 037720 7F004D30 8E0E0010 */  lw    $t6, 0x10($s0)
/* 037724 7F004D34 11C00010 */  beqz  $t6, .L7F004DF4
/* 037728 7F004D38 00000000 */   nop   
/* 03772C 7F004D3C 1040000E */  beqz  $v0, .L7F004DF4
/* 037730 7F004D40 00000000 */   nop   
/* 037734 7F004D44 8C580010 */  lw    $t8, 0x10($v0)
/* 037738 7F004D48 1300000B */  beqz  $t8, .L7F004DF4
/* 03773C 7F004D4C 00000000 */   nop   
/* 037740 7F004D50 92080003 */  lbu   $t0, 3($s0)
/* 037744 7F004D54 02402025 */  move  $a0, $s2
/* 037748 7F004D58 16880007 */  bne   $s4, $t0, .L7F004DF4
/* 03774C 7F004D5C 00000000 */   nop   
/* 037750 7F004D60 AE500004 */  sw    $s0, 4($s2)
/* 037754 7F004D64 0FC0064A */  jal   initSetLevelLoadPropLockDoor
/* 037758 7F004D68 AE420008 */   sw    $v0, 8($s2)
/* 03775C 7F004D6C 8E090064 */  lw    $t1, 0x64($s0)
/* 037760 7F004D70 35392000 */  ori   $t9, $t1, 0x2000
/* 037764 7F004D74 AE190064 */  sw    $t9, 0x64($s0)
.L7F004DF4:
/* 037768 7F004D78 0FC15AF5 */  jal   sizepropdef
/* 03776C 7F004D7C 02402025 */   move  $a0, $s2
/* 037770 7F004D80 00025080 */  sll   $t2, $v0, 2
/* 037774 7F004D84 01529021 */  addu  $s2, $t2, $s2
/* 037778 7F004D88 92430003 */  lbu   $v1, 3($s2)
/* 03777C 7F004D8C 24010030 */  li    $at, 48
/* 037780 7F004D90 26730001 */  addiu $s3, $s3, 1
/* 037784 7F004D94 5461FF52 */  bnel  $v1, $at, .L7F004B5C
/* 037788 7F004D98 2469FFFD */   addiu $t1, $v1, -3
/* 03778C 7F004D9C 1000001B */  b     .L7F004E88
/* 037790 7F004DA0 00000000 */   nop   
.L7F004E20:
/* 037794 7F004DA4 3C018006 */  lui   $at, %hi(g_CurrentSetup+0) # $at, 0x8006
/* 037798 7F004DA8 AC204C40 */  sw    $zero, %lo(g_CurrentSetup+0)($at)
/* 03779C 7F004DAC 3C018006 */  lui   $at, %hi(g_CurrentSetup+4) # $at, 0x8006
/* 0377A0 7F004DB0 AC204C44 */  sw    $zero, %lo(g_CurrentSetup+4)($at)
/* 0377A4 7F004DB4 3C018006 */  lui   $at, %hi(g_CurrentSetup+8) # $at, 0x8006
/* 0377A8 7F004DB8 AC204C48 */  sw    $zero, %lo(g_CurrentSetup+8)($at)
/* 0377AC 7F004DBC 3C018006 */  lui   $at, %hi(g_CurrentSetup+0x0c) # $at, 0x8006
/* 0377B0 7F004DC0 AC204C4C */  sw    $zero, %lo(g_CurrentSetup+0x0c)($at)
/* 0377B4 7F004DC4 3C018006 */  lui   $at, %hi(g_CurrentSetup+0x10) # $at, 0x8006
/* 0377B8 7F004DC8 AC204C50 */  sw    $zero, %lo(g_CurrentSetup+0x10)($at)
/* 0377BC 7F004DCC 3C018006 */  lui   $at, %hi(g_CurrentSetup+0x14) # $at, 0x8006
/* 0377C0 7F004DD0 AC204C54 */  sw    $zero, %lo(g_CurrentSetup+0x14)($at)
/* 0377C4 7F004DD4 3C018006 */  lui   $at, %hi(g_CurrentSetup+0x18) # $at, 0x8006
/* 0377C8 7F004DD8 AC204C58 */  sw    $zero, %lo(g_CurrentSetup+0x18)($at)
/* 0377CC 7F004DDC 3C018006 */  lui   $at, %hi(g_CurrentSetup+0x1C) # $at, 0x8006
/* 0377D0 7F004DE0 AC204C5C */  sw    $zero, %lo(g_CurrentSetup+0x1C)($at)
/* 0377D4 7F004DE4 3C018006 */  lui   $at, %hi(g_CurrentSetup+0x20) # $at, 0x8006
/* 0377D8 7F004DE8 AC204C60 */  sw    $zero, %lo(g_CurrentSetup+0x20)($at)
/* 0377DC 7F004DEC 3C018006 */  lui   $at, %hi(g_CurrentSetup+0x24) # $at, 0x8006
/* 0377E0 7F004DF0 AC204C64 */  sw    $zero, %lo(g_CurrentSetup+0x24)($at)
/* 0377E4 7F004DF4 0FC003AE */  jal   alloc_init_GUARDdata_entries
/* 0377E8 7F004DF8 00002025 */   move  $a0, $zero
/* 0377EC 7F004DFC 0FC01538 */  jal   sub_GAME_7F005540
/* 0377F0 7F004E00 00002025 */   move  $a0, $zero
/* 0377F4 7F004E04 0FC01571 */  jal   sub_GAME_7F005624
/* 0377F8 7F004E08 00002025 */   move  $a0, $zero
.L7F004E88:
/* 0377FC 7F004E0C 0FC00417 */  jal   alloc_false_GUARDdata_to_exec_global_action
/* 037800 7F004E10 00000000 */   nop   
/* 037804 7F004E14 8FBF0044 */  lw    $ra, 0x44($sp)
/* 037808 7F004E18 D7B40018 */  ldc1  $f20, 0x18($sp)
/* 03780C 7F004E1C 8FB00020 */  lw    $s0, 0x20($sp)
/* 037810 7F004E20 8FB10024 */  lw    $s1, 0x24($sp)
/* 037814 7F004E24 8FB20028 */  lw    $s2, 0x28($sp)
/* 037818 7F004E28 8FB3002C */  lw    $s3, 0x2c($sp)
/* 03781C 7F004E2C 8FB40030 */  lw    $s4, 0x30($sp)
/* 037820 7F004E30 8FB50034 */  lw    $s5, 0x34($sp)
/* 037824 7F004E34 8FB60038 */  lw    $s6, 0x38($sp)
/* 037828 7F004E38 8FB7003C */  lw    $s7, 0x3c($sp)
/* 03782C 7F004E3C 8FBE0040 */  lw    $fp, 0x40($sp)
/* 037830 7F004E40 03E00008 */  jr    $ra
/* 037834 7F004E44 27BD0280 */   addiu $sp, $sp, 0x280
 )
#endif


#endif


