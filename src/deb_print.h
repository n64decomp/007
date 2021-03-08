#ifndef _DEBUG_PRINT_H_
#define _DEBUG_PRINT_H_

#include "ultra64.h"

typedef struct 
{
  u32 mask;
  u32 value;
  char *string;
} regDesc_t;

extern void *g_StackPtrs1[];
extern void *g_StackPtrs2[];
extern void *g_StackPtrs3[];

void deboutWriteChar(unsigned char c);
void deboutScrollUp(s32 numlines);
void deboutInitBuffers();
void deboutDrawToBuffer(u16 *buffer);

#endif
