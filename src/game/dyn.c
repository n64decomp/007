#include <ultra64.h>
#include "dyn.h"
#include <token.h>
#include <str.h>
#include <memp.h>
#include <macro.h>

/**
 * This file handles memory usage for graphics related tasks.
 *
 * There are two pools, "gfx" and "vtx", which are used to store different data.
 *
 * The gfx pool (g_GfxBuffers) is sized based on the stage's -mgfx
 * argument. It contains only the master display list's GBI bytecode.
 * The master gdl is passed through all rendering functions in the game engine,
 * where each appends to the display list.
 *
 * The vtx pool (g_VtxBuffers) is sized based on the stage's -mvtx argument.
 * It is used for auxiliary graphics data such as vertex arrays, matrices and
 * colours.
 *
 * Both the gfx and vtx pools are split into two buffers of equal size.
 * Only one buffer is active at a time - the other is being drawn to the screen
 * while the active one is being built. Each time a frame is finished the active
 * buffer index is swapped to the other one.
 *
 * Both the gfx and vtx pools have a third element in them, but this is just a
 * marker for the end of the second element's allocation.
 */

u8 *g_GfxBuffers[3];
u8 *g_VtxBuffers[3];
u8 *g_GfxMemPos;
u8 g_GfxActiveBufferIndex;
s32 g_GfxRequestedDisplayList;
s32 D_800482E0 = 0;
s32 g_GfxSizesByPlayerCount[] = {0x10000, 0x18000, 0x20000, 0x28000};
s32 g_VtxSizesByPlayerCount[] = {0x10000, 0x18000, 0x20000, 0x28000};

char membars_string1[] = ">>>>>>>>>>>>>>>>>>>>>>>>>";
char membars_string2[] = "=========================";
char membars_string3[] = "-------------------------";

void dynInit(void) {
    debTryAdd(&D_800482E0, "dyn_c_debug");
}

void dynInitMemory(void) {
    if (tokenFind(1, "-mgfx")) {
        g_GfxSizesByPlayerCount[getPlayerCount() - 1] = strtol(tokenFind(1, "-mgfx"), NULL, 0) * 1024;
    }
    if (tokenFind(1, "-mvtx")) {
        g_VtxSizesByPlayerCount[getPlayerCount() - 1] = strtol(tokenFind(1, "-mvtx"), NULL, 0) * 1024;
    }

    g_GfxBuffers[0] = mempAllocBytesInBank(g_GfxSizesByPlayerCount[getPlayerCount() - 1] * 2, MEMPOOL_STAGE);
    g_GfxBuffers[1] = (g_GfxBuffers[0] + g_GfxSizesByPlayerCount[getPlayerCount() - 1]);
    g_GfxBuffers[2] = (g_GfxBuffers[1] + g_GfxSizesByPlayerCount[getPlayerCount() - 1]);

    g_VtxBuffers[0] = mempAllocBytesInBank(g_VtxSizesByPlayerCount[getPlayerCount() - 1] * 2, MEMPOOL_STAGE);
    g_VtxBuffers[1] = (g_VtxBuffers[0] + g_VtxSizesByPlayerCount[getPlayerCount() - 1]);
    g_VtxBuffers[2] = (g_VtxBuffers[1] + g_VtxSizesByPlayerCount[getPlayerCount() - 1]);

    g_GfxActiveBufferIndex = 0;
    g_GfxRequestedDisplayList = FALSE;
    g_GfxMemPos = g_VtxBuffers[0];
}

Gfx *dynGetMasterDisplayList(void) {
    g_GfxRequestedDisplayList = TRUE;

    return (Gfx*)g_GfxBuffers[g_GfxActiveBufferIndex];
}

s32 dynGetFreeGfx2(Gfx *gdl) {
    return (Gfx*)g_GfxBuffers[g_GfxActiveBufferIndex + 1] - gdl;
}

void/*Vtx?*/ *dynAllocate7F0BD6C4(s32 count) {
    void *ptr = g_GfxMemPos;
	g_GfxMemPos += count * 0x10/*sizeof(Vtx)?*/;
	return ptr;
}

Mtx *dynAllocateMatrix(void)
{
	void *ptr = g_GfxMemPos;
	g_GfxMemPos += sizeof(Mtx);
	return ptr;
}

void/*Light?*/ *dynAllocate7F0BD6F8(s32 count) {
    void *ptr = g_GfxMemPos;
	g_GfxMemPos += count * 0x10/*sizeof(Light)?*/;
	return ptr;
}

void *dynAllocate(s32 size) {
    void *ptr = g_GfxMemPos;
	size = ALIGN16_a(size);
	g_GfxMemPos += size;
	return ptr;
}

void dynSwapBuffers(void) {
    g_GfxActiveBufferIndex = (g_GfxActiveBufferIndex ^ 1);
    g_GfxRequestedDisplayList = FALSE;
    g_GfxMemPos = g_VtxBuffers[g_GfxActiveBufferIndex];
}

void dynRemovedFunc(Gfx *gdl) {
}

s32 dynGetFreeGfx(Gfx *gdl) {
    return (Gfx*)g_GfxBuffers[g_GfxActiveBufferIndex + 1] - gdl;
}

s32 dynGetFreeVtx(void) {
	return g_VtxBuffers[g_GfxActiveBufferIndex + 1] - g_GfxMemPos;
}

// Address 0x7F0BD7CC NTSC
void dynCalculateMembarLength(const char* arg0, f32 arg1, f32 arg2)
{
    s32 len;
    f32 zero = 0;
    
    len = strlen(arg0);
    
    arg1 /= arg2;
    
    if(zero);
    
    if (arg1 < zero && len > 1)
    {
        if (len > 1)
        {
            
        }
    }
}

void dynDrawMembars(Gfx *gdl) {
    dynCalculateMembarLength(membars_string2, ((Gfx*)g_GfxBuffers[g_GfxActiveBufferIndex + 1] - gdl), ((Gfx*)g_GfxBuffers[g_GfxActiveBufferIndex + 1] - (Gfx*)g_GfxBuffers[g_GfxActiveBufferIndex]));
    dynCalculateMembarLength(membars_string2, (g_VtxBuffers[g_GfxActiveBufferIndex + 1] - g_GfxMemPos), (g_VtxBuffers[g_GfxActiveBufferIndex + 1] - g_VtxBuffers[g_GfxActiveBufferIndex]));
}
