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
OBJECTIVESTATUS         objectiveStatuses[OBJECTIVES_MAX]; //This is an array of 10 OBJECTIVESTATUS,

//CODE.bss:80075D80
u32 *ptr_last_tag_entry_type16;
//CODE.bss:80075D84
struct watchMenuObjectiveText *ptr_last_briefing_setup_entry_type23;
//CODE.bss:80075D88
struct criteria_roomentered *ptr_last_enter_room_subobject_entry_type20;
//CODE.bss:80075D8C
struct criteria_deposit *ptr_last_deposit_in_room_subobject_entry_type21;
//CODE.bss:80075D90
struct criteria_picture *ptr_last_photo_obj_in_room_subobject_entry_type1E;

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



/*
* Address: 0x7f057104
*/
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
            textptr = langGet(getStringID(LMISC, MISC_STR_29_ERROR_LF)); //"E R R O R\n"
        }
        else if (page == 1)
        {
            textptr = langGet(getStringID(LMISC, MISC_STR_2A_NOBRIEFING_LF)); //"no briefing for this mission\n"
        }
        else
        {
            textptr = langGet(getStringID(LMISC, MISC_STR_2B_LF)); //"\n"
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
 * "OBJECTIVESTATUS *objectiveStatuses". 
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
            status = objectiveStatuses[objectiveNum];
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
        if (objectiveStatuses[i] != status) {
            objectiveStatuses[i] = status;
            if (get_difficulty_for_objective(i) <= lvlGetSelectedDifficulty()) {
                if (j_text_trigger != 0)
                {
                    sprintf(&buffer, "%s \x80%c ", langGet(getStringID(LMISC, MISC_STR_2C_OBJECTIVE)), availableindex + 0x1A);
                }
                else
                {
                    sprintf(&buffer, "%s %c: ", langGet(getStringID(LMISC, MISC_STR_2C_OBJECTIVE)), availableindex + 0x61);
                }
                if (status == OBJECTIVESTATUS_COMPLETE)
                {
                    strcat(&buffer, langGet(getStringID(LMISC, MISC_STR_2D_COMPLETED_LF)));
                }
                else if (status == OBJECTIVESTATUS_INCOMPLETE)
                {
                    strcat(&buffer, langGet(getStringID(LMISC, MISC_STR_2E_INCOMPLETE_LF)));
                }
                else if (status == OBJECTIVESTATUS_FAILED)
                {
                    strcat(&buffer, langGet(getStringID(LMISC, MISC_STR_2F_FAILED_LF)));
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



/**
 * NTSC address 0x7F057898.
*/
void objectiveTakePictureHandler(void)
{
    ObjectRecord *target_object;
    PropRecord *target_prop;
    struct coord3d sp84;
    struct coord2d sp7C;
    struct coord2d sp74;
    struct rectbbox sp64;
    s32 padding2[2];
    struct criteria_picture *criteria;

    criteria = ptr_last_photo_obj_in_room_subobject_entry_type1E;
    for (; criteria != NULL; criteria = criteria->next)
    {
        if (criteria->flag == 0)
        {
            target_object = objFindByTagId(criteria->tag_id);
            
            if (target_object != NULL)
            {
                target_prop = target_object->prop;
                
                if ((target_prop != NULL) 
                    && (target_prop->flags & PROPFLAG_ONSCREEN)
                    && (target_prop->zDepth >= 0.0f) // draw/render distance
                    && (objIsHealthy(target_object) != 0)
                    && (sub_GAME_7F050D30(target_object->prop, &sp84, &sp7C, &sp74) != 0))
                {
                    sub_GAME_7F03F948(&sp84, &sp7C, &sp74, &sp64.right, &sp64.left);
                    
                    if (getPlayer_c_screenleft() < sp64.right)
                    {
                        if ((sp64.right < (getPlayer_c_screenleft() + getPlayer_c_screenwidth())) && (getPlayer_c_screenleft() < sp64.left))
                        {
                            if ((sp64.left < (getPlayer_c_screenleft() + getPlayer_c_screenwidth())) && (getPlayer_c_screentop() < sp64.down))
                            {
                                if ((sp64.down < (getPlayer_c_screentop() + getPlayer_c_screenheight())) && (getPlayer_c_screentop() < sp64.up))
                                {
                                    if (sp64.up < (getPlayer_c_screentop() + getPlayer_c_screenheight()))
                                    {
                                        criteria->flag = 1;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}


//filebreak
