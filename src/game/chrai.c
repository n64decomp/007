#include <ultra64.h>
#include <bondgame.h>
#include <bondtypes.h>
#include <bondaicommands.h>
#include <boss.h>
#include <snd.h>
#include <music.h>
#include "bg.h"
#include "bondview.h"
#include "chr.h"
#include "chrai.h"
#include "chrlv.h"
#include "chrobjhandler.h"
#include "gun.h"
#include "lvl_text.h"
#include "math_floor.h"
#include "math_ceil.h"
#include "math_atan2f.h"
#include "player.h"
#include "chraidata.h"
#include <limits.h>
#include "objecthandler.h"
#include "chrobjhandler.h"
#include "initanitable.h"
#include <random.h>
#include "lvl.h"
#include "stan.h"
#include "chr.h"
#include "mp_music.h"
#include "objective_status.h"
#include "bondinv.h"
#include <assert.h>
#include "loadobjectmodel.h"
#include "cheat_buttons.h"
#include "player.h"
#include "file.h"
#include "fog.h"




//hack? used to match as called with 2 args, but decompiled code takes 1
extern s32 objectiveGetStatus_WEAK(s32 objectiveNum, s32); 


//bss
/**
 * Address 0x80069B70.
*/
sfxRecord sfx_related[SFX_RELATED_LEN];



/**
 * Play Audio in slot X from Prop or Pad 
 * @param slot: Where audio is loaded
*/
void audioPlayFromProp2(s32 slot)
{
    int tempvol;
    sfxRecord *sfx= &sfx_related[slot]; //always added to stack anyway, cleaner to use
    int clock_timer;

    if ((sfx->state ) && (sndGetPlayingState(sfx->state) ))
    {
    
        if (sfx->pos )
        {
            sfx->Volume = sub_GAME_7F0539E4(sfx->pos);   
        }
        else
        {
            if (sfx->Obj && sfx->Obj->prop)
            {
                sfx->Volume = sub_GAME_7F0539E4(&sfx->Obj->runtime_pos);
            }
        }

        tempvol = sfx->Volume;
        if (sfx->sfxID >= 0)
        {
            clock_timer = g_ClockTimer;
            if (clock_timer < sfx->sfxID)
            {
                tempvol = (((sfx->Volume - sfx->Volume2) * clock_timer) / sfx->sfxID) + sfx->Volume2;
            }
            sfx->sfxID = sfx->sfxID - clock_timer;
        }
        if (lvlGetControlsLockedFlag() != 0)
        {
            tempvol = 0;
        }
        if (tempvol != sfx->Volume2)
        {
            sndCreatePostEvent(sfx->state, 8, tempvol);
            sfx->Volume2 = tempvol;
            return;
        }
        return;
    }
    sfx->Volume2 = 0;
}



/**
 Play All Sounds in all slots 
*/
void loop_set_sound_effect_all_slots(void)
{
    int i;
    for (i = 0; i < SFX_RELATED_LEN; i++)
    {
        audioPlayFromProp2(i);
    }
}


/**
 * Load Audio Slot with sound and Play
 * @param slot: where to load sound
 * @param soundIndex: SFX_ID
*/
void audioPlayFromProp(s32 slot, s16 soundIndex) 
{
    sfxRecord *sfx = NULL; //always added to stack anyway, cleaner to use
    //"Existing ai sound number %d!\n"
    if (slot >= 0 && slot < SFX_RELATED_LEN)
    {
        if (!sfx_related[slot].state || !sndGetPlayingState(sfx_related[slot].state))
        {
            sfx = &sfx_related[slot];

            sfx->Volume  = SHRT_MAX;
            sfx->Volume2 = SHRT_MAX;
            sfx->sfxID   = -1;
            sfx->pos     = NULL;
            sfx->Obj     = NULL;
        }
    }
    sndPlaySfx(g_musicSfxBufferPtr, soundIndex, sfx);
}


/**
 Stop All Sounds in all slots 
*/
void sub_GAME_7F0349BC(s32 slot)
{
    if ((slot >= 0) && (slot < SFX_RELATED_LEN))
    {
        sndDeactivate(sfx_related[slot].state);
    }
}





/** 
 * Get AI Command Size in bytes
 * @param AIList: u8 Pointer to The AI list containing the command
 * @param offset: The offset (in bytes) to the command you want the size of
 * @return The number of bytes of AI command
 * @canonical name 
 */
s32 chraiitemsize(u8 *AIList, s32 offset)
{
    //matches only as u8* despite text evidence of ai->val structs
    switch (AIList[offset])
    {
        //Cant Use CMD Builder due to different order...
#if defined(USECMDBUILDER)
#    ifndef _SYNHILITE
#        define _AI_CMD(CMD)                                             /*  \
                                                                          */ \
            case CAT(AI_, CMDNAME):                                      /*  \
                                                                          */ \
                return CAT(CAT(AI_, CMDNAME), _LENGTH);
#        define _AI_DEBUG()
#        define _AI_CMD_POLYMORPH(CMD, A, P, Q, D)
#        define DEFINE(x)
#        include <aicommands.def>
#    endif
#endif
        case AI_GotoNext:
            return AI_GotoNext_LENGTH;
        case AI_GotoFirst:
            return AI_GotoFirst_LENGTH;
        case AI_Label:
            return AI_Label_LENGTH;
        case AI_Yield:
            return AI_Yield_LENGTH;
        case AI_EndList:
            return AI_EndList_LENGTH; 
        case AI_SetChrAiList:
            return AI_SetChrAiList_LENGTH;
        case AI_SetReturnAiList:
            return AI_SetReturnAiList_LENGTH;
        case AI_Return:
            return AI_Return_LENGTH;
        case AI_Stop:
            return AI_Stop_LENGTH;
        case AI_Kneel:
            return AI_Kneel_LENGTH;
        case AI_PlayAnimation:
            return AI_PlayAnimation_LENGTH;
        case AI_IFPlayingAnimation:
            return AI_IFPlayingAnimation_LENGTH;
        case AI_PointAtBond:
            return AI_PointAtBond_LENGTH;
        case AI_LookSurprised:
            return AI_LookSurprised_LENGTH;
        case AI_TRYSidestepping:
            return AI_TRYSidestepping_LENGTH;
        case AI_TRYSideHopping:
            return AI_TRYSideHopping_LENGTH;
        case AI_TRYSideRunning:
            return AI_TRYSideRunning_LENGTH;
        case AI_TRYFiringWalk:
            return AI_TRYFiringWalk_LENGTH;
        case AI_TRYFiringRun:
            return AI_TRYFiringRun_LENGTH;
        case AI_TRYFiringRoll:
            return AI_TRYFiringRoll_LENGTH;
        case AI_TRYFireOrAimAtTarget:
            return AI_TRYFireOrAimAtTarget_LENGTH;
        case AI_TRYFireOrAimAtTargetKneel:
            return AI_TRYFireOrAimAtTargetKneel_LENGTH;
        case AI_IFImFiring:
            return AI_IFImFiring_LENGTH;
        case AI_IFImFiringAndLockedForward:
            return AI_IFImFiringAndLockedForward_LENGTH;
        case AI_TRYFireOrAimAtTargetUpdate:
            return AI_TRYFireOrAimAtTargetUpdate_LENGTH;
        case AI_TRYFacingTarget:
            return AI_TRYFacingTarget_LENGTH;
        case AI_HitChrWithItem:
            return AI_HitChrWithItem_LENGTH;
        case AI_ChrHitChr:
            return AI_ChrHitChr_LENGTH;
        case AI_TRYThrowingGrenade:
            return AI_TRYThrowingGrenade_LENGTH;
        case AI_TRYDroppingItem:
            return AI_TRYDroppingItem_LENGTH;
        case AI_RunToPad:
            return AI_RunToPad_LENGTH;
        case AI_RunToPadPreset:
            return AI_RunToPadPreset_LENGTH;
        case AI_WalkToPad:
            return AI_WalkToPad_LENGTH;
        case AI_SprintToPad:
            return AI_SprintToPad_LENGTH;
        case AI_StartPatrol:
            return AI_StartPatrol_LENGTH;
        case AI_Surrender:
            return AI_Surrender_LENGTH;
        case AI_RemoveMe:
            return AI_RemoveMe_LENGTH;
        case AI_ChrRemoveInstant:
            return AI_ChrRemoveInstant_LENGTH;
        case AI_TRYTriggeringAlarmAtPad:
            return AI_TRYTriggeringAlarmAtPad_LENGTH;
        case AI_AlarmOn:
            return AI_AlarmOn_LENGTH;
        case AI_AlarmOff:
            return AI_AlarmOff_LENGTH;
        case AI_TRYRunFromBond:
            return AI_TRYRunFromBond_LENGTH;
        case AI_TRYRunToBond:
            return AI_TRYRunToBond_LENGTH;
        case AI_TRYWalkToBond:
            return AI_TRYWalkToBond_LENGTH;
        case AI_TRYSprintToBond:
            return AI_TRYSprintToBond_LENGTH;
        case AI_TRYFindCover:
            return AI_TRYFindCover_LENGTH;
        case AI_TRYRunToChr:
            return AI_TRYRunToChr_LENGTH;
        case AI_TRYWalkToChr:
            return AI_TRYWalkToChr_LENGTH;
        case AI_TRYSprintToChr:
            return AI_TRYSprintToChr_LENGTH;
        case AI_IFImOnPatrolOrStopped:
            return AI_IFImOnPatrolOrStopped_LENGTH;
        case AI_IFChrDyingOrDead:
            return AI_IFChrDyingOrDead_LENGTH;
        case AI_IFChrDoesNotExist:
            return AI_IFChrDoesNotExist_LENGTH;
        case AI_IFISeeBond:
            return AI_IFISeeBond_LENGTH;
        case AI_SetNewRandom:
            return AI_SetNewRandom_LENGTH;
        case AI_IFRandomLessThan:
            return AI_IFRandomLessThan_LENGTH;
        case AI_IFRandomGreaterThan:
            return AI_IFRandomGreaterThan_LENGTH;
        case AI_IFICanHearAlarm:
            return AI_IFICanHearAlarm_LENGTH;
        case AI_IFAlarmIsOn:
            return AI_IFAlarmIsOn_LENGTH;
        case AI_IFGasIsLeaking:
            return AI_IFGasIsLeaking_LENGTH;
        case AI_IFIHeardBond:
            return AI_IFIHeardBond_LENGTH;
        case AI_IFISeeSomeoneShot:
            return AI_IFISeeSomeoneShot_LENGTH;
        case AI_IFISeeSomeoneDie:
            return AI_IFISeeSomeoneDie_LENGTH;
        case AI_IFICouldSeeBond:
            return AI_IFICouldSeeBond_LENGTH;
        case AI_IFICouldSeeBondsStan:
            return AI_IFICouldSeeBondsStan_LENGTH;
        case AI_IFIWasShotRecently:
            return AI_IFIWasShotRecently_LENGTH;
        case AI_IFIHeardBondRecently:
            return AI_IFIHeardBondRecently_LENGTH;
        case AI_IFImInRoomWithChr:
            return AI_IFImInRoomWithChr_LENGTH;
        case AI_IFIveNotBeenSeen:
            return AI_IFIveNotBeenSeen_LENGTH;
        case AI_IFImOnScreen:
            return AI_IFImOnScreen_LENGTH;
        case AI_IFMyRoomIsOnScreen:
            return AI_IFMyRoomIsOnScreen_LENGTH;
        case AI_IFRoomWithPadIsOnScreen:
            return AI_IFRoomWithPadIsOnScreen_LENGTH;
        case AI_IFImTargetedByBond:
            return AI_IFImTargetedByBond_LENGTH;
        case AI_IFBondMissedMe:
            return AI_IFBondMissedMe_LENGTH;
        case AI_IFMyAngleToBondLessThan:
            return AI_IFMyAngleToBondLessThan_LENGTH;
        case AI_IFMyAngleToBondGreaterThan:
            return AI_IFMyAngleToBondGreaterThan_LENGTH;
        case AI_IFMyAngleFromBondLessThan:
            return AI_IFMyAngleFromBondLessThan_LENGTH;
        case AI_IFMyAngleFromBondGreaterThan:
            return AI_IFMyAngleFromBondGreaterThan_LENGTH;
        case AI_IFMyDistanceToBondLessThanDecimeter:
            return AI_IFMyDistanceToBondLessThanDecimeter_LENGTH;
        case AI_IFMyDistanceToBondGreaterThanDecimeter:
            return AI_IFMyDistanceToBondGreaterThanDecimeter_LENGTH;
        case AI_IFChrDistanceToPadLessThanDecimeter:
            return AI_IFChrDistanceToPadLessThanDecimeter_LENGTH;
        case AI_IFChrDistanceToPadGreaterThanDecimeter:
            return AI_IFChrDistanceToPadGreaterThanDecimeter_LENGTH;
        case AI_IFMyDistanceToChrLessThanDecimeter:
            return AI_IFMyDistanceToChrLessThanDecimeter_LENGTH;
        case AI_IFMyDistanceToChrGreaterThanDecimeter:
            return AI_IFMyDistanceToChrGreaterThanDecimeter_LENGTH;
        case AI_TRYSettingMyPresetToChrWithinDistanceDecimeter:
            return AI_TRYSettingMyPresetToChrWithinDistanceDecimeter_LENGTH;
        case AI_IFBondDistanceToPadLessThanDecimeter:
            return AI_IFBondDistanceToPadLessThanDecimeter_LENGTH;
        case AI_IFBondDistanceToPadGreaterThanDecimeter:
            return AI_IFBondDistanceToPadGreaterThanDecimeter_LENGTH;
        case AI_IFChrInRoomWithPad:
            return AI_IFChrInRoomWithPad_LENGTH;
        case AI_IFBondInRoomWithPad:
            return AI_IFBondInRoomWithPad_LENGTH;
        case AI_IFBondCollectedObject:
            return AI_IFBondCollectedObject_LENGTH;
        case AI_IFItemIsStationaryWithinLevel:
            return AI_IFItemIsStationaryWithinLevel_LENGTH;
        case AI_IFItemIsAttachedToObject:
            return AI_IFItemIsAttachedToObject_LENGTH;
        case AI_IFBondHasItemEquipped:
            return AI_IFBondHasItemEquipped_LENGTH;
        case AI_IFObjectExists:
            return AI_IFObjectExists_LENGTH;
        case AI_IFObjectNotDestroyed:
            return AI_IFObjectNotDestroyed_LENGTH;
        case AI_IFObjectWasActivated:
            return AI_IFObjectWasActivated_LENGTH;
        case AI_IFBondUsedGadgetOnObject:
            return AI_IFBondUsedGadgetOnObject_LENGTH;
        case AI_ActivateObject:
            return AI_ActivateObject_LENGTH;
        case AI_DestroyObject:
            return AI_DestroyObject_LENGTH;
        case AI_DropObject:
            return AI_DropObject_LENGTH;
        case AI_ChrDropAllConcealedItems:
            return AI_ChrDropAllConcealedItems_LENGTH;
        case AI_ChrDropAllHeldItems:
            return AI_ChrDropAllHeldItems_LENGTH;
        case AI_BondCollectObject:
            return AI_BondCollectObject_LENGTH;
        case AI_ChrEquipObject:
            return AI_ChrEquipObject_LENGTH;
        case AI_MoveObject:
            return AI_MoveObject_LENGTH;
        case AI_DoorOpen:
            return AI_DoorOpen_LENGTH;
        case AI_DoorClose:
            return AI_DoorClose_LENGTH;
        case AI_IFDoorStateEqual:
            return AI_IFDoorStateEqual_LENGTH;
        case AI_IFDoorHasBeenOpenedBefore:
            return AI_IFDoorHasBeenOpenedBefore_LENGTH;
        case AI_DoorSetLock:
            return AI_DoorSetLock_LENGTH;
        case AI_DoorUnsetLock:
            return AI_DoorUnsetLock_LENGTH;
        case AI_IFDoorLockEqual:
            return AI_IFDoorLockEqual_LENGTH;
        case AI_IFObjectiveNumComplete:
            return AI_IFObjectiveNumComplete_LENGTH;
        case AI_TRYUnknown6e:
            return AI_TRYUnknown6e_LENGTH;
        case AI_TRYUnknown6f:
            return AI_TRYUnknown6f_LENGTH;
        case AI_IFGameDifficultyLessThan:
            return AI_IFGameDifficultyLessThan_LENGTH;
        case AI_IFGameDifficultyGreaterThan:
            return AI_IFGameDifficultyGreaterThan_LENGTH;
        case AI_IFMissionTimeLessThan:
            return AI_IFMissionTimeLessThan_LENGTH;
        case AI_IFMissionTimeGreaterThan:
            return AI_IFMissionTimeGreaterThan_LENGTH;
        case AI_IFSystemPowerTimeLessThan:
            return AI_IFSystemPowerTimeLessThan_LENGTH;
        case AI_IFSystemPowerTimeGreaterThan:
            return AI_IFSystemPowerTimeGreaterThan_LENGTH;
        case AI_IFLevelIdLessThan:
            return AI_IFLevelIdLessThan_LENGTH;
        case AI_IFLevelIdGreaterThan:
            return AI_IFLevelIdGreaterThan_LENGTH;
        case AI_IFMyNumArghsLessThan:
            return AI_IFMyNumArghsLessThan_LENGTH;
        case AI_IFMyNumArghsGreaterThan:
            return AI_IFMyNumArghsGreaterThan_LENGTH;
        case AI_IFMyNumCloseArghsLessThan:
            return AI_IFMyNumCloseArghsLessThan_LENGTH;
        case AI_IFMyNumCloseArghsGreaterThan:
            return AI_IFMyNumCloseArghsGreaterThan_LENGTH;
        case AI_IFChrHealthLessThan:
            return AI_IFChrHealthLessThan_LENGTH;
        case AI_IFChrHealthGreaterThan:
            return AI_IFChrHealthGreaterThan_LENGTH;
        case AI_IFChrWasDamagedSinceLastCheck:
            return AI_IFChrWasDamagedSinceLastCheck_LENGTH;
        case AI_IFBondHealthLessThan:
            return AI_IFBondHealthLessThan_LENGTH;
        case AI_IFBondHealthGreaterThan:
            return AI_IFBondHealthGreaterThan_LENGTH;
        case AI_SetMyMorale:
            return AI_SetMyMorale_LENGTH;
        case AI_AddToMyMorale:
            return AI_AddToMyMorale_LENGTH;
        case AI_SubtractFromMyMorale:
            return AI_SubtractFromMyMorale_LENGTH;
        case AI_IFMyMoraleLessThan:
            return AI_IFMyMoraleLessThan_LENGTH;
        case AI_IFMyMoraleLessThanRandom:
            return AI_IFMyMoraleLessThanRandom_LENGTH;
        case AI_SetMyAlertness:
            return AI_SetMyAlertness_LENGTH;
        case AI_AddToMyAlertness:
            return AI_AddToMyAlertness_LENGTH;
        case AI_SubtractFromMyAlertness:
            return AI_SubtractFromMyAlertness_LENGTH;
        case AI_IFMyAlertnessLessThan:
            return AI_IFMyAlertnessLessThan_LENGTH;
        case AI_IFMyAlertnessLessThanRandom:
            return AI_IFMyAlertnessLessThanRandom_LENGTH;
        case AI_SetMyHearingScale:
            return AI_SetMyHearingScale_LENGTH;
        case AI_SetMyVisionRange:
            return AI_SetMyVisionRange_LENGTH;
        case AI_SetMyGrenadeProbability:
            return AI_SetMyGrenadeProbability_LENGTH;
        case AI_SetMyChrNum:
            return AI_SetMyChrNum_LENGTH;
        case AI_SetMyHealthTotal:
            return AI_SetMyHealthTotal_LENGTH;
        case AI_SetMyArmour:
            return AI_SetMyArmour_LENGTH;
        case AI_SetMySpeedRating:
            return AI_SetMySpeedRating_LENGTH;
        case AI_SetMyArghRating:
            return AI_SetMyArghRating_LENGTH;
        case AI_SetMyAccuracyRating:
            return AI_SetMyAccuracyRating_LENGTH;
        case AI_SetMyFlags2:
            return AI_SetMyFlags2_LENGTH;
        case AI_UnsetMyFlags2:
            return AI_UnsetMyFlags2_LENGTH;
        case AI_IFMyFlags2Has:
            return AI_IFMyFlags2Has_LENGTH;
        case AI_SetChrBitfield:
            return AI_SetChrBitfield_LENGTH;
        case AI_UnsetChrBitfield:
            return AI_UnsetChrBitfield_LENGTH;
        case AI_IFChrBitfieldHas:
            return AI_IFChrBitfieldHas_LENGTH;
        case AI_SetObjectiveBitfield:
            return AI_SetObjectiveBitfield_LENGTH;
        case AI_UnsetObjectiveBitfield:
            return AI_UnsetObjectiveBitfield_LENGTH;
        case AI_IFObjectiveBitfieldHas:
            return AI_IFObjectiveBitfieldHas_LENGTH;
        case AI_SetMychrflags:
            return AI_SetMychrflags_LENGTH;
        case AI_UnsetMychrflags:
            return AI_UnsetMychrflags_LENGTH;
        case AI_IFMychrflagsHas:
            return AI_IFMychrflagsHas_LENGTH;
        case AI_SetChrchrflags:
            return AI_SetChrchrflags_LENGTH;
        case AI_UnsetChrchrflags:
            return AI_UnsetChrchrflags_LENGTH;
        case AI_IFChrchrflagsHas:
            return AI_IFChrchrflagsHas_LENGTH;
        case AI_SetObjectFlags:
            return AI_SetObjectFlags_LENGTH;
        case AI_UnsetObjectFlags:
            return AI_UnsetObjectFlags_LENGTH;
        case AI_IFObjectFlagsHas:
            return AI_IFObjectFlagsHas_LENGTH;
        case AI_SetObjectFlags2:
            return AI_SetObjectFlags2_LENGTH;
        case AI_UnsetObjectFlags2:
            return AI_UnsetObjectFlags2_LENGTH;
        case AI_IFObjectFlags2Has:
            return AI_IFObjectFlags2Has_LENGTH;
        case AI_SetMyChrPreset:
            return AI_SetMyChrPreset_LENGTH;
        case AI_SetChrChrPreset:
            return AI_SetChrChrPreset_LENGTH;
        case AI_SetMyPadPreset:
            return AI_SetMyPadPreset_LENGTH;
        case AI_SetChrPadPreset:
            return AI_SetChrPadPreset_LENGTH;
        case AI_MyTimerStart:
            return AI_MyTimerStart_LENGTH;
        case AI_MyTimerReset:
            return AI_MyTimerReset_LENGTH;
        case AI_MyTimerPause:
            return AI_MyTimerPause_LENGTH;
        case AI_MyTimerResume:
            return AI_MyTimerResume_LENGTH;
        case AI_IFMyTimerIsNotRunning:
            return AI_IFMyTimerIsNotRunning_LENGTH;
        case AI_IFMyTimerLessThanTicks:
            return AI_IFMyTimerLessThanTicks_LENGTH;
        case AI_IFMyTimerGreaterThanTicks:
            return AI_IFMyTimerGreaterThanTicks_LENGTH;
        case AI_HudCountdownShow:
            return AI_HudCountdownShow_LENGTH;
        case AI_HudCountdownHide:
            return AI_HudCountdownHide_LENGTH;
        case AI_HudCountdownSet:
            return AI_HudCountdownSet_LENGTH;
        case AI_HudCountdownStop:
            return AI_HudCountdownStop_LENGTH;
        case AI_HudCountdownStart:
            return AI_HudCountdownStart_LENGTH;
        case AI_IFHudCountdownIsNotRunning:
            return AI_IFHudCountdownIsNotRunning_LENGTH;
        case AI_IFHudCountdownLessThan:
            return AI_IFHudCountdownLessThan_LENGTH;
        case AI_IFHudCountdownGreaterThan:
            return AI_IFHudCountdownGreaterThan_LENGTH;
        case AI_TRYSpawningChrAtPad:
            return AI_TRYSpawningChrAtPad_LENGTH;
        case AI_TRYSpawningChrNextToChr:
            return AI_TRYSpawningChrNextToChr_LENGTH;
        case AI_TRYGiveMeItem:
            return AI_TRYGiveMeItem_LENGTH;
        case AI_TRYGiveMeHat:
            return AI_TRYGiveMeHat_LENGTH;
        case AI_TRYCloningChr:
            return AI_TRYCloningChr_LENGTH;
        case AI_TextPrintBottom:
            return AI_TextPrintBottom_LENGTH;
        case AI_TextPrintTop:
            return AI_TextPrintTop_LENGTH;
        case AI_SfxPlay:
            return AI_SfxPlay_LENGTH;
        case AI_SfxEmitFromObject:
            return AI_SfxEmitFromObject_LENGTH;
        case AI_SfxEmitFromPad:
            return AI_SfxEmitFromPad_LENGTH;
        case AI_SfxSetChannelVolume:
            return AI_SfxSetChannelVolume_LENGTH;
        case AI_SfxFadeChannelVolume:
            return AI_SfxFadeChannelVolume_LENGTH;
        case AI_SfxStopChannel:
            return AI_SfxStopChannel_LENGTH;
        case AI_IFSfxChannelVolumeLessThan:
            return AI_IFSfxChannelVolumeLessThan_LENGTH;
        case AI_VehicleStartPath:
            return AI_VehicleStartPath_LENGTH;
        case AI_VehicleSpeed:
            return AI_VehicleSpeed_LENGTH;
        case AI_AircraftRotorSpeed:
            return AI_AircraftRotorSpeed_LENGTH;
        case AI_IFCameraIsInIntro:
            return AI_IFCameraIsInIntro_LENGTH;
        case AI_IFCameraIsInBondSwirl:
            return AI_IFCameraIsInBondSwirl_LENGTH;
        case AI_TvChangeScreenBank:
            return AI_TvChangeScreenBank_LENGTH;
        case AI_IFBondInTank:
            return AI_IFBondInTank_LENGTH; 
        case AI_EndLevel:
            return AI_EndLevel_LENGTH;
        case AI_CameraReturnToBond:
            return AI_CameraReturnToBond_LENGTH;
        case AI_CameraLookAtBondFromPad:
            return AI_CameraLookAtBondFromPad_LENGTH;
        case AI_CameraSwitch:
            return AI_CameraSwitch_LENGTH;
        case AI_IFBondYPosLessThan:
            return AI_IFBondYPosLessThan_LENGTH;
        case AI_BondDisableControl:
            return AI_BondDisableControl_LENGTH;
        case AI_BondEnableControl:
            return AI_BondEnableControl_LENGTH;
        case AI_TRYTeleportingChrToPad:
            return AI_TRYTeleportingChrToPad_LENGTH;
        case AI_ScreenFadeToBlack:
            return AI_ScreenFadeToBlack_LENGTH;
        case AI_ScreenFadeFromBlack:
            return AI_ScreenFadeFromBlack_LENGTH;
        case AI_IFScreenFadeCompleted:
            return AI_IFScreenFadeCompleted_LENGTH;
        case AI_HideAllChrs:
            return AI_HideAllChrs_LENGTH;
        case AI_ShowAllChrs:
            return AI_ShowAllChrs_LENGTH;
        case AI_DoorOpenInstant:
            return AI_DoorOpenInstant_LENGTH;
        case AI_ChrRemoveItemInHand:
            return AI_ChrRemoveItemInHand_LENGTH;
        case AI_IfNumberOfActivePlayersLessThan:
            return AI_IfNumberOfActivePlayersLessThan_LENGTH;
        case AI_IFBondItemTotalAmmoLessThan:
            return AI_IFBondItemTotalAmmoLessThan_LENGTH;
        case AI_BondEquipItem:
            return AI_BondEquipItem_LENGTH;
        case AI_BondEquipItemCinema:
            return AI_BondEquipItemCinema_LENGTH;
        case AI_BondSetLockedVelocity:
            return AI_BondSetLockedVelocity_LENGTH;
        case AI_IFObjectInRoomWithPad:
            return AI_IFObjectInRoomWithPad_LENGTH;
        case AI_SwitchSky:
            return AI_SwitchSky_LENGTH;
        case AI_TriggerFadeAndExitLevelOnButtonPress:
            return AI_TriggerFadeAndExitLevelOnButtonPress_LENGTH;
        case AI_IFBondIsDead:
            return AI_IFBondIsDead_LENGTH;
        case AI_BondDisableDamageAndPickups:
            return AI_BondDisableDamageAndPickups_LENGTH;
        case AI_BondHideWeapons:
            return AI_BondHideWeapons_LENGTH;
        case AI_CameraOrbitPad:
            return AI_CameraOrbitPad_LENGTH;
        case AI_CreditsRoll:
            return AI_CreditsRoll_LENGTH;
        case AI_IFCreditsHasCompleted:
            return AI_IFCreditsHasCompleted_LENGTH;
        case AI_IFObjectiveAllCompleted:
            return AI_IFObjectiveAllCompleted_LENGTH;
        case AI_IFFolderActorIsEqual:
            return AI_IFFolderActorIsEqual_LENGTH;
        case AI_IFBondDamageAndPickupsDisabled:
            return AI_IFBondDamageAndPickupsDisabled_LENGTH;
        case AI_MusicPlaySlot:
            return AI_MusicPlaySlot_LENGTH;
        case AI_MusicStopSlot:
            return AI_MusicStopSlot_LENGTH;
        case AI_TriggerExplosionsAroundBond:
            return AI_TriggerExplosionsAroundBond_LENGTH;
        case AI_IFKilledCiviliansGreaterThan:
            return AI_IFKilledCiviliansGreaterThan_LENGTH;
        case AI_IFChrWasShotSinceLastCheck:
            return AI_IFChrWasShotSinceLastCheck_LENGTH;
        case AI_BondKilledInAction:
            return AI_BondKilledInAction_LENGTH;
        case AI_RaiseArms:
            return AI_RaiseArms_LENGTH;
        case AI_GasLeakAndFadeFog:
            return AI_GasLeakAndFadeFog_LENGTH;
        case AI_ObjectRocketLaunch:
            return AI_ObjectRocketLaunch_LENGTH;
        case AI_PRINT:
        {   
            s32 pos = offset + 1;
            while (AIList[pos] != 0) 
            {
                ++pos;
            }
            return (pos - offset) + 1;
        }
        default:
#       if defined(ENABLE_LOG)
            osSyncPrintf("chraiitemsize: unknown type %d!\n", *AIList);
#       endif
            return 1;
    }
}


/**
 * Get ID of AIList 
 * @param AIList: Ailist to get ID of
 * @return ID of AIList 
 */
s32 chraiGetAIListID(AIRecord *AIList, bool *isGlobalAIList) 
{
    s32 i;

    if (g_CurrentSetup.ailists)
    {
        for (i = 0; g_CurrentSetup.ailists[i].ailist; i++)
        {
            if (g_CurrentSetup.ailists[i].ailist == AIList)
            {
                *isGlobalAIList = FALSE;
                return g_CurrentSetup.ailists[i].ID;
            }
        }
    }

    for (i = 0; g_GlobalAILists[i].ailist; i++)
    {
        if (g_GlobalAILists[i].ailist == AIList)
        {
            *isGlobalAIList = TRUE;
            return g_GlobalAILists[i].ID;
        }
    }

    return -1;
}





/** 
 * GoTo Label
 * @param AIlist: AIList containing label
 * @param LabelNum: Integer/enum ID to go to
 * @return Offset of label from beggining of AIList.
 */
s32 chraiGoToLabel(AIRecord *AIList, s32 Offset, u8 LabelNum) 
{
    s32   listID;
    char *debAIListTypeString;
    bool  isGlobalAIList;

    for (;;)
    {
        if (AIList[Offset].cmd == AI_Label)
        {
            if (AIList[Offset].val[0] == LabelNum)
            {
                // exit loop and return offset to label number
                return Offset;
            }
        }
        else if (AIList[Offset].cmd == AI_EndList)
        {
            // restart ai list PC if next label not found - causes infinit loop outside of debug
            listID = chraiGetAIListID(AIList, &isGlobalAIList);
#    ifdef DEBUG
            if (isGlobalAIList)
            {
                debAIListTypeString = "global";
            }
            else
            {
                debAIListTypeString = "local";
            }
            osSyncPrintf("AI error: endlist reached jump label=%d %s list=%d!\n", LabelNum, debAIListTypeString, listID);
#    endif
            return 0;
        }

        Offset += chraiitemsize(AIList, Offset);
    }
}




AIRecord *ailistFindById(s32 ID) 
{
    s32 i;

    if (!isGlobalAIListID(ID))
    {
        if (g_CurrentSetup.ailists)
        {
            for (i = 0; g_CurrentSetup.ailists[i].ailist; i++)
            {
                if (g_CurrentSetup.ailists[i].ID == ID)
                {
                    return g_CurrentSetup.ailists[i].ailist;
                }
            }
        }
    }
    else
    {
        for (i = 0; g_GlobalAILists[i].ailist; i++)
        {
            if (g_GlobalAILists[i].ID == ID)
            {
                return g_GlobalAILists[i].ailist;
            }
        }
    }
    return NULL;
}





PathRecord *pathFindById(s32 ID)
{
    int i;

        for  (i=0;g_CurrentSetup.patrolpaths[i].waypoints;i++)
        {
            if ( ID == g_CurrentSetup.patrolpaths[i].ID )
            {
                return &g_CurrentSetup.patrolpaths[i];
            }
           
        }

    return NULL;
}





//forward
extern void chrpropDelist(PropRecord *prop);
extern PadRecord * dword_CODE_bss_800799F8;
extern CutsceneRecord *gBondViewCutscene;
extern enum CAMERAMODE dword_CODE_bss_80079A18;
extern s32 dword_CODE_bss_80079A1C;
extern vec3d g_ForceBondMoveOffset;
//CODE.bss:80079A00
extern f32 flt_CODE_bss_80079A00;
//CODE.bss:80079A04
extern f32 flt_CODE_bss_80079A04;
//CODE.bss:80079A08
extern f32 flt_CODE_bss_80079A08;
//CODE.bss:80079A0C
extern f32 flt_CODE_bss_80079A0C;
//CODE.bss:80079A10
extern f32 flt_CODE_bss_80079A10;
//CODE.bss:80079A14
extern s32 dword_CODE_bss_80079A14;
extern bool g_isBondKIA;
//end forward




/**
 Execute AI List from Character, Stage, Vehichle(truck) or Aircraft(heli)
 Note: GE has little error checking (eg, using a chr action on aircraft) - this was fixed in PD
 @param *Entityp: Pointer to Entity (non-typed)
 @param EntityType: PROPTYPE_CHR or PROPTYPE_OBJ
 @param         PROPTYPE_CHR = Character or BG
 @param         PROPTYPE_OBJ = Object (Vehichle or Aircraft)
 @canonical name ~ maybe
*/
void ai(PropDefHeaderRecord *Entityp, PROP_TYPE EntityType)
{
    /*
     * (void *Param, int ParamType) is the correct way to pass a variable
     *    "object" eg Param can be Either ChrRecord or VehichleRecord
     *
     * Function Name derived from internal strings:
     *    ai(void) enery tune on (%d, %d, %d)
     *    ai(void) enery tune off (%d)
     *
     * Stack requires that each case declair its own AIRecord variable
     *
     */

    ChrRecord      *ChrEntityp      = NULL;
    VehichleRecord *VehichleEntityp = NULL;
    AircraftRecord *AircraftEntityp = NULL;
    AIRecord       *AiListp         = NULL;
    s32             Offset;

    if (EntityType == PROP_TYPE_CHR)
    {
        ChrEntityp = Entityp;
    }
    else if (EntityType == PROP_TYPE_OBJ)
    {
        if (Entityp->type == PROPDEF_VEHICHLE)
        {
            VehichleEntityp = Entityp;
        }
        else if (Entityp->type == PROPDEF_AIRCRAFT)
        {
            AircraftEntityp = Entityp;
        }
    }

    // Load ailist
    if (ChrEntityp)
    {
        Offset  = ChrEntityp->aioffset;
        AiListp = ChrEntityp->ailist;
    }
    else if (VehichleEntityp)
    {
        Offset  = VehichleEntityp->aioffset;
        AiListp = VehichleEntityp->ailist;
    }
    else if (AircraftEntityp)
    {
        Offset  = AircraftEntityp->aioffset;
        AiListp = AircraftEntityp->ailist;
    }

    if (AiListp) // continue if Has ailist (check once)
    {
        // loop forever (or until broken)
        for (;;)
        {
            /*
             * GE uses long Switch/case while PD uses Bool functions and tests 
             * for TRUE/FALSE if(funcpointer[ai]) break; 
             */
            switch ((AiListp + Offset)->cmd)
            {
                //unfortunatly we cannot use the cmdbuilder in matching rom as the ordering is not sequential
#ifdef USECMDBUILDER
    #define _AI_DEBUG_ID(CMD, AI_NUMBER_OF_PARAMS, PARAM, DESC)
    #define _AI_CMD_POLYMORPH(C, N, P1, P2, D)
    #define _AI_CMD_ID(CMD, AI_NUMBER_OF_PARAMS, PARAM, DESC, CODE) /*  HACK: Multiline Comments make Newlines in macro */ \
                    case CAT(CAT(AI_, CMD), ):                      /*                                                     \
                                                                    */                                                     \
                        CODE
    #include "aicommands.def"
#else
                case AI_GotoNext:
                {
                    AIRecord1 *ai = AiListp + Offset;
                    Offset        = chraiGoToLabel(AiListp, Offset, ai->val);
#ifdef ENABLE_LOG
                    osSyncPrintf("GOTO Next (%d)\n", ai->val);
#endif
                    break;
                }
                case AI_GotoFirst:
                {
                    AIRecord1 *ai = AiListp + Offset;
                    Offset        = chraiGoToLabel(AiListp, 0, ai->val);
#ifdef ENABLE_LOG
                    osSyncPrintf("GOTO First (%d)\n", ai->val);
#endif
                    break;
                }
                case AI_Label:
                {
                    Offset += AI_Label_LENGTH;
                    break;
                }
                case AI_Yield:
                {
                    Offset += AI_Yield_LENGTH;
                    if (ChrEntityp)
                    {
                        ChrEntityp->ailist   = AiListp;
                        ChrEntityp->aioffset = Offset;
                    }
                    else if (VehichleEntityp)
                    {
                        VehichleEntityp->ailist   = AiListp;
                        VehichleEntityp->aioffset = Offset;
                    }
                    else if (AircraftEntityp)
                    {
                        AircraftEntityp->ailist   = AiListp;
                        AircraftEntityp->aioffset = Offset;
                    }
                    return;
                }
                case AI_EndList:
                {
                    //Not an error to be here, same as yield except without pushing offset past it.
                    return; 
                }
                case AI_SetChrAiList:
                {
                    AIRecord  *ai         = AiListp + Offset;         /* needed for stack count inflation */
                    ChrRecord *chr;                                   //ok, so mips does not hoist vars in stack, they are in order so must be declaired here
                    u16        AI_LIST_ID = CharArrayTo16(ai->val,1); /* This is the only way to match despite assetrs below */
                    u8         CHR_NUM    = ai->val[0];

                    if (CHR_NUM == ((u8)CHR_SELF))
                    {
                        AiListp = ailistFindById(AI_LIST_ID); 
                        Offset  = 0;
                    }
                    else
                    {
                        chr = chrFindById(ChrEntityp, CHR_NUM);
                        if (chr)
                        {
                            chr->ailist   = ailistFindById(AI_LIST_ID);
                            chr->aioffset = 0;
                            chr->sleep    = 0;
                        }
                        Offset += AI_SetChrAiList_LENGTH;
                    }
                    break;
                }
                case AI_SetReturnAiList:
                {
                    AIRecord *ai         = AiListp + Offset;
                    u16       AI_LIST_ID = CharArrayTo16(ai->val,0);

                    if (ChrEntityp)
                    {
                        ChrEntityp->aireturnlist = AI_LIST_ID;
                    }
                    else if (VehichleEntityp)
                    {
                        VehichleEntityp->aireturnlist = AI_LIST_ID;
                    }
                    else if (AircraftEntityp)
                    {
                        AircraftEntityp->aireturnlist = AI_LIST_ID;
                    }

                    Offset += AI_SetReturnAiList_LENGTH;
                    break;
                }
                case AI_Return:
                {
                    if (ChrEntityp)
                    {
                        AiListp = ailistFindById(ChrEntityp->aireturnlist);
                    }
                    else if (VehichleEntityp)
                    {
                        AiListp = ailistFindById(VehichleEntityp->aireturnlist);
                    }
                    else if (AircraftEntityp)
                    {
                        AiListp = ailistFindById(AircraftEntityp->aireturnlist);
                    }
                    Offset = 0;
                    break;
                }
                case AI_Stop:
                {
                    chraiStopAnimation(ChrEntityp);
                    Offset += AI_Stop_LENGTH;
                    break;
                }
                case AI_Kneel:
                {
                    check_if_able_to_then_kneel(ChrEntityp);
                    Offset += AI_Kneel_LENGTH;
                    break;
                }
                case AI_PlayAnimation:
                {
                    AIRecord *ai = AiListp + Offset;
                    s32       startframe, anim_id, zero, endframe;

                    anim_id    = CharArrayTo16(ai->val,0);
                    startframe = CharArrayTo16(ai->val,2);
                    endframe   = CharArrayTo16(ai->val,4);

                    if (startframe == (u16)-1)
                    {
                        startframe = 0;
                    }
                    if (endframe == (u16)-1)
                    {
                        endframe = -1;
                    }

                    if (ChrEntityp)
                    {
                        check_if_able_to_then_perform_animation(ChrEntityp, anim_id, startframe, endframe, ai->val[6], ai->val[7]);
                    }
                    else if (AircraftEntityp)
                    {
                        zero = 0; //debug value maybe?
                        modelSetAnimation(AircraftEntityp->model, animation_table_ptrs2[anim_id], zero, startframe, 0.5f, (s32)ai->val[7]);
                        if (endframe >= 0)
                        {
                            modelSetAnimEndFrame(AircraftEntityp->model, endframe);
                        }
                    }
                    Offset += AI_PlayAnimation_LENGTH;
                    break;
                }
                case AI_IFPlayingAnimation:
                {
                    AIRecord1 *ai = (AiListp + Offset);

                    if (ChrEntityp->actiontype == ACT_ANIM)
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val);
                    }
                    else
                    {
                        Offset += AI_IFPlayingAnimation_LENGTH;
                    }
                    break;
                }
                case AI_PointAtBond:
                {
                    chrTrySurprisedOneHand(ChrEntityp);
                    Offset += AI_PointAtBond_LENGTH;
                    break;
                }
                case AI_LookSurprised:
                {
                    chrTrySurprisedLookAround(ChrEntityp);
                    Offset += AI_LookSurprised_LENGTH;
                    break;
                }
                case AI_IFImOnPatrolOrStopped:
                {
                    AIRecord1 *ai = AiListp + Offset;
                    if (chrHasStoppedOrPatroling(ChrEntityp))
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val);
                    }
                    else
                    {
                        Offset += AI_IFImOnPatrolOrStopped_LENGTH;
                    }
                    break;
                }
                case AI_IFChrDyingOrDead:
                {
                    AIRecord  *ai  = AiListp + Offset;
                    ChrRecord *chr = chrFindById(ChrEntityp, ai->val[0]);

                    if (!chr || chrIsDead(chr))
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[1]);
                    }
                    else
                    {
                        Offset += AI_IFChrDyingOrDead_LENGTH;
                    }
                    break;
                }
                case AI_IFChrDoesNotExist:
                {
                    AIRecord  *ai  = AiListp + Offset;
                    ChrRecord *chr = chrFindById(ChrEntityp, ai->val[0]);

                    if (!chr || !chr->model)
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[1]);
                    }
                    else
                    {
                        Offset += AI_IFChrDoesNotExist_LENGTH;
                    }
                    break;
                }
                case AI_IFISeeBond:
                {
                    AIRecord1 *ai = AiListp + Offset;

                    if (chrCheckTargetInSight(ChrEntityp))
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val);
                    }
                    else
                    {
                        Offset += AI_IFISeeBond_LENGTH;
                    }
                    break;
                }

                case AI_TRYSidestepping:
                {
                    AIRecord1 *ai = AiListp + Offset;

                    if (actor_steps_sideways(ChrEntityp))
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val);
                    }
                    else
                    {
                        Offset += AI_TRYSidestepping_LENGTH;
                    }
                    break;
                }
                case AI_TRYSideHopping:
                {
                    AIRecord1 *ai = AiListp + Offset;

                    if (actor_hops_sideways(ChrEntityp))
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val);
                    }
                    else
                    {
                        Offset += AI_TRYSideHopping_LENGTH;
                    }
                    break;
                }
                case AI_TRYSideRunning:
                {
                    AIRecord1 *ai = AiListp + Offset;

                    if (actor_jogs_sideways(ChrEntityp))
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val);
                    }
                    else
                    {
                        Offset += AI_TRYSideRunning_LENGTH;
                    }
                    break;
                }
                case AI_TRYFiringWalk:
                {
                    AIRecord1 *ai = AiListp + Offset;

                    if (actor_walks_and_fires(ChrEntityp))
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val);
                    }
                    else
                    {
                        Offset += AI_TRYFiringWalk_LENGTH;
                    }
                    break;
                }
                case AI_TRYFiringRun:
                {
                    AIRecord1 *ai = AiListp + Offset;

                    if (actor_runs_and_fires(ChrEntityp))
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val);
                    }
                    else
                    {
                        Offset += AI_TRYFiringRun_LENGTH;
                    }
                    break;
                }
                case AI_TRYFiringRoll:
                {
                    AIRecord1 *ai = AiListp + Offset;

                    if (actor_rolls_fires_crouched(ChrEntityp))
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val);
                    }
                    else
                    {
                        Offset += AI_TRYFiringRoll_LENGTH;
                    }
                    break;
                }
                case AI_TRYFireOrAimAtTarget:
                {
                    AIRecord *ai         = AiListp + Offset;
                    s32       targetid   = CharArrayTo16(ai->val,2);
                    s32       targettype = CharArrayTo16(ai->val,0);
                    if (actor_aim_at_actor(ChrEntityp, targettype, targetid))
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[4]);
                    }
                    else
                    {
                        Offset += AI_TRYFireOrAimAtTarget_LENGTH;
                    }
                    break;
                }
                case AI_TRYFireOrAimAtTargetKneel:
                {
                    AIRecord *ai         = AiListp + Offset;
                    s32       targetid   = CharArrayTo16(ai->val,2);
                    s32       targettype = CharArrayTo16(ai->val,0);
                    if (actor_kneel_aim_at_actor(ChrEntityp, targettype, targetid))
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[4]);
                    }
                    else
                    {
                        Offset += AI_TRYFireOrAimAtTargetKneel_LENGTH;
                    }
                    break;
                }
                case AI_IFImFiringAndLockedForward:
                {
                    AIRecord1 *ai = AiListp + Offset;

                    if (ChrEntityp->actiontype == ACT_ATTACK &&
                        !ChrEntityp->act_attack.type_of_motion &&
                         ChrEntityp->act_attack.attacktype & ATTACKTYPE_DONTTURN)
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val);
                    }
                    else
                    {
                        Offset += AI_IFImFiringAndLockedForward_LENGTH;
                    }
                    break;
                }
                case AI_IFImFiring:
                {
                    AIRecord1 *ai = AiListp + Offset;

                    if (ChrEntityp->actiontype == ACT_ATTACK)
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val);
                    }
                    else
                    {
                        Offset += AI_IFImFiring_LENGTH;
                    }
                    break;
                }

                case AI_TRYFireOrAimAtTargetUpdate:
                {
                    AIRecord *ai         = AiListp + Offset;
                    s32       targetid   = CharArrayTo16(ai->val,2);
                    s32       targettype = CharArrayTo16(ai->val,0);
                    if (actor_fire_or_aim_at_target_update(ChrEntityp, targettype, targetid))
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[4]);
                    }
                    else
                    {
                        Offset += AI_TRYFireOrAimAtTargetUpdate_LENGTH;
                    }
                    break;
                }
                case AI_TRYFacingTarget:
                {
                    AIRecord *ai         = AiListp + Offset;
                    s32       targetid   = CharArrayTo16(ai->val,2);
                    s32       targettype = CharArrayTo16(ai->val,0);
                    if (check_set_actor_standing_still(ChrEntityp, targettype, targetid))
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[4]);
                    }
                    else
                    {
                        Offset += AI_TRYFacingTarget_LENGTH;
                    }
                    break;
                }
                case AI_HitChrWithItem:
                {
                    AIRecord  *ai  = AiListp + Offset;
                    ChrRecord *chr = chrFindById(ChrEntityp, ai->val[0]);
                    vec3d      vec = New_Vector();

                    if (chr && chr->prop)
                    {
                        handles_shot_actors(chr, (s8)ai->val[1], &vec, ai->val[2], FALSE);
                    }

                    Offset += AI_HitChrWithItem_LENGTH;
                    break;
                }
                case AI_ChrHitChr:
                {
                    AIRecord  *ai   = AiListp + Offset;
                    ChrRecord *chr1 = chrFindById(ChrEntityp, ai->val[0]);
                    ChrRecord *chr2 = chrFindById(ChrEntityp, ai->val[1]);

                    if (chr1 && chr2 && chr1->prop && chr2->prop)
                    {
                        PropRecord      *prop = chrGetEquippedWeaponPropWithCheck(chr1, GUNRIGHT);
                        WeaponObjRecord *weapon;
                        vec3d            vec = New_Vector();

                        if (!prop) //not Right hand? try left
                        {
                            prop = chrGetEquippedWeaponPropWithCheck(chr1, GUNLEFT);
                        }

                        if (prop) //hopefully have gun else exit
                        {
                            vec.x = chr2->prop->pos.x - chr1->prop->pos.x;
                            vec.y = chr2->prop->pos.y - chr1->prop->pos.y;
                            vec.z = chr2->prop->pos.z - chr1->prop->pos.z;
                            guNormalize(&vec.x, &vec.y, &vec.z);
                            if (prop)
                            {
                            } //prop needs upgrading to v1 instead of t
                            weapon = prop->weapon;
                            handles_shot_actors(chr2, (s8)ai->val[2], &vec, weapon->weaponnum, 0);
                        }
                    }
                    Offset += AI_ChrHitChr_LENGTH;
                    break;
                }
                case AI_TRYThrowingGrenade:
                {
                    AIRecord1 *ai = AiListp + Offset;

                    if (actor_draws_throws_grenade_at_player_if_possible(ChrEntityp))
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val);
                    }
                    else
                    {
                        Offset += AI_TRYThrowingGrenade_LENGTH;
                    }
                    break;
                }
                case AI_TRYDroppingItem:
                {
                    AIRecord *ai       = AiListp + Offset;
                    u16       modelnum = CharArrayTo16(ai->val,0);
                    if (chrDropItem(ChrEntityp, modelnum, ai->val[2]))
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[3]);
                    }
                    else
                    {
                        Offset += AI_TRYDroppingItem_LENGTH;
                    }
                    break;
                }

                case AI_Surrender:
                {
                    chrTrySurrender(ChrEntityp);
                    Offset += AI_Surrender_LENGTH;
                    break;
                }
                case AI_RemoveMe:
                {
                    chrFadeOut(ChrEntityp);
                    Offset += AI_RemoveMe_LENGTH;
                    break;
                }
                case AI_ChrRemoveInstant:
                {
                    AIRecord  *ai  = AiListp + Offset;
                    ChrRecord *chr = chrFindById(ChrEntityp, ai->val[0]);
                    if (chr && chr->prop)
                    {
                        chr->hidden |= CHRHIDDEN_REMOVE;
                    }
                    Offset += AI_ChrRemoveInstant_LENGTH;
                    break;
                }
                case AI_TRYTriggeringAlarmAtPad:
                {
                    AIRecord *ai     = AiListp + Offset;
                    u16       pad_id = CharArrayTo16(ai->val,0);
                    if (chrTryStartAlarm(ChrEntityp, pad_id))
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[2]);
                    }
                    else
                    {
                        Offset += AI_TRYTriggeringAlarmAtPad_LENGTH;
                    }
                    break;
                }
                case AI_AlarmOn:
                {
                    alarmActivate();
                    Offset += AI_AlarmOn_LENGTH;
                    break;
                }
                case AI_AlarmOff:
                {
                    alarmDeactivate();
                    Offset += AI_AlarmOff_LENGTH;
                    break;
                }
                case AI_TRYRunFromBond:
                { // run from bond
                    AIRecord1 *ai = AiListp + Offset;
                    if (removed_animation_routine_27(ChrEntityp))
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val);
                    }
                    else
                    {
                        Offset += AI_TRYRunFromBond_LENGTH;
                    }
                    break;
                }
                case AI_TRYRunToBond:
                {
                    AIRecord1 *ai = AiListp + Offset;
                    if (chrGoToBond(ChrEntityp, SPEED_RUN))
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val);
                    }
                    else
                    {
                        Offset += AI_TRYRunToBond_LENGTH;
                    }
                    break;
                }
                case AI_TRYWalkToBond:
                {
                    AIRecord *ai = AiListp + Offset;
                    if (chrGoToBond(ChrEntityp, SPEED_WALK))
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[0]);
                    }
                    else
                    {
                        Offset += AI_TRYWalkToBond_LENGTH;
                    }
                    break;
                }
                case AI_TRYSprintToBond:
                {
                    AIRecord *ai = AiListp + Offset;
                    if (chrGoToBond(ChrEntityp, SPEED_SPRINT))
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[0]);
                    }
                    else
                    {
                        Offset += AI_TRYSprintToBond_LENGTH;
                    }
                    break;
                }
                case AI_TRYFindCover:
                { //Find Cover
                    AIRecord *ai = AiListp + Offset;
                    if (removed_animation_routine_2B(ChrEntityp))
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[0]);
                    }
                    else
                    {
                        Offset += AI_TRYFindCover_LENGTH;
                    }
                    break;
                }
                case AI_TRYRunToChr:
                {
                    AIRecord *ai = AiListp + Offset;
                    if (chrGoToChr(ChrEntityp, ai->val[0], SPEED_RUN))
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[1]);
                    }
                    else
                    {
                        Offset += AI_TRYRunToChr_LENGTH;
                    }
                    break;
                }
                case AI_TRYWalkToChr:
                {
                    AIRecord *ai = AiListp + Offset;
                    if (chrGoToChr(ChrEntityp, ai->val[0], SPEED_WALK))
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[1]);
                    }
                    else
                    {
                        Offset += AI_TRYWalkToChr_LENGTH;
                    }
                    break;
                }
                case AI_TRYSprintToChr:
                {
                    AIRecord *ai = AiListp + Offset;

                    if (chrGoToChr(ChrEntityp, ai->val[0] & 0xff, SPEED_SPRINT)) // &0xff is here to increase t reg by 1
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[1]);
                    }
                    else
                    {
                        Offset += AI_TRYSprintToChr_LENGTH;
                    }
                    break;
                }

                case AI_SetNewRandom:
                {
                    ChrEntityp->random = randomGetNext();
                    Offset += AI_SetNewRandom_LENGTH;
                    break;
                }
                case AI_IFRandomLessThan:
                {
                    AIRecord *ai = AiListp + Offset;

                    if (ai->val[0] > ChrEntityp->random)
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[1]);
                    }
                    else
                    {
                        Offset += AI_IFRandomLessThan_LENGTH;
                    }
                    break;
                }
                case AI_IFRandomGreaterThan:
                {
                    AIRecord *ai = AiListp + Offset;
                    if (ai->val[0] < ChrEntityp->random)
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[1]);
                    }
                    else
                    {
                        Offset += AI_IFRandomGreaterThan_LENGTH;
                    }
                    break;
                }

                case AI_RunToPad:
                {
                    AIRecord *ai  = AiListp + Offset;
                    u16       pad = CharArrayTo16(ai->val,0);
                    chrGoToPad(ChrEntityp, pad, SPEED_RUN);
                    Offset += AI_RunToPad_LENGTH;
                    break;
                }
                case AI_RunToPadPreset:
                {
                    /* PD uses GoTo Pad (speed) which seems better
                    switch (ai->val[0]) 
                    { 
                        case SPEED_WALK: 
                            chrGoToPad(ChrEntityp, ChrEntityp->padpreset1, SPEED_WALK);
                            break;  
                        case SPEED_RUN: 
                            etc...
                     */
                    chrGoToPad(ChrEntityp, ChrEntityp->padpreset1, SPEED_RUN);
                    Offset += AI_RunToPadPreset_LENGTH;
                    break;
                }
                case AI_WalkToPad:
                {
                    AIRecord *ai  = AiListp + Offset;
                    u16       pad = CharArrayTo16(ai->val,0);
                    chrGoToPad(ChrEntityp, pad, SPEED_WALK);
                    Offset += AI_WalkToPad_LENGTH;
                    break;
                }
                case AI_SprintToPad:
                {
                    AIRecord *ai  = AiListp + Offset;
                    u16       pad = CharArrayTo16(ai->val,0);
                    chrGoToPad(ChrEntityp, pad, SPEED_SPRINT);
                    Offset += AI_SprintToPad_LENGTH;
                    break;
                }
                case AI_StartPatrol:
                {
                    AIRecord   *ai   = AiListp + Offset;
                    PathRecord *path = pathFindById(ai->val[0]);
                    if_actor_able_set_on_path(ChrEntityp, path);
                    Offset += AI_StartPatrol_LENGTH;
                    break;
                }
                case AI_IFICanHearAlarm: 
                {
                    AIRecord *ai = AiListp + Offset;
                    if (chrCanHearAlarm(ChrEntityp))
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[0]);
                    }
                    else
                    {
                        Offset += AI_IFICanHearAlarm_LENGTH;
                    }
                    break;
                }
                case AI_IFAlarmIsOn:
                {
                    AIRecord *ai = AiListp + Offset;
                    if (alarmIsActive())
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[0]);
                    }
                    else
                    {
                        Offset += AI_IFAlarmIsOn_LENGTH;
                    }
                    break;
                }
                case AI_IFGasIsLeaking:
                {
                    AIRecord *ai = AiListp + Offset;
                    if (check_if_toxic_gas_activated())
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[0]);
                    }
                    else
                    {
                        Offset += AI_IFGasIsLeaking_LENGTH;
                    }
                    break;
                }
                case AI_IFIHeardBond:
                {
                    AIRecord *ai = AiListp + Offset;
                    if (chrIsHearingBond(ChrEntityp))
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[0]);
                    }
                    else
                    {
                        Offset += AI_IFIHeardBond_LENGTH;
                    }
                    break;
                }
                case AI_IFISeeSomeoneShot:
                {
                    AIRecord *ai = AiListp + Offset;
                    if (chrSawInjury(ChrEntityp))
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[0]);
                    }
                    else
                    {
                        Offset += AI_IFISeeSomeoneShot_LENGTH;
                    }
                    break;
                }
                case AI_IFISeeSomeoneDie:
                {
                    AIRecord *ai = AiListp + Offset;
                    if (chrSawDeath(ChrEntityp))
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[0]);
                    }
                    else
                    {
                        Offset += AI_IFISeeSomeoneDie_LENGTH;
                    }
                    break;
                }
                case AI_IFICouldSeeBond:
                {
                    AIRecord *ai = AiListp + Offset;
                    if (chrCanSeeBond(ChrEntityp))
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[0]);
                    }
                    else
                    {
                        Offset += AI_IFICouldSeeBond_LENGTH;
                    }
                    break;
                }
                case AI_IFICouldSeeBondsStan:
                {
                    AIRecord *ai = AiListp + Offset;
                    if (chrIsTargetNearlyInSight(ChrEntityp))
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[0]);
                    }
                    else
                    {
                        Offset += AI_IFICouldSeeBondsStan_LENGTH;
                    }
                    break;
                }
                case AI_IFIWasShotRecently:
                {
                    AIRecord *ai = AiListp + Offset;
                    if (chrSawTargetRecently(ChrEntityp))
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[0]);
                    }
                    else
                    {
                        Offset += AI_IFIWasShotRecently_LENGTH;
                    }
                    break;
                }
                case AI_IFIHeardBondRecently:
                {
                    AIRecord *ai = AiListp + Offset;
                    if (chrHeardTargetRecently(ChrEntityp))
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[0]);
                    }
                    else
                    {
                        Offset += AI_IFIHeardBondRecently_LENGTH;
                    }
                    break;
                }
                case AI_IFImInRoomWithChr:
                {
                    AIRecord  *ai  = AiListp + Offset;
                    ChrRecord *chr = chrFindById(ChrEntityp, *ai->val);
                    if (chr && chr->prop && check_if_position_in_same_room(ChrEntityp, &chr->prop->pos, chr->prop->stan))
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[1]);
                    }
                    else
                    {
                        Offset += AI_IFImInRoomWithChr_LENGTH;
                    }
                    break;
                }
                case AI_IFIveNotBeenSeen:
                {
                    AIRecord *ai = AiListp + Offset;
                    if (!(ChrEntityp->chrflags & CHRFLAG_HAS_BEEN_ON_SCREEN))
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[0]);
                    }
                    else
                    {
                        Offset += AI_IFIveNotBeenSeen_LENGTH;
                    }
                    break;
                }
                case AI_IFImOnScreen:
                {
                    AIRecord *ai = AiListp + Offset;
                    if ((ChrEntityp->prop->flags & PROPFLAG_ONSCREEN))
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[0]);
                    }
                    else
                    {
                        Offset += AI_IFImOnScreen_LENGTH;
                    }
                    break;
                }
                case AI_IFMyRoomIsOnScreen:
                {
                    AIRecord *ai = AiListp + Offset;
 
                    if (getROOMID_Bitflags(getTileRoom(ChrEntityp->prop->stan))) //embedded func to match, must be s32 not u8
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[0]);
                    }
                    else
                    {
                        Offset += AI_IFMyRoomIsOnScreen_LENGTH;
                    }
                    break;
                }
                case AI_IFRoomWithPadIsOnScreen:
                {
                    AIRecord *ai     = AiListp + Offset;
                    u16       pad_id = CharArrayTo16(ai->val,0);
                    if (check_if_room_for_preset_loaded(ChrEntityp, pad_id))
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[2]);
                    }
                    else
                    {
                        Offset += AI_IFRoomWithPadIsOnScreen_LENGTH;
                    }
                    break;
                }
                case AI_IFImTargetedByBond:
                {
                    AIRecord *ai = AiListp + Offset;
                    if (sub_GAME_7F0333F8(ChrEntityp))
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[0]);
                    }
                    else
                    {
                        Offset += AI_IFImTargetedByBond_LENGTH;
                    }
                    break;
                }
                case AI_IFBondMissedMe:
                {
                    AIRecord *ai = AiListp + Offset;
                    if (chrIfNearMiss(ChrEntityp))
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[0]);
                    }
                    else
                    {
                        Offset += AI_IFBondMissedMe_LENGTH;
                    }
                    break;
                }
                case AI_IFMyAngleToBondLessThan:
                {
                    // Alternative Names?
                    // aiIfTargetInFovLeft or aiIfBondOutOfFov
                    AIRecord *ai  = AiListp + Offset;
                    float     rad = chrGetAngleToBond(ChrEntityp); //must use float to save "hidden var"
                    if (ByteToRadian((ai->val[0])) > rad)
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[1]);
                    }
                    else
                    {
                        Offset += AI_IFMyAngleToBondLessThan_LENGTH;
                    }
                    break;
                }
                case AI_IFMyAngleToBondGreaterThan:
                {
                    AIRecord *ai  = AiListp + Offset;
                    float     rad = chrGetAngleToBond(ChrEntityp);
                    if (ByteToRadian((ai->val[0])) < rad)
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[1]);
                    }
                    else
                    {
                        Offset += AI_IFMyAngleToBondGreaterThan_LENGTH;
                    }
                    break;
                }
                case AI_IFMyAngleFromBondLessThan:
                {
                    AIRecord *ai  = AiListp + Offset;
                    float     rad = chrGetAngleFromBond(ChrEntityp);
                    if (ByteToRadian((ai->val[0])) > rad)
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[1]);
                    }
                    else
                    {
                        Offset += AI_IFMyAngleFromBondLessThan_LENGTH;
                    }
                    break;
                }
                case AI_IFMyAngleFromBondGreaterThan:
                {
                    AIRecord *ai  = AiListp + Offset;
                    float     rad = chrGetAngleFromBond(ChrEntityp);
                    if (ByteToRadian((ai->val[0])) < rad)
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[1]);
                    }
                    else
                    {
                        Offset += AI_IFMyAngleFromBondGreaterThan_LENGTH;
                    }
                    break;
                }
                case AI_IFMyDistanceToBondLessThanDecimeter:
                {
                    AIRecord *ai       = AiListp + Offset;
                    f32       distance = CharArrayTo16(ai->val,0) * 10.0f;
                    if (distance > chrGetDistanceToBond(ChrEntityp))
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[2]);
                    }
                    else
                    {
                        Offset += AI_IFMyDistanceToBondLessThanDecimeter_LENGTH;
                    }
                    break;
                }
                case AI_IFMyDistanceToBondGreaterThanDecimeter:
                {
                    AIRecord *ai       = AiListp + Offset;
                    f32       distance = CharArrayTo16(ai->val,0) * 10.0f;
                    if (distance < chrGetDistanceToBond(ChrEntityp))
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[2]);
                    }
                    else
                    {
                        Offset += AI_IFMyDistanceToBondGreaterThanDecimeter_LENGTH;
                    }
                    break;
                }
                case AI_IFChrDistanceToPadLessThanDecimeter:
                {
                    AIRecord  *ai     = AiListp + Offset;
                    ChrRecord *chr    = chrFindById(ChrEntityp, ai->val[0]);
                    u16        padnum = CharArrayTo16(ai->val,3);
                    f32        value  = CharArrayTo16(ai->val,1) * 10.0f;
                    if (chr && (value > chrGetDistanceToPad(chr, padnum)))
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[5]);
                    }
                    else
                    {
                        Offset += AI_IFChrDistanceToPadLessThanDecimeter_LENGTH;
                    }
                    break;
                }
                case AI_IFChrDistanceToPadGreaterThanDecimeter:
                {
                    AIRecord  *ai     = AiListp + Offset;
                    ChrRecord *chr    = chrFindById(ChrEntityp, ai->val[0]);
                    u16        padnum = CharArrayTo16(ai->val,3);
                    f32        value  = CharArrayTo16(ai->val,1) * 10.0f;
                    if (chr && (value < chrGetDistanceToPad(chr, padnum)))
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[5]);
                    }
                    else
                    {
                        Offset += AI_IFChrDistanceToPadGreaterThanDecimeter_LENGTH;
                    }
                    break;
                }
                case AI_IFMyDistanceToChrLessThanDecimeter:
                {
                    AIRecord *ai     = AiListp + Offset;
                    f32       cutoff = CharArrayTo16(ai->val,0) * 10.0f;
                    if (cutoff > chrGetDistanceToChr(ChrEntityp, ai->val[2]))
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[3]);
                    }
                    else
                    {
                        Offset += AI_IFMyDistanceToChrLessThanDecimeter_LENGTH;
                    }
                    break;
                }
                case AI_IFMyDistanceToChrGreaterThanDecimeter:
                {
                    AIRecord *ai     = AiListp + Offset;
                    f32       cutoff = CharArrayTo16(ai->val,0) * 10.0f;
                    if (cutoff < chrGetDistanceToChr(ChrEntityp, ai->val[2]))
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[3]);
                    }
                    else
                    {
                        Offset += AI_IFMyDistanceToChrGreaterThanDecimeter_LENGTH;
                    }
                    break;
                }
                case AI_TRYSettingMyPresetToChrWithinDistanceDecimeter:
                {
                    AIRecord *ai       = AiListp + Offset;
                    f32       distance = CharArrayTo16(ai->val,0) * 10.0f;
                    if (sub_GAME_7F033B38(ChrEntityp, distance))
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[2]);
                    }
                    else
                    {
                        Offset += AI_TRYSettingMyPresetToChrWithinDistanceDecimeter_LENGTH;
                    }
                    break;
                }
                case AI_IFBondDistanceToPadLessThanDecimeter:
                {
                    AIRecord *ai    = AiListp + Offset;
                    u16       pad   = CharArrayTo16(ai->val,2);
                    f32       value = CharArrayTo16(ai->val,0) * 10.0f;
                    if (value > chrGetDistanceFromBondToPad(ChrEntityp, pad))
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[4]);
                    }
                    else
                    {
                        Offset += AI_IFBondDistanceToPadLessThanDecimeter_LENGTH;
                    }
                    break;
                }
                case AI_IFBondDistanceToPadGreaterThanDecimeter:
                {
                    AIRecord *ai    = AiListp + Offset;
                    u16       pad   = CharArrayTo16(ai->val,2);
                    f32       value = CharArrayTo16(ai->val,0) * 10.0f;
                    if (value < chrGetDistanceFromBondToPad(ChrEntityp, pad))
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[4]);
                    }
                    else
                    {
                        Offset += AI_IFBondDistanceToPadGreaterThanDecimeter_LENGTH;
                    }
                    break;
                }
                case AI_IFChrInRoomWithPad:
                {
                    AIRecord *ai     = AiListp + Offset;
                    u16       pad_id = CharArrayTo16(ai->val,1);
                    if (chrIfInPadRoom(ChrEntityp, ai->val[0], pad_id))
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[3]);
                    }
                    else
                    {
                        Offset += AI_IFChrInRoomWithPad_LENGTH;
                    }
                    break;
                }
                case AI_IFBondInRoomWithPad:
                {
                    AIRecord *ai     = AiListp + Offset;
                    u16       pad_id = CharArrayTo16(ai->val,0);
                    if (check_if_actor_is_at_preset(ChrEntityp, pad_id))
                    {
#ifdef ENABLE_LOG
                        osSyncPrintf("BOND IN ROOM\n");
#endif
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[2]);
                    }
                    else
                    {
#ifdef DEBUG
                        osSyncPrintf("bond not in room\n");
#endif
                        Offset += AI_IFBondInRoomWithPad_LENGTH;
                    }
                    break;
                }
                case AI_IFBondCollectedObject:
                {
                    AIRecord     *ai  = AiListp + Offset;
                    ObjectRecord *obj = objFindByTagId(ai->val[0]);
                    if (obj && obj->prop && bondinvHasPropInInv(obj->prop))
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[1]);
                    }
                    else
                    {
                        Offset += AI_IFBondCollectedObject_LENGTH;
                    }
                    break;
                }
                case AI_IFItemIsStationaryWithinLevel:
                {
                    AIRecord *ai = AiListp + Offset;
                    if (weaponFindThrown(ai->val[0]))
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[1]);
                    }
                    else
                    {
                        Offset += AI_IFItemIsStationaryWithinLevel_LENGTH;
                    }
                    break;
                }
                case AI_IFItemIsAttachedToObject:
                {
                    struct
                    {
                        u8 cmd;
                        u8 val;
                        u8 val1;
                        u8 val2;
                    } *ai              = AiListp + Offset;
                    ObjectRecord *obj  = objFindByTagId(ai->val1);
                    bool          pass = FALSE;
                    if (obj && obj->prop)
                    {
                        PropRecord *prop = obj->prop->child;
                        while (prop)
                        {
                            if (prop->type == PROP_TYPE_WEAPON)
                            {
                                WeaponObjRecord *weapon = prop->weapon;
                                if (weapon->weaponnum == ai->val)
                                {
                                    pass = TRUE;
                                    break;
                                }
                            }
                            prop = prop->prev;
                        }
                    }
                    if (pass)
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val2);
                    }
                    else
                    {
                        Offset += AI_IFItemIsAttachedToObject_LENGTH;
                    }
                    break;
                }
                case AI_IFBondHasItemEquipped:
                {
                    AIRecord *ai = AiListp + Offset;
                    if (ai->val[0] == getCurrentPlayerWeaponId(GUNRIGHT) || ai->val[0] == getCurrentPlayerWeaponId(GUNLEFT)) //order matters
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[1]);
                    }
                    else
                    {
                        Offset += AI_IFBondHasItemEquipped_LENGTH;
                    }
                    break;
                }
                case AI_IFObjectExists:
                {
                    AIRecord     *ai  = AiListp + Offset;
                    ObjectRecord *obj = objFindByTagId(ai->val[0]);
                    if (obj && obj->prop)
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[1]);
                    }
                    else
                    {
                        Offset += AI_IFObjectExists_LENGTH;
                    }
                    break;
                }
                case AI_IFObjectNotDestroyed:
                {
                    AIRecord     *ai  = AiListp + Offset;
                    ObjectRecord *obj = objFindByTagId(ai->val[0]);
                    if (obj && obj->prop && objIsHealthy(obj))
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[1]);
                    }
                    else
                    {
                        Offset += AI_IFObjectNotDestroyed_LENGTH;
                    }
                    break;
                }
                case AI_IFObjectWasActivated:
                {
                    AIRecord     *ai  = AiListp + Offset;
                    ObjectRecord *obj = objFindByTagId(ai->val[0]);
                    if (obj && obj->prop && (obj->runtime_bitflags & RUNTIMEBITFLAG_ACTIVATED))
                    {
                        obj->runtime_bitflags &= ~RUNTIMEBITFLAG_ACTIVATED;
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[1]);
                    }
                    else
                    {
                        Offset += AI_IFObjectWasActivated_LENGTH;
                    }
                    break;
                }
                case AI_IFBondUsedGadgetOnObject:
                {
                    AIRecord     *ai  = AiListp + Offset;
                    ObjectRecord *obj = objFindByTagId(ai->val[0]);
                    if (obj && obj->prop && (obj->state & PROPSTATE_ACTIVATED))
                    {
                        obj->state &= ~PROPSTATE_ACTIVATED;
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[1]);
                    }
                    else
                    {
                        Offset += AI_IFBondUsedGadgetOnObject_LENGTH;
                    }
                    break;
                }
                case AI_ActivateObject:
                {
                    AIRecord     *ai  = AiListp + Offset;
                    ObjectRecord *obj = objFindByTagId(ai->val[0]);
                    if (obj && obj->prop)
                    {
                        if (obj->prop->type == PROP_TYPE_DOOR)
                        {
                            doorActivateWrapper(obj->prop);
                        }
                        else if (obj->prop->type == PROP_TYPE_OBJ || obj->prop->type == PROP_TYPE_WEAPON)
                        {
                            propobjInteract(obj->prop);
                        }
                    }
                    Offset += AI_ActivateObject_LENGTH;
                    break;
                }
                case AI_DestroyObject: //canonicly destroyobj
                {
                    AIRecord     *ai  = AiListp + Offset;
                    ObjectRecord *obj = objFindByTagId(ai->val[0]);
#ifdef ENABLE_LOG
                    osSyncPrintf("ai_destroyobj 1 : \n");
#endif
                    if (obj && obj->prop)
                    {
                        if (!objGetDestroyedLevel(obj))
                        {
                            f32 damage = ((obj->damage - obj->maxdamage) + 1) / 250.0f;
#ifdef ENABLE_LOG
                            osSyncPrintf("ai_destroyobj 3 : adddamageobj\n");
#endif

                            maybe_detonate_object(obj, damage, &obj->runtime_pos, 0x1D, -1);
                        }
                    }
                    Offset += AI_DestroyObject_LENGTH;
                    break;
                }
                case AI_DropObject:
                {
                    AIRecord     *ai  = AiListp + Offset;
                    ObjectRecord *obj = objFindByTagId(ai->val[0]);
                    if (obj && obj->prop && obj->prop->parent && obj->prop->parent->type == PROP_TYPE_CHR)
                    {
                        ChrRecord *chr = obj->prop->parent->chr;
                        propobjSetDropped(obj->prop, 2);
                        chr->hidden |= CHRHIDDEN_DROP_HELD_ITEMS;
                    }
                    Offset += AI_DropObject_LENGTH;
                    break;
                }
                case AI_ChrDropAllConcealedItems:
                {
                    AIRecord  *ai  = AiListp + Offset;
                    ChrRecord *chr = chrFindById(ChrEntityp, ai->val[0]);
                    if (chr && chr->prop)
                    {
                        chrDropItems(chr);
                    }
                    Offset += AI_ChrDropAllConcealedItems_LENGTH;
                    break;
                }
                case AI_ChrDropAllHeldItems:
                {
                    AIRecord  *ai  = AiListp + Offset;
                    ChrRecord *chr = chrFindById(ChrEntityp, ai->val[0]);
                    if (chr && chr->prop)
                    {
                        if (chr->weapons_held[GUNRIGHT])
                        {
                            propobjSetDropped(chr->weapons_held[GUNRIGHT], 1);
                            chr->hidden |= CHRHIDDEN_DROP_HELD_ITEMS;
                        }
                        if (chr->weapons_held[GUNLEFT])
                        {
                            propobjSetDropped(chr->weapons_held[GUNLEFT], 1);
                            chr->hidden |= CHRHIDDEN_DROP_HELD_ITEMS;
                        }
                    }
                    Offset += AI_ChrDropAllHeldItems_LENGTH;
                    break;
                }
                case AI_BondCollectObject:
                {
                    AIRecord     *ai  = AiListp + Offset;
                    ObjectRecord *obj = objFindByTagId(ai->val[0]);
                    if (obj && obj->prop)
                    {
                        INV_ITEM_TYPE iType = collect_or_interact_object(obj->prop, FALSE);
                        propExecuteTickOperation(obj->prop, iType);
                    }
                    Offset += AI_BondCollectObject_LENGTH;
                    break;
                }
                case AI_ChrEquipObject:
                {
                    AIRecord     *ai  = AiListp + Offset;
                    ObjectRecord *obj = objFindByTagId(ai->val[0]);
                    ChrRecord    *chr = chrFindById(ChrEntityp, ai->val[1]);
                    if (obj && obj->prop && chr)
                    {
                        if (obj->prop->parent)
                        {
                            objDetach(obj->prop);
                        }
                        else
                        {
                            chrpropDeregisterRooms(obj->prop);
                            chrpropDelist(obj->prop);
                            chrpropDisable(obj->prop);
                        }
                        if (obj->type != PROPDEF_COLLECTABLE || !chrEquipWeapon(obj, chr))
                        {
                            chrpropReparent(obj->prop, chr->prop);
                        }
                    }
                    Offset += AI_ChrEquipObject_LENGTH;
                    break;
                }
                case AI_MoveObject: //canonicly aiMoveObj
                {
                    AIRecord           *ai  = AiListp + Offset;
                    ObjectRecord       *obj = objFindByTagId(ai->val[0]);
                    volatile PadRecord *pad;
                    u16                 padnum = CharArrayTo16(ai->val,1);
                    Mtxf                matrix;

                    if (obj && obj->prop)
                    {
                        if (isNotBoundPad(padnum))
                        {
                            pad = &g_CurrentSetup.pads[padnum];
                        }
                        else
                        {
                            pad = (PadRecord *)&g_CurrentSetup.boundpads[getBoundPadNum(padnum)];
                        }
#ifdef ENABLE_LOG
                            osSyncPrintf("aiMoveObj: moving object to pad %d\n", pad);
#endif
                        matrix_4x4_7F059908(&matrix, 0, 0, 0, -pad->look.x, -pad->look.y, -pad->look.z, pad->up.x, pad->up.y, pad->up.z);
                        if (obj->model)
                        {
                            matrix_scalar_multiply(obj->model->scale, &matrix);
                        }
                        sub_GAME_7F04088C(obj, pad, &matrix, pad->stan, pad);
                        setupUpdateObjectRoomPosition(obj);
                    }
                    Offset += AI_MoveObject_LENGTH;
                    break;
                }
                case AI_DoorOpen:
                {
                    AIRecord   *ai  = AiListp + Offset;
                    DoorRecord *obj = objFindByTagId(ai->val[0]);
                    if (obj && obj->prop && obj->prop->type == PROP_TYPE_DOOR)
                    {
                        // DoorRecord *door = (DoorRecord *)obj;
                        doorActivate(obj, DOORSTATE_OPENING);
                    }
                    Offset += AI_DoorOpen_LENGTH;
                    break;
                }
                case AI_DoorClose:
                {
                    AIRecord   *ai  = AiListp + Offset;
                    DoorRecord *obj = objFindByTagId(ai->val[0]);
                    if (obj && obj->prop && obj->prop->type == PROP_TYPE_DOOR)
                    {
                        //DoorRecord *door = (DoorRecord *)obj;
                        doorActivate(obj, DOORSTATE_CLOSING);
                    }
                    Offset += AI_DoorClose_LENGTH;
                    break;
                }
                case AI_IFDoorStateEqual:
                {
                    AIRecord     *ai   = AiListp + Offset;
                    ObjectRecord *obj  = objFindByTagId(ai->val[0]);
                    bool          pass = FALSE;
                    if (obj && obj->prop && obj->type == PROPDEF_DOOR)
                    {
                        DoorRecord *door = (DoorRecord *)obj;
                        if (door->openstate == DOORSTATE_STATIONARY)
                        {
                            if (door->openPosition <= 0)
                            {
                                pass = (ai->val[1] & DOOR_STATE_CLOSED) != 0;
                            }
                            else
                            {
                                pass = (ai->val[1] & DOOR_STATE_OPEN) != 0;
                            }
                        }
                        else if (door->openstate == DOORSTATE_OPENING || door->openstate == DOORSTATE_WAITING)
                        {
                            pass = (ai->val[1] & DOOR_STATE_OPENING) != 0;
                        }
                        else if (door->openstate == DOORSTATE_CLOSING)
                        {
                            pass = (ai->val[1] & DOOR_STATE_CLOSING) != 0;
                        }
                    }
                    if (pass)
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[2]);
                    }
                    else
                    {
                        Offset += AI_IFDoorStateEqual_LENGTH;
                    }
                    break;
                }
                case AI_IFDoorHasBeenOpenedBefore:
                {
                    AIRecord     *ai  = AiListp + Offset;
                    ObjectRecord *obj = objFindByTagId(ai->val[0]);
                    if (obj && obj->prop && obj->type == PROPDEF_DOOR && (obj->runtime_bitflags & RUNTIMEBITFLAG_BEENOPENED))
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[1]);
                    }
                    else
                    {
                        Offset += AI_IFDoorHasBeenOpenedBefore_LENGTH;
                    }
                    break;
                }
                case AI_DoorSetLock:
                {
                    AIRecord     *ai  = AiListp + Offset;
                    ObjectRecord *obj = objFindByTagId(ai->val[0]);
                    if (obj && obj->prop && obj->prop->type == PROP_TYPE_DOOR)
                    {
                        DoorRecord *door = (DoorRecord *)obj;
                        u8          bits = ai->val[1];
                        door->keyflags   = door->keyflags | bits;
                    }
                    Offset += AI_DoorSetLock_LENGTH;
                    break;
                }
                case AI_DoorUnsetLock:
                {
                    AIRecord     *ai  = AiListp + Offset;
                    ObjectRecord *obj = objFindByTagId(ai->val[0]);
                    if (obj && obj->prop && obj->prop->type == PROP_TYPE_DOOR)
                    {
                        DoorRecord *door = (DoorRecord *)obj;
                        u8          bits = ai->val[1];
                        door->keyflags &= ~bits;
                    }
                    Offset += AI_DoorUnsetLock_LENGTH;
                    break;
                }
                case AI_IFDoorLockEqual:
                {
                    AIRecord     *ai   = AiListp + Offset;
                    ObjectRecord *obj  = objFindByTagId(ai->val[0]);
                    bool          pass = FALSE;
                    if (obj && obj->prop && obj->prop->type == PROP_TYPE_DOOR)
                    {
                        DoorRecord *door = (DoorRecord *)obj;
                        s32         bits = ai->val[1];
                        if ((door->keyflags & bits) == bits)
                        {
                            pass = TRUE;
                        }
                    }
                    if (pass)
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[2]);
                    }
                    else
                    {
                        Offset += AI_IFDoorLockEqual_LENGTH;
                    }
                    break;
                }
                case AI_IFObjectiveNumComplete:
                {
                    struct
                    {
                        u8 cmd;
                        u8 val;
                        u8 label;
                    } *ai = AiListp + Offset;
                    /*  additional PD code for dificulty filtering 
                     == OBJECTIVE_COMPLETE && objectivelvlGetSelectedDifficultyBits(ai->val[0]) & (1 << lvlGetSelectedDifficulty()))  *
                    */
                    if (objectiveGetCount() > ai->val && OBJECTIVESTATUS_COMPLETE == objectiveGetStatus_WEAK(ai->val * 1, ai->val )) 
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->label);
                    }
                    else
                    {
                        Offset += AI_IFObjectiveNumComplete_LENGTH;
                    }
                    break;
                }
                case AI_TRYUnknown6e:
                {
                    AIRecord *ai = AiListp + Offset;
                    if (check_2328_preset_set_with_method(ChrEntityp, ai->val[0]))
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[1]);
                    }
                    else
                    {
                        Offset += AI_TRYUnknown6e_LENGTH;
                    }
                    break;
                }
                case AI_TRYUnknown6f:
                {
                    AIRecord *ai = AiListp + Offset;
                    if (sub_GAME_7F033AAC(ChrEntityp, ai->val[0]))
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[1]);
                    }
                    else
                    {
                        Offset += AI_TRYUnknown6f_LENGTH;
                    }
                    break;
                }

                case AI_IFMyNumArghsLessThan:
                {
                    AIRecord *ai = AiListp + Offset;
                    if (ai->val[0] > chrGetNumArghs(ChrEntityp)) //order matter
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[1]);
                    }
                    else
                    {
                        Offset += AI_IFMyNumArghsLessThan_LENGTH;
                    }
                    break;
                }
                case AI_IFMyNumArghsGreaterThan:
                {
                    AIRecord *ai = AiListp + Offset;
                    if (ai->val[0] < chrGetNumArghs(ChrEntityp)) //order matter
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[1]);
                    }
                    else
                    {
                        Offset += AI_IFMyNumArghsGreaterThan_LENGTH;
                    }
                    break;
                }
                case AI_IFMyNumCloseArghsLessThan:
                {
                    AIRecord *ai = AiListp + Offset;
                    if (ai->val[0] > chrGetNumCloseArghs(ChrEntityp))
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[1]);
                    }
                    else
                    {
                        Offset += AI_IFMyNumCloseArghsLessThan_LENGTH;
                    }
                    break;
                }
                case AI_IFMyNumCloseArghsGreaterThan:
                {
                    AIRecord *ai = AiListp + Offset;
                    if (ai->val[0] < chrGetNumCloseArghs(ChrEntityp))
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[1]);
                    }
                    else
                    {
                        Offset += AI_IFMyNumCloseArghsGreaterThan_LENGTH;
                    }
                    break;
                }
                case AI_IFChrHealthLessThan:
                {
                    AIRecord  *ai    = AiListp + Offset;
                    f32        value = (ai->val[1]) * 0.1f;
                    ChrRecord *chr   = chrFindById(ChrEntityp, ai->val[0]);

                    if (chr && ((chr->maxdamage - chr->damage) < value))
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[2]);
                    }
                    else
                    {
                        Offset += AI_IFChrHealthLessThan_LENGTH;
                    }
                    break;
                }
                case AI_IFChrHealthGreaterThan:
                {
                    AIRecord  *ai    = AiListp + Offset;
                    f32        value = (ai->val[1]) * 0.1f;
                    ChrRecord *chr   = chrFindById(ChrEntityp, ai->val[0]);

                    if (chr && ((chr->maxdamage - chr->damage) > value))
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[2]);
                    }
                    else
                    {
                        Offset += AI_IFChrHealthGreaterThan_LENGTH;
                    }
                    break;
                }
                case AI_IFChrWasDamagedSinceLastCheck:
                {
                    AIRecord  *ai  = AiListp + Offset;
                    ChrRecord *chr = chrFindById(ChrEntityp, ai->val[0]);
                    if (chr && (chr->chrflags & CHRFLAG_WAS_DAMAGED))
                    {
                        chr->chrflags &= ~CHRFLAG_WAS_DAMAGED; // disable flag
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[1]);
                    }
                    else
                    {
                        Offset += AI_IFChrWasDamagedSinceLastCheck_LENGTH;
                    }
                    break;
                }
                case AI_IFBondHealthLessThan:
                {
                    AIRecord *ai  = AiListp + Offset;
                    float     val = (ai->val[0]) / 255.0f;
                    if (val > bondviewGetCurrentPlayerHealth())
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[1]);
                    }
                    else
                    {
                        Offset += AI_IFBondHealthLessThan_LENGTH;
                    }
                    break;
                }
                case AI_IFBondHealthGreaterThan:
                {
                    AIRecord *ai  = AiListp + Offset;
                    float     val = (ai->val[0]) / 255.0f;
                    if (val < bondviewGetCurrentPlayerHealth())
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[1]);
                    }
                    else
                    {
                        Offset += AI_IFBondHealthGreaterThan_LENGTH;
                    }
                    break;
                }
                case AI_IFGameDifficultyLessThan:
                {
                    AIRecord *ai = AiListp + Offset;
                    if (ai->val[0] > lvlGetSelectedDifficulty())
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[1]);
                    }
                    else
                    {
                        Offset += AI_IFGameDifficultyLessThan_LENGTH;
                    }
                    break;
                }
                case AI_IFGameDifficultyGreaterThan:
                {
                    AIRecord *ai = AiListp + Offset;
                    if (ai->val[0] < lvlGetSelectedDifficulty())
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[1]);
                    }
                    else
                    {
                        Offset += AI_IFGameDifficultyGreaterThan_LENGTH;
                    }
                    break;
                }
                case AI_IFMissionTimeLessThan:
                {
                    AIRecord *ai     = AiListp + Offset;
                    f32       target = CharArrayTo16(ai->val,0);
                    if (target > lvlGetCurrentMultiPlayerSec())
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[2]);
                    }
                    else
                    {
                        Offset += AI_IFMissionTimeLessThan_LENGTH;
                    }
                    break;
                }
                case AI_IFMissionTimeGreaterThan:
                {
                    AIRecord *ai     = AiListp + Offset;
                    f32       target = CharArrayTo16(ai->val,0);
                    if (target < lvlGetCurrentMultiPlayerSec())
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[2]);
                    }
                    else
                    {
                        Offset += AI_IFMissionTimeGreaterThan_LENGTH;
                    }
                    break;
                }
                case AI_IFSystemPowerTimeLessThan:
                {
                    AIRecord *ai     = AiListp + Offset;
                    f32       target = CharArrayTo16(ai->val,0) * CHRAI_TICKRATE_F;
                    if (target > lvlGetCurrentMultiPlayerMin())
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[2]);
                    }
                    else
                    {
                        Offset += AI_IFSystemPowerTimeLessThan_LENGTH;
                    }
                    break;
                }
                case AI_IFSystemPowerTimeGreaterThan:
                {
                    AIRecord *ai     = AiListp + Offset;
                    f32       target = CharArrayTo16(ai->val,0) * CHRAI_TICKRATE_F;
                    if (target < lvlGetCurrentMultiPlayerMin())
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[2]);
                    }
                    else
                    {
                        Offset += AI_IFSystemPowerTimeGreaterThan_LENGTH;
                    }
                    break;
                }
                case AI_IFLevelIdLessThan:
                {
                    AIRecord *ai = AiListp + Offset;
                    if (ai->val[0] > bossGetStageNum())
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[1]);
                    }
                    else
                    {
                        Offset += AI_IFLevelIdLessThan_LENGTH;
                    }
                    break;
                }
                case AI_IFLevelIdGreaterThan:
                {
                    AIRecord *ai = AiListp + Offset;
                    if (ai->val[0] < bossGetStageNum())
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[1]);
                    }
                    else
                    {
                        Offset += AI_IFLevelIdGreaterThan_LENGTH;
                    }
                    break;
                }
                case AI_SetMyMorale:
                {
                    AIRecord1 *ai      = AiListp + Offset;
                    ChrEntityp->morale = ai->val;
#ifdef ENABLE_LOG
                    osSyncPrintf("MORALE IS NOW %d \n",ChrEntityp->morale);
#endif
                    Offset += AI_SetMyMorale_LENGTH;
                    break;
                }
                case AI_AddToMyMorale:
                {
                    AIRecord1 *ai = AiListp + Offset;
                    if (255 - ai->val < ChrEntityp->morale) //clamp to 255
                    {
                        ChrEntityp->morale = 255; //max
                    }
                    else
                    {
                        ChrEntityp->morale += ai->val;
                    }
#ifdef ENABLE_LOG
                    osSyncPrintf("MORALE IS NOW %d \n",ChrEntityp->morale);
#endif

                    Offset += AI_AddToMyMorale_LENGTH;
                    break;
                }
                case AI_SubtractFromMyMorale:
                {
                    AIRecord1 *ai = AiListp + Offset;
                    if (ai->val > ChrEntityp->morale) //clamp to 0
                    {
                        ChrEntityp->morale = 0;
                    }
                    else
                    {
                        ChrEntityp->morale -= ai->val;
                    }
#ifdef ENABLE_LOG
                    osSyncPrintf("MORALE IS NOW %d \n", ChrEntityp->morale);
#endif
                    Offset += AI_SubtractFromMyMorale_LENGTH;
                    break;
                }
                case AI_IFMyMoraleLessThan:
                {
                    AIRecord *ai = AiListp + Offset;
                    if (ai->val[0] > ChrEntityp->morale)
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[1]);
                    }
                    else
                    {
                        Offset += AI_IFMyMoraleLessThan_LENGTH;
                    }
                    break;
                }
                case AI_IFMyMoraleLessThanRandom:
                {
                    AIRecord *ai = AiListp + Offset;
                    if (ChrEntityp->morale < ChrEntityp->random)
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[0]);
                    }
                    else
                    {
                        Offset += AI_IFMyMoraleLessThanRandom_LENGTH;
                    }
                    break;
                }
                case AI_SetMyAlertness:
                {
                    AIRecord1 *ai         = AiListp + Offset;
                    ChrEntityp->alertness = ai->val;
#ifdef ENABLE_LOG
                    osSyncPrintf("AI_PRINT(void) Alertness =  %d!\n", ChrEntityp->alertness);
#endif
                    Offset += AI_SetMyAlertness_LENGTH;
                    break;
                }
                case AI_AddToMyAlertness:
                {
                    AIRecord1 *ai = AiListp + Offset;
                    if (255 - ai->val < ChrEntityp->alertness) //clamp to 255
                    {
                        ChrEntityp->alertness = 255; //max
                    }
                    else
                    {
                        ChrEntityp->alertness += ai->val;
                    }
                    Offset += AI_AddToMyAlertness_LENGTH;
                    break;
                }
                case AI_SubtractFromMyAlertness:
                {
                    AIRecord1 *ai = AiListp + Offset;
                    if (ai->val > ChrEntityp->alertness) //clamp to 0
                    {
                        ChrEntityp->alertness = 0;
                    }
                    else
                    {
                        ChrEntityp->alertness -= ai->val;
                    }
                    Offset += AI_SubtractFromMyAlertness_LENGTH;
                    break;
                }
                case AI_IFMyAlertnessLessThan:
                {
                    AIRecord *ai = AiListp + Offset;
                    if (ai->val[0] > ChrEntityp->alertness)
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[1]);
                    }
                    else
                    {
                        Offset += AI_IFMyAlertnessLessThan_LENGTH;
                    }
                    break;
                }
                case AI_IFMyAlertnessLessThanRandom:
                {
                    AIRecord *ai = AiListp + Offset;
                    if (ChrEntityp->alertness < ChrEntityp->random)
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[0]);
                    }
                    else
                    {
                        Offset += AI_IFMyAlertnessLessThanRandom_LENGTH;
                    }
                    break;
                }
                case AI_SetMyHearingScale:
                {
                    AIRecord *ai             = AiListp + Offset;
                    f32       distance       = CharArrayTo16(ai->val,0) / 1000.0f;
                    ChrEntityp->hearingscale = distance;
                    Offset += AI_SetMyHearingScale_LENGTH;
                    break;
                }
                case AI_SetMyVisionRange:
                {
                    AIRecord *ai            = AiListp + Offset;
                    ChrEntityp->visionrange = (ai->val[0]);
                    Offset += AI_SetMyVisionRange_LENGTH;
                    break;
                }
                case AI_SetMyGrenadeProbability:
                {
                    AIRecord *ai            = AiListp + Offset;
                    ChrEntityp->grenadeprob = ai->val[0];
                    Offset += AI_SetMyGrenadeProbability_LENGTH;
                    break;
                }
                case AI_SetMyChrNum:
                {
                    AIRecord *ai       = AiListp + Offset;
                    ChrEntityp->chrnum = ai->val[0];
                    Offset += AI_SetMyChrNum_LENGTH;
                    break;
                }
                case AI_SetMyHealthTotal:
                {
                    AIRecord *ai     = AiListp + Offset;
                    f32       amount = CharArrayTo16(ai->val,0) * 0.1f;
                    chrSetMaxDamage(ChrEntityp, amount);
                    Offset += AI_SetMyHealthTotal_LENGTH;
                    break;
                }
                case AI_SetMyArmour:
                {
                    AIRecord *ai     = AiListp + Offset;
                    f32       amount = CharArrayTo16(ai->val,0) * 0.1f; /*if (cheatIsActive(CHEAT_ENEMYSHIELDS)) { amount = amount < 8 ? 8 : amount; } */
                    chrAddHealth(ChrEntityp, amount);
                    Offset += AI_SetMyArmour_LENGTH;
                    break;
                }
                case AI_SetMySpeedRating:
                {   AIRecord1s *ai = AiListp + Offset;
#ifdef DEBUG
                    /*
                        ".\\ported\\chrai.c", 2258, "Assertion failed: ai->val>=0"
                        ".\\ported\\chrai.c", 2259, "Assertion failed: ai->val<=100"
                     */
                    assert(ai->val >= 0);
                    assert(ai->val <= 100);
#endif
                    ChrEntityp->speedrating = ai->val;
                    Offset += AI_SetMySpeedRating_LENGTH;
                    break;
                }
                case AI_SetMyArghRating:
                {   AIRecord1s *ai = AiListp + Offset;
#ifdef DEBUG
                    /*
                        ".\\ported\\chrai.c", 2268, "Assertion failed: ai->val>=0"
                        ".\\ported\\chrai.c", 2269, "Assertion failed: ai->val<=100"
                    */
                    assert(ai->val >= 0);
                    assert(ai->val <= 100);
#endif
                    ChrEntityp->arghrating = ai->val;
                    Offset += AI_SetMyArghRating_LENGTH;
                    break;
                }
                case AI_SetMyAccuracyRating:
                {
                    struct
                    {
                        u8 cmd;
                        s8 val;
                    } *ai                      = AiListp + Offset;
                    ChrEntityp->accuracyrating = ai->val;
                    Offset += AI_SetMyAccuracyRating_LENGTH;
                    break;
                }
                case AI_SetMyFlags2:
                {
                    AIRecord *ai = AiListp + Offset;
                    chrSetFlags2(ChrEntityp, ai->val[0]);
                    Offset += AI_SetMyFlags2_LENGTH;
                    break;
                }
                case AI_UnsetMyFlags2:
                {
                    AIRecord *ai = AiListp + Offset;
                    chrUnsetFlags2(ChrEntityp, ai->val[0]);
                    Offset += AI_UnsetMyFlags2_LENGTH;
                    break;
                }
                case AI_IFMyFlags2Has:
                {
                    AIRecord *ai = AiListp + Offset;
                    if (chrHasFlags2(ChrEntityp, ai->val[0]))
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[1]);
                    }
                    else
                    {
                        Offset += AI_IFMyFlags2Has_LENGTH;
                    }
                    break;
                }
                case AI_SetChrBitfield:
                {
                    AIRecord *ai = AiListp + Offset;
                    chrSetFlags2ById(ChrEntityp, ai->val[0], ai->val[1]);
                    Offset += AI_SetChrBitfield_LENGTH;
                    break;
                }
                case AI_UnsetChrBitfield:
                {
                    AIRecord *ai = AiListp + Offset;
                    chrUnsetFlags2ById(ChrEntityp, ai->val[0], ai->val[1]);
                    Offset += AI_UnsetChrBitfield_LENGTH;
                    break;
                }
                case AI_IFChrBitfieldHas:
                {
                    AIRecord *ai = AiListp + Offset;
                    if (chrHasFlags2ById(ChrEntityp, ai->val[0], ai->val[1]))
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[2]);
                    }
                    else
                    {
                        Offset += AI_IFChrBitfieldHas_LENGTH;
                    }
                    break;
                }
                case AI_SetObjectiveBitfield:
                {
                    AIRecord *ai    = AiListp + Offset;
                    s32       flags = CharArrayTo32(ai->val,0);
                    chrSetStageFlags(ChrEntityp, flags);
                    Offset += AI_SetObjectiveBitfield_LENGTH;
                    break;
                }
                case AI_UnsetObjectiveBitfield:
                {
                    AIRecord *ai    = AiListp + Offset;
                    s32       flags = CharArrayTo32(ai->val,0);
                    chrUnsetStageFlags(ChrEntityp, flags);
                    Offset += AI_UnsetObjectiveBitfield_LENGTH;
                    break;
                }
                case AI_IFObjectiveBitfieldHas:
                {
                    AIRecord *ai    = AiListp + Offset;
                    s32       flags = CharArrayTo32(ai->val,0);
                    if (chrHasStageFlag(ChrEntityp, flags)) /* PD && ai->val[4] == 1) || (!chrHasStageFlag(ChrEntityp, flags) && ai->val[4] == 0  * */
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[4]);
                    }
                    else
                    {
                        Offset += AI_IFObjectiveBitfieldHas_LENGTH;
                    }
                    break;
                }
                case AI_SetMychrflags:
                {
                    AIRecord *ai    = AiListp + Offset;
                    CHRFLAG   flags = CharArrayTo32(ai->val,0);
                    ChrEntityp->chrflags |= flags;
                    Offset += AI_SetMychrflags_LENGTH;
                    break;
                }
                case AI_UnsetMychrflags:
                {
                    AIRecord *ai    = AiListp + Offset;
                    CHRFLAG   flags = CharArrayTo32(ai->val,0);
                    ChrEntityp->chrflags &= ~flags;
                    Offset += AI_UnsetMychrflags_LENGTH;
                    break;
                }
                case AI_IFMychrflagsHas:
                {
                    AIRecord *ai    = AiListp + Offset;
                    CHRFLAG   flags = CharArrayTo32(ai->val,0);
                    if ((ChrEntityp->chrflags & flags) == flags)
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[4]);
                    }
                    else
                    {
                        Offset += AI_IFMychrflagsHas_LENGTH;
                    }
                    break;
                }
                case AI_SetChrchrflags:
                {
                    AIRecord  *ai    = AiListp + Offset;
                    CHRFLAG    flags = CharArrayTo32(ai->val,1);
                    ChrRecord *chr   = chrFindById(ChrEntityp, ai->val[0]);
                    if (chr)
                    {
                        chr->chrflags |= flags;
                    }
                    Offset += AI_SetChrchrflags_LENGTH;
                    break;
                }
                case AI_UnsetChrchrflags:
                {
                    AIRecord  *ai    = AiListp + Offset;
                    CHRFLAG    flags = CharArrayTo32(ai->val,1);
                    ChrRecord *chr   = chrFindById(ChrEntityp, ai->val[0]);
                    if (chr)
                    {
                        chr->chrflags &= ~flags;
                    }
                    Offset += AI_UnsetChrchrflags_LENGTH;
                    break;
                }
                case AI_IFChrchrflagsHas:
                {
                    AIRecord  *ai    = AiListp + Offset;
                    CHRFLAG    flags = CharArrayTo32(ai->val,1);
                    ChrRecord *chr   = chrFindById(ChrEntityp, ai->val[0]);
                    if (chr && (chr->chrflags & flags) == flags)
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[5]);
                    }
                    else
                    {
                        Offset += AI_IFChrchrflagsHas_LENGTH;
                    }
                    break;
                }
                case AI_SetObjectFlags:
                {
                    AIRecord     *ai    = AiListp + Offset;
                    s32           flags = CharArrayTo32(ai->val,1);
                    ObjectRecord *obj   = objFindByTagId(ai->val[0]);
                    if (obj && obj->prop)
                    {
                        obj->flags |= flags;
                    }
                    Offset += AI_SetObjectFlags_LENGTH;
                    break;
                }
                case AI_UnsetObjectFlags:
                {
                    AIRecord     *ai    = AiListp + Offset;
                    s32           flags = CharArrayTo32(ai->val,1);
                    ObjectRecord *obj   = objFindByTagId(ai->val[0]);
                    if (obj && obj->prop)
                    {
                        obj->flags &= ~flags;
                    }
                    Offset += AI_UnsetObjectFlags_LENGTH;
                    break;
                }
                case AI_IFObjectFlagsHas:
                {
                    AIRecord     *ai    = AiListp + Offset;
                    s32           flags = CharArrayTo32(ai->val,1);
                    ObjectRecord *obj   = objFindByTagId(ai->val[0]);
                    if (obj && obj->prop && (obj->flags & flags) == flags)
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[5]);
                    }
                    else
                    {
                        Offset += AI_IFObjectFlagsHas_LENGTH;
                    }
                    break;
                }
                case AI_SetObjectFlags2:
                {
                    AIRecord     *ai    = AiListp + Offset;
                    s32           flags = CharArrayTo32(ai->val,1);
                    ObjectRecord *obj   = objFindByTagId(ai->val[0]);
                    if (obj && obj->prop)
                    {
                        obj->flags2 |= flags;
                    }
                    Offset += AI_SetObjectFlags2_LENGTH;
                    break;
                }
                case AI_UnsetObjectFlags2:
                {
                    AIRecord     *ai    = AiListp + Offset;
                    s32           flags = CharArrayTo32(ai->val,1);
                    ObjectRecord *obj   = objFindByTagId(ai->val[0]);
                    if (obj && obj->prop)
                    {
                        obj->flags2 &= ~flags;
                    }
                    Offset += AI_UnsetObjectFlags2_LENGTH;
                    break;
                }
                case AI_IFObjectFlags2Has:
                {
                    AIRecord     *ai    = AiListp + Offset;
                    s32           flags = CharArrayTo32(ai->val,1);
                    ObjectRecord *obj   = objFindByTagId(ai->val[0]);
                    if (obj && obj->prop && ((obj->flags2 & flags) == flags))
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[5]);
                    }
                    else
                    {
                        Offset += AI_IFObjectFlags2Has_LENGTH;
                    }
                    break;
                }
                case AI_SetMyChrPreset:
                {
                    AIRecord *ai = AiListp + Offset;
                    chrSetChrPreset(ChrEntityp, ai->val[0]);
                    Offset += AI_SetMyChrPreset_LENGTH;
                    break;
                }
                case AI_SetChrChrPreset:
                {
                    AIRecord *ai = AiListp + Offset;
                    chrSetChrPreset2(ChrEntityp, ai->val[0], ai->val[1]);
                    Offset += AI_SetChrChrPreset_LENGTH;
                    break;
                }
                case AI_SetMyPadPreset:
                {
                    AIRecord *ai     = AiListp + Offset;
                    u16       pad_id = CharArrayTo16(ai->val,0);
                    if (ChrEntityp)
                    {
#ifdef ENABLE_LOG
                        if (pad_id == PAD_PRESET1 && ChrEntityp->padpreset1 == PAD_PRESET1)
                        {
                            osSyncPrintf("RUSS : Pad is bollox -> Num=%d (%d) - PAD_PRESET1=%d\n", pad_id, ChrEntityp->padpreset1, PAD_PRESET1);
                        }
#endif
                        chrSetPadPreset(ChrEntityp, pad_id);
                    }
                    else if (AircraftEntityp)
                    {
                        AircraftEntityp->pad = pad_id;
                    }
                    Offset += AI_SetMyPadPreset_LENGTH;
                    break;
                }
                case AI_SetChrPadPreset:
                {
                    AIRecord *ai     = AiListp + Offset;
                    u16       pad_id = CharArrayTo16(ai->val,1);
                    chrSetPadPresetByChrnum(ChrEntityp, ai->val[0], pad_id);
                    Offset += AI_SetChrPadPreset_LENGTH;
                    break;
                }
                case AI_PRINT:
                {
#ifdef ENABLE_LOG
                    AIRecord *ai = AiListp + Offset;
                    //PD = osSyncPrintf("AI_PRINT(void) [%d] %s\n", ai-val);
                    osSyncPrintf("AI_PRINT: %s\n", ai->val);
#endif
                    Offset += chraiitemsize(AiListp, Offset);
                    break;
                }
                case AI_MyTimerStart:
                {
                    chrRestartTimer(ChrEntityp); //Set timer60 to 0 and set flag
                    Offset += AI_MyTimerStart_LENGTH;
                    break;
                }
                case AI_MyTimerReset:
                {
                    ChrEntityp->timer60 = 0;
                    Offset += AI_MyTimerReset_LENGTH;
                    break;
                }
                case AI_MyTimerPause:
                {
                    ChrEntityp->hidden &= ~CHRHIDDEN_TIMER_ACTIVE;
                    Offset += AI_MyTimerPause_LENGTH;
                    break;
                }
                case AI_MyTimerResume:
                {
                    ChrEntityp->hidden |= CHRHIDDEN_TIMER_ACTIVE;
                    Offset += AI_MyTimerResume_LENGTH;
                    break;
                }
                case AI_IFMyTimerIsNotRunning:
                {
                    AIRecord *ai = AiListp + Offset;
                    if (((ChrEntityp->hidden & CHRHIDDEN_TIMER_ACTIVE) == 0))
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[0]);
                    }
                    else
                    {
                        Offset += AI_IFMyTimerIsNotRunning_LENGTH;
                    }
                    break;
                }
                case AI_IFMyTimerLessThanTicks:
                {
                    AIRecord *ai   = AiListp + Offset;
                    f32       valf = ((unsigned)CharArrayTo24(ai->val,0)) / CHRAI_TICKRATE_F;

                    if (chrGetTimer(ChrEntityp) < valf)
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[3]);
                    }
                    else
                    {
                        Offset += AI_IFMyTimerLessThanTicks_LENGTH;
                    }
                    break;
                }
                case AI_IFMyTimerGreaterThanTicks:
                {
                    AIRecord *ai   = AiListp + Offset;
                    f32       valf = ((unsigned)CharArrayTo24(ai->val,0)) / CHRAI_TICKRATE_F;
                    if (chrGetTimer(ChrEntityp) > valf)
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[3]);
                    }
                    else
                    {
                        Offset += AI_IFMyTimerGreaterThanTicks_LENGTH;
                    }
                    break;
                }
                case AI_HudCountdownShow:
                {
                    countdownTimerSetVisible(1, TRUE);
                    Offset += AI_HudCountdownShow_LENGTH;
                    break;
                }
                case AI_HudCountdownHide:
                {
                    countdownTimerSetVisible(1, FALSE);
                    Offset += AI_HudCountdownHide_LENGTH;
                    break;
                }
                case AI_HudCountdownSet:
                {
                    AIRecord *ai      = AiListp + Offset;
                    f32       seconds = CharArrayTo16(ai->val,0);
                    countdownTimerSetValue(seconds * CHRAI_TICKRATE_F);
                    Offset += AI_HudCountdownSet_LENGTH;
                    break;
                }
                case AI_HudCountdownStop:
                {
                    countdownTimerSetRunning(FALSE);
                    Offset += AI_HudCountdownStop_LENGTH;
                    break;
                }
                case AI_HudCountdownStart:
                {
                    countdownTimerSetRunning(TRUE);
                    Offset += AI_HudCountdownStart_LENGTH;
                    break;
                }
                case AI_IFHudCountdownIsNotRunning:
                {
                    AIRecord *ai = AiListp + Offset;
                    if (!countdownTimerIsRunning())
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[0]);
                    }
                    else
                    {
                        Offset += AI_IFHudCountdownIsNotRunning_LENGTH;
                    }
                    break;
                }
                case AI_IFHudCountdownLessThan:
                {
                    AIRecord *ai    = AiListp + Offset;
                    f32       value = CharArrayTo16(ai->val,0);
                    if (countdownTimerGetValue() < value * CHRAI_TICKRATE_F)
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[2]);
                    }
                    else
                    {
                        Offset += AI_IFHudCountdownLessThan_LENGTH;
                    }
                    break;
                }
                case AI_IFHudCountdownGreaterThan:
                {
                    AIRecord *ai    = AiListp + Offset;
                    f32       value = CharArrayTo16(ai->val,0);
                    if (countdownTimerGetValue() > value * CHRAI_TICKRATE_F)
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[2]);
                    }
                    else
                    {
                        Offset += AI_IFHudCountdownGreaterThan_LENGTH;
                    }
                    break;
                }
                case AI_TRYSpawningChrAtPad:
                {
                    AIRecord *ai       = AiListp + Offset;
                    u16       pad      = CharArrayTo16(ai->val,2);
                    CHRFLAG   flags    = CharArrayTo32(ai->val,6);
                    u16       ailistid = CharArrayTo16(ai->val,4);
                    AIRecord *ailist   = ailistFindById(ailistid);
#ifdef ENABLE_LOG
                    if (flags & 32)
                    {
                        osSyncPrintf("ai_createchrheadthenjumpf : Flag set CHRSTART_FORCENOBLOOD\n");
                    }
#endif
                    if (chrSpawnAtPad(ChrEntityp, ai->val[0], (s8)ai->val[1], pad, ailist, flags))
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[10]);
                    }
                    else
                    {
                        Offset += AI_TRYSpawningChrAtPad_LENGTH;
                    }
                    break;
                }
                case AI_TRYSpawningChrNextToChr:
                {
                    AIRecord *ai       = AiListp + Offset;
                    CHRFLAG   flags    = CharArrayTo32(ai->val,5);
                    u16       ailistid = CharArrayTo16(ai->val,3);
                    AIRecord *ailist   = ailistFindById(ailistid);
                    if (chrSpawnAtChr(ChrEntityp, ai->val[0], (s8)ai->val[1], ai->val[2], ailist, flags))
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[9]);
                    }
                    else
                    {
                        Offset += AI_TRYSpawningChrNextToChr_LENGTH;
                    }
                    break;
                }
                case AI_TRYGiveMeItem:
                {
                    AIRecord   *ai    = AiListp + Offset;
                    s32         flags = CharArrayTo32(ai->val,3);
                    s32         model = CharArrayTo16(ai->val,0); 
                    PropRecord *prop  = NULL;

                    if (ChrEntityp && ChrEntityp->prop && ChrEntityp->model)
                    {
                        /*  more nice PD code that might be usefull in future
                        if (cheatIsActive(CHEAT_MARQUIS))
                        {
                            flags &= ~0x10000000;
                            flags |= 0x20000000;
                            prop = chrGiveWeapon(ChrEntityp, model, ai->val[2], flags);
                        }
                        else
                        */
                        if (cheatIsActive(28)) // CHEAT_ENEMYROCKETS
                        {
                            switch (ai->val[2]) // ITEM_IDS
                            {
                                case ITEM_KNIFE:
                                case ITEM_THROWKNIFE:
                                case ITEM_WPPK:
                                case ITEM_WPPKSIL:
                                case ITEM_TT33:
                                case ITEM_SKORPION:
                                case ITEM_AK47:
                                case ITEM_UZI:
                                case ITEM_MP5K:
                                case ITEM_MP5KSIL:
                                case ITEM_SPECTRE:
                                case ITEM_M16:
                                case ITEM_FNP90:
                                case ITEM_SHOTGUN:
                                case ITEM_AUTOSHOT:
                                case ITEM_SNIPERRIFLE:
                                case ITEM_RUGER:
                                case ITEM_GOLDENGUN:
                                case ITEM_SILVERWPPK:
                                case ITEM_GOLDWPPK:
                                case ITEM_LASER:
                                case ITEM_WATCHLASER:
                                case ITEM_REMOTEMINE:
                                case ITEM_TRIGGER:
                                case ITEM_TASER:

                                    prop = chrGiveWeapon(ChrEntityp, PROP_CHRROCKETLAUNCH, ITEM_ROCKETLAUNCH, flags);
                                    //!Bug, No Break! relying on chrGiveWeapon checking weapon already given
                                case ITEM_TIMEDMINE:
                                case ITEM_PROXIMITYMINE:
                                default:
                                    prop = chrGiveWeapon(ChrEntityp, model, ai->val[2], flags);
                                    break;
                            }
                        }
                        else
                        {
                            prop = chrGiveWeapon(ChrEntityp, model, ai->val[2], flags);
                        }
                    }
                    if (prop)
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[7]);
                    }
                    else
                    {
                        Offset += AI_TRYGiveMeItem_LENGTH;
                    }
                    break;
                }
                case AI_TRYGiveMeHat:
                {
                    AIRecord *ai       = AiListp + Offset;
                    s32       flags    = CharArrayTo32(ai->val,2);
                    s32       modelnum = CharArrayTo16(ai->val,0);
                    bool      ok       = FALSE;
                    if (ChrEntityp && ChrEntityp->prop && ChrEntityp->model)
                    {
                        ok = hatCreateForChr(ChrEntityp, modelnum, flags);
                    }
                    if (ok)
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[6]);
                    }
                    else
                    {
                        Offset += AI_TRYGiveMeHat_LENGTH;
                    }
                    break;
                }
                case AI_TRYCloningChr:
                {
                    AIRecord        *ai               = AiListp + Offset;
                    //int zero                        = 0; //on stack in xbla, but matches without
                    u16              ailistid         = CharArrayTo16(ai->val,1);
                    u8              *ailist           = ailistFindById((u16)ailistid);
                    ChrRecord       *chr              = chrFindById(ChrEntityp, ai->val[0]);
                    bool             pass             = FALSE; //564
                    int              chrnum;
                    PropRecord      *srcweaponLprop   = NULL;
                    PropRecord      *srcweaponRprop   = NULL;
                    PropRecord      *cloneweaponRprop = NULL;
                    PropRecord      *cloneweaponLprop = NULL;
                    PropRecord      *cloneprop        = NULL;
                    ChrRecord       *clone            = NULL; //536
                    WeaponObjRecord *srcweaponL       = NULL;
                    WeaponObjRecord *cloneweaponL     = NULL; //528
                    WeaponObjRecord *cloneweaponR     = NULL; //524
                    WeaponObjRecord *srcweaponR       = NULL;
                    PropRecord      *hatprop;
                    ObjectRecord    *hatobj;
                    //bool tryhat;
                    if (chr && (chr->chrflags & CHRFLAG_CLONE))
                    {
                        cloneprop = chrSpawnAtChr(ChrEntityp, chr->bodynum, -1, chr->chrnum, ailist, 0);
                        if (cloneprop)
                        {
                            clone  = cloneprop->chr;
                            chrnum = chr->chrnum + 10000;
                            if (!chrFindById(ChrEntityp, chrnum))
                            {
                                clone->chrnum = chrnum;
                            }
                            // chrSetChrnum(clone, getLowestUnusedChrId());
                            // chr->chrdup = clone->chrnum;
                            srcweaponRprop = chrGetEquippedWeaponProp(chr, GUNRIGHT);
                            if (srcweaponRprop)
                            {
                                srcweaponR       = srcweaponRprop->weapon;
                                cloneweaponRprop = chrGiveWeapon(clone, srcweaponR->obj, srcweaponR->weaponnum, 0);
                                if (cloneweaponRprop)
                                {
                                    cloneweaponR = cloneweaponRprop->weapon;
                                }
                            }

                            srcweaponLprop = chrGetEquippedWeaponProp(chr, GUNLEFT);
                            if (srcweaponLprop)
                            {
                                srcweaponL       = srcweaponLprop->weapon;
                                cloneweaponLprop = chrGiveWeapon(clone, srcweaponL->obj, srcweaponL->weaponnum, 0x10000000);
                                if (cloneweaponLprop)
                                {
                                    cloneweaponL = cloneweaponLprop->weapon;
                                }
                            }

                            if (srcweaponL && srcweaponR && cloneweaponL && cloneweaponR && srcweaponR == srcweaponL->dualweapon && srcweaponL == srcweaponR->dualweapon)
                            {
                                propweaponSetDual(cloneweaponL, cloneweaponR);
                            }
                            {
                                hatprop = chr->handle_positiondata_hat;
                                if (hatprop)
                                {
                                    hatobj = hatprop->obj;

                                    hatCreateForChr(clone, hatobj->obj, 0);
                                }
                            }
                            /* PD extras */
                            //clone->morale     = chr->morale;
                            //clone->alertness  = chr->alertness;
                            //clone->padpreset1 = chr->padpreset1;
                            pass = TRUE;
                        }
                    }
                    if (pass)
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[3]);
                    }
                    else
                    {
                        Offset += AI_TRYCloningChr_LENGTH;
                    }
                    break;
                }
                case AI_TextPrintBottom:
                {
                    AIRecord *ai   = AiListp + Offset;
                    char     *text = langGet(CharArrayTo16(ai->val,0));
#ifdef ENABLE_LOG
                    osSyncPrintf("USING HUD MESSAGE Stringy = %d, ai->txt = %d\n", CharArrayTo16(ai->val,0), text);
#endif
#ifdef BUGFIX_R1
                    jp_hudmsgBottomShow(text);
#else
                    hudmsgBottomShow(text);
#endif
                    Offset += AI_TextPrintBottom_LENGTH;
                    break;
                }
                case AI_TextPrintTop:
                {
                    AIRecord *ai   = AiListp + Offset;
                    char     *text = langGet(CharArrayTo16(ai->val,0));

#ifdef ENABLE_LOG
                    osSyncPrintf("ptop =  %f \n", text);
                    osSyncPrintf("USING HUD MESSAGE Stringy = %d, ai->txt = %d\n", CharArrayTo16(ai->val,0), text);

#endif

                    hudmsgTopShow(text);
                    Offset += AI_TextPrintTop_LENGTH;
                    break;
                }
                case AI_SfxPlay:
                {
                    AIRecord *ai       = AiListp + Offset;
                    s16       audio_id = CharArrayTo16(ai->val,0);
                    audioPlayFromProp((s8)ai->val[2], audio_id);
                    Offset += AI_SfxPlay_LENGTH;
                    break;
                }

                case AI_SfxStopChannel:
                {
                    AIRecord1s *ai = AiListp + Offset;
                    sub_GAME_7F0349BC(ai->val);
                    Offset += AI_SfxStopChannel_LENGTH;
                    break;
                }
                case AI_SfxSetChannelVolume:
                {
                    struct
                    {
                        u8 cmd;
                        s8 slotID;
                        u8 val[];
                    } *ai     = AiListp + Offset;
                    s16 vol   = CharArrayTo16(ai->val,0);
                    u16 sfxID = CharArrayTo16(ai->val,2);
                    if (ai->slotID >= 0 && ai->slotID < 8)
                    {
#ifdef VERSION_EU
                        sfx_related[ai->slotID].sfxID  = (sfxID * 50) / 60;
#else            
                        sfx_related[ai->slotID].sfxID  = sfxID;    
#endif
                        sfx_related[ai->slotID].Volume = vol;
                        sfx_related[ai->slotID].pos    = NULL;
                        sfx_related[ai->slotID].Obj    = NULL;
                        if (sfxID == 0)
                        {
                            audioPlayFromProp2(ai->slotID);
                        }
                    }
                    /*
                      "AI : Bad sound setup command\n"
                    */
                    Offset += AI_SfxSetChannelVolume_LENGTH;
                    break;
                }
                case AI_SfxFadeChannelVolume:
                {
                    struct
                    {
                        u8 cmd;
                        s8 slotID;
                        u8 val[];
                    } *ai     = AiListp + Offset;
                    f32 vol   = CharArrayTo16(ai->val,0);
                    u16 sfxID = CharArrayTo16(ai->val,2);
                    /*
                        "fadeTo\n"
                     */
                    if (ai->slotID >= 0 && ai->slotID < 8)
                    {
#ifdef VERSION_EU
                        sfx_related[ai->slotID].sfxID  = (sfxID * 50) / 60;
#else            
                        sfx_related[ai->slotID].sfxID  = sfxID;    
#endif
                        sfx_related[ai->slotID].Volume = sub_GAME_7F0539B8(vol);
                        sfx_related[ai->slotID].pos    = NULL;
                        sfx_related[ai->slotID].Obj    = NULL;
                        if (sfxID == 0)
                        {
                            audioPlayFromProp2(ai->slotID);
                        }
                    }
                    Offset += AI_SfxFadeChannelVolume_LENGTH;
                    break;
                }
                case AI_SfxEmitFromObject:
                {
                    struct
                    {
                        u8 cmd;
                        s8 slotID;
                        u8 val[];
                    } *ai               = AiListp + Offset;
                    ObjectRecord *obj   = objFindByTagId(ai->val[0]);
                    u16           sfxID = CharArrayTo16(ai->val,1);
                    if (ai->slotID >= 0 && ai->slotID < 8 && obj)
                    {
#ifdef VERSION_EU
                        sfx_related[ai->slotID].sfxID  = (sfxID * 50) / 60;
#else            
                        sfx_related[ai->slotID].sfxID  = sfxID;    
#endif
                        sfx_related[ai->slotID].pos   = NULL;
                        sfx_related[ai->slotID].Obj   = obj;
                        if (sfxID == 0)
                        {
                            audioPlayFromProp2(ai->slotID);
                        }
                    }
                    Offset += AI_SfxEmitFromObject_LENGTH;
                    break;
                }
                case AI_SfxEmitFromPad:
                {
                    struct
                    {
                        u8 cmd;
                        s8 slotID;
                        u8 val[];
                    } *ai             = AiListp + Offset;
                    u16        padnum = CharArrayTo16(ai->val,0);
                    PadRecord *pad;
                    u16        sfxID = CharArrayTo16(ai->val,2);
                    if (isNotBoundPad(padnum))
                    {
                        pad = &g_CurrentSetup.pads[padnum];
                    }
                    else
                    {
                        pad = (PadRecord *)&g_CurrentSetup.boundpads[getBoundPadNum(padnum)];
                    }
                    if (ai->slotID >= 0 && ai->slotID < 8 && pad)
                    {
#        ifdef VERSION_EU
                        sfx_related[ai->slotID].sfxID = (sfxID * 50) / 60;
#        else
                        sfx_related[ai->slotID].sfxID  = sfxID;
#        endif
                        sfx_related[ai->slotID].pos   = pad;
                        sfx_related[ai->slotID].Obj   = NULL;
                        if (sfxID == 0)
                        {
                            audioPlayFromProp2(ai->slotID);
                        }
                    }
                    Offset += AI_SfxEmitFromPad_LENGTH;
                    break;
                }

                case AI_IFSfxChannelVolumeLessThan:
                {
                    struct
                    {
                        u8 cmd;
                        s8 slotID;
                        u8 val[];
                    } *ai   = AiListp + Offset;
                    s16 vol = CharArrayTo16(ai->val,0);
                    /*
                     * "ai_ifmusicqueueemptyjumpf : %s, State=%x (getlvleveltime60=%f)\n"
                     */

                    if ((ai->slotID >= 0) && (ai->slotID < 8) && (sfx_related[ai->slotID].Volume2 < vol))
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[2]);
                    }
                    else
                    {
                        Offset += AI_IFSfxChannelVolumeLessThan_LENGTH;
                    }
                    break;
                }
                case AI_VehicleStartPath:
                {
                    AIRecord   *ai   = AiListp + Offset;
                    PathRecord *path = pathFindById(ai->val[0]);
                    if (VehichleEntityp)
                    {
                        VehichleEntityp->path     = path;
                        VehichleEntityp->nextstep = 0;
                    }
                    Offset += AI_VehicleStartPath_LENGTH;
                    break;
                }
                case AI_VehicleSpeed:
                {
                    AIRecord *ai        = AiListp + Offset;
                    f32       speedtime = CharArrayTo16(ai->val,2);
                    f32       speedaim  = CharArrayTo16(ai->val,0) * 100.0f / 15360.0f;
                    if (VehichleEntityp)
                    {
                        VehichleEntityp->speedaim    = speedaim;
                        VehichleEntityp->speedtime60 = speedtime;
                    }
                    Offset += AI_VehicleSpeed_LENGTH;
                    break;
                }
                case AI_AircraftRotorSpeed:
                {
                    AIRecord *ai        = AiListp + Offset;
                    f32       speedtime = CharArrayTo16(ai->val,2);
                    f32       speedaim  = CharArrayTo16(ai->val,0) * M_TAU_F / 3600.0f;
                    if (AircraftEntityp)
                    {
                        AircraftEntityp->rotaryspeedaim  = speedaim;
                        AircraftEntityp->rotaryspeedtime = speedtime;
                    }
                    Offset += AI_AircraftRotorSpeed_LENGTH;
                    break;
                }
                case AI_IFCameraIsInIntro:
                {
                    AIRecord *ai = AiListp + Offset;
                    if ((get_camera_mode() == 1) || (get_camera_mode() == 2))
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[0]);
                    }
                    else
                    {
                        Offset += AI_IFCameraIsInIntro_LENGTH;
                    }
                    break;
                }
                case AI_IFCameraIsInBondSwirl:
                {
                    AIRecord *ai = AiListp + Offset;
                    if (get_camera_mode() == 3)
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[0]);
                    }
                    else
                    {
                        Offset += AI_IFCameraIsInBondSwirl_LENGTH;
                    }
                    break;
                }
                case AI_TvChangeScreenBank:
                {
                    AIRecord     *ai  = AiListp + Offset;
                    ObjectRecord *obj = objFindByTagId(ai->val[0]);
                    if (obj && obj->prop)
                    {
                        if (obj->type == PROPDEF_MONITOR)
                        {
                            MonitorObjRecord *sm = (MonitorObjRecord *)obj;
                            monitorSetImageByNum(&sm->Monitor.cmdlist, ai->val[2]);
                        }
                        else if (obj->type == PROPDEF_MULTI_MONITOR)
                        {
                            u8 slot = ai->val[1];
                            if (slot < 4)
                            {
                                MultiMonitorObjRecord *mm = (MultiMonitorObjRecord *)obj; //need new size here 0x74 (116) + 0x80 (so monitor is obj + 74)
                                monitorSetImageByNum(&mm->Monitor[slot].cmdlist, ai->val[2]);
                            }
                        }
                    }
                    Offset += AI_TvChangeScreenBank_LENGTH;
                    break;
                }
                case AI_IFBondInTank: //canonical name
                {
                    AIRecord *ai = AiListp + Offset;
#ifdef ENABLE_LOG
                    osSyncPrintf("ai_ifbondintank\n"); 
#endif 
                    if (isBondInTank() == TRUE)
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[0]);
                    }
                    else
                    {
                        Offset += AI_IFBondInTank_LENGTH;
                    }
                    break;
                }
                case AI_EndLevel: // canonical name
                {
                    /*"aiEndLevel" */
                    if (camera_8003642C)
                    {
                        if (camera_80036434 == FALSE)
                        {
                            camera_80036434 = TRUE;
                        }
                    }
                    else
                    {
                        bossReturnTitleStage();
                    }
                    Offset += AI_EndLevel_LENGTH;
                    break;
                }
                case AI_CameraReturnToBond:
                {
                    set_camera_mode(CAMERAMODE_FP_NOINPUT);
                    Offset += AI_CameraReturnToBond_LENGTH;
                    break;
                }
                case AI_CameraLookAtBondFromPad:
                {
                    AIRecord *ai     = AiListp + Offset;
                    u16       padnum = CharArrayTo16(ai->val,0);
                    if (isNotBoundPad(padnum))
                    {
                        dword_CODE_bss_800799F8 = &g_CurrentSetup.pads[padnum];
                    }
                    else
                    {
                        dword_CODE_bss_800799F8 = (PadRecord *)&g_CurrentSetup.boundpads[getBoundPadNum(padnum)];
                    }
                    set_camera_mode(CAMERAMODE_POSEND);
                    Offset += AI_CameraLookAtBondFromPad_LENGTH;
                    break;
                }
                case AI_CameraSwitch:
                {
                    AIRecord        *ai  = AiListp + Offset;
                    TagObjectRecord *tag = sub_GAME_7F057080(ai->val[0]);
                    if (tag)
                    {
                        int TagIndex = tagGetCommandIndex(tag); //get index
                        if (TagIndex >= 0)
                        {
                            CutsceneRecord *cdef = setupGetPtrToCommandByIndex(tag->OffsetToObj + TagIndex); //get obj

#ifdef ENABLE_LOG
                            /*".\\ported\\chrai.c", 0xc2b, "Assertion failed: cdef->type==PROPDEF_CAMERAPOS") */
                            assert(cdef->type == PROPDEF_CAMERAPOS);
#endif
                            dword_CODE_bss_800799F8 = NULL;
                            gBondViewCutscene       = cdef;
                            dword_CODE_bss_80079A18 = CharArrayTo16(ai->val,1);
                            dword_CODE_bss_80079A1C = CharArrayTo16(ai->val,3);
                            set_camera_mode(CAMERAMODE_POSEND);
                        }
                    }
                    Offset += AI_CameraSwitch_LENGTH;
                    break;
                }
                case AI_IFBondYPosLessThan:
                {
                    AIRecord *ai      = AiListp + Offset;
                    f32       bondpos = (s16)CharArrayTo16(ai->val,0);
                    if (get_curplayer_positiondata()->pos.y < bondpos)
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[2]);
                    }
                    else
                    {
                        Offset += AI_IFBondYPosLessThan_LENGTH;
                    }
                    break;
                }
                case AI_BondDisableControl:
                {
                    AIRecord1 *ai = AiListp + Offset;
                    gunSetSightVisible(GUNSIGHTREASON_NOCONTROL, FALSE);
                    gunSetGunAmmoVisible(GUNAMMOREASON_NOCONTROL, FALSE);
                    if (!(PLAYERFLAG_NOCONTROL & ai->val))
                    {
                        hudmsgsSetOff(PLAYERFLAG_NOCONTROL);
                    }
                    if (!(ai->val & PLAYERFLAG_LOCKCONTROLS))
                    {
                        bondviewSetUpperTextDisplayFlag(PLAYERFLAG_NOCONTROL);
                    }
                    if (!(ai->val & PLAYERFLAG_NOTIMER))
                    {
                        countdownTimerSetVisible(16, FALSE);
                    }
                    D_800364B0 = FALSE;
                    Offset += AI_BondDisableControl_LENGTH;
                    break;
                }
                case AI_BondEnableControl:
                {
#ifdef ENABLE_LOG
                    osSyncPrintf("AI_BONDENABLECONTROL\n");
#endif
                    gunSetSightVisible(GUNSIGHTREASON_NOCONTROL, TRUE);
                    gunSetGunAmmoVisible(GUNAMMOREASON_NOCONTROL, TRUE);
                    hudmsgsSetOn(PLAYERFLAG_NOCONTROL);
                    bondviewClearUpperTextDisplayFlag(2);
                    countdownTimerSetVisible(16, TRUE);
                    D_800364B0 = TRUE;
                    Offset += AI_BondEnableControl_LENGTH;
                    break;
                }
                case AI_TRYTeleportingChrToPad:
                {
                    AIRecord  *ai     = AiListp + Offset;
                    s32        padnum = CharArrayTo16(ai->val,1);
                    ChrRecord *chr    = chrFindById(ChrEntityp, ai->val[0]);
                    bool       pass   = FALSE;
                    PadRecord *pad;
                    f32        FacingDirection;
                    coord3d    pos;
                    StandTile *stan;

                    if (chr)
                    {
                        padnum = chrResolvePadId(ChrEntityp, padnum);
                        if (isNotBoundPad(padnum))
                        {
                            pad = &g_CurrentSetup.pads[padnum];
                        }
                        else
                        {
                            pad = (PadRecord *)&g_CurrentSetup.boundpads[getBoundPadNum(padnum)];
                        }

                        FacingDirection = atan2f(pad->look.x, pad->look.z);
                        pos.x           = pad->pos.x;
                        pos.y           = pad->pos.y;
                        pos.z           = pad->pos.z;
                        //pos  = pad->pos; <-uses lw instead of lwc1
                        stan            = pad->stan;
                        sub_GAME_7F03D058(chr->prop, FALSE);

                        if (sub_GAME_7F033F48(&pos, &stan, FacingDirection, TRUE))
                        {
                            {
                                chr->prop->pos.x = pos.x;
                                chr->prop->pos.y = pos.y;
                                chr->prop->pos.z = pos.z;
                            }
                            //chr->prop->pos  = pos;
                            chr->prop->stan = stan;
                            chr->chrflags   = chr->chrflags | CHRFLAG_INIT;
                            setsubroty(chr->model, FacingDirection);
                            setsuboffset(chr->model, &pos);
                            chrPositionRelated7F020D94(chr);
                            if (chr->prop == g_CurrentPlayer->prop)
                            {
                                g_CurrentPlayer->field_488.collision_position.x = pos.x;
                                g_CurrentPlayer->field_488.collision_position.y = pos.y;
                                g_CurrentPlayer->field_488.collision_position.z = pos.z;

                                //g_CurrentPlayer->pos = pos;
                                g_CurrentPlayer->field_488.current_tile_ptr = stan;
                            }
                            pass = TRUE;
                        }
                        sub_GAME_7F03D058(chr->prop, TRUE);
                    }
                    if (pass)
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[3]);
                    }
                    else
                    {
                        Offset += AI_TRYTeleportingChrToPad_LENGTH;
                    }
                    break;
                }
                case AI_ScreenFadeToBlack:
                {
                    if (stop_time_flag != 2)
                    {
                        currentPlayerSetFadeColour(0, 0, 0, 0);
                        currentPlayerSetFadeFrac(CHRAI_TICKRATE_F, 1);
                    }
                    Offset += AI_ScreenFadeToBlack_LENGTH;
                    break;
                }
                case AI_ScreenFadeFromBlack:
                {
                    if (stop_time_flag != 2)
                    {
                        currentPlayerSetFadeColour(0, 0, 0, 1);
                        currentPlayerSetFadeFrac(CHRAI_TICKRATE_F, 0);
                    }
                    Offset += AI_ScreenFadeFromBlack_LENGTH;
                    break;
                }
                case AI_IFScreenFadeCompleted:
                {
                    AIRecord *ai = AiListp + Offset;
                    if (g_CurrentPlayer->colourfadetimemax60 < 0)
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[0]);
                    }
                    else
                    {
                        Offset += AI_IFScreenFadeCompleted_LENGTH;
                    }
                    break;
                }
                case AI_HideAllChrs:
                {
                    s32 num;
                    for (num = get_numguards() - 1; num >= 0; num--)
                    {
                        if (g_ChrSlots[num].model != NULL)
                        {
                            g_ChrSlots[num].chrflags |= CHRFLAG_HIDDEN;
                        }
                    }
                    Offset += AI_HideAllChrs_LENGTH;
                    break;
                }
                case AI_ShowAllChrs:
                {
                    s32 num;
                    for (num = get_numguards() - 1; num >= 0; num--)
                    {
                        g_ChrSlots[num].chrflags &= ~CHRFLAG_HIDDEN;
                    }

                    Offset += AI_ShowAllChrs_LENGTH;
                    break;
                }
                case AI_DoorOpenInstant:
                {
                    AIRecord   *ai   = AiListp + Offset;
                    DoorRecord *door = objFindByTagId(ai->val[0]);
                    if (door && door->prop)
                    {
                        //DoorRecord *door   = (DoorRecord *)obj;
                        door->speed        = 0;
                        door->openPosition = door->maxFrac;
                        door->openedTime   = g_GlobalTimer;
                        door->openstate    = DOORSTATE_STATIONARY;
                        sub_GAME_7F052B00(door);
                        doorActivatePortal(door); // doorActivatePortal
                        sub_GAME_7F053B10(door);
                    }
                    Offset += AI_DoorOpenInstant_LENGTH;
                    break;
                }
                case AI_ChrRemoveItemInHand:
                {
                    AIRecord  *ai  = AiListp + Offset;
                    ChrRecord *chr = chrFindById(ChrEntityp, ai->val[0]);
                    if (chr)
                    {
                        chrSetWeaponFlag4(chr, ai->val[1]);
                    }
                    Offset += AI_ChrRemoveItemInHand_LENGTH;
                    break;
                }
                case AI_IfNumberOfActivePlayersLessThan:
                {
                    struct
                    {
                        u8 cmd;
                        s8 val;
                        u8 label;
                    } *ai = AiListp + Offset;
                    if (getPlayerCount() < ai->val)
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->label);
                    }
                    else
                    {
                        Offset += AI_IfNumberOfActivePlayersLessThan_LENGTH;
                    }
                    break;
                }
                case AI_IFBondItemTotalAmmoLessThan:
                {
                    AIRecord *ai = AiListp + Offset;
                    if (currentPlayerGetAmmoCount((s8)ai->val[0]) < (s8)ai->val[1])
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[2]);
                    }
                    else
                    {
                        Offset += AI_IFBondItemTotalAmmoLessThan_LENGTH;
                    }
                    break;
                }
                case AI_BondEquipItem:
                {
                    AIRecord1s *ai = AiListp + Offset;
                    currentPlayerEquipWeaponWrapper(GUNRIGHT, ai->val);
                    currentPlayerEquipWeaponWrapper(GUNLEFT, 0);
                    Offset += AI_BondEquipItem_LENGTH;
                    break;
                }
                case AI_BondEquipItemCinema:
                {
                    AIRecord1s *ai = AiListp + Offset;
                    currentPlayerUnEquipWeaponWrapper(GUNRIGHT, ai->val);
                    currentPlayerUnEquipWeaponWrapper(GUNLEFT, 0);
                    Offset += AI_BondEquipItemCinema_LENGTH;
                    break;
                }
                case AI_BondSetLockedVelocity:
                {
                    /*
                    g_Vars.currentplayer->bondforcespeed.x = (s8)ai->val[1];
                    g_Vars.currentplayer->bondforcespeed.y = 0;
                    g_Vars.currentplayer->bondforcespeed.z = (s8)ai->val[2];
                    */
                    AIRecord *ai            = AiListp + Offset;
                    g_ForceBondMoveOffset.x = (s8)ai->val[0];
                    g_ForceBondMoveOffset.y = 0;
                    g_ForceBondMoveOffset.z = (s8)ai->val[1];
                    Offset += AI_BondSetLockedVelocity_LENGTH;
                    break;
                }
                case AI_IFObjectInRoomWithPad:
                {
                    AIRecord     *ai     = AiListp + Offset;
                    u16           padnum = CharArrayTo16(ai->val,1);
                    PadRecord    *pad;
                    ObjectRecord *obj = objFindByTagId(ai->val[0]);

                    if (isNotBoundPad(padnum))
                    {
                        pad = &g_CurrentSetup.pads[padnum * 1]; //needs a mult by 1 to correct s0/v1
                    }
                    else
                    {
                        pad = (PadRecord *)&g_CurrentSetup.boundpads[getBoundPadNum(padnum)];
                    }

                    if (pad->stan && obj && obj->prop && (pad->stan->room == obj->prop->stan->room))
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[3]);
                    }
                    else
                    {
                        Offset += AI_IFObjectInRoomWithPad_LENGTH;
                    }
                    break;
                }
                case AI_SwitchSky:
                { // SWITCHENVIRONMENT
                    fogSwitchToSolosky2(1.0);
                    Offset += AI_SwitchSky_LENGTH;
                    break;
                }
                case AI_TriggerFadeAndExitLevelOnButtonPress:
                {
                    if (stop_time_flag == FALSE)
                    {
                        stop_time_flag = TRUE;
                    }
                    Offset += AI_TriggerFadeAndExitLevelOnButtonPress_LENGTH;
                    break;
                }
                case AI_IFBondIsDead:
                {
                    AIRecord *ai = AiListp + Offset;
                    if (g_CurrentPlayer->bonddead)
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[0]);
                    }
                    else
                    {
                        Offset += AI_IFBondIsDead_LENGTH;
                    }
                    break;
                }
                case AI_BondDisableDamageAndPickups:
                {
                    g_PlayerInvincible = TRUE;
                    Offset += AI_BondDisableDamageAndPickups_LENGTH;
                    break;
                }
                case AI_BondHideWeapons:
                {
                    /*"remove guntype %d\n" */
                    remove_item_in_hand(GUNRIGHT);
                    remove_item_in_hand(GUNLEFT);
                    Offset += AI_BondHideWeapons_LENGTH;
                    break;
                }
                case AI_CameraOrbitPad: //sp order from xbla
                {
                    AIRecord *ai = AiListp + Offset;
                    s32       padnum;
                    s32       speed60;
                    s32       camDististance;
                    s32       targetHeight;
                    s32       camHeight;
                    s32       start;
                    camDististance          = CharArrayTo16(ai->val, 0);
                    camHeight               = (s16)CharArrayTo16(ai->val, 2);
                    speed60                 = (s16)CharArrayTo16(ai->val, 4);
                    padnum                  = CharArrayTo16(ai->val, 6);
                    targetHeight            = (s16)CharArrayTo16(ai->val, 8);
                    start                   = CharArrayTo16(ai->val, 10);
                    dword_CODE_bss_800799F8 = NULL;
                    gBondViewCutscene       = NULL;
                    flt_CODE_bss_80079A00   = (start * M_TAU_F) / M_U16_MAX_VALUE_F;   /*unit direction 0 - 1 (increments are 0.000001) */
                    flt_CODE_bss_80079A04   = (speed60 * M_TAU_F) / M_U16_MAX_VALUE_F; /*how many increments per frame */
                    flt_CODE_bss_80079A08   = camDististance;
                    flt_CODE_bss_80079A0C   = camHeight;
                    flt_CODE_bss_80079A10   = targetHeight;
                    dword_CODE_bss_80079A14 = padnum;
                    set_camera_mode(CAMERAMODE_POSEND);
                    Offset += AI_CameraOrbitPad_LENGTH;
                    break;
                }
                case AI_CreditsRoll:
                {
                    D_8003643C = TRUE;
                    Offset += AI_CreditsRoll_LENGTH;
                    break;
                }
                case AI_IFCreditsHasCompleted:
                {
                    AIRecord *ai = AiListp + Offset;
                    if (D_8003643C == 2)
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[0]);
                    }
                    else
                    {
                        Offset += AI_IFCreditsHasCompleted_LENGTH;
                    }
                    break;
                }
                case AI_IFObjectiveAllCompleted:
                {
                    AIRecord *ai = AiListp + Offset;
                    //bool a = objectiveIsAllComplete();
                    if (objectiveIsAllComplete())
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[0]);
                    }
                    else
                    {
                        Offset += AI_IFObjectiveAllCompleted_LENGTH;
                    }
                    break;
                }
                case AI_IFFolderActorIsEqual:
                {
                    AIRecord *ai = AiListp + Offset;
                    if (getSelectedFolderBond() == (s8)ai->val[0])
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[1]);
                    }
                    else
                    {
                        Offset += AI_IFFolderActorIsEqual_LENGTH;
                    }
                    break;
                }
                case AI_IFBondDamageAndPickupsDisabled:
                {
                    AIRecord *ai = AiListp + Offset;
                    if (g_PlayerInvincible)
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[0]);
                    }
                    else
                    {
                        Offset += AI_IFBondDamageAndPickupsDisabled_LENGTH;
                    }
                    break;
                }
                case AI_MusicPlaySlot:
                {
                    AIRecord *ai = AiListp + Offset;
                    Offset += AI_MusicPlaySlot_LENGTH;
                    musicPlaySlot((s8)ai->val[0], ai->val[1], ai->val[2]);
#ifdef ENABLE_LOG
                    osSyncPrintf("ai: enery tune on (%d, %d, %d)\n", ai->val[0], ai->val[1], ai->val[2]);
#endif
                    break;
                }
                case AI_MusicStopSlot:
                {
                    AIRecord *ai = AiListp + Offset;
                    Offset += AI_MusicStopSlot_LENGTH;
                    musicStopSlot((s8)ai->val[0]);
#ifdef ENABLE_LOG
                    osSyncPrintf("ai: enery tune off (%d)\n", ai->val[0]);
#endif
                    break;
                }
                case AI_TriggerExplosionsAroundBond:
                {
                    SurroundWithExplosions(0);
                    Offset += AI_TriggerExplosionsAroundBond_LENGTH;
                    break;
                }
                case AI_IFKilledCiviliansGreaterThan:
                {
                    AIRecord *ai = AiListp + Offset;
                    if (ai->val[0] < get_civilian_casualties())
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[1]);
                    }
                    else
                    {
                        Offset += AI_IFKilledCiviliansGreaterThan_LENGTH;
                    }
                    break;
                }
                case AI_IFChrWasShotSinceLastCheck:
                {
                    AIRecord  *ai  = AiListp + Offset;
                    ChrRecord *chr = chrFindById(ChrEntityp, ai->val[0]);
                    if (chr && chr->chrflags & CHRFLAG_WAS_HIT)
                    {
                        chr->chrflags &= ~CHRFLAG_WAS_HIT;
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[1]);
                    }
                    else
                    {
                        Offset += AI_IFChrWasShotSinceLastCheck_LENGTH;
                    }
                    break;
                }
                case AI_BondKilledInAction:
                {
                    g_isBondKIA = TRUE;
                    Offset += AI_BondKilledInAction_LENGTH;
                    break;
                }
                case AI_RaiseArms:
                {
                    chrTrySurprisedSurrender(ChrEntityp);
                    Offset += AI_RaiseArms_LENGTH;
                    break;
                }
                case AI_GasLeakAndFadeFog:
                {
                    coord3d emitPos = New_Coord3d();
                    init_trigger_toxic_gas_effect(&emitPos);
                    Offset += AI_GasLeakAndFadeFog_LENGTH;
                    break;
                }
                case AI_ObjectRocketLaunch:
                {
                    AIRecord1    *ai  = AiListp + Offset;
                    ObjectRecord *obj = objFindByTagId(ai->val);

                    if (obj && obj->prop)
                    {
                        sub_GAME_7F03FDA8(obj->prop);

                        if (obj->runtime_bitflags & RUNTIMEBITFLAG_DEPOSIT)
                        {
                            obj->projectile->flags |= 0x601;
                            projectileSetSticky(obj->prop);
                            matrix_4x4_set_identity(&obj->projectile->mtx);
                            obj->projectile->speed.x = 0;
                            obj->projectile->speed.y = 0.016666666f; //step height?
                            obj->projectile->speed.z = 0;
                            obj->projectile->unk10.x = 0;
                            obj->projectile->unk10.y = 0.29166666f; //direction to move?
                            obj->projectile->unk10.z = 0;
                        }
                    }
                    Offset += AI_ObjectRocketLaunch_LENGTH;
                    break;
                } //============================================================================================================
#endif
                default:
                    /*
                     * No Command found, advance ailist by 1. 
                     * This is attempting to handle situations where the command 
                     * type is invalid by passing over them and continuing 
                     * execution.  
                     * chraiitemsize returns 1 which is pointless really 
                     * could have done it here without a jump 
                     *
                     * Outcome:crash 
                     */
                    {
                        Offset += chraiitemsize(AiListp, Offset);
                    }
            } // switch
        }     // for
    }         // Has ailist
#ifdef ENABLE_LOG
    osSyncPrintf("SERIOUS AI ERROR!!!!!! Null ailist!\n");
#endif
}             //ai()
