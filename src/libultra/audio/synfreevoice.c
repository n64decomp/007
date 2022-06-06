/*====================================================================
 * synfreevoice.c
 *
 * Copyright 1995, Silicon Graphics, Inc.
 * All Rights Reserved.
 *
 * This is UNPUBLISHED PROPRIETARY SOURCE CODE of Silicon Graphics,
 * Inc.; the contents of this file may not be disclosed to third
 * parties, copied or duplicated in any form, in whole or in part,
 * without the prior written permission of Silicon Graphics, Inc.
 *
 * RESTRICTED RIGHTS LEGEND:
 * Use, duplication or disclosure by the Government is subject to
 * restrictions as set forth in subdivision (c)(1)(ii) of the Rights
 * in Technical Data and Computer Software clause at DFARS
 * 252.227-7013, and/or in similar or successor clauses in the FAR,
 * DOD or NASA FAR Supplement. Unpublished - rights reserved under the
 * Copyright Laws of the United States.
 *====================================================================*/

#include <ultraerror.h>
#include <os_internal.h>
#include "synthInternals.h"

#include <os.h>

void alSynFreeVoice(ALSynth *drvr, ALVoice *voice)
{
    ALFilter *f;
    ALFreeParam *update;

    if (voice->pvoice) {

        if (voice->pvoice->offset) { /* if voice was stolen */
            update = (ALFreeParam *)__allocParam();
            ALFailIf(update == 0, ERR_ALSYN_NO_UPDATE);

            /*
             * set voice data
             */
            update->delta  = drvr->paramSamples + voice->pvoice->offset;
            update->type   = AL_FILTER_FREE_VOICE;
            update->pvoice = voice->pvoice;

            f = voice->pvoice->channelKnob;
            (*f->setParam)(f, AL_FILTER_ADD_UPDATE, update);
        } else {
            _freePVoice(drvr, voice->pvoice);
        }

        voice->pvoice = 0;

    }
}
