#ifndef _FILE2_H_
#define _FILE2_H_
#include <ultra64.h>

#include <bondconstants.h>
#include <bondtypes.h>
#include "file.h"

#define RAMROM_FOLDERNUM 0x64

u8 fileGetBondForFolder(u32 folder);
void fileValidateSaves(void);
bool fileGetIsCheatUnlocked(save_data *save, s32 cheat);
s32 fileIsStageUnlockedAtDifficulty(s32 foldernum, LEVEL_SOLO_SEQUENCE stage, DIFFICULTY difficulty);
void fileUnlockStageInFolderAtDifficulty(s32 foldernum, LEVEL_SOLO_SEQUENCE stage, DIFFICULTY difficulty, s32 newtime);
void sub_GAME_7F01E760(s32 foldernum, s32 cheat);
void fileLoadSettingsForFolder(u32 folder);

#endif
