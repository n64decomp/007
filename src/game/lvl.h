#ifndef _LVL_H_
#define _LVL_H_
#include "ultra64.h"
#include "bondconstants.h"

struct ramrom_struct {
    u32 *address;
    u32 unk;
};

extern s32 D_800483C4;
extern s32 clock_timer;
extern s32 global_timer;
extern f32 global_timer_delta;
extern u32 *ptr_jfont_DL;
extern s32 dword_CODE_bss_8008C264;
extern s32 dword_CODE_bss_8008C268;
extern s32 dword_CODE_bss_8008C26C;
extern char ramrom_data_target[0x380];
extern s32 record_slot_num;
extern s32 *address_demo_loaded;
extern s32 dword_CODE_bss_8008C5F8;

void lvInitDebugNoticeList(void);
Gfx * sub_GAME_7F0BE30C(Gfx *);
void set_difficulty(s32 arg0);
void manage_mp_game(void);
void sub_GAME_7F0BF800(void);
void unload_stage_text_data(void);
DIFFICULTY get_current_difficulty(void);
void stage_load(s32 arg0);

#endif
