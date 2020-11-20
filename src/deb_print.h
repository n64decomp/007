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
extern void *stack_ptrs_1[];
extern void *stack_ptrs_2[];
extern void *stack_ptrs_3[];
extern char stderr_buffer[2280];

void write_stderr_to_buffer(u32 *buffer);
#endif
