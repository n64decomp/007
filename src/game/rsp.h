#ifndef _RSP_H_
#define _RSP_H_

#include <ultra64.h>

#include <sched.h>
#include <PR/gbi.h>
#include <PR/os.h>
#include <PR/sptask.h>

/**
 * This is cast to type OSMesg for a call to osSendMesg.
 * Name based on struct GFXInfo from \n64devkit\ultra\usr\src\pr\demos_old\simple\gfx.h.
 */ 
struct GfxInfo_s {
    OSScTask task;
    u32 cfb;
    u32 unk5C;
};

void rspInit(void);
void rspAllocateBuffers(void);
void rspGfxTaskStart(Gfx *firstGdl, Gfx *gdl, s32 arg2, OSMesg rspReplyMsg);

extern struct GfxInfo_s *g_gfxTaskSettingsList;

#endif
