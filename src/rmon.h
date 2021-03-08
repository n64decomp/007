#ifndef _RMON_H_
#define _RMON_H_
#include <ultra64.h>

void rmonMain(void);
s32 rmonIsFinalBuild(void);
s32 rmon7000CEB0(void);
void rmon7000CEB8(void);
void rmon7000CEC0(void);
s32 osSyncPrintf(const char *fmt, ...);

#endif
