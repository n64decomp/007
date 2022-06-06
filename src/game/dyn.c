#include <ultra64.h>
#include "dyn.h"
#include <token.h>
#include <str.h>
#include <memp.h>

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

void dynInitDebugNoticeList(void) {
    debTryAdd(&D_800482E0, "dyn_c_debug");
}

void dynInitMemory(void) {
    if (tokenFind(1, "-mgfx")) {
        g_GfxSizesByPlayerCount[getPlayerCount() - 1] = strtol(tokenFind(1, "-mgfx"), NULL, 0) * 1024;
    }
    if (tokenFind(1, "-mvtx")) {
        g_VtxSizesByPlayerCount[getPlayerCount() - 1] = strtol(tokenFind(1, "-mvtx"), NULL, 0) * 1024;
    }

    g_GfxBuffers[0] = mempAllocBytesInBank(g_GfxSizesByPlayerCount[getPlayerCount() - 1] * 2, 4);
    g_GfxBuffers[1] = (g_GfxBuffers[0] + g_GfxSizesByPlayerCount[getPlayerCount() - 1]);
    g_GfxBuffers[2] = (g_GfxBuffers[1] + g_GfxSizesByPlayerCount[getPlayerCount() - 1]);

    g_VtxBuffers[0] = mempAllocBytesInBank(g_VtxSizesByPlayerCount[getPlayerCount() - 1] * 2, 4);
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

#ifdef NONMATCHING
// $f2 is used for 0.0f instead of $f0
f32 dynCalculateMembarLength(const char* arg0, f32 arg1, f32 arg2) {
    strlen(arg0);
    arg1 /= arg2;
    if (arg1 < 0.0f) {
        return 0.0f;
    }
}
#else
f32 dynCalculateMembarLength(const char* arg0, f32 arg1, f32 arg2);
GLOBAL_ASM(
.text
glabel dynCalculateMembarLength
/* 0F22FC 7F0BD7CC 44856000 */  mtc1  $a1, $f12
/* 0F2300 7F0BD7D0 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0F2304 7F0BD7D4 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0F2308 7F0BD7D8 AFA60020 */  sw    $a2, 0x20($sp)
/* 0F230C 7F0BD7DC 0C004E1F */  jal   strlen
/* 0F2310 7F0BD7E0 E7AC001C */   swc1  $f12, 0x1c($sp)
/* 0F2314 7F0BD7E4 C7AC001C */  lwc1  $f12, 0x1c($sp)
/* 0F2318 7F0BD7E8 C7A40020 */  lwc1  $f4, 0x20($sp)
/* 0F231C 7F0BD7EC 44800000 */  mtc1  $zero, $f0
/* 0F2320 7F0BD7F0 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0F2324 7F0BD7F4 46046303 */  div.s $f12, $f12, $f4
/* 0F2328 7F0BD7F8 4600603C */  c.lt.s $f12, $f0
/* 0F232C 7F0BD7FC 00000000 */  nop   
/* 0F2330 7F0BD800 45000001 */  bc1f  .L7F0BD808
/* 0F2334 7F0BD804 00000000 */   nop   
.L7F0BD808:
/* 0F2338 7F0BD808 03E00008 */  jr    $ra
/* 0F233C 7F0BD80C 27BD0018 */   addiu $sp, $sp, 0x18
)
#endif

void dynDrawMembars(Gfx *gdl) {
    dynCalculateMembarLength(membars_string2, ((Gfx*)g_GfxBuffers[g_GfxActiveBufferIndex + 1] - gdl), ((Gfx*)g_GfxBuffers[g_GfxActiveBufferIndex + 1] - (Gfx*)g_GfxBuffers[g_GfxActiveBufferIndex]));
    dynCalculateMembarLength(membars_string2, (g_VtxBuffers[g_GfxActiveBufferIndex + 1] - g_GfxMemPos), (g_VtxBuffers[g_GfxActiveBufferIndex + 1] - g_VtxBuffers[g_GfxActiveBufferIndex]));
}
