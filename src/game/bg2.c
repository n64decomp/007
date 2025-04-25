#include <ultra64.h>
#include <PR/os.h>
#include <PR/gbi.h>
#include <bondconstants.h>
#include <fr.h>
#include <memp.h>
#include "bg.h"
#include "bondview.h"
#include "debugmenu_handler.h"
#include "decompress.h"
#include "fog.h"
#include "lvl.h"
#include "math_ceil.h"
#include "matrixmath.h"
#include "player.h"
#include "explosions.h"
#include "unk_0BC530.h"

// new file, per EU

/**
 * Unreferenced.
*/
void sub_GAME_7F0BA5C0(Gfx *arg0, Gfx *arg1)
{
    Gfx *var_v0;
    Gfx *var_v1;

    var_v0 = arg0;

    while (var_v0 < arg1)
    {
        for (var_v1 = DL_LUT_PRIMARY_ADDFOG; var_v1->words.w0 != 0; var_v1 += 2)
        {
            if ((var_v1->words.w0 == var_v0->words.w0) && (var_v1->words.w1 == var_v0->words.w1))
            {
                *var_v0 = *(var_v1+1);
            }
        }

        var_v0++;
    }
}



void bgLoadFromDynamicCCRMLUT(Gfx *arg0, Gfx *arg1, enum CCRMLUT arg2)
{
    Gfx *var_v0;
    Gfx *var_v1;

    static s32 D_80044DB0 = 0;

    var_v0 = arg0;

    while (((arg1 != NULL) && (var_v0 < arg1)) || ((arg1 == NULL) && (((s8*)var_v0)[0] != (s8)G_ENDDL)))
    {
        for (var_v1 = ptrDynamic_CC_RM_LUT[(s32)arg2]; var_v1->words.w0 != 0; var_v1 += 2)
        {
            if ((var_v1->words.w0 == var_v0->words.w0) && (var_v1->words.w1 == var_v0->words.w1))
            {
                D_80044DB0 += 1;
                
                *var_v0 = *(var_v1+1);
            }
        }

        var_v0++;
    }
}
