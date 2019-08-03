#ifndef _DEBUG_PRINT_H_
#define _DEBUG_PRINT_H_

#include "ultra64.h"

//im just padding
extern u32 D_80023300;

struct debug_processor_error_entry
{
  u32 val1;
  u32 val2;
  void *string;
};

extern struct debug_processor_error_entry debug_processor_error_table[];
void *stack_ptrs_1[];
void *stack_ptrs_2[];
void *stack_ptrs_3[];
char stderr_buffer[2280];

#endif
