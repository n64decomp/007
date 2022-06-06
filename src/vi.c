#include <ultra64.h>
#include <PR/gbi.h>
#include <deb.h>
/**
 * EU .data, offset from start of data_seg : 0x3740
*/

#if defined(VERSION_EU)
s32 eu_D_80022330 = 0;

#endif

OSMesg vi_c_debug_MSG[0x8];
OSMesgQueue vi_c_debug_MQ;

/* wtf is this, should it be split? is it part of debugmenu.? */
u32 viDebugNoticeList[] = 
{
    0, 0, 0,
    0, 0, 0
};


#ifndef VERSION_EU
//80024518
Gfx viDLEnd[] = {
	gsSPEndDisplayList()
};
#endif


void viDebugRemoved(void) {
    return;
}

void viInitDebugNoticeList(void)
{
#if defined(VERSION_EU)
    debTryAdd(&eu_D_80022330, "vi_c_debug");
#else
    debTryAdd(&viDebugNoticeList, "vi_c_debug");
#endif
    osCreateMesgQueue(&vi_c_debug_MQ, &vi_c_debug_MSG, 8);
}




