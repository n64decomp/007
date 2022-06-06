#include <ultra64.h>
#include <PR/libaudio.h>
#include "inflate/inflate.h"
#include "audi.h"
#include <bondconstants.h>
#include "decompress.h"
#include "dyn.h"
#include "memp.h"
#include "music.h"
#include "ramrom.h"
#include "snd.h"

/**
 * EU .data, offset from start of data_seg : 0x3570
*/

/**
 * @file music.c
 * This file contains code to init/load music from
 * ROM; play/stop specific tracks; and to fade in/out.
 */

#ifdef REFRESH_PAL
#define FADE_FRAMERATE 50.0f
#else
#define FADE_FRAMERATE 60.0f
#endif

/**
 * Similar to NUM_MUSIC_TRACKS, but also counts "NONE" track
 * and control sequence.
 */
#define MAX_NUM_MUSIC_TRACKS_W_NONE  (NUM_MUSIC_TRACKS + 2)

/**
 * Bytes allocated by call to mempAllocBytesInBank. This sets up a local heap,
 * the rest of the memory allocations in this file come from this heap.
 */
#define MUSIC_ALLOCATION_BYTES   0x2E000
#define MUSIC_MEMP_BANK                6

/**
 * This is an address (cast to pointer on use).
 */
#define ROM_MUSIC_START_OFFSET 0x10000U

#define MUSIC_SYN_CONFIG_MAX_P_VOICES   0x18
#define MUSIC_SYN_CONFIG_MAX_UPDATES    0x80

#define MUSIC_SEQ_CONFIG_MAX_VOICES     0x10
#define MUSIC_SEQ_CONFIG_MAX_EVENTS     0x40
#define MUSIC_SEQ_CONFIG_MAX_CHANNELS     16

#define MUSIC_SFX_SEQ_CONFIG_MAYBE_SND_STATE_COUNT  0x40
#define MUSIC_SFX_SEQ_CONFIG_MAX_EVENTS             0x40
#define MUSIC_SFX_SEQ_MAYBE_MAX_SOUNDS                 8

// 
// carnivorous shared default midi allocations from editor:
// main address: 80710800
// main size: 5000
// watch size: 1000
// xtrack size: 3000
#define TRACK_1_DATA_SEQ_SIZE_BYTES   6344
#define TRACK_2_DATA_SEQ_SIZE_BYTES   2000
#define TRACK_3_DATA_SEQ_SIZE_BYTES   4000

#define MUSIC_CONFIG_USE_SFX_BANK         1
#define MUSIC_CONFIG_USE_INSTRUMENT_BANK  1

// TODO: what is this?
// This is only used when playing a file (loading from ROM),
// but the only thing used is the seqData pointer, the large array
// seems unused.
struct music_struct_b {
    u8 data[8438];
    u8 *seqData;
};

s32 g_musicUnused = 0;

/**
 * Current playing track. Sometimes compared to zero to check
 * if there is any currently playing music.
 * Address 0x80024334.
 */
s32 g_musicXTrack1CurrentTrackNum = 0;

/**
 * Address 0x80024338.
 */
u16 g_musicXTrack1Volume = VOLUME_MAX;

/**
 * Current playing track. Sometimes compared to zero to check
 * if there is any currently playing music.
 * Address 0x8002433C.
 */
s32 g_musicXTrack2CurrentTrackNum = 0;

/**
 * Address 0x80024340.
 */
u16 g_musicXTrack2Volume = VOLUME_MAX;

/**
 * Current playing track. Sometimes compared to zero to check
 * if there is any currently playing music.
 * Address 0x80024344.
 */
s32 g_musicXTrack3CurrentTrackNum = 0;

/**
 * Address 0x80024348.
 */
u16 g_musicXTrack3Volume = VOLUME_MAX;

/**
 * Current fade in/out state.
 * Address 0x8002434c.
 */
s32 g_musicXTrack1Fade = MUSIC_FADESTATE_UNSET;

/**
 * Current fade in/out state.
 * Address 0x80024350.
 */
s32 g_musicXTrack2Fade = MUSIC_FADESTATE_UNSET;

/**
 * Current fade in/out state.
 * Address 0x80024354.
 */
s32 g_musicXTrack3Fade = MUSIC_FADESTATE_UNSET;

/**
 * This serves a two part purpose.
 * 1) This is the default volume for music tracks, in the sense of default-on-boot value.
 * 2) At run time, a new "default" can be set for a track, and that will overwrite the value here.
 */
s16 g_musicDefaultTrackVolume[MAX_NUM_MUSIC_TRACKS_W_NONE] = {
    /**
     * Index 0, M_NONE.
     */
    0x6665,

    /**
     * Index 1, M_SHORT_SOLO_DEATH.
     */
    0x7332,
    
    /**
     * Index 2, M_INTRO.
     */
    0x7332,
    
    /**
     * Index 3, M_TRAIN.
     */
    0x7998,
    
    /**
     * Index 4, M_DEPOT.
     */
    0x7332,
    
    /**
     * Index 5, M_MPTHEME.
     */
    0x5998,
    
    /**
     * Index 6, M_CITADEL.
     */
    0x6665,
    
    /**
     * Index 7, M_FACILITY.
     */
    0x6665,
    
    /**
     * Index 8, M_CONTROL.
     */
    0x6665,
    
    /**
     * Index 9, M_DAM.
     */
    0x6665,
    
    /**
     * Index 10, M_FRIGATE.
     */
    0x7332,
    
    /**
     * Index 11, M_ARCHIVES.
     */
    0x6665,
    
    /**
     * Index 12, M_SILO.
     */
    0x7332,
    
    /**
     * Index 13, M_MPTHEME2.
     */
    0x6665,
    
    /**
     * Index 14, M_STREETS.
     */
    0x6665,
    
    /**
     * Index 15, M_BUNKER1.
     */
    0x7332,
    
    /**
     * Index 16, M_BUNKER2.
     */
    0x7332,
    
    /**
     * Index 17, M_STATUE.
     */
    0x6665,
    
    /**
     * Index 18, M_ELEVATOR_CONTROL.
     */
    0x3FFF,
    
    /**
     * Index 19, M_CRADLE.
     */
    0x6665,
    
    /**
     * Index 20, M_UNK.
     */
    0x6665,
    
    /**
     * Index 21, M_ELEVATOR_WC.
     */
    0x3FFF,
    
    /**
     * Index 22, M_EGYPTIAN.
     */
    0x6665,
    
    /**
     * Index 23, M_FOLDERS.
     */
    0x6665,
    
    /**
     * Index 24, M_WATCH.
     */
    0x6665,
    
    /**
     * Index 25, M_AZTEC.
     */
    0x6665,
    
    /**
     * Index 26, M_WATERCAVERNS.
     */
    0x6665,
    
    /**
     * Index 27, M_DEATHSOLO.
     */
    0x7998,
    
    /**
     * Index 28, M_SURFACE2.
     */
    0x6665,
    
    /**
     * Index 29, M_TRAINX.
     */
    0x5998,
    
    /**
     * Index 30, M_UNK2.
     */
    0x6665,
    
    /**
     * Index 31, M_FACILITYX.
     */
    0x6665,
    
    /**
     * Index 32, M_DEPOTX.
     */
    0x6665,
    
    /**
     * Index 33, M_CONTROLX.
     */
    0x6665,
    
    /**
     * Index 34, M_WATERCAVERNSX.
     */
    0x6665,
    
    /**
     * Index 35, M_DAMX.
     */
    0x6665,
    
    /**
     * Index 36, M_FRIGATEX.
     */
    0x6665,
    
    /**
     * Index 37, M_ARCHIVESX.
     */
    0x5998,
    
    /**
     * Index 38, M_SILOX.
     */
    0x6665,
    
    /**
     * Index 39, M_EGYPTIANX.
     */
    0x3332,
    
    /**
     * Index 40, M_STREETSX.
     */
    0x6665,
    
    /**
     * Index 41, M_BUNKER1X.
     */
    0x7332,
    
    /**
     * Index 42, M_BUNKER2X.
     */
    0x7332,
    
    /**
     * Index 43, M_JUNGLEX.
     */
    0x5998,
    
    /**
     * Index 44, M_INTROSWOOSH.
     */
    0x7332,
    
    /**
     * Index 45, M_STATUEX.
     */
    0x6665,
    
    /**
     * Index 46, M_AZTECX.
     */
    0x6665,
    
    /**
     * Index 47, M_EGYPTX.
     */
    0x6665,
    
    /**
     * Index 48, M_CRADLEX.
     */
    0x6665,
    
    /**
     * Index 49, M_CUBA.
     */
    0x6665,
    
    /**
     * Index 50, M_RUNWAY.
     */
    0x6665,
    
    /**
     * Index 51, M_RUNWAYPLANE.
     */
    0x6665,
    
    /**
     * Index 52, M_MPTHEME3.
     */
    0x6CCB,
    
    /**
     * Index 53, M_WIND.
     */
    0x6665,
    
    /**
     * Index 54, M_GUITARGLISS.
     */
    0x6665,
    
    /**
     * Index 55, M_JUNGLE.
     */
    0x6665,
    
    /**
     * Index 56, M_RUNWAYX.
     */
    0x6665,
    
    /**
     * Index 57, M_SURFACE1.
     */
    0x6665,
    
    /**
     * Index 58, M_MPDEATH.
     */
    0x6665,
    
    /**
     * Index 59, M_SURFACE2X.
     */
    0x6665,
    
    /**
     * Index 60, M_SURFACE2END.
     */
    0x7332,
    
    /**
     * Index 61, M_STATUEPART.
     */
    0x6665,
    
    /**
     * Index 62, M_END_SOMETHING.
     */
    0x7332,
    
    /**
     * Index 63, unknown / unused / removed.
     */
    0x7998,

    /**
     * Index 64, control sequence. (some loops check for 0xffff).
     */
    0xFFFF
};

ALHeap g_musicHeap;

/**
 * Sound bank data.
 */
ALBank *g_musicSfxBufferPtr;

/**
 * Name comes from referencing _instrumentstblSegmentRomStart
 */
ALBank *g_musicInstrumentBufferPtr;

ALCSPlayer *g_musicXTrack1SeqPlayer;
ALCSPlayer *g_musicXTrack2SeqPlayer;
ALCSPlayer *g_musicXTrack3SeqPlayer;

RareALSeqBankFile *g_musicDataTable;

/**
 * Length of music track after uncompressed.
 */
u16 g_musicTrackLength[NUM_MUSIC_TRACKS + 1];

/**
 * ROM lengths for music tracks. This is 1172 compressed length.
 */
u16 g_musicTrackCompressedLength[NUM_MUSIC_TRACKS];


s16 g_musicUnused80063836;

/**
* Compact sequence data pointer, track 1.
*/
u8 *g_musicXTrack1SeqData;

/**
* Compact sequence data pointer, track 2.
*/
u8 *g_musicXTrack2SeqData;

/**
* Compact sequence data pointer, track 3.
*/
u8 *g_musicXTrack3SeqData;

/**
 * Volume of the music track saved at start of fade out.
 */
u16 g_musicXTrack1PreFadeSavedVolume;

/**
 * Volume of the music track saved at start of fade out.
 */
u16 g_musicXTrack2PreFadeSavedVolume;

/**
 * Volume of the music track saved at start of fade out.
 */
u16 g_musicXTrack3PreFadeSavedVolume;

/**
 * Destination volume of fade. For example, for full fade out this will be zero.
 */
s16 g_musicXTrack1FadeToVolume;

/**
 * Destination volume of fade. For example, for full fade out this will be zero.
 */
s16 g_musicXTrack2FadeToVolume;

/**
 * Destination volume of fade. For example, for full fade out this will be zero.
 */
s16 g_musicXTrack3FadeToVolume;

/**
 * Number of frames remaining for the current fade out.
 */
s32 g_musicXTrack1FadeRemainingFrames;

/**
 * Number of frames remaining for the current fade out.
 */
s32 g_musicXTrack2FadeRemainingFrames;

/**
 * Number of frames remaining for the current fade out.
 */
s32 g_musicXTrack3FadeRemainingFrames;

s32 g_musicUnused8006385C;

/**
 *  compact sequence, track 1
 */
ALCSeq g_musicXTrack1Seq;

/**
 *  compact sequence, track 2
 */
ALCSeq g_musicXTrack2Seq;

/**
 *  compact sequence, track 3
 */
ALCSeq g_musicXTrack3Seq;

s32 g_musicUnused80063B58;
s32 g_musicUnused80063B54;

ALSndPlayer g_sndPlayer;

/**
 * Sfx volume array. This is the applied volume (what you hear in game).
 * The watch menu "fx" volume slider will change all these values.
 * min value = 0, max value = 0x7fff.
 */
s16 *g_sndSfxSlotVolume;

/**
 * Sfx volume array. This is the original unscaled volume set at level load.
 * The watch menu "fx" volume slider will change all these values, but otherwise seems
 * unused.
 * min value = 0, max value = 0x7fff.
 */
u16 *g_sndSfxSlotNaturalVolume;

extern u32 _sfxtblSegmentRomStart;
extern u32 _sfxctlSegmentRomStart;
extern u32 _instrumentstblSegmentRomStart;
extern u32 _instrumentsctlSegmentRomStart;
extern u32 _musicsampletblSegmentRomStart;

/**
 * 75F0	700069F0
 * Patch the file so that offsets are pointers.
 * This is a copy of alSeqFileNew from n64devkit\ultra\usr\src\pr\libsrc\libultra\audio\bnkf.c
 */
void musicSeqFileNew(RareALSeqBankFile *file, u8 *base)
{
    s32 offset = (s32) base;
    s32 i;
    
    /*
     * patch the file so that offsets are pointers
     */
    for (i = 0; i < file->seqCount; i++) {
        file->seqArray[i].address = (u8 *)((u8 *)file->seqArray[i].address + offset);
    }
}

/**
 * 7630	70006A30
 *     loads sound and music banks into memory segment 6
 * 
 * Seems to be roughly based on auSeqPlayerInit in n64devkit\ultra\usr\src\pr\demos_old\nnsample2\audio.c
 */
void musicSeqPlayerInit(void)
{
    // guess at struct.
    ALSeqpSfxConfig sfxSeqpConfig; // sp 216-228
    ALBankFile *sfxBank; // sp 212
    u32 ui;
    ALBankFile *instrumentBank; // sp 204

    // This type/cast is not correct, but this is how it matches.
    s32 tblSegmentRomStartAddress = (s32)&_musicsampletblSegmentRomStart; // ??

    ALSynConfig synconfig; // sp 164-192
    ALSeqpConfig track1SeqpConfig; // sp 136-160
    ALSeqpConfig track2SeqpConfig; // sp 108-132
    ALSeqpConfig track3SeqpConfig; // sp 80-104
    u8 *mempAddress;
    u8 *p;
    u16 d;
    u32 tblSegmentSize; // sp 64
    u32 size; // sp56;
    
    if (g_sndBootswitchSound)
    {
        return;
    }

    p = (u8 *)mempAllocBytesInBank(MUSIC_ALLOCATION_BYTES, MUSIC_MEMP_BANK);

    mempAddress = p;
    do
    {
        *p++ = 0;
    } while (p < mempAddress + MUSIC_ALLOCATION_BYTES);

    alHeapInit(&g_musicHeap, mempAddress, MUSIC_ALLOCATION_BYTES);

    if (MUSIC_CONFIG_USE_SFX_BANK)
    {
        size = (u32)&_sfxtblSegmentRomStart - (u32)&_sfxctlSegmentRomStart;

        sfxBank = alHeapAlloc(&g_musicHeap, 1, size);
        romCopy(sfxBank, &_sfxctlSegmentRomStart, size);
        alBnkfNew(sfxBank, (u8 *)&_sfxtblSegmentRomStart);
        g_musicSfxBufferPtr = sfxBank->bankArray[0];
    }

    if (MUSIC_CONFIG_USE_INSTRUMENT_BANK)
    {
        size = (u32)&_instrumentstblSegmentRomStart - (u32)&_instrumentsctlSegmentRomStart;

        instrumentBank = alHeapAlloc(&g_musicHeap, 1, size);
        romCopy(instrumentBank, &_instrumentsctlSegmentRomStart, size);
        alBnkfNew(instrumentBank, (u8 *)&_instrumentstblSegmentRomStart);
        g_musicInstrumentBufferPtr = instrumentBank->bankArray[0];
    }

    // this area based on auReadSeqFileHeader

    // is this sizeof(RareALSeqBankFile) ? which implies the struct isn't right...
    size = 0x10;
    g_musicDataTable = alHeapAlloc(&g_musicHeap, 1, size);
    romCopy(g_musicDataTable, (void *)tblSegmentRomStartAddress, size);

    tblSegmentSize = (sizeof(RareALSeqData) * g_musicDataTable->seqCount) + 4;
    g_musicDataTable = alHeapAlloc(&g_musicHeap, 1, tblSegmentSize);
    romCopy(g_musicDataTable, (void *)tblSegmentRomStartAddress, ALIGN16_a(tblSegmentSize));

    // end auReadSeqFileHeader

    musicSeqFileNew(g_musicDataTable, (u8*)&_musicsampletblSegmentRomStart);
    
    size = TRACK_1_DATA_SEQ_SIZE_BYTES;
    g_musicXTrack1SeqData = alHeapAlloc(&g_musicHeap, 1, size);

    size = TRACK_2_DATA_SEQ_SIZE_BYTES + TRACK_3_DATA_SEQ_SIZE_BYTES;
    g_musicXTrack2SeqData = alHeapAlloc(&g_musicHeap, 1, size);
    
    g_musicXTrack3SeqData = (u8*)g_musicXTrack2SeqData + TRACK_2_DATA_SEQ_SIZE_BYTES;

    // This 'for' loops seems to load track offsets, and lengths one time at init.
    // devkit example does this on demand.
    // see auSeqPlayerSetFile in n64devkit\ultra\usr\src\pr\demos_old\nnsample1\audio.c
    for (ui = 0; ui < NUM_MUSIC_TRACKS; ui++)
    {
        g_musicTrackLength[ui] = g_musicDataTable->seqArray[ui].uncompressed_len;
        g_musicTrackCompressedLength[ui] = g_musicDataTable->seqArray[ui].len;

        // Note that auSeqPlayerSetFile adjusts the len value, not offset.
        if (g_musicTrackLength[ui] & 1)
        {
            g_musicTrackLength[ui]++;
        }
    }

    synconfig.maxVVoices = 0;
    synconfig.maxPVoices = MUSIC_SYN_CONFIG_MAX_P_VOICES;
    synconfig.maxUpdates = MUSIC_SYN_CONFIG_MAX_UPDATES;
    // synconfig.maxFXbusses, not set.
    synconfig.dmaproc = 0;
    synconfig.fxType = AL_FX_CUSTOM;
    synconfig.outputRate = 0;
    synconfig.heap = &g_musicHeap;
    // synconfig.params, not set.

    amCreateAudioManager(&synconfig);

    track1SeqpConfig.maxVoices = MUSIC_SEQ_CONFIG_MAX_VOICES;
    track1SeqpConfig.maxEvents = MUSIC_SEQ_CONFIG_MAX_EVENTS;
    track1SeqpConfig.maxChannels = MUSIC_SEQ_CONFIG_MAX_CHANNELS;
    track1SeqpConfig.heap = &g_musicHeap;
    track1SeqpConfig.initOsc = NULL;
    track1SeqpConfig.updateOsc = NULL;
    track1SeqpConfig.stopOsc = NULL;

    track2SeqpConfig.maxVoices = MUSIC_SEQ_CONFIG_MAX_VOICES;
    track2SeqpConfig.maxEvents = MUSIC_SEQ_CONFIG_MAX_EVENTS;
    track2SeqpConfig.maxChannels = MUSIC_SEQ_CONFIG_MAX_CHANNELS;
    track2SeqpConfig.heap = &g_musicHeap;
    track2SeqpConfig.initOsc = NULL;
    track2SeqpConfig.updateOsc = NULL;
    track2SeqpConfig.stopOsc = NULL;

    track3SeqpConfig.maxVoices = MUSIC_SEQ_CONFIG_MAX_VOICES;
    track3SeqpConfig.maxEvents = MUSIC_SEQ_CONFIG_MAX_EVENTS;
    track3SeqpConfig.maxChannels = MUSIC_SEQ_CONFIG_MAX_CHANNELS;
    track3SeqpConfig.heap = &g_musicHeap;
    track3SeqpConfig.initOsc = NULL;
    track3SeqpConfig.updateOsc = NULL;
    track3SeqpConfig.stopOsc = NULL;

    size = sizeof(ALCSPlayer); // 0x7C
    g_musicXTrack1SeqPlayer = alHeapAlloc(&g_musicHeap, 1, size);
    g_musicXTrack2SeqPlayer = alHeapAlloc(&g_musicHeap, 1, size);
    g_musicXTrack3SeqPlayer = alHeapAlloc(&g_musicHeap, 1, size);

    // Typo / mistake, the following calls to alSeqpSetBank should actually
    // be to alCSPSetBank.
    alCSPNew(g_musicXTrack1SeqPlayer, &track1SeqpConfig);
    alSeqpSetBank((ALSeqPlayer *)g_musicXTrack1SeqPlayer, g_musicInstrumentBufferPtr);
    alCSPNew(g_musicXTrack2SeqPlayer, &track2SeqpConfig);
    alSeqpSetBank((ALSeqPlayer *)g_musicXTrack2SeqPlayer, g_musicInstrumentBufferPtr);
    alCSPNew(g_musicXTrack3SeqPlayer, &track3SeqpConfig);
    alSeqpSetBank((ALSeqPlayer *)g_musicXTrack3SeqPlayer, g_musicInstrumentBufferPtr);

    sfxSeqpConfig.maxEvents = MUSIC_SFX_SEQ_CONFIG_MAX_EVENTS;
    sfxSeqpConfig.maybeSndStateCount = MUSIC_SFX_SEQ_CONFIG_MAYBE_SND_STATE_COUNT;
    sfxSeqpConfig.maybeMaxSounds = MUSIC_SFX_SEQ_MAYBE_MAX_SOUNDS;
    sfxSeqpConfig.heap = &g_musicHeap;
    
    sndNewPlayerInit(&sfxSeqpConfig);
    amStartAudioThread();
}

/**
 * 7A7C	70006E7C
 * If sound boot flag is set, nothing happens.
 * If current track number is set, will call the stop playing method.
 * Does not change g_musicXTrack1Fade, but will update current track number.
 * Waits for the sequence playing to finish "doing things" and then loads music:
 * - gets the track ROM location and size (previously set on init).
 * - copies ths ROM data to a buffer, and decompresses the content
 * - sets up the cseq player and calls alCSPPlay
 * 
 * @param track: track number to play.
 */
void musicTrack1Play(s32 track)
{
    u32 trackSizeBytes;
    struct music_struct_b thing;
    u8 *temp_a0;
    void *romAddress;
    u32 t3;
    struct huft hlist;

    if (g_sndBootswitchSound)
    {
        return;
    }

    if (g_musicXTrack1CurrentTrackNum)
    {
        musicTrack1Stop();
    }

    g_musicXTrack1CurrentTrackNum = track;

    while (alCSPGetState(g_musicXTrack1SeqPlayer))
        ;

    romAddress = g_musicDataTable->seqArray[g_musicXTrack1CurrentTrackNum].address;

    if (romAddress < (void*)ROM_MUSIC_START_OFFSET)
    {
        // Note: recursive call
        musicTrack1Play(M_SHORT_SOLO_DEATH);

        return;
    }

    t3 = ALIGN16_a(g_musicTrackLength[g_musicXTrack1CurrentTrackNum]) + ALIGN16_a(NUM_MUSIC_TRACKS);
    trackSizeBytes = ALIGN16_a(g_musicTrackCompressedLength[g_musicXTrack1CurrentTrackNum]);
    thing.seqData = g_musicXTrack1SeqData;
    temp_a0 = (u8*)((t3 + (s32)thing.seqData) - trackSizeBytes);

    romCopy(temp_a0, romAddress, trackSizeBytes);
    decompressdata(temp_a0, thing.seqData, &hlist);

    alCSeqNew(&g_musicXTrack1Seq, g_musicXTrack1SeqData);
    alCSPSetSeq(g_musicXTrack1SeqPlayer, &g_musicXTrack1Seq);
    musicTrack1ApplySeqpVol(musicTrack1GetVolume());
    alCSPPlay(g_musicXTrack1SeqPlayer);
}

/**
 * 7BD0	70006FD0
 * If sound boot flag is is set, nothing happens.
 * Updates internal variables to stopped state, regardless of current state.
 * If there's a current track set, and the cseq player is "doing something", 
 * calls alCSPStop on sequence player. 
 * Sets g_musicXTrack1Fade to MUSIC_FADESTATE_UNSET,
 * and current track to zero.
 */
void musicTrack1Stop(void)
{
    if (g_sndBootswitchSound)
    {
        return;
    }

    g_musicXTrack1Fade = MUSIC_FADESTATE_UNSET;

    if (g_musicXTrack1CurrentTrackNum != 0)
    {
        if (alCSPGetState(g_musicXTrack1SeqPlayer) == 1)
        {
            alCSPStop(g_musicXTrack1SeqPlayer);
        }
    }

    g_musicXTrack1CurrentTrackNum = 0;
}

/**
 * 7C30	70007030
 *     V0= [80024338]
 */
u16 musicTrack1GetVolume(void)
{
    return g_musicXTrack1Volume;
}

/**
 * 7C3C	7000703C
 * Sets the global variable storing the current volume.
 * This is scaled by the default volume for the specific song (e.g., M_INTRO)
 * and the cseq player volume is set to that value.
 */
void musicTrack1ApplySeqpVol(u16 volume)
{
    u32 t1 = volume;

    g_musicXTrack1Volume = (u16)t1;

    t1 *= g_musicDefaultTrackVolume[g_musicXTrack1CurrentTrackNum];

    // There's only one other relevant place in the code base that has a SRL by 0xf,
    // it matches __vsVol in n64devkit\ultra\usr\src\pr\libsrc\libultra\audio\seqplayer.c
    // but it's hard to say if it's related here or not.
    t1 >>= 15;

    alCSPSetVol(g_musicXTrack1SeqPlayer, t1);
}

/**
 * 7CA0	700070A0
 * g_musicDefaultTrackVolume is updated so that the currently playing
 * track's default volume is now the current volume.
 */
void musicTrack1SaveCurrentVolumeAsTrackDefault(void)
{
    s32 i;
    
    g_musicDefaultTrackVolume[g_musicXTrack1CurrentTrackNum] = musicTrack1GetVolume();

    for (i = 0; g_musicDefaultTrackVolume[i] >= 0; i++)
    {
        // removed;
    }
}

/**
 * 7CF8	700070F8
 * Updates internal variables to fadeout state, if not already fading out.
 * Starting/stopping output of audio is not directly managed here.
 * Sets g_musicXTrack1Fade to MUSIC_FADESTATE_UNSET.
 * 
 * @param fadeTime: length of time in seconds for fade to last. This number is 
 * multiplied by the FPS to get the number of frames fade should last.
 */
void musicTrack1FadeOut(f32 fadeTime)
{
    if (g_musicXTrack1Fade >= MUSIC_FADESTATE_UNSET)
    {
        g_musicXTrack1PreFadeSavedVolume = musicTrack1GetVolume();
        g_musicXTrack1FadeToVolume = 0;
        g_musicXTrack1FadeRemainingFrames = (s32) (fadeTime * FADE_FRAMERATE);
        g_musicXTrack1Fade = MUSIC_FADESTATE_FADE_OUT;
    }
}

/**
 * 7D68	70007168
 * Updates internal variables to fadein state, if not already fading in.
 * Calls alCSPPlay on cseq player. 
 * Sets g_musicXTrack1Fade to MUSIC_FADESTATE_FADE_IN.
 * 
 * @param fadeTime: length of time in seconds for fade to last. This number is 
 * multiplied by the FPS to get the number of frames fade should last.
 * 
 * @param volume: volume of track. Pass -1 to use previously saved volume.
 */
void musicTrack1FadeIn(f32 fadeTime, u16 volume)
{
    if (g_musicXTrack1Fade <= MUSIC_FADESTATE_UNSET)
    {
        alCSPPlay(g_musicXTrack1SeqPlayer);

        if (volume == 0xffff)
        {
            g_musicXTrack1FadeToVolume = g_musicXTrack1PreFadeSavedVolume;
        }
        else
        {
            g_musicXTrack1FadeToVolume = volume;
        }

        g_musicXTrack1PreFadeSavedVolume = 0;
        g_musicXTrack1FadeRemainingFrames = (s32) (fadeTime * FADE_FRAMERATE);
        g_musicXTrack1Fade = MUSIC_FADESTATE_FADE_IN;
    }
}

/**
 * 7E04	70007204
 * If sound boot flag is is set, nothing happens.
 * If current track number is set, will call the stop playing method.
 * Does not change g_musicXTrack2Fade, but will update current track number.
 * Waits for the sequence playing to finish "doing things" and then loads music:
 * - gets the track ROM location and size (previously set on init).
 * - copies ths ROM data to a buffer, and decompresses the content
 * - sets up the cseq player and calls alCSPPlay
 * 
 * @param track: track number to play.
 */
void musicTrack2Play(s32 track)
{
    u32 trackSizeBytes;
    struct music_struct_b thing;
    u8 *temp_a0;
    void *romAddress;
    u32 t3;
    struct huft hlist;

    if (g_sndBootswitchSound)
    {
        return;
    }

    if (g_musicXTrack2CurrentTrackNum)
    {
        musicTrack2Stop();
    }

    g_musicXTrack2CurrentTrackNum = track;

    while (alCSPGetState(g_musicXTrack2SeqPlayer))
        ;

    romAddress = g_musicDataTable->seqArray[g_musicXTrack2CurrentTrackNum].address;

    if (romAddress < (void*)ROM_MUSIC_START_OFFSET)
    {
        // Note: recursive call
        musicTrack2Play(M_SHORT_SOLO_DEATH);

        return;
    }

    t3 = ALIGN16_a(g_musicTrackLength[g_musicXTrack2CurrentTrackNum]) + ALIGN16_a(NUM_MUSIC_TRACKS);
    trackSizeBytes = ALIGN16_a(g_musicTrackCompressedLength[g_musicXTrack2CurrentTrackNum]);
    thing.seqData = g_musicXTrack2SeqData;
    temp_a0 = (u8*)((t3 + (s32)thing.seqData) - trackSizeBytes);

    romCopy(temp_a0, romAddress, trackSizeBytes);
    decompressdata(temp_a0, thing.seqData, &hlist);

    alCSeqNew(&g_musicXTrack2Seq, g_musicXTrack2SeqData);
    alCSPSetSeq(g_musicXTrack2SeqPlayer, &g_musicXTrack2Seq);
    musicTrack2ApplySeqpVol(musicTrack2GetVolume());
    alCSPPlay(g_musicXTrack2SeqPlayer);
}

/**
 * 7F58	70007358
 * If sound boot flag is is set, nothing happens.
 * Updates internal variables to stopped state, regardless of current state.
 * If there's a current track set, and the cseq player is "doing something", 
 * calls alCSPStop on sequence player. 
 * Sets g_musicXTrack2Fade to MUSIC_FADESTATE_UNSET,
 * and current track to zero.
 */
void musicTrack2Stop(void)
{
    if (g_sndBootswitchSound)
    {
        return;
    }

    g_musicXTrack2Fade = MUSIC_FADESTATE_UNSET;

    if (g_musicXTrack2CurrentTrackNum != 0)
    {
        if (alCSPGetState(g_musicXTrack2SeqPlayer) == 1)
        {
            alCSPStop(g_musicXTrack2SeqPlayer);
        }
    }

    g_musicXTrack2CurrentTrackNum = 0;
}

/**
 * 7FB8	700073B8
 *     V0= [80024340]
 */
u16 musicTrack2GetVolume(void)
{
    return g_musicXTrack2Volume;
}

/**
 * 7FC4	700073C4
 * 
 * Sets the global variable storing the current volume.
 * This is scaled by the default volume for the specific song (e.g., M_INTRO)
 * and the cseq player volume is set to that value.
 */
void musicTrack2ApplySeqpVol(u16 volume)
{
    u32 t1 = volume;

    g_musicXTrack2Volume = (u16)t1;

    t1 *= g_musicDefaultTrackVolume[g_musicXTrack2CurrentTrackNum];
    // There's only one other relevant place in the code base that has a SRL by 0xf,
    // it matches __vsVol in n64devkit\ultra\usr\src\pr\libsrc\libultra\audio\seqplayer.c
    // but it's hard to say if it's related here or not.
    t1 >>= 15;

    alCSPSetVol(g_musicXTrack2SeqPlayer, t1);
}

/**
 * 8028	70007428
 * g_musicDefaultTrackVolume is updated so that the currently playing
 * track's default volume is now the current volume.
 */
void musicTrack2SaveCurrentVolumeAsTrackDefault(void)
{
    s32 i;
    
    g_musicDefaultTrackVolume[g_musicXTrack2CurrentTrackNum] = musicTrack2GetVolume();

    for (i = 0; g_musicDefaultTrackVolume[i] >= 0; i++)
    {
        // removed;
    }
}

/**
 * 8080	70007480
 * Updates internal variables to fadeout state, if not already fading out.
 * Starting/stopping output of audio is not directly managed here.
 * Sets g_musicXTrack1Fade to MUSIC_FADESTATE_UNSET.
 * 
 * @param fadeTime: length of time in seconds for fade to last. This number is 
 * multiplied by the FPS to get the number of frames fade should last.
 */
void musicTrack2FadeOut(f32 fadeTime)
{
    if (g_musicXTrack2Fade >= MUSIC_FADESTATE_UNSET)
    {
        g_musicXTrack2PreFadeSavedVolume = musicTrack2GetVolume();
        g_musicXTrack2FadeToVolume = 0;
        g_musicXTrack2FadeRemainingFrames = (s32) (fadeTime * FADE_FRAMERATE);
        g_musicXTrack2Fade = MUSIC_FADESTATE_FADE_OUT;
    }
}

/**
 * 80F0	700074F0
 * Updates internal variables to fadein state, if not already fading in.
 * Calls alCSPPlay on cseq player. 
 * Sets g_musicXTrack1Fade to MUSIC_FADESTATE_FADE_IN.
 * 
 * @param fadeTime: length of time in seconds for fade to last. This number is 
 * multiplied by the FPS to get the number of frames fade should last.
 * 
 * @param volume: volume of track. Pass -1 to use previously saved volume.
 */
void musicTrack2FadeIn(f32 fadeTime, u16 volume)
{
    if (g_musicXTrack2Fade <= MUSIC_FADESTATE_UNSET)
    {
        alCSPPlay(g_musicXTrack2SeqPlayer);

        if (volume == 0xffff)
        {
            g_musicXTrack2FadeToVolume = g_musicXTrack2PreFadeSavedVolume;
        }
        else
        {
            g_musicXTrack2FadeToVolume = volume;
        }

        g_musicXTrack2PreFadeSavedVolume = 0;
        g_musicXTrack2FadeRemainingFrames = (s32) (fadeTime * FADE_FRAMERATE);
        g_musicXTrack2Fade = MUSIC_FADESTATE_FADE_IN;
    }
}

/**
 * 818C	7000758C
 * If sound boot flag is is set, nothing happens.
 * If current track number is set, will call the stop playing method.
 * Does not change g_musicXTrack3Fade, but will update current track number.
 * Waits for the sequence playing to finish "doing things" and then loads music:
 * - gets the track ROM location and size (previously set on init).
 * - copies ths ROM data to a buffer, and decompresses the content
 * - sets up the cseq player and calls alCSPPlay
 * 
 * @param track: track number to play.
 */
void musicTrack3Play(s32 track)
{
    u32 trackSizeBytes;
    struct music_struct_b thing;
    u8 *temp_a0;
    void *romAddress;
    u32 t3;
    struct huft hlist;

    if (g_sndBootswitchSound)
    {
        return;
    }

    if (g_musicXTrack3CurrentTrackNum)
    {
        musicTrack3Stop();
    }

    g_musicXTrack3CurrentTrackNum = track;

    while (alCSPGetState(g_musicXTrack3SeqPlayer))
        ;

    romAddress = g_musicDataTable->seqArray[g_musicXTrack3CurrentTrackNum].address;

    if (romAddress < (void*)ROM_MUSIC_START_OFFSET)
    {
        // Note: recursive call
        musicTrack3Play(M_SHORT_SOLO_DEATH);

        return;
    }

    t3 = ALIGN16_a(g_musicTrackLength[g_musicXTrack3CurrentTrackNum]) + ALIGN16_a(NUM_MUSIC_TRACKS);
    trackSizeBytes = ALIGN16_a(g_musicTrackCompressedLength[g_musicXTrack3CurrentTrackNum]);
    thing.seqData = g_musicXTrack3SeqData;
    temp_a0 = (u8*)((t3 + (s32)thing.seqData) - trackSizeBytes);

    romCopy(temp_a0, romAddress, trackSizeBytes);
    decompressdata(temp_a0, thing.seqData, &hlist);

    alCSeqNew(&g_musicXTrack3Seq, g_musicXTrack3SeqData);
    alCSPSetSeq(g_musicXTrack3SeqPlayer, &g_musicXTrack3Seq);
    musicTrack3ApplySeqpVol(musicTrack3GetVolume());
    alCSPPlay(g_musicXTrack3SeqPlayer);
}

/**
 * 82E0	700076E0
* If sound boot flag is is set, nothing happens.
 * Updates internal variables to stopped state, regardless of current state.
 * If there's a current track set, and the cseq player is "doing something", 
 * calls alCSPStop on sequence player. 
 * Sets g_musicXTrack3Fade to MUSIC_FADESTATE_UNSET,
 * and current track to zero.
 */
void musicTrack3Stop(void)
{
    if (g_sndBootswitchSound)
    {
        return;
    }

    g_musicXTrack3Fade = MUSIC_FADESTATE_UNSET;

    if (g_musicXTrack3CurrentTrackNum != 0)
    {
        if (alCSPGetState(g_musicXTrack3SeqPlayer) == 1)
        {
            alCSPStop(g_musicXTrack3SeqPlayer);
        }
    }

    g_musicXTrack3CurrentTrackNum = 0;
}

/**
 * 8340	70007740
 *     V0= 7FFF [80024348]
 */
u16 musicTrack3GetVolume(void)
{
    return g_musicXTrack3Volume;
}

/**
 * 834C	7000774C
 * 
 * Sets the global variable storing the current volume.
 * This is scaled by the default volume for the specific song (e.g., M_INTRO)
 * and the cseq player volume is set to that value.
 */
void musicTrack3ApplySeqpVol(u16 volume)
{
    u32 t1 = volume;

    g_musicXTrack3Volume = (u16)t1;

    t1 *= g_musicDefaultTrackVolume[g_musicXTrack3CurrentTrackNum];
    // There's only one other relevant place in the code base that has a SRL by 0xf,
    // it matches __vsVol in n64devkit\ultra\usr\src\pr\libsrc\libultra\audio\seqplayer.c
    // but it's hard to say if it's related here or not.
    t1 >>= 15;

    alCSPSetVol(g_musicXTrack3SeqPlayer, t1);
}

/**
 * 83B0	700077B0
 * g_musicDefaultTrackVolume is updated so that the currently playing
 * track's default volume is now the current volume.
 */
void musicTrack3SaveCurrentVolumeAsTrackDefault(void)
{
    s32 i;
    
    g_musicDefaultTrackVolume[g_musicXTrack3CurrentTrackNum] = musicTrack3GetVolume();

    for (i = 0; g_musicDefaultTrackVolume[i] >= 0; i++)
    {
        // removed;
    }
}

/**
 * 8408	70007808
 * Updates internal variables to fadeout state, if not already fading out.
 * Starting/stopping output of audio is not directly managed here.
 * Sets g_musicXTrack1Fade to MUSIC_FADESTATE_UNSET.
 * 
 * @param fadeTime: length of time in seconds for fade to last. This number is 
 * multiplied by the FPS to get the number of frames fade should last.
 */
void musicTrack3FadeOut(f32 fadeTime)
{
    if (g_musicXTrack3Fade >= MUSIC_FADESTATE_UNSET)
    {
        g_musicXTrack3PreFadeSavedVolume = musicTrack3GetVolume();
        g_musicXTrack3FadeToVolume = 0;
        g_musicXTrack3FadeRemainingFrames = (s32) (fadeTime * FADE_FRAMERATE);
        g_musicXTrack3Fade = MUSIC_FADESTATE_FADE_OUT;
    }
}

/**
 * 8478	70007878
 * Updates internal variables to fadein state, if not already fading in.
 * Calls alCSPPlay on cseq player. 
 * Sets g_musicXTrack1Fade to MUSIC_FADESTATE_FADE_IN.
 * 
 * @param fadeTime: length of time in seconds for fade to last. This number is 
 * multiplied by the FPS to get the number of frames fade should last.
 * 
 * @param volume: volume of track. Pass -1 to use previously saved volume.
 */
void musicTrack3FadeIn(f32 fadeTime, u16 volume)
{
    if (g_musicXTrack3Fade <= MUSIC_FADESTATE_UNSET)
    {
        alCSPPlay(g_musicXTrack3SeqPlayer);

        if (volume == 0xffff)
        {
            g_musicXTrack3FadeToVolume = g_musicXTrack3PreFadeSavedVolume;
        }
        else
        {
            g_musicXTrack3FadeToVolume = volume;
        }

        g_musicXTrack3PreFadeSavedVolume = 0;
        g_musicXTrack3FadeRemainingFrames = (s32) (fadeTime * FADE_FRAMERATE);
        g_musicXTrack3Fade = MUSIC_FADESTATE_FADE_IN;
    }
}

/**
 * 8514	70007914
 * Called by the scheduler to fade between music sources (e.g., level music -> watch pause music).
 */
void musicFadeTick(void)
{
    if (g_musicXTrack1Fade)
    {
        u16 t0;
        s32 t1;
        
        t0 = musicTrack1GetVolume();
        t1 = (u16)g_musicXTrack1FadeToVolume - t0;
        t0 += (s32) ((f32) t1 / (f32) g_musicXTrack1FadeRemainingFrames);

        musicTrack1ApplySeqpVol(t0);
        g_musicXTrack1FadeRemainingFrames--;

        if (g_musicXTrack1FadeRemainingFrames <= 0)
        {
            if (t0 == 0)
            {
                alCSPStop(g_musicXTrack1SeqPlayer);
            }

            g_musicXTrack1FadeRemainingFrames = 0;
            g_musicXTrack1Fade = MUSIC_FADESTATE_UNSET;
        }
    }

    if (g_musicXTrack2Fade)
    {
        u16 t0;
        s32 t1;

        t0 = musicTrack2GetVolume();
        t1 = (u16)g_musicXTrack2FadeToVolume - t0;
        t0 += (s32) ((f32) t1 / (f32) g_musicXTrack2FadeRemainingFrames);

        musicTrack2ApplySeqpVol(t0);
        g_musicXTrack2FadeRemainingFrames--;

        if (g_musicXTrack2FadeRemainingFrames <= 0)
        {
            if (t0 == 0)
            {
                alCSPStop(g_musicXTrack2SeqPlayer);
            }

            g_musicXTrack2FadeRemainingFrames = 0;
            g_musicXTrack2Fade = MUSIC_FADESTATE_UNSET;
        }
    }

    if (g_musicXTrack3Fade)
    {
        u16 t0;
        s32 t1;
        
        t0 = musicTrack3GetVolume();
        t1 = (u16)g_musicXTrack3FadeToVolume - t0;
        t0 += (s32) ((f32) t1 / (f32) g_musicXTrack3FadeRemainingFrames);

        musicTrack3ApplySeqpVol(t0);
        g_musicXTrack3FadeRemainingFrames--;

        if (g_musicXTrack3FadeRemainingFrames <= 0)
        {
            if (t0 == 0)
            {
                alCSPStop(g_musicXTrack3SeqPlayer);
            }

            g_musicXTrack3FadeRemainingFrames = 0;
            g_musicXTrack3Fade = MUSIC_FADESTATE_UNSET;
        }
    }
}
