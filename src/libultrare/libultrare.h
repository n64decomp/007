#ifndef _RARE_LIBULTRA_H_
#define _RARE_LIBULTRA_H_

/**
 * header file specific to Rare libultra modifications.
*/

#include <PR/ultratypes.h>


#define WAIT_ON_ONLY_IOBUSY(stat)       \
    stat = IO_READ(PI_STATUS_REG);      \
    while (stat & (PI_STATUS_IO_BUSY))  \
        stat = IO_READ(PI_STATUS_REG);

#define LEO_ERROR_3    3
#define LEO_ERROR_6    6
#define LEO_ERROR_17  17
#define LEO_ERROR_75  75

extern s32 osDiskExist;

#endif

