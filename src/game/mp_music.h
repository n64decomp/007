#ifndef _MP_MUSIC_H_
#define _MP_MUSIC_H_
#include <ultra64.h>

#include <bondconstants.h>

void             sub_GAME_7F0C1364(void);
void             sub_GAME_7F0C11FC(s32 stagenum);
void             set_missionstate(MISSION_STATE_ID arg0);
MISSION_STATE_ID get_mission_state(void);
void             reset_all_music_slots(void);
void             musicStopSlot(s32 slot);
void             musicPlaySlot(s32 slot, s32 min, s32 sec);
void sub_GAME_7F0C1340(void);
u16 sub_GAME_7F0C0BF0(void);

#endif
