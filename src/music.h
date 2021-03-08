#ifndef _MUSIC_H_
#define _MUSIC_H_
#include "ultra64.h"
#include "include/PR/libaudio.h"

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

extern char D_80063B50[0x54];
extern s32 D_80063BA4;
extern s32 D_80063BA8;

#endif
