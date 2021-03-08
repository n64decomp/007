#ifndef _RAMROMREPLAY_H_
#define _RAMROMREPLAY_H_

#include "ultra64.h"

void test_if_recording_demos_this_stage_load(s32 arg0, s32 arg1);
s32 iterate_ramrom_entries_handle_camera_out(void);
void stop_demo_playback(void);
s32 get_is_reamrom_flag(void);

#endif

