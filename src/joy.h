#ifndef _JOY_H_
#define _JOY_H_

#include "ultra64.h"
void *joyInitDebugNoticeList(void);
s32 get_attached_controller_count(void);
s32 get_controller_buttons_pressed(s32 arg0, s32 arg1);

#endif
