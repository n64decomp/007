#include <ultra64.h>
#include <bondconstants.h>
#include "debugmenu_handler.h"
#include "joy.h"
#include "player.h"
#include "watch.h"
#include "file.h"
#include "file2.h"
#include "front.h"
#include "cheat_buttons.h"


// bss
//CODE.bss:80069920
//CODE.bss:80069980
//CODE.bss:800699E0
//CODE.bss:80069A40
//CODE.bss:80069AA0
//CODE.bss:80069B00
save_data saves[SAVESLOTMAX];

//CODE.bss:80069B60
u32 dword_CODE_bss_80069B60;

//data
//D:8002C510
#ifdef ALL_BONDS
s32 save_selected_bond[] = {BOND_BROSNAN,BOND_CONNERY,BOND_DALTON,BOND_MOORE};
#else
s32 save_selected_bond[] = {BOND_BROSNAN,BOND_BROSNAN,BOND_BROSNAN,BOND_BROSNAN};
#endif




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
    save_data new_save = BLANKSAVEDATA;

    saves[SAVESLOTRAMROM] = new_save;
}

/**
 *
 *
 * @param save
 */
void fileWriteSmallSave(smallSave *save)
{
    if (fileGamePakProbe())
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
    if (save >= &saves[SAVESLOT1] && save < &saves[SAVESLOTRAMROM])
    {
        if ( fileGamePakProbe())
        {
            fileGenerateCRC(&save->completion_bitflags, save + 1, save);
            joyGamePakLongWrite((((u32)((save - &saves[SAVESLOT1]) * 0x60) >> 3) + 4), save, sizeof(save_data)); // 0x60 = sizeof(save_data) be sure to manually update if save changes
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
    save_data new_save  = BLANKSAVEDATA;

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
  return save->completion_bitflags & SAVEFLAG_FOLDER;
}

/**
 * Clear then set save folder flag
 *
 * @param save
 * @param folder
 */
void fileSetSaveFoldernum(save_data *save, u32 folder)
{
    save->completion_bitflags &= ~SAVEFLAG_FOLDER;
    save->completion_bitflags |= folder & SAVEFLAG_FOLDER;
}

/**
 * Get save flag 0x18
 *
 * @param folder
 * @return u32
 */
u32 fileGetSaveFlagSlot(save_data *folder)
{
  return (folder->completion_bitflags & SAVEFLAG_SLOT) >> 3;
}

/**
 * Resets save flag 0x18
 *
 * @param folder
 * @param arg1
 */
void fileResetSaveFlagSlot(save_data *folder, s32 slot)
{
    folder->completion_bitflags &= ~SAVEFLAG_SLOT;
    folder->completion_bitflags |= ((slot * 8) & SAVEFLAG_SLOT);
}

/**
 * Get the selected bond save flag
 *
 * @param folder
 * @return u32
 */
u32 fileGetSelectedBond(save_data *folder)
{
  return (folder->completion_bitflags & SAVEFLAG_BOND) >> 5;
}

/**
 * Set the selected bond save flag
 *
 * @param folder
 * @param bond
 */
void fileSetSelectedBond(save_data *folder, s32 bond)
{
    folder->completion_bitflags &= ~SAVEFLAG_BOND;
    folder->completion_bitflags |= ((bond << 5) & SAVEFLAG_BOND);
}

/**
 * Check if save has flag 0x80
 *
 * @param folder
 * @return TRUE/FALSE
 */
bool fileGetSaveFlagDoReset(save_data *folder)
{
  return ((folder->completion_bitflags & SAVEFLAG_DORESET) != FALSE);
}

/**
 * Toggle save flag 0x80
 * possibly wear levelling
 *
 * @param folder: folder to enable or disable flag
 * @param set: Enable flag if TRUE, Disable flag if FALSE
 */
void fileSetSaveFlagDoReset(save_data *folder, bool enable)
{
    if (enable)
    {
        folder->completion_bitflags |= SAVEFLAG_DORESET;
    }
    else
    {
        folder->completion_bitflags &= ~SAVEFLAG_DORESET;
    }
}

/**
 * Get completion time for stage at difficulty
 *
 * @param save
 * @param levelid
 * @param difficulty
 * @return best time for stage at difficulty
 */
s32 fileGetSaveStageDifficultyTime(save_data* save, LEVEL_SOLO_SEQUENCE levelid, DIFFICULTY difficulty)
{
    s32 offset;
    LEVEL_SOLO_SEQUENCE max_level;
    u32 time;
    s32 index;

    max_level = SP_LEVEL_MAX;
    if ((levelid >= SP_LEVEL_DAM) && (levelid < SP_LEVEL_MAX ) && (difficulty >= DIFFICULTY_AGENT) && (difficulty < DIFFICULTY_MAX))
    {
        if (difficulty == DIFFICULTY_007)
        {
            if ( fileIs007ModeUnlocked( fileGetSaveFolder(save)))
            {
                return 0x3FF; //max time
            }
            return 0;
        }

        offset = ((difficulty * max_level) + levelid) * 10; //startbit
        index = (offset >> 3);

        switch(7 - (offset & 7)) //bitmask
        {
            case 7: //no offset agent
                // first 10 bits 8 + 2                    1111 1111                                      1100 0000
                time = ((save->times[index] & 0xFF) << 2) | ((save->times[index + 1] & 0xc0) >> 6);
                break;
            case 5: //offset 2 secret agent
                // next 10 bits 6 + 4                     0011 1111                                      1111 0000
                time =  ((save->times[index] & 0x3f) << 4) | ((save->times[index + 1] & 0xf0) >> 4);
                break;
            case 3: //offset 4 00 agent
                // next 10 bits 4 + 6                     0000 1111                                      1111 1100
                time =  ((save->times[index] & 0xf) << 6) | ((save->times[index + 1] & 0xfc) >> 2);
                break;
            case 1: //offset 6 007
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
 * @param levelid
 * @param difficulty
 * @param newtime
 */
void fileSetDifficultyStageTime(save_data *save, LEVEL_SOLO_SEQUENCE levelid, DIFFICULTY difficulty, s32 newtime)
{
    s32 offset;
    s32 index;
    LEVEL_SOLO_SEQUENCE max_level;

    max_level = SP_LEVEL_MAX;
    if ((levelid >= SP_LEVEL_DAM) && (levelid < SP_LEVEL_MAX ) && (difficulty >= DIFFICULTY_AGENT) && (difficulty < DIFFICULTY_007))
    {
        if (newtime == 0) {
            newtime = 0x4f;
        } else if (newtime > 0x3ff) {
            newtime = 0x3ff;
        }

        offset = ((difficulty * max_level) + levelid) * 10; //startbit
        index = (offset >> 3);

        switch(7 - (offset & 7)) //bitmask
        {
            case 7: //no offset 4 8 12 etc agent
                save->times[index] &= 0xff00;
                save->times[index + 1] &= 0xff3f;
                save->times[index] |= (newtime >> 2) & 0xff;
                save->times[index + 1] |= (newtime << 6) & 0xc0;
                break;
            case 5: //first offset 5 9 13 etc secret agent
                save->times[index] &= 0xffc0;
                save->times[index + 1] &= 0xff0f;
                save->times[index] |= ((newtime >> 4) & 0x3f);
                save->times[index + 1] |= (newtime << 4) & 0xf0;
                break;
            case 3: //second offset 6 10 14 etc 00 agent
                save->times[index] &= 0xfff0;
                save->times[index + 1] &= 0xff03;
                save->times[index] |= ((newtime >> 6) & 0xf);
                save->times[index + 1] |= (newtime << 2) & 0xfC;
                break;
            case 1: //third offset 7 11 15 etc 007
                save->times[index] &= 0xfffc;
                save->times[index + 1] &= 0xff00;
                save->times[index] |= ((newtime >> 8) & 3);
                save->times[index + 1] |= newtime & 0xfff;
                break;
            default:
#if DEBUG
                osSyncPrintf("file.c: SHOULDN\'T GET HERE EVER [2]\n");
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
bool fileGetSaveStageCompletedForDifficulty(save_data *folder, LEVEL_SOLO_SEQUENCE levelid, DIFFICULTY difficulty)
{
    if ((levelid >= SP_LEVEL_DAM) && (levelid < SP_LEVEL_MAX) && (difficulty >= DIFFICULTY_AGENT) && (difficulty <= DIFFICULTY_007))
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
void fileCheckSaveStageDifficultyTime(save_data *folder, LEVEL_SOLO_SEQUENCE levelid, DIFFICULTY difficulty, s32 newtime)
{
    if ((levelid >= SP_LEVEL_DAM) && (levelid < SP_LEVEL_MAX) && (difficulty >= DIFFICULTY_AGENT) && (difficulty <= DIFFICULTY_007))
    {
        s32 time = fileGetSaveStageDifficultyTime(folder, levelid, difficulty);

        if ((time == 0) || (newtime < time))
        {
            fileSetDifficultyStageTime(folder, levelid, difficulty, newtime);
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

    if (cheat >= 0 && cheat < CHEAT_20)
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
void fileSetSaveCheatUnlocked(save_data *save, s32 cheat)
{
    u32 i;
    u32 temp;

    if (cheat >= 0 && cheat < CHEAT_20)
    {
        temp = 1 << (cheat);

        for(i = 0; temp > 0xff; i++)
        {
            temp = temp >> 8;
        }

        *(((u8 *)save + i + 0xe)) |= temp & 0xFFu; //save.unlocked_cheats_1[i] |= temp;
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

    for (i = SAVESLOT1; i < SAVESLOTRAMROM; i++)
    {
        if ( fileGetSaveFlagDoReset(&saves[i]) == FALSE &&
                fileGetSaveFolder(&saves[i]) == folder)
        {
            return &saves[i];
        }
    }

    if (folder == RAMROM_FOLDERNUM)
    {
        return &saves[SAVESLOTRAMROM];
    }

    return NULL;
}

/**
 * See if any save has 0x80 flag
 *
 * @return s32
 */
s32 fileGetSaveFlagDoReset_any_folder(void)
{
    s32 i;

    for(i = SAVESLOT1; i < SAVESLOTRAMROM; i++)
    {
        if ( fileGetSaveFlagDoReset(&saves[i]))
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
void fileBuildWriteNewSave(u32 folder)
{
    s32 folder_with_flag;

    folder_with_flag = fileGetSaveFlagDoReset_any_folder();

    if (folder_with_flag >= 0)
    {
        save_data new_save = BLANKSAVEDATA;
        saves[folder_with_flag] = new_save;

        fileSetSaveFoldernum(&saves[folder_with_flag], folder);
        fileSetSaveFlagDoReset(&saves[folder_with_flag], FALSE);
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
        if (joyChecksum.unk[0] != SAVEFLAGS_SET(FOLDER3, SAVESLOT1, BOND_CONNERY, FALSE))
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
            smallSave NewSave = {0, 0, SAVEFLAGS_SET(FOLDER3, SAVESLOT1, BOND_CONNERY, FALSE)};
            joyChecksum = NewSave;
            fileWriteSmallSave(&joyChecksum);
        }

        // Block read 5 saves starting at address 4th byte (? bug: address must be multiple of 8 - return is -1)
        joyGamePakLongRead(4, &saves, sizeof(save_data) * 5);

        for (i = SAVESLOT1; i != SAVESLOTRAMROM; i++) //only != matches
        {
            bool checksumOK2 = TRUE;

            fileGenerateCRC(&saves[i].completion_bitflags, &saves[i + 1], &crc); // do checksum on save data

            if (1){} // Hack to shift registers
            if (1){} // or something like if (FINAL){}

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

        for (i = FOLDER1; i < MAX_FOLDER_COUNT; i++)
        {
            s32 slot_2;
            s32 jif    = -1;
            s32 slot = -1;
            s32 j;

            // for each save
            for (j = SAVESLOT1; j < SAVESLOTRAMROM; j++)
            {
                // if save = folder and SAVEFLAG_DORESET set
                if (!fileGetSaveFlagDoReset(&saves[j]) &&
                    fileGetSaveFolder(&saves[j]) == i)
                {
                    if (jif < SAVESLOT1) // on first SAVEFLAG_DORESET do this
                    {
                        jif = j;
                        slot = fileGetSaveFlagSlot(&saves[j]);
                    }
                    else
                    {
                        slot_2 = fileGetSaveFlagSlot(&saves[j]);

                        if (slot_2 == (slot + 1) % 4)
                        {
                            fileResetSave(&saves[jif]);
                            jif = j;
                            slot = slot_2;
                        }
                        else
                        {
                            fileResetSave(&saves[j]);
                        }
                    }
                }
            }

            // SAVEFLAG_DORESET was not set
            if (jif < SAVESLOT1)
            {
                fileBuildWriteNewSave(i);
            }
        }

        for (i = FOLDER1; i < MAX_FOLDER_COUNT; i++)
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
    if ((folder >= FOLDER1) && (folder < MAX_FOLDER_COUNT))
    {
        return TRUE;
    }

    if (folder == RAMROM_FOLDERNUM)
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
 * @param levelid
 * @param difficulty
 * @return 0, 1, or 3 (STAGESTATUS_LOCKED, STAGESTATUS_UNLOCKED, STAGESTATUS_COMPLETED)
 */
STAGESTATUS fileIsStageUnlockedAtDifficulty(s32 foldernum, LEVEL_SOLO_SEQUENCE levelid, DIFFICULTY difficulty)
{
    save_data* save;
    s32 i;

    if (( fileIsFolderValid(foldernum)) &&
        (levelid >= SP_LEVEL_DAM && levelid < SP_LEVEL_MAX) &&
        (difficulty >= DIFFICULTY_AGENT && difficulty < DIFFICULTY_MAX))
    {
        save = fileGetSaveForFoldernum(foldernum);

        if (save)
        {
            if ( fileGetSaveStageCompletedForDifficulty(save, levelid, difficulty))
            {
                return STAGESTATUS_COMPLETED; //found on first try, stage has been completed and a time saved.
            }

            if ((levelid == SP_LEVEL_AZTEC && difficulty < DIFFICULTY_SECRET) ||
                (levelid == SP_LEVEL_EGYPT && difficulty < DIFFICULTY_00))
            {
                return STAGESTATUS_LOCKED; //we cant possibly have a completed bonus stage below each set dificulty
            }

            //still cant find it, do a search (this is probably how a cheat can unlock stages without having to actualy do them all)
            for (i = difficulty; i < DIFFICULTY_MAX ; i++)
            {
                LEVEL_SOLO_SEQUENCE istage;
                for (istage = SP_LEVEL_DAM; istage < levelid; istage++)
                {
                    if (! fileGetSaveStageCompletedForDifficulty(save, istage, i))
                    {
                        break;
                    }
                }
                //if the first uncomplete stage is not less than current
                if (levelid <= istage)
                {
                    return STAGESTATUS_UNLOCKED;
                }
            }

            // if we still cant find it
            if ((difficulty < DIFFICULTY_007) && (levelid < SP_LEVEL_AZTEC))
            {
                for (i = difficulty; i < DIFFICULTY_MAX; i++)
                {
                    if ( fileGetSaveStageCompletedForDifficulty(save, levelid - 1, i))
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
                        if (! fileGetSaveStageCompletedForDifficulty(save, levelid, i))
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
        if (levelid == SP_LEVEL_DAM)
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
void fileOverwriteSaveSlotWithNewSave(save_data *save1, save_data *save2)
{
    s32 folder_with_flag;
    s32 slot;

    slot = 0;
    folder_with_flag = fileGetSaveFlagDoReset_any_folder();

    if (folder_with_flag >= 0)
    {
        saves[folder_with_flag] = *save2;

        if (save1)
        {
            slot = (s32)( fileGetSaveFlagSlot(save1) + 1) % 4;
        }

        fileSetSaveFlagDoReset(&saves[folder_with_flag], FALSE);
        fileResetSaveFlagSlot(&saves[folder_with_flag], slot);
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
    if ((foldernum >= 0) && (foldernum < MAX_FOLDER_COUNT) &&
        (stage >= SP_LEVEL_DAM) && (stage < SP_LEVEL_MAX) &&
        (difficulty >= DIFFICULTY_AGENT) && (difficulty < DIFFICULTY_MAX))
    {
        save_data new_save = BLANKSAVEDATA;

        save_data *save = fileGetSaveForFoldernum(foldernum);
        s32 i;
        if (save) {
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

        fileOverwriteSaveSlotWithNewSave(&save[0], &new_save);
    }
}

/**
 *
 *
 * @param foldernum
 * @param cheat
 */
void fileSaveFolderUnlockCheat(s32 foldernum, s32 cheat)
{
    if ((foldernum >= FOLDER1) && (foldernum < MAX_FOLDER_COUNT) && (cheat >= 0) && (cheat < CHEAT_20))
    {
        save_data *save = fileGetSaveForFoldernum(foldernum);

        if (save && fileGetIsCheatUnlocked(save, cheat))
        {
           return;
        }

        {
            save_data new_save = BLANKSAVEDATA;

            if (save)
            {
                new_save = *save;
            }
            else
            {
                fileSetSaveFoldernum(&new_save, foldernum);
            }

            fileSetSaveCheatUnlocked(&new_save, cheat);
            fileOverwriteSaveSlotWithNewSave(save, &new_save);
        }
    }
}


/**
 * Get the highest stage and difficulty completed in folder
 *
 * @param foldernum
 * @param stage
 * @param difficulty
 */
void fileGetHighestStageDifficultyCompletedForFolder(s32 foldernum, LEVEL_SOLO_SEQUENCE *levelid, DIFFICULTY *difficulty)
{
    save_data *folder;
    LEVEL_SOLO_SEQUENCE stageid;
    DIFFICULTY difficultyid;

    folder = fileGetSaveForFoldernum(foldernum);

    if (folder)
    {
        for (difficultyid = DIFFICULTY_007; difficultyid >= DIFFICULTY_AGENT; difficultyid--)
        {
            for (stageid = SP_LEVEL_EGYPT; stageid >= SP_LEVEL_DAM; stageid--)
            {
                if ( fileGetSaveStageCompletedForDifficulty(folder, stageid, difficultyid))
                {
                    *levelid = stageid;
                    *difficulty = difficultyid;
                    return;
                }
            }
        }
    }
    *levelid = SP_LEVEL_DAM - 1;
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
    LEVEL_SOLO_SEQUENCE levelid;
    DIFFICULTY difficulty;

    if ( fileGetSaveForFoldernum(foldernum) != NULL)
    {
        for (levelid = SP_LEVEL_EGYPT; levelid >= SP_LEVEL_DAM; levelid--)
        {
            for (difficulty = DIFFICULTY_AGENT; difficulty < DIFFICULTY_MAX; difficulty++)
            {
                if ( fileIsStageUnlockedAtDifficulty(foldernum, levelid, difficulty))
                {
                    return levelid;
                }
            }
        }
    }
    return SP_LEVEL_DAM;
}

/**
 * Get the highest stage unlocked in any folder
 *
 * @return levelid
 */
LEVEL_SOLO_SEQUENCE fileGetHighestStageUnlockedAnyFolder(void)
{
    int folder;
    LEVEL_SOLO_SEQUENCE isfound;
    LEVEL_SOLO_SEQUENCE highest = SP_LEVEL_DAM;

    for (folder = FOLDER1; folder < MAX_FOLDER_COUNT; folder++)
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

    for (folder = FOLDER1; folder < MAX_FOLDER_COUNT; folder++)
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

    for (folder = FOLDER1; folder < MAX_FOLDER_COUNT; folder++)
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

    for (folder = FOLDER1; folder < MAX_FOLDER_COUNT; folder++)
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
    if ((folder >= FOLDER1) && (folder < MAX_FOLDER_COUNT))
    {
        return save_selected_bond[folder];
    }
#endif

    return BOND_BROSNAN;
}

/**
 * Set the selected bond to folder object
 *
 * @param folder
 * @param bond
 */
void fileSetSelectedBondTofolder(s32 folder, s32 bond)
{
    if (folder < FOLDER1 || folder > FOLDER4)
    {
        return;
    }
#ifdef ALL_BONDS
    save_selected_bond[folder] = bond;
#else
    save_selected_bond[folder] = BOND_BROSNAN;
#endif
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
    LEVEL_SOLO_SEQUENCE levelid;
    DIFFICULTY difficulty;

    if (foldernum >= FOLDER1 && foldernum < MAX_FOLDER_COUNT)
    {
        save = fileGetSaveForFoldernum(foldernum);
        if (save)
        {
            fileGetHighestStageDifficultyCompletedForFolder(foldernum, &levelid, &difficulty);
            if ((levelid >= SP_LEVEL_DAM) && (difficulty >= DIFFICULTY_AGENT))
            {
                save_data new_save = BLANKSAVEDATA;
                *save = new_save;
                fileSetSaveFoldernum(save, foldernum);
                fileSetSaveFlagDoReset(save, FALSE);
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
    LEVEL_SOLO_SEQUENCE levelid;
    DIFFICULTY difficulty;

    save = fileGetSaveForFoldernum(folder);

    for (levelid = SP_LEVEL_DAM; levelid < SP_LEVEL_MAX; levelid++)
    {
        for(difficulty = DIFFICULTY_AGENT; difficulty < DIFFICULTY_007; difficulty++)
        {
            fileCheckSaveStageDifficultyTime(save, levelid, difficulty, 99999999);
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
void fileCopyFolderToFirstFree(s32 foldernum)
{
    save_data* save;
    LEVEL_SOLO_SEQUENCE levelid;
    DIFFICULTY difficulty;
    s32 other;

    if ((foldernum >= FOLDER1) && (foldernum < MAX_FOLDER_COUNT))
    {
        save = fileGetSaveForFoldernum(foldernum);
        if (save)
        {
            fileGetHighestStageDifficultyCompletedForFolder(foldernum, &levelid, &difficulty);
            if (levelid >= SP_LEVEL_DAM)
            {
                if (difficulty >= DIFFICULTY_AGENT) {
                    for(other = FOLDER1;other != MAX_FOLDER_COUNT; other++)
                    {
                            if (( fileGetSaveForFoldernum(other) == NULL) ||
                                ( fileGetHighestStageDifficultyCompletedForFolder(other, &levelid, &difficulty),
                                (levelid < SP_LEVEL_DAM) && (difficulty < DIFFICULTY_AGENT)))
                            {
                                break;
                            }
                    }

                    if ((s32)other < MAX_FOLDER_COUNT)
                    {
                        save_data new_save = BLANKSAVEDATA;
                        save_data *temp_s2 = fileGetSaveForFoldernum(other);
                        new_save = *save;
                        fileSetSaveFoldernum(&new_save, other);
                        fileSetSelectedBondTofolder(other, fileGetBondForFolder(foldernum));
                        fileOverwriteSaveSlotWithNewSave(temp_s2, &new_save);
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

    if (get_cur_player_look_vertical_inverted())
    {
        bits = OPTION_INVERTLOOK;
    }

    if (cur_player_get_autoaim())
    {
        bits |= OPTION_AUTOAIM;
    }

    if (cur_player_get_aim_control())
    {
        bits |= OPTION_AIMCONTROL;
    }

    if (cur_player_get_sight_onscreen_control())
    {
        bits |= OPTION_SIGHTONSCREEN;
    }

    if (cur_player_get_lookahead())
    {
        bits |= OPTION_LOOKAHEAD;
    }

    if (cur_player_get_ammo_onscreen_setting())
    {
        bits |= OPTION_DISPLAYAMMO;
    }

    if (cur_player_get_screen_setting() == SCREEN_SIZE_WIDESCREEN)
    {
        bits |= OPTION_SCREENWIDE;
    }
    else if (cur_player_get_screen_setting() == SCREEN_SIZE_CINEMA)
    {
        bits |= OPTION_SCREENCINEMA;
    }

    if (get_screen_ratio() != SCREEN_RATIO_NORMAL)
    {
        bits |= OPTION_SCREENRATIO;
    }

    temp = ((u16) (cur_player_get_control_type() << 8)) & OPTION_CONTROLTYPE;
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
            cur_player_set_control_type(((s32) (options & OPTION_CONTROLTYPE) >> 8) & 0xFFFF);
        }
        else
        {
            cur_player_set_control_type(CONTROLLER_CONFIG_HONEY);
        }

        set_cur_player_look_vertical_inverted((options & OPTION_INVERTLOOK) != FALSE);
        cur_player_set_autoaim((options & OPTION_AUTOAIM) != FALSE);
        cur_player_set_aim_control((options & OPTION_AIMCONTROL) != FALSE);
        cur_player_set_sight_onscreen_control((options & OPTION_SIGHTONSCREEN) != FALSE);
        cur_player_set_lookahead((options & OPTION_LOOKAHEAD) != FALSE);
        cur_player_set_ammo_onscreen_setting((options & OPTION_DISPLAYAMMO) != FALSE);

        if (options & OPTION_SCREENCINEMA)
        {
            cur_player_set_screen_setting(SCREEN_SIZE_CINEMA);
        }
        else if (options & OPTION_SCREENWIDE)
        {
            cur_player_set_screen_setting(SCREEN_SIZE_WIDESCREEN);
        }
        else
        {
            cur_player_set_screen_setting(SCREEN_SIZE_FULLSCREEN);
        }

        set_screen_ratio((options & OPTION_SCREENRATIO) != FALSE);
    }
}

/**
 * Resets the folder save to default
 *
 * @param folder
 */
void fileClearSavefileForFolder(s32 folder)
{
    if (folder >= FOLDER1 && folder < MAX_FOLDER_COUNT)
    {
        save_data *save = fileGetSaveForFoldernum(folder);

        save_data save_to_copy = BLANKSAVEDATA;
        save_data new_save;
        if (save)
        {
            save_to_copy = *save;
        }
        else
        {
            fileSetSaveFoldernum(&save_to_copy, folder);
        }

        new_save = save_to_copy;

        fileSaveSettingsForFolder(&new_save);

        if (memcmp(&new_save, &save_to_copy, sizeof(save_data)))
        {
            fileOverwriteSaveSlotWithNewSave(save, &new_save);
        }
    }
}

/**
 * Not confident in the naming of this one...
 *
 * @param folder
 */
void fileUpdateSelectedBondInSave(s32 folder)
{

    if (folder >= FOLDER1 && folder < MAX_FOLDER_COUNT)
    {
        save_data *save = fileGetSaveForFoldernum(folder);
        save_data new_save = BLANKSAVEDATA;

        if (save)
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
            fileOverwriteSaveSlotWithNewSave(save, &new_save);
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

    save_data *in_save = fileGetSaveForFoldernum(folder);

    if (in_save)
    {
        *out_save = *in_save;
    }
    else
    {
        save_data new_save = BLANKSAVEDATA;
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
        saves[SAVESLOTRAMROM] = *save;
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
    LEVEL_SOLO_SEQUENCE levelid;
    save_data* save;

    save = fileGetSaveForFoldernum(folder);

    if (save != NULL)
    {
        if ((save->flag_007 & 1))
        {
            return TRUE;
        }

        for (levelid = SP_LEVEL_DAM; levelid < SP_LEVEL_MAX; levelid++)
        {
            if (! fileGetSaveStageCompletedForDifficulty(save, levelid, DIFFICULTY_00))
            {
                break;
            }
        }

        if (levelid == SP_LEVEL_MAX)
        {
            return TRUE;
        }
    }

    return FALSE;
}
