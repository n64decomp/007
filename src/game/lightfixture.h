#ifndef _LIGHTFIXTURE_H_
#define _LIGHTFIXTURE_H_

#include <ultra64.h>

typedef struct s_lightfixture {
    s16 room_index;
    s16 RESERVED;
    Gfx *ptr_start_pertinent_DL;
    Gfx *ptr_end_pertinent_DL;
} s_lightfixture;

struct s_darkened_light {
    u16 room_index;
    u16 vtx_index;
};

#endif
