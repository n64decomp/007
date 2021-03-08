#ifndef _SND_H_
#define _SND_H_
#include "ultra64.h"
#include "PR/libaudio.h"

/**
 * This is a guess struct, used by music setup function call into snd.
 * There's some setup of ALSeqpConfig just above the section, so
 * that's what this is based on.
 */
typedef struct ALSeqpSfxConfig_s {
    s32         maxVoices;         /* max number of voices to alloc    */
    s32         maxEvents;         /* max internal events to support   */
    u32         channelWord;
    ALHeap      *heap;             /* ptr to initialized heap          */
} ALSeqpSfxConfig;

void play_sfx_a1 (void * buffer, short entry, void * data);
void sfx_c_70007B20(ALSeqpSfxConfig *arg0);

extern s8 bootswitch_sound;


#endif
