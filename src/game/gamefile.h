#ifndef _GAMEFILE_H_
#define _GAMEFILE_H_
#include "ultra64.h"
//i am not "correct", i need proper fields for times again
struct save_data
{
  int chksum1;
  int chksum2;
  char completion_bitflags;
  char flag_007;
  char music_vol;
  char sfx_vol;
  short options;
  char unlocked_cheats_1;
  char unlocked_cheats_2;
  char unlocked_cheats_3;
  char padding;
    u8 time_dam_agent[5];
    u8 field_0x17[5];
    u8 field_0x1c[5];
    u8 field_0x21[5];
    u8 field_0x26[5];
    u8 field_0x2b[5];
    u8 field_0x30[5];
    u8 field_0x35[5];
    u8 field_0x3a[5];
    u8 field_0x3f[5];
    u8 field_0x44[5];
    u8 field_0x49[5];
    u8 field_0x4e[5];
    u8 field_0x53[5];
    u8 field_0x58[5];
    u8 field_0x5d[3];

};

u8 removed_would_have_returned_bond_for_folder_num(u32 folder);

#endif
