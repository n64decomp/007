#ifndef _TEXTRELATED_H_
#define _TEXTRELATED_H_
#include <ultra64.h>
#include "bondtypes.h"

extern s32 ptrFirstFontTableSmall;
extern s32 ptrSecondFontTableSmall;
extern s32 ptrFirstFontTableLarge;
extern s32 ptrSecondFontTableLarge;

void textrelatedInit_REMOVED(void);
void load_font_tables(void);

Gfx * microcode_constructor_related_to_menus(Gfx *, s32, s32, s32, s32, s32);
void sub_GAME_7F0AE98C(s32 *y2, s32 *x2, u8 *text, s32 ptrSecondFontTableLarge, s32 ptrFirstFontTableLarge, s32 unk5);

Gfx *microcode_constructor(Gfx *gdl);
Gfx *en_text_write_stuff(Gfx *gdl, s32 *x, s32 *y, char *text, s32 second_font_table, s32 first_font_table, s32 arg6,           s16 view_x, s16 view_y, s32 arg9, s32 arga);
Gfx *jp_text_write_stuff(Gfx *gdl, s32 *x, s32 *y,   s8 *text, s32 second_font_table, s32 first_font_table, s32 arg6, u32 arg7, s16 view_x, s16 view_y, s32 arga, s32 argb);

#endif
