#ifndef _VIEWPORT_H_
#define _VIEWPORT_H_

#include <ultra64.h>

#include <PR/gbi.h>

Gfx *zbufClearCurrentPlayer(Gfx *gdl);
Gfx *zbufInit(Gfx *gdl);

void zbufDeallocate(void);

#endif
