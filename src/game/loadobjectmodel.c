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
    
    if ((arg2 > 0.0f) && (sub_GAME_7F0B18B8(arg4, arg3->pos.f[0], arg3->pos.f[2], arg2, 0x1F, 0.0f, 1.0f) >= 0))
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
    struct modeldata_unk_pos *sp30;
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
        sp30 = sub_GAME_7F040078(obj);

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




#ifdef NONMATCHING

PropRecord *setupFindObjForReuse(s32 stageID, PropRecord **arg1, PropRecord **arg2, s32 arg3, s32 arg4, s32 arg5)
{
    PropRecord *temp_s0;
    PropRecord *temp_s0_2;
    u8          temp_v1;
    u8          temp_v1_2;
    void *      temp_v0;
    u8          phi_v1;
    PropRecord *phi_s0;
    PropRecord *phi_s2;
    PropRecord *phi_s3;
    PropRecord *phi_s2_2;
    PropRecord *phi_s3_2;
    PropRecord *phi_s2_3;
    PropRecord *phi_s3_3;


    temp_s0  = g_CurrentSetup.props;
    phi_s0   = temp_s0;
    phi_s2   = NULL;
    phi_s3   = NULL;
    phi_s2_2 = NULL;
    phi_s3_2 = NULL;
    if (temp_s0 != 0)
    {
        temp_v1 = temp_s0->unk3;
        phi_v1  = temp_v1;
        if (temp_v1 != 0x30)
        {
loop_3:
            phi_s2_3 = phi_s2;
            phi_s3_3 = phi_s3;
            phi_s2_3 = phi_s2;
            if ((stageID & 0xFF) == phi_v1)
            {
                temp_v0 = phi_s0->pos.AsArray[2];
                if (temp_v0 == 0)
                {
                    if ((arg3 == 0) && (arg4 == 0))
                    {
                        return phi_s0;
                    }
                    goto block_19;
                }
                if ((stageID != 8) && ((phi_s0->unk64 & 0x80) == 0) && ((phi_s0->unk2 & 4) == 0) && (temp_v0->unk1C == 0) && ((arg4 == 0) || (modelmgrCanSlotFitRwdata(phi_s0->stan, arg5) != 0)))
                {
                    if ((phi_s2 == 0) && ((phi_s0->pos.AsArray[2]->unk1 & 2) == 0))
                    {
                        phi_s2_3 = phi_s0;
                    }
                    if (phi_s3 == 0)
                    {
                        phi_s3_3 = phi_s0;
                    }
                }
                goto block_19;
            }
block_19:
            temp_s0_2 = (sizepropdef(phi_s0) * 4) + phi_s0;
            temp_v1_2 = temp_s0_2->unk3;
            phi_v1    = temp_v1_2;
            phi_s0    = temp_s0_2;
            phi_s2    = phi_s2_3;
            phi_s3    = phi_s3_3;
            phi_s2_2  = phi_s2_3;
            phi_s3_2  = phi_s3_3;
            if (temp_v1_2 == 0x30)
            {
                goto block_20;
            }
            goto loop_3;
        }
    }
block_20:
    *arg1 = phi_s2_2;
    *arg2 = phi_s3_2;
    return NULL;
}


#else
GLOBAL_ASM(
.text
glabel setupFindObjForReuse
/* 08BA38 7F056F08 27BDFFC0 */  addiu $sp, $sp, -0x40
/* 08BA3C 7F056F0C AFB00018 */  sw    $s0, 0x18($sp)
/* 08BA40 7F056F10 3C108007 */  lui   $s0, %hi(g_CurrentSetup+0x0c)
/* 08BA44 7F056F14 8E105D0C */  lw    $s0, %lo(g_CurrentSetup+0x0c)($s0)
/* 08BA48 7F056F18 AFBE0038 */  sw    $fp, 0x38($sp)
/* 08BA4C 7F056F1C AFB70034 */  sw    $s7, 0x34($sp)
/* 08BA50 7F056F20 AFB30024 */  sw    $s3, 0x24($sp)
/* 08BA54 7F056F24 AFB20020 */  sw    $s2, 0x20($sp)
/* 08BA58 7F056F28 0080B825 */  move  $s7, $a0
/* 08BA5C 7F056F2C 00E0F025 */  move  $fp, $a3
/* 08BA60 7F056F30 AFBF003C */  sw    $ra, 0x3c($sp)
/* 08BA64 7F056F34 AFB60030 */  sw    $s6, 0x30($sp)
/* 08BA68 7F056F38 AFB5002C */  sw    $s5, 0x2c($sp)
/* 08BA6C 7F056F3C AFB40028 */  sw    $s4, 0x28($sp)
/* 08BA70 7F056F40 AFB1001C */  sw    $s1, 0x1c($sp)
/* 08BA74 7F056F44 AFA50044 */  sw    $a1, 0x44($sp)
/* 08BA78 7F056F48 AFA60048 */  sw    $a2, 0x48($sp)
/* 08BA7C 7F056F4C 00009025 */  move  $s2, $zero
/* 08BA80 7F056F50 12000039 */  beqz  $s0, .L7F057038
/* 08BA84 7F056F54 00009825 */   move  $s3, $zero
/* 08BA88 7F056F58 92030003 */  lbu   $v1, 3($s0)
/* 08BA8C 7F056F5C 24010030 */  li    $at, 48
/* 08BA90 7F056F60 309400FF */  andi  $s4, $a0, 0xff
/* 08BA94 7F056F64 10610034 */  beq   $v1, $at, .L7F057038
/* 08BA98 7F056F68 24160008 */   li    $s6, 8
/* 08BA9C 7F056F6C 8FB50054 */  lw    $s5, 0x54($sp)
/* 08BAA0 7F056F70 8FB10050 */  lw    $s1, 0x50($sp)
.L7F056F74:
/* 08BAA4 7F056F74 16830028 */  bne   $s4, $v1, .L7F057018
/* 08BAA8 7F056F78 00000000 */   nop   
/* 08BAAC 7F056F7C 8E020010 */  lw    $v0, 0x10($s0)
/* 08BAB0 7F056F80 14400007 */  bnez  $v0, .L7F056FA0
/* 08BAB4 7F056F84 00000000 */   nop   
/* 08BAB8 7F056F88 17C00023 */  bnez  $fp, .L7F057018
/* 08BABC 7F056F8C 00000000 */   nop   
/* 08BAC0 7F056F90 16200021 */  bnez  $s1, .L7F057018
/* 08BAC4 7F056F94 00000000 */   nop   
/* 08BAC8 7F056F98 1000002C */  b     .L7F05704C
/* 08BACC 7F056F9C 02001025 */   move  $v0, $s0
.L7F056FA0:
/* 08BAD0 7F056FA0 12F6001D */  beq   $s7, $s6, .L7F057018
/* 08BAD4 7F056FA4 00000000 */   nop   
/* 08BAD8 7F056FA8 8E0E0064 */  lw    $t6, 0x64($s0)
/* 08BADC 7F056FAC 31CF0080 */  andi  $t7, $t6, 0x80
/* 08BAE0 7F056FB0 15E00019 */  bnez  $t7, .L7F057018
/* 08BAE4 7F056FB4 00000000 */   nop   
/* 08BAE8 7F056FB8 92180002 */  lbu   $t8, 2($s0)
/* 08BAEC 7F056FBC 33190004 */  andi  $t9, $t8, 4
/* 08BAF0 7F056FC0 17200015 */  bnez  $t9, .L7F057018
/* 08BAF4 7F056FC4 00000000 */   nop   
/* 08BAF8 7F056FC8 8C48001C */  lw    $t0, 0x1c($v0)
/* 08BAFC 7F056FCC 15000012 */  bnez  $t0, .L7F057018
/* 08BB00 7F056FD0 00000000 */   nop   
/* 08BB04 7F056FD4 12200005 */  beqz  $s1, .L7F056FEC
/* 08BB08 7F056FD8 02A02825 */   move  $a1, $s5
/* 08BB0C 7F056FDC 0FC1B018 */  jal   modelmgrCanSlotFitRwdata
/* 08BB10 7F056FE0 8E040014 */   lw    $a0, 0x14($s0)
/* 08BB14 7F056FE4 1040000C */  beqz  $v0, .L7F057018
/* 08BB18 7F056FE8 00000000 */   nop   
.L7F056FEC:
/* 08BB1C 7F056FEC 16400007 */  bnez  $s2, .L7F05700C
/* 08BB20 7F056FF0 00000000 */   nop   
/* 08BB24 7F056FF4 8E090010 */  lw    $t1, 0x10($s0)
/* 08BB28 7F056FF8 912A0001 */  lbu   $t2, 1($t1)
/* 08BB2C 7F056FFC 314B0002 */  andi  $t3, $t2, 2
/* 08BB30 7F057000 15600002 */  bnez  $t3, .L7F05700C
/* 08BB34 7F057004 00000000 */   nop   
/* 08BB38 7F057008 02009025 */  move  $s2, $s0
.L7F05700C:
/* 08BB3C 7F05700C 16600002 */  bnez  $s3, .L7F057018
/* 08BB40 7F057010 00000000 */   nop   
/* 08BB44 7F057014 02009825 */  move  $s3, $s0
.L7F057018:
/* 08BB48 7F057018 0FC15A3D */  jal   sizepropdef
/* 08BB4C 7F05701C 02002025 */   move  $a0, $s0
/* 08BB50 7F057020 00026080 */  sll   $t4, $v0, 2
/* 08BB54 7F057024 01908021 */  addu  $s0, $t4, $s0
/* 08BB58 7F057028 92030003 */  lbu   $v1, 3($s0)
/* 08BB5C 7F05702C 24010030 */  li    $at, 48
/* 08BB60 7F057030 1461FFD0 */  bne   $v1, $at, .L7F056F74
/* 08BB64 7F057034 00000000 */   nop   
.L7F057038:
/* 08BB68 7F057038 8FAD0044 */  lw    $t5, 0x44($sp)
/* 08BB6C 7F05703C 00001025 */  move  $v0, $zero
/* 08BB70 7F057040 ADB20000 */  sw    $s2, ($t5)
/* 08BB74 7F057044 8FAE0048 */  lw    $t6, 0x48($sp)
/* 08BB78 7F057048 ADD30000 */  sw    $s3, ($t6)
.L7F05704C:
/* 08BB7C 7F05704C 8FBF003C */  lw    $ra, 0x3c($sp)
/* 08BB80 7F057050 8FB00018 */  lw    $s0, 0x18($sp)
/* 08BB84 7F057054 8FB1001C */  lw    $s1, 0x1c($sp)
/* 08BB88 7F057058 8FB20020 */  lw    $s2, 0x20($sp)
/* 08BB8C 7F05705C 8FB30024 */  lw    $s3, 0x24($sp)
/* 08BB90 7F057060 8FB40028 */  lw    $s4, 0x28($sp)
/* 08BB94 7F057064 8FB5002C */  lw    $s5, 0x2c($sp)
/* 08BB98 7F057068 8FB60030 */  lw    $s6, 0x30($sp)
/* 08BB9C 7F05706C 8FB70034 */  lw    $s7, 0x34($sp)
/* 08BBA0 7F057070 8FBE0038 */  lw    $fp, 0x38($sp)
/* 08BBA4 7F057074 03E00008 */  jr    $ra
/* 08BBA8 7F057078 27BD0040 */   addiu $sp, $sp, 0x40
)
#endif



