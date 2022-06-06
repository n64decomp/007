#include <ultra64.h>
#include <random.h>
#include "file.h"

/**
 * Get CRC of bytes from addressA to addressB and save to retval.chksum1 and retval.chksum2
 *
 * @param addressA
 * @param addressB
 * @param retval
 * @return * void
 */
void fileGenerateCRC(u8 *addressA, u8 *addressB, save_data *retval)
{
    u8 *byte;
    s32 shift      = 0; // Shift value
    s64 polynormal = 0x8F809F473108B3C1;
    s32 checksum1  = 0; // Final checksum #1
    s32 checksum2  = 0; // Final checksum #2

    for(byte = addressA; byte < addressB; byte++,shift += 7)
    {
        polynormal += *byte << (shift & 0xF) ;
        checksum1 ^= randomGetNextFrom(&polynormal);
    }

    for(byte = addressB - 1; byte >= addressA; byte--,shift += 3)
    {
        polynormal += *byte << (shift & 0xF) ;
        checksum2 ^= randomGetNextFrom(&polynormal);
    }
    retval->chksum1 = checksum1;
    retval->chksum2 = checksum2;
}
