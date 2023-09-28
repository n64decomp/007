#include <ultra64.h>
#include <bondconstants.h>
#include <bondtypes.h>
#include "objective_status.h"
#include "assets/obseg/text/LmiscE.h"
#include "lvl_text.h"
#include "PR/os.h"
#include "str.h"
#include "bondview.h"

//Public variables - move to header
// bss
//CODE.bss:80075D30
struct objective_entry * objective_ptrs[OBJECTIVES_MAX];
OBJECTIVESTATUS         dword_CODE_bss_80075D58[OBJECTIVES_MAX]; //This is an array of 10 OBJECTIVESTATUS,

//CODE.bss:80075D80
u32 *ptr_last_tag_entry_type16;
//CODE.bss:80075D84
struct watchMenuObjectiveText *ptr_last_briefing_setup_entry_type23;
//CODE.bss:80075D88
struct criteria_roomentered *ptr_last_enter_room_subobject_entry_type20;
//CODE.bss:80075D8C
struct criteria_deposit *ptr_last_deposit_in_room_subobject_entry_type21;
//CODE.bss:80075D90
u32 *ptr_last_photo_obj_in_room_subobject_entry_type1E;

// data
s32 objective_count = 0xFFFFFFFF;
s32 objective_count_related = 0;



/*
 * Return Tag with TagID
 */
TagObjectRecord *sub_GAME_7F057080(s32 TagID) //#MATCH
{
    u16              ID  = TagID;
    TagObjectRecord *tag = ptr_last_tag_entry_type16;
    while (tag)
    {
        if (tag->ID == ID)
        {
            return tag;
        }
        tag = tag->NextTag;
    }
    return NULL;
}





/*
 * Return Object with TagID  
 * Address 7F0570C0
 */
ObjectRecord *objFindByTagId(s32 TagID) //#MATCH
{
    TagObjectRecord *tag = sub_GAME_7F057080(TagID);
    ObjectRecord *   obj = NULL;

    if (tag)
    {
        obj = tag->TaggedObject;
    }
    if (obj && !(obj->runtime_bitflags & 0x10))
    {
        obj = NULL; //clear object
    }
    return obj;
}



u8 * get_ptr_text_for_watch_breifing_page(WATCH_BRIEFING_PAGE page)
{
    struct watchMenuObjectiveText * curentry;
    u8 * textptr;

    textptr = NULL;

    for (curentry = ptr_last_briefing_setup_entry_type23; curentry != 0; curentry = curentry->nextentry)
    {
        if (page == curentry->menu)
        {
            textptr = langGet(curentry->text);
            break;
        }
    }

    if (textptr == NULL)
    {
        if (page == 0)
        {
            textptr = langGet(TEXT(LMISC, MISC_STR_29)); //"E R R O R\n"
        }
        else if (page == 1)
        {
            textptr = langGet(TEXT(LMISC, MISC_STR_2A)); //"no briefing for this mission\n"
        }
        else
        {
            textptr = langGet(TEXT(LMISC, MISC_STR_2B)); //"\n"
        }
    }

    return textptr;
}



//objectiveGetCount
s32 objectiveGetCount(void)
{
    return objective_count + 1;
}



u8 * get_text_for_objective(int objectiveIndex)
{
    u8 *textptr;
    
    if ((objectiveIndex < 10) && (objective_ptrs[objectiveIndex] != 0)) {
        return langGet(objective_ptrs[objectiveIndex]->text);
    }
    return 0;
}



s32 get_difficulty_for_objective(s32 objectiveIndex)
{
    struct objective_entry * entry;

    if (objectiveIndex < OBJECTIVES_MAX)
    {
        entry = objective_ptrs[objectiveIndex];
        if (entry != NULL)
        {
            return entry->difficulty;
        }
    }
    return 0;
}



//horrible hack to get ai matching, but it does correctly refrence this func with 2 params
#pragma weak    objectiveGetStatus_WEAK = get_status_of_objective

/*
 * Return Status of objective.
 * Note: This matches but may not in future depending on the result of var
 * "OBJECTIVESTATUS *dword_CODE_bss_80075D58". 
 * https://decomp.me/scratch/MF31e
 */
OBJECTIVESTATUS get_status_of_objective(s32 objectiveNum) //#MATCH
{
    MissionObjectiveRecord *objective;
    OBJECTIVESTATUS         currentstatus;
    OBJECTIVESTATUS         status = OBJECTIVESTATUS_COMPLETE;

    if (objectiveNum < 10)
    {
        if (!&objective_ptrs[objectiveNum]->id)
        {
            status = dword_CODE_bss_80075D58[objectiveNum];
        }
        else
        {
            // for each objective in objectives
            for (objective = &objective_ptrs[objectiveNum]->id; objective->type != PROPDEF_OBJECTIVE_END; objective = sizepropdef(objective) + (PropDefHeaderRecord *)objective)
            {
                {
                    currentstatus = OBJECTIVESTATUS_COMPLETE;
                    switch (objective->type)
                    {
                        case PROPDEF_OBJECTIVE_DESTROY_OBJECT:
                        {
                            ObjectRecord *obj = objFindByTagId(objective->ObjRefID);
                            if (obj && obj->prop && objIsHealthy(obj))
                            {
                                currentstatus = OBJECTIVESTATUS_INCOMPLETE;
                            }
                            break;
                        }
                        case PROPDEF_OBJECTIVE_COMPLETE_CONDITION:
                        {
                            if (!chrHasStageFlag(NULL, objective->ObjRefID))
                            {
                                currentstatus = OBJECTIVESTATUS_INCOMPLETE;
                            }
                            break;
                        }
                        case PROPDEF_OBJECTIVE_FAIL_CONDITION:
                        {
                            if (chrHasStageFlag(NULL, objective->ObjRefID))
                            {
                                currentstatus = OBJECTIVESTATUS_FAILED;
                            }
                            break;
                        }
                        case PROPDEF_OBJECTIVE_COLLECT_OBJECT:
                        {
                            ObjectRecord *obj = objFindByTagId(objective->ObjRefID);
                            if (!obj || !obj->prop || !objIsHealthy(obj))
                            {
                                currentstatus = OBJECTIVESTATUS_FAILED;
                            }
                            else if (!bondinvHasPropInInv(obj->prop))
                            {
                                currentstatus = OBJECTIVESTATUS_INCOMPLETE;
                            }
                            break;
                        }
                        case PROPDEF_OBJECTIVE_DEPOSIT_OBJECT:
                        {
                            ObjectRecord *obj = objFindByTagId(objective->ObjRefID);
                            if (obj && obj->prop && bondinvHasPropInInv(obj->prop))
                            {
                                currentstatus = OBJECTIVESTATUS_INCOMPLETE;
                            }
                            break;
                        }
                        case PROPDEF_OBJECTIVE_PHOTOGRAPH:
                        {
                            ObjectRecord *obj = objFindByTagId(objective->ObjRefID);
                            if (!objective->TextID) //0x8
                            {
                                if (!obj || !obj->prop || !objIsHealthy(obj))
                                {
                                    currentstatus = OBJECTIVESTATUS_FAILED;
                                }
                                else
                                {
                                    currentstatus = OBJECTIVESTATUS_INCOMPLETE;
                                }
                            }
                            break;
                        }
                        case PROPDEF_OBJECTIVE_ENTER_ROOM:
                        {
                            if (!objective->TextID) //0x8
                            {
                                currentstatus = OBJECTIVESTATUS_INCOMPLETE;
                            }
                            break;
                        }
                        case PROPDEF_OBJECTIVE_DEPOSIT_OBJECT_IN_ROOM:
                        {
                            if (!objective->MinDificulty) //0xc
                            {
                                currentstatus = OBJECTIVESTATUS_INCOMPLETE;
                            }
                            break;
                        }
                        case PROPDEF_OBJECTIVE_COPY_ITEM:
                        {
                            if (!get_keyanalyzer_flag())
                            {
                                currentstatus = OBJECTIVESTATUS_INCOMPLETE;
                            }
                            break;
                        }
                        case PROPDEF_OBJECTIVE_END:
                        case PROPDEF_OBJECTIVE_START:
                        case PROPDEF_OBJECTIVE_NULL:
                        {
                            break;
                        }
                        default:
                        {
#    ifdef DEBUG
                            osSyncPrintf("unknown goal propdef %d\n", objective->type);
#    endif
                            break;
                        }
                    }
                    if (status == OBJECTIVESTATUS_COMPLETE)
                    {
                        if (currentstatus != OBJECTIVESTATUS_COMPLETE)
                        {
                            status = currentstatus;
                        }
                    }
                    else if ((status == OBJECTIVESTATUS_INCOMPLETE) && (currentstatus == OBJECTIVESTATUS_FAILED))
                    {
                        status = currentstatus;
                    }

                    //objective  = objheader;
                }
            }
        } // if objheader
    }     //objnum < 10

    if (get_debug_all_obj_complete_flag())
    {
        status = OBJECTIVESTATUS_COMPLETE;
    }
    return status;
}



bool objectiveIsAllComplete(void)
{
    DIFFICULTY objdiff;
    DIFFICULTY curdiff;
    int objective;
    
    for (objective = 0; objective < objectiveGetCount(); objective++)
    {
        objdiff = get_difficulty_for_objective(objective);
        curdiff = lvlGetSelectedDifficulty();
        if ((objdiff <= curdiff) && (get_status_of_objective(objective) != OBJECTIVESTATUS_COMPLETE))
        {
            return FALSE;
        }
    }
    return TRUE;
}


#ifdef BUGFIX_R1
void FUN_7f057a40(void)
{
  objective_count_related = 1;
  return;
}
#endif


void display_objective_status_text_on_status_change(void) {
    s32 i;
    s32 availableindex = 0;
    char buffer[50] = "";
    enum OBJECTIVESTATUS status;

#ifdef BUGFIX_R1
    if (objective_count_related != 0) { return; }
#endif

    for (i = 0; i <= objective_count; i++) {
        status = get_status_of_objective(i);
        if (dword_CODE_bss_80075D58[i] != status) {
            dword_CODE_bss_80075D58[i] = status;
            if (get_difficulty_for_objective(i) <= lvlGetSelectedDifficulty()) {
                if (j_text_trigger != 0) {
                    sprintf(&buffer, "%s \x80%c ", langGet(0xB02C), availableindex + 0x1A);
                } else {
                    sprintf(&buffer, "%s %c: ", langGet(0xB02C), availableindex + 0x61);
                }
                if (status == OBJECTIVESTATUS_COMPLETE) {
                    strcat(&buffer, langGet(0xB02D));
                } else if (status == OBJECTIVESTATUS_INCOMPLETE) {
                    strcat(&buffer, langGet(0xB02E));
                } else if (status == OBJECTIVESTATUS_FAILED) {
                    strcat(&buffer, langGet(0xB02F));
                }
#ifdef VERSION_US
                hudmsgBottomShow(&buffer);
#else
                jp_hudmsgBottomShow(&buffer);
#endif
            }
        }
        if (get_difficulty_for_objective(i) <= lvlGetSelectedDifficulty()) {
            availableindex++;
        }
    }
}


/**
 * Iterate list of ptr_last_enter_room_subobject_entry_type20, if it's the same
 * room as the argument then set the `flag` property.
 * 
 * US address 7F057744.
 * 
 * Perfect Dark method objectiveCheckRoomEntered.
*/
void objectivestatusCheckRoomEntered(s32 roomid)
{
    struct criteria_roomentered *var_v0;
    struct PadRecord* setupPad;
    struct StandTile *stan;
    
    var_v0 = ptr_last_enter_room_subobject_entry_type20;
    while (var_v0 != NULL)
    {
        if (var_v0->status == 0)
        {
            if (isNotBoundPad(var_v0->pad))
            {
                setupPad = &g_CurrentSetup.pads[var_v0->pad];
            }
            else
            {
                setupPad = (struct PadRecord*)&g_CurrentSetup.boundpads[getBoundPadNum((s32)var_v0->pad)];
            }

            stan = setupPad->stan;

            if ((stan != NULL) && (roomid == stan->room))
            {
                var_v0->status = 1;
            }
        }

        var_v0 = var_v0->next;
    }
}





/**
 * US address 7F0577E8.
*/
void objectivestatusCheckDeposit(s32 weaponnum, s32 roomid)
{
    struct criteria_deposit *dep;
    s32 padid;
    PadRecord *pad;

    for (dep = ptr_last_deposit_in_room_subobject_entry_type21; dep != NULL; dep = dep->next)
    {
        if (dep->flag == 0 && weaponnum == dep->weaponnum)
        {
            padid = dep->padid;

            if (isNotBoundPad((u32)padid))
            {
                pad = &g_CurrentSetup.pads[padid];
            }
            else
            {
                pad = (PadRecord *)&g_CurrentSetup.boundpads[getBoundPadNum(padid)];
            }

            if (pad->stan != NULL && roomid == pad->stan->room)
            {
                dep->flag = 1;
            }
        }
    }
}




#ifdef NONMATCHING
void objectiveTakePictureHandler(void) {

}
#else
GLOBAL_ASM(
.text
glabel objectiveTakePictureHandler
/* 08C3C8 7F057898 27BDFF68 */  addiu $sp, $sp, -0x98
/* 08C3CC 7F05789C AFB10034 */  sw    $s1, 0x34($sp)
/* 08C3D0 7F0578A0 3C118007 */  lui   $s1, %hi(ptr_last_photo_obj_in_room_subobject_entry_type1E)
/* 08C3D4 7F0578A4 8E315D90 */  lw    $s1, %lo(ptr_last_photo_obj_in_room_subobject_entry_type1E)($s1)
/* 08C3D8 7F0578A8 AFBF004C */  sw    $ra, 0x4c($sp)
/* 08C3DC 7F0578AC AFB60048 */  sw    $s6, 0x48($sp)
/* 08C3E0 7F0578B0 AFB50044 */  sw    $s5, 0x44($sp)
/* 08C3E4 7F0578B4 AFB40040 */  sw    $s4, 0x40($sp)
/* 08C3E8 7F0578B8 AFB3003C */  sw    $s3, 0x3c($sp)
/* 08C3EC 7F0578BC AFB20038 */  sw    $s2, 0x38($sp)
/* 08C3F0 7F0578C0 AFB00030 */  sw    $s0, 0x30($sp)
/* 08C3F4 7F0578C4 F7B60028 */  sdc1  $f22, 0x28($sp)
/* 08C3F8 7F0578C8 12200071 */  beqz  $s1, .L7F057A90
/* 08C3FC 7F0578CC F7B40020 */   sdc1  $f20, 0x20($sp)
/* 08C400 7F0578D0 4480B000 */  mtc1  $zero, $f22
/* 08C404 7F0578D4 24160001 */  li    $s6, 1
/* 08C408 7F0578D8 27B50064 */  addiu $s5, $sp, 0x64
/* 08C40C 7F0578DC 27B40074 */  addiu $s4, $sp, 0x74
/* 08C410 7F0578E0 27B3007C */  addiu $s3, $sp, 0x7c
/* 08C414 7F0578E4 27B20084 */  addiu $s2, $sp, 0x84
/* 08C418 7F0578E8 8E2E0008 */  lw    $t6, 8($s1)
.L7F0578EC:
/* 08C41C 7F0578EC 55C00066 */  bnezl $t6, .L7F057A88
/* 08C420 7F0578F0 8E31000C */   lw    $s1, 0xc($s1)
/* 08C424 7F0578F4 0FC15C30 */  jal   objFindByTagId
/* 08C428 7F0578F8 8E240004 */   lw    $a0, 4($s1)
/* 08C42C 7F0578FC 10400061 */  beqz  $v0, .L7F057A84
/* 08C430 7F057900 00408025 */   move  $s0, $v0
/* 08C434 7F057904 8C430010 */  lw    $v1, 0x10($v0)
/* 08C438 7F057908 5060005F */  beql  $v1, $zero, .L7F057A88
/* 08C43C 7F05790C 8E31000C */   lw    $s1, 0xc($s1)
/* 08C440 7F057910 906F0001 */  lbu   $t7, 1($v1)
/* 08C444 7F057914 31F80002 */  andi  $t8, $t7, 2
/* 08C448 7F057918 5300005B */  beql  $t8, $zero, .L7F057A88
/* 08C44C 7F05791C 8E31000C */   lw    $s1, 0xc($s1)
/* 08C450 7F057920 C4640018 */  lwc1  $f4, 0x18($v1)
/* 08C454 7F057924 4604B03E */  c.le.s $f22, $f4
/* 08C458 7F057928 00000000 */  nop   
/* 08C45C 7F05792C 45020056 */  bc1fl .L7F057A88
/* 08C460 7F057930 8E31000C */   lw    $s1, 0xc($s1)
/* 08C464 7F057934 0FC13BCD */  jal   objIsHealthy
/* 08C468 7F057938 00402025 */   move  $a0, $v0
/* 08C46C 7F05793C 10400051 */  beqz  $v0, .L7F057A84
/* 08C470 7F057940 02402825 */   move  $a1, $s2
/* 08C474 7F057944 8E040010 */  lw    $a0, 0x10($s0)
/* 08C478 7F057948 02603025 */  move  $a2, $s3
/* 08C47C 7F05794C 0FC1434C */  jal   sub_GAME_7F050D30
/* 08C480 7F057950 02803825 */   move  $a3, $s4
/* 08C484 7F057954 1040004B */  beqz  $v0, .L7F057A84
/* 08C488 7F057958 02402025 */   move  $a0, $s2
/* 08C48C 7F05795C 02602825 */  move  $a1, $s3
/* 08C490 7F057960 02803025 */  move  $a2, $s4
/* 08C494 7F057964 27A7006C */  addiu $a3, $sp, 0x6c
/* 08C498 7F057968 0FC0FE52 */  jal   sub_GAME_7F03F948
/* 08C49C 7F05796C AFB50010 */   sw    $s5, 0x10($sp)
/* 08C4A0 7F057970 0FC1E131 */  jal   getPlayer_c_screenleft
/* 08C4A4 7F057974 00000000 */   nop   
/* 08C4A8 7F057978 C7A6006C */  lwc1  $f6, 0x6c($sp)
/* 08C4AC 7F05797C 4606003C */  c.lt.s $f0, $f6
/* 08C4B0 7F057980 00000000 */  nop   
/* 08C4B4 7F057984 45020040 */  bc1fl .L7F057A88
/* 08C4B8 7F057988 8E31000C */   lw    $s1, 0xc($s1)
/* 08C4BC 7F05798C 0FC1E131 */  jal   getPlayer_c_screenleft
/* 08C4C0 7F057990 00000000 */   nop   
/* 08C4C4 7F057994 0FC1E129 */  jal   getPlayer_c_screenwidth
/* 08C4C8 7F057998 46000506 */   mov.s $f20, $f0
/* 08C4CC 7F05799C 46140280 */  add.s $f10, $f0, $f20
/* 08C4D0 7F0579A0 C7A8006C */  lwc1  $f8, 0x6c($sp)
/* 08C4D4 7F0579A4 460A403C */  c.lt.s $f8, $f10
/* 08C4D8 7F0579A8 00000000 */  nop   
/* 08C4DC 7F0579AC 45020036 */  bc1fl .L7F057A88
/* 08C4E0 7F0579B0 8E31000C */   lw    $s1, 0xc($s1)
/* 08C4E4 7F0579B4 0FC1E131 */  jal   getPlayer_c_screenleft
/* 08C4E8 7F0579B8 00000000 */   nop   
/* 08C4EC 7F0579BC C7B00064 */  lwc1  $f16, 0x64($sp)
/* 08C4F0 7F0579C0 4610003C */  c.lt.s $f0, $f16
/* 08C4F4 7F0579C4 00000000 */  nop   
/* 08C4F8 7F0579C8 4502002F */  bc1fl .L7F057A88
/* 08C4FC 7F0579CC 8E31000C */   lw    $s1, 0xc($s1)
/* 08C500 7F0579D0 0FC1E131 */  jal   getPlayer_c_screenleft
/* 08C504 7F0579D4 00000000 */   nop   
/* 08C508 7F0579D8 0FC1E129 */  jal   getPlayer_c_screenwidth
/* 08C50C 7F0579DC 46000506 */   mov.s $f20, $f0
/* 08C510 7F0579E0 46140100 */  add.s $f4, $f0, $f20
/* 08C514 7F0579E4 C7B20064 */  lwc1  $f18, 0x64($sp)
/* 08C518 7F0579E8 4604903C */  c.lt.s $f18, $f4
/* 08C51C 7F0579EC 00000000 */  nop   
/* 08C520 7F0579F0 45020025 */  bc1fl .L7F057A88
/* 08C524 7F0579F4 8E31000C */   lw    $s1, 0xc($s1)
/* 08C528 7F0579F8 0FC1E135 */  jal   getPlayer_c_screentop
/* 08C52C 7F0579FC 00000000 */   nop   
/* 08C530 7F057A00 C7A60070 */  lwc1  $f6, 0x70($sp)
/* 08C534 7F057A04 4606003C */  c.lt.s $f0, $f6
/* 08C538 7F057A08 00000000 */  nop   
/* 08C53C 7F057A0C 4502001E */  bc1fl .L7F057A88
/* 08C540 7F057A10 8E31000C */   lw    $s1, 0xc($s1)
/* 08C544 7F057A14 0FC1E135 */  jal   getPlayer_c_screentop
/* 08C548 7F057A18 00000000 */   nop   
/* 08C54C 7F057A1C 0FC1E12D */  jal   getPlayer_c_screenheight
/* 08C550 7F057A20 46000506 */   mov.s $f20, $f0
/* 08C554 7F057A24 46140280 */  add.s $f10, $f0, $f20
/* 08C558 7F057A28 C7A80070 */  lwc1  $f8, 0x70($sp)
/* 08C55C 7F057A2C 460A403C */  c.lt.s $f8, $f10
/* 08C560 7F057A30 00000000 */  nop   
/* 08C564 7F057A34 45020014 */  bc1fl .L7F057A88
/* 08C568 7F057A38 8E31000C */   lw    $s1, 0xc($s1)
/* 08C56C 7F057A3C 0FC1E135 */  jal   getPlayer_c_screentop
/* 08C570 7F057A40 00000000 */   nop   
/* 08C574 7F057A44 C7B00068 */  lwc1  $f16, 0x68($sp)
/* 08C578 7F057A48 4610003C */  c.lt.s $f0, $f16
/* 08C57C 7F057A4C 00000000 */  nop   
/* 08C580 7F057A50 4502000D */  bc1fl .L7F057A88
/* 08C584 7F057A54 8E31000C */   lw    $s1, 0xc($s1)
/* 08C588 7F057A58 0FC1E135 */  jal   getPlayer_c_screentop
/* 08C58C 7F057A5C 00000000 */   nop   
/* 08C590 7F057A60 0FC1E12D */  jal   getPlayer_c_screenheight
/* 08C594 7F057A64 46000506 */   mov.s $f20, $f0
/* 08C598 7F057A68 46140100 */  add.s $f4, $f0, $f20
/* 08C59C 7F057A6C C7B20068 */  lwc1  $f18, 0x68($sp)
/* 08C5A0 7F057A70 4604903C */  c.lt.s $f18, $f4
/* 08C5A4 7F057A74 00000000 */  nop   
/* 08C5A8 7F057A78 45020003 */  bc1fl .L7F057A88
/* 08C5AC 7F057A7C 8E31000C */   lw    $s1, 0xc($s1)
/* 08C5B0 7F057A80 AE360008 */  sw    $s6, 8($s1)
.L7F057A84:
/* 08C5B4 7F057A84 8E31000C */  lw    $s1, 0xc($s1)
.L7F057A88:
/* 08C5B8 7F057A88 5620FF98 */  bnezl $s1, .L7F0578EC
/* 08C5BC 7F057A8C 8E2E0008 */   lw    $t6, 8($s1)
.L7F057A90:
/* 08C5C0 7F057A90 8FBF004C */  lw    $ra, 0x4c($sp)
/* 08C5C4 7F057A94 D7B40020 */  ldc1  $f20, 0x20($sp)
/* 08C5C8 7F057A98 D7B60028 */  ldc1  $f22, 0x28($sp)
/* 08C5CC 7F057A9C 8FB00030 */  lw    $s0, 0x30($sp)
/* 08C5D0 7F057AA0 8FB10034 */  lw    $s1, 0x34($sp)
/* 08C5D4 7F057AA4 8FB20038 */  lw    $s2, 0x38($sp)
/* 08C5D8 7F057AA8 8FB3003C */  lw    $s3, 0x3c($sp)
/* 08C5DC 7F057AAC 8FB40040 */  lw    $s4, 0x40($sp)
/* 08C5E0 7F057AB0 8FB50044 */  lw    $s5, 0x44($sp)
/* 08C5E4 7F057AB4 8FB60048 */  lw    $s6, 0x48($sp)
/* 08C5E8 7F057AB8 03E00008 */  jr    $ra
/* 08C5EC 7F057ABC 27BD0098 */   addiu $sp, $sp, 0x98
)
#endif


//filebreak
