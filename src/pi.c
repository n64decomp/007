#include "ultra64.h"


OSMesg piCmdBuf[0x8];
OSMesgQueue piCmdQ;

void piCreateManager(void) {
    osCreatePiManager(0x96, &piCmdQ, &piCmdBuf, 8);
}
