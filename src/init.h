#ifndef _INIT_H_
#define _INIT_H_
#include <ultra64.h>

extern OSThread rmonThread;
extern OSThread idleThread;
extern OSThread mainThread;
extern OSThread shedThread;
extern OSMesgQueue gfxFrameMsgQ;
extern OSMesg gfxFrameMsgBuf[32];
extern OSMesgQueue *sched_cmdQ;

extern u32 unknown_init_val;
extern u32 cart_hw_address;

typedef struct {
	unsigned int inst1;
	unsigned int inst2;
	unsigned int inst3;
	unsigned int inst4;
} __exceptionVector;

typedef struct debug_handler_entry
{
  void *address;
  char *ptr_name;
} debug_handler_entry;

void init(void);
void *set_stack_entry(u8 *stack, u32 size);
void set_hw_address_and_unknown(void);
void setuplastentryofdebughandler(void);

#endif
