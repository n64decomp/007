#ifndef _DEBUGMENU_090490_H_
#define _DEBUGMENU_090490_H_
#include "ultra64.h"

struct mcm_layout {
    int xpos;
    int ypos;
};

s32 get_debug_render_raster(void);
s32 get_debug_freeze_processing(void);
s32 get_debug_limit_controller_input(void);
void set_debug_limit_controller_input(void);
s32 get_memusage_display_flag(void);
s32 get_debug_do_draw_bg(void);
s32 get_debug_do_draw_obj(void);
s32 get_debug_stanhit_flag(void);
s32 get_debug_stanregion_flag(void);
s32 get_turbo_mode_flag(void);
s32 get_debug_man_pos_flag(void);
s32 get_debug_testingmanpos_flag(void);
void set_debug_testingmanpos_flag(s32 flag);
s32 get_debug_joy2skyedit_flag(void);
s32 get_debug_joy2hitsedit_flag(void);
s32 get_debug_joy2detailedit_flag(void);
s32 get_debug_explosioninfo_flag(void);
s32 get_debug_prroomloads_flag(void);
s32 get_debug_VisCVG_flag(void);
void set_debug_VisCVG_flag(s32 flag);
s32 get_debug_007_unlock_flag(void);
s32 get_debug_enable_agent_levels_flag(void);
s32 get_debug_enable_all_levels_flag(void);
s32 get_debug_fast_bond_flag(void);
void set_debug_fast_bond_flag(s32 flag);
s32 get_debug_all_obj_complete_flag(void);
s32 get_debug_portal_flag(void);
s32 get_debug_chrnum_flag(void);
s32 get_debug_gunwatchpos_flag(void);
s32  get_debug_profile_flag(void);
s32 get_debug_taskgrab_val(void);
void debug_menu_processor(void);
#endif
