#include <ultra64.h>
#include "ejectedcartridges.h"
#include "bondtypes.h"
#include "gun.h"

// Copied from another file. Might need code reorganization to prevent the use of extra externs.
extern s32 dword_CODE_bss_80075DB0;
extern s32 dword_CODE_bss_80075DB4;
extern ALSoundState* dword_CODE_bss_80075DB8[4];

extern u32 cartridges_eject;
extern u32 D_80034CA0;

extern CartridgeModelFileRecord ejected_cartridge[] ;

void init_ejected_cartridges(void) {
    int i = 0;
    dword_CODE_bss_80075DB0 = 0;

    while (i < 4)
    {
        dword_CODE_bss_80075DB8[i] = NULL;
        i++;
    }

    i = 0;
    cartridges_eject = 0;
    D_80034CA0 = 0;

    while (ejected_cartridge[i].header != 0) {
        fileLoad(ejected_cartridge[i].header, ejected_cartridge[i].text);
        i++;
    }
}