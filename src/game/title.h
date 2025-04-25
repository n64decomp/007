#ifndef _INTRO_LOGOS_H_
#define _INTRO_LOGOS_H_
#include <ultra64.h>

extern s32 barrelDisplayListPtr;
extern Gfx *gunbarrelgfxListPointer;
extern Mtx *matrixBufferRareLogo0;
extern Mtx *matrixBufferGunbarrel0;
extern Mtx *matrixBufferRareLogo1;
extern Mtx *matrixBufferRareLogo2;
extern Mtx *matrixBufferGunbarrel1;
extern Mtx *matrixBufferIntroBackdrop;
extern Mtx *matrixBufferIntroBond;
extern f32 x;
extern f32 y;
extern f32 titleTransitionX;
extern f32 titleTransitionY;
extern s16 word_CODE_bss_80069584;
extern s32 dword_CODE_bss_80069588;
extern s32 dword_CODE_bss_8006958C;
extern s32 virtualaddress;
extern s32 dword_CODE_bss_80069594;

extern u32 D_8002A7D0;

Gfx *sub_GAME_7F007CC8(Gfx *gdl, s32 arg1, struct FolderSelect *arg2, struct FolderSelect *arg3);
#endif
