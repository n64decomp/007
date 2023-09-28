#include <ultra64.h>
#include "joy.h"
#include <PR/os.h>

#define JOY_CLAMP_MIN          0
#define JOY_CLAMP_MAX        120
#define JOY_CLAMP_MAX_F   120.0f
#define JOY_CLAMP_OFFSET      60



struct contdata {
    /* 0x000 */ struct contsample samples[CONTSAMPLE_LEN];
    /* 0x1E0 */ s32 curlast;
    /* 0x1E4 */ s32 curstart;
    /* 0x1E8 */ s32 nextlast;
    /* 0x1EC */ s32 nextsecondlast;
    /* 0x1F0 */ u16 buttonspressed[MAXCONTROLLERS];
    /* 0x1F8 */ s32 playbackcontcount;
};

/**
 * Regular controller data for struct contdata.
 */
#define CONTDATA_REGULAR  0

/**
 * Playback controller data for struct contdata.
 */
#define CONTDATA_PLAYBACK 1

/**
 * Length of struct contdata[].
 */
#define CONTDATA_LEN      2

/**
 * Contains controller data for "regular" and playback.
 */
struct contdata g_ContData[CONTDATA_LEN];

#define CONT_INPUT_BUFFER_LEN                10
#define CONT_DISABLE_POLL_SEND_BUFFER_LEN     1
#define CONT_DISABLE_POLL_RECEIVE_BUFFER_LEN  1
#define CONT_ENABLE_POLL_SEND_BUFFER_LEN      1
#define CONT_ENABLE_POLL_RECEIVE_BUFFER_LEN   1

OSMesg      g_ContInputMessageBuffer[CONT_INPUT_BUFFER_LEN];
OSMesgQueue g_ContInputMessageQueue;

OSMesg      g_ContDisablePollSendMessageBuffer[CONT_DISABLE_POLL_SEND_BUFFER_LEN];
OSMesgQueue g_ContDisablePollSendMessageQueue;

OSMesg      g_ContDisablePollReceiveMessageBuffer[CONT_DISABLE_POLL_RECEIVE_BUFFER_LEN];
OSMesgQueue g_ContDisablePollReceiveMessageQueue;

OSMesg      g_ContEnablePollSendMessageBuffer[CONT_ENABLE_POLL_SEND_BUFFER_LEN];
OSMesgQueue g_ContEnablePollSendMessageQueue;

OSMesg      g_ContEnablePollReceiveMessageBuffer[CONT_ENABLE_POLL_RECEIVE_BUFFER_LEN];
OSMesgQueue g_ContEnablePollReceiveMessageQueue;

OSContStatus g_ContStatus[MAXCONTROLLERS];
OSPfs g_ContPfs[MAXCONTROLLERS];
s32 g_ContDebugData = 0;

struct contdata *g_ContDataPtr = &g_ContData[CONTDATA_REGULAR];
s32 g_ContBusy = 0;
s32 g_ContPollDisableCount = 0;
u8 g_ConnectedControllers = 0;

/**
 * Uses 1 bit per controller.
 */
u8 g_ControllerStates = 0;

typedef enum {
    RUMBLEPAKINITSTATE_ERROR = -1,
    RUMBLEPAKINITSTATE_NOT_READY,
    RUMBLEPAKINITSTATE_READY
} RUMBLEPAKINITSTATE;

typedef enum {
    RUMBLEPAKSTATE_OFF,
    RUMBLEPAKSTATE_ON,
    RUMBLEPAKSTATE_UNKNOWN
} RUMBLEPAKSTATE;

// forward declarations
void joyCheckStatus(void);

//

s32 g_ContRumblePakInitState[MAXCONTROLLERS] = {0};

#define set_rumble_pak_init_state_not_ready(i) do { g_ContRumblePakInitState[i] = RUMBLEPAKINITSTATE_NOT_READY; } while (0)

s32 g_ContRumblePakCurrentState[MAXCONTROLLERS] = {0};
s32 g_ContRumblePakTimer60[MAXCONTROLLERS] = {0};
s32 g_ContRumblePakTargetState[MAXCONTROLLERS] = {0};


s32 g_ContQueuesCreated = 0;
s32 g_ContInitDone = 0;
s32 g_ContCheckStatusTimer60 = 0;

contplaybackfunc g_ContPlaybackFunc = NULL;
contrecordfunc g_ContRecordFunc = NULL;

/**
 * Startup flag, cleared after first call to joyCheckStatus.
 */
s32 g_ContNeedsInit = 1;

u32 g_ContBadReadsStickX[MAXCONTROLLERS] = {0};
u32 g_ContBadReadsStickY[MAXCONTROLLERS] = {0};
u32 g_ContBadReadsButtons[MAXCONTROLLERS] = {0};
u32 g_ContBadReadsButtonsPressed[MAXCONTROLLERS] = {0};

s32 g_ContBadReadTimer60 = 0; // Static variable?

void joyInit(void)
{
    s32 i;
    s32 j;

    debTryAdd(&g_ContDebugData, "joy_c_debug");

    osCreateMesgQueue(&g_ContDisablePollSendMessageQueue, g_ContDisablePollSendMessageBuffer, CONT_DISABLE_POLL_SEND_BUFFER_LEN);
    osCreateMesgQueue(&g_ContDisablePollReceiveMessageQueue, g_ContDisablePollReceiveMessageBuffer, CONT_DISABLE_POLL_RECEIVE_BUFFER_LEN);
    osCreateMesgQueue(&g_ContEnablePollSendMessageQueue, g_ContEnablePollSendMessageBuffer, CONT_ENABLE_POLL_SEND_BUFFER_LEN);
    osCreateMesgQueue(&g_ContEnablePollReceiveMessageQueue, g_ContEnablePollReceiveMessageBuffer, CONT_ENABLE_POLL_RECEIVE_BUFFER_LEN);
    osCreateMesgQueue(&g_ContInputMessageQueue, g_ContInputMessageBuffer, CONT_INPUT_BUFFER_LEN);

    osSetEventMesg(OS_EVENT_SI, &g_ContInputMessageQueue, NULL);

    g_ContQueuesCreated = TRUE;
    g_ContPlaybackFunc = NULL;
    g_ContRecordFunc = NULL;

    for (i = 0; i < CONTDATA_LEN; i++)
    {
        g_ContData[i].curlast = 0;
        g_ContData[i].curstart = 0;
        g_ContData[i].nextlast = 0;
        g_ContData[i].nextsecondlast = 0;
        g_ContData[i].playbackcontcount = -1;

        for (j = 0; j < MAXCONTROLLERS; j++)
        {
            g_ContData[i].samples[0].pads[j].button = 0;
            g_ContData[i].samples[0].pads[j].stick_x = 0;
            g_ContData[i].samples[0].pads[j].stick_y = 0;
            g_ContData[i].samples[0].pads[j].errno = 0;
        }
    }
}

void joyCheckStatusThreadSafe(void)
{
    OSMesg  msg;

    if (g_ContQueuesCreated)
    {
        osSendMesg(&g_ContDisablePollSendMessageQueue, &msg, OS_MESG_NOBLOCK);
        osRecvMesg(&g_ContDisablePollReceiveMessageQueue, &msg, OS_MESG_BLOCK);

        joyCheckStatus();

        osSendMesg(&g_ContEnablePollSendMessageQueue, &msg, OS_MESG_NOBLOCK);
        osRecvMesg(&g_ContEnablePollReceiveMessageQueue, &msg, OS_MESG_BLOCK);
    }
}

s32 osPfsChecker(OSPfs *pfs)
{
    return PFS_ERR_INCONSISTENT;
}

void joyRumblePakInit(s32 index)
{
    s32 ret;

    if (g_ContRumblePakInitState[index] > RUMBLEPAKINITSTATE_ERROR)
    {
        if ((g_ContStatus[index].type & CONT_JOYPORT) && (g_ContStatus[index].status & CONT_CARD_ON))
        {
            ret = osPfsInit(&g_ContInputMessageQueue, &g_ContPfs[index], index);

            if ((ret == PFS_ERR_ID_FATAL) || (ret == PFS_ERR_DEVICE))
            {
                if (osMotorInit(&g_ContInputMessageQueue, &g_ContPfs[index], index) == 0)
                {
                    g_ContRumblePakInitState[index] = RUMBLEPAKINITSTATE_READY;
                }
                else
                {
                    g_ContRumblePakInitState[index] = RUMBLEPAKINITSTATE_ERROR;
                }
            }
        }
    }
}

void joyCheckStatus(void)
{
    s8 i;

    if (g_ContNeedsInit)
    {
        g_ContNeedsInit = FALSE;
        osContInit(&g_ContInputMessageQueue, &g_ConnectedControllers, g_ContStatus);
        g_ContInitDone = TRUE;
    }
    else
    {
        u32 slots = 0xF;
        s32 i;

        // The following three function calls (+for) show up in the same sequence
        // in devkit demos, but there doesn't seem to be much else in common
        // with Rare's implementation.
        // n64devkit\ultra\usr\src\pr\demos\gbpak\siproc.c line 244
        // n64devkit\ultra\usr\src\pr\demos\voice\siproc.c line 89
        osContStartQuery(&g_ContInputMessageQueue);
        osRecvMesg(&g_ContInputMessageQueue, NULL, OS_MESG_BLOCK);
        osContGetQuery(g_ContStatus);
        // end similarity to gbpak\siproc.c

        for (i = 0; i < MAXCONTROLLERS; i++)
        {
            if (g_ContStatus[i].errno & CONT_NO_RESPONSE_ERROR)
            {
                slots -= 1 << i;
            }
        }
        // end similarity to voice\siproc.c

        g_ConnectedControllers = slots;
    }

    if (0)
    {
        // Removed
    }

    for (i = 0; i < MAXCONTROLLERS; i++)
    {
        // Removed
    }

    for (i = 0; i < MAXCONTROLLERS; i++)
    {
        if ((g_ConnectedControllers & (1 << i))
            && (g_ContStatus[i].type & (CONT_ABSOLUTE | CONT_RELATIVE))
            && !(g_ContStatus[i].errno))
        {
            // This seems like a typo in the original, doing a bitwise AND
            // between a logical test on the left and a bitshift on the right.
            if ((!(g_ControllerStates) & (1 << i)) || (g_ContRumblePakInitState[i] < RUMBLEPAKINITSTATE_READY))
            {
                joyRumblePakInit(i);
            }

            g_ControllerStates |= (1 << i);
        }
        else if (g_ControllerStates & (1 << i))
        {
            g_ControllerStates ^= (1 << i);
            g_ContRumblePakInitState[i] = RUMBLEPAKINITSTATE_NOT_READY;
        }
    }
}

s8 joyGetControllerCount(void)
{
    s32 i;

    if (g_ContDataPtr->playbackcontcount >= 0)
    {
        return g_ContDataPtr->playbackcontcount;
    }

    for (i = 0; i < MAXCONTROLLERS; i++)
    {
        if ((g_ConnectedControllers & (1 << i)) == 0)
        {
            return i;
        }
    }

    return MAXCONTROLLERS;
}

u8 joyGetConnectedControllers(void)
{
    return g_ConnectedControllers;
}

void joyRumblePakTick(void)
{
    s32 i;

    for (i = 0; i < MAXCONTROLLERS; i++)
    {
        if (g_ContRumblePakCurrentState[i] != g_ContRumblePakTargetState[i])
        {
            if (g_ContRumblePakTargetState[i] == RUMBLEPAKSTATE_ON)
            {
                if (0 == osMotorStart(&g_ContPfs[i]))
                {
                    g_ContRumblePakCurrentState[i] = RUMBLEPAKSTATE_ON;
                }
                else
                {
                    set_rumble_pak_init_state_not_ready(i);
                }
#ifdef BUGFIX_R1
            }
            else if (g_ContRumblePakTargetState[i] == RUMBLEPAKSTATE_UNKNOWN)
            {
                if (osMotorInit(&g_ContInputMessageQueue, &g_ContPfs[i], i) != 0)
                {
                    set_rumble_pak_init_state_not_ready(i);
                }

                osMotorStop(&g_ContPfs[i]);
                g_ContRumblePakCurrentState[i] = RUMBLEPAKSTATE_OFF;
                g_ContRumblePakTargetState[i] = RUMBLEPAKSTATE_OFF;
#endif
            }
            else
            {
                if (0 == osMotorStop(&g_ContPfs[i]))
                {
                    g_ContRumblePakCurrentState[i] = RUMBLEPAKSTATE_OFF;
                }
                else
                {
                    set_rumble_pak_init_state_not_ready(i);
                }
            }
        }

        if (g_ContRumblePakTimer60[i] <= 0)
        {
            g_ContRumblePakTimer60[i] = 0;
        }
        else
        {
            g_ContRumblePakTimer60[i]--;

            if (g_ContRumblePakTimer60[i] <= 0)
            {
                g_ContRumblePakTimer60[i] = 0;
                g_ContRumblePakTargetState[i] = 0;
            }
        }
    }
}

void joySetPlaybackFunc(contplaybackfunc func, s32 controllercount)
{
    g_ContPlaybackFunc = func;
    g_ContData[CONTDATA_PLAYBACK].playbackcontcount = controllercount;
}

void joySetRecordFunc(contrecordfunc func)
{
    g_ContRecordFunc = func;
}

void joyConsumeSamples(struct contdata *contdata)
{
    s8 i;
    s32 samplenum;
    u16 buttons1;
    u16 buttons2;

    contdata->curstart = contdata->curlast;
    contdata->curlast = contdata->nextlast;

    for (i = 0; i < MAXCONTROLLERS; i++)
    {
        contdata->buttonspressed[i] = 0;

        if (contdata->curlast != contdata->curstart)
        {
            // Do not remove the following trailing backslash. The "while(true)"
            // needs to be on the same line as previous, otherwise the build breaks.
            // Search for WHILE_ONE_LINE to see other places in code like this.
            samplenum = ((contdata->curstart + 1) % CONTSAMPLE_LEN); \
            while (TRUE)
            {
                buttons1 = contdata->samples[samplenum].pads[i].button;
                buttons2 = contdata->samples[(samplenum + (CONTSAMPLE_LEN-1)) % CONTSAMPLE_LEN].pads[i].button;
                contdata->buttonspressed[i] |= buttons1 & ~buttons2;

                if (samplenum == contdata->curlast)
                {
                    break;
                }

                samplenum = ((samplenum + 1) % CONTSAMPLE_LEN);
            }
        }
    }
}

void joyConsumeSamplesWrapper(void)
{
    if (g_ContPlaybackFunc)
    {
        g_ContData[CONTDATA_PLAYBACK].nextlast = g_ContPlaybackFunc(g_ContData[CONTDATA_PLAYBACK].samples, g_ContData[CONTDATA_PLAYBACK].curlast);
        joyConsumeSamples(&g_ContData[CONTDATA_PLAYBACK]);
    }

    joyConsumeSamples(&g_ContData[CONTDATA_REGULAR]);

    if (g_ContRecordFunc)
    {
        g_ContRecordFunc(g_ContData[CONTDATA_REGULAR].samples, g_ContData[CONTDATA_REGULAR].curstart, g_ContData[CONTDATA_REGULAR].curlast);
    }
}

#ifdef NONMATCHING
// Stack + Regalloc
// https://decomp.me/scratch/IOID3 97.27%
void joyPoll(void)
{
    OSMesg msg;

    s32 padding[6];

    static s32 count = 0;
    s32 index;
    s8 i_s8;
    s32 i;
    
    // Check if there are any disable requests
    if (osRecvMesg(&g_ContDisablePollSendMessageQueue, &msg, OS_MESG_NOBLOCK) == 0)
    {
        if (g_ContBusy)
        {
            osRecvMesg(&g_ContInputMessageQueue, &msg, OS_MESG_BLOCK);
            g_ContBusy = FALSE;
        }

        osSendMesg(&g_ContDisablePollReceiveMessageQueue, &msg, OS_MESG_NOBLOCK);
        g_ContPollDisableCount++;

        return;
    }

    // Check if there are any enable requests
    if (osRecvMesg(&g_ContEnablePollSendMessageQueue, &msg, OS_MESG_NOBLOCK) == 0)
    {
        osContStartReadData(&g_ContInputMessageQueue);
        g_ContBusy = TRUE;
        osSendMesg(&g_ContEnablePollReceiveMessageQueue, &msg, OS_MESG_NOBLOCK);
   
        g_ContPollDisableCount--;

        return;
    }

    if ((g_ContPollDisableCount == 0) && g_ContInitDone)
    {
        // Poll controller input from SI
        if (osRecvMesg(&g_ContInputMessageQueue, &msg, OS_MESG_NOBLOCK) == 0)
        {
            g_ContBusy = FALSE;
            index = ((g_ContData[CONTDATA_REGULAR].nextlast + 1) % CONTSAMPLE_LEN);

            if (index == g_ContData[CONTDATA_REGULAR].curstart)
            {
                index = g_ContData[CONTDATA_REGULAR].nextlast;
            }


            osContGetReadData(g_ContData[CONTDATA_REGULAR].samples[index].pads);
            g_ContData[CONTDATA_REGULAR].nextlast = index;
            g_ContData[CONTDATA_REGULAR].nextsecondlast = ((g_ContData[CONTDATA_REGULAR].nextlast + (CONTSAMPLE_LEN - 1)) % CONTSAMPLE_LEN);
            g_ContCheckStatusTimer60++;

            if ((g_ContCheckStatusTimer60 % 120) == 0)
            {
                joyCheckStatus();
            }

            for (i_s8 = 0; i_s8 < MAXCONTROLLERS; i_s8++)
            {                
                if (((g_ContData[CONTDATA_REGULAR].samples[g_ContData[CONTDATA_REGULAR].nextlast].pads[i_s8].errno == 0) && (g_ContData[CONTDATA_REGULAR].samples[g_ContData[CONTDATA_REGULAR].nextsecondlast].pads[i_s8].errno != 0)) ||
                    ((g_ContData[CONTDATA_REGULAR].samples[g_ContData[CONTDATA_REGULAR].nextlast].pads[i_s8].errno != 0) && (g_ContData[CONTDATA_REGULAR].samples[g_ContData[CONTDATA_REGULAR].nextsecondlast].pads[i_s8].errno == 0)))
                {
                    joyCheckStatus();
                    
                    break;
                }
            }

            joyRumblePakTick();
            osContStartReadData(&g_ContInputMessageQueue);
            g_ContBusy = TRUE;
            count++;

            if (count >= 60)
            {
                for (i = 0; i < MAXCONTROLLERS; i++)
                {
                    if (g_ContBadReadsStickX[i] || g_ContBadReadsStickY[i] || g_ContBadReadsButtons[i] || g_ContBadReadsButtonsPressed[i])
                    {
                        g_ContBadReadsStickX[i] = 0;
                        g_ContBadReadsStickY[i] = 0;
                        g_ContBadReadsButtons[i] = 0;
                        g_ContBadReadsButtonsPressed[i] = 0;
                    }
                }
                
                count = 0;
            }
        }
    }
}
#else
void joyPoll(void);
GLOBAL_ASM(
.text
glabel joyPoll
/* 00C988 7000BD88 27BDFFB0 */  addiu $sp, $sp, -0x50
/* 00C98C 7000BD8C AFBF0014 */  sw    $ra, 0x14($sp)
/* 00C990 7000BD90 3C048006 */  lui   $a0, %hi(g_ContDisablePollSendMessageQueue)
/* 00C994 7000BD94 24845370 */  addiu $a0, %lo(g_ContDisablePollSendMessageQueue) # addiu $a0, $a0, 0x5370
/* 00C998 7000BD98 27A5004C */  addiu $a1, $sp, 0x4c
/* 00C99C 7000BD9C 0C003774 */  jal   osRecvMesg
/* 00C9A0 7000BDA0 00003025 */   move  $a2, $zero
/* 00C9A4 7000BDA4 14400015 */  bnez  $v0, .L7000BDFC
/* 00C9A8 7000BDA8 3C0E8002 */   lui   $t6, %hi(g_ContBusy)
/* 00C9AC 7000BDAC 8DCE68C8 */  lw    $t6, %lo(g_ContBusy)($t6)
/* 00C9B0 7000BDB0 3C048006 */  lui   $a0, %hi(g_ContInputMessageQueue)
/* 00C9B4 7000BDB4 24845350 */  addiu $a0, %lo(g_ContInputMessageQueue) # addiu $a0, $a0, 0x5350
/* 00C9B8 7000BDB8 11C00005 */  beqz  $t6, .L7000BDD0
/* 00C9BC 7000BDBC 27A5004C */   addiu $a1, $sp, 0x4c
/* 00C9C0 7000BDC0 0C003774 */  jal   osRecvMesg
/* 00C9C4 7000BDC4 24060001 */   li    $a2, 1
/* 00C9C8 7000BDC8 3C018002 */  lui   $at, %hi(g_ContBusy)
/* 00C9CC 7000BDCC AC2068C8 */  sw    $zero, %lo(g_ContBusy)($at)
.L7000BDD0:
/* 00C9D0 7000BDD0 3C048006 */  lui   $a0, %hi(g_ContDisablePollReceiveMessageQueue)
/* 00C9D4 7000BDD4 24845390 */  addiu $a0, %lo(g_ContDisablePollReceiveMessageQueue) # addiu $a0, $a0, 0x5390
/* 00C9D8 7000BDD8 27A5004C */  addiu $a1, $sp, 0x4c
/* 00C9DC 7000BDDC 0C0037C4 */  jal   osSendMesg
/* 00C9E0 7000BDE0 00003025 */   move  $a2, $zero
/* 00C9E4 7000BDE4 3C038002 */  lui   $v1, %hi(g_ContPollDisableCount)
/* 00C9E8 7000BDE8 246368CC */  addiu $v1, %lo(g_ContPollDisableCount) # addiu $v1, $v1, 0x68cc
/* 00C9EC 7000BDEC 8C6F0000 */  lw    $t7, ($v1)
/* 00C9F0 7000BDF0 25F80001 */  addiu $t8, $t7, 1
/* 00C9F4 7000BDF4 100000B9 */  b     .L7000C0DC
/* 00C9F8 7000BDF8 AC780000 */   sw    $t8, ($v1)
.L7000BDFC:
/* 00C9FC 7000BDFC 3C048006 */  lui   $a0, %hi(g_ContEnablePollSendMessageQueue)
/* 00CA00 7000BE00 248453B0 */  addiu $a0, %lo(g_ContEnablePollSendMessageQueue) # addiu $a0, $a0, 0x53b0
/* 00CA04 7000BE04 27A5004C */  addiu $a1, $sp, 0x4c
/* 00CA08 7000BE08 0C003774 */  jal   osRecvMesg
/* 00CA0C 7000BE0C 00003025 */   move  $a2, $zero
/* 00CA10 7000BE10 14400011 */  bnez  $v0, .L7000BE58
/* 00CA14 7000BE14 3C048006 */   lui   $a0, %hi(g_ContInputMessageQueue)
/* 00CA18 7000BE18 0C00535C */  jal   osContStartReadData
/* 00CA1C 7000BE1C 24845350 */   addiu $a0, %lo(g_ContInputMessageQueue) # addiu $a0, $a0, 0x5350
/* 00CA20 7000BE20 24190001 */  li    $t9, 1
/* 00CA24 7000BE24 3C018002 */  lui   $at, %hi(g_ContBusy)
/* 00CA28 7000BE28 3C048006 */  lui   $a0, %hi(g_ContEnablePollReceiveMessageQueue)
/* 00CA2C 7000BE2C AC3968C8 */  sw    $t9, %lo(g_ContBusy)($at)
/* 00CA30 7000BE30 248453D0 */  addiu $a0, %lo(g_ContEnablePollReceiveMessageQueue) # addiu $a0, $a0, 0x53d0
/* 00CA34 7000BE34 27A5004C */  addiu $a1, $sp, 0x4c
/* 00CA38 7000BE38 0C0037C4 */  jal   osSendMesg
/* 00CA3C 7000BE3C 00003025 */   move  $a2, $zero
/* 00CA40 7000BE40 3C038002 */  lui   $v1, %hi(g_ContPollDisableCount)
/* 00CA44 7000BE44 246368CC */  addiu $v1, %lo(g_ContPollDisableCount) # addiu $v1, $v1, 0x68cc
/* 00CA48 7000BE48 8C6B0000 */  lw    $t3, ($v1)
/* 00CA4C 7000BE4C 256CFFFF */  addiu $t4, $t3, -1
/* 00CA50 7000BE50 100000A2 */  b     .L7000C0DC
/* 00CA54 7000BE54 AC6C0000 */   sw    $t4, ($v1)
.L7000BE58:
/* 00CA58 7000BE58 3C038002 */  lui   $v1, %hi(g_ContPollDisableCount)
/* 00CA5C 7000BE5C 246368CC */  addiu $v1, %lo(g_ContPollDisableCount) # addiu $v1, $v1, 0x68cc
/* 00CA60 7000BE60 8C6D0000 */  lw    $t5, ($v1)
/* 00CA64 7000BE64 3C0E8002 */  lui   $t6, %hi(g_ContInitDone)
/* 00CA68 7000BE68 55A0009D */  bnezl $t5, .L7000C0E0
/* 00CA6C 7000BE6C 8FBF0014 */   lw    $ra, 0x14($sp)
/* 00CA70 7000BE70 8DCE691C */  lw    $t6, %lo(g_ContInitDone)($t6)
/* 00CA74 7000BE74 3C048006 */  lui   $a0, %hi(g_ContInputMessageQueue)
/* 00CA78 7000BE78 24845350 */  addiu $a0, %lo(g_ContInputMessageQueue) # addiu $a0, $a0, 0x5350
/* 00CA7C 7000BE7C 11C00097 */  beqz  $t6, .L7000C0DC
/* 00CA80 7000BE80 27A5004C */   addiu $a1, $sp, 0x4c
/* 00CA84 7000BE84 0C003774 */  jal   osRecvMesg
/* 00CA88 7000BE88 00003025 */   move  $a2, $zero
/* 00CA8C 7000BE8C 14400093 */  bnez  $v0, .L7000C0DC
/* 00CA90 7000BE90 3C058006 */   lui   $a1, %hi(g_ContData)
/* 00CA94 7000BE94 3C018002 */  lui   $at, %hi(g_ContBusy)
/* 00CA98 7000BE98 24A54F30 */  addiu $a1, %lo(g_ContData) # addiu $a1, $a1, 0x4f30
/* 00CA9C 7000BE9C AC2068C8 */  sw    $zero, %lo(g_ContBusy)($at)
/* 00CAA0 7000BEA0 8CA201E8 */  lw    $v0, 0x1e8($a1)
/* 00CAA4 7000BEA4 24010014 */  li    $at, 20
/* 00CAA8 7000BEA8 8CB801E4 */  lw    $t8, 0x1e4($a1)
/* 00CAAC 7000BEAC 24430001 */  addiu $v1, $v0, 1
/* 00CAB0 7000BEB0 0061001A */  div   $zero, $v1, $at
/* 00CAB4 7000BEB4 00001810 */  mfhi  $v1
/* 00CAB8 7000BEB8 54780003 */  bnel  $v1, $t8, .L7000BEC8
/* 00CABC 7000BEBC 0003C880 */   sll   $t9, $v1, 2
/* 00CAC0 7000BEC0 00401825 */  move  $v1, $v0
/* 00CAC4 7000BEC4 0003C880 */  sll   $t9, $v1, 2
.L7000BEC8:
/* 00CAC8 7000BEC8 0323C823 */  subu  $t9, $t9, $v1
/* 00CACC 7000BECC 0019C8C0 */  sll   $t9, $t9, 3
/* 00CAD0 7000BED0 00B92021 */  addu  $a0, $a1, $t9
/* 00CAD4 7000BED4 0C00538D */  jal   osContGetReadData
/* 00CAD8 7000BED8 AFA30040 */   sw    $v1, 0x40($sp)
/* 00CADC 7000BEDC 8FA20040 */  lw    $v0, 0x40($sp)
/* 00CAE0 7000BEE0 24010014 */  li    $at, 20
/* 00CAE4 7000BEE4 3C048002 */  lui   $a0, %hi(g_ContCheckStatusTimer60)
/* 00CAE8 7000BEE8 244B0013 */  addiu $t3, $v0, 0x13
/* 00CAEC 7000BEEC 0161001A */  div   $zero, $t3, $at
/* 00CAF0 7000BEF0 24846920 */  addiu $a0, %lo(g_ContCheckStatusTimer60) # addiu $a0, $a0, 0x6920
/* 00CAF4 7000BEF4 8C8D0000 */  lw    $t5, ($a0)
/* 00CAF8 7000BEF8 00006010 */  mfhi  $t4
/* 00CAFC 7000BEFC 24010078 */  li    $at, 120
/* 00CB00 7000BF00 25AE0001 */  addiu $t6, $t5, 1
/* 00CB04 7000BF04 01C1001A */  div   $zero, $t6, $at
/* 00CB08 7000BF08 3C058006 */  lui   $a1, %hi(g_ContData)
/* 00CB0C 7000BF0C 24A54F30 */  addiu $a1, %lo(g_ContData) # addiu $a1, $a1, 0x4f30
/* 00CB10 7000BF10 0000C010 */  mfhi  $t8
/* 00CB14 7000BF14 ACAC01EC */  sw    $t4, 0x1ec($a1)
/* 00CB18 7000BF18 AC8E0000 */  sw    $t6, ($a0)
/* 00CB1C 7000BF1C 17000006 */  bnez  $t8, .L7000BF38
/* 00CB20 7000BF20 ACA201E8 */   sw    $v0, 0x1e8($a1)
/* 00CB24 7000BF24 0C002E04 */  jal   joyCheckStatus
/* 00CB28 7000BF28 00000000 */   nop
/* 00CB2C 7000BF2C 3C058006 */  lui   $a1, %hi(g_ContData)
/* 00CB30 7000BF30 24A54F30 */  addiu $a1, %lo(g_ContData) # addiu $a1, $a1, 0x4f30
/* 00CB34 7000BF34 8CA201E8 */  lw    $v0, 0x1e8($a1)
.L7000BF38:
/* 00CB38 7000BF38 0002C880 */  sll   $t9, $v0, 2
/* 00CB3C 7000BF3C 0322C823 */  subu  $t9, $t9, $v0
/* 00CB40 7000BF40 0019C8C0 */  sll   $t9, $t9, 3
/* 00CB44 7000BF44 00B93021 */  addu  $a2, $a1, $t9
/* 00CB48 7000BF48 00002025 */  move  $a0, $zero
/* 00CB4C 7000BF4C 24070006 */  li    $a3, 6
.L7000BF50:
/* 00CB50 7000BF50 00870019 */  multu $a0, $a3
/* 00CB54 7000BF54 00001012 */  mflo  $v0
/* 00CB58 7000BF58 00C25821 */  addu  $t3, $a2, $v0
/* 00CB5C 7000BF5C 91630004 */  lbu   $v1, 4($t3)
/* 00CB60 7000BF60 1460000A */  bnez  $v1, .L7000BF8C
/* 00CB64 7000BF64 00000000 */   nop
/* 00CB68 7000BF68 8CAC01EC */  lw    $t4, 0x1ec($a1)
/* 00CB6C 7000BF6C 000C6880 */  sll   $t5, $t4, 2
/* 00CB70 7000BF70 01AC6823 */  subu  $t5, $t5, $t4
/* 00CB74 7000BF74 000D68C0 */  sll   $t5, $t5, 3
/* 00CB78 7000BF78 00AD7021 */  addu  $t6, $a1, $t5
/* 00CB7C 7000BF7C 01C27821 */  addu  $t7, $t6, $v0
/* 00CB80 7000BF80 91F80004 */  lbu   $t8, 4($t7)
/* 00CB84 7000BF84 1700000C */  bnez  $t8, .L7000BFB8
/* 00CB88 7000BF88 00000000 */   nop
.L7000BF8C:
/* 00CB8C 7000BF8C 1060000E */  beqz  $v1, .L7000BFC8
/* 00CB90 7000BF90 24840001 */   addiu $a0, $a0, 1
/* 00CB94 7000BF94 8CB901EC */  lw    $t9, 0x1ec($a1)
/* 00CB98 7000BF98 00195880 */  sll   $t3, $t9, 2
/* 00CB9C 7000BF9C 01795823 */  subu  $t3, $t3, $t9
/* 00CBA0 7000BFA0 000B58C0 */  sll   $t3, $t3, 3
/* 00CBA4 7000BFA4 00AB6021 */  addu  $t4, $a1, $t3
/* 00CBA8 7000BFA8 01826821 */  addu  $t5, $t4, $v0
/* 00CBAC 7000BFAC 91AE0004 */  lbu   $t6, 4($t5)
/* 00CBB0 7000BFB0 55C00006 */  bnezl $t6, .L7000BFCC
/* 00CBB4 7000BFB4 00047E00 */   sll   $t7, $a0, 0x18
.L7000BFB8:
/* 00CBB8 7000BFB8 0C002E04 */  jal   joyCheckStatus
/* 00CBBC 7000BFBC 00000000 */   nop
/* 00CBC0 7000BFC0 10000006 */  b     .L7000BFDC
/* 00CBC4 7000BFC4 00000000 */   nop
.L7000BFC8:
/* 00CBC8 7000BFC8 00047E00 */  sll   $t7, $a0, 0x18
.L7000BFCC:
/* 00CBCC 7000BFCC 000F2603 */  sra   $a0, $t7, 0x18
/* 00CBD0 7000BFD0 28810004 */  slti  $at, $a0, 4
/* 00CBD4 7000BFD4 1420FFDE */  bnez  $at, .L7000BF50
/* 00CBD8 7000BFD8 00000000 */   nop
.L7000BFDC:
/* 00CBDC 7000BFDC 0C002E9F */  jal   joyRumblePakTick
/* 00CBE0 7000BFE0 00000000 */   nop
/* 00CBE4 7000BFE4 3C048006 */  lui   $a0, %hi(g_ContInputMessageQueue)
/* 00CBE8 7000BFE8 0C00535C */  jal   osContStartReadData
/* 00CBEC 7000BFEC 24845350 */   addiu $a0, %lo(g_ContInputMessageQueue) # addiu $a0, $a0, 0x5350
/* 00CBF0 7000BFF0 3C038002 */  lui   $v1, %hi(g_ContBadReadTimer60)
/* 00CBF4 7000BFF4 8C636970 */  lw    $v1, %lo(g_ContBadReadTimer60)($v1)
/* 00CBF8 7000BFF8 24190001 */  li    $t9, 1
/* 00CBFC 7000BFFC 3C018002 */  lui   $at, %hi(g_ContBusy)
/* 00CC00 7000C000 AC3968C8 */  sw    $t9, %lo(g_ContBusy)($at)
/* 00CC04 7000C004 3C018002 */  lui   $at, %hi(g_ContBadReadTimer60)
/* 00CC08 7000C008 24630001 */  addiu $v1, $v1, 1
/* 00CC0C 7000C00C AC236970 */  sw    $v1, %lo(g_ContBadReadTimer60)($at)
/* 00CC10 7000C010 2861003C */  slti  $at, $v1, 0x3c
/* 00CC14 7000C014 14200031 */  bnez  $at, .L7000C0DC
/* 00CC18 7000C018 3C098002 */   lui   $t1, %hi(g_ContBadReadsStickX)
/* 00CC1C 7000C01C 3C048002 */  lui   $a0, %hi(g_ContBadReadsStickY)
/* 00CC20 7000C020 3C058002 */  lui   $a1, %hi(g_ContBadReadsButtons)
/* 00CC24 7000C024 3C038002 */  lui   $v1, %hi(g_ContBadReadsButtonsPressed)
/* 00CC28 7000C028 3C0A8002 */  lui   $t2, %hi(g_ContBadReadTimer60)
/* 00CC2C 7000C02C 254A6970 */  addiu $t2, %lo(g_ContBadReadTimer60) # addiu $t2, $t2, 0x6970
/* 00CC30 7000C030 24636960 */  addiu $v1, %lo(g_ContBadReadsButtonsPressed) # addiu $v1, $v1, 0x6960
/* 00CC34 7000C034 24A56950 */  addiu $a1, %lo(g_ContBadReadsButtons) # addiu $a1, $a1, 0x6950
/* 00CC38 7000C038 24846940 */  addiu $a0, %lo(g_ContBadReadsStickY) # addiu $a0, $a0, 0x6940
/* 00CC3C 7000C03C 25296930 */  addiu $t1, %lo(g_ContBadReadsStickX) # addiu $t1, $t1, 0x6930
.L7000C040:
/* 00CC40 7000C040 8D220000 */  lw    $v0, ($t1)
/* 00CC44 7000C044 5440000B */  bnezl $v0, .L7000C074
/* 00CC48 7000C048 AD200000 */   sw    $zero, ($t1)
/* 00CC4C 7000C04C 8C8B0000 */  lw    $t3, ($a0)
/* 00CC50 7000C050 55600008 */  bnezl $t3, .L7000C074
/* 00CC54 7000C054 AD200000 */   sw    $zero, ($t1)
/* 00CC58 7000C058 8CAC0000 */  lw    $t4, ($a1)
/* 00CC5C 7000C05C 55800005 */  bnezl $t4, .L7000C074
/* 00CC60 7000C060 AD200000 */   sw    $zero, ($t1)
/* 00CC64 7000C064 8C6D0000 */  lw    $t5, ($v1)
/* 00CC68 7000C068 51A00006 */  beql  $t5, $zero, .L7000C084
/* 00CC6C 7000C06C 8D220004 */   lw    $v0, 4($t1)
/* 00CC70 7000C070 AD200000 */  sw    $zero, ($t1)
.L7000C074:
/* 00CC74 7000C074 AC800000 */  sw    $zero, ($a0)
/* 00CC78 7000C078 ACA00000 */  sw    $zero, ($a1)
/* 00CC7C 7000C07C AC600000 */  sw    $zero, ($v1)
/* 00CC80 7000C080 8D220004 */  lw    $v0, 4($t1)
.L7000C084:
/* 00CC84 7000C084 5440000B */  bnezl $v0, .L7000C0B4
/* 00CC88 7000C088 AD200004 */   sw    $zero, 4($t1)
/* 00CC8C 7000C08C 8C8E0004 */  lw    $t6, 4($a0)
/* 00CC90 7000C090 55C00008 */  bnezl $t6, .L7000C0B4
/* 00CC94 7000C094 AD200004 */   sw    $zero, 4($t1)
/* 00CC98 7000C098 8CAF0004 */  lw    $t7, 4($a1)
/* 00CC9C 7000C09C 55E00005 */  bnezl $t7, .L7000C0B4
/* 00CCA0 7000C0A0 AD200004 */   sw    $zero, 4($t1)
/* 00CCA4 7000C0A4 8C780004 */  lw    $t8, 4($v1)
/* 00CCA8 7000C0A8 53000006 */  beql  $t8, $zero, .L7000C0C4
/* 00CCAC 7000C0AC 24630008 */   addiu $v1, $v1, 8
/* 00CCB0 7000C0B0 AD200004 */  sw    $zero, 4($t1)
.L7000C0B4:
/* 00CCB4 7000C0B4 AC800004 */  sw    $zero, 4($a0)
/* 00CCB8 7000C0B8 ACA00004 */  sw    $zero, 4($a1)
/* 00CCBC 7000C0BC AC600004 */  sw    $zero, 4($v1)
/* 00CCC0 7000C0C0 24630008 */  addiu $v1, $v1, 8
.L7000C0C4:
/* 00CCC4 7000C0C4 25290008 */  addiu $t1, $t1, 8
/* 00CCC8 7000C0C8 24840008 */  addiu $a0, $a0, 8
/* 00CCCC 7000C0CC 146AFFDC */  bne   $v1, $t2, .L7000C040
/* 00CCD0 7000C0D0 24A50008 */   addiu $a1, $a1, 8
/* 00CCD4 7000C0D4 3C018002 */  lui   $at, %hi(g_ContBadReadTimer60)
/* 00CCD8 7000C0D8 AC206970 */  sw    $zero, %lo(g_ContBadReadTimer60)($at)
.L7000C0DC:
/* 00CCDC 7000C0DC 8FBF0014 */  lw    $ra, 0x14($sp)
.L7000C0E0:
/* 00CCE0 7000C0E0 27BD0050 */  addiu $sp, $sp, 0x50
/* 00CCE4 7000C0E4 03E00008 */  jr    $ra
/* 00CCE8 7000C0E8 00000000 */   nop
)
#endif

s8 joyGetStickX(s8 contpadnum)
{
    if ((g_ContDataPtr->playbackcontcount < 0) && ((g_ConnectedControllers >> contpadnum & 1) == 0))
    {
        g_ContBadReadsStickX[contpadnum]++;
        return 0;
    }

    return g_ContDataPtr->samples[g_ContDataPtr->curlast].pads[contpadnum].stick_x;
}

s8 joy7000C174(s8 contpadnum)
{
    if ((g_ContDataPtr->playbackcontcount < 0) && ((g_ConnectedControllers >> contpadnum & 1) == 0))
    {
        g_ContBadReadsStickX[contpadnum]++;
        return 0;
    }

    return g_ContDataPtr->samples[g_ContDataPtr->curstart].pads[contpadnum].stick_x;
}

s8 joyGetStickY(s8 contpadnum)
{
    if ((g_ContDataPtr->playbackcontcount < 0) && ((g_ConnectedControllers >> contpadnum & 1) == 0))
    {
        g_ContBadReadsStickY[contpadnum]++;
        return 0;
    }

    return g_ContDataPtr->samples[g_ContDataPtr->curlast].pads[contpadnum].stick_y;
}

s8 joy7000C284(s8 contpadnum)
{
    if ((g_ContDataPtr->playbackcontcount < 0) && ((g_ConnectedControllers >> contpadnum & 1) == 0))
    {
        g_ContBadReadsStickY[contpadnum]++;
        return 0;
    }

    return g_ContDataPtr->samples[g_ContDataPtr->curstart].pads[contpadnum].stick_y;
}

u16 joyGetButtons(s8 contpadnum, u16 mask)
{
    if ((g_ContDataPtr->playbackcontcount < 0) && ((g_ConnectedControllers >> contpadnum & 1) == 0))
    {
        g_ContBadReadsButtons[contpadnum]++;
        return 0;
    }

    return g_ContDataPtr->samples[g_ContDataPtr->curlast].pads[contpadnum].button & mask;
}

u16 joyGetButtonsPressedThisFrame(s8 contpadnum, u16 mask)
{
    if ((g_ContDataPtr->playbackcontcount < 0) && ((g_ConnectedControllers >> contpadnum & 1) == 0))
    {
        g_ContBadReadsButtonsPressed[contpadnum]++;
        return 0;
    }

    return g_ContDataPtr->buttonspressed[contpadnum] & mask;
}

void joy7000C430(s8 *bytes, u16 bitfield)
{
    s32 i;
    for (i = 15; i >= 0; i--)
    {
        *bytes++ = (((((bitfield >> i) & 1) > 0) * 17) + 32);
    }
}

void joy7000C470(void)
{
    s32 i = 0;
    for (i = 0; i < joyGetControllerCount(); i++)
    {
        // Removed
    }
}

/**
 * Reads controller joystick x value. JOY_CLAMP_OFFSET is first
 * added to the raw value, then it is clamped between JOY_CLAMP_MIN
 * and JOY_CLAMP_MAX. The value is then normalized against supplied range parameters.
 * 
 * @param contpadnum controller to read.
 * @param rangemin min value of range to normalize against.
 * @param rangemax max value of range to normalize against.
 * 
 * @return returns normalized value between range, as an s32.
 */
s32 joyGetStickXInRange(s8 contpadnum, s32 rangemin, s32 rangemax)
{
    s32 range;
    s32 stick_x = joyGetStickX(contpadnum) + JOY_CLAMP_OFFSET;

    if (stick_x > JOY_CLAMP_MAX)
    {
        stick_x = JOY_CLAMP_MAX;
    }

    if (stick_x < JOY_CLAMP_MIN)
    {
        stick_x = JOY_CLAMP_MIN;
    }

    range = (rangemax - rangemin);
    return (((stick_x * range) / JOY_CLAMP_MAX) + rangemin);
}

/**
 * Reads controller joystick y value. JOY_CLAMP_OFFSET is first
 * added to the raw value, then it is clamped between JOY_CLAMP_MIN
 * and JOY_CLAMP_MAX. The value is then normalized against supplied range parameters.
 * 
 * @param contpadnum controller to read.
 * @param rangemin min value of range to normalize against.
 * @param rangemax max value of range to normalize against.
 * 
 * @return returns normalized value between range, as an s32.
 */
s32 joyGetStickYInRange(s8 contpadnum, s32 rangemin, s32 rangemax)
{
    s32 range;
    s32 stick_y = joyGetStickY(contpadnum) + JOY_CLAMP_OFFSET;

    if (stick_y > JOY_CLAMP_MAX)
    {
        stick_y = JOY_CLAMP_MAX;
    }

    if (stick_y < JOY_CLAMP_MIN)
    {
        stick_y = JOY_CLAMP_MIN;
    }

    range = (rangemax - rangemin);
    return (((stick_y * range) / JOY_CLAMP_MAX) + rangemin);
}

/**
 * Reads controller joystick x value. JOY_CLAMP_OFFSET is first
 * added to the raw value, then it is clamped between JOY_CLAMP_MIN
 * and JOY_CLAMP_MAX. The value is then normalized against supplied range parameters.
 * 
 * @param contpadnum controller to read.
 * @param rangemin min value of range to normalize against.
 * @param rangemax max value of range to normalize against.
 * 
 * @return returns normalized value between range, as a float.
 */
f32 joyGetStickXInRangef(s8 contpadnum, f32 rangemin, f32 rangemax)
{
    f32 range;
    s32 stick_x = joyGetStickX(contpadnum) + JOY_CLAMP_OFFSET;

    if (stick_x > JOY_CLAMP_MAX)
    {
        stick_x = JOY_CLAMP_MAX;
    }

    if (stick_x < JOY_CLAMP_MIN)
    {
        stick_x = JOY_CLAMP_MIN;
    }

    range = (rangemax - rangemin);
    return (((stick_x / JOY_CLAMP_MAX_F) * range) + rangemin);
}

/**
 * Reads controller joystick y value. JOY_CLAMP_OFFSET is first
 * added to the raw value, then it is clamped between JOY_CLAMP_MIN
 * and JOY_CLAMP_MAX. The value is then normalized against supplied range parameters.
 * 
 * @param contpadnum controller to read.
 * @param rangemin min value of range to normalize against.
 * @param rangemax max value of range to normalize against.
 * 
 * @return returns normalized value between range, as a float.
 */
f32 joyGetStickYInRangef(s8 contpadnum, f32 rangemin, f32 rangemax)
{
    f32 range;
    s32 stick_y = joyGetStickY(contpadnum) + JOY_CLAMP_OFFSET;

    if (stick_y > JOY_CLAMP_MAX)
    {
        stick_y = JOY_CLAMP_MAX;
    }

    if (stick_y < JOY_CLAMP_MIN)
    {
        stick_y = JOY_CLAMP_MIN;
    }

    range = (rangemax - rangemin);
    return (((stick_y / JOY_CLAMP_MAX_F) * range) + rangemin);
}

/**
 * Disables os message polling.
 */
void joyDisablePoll(void)
{
    OSMesg msg;

    osSendMesg(&g_ContDisablePollSendMessageQueue, &msg, OS_MESG_NOBLOCK);
    osRecvMesg(&g_ContDisablePollReceiveMessageQueue, &msg, OS_MESG_BLOCK);
}

/**
 * Enables os message polling.
 */
void joyEnablePoll(void)
{
    OSMesg msg;

    osSendMesg(&g_ContEnablePollSendMessageQueue, &msg, OS_MESG_NOBLOCK);
    osRecvMesg(&g_ContEnablePollReceiveMessageQueue, &msg, OS_MESG_BLOCK);
}

s32 joyGamePakProbe(void)
{
    s32 type;

    joyDisablePoll();
    type = osEepromProbe(&g_ContInputMessageQueue);
    joyEnablePoll();

    return type;
}

s32 joyGamePakRead(u8 address, u8 *buffer)
{
    s32 ret;

    joyDisablePoll();
    ret = osEepromRead(&g_ContInputMessageQueue, address, buffer);
    joyEnablePoll();

    return ret;
}

s32 joyGamePakWrite(u8 address, u8 *buffer)
{
    s32 ret;

    joyDisablePoll();
    ret = osEepromWrite(&g_ContInputMessageQueue, address, buffer);
    joyEnablePoll();

    return ret;
}

s32 joyGamePakLongRead(u8 address, u8 *buffer, s32 nbytes)
{
    s32 ret;

    joyDisablePoll();
    ret = osEepromLongRead(&g_ContInputMessageQueue, address, buffer, nbytes);
    joyEnablePoll();

    return ret;
}

s32 joyGamePakLongWrite(u8 address, u8 *buffer, s32 nbytes)
{
    s32 ret;

    joyDisablePoll();
    ret = osEepromLongWrite(&g_ContInputMessageQueue, address, buffer, nbytes);
    joyEnablePoll();

    return ret;
}

void joyRumblePakStart(s32 controller, f32 duration)
{
    s32 duration60 = (duration * 60.0f);

    if ((g_ContPlaybackFunc == NULL) && (g_ContRumblePakInitState[controller] > RUMBLEPAKINITSTATE_NOT_READY))
    {
        if (g_ContRumblePakTimer60[controller] < duration60)
        {
            g_ContRumblePakTimer60[controller] = duration60;
        }
        if (g_ContRumblePakCurrentState[controller] == RUMBLEPAKSTATE_OFF)
        {
            g_ContRumblePakTargetState[controller] = RUMBLEPAKSTATE_ON;
        }
    }
}

void joyRumblePakStop(void)
{
    s32 i;

    for (i = 0; i < MAXCONTROLLERS; i++)
    {
#if defined(BUGFIX_R0)
        g_ContRumblePakCurrentState[i] = RUMBLEPAKSTATE_ON;
        g_ContRumblePakTargetState[i] = RUMBLEPAKSTATE_OFF;
#else
        g_ContRumblePakTargetState[i] = RUMBLEPAKSTATE_UNKNOWN;
#endif
    }
}

void joySetContDataIndex(s32 index)
{
    g_ContDataPtr = &g_ContData[index];
}

s32 joyGetContDataIndex(void)
{
    return (g_ContDataPtr - g_ContData);
}
