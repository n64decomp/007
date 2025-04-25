#ifndef _TLB_PAGING_H_
#define _TLB_PAGING_H_

#include <ultra64.h>


#define STACK_POINTER_COUNT  5


typedef struct regDesc_t
{
    u32 mask;
    u32 value;
    char *string;
} regDesc_t;

extern void *g_StackPtrs1[STACK_POINTER_COUNT];
extern void *g_StackPtrs2[STACK_POINTER_COUNT];
extern void *g_StackPtrs3[STACK_POINTER_COUNT];

void crashInit(void);
void crashMain(void* arg0);

void crashAppendChar(unsigned char c);
void crashScroll(s32 numlines);
void crashInitBuffers(void);
void crashRenderFrame(u16 *buffer);



#endif
