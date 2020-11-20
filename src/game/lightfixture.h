#ifndef _LIGHTFIXTURE_H_
#define _LIGHTFIXTURE_H_

#include "ultra64.h"

typedef struct s_lightfixture {
    s16 index;
    s16 RESERVED;
    Gfx *ptr_start_pertinent_DL;
    void *ptr_end_pertinent_DL;
} s_lightfixture;

#endif
