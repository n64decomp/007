#include "ultra64.h"

OSMesg vi_c_debug_MSG[0x8];
OSMesgQueue vi_c_debug_MQ;

/* wtf is this, should it be split? is it part of debugmenu.? */
u32 ptr_vi_c_debug_debug_notice_list[] = {
         0,         0,         0,         0,         0,         0
};

//80024518
u32 enddl_80024518[] = {       
0xB8000000,         0,
};





void start_nulled_entry(void) {
    return;
}

void something_with_vi_c_debug(void)
{
    get_ptr_debug_notice_list_entry(&ptr_vi_c_debug_debug_notice_list, "vi_c_debug");
    osCreateMesgQueue(&vi_c_debug_MQ, &vi_c_debug_MSG, 8);
}




