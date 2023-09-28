#ifndef _debugmenu_handler_H_
#define _debugmenu_handler_H_
#include <ultra64.h>

struct mcm_layout {
    int xpos;
    int ypos;
};



extern s32 g_DebugMode;
extern s32 g_DebugHighlightedOption;

extern s32 show_debug_menu_flag;

s32 get_debug_render_raster(void);
s32 get_debug_freeze_processing(void);
s32 getDebugMode(void);
void setDebugMode(void);
s32 get_memusage_display_flag(void);
s32 get_debug_do_draw_bg(void);
s32 get_debug_do_draw_obj(void);
s32 get_debug_stanhit_flag(void);
s32 get_debug_stanregion_flag(void);
s32 get_debug_stan_problems_flag(void);
s32 get_debug_man_pos_flag(void);
s32 get_debug_testingmanpos_flag(void);
void set_debug_testingmanpos_flag(s32 flag);
s32 get_debug_joy2skyedit_flag(void);
s32 get_debug_joy2hitsedit_flag(void);
s32 get_debug_joy2detailedit_flag(void);
s32 get_debug_explosioninfo_flag(void);
s32 debugIsRoomStateDebugEnabled(void);
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
Gfx * debugmenuRender(Gfx *);
s32 debug_menu_processor(s8 stick_h, s8 stick_v, u16 button_held, u16 button_pressed);
void debugmenuUpdate(void);

#endif
