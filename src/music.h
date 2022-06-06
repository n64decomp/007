#ifndef _MUSIC_H_
#define _MUSIC_H_
#include <ultra64.h>
#include <PR/libaudio.h>

#define VOLUME_MAX 0x7fff

/**
 * Counting definitions for music in this file, there
 * are 63 distinct entries. This exlcudes the "NONE" music
 * and control sequence entries.
 */
#define NUM_MUSIC_TRACKS  63

/**
 * Metadata for a sequence "file" entry / data content of single sequence.
 * Based on original ALSeqData in n64devkit\ultra\usr\include\PR\libaudio.h.
 */
typedef struct
{
    // address is offset from the start of .sbk file
    u8 *address;

    // seq length after uncompressed.
    u16 uncompressed_len;

    // len is data segment length in the rom. This is the 1172 compressed length.
    u16 len;
} RareALSeqData;

/**
 * Structure for storing collection of sequence metadatas.
 * These are stored 1172 compressed.
 * Based on original ALSeqFile in n64devkit\ultra\usr\include\PR\libaudio.h.
 */
typedef struct
{
    /**
     * number of sequences.
     */
    u16 seqCount;

    /**
     * Unknown, maybe unused padding.
     */
    u16 unk;

    /**
     * ARRAY of sequence info. This is a "dynamic" array, more space
     * will be allocated from ALHeap at runtime.
     */
    RareALSeqData seqArray[1];
} RareALSeqBankFile;

typedef enum MUSIC_FADESTATE_e {
    /**
     * Music track is fading out.
     */
    MUSIC_FADESTATE_FADE_OUT = -1,

    /**
     * Default state. Also reached when forcibly halted by application.
     */
    MUSIC_FADESTATE_UNSET,

    /**
     * Music track is fading in.
     */
    MUSIC_FADESTATE_FADE_IN
} MUSIC_FADESTATE;

void musicSeqPlayerInit(void);

void musicTrack1Play(s32 track);
void musicTrack1Stop(void);
u16 musicTrack1GetVolume(void);
void musicTrack1ApplySeqpVol(u16 volume);
void musicTrack1SaveCurrentVolumeAsTrackDefault(void);
void musicTrack1FadeOut(f32 fadeTime);
void musicTrack1FadeIn(f32 fadeTime, u16 volume);

void musicTrack2Play(s32 track);
void musicTrack2Stop(void);
u16 musicTrack2GetVolume(void);
void musicTrack2ApplySeqpVol(u16 volume);
void musicTrack2SaveCurrentVolumeAsTrackDefault(void);
void musicTrack2FadeOut(f32 fadeTime);
void musicTrack2FadeIn(f32 fadeTime, u16 volume);

void musicTrack3Play(s32 track);
void musicTrack3Stop(void);
u16 musicTrack3GetVolume(void);
void musicTrack3ApplySeqpVol(u16 volume);
void musicTrack3SaveCurrentVolumeAsTrackDefault(void);
void musicTrack3FadeOut(f32 fadeTime);
void musicTrack3FadeIn(f32 fadeTime, u16 volume);

void musicFadeTick(void);

extern s32 g_musicXTrack1Fade;
extern s32 g_musicXTrack2Fade;
extern s32 g_musicXTrack3Fade;

extern ALBank *g_musicSfxBufferPtr;

extern ALSndPlayer g_sndPlayer;
extern s16 *g_sndSfxSlotVolume;
extern u16 *g_sndSfxSlotNaturalVolume;

#endif
