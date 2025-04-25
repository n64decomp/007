#include <ultra64.h>
#include <assert.h>
#include <bondgame.h>
#include <bondtypes.h>
#include <bondaicommands.h>
#include <boss.h>
#include <limits.h>
#include <music.h>
#include <random.h>
#include <snd.h>
#include "bg.h"
#include "bondview.h"
#include "cheat_buttons.h"
#include "chr.h"
#include "chrai.h"
#include "chraidata.h"
#include "chrlv.h"
#include "chrobjhandler.h"
#include "explosions.h"
#include "file.h"
#include "fog.h"
#include "gun.h"
#include "initanitable.h"
#include "loadobjectmodel.h"
#include "lvl.h"
#include "lvl_text.h"
#include "math_atan2f.h"
#include "math_ceil.h"
#include "math_floor.h"
#include "mp_music.h"
#include "player.h"
#include "objecthandler.h"
#include "objective_status.h"
#include "player.h"
#include "player_2.h"
#include "stan.h"

// bss


//CODE.bss:80069C30
s16 * ptr_list_object_lookup_indices;

//CODE.bss:80069C34
u32 num_obj_position_data_entries;

/**
 * Address 0x80069C38.
*/
PropRecord pos_data_entry[POS_DATA_ENTRY_LEN];

//CODE.bss:80071618
s16 *RoomPropListChunkIndexes;

//CODE.bss:8007161C
struct roomproplistchunk *RoomPropListChunks;

/**
 * Array of pointers, containing onscreen props.
 *
 * Address 0x80071620.
*/
PropRecord *g_OnScreenPropList[ONSCREEN_PROP_LIST_LEN];

/**
 * Pointer to last onscreen prop.
 * Address 0x80071DF0.
*/
PropRecord **g_LastOnScreenProp;

/**
 * Count of onscreen props.
 * Address 0x80071DF4.
 * canonically propznum
*/
s32 g_OnScreenPropCount;

//CODE.bss:80071DF8
PropRecord *g_InteractProp;
//CODE.bss:80071DFC
u32 dword_CODE_bss_80071DFC;
//CODE.bss:80071E00
WeaponObjRecord* temp_mine_table[30];

//CODE.bss:80071E78
f32 gasTimeToFullOpacity;
//CODE.bss:80071E7C
u32 gasDoesDamageFlag;

/**
 * Address 0x80071E80.
*/
WeaponObjRecord g_WeaponSlots[MAX_WEAPON_SLOTS];

/**
 * Address 0x80072E70.
*/
HatRecord g_HatSlots[MAX_HAT_SLOTS];

/**
 * Address 0x80073370.
*/
AmmoCrateRecord g_AmmoCrates[MAX_AMMO_CRATES];

/**
 * Address 0x80073DC0.
*/
Projectile g_Projectiles[PROJECTILES_ARR_MAX];

/**
 * Address 0x80075030.
*/
Embedment g_Embedments[EMBEDMENT_ARR_MAX];

//CODE.bss:80075B70
struct Model *g_CurrentProjectileModel;
//CODE.bss:80075B74
struct ModelNode * dword_CODE_bss_80075B74;
//CODE.bss:80075B78
coord3d flt_CODE_bss_80075B78;
//CODE.bss:80075B84
f32 flt_CODE_bss_80075B84;
//CODE.bss:80075B88
coord3d flt_CODE_bss_80075B88;
//CODE.bss:80075B94
f32 flt_CODE_bss_80075B94;

/**
 * Address 0x80075B98.
*/
MonitorRecord g_MonitorAnimController;

/**
 * Unused / unreferenced (from padding / align?)
 * Address 0x80075C0C.
*/
s32 bss_80075C0C;

/**
 * Address 0x80075C10.
*/
struct object_animation_controller g_UnknownAnimController;

/**
 * Unused / unreferenced (from padding / align?)
 * Address 0x80075C84.
*/
s32 bss_80075C84;

/**
 * Unused / unreferenced (from padding / align?)
 * Address 0x80075C88.
*/
struct object_animation_controller g_TaserAnimController;

/**
 * Address 0x80075CFC.
*/
s32 bss_80075CFC;



//CODE.bss:80075D00 - 80075D24
stagesetup g_CurrentSetup; //Public Working Setup

//CODE.bss:80075D28
stagesetup                        *g_ptrStageSetupFile;

PropRecord *ptr_obj_pos_list_current_entry = 0;
PropRecord *ptr_obj_pos_list_first_entry = 0;
PropRecord *ptr_obj_pos_list_final_entry = 0;
f32 difficulty = 1.0;
struct coord2d g_DefaultAutoAimCoord = { 0 };



// forward declarations

Gfx *chrpropRender(Gfx *arg0, PropRecord *arg1, s32 withalpha);
void chraiCheckUseHeldItem(s32 hand);
void chraiDefaultWeaponFireHandler(s32);
void chraiFistAttackHandler(s32, s32);
void propExecuteTickOperation(PropRecord *prop, INV_ITEM_TYPE op);

// end forward declarations


/**
 * Counts onscreen props.
 *
 * Address 0x7F03A240.
*/
void chraiUpdateOnscreenPropCount(void)
{
    s32 i;
    s32 j;
    s32 count;
    PropRecord *prop;
    s32 phi_a0;
    f32 phi_f12;

    i = 0;
    count = 0;
    prop = get_ptr_obj_pos_list_current_entry();

    for (; prop != NULL; prop = prop->prev)
    {
        if ((prop->flags & (PROPFLAG_ENABLED | PROPFLAG_ONSCREEN)) == (PROPFLAG_ENABLED | PROPFLAG_ONSCREEN))
        {
            g_OnScreenPropList[count] = prop;
            count++;
        }
    }

    g_OnScreenPropCount = count;
    g_OnScreenPropList[count] = NULL;

    if(1)
    {
        // removed
        #ifdef DEBUG
        assert(propznum<MAXPROPSVISIBLE); //800 props
        #endif
    }

    g_LastOnScreenProp = (PropRecord *)&g_OnScreenPropList[count];

    for (i=0; i<count; i++)
    {
        phi_a0 = -1;
        phi_f12 = -4.2949673e9f;

        for (j = i; j < count; j++)
        {
            f32 f = g_OnScreenPropList[j]->zDepth;

            if (phi_f12 < f)
            {
                phi_f12 = f;
                phi_a0 = j;
            }
        }

        if (phi_a0 >= 0)
        {
            prop = g_OnScreenPropList[i];
            g_OnScreenPropList[i] = g_OnScreenPropList[phi_a0];
            g_OnScreenPropList[phi_a0] = prop;
        }
    }
}


void chrpropEnable(PropRecord *prop)
{
    prop->flags |= PROPFLAG_ENABLED;
}



void chrpropDisable(PropRecord *prop)
{
    prop->flags &= ~PROPFLAG_ENABLED;
}







PropRecord *get_ptr_obj_pos_list_current_entry(void)
{
    return ptr_obj_pos_list_current_entry;
}



PropRecord* chrpropAllocate(void)
{
    PropRecord* prop;

    if (ptr_obj_pos_list_final_entry)
    {
        prop = ptr_obj_pos_list_final_entry;
        ptr_obj_pos_list_final_entry = prop->prev;

        prop->prev = NULL;
        prop->next = NULL;
        prop->parent = NULL;
        prop->child = NULL;

        prop->flags = 0;
        prop->stan = NULL;
        prop->timetoregen = 0;
        prop->rooms[0] = 0xFF;
        return prop;
    }

    return NULL;
}


void chrpropFree(PropRecord *prop)
{
    prop->prev = ptr_obj_pos_list_final_entry;
    prop->next = 0x0;
    prop->stan = 0x0;
    ptr_obj_pos_list_final_entry = prop;
}


void chrpropActivate(PropRecord* prop)
{
    PropRecord* cur;

    cur = ptr_obj_pos_list_current_entry;
    if (cur != NULL)
    {
        cur->next = prop;

        prop->prev = ptr_obj_pos_list_current_entry;
        prop->next = NULL;

        ptr_obj_pos_list_current_entry = prop;
        return;
    }

    prop->prev = NULL;
    prop->next = NULL;
    ptr_obj_pos_list_current_entry = ptr_obj_pos_list_first_entry = prop;
}


void chrpropActivateThisFrame(PropRecord* prop) {
    PropRecord* first;

    first = ptr_obj_pos_list_first_entry;
    if (first != NULL) {
        first->prev = prop;
        prop->next = ptr_obj_pos_list_first_entry;
        prop->prev = NULL;
        ptr_obj_pos_list_first_entry = prop;
        return;
    }
    prop->prev = NULL;
    prop->next = NULL;
    ptr_obj_pos_list_first_entry = prop;
    ptr_obj_pos_list_current_entry = prop;
}


void chrpropDelist(PropRecord *prop)
{
    PropRecord *temp_v0;
    PropRecord *temp_v0_2;

    if (prop == ptr_obj_pos_list_current_entry)
    {
        ptr_obj_pos_list_current_entry = prop->prev;
    }
    if (prop == ptr_obj_pos_list_first_entry)
    {
        ptr_obj_pos_list_first_entry = prop->next;
    }
    temp_v0 = prop->prev;
    if (temp_v0 != 0)
    {
        temp_v0->next = prop->next;
    }
    temp_v0_2 = prop->next;
    if (temp_v0_2 != 0)
    {
        temp_v0_2->prev = prop->prev;
    }
    prop->prev = NULL;
    prop->next = NULL;
}





void chrpropReparent(PropRecord *newChild, PropRecord *host)
{
    newChild->parent = host;

    // Link the newChild into its siblings
    if (host->child)
    {
        host->child->next = newChild;
    }
    newChild->prev = host->child;
    newChild->next = NULL;
    newChild->stan = NULL;
    host->child    = newChild;

}



void chrpropDetach(PropRecord* prop) {
    PropRecord* parent;
    PropRecord* prev;
    PropRecord* next;

    parent = prop->parent;
    if (parent) {
        if (prop == parent->child) {
            parent->child = prop->prev;
        }
        prev = prop->prev;
        if (prev) {
            prev->next = prop->next;
        }
        next = prop->next;
        if (next) {
            next->prev = prop->prev;
        }
        prop->parent = NULL;
        prop->prev = NULL;
        prop->next = NULL;
    }
}






/**
 * Address 0x7F03A62C.
*/
Gfx *chrpropRender(Gfx * gdl, PropRecord *prop, s32 withalpha)
{
    u8 type;

    type = prop->type;

    if (type == PROP_TYPE_CHR)
    {
        gdl = chrRenderProp(prop, gdl, withalpha);
    }
    else if ((type == PROP_TYPE_OBJ) || (type == PROP_TYPE_WEAPON) || (type == PROP_TYPE_DOOR))
    {
        gdl = chrobjRenderProp(prop, gdl, withalpha);
    }
    else if (type == PROP_TYPE_EXPLOSION)
    {
        gdl = explosionRenderPropExplosion(prop, gdl, withalpha);
    }
    else if (type == PROP_TYPE_SMOKE)
    {
        gdl = explosionRenderPropSmoke(prop, gdl, withalpha);
    }
    else if (type == PROP_TYPE_VIEWER)
    {
        gdl = bondviewRenderProp(prop, gdl, withalpha);
    }

    return gdl;
}




/**
 * Address 0x7F03A6F4.
*/
Gfx *chrpropsRenderPass(Gfx *gdl, s32 roomid, s32 renderpass)
{
    s32 flag;
    PropRecord **pp;
    PropRecord *prop;
    s32 i;
    s32* rp;
    s32 unused2;
    s32 sp48[PROPRECORD_STAN_ROOM_LEN];
    s32 unused3;
    s32 unused4;

    if (bossGetStageNum() == LEVELID_CUBA)
    {
        if (renderpass == 0)
        {
            return gdl;
        }
        else if (renderpass == 2)
        {
            renderpass = 0;
        }
    }

    if ((renderpass == 0) || (renderpass == 2))
    {
        for (pp = g_LastOnScreenProp; --pp >= g_OnScreenPropList; )
        {
            prop = *pp;

            if (prop != NULL)
            {
                flag = 0;

                if ((renderpass == 0) && ((prop->flags & 0x21) == 0))
                {
                    flag = 1;
                }
                else if ((renderpass == 2) && ((prop->flags & 0x21) == 1))
                {
                    flag = 1;
                }
    
                if (flag != 0)
                {
                    flag = 0;
                    chraiGetPropRoomIds(prop, sp48);
    
                    for (rp = sp48; *rp >= 0; rp++)
                    {
                        if (getROOMID_isRendered(*rp))
                        {
                            if (roomid == *rp)
                            {
                                flag = 1;
                            }

                            break;
                        }
                    }

                    if (flag)
                    {
                        gdl = chrpropRender(gdl, prop, 0);
                    }
                }
            }
        }
    }
    else
    {
        for (pp = g_OnScreenPropList; pp < g_LastOnScreenProp; pp++)
        {
            prop = *pp;

            if (prop != NULL)
            {
                flag = 0;
                chraiGetPropRoomIds(prop, sp48);

                for (rp = sp48; *rp >= 0; rp++)
                {
                    if (getROOMID_isRendered(*rp))
                    {
                        if (roomid == *rp)
                        {
                            flag = 1;
                        }

                        break;
                    }
                }

                if (flag)
                {
                    if (prop->flags & 0x20)
                    {
                        gdl = chrpropRender(gdl, prop, 0);
                    }

                    gdl = chrpropRender(gdl, prop, 1);
                }
            }
        }
    }

    return bgScissorCurrentPlayerViewDefault(gdl);
}




/**
 * Address 0x7F03A97C.
*/
s32 sub_GAME_7F03A97C(s32 index, coord3d* arg1, coord3d* arg2) {
    s32 sp2C[3];
    s32 sp20[3];
    s_room_info* temp_v0;

    temp_v0 = &g_BgRoomInfo[index];
    if (temp_v0->ptr_unique_collision_points != NULL) {
        sp20[0] = temp_v0->minbounds.f[0];
        sp20[1] = temp_v0->minbounds.f[1];
        sp20[2] = temp_v0->minbounds.f[2];
        sp2C[0] = temp_v0->maxbounds.f[0];
        sp2C[1] = temp_v0->maxbounds.f[1];
        sp2C[2] = temp_v0->maxbounds.f[2];
        if (bgTestLineIntersectsBbox(arg1, arg2, sp20, sp2C) != 0) {
            return 1;
        }
    }
    return 0;
}




#ifdef NONMATCHING
void sub_GAME_7F03AA44(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F03AA44
/* 06F574 7F03AA44 27BDFFA8 */  addiu $sp, $sp, -0x58
/* 06F578 7F03AA48 AFBF002C */  sw    $ra, 0x2c($sp)
/* 06F57C 7F03AA4C AFB30024 */  sw    $s3, 0x24($sp)
/* 06F580 7F03AA50 AFB20020 */  sw    $s2, 0x20($sp)
/* 06F584 7F03AA54 AFB1001C */  sw    $s1, 0x1c($sp)
/* 06F588 7F03AA58 00A08825 */  move  $s1, $a1
/* 06F58C 7F03AA5C 00C09025 */  move  $s2, $a2
/* 06F590 7F03AA60 00E09825 */  move  $s3, $a3
/* 06F594 7F03AA64 AFB40028 */  sw    $s4, 0x28($sp)
/* 06F598 7F03AA68 AFB00018 */  sw    $s0, 0x18($sp)
/* 06F59C 7F03AA6C 0FC2D20F */  jal   get_room_data_float1
/* 06F5A0 7F03AA70 AFA40058 */   sw    $a0, 0x58($sp)
/* 06F5A4 7F03AA74 0FC2D21E */  jal   bgGetLevelVisibilityScale
/* 06F5A8 7F03AA78 E7A00034 */   swc1  $f0, 0x34($sp)
/* 06F5AC 7F03AA7C C6440000 */  lwc1  $f4, ($s2)
/* 06F5B0 7F03AA80 C6260000 */  lwc1  $f6, ($s1)
/* 06F5B4 7F03AA84 24100001 */  li    $s0, 1
/* 06F5B8 7F03AA88 46062201 */  sub.s $f8, $f4, $f6
/* 06F5BC 7F03AA8C E7A80040 */  swc1  $f8, 0x40($sp)
/* 06F5C0 7F03AA90 C6300004 */  lwc1  $f16, 4($s1)
/* 06F5C4 7F03AA94 C64A0004 */  lwc1  $f10, 4($s2)
/* 06F5C8 7F03AA98 46105481 */  sub.s $f18, $f10, $f16
/* 06F5CC 7F03AA9C C7AA0034 */  lwc1  $f10, 0x34($sp)
/* 06F5D0 7F03AAA0 E7B20044 */  swc1  $f18, 0x44($sp)
/* 06F5D4 7F03AAA4 C6260008 */  lwc1  $f6, 8($s1)
/* 06F5D8 7F03AAA8 C6440008 */  lwc1  $f4, 8($s2)
/* 06F5DC 7F03AAAC 460A0082 */  mul.s $f2, $f0, $f10
/* 06F5E0 7F03AAB0 46062201 */  sub.s $f8, $f4, $f6
/* 06F5E4 7F03AAB4 E7A80048 */  swc1  $f8, 0x48($sp)
/* 06F5E8 7F03AAB8 C6300000 */  lwc1  $f16, ($s1)
/* 06F5EC 7F03AABC 46028482 */  mul.s $f18, $f16, $f2
/* 06F5F0 7F03AAC0 E7B2004C */  swc1  $f18, 0x4c($sp)
/* 06F5F4 7F03AAC4 C6240004 */  lwc1  $f4, 4($s1)
/* 06F5F8 7F03AAC8 46022182 */  mul.s $f6, $f4, $f2
/* 06F5FC 7F03AACC E7A60050 */  swc1  $f6, 0x50($sp)
/* 06F600 7F03AAD0 C6280008 */  lwc1  $f8, 8($s1)
/* 06F604 7F03AAD4 46024282 */  mul.s $f10, $f8, $f2
/* 06F608 7F03AAD8 0FC2D791 */  jal   getMaxNumRooms
/* 06F60C 7F03AADC E7AA0054 */   swc1  $f10, 0x54($sp)
/* 06F610 7F03AAE0 28410002 */  slti  $at, $v0, 2
/* 06F614 7F03AAE4 14200014 */  bnez  $at, .L7F03AB38
/* 06F618 7F03AAE8 02708821 */   addu  $s1, $s3, $s0
/* 06F61C 7F03AAEC 24140001 */  li    $s4, 1
/* 06F620 7F03AAF0 27B30040 */  addiu $s3, $sp, 0x40
/* 06F624 7F03AAF4 27B2004C */  addiu $s2, $sp, 0x4c
/* 06F628 7F03AAF8 922E0000 */  lbu   $t6, ($s1)
.L7F03AAFC:
/* 06F62C 7F03AAFC 02002025 */  move  $a0, $s0
/* 06F630 7F03AB00 02402825 */  move  $a1, $s2
/* 06F634 7F03AB04 55C00007 */  bnezl $t6, .L7F03AB24
/* 06F638 7F03AB08 26100001 */   addiu $s0, $s0, 1
/* 06F63C 7F03AB0C 0FC0EA5F */  jal   sub_GAME_7F03A97C
/* 06F640 7F03AB10 02603025 */   move  $a2, $s3
/* 06F644 7F03AB14 54400003 */  bnezl $v0, .L7F03AB24
/* 06F648 7F03AB18 26100001 */   addiu $s0, $s0, 1
/* 06F64C 7F03AB1C A2340000 */  sb    $s4, ($s1)
/* 06F650 7F03AB20 26100001 */  addiu $s0, $s0, 1
.L7F03AB24:
/* 06F654 7F03AB24 0FC2D791 */  jal   getMaxNumRooms
/* 06F658 7F03AB28 26310001 */   addiu $s1, $s1, 1
/* 06F65C 7F03AB2C 0202082A */  slt   $at, $s0, $v0
/* 06F660 7F03AB30 5420FFF2 */  bnezl $at, .L7F03AAFC
/* 06F664 7F03AB34 922E0000 */   lbu   $t6, ($s1)
.L7F03AB38:
/* 06F668 7F03AB38 8FBF002C */  lw    $ra, 0x2c($sp)
/* 06F66C 7F03AB3C 8FB00018 */  lw    $s0, 0x18($sp)
/* 06F670 7F03AB40 8FB1001C */  lw    $s1, 0x1c($sp)
/* 06F674 7F03AB44 8FB20020 */  lw    $s2, 0x20($sp)
/* 06F678 7F03AB48 8FB30024 */  lw    $s3, 0x24($sp)
/* 06F67C 7F03AB4C 8FB40028 */  lw    $s4, 0x28($sp)
/* 06F680 7F03AB50 03E00008 */  jr    $ra
/* 06F684 7F03AB54 27BD0058 */   addiu $sp, $sp, 0x58
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F03AB58(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F03AB58
/* 06F688 7F03AB58 27BDFDE0 */  addiu $sp, $sp, -0x220
/* 06F68C 7F03AB5C AFBF003C */  sw    $ra, 0x3c($sp)
/* 06F690 7F03AB60 AFB20024 */  sw    $s2, 0x24($sp)
/* 06F694 7F03AB64 00809025 */  move  $s2, $a0
/* 06F698 7F03AB68 AFB70038 */  sw    $s7, 0x38($sp)
/* 06F69C 7F03AB6C AFB60034 */  sw    $s6, 0x34($sp)
/* 06F6A0 7F03AB70 AFB50030 */  sw    $s5, 0x30($sp)
/* 06F6A4 7F03AB74 AFB4002C */  sw    $s4, 0x2c($sp)
/* 06F6A8 7F03AB78 AFB30028 */  sw    $s3, 0x28($sp)
/* 06F6AC 7F03AB7C AFB10020 */  sw    $s1, 0x20($sp)
/* 06F6B0 7F03AB80 AFB0001C */  sw    $s0, 0x1c($sp)
/* 06F6B4 7F03AB84 F7B40010 */  sdc1  $f20, 0x10($sp)
/* 06F6B8 7F03AB88 AFA50224 */  sw    $a1, 0x224($sp)
/* 06F6BC 7F03AB8C AFA60228 */  sw    $a2, 0x228($sp)
/* 06F6C0 7F03AB90 0FC2D20C */  jal   get_room_data_float2
/* 06F6C4 7F03AB94 AFA7022C */   sw    $a3, 0x22c($sp)
/* 06F6C8 7F03AB98 46000506 */  mov.s $f20, $f0
/* 06F6CC 7F03AB9C 27A40090 */  addiu $a0, $sp, 0x90
/* 06F6D0 7F03ABA0 0FC2E3A6 */  jal   sub_GAME_7F0B8E98
/* 06F6D4 7F03ABA4 24050064 */   li    $a1, 100
/* 06F6D8 7F03ABA8 18400085 */  blez  $v0, .L7F03ADC0
/* 06F6DC 7F03ABAC 27B00090 */   addiu $s0, $sp, 0x90
/* 06F6E0 7F03ABB0 00027880 */  sll   $t7, $v0, 2
/* 06F6E4 7F03ABB4 01F0A021 */  addu  $s4, $t7, $s0
/* 06F6E8 7F03ABB8 24170001 */  li    $s7, 1
/* 06F6EC 7F03ABBC 8FB60230 */  lw    $s6, 0x230($sp)
/* 06F6F0 7F03ABC0 27B30054 */  addiu $s3, $sp, 0x54
/* 06F6F4 7F03ABC4 8FB10234 */  lw    $s1, 0x234($sp)
/* 06F6F8 7F03ABC8 8E180000 */  lw    $t8, ($s0)
.L7F03ABCC:
/* 06F6FC 7F03ABCC 03161021 */  addu  $v0, $t8, $s6
/* 06F700 7F03ABD0 90590000 */  lbu   $t9, ($v0)
/* 06F704 7F03ABD4 57200077 */  bnezl $t9, .L7F03ADB4
/* 06F708 7F03ABD8 26100004 */   addiu $s0, $s0, 4
/* 06F70C 7F03ABDC A0570000 */  sb    $s7, ($v0)
/* 06F710 7F03ABE0 8FA60228 */  lw    $a2, 0x228($sp)
/* 06F714 7F03ABE4 8FA5022C */  lw    $a1, 0x22c($sp)
/* 06F718 7F03ABE8 0FC0EA5F */  jal   sub_GAME_7F03A97C
/* 06F71C 7F03ABEC 8E040000 */   lw    $a0, ($s0)
/* 06F720 7F03ABF0 1040006F */  beqz  $v0, .L7F03ADB0
/* 06F724 7F03ABF4 02402025 */   move  $a0, $s2
/* 06F728 7F03ABF8 8FA50224 */  lw    $a1, 0x224($sp)
/* 06F72C 7F03ABFC 8E060000 */  lw    $a2, ($s0)
/* 06F730 7F03AC00 0FC2DE9E */  jal   bgTestBulletHitBackground
/* 06F734 7F03AC04 02603825 */   move  $a3, $s3
/* 06F738 7F03AC08 10400069 */  beqz  $v0, .L7F03ADB0
/* 06F73C 7F03AC0C C7A40054 */   lwc1  $f4, 0x54($sp)
/* 06F740 7F03AC10 46142182 */  mul.s $f6, $f4, $f20
/* 06F744 7F03AC14 C7A80058 */  lwc1  $f8, 0x58($sp)
/* 06F748 7F03AC18 C7B0005C */  lwc1  $f16, 0x5c($sp)
/* 06F74C 7F03AC1C 8FA80238 */  lw    $t0, 0x238($sp)
/* 06F750 7F03AC20 46144282 */  mul.s $f10, $f8, $f20
/* 06F754 7F03AC24 8E020000 */  lw    $v0, ($s0)
/* 06F758 7F03AC28 02606025 */  move  $t4, $s3
/* 06F75C 7F03AC2C 46148482 */  mul.s $f18, $f16, $f20
/* 06F760 7F03AC30 E7A60054 */  swc1  $f6, 0x54($sp)
/* 06F764 7F03AC34 02206825 */  move  $t5, $s1
/* 06F768 7F03AC38 266B0030 */  addiu $t3, $s3, 0x30
/* 06F76C 7F03AC3C E7AA0058 */  swc1  $f10, 0x58($sp)
/* 06F770 7F03AC40 19000051 */  blez  $t0, .L7F03AD88
/* 06F774 7F03AC44 E7B2005C */   swc1  $f18, 0x5c($sp)
/* 06F778 7F03AC48 C6200000 */  lwc1  $f0, ($s1)
/* 06F77C 7F03AC4C C6420000 */  lwc1  $f2, ($s2)
/* 06F780 7F03AC50 4600103E */  c.le.s $f2, $f0
/* 06F784 7F03AC54 00000000 */  nop
/* 06F788 7F03AC58 4502000A */  bc1fl .L7F03AC84
/* 06F78C 7F03AC5C 4602003E */   c.le.s $f0, $f2
/* 06F790 7F03AC60 4606103E */  c.le.s $f2, $f6
/* 06F794 7F03AC64 00000000 */  nop
/* 06F798 7F03AC68 45020006 */  bc1fl .L7F03AC84
/* 06F79C 7F03AC6C 4602003E */   c.le.s $f0, $f2
/* 06F7A0 7F03AC70 4600303C */  c.lt.s $f6, $f0
/* 06F7A4 7F03AC74 00000000 */  nop
/* 06F7A8 7F03AC78 4503000E */  bc1tl .L7F03ACB4
/* 06F7AC 7F03AC7C C6200004 */   lwc1  $f0, 4($s1)
/* 06F7B0 7F03AC80 4602003E */  c.le.s $f0, $f2
.L7F03AC84:
/* 06F7B4 7F03AC84 C7A40054 */  lwc1  $f4, 0x54($sp)
/* 06F7B8 7F03AC88 4502004A */  bc1fl .L7F03ADB4
/* 06F7BC 7F03AC8C 26100004 */   addiu $s0, $s0, 4
/* 06F7C0 7F03AC90 4602203E */  c.le.s $f4, $f2
/* 06F7C4 7F03AC94 00000000 */  nop
/* 06F7C8 7F03AC98 45020046 */  bc1fl .L7F03ADB4
/* 06F7CC 7F03AC9C 26100004 */   addiu $s0, $s0, 4
/* 06F7D0 7F03ACA0 4604003C */  c.lt.s $f0, $f4
/* 06F7D4 7F03ACA4 00000000 */  nop
/* 06F7D8 7F03ACA8 45020042 */  bc1fl .L7F03ADB4
/* 06F7DC 7F03ACAC 26100004 */   addiu $s0, $s0, 4
/* 06F7E0 7F03ACB0 C6200004 */  lwc1  $f0, 4($s1)
.L7F03ACB4:
/* 06F7E4 7F03ACB4 C6420004 */  lwc1  $f2, 4($s2)
/* 06F7E8 7F03ACB8 C7A80058 */  lwc1  $f8, 0x58($sp)
/* 06F7EC 7F03ACBC 4600103E */  c.le.s $f2, $f0
/* 06F7F0 7F03ACC0 00000000 */  nop
/* 06F7F4 7F03ACC4 4502000A */  bc1fl .L7F03ACF0
/* 06F7F8 7F03ACC8 4602003E */   c.le.s $f0, $f2
/* 06F7FC 7F03ACCC 4608103E */  c.le.s $f2, $f8
/* 06F800 7F03ACD0 00000000 */  nop
/* 06F804 7F03ACD4 45020006 */  bc1fl .L7F03ACF0
/* 06F808 7F03ACD8 4602003E */   c.le.s $f0, $f2
/* 06F80C 7F03ACDC 4600403C */  c.lt.s $f8, $f0
/* 06F810 7F03ACE0 00000000 */  nop
/* 06F814 7F03ACE4 4503000E */  bc1tl .L7F03AD20
/* 06F818 7F03ACE8 C6200008 */   lwc1  $f0, 8($s1)
/* 06F81C 7F03ACEC 4602003E */  c.le.s $f0, $f2
.L7F03ACF0:
/* 06F820 7F03ACF0 C7AA0058 */  lwc1  $f10, 0x58($sp)
/* 06F824 7F03ACF4 4502002F */  bc1fl .L7F03ADB4
/* 06F828 7F03ACF8 26100004 */   addiu $s0, $s0, 4
/* 06F82C 7F03ACFC 4602503E */  c.le.s $f10, $f2
/* 06F830 7F03AD00 00000000 */  nop
/* 06F834 7F03AD04 4502002B */  bc1fl .L7F03ADB4
/* 06F838 7F03AD08 26100004 */   addiu $s0, $s0, 4
/* 06F83C 7F03AD0C 460A003C */  c.lt.s $f0, $f10
/* 06F840 7F03AD10 00000000 */  nop
/* 06F844 7F03AD14 45020027 */  bc1fl .L7F03ADB4
/* 06F848 7F03AD18 26100004 */   addiu $s0, $s0, 4
/* 06F84C 7F03AD1C C6200008 */  lwc1  $f0, 8($s1)
.L7F03AD20:
/* 06F850 7F03AD20 C6420008 */  lwc1  $f2, 8($s2)
/* 06F854 7F03AD24 C7B0005C */  lwc1  $f16, 0x5c($sp)
/* 06F858 7F03AD28 4600103E */  c.le.s $f2, $f0
/* 06F85C 7F03AD2C 00000000 */  nop
/* 06F860 7F03AD30 4502000A */  bc1fl .L7F03AD5C
/* 06F864 7F03AD34 4602003E */   c.le.s $f0, $f2
/* 06F868 7F03AD38 4610103E */  c.le.s $f2, $f16
/* 06F86C 7F03AD3C 00000000 */  nop
/* 06F870 7F03AD40 45020006 */  bc1fl .L7F03AD5C
/* 06F874 7F03AD44 4602003E */   c.le.s $f0, $f2
/* 06F878 7F03AD48 4600803C */  c.lt.s $f16, $f0
/* 06F87C 7F03AD4C 00000000 */  nop
/* 06F880 7F03AD50 4503000E */  bc1tl .L7F03AD8C
/* 06F884 7F03AD54 AFA20238 */   sw    $v0, 0x238($sp)
/* 06F888 7F03AD58 4602003E */  c.le.s $f0, $f2
.L7F03AD5C:
/* 06F88C 7F03AD5C C7B2005C */  lwc1  $f18, 0x5c($sp)
/* 06F890 7F03AD60 45020014 */  bc1fl .L7F03ADB4
/* 06F894 7F03AD64 26100004 */   addiu $s0, $s0, 4
/* 06F898 7F03AD68 4602903E */  c.le.s $f18, $f2
/* 06F89C 7F03AD6C 00000000 */  nop
/* 06F8A0 7F03AD70 45020010 */  bc1fl .L7F03ADB4
/* 06F8A4 7F03AD74 26100004 */   addiu $s0, $s0, 4
/* 06F8A8 7F03AD78 4612003C */  c.lt.s $f0, $f18
/* 06F8AC 7F03AD7C 00000000 */  nop
/* 06F8B0 7F03AD80 4502000C */  bc1fl .L7F03ADB4
/* 06F8B4 7F03AD84 26100004 */   addiu $s0, $s0, 4
.L7F03AD88:
/* 06F8B8 7F03AD88 AFA20238 */  sw    $v0, 0x238($sp)
.L7F03AD8C:
/* 06F8BC 7F03AD8C 8D810000 */  lw    $at, ($t4)
/* 06F8C0 7F03AD90 258C000C */  addiu $t4, $t4, 0xc
/* 06F8C4 7F03AD94 25AD000C */  addiu $t5, $t5, 0xc
/* 06F8C8 7F03AD98 ADA1FFF4 */  sw    $at, -0xc($t5)
/* 06F8CC 7F03AD9C 8D81FFF8 */  lw    $at, -8($t4)
/* 06F8D0 7F03ADA0 ADA1FFF8 */  sw    $at, -8($t5)
/* 06F8D4 7F03ADA4 8D81FFFC */  lw    $at, -4($t4)
/* 06F8D8 7F03ADA8 158BFFF8 */  bne   $t4, $t3, .L7F03AD8C
/* 06F8DC 7F03ADAC ADA1FFFC */   sw    $at, -4($t5)
.L7F03ADB0:
/* 06F8E0 7F03ADB0 26100004 */  addiu $s0, $s0, 4
.L7F03ADB4:
/* 06F8E4 7F03ADB4 0214082B */  sltu  $at, $s0, $s4
/* 06F8E8 7F03ADB8 5420FF84 */  bnezl $at, .L7F03ABCC
/* 06F8EC 7F03ADBC 8E180000 */   lw    $t8, ($s0)
.L7F03ADC0:
/* 06F8F0 7F03ADC0 8FBF003C */  lw    $ra, 0x3c($sp)
/* 06F8F4 7F03ADC4 8FA20238 */  lw    $v0, 0x238($sp)
/* 06F8F8 7F03ADC8 D7B40010 */  ldc1  $f20, 0x10($sp)
/* 06F8FC 7F03ADCC 8FB0001C */  lw    $s0, 0x1c($sp)
/* 06F900 7F03ADD0 8FB10020 */  lw    $s1, 0x20($sp)
/* 06F904 7F03ADD4 8FB20024 */  lw    $s2, 0x24($sp)
/* 06F908 7F03ADD8 8FB30028 */  lw    $s3, 0x28($sp)
/* 06F90C 7F03ADDC 8FB4002C */  lw    $s4, 0x2c($sp)
/* 06F910 7F03ADE0 8FB50030 */  lw    $s5, 0x30($sp)
/* 06F914 7F03ADE4 8FB60034 */  lw    $s6, 0x34($sp)
/* 06F918 7F03ADE8 8FB70038 */  lw    $s7, 0x38($sp)
/* 06F91C 7F03ADEC 03E00008 */  jr    $ra
/* 06F920 7F03ADF0 27BD0220 */   addiu $sp, $sp, 0x220
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F03ADF4(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F03ADF4
/* 06F924 7F03ADF4 27BDFD08 */  addiu $sp, $sp, -0x2f8
/* 06F928 7F03ADF8 AFBE0038 */  sw    $fp, 0x38($sp)
/* 06F92C 7F03ADFC AFB70034 */  sw    $s7, 0x34($sp)
/* 06F930 7F03AE00 AFB60030 */  sw    $s6, 0x30($sp)
/* 06F934 7F03AE04 AFB5002C */  sw    $s5, 0x2c($sp)
/* 06F938 7F03AE08 AFB40028 */  sw    $s4, 0x28($sp)
/* 06F93C 7F03AE0C AFB20020 */  sw    $s2, 0x20($sp)
/* 06F940 7F03AE10 AFB00018 */  sw    $s0, 0x18($sp)
/* 06F944 7F03AE14 AFBF003C */  sw    $ra, 0x3c($sp)
/* 06F948 7F03AE18 AFB30024 */  sw    $s3, 0x24($sp)
/* 06F94C 7F03AE1C AFB1001C */  sw    $s1, 0x1c($sp)
/* 06F950 7F03AE20 AFA502FC */  sw    $a1, 0x2fc($sp)
/* 06F954 7F03AE24 AFA60300 */  sw    $a2, 0x300($sp)
/* 06F958 7F03AE28 AFA70304 */  sw    $a3, 0x304($sp)
/* 06F95C 7F03AE2C A3A401F8 */  sb    $a0, 0x1f8($sp)
/* 06F960 7F03AE30 24100001 */  li    $s0, 1
/* 06F964 7F03AE34 27B20064 */  addiu $s2, $sp, 0x64
/* 06F968 7F03AE38 27B401F8 */  addiu $s4, $sp, 0x1f8
/* 06F96C 7F03AE3C 0000A825 */  move  $s5, $zero
/* 06F970 7F03AE40 27B601F8 */  addiu $s6, $sp, 0x1f8
/* 06F974 7F03AE44 8FB7030C */  lw    $s7, 0x30c($sp)
/* 06F978 7F03AE48 8FBE0308 */  lw    $fp, 0x308($sp)
.L7F03AE4C:
/* 06F97C 7F03AE4C 92D30000 */  lbu   $s3, ($s6)
/* 06F980 7F03AE50 240F0001 */  li    $t7, 1
/* 06F984 7F03AE54 03C02825 */  move  $a1, $fp
/* 06F988 7F03AE58 02F31021 */  addu  $v0, $s7, $s3
/* 06F98C 7F03AE5C 904E0000 */  lbu   $t6, ($v0)
/* 06F990 7F03AE60 02602025 */  move  $a0, $s3
/* 06F994 7F03AE64 55C0000F */  bnezl $t6, .L7F03AEA4
/* 06F998 7F03AE68 02602025 */   move  $a0, $s3
/* 06F99C 7F03AE6C A04F0000 */  sb    $t7, ($v0)
/* 06F9A0 7F03AE70 0FC0EA5F */  jal   sub_GAME_7F03A97C
/* 06F9A4 7F03AE74 8FA60304 */   lw    $a2, 0x304($sp)
/* 06F9A8 7F03AE78 10400009 */  beqz  $v0, .L7F03AEA0
/* 06F9AC 7F03AE7C 8FA402FC */   lw    $a0, 0x2fc($sp)
/* 06F9B0 7F03AE80 8FA50300 */  lw    $a1, 0x300($sp)
/* 06F9B4 7F03AE84 02603025 */  move  $a2, $s3
/* 06F9B8 7F03AE88 0FC2DE9E */  jal   bgTestBulletHitBackground
/* 06F9BC 7F03AE8C 8FA70310 */   lw    $a3, 0x310($sp)
/* 06F9C0 7F03AE90 50400004 */  beql  $v0, $zero, .L7F03AEA4
/* 06F9C4 7F03AE94 02602025 */   move  $a0, $s3
/* 06F9C8 7F03AE98 10000024 */  b     .L7F03AF2C
/* 06F9CC 7F03AE9C 02601025 */   move  $v0, $s3
.L7F03AEA0:
/* 06F9D0 7F03AEA0 02602025 */  move  $a0, $s3
.L7F03AEA4:
/* 06F9D4 7F03AEA4 02402825 */  move  $a1, $s2
/* 06F9D8 7F03AEA8 24060064 */  li    $a2, 100
/* 06F9DC 7F03AEAC 0FC2E3BF */  jal   sub_GAME_7F0B8EFC
/* 06F9E0 7F03AEB0 00008825 */   move  $s1, $zero
/* 06F9E4 7F03AEB4 18400018 */  blez  $v0, .L7F03AF18
/* 06F9E8 7F03AEB8 00402825 */   move  $a1, $v0
.L7F03AEBC:
/* 06F9EC 7F03AEBC 1A00000B */  blez  $s0, .L7F03AEEC
/* 06F9F0 7F03AEC0 00001825 */   move  $v1, $zero
/* 06F9F4 7F03AEC4 0011C080 */  sll   $t8, $s1, 2
/* 06F9F8 7F03AEC8 0258C821 */  addu  $t9, $s2, $t8
/* 06F9FC 7F03AECC 8F240000 */  lw    $a0, ($t9)
/* 06FA00 7F03AED0 27A201F8 */  addiu $v0, $sp, 0x1f8
.L7F03AED4:
/* 06FA04 7F03AED4 90480000 */  lbu   $t0, ($v0)
/* 06FA08 7F03AED8 11040004 */  beq   $t0, $a0, .L7F03AEEC
/* 06FA0C 7F03AEDC 00000000 */   nop
/* 06FA10 7F03AEE0 24630001 */  addiu $v1, $v1, 1
/* 06FA14 7F03AEE4 1470FFFB */  bne   $v1, $s0, .L7F03AED4
/* 06FA18 7F03AEE8 24420001 */   addiu $v0, $v0, 1
.L7F03AEEC:
/* 06FA1C 7F03AEEC 14700006 */  bne   $v1, $s0, .L7F03AF08
/* 06FA20 7F03AEF0 00114880 */   sll   $t1, $s1, 2
/* 06FA24 7F03AEF4 02495021 */  addu  $t2, $s2, $t1
/* 06FA28 7F03AEF8 8D4B0000 */  lw    $t3, ($t2)
/* 06FA2C 7F03AEFC 02906021 */  addu  $t4, $s4, $s0
/* 06FA30 7F03AF00 26100001 */  addiu $s0, $s0, 1
/* 06FA34 7F03AF04 A18B0000 */  sb    $t3, ($t4)
.L7F03AF08:
/* 06FA38 7F03AF08 26310001 */  addiu $s1, $s1, 1
/* 06FA3C 7F03AF0C 0225082A */  slt   $at, $s1, $a1
/* 06FA40 7F03AF10 1420FFEA */  bnez  $at, .L7F03AEBC
/* 06FA44 7F03AF14 00000000 */   nop
.L7F03AF18:
/* 06FA48 7F03AF18 26B50001 */  addiu $s5, $s5, 1
/* 06FA4C 7F03AF1C 02B0082A */  slt   $at, $s5, $s0
/* 06FA50 7F03AF20 1420FFCA */  bnez  $at, .L7F03AE4C
/* 06FA54 7F03AF24 26D60001 */   addiu $s6, $s6, 1
/* 06FA58 7F03AF28 00001025 */  move  $v0, $zero
.L7F03AF2C:
/* 06FA5C 7F03AF2C 8FBF003C */  lw    $ra, 0x3c($sp)
/* 06FA60 7F03AF30 8FB00018 */  lw    $s0, 0x18($sp)
/* 06FA64 7F03AF34 8FB1001C */  lw    $s1, 0x1c($sp)
/* 06FA68 7F03AF38 8FB20020 */  lw    $s2, 0x20($sp)
/* 06FA6C 7F03AF3C 8FB30024 */  lw    $s3, 0x24($sp)
/* 06FA70 7F03AF40 8FB40028 */  lw    $s4, 0x28($sp)
/* 06FA74 7F03AF44 8FB5002C */  lw    $s5, 0x2c($sp)
/* 06FA78 7F03AF48 8FB60030 */  lw    $s6, 0x30($sp)
/* 06FA7C 7F03AF4C 8FB70034 */  lw    $s7, 0x34($sp)
/* 06FA80 7F03AF50 8FBE0038 */  lw    $fp, 0x38($sp)
/* 06FA84 7F03AF54 03E00008 */  jr    $ra
/* 06FA88 7F03AF58 27BD02F8 */   addiu $sp, $sp, 0x2f8
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F03AF5C(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F03AF5C
/* 06FA8C 7F03AF5C 27BDFF40 */  addiu $sp, $sp, -0xc0
/* 06FA90 7F03AF60 F7BA0030 */  sdc1  $f26, 0x30($sp)
/* 06FA94 7F03AF64 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 06FA98 7F03AF68 AFBF0064 */  sw    $ra, 0x64($sp)
/* 06FA9C 7F03AF6C AFBE0060 */  sw    $fp, 0x60($sp)
/* 06FAA0 7F03AF70 AFB7005C */  sw    $s7, 0x5c($sp)
/* 06FAA4 7F03AF74 AFB3004C */  sw    $s3, 0x4c($sp)
/* 06FAA8 7F03AF78 4481D000 */  mtc1  $at, $f26
/* 06FAAC 7F03AF7C 00A09825 */  move  $s3, $a1
/* 06FAB0 7F03AF80 00E0F025 */  move  $fp, $a3
/* 06FAB4 7F03AF84 AFB60058 */  sw    $s6, 0x58($sp)
/* 06FAB8 7F03AF88 AFB50054 */  sw    $s5, 0x54($sp)
/* 06FABC 7F03AF8C AFB40050 */  sw    $s4, 0x50($sp)
/* 06FAC0 7F03AF90 AFB20048 */  sw    $s2, 0x48($sp)
/* 06FAC4 7F03AF94 AFB10044 */  sw    $s1, 0x44($sp)
/* 06FAC8 7F03AF98 AFB00040 */  sw    $s0, 0x40($sp)
/* 06FACC 7F03AF9C F7BC0038 */  sdc1  $f28, 0x38($sp)
/* 06FAD0 7F03AFA0 F7B80028 */  sdc1  $f24, 0x28($sp)
/* 06FAD4 7F03AFA4 F7B60020 */  sdc1  $f22, 0x20($sp)
/* 06FAD8 7F03AFA8 F7B40018 */  sdc1  $f20, 0x18($sp)
/* 06FADC 7F03AFAC AFA400C0 */  sw    $a0, 0xc0($sp)
/* 06FAE0 7F03AFB0 AFA600C8 */  sw    $a2, 0xc8($sp)
/* 06FAE4 7F03AFB4 0FC2D20C */  jal   get_room_data_float2
/* 06FAE8 7F03AFB8 0000B825 */   move  $s7, $zero
/* 06FAEC 7F03AFBC 46000606 */  mov.s $f24, $f0
/* 06FAF0 7F03AFC0 0FC2D791 */  jal   getMaxNumRooms
/* 06FAF4 7F03AFC4 24110001 */   li    $s1, 1
/* 06FAF8 7F03AFC8 28410002 */  slti  $at, $v0, 2
/* 06FAFC 7F03AFCC 14200051 */  bnez  $at, .L7F03B114
/* 06FB00 7F03AFD0 8FAE00D4 */   lw    $t6, 0xd4($sp)
/* 06FB04 7F03AFD4 3C014080 */  li    $at, 0x40800000 # 4.000000
/* 06FB08 7F03AFD8 4481E000 */  mtc1  $at, $f28
/* 06FB0C 7F03AFDC 01D19021 */  addu  $s2, $t6, $s1
/* 06FB10 7F03AFE0 27B60088 */  addiu $s6, $sp, 0x88
/* 06FB14 7F03AFE4 24150001 */  li    $s5, 1
/* 06FB18 7F03AFE8 8FB400D0 */  lw    $s4, 0xd0($sp)
/* 06FB1C 7F03AFEC 8FB000D8 */  lw    $s0, 0xd8($sp)
/* 06FB20 7F03AFF0 924F0000 */  lbu   $t7, ($s2)
.L7F03AFF4:
/* 06FB24 7F03AFF4 02202025 */  move  $a0, $s1
/* 06FB28 7F03AFF8 02802825 */  move  $a1, $s4
/* 06FB2C 7F03AFFC 15E0003F */  bnez  $t7, .L7F03B0FC
/* 06FB30 7F03B000 03C03025 */   move  $a2, $fp
/* 06FB34 7F03B004 0FC0EA5F */  jal   sub_GAME_7F03A97C
/* 06FB38 7F03B008 A2550000 */   sb    $s5, ($s2)
/* 06FB3C 7F03B00C 1040003B */  beqz  $v0, .L7F03B0FC
/* 06FB40 7F03B010 02602025 */   move  $a0, $s3
/* 06FB44 7F03B014 8FA500C8 */  lw    $a1, 0xc8($sp)
/* 06FB48 7F03B018 02203025 */  move  $a2, $s1
/* 06FB4C 7F03B01C 0FC2DE9E */  jal   bgTestBulletHitBackground
/* 06FB50 7F03B020 02C03825 */   move  $a3, $s6
/* 06FB54 7F03B024 10400035 */  beqz  $v0, .L7F03B0FC
/* 06FB58 7F03B028 C7A40088 */   lwc1  $f4, 0x88($sp)
/* 06FB5C 7F03B02C 46182182 */  mul.s $f6, $f4, $f24
/* 06FB60 7F03B030 C7AA008C */  lwc1  $f10, 0x8c($sp)
/* 06FB64 7F03B034 C6680000 */  lwc1  $f8, ($s3)
/* 06FB68 7F03B038 C7A40090 */  lwc1  $f4, 0x90($sp)
/* 06FB6C 7F03B03C 46185402 */  mul.s $f16, $f10, $f24
/* 06FB70 7F03B040 C6720004 */  lwc1  $f18, 4($s3)
/* 06FB74 7F03B044 87A400B2 */  lh    $a0, 0xb2($sp)
/* 06FB78 7F03B048 46083001 */  sub.s $f0, $f6, $f8
/* 06FB7C 7F03B04C 46182182 */  mul.s $f6, $f4, $f24
/* 06FB80 7F03B050 C6680008 */  lwc1  $f8, 8($s3)
/* 06FB84 7F03B054 46128081 */  sub.s $f2, $f16, $f18
/* 06FB88 7F03B058 46000282 */  mul.s $f10, $f0, $f0
/* 06FB8C 7F03B05C 00000000 */  nop
/* 06FB90 7F03B060 46021402 */  mul.s $f16, $f2, $f2
/* 06FB94 7F03B064 46083301 */  sub.s $f12, $f6, $f8
/* 06FB98 7F03B068 460C6102 */  mul.s $f4, $f12, $f12
/* 06FB9C 7F03B06C 46105480 */  add.s $f18, $f10, $f16
/* 06FBA0 7F03B070 46049580 */  add.s $f22, $f18, $f4
/* 06FBA4 7F03B074 0FC2ED8C */  jal   check_if_imageID_is_light
/* 06FBA8 7F03B078 4600B506 */   mov.s $f20, $f22
/* 06FBAC 7F03B07C 10400002 */  beqz  $v0, .L7F03B088
/* 06FBB0 7F03B080 C7A60088 */   lwc1  $f6, 0x88($sp)
/* 06FBB4 7F03B084 461CB501 */  sub.s $f20, $f22, $f28
.L7F03B088:
/* 06FBB8 7F03B088 461AA03C */  c.lt.s $f20, $f26
/* 06FBBC 7F03B08C 00000000 */  nop
/* 06FBC0 7F03B090 4502001B */  bc1fl .L7F03B100
/* 06FBC4 7F03B094 26310001 */   addiu $s1, $s1, 1
/* 06FBC8 7F03B098 E6060000 */  swc1  $f6, ($s0)
/* 06FBCC 7F03B09C C7A8008C */  lwc1  $f8, 0x8c($sp)
/* 06FBD0 7F03B0A0 4600A686 */  mov.s $f26, $f20
/* 06FBD4 7F03B0A4 0220B825 */  move  $s7, $s1
/* 06FBD8 7F03B0A8 E6080004 */  swc1  $f8, 4($s0)
/* 06FBDC 7F03B0AC C7AA0090 */  lwc1  $f10, 0x90($sp)
/* 06FBE0 7F03B0B0 E60A0008 */  swc1  $f10, 8($s0)
/* 06FBE4 7F03B0B4 C7B00094 */  lwc1  $f16, 0x94($sp)
/* 06FBE8 7F03B0B8 E610000C */  swc1  $f16, 0xc($s0)
/* 06FBEC 7F03B0BC C7B20098 */  lwc1  $f18, 0x98($sp)
/* 06FBF0 7F03B0C0 E6120010 */  swc1  $f18, 0x10($s0)
/* 06FBF4 7F03B0C4 C7A4009C */  lwc1  $f4, 0x9c($sp)
/* 06FBF8 7F03B0C8 E6040014 */  swc1  $f4, 0x14($s0)
/* 06FBFC 7F03B0CC 8FB800A0 */  lw    $t8, 0xa0($sp)
/* 06FC00 7F03B0D0 AE180018 */  sw    $t8, 0x18($s0)
/* 06FC04 7F03B0D4 8FB900A4 */  lw    $t9, 0xa4($sp)
/* 06FC08 7F03B0D8 AE19001C */  sw    $t9, 0x1c($s0)
/* 06FC0C 7F03B0DC 8FA800A8 */  lw    $t0, 0xa8($sp)
/* 06FC10 7F03B0E0 AE080020 */  sw    $t0, 0x20($s0)
/* 06FC14 7F03B0E4 87A900B2 */  lh    $t1, 0xb2($sp)
/* 06FC18 7F03B0E8 A609002A */  sh    $t1, 0x2a($s0)
/* 06FC1C 7F03B0EC 8FAA00AC */  lw    $t2, 0xac($sp)
/* 06FC20 7F03B0F0 AE0A0024 */  sw    $t2, 0x24($s0)
/* 06FC24 7F03B0F4 87AB00B0 */  lh    $t3, 0xb0($sp)
/* 06FC28 7F03B0F8 A60B0028 */  sh    $t3, 0x28($s0)
.L7F03B0FC:
/* 06FC2C 7F03B0FC 26310001 */  addiu $s1, $s1, 1
.L7F03B100:
/* 06FC30 7F03B100 0FC2D791 */  jal   getMaxNumRooms
/* 06FC34 7F03B104 26520001 */   addiu $s2, $s2, 1
/* 06FC38 7F03B108 0222082A */  slt   $at, $s1, $v0
/* 06FC3C 7F03B10C 5420FFB9 */  bnezl $at, .L7F03AFF4
/* 06FC40 7F03B110 924F0000 */   lbu   $t7, ($s2)
.L7F03B114:
/* 06FC44 7F03B114 8FBF0064 */  lw    $ra, 0x64($sp)
/* 06FC48 7F03B118 02E01025 */  move  $v0, $s7
/* 06FC4C 7F03B11C 8FB7005C */  lw    $s7, 0x5c($sp)
/* 06FC50 7F03B120 D7B40018 */  ldc1  $f20, 0x18($sp)
/* 06FC54 7F03B124 D7B60020 */  ldc1  $f22, 0x20($sp)
/* 06FC58 7F03B128 D7B80028 */  ldc1  $f24, 0x28($sp)
/* 06FC5C 7F03B12C D7BA0030 */  ldc1  $f26, 0x30($sp)
/* 06FC60 7F03B130 D7BC0038 */  ldc1  $f28, 0x38($sp)
/* 06FC64 7F03B134 8FB00040 */  lw    $s0, 0x40($sp)
/* 06FC68 7F03B138 8FB10044 */  lw    $s1, 0x44($sp)
/* 06FC6C 7F03B13C 8FB20048 */  lw    $s2, 0x48($sp)
/* 06FC70 7F03B140 8FB3004C */  lw    $s3, 0x4c($sp)
/* 06FC74 7F03B144 8FB40050 */  lw    $s4, 0x50($sp)
/* 06FC78 7F03B148 8FB50054 */  lw    $s5, 0x54($sp)
/* 06FC7C 7F03B14C 8FB60058 */  lw    $s6, 0x58($sp)
/* 06FC80 7F03B150 8FBE0060 */  lw    $fp, 0x60($sp)
/* 06FC84 7F03B154 03E00008 */  jr    $ra
/* 06FC88 7F03B158 27BD00C0 */   addiu $sp, $sp, 0xc0
)
#endif





#ifdef NONMATCHING
void chraiDefaultWeaponFireHandler(void) {

}
#else
GLOBAL_ASM(
.text
glabel chraiDefaultWeaponFireHandler
/* 06FC8C 7F03B15C 27BDFA88 */  addiu $sp, $sp, -0x578
/* 06FC90 7F03B160 AFBF0034 */  sw    $ra, 0x34($sp)
/* 06FC94 7F03B164 AFB00028 */  sw    $s0, 0x28($sp)
/* 06FC98 7F03B168 00808025 */  move  $s0, $a0
/* 06FC9C 7F03B16C AFB20030 */  sw    $s2, 0x30($sp)
/* 06FCA0 7F03B170 AFB1002C */  sw    $s1, 0x2c($sp)
/* 06FCA4 7F03B174 AFA0056C */  sw    $zero, 0x56c($sp)
/* 06FCA8 7F03B178 AFA0055C */  sw    $zero, 0x55c($sp)
/* 06FCAC 7F03B17C AFA00554 */  sw    $zero, 0x554($sp)
/* 06FCB0 7F03B180 0FC225E6 */  jal   get_curplayer_positiondata
/* 06FCB4 7F03B184 AFA00544 */   sw    $zero, 0x544($sp)
/* 06FCB8 7F03B188 8C4E0014 */  lw    $t6, 0x14($v0)
/* 06FCBC 7F03B18C 27B20194 */  addiu $s2, $sp, 0x194
/* 06FCC0 7F03B190 00408825 */  move  $s1, $v0
/* 06FCC4 7F03B194 AFA0018C */  sw    $zero, 0x18c($sp)
/* 06FCC8 7F03B198 02402025 */  move  $a0, $s2
/* 06FCCC 7F03B19C 27A501A0 */  addiu $a1, $sp, 0x1a0
/* 06FCD0 7F03B1A0 02003025 */  move  $a2, $s0
/* 06FCD4 7F03B1A4 0FC1A073 */  jal   bullet_path_from_screen_center
/* 06FCD8 7F03B1A8 AFAE04F8 */   sw    $t6, 0x4f8($sp)
/* 06FCDC 7F03B1AC 0FC17674 */  jal   getCurrentPlayerWeaponId
/* 06FCE0 7F03B1B0 02002025 */   move  $a0, $s0
/* 06FCE4 7F03B1B4 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 06FCE8 7F03B1B8 44812000 */  mtc1  $at, $f4
/* 06FCEC 7F03B1BC AFA201AC */  sw    $v0, 0x1ac($sp)
/* 06FCF0 7F03B1C0 27A204B4 */  addiu $v0, $sp, 0x4b4
/* 06FCF4 7F03B1C4 AFA001D0 */  sw    $zero, 0x1d0($sp)
/* 06FCF8 7F03B1C8 AFA001D4 */  sw    $zero, 0x1d4($sp)
/* 06FCFC 7F03B1CC AFA001D8 */  sw    $zero, 0x1d8($sp)
/* 06FD00 7F03B1D0 AFA00220 */  sw    $zero, 0x220($sp)
/* 06FD04 7F03B1D4 AFA00224 */  sw    $zero, 0x224($sp)
/* 06FD08 7F03B1D8 AFA00228 */  sw    $zero, 0x228($sp)
/* 06FD0C 7F03B1DC 27B00234 */  addiu $s0, $sp, 0x234
/* 06FD10 7F03B1E0 E7A401C8 */  swc1  $f4, 0x1c8($sp)
.L7F03B1E4:
/* 06FD14 7F03B1E4 26100140 */  addiu $s0, $s0, 0x140
/* 06FD18 7F03B1E8 AE00FF4C */  sw    $zero, -0xb4($s0)
/* 06FD1C 7F03B1EC AE00FF50 */  sw    $zero, -0xb0($s0)
/* 06FD20 7F03B1F0 AE00FF54 */  sw    $zero, -0xac($s0)
/* 06FD24 7F03B1F4 AE00FF9C */  sw    $zero, -0x64($s0)
/* 06FD28 7F03B1F8 AE00FFA0 */  sw    $zero, -0x60($s0)
/* 06FD2C 7F03B1FC AE00FFA4 */  sw    $zero, -0x5c($s0)
/* 06FD30 7F03B200 AE00FFEC */  sw    $zero, -0x14($s0)
/* 06FD34 7F03B204 AE00FFF0 */  sw    $zero, -0x10($s0)
/* 06FD38 7F03B208 AE00FFF4 */  sw    $zero, -0xc($s0)
/* 06FD3C 7F03B20C AE00FEFC */  sw    $zero, -0x104($s0)
/* 06FD40 7F03B210 AE00FF00 */  sw    $zero, -0x100($s0)
/* 06FD44 7F03B214 1602FFF3 */  bne   $s0, $v0, .L7F03B1E4
/* 06FD48 7F03B218 AE00FF04 */   sw    $zero, -0xfc($s0)
/* 06FD4C 7F03B21C C7A60194 */  lwc1  $f6, 0x194($sp)
/* 06FD50 7F03B220 C7A80198 */  lwc1  $f8, 0x198($sp)
/* 06FD54 7F03B224 C7AA019C */  lwc1  $f10, 0x19c($sp)
/* 06FD58 7F03B228 E7A601B0 */  swc1  $f6, 0x1b0($sp)
/* 06FD5C 7F03B22C E7A801B4 */  swc1  $f8, 0x1b4($sp)
/* 06FD60 7F03B230 0FC1E111 */  jal   currentPlayerGetMatrix10D4
/* 06FD64 7F03B234 E7AA01B8 */   swc1  $f10, 0x1b8($sp)
/* 06FD68 7F03B238 00402025 */  move  $a0, $v0
/* 06FD6C 7F03B23C 0FC1611D */  jal   mtx4TransformVecInPlace
/* 06FD70 7F03B240 27A501B0 */   addiu $a1, $sp, 0x1b0
/* 06FD74 7F03B244 C7B001A0 */  lwc1  $f16, 0x1a0($sp)
/* 06FD78 7F03B248 C7B201A4 */  lwc1  $f18, 0x1a4($sp)
/* 06FD7C 7F03B24C C7A401A8 */  lwc1  $f4, 0x1a8($sp)
/* 06FD80 7F03B250 E7B001BC */  swc1  $f16, 0x1bc($sp)
/* 06FD84 7F03B254 E7B201C0 */  swc1  $f18, 0x1c0($sp)
/* 06FD88 7F03B258 0FC1E111 */  jal   currentPlayerGetMatrix10D4
/* 06FD8C 7F03B25C E7A401C4 */   swc1  $f4, 0x1c4($sp)
/* 06FD90 7F03B260 00402025 */  move  $a0, $v0
/* 06FD94 7F03B264 0FC160F6 */  jal   mtx4RotateVecInPlace
/* 06FD98 7F03B268 27A501BC */   addiu $a1, $sp, 0x1bc
/* 06FD9C 7F03B26C 3C014780 */  li    $at, 0x47800000 # 65536.000000
/* 06FDA0 7F03B270 44810000 */  mtc1  $at, $f0
/* 06FDA4 7F03B274 C7A601BC */  lwc1  $f6, 0x1bc($sp)
/* 06FDA8 7F03B278 C7AA01B0 */  lwc1  $f10, 0x1b0($sp)
/* 06FDAC 7F03B27C C7B201C0 */  lwc1  $f18, 0x1c0($sp)
/* 06FDB0 7F03B280 46003202 */  mul.s $f8, $f6, $f0
/* 06FDB4 7F03B284 C7A601B4 */  lwc1  $f6, 0x1b4($sp)
/* 06FDB8 7F03B288 44075000 */  mfc1  $a3, $f10
/* 06FDBC 7F03B28C 46009102 */  mul.s $f4, $f18, $f0
/* 06FDC0 7F03B290 27A404F8 */  addiu $a0, $sp, 0x4f8
/* 06FDC4 7F03B294 460A4400 */  add.s $f16, $f8, $f10
/* 06FDC8 7F03B298 46062200 */  add.s $f8, $f4, $f6
/* 06FDCC 7F03B29C E7B004EC */  swc1  $f16, 0x4ec($sp)
/* 06FDD0 7F03B2A0 C7B001C4 */  lwc1  $f16, 0x1c4($sp)
/* 06FDD4 7F03B2A4 C7A401B8 */  lwc1  $f4, 0x1b8($sp)
/* 06FDD8 7F03B2A8 E7A804F0 */  swc1  $f8, 0x4f0($sp)
/* 06FDDC 7F03B2AC 46008482 */  mul.s $f18, $f16, $f0
/* 06FDE0 7F03B2B0 46049180 */  add.s $f6, $f18, $f4
/* 06FDE4 7F03B2B4 E7A604F4 */  swc1  $f6, 0x4f4($sp)
/* 06FDE8 7F03B2B8 8E260010 */  lw    $a2, 0x10($s1)
/* 06FDEC 7F03B2BC 8E250008 */  lw    $a1, 8($s1)
/* 06FDF0 7F03B2C0 0FC2C2F9 */  jal   walkTilesBetweenPoints_NoCallback
/* 06FDF4 7F03B2C4 E7A40010 */   swc1  $f4, 0x10($sp)
/* 06FDF8 7F03B2C8 504000B9 */  beql  $v0, $zero, .L7F03B5B0
/* 06FDFC 7F03B2CC 8FB901AC */   lw    $t9, 0x1ac($sp)
/* 06FE00 7F03B2D0 0FC2D20F */  jal   get_room_data_float1
/* 06FE04 7F03B2D4 00000000 */   nop
/* 06FE08 7F03B2D8 0FC2D21E */  jal   bgGetLevelVisibilityScale
/* 06FE0C 7F03B2DC E7A00048 */   swc1  $f0, 0x48($sp)
/* 06FE10 7F03B2E0 C7A20048 */  lwc1  $f2, 0x48($sp)
/* 06FE14 7F03B2E4 46020202 */  mul.s $f8, $f0, $f2
/* 06FE18 7F03B2E8 0FC227F5 */  jal   bondviewGetCurrentPlayersPosition
/* 06FE1C 7F03B2EC E7A8006C */   swc1  $f8, 0x6c($sp)
/* 06FE20 7F03B2F0 0FC2C731 */  jal   sub_GAME_7F0B1CC4
/* 06FE24 7F03B2F4 00408025 */   move  $s0, $v0
/* 06FE28 7F03B2F8 C7B004F4 */  lwc1  $f16, 0x4f4($sp)
/* 06FE2C 7F03B2FC 27A404F8 */  addiu $a0, $sp, 0x4f8
/* 06FE30 7F03B300 8FA501B0 */  lw    $a1, 0x1b0($sp)
/* 06FE34 7F03B304 8FA601B8 */  lw    $a2, 0x1b8($sp)
/* 06FE38 7F03B308 8FA704EC */  lw    $a3, 0x4ec($sp)
/* 06FE3C 7F03B30C 0FC2C2F9 */  jal   walkTilesBetweenPoints_NoCallback
/* 06FE40 7F03B310 E7B00010 */   swc1  $f16, 0x10($sp)
/* 06FE44 7F03B314 14400008 */  bnez  $v0, .L7F03B338
/* 06FE48 7F03B318 C7B204EC */   lwc1  $f18, 0x4ec($sp)
/* 06FE4C 7F03B31C 27A401B0 */  addiu $a0, $sp, 0x1b0
/* 06FE50 7F03B320 27A501BC */  addiu $a1, $sp, 0x1bc
/* 06FE54 7F03B324 0FC09893 */  jal   chrlvStanLineDirIntersection
/* 06FE58 7F03B328 27A60560 */   addiu $a2, $sp, 0x560
/* 06FE5C 7F03B32C 240F0001 */  li    $t7, 1
/* 06FE60 7F03B330 10000006 */  b     .L7F03B34C
/* 06FE64 7F03B334 AFAF056C */   sw    $t7, 0x56c($sp)
.L7F03B338:
/* 06FE68 7F03B338 C7A604F0 */  lwc1  $f6, 0x4f0($sp)
/* 06FE6C 7F03B33C C7AA04F4 */  lwc1  $f10, 0x4f4($sp)
/* 06FE70 7F03B340 E7B20560 */  swc1  $f18, 0x560($sp)
/* 06FE74 7F03B344 E7A60564 */  swc1  $f6, 0x564($sp)
/* 06FE78 7F03B348 E7AA0568 */  swc1  $f10, 0x568($sp)
.L7F03B34C:
/* 06FE7C 7F03B34C C7A40560 */  lwc1  $f4, 0x560($sp)
/* 06FE80 7F03B350 C6080000 */  lwc1  $f8, ($s0)
/* 06FE84 7F03B354 C7B20564 */  lwc1  $f18, 0x564($sp)
/* 06FE88 7F03B358 C7A0006C */  lwc1  $f0, 0x6c($sp)
/* 06FE8C 7F03B35C 46082401 */  sub.s $f16, $f4, $f8
/* 06FE90 7F03B360 C7A40568 */  lwc1  $f4, 0x568($sp)
/* 06FE94 7F03B364 8FA404F8 */  lw    $a0, 0x4f8($sp)
/* 06FE98 7F03B368 E7B00070 */  swc1  $f16, 0x70($sp)
/* 06FE9C 7F03B36C C6060004 */  lwc1  $f6, 4($s0)
/* 06FEA0 7F03B370 46069281 */  sub.s $f10, $f18, $f6
/* 06FEA4 7F03B374 E7AA0074 */  swc1  $f10, 0x74($sp)
/* 06FEA8 7F03B378 C6080008 */  lwc1  $f8, 8($s0)
/* 06FEAC 7F03B37C 46082401 */  sub.s $f16, $f4, $f8
/* 06FEB0 7F03B380 E7B00078 */  swc1  $f16, 0x78($sp)
/* 06FEB4 7F03B384 C6120000 */  lwc1  $f18, ($s0)
/* 06FEB8 7F03B388 46009182 */  mul.s $f6, $f18, $f0
/* 06FEBC 7F03B38C E7A6007C */  swc1  $f6, 0x7c($sp)
/* 06FEC0 7F03B390 C60A0004 */  lwc1  $f10, 4($s0)
/* 06FEC4 7F03B394 46005102 */  mul.s $f4, $f10, $f0
/* 06FEC8 7F03B398 E7A40080 */  swc1  $f4, 0x80($sp)
/* 06FECC 7F03B39C C6080008 */  lwc1  $f8, 8($s0)
/* 06FED0 7F03B3A0 AFA4055C */  sw    $a0, 0x55c($sp)
/* 06FED4 7F03B3A4 46004402 */  mul.s $f16, $f8, $f0
/* 06FED8 7F03B3A8 0FC2CBF6 */  jal   getTileRoom
/* 06FEDC 7F03B3AC E7B00084 */   swc1  $f16, 0x84($sp)
/* 06FEE0 7F03B3B0 00408825 */  move  $s1, $v0
/* 06FEE4 7F03B3B4 27A2018C */  addiu $v0, $sp, 0x18c
/* 06FEE8 7F03B3B8 27A3008C */  addiu $v1, $sp, 0x8c
.L7F03B3BC:
/* 06FEEC 7F03B3BC 24630004 */  addiu $v1, $v1, 4
/* 06FEF0 7F03B3C0 A060FFFD */  sb    $zero, -3($v1)
/* 06FEF4 7F03B3C4 A060FFFE */  sb    $zero, -2($v1)
/* 06FEF8 7F03B3C8 A060FFFF */  sb    $zero, -1($v1)
/* 06FEFC 7F03B3CC 1462FFFB */  bne   $v1, $v0, .L7F03B3BC
/* 06FF00 7F03B3D0 A060FFFC */   sb    $zero, -4($v1)
/* 06FF04 7F03B3D4 02002025 */  move  $a0, $s0
/* 06FF08 7F03B3D8 27A50560 */  addiu $a1, $sp, 0x560
/* 06FF0C 7F03B3DC 02203025 */  move  $a2, $s1
/* 06FF10 7F03B3E0 0FC2DE9E */  jal   bgTestBulletHitBackground
/* 06FF14 7F03B3E4 27A70510 */   addiu $a3, $sp, 0x510
/* 06FF18 7F03B3E8 10400002 */  beqz  $v0, .L7F03B3F4
/* 06FF1C 7F03B3EC 24190001 */   li    $t9, 1
/* 06FF20 7F03B3F0 AFB10544 */  sw    $s1, 0x544($sp)
.L7F03B3F4:
/* 06FF24 7F03B3F4 03B14021 */  addu  $t0, $sp, $s1
/* 06FF28 7F03B3F8 A119008C */  sb    $t9, 0x8c($t0)
/* 06FF2C 7F03B3FC 8FA90544 */  lw    $t1, 0x544($sp)
/* 06FF30 7F03B400 3C0A8008 */  lui   $t2, %hi(g_BgPortals)
/* 06FF34 7F03B404 5D200027 */  bgtzl $t1, .L7F03B4A4
/* 06FF38 7F03B408 8FA80544 */   lw    $t0, 0x544($sp)
/* 06FF3C 7F03B40C 8D4AFF80 */  lw    $t2, %lo(g_BgPortals)($t2)
/* 06FF40 7F03B410 8D4B0000 */  lw    $t3, ($t2)
/* 06FF44 7F03B414 11600012 */  beqz  $t3, .L7F03B460
/* 06FF48 7F03B418 00000000 */   nop
/* 06FF4C 7F03B41C 0FC225E6 */  jal   get_curplayer_positiondata
/* 06FF50 7F03B420 00000000 */   nop
/* 06FF54 7F03B424 0FC2CBF6 */  jal   getTileRoom
/* 06FF58 7F03B428 8C440014 */   lw    $a0, 0x14($v0)
/* 06FF5C 7F03B42C 27AC007C */  addiu $t4, $sp, 0x7c
/* 06FF60 7F03B430 27AD008C */  addiu $t5, $sp, 0x8c
/* 06FF64 7F03B434 27AE0510 */  addiu $t6, $sp, 0x510
/* 06FF68 7F03B438 AFAE0018 */  sw    $t6, 0x18($sp)
/* 06FF6C 7F03B43C AFAD0014 */  sw    $t5, 0x14($sp)
/* 06FF70 7F03B440 AFAC0010 */  sw    $t4, 0x10($sp)
/* 06FF74 7F03B444 00402025 */  move  $a0, $v0
/* 06FF78 7F03B448 02002825 */  move  $a1, $s0
/* 06FF7C 7F03B44C 27A60560 */  addiu $a2, $sp, 0x560
/* 06FF80 7F03B450 0FC0EB7D */  jal   sub_GAME_7F03ADF4
/* 06FF84 7F03B454 27A70070 */   addiu $a3, $sp, 0x70
/* 06FF88 7F03B458 10000011 */  b     .L7F03B4A0
/* 06FF8C 7F03B45C AFA20544 */   sw    $v0, 0x544($sp)
.L7F03B460:
/* 06FF90 7F03B460 0FC225E6 */  jal   get_curplayer_positiondata
/* 06FF94 7F03B464 00000000 */   nop
/* 06FF98 7F03B468 0FC2CBF6 */  jal   getTileRoom
/* 06FF9C 7F03B46C 8C440014 */   lw    $a0, 0x14($v0)
/* 06FFA0 7F03B470 27AF007C */  addiu $t7, $sp, 0x7c
/* 06FFA4 7F03B474 27B8008C */  addiu $t8, $sp, 0x8c
/* 06FFA8 7F03B478 27B90510 */  addiu $t9, $sp, 0x510
/* 06FFAC 7F03B47C AFB90018 */  sw    $t9, 0x18($sp)
/* 06FFB0 7F03B480 AFB80014 */  sw    $t8, 0x14($sp)
/* 06FFB4 7F03B484 AFAF0010 */  sw    $t7, 0x10($sp)
/* 06FFB8 7F03B488 00402025 */  move  $a0, $v0
/* 06FFBC 7F03B48C 02002825 */  move  $a1, $s0
/* 06FFC0 7F03B490 27A60560 */  addiu $a2, $sp, 0x560
/* 06FFC4 7F03B494 0FC0EBD7 */  jal   sub_GAME_7F03AF5C
/* 06FFC8 7F03B498 27A70070 */   addiu $a3, $sp, 0x70
/* 06FFCC 7F03B49C AFA20544 */  sw    $v0, 0x544($sp)
.L7F03B4A0:
/* 06FFD0 7F03B4A0 8FA80544 */  lw    $t0, 0x544($sp)
.L7F03B4A4:
/* 06FFD4 7F03B4A4 5900000F */  blezl $t0, .L7F03B4E4
/* 06FFD8 7F03B4A8 8FAB0544 */   lw    $t3, 0x544($sp)
/* 06FFDC 7F03B4AC 0FC2D20C */  jal   get_room_data_float2
/* 06FFE0 7F03B4B0 00000000 */   nop
/* 06FFE4 7F03B4B4 C7B20510 */  lwc1  $f18, 0x510($sp)
/* 06FFE8 7F03B4B8 C7AA0514 */  lwc1  $f10, 0x514($sp)
/* 06FFEC 7F03B4BC C7A80518 */  lwc1  $f8, 0x518($sp)
/* 06FFF0 7F03B4C0 46009182 */  mul.s $f6, $f18, $f0
/* 06FFF4 7F03B4C4 00000000 */  nop
/* 06FFF8 7F03B4C8 46005102 */  mul.s $f4, $f10, $f0
/* 06FFFC 7F03B4CC 00000000 */  nop
/* 070000 7F03B4D0 46004402 */  mul.s $f16, $f8, $f0
/* 070004 7F03B4D4 E7A60510 */  swc1  $f6, 0x510($sp)
/* 070008 7F03B4D8 E7A40514 */  swc1  $f4, 0x514($sp)
/* 07000C 7F03B4DC E7B00518 */  swc1  $f16, 0x518($sp)
/* 070010 7F03B4E0 8FAB0544 */  lw    $t3, 0x544($sp)
.L7F03B4E4:
/* 070014 7F03B4E4 27A9008C */  addiu $t1, $sp, 0x8c
/* 070018 7F03B4E8 27AA0510 */  addiu $t2, $sp, 0x510
/* 07001C 7F03B4EC AFAA0014 */  sw    $t2, 0x14($sp)
/* 070020 7F03B4F0 AFA90010 */  sw    $t1, 0x10($sp)
/* 070024 7F03B4F4 02002025 */  move  $a0, $s0
/* 070028 7F03B4F8 27A50560 */  addiu $a1, $sp, 0x560
/* 07002C 7F03B4FC 27A60070 */  addiu $a2, $sp, 0x70
/* 070030 7F03B500 27A7007C */  addiu $a3, $sp, 0x7c
/* 070034 7F03B504 0FC0EAD6 */  jal   sub_GAME_7F03AB58
/* 070038 7F03B508 AFAB0018 */   sw    $t3, 0x18($sp)
/* 07003C 7F03B50C 1840000F */  blez  $v0, .L7F03B54C
/* 070040 7F03B510 AFA20544 */   sw    $v0, 0x544($sp)
/* 070044 7F03B514 C7B20510 */  lwc1  $f18, 0x510($sp)
/* 070048 7F03B518 87AD053A */  lh    $t5, 0x53a($sp)
/* 07004C 7F03B51C C7B00514 */  lwc1  $f16, 0x514($sp)
/* 070050 7F03B520 C7AE0518 */  lwc1  $f14, 0x518($sp)
/* 070054 7F03B524 240C0001 */  li    $t4, 1
/* 070058 7F03B528 AFAC0554 */  sw    $t4, 0x554($sp)
/* 07005C 7F03B52C AFAD0540 */  sw    $t5, 0x540($sp)
/* 070060 7F03B530 E7B20548 */  swc1  $f18, 0x548($sp)
/* 070064 7F03B534 E7B20500 */  swc1  $f18, 0x500($sp)
/* 070068 7F03B538 E7B0054C */  swc1  $f16, 0x54c($sp)
/* 07006C 7F03B53C E7B00504 */  swc1  $f16, 0x504($sp)
/* 070070 7F03B540 E7AE0550 */  swc1  $f14, 0x550($sp)
/* 070074 7F03B544 1000000A */  b     .L7F03B570
/* 070078 7F03B548 E7AE0508 */   swc1  $f14, 0x508($sp)
.L7F03B54C:
/* 07007C 7F03B54C C7B204EC */  lwc1  $f18, 0x4ec($sp)
/* 070080 7F03B550 C7A604F0 */  lwc1  $f6, 0x4f0($sp)
/* 070084 7F03B554 C7AA04F4 */  lwc1  $f10, 0x4f4($sp)
/* 070088 7F03B558 240EFFFF */  li    $t6, -1
/* 07008C 7F03B55C AFB10544 */  sw    $s1, 0x544($sp)
/* 070090 7F03B560 AFAE0540 */  sw    $t6, 0x540($sp)
/* 070094 7F03B564 E7B20500 */  swc1  $f18, 0x500($sp)
/* 070098 7F03B568 E7A60504 */  swc1  $f6, 0x504($sp)
/* 07009C 7F03B56C E7AA0508 */  swc1  $f10, 0x508($sp)
.L7F03B570:
/* 0700A0 7F03B570 8FAF056C */  lw    $t7, 0x56c($sp)
/* 0700A4 7F03B574 8FB80554 */  lw    $t8, 0x554($sp)
/* 0700A8 7F03B578 15E00003 */  bnez  $t7, .L7F03B588
/* 0700AC 7F03B57C 00000000 */   nop
/* 0700B0 7F03B580 5300000B */  beql  $t8, $zero, .L7F03B5B0
/* 0700B4 7F03B584 8FB901AC */   lw    $t9, 0x1ac($sp)
.L7F03B588:
/* 0700B8 7F03B588 0FC1E0F1 */  jal   camGetWorldToScreenMtxf
/* 0700BC 7F03B58C 00000000 */   nop
/* 0700C0 7F03B590 00402025 */  move  $a0, $v0
/* 0700C4 7F03B594 0FC1611D */  jal   mtx4TransformVecInPlace
/* 0700C8 7F03B598 27A50500 */   addiu $a1, $sp, 0x500
/* 0700CC 7F03B59C C7A40508 */  lwc1  $f4, 0x508($sp)
/* 0700D0 7F03B5A0 46002207 */  neg.s $f8, $f4
/* 0700D4 7F03B5A4 E7A8050C */  swc1  $f8, 0x50c($sp)
/* 0700D8 7F03B5A8 E7A801C8 */  swc1  $f8, 0x1c8($sp)
/* 0700DC 7F03B5AC 8FB901AC */  lw    $t9, 0x1ac($sp)
.L7F03B5B0:
/* 0700E0 7F03B5B0 24010017 */  li    $at, 23
/* 0700E4 7F03B5B4 C7B201C8 */  lwc1  $f18, 0x1c8($sp)
/* 0700E8 7F03B5B8 1721000B */  bne   $t9, $at, .L7F03B5E8
/* 0700EC 7F03B5BC 3C118007 */   lui   $s1, %hi(g_LastOnScreenProp)
/* 0700F0 7F03B5C0 3C014396 */  li    $at, 0x43960000 # 300.000000
/* 0700F4 7F03B5C4 44818000 */  mtc1  $at, $f16
/* 0700F8 7F03B5C8 3C014396 */  li    $at, 0x43960000 # 300.000000
/* 0700FC 7F03B5CC 4612803C */  c.lt.s $f16, $f18
/* 070100 7F03B5D0 00000000 */  nop
/* 070104 7F03B5D4 45000004 */  bc1f  .L7F03B5E8
/* 070108 7F03B5D8 00000000 */   nop
/* 07010C 7F03B5DC 44813000 */  mtc1  $at, $f6
/* 070110 7F03B5E0 00000000 */  nop
/* 070114 7F03B5E4 E7A601C8 */  swc1  $f6, 0x1c8($sp)
.L7F03B5E8:
/* 070118 7F03B5E8 8E311DF0 */  lw    $s1, %lo(g_LastOnScreenProp)($s1)
/* 07011C 7F03B5EC 3C088007 */  lui   $t0, %hi(g_OnScreenPropList)
/* 070120 7F03B5F0 25081620 */  addiu $t0, %lo(g_OnScreenPropList) # addiu $t0, $t0, 0x1620
/* 070124 7F03B5F4 2631FFFC */  addiu $s1, $s1, -4
/* 070128 7F03B5F8 0228082B */  sltu  $at, $s1, $t0
/* 07012C 7F03B5FC 5420002A */  bnezl $at, .L7F03B6A8
/* 070130 7F03B600 27B00194 */   addiu $s0, $sp, 0x194
/* 070134 7F03B604 8E300000 */  lw    $s0, ($s1)
.L7F03B608:
/* 070138 7F03B608 12000020 */  beqz  $s0, .L7F03B68C
/* 07013C 7F03B60C 00000000 */   nop
/* 070140 7F03B610 92020000 */  lbu   $v0, ($s0)
/* 070144 7F03B614 24010003 */  li    $at, 3
/* 070148 7F03B618 1041000C */  beq   $v0, $at, .L7F03B64C
/* 07014C 7F03B61C 24010006 */   li    $at, 6
/* 070150 7F03B620 54410010 */  bnel  $v0, $at, .L7F03B664
/* 070154 7F03B624 92020000 */   lbu   $v0, ($s0)
/* 070158 7F03B628 8E090004 */  lw    $t1, 4($s0)
/* 07015C 7F03B62C 5120000D */  beql  $t1, $zero, .L7F03B664
/* 070160 7F03B630 92020000 */   lbu   $v0, ($s0)
/* 070164 7F03B634 0FC26C57 */  jal   getPlayerPointerIndex
/* 070168 7F03B638 02002025 */   move  $a0, $s0
/* 07016C 7F03B63C 0FC26C54 */  jal   get_cur_playernum
/* 070170 7F03B640 AFA2004C */   sw    $v0, 0x4c($sp)
/* 070174 7F03B644 8FAA004C */  lw    $t2, 0x4c($sp)
/* 070178 7F03B648 104A0005 */  beq   $v0, $t2, .L7F03B660
.L7F03B64C:
/* 07017C 7F03B64C 02002025 */   move  $a0, $s0
/* 070180 7F03B650 0FC08992 */  jal   sub_GAME_7F022648
/* 070184 7F03B654 02402825 */   move  $a1, $s2
/* 070188 7F03B658 1000000C */  b     .L7F03B68C
/* 07018C 7F03B65C 00000000 */   nop
.L7F03B660:
/* 070190 7F03B660 92020000 */  lbu   $v0, ($s0)
.L7F03B664:
/* 070194 7F03B664 24010001 */  li    $at, 1
/* 070198 7F03B668 02002025 */  move  $a0, $s0
/* 07019C 7F03B66C 10410005 */  beq   $v0, $at, .L7F03B684
/* 0701A0 7F03B670 24010004 */   li    $at, 4
/* 0701A4 7F03B674 10410003 */  beq   $v0, $at, .L7F03B684
/* 0701A8 7F03B678 24010002 */   li    $at, 2
/* 0701AC 7F03B67C 14410003 */  bne   $v0, $at, .L7F03B68C
/* 0701B0 7F03B680 00000000 */   nop
.L7F03B684:
/* 0701B4 7F03B684 0FC13A6F */  jal   sub_GAME_7F04E9BC
/* 0701B8 7F03B688 02402825 */   move  $a1, $s2
.L7F03B68C:
/* 0701BC 7F03B68C 3C0B8007 */  lui   $t3, %hi(g_OnScreenPropList)
/* 0701C0 7F03B690 256B1620 */  addiu $t3, %lo(g_OnScreenPropList) # addiu $t3, $t3, 0x1620
/* 0701C4 7F03B694 2631FFFC */  addiu $s1, $s1, -4
/* 0701C8 7F03B698 022B082B */  sltu  $at, $s1, $t3
/* 0701CC 7F03B69C 5020FFDA */  beql  $at, $zero, .L7F03B608
/* 0701D0 7F03B6A0 8E300000 */   lw    $s0, ($s1)
/* 0701D4 7F03B6A4 27B00194 */  addiu $s0, $sp, 0x194
.L7F03B6A8:
/* 0701D8 7F03B6A8 27B104B4 */  addiu $s1, $sp, 0x4b4
/* 0701DC 7F03B6AC 8E03003C */  lw    $v1, 0x3c($s0)
.L7F03B6B0:
/* 0701E0 7F03B6B0 50600024 */  beql  $v1, $zero, .L7F03B744
/* 0701E4 7F03B6B4 26100050 */   addiu $s0, $s0, 0x50
/* 0701E8 7F03B6B8 90620000 */  lbu   $v0, ($v1)
/* 0701EC 7F03B6BC 24010003 */  li    $at, 3
/* 0701F0 7F03B6C0 02402025 */  move  $a0, $s2
/* 0701F4 7F03B6C4 10410003 */  beq   $v0, $at, .L7F03B6D4
/* 0701F8 7F03B6C8 24010006 */   li    $at, 6
/* 0701FC 7F03B6CC 54410006 */  bnel  $v0, $at, .L7F03B6E8
/* 070200 7F03B6D0 24010001 */   li    $at, 1
.L7F03B6D4:
/* 070204 7F03B6D4 0FC08A60 */  jal   sub_GAME_7F022980
/* 070208 7F03B6D8 26050038 */   addiu $a1, $s0, 0x38
/* 07020C 7F03B6DC 1000000C */  b     .L7F03B710
/* 070210 7F03B6E0 8E0C0084 */   lw    $t4, 0x84($s0)
/* 070214 7F03B6E4 24010001 */  li    $at, 1
.L7F03B6E8:
/* 070218 7F03B6E8 10410006 */  beq   $v0, $at, .L7F03B704
/* 07021C 7F03B6EC 02402025 */   move  $a0, $s2
/* 070220 7F03B6F0 24010004 */  li    $at, 4
/* 070224 7F03B6F4 10410003 */  beq   $v0, $at, .L7F03B704
/* 070228 7F03B6F8 24010002 */   li    $at, 2
/* 07022C 7F03B6FC 54410004 */  bnel  $v0, $at, .L7F03B710
/* 070230 7F03B700 8E0C0084 */   lw    $t4, 0x84($s0)
.L7F03B704:
/* 070234 7F03B704 0FC13A9A */  jal   sub_GAME_7F04EA68
/* 070238 7F03B708 26050038 */   addiu $a1, $s0, 0x38
/* 07023C 7F03B70C 8E0C0084 */  lw    $t4, 0x84($s0)
.L7F03B710:
/* 070240 7F03B710 8FAD018C */  lw    $t5, 0x18c($sp)
/* 070244 7F03B714 1180000A */  beqz  $t4, .L7F03B740
/* 070248 7F03B718 25AE0001 */   addiu $t6, $t5, 1
/* 07024C 7F03B71C AFAE018C */  sw    $t6, 0x18c($sp)
/* 070250 7F03B720 0FC1780E */  jal   bondwalkItemGetObjectsShootThrough
/* 070254 7F03B724 8FA401AC */   lw    $a0, 0x1ac($sp)
/* 070258 7F03B728 8FAF018C */  lw    $t7, 0x18c($sp)
/* 07025C 7F03B72C 01E2082A */  slt   $at, $t7, $v0
/* 070260 7F03B730 54200004 */  bnezl $at, .L7F03B744
/* 070264 7F03B734 26100050 */   addiu $s0, $s0, 0x50
/* 070268 7F03B738 AFA00554 */  sw    $zero, 0x554($sp)
/* 07026C 7F03B73C AFA0056C */  sw    $zero, 0x56c($sp)
.L7F03B740:
/* 070270 7F03B740 26100050 */  addiu $s0, $s0, 0x50
.L7F03B744:
/* 070274 7F03B744 5611FFDA */  bnel  $s0, $s1, .L7F03B6B0
/* 070278 7F03B748 8E03003C */   lw    $v1, 0x3c($s0)
/* 07027C 7F03B74C 8FB80554 */  lw    $t8, 0x554($sp)
/* 070280 7F03B750 8FB9056C */  lw    $t9, 0x56c($sp)
/* 070284 7F03B754 8FA801AC */  lw    $t0, 0x1ac($sp)
/* 070288 7F03B758 17000002 */  bnez  $t8, .L7F03B764
/* 07028C 7F03B75C 24010017 */   li    $at, 23
/* 070290 7F03B760 13200091 */  beqz  $t9, .L7F03B9A8
.L7F03B764:
/* 070294 7F03B764 00008025 */   move  $s0, $zero
/* 070298 7F03B768 15010009 */  bne   $t0, $at, .L7F03B790
/* 07029C 7F03B76C 24110001 */   li    $s1, 1
/* 0702A0 7F03B770 3C014396 */  li    $at, 0x43960000 # 300.000000
/* 0702A4 7F03B774 44815000 */  mtc1  $at, $f10
/* 0702A8 7F03B778 C7A4050C */  lwc1  $f4, 0x50c($sp)
/* 0702AC 7F03B77C 4604503C */  c.lt.s $f10, $f4
/* 0702B0 7F03B780 00000000 */  nop
/* 0702B4 7F03B784 45020003 */  bc1fl .L7F03B794
/* 0702B8 7F03B788 8FA90554 */   lw    $t1, 0x554($sp)
/* 0702BC 7F03B78C 00008825 */  move  $s1, $zero
.L7F03B790:
/* 0702C0 7F03B790 8FA90554 */  lw    $t1, 0x554($sp)
.L7F03B794:
/* 0702C4 7F03B794 87AA053A */  lh    $t2, 0x53a($sp)
/* 0702C8 7F03B798 8FAC056C */  lw    $t4, 0x56c($sp)
/* 0702CC 7F03B79C 11200034 */  beqz  $t1, .L7F03B870
/* 0702D0 7F03B7A0 00000000 */   nop
/* 0702D4 7F03B7A4 05410004 */  bgez  $t2, .L7F03B7B8
/* 0702D8 7F03B7A8 87AB053A */   lh    $t3, 0x53a($sp)
/* 0702DC 7F03B7AC 3C108005 */  lui   $s0, %hi(D_8004E86C)
/* 0702E0 7F03B7B0 1000000A */  b     .L7F03B7DC
/* 0702E4 7F03B7B4 8E10E86C */   lw    $s0, %lo(D_8004E86C)($s0)
.L7F03B7B8:
/* 0702E8 7F03B7B8 000B60C0 */  sll   $t4, $t3, 3
/* 0702EC 7F03B7BC 3C0D8005 */  lui   $t5, %hi(g_Textures)
/* 0702F0 7F03B7C0 01AC6821 */  addu  $t5, $t5, $t4
/* 0702F4 7F03B7C4 91AD9300 */  lbu   $t5, %lo(g_Textures)($t5)
/* 0702F8 7F03B7C8 3C108005 */  lui   $s0, %hi(D_8004E86C)
/* 0702FC 7F03B7CC 31AE000F */  andi  $t6, $t5, 0xf
/* 070300 7F03B7D0 000E7880 */  sll   $t7, $t6, 2
/* 070304 7F03B7D4 020F8021 */  addu  $s0, $s0, $t7
/* 070308 7F03B7D8 8E10E86C */  lw    $s0, %lo(D_8004E86C)($s0)
.L7F03B7DC:
/* 07030C 7F03B7DC 12200022 */  beqz  $s1, .L7F03B868
/* 070310 7F03B7E0 00000000 */   nop
/* 070314 7F03B7E4 8618000A */  lh    $t8, 0xa($s0)
/* 070318 7F03B7E8 8FB901AC */  lw    $t9, 0x1ac($sp)
/* 07031C 7F03B7EC 24010017 */  li    $at, 23
/* 070320 7F03B7F0 1B000016 */  blez  $t8, .L7F03B84C
/* 070324 7F03B7F4 00000000 */   nop
/* 070328 7F03B7F8 13210014 */  beq   $t9, $at, .L7F03B84C
/* 07032C 7F03B7FC 00000000 */   nop
/* 070330 7F03B800 0C002914 */  jal   randomGetNext
/* 070334 7F03B804 00000000 */   nop
/* 070338 7F03B808 8608000A */  lh    $t0, 0xa($s0)
/* 07033C 7F03B80C 8E090004 */  lw    $t1, 4($s0)
/* 070340 7F03B810 240BFFFF */  li    $t3, -1
/* 070344 7F03B814 0048001B */  divu  $zero, $v0, $t0
/* 070348 7F03B818 00001810 */  mfhi  $v1
/* 07034C 7F03B81C 01235021 */  addu  $t2, $t1, $v1
/* 070350 7F03B820 91460000 */  lbu   $a2, ($t2)
/* 070354 7F03B824 15000002 */  bnez  $t0, .L7F03B830
/* 070358 7F03B828 00000000 */   nop
/* 07035C 7F03B82C 0007000D */  break 7
.L7F03B830:
/* 070360 7F03B830 AFA00018 */  sw    $zero, 0x18($sp)
/* 070364 7F03B834 AFAB0014 */  sw    $t3, 0x14($sp)
/* 070368 7F03B838 AFA00010 */  sw    $zero, 0x10($sp)
/* 07036C 7F03B83C 27A40548 */  addiu $a0, $sp, 0x548
/* 070370 7F03B840 27A5051C */  addiu $a1, $sp, 0x51c
/* 070374 7F03B844 0FC28423 */  jal   explosionCreateBulletImpact
/* 070378 7F03B848 87A70546 */   lh    $a3, 0x546($sp)
.L7F03B84C:
/* 07037C 7F03B84C 0FC2ED8C */  jal   check_if_imageID_is_light
/* 070380 7F03B850 87A4053A */   lh    $a0, 0x53a($sp)
/* 070384 7F03B854 10400004 */  beqz  $v0, .L7F03B868
/* 070388 7F03B858 8FA40534 */   lw    $a0, 0x534($sp)
/* 07038C 7F03B85C 87A50538 */  lh    $a1, 0x538($sp)
/* 070390 7F03B860 0FC2EF83 */  jal   sub_GAME_7F0BBE0C
/* 070394 7F03B864 8FA60544 */   lw    $a2, 0x544($sp)
.L7F03B868:
/* 070398 7F03B868 10000014 */  b     .L7F03B8BC
/* 07039C 7F03B86C 27B00548 */   addiu $s0, $sp, 0x548
.L7F03B870:
/* 0703A0 7F03B870 11800012 */  beqz  $t4, .L7F03B8BC
/* 0703A4 7F03B874 3C014780 */   li    $at, 0x47800000 # 65536.000000
/* 0703A8 7F03B878 44810000 */  mtc1  $at, $f0
/* 0703AC 7F03B87C C7A801BC */  lwc1  $f8, 0x1bc($sp)
/* 0703B0 7F03B880 C7B201B0 */  lwc1  $f18, 0x1b0($sp)
/* 0703B4 7F03B884 C7AA01C0 */  lwc1  $f10, 0x1c0($sp)
/* 0703B8 7F03B888 46004402 */  mul.s $f16, $f8, $f0
/* 0703BC 7F03B88C C7A801B4 */  lwc1  $f8, 0x1b4($sp)
/* 0703C0 7F03B890 27B00560 */  addiu $s0, $sp, 0x560
/* 0703C4 7F03B894 46005102 */  mul.s $f4, $f10, $f0
/* 0703C8 7F03B898 C7AA01B8 */  lwc1  $f10, 0x1b8($sp)
/* 0703CC 7F03B89C 46128180 */  add.s $f6, $f16, $f18
/* 0703D0 7F03B8A0 C7B201C4 */  lwc1  $f18, 0x1c4($sp)
/* 0703D4 7F03B8A4 46082400 */  add.s $f16, $f4, $f8
/* 0703D8 7F03B8A8 E7A60560 */  swc1  $f6, 0x560($sp)
/* 0703DC 7F03B8AC 46009182 */  mul.s $f6, $f18, $f0
/* 0703E0 7F03B8B0 E7B00564 */  swc1  $f16, 0x564($sp)
/* 0703E4 7F03B8B4 460A3100 */  add.s $f4, $f6, $f10
/* 0703E8 7F03B8B8 E7A40568 */  swc1  $f4, 0x568($sp)
.L7F03B8BC:
/* 0703EC 7F03B8BC 5200003B */  beql  $s0, $zero, .L7F03B9AC
/* 0703F0 7F03B8C0 8FBF0034 */   lw    $ra, 0x34($sp)
/* 0703F4 7F03B8C4 1220001D */  beqz  $s1, .L7F03B93C
/* 0703F8 7F03B8C8 8FA401AC */   lw    $a0, 0x1ac($sp)
/* 0703FC 7F03B8CC 02002825 */  move  $a1, $s0
/* 070400 7F03B8D0 0FC191DD */  jal   recall_joy2_hits_edit_flag
/* 070404 7F03B8D4 8FA60540 */   lw    $a2, 0x540($sp)
/* 070408 7F03B8D8 8FAD0540 */  lw    $t5, 0x540($sp)
/* 07040C 7F03B8DC 3C028005 */  lui   $v0, %hi(g_Textures)
/* 070410 7F03B8E0 24010005 */  li    $at, 5
/* 070414 7F03B8E4 000D70C0 */  sll   $t6, $t5, 3
/* 070418 7F03B8E8 004E1021 */  addu  $v0, $v0, $t6
/* 07041C 7F03B8EC 90429300 */  lbu   $v0, %lo(g_Textures)($v0)
/* 070420 7F03B8F0 304F000F */  andi  $t7, $v0, 0xf
/* 070424 7F03B8F4 11E10011 */  beq   $t7, $at, .L7F03B93C
/* 070428 7F03B8F8 24010006 */   li    $at, 6
/* 07042C 7F03B8FC 11E1000F */  beq   $t7, $at, .L7F03B93C
/* 070430 7F03B900 8FB80544 */   lw    $t8, 0x544($sp)
/* 070434 7F03B904 241900FF */  li    $t9, 255
/* 070438 7F03B908 A3B80050 */  sb    $t8, 0x50($sp)
/* 07043C 7F03B90C 0FC26C54 */  jal   get_cur_playernum
/* 070440 7F03B910 A3B90051 */   sb    $t9, 0x51($sp)
/* 070444 7F03B914 27A80050 */  addiu $t0, $sp, 0x50
/* 070448 7F03B918 AFA80018 */  sw    $t0, 0x18($sp)
/* 07044C 7F03B91C 00002025 */  move  $a0, $zero
/* 070450 7F03B920 02002825 */  move  $a1, $s0
/* 070454 7F03B924 8FA6055C */  lw    $a2, 0x55c($sp)
/* 070458 7F03B928 24070001 */  li    $a3, 1
/* 07045C 7F03B92C AFA00010 */  sw    $zero, 0x10($sp)
/* 070460 7F03B930 AFA20014 */  sw    $v0, 0x14($sp)
/* 070464 7F03B934 0FC27094 */  jal   explosionCreate
/* 070468 7F03B938 AFA0001C */   sw    $zero, 0x1c($sp)
.L7F03B93C:
/* 07046C 7F03B93C 3C0141D0 */  li    $at, 0x41D00000 # 26.000000
/* 070470 7F03B940 44810000 */  mtc1  $at, $f0
/* 070474 7F03B944 C7B001BC */  lwc1  $f16, 0x1bc($sp)
/* 070478 7F03B948 C6080000 */  lwc1  $f8, ($s0)
/* 07047C 7F03B94C C60A0004 */  lwc1  $f10, 4($s0)
/* 070480 7F03B950 46100482 */  mul.s $f18, $f0, $f16
/* 070484 7F03B954 02002025 */  move  $a0, $s0
/* 070488 7F03B958 46124181 */  sub.s $f6, $f8, $f18
/* 07048C 7F03B95C C6120008 */  lwc1  $f18, 8($s0)
/* 070490 7F03B960 E6060000 */  swc1  $f6, ($s0)
/* 070494 7F03B964 C7A401C0 */  lwc1  $f4, 0x1c0($sp)
/* 070498 7F03B968 46040402 */  mul.s $f16, $f0, $f4
/* 07049C 7F03B96C 46105201 */  sub.s $f8, $f10, $f16
/* 0704A0 7F03B970 E6080004 */  swc1  $f8, 4($s0)
/* 0704A4 7F03B974 C7A601C4 */  lwc1  $f6, 0x1c4($sp)
/* 0704A8 7F03B978 46060102 */  mul.s $f4, $f0, $f6
/* 0704AC 7F03B97C 46049281 */  sub.s $f10, $f18, $f4
/* 0704B0 7F03B980 0FC19ED3 */  jal   sub_GAME_7F067B4C
/* 0704B4 7F03B984 E60A0008 */   swc1  $f10, 8($s0)
/* 0704B8 7F03B988 3C0141D0 */  li    $at, 0x41D00000 # 26.000000
/* 0704BC 7F03B98C 44810000 */  mtc1  $at, $f0
/* 0704C0 7F03B990 12200005 */  beqz  $s1, .L7F03B9A8
/* 0704C4 7F03B994 02002025 */   move  $a0, $s0
/* 0704C8 7F03B998 44060000 */  mfc1  $a2, $f0
/* 0704CC 7F03B99C 24050001 */  li    $a1, 1
/* 0704D0 7F03B9A0 0FC28F87 */  jal   sub_GAME_7F0A3E1C
/* 0704D4 7F03B9A4 87A70546 */   lh    $a3, 0x546($sp)
.L7F03B9A8:
/* 0704D8 7F03B9A8 8FBF0034 */  lw    $ra, 0x34($sp)
.L7F03B9AC:
/* 0704DC 7F03B9AC 8FB00028 */  lw    $s0, 0x28($sp)
/* 0704E0 7F03B9B0 8FB1002C */  lw    $s1, 0x2c($sp)
/* 0704E4 7F03B9B4 8FB20030 */  lw    $s2, 0x30($sp)
/* 0704E8 7F03B9B8 03E00008 */  jr    $ra
/* 0704EC 7F03B9BC 27BD0578 */   addiu $sp, $sp, 0x578
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F03B9C0(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F03B9C0
/* 0704F0 7F03B9C0 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 0704F4 7F03B9C4 8FAE0054 */  lw    $t6, 0x54($sp)
/* 0704F8 7F03B9C8 44867000 */  mtc1  $a2, $f14
/* 0704FC 7F03B9CC AFBF0014 */  sw    $ra, 0x14($sp)
/* 070500 7F03B9D0 AFA40030 */  sw    $a0, 0x30($sp)
/* 070504 7F03B9D4 AFA50034 */  sw    $a1, 0x34($sp)
/* 070508 7F03B9D8 11C00091 */  beqz  $t6, .L7F03BC20
/* 07050C 7F03B9DC AFA7003C */   sw    $a3, 0x3c($sp)
/* 070510 7F03B9E0 44806000 */  mtc1  $zero, $f12
/* 070514 7F03B9E4 00003025 */  move  $a2, $zero
/* 070518 7F03B9E8 00002825 */  move  $a1, $zero
/* 07051C 7F03B9EC 00001825 */  move  $v1, $zero
/* 070520 7F03B9F0 00801025 */  move  $v0, $a0
/* 070524 7F03B9F4 46006086 */  mov.s $f2, $f12
.L7F03B9F8:
/* 070528 7F03B9F8 8C4F003C */  lw    $t7, 0x3c($v0)
/* 07052C 7F03B9FC 51E0000E */  beql  $t7, $zero, .L7F03BA38
/* 070530 7F03BA00 24630001 */   addiu $v1, $v1, 1
/* 070534 7F03BA04 8C580084 */  lw    $t8, 0x84($v0)
/* 070538 7F03BA08 5300000B */  beql  $t8, $zero, .L7F03BA38
/* 07053C 7F03BA0C 24630001 */   addiu $v1, $v1, 1
/* 070540 7F03BA10 C4400038 */  lwc1  $f0, 0x38($v0)
/* 070544 7F03BA14 24A50001 */  addiu $a1, $a1, 1
/* 070548 7F03BA18 4600103C */  c.lt.s $f2, $f0
/* 07054C 7F03BA1C 00000000 */  nop
/* 070550 7F03BA20 45020005 */  bc1fl .L7F03BA38
/* 070554 7F03BA24 24630001 */   addiu $v1, $v1, 1
/* 070558 7F03BA28 46001306 */  mov.s $f12, $f2
/* 07055C 7F03BA2C 46000086 */  mov.s $f2, $f0
/* 070560 7F03BA30 00603025 */  move  $a2, $v1
/* 070564 7F03BA34 24630001 */  addiu $v1, $v1, 1
.L7F03BA38:
/* 070568 7F03BA38 2861000A */  slti  $at, $v1, 0xa
/* 07056C 7F03BA3C 1420FFEE */  bnez  $at, .L7F03B9F8
/* 070570 7F03BA40 24420050 */   addiu $v0, $v0, 0x50
/* 070574 7F03BA44 8FB90030 */  lw    $t9, 0x30($sp)
/* 070578 7F03BA48 8F240018 */  lw    $a0, 0x18($t9)
/* 07057C 7F03BA4C E7AE0038 */  swc1  $f14, 0x38($sp)
/* 070580 7F03BA50 E7AC0020 */  swc1  $f12, 0x20($sp)
/* 070584 7F03BA54 AFA60024 */  sw    $a2, 0x24($sp)
/* 070588 7F03BA58 0FC1780E */  jal   bondwalkItemGetObjectsShootThrough
/* 07058C 7F03BA5C AFA5001C */   sw    $a1, 0x1c($sp)
/* 070590 7F03BA60 8FA5001C */  lw    $a1, 0x1c($sp)
/* 070594 7F03BA64 8FA60024 */  lw    $a2, 0x24($sp)
/* 070598 7F03BA68 8FA70030 */  lw    $a3, 0x30($sp)
/* 07059C 7F03BA6C 00A2082A */  slt   $at, $a1, $v0
/* 0705A0 7F03BA70 C7AC0020 */  lwc1  $f12, 0x20($sp)
/* 0705A4 7F03BA74 1420005A */  bnez  $at, .L7F03BBE0
/* 0705A8 7F03BA78 C7AE0038 */   lwc1  $f14, 0x38($sp)
/* 0705AC 7F03BA7C 00064080 */  sll   $t0, $a2, 2
/* 0705B0 7F03BA80 460E603C */  c.lt.s $f12, $f14
/* 0705B4 7F03BA84 01064021 */  addu  $t0, $t0, $a2
/* 0705B8 7F03BA88 00084100 */  sll   $t0, $t0, 4
/* 0705BC 7F03BA8C 00E84821 */  addu  $t1, $a3, $t0
/* 0705C0 7F03BA90 AD20003C */  sw    $zero, 0x3c($t1)
/* 0705C4 7F03BA94 45000002 */  bc1f  .L7F03BAA0
/* 0705C8 7F03BA98 E4EC0034 */   swc1  $f12, 0x34($a3)
/* 0705CC 7F03BA9C E4EE0034 */  swc1  $f14, 0x34($a3)
.L7F03BAA0:
/* 0705D0 7F03BAA0 8CEA003C */  lw    $t2, 0x3c($a3)
/* 0705D4 7F03BAA4 00E01025 */  move  $v0, $a3
/* 0705D8 7F03BAA8 240400A0 */  li    $a0, 160
/* 0705DC 7F03BAAC 1140000A */  beqz  $t2, .L7F03BAD8
/* 0705E0 7F03BAB0 24030320 */   li    $v1, 800
/* 0705E4 7F03BAB4 8C4B0084 */  lw    $t3, 0x84($v0)
/* 0705E8 7F03BAB8 55600008 */  bnezl $t3, .L7F03BADC
/* 0705EC 7F03BABC 8C4C008C */   lw    $t4, 0x8c($v0)
/* 0705F0 7F03BAC0 C4440038 */  lwc1  $f4, 0x38($v0)
/* 0705F4 7F03BAC4 4604603C */  c.lt.s $f12, $f4
/* 0705F8 7F03BAC8 00000000 */  nop
/* 0705FC 7F03BACC 45020003 */  bc1fl .L7F03BADC
/* 070600 7F03BAD0 8C4C008C */   lw    $t4, 0x8c($v0)
/* 070604 7F03BAD4 AC40003C */  sw    $zero, 0x3c($v0)
.L7F03BAD8:
/* 070608 7F03BAD8 8C4C008C */  lw    $t4, 0x8c($v0)
.L7F03BADC:
/* 07060C 7F03BADC 5180000B */  beql  $t4, $zero, .L7F03BB0C
/* 070610 7F03BAE0 24E200A0 */   addiu $v0, $a3, 0xa0
/* 070614 7F03BAE4 8C4D00D4 */  lw    $t5, 0xd4($v0)
/* 070618 7F03BAE8 55A00008 */  bnezl $t5, .L7F03BB0C
/* 07061C 7F03BAEC 24E200A0 */   addiu $v0, $a3, 0xa0
/* 070620 7F03BAF0 C4460088 */  lwc1  $f6, 0x88($v0)
/* 070624 7F03BAF4 4606603C */  c.lt.s $f12, $f6
/* 070628 7F03BAF8 00000000 */  nop
/* 07062C 7F03BAFC 45020003 */  bc1fl .L7F03BB0C
/* 070630 7F03BB00 24E200A0 */   addiu $v0, $a3, 0xa0
/* 070634 7F03BB04 AC40008C */  sw    $zero, 0x8c($v0)
/* 070638 7F03BB08 24E200A0 */  addiu $v0, $a3, 0xa0
.L7F03BB0C:
/* 07063C 7F03BB0C 8C4E003C */  lw    $t6, 0x3c($v0)
/* 070640 7F03BB10 24840140 */  addiu $a0, $a0, 0x140
/* 070644 7F03BB14 51C0000B */  beql  $t6, $zero, .L7F03BB44
/* 070648 7F03BB18 8C58008C */   lw    $t8, 0x8c($v0)
/* 07064C 7F03BB1C 8C4F0084 */  lw    $t7, 0x84($v0)
/* 070650 7F03BB20 55E00008 */  bnezl $t7, .L7F03BB44
/* 070654 7F03BB24 8C58008C */   lw    $t8, 0x8c($v0)
/* 070658 7F03BB28 C4480038 */  lwc1  $f8, 0x38($v0)
/* 07065C 7F03BB2C 4608603C */  c.lt.s $f12, $f8
/* 070660 7F03BB30 00000000 */  nop
/* 070664 7F03BB34 45020003 */  bc1fl .L7F03BB44
/* 070668 7F03BB38 8C58008C */   lw    $t8, 0x8c($v0)
/* 07066C 7F03BB3C AC40003C */  sw    $zero, 0x3c($v0)
/* 070670 7F03BB40 8C58008C */  lw    $t8, 0x8c($v0)
.L7F03BB44:
/* 070674 7F03BB44 5300000B */  beql  $t8, $zero, .L7F03BB74
/* 070678 7F03BB48 8C4800DC */   lw    $t0, 0xdc($v0)
/* 07067C 7F03BB4C 8C5900D4 */  lw    $t9, 0xd4($v0)
/* 070680 7F03BB50 57200008 */  bnezl $t9, .L7F03BB74
/* 070684 7F03BB54 8C4800DC */   lw    $t0, 0xdc($v0)
/* 070688 7F03BB58 C44A0088 */  lwc1  $f10, 0x88($v0)
/* 07068C 7F03BB5C 460A603C */  c.lt.s $f12, $f10
/* 070690 7F03BB60 00000000 */  nop
/* 070694 7F03BB64 45020003 */  bc1fl .L7F03BB74
/* 070698 7F03BB68 8C4800DC */   lw    $t0, 0xdc($v0)
/* 07069C 7F03BB6C AC40008C */  sw    $zero, 0x8c($v0)
/* 0706A0 7F03BB70 8C4800DC */  lw    $t0, 0xdc($v0)
.L7F03BB74:
/* 0706A4 7F03BB74 5100000B */  beql  $t0, $zero, .L7F03BBA4
/* 0706A8 7F03BB78 8C4A012C */   lw    $t2, 0x12c($v0)
/* 0706AC 7F03BB7C 8C490124 */  lw    $t1, 0x124($v0)
/* 0706B0 7F03BB80 55200008 */  bnezl $t1, .L7F03BBA4
/* 0706B4 7F03BB84 8C4A012C */   lw    $t2, 0x12c($v0)
/* 0706B8 7F03BB88 C45000D8 */  lwc1  $f16, 0xd8($v0)
/* 0706BC 7F03BB8C 4610603C */  c.lt.s $f12, $f16
/* 0706C0 7F03BB90 00000000 */  nop
/* 0706C4 7F03BB94 45020003 */  bc1fl .L7F03BBA4
/* 0706C8 7F03BB98 8C4A012C */   lw    $t2, 0x12c($v0)
/* 0706CC 7F03BB9C AC4000DC */  sw    $zero, 0xdc($v0)
/* 0706D0 7F03BBA0 8C4A012C */  lw    $t2, 0x12c($v0)
.L7F03BBA4:
/* 0706D4 7F03BBA4 1140000A */  beqz  $t2, .L7F03BBD0
/* 0706D8 7F03BBA8 00000000 */   nop
/* 0706DC 7F03BBAC 8C4B0174 */  lw    $t3, 0x174($v0)
/* 0706E0 7F03BBB0 15600007 */  bnez  $t3, .L7F03BBD0
/* 0706E4 7F03BBB4 00000000 */   nop
/* 0706E8 7F03BBB8 C4520128 */  lwc1  $f18, 0x128($v0)
/* 0706EC 7F03BBBC 4612603C */  c.lt.s $f12, $f18
/* 0706F0 7F03BBC0 00000000 */  nop
/* 0706F4 7F03BBC4 45000002 */  bc1f  .L7F03BBD0
/* 0706F8 7F03BBC8 00000000 */   nop
/* 0706FC 7F03BBCC AC40012C */  sw    $zero, 0x12c($v0)
.L7F03BBD0:
/* 070700 7F03BBD0 1483FFCE */  bne   $a0, $v1, .L7F03BB0C
/* 070704 7F03BBD4 24420140 */   addiu $v0, $v0, 0x140
/* 070708 7F03BBD8 10000012 */  b     .L7F03BC24
/* 07070C 7F03BBDC 8FAD0058 */   lw    $t5, 0x58($sp)
.L7F03BBE0:
/* 070710 7F03BBE0 8CE40018 */  lw    $a0, 0x18($a3)
/* 070714 7F03BBE4 E7AE0038 */  swc1  $f14, 0x38($sp)
/* 070718 7F03BBE8 0FC1780E */  jal   bondwalkItemGetObjectsShootThrough
/* 07071C 7F03BBEC AFA5001C */   sw    $a1, 0x1c($sp)
/* 070720 7F03BBF0 8FA5001C */  lw    $a1, 0x1c($sp)
/* 070724 7F03BBF4 8FA70030 */  lw    $a3, 0x30($sp)
/* 070728 7F03BBF8 C7AE0038 */  lwc1  $f14, 0x38($sp)
/* 07072C 7F03BBFC 24AC0001 */  addiu $t4, $a1, 1
/* 070730 7F03BC00 55820008 */  bnel  $t4, $v0, .L7F03BC24
/* 070734 7F03BC04 8FAD0058 */   lw    $t5, 0x58($sp)
/* 070738 7F03BC08 C4E40034 */  lwc1  $f4, 0x34($a3)
/* 07073C 7F03BC0C 4604703C */  c.lt.s $f14, $f4
/* 070740 7F03BC10 00000000 */  nop
/* 070744 7F03BC14 45020003 */  bc1fl .L7F03BC24
/* 070748 7F03BC18 8FAD0058 */   lw    $t5, 0x58($sp)
/* 07074C 7F03BC1C E4EE0034 */  swc1  $f14, 0x34($a3)
.L7F03BC20:
/* 070750 7F03BC20 8FAD0058 */  lw    $t5, 0x58($sp)
.L7F03BC24:
/* 070754 7F03BC24 8FAE0030 */  lw    $t6, 0x30($sp)
/* 070758 7F03BC28 51A00048 */  beql  $t5, $zero, .L7F03BD4C
/* 07075C 7F03BC2C 00002025 */   move  $a0, $zero
/* 070760 7F03BC30 8DC20018 */  lw    $v0, 0x18($t6)
/* 070764 7F03BC34 24010012 */  li    $at, 18
/* 070768 7F03BC38 10410043 */  beq   $v0, $at, .L7F03BD48
/* 07076C 7F03BC3C 24010014 */   li    $at, 20
/* 070770 7F03BC40 50410042 */  beql  $v0, $at, .L7F03BD4C
/* 070774 7F03BC44 00002025 */   move  $a0, $zero
/* 070778 7F03BC48 8DC3003C */  lw    $v1, 0x3c($t6)
/* 07077C 7F03BC4C 01C01025 */  move  $v0, $t6
/* 070780 7F03BC50 50600008 */  beql  $v1, $zero, .L7F03BC74
/* 070784 7F03BC54 8C4F008C */   lw    $t7, 0x8c($v0)
/* 070788 7F03BC58 C5C60038 */  lwc1  $f6, 0x38($t6)
/* 07078C 7F03BC5C 4606703C */  c.lt.s $f14, $f6
/* 070790 7F03BC60 00000000 */  nop
/* 070794 7F03BC64 45020003 */  bc1fl .L7F03BC74
/* 070798 7F03BC68 8C4F008C */   lw    $t7, 0x8c($v0)
/* 07079C 7F03BC6C ADC0003C */  sw    $zero, 0x3c($t6)
/* 0707A0 7F03BC70 8C4F008C */  lw    $t7, 0x8c($v0)
.L7F03BC74:
/* 0707A4 7F03BC74 51E00008 */  beql  $t7, $zero, .L7F03BC98
/* 0707A8 7F03BC78 8FA20030 */   lw    $v0, 0x30($sp)
/* 0707AC 7F03BC7C C4480088 */  lwc1  $f8, 0x88($v0)
/* 0707B0 7F03BC80 4608703C */  c.lt.s $f14, $f8
/* 0707B4 7F03BC84 00000000 */  nop
/* 0707B8 7F03BC88 45020003 */  bc1fl .L7F03BC98
/* 0707BC 7F03BC8C 8FA20030 */   lw    $v0, 0x30($sp)
/* 0707C0 7F03BC90 AC40008C */  sw    $zero, 0x8c($v0)
/* 0707C4 7F03BC94 8FA20030 */  lw    $v0, 0x30($sp)
.L7F03BC98:
/* 0707C8 7F03BC98 240400A0 */  li    $a0, 160
/* 0707CC 7F03BC9C 24030320 */  li    $v1, 800
/* 0707D0 7F03BCA0 244200A0 */  addiu $v0, $v0, 0xa0
.L7F03BCA4:
/* 0707D4 7F03BCA4 8C58003C */  lw    $t8, 0x3c($v0)
/* 0707D8 7F03BCA8 24840140 */  addiu $a0, $a0, 0x140
/* 0707DC 7F03BCAC 53000008 */  beql  $t8, $zero, .L7F03BCD0
/* 0707E0 7F03BCB0 8C59008C */   lw    $t9, 0x8c($v0)
/* 0707E4 7F03BCB4 C44A0038 */  lwc1  $f10, 0x38($v0)
/* 0707E8 7F03BCB8 460A703C */  c.lt.s $f14, $f10
/* 0707EC 7F03BCBC 00000000 */  nop
/* 0707F0 7F03BCC0 45020003 */  bc1fl .L7F03BCD0
/* 0707F4 7F03BCC4 8C59008C */   lw    $t9, 0x8c($v0)
/* 0707F8 7F03BCC8 AC40003C */  sw    $zero, 0x3c($v0)
/* 0707FC 7F03BCCC 8C59008C */  lw    $t9, 0x8c($v0)
.L7F03BCD0:
/* 070800 7F03BCD0 53200008 */  beql  $t9, $zero, .L7F03BCF4
/* 070804 7F03BCD4 8C4800DC */   lw    $t0, 0xdc($v0)
/* 070808 7F03BCD8 C4500088 */  lwc1  $f16, 0x88($v0)
/* 07080C 7F03BCDC 4610703C */  c.lt.s $f14, $f16
/* 070810 7F03BCE0 00000000 */  nop
/* 070814 7F03BCE4 45020003 */  bc1fl .L7F03BCF4
/* 070818 7F03BCE8 8C4800DC */   lw    $t0, 0xdc($v0)
/* 07081C 7F03BCEC AC40008C */  sw    $zero, 0x8c($v0)
/* 070820 7F03BCF0 8C4800DC */  lw    $t0, 0xdc($v0)
.L7F03BCF4:
/* 070824 7F03BCF4 51000008 */  beql  $t0, $zero, .L7F03BD18
/* 070828 7F03BCF8 8C49012C */   lw    $t1, 0x12c($v0)
/* 07082C 7F03BCFC C45200D8 */  lwc1  $f18, 0xd8($v0)
/* 070830 7F03BD00 4612703C */  c.lt.s $f14, $f18
/* 070834 7F03BD04 00000000 */  nop
/* 070838 7F03BD08 45020003 */  bc1fl .L7F03BD18
/* 07083C 7F03BD0C 8C49012C */   lw    $t1, 0x12c($v0)
/* 070840 7F03BD10 AC4000DC */  sw    $zero, 0xdc($v0)
/* 070844 7F03BD14 8C49012C */  lw    $t1, 0x12c($v0)
.L7F03BD18:
/* 070848 7F03BD18 11200007 */  beqz  $t1, .L7F03BD38
/* 07084C 7F03BD1C 00000000 */   nop
/* 070850 7F03BD20 C4440128 */  lwc1  $f4, 0x128($v0)
/* 070854 7F03BD24 4604703C */  c.lt.s $f14, $f4
/* 070858 7F03BD28 00000000 */  nop
/* 07085C 7F03BD2C 45000002 */  bc1f  .L7F03BD38
/* 070860 7F03BD30 00000000 */   nop
/* 070864 7F03BD34 AC40012C */  sw    $zero, 0x12c($v0)
.L7F03BD38:
/* 070868 7F03BD38 1483FFDA */  bne   $a0, $v1, .L7F03BCA4
/* 07086C 7F03BD3C 24420140 */   addiu $v0, $v0, 0x140
/* 070870 7F03BD40 8FAA0030 */  lw    $t2, 0x30($sp)
/* 070874 7F03BD44 E54E0034 */  swc1  $f14, 0x34($t2)
.L7F03BD48:
/* 070878 7F03BD48 00002025 */  move  $a0, $zero
.L7F03BD4C:
/* 07087C 7F03BD4C 8FA20030 */  lw    $v0, 0x30($sp)
/* 070880 7F03BD50 24030320 */  li    $v1, 800
.L7F03BD54:
/* 070884 7F03BD54 8C4B003C */  lw    $t3, 0x3c($v0)
/* 070888 7F03BD58 24840050 */  addiu $a0, $a0, 0x50
/* 07088C 7F03BD5C 1560001D */  bnez  $t3, .L7F03BDD4
/* 070890 7F03BD60 00000000 */   nop
/* 070894 7F03BD64 E44E0038 */  swc1  $f14, 0x38($v0)
/* 070898 7F03BD68 8FAC0034 */  lw    $t4, 0x34($sp)
/* 07089C 7F03BD6C 00404025 */  move  $t0, $v0
/* 0708A0 7F03BD70 AC4C003C */  sw    $t4, 0x3c($v0)
/* 0708A4 7F03BD74 8FAD003C */  lw    $t5, 0x3c($sp)
/* 0708A8 7F03BD78 AC4D0040 */  sw    $t5, 0x40($v0)
/* 0708AC 7F03BD7C 8FAE0040 */  lw    $t6, 0x40($sp)
/* 0708B0 7F03BD80 AC4E0044 */  sw    $t6, 0x44($v0)
/* 0708B4 7F03BD84 8FAF0044 */  lw    $t7, 0x44($sp)
/* 0708B8 7F03BD88 25F90030 */  addiu $t9, $t7, 0x30
.L7F03BD8C:
/* 0708BC 7F03BD8C 8DE10000 */  lw    $at, ($t7)
/* 0708C0 7F03BD90 25EF000C */  addiu $t7, $t7, 0xc
/* 0708C4 7F03BD94 2508000C */  addiu $t0, $t0, 0xc
/* 0708C8 7F03BD98 AD01003C */  sw    $at, 0x3c($t0)
/* 0708CC 7F03BD9C 8DE1FFF8 */  lw    $at, -8($t7)
/* 0708D0 7F03BDA0 AD010040 */  sw    $at, 0x40($t0)
/* 0708D4 7F03BDA4 8DE1FFFC */  lw    $at, -4($t7)
/* 0708D8 7F03BDA8 15F9FFF8 */  bne   $t7, $t9, .L7F03BD8C
/* 0708DC 7F03BDAC AD010044 */   sw    $at, 0x44($t0)
/* 0708E0 7F03BDB0 8FA90048 */  lw    $t1, 0x48($sp)
/* 0708E4 7F03BDB4 AC490078 */  sw    $t1, 0x78($v0)
/* 0708E8 7F03BDB8 8FAA004C */  lw    $t2, 0x4c($sp)
/* 0708EC 7F03BDBC AC4A007C */  sw    $t2, 0x7c($v0)
/* 0708F0 7F03BDC0 8FAB0050 */  lw    $t3, 0x50($sp)
/* 0708F4 7F03BDC4 AC4B0080 */  sw    $t3, 0x80($v0)
/* 0708F8 7F03BDC8 8FAC0054 */  lw    $t4, 0x54($sp)
/* 0708FC 7F03BDCC 10000003 */  b     .L7F03BDDC
/* 070900 7F03BDD0 AC4C0084 */   sw    $t4, 0x84($v0)
.L7F03BDD4:
/* 070904 7F03BDD4 1483FFDF */  bne   $a0, $v1, .L7F03BD54
/* 070908 7F03BDD8 24420050 */   addiu $v0, $v0, 0x50
.L7F03BDDC:
/* 07090C 7F03BDDC 8FBF0014 */  lw    $ra, 0x14($sp)
/* 070910 7F03BDE0 27BD0030 */  addiu $sp, $sp, 0x30
/* 070914 7F03BDE4 03E00008 */  jr    $ra
/* 070918 7F03BDE8 00000000 */   nop
)
#endif





#ifdef NONMATCHING
void chraiFistAttackHandler(void) {

}
#else
GLOBAL_ASM(
.text
glabel chraiFistAttackHandler
/* 07091C 7F03BDEC 27BDFF38 */  addiu $sp, $sp, -0xc8
/* 070920 7F03BDF0 AFBF0064 */  sw    $ra, 0x64($sp)
/* 070924 7F03BDF4 AFB60060 */  sw    $s6, 0x60($sp)
/* 070928 7F03BDF8 00A0B025 */  move  $s6, $a1
/* 07092C 7F03BDFC AFB5005C */  sw    $s5, 0x5c($sp)
/* 070930 7F03BE00 AFB40058 */  sw    $s4, 0x58($sp)
/* 070934 7F03BE04 AFB30054 */  sw    $s3, 0x54($sp)
/* 070938 7F03BE08 AFB20050 */  sw    $s2, 0x50($sp)
/* 07093C 7F03BE0C AFB1004C */  sw    $s1, 0x4c($sp)
/* 070940 7F03BE10 AFB00048 */  sw    $s0, 0x48($sp)
/* 070944 7F03BE14 F7B80040 */  sdc1  $f24, 0x40($sp)
/* 070948 7F03BE18 F7B60038 */  sdc1  $f22, 0x38($sp)
/* 07094C 7F03BE1C F7B40030 */  sdc1  $f20, 0x30($sp)
/* 070950 7F03BE20 AFA400C8 */  sw    $a0, 0xc8($sp)
/* 070954 7F03BE24 0FC225E6 */  jal   get_curplayer_positiondata
/* 070958 7F03BE28 AFA000BC */   sw    $zero, 0xbc($sp)
/* 07095C 7F03BE2C 3C048008 */  lui   $a0, %hi(g_CurrentPlayer)
/* 070960 7F03BE30 0040A025 */  move  $s4, $v0
/* 070964 7F03BE34 0FC225E0 */  jal   bondviewGetPlayerDuckingHeightRelated
/* 070968 7F03BE38 8C84A0B0 */   lw    $a0, %lo(g_CurrentPlayer)($a0)
/* 07096C 7F03BE3C 3C138007 */  lui   $s3, %hi(g_LastOnScreenProp)
/* 070970 7F03BE40 8E731DF0 */  lw    $s3, %lo(g_LastOnScreenProp)($s3)
/* 070974 7F03BE44 3C0E8007 */  lui   $t6, %hi(g_OnScreenPropList)
/* 070978 7F03BE48 25CE1620 */  addiu $t6, %lo(g_OnScreenPropList) # addiu $t6, $t6, 0x1620
/* 07097C 7F03BE4C 2673FFFC */  addiu $s3, $s3, -4
/* 070980 7F03BE50 026E082B */  sltu  $at, $s3, $t6
/* 070984 7F03BE54 1420008F */  bnez  $at, .L7F03C094
/* 070988 7F03BE58 46000606 */   mov.s $f24, $f0
/* 07098C 7F03BE5C 4480B000 */  mtc1  $zero, $f22
/* 070990 7F03BE60 27B50078 */  addiu $s5, $sp, 0x78
/* 070994 7F03BE64 8E700000 */  lw    $s0, ($s3)
.L7F03BE68:
/* 070998 7F03BE68 3C0143FA */  li    $at, 0x43FA0000 # 500.000000
/* 07099C 7F03BE6C 12000083 */  beqz  $s0, .L7F03C07C
/* 0709A0 7F03BE70 00000000 */   nop
/* 0709A4 7F03BE74 C6040018 */  lwc1  $f4, 0x18($s0)
/* 0709A8 7F03BE78 44813000 */  mtc1  $at, $f6
/* 0709AC 7F03BE7C 00000000 */  nop
/* 0709B0 7F03BE80 4606203C */  c.lt.s $f4, $f6
/* 0709B4 7F03BE84 00000000 */  nop
/* 0709B8 7F03BE88 4500007C */  bc1f  .L7F03C07C
/* 0709BC 7F03BE8C 00000000 */   nop
/* 0709C0 7F03BE90 92020000 */  lbu   $v0, ($s0)
/* 0709C4 7F03BE94 24010003 */  li    $at, 3
/* 0709C8 7F03BE98 1041000B */  beq   $v0, $at, .L7F03BEC8
/* 0709CC 7F03BE9C 24010006 */   li    $at, 6
/* 0709D0 7F03BEA0 14410076 */  bne   $v0, $at, .L7F03C07C
/* 0709D4 7F03BEA4 00000000 */   nop
/* 0709D8 7F03BEA8 8E0F0004 */  lw    $t7, 4($s0)
/* 0709DC 7F03BEAC 11E00073 */  beqz  $t7, .L7F03C07C
/* 0709E0 7F03BEB0 00000000 */   nop
/* 0709E4 7F03BEB4 0FC26C57 */  jal   getPlayerPointerIndex
/* 0709E8 7F03BEB8 02002025 */   move  $a0, $s0
/* 0709EC 7F03BEBC 0FC26C54 */  jal   get_cur_playernum
/* 0709F0 7F03BEC0 00408825 */   move  $s1, $v0
/* 0709F4 7F03BEC4 1051006D */  beq   $v0, $s1, .L7F03C07C
.L7F03BEC8:
/* 0709F8 7F03BEC8 3C014248 */   li    $at, 0x42480000 # 50.000000
/* 0709FC 7F03BECC 4481A000 */  mtc1  $at, $f20
/* 070A00 7F03BED0 0FC1741E */  jal   getCurrentWeaponOrItem
/* 070A04 7F03BED4 8E120004 */   lw    $s2, 4($s0)
/* 070A08 7F03BED8 24010011 */  li    $at, 17
/* 070A0C 7F03BEDC 14410004 */  bne   $v0, $at, .L7F03BEF0
/* 070A10 7F03BEE0 27A500AC */   addiu $a1, $sp, 0xac
/* 070A14 7F03BEE4 3C0142C8 */  li    $at, 0x42C80000 # 100.000000
/* 070A18 7F03BEE8 4481A000 */  mtc1  $at, $f20
/* 070A1C 7F03BEEC 00000000 */  nop
.L7F03BEF0:
/* 070A20 7F03BEF0 8E44001C */  lw    $a0, 0x1c($s2)
/* 070A24 7F03BEF4 27A600A8 */  addiu $a2, $sp, 0xa8
/* 070A28 7F03BEF8 0FC0FDD2 */  jal   sub_GAME_7F03F748
/* 070A2C 7F03BEFC 00003825 */   move  $a3, $zero
/* 070A30 7F03BF00 C7A800AC */  lwc1  $f8, 0xac($sp)
/* 070A34 7F03BF04 C7AA00A8 */  lwc1  $f10, 0xa8($sp)
/* 070A38 7F03BF08 4608B03E */  c.le.s $f22, $f8
/* 070A3C 7F03BF0C 00000000 */  nop
/* 070A40 7F03BF10 4500005A */  bc1f  .L7F03C07C
/* 070A44 7F03BF14 00000000 */   nop
/* 070A48 7F03BF18 4616503E */  c.le.s $f10, $f22
/* 070A4C 7F03BF1C 27A500A4 */  addiu $a1, $sp, 0xa4
/* 070A50 7F03BF20 27A600A0 */  addiu $a2, $sp, 0xa0
/* 070A54 7F03BF24 24070001 */  li    $a3, 1
/* 070A58 7F03BF28 45000054 */  bc1f  .L7F03C07C
/* 070A5C 7F03BF2C 00000000 */   nop
/* 070A60 7F03BF30 0FC0FDD2 */  jal   sub_GAME_7F03F748
/* 070A64 7F03BF34 8E44001C */   lw    $a0, 0x1c($s2)
/* 070A68 7F03BF38 C7B000A4 */  lwc1  $f16, 0xa4($sp)
/* 070A6C 7F03BF3C C7B200A0 */  lwc1  $f18, 0xa0($sp)
/* 070A70 7F03BF40 4610B03E */  c.le.s $f22, $f16
/* 070A74 7F03BF44 00000000 */  nop
/* 070A78 7F03BF48 4500004C */  bc1f  .L7F03C07C
/* 070A7C 7F03BF4C 00000000 */   nop
/* 070A80 7F03BF50 4616903E */  c.le.s $f18, $f22
/* 070A84 7F03BF54 27A5009C */  addiu $a1, $sp, 0x9c
/* 070A88 7F03BF58 27A60098 */  addiu $a2, $sp, 0x98
/* 070A8C 7F03BF5C 24070002 */  li    $a3, 2
/* 070A90 7F03BF60 45000046 */  bc1f  .L7F03C07C
/* 070A94 7F03BF64 00000000 */   nop
/* 070A98 7F03BF68 0FC0FDD2 */  jal   sub_GAME_7F03F748
/* 070A9C 7F03BF6C 8E44001C */   lw    $a0, 0x1c($s2)
/* 070AA0 7F03BF70 C7A40098 */  lwc1  $f4, 0x98($sp)
/* 070AA4 7F03BF74 C7A6009C */  lwc1  $f6, 0x9c($sp)
/* 070AA8 7F03BF78 4616203E */  c.le.s $f4, $f22
/* 070AAC 7F03BF7C 00000000 */  nop
/* 070AB0 7F03BF80 4500003E */  bc1f  .L7F03C07C
/* 070AB4 7F03BF84 00000000 */   nop
/* 070AB8 7F03BF88 4600A207 */  neg.s $f8, $f20
/* 070ABC 7F03BF8C 27A40090 */  addiu $a0, $sp, 0x90
/* 070AC0 7F03BF90 4606403E */  c.le.s $f8, $f6
/* 070AC4 7F03BF94 24190013 */  li    $t9, 19
/* 070AC8 7F03BF98 45000038 */  bc1f  .L7F03C07C
/* 070ACC 7F03BF9C 00000000 */   nop
/* 070AD0 7F03BFA0 8E980014 */  lw    $t8, 0x14($s4)
/* 070AD4 7F03BFA4 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 070AD8 7F03BFA8 44818000 */  mtc1  $at, $f16
/* 070ADC 7F03BFAC AFB80090 */  sw    $t8, 0x90($sp)
/* 070AE0 7F03BFB0 C60A0010 */  lwc1  $f10, 0x10($s0)
/* 070AE4 7F03BFB4 8E070008 */  lw    $a3, 8($s0)
/* 070AE8 7F03BFB8 8E860010 */  lw    $a2, 0x10($s4)
/* 070AEC 7F03BFBC 8E850008 */  lw    $a1, 8($s4)
/* 070AF0 7F03BFC0 E7B60020 */  swc1  $f22, 0x20($sp)
/* 070AF4 7F03BFC4 E7B8001C */  swc1  $f24, 0x1c($sp)
/* 070AF8 7F03BFC8 E7B80018 */  swc1  $f24, 0x18($sp)
/* 070AFC 7F03BFCC AFB90014 */  sw    $t9, 0x14($sp)
/* 070B00 7F03BFD0 E7B00024 */  swc1  $f16, 0x24($sp)
/* 070B04 7F03BFD4 0FC2C389 */  jal   stanTestLineUnobstructed
/* 070B08 7F03BFD8 E7AA0010 */   swc1  $f10, 0x10($sp)
/* 070B0C 7F03BFDC 10400027 */  beqz  $v0, .L7F03C07C
/* 070B10 7F03BFE0 8FA80090 */   lw    $t0, 0x90($sp)
/* 070B14 7F03BFE4 8E090014 */  lw    $t1, 0x14($s0)
/* 070B18 7F03BFE8 15090024 */  bne   $t0, $t1, .L7F03C07C
/* 070B1C 7F03BFEC 00000000 */   nop
/* 070B20 7F03BFF0 0FC1E67C */  jal   currentPlayerGetCrouchPos
/* 070B24 7F03BFF4 2411000F */   li    $s1, 15
/* 070B28 7F03BFF8 24010001 */  li    $at, 1
/* 070B2C 7F03BFFC 14410003 */  bne   $v0, $at, .L7F03C00C
/* 070B30 7F03C000 00000000 */   nop
/* 070B34 7F03C004 10000006 */  b     .L7F03C020
/* 070B38 7F03C008 241100C8 */   li    $s1, 200
.L7F03C00C:
/* 070B3C 7F03C00C 0FC1E67C */  jal   currentPlayerGetCrouchPos
/* 070B40 7F03C010 00000000 */   nop
/* 070B44 7F03C014 54400003 */  bnezl $v0, .L7F03C024
/* 070B48 7F03C018 27A40084 */   addiu $a0, $sp, 0x84
/* 070B4C 7F03C01C 241100C9 */  li    $s1, 201
.L7F03C020:
/* 070B50 7F03C020 27A40084 */  addiu $a0, $sp, 0x84
.L7F03C024:
/* 070B54 7F03C024 02A02825 */  move  $a1, $s5
/* 070B58 7F03C028 0FC1A073 */  jal   bullet_path_from_screen_center
/* 070B5C 7F03C02C 8FA600C8 */   lw    $a2, 0xc8($sp)
/* 070B60 7F03C030 0FC1E111 */  jal   currentPlayerGetMatrix10D4
/* 070B64 7F03C034 00000000 */   nop
/* 070B68 7F03C038 00402025 */  move  $a0, $v0
/* 070B6C 7F03C03C 0FC160F6 */  jal   mtx4RotateVecInPlace
/* 070B70 7F03C040 02A02825 */   move  $a1, $s5
/* 070B74 7F03C044 240A0001 */  li    $t2, 1
/* 070B78 7F03C048 AFAA0010 */  sw    $t2, 0x10($sp)
/* 070B7C 7F03C04C 02402025 */  move  $a0, $s2
/* 070B80 7F03C050 02202825 */  move  $a1, $s1
/* 070B84 7F03C054 02A03025 */  move  $a2, $s5
/* 070B88 7F03C058 0FC09C9F */  jal   handles_shot_actors
/* 070B8C 7F03C05C 02C03825 */   move  $a3, $s6
/* 070B90 7F03C060 10400006 */  beqz  $v0, .L7F03C07C
/* 070B94 7F03C064 02C02025 */   move  $a0, $s6
/* 070B98 7F03C068 240B0001 */  li    $t3, 1
/* 070B9C 7F03C06C AFAB00BC */  sw    $t3, 0xbc($sp)
/* 070BA0 7F03C070 02002825 */  move  $a1, $s0
/* 070BA4 7F03C074 0FC19107 */  jal   recall_joy2_hits_edit_detail_edit_flag
/* 070BA8 7F03C078 2406FFFF */   li    $a2, -1
.L7F03C07C:
/* 070BAC 7F03C07C 3C0C8007 */  lui   $t4, %hi(g_OnScreenPropList)
/* 070BB0 7F03C080 258C1620 */  addiu $t4, %lo(g_OnScreenPropList) # addiu $t4, $t4, 0x1620
/* 070BB4 7F03C084 2673FFFC */  addiu $s3, $s3, -4
/* 070BB8 7F03C088 026C082B */  sltu  $at, $s3, $t4
/* 070BBC 7F03C08C 5020FF76 */  beql  $at, $zero, .L7F03BE68
/* 070BC0 7F03C090 8E700000 */   lw    $s0, ($s3)
.L7F03C094:
/* 070BC4 7F03C094 8FAD00BC */  lw    $t5, 0xbc($sp)
/* 070BC8 7F03C098 24010001 */  li    $at, 1
/* 070BCC 7F03C09C 55A00008 */  bnezl $t5, .L7F03C0C0
/* 070BD0 7F03C0A0 8FBF0064 */   lw    $ra, 0x64($sp)
/* 070BD4 7F03C0A4 16C10005 */  bne   $s6, $at, .L7F03C0BC
/* 070BD8 7F03C0A8 3C048006 */   lui   $a0, %hi(g_musicSfxBufferPtr)
/* 070BDC 7F03C0AC 8C843720 */  lw    $a0, %lo(g_musicSfxBufferPtr)($a0)
/* 070BE0 7F03C0B0 24050069 */  li    $a1, 105
/* 070BE4 7F03C0B4 0C002382 */  jal   sndPlaySfx
/* 070BE8 7F03C0B8 00003025 */   move  $a2, $zero
.L7F03C0BC:
/* 070BEC 7F03C0BC 8FBF0064 */  lw    $ra, 0x64($sp)
.L7F03C0C0:
/* 070BF0 7F03C0C0 D7B40030 */  ldc1  $f20, 0x30($sp)
/* 070BF4 7F03C0C4 D7B60038 */  ldc1  $f22, 0x38($sp)
/* 070BF8 7F03C0C8 D7B80040 */  ldc1  $f24, 0x40($sp)
/* 070BFC 7F03C0CC 8FB00048 */  lw    $s0, 0x48($sp)
/* 070C00 7F03C0D0 8FB1004C */  lw    $s1, 0x4c($sp)
/* 070C04 7F03C0D4 8FB20050 */  lw    $s2, 0x50($sp)
/* 070C08 7F03C0D8 8FB30054 */  lw    $s3, 0x54($sp)
/* 070C0C 7F03C0DC 8FB40058 */  lw    $s4, 0x58($sp)
/* 070C10 7F03C0E0 8FB5005C */  lw    $s5, 0x5c($sp)
/* 070C14 7F03C0E4 8FB60060 */  lw    $s6, 0x60($sp)
/* 070C18 7F03C0E8 03E00008 */  jr    $ra
/* 070C1C 7F03C0EC 27BD00C8 */   addiu $sp, $sp, 0xc8
)
#endif




void chraiDefaultWeaponFireHandler(s32);

/**
 * Address 0x7F03C0F0.
*/
void chraiCheckUseHeldItem(s32 hand)
{
    s32 item_id;
    s32 i;

    if (get_hands_firing_status(hand) != 0)
    {
        item_id = getCurrentPlayerWeaponId(hand);

        if (item_id == ITEM_TRIGGER)
        {
            trigger_remote_mine_detonation();
        }
        else if (item_id == ITEM_GRENADELAUNCH
            || item_id == ITEM_ROCKETLAUNCH
            || item_id == ITEM_GRENADE
            || item_id == ITEM_THROWKNIFE
            || item_id == ITEM_REMOTEMINE
            || item_id == ITEM_PROXIMITYMINE
            || item_id == ITEM_TIMEDMINE
            || item_id == ITEM_FLAREPISTOL
            || item_id == ITEM_PITONGUN
            || item_id == ITEM_BOMBCASE
            || item_id == ITEM_BUG
            || item_id == ITEM_MICROCAMERA
            || item_id == ITEM_GOLDENEYEKEY
            || item_id == ITEM_TOKEN
            || item_id == ITEM_PLASTIQUE
        )
        {
            // nothing to do
        }
        else if (item_id == ITEM_TANKSHELLS)
        {
            gunFireTankShell(hand);
        }
        else if (item_id == ITEM_FIST || item_id == ITEM_KNIFE)
        {
            chraiFistAttackHandler(hand, item_id);
        }
        else if (item_id == ITEM_SHOTGUN || item_id == ITEM_AUTOSHOT)
        {
            inc_curplayer_hitcount_with_weapon(item_id, SHOT_REGISTER_TOTAL);

            for (i=0; i<NUMBER_SHOTGUN_BULLETS; i++)
            {
                chraiDefaultWeaponFireHandler(hand);
            }
        }
        else if (item_id == ITEM_CAMERA)
        {
            objectiveTakePictureHandler();
        }
        else if (item_id == ITEM_WATCHMAGNETATTRACT)
        {
            g_CurrentPlayer->magnetattracttime = 0;
        }
        else
        {
            inc_curplayer_hitcount_with_weapon(item_id, SHOT_REGISTER_TOTAL);
            chraiDefaultWeaponFireHandler(hand);
        }
    }
}





/**
 * Address 0x7F03C294.
*/
void chraiCheckUseHeldItems(void)
{
    chraiCheckUseHeldItem(GUNRIGHT);
    chraiCheckUseHeldItem(GUNLEFT);
}





void propExecuteTickOperation(PropRecord *prop, INV_ITEM_TYPE type) //#MATCH
{
    ObjectRecord *propobj;

    if (type == INV_ITEM_WEAPON)
    {
        if ((prop->type == PROP_TYPE_WEAPON) || (prop->type == PROP_TYPE_OBJ))
        {
            propobj = prop->obj;
            if (prop->obj->state & 4) //matches only is called directly (not propobj)
            {
                #ifndef VERSION_EU
                prop->timetoregen = 0x4B0;
                #else
                prop->timetoregen = 0x3E8;
                #endif
                propobj->runtime_bitflags |= 0x800;
                propobj->runtime_bitflags &= ~4;
                propobj->state &= ~0x80;
                propobj->maxdamage = 0.0f;
                chrpropDeregisterRooms(prop);
                chrpropDisable(prop);
                return;
            }
        }
        chrpropDeregisterRooms(prop);
        chrpropDelist(prop);
        chrpropDisable(prop);
        chrpropFree(prop);
    }
    else if (type == INV_ITEM_PROP)
    {
        chrpropDeregisterRooms(prop);
        chrpropDelist(prop);
        chrpropDisable(prop);
    }
    else if (type == INV_ITEM_PICKUP)
    {
        chrpropDeregisterRooms(prop);
        chrpropDelist(prop);
        chrpropDisable(prop);
        objDetach(prop);
        objFreeEmbedmentOrProjectile(prop);
        chrpropReparent(prop, get_curplayer_positiondata());
    }
}


PropRecord *propFindForInteract(void)
{
    PropRecord **ptr;
    s32 i;
    bool checkmore = TRUE;

    g_InteractProp = NULL;

    // Iterate onscreen list near to far
    for (ptr = g_LastOnScreenProp - 1; ptr >= g_OnScreenPropList; ptr--)
    {
        PropRecord *prop = *ptr;

        if (prop)
        {
            if (prop->type == PROP_TYPE_CHR)
            {
                // empty
            }
            else if (prop->type == PROP_TYPE_OBJ || prop->type == PROP_TYPE_WEAPON)
            {
                checkmore = objTestForInteract(prop);
            }
            else if (prop->type == PROP_TYPE_DOOR)
            {
                checkmore = doorTestForInteract(prop);
            }
            else if (prop->type == PROP_TYPE_EXPLOSION)
            {
                // empty
            }
            else if (prop->type == PROP_TYPE_SMOKE)
            {
                // empty
            }

            if (!checkmore)
            {
                break;
            }
        }
    }

    return g_InteractProp;
}


bool bond_interact_object(void)
{
    PropRecord *prop;
    bool op;

    prop = propFindForInteract();
    op = INV_ITEM_NONE;

    if (prop)
    {
        switch (prop->type)
        {
            case PROP_TYPE_OBJ:
            case PROP_TYPE_WEAPON:
                op = propobjInteract(prop);
                break;
            case PROP_TYPE_DOOR:
                op = propdoorInteract(prop);
                break;
            case PROP_TYPE_CHR:
            case PROP_TYPE_PLAYER:
            case PROP_TYPE_EXPLOSION:
            case PROP_TYPE_SMOKE:
                break;
        }

        propExecuteTickOperation(prop, op);

        return FALSE;
    }

    return TRUE;
}


/* Not quite sure what to name this, it returns true when the given prop isn't within 400 units of any player prop */
s32 sub_GAME_7F03C574(PropRecord* prop)
{
    PropRecord* player_prop;
    coord3d pos_diff;
    s32 uninitialized; // needed for match
    s32 rc;
    s32 i;
    s32 player_count;

    player_count = getPlayerCount();
    rc = 1;

    for (i = 0; i < player_count; i++)
    {
        player_prop = g_playerPointers[i]->prop;
        pos_diff.x = player_prop->pos.x - prop->pos.x;
        pos_diff.y = player_prop->pos.y - prop->pos.y;
        pos_diff.z = player_prop->pos.z - prop->pos.z;
        if (sqrtf((pos_diff.x * pos_diff.x) + (pos_diff.y * pos_diff.y) + (pos_diff.z * pos_diff.z)) < 400.0f)
        {
            rc = 0;
            break;
        }
    }

    return rc;
}




#ifdef NONMATCHING
void handle_mp_respawn_and_some_things(void) {
    void *prev_prop;//sp4C
    s32 sp38;
    s32 sp30;
    s32 pad; // sp2C is pad
    void *sp28;
    s16 prop_time_to_regen; //temp_v0_3
    s16 prop_time_to_regen_2; //temp_v0_4
    s32 var_s2;
    s32 var_s3;
    s32 var_v1;
    u8 prop_type; //temp_v0_2
    void *temp_a0;
    void *temp_s0;
    ObjectRecord *temp_s0_2;
    void *temp_s0_3;
    PropRecord *prop; //temp_v0
    void *temp_v0_5;
    void *prop_s0; // var_s0
    PropRecord *prop_s1; //var_s1

    chrlvAllChrTick();
    prop = get_ptr_obj_pos_list_current_entry();
    prop_s1 = prop;
    if (prop != NULL) {
        do {
            var_s2 = 0;
            prev_prop = prop_s1->prev; //unk24
            prop_type = prop_s1->type;
            if (prop_type == 3) {
                temp_s0 = prop_s1->obj; //unk4
                sub_GAME_7F062B00(temp_s0 + 0x180); // function receives ChrRecord_f180
                sub_GAME_7F062B00(temp_s0 + 0x1AC); // function receives ChrRecord_f180
            } else if ((prop_type == PROP_TYPE_OBJ) || (prop_type == PROP_TYPE_WEAPON) || (prop_type == PROP_TYPE_DOOR)) {
                prop_time_to_regen = prop_s1->timetoregen; //unk2
                temp_s0_2 = prop_s1->obj; //unk4
                var_s3 = 0;
                if (prop_time_to_regen > 0) {
                    var_v1 = 1;
                    if (prop_time_to_regen >= 0x3C) {
                        var_v1 = 0;
                    }
                    prop_s1->timetoregen = (s16) (prop_time_to_regen - g_ClockTimer);
                    if ((prop_s1->timetoregen < 0x3C) && (var_v1 == 0)) {
                        sp38 = var_v1;
                        if (sub_GAME_7F03C574(prop_s1) == 0) {
                            prop_s1->timetoregen = (s16) (prop_s1->timetoregen + 0x3C);
                        }
                    }
                    prop_time_to_regen_2 = prop_s1->timetoregen;
                    if (prop_time_to_regen_2 <= 0) {
                        prop_s1->timetoregen = 0;
                        if (temp_s0_2->state & 0x10) {
                            temp_s0_2->runtime_bitflags = (s32) (temp_s0_2->runtime_bitflags | 0x1000);
                        } else {
                            temp_s0_2->runtime_bitflags = (s32) (temp_s0_2->runtime_bitflags & ~0x1000);
                        }
                    } else if ((prop_time_to_regen_2 < 0x3C) && (var_v1 == 0)) {
                        if ((temp_s0_2->maxdamage == 0.0f) && !(temp_s0_2->state & 0x80)) {
                            if (temp_s0_2->flags & 0x8000) {
                                chrpropDeregisterRooms(prop_s1);
                                chrpropDelist(prop_s1);
                                temp_s0_2->runtime_bitflags = (s32) (temp_s0_2->runtime_bitflags & ~0x800);
                                sp30 = setupGetCommandIndexByProp(prop_s1);
                                pad = (s32) temp_s0_2->pad;
                                temp_v0_5 = setupCommandGetObject(lvlGetCurrentStageToLoad(), sp30 + pad);
                                if ((temp_v0_5 != NULL) && (temp_v0_5->prop != 0)) { //unk10 is prop
                                    temp_a0 = temp_s0_2->model; //unk14
                                    sp28 = temp_v0_5;
                                    modelSetScale(temp_a0, temp_a0->unk14);
                                    chrpropReparent(temp_s0_2->unk10, sp28->unk10);
                                    var_s3 = 1;
                                }
                            } else {
                                chrpropEnable(prop_s1);
                                sub_GAME_7F03E134(prop_s1);
                                temp_s0_2->runtime_bitflags = (s32) (temp_s0_2->runtime_bitflags & ~0x800);
                            }
                        } else {
                            if (temp_s0_2->state & 8) {
                                temp_s0_2->flags = (s32) (temp_s0_2->flags | 0x100);
                            } else {
                                temp_s0_2->flags = (s32) (temp_s0_2->flags & ~0x100);
                            }
                            temp_s0_2->maxdamage = 0.0f;
                            temp_s0_2->state = (u8) (temp_s0_2->state & 0xFF7F);
                            sub_GAME_7F050DE8(temp_s0_2->model);
                        }
                        if (temp_s0_2->type == 0x15) {
                            temp_s0_2->unk84 = (f32) temp_s0_2->unk80; // unk80 and unk84 invalid??
                        }
                        if (var_s3 == 0) {
                            chrobjSndCreatePostEventDefault(sndPlaySfx(g_musicSfxBufferPtr, 0x52, 0), prop_s1->pos);
                        }
                    }
                }
                if (temp_s0_2->unk3 == 0xD) { // type == unk3 == 0xD ??? invald??
                    sub_GAME_7F062B00(prop_s1->unk4->unkCC); // unkCC invalid??, function receives ChrRecord_f180
                    // 0x04 is chr, obj, door, weapon
                }
            } else if (prop_type == PROP_TYPE_EXPLOSION) {
                var_s2 = explosionTick(prop_s1); // explosions related
            } else if (prop_type == PROP_TYPE_SMOKE) {
                var_s2 = explosionSmokeTick(prop_s1); // smoke related
            } else if (prop_type == PROP_TYPE_VIEWER) {
                sub_GAME_7F062B00(*(&g_playerPointers + (getPlayerPointerIndex(prop_s1) * 4)) + 0xA54); // function receives ChrRecord_f180
                sub_GAME_7F062B00(*(&g_playerPointers + (getPlayerPointerIndex(prop_s1) * 4)) + 0xDFC); // function receives ChrRecord_f180
                if ((prop_s1->unk4 != NULL) && (getPlayerCount() >= 2)) {
                    temp_s0_3 = prop_s1->unk4;
                    sub_GAME_7F062B00(temp_s0_3 + 0x180); // function receives ChrRecord_f180
                    sub_GAME_7F062B00(temp_s0_3 + 0x1AC); // function receives ChrRecord_f180
                }
            }
            if (var_s2 == 5) {
                prop_s0 = prev_prop;
            } else {
                prop_s0 = prop_s1->prev;
                if (var_s2 == 3) {
                    chrpropDelist(prop_s1);
                    chrpropActivateThisFrame(prop_s1);
                    if (prop_s0 == NULL) {
                        prop_s0 = prop_s1;
                    }
                } else {
                    propExecuteTickOperation(prop_s1, var_s2);
                }
            }
            prop_s1 = prop_s0; // next prop in list
        } while (prop_s0 != NULL);
    }
}
#else

#if defined(VERSION_US) || defined(VERSION_JP)
GLOBAL_ASM(
.text
glabel handle_mp_respawn_and_some_things
/* 071178 7F03C648 27BDFFA8 */  addiu $sp, $sp, -0x58
/* 07117C 7F03C64C AFBF0024 */  sw    $ra, 0x24($sp)
/* 071180 7F03C650 AFB30020 */  sw    $s3, 0x20($sp)
/* 071184 7F03C654 AFB2001C */  sw    $s2, 0x1c($sp)
/* 071188 7F03C658 AFB10018 */  sw    $s1, 0x18($sp)
/* 07118C 7F03C65C 0FC0CA47 */  jal   chrlvAllChrTick
/* 071190 7F03C660 AFB00014 */   sw    $s0, 0x14($sp)
/* 071194 7F03C664 0FC0E909 */  jal   get_ptr_obj_pos_list_current_entry
/* 071198 7F03C668 00000000 */   nop
/* 07119C 7F03C66C 104000E9 */  beqz  $v0, .L7F03CA14
/* 0711A0 7F03C670 00408825 */   move  $s1, $v0
.L7F03C674:
/* 0711A4 7F03C674 8E2E0024 */  lw    $t6, 0x24($s1)
/* 0711A8 7F03C678 24010003 */  li    $at, 3
/* 0711AC 7F03C67C 00009025 */  move  $s2, $zero
/* 0711B0 7F03C680 AFAE004C */  sw    $t6, 0x4c($sp)
/* 0711B4 7F03C684 92220000 */  lbu   $v0, ($s1)
/* 0711B8 7F03C688 54410009 */  bnel  $v0, $at, .L7F03C6B0
/* 0711BC 7F03C68C 24010001 */   li    $at, 1
/* 0711C0 7F03C690 8E300004 */  lw    $s0, 4($s1)
/* 0711C4 7F03C694 0FC18AC0 */  jal   sub_GAME_7F062B00
/* 0711C8 7F03C698 26040180 */   addiu $a0, $s0, 0x180
/* 0711CC 7F03C69C 0FC18AC0 */  jal   sub_GAME_7F062B00
/* 0711D0 7F03C6A0 260401AC */   addiu $a0, $s0, 0x1ac
/* 0711D4 7F03C6A4 100000C7 */  b     .L7F03C9C4
/* 0711D8 7F03C6A8 24010005 */   li    $at, 5
/* 0711DC 7F03C6AC 24010001 */  li    $at, 1
.L7F03C6B0:
/* 0711E0 7F03C6B0 10410005 */  beq   $v0, $at, .L7F03C6C8
/* 0711E4 7F03C6B4 24010004 */   li    $at, 4
/* 0711E8 7F03C6B8 10410003 */  beq   $v0, $at, .L7F03C6C8
/* 0711EC 7F03C6BC 24010002 */   li    $at, 2
/* 0711F0 7F03C6C0 54410092 */  bnel  $v0, $at, .L7F03C90C
/* 0711F4 7F03C6C4 24010007 */   li    $at, 7
.L7F03C6C8:
/* 0711F8 7F03C6C8 86220002 */  lh    $v0, 2($s1)
/* 0711FC 7F03C6CC 8E300004 */  lw    $s0, 4($s1)
/* 071200 7F03C6D0 00009825 */  move  $s3, $zero
/* 071204 7F03C6D4 18400083 */  blez  $v0, .L7F03C8E4
/* 071208 7F03C6D8 2841003C */   slti  $at, $v0, 0x3c
/* 07120C 7F03C6DC 14200002 */  bnez  $at, .L7F03C6E8
/* 071210 7F03C6E0 24030001 */   li    $v1, 1
/* 071214 7F03C6E4 00001825 */  move  $v1, $zero
.L7F03C6E8:
/* 071218 7F03C6E8 3C0F8005 */  lui   $t7, %hi(g_ClockTimer)
/* 07121C 7F03C6EC 8DEF8374 */  lw    $t7, %lo(g_ClockTimer)($t7)
/* 071220 7F03C6F0 004FC023 */  subu  $t8, $v0, $t7
/* 071224 7F03C6F4 A6380002 */  sh    $t8, 2($s1)
/* 071228 7F03C6F8 86390002 */  lh    $t9, 2($s1)
/* 07122C 7F03C6FC 2B21003C */  slti  $at, $t9, 0x3c
/* 071230 7F03C700 5020000B */  beql  $at, $zero, .L7F03C730
/* 071234 7F03C704 86220002 */   lh    $v0, 2($s1)
/* 071238 7F03C708 14600008 */  bnez  $v1, .L7F03C72C
/* 07123C 7F03C70C 02202025 */   move  $a0, $s1
/* 071240 7F03C710 0FC0F15D */  jal   sub_GAME_7F03C574
/* 071244 7F03C714 AFA30038 */   sw    $v1, 0x38($sp)
/* 071248 7F03C718 14400004 */  bnez  $v0, .L7F03C72C
/* 07124C 7F03C71C 8FA30038 */   lw    $v1, 0x38($sp)
/* 071250 7F03C720 86280002 */  lh    $t0, 2($s1)
/* 071254 7F03C724 2509003C */  addiu $t1, $t0, 0x3c
/* 071258 7F03C728 A6290002 */  sh    $t1, 2($s1)
.L7F03C72C:
/* 07125C 7F03C72C 86220002 */  lh    $v0, 2($s1)
.L7F03C730:
/* 071260 7F03C730 1C40000F */  bgtz  $v0, .L7F03C770
/* 071264 7F03C734 2841003C */   slti  $at, $v0, 0x3c
/* 071268 7F03C738 A6200002 */  sh    $zero, 2($s1)
/* 07126C 7F03C73C 920A0002 */  lbu   $t2, 2($s0)
/* 071270 7F03C740 314B0010 */  andi  $t3, $t2, 0x10
/* 071274 7F03C744 51600006 */  beql  $t3, $zero, .L7F03C760
/* 071278 7F03C748 8E0E0064 */   lw    $t6, 0x64($s0)
/* 07127C 7F03C74C 8E0C0064 */  lw    $t4, 0x64($s0)
/* 071280 7F03C750 358D1000 */  ori   $t5, $t4, 0x1000
/* 071284 7F03C754 10000063 */  b     .L7F03C8E4
/* 071288 7F03C758 AE0D0064 */   sw    $t5, 0x64($s0)
/* 07128C 7F03C75C 8E0E0064 */  lw    $t6, 0x64($s0)
.L7F03C760:
/* 071290 7F03C760 2401EFFF */  li    $at, -4097
/* 071294 7F03C764 01C17824 */  and   $t7, $t6, $at
/* 071298 7F03C768 1000005E */  b     .L7F03C8E4
/* 07129C 7F03C76C AE0F0064 */   sw    $t7, 0x64($s0)
.L7F03C770:
/* 0712A0 7F03C770 5020005D */  beql  $at, $zero, .L7F03C8E8
/* 0712A4 7F03C774 92190003 */   lbu   $t9, 3($s0)
/* 0712A8 7F03C778 5460005B */  bnezl $v1, .L7F03C8E8
/* 0712AC 7F03C77C 92190003 */   lbu   $t9, 3($s0)
/* 0712B0 7F03C780 44800000 */  mtc1  $zero, $f0
/* 0712B4 7F03C784 C6040070 */  lwc1  $f4, 0x70($s0)
/* 0712B8 7F03C788 46040032 */  c.eq.s $f0, $f4
/* 0712BC 7F03C78C 00000000 */  nop
/* 0712C0 7F03C790 45020035 */  bc1fl .L7F03C868
/* 0712C4 7F03C794 92080002 */   lbu   $t0, 2($s0)
/* 0712C8 7F03C798 92180002 */  lbu   $t8, 2($s0)
/* 0712CC 7F03C79C 33190080 */  andi  $t9, $t8, 0x80
/* 0712D0 7F03C7A0 57200031 */  bnezl $t9, .L7F03C868
/* 0712D4 7F03C7A4 92080002 */   lbu   $t0, 2($s0)
/* 0712D8 7F03C7A8 8E080008 */  lw    $t0, 8($s0)
/* 0712DC 7F03C7AC 31098000 */  andi  $t1, $t0, 0x8000
/* 0712E0 7F03C7B0 11200023 */  beqz  $t1, .L7F03C840
/* 0712E4 7F03C7B4 00000000 */   nop
/* 0712E8 7F03C7B8 0FC0F863 */  jal   chrpropDeregisterRooms
/* 0712EC 7F03C7BC 02202025 */   move  $a0, $s1
/* 0712F0 7F03C7C0 0FC0E94E */  jal   chrpropDelist
/* 0712F4 7F03C7C4 02202025 */   move  $a0, $s1
/* 0712F8 7F03C7C8 8E0A0064 */  lw    $t2, 0x64($s0)
/* 0712FC 7F03C7CC 2401F7FF */  li    $at, -2049
/* 071300 7F03C7D0 02202025 */  move  $a0, $s1
/* 071304 7F03C7D4 01415824 */  and   $t3, $t2, $at
/* 071308 7F03C7D8 0FC15AEA */  jal   setupGetCommandIndexByProp
/* 07130C 7F03C7DC AE0B0064 */   sw    $t3, 0x64($s0)
/* 071310 7F03C7E0 AFA20030 */  sw    $v0, 0x30($sp)
/* 071314 7F03C7E4 860C0006 */  lh    $t4, 6($s0)
/* 071318 7F03C7E8 0FC2F7C1 */  jal   lvlGetCurrentStageToLoad
/* 07131C 7F03C7EC AFAC002C */   sw    $t4, 0x2c($sp)
/* 071320 7F03C7F0 8FAD0030 */  lw    $t5, 0x30($sp)
/* 071324 7F03C7F4 8FAE002C */  lw    $t6, 0x2c($sp)
/* 071328 7F03C7F8 00402025 */  move  $a0, $v0
/* 07132C 7F03C7FC 0FC15BA8 */  jal   setupCommandGetObject
/* 071330 7F03C800 01AE2821 */   addu  $a1, $t5, $t6
/* 071334 7F03C804 5040002A */  beql  $v0, $zero, .L7F03C8B0
/* 071338 7F03C808 92180003 */   lbu   $t8, 3($s0)
/* 07133C 7F03C80C 8C4F0010 */  lw    $t7, 0x10($v0)
/* 071340 7F03C810 51E00027 */  beql  $t7, $zero, .L7F03C8B0
/* 071344 7F03C814 92180003 */   lbu   $t8, 3($s0)
/* 071348 7F03C818 8E040014 */  lw    $a0, 0x14($s0)
/* 07134C 7F03C81C 8C850014 */  lw    $a1, 0x14($a0)
/* 071350 7F03C820 0FC1B39E */  jal   modelSetScale
/* 071354 7F03C824 AFA20028 */   sw    $v0, 0x28($sp)
/* 071358 7F03C828 8FA30028 */  lw    $v1, 0x28($sp)
/* 07135C 7F03C82C 8E040010 */  lw    $a0, 0x10($s0)
/* 071360 7F03C830 0FC0E969 */  jal   chrpropReparent
/* 071364 7F03C834 8C650010 */   lw    $a1, 0x10($v1)
/* 071368 7F03C838 1000001C */  b     .L7F03C8AC
/* 07136C 7F03C83C 24130001 */   li    $s3, 1
.L7F03C840:
/* 071370 7F03C840 0FC0E901 */  jal   chrpropEnable
/* 071374 7F03C844 02202025 */   move  $a0, $s1
/* 071378 7F03C848 0FC0F84D */  jal   sub_GAME_7F03E134
/* 07137C 7F03C84C 02202025 */   move  $a0, $s1
/* 071380 7F03C850 8E180064 */  lw    $t8, 0x64($s0)
/* 071384 7F03C854 2401F7FF */  li    $at, -2049
/* 071388 7F03C858 0301C824 */  and   $t9, $t8, $at
/* 07138C 7F03C85C 10000013 */  b     .L7F03C8AC
/* 071390 7F03C860 AE190064 */   sw    $t9, 0x64($s0)
/* 071394 7F03C864 92080002 */  lbu   $t0, 2($s0)
.L7F03C868:
/* 071398 7F03C868 31090008 */  andi  $t1, $t0, 8
/* 07139C 7F03C86C 51200006 */  beql  $t1, $zero, .L7F03C888
/* 0713A0 7F03C870 8E0C0008 */   lw    $t4, 8($s0)
/* 0713A4 7F03C874 8E0A0008 */  lw    $t2, 8($s0)
/* 0713A8 7F03C878 354B0100 */  ori   $t3, $t2, 0x100
/* 0713AC 7F03C87C 10000005 */  b     .L7F03C894
/* 0713B0 7F03C880 AE0B0008 */   sw    $t3, 8($s0)
/* 0713B4 7F03C884 8E0C0008 */  lw    $t4, 8($s0)
.L7F03C888:
/* 0713B8 7F03C888 2401FEFF */  li    $at, -257
/* 0713BC 7F03C88C 01816824 */  and   $t5, $t4, $at
/* 0713C0 7F03C890 AE0D0008 */  sw    $t5, 8($s0)
.L7F03C894:
/* 0713C4 7F03C894 920E0002 */  lbu   $t6, 2($s0)
/* 0713C8 7F03C898 E6000070 */  swc1  $f0, 0x70($s0)
/* 0713CC 7F03C89C 8E040014 */  lw    $a0, 0x14($s0)
/* 0713D0 7F03C8A0 31CFFF7F */  andi  $t7, $t6, 0xff7f
/* 0713D4 7F03C8A4 0FC1437A */  jal   sub_GAME_7F050DE8
/* 0713D8 7F03C8A8 A20F0002 */   sb    $t7, 2($s0)
.L7F03C8AC:
/* 0713DC 7F03C8AC 92180003 */  lbu   $t8, 3($s0)
.L7F03C8B0:
/* 0713E0 7F03C8B0 24010015 */  li    $at, 21
/* 0713E4 7F03C8B4 3C048006 */  lui   $a0, %hi(g_musicSfxBufferPtr)
/* 0713E8 7F03C8B8 17010003 */  bne   $t8, $at, .L7F03C8C8
/* 0713EC 7F03C8BC 24050052 */   li    $a1, 82
/* 0713F0 7F03C8C0 C6060080 */  lwc1  $f6, 0x80($s0)
/* 0713F4 7F03C8C4 E6060084 */  swc1  $f6, 0x84($s0)
.L7F03C8C8:
/* 0713F8 7F03C8C8 16600006 */  bnez  $s3, .L7F03C8E4
/* 0713FC 7F03C8CC 00003025 */   move  $a2, $zero
/* 071400 7F03C8D0 0C002382 */  jal   sndPlaySfx
/* 071404 7F03C8D4 8C843720 */   lw    $a0, %lo(g_musicSfxBufferPtr)($a0)
/* 071408 7F03C8D8 00402025 */  move  $a0, $v0
/* 07140C 7F03C8DC 0FC14E84 */  jal   chrobjSndCreatePostEventDefault
/* 071410 7F03C8E0 26250008 */   addiu $a1, $s1, 8
.L7F03C8E4:
/* 071414 7F03C8E4 92190003 */  lbu   $t9, 3($s0)
.L7F03C8E8:
/* 071418 7F03C8E8 2401000D */  li    $at, 13
/* 07141C 7F03C8EC 57210035 */  bnel  $t9, $at, .L7F03C9C4
/* 071420 7F03C8F0 24010005 */   li    $at, 5
/* 071424 7F03C8F4 8E220004 */  lw    $v0, 4($s1)
/* 071428 7F03C8F8 0FC18AC0 */  jal   sub_GAME_7F062B00
/* 07142C 7F03C8FC 8C4400CC */   lw    $a0, 0xcc($v0)
/* 071430 7F03C900 10000030 */  b     .L7F03C9C4
/* 071434 7F03C904 24010005 */   li    $at, 5
/* 071438 7F03C908 24010007 */  li    $at, 7
.L7F03C90C:
/* 07143C 7F03C90C 54410006 */  bnel  $v0, $at, .L7F03C928
/* 071440 7F03C910 24010008 */   li    $at, 8
/* 071444 7F03C914 0FC273BA */  jal   explosionTick
/* 071448 7F03C918 02202025 */   move  $a0, $s1
/* 07144C 7F03C91C 10000028 */  b     .L7F03C9C0
/* 071450 7F03C920 00409025 */   move  $s2, $v0
/* 071454 7F03C924 24010008 */  li    $at, 8
.L7F03C928:
/* 071458 7F03C928 54410006 */  bnel  $v0, $at, .L7F03C944
/* 07145C 7F03C92C 24010006 */   li    $at, 6
/* 071460 7F03C930 0FC27A2B */  jal   explosionSmokeTick
/* 071464 7F03C934 02202025 */   move  $a0, $s1
/* 071468 7F03C938 10000021 */  b     .L7F03C9C0
/* 07146C 7F03C93C 00409025 */   move  $s2, $v0
/* 071470 7F03C940 24010006 */  li    $at, 6
.L7F03C944:
/* 071474 7F03C944 5441001F */  bnel  $v0, $at, .L7F03C9C4
/* 071478 7F03C948 24010005 */   li    $at, 5
/* 07147C 7F03C94C 0FC26C57 */  jal   getPlayerPointerIndex
/* 071480 7F03C950 02202025 */   move  $a0, $s1
/* 071484 7F03C954 00024080 */  sll   $t0, $v0, 2
/* 071488 7F03C958 3C048008 */  lui   $a0, %hi(g_playerPointers)
/* 07148C 7F03C95C 00882021 */  addu  $a0, $a0, $t0
/* 071490 7F03C960 8C849EE0 */  lw    $a0, %lo(g_playerPointers)($a0)
/* 071494 7F03C964 0FC18AC0 */  jal   sub_GAME_7F062B00
/* 071498 7F03C968 24840A54 */   addiu $a0, $a0, 0xa54
/* 07149C 7F03C96C 0FC26C57 */  jal   getPlayerPointerIndex
/* 0714A0 7F03C970 02202025 */   move  $a0, $s1
/* 0714A4 7F03C974 00024880 */  sll   $t1, $v0, 2
/* 0714A8 7F03C978 3C048008 */  lui   $a0, %hi(g_playerPointers)
/* 0714AC 7F03C97C 00892021 */  addu  $a0, $a0, $t1
/* 0714B0 7F03C980 8C849EE0 */  lw    $a0, %lo(g_playerPointers)($a0)
/* 0714B4 7F03C984 0FC18AC0 */  jal   sub_GAME_7F062B00
/* 0714B8 7F03C988 24840DFC */   addiu $a0, $a0, 0xdfc
/* 0714BC 7F03C98C 8E2A0004 */  lw    $t2, 4($s1)
/* 0714C0 7F03C990 5140000C */  beql  $t2, $zero, .L7F03C9C4
/* 0714C4 7F03C994 24010005 */   li    $at, 5
/* 0714C8 7F03C998 0FC26919 */  jal   getPlayerCount
/* 0714CC 7F03C99C 00000000 */   nop
/* 0714D0 7F03C9A0 28410002 */  slti  $at, $v0, 2
/* 0714D4 7F03C9A4 54200007 */  bnezl $at, .L7F03C9C4
/* 0714D8 7F03C9A8 24010005 */   li    $at, 5
/* 0714DC 7F03C9AC 8E300004 */  lw    $s0, 4($s1)
/* 0714E0 7F03C9B0 0FC18AC0 */  jal   sub_GAME_7F062B00
/* 0714E4 7F03C9B4 26040180 */   addiu $a0, $s0, 0x180
/* 0714E8 7F03C9B8 0FC18AC0 */  jal   sub_GAME_7F062B00
/* 0714EC 7F03C9BC 260401AC */   addiu $a0, $s0, 0x1ac
.L7F03C9C0:
/* 0714F0 7F03C9C0 24010005 */  li    $at, 5
.L7F03C9C4:
/* 0714F4 7F03C9C4 56410004 */  bnel  $s2, $at, .L7F03C9D8
/* 0714F8 7F03C9C8 24010003 */   li    $at, 3
/* 0714FC 7F03C9CC 1000000F */  b     .L7F03CA0C
/* 071500 7F03C9D0 8FB0004C */   lw    $s0, 0x4c($sp)
/* 071504 7F03C9D4 24010003 */  li    $at, 3
.L7F03C9D8:
/* 071508 7F03C9D8 16410009 */  bne   $s2, $at, .L7F03CA00
/* 07150C 7F03C9DC 8E300024 */   lw    $s0, 0x24($s1)
/* 071510 7F03C9E0 0FC0E94E */  jal   chrpropDelist
/* 071514 7F03C9E4 02202025 */   move  $a0, $s1
/* 071518 7F03C9E8 0FC0E93C */  jal   chrpropActivateThisFrame
/* 07151C 7F03C9EC 02202025 */   move  $a0, $s1
/* 071520 7F03C9F0 16000006 */  bnez  $s0, .L7F03CA0C
/* 071524 7F03C9F4 00000000 */   nop
/* 071528 7F03C9F8 10000004 */  b     .L7F03CA0C
/* 07152C 7F03C9FC 02208025 */   move  $s0, $s1
.L7F03CA00:
/* 071530 7F03CA00 02202025 */  move  $a0, $s1
/* 071534 7F03CA04 0FC0F0AF */  jal   propExecuteTickOperation
/* 071538 7F03CA08 02402825 */   move  $a1, $s2
.L7F03CA0C:
/* 07153C 7F03CA0C 1600FF19 */  bnez  $s0, .L7F03C674
/* 071540 7F03CA10 02008825 */   move  $s1, $s0
.L7F03CA14:
/* 071544 7F03CA14 8FBF0024 */  lw    $ra, 0x24($sp)
/* 071548 7F03CA18 8FB00014 */  lw    $s0, 0x14($sp)
/* 07154C 7F03CA1C 8FB10018 */  lw    $s1, 0x18($sp)
/* 071550 7F03CA20 8FB2001C */  lw    $s2, 0x1c($sp)
/* 071554 7F03CA24 8FB30020 */  lw    $s3, 0x20($sp)
/* 071558 7F03CA28 03E00008 */  jr    $ra
/* 07155C 7F03CA2C 27BD0058 */   addiu $sp, $sp, 0x58
)
#endif

#if defined(VERSION_EU)
GLOBAL_ASM(
.text
glabel handle_mp_respawn_and_some_things
/* 06F0F8 7F03C708 27BDFFA8 */  addiu $sp, $sp, -0x58
/* 06F0FC 7F03C70C AFBF0024 */  sw    $ra, 0x24($sp)
/* 06F100 7F03C710 AFB30020 */  sw    $s3, 0x20($sp)
/* 06F104 7F03C714 AFB2001C */  sw    $s2, 0x1c($sp)
/* 06F108 7F03C718 AFB10018 */  sw    $s1, 0x18($sp)
/* 06F10C 7F03C71C 0FC0CA58 */  jal   chrlvAllChrTick
/* 06F110 7F03C720 AFB00014 */   sw    $s0, 0x14($sp)
/* 06F114 7F03C724 0FC0E939 */  jal   get_ptr_obj_pos_list_current_entry
/* 06F118 7F03C728 00000000 */   nop
/* 06F11C 7F03C72C 104000E9 */  beqz  $v0, .L7F03CAD4
/* 06F120 7F03C730 00408825 */   move  $s1, $v0
.L7F03C734:
/* 06F124 7F03C734 8E2E0024 */  lw    $t6, 0x24($s1)
/* 06F128 7F03C738 24010003 */  li    $at, 3
/* 06F12C 7F03C73C 00009025 */  move  $s2, $zero
/* 06F130 7F03C740 AFAE004C */  sw    $t6, 0x4c($sp)
/* 06F134 7F03C744 92220000 */  lbu   $v0, ($s1)
/* 06F138 7F03C748 54410009 */  bnel  $v0, $at, .L7F03C770
/* 06F13C 7F03C74C 24010001 */   li    $at, 1
/* 06F140 7F03C750 8E300004 */  lw    $s0, 4($s1)
/* 06F144 7F03C754 0FC18BF1 */  jal   sub_GAME_7F062B00
/* 06F148 7F03C758 26040180 */   addiu $a0, $s0, 0x180
/* 06F14C 7F03C75C 0FC18BF1 */  jal   sub_GAME_7F062B00
/* 06F150 7F03C760 260401AC */   addiu $a0, $s0, 0x1ac
/* 06F154 7F03C764 100000C7 */  b     .L7F03CA84
/* 06F158 7F03C768 24010005 */   li    $at, 5
/* 06F15C 7F03C76C 24010001 */  li    $at, 1
.L7F03C770:
/* 06F160 7F03C770 10410005 */  beq   $v0, $at, .L7F03C788
/* 06F164 7F03C774 24010004 */   li    $at, 4
/* 06F168 7F03C778 10410003 */  beq   $v0, $at, .L7F03C788
/* 06F16C 7F03C77C 24010002 */   li    $at, 2
/* 06F170 7F03C780 54410092 */  bnel  $v0, $at, .L7F03C9CC
/* 06F174 7F03C784 24010007 */   li    $at, 7
.L7F03C788:
/* 06F178 7F03C788 86220002 */  lh    $v0, 2($s1)
/* 06F17C 7F03C78C 8E300004 */  lw    $s0, 4($s1)
/* 06F180 7F03C790 00009825 */  move  $s3, $zero
/* 06F184 7F03C794 18400083 */  blez  $v0, .L7F03C9A4
/* 06F188 7F03C798 28410032 */   slti  $at, $v0, 0x32
/* 06F18C 7F03C79C 14200002 */  bnez  $at, .L7F03C7A8
/* 06F190 7F03C7A0 24030001 */   li    $v1, 1
/* 06F194 7F03C7A4 00001825 */  move  $v1, $zero
.L7F03C7A8:
/* 06F198 7F03C7A8 3C0F8004 */  lui   $t7, %hi(g_ClockTimer) # $t7, 0x8004
/* 06F19C 7F03C7AC 8DEF0FF4 */  lw    $t7, %lo(g_ClockTimer)($t7)
/* 06F1A0 7F03C7B0 004FC023 */  subu  $t8, $v0, $t7
/* 06F1A4 7F03C7B4 A6380002 */  sh    $t8, 2($s1)
/* 06F1A8 7F03C7B8 86390002 */  lh    $t9, 2($s1)
/* 06F1AC 7F03C7BC 2B210032 */  slti  $at, $t9, 0x32
/* 06F1B0 7F03C7C0 5020000B */  beql  $at, $zero, .L7F03C7F0
/* 06F1B4 7F03C7C4 86220002 */   lh    $v0, 2($s1)
/* 06F1B8 7F03C7C8 14600008 */  bnez  $v1, .L7F03C7EC
/* 06F1BC 7F03C7CC 02202025 */   move  $a0, $s1
/* 06F1C0 7F03C7D0 0FC0F18D */  jal   sub_GAME_7F03C574
/* 06F1C4 7F03C7D4 AFA30038 */   sw    $v1, 0x38($sp)
/* 06F1C8 7F03C7D8 14400004 */  bnez  $v0, .L7F03C7EC
/* 06F1CC 7F03C7DC 8FA30038 */   lw    $v1, 0x38($sp)
/* 06F1D0 7F03C7E0 86280002 */  lh    $t0, 2($s1)
/* 06F1D4 7F03C7E4 25090032 */  addiu $t1, $t0, 0x32
/* 06F1D8 7F03C7E8 A6290002 */  sh    $t1, 2($s1)
.L7F03C7EC:
/* 06F1DC 7F03C7EC 86220002 */  lh    $v0, 2($s1)
.L7F03C7F0:
/* 06F1E0 7F03C7F0 1C40000F */  bgtz  $v0, .L7F03C830
/* 06F1E4 7F03C7F4 28410032 */   slti  $at, $v0, 0x32
/* 06F1E8 7F03C7F8 A6200002 */  sh    $zero, 2($s1)
/* 06F1EC 7F03C7FC 920A0002 */  lbu   $t2, 2($s0)
/* 06F1F0 7F03C800 314B0010 */  andi  $t3, $t2, 0x10
/* 06F1F4 7F03C804 51600006 */  beql  $t3, $zero, .L7F03C820
/* 06F1F8 7F03C808 8E0E0064 */   lw    $t6, 0x64($s0)
/* 06F1FC 7F03C80C 8E0C0064 */  lw    $t4, 0x64($s0)
/* 06F200 7F03C810 358D1000 */  ori   $t5, $t4, 0x1000
/* 06F204 7F03C814 10000063 */  b     .L7F03C9A4
/* 06F208 7F03C818 AE0D0064 */   sw    $t5, 0x64($s0)
/* 06F20C 7F03C81C 8E0E0064 */  lw    $t6, 0x64($s0)
.L7F03C820:
/* 06F210 7F03C820 2401EFFF */  li    $at, -4097
/* 06F214 7F03C824 01C17824 */  and   $t7, $t6, $at
/* 06F218 7F03C828 1000005E */  b     .L7F03C9A4
/* 06F21C 7F03C82C AE0F0064 */   sw    $t7, 0x64($s0)
.L7F03C830:
/* 06F220 7F03C830 5020005D */  beql  $at, $zero, .L7F03C9A8
/* 06F224 7F03C834 92190003 */   lbu   $t9, 3($s0)
/* 06F228 7F03C838 5460005B */  bnezl $v1, .L7F03C9A8
/* 06F22C 7F03C83C 92190003 */   lbu   $t9, 3($s0)
/* 06F230 7F03C840 44800000 */  mtc1  $zero, $f0
/* 06F234 7F03C844 C6040070 */  lwc1  $f4, 0x70($s0)
/* 06F238 7F03C848 46040032 */  c.eq.s $f0, $f4
/* 06F23C 7F03C84C 00000000 */  nop
/* 06F240 7F03C850 45020035 */  bc1fl .L7F03C928
/* 06F244 7F03C854 92080002 */   lbu   $t0, 2($s0)
/* 06F248 7F03C858 92180002 */  lbu   $t8, 2($s0)
/* 06F24C 7F03C85C 33190080 */  andi  $t9, $t8, 0x80
/* 06F250 7F03C860 57200031 */  bnezl $t9, .L7F03C928
/* 06F254 7F03C864 92080002 */   lbu   $t0, 2($s0)
/* 06F258 7F03C868 8E080008 */  lw    $t0, 8($s0)
/* 06F25C 7F03C86C 31098000 */  andi  $t1, $t0, 0x8000
/* 06F260 7F03C870 11200023 */  beqz  $t1, .L7F03C900
/* 06F264 7F03C874 00000000 */   nop
/* 06F268 7F03C878 0FC0F893 */  jal   chrpropDeregisterRooms
/* 06F26C 7F03C87C 02202025 */   move  $a0, $s1
/* 06F270 7F03C880 0FC0E97E */  jal   chrpropDelist
/* 06F274 7F03C884 02202025 */   move  $a0, $s1
/* 06F278 7F03C888 8E0A0064 */  lw    $t2, 0x64($s0)
/* 06F27C 7F03C88C 2401F7FF */  li    $at, -2049
/* 06F280 7F03C890 02202025 */  move  $a0, $s1
/* 06F284 7F03C894 01415824 */  and   $t3, $t2, $at
/* 06F288 7F03C898 0FC15BA2 */  jal   setupGetCommandIndexByProp
/* 06F28C 7F03C89C AE0B0064 */   sw    $t3, 0x64($s0)
/* 06F290 7F03C8A0 AFA20030 */  sw    $v0, 0x30($sp)
/* 06F294 7F03C8A4 860C0006 */  lh    $t4, 6($s0)
/* 06F298 7F03C8A8 0FC2F4B1 */  jal   lvlGetCurrentStageToLoad
/* 06F29C 7F03C8AC AFAC002C */   sw    $t4, 0x2c($sp)
/* 06F2A0 7F03C8B0 8FAD0030 */  lw    $t5, 0x30($sp)
/* 06F2A4 7F03C8B4 8FAE002C */  lw    $t6, 0x2c($sp)
/* 06F2A8 7F03C8B8 00402025 */  move  $a0, $v0
/* 06F2AC 7F03C8BC 0FC15C60 */  jal   setupCommandGetObject
/* 06F2B0 7F03C8C0 01AE2821 */   addu  $a1, $t5, $t6
/* 06F2B4 7F03C8C4 5040002A */  beql  $v0, $zero, .L7F03C970
/* 06F2B8 7F03C8C8 92180003 */   lbu   $t8, 3($s0)
/* 06F2BC 7F03C8CC 8C4F0010 */  lw    $t7, 0x10($v0)
/* 06F2C0 7F03C8D0 51E00027 */  beql  $t7, $zero, .L7F03C970
/* 06F2C4 7F03C8D4 92180003 */   lbu   $t8, 3($s0)
/* 06F2C8 7F03C8D8 8E040014 */  lw    $a0, 0x14($s0)
/* 06F2CC 7F03C8DC 8C850014 */  lw    $a1, 0x14($a0)
/* 06F2D0 7F03C8E0 0FC1B4CF */  jal   modelSetScale
/* 06F2D4 7F03C8E4 AFA20028 */   sw    $v0, 0x28($sp)
/* 06F2D8 7F03C8E8 8FA30028 */  lw    $v1, 0x28($sp)
/* 06F2DC 7F03C8EC 8E040010 */  lw    $a0, 0x10($s0)
/* 06F2E0 7F03C8F0 0FC0E999 */  jal   chrpropReparent
/* 06F2E4 7F03C8F4 8C650010 */   lw    $a1, 0x10($v1)
/* 06F2E8 7F03C8F8 1000001C */  b     .L7F03C96C
/* 06F2EC 7F03C8FC 24130001 */   li    $s3, 1
.L7F03C900:
/* 06F2F0 7F03C900 0FC0E931 */  jal   chrpropEnable
/* 06F2F4 7F03C904 02202025 */   move  $a0, $s1
/* 06F2F8 7F03C908 0FC0F87D */  jal   sub_GAME_7F03E134
/* 06F2FC 7F03C90C 02202025 */   move  $a0, $s1
/* 06F300 7F03C910 8E180064 */  lw    $t8, 0x64($s0)
/* 06F304 7F03C914 2401F7FF */  li    $at, -2049
/* 06F308 7F03C918 0301C824 */  and   $t9, $t8, $at
/* 06F30C 7F03C91C 10000013 */  b     .L7F03C96C
/* 06F310 7F03C920 AE190064 */   sw    $t9, 0x64($s0)
/* 06F314 7F03C924 92080002 */  lbu   $t0, 2($s0)
.L7F03C928:
/* 06F318 7F03C928 31090008 */  andi  $t1, $t0, 8
/* 06F31C 7F03C92C 51200006 */  beql  $t1, $zero, .L7F03C948
/* 06F320 7F03C930 8E0C0008 */   lw    $t4, 8($s0)
/* 06F324 7F03C934 8E0A0008 */  lw    $t2, 8($s0)
/* 06F328 7F03C938 354B0100 */  ori   $t3, $t2, 0x100
/* 06F32C 7F03C93C 10000005 */  b     .L7F03C954
/* 06F330 7F03C940 AE0B0008 */   sw    $t3, 8($s0)
/* 06F334 7F03C944 8E0C0008 */  lw    $t4, 8($s0)
.L7F03C948:
/* 06F338 7F03C948 2401FEFF */  li    $at, -257
/* 06F33C 7F03C94C 01816824 */  and   $t5, $t4, $at
/* 06F340 7F03C950 AE0D0008 */  sw    $t5, 8($s0)
.L7F03C954:
/* 06F344 7F03C954 920E0002 */  lbu   $t6, 2($s0)
/* 06F348 7F03C958 E6000070 */  swc1  $f0, 0x70($s0)
/* 06F34C 7F03C95C 8E040014 */  lw    $a0, 0x14($s0)
/* 06F350 7F03C960 31CFFF7F */  andi  $t7, $t6, 0xff7f
/* 06F354 7F03C964 0FC14432 */  jal   sub_GAME_7F050DE8
/* 06F358 7F03C968 A20F0002 */   sb    $t7, 2($s0)
.L7F03C96C:
/* 06F35C 7F03C96C 92180003 */  lbu   $t8, 3($s0)
.L7F03C970:
/* 06F360 7F03C970 24010015 */  li    $at, 21
/* 06F364 7F03C974 3C048005 */  lui   $a0, %hi(g_musicSfxBufferPtr) # $a0, 0x8005
/* 06F368 7F03C978 17010003 */  bne   $t8, $at, .L7F03C988
/* 06F36C 7F03C97C 24050052 */   li    $a1, 82
/* 06F370 7F03C980 C6060080 */  lwc1  $f6, 0x80($s0)
/* 06F374 7F03C984 E6060084 */  swc1  $f6, 0x84($s0)
.L7F03C988:
/* 06F378 7F03C988 16600006 */  bnez  $s3, .L7F03C9A4
/* 06F37C 7F03C98C 00003025 */   move  $a2, $zero
/* 06F380 7F03C990 0C00209A */  jal   sndPlaySfx
/* 06F384 7F03C994 8C846900 */   lw    $a0, %lo(g_musicSfxBufferPtr)($a0)
/* 06F388 7F03C998 00402025 */  move  $a0, $v0
/* 06F38C 7F03C99C 0FC14F3C */  jal   chrobjSndCreatePostEventDefault
/* 06F390 7F03C9A0 26250008 */   addiu $a1, $s1, 8
.L7F03C9A4:
/* 06F394 7F03C9A4 92190003 */  lbu   $t9, 3($s0)
.L7F03C9A8:
/* 06F398 7F03C9A8 2401000D */  li    $at, 13
/* 06F39C 7F03C9AC 57210035 */  bnel  $t9, $at, .L7F03CA84
/* 06F3A0 7F03C9B0 24010005 */   li    $at, 5
/* 06F3A4 7F03C9B4 8E220004 */  lw    $v0, 4($s1)
/* 06F3A8 7F03C9B8 0FC18BF1 */  jal   sub_GAME_7F062B00
/* 06F3AC 7F03C9BC 8C4400CC */   lw    $a0, 0xcc($v0)
/* 06F3B0 7F03C9C0 10000030 */  b     .L7F03CA84
/* 06F3B4 7F03C9C4 24010005 */   li    $at, 5
/* 06F3B8 7F03C9C8 24010007 */  li    $at, 7
.L7F03C9CC:
/* 06F3BC 7F03C9CC 54410006 */  bnel  $v0, $at, .L7F03C9E8
/* 06F3C0 7F03C9D0 24010008 */   li    $at, 8
/* 06F3C4 7F03C9D4 0FC2710B */  jal   explosionTick
/* 06F3C8 7F03C9D8 02202025 */   move  $a0, $s1
/* 06F3CC 7F03C9DC 10000028 */  b     .L7F03CA80
/* 06F3D0 7F03C9E0 00409025 */   move  $s2, $v0
/* 06F3D4 7F03C9E4 24010008 */  li    $at, 8
.L7F03C9E8:
/* 06F3D8 7F03C9E8 54410006 */  bnel  $v0, $at, .L7F03CA04
/* 06F3DC 7F03C9EC 24010006 */   li    $at, 6
/* 06F3E0 7F03C9F0 0FC2777C */  jal   explosionSmokeTick
/* 06F3E4 7F03C9F4 02202025 */   move  $a0, $s1
/* 06F3E8 7F03C9F8 10000021 */  b     .L7F03CA80
/* 06F3EC 7F03C9FC 00409025 */   move  $s2, $v0
/* 06F3F0 7F03CA00 24010006 */  li    $at, 6
.L7F03CA04:
/* 06F3F4 7F03CA04 5441001F */  bnel  $v0, $at, .L7F03CA84
/* 06F3F8 7F03CA08 24010005 */   li    $at, 5
/* 06F3FC 7F03CA0C 0FC269A7 */  jal   getPlayerPointerIndex
/* 06F400 7F03CA10 02202025 */   move  $a0, $s1
/* 06F404 7F03CA14 00024080 */  sll   $t0, $v0, 2
/* 06F408 7F03CA18 3C048007 */  lui   $a0, %hi(g_playerPointers)
/* 06F40C 7F03CA1C 00882021 */  addu  $a0, $a0, $t0
/* 06F410 7F03CA20 8C8489F0 */  lw    $a0, %lo(g_playerPointers)($a0)
/* 06F414 7F03CA24 0FC18BF1 */  jal   sub_GAME_7F062B00
/* 06F418 7F03CA28 24840A4C */   addiu $a0, $a0, 0xa4c
/* 06F41C 7F03CA2C 0FC269A7 */  jal   getPlayerPointerIndex
/* 06F420 7F03CA30 02202025 */   move  $a0, $s1
/* 06F424 7F03CA34 00024880 */  sll   $t1, $v0, 2
/* 06F428 7F03CA38 3C048007 */  lui   $a0, %hi(g_playerPointers)
/* 06F42C 7F03CA3C 00892021 */  addu  $a0, $a0, $t1
/* 06F430 7F03CA40 8C8489F0 */  lw    $a0, %lo(g_playerPointers)($a0)
/* 06F434 7F03CA44 0FC18BF1 */  jal   sub_GAME_7F062B00
/* 06F438 7F03CA48 24840DF4 */   addiu $a0, $a0, 0xdf4
/* 06F43C 7F03CA4C 8E2A0004 */  lw    $t2, 4($s1)
/* 06F440 7F03CA50 5140000C */  beql  $t2, $zero, .L7F03CA84
/* 06F444 7F03CA54 24010005 */   li    $at, 5
/* 06F448 7F03CA58 0FC26669 */  jal   getPlayerCount
/* 06F44C 7F03CA5C 00000000 */   nop
/* 06F450 7F03CA60 28410002 */  slti  $at, $v0, 2
/* 06F454 7F03CA64 54200007 */  bnezl $at, .L7F03CA84
/* 06F458 7F03CA68 24010005 */   li    $at, 5
/* 06F45C 7F03CA6C 8E300004 */  lw    $s0, 4($s1)
/* 06F460 7F03CA70 0FC18BF1 */  jal   sub_GAME_7F062B00
/* 06F464 7F03CA74 26040180 */   addiu $a0, $s0, 0x180
/* 06F468 7F03CA78 0FC18BF1 */  jal   sub_GAME_7F062B00
/* 06F46C 7F03CA7C 260401AC */   addiu $a0, $s0, 0x1ac
.L7F03CA80:
/* 06F470 7F03CA80 24010005 */  li    $at, 5
.L7F03CA84:
/* 06F474 7F03CA84 56410004 */  bnel  $s2, $at, .L7F03CA98
/* 06F478 7F03CA88 24010003 */   li    $at, 3
/* 06F47C 7F03CA8C 1000000F */  b     .L7F03CACC
/* 06F480 7F03CA90 8FB0004C */   lw    $s0, 0x4c($sp)
/* 06F484 7F03CA94 24010003 */  li    $at, 3
.L7F03CA98:
/* 06F488 7F03CA98 16410009 */  bne   $s2, $at, .L7F03CAC0
/* 06F48C 7F03CA9C 8E300024 */   lw    $s0, 0x24($s1)
/* 06F490 7F03CAA0 0FC0E97E */  jal   chrpropDelist
/* 06F494 7F03CAA4 02202025 */   move  $a0, $s1
/* 06F498 7F03CAA8 0FC0E96C */  jal   chrpropActivateThisFrame
/* 06F49C 7F03CAAC 02202025 */   move  $a0, $s1
/* 06F4A0 7F03CAB0 16000006 */  bnez  $s0, .L7F03CACC
/* 06F4A4 7F03CAB4 00000000 */   nop
/* 06F4A8 7F03CAB8 10000004 */  b     .L7F03CACC
/* 06F4AC 7F03CABC 02208025 */   move  $s0, $s1
.L7F03CAC0:
/* 06F4B0 7F03CAC0 02202025 */  move  $a0, $s1
/* 06F4B4 7F03CAC4 0FC0F0DF */  jal   propExecuteTickOperation
/* 06F4B8 7F03CAC8 02402825 */   move  $a1, $s2
.L7F03CACC:
/* 06F4BC 7F03CACC 1600FF19 */  bnez  $s0, .L7F03C734
/* 06F4C0 7F03CAD0 02008825 */   move  $s1, $s0
.L7F03CAD4:
/* 06F4C4 7F03CAD4 8FBF0024 */  lw    $ra, 0x24($sp)
/* 06F4C8 7F03CAD8 8FB00014 */  lw    $s0, 0x14($sp)
/* 06F4CC 7F03CADC 8FB10018 */  lw    $s1, 0x18($sp)
/* 06F4D0 7F03CAE0 8FB2001C */  lw    $s2, 0x1c($sp)
/* 06F4D4 7F03CAE4 8FB30020 */  lw    $s3, 0x20($sp)
/* 06F4D8 7F03CAE8 03E00008 */  jr    $ra
/* 06F4DC 7F03CAEC 27BD0058 */   addiu $sp, $sp, 0x58
)
#endif
#endif





/*
* Address: 0x7F03CA30
* PD: propsTick (src/game/proptick.c)
*/
void determing_type_of_object_and_detection(void)
{
    s32 tickop;
    PropRecord *prop;
    PropRecord *prev;
    PropRecord *propprev;

    prop = get_ptr_obj_pos_list_current_entry();

    while (prop != NULL)
    {
        tickop = 0;
        prev = prop->prev;

        if (prop->type == PROP_TYPE_CHR)
        {
            tickop = chrTickBeams(prop);
        }
        else if ((prop->type == PROP_TYPE_OBJ) || (prop->type == PROP_TYPE_WEAPON) || (prop->type == PROP_TYPE_DOOR))
        {
            tickop = object_interaction(prop);
        }
        else if (prop->type == PROP_TYPE_EXPLOSION)
        {
            tickop = explosionChrpropExplosionTick(prop);
        }
        else if (prop->type == PROP_TYPE_SMOKE)
        {
            tickop = explosionChrpropSmokeTick(prop);
        }
        else if (prop->type == PROP_TYPE_VIEWER)
        {
            tickop = playerTickBeams(prop);
        }

		if (tickop == 5)
        {
			propprev = prev;
		}
        else
        {
			propprev = prop->prev;

			if (tickop == 3)
            {
				chrpropDelist(prop);
				chrpropActivateThisFrame(prop);

				if (propprev == NULL)
                {
					propprev = prop;
				}
			}
            else
            {
				propExecuteTickOperation(prop, tickop);
			}
		}

		prop = propprev;
    }

    if (sub_GAME_7F09B4D8(get_cur_playernum()) == 0)
    {
        handle_alarm_gas_timer_calldamage();
        loop_set_sound_effect_all_slots();
        propsDefragRoomProps();
    }
}






/**
 * Copies stan roomids from prop to array. The list is terminated
 * with an entry of -1.
 *
 * @param self: prop
 * @param roomids: out parameter. Must contain enough space to store room ids.
 *
 * Address 0x7F03CB8C.
*/
void chraiGetPropRoomIds(PropRecord *self, s32 *roomids)
{
    StandTile *stan;
    s32 i;

    stan = self->stan;

    if (stan == NULL)
    {
        roomids[0] = -1;
    }
    else if ((self->type == PROP_TYPE_VIEWER) && (self->obj == NULL))
    {
        roomids[0] = stan->room;
        roomids[1] = -1;
    }
    else
    {
        for (i=0; self->rooms[i] != 0xff; i++)
        {
            roomids[i] = self->rooms[i];
        }

        roomids[i] = -1;
    }
}




/**
 * @param arg0:
 * @param arg1: out parameter. Bounding coords (x,z) by (x,z).
 * @param arg2: out parameter.
 * @param arg3: out parameter. Maybe ymin. (ground)
 * @param arg4: out parameter. Maybe ymax. (ground + chr/object height)
 *
 * Address 0x7F03CC20.
*/
void chraiGetCollisionBounds(PropRecord *arg0, struct rect4f **arg1, s32 *arg2, f32 *arg3, f32 *arg4)
{
    *arg1 = NULL;
    *arg2 = 0;

    if (arg0->type == PROP_TYPE_CHR)
    {
        chrUpdateCollisionBounds(arg0, arg1, arg2, arg3, arg4);
    }
    else if (arg0->type == PROP_TYPE_VIEWER)
    {
        bondviewGetPropHeightRelatedValues(arg0, arg1, arg2, arg3, arg4);
    }
    else if (arg0->type == PROP_TYPE_WEAPON)
    {
        // nothing to do
    }
    else if ((arg0->type == PROP_TYPE_OBJ) || (arg0->type == PROP_TYPE_DOOR))
    {
        sub_GAME_7F04F244(arg0, arg1, arg2, arg3, arg4);
    }
    else if (arg0->type == PROP_TYPE_PLAYER)
    {
        // nothing to do
    }
    else if (arg0->type == PROP_TYPE_NUL)
    {
        // nothing to do
    }

    return;
}





/**
 * Same as @see chraiGetCollisionBounds, but throws away arg3 and arg4.
 *
 * @param arg0:
 * @param arg1: out parameter. Bounding coords (x,z) by (x,z).
 * @param arg2: out parameter.
 *
 * Address 0x7F03CCB0.
*/
void chraiGetCollisionBoundsWithoutY(PropRecord *arg0, struct rect4f **arg1, s32 *arg2)
{
    f32 sp24;
    f32 sp20;

    chraiGetCollisionBounds(arg0, arg1, arg2, &sp24, &sp20);
}





/**
 * @param point: 3d point to test if inside polygon. Only uses (x,z).
 * @param polygon: Convex polygon. Iterates edges and checks that
 * point is oriented correctly inside all of them.
 * @param edges: Number of edges to iterate in polygon.
 * Address 0x7F03CCD8.
*/
s32 chrpropTestPointInPolygon(coord3d *point, struct rect4f *polygon, s32 edges)
{
    /**
     * Stack overflow:
     *
     * In any case, for any convex polygon (including rectangle) the test is
     * very simple: check each edge of the polygon, assuming each edge is
     * oriented in counterclockwise direction, and test whether the point lies
     * to the left of the edge (in the left-hand half-plane). If all edges pass
     * the test - the point is inside. If at least one fails - the point is outside.
     *
     * In order to test whether the point (xp, yp) lies on the left-hand
     * side of the edge (x1, y1) - (x2, y2), you just need to calculate
     *
     * D = (x2 - x1) * (yp - y1) - (xp - x1) * (y2 - y1)
     *
     * https://stackoverflow.com/a/2752753/1462295
    */

    /**
     * Assuming the above is correct, I think that means rectangles (polygons)
     * are clockwise oriented.
    */

    f32 diff;
    s32 i;
    s32 ret = -1;

    if (edges <= 0)
    {
        return 0;
    }

    for (i=0; i<edges; i++)
    {
        // curse you compiler loop unroller
        diff = (    (polygon->points[(i+1) % edges].f[1] - polygon->points[i].f[1]) * (point->f[0] - polygon->points[i].f[0]))
                 - ((polygon->points[(i+1) % edges].f[0] - polygon->points[i].f[0]) * (point->f[2] - polygon->points[i].f[1]));

        if (diff != 0.0f)
        {
            if (i == 0 || ret < 0)
            {
                ret = (diff > 0.0f);

                continue;
            }

            if ((ret != 0) && (diff < 0.0f))
            {
                return 0;
            }

            if ((ret == 0) && (diff > 0.0f))
            {
                return 0;
            }
        }
    }

    return 1;
}





/**
 * @param arg0: prop
 * @param collision_radius: out parameter, will be set to character width or player collision radius.
 * @param height: out parameter, will be set to height
 * @param always_20: out parameter, will be set to either 20 or 30.
 *
 * Address 0x7F03CF88.
*/
void chrpropGetCollisionBounds(PropRecord *arg0, f32 *collision_radius, f32 *height, f32 *arg3)
{
    if (arg0->type == PROP_TYPE_CHR)
    {
        chrGetChrWidthHeight(arg0, collision_radius, height, arg3);
        return;
    }

    if (arg0->type == PROP_TYPE_VIEWER)
    {
        bondviewGetCollisionRadius(arg0, collision_radius, height, arg3);
        return;
    }

    *collision_radius = 0.0f;
}




/**
 * Address 0x7F03CFE8.
*/
f32 sub_GAME_7F03CFE8(PropRecord *arg0)
{
    if (arg0->type == PROP_TYPE_CHR)
    {
        return chrGetChrGround(arg0);
    }

    if (arg0->type == PROP_TYPE_VIEWER)
    {
        return bondviewGetPlayerStanHeight(g_playerPointers[getPlayerPointerIndex(arg0)]);
    }

    return 0.0f;
}






void sub_GAME_7F03D058(PropRecord *prop, bool unset) //#MATCH
{
    if (prop->type == PROP_TYPE_CHR)
    {
        chrSetMoving(prop->chr, unset);
    }
    else if (prop->type == PROP_TYPE_VIEWER)
    {
        bondviewUpdateGuardTankFlagsRelated(prop, unset);
    }
    else if ((prop->type == PROP_TYPE_OBJ) || (prop->type == PROP_TYPE_DOOR) || (prop->type == PROP_TYPE_WEAPON))
    {
        sub_GAME_7F04F218(prop, unset);
    }
}



/**
 * NTSC address: 0x7F03D0D4.
*/
void sub_GAME_7F03D0D4(void)
{
    PropRecord *prop;
    PropRecord *propprev;
    bool isCollected = FALSE;

    if (!isBondInTank() && !g_PlayerInvincible)
    {
        //for each prop in setup

        for (prop = get_ptr_obj_pos_list_current_entry(); prop != NULL; prop = propprev)
        {
            isCollected = 0;

            if (prop->timetoregen <= 0)
            {
                switch (prop->type)
                {
                    case PROP_TYPE_DOOR:
                    case PROP_TYPE_CHR:
                    case PROP_TYPE_PLAYER:
                    case PROP_TYPE_VIEWER:
                    case PROP_TYPE_EXPLOSION:
                    case PROP_TYPE_SMOKE:
                         break;

                    case PROP_TYPE_OBJ:
                        isCollected = object_collectability_routines(prop);
                        break;

                    case PROP_TYPE_WEAPON:
                        isCollected = redirect_object_collectability_routines(prop);
                        break;
                }
            }
            propprev = prop->prev; //not sure why rare put this here and not in the for statement

            propExecuteTickOperation(prop, isCollected);
        }
    }
}


f32 sub_GAME_7F03D188(PropRecord *prop, coord3d *arg1, f32 *arg2, f32 *arg3, f32 *arg4)
{
    f32 spa0[2];
    coord3d sp94;
    f32 sp8c[2];
    f32 sp84[2];
    f32 sp7c[2];
    f32 sp74[2];
    f32 sp70;
    f32 sp6c;
    f32 top;
    f32 bottom;
    f32 left;
    f32 right;
    f32 result;
    bool sp4c;
    f32 sp48;
    PropRecord *playerprop;
    StandTile* stan;
    f32 ducking_height_related;

    top = getPlayer_c_screentop() + getPlayer_c_screenheight() * 0.175f;
    bottom = getPlayer_c_screentop() + getPlayer_c_screenheight() * 0.825f;
    left = getPlayer_c_screenleft() + getPlayer_c_screenwidth() * 0.25f;
    right = getPlayer_c_screenleft() + getPlayer_c_screenwidth() * 0.75f;

    result = -2;

    transform3Dto2DCoords(arg1, (coord3d*)spa0);
    sp94.x = arg2[0];
    sp94.y = arg1->y;
    sp94.z = arg1->z;
    transform3Dto2DCoords(&sp94, (coord3d*)sp8c);
    sp94.x = arg2[1];
    sp94.y = arg1->y;
    sp94.z = arg1->z;
    transform3Dto2DCoords(&sp94, (coord3d*)sp84);
    sp94.x = arg1->x;
    sp94.y = arg3[1];
    sp94.z = arg1->z;
    transform3Dto2DCoords(&sp94, (coord3d*)sp7c);
    sp94.x = arg1->x;
    sp94.y = arg3[0];
    sp94.z = arg1->z;
    transform3Dto2DCoords(&sp94, (coord3d*)sp74);

    if (sp74[1] >= top && bottom >= sp7c[1])
    {
        sp4c = FALSE;
        get_bullet_angle(&sp70, &sp6c);
        sp8c[0] = floorFloat(sp8c[0]);
        sp84[0] = ceilFloat(sp84[0]);

        if (redirect_get_BONDdata_autoaim_x())
        {
            if (sp8c[0] <= right && left <= sp84[0])
            {
                sp48 = (sp84[0] - sp8c[0]) * 1.5f;

                if (getPlayerCount() == 1)
                {
                    sp48 = sp48 * difficulty;
                }

                sp4c = getPlayer_c_screenleft() + 0.5f * getPlayer_c_screenwidth() >= (sp8c[0] + sp84[0]) * 0.5f - sp48
                    && getPlayer_c_screenleft() + 0.5f * getPlayer_c_screenwidth() <= (sp8c[0] + sp84[0]) * 0.5f + sp48
                    && left <= spa0[0]
                    && right >= spa0[0];
            }
        }
        else
        {
            sp4c = sp8c[0] <= sp70 && sp70 <= sp84[0];
        }

        if (sp4c)
        {
            playerprop = get_curplayer_positiondata();
            stan = playerprop->stan;
            ducking_height_related = bondviewGetPlayerDuckingHeightRelated(g_CurrentPlayer);
            bondviewUpdateGuardTankFlagsRelated(playerprop, FALSE);

            if ((stanTestLineUnobstructed(&stan, playerprop->pos.f[0], playerprop->pos.f[2], prop->pos.f[0], prop->pos.f[2], CDTYPE_OBJS | CDTYPE_DOORS | CDTYPE_PATHBLOCKER, ducking_height_related, ducking_height_related, 0.0f, 1.0f) != 0))
            {
                if (stan == prop->stan)
                {
                    f32 value = spa0[1];

                    if (value < top)
                    {
                        value = top;
                    }
                    else if (value > bottom)
                    {
                        value = bottom;
                    }

                    arg4[1] = value;

                    if (redirect_get_BONDdata_autoaim_x())
                    {
                        f32 value = spa0[0];

                        if (value < left)
                        {
                            value = left;
                        }
                        else if (value > right)
                        {
                            value = right;
                        }

                        arg4[0] = value;
                    }

                    if (getPlayer_c_screenleft() + 0.5f * getPlayer_c_screenwidth() >= sp8c[0]
                            && getPlayer_c_screenleft() + 0.5f * getPlayer_c_screenwidth() <= sp84[0])
                    {
                        result = 1;
                    }
                    else if (getPlayer_c_screenleft() + 0.5f * getPlayer_c_screenwidth() >= sp8c[0])
                    {
                        result = 1 - ((getPlayer_c_screenleft() + 0.5f * getPlayer_c_screenwidth()) - sp84[0]) / sp48;
                    }
                    else
                    {
                        result = 1 - (sp8c[0] - (getPlayer_c_screenleft() + 0.5f * getPlayer_c_screenwidth())) / sp48;
                    }
                }
            }

            bondviewUpdateGuardTankFlagsRelated(playerprop, TRUE);
        }
    }

    return result;
}


/**
 * Iterates on screen props to find autoaim target.
 *
 * US address 7F03D78C.
*/
void chrpropUpdateAutoaimTarget(void)
{
    f32 var_f20;
    struct coord2d sp9C;
    f32 var_f0;
    struct PropRecord **pprop_iter;
    struct coord3d sp88;
    struct coord2d sp80;
    struct coord2d sp78;
    struct PropRecord *prop;
    struct coord2d sp6C;
    struct PropRecord *winning_prop;
    struct ChrRecord *chr;

    winning_prop = NULL;
    sp9C = g_DefaultAutoAimCoord;

    if (redirect_get_BONDdata_autoaim_y() != 0)
    {
        var_f20 = -1.0f;

        for (pprop_iter = g_LastOnScreenProp - 1; pprop_iter >= &g_OnScreenPropList[0]; pprop_iter--)
        {
            prop = *pprop_iter;

            if (prop == NULL)
            {
                continue;
            }

            if ((prop->type != PROP_TYPE_CHR)
                    && ((prop->type != PROP_TYPE_VIEWER)
                        || (prop->obj == NULL)
                        || (getPlayerPointerIndex(prop) == get_cur_playernum())))
            {
                continue;
            }

            chr = prop->chr;

            if (((chrGetEquippedWeaponProp(chr, GUNRIGHT) == 0) && (chrGetEquippedWeaponProp(chr, GUNLEFT) == 0)))
            {
                continue;
            }

            if ((sub_GAME_7F023194(prop, &sp88, &sp80, &sp78) == 0))
            {
                continue;
            }

            var_f0 = sub_GAME_7F03D188(prop, &sp88, &sp80.x, &sp78.x, &sp6C.x);

            if (var_f20 < var_f0)
            {
                var_f20 = var_f0;

                winning_prop = prop;
                sp9C.x = sp6C.x;
                sp9C.y = sp6C.y;

                if (1.0f <= var_f0)
                {
                    break;
                }
            }
        }
    }

    if (winning_prop != NULL)
    {
        if (sp9C.x > 1.0f);

        bondviewUpdateYAutoAimTime(winning_prop, ((sp9C.y - getPlayer_c_screentop()) / (getPlayer_c_screenheight() * 0.5f)) - 1.0f);

        if (redirect_get_BONDdata_autoaim_x() != 0)
        {
            bondviewUpdateXAutoAimTime(winning_prop, ((sp9C.x - getPlayer_c_screenleft()) / (getPlayer_c_screenwidth() * 0.5f)) - 1.0f);
        }
    }
    else
    {
        bondviewUpdateYAutoAimTime(NULL, 0.0f);
        bondviewUpdateXAutoAimTime(NULL, 0.0f);
    }
}

/*
* Address: 7F03D9EC
*/
s32 propDoorGetCdTypes(PropRecord* prop)
{
    s32 var_v1;

    if (prop->door->openPosition <= 0.0f)
    {
        var_v1 = CDTYPE_CLOSEDDOORS;
    }
    else
    {
        var_v1 = (prop->door->maxFrac <= prop->door->openPosition)
            ? CDTYPE_OPENDOORS
            : CDTYPE_AJARDOORS;
    }

    if (((s32)prop->door->flags2 * 4) < 0)
    {
        var_v1 |= CDTYPE_DOORSLOCKEDTOAI;
    }

    return var_v1;
}


/*
* Address: 7F03DA50
* PD: prop_is_of_cd_type
*/
s32 propIsOfCdType(PropRecord* prop, s32 cdtypes) {
    s32 ret;
    ObjectRecord *obj;
    ret = 1;

    if (prop->type == PROP_TYPE_DOOR) {
        if ((cdtypes & CDTYPE_AIOPAQUE)) {
            obj = prop->obj;

            if (obj->flags & PROPFLAG_04000000) {
                ret = 0;
            }
        }

        if (!(cdtypes & CDTYPE_DOORS)) {
            if (!(propDoorGetCdTypes(prop) & cdtypes)) {
                ret = 0;
            }
        }
    } else if (prop->type == PROP_TYPE_VIEWER) {
        if (!(cdtypes & CDTYPE_PLAYERS)) {
            ret = 0;
        }
    } else if (prop->type == PROP_TYPE_CHR) {
        if (!(cdtypes & CDTYPE_CHRS)) {
            ret = 0;
        }
    } else {
        obj = prop->obj;

        if ((cdtypes & CDTYPE_AIOPAQUE) && (obj->flags & PROPFLAG_04000000)) {
            ret = 0;
        }

        if ((cdtypes & CDTYPE_OBJSIMMUNETOEXPLOSIONS) && !(obj->flags & PROPFLAG_INVINCIBLE)) {
            ret = 0;
        }

        if (obj->flags & PROPFLAG_00000800) {
            if (!(cdtypes & CDTYPE_PATHBLOCKER)) {
                ret = 0;
            }
        } else if (!(cdtypes & CDTYPE_OBJS)) {
            ret = 0;
        }
    }

    return ret;
}



/* I think the arguments are lists of roomids but I'm not certain. This function checks if any item in the two lists match */
s32 sub_GAME_7F03DB70(s32* roomids1, s32* roomids2)
{
    s32* itr1;
    s32* itr2;
    s32 itr1_val;
    s32 itr2_val;

    itr1 = roomids1;
    itr1_val = *itr1;
    while (itr1_val >= 0)
    {
        itr2 = roomids2;
        itr2_val = *itr2;
        while(itr2_val >= 0)
        {
            if (itr1_val == itr2_val) { return 1; }
            itr2++;
            itr2_val = *itr2;
        }
        itr1++;
        itr1_val = *itr1;
    }

    return 0;
}



/*
* Address: 0x7F03DBCC
* PD: prop_try_add_to_chunk
*/
s32 chrpropInsertPropnum(s16 propnum, s32 chunkindex) {
    s32 i;

    // Note: The size of the propnums array is 16, but we're only iterating over the first 15 elements.
    //       Is this because the last element is always -1? Seems like a waste.
    for (i = 0; i < 15; i++)
    {
        if (RoomPropListChunks[chunkindex].propnums[i] < 0)
        {
            RoomPropListChunks[chunkindex].propnums[i] = propnum;
            return 1;
        }
    }

    return 0;
}



/*
* Address: 0x7F03DCB8
* Description: Find an emtpy chunk that can be assigned to a room
* PD: room_allocate_prop_list_chunk
*/
s32 chrpropInitializeNewChunkForRoom(s32 roomindex, s32 chunkindex)
{
    s32 i;
    for (i = 0; i < 256; i++)
    {
        if (RoomPropListChunks[i].propnums[0] == -2)
        {
            // This chunk is allowed to be erased
            s32 j; 
            for (j = 0; j < 16; j++)
            {
                RoomPropListChunks[i].propnums[j] = -1;
            }

            if (chunkindex >= 0)
            {
                RoomPropListChunks[chunkindex].propnums[0xF] = i;
            }
            else
            {
                RoomPropListChunkIndexes[roomindex] = i;
            }
            
            return i;
        }
    }

    return -1;
}




/*
* Address: 0x7F03DD9C
* PD: prop_register_room
* PD adds an upper bound check to make sure room is not above the max number of rooms
*/
void chrpropRegisterRoom(PropRecord *prop, s16 room)
{
   	s32 prevchunk = -1;

    if (room < 0)
    {
        return;
    }
    else
    {
        // Find which chunk to start at
        s32 chunkindex = RoomPropListChunkIndexes[room];
        s16 propnum = (prop - pos_data_entry);
        
        while (chunkindex >= 0)
        {
            if (chrpropInsertPropnum(propnum, chunkindex))
            {
                return;
            }

            prevchunk = chunkindex;
            chunkindex = RoomPropListChunks[chunkindex].propnums[0xF];
        }

        // Allocate a new chunk
        chunkindex = chrpropInitializeNewChunkForRoom(room, prevchunk);

        if (chunkindex >= 0)
        {
            chrpropInsertPropnum(propnum, chunkindex);
        }
    }
}




/*
* Address: 0x7F03DE94
* PD: prop_deregister_room
* PD adds an upper bound check to make sure room is not above the max number of rooms
*/
void chrpropDeregisterRoom(PropRecord* prop, s16 room) {
    bool removed = 0;
    s32 prev = -1;
    
    if (room >= 0)
    {
        s16 chunkindex = RoomPropListChunkIndexes[room];
        s16 propIndex = (prop - pos_data_entry);
        
        while (chunkindex >= 0) 
        {
            bool populated = 0; 
            s32 var_s0_2;

            // Check each prop entry in the chunk
            for (var_s0_2 = 0; var_s0_2 < 15; var_s0_2++)
            {
                if (propIndex == RoomPropListChunks[chunkindex].propnums[var_s0_2])
                {
                    RoomPropListChunks[chunkindex].propnums[var_s0_2] = -1; // Mark entry as empty
                    removed = 1;
                } 
                else if (!populated && RoomPropListChunks[chunkindex].propnums[var_s0_2] >= 0)
                {
                    populated = 1;
                }
            }

            if (!populated) // not matching
            {
                // This chunk is empty, so it can be marked as available
                RoomPropListChunks[chunkindex].propnums[0] = -2;
                
                if (prev >= 0)
                {
                    RoomPropListChunks[prev].propnums[0xF] = RoomPropListChunks[chunkindex].propnums[0xF];
                }
                else
                {
                    RoomPropListChunkIndexes[room] = RoomPropListChunks[chunkindex].propnums[0xF];
                }
            }
            else
            {
                prev = chunkindex; // not matching
            }

            if (removed)
            {
                return;
            }

            chunkindex = RoomPropListChunks[chunkindex].propnums[0xF];
        }
    }
}



void sub_GAME_7F03E134(PropRecord* arg0) {
    if (arg0->type == 3) {
        chrPositionRelated7F020D94(arg0->chr);
    } else if ((arg0->type == 1) || (arg0->type == 4)) {
        setupUpdateObjectRoomPosition((ObjectRecord* ) arg0->chr);
    }
}



// Duplicate of the below function with a small extension.
void chrpropDeregisterRooms(PropRecord *prop)
{
    u8  room;
    u8 *roomIter;

    roomIter = prop->rooms;
    room     = roomIter[0];

    while (room != (u8)-1)
    {
        chrpropDeregisterRoom(prop, room);
        roomIter += 1;
        room = *roomIter;
    }
    if (!(prop->flags & 0x10))
    {
        prop->rooms[0] = -1;
    }
}




void chrpropRegisterRooms(PropRecord *prop)
{
    u8  room;
    u8 *roomIter;

    roomIter = prop->rooms;
    room     = roomIter[0];

    while (room != (u8)-1)
    {
        chrpropRegisterRoom(prop, room);
        roomIter += 1;
        room = *roomIter;
    }
}





#ifdef NONMATCHING
/*
* Address: 0x7F03E27C
* PD: Could be one of the following
*        - los_find_intersecting_rooms_properly, 
*        - los_find_final_room_properly
*        - los_find_intersecting_rooms_exhaustive
*        - los_find_final_room_exhaustive
*        - los_find_final_room_fast
*/
void sub_GAME_7F03E27C(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F03E27C
/* 072DAC 7F03E27C 27BDFF90 */  addiu $sp, $sp, -0x70
/* 072DB0 7F03E280 AFBF002C */  sw    $ra, 0x2c($sp)
/* 072DB4 7F03E284 AFB00028 */  sw    $s0, 0x28($sp)
/* 072DB8 7F03E288 AFA50074 */  sw    $a1, 0x74($sp)
/* 072DBC 7F03E28C AFA60078 */  sw    $a2, 0x78($sp)
/* 072DC0 7F03E290 AFA00048 */  sw    $zero, 0x48($sp)
/* 072DC4 7F03E294 908E0001 */  lbu   $t6, 1($a0)
/* 072DC8 7F03E298 44876000 */  mtc1  $a3, $f12
/* 072DCC 7F03E29C 00808025 */  move  $s0, $a0
/* 072DD0 7F03E2A0 31CF0008 */  andi  $t7, $t6, 8
/* 072DD4 7F03E2A4 11E00028 */  beqz  $t7, .L7F03E348
/* 072DD8 7F03E2A8 00001825 */   move  $v1, $zero
/* 072DDC 7F03E2AC 90820000 */  lbu   $v0, ($a0)
/* 072DE0 7F03E2B0 24010001 */  li    $at, 1
/* 072DE4 7F03E2B4 2606002C */  addiu $a2, $s0, 0x2c
/* 072DE8 7F03E2B8 10410005 */  beq   $v0, $at, .L7F03E2D0
/* 072DEC 7F03E2BC 24010004 */   li    $at, 4
/* 072DF0 7F03E2C0 10410003 */  beq   $v0, $at, .L7F03E2D0
/* 072DF4 7F03E2C4 24010002 */   li    $at, 2
/* 072DF8 7F03E2C8 14410002 */  bne   $v0, $at, .L7F03E2D4
/* 072DFC 7F03E2CC 00000000 */   nop
.L7F03E2D0:
/* 072E00 7F03E2D0 8E030004 */  lw    $v1, 4($s0)
.L7F03E2D4:
/* 072E04 7F03E2D4 1060000C */  beqz  $v1, .L7F03E308
/* 072E08 7F03E2D8 00000000 */   nop
/* 072E0C 7F03E2DC 8C780064 */  lw    $t8, 0x64($v1)
/* 072E10 7F03E2E0 33190080 */  andi  $t9, $t8, 0x80
/* 072E14 7F03E2E4 13200008 */  beqz  $t9, .L7F03E308
/* 072E18 7F03E2E8 00000000 */   nop
/* 072E1C 7F03E2EC 8C62006C */  lw    $v0, 0x6c($v1)
/* 072E20 7F03E2F0 8C490000 */  lw    $t1, ($v0)
/* 072E24 7F03E2F4 312A0008 */  andi  $t2, $t1, 8
/* 072E28 7F03E2F8 11400003 */  beqz  $t2, .L7F03E308
/* 072E2C 7F03E2FC 00000000 */   nop
/* 072E30 7F03E300 10000001 */  b     .L7F03E308
/* 072E34 7F03E304 244600CC */   addiu $a2, $v0, 0xcc
.L7F03E308:
/* 072E38 7F03E308 90CB0000 */  lbu   $t3, ($a2)
/* 072E3C 7F03E30C 240500FF */  li    $a1, 255
/* 072E40 7F03E310 00004025 */  move  $t0, $zero
/* 072E44 7F03E314 10AB0009 */  beq   $a1, $t3, .L7F03E33C
/* 072E48 7F03E318 27A20050 */   addiu $v0, $sp, 0x50
/* 072E4C 7F03E31C 00C01825 */  move  $v1, $a2
/* 072E50 7F03E320 90C40000 */  lbu   $a0, ($a2)
.L7F03E324:
/* 072E54 7F03E324 AC440000 */  sw    $a0, ($v0)
/* 072E58 7F03E328 90640001 */  lbu   $a0, 1($v1)
/* 072E5C 7F03E32C 25080001 */  addiu $t0, $t0, 1
/* 072E60 7F03E330 24420004 */  addiu $v0, $v0, 4
/* 072E64 7F03E334 14A4FFFB */  bne   $a1, $a0, .L7F03E324
/* 072E68 7F03E338 24630001 */   addiu $v1, $v1, 1
.L7F03E33C:
/* 072E6C 7F03E33C AFA80048 */  sw    $t0, 0x48($sp)
/* 072E70 7F03E340 10000010 */  b     .L7F03E384
/* 072E74 7F03E344 00004025 */   move  $t0, $zero
.L7F03E348:
/* 072E78 7F03E348 8E0C0014 */  lw    $t4, 0x14($s0)
/* 072E7C 7F03E34C AFA00048 */  sw    $zero, 0x48($sp)
/* 072E80 7F03E350 44076000 */  mfc1  $a3, $f12
/* 072E84 7F03E354 AFAC004C */  sw    $t4, 0x4c($sp)
/* 072E88 7F03E358 8E060010 */  lw    $a2, 0x10($s0)
/* 072E8C 7F03E35C 8E050008 */  lw    $a1, 8($s0)
/* 072E90 7F03E360 27AD0050 */  addiu $t5, $sp, 0x50
/* 072E94 7F03E364 27AE0048 */  addiu $t6, $sp, 0x48
/* 072E98 7F03E368 240F0007 */  li    $t7, 7
/* 072E9C 7F03E36C AFAF0018 */  sw    $t7, 0x18($sp)
/* 072EA0 7F03E370 AFAE0014 */  sw    $t6, 0x14($sp)
/* 072EA4 7F03E374 AFAD0010 */  sw    $t5, 0x10($sp)
/* 072EA8 7F03E378 0FC2C86C */  jal   sub_GAME_7F0B21B0
/* 072EAC 7F03E37C 27A4004C */   addiu $a0, $sp, 0x4c
/* 072EB0 7F03E380 00004025 */  move  $t0, $zero
.L7F03E384:
/* 072EB4 7F03E384 24180007 */  li    $t8, 7
/* 072EB8 7F03E388 AFB80010 */  sw    $t8, 0x10($sp)
/* 072EBC 7F03E38C 8FA40074 */  lw    $a0, 0x74($sp)
/* 072EC0 7F03E390 8FA50078 */  lw    $a1, 0x78($sp)
/* 072EC4 7F03E394 27A60050 */  addiu $a2, $sp, 0x50
/* 072EC8 7F03E398 27A70048 */  addiu $a3, $sp, 0x48
/* 072ECC 7F03E39C 0FC2E8B5 */  jal   sub_GAME_7F0BA2D4
/* 072ED0 7F03E3A0 AFA80044 */   sw    $t0, 0x44($sp)
/* 072ED4 7F03E3A4 8FB90048 */  lw    $t9, 0x48($sp)
/* 072ED8 7F03E3A8 8FA80044 */  lw    $t0, 0x44($sp)
/* 072EDC 7F03E3AC 27A20050 */  addiu $v0, $sp, 0x50
/* 072EE0 7F03E3B0 1B20000B */  blez  $t9, .L7F03E3E0
/* 072EE4 7F03E3B4 240B00FF */   li    $t3, 255
/* 072EE8 7F03E3B8 02001825 */  move  $v1, $s0
/* 072EEC 7F03E3BC 8C490000 */  lw    $t1, ($v0)
.L7F03E3C0:
/* 072EF0 7F03E3C0 25080001 */  addiu $t0, $t0, 1
/* 072EF4 7F03E3C4 24420004 */  addiu $v0, $v0, 4
/* 072EF8 7F03E3C8 A069002C */  sb    $t1, 0x2c($v1)
/* 072EFC 7F03E3CC 8FAA0048 */  lw    $t2, 0x48($sp)
/* 072F00 7F03E3D0 24630001 */  addiu $v1, $v1, 1
/* 072F04 7F03E3D4 010A082A */  slt   $at, $t0, $t2
/* 072F08 7F03E3D8 5420FFF9 */  bnezl $at, .L7F03E3C0
/* 072F0C 7F03E3DC 8C490000 */   lw    $t1, ($v0)
.L7F03E3E0:
/* 072F10 7F03E3E0 02086021 */  addu  $t4, $s0, $t0
/* 072F14 7F03E3E4 A18B002C */  sb    $t3, 0x2c($t4)
/* 072F18 7F03E3E8 8FBF002C */  lw    $ra, 0x2c($sp)
/* 072F1C 7F03E3EC 8FB00028 */  lw    $s0, 0x28($sp)
/* 072F20 7F03E3F0 27BD0070 */  addiu $sp, $sp, 0x70
/* 072F24 7F03E3F4 03E00008 */  jr    $ra
/* 072F28 7F03E3F8 00000000 */   nop
)
#endif


/**
 * Given a list of rooms (terminated by -1), populate the propnums
 * list based on which props are in any of those rooms.
 * PD: roomGetProps
 */
void roomGetProps(s32 *rooms)
{
    s16 *writeptr = ptr_list_object_lookup_indices;
    s32 room;
    s32 i;
    s32 j;

    room = *rooms;

    // Iterate rooms
    while (room >= 0)
    {
        // Find the chunk to start at
        s32 chunkindex = RoomPropListChunkIndexes[room];

        // Iterate the chunks
        while (chunkindex >= 0)
        {
            // Iterate the propnums within each chunk
            for (i = 0; i < 15; i++)
            {
                s32 propnum = RoomPropListChunks[chunkindex].propnums[i];

                if (propnum >= 0)
                {
                    // Check if it's in the list already
                    s16 *ptr = ptr_list_object_lookup_indices;

                    while (ptr < writeptr)
                    {
                        if (*ptr == propnum) { break; }
                        ptr++;
                    }

                    if (ptr == writeptr)
                    {
                        // Prop is not in the list, so insert it
                        *writeptr = propnum;
                        writeptr++;
                    }
                }
            }

            chunkindex = RoomPropListChunks[chunkindex].propnums[15];
        }

        rooms++;
        room = *rooms;
    }

    *writeptr = -1;
    writeptr++;
    num_obj_position_data_entries = writeptr - ptr_list_object_lookup_indices;
}


void propsDefragRoomProps(void)
{
	s32 i;
	s32 j;
	s32 k;

	// Iterate rooms
	for (i = 0; i < g_MaxNumRooms; i++)
    {
		s32 previndex = RoomPropListChunkIndexes[i];

		if (previndex >= 0)
        {
			s32 nextindex = RoomPropListChunks[previndex].propnums[0xF];

			// Iterate this room's chunks but skip the first
			while (nextindex >= 0)
            {
				// Iterate propnums within this chunk
				for (j = 0; j < 15; j++)
                {
					// If this propnum is unallocated
					if (RoomPropListChunks[previndex].propnums[j] < 0)
                    {
						// Iterate forward through the chunk list and find a
						// propnum to move back to the prev chunk
						for (k = 0; k < 15; k++)
                        {
							if (RoomPropListChunks[nextindex].propnums[k] >= 0)
                            {
								RoomPropListChunks[previndex].propnums[j] = RoomPropListChunks[nextindex].propnums[k];
								RoomPropListChunks[nextindex].propnums[k] = -1;
								break;
							}
						}

						// Check if there are more propnums in the future chunk
						for (; k < 15; k++)
                        {
							if (RoomPropListChunks[nextindex].propnums[k] >= 0)
                            {
								break;
							}
						}

						if (k == 15)
                        {
							// There's no more propnums, so this chunk can be removed
							RoomPropListChunks[nextindex].propnums[0] = -2;
							RoomPropListChunks[previndex].propnums[15] = RoomPropListChunks[nextindex].propnums[15];

							nextindex = RoomPropListChunks[previndex].propnums[15];

							if (nextindex < 0)
                            {
								break;
							}
						}
					}
				}

				if (nextindex >= 0)
                {
					previndex = nextindex;
					nextindex = RoomPropListChunks[nextindex].propnums[15];
				}
			}
		}
	}
}


void removed_debug_roomblocks_feature(void)
{
    /* gleened from debug
    
        fVar1 = 1.0f / sqrtf(((param_2 * param_2) + (param_3*param_3)) + (param_4*param_4));
        param_2 *= fvar1;
        param_3 *= fvar1;
        param_4 *= fvar1;

        param_1 *= 0.017453292; //Deg2Rad?

        fVar1       = 1.0 - cosf(param_1);
        fVar2       = param_2 * param_3 * fVar1;
        fVar3       = param_3 * param_4 * fVar1;
        fVar1       = param_4 * param_2 * fVar1;

        matrix_4x4_set_identity(param_5);

        *param_5    = param_2 * param_2 + cosf(param_1) * (1.0 - param_2 * param_2);
        param_5[9]  = fVar3 - param_2 * sinf(param_1);
        param_5[6]  = fVar3 + param_2 * sinf(param_1);
        param_5[5]  = param_3 * param_3 + cosf(param_1) * (1.0 - param_3 * param_3);
        param_5[8]  = fVar1 + param_3 * sinf(param_1);
        param_5[2]  = fVar1 - param_3 * sinf(param_1);
        param_5[10] = param_4 * param_4 + cosf(param_1) * (1.0 - param_4 * param_4);
        param_5[4]  = fVar2 - param_4 * sinf(param_1);
        param_5[1]  = fVar2 + param_4 * sinf(param_1);
        */
}


/**
 * NTSC address 0x7F03E6A0.
*/
void sub_GAME_7F03E6A0(PropRecord *prop)
{
    struct LinkRecord *link;
    struct ObjectRecord *obj;

    obj = prop->obj;

    if (obj->runtime_bitflags & RUNTIMEBITFLAG_00000001)
    {
        for (link = g_LevelLoadPropSwitch; link != NULL; link = link->next)
        {
            if (prop == link->first)
            {
                if (link->second != NULL)
                {
                    doorActivateWrapper(link->second);
                }
            }
        }
    }
}



bool doorIsPadlockFree(DoorRecord* door)
{
    if (door->runtime_bitflags & RUNTIMEBITFLAG_PADLOCKEDDOOR)
    {
        LockDoorRecord *padlockeddoor = g_LevelLoadPropLockDoor;

        while (padlockeddoor)
        {
            if (door == padlockeddoor->door
                    && padlockeddoor->lock
                    && padlockeddoor->lock->prop
                    && objIsHealthy(padlockeddoor->lock)) {
                return FALSE;
            }

            padlockeddoor = padlockeddoor->next;
        }
    }

    return TRUE;
}


bool objCanPickupFromSafe(ObjectRecord *obj)
{
    if (obj->flags2 & PROPFLAG2_LINKEDTOSAFE)
    {
        SafeObjectRecord *link = g_LevelLoadPropSafeItem;

        while (link)
        {
            ObjectRecord *loopobj = link->item;

            if (obj == link->item && link->door && link->door->prop)
            {
                if (link->door->openPosition <= 0.5f)
                {
                    return FALSE;
                }
            }

            link = link->next;
        }
    }

    return TRUE;
}


void sub_GAME_7F03E830(ObjectRecord* arg0)
{
    PropRecord* prop = arg0->prop;
    stanGetPositionYValue(prop->stan, prop->pos.x, prop->pos.z);
}

f32 chrpropBBOXGetXmin(ModelRoData_BoundingBoxRecord *modelBoundingBox)
{
    return modelBoundingBox->Bounds.xmin;
}

f32 chrpropBBOXGetYmin(ModelRoData_BoundingBoxRecord *modelBoundingBox)
{
    return modelBoundingBox->Bounds.ymin;
}

f32 chrpropBBOXGetYmax(ModelRoData_BoundingBoxRecord *modelBoundingBox)
{
    return modelBoundingBox->Bounds.ymax;
}
f32 chrpropBBOXGetZmin(ModelRoData_BoundingBoxRecord *modelBoundingBox)
{
    return modelBoundingBox->Bounds.zmin;
}







/**
 * Address 0x7F03E87C.
*/
f32 chrpropSumMatrixPosX(struct ModelRoData_BoundingBoxRecord *bbox, Mtxf *arg1)
{
    f32 phi_f2;

    phi_f2 = 0.0f;

    if (arg1->m[0][0] >= 0.0f)
    {
        phi_f2 += (bbox->Bounds.xmin * arg1->m[0][0]);
    }
    else
    {
        phi_f2 += (bbox->Bounds.xmax * arg1->m[0][0]);
    }

    if (arg1->m[1][0] >= 0.0f)
    {
        phi_f2 += (bbox->Bounds.ymin * arg1->m[1][0]);
    }
    else
    {
        phi_f2 += (bbox->Bounds.ymax * arg1->m[1][0]);
    }

    if (arg1->m[2][0] >= 0.0f)
    {
        phi_f2 += (bbox->Bounds.zmin * arg1->m[2][0]);
    }
    else
    {
        phi_f2 += (bbox->Bounds.zmax * arg1->m[2][0]);
    }

    return phi_f2;
}




/**
 * Address 0x7F03E91C.
*/
f32 chrpropSumMatrixNegX(struct ModelRoData_BoundingBoxRecord *bbox, Mtxf *arg1)
{
    f32 phi_f2;

    phi_f2 = 0.0f;

    if (arg1->m[0][0] <= 0.0f)
    {
        phi_f2 += (bbox->Bounds.xmin * arg1->m[0][0]);
    }
    else
    {
        phi_f2 += (bbox->Bounds.xmax * arg1->m[0][0]);
    }

    if (arg1->m[1][0] <= 0.0f)
    {
        phi_f2 += (bbox->Bounds.ymin * arg1->m[1][0]);
    }
    else
    {
        phi_f2 += (bbox->Bounds.ymax * arg1->m[1][0]);
    }

    if (arg1->m[2][0] <= 0.0f)
    {
        phi_f2 += (bbox->Bounds.zmin * arg1->m[2][0]);
    }
    else
    {
        phi_f2 += (bbox->Bounds.zmax * arg1->m[2][0]);
    }

    return phi_f2;
}




/**
 * Address 0x7F03E9BC.
*/
f32 chrpropSumMatrixPosY(struct ModelRoData_BoundingBoxRecord *bbox, Mtxf *arg1)
{
    f32 phi_f2;

    phi_f2 = 0.0f;

    if (arg1->m[0][1] >= 0.0f)
    {
        phi_f2 += (bbox->Bounds.xmin * arg1->m[0][1]);
    }
    else
    {
        phi_f2 += (bbox->Bounds.xmax * arg1->m[0][1]);
    }

    if (arg1->m[1][1] >= 0.0f)
    {
        phi_f2 += (bbox->Bounds.ymin * arg1->m[1][1]);
    }
    else
    {
        phi_f2 += (bbox->Bounds.ymax * arg1->m[1][1]);
    }

    if (arg1->m[2][1] >= 0.0f)
    {
        phi_f2 += (bbox->Bounds.zmin * arg1->m[2][1]);
    }
    else
    {
        phi_f2 += (bbox->Bounds.zmax * arg1->m[2][1]);
    }

    return phi_f2;
}



/**
 * Address 0x7F03EA5C.
*/
f32 chrpropSumMatrixNegY(struct ModelRoData_BoundingBoxRecord *bbox, Mtxf *arg1)
{
    f32 phi_f2;

    phi_f2 = 0.0f;

    if (arg1->m[0][1] <= 0.0f)
    {
        phi_f2 += (bbox->Bounds.xmin * arg1->m[0][1]);
    }
    else
    {
        phi_f2 += (bbox->Bounds.xmax * arg1->m[0][1]);
    }

    if (arg1->m[1][1] <= 0.0f)
    {
        phi_f2 += (bbox->Bounds.ymin * arg1->m[1][1]);
    }
    else
    {
        phi_f2 += (bbox->Bounds.ymax * arg1->m[1][1]);
    }

    if (arg1->m[2][1] <= 0.0f)
    {
        phi_f2 += (bbox->Bounds.zmin * arg1->m[2][1]);
    }
    else
    {
        phi_f2 += (bbox->Bounds.zmax * arg1->m[2][1]);
    }

    return phi_f2;
}



/**
 * Address 0x7F03EAFC.
*/
f32 chrpropSumMatrixPosZ(struct ModelRoData_BoundingBoxRecord *bbox, Mtxf *arg1)
{
    f32 phi_f2;

    phi_f2 = 0.0f;

    if (arg1->m[0][2] >= 0.0f)
    {
        phi_f2 += (bbox->Bounds.xmin * arg1->m[0][2]);
    }
    else
    {
        phi_f2 += (bbox->Bounds.xmax * arg1->m[0][2]);
    }

    if (arg1->m[1][2] >= 0.0f)
    {
        phi_f2 += (bbox->Bounds.ymin * arg1->m[1][2]);
    }
    else
    {
        phi_f2 += (bbox->Bounds.ymax * arg1->m[1][2]);
    }

    if (arg1->m[2][2] >= 0.0f)
    {
        phi_f2 += (bbox->Bounds.zmin * arg1->m[2][2]);
    }
    else
    {
        phi_f2 += (bbox->Bounds.zmax * arg1->m[2][2]);
    }

    return phi_f2;
}



/**
 * Address 0x7F03EB9C.
*/
f32 chrpropSumMatrixNegZ(struct ModelRoData_BoundingBoxRecord *bbox, Mtxf *arg1)
{
    f32 phi_f2;

    phi_f2 = 0.0f;

    if (arg1->m[0][2] <= 0.0f)
    {
        phi_f2 += (bbox->Bounds.xmin * arg1->m[0][2]);
    }
    else
    {
        phi_f2 += (bbox->Bounds.xmax * arg1->m[0][2]);
    }

    if (arg1->m[1][2] <= 0.0f)
    {
        phi_f2 += (bbox->Bounds.ymin * arg1->m[1][2]);
    }
    else
    {
        phi_f2 += (bbox->Bounds.ymax * arg1->m[1][2]);
    }

    if (arg1->m[2][2] <= 0.0f)
    {
        phi_f2 += (bbox->Bounds.zmin * arg1->m[2][2]);
    }
    else
    {
        phi_f2 += (bbox->Bounds.zmax * arg1->m[2][2]);
    }

    return phi_f2;
}




/**
 * Unreferenced.
 * 0x7F03EC3C.
*/
void sub_GAME_7F03EC3C(struct ModelRoData_BoundingBoxRecord *bbox, Mtxf *arg1, struct coord3d *arg2)
{
    if (arg1->m[0][2] <= 0.0f)
    {
        arg2->f[0] = bbox->Bounds.xmin;
    }
    else
    {
        arg2->f[0] = bbox->Bounds.xmax;
    }

    if (arg1->m[1][2] <= 0.0f)
    {
        arg2->f[1] = bbox->Bounds.ymin;
    }
    else
    {
        arg2->f[1] = bbox->Bounds.ymax;
    }

    if (arg1->m[2][2] <= 0.0f)
    {
        arg2->f[2] = bbox->Bounds.zmin;
    }
    else
    {
        arg2->f[2] = bbox->Bounds.zmax;
    }
}





#ifdef NONMATCHING
void sub_GAME_7F03ECC0(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, void* arg6, void* arg7, s32* arg8) {

}
#else
/* This forward declaration is required for sub_GAME_7F03F540() to link until sub_GAME_7F03ECC0() is properly decompiled */
void sub_GAME_7F03ECC0(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, Mtxf* arg6, struct rect4f* arg7, struct collision_data* arg8);
GLOBAL_ASM(
.text
glabel sub_GAME_7F03ECC0
/* 0737F0 7F03ECC0 27BDFE20 */  addiu $sp, $sp, -0x1e0
/* 0737F4 7F03ECC4 AFA601E8 */  sw    $a2, 0x1e8($sp)
/* 0737F8 7F03ECC8 8FA601F8 */  lw    $a2, 0x1f8($sp)
/* 0737FC 7F03ECCC E7AE01E4 */  swc1  $f14, 0x1e4($sp)
/* 073800 7F03ECD0 AFA701EC */  sw    $a3, 0x1ec($sp)
/* 073804 7F03ECD4 C4C40000 */  lwc1  $f4, ($a2)
/* 073808 7F03ECD8 46006021 */  cvt.d.s $f0, $f12
/* 07380C 7F03ECDC 27AE0160 */  addiu $t6, $sp, 0x160
/* 073810 7F03ECE0 460021A1 */  cvt.d.s $f6, $f4
/* 073814 7F03ECE4 0000C900 */  sll   $t9, $zero, 4
/* 073818 7F03ECE8 F7A600F0 */  sdc1  $f6, 0xf0($sp)
/* 07381C 7F03ECEC C4CA0008 */  lwc1  $f10, 8($a2)
/* 073820 7F03ECF0 032E4821 */  addu  $t1, $t9, $t6
/* 073824 7F03ECF4 00005025 */  move  $t2, $zero
/* 073828 7F03ECF8 46005221 */  cvt.d.s $f8, $f10
/* 07382C 7F03ECFC 000AC900 */  sll   $t9, $t2, 4
/* 073830 7F03ED00 F7A800E8 */  sdc1  $f8, 0xe8($sp)
/* 073834 7F03ED04 C4C40010 */  lwc1  $f4, 0x10($a2)
/* 073838 7F03ED08 27AE0160 */  addiu $t6, $sp, 0x160
/* 07383C 7F03ED0C 032E4021 */  addu  $t0, $t9, $t6
/* 073840 7F03ED10 460021A1 */  cvt.d.s $f6, $f4
/* 073844 7F03ED14 00002025 */  move  $a0, $zero
/* 073848 7F03ED18 F7A600E0 */  sdc1  $f6, 0xe0($sp)
/* 07384C 7F03ED1C C4CA0018 */  lwc1  $f10, 0x18($a2)
/* 073850 7F03ED20 0004C900 */  sll   $t9, $a0, 4
/* 073854 7F03ED24 27AE0160 */  addiu $t6, $sp, 0x160
/* 073858 7F03ED28 46005221 */  cvt.d.s $f8, $f10
/* 07385C 7F03ED2C 032E3821 */  addu  $a3, $t9, $t6
/* 073860 7F03ED30 F7A800D8 */  sdc1  $f8, 0xd8($sp)
/* 073864 7F03ED34 C4C60028 */  lwc1  $f6, 0x28($a2)
/* 073868 7F03ED38 C4C40020 */  lwc1  $f4, 0x20($a2)
/* 07386C 7F03ED3C D7A800F0 */  ldc1  $f8, 0xf0($sp)
/* 073870 7F03ED40 460032A1 */  cvt.d.s $f10, $f6
/* 073874 7F03ED44 C7A601E8 */  lwc1  $f6, 0x1e8($sp)
/* 073878 7F03ED48 F7AA00C8 */  sdc1  $f10, 0xc8($sp)
/* 07387C 7F03ED4C D7AA00E0 */  ldc1  $f10, 0xe0($sp)
/* 073880 7F03ED50 460024A1 */  cvt.d.s $f18, $f4
/* 073884 7F03ED54 46204102 */  mul.d $f4, $f8, $f0
/* 073888 7F03ED58 460030A1 */  cvt.d.s $f2, $f6
/* 07388C 7F03ED5C F7AA0008 */  sdc1  $f10, 8($sp)
/* 073890 7F03ED60 F7A80000 */  sdc1  $f8, ($sp)
/* 073894 7F03ED64 46225182 */  mul.d $f6, $f10, $f2
/* 073898 7F03ED68 C7AA01F0 */  lwc1  $f10, 0x1f0($sp)
/* 07389C 7F03ED6C 00005825 */  move  $t3, $zero
/* 0738A0 7F03ED70 000BC900 */  sll   $t9, $t3, 4
/* 0738A4 7F03ED74 46005421 */  cvt.d.s $f16, $f10
/* 0738A8 7F03ED78 F7A400A0 */  sdc1  $f4, 0xa0($sp)
/* 0738AC 7F03ED7C 46309282 */  mul.d $f10, $f18, $f16
/* 0738B0 7F03ED80 F7A40010 */  sdc1  $f4, 0x10($sp)
/* 0738B4 7F03ED84 46262200 */  add.d $f8, $f4, $f6
/* 0738B8 7F03ED88 F7A60098 */  sdc1  $f6, 0x98($sp)
/* 0738BC 7F03ED8C F7A60018 */  sdc1  $f6, 0x18($sp)
/* 0738C0 7F03ED90 27AE0160 */  addiu $t6, $sp, 0x160
/* 0738C4 7F03ED94 F7A80038 */  sdc1  $f8, 0x38($sp)
/* 0738C8 7F03ED98 00001025 */  move  $v0, $zero
/* 0738CC 7F03ED9C 462A4100 */  add.d $f4, $f8, $f10
/* 0738D0 7F03EDA0 F7AA0090 */  sdc1  $f10, 0x90($sp)
/* 0738D4 7F03EDA4 27A50170 */  addiu $a1, $sp, 0x170
/* 0738D8 7F03EDA8 24030001 */  li    $v1, 1
/* 0738DC 7F03EDAC F7A40160 */  sdc1  $f4, 0x160($sp)
/* 0738E0 7F03EDB0 D7A400E8 */  ldc1  $f4, 0xe8($sp)
/* 0738E4 7F03EDB4 032E6021 */  addu  $t4, $t9, $t6
/* 0738E8 7F03EDB8 27AD0130 */  addiu $t5, $sp, 0x130
/* 0738EC 7F03EDBC 46202102 */  mul.d $f4, $f4, $f0
/* 0738F0 7F03EDC0 F7A40088 */  sdc1  $f4, 0x88($sp)
/* 0738F4 7F03EDC4 D7A400D8 */  ldc1  $f4, 0xd8($sp)
/* 0738F8 7F03EDC8 46222102 */  mul.d $f4, $f4, $f2
/* 0738FC 7F03EDCC F7A40080 */  sdc1  $f4, 0x80($sp)
/* 073900 7F03EDD0 D7A60080 */  ldc1  $f6, 0x80($sp)
/* 073904 7F03EDD4 D7A40088 */  ldc1  $f4, 0x88($sp)
/* 073908 7F03EDD8 46262100 */  add.d $f4, $f4, $f6
/* 07390C 7F03EDDC D7A600C8 */  ldc1  $f6, 0xc8($sp)
/* 073910 7F03EDE0 F7A40078 */  sdc1  $f4, 0x78($sp)
/* 073914 7F03EDE4 46303102 */  mul.d $f4, $f6, $f16
/* 073918 7F03EDE8 D7A60078 */  ldc1  $f6, 0x78($sp)
/* 07391C 7F03EDEC 46243180 */  add.d $f6, $f6, $f4
/* 073920 7F03EDF0 F7A40070 */  sdc1  $f4, 0x70($sp)
/* 073924 7F03EDF4 C7A401F4 */  lwc1  $f4, 0x1f4($sp)
/* 073928 7F03EDF8 F7A60168 */  sdc1  $f6, 0x168($sp)
/* 07392C 7F03EDFC 460021A1 */  cvt.d.s $f6, $f4
/* 073930 7F03EE00 F7A600A8 */  sdc1  $f6, 0xa8($sp)
/* 073934 7F03EE04 46269182 */  mul.d $f6, $f18, $f6
/* 073938 7F03EE08 D7A400A8 */  ldc1  $f4, 0xa8($sp)
/* 07393C 7F03EE0C F7A60068 */  sdc1  $f6, 0x68($sp)
/* 073940 7F03EE10 46264180 */  add.d $f6, $f8, $f6
/* 073944 7F03EE14 D7A800C8 */  ldc1  $f8, 0xc8($sp)
/* 073948 7F03EE18 46244302 */  mul.d $f12, $f8, $f4
/* 07394C 7F03EE1C F7A60170 */  sdc1  $f6, 0x170($sp)
/* 073950 7F03EE20 D7A60078 */  ldc1  $f6, 0x78($sp)
/* 073954 7F03EE24 C7A401EC */  lwc1  $f4, 0x1ec($sp)
/* 073958 7F03EE28 46002021 */  cvt.d.s $f0, $f4
/* 07395C 7F03EE2C 462C3200 */  add.d $f8, $f6, $f12
/* 073960 7F03EE30 D7A60008 */  ldc1  $f6, 8($sp)
/* 073964 7F03EE34 46203382 */  mul.d $f14, $f6, $f0
/* 073968 7F03EE38 F7A80178 */  sdc1  $f8, 0x178($sp)
/* 07396C 7F03EE3C D7A80010 */  ldc1  $f8, 0x10($sp)
/* 073970 7F03EE40 D7A600D8 */  ldc1  $f6, 0xd8($sp)
/* 073974 7F03EE44 46203402 */  mul.d $f16, $f6, $f0
/* 073978 7F03EE48 462E4080 */  add.d $f2, $f8, $f14
/* 07397C 7F03EE4C D7A80088 */  ldc1  $f8, 0x88($sp)
/* 073980 7F03EE50 F7AE0038 */  sdc1  $f14, 0x38($sp)
/* 073984 7F03EE54 462A1100 */  add.d $f4, $f2, $f10
/* 073988 7F03EE58 46304480 */  add.d $f18, $f8, $f16
/* 07398C 7F03EE5C F7A40180 */  sdc1  $f4, 0x180($sp)
/* 073990 7F03EE60 D7A40070 */  ldc1  $f4, 0x70($sp)
/* 073994 7F03EE64 D7A80068 */  ldc1  $f8, 0x68($sp)
/* 073998 7F03EE68 F7B20030 */  sdc1  $f18, 0x30($sp)
/* 07399C 7F03EE6C 46249180 */  add.d $f6, $f18, $f4
/* 0739A0 7F03EE70 46281100 */  add.d $f4, $f2, $f8
/* 0739A4 7F03EE74 F7A60188 */  sdc1  $f6, 0x188($sp)
/* 0739A8 7F03EE78 D7A60000 */  ldc1  $f6, ($sp)
/* 0739AC 7F03EE7C 462C9200 */  add.d $f8, $f18, $f12
/* 0739B0 7F03EE80 F7A40190 */  sdc1  $f4, 0x190($sp)
/* 0739B4 7F03EE84 C7A401E4 */  lwc1  $f4, 0x1e4($sp)
/* 0739B8 7F03EE88 F7A80198 */  sdc1  $f8, 0x198($sp)
/* 0739BC 7F03EE8C 46002021 */  cvt.d.s $f0, $f4
/* 0739C0 7F03EE90 D7A400E8 */  ldc1  $f4, 0xe8($sp)
/* 0739C4 7F03EE94 46203202 */  mul.d $f8, $f6, $f0
/* 0739C8 7F03EE98 D7A60018 */  ldc1  $f6, 0x18($sp)
/* 0739CC 7F03EE9C 46202382 */  mul.d $f14, $f4, $f0
/* 0739D0 7F03EEA0 F7A80088 */  sdc1  $f8, 0x88($sp)
/* 0739D4 7F03EEA4 46264080 */  add.d $f2, $f8, $f6
/* 0739D8 7F03EEA8 D7A60080 */  ldc1  $f6, 0x80($sp)
/* 0739DC 7F03EEAC 462A1200 */  add.d $f8, $f2, $f10
/* 0739E0 7F03EEB0 46267480 */  add.d $f18, $f14, $f6
/* 0739E4 7F03EEB4 F7A801A0 */  sdc1  $f8, 0x1a0($sp)
/* 0739E8 7F03EEB8 D7A80070 */  ldc1  $f8, 0x70($sp)
/* 0739EC 7F03EEBC D7A60068 */  ldc1  $f6, 0x68($sp)
/* 0739F0 7F03EEC0 46289100 */  add.d $f4, $f18, $f8
/* 0739F4 7F03EEC4 46261200 */  add.d $f8, $f2, $f6
/* 0739F8 7F03EEC8 D7A60088 */  ldc1  $f6, 0x88($sp)
/* 0739FC 7F03EECC F7A401A8 */  sdc1  $f4, 0x1a8($sp)
/* 073A00 7F03EED0 462C9100 */  add.d $f4, $f18, $f12
/* 073A04 7F03EED4 F7A801B0 */  sdc1  $f8, 0x1b0($sp)
/* 073A08 7F03EED8 D7A80038 */  ldc1  $f8, 0x38($sp)
/* 073A0C 7F03EEDC 46307080 */  add.d $f2, $f14, $f16
/* 073A10 7F03EEE0 F7A401B8 */  sdc1  $f4, 0x1b8($sp)
/* 073A14 7F03EEE4 46283000 */  add.d $f0, $f6, $f8
/* 073A18 7F03EEE8 D7A60070 */  ldc1  $f6, 0x70($sp)
/* 073A1C 7F03EEEC 462A0100 */  add.d $f4, $f0, $f10
/* 073A20 7F03EEF0 D7AA0068 */  ldc1  $f10, 0x68($sp)
/* 073A24 7F03EEF4 46261200 */  add.d $f8, $f2, $f6
/* 073A28 7F03EEF8 F7A401C0 */  sdc1  $f4, 0x1c0($sp)
/* 073A2C 7F03EEFC 462C1180 */  add.d $f6, $f2, $f12
/* 073A30 7F03EF00 F7A801C8 */  sdc1  $f8, 0x1c8($sp)
/* 073A34 7F03EF04 462A0100 */  add.d $f4, $f0, $f10
/* 073A38 7F03EF08 F7A601D8 */  sdc1  $f6, 0x1d8($sp)
/* 073A3C 7F03EF0C F7A401D0 */  sdc1  $f4, 0x1d0($sp)
/* 073A40 7F03EF10 D5200000 */  ldc1  $f0, ($t1)
.L7F03EF14:
/* 073A44 7F03EF14 D4A20000 */  ldc1  $f2, ($a1)
/* 073A48 7F03EF18 00037900 */  sll   $t7, $v1, 4
/* 073A4C 7F03EF1C 27B80160 */  addiu $t8, $sp, 0x160
/* 073A50 7F03EF20 4620103C */  c.lt.d $f2, $f0
/* 073A54 7F03EF24 00000000 */  nop
/* 073A58 7F03EF28 4503000C */  bc1tl .L7F03EF5C
/* 073A5C 7F03EF2C 01F84821 */   addu  $t1, $t7, $t8
/* 073A60 7F03EF30 46201032 */  c.eq.d $f2, $f0
/* 073A64 7F03EF34 00000000 */  nop
/* 073A68 7F03EF38 4502000B */  bc1fl .L7F03EF68
/* 073A6C 7F03EF3C 24630001 */   addiu $v1, $v1, 1
/* 073A70 7F03EF40 D4A80008 */  ldc1  $f8, 8($a1)
/* 073A74 7F03EF44 D52A0008 */  ldc1  $f10, 8($t1)
/* 073A78 7F03EF48 462A403C */  c.lt.d $f8, $f10
/* 073A7C 7F03EF4C 00000000 */  nop
/* 073A80 7F03EF50 45020005 */  bc1fl .L7F03EF68
/* 073A84 7F03EF54 24630001 */   addiu $v1, $v1, 1
/* 073A88 7F03EF58 01F84821 */  addu  $t1, $t7, $t8
.L7F03EF5C:
/* 073A8C 7F03EF5C D5200000 */  ldc1  $f0, ($t1)
/* 073A90 7F03EF60 00601025 */  move  $v0, $v1
/* 073A94 7F03EF64 24630001 */  addiu $v1, $v1, 1
.L7F03EF68:
/* 073A98 7F03EF68 28610008 */  slti  $at, $v1, 8
/* 073A9C 7F03EF6C 1420FFE9 */  bnez  $at, .L7F03EF14
/* 073AA0 7F03EF70 24A50010 */   addiu $a1, $a1, 0x10
/* 073AA4 7F03EF74 24030001 */  li    $v1, 1
/* 073AA8 7F03EF78 27A50170 */  addiu $a1, $sp, 0x170
.L7F03EF7C:
/* 073AAC 7F03EF7C D50C0008 */  ldc1  $f12, 8($t0)
/* 073AB0 7F03EF80 D4A20008 */  ldc1  $f2, 8($a1)
/* 073AB4 7F03EF84 00037900 */  sll   $t7, $v1, 4
/* 073AB8 7F03EF88 27B80160 */  addiu $t8, $sp, 0x160
/* 073ABC 7F03EF8C 4622603C */  c.lt.d $f12, $f2
/* 073AC0 7F03EF90 00000000 */  nop
/* 073AC4 7F03EF94 4503000C */  bc1tl .L7F03EFC8
/* 073AC8 7F03EF98 00605025 */   move  $t2, $v1
/* 073ACC 7F03EF9C 462C1032 */  c.eq.d $f2, $f12
/* 073AD0 7F03EFA0 00000000 */  nop
/* 073AD4 7F03EFA4 4502000A */  bc1fl .L7F03EFD0
/* 073AD8 7F03EFA8 24630001 */   addiu $v1, $v1, 1
/* 073ADC 7F03EFAC D4A40000 */  ldc1  $f4, ($a1)
/* 073AE0 7F03EFB0 D5060000 */  ldc1  $f6, ($t0)
/* 073AE4 7F03EFB4 4626203C */  c.lt.d $f4, $f6
/* 073AE8 7F03EFB8 00000000 */  nop
/* 073AEC 7F03EFBC 45020004 */  bc1fl .L7F03EFD0
/* 073AF0 7F03EFC0 24630001 */   addiu $v1, $v1, 1
/* 073AF4 7F03EFC4 00605025 */  move  $t2, $v1
.L7F03EFC8:
/* 073AF8 7F03EFC8 01F84021 */  addu  $t0, $t7, $t8
/* 073AFC 7F03EFCC 24630001 */  addiu $v1, $v1, 1
.L7F03EFD0:
/* 073B00 7F03EFD0 28610008 */  slti  $at, $v1, 8
/* 073B04 7F03EFD4 1420FFE9 */  bnez  $at, .L7F03EF7C
/* 073B08 7F03EFD8 24A50010 */   addiu $a1, $a1, 0x10
/* 073B0C 7F03EFDC 24030001 */  li    $v1, 1
/* 073B10 7F03EFE0 27A50170 */  addiu $a1, $sp, 0x170
.L7F03EFE4:
/* 073B14 7F03EFE4 D4F00000 */  ldc1  $f16, ($a3)
/* 073B18 7F03EFE8 D4A20000 */  ldc1  $f2, ($a1)
/* 073B1C 7F03EFEC 00037900 */  sll   $t7, $v1, 4
/* 073B20 7F03EFF0 27B80160 */  addiu $t8, $sp, 0x160
/* 073B24 7F03EFF4 4622803C */  c.lt.d $f16, $f2
/* 073B28 7F03EFF8 00000000 */  nop
/* 073B2C 7F03EFFC 4503000C */  bc1tl .L7F03F030
/* 073B30 7F03F000 00602025 */   move  $a0, $v1
/* 073B34 7F03F004 46301032 */  c.eq.d $f2, $f16
/* 073B38 7F03F008 00000000 */  nop
/* 073B3C 7F03F00C 4502000A */  bc1fl .L7F03F038
/* 073B40 7F03F010 24630001 */   addiu $v1, $v1, 1
/* 073B44 7F03F014 D4E80008 */  ldc1  $f8, 8($a3)
/* 073B48 7F03F018 D4AA0008 */  ldc1  $f10, 8($a1)
/* 073B4C 7F03F01C 462A403C */  c.lt.d $f8, $f10
/* 073B50 7F03F020 00000000 */  nop
/* 073B54 7F03F024 45020004 */  bc1fl .L7F03F038
/* 073B58 7F03F028 24630001 */   addiu $v1, $v1, 1
/* 073B5C 7F03F02C 00602025 */  move  $a0, $v1
.L7F03F030:
/* 073B60 7F03F030 01F83821 */  addu  $a3, $t7, $t8
/* 073B64 7F03F034 24630001 */  addiu $v1, $v1, 1
.L7F03F038:
/* 073B68 7F03F038 28610008 */  slti  $at, $v1, 8
/* 073B6C 7F03F03C 1420FFE9 */  bnez  $at, .L7F03EFE4
/* 073B70 7F03F040 24A50010 */   addiu $a1, $a1, 0x10
/* 073B74 7F03F044 24030001 */  li    $v1, 1
/* 073B78 7F03F048 27A50170 */  addiu $a1, $sp, 0x170
.L7F03F04C:
/* 073B7C 7F03F04C D4A20008 */  ldc1  $f2, 8($a1)
/* 073B80 7F03F050 D58C0008 */  ldc1  $f12, 8($t4)
/* 073B84 7F03F054 00037900 */  sll   $t7, $v1, 4
/* 073B88 7F03F058 27B80160 */  addiu $t8, $sp, 0x160
/* 073B8C 7F03F05C 462C103C */  c.lt.d $f2, $f12
/* 073B90 7F03F060 00000000 */  nop
/* 073B94 7F03F064 4503000C */  bc1tl .L7F03F098
/* 073B98 7F03F068 00605825 */   move  $t3, $v1
/* 073B9C 7F03F06C 462C1032 */  c.eq.d $f2, $f12
/* 073BA0 7F03F070 00000000 */  nop
/* 073BA4 7F03F074 4502000A */  bc1fl .L7F03F0A0
/* 073BA8 7F03F078 24630001 */   addiu $v1, $v1, 1
/* 073BAC 7F03F07C D5840000 */  ldc1  $f4, ($t4)
/* 073BB0 7F03F080 D4A60000 */  ldc1  $f6, ($a1)
/* 073BB4 7F03F084 4626203C */  c.lt.d $f4, $f6
/* 073BB8 7F03F088 00000000 */  nop
/* 073BBC 7F03F08C 45020004 */  bc1fl .L7F03F0A0
/* 073BC0 7F03F090 24630001 */   addiu $v1, $v1, 1
/* 073BC4 7F03F094 00605825 */  move  $t3, $v1
.L7F03F098:
/* 073BC8 7F03F098 01F86021 */  addu  $t4, $t7, $t8
/* 073BCC 7F03F09C 24630001 */  addiu $v1, $v1, 1
.L7F03F0A0:
/* 073BD0 7F03F0A0 28610008 */  slti  $at, $v1, 8
/* 073BD4 7F03F0A4 1420FFE9 */  bnez  $at, .L7F03F04C
/* 073BD8 7F03F0A8 24A50010 */   addiu $a1, $a1, 0x10
/* 073BDC 7F03F0AC 00002825 */  move  $a1, $zero
/* 073BE0 7F03F0B0 00001825 */  move  $v1, $zero
.L7F03F0B4:
/* 073BE4 7F03F0B4 5062000B */  beql  $v1, $v0, .L7F03F0E4
/* 073BE8 7F03F0B8 24630001 */   addiu $v1, $v1, 1
/* 073BEC 7F03F0BC 50640009 */  beql  $v1, $a0, .L7F03F0E4
/* 073BF0 7F03F0C0 24630001 */   addiu $v1, $v1, 1
/* 073BF4 7F03F0C4 506A0007 */  beql  $v1, $t2, .L7F03F0E4
/* 073BF8 7F03F0C8 24630001 */   addiu $v1, $v1, 1
/* 073BFC 7F03F0CC 106B0004 */  beq   $v1, $t3, .L7F03F0E0
/* 073C00 7F03F0D0 0005C880 */   sll   $t9, $a1, 2
/* 073C04 7F03F0D4 01B97021 */  addu  $t6, $t5, $t9
/* 073C08 7F03F0D8 ADC30000 */  sw    $v1, ($t6)
/* 073C0C 7F03F0DC 24A50001 */  addiu $a1, $a1, 1
.L7F03F0E0:
/* 073C10 7F03F0E0 24630001 */  addiu $v1, $v1, 1
.L7F03F0E4:
/* 073C14 7F03F0E4 28610008 */  slti  $at, $v1, 8
/* 073C18 7F03F0E8 1420FFF2 */  bnez  $at, .L7F03F0B4
/* 073C1C 7F03F0EC 00000000 */   nop
/* 073C20 7F03F0F0 46200220 */  cvt.s.d $f8, $f0
/* 073C24 7F03F0F4 8FAA01FC */  lw    $t2, 0x1fc($sp)
/* 073C28 7F03F0F8 24050001 */  li    $a1, 1
/* 073C2C 7F03F0FC 27A20130 */  addiu $v0, $sp, 0x130
/* 073C30 7F03F100 E5480000 */  swc1  $f8, ($t2)
/* 073C34 7F03F104 D52A0008 */  ldc1  $f10, 8($t1)
/* 073C38 7F03F108 27AD0140 */  addiu $t5, $sp, 0x140
/* 073C3C 7F03F10C 27A40160 */  addiu $a0, $sp, 0x160
/* 073C40 7F03F110 46205120 */  cvt.s.d $f4, $f10
/* 073C44 7F03F114 E5440004 */  swc1  $f4, 4($t2)
/* 073C48 7F03F118 D5280000 */  ldc1  $f8, ($t1)
/* 073C4C 7F03F11C D5260008 */  ldc1  $f6, 8($t1)
/* 073C50 7F03F120 D5820000 */  ldc1  $f2, ($t4)
/* 073C54 7F03F124 D58C0008 */  ldc1  $f12, 8($t4)
/* 073C58 7F03F128 46224401 */  sub.d $f16, $f8, $f2
/* 073C5C 7F03F12C 462C3381 */  sub.d $f14, $f6, $f12
/* 073C60 7F03F130 8C430000 */  lw    $v1, ($v0)
.L7F03F134:
/* 073C64 7F03F134 00037900 */  sll   $t7, $v1, 4
/* 073C68 7F03F138 008F5821 */  addu  $t3, $a0, $t7
/* 073C6C 7F03F13C D5600000 */  ldc1  $f0, ($t3)
/* 073C70 7F03F140 D5660008 */  ldc1  $f6, 8($t3)
/* 073C74 7F03F144 46220281 */  sub.d $f10, $f0, $f2
/* 073C78 7F03F148 462C3201 */  sub.d $f8, $f6, $f12
/* 073C7C 7F03F14C 462E5102 */  mul.d $f4, $f10, $f14
/* 073C80 7F03F150 00000000 */  nop
/* 073C84 7F03F154 46304282 */  mul.d $f10, $f8, $f16
/* 073C88 7F03F158 462A203C */  c.lt.d $f4, $f10
/* 073C8C 7F03F15C 00000000 */  nop
/* 073C90 7F03F160 4500000A */  bc1f  .L7F03F18C
/* 073C94 7F03F164 00000000 */   nop
/* 073C98 7F03F168 462001A0 */  cvt.s.d $f6, $f0
/* 073C9C 7F03F16C 25420008 */  addiu $v0, $t2, 8
/* 073CA0 7F03F170 24050002 */  li    $a1, 2
/* 073CA4 7F03F174 E4460000 */  swc1  $f6, ($v0)
/* 073CA8 7F03F178 D5680008 */  ldc1  $f8, 8($t3)
/* 073CAC 7F03F17C 46204120 */  cvt.s.d $f4, $f8
/* 073CB0 7F03F180 E4440004 */  swc1  $f4, 4($v0)
/* 073CB4 7F03F184 10000005 */  b     .L7F03F19C
/* 073CB8 7F03F188 D5820000 */   ldc1  $f2, ($t4)
.L7F03F18C:
/* 073CBC 7F03F18C 24420004 */  addiu $v0, $v0, 4
/* 073CC0 7F03F190 004D082B */  sltu  $at, $v0, $t5
/* 073CC4 7F03F194 5420FFE7 */  bnezl $at, .L7F03F134
/* 073CC8 7F03F198 8C430000 */   lw    $v1, ($v0)
.L7F03F19C:
/* 073CCC 7F03F19C 462012A0 */  cvt.s.d $f10, $f2
/* 073CD0 7F03F1A0 0005C0C0 */  sll   $t8, $a1, 3
/* 073CD4 7F03F1A4 01585821 */  addu  $t3, $t2, $t8
/* 073CD8 7F03F1A8 256B0008 */  addiu $t3, $t3, 8
/* 073CDC 7F03F1AC E56AFFF8 */  swc1  $f10, -8($t3)
/* 073CE0 7F03F1B0 D5860008 */  ldc1  $f6, 8($t4)
/* 073CE4 7F03F1B4 24A50001 */  addiu $a1, $a1, 1
/* 073CE8 7F03F1B8 27A20130 */  addiu $v0, $sp, 0x130
/* 073CEC 7F03F1BC 46203220 */  cvt.s.d $f8, $f6
/* 073CF0 7F03F1C0 27AD0140 */  addiu $t5, $sp, 0x140
/* 073CF4 7F03F1C4 E568FFFC */  swc1  $f8, -4($t3)
/* 073CF8 7F03F1C8 D58A0000 */  ldc1  $f10, ($t4)
/* 073CFC 7F03F1CC D5840008 */  ldc1  $f4, 8($t4)
/* 073D00 7F03F1D0 D4E00008 */  ldc1  $f0, 8($a3)
/* 073D04 7F03F1D4 D4F00000 */  ldc1  $f16, ($a3)
/* 073D08 7F03F1D8 46202301 */  sub.d $f12, $f4, $f0
/* 073D0C 7F03F1DC 46305381 */  sub.d $f14, $f10, $f16
/* 073D10 7F03F1E0 8C430000 */  lw    $v1, ($v0)
.L7F03F1E4:
/* 073D14 7F03F1E4 0003C900 */  sll   $t9, $v1, 4
/* 073D18 7F03F1E8 00996021 */  addu  $t4, $a0, $t9
/* 073D1C 7F03F1EC D5820000 */  ldc1  $f2, ($t4)
/* 073D20 7F03F1F0 D5840008 */  ldc1  $f4, 8($t4)
/* 073D24 7F03F1F4 46301181 */  sub.d $f6, $f2, $f16
/* 073D28 7F03F1F8 46202281 */  sub.d $f10, $f4, $f0
/* 073D2C 7F03F1FC 462C3202 */  mul.d $f8, $f6, $f12
/* 073D30 7F03F200 00000000 */  nop
/* 073D34 7F03F204 462E5182 */  mul.d $f6, $f10, $f14
/* 073D38 7F03F208 4626403C */  c.lt.d $f8, $f6
/* 073D3C 7F03F20C 00000000 */  nop
/* 073D40 7F03F210 4500000A */  bc1f  .L7F03F23C
/* 073D44 7F03F214 00000000 */   nop
/* 073D48 7F03F218 46201120 */  cvt.s.d $f4, $f2
/* 073D4C 7F03F21C 24A50001 */  addiu $a1, $a1, 1
/* 073D50 7F03F220 256B0008 */  addiu $t3, $t3, 8
/* 073D54 7F03F224 E564FFF8 */  swc1  $f4, -8($t3)
/* 073D58 7F03F228 D58A0008 */  ldc1  $f10, 8($t4)
/* 073D5C 7F03F22C 46205220 */  cvt.s.d $f8, $f10
/* 073D60 7F03F230 E568FFFC */  swc1  $f8, -4($t3)
/* 073D64 7F03F234 10000005 */  b     .L7F03F24C
/* 073D68 7F03F238 D4F00000 */   ldc1  $f16, ($a3)
.L7F03F23C:
/* 073D6C 7F03F23C 24420004 */  addiu $v0, $v0, 4
/* 073D70 7F03F240 004D082B */  sltu  $at, $v0, $t5
/* 073D74 7F03F244 5420FFE7 */  bnezl $at, .L7F03F1E4
/* 073D78 7F03F248 8C430000 */   lw    $v1, ($v0)
.L7F03F24C:
/* 073D7C 7F03F24C 462081A0 */  cvt.s.d $f6, $f16
/* 073D80 7F03F250 24A50001 */  addiu $a1, $a1, 1
/* 073D84 7F03F254 256B0008 */  addiu $t3, $t3, 8
/* 073D88 7F03F258 27A20130 */  addiu $v0, $sp, 0x130
/* 073D8C 7F03F25C E566FFF8 */  swc1  $f6, -8($t3)
/* 073D90 7F03F260 D4E40008 */  ldc1  $f4, 8($a3)
/* 073D94 7F03F264 27AC0140 */  addiu $t4, $sp, 0x140
/* 073D98 7F03F268 462022A0 */  cvt.s.d $f10, $f4
/* 073D9C 7F03F26C E56AFFFC */  swc1  $f10, -4($t3)
/* 073DA0 7F03F270 D4E60000 */  ldc1  $f6, ($a3)
/* 073DA4 7F03F274 D4E80008 */  ldc1  $f8, 8($a3)
/* 073DA8 7F03F278 D50E0000 */  ldc1  $f14, ($t0)
/* 073DAC 7F03F27C D50C0008 */  ldc1  $f12, 8($t0)
/* 073DB0 7F03F280 462E3481 */  sub.d $f18, $f6, $f14
/* 073DB4 7F03F284 462C4081 */  sub.d $f2, $f8, $f12
/* 073DB8 7F03F288 8C430000 */  lw    $v1, ($v0)
.L7F03F28C:
/* 073DBC 7F03F28C 00037100 */  sll   $t6, $v1, 4
/* 073DC0 7F03F290 008E3821 */  addu  $a3, $a0, $t6
/* 073DC4 7F03F294 D4E00000 */  ldc1  $f0, ($a3)
/* 073DC8 7F03F298 D4E80008 */  ldc1  $f8, 8($a3)
/* 073DCC 7F03F29C 462E0101 */  sub.d $f4, $f0, $f14
/* 073DD0 7F03F2A0 462C4181 */  sub.d $f6, $f8, $f12
/* 073DD4 7F03F2A4 46222282 */  mul.d $f10, $f4, $f2
/* 073DD8 7F03F2A8 00000000 */  nop
/* 073DDC 7F03F2AC 46323102 */  mul.d $f4, $f6, $f18
/* 073DE0 7F03F2B0 4624503C */  c.lt.d $f10, $f4
/* 073DE4 7F03F2B4 00000000 */  nop
/* 073DE8 7F03F2B8 4500000A */  bc1f  .L7F03F2E4
/* 073DEC 7F03F2BC 00000000 */   nop
/* 073DF0 7F03F2C0 46200220 */  cvt.s.d $f8, $f0
/* 073DF4 7F03F2C4 24A50001 */  addiu $a1, $a1, 1
/* 073DF8 7F03F2C8 256B0008 */  addiu $t3, $t3, 8
/* 073DFC 7F03F2CC E568FFF8 */  swc1  $f8, -8($t3)
/* 073E00 7F03F2D0 D4E60008 */  ldc1  $f6, 8($a3)
/* 073E04 7F03F2D4 462032A0 */  cvt.s.d $f10, $f6
/* 073E08 7F03F2D8 E56AFFFC */  swc1  $f10, -4($t3)
/* 073E0C 7F03F2DC 10000005 */  b     .L7F03F2F4
/* 073E10 7F03F2E0 D50E0000 */   ldc1  $f14, ($t0)
.L7F03F2E4:
/* 073E14 7F03F2E4 24420004 */  addiu $v0, $v0, 4
/* 073E18 7F03F2E8 004C082B */  sltu  $at, $v0, $t4
/* 073E1C 7F03F2EC 5420FFE7 */  bnezl $at, .L7F03F28C
/* 073E20 7F03F2F0 8C430000 */   lw    $v1, ($v0)
.L7F03F2F4:
/* 073E24 7F03F2F4 46207120 */  cvt.s.d $f4, $f14
/* 073E28 7F03F2F8 24A50001 */  addiu $a1, $a1, 1
/* 073E2C 7F03F2FC 256B0008 */  addiu $t3, $t3, 8
/* 073E30 7F03F300 27A20130 */  addiu $v0, $sp, 0x130
/* 073E34 7F03F304 E564FFF8 */  swc1  $f4, -8($t3)
/* 073E38 7F03F308 D5080008 */  ldc1  $f8, 8($t0)
/* 073E3C 7F03F30C 462041A0 */  cvt.s.d $f6, $f8
/* 073E40 7F03F310 E566FFFC */  swc1  $f6, -4($t3)
/* 073E44 7F03F314 D5040000 */  ldc1  $f4, ($t0)
/* 073E48 7F03F318 D50A0008 */  ldc1  $f10, 8($t0)
/* 073E4C 7F03F31C D5220008 */  ldc1  $f2, 8($t1)
/* 073E50 7F03F320 D5200000 */  ldc1  $f0, ($t1)
/* 073E54 7F03F324 27A80140 */  addiu $t0, $sp, 0x140
/* 073E58 7F03F328 46225401 */  sub.d $f16, $f10, $f2
/* 073E5C 7F03F32C 46202481 */  sub.d $f18, $f4, $f0
/* 073E60 7F03F330 8C430000 */  lw    $v1, ($v0)
.L7F03F334:
/* 073E64 7F03F334 00037900 */  sll   $t7, $v1, 4
/* 073E68 7F03F338 008F3821 */  addu  $a3, $a0, $t7
/* 073E6C 7F03F33C D4EC0000 */  ldc1  $f12, ($a3)
/* 073E70 7F03F340 D4EA0008 */  ldc1  $f10, 8($a3)
/* 073E74 7F03F344 46206201 */  sub.d $f8, $f12, $f0
/* 073E78 7F03F348 46225101 */  sub.d $f4, $f10, $f2
/* 073E7C 7F03F34C 46304182 */  mul.d $f6, $f8, $f16
/* 073E80 7F03F350 00000000 */  nop
/* 073E84 7F03F354 46322202 */  mul.d $f8, $f4, $f18
/* 073E88 7F03F358 4628303C */  c.lt.d $f6, $f8
/* 073E8C 7F03F35C 00000000 */  nop
/* 073E90 7F03F360 45000009 */  bc1f  .L7F03F388
/* 073E94 7F03F364 00000000 */   nop
/* 073E98 7F03F368 462062A0 */  cvt.s.d $f10, $f12
/* 073E9C 7F03F36C 24A50001 */  addiu $a1, $a1, 1
/* 073EA0 7F03F370 00001825 */  move  $v1, $zero
/* 073EA4 7F03F374 E56A0000 */  swc1  $f10, ($t3)
/* 073EA8 7F03F378 D4E40008 */  ldc1  $f4, 8($a3)
/* 073EAC 7F03F37C 462021A0 */  cvt.s.d $f6, $f4
/* 073EB0 7F03F380 10000006 */  b     .L7F03F39C
/* 073EB4 7F03F384 E5660004 */   swc1  $f6, 4($t3)
.L7F03F388:
/* 073EB8 7F03F388 24420004 */  addiu $v0, $v0, 4
/* 073EBC 7F03F38C 0048082B */  sltu  $at, $v0, $t0
/* 073EC0 7F03F390 5420FFE8 */  bnezl $at, .L7F03F334
/* 073EC4 7F03F394 8C430000 */   lw    $v1, ($v0)
/* 073EC8 7F03F398 00001825 */  move  $v1, $zero
.L7F03F39C:
/* 073ECC 7F03F39C 8FB80200 */  lw    $t8, 0x200($sp)
/* 073ED0 7F03F3A0 18A00065 */  blez  $a1, .L7F03F538
/* 073ED4 7F03F3A4 AF050000 */   sw    $a1, ($t8)
/* 073ED8 7F03F3A8 30A70003 */  andi  $a3, $a1, 3
/* 073EDC 7F03F3AC 10E0001A */  beqz  $a3, .L7F03F418
/* 073EE0 7F03F3B0 00E02025 */   move  $a0, $a3
/* 073EE4 7F03F3B4 0003C8C0 */  sll   $t9, $v1, 3
/* 073EE8 7F03F3B8 01591021 */  addu  $v0, $t2, $t9
/* 073EEC 7F03F3BC 24630001 */  addiu $v1, $v1, 1
/* 073EF0 7F03F3C0 1083000C */  beq   $a0, $v1, .L7F03F3F4
/* 073EF4 7F03F3C4 C4520000 */   lwc1  $f18, ($v0)
.L7F03F3C8:
/* 073EF8 7F03F3C8 C4D00030 */  lwc1  $f16, 0x30($a2)
/* 073EFC 7F03F3CC C44E0004 */  lwc1  $f14, 4($v0)
/* 073F00 7F03F3D0 24630001 */  addiu $v1, $v1, 1
/* 073F04 7F03F3D4 46109400 */  add.s $f16, $f18, $f16
/* 073F08 7F03F3D8 C4520008 */  lwc1  $f18, 8($v0)
/* 073F0C 7F03F3DC 24420008 */  addiu $v0, $v0, 8
/* 073F10 7F03F3E0 E450FFF8 */  swc1  $f16, -8($v0)
/* 073F14 7F03F3E4 C4D00038 */  lwc1  $f16, 0x38($a2)
/* 073F18 7F03F3E8 46107400 */  add.s $f16, $f14, $f16
/* 073F1C 7F03F3EC 1483FFF6 */  bne   $a0, $v1, .L7F03F3C8
/* 073F20 7F03F3F0 E450FFFC */   swc1  $f16, -4($v0)
.L7F03F3F4:
/* 073F24 7F03F3F4 C4D00030 */  lwc1  $f16, 0x30($a2)
/* 073F28 7F03F3F8 C44E0004 */  lwc1  $f14, 4($v0)
/* 073F2C 7F03F3FC 24420008 */  addiu $v0, $v0, 8
/* 073F30 7F03F400 46109400 */  add.s $f16, $f18, $f16
/* 073F34 7F03F404 E450FFF8 */  swc1  $f16, -8($v0)
/* 073F38 7F03F408 C4D00038 */  lwc1  $f16, 0x38($a2)
/* 073F3C 7F03F40C 46107400 */  add.s $f16, $f14, $f16
/* 073F40 7F03F410 E450FFFC */  swc1  $f16, -4($v0)
/* 073F44 7F03F414 10650048 */  beq   $v1, $a1, .L7F03F538
.L7F03F418:
/* 073F48 7F03F418 000370C0 */   sll   $t6, $v1, 3
/* 073F4C 7F03F41C 000578C0 */  sll   $t7, $a1, 3
/* 073F50 7F03F420 01EA2021 */  addu  $a0, $t7, $t2
/* 073F54 7F03F424 014E1021 */  addu  $v0, $t2, $t6
/* 073F58 7F03F428 24420020 */  addiu $v0, $v0, 0x20
/* 073F5C 7F03F42C 10440023 */  beq   $v0, $a0, .L7F03F4BC
/* 073F60 7F03F430 C452FFE0 */   lwc1  $f18, -0x20($v0)
.L7F03F434:
/* 073F64 7F03F434 C4D00030 */  lwc1  $f16, 0x30($a2)
/* 073F68 7F03F438 C44EFFE4 */  lwc1  $f14, -0x1c($v0)
/* 073F6C 7F03F43C C44CFFE8 */  lwc1  $f12, -0x18($v0)
/* 073F70 7F03F440 46109400 */  add.s $f16, $f18, $f16
/* 073F74 7F03F444 C44AFFEC */  lwc1  $f10, -0x14($v0)
/* 073F78 7F03F448 C448FFF0 */  lwc1  $f8, -0x10($v0)
/* 073F7C 7F03F44C C446FFF4 */  lwc1  $f6, -0xc($v0)
/* 073F80 7F03F450 E450FFE0 */  swc1  $f16, -0x20($v0)
/* 073F84 7F03F454 C4D00038 */  lwc1  $f16, 0x38($a2)
/* 073F88 7F03F458 C444FFF8 */  lwc1  $f4, -8($v0)
/* 073F8C 7F03F45C C442FFFC */  lwc1  $f2, -4($v0)
/* 073F90 7F03F460 46107400 */  add.s $f16, $f14, $f16
/* 073F94 7F03F464 C4520000 */  lwc1  $f18, ($v0)
/* 073F98 7F03F468 24420020 */  addiu $v0, $v0, 0x20
/* 073F9C 7F03F46C E450FFC4 */  swc1  $f16, -0x3c($v0)
/* 073FA0 7F03F470 C4D00030 */  lwc1  $f16, 0x30($a2)
/* 073FA4 7F03F474 46106400 */  add.s $f16, $f12, $f16
/* 073FA8 7F03F478 E450FFC8 */  swc1  $f16, -0x38($v0)
/* 073FAC 7F03F47C C4D00038 */  lwc1  $f16, 0x38($a2)
/* 073FB0 7F03F480 46105400 */  add.s $f16, $f10, $f16
/* 073FB4 7F03F484 E450FFCC */  swc1  $f16, -0x34($v0)
/* 073FB8 7F03F488 C4D00030 */  lwc1  $f16, 0x30($a2)
/* 073FBC 7F03F48C 46104400 */  add.s $f16, $f8, $f16
/* 073FC0 7F03F490 E450FFD0 */  swc1  $f16, -0x30($v0)
/* 073FC4 7F03F494 C4D00038 */  lwc1  $f16, 0x38($a2)
/* 073FC8 7F03F498 46103400 */  add.s $f16, $f6, $f16
/* 073FCC 7F03F49C E450FFD4 */  swc1  $f16, -0x2c($v0)
/* 073FD0 7F03F4A0 C4D00030 */  lwc1  $f16, 0x30($a2)
/* 073FD4 7F03F4A4 46102400 */  add.s $f16, $f4, $f16
/* 073FD8 7F03F4A8 E450FFD8 */  swc1  $f16, -0x28($v0)
/* 073FDC 7F03F4AC C4D00038 */  lwc1  $f16, 0x38($a2)
/* 073FE0 7F03F4B0 46101400 */  add.s $f16, $f2, $f16
/* 073FE4 7F03F4B4 1444FFDF */  bne   $v0, $a0, .L7F03F434
/* 073FE8 7F03F4B8 E450FFDC */   swc1  $f16, -0x24($v0)
.L7F03F4BC:
/* 073FEC 7F03F4BC C4D00030 */  lwc1  $f16, 0x30($a2)
/* 073FF0 7F03F4C0 C44EFFE4 */  lwc1  $f14, -0x1c($v0)
/* 073FF4 7F03F4C4 C44CFFE8 */  lwc1  $f12, -0x18($v0)
/* 073FF8 7F03F4C8 46109400 */  add.s $f16, $f18, $f16
/* 073FFC 7F03F4CC C44AFFEC */  lwc1  $f10, -0x14($v0)
/* 074000 7F03F4D0 C448FFF0 */  lwc1  $f8, -0x10($v0)
/* 074004 7F03F4D4 C446FFF4 */  lwc1  $f6, -0xc($v0)
/* 074008 7F03F4D8 E450FFE0 */  swc1  $f16, -0x20($v0)
/* 07400C 7F03F4DC C4D00038 */  lwc1  $f16, 0x38($a2)
/* 074010 7F03F4E0 C444FFF8 */  lwc1  $f4, -8($v0)
/* 074014 7F03F4E4 C442FFFC */  lwc1  $f2, -4($v0)
/* 074018 7F03F4E8 46107400 */  add.s $f16, $f14, $f16
/* 07401C 7F03F4EC E450FFE4 */  swc1  $f16, -0x1c($v0)
/* 074020 7F03F4F0 C4D00030 */  lwc1  $f16, 0x30($a2)
/* 074024 7F03F4F4 46106400 */  add.s $f16, $f12, $f16
/* 074028 7F03F4F8 E450FFE8 */  swc1  $f16, -0x18($v0)
/* 07402C 7F03F4FC C4D00038 */  lwc1  $f16, 0x38($a2)
/* 074030 7F03F500 46105400 */  add.s $f16, $f10, $f16
/* 074034 7F03F504 E450FFEC */  swc1  $f16, -0x14($v0)
/* 074038 7F03F508 C4D00030 */  lwc1  $f16, 0x30($a2)
/* 07403C 7F03F50C 46104400 */  add.s $f16, $f8, $f16
/* 074040 7F03F510 E450FFF0 */  swc1  $f16, -0x10($v0)
/* 074044 7F03F514 C4D00038 */  lwc1  $f16, 0x38($a2)
/* 074048 7F03F518 46103400 */  add.s $f16, $f6, $f16
/* 07404C 7F03F51C E450FFF4 */  swc1  $f16, -0xc($v0)
/* 074050 7F03F520 C4D00030 */  lwc1  $f16, 0x30($a2)
/* 074054 7F03F524 46102400 */  add.s $f16, $f4, $f16
/* 074058 7F03F528 E450FFF8 */  swc1  $f16, -8($v0)
/* 07405C 7F03F52C C4D00038 */  lwc1  $f16, 0x38($a2)
/* 074060 7F03F530 46101400 */  add.s $f16, $f2, $f16
/* 074064 7F03F534 E450FFFC */  swc1  $f16, -4($v0)
.L7F03F538:
/* 074068 7F03F538 03E00008 */  jr    $ra
/* 07406C 7F03F53C 27BD01E0 */   addiu $sp, $sp, 0x1e0
)
#endif



void sub_GAME_7F03F540(struct ModelRoData_BoundingBoxRecord *bbox, Mtxf* arg1, struct rect4f* arg2, struct collision_data* arg3)
{
    sub_GAME_7F03ECC0(bbox->Bounds.xmin, bbox->Bounds.xmax, bbox->Bounds.ymin, bbox->Bounds.ymax, bbox->Bounds.zmin, bbox->Bounds.zmax, arg1, arg2, arg3);
}


#ifdef NONMATCHING
s32 sub_GAME_7F03F598(coord3d* pos, f32 arg1, BoundPadRecord *boundpads) {
      dword local_70;
  ushort *local_20;
  dword local_1c;
  dword local_18;
  dword local_14;
  dword local_8;

  local_20 = **(param_1 + 8);
  do {
    while( true ) {
      if (local_20 == NULL) {
        return NULL;
      }
      if (((*local_20 & 0xff) == 10) && (**(local_20 + 2) == param_2)) {
        return local_20;
      }
      if (*(local_20 + 10) == 0) break;
      local_20 = *(local_20 + 10);
    }
    for (; local_20 != NULL; local_20 = *(local_20 + 4)) {
      if (*(local_20 + 6) != 0) {
        local_20 = *(local_20 + 6);
        break;
      }
    }
  } while( true );


}
#else
s32 sub_GAME_7F03F598(coord3d* pos, f32 arg1, BoundPadRecord *boundpads);
GLOBAL_ASM(
.text
glabel sub_GAME_7F03F598
/* 0740C8 7F03F598 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 0740CC 7F03F59C F7B40008 */  sdc1  $f20, 8($sp)
/* 0740D0 7F03F5A0 C4C60000 */  lwc1  $f6, ($a2)
/* 0740D4 7F03F5A4 C4840000 */  lwc1  $f4, ($a0)
/* 0740D8 7F03F5A8 C4CA0004 */  lwc1  $f10, 4($a2)
/* 0740DC 7F03F5AC C4880004 */  lwc1  $f8, 4($a0)
/* 0740E0 7F03F5B0 46062001 */  sub.s $f0, $f4, $f6
/* 0740E4 7F03F5B4 C4C40008 */  lwc1  $f4, 8($a2)
/* 0740E8 7F03F5B8 C4920008 */  lwc1  $f18, 8($a0)
/* 0740EC 7F03F5BC 460A4081 */  sub.s $f2, $f8, $f10
/* 0740F0 7F03F5C0 C4C80020 */  lwc1  $f8, 0x20($a2)
/* 0740F4 7F03F5C4 C4C60010 */  lwc1  $f6, 0x10($a2)
/* 0740F8 7F03F5C8 46049301 */  sub.s $f12, $f18, $f4
/* 0740FC 7F03F5CC C4C40014 */  lwc1  $f4, 0x14($a2)
/* 074100 7F03F5D0 46083282 */  mul.s $f10, $f6, $f8
/* 074104 7F03F5D4 C4D2001C */  lwc1  $f18, 0x1c($a2)
/* 074108 7F03F5D8 4485A000 */  mtc1  $a1, $f20
/* 07410C 7F03F5DC 46049182 */  mul.s $f6, $f18, $f4
/* 074110 7F03F5E0 46065201 */  sub.s $f8, $f10, $f6
/* 074114 7F03F5E4 E7A80010 */  swc1  $f8, 0x10($sp)
/* 074118 7F03F5E8 C4C40018 */  lwc1  $f4, 0x18($a2)
/* 07411C 7F03F5EC C4D20014 */  lwc1  $f18, 0x14($a2)
/* 074120 7F03F5F0 C4C60020 */  lwc1  $f6, 0x20($a2)
/* 074124 7F03F5F4 C4C8000C */  lwc1  $f8, 0xc($a2)
/* 074128 7F03F5F8 46049282 */  mul.s $f10, $f18, $f4
/* 07412C 7F03F5FC 00000000 */  nop
/* 074130 7F03F600 46083482 */  mul.s $f18, $f6, $f8
/* 074134 7F03F604 46125101 */  sub.s $f4, $f10, $f18
/* 074138 7F03F608 E7A40014 */  swc1  $f4, 0x14($sp)
/* 07413C 7F03F60C C4C8001C */  lwc1  $f8, 0x1c($a2)
/* 074140 7F03F610 C4C6000C */  lwc1  $f6, 0xc($a2)
/* 074144 7F03F614 C4D20018 */  lwc1  $f18, 0x18($a2)
/* 074148 7F03F618 C4C40010 */  lwc1  $f4, 0x10($a2)
/* 07414C 7F03F61C 46083282 */  mul.s $f10, $f6, $f8
/* 074150 7F03F620 00000000 */  nop
/* 074154 7F03F624 46049182 */  mul.s $f6, $f18, $f4
/* 074158 7F03F628 46065201 */  sub.s $f8, $f10, $f6
/* 07415C 7F03F62C E7A80018 */  swc1  $f8, 0x18($sp)
/* 074160 7F03F630 C4D20018 */  lwc1  $f18, 0x18($a2)
/* 074164 7F03F634 C4CA001C */  lwc1  $f10, 0x1c($a2)
/* 074168 7F03F638 46120102 */  mul.s $f4, $f0, $f18
/* 07416C 7F03F63C C4D20020 */  lwc1  $f18, 0x20($a2)
/* 074170 7F03F640 460A1182 */  mul.s $f6, $f2, $f10
/* 074174 7F03F644 46062200 */  add.s $f8, $f4, $f6
/* 074178 7F03F648 460C9282 */  mul.s $f10, $f18, $f12
/* 07417C 7F03F64C C4C40040 */  lwc1  $f4, 0x40($a2)
/* 074180 7F03F650 46142180 */  add.s $f6, $f4, $f20
/* 074184 7F03F654 46085380 */  add.s $f14, $f10, $f8
/* 074188 7F03F658 460E303C */  c.lt.s $f6, $f14
/* 07418C 7F03F65C 00000000 */  nop
/* 074190 7F03F660 45010007 */  bc1t  .L7F03F680
/* 074194 7F03F664 00000000 */   nop
/* 074198 7F03F668 C4D2003C */  lwc1  $f18, 0x3c($a2)
/* 07419C 7F03F66C 46149281 */  sub.s $f10, $f18, $f20
/* 0741A0 7F03F670 460A703C */  c.lt.s $f14, $f10
/* 0741A4 7F03F674 00000000 */  nop
/* 0741A8 7F03F678 45020004 */  bc1fl .L7F03F68C
/* 0741AC 7F03F67C C4C8000C */   lwc1  $f8, 0xc($a2)
.L7F03F680:
/* 0741B0 7F03F680 1000002E */  b     .L7F03F73C
/* 0741B4 7F03F684 00001025 */   move  $v0, $zero
/* 0741B8 7F03F688 C4C8000C */  lwc1  $f8, 0xc($a2)
.L7F03F68C:
/* 0741BC 7F03F68C C4C60010 */  lwc1  $f6, 0x10($a2)
/* 0741C0 7F03F690 46080102 */  mul.s $f4, $f0, $f8
/* 0741C4 7F03F694 C4C80014 */  lwc1  $f8, 0x14($a2)
/* 0741C8 7F03F698 46061482 */  mul.s $f18, $f2, $f6
/* 0741CC 7F03F69C 46122280 */  add.s $f10, $f4, $f18
/* 0741D0 7F03F6A0 460C4182 */  mul.s $f6, $f8, $f12
/* 0741D4 7F03F6A4 C4C40038 */  lwc1  $f4, 0x38($a2)
/* 0741D8 7F03F6A8 46142480 */  add.s $f18, $f4, $f20
/* 0741DC 7F03F6AC 460A3380 */  add.s $f14, $f6, $f10
/* 0741E0 7F03F6B0 460E903C */  c.lt.s $f18, $f14
/* 0741E4 7F03F6B4 00000000 */  nop
/* 0741E8 7F03F6B8 45010009 */  bc1t  .L7F03F6E0
/* 0741EC 7F03F6BC 00000000 */   nop
/* 0741F0 7F03F6C0 C4C80034 */  lwc1  $f8, 0x34($a2)
/* 0741F4 7F03F6C4 C7AA0010 */  lwc1  $f10, 0x10($sp)
/* 0741F8 7F03F6C8 C7B20014 */  lwc1  $f18, 0x14($sp)
/* 0741FC 7F03F6CC 46144181 */  sub.s $f6, $f8, $f20
/* 074200 7F03F6D0 4606703C */  c.lt.s $f14, $f6
/* 074204 7F03F6D4 00000000 */  nop
/* 074208 7F03F6D8 45000003 */  bc1f  .L7F03F6E8
/* 07420C 7F03F6DC 00000000 */   nop
.L7F03F6E0:
/* 074210 7F03F6E0 10000016 */  b     .L7F03F73C
/* 074214 7F03F6E4 00001025 */   move  $v0, $zero
.L7F03F6E8:
/* 074218 7F03F6E8 460A0102 */  mul.s $f4, $f0, $f10
/* 07421C 7F03F6EC C7AA0018 */  lwc1  $f10, 0x18($sp)
/* 074220 7F03F6F0 46121202 */  mul.s $f8, $f2, $f18
/* 074224 7F03F6F4 46082180 */  add.s $f6, $f4, $f8
/* 074228 7F03F6F8 460C5482 */  mul.s $f18, $f10, $f12
/* 07422C 7F03F6FC C4C40030 */  lwc1  $f4, 0x30($a2)
/* 074230 7F03F700 46142200 */  add.s $f8, $f4, $f20
/* 074234 7F03F704 46069400 */  add.s $f16, $f18, $f6
/* 074238 7F03F708 4610403C */  c.lt.s $f8, $f16
/* 07423C 7F03F70C 00000000 */  nop
/* 074240 7F03F710 45010008 */  bc1t  .L7F03F734
/* 074244 7F03F714 00000000 */   nop
/* 074248 7F03F718 C4CA002C */  lwc1  $f10, 0x2c($a2)
/* 07424C 7F03F71C 24020001 */  li    $v0, 1
/* 074250 7F03F720 46145481 */  sub.s $f18, $f10, $f20
/* 074254 7F03F724 4612803C */  c.lt.s $f16, $f18
/* 074258 7F03F728 00000000 */  nop
/* 07425C 7F03F72C 45000003 */  bc1f  .L7F03F73C
/* 074260 7F03F730 00000000 */   nop
.L7F03F734:
/* 074264 7F03F734 10000001 */  b     .L7F03F73C
/* 074268 7F03F738 00001025 */   move  $v0, $zero
.L7F03F73C:
/* 07426C 7F03F73C D7B40008 */  ldc1  $f20, 8($sp)
/* 074270 7F03F740 03E00008 */  jr    $ra
/* 074274 7F03F744 27BD0028 */   addiu $sp, $sp, 0x28
)
#endif


void sub_GAME_7F03F748(Model* model, f32* max, f32* min, s32 axis)
{
    ModelNode *node = model->obj->RootNode;
    bool first = TRUE;

    while (node)
    {
        u32 type = node->Opcode & 0xFF;

        if (type == MODELNODE_OPCODE_BBOX)
        {
            struct ModelRoData_BoundingBoxRecord *bbox = &node->Data->BoundingBox;
            Mtxf *mtx = modelFindNodeMtx(model, node, 0);
            f32 dist1;
            f32 dist2;

            if (axis == 0)
            {
                dist1 = chrpropSumMatrixNegX(bbox, mtx) + mtx->m[3][0];
                dist2 = chrpropSumMatrixPosX(bbox, mtx) + mtx->m[3][0];
            }
            else if (axis == 1)
            {
                dist1 = chrpropSumMatrixNegY(bbox, mtx) + mtx->m[3][1];
                dist2 = chrpropSumMatrixPosY(bbox, mtx) + mtx->m[3][1];
            }
            else
            {
                dist1 = chrpropSumMatrixNegZ(bbox, mtx) + mtx->m[3][2];
                dist2 = chrpropSumMatrixPosZ(bbox, mtx) + mtx->m[3][2];
            }

            if (first || dist1 > *max)
            {
                *max = dist1;
            }

            if (first || dist2 < *min)
            {
                *min = dist2;
            }

            first = FALSE;
        }
        else
        {
            // empty
        }

        if (node->Child)
        {
            node = node->Child;
        }
        else
        {
            while (node)
            {
                if (node->Next)
                {
                    node = node->Next;
                    break;
                }

                node = node->Parent;
            }
        }
    }
}


void sub_GAME_7F03F90C(Model *model, f32 *arg1, f32 *arg2, f32 *arg3, f32 *arg4)
{
    sub_GAME_7F03F748(model, arg1, arg2, 0);
    sub_GAME_7F03F748(model, arg3, arg4, 1);
}


/**
 * NTSC address 0x7F03F948.
*/
void sub_GAME_7F03F948(struct coord3d *arg0, struct coord2d *arg1, struct coord2d *arg2, struct coord2d *arg3, struct coord2d *arg4)
{
    struct coord3d sp24;
    struct coord2d tout;

    sp24.f[0] = arg1->f[0];
    sp24.f[1] = arg0->f[1];
    sp24.f[2] = arg0->f[2];
    transform3Dto2DCoords(&sp24, &tout);
    arg3->f[0] = tout.f[0];

    sp24.f[0] = arg1->f[1];
    sp24.f[1] = arg0->f[1];
    sp24.f[2] = arg0->f[2];
    transform3Dto2DCoords(&sp24, &tout);
    arg4->f[0] = tout.f[0];

    sp24.f[0] = arg0->f[0];
    sp24.f[1] = arg2->f[1];
    sp24.f[2] = arg0->f[2];
    transform3Dto2DCoords(&sp24, &tout);
    arg3->f[1] = tout.f[1];

    sp24.f[0] = arg0->f[0];
    sp24.f[1] = arg2->f[0];
    sp24.f[2] = arg0->f[2];
    transform3Dto2DCoords(&sp24, &tout);
    arg4->f[1] = tout.f[1];
}




/*
* Address: 0x7F03FA44
*/
ObjectRecord *scan_position_data_table_for_normal_object_at_preset(s32 PadId) {
    PropRecord *prop;
    s16 tempPadId = PadId;

    prop = get_ptr_obj_pos_list_current_entry();
    while (prop != NULL)
    {
        if (prop->type == PROP_TYPE_OBJ)
        {
            if (tempPadId == prop->obj->pad)
            {
                return prop->obj;
            }
        }

        prop = prop->prev;
    }

    return NULL;
}




ObjectRecord * sub_GAME_7F03FAB0(struct coord3d *pos, s32 RoomID)
{
    s32 unused;
    rect4f * polygon;
    s32 edges;
    PropRecord * prop;

    prop = get_ptr_obj_pos_list_current_entry();
    while (prop != NULL)
    {
        if ((prop->type == PROP_TYPE_OBJ) && (RoomID == prop->stan->room))
        {
            chraiGetCollisionBoundsWithoutY(prop, &polygon, &edges);
            if (chrpropTestPointInPolygon(pos, polygon, edges) != 0)
            {
                return (ObjectRecord *) prop->chr;
            }
        }
        prop = prop->prev;
    }

    return NULL;
}

