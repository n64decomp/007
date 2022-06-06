#include <ultra64.h>

#if defined(LEFTOVERDEBUG)
u8 _decompressBuffer[0xAB400];
#else
u8 _decompressBuffer[0xA1AB0];
#endif