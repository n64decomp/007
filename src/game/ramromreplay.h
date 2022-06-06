#ifndef _RAMROMREPLAY_H_
#define _RAMROMREPLAY_H_

#include <ultra64.h>
#include "file.h"
#define INDY_RAMROM_DEMO_ADDRESS 0x00F00000

typedef struct ramromfilestructure {
    u64 randomseed;
    u64 randomizer;
    enum LEVELID stagenum;
    enum DIFFICULTY difficulty;
    u32 size_cmds;
    save_data savefile;
    f32 totaltime_ms;
    u32 filesize;
    enum GAMEMODE mode;
    u32 slotnum;
    u32 numplayers;
    u32 scenario;
    u32 mpstage_sel;
    u32 gamelength;
    u32 mp_weapon_set;
    u32 mp_char[4];
    u32 mp_handi[4];
    u32 mp_contstyle[4];
    u32 aim_option;
    u32 mp_flags[4];

} ramromfilestructure;
void test_if_recording_demos_this_stage_load(s32 arg0, s32 arg1);
s32 iterate_ramrom_entries_handle_camera_out(void);
void stop_demo_playback(void);
s32 get_is_reamrom_flag(void);
u32 check_ramrom_flags(void);

#endif

