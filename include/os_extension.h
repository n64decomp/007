#ifndef _OS_EXTENSION_H_
#define _OS_EXTENSION_H_

/* ******************************************************************************** */
// controller
/* ******************************************************************************** */
#define ANY_BUTTON 0xFFFF

/* ******************************************************************************** */
// audio
/* ******************************************************************************** */

#define AL_USEC_PER_FRAME_60FPS       16000
#define AL_USEC_PER_FRAME_30FPS       33000

// Used while iterating during AL_SNDP_PLAY_EVT;
// Seems to be used to flag visited ALEvents.
#define AL_UNKOWN_3     3

// Maybe: call to alSynAllocVoice failed
#define AL_UNKOWN_4     4

// Maybe: currently initializing state?
#define AL_UNKOWN_5     5

#endif
