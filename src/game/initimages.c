#include <ultra64.h>
#include "image.h"

/**
 * NTSC address 0x7F000BD0.
*/
void image_entries_load(void)
{   
    s32 offset;
    s32 next_offset;
    s32 temp_t3;
    struct image_entry *entryp;

    entryp = g_Textures;
    offset = 0;
    next_offset = entryp->dataoffset;

    while (entryp->dataoffset != 0xffff)
    {
        temp_t3 = entryp->dataoffset;
        entryp->dataoffset = offset;
        offset += temp_t3;
        entryp++;
        next_offset = entryp->dataoffset;
    }

    entryp->dataoffset = offset;
}
