#include <ultra64.h>
#include <bondconstants.h>
#include "debugmenu_handler.h"
#include "joy.h"
#include "player.h"
#include "watch.h"
#include "file.h"
#include "file2.h"
#include "front.h"



// bss
//CODE.bss:80069920
//CODE.bss:80069980
//CODE.bss:800699E0
//CODE.bss:80069A40
//CODE.bss:80069AA0
//CODE.bss:80069B00
save_data saves[6];

//CODE.bss:80069B60
u32 dword_CODE_bss_80069B60;

//data
//D:8002C510
s32 save_selected_bond[] = {0,0,0,0};

//D:8002C520
save_data D_8002C520 = {0, 0, 0x80, 0x00, 0xFF, 0xFF, DEFAULT_OPTIONS, 0x00, 0x00, 0, 0, 0, 0, 0};
//D:8002C580
// Default Save
save_data D_8002C580 = {0, 0, 0x80, 0x00, 0xFF, 0xFF, DEFAULT_OPTIONS, 0x00, 0x00, 0, 0, 0, 0, 0};
//D:8002C5E0
save_data D_8002C5E0 = {0, 0, 0x80, 0x00, 0xFF, 0xFF, DEFAULT_OPTIONS, 0x00, 0x00, 0, 0, 0, 0, 0};
//D:8002C640
smallSave blankSmallSave = {0, 0, 0x42};

//D:8002C660
save_data D_8002C660 = {0, 0, 0x80, 0x00, 0xFF, 0xFF, DEFAULT_OPTIONS, 0x00, 0x00, 0, 0, 0, 0, 0};

//D:8002C6C0
save_data D_8002C6C0 = {0, 0, 0x80, 0x00, 0xFF, 0xFF, DEFAULT_OPTIONS, 0x00, 0x00, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
//D:8002C720
save_data D_8002C720 = {0, 0, 0x80, 0x00, 0xFF, 0xFF, DEFAULT_OPTIONS, 0x00, 0x00, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
//D:8002C780
save_data D_8002C780 = {0, 0, 0x80, 0x00, 0xFF, 0xFF, DEFAULT_OPTIONS, 0x00, 0x00, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
//D:8002C7E0
save_data D_8002C7E0 = {0, 0, 0x80, 0x00, 0xFF, 0xFF, DEFAULT_OPTIONS, 0x00, 0x00, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
//D:8002C840
save_data D_8002C840 = {0, 0, 0x80, 0x00, 0xFF, 0xFF, DEFAULT_OPTIONS, 0x00, 0x00, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
//D:8002C8A0
save_data blank_eeprom = {0, 0, 0x80, 0x00, 0xFF, 0xFF, DEFAULT_OPTIONS, 0x00, 0x00, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};


/**
 *
 *
 * @return s32
 */
s32 fileGamePakProbe(void)
{
  return joyGamePakProbe();
}

/**
 * Resets the RamRom replay folder save
 *
 */
void fileResetRamRomSave(void)
{
    save_data new_save = D_8002C520;

    saves[5] = new_save;
}

/**
 *
 *
 * @param save
 */
void fileWriteSmallSave(smallSave *save)
{
    if (fileGamePakProbe() != 0)
    {
        fileGenerateCRC(&save->unk[0], &save->unk[24], save);
        joyGamePakLongWrite(0, save, sizeof(smallSave));
    }
}

/**
 *
 *
 * @param save
 */
void fileWriteSave(save_data *save)
{
    if (save >= &saves[0] && save < &saves[5])
    {
        if ( fileGamePakProbe() != 0)
        {
            fileGenerateCRC(&save->completion_bitflags, save + 1, save);
            joyGamePakLongWrite((((u32)((save - &saves[0]) * 0x60) >> 3) + 4), save, sizeof(save_data));
        }
    }
}

/**
 * reset save to default
 *
 * @param save
 */
void fileResetSave(save_data *save)
{
    save_data new_save  = D_8002C580;

    *save = new_save;
    fileWriteSave(save);
}

/**
 * Get the folder of save
 *
 * @param save
 * @return u32
 */
u32 fileGetSaveFolder(save_data *save)
{
  return save->completion_bitflags & 7;
}

/**
 * Clear then set save folder flag
 *
 * @param save
 * @param folder
 */
void fileSetSaveFoldernum(save_data *save, u32 folder)
{
    save->completion_bitflags &= ~7;
    save->completion_bitflags |= folder & 7;
}

/**
 * Set save flag 0x18
 *
 * @param folder
 * @return u32
 */
u32 fileSetSaveFlag_0x18(save_data *folder)
{
  return (folder->completion_bitflags & 0x18) >> 3;
}

/**
 * Resets save flag 0x18
 *
 * @param folder
 * @param arg1
 */
void fileResetSaveFlag_0x18(save_data *folder, s32 arg1)
{
    folder->completion_bitflags &= ~0x18;
    folder->completion_bitflags |= ((arg1 * 8) & 0x18);
}

/**
 * Get the selected bond save flag
 *
 * @param folder
 * @return u32
 */
u32 fileGetSelectedBond(save_data *folder)
{
  return (folder->completion_bitflags & 0x60) >> 5;
}

/**
 * Set the selected bond save flag
 *
 * @param folder
 * @param arg1
 */
void fileSetSelectedBond(save_data *folder, s32 arg1)
{
    folder->completion_bitflags &= ~0x60;
    folder->completion_bitflags |= ((arg1 << 5) & 0x60);
}

/**
 * Check if save has flag 0x80
 *
 * @param folder
 * @return TRUE/FALSE
 */
bool fileGetSaveFlag_0x80(save_data *folder)
{
  return ((folder->completion_bitflags & 0x80) != 0);
}

/**
 * Toggle save flag 0x80
 * possibly wear levelling
 *
 * @param folder: folder to enable or disable flag
 * @param set: Enable flag if TRUE, Disable flag if FALSE
 */
void fileSetSaveFlag_0x80(save_data *folder, bool enable)
{
    if (enable)
    {
        folder->completion_bitflags |= 0x80;
    }
    else
    {
        folder->completion_bitflags &= ~0x80;
    }
}

/**
 * Get completion time for stage at difficulty
 *
 * @param save
 * @param stagenum
 * @param difficulty
 * @return best time for stage at difficulty
 */
s32 fileGetSaveStageDifficultyTime(save_data* save, LEVEL_SOLO_SEQUENCE stagenum, DIFFICULTY difficulty)
{
    s32 offset;
    LEVEL_SOLO_SEQUENCE max_level;
    u32 time;
    s32 index;

    max_level = SP_LEVEL_MAX;
    if ((stagenum >= SP_LEVEL_DAM) && (stagenum < SP_LEVEL_MAX ) && (difficulty >= DIFFICULTY_AGENT) && (difficulty < DIFFICULTY_MAX))
    {
        if (difficulty == DIFFICULTY_007)
        {
            if ( fileIs007ModeUnlocked( fileGetSaveFolder(save)))
            {
                return 0x3FF; //max time
            }
            return 0;
        }

        offset = ((difficulty * max_level) + stagenum) * 10; //startbit
        index = (offset >> 3);

        switch(7 - (offset & 7)) //bitmask
        {
            case 7: //no offset
                // first 10 bits 8 + 2                    1111 1111                                      1100 0000
                time = ((save->times[index] & 0xFF) << 2) | ((save->times[index + 1] & 0xc0) >> 6);
                break;
            case 5: //offset 2
                // next 10 bits 6 + 4                     0011 1111                                      1111 0000
                time =  ((save->times[index] & 0x3f) << 4) | ((save->times[index + 1] & 0xf0) >> 4);
                break;
            case 3: //offset 4
                // next 10 bits 4 + 6                     0000 1111                                      1111 1100
                time =  ((save->times[index] & 0xf) << 6) | ((save->times[index + 1] & 0xfc) >> 2);
                break;
            case 1: //offset 6
                // next 10 bits 2 + 8                     0000 0011                                      1111 1111
                time = ((save->times[index] & 0x3)  << 8) | ((save->times[index + 1] & 0xFFF));
                break;
            default:
                time = 0; // shouldnt reach
#if DEBUG
                osSyncPrintf("file.c: SHOULDN\'T GET HERE EVER [1]\n");
#endif
        }

        return time;
    }

    return 0;
}

/**
 * Set completion time for stage at difficulty
 *
 * @param save
 * @param stage
 * @param difficulty
 * @param newtime
 */
void fileSetDifficultyStageTime(save_data *save, LEVEL_SOLO_SEQUENCE stage, DIFFICULTY difficulty, s32 newtime)
{
    s32 offset;
    s32 index;
    u32 max_level;

    max_level = SP_LEVEL_MAX;
    if ((stage >= 0) && (stage < SP_LEVEL_MAX ) && (difficulty >= DIFFICULTY_AGENT) && (difficulty < DIFFICULTY_007))
    {
        if (newtime == 0) {
            newtime = 0x4f;
        } else if (newtime > 0x3ff) {
            newtime = 0x3ff;
        }

        offset = ((difficulty * max_level) + stage) * 10; //startbit
        index = (offset >> 3);

        switch(7 - (offset & 7)) //bitmask
        {
            case 7: //no offset 4 8 12 etc
                save->times[index] &= 0xff00;
                save->times[index + 1] &= 0xff3f;
                save->times[index] |= (newtime >> 2) & 0xff;
                save->times[index + 1] |= (newtime << 6) & 0xc0;
                break;
            case 5: //first offset 5 9 13 etc
                save->times[index] &= 0xffc0;
                save->times[index + 1] &= 0xff0f;
                save->times[index] |= ((newtime >> 4) & 0x3f);
                save->times[index + 1] |= (newtime << 4) & 0xf0;
                break;
            case 3: //second offset 6 10 14 etc
                save->times[index] &= 0xfff0;
                save->times[index + 1] &= 0xff03;
                save->times[index] |= ((newtime >> 6) & 0xf);
                save->times[index + 1] |= (newtime << 2) & 0xfC;
                break;
            case 1: //third offset 7 11 15 etc
                save->times[index] &= 0xfffc;
                save->times[index + 1] &= 0xff00;
                save->times[index] |= ((newtime >> 8) & 3);
                save->times[index + 1] |= newtime & 0xfff;
                break;
            default:
#if DEBUG
                osSyncPrintf("file.c: SHOULDN\'T GET HERE EVER [1]\n");
#endif
                break;
        }
    }
}


/**
 * Check if stage is completed at difficulty for save
 *
 * @param folder
 * @param levelid
 * @param difficulty
 * @return is stage at diffiuclty completed
 */
bool fileGetSaveStageCompletedForDifficulty(save_data *folder, s32 levelid, DIFFICULTY difficulty)
{
    if ((levelid >= 0) && (levelid < SP_LEVEL_MAX) && (difficulty >= DIFFICULTY_AGENT) && (difficulty <= DIFFICULTY_007))
    {
        return fileGetSaveStageDifficultyTime(folder, levelid, difficulty) != 0;
    }

    return FALSE;
}

/**
 * Updates time for stage at difficulty if better
 *
 * @param folder
 * @param levelid
 * @param difficulty
 * @param arg4
 */
void fileCheckSaveStageDifficultyTime(save_data *folder, LEVEL_SOLO_SEQUENCE stage, DIFFICULTY difficulty, s32 newtime)
{
    if ((stage >= 0) && (stage < SP_LEVEL_MAX) && (difficulty >= DIFFICULTY_AGENT) && (difficulty <= DIFFICULTY_007))
    {
        s32 time = fileGetSaveStageDifficultyTime(folder, stage, difficulty);

        if ((time == 0) || (newtime < time))
        {
            fileSetDifficultyStageTime(folder, stage, difficulty, newtime);
        }
    }
}

/**
 * Check if cheat is unlocked
 *
 * @param save
 * @param cheat
 * @return bool
 */
bool fileGetIsCheatUnlocked(save_data *save, s32 cheat)
{
    s32 bits;

    if (cheat >= 0 && cheat < SP_LEVEL_MAX)
    {
        bits = save->unlocked_cheats_1 | save->unlocked_cheats_3 << 0x18 | save->unlocked_cheats_3 << 0x10 | save->unlocked_cheats_2 << 8;
        return ((1 << cheat) & bits) != 0;
    }

    return FALSE;
}

/**
 *
 *
 * @param save
 * @param cheat
 */
void sub_GAME_7F01DD74(save_data *save, s32 cheat)
{
    u32 i;
    u32 temp;

    if (cheat >= 0 && cheat < SP_LEVEL_MAX)
    {
        temp = 1 << (cheat);

        for(i = 0; temp > 0xff; i++)
        {
            temp = temp >> 8;
        }

        *(((u8 *)save + i + 0xe)) |= temp & 0xFFu;
    }
}

/**
 * Get save in foldernum slot
 *
 * @param foldernum
 * @return save_data*
 */
save_data * fileGetSaveForFoldernum(u32 folder)
{
    int i;

    for (i = 0; i < 5; i++)
    {
        if ( fileGetSaveFlag_0x80(&saves[i]) == 0 &&
                fileGetSaveFolder(&saves[i]) == folder)
        {
            return &saves[i];
        }
    }

    if (folder == RAMROM_FOLDERNUM)
    {
        return &saves[5];
    }

    return NULL;
}

/**
 * See if any save has 0x80 flag
 *
 * @return s32
 */
s32 fileGetSaveFlag_0x80_any_folder(void)
{
    s32 i;

    for(i = 0; i < 5; i++)
    {
        if ( fileGetSaveFlag_0x80(&saves[i]))
        {
            return i;
        }
    }

    return -1;
}

/**
 * Resets save with 0x80 flag
 * Maybe clearing for copy or wear level
 *
 * @param folder
 */
void sub_GAME_7F01DEB4(u32 folder)
{
    s32 folder_with_flag;
    save_data new_save;

    folder_with_flag = fileGetSaveFlag_0x80_any_folder();

    if (folder_with_flag >= 0)
    {
        new_save = D_8002C5E0;
        saves[folder_with_flag] = new_save;

        fileSetSaveFoldernum(&saves[folder_with_flag], folder);
        fileSetSaveFlag_0x80(&saves[folder_with_flag], 0);
        fileSetSelectedBond(&saves[folder_with_flag], folder);
        fileWriteSave(&saves[folder_with_flag]);
    }
}

void fileValidateSaves(void)
{
    bool checksumOK;
    smallSave joyChecksum;
    s32 crc[2];
    s32 i;
    s32 *temp;

    if (fileGamePakProbe())
    {
        checksumOK = TRUE;

        // block read 32 bytes
        joyGamePakLongRead(0, &joyChecksum, sizeof(smallSave));

        // if customised file dont assume crc is ok
        if (joyChecksum.unk[0] != (0x40 | 0x2))
        {
            checksumOK = FALSE;
        }

        fileGenerateCRC(&joyChecksum.unk[0], &joyChecksum.unk[24], &crc); //do checksum on 24 bytes of save data

        temp = &joyChecksum;

        if ((crc[0] != temp[0]) || (crc[1] != temp[1]))
        {
            checksumOK = FALSE;
        }

        // bad checksum, create a new save and replace damaged one.
        if (!checksumOK)
        {
            smallSave NewSave = blankSmallSave;
            joyChecksum = NewSave;
            fileWriteSmallSave(&joyChecksum);
        }

        // Block read 5 saves starting at address 4th byte (? bug: address must be multiple of 8 - return is -1)
        joyGamePakLongRead(4, &saves, sizeof(save_data) * 5);

        for (i = 0; i != 5; i++) //only != matches
        {
            bool checksumOK2 = TRUE;

            fileGenerateCRC(&saves[i].completion_bitflags, &saves[i + 1], &crc); // do checksum on save data

            if (1){} if (1){} // Hack to shift registers

            if ((crc[0] != saves[i].chksum1) ||
                (crc[1] != saves[i].chksum2))
            {
                checksumOK2 = FALSE;
            }

            if (!checksumOK2)
            {
                fileResetSave(&saves[i]);
            }
        }

        for (i = 0; i < 4; i++)
        {
            s32 flag18_2;
            s32 jif    = -1;
            s32 flag18 = -1;
            s32 j;

            // for each save
            for (j = 0; j < 5; j++)
            {
                // if save = folder and 80 set
                if (!fileGetSaveFlag_0x80(&saves[j]) &&
                    fileGetSaveFolder(&saves[j]) == i)
                {
                    if (jif < 0) // on first 80 do this
                    {
                        jif = j;
                        flag18 = fileSetSaveFlag_0x18(&saves[j]);
                    }
                    else
                    {
                        flag18_2 = fileSetSaveFlag_0x18(&saves[j]);

                        if (flag18_2 == (flag18 + 1) % 4)
                        {
                            fileResetSave(&saves[jif]);
                            jif = j;
                            flag18 = flag18_2;
                        }
                        else
                        {
                            fileResetSave(&saves[j]);
                        }
                    }
                }
            }

            // 80 was not set
            if (jif < 0)
            {
                sub_GAME_7F01DEB4(i);
            }
        }

        for (i = 0; i < 4; i++)
        {
            save_data *save = fileGetSaveForFoldernum(i);

            if (save)
            {
                save_selected_bond[i] = fileGetSelectedBond(save);
            }
        }
    }
}

/**
 * Check if folder is valid
 *
 * @param folder
 * @return bool
 */
bool fileIsFolderValid(s32 folder)
{
    if ((folder >= 0) && (folder < 4))
    {
        return TRUE;
    }

    if (folder == 100)
    {
        return TRUE;
    }

    return FALSE;
}

/**
 * wrapper func - uses save if found
 * file fileIsStageUnlockedAtDifficulty calls fileIsSavedStageUnlockedAtDifficulty
 *
 * @param foldernum
 * @param stage
 * @param difficulty
 * @return 0, 1, or 3 (STAGESTATUS_LOCKED, STAGESTATUS_UNLOCKED, STAGESTATUS_COMPLETED)
 */
STAGESTATUS fileIsStageUnlockedAtDifficulty(s32 foldernum, LEVEL_SOLO_SEQUENCE stage, DIFFICULTY difficulty)
{
    save_data* save;
    s32 i;

    if (( fileIsFolderValid(foldernum)) &&
        (stage >= SP_LEVEL_DAM && stage < SP_LEVEL_MAX) &&
        (difficulty >= DIFFICULTY_AGENT && difficulty < DIFFICULTY_MAX))
    {
        save = fileGetSaveForFoldernum(foldernum);

        if (save)
        {
            if ( fileGetSaveStageCompletedForDifficulty(save, stage, difficulty))
            {
                return STAGESTATUS_COMPLETED; //found on first try, stage has been completed and a time saved.
            }

            if ((stage == SP_LEVEL_AZTEC && difficulty < DIFFICULTY_SECRET) ||
                (stage == SP_LEVEL_EGYPT && difficulty < DIFFICULTY_00))
            {
                return STAGESTATUS_LOCKED; //we cant possibly have a completed bonus stage below each set dificulty
            }

            //still cant find it, do a search (this is probably how a cheat can unlock stages without having to actualy do them all)
            for (i = difficulty; i < DIFFICULTY_MAX ; i++)
            {
                LEVEL_SOLO_SEQUENCE istage;
                for (istage = SP_LEVEL_DAM; istage < stage; istage++)
                {
                    if (! fileGetSaveStageCompletedForDifficulty(save, istage, i))
                    {
                        break;
                    }
                }
                //if the first uncomplete stage is not less than current
                if (stage <= istage)
                {
                    return STAGESTATUS_UNLOCKED;
                }
            }

            // if we still cant find it
            if ((difficulty < DIFFICULTY_007) && (stage < SP_LEVEL_AZTEC))
            {
                for (i = difficulty; i < DIFFICULTY_MAX; i++)
                {
                    if ( fileGetSaveStageCompletedForDifficulty(save, stage - 1, i))
                    {
                        return STAGESTATUS_UNLOCKED;
                    }
                }
            }

            if (difficulty < DIFFICULTY_007)
            {
                for (i = SP_LEVEL_DAM; i < SP_LEVEL_AZTEC; i++)
                {
                    if (! fileGetSaveStageCompletedForDifficulty(save, i, DIFFICULTY_AGENT))
                    {
                        break;
                    }
                }
                //this cant actually fire an it?
                if (i >= SP_LEVEL_AZTEC)
                {
                    for (i = DIFFICULTY_AGENT; i < difficulty; i++)
                    {
                        if (! fileGetSaveStageCompletedForDifficulty(save, stage, i))
                        {
                            break;
                        }
                    }

                    if (difficulty <= i)
                    {
                        return STAGESTATUS_UNLOCKED;
                    }
                }
            }// difficulty < DIFFICULTY_007
        }// save

        // no save, current level is dam, its unlocked.
        if (stage == SP_LEVEL_DAM)
        {
            return STAGESTATUS_UNLOCKED;
        }

        // no save, cheat enabled, its unlocked.
        if (get_debug_enable_agent_levels_flag() && difficulty == DIFFICULTY_AGENT)
        {
            return STAGESTATUS_UNLOCKED;
        }

        // no save, cheat enabled, its unlocked. (basically a repeat of above)
        if (get_debug_enable_all_levels_flag())
        {
            return STAGESTATUS_UNLOCKED;
        }
    }
    // After all that the stage is not unlocked
    return STAGESTATUS_LOCKED;
}

/**
 *
 *
 * @param save1
 * @param save2
 */
void sub_GAME_7F01E504(save_data *save1, save_data *save2)
{
    s32 folder_with_flag;
    s32 otherfolder;

    otherfolder = 0;
    folder_with_flag = fileGetSaveFlag_0x80_any_folder();

    if (folder_with_flag >= 0)
    {
        saves[folder_with_flag] = *save2;

        if (save1)
        {
            otherfolder = (s32)( fileSetSaveFlag_0x18(save1) + 1) % 4;
        }

        fileSetSaveFlag_0x80(&saves[folder_with_flag], 0);
        fileResetSaveFlag_0x18(&saves[folder_with_flag], otherfolder);
        fileWriteSave(&saves[folder_with_flag]);

        if (save1)
        {
            fileResetSave(save1);
        }
    }
}

/**
 *
 *
 * @param foldernum
 * @param stage
 * @param difficulty
 * @param maxtime
 */
void fileUnlockStageInFolderAtDifficulty(s32 foldernum, LEVEL_SOLO_SEQUENCE stage, DIFFICULTY difficulty, s32 newtime)
{
    save_data new_save;
    save_data *save;
    s32 i;

    if ((foldernum >= 0) && (foldernum < 4) &&
        (stage >= SP_LEVEL_DAM) && (stage < SP_LEVEL_MAX) &&
        (difficulty >= DIFFICULTY_AGENT) && (difficulty < DIFFICULTY_MAX))
    {
        new_save = D_8002C660;

        save = fileGetSaveForFoldernum(foldernum);

        if (save != 0) {
            new_save = *save;
        } else {
            fileSetSaveFoldernum(&new_save, foldernum);
        }

        for (i = difficulty; i >= DIFFICULTY_AGENT; i--)
        {
            if (i == difficulty)
            {
                fileCheckSaveStageDifficultyTime(&new_save, stage, i, newtime);
            }
            else
            {
                fileCheckSaveStageDifficultyTime(&new_save, stage, i, 99999999);
            }
        }

        sub_GAME_7F01E504(&save->chksum1, &new_save);
    }
}

/**
 *
 *
 * @param foldernum
 * @param cheat
 */
void sub_GAME_7F01E760(s32 foldernum, s32 cheat)
{
    save_data *save;
    save_data new_save;

    if ((foldernum >= 0) && (foldernum < 4) && (cheat >= 0) && (cheat < SP_LEVEL_MAX))
    {
        save = fileGetSaveForFoldernum(foldernum);

        if (save != 0 && fileGetIsCheatUnlocked(save, cheat) != 0)
        {
           return;
        }

        new_save = D_8002C6C0;

        if (save != 0)
        {
            new_save = *save;
        }
        else
        {
            fileSetSaveFoldernum(&new_save, foldernum);
        }

        sub_GAME_7F01DD74(&new_save, cheat);
        sub_GAME_7F01E504(save, &new_save);
    }
}


/**
 * Get the highest stage and difficulty completed in folder
 *
 * @param foldernum
 * @param stage
 * @param difficulty
 */
void fileGetHighestStageDifficultyCompletedForFolder(s32 foldernum, LEVEL_SOLO_SEQUENCE *stage, DIFFICULTY *difficulty)
{
    save_data *folder;
    LEVEL_SOLO_SEQUENCE stageid;
    DIFFICULTY difficultyid;

    folder = fileGetSaveForFoldernum(foldernum);

    if (folder != NULL)
    {
        for (difficultyid = DIFFICULTY_007; difficultyid >= 0; difficultyid--)
        {
            for (stageid = SP_LEVEL_EGYPT; stageid >= 0; stageid--)
            {
                if ( fileGetSaveStageCompletedForDifficulty(folder, stageid, difficultyid))
                {
                    *stage = stageid;
                    *difficulty = difficultyid;
                    return;
                }
            }
        }
    }
    *stage = SP_LEVEL_DAM - 1;
    *difficulty = DIFFICULTY_MULTI;
}

/**
 * Get the highest stage unlocked in folder
 *
 * @param foldernum
 * @return LEVEL_SOLO_SEQUENCE
 */
LEVEL_SOLO_SEQUENCE fileGetHighestStageUnlockedForFolder(s32 foldernum)
{
    LEVEL_SOLO_SEQUENCE stageid;
    DIFFICULTY difficulty;

    if ( fileGetSaveForFoldernum(foldernum) != NULL)
    {
        for (stageid = SP_LEVEL_EGYPT; stageid >= 0; stageid--)
        {
            for (difficulty = DIFFICULTY_AGENT; difficulty < DIFFICULTY_MAX; difficulty++)
            {
                if ( fileIsStageUnlockedAtDifficulty(foldernum, stageid, difficulty))
                {
                    return stageid;
                }
            }
        }
    }
    return SP_LEVEL_DAM;
}

/**
 * Get the highest stage unlocked in any folder
 *
 * @return stageid
 */
LEVEL_SOLO_SEQUENCE fileGetHighestStageUnlockedAnyFolder(void)
{
    int folder;
    LEVEL_SOLO_SEQUENCE isfound;
    LEVEL_SOLO_SEQUENCE highest = 0;

    for (folder = 0; folder < 4; folder++)
    {
        isfound = fileGetHighestStageUnlockedForFolder(folder);
        if (highest < isfound)
        {
            highest = isfound;
        }
    }

    return highest;
}

/**
 * Check if cradle has been completed at any difficulty
 *
 * @param foldernum
 * @return bool
 */
bool fileIsCradleCompletedForFolder(s32 folder)
{
    return (fileIsStageUnlockedAtDifficulty(folder, SP_LEVEL_CRADLE, DIFFICULTY_AGENT) == STAGESTATUS_COMPLETED) ||
           (fileIsStageUnlockedAtDifficulty(folder, SP_LEVEL_CRADLE, DIFFICULTY_SECRET) == STAGESTATUS_COMPLETED) ||
           (fileIsStageUnlockedAtDifficulty(folder, SP_LEVEL_CRADLE, DIFFICULTY_00) == STAGESTATUS_COMPLETED);
}

/**
 * Check if aztec has been completed at secret or 00 difficulty
 *
 * @param folder
 * @return bool
 */
bool fileIsAztecCompletedOnSecretOr00ForFolder(s32 folder)
{
    return (fileIsStageUnlockedAtDifficulty(folder, SP_LEVEL_AZTEC, DIFFICULTY_SECRET) == STAGESTATUS_COMPLETED) ||
           (fileIsStageUnlockedAtDifficulty(folder, SP_LEVEL_AZTEC, DIFFICULTY_00) == STAGESTATUS_COMPLETED);
}

/**
 * Check if egypt is completed at 00 difficulty
 *
 * @param foldernum
 * @return bool
 */
bool fileIsEgyptCompletedOn00ForFolder(int foldernum)
{
    return fileIsStageUnlockedAtDifficulty(foldernum, SP_LEVEL_EGYPT, DIFFICULTY_00) == STAGESTATUS_COMPLETED;
}

/**
 * Check if cradle has been completed in any folder
 *
 * @return bool
 */
bool fileIsCradleCompletedAnyFolder(void)
{
    int folder;

    for (folder = 0; folder < 4; folder++)
    {
        if ( fileIsCradleCompletedForFolder(folder))
        {
            return TRUE;
        }
    }

    return FALSE;
}

/**
 * Check if aztec has been completed in any folder at secret or 00 difficulty
 *
 * @return bool
 */
bool check_aztec_completed_any_folder_secret_00(void)
{
    int folder;

    for (folder = 0; folder < 4; folder++)
    {
        if ( fileIsAztecCompletedOnSecretOr00ForFolder(folder))
        {
            return TRUE;
        }
    }

    return FALSE;
}

/**
 * Check if Egypt has been completed in any folder at secret or 00 difficulty
 *
 * @return bool
 */
bool fileIsEgyptCompletedOn00AnyFolder(void)
{
    int folder;

    for (folder = 0; folder < 4; folder++)
    {
        if ( fileIsEgyptCompletedOn00ForFolder(folder))
        {
            return TRUE;
        }
    }

    return FALSE;
}

/**
 * Get bond for folder
 *
 * @param folder
 * @return u8
 */
u8 fileGetBondForFolder(u32 folder)
{
#ifdef ALL_BONDS
    //likely code based on behavior
    if ((folder >= 0) && (folder < 4))
    {
        return save_selected_bond[folder];
    }
#endif

    return 0;
}

/**
 * Set the selected bond to folder object
 *
 * @param folder
 * @param bond
 */
void fileSetSelectedBondTofolder(s32 folder, s32 bond)
{
    if (folder < 0 || folder > 3)
    {
        return;
    }

    save_selected_bond[folder] = 0;
}

/**
 *
 *
 * @param unused
 */
void sub_GAME_7F01EBF4(u32 unused)
{
    return;
}

/**
 *
 *
 * @param unused
 */
void sub_GAME_7F01EBFC(u32 unused)
{
    return;
}

/**
 * Delete save at foldernum
 *
 * @param foldernum
 */
void fileDeleteSaveForFolder(s32 foldernum)
{
    save_data *save;
    LEVEL_SOLO_SEQUENCE stage;
    DIFFICULTY difficulty;
    save_data new_save;

    if (foldernum >= 0 && foldernum < 4)
    {
        save = fileGetSaveForFoldernum(foldernum);
        if (save != 0)
        {
            fileGetHighestStageDifficultyCompletedForFolder(foldernum, &stage, &difficulty);
            if ((stage >= 0) && (difficulty >= 0))
            {
                new_save = D_8002C720;
                *save = new_save;
                fileSetSaveFoldernum(save, foldernum);
                fileSetSaveFlag_0x80(save, 0);
                fileSetSelectedBond(save, foldernum);
                fileSetSelectedBondTofolder(foldernum, foldernum);
                fileWriteSave(save);
            }
        }
    }
}

/**
 *
 *
 * Resetting times??
 * @param folder
 */
void fileInitializeAllTimes(u32 folder)
{
    save_data *save;
    LEVEL_SOLO_SEQUENCE stagenum;
    DIFFICULTY difficulty;

    save = fileGetSaveForFoldernum(folder);

    for (stagenum = SP_LEVEL_DAM; stagenum < SP_LEVEL_MAX; stagenum++)
    {
        for(difficulty = DIFFICULTY_AGENT; difficulty < DIFFICULTY_007; difficulty++)
        {
            fileCheckSaveStageDifficultyTime(save, stagenum, difficulty, 99999999);
        }
    }
}

/**
 * Copy save
 *
 * Copies selected save to the first free slot
 * if no free slot, do nothing
 * @param foldernum Current folder number
 */
void sub_GAME_7F01EDA0(s32 foldernum)
{
    save_data* save;
    LEVEL_SOLO_SEQUENCE stage;
    DIFFICULTY difficulty;
    s32 other;
    save_data new_save;
    save_data* temp_s2;

    if ((foldernum >= 0) && (foldernum < 4))
    {
        save = fileGetSaveForFoldernum(foldernum);
        if (save != 0)
        {
            fileGetHighestStageDifficultyCompletedForFolder(foldernum, &stage, &difficulty);
            if (stage >= 0)
            {
                if (difficulty >= 0) {
                    for(other = 0;other != 4; other++)
                    {
                            if (( fileGetSaveForFoldernum(other) == 0) ||
                                ( fileGetHighestStageDifficultyCompletedForFolder(other, &stage, &difficulty),
                                (stage < 0) && (difficulty < 0)))
                            {
                                break;
                            }
                    }

                    if ((s32)other < 4)
                    {
                        new_save = D_8002C780;
                        temp_s2 = fileGetSaveForFoldernum(other);
                        new_save = *save;
                        fileSetSaveFoldernum(&new_save, other);
                        fileSetSelectedBondTofolder(other, fileGetBondForFolder(foldernum));
                        sub_GAME_7F01E504(temp_s2, &new_save);
                    }
                }
            }
        }
    }
}

/**
 *
 *
 * @param save
 */
void fileSaveSettingsForFolder(save_data *save)
{
    u32 temp;
    u16 bits;

    bits = 0;
    save->music_vol = get_mTrack2Vol() >> 7;
    save->sfx_vol = (call_sndGetSfxSlotFirstNaturalVolume() >> 7);

    if (get_cur_player_look_vertical_inverted() != 0)
    {
        bits = 1;
    }

    if (cur_player_get_autoaim() != 0)
    {
        bits |= 2;
    }

    if (cur_player_get_aim_control() != 0)
    {
        bits |= 4;
    }

    if (cur_player_get_sight_onscreen_control() != 0)
    {
        bits |= 8;
    }

    if (cur_player_get_lookahead() != 0)
    {
        bits |= 0x10;
    }

    if (cur_player_get_ammo_onscreen_setting() != 0)
    {
        bits |= 0x20;
    }

    if (cur_player_get_screen_setting() == 1)
    {
        bits |= 0x40;
    }
    else if (cur_player_get_screen_setting() == 2)
    {
        bits |= 0x800;
    }

    if (get_screen_ratio() != SCREEN_RATIO_NORMAL)
    {
        bits |= 0x80;
    }

    temp = ((u16) (cur_player_get_control_type() << 8)) & 0x700;
    save->options = bits | temp;
}

/**
 * Loads settings from save file
 *
 * @param folder
 */
void fileLoadSettingsForFolder(u32 folder)
{
    save_data *save;
    u16 padding;
    u16 options;

    save = fileGetSaveForFoldernum(folder);
    if (save)
    {
        set_mTrack2Vol((save->music_vol << 7) | (save->music_vol >> 1));
        sub_GAME_7F0A91A0((save->sfx_vol << 7) | (save->sfx_vol >> 1));

        options = save->options;

        if (getPlayerCount() == 1)
        {
            cur_player_set_control_type(((s32) (options & 0x700) >> 8) & 0xFFFF);
        }
        else
        {
            cur_player_set_control_type(0);
        }

        set_cur_player_look_vertical_inverted((options & 1) != 0);
        cur_player_set_autoaim((options & 2) != 0);
        cur_player_set_aim_control((options & 4) != 0);
        cur_player_set_sight_onscreen_control((options & 8) != 0);
        cur_player_set_lookahead((options & 0x10) != 0);
        cur_player_set_ammo_onscreen_setting((options & 0x20) != 0);

        if (options & 0x800)
        {
            cur_player_set_screen_setting(2);
        }
        else if (options & 0x40)
        {
            cur_player_set_screen_setting(1);
        }
        else
        {
            cur_player_set_screen_setting(0);
        }

        set_screen_ratio((options & 0x80) != 0);
    }
}

/**
 * Resets the folder save to default
 *
 * @param folder
 */
void fileClearSavefileForFolder(s32 folder)
{
    save_data *save;
    save_data save_to_copy;
    save_data new_save;

    if (folder >= 0 && folder < 4)
    {
        save = fileGetSaveForFoldernum(folder);

        save_to_copy = D_8002C7E0;

        if (save != 0)
        {
            save_to_copy = *save;
        }
        else
        {
            fileSetSaveFoldernum(&save_to_copy, folder);
        }

        new_save = save_to_copy;

        fileSaveSettingsForFolder(&new_save);

        if (_bcmp(&new_save, &save_to_copy, sizeof(save_data)) != 0)
        {
            sub_GAME_7F01E504(save, &new_save);
        }
    }
}

/**
 * Not confident in the naming of this one...
 *
 * @param folder
 */
void fileCopySaveIfSelectedBondDifferent(s32 folder)
{
    save_data *save;
    save_data new_save;

    if (folder >= 0 && folder < 4)
    {
        save = fileGetSaveForFoldernum(folder);
        new_save = D_8002C840;

        if (save != 0)
        {
            new_save = *save;
        }
        else
        {
            fileSetSaveFoldernum(&new_save, folder);
        }

        if (save_selected_bond[folder] != fileGetSelectedBond(&new_save))
        {
            fileSetSelectedBond(&new_save, save_selected_bond[folder]);
            sub_GAME_7F01E504(save, &new_save);
        }
    }
}

/**
 * Copy folder save
 *
 * @param foldernum
 * @param out_save
 */
void fileCopySave(s32 folder, save_data *out_save)
{
    save_data *in_save;
    save_data new_save;

    in_save = fileGetSaveForFoldernum(folder);

    if (in_save != 0)
    {
        *out_save = *in_save;
    }
    else
    {
        new_save = blank_eeprom;
        *out_save = new_save;
    }
}

/**
 * Copy save to RarRom replay save
 *
 * @param folder
 * @param save
 */
void fileCopyDemoSaveToRamRomSave(u32 folder, save_data *save)
{
    if (folder == RAMROM_FOLDERNUM)
    {
        saves[5] = *save;
    }
}

/**
 * Check if 007 mode is unlocked
 *
 * @param folder
 * @return bool
 */
s32 fileIs007ModeUnlocked(u32 folder)
{
    LEVEL_SOLO_SEQUENCE stage;
    save_data* save;

    save = fileGetSaveForFoldernum(folder);

    if (save != NULL)
    {
        if ((save->flag_007 & 1))
        {
            return TRUE;
        }

        for (stage = SP_LEVEL_DAM; stage < SP_LEVEL_MAX; stage++)
        {
            if (! fileGetSaveStageCompletedForDifficulty(save, stage, DIFFICULTY_00))
            {
                break;
            }
        }

        if (stage == SP_LEVEL_MAX)
        {
            return TRUE;
        }
    }

    return FALSE;
}
