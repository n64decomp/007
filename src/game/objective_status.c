#include <ultra64.h>
#include <bondconstants.h>
#include <bondtypes.h>
#include "objective_status.h"

//Public variables - move to header
// bss
//CODE.bss:80075D30
struct objective_entry * objective_ptrs[10];
OBJECTIVESTATUS         dword_CODE_bss_80075D58[10]; //This is an array of 10 OBJECTIVESTATUS,

//CODE.bss:80075D80
u32 *ptr_last_tag_entry_type16;
//CODE.bss:80075D84
u32 *ptr_last_briefing_setup_entry_type23;
//CODE.bss:80075D88
u32 *ptr_last_enter_room_subobject_entry_type20;
//CODE.bss:80075D8C
u32 *ptr_last_deposit_in_room_subobject_entry_type21;
//CODE.bss:80075D90
u32 *ptr_last_photo_obj_in_room_subobject_entry_type1E;

// data
s32 num_objective_ptrs[] = {0xFFFFFFFF, 0};



// rodata
const u32 D_80053610[] = {0,0,0,0,0,0,0,0,0,0,0,0,0};
//D:80053644
const u32 aSAC[] = {0x25732080, 0x25632000};
//D:8005364C
const char aSC[] = "%s %c: ";



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






#ifdef NONMATCHING
u8 * get_ptr_text_for_watch_breifing_page(WATCH_BRIEFING_PAGE page)
{
    struct watchMenuObjectiveText * curentry;
    u8 * textptr;

    textptr = 0;
    for (curentry = ptr_last_briefing_setup_entry_type23; curentry != 0; curentry = curentry->nextentry)
    {
        if (page == curentry->menu)
        {
            textptr = langGet(curentry->text);
        }
        textptr = 0;
    }
    if (textptr == 0)
    {
        if (page == 0)
        {
            textptr = langGet(TEXT(LMISC, 0x29)); //"E R R O R\n"
        }
        else
        {
            if (page == 1)
            {
                textptr = langGet(TEXT(LMISC, 0x2a)); //"no briefing for this mission\n"
            }
            else
            {
                textptr = langGet(TEXT(LMISC, 0x2b)); //"\n"
            }
        }
    }
    return textptr;
}
#else
GLOBAL_ASM(
.text
glabel get_ptr_text_for_watch_breifing_page
/* 08BC34 7F057104 3C028007 */  lui   $v0, %hi(ptr_last_briefing_setup_entry_type23)
/* 08BC38 7F057108 8C425D84 */  lw    $v0, %lo(ptr_last_briefing_setup_entry_type23)($v0)
/* 08BC3C 7F05710C 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 08BC40 7F057110 AFBF0014 */  sw    $ra, 0x14($sp)
/* 08BC44 7F057114 00802825 */  move  $a1, $a0
/* 08BC48 7F057118 1040000D */  beqz  $v0, .L7F057150
/* 08BC4C 7F05711C 00001825 */   move  $v1, $zero
/* 08BC50 7F057120 8C4E0004 */  lw    $t6, 4($v0)
.L7F057124:
/* 08BC54 7F057124 54AE0008 */  bnel  $a1, $t6, .L7F057148
/* 08BC58 7F057128 8C42000C */   lw    $v0, 0xc($v0)
/* 08BC5C 7F05712C 9444000A */  lhu   $a0, 0xa($v0)
/* 08BC60 7F057130 0FC30776 */  jal   langGet
/* 08BC64 7F057134 AFA50018 */   sw    $a1, 0x18($sp)
/* 08BC68 7F057138 8FA50018 */  lw    $a1, 0x18($sp)
/* 08BC6C 7F05713C 10000004 */  b     .L7F057150
/* 08BC70 7F057140 00401825 */   move  $v1, $v0
/* 08BC74 7F057144 8C42000C */  lw    $v0, 0xc($v0)
.L7F057148:
/* 08BC78 7F057148 5440FFF6 */  bnezl $v0, .L7F057124
/* 08BC7C 7F05714C 8C4E0004 */   lw    $t6, 4($v0)
.L7F057150:
/* 08BC80 7F057150 54600011 */  bnezl $v1, .L7F057198
/* 08BC84 7F057154 8FBF0014 */   lw    $ra, 0x14($sp)
/* 08BC88 7F057158 14A00005 */  bnez  $a1, .L7F057170
/* 08BC8C 7F05715C 24010001 */   li    $at, 1
/* 08BC90 7F057160 0FC30776 */  jal   langGet
/* 08BC94 7F057164 3404B029 */   li    $a0, 45097
/* 08BC98 7F057168 1000000A */  b     .L7F057194
/* 08BC9C 7F05716C 00401825 */   move  $v1, $v0
.L7F057170:
/* 08BCA0 7F057170 14A10005 */  bne   $a1, $at, .L7F057188
/* 08BCA4 7F057174 00000000 */   nop   
/* 08BCA8 7F057178 0FC30776 */  jal   langGet
/* 08BCAC 7F05717C 3404B02A */   li    $a0, 45098
/* 08BCB0 7F057180 10000004 */  b     .L7F057194
/* 08BCB4 7F057184 00401825 */   move  $v1, $v0
.L7F057188:
/* 08BCB8 7F057188 0FC30776 */  jal   langGet
/* 08BCBC 7F05718C 3404B02B */   li    $a0, 45099
/* 08BCC0 7F057190 00401825 */  move  $v1, $v0
.L7F057194:
/* 08BCC4 7F057194 8FBF0014 */  lw    $ra, 0x14($sp)
.L7F057198:
/* 08BCC8 7F057198 27BD0018 */  addiu $sp, $sp, 0x18
/* 08BCCC 7F05719C 00601025 */  move  $v0, $v1
/* 08BCD0 7F0571A0 03E00008 */  jr    $ra
/* 08BCD4 7F0571A4 00000000 */   nop   
)
#endif





//objectiveGetCount
s32 objectiveGetCount(void)
{
    return num_objective_ptrs[0]+1;
}



u8 * get_text_for_objective(int objective)
{
    u8 *textptr;
    
    if ((objective < 10) && (objective_ptrs[objective] != 0)) {
        return langGet(objective_ptrs[objective]->text);
    }
    return 0;
}





#ifdef NONMATCHING
void get_difficulty_for_objective(void) {

}
#else
GLOBAL_ASM(
.text
glabel get_difficulty_for_objective
/* 08BD34 7F057204 2881000A */  slti  $at, $a0, 0xa
/* 08BD38 7F057208 10200008 */  beqz  $at, .L7F05722C
/* 08BD3C 7F05720C 00047080 */   sll   $t6, $a0, 2
/* 08BD40 7F057210 3C038007 */  lui   $v1, %hi(objective_ptrs)
/* 08BD44 7F057214 006E1821 */  addu  $v1, $v1, $t6
/* 08BD48 7F057218 8C635D30 */  lw    $v1, %lo(objective_ptrs)($v1)
/* 08BD4C 7F05721C 50600004 */  beql  $v1, $zero, .L7F057230
/* 08BD50 7F057220 00001025 */   move  $v0, $zero
/* 08BD54 7F057224 03E00008 */  jr    $ra
/* 08BD58 7F057228 8062000F */   lb    $v0, 0xf($v1)

.L7F05722C:
/* 08BD5C 7F05722C 00001025 */  move  $v0, $zero
.L7F057230:
/* 08BD60 7F057230 03E00008 */  jr    $ra
/* 08BD64 7F057234 00000000 */   nop   
)
#endif



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
  num_objective_ptrs[1] = 1;
  return;
}
#endif

#ifdef NONMATCHING
void display_objective_status_text_on_status_change(void) {

}
#else

#ifdef VERSION_US
GLOBAL_ASM(
.rdata
/*glabel D_80053610*/
/*.word 0,0,0,0,0,0,0,0,0,0*/
/*glabel D_80053640*/
/*.word 0*/
.text
glabel display_objective_status_text_on_status_change
/* 08C070 7F057540 27BDFF70 */  addiu $sp, $sp, -0x90
/* 08C074 7F057544 AFB60030 */  sw    $s6, 0x30($sp)
/* 08C078 7F057548 AFB30024 */  sw    $s3, 0x24($sp)
/* 08C07C 7F05754C 3C0E8005 */  lui   $t6, %hi(D_80053610) 
/* 08C080 7F057550 27B30054 */  addiu $s3, $sp, 0x54
/* 08C084 7F057554 3C168003 */  lui   $s6, %hi(num_objective_ptrs)
/* 08C088 7F057558 AFB40028 */  sw    $s4, 0x28($sp)
/* 08C08C 7F05755C 25CE3610 */  addiu $t6, %lo(D_80053610) # addiu $t6, $t6, 0x3610
/* 08C090 7F057560 26D622F0 */  addiu $s6, %lo(num_objective_ptrs) # addiu $s6, $s6, 0x22f0
/* 08C094 7F057564 AFBF003C */  sw    $ra, 0x3c($sp)
/* 08C098 7F057568 AFBE0038 */  sw    $fp, 0x38($sp)
/* 08C09C 7F05756C AFB70034 */  sw    $s7, 0x34($sp)
/* 08C0A0 7F057570 AFB5002C */  sw    $s5, 0x2c($sp)
/* 08C0A4 7F057574 AFB20020 */  sw    $s2, 0x20($sp)
/* 08C0A8 7F057578 AFB1001C */  sw    $s1, 0x1c($sp)
/* 08C0AC 7F05757C AFB00018 */  sw    $s0, 0x18($sp)
/* 08C0B0 7F057580 0000A025 */  move  $s4, $zero
/* 08C0B4 7F057584 25D90030 */  addiu $t9, $t6, 0x30
/* 08C0B8 7F057588 02604025 */  move  $t0, $s3
.L7F05758C:
/* 08C0BC 7F05758C 8DC10000 */  lw    $at, ($t6)
/* 08C0C0 7F057590 25CE000C */  addiu $t6, $t6, 0xc
/* 08C0C4 7F057594 2508000C */  addiu $t0, $t0, 0xc
/* 08C0C8 7F057598 AD01FFF4 */  sw    $at, -0xc($t0)
/* 08C0CC 7F05759C 8DC1FFF8 */  lw    $at, -8($t6)
/* 08C0D0 7F0575A0 AD01FFF8 */  sw    $at, -8($t0)
/* 08C0D4 7F0575A4 8DC1FFFC */  lw    $at, -4($t6)
/* 08C0D8 7F0575A8 15D9FFF8 */  bne   $t6, $t9, .L7F05758C
/* 08C0DC 7F0575AC AD01FFFC */   sw    $at, -4($t0)
/* 08C0E0 7F0575B0 95C10000 */  lhu   $at, ($t6)
/* 08C0E4 7F0575B4 3C158007 */  lui   $s5, %hi(dword_CODE_bss_80075D58)
/* 08C0E8 7F0575B8 3C1E8005 */  lui   $fp, %hi(aSAC) 
/* 08C0EC 7F0575BC A5010000 */  sh    $at, ($t0)
/* 08C0F0 7F0575C0 8EC90000 */  lw    $t1, ($s6)
/* 08C0F4 7F0575C4 27DE3644 */  addiu $fp, %lo(aSAC) # addiu $fp, $fp, 0x3644
/* 08C0F8 7F0575C8 26B55D58 */  addiu $s5, %lo(dword_CODE_bss_80075D58) # addiu $s5, $s5, 0x5d58
/* 08C0FC 7F0575CC 05200051 */  bltz  $t1, .L7F057714
/* 08C100 7F0575D0 00009025 */   move  $s2, $zero
/* 08C104 7F0575D4 3C178005 */  lui   $s7, %hi(j_text_trigger) 
/* 08C108 7F0575D8 26F784D0 */  addiu $s7, %lo(j_text_trigger) # addiu $s7, $s7, -0x7b30
.L7F0575DC:
/* 08C10C 7F0575DC 0FC15C8E */  jal   get_status_of_objective
/* 08C110 7F0575E0 02402025 */   move  $a0, $s2
/* 08C114 7F0575E4 8EAA0000 */  lw    $t2, ($s5)
/* 08C118 7F0575E8 00408825 */  move  $s1, $v0
/* 08C11C 7F0575EC 02402025 */  move  $a0, $s2
/* 08C120 7F0575F0 104A003A */  beq   $v0, $t2, .L7F0576DC
/* 08C124 7F0575F4 00000000 */   nop   
/* 08C128 7F0575F8 0FC15C81 */  jal   get_difficulty_for_objective
/* 08C12C 7F0575FC AEA20000 */   sw    $v0, ($s5)
/* 08C130 7F057600 0FC2FF04 */  jal   lvlGetSelectedDifficulty
/* 08C134 7F057604 00408025 */   move  $s0, $v0
/* 08C138 7F057608 0050082A */  slt   $at, $v0, $s0
/* 08C13C 7F05760C 14200033 */  bnez  $at, .L7F0576DC
/* 08C140 7F057610 00000000 */   nop   
/* 08C144 7F057614 8EEB0000 */  lw    $t3, ($s7)
/* 08C148 7F057618 2690001A */  addiu $s0, $s4, 0x1a
/* 08C14C 7F05761C 3404B02C */  li    $a0, 45100
/* 08C150 7F057620 1160000A */  beqz  $t3, .L7F05764C
/* 08C154 7F057624 00000000 */   nop   
/* 08C158 7F057628 0FC30776 */  jal   langGet
/* 08C15C 7F05762C 3404B02C */   li    $a0, 45100
/* 08C160 7F057630 02602025 */  move  $a0, $s3
/* 08C164 7F057634 03C02825 */  move  $a1, $fp
/* 08C168 7F057638 00403025 */  move  $a2, $v0
/* 08C16C 7F05763C 0C002B25 */  jal   sprintf
/* 08C170 7F057640 02003825 */   move  $a3, $s0
/* 08C174 7F057644 1000000A */  b     .L7F057670
/* 08C178 7F057648 24010001 */   li    $at, 1
.L7F05764C:
/* 08C17C 7F05764C 0FC30776 */  jal   langGet
/* 08C180 7F057650 26900061 */   addiu $s0, $s4, 0x61
/* 08C184 7F057654 3C058005 */  lui   $a1, %hi(aSC)
/* 08C188 7F057658 24A5364C */  addiu $a1, %lo(aSC) # addiu $a1, $a1, 0x364c
/* 08C18C 7F05765C 02602025 */  move  $a0, $s3
/* 08C190 7F057660 00403025 */  move  $a2, $v0
/* 08C194 7F057664 0C002B25 */  jal   sprintf
/* 08C198 7F057668 02003825 */   move  $a3, $s0
/* 08C19C 7F05766C 24010001 */  li    $at, 1
.L7F057670:
/* 08C1A0 7F057670 16210008 */  bne   $s1, $at, .L7F057694
/* 08C1A4 7F057674 00000000 */   nop   
/* 08C1A8 7F057678 0FC30776 */  jal   langGet
/* 08C1AC 7F05767C 3404B02D */   li    $a0, 45101
/* 08C1B0 7F057680 02602025 */  move  $a0, $s3
/* 08C1B4 7F057684 0C0029FF */  jal   strcat
/* 08C1B8 7F057688 00402825 */   move  $a1, $v0
/* 08C1BC 7F05768C 10000011 */  b     .L7F0576D4
/* 08C1C0 7F057690 00000000 */   nop   
.L7F057694:
/* 08C1C4 7F057694 16200008 */  bnez  $s1, .L7F0576B8
/* 08C1C8 7F057698 24010002 */   li    $at, 2
/* 08C1CC 7F05769C 0FC30776 */  jal   langGet
/* 08C1D0 7F0576A0 3404B02E */   li    $a0, 45102
/* 08C1D4 7F0576A4 02602025 */  move  $a0, $s3
/* 08C1D8 7F0576A8 0C0029FF */  jal   strcat
/* 08C1DC 7F0576AC 00402825 */   move  $a1, $v0
/* 08C1E0 7F0576B0 10000008 */  b     .L7F0576D4
/* 08C1E4 7F0576B4 00000000 */   nop   
.L7F0576B8:
/* 08C1E8 7F0576B8 16210006 */  bne   $s1, $at, .L7F0576D4
/* 08C1EC 7F0576BC 00000000 */   nop   
/* 08C1F0 7F0576C0 0FC30776 */  jal   langGet
/* 08C1F4 7F0576C4 3404B02F */   li    $a0, 45103
/* 08C1F8 7F0576C8 02602025 */  move  $a0, $s3
/* 08C1FC 7F0576CC 0C0029FF */  jal   strcat
/* 08C200 7F0576D0 00402825 */   move  $a1, $v0
.L7F0576D4:
/* 08C204 7F0576D4 0FC228F2 */  jal   hudmsgBottomShow
/* 08C208 7F0576D8 02602025 */   move  $a0, $s3
.L7F0576DC:
/* 08C20C 7F0576DC 0FC15C81 */  jal   get_difficulty_for_objective
/* 08C210 7F0576E0 02402025 */   move  $a0, $s2
/* 08C214 7F0576E4 0FC2FF04 */  jal   lvlGetSelectedDifficulty
/* 08C218 7F0576E8 00408025 */   move  $s0, $v0
/* 08C21C 7F0576EC 0050082A */  slt   $at, $v0, $s0
/* 08C220 7F0576F0 54200003 */  bnezl $at, .L7F057700
/* 08C224 7F0576F4 8ECC0000 */   lw    $t4, ($s6)
/* 08C228 7F0576F8 26940001 */  addiu $s4, $s4, 1
/* 08C22C 7F0576FC 8ECC0000 */  lw    $t4, ($s6)
.L7F057700:
/* 08C230 7F057700 26520001 */  addiu $s2, $s2, 1
/* 08C234 7F057704 26B50004 */  addiu $s5, $s5, 4
/* 08C238 7F057708 0192082A */  slt   $at, $t4, $s2
/* 08C23C 7F05770C 1020FFB3 */  beqz  $at, .L7F0575DC
/* 08C240 7F057710 00000000 */   nop   
.L7F057714:
/* 08C244 7F057714 8FBF003C */  lw    $ra, 0x3c($sp)
/* 08C248 7F057718 8FB00018 */  lw    $s0, 0x18($sp)
/* 08C24C 7F05771C 8FB1001C */  lw    $s1, 0x1c($sp)
/* 08C250 7F057720 8FB20020 */  lw    $s2, 0x20($sp)
/* 08C254 7F057724 8FB30024 */  lw    $s3, 0x24($sp)
/* 08C258 7F057728 8FB40028 */  lw    $s4, 0x28($sp)
/* 08C25C 7F05772C 8FB5002C */  lw    $s5, 0x2c($sp)
/* 08C260 7F057730 8FB60030 */  lw    $s6, 0x30($sp)
/* 08C264 7F057734 8FB70034 */  lw    $s7, 0x34($sp)
/* 08C268 7F057738 8FBE0038 */  lw    $fp, 0x38($sp)
/* 08C26C 7F05773C 03E00008 */  jr    $ra
/* 08C270 7F057740 27BD0090 */   addiu $sp, $sp, 0x90
)
#endif

#ifdef VERSION_JP
GLOBAL_ASM(
.text
glabel display_objective_status_text_on_status_change
/* 08C5C0 7F057A50 27BDFF70 */  addiu $sp, $sp, -0x90
/* 08C5C4 7F057A54 AFB30024 */  sw    $s3, 0x24($sp)
/* 08C5C8 7F057A58 3C0E8005 */  lui   $t6, %hi(D_80053610) # $t6, 0x8005
/* 08C5CC 7F057A5C 27B30054 */  addiu $s3, $sp, 0x54
/* 08C5D0 7F057A60 AFB5002C */  sw    $s5, 0x2c($sp)
/* 08C5D4 7F057A64 25CE3640 */  addiu $t6, %lo(D_80053610) # addiu $t6, $t6, 0x3640
/* 08C5D8 7F057A68 AFBF003C */  sw    $ra, 0x3c($sp)
/* 08C5DC 7F057A6C AFBE0038 */  sw    $fp, 0x38($sp)
/* 08C5E0 7F057A70 AFB70034 */  sw    $s7, 0x34($sp)
/* 08C5E4 7F057A74 AFB60030 */  sw    $s6, 0x30($sp)
/* 08C5E8 7F057A78 AFB40028 */  sw    $s4, 0x28($sp)
/* 08C5EC 7F057A7C AFB20020 */  sw    $s2, 0x20($sp)
/* 08C5F0 7F057A80 AFB1001C */  sw    $s1, 0x1c($sp)
/* 08C5F4 7F057A84 AFB00018 */  sw    $s0, 0x18($sp)
/* 08C5F8 7F057A88 0000A825 */  move  $s5, $zero
/* 08C5FC 7F057A8C 25D90030 */  addiu $t9, $t6, 0x30
/* 08C600 7F057A90 02604025 */  move  $t0, $s3
.L7F057A94:
/* 08C604 7F057A94 8DC10000 */  lw    $at, ($t6)
/* 08C608 7F057A98 25CE000C */  addiu $t6, $t6, 0xc
/* 08C60C 7F057A9C 2508000C */  addiu $t0, $t0, 0xc
/* 08C610 7F057AA0 AD01FFF4 */  sw    $at, -0xc($t0)
/* 08C614 7F057AA4 8DC1FFF8 */  lw    $at, -8($t6)
/* 08C618 7F057AA8 AD01FFF8 */  sw    $at, -8($t0)
/* 08C61C 7F057AAC 8DC1FFFC */  lw    $at, -4($t6)
/* 08C620 7F057AB0 15D9FFF8 */  bne   $t6, $t9, .L7F057A94
/* 08C624 7F057AB4 AD01FFFC */   sw    $at, -4($t0)
/* 08C628 7F057AB8 95C10000 */  lhu   $at, ($t6)
/* 08C62C 7F057ABC 3C098003 */  lui   $t1, %hi(num_objective_ptrs+4) # $t1, 0x8003
/* 08C630 7F057AC0 3C168003 */  lui   $s6, %hi(num_objective_ptrs) # $s6, 0x8003
/* 08C634 7F057AC4 A5010000 */  sh    $at, ($t0)
/* 08C638 7F057AC8 8D292334 */  lw    $t1, %lo(num_objective_ptrs+4)($t1)
/* 08C63C 7F057ACC 26D62330 */  addiu $s6, %lo(num_objective_ptrs) # addiu $s6, $s6, 0x2330
/* 08C640 7F057AD0 55200058 */  bnezl $t1, .L7F057C34
/* 08C644 7F057AD4 8FBF003C */   lw    $ra, 0x3c($sp)
/* 08C648 7F057AD8 8ECA0000 */  lw    $t2, ($s6)
/* 08C64C 7F057ADC 3C148007 */  lui   $s4, %hi(dword_CODE_bss_80075D58) # $s4, 0x8007
/* 08C650 7F057AE0 26945D98 */  addiu $s4, %lo(dword_CODE_bss_80075D58) # addiu $s4, $s4, 0x5d98
/* 08C654 7F057AE4 05400052 */  bltz  $t2, .L7F057C30
/* 08C658 7F057AE8 00009025 */   move  $s2, $zero
/* 08C65C 7F057AEC 3C178005 */  lui   $s7, %hi(j_text_trigger) # $s7, 0x8005
/* 08C660 7F057AF0 26F78500 */  addiu $s7, %lo(j_text_trigger) # addiu $s7, $s7, -0x7b00
/* 08C664 7F057AF4 241E0001 */  li    $fp, 1
.L7F057AF8:
/* 08C668 7F057AF8 0FC15DCE */  jal   get_status_of_objective
/* 08C66C 7F057AFC 02402025 */   move  $a0, $s2
/* 08C670 7F057B00 8E8B0000 */  lw    $t3, ($s4)
/* 08C674 7F057B04 00408825 */  move  $s1, $v0
/* 08C678 7F057B08 02402025 */  move  $a0, $s2
/* 08C67C 7F057B0C 104B003A */  beq   $v0, $t3, .L7F057BF8
/* 08C680 7F057B10 00000000 */   nop   
/* 08C684 7F057B14 0FC15DC1 */  jal   get_difficulty_for_objective
/* 08C688 7F057B18 AE820000 */   sw    $v0, ($s4)
/* 08C68C 7F057B1C 0FC3021E */  jal   lvlGetSelectedDifficulty
/* 08C690 7F057B20 00408025 */   move  $s0, $v0
/* 08C694 7F057B24 0050082A */  slt   $at, $v0, $s0
/* 08C698 7F057B28 14200033 */  bnez  $at, .L7F057BF8
/* 08C69C 7F057B2C 00000000 */   nop   
/* 08C6A0 7F057B30 8EEC0000 */  lw    $t4, ($s7)
/* 08C6A4 7F057B34 26B0001A */  addiu $s0, $s5, 0x1a
/* 08C6A8 7F057B38 3404B02C */  li    $a0, 45100
/* 08C6AC 7F057B3C 1180000B */  beqz  $t4, .L7F057B6C
/* 08C6B0 7F057B40 00000000 */   nop   
/* 08C6B4 7F057B44 0FC30AA2 */  jal   langGet
/* 08C6B8 7F057B48 3404B02C */   li    $a0, 45100
/* 08C6BC 7F057B4C 3C058005 */  lui   $a1, %hi(aSAC) # $a1, 0x8005
/* 08C6C0 7F057B50 24A53674 */  addiu $a1, %lo(aSAC) # addiu $a1, $a1, 0x3674
/* 08C6C4 7F057B54 02602025 */  move  $a0, $s3
/* 08C6C8 7F057B58 00403025 */  move  $a2, $v0
/* 08C6CC 7F057B5C 0C002B29 */  jal   sprintf
/* 08C6D0 7F057B60 02003825 */   move  $a3, $s0
/* 08C6D4 7F057B64 10000009 */  b     .L7F057B8C
/* 08C6D8 7F057B68 00000000 */   nop   
.L7F057B6C:
/* 08C6DC 7F057B6C 0FC30AA2 */  jal   langGet
/* 08C6E0 7F057B70 26B00061 */   addiu $s0, $s5, 0x61
/* 08C6E4 7F057B74 3C058005 */  lui   $a1, %hi(aSC) # $a1, 0x8005
/* 08C6E8 7F057B78 24A5367C */  addiu $a1, %lo(aSC) # addiu $a1, $a1, 0x367c
/* 08C6EC 7F057B7C 02602025 */  move  $a0, $s3
/* 08C6F0 7F057B80 00403025 */  move  $a2, $v0
/* 08C6F4 7F057B84 0C002B29 */  jal   sprintf
/* 08C6F8 7F057B88 02003825 */   move  $a3, $s0
.L7F057B8C:
/* 08C6FC 7F057B8C 163E0008 */  bne   $s1, $fp, .L7F057BB0
/* 08C700 7F057B90 00000000 */   nop   
/* 08C704 7F057B94 0FC30AA2 */  jal   langGet
/* 08C708 7F057B98 3404B02D */   li    $a0, 45101
/* 08C70C 7F057B9C 02602025 */  move  $a0, $s3
/* 08C710 7F057BA0 0C002A03 */  jal   strcat
/* 08C714 7F057BA4 00402825 */   move  $a1, $v0
/* 08C718 7F057BA8 10000011 */  b     .L7F057BF0
/* 08C71C 7F057BAC 00000000 */   nop   
.L7F057BB0:
/* 08C720 7F057BB0 16200008 */  bnez  $s1, .L7F057BD4
/* 08C724 7F057BB4 24010002 */   li    $at, 2
/* 08C728 7F057BB8 0FC30AA2 */  jal   langGet
/* 08C72C 7F057BBC 3404B02E */   li    $a0, 45102
/* 08C730 7F057BC0 02602025 */  move  $a0, $s3
/* 08C734 7F057BC4 0C002A03 */  jal   strcat
/* 08C738 7F057BC8 00402825 */   move  $a1, $v0
/* 08C73C 7F057BCC 10000008 */  b     .L7F057BF0
/* 08C740 7F057BD0 00000000 */   nop   
.L7F057BD4:
/* 08C744 7F057BD4 16210006 */  bne   $s1, $at, .L7F057BF0
/* 08C748 7F057BD8 00000000 */   nop   
/* 08C74C 7F057BDC 0FC30AA2 */  jal   langGet
/* 08C750 7F057BE0 3404B02F */   li    $a0, 45103
/* 08C754 7F057BE4 02602025 */  move  $a0, $s3
/* 08C758 7F057BE8 0C002A03 */  jal   strcat
/* 08C75C 7F057BEC 00402825 */   move  $a1, $v0
.L7F057BF0:
/* 08C760 7F057BF0 0FC22B10 */  jal   jp_hudmsgBottomShow
/* 08C764 7F057BF4 02602025 */   move  $a0, $s3
.L7F057BF8:
/* 08C768 7F057BF8 0FC15DC1 */  jal   get_difficulty_for_objective
/* 08C76C 7F057BFC 02402025 */   move  $a0, $s2
/* 08C770 7F057C00 0FC3021E */  jal   lvlGetSelectedDifficulty
/* 08C774 7F057C04 00408025 */   move  $s0, $v0
/* 08C778 7F057C08 0050082A */  slt   $at, $v0, $s0
/* 08C77C 7F057C0C 54200003 */  bnezl $at, .L7F057C1C
/* 08C780 7F057C10 8ECD0000 */   lw    $t5, ($s6)
/* 08C784 7F057C14 26B50001 */  addiu $s5, $s5, 1
/* 08C788 7F057C18 8ECD0000 */  lw    $t5, ($s6)
.L7F057C1C:
/* 08C78C 7F057C1C 26520001 */  addiu $s2, $s2, 1
/* 08C790 7F057C20 26940004 */  addiu $s4, $s4, 4
/* 08C794 7F057C24 01B2082A */  slt   $at, $t5, $s2
/* 08C798 7F057C28 1020FFB3 */  beqz  $at, .L7F057AF8
/* 08C79C 7F057C2C 00000000 */   nop   
.L7F057C30:
/* 08C7A0 7F057C30 8FBF003C */  lw    $ra, 0x3c($sp)
.L7F057C34:
/* 08C7A4 7F057C34 8FB00018 */  lw    $s0, 0x18($sp)
/* 08C7A8 7F057C38 8FB1001C */  lw    $s1, 0x1c($sp)
/* 08C7AC 7F057C3C 8FB20020 */  lw    $s2, 0x20($sp)
/* 08C7B0 7F057C40 8FB30024 */  lw    $s3, 0x24($sp)
/* 08C7B4 7F057C44 8FB40028 */  lw    $s4, 0x28($sp)
/* 08C7B8 7F057C48 8FB5002C */  lw    $s5, 0x2c($sp)
/* 08C7BC 7F057C4C 8FB60030 */  lw    $s6, 0x30($sp)
/* 08C7C0 7F057C50 8FB70034 */  lw    $s7, 0x34($sp)
/* 08C7C4 7F057C54 8FBE0038 */  lw    $fp, 0x38($sp)
/* 08C7C8 7F057C58 03E00008 */  jr    $ra
/* 08C7CC 7F057C5C 27BD0090 */   addiu $sp, $sp, 0x90
)
#endif
#ifdef VERSION_EU
GLOBAL_ASM(
.rdata
/*glabel D_80053610*/
/*.word 0,0,0,0,0,0,0,0,0,0*/
/*glabel D_80053640*/
/*.word 0*/
.text
glabel display_objective_status_text_on_status_change
/* 08A220 7F057830 27BDFF70 */  addiu $sp, $sp, -0x90
/* 08A224 7F057834 AFB30024 */  sw    $s3, 0x24($sp)
/* 08A228 7F057838 3C0E8005 */  lui   $t6, %hi(D_80053610) # $t6, 0x8005
/* 08A22C 7F05783C 27B30054 */  addiu $s3, $sp, 0x54
/* 08A230 7F057840 AFB5002C */  sw    $s5, 0x2c($sp)
/* 08A234 7F057844 25CE9750 */  addiu $t6, %lo(D_80053610) # addiu $t6, $t6, -0x68b0
/* 08A238 7F057848 AFBF003C */  sw    $ra, 0x3c($sp)
/* 08A23C 7F05784C AFBE0038 */  sw    $fp, 0x38($sp)
/* 08A240 7F057850 AFB70034 */  sw    $s7, 0x34($sp)
/* 08A244 7F057854 AFB60030 */  sw    $s6, 0x30($sp)
/* 08A248 7F057858 AFB40028 */  sw    $s4, 0x28($sp)
/* 08A24C 7F05785C AFB20020 */  sw    $s2, 0x20($sp)
/* 08A250 7F057860 AFB1001C */  sw    $s1, 0x1c($sp)
/* 08A254 7F057864 AFB00018 */  sw    $s0, 0x18($sp)
/* 08A258 7F057868 0000A825 */  move  $s5, $zero
/* 08A25C 7F05786C 25D90030 */  addiu $t9, $t6, 0x30
/* 08A260 7F057870 02604025 */  move  $t0, $s3
.L7F057874:
/* 08A264 7F057874 8DC10000 */  lw    $at, ($t6)
/* 08A268 7F057878 25CE000C */  addiu $t6, $t6, 0xc
/* 08A26C 7F05787C 2508000C */  addiu $t0, $t0, 0xc
/* 08A270 7F057880 AD01FFF4 */  sw    $at, -0xc($t0)
/* 08A274 7F057884 8DC1FFF8 */  lw    $at, -8($t6)
/* 08A278 7F057888 AD01FFF8 */  sw    $at, -8($t0)
/* 08A27C 7F05788C 8DC1FFFC */  lw    $at, -4($t6)
/* 08A280 7F057890 15D9FFF8 */  bne   $t6, $t9, .L7F057874
/* 08A284 7F057894 AD01FFFC */   sw    $at, -4($t0)
/* 08A288 7F057898 95C10000 */  lhu   $at, ($t6)
/* 08A28C 7F05789C 3C098003 */  lui   $t1, %hi(num_objective_ptrs+4) # $t1, 0x8003
/* 08A290 7F0578A0 3C168003 */  lui   $s6, %hi(num_objective_ptrs) # $s6, 0x8003
/* 08A294 7F0578A4 A5010000 */  sh    $at, ($t0)
/* 08A298 7F0578A8 8D29D844 */  lw    $t1, %lo(num_objective_ptrs+4)($t1)
/* 08A29C 7F0578AC 26D6D840 */  addiu $s6, %lo(num_objective_ptrs) # addiu $s6, $s6, -0x27c0
/* 08A2A0 7F0578B0 55200058 */  bnezl $t1, .L7F057A14
/* 08A2A4 7F0578B4 8FBF003C */   lw    $ra, 0x3c($sp)
/* 08A2A8 7F0578B8 8ECA0000 */  lw    $t2, ($s6)
/* 08A2AC 7F0578BC 3C148006 */  lui   $s4, %hi(dword_CODE_bss_80075D58) # $s4, 0x8006
/* 08A2B0 7F0578C0 26944C98 */  addiu $s4, %lo(dword_CODE_bss_80075D58) # addiu $s4, $s4, 0x4c98
/* 08A2B4 7F0578C4 05400052 */  bltz  $t2, .L7F057A10
/* 08A2B8 7F0578C8 00009025 */   move  $s2, $zero
/* 08A2BC 7F0578CC 3C178004 */  lui   $s7, %hi(j_text_trigger) # $s7, 0x8004
/* 08A2C0 7F0578D0 26F71150 */  addiu $s7, %lo(j_text_trigger) # addiu $s7, $s7, 0x1150
/* 08A2C4 7F0578D4 241E0001 */  li    $fp, 1
.L7F0578D8:
/* 08A2C8 7F0578D8 0FC15D46 */  jal   get_status_of_objective
/* 08A2CC 7F0578DC 02402025 */   move  $a0, $s2
/* 08A2D0 7F0578E0 8E8B0000 */  lw    $t3, ($s4)
/* 08A2D4 7F0578E4 00408825 */  move  $s1, $v0
/* 08A2D8 7F0578E8 02402025 */  move  $a0, $s2
/* 08A2DC 7F0578EC 104B003A */  beq   $v0, $t3, .L7F0579D8
/* 08A2E0 7F0578F0 00000000 */   nop   
/* 08A2E4 7F0578F4 0FC15D39 */  jal   get_difficulty_for_objective
/* 08A2E8 7F0578F8 AE820000 */   sw    $v0, ($s4)
/* 08A2EC 7F0578FC 0FC2FC21 */  jal   lvlGetSelectedDifficulty
/* 08A2F0 7F057900 00408025 */   move  $s0, $v0
/* 08A2F4 7F057904 0050082A */  slt   $at, $v0, $s0
/* 08A2F8 7F057908 14200033 */  bnez  $at, .L7F0579D8
/* 08A2FC 7F05790C 00000000 */   nop   
/* 08A300 7F057910 8EEC0000 */  lw    $t4, ($s7)
/* 08A304 7F057914 26B0001A */  addiu $s0, $s5, 0x1a
/* 08A308 7F057918 3404B02C */  li    $a0, 45100
/* 08A30C 7F05791C 1180000B */  beqz  $t4, .L7F05794C
/* 08A310 7F057920 00000000 */   nop   
/* 08A314 7F057924 0FC304AE */  jal   langGet
/* 08A318 7F057928 3404B02C */   li    $a0, 45100
/* 08A31C 7F05792C 3C058005 */  lui   $a1, %hi(aSAC) # $a1, 0x8005
/* 08A320 7F057930 24A59784 */  addiu $a1, %lo(aSAC) # addiu $a1, $a1, -0x687c
/* 08A324 7F057934 02602025 */  move  $a0, $s3
/* 08A328 7F057938 00403025 */  move  $a2, $v0
/* 08A32C 7F05793C 0C00283D */  jal   sprintf
/* 08A330 7F057940 02003825 */   move  $a3, $s0
/* 08A334 7F057944 10000009 */  b     .L7F05796C
/* 08A338 7F057948 00000000 */   nop   
.L7F05794C:
/* 08A33C 7F05794C 0FC304AE */  jal   langGet
/* 08A340 7F057950 26B00061 */   addiu $s0, $s5, 0x61
/* 08A344 7F057954 3C058005 */  lui   $a1, %hi(aSC) # $a1, 0x8005
/* 08A348 7F057958 24A5978C */  addiu $a1, %lo(aSC) # addiu $a1, $a1, -0x6874
/* 08A34C 7F05795C 02602025 */  move  $a0, $s3
/* 08A350 7F057960 00403025 */  move  $a2, $v0
/* 08A354 7F057964 0C00283D */  jal   sprintf
/* 08A358 7F057968 02003825 */   move  $a3, $s0
.L7F05796C:
/* 08A35C 7F05796C 163E0008 */  bne   $s1, $fp, .L7F057990
/* 08A360 7F057970 00000000 */   nop   
/* 08A364 7F057974 0FC304AE */  jal   langGet
/* 08A368 7F057978 3404B02D */   li    $a0, 45101
/* 08A36C 7F05797C 02602025 */  move  $a0, $s3
/* 08A370 7F057980 0C002717 */  jal   strcat
/* 08A374 7F057984 00402825 */   move  $a1, $v0
/* 08A378 7F057988 10000011 */  b     .L7F0579D0
/* 08A37C 7F05798C 00000000 */   nop   
.L7F057990:
/* 08A380 7F057990 16200008 */  bnez  $s1, .L7F0579B4
/* 08A384 7F057994 24010002 */   li    $at, 2
/* 08A388 7F057998 0FC304AE */  jal   langGet
/* 08A38C 7F05799C 3404B02E */   li    $a0, 45102
/* 08A390 7F0579A0 02602025 */  move  $a0, $s3
/* 08A394 7F0579A4 0C002717 */  jal   strcat
/* 08A398 7F0579A8 00402825 */   move  $a1, $v0
/* 08A39C 7F0579AC 10000008 */  b     .L7F0579D0
/* 08A3A0 7F0579B0 00000000 */   nop   
.L7F0579B4:
/* 08A3A4 7F0579B4 16210006 */  bne   $s1, $at, .L7F0579D0
/* 08A3A8 7F0579B8 00000000 */   nop   
/* 08A3AC 7F0579BC 0FC304AE */  jal   langGet
/* 08A3B0 7F0579C0 3404B02F */   li    $a0, 45103
/* 08A3B4 7F0579C4 02602025 */  move  $a0, $s3
/* 08A3B8 7F0579C8 0C002717 */  jal   strcat
/* 08A3BC 7F0579CC 00402825 */   move  $a1, $v0
.L7F0579D0:
/* 08A3C0 7F0579D0 0FC229B5 */  jal   jp_hudmsgBottomShow
/* 08A3C4 7F0579D4 02602025 */   move  $a0, $s3
.L7F0579D8:
/* 08A3C8 7F0579D8 0FC15D39 */  jal   get_difficulty_for_objective
/* 08A3CC 7F0579DC 02402025 */   move  $a0, $s2
/* 08A3D0 7F0579E0 0FC2FC21 */  jal   lvlGetSelectedDifficulty
/* 08A3D4 7F0579E4 00408025 */   move  $s0, $v0
/* 08A3D8 7F0579E8 0050082A */  slt   $at, $v0, $s0
/* 08A3DC 7F0579EC 54200003 */  bnezl $at, .L7F0579FC
/* 08A3E0 7F0579F0 8ECD0000 */   lw    $t5, ($s6)
/* 08A3E4 7F0579F4 26B50001 */  addiu $s5, $s5, 1
/* 08A3E8 7F0579F8 8ECD0000 */  lw    $t5, ($s6)
.L7F0579FC:
/* 08A3EC 7F0579FC 26520001 */  addiu $s2, $s2, 1
/* 08A3F0 7F057A00 26940004 */  addiu $s4, $s4, 4
/* 08A3F4 7F057A04 01B2082A */  slt   $at, $t5, $s2
/* 08A3F8 7F057A08 1020FFB3 */  beqz  $at, .L7F0578D8
/* 08A3FC 7F057A0C 00000000 */   nop   
.L7F057A10:
/* 08A400 7F057A10 8FBF003C */  lw    $ra, 0x3c($sp)
.L7F057A14:
/* 08A404 7F057A14 8FB00018 */  lw    $s0, 0x18($sp)
/* 08A408 7F057A18 8FB1001C */  lw    $s1, 0x1c($sp)
/* 08A40C 7F057A1C 8FB20020 */  lw    $s2, 0x20($sp)
/* 08A410 7F057A20 8FB30024 */  lw    $s3, 0x24($sp)
/* 08A414 7F057A24 8FB40028 */  lw    $s4, 0x28($sp)
/* 08A418 7F057A28 8FB5002C */  lw    $s5, 0x2c($sp)
/* 08A41C 7F057A2C 8FB60030 */  lw    $s6, 0x30($sp)
/* 08A420 7F057A30 8FB70034 */  lw    $s7, 0x34($sp)
/* 08A424 7F057A34 8FBE0038 */  lw    $fp, 0x38($sp)
/* 08A428 7F057A38 03E00008 */  jr    $ra
/* 08A42C 7F057A3C 27BD0090 */   addiu $sp, $sp, 0x90
)
#endif

#endif



#ifdef NONMATCHING
void sub_GAME_7F057744(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F057744
/* 08C274 7F057744 3C028007 */  lui   $v0, %hi(ptr_last_enter_room_subobject_entry_type20)
/* 08C278 7F057748 8C425D88 */  lw    $v0, %lo(ptr_last_enter_room_subobject_entry_type20)($v0)
/* 08C27C 7F05774C 3C0AFFF5 */  lui   $t2, (0xFFF59FC0 >> 16) # lui $t2, 0xfff5
/* 08C280 7F057750 00802825 */  move  $a1, $a0
/* 08C284 7F057754 10400022 */  beqz  $v0, .L7F0577E0
/* 08C288 7F057758 354A9FC0 */   ori   $t2, (0xFFF59FC0 & 0xFFFF) # ori $t2, $t2, 0x9fc0
/* 08C28C 7F05775C 3C078007 */  lui   $a3, %hi(g_chraiCurrentSetup+0)
/* 08C290 7F057760 24E75D00 */  addiu $a3, %lo(g_chraiCurrentSetup+0) # addiu $a3, $a3, 0x5d00
/* 08C294 7F057764 24090044 */  li    $t1, 68
/* 08C298 7F057768 24080001 */  li    $t0, 1
/* 08C29C 7F05776C 2406002C */  li    $a2, 44
/* 08C2A0 7F057770 8C4E0008 */  lw    $t6, 8($v0)
.L7F057774:
/* 08C2A4 7F057774 55C00018 */  bnezl $t6, .L7F0577D8
/* 08C2A8 7F057778 8C42000C */   lw    $v0, 0xc($v0)
/* 08C2AC 7F05777C 8C430004 */  lw    $v1, 4($v0)
/* 08C2B0 7F057780 2C612710 */  sltiu $at, $v1, 0x2710
/* 08C2B4 7F057784 10200007 */  beqz  $at, .L7F0577A4
/* 08C2B8 7F057788 00000000 */   nop   
/* 08C2BC 7F05778C 00660019 */  multu $v1, $a2
/* 08C2C0 7F057790 8CF80018 */  lw    $t8, 0x18($a3)
/* 08C2C4 7F057794 00007812 */  mflo  $t7
/* 08C2C8 7F057798 01F82021 */  addu  $a0, $t7, $t8
/* 08C2CC 7F05779C 10000007 */  b     .L7F0577BC
/* 08C2D0 7F0577A0 8C830028 */   lw    $v1, 0x28($a0)
.L7F0577A4:
/* 08C2D4 7F0577A4 00690019 */  multu $v1, $t1
/* 08C2D8 7F0577A8 8CEB001C */  lw    $t3, 0x1c($a3)
/* 08C2DC 7F0577AC 0000C812 */  mflo  $t9
/* 08C2E0 7F0577B0 032B6021 */  addu  $t4, $t9, $t3
/* 08C2E4 7F0577B4 018A2021 */  addu  $a0, $t4, $t2
/* 08C2E8 7F0577B8 8C830028 */  lw    $v1, 0x28($a0)
.L7F0577BC:
/* 08C2EC 7F0577BC 50600006 */  beql  $v1, $zero, .L7F0577D8
/* 08C2F0 7F0577C0 8C42000C */   lw    $v0, 0xc($v0)
/* 08C2F4 7F0577C4 906D0003 */  lbu   $t5, 3($v1)
/* 08C2F8 7F0577C8 54AD0003 */  bnel  $a1, $t5, .L7F0577D8
/* 08C2FC 7F0577CC 8C42000C */   lw    $v0, 0xc($v0)
/* 08C300 7F0577D0 AC480008 */  sw    $t0, 8($v0)
/* 08C304 7F0577D4 8C42000C */  lw    $v0, 0xc($v0)
.L7F0577D8:
/* 08C308 7F0577D8 5440FFE6 */  bnezl $v0, .L7F057774
/* 08C30C 7F0577DC 8C4E0008 */   lw    $t6, 8($v0)
.L7F0577E0:
/* 08C310 7F0577E0 03E00008 */  jr    $ra
/* 08C314 7F0577E4 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0577E8(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0577E8
/* 08C318 7F0577E8 3C028007 */  lui   $v0, %hi(ptr_last_deposit_in_room_subobject_entry_type21)
/* 08C31C 7F0577EC 8C425D8C */  lw    $v0, %lo(ptr_last_deposit_in_room_subobject_entry_type21)($v0)
/* 08C320 7F0577F0 3C0BFFF5 */  lui   $t3, (0xFFF59FC0 >> 16) # lui $t3, 0xfff5
/* 08C324 7F0577F4 00A03025 */  move  $a2, $a1
/* 08C328 7F0577F8 10400025 */  beqz  $v0, .L7F057890
/* 08C32C 7F0577FC 356B9FC0 */   ori   $t3, (0xFFF59FC0 & 0xFFFF) # ori $t3, $t3, 0x9fc0
/* 08C330 7F057800 3C088007 */  lui   $t0, %hi(g_chraiCurrentSetup+0) 
/* 08C334 7F057804 25085D00 */  addiu $t0, %lo(g_chraiCurrentSetup+0) # addiu $t0, $t0, 0x5d00
/* 08C338 7F057808 240A0044 */  li    $t2, 68
/* 08C33C 7F05780C 24090001 */  li    $t1, 1
/* 08C340 7F057810 2407002C */  li    $a3, 44
/* 08C344 7F057814 8C4E000C */  lw    $t6, 0xc($v0)
.L7F057818:
/* 08C348 7F057818 55C0001B */  bnezl $t6, .L7F057888
/* 08C34C 7F05781C 8C420010 */   lw    $v0, 0x10($v0)
/* 08C350 7F057820 8C4F0004 */  lw    $t7, 4($v0)
/* 08C354 7F057824 548F0018 */  bnel  $a0, $t7, .L7F057888
/* 08C358 7F057828 8C420010 */   lw    $v0, 0x10($v0)
/* 08C35C 7F05782C 8C430008 */  lw    $v1, 8($v0)
/* 08C360 7F057830 2C612710 */  sltiu $at, $v1, 0x2710
/* 08C364 7F057834 10200007 */  beqz  $at, .L7F057854
/* 08C368 7F057838 00000000 */   nop   
/* 08C36C 7F05783C 00670019 */  multu $v1, $a3
/* 08C370 7F057840 8D190018 */  lw    $t9, 0x18($t0)
/* 08C374 7F057844 0000C012 */  mflo  $t8
/* 08C378 7F057848 03192821 */  addu  $a1, $t8, $t9
/* 08C37C 7F05784C 10000007 */  b     .L7F05786C
/* 08C380 7F057850 8CA30028 */   lw    $v1, 0x28($a1)
.L7F057854:
/* 08C384 7F057854 006A0019 */  multu $v1, $t2
/* 08C388 7F057858 8D0D001C */  lw    $t5, 0x1c($t0)
/* 08C38C 7F05785C 00006012 */  mflo  $t4
/* 08C390 7F057860 018D7021 */  addu  $t6, $t4, $t5
/* 08C394 7F057864 01CB2821 */  addu  $a1, $t6, $t3
/* 08C398 7F057868 8CA30028 */  lw    $v1, 0x28($a1)
.L7F05786C:
/* 08C39C 7F05786C 50600006 */  beql  $v1, $zero, .L7F057888
/* 08C3A0 7F057870 8C420010 */   lw    $v0, 0x10($v0)
/* 08C3A4 7F057874 906F0003 */  lbu   $t7, 3($v1)
/* 08C3A8 7F057878 54CF0003 */  bnel  $a2, $t7, .L7F057888
/* 08C3AC 7F05787C 8C420010 */   lw    $v0, 0x10($v0)
/* 08C3B0 7F057880 AC49000C */  sw    $t1, 0xc($v0)
/* 08C3B4 7F057884 8C420010 */  lw    $v0, 0x10($v0)
.L7F057888:
/* 08C3B8 7F057888 5440FFE3 */  bnezl $v0, .L7F057818
/* 08C3BC 7F05788C 8C4E000C */   lw    $t6, 0xc($v0)
.L7F057890:
/* 08C3C0 7F057890 03E00008 */  jr    $ra
/* 08C3C4 7F057894 00000000 */   nop   
)
#endif





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
