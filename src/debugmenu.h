#ifndef _DEBUGMENU_H_
#define _DEBUGMENU_H_

#include <ultra64.h>

void debmenu7000ADA8(void);
void debmenuInit(void);
void debmenuReset(void);
void debmenuSetPosition(s32 x, s32 y);
void debmenuSetPrimColor(s32 r, s32 g, s32 b, s32 a);
void debmenuSetEnvColor(s32 r, s32 g, s32 b, s32 a);
void debmenuWriteString(const unsigned char *str);
Gfx *debmenuDraw(Gfx *gdl);

#endif
