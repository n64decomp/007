#include <ultra64.h>
#include <bondconstants.h>
#include <memp.h>
#include "alloc_window_pieces.h"
#include "unk_0A1DA0.h"



void alloc_shattered_window_pieces(void)
{
    s32 i;
    s32 level = lvlGetCurrentStageToLoad();

    SHATTERED_WINDOW_PIECES_BUFFER_LEN = (200 / getPlayerCount());
    if ((level == LEVELID_STREETS) || (level == LEVELID_DEPOT))
    {
        SHATTERED_WINDOW_PIECES_BUFFER_LEN = (SHATTERED_WINDOW_PIECES_BUFFER_LEN >> 1);
    }
    ptr_shattered_window_pieces = mempAllocBytesInBank(((SHATTERED_WINDOW_PIECES_BUFFER_LEN * 0x68) + 0xF) & ~0xF, MEMPOOL_STAGE);
    for(i=0; i<SHATTERED_WINDOW_PIECES_BUFFER_LEN; i++)
    {
        ptr_shattered_window_pieces[i].piece = 0;
    }

    g_NextShardNum = 0;
}

