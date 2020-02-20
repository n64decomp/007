#ifndef _PI_H_
#define _PI_H_
#include <ultra64.h>

extern OSMesg piCmdBuf[0x8];
extern OSMesgQueue piCmdQ;

void start_pi_manager(void);

#endif