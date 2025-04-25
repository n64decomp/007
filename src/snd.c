#include <ultra64.h>
#include <PR/libaudio.h>
#include <os_extension.h>
#include "music.h"
#include "snd.h"

/**
 * EU .data, offset from start of data_seg : 0x3620
*/

/**
 * @file snd.c
 * This file contains code to deal with snd.
 */

#define DEFAULT_SETUP_PITCH_SHIFT (-0x1770)

/**
 * Based on \n64devkit\ultra\usr\src\pr\libsrc\libultra\audio\sndp.h
 * ALSndpEvent
 */
typedef union ALSndpEvent_u {

    struct {
        // offset 0
        u16             type;
        // offset 4
        ALSoundState    *state;
    } common;

    struct {
        u16             type;
        ALSoundState    *state;
        s32             vol;
    } vol;

    struct {
        u16             type;
        ALSoundState    *state;
        f32             pitch;
    } pitch;

    struct {
        u16             type;
        ALSoundState    *state;
        s32           pan32;
    } pan32;

    struct {
        u16             type;
        ALSoundState    *state;
        s32             mix32;
    } fx32;

    struct {
        u16 type;
        ALSoundState *state;
        s32 soundIndex;
        struct ALBankAlt_s *soundBank;
    } playSfx;

    struct {
        s16 type;
        ALSoundState *state;
        s32 val8;
        s32 valc;
    } unks32;

    struct {
        s32 unk0;
        s32 unk4;
        s32 unk8;
        s32 unkC;
    } align_size;

} ALSndpEvent;

union ALSndpSmallEvent_u {
    struct {
        u16 type;
        ALSoundState *state;
    } msg;

    union {
        s32 unk0;
        s32 unk4;
    } align_size;
};

// TODO: is this struct really the answer?
// 800243E4
struct D_800243E4_s {
    // address 800243E4 and 800243E8
    ALLink node;
    // address 800243EC
    struct ALSoundState_s *g_sndPlayerSoundStatePtr;
};

s32 g_sndUnused800243E0 = 0;

// // TODO: is this struct really the answer?
struct D_800243E4_s D_800243E4 = { {NULL, NULL}, NULL};

ALSndPlayer *g_sndPlayerPtr = &g_sndPlayer;

/**
 * Current number of allocated voices, via alSynAllocVoice
 */
s16 g_sndAllocatedVoicesCount = 0;

/**
 * Boot flag. If set, sound is disabled.
 */
s8 g_sndBootswitchSound = 0;

/**
 * Used in level load/setup, sound effect slot volume will be scaled by this amount.
 */
f32 g_sndSfxVolumeScale = 1.0;

// forward declarations

ALMicroTime sndPlayerVoiceHandler(void *node);
void sndHandleEvent(ALSndPlayer *sndp, ALSndpEvent *event);
void sndDisposeSound(ALSoundState *state);
void sndCreatePitchEvent(ALSoundState *state);
void sndRemoveEvents(ALEventQueue *evtq, ALSoundState *state, u16 eventType);
s32 sndCountAllocList(s16 *allocListCount, s16 *freeListCount);
ALSoundState *sndSetupSound(struct ALBankAlt_s *soundBank, ALSound* sound);
void sndUnlinkClearSound(ALSoundState *state);
void sndSetPriority(ALSoundState *state, u8 priority);
u8 sndGetPlayingState(ALSoundState *state);
void sndDeactivateAllSfxByFlag(u8 flag);
void sndDeactivateAllSfxByFlag_1(void);
void sndDeactivateAllSfxByFlag_11(void);
void sndDeactivateAllSfxByFlag_3(void);
u16 sndGetSfxSlotFirstNaturalVolume(void);
void sndApplyVolumeAllSfxSlot(u16 arg0);
void sndSetScalerApplyVolumeAllSfxSlot(f32 arg0);
u16 sndGetSfxSlotNaturalVolume(u8 arg0);
void sndSetSfxSlotVolume(u8 arg0, u16 arg1);

// end forward declarations

/**
 * 8720    70007B20
 *
 * Mostly identical to n64devkit\ultra\usr\src\pr\libsrc\libultra\audio\sndplayer.c
 * method alSndpNew.
 */
void sndNewPlayerInit(ALSeqpSfxConfig *sfxSeqpConfig)
{
    u8 *ptr;
    struct ALSoundState_s *sState;
    ALEvent evt;
    u32 i;

    /*
     * Init member variables
     */
    g_sndPlayerPtr->maxSounds = sfxSeqpConfig->maybeMaxSounds;
    g_sndPlayerPtr->target = 0;
    g_sndPlayerPtr->frameTime = AL_USEC_PER_FRAME_30FPS;
    sState = alHeapAlloc(sfxSeqpConfig->heap, 1, sfxSeqpConfig->maybeSndStateCount * sizeof(struct ALSoundState_s));
    g_sndPlayerPtr->sndState = sState;

    /*
     * init the event queue
     */
    ptr = alHeapAlloc(sfxSeqpConfig->heap, 1, sfxSeqpConfig->maxEvents * sizeof(ALEventListItem));
    alEvtqNew(&g_sndPlayerPtr->evtq, (ALEventListItem *)ptr, sfxSeqpConfig->maxEvents);

    D_800243E4.g_sndPlayerSoundStatePtr = g_sndPlayerPtr->sndState;

    for(i = 1; i < sfxSeqpConfig->maybeSndStateCount; i++)
    {
        // The compiler says this reassignment matters ...
        sState = (struct ALSoundState_s*)g_sndPlayerPtr->sndState;

        // this works because `ALLink node` is at offset zero.
        alLink((ALLink*)(&sState[i]), (ALLink*)(&sState[i]-1));
    }

    g_sndSfxSlotVolume = alHeapAlloc(sfxSeqpConfig->heap, sizeof(s16), SFX_SLOT_COUNT);
    g_sndSfxSlotNaturalVolume = alHeapAlloc(sfxSeqpConfig->heap, sizeof(s16), SFX_SLOT_COUNT);

    for(i = 0; i < SFX_SLOT_COUNT; i++)
    {
        g_sndSfxSlotNaturalVolume[i] = \
            g_sndSfxSlotVolume[i] = (s16)0x7FFF;
    }

    /*
     * add ourselves to the driver
     */
    g_sndPlayerPtr->drvr = &alGlobals->drvr;
    g_sndPlayerPtr->node.next = NULL;
    g_sndPlayerPtr->node.handler = &sndPlayerVoiceHandler;
    g_sndPlayerPtr->node.clientData = g_sndPlayerPtr;
    alSynAddPlayer(g_sndPlayerPtr->drvr, &g_sndPlayerPtr->node);

    /*
     * Start responding to API events
     */
    evt.type = AL_SNDP_API_EVT;
    alEvtqPostEvent(&g_sndPlayerPtr->evtq, (ALEvent *)&evt, g_sndPlayerPtr->frameTime);
    g_sndPlayerPtr->nextDelta = alEvtqNextEvent(&g_sndPlayerPtr->evtq, &g_sndPlayerPtr->nextEvent);
}

/**
 * 89DC    70007DDC
 *
 * Almost identical to \n64devkit\ultra\usr\src\pr\libsrc\libultra\audio\sndplayer.c
 * method ALMicroTime _sndpVoiceHandler(void *node).
 */
ALMicroTime sndPlayerVoiceHandler(void *node)
{
    ALSndPlayer *sndp = (ALSndPlayer *) node;
    ALSndpEvent evt;

    do
    {
        switch (sndp->nextEvent.type)
        {
            case (AL_SNDP_API_EVT):
                evt.common.type = (s16)AL_SNDP_API_EVT;
                alEvtqPostEvent(&sndp->evtq, (ALEvent *)&evt, sndp->frameTime);
                break;

            default:
                sndHandleEvent(sndp, (ALSndpEvent *)&sndp->nextEvent);
                break;
        }

        sndp->nextDelta = alEvtqNextEvent(&sndp->evtq, &sndp->nextEvent);

    } while (sndp->nextDelta == 0);

    sndp->curTime += sndp->nextDelta;

    return sndp->nextDelta;
}


/**
 * 8A80    70007E80
 *
 * Draws inspiration from n64devkit\ultra\usr\src\pr\libsrc\libultra\audio\sndplayer.c
 * method _handleEvent
 *
 * decomp status:
 * - compiles: yes
 * - stack resize: ok
 * - identical instructions: yes
 * - identical registers: fail
 *
 * Notes:
 * - all floating point registers match
 * - there's a few places with temp variables and MIN,MAX macros, stuffing it all into one
 *   line generally causes increase of +2 lines to match, but the temp registers seem
 *   to get more shifted. I don't know if that's an improvement.
 * - ran decomp-permuter on the whole method for ~12 hours, and then targetting just
 *   the areas before and after the switch block for ~12 hours, but it never found
 *   any improvements.
 * - there's an assigment `voice = &state->voice;` that I factored out. Doesn't seem
 *   to make a difference, it's present in sndplayer.c _handleEvent ...
 */
#ifdef NONMATCHING
// https://decomp.me/scratch/2v3fu 97.63%
void sndHandleEvent(ALSndPlayer *sndp, ALSndpEvent *event)
{
    // declarations

                                        ////
                                        //// "..." means not explicitly referenced by stack offset
                                        ////
    ALVoiceConfig vc;                   // sp 0xc8; priority=200, fxBus=202, unityPitch=204
    ALSoundState *state;                // ...
    ALSoundState *tstate;               // ...
    s32 stack_size_3;                   // ...
    ALVoice *voice_factored_out;        // ...
    s16 tmp;                            // ...
    s16 vol;                            // ...
    union ALSndpSmallEvent_u stopEvent; // sp 0xac = 172,176
    ALSndpEvent evt;                    // sp 0x9c; 156,160,164,168
    ALSound *snd;                       // ...
    ALKeyMap *keyMap;                   // ...
    s32 vtmp;                           // sp 0x90 = 144
    ALMicroTime delta;                  // ...
    s32 msgtype;                        // ...
    u8 aaa; // using "pan" u8 space
    ALPan pan;                          // ...
    s32 done_state;                     // sp 0x80 = 128
    s32 allocVoiceSuccess;              // sp 0x7c = 124
    ALSoundState *prevState;            // sp 0x78 = 120
    ALSoundState *nextState;            // sp 0x74 = 116 ; could also be ALLink (with sp78)
    s16 sp72;                           // sp 0x72 = 114
    s16 sp70;                           // sp 0x70 = 112
    ALSoundState *loopCheckVar[1];      // sp 0x6c = 108
    s32 compare_result;                 // ...
    s32 stack_size_4;
    union ALSndpSmallEvent_u playAllocEvent;    // sp 0x5c = 92,96

    // done with declarations

    done_state = 1;
    allocVoiceSuccess = 0;
    nextState = NULL;
    // // typo/mistake, prevState is unitialized.
    state = (void*)prevState;

    while (1)
    {
        if (nextState)
        {
            evt.common.state = state;
            evt.common.type = event->common.type;
            evt.unks32.val8 = event->unks32.val8;
            event = (ALSndpEvent *)&evt;
        }

        state = event->common.state;
        snd = state->sound;

        if (snd == NULL)
        {
            sndCountAllocList(&sp72, &sp70);
            return;
        }

        keyMap = snd->keyMap;
        nextState = (ALSoundState *)state->link.next;

        switch (event->common.type)
        {
            case (AL_SNDP_PLAY_EVT):
            {
                if ((state->playingState == AL_UNKOWN_5) || (state->playingState == AL_UNKOWN_4))
                {
                    // comment copied from sndplayer: effect buss 0
                    vc.fxBus = 0;
                    vc.priority = state->priority;
                    vc.unityPitch = 0;
                    //voice = &state->voice;

                    compare_result = ((s32)g_sndAllocatedVoicesCount >= sndp->maxSounds);

                    if ((!compare_result) || (state->unk3e & 0x10))
                    {
                        allocVoiceSuccess = alSynAllocVoice(sndp->drvr, &state->voice, &vc);
                    }

                    if (!allocVoiceSuccess)
                    {
                        if ((state->unk3e & 0x12) || (state->unk38 > 0))
                        {
                            state->playingState = AL_UNKOWN_4;
                            state->unk38--;
                            alEvtqPostEvent(&sndp->evtq, (ALEvent*)event, DELTA_33_MS);

                            return;
                        }

                        if (compare_result)
                        {
                            tstate = (ALSoundState*)D_800243E4.node.prev;
                            do
                            {
                                if (
                                    ((state->unk3e & 0x12) == 0)
                                    && (state->unk3e & 4)
                                    && (tstate->playingState != AL_UNKOWN_3))
                                {
                                    playAllocEvent.common.type = AL_SNDP_END_EVT;
                                    playAllocEvent.msg.state = tstate;
                                    tstate->playingState = AL_UNKOWN_3;
                                    compare_result = 0;
                                    loopCheckVar[0] = tstate;

                                    alEvtqPostEvent(&sndp->evtq, (ALEvent *)&playAllocEvent, DELTA_1_MS);

                                    tstate = loopCheckVar[0];
                                    //voice = &tstate->voice;
                                    alSynSetVol(sndp->drvr, (ALVoice*)&tstate->voice, 0, DELTA_1_MS);

                                    tstate = loopCheckVar[0];
                                }

                                tstate = (ALSoundState *)tstate->link.prev;
                            }
                            while (compare_result != 0 && tstate != NULL);

                            if (compare_result == 0)
                            {
                                state->unk38 = 2;
                                alEvtqPostEvent(&sndp->evtq, (ALEvent*)event, DELTA_1_MS + 1);
                                return;
                            }

                            sndDisposeSound(state);
                            return;
                        }

                        sndDisposeSound(state);
                        return;
                    }

                    state->unk3e = state->unk3e | 4;
                    alSynStartVoice(sndp->drvr, &state->voice, snd->wavetable);

                    state->playingState = AL_PLAYING;
                    g_sndAllocatedVoicesCount++;

                    delta = (ALMicroTime)((f32)snd->envelope->attackTime / state->pitch_2c / state->pitch_28);

                    aaa = keyMap->keyMin & 0x3f;
                    tmp = g_sndSfxSlotVolume[aaa];
                    vol = state->vol;
                    vtmp = ((vol * (snd->envelope->attackVolume * snd->sampleVolume)) / (AL_VOL_FULL * AL_VOL_FULL)) * tmp;
                    vtmp = vtmp / 0x7fff;
                    vtmp = MAX(0, vtmp - 1);

                    // vtmp = MAX(0, (vol * (snd->envelope->attackVolume * snd->sampleVolume)
                    //     / (AL_VOL_FULL * AL_VOL_FULL)
                    //     * tmp
                    //     / 0x7fff) - 1);

                    alSynSetVol(sndp->drvr, &state->voice, 0, 0);
                    alSynSetVol(sndp->drvr, &state->voice, vtmp, delta);

                    vtmp = state->pan - AL_PAN_CENTER + snd->samplePan;
                    pan = (ALPan) MIN(MAX(vtmp, AL_PAN_LEFT), AL_PAN_RIGHT);
                    //pan = (ALPan) MIN(MAX(state->pan - AL_PAN_CENTER + snd->samplePan, AL_PAN_LEFT), AL_PAN_RIGHT);

                    alSynSetPan(sndp->drvr, &state->voice, pan);
                    alSynSetPitch(sndp->drvr, &state->voice, state->pitch_2c * state->pitch_28);

                    vtmp = (state->fxMix + (keyMap->keyMax & 0xf)) * 8;
                    vtmp = MIN(AL_VOL_FULL, MAX(AL_DEFAULT_FXMIX, vtmp));
                    //vtmp = MIN(AL_VOL_FULL, MAX(AL_DEFAULT_FXMIX, (state->fxMix + (keyMap->keyMax & 0xf)) * 8));
                    alSynSetFXMix(sndp->drvr, &state->voice, vtmp);

                    stopEvent.common.type = AL_SNDP_DECAY_EVT;
                    stopEvent.msg.state = state;
                    delta = (ALMicroTime)((f32)snd->envelope->attackTime / state->pitch_2c / state->pitch_28);
                    alEvtqPostEvent(&sndp->evtq, (ALEvent *)&stopEvent, delta);
                }
                else
                {
                    return;
                }
            }
            break;

            case (AL_SNDP_DEACTIVATE_EVT): // fallthrough
            case (AL_SNDP_UNKNOWN_12_EVT): // fallthrough
            case (AL_SNDP_STOP_EVT):
            {
                if (event->common.type != AL_SNDP_UNKNOWN_12_EVT
                    || (state->unk3e & 0x2)
                )
                {
                    switch (state->playingState)
                    {
                        case (AL_PLAYING):
                        {
                            sndRemoveEvents(&sndp->evtq, state, AL_SNDP_DECAY_EVT);

                            delta = (ALMicroTime)((f32)snd->envelope->releaseTime / state->pitch_28 / state->pitch_2c);
                            alSynSetVol(sndp->drvr, (ALVoice *)&state->voice, 0, delta);

                            if (delta)
                            {
                                stopEvent.common.type = AL_SNDP_END_EVT;
                                stopEvent.msg.state = state;
                                alEvtqPostEvent(&sndp->evtq, (ALEvent *)&stopEvent, delta);
                                state->playingState = AL_STOPPING;
                            }
                            else
                            {
                                sndDisposeSound(state);
                            }
                        }
                        break;

                        case (AL_UNKOWN_4): // fallthrough
                        case (AL_UNKOWN_5):
                        {
                            sndDisposeSound(state);
                        }
                        break;

                        default:
                            // nothing to do
                        break;
                    }

                    if (event->common.type == AL_SNDP_STOP_EVT)
                    {
                        event->common.type = AL_SNDP_UNKNOWN_12_EVT;
                    }
                }
            }
            break;

            case (AL_SNDP_PAN_EVT):
            {
                state->pan = event->pan32.pan32;

                if (state->playingState == AL_PLAYING)
                {
                    vtmp = state->pan - AL_PAN_CENTER + snd->samplePan;
                    pan = (ALPan) MIN(MAX(vtmp, AL_PAN_LEFT), AL_PAN_RIGHT);
                    //pan = (ALPan) MIN(MAX(state->pan - AL_PAN_CENTER + snd->samplePan, AL_PAN_LEFT), AL_PAN_RIGHT);

                    alSynSetPan(sndp->drvr, &state->voice, pan);
                }
            }
            break;

            case (AL_SNDP_PITCH_EVT):
            {
                state->pitch_2c = event->pitch.pitch;

                if (state->playingState == AL_PLAYING)
                {
                    alSynSetPitch(sndp->drvr, &state->voice, state->pitch_2c * state->pitch_28);

                    if (state->unk3e & 0x20)
                    {
                        sndCreatePitchEvent(state);
                    }
                }
            }
            break;

            case (AL_SNDP_FX_EVT):
            {
                state->fxMix = event->fx32.mix32;

                if (state->playingState == AL_PLAYING)
                {
                    vtmp = (state->fxMix + (keyMap->keyMax & 0xf)) * 8;
                    vtmp = MIN(AL_VOL_FULL, MAX(AL_DEFAULT_FXMIX, vtmp));
                    //vtmp = MIN(AL_VOL_FULL, MAX(AL_DEFAULT_FXMIX, (state->fxMix + (keyMap->keyMax & 0xf)) * 8));

                    alSynSetFXMix(sndp->drvr, &state->voice, vtmp);
                }
            }
            break;

            case (AL_SNDP_VOL_EVT):
            {
                state->vol = event->vol.vol;
                if (state->playingState == AL_PLAYING)
                {
                    tmp = g_sndSfxSlotVolume[keyMap->keyMin & 0x3f];
                    vol = state->vol;
                    vtmp =
                        vol * (snd->envelope->decayVolume * snd->sampleVolume)
                        / (AL_VOL_FULL * AL_VOL_FULL)
                        * tmp
                        / 0x7fff;
                    vtmp = MAX(0, vtmp - 1);

                    // vtmp = MAX(0, (vol * (snd->envelope->decayVolume * snd->sampleVolume)
                    //     / (AL_VOL_FULL * AL_VOL_FULL)
                    //     * tmp
                    //     / 0x7fff) - 1);

                    alSynSetVol(sndp->drvr, (ALVoice *)&state->voice, vtmp, DELTA_1_MS);
                }
            }
            break;

            // case 0x20 (AL_SNDP_API_EVT)
            // handled in sndPlayerVoiceHandler

            case (AL_SNDP_RELEASE_EVT):
            {
                if (state->playingState == AL_PLAYING)
                {
                    delta = ((f32)snd->envelope->releaseTime / state->pitch_28 / state->pitch_2c);

                    tmp = g_sndSfxSlotVolume[keyMap->keyMin & 0x3f];
                    vol = state->vol;
                    vtmp =
                        vol * (snd->envelope->decayVolume * snd->sampleVolume)
                        / (AL_VOL_FULL * AL_VOL_FULL)
                        * tmp
                        / 0x7fff;
                    vtmp = MAX(0, vtmp - 1);

                    // vtmp = MAX(0, (vol * (snd->envelope->decayVolume * snd->sampleVolume)
                    //     / (AL_VOL_FULL * AL_VOL_FULL)
                    //     * tmp
                    //     / 0x7fff) - 1);

                    alSynSetVol(sndp->drvr, &state->voice, vtmp, delta);
                }
            }
            break;

            case (AL_SNDP_DECAY_EVT):
            {
                if ((state->unk3e & 2) == 0)
                {
                    tmp = g_sndSfxSlotVolume[keyMap->keyMin & 0x3f];
                    vol = state->vol;
                    vtmp =
                        (vol * (snd->envelope->decayVolume * snd->sampleVolume)
                        / (AL_VOL_FULL * AL_VOL_FULL))
                        * tmp
                        / 0x7fff;

                    vtmp = MAX(0, vtmp - 1);

                    // can't seem to combine this volume computation into one line with the macro.

                    delta = (ALMicroTime)((f32)snd->envelope->decayTime / state->pitch_28 / state->pitch_2c);
                    alSynSetVol(sndp->drvr, &state->voice, vtmp, delta);

                    stopEvent.common.type = AL_SNDP_STOP_EVT;
                    stopEvent.msg.state = state;
                    alEvtqPostEvent(&sndp->evtq, (ALEvent *)&stopEvent, delta);

                    if ((state->unk3e & 0x20) != 0)
                    {
                        sndCreatePitchEvent(state);
                    }
                }
            }
            break;

            case (AL_SNDP_END_EVT):
            {
                sndDisposeSound(state);
            }
            break;

            case (AL_SNDP_PLAY_SFX_EVT):
            {
                if ((state->unk3e & 0x10) != 0)
                {
                    sndPlaySfx((struct ALBankAlt_s *)event->playSfx.soundBank, event->playSfx.soundIndex, state->state);
                }
            }
            break;

            default:
                // not supported
            break;
        }

        msgtype = event->common.type & 0x2d1;
        state = nextState;

        if (state == NULL || msgtype != 0)
        {
            // do nothing
        }
        else
        {
            done_state =
                // best guess at cast to get offset 0x3e ...
                ((ALSoundState*)event)->unk3e & 0x1;
        }

        if (done_state || state == NULL)
        {
            break;
        }
        else if (msgtype == 0)
        {
            continue;
        }
        else
        {
            prevState = state;
            break;
        }
    }

    if (prevState)
    {
        // removed
    }
}
#else
GLOBAL_ASM(
.text
glabel sndHandleEvent
/* 008A80 70007E80 27BDFF30 */  addiu $sp, $sp, -0xd0
/* 008A84 70007E84 AFBE0038 */  sw    $fp, 0x38($sp)
/* 008A88 70007E88 AFB70034 */  sw    $s7, 0x34($sp)
/* 008A8C 70007E8C AFB5002C */  sw    $s5, 0x2c($sp)
/* 008A90 70007E90 AFB1001C */  sw    $s1, 0x1c($sp)
/* 008A94 70007E94 240E0001 */  li    $t6, 1
/* 008A98 70007E98 00A0A825 */  move  $s5, $a1
/* 008A9C 70007E9C 0080B825 */  move  $s7, $a0
/* 008AA0 70007EA0 AFBF003C */  sw    $ra, 0x3c($sp)
/* 008AA4 70007EA4 AFB60030 */  sw    $s6, 0x30($sp)
/* 008AA8 70007EA8 AFB40028 */  sw    $s4, 0x28($sp)
/* 008AAC 70007EAC AFB30024 */  sw    $s3, 0x24($sp)
/* 008AB0 70007EB0 AFB20020 */  sw    $s2, 0x20($sp)
/* 008AB4 70007EB4 AFB00018 */  sw    $s0, 0x18($sp)
/* 008AB8 70007EB8 AFAE0080 */  sw    $t6, 0x80($sp)
/* 008ABC 70007EBC AFA0007C */  sw    $zero, 0x7c($sp)
/* 008AC0 70007EC0 AFA00074 */  sw    $zero, 0x74($sp)
/* 008AC4 70007EC4 8FB10078 */  lw    $s1, 0x78($sp)
/* 008AC8 70007EC8 241E0001 */  li    $fp, 1
/* 008ACC 70007ECC 8FAF0074 */  lw    $t7, 0x74($sp)
.L70007ED0:
/* 008AD0 70007ED0 51E00008 */  beql  $t7, $zero, .L70007EF4
/* 008AD4 70007ED4 8EB10004 */   lw    $s1, 4($s5)
/* 008AD8 70007ED8 AFB100A0 */  sw    $s1, 0xa0($sp)
/* 008ADC 70007EDC 96B80000 */  lhu   $t8, ($s5)
/* 008AE0 70007EE0 A7B8009C */  sh    $t8, 0x9c($sp)
/* 008AE4 70007EE4 8EB90008 */  lw    $t9, 8($s5)
/* 008AE8 70007EE8 27B5009C */  addiu $s5, $sp, 0x9c
/* 008AEC 70007EEC AFB900A4 */  sw    $t9, 0xa4($sp)
/* 008AF0 70007EF0 8EB10004 */  lw    $s1, 4($s5)
.L70007EF4:
/* 008AF4 70007EF4 8E320008 */  lw    $s2, 8($s1)
/* 008AF8 70007EF8 16400005 */  bnez  $s2, .L70007F10
/* 008AFC 70007EFC 27A40072 */   addiu $a0, $sp, 0x72
/* 008B00 70007F00 0C0022BC */  jal   sndCountAllocList
/* 008B04 70007F04 27A50070 */   addiu $a1, $sp, 0x70
/* 008B08 70007F08 10000284 */  b     .L7000891C
/* 008B0C 70007F0C 8FBF003C */   lw    $ra, 0x3c($sp)
.L70007F10:
/* 008B10 70007F10 8E280000 */  lw    $t0, ($s1)
/* 008B14 70007F14 8E560004 */  lw    $s6, 4($s2)
/* 008B18 70007F18 AFA80074 */  sw    $t0, 0x74($sp)
/* 008B1C 70007F1C 96A30000 */  lhu   $v1, ($s5)
/* 008B20 70007F20 28610101 */  slti  $at, $v1, 0x101
/* 008B24 70007F24 1420000C */  bnez  $at, .L70007F58
/* 008B28 70007F28 00601025 */   move  $v0, $v1
/* 008B2C 70007F2C 24010200 */  li    $at, 512
/* 008B30 70007F30 1041025D */  beq   $v0, $at, .L700088A8
/* 008B34 70007F34 24010400 */   li    $at, 1024
/* 008B38 70007F38 10410113 */  beq   $v0, $at, .L70008388
/* 008B3C 70007F3C 24010800 */   li    $at, 2048
/* 008B40 70007F40 104101D3 */  beq   $v0, $at, .L70008690
/* 008B44 70007F44 24011000 */   li    $at, 4096
/* 008B48 70007F48 50410110 */  beql  $v0, $at, .L7000838C
/* 008B4C 70007F4C 24011000 */   li    $at, 4096
/* 008B50 70007F50 10000261 */  b     .L700088D8
/* 008B54 70007F54 306202D1 */   andi  $v0, $v1, 0x2d1
.L70007F58:
/* 008B58 70007F58 28410041 */  slti  $at, $v0, 0x41
/* 008B5C 70007F5C 14200007 */  bnez  $at, .L70007F7C
/* 008B60 70007F60 24010080 */   li    $at, 128
/* 008B64 70007F64 1041024A */  beq   $v0, $at, .L70008890
/* 008B68 70007F68 24010100 */   li    $at, 256
/* 008B6C 70007F6C 50410177 */  beql  $v0, $at, .L7000854C
/* 008B70 70007F70 922E003F */   lbu   $t6, 0x3f($s1)
/* 008B74 70007F74 10000258 */  b     .L700088D8
/* 008B78 70007F78 306202D1 */   andi  $v0, $v1, 0x2d1
.L70007F7C:
/* 008B7C 70007F7C 28410011 */  slti  $at, $v0, 0x11
/* 008B80 70007F80 14200006 */  bnez  $at, .L70007F9C
/* 008B84 70007F84 2449FFFF */   addiu $t1, $v0, -1
/* 008B88 70007F88 24010040 */  li    $at, 64
/* 008B8C 70007F8C 504101F8 */  beql  $v0, $at, .L70008770
/* 008B90 70007F90 9239003E */   lbu   $t9, 0x3e($s1)
/* 008B94 70007F94 10000250 */  b     .L700088D8
/* 008B98 70007F98 306202D1 */   andi  $v0, $v1, 0x2d1
.L70007F9C:
/* 008B9C 70007F9C 2D210010 */  sltiu $at, $t1, 0x10
/* 008BA0 70007FA0 1020024C */  beqz  $at, .L700088D4
/* 008BA4 70007FA4 00094880 */   sll   $t1, $t1, 2
/* 008BA8 70007FA8 3C018003 */  lui   $at, %hi(jpt_80029160)
/* 008BAC 70007FAC 00290821 */  addu  $at, $at, $t1
/* 008BB0 70007FB0 8C299160 */  lw    $t1, %lo(jpt_80029160)($at) # lw    $t1, -0x6ea0($at)
/* 008BB4 70007FB4 01200008 */  jr    $t1
/* 008BB8 70007FB8 00000000 */   nop
glabel .L70007FBC
/* 008BBC 70007FBC 9222003F */  lbu   $v0, 0x3f($s1)
/* 008BC0 70007FC0 24010005 */  li    $at, 5
/* 008BC4 70007FC4 3C0B8002 */  lui   $t3, %hi(g_sndAllocatedVoicesCount)
/* 008BC8 70007FC8 10410003 */  beq   $v0, $at, .L70007FD8
/* 008BCC 70007FCC 24010004 */   li    $at, 4
/* 008BD0 70007FD0 54410252 */  bnel  $v0, $at, .L7000891C
/* 008BD4 70007FD4 8FBF003C */   lw    $ra, 0x3c($sp)
.L70007FD8:
/* 008BD8 70007FD8 A7A000CA */  sh    $zero, 0xca($sp)
/* 008BDC 70007FDC 922A0036 */  lbu   $t2, 0x36($s1)
/* 008BE0 70007FE0 A3A000CC */  sb    $zero, 0xcc($sp)
/* 008BE4 70007FE4 856B43F4 */  lh    $t3, %lo(g_sndAllocatedVoicesCount)($t3)
/* 008BE8 70007FE8 A7AA00C8 */  sh    $t2, 0xc8($sp)
/* 008BEC 70007FEC 8EEC0044 */  lw    $t4, 0x44($s7)
/* 008BF0 70007FF0 2625000C */  addiu $a1, $s1, 0xc
/* 008BF4 70007FF4 27A600C8 */  addiu $a2, $sp, 0xc8
/* 008BF8 70007FF8 016C802A */  slt   $s0, $t3, $t4
/* 008BFC 70007FFC 3A100001 */  xori  $s0, $s0, 1
/* 008C00 70008000 12000005 */  beqz  $s0, .L70008018
/* 008C04 70008004 00000000 */   nop
/* 008C08 70008008 9223003E */  lbu   $v1, 0x3e($s1)
/* 008C0C 7000800C 306D0010 */  andi  $t5, $v1, 0x10
/* 008C10 70008010 51A00006 */  beql  $t5, $zero, .L7000802C
/* 008C14 70008014 8FAE007C */   lw    $t6, 0x7c($sp)
.L70008018:
/* 008C18 70008018 0C004C96 */  jal   alSynAllocVoice
/* 008C1C 7000801C 8EE40038 */   lw    $a0, 0x38($s7)
/* 008C20 70008020 AFA2007C */  sw    $v0, 0x7c($sp)
/* 008C24 70008024 9223003E */  lbu   $v1, 0x3e($s1)
/* 008C28 70008028 8FAE007C */  lw    $t6, 0x7c($sp)
.L7000802C:
/* 008C2C 7000802C 2633000C */  addiu $s3, $s1, 0xc
/* 008C30 70008030 346F0004 */  ori   $t7, $v1, 4
/* 008C34 70008034 15C00045 */  bnez  $t6, .L7000814C
/* 008C38 70008038 02602825 */   move  $a1, $s3
/* 008C3C 7000803C 306F0012 */  andi  $t7, $v1, 0x12
/* 008C40 70008040 15E00004 */  bnez  $t7, .L70008054
/* 008C44 70008044 24190004 */   li    $t9, 4
/* 008C48 70008048 8E380038 */  lw    $t8, 0x38($s1)
/* 008C4C 7000804C 1B00000B */  blez  $t8, .L7000807C
/* 008C50 70008050 00000000 */   nop
.L70008054:
/* 008C54 70008054 8E280038 */  lw    $t0, 0x38($s1)
/* 008C58 70008058 A239003F */  sb    $t9, 0x3f($s1)
/* 008C5C 7000805C 26E40014 */  addiu $a0, $s7, 0x14
/* 008C60 70008060 2509FFFF */  addiu $t1, $t0, -1
/* 008C64 70008064 AE290038 */  sw    $t1, 0x38($s1)
/* 008C68 70008068 02A02825 */  move  $a1, $s5
/* 008C6C 7000806C 0C004BBF */  jal   alEvtqPostEvent
/* 008C70 70008070 34068235 */   li    $a2, 33333
/* 008C74 70008074 10000229 */  b     .L7000891C
/* 008C78 70008078 8FBF003C */   lw    $ra, 0x3c($sp)
.L7000807C:
/* 008C7C 7000807C 1200002F */  beqz  $s0, .L7000813C
/* 008C80 70008080 3C028002 */   lui   $v0, %hi(D_800243E4)
/* 008C84 70008084 8C4243E8 */  lw    $v0, %lo(D_800243E4+4)($v0)
/* 008C88 70008088 27B4005C */  addiu $s4, $sp, 0x5c
/* 008C8C 7000808C 24130003 */  li    $s3, 3
/* 008C90 70008090 24120003 */  li    $s2, 3
/* 008C94 70008094 9043003E */  lbu   $v1, 0x3e($v0)
.L70008098:
/* 008C98 70008098 306A0012 */  andi  $t2, $v1, 0x12
/* 008C9C 7000809C 15400016 */  bnez  $t2, .L700080F8
/* 008CA0 700080A0 306B0004 */   andi  $t3, $v1, 4
/* 008CA4 700080A4 11600014 */  beqz  $t3, .L700080F8
/* 008CA8 700080A8 00000000 */   nop
/* 008CAC 700080AC 904C003F */  lbu   $t4, 0x3f($v0)
/* 008CB0 700080B0 240D0080 */  li    $t5, 128
/* 008CB4 700080B4 26E40014 */  addiu $a0, $s7, 0x14
/* 008CB8 700080B8 124C000F */  beq   $s2, $t4, .L700080F8
/* 008CBC 700080BC 02802825 */   move  $a1, $s4
/* 008CC0 700080C0 A7AD005C */  sh    $t5, 0x5c($sp)
/* 008CC4 700080C4 AFA20060 */  sw    $v0, 0x60($sp)
/* 008CC8 700080C8 A053003F */  sb    $s3, 0x3f($v0)
/* 008CCC 700080CC 00008025 */  move  $s0, $zero
/* 008CD0 700080D0 AFA2006C */  sw    $v0, 0x6c($sp)
/* 008CD4 700080D4 0C004BBF */  jal   alEvtqPostEvent
/* 008CD8 700080D8 240603E8 */   li    $a2, 1000
/* 008CDC 700080DC 8FA2006C */  lw    $v0, 0x6c($sp)
/* 008CE0 700080E0 8EE40038 */  lw    $a0, 0x38($s7)
/* 008CE4 700080E4 00003025 */  move  $a2, $zero
/* 008CE8 700080E8 240703E8 */  li    $a3, 1000
/* 008CEC 700080EC 0C004CE8 */  jal   alSynSetVol
/* 008CF0 700080F0 2445000C */   addiu $a1, $v0, 0xc
/* 008CF4 700080F4 8FA2006C */  lw    $v0, 0x6c($sp)
.L700080F8:
/* 008CF8 700080F8 12000003 */  beqz  $s0, .L70008108
/* 008CFC 700080FC 8C420004 */   lw    $v0, 4($v0)
/* 008D00 70008100 5440FFE5 */  bnezl $v0, .L70008098
/* 008D04 70008104 9043003E */   lbu   $v1, 0x3e($v0)
.L70008108:
/* 008D08 70008108 16000008 */  bnez  $s0, .L7000812C
/* 008D0C 7000810C 240E0002 */   li    $t6, 2
/* 008D10 70008110 AE2E0038 */  sw    $t6, 0x38($s1)
/* 008D14 70008114 26E40014 */  addiu $a0, $s7, 0x14
/* 008D18 70008118 02A02825 */  move  $a1, $s5
/* 008D1C 7000811C 0C004BBF */  jal   alEvtqPostEvent
/* 008D20 70008120 240603E9 */   li    $a2, 1001
/* 008D24 70008124 100001FD */  b     .L7000891C
/* 008D28 70008128 8FBF003C */   lw    $ra, 0x3c($sp)
.L7000812C:
/* 008D2C 7000812C 0C002252 */  jal   sndDisposeSound
/* 008D30 70008130 02202025 */   move  $a0, $s1
/* 008D34 70008134 100001F9 */  b     .L7000891C
/* 008D38 70008138 8FBF003C */   lw    $ra, 0x3c($sp)
.L7000813C:
/* 008D3C 7000813C 0C002252 */  jal   sndDisposeSound
/* 008D40 70008140 02202025 */   move  $a0, $s1
/* 008D44 70008144 100001F5 */  b     .L7000891C
/* 008D48 70008148 8FBF003C */   lw    $ra, 0x3c($sp)
.L7000814C:
/* 008D4C 7000814C A22F003E */  sb    $t7, 0x3e($s1)
/* 008D50 70008150 8E460008 */  lw    $a2, 8($s2)
/* 008D54 70008154 8EE40038 */  lw    $a0, 0x38($s7)
/* 008D58 70008158 0C004D10 */  jal   alSynStartVoice
/* 008D5C 7000815C 26F40014 */   addiu $s4, $s7, 0x14
/* 008D60 70008160 24180001 */  li    $t8, 1
/* 008D64 70008164 A238003F */  sb    $t8, 0x3f($s1)
/* 008D68 70008168 3C198002 */  lui   $t9, %hi(g_sndAllocatedVoicesCount)
/* 008D6C 7000816C 873943F4 */  lh    $t9, %lo(g_sndAllocatedVoicesCount)($t9)
/* 008D70 70008170 3C018002 */  lui   $at, %hi(g_sndAllocatedVoicesCount)
/* 008D74 70008174 3C0B8006 */  lui   $t3, %hi(g_sndSfxSlotVolume)
/* 008D78 70008178 27280001 */  addiu $t0, $t9, 1
/* 008D7C 7000817C A42843F4 */  sh    $t0, %lo(g_sndAllocatedVoicesCount)($at)
/* 008D80 70008180 8E420000 */  lw    $v0, ($s2)
/* 008D84 70008184 86280034 */  lh    $t0, 0x34($s1)
/* 008D88 70008188 924A000D */  lbu   $t2, 0xd($s2)
/* 008D8C 7000818C 9059000C */  lbu   $t9, 0xc($v0)
/* 008D90 70008190 8C490000 */  lw    $t1, ($v0)
/* 008D94 70008194 92CC0002 */  lbu   $t4, 2($s6)
/* 008D98 70008198 03280019 */  multu $t9, $t0
/* 008D9C 7000819C 44892000 */  mtc1  $t1, $f4
/* 008DA0 700081A0 318D003F */  andi  $t5, $t4, 0x3f
/* 008DA4 700081A4 24013F01 */  li    $at, 16129
/* 008DA8 700081A8 8D6B3BA4 */  lw    $t3, %lo(g_sndSfxSlotVolume)($t3)
/* 008DAC 700081AC 000D7040 */  sll   $t6, $t5, 1
/* 008DB0 700081B0 468021A0 */  cvt.s.w $f6, $f4
/* 008DB4 700081B4 016E7821 */  addu  $t7, $t3, $t6
/* 008DB8 700081B8 85F80000 */  lh    $t8, ($t7)
/* 008DBC 700081BC C628002C */  lwc1  $f8, 0x2c($s1)
/* 008DC0 700081C0 00004812 */  mflo  $t1
/* 008DC4 700081C4 C6300028 */  lwc1  $f16, 0x28($s1)
/* 008DC8 700081C8 46083283 */  div.s $f10, $f6, $f8
/* 008DCC 700081CC 012A0019 */  multu $t1, $t2
/* 008DD0 700081D0 02602825 */  move  $a1, $s3
/* 008DD4 700081D4 00003025 */  move  $a2, $zero
/* 008DD8 700081D8 00003825 */  move  $a3, $zero
/* 008DDC 700081DC 00006012 */  mflo  $t4
/* 008DE0 700081E0 00000000 */  nop
/* 008DE4 700081E4 00000000 */  nop
/* 008DE8 700081E8 0181001A */  div   $zero, $t4, $at
/* 008DEC 700081EC 00006812 */  mflo  $t5
/* 008DF0 700081F0 24017FFF */  li    $at, 32767
/* 008DF4 700081F4 46105483 */  div.s $f18, $f10, $f16
/* 008DF8 700081F8 030D0019 */  multu $t8, $t5
/* 008DFC 700081FC 00002012 */  mflo  $a0
/* 008E00 70008200 00000000 */  nop
/* 008E04 70008204 00000000 */  nop
/* 008E08 70008208 0081001A */  div   $zero, $a0, $at
/* 008E0C 7000820C 4600910D */  trunc.w.s $f4, $f18
/* 008E10 70008210 00005812 */  mflo  $t3
/* 008E14 70008214 2564FFFF */  addiu $a0, $t3, -1
/* 008E18 70008218 00801825 */  move  $v1, $a0
/* 008E1C 7000821C 44102000 */  mfc1  $s0, $f4
/* 008E20 70008220 04810003 */  bgez  $a0, .L70008230
/* 008E24 70008224 00000000 */   nop
/* 008E28 70008228 10000001 */  b     .L70008230
/* 008E2C 7000822C 00001825 */   move  $v1, $zero
.L70008230:
/* 008E30 70008230 8EE40038 */  lw    $a0, 0x38($s7)
/* 008E34 70008234 0C004CE8 */  jal   alSynSetVol
/* 008E38 70008238 AFA30090 */   sw    $v1, 0x90($sp)
/* 008E3C 7000823C 8FA30090 */  lw    $v1, 0x90($sp)
/* 008E40 70008240 8EE40038 */  lw    $a0, 0x38($s7)
/* 008E44 70008244 02602825 */  move  $a1, $s3
/* 008E48 70008248 00033400 */  sll   $a2, $v1, 0x10
/* 008E4C 7000824C 00067403 */  sra   $t6, $a2, 0x10
/* 008E50 70008250 01C03025 */  move  $a2, $t6
/* 008E54 70008254 0C004CE8 */  jal   alSynSetVol
/* 008E58 70008258 02003825 */   move  $a3, $s0
/* 008E5C 7000825C 922F003C */  lbu   $t7, 0x3c($s1)
/* 008E60 70008260 9259000C */  lbu   $t9, 0xc($s2)
/* 008E64 70008264 00001025 */  move  $v0, $zero
/* 008E68 70008268 2406007F */  li    $a2, 127
/* 008E6C 7000826C 01F91821 */  addu  $v1, $t7, $t9
/* 008E70 70008270 2463FFC0 */  addiu $v1, $v1, -0x40
/* 008E74 70008274 18600003 */  blez  $v1, .L70008284
/* 008E78 70008278 02602825 */   move  $a1, $s3
/* 008E7C 7000827C 10000001 */  b     .L70008284
/* 008E80 70008280 00601025 */   move  $v0, $v1
.L70008284:
/* 008E84 70008284 2841007F */  slti  $at, $v0, 0x7f
/* 008E88 70008288 10200007 */  beqz  $at, .L700082A8
/* 008E8C 7000828C 00000000 */   nop
/* 008E90 70008290 18600003 */  blez  $v1, .L700082A0
/* 008E94 70008294 00001025 */   move  $v0, $zero
/* 008E98 70008298 10000003 */  b     .L700082A8
/* 008E9C 7000829C 306600FF */   andi  $a2, $v1, 0xff
.L700082A0:
/* 008EA0 700082A0 10000001 */  b     .L700082A8
/* 008EA4 700082A4 304600FF */   andi  $a2, $v0, 0xff
.L700082A8:
/* 008EA8 700082A8 0C004D34 */  jal   alSynSetPan
/* 008EAC 700082AC 8EE40038 */   lw    $a0, 0x38($s7)
/* 008EB0 700082B0 C626002C */  lwc1  $f6, 0x2c($s1)
/* 008EB4 700082B4 C6280028 */  lwc1  $f8, 0x28($s1)
/* 008EB8 700082B8 8EE40038 */  lw    $a0, 0x38($s7)
/* 008EBC 700082BC 02602825 */  move  $a1, $s3
/* 008EC0 700082C0 46083282 */  mul.s $f10, $f6, $f8
/* 008EC4 700082C4 44065000 */  mfc1  $a2, $f10
/* 008EC8 700082C8 0C004D58 */  jal   alSynSetPitch
/* 008ECC 700082CC 00000000 */   nop
/* 008ED0 700082D0 92C90003 */  lbu   $t1, 3($s6)
/* 008ED4 700082D4 9228003D */  lbu   $t0, 0x3d($s1)
/* 008ED8 700082D8 02602825 */  move  $a1, $s3
/* 008EDC 700082DC 312A000F */  andi  $t2, $t1, 0xf
/* 008EE0 700082E0 010A1821 */  addu  $v1, $t0, $t2
/* 008EE4 700082E4 000360C0 */  sll   $t4, $v1, 3
/* 008EE8 700082E8 05810003 */  bgez  $t4, .L700082F8
/* 008EEC 700082EC 01801825 */   move  $v1, $t4
/* 008EF0 700082F0 10000002 */  b     .L700082FC
/* 008EF4 700082F4 00001025 */   move  $v0, $zero
.L700082F8:
/* 008EF8 700082F8 00601025 */  move  $v0, $v1
.L700082FC:
/* 008EFC 700082FC 28410080 */  slti  $at, $v0, 0x80
/* 008F00 70008300 14200003 */  bnez  $at, .L70008310
/* 008F04 70008304 00000000 */   nop
/* 008F08 70008308 10000006 */  b     .L70008324
/* 008F0C 7000830C 2403007F */   li    $v1, 127
.L70008310:
/* 008F10 70008310 04610003 */  bgez  $v1, .L70008320
/* 008F14 70008314 00601025 */   move  $v0, $v1
/* 008F18 70008318 10000001 */  b     .L70008320
/* 008F1C 7000831C 00001025 */   move  $v0, $zero
.L70008320:
/* 008F20 70008320 00401825 */  move  $v1, $v0
.L70008324:
/* 008F24 70008324 8EE40038 */  lw    $a0, 0x38($s7)
/* 008F28 70008328 0C004D7C */  jal   alSynSetFXMix
/* 008F2C 7000832C 306600FF */   andi  $a2, $v1, 0xff
/* 008F30 70008330 24180040 */  li    $t8, 64
/* 008F34 70008334 A7B800AC */  sh    $t8, 0xac($sp)
/* 008F38 70008338 AFB100B0 */  sw    $s1, 0xb0($sp)
/* 008F3C 7000833C 8E4D0000 */  lw    $t5, ($s2)
/* 008F40 70008340 C624002C */  lwc1  $f4, 0x2c($s1)
/* 008F44 70008344 C6280028 */  lwc1  $f8, 0x28($s1)
/* 008F48 70008348 8DAB0000 */  lw    $t3, ($t5)
/* 008F4C 7000834C 02802025 */  move  $a0, $s4
/* 008F50 70008350 27A500AC */  addiu $a1, $sp, 0xac
/* 008F54 70008354 448B8000 */  mtc1  $t3, $f16
/* 008F58 70008358 00000000 */  nop
/* 008F5C 7000835C 468084A0 */  cvt.s.w $f18, $f16
/* 008F60 70008360 46049183 */  div.s $f6, $f18, $f4
/* 008F64 70008364 46083283 */  div.s $f10, $f6, $f8
/* 008F68 70008368 4600540D */  trunc.w.s $f16, $f10
/* 008F6C 7000836C 44068000 */  mfc1  $a2, $f16
/* 008F70 70008370 0C004BBF */  jal   alEvtqPostEvent
/* 008F74 70008374 00000000 */   nop
/* 008F78 70008378 96A20000 */  lhu   $v0, ($s5)
/* 008F7C 7000837C 304F02D1 */  andi  $t7, $v0, 0x2d1
/* 008F80 70008380 10000155 */  b     .L700088D8
/* 008F84 70008384 01E01025 */   move  $v0, $t7
glabel .L70008388
/* 008F88 70008388 24011000 */  li    $at, 4096
.L7000838C:
/* 008F8C 7000838C 54610006 */  bnel  $v1, $at, .L700083A8
/* 008F90 70008390 9222003F */   lbu   $v0, 0x3f($s1)
/* 008F94 70008394 9239003E */  lbu   $t9, 0x3e($s1)
/* 008F98 70008398 33290002 */  andi  $t1, $t9, 2
/* 008F9C 7000839C 11200035 */  beqz  $t1, .L70008474
/* 008FA0 700083A0 00000000 */   nop
/* 008FA4 700083A4 9222003F */  lbu   $v0, 0x3f($s1)
.L700083A8:
/* 008FA8 700083A8 26F40014 */  addiu $s4, $s7, 0x14
/* 008FAC 700083AC 02802025 */  move  $a0, $s4
/* 008FB0 700083B0 105E0008 */  beq   $v0, $fp, .L700083D4
/* 008FB4 700083B4 02202825 */   move  $a1, $s1
/* 008FB8 700083B8 24010004 */  li    $at, 4
/* 008FBC 700083BC 10410025 */  beq   $v0, $at, .L70008454
/* 008FC0 700083C0 24010005 */   li    $at, 5
/* 008FC4 700083C4 10410023 */  beq   $v0, $at, .L70008454
/* 008FC8 700083C8 00000000 */   nop
/* 008FCC 700083CC 10000025 */  b     .L70008464
/* 008FD0 700083D0 24010002 */   li    $at, 2
.L700083D4:
/* 008FD4 700083D4 0C00228C */  jal   sndRemoveEvents
/* 008FD8 700083D8 24060040 */   li    $a2, 64
/* 008FDC 700083DC 8E480000 */  lw    $t0, ($s2)
/* 008FE0 700083E0 C6260028 */  lwc1  $f6, 0x28($s1)
/* 008FE4 700083E4 C62A002C */  lwc1  $f10, 0x2c($s1)
/* 008FE8 700083E8 8D0A0008 */  lw    $t2, 8($t0)
/* 008FEC 700083EC 8EE40038 */  lw    $a0, 0x38($s7)
/* 008FF0 700083F0 2625000C */  addiu $a1, $s1, 0xc
/* 008FF4 700083F4 448A9000 */  mtc1  $t2, $f18
/* 008FF8 700083F8 00003025 */  move  $a2, $zero
/* 008FFC 700083FC 46809120 */  cvt.s.w $f4, $f18
/* 009000 70008400 46062203 */  div.s $f8, $f4, $f6
/* 009004 70008404 460A4403 */  div.s $f16, $f8, $f10
/* 009008 70008408 4600848D */  trunc.w.s $f18, $f16
/* 00900C 7000840C 44109000 */  mfc1  $s0, $f18
/* 009010 70008410 0C004CE8 */  jal   alSynSetVol
/* 009014 70008414 02003825 */   move  $a3, $s0
/* 009018 70008418 1200000A */  beqz  $s0, .L70008444
/* 00901C 7000841C 24180080 */   li    $t8, 128
/* 009020 70008420 A7B800AC */  sh    $t8, 0xac($sp)
/* 009024 70008424 AFB100B0 */  sw    $s1, 0xb0($sp)
/* 009028 70008428 02802025 */  move  $a0, $s4
/* 00902C 7000842C 27A500AC */  addiu $a1, $sp, 0xac
/* 009030 70008430 0C004BBF */  jal   alEvtqPostEvent
/* 009034 70008434 02003025 */   move  $a2, $s0
/* 009038 70008438 240D0002 */  li    $t5, 2
/* 00903C 7000843C 10000003 */  b     .L7000844C
/* 009040 70008440 A22D003F */   sb    $t5, 0x3f($s1)
.L70008444:
/* 009044 70008444 0C002252 */  jal   sndDisposeSound
/* 009048 70008448 02202025 */   move  $a0, $s1
.L7000844C:
/* 00904C 7000844C 10000004 */  b     .L70008460
/* 009050 70008450 96A30000 */   lhu   $v1, ($s5)
.L70008454:
/* 009054 70008454 0C002252 */  jal   sndDisposeSound
/* 009058 70008458 02202025 */   move  $a0, $s1
/* 00905C 7000845C 96A30000 */  lhu   $v1, ($s5)
.L70008460:
/* 009060 70008460 24010002 */  li    $at, 2
.L70008464:
/* 009064 70008464 14610003 */  bne   $v1, $at, .L70008474
/* 009068 70008468 240B1000 */   li    $t3, 4096
/* 00906C 7000846C A6AB0000 */  sh    $t3, ($s5)
/* 009070 70008470 3163FFFF */  andi  $v1, $t3, 0xffff
.L70008474:
/* 009074 70008474 10000118 */  b     .L700088D8
/* 009078 70008478 306202D1 */   andi  $v0, $v1, 0x2d1
glabel .L7000847C
/* 00907C 7000847C 922F003F */  lbu   $t7, 0x3f($s1)
/* 009080 70008480 8EAE0008 */  lw    $t6, 8($s5)
/* 009084 70008484 2625000C */  addiu $a1, $s1, 0xc
/* 009088 70008488 17CF0015 */  bne   $fp, $t7, .L700084E0
/* 00908C 7000848C A22E003C */   sb    $t6, 0x3c($s1)
/* 009090 70008490 9249000C */  lbu   $t1, 0xc($s2)
/* 009094 70008494 31D900FF */  andi  $t9, $t6, 0xff
/* 009098 70008498 00001025 */  move  $v0, $zero
/* 00909C 7000849C 03291821 */  addu  $v1, $t9, $t1
/* 0090A0 700084A0 2463FFC0 */  addiu $v1, $v1, -0x40
/* 0090A4 700084A4 18600003 */  blez  $v1, .L700084B4
/* 0090A8 700084A8 2406007F */   li    $a2, 127
/* 0090AC 700084AC 10000001 */  b     .L700084B4
/* 0090B0 700084B0 00601025 */   move  $v0, $v1
.L700084B4:
/* 0090B4 700084B4 2841007F */  slti  $at, $v0, 0x7f
/* 0090B8 700084B8 10200007 */  beqz  $at, .L700084D8
/* 0090BC 700084BC 00000000 */   nop
/* 0090C0 700084C0 18600003 */  blez  $v1, .L700084D0
/* 0090C4 700084C4 00001025 */   move  $v0, $zero
/* 0090C8 700084C8 10000003 */  b     .L700084D8
/* 0090CC 700084CC 306600FF */   andi  $a2, $v1, 0xff
.L700084D0:
/* 0090D0 700084D0 10000001 */  b     .L700084D8
/* 0090D4 700084D4 304600FF */   andi  $a2, $v0, 0xff
.L700084D8:
/* 0090D8 700084D8 0C004D34 */  jal   alSynSetPan
/* 0090DC 700084DC 8EE40038 */   lw    $a0, 0x38($s7)
.L700084E0:
/* 0090E0 700084E0 96A20000 */  lhu   $v0, ($s5)
/* 0090E4 700084E4 304802D1 */  andi  $t0, $v0, 0x2d1
/* 0090E8 700084E8 100000FB */  b     .L700088D8
/* 0090EC 700084EC 01001025 */   move  $v0, $t0
glabel .L700084F0
/* 0090F0 700084F0 922A003F */  lbu   $t2, 0x3f($s1)
/* 0090F4 700084F4 C6A40008 */  lwc1  $f4, 8($s5)
/* 0090F8 700084F8 17CA000F */  bne   $fp, $t2, .L70008538
/* 0090FC 700084FC E624002C */   swc1  $f4, 0x2c($s1)
/* 009100 70008500 C626002C */  lwc1  $f6, 0x2c($s1)
/* 009104 70008504 C6280028 */  lwc1  $f8, 0x28($s1)
/* 009108 70008508 8EE40038 */  lw    $a0, 0x38($s7)
/* 00910C 7000850C 2625000C */  addiu $a1, $s1, 0xc
/* 009110 70008510 46083282 */  mul.s $f10, $f6, $f8
/* 009114 70008514 44065000 */  mfc1  $a2, $f10
/* 009118 70008518 0C004D58 */  jal   alSynSetPitch
/* 00911C 7000851C 00000000 */   nop
/* 009120 70008520 922C003E */  lbu   $t4, 0x3e($s1)
/* 009124 70008524 31980020 */  andi  $t8, $t4, 0x20
/* 009128 70008528 53000004 */  beql  $t8, $zero, .L7000853C
/* 00912C 7000852C 96A20000 */   lhu   $v0, ($s5)
/* 009130 70008530 0C002271 */  jal   sndCreatePitchEvent
/* 009134 70008534 02202025 */   move  $a0, $s1
.L70008538:
/* 009138 70008538 96A20000 */  lhu   $v0, ($s5)
.L7000853C:
/* 00913C 7000853C 304D02D1 */  andi  $t5, $v0, 0x2d1
/* 009140 70008540 100000E5 */  b     .L700088D8
/* 009144 70008544 01A01025 */   move  $v0, $t5
/* 009148 70008548 922E003F */  lbu   $t6, 0x3f($s1)
.L7000854C:
/* 00914C 7000854C 8EAB0008 */  lw    $t3, 8($s5)
/* 009150 70008550 2625000C */  addiu $a1, $s1, 0xc
/* 009154 70008554 17CE0018 */  bne   $fp, $t6, .L700085B8
/* 009158 70008558 A22B003D */   sb    $t3, 0x3d($s1)
/* 00915C 7000855C 92D90003 */  lbu   $t9, 3($s6)
/* 009160 70008560 316F00FF */  andi  $t7, $t3, 0xff
/* 009164 70008564 3329000F */  andi  $t1, $t9, 0xf
/* 009168 70008568 01E91821 */  addu  $v1, $t7, $t1
/* 00916C 7000856C 000340C0 */  sll   $t0, $v1, 3
/* 009170 70008570 05010003 */  bgez  $t0, .L70008580
/* 009174 70008574 01001825 */   move  $v1, $t0
/* 009178 70008578 10000002 */  b     .L70008584
/* 00917C 7000857C 00001025 */   move  $v0, $zero
.L70008580:
/* 009180 70008580 00601025 */  move  $v0, $v1
.L70008584:
/* 009184 70008584 28410080 */  slti  $at, $v0, 0x80
/* 009188 70008588 14200003 */  bnez  $at, .L70008598
/* 00918C 7000858C 00000000 */   nop
/* 009190 70008590 10000006 */  b     .L700085AC
/* 009194 70008594 2403007F */   li    $v1, 127
.L70008598:
/* 009198 70008598 04610003 */  bgez  $v1, .L700085A8
/* 00919C 7000859C 00601025 */   move  $v0, $v1
/* 0091A0 700085A0 10000001 */  b     .L700085A8
/* 0091A4 700085A4 00001025 */   move  $v0, $zero
.L700085A8:
/* 0091A8 700085A8 00401825 */  move  $v1, $v0
.L700085AC:
/* 0091AC 700085AC 8EE40038 */  lw    $a0, 0x38($s7)
/* 0091B0 700085B0 0C004D7C */  jal   alSynSetFXMix
/* 0091B4 700085B4 306600FF */   andi  $a2, $v1, 0xff
.L700085B8:
/* 0091B8 700085B8 96A20000 */  lhu   $v0, ($s5)
/* 0091BC 700085BC 304A02D1 */  andi  $t2, $v0, 0x2d1
/* 0091C0 700085C0 100000C5 */  b     .L700088D8
/* 0091C4 700085C4 01401025 */   move  $v0, $t2
glabel .L700085C8
/* 0091C8 700085C8 9238003F */  lbu   $t8, 0x3f($s1)
/* 0091CC 700085CC 8EAC0008 */  lw    $t4, 8($s5)
/* 0091D0 700085D0 2625000C */  addiu $a1, $s1, 0xc
/* 0091D4 700085D4 17D8002A */  bne   $fp, $t8, .L70008680
/* 0091D8 700085D8 A62C0034 */   sh    $t4, 0x34($s1)
/* 0091DC 700085DC 8E480000 */  lw    $t0, ($s2)
/* 0091E0 700085E0 862C0034 */  lh    $t4, 0x34($s1)
/* 0091E4 700085E4 92CB0002 */  lbu   $t3, 2($s6)
/* 0091E8 700085E8 910A000D */  lbu   $t2, 0xd($t0)
/* 0091EC 700085EC 24013F01 */  li    $at, 16129
/* 0091F0 700085F0 316E003F */  andi  $t6, $t3, 0x3f
/* 0091F4 700085F4 014C0019 */  multu $t2, $t4
/* 0091F8 700085F8 924B000D */  lbu   $t3, 0xd($s2)
/* 0091FC 700085FC 000EC840 */  sll   $t9, $t6, 1
/* 009200 70008600 3C0D8006 */  lui   $t5, %hi(g_sndSfxSlotVolume)
/* 009204 70008604 8DAD3BA4 */  lw    $t5, %lo(g_sndSfxSlotVolume)($t5)
/* 009208 70008608 240703E8 */  li    $a3, 1000
/* 00920C 7000860C 01B97821 */  addu  $t7, $t5, $t9
/* 009210 70008610 85E90000 */  lh    $t1, ($t7)
/* 009214 70008614 0000C012 */  mflo  $t8
/* 009218 70008618 00000000 */  nop
/* 00921C 7000861C 00000000 */  nop
/* 009220 70008620 030B0019 */  multu $t8, $t3
/* 009224 70008624 00007012 */  mflo  $t6
/* 009228 70008628 00000000 */  nop
/* 00922C 7000862C 00000000 */  nop
/* 009230 70008630 01C1001A */  div   $zero, $t6, $at
/* 009234 70008634 00006812 */  mflo  $t5
/* 009238 70008638 24017FFF */  li    $at, 32767
/* 00923C 7000863C 00000000 */  nop
/* 009240 70008640 012D0019 */  multu $t1, $t5
/* 009244 70008644 00002012 */  mflo  $a0
/* 009248 70008648 00000000 */  nop
/* 00924C 7000864C 00000000 */  nop
/* 009250 70008650 0081001A */  div   $zero, $a0, $at
/* 009254 70008654 0000C812 */  mflo  $t9
/* 009258 70008658 2724FFFF */  addiu $a0, $t9, -1
/* 00925C 7000865C 04810003 */  bgez  $a0, .L7000866C
/* 009260 70008660 00801825 */   move  $v1, $a0
/* 009264 70008664 10000001 */  b     .L7000866C
/* 009268 70008668 00001825 */   move  $v1, $zero
.L7000866C:
/* 00926C 7000866C 00033400 */  sll   $a2, $v1, 0x10
/* 009270 70008670 00067C03 */  sra   $t7, $a2, 0x10
/* 009274 70008674 01E03025 */  move  $a2, $t7
/* 009278 70008678 0C004CE8 */  jal   alSynSetVol
/* 00927C 7000867C 8EE40038 */   lw    $a0, 0x38($s7)
.L70008680:
/* 009280 70008680 96A20000 */  lhu   $v0, ($s5)
/* 009284 70008684 304802D1 */  andi  $t0, $v0, 0x2d1
/* 009288 70008688 10000093 */  b     .L700088D8
/* 00928C 7000868C 01001025 */   move  $v0, $t0
.L70008690:
/* 009290 70008690 922A003F */  lbu   $t2, 0x3f($s1)
/* 009294 70008694 2625000C */  addiu $a1, $s1, 0xc
/* 009298 70008698 17CA0032 */  bne   $fp, $t2, .L70008764
/* 00929C 7000869C 00000000 */   nop
/* 0092A0 700086A0 8E420000 */  lw    $v0, ($s2)
/* 0092A4 700086A4 862A0034 */  lh    $t2, 0x34($s1)
/* 0092A8 700086A8 9258000D */  lbu   $t8, 0xd($s2)
/* 0092AC 700086AC 9048000D */  lbu   $t0, 0xd($v0)
/* 0092B0 700086B0 8C4C0008 */  lw    $t4, 8($v0)
/* 0092B4 700086B4 92CE0002 */  lbu   $t6, 2($s6)
/* 0092B8 700086B8 010A0019 */  multu $t0, $t2
/* 0092BC 700086BC 448C8000 */  mtc1  $t4, $f16
/* 0092C0 700086C0 31C9003F */  andi  $t1, $t6, 0x3f
/* 0092C4 700086C4 24013F01 */  li    $at, 16129
/* 0092C8 700086C8 3C0B8006 */  lui   $t3, %hi(g_sndSfxSlotVolume)
/* 0092CC 700086CC 8D6B3BA4 */  lw    $t3, %lo(g_sndSfxSlotVolume)($t3)
/* 0092D0 700086D0 00096840 */  sll   $t5, $t1, 1
/* 0092D4 700086D4 468084A0 */  cvt.s.w $f18, $f16
/* 0092D8 700086D8 016DC821 */  addu  $t9, $t3, $t5
/* 0092DC 700086DC 872F0000 */  lh    $t7, ($t9)
/* 0092E0 700086E0 00006012 */  mflo  $t4
/* 0092E4 700086E4 C6240028 */  lwc1  $f4, 0x28($s1)
/* 0092E8 700086E8 C628002C */  lwc1  $f8, 0x2c($s1)
/* 0092EC 700086EC 01980019 */  multu $t4, $t8
/* 0092F0 700086F0 46049183 */  div.s $f6, $f18, $f4
/* 0092F4 700086F4 00007012 */  mflo  $t6
/* 0092F8 700086F8 00000000 */  nop
/* 0092FC 700086FC 00000000 */  nop
/* 009300 70008700 01C1001A */  div   $zero, $t6, $at
/* 009304 70008704 00004812 */  mflo  $t1
/* 009308 70008708 24017FFF */  li    $at, 32767
/* 00930C 7000870C 46083283 */  div.s $f10, $f6, $f8
/* 009310 70008710 01E90019 */  multu $t7, $t1
/* 009314 70008714 00002012 */  mflo  $a0
/* 009318 70008718 00000000 */  nop
/* 00931C 7000871C 00000000 */  nop
/* 009320 70008720 0081001A */  div   $zero, $a0, $at
/* 009324 70008724 4600540D */  trunc.w.s $f16, $f10
/* 009328 70008728 00005812 */  mflo  $t3
/* 00932C 7000872C 2564FFFF */  addiu $a0, $t3, -1
/* 009330 70008730 00801825 */  move  $v1, $a0
/* 009334 70008734 44108000 */  mfc1  $s0, $f16
/* 009338 70008738 04810003 */  bgez  $a0, .L70008748
/* 00933C 7000873C 00000000 */   nop
/* 009340 70008740 10000001 */  b     .L70008748
/* 009344 70008744 00001825 */   move  $v1, $zero
.L70008748:
/* 009348 70008748 00033400 */  sll   $a2, $v1, 0x10
/* 00934C 7000874C 00066C03 */  sra   $t5, $a2, 0x10
/* 009350 70008750 01A03025 */  move  $a2, $t5
/* 009354 70008754 8EE40038 */  lw    $a0, 0x38($s7)
/* 009358 70008758 0C004CE8 */  jal   alSynSetVol
/* 00935C 7000875C 02003825 */   move  $a3, $s0
/* 009360 70008760 96A30000 */  lhu   $v1, ($s5)
.L70008764:
/* 009364 70008764 1000005C */  b     .L700088D8
/* 009368 70008768 306202D1 */   andi  $v0, $v1, 0x2d1
/* 00936C 7000876C 9239003E */  lbu   $t9, 0x3e($s1)
.L70008770:
/* 009370 70008770 33280002 */  andi  $t0, $t9, 2
/* 009374 70008774 55000043 */  bnezl $t0, .L70008884
/* 009378 70008778 96A20000 */   lhu   $v0, ($s5)
/* 00937C 7000877C 8E420000 */  lw    $v0, ($s2)
/* 009380 70008780 862D0034 */  lh    $t5, 0x34($s1)
/* 009384 70008784 9248000D */  lbu   $t0, 0xd($s2)
/* 009388 70008788 904B000D */  lbu   $t3, 0xd($v0)
/* 00938C 7000878C 92CC0002 */  lbu   $t4, 2($s6)
/* 009390 70008790 24013F01 */  li    $at, 16129
/* 009394 70008794 016D0019 */  multu $t3, $t5
/* 009398 70008798 3198003F */  andi  $t8, $t4, 0x3f
/* 00939C 7000879C 3C0A8006 */  lui   $t2, %hi(g_sndSfxSlotVolume)
/* 0093A0 700087A0 8D4A3BA4 */  lw    $t2, %lo(g_sndSfxSlotVolume)($t2)
/* 0093A4 700087A4 00187040 */  sll   $t6, $t8, 1
/* 0093A8 700087A8 26F40014 */  addiu $s4, $s7, 0x14
/* 0093AC 700087AC 014E7821 */  addu  $t7, $t2, $t6
/* 0093B0 700087B0 85E90000 */  lh    $t1, ($t7)
/* 0093B4 700087B4 0000C812 */  mflo  $t9
/* 0093B8 700087B8 00000000 */  nop
/* 0093BC 700087BC 00000000 */  nop
/* 0093C0 700087C0 03280019 */  multu $t9, $t0
/* 0093C4 700087C4 00006012 */  mflo  $t4
/* 0093C8 700087C8 00000000 */  nop
/* 0093CC 700087CC 00000000 */  nop
/* 0093D0 700087D0 0181001A */  div   $zero, $t4, $at
/* 0093D4 700087D4 0000C012 */  mflo  $t8
/* 0093D8 700087D8 24017FFF */  li    $at, 32767
/* 0093DC 700087DC 00000000 */  nop
/* 0093E0 700087E0 01380019 */  multu $t1, $t8
/* 0093E4 700087E4 00002012 */  mflo  $a0
/* 0093E8 700087E8 00000000 */  nop
/* 0093EC 700087EC 00000000 */  nop
/* 0093F0 700087F0 0081001A */  div   $zero, $a0, $at
/* 0093F4 700087F4 00005012 */  mflo  $t2
/* 0093F8 700087F8 2544FFFF */  addiu $a0, $t2, -1
/* 0093FC 700087FC 04810003 */  bgez  $a0, .L7000880C
/* 009400 70008800 00801825 */   move  $v1, $a0
/* 009404 70008804 10000001 */  b     .L7000880C
/* 009408 70008808 00001825 */   move  $v1, $zero
.L7000880C:
/* 00940C 7000880C 8C4E0004 */  lw    $t6, 4($v0)
/* 009410 70008810 C6260028 */  lwc1  $f6, 0x28($s1)
/* 009414 70008814 C62A002C */  lwc1  $f10, 0x2c($s1)
/* 009418 70008818 448E9000 */  mtc1  $t6, $f18
/* 00941C 7000881C 00033400 */  sll   $a2, $v1, 0x10
/* 009420 70008820 00065C03 */  sra   $t3, $a2, 0x10
/* 009424 70008824 46809120 */  cvt.s.w $f4, $f18
/* 009428 70008828 01603025 */  move  $a2, $t3
/* 00942C 7000882C 8EE40038 */  lw    $a0, 0x38($s7)
/* 009430 70008830 2625000C */  addiu $a1, $s1, 0xc
/* 009434 70008834 46062203 */  div.s $f8, $f4, $f6
/* 009438 70008838 460A4403 */  div.s $f16, $f8, $f10
/* 00943C 7000883C 4600848D */  trunc.w.s $f18, $f16
/* 009440 70008840 44109000 */  mfc1  $s0, $f18
/* 009444 70008844 0C004CE8 */  jal   alSynSetVol
/* 009448 70008848 02003825 */   move  $a3, $s0
/* 00944C 7000884C 240D0002 */  li    $t5, 2
/* 009450 70008850 A7AD00AC */  sh    $t5, 0xac($sp)
/* 009454 70008854 AFB100B0 */  sw    $s1, 0xb0($sp)
/* 009458 70008858 02802025 */  move  $a0, $s4
/* 00945C 7000885C 27A500AC */  addiu $a1, $sp, 0xac
/* 009460 70008860 0C004BBF */  jal   alEvtqPostEvent
/* 009464 70008864 02003025 */   move  $a2, $s0
/* 009468 70008868 9239003E */  lbu   $t9, 0x3e($s1)
/* 00946C 7000886C 33280020 */  andi  $t0, $t9, 0x20
/* 009470 70008870 51000004 */  beql  $t0, $zero, .L70008884
/* 009474 70008874 96A20000 */   lhu   $v0, ($s5)
/* 009478 70008878 0C002271 */  jal   sndCreatePitchEvent
/* 00947C 7000887C 02202025 */   move  $a0, $s1
/* 009480 70008880 96A20000 */  lhu   $v0, ($s5)
.L70008884:
/* 009484 70008884 304C02D1 */  andi  $t4, $v0, 0x2d1
/* 009488 70008888 10000013 */  b     .L700088D8
/* 00948C 7000888C 01801025 */   move  $v0, $t4
.L70008890:
/* 009490 70008890 0C002252 */  jal   sndDisposeSound
/* 009494 70008894 02202025 */   move  $a0, $s1
/* 009498 70008898 96A20000 */  lhu   $v0, ($s5)
/* 00949C 7000889C 304902D1 */  andi  $t1, $v0, 0x2d1
/* 0094A0 700088A0 1000000D */  b     .L700088D8
/* 0094A4 700088A4 01201025 */   move  $v0, $t1
.L700088A8:
/* 0094A8 700088A8 9238003E */  lbu   $t8, 0x3e($s1)
/* 0094AC 700088AC 330A0010 */  andi  $t2, $t8, 0x10
/* 0094B0 700088B0 11400006 */  beqz  $t2, .L700088CC
/* 0094B4 700088B4 00000000 */   nop
/* 0094B8 700088B8 8EA4000C */  lw    $a0, 0xc($s5)
/* 0094BC 700088BC 86A5000A */  lh    $a1, 0xa($s5)
/* 0094C0 700088C0 0C002382 */  jal   sndPlaySfx
/* 0094C4 700088C4 8E260030 */   lw    $a2, 0x30($s1)
/* 0094C8 700088C8 96A30000 */  lhu   $v1, ($s5)
.L700088CC:
/* 0094CC 700088CC 10000002 */  b     .L700088D8
/* 0094D0 700088D0 306202D1 */   andi  $v0, $v1, 0x2d1
glabel .L700088D4
/* 0094D4 700088D4 306202D1 */  andi  $v0, $v1, 0x2d1
.L700088D8:
/* 0094D8 700088D8 8FA30074 */  lw    $v1, 0x74($sp)
/* 0094DC 700088DC 10600006 */  beqz  $v1, .L700088F8
/* 0094E0 700088E0 00608825 */   move  $s1, $v1
/* 0094E4 700088E4 54400005 */  bnezl $v0, .L700088FC
/* 0094E8 700088E8 8FAB0080 */   lw    $t3, 0x80($sp)
/* 0094EC 700088EC 906E003E */  lbu   $t6, 0x3e($v1)
/* 0094F0 700088F0 31CF0001 */  andi  $t7, $t6, 1
/* 0094F4 700088F4 AFAF0080 */  sw    $t7, 0x80($sp)
.L700088F8:
/* 0094F8 700088F8 8FAB0080 */  lw    $t3, 0x80($sp)
.L700088FC:
/* 0094FC 700088FC 55600007 */  bnezl $t3, .L7000891C
/* 009500 70008900 8FBF003C */   lw    $ra, 0x3c($sp)
/* 009504 70008904 50600005 */  beql  $v1, $zero, .L7000891C
/* 009508 70008908 8FBF003C */   lw    $ra, 0x3c($sp)
/* 00950C 7000890C 5040FD70 */  beql  $v0, $zero, .L70007ED0
/* 009510 70008910 8FAF0074 */   lw    $t7, 0x74($sp)
/* 009514 70008914 AFB10078 */  sw    $s1, 0x78($sp)
/* 009518 70008918 8FBF003C */  lw    $ra, 0x3c($sp)
.L7000891C:
/* 00951C 7000891C 8FB00018 */  lw    $s0, 0x18($sp)
/* 009520 70008920 8FB1001C */  lw    $s1, 0x1c($sp)
/* 009524 70008924 8FB20020 */  lw    $s2, 0x20($sp)
/* 009528 70008928 8FB30024 */  lw    $s3, 0x24($sp)
/* 00952C 7000892C 8FB40028 */  lw    $s4, 0x28($sp)
/* 009530 70008930 8FB5002C */  lw    $s5, 0x2c($sp)
/* 009534 70008934 8FB60030 */  lw    $s6, 0x30($sp)
/* 009538 70008938 8FB70034 */  lw    $s7, 0x34($sp)
/* 00953C 7000893C 8FBE0038 */  lw    $fp, 0x38($sp)
/* 009540 70008940 03E00008 */  jr    $ra
/* 009544 70008944 27BD00D0 */   addiu $sp, $sp, 0xd0

.late_rodata
glabel jpt_80029160
 .word .L70007FBC
 .word .L70008388
 .word .L700088D4
 .word .L7000847C
 .word .L700088D4
 .word .L700088D4
 .word .L700088D4
 .word .L700085C8
 .word .L700088D4
 .word .L700088D4
 .word .L700088D4
 .word .L700088D4
 .word .L700088D4
 .word .L700088D4
 .word .L700088D4
 .word .L700084F0
 .size jpt_80029160, . - jpt_80029160
)
#endif


/**
 * 9548    70008948
 */
void sndDisposeSound(ALSoundState *state)
{
    if (state->unk3e & 4)
    {
        alSynStopVoice(g_sndPlayerPtr->drvr, &state->voice);
        alSynFreeVoice(g_sndPlayerPtr->drvr, &state->voice);
    }

    sndUnlinkClearSound(state);
    sndRemoveEvents(&g_sndPlayerPtr->evtq, state, 0xffff);
}

/**
 * 95C4    700089C4
 */
void sndCreatePitchEvent(ALSoundState *state)
{
    ALSndpEvent evt;
    f32 pitch;

    pitch = (f32) (alCents2Ratio(state->sound->keyMap->detune) * (f32)state->pitch_2c);
    evt.pitch.state = state;
    evt.pitch.type = AL_SNDP_PITCH_EVT;

    // TODO: surely there's a better way to match target, especially since there's already a union type used with f32 for pitch.
    evt.unks32.val8 = *(s32*)&pitch;

    alEvtqPostEvent(&g_sndPlayerPtr->evtq, (ALEvent *)&evt, DELTA_33_MS);
}

/**
 * 9630     70008A30
 * Based on (almost identical to) the method
 * static void _removeEvents(ALEventQueue *evtq, ALSoundState *state)
 * from n64devkit\ultra\usr\src\pr\libsrc\libultra\audio\sndplayer.c
 */
void sndRemoveEvents(ALEventQueue *evtq, ALSoundState *state, u16 eventType)
{
    ALLink              *thisNode;
    ALLink              *nextNode;
    ALEventListItem     *thisItem;
    ALEventListItem     *nextItem;
    ALSndpEvent         *thisEvent;
    OSIntMask           mask;

    mask = osSetIntMask(OS_IM_NONE);

    thisNode = evtq->allocList.next;

    while(thisNode != NULL)
    {
	    nextNode = thisNode->next;
        thisItem = (ALEventListItem *)thisNode;
        nextItem = (ALEventListItem *)nextNode;
        thisEvent = (ALSndpEvent *)&thisItem->evt;

        if (thisEvent->common.state == state && (((u16)thisItem->evt.type & (u16)eventType) != 0))
        {
            if (nextItem != NULL)
            {
                nextItem->delta += thisItem->delta;
            }

            alUnlink(thisNode);
            alLink(thisNode, &evtq->freeList);
        }

	    thisNode = nextNode;
    }

    osSetIntMask(mask);
}

/**
 * 96F0     70008AF0
 * Has similarities to
 * void alEvtqPrintEvtQueue(ALEventQueue *evtq)
 * from n64devkit\ultra\usr\src\pr\libsrc\libultra\audio\event.c
 *
 * @param allocListCount Out param. Will contain the number of (next) nodes in the D_800243E4 allocList.
 * @param freeListCount Out param. Will contain the number of (next) nodes in the D_800243E4 freeList.
 * @return Number of (prev) nodes in the D_800243E4 freeList.
 */
s32 sndCountAllocList(s16 *allocListCount, s16 *freeListCount)
{
    u16 counter1;
    u16 counter2;
    u16 returnCounter;

    ALEventQueue *evtq = (ALEventQueue *)&D_800243E4;

    ALLink *freeListNodeForward = evtq->freeList.next;
    ALLink *allocListNodeForward = evtq->allocList.next;
    ALLink *freeListNodeBackward = evtq->freeList.prev;

    for (counter1 = 0; freeListNodeForward != NULL; freeListNodeForward = freeListNodeForward->next)
    {
         counter1++;
    }

    for (counter2 = 0; allocListNodeForward != NULL; allocListNodeForward = allocListNodeForward->next)
    {
         counter2++;
    }

    for (returnCounter = 0; freeListNodeBackward != NULL; freeListNodeBackward = freeListNodeBackward->prev)
    {
         returnCounter++;
    }

    *allocListCount = (s16) counter2;
    *freeListCount = (s16) counter1;

    return returnCounter;
}

/**
 * 9770    70008B70
 * initializes soundstate to sound based on global g_sndPlayerSoundStatePtr.
 *     accepts: A0=sound data offset?, A1=sample address?
 *
 * @param soundBank unused.
 * @param sound sound to use.
 */
ALSoundState *sndSetupSound(struct ALBankAlt_s *soundBank, ALSound* sound)
{
    s32 decayTimeFlag;
    ALKeyMap *keymap = sound->keyMap;
    ALSoundState *state = (ALSoundState *)D_800243E4.g_sndPlayerSoundStatePtr;
    OSIntMask mask;

    if (state != NULL)
    {
        mask = osSetIntMask(OS_IM_NONE);

        D_800243E4.g_sndPlayerSoundStatePtr = (void *)state->link.next;
        alUnlink(&state->link);

        if (D_800243E4.node.next != NULL)
        {
            state->link.next = (void *)D_800243E4.node.next;
            state->link.prev = NULL;
            D_800243E4.node.next->prev = (void *)state; // what?
            D_800243E4.node.next = (void *)state;
        }
        else
        {
            state->link.prev = NULL;
            state->link.next = NULL;
            D_800243E4.node.next = (void *)state;
            D_800243E4.node.prev = (void *)state;
        }

        osSetIntMask(mask);

        decayTimeFlag = (sound->envelope->decayTime == -1);
        state->priority = decayTimeFlag + 0x40;

        state->playingState = AL_UNKOWN_5;
        state->unk38 = 2;
        state->sound = sound;
        state->pitch_2c = 1.0f;
        state->unk3e = (keymap->keyMax & (u8)0xf0);
        state->state = NULL;

        if ((state->unk3e & 0x20) != 0)
        {
            state->pitch_28 = alCents2Ratio(((keymap->keyBase * 100) + DEFAULT_SETUP_PITCH_SHIFT));
        }
        else
        {
            state->pitch_28 = alCents2Ratio((((keymap->keyBase * 100) + keymap->detune) + DEFAULT_SETUP_PITCH_SHIFT));
        }

        if (decayTimeFlag)
        {
            state->unk3e |= 2;
        }

        state->fxMix = (u8)AL_DEFAULT_FXMIX;
        state->pan = (u8)AL_PAN_CENTER;
        state->vol = (u16)0x7fff;
    }

    return state;
}


/**
 * 9904    70008D04
 * some kind of dispose method, unlinks next/prev pointers.
 */
void sndUnlinkClearSound(ALSoundState *state)
{
    if (state == (ALSoundState *)D_800243E4.node.next)
    {
        D_800243E4.node.next = state->link.next;
    }

    if (state == (ALSoundState *)D_800243E4.node.prev)
    {
        D_800243E4.node.prev = state->link.prev;
    }

    alUnlink(&state->link);

    if (D_800243E4.g_sndPlayerSoundStatePtr != NULL)
    {
        state->link.next = (void *)D_800243E4.g_sndPlayerSoundStatePtr;
        state->link.prev = NULL;
        D_800243E4.g_sndPlayerSoundStatePtr->link.prev = (void *)state;
        D_800243E4.g_sndPlayerSoundStatePtr = state;
    }
    else
    {
        state->link.prev = NULL;
        state->link.next = NULL;
        D_800243E4.g_sndPlayerSoundStatePtr = state;
    }

    if ((state->unk3e & 4) != 0)
    {
        g_sndAllocatedVoicesCount--;
    }

    state->playingState = AL_STOPPED;

    if (state->state != NULL)
    {
        if (state == (ALSoundState *)state->state->link.next)
        {
            state->state->link.next = NULL;
        }

        state->state = NULL;
    }
}

/**
 * 99D8    70008DD8
 * Sets priority of ALSoundState.
 */
void sndSetPriority(ALSoundState *state, u8 priority)
{
    if (state != NULL)
    {
        state->priority = priority;
    }
}

/**
 * 99F0    70008DF0
 * Gets Playing State if a state is available
 * @param state: the state to check
 * @return AL_PLAYSTATE
 */
u8 sndGetPlayingState(ALSoundState *state)
{
    if (state != NULL)
    {
        return state->playingState;
    }

    return AL_STOPPED;
}

#ifdef DEBUG
#    define _sndPlaySfx(sbank, id, state) sndPlaySfx(sbank, id, state, g_sndSfxVolume, __FILE__, __LINE__)
ALSoundState *sndPlaySfx(struct ALBankAlt_s *soundBank, s16 soundIndex, ALSoundState *pendingState, f32 volume, char*file, int line)
#else
/**
 * 9A08    70008E08
 *     sets sound effect; used by sound effect routines
 *
 * Old comments:
 *
 *     accepts: A0=p->SE buffer, A1=SE #, A2=p->data
 *          data:    0x0    4    p->SE entry
 *              0x4    4    target volume
 *              0x8    4    audible range (timer)
 *              0xC    4    initial volume
 *              0x10    4    p->preset emitting sound
 *              0x14    4    p->object emitting sound
 *
 * // end old comments.
 *
 * @param soundBank sound bank
 * @param soundIndex index into sound bank: soundBank->instArray[0]->soundArray[soundIndex]
 * @param pendingState Optional pointer. If provided, its link.next pointer will be
 * to the newly created soundState.
 */
ALSoundState *sndPlaySfx(struct ALBankAlt_s *soundBank, s16 soundIndex, ALSoundState *pendingState)
#endif
{
    // declarations

    // declaration order doesn't seem to matter for these.

    ALMicroTime deltaTotal;
    ALSound *sound;
    ALSoundState *newState;
    ALSoundState *nextState;

    // declaration order matters:

    s16 eventSoundIndex;       // 110(sp)
    s16 unused_sp6c;           // 108(sp)
    ALMicroTime playSfxDelta;  // 104(sp)
    ALMicroTime deltaLoop; // 100(sp)

    // end declarations

    nextState = NULL;
    eventSoundIndex = 0;
    deltaTotal = 0;

    if(0); // debug?

    if (g_sndBootswitchSound)
    {
        return NULL;
    }

    if (soundIndex == 0)
    {
        return NULL;
    }

    do
    {
        ALKeyMap *keyMap;

        sound = (soundBank->instArray[0]->soundArray[soundIndex]);

        newState = sndSetupSound(soundBank, sound);

        if (newState != NULL)
        {
            ALSndpEvent playEvent;

            g_sndPlayerPtr->target = (s32)newState;
            playEvent.common.type = AL_SNDP_PLAY_EVT;
            playEvent.common.state = newState;
            deltaLoop = sound->keyMap->velocityMax * DELTA_33_MS;

            if (newState->unk3e & 0x10)
            {
                newState->unk3e &= (~(s16)(0x10));
                alEvtqPostEvent(&g_sndPlayerPtr->evtq, (ALEvent *)&playEvent, deltaTotal + 1);
                playSfxDelta = deltaLoop + 1;
                eventSoundIndex = soundIndex;
            }
            else
            {
                alEvtqPostEvent(&g_sndPlayerPtr->evtq, (ALEvent *)&playEvent, deltaLoop + 1);
            }

            nextState = newState;
        }

        deltaTotal += deltaLoop;

        keyMap = sound->keyMap;
        soundIndex = (s16)((s32)keyMap->velocityMin + ((s32)(keyMap->keyMin & 0xC0) * 4));
    } while (soundIndex != 0 && newState != NULL);

    if(!soundIndex)
    {
        // removed
    }

    if(!sound)
    {
        // removed
    }

    if (nextState != NULL)
    {
        nextState->unk3e |= 0x1;
        nextState->state = pendingState;

        if (eventSoundIndex != 0)
        {
            ALSndpEvent playSfxEvent;

            nextState->unk3e |= 0x10;

            playSfxEvent.playSfx.type = AL_SNDP_PLAY_SFX_EVT;
            playSfxEvent.playSfx.state = nextState;
            playSfxEvent.playSfx.soundIndex = eventSoundIndex; // types dont match
            playSfxEvent.playSfx.soundBank = soundBank;

            alEvtqPostEvent(&g_sndPlayerPtr->evtq, (ALEvent *)&playSfxEvent, playSfxDelta);
        }
    }

    if (pendingState != NULL)
    {
        pendingState->link.next = (void*)nextState;
    }

    return nextState;
}

/**
 * 9C20    70009020
 *     decativates sound effect
 *     accepts: A0=p->SE buffer
 */
void sndDeactivate(ALSoundState *state)
{
    ALSndpEvent evt;

    evt.common.type = AL_SNDP_DEACTIVATE_EVT;
    evt.common.state = state;

    if (state != NULL)
    {
        state->unk3e = (s8) (state->unk3e & (~(s16)(0x10)));

        alEvtqPostEvent(&g_sndPlayerPtr->evtq, (ALEvent *)&evt, 0);
    }
}

/**
 * 9C6C    7000906C
 * Similar to sndDeactivate, but iterates the global list and deactivates
 * items with the same unk3e flag.
 *
 * @param flag flag bitmask to match item on.
 */
void sndDeactivateAllSfxByFlag(u8 flag)
{
    OSIntMask mask;
    ALSndpEvent evt;
    ALSoundState *item;

    mask = osSetIntMask(OS_IM_NONE);

    item = (ALSoundState *)D_800243E4.node.next;
    while (item != NULL)
    {
        evt.common.type = AL_SNDP_DEACTIVATE_EVT;
        evt.common.state = item;

        if ((item->unk3e & flag) == flag)
        {
            item->unk3e = (s8) (item->unk3e & (~(s16)(0x10)));
            alEvtqPostEvent(&g_sndPlayerPtr->evtq, (ALEvent *)&evt, 0);
        }

        item = (ALSoundState *)item->link.next;
    }

    osSetIntMask(mask);
}

/**
 * 9D24    70009124
 *     redirect to 7000906C: A0=1
 */
void sndDeactivateAllSfxByFlag_1(void)
{
    sndDeactivateAllSfxByFlag(1);
}

/**
 * 9D44    70009144
 *     redirect to 7000906C: A0=11
 */
void sndDeactivateAllSfxByFlag_11(void)
{
    sndDeactivateAllSfxByFlag(0x11);
}

/**
 * 9D64    70009164
 *     redirect to 7000906C: A0=3
 */
void sndDeactivateAllSfxByFlag_3(void)
{
    sndDeactivateAllSfxByFlag(3);
}

/**
 * 9D84    70009184
 * Calls alEvtqPostEvent with the method parameters and delta=0.
 *
 * @param state sound state.
 * @param eventType type of event to post.
 * @param arg2 event data value (interpretation depends on eventType).
 */
void sndCreatePostEvent(ALSoundState *state, s16 eventType, s32 arg2)
{
    ALSndpEvent evt;

    evt.common.type = eventType;
    evt.common.state = state;
    evt.unks32.val8 = arg2;

    if (state != NULL)
    {
        alEvtqPostEvent(&g_sndPlayerPtr->evtq, (ALEvent *)&evt, 0);
    }
}

/**
 * 9DC8    700091C8
 *     redirect to 70009264: A0=0
 */
u16 sndGetSfxSlotFirstNaturalVolume(void)
{
    return sndGetSfxSlotNaturalVolume(0);
}

/**
 * 9DE8    700091E8
 */
void sndApplyVolumeAllSfxSlot(u16 volume)
{
    u8 i;

    for (i = 0; i < SFX_SLOT_COUNT; i++)
    {
        sndSetSfxSlotVolume(i, volume);
    }
}

/**
 * 9E38    70009238
 */
void sndSetScalerApplyVolumeAllSfxSlot(f32 volumeScale)
{
    g_sndSfxVolumeScale = volumeScale;
    sndApplyVolumeAllSfxSlot(sndGetSfxSlotFirstNaturalVolume());
}

/**
 * 9E64    70009264
 *     V0= halfword A0 in table at [80063BA8]; fries T6,T7,T8,T9
 */
u16 sndGetSfxSlotNaturalVolume(u8 sfxIndex)
{
    return g_sndSfxSlotNaturalVolume[sfxIndex];
}

/**
 * 9E84    70009284
 */
void sndSetSfxSlotVolume(u8 sfxIndex, u16 volume)
{
    // Not sure if these are debug leftovers, or is the type `ALSndpEvent` wrong?
    u32 unused[2];

    ALSndpEvent evt;
    ALSoundState *item;

    item = (ALSoundState *)D_800243E4.node.next;

    g_sndSfxSlotNaturalVolume[sfxIndex] = volume;
    g_sndSfxSlotVolume[sfxIndex] = (s16) ((f32) volume * g_sndSfxVolumeScale);

    while (item != NULL)
    {
        if (item->sound != NULL)
        {
            if ((item->sound->keyMap->keyMin & 0x3f) == sfxIndex)
            {
                evt.common.type = AL_SNDP_RELEASE_EVT;
                evt.common.state = item;

                alEvtqPostEvent(&g_sndPlayerPtr->evtq, (ALEvent *)&evt, 0);
            }
        }

        item = (ALSoundState *)item->link.next;
    }
}
