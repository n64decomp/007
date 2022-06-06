#ifndef _DEBUG_PRINT_H_
#define _DEBUG_PRINT_H_

#include <ultra64.h>


#define STACK_POINTER_COUNT  5


typedef struct 
{
    u32 mask;
    u32 value;
    char *string;
} regDesc_t;

extern void *g_StackPtrs1[STACK_POINTER_COUNT];
extern void *g_StackPtrs2[STACK_POINTER_COUNT];
extern void *g_StackPtrs3[STACK_POINTER_COUNT];

void deboutWriteChar(unsigned char c);
void deboutScrollUp(s32 numlines);
void deboutInitBuffers();
void deboutDrawToBuffer(u16 *buffer);

#endif
