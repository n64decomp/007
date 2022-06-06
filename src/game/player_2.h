#ifndef _PLAYER_2_H_
#define _PLAYER_2_H_
#include <ultra64.h>
#include <bondtypes.h>

s32 getPlayerCount(void);
s32 get_cur_playernum(void);
void set_cur_player_fovy(f32 fovy);
s32 sub_GAME_7F09B15C( PropRecord* prop);
void set_cur_player_aspect(f32 aspect);

#endif
