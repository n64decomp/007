#include "ultra64.h"
#include "gbi.h"

OSMesg vi_c_debug_MSG[0x8];
OSMesgQueue vi_c_debug_MQ;

/* wtf is this, should it be split? is it part of debugmenu.? */
u32 viDebugNoticeList[] = 
{
    0, 0, 0,
    0, 0, 0
};

//80024518
u32 viDLEnd[] = {       
    0xB8000000,0x00000000,
};
//Gfx viDLEnd[] = {
//	gsSPEndDisplayList()
//};



void viDebugRemoved(void) {
    return;
}

void viInitDebugNoticeList(void)
{
    debCheckAddDebugNoticeListEntry(&viDebugNoticeList, "vi_c_debug");
    osCreateMesgQueue(&vi_c_debug_MQ, &vi_c_debug_MSG, 8);
}




