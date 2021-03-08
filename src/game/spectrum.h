#ifndef _SPECTRUM_H_
#define _SPECTRUM_H_
#include "ultra64.h"

typedef enum SPECTRUMROMS {
    ROM_SABRE,
    ROM_ATIC,
    ROM_JETPAC,
    ROM_JETMAN,
    ROM_ALIEN8,
    ROM_GUNFRIGHT,
    ROM_UNDER,
    ROM_KNIGHTLORE,
    ROM_PSSST,
    ROM_COOKIE
} SPECTRUMROMS;

extern void init_spectrum_game(u32 game);
extern void run_spectrum_game(void);
extern void spectrum_draw_screen(u32);

#endif
