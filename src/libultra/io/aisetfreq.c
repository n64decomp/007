#include <rcp.h>
#include "../os/osint.h"

s32 osAiSetFrequency(u32 frequency)
{
    register unsigned int dacRate;
    register unsigned char bitRate;
    register float f;
    f = osViClock / (float)frequency + .5f;
    dacRate = f;
    if (dacRate < AI_MIN_DAC_RATE)
        return -1;
    bitRate = (dacRate / 66);
    if (bitRate > AI_MAX_BIT_RATE)
        bitRate = AI_MAX_BIT_RATE;
    IO_WRITE(AI_DACRATE_REG, dacRate - 1);
    IO_WRITE(AI_BITRATE_REG, bitRate - 1);
    IO_WRITE(AI_CONTROL_REG, AI_CONTROL_DMA_ON);
    return osViClock / (s32)dacRate;
}
