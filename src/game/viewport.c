#include <ultra64.h>
#include <memp.h>
#include "bondview.h"
#include <PR/os.h>
#include <PR/gbi.h>
#include <macro.h>
#include "player_2.h"
#include <fr.h>

// bss
s32 z_buffer_width;
s32 z_buffer_height;

// data
s32 z_buffer = 0;

void zbufDeallocate(void) {
    z_buffer = 0;
}

void zbufAllocate(void)
{
    if (resolution != 0)
    {
        z_buffer_width = Z_BUFFER_4_3_WIDTH;
        z_buffer_height = Z_BUFFER_4_3_HEIGHT;
    }
    else
    {
        z_buffer_width = SCREEN_WIDTH;

        if (getPlayerCount() == 1)
        {
            z_buffer_height = SCREEN_HEIGHT;
        }
        else
        {
            z_buffer_height = Z_BUFFER_HEIGHT;
        }
    }

    z_buffer = mempAllocBytesInBank((z_buffer_width * z_buffer_height * 2) + 64, 4);
    z_buffer = ALIGN64_V1(z_buffer);
}

void zbufSetBuffer(s32 buffer, s32 width, s32 height) {
    z_buffer = buffer;
    z_buffer_width = width;
    z_buffer_height = height;
}

Gfx *zbufInit(Gfx *gdl) {
    s32 phi_a3;
    s32 test;
    if (z_buffer == 0) {
        zbufAllocate();
    }
    if (!(get_cur_playernum() < 2) || ((getPlayerCount() == 2) && (get_cur_playernum() == 1))) {
        phi_a3 = SCREEN_WIDTH * SCREEN_HEIGHT;
    } else {
        phi_a3 = 0;
    }
    test = (z_buffer - phi_a3);
    test = test & ~0x3F;
    gDPPipeSync(gdl++);
    gDPSetDepthImage(gdl++, test);
    return gdl;
}

Gfx *zbufClearCurrentPlayer(Gfx *gdl) {
    s32 start_x;
    s32 end_x;
    gDPPipeSync(gdl++);
    gDPSetRenderMode(gdl++, G_RM_NOOP, G_RM_NOOP2);
    gDPSetColorImage(gdl++, G_IM_FMT_RGBA, G_IM_SIZ_16b, z_buffer_width, OS_K0_TO_PHYSICAL(z_buffer));
    gDPSetCycleType(gdl++, G_CYC_FILL);
    gDPSetFillColor(gdl++, (GPACK_ZDZ(G_MAXFBZ, 0) << 16 | GPACK_ZDZ(G_MAXFBZ, 0)));
    gDPSetScissor(gdl++, G_SC_NON_INTERLACE, 0, 0, viGetX(), viGetY());
    if (getPlayerCount() < 3) {
        start_x = 0;
        end_x = viGetX() - 1;
    } else if ((get_cur_playernum() == 0) || (get_cur_playernum() == 2)) {
        start_x = 0;
        end_x = (viGetX() / 2) - 1;
    } else {
        start_x = viGetX() / 2;
        end_x = viGetX() - 1;
    }
    gDPFillRectangle(gdl++, start_x, 0, end_x, (z_buffer_height - 1));
    gDPPipeSync(gdl++);
    return gdl;
}
