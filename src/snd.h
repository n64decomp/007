#ifndef _SND_H_
#define _SND_H_

#include <ultra64.h>
#include <PR/libaudio.h>

#define DELTA_1_MS   1000
#define DELTA_33_MS 33333

#define SFX_SLOT_COUNT   7

/**
 * Based on n64devkit\ultra\usr\src\pr\libsrc\libultra\audio\sndp.h
 * enum ALSndpMsgType,
 * except this version is bitwise.
 */
typedef enum ALSndpMsgType_e {
    AL_SNDP_PLAY_EVT       = (1 << 0),
    AL_SNDP_STOP_EVT       = (1 << 1),
    AL_SNDP_PAN_EVT        = (1 << 2),
    AL_SNDP_VOL_EVT        = (1 << 3),
    AL_SNDP_PITCH_EVT      = (1 << 4),
    AL_SNDP_API_EVT        = (1 << 5),
    AL_SNDP_DECAY_EVT      = (1 << 6),
    AL_SNDP_END_EVT        = (1 << 7),
    AL_SNDP_FX_EVT         = (1 << 8),
    AL_SNDP_PLAY_SFX_EVT   = (1 << 9),
    AL_SNDP_DEACTIVATE_EVT = (1 << 10),
    AL_SNDP_RELEASE_EVT    = (1 << 11),
    AL_SNDP_UNKNOWN_12_EVT = (1 << 12), // used
    AL_SNDP_UNUSED_13_EVT  = (1 << 13), // defined here for 16 bit completion
    AL_SNDP_UNUSED_14_EVT  = (1 << 14), // defined here for 16 bit completion
    AL_SNDP_UNUSED_15_EVT  = (1 << 15)  // defined here for 16 bit completion
} ALSndpMsgType;

// based on n64devkit\ultra\usr\src\pr\libsrc\libultra\audio\sndp.h
struct ALSoundState_s;
typedef struct ALSoundState_s {
    // offset 0
    ALLink link;

    // offset 8
    ALSound *sound;

    // offset 0xc
    ALVoice voice;

    // current playback pitch ... ?
    // offset 0x28
    f32 pitch_28;

    // bendRatio?
    // offset 0x2c
    f32 pitch_2c;

    // play state for this sound
    // offset 0x30
    struct ALSoundState_s *state;

    // offset 0x34
    s16 vol;

    /// offset 0x36
    u8 priority;

    // unused?
    s8 unk37;

    // counter of some kind
    s32 unk38;

    // offset 0x3c = 60
    // pan - 0 = left, 127 = right
    ALPan pan;

    // offset 0x3d = 61
    // wet/dry mix - 0 = dry, 127 = wet
    u8 fxMix;

    // flags?
    // 0x01 = ? used in sndPlaySfx if there is "nextState"
    // 0x02 = decay time flag
    // 0x04 = maybe: voice allocated/started ?
    // 0x08 = ?
    // 0x10 = active flag
    // 0x20 = related to detune
    // 0x40 = ?
    // 0x80 = ?
    u8 unk3e;
    /*
      AL_STOPPED
      AL_PLAYING
      AL_STOPPING
    */
    u8 playingState; 

} ALSoundState;

/**
 * This is a guess struct, used by music setup function call into snd.
 * The method call makes it seem like this should be ALSndpConfig,
 * but there's an extra field here.
 */
typedef struct ALSeqpSfxConfig_s {

    /**
     * (actual field is unknown)
     * Used to calculate size in call to alHeapAlloc for sndState,
     * this is the number of ALSndPlayer.sndState entries.
     * Offset 0.
     */
    s32 maybeSndStateCount;

    /**
     * max internal events to support
     * Offset 4.
     */
    s32 maxEvents;

    /**
     * (actual field is unknown)
     * ALSndPlayer.maxSounds will be assigned this value
     * Offset 8.
     */
    u32 maybeMaxSounds;

    /**
     * ptr to initialized heap
     * Offset 0xc.
     */
    ALHeap *heap;
} ALSeqpSfxConfig;

// begin Alternate defintion for ALInstrument

struct ALInstrumentAlt_s
{
    s32 unk0;
    s32 unk4;
    s32 unk8;
    ALSound *soundArray[1];
};

struct ALBankAlt_s
{
    s16 instCount; /* number of programs in this bank */
    u8 flags;
    u8 pad;
    s32 sampleRate;             /* e.g. 44100, 22050, etc...       */
    ALInstrument *percussion;   /* default percussion for GM       */
    struct ALInstrumentAlt_s *instArray[1]; /* ARRAY of instruments            */
};

// end Alternate defintion for ALInstrument

void sndNewPlayerInit(ALSeqpSfxConfig *arg0);
u8 sndGetPlayingState(ALSoundState *state);
void sndDeactivate(ALSoundState *state);
void sndDeactivateAllSfxByFlag_1(void);
void sndCreatePostEvent(ALSoundState *state, s16 eventType, s32 arg2);
ALSoundState *sndPlaySfx(struct ALBankAlt_s *soundBank, s16 soundIndex, ALSoundState *pendingState);
u16 sndGetSfxSlotFirstNaturalVolume(void);
void sndApplyVolumeAllSfxSlot(u16 arg0);
void sndSetScalerApplyVolumeAllSfxSlot(f32 arg0);

extern s8 g_sndBootswitchSound;


#endif
