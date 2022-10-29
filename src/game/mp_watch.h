#ifndef _MP_WATCH_H_
#define _MP_WATCH_H_
#include <ultra64.h>

typedef enum TEXTCOLORS {
    GREEN_NORMAL=0,
    GREEN_HIGHLIGHT,
    RED_NORMAL,
    RED_HIGHLIGHT,
    BLUE_NORMAL,
    BLUE_HIGHLIGHT
} TEXTCOLORS;

struct AwardMetrics {
	s32 num_shots;                    // 0x00
	s32 num_headshots;                // 0x04
	s32 num_kills;                    // 0x08
	s32 num_deaths;                   // 0x0c
	s32 num_suicides;                 // 0x10
	f32 ks_ratio;                     // 0x14
	f32 kd_ratio;                     // 0x18
	s32 damage_to_backside;           // 0x1c
	s32 time_other_players_on_screen; // 0x20
	f32 avg_km_per_hour;              // 0x24
	f32 body_armor_pickups;           // 0x28
	u32 awards;                       // 0x2c
	s32 longest_inning;               // 0x30
	s32 shortest_inning;              // 0x34
};

s32 mpFindMaxInt(int param_1, int param_2, int param_3, int param_4, int param_5);

s32 mpFindMinInt(int param_1, int param_2, int param_3, int param_4, int param_5);

void mpwatchUnpauseGame(void);
Gfx *display_text_for_playerdata_on_MP_menu(Gfx *gdl, s32 x, s32 y, u16* arg3, TEXTCOLORS text_color);

s32 checkGamePaused(void);

void mpCalculateAwards(int arg0);
s32 get_points_for_mp_player(s32 arg0);
void mpwatchSetStopPlayFlag(void);
Gfx * mp_watch_menu_display(Gfx *arg0);

#endif
