#ifndef _LVL_H_
#define _LVL_H_
#include <ultra64.h>
#include <bondconstants.h>

#define DEFAULT_AGENT_AI_ACCURACY_MODIFIER 0.6f
#define DEFAULT_AGENT_AI_DAMAGE_MODIFIER 0.5f
#define DEFAULT_AGENT_SOLO_AMMO_MULTIPLIER 2.0f
#define DEFAULT_AGENT_AI_REACTION_SPEED 0.2f

#define DEFAULT_SECRET_AGENT_AI_ACCURACY_MODIFIER 0.75f
#define DEFAULT_SECRET_AGENT_AI_DAMAGE_MODIFIER 0.75f
#define DEFAULT_SECRET_AGENT_SOLO_AMMO_MULTIPLIER 1.5f
#define DEFAULT_SECRET_AGENT_AI_REACTION_SPEED 0.5f

#define DEFAULT_00_AGENT_AI_ACCURACY_MODIFIER 1.0f
#define DEFAULT_00_AGENT_AI_DAMAGE_MODIFIER 1.0f
#define DEFAULT_00_AGENT_SOLO_AMMO_MULTIPLIER 1.0f
#define DEFAULT_00_AGENT_AI_REACTION_SPEED 1.0f

#define DEFAULT_007_AI_ACCURACY_MODIFIER DEFAULT_00_AGENT_AI_ACCURACY_MODIFIER
#define DEFAULT_007_AI_DAMAGE_MODIFIER DEFAULT_00_AGENT_AI_DAMAGE_MODIFIER
#define DEFAULT_007_SOLO_AMMO_MULTIPLIER DEFAULT_00_AGENT_SOLO_AMMO_MULTIPLIER
#define DEFAULT_007_AI_REACTION_SPEED DEFAULT_00_AGENT_AI_REACTION_SPEED

struct ramrom_struct {
    u32 *address;
    u32 locked;
};

struct LvlMpUnknown {
    u8 unk_0;
    u8 unk_1;
    u8 unk_2;
    u8 unk_3;
};

extern s32 D_800483C4;
extern struct LvlMpUnknown *D_800483C8;

extern s32 g_ClockTimer;
extern s32 g_GlobalTimer;
extern f32 g_GlobalTimerDelta;
extern s32 D_80048380;
extern u32 *ptr_font_DL;
extern s32 dword_CODE_bss_8008C264;
extern s32 dword_CODE_bss_8008C268;
extern s32 dword_CODE_bss_8008C26C;
extern char ramrom_data_target[0x380];
extern s32 record_slot_num;
extern s32 address_demo_loaded;
extern s32 dword_CODE_bss_8008C5F8;

#if defined(BUGFIX_R1)
extern f32 g_JP_GlobalTimerDelta;
#endif

void lvInitDebugNoticeList(void);
Gfx * lvlRender(Gfx *);
void lvlSetSelectedDifficulty(DIFFICULTY arg0);
void lvlManageMpGame(void);
void lvlUpdateMpPlayerData(void);
void lvlUnloadStageTextData(void);
DIFFICULTY lvlGetSelectedDifficulty(void);
void lvlStageLoad(s32 stage);

void lvlSetMpTime(s32 arg0);
void lvlSetMpPoint(s32 arg0);
void lvlSetControlsLockedFlag(s32 arg0);
s32 lvlGetControlsLockedFlag(void);
void lvlSetMultipliersForDifficulty(void);
s32 lvlGetCurrentStageToLoad(void);
s32        sub_GAME_7F0BD8F0(void);
f32        lvlGetCurrentMultiPlayerSec(void);
f32        lvlGetCurrentMultiPlayerMin(void);

#endif
