#include <ultra64.h>
#include "unk_0C0A70.h"

// data
s32 D_80048490 = -1;
s32 D_80048494 = 0;

/**
 * Appears to be rendered framerate, or some kind of counter since the last frame update.
 */
s32 speedgraphframes = 1;

#if defined(BUGFIX_R1)
// EU address D_8004111C
f32 jpD_800484CC = 1.0f;

// EU address D_80041120
f32 jpD_800484D0 = 1.0f;
#endif

s32 D_8004849C = -1;
s32 D_800484A0 = 0; // half of D_80048494
s32 D_800484A4 = 0; // is D_80048494 Odd
s32 D_800484A8 = 0; // half - D_8004849C
u32 copy_of_osgetcount_value_0 = 0;
u32 copy_of_osgetcount_value_1 = 0;
s32 D_800484B4 = 1; //usually 1




void store_osgetcount(void)
{
    copy_of_osgetcount_value_1 = osGetCount();
    copy_of_osgetcount_value_0 = copy_of_osgetcount_value_1;
}

//timing related
void sub_GAME_7F0C0AA0(s32 arg0)
{
    copy_of_osgetcount_value_0 = (s32) copy_of_osgetcount_value_1;
    copy_of_osgetcount_value_1 = osGetCount();

    D_80048490 = D_80048494;
    D_80048494 = (s32) (D_80048494 + arg0);
    speedgraphframes = arg0;

    #ifdef BUGFIX_R1
    jpD_800484CC = (f32) arg0;
    #ifdef REFRESH_PAL
    jpD_800484D0 = (jpD_800484CC * 60.0f) / 50.0f;
    #else
    jpD_800484D0 = (f32) jpD_800484CC;
    #endif
    #endif

    D_8004849C = (s32) D_800484A0;
    D_800484A0 = (s32) (D_80048494 / 2);
    D_800484A4 = (s32) (D_80048494 & 1);
    D_800484A8 = (s32) (D_800484A0 - D_8004849C);
}


void sub_GAME_7F0C0B4C(void) //maybe WaitForTick
{
  u32 uVar1; //next frame time?
  
  do {
    #ifdef REFRESH_PAL
    uVar1 = ((osGetCount() - copy_of_osgetcount_value_1) + 465525) / 931050; 
    #else
    uVar1 = ((osGetCount() - copy_of_osgetcount_value_1) + 387937) / 775875; //current time + 1/5
    #endif
  } while (uVar1 < D_800484B4);

  D_800484B4 = 1;
  sub_GAME_7F0C0AA0(uVar1);
}


void sub_GAME_7F0C0BE4(s32 arg0) {
    #ifdef LEFTOVERDEBUG
    D_800484B4 = arg0;
    #endif
}

#ifdef VERSION_EU
void eu_sub_7f0c00a4(void)
{
  
}
#endif




