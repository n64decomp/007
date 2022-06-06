#include <ultra64.h>
#include <PR/gbi.h>
#include <bondgame.h>
#include <bondconstants.h>
#include <bondtypes.h>
#include <random.h>
#include <snd.h>
#include <math.h>
#include "bg.h"
#include "cheat_buttons.h"
#include "chr.h"
#include "chrai.h"
#include "chrlv.h"
#include "chrobjdata.h"
#include "chrobjhandler.h"
#include "gun.h"
#include "initanitable.h"
#include "lvl.h"
#include "lvl_text.h"
#include "objecthandler.h"
#include "player.h"
#include "stan.h"

// forward declarations

void chrAimGlobalTimerTickRelated( ChrRecord *arg0);
void chrPositionRelated7F020E40( ChrRecord *chr, s32 arg1);

// end forward declarations

// data
f32 animation_rate = 0;
s32 D_8002C904 = 0;

/**
 * Address 0x8002C908.
 */
s32 g_AnimationTablePointerCountRelated = 0;
s32 D_8002C90C = 0;
s32 D_8002C910 = 0;

//D:8002C914
struct animation_something D_8002C914[] = {
    {0         , 0, 0,    0, 0, 0,    0,       NULL, 0,       NULL, 0},
    {1         , 1, 0, 17.0, 3, 0, 34.0, D_8002CE54, 0, D_8002DF10, 0},
    {2         , 1, 0, 17.0, 3, 0, 39.0, D_8002CEE0, 0, D_8002DF64, 0},
    {3         , 1, 0, 21.0, 3, 0, 43.0, D_8002CF6C, 0, D_8002DFB8, 0},
    {4         , 1, 0, 17.0, 3, 0, 34.0, D_8002D014, 0, D_8002E028, 0},
    {5         , 1, 0, 17.0, 3, 0, 39.0, D_8002D0A0, 0, D_8002E07C, 0},
    {6         , 1, 0, 21.0, 3, 0, 43.0, D_8002D12C, 0, D_8002E0D0, 0},
    {7         , 1, 0, 21.0, 3, 0, 52.0, D_8002D1D4, 0, D_8002E140, 0},
    {8         , 1, 0, 21.0, 3, 0, 43.0, D_8002D3B0, 0, D_8002E23C, 0},
    {9         , 1, 0, 17.0, 3, 0, 34.0, D_8002D6DC, 0, D_8002E300, 0}, // previously D_8002CAA0 = &D_8002C914 + (0x2c * 9)
    {0xA       , 1, 0, 17.0, 3, 0, 43.0, D_8002D768, 0, D_8002E354, 0}, // previously D_8002CACC
    {0xB       , 1, 0, 21.0, 3, 0, 52.0, D_8002D7F4, 0, D_8002E3A8, 0},
    {0xC       , 1, 0, 17.0, 3, 0, 34.0, D_8002D880, 0, D_8002E418, 0}, // previously D_8002CB24
    {0xD       , 1, 0, 17.0, 3, 0, 43.0, D_8002D90C, 0, D_8002E46C, 0}, // previously D_8002CB50
    {0xE       , 1, 0, 21.0, 3, 0, 52.0, D_8002D998, 0, D_8002E4C0, 0},
    {0xF       , 1, 0, 26.0, 3, 0, 60.0, D_8002DA24, 0, D_8002E530, 0},
    {0x64      , 1, 0, 26.0, 0, 0,  0.0, D_8002DCE0, 0, D_8002E5BC, 0},
    {0x6E      , 1, 0, 21.0, 0, 0,  0.0,       NULL, 0,       NULL, 0},
    {0xFFFFFFFF, 0, 0,  0.0, 0, 0,  0.0,       NULL, 0,       NULL, 0},
};




s32 D_8002CC58 = 0;
s32 show_patrols_flag = FALSE;
s32 player1_guardID = 5000;
 ChrRecord *ptr_guard_data = 0;
s32 num_guards = 0;
struct unk_joint_list D_8002CC6C = {NULL, 1, 3, NULL, NULL, 0, 0, 0, 0, 0, 0, 0, 0, 0, {0, 0, 0, 0}, 0};
s32 D_8002CCAC = 0;
s32 D_8002CCB0 = 0;
s32 D_8002CCB4 = 0;

 rgba_u8 D_8002CCB8 = { 0x5a, 0, 0, 0};

/**
 * Address 0x8002CCBC.
*/

struct unk_joint_list D_8002CCBC = {NULL, 1, 3, NULL, NULL, 0, 0, 0, 0, 0, 0, 0, 0, 0, {0, 0, 0, 0}, 0};
//s32 D_8002CCF8 = 0;
s32 D_8002CCFC = 0;
u32 num_bodies = 0;
u32 num_male_heads = 0;
u32 num_female_heads = 0;

s32 list_of_bodies[] = {
    BODY_Jungle_Commando,BODY_St_Petersburg_Guard,BODY_Russian_Soldier,BODY_Russian_Infantry,
    BODY_Janus_Special_Forces,BODY_Tuxedo,BODY_Boris,BODY_Ourumov,
    BODY_Trevelyan_Janus,BODY_Valentin_,BODY_Xenia,BODY_Baron_Samedi,
    BODY_Jaws,BODY_Mayday,BODY_Oddjob,BODY_Natalya_Skirt,
    BODY_Janus_Marine,BODY_Russian_Commandant,BODY_Siberian_Guard_1_Mishkin,BODY_Naval_Officer,
    BODY_Siberian_Special_Forces,BODY_Special_Operations_Uniform,BODY_Formal_Wear,BODY_Jungle_Fatigues,
    BODY_Unused_Female,BODY_Rosika,BODY_Scientist_2_Female,BODY_Civilian_1_Female,
    BODY_Unused_Male_1,BODY_Unused_Male_2,BODY_Civilian_4,BODY_Civilian_2,
    BODY_Civilian_3,BODY_Scientist_1_Male,BODY_Tuxedo,BODY_Tuxedo,
    BODY_Tuxedo,BODY_Helicopter_Pilot,BODY_Siberian_Guard_2,BODY_Arctic_Commando,
    BODY_Moonraker_Elite_1_Male,BODY_Moonraker_Elite_2_Female,-1,
};

s32 random_male_heads[] = {
    HEAD_Male_Jim,HEAD_Male_Chris,HEAD_Male_Lee,HEAD_Male_Graeme,HEAD_Male_Steve_H,
    HEAD_Male_Neil,HEAD_Male_Robin,HEAD_Male_Des,HEAD_Male_Grant,HEAD_Male_Dave_Dr_Doak,
    HEAD_Male_Karl,HEAD_Male_Alan,HEAD_Male_Pete,HEAD_Male_Martin,HEAD_Male_Mark,
    HEAD_Male_Duncan,HEAD_Male_Shaun,HEAD_Male_Dwayne,HEAD_Male_B,HEAD_Male_Steve_Ellis,
    HEAD_Male_Joel,HEAD_Male_Scott,HEAD_Male_Joe_Altered,HEAD_Male_Ken,HEAD_Male_Joe,
    -1
};

s32 random_female_heads[] = {
    HEAD_Female_Sally,HEAD_Female_Marion_Rosika,HEAD_Female_Mandy,HEAD_Female_Vivien, -1
};

u32 current_random_body = 0;
u32 current_random_male_head = 0;
u32 current_random_female_head = 0;

/*
* Enemy accuracy modifier.
* Set on level load.
* One of the values that can be set with the 007 slider.
*/
f32 g_AiAccuracyModifier = 1.0f;

/*
* Enemy damage modifier.
* Set on level load.
* One of the values that can be set with the 007 slider.
*/
f32 g_AiDamageModifier = 1.0f;

f32 g_AiHealthModifier = 1.0f;

/*
* Enemy reaction speed modifier.
* Set on level load.
* One of the values that can be set with the 007 slider.
*/
f32 g_AiReactionSpeed = 1.0f;

/**
 * Count of number of guards that have recently seen bond:
 *     (guard->lastseetarget60 > 0) && (g_GlobalTimer - guard->lastseetarget60 < 120)
 * Updated every tick.
 * Address 0x8002CE50.
*/
s32 g_SeenBondRecentlyGuardCount = 0;

struct struck_animation_table D_8002CE54[] = {
    {0x35C8, 0, -1.0, 0.5, 0, 27.0, -1.0},
    {0x36D8, 0, -1.0, 0.5, 0, 26.0, -1.0},
    {0x33AC, 1, -1.0, 0.5, 0, 25.0, -1.0},
    {0x34D4, 1, -1.0, 0.5, 0, 23.0, -1.0},
    {0, 0, 0.0, 0.5, 0, -1.0, -1.0}
};

struct struck_animation_table D_8002CEE0[] = {
    {0x35C8, 0, -1.0, 0.5, 0, 27.0, -1.0},
    {0x36D8, 0, -1.0, 0.5, 0, 26.0, -1.0},
    {0x33AC, 1, -1.0, 0.5, 0, 25.0, -1.0},
    {0x34D4, 1, -1.0, 0.5, 0, 23.0, -1.0},
    {0, 0, 0.0, 0.5, 0, -1.0, -1.0}
};

struct struck_animation_table D_8002CF6C[] = {
    {0x35C8, 0, -1.0, 0.5, 1, 27.0, -1.0},
    {0x36D8, 0, -1.0, 0.5, 1, 26.0, -1.0},
    {0x33AC, 1, -1.0, 0.5, 1, 25.0, -1.0},
    {0x34D4, 1, -1.0, 0.5, 1, 23.0, -1.0},
    {0x540C, 1, -1.0, 0.5, 0, -1.0, -1.0},
    {0, 0, 0.0, 0.5, 0, -1.0, -1.0}
};

struct struck_animation_table D_8002D014[] = {
    {0x33AC, 0, -1.0, 0.5, 0, 25.0, -1.0},
    {0x34D4, 0, -1.0, 0.5, 0, 23.0, -1.0},
    {0x35C8, 1, -1.0, 0.5, 0, 27.0, -1.0},
    {0x36D8, 1, -1.0, 0.5, 0, 26.0, -1.0},
    {0, 0, 0.0, 0.5, 0, -1.0, -1.0}
};

struct struck_animation_table D_8002D0A0[] = {
    {0x33AC, 0, -1.0, 0.5, 0, 25.0, -1.0},
    {0x34D4, 0, -1.0, 0.5, 0, 23.0, -1.0},
    {0x35C8, 1, -1.0, 0.5, 0, 27.0, -1.0},
    {0x36D8, 1, -1.0, 0.5, 0, 26.0, -1.0},
    {0, 0, 0.0, 0.5, 0, -1.0, -1.0}
};

struct struck_animation_table D_8002D12C[] = {
    {0x33AC, 0, -1.0, 0.5, 1, 25.0, -1.0},
    {0x34D4, 0, -1.0, 0.5, 1, 23.0, -1.0},
    {0x35C8, 1, -1.0, 0.5, 1, 27.0, -1.0},
    {0x36D8, 1, -1.0, 0.5, 1, 26.0, -1.0},
    {0x540C, 0, -1.0, 0.5, 0, -1.0, -1.0},
    {0, 0, 0.0, 0.5, 0, -1.0, -1.0}
};

struct struck_animation_table D_8002D1D4[] = {
    {0x30B8, 0, -1.0, 0.5, 0, 55.0, 39.0},
    {0x30B8, 1, -1.0, 0.5, 0, 55.0, 39.0},
    {0x31DC, 0, -1.0, 0.5, 0, 36.0, -1.0},
    {0x31DC, 1, -1.0, 0.5, 0, 36.0, -1.0},
    {0x32C8, 0, -1.0, 0.5, 1, 29.0, -1.0},
    {0x32C8, 1, -1.0, 0.5, 1, 29.0, -1.0},
    {0x384C, 0, -1.0, 0.5, 0, 97.0, 64.0},
    {0x384C, 1, -1.0, 0.5, 0, 97.0, 64.0},
    {0x3AF0, 0, -1.0, 0.5, 0, 31.0, -1.0},
    {0x3AF0, 1, -1.0, 0.5, 0, 31.0, -1.0},
    {0x3C10, 0, -1.0, 0.5, 0, 36.0, -1.0},
    {0x3C10, 1, -1.0, 0.5, 0, 36.0, -1.0},
    {0x3D04, 0, -1.0, 0.5, 0, 28.0, -1.0},
    {0x3D04, 1, -1.0, 0.5, 0, 28.0, -1.0},
    {0x282C, 0, -1.0, 0.5, 0, 79.0, 415.0},
    {0x282C, 1, -1.0, 0.5, 0, 79.0, 415.0},
    {0, 0, -1.0, 0.5, 0, -1.0, -1.0}
};

struct struck_animation_table D_8002D3B0[] = {
    {0x30B8, 0, -1.0, 0.5, 0, 55.0, 39.0},
    {0x30B8, 1, -1.0, 0.5, 0, 55.0, 39.0},
    {0x31DC, 0, -1.0, 0.5, 0, 36.0, -1.0},
    {0x31DC, 1, -1.0, 0.5, 0, 36.0, -1.0},
    {0x32C8, 0, -1.0, 0.5, 1, 29.0, -1.0},
    {0x32C8, 1, -1.0, 0.5, 1, 29.0, -1.0},
    {0x33AC, 0, -1.0, 0.5, 1, 25.0, -1.0},
    {0x33AC, 1, -1.0, 0.5, 1, 25.0, -1.0},
    {0x34D4, 0, -1.0, 0.5, 1, 23.0, -1.0},
    {0x34D4, 1, -1.0, 0.5, 1, 23.0, -1.0},
    {0x35C8, 0, -1.0, 0.5, 1, 27.0, -1.0},
    {0x35C8, 1, -1.0, 0.5, 1, 27.0, -1.0},
    {0x36D8, 0, -1.0, 0.5, 1, 26.0, -1.0},
    {0x36D8, 1, -1.0, 0.5, 1, 26.0, -1.0},
    {0x384C, 0, -1.0, 0.5, 0, 97.0, 64.0},
    {0x384C, 1, -1.0, 0.5, 0, 97.0, 64.0},
    {0x39C0, 0, -1.0, 0.5, 0, 94.0, 66.0},
    {0x39C0, 1, -1.0, 0.5, 0, 94.0, 66.0},
    {0x3AF0, 0, -1.0, 0.5, 0, 31.0, -1.0},
    {0x3AF0, 1, -1.0, 0.5, 0, 31.0, -1.0},
    {0x3C10, 0, -1.0, 0.5, 0, 36.0, -1.0},
    {0x3C10, 1, -1.0, 0.5, 0, 36.0, -1.0},
    {0x3D04, 0, -1.0, 0.5, 0, 28.0, -1.0},
    {0x3D04, 1, -1.0, 0.5, 0, 28.0, -1.0},
    {0x2E64, 0, -1.0, 0.5, 0, 87.0, 203.0},
    {0x2E64, 1, -1.0, 0.5, 0, 87.0, 203.0},
    {0x51C4, 0, -1.0, 0.5, 0, -1.0, -1.0},
    {0x51C4, 1, -1.0, 0.5, 0, -1.0, -1.0},
    {0, 0, -1.0, 0.5, 0, -1.0, -1.0}
};

struct struck_animation_table D_8002D6DC[] = {
    {0x35C8, 0, -1.0, 0.5, 0, 27.0, -1.0},
    {0x36D8, 0, -1.0, 0.5, 0, 26.0, -1.0},
    {0x33AC, 1, -1.0, 0.5, 0, 25.0, -1.0},
    {0x34D4, 1, -1.0, 0.5, 0, 23.0, -1.0},
    {0, 0, -1.0, 0.5, 0, -1.0, -1.0}
};

struct struck_animation_table D_8002D768[] = {
    {0x35C8, 0, -1.0, 0.5, 0, 27.0, -1.0},
    {0x36D8, 0, -1.0, 0.5, 0, 26.0, -1.0},
    {0x33AC, 1, -1.0, 0.5, 0, 25.0, -1.0},
    {0x34D4, 1, -1.0, 0.5, 0, 23.0, -1.0},
    {0, 0, -1.0, 0.5, 0, -1.0, -1.0}
};

struct struck_animation_table D_8002D7F4[] = {
    {0x35C8, 0, -1.0, 0.5, 1, 27.0, -1.0},
    {0x36D8, 0, -1.0, 0.5, 1, 26.0, -1.0},
    {0x33AC, 1, -1.0, 0.5, 1, 25.0, -1.0},
    {0x34D4, 1, -1.0, 0.5, 1, 23.0, -1.0},
    {0, 0, -1.0, 0.5, 0, -1.0, -1.0}
};

struct struck_animation_table D_8002D880[] = {
    {0x33AC, 0, -1.0, 0.5, 0, 25.0, -1.0},
    {0x34D4, 0, -1.0, 0.5, 0, 23.0, -1.0},
    {0x35C8, 1, -1.0, 0.5, 0, 27.0, -1.0},
    {0x36D8, 1, -1.0, 0.5, 0, 26.0, -1.0},
    {0, 0, -1.0, 0.5, 0, -1.0, -1.0}
};

struct struck_animation_table D_8002D90C[] = {
    {0x33AC, 0, -1.0, 0.5, 0, 25.0, -1.0},
    {0x34D4, 0, -1.0, 0.5, 0, 23.0, -1.0},
    {0x35C8, 1, -1.0, 0.5, 0, 27.0, -1.0},
    {0x36D8, 1, -1.0, 0.5, 0, 26.0, -1.0},
    {0, 0, -1.0, 0.5, 0, -1.0, -1.0}
};

struct struck_animation_table D_8002D998[] = {
    {0x33AC, 0, -1.0, 0.5, 1, 25.0, -1.0},
    {0x34D4, 0, -1.0, 0.5, 1, 23.0, -1.0},
    {0x35C8, 1, -1.0, 0.5, 1, 27.0, -1.0},
    {0x36D8, 1, -1.0, 0.5, 1, 26.0, -1.0},
    {0, 0, -1.0, 0.5, 0, -1.0, -1.0}
};

struct struck_animation_table D_8002DA24[] = {
    {0x30B8, 0, -1.0, 0.5, 0, 55.0, 39.0},
    {0x30B8, 1, -1.0, 0.5, 0, 55.0, 39.0},
    {0x31DC, 0, -1.0, 0.5, 0, 36.0, -1.0},
    {0x31DC, 1, -1.0, 0.5, 0, 36.0, -1.0},
    {0x32C8, 0, -1.0, 0.5, 1, 29.0, -1.0},
    {0x32C8, 1, -1.0, 0.5, 1, 29.0, -1.0},
    {0x33AC, 0, -1.0, 0.5, 1, 25.0, -1.0},
    {0x33AC, 1, -1.0, 0.5, 1, 25.0, -1.0},
    {0x34D4, 0, -1.0, 0.5, 1, 23.0, -1.0},
    {0x34D4, 1, -1.0, 0.5, 1, 23.0, -1.0},
    {0x35C8, 0, -1.0, 0.5, 1, 27.0, -1.0},
    {0x35C8, 1, -1.0, 0.5, 1, 27.0, -1.0},
    {0x36D8, 0, -1.0, 0.5, 1, 26.0, -1.0},
    {0x36D8, 1, -1.0, 0.5, 1, 26.0, -1.0},
    {0x384C, 0, -1.0, 0.5, 0, 97.0, 64.0},
    {0x384C, 1, -1.0, 0.5, 0, 97.0, 64.0},
    {0x39C0, 0, -1.0, 0.5, 0, 94.0, 66.0},
    {0x39C0, 1, -1.0, 0.5, 0, 94.0, 66.0},
    {0x3AF0, 0, -1.0, 0.5, 0, 31.0, -1.0},
    {0x3AF0, 1, -1.0, 0.5, 0, 31.0, -1.0},
    {0x3C10, 0, -1.0, 0.5, 0, 36.0, -1.0},
    {0x3C10, 1, -1.0, 0.5, 0, 36.0, -1.0},
    {0x3D04, 0, -1.0, 0.5, 0, 28.0, -1.0},
    {0x3D04, 1, -1.0, 0.5, 0, 28.0, -1.0},
    {0, 0, -1.0, 0.5, 0, -1.0, -1.0}
};

struct struck_animation_table D_8002DCE0[] = {
    {0x30B8, 0, -1.0, 0.5, 0, 55.0, 39.0},
    {0x30B8, 1, -1.0, 0.5, 0, 55.0, 39.0},
    {0x31DC, 0, -1.0, 0.5, 0, 36.0, -1.0},
    {0x31DC, 1, -1.0, 0.5, 0, 36.0, -1.0},
    {0x32C8, 0, -1.0, 0.5, 1, 29.0, -1.0},
    {0x32C8, 1, -1.0, 0.5, 1, 29.0, -1.0},
    {0x384C, 0, -1.0, 0.5, 0, 97.0, 64.0},
    {0x384C, 1, -1.0, 0.5, 0, 97.0, 64.0},
    {0x39C0, 0, -1.0, 0.5, 0, 94.0, 66.0},
    {0x39C0, 1, -1.0, 0.5, 0, 94.0, 66.0},
    {0x3AF0, 0, -1.0, 0.5, 0, 31.0, -1.0},
    {0x3AF0, 1, -1.0, 0.5, 0, 31.0, -1.0},
    {0x3C10, 0, -1.0, 0.5, 0, 36.0, -1.0},
    {0x3C10, 1, -1.0, 0.5, 0, 36.0, -1.0},
    {0x3D04, 0, -1.0, 0.5, 0, 28.0, -1.0},
    {0x3D04, 1, -1.0, 0.5, 0, 28.0, -1.0},
    {0, 0, -1.0, 0.5, 0, -1.0, -1.0}
};

struct struck_animation_table D_8002DEBC[] = {
    {0x2F94, 0, -1.0, 0.5, 0, 67.0, 54.0},
    {0x2F94, 1, -1.0, 0.5, 0, 67.0, 54.0},
    {0, 0, -1.0, 0.5, 0, -1.0, -1.0}
};

struct struck_animation_table D_8002DF10[] = {
    {0x1F84, 0, -1.0, 0.5, 0, -1.0, -1.0},
    {0x2134, 1, -1.0, 0.5, 0, -1.0, -1.0},
    {0, 0, -1.0, 0.5, 0, -1.0, -1.0}
};

struct struck_animation_table D_8002DF64[] = {
    {0x1F84, 0, -1.0, 0.5, 0, -1.0, -1.0},
    {0x2134, 1, -1.0, 0.5, 0, -1.0, -1.0},
    {0, 0, -1.0, 0.5, 0, -1.0, -1.0}
};

struct struck_animation_table D_8002DFB8[] = {
    {0x1F84, 0, -1.0, 0.5, 0, -1.0, -1.0},
    {0x2134, 1, -1.0, 0.5, 0, -1.0, -1.0},
    {0x540C, 1, 20.0, 0.40000001, 0, -1.0, -1.0},
    {0, 0, -1.0, 0.5, 0, -1.0, -1.0}
};

struct struck_animation_table D_8002E028[] = {
    {0x2134, 0, -1.0, 0.5, 0, -1.0, -1.0},
    {0x1F84, 1, -1.0, 0.5, 0, -1.0, -1.0},
    {0, 0, -1.0, 0.5, 0, -1.0, -1.0}
};

struct struck_animation_table D_8002E07C[] = {
    {0x2134, 0, -1.0, 0.5, 0, -1.0, -1.0},
    {0x1F84, 1, -1.0, 0.5, 0, -1.0, -1.0},
    {0, 0, -1.0, 0.5, 0, -1.0, -1.0}
};

struct struck_animation_table D_8002E0D0[] = {
    {0x2134, 0, -1.0, 0.5, 0, -1.0, -1.0},
    {0x1F84, 1, -1.0, 0.5, 0, -1.0, -1.0},
    {0x540C, 0, 20.0, 0.40000001, 0, -1.0, -1.0},
    {0, 0, -1.0, 0.5, 0, -1.0, -1.0}
};

struct struck_animation_table D_8002E140[] = {
    {0x282C, 0, 20.0, 0.5, 0, -1.0, -1.0},
    {0x282C, 1, 30.0, 0.5, 0, -1.0, -1.0},
    {0x39C0, 0, 20.0, 0.5, 0, -1.0, -1.0},
    {0x39C0, 1, 20.0, 0.5, 0, -1.0, -1.0},
    {0x30B8, 0, 15.0, 0.5, 0, -1.0, -1.0},
    {0x30B8, 1, 15.0, 0.5, 0, -1.0, -1.0},
    {0x3AF0, 0, 10.0, 0.25, 0, -1.0, -1.0},
    {0x3AF0, 1, 10.0, 0.25, 0, -1.0, -1.0},
    {0, 0, -1.0, 0.5, 0, -1.0, -1.0}
};

struct struck_animation_table D_8002E23C[] = {
    {0x2E64, 0, 15.0, 0.5, 0, 87.0, 203.0},
    {0x2E64, 1, 15.0, 0.5, 0, 87.0, 203.0},
    {0x39C0, 0, 20.0, 0.5, 0, -1.0, -1.0},
    {0x39C0, 1, 20.0, 0.5, 0, -1.0, -1.0},
    {0x30B8, 0, 15.0, 0.5, 0, -1.0, -1.0},
    {0x30B8, 1, 15.0, 0.5, 0, -1.0, -1.0},
    {0, 0, -1.0, 0.5, 0, -1.0, -1.0}
};

struct struck_animation_table D_8002E300[] = {
    {0x1C9C, 0, -1.0, 0.5, 0, -1.0, -1.0},
    {0x1E40, 1, -1.0, 0.5, 0, -1.0, -1.0},
    {0, 0, -1.0, 0.5, 0, -1.0, -1.0}
};

struct struck_animation_table D_8002E354[] = {
    {0x1A6C, 0, -1.0, 0.5, 0, -1.0, -1.0},
    {0x1B54, 1, -1.0, 0.5, 0, -1.0, -1.0},
    {0, 0, -1.0, 0.5, 0, -1.0, -1.0}
};

struct struck_animation_table D_8002E3A8[] = {
    {0x186C, 0, -1.0, 0.5, 0, -1.0, -1.0},
    {0x1984, 1, -1.0, 0.5, 0, -1.0, -1.0},
    {0x39C0, 0, 20.0, 0.5, 0, -1.0, -1.0},
    {0, 0, -1.0, 0.5, 0, -1.0, -1.0}
};

struct struck_animation_table D_8002E418[] = {
    {0x1E40, 0, -1.0, 0.5, 0, -1.0, -1.0},
    {0x1C9C, 1, -1.0, 0.5, 0, -1.0, -1.0},
    {0, 0, -1.0, 0.5, 0, -1.0, -1.0}
};

struct struck_animation_table D_8002E46C[] = {
    {0x1B54, 0, -1.0, 0.5, 0, -1.0, -1.0},
    {0x1A6C, 1, -1.0, 0.5, 0, -1.0, -1.0},
    {0, 0, -1.0, 0.5, 0, -1.0, -1.0}
};

struct struck_animation_table D_8002E4C0[] = {
    {0x1984, 0, -1.0, 0.5, 0, -1.0, -1.0},
    {0x186C, 1, -1.0, 0.5, 0, -1.0, -1.0},
    {0x39C0, 1, 20.0, 0.5, 0, -1.0, -1.0},
    {0, 0, -1.0, 0.5, 0, -1.0, -1.0}
};

struct struck_animation_table D_8002E530[] = {
    {0x39C0, 0, 20.0, 0.5, 0, -1.0, -1.0},
    {0x39C0, 1, 20.0, 0.5, 0, -1.0, -1.0},
    {0x30B8, 0, 15.0, 0.5, 0, -1.0, -1.0},
    {0x30B8, 1, 15.0, 0.5, 0, -1.0, -1.0},
    {0, 0, -1.0, 0.5, 0, -1.0, -1.0}
};

struct struck_animation_table D_8002E5BC[] = {
    {0x39C0, 0, 20.0, 0.5, 0, -1.0, -1.0},
    {0x39C0, 1, 20.0, 0.5, 0, -1.0, -1.0},
    {0x30B8, 0, 15.0, 0.5, 0, -1.0, -1.0},
    {0x30B8, 1, 15.0, 0.5, 0, -1.0, -1.0},
    {0, 0, -1.0, 0.5, 0, -1.0, -1.0}
};



struct explosion_death_animation D_8002E648[] = {
    {0x98C8, 0, 0.5, 9.0, 18.0, 29.0, -1.0},
    {0x98C8, 1, 0.5, 9.0, 18.0, 29.0, -1.0},
    {0xA1B8, 0, 0.5, 11.0, 19.0, 31.0, -1.0},
    {0xA1B8, 1, 0.5, 11.0, 19.0, 31.0, -1.0},
    {0xA094, 0, 0.5, 6.0, 20.0, 27.0, -1.0},
    {0xA094, 1, 0.5, 6.0, 20.0, 27.0, -1.0},
    {0xA424, 0, 0.5, 29.0, 36.0, 48.0, -1.0},
    {0xA424, 1, 0.5, 29.0, 36.0, 48.0, -1.0},
    {0xA538, 0, 0.5, 29.0, 38.0, 49.0, -1.0},
    {0xA538, 1, 0.5, 29.0, 38.0, 49.0, -1.0},
    {0xA650, 0, 0.5, 19.0, 30.0, 42.0, -1.0},
    {0xA650, 1, 0.5, 19.0, 30.0, 42.0, -1.0},
    {0x9A2C, 0, 0.5, 9.0, 21.0, 29.0, 55.0},
    {0x9A2C, 1, 0.5, 9.0, 21.0, 29.0, 55.0},
    {0x9D5C, 0, 0.5, 6.0, 18.0, 27.0, -1.0},
    {0x9D5C, 1, 0.5, 6.0, 18.0, 27.0, -1.0},
    {0x9E44, 0, 0.5, 6.0, 19.0, 29.0, -1.0},
    {0x9E44, 1, 0.5, 6.0, 19.0, 29.0, -1.0},
    {0x9B48, 0, 0.5, 8.0, 14.0, 25.0, -1.0},
    {0x9B48, 1, 0.5, 8.0, 14.0, 25.0, -1.0},
    {0x9C4C, 0, 0.5, 8.0, 19.0, 25.0, -1.0},
    {0x9C4C, 1, 0.5, 8.0, 19.0, 25.0, -1.0},
    {0x9F48, 0, 0.5, 12.0, 21.0, 29.0, -1.0},
    {0x9F48, 1, 0.5, 12.0, 21.0, 29.0, -1.0},
    {0xA2F8, 0, 0.5, 22.0, 30.0, 41.0, -1.0},
    {0xA2F8, 1, 0.5, 22.0, 30.0, 41.0, -1.0},
    {0, 0, 0.5, 0.0, 0.0, 0.0, -1.0},
};

s8 expl_forward[] = {0x0, 0x01, 0x02, 0x03, 0x4, 0x05, 0x00, 0x00};
s8 expl_f_left[] = {0x7, 0x09, 0x0B, 0x00};
s8 expl_f_right[] = {0x06, 0x08, 0x0A, 0x00};
s8 expl_left[] = {0x0C, 0x0F, 0x11, 0x00};
s8 expl_right[] = {0x0D, 0x0E, 0x10, 0x00};
s8 expl_back[] = {0x14, 0x15, 0x16, 0x17};
s8 expl_b_right[] = {0x12, 0x18, 0x00, 0x00};
s8 expl_b_left[] = {0x13, 0x19, 0x00, 0x00};

struct explosion_anim_group_info explosion_animation_table[EXPLOSION_ANIMATION_TABLE_LEN] = {
    {expl_forward, 6},
    {expl_f_left, 3},
    {expl_left, 3},
    {expl_b_right, 2},
    {expl_back, 4},
    {expl_b_left, 2},
    {expl_right, 3},
    {expl_f_right, 3}
};

struct weapon_firing_animation_table rifle_firing_animation_group1[] = {
    {0x214, 28.0, 0, 0, 0, -1.0, 23.0, 54.0, -1.0, -1.0, 18.0, 54.0, 0.87266463, -0.52359879, 1.0471976, -0.34906587, 1.6, 1.8},
    {0, 0.0, 0, 0, 0, -1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0}
};

struct anim_group_info ptr_rifle_firing_animation_group1 = { &rifle_firing_animation_group1, -1 };

struct weapon_firing_animation_table rifle_firing_animation_group2[] = {
    {0x144, 37.0, 0, 0, 0, -1.0, 30.0, 81.0, -1.0, -1.0, 25.0, 81.0, 0.87266463, -0.69813174, 0.69813174, -0.69813174, 1.6, 1.75},
    {0x318, 27.0, 0, 0, 0, -1.0, 22.0, 61.0, -1.0, -1.0, 17.0, 61.0, 0.87266463, -0.2617994, 0.69813174, -0.69813174, 2.0, 1.0},
    {0, 0.0, 0, 0, 0, -1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0}
};

struct anim_group_info ptr_rifle_firing_animation_group2 = { &rifle_firing_animation_group2, -1 };

struct weapon_firing_animation_table rifle_firing_animation_group5[] = {
    {0x144, 37.0, 0, 0, 0, -1.0, 30.0, 81.0, -1.0, -1.0, 25.0, 81.0, 0.87266463, -0.69813174, 0.69813174, -0.69813174, 1.6, 1.75},
    {0x318, 27.0, 0, 0, 0, -1.0, 22.0, 61.0, -1.0, -1.0, 17.0, 61.0, 0.87266463, -0.2617994, 0.69813174, -0.69813174, 2.0, 1.0},
    {0, 0.0, 0, 0, 0, -1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0}
};

struct anim_group_info ptr_rifle_firing_animation_group5 = { &rifle_firing_animation_group5, -1 };

struct weapon_firing_animation_table rifle_firing_animation_group3[] = {
    {0x3C4, 19.0, 0, 1.5707964, 0, -1.0, 19.0, 61.0, -1.0, -1.0, 14.0, 61.0, 0.87266463, -0.34906587, 0.43633232, -1.0471976, 2.5, 2.5},
    {0, 0.0, 0, 0, 0, -1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0}
};

struct anim_group_info ptr_rifle_firing_animation_group3 = { &rifle_firing_animation_group3, -1 };

struct weapon_firing_animation_table rifle_firing_animation_group4[] = {
    {0x814, 27.0, 0, 0, 0, -1.0, 39.0, 74.0, -1.0, -1.0, 34.0, 74.0, 0.87266463, -0.69813174, 0.78539819, -0.69813174, 1.5, 1.5},
    {0, 0.0, 0, 0, 0, -1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0}
};

struct anim_group_info ptr_rifle_firing_animation_group4 = { &rifle_firing_animation_group4, -1 };

struct anim_group_info *ptr_rifle_firing_animation_groups[] = {
    &ptr_rifle_firing_animation_group1,
    &ptr_rifle_firing_animation_group2,
    &ptr_rifle_firing_animation_group2,
    &ptr_rifle_firing_animation_group2,
    &ptr_rifle_firing_animation_group2,
    &ptr_rifle_firing_animation_group2,
    &ptr_rifle_firing_animation_group2,
    &ptr_rifle_firing_animation_group2,
    &ptr_rifle_firing_animation_group2,
    &ptr_rifle_firing_animation_group2,
    &ptr_rifle_firing_animation_group3,
    &ptr_rifle_firing_animation_group3,
    &ptr_rifle_firing_animation_group3,
    &ptr_rifle_firing_animation_group3,
    &ptr_rifle_firing_animation_group3,
    &ptr_rifle_firing_animation_group3,
    &ptr_rifle_firing_animation_group4,
    &ptr_rifle_firing_animation_group4,
    &ptr_rifle_firing_animation_group4,
    &ptr_rifle_firing_animation_group4,
    &ptr_rifle_firing_animation_group4,
    &ptr_rifle_firing_animation_group4,
    &ptr_rifle_firing_animation_group5,
    &ptr_rifle_firing_animation_group5,
    &ptr_rifle_firing_animation_group5,
    &ptr_rifle_firing_animation_group5,
    &ptr_rifle_firing_animation_group5,
    &ptr_rifle_firing_animation_group5,
    &ptr_rifle_firing_animation_group5,
    &ptr_rifle_firing_animation_group5,
    &ptr_rifle_firing_animation_group5,
    &ptr_rifle_firing_animation_group1
};

struct weapon_firing_animation_table pistol_firing_animation_group1[] = {
    {0x60D4, 26.0, 0, 0, 12.0, 140.0, 58.0, 92.0, 60.0, 79.0, 20.0, 120.0, 0.87266463, -0.69813174, 0.69813174, -0.69813174, 0.0, 0.0},
    {0x6484, 0.0, 0, 0, 17.0, 100.0, 25.0, 87.0, 30.0, 55.0, 20.0, 93.0, 0.87266463, -0.69813174, 0.69813174, -1.0471976, 0.0, 0.0},
    {0x6554, 0.0, 0, 0, 12.0, 64.0, 19.0, 51.0, 24.0, 46.0, 14.0, 58.0, 0.87266463, -0.69813174, 0.52359879, -0.78539819, 0.0, 0.0},
    {0x6644, 22.0, 0, 0, 4.0, 69.0, 22.0, 49.0, 22.0, 33.0, 8.0, 58.0, 0.87266463, -0.69813174, 0.43633232, -0.78539819, 0.0, 0.0},
    {0, 0.0, 0, 0, 0, -1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0}
};

struct anim_group_info ptr_pistol_firing_animation_group1 = { &pistol_firing_animation_group1, -1 };

struct weapon_firing_animation_table pistol_firing_animation_group2[] = {
    {0x60D4, 26.0, 0, 0, 12.0, 140.0, 58.0, 92.0, 60.0, 79.0, 20.0, 120.0, 0.87266463, -0.69813174, 0.69813174, -0.69813174, 0.0, 0.0},
    {0x6644, 22.0, 0, 0, 4.0, 69.0, 22.0, 49.0, 22.0, 33.0, 8.0, 58.0, 0.87266463, -0.69813174, 0.43633232, -0.78539819, 0.0, 0.0},
    {0, 0.0, 0, 0, 0, -1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0}
};

struct anim_group_info ptr_pistol_firing_animation_group2 = { &pistol_firing_animation_group2, -1 };

struct weapon_firing_animation_table pistol_firing_animation_group3[] = {
    {0x60D4, 26.0, 0, 0, 12.0, 140.0, 58.0, 92.0, 60.0, 79.0, 20.0, 120.0, 0.87266463, -0.69813174, 0.69813174, -0.69813174, 0.0, 0.0},
    {0x6644, 22.0, 0, 0, 4.0, 69.0, 22.0, 49.0, 22.0, 33.0, 8.0, 58.0, 0.87266463, -0.69813174, 0.43633232, -0.78539819, 0.0, 0.0},
    {0x694C, 0.0, 0, 1.5707964, 7.0, 130.0, 45.0, 93.0, 56.0, 73.0, 26.0, 107.0, 0.87266463, -0.69813174, 0.34906587, -0.52359879, 0.0, 0.0},
    {0x6A18, 15.0, 0, 1.5707964, 5.0, 76.0, 20.0, 31.0, 31.0, 38.0, 15.0, 49.0, 0.87266463, -0.69813174, 0.52359879, -1.0471976, 0.0, 0.0},
    {0, 0.0, 0, 0, 0, -1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0}
};

struct anim_group_info ptr_pistol_firing_animation_group3 = { &pistol_firing_animation_group3, -1 };

struct weapon_firing_animation_table pistol_firing_animation_group6[] = {
    {0x60D4, 26.0, 0, 0, 12.0, 140.0, 58.0, 92.0, 60.0, 79.0, 20.0, 120.0, 0.87266463, -0.69813174, 0.69813174, -0.69813174, 0.0, 0.0},
    {0x6644, 22.0, 0, 0, 4.0, 69.0, 22.0, 49.0, 22.0, 33.0, 8.0, 58.0, 0.87266463, -0.69813174, 0.43633232, -0.78539819, 0.0, 0.0},
    {0x6738, 0.0, 0, 4.712389, 7.0, 139.0, 54.0, 105.0, 61.0, 88.0, 26.0, 120.0, 0.87266463, -0.69813174, 0.69813174, -0.61086529, 0.0, 0.0},
    {0x6808, 19.0, 0, 4.712389, 4.0, 79.0, 21.0, 50.0, 26.0, 42.0, 10.0, 64.0, 0.87266463, -0.69813174, 0.69813174, -0.61086529, 0.0, 0.0},
    {0, 0.0, 0, 0, 0, -1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0}
};

struct anim_group_info ptr_pistol_firing_animation_group6 = { &pistol_firing_animation_group6, -1 };

struct weapon_firing_animation_table pistol_firing_animation_group4[] = {
    {0x6A18, 19.0, 0, 1.5707964, 5.0, 76.0, 20.0, 31.0, 31.0, 38.0, 15.0, 49.0, 0.87266463, -0.69813174, 0.52359879, -1.0471976, 0.0, 0.0},
    {0, 0.0, 0, 0, 0, -1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0}
};

struct anim_group_info ptr_pistol_firing_animation_group4 = { &pistol_firing_animation_group4, -1 };

struct weapon_firing_animation_table pistol_firing_animation_group5[] = {
    {0x6808, 19.0, 0, 4.712389, 4.0, 79.0, 21.0, 50.0, 26.0, 42.0, 10.0, 64.0, 0.87266463, -0.69813174, 0.69813174, -0.61086529, 0.0, 0.0},
    {0, 0.0, 0, 0, 0, -1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0}
};

struct anim_group_info ptr_pistol_firing_animation_group5 = { &pistol_firing_animation_group5, -1 };

struct anim_group_info *ptr_pistol_firing_animation_groups[] = {
    &ptr_pistol_firing_animation_group1,
    &ptr_pistol_firing_animation_group1,
    &ptr_pistol_firing_animation_group2,
    &ptr_pistol_firing_animation_group2,
    &ptr_pistol_firing_animation_group2,
    &ptr_pistol_firing_animation_group3,
    &ptr_pistol_firing_animation_group3,
    &ptr_pistol_firing_animation_group3,
    &ptr_pistol_firing_animation_group3,
    &ptr_pistol_firing_animation_group3,
    &ptr_pistol_firing_animation_group4,
    &ptr_pistol_firing_animation_group4,
    &ptr_pistol_firing_animation_group4,
    &ptr_pistol_firing_animation_group4,
    &ptr_pistol_firing_animation_group4,
    &ptr_pistol_firing_animation_group4,
    &ptr_pistol_firing_animation_group5,
    &ptr_pistol_firing_animation_group5,
    &ptr_pistol_firing_animation_group5,
    &ptr_pistol_firing_animation_group5,
    &ptr_pistol_firing_animation_group5,
    &ptr_pistol_firing_animation_group5,
    &ptr_pistol_firing_animation_group6,
    &ptr_pistol_firing_animation_group6,
    &ptr_pistol_firing_animation_group6,
    &ptr_pistol_firing_animation_group6,
    &ptr_pistol_firing_animation_group6,
    &ptr_pistol_firing_animation_group2,
    &ptr_pistol_firing_animation_group2,
    &ptr_pistol_firing_animation_group2,
    &ptr_pistol_firing_animation_group1,
    &ptr_pistol_firing_animation_group1
};

struct weapon_firing_animation_table doubles_firing_animation_group1[] = {
    {0x8E1C, 26.0, 0, 0, 7.0, 92.0, 28.0, 68.0, -1.0, -1.0, 11.0, 73.0, 0.87266463, -0.69813174, 0.69813174, -0.69813174, 0.0, 0.0},
    {0, 0.0, 0, 0, 0, -1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0}
};

struct anim_group_info ptr_doubles_firing_animation_group1 = { &doubles_firing_animation_group1, -1 };

struct weapon_firing_animation_table doubles_firing_animation_group2[] = {
    {0x8F2C, 26.0, 0, 1.5707964, 9.0, 112.0, 38.0, 87.0, -1.0, -1.0, 19.0, 98.0, 0.87266463, -0.69813174, 0.43633232, -0.43633232, 0.0, 0.0},
    {0x9194, 25.0, 0, 1.5707964, 10.0, 112.0, 32.0, 86.0, -1.0, -1.0, 19.0, 97.0, 0.87266463, -0.69813174, 0.43633232, -0.43633232, 0.0, 0.0},
    {0, 0.0, 0, 0, 0, -1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0}
};

struct anim_group_info ptr_doubles_firing_animation_group2 = { &doubles_firing_animation_group2, -1 };

struct weapon_firing_animation_table doubles_firing_animation_group3[] = {
    {0x9084, 39.0, 0, 4.712389, 22.0, 127.0, 44.0, 102.0, -1.0, -1.0, 28.0, 112.0, 0.87266463, -0.69813174, 0.43633232, -0.43633232, 0.0, 0.0},
    {0x92EC, 39.0, 0, 4.712389, 23.0, 130.0, 46.0, 100.0, -1.0, -1.0, 30.0, 110.0, 0.87266463, -0.69813174, 0.43633232, -0.43633232, 0.0, 0.0},
    {0, 0.0, 0, 0, 0, -1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0}
};

struct anim_group_info ptr_doubles_firing_animation_group3 = { &doubles_firing_animation_group3, -1 };

struct anim_group_info *ptr_doubles_firing_animation_groups[] = {
    &ptr_doubles_firing_animation_group1,
    &ptr_doubles_firing_animation_group1,
    &ptr_doubles_firing_animation_group1,
    &ptr_doubles_firing_animation_group1,
    &ptr_doubles_firing_animation_group1,
    &ptr_doubles_firing_animation_group2,
    &ptr_doubles_firing_animation_group2,
    &ptr_doubles_firing_animation_group2,
    &ptr_doubles_firing_animation_group2,
    &ptr_doubles_firing_animation_group2,
    &ptr_doubles_firing_animation_group2,
    &ptr_doubles_firing_animation_group2,
    &ptr_doubles_firing_animation_group2,
    &ptr_doubles_firing_animation_group2,
    &ptr_doubles_firing_animation_group2,
    &ptr_doubles_firing_animation_group2,
    &ptr_doubles_firing_animation_group3,
    &ptr_doubles_firing_animation_group3,
    &ptr_doubles_firing_animation_group3,
    &ptr_doubles_firing_animation_group3,
    &ptr_doubles_firing_animation_group3,
    &ptr_doubles_firing_animation_group3,
    &ptr_doubles_firing_animation_group3,
    &ptr_doubles_firing_animation_group3,
    &ptr_doubles_firing_animation_group3,
    &ptr_doubles_firing_animation_group3,
    &ptr_doubles_firing_animation_group3,
    &ptr_doubles_firing_animation_group1,
    &ptr_doubles_firing_animation_group1,
    &ptr_doubles_firing_animation_group1,
    &ptr_doubles_firing_animation_group1,
    &ptr_doubles_firing_animation_group1
};

struct weapon_firing_animation_table crouched_rifle_firing_animation_group1[] = {
    {0x990, 27.0, 0, 0, 0, -1.0, 35.0, 75.0, -1.0, -1.0, 31.0, 75.0, 0.87266463, -0.69813174, 0.90757126, -0.69813174, 1.5, 1.5},
};

struct weapon_firing_animation_table crouched_rifle_firing_animation_groupA[] = {
    {0xB84, 24.0, 0, 0, 0, -1.0, 46.0, 98.0, -1.0, -1.0, 41.0, 98.0, 0.87266463, -0.52359879, 1.134464, -0.69813174, 1.6, 1.6},
    {0, 0.0, 0, 0, 0, -1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0}
};

struct anim_group_info ptr_crouched_rifle_firing_animation_group1 = { &crouched_rifle_firing_animation_group1, -1 };

struct weapon_firing_animation_table crouched_rifle_firing_animation_group2[] = {
    {0xDB4, 26.0, 0, 0, 0, -1.0, 34.0, 87.0, -1.0, -1.0, 29.0, 87.0, 0.87266463, -0.52359879, 0.69813174, -0.95993108, 1.6, 2.0},
    {0, 0.0, 0, 0, 0, -1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0}
};

struct anim_group_info ptr_crouched_rifle_firing_animation_group2 = { &crouched_rifle_firing_animation_group2, -1 };

struct weapon_firing_animation_table crouched_rifle_firing_animation_group3[] = {
    {0x1028, 28.0, 0, 0, 0, -1.0, 36.0, 88.0, -1.0, -1.0, 31.0, 88.0, 0.87266463, -0.69813174, 0.87266463, -0.43633232, 1.6, 1.5},
    {0, 0.0, 0, 0, 0, -1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0}
};

struct anim_group_info ptr_crouched_rifle_firing_animation_group3 = { &crouched_rifle_firing_animation_group3, -1 };

struct anim_group_info *ptr_crouched_rifle_firing_animation_groups[] = {
    &ptr_crouched_rifle_firing_animation_group1,
    &ptr_crouched_rifle_firing_animation_group1,
    &ptr_crouched_rifle_firing_animation_group1,
    &ptr_crouched_rifle_firing_animation_group1,
    &ptr_crouched_rifle_firing_animation_group1,
    &ptr_crouched_rifle_firing_animation_group1,
    &ptr_crouched_rifle_firing_animation_group1,
    &ptr_crouched_rifle_firing_animation_group1,
    &ptr_crouched_rifle_firing_animation_group1,
    &ptr_crouched_rifle_firing_animation_group1,
    &ptr_crouched_rifle_firing_animation_group2,
    &ptr_crouched_rifle_firing_animation_group2,
    &ptr_crouched_rifle_firing_animation_group2,
    &ptr_crouched_rifle_firing_animation_group2,
    &ptr_crouched_rifle_firing_animation_group2,
    &ptr_crouched_rifle_firing_animation_group2,
    &ptr_crouched_rifle_firing_animation_group3,
    &ptr_crouched_rifle_firing_animation_group3,
    &ptr_crouched_rifle_firing_animation_group3,
    &ptr_crouched_rifle_firing_animation_group3,
    &ptr_crouched_rifle_firing_animation_group3,
    &ptr_crouched_rifle_firing_animation_group3,
    &ptr_crouched_rifle_firing_animation_group1,
    &ptr_crouched_rifle_firing_animation_group1,
    &ptr_crouched_rifle_firing_animation_group1,
    &ptr_crouched_rifle_firing_animation_group1,
    &ptr_crouched_rifle_firing_animation_group1,
    &ptr_crouched_rifle_firing_animation_group1,
    &ptr_crouched_rifle_firing_animation_group1,
    &ptr_crouched_rifle_firing_animation_group1,
    &ptr_crouched_rifle_firing_animation_group1,
    &ptr_crouched_rifle_firing_animation_group1
};

struct weapon_firing_animation_table crouched_pistol_firing_animation_group1[] = {
    {0x6C18, 25.0, 0, 0, 12.0, 132.0, 55.0, 87.0, 67.0, 87.0, 26.0, 111.0, 0.87266463, -0.69813174, 0.61086529, -0.78539819, 0.0, 0.0},
    {0x6D50, 26.0, 0, 0, 8.0, 89.0, 31.0, 63.0, 41.0, 51.0, 21.0, 80.0, 0.87266463, -0.69813174, 0.34906587, -1.134464, 0.0, 0.0},
    {0, 0.0, 0, 0, 0, -1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0}
};

struct anim_group_info ptr_crouched_pistol_firing_animation_group1 = { &crouched_pistol_firing_animation_group1, -1 };

struct weapon_firing_animation_table crouched_pistol_firing_animation_group2[] = {
    {0x71D0, 47.0, 0, 1.5707964, 7.0, 128.0, 33.0, 86.0,47.0, 74.0, 23.0, 106.0, 0.87266463, -0.52359879, 0.52359879, -0.78539819, 0.0, 0.0},
    {0x7304, 18.0, 0, 1.5707964, 7.0, 78.0, 28.0, 52.0, 35.0, 45.0, 15.0, 66.0, 0.87266463, -0.087266468, 0.69813174, -0.78539819, 1.5, 1.0},
    {0x7430, 20.0, 0, 1.5707964, 13.0, 92.0, 37.0, 67.0, 42.0, 55.0, 25.0, 84.0, 0.87266463, -0.52359879, 0.34906587, -0.69813174, 0.0, 0.0},
    {0, 0.0, 0, 0, 0, -1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0}
};

struct anim_group_info ptr_crouched_pistol_firing_animation_group2 = { &crouched_pistol_firing_animation_group2, -1 };

struct weapon_firing_animation_table crouched_pistol_firing_animation_group3[] = {
    {0x6F08, 28.0, 0, 4.712389, 15.0, 124.0, 38.0, 97.0, 60.0, 84.0, 20.0, 106.0, 0.87266463, -0.69813174, 0.52359879, -0.87266463, 0.0, 0.0},
    {0x700C, 23.0, 0, 4.712389, 0, 85.0, 32.0, 38.0, 38.0, 60.0, 14.0, 71.0, 0.87266463, -0.69813174, 0.61086529, -0.95993108, 0.0, 0.0},
    {0, 0.0, 0, 0, 0, -1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0}
};

struct anim_group_info ptr_crouched_pistol_firing_animation_group3 = { &crouched_pistol_firing_animation_group3, -1 };

struct anim_group_info *ptr_crouched_pistol_firing_animation_groups[] = {
    &ptr_crouched_pistol_firing_animation_group1,
    &ptr_crouched_pistol_firing_animation_group1,
    &ptr_crouched_pistol_firing_animation_group1,
    &ptr_crouched_pistol_firing_animation_group1,
    &ptr_crouched_pistol_firing_animation_group1,
    &ptr_crouched_pistol_firing_animation_group1,
    &ptr_crouched_pistol_firing_animation_group1,
    &ptr_crouched_pistol_firing_animation_group1,
    &ptr_crouched_pistol_firing_animation_group1,
    &ptr_crouched_pistol_firing_animation_group1,
    &ptr_crouched_pistol_firing_animation_group2,
    &ptr_crouched_pistol_firing_animation_group2,
    &ptr_crouched_pistol_firing_animation_group2,
    &ptr_crouched_pistol_firing_animation_group2,
    &ptr_crouched_pistol_firing_animation_group2,
    &ptr_crouched_pistol_firing_animation_group2,
    &ptr_crouched_pistol_firing_animation_group3,
    &ptr_crouched_pistol_firing_animation_group3,
    &ptr_crouched_pistol_firing_animation_group3,
    &ptr_crouched_pistol_firing_animation_group3,
    &ptr_crouched_pistol_firing_animation_group3,
    &ptr_crouched_pistol_firing_animation_group3,
    &ptr_crouched_pistol_firing_animation_group1,
    &ptr_crouched_pistol_firing_animation_group1,
    &ptr_crouched_pistol_firing_animation_group1,
    &ptr_crouched_pistol_firing_animation_group1,
    &ptr_crouched_pistol_firing_animation_group1,
    &ptr_crouched_pistol_firing_animation_group1,
    &ptr_crouched_pistol_firing_animation_group1,
    &ptr_crouched_pistol_firing_animation_group1,
    &ptr_crouched_pistol_firing_animation_group1,
    &ptr_crouched_pistol_firing_animation_group1
};

struct weapon_firing_animation_table crouched_doubles_firing_animation_group1[] = {
    {0x8698, 22.0, 0, 0, 10.0, 111.0, 34.0, 87.0, -1.0, -1.0, 17.0, 104.0, 0.87266463, -0.69813174, 0.61086529, -0.78539819, 0.0, 0.0},
    {0x8AAC, 25.0, 0, 0, 9.0, 92.0, 33.0, 62.0, -1.0, -1.0, 18.0, 69.0, 0.87266463, -0.69813174, 0.61086529, -0.78539819, 0.0, 0.0},
    {0, 0.0, 0, 0, 0, -1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0}
};

struct anim_group_info ptr_crouched_doubles_firing_animation_group1 = { &crouched_doubles_firing_animation_group1, -1 };

struct weapon_firing_animation_table crouched_doubles_firing_animation_group2[] = {
    {0x8800, 28.0, 0, 1.5707964, 15.0, 108.0, 34.0, 73.0, -1.0, -1.0, 17.0, 93.0, 0.87266463, -0.69813174, 0.52359879, -0.78539819, 0.0, 0.0},
    {0x8BF0, 19.0, 0, 1.5707964, 3.0, 95.0, 30.0, 64.0, -1.0, -1.0, 14.0, 71.0, 0.87266463, -0.69813174, 0.52359879, -0.78539819, 1.5, 1.0},
    {0, 0.0, 0, 0, 0, -1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0}
};

struct anim_group_info ptr_crouched_doubles_firing_animation_group2 = { &crouched_doubles_firing_animation_group2, -1 };

struct weapon_firing_animation_table crouched_doubles_firing_animation_group3[] = {
    {0x8978, 31.0, 0, 4.712389, 14.0, 111.0, 40.0, 83.0,-1.0, -1.0, 21.0, 94.0, 0.87266463, -0.69813174, 0.52359879, -0.78539819, 0.0, 0.0},
    {0x8D28, 26.0, 0, 4.712389, 7.0, 89.0, 34.0, 60.0, -1.0, -1.0, 20.0, 68.0, 0.87266463, -0.69813174, 0.52359879, -0.78539819, 0.0, 0.0},
    {0, 0.0, 0, 0, 0, -1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0}
};

struct anim_group_info ptr_crouched_doubles_firing_animation_group3 = { &crouched_doubles_firing_animation_group3, -1 };

struct anim_group_info* ptr_crouched_doubles_firing_animation_groups[] = {
    &ptr_crouched_doubles_firing_animation_group1,
    &ptr_crouched_doubles_firing_animation_group1,
    &ptr_crouched_doubles_firing_animation_group1,
    &ptr_crouched_doubles_firing_animation_group1,
    &ptr_crouched_doubles_firing_animation_group1,
    &ptr_crouched_doubles_firing_animation_group1,
    &ptr_crouched_doubles_firing_animation_group1,
    &ptr_crouched_doubles_firing_animation_group1,
    &ptr_crouched_doubles_firing_animation_group1,
    &ptr_crouched_doubles_firing_animation_group1,
    &ptr_crouched_doubles_firing_animation_group2,
    &ptr_crouched_doubles_firing_animation_group2,
    &ptr_crouched_doubles_firing_animation_group2,
    &ptr_crouched_doubles_firing_animation_group2,
    &ptr_crouched_doubles_firing_animation_group2,
    &ptr_crouched_doubles_firing_animation_group2,
    &ptr_crouched_doubles_firing_animation_group3,
    &ptr_crouched_doubles_firing_animation_group3,
    &ptr_crouched_doubles_firing_animation_group3,
    &ptr_crouched_doubles_firing_animation_group3,
    &ptr_crouched_doubles_firing_animation_group3,
    &ptr_crouched_doubles_firing_animation_group3,
    &ptr_crouched_doubles_firing_animation_group1,
    &ptr_crouched_doubles_firing_animation_group1,
    &ptr_crouched_doubles_firing_animation_group1,
    &ptr_crouched_doubles_firing_animation_group1,
    &ptr_crouched_doubles_firing_animation_group1,
    &ptr_crouched_doubles_firing_animation_group1,
    &ptr_crouched_doubles_firing_animation_group1,
    &ptr_crouched_doubles_firing_animation_group1,
    &ptr_crouched_doubles_firing_animation_group1,
    &ptr_crouched_doubles_firing_animation_group1
};

struct weapon_firing_animation_table D_80030078[] = {
    // sizeof(struct weapon_firing_animation_table) = 0x48 = 72.
    // address 0xD_80030078. Index 0, = D_80030078 + 0.
    {0x1334, 76.0, 0.0, 0.0, 20.0, -1.0, 98.0, 161.0, -1.0, -1.0, 93.0, 161.0, 0.87266463, -0.52359879, 0.69813174, -0.69813174, 1.7, 2.0},
    
    // address 0x800300C0. Index 1, = D_80030078 + 72.
    {0x1578, 58.0, 0.0, 0.0, 10.0, -1.0, 77.0, 104.0, -1.0, -1.0, 72.0, 104.0, 0.87266463, -0.34906587, 0.61086529, -0.69813174, 1.55, 1.5},
    
    // address 0x80030108. Index 2, = D_80030078 + 144.
    {0x17B4, 61.0, 0.0, 0.0, 10.0, -1.0, 83.0, 128.0, -1.0, -1.0, 78.0, 128.0, 0.87266463, -0.52359879, 0.87266463, -0.52359879, 1.2, 1.3},
    
    // address 0x80030150. Index 3, = D_80030078 + 216.
    {0x3FA0, 63.0, 0.0, 0.0, 10.0, -1.0, 73.0, 114.0, -1.0, -1.0, 68.0, 114.0, 0.87266463, -0.52359879, 0.61086529, -0.61086529, 1.65, 1.5},
    
    // address 0x80030198. Index 4, = D_80030078 + 288.
    {0x1334, 76.0, 0.0, 0.0, 20.0, 76.0, 98.0, 161.0, -1.0, -1.0, 93.0, 161.0, 0.87266463, -0.52359879, 0.69813174, -0.69813174, 1.7, 2.0},
    
    // address 0x800301E0. Index 5, = D_80030078 + 360.
    {0x1578, 58.0, 0.0, 0.0, 10.0, 63.0, 77.0, 104.0, -1.0, -1.0, 72.0, 104.0, 0.87266463, -0.34906587, 0.61086529, -0.69813174, 1.55, 1.5},
    
    // address 0x80030228. Index 6, = D_80030078 + 432.
    {0x17B4, 61.0, 0.0, 0.0, 10.0, 56.0, 83.0, 128.0, -1.0, -1.0, 78.0, 128.0, 0.87266463, -0.52359879, 0.87266463, -0.52359879, 1.2, 1.3},
    
    // address 0x80030270. Index 7, = D_80030078 + 504.
    {0x3FA0, 63.0, 0.0, 0.0, 10.0, 50.0, 73.0, 114.0, -1.0, -1.0, 68.0, 114.0, 0.87266463, -0.52359879, 0.61086529, -0.61086529, 1.65, 1.5},
    
    // address 0x800302B8. Index 8, = D_80030078 + 576.
    {0x6554, 0.0, 0.0, 0.0, 7.0, 64.0, 19.0, 51.0, 24.0, 46.0, 14.0, 58.0, 0.87266463, -0.69813174, 0.52359879, -0.78539819, 0.0, 0.0},
    
    // address 0x80030300. Index 9, = D_80030078 + 648.
    {0x6A18, 0.0, 0.0, 1.5707964, 14.0, 76.0, 26.0, 31.0, 31.0, 38.0, 15.0, 49.0, 0.87266463, -0.69813174, 0.52359879, -1.0471976, 0.0, 0.0},
    
    // address 0x80030348. Index 10, = D_80030078 + 720.
    {0x6D50, 26.0, 0.0, 0.0, 25.0, 89.0, 41.0, 63.0, 41.0, 51.0, 21.0, 80.0, 0.87266463, -0.69813174, 0.34906587, -1.134464, 0.0, 0.0},
    
    // address 0x80030390. Index 11, = D_80030078 + 792.
    {0x7304, 18.0, 0.0, 1.5707964, 11.0, 78.0, 33.0, 52.0, 35.0, 45.0, 15.0, 66.0, 0.87266463, -0.087266468, 0.69813174, -0.78539819, 1.5, 1.0},
    
    // address 0x800303D8. Index 12, = D_80030078 + 864.
    {0x8E1C, 26.0, 0.0, 0.0, 7.0, 92.0, 28.0, 68.0, -1.0, -1.0, 11.0, 73.0, 0.87266463, -0.69813174, 0.69813174, -0.69813174, 0.0, 0.0},
    
    // address 0x80030420. Index 13, = D_80030078 + 936.
    {0x8F2C, 26.0, 0.0, 1.5707964, 9.0, 112.0, 38.0, 87.0, -1.0, -1.0, 19.0, 98.0, 0.87266463, -0.69813174, 0.43633232, -0.43633232, 0.0, 0.0},
    
    // address 0x80030468. Index 14, = D_80030078 + 1008.
    {0x8698, 22.0, 0.0, 0.0, 10.0, 11.0, 34.0, 87.0, -1.0, -1.0, 17.0, 104.0, 0.87266463, -0.69813174, 0.61086529, -0.78539819, 0.0, 0.0},
    
    // address 0x800304B0. Index 15, = D_80030078 + 1080.
    {0x8800, 28.0, 0.0, 1.5707964, 15.0, 108.0, 34.0, 73.0, -1.0, -1.0, 17.0, 93.0, 0.87266463, -0.69813174, 0.52359879, -0.78539819, 0.0, 0.0},
    
    // address 0x800304F8. Index 16, = D_80030078 + 1152.
    {0x8E1C, 26.0, 0.0, 0.0, 7.0, 92.0, 28.0, 68.0, -1.0, -1.0, 11.0, 73.0, 0.87266463, -0.69813174, 0.69813174, -0.69813174, 0.0, 0.0},
    
    // address 0x80030540. Index 17, = D_80030078 + 1224.
    {0x9194, 25.0, 0.0, 1.5707964, 10.0, 112.0, 32.0, 86.0, -1.0, -1.0, 19.0, 97.0, 0.87266463, -0.69813174, 0.43633232, -0.43633232, 0.0, 0.0},
    
    // address 0x80030588. Index 18, = D_80030078 + 1296.
    {0x8AAC, 25.0, 0.0, 0.0, 9.0, 92.0, 33.0, 62.0, -1.0, -1.0, 18.0, 69.0, 0.87266463, -0.69813174, 0.61086529, -0.78539819, 0.0, 0.0},
    
    // address 0x800305D0. Index 19, = D_80030078 + 1368.
    {0x8BF0, 19.0, 0.0, 1.5707964, 3.0, 95.0, 30.0, 64.0, -1.0, -1.0, 14.0, 71.0, 0.87266463, -0.69813174, 0.52359879, -0.78539819, 1.5, 1.0},
    
    // address 0x80030618. Index 20, = D_80030078 + 1440.
    {0, 0.0, 0.0, 0.0, 0.0, -1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0}
};

struct weapon_firing_animation_table D_80030660[] = {
    // address 0x80030660. Index 0, = D_80030660 + 0.
    {0x4574, 0.0, 0.0, 0.0, 0.0, -1.0, 0.0, 0.0, -1.0, -1.0, 0.0, 0.0, 0.87266463, -0.52359879, 0.52359879, -0.52359879, 1.4, 1.3},
    
    // address 0x800306A8. Index 1, = D_80030660 + 72.
    {0x45CC, 0.0, 0.0, 0.0, 0.0, -1.0, 0.0, 0.0, -1.0, -1.0, 0.0, 0.0, 0.87266463, -0.52359879, 0.52359879, -0.52359879, 1.1, 1.2},

    // address 0x800306F0. Index 2, = D_80030660 + 144.
    {0x74A4, 0.0, 0.0, 0.0, 0.0, -1.0, 0.0, 0.0, -1.0, -1.0, 0.0, 0.0, 0.87266463, -0.52359879, 0.52359879, -0.52359879, 0.0, 0.0},
    
    // address 0x80030738. Index 3, = D_80030660 + 216.
    {0x75EC, 0.0, 0.0, 0.0, 0.0, -1.0, 0.0, 0.0, -1.0, -1.0, 0.0, 0.0, 0.87266463, -0.52359879, 0.52359879, -0.52359879, 0.0, 0.0},
    
    // address 0x80030780. Index 4, = D_80030660 + 288.
    {0x8274, 0.0, 0.0, 0.0, 0.0, -1.0, 0.0, 0.0, -1.0, -1.0, 0.0, 0.0, 0.87266463, -0.52359879, 0.52359879, -0.52359879, 0.0, 0.0},
    
    // address 0x800307C8. Index 5, = D_80030660 + 360.
    {0x8340, 0.0, 0.0, 0.0, 0.0, -1.0, 0.0, 0.0, -1.0, -1.0, 0.0, 0.0, 0.87266463, -0.52359879, 0.52359879, -0.52359879, 0.0, 0.0},
    
    // address 0x80030810. Index 6, = D_80030660 + 432.
    {0x82E0, 0.0, 0.0, 0.0, 0.0, -1.0, 0.0, 0.0, -1.0, -1.0, 0.0, 0.0, 0.87266463, -0.52359879, 0.52359879, -0.52359879, 0.0, 0.0},
    
    // address 0x80030858. Index 7, = D_80030660 + 504.
    {0x83A4, 0.0, 0.0, 0.0, 0.0, -1.0, 0.0, 0.0, -1.0, -1.0, 0.0, 0.0, 0.87266463, -0.52359879, 0.52359879, -0.52359879, 0.0, 0.0},
    
    // address 0x800308A0. Index 8, = D_80030660 + 576.
    {0x76B8, 0.0, 0.0, 1.5707964, 0.0, -1.0, 0.0, 0.0, -1.0, -1.0, 0.0, 0.0, 0.87266463, -0.52359879, 0.52359879, -0.52359879, 0.0, 0.0},
    
    // address 0x800308E8. Index 9, = D_80030660 + 648.
    {0x7650, 0.0, 0.0, 4.712389, 0.0, -1.0, 0.0, 0.0, -1.0, -1.0, 0.0, 0.0, 0.87266463, -0.52359879, 0.52359879, -0.52359879, 0.0, 0.0},
    
    // address 0x80030930. Index 10, = D_80030660 + 720.
    {0, 0.0, 0.0, 0.0, 0.0, -1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0}
};

s32 objectiveregisters1 = 0;

/**
 * List of characters updated every tick.
 * 
 * Address 0x8003097C.
*/
ChrRecord* g_ActiveChrs = 0;

/**
 * Number of items in g_ActiveChrs.
 * 
 * Adress 0x0x80030980.
*/
s32 g_ActiveChrsCount = 0;

/**
 * Default factor in chrlvModelScaleAnimationRelated.
 * Address 0x80030984.
*/
f32 D_80030984 = 0;

/**
 * Scale factor in chrlvModelScaleAnimationRelated, used by ANIM_DATA_running.
 * Address 0x80030988.
*/
f32 D_80030988 = 0;

/**
 * Scale factor in chrlvModelScaleAnimationRelated, used by ANIM_DATA_sprinting.
 * Address 0x8003098C.
*/
f32 D_8003098C = 0;

/**
 * Scale factor in chrlvModelScaleAnimationRelated, used by ANIM_DATA_walking_unarmed.
 * Address 0x80030990.
*/
f32 D_80030990 = 0;

/**
 * Scale factor in chrlvModelScaleAnimationRelated, used by ANIM_DATA_running_one_handed_weapon.
 * Address 0x80030994.
*/
f32 D_80030994 = 0;

/**
 * Scale factor in chrlvModelScaleAnimationRelated, used by first ANIM_DATA_sprinting_one_handed_weapon.
 * Address 0x80030998.
*/
f32 D_80030998 = 0;

/**
 * Scale factor in chrlvModelScaleAnimationRelated, used by ANIM_DATA_walking_female.
 * Address 0x8003099C.
*/
f32 D_8003099C = 0;

/**
 * Scale factor in chrlvModelScaleAnimationRelated, used by ANIM_DATA_running_female.
 * Address 0x800309A0.
*/
f32 D_800309A0 = 0;

/**
 * Scale factor in chrlvModelScaleAnimationRelated, used by duplicate ANIM_DATA_sprinting_one_handed_weapon.
 * Address 0x800309A4.
*/
f32 D_800309A4 = 0;

 point2d D_800309A8 = {0, 0};
//s32 D_800309AC = 0;
 point2d D_800309B0 = {0, 0};
//s32 D_800309B4 = 0;

/**
 * Default firing state, left and right hand.
 * Address 0x800309B8.
*/
 point2d D_800309B8 = {0, 0};

/**
 * Default firing state when crouched, left and right hand.
 * Address 0x800309C0.
*/
 point2d D_800309C0 = {0, 0};

 point2d D_800309C8 = {0, 0};
 point2d D_800309D0 = {0, 0};
 point2d D_800309D8 = {0, 0};

 point2d D_800309E0 = {0, 0};

 point2d D_800309E8 = {0, 0};

 point2d D_800309F0 = {0, 0};

s16 male_guard_yelps[] = {
    0x86,  0x87,  0x88,  0x89,  0x8A,  0x8B,  0x8C,  0x8D,  0x8E,  0x8F,
    0x90,  0x91,  0x92,  0x93,  0x94,  0x95,  0x96,  0x97,  0x98,  0x99,
    0x9A,  0x9B,  0x9C,  0x9D,  0x9E,     0
};

s16 female_guard_yelps[] = {
    0xD,   0xE,   0xF,     0
};

s32 male_guard_yelp_counter = 0;
s32 female_guard_yelp_counter = 0;

s16 metal_ricochet_SFX[3] = {0xEF, 0x48, 0x49};


// // probably better described as vec3d than coordinates.
coord3d D_80030A44 = {0,0,0};





s32 get_numguards(void)
{
  return num_guards;
}

void get_ptr_allocated_block_for_vertices(int param_1)
{
  dynAllocate(param_1 << 4);
}

void set_show_patrols_flag(s32 flag)
{
  show_patrols_flag = flag;
}

s32 get_show_patrols_flag(void)
{
  return show_patrols_flag;
}




/**
 * Unreferenced.
 * 
 * Address 0x7F01F574.
 */
f32 chrUnusedYPositionRelated(PropRecord *arg0)
{
    if (arg0->stan != 0)
    {
        if (sub_GAME_7F0B20D0(&arg0->stan, arg0->pos.x, arg0->pos.z, 1.0f) < 0)
        {
            return stanGetPositionYValue(arg0->stan, arg0->pos.x, arg0->pos.z);
        }

        return 0.0f;
    }

    return 0.0f;
}



void set_or_unset_GUARDdata_flag(ChrRecord *self, bool unset)
{
    if (unset)
    {
        self->hidden &= ~0x100;
    }
    else
    {
        self->hidden |= 0x100;
    }
    return;
}


#ifdef NONMATCHING
void sub_GAME_7F01F614(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F01F614
/* 054144 7F01F614 27BDFF68 */  addiu $sp, $sp, -0x98
/* 054148 7F01F618 AFB10030 */  sw    $s1, 0x30($sp)
/* 05414C 7F01F61C AFB0002C */  sw    $s0, 0x2c($sp)
/* 054150 7F01F620 00C08025 */  move  $s0, $a2
/* 054154 7F01F624 00E08825 */  move  $s1, $a3
/* 054158 7F01F628 AFBF0034 */  sw    $ra, 0x34($sp)
/* 05415C 7F01F62C AFA40098 */  sw    $a0, 0x98($sp)
/* 054160 7F01F630 AFA5009C */  sw    $a1, 0x9c($sp)
/* 054164 7F01F634 AFA00094 */  sw    $zero, 0x94($sp)
/* 054168 7F01F638 AFA50090 */  sw    $a1, 0x90($sp)
/* 05416C 7F01F63C 8C840018 */  lw    $a0, 0x18($a0)
/* 054170 7F01F640 27A50084 */  addiu $a1, $sp, 0x84
/* 054174 7F01F644 27A70088 */  addiu $a3, $sp, 0x88
/* 054178 7F01F648 0FC08C58 */  jal   chrGetChrWidthHeight
/* 05417C 7F01F64C 27A6008C */   addiu $a2, $sp, 0x8c
/* 054180 7F01F650 8FA40098 */  lw    $a0, 0x98($sp)
/* 054184 7F01F654 0FC07D7A */  jal   set_or_unset_GUARDdata_flag
/* 054188 7F01F658 00002825 */   move  $a1, $zero
/* 05418C 7F01F65C 0FC2C731 */  jal   sub_GAME_7F0B1CC4
/* 054190 7F01F660 00000000 */   nop   
/* 054194 7F01F664 C6240008 */  lwc1  $f4, 8($s1)
/* 054198 7F01F668 8E050000 */  lw    $a1, ($s0)
/* 05419C 7F01F66C 8E060008 */  lw    $a2, 8($s0)
/* 0541A0 7F01F670 8E270000 */  lw    $a3, ($s1)
/* 0541A4 7F01F674 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0541A8 7F01F678 44818000 */  mtc1  $at, $f16
/* 0541AC 7F01F67C C7A6008C */  lwc1  $f6, 0x8c($sp)
/* 0541B0 7F01F680 C7A80088 */  lwc1  $f8, 0x88($sp)
/* 0541B4 7F01F684 44805000 */  mtc1  $zero, $f10
/* 0541B8 7F01F688 2418001F */  li    $t8, 31
/* 0541BC 7F01F68C AFB80014 */  sw    $t8, 0x14($sp)
/* 0541C0 7F01F690 27A40090 */  addiu $a0, $sp, 0x90
/* 0541C4 7F01F694 E7A40010 */  swc1  $f4, 0x10($sp)
/* 0541C8 7F01F698 E7A60018 */  swc1  $f6, 0x18($sp)
/* 0541CC 7F01F69C E7B00024 */  swc1  $f16, 0x24($sp)
/* 0541D0 7F01F6A0 E7A8001C */  swc1  $f8, 0x1c($sp)
/* 0541D4 7F01F6A4 0FC2C389 */  jal   sub_GAME_7F0B0E24
/* 0541D8 7F01F6A8 E7AA0020 */   swc1  $f10, 0x20($sp)
/* 0541DC 7F01F6AC 10400016 */  beqz  $v0, .L7F01F708
/* 0541E0 7F01F6B0 27A40090 */   addiu $a0, $sp, 0x90
/* 0541E4 7F01F6B4 C7B2008C */  lwc1  $f18, 0x8c($sp)
/* 0541E8 7F01F6B8 C7A40088 */  lwc1  $f4, 0x88($sp)
/* 0541EC 7F01F6BC 8E250000 */  lw    $a1, ($s1)
/* 0541F0 7F01F6C0 8E260008 */  lw    $a2, 8($s1)
/* 0541F4 7F01F6C4 2419001F */  li    $t9, 31
/* 0541F8 7F01F6C8 AFB90010 */  sw    $t9, 0x10($sp)
/* 0541FC 7F01F6CC 8FA70084 */  lw    $a3, 0x84($sp)
/* 054200 7F01F6D0 E7B20014 */  swc1  $f18, 0x14($sp)
/* 054204 7F01F6D4 0FC2C62E */  jal   sub_GAME_7F0B18B8
/* 054208 7F01F6D8 E7A40018 */   swc1  $f4, 0x18($sp)
/* 05420C 7F01F6DC 0441000A */  bgez  $v0, .L7F01F708
/* 054210 7F01F6E0 8FA800A8 */   lw    $t0, 0xa8($sp)
/* 054214 7F01F6E4 11000005 */  beqz  $t0, .L7F01F6FC
/* 054218 7F01F6E8 8FA90098 */   lw    $t1, 0x98($sp)
/* 05421C 7F01F6EC A1200009 */  sb    $zero, 9($t1)
/* 054220 7F01F6F0 3C0A8005 */  lui   $t2, %hi(g_GlobalTimer) 
/* 054224 7F01F6F4 8D4A837C */  lw    $t2, %lo(g_GlobalTimer)($t2)
/* 054228 7F01F6F8 AD2A00CC */  sw    $t2, 0xcc($t1)
.L7F01F6FC:
/* 05422C 7F01F6FC 8FAB0090 */  lw    $t3, 0x90($sp)
/* 054230 7F01F700 10000135 */  b     .L7F01FBD8
/* 054234 7F01F704 AFAB0094 */   sw    $t3, 0x94($sp)
.L7F01F708:
/* 054238 7F01F708 AFA0004C */  sw    $zero, 0x4c($sp)
/* 05423C 7F01F70C 27A40078 */  addiu $a0, $sp, 0x78
/* 054240 7F01F710 0FC2CA2C */  jal   getCollisionEdge_maybe
/* 054244 7F01F714 27A5006C */   addiu $a1, $sp, 0x6c
/* 054248 7F01F718 50400130 */  beql  $v0, $zero, .L7F01FBDC
/* 05424C 7F01F71C 8FA40098 */   lw    $a0, 0x98($sp)
/* 054250 7F01F720 C6260000 */  lwc1  $f6, ($s1)
/* 054254 7F01F724 C6080000 */  lwc1  $f8, ($s0)
/* 054258 7F01F728 46083281 */  sub.s $f10, $f6, $f8
/* 05425C 7F01F72C C7A8006C */  lwc1  $f8, 0x6c($sp)
/* 054260 7F01F730 C7A60078 */  lwc1  $f6, 0x78($sp)
/* 054264 7F01F734 E7AA0060 */  swc1  $f10, 0x60($sp)
/* 054268 7F01F738 C6120008 */  lwc1  $f18, 8($s0)
/* 05426C 7F01F73C C6300008 */  lwc1  $f16, 8($s1)
/* 054270 7F01F740 46083032 */  c.eq.s $f6, $f8
/* 054274 7F01F744 C7AA0080 */  lwc1  $f10, 0x80($sp)
/* 054278 7F01F748 46128101 */  sub.s $f4, $f16, $f18
/* 05427C 7F01F74C C7B00074 */  lwc1  $f16, 0x74($sp)
/* 054280 7F01F750 45000005 */  bc1f  .L7F01F768
/* 054284 7F01F754 E7A40068 */   swc1  $f4, 0x68($sp)
/* 054288 7F01F758 46105032 */  c.eq.s $f10, $f16
/* 05428C 7F01F75C 00000000 */  nop   
/* 054290 7F01F760 45030028 */  bc1tl .L7F01F804
/* 054294 7F01F764 8FAE004C */   lw    $t6, 0x4c($sp)
.L7F01F768:
/* 054298 7F01F768 C7A60074 */  lwc1  $f6, 0x74($sp)
/* 05429C 7F01F76C C7A80080 */  lwc1  $f8, 0x80($sp)
/* 0542A0 7F01F770 C7B2006C */  lwc1  $f18, 0x6c($sp)
/* 0542A4 7F01F774 C7A40078 */  lwc1  $f4, 0x78($sp)
/* 0542A8 7F01F778 46083081 */  sub.s $f2, $f6, $f8
/* 0542AC 7F01F77C 240C0001 */  li    $t4, 1
/* 0542B0 7F01F780 AFAC004C */  sw    $t4, 0x4c($sp)
/* 0542B4 7F01F784 46049001 */  sub.s $f0, $f18, $f4
/* 0542B8 7F01F788 46021282 */  mul.s $f10, $f2, $f2
/* 0542BC 7F01F78C E7A2005C */  swc1  $f2, 0x5c($sp)
/* 0542C0 7F01F790 46000402 */  mul.s $f16, $f0, $f0
/* 0542C4 7F01F794 E7A00054 */  swc1  $f0, 0x54($sp)
/* 0542C8 7F01F798 0C007DF8 */  jal   sqrtf
/* 0542CC 7F01F79C 46105300 */   add.s $f12, $f10, $f16
/* 0542D0 7F01F7A0 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0542D4 7F01F7A4 44819000 */  mtc1  $at, $f18
/* 0542D8 7F01F7A8 C7A40054 */  lwc1  $f4, 0x54($sp)
/* 0542DC 7F01F7AC C7A8005C */  lwc1  $f8, 0x5c($sp)
/* 0542E0 7F01F7B0 46009083 */  div.s $f2, $f18, $f0
/* 0542E4 7F01F7B4 C7B00068 */  lwc1  $f16, 0x68($sp)
/* 0542E8 7F01F7B8 8FAD009C */  lw    $t5, 0x9c($sp)
/* 0542EC 7F01F7BC 46022182 */  mul.s $f6, $f4, $f2
/* 0542F0 7F01F7C0 C7A40060 */  lwc1  $f4, 0x60($sp)
/* 0542F4 7F01F7C4 46024282 */  mul.s $f10, $f8, $f2
/* 0542F8 7F01F7C8 E7A60054 */  swc1  $f6, 0x54($sp)
/* 0542FC 7F01F7CC 46105482 */  mul.s $f18, $f10, $f16
/* 054300 7F01F7D0 E7AA005C */  swc1  $f10, 0x5c($sp)
/* 054304 7F01F7D4 46062202 */  mul.s $f8, $f4, $f6
/* 054308 7F01F7D8 C6040000 */  lwc1  $f4, ($s0)
/* 05430C 7F01F7DC 46089300 */  add.s $f12, $f18, $f8
/* 054310 7F01F7E0 460C3402 */  mul.s $f16, $f6, $f12
/* 054314 7F01F7E4 46048480 */  add.s $f18, $f16, $f4
/* 054318 7F01F7E8 460C5202 */  mul.s $f8, $f10, $f12
/* 05431C 7F01F7EC E7B20040 */  swc1  $f18, 0x40($sp)
/* 054320 7F01F7F0 C6060008 */  lwc1  $f6, 8($s0)
/* 054324 7F01F7F4 AFAD0090 */  sw    $t5, 0x90($sp)
/* 054328 7F01F7F8 46064400 */  add.s $f16, $f8, $f6
/* 05432C 7F01F7FC E7B00048 */  swc1  $f16, 0x48($sp)
/* 054330 7F01F800 8FAE004C */  lw    $t6, 0x4c($sp)
.L7F01F804:
/* 054334 7F01F804 27A40090 */  addiu $a0, $sp, 0x90
/* 054338 7F01F808 8FA70040 */  lw    $a3, 0x40($sp)
/* 05433C 7F01F80C 11C00027 */  beqz  $t6, .L7F01F8AC
/* 054340 7F01F810 C7A40048 */   lwc1  $f4, 0x48($sp)
/* 054344 7F01F814 8E050000 */  lw    $a1, ($s0)
/* 054348 7F01F818 8E060008 */  lw    $a2, 8($s0)
/* 05434C 7F01F81C 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 054350 7F01F820 44813000 */  mtc1  $at, $f6
/* 054354 7F01F824 C7B2008C */  lwc1  $f18, 0x8c($sp)
/* 054358 7F01F828 C7AA0088 */  lwc1  $f10, 0x88($sp)
/* 05435C 7F01F82C 44804000 */  mtc1  $zero, $f8
/* 054360 7F01F830 240F001F */  li    $t7, 31
/* 054364 7F01F834 AFAF0014 */  sw    $t7, 0x14($sp)
/* 054368 7F01F838 E7A40010 */  swc1  $f4, 0x10($sp)
/* 05436C 7F01F83C E7B20018 */  swc1  $f18, 0x18($sp)
/* 054370 7F01F840 E7A60024 */  swc1  $f6, 0x24($sp)
/* 054374 7F01F844 E7AA001C */  swc1  $f10, 0x1c($sp)
/* 054378 7F01F848 0FC2C389 */  jal   sub_GAME_7F0B0E24
/* 05437C 7F01F84C E7A80020 */   swc1  $f8, 0x20($sp)
/* 054380 7F01F850 10400016 */  beqz  $v0, .L7F01F8AC
/* 054384 7F01F854 27A40090 */   addiu $a0, $sp, 0x90
/* 054388 7F01F858 C7B0008C */  lwc1  $f16, 0x8c($sp)
/* 05438C 7F01F85C C7A40088 */  lwc1  $f4, 0x88($sp)
/* 054390 7F01F860 2418001F */  li    $t8, 31
/* 054394 7F01F864 AFB80010 */  sw    $t8, 0x10($sp)
/* 054398 7F01F868 8FA50040 */  lw    $a1, 0x40($sp)
/* 05439C 7F01F86C 8FA60048 */  lw    $a2, 0x48($sp)
/* 0543A0 7F01F870 8FA70084 */  lw    $a3, 0x84($sp)
/* 0543A4 7F01F874 E7B00014 */  swc1  $f16, 0x14($sp)
/* 0543A8 7F01F878 0FC2C62E */  jal   sub_GAME_7F0B18B8
/* 0543AC 7F01F87C E7A40018 */   swc1  $f4, 0x18($sp)
/* 0543B0 7F01F880 0441000A */  bgez  $v0, .L7F01F8AC
/* 0543B4 7F01F884 C7B20040 */   lwc1  $f18, 0x40($sp)
/* 0543B8 7F01F888 E6320000 */  swc1  $f18, ($s1)
/* 0543BC 7F01F88C C7AA0048 */  lwc1  $f10, 0x48($sp)
/* 0543C0 7F01F890 24190002 */  li    $t9, 2
/* 0543C4 7F01F894 E62A0008 */  swc1  $f10, 8($s1)
/* 0543C8 7F01F898 8FA80098 */  lw    $t0, 0x98($sp)
/* 0543CC 7F01F89C A1190009 */  sb    $t9, 9($t0)
/* 0543D0 7F01F8A0 8FAA0090 */  lw    $t2, 0x90($sp)
/* 0543D4 7F01F8A4 100000CC */  b     .L7F01FBD8
/* 0543D8 7F01F8A8 AFAA0094 */   sw    $t2, 0x94($sp)
.L7F01F8AC:
/* 0543DC 7F01F8AC C7A80078 */  lwc1  $f8, 0x78($sp)
/* 0543E0 7F01F8B0 C6260000 */  lwc1  $f6, ($s1)
/* 0543E4 7F01F8B4 C7A40080 */  lwc1  $f4, 0x80($sp)
/* 0543E8 7F01F8B8 46064401 */  sub.s $f16, $f8, $f6
/* 0543EC 7F01F8BC C7A60084 */  lwc1  $f6, 0x84($sp)
/* 0543F0 7F01F8C0 E7B00054 */  swc1  $f16, 0x54($sp)
/* 0543F4 7F01F8C4 C6320008 */  lwc1  $f18, 8($s1)
/* 0543F8 7F01F8C8 46063002 */  mul.s $f0, $f6, $f6
/* 0543FC 7F01F8CC 46122281 */  sub.s $f10, $f4, $f18
/* 054400 7F01F8D0 460A5482 */  mul.s $f18, $f10, $f10
/* 054404 7F01F8D4 E7AA005C */  swc1  $f10, 0x5c($sp)
/* 054408 7F01F8D8 46108182 */  mul.s $f6, $f16, $f16
/* 05440C 7F01F8DC C7B0006C */  lwc1  $f16, 0x6c($sp)
/* 054410 7F01F8E0 46069280 */  add.s $f10, $f18, $f6
/* 054414 7F01F8E4 4600503E */  c.le.s $f10, $f0
/* 054418 7F01F8E8 00000000 */  nop   
/* 05441C 7F01F8EC 45020058 */  bc1fl .L7F01FA50
/* 054420 7F01F8F0 C6260000 */   lwc1  $f6, ($s1)
/* 054424 7F01F8F4 C6100000 */  lwc1  $f16, ($s0)
/* 054428 7F01F8F8 C7A60080 */  lwc1  $f6, 0x80($sp)
/* 05442C 7F01F8FC 46104032 */  c.eq.s $f8, $f16
/* 054430 7F01F900 00000000 */  nop   
/* 054434 7F01F904 45020007 */  bc1fl .L7F01F924
/* 054438 7F01F908 C60A0008 */   lwc1  $f10, 8($s0)
/* 05443C 7F01F90C C6120008 */  lwc1  $f18, 8($s0)
/* 054440 7F01F910 46122032 */  c.eq.s $f4, $f18
/* 054444 7F01F914 00000000 */  nop   
/* 054448 7F01F918 450300B0 */  bc1tl .L7F01FBDC
/* 05444C 7F01F91C 8FA40098 */   lw    $a0, 0x98($sp)
/* 054450 7F01F920 C60A0008 */  lwc1  $f10, 8($s0)
.L7F01F924:
/* 054454 7F01F924 C7A40078 */  lwc1  $f4, 0x78($sp)
/* 054458 7F01F928 460A3201 */  sub.s $f8, $f6, $f10
/* 05445C 7F01F92C 46004407 */  neg.s $f16, $f8
/* 054460 7F01F930 E7B00054 */  swc1  $f16, 0x54($sp)
/* 054464 7F01F934 C6120000 */  lwc1  $f18, ($s0)
/* 054468 7F01F938 46122181 */  sub.s $f6, $f4, $f18
/* 05446C 7F01F93C 46063282 */  mul.s $f10, $f6, $f6
/* 054470 7F01F940 E7A6005C */  swc1  $f6, 0x5c($sp)
/* 054474 7F01F944 46108202 */  mul.s $f8, $f16, $f16
/* 054478 7F01F948 0C007DF8 */  jal   sqrtf
/* 05447C 7F01F94C 46085300 */   add.s $f12, $f10, $f8
/* 054480 7F01F950 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 054484 7F01F954 44812000 */  mtc1  $at, $f4
/* 054488 7F01F958 C7B20054 */  lwc1  $f18, 0x54($sp)
/* 05448C 7F01F95C C7B0005C */  lwc1  $f16, 0x5c($sp)
/* 054490 7F01F960 46002083 */  div.s $f2, $f4, $f0
/* 054494 7F01F964 C7A80068 */  lwc1  $f8, 0x68($sp)
/* 054498 7F01F968 8FA9009C */  lw    $t1, 0x9c($sp)
/* 05449C 7F01F96C 240B001F */  li    $t3, 31
/* 0544A0 7F01F970 27A40090 */  addiu $a0, $sp, 0x90
/* 0544A4 7F01F974 46029182 */  mul.s $f6, $f18, $f2
/* 0544A8 7F01F978 C7B20060 */  lwc1  $f18, 0x60($sp)
/* 0544AC 7F01F97C 46028282 */  mul.s $f10, $f16, $f2
/* 0544B0 7F01F980 E7A60054 */  swc1  $f6, 0x54($sp)
/* 0544B4 7F01F984 46085102 */  mul.s $f4, $f10, $f8
/* 0544B8 7F01F988 E7AA005C */  swc1  $f10, 0x5c($sp)
/* 0544BC 7F01F98C 46069402 */  mul.s $f16, $f18, $f6
/* 0544C0 7F01F990 C6120000 */  lwc1  $f18, ($s0)
/* 0544C4 7F01F994 46102300 */  add.s $f12, $f4, $f16
/* 0544C8 7F01F998 460C3202 */  mul.s $f8, $f6, $f12
/* 0544CC 7F01F99C 46124100 */  add.s $f4, $f8, $f18
/* 0544D0 7F01F9A0 460C5402 */  mul.s $f16, $f10, $f12
/* 0544D4 7F01F9A4 C7AA0088 */  lwc1  $f10, 0x88($sp)
/* 0544D8 7F01F9A8 C7B2008C */  lwc1  $f18, 0x8c($sp)
/* 0544DC 7F01F9AC E7A40040 */  swc1  $f4, 0x40($sp)
/* 0544E0 7F01F9B0 C6060008 */  lwc1  $f6, 8($s0)
/* 0544E4 7F01F9B4 AFA90090 */  sw    $t1, 0x90($sp)
/* 0544E8 7F01F9B8 44072000 */  mfc1  $a3, $f4
/* 0544EC 7F01F9BC 46068200 */  add.s $f8, $f16, $f6
/* 0544F0 7F01F9C0 44813000 */  mtc1  $at, $f6
/* 0544F4 7F01F9C4 44808000 */  mtc1  $zero, $f16
/* 0544F8 7F01F9C8 E7A80048 */  swc1  $f8, 0x48($sp)
/* 0544FC 7F01F9CC 8E060008 */  lw    $a2, 8($s0)
/* 054500 7F01F9D0 8E050000 */  lw    $a1, ($s0)
/* 054504 7F01F9D4 AFAB0014 */  sw    $t3, 0x14($sp)
/* 054508 7F01F9D8 E7A80010 */  swc1  $f8, 0x10($sp)
/* 05450C 7F01F9DC E7AA001C */  swc1  $f10, 0x1c($sp)
/* 054510 7F01F9E0 E7B20018 */  swc1  $f18, 0x18($sp)
/* 054514 7F01F9E4 E7A60024 */  swc1  $f6, 0x24($sp)
/* 054518 7F01F9E8 0FC2C389 */  jal   sub_GAME_7F0B0E24
/* 05451C 7F01F9EC E7B00020 */   swc1  $f16, 0x20($sp)
/* 054520 7F01F9F0 10400079 */  beqz  $v0, .L7F01FBD8
/* 054524 7F01F9F4 27A40090 */   addiu $a0, $sp, 0x90
/* 054528 7F01F9F8 C7A4008C */  lwc1  $f4, 0x8c($sp)
/* 05452C 7F01F9FC C7A80088 */  lwc1  $f8, 0x88($sp)
/* 054530 7F01FA00 240C001F */  li    $t4, 31
/* 054534 7F01FA04 AFAC0010 */  sw    $t4, 0x10($sp)
/* 054538 7F01FA08 8FA50040 */  lw    $a1, 0x40($sp)
/* 05453C 7F01FA0C 8FA60048 */  lw    $a2, 0x48($sp)
/* 054540 7F01FA10 8FA70084 */  lw    $a3, 0x84($sp)
/* 054544 7F01FA14 E7A40014 */  swc1  $f4, 0x14($sp)
/* 054548 7F01FA18 0FC2C62E */  jal   sub_GAME_7F0B18B8
/* 05454C 7F01FA1C E7A80018 */   swc1  $f8, 0x18($sp)
/* 054550 7F01FA20 0441006D */  bgez  $v0, .L7F01FBD8
/* 054554 7F01FA24 C7B20040 */   lwc1  $f18, 0x40($sp)
/* 054558 7F01FA28 E6320000 */  swc1  $f18, ($s1)
/* 05455C 7F01FA2C C7AA0048 */  lwc1  $f10, 0x48($sp)
/* 054560 7F01FA30 240D0002 */  li    $t5, 2
/* 054564 7F01FA34 E62A0008 */  swc1  $f10, 8($s1)
/* 054568 7F01FA38 8FAE0098 */  lw    $t6, 0x98($sp)
/* 05456C 7F01FA3C A1CD0009 */  sb    $t5, 9($t6)
/* 054570 7F01FA40 8FAF0090 */  lw    $t7, 0x90($sp)
/* 054574 7F01FA44 10000064 */  b     .L7F01FBD8
/* 054578 7F01FA48 AFAF0094 */   sw    $t7, 0x94($sp)
/* 05457C 7F01FA4C C6260000 */  lwc1  $f6, ($s1)
.L7F01FA50:
/* 054580 7F01FA50 C7A80074 */  lwc1  $f8, 0x74($sp)
/* 054584 7F01FA54 46068101 */  sub.s $f4, $f16, $f6
/* 054588 7F01FA58 E7A40054 */  swc1  $f4, 0x54($sp)
/* 05458C 7F01FA5C C6320008 */  lwc1  $f18, 8($s1)
/* 054590 7F01FA60 46124281 */  sub.s $f10, $f8, $f18
/* 054594 7F01FA64 460A5182 */  mul.s $f6, $f10, $f10
/* 054598 7F01FA68 E7AA005C */  swc1  $f10, 0x5c($sp)
/* 05459C 7F01FA6C 46042482 */  mul.s $f18, $f4, $f4
/* 0545A0 7F01FA70 46123280 */  add.s $f10, $f6, $f18
/* 0545A4 7F01FA74 4600503E */  c.le.s $f10, $f0
/* 0545A8 7F01FA78 00000000 */  nop   
/* 0545AC 7F01FA7C 45020057 */  bc1fl .L7F01FBDC
/* 0545B0 7F01FA80 8FA40098 */   lw    $a0, 0x98($sp)
/* 0545B4 7F01FA84 C6040000 */  lwc1  $f4, ($s0)
/* 0545B8 7F01FA88 C7B20074 */  lwc1  $f18, 0x74($sp)
/* 0545BC 7F01FA8C 46048032 */  c.eq.s $f16, $f4
/* 0545C0 7F01FA90 00000000 */  nop   
/* 0545C4 7F01FA94 45020007 */  bc1fl .L7F01FAB4
/* 0545C8 7F01FA98 C60A0008 */   lwc1  $f10, 8($s0)
/* 0545CC 7F01FA9C C6060008 */  lwc1  $f6, 8($s0)
/* 0545D0 7F01FAA0 46064032 */  c.eq.s $f8, $f6
/* 0545D4 7F01FAA4 00000000 */  nop   
/* 0545D8 7F01FAA8 4503004C */  bc1tl .L7F01FBDC
/* 0545DC 7F01FAAC 8FA40098 */   lw    $a0, 0x98($sp)
/* 0545E0 7F01FAB0 C60A0008 */  lwc1  $f10, 8($s0)
.L7F01FAB4:
/* 0545E4 7F01FAB4 C7A8006C */  lwc1  $f8, 0x6c($sp)
/* 0545E8 7F01FAB8 460A9401 */  sub.s $f16, $f18, $f10
/* 0545EC 7F01FABC 46008107 */  neg.s $f4, $f16
/* 0545F0 7F01FAC0 E7A40054 */  swc1  $f4, 0x54($sp)
/* 0545F4 7F01FAC4 C6060000 */  lwc1  $f6, ($s0)
/* 0545F8 7F01FAC8 46064481 */  sub.s $f18, $f8, $f6
/* 0545FC 7F01FACC 46129282 */  mul.s $f10, $f18, $f18
/* 054600 7F01FAD0 E7B2005C */  swc1  $f18, 0x5c($sp)
/* 054604 7F01FAD4 46042402 */  mul.s $f16, $f4, $f4
/* 054608 7F01FAD8 0C007DF8 */  jal   sqrtf
/* 05460C 7F01FADC 46105300 */   add.s $f12, $f10, $f16
/* 054610 7F01FAE0 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 054614 7F01FAE4 44814000 */  mtc1  $at, $f8
/* 054618 7F01FAE8 C7A60054 */  lwc1  $f6, 0x54($sp)
/* 05461C 7F01FAEC C7A4005C */  lwc1  $f4, 0x5c($sp)
/* 054620 7F01FAF0 46004083 */  div.s $f2, $f8, $f0
/* 054624 7F01FAF4 C7B00068 */  lwc1  $f16, 0x68($sp)
/* 054628 7F01FAF8 8FB8009C */  lw    $t8, 0x9c($sp)
/* 05462C 7F01FAFC 2419001F */  li    $t9, 31
/* 054630 7F01FB00 27A40090 */  addiu $a0, $sp, 0x90
/* 054634 7F01FB04 46023482 */  mul.s $f18, $f6, $f2
/* 054638 7F01FB08 C7A60060 */  lwc1  $f6, 0x60($sp)
/* 05463C 7F01FB0C 46022282 */  mul.s $f10, $f4, $f2
/* 054640 7F01FB10 E7B20054 */  swc1  $f18, 0x54($sp)
/* 054644 7F01FB14 46105202 */  mul.s $f8, $f10, $f16
/* 054648 7F01FB18 E7AA005C */  swc1  $f10, 0x5c($sp)
/* 05464C 7F01FB1C 46123102 */  mul.s $f4, $f6, $f18
/* 054650 7F01FB20 C6060000 */  lwc1  $f6, ($s0)
/* 054654 7F01FB24 46044300 */  add.s $f12, $f8, $f4
/* 054658 7F01FB28 460C9402 */  mul.s $f16, $f18, $f12
/* 05465C 7F01FB2C 46068200 */  add.s $f8, $f16, $f6
/* 054660 7F01FB30 460C5102 */  mul.s $f4, $f10, $f12
/* 054664 7F01FB34 C7AA0088 */  lwc1  $f10, 0x88($sp)
/* 054668 7F01FB38 C7A6008C */  lwc1  $f6, 0x8c($sp)
/* 05466C 7F01FB3C E7A80040 */  swc1  $f8, 0x40($sp)
/* 054670 7F01FB40 C6120008 */  lwc1  $f18, 8($s0)
/* 054674 7F01FB44 AFB80090 */  sw    $t8, 0x90($sp)
/* 054678 7F01FB48 44074000 */  mfc1  $a3, $f8
/* 05467C 7F01FB4C 46122400 */  add.s $f16, $f4, $f18
/* 054680 7F01FB50 44819000 */  mtc1  $at, $f18
/* 054684 7F01FB54 44802000 */  mtc1  $zero, $f4
/* 054688 7F01FB58 E7B00048 */  swc1  $f16, 0x48($sp)
/* 05468C 7F01FB5C 8E060008 */  lw    $a2, 8($s0)
/* 054690 7F01FB60 8E050000 */  lw    $a1, ($s0)
/* 054694 7F01FB64 AFB90014 */  sw    $t9, 0x14($sp)
/* 054698 7F01FB68 E7B00010 */  swc1  $f16, 0x10($sp)
/* 05469C 7F01FB6C E7AA001C */  swc1  $f10, 0x1c($sp)
/* 0546A0 7F01FB70 E7A60018 */  swc1  $f6, 0x18($sp)
/* 0546A4 7F01FB74 E7B20024 */  swc1  $f18, 0x24($sp)
/* 0546A8 7F01FB78 0FC2C389 */  jal   sub_GAME_7F0B0E24
/* 0546AC 7F01FB7C E7A40020 */   swc1  $f4, 0x20($sp)
/* 0546B0 7F01FB80 10400015 */  beqz  $v0, .L7F01FBD8
/* 0546B4 7F01FB84 27A40090 */   addiu $a0, $sp, 0x90
/* 0546B8 7F01FB88 C7A8008C */  lwc1  $f8, 0x8c($sp)
/* 0546BC 7F01FB8C C7B00088 */  lwc1  $f16, 0x88($sp)
/* 0546C0 7F01FB90 2408001F */  li    $t0, 31
/* 0546C4 7F01FB94 AFA80010 */  sw    $t0, 0x10($sp)
/* 0546C8 7F01FB98 8FA50040 */  lw    $a1, 0x40($sp)
/* 0546CC 7F01FB9C 8FA60048 */  lw    $a2, 0x48($sp)
/* 0546D0 7F01FBA0 8FA70084 */  lw    $a3, 0x84($sp)
/* 0546D4 7F01FBA4 E7A80014 */  swc1  $f8, 0x14($sp)
/* 0546D8 7F01FBA8 0FC2C62E */  jal   sub_GAME_7F0B18B8
/* 0546DC 7F01FBAC E7B00018 */   swc1  $f16, 0x18($sp)
/* 0546E0 7F01FBB0 04410009 */  bgez  $v0, .L7F01FBD8
/* 0546E4 7F01FBB4 C7A60040 */   lwc1  $f6, 0x40($sp)
/* 0546E8 7F01FBB8 E6260000 */  swc1  $f6, ($s1)
/* 0546EC 7F01FBBC C7AA0048 */  lwc1  $f10, 0x48($sp)
/* 0546F0 7F01FBC0 240A0002 */  li    $t2, 2
/* 0546F4 7F01FBC4 E62A0008 */  swc1  $f10, 8($s1)
/* 0546F8 7F01FBC8 8FA90098 */  lw    $t1, 0x98($sp)
/* 0546FC 7F01FBCC A12A0009 */  sb    $t2, 9($t1)
/* 054700 7F01FBD0 8FAB0090 */  lw    $t3, 0x90($sp)
/* 054704 7F01FBD4 AFAB0094 */  sw    $t3, 0x94($sp)
.L7F01FBD8:
/* 054708 7F01FBD8 8FA40098 */  lw    $a0, 0x98($sp)
.L7F01FBDC:
/* 05470C 7F01FBDC 0FC07D7A */  jal   set_or_unset_GUARDdata_flag
/* 054710 7F01FBE0 24050001 */   li    $a1, 1
/* 054714 7F01FBE4 8FAC0094 */  lw    $t4, 0x94($sp)
/* 054718 7F01FBE8 8FAE0098 */  lw    $t6, 0x98($sp)
/* 05471C 7F01FBEC 15800002 */  bnez  $t4, .L7F01FBF8
/* 054720 7F01FBF0 240D0001 */   li    $t5, 1
/* 054724 7F01FBF4 A1CD0009 */  sb    $t5, 9($t6)
.L7F01FBF8:
/* 054728 7F01FBF8 8FBF0034 */  lw    $ra, 0x34($sp)
/* 05472C 7F01FBFC 8FA20094 */  lw    $v0, 0x94($sp)
/* 054730 7F01FC00 8FB0002C */  lw    $s0, 0x2c($sp)
/* 054734 7F01FC04 8FB10030 */  lw    $s1, 0x30($sp)
/* 054738 7F01FC08 03E00008 */  jr    $ra
/* 05473C 7F01FC0C 27BD0098 */   addiu $sp, $sp, 0x98
)
#endif



#ifdef NONMATCHING
void sub_GAME_7F01FC10(void) {

}
#else
#ifdef VERSION_US
GLOBAL_ASM(
.late_rodata
glabel D_80051D10
.word 0x3dccccd0 /*0.10000002*/
glabel D_80051D14
.word 0x3dccccd0 /*0.10000002*/
glabel D_80051D18
.word 0x3f666666 /*0.89999998*/
glabel D_80051D1C
.word 0x3dcccccd /*0.1*/
glabel D_80051D20
.word 0x3dccccd0 /*0.10000002*/
glabel D_80051D24
.word 0xbdcccccd /*-0.1*/

glabel D_80051D28
.word 0x40c90fdb /*6.2831855*/
glabel D_80051D2C
.word 0x40c90fdb /*6.2831855*/
glabel D_80051D30
.word 0x3f860a92 /*1.0471976*/
glabel D_80051D34
.word 0xbf5f66f3 /*-0.87266463*/
glabel D_80051D38
.word 0x3f5f66f3 /*0.87266463*/
glabel D_80051D3C
.word 0x3f860a92 /*1.0471976*/
glabel D_80051D40
.word 0xbf5f66f3 /*-0.87266463*/
glabel D_80051D44
.word 0x40c90fdb /*6.2831855*/
glabel D_80051D48
.word 0x40c90fdb /*6.2831855*/
glabel D_80051D4C
.word 0x40c90fdb /*6.2831855*/
glabel D_80051D50
.word 0x40c90fdb /*6.2831855*/
glabel D_80051D54
.word 0x40c90fdb /*6.2831855*/
glabel D_80051D58
.word 0x3ca3d70a /*0.02*/
glabel D_80051D5C
.word 0x3ca3d70a /*0.02*/
glabel D_80051D60
.word 0x3ca3d70a /*0.02*/
glabel D_80051D64
.word 0x3ca3d70a /*0.02*/
glabel D_80051D68
.word 0x3ca3d70a /*0.02*/
glabel D_80051D6C
.word 0x3ca3d70a /*0.02*/
glabel D_80051D70
.word 0x3f7eb852 /*0.995*/
glabel D_80051D74
.word 0x3f80a3d7 /*1.005*/
glabel D_80051D78
.word 0x3f7eb852 /*0.995*/
glabel D_80051D7C
.word 0x3f80a3d7 /*1.005*/
glabel D_80051D80
.word 0x3f7eb852 /*0.995*/
glabel D_80051D84
.word 0x3f80a3d7 /*1.005*/
glabel D_80051D88
.word 0x41aa6666 /*21.299999*/

.text
glabel sub_GAME_7F01FC10
/* 054740 7F01FC10 27BDFFC8 */  addiu $sp, $sp, -0x38
/* 054744 7F01FC14 AFBF0024 */  sw    $ra, 0x24($sp)
/* 054748 7F01FC18 AFB10020 */  sw    $s1, 0x20($sp)
/* 05474C 7F01FC1C AFB0001C */  sw    $s0, 0x1c($sp)
/* 054750 7F01FC20 AFA40038 */  sw    $a0, 0x38($sp)
/* 054754 7F01FC24 AFA5003C */  sw    $a1, 0x3c($sp)
/* 054758 7F01FC28 AFA70044 */  sw    $a3, 0x44($sp)
/* 05475C 7F01FC2C 8C900004 */  lw    $s0, 4($a0)
/* 054760 7F01FC30 AFA00030 */  sw    $zero, 0x30($sp)
/* 054764 7F01FC34 44806000 */  mtc1  $zero, $f12
/* 054768 7F01FC38 8E0F0018 */  lw    $t7, 0x18($s0)
/* 05476C 7F01FC3C 00C08825 */  move  $s1, $a2
/* 054770 7F01FC40 00A01825 */  move  $v1, $a1
/* 054774 7F01FC44 8DF80014 */  lw    $t8, 0x14($t7)
/* 054778 7F01FC48 46006386 */  mov.s $f14, $f12
/* 05477C 7F01FC4C 530000CC */  beql  $t8, $zero, .L7F01FF80
/* 054780 7F01FC50 8FAD0044 */   lw    $t5, 0x44($sp)
/* 054784 7F01FC54 82190007 */  lb    $t9, 7($s0)
/* 054788 7F01FC58 24010004 */  li    $at, 4
/* 05478C 7F01FC5C 1721002C */  bne   $t9, $at, .L7F01FD10
/* 054790 7F01FC60 00000000 */   nop   
/* 054794 7F01FC64 C6020038 */  lwc1  $f2, 0x38($s0)
/* 054798 7F01FC68 3C028005 */  lui   $v0, %hi(g_GlobalTimerDelta)
/* 05479C 7F01FC6C 24428378 */  addiu $v0, %lo(g_GlobalTimerDelta) # addiu $v0, $v0, -0x7c88
/* 0547A0 7F01FC70 4602603C */  c.lt.s $f12, $f2
/* 0547A4 7F01FC74 00000000 */  nop   
/* 0547A8 7F01FC78 45000025 */  bc1f  .L7F01FD10
/* 0547AC 7F01FC7C 00000000 */   nop   
/* 0547B0 7F01FC80 C48400A4 */  lwc1  $f4, 0xa4($a0)
/* 0547B4 7F01FC84 C4460000 */  lwc1  $f6, ($v0)
/* 0547B8 7F01FC88 C60A003C */  lwc1  $f10, 0x3c($s0)
/* 0547BC 7F01FC8C 46062202 */  mul.s $f8, $f4, $f6
/* 0547C0 7F01FC90 460A1481 */  sub.s $f18, $f2, $f10
/* 0547C4 7F01FC94 C60A0040 */  lwc1  $f10, 0x40($s0)
/* 0547C8 7F01FC98 C4C60000 */  lwc1  $f6, ($a2)
/* 0547CC 7F01FC9C 46124102 */  mul.s $f4, $f8, $f18
/* 0547D0 7F01FCA0 46022003 */  div.s $f0, $f4, $f2
/* 0547D4 7F01FCA4 C4C40004 */  lwc1  $f4, 4($a2)
/* 0547D8 7F01FCA8 46005202 */  mul.s $f8, $f10, $f0
/* 0547DC 7F01FCAC 46083480 */  add.s $f18, $f6, $f8
/* 0547E0 7F01FCB0 E4D20000 */  swc1  $f18, ($a2)
/* 0547E4 7F01FCB4 C60A0044 */  lwc1  $f10, 0x44($s0)
/* 0547E8 7F01FCB8 C4D20008 */  lwc1  $f18, 8($a2)
/* 0547EC 7F01FCBC 46005182 */  mul.s $f6, $f10, $f0
/* 0547F0 7F01FCC0 46062200 */  add.s $f8, $f4, $f6
/* 0547F4 7F01FCC4 E4C80004 */  swc1  $f8, 4($a2)
/* 0547F8 7F01FCC8 C60A0048 */  lwc1  $f10, 0x48($s0)
/* 0547FC 7F01FCCC 46005102 */  mul.s $f4, $f10, $f0
/* 054800 7F01FCD0 46049180 */  add.s $f6, $f18, $f4
/* 054804 7F01FCD4 E4C60008 */  swc1  $f6, 8($a2)
/* 054808 7F01FCD8 8FA80038 */  lw    $t0, 0x38($sp)
/* 05480C 7F01FCDC C4480000 */  lwc1  $f8, ($v0)
/* 054810 7F01FCE0 C604003C */  lwc1  $f4, 0x3c($s0)
/* 054814 7F01FCE4 C50A00A4 */  lwc1  $f10, 0xa4($t0)
/* 054818 7F01FCE8 460A4482 */  mul.s $f18, $f8, $f10
/* 05481C 7F01FCEC C6080038 */  lwc1  $f8, 0x38($s0)
/* 054820 7F01FCF0 46122180 */  add.s $f6, $f4, $f18
/* 054824 7F01FCF4 E606003C */  swc1  $f6, 0x3c($s0)
/* 054828 7F01FCF8 C60A003C */  lwc1  $f10, 0x3c($s0)
/* 05482C 7F01FCFC 460A403C */  c.lt.s $f8, $f10
/* 054830 7F01FD00 00000000 */  nop   
/* 054834 7F01FD04 45000002 */  bc1f  .L7F01FD10
/* 054838 7F01FD08 00000000 */   nop   
/* 05483C 7F01FD0C E60C0038 */  swc1  $f12, 0x38($s0)
.L7F01FD10:
/* 054840 7F01FD10 3C028005 */  lui   $v0, %hi(g_GlobalTimerDelta)
/* 054844 7F01FD14 24428378 */  addiu $v0, %lo(g_GlobalTimerDelta) # addiu $v0, $v0, -0x7c88
/* 054848 7F01FD18 C4520000 */  lwc1  $f18, ($v0)
/* 05484C 7F01FD1C C60400B0 */  lwc1  $f4, 0xb0($s0)
/* 054850 7F01FD20 C6280000 */  lwc1  $f8, ($s1)
/* 054854 7F01FD24 240A0001 */  li    $t2, 1
/* 054858 7F01FD28 46122182 */  mul.s $f6, $f4, $f18
/* 05485C 7F01FD2C 02002025 */  move  $a0, $s0
/* 054860 7F01FD30 02203825 */  move  $a3, $s1
/* 054864 7F01FD34 46064280 */  add.s $f10, $f8, $f6
/* 054868 7F01FD38 C6260008 */  lwc1  $f6, 8($s1)
/* 05486C 7F01FD3C E62A0000 */  swc1  $f10, ($s1)
/* 054870 7F01FD40 C4520000 */  lwc1  $f18, ($v0)
/* 054874 7F01FD44 C60400B8 */  lwc1  $f4, 0xb8($s0)
/* 054878 7F01FD48 46122202 */  mul.s $f8, $f4, $f18
/* 05487C 7F01FD4C 46083280 */  add.s $f10, $f6, $f8
/* 054880 7F01FD50 E62A0008 */  swc1  $f10, 8($s1)
/* 054884 7F01FD54 8E090018 */  lw    $t1, 0x18($s0)
/* 054888 7F01FD58 8FA6003C */  lw    $a2, 0x3c($sp)
/* 05488C 7F01FD5C 8D250014 */  lw    $a1, 0x14($t1)
/* 054890 7F01FD60 AFA30028 */  sw    $v1, 0x28($sp)
/* 054894 7F01FD64 0FC07D85 */  jal   sub_GAME_7F01F614
/* 054898 7F01FD68 AFAA0010 */   sw    $t2, 0x10($sp)
/* 05489C 7F01FD6C 10400006 */  beqz  $v0, .L7F01FD88
/* 0548A0 7F01FD70 8FA30028 */   lw    $v1, 0x28($sp)
/* 0548A4 7F01FD74 8E0B0018 */  lw    $t3, 0x18($s0)
/* 0548A8 7F01FD78 240C0001 */  li    $t4, 1
/* 0548AC 7F01FD7C 02201825 */  move  $v1, $s1
/* 0548B0 7F01FD80 AD620014 */  sw    $v0, 0x14($t3)
/* 0548B4 7F01FD84 AFAC0030 */  sw    $t4, 0x30($sp)
.L7F01FD88:
/* 0548B8 7F01FD88 8E0D0014 */  lw    $t5, 0x14($s0)
/* 0548BC 7F01FD8C 31AF1000 */  andi  $t7, $t5, 0x1000
/* 0548C0 7F01FD90 55E0007A */  bnezl $t7, .L7F01FF7C
/* 0548C4 7F01FD94 C60E00AC */   lwc1  $f14, 0xac($s0)
/* 0548C8 7F01FD98 8E180018 */  lw    $t8, 0x18($s0)
/* 0548CC 7F01FD9C 8C650000 */  lw    $a1, ($v1)
/* 0548D0 7F01FDA0 8C660008 */  lw    $a2, 8($v1)
/* 0548D4 7F01FDA4 0FC2CA5C */  jal   stanGetPositionYValue
/* 0548D8 7F01FDA8 8F040014 */   lw    $a0, 0x14($t8)
/* 0548DC 7F01FDAC 8E190014 */  lw    $t9, 0x14($s0)
/* 0548E0 7F01FDB0 44806000 */  mtc1  $zero, $f12
/* 0548E4 7F01FDB4 46000386 */  mov.s $f14, $f0
/* 0548E8 7F01FDB8 332E0001 */  andi  $t6, $t9, 1
/* 0548EC 7F01FDBC 11C00014 */  beqz  $t6, .L7F01FE10
/* 0548F0 7F01FDC0 E60000AC */   swc1  $f0, 0xac($s0)
/* 0548F4 7F01FDC4 8FA40038 */  lw    $a0, 0x38($sp)
/* 0548F8 7F01FDC8 8C880008 */  lw    $t0, 8($a0)
/* 0548FC 7F01FDCC 8D050000 */  lw    $a1, ($t0)
/* 054900 7F01FDD0 0FC1B1E7 */  jal   extract_id_from_object_structure_microcode
/* 054904 7F01FDD4 E7AE002C */   swc1  $f14, 0x2c($sp)
/* 054908 7F01FDD8 8E090014 */  lw    $t1, 0x14($s0)
/* 05490C 7F01FDDC C60200AC */  lwc1  $f2, 0xac($s0)
/* 054910 7F01FDE0 2401FFFE */  li    $at, -2
/* 054914 7F01FDE4 C7AE002C */  lwc1  $f14, 0x2c($sp)
/* 054918 7F01FDE8 01215024 */  and   $t2, $t1, $at
/* 05491C 7F01FDEC AE0A0014 */  sw    $t2, 0x14($s0)
/* 054920 7F01FDF0 3C018005 */  lui   $at, %hi(D_80051D10)
/* 054924 7F01FDF4 E60200A8 */  swc1  $f2, 0xa8($s0)
/* 054928 7F01FDF8 C4241D10 */  lwc1  $f4, %lo(D_80051D10)($at)
/* 05492C 7F01FDFC 46041483 */  div.s $f18, $f2, $f4
/* 054930 7F01FE00 E61200A4 */  swc1  $f18, 0xa4($s0)
/* 054934 7F01FE04 C4460028 */  lwc1  $f6, 0x28($v0)
/* 054938 7F01FE08 10000055 */  b     .L7F01FF60
/* 05493C 7F01FE0C E4460038 */   swc1  $f6, 0x38($v0)
.L7F01FE10:
/* 054940 7F01FE10 C60800B4 */  lwc1  $f8, 0xb4($s0)
/* 054944 7F01FE14 260400A8 */  addiu $a0, $s0, 0xa8
/* 054948 7F01FE18 260500B4 */  addiu $a1, $s0, 0xb4
/* 05494C 7F01FE1C 46086032 */  c.eq.s $f12, $f8
/* 054950 7F01FE20 3C068005 */  lui   $a2, %hi(g_GlobalTimerDelta)
/* 054954 7F01FE24 45000007 */  bc1f  .L7F01FE44
/* 054958 7F01FE28 00000000 */   nop   
/* 05495C 7F01FE2C C60200AC */  lwc1  $f2, 0xac($s0)
/* 054960 7F01FE30 C60000A8 */  lwc1  $f0, 0xa8($s0)
/* 054964 7F01FE34 4600103C */  c.lt.s $f2, $f0
/* 054968 7F01FE38 00000000 */  nop   
/* 05496C 7F01FE3C 45020013 */  bc1fl .L7F01FE8C
/* 054970 7F01FE40 4602003E */   c.le.s $f0, $f2
.L7F01FE44:
/* 054974 7F01FE44 8CC68378 */  lw    $a2, %lo(g_GlobalTimerDelta)($a2)
/* 054978 7F01FE48 0FC15F51 */  jal   sub_GAME_7F057D44
/* 05497C 7F01FE4C E7AE002C */   swc1  $f14, 0x2c($sp)
/* 054980 7F01FE50 C60200AC */  lwc1  $f2, 0xac($s0)
/* 054984 7F01FE54 C60000A8 */  lwc1  $f0, 0xa8($s0)
/* 054988 7F01FE58 44806000 */  mtc1  $zero, $f12
/* 05498C 7F01FE5C C7AE002C */  lwc1  $f14, 0x2c($sp)
/* 054990 7F01FE60 4602003E */  c.le.s $f0, $f2
/* 054994 7F01FE64 3C018005 */  lui   $at, %hi(D_80051D14)
/* 054998 7F01FE68 45020008 */  bc1fl .L7F01FE8C
/* 05499C 7F01FE6C 4602003E */   c.le.s $f0, $f2
/* 0549A0 7F01FE70 E60200A8 */  swc1  $f2, 0xa8($s0)
/* 0549A4 7F01FE74 C42A1D14 */  lwc1  $f10, %lo(D_80051D14)($at)
/* 0549A8 7F01FE78 E60C00B4 */  swc1  $f12, 0xb4($s0)
/* 0549AC 7F01FE7C C60000A8 */  lwc1  $f0, 0xa8($s0)
/* 0549B0 7F01FE80 460A1103 */  div.s $f4, $f2, $f10
/* 0549B4 7F01FE84 E60400A4 */  swc1  $f4, 0xa4($s0)
/* 0549B8 7F01FE88 4602003E */  c.le.s $f0, $f2
.L7F01FE8C:
/* 0549BC 7F01FE8C 3C038005 */  lui   $v1, %hi(g_ClockTimer)
/* 0549C0 7F01FE90 24638374 */  addiu $v1, %lo(g_ClockTimer) # addiu $v1, $v1, -0x7c8c
/* 0549C4 7F01FE94 45020033 */  bc1fl .L7F01FF64
/* 0549C8 7F01FE98 C60600A8 */   lwc1  $f6, 0xa8($s0)
/* 0549CC 7F01FE9C 8C6B0000 */  lw    $t3, ($v1)
/* 0549D0 7F01FEA0 00001025 */  move  $v0, $zero
/* 0549D4 7F01FEA4 3C018005 */  lui   $at, %hi(D_80051D18)
/* 0549D8 7F01FEA8 19600011 */  blez  $t3, .L7F01FEF0
/* 0549DC 7F01FEAC 00000000 */   nop   
/* 0549E0 7F01FEB0 C4201D18 */  lwc1  $f0, %lo(D_80051D18)($at)
/* 0549E4 7F01FEB4 C61200A4 */  lwc1  $f18, 0xa4($s0)
.L7F01FEB8:
/* 0549E8 7F01FEB8 C60A00B0 */  lwc1  $f10, 0xb0($s0)
/* 0549EC 7F01FEBC 24420001 */  addiu $v0, $v0, 1
/* 0549F0 7F01FEC0 46009182 */  mul.s $f6, $f18, $f0
/* 0549F4 7F01FEC4 C61200B8 */  lwc1  $f18, 0xb8($s0)
/* 0549F8 7F01FEC8 46005102 */  mul.s $f4, $f10, $f0
/* 0549FC 7F01FECC 46023200 */  add.s $f8, $f6, $f2
/* 054A00 7F01FED0 46009182 */  mul.s $f6, $f18, $f0
/* 054A04 7F01FED4 E60400B0 */  swc1  $f4, 0xb0($s0)
/* 054A08 7F01FED8 E60800A4 */  swc1  $f8, 0xa4($s0)
/* 054A0C 7F01FEDC E60600B8 */  swc1  $f6, 0xb8($s0)
/* 054A10 7F01FEE0 8C6C0000 */  lw    $t4, ($v1)
/* 054A14 7F01FEE4 004C082A */  slt   $at, $v0, $t4
/* 054A18 7F01FEE8 5420FFF3 */  bnezl $at, .L7F01FEB8
/* 054A1C 7F01FEEC C61200A4 */   lwc1  $f18, 0xa4($s0)
.L7F01FEF0:
/* 054A20 7F01FEF0 3C018005 */  lui   $at, %hi(D_80051D1C)
/* 054A24 7F01FEF4 C4221D1C */  lwc1  $f2, %lo(D_80051D1C)($at)
/* 054A28 7F01FEF8 3C018005 */  lui   $at, %hi(D_80051D20)
/* 054A2C 7F01FEFC C42A1D20 */  lwc1  $f10, %lo(D_80051D20)($at)
/* 054A30 7F01FF00 C60800A4 */  lwc1  $f8, 0xa4($s0)
/* 054A34 7F01FF04 C60000B0 */  lwc1  $f0, 0xb0($s0)
/* 054A38 7F01FF08 3C018005 */  lui   $at, %hi(D_80051D24)
/* 054A3C 7F01FF0C 460A4102 */  mul.s $f4, $f8, $f10
/* 054A40 7F01FF10 4602003C */  c.lt.s $f0, $f2
/* 054A44 7F01FF14 00000000 */  nop   
/* 054A48 7F01FF18 45000011 */  bc1f  .L7F01FF60
/* 054A4C 7F01FF1C E60400A8 */   swc1  $f4, 0xa8($s0)
/* 054A50 7F01FF20 C4301D24 */  lwc1  $f16, %lo(D_80051D24)($at)
/* 054A54 7F01FF24 4600803C */  c.lt.s $f16, $f0
/* 054A58 7F01FF28 00000000 */  nop   
/* 054A5C 7F01FF2C 4502000D */  bc1fl .L7F01FF64
/* 054A60 7F01FF30 C60600A8 */   lwc1  $f6, 0xa8($s0)
/* 054A64 7F01FF34 C60000B8 */  lwc1  $f0, 0xb8($s0)
/* 054A68 7F01FF38 4602003C */  c.lt.s $f0, $f2
/* 054A6C 7F01FF3C 00000000 */  nop   
/* 054A70 7F01FF40 45020008 */  bc1fl .L7F01FF64
/* 054A74 7F01FF44 C60600A8 */   lwc1  $f6, 0xa8($s0)
/* 054A78 7F01FF48 4600803C */  c.lt.s $f16, $f0
/* 054A7C 7F01FF4C 00000000 */  nop   
/* 054A80 7F01FF50 45020004 */  bc1fl .L7F01FF64
/* 054A84 7F01FF54 C60600A8 */   lwc1  $f6, 0xa8($s0)
/* 054A88 7F01FF58 E60C00B8 */  swc1  $f12, 0xb8($s0)
/* 054A8C 7F01FF5C E60C00B0 */  swc1  $f12, 0xb0($s0)
.L7F01FF60:
/* 054A90 7F01FF60 C60600A8 */  lwc1  $f6, 0xa8($s0)
.L7F01FF64:
/* 054A94 7F01FF64 C6320004 */  lwc1  $f18, 4($s1)
/* 054A98 7F01FF68 460E3201 */  sub.s $f8, $f6, $f14
/* 054A9C 7F01FF6C 46089280 */  add.s $f10, $f18, $f8
/* 054AA0 7F01FF70 10000002 */  b     .L7F01FF7C
/* 054AA4 7F01FF74 E62A0004 */   swc1  $f10, 4($s1)
/* 054AA8 7F01FF78 C60E00AC */  lwc1  $f14, 0xac($s0)
.L7F01FF7C:
/* 054AAC 7F01FF7C 8FAD0044 */  lw    $t5, 0x44($sp)
.L7F01FF80:
/* 054AB0 7F01FF80 24020001 */  li    $v0, 1
/* 054AB4 7F01FF84 E5AE0000 */  swc1  $f14, ($t5)
/* 054AB8 7F01FF88 8FAF0030 */  lw    $t7, 0x30($sp)
/* 054ABC 7F01FF8C 8FB8003C */  lw    $t8, 0x3c($sp)
/* 054AC0 7F01FF90 55E00007 */  bnezl $t7, .L7F01FFB0
/* 054AC4 7F01FF94 8FBF0024 */   lw    $ra, 0x24($sp)
/* 054AC8 7F01FF98 C7040000 */  lwc1  $f4, ($t8)
/* 054ACC 7F01FF9C E6240000 */  swc1  $f4, ($s1)
/* 054AD0 7F01FFA0 8FB9003C */  lw    $t9, 0x3c($sp)
/* 054AD4 7F01FFA4 C7260008 */  lwc1  $f6, 8($t9)
/* 054AD8 7F01FFA8 E6260008 */  swc1  $f6, 8($s1)
/* 054ADC 7F01FFAC 8FBF0024 */  lw    $ra, 0x24($sp)
.L7F01FFB0:
/* 054AE0 7F01FFB0 8FB0001C */  lw    $s0, 0x1c($sp)
/* 054AE4 7F01FFB4 8FB10020 */  lw    $s1, 0x20($sp)
/* 054AE8 7F01FFB8 03E00008 */  jr    $ra
/* 054AEC 7F01FFBC 27BD0038 */   addiu $sp, $sp, 0x38
)
#endif
#ifdef VERSION_JP
GLOBAL_ASM(
.late_rodata
glabel D_80051D10
.word 0x3dccccd0 /*0.10000002*/
glabel D_80051D14
.word 0x3dccccd0 /*0.10000002*/
glabel D_80051D18
.word 0x3f666666 /*0.89999998*/
glabel D_80051D1C
.word 0x3dcccccd /*0.1*/
glabel D_80051D20
.word 0x3dccccd0 /*0.10000002*/
glabel D_80051D24
.word 0xbdcccccd /*-0.1*/
glabel D_80051D28
.word 0x40c90fdb /*6.2831855*/
glabel D_80051D2C
.word 0x40c90fdb /*6.2831855*/
glabel D_80051D30
.word 0x3f860a92 /*1.0471976*/
glabel D_80051D34
.word 0xbf5f66f3 /*-0.87266463*/
glabel D_80051D38
.word 0x3f5f66f3 /*0.87266463*/
glabel D_80051D3C
.word 0x3f860a92 /*1.0471976*/
glabel D_80051D40
.word 0xbf5f66f3 /*-0.87266463*/
glabel D_80051D44
.word 0x40c90fdb /*6.2831855*/
glabel D_80051D48
.word 0x40c90fdb /*6.2831855*/
glabel D_80051D4C
.word 0x40c90fdb /*6.2831855*/
glabel D_80051D50
.word 0x40c90fdb /*6.2831855*/
glabel D_80051D54
.word 0x40c90fdb /*6.2831855*/

glabel D_jp80051D88
.word 0x3f4ccccd

glabel D_80051D58
.word 0x3ca3d70a /*0.02*/
glabel D_80051D5C
.word 0x3ca3d70a /*0.02*/
glabel D_80051D60
.word 0x3ca3d70a /*0.02*/
glabel D_80051D64
.word 0x3ca3d70a /*0.02*/
glabel D_80051D68
.word 0x3ca3d70a /*0.02*/
glabel D_80051D6C
.word 0x3ca3d70a /*0.02*/
glabel D_80051D70
.word 0x3f7eb852 /*0.995*/
glabel D_80051D74
.word 0x3f80a3d7 /*1.005*/
glabel D_80051D78
.word 0x3f7eb852 /*0.995*/
glabel D_80051D7C
.word 0x3f80a3d7 /*1.005*/
glabel D_80051D80
.word 0x3f7eb852 /*0.995*/
glabel D_80051D84
.word 0x3f80a3d7 /*1.005*/
glabel D_80051D88
.word 0x41aa6666 /*21.299999*/

/*.word 0x0*/
.text
glabel sub_GAME_7F01FC10
/* 054740 7F01FC10 27BDFFC8 */  addiu $sp, $sp, -0x38
/* 054744 7F01FC14 AFBF0024 */  sw    $ra, 0x24($sp)
/* 054748 7F01FC18 AFB10020 */  sw    $s1, 0x20($sp)
/* 05474C 7F01FC1C AFB0001C */  sw    $s0, 0x1c($sp)
/* 054750 7F01FC20 AFA40038 */  sw    $a0, 0x38($sp)
/* 054754 7F01FC24 AFA5003C */  sw    $a1, 0x3c($sp)
/* 054758 7F01FC28 AFA70044 */  sw    $a3, 0x44($sp)
/* 05475C 7F01FC2C 8C900004 */  lw    $s0, 4($a0)
/* 054760 7F01FC30 AFA00030 */  sw    $zero, 0x30($sp)
/* 054764 7F01FC34 44806000 */  mtc1  $zero, $f12
/* 054768 7F01FC38 8E0F0018 */  lw    $t7, 0x18($s0)
/* 05476C 7F01FC3C 00C08825 */  move  $s1, $a2
/* 054770 7F01FC40 00A01825 */  move  $v1, $a1
/* 054774 7F01FC44 8DF80014 */  lw    $t8, 0x14($t7)
/* 054778 7F01FC48 46006386 */  mov.s $f14, $f12
/* 05477C 7F01FC4C 530000CC */  beql  $t8, $zero, .L7F01FF80
/* 054780 7F01FC50 8FAD0044 */   lw    $t5, 0x44($sp)
/* 054784 7F01FC54 82190007 */  lb    $t9, 7($s0)
/* 054788 7F01FC58 24010004 */  li    $at, 4
/* 05478C 7F01FC5C 1721002C */  bne   $t9, $at, .L7F01FD10
/* 054790 7F01FC60 00000000 */   nop   
/* 054794 7F01FC64 C6020038 */  lwc1  $f2, 0x38($s0)
/* 054798 7F01FC68 3C028005 */  lui   $v0, %hi(g_JP_GlobalTimerDelta)
/* 05479C 7F01FC6C 24428378 */  addiu $v0, %lo(g_JP_GlobalTimerDelta) # addiu $v0, $v0, -0x7c88
/* 0547A0 7F01FC70 4602603C */  c.lt.s $f12, $f2
/* 0547A4 7F01FC74 00000000 */  nop   
/* 0547A8 7F01FC78 45000025 */  bc1f  .L7F01FD10
/* 0547AC 7F01FC7C 00000000 */   nop   
/* 0547B0 7F01FC80 C48400A4 */  lwc1  $f4, 0xa4($a0)
/* 0547B4 7F01FC84 C4460000 */  lwc1  $f6, ($v0)
/* 0547B8 7F01FC88 C60A003C */  lwc1  $f10, 0x3c($s0)
/* 0547BC 7F01FC8C 46062202 */  mul.s $f8, $f4, $f6
/* 0547C0 7F01FC90 460A1481 */  sub.s $f18, $f2, $f10
/* 0547C4 7F01FC94 C60A0040 */  lwc1  $f10, 0x40($s0)
/* 0547C8 7F01FC98 C4C60000 */  lwc1  $f6, ($a2)
/* 0547CC 7F01FC9C 46124102 */  mul.s $f4, $f8, $f18
/* 0547D0 7F01FCA0 46022003 */  div.s $f0, $f4, $f2
/* 0547D4 7F01FCA4 C4C40004 */  lwc1  $f4, 4($a2)
/* 0547D8 7F01FCA8 46005202 */  mul.s $f8, $f10, $f0
/* 0547DC 7F01FCAC 46083480 */  add.s $f18, $f6, $f8
/* 0547E0 7F01FCB0 E4D20000 */  swc1  $f18, ($a2)
/* 0547E4 7F01FCB4 C60A0044 */  lwc1  $f10, 0x44($s0)
/* 0547E8 7F01FCB8 C4D20008 */  lwc1  $f18, 8($a2)
/* 0547EC 7F01FCBC 46005182 */  mul.s $f6, $f10, $f0
/* 0547F0 7F01FCC0 46062200 */  add.s $f8, $f4, $f6
/* 0547F4 7F01FCC4 E4C80004 */  swc1  $f8, 4($a2)
/* 0547F8 7F01FCC8 C60A0048 */  lwc1  $f10, 0x48($s0)
/* 0547FC 7F01FCCC 46005102 */  mul.s $f4, $f10, $f0
/* 054800 7F01FCD0 46049180 */  add.s $f6, $f18, $f4
/* 054804 7F01FCD4 E4C60008 */  swc1  $f6, 8($a2)
/* 054808 7F01FCD8 8FA80038 */  lw    $t0, 0x38($sp)
/* 05480C 7F01FCDC C4480000 */  lwc1  $f8, ($v0)
/* 054810 7F01FCE0 C604003C */  lwc1  $f4, 0x3c($s0)
/* 054814 7F01FCE4 C50A00A4 */  lwc1  $f10, 0xa4($t0)
/* 054818 7F01FCE8 460A4482 */  mul.s $f18, $f8, $f10
/* 05481C 7F01FCEC C6080038 */  lwc1  $f8, 0x38($s0)
/* 054820 7F01FCF0 46122180 */  add.s $f6, $f4, $f18
/* 054824 7F01FCF4 E606003C */  swc1  $f6, 0x3c($s0)
/* 054828 7F01FCF8 C60A003C */  lwc1  $f10, 0x3c($s0)
/* 05482C 7F01FCFC 460A403C */  c.lt.s $f8, $f10
/* 054830 7F01FD00 00000000 */  nop   
/* 054834 7F01FD04 45000002 */  bc1f  .L7F01FD10
/* 054838 7F01FD08 00000000 */   nop   
/* 05483C 7F01FD0C E60C0038 */  swc1  $f12, 0x38($s0)
.L7F01FD10:
/* 054840 7F01FD10 3C028005 */  lui   $v0, %hi(g_GlobalTimerDelta)
/* 054844 7F01FD14 24428378 */  addiu $v0, %lo(g_GlobalTimerDelta) # addiu $v0, $v0, -0x7c88
/* 054848 7F01FD18 C4520000 */  lwc1  $f18, ($v0)
/* 05484C 7F01FD1C C60400B0 */  lwc1  $f4, 0xb0($s0)
/* 054850 7F01FD20 C6280000 */  lwc1  $f8, ($s1)
/* 054854 7F01FD24 240A0001 */  li    $t2, 1
/* 054858 7F01FD28 46122182 */  mul.s $f6, $f4, $f18
/* 05485C 7F01FD2C 02002025 */  move  $a0, $s0
/* 054860 7F01FD30 02203825 */  move  $a3, $s1
/* 054864 7F01FD34 46064280 */  add.s $f10, $f8, $f6
/* 054868 7F01FD38 C6260008 */  lwc1  $f6, 8($s1)
/* 05486C 7F01FD3C E62A0000 */  swc1  $f10, ($s1)
/* 054870 7F01FD40 C4520000 */  lwc1  $f18, ($v0)
/* 054874 7F01FD44 C60400B8 */  lwc1  $f4, 0xb8($s0)
/* 054878 7F01FD48 46122202 */  mul.s $f8, $f4, $f18
/* 05487C 7F01FD4C 46083280 */  add.s $f10, $f6, $f8
/* 054880 7F01FD50 E62A0008 */  swc1  $f10, 8($s1)
/* 054884 7F01FD54 8E090018 */  lw    $t1, 0x18($s0)
/* 054888 7F01FD58 8FA6003C */  lw    $a2, 0x3c($sp)
/* 05488C 7F01FD5C 8D250014 */  lw    $a1, 0x14($t1)
/* 054890 7F01FD60 AFA30028 */  sw    $v1, 0x28($sp)
/* 054894 7F01FD64 0FC07D85 */  jal   sub_GAME_7F01F614
/* 054898 7F01FD68 AFAA0010 */   sw    $t2, 0x10($sp)
/* 05489C 7F01FD6C 10400006 */  beqz  $v0, .L7F01FD88
/* 0548A0 7F01FD70 8FA30028 */   lw    $v1, 0x28($sp)
/* 0548A4 7F01FD74 8E0B0018 */  lw    $t3, 0x18($s0)
/* 0548A8 7F01FD78 240C0001 */  li    $t4, 1
/* 0548AC 7F01FD7C 02201825 */  move  $v1, $s1
/* 0548B0 7F01FD80 AD620014 */  sw    $v0, 0x14($t3)
/* 0548B4 7F01FD84 AFAC0030 */  sw    $t4, 0x30($sp)
.L7F01FD88:
/* 0548B8 7F01FD88 8E0D0014 */  lw    $t5, 0x14($s0)
/* 0548BC 7F01FD8C 31AF1000 */  andi  $t7, $t5, 0x1000
/* 0548C0 7F01FD90 55E0007A */  bnezl $t7, .L7F01FF7C
/* 0548C4 7F01FD94 C60E00AC */   lwc1  $f14, 0xac($s0)
/* 0548C8 7F01FD98 8E180018 */  lw    $t8, 0x18($s0)
/* 0548CC 7F01FD9C 8C650000 */  lw    $a1, ($v1)
/* 0548D0 7F01FDA0 8C660008 */  lw    $a2, 8($v1)
/* 0548D4 7F01FDA4 0FC2CA5C */  jal   stanGetPositionYValue
/* 0548D8 7F01FDA8 8F040014 */   lw    $a0, 0x14($t8)
/* 0548DC 7F01FDAC 8E190014 */  lw    $t9, 0x14($s0)
/* 0548E0 7F01FDB0 44806000 */  mtc1  $zero, $f12
/* 0548E4 7F01FDB4 46000386 */  mov.s $f14, $f0
/* 0548E8 7F01FDB8 332E0001 */  andi  $t6, $t9, 1
/* 0548EC 7F01FDBC 11C00014 */  beqz  $t6, .L7F01FE10
/* 0548F0 7F01FDC0 E60000AC */   swc1  $f0, 0xac($s0)
/* 0548F4 7F01FDC4 8FA40038 */  lw    $a0, 0x38($sp)
/* 0548F8 7F01FDC8 8C880008 */  lw    $t0, 8($a0)
/* 0548FC 7F01FDCC 8D050000 */  lw    $a1, ($t0)
/* 054900 7F01FDD0 0FC1B1E7 */  jal   extract_id_from_object_structure_microcode
/* 054904 7F01FDD4 E7AE002C */   swc1  $f14, 0x2c($sp)
/* 054908 7F01FDD8 8E090014 */  lw    $t1, 0x14($s0)
/* 05490C 7F01FDDC C60200AC */  lwc1  $f2, 0xac($s0)
/* 054910 7F01FDE0 2401FFFE */  li    $at, -2
/* 054914 7F01FDE4 C7AE002C */  lwc1  $f14, 0x2c($sp)
/* 054918 7F01FDE8 01215024 */  and   $t2, $t1, $at
/* 05491C 7F01FDEC AE0A0014 */  sw    $t2, 0x14($s0)
/* 054920 7F01FDF0 3C018005 */  lui   $at, %hi(D_80051D10)
/* 054924 7F01FDF4 E60200A8 */  swc1  $f2, 0xa8($s0)
/* 054928 7F01FDF8 C4241D10 */  lwc1  $f4, %lo(D_80051D10)($at)
/* 05492C 7F01FDFC 46041483 */  div.s $f18, $f2, $f4
/* 054930 7F01FE00 E61200A4 */  swc1  $f18, 0xa4($s0)
/* 054934 7F01FE04 C4460028 */  lwc1  $f6, 0x28($v0)
/* 054938 7F01FE08 10000055 */  b     .L7F01FF60
/* 05493C 7F01FE0C E4460038 */   swc1  $f6, 0x38($v0)
.L7F01FE10:
/* 054940 7F01FE10 C60800B4 */  lwc1  $f8, 0xb4($s0)
/* 054944 7F01FE14 260400A8 */  addiu $a0, $s0, 0xa8
/* 054948 7F01FE18 260500B4 */  addiu $a1, $s0, 0xb4
/* 05494C 7F01FE1C 46086032 */  c.eq.s $f12, $f8
/* 054950 7F01FE20 3C068005 */  lui   $a2, %hi(g_GlobalTimerDelta)
/* 054954 7F01FE24 45000007 */  bc1f  .L7F01FE44
/* 054958 7F01FE28 00000000 */   nop   
/* 05495C 7F01FE2C C60200AC */  lwc1  $f2, 0xac($s0)
/* 054960 7F01FE30 C60000A8 */  lwc1  $f0, 0xa8($s0)
/* 054964 7F01FE34 4600103C */  c.lt.s $f2, $f0
/* 054968 7F01FE38 00000000 */  nop   
/* 05496C 7F01FE3C 45020013 */  bc1fl .L7F01FE8C
/* 054970 7F01FE40 4602003E */   c.le.s $f0, $f2
.L7F01FE44:
/* 054974 7F01FE44 8CC68378 */  lw    $a2, %lo(g_GlobalTimerDelta)($a2)
/* 054978 7F01FE48 0FC15F51 */  jal   sub_GAME_7F057D44
/* 05497C 7F01FE4C E7AE002C */   swc1  $f14, 0x2c($sp)
/* 054980 7F01FE50 C60200AC */  lwc1  $f2, 0xac($s0)
/* 054984 7F01FE54 C60000A8 */  lwc1  $f0, 0xa8($s0)
/* 054988 7F01FE58 44806000 */  mtc1  $zero, $f12
/* 05498C 7F01FE5C C7AE002C */  lwc1  $f14, 0x2c($sp)
/* 054990 7F01FE60 4602003E */  c.le.s $f0, $f2
/* 054994 7F01FE64 3C018005 */  lui   $at, %hi(D_80051D14)
/* 054998 7F01FE68 45020008 */  bc1fl .L7F01FE8C
/* 05499C 7F01FE6C 4602003E */   c.le.s $f0, $f2
/* 0549A0 7F01FE70 E60200A8 */  swc1  $f2, 0xa8($s0)
/* 0549A4 7F01FE74 C42A1D14 */  lwc1  $f10, %lo(D_80051D14)($at)
/* 0549A8 7F01FE78 E60C00B4 */  swc1  $f12, 0xb4($s0)
/* 0549AC 7F01FE7C C60000A8 */  lwc1  $f0, 0xa8($s0)
/* 0549B0 7F01FE80 460A1103 */  div.s $f4, $f2, $f10
/* 0549B4 7F01FE84 E60400A4 */  swc1  $f4, 0xa4($s0)
/* 0549B8 7F01FE88 4602003E */  c.le.s $f0, $f2
.L7F01FE8C:
/* 0549BC 7F01FE8C 3C038005 */  lui   $v1, %hi(g_ClockTimer)
/* 0549C0 7F01FE90 24638374 */  addiu $v1, %lo(g_ClockTimer) # addiu $v1, $v1, -0x7c8c
/* 0549C4 7F01FE94 45020033 */  bc1fl .L7F01FF64
/* 0549C8 7F01FE98 C60600A8 */   lwc1  $f6, 0xa8($s0)
/* 0549CC 7F01FE9C 8C6B0000 */  lw    $t3, ($v1)
/* 0549D0 7F01FEA0 00001025 */  move  $v0, $zero
/* 0549D4 7F01FEA4 3C018005 */  lui   $at, %hi(D_80051D18)
/* 0549D8 7F01FEA8 19600011 */  blez  $t3, .L7F01FEF0
/* 0549DC 7F01FEAC 00000000 */   nop   
/* 0549E0 7F01FEB0 C4201D18 */  lwc1  $f0, %lo(D_80051D18)($at)
/* 0549E4 7F01FEB4 C61200A4 */  lwc1  $f18, 0xa4($s0)
.L7F01FEB8:
/* 0549E8 7F01FEB8 C60A00B0 */  lwc1  $f10, 0xb0($s0)
/* 0549EC 7F01FEBC 24420001 */  addiu $v0, $v0, 1
/* 0549F0 7F01FEC0 46009182 */  mul.s $f6, $f18, $f0
/* 0549F4 7F01FEC4 C61200B8 */  lwc1  $f18, 0xb8($s0)
/* 0549F8 7F01FEC8 46005102 */  mul.s $f4, $f10, $f0
/* 0549FC 7F01FECC 46023200 */  add.s $f8, $f6, $f2
/* 054A00 7F01FED0 46009182 */  mul.s $f6, $f18, $f0
/* 054A04 7F01FED4 E60400B0 */  swc1  $f4, 0xb0($s0)
/* 054A08 7F01FED8 E60800A4 */  swc1  $f8, 0xa4($s0)
/* 054A0C 7F01FEDC E60600B8 */  swc1  $f6, 0xb8($s0)
/* 054A10 7F01FEE0 8C6C0000 */  lw    $t4, ($v1)
/* 054A14 7F01FEE4 004C082A */  slt   $at, $v0, $t4
/* 054A18 7F01FEE8 5420FFF3 */  bnezl $at, .L7F01FEB8
/* 054A1C 7F01FEEC C61200A4 */   lwc1  $f18, 0xa4($s0)
.L7F01FEF0:
/* 054A20 7F01FEF0 3C018005 */  lui   $at, %hi(D_80051D1C)
/* 054A24 7F01FEF4 C4221D1C */  lwc1  $f2, %lo(D_80051D1C)($at)
/* 054A28 7F01FEF8 3C018005 */  lui   $at, %hi(D_80051D20)
/* 054A2C 7F01FEFC C42A1D20 */  lwc1  $f10, %lo(D_80051D20)($at)
/* 054A30 7F01FF00 C60800A4 */  lwc1  $f8, 0xa4($s0)
/* 054A34 7F01FF04 C60000B0 */  lwc1  $f0, 0xb0($s0)
/* 054A38 7F01FF08 3C018005 */  lui   $at, %hi(D_80051D24)
/* 054A3C 7F01FF0C 460A4102 */  mul.s $f4, $f8, $f10
/* 054A40 7F01FF10 4602003C */  c.lt.s $f0, $f2
/* 054A44 7F01FF14 00000000 */  nop   
/* 054A48 7F01FF18 45000011 */  bc1f  .L7F01FF60
/* 054A4C 7F01FF1C E60400A8 */   swc1  $f4, 0xa8($s0)
/* 054A50 7F01FF20 C4301D24 */  lwc1  $f16, %lo(D_80051D24)($at)
/* 054A54 7F01FF24 4600803C */  c.lt.s $f16, $f0
/* 054A58 7F01FF28 00000000 */  nop   
/* 054A5C 7F01FF2C 4502000D */  bc1fl .L7F01FF64
/* 054A60 7F01FF30 C60600A8 */   lwc1  $f6, 0xa8($s0)
/* 054A64 7F01FF34 C60000B8 */  lwc1  $f0, 0xb8($s0)
/* 054A68 7F01FF38 4602003C */  c.lt.s $f0, $f2
/* 054A6C 7F01FF3C 00000000 */  nop   
/* 054A70 7F01FF40 45020008 */  bc1fl .L7F01FF64
/* 054A74 7F01FF44 C60600A8 */   lwc1  $f6, 0xa8($s0)
/* 054A78 7F01FF48 4600803C */  c.lt.s $f16, $f0
/* 054A7C 7F01FF4C 00000000 */  nop   
/* 054A80 7F01FF50 45020004 */  bc1fl .L7F01FF64
/* 054A84 7F01FF54 C60600A8 */   lwc1  $f6, 0xa8($s0)
/* 054A88 7F01FF58 E60C00B8 */  swc1  $f12, 0xb8($s0)
/* 054A8C 7F01FF5C E60C00B0 */  swc1  $f12, 0xb0($s0)
.L7F01FF60:
/* 054A90 7F01FF60 C60600A8 */  lwc1  $f6, 0xa8($s0)
.L7F01FF64:
/* 054A94 7F01FF64 C6320004 */  lwc1  $f18, 4($s1)
/* 054A98 7F01FF68 460E3201 */  sub.s $f8, $f6, $f14
/* 054A9C 7F01FF6C 46089280 */  add.s $f10, $f18, $f8
/* 054AA0 7F01FF70 10000002 */  b     .L7F01FF7C
/* 054AA4 7F01FF74 E62A0004 */   swc1  $f10, 4($s1)
/* 054AA8 7F01FF78 C60E00AC */  lwc1  $f14, 0xac($s0)
.L7F01FF7C:
/* 054AAC 7F01FF7C 8FAD0044 */  lw    $t5, 0x44($sp)
.L7F01FF80:
/* 054AB0 7F01FF80 24020001 */  li    $v0, 1
/* 054AB4 7F01FF84 E5AE0000 */  swc1  $f14, ($t5)
/* 054AB8 7F01FF88 8FAF0030 */  lw    $t7, 0x30($sp)
/* 054ABC 7F01FF8C 8FB8003C */  lw    $t8, 0x3c($sp)
/* 054AC0 7F01FF90 55E00007 */  bnezl $t7, .L7F01FFB0
/* 054AC4 7F01FF94 8FBF0024 */   lw    $ra, 0x24($sp)
/* 054AC8 7F01FF98 C7040000 */  lwc1  $f4, ($t8)
/* 054ACC 7F01FF9C E6240000 */  swc1  $f4, ($s1)
/* 054AD0 7F01FFA0 8FB9003C */  lw    $t9, 0x3c($sp)
/* 054AD4 7F01FFA4 C7260008 */  lwc1  $f6, 8($t9)
/* 054AD8 7F01FFA8 E6260008 */  swc1  $f6, 8($s1)
/* 054ADC 7F01FFAC 8FBF0024 */  lw    $ra, 0x24($sp)
.L7F01FFB0:
/* 054AE0 7F01FFB0 8FB0001C */  lw    $s0, 0x1c($sp)
/* 054AE4 7F01FFB4 8FB10020 */  lw    $s1, 0x20($sp)
/* 054AE8 7F01FFB8 03E00008 */  jr    $ra
/* 054AEC 7F01FFBC 27BD0038 */   addiu $sp, $sp, 0x38
)
#endif
#ifdef VERSION_EU
GLOBAL_ASM(
.late_rodata
glabel D_80051D10
.word 0x3DF34D68 /* 0.118799984455109 */
glabel D_80051D14
.word 0x3DF34D68 /* 0.118799984455109 */
glabel D_80051D18
.word 0x3F619653 /* 0.881200015544891 */
glabel D_80051D1C
.word 0x3dcccccd /*0.1*/
glabel D_80051D20
.word 0x3DF34D68 /* 0.118799984455109 */
glabel D_80051D24
.word 0xbdcccccd /*-0.1*/

.text
glabel sub_GAME_7F01FC10
/* 054740 7F01FC10 27BDFFC8 */  addiu $sp, $sp, -0x38
/* 054744 7F01FC14 AFBF0024 */  sw    $ra, 0x24($sp)
/* 054748 7F01FC18 AFB10020 */  sw    $s1, 0x20($sp)
/* 05474C 7F01FC1C AFB0001C */  sw    $s0, 0x1c($sp)
/* 054750 7F01FC20 AFA40038 */  sw    $a0, 0x38($sp)
/* 054754 7F01FC24 AFA5003C */  sw    $a1, 0x3c($sp)
/* 054758 7F01FC28 AFA70044 */  sw    $a3, 0x44($sp)
/* 05475C 7F01FC2C 8C900004 */  lw    $s0, 4($a0)
/* 054760 7F01FC30 AFA00030 */  sw    $zero, 0x30($sp)
/* 054764 7F01FC34 44806000 */  mtc1  $zero, $f12
/* 054768 7F01FC38 8E0F0018 */  lw    $t7, 0x18($s0)
/* 05476C 7F01FC3C 00C08825 */  move  $s1, $a2
/* 054770 7F01FC40 00A01825 */  move  $v1, $a1
/* 054774 7F01FC44 8DF80014 */  lw    $t8, 0x14($t7)
/* 054778 7F01FC48 46006386 */  mov.s $f14, $f12
/* 05477C 7F01FC4C 530000CC */  beql  $t8, $zero, .L7F01FF80
/* 054780 7F01FC50 8FAD0044 */   lw    $t5, 0x44($sp)
/* 054784 7F01FC54 82190007 */  lb    $t9, 7($s0)
/* 054788 7F01FC58 24010004 */  li    $at, 4
/* 05478C 7F01FC5C 1721002C */  bne   $t9, $at, .L7F01FD10
/* 054790 7F01FC60 00000000 */   nop   
/* 054794 7F01FC64 C6020038 */  lwc1  $f2, 0x38($s0)
/* 054798 7F01FC68 3C028005 */  lui   $v0, %hi(g_JP_GlobalTimerDelta)
/* 05479C 7F01FC6C 24428378 */  addiu $v0, %lo(g_JP_GlobalTimerDelta) # addiu $v0, $v0, -0x7c88
/* 0547A0 7F01FC70 4602603C */  c.lt.s $f12, $f2
/* 0547A4 7F01FC74 00000000 */  nop   
/* 0547A8 7F01FC78 45000025 */  bc1f  .L7F01FD10
/* 0547AC 7F01FC7C 00000000 */   nop   
/* 0547B0 7F01FC80 C48400A4 */  lwc1  $f4, 0xa4($a0)
/* 0547B4 7F01FC84 C4460000 */  lwc1  $f6, ($v0)
/* 0547B8 7F01FC88 C60A003C */  lwc1  $f10, 0x3c($s0)
/* 0547BC 7F01FC8C 46062202 */  mul.s $f8, $f4, $f6
/* 0547C0 7F01FC90 460A1481 */  sub.s $f18, $f2, $f10
/* 0547C4 7F01FC94 C60A0040 */  lwc1  $f10, 0x40($s0)
/* 0547C8 7F01FC98 C4C60000 */  lwc1  $f6, ($a2)
/* 0547CC 7F01FC9C 46124102 */  mul.s $f4, $f8, $f18
/* 0547D0 7F01FCA0 46022003 */  div.s $f0, $f4, $f2
/* 0547D4 7F01FCA4 C4C40004 */  lwc1  $f4, 4($a2)
/* 0547D8 7F01FCA8 46005202 */  mul.s $f8, $f10, $f0
/* 0547DC 7F01FCAC 46083480 */  add.s $f18, $f6, $f8
/* 0547E0 7F01FCB0 E4D20000 */  swc1  $f18, ($a2)
/* 0547E4 7F01FCB4 C60A0044 */  lwc1  $f10, 0x44($s0)
/* 0547E8 7F01FCB8 C4D20008 */  lwc1  $f18, 8($a2)
/* 0547EC 7F01FCBC 46005182 */  mul.s $f6, $f10, $f0
/* 0547F0 7F01FCC0 46062200 */  add.s $f8, $f4, $f6
/* 0547F4 7F01FCC4 E4C80004 */  swc1  $f8, 4($a2)
/* 0547F8 7F01FCC8 C60A0048 */  lwc1  $f10, 0x48($s0)
/* 0547FC 7F01FCCC 46005102 */  mul.s $f4, $f10, $f0
/* 054800 7F01FCD0 46049180 */  add.s $f6, $f18, $f4
/* 054804 7F01FCD4 E4C60008 */  swc1  $f6, 8($a2)
/* 054808 7F01FCD8 8FA80038 */  lw    $t0, 0x38($sp)
/* 05480C 7F01FCDC C4480000 */  lwc1  $f8, ($v0)
/* 054810 7F01FCE0 C604003C */  lwc1  $f4, 0x3c($s0)
/* 054814 7F01FCE4 C50A00A4 */  lwc1  $f10, 0xa4($t0)
/* 054818 7F01FCE8 460A4482 */  mul.s $f18, $f8, $f10
/* 05481C 7F01FCEC C6080038 */  lwc1  $f8, 0x38($s0)
/* 054820 7F01FCF0 46122180 */  add.s $f6, $f4, $f18
/* 054824 7F01FCF4 E606003C */  swc1  $f6, 0x3c($s0)
/* 054828 7F01FCF8 C60A003C */  lwc1  $f10, 0x3c($s0)
/* 05482C 7F01FCFC 460A403C */  c.lt.s $f8, $f10
/* 054830 7F01FD00 00000000 */  nop   
/* 054834 7F01FD04 45000002 */  bc1f  .L7F01FD10
/* 054838 7F01FD08 00000000 */   nop   
/* 05483C 7F01FD0C E60C0038 */  swc1  $f12, 0x38($s0)
.L7F01FD10:
/* 054840 7F01FD10 3C028005 */  lui   $v0, %hi(g_GlobalTimerDelta)
/* 054844 7F01FD14 24428378 */  addiu $v0, %lo(g_GlobalTimerDelta) # addiu $v0, $v0, -0x7c88
/* 054848 7F01FD18 C4520000 */  lwc1  $f18, ($v0)
/* 05484C 7F01FD1C C60400B0 */  lwc1  $f4, 0xb0($s0)
/* 054850 7F01FD20 C6280000 */  lwc1  $f8, ($s1)
/* 054854 7F01FD24 240A0001 */  li    $t2, 1
/* 054858 7F01FD28 46122182 */  mul.s $f6, $f4, $f18
/* 05485C 7F01FD2C 02002025 */  move  $a0, $s0
/* 054860 7F01FD30 02203825 */  move  $a3, $s1
/* 054864 7F01FD34 46064280 */  add.s $f10, $f8, $f6
/* 054868 7F01FD38 C6260008 */  lwc1  $f6, 8($s1)
/* 05486C 7F01FD3C E62A0000 */  swc1  $f10, ($s1)
/* 054870 7F01FD40 C4520000 */  lwc1  $f18, ($v0)
/* 054874 7F01FD44 C60400B8 */  lwc1  $f4, 0xb8($s0)
/* 054878 7F01FD48 46122202 */  mul.s $f8, $f4, $f18
/* 05487C 7F01FD4C 46083280 */  add.s $f10, $f6, $f8
/* 054880 7F01FD50 E62A0008 */  swc1  $f10, 8($s1)
/* 054884 7F01FD54 8E090018 */  lw    $t1, 0x18($s0)
/* 054888 7F01FD58 8FA6003C */  lw    $a2, 0x3c($sp)
/* 05488C 7F01FD5C 8D250014 */  lw    $a1, 0x14($t1)
/* 054890 7F01FD60 AFA30028 */  sw    $v1, 0x28($sp)
/* 054894 7F01FD64 0FC07D85 */  jal   sub_GAME_7F01F614
/* 054898 7F01FD68 AFAA0010 */   sw    $t2, 0x10($sp)
/* 05489C 7F01FD6C 10400006 */  beqz  $v0, .L7F01FD88
/* 0548A0 7F01FD70 8FA30028 */   lw    $v1, 0x28($sp)
/* 0548A4 7F01FD74 8E0B0018 */  lw    $t3, 0x18($s0)
/* 0548A8 7F01FD78 240C0001 */  li    $t4, 1
/* 0548AC 7F01FD7C 02201825 */  move  $v1, $s1
/* 0548B0 7F01FD80 AD620014 */  sw    $v0, 0x14($t3)
/* 0548B4 7F01FD84 AFAC0030 */  sw    $t4, 0x30($sp)
.L7F01FD88:
/* 0548B8 7F01FD88 8E0D0014 */  lw    $t5, 0x14($s0)
/* 0548BC 7F01FD8C 31AF1000 */  andi  $t7, $t5, 0x1000
/* 0548C0 7F01FD90 55E0007A */  bnezl $t7, .L7F01FF7C
/* 0548C4 7F01FD94 C60E00AC */   lwc1  $f14, 0xac($s0)
/* 0548C8 7F01FD98 8E180018 */  lw    $t8, 0x18($s0)
/* 0548CC 7F01FD9C 8C650000 */  lw    $a1, ($v1)
/* 0548D0 7F01FDA0 8C660008 */  lw    $a2, 8($v1)
/* 0548D4 7F01FDA4 0FC2CA5C */  jal   stanGetPositionYValue
/* 0548D8 7F01FDA8 8F040014 */   lw    $a0, 0x14($t8)
/* 0548DC 7F01FDAC 8E190014 */  lw    $t9, 0x14($s0)
/* 0548E0 7F01FDB0 44806000 */  mtc1  $zero, $f12
/* 0548E4 7F01FDB4 46000386 */  mov.s $f14, $f0
/* 0548E8 7F01FDB8 332E0001 */  andi  $t6, $t9, 1
/* 0548EC 7F01FDBC 11C00014 */  beqz  $t6, .L7F01FE10
/* 0548F0 7F01FDC0 E60000AC */   swc1  $f0, 0xac($s0)
/* 0548F4 7F01FDC4 8FA40038 */  lw    $a0, 0x38($sp)
/* 0548F8 7F01FDC8 8C880008 */  lw    $t0, 8($a0)
/* 0548FC 7F01FDCC 8D050000 */  lw    $a1, ($t0)
/* 054900 7F01FDD0 0FC1B1E7 */  jal   extract_id_from_object_structure_microcode
/* 054904 7F01FDD4 E7AE002C */   swc1  $f14, 0x2c($sp)
/* 054908 7F01FDD8 8E090014 */  lw    $t1, 0x14($s0)
/* 05490C 7F01FDDC C60200AC */  lwc1  $f2, 0xac($s0)
/* 054910 7F01FDE0 2401FFFE */  li    $at, -2
/* 054914 7F01FDE4 C7AE002C */  lwc1  $f14, 0x2c($sp)
/* 054918 7F01FDE8 01215024 */  and   $t2, $t1, $at
/* 05491C 7F01FDEC AE0A0014 */  sw    $t2, 0x14($s0)
/* 054920 7F01FDF0 3C018005 */  lui   $at, %hi(D_80051D10)
/* 054924 7F01FDF4 E60200A8 */  swc1  $f2, 0xa8($s0)
/* 054928 7F01FDF8 C4241D10 */  lwc1  $f4, %lo(D_80051D10)($at)
/* 05492C 7F01FDFC 46041483 */  div.s $f18, $f2, $f4
/* 054930 7F01FE00 E61200A4 */  swc1  $f18, 0xa4($s0)
/* 054934 7F01FE04 C4460028 */  lwc1  $f6, 0x28($v0)
/* 054938 7F01FE08 10000055 */  b     .L7F01FF60
/* 05493C 7F01FE0C E4460038 */   swc1  $f6, 0x38($v0)
.L7F01FE10:
/* 054940 7F01FE10 C60800B4 */  lwc1  $f8, 0xb4($s0)
/* 054944 7F01FE14 260400A8 */  addiu $a0, $s0, 0xa8
/* 054948 7F01FE18 260500B4 */  addiu $a1, $s0, 0xb4
/* 05494C 7F01FE1C 46086032 */  c.eq.s $f12, $f8
/* 054950 7F01FE20 3C068005 */  lui   $a2, %hi(g_GlobalTimerDelta)
/* 054954 7F01FE24 45000007 */  bc1f  .L7F01FE44
/* 054958 7F01FE28 00000000 */   nop   
/* 05495C 7F01FE2C C60200AC */  lwc1  $f2, 0xac($s0)
/* 054960 7F01FE30 C60000A8 */  lwc1  $f0, 0xa8($s0)
/* 054964 7F01FE34 4600103C */  c.lt.s $f2, $f0
/* 054968 7F01FE38 00000000 */  nop   
/* 05496C 7F01FE3C 45020013 */  bc1fl .L7F01FE8C
/* 054970 7F01FE40 4602003E */   c.le.s $f0, $f2
.L7F01FE44:
/* 054974 7F01FE44 8CC68378 */  lw    $a2, %lo(g_GlobalTimerDelta)($a2)
/* 054978 7F01FE48 0FC15F51 */  jal   sub_GAME_7F057D44
/* 05497C 7F01FE4C E7AE002C */   swc1  $f14, 0x2c($sp)
/* 054980 7F01FE50 C60200AC */  lwc1  $f2, 0xac($s0)
/* 054984 7F01FE54 C60000A8 */  lwc1  $f0, 0xa8($s0)
/* 054988 7F01FE58 44806000 */  mtc1  $zero, $f12
/* 05498C 7F01FE5C C7AE002C */  lwc1  $f14, 0x2c($sp)
/* 054990 7F01FE60 4602003E */  c.le.s $f0, $f2
/* 054994 7F01FE64 3C018005 */  lui   $at, %hi(D_80051D14)
/* 054998 7F01FE68 45020008 */  bc1fl .L7F01FE8C
/* 05499C 7F01FE6C 4602003E */   c.le.s $f0, $f2
/* 0549A0 7F01FE70 E60200A8 */  swc1  $f2, 0xa8($s0)
/* 0549A4 7F01FE74 C42A1D14 */  lwc1  $f10, %lo(D_80051D14)($at)
/* 0549A8 7F01FE78 E60C00B4 */  swc1  $f12, 0xb4($s0)
/* 0549AC 7F01FE7C C60000A8 */  lwc1  $f0, 0xa8($s0)
/* 0549B0 7F01FE80 460A1103 */  div.s $f4, $f2, $f10
/* 0549B4 7F01FE84 E60400A4 */  swc1  $f4, 0xa4($s0)
/* 0549B8 7F01FE88 4602003E */  c.le.s $f0, $f2
.L7F01FE8C:
/* 0549BC 7F01FE8C 3C038005 */  lui   $v1, %hi(g_ClockTimer)
/* 0549C0 7F01FE90 24638374 */  addiu $v1, %lo(g_ClockTimer) # addiu $v1, $v1, -0x7c8c
/* 0549C4 7F01FE94 45020033 */  bc1fl .L7F01FF64
/* 0549C8 7F01FE98 C60600A8 */   lwc1  $f6, 0xa8($s0)
/* 0549CC 7F01FE9C 8C6B0000 */  lw    $t3, ($v1)
/* 0549D0 7F01FEA0 00001025 */  move  $v0, $zero
/* 0549D4 7F01FEA4 3C018005 */  lui   $at, %hi(D_80051D18)
/* 0549D8 7F01FEA8 19600011 */  blez  $t3, .L7F01FEF0
/* 0549DC 7F01FEAC 00000000 */   nop   
/* 0549E0 7F01FEB0 C4201D18 */  lwc1  $f0, %lo(D_80051D18)($at)
/* 0549E4 7F01FEB4 C61200A4 */  lwc1  $f18, 0xa4($s0)
.L7F01FEB8:
/* 0549E8 7F01FEB8 C60A00B0 */  lwc1  $f10, 0xb0($s0)
/* 0549EC 7F01FEBC 24420001 */  addiu $v0, $v0, 1
/* 0549F0 7F01FEC0 46009182 */  mul.s $f6, $f18, $f0
/* 0549F4 7F01FEC4 C61200B8 */  lwc1  $f18, 0xb8($s0)
/* 0549F8 7F01FEC8 46005102 */  mul.s $f4, $f10, $f0
/* 0549FC 7F01FECC 46023200 */  add.s $f8, $f6, $f2
/* 054A00 7F01FED0 46009182 */  mul.s $f6, $f18, $f0
/* 054A04 7F01FED4 E60400B0 */  swc1  $f4, 0xb0($s0)
/* 054A08 7F01FED8 E60800A4 */  swc1  $f8, 0xa4($s0)
/* 054A0C 7F01FEDC E60600B8 */  swc1  $f6, 0xb8($s0)
/* 054A10 7F01FEE0 8C6C0000 */  lw    $t4, ($v1)
/* 054A14 7F01FEE4 004C082A */  slt   $at, $v0, $t4
/* 054A18 7F01FEE8 5420FFF3 */  bnezl $at, .L7F01FEB8
/* 054A1C 7F01FEEC C61200A4 */   lwc1  $f18, 0xa4($s0)
.L7F01FEF0:
/* 054A20 7F01FEF0 3C018005 */  lui   $at, %hi(D_80051D1C)
/* 054A24 7F01FEF4 C4221D1C */  lwc1  $f2, %lo(D_80051D1C)($at)
/* 054A28 7F01FEF8 3C018005 */  lui   $at, %hi(D_80051D20)
/* 054A2C 7F01FEFC C42A1D20 */  lwc1  $f10, %lo(D_80051D20)($at)
/* 054A30 7F01FF00 C60800A4 */  lwc1  $f8, 0xa4($s0)
/* 054A34 7F01FF04 C60000B0 */  lwc1  $f0, 0xb0($s0)
/* 054A38 7F01FF08 3C018005 */  lui   $at, %hi(D_80051D24)
/* 054A3C 7F01FF0C 460A4102 */  mul.s $f4, $f8, $f10
/* 054A40 7F01FF10 4602003C */  c.lt.s $f0, $f2
/* 054A44 7F01FF14 00000000 */  nop   
/* 054A48 7F01FF18 45000011 */  bc1f  .L7F01FF60
/* 054A4C 7F01FF1C E60400A8 */   swc1  $f4, 0xa8($s0)
/* 054A50 7F01FF20 C4301D24 */  lwc1  $f16, %lo(D_80051D24)($at)
/* 054A54 7F01FF24 4600803C */  c.lt.s $f16, $f0
/* 054A58 7F01FF28 00000000 */  nop   
/* 054A5C 7F01FF2C 4502000D */  bc1fl .L7F01FF64
/* 054A60 7F01FF30 C60600A8 */   lwc1  $f6, 0xa8($s0)
/* 054A64 7F01FF34 C60000B8 */  lwc1  $f0, 0xb8($s0)
/* 054A68 7F01FF38 4602003C */  c.lt.s $f0, $f2
/* 054A6C 7F01FF3C 00000000 */  nop   
/* 054A70 7F01FF40 45020008 */  bc1fl .L7F01FF64
/* 054A74 7F01FF44 C60600A8 */   lwc1  $f6, 0xa8($s0)
/* 054A78 7F01FF48 4600803C */  c.lt.s $f16, $f0
/* 054A7C 7F01FF4C 00000000 */  nop   
/* 054A80 7F01FF50 45020004 */  bc1fl .L7F01FF64
/* 054A84 7F01FF54 C60600A8 */   lwc1  $f6, 0xa8($s0)
/* 054A88 7F01FF58 E60C00B8 */  swc1  $f12, 0xb8($s0)
/* 054A8C 7F01FF5C E60C00B0 */  swc1  $f12, 0xb0($s0)
.L7F01FF60:
/* 054A90 7F01FF60 C60600A8 */  lwc1  $f6, 0xa8($s0)
.L7F01FF64:
/* 054A94 7F01FF64 C6320004 */  lwc1  $f18, 4($s1)
/* 054A98 7F01FF68 460E3201 */  sub.s $f8, $f6, $f14
/* 054A9C 7F01FF6C 46089280 */  add.s $f10, $f18, $f8
/* 054AA0 7F01FF70 10000002 */  b     .L7F01FF7C
/* 054AA4 7F01FF74 E62A0004 */   swc1  $f10, 4($s1)
/* 054AA8 7F01FF78 C60E00AC */  lwc1  $f14, 0xac($s0)
.L7F01FF7C:
/* 054AAC 7F01FF7C 8FAD0044 */  lw    $t5, 0x44($sp)
.L7F01FF80:
/* 054AB0 7F01FF80 24020001 */  li    $v0, 1
/* 054AB4 7F01FF84 E5AE0000 */  swc1  $f14, ($t5)
/* 054AB8 7F01FF88 8FAF0030 */  lw    $t7, 0x30($sp)
/* 054ABC 7F01FF8C 8FB8003C */  lw    $t8, 0x3c($sp)
/* 054AC0 7F01FF90 55E00007 */  bnezl $t7, .L7F01FFB0
/* 054AC4 7F01FF94 8FBF0024 */   lw    $ra, 0x24($sp)
/* 054AC8 7F01FF98 C7040000 */  lwc1  $f4, ($t8)
/* 054ACC 7F01FF9C E6240000 */  swc1  $f4, ($s1)
/* 054AD0 7F01FFA0 8FB9003C */  lw    $t9, 0x3c($sp)
/* 054AD4 7F01FFA4 C7260008 */  lwc1  $f6, 8($t9)
/* 054AD8 7F01FFA8 E6260008 */  swc1  $f6, 8($s1)
/* 054ADC 7F01FFAC 8FBF0024 */  lw    $ra, 0x24($sp)
.L7F01FFB0:
/* 054AE0 7F01FFB0 8FB0001C */  lw    $s0, 0x1c($sp)
/* 054AE4 7F01FFB4 8FB10020 */  lw    $s1, 0x20($sp)
/* 054AE8 7F01FFB8 03E00008 */  jr    $ra
/* 054AEC 7F01FFBC 27BD0038 */   addiu $sp, $sp, 0x38
)
#endif


#endif

s32 chrGetNumFree(void)
{
    s32 count = 0;
    s32 i;

    for (i = 0; i < num_guards; i++)
    {
        if (ptr_guard_data[i].model == 0)
        {
            count++;
        }
    }

    return count;
}

f32  get_007_health_mod(void);

void chrSetMaxDamage(ChrRecord *chr, f32 maxdamage)
{
    chr->maxdamage = (get_007_health_mod() * maxdamage);
}

f32 chrGetMaxDamage(ChrRecord *chr)
{
    return chr->maxdamage;
}

void chrAddHealth(ChrRecord *chr, f32 health)
{
    chr->damage -= (health * get_007_health_mod());
}

f32 chrGetArmor(ChrRecord *chr)
{
    if (chr->damage < 0)
    {
        return -chr->damage;
    }

    return 0;
}

#ifdef NONMATCHING
void init_GUARDdata_with_set_values(void) {

}
#else
#ifndef VERSION_EU
GLOBAL_ASM(
.text
glabel init_GUARDdata_with_set_values
/* 054BEC 7F0200BC 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 054BF0 7F0200C0 F7B40010 */  sdc1  $f20, 0x10($sp)
/* 054BF4 7F0200C4 4487A000 */  mtc1  $a3, $f20
/* 054BF8 7F0200C8 3C078003 */  lui   $a3, %hi(num_guards)
/* 054BFC 7F0200CC 8CE7CC68 */  lw    $a3, %lo(num_guards)($a3)
/* 054C00 7F0200D0 AFB30028 */  sw    $s3, 0x28($sp)
/* 054C04 7F0200D4 AFB20024 */  sw    $s2, 0x24($sp)
/* 054C08 7F0200D8 AFB10020 */  sw    $s1, 0x20($sp)
/* 054C0C 7F0200DC AFB0001C */  sw    $s0, 0x1c($sp)
/* 054C10 7F0200E0 00808825 */  move  $s1, $a0
/* 054C14 7F0200E4 00A09025 */  move  $s2, $a1
/* 054C18 7F0200E8 00C09825 */  move  $s3, $a2
/* 054C1C 7F0200EC AFBF002C */  sw    $ra, 0x2c($sp)
/* 054C20 7F0200F0 00008025 */  move  $s0, $zero
/* 054C24 7F0200F4 18E0000E */  blez  $a3, .L7F020130
/* 054C28 7F0200F8 00001025 */   move  $v0, $zero
/* 054C2C 7F0200FC 3C058003 */  lui   $a1, %hi(ptr_guard_data)
/* 054C30 7F020100 8CA5CC64 */  lw    $a1, %lo(ptr_guard_data)($a1)
/* 054C34 7F020104 00002025 */  move  $a0, $zero
/* 054C38 7F020108 00A01825 */  move  $v1, $a1
.L7F02010C:
/* 054C3C 7F02010C 8C6E001C */  lw    $t6, 0x1c($v1)
/* 054C40 7F020110 24420001 */  addiu $v0, $v0, 1
/* 054C44 7F020114 0047082A */  slt   $at, $v0, $a3
/* 054C48 7F020118 15C00003 */  bnez  $t6, .L7F020128
/* 054C4C 7F02011C 246301DC */   addiu $v1, $v1, 0x1dc
/* 054C50 7F020120 10000003 */  b     .L7F020130
/* 054C54 7F020124 00858021 */   addu  $s0, $a0, $a1
.L7F020128:
/* 054C58 7F020128 1420FFF8 */  bnez  $at, .L7F02010C
/* 054C5C 7F02012C 248401DC */   addiu $a0, $a0, 0x1dc
.L7F020130:
/* 054C60 7F020130 240F0003 */  li    $t7, 3
/* 054C64 7F020134 A22F0000 */  sb    $t7, ($s1)
/* 054C68 7F020138 AE300004 */  sw    $s0, 4($s1)
/* 054C6C 7F02013C C6640000 */  lwc1  $f4, ($s3)
/* 054C70 7F020140 3C057F02 */  lui   $a1, %hi(sub_GAME_7F01FC10) # $a1, 0x7f02
/* 054C74 7F020144 24A5FC10 */  addiu $a1, %lo(sub_GAME_7F01FC10) # addiu $a1, $a1, -0x3f0
/* 054C78 7F020148 E6240008 */  swc1  $f4, 8($s1)
/* 054C7C 7F02014C C6660004 */  lwc1  $f6, 4($s3)
/* 054C80 7F020150 02402025 */  move  $a0, $s2
/* 054C84 7F020154 E626000C */  swc1  $f6, 0xc($s1)
/* 054C88 7F020158 C6680008 */  lwc1  $f8, 8($s3)
/* 054C8C 7F02015C E6280010 */  swc1  $f8, 0x10($s1)
/* 054C90 7F020160 8FB80040 */  lw    $t8, 0x40($sp)
/* 054C94 7F020164 0FC1BFD7 */  jal   sub_GAME_7F06FF5C
/* 054C98 7F020168 AE380014 */   sw    $t8, 0x14($s1)
/* 054C9C 7F02016C 2419000A */  li    $t9, 10
/* 054CA0 7F020170 A6590000 */  sh    $t9, ($s2)
/* 054CA4 7F020174 AE500004 */  sw    $s0, 4($s2)
/* 054CA8 7F020178 02402025 */  move  $a0, $s2
/* 054CAC 7F02017C 0FC1B303 */  jal   setsuboffset
/* 054CB0 7F020180 02602825 */   move  $a1, $s3
/* 054CB4 7F020184 4405A000 */  mfc1  $a1, $f20
/* 054CB8 7F020188 0FC1B34F */  jal   setsubroty
/* 054CBC 7F02018C 02402025 */   move  $a0, $s2
/* 054CC0 7F020190 4480A000 */  mtc1  $zero, $f20
/* 054CC4 7F020194 3C058003 */  lui   $a1, %hi(animation_rate)
/* 054CC8 7F020198 8CA5C900 */  lw    $a1, %lo(animation_rate)($a1)
/* 054CCC 7F02019C 4406A000 */  mfc1  $a2, $f20
/* 054CD0 7F0201A0 0FC1BFC6 */  jal   sub_GAME_7F06FF18
/* 054CD4 7F0201A4 02402025 */   move  $a0, $s2
/* 054CD8 7F0201A8 3C028003 */  lui   $v0, %hi(player1_guardID)
/* 054CDC 7F0201AC 2442CC60 */  addiu $v0, %lo(player1_guardID) # addiu $v0, $v0, -0x33a0
/* 054CE0 7F0201B0 8C480000 */  lw    $t0, ($v0)
/* 054CE4 7F0201B4 3C0B8005 */  lui   $t3, %hi(g_GlobalTimer) 
/* 054CE8 7F0201B8 3C01437A */  li    $at, 0x437A0000 # 250.000000
/* 054CEC 7F0201BC A6080000 */  sh    $t0, ($s0)
/* 054CF0 7F0201C0 8C490000 */  lw    $t1, ($v0)
/* 054CF4 7F0201C4 44815000 */  mtc1  $at, $f10
/* 054CF8 7F0201C8 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 054CFC 7F0201CC 252A0001 */  addiu $t2, $t1, 1
/* 054D00 7F0201D0 AC4A0000 */  sw    $t2, ($v0)
/* 054D04 7F0201D4 A2000006 */  sb    $zero, 6($s0)
/* 054D08 7F0201D8 A200000F */  sb    $zero, 0xf($s0)
/* 054D0C 7F0201DC AE110018 */  sw    $s1, 0x18($s0)
/* 054D10 7F0201E0 AE12001C */  sw    $s2, 0x1c($s0)
/* 054D14 7F0201E4 AE000020 */  sw    $zero, 0x20($s0)
/* 054D18 7F0201E8 A200000B */  sb    $zero, 0xb($s0)
/* 054D1C 7F0201EC AE0000C8 */  sw    $zero, 0xc8($s0)
/* 054D20 7F0201F0 A2000009 */  sb    $zero, 9($s0)
/* 054D24 7F0201F4 8D6B837C */  lw    $t3, %lo(g_GlobalTimer)($t3)
/* 054D28 7F0201F8 44818000 */  mtc1  $at, $f16
/* 054D2C 7F0201FC AE0000D4 */  sw    $zero, 0xd4($s0)
/* 054D30 7F020200 E61400D8 */  swc1  $f20, 0xd8($s0)
/* 054D34 7F020204 E61400DC */  swc1  $f20, 0xdc($s0)
/* 054D38 7F020208 E61400E0 */  swc1  $f20, 0xe0($s0)
/* 054D3C 7F02020C AE0000E4 */  sw    $zero, 0xe4($s0)
/* 054D40 7F020210 AE0000E8 */  sw    $zero, 0xe8($s0)
/* 054D44 7F020214 AE0000F0 */  sw    $zero, 0xf0($s0)
/* 054D48 7F020218 A200000A */  sb    $zero, 0xa($s0)
/* 054D4C 7F02021C E614013C */  swc1  $f20, 0x13c($s0)
/* 054D50 7F020220 E61400FC */  swc1  $f20, 0xfc($s0)
/* 054D54 7F020224 E60A00D0 */  swc1  $f10, 0xd0($s0)
/* 054D58 7F020228 AE0B00CC */  sw    $t3, 0xcc($s0)
/* 054D5C 7F02022C 0FC074BA */  jal   get_007_health_mod
/* 054D60 7F020230 E61000EC */   swc1  $f16, 0xec($s0)
/* 054D64 7F020234 3C014080 */  li    $at, 0x40800000 # 4.000000
/* 054D68 7F020238 44819000 */  mtc1  $at, $f18
/* 054D6C 7F02023C 02202025 */  move  $a0, $s1
/* 054D70 7F020240 260500F8 */  addiu $a1, $s0, 0xf8
/* 054D74 7F020244 46120102 */  mul.s $f4, $f0, $f18
/* 054D78 7F020248 0FC10027 */  jal   set_color_shading_from_tile
/* 054D7C 7F02024C E6040100 */   swc1  $f4, 0x100($s0)
/* 054D80 7F020250 920C00F8 */  lbu   $t4, 0xf8($s0)
/* 054D84 7F020254 920D00F9 */  lbu   $t5, 0xf9($s0)
/* 054D88 7F020258 920E00FA */  lbu   $t6, 0xfa($s0)
/* 054D8C 7F02025C 920F00FB */  lbu   $t7, 0xfb($s0)
/* 054D90 7F020260 241800FF */  li    $t8, 255
/* 054D94 7F020264 24190001 */  li    $t9, 1
/* 054D98 7F020268 A218000C */  sb    $t8, 0xc($s0)
/* 054D9C 7F02026C AE000168 */  sw    $zero, 0x168($s0)
/* 054DA0 7F020270 AE00016C */  sw    $zero, 0x16c($s0)
/* 054DA4 7F020274 AE000170 */  sw    $zero, 0x170($s0)
/* 054DA8 7F020278 AE000174 */  sw    $zero, 0x174($s0)
/* 054DAC 7F02027C AE000178 */  sw    $zero, 0x178($s0)
/* 054DB0 7F020280 AE00017C */  sw    $zero, 0x17c($s0)
/* 054DB4 7F020284 AE190014 */  sw    $t9, 0x14($s0)
/* 054DB8 7F020288 A6000012 */  sh    $zero, 0x12($s0)
/* 054DBC 7F02028C E61400A4 */  swc1  $f20, 0xa4($s0)
/* 054DC0 7F020290 E61400A8 */  swc1  $f20, 0xa8($s0)
/* 054DC4 7F020294 E61400AC */  swc1  $f20, 0xac($s0)
/* 054DC8 7F020298 E61400B0 */  swc1  $f20, 0xb0($s0)
/* 054DCC 7F02029C E61400B4 */  swc1  $f20, 0xb4($s0)
/* 054DD0 7F0202A0 E61400B8 */  swc1  $f20, 0xb8($s0)
/* 054DD4 7F0202A4 A20C00F4 */  sb    $t4, 0xf4($s0)
/* 054DD8 7F0202A8 A20D00F5 */  sb    $t5, 0xf5($s0)
/* 054DDC 7F0202AC A20E00F6 */  sb    $t6, 0xf6($s0)
/* 054DE0 7F0202B0 A20F00F7 */  sb    $t7, 0xf7($s0)
/* 054DE4 7F0202B4 C6660000 */  lwc1  $f6, ($s3)
/* 054DE8 7F0202B8 2402FFFF */  li    $v0, -1
/* 054DEC 7F0202BC 3C0141A0 */  li    $at, 0x41A00000 # 20.000000
/* 054DF0 7F0202C0 E60600BC */  swc1  $f6, 0xbc($s0)
/* 054DF4 7F0202C4 C6680004 */  lwc1  $f8, 4($s3)
/* 054DF8 7F0202C8 44818000 */  mtc1  $at, $f16
/* 054DFC 7F0202CC 3C014339 */  li    $at, 0x43390000 # 185.000000
/* 054E00 7F0202D0 E60800C0 */  swc1  $f8, 0xc0($s0)
/* 054E04 7F0202D4 C66A0008 */  lwc1  $f10, 8($s3)
/* 054E08 7F0202D8 A2000007 */  sb    $zero, 7($s0)
/* 054E0C 7F0202DC A2000008 */  sb    $zero, 8($s0)
/* 054E10 7F0202E0 E60A00C4 */  swc1  $f10, 0xc4($s0)
/* 054E14 7F0202E4 8FA80044 */  lw    $t0, 0x44($sp)
/* 054E18 7F0202E8 44819000 */  mtc1  $at, $f18
/* 054E1C 7F0202EC 26250008 */  addiu $a1, $s1, 8
/* 054E20 7F0202F0 A6000108 */  sh    $zero, 0x108($s0)
/* 054E24 7F0202F4 A602010A */  sh    $v0, 0x10a($s0)
/* 054E28 7F0202F8 A200010C */  sb    $zero, 0x10c($s0)
/* 054E2C 7F0202FC A200010D */  sb    $zero, 0x10d($s0)
/* 054E30 7F020300 A200010E */  sb    $zero, 0x10e($s0)
/* 054E34 7F020304 A200010F */  sb    $zero, 0x10f($s0)
/* 054E38 7F020308 AE000110 */  sw    $zero, 0x110($s0)
/* 054E3C 7F02030C A6020114 */  sh    $v0, 0x114($s0)
/* 054E40 7F020310 A6020118 */  sh    $v0, 0x118($s0)
/* 054E44 7F020314 A602011A */  sh    $v0, 0x11a($s0)
/* 054E48 7F020318 A6020116 */  sh    $v0, 0x116($s0)
/* 054E4C 7F02031C A2020180 */  sb    $v0, 0x180($s0)
/* 054E50 7F020320 A20201AC */  sb    $v0, 0x1ac($s0)
/* 054E54 7F020324 A2000004 */  sb    $zero, 4($s0)
/* 054E58 7F020328 A2000005 */  sb    $zero, 5($s0)
/* 054E5C 7F02032C A2000010 */  sb    $zero, 0x10($s0)
/* 054E60 7F020330 A2000002 */  sb    $zero, 2($s0)
/* 054E64 7F020334 A2000003 */  sb    $zero, 3($s0)
/* 054E68 7F020338 A200000D */  sb    $zero, 0xd($s0)
/* 054E6C 7F02033C A2020011 */  sb    $v0, 0x11($s0)
/* 054E70 7F020340 E6140140 */  swc1  $f20, 0x140($s0)
/* 054E74 7F020344 E6140144 */  swc1  $f20, 0x144($s0)
/* 054E78 7F020348 E6140148 */  swc1  $f20, 0x148($s0)
/* 054E7C 7F02034C E614014C */  swc1  $f20, 0x14c($s0)
/* 054E80 7F020350 E6140150 */  swc1  $f20, 0x150($s0)
/* 054E84 7F020354 E6140154 */  swc1  $f20, 0x154($s0)
/* 054E88 7F020358 E6140158 */  swc1  $f20, 0x158($s0)
/* 054E8C 7F02035C E614015C */  swc1  $f20, 0x15c($s0)
/* 054E90 7F020360 A200000E */  sb    $zero, 0xe($s0)
/* 054E94 7F020364 AE000160 */  sw    $zero, 0x160($s0)
/* 054E98 7F020368 AE000164 */  sw    $zero, 0x164($s0)
/* 054E9C 7F02036C AE0001D8 */  sw    $zero, 0x1d8($s0)
/* 054EA0 7F020370 00A03025 */  move  $a2, $a1
/* 054EA4 7F020374 02402025 */  move  $a0, $s2
/* 054EA8 7F020378 260700AC */  addiu $a3, $s0, 0xac
/* 054EAC 7F02037C E6100024 */  swc1  $f16, 0x24($s0)
/* 054EB0 7F020380 AE080104 */  sw    $t0, 0x104($s0)
/* 054EB4 7F020384 0FC07F04 */  jal   sub_GAME_7F01FC10
/* 054EB8 7F020388 E6120028 */   swc1  $f18, 0x28($s0)
/* 054EBC 7F02038C 0FC08365 */  jal   chrPositionRelated7F020D94
/* 054EC0 7F020390 02002025 */   move  $a0, $s0
/* 054EC4 7F020394 8FBF002C */  lw    $ra, 0x2c($sp)
/* 054EC8 7F020398 02201025 */  move  $v0, $s1
/* 054ECC 7F02039C 8FB10020 */  lw    $s1, 0x20($sp)
/* 054ED0 7F0203A0 D7B40010 */  ldc1  $f20, 0x10($sp)
/* 054ED4 7F0203A4 8FB0001C */  lw    $s0, 0x1c($sp)
/* 054ED8 7F0203A8 8FB20024 */  lw    $s2, 0x24($sp)
/* 054EDC 7F0203AC 8FB30028 */  lw    $s3, 0x28($sp)
/* 054EE0 7F0203B0 03E00008 */  jr    $ra
/* 054EE4 7F0203B4 27BD0030 */   addiu $sp, $sp, 0x30
)
#endif
#ifdef VERSION_EU
GLOBAL_ASM(
.late_rodata 
glabel D_80047E48
.word 0x3f99999a /*1.2*/

.text
glabel init_GUARDdata_with_set_values
/* 05290C 7F01FF1C 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 052910 7F01FF20 F7B40010 */  sdc1  $f20, 0x10($sp)
/* 052914 7F01FF24 4487A000 */  mtc1  $a3, $f20
/* 052918 7F01FF28 3C078003 */  lui   $a3, %hi(num_guards) # $a3, 0x8003
/* 05291C 7F01FF2C 8CE781B8 */  lw    $a3, %lo(num_guards)($a3)
/* 052920 7F01FF30 AFB30028 */  sw    $s3, 0x28($sp)
/* 052924 7F01FF34 AFB20024 */  sw    $s2, 0x24($sp)
/* 052928 7F01FF38 AFB10020 */  sw    $s1, 0x20($sp)
/* 05292C 7F01FF3C AFB0001C */  sw    $s0, 0x1c($sp)
/* 052930 7F01FF40 00808825 */  move  $s1, $a0
/* 052934 7F01FF44 00A09025 */  move  $s2, $a1
/* 052938 7F01FF48 00C09825 */  move  $s3, $a2
/* 05293C 7F01FF4C AFBF002C */  sw    $ra, 0x2c($sp)
/* 052940 7F01FF50 00008025 */  move  $s0, $zero
/* 052944 7F01FF54 18E0000E */  blez  $a3, .L7F01FF90
/* 052948 7F01FF58 00001025 */   move  $v0, $zero
/* 05294C 7F01FF5C 3C058003 */  lui   $a1, %hi(ptr_guard_data) # $a1, 0x8003
/* 052950 7F01FF60 8CA581B4 */  lw    $a1, %lo(ptr_guard_data)($a1)
/* 052954 7F01FF64 00002025 */  move  $a0, $zero
/* 052958 7F01FF68 00A01825 */  move  $v1, $a1
.L7F01FF6C:
/* 05295C 7F01FF6C 8C6E001C */  lw    $t6, 0x1c($v1)
/* 052960 7F01FF70 24420001 */  addiu $v0, $v0, 1
/* 052964 7F01FF74 0047082A */  slt   $at, $v0, $a3
/* 052968 7F01FF78 15C00003 */  bnez  $t6, .L7F01FF88
/* 05296C 7F01FF7C 246301DC */   addiu $v1, $v1, 0x1dc
/* 052970 7F01FF80 10000003 */  b     .L7F01FF90
/* 052974 7F01FF84 00858021 */   addu  $s0, $a0, $a1
.L7F01FF88:
/* 052978 7F01FF88 1420FFF8 */  bnez  $at, .L7F01FF6C
/* 05297C 7F01FF8C 248401DC */   addiu $a0, $a0, 0x1dc
.L7F01FF90:
/* 052980 7F01FF90 240F0003 */  li    $t7, 3
/* 052984 7F01FF94 A22F0000 */  sb    $t7, ($s1)
/* 052988 7F01FF98 AE300004 */  sw    $s0, 4($s1)
/* 05298C 7F01FF9C C6640000 */  lwc1  $f4, ($s3)
/* 052990 7F01FFA0 3C057F02 */  lui   $a1, %hi(sub_GAME_7F01FC10) # $a1, 0x7f02
/* 052994 7F01FFA4 24A5FA70 */  addiu $a1, %lo(sub_GAME_7F01FC10) # addiu $a1, $a1, -0x590
/* 052998 7F01FFA8 E6240008 */  swc1  $f4, 8($s1)
/* 05299C 7F01FFAC C6660004 */  lwc1  $f6, 4($s3)
/* 0529A0 7F01FFB0 02402025 */  move  $a0, $s2
/* 0529A4 7F01FFB4 E626000C */  swc1  $f6, 0xc($s1)
/* 0529A8 7F01FFB8 C6680008 */  lwc1  $f8, 8($s3)
/* 0529AC 7F01FFBC E6280010 */  swc1  $f8, 0x10($s1)
/* 0529B0 7F01FFC0 8FB80040 */  lw    $t8, 0x40($sp)
/* 0529B4 7F01FFC4 0FC1C03F */  jal   sub_GAME_7F06FF5C
/* 0529B8 7F01FFC8 AE380014 */   sw    $t8, 0x14($s1)
/* 0529BC 7F01FFCC 2419000A */  li    $t9, 10
/* 0529C0 7F01FFD0 A6590000 */  sh    $t9, ($s2)
/* 0529C4 7F01FFD4 AE500004 */  sw    $s0, 4($s2)
/* 0529C8 7F01FFD8 02402025 */  move  $a0, $s2
/* 0529CC 7F01FFDC 0FC1B480 */  jal   setsuboffset
/* 0529D0 7F01FFE0 02602825 */   move  $a1, $s3
/* 0529D4 7F01FFE4 4405A000 */  mfc1  $a1, $f20
/* 0529D8 7F01FFE8 0FC1B49D */  jal   setsubroty
/* 0529DC 7F01FFEC 02402025 */   move  $a0, $s2
/* 0529E0 7F01FFF0 3C018002 */  lui   $at, %hi(animation_rate) # $at, 0x8002
/* 0529E4 7F01FFF4 C42A7E50 */  lwc1  $f10, %lo(animation_rate)($at)
/* 0529E8 7F01FFF8 3C018004 */  lui   $at, %hi(D_80047E48) # $at, 0x8004
/* 0529EC 7F01FFFC C4307E48 */  lwc1  $f16, %lo(D_80047E48)($at)
/* 0529F0 7F020000 4480A000 */  mtc1  $zero, $f20
/* 0529F4 7F020004 02402025 */  move  $a0, $s2
/* 0529F8 7F020008 46105482 */  mul.s $f18, $f10, $f16
/* 0529FC 7F02000C 4406A000 */  mfc1  $a2, $f20
/* 052A00 7F020010 44059000 */  mfc1  $a1, $f18
/* 052A04 7F020014 0FC1C02E */  jal   sub_GAME_7F06FF18
/* 052A08 7F020018 00000000 */   nop   
/* 052A0C 7F02001C 3C028003 */  lui   $v0, %hi(player1_guardID) # $v0, 0x8003
/* 052A10 7F020020 244281B0 */  addiu $v0, %lo(player1_guardID) # addiu $v0, $v0, -0x7e50
/* 052A14 7F020024 8C480000 */  lw    $t0, ($v0)
/* 052A18 7F020028 3C0B8004 */  lui   $t3, %hi(g_GlobalTimer) # $t3, 0x8004
/* 052A1C 7F02002C 3C01437A */  li    $at, 0x437A0000 # 250.000000
/* 052A20 7F020030 A6080000 */  sh    $t0, ($s0)
/* 052A24 7F020034 8C490000 */  lw    $t1, ($v0)
/* 052A28 7F020038 44812000 */  mtc1  $at, $f4
/* 052A2C 7F02003C 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 052A30 7F020040 252A0001 */  addiu $t2, $t1, 1
/* 052A34 7F020044 AC4A0000 */  sw    $t2, ($v0)
/* 052A38 7F020048 A2000006 */  sb    $zero, 6($s0)
/* 052A3C 7F02004C A200000F */  sb    $zero, 0xf($s0)
/* 052A40 7F020050 AE110018 */  sw    $s1, 0x18($s0)
/* 052A44 7F020054 AE12001C */  sw    $s2, 0x1c($s0)
/* 052A48 7F020058 AE000020 */  sw    $zero, 0x20($s0)
/* 052A4C 7F02005C A200000B */  sb    $zero, 0xb($s0)
/* 052A50 7F020060 AE0000C8 */  sw    $zero, 0xc8($s0)
/* 052A54 7F020064 A2000009 */  sb    $zero, 9($s0)
/* 052A58 7F020068 8D6B0FFC */  lw    $t3, %lo(g_GlobalTimer)($t3)
/* 052A5C 7F02006C 44813000 */  mtc1  $at, $f6
/* 052A60 7F020070 AE0000D4 */  sw    $zero, 0xd4($s0)
/* 052A64 7F020074 E61400D8 */  swc1  $f20, 0xd8($s0)
/* 052A68 7F020078 E61400DC */  swc1  $f20, 0xdc($s0)
/* 052A6C 7F02007C E61400E0 */  swc1  $f20, 0xe0($s0)
/* 052A70 7F020080 AE0000E4 */  sw    $zero, 0xe4($s0)
/* 052A74 7F020084 AE0000E8 */  sw    $zero, 0xe8($s0)
/* 052A78 7F020088 AE0000F0 */  sw    $zero, 0xf0($s0)
/* 052A7C 7F02008C A200000A */  sb    $zero, 0xa($s0)
/* 052A80 7F020090 E614013C */  swc1  $f20, 0x13c($s0)
/* 052A84 7F020094 E61400FC */  swc1  $f20, 0xfc($s0)
/* 052A88 7F020098 E60400D0 */  swc1  $f4, 0xd0($s0)
/* 052A8C 7F02009C AE0B00CC */  sw    $t3, 0xcc($s0)
/* 052A90 7F0200A0 0FC07452 */  jal   get_007_health_mod
/* 052A94 7F0200A4 E60600EC */   swc1  $f6, 0xec($s0)
/* 052A98 7F0200A8 3C014080 */  li    $at, 0x40800000 # 4.000000
/* 052A9C 7F0200AC 44814000 */  mtc1  $at, $f8
/* 052AA0 7F0200B0 02202025 */  move  $a0, $s1
/* 052AA4 7F0200B4 260500F8 */  addiu $a1, $s0, 0xf8
/* 052AA8 7F0200B8 46080282 */  mul.s $f10, $f0, $f8
/* 052AAC 7F0200BC 0FC10057 */  jal   set_color_shading_from_tile
/* 052AB0 7F0200C0 E60A0100 */   swc1  $f10, 0x100($s0)
/* 052AB4 7F0200C4 920C00F8 */  lbu   $t4, 0xf8($s0)
/* 052AB8 7F0200C8 920D00F9 */  lbu   $t5, 0xf9($s0)
/* 052ABC 7F0200CC 920E00FA */  lbu   $t6, 0xfa($s0)
/* 052AC0 7F0200D0 920F00FB */  lbu   $t7, 0xfb($s0)
/* 052AC4 7F0200D4 241800FF */  li    $t8, 255
/* 052AC8 7F0200D8 24190001 */  li    $t9, 1
/* 052ACC 7F0200DC A218000C */  sb    $t8, 0xc($s0)
/* 052AD0 7F0200E0 AE000168 */  sw    $zero, 0x168($s0)
/* 052AD4 7F0200E4 AE00016C */  sw    $zero, 0x16c($s0)
/* 052AD8 7F0200E8 AE000170 */  sw    $zero, 0x170($s0)
/* 052ADC 7F0200EC AE000174 */  sw    $zero, 0x174($s0)
/* 052AE0 7F0200F0 AE000178 */  sw    $zero, 0x178($s0)
/* 052AE4 7F0200F4 AE00017C */  sw    $zero, 0x17c($s0)
/* 052AE8 7F0200F8 AE190014 */  sw    $t9, 0x14($s0)
/* 052AEC 7F0200FC A6000012 */  sh    $zero, 0x12($s0)
/* 052AF0 7F020100 E61400A4 */  swc1  $f20, 0xa4($s0)
/* 052AF4 7F020104 E61400A8 */  swc1  $f20, 0xa8($s0)
/* 052AF8 7F020108 E61400AC */  swc1  $f20, 0xac($s0)
/* 052AFC 7F02010C E61400B0 */  swc1  $f20, 0xb0($s0)
/* 052B00 7F020110 E61400B4 */  swc1  $f20, 0xb4($s0)
/* 052B04 7F020114 E61400B8 */  swc1  $f20, 0xb8($s0)
/* 052B08 7F020118 A20C00F4 */  sb    $t4, 0xf4($s0)
/* 052B0C 7F02011C A20D00F5 */  sb    $t5, 0xf5($s0)
/* 052B10 7F020120 A20E00F6 */  sb    $t6, 0xf6($s0)
/* 052B14 7F020124 A20F00F7 */  sb    $t7, 0xf7($s0)
/* 052B18 7F020128 C6700000 */  lwc1  $f16, ($s3)
/* 052B1C 7F02012C 2402FFFF */  li    $v0, -1
/* 052B20 7F020130 3C0141A0 */  li    $at, 0x41A00000 # 20.000000
/* 052B24 7F020134 E61000BC */  swc1  $f16, 0xbc($s0)
/* 052B28 7F020138 C6720004 */  lwc1  $f18, 4($s3)
/* 052B2C 7F02013C 44813000 */  mtc1  $at, $f6
/* 052B30 7F020140 3C014339 */  li    $at, 0x43390000 # 185.000000
/* 052B34 7F020144 E61200C0 */  swc1  $f18, 0xc0($s0)
/* 052B38 7F020148 C6640008 */  lwc1  $f4, 8($s3)
/* 052B3C 7F02014C A2000007 */  sb    $zero, 7($s0)
/* 052B40 7F020150 A2000008 */  sb    $zero, 8($s0)
/* 052B44 7F020154 E60400C4 */  swc1  $f4, 0xc4($s0)
/* 052B48 7F020158 8FA80044 */  lw    $t0, 0x44($sp)
/* 052B4C 7F02015C 44814000 */  mtc1  $at, $f8
/* 052B50 7F020160 26250008 */  addiu $a1, $s1, 8
/* 052B54 7F020164 A6000108 */  sh    $zero, 0x108($s0)
/* 052B58 7F020168 A602010A */  sh    $v0, 0x10a($s0)
/* 052B5C 7F02016C A200010C */  sb    $zero, 0x10c($s0)
/* 052B60 7F020170 A200010D */  sb    $zero, 0x10d($s0)
/* 052B64 7F020174 A200010E */  sb    $zero, 0x10e($s0)
/* 052B68 7F020178 A200010F */  sb    $zero, 0x10f($s0)
/* 052B6C 7F02017C AE000110 */  sw    $zero, 0x110($s0)
/* 052B70 7F020180 A6020114 */  sh    $v0, 0x114($s0)
/* 052B74 7F020184 A6020118 */  sh    $v0, 0x118($s0)
/* 052B78 7F020188 A602011A */  sh    $v0, 0x11a($s0)
/* 052B7C 7F02018C A6020116 */  sh    $v0, 0x116($s0)
/* 052B80 7F020190 A2020180 */  sb    $v0, 0x180($s0)
/* 052B84 7F020194 A20201AC */  sb    $v0, 0x1ac($s0)
/* 052B88 7F020198 A2000004 */  sb    $zero, 4($s0)
/* 052B8C 7F02019C A2000005 */  sb    $zero, 5($s0)
/* 052B90 7F0201A0 A2000010 */  sb    $zero, 0x10($s0)
/* 052B94 7F0201A4 A2000002 */  sb    $zero, 2($s0)
/* 052B98 7F0201A8 A2000003 */  sb    $zero, 3($s0)
/* 052B9C 7F0201AC A200000D */  sb    $zero, 0xd($s0)
/* 052BA0 7F0201B0 A2020011 */  sb    $v0, 0x11($s0)
/* 052BA4 7F0201B4 E6140140 */  swc1  $f20, 0x140($s0)
/* 052BA8 7F0201B8 E6140144 */  swc1  $f20, 0x144($s0)
/* 052BAC 7F0201BC E6140148 */  swc1  $f20, 0x148($s0)
/* 052BB0 7F0201C0 E614014C */  swc1  $f20, 0x14c($s0)
/* 052BB4 7F0201C4 E6140150 */  swc1  $f20, 0x150($s0)
/* 052BB8 7F0201C8 E6140154 */  swc1  $f20, 0x154($s0)
/* 052BBC 7F0201CC E6140158 */  swc1  $f20, 0x158($s0)
/* 052BC0 7F0201D0 E614015C */  swc1  $f20, 0x15c($s0)
/* 052BC4 7F0201D4 A200000E */  sb    $zero, 0xe($s0)
/* 052BC8 7F0201D8 AE000160 */  sw    $zero, 0x160($s0)
/* 052BCC 7F0201DC AE000164 */  sw    $zero, 0x164($s0)
/* 052BD0 7F0201E0 AE0001D8 */  sw    $zero, 0x1d8($s0)
/* 052BD4 7F0201E4 00A03025 */  move  $a2, $a1
/* 052BD8 7F0201E8 02402025 */  move  $a0, $s2
/* 052BDC 7F0201EC 260700AC */  addiu $a3, $s0, 0xac
/* 052BE0 7F0201F0 E6060024 */  swc1  $f6, 0x24($s0)
/* 052BE4 7F0201F4 AE080104 */  sw    $t0, 0x104($s0)
/* 052BE8 7F0201F8 0FC07E9C */  jal   sub_GAME_7F01FC10
/* 052BEC 7F0201FC E6080028 */   swc1  $f8, 0x28($s0)
/* 052BF0 7F020200 0FC08343 */  jal   chrPositionRelated7F020D94
/* 052BF4 7F020204 02002025 */   move  $a0, $s0
/* 052BF8 7F020208 8FBF002C */  lw    $ra, 0x2c($sp)
/* 052BFC 7F02020C 02201025 */  move  $v0, $s1
/* 052C00 7F020210 8FB10020 */  lw    $s1, 0x20($sp)
/* 052C04 7F020214 D7B40010 */  ldc1  $f20, 0x10($sp)
/* 052C08 7F020218 8FB0001C */  lw    $s0, 0x1c($sp)
/* 052C0C 7F02021C 8FB20024 */  lw    $s2, 0x24($sp)
/* 052C10 7F020220 8FB30028 */  lw    $s3, 0x28($sp)
/* 052C14 7F020224 03E00008 */  jr    $ra
/* 052C18 7F020228 27BD0030 */   addiu $sp, $sp, 0x30
)
#endif
#endif



/**
 * Address 0x7F0203B8.
 */
PropRecord * replace_GUARDdata_with_actual_values( Model * arg0, coord3d * arg1, f32 arg2,  StandTile * arg3, s32 arg4)
{
    PropRecord * ret;
    s32 phi_a0;

    ret = chrpropAllocate();

    if (ret != 0)
    {
        ret = init_GUARDdata_with_set_values(ret, arg0, arg1, arg2, arg3, arg4);
    }

    return ret;
}




#ifdef NONMATCHING
/**
 * Address 0x7F020414.
 * 
 * decomp status:
 * - compiles: yes
 * - stack resize: ok
 * - identical instructions: fail
 * - identical registers: fail
 * 
 * notes: something isn't right around the area the nextSibling pointer is iterated.
 */
void disable_sounds_attached_to_player_then_something(PropRecord *prop)
{
    PropRecord *p;
    ChrRecord *chr;
    struct object_standard *model;
    
    chr = prop->chr;
    model = chr->model;

    if ((chr->ptr_SEbuffer1 != NULL) && (sndGetPlayingState(chr->ptr_SEbuffer1) != 0))
    {
        sndDeactivate(chr->ptr_SEbuffer1);
    }

    if ((chr->ptr_SEbuffer2 != NULL) && (sndGetPlayingState(chr->ptr_SEbuffer2) != 0))
    {
        sndDeactivate(chr->ptr_SEbuffer2);
    }

    if ((chr->ptr_SEbuffer3 != NULL) && (sndGetPlayingState(chr->ptr_SEbuffer3) != 0))
    {
        sndDeactivate(chr->ptr_SEbuffer3);
    }

    if ((chr->ptr_SEbuffer4 != NULL) && (sndGetPlayingState(chr->ptr_SEbuffer4) != 0))
    {
        sndDeactivate(chr->ptr_SEbuffer4);
    }

    sub_GAME_7F050DE8(model);
    chrpropDeregisterRooms(prop);

    p = prop->child;
    while (p != NULL)
    {
        sub_GAME_7F04C044(p);
        objFreePermanently(p->chr, 1);
        p = p->nextSibling;
    }

    set_aircraft_obj_inst_scale_to_zero(model);

    chr->model = NULL;
    chr->chrnum = -1;
    if (chr->field_20 != NULL)
    {
        sub_GAME_7F06B248(chr->field_20);
    }
}
#else
GLOBAL_ASM(
.text
glabel disable_sounds_attached_to_player_then_something
/* 054F44 7F020414 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 054F48 7F020418 AFBF0024 */  sw    $ra, 0x24($sp)
/* 054F4C 7F02041C AFB20020 */  sw    $s2, 0x20($sp)
/* 054F50 7F020420 AFB1001C */  sw    $s1, 0x1c($sp)
/* 054F54 7F020424 AFB00018 */  sw    $s0, 0x18($sp)
/* 054F58 7F020428 8C920004 */  lw    $s2, 4($a0)
/* 054F5C 7F02042C 00808025 */  move  $s0, $a0
/* 054F60 7F020430 8E4E001C */  lw    $t6, 0x1c($s2)
/* 054F64 7F020434 AFAE0028 */  sw    $t6, 0x28($sp)
/* 054F68 7F020438 8E450168 */  lw    $a1, 0x168($s2)
/* 054F6C 7F02043C 50A00008 */  beql  $a1, $zero, .L7F020460
/* 054F70 7F020440 8E44016C */   lw    $a0, 0x16c($s2)
/* 054F74 7F020444 0C00237C */  jal   sndGetPlayingState
/* 054F78 7F020448 00A02025 */   move  $a0, $a1
/* 054F7C 7F02044C 50400004 */  beql  $v0, $zero, .L7F020460
/* 054F80 7F020450 8E44016C */   lw    $a0, 0x16c($s2)
/* 054F84 7F020454 0C002408 */  jal   sndDeactivate
/* 054F88 7F020458 8E440168 */   lw    $a0, 0x168($s2)
/* 054F8C 7F02045C 8E44016C */  lw    $a0, 0x16c($s2)
.L7F020460:
/* 054F90 7F020460 50800008 */  beql  $a0, $zero, .L7F020484
/* 054F94 7F020464 8E440170 */   lw    $a0, 0x170($s2)
/* 054F98 7F020468 0C00237C */  jal   sndGetPlayingState
/* 054F9C 7F02046C 00000000 */   nop   
/* 054FA0 7F020470 50400004 */  beql  $v0, $zero, .L7F020484
/* 054FA4 7F020474 8E440170 */   lw    $a0, 0x170($s2)
/* 054FA8 7F020478 0C002408 */  jal   sndDeactivate
/* 054FAC 7F02047C 8E44016C */   lw    $a0, 0x16c($s2)
/* 054FB0 7F020480 8E440170 */  lw    $a0, 0x170($s2)
.L7F020484:
/* 054FB4 7F020484 50800008 */  beql  $a0, $zero, .L7F0204A8
/* 054FB8 7F020488 8E440174 */   lw    $a0, 0x174($s2)
/* 054FBC 7F02048C 0C00237C */  jal   sndGetPlayingState
/* 054FC0 7F020490 00000000 */   nop   
/* 054FC4 7F020494 50400004 */  beql  $v0, $zero, .L7F0204A8
/* 054FC8 7F020498 8E440174 */   lw    $a0, 0x174($s2)
/* 054FCC 7F02049C 0C002408 */  jal   sndDeactivate
/* 054FD0 7F0204A0 8E440170 */   lw    $a0, 0x170($s2)
/* 054FD4 7F0204A4 8E440174 */  lw    $a0, 0x174($s2)
.L7F0204A8:
/* 054FD8 7F0204A8 10800007 */  beqz  $a0, .L7F0204C8
/* 054FDC 7F0204AC 00000000 */   nop   
/* 054FE0 7F0204B0 0C00237C */  jal   sndGetPlayingState
/* 054FE4 7F0204B4 00000000 */   nop   
/* 054FE8 7F0204B8 10400003 */  beqz  $v0, .L7F0204C8
/* 054FEC 7F0204BC 00000000 */   nop   
/* 054FF0 7F0204C0 0C002408 */  jal   sndDeactivate
/* 054FF4 7F0204C4 8E440174 */   lw    $a0, 0x174($s2)
.L7F0204C8:
/* 054FF8 7F0204C8 0FC1437A */  jal   sub_GAME_7F050DE8
/* 054FFC 7F0204CC 8FA40028 */   lw    $a0, 0x28($sp)
/* 055000 7F0204D0 0FC0F863 */  jal   chrpropDeregisterRooms
/* 055004 7F0204D4 02002025 */   move  $a0, $s0
/* 055008 7F0204D8 8E040020 */  lw    $a0, 0x20($s0)
/* 05500C 7F0204DC 10800009 */  beqz  $a0, .L7F020504
/* 055010 7F0204E0 00000000 */   nop   
.L7F0204E4:
/* 055014 7F0204E4 8C910004 */  lw    $s1, 4($a0)
/* 055018 7F0204E8 0FC13011 */  jal   sub_GAME_7F04C044
/* 05501C 7F0204EC 8C900024 */   lw    $s0, 0x24($a0)
/* 055020 7F0204F0 02202025 */  move  $a0, $s1
/* 055024 7F0204F4 0FC10409 */  jal   objFreePermanently
/* 055028 7F0204F8 24050001 */   li    $a1, 1
/* 05502C 7F0204FC 1600FFF9 */  bnez  $s0, .L7F0204E4
/* 055030 7F020500 02002025 */   move  $a0, $s0
.L7F020504:
/* 055034 7F020504 0FC1B0FE */  jal   set_aircraft_obj_inst_scale_to_zero
/* 055038 7F020508 8FA40028 */   lw    $a0, 0x28($sp)
/* 05503C 7F02050C 8E440020 */  lw    $a0, 0x20($s2)
/* 055040 7F020510 240FFFFF */  li    $t7, -1
/* 055044 7F020514 AE40001C */  sw    $zero, 0x1c($s2)
/* 055048 7F020518 10800003 */  beqz  $a0, .L7F020528
/* 05504C 7F02051C A64F0000 */   sh    $t7, ($s2)
/* 055050 7F020520 0FC1AC92 */  jal   sub_GAME_7F06B248
/* 055054 7F020524 00000000 */   nop   
.L7F020528:
/* 055058 7F020528 8FBF0024 */  lw    $ra, 0x24($sp)
/* 05505C 7F02052C 8FB00018 */  lw    $s0, 0x18($sp)
/* 055060 7F020530 8FB1001C */  lw    $s1, 0x1c($sp)
/* 055064 7F020534 8FB20020 */  lw    $s2, 0x20($sp)
/* 055068 7F020538 03E00008 */  jr    $ra
/* 05506C 7F02053C 27BD0030 */   addiu $sp, $sp, 0x30
)
#endif



/**
 * Address 0x7F020540 (VERSION_US, VERSION_JP).
 * Address 0x7F0203B4 (VERSION_EU).
 */
void animation_speed_related(f32 arg0)
{
    s32 i;

    animation_rate = arg0;

    for (i=0; i<num_guards; i++)
    {
        if (ptr_guard_data[i].model != NULL)
        {
#if defined(REFRESH_PAL)
/* should reference D_80047E4C (1.2f) */
            sub_GAME_7F06FF18(ptr_guard_data[i].model, animation_rate * 1.2f, 600.0f);
#else
            sub_GAME_7F06FF18(ptr_guard_data[i].model, animation_rate, 600.0f);
#endif
        }
    }
}




f32 get_animation_rate(void)
{
  return animation_rate;
}



/**
 * Address 0x7F0205F0 (all versions).
 */
void chrAimGlobalTimerTickRelated( ChrRecord *self)
{
    f32 temp_f0;

    if (self->aimendcount >= 2)
    {
#if defined(BUGFIX_R1)
        temp_f0 = g_JP_GlobalTimerDelta / (f32) self->aimendcount;
#else
        temp_f0 = g_GlobalTimerDelta / (f32) self->aimendcount;
#endif
        
        if (temp_f0 > 1.0f)
        {
            temp_f0 = 1.0f;
        }

        self->aimuplshoulder += ((self->aimendlshoulder - self->aimuplshoulder) * temp_f0);
        self->aimuprshoulder += ((self->aimendrshoulder - self->aimuprshoulder) * temp_f0);
        self->aimupback += ((self->aimendback - self->aimupback) * temp_f0);
        self->aimsideback += ((self->aimendsideback - self->aimsideback) * temp_f0);
        self->aimendcount -= g_ClockTimer;

        return;
    }

    self->aimuplshoulder = self->aimendlshoulder;
    self->aimuprshoulder = self->aimendrshoulder;
    self->aimupback = self->aimendback;
    self->aimsideback = self->aimendsideback;
}



/**
 * Address 0x7F0206D4.
 */
void chrSetHiddenToRandom(ChrRecord *self)
{
    ChrRecord *temp_a0;
    u32 rand;

    if ((s32) self->flinchcnt < 0)
    {
        self->flinchcnt = 1;
        self->hidden &= 0xFFF;
        
        // roll for bits 12,13.
        // rand -> value
        // 2 => nothing
        // 0 => set bit 12
        // 1 => set bit 13
        rand = randomGetNext() % 3U;
        
        if (rand == 0)
        {
            self->hidden |= 0x1000;
        }
        else if (rand == 1)
        {
            self->hidden |= 0x2000;
        }

        // roll for bits 14,15.
        // rand -> value
        // 2 => nothing
        // 0 => set bit 14
        // 1 => set bit 15
        rand = randomGetNext() % 3U;
        
        if (rand == 0)
        {
            self->hidden |= 0x4000;
        }
        else if (rand == 1)
        {
            self->hidden |= 0x8000;
        }
    }
}




#ifdef NONMATCHING
/**
 * Address 0x7F020794.
 */
f32 sub_GAME_7F020794(ChrRecord *arg0)
{
    // this method matches, but references D_80051D28,D_80051D2C
    // for the M_TAU_F variable.

    f32 temp_f2;
    f32 phi_f2;

    temp_f2 = (f32) arg0->flinchcnt;

    if (temp_f2 < 10.0f)
    {
        phi_f2 = sinf((temp_f2 * M_TAU_F * 0.25f) / 10.0f);
    }
    else
    {
        phi_f2 = 1.0f - sinf(((temp_f2 - 10.0f) * M_TAU_F * 0.25f) / 20.0f);
    }

    return phi_f2;
}
#else

#if defined(LEFTOVERDEBUG)
GLOBAL_ASM(
.text
glabel sub_GAME_7F020794
/* 0552C4 7F020794 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0552C8 7F020798 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0552CC 7F02079C 808E0011 */  lb    $t6, 0x11($a0)
/* 0552D0 7F0207A0 3C014120 */  li    $at, 0x41200000 # 10.000000
/* 0552D4 7F0207A4 44810000 */  mtc1  $at, $f0
/* 0552D8 7F0207A8 448E2000 */  mtc1  $t6, $f4
/* 0552DC 7F0207AC 3C018005 */  lui   $at, %hi(D_80051D2C)
/* 0552E0 7F0207B0 468020A0 */  cvt.s.w $f2, $f4
/* 0552E4 7F0207B4 4600103C */  c.lt.s $f2, $f0
/* 0552E8 7F0207B8 00000000 */  nop   
/* 0552EC 7F0207BC 4502000D */  bc1fl .L7F0207F4
/* 0552F0 7F0207C0 46001481 */   sub.s $f18, $f2, $f0
/* 0552F4 7F0207C4 3C018005 */  lui   $at, %hi(D_80051D28)
/* 0552F8 7F0207C8 C4261D28 */  lwc1  $f6, %lo(D_80051D28)($at)
/* 0552FC 7F0207CC 3C013E80 */  li    $at, 0x3E800000 # 0.250000
/* 055300 7F0207D0 44815000 */  mtc1  $at, $f10
/* 055304 7F0207D4 46061202 */  mul.s $f8, $f2, $f6
/* 055308 7F0207D8 00000000 */  nop   
/* 05530C 7F0207DC 460A4402 */  mul.s $f16, $f8, $f10
/* 055310 7F0207E0 0FC15FAB */  jal   sinf
/* 055314 7F0207E4 46008303 */   div.s $f12, $f16, $f0
/* 055318 7F0207E8 1000000F */  b     .L7F020828
/* 05531C 7F0207EC 46000086 */   mov.s $f2, $f0
/* 055320 7F0207F0 46001481 */  sub.s $f18, $f2, $f0
.L7F0207F4:
/* 055324 7F0207F4 C4241D2C */  lwc1  $f4, %lo(D_80051D2C)($at)
/* 055328 7F0207F8 3C013E80 */  li    $at, 0x3E800000 # 0.250000
/* 05532C 7F0207FC 44814000 */  mtc1  $at, $f8
/* 055330 7F020800 46049182 */  mul.s $f6, $f18, $f4
/* 055334 7F020804 3C0141A0 */  li    $at, 0x41A00000 # 20.000000
/* 055338 7F020808 44818000 */  mtc1  $at, $f16
/* 05533C 7F02080C 46083282 */  mul.s $f10, $f6, $f8
/* 055340 7F020810 0FC15FAB */  jal   sinf
/* 055344 7F020814 46105303 */   div.s $f12, $f10, $f16
/* 055348 7F020818 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 05534C 7F02081C 44819000 */  mtc1  $at, $f18
/* 055350 7F020820 00000000 */  nop   
/* 055354 7F020824 46009081 */  sub.s $f2, $f18, $f0
.L7F020828:
/* 055358 7F020828 8FBF0014 */  lw    $ra, 0x14($sp)
/* 05535C 7F02082C 27BD0018 */  addiu $sp, $sp, 0x18
/* 055360 7F020830 46001006 */  mov.s $f0, $f2
/* 055364 7F020834 03E00008 */  jr    $ra
/* 055368 7F020838 00000000 */   nop   
)
#endif

#if !defined(LEFTOVERDEBUG)
GLOBAL_ASM(
.late_rodata
glabel D_80051D28
.word 0x40c90fdb /*6.2831855*/
glabel D_80051D2C
.word 0x40c90fdb /*6.2831855*/

.text
glabel sub_GAME_7F020794
/* 053014 7F020624 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 053018 7F020628 AFBF0014 */  sw    $ra, 0x14($sp)
/* 05301C 7F02062C 808E0011 */  lb    $t6, 0x11($a0)
/* 053020 7F020630 3C014100 */  li    $at, 0x41000000 # 8.000000
/* 053024 7F020634 44810000 */  mtc1  $at, $f0
/* 053028 7F020638 448E2000 */  mtc1  $t6, $f4
/* 05302C 7F02063C 3C018004 */  lui   $at, %hi(D_80051D2C)
/* 053030 7F020640 468020A0 */  cvt.s.w $f2, $f4
/* 053034 7F020644 4600103C */  c.lt.s $f2, $f0
/* 053038 7F020648 00000000 */  nop   
/* 05303C 7F02064C 4502000D */  bc1fl .L7F020684
/* 053040 7F020650 46001481 */   sub.s $f18, $f2, $f0
/* 053044 7F020654 3C018004 */  lui   $at, %hi(D_80051D28) # $at, 0x8004
/* 053048 7F020658 C4267E50 */  lwc1  $f6, %lo(D_80051D28)($at)
/* 05304C 7F02065C 3C013E80 */  li    $at, 0x3E800000 # 0.250000
/* 053050 7F020660 44815000 */  mtc1  $at, $f10
/* 053054 7F020664 46061202 */  mul.s $f8, $f2, $f6
/* 053058 7F020668 00000000 */  nop   
/* 05305C 7F02066C 460A4402 */  mul.s $f16, $f8, $f10
/* 053060 7F020670 0FC1606B */  jal   sinf
/* 053064 7F020674 46008303 */   div.s $f12, $f16, $f0
/* 053068 7F020678 1000000F */  b     .L7F0206B8
/* 05306C 7F02067C 46000086 */   mov.s $f2, $f0
/* 053070 7F020680 46001481 */  sub.s $f18, $f2, $f0
.L7F020684:
/* 053074 7F020684 C4247E54 */  lwc1  $f4, %lo(D_80051D2C)($at)
/* 053078 7F020688 3C013E80 */  li    $at, 0x3E800000 # 0.250000
/* 05307C 7F02068C 44814000 */  mtc1  $at, $f8
/* 053080 7F020690 46049182 */  mul.s $f6, $f18, $f4
/* 053084 7F020694 3C014180 */  li    $at, 0x41800000 # 16.000000
/* 053088 7F020698 44818000 */  mtc1  $at, $f16
/* 05308C 7F02069C 46083282 */  mul.s $f10, $f6, $f8
/* 053090 7F0206A0 0FC1606B */  jal   sinf
/* 053094 7F0206A4 46105303 */   div.s $f12, $f10, $f16
/* 053098 7F0206A8 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 05309C 7F0206AC 44819000 */  mtc1  $at, $f18
/* 0530A0 7F0206B0 00000000 */  nop   
/* 0530A4 7F0206B4 46009081 */  sub.s $f2, $f18, $f0
.L7F0206B8:
/* 0530A8 7F0206B8 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0530AC 7F0206BC 27BD0018 */  addiu $sp, $sp, 0x18
/* 0530B0 7F0206C0 46001006 */  mov.s $f0, $f2
/* 0530B4 7F0206C4 03E00008 */  jr    $ra
/* 0530B8 7F0206C8 00000000 */   nop   
)
#endif
#endif

#ifdef BUGFIX_R1
s32 not_in_us_7F0209EC(s32 bodynum, s32 headnum)
{
    if (j_text_trigger == 0)
    {
        return 1;
    }

    if ((bodynum != 6) && (bodynum != 7) && (bodynum != 8) && (bodynum != 9) && (bodynum != 0xA) && (bodynum != 0xB) && (bodynum != 0xC) && (bodynum != 0xD) && (bodynum != 0xE) && (bodynum != 0xF) && (bodynum != 0x10) && (bodynum != 0x4F) 
        && (headnum != 0x4A) && (headnum != 0x4B) && (headnum != 0x4C) && (headnum != 0x4D) && (headnum != 0x4E) && (headnum != 0x45))
    {
        return 1;
    }

    return 0;
}
#endif





#ifdef NONMATCHING
void sub_GAME_7F02083C(void) {

}
#else

#ifdef VERSION_US
GLOBAL_ASM(
.text
glabel sub_GAME_7F02083C
/* 05536C 7F02083C 27BDFF68 */  addiu $sp, $sp, -0x98
/* 055370 7F020840 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 055374 7F020844 44812000 */  mtc1  $at, $f4
/* 055378 7F020848 AFBF0014 */  sw    $ra, 0x14($sp)
/* 05537C 7F02084C 00803025 */  move  $a2, $a0
/* 055380 7F020850 AFA5009C */  sw    $a1, 0x9c($sp)
/* 055384 7F020854 AFA60098 */  sw    $a2, 0x98($sp)
/* 055388 7F020858 2404000C */  li    $a0, 12
/* 05538C 7F02085C 0FC249EF */  jal   cheatIsActive
/* 055390 7F020860 E7A40094 */   swc1  $f4, 0x94($sp)
/* 055394 7F020864 1040000E */  beqz  $v0, .L7F0208A0
/* 055398 7F020868 8FA60098 */   lw    $a2, 0x98($sp)
/* 05539C 7F02086C 14C00005 */  bnez  $a2, .L7F020884
/* 0553A0 7F020870 24030002 */   li    $v1, 2
/* 0553A4 7F020874 3C014080 */  li    $at, 0x40800000 # 4.000000
/* 0553A8 7F020878 44813000 */  mtc1  $at, $f6
/* 0553AC 7F02087C 10000008 */  b     .L7F0208A0
/* 0553B0 7F020880 E7A60094 */   swc1  $f6, 0x94($sp)
.L7F020884:
/* 0553B4 7F020884 10C30002 */  beq   $a2, $v1, .L7F020890
/* 0553B8 7F020888 24050003 */   li    $a1, 3
/* 0553BC 7F02088C 14C50004 */  bne   $a2, $a1, .L7F0208A0
.L7F020890:
/* 0553C0 7F020890 3C014020 */   li    $at, 0x40200000 # 2.500000
/* 0553C4 7F020894 44814000 */  mtc1  $at, $f8
/* 0553C8 7F020898 00000000 */  nop   
/* 0553CC 7F02089C E7A80094 */  swc1  $f8, 0x94($sp)
.L7F0208A0:
/* 0553D0 7F0208A0 24030002 */  li    $v1, 2
/* 0553D4 7F0208A4 10C30007 */  beq   $a2, $v1, .L7F0208C4
/* 0553D8 7F0208A8 24050003 */   li    $a1, 3
/* 0553DC 7F0208AC 10C50005 */  beq   $a2, $a1, .L7F0208C4
/* 0553E0 7F0208B0 24070001 */   li    $a3, 1
/* 0553E4 7F0208B4 50C70004 */  beql  $a2, $a3, .L7F0208C8
/* 0553E8 7F0208B8 44809000 */   mtc1  $zero, $f18
/* 0553EC 7F0208BC 54C00132 */  bnezl $a2, .L7F020D88
/* 0553F0 7F0208C0 8FBF0014 */   lw    $ra, 0x14($sp)
.L7F0208C4:
/* 0553F4 7F0208C4 44809000 */  mtc1  $zero, $f18
.L7F0208C8:
/* 0553F8 7F0208C8 24070001 */  li    $a3, 1
/* 0553FC 7F0208CC 3C0E8007 */  lui   $t6, %hi(dword_CODE_bss_80069B60) 
/* 055400 7F0208D0 46009386 */  mov.s $f14, $f18
/* 055404 7F0208D4 46009306 */  mov.s $f12, $f18
/* 055408 7F0208D8 14C50004 */  bne   $a2, $a1, .L7F0208EC
/* 05540C 7F0208DC E7B20088 */   swc1  $f18, 0x88($sp)
/* 055410 7F0208E0 8DCE9B60 */  lw    $t6, %lo(dword_CODE_bss_80069B60)($t6)
/* 055414 7F0208E4 10000043 */  b     .L7F0209F4
/* 055418 7F0208E8 C5CE0144 */   lwc1  $f14, 0x144($t6)
.L7F0208EC:
/* 05541C 7F0208EC 14C30004 */  bne   $a2, $v1, .L7F020900
/* 055420 7F0208F0 3C0F8007 */   lui   $t7, %hi(dword_CODE_bss_80069B60) 
/* 055424 7F0208F4 8DEF9B60 */  lw    $t7, %lo(dword_CODE_bss_80069B60)($t7)
/* 055428 7F0208F8 1000003E */  b     .L7F0209F4
/* 05542C 7F0208FC C5EE0140 */   lwc1  $f14, 0x140($t7)
.L7F020900:
/* 055430 7F020900 14C7001C */  bne   $a2, $a3, .L7F020974
/* 055434 7F020904 3C048007 */   lui   $a0, %hi(dword_CODE_bss_80069B60)
/* 055438 7F020908 8C849B60 */  lw    $a0, %lo(dword_CODE_bss_80069B60)($a0)
/* 05543C 7F02090C 3C018005 */  lui   $at, %hi(D_80051D30)
/* 055440 7F020910 94980012 */  lhu   $t8, 0x12($a0)
/* 055444 7F020914 C48E0148 */  lwc1  $f14, 0x148($a0)
/* 055448 7F020918 33190400 */  andi  $t9, $t8, 0x400
/* 05544C 7F02091C 13200013 */  beqz  $t9, .L7F02096C
/* 055450 7F020920 00000000 */   nop   
/* 055454 7F020924 C4201D30 */  lwc1  $f0, %lo(D_80051D30)($at)
/* 055458 7F020928 3C018005 */  lui   $at, %hi(D_80051D34)
/* 05545C 7F02092C 460E003C */  c.lt.s $f0, $f14
/* 055460 7F020930 00000000 */  nop   
/* 055464 7F020934 45000003 */  bc1f  .L7F020944
/* 055468 7F020938 00000000 */   nop   
/* 05546C 7F02093C 1000000B */  b     .L7F02096C
/* 055470 7F020940 46007381 */   sub.s $f14, $f14, $f0
.L7F020944:
/* 055474 7F020944 C4201D34 */  lwc1  $f0, %lo(D_80051D34)($at)
/* 055478 7F020948 3C018005 */  lui   $at, %hi(D_80051D38)
/* 05547C 7F02094C 4600703C */  c.lt.s $f14, $f0
/* 055480 7F020950 00000000 */  nop   
/* 055484 7F020954 45020005 */  bc1fl .L7F02096C
/* 055488 7F020958 46009386 */   mov.s $f14, $f18
/* 05548C 7F02095C C42A1D38 */  lwc1  $f10, %lo(D_80051D38)($at)
/* 055490 7F020960 10000002 */  b     .L7F02096C
/* 055494 7F020964 460A7380 */   add.s $f14, $f14, $f10
/* 055498 7F020968 46009386 */  mov.s $f14, $f18
.L7F02096C:
/* 05549C 7F02096C 10000021 */  b     .L7F0209F4
/* 0554A0 7F020970 C48C014C */   lwc1  $f12, 0x14c($a0)
.L7F020974:
/* 0554A4 7F020974 14C0001F */  bnez  $a2, .L7F0209F4
/* 0554A8 7F020978 3C048007 */   lui   $a0, %hi(dword_CODE_bss_80069B60)
/* 0554AC 7F02097C 8C849B60 */  lw    $a0, %lo(dword_CODE_bss_80069B60)($a0)
/* 0554B0 7F020980 94820012 */  lhu   $v0, 0x12($a0)
/* 0554B4 7F020984 30480400 */  andi  $t0, $v0, 0x400
/* 0554B8 7F020988 51000014 */  beql  $t0, $zero, .L7F0209DC
/* 0554BC 7F02098C 8C89001C */   lw    $t1, 0x1c($a0)
/* 0554C0 7F020990 11000018 */  beqz  $t0, .L7F0209F4
/* 0554C4 7F020994 C48E0148 */   lwc1  $f14, 0x148($a0)
/* 0554C8 7F020998 3C018005 */  lui   $at, %hi(D_80051D3C)
/* 0554CC 7F02099C C4201D3C */  lwc1  $f0, %lo(D_80051D3C)($at)
/* 0554D0 7F0209A0 3C018005 */  lui   $at, %hi(D_80051D40)
/* 0554D4 7F0209A4 460E003C */  c.lt.s $f0, $f14
/* 0554D8 7F0209A8 00000000 */  nop   
/* 0554DC 7F0209AC 45000003 */  bc1f  .L7F0209BC
/* 0554E0 7F0209B0 00000000 */   nop   
/* 0554E4 7F0209B4 1000000F */  b     .L7F0209F4
/* 0554E8 7F0209B8 46000386 */   mov.s $f14, $f0
.L7F0209BC:
/* 0554EC 7F0209BC C4201D40 */  lwc1  $f0, %lo(D_80051D40)($at)
/* 0554F0 7F0209C0 4600703C */  c.lt.s $f14, $f0
/* 0554F4 7F0209C4 00000000 */  nop   
/* 0554F8 7F0209C8 4500000A */  bc1f  .L7F0209F4
/* 0554FC 7F0209CC 00000000 */   nop   
/* 055500 7F0209D0 10000008 */  b     .L7F0209F4
/* 055504 7F0209D4 46000386 */   mov.s $f14, $f0
/* 055508 7F0209D8 8C89001C */  lw    $t1, 0x1c($a0)
.L7F0209DC:
/* 05550C 7F0209DC 812A0024 */  lb    $t2, 0x24($t1)
/* 055510 7F0209E0 51400004 */  beql  $t2, $zero, .L7F0209F4
/* 055514 7F0209E4 C48E0144 */   lwc1  $f14, 0x144($a0)
/* 055518 7F0209E8 10000002 */  b     .L7F0209F4
/* 05551C 7F0209EC C48E0140 */   lwc1  $f14, 0x140($a0)
/* 055520 7F0209F0 C48E0144 */  lwc1  $f14, 0x144($a0)
.L7F0209F4:
/* 055524 7F0209F4 3C048007 */  lui   $a0, %hi(dword_CODE_bss_80069B60)
/* 055528 7F0209F8 8C849B60 */  lw    $a0, %lo(dword_CODE_bss_80069B60)($a0)
/* 05552C 7F0209FC 808B0011 */  lb    $t3, 0x11($a0)
/* 055530 7F020A00 05620055 */  bltzl $t3, .L7F020B58
/* 055534 7F020A04 46127032 */   c.eq.s $f14, $f18
/* 055538 7F020A08 50C50004 */  beql  $a2, $a1, .L7F020A1C
/* 05553C 7F020A0C E7AC008C */   swc1  $f12, 0x8c($sp)
/* 055540 7F020A10 14C3001D */  bne   $a2, $v1, .L7F020A88
/* 055544 7F020A14 00000000 */   nop   
/* 055548 7F020A18 E7AC008C */  swc1  $f12, 0x8c($sp)
.L7F020A1C:
/* 05554C 7F020A1C 0FC081E5 */  jal   sub_GAME_7F020794
/* 055550 7F020A20 E7AE0090 */   swc1  $f14, 0x90($sp)
/* 055554 7F020A24 3C018005 */  lui   $at, %hi(D_80051D44)
/* 055558 7F020A28 C4241D44 */  lwc1  $f4, %lo(D_80051D44)($at)
/* 05555C 7F020A2C 3C014170 */  li    $at, 0x41700000 # 15.000000
/* 055560 7F020A30 44814000 */  mtc1  $at, $f8
/* 055564 7F020A34 46040182 */  mul.s $f6, $f0, $f4
/* 055568 7F020A38 3C0143B4 */  li    $at, 0x43B40000 # 360.000000
/* 05556C 7F020A3C 44812000 */  mtc1  $at, $f4
/* 055570 7F020A40 3C048007 */  lui   $a0, %hi(dword_CODE_bss_80069B60)
/* 055574 7F020A44 8C849B60 */  lw    $a0, %lo(dword_CODE_bss_80069B60)($a0)
/* 055578 7F020A48 C7AE0090 */  lwc1  $f14, 0x90($sp)
/* 05557C 7F020A4C 44809000 */  mtc1  $zero, $f18
/* 055580 7F020A50 46083282 */  mul.s $f10, $f6, $f8
/* 055584 7F020A54 94820012 */  lhu   $v0, 0x12($a0)
/* 055588 7F020A58 C7AC008C */  lwc1  $f12, 0x8c($sp)
/* 05558C 7F020A5C 304C1000 */  andi  $t4, $v0, 0x1000
/* 055590 7F020A60 304D2000 */  andi  $t5, $v0, 0x2000
/* 055594 7F020A64 46045083 */  div.s $f2, $f10, $f4
/* 055598 7F020A68 11800003 */  beqz  $t4, .L7F020A78
/* 05559C 7F020A6C 46027381 */   sub.s $f14, $f14, $f2
/* 0555A0 7F020A70 10000038 */  b     .L7F020B54
/* 0555A4 7F020A74 46026301 */   sub.s $f12, $f12, $f2
.L7F020A78:
/* 0555A8 7F020A78 51A00037 */  beql  $t5, $zero, .L7F020B58
/* 0555AC 7F020A7C 46127032 */   c.eq.s $f14, $f18
/* 0555B0 7F020A80 10000034 */  b     .L7F020B54
/* 0555B4 7F020A84 46026300 */   add.s $f12, $f12, $f2
.L7F020A88:
/* 0555B8 7F020A88 54C70033 */  bnel  $a2, $a3, .L7F020B58
/* 0555BC 7F020A8C 46127032 */   c.eq.s $f14, $f18
/* 0555C0 7F020A90 E7AC008C */  swc1  $f12, 0x8c($sp)
/* 0555C4 7F020A94 0FC081E5 */  jal   sub_GAME_7F020794
/* 0555C8 7F020A98 E7AE0090 */   swc1  $f14, 0x90($sp)
/* 0555CC 7F020A9C 3C018005 */  lui   $at, %hi(D_80051D48)
/* 0555D0 7F020AA0 C4261D48 */  lwc1  $f6, %lo(D_80051D48)($at)
/* 0555D4 7F020AA4 3C014170 */  li    $at, 0x41700000 # 15.000000
/* 0555D8 7F020AA8 44814000 */  mtc1  $at, $f8
/* 0555DC 7F020AAC 46060402 */  mul.s $f16, $f0, $f6
/* 0555E0 7F020AB0 3C0143B4 */  li    $at, 0x43B40000 # 360.000000
/* 0555E4 7F020AB4 44812000 */  mtc1  $at, $f4
/* 0555E8 7F020AB8 3C048007 */  lui   $a0, %hi(dword_CODE_bss_80069B60)
/* 0555EC 7F020ABC 8C849B60 */  lw    $a0, %lo(dword_CODE_bss_80069B60)($a0)
/* 0555F0 7F020AC0 C7AE0090 */  lwc1  $f14, 0x90($sp)
/* 0555F4 7F020AC4 44809000 */  mtc1  $zero, $f18
/* 0555F8 7F020AC8 46088282 */  mul.s $f10, $f16, $f8
/* 0555FC 7F020ACC 94820012 */  lhu   $v0, 0x12($a0)
/* 055600 7F020AD0 C7AC008C */  lwc1  $f12, 0x8c($sp)
/* 055604 7F020AD4 3C014120 */  li    $at, 0x41200000 # 10.000000
/* 055608 7F020AD8 304E1000 */  andi  $t6, $v0, 0x1000
/* 05560C 7F020ADC 304F2000 */  andi  $t7, $v0, 0x2000
/* 055610 7F020AE0 30584000 */  andi  $t8, $v0, 0x4000
/* 055614 7F020AE4 46045083 */  div.s $f2, $f10, $f4
/* 055618 7F020AE8 30598000 */  andi  $t9, $v0, 0x8000
/* 05561C 7F020AEC 11C00003 */  beqz  $t6, .L7F020AFC
/* 055620 7F020AF0 46027380 */   add.s $f14, $f14, $f2
/* 055624 7F020AF4 10000004 */  b     .L7F020B08
/* 055628 7F020AF8 46026300 */   add.s $f12, $f12, $f2
.L7F020AFC:
/* 05562C 7F020AFC 11E00002 */  beqz  $t7, .L7F020B08
/* 055630 7F020B00 00000000 */   nop   
/* 055634 7F020B04 46026301 */  sub.s $f12, $f12, $f2
.L7F020B08:
/* 055638 7F020B08 13000009 */  beqz  $t8, .L7F020B30
/* 05563C 7F020B0C 00000000 */   nop   
/* 055640 7F020B10 44813000 */  mtc1  $at, $f6
/* 055644 7F020B14 3C0143B4 */  li    $at, 0x43B40000 # 360.000000
/* 055648 7F020B18 44815000 */  mtc1  $at, $f10
/* 05564C 7F020B1C 46068202 */  mul.s $f8, $f16, $f6
/* 055650 7F020B20 460A4103 */  div.s $f4, $f8, $f10
/* 055654 7F020B24 46049180 */  add.s $f6, $f18, $f4
/* 055658 7F020B28 1000000A */  b     .L7F020B54
/* 05565C 7F020B2C E7A60088 */   swc1  $f6, 0x88($sp)
.L7F020B30:
/* 055660 7F020B30 13200008 */  beqz  $t9, .L7F020B54
/* 055664 7F020B34 3C014120 */   li    $at, 0x41200000 # 10.000000
/* 055668 7F020B38 44814000 */  mtc1  $at, $f8
/* 05566C 7F020B3C 3C0143B4 */  li    $at, 0x43B40000 # 360.000000
/* 055670 7F020B40 44812000 */  mtc1  $at, $f4
/* 055674 7F020B44 46088282 */  mul.s $f10, $f16, $f8
/* 055678 7F020B48 46045183 */  div.s $f6, $f10, $f4
/* 05567C 7F020B4C 46069201 */  sub.s $f8, $f18, $f6
/* 055680 7F020B50 E7A80088 */  swc1  $f8, 0x88($sp)
.L7F020B54:
/* 055684 7F020B54 46127032 */  c.eq.s $f14, $f18
.L7F020B58:
/* 055688 7F020B58 00000000 */  nop   
/* 05568C 7F020B5C 45020011 */  bc1fl .L7F020BA4
/* 055690 7F020B60 E7AC008C */   swc1  $f12, 0x8c($sp)
/* 055694 7F020B64 46126032 */  c.eq.s $f12, $f18
/* 055698 7F020B68 C7AA0088 */  lwc1  $f10, 0x88($sp)
/* 05569C 7F020B6C 4502000D */  bc1fl .L7F020BA4
/* 0556A0 7F020B70 E7AC008C */   swc1  $f12, 0x8c($sp)
/* 0556A4 7F020B74 46125032 */  c.eq.s $f10, $f18
/* 0556A8 7F020B78 C7A40094 */  lwc1  $f4, 0x94($sp)
/* 0556AC 7F020B7C 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0556B0 7F020B80 45020008 */  bc1fl .L7F020BA4
/* 0556B4 7F020B84 E7AC008C */   swc1  $f12, 0x8c($sp)
/* 0556B8 7F020B88 44813000 */  mtc1  $at, $f6
/* 0556BC 7F020B8C 00000000 */  nop   
/* 0556C0 7F020B90 46062032 */  c.eq.s $f4, $f6
/* 0556C4 7F020B94 00000000 */  nop   
/* 0556C8 7F020B98 4503007B */  bc1tl .L7F020D88
/* 0556CC 7F020B9C 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0556D0 7F020BA0 E7AC008C */  swc1  $f12, 0x8c($sp)
.L7F020BA4:
/* 0556D4 7F020BA4 0FC0B064 */  jal   chrlvGetSubrotySideback
/* 0556D8 7F020BA8 E7AE0090 */   swc1  $f14, 0x90($sp)
/* 0556DC 7F020BAC C7AE0090 */  lwc1  $f14, 0x90($sp)
/* 0556E0 7F020BB0 44809000 */  mtc1  $zero, $f18
/* 0556E4 7F020BB4 C7AC008C */  lwc1  $f12, 0x8c($sp)
/* 0556E8 7F020BB8 E7A00070 */  swc1  $f0, 0x70($sp)
/* 0556EC 7F020BBC 4612703C */  c.lt.s $f14, $f18
/* 0556F0 7F020BC0 3C018005 */  lui   $at, %hi(D_80051D4C)
/* 0556F4 7F020BC4 45000003 */  bc1f  .L7F020BD4
/* 0556F8 7F020BC8 00000000 */   nop   
/* 0556FC 7F020BCC 10000003 */  b     .L7F020BDC
/* 055700 7F020BD0 46007387 */   neg.s $f14, $f14
.L7F020BD4:
/* 055704 7F020BD4 C4281D4C */  lwc1  $f8, %lo(D_80051D4C)($at)
/* 055708 7F020BD8 460E4381 */  sub.s $f14, $f8, $f14
.L7F020BDC:
/* 05570C 7F020BDC 4612603C */  c.lt.s $f12, $f18
/* 055710 7F020BE0 3C018005 */  lui   $at, %hi(D_80051D50)
/* 055714 7F020BE4 45020004 */  bc1fl .L7F020BF8
/* 055718 7F020BE8 E7AC008C */   swc1  $f12, 0x8c($sp)
/* 05571C 7F020BEC C42A1D50 */  lwc1  $f10, %lo(D_80051D50)($at)
/* 055720 7F020BF0 460A6300 */  add.s $f12, $f12, $f10
/* 055724 7F020BF4 E7AC008C */  swc1  $f12, 0x8c($sp)
.L7F020BF8:
/* 055728 7F020BF8 0FC1E111 */  jal   currentPlayerGetMatrix10D4
/* 05572C 7F020BFC E7AE0090 */   swc1  $f14, 0x90($sp)
/* 055730 7F020C00 00402025 */  move  $a0, $v0
/* 055734 7F020C04 0FC16026 */  jal   matrix_4x4_multiply_homogeneous_in_place
/* 055738 7F020C08 8FA5009C */   lw    $a1, 0x9c($sp)
/* 05573C 7F020C0C 8FA2009C */  lw    $v0, 0x9c($sp)
/* 055740 7F020C10 C7AE0090 */  lwc1  $f14, 0x90($sp)
/* 055744 7F020C14 44809000 */  mtc1  $zero, $f18
/* 055748 7F020C18 C4440030 */  lwc1  $f4, 0x30($v0)
/* 05574C 7F020C1C C7AC008C */  lwc1  $f12, 0x8c($sp)
/* 055750 7F020C20 46127032 */  c.eq.s $f14, $f18
/* 055754 7F020C24 E7A40074 */  swc1  $f4, 0x74($sp)
/* 055758 7F020C28 C4460034 */  lwc1  $f6, 0x34($v0)
/* 05575C 7F020C2C 27A50030 */  addiu $a1, $sp, 0x30
/* 055760 7F020C30 E7A60078 */  swc1  $f6, 0x78($sp)
/* 055764 7F020C34 C4480038 */  lwc1  $f8, 0x38($v0)
/* 055768 7F020C38 E7A8007C */  swc1  $f8, 0x7c($sp)
/* 05576C 7F020C3C E4520030 */  swc1  $f18, 0x30($v0)
/* 055770 7F020C40 E4520034 */  swc1  $f18, 0x34($v0)
/* 055774 7F020C44 45000006 */  bc1f  .L7F020C60
/* 055778 7F020C48 E4520038 */   swc1  $f18, 0x38($v0)
/* 05577C 7F020C4C C7AA0088 */  lwc1  $f10, 0x88($sp)
/* 055780 7F020C50 46125032 */  c.eq.s $f10, $f18
/* 055784 7F020C54 00000000 */  nop   
/* 055788 7F020C58 45010030 */  bc1t  .L7F020D1C
/* 05578C 7F020C5C 00000000 */   nop   
.L7F020C60:
/* 055790 7F020C60 C7A40070 */  lwc1  $f4, 0x70($sp)
/* 055794 7F020C64 3C018005 */  lui   $at, %hi(D_80051D54)
/* 055798 7F020C68 46046301 */  sub.s $f12, $f12, $f4
/* 05579C 7F020C6C 4612603C */  c.lt.s $f12, $f18
/* 0557A0 7F020C70 00000000 */  nop   
/* 0557A4 7F020C74 45000003 */  bc1f  .L7F020C84
/* 0557A8 7F020C78 00000000 */   nop   
/* 0557AC 7F020C7C C4261D54 */  lwc1  $f6, %lo(D_80051D54)($at)
/* 0557B0 7F020C80 46066300 */  add.s $f12, $f12, $f6
.L7F020C84:
/* 0557B4 7F020C84 0FC1617F */  jal   matrix_4x4_set_rotation_around_y
/* 0557B8 7F020C88 E7AE0090 */   swc1  $f14, 0x90($sp)
/* 0557BC 7F020C8C 27A40030 */  addiu $a0, $sp, 0x30
/* 0557C0 7F020C90 0FC16026 */  jal   matrix_4x4_multiply_homogeneous_in_place
/* 0557C4 7F020C94 8FA5009C */   lw    $a1, 0x9c($sp)
/* 0557C8 7F020C98 C7AE0090 */  lwc1  $f14, 0x90($sp)
/* 0557CC 7F020C9C 44809000 */  mtc1  $zero, $f18
/* 0557D0 7F020CA0 27A50030 */  addiu $a1, $sp, 0x30
/* 0557D4 7F020CA4 46127032 */  c.eq.s $f14, $f18
/* 0557D8 7F020CA8 00000000 */  nop   
/* 0557DC 7F020CAC 45030009 */  bc1tl .L7F020CD4
/* 0557E0 7F020CB0 C7A80088 */   lwc1  $f8, 0x88($sp)
/* 0557E4 7F020CB4 0FC1615C */  jal   matrix_4x4_set_rotation_around_x
/* 0557E8 7F020CB8 46007306 */   mov.s $f12, $f14
/* 0557EC 7F020CBC 27A40030 */  addiu $a0, $sp, 0x30
/* 0557F0 7F020CC0 0FC16026 */  jal   matrix_4x4_multiply_homogeneous_in_place
/* 0557F4 7F020CC4 8FA5009C */   lw    $a1, 0x9c($sp)
/* 0557F8 7F020CC8 44809000 */  mtc1  $zero, $f18
/* 0557FC 7F020CCC 00000000 */  nop   
/* 055800 7F020CD0 C7A80088 */  lwc1  $f8, 0x88($sp)
.L7F020CD4:
/* 055804 7F020CD4 27A50030 */  addiu $a1, $sp, 0x30
/* 055808 7F020CD8 46124032 */  c.eq.s $f8, $f18
/* 05580C 7F020CDC 00000000 */  nop   
/* 055810 7F020CE0 45030007 */  bc1tl .L7F020D00
/* 055814 7F020CE4 C7AC0070 */   lwc1  $f12, 0x70($sp)
/* 055818 7F020CE8 0FC161A2 */  jal   matrix_4x4_set_rotation_around_z
/* 05581C 7F020CEC 46004306 */   mov.s $f12, $f8
/* 055820 7F020CF0 27A40030 */  addiu $a0, $sp, 0x30
/* 055824 7F020CF4 0FC16026 */  jal   matrix_4x4_multiply_homogeneous_in_place
/* 055828 7F020CF8 8FA5009C */   lw    $a1, 0x9c($sp)
/* 05582C 7F020CFC C7AC0070 */  lwc1  $f12, 0x70($sp)
.L7F020D00:
/* 055830 7F020D00 0FC1617F */  jal   matrix_4x4_set_rotation_around_y
/* 055834 7F020D04 27A50030 */   addiu $a1, $sp, 0x30
/* 055838 7F020D08 27A40030 */  addiu $a0, $sp, 0x30
/* 05583C 7F020D0C 0FC16026 */  jal   matrix_4x4_multiply_homogeneous_in_place
/* 055840 7F020D10 8FA5009C */   lw    $a1, 0x9c($sp)
/* 055844 7F020D14 10000007 */  b     .L7F020D34
/* 055848 7F020D18 3C013F80 */   lui   $at, 0x3f80
.L7F020D1C:
/* 05584C 7F020D1C 0FC1617F */  jal   matrix_4x4_set_rotation_around_y
/* 055850 7F020D20 27A50030 */   addiu $a1, $sp, 0x30
/* 055854 7F020D24 27A40030 */  addiu $a0, $sp, 0x30
/* 055858 7F020D28 0FC16026 */  jal   matrix_4x4_multiply_homogeneous_in_place
/* 05585C 7F020D2C 8FA5009C */   lw    $a1, 0x9c($sp)
/* 055860 7F020D30 3C013F80 */  li    $at, 0x3F800000 # 1.000000
.L7F020D34:
/* 055864 7F020D34 44812000 */  mtc1  $at, $f4
/* 055868 7F020D38 C7AA0094 */  lwc1  $f10, 0x94($sp)
/* 05586C 7F020D3C 8FA5009C */  lw    $a1, 0x9c($sp)
/* 055870 7F020D40 46045032 */  c.eq.s $f10, $f4
/* 055874 7F020D44 00000000 */  nop   
/* 055878 7F020D48 45030004 */  bc1tl .L7F020D5C
/* 05587C 7F020D4C C7A60074 */   lwc1  $f6, 0x74($sp)
/* 055880 7F020D50 0FC1629F */  jal   matrix_scalar_multiply
/* 055884 7F020D54 46005306 */   mov.s $f12, $f10
/* 055888 7F020D58 C7A60074 */  lwc1  $f6, 0x74($sp)
.L7F020D5C:
/* 05588C 7F020D5C 8FA8009C */  lw    $t0, 0x9c($sp)
/* 055890 7F020D60 E5060030 */  swc1  $f6, 0x30($t0)
/* 055894 7F020D64 C7A80078 */  lwc1  $f8, 0x78($sp)
/* 055898 7F020D68 E5080034 */  swc1  $f8, 0x34($t0)
/* 05589C 7F020D6C C7A4007C */  lwc1  $f4, 0x7c($sp)
/* 0558A0 7F020D70 0FC1E0F1 */  jal   currentPlayerGetMatrix10CC
/* 0558A4 7F020D74 E5040038 */   swc1  $f4, 0x38($t0)
/* 0558A8 7F020D78 00402025 */  move  $a0, $v0
/* 0558AC 7F020D7C 0FC16026 */  jal   matrix_4x4_multiply_homogeneous_in_place
/* 0558B0 7F020D80 8FA5009C */   lw    $a1, 0x9c($sp)
/* 0558B4 7F020D84 8FBF0014 */  lw    $ra, 0x14($sp)
.L7F020D88:
/* 0558B8 7F020D88 27BD0098 */  addiu $sp, $sp, 0x98
/* 0558BC 7F020D8C 03E00008 */  jr    $ra
/* 0558C0 7F020D90 00000000 */   nop   
)
#endif

#ifndef VERSION_US
GLOBAL_ASM(
.text
glabel sub_GAME_7F02083C
/* 05561C 7F020AAC 27BDFF68 */  addiu $sp, $sp, -0x98
/* 055620 7F020AB0 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 055624 7F020AB4 44812000 */  mtc1  $at, $f4
/* 055628 7F020AB8 AFBF0014 */  sw    $ra, 0x14($sp)
/* 05562C 7F020ABC 00803825 */  move  $a3, $a0
/* 055630 7F020AC0 AFA5009C */  sw    $a1, 0x9c($sp)
/* 055634 7F020AC4 AFA70098 */  sw    $a3, 0x98($sp)
/* 055638 7F020AC8 2404000C */  li    $a0, 12
/* 05563C 7F020ACC 0FC24CCF */  jal   cheatIsActive
/* 055640 7F020AD0 E7A40094 */   swc1  $f4, 0x94($sp)
/* 055644 7F020AD4 1040001C */  beqz  $v0, .L7F020B48
/* 055648 7F020AD8 8FA70098 */   lw    $a3, 0x98($sp)
/* 05564C 7F020ADC 3C068007 */  lui   $a2, %hi(dword_CODE_bss_80069B60) # $a2, 0x8007
/* 055650 7F020AE0 8CC69BA0 */  lw    $a2, %lo(dword_CODE_bss_80069B60)($a2)
/* 055654 7F020AE4 80C4000F */  lb    $a0, 0xf($a2)
/* 055658 7F020AE8 80C50006 */  lb    $a1, 6($a2)
/* 05565C 7F020AEC 0FC0827B */  jal   not_in_us_7F0209EC
/* 055660 7F020AF0 AFA70098 */   sw    $a3, 0x98($sp)
/* 055664 7F020AF4 10400014 */  beqz  $v0, .L7F020B48
/* 055668 7F020AF8 8FA70098 */   lw    $a3, 0x98($sp)
/* 05566C 7F020AFC 14E00005 */  bnez  $a3, .L7F020B14
/* 055670 7F020B00 24030002 */   li    $v1, 2
/* 055674 7F020B04 3C014080 */  li    $at, 0x40800000 # 4.000000
/* 055678 7F020B08 44813000 */  mtc1  $at, $f6
/* 05567C 7F020B0C 1000000E */  b     .L7F020B48
/* 055680 7F020B10 E7A60094 */   swc1  $f6, 0x94($sp)
.L7F020B14:
/* 055684 7F020B14 10E30002 */  beq   $a3, $v1, .L7F020B20
/* 055688 7F020B18 24050003 */   li    $a1, 3
/* 05568C 7F020B1C 14E5000A */  bne   $a3, $a1, .L7F020B48
.L7F020B20:
/* 055690 7F020B20 3C0E8007 */   lui   $t6, %hi(dword_CODE_bss_80069B60) # $t6, 0x8007
/* 055694 7F020B24 8DCE9BA0 */  lw    $t6, %lo(dword_CODE_bss_80069B60)($t6)
/* 055698 7F020B28 3C014020 */  li    $at, 0x40200000 # 2.500000
/* 05569C 7F020B2C 8DCF0014 */  lw    $t7, 0x14($t6)
/* 0556A0 7F020B30 000FC100 */  sll   $t8, $t7, 4
/* 0556A4 7F020B34 07020005 */  bltzl $t8, .L7F020B4C
/* 0556A8 7F020B38 24030002 */   li    $v1, 2
/* 0556AC 7F020B3C 44814000 */  mtc1  $at, $f8
/* 0556B0 7F020B40 00000000 */  nop   
/* 0556B4 7F020B44 E7A80094 */  swc1  $f8, 0x94($sp)
.L7F020B48:
/* 0556B8 7F020B48 24030002 */  li    $v1, 2
.L7F020B4C:
/* 0556BC 7F020B4C 10E30007 */  beq   $a3, $v1, .L7F020B6C
/* 0556C0 7F020B50 24050003 */   li    $a1, 3
/* 0556C4 7F020B54 10E50005 */  beq   $a3, $a1, .L7F020B6C
/* 0556C8 7F020B58 24040001 */   li    $a0, 1
/* 0556CC 7F020B5C 50E40004 */  beql  $a3, $a0, .L7F020B70
/* 0556D0 7F020B60 44809000 */   mtc1  $zero, $f18
/* 0556D4 7F020B64 54E0012E */  bnezl $a3, .L7F021020
/* 0556D8 7F020B68 8FBF0014 */   lw    $ra, 0x14($sp)
.L7F020B6C:
/* 0556DC 7F020B6C 44809000 */  mtc1  $zero, $f18
.L7F020B70:
/* 0556E0 7F020B70 3C068007 */  lui   $a2, %hi(dword_CODE_bss_80069B60) # $a2, 0x8007
/* 0556E4 7F020B74 24040001 */  li    $a0, 1
/* 0556E8 7F020B78 8CC69BA0 */  lw    $a2, %lo(dword_CODE_bss_80069B60)($a2)
/* 0556EC 7F020B7C 46009386 */  mov.s $f14, $f18
/* 0556F0 7F020B80 46009306 */  mov.s $f12, $f18
/* 0556F4 7F020B84 14E50003 */  bne   $a3, $a1, .L7F020B94
/* 0556F8 7F020B88 E7B20088 */   swc1  $f18, 0x88($sp)
/* 0556FC 7F020B8C 10000040 */  b     .L7F020C90
/* 055700 7F020B90 C4CE0144 */   lwc1  $f14, 0x144($a2)
.L7F020B94:
/* 055704 7F020B94 14E30003 */  bne   $a3, $v1, .L7F020BA4
/* 055708 7F020B98 00000000 */   nop   
/* 05570C 7F020B9C 1000003C */  b     .L7F020C90
/* 055710 7F020BA0 C4CE0140 */   lwc1  $f14, 0x140($a2)
.L7F020BA4:
/* 055714 7F020BA4 14E4001B */  bne   $a3, $a0, .L7F020C14
/* 055718 7F020BA8 00000000 */   nop   
/* 05571C 7F020BAC 94D90012 */  lhu   $t9, 0x12($a2)
/* 055720 7F020BB0 C4CE0148 */  lwc1  $f14, 0x148($a2)
/* 055724 7F020BB4 3C018005 */  lui   $at, %hi(D_80051D30) # $at, 0x8005
/* 055728 7F020BB8 33280400 */  andi  $t0, $t9, 0x400
/* 05572C 7F020BBC 11000013 */  beqz  $t0, .L7F020C0C
/* 055730 7F020BC0 00000000 */   nop   
/* 055734 7F020BC4 C4201D60 */  lwc1  $f0, %lo(D_80051D30)($at)
/* 055738 7F020BC8 3C018005 */  lui   $at, %hi(D_80051D34) # $at, 0x8005
/* 05573C 7F020BCC 460E003C */  c.lt.s $f0, $f14
/* 055740 7F020BD0 00000000 */  nop   
/* 055744 7F020BD4 45000003 */  bc1f  .L7F020BE4
/* 055748 7F020BD8 00000000 */   nop   
/* 05574C 7F020BDC 1000000B */  b     .L7F020C0C
/* 055750 7F020BE0 46007381 */   sub.s $f14, $f14, $f0
.L7F020BE4:
/* 055754 7F020BE4 C4201D64 */  lwc1  $f0, %lo(D_80051D34)($at)
/* 055758 7F020BE8 3C018005 */  lui   $at, %hi(D_80051D38) # $at, 0x8005
/* 05575C 7F020BEC 4600703C */  c.lt.s $f14, $f0
/* 055760 7F020BF0 00000000 */  nop   
/* 055764 7F020BF4 45020005 */  bc1fl .L7F020C0C
/* 055768 7F020BF8 46009386 */   mov.s $f14, $f18
/* 05576C 7F020BFC C42A1D68 */  lwc1  $f10, %lo(D_80051D38)($at)
/* 055770 7F020C00 10000002 */  b     .L7F020C0C
/* 055774 7F020C04 460A7380 */   add.s $f14, $f14, $f10
/* 055778 7F020C08 46009386 */  mov.s $f14, $f18
.L7F020C0C:
/* 05577C 7F020C0C 10000020 */  b     .L7F020C90
/* 055780 7F020C10 C4CC014C */   lwc1  $f12, 0x14c($a2)
.L7F020C14:
/* 055784 7F020C14 54E0001F */  bnezl $a3, .L7F020C94
/* 055788 7F020C18 80CC0011 */   lb    $t4, 0x11($a2)
/* 05578C 7F020C1C 94C20012 */  lhu   $v0, 0x12($a2)
/* 055790 7F020C20 30490400 */  andi  $t1, $v0, 0x400
/* 055794 7F020C24 51200014 */  beql  $t1, $zero, .L7F020C78
/* 055798 7F020C28 8CCA001C */   lw    $t2, 0x1c($a2)
/* 05579C 7F020C2C 11200018 */  beqz  $t1, .L7F020C90
/* 0557A0 7F020C30 C4CE0148 */   lwc1  $f14, 0x148($a2)
/* 0557A4 7F020C34 3C018005 */  lui   $at, %hi(D_80051D3C) # $at, 0x8005
/* 0557A8 7F020C38 C4201D6C */  lwc1  $f0, %lo(D_80051D3C)($at)
/* 0557AC 7F020C3C 3C018005 */  lui   $at, %hi(D_80051D40) # $at, 0x8005
/* 0557B0 7F020C40 460E003C */  c.lt.s $f0, $f14
/* 0557B4 7F020C44 00000000 */  nop   
/* 0557B8 7F020C48 45000003 */  bc1f  .L7F020C58
/* 0557BC 7F020C4C 00000000 */   nop   
/* 0557C0 7F020C50 1000000F */  b     .L7F020C90
/* 0557C4 7F020C54 46000386 */   mov.s $f14, $f0
.L7F020C58:
/* 0557C8 7F020C58 C4201D70 */  lwc1  $f0, %lo(D_80051D40)($at)
/* 0557CC 7F020C5C 4600703C */  c.lt.s $f14, $f0
/* 0557D0 7F020C60 00000000 */  nop   
/* 0557D4 7F020C64 4502000B */  bc1fl .L7F020C94
/* 0557D8 7F020C68 80CC0011 */   lb    $t4, 0x11($a2)
/* 0557DC 7F020C6C 10000008 */  b     .L7F020C90
/* 0557E0 7F020C70 46000386 */   mov.s $f14, $f0
/* 0557E4 7F020C74 8CCA001C */  lw    $t2, 0x1c($a2)
.L7F020C78:
/* 0557E8 7F020C78 814B0024 */  lb    $t3, 0x24($t2)
/* 0557EC 7F020C7C 51600004 */  beql  $t3, $zero, .L7F020C90
/* 0557F0 7F020C80 C4CE0144 */   lwc1  $f14, 0x144($a2)
/* 0557F4 7F020C84 10000002 */  b     .L7F020C90
/* 0557F8 7F020C88 C4CE0140 */   lwc1  $f14, 0x140($a2)
/* 0557FC 7F020C8C C4CE0144 */  lwc1  $f14, 0x144($a2)
.L7F020C90:
/* 055800 7F020C90 80CC0011 */  lb    $t4, 0x11($a2)
.L7F020C94:
/* 055804 7F020C94 05820056 */  bltzl $t4, .L7F020DF0
/* 055808 7F020C98 46127032 */   c.eq.s $f14, $f18
/* 05580C 7F020C9C 50E50004 */  beql  $a3, $a1, .L7F020CB0
/* 055810 7F020CA0 00C02025 */   move  $a0, $a2
/* 055814 7F020CA4 14E3001E */  bne   $a3, $v1, .L7F020D20
/* 055818 7F020CA8 00000000 */   nop   
/* 05581C 7F020CAC 00C02025 */  move  $a0, $a2
.L7F020CB0:
/* 055820 7F020CB0 E7AC008C */  swc1  $f12, 0x8c($sp)
/* 055824 7F020CB4 0FC08251 */  jal   sub_GAME_7F020794
/* 055828 7F020CB8 E7AE0090 */   swc1  $f14, 0x90($sp)
/* 05582C 7F020CBC 3C018005 */  lui   $at, %hi(D_80051D44) # $at, 0x8005
/* 055830 7F020CC0 C4241D74 */  lwc1  $f4, %lo(D_80051D44)($at)
/* 055834 7F020CC4 3C014170 */  li    $at, 0x41700000 # 15.000000
/* 055838 7F020CC8 44814000 */  mtc1  $at, $f8
/* 05583C 7F020CCC 46040182 */  mul.s $f6, $f0, $f4
/* 055840 7F020CD0 3C0143B4 */  li    $at, 0x43B40000 # 360.000000
/* 055844 7F020CD4 44812000 */  mtc1  $at, $f4
/* 055848 7F020CD8 3C068007 */  lui   $a2, %hi(dword_CODE_bss_80069B60) # $a2, 0x8007
/* 05584C 7F020CDC 8CC69BA0 */  lw    $a2, %lo(dword_CODE_bss_80069B60)($a2)
/* 055850 7F020CE0 C7AE0090 */  lwc1  $f14, 0x90($sp)
/* 055854 7F020CE4 44809000 */  mtc1  $zero, $f18
/* 055858 7F020CE8 46083282 */  mul.s $f10, $f6, $f8
/* 05585C 7F020CEC 94C20012 */  lhu   $v0, 0x12($a2)
/* 055860 7F020CF0 C7AC008C */  lwc1  $f12, 0x8c($sp)
/* 055864 7F020CF4 304D1000 */  andi  $t5, $v0, 0x1000
/* 055868 7F020CF8 304E2000 */  andi  $t6, $v0, 0x2000
/* 05586C 7F020CFC 46045083 */  div.s $f2, $f10, $f4
/* 055870 7F020D00 11A00003 */  beqz  $t5, .L7F020D10
/* 055874 7F020D04 46027381 */   sub.s $f14, $f14, $f2
/* 055878 7F020D08 10000038 */  b     .L7F020DEC
/* 05587C 7F020D0C 46026301 */   sub.s $f12, $f12, $f2
.L7F020D10:
/* 055880 7F020D10 51C00037 */  beql  $t6, $zero, .L7F020DF0
/* 055884 7F020D14 46127032 */   c.eq.s $f14, $f18
/* 055888 7F020D18 10000034 */  b     .L7F020DEC
/* 05588C 7F020D1C 46026300 */   add.s $f12, $f12, $f2
.L7F020D20:
/* 055890 7F020D20 14E40032 */  bne   $a3, $a0, .L7F020DEC
/* 055894 7F020D24 00C02025 */   move  $a0, $a2
/* 055898 7F020D28 E7AC008C */  swc1  $f12, 0x8c($sp)
/* 05589C 7F020D2C 0FC08251 */  jal   sub_GAME_7F020794
/* 0558A0 7F020D30 E7AE0090 */   swc1  $f14, 0x90($sp)
/* 0558A4 7F020D34 3C018005 */  lui   $at, %hi(D_80051D48) # $at, 0x8005
/* 0558A8 7F020D38 C4261D78 */  lwc1  $f6, %lo(D_80051D48)($at)
/* 0558AC 7F020D3C 3C014170 */  li    $at, 0x41700000 # 15.000000
/* 0558B0 7F020D40 44814000 */  mtc1  $at, $f8
/* 0558B4 7F020D44 46060402 */  mul.s $f16, $f0, $f6
/* 0558B8 7F020D48 3C0143B4 */  li    $at, 0x43B40000 # 360.000000
/* 0558BC 7F020D4C 44812000 */  mtc1  $at, $f4
/* 0558C0 7F020D50 3C068007 */  lui   $a2, %hi(dword_CODE_bss_80069B60) # $a2, 0x8007
/* 0558C4 7F020D54 8CC69BA0 */  lw    $a2, %lo(dword_CODE_bss_80069B60)($a2)
/* 0558C8 7F020D58 C7AE0090 */  lwc1  $f14, 0x90($sp)
/* 0558CC 7F020D5C 44809000 */  mtc1  $zero, $f18
/* 0558D0 7F020D60 46088282 */  mul.s $f10, $f16, $f8
/* 0558D4 7F020D64 94C20012 */  lhu   $v0, 0x12($a2)
/* 0558D8 7F020D68 C7AC008C */  lwc1  $f12, 0x8c($sp)
/* 0558DC 7F020D6C 3C014120 */  li    $at, 0x41200000 # 10.000000
/* 0558E0 7F020D70 304F1000 */  andi  $t7, $v0, 0x1000
/* 0558E4 7F020D74 30582000 */  andi  $t8, $v0, 0x2000
/* 0558E8 7F020D78 30594000 */  andi  $t9, $v0, 0x4000
/* 0558EC 7F020D7C 46045083 */  div.s $f2, $f10, $f4
/* 0558F0 7F020D80 30488000 */  andi  $t0, $v0, 0x8000
/* 0558F4 7F020D84 11E00003 */  beqz  $t7, .L7F020D94
/* 0558F8 7F020D88 46027380 */   add.s $f14, $f14, $f2
/* 0558FC 7F020D8C 10000004 */  b     .L7F020DA0
/* 055900 7F020D90 46026300 */   add.s $f12, $f12, $f2
.L7F020D94:
/* 055904 7F020D94 13000002 */  beqz  $t8, .L7F020DA0
/* 055908 7F020D98 00000000 */   nop   
/* 05590C 7F020D9C 46026301 */  sub.s $f12, $f12, $f2
.L7F020DA0:
/* 055910 7F020DA0 13200009 */  beqz  $t9, .L7F020DC8
/* 055914 7F020DA4 00000000 */   nop   
/* 055918 7F020DA8 44813000 */  mtc1  $at, $f6
/* 05591C 7F020DAC 3C0143B4 */  li    $at, 0x43B40000 # 360.000000
/* 055920 7F020DB0 44815000 */  mtc1  $at, $f10
/* 055924 7F020DB4 46068202 */  mul.s $f8, $f16, $f6
/* 055928 7F020DB8 460A4103 */  div.s $f4, $f8, $f10
/* 05592C 7F020DBC 46049180 */  add.s $f6, $f18, $f4
/* 055930 7F020DC0 1000000A */  b     .L7F020DEC
/* 055934 7F020DC4 E7A60088 */   swc1  $f6, 0x88($sp)
.L7F020DC8:
/* 055938 7F020DC8 11000008 */  beqz  $t0, .L7F020DEC
/* 05593C 7F020DCC 3C014120 */   li    $at, 0x41200000 # 10.000000
/* 055940 7F020DD0 44814000 */  mtc1  $at, $f8
/* 055944 7F020DD4 3C0143B4 */  li    $at, 0x43B40000 # 360.000000
/* 055948 7F020DD8 44812000 */  mtc1  $at, $f4
/* 05594C 7F020DDC 46088282 */  mul.s $f10, $f16, $f8
/* 055950 7F020DE0 46045183 */  div.s $f6, $f10, $f4
/* 055954 7F020DE4 46069201 */  sub.s $f8, $f18, $f6
/* 055958 7F020DE8 E7A80088 */  swc1  $f8, 0x88($sp)
.L7F020DEC:
/* 05595C 7F020DEC 46127032 */  c.eq.s $f14, $f18
.L7F020DF0:
/* 055960 7F020DF0 00C02025 */  move  $a0, $a2
/* 055964 7F020DF4 45020011 */  bc1fl .L7F020E3C
/* 055968 7F020DF8 E7AC008C */   swc1  $f12, 0x8c($sp)
/* 05596C 7F020DFC 46126032 */  c.eq.s $f12, $f18
/* 055970 7F020E00 C7AA0088 */  lwc1  $f10, 0x88($sp)
/* 055974 7F020E04 4502000D */  bc1fl .L7F020E3C
/* 055978 7F020E08 E7AC008C */   swc1  $f12, 0x8c($sp)
/* 05597C 7F020E0C 46125032 */  c.eq.s $f10, $f18
/* 055980 7F020E10 C7A40094 */  lwc1  $f4, 0x94($sp)
/* 055984 7F020E14 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 055988 7F020E18 45020008 */  bc1fl .L7F020E3C
/* 05598C 7F020E1C E7AC008C */   swc1  $f12, 0x8c($sp)
/* 055990 7F020E20 44813000 */  mtc1  $at, $f6
/* 055994 7F020E24 00000000 */  nop   
/* 055998 7F020E28 46062032 */  c.eq.s $f4, $f6
/* 05599C 7F020E2C 00000000 */  nop   
/* 0559A0 7F020E30 4503007B */  bc1tl .L7F021020
/* 0559A4 7F020E34 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0559A8 7F020E38 E7AC008C */  swc1  $f12, 0x8c($sp)
.L7F020E3C:
/* 0559AC 7F020E3C 0FC0B126 */  jal   chrlvGetSubrotySideback
/* 0559B0 7F020E40 E7AE0090 */   swc1  $f14, 0x90($sp)
/* 0559B4 7F020E44 C7AE0090 */  lwc1  $f14, 0x90($sp)
/* 0559B8 7F020E48 44809000 */  mtc1  $zero, $f18
/* 0559BC 7F020E4C C7AC008C */  lwc1  $f12, 0x8c($sp)
/* 0559C0 7F020E50 E7A00070 */  swc1  $f0, 0x70($sp)
/* 0559C4 7F020E54 4612703C */  c.lt.s $f14, $f18
/* 0559C8 7F020E58 3C018005 */  lui   $at, %hi(D_80051D4C) # $at, 0x8005
/* 0559CC 7F020E5C 45000003 */  bc1f  .L7F020E6C
/* 0559D0 7F020E60 00000000 */   nop   
/* 0559D4 7F020E64 10000003 */  b     .L7F020E74
/* 0559D8 7F020E68 46007387 */   neg.s $f14, $f14
.L7F020E6C:
/* 0559DC 7F020E6C C4281D7C */  lwc1  $f8, %lo(D_80051D4C)($at)
/* 0559E0 7F020E70 460E4381 */  sub.s $f14, $f8, $f14
.L7F020E74:
/* 0559E4 7F020E74 4612603C */  c.lt.s $f12, $f18
/* 0559E8 7F020E78 3C018005 */  lui   $at, %hi(D_80051D50) # $at, 0x8005
/* 0559EC 7F020E7C 45020004 */  bc1fl .L7F020E90
/* 0559F0 7F020E80 E7AC008C */   swc1  $f12, 0x8c($sp)
/* 0559F4 7F020E84 C42A1D80 */  lwc1  $f10, %lo(D_80051D50)($at)
/* 0559F8 7F020E88 460A6300 */  add.s $f12, $f12, $f10
/* 0559FC 7F020E8C E7AC008C */  swc1  $f12, 0x8c($sp)
.L7F020E90:
/* 055A00 7F020E90 0FC1E28D */  jal   currentPlayerGetMatrix10D4
/* 055A04 7F020E94 E7AE0090 */   swc1  $f14, 0x90($sp)
/* 055A08 7F020E98 00402025 */  move  $a0, $v0
/* 055A0C 7F020E9C 0FC1616E */  jal   matrix_4x4_multiply_homogeneous_in_place
/* 055A10 7F020EA0 8FA5009C */   lw    $a1, 0x9c($sp)
/* 055A14 7F020EA4 8FA2009C */  lw    $v0, 0x9c($sp)
/* 055A18 7F020EA8 C7AE0090 */  lwc1  $f14, 0x90($sp)
/* 055A1C 7F020EAC 44809000 */  mtc1  $zero, $f18
/* 055A20 7F020EB0 C4440030 */  lwc1  $f4, 0x30($v0)
/* 055A24 7F020EB4 C7AC008C */  lwc1  $f12, 0x8c($sp)
/* 055A28 7F020EB8 46127032 */  c.eq.s $f14, $f18
/* 055A2C 7F020EBC E7A40074 */  swc1  $f4, 0x74($sp)
/* 055A30 7F020EC0 C4460034 */  lwc1  $f6, 0x34($v0)
/* 055A34 7F020EC4 27A50030 */  addiu $a1, $sp, 0x30
/* 055A38 7F020EC8 E7A60078 */  swc1  $f6, 0x78($sp)
/* 055A3C 7F020ECC C4480038 */  lwc1  $f8, 0x38($v0)
/* 055A40 7F020ED0 E7A8007C */  swc1  $f8, 0x7c($sp)
/* 055A44 7F020ED4 E4520030 */  swc1  $f18, 0x30($v0)
/* 055A48 7F020ED8 E4520034 */  swc1  $f18, 0x34($v0)
/* 055A4C 7F020EDC 45000006 */  bc1f  .L7F020EF8
/* 055A50 7F020EE0 E4520038 */   swc1  $f18, 0x38($v0)
/* 055A54 7F020EE4 C7AA0088 */  lwc1  $f10, 0x88($sp)
/* 055A58 7F020EE8 46125032 */  c.eq.s $f10, $f18
/* 055A5C 7F020EEC 00000000 */  nop   
/* 055A60 7F020EF0 45010030 */  bc1t  .L7F020FB4
/* 055A64 7F020EF4 00000000 */   nop   
.L7F020EF8:
/* 055A68 7F020EF8 C7A40070 */  lwc1  $f4, 0x70($sp)
/* 055A6C 7F020EFC 3C018005 */  lui   $at, %hi(D_80051D54) # $at, 0x8005
/* 055A70 7F020F00 46046301 */  sub.s $f12, $f12, $f4
/* 055A74 7F020F04 4612603C */  c.lt.s $f12, $f18
/* 055A78 7F020F08 00000000 */  nop   
/* 055A7C 7F020F0C 45000003 */  bc1f  .L7F020F1C
/* 055A80 7F020F10 00000000 */   nop   
/* 055A84 7F020F14 C4261D84 */  lwc1  $f6, %lo(D_80051D54)($at)
/* 055A88 7F020F18 46066300 */  add.s $f12, $f12, $f6
.L7F020F1C:
/* 055A8C 7F020F1C 0FC162C7 */  jal   matrix_4x4_set_rotation_around_y
/* 055A90 7F020F20 E7AE0090 */   swc1  $f14, 0x90($sp)
/* 055A94 7F020F24 27A40030 */  addiu $a0, $sp, 0x30
/* 055A98 7F020F28 0FC1616E */  jal   matrix_4x4_multiply_homogeneous_in_place
/* 055A9C 7F020F2C 8FA5009C */   lw    $a1, 0x9c($sp)
/* 055AA0 7F020F30 C7AE0090 */  lwc1  $f14, 0x90($sp)
/* 055AA4 7F020F34 44809000 */  mtc1  $zero, $f18
/* 055AA8 7F020F38 27A50030 */  addiu $a1, $sp, 0x30
/* 055AAC 7F020F3C 46127032 */  c.eq.s $f14, $f18
/* 055AB0 7F020F40 00000000 */  nop   
/* 055AB4 7F020F44 45030009 */  bc1tl .L7F020F6C
/* 055AB8 7F020F48 C7A80088 */   lwc1  $f8, 0x88($sp)
/* 055ABC 7F020F4C 0FC162A4 */  jal   matrix_4x4_set_rotation_around_x
/* 055AC0 7F020F50 46007306 */   mov.s $f12, $f14
/* 055AC4 7F020F54 27A40030 */  addiu $a0, $sp, 0x30
/* 055AC8 7F020F58 0FC1616E */  jal   matrix_4x4_multiply_homogeneous_in_place
/* 055ACC 7F020F5C 8FA5009C */   lw    $a1, 0x9c($sp)
/* 055AD0 7F020F60 44809000 */  mtc1  $zero, $f18
/* 055AD4 7F020F64 00000000 */  nop   
/* 055AD8 7F020F68 C7A80088 */  lwc1  $f8, 0x88($sp)
.L7F020F6C:
/* 055ADC 7F020F6C 27A50030 */  addiu $a1, $sp, 0x30
/* 055AE0 7F020F70 46124032 */  c.eq.s $f8, $f18
/* 055AE4 7F020F74 00000000 */  nop   
/* 055AE8 7F020F78 45030007 */  bc1tl .L7F020F98
/* 055AEC 7F020F7C C7AC0070 */   lwc1  $f12, 0x70($sp)
/* 055AF0 7F020F80 0FC162EA */  jal   matrix_4x4_set_rotation_around_z
/* 055AF4 7F020F84 46004306 */   mov.s $f12, $f8
/* 055AF8 7F020F88 27A40030 */  addiu $a0, $sp, 0x30
/* 055AFC 7F020F8C 0FC1616E */  jal   matrix_4x4_multiply_homogeneous_in_place
/* 055B00 7F020F90 8FA5009C */   lw    $a1, 0x9c($sp)
/* 055B04 7F020F94 C7AC0070 */  lwc1  $f12, 0x70($sp)
.L7F020F98:
/* 055B08 7F020F98 0FC162C7 */  jal   matrix_4x4_set_rotation_around_y
/* 055B0C 7F020F9C 27A50030 */   addiu $a1, $sp, 0x30
/* 055B10 7F020FA0 27A40030 */  addiu $a0, $sp, 0x30
/* 055B14 7F020FA4 0FC1616E */  jal   matrix_4x4_multiply_homogeneous_in_place
/* 055B18 7F020FA8 8FA5009C */   lw    $a1, 0x9c($sp)
/* 055B1C 7F020FAC 10000007 */  b     .L7F020FCC
/* 055B20 7F020FB0 3C013F80 */   lui   $at, 0x3f80
.L7F020FB4:
/* 055B24 7F020FB4 0FC162C7 */  jal   matrix_4x4_set_rotation_around_y
/* 055B28 7F020FB8 27A50030 */   addiu $a1, $sp, 0x30
/* 055B2C 7F020FBC 27A40030 */  addiu $a0, $sp, 0x30
/* 055B30 7F020FC0 0FC1616E */  jal   matrix_4x4_multiply_homogeneous_in_place
/* 055B34 7F020FC4 8FA5009C */   lw    $a1, 0x9c($sp)
/* 055B38 7F020FC8 3C013F80 */  li    $at, 0x3F800000 # 1.000000
.L7F020FCC:
/* 055B3C 7F020FCC 44812000 */  mtc1  $at, $f4
/* 055B40 7F020FD0 C7AA0094 */  lwc1  $f10, 0x94($sp)
/* 055B44 7F020FD4 8FA5009C */  lw    $a1, 0x9c($sp)
/* 055B48 7F020FD8 46045032 */  c.eq.s $f10, $f4
/* 055B4C 7F020FDC 00000000 */  nop   
/* 055B50 7F020FE0 45030004 */  bc1tl .L7F020FF4
/* 055B54 7F020FE4 C7A60074 */   lwc1  $f6, 0x74($sp)
/* 055B58 7F020FE8 0FC163E7 */  jal   matrix_scalar_multiply
/* 055B5C 7F020FEC 46005306 */   mov.s $f12, $f10
/* 055B60 7F020FF0 C7A60074 */  lwc1  $f6, 0x74($sp)
.L7F020FF4:
/* 055B64 7F020FF4 8FA9009C */  lw    $t1, 0x9c($sp)
/* 055B68 7F020FF8 E5260030 */  swc1  $f6, 0x30($t1)
/* 055B6C 7F020FFC C7A80078 */  lwc1  $f8, 0x78($sp)
/* 055B70 7F021000 E5280034 */  swc1  $f8, 0x34($t1)
/* 055B74 7F021004 C7A4007C */  lwc1  $f4, 0x7c($sp)
/* 055B78 7F021008 0FC1E26D */  jal   currentPlayerGetMatrix10CC
/* 055B7C 7F02100C E5240038 */   swc1  $f4, 0x38($t1)
/* 055B80 7F021010 00402025 */  move  $a0, $v0
/* 055B84 7F021014 0FC1616E */  jal   matrix_4x4_multiply_homogeneous_in_place
/* 055B88 7F021018 8FA5009C */   lw    $a1, 0x9c($sp)
/* 055B8C 7F02101C 8FBF0014 */  lw    $ra, 0x14($sp)
.L7F021020:
/* 055B90 7F021020 27BD0098 */  addiu $sp, $sp, 0x98
/* 055B94 7F021024 03E00008 */  jr    $ra
/* 055B98 7F021028 00000000 */   nop   
    
)
#endif

#endif


/**
 * Address 0x7F020D94.
 */
void chrPositionRelated7F020D94(ChrRecord *self)
{
    PropRecord *myprop;
    coord3d     lowerbounds;
    coord3d     upperbounds;

    myprop        = self->prop;
    lowerbounds.x = myprop->pos.x - 50.0f;
    lowerbounds.y = self->ground - 1.0f;
    lowerbounds.z = myprop->pos.z - 50.0f;
    upperbounds.x = myprop->pos.x + 50.0f;
    upperbounds.y = myprop->pos.y + 100.0f;
    upperbounds.z = myprop->pos.z + 50.0f;
    chrpropDeregisterRooms(myprop);
    sub_GAME_7F03E27C(myprop, &lowerbounds, &upperbounds, 50.0f);
    chrpropRegisterRooms(myprop);
}




/**
 * Address 0x7F020E40.
 */
void chrPositionRelated7F020E40(ChrRecord *chr, s32 arg1)
{
    Model *model;
    PropRecord* prop;

    model = chr->model;
    prop = chr->prop;

    if ((chr->hidden & 0x800) == 0)
    {
        getsuboffset(model, &chr->prevpos);
        sub_GAME_7F070AEC(model, arg1, 1);
        subcalcpos(model);
        set_color_shading_from_tile(prop, &chr->nextcol);
        getsuboffset(model, &prop->pos);
        chrPositionRelated7F020D94(chr);

        return;
    }

    subcalcpos(model);
    getsuboffset(model, &prop->pos);
}



#ifdef NONMATCHING
void sub_GAME_7F020EF0(void) {

}
#else

#ifdef VERSION_US
GLOBAL_ASM(
.text
glabel sub_GAME_7F020EF0
/* 055A20 7F020EF0 27BDFEA8 */  addiu $sp, $sp, -0x158
/* 055A24 7F020EF4 3C0F8003 */  lui   $t7, %hi(D_8002CC6C) 
/* 055A28 7F020EF8 25EFCC6C */  addiu $t7, %lo(D_8002CC6C) # addiu $t7, $t7, -0x3394
/* 055A2C 7F020EFC AFBF0024 */  sw    $ra, 0x24($sp)
/* 055A30 7F020F00 AFB00020 */  sw    $s0, 0x20($sp)
/* 055A34 7F020F04 AFA40158 */  sw    $a0, 0x158($sp)
/* 055A38 7F020F08 25E8003C */  addiu $t0, $t7, 0x3c
/* 055A3C 7F020F0C 27AE0118 */  addiu $t6, $sp, 0x118
.L7F020F10:
/* 055A40 7F020F10 8DE10000 */  lw    $at, ($t7)
/* 055A44 7F020F14 25EF000C */  addiu $t7, $t7, 0xc
/* 055A48 7F020F18 25CE000C */  addiu $t6, $t6, 0xc
/* 055A4C 7F020F1C ADC1FFF4 */  sw    $at, -0xc($t6)
/* 055A50 7F020F20 8DE1FFF8 */  lw    $at, -8($t7)
/* 055A54 7F020F24 ADC1FFF8 */  sw    $at, -8($t6)
/* 055A58 7F020F28 8DE1FFFC */  lw    $at, -4($t7)
/* 055A5C 7F020F2C 15E8FFF8 */  bne   $t7, $t0, .L7F020F10
/* 055A60 7F020F30 ADC1FFFC */   sw    $at, -4($t6)
/* 055A64 7F020F34 8DE10000 */  lw    $at, ($t7)
/* 055A68 7F020F38 3C0C8005 */  lui   $t4, %hi(g_ClockTimer) 
/* 055A6C 7F020F3C 240B0001 */  li    $t3, 1
/* 055A70 7F020F40 ADC10000 */  sw    $at, ($t6)
/* 055A74 7F020F44 8FA90158 */  lw    $t1, 0x158($sp)
/* 055A78 7F020F48 8D8C8374 */  lw    $t4, %lo(g_ClockTimer)($t4)
/* 055A7C 7F020F4C 3C188003 */  lui   $t8, %hi(D_8002C904) 
/* 055A80 7F020F50 8D300004 */  lw    $s0, 4($t1)
/* 055A84 7F020F54 8E0A001C */  lw    $t2, 0x1c($s0)
/* 055A88 7F020F58 AFAB0108 */  sw    $t3, 0x108($sp)
/* 055A8C 7F020F5C AFAC0104 */  sw    $t4, 0x104($sp)
/* 055A90 7F020F60 AFAA0110 */  sw    $t2, 0x110($sp)
/* 055A94 7F020F64 8E020014 */  lw    $v0, 0x14($s0)
/* 055A98 7F020F68 304D0400 */  andi  $t5, $v0, 0x400
/* 055A9C 7F020F6C 11A00003 */  beqz  $t5, .L7F020F7C
/* 055AA0 7F020F70 0002CB40 */   sll   $t9, $v0, 0xd
/* 055AA4 7F020F74 07230035 */  bgezl $t9, .L7F02104C
/* 055AA8 7F020F78 96180012 */   lhu   $t8, 0x12($s0)
.L7F020F7C:
/* 055AAC 7F020F7C 8F18C904 */  lw    $t8, %lo(D_8002C904)($t8)
/* 055AB0 7F020F80 3C088003 */  lui   $t0, %hi(g_AnimationTablePointerCountRelated) 
/* 055AB4 7F020F84 1300001E */  beqz  $t8, .L7F021000
/* 055AB8 7F020F88 00000000 */   nop   
/* 055ABC 7F020F8C 8D08C908 */  lw    $t0, %lo(g_AnimationTablePointerCountRelated)($t0)
/* 055AC0 7F020F90 3C0E8003 */  lui   $t6, %hi(animation_table_ptrs1)
/* 055AC4 7F020F94 24010001 */  li    $at, 1
/* 055AC8 7F020F98 00087880 */  sll   $t7, $t0, 2
/* 055ACC 7F020F9C 01CF7021 */  addu  $t6, $t6, $t7
/* 055AD0 7F020FA0 8DCE9D6C */  lw    $t6, %lo(animation_table_ptrs1)($t6)
/* 055AD4 7F020FA4 11C1001D */  beq   $t6, $at, .L7F02101C
/* 055AD8 7F020FA8 00000000 */   nop   
/* 055ADC 7F020FAC 0FC1BD6B */  jal   objecthandlerGetModelAnim
/* 055AE0 7F020FB0 8FA40110 */   lw    $a0, 0x110($sp)
/* 055AE4 7F020FB4 3C098003 */  lui   $t1, %hi(g_AnimationTablePointerCountRelated) 
/* 055AE8 7F020FB8 8D29C908 */  lw    $t1, %lo(g_AnimationTablePointerCountRelated)($t1)
/* 055AEC 7F020FBC 3C058003 */  lui   $a1, %hi(animation_table_ptrs1)
/* 055AF0 7F020FC0 8FA40110 */  lw    $a0, 0x110($sp)
/* 055AF4 7F020FC4 00095080 */  sll   $t2, $t1, 2
/* 055AF8 7F020FC8 00AA2821 */  addu  $a1, $a1, $t2
/* 055AFC 7F020FCC 8CA59D6C */  lw    $a1, %lo(animation_table_ptrs1)($a1)
/* 055B00 7F020FD0 00003025 */  move  $a2, $zero
/* 055B04 7F020FD4 10450011 */  beq   $v0, $a1, .L7F02101C
/* 055B08 7F020FD8 00000000 */   nop   
/* 055B0C 7F020FDC 44800000 */  mtc1  $zero, $f0
/* 055B10 7F020FE0 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 055B14 7F020FE4 44812000 */  mtc1  $at, $f4
/* 055B18 7F020FE8 44070000 */  mfc1  $a3, $f0
/* 055B1C 7F020FEC E7A00014 */  swc1  $f0, 0x14($sp)
/* 055B20 7F020FF0 0FC1BF2A */  jal   modelSetAnimation
/* 055B24 7F020FF4 E7A40010 */   swc1  $f4, 0x10($sp)
/* 055B28 7F020FF8 10000008 */  b     .L7F02101C
/* 055B2C 7F020FFC 00000000 */   nop   
.L7F021000:
/* 055B30 7F021000 0FC0C9AF */  jal   chrlvActionTick
/* 055B34 7F021004 02002025 */   move  $a0, $s0
/* 055B38 7F021008 8E0B001C */  lw    $t3, 0x1c($s0)
/* 055B3C 7F02100C 15600003 */  bnez  $t3, .L7F02101C
/* 055B40 7F021010 00000000 */   nop   
/* 055B44 7F021014 100002BD */  b     .L7F021B0C
/* 055B48 7F021018 24020001 */   li    $v0, 1
.L7F02101C:
/* 055B4C 7F02101C 3C0C8003 */  lui   $t4, %hi(D_8002C90C) 
/* 055B50 7F021020 8D8CC90C */  lw    $t4, %lo(D_8002C90C)($t4)
/* 055B54 7F021024 3C0D8003 */  lui   $t5, %hi(D_8002C910) 
/* 055B58 7F021028 51800008 */  beql  $t4, $zero, .L7F02104C
/* 055B5C 7F02102C 96180012 */   lhu   $t8, 0x12($s0)
/* 055B60 7F021030 8DADC910 */  lw    $t5, %lo(D_8002C910)($t5)
/* 055B64 7F021034 AFA00104 */  sw    $zero, 0x104($sp)
/* 055B68 7F021038 24190001 */  li    $t9, 1
/* 055B6C 7F02103C 51A00003 */  beql  $t5, $zero, .L7F02104C
/* 055B70 7F021040 96180012 */   lhu   $t8, 0x12($s0)
/* 055B74 7F021044 AFB90104 */  sw    $t9, 0x104($sp)
/* 055B78 7F021048 96180012 */  lhu   $t8, 0x12($s0)
.L7F02104C:
/* 055B7C 7F02104C 33080020 */  andi  $t0, $t8, 0x20
/* 055B80 7F021050 51000006 */  beql  $t0, $zero, .L7F02106C
/* 055B84 7F021054 8E020160 */   lw    $v0, 0x160($s0)
/* 055B88 7F021058 0FC08105 */  jal   disable_sounds_attached_to_player_then_something
/* 055B8C 7F02105C 8FA40158 */   lw    $a0, 0x158($sp)
/* 055B90 7F021060 100002AA */  b     .L7F021B0C
/* 055B94 7F021064 24020001 */   li    $v0, 1
/* 055B98 7F021068 8E020160 */  lw    $v0, 0x160($s0)
.L7F02106C:
/* 055B9C 7F02106C 50400009 */  beql  $v0, $zero, .L7F021094
/* 055BA0 7F021070 8E020164 */   lw    $v0, 0x164($s0)
/* 055BA4 7F021074 8C440004 */  lw    $a0, 4($v0)
/* 055BA8 7F021078 8C8F0064 */  lw    $t7, 0x64($a0)
/* 055BAC 7F02107C 31EE0004 */  andi  $t6, $t7, 4
/* 055BB0 7F021080 51C00004 */  beql  $t6, $zero, .L7F021094
/* 055BB4 7F021084 8E020164 */   lw    $v0, 0x164($s0)
/* 055BB8 7F021088 0FC10409 */  jal   objFreePermanently
/* 055BBC 7F02108C 24050001 */   li    $a1, 1
/* 055BC0 7F021090 8E020164 */  lw    $v0, 0x164($s0)
.L7F021094:
/* 055BC4 7F021094 50400009 */  beql  $v0, $zero, .L7F0210BC
/* 055BC8 7F021098 8E020014 */   lw    $v0, 0x14($s0)
/* 055BCC 7F02109C 8C440004 */  lw    $a0, 4($v0)
/* 055BD0 7F0210A0 8C890064 */  lw    $t1, 0x64($a0)
/* 055BD4 7F0210A4 312A0004 */  andi  $t2, $t1, 4
/* 055BD8 7F0210A8 51400004 */  beql  $t2, $zero, .L7F0210BC
/* 055BDC 7F0210AC 8E020014 */   lw    $v0, 0x14($s0)
/* 055BE0 7F0210B0 0FC10409 */  jal   objFreePermanently
/* 055BE4 7F0210B4 24050001 */   li    $a1, 1
/* 055BE8 7F0210B8 8E020014 */  lw    $v0, 0x14($s0)
.L7F0210BC:
/* 055BEC 7F0210BC 8FAC0158 */  lw    $t4, 0x158($sp)
/* 055BF0 7F0210C0 304B0400 */  andi  $t3, $v0, 0x400
/* 055BF4 7F0210C4 51600005 */  beql  $t3, $zero, .L7F0210DC
/* 055BF8 7F0210C8 918D0000 */   lbu   $t5, ($t4)
/* 055BFC 7F0210CC AFA0010C */  sw    $zero, 0x10c($sp)
/* 055C00 7F0210D0 100000BD */  b     .L7F0213C8
/* 055C04 7F0210D4 82030007 */   lb    $v1, 7($s0)
/* 055C08 7F0210D8 918D0000 */  lbu   $t5, ($t4)
.L7F0210DC:
/* 055C0C 7F0210DC 24010006 */  li    $at, 6
/* 055C10 7F0210E0 55A1000D */  bnel  $t5, $at, .L7F021118
/* 055C14 7F0210E4 00027A00 */   sll   $t7, $v0, 8
/* 055C18 7F0210E8 0FC26C57 */  jal   sub_GAME_7F09B15C
/* 055C1C 7F0210EC 01802025 */   move  $a0, $t4
/* 055C20 7F0210F0 0002C880 */  sll   $t9, $v0, 2
/* 055C24 7F0210F4 3C188008 */  lui   $t8, %hi(g_playerPointers)
/* 055C28 7F0210F8 0319C021 */  addu  $t8, $t8, $t9
/* 055C2C 7F0210FC 8F189EE0 */  lw    $t8, %lo(g_playerPointers)($t8)
/* 055C30 7F021100 24010001 */  li    $at, 1
/* 055C34 7F021104 8F080000 */  lw    $t0, ($t8)
/* 055C38 7F021108 51010005 */  beql  $t0, $at, .L7F021120
/* 055C3C 7F02110C 240E0001 */   li    $t6, 1
/* 055C40 7F021110 8E020014 */  lw    $v0, 0x14($s0)
/* 055C44 7F021114 00027A00 */  sll   $t7, $v0, 8
.L7F021118:
/* 055C48 7F021118 05E10017 */  bgez  $t7, .L7F021178
/* 055C4C 7F02111C 240E0001 */   li    $t6, 1
.L7F021120:
/* 055C50 7F021120 AFAE010C */  sw    $t6, 0x10c($sp)
/* 055C54 7F021124 82090007 */  lb    $t1, 7($s0)
/* 055C58 7F021128 24010003 */  li    $at, 3
/* 055C5C 7F02112C 02002025 */  move  $a0, $s0
/* 055C60 7F021130 1521000D */  bne   $t1, $at, .L7F021168
/* 055C64 7F021134 00000000 */   nop   
/* 055C68 7F021138 8E0A002C */  lw    $t2, 0x2c($s0)
/* 055C6C 7F02113C 1540000A */  bnez  $t2, .L7F021168
/* 055C70 7F021140 00000000 */   nop   
/* 055C74 7F021144 8E0B003C */  lw    $t3, 0x3c($s0)
/* 055C78 7F021148 8FA50104 */  lw    $a1, 0x104($sp)
/* 055C7C 7F02114C 00003025 */  move  $a2, $zero
/* 055C80 7F021150 11600005 */  beqz  $t3, .L7F021168
/* 055C84 7F021154 00000000 */   nop   
/* 055C88 7F021158 0FC1C2BB */  jal   sub_GAME_7F070AEC
/* 055C8C 7F02115C 8FA40110 */   lw    $a0, 0x110($sp)
/* 055C90 7F021160 10000003 */  b     .L7F021170
/* 055C94 7F021164 00000000 */   nop   
.L7F021168:
/* 055C98 7F021168 0FC08390 */  jal   chrPositionRelated7F020E40
/* 055C9C 7F02116C 8FA50104 */   lw    $a1, 0x104($sp)
.L7F021170:
/* 055CA0 7F021170 10000095 */  b     .L7F0213C8
/* 055CA4 7F021174 82030007 */   lb    $v1, 7($s0)
.L7F021178:
/* 055CA8 7F021178 82030007 */  lb    $v1, 7($s0)
/* 055CAC 7F02117C 2406000E */  li    $a2, 14
/* 055CB0 7F021180 2401000F */  li    $at, 15
/* 055CB4 7F021184 10C30003 */  beq   $a2, $v1, .L7F021194
/* 055CB8 7F021188 00000000 */   nop   
/* 055CBC 7F02118C 54610041 */  bnel  $v1, $at, .L7F021294
/* 055CC0 7F021190 24010003 */   li    $at, 3
.L7F021194:
/* 055CC4 7F021194 54C30005 */  bnel  $a2, $v1, .L7F0211AC
/* 055CC8 7F021198 2401000F */   li    $at, 15
/* 055CCC 7F02119C 820D0038 */  lb    $t5, 0x38($s0)
/* 055CD0 7F0211A0 24010006 */  li    $at, 6
/* 055CD4 7F0211A4 11A10007 */  beq   $t5, $at, .L7F0211C4
/* 055CD8 7F0211A8 2401000F */   li    $at, 15
.L7F0211AC:
/* 055CDC 7F0211AC 1461001E */  bne   $v1, $at, .L7F021228
/* 055CE0 7F0211B0 02002025 */   move  $a0, $s0
/* 055CE4 7F0211B4 820C005C */  lb    $t4, 0x5c($s0)
/* 055CE8 7F0211B8 24010006 */  li    $at, 6
/* 055CEC 7F0211BC 1581001A */  bne   $t4, $at, .L7F021228
/* 055CF0 7F0211C0 00000000 */   nop   
.L7F0211C4:
/* 055CF4 7F0211C4 0FC1B403 */  jal   getinstsize
/* 055CF8 7F0211C8 8FA40110 */   lw    $a0, 0x110($sp)
/* 055CFC 7F0211CC 8FA40158 */  lw    $a0, 0x158($sp)
/* 055D00 7F0211D0 44060000 */  mfc1  $a2, $f0
/* 055D04 7F0211D4 24070001 */  li    $a3, 1
/* 055D08 7F0211D8 24850008 */  addiu $a1, $a0, 8
/* 055D0C 7F0211DC 0FC1535B */  jal   sub_GAME_7F054D6C
/* 055D10 7F0211E0 AFA50030 */   sw    $a1, 0x30($sp)
/* 055D14 7F0211E4 10400028 */  beqz  $v0, .L7F021288
/* 055D18 7F0211E8 AFA2010C */   sw    $v0, 0x10c($sp)
/* 055D1C 7F0211EC 8FA40110 */  lw    $a0, 0x110($sp)
/* 055D20 7F0211F0 0FC1B2E6 */  jal   getsuboffset
/* 055D24 7F0211F4 260500BC */   addiu $a1, $s0, 0xbc
/* 055D28 7F0211F8 0FC1B5AC */  jal   subcalcpos
/* 055D2C 7F0211FC 8FA40110 */   lw    $a0, 0x110($sp)
/* 055D30 7F021200 8FA40158 */  lw    $a0, 0x158($sp)
/* 055D34 7F021204 0FC10027 */  jal   set_color_shading_from_tile
/* 055D38 7F021208 260500F8 */   addiu $a1, $s0, 0xf8
/* 055D3C 7F02120C 8FA40110 */  lw    $a0, 0x110($sp)
/* 055D40 7F021210 0FC1B2E6 */  jal   getsuboffset
/* 055D44 7F021214 8FA50030 */   lw    $a1, 0x30($sp)
/* 055D48 7F021218 0FC08365 */  jal   chrPositionRelated7F020D94
/* 055D4C 7F02121C 02002025 */   move  $a0, $s0
/* 055D50 7F021220 10000019 */  b     .L7F021288
/* 055D54 7F021224 00000000 */   nop   
.L7F021228:
/* 055D58 7F021228 0FC08390 */  jal   chrPositionRelated7F020E40
/* 055D5C 7F02122C 8FA50104 */   lw    $a1, 0x104($sp)
/* 055D60 7F021230 0FC1B403 */  jal   getinstsize
/* 055D64 7F021234 8FA40110 */   lw    $a0, 0x110($sp)
/* 055D68 7F021238 8FA40158 */  lw    $a0, 0x158($sp)
/* 055D6C 7F02123C 44060000 */  mfc1  $a2, $f0
/* 055D70 7F021240 24070001 */  li    $a3, 1
/* 055D74 7F021244 0FC1535B */  jal   sub_GAME_7F054D6C
/* 055D78 7F021248 24850008 */   addiu $a1, $a0, 8
/* 055D7C 7F02124C 1040000E */  beqz  $v0, .L7F021288
/* 055D80 7F021250 AFA2010C */   sw    $v0, 0x10c($sp)
/* 055D84 7F021254 82030007 */  lb    $v1, 7($s0)
/* 055D88 7F021258 2401000E */  li    $at, 14
/* 055D8C 7F02125C 3C088005 */  lui   $t0, %hi(g_GlobalTimer) 
/* 055D90 7F021260 54610005 */  bnel  $v1, $at, .L7F021278
/* 055D94 7F021264 2401000F */   li    $at, 15
/* 055D98 7F021268 8D08837C */  lw    $t0, %lo(g_GlobalTimer)($t0)
/* 055D9C 7F02126C 10000006 */  b     .L7F021288
/* 055DA0 7F021270 AE080078 */   sw    $t0, 0x78($s0)
/* 055DA4 7F021274 2401000F */  li    $at, 15
.L7F021278:
/* 055DA8 7F021278 14610003 */  bne   $v1, $at, .L7F021288
/* 055DAC 7F02127C 3C0F8005 */   lui   $t7, %hi(g_GlobalTimer) 
/* 055DB0 7F021280 8DEF837C */  lw    $t7, %lo(g_GlobalTimer)($t7)
/* 055DB4 7F021284 AE0F009C */  sw    $t7, 0x9c($s0)
.L7F021288:
/* 055DB8 7F021288 1000004F */  b     .L7F0213C8
/* 055DBC 7F02128C 82030007 */   lb    $v1, 7($s0)
/* 055DC0 7F021290 24010003 */  li    $at, 3
.L7F021294:
/* 055DC4 7F021294 5461001C */  bnel  $v1, $at, .L7F021308
/* 055DC8 7F021298 24010001 */   li    $at, 1
/* 055DCC 7F02129C 8E0E002C */  lw    $t6, 0x2c($s0)
/* 055DD0 7F0212A0 55C00019 */  bnezl $t6, .L7F021308
/* 055DD4 7F0212A4 24010001 */   li    $at, 1
/* 055DD8 7F0212A8 0FC1B403 */  jal   getinstsize
/* 055DDC 7F0212AC 8FA40110 */   lw    $a0, 0x110($sp)
/* 055DE0 7F0212B0 8FA40158 */  lw    $a0, 0x158($sp)
/* 055DE4 7F0212B4 44060000 */  mfc1  $a2, $f0
/* 055DE8 7F0212B8 24070001 */  li    $a3, 1
/* 055DEC 7F0212BC 0FC1535B */  jal   sub_GAME_7F054D6C
/* 055DF0 7F0212C0 24850008 */   addiu $a1, $a0, 8
/* 055DF4 7F0212C4 10400009 */  beqz  $v0, .L7F0212EC
/* 055DF8 7F0212C8 AFA2010C */   sw    $v0, 0x10c($sp)
/* 055DFC 7F0212CC 8E0A003C */  lw    $t2, 0x3c($s0)
/* 055E00 7F0212D0 02002025 */  move  $a0, $s0
/* 055E04 7F0212D4 55400006 */  bnezl $t2, .L7F0212F0
/* 055E08 7F0212D8 8FA40110 */   lw    $a0, 0x110($sp)
/* 055E0C 7F0212DC 0FC08390 */  jal   chrPositionRelated7F020E40
/* 055E10 7F0212E0 8FA50104 */   lw    $a1, 0x104($sp)
/* 055E14 7F0212E4 10000005 */  b     .L7F0212FC
/* 055E18 7F0212E8 00000000 */   nop   
.L7F0212EC:
/* 055E1C 7F0212EC 8FA40110 */  lw    $a0, 0x110($sp)
.L7F0212F0:
/* 055E20 7F0212F0 8FA50104 */  lw    $a1, 0x104($sp)
/* 055E24 7F0212F4 0FC1C2BB */  jal   sub_GAME_7F070AEC
/* 055E28 7F0212F8 00003025 */   move  $a2, $zero
.L7F0212FC:
/* 055E2C 7F0212FC 10000032 */  b     .L7F0213C8
/* 055E30 7F021300 82030007 */   lb    $v1, 7($s0)
/* 055E34 7F021304 24010001 */  li    $at, 1
.L7F021308:
/* 055E38 7F021308 1461001C */  bne   $v1, $at, .L7F02137C
/* 055E3C 7F02130C 30484000 */   andi  $t0, $v0, 0x4000
/* 055E40 7F021310 0FC1B403 */  jal   getinstsize
/* 055E44 7F021314 8FA40110 */   lw    $a0, 0x110($sp)
/* 055E48 7F021318 8FA40158 */  lw    $a0, 0x158($sp)
/* 055E4C 7F02131C 44060000 */  mfc1  $a2, $f0
/* 055E50 7F021320 24070001 */  li    $a3, 1
/* 055E54 7F021324 0FC1535B */  jal   sub_GAME_7F054D6C
/* 055E58 7F021328 24850008 */   addiu $a1, $a0, 8
/* 055E5C 7F02132C 14400005 */  bnez  $v0, .L7F021344
/* 055E60 7F021330 AFA2010C */   sw    $v0, 0x10c($sp)
/* 055E64 7F021334 8E0D0014 */  lw    $t5, 0x14($s0)
/* 055E68 7F021338 8FB90110 */  lw    $t9, 0x110($sp)
/* 055E6C 7F02133C 31AC0001 */  andi  $t4, $t5, 1
/* 055E70 7F021340 11800005 */  beqz  $t4, .L7F021358
.L7F021344:
/* 055E74 7F021344 02002025 */   move  $a0, $s0
/* 055E78 7F021348 0FC08390 */  jal   chrPositionRelated7F020E40
/* 055E7C 7F02134C 8FA50104 */   lw    $a1, 0x104($sp)
/* 055E80 7F021350 10000008 */  b     .L7F021374
/* 055E84 7F021354 00000000 */   nop   
.L7F021358:
/* 055E88 7F021358 8F380054 */  lw    $t8, 0x54($t9)
/* 055E8C 7F02135C 03202025 */  move  $a0, $t9
/* 055E90 7F021360 8FA50104 */  lw    $a1, 0x104($sp)
/* 055E94 7F021364 13000003 */  beqz  $t8, .L7F021374
/* 055E98 7F021368 00000000 */   nop   
/* 055E9C 7F02136C 0FC1C2BB */  jal   sub_GAME_7F070AEC
/* 055EA0 7F021370 00003025 */   move  $a2, $zero
.L7F021374:
/* 055EA4 7F021374 10000014 */  b     .L7F0213C8
/* 055EA8 7F021378 82030007 */   lb    $v1, 7($s0)
.L7F02137C:
/* 055EAC 7F02137C 11000007 */  beqz  $t0, .L7F02139C
/* 055EB0 7F021380 02002025 */   move  $a0, $s0
/* 055EB4 7F021384 8FA40110 */  lw    $a0, 0x110($sp)
/* 055EB8 7F021388 8FA50104 */  lw    $a1, 0x104($sp)
/* 055EBC 7F02138C 0FC1C2BB */  jal   sub_GAME_7F070AEC
/* 055EC0 7F021390 00003025 */   move  $a2, $zero
/* 055EC4 7F021394 10000003 */  b     .L7F0213A4
/* 055EC8 7F021398 00000000 */   nop   
.L7F02139C:
/* 055ECC 7F02139C 0FC08390 */  jal   chrPositionRelated7F020E40
/* 055ED0 7F0213A0 8FA50104 */   lw    $a1, 0x104($sp)
.L7F0213A4:
/* 055ED4 7F0213A4 0FC1B403 */  jal   getinstsize
/* 055ED8 7F0213A8 8FA40110 */   lw    $a0, 0x110($sp)
/* 055EDC 7F0213AC 8FA40158 */  lw    $a0, 0x158($sp)
/* 055EE0 7F0213B0 44060000 */  mfc1  $a2, $f0
/* 055EE4 7F0213B4 24070001 */  li    $a3, 1
/* 055EE8 7F0213B8 0FC1535B */  jal   sub_GAME_7F054D6C
/* 055EEC 7F0213BC 24850008 */   addiu $a1, $a0, 8
/* 055EF0 7F0213C0 AFA2010C */  sw    $v0, 0x10c($sp)
/* 055EF4 7F0213C4 82030007 */  lb    $v1, 7($s0)
.L7F0213C8:
/* 055EF8 7F0213C8 24010001 */  li    $at, 1
/* 055EFC 7F0213CC 14610009 */  bne   $v1, $at, .L7F0213F4
/* 055F00 7F0213D0 8FAE0110 */   lw    $t6, 0x110($sp)
/* 055F04 7F0213D4 8DC90054 */  lw    $t1, 0x54($t6)
/* 055F08 7F0213D8 8FAA0158 */  lw    $t2, 0x158($sp)
/* 055F0C 7F0213DC 55200006 */  bnezl $t1, .L7F0213F8
/* 055F10 7F0213E0 960D0012 */   lhu   $t5, 0x12($s0)
/* 055F14 7F0213E4 914B0000 */  lbu   $t3, ($t2)
/* 055F18 7F0213E8 24010006 */  li    $at, 6
/* 055F1C 7F0213EC 15610004 */  bne   $t3, $at, .L7F021400
/* 055F20 7F0213F0 00000000 */   nop   
.L7F0213F4:
/* 055F24 7F0213F4 960D0012 */  lhu   $t5, 0x12($s0)
.L7F0213F8:
/* 055F28 7F0213F8 35AC0200 */  ori   $t4, $t5, 0x200
/* 055F2C 7F0213FC A60C0012 */  sh    $t4, 0x12($s0)
.L7F021400:
/* 055F30 7F021400 0FC0817C */  jal   chrAimGlobalTimerTickRelated
/* 055F34 7F021404 02002025 */   move  $a0, $s0
/* 055F38 7F021408 8E040020 */  lw    $a0, 0x20($s0)
/* 055F3C 7F02140C 50800005 */  beql  $a0, $zero, .L7F021424
/* 055F40 7F021410 8FB8010C */   lw    $t8, 0x10c($sp)
/* 055F44 7F021414 0FC1AC92 */  jal   sub_GAME_7F06B248
/* 055F48 7F021418 00000000 */   nop   
/* 055F4C 7F02141C AE000020 */  sw    $zero, 0x20($s0)
/* 055F50 7F021420 8FB8010C */  lw    $t8, 0x10c($sp)
.L7F021424:
/* 055F54 7F021424 261900F8 */  addiu $t9, $s0, 0xf8
/* 055F58 7F021428 53000182 */  beql  $t8, $zero, .L7F021A34
/* 055F5C 7F02142C 8E020160 */   lw    $v0, 0x160($s0)
/* 055F60 7F021430 0FC24412 */  jal   get_debug_chrnum_flag
/* 055F64 7F021434 AFB90030 */   sw    $t9, 0x30($sp)
/* 055F68 7F021438 8FA20158 */  lw    $v0, 0x158($sp)
/* 055F6C 7F02143C 2404000C */  li    $a0, 12
/* 055F70 7F021440 90480001 */  lbu   $t0, 1($v0)
/* 055F74 7F021444 350F0002 */  ori   $t7, $t0, 2
/* 055F78 7F021448 A04F0001 */  sb    $t7, 1($v0)
/* 055F7C 7F02144C 8E0E0014 */  lw    $t6, 0x14($s0)
/* 055F80 7F021450 35C90008 */  ori   $t1, $t6, 8
/* 055F84 7F021454 0FC249EF */  jal   cheatIsActive
/* 055F88 7F021458 AE090014 */   sw    $t1, 0x14($s0)
/* 055F8C 7F02145C 10400004 */  beqz  $v0, .L7F021470
/* 055F90 7F021460 3C013EA0 */   li    $at, 0x3EA00000 # 0.312500
/* 055F94 7F021464 44816000 */  mtc1  $at, $f12
/* 055F98 7F021468 0FC1B103 */  jal   set_float_80036088
/* 055F9C 7F02146C 00000000 */   nop   
.L7F021470:
/* 055FA0 7F021470 3C0A7F02 */  lui   $t2, %hi(sub_GAME_7F02083C) # $t2, 0x7f02
/* 055FA4 7F021474 254A083C */  addiu $t2, %lo(sub_GAME_7F02083C) # addiu $t2, $t2, 0x83c
/* 055FA8 7F021478 3C018003 */  lui   $at, %hi(D_80036090)
/* 055FAC 7F02147C AC2A6090 */  sw    $t2, %lo(D_80036090)($at)
/* 055FB0 7F021480 3C018007 */  lui   $at, %hi(dword_CODE_bss_80069B60)
/* 055FB4 7F021484 0FC1E0F1 */  jal   currentPlayerGetMatrix10CC
/* 055FB8 7F021488 AC309B60 */   sw    $s0, %lo(dword_CODE_bss_80069B60)($at)
/* 055FBC 7F02148C 8FAB0110 */  lw    $t3, 0x110($sp)
/* 055FC0 7F021490 AFA20118 */  sw    $v0, 0x118($sp)
/* 055FC4 7F021494 8D6D0008 */  lw    $t5, 8($t3)
/* 055FC8 7F021498 85A4000E */  lh    $a0, 0xe($t5)
/* 055FCC 7F02149C 00046180 */  sll   $t4, $a0, 6
/* 055FD0 7F0214A0 0FC2F5C5 */  jal   dynAllocate
/* 055FD4 7F0214A4 01802025 */   move  $a0, $t4
/* 055FD8 7F0214A8 3C058007 */  lui   $a1, %hi(dword_CODE_bss_80069B60)
/* 055FDC 7F0214AC 24A59B60 */  addiu $a1, %lo(dword_CODE_bss_80069B60) # addiu $a1, $a1, -0x64a0
/* 055FE0 7F0214B0 8CA30000 */  lw    $v1, ($a1)
/* 055FE4 7F0214B4 AFA20128 */  sw    $v0, 0x128($sp)
/* 055FE8 7F0214B8 80640011 */  lb    $a0, 0x11($v1)
/* 055FEC 7F0214BC 0480000B */  bltz  $a0, .L7F0214EC
/* 055FF0 7F0214C0 3C188005 */   lui   $t8, %hi(g_ClockTimer) 
/* 055FF4 7F0214C4 8F188374 */  lw    $t8, %lo(g_ClockTimer)($t8)
/* 055FF8 7F0214C8 240FFFFF */  li    $t7, -1
/* 055FFC 7F0214CC 0098C821 */  addu  $t9, $a0, $t8
/* 056000 7F0214D0 A0790011 */  sb    $t9, 0x11($v1)
/* 056004 7F0214D4 8CA30000 */  lw    $v1, ($a1)
/* 056008 7F0214D8 80680011 */  lb    $t0, 0x11($v1)
/* 05600C 7F0214DC 2901001E */  slti  $at, $t0, 0x1e
/* 056010 7F0214E0 54200003 */  bnezl $at, .L7F0214F0
/* 056014 7F0214E4 27A40118 */   addiu $a0, $sp, 0x118
/* 056018 7F0214E8 A06F0011 */  sb    $t7, 0x11($v1)
.L7F0214EC:
/* 05601C 7F0214EC 27A40118 */  addiu $a0, $sp, 0x118
.L7F0214F0:
/* 056020 7F0214F0 0FC1BCBE */  jal   subcalcmatrices
/* 056024 7F0214F4 8FA50110 */   lw    $a1, 0x110($sp)
/* 056028 7F0214F8 3C018003 */  lui   $at, %hi(D_80036090)
/* 05602C 7F0214FC AC206090 */  sw    $zero, %lo(D_80036090)($at)
/* 056030 7F021500 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 056034 7F021504 44816000 */  mtc1  $at, $f12
/* 056038 7F021508 0FC1B103 */  jal   set_float_80036088
/* 05603C 7F02150C 00000000 */   nop   
/* 056040 7F021510 260400F4 */  addiu $a0, $s0, 0xf4
/* 056044 7F021514 0FC100C4 */  jal   update_color_shading
/* 056048 7F021518 8FA50030 */   lw    $a1, 0x30($sp)
/* 05604C 7F02151C 0FC1B1DA */  jal   sub_GAME_7F06C768
/* 056050 7F021520 8FA40110 */   lw    $a0, 0x110($sp)
/* 056054 7F021524 8FAE0158 */  lw    $t6, 0x158($sp)
/* 056058 7F021528 00002025 */  move  $a0, $zero
/* 05605C 7F02152C E5C00018 */  swc1  $f0, 0x18($t6)
/* 056060 7F021530 0FC1AC48 */  jal   sub_GAME_7F06B120
/* 056064 7F021534 8FA50110 */   lw    $a1, 0x110($sp)
/* 056068 7F021538 AE020020 */  sw    $v0, 0x20($s0)
/* 05606C 7F02153C 26060020 */  addiu $a2, $s0, 0x20
/* 056070 7F021540 AFA60030 */  sw    $a2, 0x30($sp)
/* 056074 7F021544 8FA40158 */  lw    $a0, 0x158($sp)
/* 056078 7F021548 0FC148FE */  jal   sub_GAME_7F0523F8
/* 05607C 7F02154C 00002825 */   move  $a1, $zero
/* 056080 7F021550 8FA60030 */  lw    $a2, 0x30($sp)
/* 056084 7F021554 8FA40158 */  lw    $a0, 0x158($sp)
/* 056088 7F021558 0FC148FE */  jal   sub_GAME_7F0523F8
/* 05608C 7F02155C 24050001 */   li    $a1, 1
/* 056090 7F021560 8E0201D8 */  lw    $v0, 0x1d8($s0)
/* 056094 7F021564 5040011A */  beql  $v0, $zero, .L7F0219D0
/* 056098 7F021568 8FAD0110 */   lw    $t5, 0x110($sp)
/* 05609C 7F02156C 8C470004 */  lw    $a3, 4($v0)
/* 0560A0 7F021570 90490001 */  lbu   $t1, 1($v0)
/* 0560A4 7F021574 00003025 */  move  $a2, $zero
/* 0560A8 7F021578 8CE30014 */  lw    $v1, 0x14($a3)
/* 0560AC 7F02157C 352A0002 */  ori   $t2, $t1, 2
/* 0560B0 7F021580 A04A0001 */  sb    $t2, 1($v0)
/* 0560B4 7F021584 8C65001C */  lw    $a1, 0x1c($v1)
/* 0560B8 7F021588 8FA40110 */  lw    $a0, 0x110($sp)
/* 0560BC 7F02158C AFA70100 */  sw    $a3, 0x100($sp)
/* 0560C0 7F021590 0FC1B198 */  jal   sub_GAME_7F06C660
/* 0560C4 7F021594 AFA300FC */   sw    $v1, 0xfc($sp)
/* 0560C8 7F021598 8FAB00FC */  lw    $t3, 0xfc($sp)
/* 0560CC 7F02159C AFA20118 */  sw    $v0, 0x118($sp)
/* 0560D0 7F0215A0 8D6D0008 */  lw    $t5, 8($t3)
/* 0560D4 7F0215A4 85A4000E */  lh    $a0, 0xe($t5)
/* 0560D8 7F0215A8 00046180 */  sll   $t4, $a0, 6
/* 0560DC 7F0215AC 0FC2F5C5 */  jal   dynAllocate
/* 0560E0 7F0215B0 01802025 */   move  $a0, $t4
/* 0560E4 7F0215B4 AFA20128 */  sw    $v0, 0x128($sp)
/* 0560E8 7F0215B8 27A40118 */  addiu $a0, $sp, 0x118
/* 0560EC 7F0215BC 0FC1BC92 */  jal   instcalcmatrices
/* 0560F0 7F0215C0 8FA500FC */   lw    $a1, 0xfc($sp)
/* 0560F4 7F0215C4 82020006 */  lb    $v0, 6($s0)
/* 0560F8 7F0215C8 2841002A */  slti  $at, $v0, 0x2a
/* 0560FC 7F0215CC 142000F2 */  bnez  $at, .L7F021998
/* 056100 7F0215D0 28410046 */   slti  $at, $v0, 0x46
/* 056104 7F0215D4 102000F0 */  beqz  $at, .L7F021998
/* 056108 7F0215D8 3C198003 */   lui   $t9, %hi(D_8002CCAC) 
/* 05610C 7F0215DC 2739CCAC */  addiu $t9, %lo(D_8002CCAC) # addiu $t9, $t9, -0x3354
/* 056110 7F0215E0 8F210000 */  lw    $at, ($t9)
/* 056114 7F0215E4 27B800F0 */  addiu $t8, $sp, 0xf0
/* 056118 7F0215E8 8F2F0004 */  lw    $t7, 4($t9)
/* 05611C 7F0215EC AF010000 */  sw    $at, ($t8)
/* 056120 7F0215F0 8F210008 */  lw    $at, 8($t9)
/* 056124 7F0215F4 AF0F0004 */  sw    $t7, 4($t8)
/* 056128 7F0215F8 AF010008 */  sw    $at, 8($t8)
/* 05612C 7F0215FC 0FC149A1 */  jal   get_hat_model
/* 056130 7F021600 8E0401D8 */   lw    $a0, 0x1d8($s0)
/* 056134 7F021604 AFA20060 */  sw    $v0, 0x60($sp)
/* 056138 7F021608 82040006 */  lb    $a0, 6($s0)
/* 05613C 7F02160C 00024880 */  sll   $t1, $v0, 2
/* 056140 7F021610 01224823 */  subu  $t1, $t1, $v0
/* 056144 7F021614 2484FFD6 */  addiu $a0, $a0, -0x2a
/* 056148 7F021618 000470C0 */  sll   $t6, $a0, 3
/* 05614C 7F02161C 01C47021 */  addu  $t6, $t6, $a0
/* 056150 7F021620 000E7100 */  sll   $t6, $t6, 4
/* 056154 7F021624 000948C0 */  sll   $t1, $t1, 3
/* 056158 7F021628 3C0B8004 */  lui   $t3, %hi(headHat_array_8003E464) 
/* 05615C 7F02162C 256BE464 */  addiu $t3, %lo(headHat_array_8003E464) # addiu $t3, $t3, -0x1b9c
/* 056160 7F021630 01C95021 */  addu  $t2, $t6, $t1
/* 056164 7F021634 014B1821 */  addu  $v1, $t2, $t3
/* 056168 7F021638 0FC243BF */  jal   get_debug_render_raster
/* 05616C 7F02163C AFA30058 */   sw    $v1, 0x58($sp)
/* 056170 7F021640 144000AA */  bnez  $v0, .L7F0218EC
/* 056174 7F021644 8FA30058 */   lw    $v1, 0x58($sp)
/* 056178 7F021648 AFA00054 */  sw    $zero, 0x54($sp)
/* 05617C 7F02164C 00002025 */  move  $a0, $zero
/* 056180 7F021650 24050020 */  li    $a1, 32
/* 056184 7F021654 0C0030C3 */  jal   joyGetButtons
/* 056188 7F021658 AFA30058 */   sw    $v1, 0x58($sp)
/* 05618C 7F02165C 1040004F */  beqz  $v0, .L7F02179C
/* 056190 7F021660 8FA30058 */   lw    $v1, 0x58($sp)
/* 056194 7F021664 00002025 */  move  $a0, $zero
/* 056198 7F021668 34058000 */  li    $a1, 32768
/* 05619C 7F02166C 0C0030C3 */  jal   joyGetButtons
/* 0561A0 7F021670 AFA30058 */   sw    $v1, 0x58($sp)
/* 0561A4 7F021674 10400008 */  beqz  $v0, .L7F021698
/* 0561A8 7F021678 8FA30058 */   lw    $v1, 0x58($sp)
/* 0561AC 7F02167C 3C018005 */  lui   $at, %hi(D_80051D58)
/* 0561B0 7F021680 C4281D58 */  lwc1  $f8, %lo(D_80051D58)($at)
/* 0561B4 7F021684 C4660008 */  lwc1  $f6, 8($v1)
/* 0561B8 7F021688 240D0001 */  li    $t5, 1
/* 0561BC 7F02168C 46083281 */  sub.s $f10, $f6, $f8
/* 0561C0 7F021690 E46A0008 */  swc1  $f10, 8($v1)
/* 0561C4 7F021694 AFAD0054 */  sw    $t5, 0x54($sp)
.L7F021698:
/* 0561C8 7F021698 00002025 */  move  $a0, $zero
/* 0561CC 7F02169C 24054000 */  li    $a1, 16384
/* 0561D0 7F0216A0 0C0030C3 */  jal   joyGetButtons
/* 0561D4 7F0216A4 AFA30058 */   sw    $v1, 0x58($sp)
/* 0561D8 7F0216A8 10400008 */  beqz  $v0, .L7F0216CC
/* 0561DC 7F0216AC 8FA30058 */   lw    $v1, 0x58($sp)
/* 0561E0 7F0216B0 3C018005 */  lui   $at, %hi(D_80051D5C)
/* 0561E4 7F0216B4 C4321D5C */  lwc1  $f18, %lo(D_80051D5C)($at)
/* 0561E8 7F0216B8 C4700008 */  lwc1  $f16, 8($v1)
/* 0561EC 7F0216BC 240C0001 */  li    $t4, 1
/* 0561F0 7F0216C0 46128100 */  add.s $f4, $f16, $f18
/* 0561F4 7F0216C4 E4640008 */  swc1  $f4, 8($v1)
/* 0561F8 7F0216C8 AFAC0054 */  sw    $t4, 0x54($sp)
.L7F0216CC:
/* 0561FC 7F0216CC 00002025 */  move  $a0, $zero
/* 056200 7F0216D0 24050004 */  li    $a1, 4
/* 056204 7F0216D4 0C0030C3 */  jal   joyGetButtons
/* 056208 7F0216D8 AFA30058 */   sw    $v1, 0x58($sp)
/* 05620C 7F0216DC 10400008 */  beqz  $v0, .L7F021700
/* 056210 7F0216E0 8FA30058 */   lw    $v1, 0x58($sp)
/* 056214 7F0216E4 3C018005 */  lui   $at, %hi(D_80051D60)
/* 056218 7F0216E8 C4281D60 */  lwc1  $f8, %lo(D_80051D60)($at)
/* 05621C 7F0216EC C4660004 */  lwc1  $f6, 4($v1)
/* 056220 7F0216F0 24080001 */  li    $t0, 1
/* 056224 7F0216F4 46083281 */  sub.s $f10, $f6, $f8
/* 056228 7F0216F8 E46A0004 */  swc1  $f10, 4($v1)
/* 05622C 7F0216FC AFA80054 */  sw    $t0, 0x54($sp)
.L7F021700:
/* 056230 7F021700 00002025 */  move  $a0, $zero
/* 056234 7F021704 24050008 */  li    $a1, 8
/* 056238 7F021708 0C0030C3 */  jal   joyGetButtons
/* 05623C 7F02170C AFA30058 */   sw    $v1, 0x58($sp)
/* 056240 7F021710 10400008 */  beqz  $v0, .L7F021734
/* 056244 7F021714 8FA30058 */   lw    $v1, 0x58($sp)
/* 056248 7F021718 3C018005 */  lui   $at, %hi(D_80051D64)
/* 05624C 7F02171C C4321D64 */  lwc1  $f18, %lo(D_80051D64)($at)
/* 056250 7F021720 C4700004 */  lwc1  $f16, 4($v1)
/* 056254 7F021724 24180001 */  li    $t8, 1
/* 056258 7F021728 46128100 */  add.s $f4, $f16, $f18
/* 05625C 7F02172C E4640004 */  swc1  $f4, 4($v1)
/* 056260 7F021730 AFB80054 */  sw    $t8, 0x54($sp)
.L7F021734:
/* 056264 7F021734 00002025 */  move  $a0, $zero
/* 056268 7F021738 24050002 */  li    $a1, 2
/* 05626C 7F02173C 0C0030C3 */  jal   joyGetButtons
/* 056270 7F021740 AFA30058 */   sw    $v1, 0x58($sp)
/* 056274 7F021744 10400008 */  beqz  $v0, .L7F021768
/* 056278 7F021748 8FA30058 */   lw    $v1, 0x58($sp)
/* 05627C 7F02174C 3C018005 */  lui   $at, %hi(D_80051D68)
/* 056280 7F021750 C4281D68 */  lwc1  $f8, %lo(D_80051D68)($at)
/* 056284 7F021754 C4660000 */  lwc1  $f6, ($v1)
/* 056288 7F021758 24190001 */  li    $t9, 1
/* 05628C 7F02175C 46083281 */  sub.s $f10, $f6, $f8
/* 056290 7F021760 E46A0000 */  swc1  $f10, ($v1)
/* 056294 7F021764 AFB90054 */  sw    $t9, 0x54($sp)
.L7F021768:
/* 056298 7F021768 00002025 */  move  $a0, $zero
/* 05629C 7F02176C 24050001 */  li    $a1, 1
/* 0562A0 7F021770 0C0030C3 */  jal   joyGetButtons
/* 0562A4 7F021774 AFA30058 */   sw    $v1, 0x58($sp)
/* 0562A8 7F021778 10400008 */  beqz  $v0, .L7F02179C
/* 0562AC 7F02177C 8FA30058 */   lw    $v1, 0x58($sp)
/* 0562B0 7F021780 3C018005 */  lui   $at, %hi(D_80051D6C)
/* 0562B4 7F021784 C4321D6C */  lwc1  $f18, %lo(D_80051D6C)($at)
/* 0562B8 7F021788 C4700000 */  lwc1  $f16, ($v1)
/* 0562BC 7F02178C 240F0001 */  li    $t7, 1
/* 0562C0 7F021790 46128100 */  add.s $f4, $f16, $f18
/* 0562C4 7F021794 E4640000 */  swc1  $f4, ($v1)
/* 0562C8 7F021798 AFAF0054 */  sw    $t7, 0x54($sp)
.L7F02179C:
/* 0562CC 7F02179C 00002025 */  move  $a0, $zero
/* 0562D0 7F0217A0 24050010 */  li    $a1, 16
/* 0562D4 7F0217A4 0C0030C3 */  jal   joyGetButtons
/* 0562D8 7F0217A8 AFA30058 */   sw    $v1, 0x58($sp)
/* 0562DC 7F0217AC 1040004F */  beqz  $v0, .L7F0218EC
/* 0562E0 7F0217B0 8FA30058 */   lw    $v1, 0x58($sp)
/* 0562E4 7F0217B4 00002025 */  move  $a0, $zero
/* 0562E8 7F0217B8 34058000 */  li    $a1, 32768
/* 0562EC 7F0217BC 0C0030C3 */  jal   joyGetButtons
/* 0562F0 7F0217C0 AFA30058 */   sw    $v1, 0x58($sp)
/* 0562F4 7F0217C4 10400008 */  beqz  $v0, .L7F0217E8
/* 0562F8 7F0217C8 8FA30058 */   lw    $v1, 0x58($sp)
/* 0562FC 7F0217CC 3C018005 */  lui   $at, %hi(D_80051D70)
/* 056300 7F0217D0 C4281D70 */  lwc1  $f8, %lo(D_80051D70)($at)
/* 056304 7F0217D4 C4660014 */  lwc1  $f6, 0x14($v1)
/* 056308 7F0217D8 240E0001 */  li    $t6, 1
/* 05630C 7F0217DC 46083282 */  mul.s $f10, $f6, $f8
/* 056310 7F0217E0 E46A0014 */  swc1  $f10, 0x14($v1)
/* 056314 7F0217E4 AFAE0054 */  sw    $t6, 0x54($sp)
.L7F0217E8:
/* 056318 7F0217E8 00002025 */  move  $a0, $zero
/* 05631C 7F0217EC 24054000 */  li    $a1, 16384
/* 056320 7F0217F0 0C0030C3 */  jal   joyGetButtons
/* 056324 7F0217F4 AFA30058 */   sw    $v1, 0x58($sp)
/* 056328 7F0217F8 10400008 */  beqz  $v0, .L7F02181C
/* 05632C 7F0217FC 8FA30058 */   lw    $v1, 0x58($sp)
/* 056330 7F021800 3C018005 */  lui   $at, %hi(D_80051D74)
/* 056334 7F021804 C4321D74 */  lwc1  $f18, %lo(D_80051D74)($at)
/* 056338 7F021808 C4700014 */  lwc1  $f16, 0x14($v1)
/* 05633C 7F02180C 24090001 */  li    $t1, 1
/* 056340 7F021810 46128102 */  mul.s $f4, $f16, $f18
/* 056344 7F021814 E4640014 */  swc1  $f4, 0x14($v1)
/* 056348 7F021818 AFA90054 */  sw    $t1, 0x54($sp)
.L7F02181C:
/* 05634C 7F02181C 00002025 */  move  $a0, $zero
/* 056350 7F021820 24050004 */  li    $a1, 4
/* 056354 7F021824 0C0030C3 */  jal   joyGetButtons
/* 056358 7F021828 AFA30058 */   sw    $v1, 0x58($sp)
/* 05635C 7F02182C 10400008 */  beqz  $v0, .L7F021850
/* 056360 7F021830 8FA30058 */   lw    $v1, 0x58($sp)
/* 056364 7F021834 3C018005 */  lui   $at, %hi(D_80051D78)
/* 056368 7F021838 C4281D78 */  lwc1  $f8, %lo(D_80051D78)($at)
/* 05636C 7F02183C C4660010 */  lwc1  $f6, 0x10($v1)
/* 056370 7F021840 240A0001 */  li    $t2, 1
/* 056374 7F021844 46083282 */  mul.s $f10, $f6, $f8
/* 056378 7F021848 E46A0010 */  swc1  $f10, 0x10($v1)
/* 05637C 7F02184C AFAA0054 */  sw    $t2, 0x54($sp)
.L7F021850:
/* 056380 7F021850 00002025 */  move  $a0, $zero
/* 056384 7F021854 24050008 */  li    $a1, 8
/* 056388 7F021858 0C0030C3 */  jal   joyGetButtons
/* 05638C 7F02185C AFA30058 */   sw    $v1, 0x58($sp)
/* 056390 7F021860 10400008 */  beqz  $v0, .L7F021884
/* 056394 7F021864 8FA30058 */   lw    $v1, 0x58($sp)
/* 056398 7F021868 3C018005 */  lui   $at, %hi(D_80051D7C)
/* 05639C 7F02186C C4321D7C */  lwc1  $f18, %lo(D_80051D7C)($at)
/* 0563A0 7F021870 C4700010 */  lwc1  $f16, 0x10($v1)
/* 0563A4 7F021874 240B0001 */  li    $t3, 1
/* 0563A8 7F021878 46128102 */  mul.s $f4, $f16, $f18
/* 0563AC 7F02187C E4640010 */  swc1  $f4, 0x10($v1)
/* 0563B0 7F021880 AFAB0054 */  sw    $t3, 0x54($sp)
.L7F021884:
/* 0563B4 7F021884 00002025 */  move  $a0, $zero
/* 0563B8 7F021888 24050002 */  li    $a1, 2
/* 0563BC 7F02188C 0C0030C3 */  jal   joyGetButtons
/* 0563C0 7F021890 AFA30058 */   sw    $v1, 0x58($sp)
/* 0563C4 7F021894 10400008 */  beqz  $v0, .L7F0218B8
/* 0563C8 7F021898 8FA30058 */   lw    $v1, 0x58($sp)
/* 0563CC 7F02189C 3C018005 */  lui   $at, %hi(D_80051D80)
/* 0563D0 7F0218A0 C4281D80 */  lwc1  $f8, %lo(D_80051D80)($at)
/* 0563D4 7F0218A4 C466000C */  lwc1  $f6, 0xc($v1)
/* 0563D8 7F0218A8 240D0001 */  li    $t5, 1
/* 0563DC 7F0218AC 46083282 */  mul.s $f10, $f6, $f8
/* 0563E0 7F0218B0 E46A000C */  swc1  $f10, 0xc($v1)
/* 0563E4 7F0218B4 AFAD0054 */  sw    $t5, 0x54($sp)
.L7F0218B8:
/* 0563E8 7F0218B8 00002025 */  move  $a0, $zero
/* 0563EC 7F0218BC 24050001 */  li    $a1, 1
/* 0563F0 7F0218C0 0C0030C3 */  jal   joyGetButtons
/* 0563F4 7F0218C4 AFA30058 */   sw    $v1, 0x58($sp)
/* 0563F8 7F0218C8 10400008 */  beqz  $v0, .L7F0218EC
/* 0563FC 7F0218CC 8FA30058 */   lw    $v1, 0x58($sp)
/* 056400 7F0218D0 3C018005 */  lui   $at, %hi(D_80051D84)
/* 056404 7F0218D4 C4321D84 */  lwc1  $f18, %lo(D_80051D84)($at)
/* 056408 7F0218D8 C470000C */  lwc1  $f16, 0xc($v1)
/* 05640C 7F0218DC 240C0001 */  li    $t4, 1
/* 056410 7F0218E0 46128102 */  mul.s $f4, $f16, $f18
/* 056414 7F0218E4 E464000C */  swc1  $f4, 0xc($v1)
/* 056418 7F0218E8 AFAC0054 */  sw    $t4, 0x54($sp)
.L7F0218EC:
/* 05641C 7F0218EC 3C018005 */  lui   $at, %hi(D_80051D88)
/* 056420 7F0218F0 C4201D88 */  lwc1  $f0, %lo(D_80051D88)($at)
/* 056424 7F0218F4 C4660000 */  lwc1  $f6, ($v1)
/* 056428 7F0218F8 27A400F0 */  addiu $a0, $sp, 0xf0
/* 05642C 7F0218FC 27A500A4 */  addiu $a1, $sp, 0xa4
/* 056430 7F021900 46003202 */  mul.s $f8, $f6, $f0
/* 056434 7F021904 E7A800F0 */  swc1  $f8, 0xf0($sp)
/* 056438 7F021908 C46A0004 */  lwc1  $f10, 4($v1)
/* 05643C 7F02190C 46005402 */  mul.s $f16, $f10, $f0
/* 056440 7F021910 E7B000F4 */  swc1  $f16, 0xf4($sp)
/* 056444 7F021914 C4720008 */  lwc1  $f18, 8($v1)
/* 056448 7F021918 46009102 */  mul.s $f4, $f18, $f0
/* 05644C 7F02191C E7A400F8 */  swc1  $f4, 0xf8($sp)
/* 056450 7F021920 C466000C */  lwc1  $f6, 0xc($v1)
/* 056454 7F021924 E7A600EC */  swc1  $f6, 0xec($sp)
/* 056458 7F021928 C4680010 */  lwc1  $f8, 0x10($v1)
/* 05645C 7F02192C E7A800E8 */  swc1  $f8, 0xe8($sp)
/* 056460 7F021930 C46A0014 */  lwc1  $f10, 0x14($v1)
/* 056464 7F021934 0FC16259 */  jal   matrix_4x4_set_identity_and_position
/* 056468 7F021938 E7AA00E4 */   swc1  $f10, 0xe4($sp)
/* 05646C 7F02193C C7AC00EC */  lwc1  $f12, 0xec($sp)
/* 056470 7F021940 0FC1626D */  jal   matrix_column_1_scalar_multiply
/* 056474 7F021944 27A500A4 */   addiu $a1, $sp, 0xa4
/* 056478 7F021948 C7AC00E8 */  lwc1  $f12, 0xe8($sp)
/* 05647C 7F02194C 0FC16279 */  jal   matrix_column_2_scalar_multiply
/* 056480 7F021950 27A500A4 */   addiu $a1, $sp, 0xa4
/* 056484 7F021954 C7AC00E4 */  lwc1  $f12, 0xe4($sp)
/* 056488 7F021958 0FC16293 */  jal   matrix_column_3_scalar_multiply_2
/* 05648C 7F02195C 27A500A4 */   addiu $a1, $sp, 0xa4
/* 056490 7F021960 8FA800FC */  lw    $t0, 0xfc($sp)
/* 056494 7F021964 27A500A4 */  addiu $a1, $sp, 0xa4
/* 056498 7F021968 27A60064 */  addiu $a2, $sp, 0x64
/* 05649C 7F02196C 0FC16063 */  jal   matrix_4x4_multiply_homogeneous
/* 0564A0 7F021970 8D04000C */   lw    $a0, 0xc($t0)
/* 0564A4 7F021974 8FB800FC */  lw    $t8, 0xfc($sp)
/* 0564A8 7F021978 27A40064 */  addiu $a0, $sp, 0x64
/* 0564AC 7F02197C 0FC16008 */  jal   matrix_4x4_copy
/* 0564B0 7F021980 8F05000C */   lw    $a1, 0xc($t8)
/* 0564B4 7F021984 8FB90060 */  lw    $t9, 0x60($sp)
/* 0564B8 7F021988 24010002 */  li    $at, 2
/* 0564BC 7F02198C 57210003 */  bnel  $t9, $at, .L7F02199C
/* 0564C0 7F021990 960F0012 */   lhu   $t7, 0x12($s0)
/* 0564C4 7F021994 AFA00108 */  sw    $zero, 0x108($sp)
.L7F021998:
/* 0564C8 7F021998 960F0012 */  lhu   $t7, 0x12($s0)
.L7F02199C:
/* 0564CC 7F02199C 8FA90100 */  lw    $t1, 0x100($sp)
/* 0564D0 7F0219A0 8FA500FC */  lw    $a1, 0xfc($sp)
/* 0564D4 7F0219A4 31EE0001 */  andi  $t6, $t7, 1
/* 0564D8 7F0219A8 11C00005 */  beqz  $t6, .L7F0219C0
/* 0564DC 7F0219AC 00000000 */   nop   
/* 0564E0 7F0219B0 8D2A0064 */  lw    $t2, 0x64($t1)
/* 0564E4 7F0219B4 314B0080 */  andi  $t3, $t2, 0x80
/* 0564E8 7F0219B8 55600005 */  bnezl $t3, .L7F0219D0
/* 0564EC 7F0219BC 8FAD0110 */   lw    $t5, 0x110($sp)
.L7F0219C0:
/* 0564F0 7F0219C0 0FC1AC48 */  jal   sub_GAME_7F06B120
/* 0564F4 7F0219C4 8E040020 */   lw    $a0, 0x20($s0)
/* 0564F8 7F0219C8 AE020020 */  sw    $v0, 0x20($s0)
/* 0564FC 7F0219CC 8FAD0110 */  lw    $t5, 0x110($sp)
.L7F0219D0:
/* 056500 7F0219D0 8DAC0008 */  lw    $t4, 8($t5)
/* 056504 7F0219D4 8D880008 */  lw    $t0, 8($t4)
/* 056508 7F0219D8 8D050010 */  lw    $a1, 0x10($t0)
/* 05650C 7F0219DC 10A0000E */  beqz  $a1, .L7F021A18
/* 056510 7F0219E0 00000000 */   nop   
/* 056514 7F0219E4 0FC1B1E7 */  jal   extract_id_from_object_structure_microcode
/* 056518 7F0219E8 01A02025 */   move  $a0, $t5
/* 05651C 7F0219EC 8C430000 */  lw    $v1, ($v0)
/* 056520 7F0219F0 10600009 */  beqz  $v1, .L7F021A18
/* 056524 7F0219F4 00000000 */   nop   
/* 056528 7F0219F8 8C780008 */  lw    $t8, 8($v1)
/* 05652C 7F0219FC 8F050004 */  lw    $a1, 4($t8)
/* 056530 7F021A00 10A00005 */  beqz  $a1, .L7F021A18
/* 056534 7F021A04 00000000 */   nop   
/* 056538 7F021A08 0FC1B1E7 */  jal   extract_id_from_object_structure_microcode
/* 05653C 7F021A0C 8FA40110 */   lw    $a0, 0x110($sp)
/* 056540 7F021A10 8FB90108 */  lw    $t9, 0x108($sp)
/* 056544 7F021A14 AC590000 */  sw    $t9, ($v0)
.L7F021A18:
/* 056548 7F021A18 0FC1ACA7 */  jal   sub_GAME_7F06B29C
/* 05654C 7F021A1C 8E040020 */   lw    $a0, 0x20($s0)
/* 056550 7F021A20 0FC1AECA */  jal   sub_GAME_7F06BB28
/* 056554 7F021A24 8E040020 */   lw    $a0, 0x20($s0)
/* 056558 7F021A28 10000020 */  b     .L7F021AAC
/* 05655C 7F021A2C AE020020 */   sw    $v0, 0x20($s0)
/* 056560 7F021A30 8E020160 */  lw    $v0, 0x160($s0)
.L7F021A34:
/* 056564 7F021A34 50400005 */  beql  $v0, $zero, .L7F021A4C
/* 056568 7F021A38 8E020164 */   lw    $v0, 0x164($s0)
/* 05656C 7F021A3C 904F0001 */  lbu   $t7, 1($v0)
/* 056570 7F021A40 31EEFFFD */  andi  $t6, $t7, 0xfffd
/* 056574 7F021A44 A04E0001 */  sb    $t6, 1($v0)
/* 056578 7F021A48 8E020164 */  lw    $v0, 0x164($s0)
.L7F021A4C:
/* 05657C 7F021A4C 2403FFFD */  li    $v1, -3
/* 056580 7F021A50 50400005 */  beql  $v0, $zero, .L7F021A68
/* 056584 7F021A54 8E0201D8 */   lw    $v0, 0x1d8($s0)
/* 056588 7F021A58 90490001 */  lbu   $t1, 1($v0)
/* 05658C 7F021A5C 01235024 */  and   $t2, $t1, $v1
/* 056590 7F021A60 A04A0001 */  sb    $t2, 1($v0)
/* 056594 7F021A64 8E0201D8 */  lw    $v0, 0x1d8($s0)
.L7F021A68:
/* 056598 7F021A68 50400005 */  beql  $v0, $zero, .L7F021A80
/* 05659C 7F021A6C 8FA80158 */   lw    $t0, 0x158($sp)
/* 0565A0 7F021A70 904B0001 */  lbu   $t3, 1($v0)
/* 0565A4 7F021A74 01636024 */  and   $t4, $t3, $v1
/* 0565A8 7F021A78 A04C0001 */  sb    $t4, 1($v0)
/* 0565AC 7F021A7C 8FA80158 */  lw    $t0, 0x158($sp)
.L7F021A80:
/* 0565B0 7F021A80 910D0001 */  lbu   $t5, 1($t0)
/* 0565B4 7F021A84 01A3C024 */  and   $t8, $t5, $v1
/* 0565B8 7F021A88 A1180001 */  sb    $t8, 1($t0)
/* 0565BC 7F021A8C 921900F8 */  lbu   $t9, 0xf8($s0)
/* 0565C0 7F021A90 920F00F9 */  lbu   $t7, 0xf9($s0)
/* 0565C4 7F021A94 920E00FA */  lbu   $t6, 0xfa($s0)
/* 0565C8 7F021A98 920900FB */  lbu   $t1, 0xfb($s0)
/* 0565CC 7F021A9C A21900F4 */  sb    $t9, 0xf4($s0)
/* 0565D0 7F021AA0 A20F00F5 */  sb    $t7, 0xf5($s0)
/* 0565D4 7F021AA4 A20E00F6 */  sb    $t6, 0xf6($s0)
/* 0565D8 7F021AA8 A20900F7 */  sb    $t1, 0xf7($s0)
.L7F021AAC:
/* 0565DC 7F021AAC 8E0A0014 */  lw    $t2, 0x14($s0)
/* 0565E0 7F021AB0 314B0400 */  andi  $t3, $t2, 0x400
/* 0565E4 7F021AB4 55600015 */  bnezl $t3, .L7F021B0C
/* 0565E8 7F021AB8 00001025 */   move  $v0, $zero
/* 0565EC 7F021ABC 96020012 */  lhu   $v0, 0x12($s0)
/* 0565F0 7F021AC0 8FAD0158 */  lw    $t5, 0x158($sp)
/* 0565F4 7F021AC4 304C0001 */  andi  $t4, $v0, 1
/* 0565F8 7F021AC8 1180000D */  beqz  $t4, .L7F021B00
/* 0565FC 7F021ACC 00000000 */   nop   
/* 056600 7F021AD0 8DA40020 */  lw    $a0, 0x20($t5)
/* 056604 7F021AD4 50800009 */  beql  $a0, $zero, .L7F021AFC
/* 056608 7F021AD8 3058FFFE */   andi  $t8, $v0, 0xfffe
/* 05660C 7F021ADC 8C830024 */  lw    $v1, 0x24($a0)
.L7F021AE0:
/* 056610 7F021AE0 0FC1304C */  jal   sub_GAME_7F04C130
/* 056614 7F021AE4 AFA3003C */   sw    $v1, 0x3c($sp)
/* 056618 7F021AE8 8FA4003C */  lw    $a0, 0x3c($sp)
/* 05661C 7F021AEC 5480FFFC */  bnezl $a0, .L7F021AE0
/* 056620 7F021AF0 8C830024 */   lw    $v1, 0x24($a0)
/* 056624 7F021AF4 96020012 */  lhu   $v0, 0x12($s0)
/* 056628 7F021AF8 3058FFFE */  andi  $t8, $v0, 0xfffe
.L7F021AFC:
/* 05662C 7F021AFC A6180012 */  sh    $t8, 0x12($s0)
.L7F021B00:
/* 056630 7F021B00 0FC0B89B */  jal   chrlvTriggerFireWeapon
/* 056634 7F021B04 02002025 */   move  $a0, $s0
/* 056638 7F021B08 00001025 */  move  $v0, $zero
.L7F021B0C:
/* 05663C 7F021B0C 8FBF0024 */  lw    $ra, 0x24($sp)
/* 056640 7F021B10 8FB00020 */  lw    $s0, 0x20($sp)
/* 056644 7F021B14 27BD0158 */  addiu $sp, $sp, 0x158
/* 056648 7F021B18 03E00008 */  jr    $ra
/* 05664C 7F021B1C 00000000 */   nop   
)
#endif

#ifdef VERSION_JP
GLOBAL_ASM(
.text
glabel sub_GAME_7F020EF0
/* 055CF8 7F021188 27BDFEA8 */  addiu $sp, $sp, -0x158
/* 055CFC 7F02118C 3C0F8003 */  lui   $t7, %hi(D_8002CC6C) # $t7, 0x8003
/* 055D00 7F021190 25EFCCAC */  addiu $t7, %lo(D_8002CC6C) # addiu $t7, $t7, -0x3354
/* 055D04 7F021194 AFBF0024 */  sw    $ra, 0x24($sp)
/* 055D08 7F021198 AFB00020 */  sw    $s0, 0x20($sp)
/* 055D0C 7F02119C AFA40158 */  sw    $a0, 0x158($sp)
/* 055D10 7F0211A0 25E8003C */  addiu $t0, $t7, 0x3c
/* 055D14 7F0211A4 27AE0118 */  addiu $t6, $sp, 0x118
.Ljp7F0211A8:
/* 055D18 7F0211A8 8DE10000 */  lw    $at, ($t7)
/* 055D1C 7F0211AC 25EF000C */  addiu $t7, $t7, 0xc
/* 055D20 7F0211B0 25CE000C */  addiu $t6, $t6, 0xc
/* 055D24 7F0211B4 ADC1FFF4 */  sw    $at, -0xc($t6)
/* 055D28 7F0211B8 8DE1FFF8 */  lw    $at, -8($t7)
/* 055D2C 7F0211BC ADC1FFF8 */  sw    $at, -8($t6)
/* 055D30 7F0211C0 8DE1FFFC */  lw    $at, -4($t7)
/* 055D34 7F0211C4 15E8FFF8 */  bne   $t7, $t0, .Ljp7F0211A8
/* 055D38 7F0211C8 ADC1FFFC */   sw    $at, -4($t6)
/* 055D3C 7F0211CC 8DE10000 */  lw    $at, ($t7)
/* 055D40 7F0211D0 3C0C8005 */  lui   $t4, %hi(g_ClockTimer) # $t4, 0x8005
/* 055D44 7F0211D4 240B0001 */  li    $t3, 1
/* 055D48 7F0211D8 ADC10000 */  sw    $at, ($t6)
/* 055D4C 7F0211DC 8FA90158 */  lw    $t1, 0x158($sp)
/* 055D50 7F0211E0 8D8C83A4 */  lw    $t4, %lo(g_ClockTimer)($t4)
/* 055D54 7F0211E4 3C188003 */  lui   $t8, %hi(D_8002C904) # $t8, 0x8003
/* 055D58 7F0211E8 8D300004 */  lw    $s0, 4($t1)
/* 055D5C 7F0211EC 8E0A001C */  lw    $t2, 0x1c($s0)
/* 055D60 7F0211F0 AFAB0108 */  sw    $t3, 0x108($sp)
/* 055D64 7F0211F4 AFAC0104 */  sw    $t4, 0x104($sp)
/* 055D68 7F0211F8 AFAA0110 */  sw    $t2, 0x110($sp)
/* 055D6C 7F0211FC 8E020014 */  lw    $v0, 0x14($s0)
/* 055D70 7F021200 304D0400 */  andi  $t5, $v0, 0x400
/* 055D74 7F021204 11A00003 */  beqz  $t5, .Ljp7F021214
/* 055D78 7F021208 0002CB40 */   sll   $t9, $v0, 0xd
/* 055D7C 7F02120C 07230035 */  bgezl $t9, .Ljp7F0212E4
/* 055D80 7F021210 96180012 */   lhu   $t8, 0x12($s0)
.Ljp7F021214:
/* 055D84 7F021214 8F18C944 */  lw    $t8, %lo(D_8002C904)($t8)
/* 055D88 7F021218 3C088003 */  lui   $t0, %hi(g_AnimationTablePointerCountRelated) # $t0, 0x8003
/* 055D8C 7F02121C 1300001E */  beqz  $t8, .Ljp7F021298
/* 055D90 7F021220 00000000 */   nop   
/* 055D94 7F021224 8D08C948 */  lw    $t0, %lo(g_AnimationTablePointerCountRelated)($t0)
/* 055D98 7F021228 3C0E8003 */  lui   $t6, %hi(animation_table_ptrs1)
/* 055D9C 7F02122C 24010001 */  li    $at, 1
/* 055DA0 7F021230 00087880 */  sll   $t7, $t0, 2
/* 055DA4 7F021234 01CF7021 */  addu  $t6, $t6, $t7
/* 055DA8 7F021238 8DCE9DAC */  lw    $t6, %lo(animation_table_ptrs1)($t6)
/* 055DAC 7F02123C 11C1001D */  beq   $t6, $at, .Ljp7F0212B4
/* 055DB0 7F021240 00000000 */   nop   
/* 055DB4 7F021244 0FC1BEE7 */  jal   objecthandlerGetModelAnim
/* 055DB8 7F021248 8FA40110 */   lw    $a0, 0x110($sp)
/* 055DBC 7F02124C 3C098003 */  lui   $t1, %hi(g_AnimationTablePointerCountRelated) # $t1, 0x8003
/* 055DC0 7F021250 8D29C948 */  lw    $t1, %lo(g_AnimationTablePointerCountRelated)($t1)
/* 055DC4 7F021254 3C058003 */  lui   $a1, %hi(animation_table_ptrs1)
/* 055DC8 7F021258 8FA40110 */  lw    $a0, 0x110($sp)
/* 055DCC 7F02125C 00095080 */  sll   $t2, $t1, 2
/* 055DD0 7F021260 00AA2821 */  addu  $a1, $a1, $t2
/* 055DD4 7F021264 8CA59DAC */  lw    $a1, %lo(animation_table_ptrs1)($a1)
/* 055DD8 7F021268 00003025 */  move  $a2, $zero
/* 055DDC 7F02126C 10450011 */  beq   $v0, $a1, .Ljp7F0212B4
/* 055DE0 7F021270 00000000 */   nop   
/* 055DE4 7F021274 44800000 */  mtc1  $zero, $f0
/* 055DE8 7F021278 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 055DEC 7F02127C 44812000 */  mtc1  $at, $f4
/* 055DF0 7F021280 44070000 */  mfc1  $a3, $f0
/* 055DF4 7F021284 E7A00014 */  swc1  $f0, 0x14($sp)
/* 055DF8 7F021288 0FC1C0A6 */  jal   modelSetAnimation
/* 055DFC 7F02128C E7A40010 */   swc1  $f4, 0x10($sp)
/* 055E00 7F021290 10000008 */  b     .Ljp7F0212B4
/* 055E04 7F021294 00000000 */   nop   
.Ljp7F021298:
/* 055E08 7F021298 0FC0CA6F */  jal   chrlvActionTick
/* 055E0C 7F02129C 02002025 */   move  $a0, $s0
/* 055E10 7F0212A0 8E0B001C */  lw    $t3, 0x1c($s0)
/* 055E14 7F0212A4 15600003 */  bnez  $t3, .Ljp7F0212B4
/* 055E18 7F0212A8 00000000 */   nop   
/* 055E1C 7F0212AC 100002D1 */  b     .Ljp7F021DF4
/* 055E20 7F0212B0 24020001 */   li    $v0, 1
.Ljp7F0212B4:
/* 055E24 7F0212B4 3C0C8003 */  lui   $t4, %hi(D_8002C90C) # $t4, 0x8003
/* 055E28 7F0212B8 8D8CC94C */  lw    $t4, %lo(D_8002C90C)($t4)
/* 055E2C 7F0212BC 3C0D8003 */  lui   $t5, %hi(D_8002C910) # $t5, 0x8003
/* 055E30 7F0212C0 51800008 */  beql  $t4, $zero, .Ljp7F0212E4
/* 055E34 7F0212C4 96180012 */   lhu   $t8, 0x12($s0)
/* 055E38 7F0212C8 8DADC950 */  lw    $t5, %lo(D_8002C910)($t5)
/* 055E3C 7F0212CC AFA00104 */  sw    $zero, 0x104($sp)
/* 055E40 7F0212D0 24190001 */  li    $t9, 1
/* 055E44 7F0212D4 51A00003 */  beql  $t5, $zero, .Ljp7F0212E4
/* 055E48 7F0212D8 96180012 */   lhu   $t8, 0x12($s0)
/* 055E4C 7F0212DC AFB90104 */  sw    $t9, 0x104($sp)
/* 055E50 7F0212E0 96180012 */  lhu   $t8, 0x12($s0)
.Ljp7F0212E4:
/* 055E54 7F0212E4 33080020 */  andi  $t0, $t8, 0x20
/* 055E58 7F0212E8 51000006 */  beql  $t0, $zero, .Ljp7F021304
/* 055E5C 7F0212EC 8E020160 */   lw    $v0, 0x160($s0)
/* 055E60 7F0212F0 0FC08171 */  jal   disable_sounds_attached_to_player_then_something
/* 055E64 7F0212F4 8FA40158 */   lw    $a0, 0x158($sp)
/* 055E68 7F0212F8 100002BE */  b     .Ljp7F021DF4
/* 055E6C 7F0212FC 24020001 */   li    $v0, 1
/* 055E70 7F021300 8E020160 */  lw    $v0, 0x160($s0)
.Ljp7F021304:
/* 055E74 7F021304 50400009 */  beql  $v0, $zero, .Ljp7F02132C
/* 055E78 7F021308 8E020164 */   lw    $v0, 0x164($s0)
/* 055E7C 7F02130C 8C440004 */  lw    $a0, 4($v0)
/* 055E80 7F021310 8C8F0064 */  lw    $t7, 0x64($a0)
/* 055E84 7F021314 31EE0004 */  andi  $t6, $t7, 4
/* 055E88 7F021318 51C00004 */  beql  $t6, $zero, .Ljp7F02132C
/* 055E8C 7F02131C 8E020164 */   lw    $v0, 0x164($s0)
/* 055E90 7F021320 0FC104C9 */  jal   objFreePermanently
/* 055E94 7F021324 24050001 */   li    $a1, 1
/* 055E98 7F021328 8E020164 */  lw    $v0, 0x164($s0)
.Ljp7F02132C:
/* 055E9C 7F02132C 50400009 */  beql  $v0, $zero, .Ljp7F021354
/* 055EA0 7F021330 8E020014 */   lw    $v0, 0x14($s0)
/* 055EA4 7F021334 8C440004 */  lw    $a0, 4($v0)
/* 055EA8 7F021338 8C890064 */  lw    $t1, 0x64($a0)
/* 055EAC 7F02133C 312A0004 */  andi  $t2, $t1, 4
/* 055EB0 7F021340 51400004 */  beql  $t2, $zero, .Ljp7F021354
/* 055EB4 7F021344 8E020014 */   lw    $v0, 0x14($s0)
/* 055EB8 7F021348 0FC104C9 */  jal   objFreePermanently
/* 055EBC 7F02134C 24050001 */   li    $a1, 1
/* 055EC0 7F021350 8E020014 */  lw    $v0, 0x14($s0)
.Ljp7F021354:
/* 055EC4 7F021354 8FAC0158 */  lw    $t4, 0x158($sp)
/* 055EC8 7F021358 304B0400 */  andi  $t3, $v0, 0x400
/* 055ECC 7F02135C 51600005 */  beql  $t3, $zero, .Ljp7F021374
/* 055ED0 7F021360 918D0000 */   lbu   $t5, ($t4)
/* 055ED4 7F021364 AFA0010C */  sw    $zero, 0x10c($sp)
/* 055ED8 7F021368 100000BD */  b     .Ljp7F021660
/* 055EDC 7F02136C 82030007 */   lb    $v1, 7($s0)
/* 055EE0 7F021370 918D0000 */  lbu   $t5, ($t4)
.Ljp7F021374:
/* 055EE4 7F021374 24010006 */  li    $at, 6
/* 055EE8 7F021378 55A1000D */  bnel  $t5, $at, .Ljp7F0213B0
/* 055EEC 7F02137C 00027A00 */   sll   $t7, $v0, 8
/* 055EF0 7F021380 0FC26F3F */  jal   sub_GAME_7F09B15C
/* 055EF4 7F021384 01802025 */   move  $a0, $t4
/* 055EF8 7F021388 0002C880 */  sll   $t9, $v0, 2
/* 055EFC 7F02138C 3C188008 */  lui   $t8, %hi(g_playerPointers)
/* 055F00 7F021390 0319C021 */  addu  $t8, $t8, $t9
/* 055F04 7F021394 8F189F50 */  lw    $t8, %lo(g_playerPointers)($t8)
/* 055F08 7F021398 24010001 */  li    $at, 1
/* 055F0C 7F02139C 8F080000 */  lw    $t0, ($t8)
/* 055F10 7F0213A0 51010005 */  beql  $t0, $at, .Ljp7F0213B8
/* 055F14 7F0213A4 240E0001 */   li    $t6, 1
/* 055F18 7F0213A8 8E020014 */  lw    $v0, 0x14($s0)
/* 055F1C 7F0213AC 00027A00 */  sll   $t7, $v0, 8
.Ljp7F0213B0:
/* 055F20 7F0213B0 05E10017 */  bgez  $t7, .Ljp7F021410
/* 055F24 7F0213B4 240E0001 */   li    $t6, 1
.Ljp7F0213B8:
/* 055F28 7F0213B8 AFAE010C */  sw    $t6, 0x10c($sp)
/* 055F2C 7F0213BC 82090007 */  lb    $t1, 7($s0)
/* 055F30 7F0213C0 24010003 */  li    $at, 3
/* 055F34 7F0213C4 02002025 */  move  $a0, $s0
/* 055F38 7F0213C8 1521000D */  bne   $t1, $at, .Ljp7F021400
/* 055F3C 7F0213CC 00000000 */   nop   
/* 055F40 7F0213D0 8E0A002C */  lw    $t2, 0x2c($s0)
/* 055F44 7F0213D4 1540000A */  bnez  $t2, .Ljp7F021400
/* 055F48 7F0213D8 00000000 */   nop   
/* 055F4C 7F0213DC 8E0B003C */  lw    $t3, 0x3c($s0)
/* 055F50 7F0213E0 8FA50104 */  lw    $a1, 0x104($sp)
/* 055F54 7F0213E4 00003025 */  move  $a2, $zero
/* 055F58 7F0213E8 11600005 */  beqz  $t3, .Ljp7F021400
/* 055F5C 7F0213EC 00000000 */   nop   
/* 055F60 7F0213F0 0FC1C437 */  jal   sub_GAME_7F070AEC
/* 055F64 7F0213F4 8FA40110 */   lw    $a0, 0x110($sp)
/* 055F68 7F0213F8 10000003 */  b     .Ljp7F021408
/* 055F6C 7F0213FC 00000000 */   nop   
.Ljp7F021400:
/* 055F70 7F021400 0FC08436 */  jal   chrPositionRelated7F020E40
/* 055F74 7F021404 8FA50104 */   lw    $a1, 0x104($sp)
.Ljp7F021408:
/* 055F78 7F021408 10000095 */  b     .Ljp7F021660
/* 055F7C 7F02140C 82030007 */   lb    $v1, 7($s0)
.Ljp7F021410:
/* 055F80 7F021410 82030007 */  lb    $v1, 7($s0)
/* 055F84 7F021414 2406000E */  li    $a2, 14
/* 055F88 7F021418 2401000F */  li    $at, 15
/* 055F8C 7F02141C 10C30003 */  beq   $a2, $v1, .Ljp7F02142C
/* 055F90 7F021420 00000000 */   nop   
/* 055F94 7F021424 54610041 */  bnel  $v1, $at, .Ljp7F02152C
/* 055F98 7F021428 24010003 */   li    $at, 3
.Ljp7F02142C:
/* 055F9C 7F02142C 54C30005 */  bnel  $a2, $v1, .Ljp7F021444
/* 055FA0 7F021430 2401000F */   li    $at, 15
/* 055FA4 7F021434 820D0038 */  lb    $t5, 0x38($s0)
/* 055FA8 7F021438 24010006 */  li    $at, 6
/* 055FAC 7F02143C 11A10007 */  beq   $t5, $at, .Ljp7F02145C
/* 055FB0 7F021440 2401000F */   li    $at, 15
.Ljp7F021444:
/* 055FB4 7F021444 1461001E */  bne   $v1, $at, .Ljp7F0214C0
/* 055FB8 7F021448 02002025 */   move  $a0, $s0
/* 055FBC 7F02144C 820C005C */  lb    $t4, 0x5c($s0)
/* 055FC0 7F021450 24010006 */  li    $at, 6
/* 055FC4 7F021454 1581001A */  bne   $t4, $at, .Ljp7F0214C0
/* 055FC8 7F021458 00000000 */   nop   
.Ljp7F02145C:
/* 055FCC 7F02145C 0FC1B57F */  jal   getinstsize
/* 055FD0 7F021460 8FA40110 */   lw    $a0, 0x110($sp)
/* 055FD4 7F021464 8FA40158 */  lw    $a0, 0x158($sp)
/* 055FD8 7F021468 44060000 */  mfc1  $a2, $f0
/* 055FDC 7F02146C 24070001 */  li    $a3, 1
/* 055FE0 7F021470 24850008 */  addiu $a1, $a0, 8
/* 055FE4 7F021474 0FC1549A */  jal   sub_GAME_7F054D6C
/* 055FE8 7F021478 AFA50030 */   sw    $a1, 0x30($sp)
/* 055FEC 7F02147C 10400028 */  beqz  $v0, .Ljp7F021520
/* 055FF0 7F021480 AFA2010C */   sw    $v0, 0x10c($sp)
/* 055FF4 7F021484 8FA40110 */  lw    $a0, 0x110($sp)
/* 055FF8 7F021488 0FC1B462 */  jal   getsuboffset
/* 055FFC 7F02148C 260500BC */   addiu $a1, $s0, 0xbc
/* 056000 7F021490 0FC1B728 */  jal   subcalcpos
/* 056004 7F021494 8FA40110 */   lw    $a0, 0x110($sp)
/* 056008 7F021498 8FA40158 */  lw    $a0, 0x158($sp)
/* 05600C 7F02149C 0FC100E7 */  jal   set_color_shading_from_tile
/* 056010 7F0214A0 260500F8 */   addiu $a1, $s0, 0xf8
/* 056014 7F0214A4 8FA40110 */  lw    $a0, 0x110($sp)
/* 056018 7F0214A8 0FC1B462 */  jal   getsuboffset
/* 05601C 7F0214AC 8FA50030 */   lw    $a1, 0x30($sp)
/* 056020 7F0214B0 0FC0840B */  jal   chrPositionRelated7F020D94
/* 056024 7F0214B4 02002025 */   move  $a0, $s0
/* 056028 7F0214B8 10000019 */  b     .Ljp7F021520
/* 05602C 7F0214BC 00000000 */   nop   
.Ljp7F0214C0:
/* 056030 7F0214C0 0FC08436 */  jal   chrPositionRelated7F020E40
/* 056034 7F0214C4 8FA50104 */   lw    $a1, 0x104($sp)
/* 056038 7F0214C8 0FC1B57F */  jal   getinstsize
/* 05603C 7F0214CC 8FA40110 */   lw    $a0, 0x110($sp)
/* 056040 7F0214D0 8FA40158 */  lw    $a0, 0x158($sp)
/* 056044 7F0214D4 44060000 */  mfc1  $a2, $f0
/* 056048 7F0214D8 24070001 */  li    $a3, 1
/* 05604C 7F0214DC 0FC1549A */  jal   sub_GAME_7F054D6C
/* 056050 7F0214E0 24850008 */   addiu $a1, $a0, 8
/* 056054 7F0214E4 1040000E */  beqz  $v0, .Ljp7F021520
/* 056058 7F0214E8 AFA2010C */   sw    $v0, 0x10c($sp)
/* 05605C 7F0214EC 82030007 */  lb    $v1, 7($s0)
/* 056060 7F0214F0 2401000E */  li    $at, 14
/* 056064 7F0214F4 3C088005 */  lui   $t0, %hi(g_GlobalTimer) # $t0, 0x8005
/* 056068 7F0214F8 54610005 */  bnel  $v1, $at, .Ljp7F021510
/* 05606C 7F0214FC 2401000F */   li    $at, 15
/* 056070 7F021500 8D0883AC */  lw    $t0, %lo(g_GlobalTimer)($t0)
/* 056074 7F021504 10000006 */  b     .Ljp7F021520
/* 056078 7F021508 AE080078 */   sw    $t0, 0x78($s0)
/* 05607C 7F02150C 2401000F */  li    $at, 15
.Ljp7F021510:
/* 056080 7F021510 14610003 */  bne   $v1, $at, .Ljp7F021520
/* 056084 7F021514 3C0F8005 */   lui   $t7, %hi(g_GlobalTimer) # $t7, 0x8005
/* 056088 7F021518 8DEF83AC */  lw    $t7, %lo(g_GlobalTimer)($t7)
/* 05608C 7F02151C AE0F009C */  sw    $t7, 0x9c($s0)
.Ljp7F021520:
/* 056090 7F021520 1000004F */  b     .Ljp7F021660
/* 056094 7F021524 82030007 */   lb    $v1, 7($s0)
/* 056098 7F021528 24010003 */  li    $at, 3
.Ljp7F02152C:
/* 05609C 7F02152C 5461001C */  bnel  $v1, $at, .Ljp7F0215A0
/* 0560A0 7F021530 24010001 */   li    $at, 1
/* 0560A4 7F021534 8E0E002C */  lw    $t6, 0x2c($s0)
/* 0560A8 7F021538 55C00019 */  bnezl $t6, .Ljp7F0215A0
/* 0560AC 7F02153C 24010001 */   li    $at, 1
/* 0560B0 7F021540 0FC1B57F */  jal   getinstsize
/* 0560B4 7F021544 8FA40110 */   lw    $a0, 0x110($sp)
/* 0560B8 7F021548 8FA40158 */  lw    $a0, 0x158($sp)
/* 0560BC 7F02154C 44060000 */  mfc1  $a2, $f0
/* 0560C0 7F021550 24070001 */  li    $a3, 1
/* 0560C4 7F021554 0FC1549A */  jal   sub_GAME_7F054D6C
/* 0560C8 7F021558 24850008 */   addiu $a1, $a0, 8
/* 0560CC 7F02155C 10400009 */  beqz  $v0, .Ljp7F021584
/* 0560D0 7F021560 AFA2010C */   sw    $v0, 0x10c($sp)
/* 0560D4 7F021564 8E0A003C */  lw    $t2, 0x3c($s0)
/* 0560D8 7F021568 02002025 */  move  $a0, $s0
/* 0560DC 7F02156C 55400006 */  bnezl $t2, .Ljp7F021588
/* 0560E0 7F021570 8FA40110 */   lw    $a0, 0x110($sp)
/* 0560E4 7F021574 0FC08436 */  jal   chrPositionRelated7F020E40
/* 0560E8 7F021578 8FA50104 */   lw    $a1, 0x104($sp)
/* 0560EC 7F02157C 10000005 */  b     .Ljp7F021594
/* 0560F0 7F021580 00000000 */   nop   
.Ljp7F021584:
/* 0560F4 7F021584 8FA40110 */  lw    $a0, 0x110($sp)
.Ljp7F021588:
/* 0560F8 7F021588 8FA50104 */  lw    $a1, 0x104($sp)
/* 0560FC 7F02158C 0FC1C437 */  jal   sub_GAME_7F070AEC
/* 056100 7F021590 00003025 */   move  $a2, $zero
.Ljp7F021594:
/* 056104 7F021594 10000032 */  b     .Ljp7F021660
/* 056108 7F021598 82030007 */   lb    $v1, 7($s0)
/* 05610C 7F02159C 24010001 */  li    $at, 1
.Ljp7F0215A0:
/* 056110 7F0215A0 1461001C */  bne   $v1, $at, .Ljp7F021614
/* 056114 7F0215A4 30484000 */   andi  $t0, $v0, 0x4000
/* 056118 7F0215A8 0FC1B57F */  jal   getinstsize
/* 05611C 7F0215AC 8FA40110 */   lw    $a0, 0x110($sp)
/* 056120 7F0215B0 8FA40158 */  lw    $a0, 0x158($sp)
/* 056124 7F0215B4 44060000 */  mfc1  $a2, $f0
/* 056128 7F0215B8 24070001 */  li    $a3, 1
/* 05612C 7F0215BC 0FC1549A */  jal   sub_GAME_7F054D6C
/* 056130 7F0215C0 24850008 */   addiu $a1, $a0, 8
/* 056134 7F0215C4 14400005 */  bnez  $v0, .Ljp7F0215DC
/* 056138 7F0215C8 AFA2010C */   sw    $v0, 0x10c($sp)
/* 05613C 7F0215CC 8E0D0014 */  lw    $t5, 0x14($s0)
/* 056140 7F0215D0 8FB90110 */  lw    $t9, 0x110($sp)
/* 056144 7F0215D4 31AC0001 */  andi  $t4, $t5, 1
/* 056148 7F0215D8 11800005 */  beqz  $t4, .Ljp7F0215F0
.Ljp7F0215DC:
/* 05614C 7F0215DC 02002025 */   move  $a0, $s0
/* 056150 7F0215E0 0FC08436 */  jal   chrPositionRelated7F020E40
/* 056154 7F0215E4 8FA50104 */   lw    $a1, 0x104($sp)
/* 056158 7F0215E8 10000008 */  b     .Ljp7F02160C
/* 05615C 7F0215EC 00000000 */   nop   
.Ljp7F0215F0:
/* 056160 7F0215F0 8F380054 */  lw    $t8, 0x54($t9)
/* 056164 7F0215F4 03202025 */  move  $a0, $t9
/* 056168 7F0215F8 8FA50104 */  lw    $a1, 0x104($sp)
/* 05616C 7F0215FC 13000003 */  beqz  $t8, .Ljp7F02160C
/* 056170 7F021600 00000000 */   nop   
/* 056174 7F021604 0FC1C437 */  jal   sub_GAME_7F070AEC
/* 056178 7F021608 00003025 */   move  $a2, $zero
.Ljp7F02160C:
/* 05617C 7F02160C 10000014 */  b     .Ljp7F021660
/* 056180 7F021610 82030007 */   lb    $v1, 7($s0)
.Ljp7F021614:
/* 056184 7F021614 11000007 */  beqz  $t0, .Ljp7F021634
/* 056188 7F021618 02002025 */   move  $a0, $s0
/* 05618C 7F02161C 8FA40110 */  lw    $a0, 0x110($sp)
/* 056190 7F021620 8FA50104 */  lw    $a1, 0x104($sp)
/* 056194 7F021624 0FC1C437 */  jal   sub_GAME_7F070AEC
/* 056198 7F021628 00003025 */   move  $a2, $zero
/* 05619C 7F02162C 10000003 */  b     .Ljp7F02163C
/* 0561A0 7F021630 00000000 */   nop   
.Ljp7F021634:
/* 0561A4 7F021634 0FC08436 */  jal   chrPositionRelated7F020E40
/* 0561A8 7F021638 8FA50104 */   lw    $a1, 0x104($sp)
.Ljp7F02163C:
/* 0561AC 7F02163C 0FC1B57F */  jal   getinstsize
/* 0561B0 7F021640 8FA40110 */   lw    $a0, 0x110($sp)
/* 0561B4 7F021644 8FA40158 */  lw    $a0, 0x158($sp)
/* 0561B8 7F021648 44060000 */  mfc1  $a2, $f0
/* 0561BC 7F02164C 24070001 */  li    $a3, 1
/* 0561C0 7F021650 0FC1549A */  jal   sub_GAME_7F054D6C
/* 0561C4 7F021654 24850008 */   addiu $a1, $a0, 8
/* 0561C8 7F021658 AFA2010C */  sw    $v0, 0x10c($sp)
/* 0561CC 7F02165C 82030007 */  lb    $v1, 7($s0)
.Ljp7F021660:
/* 0561D0 7F021660 24010001 */  li    $at, 1
/* 0561D4 7F021664 14610009 */  bne   $v1, $at, .Ljp7F02168C
/* 0561D8 7F021668 8FAE0110 */   lw    $t6, 0x110($sp)
/* 0561DC 7F02166C 8DC90054 */  lw    $t1, 0x54($t6)
/* 0561E0 7F021670 8FAA0158 */  lw    $t2, 0x158($sp)
/* 0561E4 7F021674 55200006 */  bnezl $t1, .Ljp7F021690
/* 0561E8 7F021678 960D0012 */   lhu   $t5, 0x12($s0)
/* 0561EC 7F02167C 914B0000 */  lbu   $t3, ($t2)
/* 0561F0 7F021680 24010006 */  li    $at, 6
/* 0561F4 7F021684 15610004 */  bne   $t3, $at, .Ljp7F021698
/* 0561F8 7F021688 00000000 */   nop   
.Ljp7F02168C:
/* 0561FC 7F02168C 960D0012 */  lhu   $t5, 0x12($s0)
.Ljp7F021690:
/* 056200 7F021690 35AC0200 */  ori   $t4, $t5, 0x200
/* 056204 7F021694 A60C0012 */  sh    $t4, 0x12($s0)
.Ljp7F021698:
/* 056208 7F021698 0FC081E8 */  jal   chrAimGlobalTimerTickRelated
/* 05620C 7F02169C 02002025 */   move  $a0, $s0
/* 056210 7F0216A0 8E040020 */  lw    $a0, 0x20($s0)
/* 056214 7F0216A4 50800005 */  beql  $a0, $zero, .Ljp7F0216BC
/* 056218 7F0216A8 8FB8010C */   lw    $t8, 0x10c($sp)
/* 05621C 7F0216AC 0FC1AE0E */  jal   sub_GAME_7F06B248
/* 056220 7F0216B0 00000000 */   nop   
/* 056224 7F0216B4 AE000020 */  sw    $zero, 0x20($s0)
/* 056228 7F0216B8 8FB8010C */  lw    $t8, 0x10c($sp)
.Ljp7F0216BC:
/* 05622C 7F0216BC 261900F8 */  addiu $t9, $s0, 0xf8
/* 056230 7F0216C0 53000196 */  beql  $t8, $zero, .Ljp7F021D1C
/* 056234 7F0216C4 8E020160 */   lw    $v0, 0x160($s0)
/* 056238 7F0216C8 0FC246CA */  jal   get_debug_chrnum_flag
/* 05623C 7F0216CC AFB9002C */   sw    $t9, 0x2c($sp)
/* 056240 7F0216D0 8FA20158 */  lw    $v0, 0x158($sp)
/* 056244 7F0216D4 2404000C */  li    $a0, 12
/* 056248 7F0216D8 90480001 */  lbu   $t0, 1($v0)
/* 05624C 7F0216DC 350F0002 */  ori   $t7, $t0, 2
/* 056250 7F0216E0 A04F0001 */  sb    $t7, 1($v0)
/* 056254 7F0216E4 8E0E0014 */  lw    $t6, 0x14($s0)
/* 056258 7F0216E8 35C90008 */  ori   $t1, $t6, 8
/* 05625C 7F0216EC 0FC24CCF */  jal   cheatIsActive
/* 056260 7F0216F0 AE090014 */   sw    $t1, 0x14($s0)
/* 056264 7F0216F4 10400018 */  beqz  $v0, .Ljp7F021758
/* 056268 7F0216F8 00000000 */   nop   
/* 05626C 7F0216FC 8204000F */  lb    $a0, 0xf($s0)
/* 056270 7F021700 0FC0827B */  jal   not_in_us_7F0209EC
/* 056274 7F021704 82050006 */   lb    $a1, 6($s0)
/* 056278 7F021708 10400013 */  beqz  $v0, .Ljp7F021758
/* 05627C 7F02170C 3C013EA0 */   li    $at, 0x3EA00000 # 0.312500
/* 056280 7F021710 44816000 */  mtc1  $at, $f12
/* 056284 7F021714 0FC1B27F */  jal   set_float_80036088
/* 056288 7F021718 00000000 */   nop   
/* 05628C 7F02171C 8E020014 */  lw    $v0, 0x14($s0)
/* 056290 7F021720 3C01EFFF */  lui   $at, (0xEFFFFFFF >> 16) # lui $at, 0xefff
/* 056294 7F021724 3421FFFF */  ori   $at, (0xEFFFFFFF & 0xFFFF) # ori $at, $at, 0xffff
/* 056298 7F021728 000250C0 */  sll   $t2, $v0, 3
/* 05629C 7F02172C 0541000A */  bgez  $t2, .Ljp7F021758
/* 0562A0 7F021730 00415824 */   and   $t3, $v0, $at
/* 0562A4 7F021734 8E04001C */  lw    $a0, 0x1c($s0)
/* 0562A8 7F021738 AE0B0014 */  sw    $t3, 0x14($s0)
/* 0562AC 7F02173C 3C018005 */  lui   $at, %hi(D_jp80051D88) # $at, 0x8005
/* 0562B0 7F021740 C4281D88 */  lwc1  $f8, %lo(D_jp80051D88)($at)
/* 0562B4 7F021744 C4860014 */  lwc1  $f6, 0x14($a0)
/* 0562B8 7F021748 46083283 */  div.s $f10, $f6, $f8
/* 0562BC 7F02174C 44055000 */  mfc1  $a1, $f10
/* 0562C0 7F021750 0FC1B51A */  jal   modelSetScale
/* 0562C4 7F021754 00000000 */   nop   
.Ljp7F021758:
/* 0562C8 7F021758 3C0D7F02 */  lui   $t5, %hi(sub_GAME_7F02083C) # $t5, 0x7f02
/* 0562CC 7F02175C 25AD0AAC */  addiu $t5, %lo(sub_GAME_7F02083C) # addiu $t5, $t5, 0xaac
/* 0562D0 7F021760 3C018003 */  lui   $at, %hi(D_80036090) # $at, 0x8003
/* 0562D4 7F021764 AC2D60D0 */  sw    $t5, %lo(D_80036090)($at)
/* 0562D8 7F021768 3C018007 */  lui   $at, %hi(dword_CODE_bss_80069B60) # $at, 0x8007
/* 0562DC 7F02176C 0FC1E26D */  jal   currentPlayerGetMatrix10CC
/* 0562E0 7F021770 AC309BA0 */   sw    $s0, %lo(dword_CODE_bss_80069B60)($at)
/* 0562E4 7F021774 8FAC0110 */  lw    $t4, 0x110($sp)
/* 0562E8 7F021778 AFA20118 */  sw    $v0, 0x118($sp)
/* 0562EC 7F02177C 8D980008 */  lw    $t8, 8($t4)
/* 0562F0 7F021780 8704000E */  lh    $a0, 0xe($t8)
/* 0562F4 7F021784 0004C980 */  sll   $t9, $a0, 6
/* 0562F8 7F021788 0FC2F8B1 */  jal   dynAllocate
/* 0562FC 7F02178C 03202025 */   move  $a0, $t9
/* 056300 7F021790 3C058007 */  lui   $a1, %hi(dword_CODE_bss_80069B60) # $a1, 0x8007
/* 056304 7F021794 24A59BA0 */  addiu $a1, %lo(dword_CODE_bss_80069B60) # addiu $a1, $a1, -0x6460
/* 056308 7F021798 8CA30000 */  lw    $v1, ($a1)
/* 05630C 7F02179C AFA20128 */  sw    $v0, 0x128($sp)
/* 056310 7F0217A0 80640011 */  lb    $a0, 0x11($v1)
/* 056314 7F0217A4 0480000B */  bltz  $a0, .Ljp7F0217D4
/* 056318 7F0217A8 3C088005 */   lui   $t0, %hi(g_ClockTimer) # $t0, 0x8005
/* 05631C 7F0217AC 8D0883A4 */  lw    $t0, %lo(g_ClockTimer)($t0)
/* 056320 7F0217B0 2409FFFF */  li    $t1, -1
/* 056324 7F0217B4 00887821 */  addu  $t7, $a0, $t0
/* 056328 7F0217B8 A06F0011 */  sb    $t7, 0x11($v1)
/* 05632C 7F0217BC 8CA30000 */  lw    $v1, ($a1)
/* 056330 7F0217C0 806E0011 */  lb    $t6, 0x11($v1)
/* 056334 7F0217C4 29C1001E */  slti  $at, $t6, 0x1e
/* 056338 7F0217C8 54200003 */  bnezl $at, .Ljp7F0217D8
/* 05633C 7F0217CC 27A40118 */   addiu $a0, $sp, 0x118
/* 056340 7F0217D0 A0690011 */  sb    $t1, 0x11($v1)
.Ljp7F0217D4:
/* 056344 7F0217D4 27A40118 */  addiu $a0, $sp, 0x118
.Ljp7F0217D8:
/* 056348 7F0217D8 0FC1BE3A */  jal   subcalcmatrices
/* 05634C 7F0217DC 8FA50110 */   lw    $a1, 0x110($sp)
/* 056350 7F0217E0 3C018003 */  lui   $at, %hi(D_80036090) # $at, 0x8003
/* 056354 7F0217E4 AC2060D0 */  sw    $zero, %lo(D_80036090)($at)
/* 056358 7F0217E8 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 05635C 7F0217EC 44816000 */  mtc1  $at, $f12
/* 056360 7F0217F0 0FC1B27F */  jal   set_float_80036088
/* 056364 7F0217F4 00000000 */   nop   
/* 056368 7F0217F8 260400F4 */  addiu $a0, $s0, 0xf4
/* 05636C 7F0217FC 0FC10184 */  jal   update_color_shading
/* 056370 7F021800 8FA5002C */   lw    $a1, 0x2c($sp)
/* 056374 7F021804 0FC1B356 */  jal   sub_GAME_7F06C768
/* 056378 7F021808 8FA40110 */   lw    $a0, 0x110($sp)
/* 05637C 7F02180C 8FAA0158 */  lw    $t2, 0x158($sp)
/* 056380 7F021810 00002025 */  move  $a0, $zero
/* 056384 7F021814 E5400018 */  swc1  $f0, 0x18($t2)
/* 056388 7F021818 0FC1ADC4 */  jal   sub_GAME_7F06B120
/* 05638C 7F02181C 8FA50110 */   lw    $a1, 0x110($sp)
/* 056390 7F021820 AE020020 */  sw    $v0, 0x20($s0)
/* 056394 7F021824 26060020 */  addiu $a2, $s0, 0x20
/* 056398 7F021828 AFA60030 */  sw    $a2, 0x30($sp)
/* 05639C 7F02182C 8FA40158 */  lw    $a0, 0x158($sp)
/* 0563A0 7F021830 0FC14A3D */  jal   sub_GAME_7F0523F8
/* 0563A4 7F021834 00002825 */   move  $a1, $zero
/* 0563A8 7F021838 8FA60030 */  lw    $a2, 0x30($sp)
/* 0563AC 7F02183C 8FA40158 */  lw    $a0, 0x158($sp)
/* 0563B0 7F021840 0FC14A3D */  jal   sub_GAME_7F0523F8
/* 0563B4 7F021844 24050001 */   li    $a1, 1
/* 0563B8 7F021848 8E0201D8 */  lw    $v0, 0x1d8($s0)
/* 0563BC 7F02184C 5040011A */  beql  $v0, $zero, .Ljp7F021CB8
/* 0563C0 7F021850 8FB80110 */   lw    $t8, 0x110($sp)
/* 0563C4 7F021854 8C470004 */  lw    $a3, 4($v0)
/* 0563C8 7F021858 904B0001 */  lbu   $t3, 1($v0)
/* 0563CC 7F02185C 00003025 */  move  $a2, $zero
/* 0563D0 7F021860 8CE30014 */  lw    $v1, 0x14($a3)
/* 0563D4 7F021864 356D0002 */  ori   $t5, $t3, 2
/* 0563D8 7F021868 A04D0001 */  sb    $t5, 1($v0)
/* 0563DC 7F02186C 8C65001C */  lw    $a1, 0x1c($v1)
/* 0563E0 7F021870 8FA40110 */  lw    $a0, 0x110($sp)
/* 0563E4 7F021874 AFA70100 */  sw    $a3, 0x100($sp)
/* 0563E8 7F021878 0FC1B314 */  jal   sub_GAME_7F06C660
/* 0563EC 7F02187C AFA300FC */   sw    $v1, 0xfc($sp)
/* 0563F0 7F021880 8FAC00FC */  lw    $t4, 0xfc($sp)
/* 0563F4 7F021884 AFA20118 */  sw    $v0, 0x118($sp)
/* 0563F8 7F021888 8D980008 */  lw    $t8, 8($t4)
/* 0563FC 7F02188C 8704000E */  lh    $a0, 0xe($t8)
/* 056400 7F021890 0004C980 */  sll   $t9, $a0, 6
/* 056404 7F021894 0FC2F8B1 */  jal   dynAllocate
/* 056408 7F021898 03202025 */   move  $a0, $t9
/* 05640C 7F02189C AFA20128 */  sw    $v0, 0x128($sp)
/* 056410 7F0218A0 27A40118 */  addiu $a0, $sp, 0x118
/* 056414 7F0218A4 0FC1BE0E */  jal   instcalcmatrices
/* 056418 7F0218A8 8FA500FC */   lw    $a1, 0xfc($sp)
/* 05641C 7F0218AC 82020006 */  lb    $v0, 6($s0)
/* 056420 7F0218B0 2841002A */  slti  $at, $v0, 0x2a
/* 056424 7F0218B4 142000F2 */  bnez  $at, .Ljp7F021C80
/* 056428 7F0218B8 28410046 */   slti  $at, $v0, 0x46
/* 05642C 7F0218BC 102000F0 */  beqz  $at, .Ljp7F021C80
/* 056430 7F0218C0 3C0F8003 */   lui   $t7, %hi(D_8002CCAC) # $t7, 0x8003
/* 056434 7F0218C4 25EFCCEC */  addiu $t7, %lo(D_8002CCAC) # addiu $t7, $t7, -0x3314
/* 056438 7F0218C8 8DE10000 */  lw    $at, ($t7)
/* 05643C 7F0218CC 27A800F0 */  addiu $t0, $sp, 0xf0
/* 056440 7F0218D0 8DE90004 */  lw    $t1, 4($t7)
/* 056444 7F0218D4 AD010000 */  sw    $at, ($t0)
/* 056448 7F0218D8 8DE10008 */  lw    $at, 8($t7)
/* 05644C 7F0218DC AD090004 */  sw    $t1, 4($t0)
/* 056450 7F0218E0 AD010008 */  sw    $at, 8($t0)
/* 056454 7F0218E4 0FC14AE0 */  jal   get_hat_model
/* 056458 7F0218E8 8E0401D8 */   lw    $a0, 0x1d8($s0)
/* 05645C 7F0218EC AFA20060 */  sw    $v0, 0x60($sp)
/* 056460 7F0218F0 82040006 */  lb    $a0, 6($s0)
/* 056464 7F0218F4 00025880 */  sll   $t3, $v0, 2
/* 056468 7F0218F8 01625823 */  subu  $t3, $t3, $v0
/* 05646C 7F0218FC 2484FFD6 */  addiu $a0, $a0, -0x2a
/* 056470 7F021900 000450C0 */  sll   $t2, $a0, 3
/* 056474 7F021904 01445021 */  addu  $t2, $t2, $a0
/* 056478 7F021908 000A5100 */  sll   $t2, $t2, 4
/* 05647C 7F02190C 000B58C0 */  sll   $t3, $t3, 3
/* 056480 7F021910 3C0C8004 */  lui   $t4, %hi(headHat_array_8003E464) # $t4, 0x8004
/* 056484 7F021914 258CE494 */  addiu $t4, %lo(headHat_array_8003E464) # addiu $t4, $t4, -0x1b6c
/* 056488 7F021918 014B6821 */  addu  $t5, $t2, $t3
/* 05648C 7F02191C 01AC1821 */  addu  $v1, $t5, $t4
/* 056490 7F021920 0FC24677 */  jal   get_debug_render_raster
/* 056494 7F021924 AFA30058 */   sw    $v1, 0x58($sp)
/* 056498 7F021928 144000AA */  bnez  $v0, .Ljp7F021BD4
/* 05649C 7F02192C 8FA30058 */   lw    $v1, 0x58($sp)
/* 0564A0 7F021930 AFA00054 */  sw    $zero, 0x54($sp)
/* 0564A4 7F021934 00002025 */  move  $a0, $zero
/* 0564A8 7F021938 24050020 */  li    $a1, 32
/* 0564AC 7F02193C 0C0030DC */  jal   joyGetButtons
/* 0564B0 7F021940 AFA30058 */   sw    $v1, 0x58($sp)
/* 0564B4 7F021944 1040004F */  beqz  $v0, .Ljp7F021A84
/* 0564B8 7F021948 8FA30058 */   lw    $v1, 0x58($sp)
/* 0564BC 7F02194C 00002025 */  move  $a0, $zero
/* 0564C0 7F021950 34058000 */  li    $a1, 32768
/* 0564C4 7F021954 0C0030DC */  jal   joyGetButtons
/* 0564C8 7F021958 AFA30058 */   sw    $v1, 0x58($sp)
/* 0564CC 7F02195C 10400008 */  beqz  $v0, .Ljp7F021980
/* 0564D0 7F021960 8FA30058 */   lw    $v1, 0x58($sp)
/* 0564D4 7F021964 3C018005 */  lui   $at, %hi(D_80051D58) # $at, 0x8005
/* 0564D8 7F021968 C4321D8C */  lwc1  $f18, %lo(D_80051D58)($at)
/* 0564DC 7F02196C C4700008 */  lwc1  $f16, 8($v1)
/* 0564E0 7F021970 24180001 */  li    $t8, 1
/* 0564E4 7F021974 46128101 */  sub.s $f4, $f16, $f18
/* 0564E8 7F021978 E4640008 */  swc1  $f4, 8($v1)
/* 0564EC 7F02197C AFB80054 */  sw    $t8, 0x54($sp)
.Ljp7F021980:
/* 0564F0 7F021980 00002025 */  move  $a0, $zero
/* 0564F4 7F021984 24054000 */  li    $a1, 16384
/* 0564F8 7F021988 0C0030DC */  jal   joyGetButtons
/* 0564FC 7F02198C AFA30058 */   sw    $v1, 0x58($sp)
/* 056500 7F021990 10400008 */  beqz  $v0, .Ljp7F0219B4
/* 056504 7F021994 8FA30058 */   lw    $v1, 0x58($sp)
/* 056508 7F021998 3C018005 */  lui   $at, %hi(D_80051D5C) # $at, 0x8005
/* 05650C 7F02199C C4281D90 */  lwc1  $f8, %lo(D_80051D5C)($at)
/* 056510 7F0219A0 C4660008 */  lwc1  $f6, 8($v1)
/* 056514 7F0219A4 24190001 */  li    $t9, 1
/* 056518 7F0219A8 46083280 */  add.s $f10, $f6, $f8
/* 05651C 7F0219AC E46A0008 */  swc1  $f10, 8($v1)
/* 056520 7F0219B0 AFB90054 */  sw    $t9, 0x54($sp)
.Ljp7F0219B4:
/* 056524 7F0219B4 00002025 */  move  $a0, $zero
/* 056528 7F0219B8 24050004 */  li    $a1, 4
/* 05652C 7F0219BC 0C0030DC */  jal   joyGetButtons
/* 056530 7F0219C0 AFA30058 */   sw    $v1, 0x58($sp)
/* 056534 7F0219C4 10400008 */  beqz  $v0, .Ljp7F0219E8
/* 056538 7F0219C8 8FA30058 */   lw    $v1, 0x58($sp)
/* 05653C 7F0219CC 3C018005 */  lui   $at, %hi(D_80051D60) # $at, 0x8005
/* 056540 7F0219D0 C4321D94 */  lwc1  $f18, %lo(D_80051D60)($at)
/* 056544 7F0219D4 C4700004 */  lwc1  $f16, 4($v1)
/* 056548 7F0219D8 240E0001 */  li    $t6, 1
/* 05654C 7F0219DC 46128101 */  sub.s $f4, $f16, $f18
/* 056550 7F0219E0 E4640004 */  swc1  $f4, 4($v1)
/* 056554 7F0219E4 AFAE0054 */  sw    $t6, 0x54($sp)
.Ljp7F0219E8:
/* 056558 7F0219E8 00002025 */  move  $a0, $zero
/* 05655C 7F0219EC 24050008 */  li    $a1, 8
/* 056560 7F0219F0 0C0030DC */  jal   joyGetButtons
/* 056564 7F0219F4 AFA30058 */   sw    $v1, 0x58($sp)
/* 056568 7F0219F8 10400008 */  beqz  $v0, .Ljp7F021A1C
/* 05656C 7F0219FC 8FA30058 */   lw    $v1, 0x58($sp)
/* 056570 7F021A00 3C018005 */  lui   $at, %hi(D_80051D64) # $at, 0x8005
/* 056574 7F021A04 C4281D98 */  lwc1  $f8, %lo(D_80051D64)($at)
/* 056578 7F021A08 C4660004 */  lwc1  $f6, 4($v1)
/* 05657C 7F021A0C 24080001 */  li    $t0, 1
/* 056580 7F021A10 46083280 */  add.s $f10, $f6, $f8
/* 056584 7F021A14 E46A0004 */  swc1  $f10, 4($v1)
/* 056588 7F021A18 AFA80054 */  sw    $t0, 0x54($sp)
.Ljp7F021A1C:
/* 05658C 7F021A1C 00002025 */  move  $a0, $zero
/* 056590 7F021A20 24050002 */  li    $a1, 2
/* 056594 7F021A24 0C0030DC */  jal   joyGetButtons
/* 056598 7F021A28 AFA30058 */   sw    $v1, 0x58($sp)
/* 05659C 7F021A2C 10400008 */  beqz  $v0, .Ljp7F021A50
/* 0565A0 7F021A30 8FA30058 */   lw    $v1, 0x58($sp)
/* 0565A4 7F021A34 3C018005 */  lui   $at, %hi(D_80051D68) # $at, 0x8005
/* 0565A8 7F021A38 C4321D9C */  lwc1  $f18, %lo(D_80051D68)($at)
/* 0565AC 7F021A3C C4700000 */  lwc1  $f16, ($v1)
/* 0565B0 7F021A40 240F0001 */  li    $t7, 1
/* 0565B4 7F021A44 46128101 */  sub.s $f4, $f16, $f18
/* 0565B8 7F021A48 E4640000 */  swc1  $f4, ($v1)
/* 0565BC 7F021A4C AFAF0054 */  sw    $t7, 0x54($sp)
.Ljp7F021A50:
/* 0565C0 7F021A50 00002025 */  move  $a0, $zero
/* 0565C4 7F021A54 24050001 */  li    $a1, 1
/* 0565C8 7F021A58 0C0030DC */  jal   joyGetButtons
/* 0565CC 7F021A5C AFA30058 */   sw    $v1, 0x58($sp)
/* 0565D0 7F021A60 10400008 */  beqz  $v0, .Ljp7F021A84
/* 0565D4 7F021A64 8FA30058 */   lw    $v1, 0x58($sp)
/* 0565D8 7F021A68 3C018005 */  lui   $at, %hi(D_80051D6C) # $at, 0x8005
/* 0565DC 7F021A6C C4281DA0 */  lwc1  $f8, %lo(D_80051D6C)($at)
/* 0565E0 7F021A70 C4660000 */  lwc1  $f6, ($v1)
/* 0565E4 7F021A74 24090001 */  li    $t1, 1
/* 0565E8 7F021A78 46083280 */  add.s $f10, $f6, $f8
/* 0565EC 7F021A7C E46A0000 */  swc1  $f10, ($v1)
/* 0565F0 7F021A80 AFA90054 */  sw    $t1, 0x54($sp)
.Ljp7F021A84:
/* 0565F4 7F021A84 00002025 */  move  $a0, $zero
/* 0565F8 7F021A88 24050010 */  li    $a1, 16
/* 0565FC 7F021A8C 0C0030DC */  jal   joyGetButtons
/* 056600 7F021A90 AFA30058 */   sw    $v1, 0x58($sp)
/* 056604 7F021A94 1040004F */  beqz  $v0, .Ljp7F021BD4
/* 056608 7F021A98 8FA30058 */   lw    $v1, 0x58($sp)
/* 05660C 7F021A9C 00002025 */  move  $a0, $zero
/* 056610 7F021AA0 34058000 */  li    $a1, 32768
/* 056614 7F021AA4 0C0030DC */  jal   joyGetButtons
/* 056618 7F021AA8 AFA30058 */   sw    $v1, 0x58($sp)
/* 05661C 7F021AAC 10400008 */  beqz  $v0, .Ljp7F021AD0
/* 056620 7F021AB0 8FA30058 */   lw    $v1, 0x58($sp)
/* 056624 7F021AB4 3C018005 */  lui   $at, %hi(D_80051D70) # $at, 0x8005
/* 056628 7F021AB8 C4321DA4 */  lwc1  $f18, %lo(D_80051D70)($at)
/* 05662C 7F021ABC C4700014 */  lwc1  $f16, 0x14($v1)
/* 056630 7F021AC0 240A0001 */  li    $t2, 1
/* 056634 7F021AC4 46128102 */  mul.s $f4, $f16, $f18
/* 056638 7F021AC8 E4640014 */  swc1  $f4, 0x14($v1)
/* 05663C 7F021ACC AFAA0054 */  sw    $t2, 0x54($sp)
.Ljp7F021AD0:
/* 056640 7F021AD0 00002025 */  move  $a0, $zero
/* 056644 7F021AD4 24054000 */  li    $a1, 16384
/* 056648 7F021AD8 0C0030DC */  jal   joyGetButtons
/* 05664C 7F021ADC AFA30058 */   sw    $v1, 0x58($sp)
/* 056650 7F021AE0 10400008 */  beqz  $v0, .Ljp7F021B04
/* 056654 7F021AE4 8FA30058 */   lw    $v1, 0x58($sp)
/* 056658 7F021AE8 3C018005 */  lui   $at, %hi(D_80051D74) # $at, 0x8005
/* 05665C 7F021AEC C4281DA8 */  lwc1  $f8, %lo(D_80051D74)($at)
/* 056660 7F021AF0 C4660014 */  lwc1  $f6, 0x14($v1)
/* 056664 7F021AF4 240B0001 */  li    $t3, 1
/* 056668 7F021AF8 46083282 */  mul.s $f10, $f6, $f8
/* 05666C 7F021AFC E46A0014 */  swc1  $f10, 0x14($v1)
/* 056670 7F021B00 AFAB0054 */  sw    $t3, 0x54($sp)
.Ljp7F021B04:
/* 056674 7F021B04 00002025 */  move  $a0, $zero
/* 056678 7F021B08 24050004 */  li    $a1, 4
/* 05667C 7F021B0C 0C0030DC */  jal   joyGetButtons
/* 056680 7F021B10 AFA30058 */   sw    $v1, 0x58($sp)
/* 056684 7F021B14 10400008 */  beqz  $v0, .Ljp7F021B38
/* 056688 7F021B18 8FA30058 */   lw    $v1, 0x58($sp)
/* 05668C 7F021B1C 3C018005 */  lui   $at, %hi(D_80051D78) # $at, 0x8005
/* 056690 7F021B20 C4321DAC */  lwc1  $f18, %lo(D_80051D78)($at)
/* 056694 7F021B24 C4700010 */  lwc1  $f16, 0x10($v1)
/* 056698 7F021B28 240D0001 */  li    $t5, 1
/* 05669C 7F021B2C 46128102 */  mul.s $f4, $f16, $f18
/* 0566A0 7F021B30 E4640010 */  swc1  $f4, 0x10($v1)
/* 0566A4 7F021B34 AFAD0054 */  sw    $t5, 0x54($sp)
.Ljp7F021B38:
/* 0566A8 7F021B38 00002025 */  move  $a0, $zero
/* 0566AC 7F021B3C 24050008 */  li    $a1, 8
/* 0566B0 7F021B40 0C0030DC */  jal   joyGetButtons
/* 0566B4 7F021B44 AFA30058 */   sw    $v1, 0x58($sp)
/* 0566B8 7F021B48 10400008 */  beqz  $v0, .Ljp7F021B6C
/* 0566BC 7F021B4C 8FA30058 */   lw    $v1, 0x58($sp)
/* 0566C0 7F021B50 3C018005 */  lui   $at, %hi(D_80051D7C) # $at, 0x8005
/* 0566C4 7F021B54 C4281DB0 */  lwc1  $f8, %lo(D_80051D7C)($at)
/* 0566C8 7F021B58 C4660010 */  lwc1  $f6, 0x10($v1)
/* 0566CC 7F021B5C 240C0001 */  li    $t4, 1
/* 0566D0 7F021B60 46083282 */  mul.s $f10, $f6, $f8
/* 0566D4 7F021B64 E46A0010 */  swc1  $f10, 0x10($v1)
/* 0566D8 7F021B68 AFAC0054 */  sw    $t4, 0x54($sp)
.Ljp7F021B6C:
/* 0566DC 7F021B6C 00002025 */  move  $a0, $zero
/* 0566E0 7F021B70 24050002 */  li    $a1, 2
/* 0566E4 7F021B74 0C0030DC */  jal   joyGetButtons
/* 0566E8 7F021B78 AFA30058 */   sw    $v1, 0x58($sp)
/* 0566EC 7F021B7C 10400008 */  beqz  $v0, .Ljp7F021BA0
/* 0566F0 7F021B80 8FA30058 */   lw    $v1, 0x58($sp)
/* 0566F4 7F021B84 3C018005 */  lui   $at, %hi(D_80051D80) # $at, 0x8005
/* 0566F8 7F021B88 C4321DB4 */  lwc1  $f18, %lo(D_80051D80)($at)
/* 0566FC 7F021B8C C470000C */  lwc1  $f16, 0xc($v1)
/* 056700 7F021B90 24180001 */  li    $t8, 1
/* 056704 7F021B94 46128102 */  mul.s $f4, $f16, $f18
/* 056708 7F021B98 E464000C */  swc1  $f4, 0xc($v1)
/* 05670C 7F021B9C AFB80054 */  sw    $t8, 0x54($sp)
.Ljp7F021BA0:
/* 056710 7F021BA0 00002025 */  move  $a0, $zero
/* 056714 7F021BA4 24050001 */  li    $a1, 1
/* 056718 7F021BA8 0C0030DC */  jal   joyGetButtons
/* 05671C 7F021BAC AFA30058 */   sw    $v1, 0x58($sp)
/* 056720 7F021BB0 10400008 */  beqz  $v0, .Ljp7F021BD4
/* 056724 7F021BB4 8FA30058 */   lw    $v1, 0x58($sp)
/* 056728 7F021BB8 3C018005 */  lui   $at, %hi(D_80051D84) # $at, 0x8005
/* 05672C 7F021BBC C4281DB8 */  lwc1  $f8, %lo(D_80051D84)($at)
/* 056730 7F021BC0 C466000C */  lwc1  $f6, 0xc($v1)
/* 056734 7F021BC4 24190001 */  li    $t9, 1
/* 056738 7F021BC8 46083282 */  mul.s $f10, $f6, $f8
/* 05673C 7F021BCC E46A000C */  swc1  $f10, 0xc($v1)
/* 056740 7F021BD0 AFB90054 */  sw    $t9, 0x54($sp)
.Ljp7F021BD4:
/* 056744 7F021BD4 3C018005 */  lui   $at, %hi(D_80051D88) # $at, 0x8005
/* 056748 7F021BD8 C4201DBC */  lwc1  $f0, %lo(D_80051D88)($at)
/* 05674C 7F021BDC C4700000 */  lwc1  $f16, ($v1)
/* 056750 7F021BE0 27A400F0 */  addiu $a0, $sp, 0xf0
/* 056754 7F021BE4 27A500A4 */  addiu $a1, $sp, 0xa4
/* 056758 7F021BE8 46008482 */  mul.s $f18, $f16, $f0
/* 05675C 7F021BEC E7B200F0 */  swc1  $f18, 0xf0($sp)
/* 056760 7F021BF0 C4640004 */  lwc1  $f4, 4($v1)
/* 056764 7F021BF4 46002182 */  mul.s $f6, $f4, $f0
/* 056768 7F021BF8 E7A600F4 */  swc1  $f6, 0xf4($sp)
/* 05676C 7F021BFC C4680008 */  lwc1  $f8, 8($v1)
/* 056770 7F021C00 46004282 */  mul.s $f10, $f8, $f0
/* 056774 7F021C04 E7AA00F8 */  swc1  $f10, 0xf8($sp)
/* 056778 7F021C08 C470000C */  lwc1  $f16, 0xc($v1)
/* 05677C 7F021C0C E7B000EC */  swc1  $f16, 0xec($sp)
/* 056780 7F021C10 C4720010 */  lwc1  $f18, 0x10($v1)
/* 056784 7F021C14 E7B200E8 */  swc1  $f18, 0xe8($sp)
/* 056788 7F021C18 C4640014 */  lwc1  $f4, 0x14($v1)
/* 05678C 7F021C1C 0FC163A1 */  jal   matrix_4x4_set_identity_and_position
/* 056790 7F021C20 E7A400E4 */   swc1  $f4, 0xe4($sp)
/* 056794 7F021C24 C7AC00EC */  lwc1  $f12, 0xec($sp)
/* 056798 7F021C28 0FC163B5 */  jal   matrix_column_1_scalar_multiply
/* 05679C 7F021C2C 27A500A4 */   addiu $a1, $sp, 0xa4
/* 0567A0 7F021C30 C7AC00E8 */  lwc1  $f12, 0xe8($sp)
/* 0567A4 7F021C34 0FC163C1 */  jal   matrix_column_2_scalar_multiply
/* 0567A8 7F021C38 27A500A4 */   addiu $a1, $sp, 0xa4
/* 0567AC 7F021C3C C7AC00E4 */  lwc1  $f12, 0xe4($sp)
/* 0567B0 7F021C40 0FC163DB */  jal   matrix_column_3_scalar_multiply_2
/* 0567B4 7F021C44 27A500A4 */   addiu $a1, $sp, 0xa4
/* 0567B8 7F021C48 8FAE00FC */  lw    $t6, 0xfc($sp)
/* 0567BC 7F021C4C 27A500A4 */  addiu $a1, $sp, 0xa4
/* 0567C0 7F021C50 27A60064 */  addiu $a2, $sp, 0x64
/* 0567C4 7F021C54 0FC161AB */  jal   matrix_4x4_multiply_homogeneous
/* 0567C8 7F021C58 8DC4000C */   lw    $a0, 0xc($t6)
/* 0567CC 7F021C5C 8FA800FC */  lw    $t0, 0xfc($sp)
/* 0567D0 7F021C60 27A40064 */  addiu $a0, $sp, 0x64
/* 0567D4 7F021C64 0FC16150 */  jal   matrix_4x4_copy
/* 0567D8 7F021C68 8D05000C */   lw    $a1, 0xc($t0)
/* 0567DC 7F021C6C 8FAF0060 */  lw    $t7, 0x60($sp)
/* 0567E0 7F021C70 24010002 */  li    $at, 2
/* 0567E4 7F021C74 55E10003 */  bnel  $t7, $at, .Ljp7F021C84
/* 0567E8 7F021C78 96090012 */   lhu   $t1, 0x12($s0)
/* 0567EC 7F021C7C AFA00108 */  sw    $zero, 0x108($sp)
.Ljp7F021C80:
/* 0567F0 7F021C80 96090012 */  lhu   $t1, 0x12($s0)
.Ljp7F021C84:
/* 0567F4 7F021C84 8FAB0100 */  lw    $t3, 0x100($sp)
/* 0567F8 7F021C88 8FA500FC */  lw    $a1, 0xfc($sp)
/* 0567FC 7F021C8C 312A0001 */  andi  $t2, $t1, 1
/* 056800 7F021C90 11400005 */  beqz  $t2, .Ljp7F021CA8
/* 056804 7F021C94 00000000 */   nop   
/* 056808 7F021C98 8D6D0064 */  lw    $t5, 0x64($t3)
/* 05680C 7F021C9C 31AC0080 */  andi  $t4, $t5, 0x80
/* 056810 7F021CA0 55800005 */  bnezl $t4, .Ljp7F021CB8
/* 056814 7F021CA4 8FB80110 */   lw    $t8, 0x110($sp)
.Ljp7F021CA8:
/* 056818 7F021CA8 0FC1ADC4 */  jal   sub_GAME_7F06B120
/* 05681C 7F021CAC 8E040020 */   lw    $a0, 0x20($s0)
/* 056820 7F021CB0 AE020020 */  sw    $v0, 0x20($s0)
/* 056824 7F021CB4 8FB80110 */  lw    $t8, 0x110($sp)
.Ljp7F021CB8:
/* 056828 7F021CB8 8F190008 */  lw    $t9, 8($t8)
/* 05682C 7F021CBC 8F2E0008 */  lw    $t6, 8($t9)
/* 056830 7F021CC0 8DC50010 */  lw    $a1, 0x10($t6)
/* 056834 7F021CC4 10A0000E */  beqz  $a1, .Ljp7F021D00
/* 056838 7F021CC8 00000000 */   nop   
/* 05683C 7F021CCC 0FC1B363 */  jal   extract_id_from_object_structure_microcode
/* 056840 7F021CD0 03002025 */   move  $a0, $t8
/* 056844 7F021CD4 8C430000 */  lw    $v1, ($v0)
/* 056848 7F021CD8 10600009 */  beqz  $v1, .Ljp7F021D00
/* 05684C 7F021CDC 00000000 */   nop   
/* 056850 7F021CE0 8C680008 */  lw    $t0, 8($v1)
/* 056854 7F021CE4 8D050004 */  lw    $a1, 4($t0)
/* 056858 7F021CE8 10A00005 */  beqz  $a1, .Ljp7F021D00
/* 05685C 7F021CEC 00000000 */   nop   
/* 056860 7F021CF0 0FC1B363 */  jal   extract_id_from_object_structure_microcode
/* 056864 7F021CF4 8FA40110 */   lw    $a0, 0x110($sp)
/* 056868 7F021CF8 8FAF0108 */  lw    $t7, 0x108($sp)
/* 05686C 7F021CFC AC4F0000 */  sw    $t7, ($v0)
.Ljp7F021D00:
/* 056870 7F021D00 0FC1AE23 */  jal   sub_GAME_7F06B29C
/* 056874 7F021D04 8E040020 */   lw    $a0, 0x20($s0)
/* 056878 7F021D08 0FC1B046 */  jal   sub_GAME_7F06BB28
/* 05687C 7F021D0C 8E040020 */   lw    $a0, 0x20($s0)
/* 056880 7F021D10 10000020 */  b     .Ljp7F021D94
/* 056884 7F021D14 AE020020 */   sw    $v0, 0x20($s0)
/* 056888 7F021D18 8E020160 */  lw    $v0, 0x160($s0)
.Ljp7F021D1C:
/* 05688C 7F021D1C 50400005 */  beql  $v0, $zero, .Ljp7F021D34
/* 056890 7F021D20 8E020164 */   lw    $v0, 0x164($s0)
/* 056894 7F021D24 90490001 */  lbu   $t1, 1($v0)
/* 056898 7F021D28 312AFFFD */  andi  $t2, $t1, 0xfffd
/* 05689C 7F021D2C A04A0001 */  sb    $t2, 1($v0)
/* 0568A0 7F021D30 8E020164 */  lw    $v0, 0x164($s0)
.Ljp7F021D34:
/* 0568A4 7F021D34 2403FFFD */  li    $v1, -3
/* 0568A8 7F021D38 50400005 */  beql  $v0, $zero, .Ljp7F021D50
/* 0568AC 7F021D3C 8E0201D8 */   lw    $v0, 0x1d8($s0)
/* 0568B0 7F021D40 904B0001 */  lbu   $t3, 1($v0)
/* 0568B4 7F021D44 01636824 */  and   $t5, $t3, $v1
/* 0568B8 7F021D48 A04D0001 */  sb    $t5, 1($v0)
/* 0568BC 7F021D4C 8E0201D8 */  lw    $v0, 0x1d8($s0)
.Ljp7F021D50:
/* 0568C0 7F021D50 50400005 */  beql  $v0, $zero, .Ljp7F021D68
/* 0568C4 7F021D54 8FAE0158 */   lw    $t6, 0x158($sp)
/* 0568C8 7F021D58 904C0001 */  lbu   $t4, 1($v0)
/* 0568CC 7F021D5C 0183C824 */  and   $t9, $t4, $v1
/* 0568D0 7F021D60 A0590001 */  sb    $t9, 1($v0)
/* 0568D4 7F021D64 8FAE0158 */  lw    $t6, 0x158($sp)
.Ljp7F021D68:
/* 0568D8 7F021D68 91D80001 */  lbu   $t8, 1($t6)
/* 0568DC 7F021D6C 03034024 */  and   $t0, $t8, $v1
/* 0568E0 7F021D70 A1C80001 */  sb    $t0, 1($t6)
/* 0568E4 7F021D74 920F00F8 */  lbu   $t7, 0xf8($s0)
/* 0568E8 7F021D78 920900F9 */  lbu   $t1, 0xf9($s0)
/* 0568EC 7F021D7C 920A00FA */  lbu   $t2, 0xfa($s0)
/* 0568F0 7F021D80 920B00FB */  lbu   $t3, 0xfb($s0)
/* 0568F4 7F021D84 A20F00F4 */  sb    $t7, 0xf4($s0)
/* 0568F8 7F021D88 A20900F5 */  sb    $t1, 0xf5($s0)
/* 0568FC 7F021D8C A20A00F6 */  sb    $t2, 0xf6($s0)
/* 056900 7F021D90 A20B00F7 */  sb    $t3, 0xf7($s0)
.Ljp7F021D94:
/* 056904 7F021D94 8E0D0014 */  lw    $t5, 0x14($s0)
/* 056908 7F021D98 31AC0400 */  andi  $t4, $t5, 0x400
/* 05690C 7F021D9C 55800015 */  bnezl $t4, .Ljp7F021DF4
/* 056910 7F021DA0 00001025 */   move  $v0, $zero
/* 056914 7F021DA4 96020012 */  lhu   $v0, 0x12($s0)
/* 056918 7F021DA8 8FB80158 */  lw    $t8, 0x158($sp)
/* 05691C 7F021DAC 30590001 */  andi  $t9, $v0, 1
/* 056920 7F021DB0 1320000D */  beqz  $t9, .Ljp7F021DE8
/* 056924 7F021DB4 00000000 */   nop   
/* 056928 7F021DB8 8F040020 */  lw    $a0, 0x20($t8)
/* 05692C 7F021DBC 50800009 */  beql  $a0, $zero, .Ljp7F021DE4
/* 056930 7F021DC0 3048FFFE */   andi  $t0, $v0, 0xfffe
/* 056934 7F021DC4 8C830024 */  lw    $v1, 0x24($a0)
.Ljp7F021DC8:
/* 056938 7F021DC8 0FC1314D */  jal   sub_GAME_7F04C130
/* 05693C 7F021DCC AFA3003C */   sw    $v1, 0x3c($sp)
/* 056940 7F021DD0 8FA4003C */  lw    $a0, 0x3c($sp)
/* 056944 7F021DD4 5480FFFC */  bnezl $a0, .Ljp7F021DC8
/* 056948 7F021DD8 8C830024 */   lw    $v1, 0x24($a0)
/* 05694C 7F021DDC 96020012 */  lhu   $v0, 0x12($s0)
/* 056950 7F021DE0 3048FFFE */  andi  $t0, $v0, 0xfffe
.Ljp7F021DE4:
/* 056954 7F021DE4 A6080012 */  sh    $t0, 0x12($s0)
.Ljp7F021DE8:
/* 056958 7F021DE8 0FC0B95D */  jal   chrlvTriggerFireWeapon
/* 05695C 7F021DEC 02002025 */   move  $a0, $s0
/* 056960 7F021DF0 00001025 */  move  $v0, $zero
.Ljp7F021DF4:
/* 056964 7F021DF4 8FBF0024 */  lw    $ra, 0x24($sp)
/* 056968 7F021DF8 8FB00020 */  lw    $s0, 0x20($sp)
/* 05696C 7F021DFC 27BD0158 */  addiu $sp, $sp, 0x158
/* 056970 7F021E00 03E00008 */  jr    $ra
/* 056974 7F021E04 00000000 */   nop   
    
)
#endif

#ifdef VERSION_EU
GLOBAL_ASM(
/* i belong to sub_GAME_7F02083C*/
.late_rodata
glabel D_80051D30
.word 0x3f860a92 /*1.0471976*/
glabel D_80051D34
.word 0xbf5f66f3 /*-0.87266463*/
glabel D_80051D38
.word 0x3f5f66f3 /*0.87266463*/
glabel D_80051D3C
.word 0x3f860a92 /*1.0471976*/
glabel D_80051D40
.word 0xbf5f66f3 /*-0.87266463*/
glabel D_80051D44
.word 0x40c90fdb /*6.2831855*/
glabel D_80051D48
.word 0x40c90fdb /*6.2831855*/
glabel D_80051D4C
.word 0x40c90fdb /*6.2831855*/
glabel D_80051D50
.word 0x40c90fdb /*6.2831855*/
glabel D_80051D54
.word 0x40c90fdb /*6.2831855*/

/* i belong to this function*/
.late_rodata
glabel D_jp80051D88
.word 0x3f4ccccd
glabel D_80051D58
.word 0x3ca3d70a /*0.02*/
glabel D_80051D5C
.word 0x3ca3d70a /*0.02*/
glabel D_80051D60
.word 0x3ca3d70a /*0.02*/
glabel D_80051D64
.word 0x3ca3d70a /*0.02*/
glabel D_80051D68
.word 0x3ca3d70a /*0.02*/
glabel D_80051D6C
.word 0x3ca3d70a /*0.02*/
glabel D_80051D70
.word 0x3f7eb852 /*0.995*/
glabel D_80051D74
.word 0x3f80a3d7 /*1.005*/
glabel D_80051D78
.word 0x3f7eb852 /*0.995*/
glabel D_80051D7C
.word 0x3f80a3d7 /*1.005*/
glabel D_80051D80
.word 0x3f7eb852 /*0.995*/
glabel D_80051D84
.word 0x3f80a3d7 /*1.005*/
glabel D_80051D88
.word 0x41aa6666 /*21.299999*/
.text
glabel sub_GAME_7F020EF0
/* 053858 7F020E68 27BDFEA8 */  addiu $sp, $sp, -0x158
/* 05385C 7F020E6C 3C0F8003 */  lui   $t7, %hi(D_8002CC6C) # $t7, 0x8003
/* 053860 7F020E70 25EF81BC */  addiu $t7, %lo(D_8002CC6C) # addiu $t7, $t7, -0x7e44
/* 053864 7F020E74 AFBF0024 */  sw    $ra, 0x24($sp)
/* 053868 7F020E78 AFB00020 */  sw    $s0, 0x20($sp)
/* 05386C 7F020E7C AFA40158 */  sw    $a0, 0x158($sp)
/* 053870 7F020E80 25E8003C */  addiu $t0, $t7, 0x3c
/* 053874 7F020E84 27AE0118 */  addiu $t6, $sp, 0x118
.L7F020E88:
/* 053878 7F020E88 8DE10000 */  lw    $at, ($t7)
/* 05387C 7F020E8C 25EF000C */  addiu $t7, $t7, 0xc
/* 053880 7F020E90 25CE000C */  addiu $t6, $t6, 0xc
/* 053884 7F020E94 ADC1FFF4 */  sw    $at, -0xc($t6)
/* 053888 7F020E98 8DE1FFF8 */  lw    $at, -8($t7)
/* 05388C 7F020E9C ADC1FFF8 */  sw    $at, -8($t6)
/* 053890 7F020EA0 8DE1FFFC */  lw    $at, -4($t7)
/* 053894 7F020EA4 15E8FFF8 */  bne   $t7, $t0, .L7F020E88
/* 053898 7F020EA8 ADC1FFFC */   sw    $at, -4($t6)
/* 05389C 7F020EAC 8DE10000 */  lw    $at, ($t7)
/* 0538A0 7F020EB0 3C0C8004 */  lui   $t4, %hi(g_ClockTimer) # $t4, 0x8004
/* 0538A4 7F020EB4 240B0001 */  li    $t3, 1
/* 0538A8 7F020EB8 ADC10000 */  sw    $at, ($t6)
/* 0538AC 7F020EBC 8FA90158 */  lw    $t1, 0x158($sp)
/* 0538B0 7F020EC0 8D8C0FF4 */  lw    $t4, %lo(g_ClockTimer)($t4)
/* 0538B4 7F020EC4 3C188002 */  lui   $t8, %hi(D_8002C904) # $t8, 0x8002
/* 0538B8 7F020EC8 8D300004 */  lw    $s0, 4($t1)
/* 0538BC 7F020ECC 8E0A001C */  lw    $t2, 0x1c($s0)
/* 0538C0 7F020ED0 AFAB0108 */  sw    $t3, 0x108($sp)
/* 0538C4 7F020ED4 AFAC0104 */  sw    $t4, 0x104($sp)
/* 0538C8 7F020ED8 AFAA0110 */  sw    $t2, 0x110($sp)
/* 0538CC 7F020EDC 8E020014 */  lw    $v0, 0x14($s0)
/* 0538D0 7F020EE0 304D0400 */  andi  $t5, $v0, 0x400
/* 0538D4 7F020EE4 11A00003 */  beqz  $t5, .L7F020EF4
/* 0538D8 7F020EE8 0002CB40 */   sll   $t9, $v0, 0xd
/* 0538DC 7F020EEC 07230035 */  bgezl $t9, .L7F020FC4
/* 0538E0 7F020EF0 96180012 */   lhu   $t8, 0x12($s0)
.L7F020EF4:
/* 0538E4 7F020EF4 8F187E54 */  lw    $t8, %lo(D_8002C904)($t8)
/* 0538E8 7F020EF8 3C088002 */  lui   $t0, %hi(g_AnimationTablePointerCountRelated) # $t0, 0x8002
/* 0538EC 7F020EFC 1300001E */  beqz  $t8, .L7F020F78
/* 0538F0 7F020F00 00000000 */   nop   
/* 0538F4 7F020F04 8D087E58 */  lw    $t0, %lo(g_AnimationTablePointerCountRelated)($t0)
/* 0538F8 7F020F08 3C0E8002 */  lui   $t6, %hi(animation_table_ptrs1)
/* 0538FC 7F020F0C 24010001 */  li    $at, 1
/* 053900 7F020F10 00087880 */  sll   $t7, $t0, 2
/* 053904 7F020F14 01CF7021 */  addu  $t6, $t6, $t7
/* 053908 7F020F18 8DCE52BC */  lw    $t6, %lo(animation_table_ptrs1)($t6)
/* 05390C 7F020F1C 11C1001D */  beq   $t6, $at, .L7F020F94
/* 053910 7F020F20 00000000 */   nop   
/* 053914 7F020F24 0FC1BDD3 */  jal   objecthandlerGetModelAnim
/* 053918 7F020F28 8FA40110 */   lw    $a0, 0x110($sp)
/* 05391C 7F020F2C 3C098002 */  lui   $t1, %hi(g_AnimationTablePointerCountRelated) # $t1, 0x8002
/* 053920 7F020F30 8D297E58 */  lw    $t1, %lo(g_AnimationTablePointerCountRelated)($t1)
/* 053924 7F020F34 3C058002 */  lui   $a1, %hi(animation_table_ptrs1)
/* 053928 7F020F38 8FA40110 */  lw    $a0, 0x110($sp)
/* 05392C 7F020F3C 00095080 */  sll   $t2, $t1, 2
/* 053930 7F020F40 00AA2821 */  addu  $a1, $a1, $t2
/* 053934 7F020F44 8CA552BC */  lw    $a1, %lo(animation_table_ptrs1)($a1)
/* 053938 7F020F48 00003025 */  move  $a2, $zero
/* 05393C 7F020F4C 10450011 */  beq   $v0, $a1, .L7F020F94
/* 053940 7F020F50 00000000 */   nop   
/* 053944 7F020F54 44800000 */  mtc1  $zero, $f0
/* 053948 7F020F58 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 05394C 7F020F5C 44812000 */  mtc1  $at, $f4
/* 053950 7F020F60 44070000 */  mfc1  $a3, $f0
/* 053954 7F020F64 E7A00014 */  swc1  $f0, 0x14($sp)
/* 053958 7F020F68 0FC1BF92 */  jal   modelSetAnimation
/* 05395C 7F020F6C E7A40010 */   swc1  $f4, 0x10($sp)
/* 053960 7F020F70 10000008 */  b     .L7F020F94
/* 053964 7F020F74 00000000 */   nop   
.L7F020F78:
/* 053968 7F020F78 0FC0C9C0 */  jal   chrlvActionTick
/* 05396C 7F020F7C 02002025 */   move  $a0, $s0
/* 053970 7F020F80 8E0B001C */  lw    $t3, 0x1c($s0)
/* 053974 7F020F84 15600003 */  bnez  $t3, .L7F020F94
/* 053978 7F020F88 00000000 */   nop   
/* 05397C 7F020F8C 100002D1 */  b     .L7F021AD4
/* 053980 7F020F90 24020001 */   li    $v0, 1
.L7F020F94:
/* 053984 7F020F94 3C0C8002 */  lui   $t4, %hi(D_8002C90C) # $t4, 0x8002
/* 053988 7F020F98 8D8C7E5C */  lw    $t4, %lo(D_8002C90C)($t4)
/* 05398C 7F020F9C 3C0D8002 */  lui   $t5, %hi(D_8002C910) # $t5, 0x8002
/* 053990 7F020FA0 51800008 */  beql  $t4, $zero, .L7F020FC4
/* 053994 7F020FA4 96180012 */   lhu   $t8, 0x12($s0)
/* 053998 7F020FA8 8DAD7E60 */  lw    $t5, %lo(D_8002C910)($t5)
/* 05399C 7F020FAC AFA00104 */  sw    $zero, 0x104($sp)
/* 0539A0 7F020FB0 24190001 */  li    $t9, 1
/* 0539A4 7F020FB4 51A00003 */  beql  $t5, $zero, .L7F020FC4
/* 0539A8 7F020FB8 96180012 */   lhu   $t8, 0x12($s0)
/* 0539AC 7F020FBC AFB90104 */  sw    $t9, 0x104($sp)
/* 0539B0 7F020FC0 96180012 */  lhu   $t8, 0x12($s0)
.L7F020FC4:
/* 0539B4 7F020FC4 33080020 */  andi  $t0, $t8, 0x20
/* 0539B8 7F020FC8 51000006 */  beql  $t0, $zero, .L7F020FE4
/* 0539BC 7F020FCC 8E020160 */   lw    $v0, 0x160($s0)
/* 0539C0 7F020FD0 0FC080A2 */  jal   disable_sounds_attached_to_player_then_something
/* 0539C4 7F020FD4 8FA40158 */   lw    $a0, 0x158($sp)
/* 0539C8 7F020FD8 100002BE */  b     .L7F021AD4
/* 0539CC 7F020FDC 24020001 */   li    $v0, 1
/* 0539D0 7F020FE0 8E020160 */  lw    $v0, 0x160($s0)
.L7F020FE4:
/* 0539D4 7F020FE4 50400009 */  beql  $v0, $zero, .L7F02100C
/* 0539D8 7F020FE8 8E020164 */   lw    $v0, 0x164($s0)
/* 0539DC 7F020FEC 8C440004 */  lw    $a0, 4($v0)
/* 0539E0 7F020FF0 8C8F0064 */  lw    $t7, 0x64($a0)
/* 0539E4 7F020FF4 31EE0004 */  andi  $t6, $t7, 4
/* 0539E8 7F020FF8 51C00004 */  beql  $t6, $zero, .L7F02100C
/* 0539EC 7F020FFC 8E020164 */   lw    $v0, 0x164($s0)
/* 0539F0 7F021000 0FC10439 */  jal   objFreePermanently
/* 0539F4 7F021004 24050001 */   li    $a1, 1
/* 0539F8 7F021008 8E020164 */  lw    $v0, 0x164($s0)
.L7F02100C:
/* 0539FC 7F02100C 50400009 */  beql  $v0, $zero, .L7F021034
/* 053A00 7F021010 8E020014 */   lw    $v0, 0x14($s0)
/* 053A04 7F021014 8C440004 */  lw    $a0, 4($v0)
/* 053A08 7F021018 8C890064 */  lw    $t1, 0x64($a0)
/* 053A0C 7F02101C 312A0004 */  andi  $t2, $t1, 4
/* 053A10 7F021020 51400004 */  beql  $t2, $zero, .L7F021034
/* 053A14 7F021024 8E020014 */   lw    $v0, 0x14($s0)
/* 053A18 7F021028 0FC10439 */  jal   objFreePermanently
/* 053A1C 7F02102C 24050001 */   li    $a1, 1
/* 053A20 7F021030 8E020014 */  lw    $v0, 0x14($s0)
.L7F021034:
/* 053A24 7F021034 8FAC0158 */  lw    $t4, 0x158($sp)
/* 053A28 7F021038 304B0400 */  andi  $t3, $v0, 0x400
/* 053A2C 7F02103C 51600005 */  beql  $t3, $zero, .L7F021054
/* 053A30 7F021040 918D0000 */   lbu   $t5, ($t4)
/* 053A34 7F021044 AFA0010C */  sw    $zero, 0x10c($sp)
/* 053A38 7F021048 100000BD */  b     .L7F021340
/* 053A3C 7F02104C 82030007 */   lb    $v1, 7($s0)
/* 053A40 7F021050 918D0000 */  lbu   $t5, ($t4)
.L7F021054:
/* 053A44 7F021054 24010006 */  li    $at, 6
/* 053A48 7F021058 55A1000D */  bnel  $t5, $at, .L7F021090
/* 053A4C 7F02105C 00027A00 */   sll   $t7, $v0, 8
/* 053A50 7F021060 0FC269A7 */  jal   sub_GAME_7F09B15C
/* 053A54 7F021064 01802025 */   move  $a0, $t4
/* 053A58 7F021068 0002C880 */  sll   $t9, $v0, 2
/* 053A5C 7F02106C 3C188007 */  lui   $t8, %hi(g_playerPointers)
/* 053A60 7F021070 0319C021 */  addu  $t8, $t8, $t9
/* 053A64 7F021074 8F1889F0 */  lw    $t8, %lo(g_playerPointers)($t8)
/* 053A68 7F021078 24010001 */  li    $at, 1
/* 053A6C 7F02107C 8F080000 */  lw    $t0, ($t8)
/* 053A70 7F021080 51010005 */  beql  $t0, $at, .L7F021098
/* 053A74 7F021084 240E0001 */   li    $t6, 1
/* 053A78 7F021088 8E020014 */  lw    $v0, 0x14($s0)
/* 053A7C 7F02108C 00027A00 */  sll   $t7, $v0, 8
.L7F021090:
/* 053A80 7F021090 05E10017 */  bgez  $t7, .L7F0210F0
/* 053A84 7F021094 240E0001 */   li    $t6, 1
.L7F021098:
/* 053A88 7F021098 AFAE010C */  sw    $t6, 0x10c($sp)
/* 053A8C 7F02109C 82090007 */  lb    $t1, 7($s0)
/* 053A90 7F0210A0 24010003 */  li    $at, 3
/* 053A94 7F0210A4 02002025 */  move  $a0, $s0
/* 053A98 7F0210A8 1521000D */  bne   $t1, $at, .L7F0210E0
/* 053A9C 7F0210AC 00000000 */   nop   
/* 053AA0 7F0210B0 8E0A002C */  lw    $t2, 0x2c($s0)
/* 053AA4 7F0210B4 1540000A */  bnez  $t2, .L7F0210E0
/* 053AA8 7F0210B8 00000000 */   nop   
/* 053AAC 7F0210BC 8E0B003C */  lw    $t3, 0x3c($s0)
/* 053AB0 7F0210C0 8FA50104 */  lw    $a1, 0x104($sp)
/* 053AB4 7F0210C4 00003025 */  move  $a2, $zero
/* 053AB8 7F0210C8 11600005 */  beqz  $t3, .L7F0210E0
/* 053ABC 7F0210CC 00000000 */   nop   
/* 053AC0 7F0210D0 0FC1C323 */  jal   sub_GAME_7F070AEC
/* 053AC4 7F0210D4 8FA40110 */   lw    $a0, 0x110($sp)
/* 053AC8 7F0210D8 10000003 */  b     .L7F0210E8
/* 053ACC 7F0210DC 00000000 */   nop   
.L7F0210E0:
/* 053AD0 7F0210E0 0FC0836E */  jal   chrPositionRelated7F020E40
/* 053AD4 7F0210E4 8FA50104 */   lw    $a1, 0x104($sp)
.L7F0210E8:
/* 053AD8 7F0210E8 10000095 */  b     .L7F021340
/* 053ADC 7F0210EC 82030007 */   lb    $v1, 7($s0)
.L7F0210F0:
/* 053AE0 7F0210F0 82030007 */  lb    $v1, 7($s0)
/* 053AE4 7F0210F4 2406000E */  li    $a2, 14
/* 053AE8 7F0210F8 2401000F */  li    $at, 15
/* 053AEC 7F0210FC 10C30003 */  beq   $a2, $v1, .L7F02110C
/* 053AF0 7F021100 00000000 */   nop   
/* 053AF4 7F021104 54610041 */  bnel  $v1, $at, .L7F02120C
/* 053AF8 7F021108 24010003 */   li    $at, 3
.L7F02110C:
/* 053AFC 7F02110C 54C30005 */  bnel  $a2, $v1, .L7F021124
/* 053B00 7F021110 2401000F */   li    $at, 15
/* 053B04 7F021114 820D0038 */  lb    $t5, 0x38($s0)
/* 053B08 7F021118 24010006 */  li    $at, 6
/* 053B0C 7F02111C 11A10007 */  beq   $t5, $at, .L7F02113C
/* 053B10 7F021120 2401000F */   li    $at, 15
.L7F021124:
/* 053B14 7F021124 1461001E */  bne   $v1, $at, .L7F0211A0
/* 053B18 7F021128 02002025 */   move  $a0, $s0
/* 053B1C 7F02112C 820C005C */  lb    $t4, 0x5c($s0)
/* 053B20 7F021130 24010006 */  li    $at, 6
/* 053B24 7F021134 1581001A */  bne   $t4, $at, .L7F0211A0
/* 053B28 7F021138 00000000 */   nop   
.L7F02113C:
/* 053B2C 7F02113C 0FC1B525 */  jal   getinstsize
/* 053B30 7F021140 8FA40110 */   lw    $a0, 0x110($sp)
/* 053B34 7F021144 8FA40158 */  lw    $a0, 0x158($sp)
/* 053B38 7F021148 44060000 */  mfc1  $a2, $f0
/* 053B3C 7F02114C 24070001 */  li    $a3, 1
/* 053B40 7F021150 24850008 */  addiu $a1, $a0, 8
/* 053B44 7F021154 0FC15413 */  jal   sub_GAME_7F054D6C
/* 053B48 7F021158 AFA50030 */   sw    $a1, 0x30($sp)
/* 053B4C 7F02115C 10400028 */  beqz  $v0, .L7F021200
/* 053B50 7F021160 AFA2010C */   sw    $v0, 0x10c($sp)
/* 053B54 7F021164 8FA40110 */  lw    $a0, 0x110($sp)
/* 053B58 7F021168 0FC1B476 */  jal   getsuboffset
/* 053B5C 7F02116C 260500BC */   addiu $a1, $s0, 0xbc
/* 053B60 7F021170 0FC1B6B8 */  jal   subcalcpos
/* 053B64 7F021174 8FA40110 */   lw    $a0, 0x110($sp)
/* 053B68 7F021178 8FA40158 */  lw    $a0, 0x158($sp)
/* 053B6C 7F02117C 0FC10057 */  jal   set_color_shading_from_tile
/* 053B70 7F021180 260500F8 */   addiu $a1, $s0, 0xf8
/* 053B74 7F021184 8FA40110 */  lw    $a0, 0x110($sp)
/* 053B78 7F021188 0FC1B476 */  jal   getsuboffset
/* 053B7C 7F02118C 8FA50030 */   lw    $a1, 0x30($sp)
/* 053B80 7F021190 0FC08343 */  jal   chrPositionRelated7F020D94
/* 053B84 7F021194 02002025 */   move  $a0, $s0
/* 053B88 7F021198 10000019 */  b     .L7F021200
/* 053B8C 7F02119C 00000000 */   nop   
.L7F0211A0:
/* 053B90 7F0211A0 0FC0836E */  jal   chrPositionRelated7F020E40
/* 053B94 7F0211A4 8FA50104 */   lw    $a1, 0x104($sp)
/* 053B98 7F0211A8 0FC1B525 */  jal   getinstsize
/* 053B9C 7F0211AC 8FA40110 */   lw    $a0, 0x110($sp)
/* 053BA0 7F0211B0 8FA40158 */  lw    $a0, 0x158($sp)
/* 053BA4 7F0211B4 44060000 */  mfc1  $a2, $f0
/* 053BA8 7F0211B8 24070001 */  li    $a3, 1
/* 053BAC 7F0211BC 0FC15413 */  jal   sub_GAME_7F054D6C
/* 053BB0 7F0211C0 24850008 */   addiu $a1, $a0, 8
/* 053BB4 7F0211C4 1040000E */  beqz  $v0, .L7F021200
/* 053BB8 7F0211C8 AFA2010C */   sw    $v0, 0x10c($sp)
/* 053BBC 7F0211CC 82030007 */  lb    $v1, 7($s0)
/* 053BC0 7F0211D0 2401000E */  li    $at, 14
/* 053BC4 7F0211D4 3C088004 */  lui   $t0, %hi(g_GlobalTimer) # $t0, 0x8004
/* 053BC8 7F0211D8 54610005 */  bnel  $v1, $at, .L7F0211F0
/* 053BCC 7F0211DC 2401000F */   li    $at, 15
/* 053BD0 7F0211E0 8D080FFC */  lw    $t0, %lo(g_GlobalTimer)($t0)
/* 053BD4 7F0211E4 10000006 */  b     .L7F021200
/* 053BD8 7F0211E8 AE080078 */   sw    $t0, 0x78($s0)
/* 053BDC 7F0211EC 2401000F */  li    $at, 15
.L7F0211F0:
/* 053BE0 7F0211F0 14610003 */  bne   $v1, $at, .L7F021200
/* 053BE4 7F0211F4 3C0F8004 */   lui   $t7, %hi(g_GlobalTimer) # $t7, 0x8004
/* 053BE8 7F0211F8 8DEF0FFC */  lw    $t7, %lo(g_GlobalTimer)($t7)
/* 053BEC 7F0211FC AE0F009C */  sw    $t7, 0x9c($s0)
.L7F021200:
/* 053BF0 7F021200 1000004F */  b     .L7F021340
/* 053BF4 7F021204 82030007 */   lb    $v1, 7($s0)
/* 053BF8 7F021208 24010003 */  li    $at, 3
.L7F02120C:
/* 053BFC 7F02120C 5461001C */  bnel  $v1, $at, .L7F021280
/* 053C00 7F021210 24010001 */   li    $at, 1
/* 053C04 7F021214 8E0E002C */  lw    $t6, 0x2c($s0)
/* 053C08 7F021218 55C00019 */  bnezl $t6, .L7F021280
/* 053C0C 7F02121C 24010001 */   li    $at, 1
/* 053C10 7F021220 0FC1B525 */  jal   getinstsize
/* 053C14 7F021224 8FA40110 */   lw    $a0, 0x110($sp)
/* 053C18 7F021228 8FA40158 */  lw    $a0, 0x158($sp)
/* 053C1C 7F02122C 44060000 */  mfc1  $a2, $f0
/* 053C20 7F021230 24070001 */  li    $a3, 1
/* 053C24 7F021234 0FC15413 */  jal   sub_GAME_7F054D6C
/* 053C28 7F021238 24850008 */   addiu $a1, $a0, 8
/* 053C2C 7F02123C 10400009 */  beqz  $v0, .L7F021264
/* 053C30 7F021240 AFA2010C */   sw    $v0, 0x10c($sp)
/* 053C34 7F021244 8E0A003C */  lw    $t2, 0x3c($s0)
/* 053C38 7F021248 02002025 */  move  $a0, $s0
/* 053C3C 7F02124C 55400006 */  bnezl $t2, .L7F021268
/* 053C40 7F021250 8FA40110 */   lw    $a0, 0x110($sp)
/* 053C44 7F021254 0FC0836E */  jal   chrPositionRelated7F020E40
/* 053C48 7F021258 8FA50104 */   lw    $a1, 0x104($sp)
/* 053C4C 7F02125C 10000005 */  b     .L7F021274
/* 053C50 7F021260 00000000 */   nop   
.L7F021264:
/* 053C54 7F021264 8FA40110 */  lw    $a0, 0x110($sp)
.L7F021268:
/* 053C58 7F021268 8FA50104 */  lw    $a1, 0x104($sp)
/* 053C5C 7F02126C 0FC1C323 */  jal   sub_GAME_7F070AEC
/* 053C60 7F021270 00003025 */   move  $a2, $zero
.L7F021274:
/* 053C64 7F021274 10000032 */  b     .L7F021340
/* 053C68 7F021278 82030007 */   lb    $v1, 7($s0)
/* 053C6C 7F02127C 24010001 */  li    $at, 1
.L7F021280:
/* 053C70 7F021280 1461001C */  bne   $v1, $at, .L7F0212F4
/* 053C74 7F021284 30484000 */   andi  $t0, $v0, 0x4000
/* 053C78 7F021288 0FC1B525 */  jal   getinstsize
/* 053C7C 7F02128C 8FA40110 */   lw    $a0, 0x110($sp)
/* 053C80 7F021290 8FA40158 */  lw    $a0, 0x158($sp)
/* 053C84 7F021294 44060000 */  mfc1  $a2, $f0
/* 053C88 7F021298 24070001 */  li    $a3, 1
/* 053C8C 7F02129C 0FC15413 */  jal   sub_GAME_7F054D6C
/* 053C90 7F0212A0 24850008 */   addiu $a1, $a0, 8
/* 053C94 7F0212A4 14400005 */  bnez  $v0, .L7F0212BC
/* 053C98 7F0212A8 AFA2010C */   sw    $v0, 0x10c($sp)
/* 053C9C 7F0212AC 8E0D0014 */  lw    $t5, 0x14($s0)
/* 053CA0 7F0212B0 8FB90110 */  lw    $t9, 0x110($sp)
/* 053CA4 7F0212B4 31AC0001 */  andi  $t4, $t5, 1
/* 053CA8 7F0212B8 11800005 */  beqz  $t4, .L7F0212D0
.L7F0212BC:
/* 053CAC 7F0212BC 02002025 */   move  $a0, $s0
/* 053CB0 7F0212C0 0FC0836E */  jal   chrPositionRelated7F020E40
/* 053CB4 7F0212C4 8FA50104 */   lw    $a1, 0x104($sp)
/* 053CB8 7F0212C8 10000008 */  b     .L7F0212EC
/* 053CBC 7F0212CC 00000000 */   nop   
.L7F0212D0:
/* 053CC0 7F0212D0 8F380054 */  lw    $t8, 0x54($t9)
/* 053CC4 7F0212D4 03202025 */  move  $a0, $t9
/* 053CC8 7F0212D8 8FA50104 */  lw    $a1, 0x104($sp)
/* 053CCC 7F0212DC 13000003 */  beqz  $t8, .L7F0212EC
/* 053CD0 7F0212E0 00000000 */   nop   
/* 053CD4 7F0212E4 0FC1C323 */  jal   sub_GAME_7F070AEC
/* 053CD8 7F0212E8 00003025 */   move  $a2, $zero
.L7F0212EC:
/* 053CDC 7F0212EC 10000014 */  b     .L7F021340
/* 053CE0 7F0212F0 82030007 */   lb    $v1, 7($s0)
.L7F0212F4:
/* 053CE4 7F0212F4 11000007 */  beqz  $t0, .L7F021314
/* 053CE8 7F0212F8 02002025 */   move  $a0, $s0
/* 053CEC 7F0212FC 8FA40110 */  lw    $a0, 0x110($sp)
/* 053CF0 7F021300 8FA50104 */  lw    $a1, 0x104($sp)
/* 053CF4 7F021304 0FC1C323 */  jal   sub_GAME_7F070AEC
/* 053CF8 7F021308 00003025 */   move  $a2, $zero
/* 053CFC 7F02130C 10000003 */  b     .L7F02131C
/* 053D00 7F021310 00000000 */   nop   
.L7F021314:
/* 053D04 7F021314 0FC0836E */  jal   chrPositionRelated7F020E40
/* 053D08 7F021318 8FA50104 */   lw    $a1, 0x104($sp)
.L7F02131C:
/* 053D0C 7F02131C 0FC1B525 */  jal   getinstsize
/* 053D10 7F021320 8FA40110 */   lw    $a0, 0x110($sp)
/* 053D14 7F021324 8FA40158 */  lw    $a0, 0x158($sp)
/* 053D18 7F021328 44060000 */  mfc1  $a2, $f0
/* 053D1C 7F02132C 24070001 */  li    $a3, 1
/* 053D20 7F021330 0FC15413 */  jal   sub_GAME_7F054D6C
/* 053D24 7F021334 24850008 */   addiu $a1, $a0, 8
/* 053D28 7F021338 AFA2010C */  sw    $v0, 0x10c($sp)
/* 053D2C 7F02133C 82030007 */  lb    $v1, 7($s0)
.L7F021340:
/* 053D30 7F021340 24010001 */  li    $at, 1
/* 053D34 7F021344 14610009 */  bne   $v1, $at, .L7F02136C
/* 053D38 7F021348 8FAE0110 */   lw    $t6, 0x110($sp)
/* 053D3C 7F02134C 8DC90054 */  lw    $t1, 0x54($t6)
/* 053D40 7F021350 8FAA0158 */  lw    $t2, 0x158($sp)
/* 053D44 7F021354 55200006 */  bnezl $t1, .L7F021370
/* 053D48 7F021358 960D0012 */   lhu   $t5, 0x12($s0)
/* 053D4C 7F02135C 914B0000 */  lbu   $t3, ($t2)
/* 053D50 7F021360 24010006 */  li    $at, 6
/* 053D54 7F021364 15610004 */  bne   $t3, $at, .L7F021378
/* 053D58 7F021368 00000000 */   nop   
.L7F02136C:
/* 053D5C 7F02136C 960D0012 */  lhu   $t5, 0x12($s0)
.L7F021370:
/* 053D60 7F021370 35AC0200 */  ori   $t4, $t5, 0x200
/* 053D64 7F021374 A60C0012 */  sh    $t4, 0x12($s0)
.L7F021378:
/* 053D68 7F021378 0FC08120 */  jal   chrAimGlobalTimerTickRelated
/* 053D6C 7F02137C 02002025 */   move  $a0, $s0
/* 053D70 7F021380 8E040020 */  lw    $a0, 0x20($s0)
/* 053D74 7F021384 50800005 */  beql  $a0, $zero, .L7F02139C
/* 053D78 7F021388 8FB8010C */   lw    $t8, 0x10c($sp)
/* 053D7C 7F02138C 0FC1AE7E */  jal   sub_GAME_7F06B248
/* 053D80 7F021390 00000000 */   nop   
/* 053D84 7F021394 AE000020 */  sw    $zero, 0x20($s0)
/* 053D88 7F021398 8FB8010C */  lw    $t8, 0x10c($sp)
.L7F02139C:
/* 053D8C 7F02139C 261900F8 */  addiu $t9, $s0, 0xf8
/* 053D90 7F0213A0 53000196 */  beql  $t8, $zero, .L7F0219FC
/* 053D94 7F0213A4 8E020160 */   lw    $v0, 0x160($s0)
/* 053D98 7F0213A8 0FC24128 */  jal   get_debug_chrnum_flag
/* 053D9C 7F0213AC AFB9002C */   sw    $t9, 0x2c($sp)
/* 053DA0 7F0213B0 8FA20158 */  lw    $v0, 0x158($sp)
/* 053DA4 7F0213B4 2404000C */  li    $a0, 12
/* 053DA8 7F0213B8 90480001 */  lbu   $t0, 1($v0)
/* 053DAC 7F0213BC 350F0002 */  ori   $t7, $t0, 2
/* 053DB0 7F0213C0 A04F0001 */  sb    $t7, 1($v0)
/* 053DB4 7F0213C4 8E0E0014 */  lw    $t6, 0x14($s0)
/* 053DB8 7F0213C8 35C90008 */  ori   $t1, $t6, 8
/* 053DBC 7F0213CC 0FC24737 */  jal   cheatIsActive
/* 053DC0 7F0213D0 AE090014 */   sw    $t1, 0x14($s0)
/* 053DC4 7F0213D4 10400018 */  beqz  $v0, .L7F021438
/* 053DC8 7F0213D8 00000000 */   nop   
/* 053DCC 7F0213DC 8204000F */  lb    $a0, 0xf($s0)
/* 053DD0 7F0213E0 0FC081B3 */  jal   not_in_us_7F0209EC
/* 053DD4 7F0213E4 82050006 */   lb    $a1, 6($s0)
/* 053DD8 7F0213E8 10400013 */  beqz  $v0, .L7F021438
/* 053DDC 7F0213EC 3C013EA0 */   li    $at, 0x3EA00000 # 0.312500
/* 053DE0 7F0213F0 44816000 */  mtc1  $at, $f12
/* 053DE4 7F0213F4 0FC1B2D3 */  jal   set_float_80036088
/* 053DE8 7F0213F8 00000000 */   nop   
/* 053DEC 7F0213FC 8E020014 */  lw    $v0, 0x14($s0)
/* 053DF0 7F021400 3C01EFFF */  lui   $at, (0xEFFFFFFF >> 16) # lui $at, 0xefff
/* 053DF4 7F021404 3421FFFF */  ori   $at, (0xEFFFFFFF & 0xFFFF) # ori $at, $at, 0xffff
/* 053DF8 7F021408 000250C0 */  sll   $t2, $v0, 3
/* 053DFC 7F02140C 0541000A */  bgez  $t2, .L7F021438
/* 053E00 7F021410 00415824 */   and   $t3, $v0, $at
/* 053E04 7F021414 8E04001C */  lw    $a0, 0x1c($s0)
/* 053E08 7F021418 AE0B0014 */  sw    $t3, 0x14($s0)
/* 053E0C 7F02141C 3C018004 */  lui   $at, %hi(D_jp80051D88) # $at, 0x8004
/* 053E10 7F021420 C4287E80 */  lwc1  $f8, %lo(D_jp80051D88)($at)
/* 053E14 7F021424 C4860014 */  lwc1  $f6, 0x14($a0)
/* 053E18 7F021428 46083283 */  div.s $f10, $f6, $f8
/* 053E1C 7F02142C 44055000 */  mfc1  $a1, $f10
/* 053E20 7F021430 0FC1B4CF */  jal   modelSetScale
/* 053E24 7F021434 00000000 */   nop   
.L7F021438:
/* 053E28 7F021438 3C0D7F02 */  lui   $t5, %hi(sub_GAME_7F02083C) # $t5, 0x7f02
/* 053E2C 7F02143C 25AD078C */  addiu $t5, %lo(sub_GAME_7F02083C) # addiu $t5, $t5, 0x78c
/* 053E30 7F021440 3C018003 */  lui   $at, %hi(D_80036090) # $at, 0x8003
/* 053E34 7F021444 AC2D15E0 */  sw    $t5, %lo(D_80036090)($at)
/* 053E38 7F021448 3C018006 */  lui   $at, %hi(dword_CODE_bss_80069B60) # $at, 0x8006
/* 053E3C 7F02144C 0FC1E111 */  jal   currentPlayerGetMatrix10CC
/* 053E40 7F021450 AC308AA0 */   sw    $s0, %lo(dword_CODE_bss_80069B60)($at)
/* 053E44 7F021454 8FAC0110 */  lw    $t4, 0x110($sp)
/* 053E48 7F021458 AFA20118 */  sw    $v0, 0x118($sp)
/* 053E4C 7F02145C 8D980008 */  lw    $t8, 8($t4)
/* 053E50 7F021460 8704000E */  lh    $a0, 0xe($t8)
/* 053E54 7F021464 0004C980 */  sll   $t9, $a0, 6
/* 053E58 7F021468 0FC2F2B1 */  jal   dynAllocate
/* 053E5C 7F02146C 03202025 */   move  $a0, $t9
/* 053E60 7F021470 3C058006 */  lui   $a1, %hi(dword_CODE_bss_80069B60) # $a1, 0x8006
/* 053E64 7F021474 24A58AA0 */  addiu $a1, %lo(dword_CODE_bss_80069B60) # addiu $a1, $a1, -0x7560
/* 053E68 7F021478 8CA30000 */  lw    $v1, ($a1)
/* 053E6C 7F02147C AFA20128 */  sw    $v0, 0x128($sp)
/* 053E70 7F021480 80640011 */  lb    $a0, 0x11($v1)
/* 053E74 7F021484 0480000B */  bltz  $a0, .L7F0214B4
/* 053E78 7F021488 3C088004 */   lui   $t0, %hi(g_ClockTimer) # $t0, 0x8004
/* 053E7C 7F02148C 8D080FF4 */  lw    $t0, %lo(g_ClockTimer)($t0)
/* 053E80 7F021490 2409FFFF */  li    $t1, -1
/* 053E84 7F021494 00887821 */  addu  $t7, $a0, $t0
/* 053E88 7F021498 A06F0011 */  sb    $t7, 0x11($v1)
/* 053E8C 7F02149C 8CA30000 */  lw    $v1, ($a1)
/* 053E90 7F0214A0 806E0011 */  lb    $t6, 0x11($v1)
/* 053E94 7F0214A4 29C10018 */  slti  $at, $t6, 0x18
/* 053E98 7F0214A8 54200003 */  bnezl $at, .L7F0214B8
/* 053E9C 7F0214AC 27A40118 */   addiu $a0, $sp, 0x118
/* 053EA0 7F0214B0 A0690011 */  sb    $t1, 0x11($v1)
.L7F0214B4:
/* 053EA4 7F0214B4 27A40118 */  addiu $a0, $sp, 0x118
.L7F0214B8:
/* 053EA8 7F0214B8 0FC1BD9C */  jal   subcalcmatrices
/* 053EAC 7F0214BC 8FA50110 */   lw    $a1, 0x110($sp)
/* 053EB0 7F0214C0 3C018003 */  lui   $at, %hi(D_80036090) # $at, 0x8003
/* 053EB4 7F0214C4 AC2015E0 */  sw    $zero, %lo(D_80036090)($at)
/* 053EB8 7F0214C8 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 053EBC 7F0214CC 44816000 */  mtc1  $at, $f12
/* 053EC0 7F0214D0 0FC1B2D3 */  jal   set_float_80036088
/* 053EC4 7F0214D4 00000000 */   nop   
/* 053EC8 7F0214D8 260400F4 */  addiu $a0, $s0, 0xf4
/* 053ECC 7F0214DC 0FC100F4 */  jal   update_color_shading
/* 053ED0 7F0214E0 8FA5002C */   lw    $a1, 0x2c($sp)
/* 053ED4 7F0214E4 0FC1B396 */  jal   sub_GAME_7F06C768
/* 053ED8 7F0214E8 8FA40110 */   lw    $a0, 0x110($sp)
/* 053EDC 7F0214EC 8FAA0158 */  lw    $t2, 0x158($sp)
/* 053EE0 7F0214F0 00002025 */  move  $a0, $zero
/* 053EE4 7F0214F4 E5400018 */  swc1  $f0, 0x18($t2)
/* 053EE8 7F0214F8 0FC1AE34 */  jal   sub_GAME_7F06B120
/* 053EEC 7F0214FC 8FA50110 */   lw    $a1, 0x110($sp)
/* 053EF0 7F021500 AE020020 */  sw    $v0, 0x20($s0)
/* 053EF4 7F021504 26060020 */  addiu $a2, $s0, 0x20
/* 053EF8 7F021508 AFA60030 */  sw    $a2, 0x30($sp)
/* 053EFC 7F02150C 8FA40158 */  lw    $a0, 0x158($sp)
/* 053F00 7F021510 0FC149B6 */  jal   sub_GAME_7F0523F8
/* 053F04 7F021514 00002825 */   move  $a1, $zero
/* 053F08 7F021518 8FA60030 */  lw    $a2, 0x30($sp)
/* 053F0C 7F02151C 8FA40158 */  lw    $a0, 0x158($sp)
/* 053F10 7F021520 0FC149B6 */  jal   sub_GAME_7F0523F8
/* 053F14 7F021524 24050001 */   li    $a1, 1
/* 053F18 7F021528 8E0201D8 */  lw    $v0, 0x1d8($s0)
/* 053F1C 7F02152C 5040011A */  beql  $v0, $zero, .L7F021998
/* 053F20 7F021530 8FB80110 */   lw    $t8, 0x110($sp)
/* 053F24 7F021534 8C470004 */  lw    $a3, 4($v0)
/* 053F28 7F021538 904B0001 */  lbu   $t3, 1($v0)
/* 053F2C 7F02153C 00003025 */  move  $a2, $zero
/* 053F30 7F021540 8CE30014 */  lw    $v1, 0x14($a3)
/* 053F34 7F021544 356D0002 */  ori   $t5, $t3, 2
/* 053F38 7F021548 A04D0001 */  sb    $t5, 1($v0)
/* 053F3C 7F02154C 8C65001C */  lw    $a1, 0x1c($v1)
/* 053F40 7F021550 8FA40110 */  lw    $a0, 0x110($sp)
/* 053F44 7F021554 AFA70100 */  sw    $a3, 0x100($sp)
/* 053F48 7F021558 0FC1B366 */  jal   sub_GAME_7F06C660
/* 053F4C 7F02155C AFA300FC */   sw    $v1, 0xfc($sp)
/* 053F50 7F021560 8FAC00FC */  lw    $t4, 0xfc($sp)
/* 053F54 7F021564 AFA20118 */  sw    $v0, 0x118($sp)
/* 053F58 7F021568 8D980008 */  lw    $t8, 8($t4)
/* 053F5C 7F02156C 8704000E */  lh    $a0, 0xe($t8)
/* 053F60 7F021570 0004C980 */  sll   $t9, $a0, 6
/* 053F64 7F021574 0FC2F2B1 */  jal   dynAllocate
/* 053F68 7F021578 03202025 */   move  $a0, $t9
/* 053F6C 7F02157C AFA20128 */  sw    $v0, 0x128($sp)
/* 053F70 7F021580 27A40118 */  addiu $a0, $sp, 0x118
/* 053F74 7F021584 0FC1BD8D */  jal   instcalcmatrices
/* 053F78 7F021588 8FA500FC */   lw    $a1, 0xfc($sp)
/* 053F7C 7F02158C 82020006 */  lb    $v0, 6($s0)
/* 053F80 7F021590 2841002A */  slti  $at, $v0, 0x2a
/* 053F84 7F021594 142000F2 */  bnez  $at, .L7F021960
/* 053F88 7F021598 28410046 */   slti  $at, $v0, 0x46
/* 053F8C 7F02159C 102000F0 */  beqz  $at, .L7F021960
/* 053F90 7F0215A0 3C0F8003 */   lui   $t7, %hi(D_8002CCAC) # $t7, 0x8003
/* 053F94 7F0215A4 25EF81FC */  addiu $t7, %lo(D_8002CCAC) # addiu $t7, $t7, -0x7e04
/* 053F98 7F0215A8 8DE10000 */  lw    $at, ($t7)
/* 053F9C 7F0215AC 27A800F0 */  addiu $t0, $sp, 0xf0
/* 053FA0 7F0215B0 8DE90004 */  lw    $t1, 4($t7)
/* 053FA4 7F0215B4 AD010000 */  sw    $at, ($t0)
/* 053FA8 7F0215B8 8DE10008 */  lw    $at, 8($t7)
/* 053FAC 7F0215BC AD090004 */  sw    $t1, 4($t0)
/* 053FB0 7F0215C0 AD010008 */  sw    $at, 8($t0)
/* 053FB4 7F0215C4 0FC14A59 */  jal   get_hat_model
/* 053FB8 7F0215C8 8E0401D8 */   lw    $a0, 0x1d8($s0)
/* 053FBC 7F0215CC AFA20060 */  sw    $v0, 0x60($sp)
/* 053FC0 7F0215D0 82040006 */  lb    $a0, 6($s0)
/* 053FC4 7F0215D4 00025880 */  sll   $t3, $v0, 2
/* 053FC8 7F0215D8 01625823 */  subu  $t3, $t3, $v0
/* 053FCC 7F0215DC 2484FFD6 */  addiu $a0, $a0, -0x2a
/* 053FD0 7F0215E0 000450C0 */  sll   $t2, $a0, 3
/* 053FD4 7F0215E4 01445021 */  addu  $t2, $t2, $a0
/* 053FD8 7F0215E8 000A5100 */  sll   $t2, $t2, 4
/* 053FDC 7F0215EC 000B58C0 */  sll   $t3, $t3, 3
/* 053FE0 7F0215F0 3C0C8004 */  lui   $t4, %hi(headHat_array_8003E464) # $t4, 0x8004
/* 053FE4 7F0215F4 258C80B4 */  addiu $t4, %lo(headHat_array_8003E464) # addiu $t4, $t4, -0x7f4c
/* 053FE8 7F0215F8 014B6821 */  addu  $t5, $t2, $t3
/* 053FEC 7F0215FC 01AC1821 */  addu  $v1, $t5, $t4
/* 053FF0 7F021600 0FC240F8 */  jal   get_debug_render_raster
/* 053FF4 7F021604 AFA30058 */   sw    $v1, 0x58($sp)
/* 053FF8 7F021608 144000AA */  bnez  $v0, .L7F0218B4
/* 053FFC 7F02160C 8FA30058 */   lw    $v1, 0x58($sp)
/* 054000 7F021610 AFA00054 */  sw    $zero, 0x54($sp)
/* 054004 7F021614 00002025 */  move  $a0, $zero
/* 054008 7F021618 24050020 */  li    $a1, 32
/* 05400C 7F02161C 0C002C20 */  jal   joyGetButtons
/* 054010 7F021620 AFA30058 */   sw    $v1, 0x58($sp)
/* 054014 7F021624 1040004F */  beqz  $v0, .L7F021764
/* 054018 7F021628 8FA30058 */   lw    $v1, 0x58($sp)
/* 05401C 7F02162C 00002025 */  move  $a0, $zero
/* 054020 7F021630 34058000 */  li    $a1, 32768
/* 054024 7F021634 0C002C20 */  jal   joyGetButtons
/* 054028 7F021638 AFA30058 */   sw    $v1, 0x58($sp)
/* 05402C 7F02163C 10400008 */  beqz  $v0, .L7F021660
/* 054030 7F021640 8FA30058 */   lw    $v1, 0x58($sp)
/* 054034 7F021644 3C018004 */  lui   $at, %hi(D_80051D58) # $at, 0x8004
/* 054038 7F021648 C4327E84 */  lwc1  $f18, %lo(D_80051D58)($at)
/* 05403C 7F02164C C4700008 */  lwc1  $f16, 8($v1)
/* 054040 7F021650 24180001 */  li    $t8, 1
/* 054044 7F021654 46128101 */  sub.s $f4, $f16, $f18
/* 054048 7F021658 E4640008 */  swc1  $f4, 8($v1)
/* 05404C 7F02165C AFB80054 */  sw    $t8, 0x54($sp)
.L7F021660:
/* 054050 7F021660 00002025 */  move  $a0, $zero
/* 054054 7F021664 24054000 */  li    $a1, 16384
/* 054058 7F021668 0C002C20 */  jal   joyGetButtons
/* 05405C 7F02166C AFA30058 */   sw    $v1, 0x58($sp)
/* 054060 7F021670 10400008 */  beqz  $v0, .L7F021694
/* 054064 7F021674 8FA30058 */   lw    $v1, 0x58($sp)
/* 054068 7F021678 3C018004 */  lui   $at, %hi(D_80051D5C) # $at, 0x8004
/* 05406C 7F02167C C4287E88 */  lwc1  $f8, %lo(D_80051D5C)($at)
/* 054070 7F021680 C4660008 */  lwc1  $f6, 8($v1)
/* 054074 7F021684 24190001 */  li    $t9, 1
/* 054078 7F021688 46083280 */  add.s $f10, $f6, $f8
/* 05407C 7F02168C E46A0008 */  swc1  $f10, 8($v1)
/* 054080 7F021690 AFB90054 */  sw    $t9, 0x54($sp)
.L7F021694:
/* 054084 7F021694 00002025 */  move  $a0, $zero
/* 054088 7F021698 24050004 */  li    $a1, 4
/* 05408C 7F02169C 0C002C20 */  jal   joyGetButtons
/* 054090 7F0216A0 AFA30058 */   sw    $v1, 0x58($sp)
/* 054094 7F0216A4 10400008 */  beqz  $v0, .L7F0216C8
/* 054098 7F0216A8 8FA30058 */   lw    $v1, 0x58($sp)
/* 05409C 7F0216AC 3C018004 */  lui   $at, %hi(D_80051D60) # $at, 0x8004
/* 0540A0 7F0216B0 C4327E8C */  lwc1  $f18, %lo(D_80051D60)($at)
/* 0540A4 7F0216B4 C4700004 */  lwc1  $f16, 4($v1)
/* 0540A8 7F0216B8 240E0001 */  li    $t6, 1
/* 0540AC 7F0216BC 46128101 */  sub.s $f4, $f16, $f18
/* 0540B0 7F0216C0 E4640004 */  swc1  $f4, 4($v1)
/* 0540B4 7F0216C4 AFAE0054 */  sw    $t6, 0x54($sp)
.L7F0216C8:
/* 0540B8 7F0216C8 00002025 */  move  $a0, $zero
/* 0540BC 7F0216CC 24050008 */  li    $a1, 8
/* 0540C0 7F0216D0 0C002C20 */  jal   joyGetButtons
/* 0540C4 7F0216D4 AFA30058 */   sw    $v1, 0x58($sp)
/* 0540C8 7F0216D8 10400008 */  beqz  $v0, .L7F0216FC
/* 0540CC 7F0216DC 8FA30058 */   lw    $v1, 0x58($sp)
/* 0540D0 7F0216E0 3C018004 */  lui   $at, %hi(D_80051D64) # $at, 0x8004
/* 0540D4 7F0216E4 C4287E90 */  lwc1  $f8, %lo(D_80051D64)($at)
/* 0540D8 7F0216E8 C4660004 */  lwc1  $f6, 4($v1)
/* 0540DC 7F0216EC 24080001 */  li    $t0, 1
/* 0540E0 7F0216F0 46083280 */  add.s $f10, $f6, $f8
/* 0540E4 7F0216F4 E46A0004 */  swc1  $f10, 4($v1)
/* 0540E8 7F0216F8 AFA80054 */  sw    $t0, 0x54($sp)
.L7F0216FC:
/* 0540EC 7F0216FC 00002025 */  move  $a0, $zero
/* 0540F0 7F021700 24050002 */  li    $a1, 2
/* 0540F4 7F021704 0C002C20 */  jal   joyGetButtons
/* 0540F8 7F021708 AFA30058 */   sw    $v1, 0x58($sp)
/* 0540FC 7F02170C 10400008 */  beqz  $v0, .L7F021730
/* 054100 7F021710 8FA30058 */   lw    $v1, 0x58($sp)
/* 054104 7F021714 3C018004 */  lui   $at, %hi(D_80051D68) # $at, 0x8004
/* 054108 7F021718 C4327E94 */  lwc1  $f18, %lo(D_80051D68)($at)
/* 05410C 7F02171C C4700000 */  lwc1  $f16, ($v1)
/* 054110 7F021720 240F0001 */  li    $t7, 1
/* 054114 7F021724 46128101 */  sub.s $f4, $f16, $f18
/* 054118 7F021728 E4640000 */  swc1  $f4, ($v1)
/* 05411C 7F02172C AFAF0054 */  sw    $t7, 0x54($sp)
.L7F021730:
/* 054120 7F021730 00002025 */  move  $a0, $zero
/* 054124 7F021734 24050001 */  li    $a1, 1
/* 054128 7F021738 0C002C20 */  jal   joyGetButtons
/* 05412C 7F02173C AFA30058 */   sw    $v1, 0x58($sp)
/* 054130 7F021740 10400008 */  beqz  $v0, .L7F021764
/* 054134 7F021744 8FA30058 */   lw    $v1, 0x58($sp)
/* 054138 7F021748 3C018004 */  lui   $at, %hi(D_80051D6C) # $at, 0x8004
/* 05413C 7F02174C C4287E98 */  lwc1  $f8, %lo(D_80051D6C)($at)
/* 054140 7F021750 C4660000 */  lwc1  $f6, ($v1)
/* 054144 7F021754 24090001 */  li    $t1, 1
/* 054148 7F021758 46083280 */  add.s $f10, $f6, $f8
/* 05414C 7F02175C E46A0000 */  swc1  $f10, ($v1)
/* 054150 7F021760 AFA90054 */  sw    $t1, 0x54($sp)
.L7F021764:
/* 054154 7F021764 00002025 */  move  $a0, $zero
/* 054158 7F021768 24050010 */  li    $a1, 16
/* 05415C 7F02176C 0C002C20 */  jal   joyGetButtons
/* 054160 7F021770 AFA30058 */   sw    $v1, 0x58($sp)
/* 054164 7F021774 1040004F */  beqz  $v0, .L7F0218B4
/* 054168 7F021778 8FA30058 */   lw    $v1, 0x58($sp)
/* 05416C 7F02177C 00002025 */  move  $a0, $zero
/* 054170 7F021780 34058000 */  li    $a1, 32768
/* 054174 7F021784 0C002C20 */  jal   joyGetButtons
/* 054178 7F021788 AFA30058 */   sw    $v1, 0x58($sp)
/* 05417C 7F02178C 10400008 */  beqz  $v0, .L7F0217B0
/* 054180 7F021790 8FA30058 */   lw    $v1, 0x58($sp)
/* 054184 7F021794 3C018004 */  lui   $at, %hi(D_80051D70) # $at, 0x8004
/* 054188 7F021798 C4327E9C */  lwc1  $f18, %lo(D_80051D70)($at)
/* 05418C 7F02179C C4700014 */  lwc1  $f16, 0x14($v1)
/* 054190 7F0217A0 240A0001 */  li    $t2, 1
/* 054194 7F0217A4 46128102 */  mul.s $f4, $f16, $f18
/* 054198 7F0217A8 E4640014 */  swc1  $f4, 0x14($v1)
/* 05419C 7F0217AC AFAA0054 */  sw    $t2, 0x54($sp)
.L7F0217B0:
/* 0541A0 7F0217B0 00002025 */  move  $a0, $zero
/* 0541A4 7F0217B4 24054000 */  li    $a1, 16384
/* 0541A8 7F0217B8 0C002C20 */  jal   joyGetButtons
/* 0541AC 7F0217BC AFA30058 */   sw    $v1, 0x58($sp)
/* 0541B0 7F0217C0 10400008 */  beqz  $v0, .L7F0217E4
/* 0541B4 7F0217C4 8FA30058 */   lw    $v1, 0x58($sp)
/* 0541B8 7F0217C8 3C018004 */  lui   $at, %hi(D_80051D74) # $at, 0x8004
/* 0541BC 7F0217CC C4287EA0 */  lwc1  $f8, %lo(D_80051D74)($at)
/* 0541C0 7F0217D0 C4660014 */  lwc1  $f6, 0x14($v1)
/* 0541C4 7F0217D4 240B0001 */  li    $t3, 1
/* 0541C8 7F0217D8 46083282 */  mul.s $f10, $f6, $f8
/* 0541CC 7F0217DC E46A0014 */  swc1  $f10, 0x14($v1)
/* 0541D0 7F0217E0 AFAB0054 */  sw    $t3, 0x54($sp)
.L7F0217E4:
/* 0541D4 7F0217E4 00002025 */  move  $a0, $zero
/* 0541D8 7F0217E8 24050004 */  li    $a1, 4
/* 0541DC 7F0217EC 0C002C20 */  jal   joyGetButtons
/* 0541E0 7F0217F0 AFA30058 */   sw    $v1, 0x58($sp)
/* 0541E4 7F0217F4 10400008 */  beqz  $v0, .L7F021818
/* 0541E8 7F0217F8 8FA30058 */   lw    $v1, 0x58($sp)
/* 0541EC 7F0217FC 3C018004 */  lui   $at, %hi(D_80051D78) # $at, 0x8004
/* 0541F0 7F021800 C4327EA4 */  lwc1  $f18, %lo(D_80051D78)($at)
/* 0541F4 7F021804 C4700010 */  lwc1  $f16, 0x10($v1)
/* 0541F8 7F021808 240D0001 */  li    $t5, 1
/* 0541FC 7F02180C 46128102 */  mul.s $f4, $f16, $f18
/* 054200 7F021810 E4640010 */  swc1  $f4, 0x10($v1)
/* 054204 7F021814 AFAD0054 */  sw    $t5, 0x54($sp)
.L7F021818:
/* 054208 7F021818 00002025 */  move  $a0, $zero
/* 05420C 7F02181C 24050008 */  li    $a1, 8
/* 054210 7F021820 0C002C20 */  jal   joyGetButtons
/* 054214 7F021824 AFA30058 */   sw    $v1, 0x58($sp)
/* 054218 7F021828 10400008 */  beqz  $v0, .L7F02184C
/* 05421C 7F02182C 8FA30058 */   lw    $v1, 0x58($sp)
/* 054220 7F021830 3C018004 */  lui   $at, %hi(D_80051D7C) # $at, 0x8004
/* 054224 7F021834 C4287EA8 */  lwc1  $f8, %lo(D_80051D7C)($at)
/* 054228 7F021838 C4660010 */  lwc1  $f6, 0x10($v1)
/* 05422C 7F02183C 240C0001 */  li    $t4, 1
/* 054230 7F021840 46083282 */  mul.s $f10, $f6, $f8
/* 054234 7F021844 E46A0010 */  swc1  $f10, 0x10($v1)
/* 054238 7F021848 AFAC0054 */  sw    $t4, 0x54($sp)
.L7F02184C:
/* 05423C 7F02184C 00002025 */  move  $a0, $zero
/* 054240 7F021850 24050002 */  li    $a1, 2
/* 054244 7F021854 0C002C20 */  jal   joyGetButtons
/* 054248 7F021858 AFA30058 */   sw    $v1, 0x58($sp)
/* 05424C 7F02185C 10400008 */  beqz  $v0, .L7F021880
/* 054250 7F021860 8FA30058 */   lw    $v1, 0x58($sp)
/* 054254 7F021864 3C018004 */  lui   $at, %hi(D_80051D80) # $at, 0x8004
/* 054258 7F021868 C4327EAC */  lwc1  $f18, %lo(D_80051D80)($at)
/* 05425C 7F02186C C470000C */  lwc1  $f16, 0xc($v1)
/* 054260 7F021870 24180001 */  li    $t8, 1
/* 054264 7F021874 46128102 */  mul.s $f4, $f16, $f18
/* 054268 7F021878 E464000C */  swc1  $f4, 0xc($v1)
/* 05426C 7F02187C AFB80054 */  sw    $t8, 0x54($sp)
.L7F021880:
/* 054270 7F021880 00002025 */  move  $a0, $zero
/* 054274 7F021884 24050001 */  li    $a1, 1
/* 054278 7F021888 0C002C20 */  jal   joyGetButtons
/* 05427C 7F02188C AFA30058 */   sw    $v1, 0x58($sp)
/* 054280 7F021890 10400008 */  beqz  $v0, .L7F0218B4
/* 054284 7F021894 8FA30058 */   lw    $v1, 0x58($sp)
/* 054288 7F021898 3C018004 */  lui   $at, %hi(D_80051D84) # $at, 0x8004
/* 05428C 7F02189C C4287EB0 */  lwc1  $f8, %lo(D_80051D84)($at)
/* 054290 7F0218A0 C466000C */  lwc1  $f6, 0xc($v1)
/* 054294 7F0218A4 24190001 */  li    $t9, 1
/* 054298 7F0218A8 46083282 */  mul.s $f10, $f6, $f8
/* 05429C 7F0218AC E46A000C */  swc1  $f10, 0xc($v1)
/* 0542A0 7F0218B0 AFB90054 */  sw    $t9, 0x54($sp)
.L7F0218B4:
/* 0542A4 7F0218B4 3C018004 */  lui   $at, %hi(D_80051D88) # $at, 0x8004
/* 0542A8 7F0218B8 C4207EB4 */  lwc1  $f0, %lo(D_80051D88)($at)
/* 0542AC 7F0218BC C4700000 */  lwc1  $f16, ($v1)
/* 0542B0 7F0218C0 27A400F0 */  addiu $a0, $sp, 0xf0
/* 0542B4 7F0218C4 27A500A4 */  addiu $a1, $sp, 0xa4
/* 0542B8 7F0218C8 46008482 */  mul.s $f18, $f16, $f0
/* 0542BC 7F0218CC E7B200F0 */  swc1  $f18, 0xf0($sp)
/* 0542C0 7F0218D0 C4640004 */  lwc1  $f4, 4($v1)
/* 0542C4 7F0218D4 46002182 */  mul.s $f6, $f4, $f0
/* 0542C8 7F0218D8 E7A600F4 */  swc1  $f6, 0xf4($sp)
/* 0542CC 7F0218DC C4680008 */  lwc1  $f8, 8($v1)
/* 0542D0 7F0218E0 46004282 */  mul.s $f10, $f8, $f0
/* 0542D4 7F0218E4 E7AA00F8 */  swc1  $f10, 0xf8($sp)
/* 0542D8 7F0218E8 C470000C */  lwc1  $f16, 0xc($v1)
/* 0542DC 7F0218EC E7B000EC */  swc1  $f16, 0xec($sp)
/* 0542E0 7F0218F0 C4720010 */  lwc1  $f18, 0x10($v1)
/* 0542E4 7F0218F4 E7B200E8 */  swc1  $f18, 0xe8($sp)
/* 0542E8 7F0218F8 C4640014 */  lwc1  $f4, 0x14($v1)
/* 0542EC 7F0218FC 0FC16383 */  jal   matrix_4x4_set_identity_and_position
/* 0542F0 7F021900 E7A400E4 */   swc1  $f4, 0xe4($sp)
/* 0542F4 7F021904 C7AC00EC */  lwc1  $f12, 0xec($sp)
/* 0542F8 7F021908 0FC16397 */  jal   matrix_column_1_scalar_multiply
/* 0542FC 7F02190C 27A500A4 */   addiu $a1, $sp, 0xa4
/* 054300 7F021910 C7AC00E8 */  lwc1  $f12, 0xe8($sp)
/* 054304 7F021914 0FC163A3 */  jal   matrix_column_2_scalar_multiply
/* 054308 7F021918 27A500A4 */   addiu $a1, $sp, 0xa4
/* 05430C 7F02191C C7AC00E4 */  lwc1  $f12, 0xe4($sp)
/* 054310 7F021920 0FC163BD */  jal   matrix_column_3_scalar_multiply_2
/* 054314 7F021924 27A500A4 */   addiu $a1, $sp, 0xa4
/* 054318 7F021928 8FAE00FC */  lw    $t6, 0xfc($sp)
/* 05431C 7F02192C 27A500A4 */  addiu $a1, $sp, 0xa4
/* 054320 7F021930 27A60064 */  addiu $a2, $sp, 0x64
/* 054324 7F021934 0FC1618D */  jal   matrix_4x4_multiply_homogeneous
/* 054328 7F021938 8DC4000C */   lw    $a0, 0xc($t6)
/* 05432C 7F02193C 8FA800FC */  lw    $t0, 0xfc($sp)
/* 054330 7F021940 27A40064 */  addiu $a0, $sp, 0x64
/* 054334 7F021944 0FC16132 */  jal   matrix_4x4_copy
/* 054338 7F021948 8D05000C */   lw    $a1, 0xc($t0)
/* 05433C 7F02194C 8FAF0060 */  lw    $t7, 0x60($sp)
/* 054340 7F021950 24010002 */  li    $at, 2
/* 054344 7F021954 55E10003 */  bnel  $t7, $at, .L7F021964
/* 054348 7F021958 96090012 */   lhu   $t1, 0x12($s0)
/* 05434C 7F02195C AFA00108 */  sw    $zero, 0x108($sp)
.L7F021960:
/* 054350 7F021960 96090012 */  lhu   $t1, 0x12($s0)
.L7F021964:
/* 054354 7F021964 8FAB0100 */  lw    $t3, 0x100($sp)
/* 054358 7F021968 8FA500FC */  lw    $a1, 0xfc($sp)
/* 05435C 7F02196C 312A0001 */  andi  $t2, $t1, 1
/* 054360 7F021970 11400005 */  beqz  $t2, .L7F021988
/* 054364 7F021974 00000000 */   nop   
/* 054368 7F021978 8D6D0064 */  lw    $t5, 0x64($t3)
/* 05436C 7F02197C 31AC0080 */  andi  $t4, $t5, 0x80
/* 054370 7F021980 55800005 */  bnezl $t4, .L7F021998
/* 054374 7F021984 8FB80110 */   lw    $t8, 0x110($sp)
.L7F021988:
/* 054378 7F021988 0FC1AE34 */  jal   sub_GAME_7F06B120
/* 05437C 7F02198C 8E040020 */   lw    $a0, 0x20($s0)
/* 054380 7F021990 AE020020 */  sw    $v0, 0x20($s0)
/* 054384 7F021994 8FB80110 */  lw    $t8, 0x110($sp)
.L7F021998:
/* 054388 7F021998 8F190008 */  lw    $t9, 8($t8)
/* 05438C 7F02199C 8F2E0008 */  lw    $t6, 8($t9)
/* 054390 7F0219A0 8DC50010 */  lw    $a1, 0x10($t6)
/* 054394 7F0219A4 10A0000E */  beqz  $a1, .L7F0219E0
/* 054398 7F0219A8 00000000 */   nop   
/* 05439C 7F0219AC 0FC1B3A3 */  jal   extract_id_from_object_structure_microcode
/* 0543A0 7F0219B0 03002025 */   move  $a0, $t8
/* 0543A4 7F0219B4 8C430000 */  lw    $v1, ($v0)
/* 0543A8 7F0219B8 10600009 */  beqz  $v1, .L7F0219E0
/* 0543AC 7F0219BC 00000000 */   nop   
/* 0543B0 7F0219C0 8C680008 */  lw    $t0, 8($v1)
/* 0543B4 7F0219C4 8D050004 */  lw    $a1, 4($t0)
/* 0543B8 7F0219C8 10A00005 */  beqz  $a1, .L7F0219E0
/* 0543BC 7F0219CC 00000000 */   nop   
/* 0543C0 7F0219D0 0FC1B3A3 */  jal   extract_id_from_object_structure_microcode
/* 0543C4 7F0219D4 8FA40110 */   lw    $a0, 0x110($sp)
/* 0543C8 7F0219D8 8FAF0108 */  lw    $t7, 0x108($sp)
/* 0543CC 7F0219DC AC4F0000 */  sw    $t7, ($v0)
.L7F0219E0:
/* 0543D0 7F0219E0 0FC1AE93 */  jal   sub_GAME_7F06B29C
/* 0543D4 7F0219E4 8E040020 */   lw    $a0, 0x20($s0)
/* 0543D8 7F0219E8 0FC1B0B6 */  jal   sub_GAME_7F06BB28
/* 0543DC 7F0219EC 8E040020 */   lw    $a0, 0x20($s0)
/* 0543E0 7F0219F0 10000020 */  b     .L7F021A74
/* 0543E4 7F0219F4 AE020020 */   sw    $v0, 0x20($s0)
/* 0543E8 7F0219F8 8E020160 */  lw    $v0, 0x160($s0)
.L7F0219FC:
/* 0543EC 7F0219FC 50400005 */  beql  $v0, $zero, .L7F021A14
/* 0543F0 7F021A00 8E020164 */   lw    $v0, 0x164($s0)
/* 0543F4 7F021A04 90490001 */  lbu   $t1, 1($v0)
/* 0543F8 7F021A08 312AFFFD */  andi  $t2, $t1, 0xfffd
/* 0543FC 7F021A0C A04A0001 */  sb    $t2, 1($v0)
/* 054400 7F021A10 8E020164 */  lw    $v0, 0x164($s0)
.L7F021A14:
/* 054404 7F021A14 2403FFFD */  li    $v1, -3
/* 054408 7F021A18 50400005 */  beql  $v0, $zero, .L7F021A30
/* 05440C 7F021A1C 8E0201D8 */   lw    $v0, 0x1d8($s0)
/* 054410 7F021A20 904B0001 */  lbu   $t3, 1($v0)
/* 054414 7F021A24 01636824 */  and   $t5, $t3, $v1
/* 054418 7F021A28 A04D0001 */  sb    $t5, 1($v0)
/* 05441C 7F021A2C 8E0201D8 */  lw    $v0, 0x1d8($s0)
.L7F021A30:
/* 054420 7F021A30 50400005 */  beql  $v0, $zero, .L7F021A48
/* 054424 7F021A34 8FAE0158 */   lw    $t6, 0x158($sp)
/* 054428 7F021A38 904C0001 */  lbu   $t4, 1($v0)
/* 05442C 7F021A3C 0183C824 */  and   $t9, $t4, $v1
/* 054430 7F021A40 A0590001 */  sb    $t9, 1($v0)
/* 054434 7F021A44 8FAE0158 */  lw    $t6, 0x158($sp)
.L7F021A48:
/* 054438 7F021A48 91D80001 */  lbu   $t8, 1($t6)
/* 05443C 7F021A4C 03034024 */  and   $t0, $t8, $v1
/* 054440 7F021A50 A1C80001 */  sb    $t0, 1($t6)
/* 054444 7F021A54 920F00F8 */  lbu   $t7, 0xf8($s0)
/* 054448 7F021A58 920900F9 */  lbu   $t1, 0xf9($s0)
/* 05444C 7F021A5C 920A00FA */  lbu   $t2, 0xfa($s0)
/* 054450 7F021A60 920B00FB */  lbu   $t3, 0xfb($s0)
/* 054454 7F021A64 A20F00F4 */  sb    $t7, 0xf4($s0)
/* 054458 7F021A68 A20900F5 */  sb    $t1, 0xf5($s0)
/* 05445C 7F021A6C A20A00F6 */  sb    $t2, 0xf6($s0)
/* 054460 7F021A70 A20B00F7 */  sb    $t3, 0xf7($s0)
.L7F021A74:
/* 054464 7F021A74 8E0D0014 */  lw    $t5, 0x14($s0)
/* 054468 7F021A78 31AC0400 */  andi  $t4, $t5, 0x400
/* 05446C 7F021A7C 55800015 */  bnezl $t4, .L7F021AD4
/* 054470 7F021A80 00001025 */   move  $v0, $zero
/* 054474 7F021A84 96020012 */  lhu   $v0, 0x12($s0)
/* 054478 7F021A88 8FB80158 */  lw    $t8, 0x158($sp)
/* 05447C 7F021A8C 30590001 */  andi  $t9, $v0, 1
/* 054480 7F021A90 1320000D */  beqz  $t9, .L7F021AC8
/* 054484 7F021A94 00000000 */   nop   
/* 054488 7F021A98 8F040020 */  lw    $a0, 0x20($t8)
/* 05448C 7F021A9C 50800009 */  beql  $a0, $zero, .L7F021AC4
/* 054490 7F021AA0 3048FFFE */   andi  $t0, $v0, 0xfffe
/* 054494 7F021AA4 8C830024 */  lw    $v1, 0x24($a0)
.L7F021AA8:
/* 054498 7F021AA8 0FC130C9 */  jal   sub_GAME_7F04C130
/* 05449C 7F021AAC AFA3003C */   sw    $v1, 0x3c($sp)
/* 0544A0 7F021AB0 8FA4003C */  lw    $a0, 0x3c($sp)
/* 0544A4 7F021AB4 5480FFFC */  bnezl $a0, .L7F021AA8
/* 0544A8 7F021AB8 8C830024 */   lw    $v1, 0x24($a0)
/* 0544AC 7F021ABC 96020012 */  lhu   $v0, 0x12($s0)
/* 0544B0 7F021AC0 3048FFFE */  andi  $t0, $v0, 0xfffe
.L7F021AC4:
/* 0544B4 7F021AC4 A6080012 */  sh    $t0, 0x12($s0)
.L7F021AC8:
/* 0544B8 7F021AC8 0FC0B8A8 */  jal   chrlvTriggerFireWeapon
/* 0544BC 7F021ACC 02002025 */   move  $a0, $s0
/* 0544C0 7F021AD0 00001025 */  move  $v0, $zero
.L7F021AD4:
/* 0544C4 7F021AD4 8FBF0024 */  lw    $ra, 0x24($sp)
/* 0544C8 7F021AD8 8FB00020 */  lw    $s0, 0x20($sp)
/* 0544CC 7F021ADC 27BD0158 */  addiu $sp, $sp, 0x158
/* 0544D0 7F021AE0 03E00008 */  jr    $ra
/* 0544D4 7F021AE4 00000000 */   nop   

)
#endif

#endif


/**
 * Address 0x7F021B20.
 */
void chrDropItems(ChrRecord *self) 
{
    PropRecord *childprop = self->prop->child;
    while (childprop)
    {
        if ((childprop != self->handle_positiondata_hat) &&
            (childprop != self->weapons_held[GUNLEFT]) &&
            (childprop != self->weapons_held[GUNRIGHT]))
        {
            WeaponObjRecord *wep = childprop->weapon;
            if (!(wep->flags & 0x2000))
            {
                propobjSetDropped(childprop, 1);
            }
        }
        childprop = childprop->prev;
    };

    self->hidden |= 1;
}



/**
 * Unreferenced.
 * 
 * Sets D_8002CCB8 3 bytes from paramter.
 * 
 * @param arg0: u8[3].
 * 
 * Address 0x7F021BB4.
 */
void chrSetD_8002CCB8(rgba_u8 *arg0)
{
    D_8002CCB8.r = arg0->r;
    D_8002CCB8.g = arg0->g;
    D_8002CCB8.b = arg0->b;
}


/**
 * Unreferenced.
 * 
 * Gets D_8002CCB8 3 bytes and sets them into parameter.
 * 
 * @param arg0: u8[3].
 * 
 * Address 0x7F021BD8.
 */
void chrGetD_8002CCB8(rgba_u8 *arg0)
{
    arg0->r = D_8002CCB8.r;
    arg0->g = D_8002CCB8.g;
    arg0->b = D_8002CCB8.b;
}



/**
 * Address 0x7F021BFC.
*/
Gfx *chrRenderProp(PropRecord *prop, Gfx *gdl, s32 withalpha)
{
    ChrRecord *chr;
    Model *chrmodel;
    struct rgba_f32 spC0; // 192
    s32 spBC; // 188
    s32 spB8; // 184
    s32 spB4; // 180
    rgba_u8 temp_v1_2;
    struct unk_joint_list jlist; // 112
    struct view4f sp60; // -?? 96
    struct rgba_s32 sp50;
    s32 sp4C; // 76
    PropRecord *prop_held_right; // 72
    PropRecord *prop_held_left; // 68
    PropRecord *prop_held_hat; // 64
    ObjectRecord *held_right_obj; // 60
    ObjectRecord *held_left_obj; // 56
    ObjectRecord *held_hat_obj; // 52

    //

    chr = prop->chr;
    chrmodel = chr->model;
    spB4 = (s32) chr->fadealpha;

    if ((chr->chrflags << 5) >= 0) //CHRFLAG_04000000
    {
        f32 f = chrobjFogVisRangeRelated(prop, getinstsize(chrmodel));
        spB4 = (s32) (f * (f32) spB4);
    }

    if ((spB4 < 0xFF) || (chr->chrflags & CHRFLAG_00020000))
    {
        if (withalpha == 0)
        {
            // nothing to do
            return gdl;
        }
        else
        {
            spB8 = 3;
        }
    }
    else
    {
        if (withalpha == 0)
        {
            spB8 = 1;
        }
        else
        {
            spB8 = 2;
        }
    }

    spBC = fogGetPropDistColor(prop, &spC0);
    if (spBC != 0)
    {
        if (spB4 > 0)
        {
            jlist = D_8002CCBC;

            sp4C = 0x50;

            prop_held_right = chr->weapons_held[GUNRIGHT];
            prop_held_left = chr->weapons_held[GUNLEFT];
            prop_held_hat = chr->handle_positiondata_hat;
            held_right_obj = NULL;
            held_left_obj = NULL;
            held_hat_obj = NULL;

            if (prop_held_right != NULL)
            {
                held_right_obj = prop_held_right->obj;
            }

            if (prop_held_left != NULL)
            {
                held_left_obj = prop_held_left->obj;
            }

            if (prop_held_hat != NULL)
            {
                held_hat_obj = prop_held_hat->obj;
            }

            if ((sub_GAME_7F054A64(prop, &sp60) > 0) && ((chr->chrflags << 8) >= 0))//CHRFLAG_CULL_USING_HITBOX
            {
                gdl = bgScissorCurrentPlayerViewF(gdl, sp60.left, sp60.top, sp60.width, sp60.height);
            }
            else
            {
                gdl = bgScissorCurrentPlayerViewDefault(gdl);
            }
            
            jlist.unk08 = spB8;
            jlist.unk04 = 1;
            jlist.gdl = gdl;
            
            if ((chr->chrflags & CHRFLAG_NO_SHADOW) != 0)
            {
                sp4C = 0;
            }
            else if (spBC == 1)
            {
                sp4C = ((1.0f - spC0.a) * (f32)(sp4C));
            }

            sub_GAME_7F073FC8(sp4C);

            sp50.r = chr->shadecol.r;
            sp50.g = chr->shadecol.g;
            sp50.b = chr->shadecol.b;
            sp50.a = chr->shadecol.a;

            sub_GAME_7F040384(&sp50, spBC, &spC0);

            jlist.unk34 = ((D_8002CCB8.rgba[0] << 0x18) | (D_8002CCB8.rgba[1] << 0x10)) | (D_8002CCB8.rgba[2] << 0x08);
            jlist.unk38.word = (sp50.rgba[0] << 0x18) | (sp50.rgba[1] << 0x10) | (sp50.rgba[2] << 0x08) | (sp50.rgba[3] << 0x00);

            if (spB4 < 0xFF)
            {
                jlist.unk30 = 8;
                jlist.unk34 |= (u8)spB4;
            }
            else
            {
                jlist.unk30 = 7;
            }

            g_playerPerm->time_other_players_on_screen += 1;
            drawjointlist(&jlist, chr->field_20);

            gdl = jlist.gdl;

            if ((held_right_obj != NULL) && (( held_right_obj->state & ((u8)(1 << withalpha) )) ))
            {
                gdl = explosionRenderBulletImpactOnProp(gdl, prop_held_right, withalpha);
            }

            if ((held_left_obj != NULL) && (( held_left_obj->state & ((u8)(1 << withalpha) )) ))
            {
                gdl = explosionRenderBulletImpactOnProp(gdl, prop_held_left, withalpha);
            }

            if ((held_hat_obj != NULL) && (( held_hat_obj->state & ((u8)(1 << withalpha) )) ))
            {
                gdl = explosionRenderBulletImpactOnProp(gdl, prop_held_hat, withalpha);
            }

            if (withalpha != 0)
            {
                bondviewTransformManyPosToViewMatrix(chr->model->render_pos, chr->model->obj->numMatrices);

                if ((held_right_obj != NULL) && ((held_right_obj->runtime_bitflags & 0x800) == 0))
                {
                    bondviewTransformManyPosToViewMatrix(held_right_obj->model->render_pos, held_right_obj->model->obj->numMatrices);
                }

                if ((held_left_obj != NULL) && ((held_left_obj->runtime_bitflags & 0x800) == 0))
                {
                    bondviewTransformManyPosToViewMatrix(held_left_obj->model->render_pos, held_left_obj->model->obj->numMatrices);
                }

                if (held_hat_obj != NULL)
                {
                    bondviewTransformManyPosToViewMatrix(held_hat_obj->model->render_pos, held_hat_obj->model->obj->numMatrices);
                }
            }
        }
    }

    if (withalpha != 0)
    {
        sub_GAME_7F06B248(chr->field_20);
        chr->field_20 = NULL;
    }

    return gdl;
}


#ifdef NONMATCHING
void sub_GAME_7F022078(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F022078
/* 056BA8 7F022078 3C0B8003 */  lui   $t3, %hi(D_8002C914) 
/* 056BAC 7F02207C 256BC914 */  addiu $t3, %lo(D_8002C914) # addiu $t3, $t3, -0x36ec
/* 056BB0 7F022080 8D6E0000 */  lw    $t6, ($t3)
/* 056BB4 7F022084 27BDFFB0 */  addiu $sp, $sp, -0x50
/* 056BB8 7F022088 2409FFFF */  li    $t1, -1
/* 056BBC 7F02208C AFBF001C */  sw    $ra, 0x1c($sp)
/* 056BC0 7F022090 AFB00018 */  sw    $s0, 0x18($sp)
/* 056BC4 7F022094 AFA40050 */  sw    $a0, 0x50($sp)
/* 056BC8 7F022098 AFA7005C */  sw    $a3, 0x5c($sp)
/* 056BCC 7F02209C 00005025 */  move  $t2, $zero
/* 056BD0 7F0220A0 112E000D */  beq   $t1, $t6, .L7F0220D8
/* 056BD4 7F0220A4 00004025 */   move  $t0, $zero
/* 056BD8 7F0220A8 3C0F8003 */  lui   $t7, %hi(D_8002C914)
/* 056BDC 7F0220AC 25E2C914 */  addiu $v0, $t7, %lo(D_8002C914)
/* 056BE0 7F0220B0 8C430000 */  lw    $v1, ($v0)
.L7F0220B4:
/* 056BE4 7F0220B4 54A30004 */  bnel  $a1, $v1, .L7F0220C8
/* 056BE8 7F0220B8 8C43002C */   lw    $v1, 0x2c($v0)
/* 056BEC 7F0220BC 10000006 */  b     .L7F0220D8
/* 056BF0 7F0220C0 01005025 */   move  $t2, $t0
/* 056BF4 7F0220C4 8C43002C */  lw    $v1, 0x2c($v0)
.L7F0220C8:
/* 056BF8 7F0220C8 25080001 */  addiu $t0, $t0, 1
/* 056BFC 7F0220CC 2442002C */  addiu $v0, $v0, 0x2c
/* 056C00 7F0220D0 1523FFF8 */  bne   $t1, $v1, .L7F0220B4
/* 056C04 7F0220D4 00000000 */   nop   
.L7F0220D8:
/* 056C08 7F0220D8 000AC080 */  sll   $t8, $t2, 2
/* 056C0C 7F0220DC 030AC023 */  subu  $t8, $t8, $t2
/* 056C10 7F0220E0 0018C080 */  sll   $t8, $t8, 2
/* 056C14 7F0220E4 030AC023 */  subu  $t8, $t8, $t2
/* 056C18 7F0220E8 0018C080 */  sll   $t8, $t8, 2
/* 056C1C 7F0220EC 01788021 */  addu  $s0, $t3, $t8
/* 056C20 7F0220F0 8E190010 */  lw    $t9, 0x10($s0)
/* 056C24 7F0220F4 5320002C */  beql  $t9, $zero, .L7F0221A8
/* 056C28 7F0220F8 8E050004 */   lw    $a1, 4($s0)
/* 056C2C 7F0220FC 0C002914 */  jal   randomGetNext
/* 056C30 7F022100 AFA60058 */   sw    $a2, 0x58($sp)
/* 056C34 7F022104 304C0004 */  andi  $t4, $v0, 4
/* 056C38 7F022108 15800026 */  bnez  $t4, .L7F0221A4
/* 056C3C 7F02210C 8FA60058 */   lw    $a2, 0x58($sp)
/* 056C40 7F022110 C4C20000 */  lwc1  $f2, ($a2)
/* 056C44 7F022114 C4CE0004 */  lwc1  $f14, 4($a2)
/* 056C48 7F022118 C4C00008 */  lwc1  $f0, 8($a2)
/* 056C4C 7F02211C 46021102 */  mul.s $f4, $f2, $f2
/* 056C50 7F022120 AFA60058 */  sw    $a2, 0x58($sp)
/* 056C54 7F022124 460E7182 */  mul.s $f6, $f14, $f14
/* 056C58 7F022128 46062200 */  add.s $f8, $f4, $f6
/* 056C5C 7F02212C 46000282 */  mul.s $f10, $f0, $f0
/* 056C60 7F022130 0C007DF8 */  jal   sqrtf
/* 056C64 7F022134 46085300 */   add.s $f12, $f10, $f8
/* 056C68 7F022138 3C014228 */  li    $at, 0x42280000 # 42.000000
/* 056C6C 7F02213C 44818000 */  mtc1  $at, $f16
/* 056C70 7F022140 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 056C74 7F022144 44812000 */  mtc1  $at, $f4
/* 056C78 7F022148 46008483 */  div.s $f18, $f16, $f0
/* 056C7C 7F02214C 8FA60058 */  lw    $a2, 0x58($sp)
/* 056C80 7F022150 C4C60000 */  lwc1  $f6, ($a2)
/* 056C84 7F022154 46049080 */  add.s $f2, $f18, $f4
/* 056C88 7F022158 46023282 */  mul.s $f10, $f6, $f2
/* 056C8C 7F02215C E7AA003C */  swc1  $f10, 0x3c($sp)
/* 056C90 7F022160 C4C80004 */  lwc1  $f8, 4($a2)
/* 056C94 7F022164 46024402 */  mul.s $f16, $f8, $f2
/* 056C98 7F022168 E7B00040 */  swc1  $f16, 0x40($sp)
/* 056C9C 7F02216C C4D20008 */  lwc1  $f18, 8($a2)
/* 056CA0 7F022170 46029102 */  mul.s $f4, $f18, $f2
/* 056CA4 7F022174 0FC1E111 */  jal   currentPlayerGetMatrix10D4
/* 056CA8 7F022178 E7A40044 */   swc1  $f4, 0x44($sp)
/* 056CAC 7F02217C 00402025 */  move  $a0, $v0
/* 056CB0 7F022180 0FC1611D */  jal   matrix_4x4_transform_vector_in_place
/* 056CB4 7F022184 27A5003C */   addiu $a1, $sp, 0x3c
/* 056CB8 7F022188 8FAD0050 */  lw    $t5, 0x50($sp)
/* 056CBC 7F02218C 27A4003C */  addiu $a0, $sp, 0x3c
/* 056CC0 7F022190 8E050010 */  lw    $a1, 0x10($s0)
/* 056CC4 7F022194 8DAE0014 */  lw    $t6, 0x14($t5)
/* 056CC8 7F022198 8E060018 */  lw    $a2, 0x18($s0)
/* 056CCC 7F02219C 0FC28F87 */  jal   sub_GAME_7F0A3E1C
/* 056CD0 7F0221A0 91C70003 */   lbu   $a3, 3($t6)
.L7F0221A4:
/* 056CD4 7F0221A4 8E050004 */  lw    $a1, 4($s0)
.L7F0221A8:
/* 056CD8 7F0221A8 8FAF0050 */  lw    $t7, 0x50($sp)
/* 056CDC 7F0221AC 50A00007 */  beql  $a1, $zero, .L7F0221CC
/* 056CE0 7F0221B0 8FBF001C */   lw    $ra, 0x1c($sp)
/* 056CE4 7F0221B4 8DF80014 */  lw    $t8, 0x14($t7)
/* 056CE8 7F0221B8 8FA4005C */  lw    $a0, 0x5c($sp)
/* 056CEC 7F0221BC 8E06000C */  lw    $a2, 0xc($s0)
/* 056CF0 7F0221C0 0FC28F87 */  jal   sub_GAME_7F0A3E1C
/* 056CF4 7F0221C4 93070003 */   lbu   $a3, 3($t8)
/* 056CF8 7F0221C8 8FBF001C */  lw    $ra, 0x1c($sp)
.L7F0221CC:
/* 056CFC 7F0221CC 8FB00018 */  lw    $s0, 0x18($sp)
/* 056D00 7F0221D0 27BD0050 */  addiu $sp, $sp, 0x50
/* 056D04 7F0221D4 03E00008 */  jr    $ra
/* 056D08 7F0221D8 00000000 */   nop   
)
#endif



#ifdef NONMATCHING
void sub_GAME_7F0221DC(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0221DC
/* 056D0C 7F0221DC 27BDFF50 */  addiu $sp, $sp, -0xb0
/* 056D10 7F0221E0 AFBF0034 */  sw    $ra, 0x34($sp)
/* 056D14 7F0221E4 AFB60030 */  sw    $s6, 0x30($sp)
/* 056D18 7F0221E8 AFB5002C */  sw    $s5, 0x2c($sp)
/* 056D1C 7F0221EC AFB40028 */  sw    $s4, 0x28($sp)
/* 056D20 7F0221F0 AFB30024 */  sw    $s3, 0x24($sp)
/* 056D24 7F0221F4 AFB20020 */  sw    $s2, 0x20($sp)
/* 056D28 7F0221F8 AFB1001C */  sw    $s1, 0x1c($sp)
/* 056D2C 7F0221FC AFB00018 */  sw    $s0, 0x18($sp)
/* 056D30 7F022200 AFA500B4 */  sw    $a1, 0xb4($sp)
/* 056D34 7F022204 C4E40000 */  lwc1  $f4, ($a3)
/* 056D38 7F022208 3C117FFF */  lui   $s1, (0x7FFFFFFF >> 16) # lui $s1, 0x7fff
/* 056D3C 7F02220C 00C09025 */  move  $s2, $a2
/* 056D40 7F022210 4600218D */  trunc.w.s $f6, $f4
/* 056D44 7F022214 0080B025 */  move  $s6, $a0
/* 056D48 7F022218 0000A025 */  move  $s4, $zero
/* 056D4C 7F02221C 0000A825 */  move  $s5, $zero
/* 056D50 7F022220 440F3000 */  mfc1  $t7, $f6
/* 056D54 7F022224 3631FFFF */  ori   $s1, (0x7FFFFFFF & 0xFFFF) # ori $s1, $s1, 0xffff
/* 056D58 7F022228 00C08025 */  move  $s0, $a2
/* 056D5C 7F02222C AFAF00A4 */  sw    $t7, 0xa4($sp)
/* 056D60 7F022230 C4E80004 */  lwc1  $f8, 4($a3)
/* 056D64 7F022234 4600428D */  trunc.w.s $f10, $f8
/* 056D68 7F022238 44195000 */  mfc1  $t9, $f10
/* 056D6C 7F02223C 00000000 */  nop   
/* 056D70 7F022240 AFB900A8 */  sw    $t9, 0xa8($sp)
/* 056D74 7F022244 C4F00008 */  lwc1  $f16, 8($a3)
/* 056D78 7F022248 4600848D */  trunc.w.s $f18, $f16
/* 056D7C 7F02224C 440B9000 */  mfc1  $t3, $f18
/* 056D80 7F022250 10C0005B */  beqz  $a2, .L7F0223C0
/* 056D84 7F022254 AFAB00AC */   sw    $t3, 0xac($sp)
/* 056D88 7F022258 96130000 */  lhu   $s3, ($s0)
.L7F02225C:
/* 056D8C 7F02225C 24010008 */  li    $at, 8
/* 056D90 7F022260 02C02025 */  move  $a0, $s6
/* 056D94 7F022264 326C00FF */  andi  $t4, $s3, 0xff
/* 056D98 7F022268 11810030 */  beq   $t4, $at, .L7F02232C
/* 056D9C 7F02226C 01809825 */   move  $s3, $t4
/* 056DA0 7F022270 24010012 */  li    $at, 18
/* 056DA4 7F022274 11810031 */  beq   $t4, $at, .L7F02233C
/* 056DA8 7F022278 02C02025 */   move  $a0, $s6
/* 056DAC 7F02227C 24010017 */  li    $at, 23
/* 056DB0 7F022280 11810032 */  beq   $t4, $at, .L7F02234C
/* 056DB4 7F022284 02C02025 */   move  $a0, $s6
/* 056DB8 7F022288 24010018 */  li    $at, 24
/* 056DBC 7F02228C 15810032 */  bne   $t4, $at, .L7F022358
/* 056DC0 7F022290 8E090014 */   lw    $t1, 0x14($s0)
/* 056DC4 7F022294 8E020004 */  lw    $v0, 4($s0)
/* 056DC8 7F022298 00003025 */  move  $a2, $zero
/* 056DCC 7F02229C 8448000E */  lh    $t0, 0xe($v0)
/* 056DD0 7F0222A0 1900002D */  blez  $t0, .L7F022358
/* 056DD4 7F0222A4 00000000 */   nop   
/* 056DD8 7F0222A8 8C450010 */  lw    $a1, 0x10($v0)
.L7F0222AC:
/* 056DDC 7F0222AC 8FAD00A4 */  lw    $t5, 0xa4($sp)
/* 056DE0 7F0222B0 84AE0000 */  lh    $t6, ($a1)
/* 056DE4 7F0222B4 8FAF00A8 */  lw    $t7, 0xa8($sp)
/* 056DE8 7F0222B8 84B80002 */  lh    $t8, 2($a1)
/* 056DEC 7F0222BC 01AE1023 */  subu  $v0, $t5, $t6
/* 056DF0 7F0222C0 00420019 */  multu $v0, $v0
/* 056DF4 7F0222C4 01F81823 */  subu  $v1, $t7, $t8
/* 056DF8 7F0222C8 8FB900AC */  lw    $t9, 0xac($sp)
/* 056DFC 7F0222CC 84AA0004 */  lh    $t2, 4($a1)
/* 056E00 7F0222D0 032A2023 */  subu  $a0, $t9, $t2
/* 056E04 7F0222D4 00005812 */  mflo  $t3
/* 056E08 7F0222D8 00000000 */  nop   
/* 056E0C 7F0222DC 00000000 */  nop   
/* 056E10 7F0222E0 00630019 */  multu $v1, $v1
/* 056E14 7F0222E4 00006012 */  mflo  $t4
/* 056E18 7F0222E8 016C6821 */  addu  $t5, $t3, $t4
/* 056E1C 7F0222EC 00000000 */  nop   
/* 056E20 7F0222F0 00840019 */  multu $a0, $a0
/* 056E24 7F0222F4 00007012 */  mflo  $t6
/* 056E28 7F0222F8 01AE3821 */  addu  $a3, $t5, $t6
/* 056E2C 7F0222FC 00F1082A */  slt   $at, $a3, $s1
/* 056E30 7F022300 50200005 */  beql  $at, $zero, .L7F022318
/* 056E34 7F022304 24C60001 */   addiu $a2, $a2, 1
/* 056E38 7F022308 00E08825 */  move  $s1, $a3
/* 056E3C 7F02230C 0200A025 */  move  $s4, $s0
/* 056E40 7F022310 00C0A825 */  move  $s5, $a2
/* 056E44 7F022314 24C60001 */  addiu $a2, $a2, 1
.L7F022318:
/* 056E48 7F022318 00C8082A */  slt   $at, $a2, $t0
/* 056E4C 7F02231C 1420FFE3 */  bnez  $at, .L7F0222AC
/* 056E50 7F022320 24A50010 */   addiu $a1, $a1, 0x10
/* 056E54 7F022324 1000000C */  b     .L7F022358
/* 056E58 7F022328 00000000 */   nop   
.L7F02232C:
/* 056E5C 7F02232C 0FC1BA5C */  jal   sub_GAME_7F06E970
/* 056E60 7F022330 02002825 */   move  $a1, $s0
/* 056E64 7F022334 10000008 */  b     .L7F022358
/* 056E68 7F022338 8E090014 */   lw    $t1, 0x14($s0)
.L7F02233C:
/* 056E6C 7F02233C 0FC1BA6F */  jal   process_12_handle_switch
/* 056E70 7F022340 02002825 */   move  $a1, $s0
/* 056E74 7F022344 10000004 */  b     .L7F022358
/* 056E78 7F022348 8E090014 */   lw    $t1, 0x14($s0)
.L7F02234C:
/* 056E7C 7F02234C 0FC1BA82 */  jal   process_17_pointer_to_head
/* 056E80 7F022350 02002825 */   move  $a1, $s0
/* 056E84 7F022354 8E090014 */  lw    $t1, 0x14($s0)
.L7F022358:
/* 056E88 7F022358 11200009 */  beqz  $t1, .L7F022380
/* 056E8C 7F02235C 00000000 */   nop   
/* 056E90 7F022360 12120005 */  beq   $s0, $s2, .L7F022378
/* 056E94 7F022364 2401000A */   li    $at, 10
/* 056E98 7F022368 12610005 */  beq   $s3, $at, .L7F022380
/* 056E9C 7F02236C 24010011 */   li    $at, 17
/* 056EA0 7F022370 12610003 */  beq   $s3, $at, .L7F022380
/* 056EA4 7F022374 00000000 */   nop   
.L7F022378:
/* 056EA8 7F022378 1000000F */  b     .L7F0223B8
/* 056EAC 7F02237C 01208025 */   move  $s0, $t1
.L7F022380:
/* 056EB0 7F022380 1200000D */  beqz  $s0, .L7F0223B8
/* 056EB4 7F022384 00000000 */   nop   
.L7F022388:
/* 056EB8 7F022388 56120004 */  bnel  $s0, $s2, .L7F02239C
/* 056EBC 7F02238C 8E02000C */   lw    $v0, 0xc($s0)
/* 056EC0 7F022390 10000009 */  b     .L7F0223B8
/* 056EC4 7F022394 00008025 */   move  $s0, $zero
/* 056EC8 7F022398 8E02000C */  lw    $v0, 0xc($s0)
.L7F02239C:
/* 056ECC 7F02239C 50400004 */  beql  $v0, $zero, .L7F0223B0
/* 056ED0 7F0223A0 8E100008 */   lw    $s0, 8($s0)
/* 056ED4 7F0223A4 10000004 */  b     .L7F0223B8
/* 056ED8 7F0223A8 00408025 */   move  $s0, $v0
/* 056EDC 7F0223AC 8E100008 */  lw    $s0, 8($s0)
.L7F0223B0:
/* 056EE0 7F0223B0 1600FFF5 */  bnez  $s0, .L7F022388
/* 056EE4 7F0223B4 00000000 */   nop   
.L7F0223B8:
/* 056EE8 7F0223B8 5600FFA8 */  bnezl $s0, .L7F02225C
/* 056EEC 7F0223BC 96130000 */   lhu   $s3, ($s0)
.L7F0223C0:
/* 056EF0 7F0223C0 12800097 */  beqz  $s4, .L7F022620
/* 056EF4 7F0223C4 02C02025 */   move  $a0, $s6
/* 056EF8 7F0223C8 8E900004 */  lw    $s0, 4($s4)
/* 056EFC 7F0223CC 0FC1B1E7 */  jal   extract_id_from_object_structure_microcode
/* 056F00 7F0223D0 02802825 */   move  $a1, $s4
/* 056F04 7F0223D4 0040A025 */  move  $s4, $v0
/* 056F08 7F0223D8 00008825 */  move  $s1, $zero
/* 056F0C 7F0223DC 00009825 */  move  $s3, $zero
/* 056F10 7F0223E0 0C002914 */  jal   randomGetNext
/* 056F14 7F0223E4 AFA00060 */   sw    $zero, 0x60($sp)
/* 056F18 7F0223E8 24010032 */  li    $at, 50
/* 056F1C 7F0223EC 0041001B */  divu  $zero, $v0, $at
/* 056F20 7F0223F0 8FAF00B4 */  lw    $t7, 0xb4($sp)
/* 056F24 7F0223F4 00001810 */  mfhi  $v1
/* 056F28 7F0223F8 24630014 */  addiu $v1, $v1, 0x14
/* 056F2C 7F0223FC 24010008 */  li    $at, 8
/* 056F30 7F022400 15E10002 */  bne   $t7, $at, .L7F02240C
/* 056F34 7F022404 00609025 */   move  $s2, $v1
/* 056F38 7F022408 24720064 */  addiu $s2, $v1, 0x64
.L7F02240C:
/* 056F3C 7F02240C 8FB800B4 */  lw    $t8, 0xb4($sp)
/* 056F40 7F022410 2401000F */  li    $at, 15
/* 056F44 7F022414 02C02025 */  move  $a0, $s6
/* 056F48 7F022418 57010003 */  bnel  $t8, $at, .L7F022428
/* 056F4C 7F02241C 8E190010 */   lw    $t9, 0x10($s0)
/* 056F50 7F022420 26520032 */  addiu $s2, $s2, 0x32
/* 056F54 7F022424 8E190010 */  lw    $t9, 0x10($s0)
.L7F022428:
/* 056F58 7F022428 00154100 */  sll   $t0, $s5, 4
/* 056F5C 7F02242C 03285021 */  addu  $t2, $t9, $t0
/* 056F60 7F022430 8D420008 */  lw    $v0, 8($t2)
/* 056F64 7F022434 1040000A */  beqz  $v0, .L7F022460
/* 056F68 7F022438 00402825 */   move  $a1, $v0
/* 056F6C 7F02243C 8C510004 */  lw    $s1, 4($v0)
/* 056F70 7F022440 0FC1B1E7 */  jal   extract_id_from_object_structure_microcode
/* 056F74 7F022444 AFA8003C */   sw    $t0, 0x3c($sp)
/* 056F78 7F022448 8FA8003C */  lw    $t0, 0x3c($sp)
/* 056F7C 7F02244C 8E0B0010 */  lw    $t3, 0x10($s0)
/* 056F80 7F022450 00409825 */  move  $s3, $v0
/* 056F84 7F022454 01686021 */  addu  $t4, $t3, $t0
/* 056F88 7F022458 858D000C */  lh    $t5, 0xc($t4)
/* 056F8C 7F02245C AFAD0060 */  sw    $t5, 0x60($sp)
.L7F022460:
/* 056F90 7F022460 8E0E0008 */  lw    $t6, 8($s0)
/* 056F94 7F022464 8E8F0000 */  lw    $t7, ($s4)
/* 056F98 7F022468 3405CCCC */  li    $a1, 52428
/* 056F9C 7F02246C 00003025 */  move  $a2, $zero
/* 056FA0 7F022470 15CF001D */  bne   $t6, $t7, .L7F0224E8
/* 056FA4 7F022474 00003825 */   move  $a3, $zero
/* 056FA8 7F022478 8604000C */  lh    $a0, 0xc($s0)
/* 056FAC 7F02247C 0FC26F93 */  jal   sub_GAME_7F09BE4C
/* 056FB0 7F022480 AFA8003C */   sw    $t0, 0x3c($sp)
/* 056FB4 7F022484 10400018 */  beqz  $v0, .L7F0224E8
/* 056FB8 7F022488 8FA8003C */   lw    $t0, 0x3c($sp)
/* 056FBC 7F02248C AE820000 */  sw    $v0, ($s4)
/* 056FC0 7F022490 8618000C */  lh    $t8, 0xc($s0)
/* 056FC4 7F022494 00001825 */  move  $v1, $zero
/* 056FC8 7F022498 00002025 */  move  $a0, $zero
/* 056FCC 7F02249C 1B000012 */  blez  $t8, .L7F0224E8
/* 056FD0 7F0224A0 00402825 */   move  $a1, $v0
/* 056FD4 7F0224A4 8E190008 */  lw    $t9, 8($s0)
.L7F0224A8:
/* 056FD8 7F0224A8 24630001 */  addiu $v1, $v1, 1
/* 056FDC 7F0224AC 24A50010 */  addiu $a1, $a1, 0x10
/* 056FE0 7F0224B0 03245021 */  addu  $t2, $t9, $a0
/* 056FE4 7F0224B4 8D410000 */  lw    $at, ($t2)
/* 056FE8 7F0224B8 24840010 */  addiu $a0, $a0, 0x10
/* 056FEC 7F0224BC ACA1FFF0 */  sw    $at, -0x10($a1)
/* 056FF0 7F0224C0 8D4C0004 */  lw    $t4, 4($t2)
/* 056FF4 7F0224C4 ACACFFF4 */  sw    $t4, -0xc($a1)
/* 056FF8 7F0224C8 8D410008 */  lw    $at, 8($t2)
/* 056FFC 7F0224CC ACA1FFF8 */  sw    $at, -8($a1)
/* 057000 7F0224D0 8D4C000C */  lw    $t4, 0xc($t2)
/* 057004 7F0224D4 ACACFFFC */  sw    $t4, -4($a1)
/* 057008 7F0224D8 860D000C */  lh    $t5, 0xc($s0)
/* 05700C 7F0224DC 006D082A */  slt   $at, $v1, $t5
/* 057010 7F0224E0 5420FFF1 */  bnezl $at, .L7F0224A8
/* 057014 7F0224E4 8E190008 */   lw    $t9, 8($s0)
.L7F0224E8:
/* 057018 7F0224E8 52600024 */  beql  $s3, $zero, .L7F02257C
/* 05701C 7F0224EC 8E0E0008 */   lw    $t6, 8($s0)
/* 057020 7F0224F0 8E2E0008 */  lw    $t6, 8($s1)
/* 057024 7F0224F4 8E6F0000 */  lw    $t7, ($s3)
/* 057028 7F0224F8 3405CCCC */  li    $a1, 52428
/* 05702C 7F0224FC 00003025 */  move  $a2, $zero
/* 057030 7F022500 15CF001D */  bne   $t6, $t7, .L7F022578
/* 057034 7F022504 00003825 */   move  $a3, $zero
/* 057038 7F022508 8624000C */  lh    $a0, 0xc($s1)
/* 05703C 7F02250C 0FC26F93 */  jal   sub_GAME_7F09BE4C
/* 057040 7F022510 AFA8003C */   sw    $t0, 0x3c($sp)
/* 057044 7F022514 10400018 */  beqz  $v0, .L7F022578
/* 057048 7F022518 8FA8003C */   lw    $t0, 0x3c($sp)
/* 05704C 7F02251C AE620000 */  sw    $v0, ($s3)
/* 057050 7F022520 8638000C */  lh    $t8, 0xc($s1)
/* 057054 7F022524 00001825 */  move  $v1, $zero
/* 057058 7F022528 00002025 */  move  $a0, $zero
/* 05705C 7F02252C 1B000012 */  blez  $t8, .L7F022578
/* 057060 7F022530 00402825 */   move  $a1, $v0
/* 057064 7F022534 8E390008 */  lw    $t9, 8($s1)
.L7F022538:
/* 057068 7F022538 24630001 */  addiu $v1, $v1, 1
/* 05706C 7F02253C 24A50010 */  addiu $a1, $a1, 0x10
/* 057070 7F022540 03245821 */  addu  $t3, $t9, $a0
/* 057074 7F022544 8D610000 */  lw    $at, ($t3)
/* 057078 7F022548 24840010 */  addiu $a0, $a0, 0x10
/* 05707C 7F02254C ACA1FFF0 */  sw    $at, -0x10($a1)
/* 057080 7F022550 8D6C0004 */  lw    $t4, 4($t3)
/* 057084 7F022554 ACACFFF4 */  sw    $t4, -0xc($a1)
/* 057088 7F022558 8D610008 */  lw    $at, 8($t3)
/* 05708C 7F02255C ACA1FFF8 */  sw    $at, -8($a1)
/* 057090 7F022560 8D6C000C */  lw    $t4, 0xc($t3)
/* 057094 7F022564 ACACFFFC */  sw    $t4, -4($a1)
/* 057098 7F022568 862D000C */  lh    $t5, 0xc($s1)
/* 05709C 7F02256C 006D082A */  slt   $at, $v1, $t5
/* 0570A0 7F022570 5420FFF1 */  bnezl $at, .L7F022538
/* 0570A4 7F022574 8E390008 */   lw    $t9, 8($s1)
.L7F022578:
/* 0570A8 7F022578 8E0E0008 */  lw    $t6, 8($s0)
.L7F02257C:
/* 0570AC 7F02257C 8E8F0000 */  lw    $t7, ($s4)
/* 0570B0 7F022580 11CF0010 */  beq   $t6, $t7, .L7F0225C4
/* 0570B4 7F022584 00000000 */   nop   
/* 0570B8 7F022588 8E180010 */  lw    $t8, 0x10($s0)
/* 0570BC 7F02258C 0308C821 */  addu  $t9, $t8, $t0
/* 0570C0 7F022590 87220006 */  lh    $v0, 6($t9)
/* 0570C4 7F022594 0440000B */  bltz  $v0, .L7F0225C4
/* 0570C8 7F022598 00000000 */   nop   
/* 0570CC 7F02259C 8E8A0000 */  lw    $t2, ($s4)
.L7F0225A0:
/* 0570D0 7F0225A0 00025900 */  sll   $t3, $v0, 4
/* 0570D4 7F0225A4 00027040 */  sll   $t6, $v0, 1
/* 0570D8 7F0225A8 014B6021 */  addu  $t4, $t2, $t3
/* 0570DC 7F0225AC A192000F */  sb    $s2, 0xf($t4)
/* 0570E0 7F0225B0 8E0D0014 */  lw    $t5, 0x14($s0)
/* 0570E4 7F0225B4 01AE7821 */  addu  $t7, $t5, $t6
/* 0570E8 7F0225B8 85E20000 */  lh    $v0, ($t7)
/* 0570EC 7F0225BC 0443FFF8 */  bgezl $v0, .L7F0225A0
/* 0570F0 7F0225C0 8E8A0000 */   lw    $t2, ($s4)
.L7F0225C4:
/* 0570F4 7F0225C4 52600017 */  beql  $s3, $zero, .L7F022624
/* 0570F8 7F0225C8 8FBF0034 */   lw    $ra, 0x34($sp)
/* 0570FC 7F0225CC 8E380008 */  lw    $t8, 8($s1)
/* 057100 7F0225D0 8E790000 */  lw    $t9, ($s3)
/* 057104 7F0225D4 8FAB0060 */  lw    $t3, 0x60($sp)
/* 057108 7F0225D8 53190012 */  beql  $t8, $t9, .L7F022624
/* 05710C 7F0225DC 8FBF0034 */   lw    $ra, 0x34($sp)
/* 057110 7F0225E0 8E2A0010 */  lw    $t2, 0x10($s1)
/* 057114 7F0225E4 000B6100 */  sll   $t4, $t3, 4
/* 057118 7F0225E8 014C6821 */  addu  $t5, $t2, $t4
/* 05711C 7F0225EC 85A20006 */  lh    $v0, 6($t5)
/* 057120 7F0225F0 0442000C */  bltzl $v0, .L7F022624
/* 057124 7F0225F4 8FBF0034 */   lw    $ra, 0x34($sp)
/* 057128 7F0225F8 8E6E0000 */  lw    $t6, ($s3)
.L7F0225FC:
/* 05712C 7F0225FC 00027900 */  sll   $t7, $v0, 4
/* 057130 7F022600 00025840 */  sll   $t3, $v0, 1
/* 057134 7F022604 01CFC021 */  addu  $t8, $t6, $t7
/* 057138 7F022608 A312000F */  sb    $s2, 0xf($t8)
/* 05713C 7F02260C 8E390014 */  lw    $t9, 0x14($s1)
/* 057140 7F022610 032B5021 */  addu  $t2, $t9, $t3
/* 057144 7F022614 85420000 */  lh    $v0, ($t2)
/* 057148 7F022618 0443FFF8 */  bgezl $v0, .L7F0225FC
/* 05714C 7F02261C 8E6E0000 */   lw    $t6, ($s3)
.L7F022620:
/* 057150 7F022620 8FBF0034 */  lw    $ra, 0x34($sp)
.L7F022624:
/* 057154 7F022624 8FB00018 */  lw    $s0, 0x18($sp)
/* 057158 7F022628 8FB1001C */  lw    $s1, 0x1c($sp)
/* 05715C 7F02262C 8FB20020 */  lw    $s2, 0x20($sp)
/* 057160 7F022630 8FB30024 */  lw    $s3, 0x24($sp)
/* 057164 7F022634 8FB40028 */  lw    $s4, 0x28($sp)
/* 057168 7F022638 8FB5002C */  lw    $s5, 0x2c($sp)
/* 05716C 7F02263C 8FB60030 */  lw    $s6, 0x30($sp)
/* 057170 7F022640 03E00008 */  jr    $ra
/* 057174 7F022644 27BD00B0 */   addiu $sp, $sp, 0xb0
)
#endif



#ifdef NONMATCHING
void sub_GAME_7F022648(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F022648
/* 057178 7F022648 27BDFF10 */  addiu $sp, $sp, -0xf0
/* 05717C 7F02264C AFBF0044 */  sw    $ra, 0x44($sp)
/* 057180 7F022650 AFB20040 */  sw    $s2, 0x40($sp)
/* 057184 7F022654 AFB1003C */  sw    $s1, 0x3c($sp)
/* 057188 7F022658 AFB00038 */  sw    $s0, 0x38($sp)
/* 05718C 7F02265C AFA400F0 */  sw    $a0, 0xf0($sp)
/* 057190 7F022660 8C820004 */  lw    $v0, 4($a0)
/* 057194 7F022664 24010005 */  li    $at, 5
/* 057198 7F022668 00A09025 */  move  $s2, $a1
/* 05719C 7F02266C 804F0007 */  lb    $t7, 7($v0)
/* 0571A0 7F022670 51E100BE */  beql  $t7, $at, .L7F02296C
/* 0571A4 7F022674 8FBF0044 */   lw    $ra, 0x44($sp)
/* 0571A8 7F022678 8C50001C */  lw    $s0, 0x1c($v0)
/* 0571AC 7F02267C AFA200EC */  sw    $v0, 0xec($sp)
/* 0571B0 7F022680 0FC1B403 */  jal   getinstsize
/* 0571B4 7F022684 02002025 */   move  $a0, $s0
/* 0571B8 7F022688 8FA200F0 */  lw    $v0, 0xf0($sp)
/* 0571BC 7F02268C E7A000E4 */  swc1  $f0, 0xe4($sp)
/* 0571C0 7F022690 90580001 */  lbu   $t8, 1($v0)
/* 0571C4 7F022694 33190002 */  andi  $t9, $t8, 2
/* 0571C8 7F022698 532000B4 */  beql  $t9, $zero, .L7F02296C
/* 0571CC 7F02269C 8FBF0044 */   lw    $ra, 0x44($sp)
/* 0571D0 7F0226A0 C4440018 */  lwc1  $f4, 0x18($v0)
/* 0571D4 7F0226A4 C6480034 */  lwc1  $f8, 0x34($s2)
/* 0571D8 7F0226A8 00008825 */  move  $s1, $zero
/* 0571DC 7F0226AC 46002181 */  sub.s $f6, $f4, $f0
/* 0571E0 7F0226B0 02002025 */  move  $a0, $s0
/* 0571E4 7F0226B4 4608303C */  c.lt.s $f6, $f8
/* 0571E8 7F0226B8 00000000 */  nop   
/* 0571EC 7F0226BC 450200AB */  bc1fl .L7F02296C
/* 0571F0 7F0226C0 8FBF0044 */   lw    $ra, 0x44($sp)
/* 0571F4 7F0226C4 AFA000DC */  sw    $zero, 0xdc($sp)
/* 0571F8 7F0226C8 AFA000D8 */  sw    $zero, 0xd8($sp)
/* 0571FC 7F0226CC AFA000D4 */  sw    $zero, 0xd4($sp)
/* 057200 7F0226D0 0FC1B1A8 */  jal   getsubmatrix
/* 057204 7F0226D4 AFA0009C */   sw    $zero, 0x9c($sp)
/* 057208 7F0226D8 44806000 */  mtc1  $zero, $f12
/* 05720C 7F0226DC AFA20098 */  sw    $v0, 0x98($sp)
/* 057210 7F0226E0 00002825 */  move  $a1, $zero
/* 057214 7F0226E4 8FA600EC */  lw    $a2, 0xec($sp)
.L7F0226E8:
/* 057218 7F0226E8 8CC30160 */  lw    $v1, 0x160($a2)
/* 05721C 7F0226EC 50600012 */  beql  $v1, $zero, .L7F022738
/* 057220 7F0226F0 24A50004 */   addiu $a1, $a1, 4
/* 057224 7F0226F4 8C620004 */  lw    $v0, 4($v1)
/* 057228 7F0226F8 8C440014 */  lw    $a0, 0x14($v0)
/* 05722C 7F0226FC E7AC0094 */  swc1  $f12, 0x94($sp)
/* 057230 7F022700 AFA60050 */  sw    $a2, 0x50($sp)
/* 057234 7F022704 0FC1B403 */  jal   getinstsize
/* 057238 7F022708 AFA50054 */   sw    $a1, 0x54($sp)
/* 05723C 7F02270C C60A0014 */  lwc1  $f10, 0x14($s0)
/* 057240 7F022710 C7AC0094 */  lwc1  $f12, 0x94($sp)
/* 057244 7F022714 8FA50054 */  lw    $a1, 0x54($sp)
/* 057248 7F022718 460A0082 */  mul.s $f2, $f0, $f10
/* 05724C 7F02271C 8FA60050 */  lw    $a2, 0x50($sp)
/* 057250 7F022720 4602603C */  c.lt.s $f12, $f2
/* 057254 7F022724 00000000 */  nop   
/* 057258 7F022728 45020003 */  bc1fl .L7F022738
/* 05725C 7F02272C 24A50004 */   addiu $a1, $a1, 4
/* 057260 7F022730 46001306 */  mov.s $f12, $f2
/* 057264 7F022734 24A50004 */  addiu $a1, $a1, 4
.L7F022738:
/* 057268 7F022738 24010008 */  li    $at, 8
/* 05726C 7F02273C 14A1FFEA */  bne   $a1, $at, .L7F0226E8
/* 057270 7F022740 24C60004 */   addiu $a2, $a2, 4
/* 057274 7F022744 C7A000E4 */  lwc1  $f0, 0xe4($sp)
/* 057278 7F022748 8FA60098 */  lw    $a2, 0x98($sp)
/* 05727C 7F02274C 2650000C */  addiu $s0, $s2, 0xc
/* 057280 7F022750 460C0000 */  add.s $f0, $f0, $f12
/* 057284 7F022754 02002825 */  move  $a1, $s0
/* 057288 7F022758 02402025 */  move  $a0, $s2
/* 05728C 7F02275C 24C60030 */  addiu $a2, $a2, 0x30
/* 057290 7F022760 44070000 */  mfc1  $a3, $f0
/* 057294 7F022764 0FC1041D */  jal   sub_GAME_7F041074
/* 057298 7F022768 00000000 */   nop   
/* 05729C 7F02276C 10400003 */  beqz  $v0, .L7F02277C
/* 0572A0 7F022770 24080001 */   li    $t0, 1
/* 0572A4 7F022774 AFA800D4 */  sw    $t0, 0xd4($sp)
/* 0572A8 7F022778 24110001 */  li    $s1, 1
.L7F02277C:
/* 0572AC 7F02277C 12200028 */  beqz  $s1, .L7F022820
/* 0572B0 7F022780 8FA900EC */   lw    $t1, 0xec($sp)
/* 0572B4 7F022784 8D2A0020 */  lw    $t2, 0x20($t1)
/* 0572B8 7F022788 27AB00D8 */  addiu $t3, $sp, 0xd8
/* 0572BC 7F02278C AFAB0010 */  sw    $t3, 0x10($sp)
/* 0572C0 7F022790 27A40080 */  addiu $a0, $sp, 0x80
/* 0572C4 7F022794 02402825 */  move  $a1, $s2
/* 0572C8 7F022798 02003025 */  move  $a2, $s0
/* 0572CC 7F02279C 27A700DC */  addiu $a3, $sp, 0xdc
/* 0572D0 7F0227A0 0FC1B004 */  jal   sub_GAME_7F06C010
/* 0572D4 7F0227A4 AFAA0080 */   sw    $t2, 0x80($sp)
/* 0572D8 7F0227A8 24010064 */  li    $at, 100
/* 0572DC 7F0227AC 10410003 */  beq   $v0, $at, .L7F0227BC
/* 0572E0 7F0227B0 00408825 */   move  $s1, $v0
/* 0572E4 7F0227B4 2401006E */  li    $at, 110
/* 0572E8 7F0227B8 14410019 */  bne   $v0, $at, .L7F022820
.L7F0227BC:
/* 0572EC 7F0227BC 27AC00A4 */   addiu $t4, $sp, 0xa4
.L7F0227C0:
/* 0572F0 7F0227C0 27AD00A0 */  addiu $t5, $sp, 0xa0
/* 0572F4 7F0227C4 27AE009C */  addiu $t6, $sp, 0x9c
/* 0572F8 7F0227C8 AFAE0018 */  sw    $t6, 0x18($sp)
/* 0572FC 7F0227CC AFAD0014 */  sw    $t5, 0x14($sp)
/* 057300 7F0227D0 AFAC0010 */  sw    $t4, 0x10($sp)
/* 057304 7F0227D4 8FA400DC */  lw    $a0, 0xdc($sp)
/* 057308 7F0227D8 8FA500D8 */  lw    $a1, 0xd8($sp)
/* 05730C 7F0227DC 02403025 */  move  $a2, $s2
/* 057310 7F0227E0 0FC1366C */  jal   sub_GAME_7F04D9B0
/* 057314 7F0227E4 02003825 */   move  $a3, $s0
/* 057318 7F0227E8 1440000D */  bnez  $v0, .L7F022820
/* 05731C 7F0227EC 27A40080 */   addiu $a0, $sp, 0x80
/* 057320 7F0227F0 27AF00D8 */  addiu $t7, $sp, 0xd8
/* 057324 7F0227F4 AFAF0010 */  sw    $t7, 0x10($sp)
/* 057328 7F0227F8 02402825 */  move  $a1, $s2
/* 05732C 7F0227FC 02003025 */  move  $a2, $s0
/* 057330 7F022800 0FC1AF80 */  jal   probably_damage_detail_blood_effect_related
/* 057334 7F022804 27A700DC */   addiu $a3, $sp, 0xdc
/* 057338 7F022808 24010064 */  li    $at, 100
/* 05733C 7F02280C 1041FFEB */  beq   $v0, $at, .L7F0227BC
/* 057340 7F022810 00408825 */   move  $s1, $v0
/* 057344 7F022814 2401006E */  li    $at, 110
/* 057348 7F022818 5041FFE9 */  beql  $v0, $at, .L7F0227C0
/* 05734C 7F02281C 27AC00A4 */   addiu $t4, $sp, 0xa4
.L7F022820:
/* 057350 7F022820 5A200041 */  blezl $s1, .L7F022928
/* 057354 7F022824 8FAC00D4 */   lw    $t4, 0xd4($sp)
/* 057358 7F022828 C650000C */  lwc1  $f16, 0xc($s2)
/* 05735C 7F02282C E7B00074 */  swc1  $f16, 0x74($sp)
/* 057360 7F022830 C6520010 */  lwc1  $f18, 0x10($s2)
/* 057364 7F022834 E7B20078 */  swc1  $f18, 0x78($sp)
/* 057368 7F022838 C6440014 */  lwc1  $f4, 0x14($s2)
/* 05736C 7F02283C 0FC1E111 */  jal   currentPlayerGetMatrix10D4
/* 057370 7F022840 E7A4007C */   swc1  $f4, 0x7c($sp)
/* 057374 7F022844 00402025 */  move  $a0, $v0
/* 057378 7F022848 0FC160F6 */  jal   matrix_4x4_rotate_vector_in_place
/* 05737C 7F02284C 27A50074 */   addiu $a1, $sp, 0x74
/* 057380 7F022850 8FA400DC */  lw    $a0, 0xdc($sp)
/* 057384 7F022854 8FA500D8 */  lw    $a1, 0xd8($sp)
/* 057388 7F022858 0FC1B198 */  jal   sub_GAME_7F06C660
/* 05738C 7F02285C 00003025 */   move  $a2, $zero
/* 057390 7F022860 C4460030 */  lwc1  $f6, 0x30($v0)
/* 057394 7F022864 C6480000 */  lwc1  $f8, ($s2)
/* 057398 7F022868 46083281 */  sub.s $f10, $f6, $f8
/* 05739C 7F02286C E7AA0060 */  swc1  $f10, 0x60($sp)
/* 0573A0 7F022870 C6520004 */  lwc1  $f18, 4($s2)
/* 0573A4 7F022874 C4500034 */  lwc1  $f16, 0x34($v0)
/* 0573A8 7F022878 46128101 */  sub.s $f4, $f16, $f18
/* 0573AC 7F02287C C7B00060 */  lwc1  $f16, 0x60($sp)
/* 0573B0 7F022880 E7A40064 */  swc1  $f4, 0x64($sp)
/* 0573B4 7F022884 C6480008 */  lwc1  $f8, 8($s2)
/* 0573B8 7F022888 C4460038 */  lwc1  $f6, 0x38($v0)
/* 0573BC 7F02288C 46108482 */  mul.s $f18, $f16, $f16
/* 0573C0 7F022890 C7A40064 */  lwc1  $f4, 0x64($sp)
/* 0573C4 7F022894 46083281 */  sub.s $f10, $f6, $f8
/* 0573C8 7F022898 46042182 */  mul.s $f6, $f4, $f4
/* 0573CC 7F02289C E7AA0068 */  swc1  $f10, 0x68($sp)
/* 0573D0 7F0228A0 C7AA0068 */  lwc1  $f10, 0x68($sp)
/* 0573D4 7F0228A4 460A5402 */  mul.s $f16, $f10, $f10
/* 0573D8 7F0228A8 46069200 */  add.s $f8, $f18, $f6
/* 0573DC 7F0228AC 0C007DF8 */  jal   sqrtf
/* 0573E0 7F0228B0 46088300 */   add.s $f12, $f16, $f8
/* 0573E4 7F0228B4 C6440014 */  lwc1  $f4, 0x14($s2)
/* 0573E8 7F0228B8 C6460008 */  lwc1  $f6, 8($s2)
/* 0573EC 7F0228BC C64A0034 */  lwc1  $f10, 0x34($s2)
/* 0573F0 7F0228C0 46002482 */  mul.s $f18, $f4, $f0
/* 0573F4 7F0228C4 02402025 */  move  $a0, $s2
/* 0573F8 7F0228C8 8FA500F0 */  lw    $a1, 0xf0($sp)
/* 0573FC 7F0228CC 02203825 */  move  $a3, $s1
/* 057400 7F0228D0 8FB800D8 */  lw    $t8, 0xd8($sp)
/* 057404 7F0228D4 27B900A4 */  addiu $t9, $sp, 0xa4
/* 057408 7F0228D8 240B0001 */  li    $t3, 1
/* 05740C 7F0228DC 46069080 */  add.s $f2, $f18, $f6
/* 057410 7F0228E0 46001087 */  neg.s $f2, $f2
/* 057414 7F0228E4 460A103C */  c.lt.s $f2, $f10
/* 057418 7F0228E8 00000000 */  nop   
/* 05741C 7F0228EC 4502000E */  bc1fl .L7F022928
/* 057420 7F0228F0 8FAC00D4 */   lw    $t4, 0xd4($sp)
/* 057424 7F0228F4 8FA800A0 */  lw    $t0, 0xa0($sp)
/* 057428 7F0228F8 8FA9009C */  lw    $t1, 0x9c($sp)
/* 05742C 7F0228FC 8FAA00DC */  lw    $t2, 0xdc($sp)
/* 057430 7F022900 44061000 */  mfc1  $a2, $f2
/* 057434 7F022904 AFB80010 */  sw    $t8, 0x10($sp)
/* 057438 7F022908 AFB90014 */  sw    $t9, 0x14($sp)
/* 05743C 7F02290C AFAB0024 */  sw    $t3, 0x24($sp)
/* 057440 7F022910 AFA00028 */  sw    $zero, 0x28($sp)
/* 057444 7F022914 AFA80018 */  sw    $t0, 0x18($sp)
/* 057448 7F022918 AFA9001C */  sw    $t1, 0x1c($sp)
/* 05744C 7F02291C 0FC0EE70 */  jal   sub_GAME_7F03B9C0
/* 057450 7F022920 AFAA0020 */   sw    $t2, 0x20($sp)
/* 057454 7F022924 8FAC00D4 */  lw    $t4, 0xd4($sp)
.L7F022928:
/* 057458 7F022928 8FAD00F0 */  lw    $t5, 0xf0($sp)
/* 05745C 7F02292C 5180000F */  beql  $t4, $zero, .L7F02296C
/* 057460 7F022930 8FBF0044 */   lw    $ra, 0x44($sp)
/* 057464 7F022934 C6500034 */  lwc1  $f16, 0x34($s2)
/* 057468 7F022938 C5A80018 */  lwc1  $f8, 0x18($t5)
/* 05746C 7F02293C 8FAE00EC */  lw    $t6, 0xec($sp)
/* 057470 7F022940 4610403E */  c.le.s $f8, $f16
/* 057474 7F022944 00000000 */  nop   
/* 057478 7F022948 45020008 */  bc1fl .L7F02296C
/* 05747C 7F02294C 8FBF0044 */   lw    $ra, 0x44($sp)
/* 057480 7F022950 8DCF0014 */  lw    $t7, 0x14($t6)
/* 057484 7F022954 81D9000A */  lb    $t9, 0xa($t6)
/* 057488 7F022958 35F80004 */  ori   $t8, $t7, 4
/* 05748C 7F02295C 27280001 */  addiu $t0, $t9, 1
/* 057490 7F022960 ADD80014 */  sw    $t8, 0x14($t6)
/* 057494 7F022964 A1C8000A */  sb    $t0, 0xa($t6)
/* 057498 7F022968 8FBF0044 */  lw    $ra, 0x44($sp)
.L7F02296C:
/* 05749C 7F02296C 8FB00038 */  lw    $s0, 0x38($sp)
/* 0574A0 7F022970 8FB1003C */  lw    $s1, 0x3c($sp)
/* 0574A4 7F022974 8FB20040 */  lw    $s2, 0x40($sp)
/* 0574A8 7F022978 03E00008 */  jr    $ra
/* 0574AC 7F02297C 27BD00F0 */   addiu $sp, $sp, 0xf0
)
#endif



#ifdef NONMATCHING
void sub_GAME_7F022980(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F022980
/* 0574B0 7F022980 27BDFF08 */  addiu $sp, $sp, -0xf8
/* 0574B4 7F022984 AFBF004C */  sw    $ra, 0x4c($sp)
/* 0574B8 7F022988 AFB60048 */  sw    $s6, 0x48($sp)
/* 0574BC 7F02298C AFB50044 */  sw    $s5, 0x44($sp)
/* 0574C0 7F022990 AFB40040 */  sw    $s4, 0x40($sp)
/* 0574C4 7F022994 AFB3003C */  sw    $s3, 0x3c($sp)
/* 0574C8 7F022998 AFB20038 */  sw    $s2, 0x38($sp)
/* 0574CC 7F02299C AFB10034 */  sw    $s1, 0x34($sp)
/* 0574D0 7F0229A0 AFB00030 */  sw    $s0, 0x30($sp)
/* 0574D4 7F0229A4 F7B40028 */  sdc1  $f20, 0x28($sp)
/* 0574D8 7F0229A8 C4A40000 */  lwc1  $f4, ($a1)
/* 0574DC 7F0229AC C486000C */  lwc1  $f6, 0xc($a0)
/* 0574E0 7F0229B0 C48A0014 */  lwc1  $f10, 0x14($a0)
/* 0574E4 7F0229B4 C4920000 */  lwc1  $f18, ($a0)
/* 0574E8 7F0229B8 46062202 */  mul.s $f8, $f4, $f6
/* 0574EC 7F0229BC 8CAE0004 */  lw    $t6, 4($a1)
/* 0574F0 7F0229C0 00A08825 */  move  $s1, $a1
/* 0574F4 7F0229C4 0080A025 */  move  $s4, $a0
/* 0574F8 7F0229C8 8DD60004 */  lw    $s6, 4($t6)
/* 0574FC 7F0229CC 460A4403 */  div.s $f16, $f8, $f10
/* 057500 7F0229D0 46109101 */  sub.s $f4, $f18, $f16
/* 057504 7F0229D4 E7A40098 */  swc1  $f4, 0x98($sp)
/* 057508 7F0229D8 C4A60000 */  lwc1  $f6, ($a1)
/* 05750C 7F0229DC C4880010 */  lwc1  $f8, 0x10($a0)
/* 057510 7F0229E0 C4920014 */  lwc1  $f18, 0x14($a0)
/* 057514 7F0229E4 C4840004 */  lwc1  $f4, 4($a0)
/* 057518 7F0229E8 46083282 */  mul.s $f10, $f6, $f8
/* 05751C 7F0229EC 46125403 */  div.s $f16, $f10, $f18
/* 057520 7F0229F0 46102181 */  sub.s $f6, $f4, $f16
/* 057524 7F0229F4 C7A40098 */  lwc1  $f4, 0x98($sp)
/* 057528 7F0229F8 E7A6009C */  swc1  $f6, 0x9c($sp)
/* 05752C 7F0229FC C4AA0000 */  lwc1  $f10, ($a1)
/* 057530 7F022A00 C4880008 */  lwc1  $f8, 8($a0)
/* 057534 7F022A04 46042402 */  mul.s $f16, $f4, $f4
/* 057538 7F022A08 C7A6009C */  lwc1  $f6, 0x9c($sp)
/* 05753C 7F022A0C 460A4481 */  sub.s $f18, $f8, $f10
/* 057540 7F022A10 46063202 */  mul.s $f8, $f6, $f6
/* 057544 7F022A14 E7B200A0 */  swc1  $f18, 0xa0($sp)
/* 057548 7F022A18 C7B200A0 */  lwc1  $f18, 0xa0($sp)
/* 05754C 7F022A1C 46129102 */  mul.s $f4, $f18, $f18
/* 057550 7F022A20 46088280 */  add.s $f10, $f16, $f8
/* 057554 7F022A24 0C007DF8 */  jal   sqrtf
/* 057558 7F022A28 460A2300 */   add.s $f12, $f4, $f10
/* 05755C 7F022A2C 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 057560 7F022A30 44813000 */  mtc1  $at, $f6
/* 057564 7F022A34 3C014228 */  li    $at, 0x42280000 # 42.000000
/* 057568 7F022A38 44818000 */  mtc1  $at, $f16
/* 05756C 7F022A3C C7B20098 */  lwc1  $f18, 0x98($sp)
/* 057570 7F022A40 C7AA009C */  lwc1  $f10, 0x9c($sp)
/* 057574 7F022A44 46008203 */  div.s $f8, $f16, $f0
/* 057578 7F022A48 46083081 */  sub.s $f2, $f6, $f8
/* 05757C 7F022A4C C7A600A0 */  lwc1  $f6, 0xa0($sp)
/* 057580 7F022A50 46029102 */  mul.s $f4, $f18, $f2
/* 057584 7F022A54 00000000 */  nop   
/* 057588 7F022A58 46025402 */  mul.s $f16, $f10, $f2
/* 05758C 7F022A5C 00000000 */  nop   
/* 057590 7F022A60 46023202 */  mul.s $f8, $f6, $f2
/* 057594 7F022A64 E7A400A8 */  swc1  $f4, 0xa8($sp)
/* 057598 7F022A68 E7B000AC */  swc1  $f16, 0xac($sp)
/* 05759C 7F022A6C 0FC1E111 */  jal   currentPlayerGetMatrix10D4
/* 0575A0 7F022A70 E7A800B0 */   swc1  $f8, 0xb0($sp)
/* 0575A4 7F022A74 27B000A8 */  addiu $s0, $sp, 0xa8
/* 0575A8 7F022A78 02002825 */  move  $a1, $s0
/* 0575AC 7F022A7C 0FC1611D */  jal   matrix_4x4_transform_vector_in_place
/* 0575B0 7F022A80 00402025 */   move  $a0, $v0
/* 0575B4 7F022A84 0FC19ED3 */  jal   sub_GAME_7F067B4C
/* 0575B8 7F022A88 02002025 */   move  $a0, $s0
/* 0575BC 7F022A8C 8E840018 */  lw    $a0, 0x18($s4)
/* 0575C0 7F022A90 8E250004 */  lw    $a1, 4($s1)
/* 0575C4 7F022A94 0FC19107 */  jal   recall_joy2_hits_edit_detail_edit_flag
/* 0575C8 7F022A98 2406FFFF */   li    $a2, -1
/* 0575CC 7F022A9C 8E240004 */  lw    $a0, 4($s1)
/* 0575D0 7F022AA0 8E250008 */  lw    $a1, 8($s1)
/* 0575D4 7F022AA4 27A60098 */  addiu $a2, $sp, 0x98
/* 0575D8 7F022AA8 0FC0881E */  jal   sub_GAME_7F022078
/* 0575DC 7F022AAC 02003825 */   move  $a3, $s0
/* 0575E0 7F022AB0 8E250008 */  lw    $a1, 8($s1)
/* 0575E4 7F022AB4 8E870018 */  lw    $a3, 0x18($s4)
/* 0575E8 7F022AB8 240F0001 */  li    $t7, 1
/* 0575EC 7F022ABC AFAF0010 */  sw    $t7, 0x10($sp)
/* 0575F0 7F022AC0 02C02025 */  move  $a0, $s6
/* 0575F4 7F022AC4 0FC09C9F */  jal   handles_shot_actors
/* 0575F8 7F022AC8 26860028 */   addiu $a2, $s4, 0x28
/* 0575FC 7F022ACC 504000C9 */  beql  $v0, $zero, .L7F022DF4
/* 057600 7F022AD0 8FBF004C */   lw    $ra, 0x4c($sp)
/* 057604 7F022AD4 8E220008 */  lw    $v0, 8($s1)
/* 057608 7F022AD8 24010064 */  li    $at, 100
/* 05760C 7F022ADC 3C158005 */  lui   $s5, %hi(D_8004E86C)
/* 057610 7F022AE0 14410057 */  bne   $v0, $at, .L7F022C40
/* 057614 7F022AE4 26B5E86C */   addiu $s5, %lo(D_8004E86C) # addiu $s5, $s5, -0x1794
/* 057618 7F022AE8 00009025 */  move  $s2, $zero
/* 05761C 7F022AEC 02C09825 */  move  $s3, $s6
.L7F022AF0:
/* 057620 7F022AF0 8E700160 */  lw    $s0, 0x160($s3)
/* 057624 7F022AF4 5200004D */  beql  $s0, $zero, .L7F022C2C
/* 057628 7F022AF8 26520004 */   addiu $s2, $s2, 4
/* 05762C 7F022AFC 8E030004 */  lw    $v1, 4($s0)
/* 057630 7F022B00 8E380048 */  lw    $t8, 0x48($s1)
/* 057634 7F022B04 8C790014 */  lw    $t9, 0x14($v1)
/* 057638 7F022B08 57190048 */  bnel  $t8, $t9, .L7F022C2C
/* 05763C 7F022B0C 26520004 */   addiu $s2, $s2, 4
/* 057640 7F022B10 80620080 */  lb    $v0, 0x80($v1)
/* 057644 7F022B14 2401001A */  li    $at, 26
/* 057648 7F022B18 02002025 */  move  $a0, $s0
/* 05764C 7F022B1C 1041000D */  beq   $v0, $at, .L7F022B54
/* 057650 7F022B20 24010057 */   li    $at, 87
/* 057654 7F022B24 1041000B */  beq   $v0, $at, .L7F022B54
/* 057658 7F022B28 24010056 */   li    $at, 86
/* 05765C 7F022B2C 10410009 */  beq   $v0, $at, .L7F022B54
/* 057660 7F022B30 2401001B */   li    $at, 27
/* 057664 7F022B34 10410007 */  beq   $v0, $at, .L7F022B54
/* 057668 7F022B38 24010021 */   li    $at, 33
/* 05766C 7F022B3C 10410005 */  beq   $v0, $at, .L7F022B54
/* 057670 7F022B40 2401001D */   li    $at, 29
/* 057674 7F022B44 10410003 */  beq   $v0, $at, .L7F022B54
/* 057678 7F022B48 2401001C */   li    $at, 28
/* 05767C 7F022B4C 54410013 */  bnel  $v0, $at, .L7F022B9C
/* 057680 7F022B50 8622003A */   lh    $v0, 0x3a($s1)
.L7F022B54:
/* 057684 7F022B54 0FC12FF4 */  jal   propobjSetDropped
/* 057688 7F022B58 24050001 */   li    $a1, 1
/* 05768C 7F022B5C 96C90012 */  lhu   $t1, 0x12($s6)
/* 057690 7F022B60 352A0001 */  ori   $t2, $t1, 1
/* 057694 7F022B64 A6CA0012 */  sh    $t2, 0x12($s6)
/* 057698 7F022B68 0FC177E1 */  jal   bondwalkItemGetDestructionAmount
/* 05769C 7F022B6C 8E840018 */   lw    $a0, 0x18($s4)
/* 0576A0 7F022B70 0FC26C54 */  jal   get_cur_playernum
/* 0576A4 7F022B74 46000506 */   mov.s $f20, $f0
/* 0576A8 7F022B78 8E040004 */  lw    $a0, 4($s0)
/* 0576AC 7F022B7C 4405A000 */  mfc1  $a1, $f20
/* 0576B0 7F022B80 8E870018 */  lw    $a3, 0x18($s4)
/* 0576B4 7F022B84 AFA20010 */  sw    $v0, 0x10($sp)
/* 0576B8 7F022B88 0FC13842 */  jal   maybe_detonate_object
/* 0576BC 7F022B8C 27A60098 */   addiu $a2, $sp, 0x98
/* 0576C0 7F022B90 10000026 */  b     .L7F022C2C
/* 0576C4 7F022B94 26520004 */   addiu $s2, $s2, 4
/* 0576C8 7F022B98 8622003A */  lh    $v0, 0x3a($s1)
.L7F022B9C:
/* 0576CC 7F022B9C 26240010 */  addiu $a0, $s1, 0x10
/* 0576D0 7F022BA0 2625001C */  addiu $a1, $s1, 0x1c
/* 0576D4 7F022BA4 04410003 */  bgez  $v0, .L7F022BB4
/* 0576D8 7F022BA8 000258C0 */   sll   $t3, $v0, 3
/* 0576DC 7F022BAC 10000008 */  b     .L7F022BD0
/* 0576E0 7F022BB0 8EA30000 */   lw    $v1, ($s5)
.L7F022BB4:
/* 0576E4 7F022BB4 3C0C8005 */  lui   $t4, %hi(image_entries)
/* 0576E8 7F022BB8 018B6021 */  addu  $t4, $t4, $t3
/* 0576EC 7F022BBC 918C9300 */  lbu   $t4, %lo(image_entries)($t4)
/* 0576F0 7F022BC0 318D000F */  andi  $t5, $t4, 0xf
/* 0576F4 7F022BC4 000D7080 */  sll   $t6, $t5, 2
/* 0576F8 7F022BC8 02AE7821 */  addu  $t7, $s5, $t6
/* 0576FC 7F022BCC 8DE30000 */  lw    $v1, ($t7)
.L7F022BD0:
/* 057700 7F022BD0 AFA30088 */  sw    $v1, 0x88($sp)
/* 057704 7F022BD4 AFA40054 */  sw    $a0, 0x54($sp)
/* 057708 7F022BD8 0C002914 */  jal   randomGetNext
/* 05770C 7F022BDC AFA50050 */   sw    $a1, 0x50($sp)
/* 057710 7F022BE0 8FA30088 */  lw    $v1, 0x88($sp)
/* 057714 7F022BE4 8FA40054 */  lw    $a0, 0x54($sp)
/* 057718 7F022BE8 8FA50050 */  lw    $a1, 0x50($sp)
/* 05771C 7F022BEC 8478000A */  lh    $t8, 0xa($v1)
/* 057720 7F022BF0 8C790004 */  lw    $t9, 4($v1)
/* 057724 7F022BF4 24070001 */  li    $a3, 1
/* 057728 7F022BF8 0058001B */  divu  $zero, $v0, $t8
/* 05772C 7F022BFC 00004010 */  mfhi  $t0
/* 057730 7F022C00 03284821 */  addu  $t1, $t9, $t0
/* 057734 7F022C04 91260000 */  lbu   $a2, ($t1)
/* 057738 7F022C08 AFB00010 */  sw    $s0, 0x10($sp)
/* 05773C 7F022C0C 8E2A0040 */  lw    $t2, 0x40($s1)
/* 057740 7F022C10 17000002 */  bnez  $t8, .L7F022C1C
/* 057744 7F022C14 00000000 */   nop   
/* 057748 7F022C18 0007000D */  break 7
.L7F022C1C:
/* 05774C 7F022C1C AFA00018 */  sw    $zero, 0x18($sp)
/* 057750 7F022C20 0FC28423 */  jal   sub_GAME_7F0A108C
/* 057754 7F022C24 AFAA0014 */   sw    $t2, 0x14($sp)
/* 057758 7F022C28 26520004 */  addiu $s2, $s2, 4
.L7F022C2C:
/* 05775C 7F022C2C 24010008 */  li    $at, 8
/* 057760 7F022C30 1641FFAF */  bne   $s2, $at, .L7F022AF0
/* 057764 7F022C34 26730004 */   addiu $s3, $s3, 4
/* 057768 7F022C38 1000006E */  b     .L7F022DF4
/* 05776C 7F022C3C 8FBF004C */   lw    $ra, 0x4c($sp)
.L7F022C40:
/* 057770 7F022C40 2401006E */  li    $at, 110
/* 057774 7F022C44 14410027 */  bne   $v0, $at, .L7F022CE4
/* 057778 7F022C48 00003025 */   move  $a2, $zero
/* 05777C 7F022C4C 8622003A */  lh    $v0, 0x3a($s1)
/* 057780 7F022C50 3C158005 */  lui   $s5, %hi(D_8004E86C)
/* 057784 7F022C54 3C0C8005 */  lui   $t4, %hi(image_entries)
/* 057788 7F022C58 04410004 */  bgez  $v0, .L7F022C6C
/* 05778C 7F022C5C 000258C0 */   sll   $t3, $v0, 3
/* 057790 7F022C60 26B5E86C */  addiu $s5, %lo(D_8004E86C) # addiu $s5, $s5, -0x1794
/* 057794 7F022C64 10000009 */  b     .L7F022C8C
/* 057798 7F022C68 8EB00000 */   lw    $s0, ($s5)
.L7F022C6C:
/* 05779C 7F022C6C 018B6021 */  addu  $t4, $t4, $t3
/* 0577A0 7F022C70 918C9300 */  lbu   $t4, %lo(image_entries)($t4)
/* 0577A4 7F022C74 3C158005 */  lui   $s5, %hi(D_8004E86C)
/* 0577A8 7F022C78 26B5E86C */  addiu $s5, %lo(D_8004E86C) # addiu $s5, $s5, -0x1794
/* 0577AC 7F022C7C 318D000F */  andi  $t5, $t4, 0xf
/* 0577B0 7F022C80 000D7080 */  sll   $t6, $t5, 2
/* 0577B4 7F022C84 02AE7821 */  addu  $t7, $s5, $t6
/* 0577B8 7F022C88 8DF00000 */  lw    $s0, ($t7)
.L7F022C8C:
/* 0577BC 7F022C8C 0C002914 */  jal   randomGetNext
/* 0577C0 7F022C90 00000000 */   nop   
/* 0577C4 7F022C94 8618000A */  lh    $t8, 0xa($s0)
/* 0577C8 7F022C98 8E190004 */  lw    $t9, 4($s0)
/* 0577CC 7F022C9C 8ECA01D8 */  lw    $t2, 0x1d8($s6)
/* 0577D0 7F022CA0 0058001B */  divu  $zero, $v0, $t8
/* 0577D4 7F022CA4 00001810 */  mfhi  $v1
/* 0577D8 7F022CA8 03234821 */  addu  $t1, $t9, $v1
/* 0577DC 7F022CAC 91260000 */  lbu   $a2, ($t1)
/* 0577E0 7F022CB0 AFAA0010 */  sw    $t2, 0x10($sp)
/* 0577E4 7F022CB4 8E2B0040 */  lw    $t3, 0x40($s1)
/* 0577E8 7F022CB8 17000002 */  bnez  $t8, .L7F022CC4
/* 0577EC 7F022CBC 00000000 */   nop   
/* 0577F0 7F022CC0 0007000D */  break 7
.L7F022CC4:
/* 0577F4 7F022CC4 AFA00018 */  sw    $zero, 0x18($sp)
/* 0577F8 7F022CC8 26240010 */  addiu $a0, $s1, 0x10
/* 0577FC 7F022CCC 2625001C */  addiu $a1, $s1, 0x1c
/* 057800 7F022CD0 24070001 */  li    $a3, 1
/* 057804 7F022CD4 0FC28423 */  jal   sub_GAME_7F0A108C
/* 057808 7F022CD8 AFAB0014 */   sw    $t3, 0x14($sp)
/* 05780C 7F022CDC 10000045 */  b     .L7F022DF4
/* 057810 7F022CE0 8FBF004C */   lw    $ra, 0x4c($sp)
.L7F022CE4:
/* 057814 7F022CE4 8E240048 */  lw    $a0, 0x48($s1)
/* 057818 7F022CE8 0FC1B198 */  jal   sub_GAME_7F06C660
/* 05781C 7F022CEC 8E25000C */   lw    $a1, 0xc($s1)
/* 057820 7F022CF0 C7B20098 */  lwc1  $f18, 0x98($sp)
/* 057824 7F022CF4 C7A4009C */  lwc1  $f4, 0x9c($sp)
/* 057828 7F022CF8 C7AA00A0 */  lwc1  $f10, 0xa0($sp)
/* 05782C 7F022CFC E7B20070 */  swc1  $f18, 0x70($sp)
/* 057830 7F022D00 E7A40074 */  swc1  $f4, 0x74($sp)
/* 057834 7F022D04 E7AA0078 */  swc1  $f10, 0x78($sp)
/* 057838 7F022D08 C4500030 */  lwc1  $f16, 0x30($v0)
/* 05783C 7F022D0C 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 057840 7F022D10 4481A000 */  mtc1  $at, $f20
/* 057844 7F022D14 46109181 */  sub.s $f6, $f18, $f16
/* 057848 7F022D18 00408025 */  move  $s0, $v0
/* 05784C 7F022D1C 46143202 */  mul.s $f8, $f6, $f20
/* 057850 7F022D20 46089400 */  add.s $f16, $f18, $f8
/* 057854 7F022D24 E7B00070 */  swc1  $f16, 0x70($sp)
/* 057858 7F022D28 C4460034 */  lwc1  $f6, 0x34($v0)
/* 05785C 7F022D2C 46062481 */  sub.s $f18, $f4, $f6
/* 057860 7F022D30 46149202 */  mul.s $f8, $f18, $f20
/* 057864 7F022D34 46082400 */  add.s $f16, $f4, $f8
/* 057868 7F022D38 E7B00074 */  swc1  $f16, 0x74($sp)
/* 05786C 7F022D3C C4460038 */  lwc1  $f6, 0x38($v0)
/* 057870 7F022D40 46065481 */  sub.s $f18, $f10, $f6
/* 057874 7F022D44 46149102 */  mul.s $f4, $f18, $f20
/* 057878 7F022D48 46045200 */  add.s $f8, $f10, $f4
/* 05787C 7F022D4C E7A80078 */  swc1  $f8, 0x78($sp)
/* 057880 7F022D50 8E25000C */  lw    $a1, 0xc($s1)
/* 057884 7F022D54 0FC1B3A4 */  jal   getjointsize
/* 057888 7F022D58 8E240048 */   lw    $a0, 0x48($s1)
/* 05788C 7F022D5C 46140402 */  mul.s $f16, $f0, $f20
/* 057890 7F022D60 C686000C */  lwc1  $f6, 0xc($s4)
/* 057894 7F022D64 C7AA0070 */  lwc1  $f10, 0x70($sp)
/* 057898 7F022D68 46068482 */  mul.s $f18, $f16, $f6
/* 05789C 7F022D6C 46125101 */  sub.s $f4, $f10, $f18
/* 0578A0 7F022D70 E7A40070 */  swc1  $f4, 0x70($sp)
/* 0578A4 7F022D74 8E25000C */  lw    $a1, 0xc($s1)
/* 0578A8 7F022D78 0FC1B3A4 */  jal   getjointsize
/* 0578AC 7F022D7C 8E240048 */   lw    $a0, 0x48($s1)
/* 0578B0 7F022D80 46140202 */  mul.s $f8, $f0, $f20
/* 0578B4 7F022D84 C6900010 */  lwc1  $f16, 0x10($s4)
/* 0578B8 7F022D88 C7AA0074 */  lwc1  $f10, 0x74($sp)
/* 0578BC 7F022D8C 46104182 */  mul.s $f6, $f8, $f16
/* 0578C0 7F022D90 46065481 */  sub.s $f18, $f10, $f6
/* 0578C4 7F022D94 E7B20074 */  swc1  $f18, 0x74($sp)
/* 0578C8 7F022D98 8E25000C */  lw    $a1, 0xc($s1)
/* 0578CC 7F022D9C 0FC1B3A4 */  jal   getjointsize
/* 0578D0 7F022DA0 8E240048 */   lw    $a0, 0x48($s1)
/* 0578D4 7F022DA4 46140102 */  mul.s $f4, $f0, $f20
/* 0578D8 7F022DA8 C6880014 */  lwc1  $f8, 0x14($s4)
/* 0578DC 7F022DAC C7AA0078 */  lwc1  $f10, 0x78($sp)
/* 0578E0 7F022DB0 27B200B4 */  addiu $s2, $sp, 0xb4
/* 0578E4 7F022DB4 02402825 */  move  $a1, $s2
/* 0578E8 7F022DB8 02002025 */  move  $a0, $s0
/* 0578EC 7F022DBC 46082402 */  mul.s $f16, $f4, $f8
/* 0578F0 7F022DC0 46105181 */  sub.s $f6, $f10, $f16
/* 0578F4 7F022DC4 0FC16799 */  jal   matrix_4x4_7F059E64
/* 0578F8 7F022DC8 E7A60078 */   swc1  $f6, 0x78($sp)
/* 0578FC 7F022DCC 27B00070 */  addiu $s0, $sp, 0x70
/* 057900 7F022DD0 02002825 */  move  $a1, $s0
/* 057904 7F022DD4 0FC1611D */  jal   matrix_4x4_transform_vector_in_place
/* 057908 7F022DD8 02402025 */   move  $a0, $s2
/* 05790C 7F022DDC 8E240048 */  lw    $a0, 0x48($s1)
/* 057910 7F022DE0 8E250008 */  lw    $a1, 8($s1)
/* 057914 7F022DE4 8E26000C */  lw    $a2, 0xc($s1)
/* 057918 7F022DE8 0FC08877 */  jal   sub_GAME_7F0221DC
/* 05791C 7F022DEC 02003825 */   move  $a3, $s0
/* 057920 7F022DF0 8FBF004C */  lw    $ra, 0x4c($sp)
.L7F022DF4:
/* 057924 7F022DF4 D7B40028 */  ldc1  $f20, 0x28($sp)
/* 057928 7F022DF8 8FB00030 */  lw    $s0, 0x30($sp)
/* 05792C 7F022DFC 8FB10034 */  lw    $s1, 0x34($sp)
/* 057930 7F022E00 8FB20038 */  lw    $s2, 0x38($sp)
/* 057934 7F022E04 8FB3003C */  lw    $s3, 0x3c($sp)
/* 057938 7F022E08 8FB40040 */  lw    $s4, 0x40($sp)
/* 05793C 7F022E0C 8FB50044 */  lw    $s5, 0x44($sp)
/* 057940 7F022E10 8FB60048 */  lw    $s6, 0x48($sp)
/* 057944 7F022E14 03E00008 */  jr    $ra
/* 057948 7F022E18 27BD00F8 */   addiu $sp, $sp, 0xf8
)
#endif




/**
 * Removed.
 * 
 * Address 0x7F022E1C.
 */
void chrRemoved7F022E1C(f32 arg0)
{
    // removed
}



void setanimationdebugflag(s32 param_1)
{
  D_8002C904 = param_1;
  return;
}



/**
 * Decrements g_AnimationTablePointerCountRelated.
 * If less than zero, the variable will then be set to the
 * number of non-zero entries in animation_table_ptrs1.
 * 
 * Address 0x7F022E30.
 */
void chrDecrementAnimationTablePointerCount(void)
{
    g_AnimationTablePointerCountRelated--;

    if (g_AnimationTablePointerCountRelated < 0)
    {
        for (
            g_AnimationTablePointerCountRelated = 0;
            animation_table_ptrs1[g_AnimationTablePointerCountRelated+1] != 0;
            g_AnimationTablePointerCountRelated++)
        {
            // nothing to do.
        }
    }
}



/**
 * Decrements g_AnimationTablePointerCountRelated.
 * If the entry in animation_table_ptrs1 at that index is zero
 * then the global variable will be set to zero.
 * 
 * Address 0x7F022E90.
 */
void chrIncrementAnimationTablePointerCount(void)
{
    g_AnimationTablePointerCountRelated++;

    if (animation_table_ptrs1[g_AnimationTablePointerCountRelated] == 0)
    {
        g_AnimationTablePointerCountRelated = 0;
    }
}



/**
 * Address 0x7F022EC8.
 */
void chrToggleD_8002C90C(void)
{
    D_8002C90C = !D_8002C90C;
}



void sub_GAME_7F022EE0(s32 param_1){
  D_8002C910 = param_1;
}





/**
 * Iterates all guards and checks if the noise is within the hearing scale distance.
 * 
 * @param noise: noise amount to check.
 * 
 * Address 0x7F022EEC.
 */
void chrCheckGuardsHeardSound(f32 noise)
{
    s32 i;

    for (i=0; i<num_guards; i++)
    {
        if (ptr_guard_data[i].model != NULL)
        {
            if (chrGetDistanceToBond(&ptr_guard_data[i]) < ptr_guard_data[i].hearingscale * (noise * 100.0f))
            {
                chrlvAlertGuardToPlayerPosition(&ptr_guard_data[i]);
            }
        }
    }
}



/**
 * Iterates ptr_guard_data. Returns the first object that (1) model
 * is not null and (2) chrnum matches index.
 * 
 * Address 0x7F022FC8.
 * chrFindByLiteralId
 */
ChrRecord* chrFindByLiteralId(s32 index)
{
    s32 i;

    for (i=0; i<num_guards; i++)
    {
        if (ptr_guard_data[i].model != NULL && ptr_guard_data[i].chrnum == index)
        {
            return &ptr_guard_data[i];
        }
    }

    return NULL;
}



/**
 * Address 0x7F02302C.
 */
PropRecord *chrGetEquippedWeaponProp(ChrRecord *self, GUNHAND hand)
{
    return self->weapons_held[hand]; //0x160
}




/**
 * Address 0x7F02303C.
 */
PropRecord *chrGetEquippedWeaponPropWithCheck(ChrRecord *self, GUNHAND hand) 
{
    PropRecord *gunprop = self->weapons_held[hand];
    if (gunprop)
    {
        WeaponObjRecord *wep = gunprop->weapon;

        if (bondwalkItemCheckBitflags(wep->weaponnum, 0x200) == 0)
        {
            gunprop = NULL;
        }
    }
    return gunprop;
}



/**
 * Updates character collision bounds based on chracter width.
 * 
 * @param arg0: prop
 * @param arg1: out parameter, will contain character collision_bounds.
 * @param arg2: out parameter, will contain 0 or 4
 * @param y_out: out parameter, will be character ground + character height
 * @param ground: out parameter, will contain character ground
 * 
 * Address 0x7F02308C.
 */
void chrUpdateCollisionBounds(PropRecord *arg0, rect4f **arg1, s32 *arg2, f32 *y_out, f32 *ground)
{
    ChrRecord *chr;

    chr = arg0->chr;

    if (
        (chr->actiontype != ACT_DIE) &&
        (chr->actiontype != ACT_DEAD) &&
        ((chr->chrflags & (CHRFLAG_00010000 | CHRFLAG_HIDDEN)) == 0) && 
        ((chr->hidden & 0x100) == 0)
        )
    {
        *arg2 = 4;
        *arg1 = &chr->collision_bounds;

        //collision box is a diamond around chr

        chr->collision_bounds.f[0] = arg0->pos.x + chr->chrwidth;
        chr->collision_bounds.f[1] = arg0->pos.z;

        chr->collision_bounds.f[2] = arg0->pos.x;
        chr->collision_bounds.f[3] = arg0->pos.z + chr->chrwidth;

        chr->collision_bounds.f[4] = arg0->pos.x - chr->chrwidth;
        chr->collision_bounds.f[5] = arg0->pos.z;

        chr->collision_bounds.f[6] = arg0->pos.x;
        chr->collision_bounds.f[7] = arg0->pos.z - chr->chrwidth;

        *ground = chr->ground;
        *y_out = *ground + chr->chrheight;

        return;
    }

    *arg2 = 0;
}




/**
 * @param arg0: prop
 * @param width: out parameter, will be set to character width
 * @param height: out parameter, will be set to character height - 20
 * @param always_20: out parameter, will be set to 20
 * 
 * Address 0x7F023160.
 */
void chrGetChrWidthHeight(PropRecord *arg0, f32 *width, f32 *height, f32 *always_20)
{
    void *temp_v0;

    ChrRecord *c = arg0->chr;

    *width = c->chrwidth;
    *height = c->chrheight - 20.0f;
    *always_20 = 20.0f;
}



/**
 * Address 0x7F023188.
 */
f32 chrGetChrGround(PropRecord *arg0)
{
    ChrRecord *c = arg0->chr;
    return c->ground;
}



#ifdef NONMATCHING
void sub_GAME_7F023194(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F023194
/* 057CC4 7F023194 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 057CC8 7F023198 AFBF001C */  sw    $ra, 0x1c($sp)
/* 057CCC 7F02319C AFA50024 */  sw    $a1, 0x24($sp)
/* 057CD0 7F0231A0 AFA7002C */  sw    $a3, 0x2c($sp)
/* 057CD4 7F0231A4 908E0001 */  lbu   $t6, 1($a0)
/* 057CD8 7F0231A8 8C830004 */  lw    $v1, 4($a0)
/* 057CDC 7F0231AC 31CF0002 */  andi  $t7, $t6, 2
/* 057CE0 7F0231B0 51E00033 */  beql  $t7, $zero, .L7F023280
/* 057CE4 7F0231B4 00001025 */   move  $v0, $zero
/* 057CE8 7F0231B8 80620007 */  lb    $v0, 7($v1)
/* 057CEC 7F0231BC 24010004 */  li    $at, 4
/* 057CF0 7F0231C0 1041002E */  beq   $v0, $at, .L7F02327C
/* 057CF4 7F0231C4 24010005 */   li    $at, 5
/* 057CF8 7F0231C8 5041002D */  beql  $v0, $at, .L7F023280
/* 057CFC 7F0231CC 00001025 */   move  $v0, $zero
/* 057D00 7F0231D0 8C780014 */  lw    $t8, 0x14($v1)
/* 057D04 7F0231D4 33190800 */  andi  $t9, $t8, 0x800
/* 057D08 7F0231D8 57200029 */  bnezl $t9, .L7F023280
/* 057D0C 7F0231DC 00001025 */   move  $v0, $zero
/* 057D10 7F0231E0 8C64001C */  lw    $a0, 0x1c($v1)
/* 057D14 7F0231E4 3C013E80 */  li    $at, 0x3E800000 # 0.250000
/* 057D18 7F0231E8 44817000 */  mtc1  $at, $f14
/* 057D1C 7F0231EC 8C82000C */  lw    $v0, 0xc($a0)
/* 057D20 7F0231F0 44806000 */  mtc1  $zero, $f12
/* 057D24 7F0231F4 24480040 */  addiu $t0, $v0, 0x40
/* 057D28 7F0231F8 C5000038 */  lwc1  $f0, 0x38($t0)
/* 057D2C 7F0231FC C4440038 */  lwc1  $f4, 0x38($v0)
/* 057D30 7F023200 46002181 */  sub.s $f6, $f4, $f0
/* 057D34 7F023204 460E3202 */  mul.s $f8, $f6, $f14
/* 057D38 7F023208 46004280 */  add.s $f10, $f8, $f0
/* 057D3C 7F02320C 460C503C */  c.lt.s $f10, $f12
/* 057D40 7F023210 E4AA0008 */  swc1  $f10, 8($a1)
/* 057D44 7F023214 4502001A */  bc1fl .L7F023280
/* 057D48 7F023218 00001025 */   move  $v0, $zero
/* 057D4C 7F02321C C5000030 */  lwc1  $f0, 0x30($t0)
/* 057D50 7F023220 C4500030 */  lwc1  $f16, 0x30($v0)
/* 057D54 7F023224 46008481 */  sub.s $f18, $f16, $f0
/* 057D58 7F023228 460E9102 */  mul.s $f4, $f18, $f14
/* 057D5C 7F02322C 46002180 */  add.s $f6, $f4, $f0
/* 057D60 7F023230 E4A60000 */  swc1  $f6, ($a1)
/* 057D64 7F023234 C4480034 */  lwc1  $f8, 0x34($v0)
/* 057D68 7F023238 C5020034 */  lwc1  $f2, 0x34($t0)
/* 057D6C 7F02323C 46024281 */  sub.s $f10, $f8, $f2
/* 057D70 7F023240 460E5402 */  mul.s $f16, $f10, $f14
/* 057D74 7F023244 46028480 */  add.s $f18, $f16, $f2
/* 057D78 7F023248 E4B20004 */  swc1  $f18, 4($a1)
/* 057D7C 7F02324C 8FAB002C */  lw    $t3, 0x2c($sp)
/* 057D80 7F023250 24C50004 */  addiu $a1, $a2, 4
/* 057D84 7F023254 E56C0004 */  swc1  $f12, 4($t3)
/* 057D88 7F023258 E56C0000 */  swc1  $f12, ($t3)
/* 057D8C 7F02325C E4CC0000 */  swc1  $f12, ($a2)
/* 057D90 7F023260 E4CC0004 */  swc1  $f12, 4($a2)
/* 057D94 7F023264 8FAC002C */  lw    $t4, 0x2c($sp)
/* 057D98 7F023268 25870004 */  addiu $a3, $t4, 4
/* 057D9C 7F02326C 0FC0FE43 */  jal   sub_GAME_7F03F90C
/* 057DA0 7F023270 AFAC0010 */   sw    $t4, 0x10($sp)
/* 057DA4 7F023274 10000002 */  b     .L7F023280
/* 057DA8 7F023278 24020001 */   li    $v0, 1
.L7F02327C:
/* 057DAC 7F02327C 00001025 */  move  $v0, $zero
.L7F023280:
/* 057DB0 7F023280 8FBF001C */  lw    $ra, 0x1c($sp)
/* 057DB4 7F023284 27BD0020 */  addiu $sp, $sp, 0x20
/* 057DB8 7F023288 03E00008 */  jr    $ra
/* 057DBC 7F02328C 00000000 */   nop   
)
#endif



//filesplit
