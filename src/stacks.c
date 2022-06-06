#include <ultra64.h>

u8 sp_boot[0x10];
u8 sp_rmon[0x300];
u8 sp_idle[0x40];
u8 sp_shed[0x200];
u8 sp_main[0x8000];
u8 sp_audi[0x1000];

#if defined(LEFTOVERDEBUG)
u8 sp_debug[0x6B0];
#endif
