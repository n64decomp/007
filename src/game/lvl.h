#ifndef _LVL_H_
#define _LVL_H_
#include "ultra64.h"

struct ramrom_struct {
    u32 *address;
    u32 unk;
};

extern s32 D_800483C4;

extern u32 *ptr_jfont_DL;
extern s32 dword_CODE_bss_8008C264;
extern s32 dword_CODE_bss_8008C268;
extern s32 dword_CODE_bss_8008C26C;
extern char ramrom_data_target[0x380];
extern s32 record_slot_num;
extern s32 *address_demo_loaded;
extern s32 dword_CODE_bss_8008C5F8;

#endif
