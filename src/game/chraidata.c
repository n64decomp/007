/*========================================================================
 * chraidata.c
 *
 * Global AI Data to be used by any Setup.
 * 
 *========================================================================*/
/**************************************************************************
 *
 *  $REVISION: 1.0 $
 *  $DATE: 2022/02/24 20:31:28 $
 *  $SOURCE: /src/game/chraidata.c,v $
 *
 **************************************************************************/
#include <ultra64.h>
#include <bondgame.h>
#include <bondaicommands.h>
#include "chrobjdata.h"

#pragma region Private Members

/*private enum, only accessable from within this file */
static enum lbl
{
    lblZero,
    lblLoop,
    lblDone,
    lblNext,
    lblWaiting,
    lblAlarmActivated,
    lblStoppedMoving,
    lblSeesBond,
    lblKneel             = 11,
    lbl12,
    lblBuddyShot,
    lblCloneContinue,
    lblRunToObjective,
    lblNearMiss,
    lblDead,
    /*Big Gap? wonder why*/
    lblRunning           = 27,
    lblResetAndRunAgain,
    lblAbleToRun,
    lblSitRep,
    lblCheckDistance     = 36,
    lblRun               = 40,
    lblMaybeThrowGrenade = 43,
    lblCheckDistance2    = 45,
    lbl46,
    lblInvincibleCheck
};


/* global ai lists used for all levels */
/* data */

/*D:80037070 */
/**
    Try aiming at bond, otherwise do nothing
    @return No Return - AI List can only be changed by a 3rd party via SetChrAiList
 */
u8 m_AimAtBond[] = { 
    TRYAimAtBond(lblLoop)
    YIELD_FOREVER(lblLoop)
    EndList()
};

/*D:8003707C */
/**
    Dead or Removed AI. 
    Use when AI has no more to do (or use YIELD_FOREVER)
    @return No Return - AI List can only be changed by a 3rd party via SetChrAiList
*/
u8 m_DeadAI[] = {
    /*AI_PRINT,'d','y','e','n','g','\0',*/
    YIELD_FOREVER(lblDead)
    EndList()
};

/*D:80037084 */
/**
    Stand Guard and Kill Time or patrol (Not typicaly used for patrolling). 
    While killing time, play Idle animations 
    On detecting Bond, Send a clone OR Run to Bond and Attack. 
    This AI List is used by nearly all guards either as default or as a result
    of detecting Bond or finishing their assigned behaivior.
    @return No Return - AI List can only be changed by a 3rd party via SetChrAiList
 */
u8 m_StandardGuard[] = {
    /*
        THIS is used for CALL functions that return to this script.
        This is the only example available in Global AI where a script will
        return to itself - therefor the only example of CALL too.
    */
    #define THIS GAILIST_STANDARD_GUARD 

    DO(lblLoop)
        IFImDyingOrDead(lblDead)    /* guard died, safely end list */
        IFImOnPatrolOrStopped(lblStoppedMoving) /* guard has stopped moving, safe to continue */
        /*ELSE*/
        CONTINUE(lblLoop)
        
        
        Label(lblStoppedMoving)
            /*Jump table*/
            IFISeeBond(lblSeesBond)
            IFIWasShotRecently(lblBuddyShot) 
            IFIHeardBondRecently(lblCloneContinue)        
            IFBondMissedMe(lblNearMiss)                      
            IFISeeSomeoneShot(lblBuddyShot)                    
            IFISeeSomeoneDie(lblBuddyShot)                     
            IFPlayingAnimation(lblNext)        /*CONTNUE*/
            IFNewRandomGreaterThan(1, lblNext) /* 1/255 chance of playing new animation else continue */
            /*Default*/ 
            CALL( GAILIST_PLAY_IDLE_ANIMATION) /* play idle animation and return to list */
    
        Label(lblNext) 

    LOOP(lblLoop)
    
    
    Label(lblNearMiss) /* bond shot near guard */
        IFNewRandomGreaterThan(127, lblSeesBond) /* 50% chance of playing looking around animation */
        CALL( GAILIST_STARTLE_AND_RUN_TO_BOND)
        
    Label(lblSeesBond) /* guard sees bond */
        CALL( GAILIST_ATTACK_BOND)
        
    Label(lblBuddyShot) /* guard saw someone shot/die or guard was shot themselves */
        CALL( GAILIST_RUN_TO_BOND)
        
    Label(lblCloneContinue) /* guard heard bond, attempt to spawn clone (only if chr has clone flag) */
        SetReturnAiList(THIS) // This command is useless
        JumpTo(GAILIST_TRY_CLONE_SEND_OR_RUN_TO_BOND)
        
    Label(lblDead) /* guard has died, end routine */
        JumpTo( GAILIST_DEAD_AI)
    EndList()

    /*Undefine THIS and redefine for every script that wants to CALL subroutines*/
    #undef THIS
};

/*D:800370DC */
/**
    Play one random idle animation 
    @return to caller if called with CALL 
    -or-
    return to List set by SetReturnAiList - If not set will crash
 */
u8 m_IdleAnimations[] = {
#if 0
    IFNewRandomGreaterThan(50, lblNext) /* generate annd compare random seed to see which animation to play */
    PlayAnimation(ANIM_yawning, 0, 193, ANIM_IDLE_POSE_WHEN_COMPLETE | ANIM_PLAY_SFX, ANIM_DEFAULT_INTERPOLATION)
        GotoNext(lblDone) /* jump to end, we're done */
    
    Label(lblNext)
        IFRandomGreaterThan(100, lblNext)
        PlayAnimation(ANIM_swatting_flies, 0, 294, ANIM_IDLE_POSE_WHEN_COMPLETE | ANIM_PLAY_SFX, ANIM_DEFAULT_INTERPOLATION)
        GotoNext(lblDone) /* jump to end, we're done */
        
    Label(lblNext)
        IFRandomGreaterThan(150, lblNext)
        PlayAnimation(ANIM_scratching_leg, 0, 183, ANIM_IDLE_POSE_WHEN_COMPLETE | ANIM_PLAY_SFX, ANIM_DEFAULT_INTERPOLATION)
        GotoNext(lblDone) /* jump to end, we're done */
        
    Label(lblNext)
        IFRandomGreaterThan(200, lblNext)
        PlayAnimation(ANIM_scratching_butt, 0, 123, ANIM_IDLE_POSE_WHEN_COMPLETE | ANIM_PLAY_SFX, ANIM_DEFAULT_INTERPOLATION)
        GotoNext(lblDone) /* jump to end, we're done */
        
    Label(lblNext)
        IFRandomGreaterThan(250, lblNext)
        PlayAnimation(ANIM_adjusting_crotch, 0, 56, ANIM_IDLE_POSE_WHEN_COMPLETE | ANIM_PLAY_SFX, ANIM_DEFAULT_INTERPOLATION)
        GotoNext(lblDone) /* jump to end, we're done */
        
    Label(lblNext)
        PlayAnimation(ANIM_sneeze, 0, 137, ANIM_IDLE_POSE_WHEN_COMPLETE | ANIM_PLAY_SFX, ANIM_DEFAULT_INTERPOLATION)
        GotoNext(lblDone) /* jump to end, we're done */
        
    Label(lblDone)
#else
    SWITCH(SetNewRandom(),
        IFRandomGreaterThan, 250,
            PlayAnimation(ANIM_sneeze          , 0, 137, ANIM_IDLE_POSE_WHEN_COMPLETE | ANIM_PLAY_SFX, ANIM_DEFAULT_INTERPOLATION)
            BREAK,
        IFRandomGreaterThan,200,
            PlayAnimation(ANIM_adjusting_crotch, 0,  56, ANIM_IDLE_POSE_WHEN_COMPLETE | ANIM_PLAY_SFX, ANIM_DEFAULT_INTERPOLATION)
            BREAK,
        IFRandomGreaterThan,150,
            PlayAnimation(ANIM_scratching_butt , 0, 123, ANIM_IDLE_POSE_WHEN_COMPLETE | ANIM_PLAY_SFX, ANIM_DEFAULT_INTERPOLATION)
            BREAK,
        IFRandomGreaterThan,100,
            PlayAnimation(ANIM_scratching_leg  , 0, 183, ANIM_IDLE_POSE_WHEN_COMPLETE | ANIM_PLAY_SFX, ANIM_DEFAULT_INTERPOLATION)
            BREAK,
        IFRandomGreaterThan,50, 
            PlayAnimation(ANIM_swatting_flies  , 0, 294, ANIM_IDLE_POSE_WHEN_COMPLETE | ANIM_PLAY_SFX, ANIM_DEFAULT_INTERPOLATION)
            BREAK,
        /*DEFAULT*/,,
            PlayAnimation(ANIM_yawning         , 0, 193, ANIM_IDLE_POSE_WHEN_COMPLETE | ANIM_PLAY_SFX, ANIM_DEFAULT_INTERPOLATION)
            BREAK,
    )
#endif
    Return()
    EndList()
};

/*D:8003713C */
/**
    Bash that Keyboard once with a random animation
    @return to caller if called with CALL 
    -or-
    return to List set by SetReturnAiList - If not set will crash
 */
u8 m_BashKeyboard[] = {
    #if 0
    IFNewRandomGreaterThan(60, lblNext)
    PlayAnimation(ANIM_keyboard_right_hand1, 0, 69, 0x00, ANIM_DEFAULT_INTERPOLATION)
    GotoNext(lblDone) /* jump to end, we're done */
    
    Label(lblNext)
        IFRandomGreaterThan(120, lblNext)
        PlayAnimation(ANIM_keyboard_right_hand2, 0, 74, 0x00, ANIM_DEFAULT_INTERPOLATION)
        GotoNext(lblDone) /* jump to end, we're done */
        
    Label(lblNext)
        IFRandomGreaterThan(180, lblNext)
        PlayAnimation(ANIM_keyboard_left_hand, 0, 79, 0x00, ANIM_DEFAULT_INTERPOLATION)
        GotoNext(lblDone) /* jump to end, we're done */
        
    Label(lblNext)
        PlayAnimation(ANIM_keyboard_right_hand_tapping, 0, 89, 0x00, ANIM_DEFAULT_INTERPOLATION)
        GotoNext(lblDone) /* jump to end, we're done */
    Label(lblDone)
        #endif
    SWITCH(SetNewRandom(),
        IFRandomGreaterThan,180,
            PlayAnimation(ANIM_keyboard_right_hand_tapping, 0, 89, 0x00, ANIM_DEFAULT_INTERPOLATION)
            BREAK,
        IFRandomGreaterThan,120,
            PlayAnimation(ANIM_keyboard_left_hand, 0, 79, 0x00, ANIM_DEFAULT_INTERPOLATION)
            BREAK,
        IFRandomGreaterThan,60,
            PlayAnimation(ANIM_keyboard_right_hand2, 0, 74, 0x00, ANIM_DEFAULT_INTERPOLATION)
            BREAK,
        /*DEFAULT*/,, 
            PlayAnimation(ANIM_keyboard_right_hand1, 0, 69, 0x00, ANIM_DEFAULT_INTERPOLATION)
            BREAK,
    )

    Return()
    EndList()};

/*D:8003717C */
/**
    Stand Guard Statically (No Clones, No animations) or patrol.
    On detecting Bond (sight/near-miss only), Act like a Standard Guard. 
    @return to Standard Guard
 */
u8 m_SimpleGuardDeaf[] = { 
    DO(lblLoop) /* wait for guard to stop moving before branching to next logic */
        IFImOnPatrolOrStopped(lblStoppedMoving)
        /*ELSE*/
        CONTINUE(lblLoop)
        
        Label(lblStoppedMoving)
            IFISeeBond(lblSeesBond)
            IFIWasShotRecently(lblBuddyShot)
            IFBondMissedMe(lblNearMiss)
            IFISeeSomeoneShot(lblBuddyShot)
            IFISeeSomeoneDie(lblBuddyShot)
    LOOP(lblLoop)
        
        
    Label(lblNearMiss) /* bond shot near guard */
        IFNewRandomGreaterThan(127, lblSeesBond) /* 50% chance of playing looking around animation */
        JUMPTO_THEN_GUARD( GAILIST_STARTLE_AND_RUN_TO_BOND)
        
    Label(lblSeesBond) /* guard sees bond */
        JUMPTO_THEN_GUARD( GAILIST_ATTACK_BOND)
        
    Label(lblBuddyShot) /* guard saw another guard shot/die or guard was shot */
        JUMPTO_THEN_GUARD( GAILIST_RUN_TO_BOND)
    EndList()
};

/*D:800371B4 */
/**
    Attack Bond once via 1 random animation
    @return to caller if called with CALL
    -or-
    return to List set by SetReturnAiList - If not set will crash
 */
u8 m_AttackBond[] = {
    #if 0 //Doesnt work any simpler 
    IFMyFlags2Has(FLAGS2_DONT_POINT_AT_BOND, lblNext) /* if guard already pointed at bond */
    /*ELSE*/
        IFNewRandomGreaterThan(32, lblNext)           /* 12.5% chance of pointing to bond */
        PointAtBond()
        SetMyFlags2(FLAGS2_DONT_POINT_AT_BOND)        /* don't point again, thank you object permanence */
        Return()                                      /* guard pointed at bond, return to list */

    Label(lblNext)                                    
        SetMyFlags2(FLAGS2_DONT_POINT_AT_BOND)        /* I am awayer of Bond, set flag so we don't point at bond */
        SWITCH(/*SetNewRandom()*/EMPTY,
               IFRandomGreaterThan,127,
                    IFNewRandomGreaterThan(127, lblKneel)
                    TRYFireAtBond(lblDone)
                    Label(lblKneel)
                       TRYFireAtBondKneeling,
               IFNewRandomGreaterThan, 64,
                   TRYFiringRun,
               IFNewRandomGreaterThan,50,
                   TRYFiringWalk,                     /* infinite ammo death sentence ;) */
               IFNewRandomGreaterThan,25,
                   TRYSideRunning,
               IFNewRandomGreaterThan,10,
                   TRYSidestepping,
               IFNewRandomGreaterThan,10, 
                   TRYSideHopping,
               /*DEFAULT*/,,
                   TRYFiringRoll,
               ,,
                   TRYThrowingGrenade                 /* attempt to throw grenade, depends on chr->grenadeprob value */
           )
    #else  
    IFMyFlags2Has(FLAGS2_DONT_POINT_AT_BOND, lblNext) /* if guard already pointed at bond */
    IFNewRandomGreaterThan(32, lblNext)               /* 12.5% chance of pointing to bond */
    PointAtBond()
    SetMyFlags2(FLAGS2_DONT_POINT_AT_BOND)            /* don't point again, thank you object permanence */
    Return()                                          /* guard pointed at bond, return to list */

    Label(lblNext)                                    /*Not a switch*/
        SetMyFlags2(FLAGS2_DONT_POINT_AT_BOND)        /* I am awayer of Bond, set flag so we don't point at bond */
        TRYThrowingGrenade(lblDone)                   /* attempt to throw grenade, depends on chr->grenadeprob value */
        
    Label(lblNext)
        IFNewRandomGreaterThan(10, lblNext)
        TRYFiringRoll(lblDone)
        
    Label(lblNext)
        IFNewRandomGreaterThan(10, lblNext)
        TRYSideHopping(lblDone)
        
    Label(lblNext)
        IFNewRandomGreaterThan(25, lblNext)
        TRYSidestepping(lblDone)
        
    Label(lblNext)
        IFNewRandomGreaterThan(50, lblNext)
        TRYSideRunning(lblDone)
        
    Label(lblNext)
        IFNewRandomGreaterThan(64, lblNext)
        TRYFiringWalk(lblDone)                        /* infinite ammo death sentence ;) */
        
    Label(lblNext)
        IFRandomGreaterThan(127, lblNext)
        TRYFiringRun(lblDone)
        
    Label(lblNext)
        IFNewRandomGreaterThan(127, lblKneel)
        TRYFireAtBond(lblDone)
        
    Label(lblKneel)
        TRYFireAtBondKneeling(lblDone)

    Label(lblDone)                                    /* guard did the thing, now go back home */
#endif

    Return()
    EndList() 
};

/*D:8003720C */
/**
    Run to bond and fire if seen, otherwise wait.
    @return to caller if called with CALL
    -or-
    return to List set by SetReturnAiList - If not set will crash
 */
u8 m_RunToBond[] = { 
    SetMyFlags2(FLAGS2_DONT_POINT_AT_BOND) /* guard is aware of bond, so don't point at him when first spotted */
    TRYRunToBond(lblLoop)                  /* goto loop if bond position is reachable */
    Return()                               /* if guard can't reach bond, return to ai list (read TRYRunToBond command info) */

    DO(lblLoop)
        IFImOnPatrolOrStopped(lblStoppedMoving)
        IFISeeBond(lblSeesBond)            /* executes every frame instead of "at ready" state */
    LOOP(lblLoop)
        
    Label(lblSeesBond)
        JumpTo( GAILIST_ATTACK_BOND)
        
    Label(lblStoppedMoving)
        Return()
        EndList()
};

/*D:80037224 */
/**
    If Calling Chr NOT been seen, Send Clone after Bond, otherwise Act like a 
    Standard Guard
    @return to Standard Guard
 */
u8 m_TryCloneSendOrRunToBond[] = { 
    SetMyFlags2(FLAGS2_DONT_POINT_AT_BOND)            /* I am aware of bond, so won't point at him */
    IFIveNotBeenSeen(lblCloneContinue)                              
    JumpTo( GAILIST_RUN_TO_BOND)                                    
    
    Label(lblCloneContinue)
        IFMyCloneDoesNotExist(lblCloneContinue)       /* Ive not been seen, test for clone existance */
        JumpTo( GAILIST_STANDARD_GUARD)               /* we only want 1 clone */
        
    Label(lblCloneContinue)                           /* clone didnt exist, create one */
        TRYCloningMe(GAILIST_STANDARD_CLONE, lblNext) /* Assign AI to clone */
        JumpTo( GAILIST_RUN_TO_BOND)                  /* clone failed to spawn (not enough memory/guard doesn't have clone flag on),
                                                         Its all down to me now. */

    Label(lblNext)                                    /* if clone spawn was successful */
        JumpTo( GAILIST_STANDARD_GUARD)               /* I'll sit tight while the clone does all the work, giving the
                                                         illusion that the level is a crowded complex */
    EndList()
};

/*D:80037248 */
/**
    Run to bond then act like a Standard Guard
    @return to Standard Guard
 */
u8 m_StandardClone[] = { 
    JUMPTO_THEN_GUARD( GAILIST_RUN_TO_BOND)
    EndList()
};

/*D:80037250 */
/**
    Stand Guard Statically (No Clones, No animations) or patrol (Typical Use of this type). 
    On detecting Bond, Act like a Standard Guard.
    @return to Standard Guard
 */
u8 m_SimpleGuard[] = {
    /* Simple Detection Loop */
    DO(lblLoop) 
        IFISeeBond(lblSeesBond)
        IFIWasShotRecently(lblBuddyShot)
        IFIHeardBondRecently(lblBuddyShot)
        IFBondMissedMe(lblBuddyShot)
        IFISeeSomeoneShot(lblBuddyShot)
        IFISeeSomeoneDie(lblBuddyShot)
    LOOP(lblLoop)
        
    Label(lblSeesBond)      /* guard sees bond */
        JUMPTO_THEN_GUARD( GAILIST_ATTACK_BOND)
        
    Label(lblBuddyShot)     /* guard saw another guard shot/die or guard was shot */
        JUMPTO_THEN_GUARD( GAILIST_RUN_TO_BOND)
        
    Label(lblCloneContinue) /* unused spawn clone reaction for hearing bond, likely made game too difficult/slow */
        JUMPTO_THEN_GUARD( GAILIST_TRY_CLONE_SEND_OR_RUN_TO_BOND)
    EndList()
};

/*D:80037280 */
/**
    Stand Guard Statically (No Clones, No animations) or patrol. 
    On detecting Bond, Run to padpreset1 and activate alarm. 
    Act like a Standard Guard thereafter
    @return to Standard Guard
 */
u8 m_SimpleGuardAlarmRaiser[] = { 
         
    DO(lblLoop) 
        IFImOnPatrolOrStopped(lblStoppedMoving)                               
        /*ELSE*/
        CONTINUE(lblLoop)
        
        Label(lblStoppedMoving)
            IFISeeBond(lblRunToObjective)
            IFMyNumCloseArghsGreaterThan(0, lblNearMiss)
            IFIHeardBondRecently(lblNearMiss)
            IFISeeSomeoneShot(lblNearMiss)
            IFISeeSomeoneDie(lblNearMiss)
    LOOP(lblLoop)
        

    Label(lblNearMiss)                                              /* a guard in sight was killed/shot, heard bond or bond shot guard */
        IFMyNumArghsGreaterThan(0, lblRunToObjective)               /* doesn't make sense why the guard would be mildly curious about getting shot */
        LookSurprised()
        
    DO(lblWaiting)                                                  /* wait for guard to stop moving before branching to next logic (triggered by look around animation) */
        IFImOnPatrolOrStopped(lblRunToObjective)
    LOOP(lblWaiting)
        
    Label(lblRunToObjective)
        RunToPad(PAD_PRESET1)
        
    DO(lblNext)                                                     /* wait for guard to stop moving (reached destination/guard was shot) */
        IFImOnPatrolOrStopped(lblDone)
    LOOP(lblNext)
        
    Label(lblDone)
        IFMyDistanceToPadGreaterThanMeter( 1, PAD_PRESET1, lblDone) /* if guard is more than 1 meter away from alarm, skip to attack ai list */
        TRYTriggeringAlarmAtPad(PAD_PRESET1, lblAlarmActivated)
        GotoNext(lblDone)                                           /* didn't activate alarm (alarm destroyed?) */
        
    DO(lblAlarmActivated)                                           /* wait for guard to finish activating alarm */
        IFImOnPatrolOrStopped(lblDone)
    LOOP(lblAlarmActivated)
        
    Label(lblDone)
        JUMPTO_THEN_GUARD( GAILIST_RUN_TO_BOND)
    EndList()
};

/*D:800372D0 */
/**
    Startle character then Run To Bond
    @return to caller if called with CALL -or- return to List set by SetReturnAiList - If not set will crash
 */
u8 m_StartleAndRunToBond[] = { 
    LookSurprised() /* trigger animation */
    DO(lblLoop)
        IFImOnPatrolOrStopped(lblDone) /* wait for chr to stop moving */
    LOOP(lblLoop)
        
    Label(lblDone) /* chr stopped moving */
        JumpTo( GAILIST_RUN_TO_BOND)
    EndList()
};

/*D:800372E0 */
/**
    Persistently chase Bond and Attack (halt randomly)
    @return No Return - AI List can only be changed by a 3rd party via SetChrAiList
 */
u8 m_RunToBondPersistent[] = { 
           
    /*DO*/
    Label(lblRun)
        TRYRunToBond(lblRunning)                                               /* goto loop if bond position is reachable */
        AI_PRINT,'n','o',' ','g','o','!','\n','\0',                                                      /* guard can't reach bond */
        
        DO(lblRunning)
            IFICouldSeeBond(lblStoppedMoving)
            IFImOnPatrolOrStopped(lblDone)
        LOOP(lblRunning)
        
        DO(lblLoop)                                                            /*Check Hits and Stopped/Patrol State*/
            IFMyNumArghsLessThan(6, lblCheckDistance2)
            /*ELSE*/IFMychrflagsHas(CHRFLAG_INVINCIBLE, lblInvincibleCheck) /*BREAK*/
        
            Label(lblCheckDistance2)
            IFImOnPatrolOrStopped(lblStoppedMoving)
            /*// BUG - this causes guard to shuffle about uselessly if Bond & guard are within line of sight and over 20 meters */
            IFMyDistanceToBondGreaterThanMeter(20, lblNext)                    /* if guard is further than 20 meters away from bond, break */
        LOOP(lblLoop)
                
        Label(lblNext)
            CONTINUE(lblRun)
        
        Label(lblStoppedMoving)
            IFICouldSeeBond(lblNext)                                           /*If Not invincible, do Attack loop*/
            GotoNext(lblDone)                                                  /*Goto end of Attack Switch*/
        
        Label(lblCheckDistance)
            Yield()
            IFMyDistanceToBondLessThanMeter(5, lblNext) /*BREAK*/
            /* OR */ IFImOnPatrolOrStopped(lblNext)     /*BREAK*/
    LOOP(lblRun)

    Label(lblNext)
        IFMychrflagsHas(CHRFLAG_INVINCIBLE, lblInvincibleCheck)                /*Check Hits, Unset flags and Loop Attack Options*/
        
    /*DO*/
    Label(lblMaybeThrowGrenade)
        #if 0
            IFNewRandomGreaterThan(10, lblNext)
            TRYThrowingGrenade(lblDone) /* depends on chr->grenadeprob value */
        
        Label(lblNext)
            IFRandomGreaterThan(50, lblNext)
            TRYSidestepping(lblDone)
        
        Label(lblNext)
            IFRandomGreaterThan(60, lblNext)
            TRYFiringRoll(lblDone)
        
        Label(lblNext)
            IFRandomGreaterThan(80, lblNext)
            TRYFiringRoll(lblDone)
        
        Label(lblNext)
            IFRandomGreaterThan(100, lblNext)
            TRYFiringWalk(lblDone)

        Label(lblNext)
            IFRandomGreaterThan(150, lblNext)
            TRYFiringRun(lblDone)

        Label(lblNext)
            IFRandomGreaterThan(200, lblNext)
            TRYFireAtBond(lblDone)

        Label(lblNext)
            TRYFireAtBondKneeling(lblDone)

        Label(lblDone)
        #else
            SWITCH(SetNewRandom(),
                IFRandomGreaterThan,200,
                    TRYFireAtBondKneeling,
                IFRandomGreaterThan, 150,
                    TRYFireAtBond,
                IFRandomGreaterThan, 100,
                    TRYFiringRun,
                IFRandomGreaterThan,80,
                    TRYFiringWalk,                    
                IFRandomGreaterThan,60,
                    TRYFiringRoll,
                IFRandomGreaterThan,50,
                    TRYFiringRoll,
                IFRandomGreaterThan,10, 
                    TRYSidestepping,
                /*DEFAULT*/,,
                    TRYThrowingGrenade,
            )/*lblDone*/
        #endif
            IFICouldSeeBond(lblNext)
            GotoNext(lblRunning)

        Label(lblRunning)
            Yield()
            IFNewRandomGreaterThan(160, lblNext)
            GotoNext(lblResetAndRunAgain)

        Label(lblNext)
            Yield() 
            GotoFirst(lblLoop)                                                 /*Check Hits and Stopped/Patrol State*/

        Label(lblResetAndRunAgain)
            MyTimerStart()
            TRYRunToBond(lblAbleToRun)

        DO(lblAbleToRun)
            IFImOnPatrolOrStopped(lblNext)
            IFMyTimerGreaterThanSeconds(1, lblNext)
        LOOP(lblAbleToRun)

        Label(lblNext)
            Stop()
            AI_PRINT,'w','a','i','t','\n','\0',
            UnsetMyFlags2(FLAGS2_04)
            IFNewRandomGreaterThan(160, lblNext)
            SetMyFlags2(FLAGS2_04)

        Label(lblNext)
            MyTimerStart()

        DO(lblSitRep)
            IFICouldSeeBond(lblNext)/*BREAK*/
            IFBondMissedMe(lblNext) /*BREAK*/
            Yield()
            IFMyTimerLessThanSeconds(10, lblWaiting) 
            IFMyFlags2Has(FLAGS2_04, lblAlarmActivated)
            GotoFirst(lblRun)

            Label(lblAlarmActivated)
                GotoFirst(lblResetAndRunAgain)

            Label(lblWaiting)
        LOOP(lblSitRep)

        Label(lblNext)
            GotoFirst(lblLoop)                                                 /*Check Hits and Stopped/Patrol State*/


        Label(lblInvincibleCheck)                                              /*Check Hits, Unset flags and Loop Attack Options*/
            IFMyNumArghsLessThan(6, lblNext)
            UnsetMychrflags(CHRFLAG_INVINCIBLE)

        Label(lblNext)
    LOOP(lblMaybeThrowGrenade)
    EndList()
};

/*D : 800373D0 */
/** 
    Wait for one second then return
    @return to caller if called with CALL -or- return to List set by SetReturnAiList - If not set will crash
 */
u8 m_WaitOneSecond[] = { 
    MyTimerStart()
    DO(lblRunning)
        IFMyTimerGreaterThanSeconds(1, lblNext) /* wait one second */
    LOOP(lblRunning)

    Label(lblNext)
        Return()
        EndList()
};

/*D:800373E0*/ 
/**
    Exit level and set BG AI to nothing
    @return No Return - AI is Dead
 */
u8 m_EndLevel[] = { 
    EndLevel()
    JumpTo( GAILIST_DEAD_AI)
    EndList()
};

/*D:800373E8*/
/**
    Draw TT33, Aim and fire.
    Act like a Standard Guard thereafter
    @return to Standard Guard
 */
u8 m_DrawPistolAndAttackBond[] = { 
    SetMySpeedRating(40) /* fast boi watch out! */
    SetMyAccuracyRating(50)

    Label(lblNext)
        TRYFacingBond(lblNext)

    Label(lblNext)
        MyTimerStart()

    DO(lblRunning)
        IFMyTimerGreaterThanTicks(20, lblNext) /* wait 1/3 of a second */
    LOOP(lblRunning)
        
    Label(lblNext)
        PlayAnimation(ANIM_fire_standing_draw_one_handed_weapon_fast,
                      0,
                      20,
                      ANIM_LOOP_HOLD_LAST_FRAME,
                      ANIM_DEFAULT_INTERPOLATION)

    DO(lblResetAndRunAgain)
        IFImOnPatrolOrStopped(lblNext)
    LOOP(lblResetAndRunAgain)

    Label(lblNext)
        TRYGiveMeItem(PROP_CHRTT33, ITEM_TT33, 0, lblNext)

    Label(lblNext)
        TRYAimAtBond( lblNext)       /* aim... */

    Label(lblNext)
        TRYFireAtBondUpdate(lblNext) /* FIRE! */

    Label(lblNext)
        DO(lblSitRep)                /* loop until chr has stopped firing at bond */
            IFImOnPatrolOrStopped(lblNext)
        LOOP(lblSitRep)

    Label(lblNext)
        JUMPTO_THEN_GUARD( GAILIST_RUN_TO_BOND)
    EndList()
};

/*D:80037444*/
/**
    Remove Calling chr and set AI to nothing
    @return No Return - AI is Dead
 */
u8 m_RemoveSelf[] = { 
    RemoveMeInstantly() /* remove self */
    JumpTo( GAILIST_DEAD_AI)
    EndList()
};

#pragma endregion Private Members

/*D:8003744C */
/* global ai lists (glists) */
AIListRecord g_GlobalAILists[] = { 
    {m_AimAtBond               , GAILIST_AIM_AT_BOND},
    {m_DeadAI                  , GAILIST_DEAD_AI},
    {m_StandardGuard           , GAILIST_STANDARD_GUARD},
    {m_IdleAnimations          , GAILIST_PLAY_IDLE_ANIMATION},
    {m_BashKeyboard            , GAILIST_BASH_KEYBOARD},
    {m_SimpleGuardDeaf         , GAILIST_SIMPLE_GUARD_DEAF},
    {m_AttackBond              , GAILIST_ATTACK_BOND},
    {m_SimpleGuard             , GAILIST_SIMPLE_GUARD},
    {m_RunToBond               , GAILIST_RUN_TO_BOND},
    {m_SimpleGuardAlarmRaiser  , GAILIST_SIMPLE_GUARD_ALARM_RAISER},
    {m_StartleAndRunToBond     , GAILIST_STARTLE_AND_RUN_TO_BOND},
    {m_TryCloneSendOrRunToBond , GAILIST_TRY_CLONE_SEND_OR_RUN_TO_BOND},
    {m_StandardClone           , GAILIST_STANDARD_CLONE},
    {m_RunToBondPersistent     , GAILIST_PERSISTENTLY_CHASE_AND_ATTACK_BOND},
    {m_WaitOneSecond           , GAILIST_WAIT_ONE_SECOND},
    {m_EndLevel                , GAILIST_END_LEVEL},
    {m_DrawPistolAndAttackBond , GAILIST_DRAW_TT33_AND_ATTCK_BOND},
    {m_RemoveSelf              , GAILIST_REMOVE_CHR}
};
                     
/*D:800374DC */
u32 D_800374DC[] = {0,0};

/*D:800374E4 */
char *setup_text_pointers[] = {
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, "UsetupsevbunkerZ",
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,"UsetupsiloZ",
    "UsetupsevbunkerZ","UsetupstatueZ","UsetupcontrolZ","UsetuparchZ","UsetuptraZ",
    "UsetupdestZ","UsetupsevbZ","UsetupaztZ","UsetuppeteZ","UsetupdepoZ","UsetuprefZ",
    "UsetupcrypZ","UsetupdamZ","UsetuparkZ","UsetuprunZ","UsetupsevxZ","UsetupjunZ",
    "UsetupdishZ","UsetupcaveZ","UsetupcatZ","UsetupcradZ","UsetupshoZ","UsetupsevxbZ",
    "UsetupeldZ","UsetupimpZ","UsetupashZ","UsetuplueZ","UsetupameZ","UsetupritZ",
    "UsetupoatZ","UsetupearZ","UsetupleeZ","UsetuplipZ","UsetuplenZ","UsetupwaxZ",
    "UsetuppamZ", NULL, NULL
};


    
