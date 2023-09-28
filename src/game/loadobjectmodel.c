#include <ultra64.h>
#include <bondtypes.h>
#include "chrai.h"
#include "chrobjdata.h"
#include "chrobjhandler.h"
#include "loadobjectmodel.h"
#include "stan.h"

/**
 * Address 0x7F056850.
*/
s32 sub_GAME_7F056850(PadRecord *arg0, StandTile *arg1, f32 arg2, PadRecord *arg3, StandTile **arg4)
{
    arg3->pos.f[0] = arg0->pos.f[0];
    arg3->pos.f[1] = arg0->pos.f[1];
    arg3->pos.f[2] = arg0->pos.f[2];
    
    *arg4 = arg1;
    
    if (arg1 == 0)
    {
        return 0;
    }
    
    if ((arg2 > 0.0f) && (stanTestVolume(arg4, arg3->pos.f[0], arg3->pos.f[2], arg2, 0x1F, 0.0f, 1.0f) >= 0))
    {
        return 0;
    }
    
    return 1;
}

//Todo: finish this func
/**
 * Get Size of Prop Definition 
 * @param pdef:  Prop Defenition to get size of
 * @return Size of prop in Words (32bit)
*/
s32 sizepropdef(PropDefHeaderRecord *pdef)
{
    switch(pdef->type)
    {
        case PROPDEF_GUARD:
            return sizeof(GuardRecord) / 4;
        case PROPDEF_DOOR:
            return sizeof(DoorRecord) / 4;
        case PROPDEF_DOOR_SCALE:
            return sizeof(GlobalDoorScaleRecord) / 4;
        case PROPDEF_PROP:
            return sizeof(ObjectRecord) / 4;
        case PROPDEF_GLASS:
            return sizeof(ObjectRecord) / 4;
        case PROPDEF_TINTED_GLASS:
            return 0x25;//return sizeof(TintedGlassRecord) / 4;
        case PROPDEF_SAFE:
            return 0x20;//return sizeof(GlassRecord) / 4;
        case PROPDEF_GAS_RELEASING:
            return 0x20;//return sizeof(GlassRecord) / 4;
        case PROPDEF_KEY:
            return 0x21;//return sizeof(GlassRecord) / 4;
        case PROPDEF_ALARM:
            return 0x20;//return sizeof(GlassRecord) / 4;
        case PROPDEF_CCTV:
            return 0x3b;//return sizeof(GlassRecord) / 4;
        case PROPDEF_MAGAZINE:
            return 0x21;//return sizeof(GlassRecord) / 4;
        case PROPDEF_COLLECTABLE:
            return 0x22;//return sizeof(GlassRecord) / 4;
        case PROPDEF_MONITOR:
            return 0x40;//return sizeof(GlassRecord) / 4;
        case PROPDEF_MULTI_MONITOR:
            return 0x95;//return sizeof(GlassRecord) / 4;
        case PROPDEF_RACK:
            return 0x20;//return sizeof(GlassRecord) / 4;
        case PROPDEF_AUTOGUN:
            return 0x36;//return sizeof(GlassRecord) / 4;
        case PROPDEF_LINK:
            return 3;//return sizeof(GlassRecord) / 4;
        case PROPDEF_HAT:
            return 0x20;//return sizeof(GlassRecord) / 4;
        case PROPDEF_GUARD_ATTRIBUTE:
            return 3;//return sizeof(GlassRecord) / 4;
        case PROPDEF_SWITCH:
            return 4;//return sizeof(GlassRecord) / 4;
        case PROPDEF_SAFE_ITEM:
            return 5;//return sizeof(GlassRecord) / 4;
        case PROPDEF_AMMO:
            return 0x2d;//return sizeof(GlassRecord) / 4;
        case PROPDEF_ARMOUR:
            return 0x22;//return sizeof(GlassRecord) / 4;
        case PROPDEF_TAG:
            return 4;//return sizeof(GlassRecord) / 4;
        case PROPDEF_RENAME:
            return 10;//return sizeof(GlassRecord) / 4;
        case PROPDEF_OBJECTIVE_START:
            return 4;//return sizeof(GlassRecord) / 4;
        case PROPDEF_OBJECTIVE_END:
            return 1;//return sizeof(GlassRecord) / 4;
        case PROPDEF_OBJECTIVE_DESTROY_OBJECT:
            return 2;//return sizeof(GlassRecord) / 4;
        case PROPDEF_OBJECTIVE_COMPLETE_CONDITION:
            return 2;//return sizeof(GlassRecord) / 4;
        case PROPDEF_OBJECTIVE_FAIL_CONDITION:
            return 2;//return sizeof(GlassRecord) / 4;
        case PROPDEF_OBJECTIVE_COLLECT_OBJECT:
            return 2;//return sizeof(GlassRecord) / 4;
        case PROPDEF_OBJECTIVE_DEPOSIT_OBJECT:
            return 2;//return sizeof(GlassRecord) / 4;
        case PROPDEF_OBJECTIVE_PHOTOGRAPH:
            return 4;//return sizeof(GlassRecord) / 4;
        case PROPDEF_OBJECTIVE_NULL:
            return 1;//return sizeof(GlassRecord) / 4;
        case PROPDEF_OBJECTIVE_ENTER_ROOM:
            return 4;//return sizeof(GlassRecord) / 4;
        case PROPDEF_OBJECTIVE_DEPOSIT_OBJECT_IN_ROOM:
            return 5;//return sizeof(GlassRecord) / 4;
        case PROPDEF_OBJECTIVE_COPY_ITEM:
            return 1;//return sizeof(GlassRecord) / 4;
        case PROPDEF_WATCH_MENU_OBJECTIVE_TEXT:
            return 4;//return sizeof(GlassRecord) / 4;
        case PROPDEF_LOCK_DOOR:
            return 4;//return sizeof(GlassRecord) / 4;
        case PROPDEF_VEHICHLE:
            return 0x2c;//return sizeof(GlassRecord) / 4;
        case PROPDEF_AIRCRAFT:
            return 0x2d;//return sizeof(GlassRecord) / 4;
        case PROPDEF_TANK:
            return 0x38;//return sizeof(GlassRecord) / 4;
        case PROPDEF_CAMERAPOS:
            return 7;//return sizeof(GlassRecord) / 4;
        default:
            return sizeof(PropDefHeaderRecord) / 4;;
    }
}




/*
 *Return Item by Setup index
 *Setup Array is most likley PropDefHeaderRecord since size was 4
 */
ObjectRecord *setupGetPtrToCommandByIndex(s32 index) //#MATCH
{
    PropDefHeaderRecord *object = g_CurrentSetup.propDefs; //wow, first use of header, cool

    if (index >= 0 && object)
    {
        s32 i;
        for (i = 0; object->type != PROPDEF_END; i++)
        {
            if (i == index)
            {
                return object;
            }

            object = sizepropdef(object) + object; //This is correct order, using += swaps t7/s1
        }
    }

    return NULL;
}




/**
 * Address 0x7F056B1C.
*/
s32 tagGetCommandIndex(struct ObjectRecord *tag)
{
    PropDefHeaderRecord *object;
    s32 i;

    object = g_CurrentSetup.propDefs;

    if (object != NULL)
    {
        for (i = 0; object->type != PROPDEF_END; i++)
        {
            if ((void*)object == (void*)tag)
            {
                return i;
            }

            object = sizepropdef(object) + object;
        }
    }

    return -1;
}



/**
 * Address 0x7F056BA8.
*/
s32 setupGetCommandIndexByProp(struct PropRecord *prop)
{
    PropDefHeaderRecord *object;
    s32 i;

    object = g_CurrentSetup.propDefs;

    if (object != NULL)
    {
        for (i = 0; object->type != PROPDEF_END; i++)
        {
            if ((void*)((struct ObjectRecord *)object)->prop == (void*)prop)
            {
                return i;
            }

            object = sizepropdef(object) + object;
        }
    }

    return -1;
}



s32 modelLoad(s32 modelid)
{
    if (PitemZ_entries[modelid].header->RootNode == NULL) 
    {
        fileLoad(PitemZ_entries[modelid].header,PitemZ_entries[modelid].filename);
        modelCalculateRwDataLen(PitemZ_entries[modelid].header);
        return TRUE;
    }
    return FALSE;
}




/**
 * Address 0x7F056CA0.
*/
void setupUpdateObjectRoomPosition(ObjectRecord *obj)
{
    PropRecord *temp_s1;
    struct coord3d sp40;
    struct coord3d sp34;
    struct ModelRoData_BoundingBoxRecord *sp30;
    f32 phi_f20;

    temp_s1 = obj->prop;
    phi_f20 = 0.0f;
    chrpropDeregisterRooms(temp_s1);

    if (obj->flags2 & 0x20000)
    {
        if (temp_s1->stan != NULL)
        {
            temp_s1->rooms[0] = temp_s1->stan->room;
            temp_s1->rooms[1] = (u8)-1;
        }
        else
        {
            temp_s1->rooms[0] = (u8)-1;
        }
    }
    else
    {
        sp30 = chrobjGetBboxFromObjectRecord(obj);

        if (sp30 != NULL)
        {
            sp40.f[0] = chrpropSumMatrixPosX(sp30, &obj->mtx) - 30.0f;
            sp40.f[1] = chrpropSumMatrixPosY(sp30, &obj->mtx);
            sp40.f[2] = chrpropSumMatrixPosZ(sp30, &obj->mtx) - 30.0f;

            sp34.f[0] = chrpropSumMatrixNegX(sp30, &obj->mtx) + 30.0f;
            sp34.f[1] = chrpropSumMatrixNegY(sp30, &obj->mtx);
            sp34.f[2] = chrpropSumMatrixNegZ(sp30, &obj->mtx) + 30.0f;

            if (phi_f20 < -sp40.f[0])
            {
                phi_f20 = -sp40.f[0];
            }

            if (phi_f20 < -sp40.f[2])
            {
                phi_f20 = -sp40.f[2];
            }

            if (phi_f20 < sp34.f[0])
            {
                phi_f20 = sp34.f[0];
            }

            if (phi_f20 < sp34.f[2])
            {
                phi_f20 = sp34.f[2];
            }

            sp40.f[0] += obj->runtime_pos.f[0];
            sp40.f[1] += obj->runtime_pos.f[1];
            sp40.f[2] += obj->runtime_pos.f[2];

            sp34.f[0] += obj->runtime_pos.f[0];
            sp34.f[1] += obj->runtime_pos.f[1];
            sp34.f[2] += obj->runtime_pos.f[2];

            sub_GAME_7F03E27C(temp_s1, &sp40, &sp34, phi_f20);
        }
    }

    chrpropRegisterRooms(temp_s1);
}



/**
 * Address 0x7F056EA0.
*/
struct ObjectRecord *setupCommandGetObject(s32 stageID, s32 index)
{
    struct PropDefHeaderRecord *obj;

    obj = setupGetPtrToCommandByIndex(index);

    if (obj != NULL)
    {
        switch (obj->type)
        {
            case PROPDEF_DOOR:    //1
            case PROPDEF_PROP: //3:
            case PROPDEF_KEY:  //4:
            case PROPDEF_ALARM: // 5:
            case PROPDEF_CCTV: //6:
            case PROPDEF_MAGAZINE: //7:
            case PROPDEF_COLLECTABLE: // 8:
            case PROPDEF_MONITOR: //10:
            case PROPDEF_MULTI_MONITOR:// 11:
            case PROPDEF_RACK: //12:
            case PROPDEF_AUTOGUN: //13:
            case PROPDEF_HAT: //17:
            case PROPDEF_AMMO: //20:
            case PROPDEF_ARMOUR: //21:
            case PROPDEF_GAS_RELEASING: //36:
            case PROPDEF_VEHICHLE: //39:
            case PROPDEF_AIRCRAFT: //40:
            case PROPDEF_UNK41: //41:
            case PROPDEF_GLASS: //42:
            case PROPDEF_SAFE: //43:
            case PROPDEF_TANK: //45:
            case PROPDEF_TINTED_GLASS:                 //47:
                return obj;
            break;

            case PROPDEF_DOOR_SCALE: //2
            case PROPDEF_GUARD:           //9 :
            case PROPDEF_LINK:            //14:
            case PROPDEF_GUARD_ATTRIBUTE: //18:
            case PROPDEF_SWITCH:          //19:
            case PROPDEF_TAG:             //22:
            case PROPDEF_OBJECTIVE_START: //23
            case PROPDEF_OBJECTIVE_END:
            case PROPDEF_OBJECTIVE_DESTROY_OBJECT:
            case PROPDEF_OBJECTIVE_COMPLETE_CONDITION:
            case PROPDEF_OBJECTIVE_FAIL_CONDITION:
            case PROPDEF_OBJECTIVE_COLLECT_OBJECT:
            case PROPDEF_OBJECTIVE_DEPOSIT_OBJECT:
            case PROPDEF_OBJECTIVE_PHOTOGRAPH:
            case PROPDEF_OBJECTIVE_NULL:
            case PROPDEF_OBJECTIVE_ENTER_ROOM:
            case PROPDEF_OBJECTIVE_DEPOSIT_OBJECT_IN_ROOM:
            case PROPDEF_OBJECTIVE_COPY_ITEM:
            case PROPDEF_WATCH_MENU_OBJECTIVE_TEXT: //35
            case PROPDEF_RENAME:                    //37:
            case PROPDEF_LOCK_DOOR:                 //38:
            case PROPDEF_SAFE_ITEM:                 //44:
            case PROPDEF_CAMERAPOS:                 //46:
                return NULL;
            break;

            // not included:
            //case PROPDEF_UNK15: //15:
            //case PROPDEF_UNK16: //16:
            // return ???
        }
    }
    return obj;
}


ObjectRecord *setupFindObjForReuse(s32 wanttype, ObjectRecord **offscreenobjptr, ObjectRecord **anyobjptr, bool musthaveprop, bool musthavemodel, ModelFileHeader *modeldef)
{
    ObjectRecord *offscreenobj = NULL;
    ObjectRecord *anyobj = NULL;

    u32 *cmd = g_CurrentSetup.propDefs;

    if (cmd)
    {
        while ((u8)cmd[0] != PROPDEF_END)
        {
            if ((wanttype & 0xff) == (u8)cmd[0])
            {
                ObjectRecord *obj = (ObjectRecord *)cmd;

                if (obj->prop == NULL)
                {
                    if (!musthaveprop && !musthavemodel)
                    {
                        return obj;
                    }
                }
                else if (wanttype != PROP_TYPE_SMOKE
                        && (obj->runtime_bitflags & RUNTIMEBITFLAG_DEPOSIT) == 0
                        && (obj->state & PROPSTATE_RESPAWN) == 0
                        && obj->prop->parent == NULL
                        && (!musthavemodel || modelmgrCanSlotFitRwdata(obj->model, modeldef)))
                {
                    if (offscreenobj == NULL && (obj->prop->flags & PROPFLAG_ONSCREEN) == 0)
                    {
                        offscreenobj = obj;
                    }

                    if (anyobj == NULL)
                    {
                        anyobj = obj;
                    }
                }
            }

            cmd = cmd + sizepropdef(cmd);
        }
    }

    *offscreenobjptr = offscreenobj;
    *anyobjptr = anyobj;

    return NULL;
}

