#ifndef _VI_H_
#define _VI_H_
#include <ultra64.h>

extern OSMesg vi_c_debug_MSG[0x8];
extern OSMesgQueue vi_c_debug_MQ;

extern u32 viDLEnd[];

void viDebugRemoved(void);
void viInit(void);

#endif
