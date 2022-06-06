#ifndef _INDY_COMMS_H_
#define _INDY_COMMS_H_
#include <ultra64.h>

s32 indycommInit(void);
void indycommHostinit(void);
void indycommHostLoadFile(char *filename, u8 *targetloc);
void indycommHostSendDump(char *filename, u8 *data, u32 size);
void indycommHostRamRomLoad(char *filename, u8 *target, s32 size);
void indycommHostSaveFile(char *filename, s32 size, u8 * data);
u8 * indycommHostCheckFileExists(char *name, s32 *size);
u8 *indycommHostSendCmd(u8 *cmdstr);
#endif
