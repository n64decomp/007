#ifndef _RSP_H_
#define _RSP_H_
#include "ultra64.h"

void rspInitDebugNoticeList(void);
void *load_rsp_microcode(Gfx *arg0, Gfx *arg1, s32 arg2, s32 *arg3);

extern u32 **fast3d_related_array;

#endif
