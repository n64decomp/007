#include "ultra64.h"


OSMesg piCmdBuf[0x8];
OSMesgQueue piCmdQ;

void start_pi_manager(void) {
    osCreatePiManager(0x96, &piCmdQ, &piCmdBuf, 8);
}
