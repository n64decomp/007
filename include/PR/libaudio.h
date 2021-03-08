#ifndef _ULTRA64_LIBAUDIO_H_
#define _ULTRA64_LIBAUDIO_H_

#include "abi.h"

/***********************************************************************
 * misc defines
 ***********************************************************************/    
typedef u8      ALPan;

/***********************************************************************
 * Audio Library global routines
 ***********************************************************************/
typedef struct ALLink_s {
    struct ALLink_s      *next;
    struct ALLink_s      *prev;
} ALLink;

typedef s32 (*ALDMAproc)(s32 addr, s32 len, void *state);
typedef ALDMAproc (*ALDMANew)(void *state);

#define AL_FX_NONE      0
#define AL_FX_SMALLROOM 1
#define AL_FX_BIGROOM   2
#define AL_FX_CHORUS    3
#define AL_FX_FLANGE    4
#define AL_FX_ECHO      5
#define AL_FX_CUSTOM    6

typedef u8 ALFxId;
typedef s32     ALMicroTime;

typedef struct {
    u8 *base;
    u8 *current;
    s32 len;
    s32 count;
} ALHeap;

typedef struct {
    s32 maxVVoices; /* obsolete */
    s32 maxPVoices;
    s32 maxUpdates;
    s32 maxFXbusses;
    void *dmaproc;
    ALHeap *heap;
    s32 outputRate;
    ALFxId fxType;
    s32 *params;
} ALSynConfig;


void    alHeapInit(ALHeap *hp, u8 *base, s32 len);
void    *alHeapDBAlloc(u8 *file, s32 line, ALHeap *hp, s32 num, s32 size);

#ifdef DEBUG
#define alHeapAlloc(hp, elem ,size) alHeapDBAlloc((u8 *) __FILE__,__LINE__,(hp),(elem),(size))
#else
#define alHeapAlloc(hp, elem ,size) alHeapDBAlloc(0, 0,(hp),(elem),(size))
#endif

/***********************************************************************
 * data structures for sound banks
 ***********************************************************************/

typedef struct {
    s32 order;
    s32 npredictors;
    s16 book[1];        /* Actually variable size. Must be 8-byte aligned */
} ALADPCMBook;

typedef struct {
    u32         start;
    u32         end;
    u32         count;
    ADPCM_STATE state;
} ALADPCMloop;

typedef struct {
    u32         start;
    u32         end;
    u32         count;
} ALRawLoop;

typedef struct {
    ALMicroTime attackTime;
    ALMicroTime decayTime;
    ALMicroTime releaseTime;
    u8          attackVolume;
    u8          decayVolume;
} ALEnvelope;

typedef struct {
    u8          velocityMin;
    u8          velocityMax;
    u8          keyMin;
    u8          keyMax;
    u8          keyBase;
    s8          detune;
} ALKeyMap;

typedef struct {
    ALADPCMloop *loop;
    ALADPCMBook *book;
} ALADPCMWaveInfo;

typedef struct {
    ALRawLoop *loop;
} ALRAWWaveInfo;

typedef struct ALWaveTable_s {
    u8          *base;          /* ptr to start of wave data    */
    s32         len;            /* length of data in bytes      */
    u8          type;           /* compression type             */
    u8          flags;          /* offset/address flags         */
    union {
        ALADPCMWaveInfo adpcmWave;
        ALRAWWaveInfo   rawWave;
    } waveInfo;
} ALWaveTable;

typedef struct ALSound_s {
    ALEnvelope  *envelope;
    ALKeyMap    *keyMap;
    ALWaveTable *wavetable;     /* offset to wavetable struct           */
    ALPan       samplePan;
    u8          sampleVolume;
    u8          flags;
} ALSound;

typedef struct {
    u8          volume;         /* overall volume for this instrument   */
    ALPan       pan;            /* 0 = hard left, 127 = hard right      */
    u8          priority;       /* voice priority for this instrument   */
    u8          flags;
    u8          tremType;       /* the type of tremelo osc. to use      */
    u8          tremRate;       /* the rate of the tremelo osc.         */
    u8          tremDepth;      /* the depth of the tremelo osc         */
    u8          tremDelay;      /* the delay for the tremelo osc        */
    u8          vibType;        /* the type of tremelo osc. to use      */
    u8          vibRate;        /* the rate of the tremelo osc.         */
    u8          vibDepth;       /* the depth of the tremelo osc         */
    u8          vibDelay;       /* the delay for the tremelo osc        */
    s16         bendRange;      /* pitch bend range in cents            */
    s16         soundCount;     /* number of sounds in this array       */
    ALSound     *soundArray[1];
} ALInstrument;

typedef struct ALBank_s {
    s16                 instCount;      /* number of programs in this bank */
    u8                  flags;
    u8                  pad;
    s32                 sampleRate;     /* e.g. 44100, 22050, etc...       */
    ALInstrument        *percussion;    /* default percussion for GM       */
    ALInstrument        *instArray[1];  /* ARRAY of instruments            */
} ALBank;

typedef struct {                /* Note: sizeof won't be correct        */
    s16         revision;       /* format revision of this file         */
    s16         bankCount;      /* number of banks                      */
    ALBank      *bankArray[1];  /* ARRAY of bank offsets                */
} ALBankFile;

void    alBnkfNew(ALBankFile *f, u8 *table);

/***********************************************************************
 * Synthesis driver stuff
 ***********************************************************************/
typedef ALMicroTime (*ALVoiceHandler)(void *);

typedef struct ALPlayer_s {
    struct ALPlayer_s   *next;
    void                *clientData;    /* storage for client callback  */
    ALVoiceHandler      handler;        /* voice handler for player     */
    ALMicroTime         callTime;       /* usec requested callback      */
    s32                 samplesLeft;    /* usec remaining to callback   */
} ALPlayer;

typedef struct ALVoice_s {
    ALLink              node;
    struct PVoice_s     *pvoice;
    ALWaveTable         *table;
    void                *clientPrivate;
    s16                 state;
    s16                 priority;
    s16                 fxBus;
    s16                 unityPitch;
} ALVoice;

typedef struct {
    ALPlayer    *head;          /* client list head                     */
    ALLink      pFreeList;      /* list of free physical voices         */
    ALLink      pAllocList;     /* list of allocated physical voices    */
    ALLink      pLameList;      /* list of voices ready to be freed     */
    s32         paramSamples;
    s32         curSamples;     /* samples from start of game           */
    ALDMANew    dma;
    ALHeap      *heap;
    
    struct ALParam_s    *paramList;
    
    struct ALMainBus_s  *mainBus;
    struct ALAuxBus_s   *auxBus;        /* ptr to array of aux bus structs */
    struct ALFilter_s   *outputFilter;  /* last filter in the filter chain */

    s32                 numPVoices;
    s32                 maxAuxBusses;
    s32                 outputRate;     /* output sample rate */
    s32                 maxOutSamples;  /* Maximum samples rsp can generate
                                           at one time at output rate */
} ALSynth;

/***********************************************************************
 * Audio Library (AL) stuff
 ***********************************************************************/
typedef struct {
    ALSynth     drvr;
} ALGlobals;

/***********************************************************************
 * Sequence Files
 ***********************************************************************/

/**
 * Metadata for a sequence "file" entry / data content of single sequence.
 * Based on original ALSeqData in n64devkit\ultra\usr\include\PR\libaudio.h.
 */
typedef struct
{
    u8 *address;
    u16 offset;
    u16 len;
} ALSeqData;

/**
 * Structure for storing collection of sequence metadatas.
 * Based on original ALSeqFile in n64devkit\ultra\usr\include\PR\libaudio.h.
 */
typedef struct
{
    /**
     * number of sequences.
     */
    u16 seqCount;

    /**
     * Unknown, maybe revision.
     */
    u16 unk;

    /**
     * ARRAY of sequence info. This is a "dynamic" array, more space
     * will be allocated from ALHeap at runtime.
     */
    ALSeqData seqArray[1];
} ALSeqFile;

void alSeqFileNew(ALSeqFile *f, u8 *base);

/***********************************************************************
 * Audio Library (AL) stuff
 ***********************************************************************/
typedef struct {
    u8          *curPtr;                /* ptr to the next event */
    s32         lastTicks;              /* sequence clock ticks (used by alSeqSetLoc) */
    s32               curTicks;        /* sequence clock ticks of next event (used by loop end test) */
    s16         lastStatus;             /* the last status msg */
} ALSeqMarker;

typedef struct {
    s32         ticks;    /* MIDI, Tempo and End events must start with ticks */
    u8          status;
    u8          byte1; 
    u8          byte2;
    u32         duration;
} ALMIDIEvent;

typedef struct {
    s32         ticks;
    u8          status;
    u8          type;
    u8          len;
    u8          byte1;
    u8          byte2;
    u8          byte3;
} ALTempoEvent;

typedef struct {
    s32         ticks;
    u8          status;
    u8          type;
    u8          len;
} ALEndEvent;

typedef struct {
    struct ALVoice_s    *voice;
} ALNoteEvent;

typedef struct {
    struct ALVoice_s    *voice;
    ALMicroTime         delta;
    u8                  vol;
} ALVolumeEvent;

typedef struct {
    s16                 vol;
} ALSeqpVolEvent;

typedef struct {
    ALSeqMarker         *start;
    ALSeqMarker         *end;
    s32                 count;
} ALSeqpLoopEvent;

typedef struct {
    u8            chan;
    u8            priority;
} ALSeqpPriorityEvent;

typedef struct {
    void        *seq;    /* pointer to a seq (could be an ALSeq or an ALCSeq). */
} ALSeqpSeqEvent;

typedef struct {
    ALBank        *bank;
} ALSeqpBankEvent;

typedef struct {
    struct ALVoiceState_s      *vs;
    void                       *oscState;
    u8                         chan;
} ALOscEvent;

typedef struct {
    s16                     type;
    union {
        ALMIDIEvent         midi;
        ALTempoEvent        tempo;
        ALEndEvent          end;
        ALNoteEvent         note;
        ALVolumeEvent       vol;
        ALSeqpLoopEvent     loop;
        ALSeqpVolEvent      spvol;
        ALSeqpPriorityEvent    sppriority;
        ALSeqpSeqEvent        spseq;
        ALSeqpBankEvent        spbank;
        ALOscEvent          osc;
    } msg;
} ALEvent;

typedef struct {
    ALLink      freeList;
    ALLink      allocList;
    s32         eventCount;
} ALEventQueue;

typedef struct {
    ALInstrument        *instrument;    /* instrument assigned to this chan */
    s16                 bendRange;      /* pitch bend range in cents        */
    ALFxId              fxId;           /* type of fx assigned to this chan */
    ALPan               pan;            /* overall pan for this chan        */
    u8                  priority;       /* priority for this chan           */
    u8                  vol;            /* current volume for this chan     */
    u8                  fxmix;          /* current fx mix for this chan     */
    u8                  sustain;        /* current sustain pedal state      */
    f32                 pitchBend;      /* current pitch bend val in cents  */
} ALChanState;

typedef struct ALVoiceState_s {
    struct ALVoiceState_s *next;/* MUST be first                */
    ALVoice     voice;
    ALSound     *sound;
    ALMicroTime envEndTime;     /* time of envelope segment end */
    f32         pitch;          /* currect pitch ratio          */
    f32         vibrato;        /* current value of the vibrato */
    u8          envGain;        /* current envelope gain        */
    u8          channel;        /* channel assignment           */
    u8          key;            /* note on key number           */
    u8          velocity;       /* note on velocity             */
    u8          envPhase;       /* what envelope phase          */
    u8          phase;
    u8          tremelo;        /* current value of the tremelo */
    u8          flags;          /* bit 0 tremelo flag
                                   bit 1 vibrato flag           */
} ALVoiceState;

typedef struct ALSeq_s {
    u8          *base;                  /* ptr to start of sequence file   */
    u8          *trackStart;            /* ptr to first MIDI event         */
    u8          *curPtr;                /* ptr to next event to read       */
    s32         lastTicks;              /* MIDI ticks for last event       */
    s32         len;                    /* length of sequence in bytes     */
    f32         qnpt;                   /* qrter notes / tick (1/division) */
    s16         division;               /* ticks per quarter note          */
    s16         lastStatus;             /* for running status              */
} ALSeq;

typedef struct {
    u32      trackOffset[16];
    u32      division;
} ALCMidiHdr;

typedef struct ALCSeq_s {
    ALCMidiHdr    *base;             /* ptr to start of sequence file         */
    u32           validTracks;       /* set of flags, showing valid tracks    */
    f32           qnpt;              /* qrter notes / tick (1/division)       */
    u32           lastTicks;         /* keep track of ticks incase app wants  */
    u32           lastDeltaTicks;    /* number of delta ticks of last event   */
    u32          deltaFlag;         /* flag: set if delta's not subtracted   */
    u8            *curLoc[16];       /* ptr to current track location,        */
                                     /* may point to next event, or may point */
                                     /* to a backup code                      */
    u8            *curBUPtr[16];     /* ptr to next event if in backup mode   */
    u8            curBULen[16];      /* if > 0, then in backup mode           */
    u8            lastStatus[16];    /* for running status                    */
    u32           evtDeltaTicks[16]; /* delta time to next event              */
} ALCSeq;

typedef struct {
    u32         validTracks;
    s32         lastTicks;
    u32         lastDeltaTicks;
    u8          *curLoc[16];
    u8          *curBUPtr[16];
    u8          curBULen[16];
    u8          lastStatus[16];
    u32         evtDeltaTicks[16];
} ALCSeqMarker;

typedef struct ALSeqpConfig_s {
    s32         maxVoices;         /* max number of voices to alloc    */
    s32         maxEvents;         /* max internal events to support   */
    u8          maxChannels;       /* max MIDI channels to support (16)*/
    u8          debugFlags;        /* control which error get reported */
    ALHeap      *heap;             /* ptr to initialized heap          */
    void        *initOsc;
    void        *updateOsc;
    void        *stopOsc;
} ALSeqpConfig;

typedef ALMicroTime   (*ALOscInit)(void **oscState,f32 *initVal, u8 oscType,
                                   u8 oscRate, u8 oscDepth, u8 oscDelay);
typedef ALMicroTime   (*ALOscUpdate)(void *oscState, f32 *updateVal);
typedef void          (*ALOscStop)(void *oscState);

typedef struct {
    ALPlayer            node;           /* note: must be first in structure */
    ALSynth             *drvr;          /* reference to the client driver   */
    ALSeq               *target;        /* current sequence                 */
    ALMicroTime         curTime;
    ALBank              *bank;          /* current ALBank                   */
    s32                 uspt;           /* microseconds per tick            */
    s32                 nextDelta;      /* microseconds to next callback    */
    s32                 state;
    u16                 chanMask;       /* active channels                  */
    s16                 vol;            /* overall sequence volume          */
    u8                  maxChannels;    /* number of MIDI channels          */
    u8                  debugFlags;     /* control which error get reported */
    ALEvent             nextEvent;
    ALEventQueue        evtq;
    ALMicroTime         frameTime;
    ALChanState         *chanState;     /* 16 channels for MIDI             */
    ALVoiceState        *vAllocHead;    /* list head for allocated voices   */
    ALVoiceState        *vAllocTail;    /* list tail for allocated voices   */
    ALVoiceState        *vFreeList;     /* list of free voice state structs */
    ALOscInit           initOsc;
    ALOscUpdate         updateOsc;
    ALOscStop           stopOsc;
    ALSeqMarker         *loopStart;
    ALSeqMarker         *loopEnd;
    s32                 loopCount;      /* -1 = loop forever, 0 = no loop   */
} ALSeqPlayer;

typedef struct {
    ALPlayer            node;           /* note: must be first in structure */
    ALSynth             *drvr;          /* reference to the client driver   */
    ALCSeq              *target;        /* current sequence                 */
    ALMicroTime         curTime;
    ALBank              *bank;          /* current ALBank                   */
    s32                 uspt;           /* microseconds per tick            */
    s32                 nextDelta;      /* microseconds to next callback    */
    s32                 state;
    u16                 chanMask;       /* active channels                  */
    s16                 vol;            /* overall sequence volume          */
    u8                  maxChannels;    /* number of MIDI channels          */
    u8                  debugFlags;     /* control which error get reported */
    ALEvent             nextEvent;
    ALEventQueue        evtq;
    ALMicroTime         frameTime;
    ALChanState         *chanState;     /* 16 channels for MIDI             */
    ALVoiceState        *vAllocHead;    /* list head for allocated voices   */
    ALVoiceState        *vAllocTail;    /* list tail for allocated voices   */
    ALVoiceState        *vFreeList;     /* list of free voice state structs */
    ALOscInit           initOsc;
    ALOscUpdate         updateOsc;
    ALOscStop           stopOsc;
} ALCSPlayer;

/*
 * Sequence data representation routines
 */
void    alSeqNew(ALSeq *seq, u8 *ptr, s32 len);
void    alSeqNextEvent(ALSeq *seq, ALEvent *event);
s32     alSeqGetTicks(ALSeq *seq);
f32     alSeqTicksToSec(ALSeq *seq, s32 ticks, u32 tempo);
u32     alSeqSecToTicks(ALSeq *seq, f32 sec, u32 tempo);
void    alSeqNewMarker(ALSeq *seq, ALSeqMarker *m, u32 ticks);
void    alSeqSetLoc(ALSeq *seq, ALSeqMarker *marker);
void    alSeqGetLoc(ALSeq *seq, ALSeqMarker *marker);
/*
 * Compact Sequence data representation routines
 */
void    alCSeqNew(ALCSeq *seq, u8 *ptr);
void    alCSeqNextEvent(ALCSeq *seq,ALEvent *evt);
s32     alCSeqGetTicks(ALCSeq *seq);
f32     alCSeqTicksToSec(ALCSeq *seq, s32 ticks, u32 tempo);
u32     alCSeqSecToTicks(ALCSeq *seq, f32 sec, u32 tempo);
void    alCSeqNewMarker(ALCSeq *seq, ALCSeqMarker *m, u32 ticks);
void    alCSeqSetLoc(ALCSeq *seq, ALCSeqMarker *marker);
void    alCSeqGetLoc(ALCSeq *seq, ALCSeqMarker *marker); 

/*
 * Sequence Player routines
 */
f32     alCents2Ratio(s32 cents);

void    alSeqpNew(ALSeqPlayer *seqp, ALSeqpConfig *config);
void    alSeqpDelete(ALSeqPlayer *seqp);
void    alSeqpSetSeq(ALSeqPlayer *seqp, ALSeq *seq);
ALSeq   *alSeqpGetSeq(ALSeqPlayer *seqp);
void    alSeqpPlay(ALSeqPlayer *seqp);
void    alSeqpStop(ALSeqPlayer *seqp);
s32     alSeqpGetState(ALSeqPlayer *seqp);
void    alSeqpSetBank(ALSeqPlayer *seqp, ALBank *b);
void    alSeqpSetTempo(ALSeqPlayer *seqp, s32 tempo);
s32     alSeqpGetTempo(ALSeqPlayer *seqp);
s16     alSeqpGetVol(ALSeqPlayer *seqp);        /* Master volume control */
void    alSeqpSetVol(ALSeqPlayer *seqp, s16 vol);
void    alSeqpLoop(ALSeqPlayer *seqp, ALSeqMarker *start, ALSeqMarker *end, s32 count);

void    alSeqpSetChlProgram(ALSeqPlayer *seqp, u8 chan, u8 prog);
s32     alSeqpGetChlProgram(ALSeqPlayer *seqp, u8 chan);
void    alSeqpSetChlFXMix(ALSeqPlayer *seqp, u8 chan, u8 fxmix);
u8      alSeqpGetChlFXMix(ALSeqPlayer *seqp, u8 chan);
void    alSeqpSetChlVol(ALSeqPlayer *seqp, u8 chan, u8 vol);
u8      alSeqpGetChlVol(ALSeqPlayer *seqp, u8 chan);
void    alSeqpSetChlPan(ALSeqPlayer *seqp, u8 chan, ALPan pan);
ALPan   alSeqpGetChlPan(ALSeqPlayer *seqp, u8 chan);
void    alSeqpSetChlPriority(ALSeqPlayer *seqp, u8 chan, u8 priority);
u8      alSeqpGetChlPriority(ALSeqPlayer *seqp, u8 chan);
void    alSeqpSendMidi(ALSeqPlayer *seqp, s32 ticks, u8 status, u8 byte1, u8 byte2);


/* Maintain backwards compatibility with old routine names. */
#define alSeqpSetProgram        alSeqpSetChlProgram
#define alSeqpGetProgram        alSeqpGetChlProgram
#define alSeqpSetFXMix          alSeqpSetChlFXMix
#define alSeqpGetFXMix          alSeqpGetChlFXMix
#define alSeqpSetPan            alSeqpSetChlPan
#define alSeqpGetPan            alSeqpGetChlPan
#define alSeqpSetChannelPriority    alSeqpSetChlPriority
#define alSeqpGetChannelPriority    alSeqpGetChlPriority



/*
 * Compressed Sequence Player routines
 */
void    alCSPNew(ALCSPlayer *seqp, ALSeqpConfig *config);
void    alCSPDelete(ALCSPlayer *seqp);
void    alCSPSetSeq(ALCSPlayer *seqp, ALCSeq *seq);
ALCSeq  *alCSPGetSeq(ALCSPlayer *seqp);
void    alCSPPlay(ALCSPlayer *seqp);
void    alCSPStop(ALCSPlayer *seqp);
s32     alCSPGetState(ALCSPlayer *seqp);
void    alCSPSetBank(ALCSPlayer *seqp, ALBank *b);
void    alCSPSetTempo(ALCSPlayer *seqp, s32 tempo);
s32     alCSPGetTempo(ALCSPlayer *seqp);
s16     alCSPGetVol(ALCSPlayer *seqp);
void    alCSPSetVol(ALCSPlayer *seqp, s16 vol);

void    alCSPSetChlProgram(ALCSPlayer *seqp, u8 chan, u8 prog);
s32     alCSPGetChlProgram(ALCSPlayer *seqp, u8 chan);
void    alCSPSetChlFXMix(ALCSPlayer *seqp, u8 chan, u8 fxmix);
u8      alCSPGetChlFXMix(ALCSPlayer *seqp, u8 chan);
void    alCSPSetChlPan(ALCSPlayer *seqp, u8 chan, ALPan pan);
ALPan   alCSPGetChlPan(ALCSPlayer *seqp, u8 chan);
void    alCSPSetChlVol(ALCSPlayer *seqp, u8 chan, u8 vol);
u8      alCSPGetChlVol(ALCSPlayer *seqp, u8 chan);
void    alCSPSetChlPriority(ALCSPlayer *seqp, u8 chan, u8 priority);
u8      alCSPGetChlPriority(ALCSPlayer *seqp, u8 chan);
void    alCSPSendMidi(ALCSPlayer *seqp, s32 ticks, u8 status,
                       u8 byte1, u8 byte2);


/* Maintain backwards compatibility with old routine names. */
#define alCSPSetProgram      alCSPSetChlProgram
#define alCSPGetProgram      alCSPGetChlProgram
#define alCSPSetFXMix        alCSPSetChlFXMix
#define alCSPGetFXMix        alCSPGetChlFXMix
#define alCSPSetPan          alCSPSetChlPan
#define alCSPGetPan          alCSPGetChlPan
#define alCSPSetChannelPriority    alCSPSetChlPriority
#define alCSPGetChannelPriority    alCSPGetChlPriority

#endif
