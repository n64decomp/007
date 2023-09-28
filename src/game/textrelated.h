#ifndef _TEXTRELATED_H_
#define _TEXTRELATED_H_
#include <ultra64.h>
#include "bondtypes.h"

extern s32 ptrFontBankGothic;
extern s32 ptrFontBankGothicChars;
extern s32 ptrFontZurichBold;
extern s32 ptrFontZurichBoldChars;

void textrelatedInit_REMOVED(void);
void load_font_tables(void);

struct fontchar {
    u32 index;
    s32 baseline;
    u32 height;
    u32 width;
    s32 kerningindex;
    u8 *pixeldata;
};

struct font {
	s32 kerning[13 * 13];
	struct fontchar chars[94]; // can be 135 in PAL
};

Gfx * microcode_constructor_related_to_menus(Gfx *, s32, s32, s32, s32, s32);
void textMeasure(s32 *textheight, s32 *textwidth, char *text, struct fontchar *font1, struct font *font2, s32 lineheight);

Gfx *microcode_constructor(Gfx *gdl);
Gfx *textRender(Gfx *gdl, s32 *x, s32 *y, char *text, s32 second_font_table, s32 first_font_table, s32 arg6, s16 view_x, s16 view_y, s32 arg9, s32 arga);
Gfx *textRenderGlow(Gfx *gdl, s32 *x, s32 *y, s8 *text, s32 second_font_table, s32 first_font_table, s32 arg6, u32 arg7, s16 view_x, s16 view_y, s32 arga, s32 argb);

Gfx *combiner_bayer_lod_perspective(Gfx *gdl);
void setTextSpacingInverted(s32 spacing);
void setTextWordWrap(s32 flag);
void sub_GAME_7F0AEB64(s32 arg0, s8 *arg1, s8 *arg2, struct fontchar *arg3, struct font *arg4);
void setTextOverlapCorrection(s32 flag);

#endif
