#ifndef _INDY_COMMS_H_
#define _INDY_COMMS_H_
#include "ultra64.h"

s32 init_indy_if_not_ready(void);
void init_indy_if_ready(void);
void load_resource_on_indy(u8 *filename, u8 *targetloc);
void indy_send_capture_data(u8 *filename, u8 *data, u32 size);
void indy_load_ramrom_file(u8 *filename, u8 *target, s32 size);
void check_file_exported(u8 *filename, s32 size, u8 * data);
u8 * check_file_found_on_indy(u8 *name, s32 *size);
//u8 *send_command_string(u8 *cmdstr);
#endif
