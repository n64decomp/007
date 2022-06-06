#ifndef _PLAYER_H_
#define _PLAYER_H_
#include <ultra64.h>
#include <bondconstants.h>
#include <bondtypes.h>
#include "bondview.h"

struct player_data {
    /* 0x0 */
    s32 shot_count[7];

    /* 0x1c */
    int kill_count;

    /* 0x20 */
    int killed_gg_owner_count;

    /* 0x24 */
    int killed_p1;

    /* 0x28 */
    int killed_p2;

    /* 0x2c */
    int killed_p3;

    /* 0x30 */
    int killed_p4;

    /* 0x34 */
    int time_other_players_on_screen;

    /* 0x38 */
    float distance_traveled;

    /* 0x3c */
    int damage_to_backside;

    /* 0x40 */
    float body_armor_pickups;

    /* 0x44 */
    int min_time_between_kills;

    /* 0x48 */
    int max_time_between_kills;

    /* 0x4c */
    int longest_inning;

    /* 0x50 */
    s32 shortest_inning;

    /* 0x54 */
    int most_killed_one_life;

    /* 0x58 */
    int most_killed_one_time;

    /* 0x5c */
    float handicap;

    /* 0x60 */
    int flag_counter;

    /* 0x64 */
    float player_perspective_height;

    /* 0x68 */
    u8 order_out_in_yolt;

    /* 0x69 */
    u8 have_token_or_goldengun;

    /* 0x6a */
    u8 autoaim;

    /* 0x6b */
    u8 sight;

    /* 0x6c */
    int killed_civilians;
};

extern struct player *g_playerPointers[4];

// extern struct player_data player1_player_data;
// extern struct player_data player2_player_data;
// extern struct player_data player3_player_data;
// extern struct player_data player4_player_data;

extern struct player_data g_playerPlayerData[4];

extern struct player *g_CurrentPlayer;
extern struct player_data *g_playerPerm;
extern s32 player_num;
extern s32 random_byte;
extern PLAYER_ID array_PLAYER_IDs[4];


void reset_play_data_ptrs(void);
void init_player_data_ptrs_construct_viewports(int playercount);
void shuffle_player_ids(void);
s32 get_nth_player_from_shuffled(PLAYER_ID id);
void set_cur_player(s32 playernum);
s32 getPlayerCount(void);
void set_cur_player_screen_size(u32 width, u32 height);
void set_cur_player_viewport_size(u32 ulx, u32 uly);
void store_stagenum_to_copyof_stagenum(s32 stagenum);
void sub_GAME_7F094438(void);
Gfx * sub_GAME_7F094488(Gfx *arg0);

#endif
