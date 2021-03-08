#include "ultra64.h"
#include "sched.h"
#include "audi.h"

/**
 * @file audi.c
 * This file contains audio code. Starts main audio thread, handles some audio DMA.
 */

// 0x5622 = 22050
#define OUTPUT_RATE                    0x5622
#define MAYBE_FRAME_RATE                   60
#define FRAMES_PER_FIELD_AS_POW2            1
#define AUDIO_FRAME_MESSAGE_QUEUE_SIZE      8
#define AUDIO_REPLY_MESSAGE_QUEUE_SIZE      8
#define AUDIO_DMA_IO_QUEUE_SIZE            64
#define AUDIO_DMA_QUEUE_SIZE               66
#define AUDIO_DMA_MAX_BUFFER_LENGTH     0x200

#define NUMBER_OUTPUT_BUFFERS               3
#define NUMBER_ACMD_LISTS                   2
#define MAX_ACMD_SIZE                    3000
#define NUMBER_DMA_BUFFERS                 64
#define EXTRA_SAMPLES                    0x25
#define AUDIO_FRAME_MESSAGE_QUEUE_SIZE      8
#define AUDIO_REPLY_MESSAGE_QUEUE_SIZE      8

#define MAIN_QUIT_MESSAGE                  10
#define AUDIO_MANAGER_COUNT_INTERVAL     0xf0

extern long long int rspbootTextStart[];
extern long long int gsp3DTextStart[];
extern long long int aspMainTextStart[];
extern long long int aspMainDataStart[];
extern u8 sp_audi[];

/**
 * Copied from the n64devkit audio examples.
 * sizeof(struct DMABuffer_s) == 0x14 (20)
 */
typedef struct DMABuffer_s {
    /**
     * 0x0.
     */
    ALLink node;

    /**
     * 0x8.
     */
    int startAddr;

    /**
     * 0xc.
     */
    u32 lastFrame;

    /**
     * 0x10.
     */
    u8* ptr;
} DMABuffer;

/**
 * Copied from the n64devkit audio examples.
 * sizeof(struct DMAState_s) == 0xc (12).
 */
typedef struct DMAState_s {
    /**
     * This was defined (in the devkit) as u8 (and code expects a byte), but the size 
     * of the struct and offset for firstUsed seems to make this u32/s32.
     * I'm adding the union to make this explicit.
     * 0x0.
     */
    union {
        u8 initialized;
        s32 _unusedAlign;
    } u;

    /**
     * 0x4.
     */
    DMABuffer *firstUsed;

    /**
     * 0x8.
     */
    DMABuffer *firstFree;
} DMAState;

/**
 * Copied from the n64devkit audio examples.
 */
typedef union AudioMessage_u {
    struct {
        s16 type;
    } gen;
    
    struct {
        s16 type;
        struct AudioInfo_s *info;
    } done;
    
    OSScMsg app;
} AudioMessage;

/**
* Modified from n64devkit example.
* sizeof(struct _DMAState) == 0xc (12).
*/
typedef struct AudioInfo_s {
    /**
    * Output data pointer.
    * 0x0.
    */
    s16 *data;

    /**
     * # of samples synthesized in this frame
     * 0x4.
     */
    s16 frameSamples;

    /**
     * scheduler structure
     * 0x8
     */
    OSScTask task;
} AudioInfo;

// unknown purpose
u32 D_800230F0 = 0;

u32 g_AudioFrameCount = 0;

u32 g_NextDMa = 0;

u32 g_CurrentAcmdList = 0;

/*
* This macro is used/defined in both libultra and libnaudio
*/
#define ms *(((s32)((f32)44.1)) & ~0x7)

#define CUSTOM_FX_SECTION_COUNT   6
#define CUSTOM_FX_SECTION_SIZE    8
/*
* Following the libultra and libnaudio naming convention ...
*/
s32 CUSTOM_FX_PARAMS_N[CUSTOM_FX_SECTION_COUNT * CUSTOM_FX_SECTION_SIZE + 2] = {

    /* sections	   length */
             6,     160 ms,

    /*                                         chorus  chorus   filter
    input    output  fbcoef  ffcoef    gain     rate   depth    coef  */
        0,     4 ms,   9830,  -9830,      0,        0,     0,       0,
     4 ms,     8 ms,   9830,  -9830, 0x2B84,        0,     0,  0x2500,
    20 ms,    64 ms,  16384, -16384, 0x11EB,        0,     0,  0x3000,
    80 ms,   140 ms,  16384, -16384, 0x11EB,        0,     0,  0x3500,
    84 ms,   120 ms,   8192,  -8192,      0,        0,     0,  0x4000,
        0,   148 ms,  13000, -13000,      0,   0x017C,   0xA,  0x4500
};

s32 g_FirstTime = 1;

/*bss needs fixing */
s32 dword_CODE_bss_8005E4B0[2];

/**
 * Address 8005E4B8.
 * (type is u64)
 * Used in amMain.
 * This looks like it stores the largest sDeltaTime between
 * counts of AUDIO_MANAGER_COUNT_INTERVAL.
 */
OSTime g_LargestDeltaTime;

/**
 * Address 8005E4C0.
 * (type is u64)
 * Used in amMain.
 * Stores the elpased time of main loop (difference between sEndTime and sStartTime).
 */
#ifdef NONMATCHING
OSTime g_DeltaTime;
#else
s32 dword_CODE_bss_8005E4C0;
s32 dword_CODE_bss_8005E4C4;
#endif

/**
 * Address 8005E4C8.
 * Every AUDIO_MANAGER_COUNT_INTERVAL number of events, the average for sDeltaTimeSum
 * is computed and stored here.
 */
#ifdef NONMATCHING
u64 g_DeltaAverage;
#else
s32 dword_CODE_bss_8005E4C8;
s32 dword_CODE_bss_8005E4CC;
#endif

/**
 * Address 8005E4D0.
 * Tracks the sum total elapsed time. Reset every AUDIO_MANAGER_COUNT_INTERVAL.
 */
u64 g_DeltaTimeSum;

/**
 * Address 8005E4D8.
 * (type is u64)
 * Used in amMain.
 * Stores the time at the start of the loop.
 */
OSTime g_StartTime;

/**
 * Address 8005E4E0.
 * (type is u64)
 * Used in amMain.
 * Stores the time after primary processing is done.
 */
OSTime g_EndTime;

/**
 * Unknown / unused
 */
char dword_CODE_bss_8005E4E8[0x30];

/**
 * Address 8005e518.
 * sizeof(struct AudioManager_s) == 0x288 (648)
 */
struct AudioManager_s {

    /**
     * 0.
     */
    Acmd *cmdList[NUMBER_ACMD_LISTS];
    
    /**
     * 0x8.
     */
    AudioInfo *audioInfo[NUMBER_OUTPUT_BUFFERS];
    
    /**
    * 0x14.
    */
    u32 numberOutputBuffers;
    
    /**
     * 0x18.
     */
    OSThread audioThread;
    
    /**
     * 0x1c8.
     */
    OSMesgQueue frameMessageQueue;
    
    /**
     * 0x1e0.
     */
    OSMesg frameMessageBuffer[AUDIO_FRAME_MESSAGE_QUEUE_SIZE];
    
    /**
     * 0x200.
     */
    OSMesgQueue replyMessageQueue;

    /**
     * 0x218.
     */
    OSMesg replyMessageBuffer[AUDIO_REPLY_MESSAGE_QUEUE_SIZE];

    /**
     * 0x238
     */
    ALGlobals g;

} g_AudioManager;

/**
 * Address 0x8005e7a0.
 */
OSScClient g_AudioClient[2];

/**
 * Address 0x8005e7b0.
 */
DMAState g_DmaState;

DMABuffer g_DmaBuffers[NUMBER_DMA_BUFFERS];

u32 g_MinFrameSize;
u32 g_FrameSize;
u32 g_MaxFrameSize;
s32 g_CommandLength;

OSIoMesg g_DmaIOMessageBuffer[AUDIO_DMA_IO_QUEUE_SIZE];

OSMesgQueue g_DmaMessageQueue;

OSMesg g_DmaMessageBuffer[AUDIO_DMA_QUEUE_SIZE];


// Forward declarations
s32 amDmaCallback(s32 addr, s32 len, void* state);
void amClearDmaBuffers(void);
void amHandleFrameMessage(AudioInfo *info, AudioInfo *lastInfo);
void amHandleDoneMessage(AudioInfo *info);
void amMain(void* arg);
ALDMAproc amDmaNew(DMAState** state);


/**
 * Address 29D0 70001BD0
 *
 * Looks to be loosely based on method
 *     amCreateAudioMgr
 * from the n64devkit. 
 *
 * @param alconf hw setup/config.
 */
void amCreateAudioManager(ALSynConfig* alconf)
{
    u32 j;
    f32 fsize;

    alconf->dmaproc = &amDmaNew;
    alconf->outputRate = osAiSetFrequency(OUTPUT_RATE);
    
    fsize = (f32) ((alconf->outputRate << FRAMES_PER_FIELD_AS_POW2) / (f32)MAYBE_FRAME_RATE);
    
    g_FrameSize = (u32) fsize;

    if (g_FrameSize < fsize)
    {
        g_FrameSize++;
    }
    
    // This rounds up to the next multiple of 16.
    if (g_FrameSize & 0xf)
    {
        g_FrameSize = (g_FrameSize & ~0xf) + 0x10;
    }
    
    g_MinFrameSize = (u32)(g_FrameSize - 0x10);
    g_MaxFrameSize = (u32)(g_FrameSize + EXTRA_SAMPLES + 0x10);
    
    if (alconf->fxType == AL_FX_CUSTOM)
    {
        s32 sp48[CUSTOM_FX_SECTION_COUNT * CUSTOM_FX_SECTION_SIZE + 2] = CUSTOM_FX_PARAMS_N;
        alconf->params = sp48;
        alInit(&g_AudioManager.g, alconf);
    }
    else
    {
        alInit(&g_AudioManager.g, alconf);
    }
    
    for (j=0; j < NUMBER_OUTPUT_BUFFERS; j++)
    {
        g_AudioManager.audioInfo[j] = (AudioInfo *)alHeapDBAlloc(0, 0, alconf->heap, 1, sizeof(AudioInfo));
        g_AudioManager.audioInfo[j]->data = (s16*)alHeapDBAlloc(0, 0, alconf->heap, 1, g_MaxFrameSize * 4);
    }
    
    osCreateMesgQueue(&g_AudioManager.replyMessageQueue, (OSMesg*)&g_AudioManager.replyMessageBuffer, AUDIO_REPLY_MESSAGE_QUEUE_SIZE);
    osCreateMesgQueue(&g_AudioManager.frameMessageQueue, (OSMesg*)&g_AudioManager.frameMessageBuffer, AUDIO_FRAME_MESSAGE_QUEUE_SIZE);
    osCreateMesgQueue(&g_DmaMessageQueue, (OSMesg*)&g_DmaMessageBuffer, AUDIO_DMA_IO_QUEUE_SIZE);
    
    g_DmaBuffers[0].node.prev = NULL;
    g_DmaBuffers[0].node.next = NULL;

    for (j=0; (s32)j < NUMBER_DMA_BUFFERS - 1; j++)
    {
        alLink((ALLink*)&g_DmaBuffers[j+1], (ALLink*)&g_DmaBuffers[j]);
        g_DmaBuffers[j].ptr = (void*)alHeapDBAlloc(0, 0, alconf->heap, 1, AUDIO_DMA_MAX_BUFFER_LENGTH);
    }
    // last buffer already linked, but still needs buffer
    g_DmaBuffers[j].ptr = (void*)alHeapDBAlloc(0, 0, alconf->heap, 1, AUDIO_DMA_MAX_BUFFER_LENGTH);
    
    for (j=0; j < NUMBER_ACMD_LISTS; j++)
    {
        g_AudioManager.cmdList[j] = (Acmd *)alHeapDBAlloc(0, 0, alconf->heap, 1, MAX_ACMD_SIZE * sizeof(Acmd));
    }

    osCreateThread(&g_AudioManager.audioThread, 4, &amMain, 0, (void*)set_stack_entry((u8*)(&sp_audi), 0x1000), 0x14);
}

/**
 * 2B58 70001F58
 * insert sound manager thread
 *	redirect to 7000D580: A0=8005E530
 */
void amStartAudioThread(void)
{
    osStartThread(&g_AudioManager.audioThread);
}

#ifdef NONMATCHING
/**
 * 2B7C 70001F7C
 * Looks to be loosely based on method
 *     __amMain
 * from the n64devkit. This method makes some kind of video calls,
 * but also does some kind of debug tracking of the time spent between
 * beginning and end of processing.
 *
 * @param arg unused.
 *
 * decomp status:
 * - compiles: yes
 * - stack resize: ok
 * - identical instructions: fail
 * - identical registers: fail
 *
 * notes: It looks like there are a few issues.
 * 1) The static variables are being loaded into the wrong registers.
 *     This is sEndTime, sStartTime, sLargestDeltaTime.
 *     This causes trickle down differences.
 * 2) Inside the first if block, registers are saved onto the stack,
 *     but the stack locations differ.
 *     This causes trickle down differences.
 * 3) localDelta is probably a red herring, it makes the code close, but ...
 * 4) g_DeltaAverage and g_DeltaTime don't seem to be written correctly as u64.
 * Compare:
 4e8:	3c010000 	lui	at,0x0	4e8: R_MIPS_HI16	dword_CODE_bss_8005E4C0
 4ec:	006bc823 	subu	t9,v1,t3
 4f0:	ac390000 	sw	t9,0(at)	4f0: R_MIPS_LO16	dword_CODE_bss_8005E4C4
 4f4:	ac380000 	sw	t8,0(at)	4f4: R_MIPS_LO16	dword_CODE_bss_8005E4C0
 to
4e8:	3c010000 	lui	at,0x0	4e8: R_MIPS_HI16	g_DeltaTime
 4ec:	006bc823 	subu	t9,v1,t3
 4f0:	ac390004 	sw	t9,4(at)	4f0: R_MIPS_LO16	g_DeltaTime
 4f4:	ac380000 	sw	t8,0(at)	4f4: R_MIPS_LO16	g_DeltaTime
 */
void amMain(void* arg)
{
    s32 counter = 0;
    
    s32 done = 0;
    AudioMessage *msg = 0;
    AudioInfo *lastInfo = 0;
    u64 localDelta;

    osScAddClient(&sc, &(g_AudioClient[0]), &(g_AudioManager.frameMessageQueue), (void*)1);

    while (!done)
    {
        osRecvMesg(&g_AudioManager.frameMessageQueue, (OSMesg *)&msg, OS_MESG_BLOCK);
        
        switch (msg->gen.type)
        {
            case OS_SC_RETRACE_MSG:
            {
                g_StartTime = osGetTime();
                
                speedGraphVideoRelated_3(0x30000);
                amHandleFrameMessage(g_AudioManager.audioInfo[g_AudioFrameCount % 3U], lastInfo);
                counter++;
                speedGraphVideoRelated_3(0x60000);

                g_EndTime = osGetTime();
                
                localDelta = g_EndTime - g_StartTime;
                g_DeltaTime = localDelta;
            
                if ((counter % AUDIO_MANAGER_COUNT_INTERVAL) == 0)
                {
                    g_DeltaAverage = g_DeltaTimeSum / AUDIO_MANAGER_COUNT_INTERVAL;
                    
                    localDelta = g_EndTime - g_StartTime;
                    
                    g_DeltaTimeSum = 0U;
                    g_LargestDeltaTime = 0U;
                }
                else
                {
                    g_DeltaTimeSum = g_DeltaTimeSum + g_EndTime - g_StartTime;
                }

                if (g_LargestDeltaTime < localDelta)
                {
                    g_LargestDeltaTime = localDelta;
                }
                
                osRecvMesg(&g_AudioManager.replyMessageQueue, (OSMesg *)&lastInfo, OS_MESG_BLOCK);
                
                amHandleDoneMessage(lastInfo);
            }
                break;
                
            case 5:
                done = 1;
                break;
                
            case MAIN_QUIT_MESSAGE:
                done = 1;
                break;
                
            default:
                break;
        }
    }
    
    alClose(&(g_AudioManager.g));
}
#else
GLOBAL_ASM(
.text
glabel amMain
/* 002B7C 70001F7C 27BDFF90 */  addiu $sp, $sp, -0x70
/* 002B80 70001F80 AFB60030 */  sw    $s6, 0x30($sp)
/* 002B84 70001F84 3C168006 */  lui   $s6, %hi(g_AudioManager+0x1C8)
/* 002B88 70001F88 AFA40070 */  sw    $a0, 0x70($sp)
/* 002B8C 70001F8C 26D6E6E0 */  addiu $s6, %lo(g_AudioManager+0x1C8) # addiu $s6, $s6, -0x1920
/* 002B90 70001F90 AFBF003C */  sw    $ra, 0x3c($sp)
/* 002B94 70001F94 AFB20020 */  sw    $s2, 0x20($sp)
/* 002B98 70001F98 AFB1001C */  sw    $s1, 0x1c($sp)
/* 002B9C 70001F9C 3C048006 */  lui   $a0, %hi(sc)
/* 002BA0 70001FA0 3C058006 */  lui   $a1, %hi(g_AudioClient)
/* 002BA4 70001FA4 AFBE0038 */  sw    $fp, 0x38($sp)
/* 002BA8 70001FA8 AFB70034 */  sw    $s7, 0x34($sp)
/* 002BAC 70001FAC AFB5002C */  sw    $s5, 0x2c($sp)
/* 002BB0 70001FB0 AFB40028 */  sw    $s4, 0x28($sp)
/* 002BB4 70001FB4 AFB30024 */  sw    $s3, 0x24($sp)
/* 002BB8 70001FB8 AFB00018 */  sw    $s0, 0x18($sp)
/* 002BBC 70001FBC 00008825 */  move  $s1, $zero
/* 002BC0 70001FC0 00009025 */  move  $s2, $zero
/* 002BC4 70001FC4 AFA00064 */  sw    $zero, 0x64($sp)
/* 002BC8 70001FC8 AFA00060 */  sw    $zero, 0x60($sp)
/* 002BCC 70001FCC 24A5E7A0 */  addiu $a1, %lo(g_AudioClient) # addiu $a1, $a1, -0x1860
/* 002BD0 70001FD0 2484DA40 */  addiu $a0, %lo(sc) # addiu $a0, $a0, -0x25c0
/* 002BD4 70001FD4 02C03025 */  move  $a2, $s6
/* 002BD8 70001FD8 0C000305 */  jal   osScAddClient
/* 002BDC 70001FDC 24070001 */   li    $a3, 1
/* 002BE0 70001FE0 3C158006 */  lui   $s5, %hi(g_EndTime)
/* 002BE4 70001FE4 3C148006 */  lui   $s4, %hi(g_StartTime)
/* 002BE8 70001FE8 3C138006 */  lui   $s3, %hi(g_LargestDeltaTime)
/* 002BEC 70001FEC 3C108006 */  lui   $s0, %hi(g_DeltaTimeSum)
/* 002BF0 70001FF0 2610E4D0 */  addiu $s0, %lo(g_DeltaTimeSum) # addiu $s0, $s0, -0x1b30
/* 002BF4 70001FF4 2673E4B8 */  addiu $s3, %lo(g_LargestDeltaTime) # addiu $s3, $s3, -0x1b48
/* 002BF8 70001FF8 2694E4D8 */  addiu $s4, %lo(g_StartTime) # addiu $s4, $s4, -0x1b28
/* 002BFC 70001FFC 26B5E4E0 */  addiu $s5, %lo(g_EndTime) # addiu $s5, $s5, -0x1b20
/* 002C00 70002000 241E0001 */  li    $fp, 1
/* 002C04 70002004 27B70064 */  addiu $s7, $sp, 0x64
/* 002C08 70002008 02C02025 */  move  $a0, $s6
.L7000200C:
/* 002C0C 7000200C 02E02825 */  move  $a1, $s7
/* 002C10 70002010 0C003774 */  jal   osRecvMesg
/* 002C14 70002014 03C03025 */   move  $a2, $fp
/* 002C18 70002018 8FAE0064 */  lw    $t6, 0x64($sp)
/* 002C1C 7000201C 24010005 */  li    $at, 5
/* 002C20 70002020 85C40000 */  lh    $a0, ($t6)
/* 002C24 70002024 109E0007 */  beq   $a0, $fp, .L70002044
/* 002C28 70002028 00000000 */   nop   
/* 002C2C 7000202C 10810071 */  beq   $a0, $at, .L700021F4
/* 002C30 70002030 2401000A */   li    $at, 10
/* 002C34 70002034 50810072 */  beql  $a0, $at, .L70002200
/* 002C38 70002038 03C09025 */   move  $s2, $fp
/* 002C3C 7000203C 10000070 */  b     .L70002200
/* 002C40 70002040 00000000 */   nop   
.L70002044:
/* 002C44 70002044 0C003AEC */  jal   osGetTime
/* 002C48 70002048 00000000 */   nop   
/* 002C4C 7000204C AE820000 */  sw    $v0, ($s4)
/* 002C50 70002050 AE830004 */  sw    $v1, 4($s4)
/* 002C54 70002054 0C000A15 */  jal   speedGraphVideoRelated_3
/* 002C58 70002058 3C040003 */   lui   $a0, 3
/* 002C5C 7000205C 3C0F8002 */  lui   $t7, %hi(g_AudioFrameCount) 
/* 002C60 70002060 8DEF30F4 */  lw    $t7, %lo(g_AudioFrameCount)($t7)
/* 002C64 70002064 24010003 */  li    $at, 3
/* 002C68 70002068 3C048006 */  lui   $a0, %hi(g_AudioManager+8)
/* 002C6C 7000206C 01E1001B */  divu  $zero, $t7, $at
/* 002C70 70002070 0000C010 */  mfhi  $t8
/* 002C74 70002074 0018C880 */  sll   $t9, $t8, 2
/* 002C78 70002078 00992021 */  addu  $a0, $a0, $t9
/* 002C7C 7000207C 8C84E520 */  lw    $a0, %lo(g_AudioManager+8)($a0)
/* 002C80 70002080 0C000891 */  jal   amHandleFrameMessage
/* 002C84 70002084 8FA50060 */   lw    $a1, 0x60($sp)
/* 002C88 70002088 26310001 */  addiu $s1, $s1, 1
/* 002C8C 7000208C 0C000A15 */  jal   speedGraphVideoRelated_3
/* 002C90 70002090 3C040006 */   lui   $a0, 6
/* 002C94 70002094 0C003AEC */  jal   osGetTime
/* 002C98 70002098 00000000 */   nop   
/* 002C9C 7000209C 8E8A0000 */  lw    $t2, ($s4)
/* 002CA0 700020A0 8E8B0004 */  lw    $t3, 4($s4)
/* 002CA4 700020A4 AEA20000 */  sw    $v0, ($s5)
/* 002CA8 700020A8 004AC023 */  subu  $t8, $v0, $t2
/* 002CAC 700020AC 006B082B */  sltu  $at, $v1, $t3
/* 002CB0 700020B0 0301C023 */  subu  $t8, $t8, $at
/* 002CB4 700020B4 AEA30004 */  sw    $v1, 4($s5)
/* 002CB8 700020B8 3C018006 */  lui   $at, %hi(dword_CODE_bss_8005E4C0)
/* 002CBC 700020BC 006BC823 */  subu  $t9, $v1, $t3
/* 002CC0 700020C0 AC39E4C4 */  sw    $t9, %lo(dword_CODE_bss_8005E4C4)($at)
/* 002CC4 700020C4 AC38E4C0 */  sw    $t8, %lo(dword_CODE_bss_8005E4C0)($at)
/* 002CC8 700020C8 240100F0 */  li    $at, 240
/* 002CCC 700020CC 0221001A */  div   $zero, $s1, $at
/* 002CD0 700020D0 00004010 */  mfhi  $t0
/* 002CD4 700020D4 AFB90044 */  sw    $t9, 0x44($sp)
/* 002CD8 700020D8 AFB80040 */  sw    $t8, 0x40($sp)
/* 002CDC 700020DC AFA20050 */  sw    $v0, 0x50($sp)
/* 002CE0 700020E0 AFA30054 */  sw    $v1, 0x54($sp)
/* 002CE4 700020E4 AFAA0048 */  sw    $t2, 0x48($sp)
/* 002CE8 700020E8 1500001C */  bnez  $t0, .L7000215C
/* 002CEC 700020EC AFAB004C */   sw    $t3, 0x4c($sp)
/* 002CF0 700020F0 8E040000 */  lw    $a0, ($s0)
/* 002CF4 700020F4 8E050004 */  lw    $a1, 4($s0)
/* 002CF8 700020F8 24060000 */  li    $a2, 0
/* 002CFC 700020FC 0C003B2A */  jal   __ull_div
/* 002D00 70002100 240700F0 */   li    $a3, 240
/* 002D04 70002104 3C018006 */  lui   $at, %hi(dword_CODE_bss_8005E4CC)
/* 002D08 70002108 AC22E4C8 */  sw    $v0, %lo(dword_CODE_bss_8005E4C8)($at)
/* 002D0C 7000210C AC23E4CC */  sw    $v1, %lo(dword_CODE_bss_8005E4CC)($at)
/* 002D10 70002110 8E990004 */  lw    $t9, 4($s4)
/* 002D14 70002114 8E980000 */  lw    $t8, ($s4)
/* 002D18 70002118 8EAF0004 */  lw    $t7, 4($s5)
/* 002D1C 7000211C 8EAE0000 */  lw    $t6, ($s5)
/* 002D20 70002120 240A0000 */  li    $t2, 0
/* 002D24 70002124 01F9082B */  sltu  $at, $t7, $t9
/* 002D28 70002128 01D84023 */  subu  $t0, $t6, $t8
/* 002D2C 7000212C 01014023 */  subu  $t0, $t0, $at
/* 002D30 70002130 240B0000 */  li    $t3, 0
/* 002D34 70002134 240C0000 */  li    $t4, 0
/* 002D38 70002138 240D0000 */  li    $t5, 0
/* 002D3C 7000213C 01F94823 */  subu  $t1, $t7, $t9
/* 002D40 70002140 AFA90044 */  sw    $t1, 0x44($sp)
/* 002D44 70002144 AE6D0004 */  sw    $t5, 4($s3)
/* 002D48 70002148 AE6C0000 */  sw    $t4, ($s3)
/* 002D4C 7000214C AE0B0004 */  sw    $t3, 4($s0)
/* 002D50 70002150 AFA80040 */  sw    $t0, 0x40($sp)
/* 002D54 70002154 10000011 */  b     .L7000219C
/* 002D58 70002158 AE0A0000 */   sw    $t2, ($s0)
.L7000215C:
/* 002D5C 7000215C 8E0B0004 */  lw    $t3, 4($s0)
/* 002D60 70002160 8FAD0054 */  lw    $t5, 0x54($sp)
/* 002D64 70002164 8E0A0000 */  lw    $t2, ($s0)
/* 002D68 70002168 8FAC0050 */  lw    $t4, 0x50($sp)
/* 002D6C 7000216C 016D7821 */  addu  $t7, $t3, $t5
/* 002D70 70002170 8FB80048 */  lw    $t8, 0x48($sp)
/* 002D74 70002174 8FB9004C */  lw    $t9, 0x4c($sp)
/* 002D78 70002178 01ED082B */  sltu  $at, $t7, $t5
/* 002D7C 7000217C 002A7021 */  addu  $t6, $at, $t2
/* 002D80 70002180 01CC7021 */  addu  $t6, $t6, $t4
/* 002D84 70002184 01D84023 */  subu  $t0, $t6, $t8
/* 002D88 70002188 01F9082B */  sltu  $at, $t7, $t9
/* 002D8C 7000218C 01014023 */  subu  $t0, $t0, $at
/* 002D90 70002190 01F94823 */  subu  $t1, $t7, $t9
/* 002D94 70002194 AE090004 */  sw    $t1, 4($s0)
/* 002D98 70002198 AE080000 */  sw    $t0, ($s0)
.L7000219C:
/* 002D9C 7000219C 8E6A0000 */  lw    $t2, ($s3)
/* 002DA0 700021A0 8FAC0040 */  lw    $t4, 0x40($sp)
/* 002DA4 700021A4 8E6B0004 */  lw    $t3, 4($s3)
/* 002DA8 700021A8 8FAD0044 */  lw    $t5, 0x44($sp)
/* 002DAC 700021AC 018A082B */  sltu  $at, $t4, $t2
/* 002DB0 700021B0 14200008 */  bnez  $at, .L700021D4
/* 002DB4 700021B4 3C048006 */   lui   $a0, %hi(g_AudioManager+0x200)
/* 002DB8 700021B8 014C082B */  sltu  $at, $t2, $t4
/* 002DBC 700021BC 14200003 */  bnez  $at, .L700021CC
/* 002DC0 700021C0 016D082B */   sltu  $at, $t3, $t5
/* 002DC4 700021C4 10200003 */  beqz  $at, .L700021D4
/* 002DC8 700021C8 00000000 */   nop   
.L700021CC:
/* 002DCC 700021CC AE6C0000 */  sw    $t4, ($s3)
/* 002DD0 700021D0 AE6D0004 */  sw    $t5, 4($s3)
.L700021D4:
/* 002DD4 700021D4 2484E718 */  addiu $a0, %lo(g_AudioManager+0x200) # addiu $a0, $a0, -0x18e8
/* 002DD8 700021D8 27A50060 */  addiu $a1, $sp, 0x60
/* 002DDC 700021DC 0C003774 */  jal   osRecvMesg
/* 002DE0 700021E0 03C03025 */   move  $a2, $fp
/* 002DE4 700021E4 0C0008F9 */  jal   amHandleDoneMessage
/* 002DE8 700021E8 8FA40060 */   lw    $a0, 0x60($sp)
/* 002DEC 700021EC 10000004 */  b     .L70002200
/* 002DF0 700021F0 00000000 */   nop   
.L700021F4:
/* 002DF4 700021F4 10000002 */  b     .L70002200
/* 002DF8 700021F8 03C09025 */   move  $s2, $fp
/* 002DFC 700021FC 03C09025 */  move  $s2, $fp
.L70002200:
/* 002E00 70002200 5240FF82 */  beql  $s2, $zero, .L7000200C
/* 002E04 70002204 02C02025 */   move  $a0, $s6
/* 002E08 70002208 3C048006 */  lui   $a0, %hi(g_AudioManager+0x238)
/* 002E0C 7000220C 0C003AB9 */  jal   alClose
/* 002E10 70002210 2484E750 */   addiu $a0, %lo(g_AudioManager+0x238) # addiu $a0, $a0, -0x18b0
/* 002E14 70002214 8FBF003C */  lw    $ra, 0x3c($sp)
/* 002E18 70002218 8FB00018 */  lw    $s0, 0x18($sp)
/* 002E1C 7000221C 8FB1001C */  lw    $s1, 0x1c($sp)
/* 002E20 70002220 8FB20020 */  lw    $s2, 0x20($sp)
/* 002E24 70002224 8FB30024 */  lw    $s3, 0x24($sp)
/* 002E28 70002228 8FB40028 */  lw    $s4, 0x28($sp)
/* 002E2C 7000222C 8FB5002C */  lw    $s5, 0x2c($sp)
/* 002E30 70002230 8FB60030 */  lw    $s6, 0x30($sp)
/* 002E34 70002234 8FB70034 */  lw    $s7, 0x34($sp)
/* 002E38 70002238 8FBE0038 */  lw    $fp, 0x38($sp)
/* 002E3C 7000223C 03E00008 */  jr    $ra
/* 002E40 70002240 27BD0070 */   addiu $sp, $sp, 0x70
)
#endif

/**
 * 2E44	70002244
 * Based on method
 *     static u32 __amHandleFrameMsg(AudioInfo *info, AudioInfo *lastInfo)
 * from the n64devkit demos_old/simple/audiomgr.c.
 *
 * original documentation:
 * First, clear the past audio dma's, then calculate 
 * the number of samples you will need for this frame. This value varies
 * due to the fact that audio is synchronised off of the video interupt 
 * which can have a small amount of jitter in it. Varying the number of 
 * samples slightly will allow you to stay in synch with the video. This
 * is an advantageous thing to do, since if you are in synch with the 
 * video, you will have fewer graphics yields. After you've calculated 
 * the number of frames needed, call alAudioFrame, which will call all
 * of the synthesizer's players (sequence player and sound player) to
 * generate the audio task list. If you get a valid task list back, put
 * it in a task structure and send a message to the scheduler to let it
 * know that the next frame of audio is ready for processing.
 * 
 * @param info audio info.
 * @param lastInfo last info.
 */
void amHandleFrameMessage(AudioInfo *info, AudioInfo *lastInfo)
{
    s16* outBuffer;
    Acmd *cmdlp;
    s32 temp_v1;

    /* call once a frame, before doing alAudioFrame */
    amClearDmaBuffers();
    
    outBuffer = (s16*)osVirtualToPhysical(info->data);
    
    if (lastInfo)
    {
        osAiSetNextBuffer(lastInfo->data, lastInfo->frameSamples * 4);
    }
    
    /* calculate how many samples needed for this frame to keep the DAC full */
    /* this will vary slightly frame to frame, must recalculate every frame */
    /* divide by four, to convert bytes */
    /* to stereo 16 bit samples */
    info->frameSamples = (u16)(((g_FrameSize - (osAiGetLength() >> 2)) + 16 + EXTRA_SAMPLES) & ~0xf);  
    temp_v1 = g_MinFrameSize;
    
    if ((s32)info->frameSamples < (s32)(s16)temp_v1)
    {
        info->frameSamples = (s16)temp_v1;
    }
    
    cmdlp = (Acmd*)alAudioFrame(g_AudioManager.cmdList[g_CurrentAcmdList], &g_CommandLength, outBuffer, info->frameSamples);
    
    /* paranoia */
    info->task.next = 0;
    info->task.flags = 0;

    /* reply to when finished */
    info->task.msgQ = (void *) (&(g_AudioManager.replyMessageQueue.mtqueue));

    /* reply with this message */
    info->task.msg = info;
    info->task.flags = OS_SC_NEEDS_RSP;
    info->task.list.t.data_ptr = (u64*)(g_AudioManager.cmdList[g_CurrentAcmdList]);
    info->task.list.t.data_size = (((s32)cmdlp - (s32)g_AudioManager.cmdList[g_CurrentAcmdList]) >> 3) * sizeof(Acmd);
    info->task.list.t.type = M_AUDTASK;
    info->task.list.t.ucode_boot = (u64*)rspbootTextStart;
    info->task.list.t.ucode_boot_size = ((s32)gsp3DTextStart - (s32)rspbootTextStart);
    info->task.list.t.flags = 0; // 1c
    info->task.list.t.ucode = (u64*)aspMainTextStart;
    info->task.list.t.ucode_data = (u64*)aspMainDataStart;
    info->task.list.t.ucode_data_size = SP_UCODE_DATA_SIZE;
    info->task.list.t.yield_data_ptr = NULL; // 50
    info->task.list.t.yield_data_size = 0; // 54
    
    osSendMesg(osScGetCmdQ(&sc), (OSMesg)&info->task, OS_MESG_NOBLOCK);

    /* swap which acmd list you use each frame */
    g_CurrentAcmdList ^= 1;
}


/**
 * 2FE4	700023E4
 * Based on method
 *     static void __amHandleDoneMsg(AudioInfo *info)
 * from the n64devkit demos_old/simple/audiomgr.c.
 *
 * original documentation:
 * Really just debugging info in this frame. Checks
 * to make sure we completed before we were out of samples.
 * 
 * @param info Unused.
 */
void amHandleDoneMessage(AudioInfo *info)
{
    s32 samplesLeft;
    /*
    * in the audiomgr example, firstTime is declared here with
    * the static keyword. That breaks the build, but the following
    * code will compile to a matching binary,
    */
    int *b;
    
    samplesLeft = (s32)osAiGetLength() >> 2;

    /*
    * The initial code probably looked like the following (and this
    * is what you get with mips_to_c):
    * 
    *     if (samplesLeft == 0 && !firstTime) 
    */   
    b = &g_FirstTime;
    if (!samplesLeft && !(*b))
    {
        // debug printf from audioMgr demo
#ifdef DEBUG
      osSyncPrintf("audio: ai out of samples\n");    
#endif
        g_FirstTime = 0;
    }
}

/**
 * 3024 70002424
 * Looks to be based on method
 *     s32 __amDMA(s32 addr, s32 len, void *state)
 * from the n64devkit.
 * 
 *  original documentation:
 * This routine handles the dma'ing of samples from rom to ram.
 * First it checks the current buffers to see if the samples needed are
 * already in place. Because buffers are linked sequentially by the
 * addresses where the samples are on rom, it doesn't need to check all
 * of them, only up to the address that it needs. If it finds one, it
 * returns the address of that buffer. If it doesn't find the samples 
 * that it needs, it will initiate a DMA of the samples that it needs.
 * In either case, it updates the lastFrame variable, to indicate that
 * this buffer was last used in this frame. This is important for the
 * __clearAudioDMA routine.
 * 
 * @param addr ?.
 * @param len ?.
 * @param state unused.
 * @return result from call to osVirtualToPhysical
 */
s32 amDmaCallback(s32 addr, s32 len, void* state)
{
    void *freeBuffer;
    s32 delta;
    DMABuffer *dmaPtr;
    s32 addrEnd;
    s32 buffEnd;
    DMABuffer *lastDmaPtr;

    lastDmaPtr = NULL;
    dmaPtr = g_DmaState.firstUsed;
    delta = addr & 0x1;
    addrEnd = addr + len;

    /* first check to see if a currently existing buffer contains the
       sample that you need.  */
    while (dmaPtr)
    {
        buffEnd = dmaPtr->startAddr + AUDIO_DMA_MAX_BUFFER_LENGTH;

        /* since buffers are ordered */
        /* abort if past possible */
        if ((u32)dmaPtr->startAddr > (u32)addr)
        {
            break;
        }
        /* yes, found a buffer with samples */
        else if (addrEnd <= buffEnd)
        {
            /* mark it used */
            dmaPtr->lastFrame = (s32) g_AudioFrameCount;
            freeBuffer = (dmaPtr->ptr + addr) - dmaPtr->startAddr;
            return osVirtualToPhysical(freeBuffer);
        }
    
        lastDmaPtr = dmaPtr;
        dmaPtr = (DMABuffer*)dmaPtr->node.next;
    }

    /* get here, and you didn't find a buffer, so dma a new one */
    /* get a buffer from the free list */
    dmaPtr = g_DmaState.firstFree;

    /* 
     * if you get here and dmaPtr is null, send back a bogus
     * pointer, it's better than nothing
     */
    if (!dmaPtr)
    {
        if (!lastDmaPtr)
        {
            lastDmaPtr = g_DmaState.firstUsed;
        }

        return osVirtualToPhysical(lastDmaPtr->ptr) + delta;
    }

    g_DmaState.firstFree = (DMABuffer*)dmaPtr->node.next;
    alUnlink((ALLink*)dmaPtr);

    /* add it to the used list */
    /* if you have other dmabuffers used, add this one */
    /* to the list, after the last one checked above */
    if (lastDmaPtr)
    {
        alLink((ALLink*)dmaPtr, (ALLink*)lastDmaPtr);
    }
    /* if this buffer is before any others */
    // Jam at begining of list
    else if (g_DmaState.firstUsed)
    {
        lastDmaPtr = g_DmaState.firstUsed;
        g_DmaState.firstUsed = dmaPtr;
        dmaPtr->node.next = (ALLink*)lastDmaPtr;
        dmaPtr->node.prev = 0;
        lastDmaPtr->node.prev = (ALLink*)dmaPtr;
    }
    /* no buffers in list, this is the first one */
    else
    {
        g_DmaState.firstUsed = dmaPtr;
        dmaPtr->node.next = 0;
        dmaPtr->node.prev = 0;
    }

    freeBuffer = dmaPtr->ptr;
    addr -= delta;
    dmaPtr->startAddr = addr;
    dmaPtr->lastFrame = g_AudioFrameCount;

    osPiStartDma(&g_DmaIOMessageBuffer[g_NextDMa++], OS_MESG_PRI_HIGH, OS_READ, (u32)addr, freeBuffer, AUDIO_DMA_MAX_BUFFER_LENGTH, &g_DmaMessageQueue);
    return (s32)osVirtualToPhysical(freeBuffer) + delta;
}

/**
 * 31D8 700025D8
 * Based on method
 *     ALDMAproc __amDmaNew(AMDMAState **state)
 * from the n64devkit demos_old/simple/audiomgr.c.
 *
 * original documentation:
 * Initialize the dma buffers and return the address of the
 * procedure that will be used to dma the samples from rom to ram. This 
 * routine will be called once for each physical voice that is created. 
 * In this case, because we know where all the buffers are, and since 
 * they are not attached to a specific voice, we will only really do any
 * initialization the first time. After that we just return the address
 * to the dma routine.
 * 
 * @param state will point to g_DmaState after call.
 * @return Address of dma callback function.
 */
ALDMAproc amDmaNew(DMAState** state)
{
    if (g_DmaState.u.initialized == 0)
    {
        g_DmaState.firstUsed = NULL;
        g_DmaState.firstFree = g_DmaBuffers;
        g_DmaState.u.initialized = (u8)1U;
    }

    *state = &g_DmaState;
    return &amDmaCallback;
}

/**
 * 3210 70002610
 * Based on method
 *     static void __clearAudioDMA(void)
 * from the n64devkit demos_old/simple/audiomgr.c.
 *
 * original documentation:
 * Routine to move dma buffers back to the unused list.
 * First clear out your dma messageQ. Then check each buffer to see when
 * it was last used. If that was more than FRAME_LAG frames ago, move it
 * back to the unused list. 
 */
void amClearDmaBuffers(void)
{
    u32 i;
    OSMesg osmesg;
    DMABuffer *dmaPtr, *nextPtr;
    
    osmesg = 0;

   /*
    * Don't block here. If dma's aren't complete, you've had an audio
    * overrun. (Bad news, but go for it anyway, and try and recover.
    */
   for (i=0; i < g_NextDMa; i++)
   {
       if (osRecvMesg(&g_DmaMessageQueue, (OSMesg *)&osmesg, OS_MESG_NOBLOCK) == -1)
       {
#ifdef DEBUG
	        osSyncPrintf("Dma not done\n");
#endif
       }

#ifdef DEBUG
    /* debug logging from audioMgr.c, I think this requires #include <ultralog.h>
    * //    if (logging)
    * //        osLogEvent(log, 17, 2, osmesg->devAddr, osmesg->size);
    */
#endif
   }

    dmaPtr = g_DmaState.firstUsed;
    while (dmaPtr)
    {
        nextPtr = (DMABuffer*)dmaPtr->node.next;

        /* remove old dma's from list */
        /* Can change FRAME_LAG value.  Should be at least one.  */
        /* Larger values mean more buffers needed, but fewer DMA's */
        if (dmaPtr->lastFrame + 1 < g_AudioFrameCount)
        {
            if (g_DmaState.firstUsed == dmaPtr)
            {
                g_DmaState.firstUsed = (DMABuffer*)dmaPtr->node.next;
            }

            alUnlink((ALLink*)dmaPtr);

            if (g_DmaState.firstFree)
            {
                alLink((ALLink*)dmaPtr, (ALLink*)g_DmaState.firstFree);
            }
            else
            {
                g_DmaState.firstFree = dmaPtr;
                dmaPtr->node.next = 0;
                dmaPtr->node.prev = 0;
            }
        }
        dmaPtr = nextPtr;
    }

    g_NextDMa = 0U;
    g_AudioFrameCount = (s32)(g_AudioFrameCount + 1);
}

