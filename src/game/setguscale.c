#include <ultra64.h>
#include "explosions.h"

void set_gu_scale(void) {
    guScale((Mtx *)&dword_CODE_bss_8007A100, 0.1f, 0.1f, 0.1f);
}

