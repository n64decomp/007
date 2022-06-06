/*====================================================================
 * seq.c
 *
 * Copyright 1993, Silicon Graphics, Inc.
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

#include <libaudio.h>
#include <os_internal.h>
#include <ultraerror.h>
#include "seq.h"


#define IFF_FILE_HDR    0x4d546864	/* 'MThd' */
#define IFF_TRACK_HDR   0x4d54726b	/* 'MTrk' */

static s32 readVarLen(ALSeq *s);
static u8  read8(ALSeq *s);
static s16 read16(ALSeq *s);
static s32 read32(ALSeq *s);


void alSeqNew(ALSeq *seq, u8 *ptr, s32 len)
{
    /*
     * load the seqence pointed to by ptr
     */
    seq->base           = ptr;
    seq->len            = len;
    seq->lastStatus     = 0;
    seq->lastTicks      = 0;
    seq->curPtr         = ptr;
    
    if (read32(seq) != IFF_FILE_HDR) {
#ifdef _DEBUG
        __osError(ERR_ALSEQNOTMIDI, 1, ptr);
#endif        
        return;
    }

    read32(seq);        /* skip the length field */

    if (read16(seq) != 0) {
#ifdef _DEBUG        
        __osError(ERR_ALSEQNOTMIDI0, 1, ptr);
#endif        
        return;
    }

    if (read16(seq) != 1) {
#ifdef _DEBUG        
        __osError(ERR_ALSEQNUMTRACKS, 1, ptr);
#endif        
        return;
    }

    seq->division = read16(seq);
    if (seq->division & 0x8000) {
#ifdef _DEBUG        
        __osError(ERR_ALSEQTIME, 1, ptr);
#endif        
        return;
    }
    
    seq->qnpt = 1.0/(f32)seq->division;

    if (read32(seq) != IFF_TRACK_HDR) {
#ifdef _DEBUG        
        __osError(ERR_ALSEQTRACKHDR, 1, ptr);
#endif        
        return;
    }

    read32(seq);                /* skip the length field */

    seq->trackStart = seq->curPtr;
}


void alSeqNextEvent(ALSeq *seq, ALEvent *event)
{
    u8          status;
    s16         delta;
    s32         len;
    s32         deltaTicks;
    s32         i;

#ifdef _DEBUG
    /* sct 1/17/96 - Warn if curPtr is beyond the end of sequence. */
    if (seq->curPtr >= seq->base + seq->len)
	__osError(ERR_ALSEQOVERRUN, 0);
#endif
    
    deltaTicks = readVarLen(seq);   /* read the delta time */
    seq->lastTicks += deltaTicks;
    status = read8(seq);
    
#if _DEBUG
    /*
     * System exclusives are not supported, so just skip them and read
     * the next event
     */
    if ((status == 0xf0) || (status == 0xf7)) {
        __osError(ERR_ALSEQSYSEX, 0);
        len = readVarLen(seq);
        for (i = 0; i < len; i++) {
            read8(seq);
        }
        alSeqNextEvent(seq,event);
        return;
    }
#endif
    
    if (status == AL_MIDI_Meta) {
        u8 type = read8(seq);
        
        if (type == AL_MIDI_META_TEMPO) {
            event->type = AL_TEMPO_EVT;
            event->msg.tempo.ticks = deltaTicks;
            event->msg.tempo.status = status;
            event->msg.tempo.type = type;
            event->msg.tempo.len  = read8(seq);
            event->msg.tempo.byte1 = read8(seq);
            event->msg.tempo.byte2 = read8(seq);
            event->msg.tempo.byte3 = read8(seq);
        } else if (type == AL_MIDI_META_EOT) {
            event->type = AL_SEQ_END_EVT;
            event->msg.end.ticks  = deltaTicks;
            event->msg.end.status = status;
            event->msg.end.type   = type;
            event->msg.end.len    = read8(seq);
        } else {
#ifdef _DEBUG
            __osError(ERR_ALSEQMETA, 1, type);
            len = readVarLen(seq);
            for (i = 0; i < len; i++) {
                read8(seq);
            }
            alSeqNextEvent(seq,event);
            return;
#endif            
        }

        seq->lastStatus = 0;
        
    } else {
        event->type = AL_SEQ_MIDI_EVT;
        event->msg.midi.ticks = deltaTicks;
        if (status & 0x80) {
            event->msg.midi.status = status;
            event->msg.midi.byte1 = read8(seq);
            seq->lastStatus = status;
        } else {
            /* running status */
            event->msg.midi.status = seq->lastStatus;
            event->msg.midi.byte1 = status;
        }
        
        if (((event->msg.midi.status & 0xf0) != AL_MIDI_ProgramChange) &&
            ((event->msg.midi.status & 0xf0) != AL_MIDI_ChannelPressure)) {
            event->msg.midi.byte2 = read8(seq);
        } else {
            event->msg.midi.byte2 = 0;
        }
    }
}


/*
  Returns the delta time in ticks for the next event in the sequence.
  Assumes that the sequence data pointer is pointing to the delta time.
  
  If the curPtr is at or beyond the end of the sequence, then return FALSE
  to indicate no next event.

  sct 11/6/95
*/
char __alSeqNextDelta (ALSeq *seq, s32 *pDeltaTicks)
{
  u8 *	savedPtr;

  /* sct 1/16/96 - Put in safety check here to make sure we don't read past sequence data. */
  if (seq->curPtr >= seq->base + seq->len)
      return FALSE;

  savedPtr = seq->curPtr;
  *pDeltaTicks = readVarLen(seq);   /* read the delta time */
  seq->curPtr = savedPtr;

  return TRUE;
}  


f32 alSeqTicksToSec(ALSeq *seq, s32 ticks, u32 tempo)
{
    return ((f32) (((f32)(ticks) * (f32)(tempo)) /
                     ((f32)(seq->division) * 1000000.0)));
}

u32 alSeqSecToTicks(ALSeq *seq, f32 sec, u32 tempo)
{
    return (u32)(((sec * 1000000.0) * seq->division) / tempo);
}

void alSeqNewMarker(ALSeq *seq, ALSeqMarker *m, u32 ticks)
{
    ALEvent     evt;
    u8          *savePtr, *lastPtr;
    s32         saveTicks, lastTicks;
    s16         saveStatus, lastStatus;
    
    /* does not check that ticks is within bounds */
    
    if (ticks == 0) { /* common case */
        m->curPtr     = seq->trackStart;
        m->lastStatus = 0;
        m->lastTicks  = 0;
	m->curTicks = 0;
        return;
    } else {
        savePtr     = seq->curPtr;
        saveStatus  = seq->lastStatus;
        saveTicks   = seq->lastTicks;

        seq->curPtr     = seq->trackStart;
        seq->lastStatus = 0;
        seq->lastTicks  = 0;

        do {
            lastPtr    = seq->curPtr;
            lastStatus = seq->lastStatus;
            lastTicks  = seq->lastTicks;
        
            alSeqNextEvent(seq, &evt);
            
            if (evt.type == AL_SEQ_END_EVT)
	    {
		lastPtr    = seq->curPtr;
		lastStatus = seq->lastStatus;
		lastTicks  = seq->lastTicks;
                break;
	    }
            
        } while (seq->lastTicks < ticks);

        m->curPtr     = lastPtr;
        m->lastStatus = lastStatus;
        m->lastTicks  = lastTicks;
	m->curTicks = seq->lastTicks;	/* Used by test loop condition. */
    
        seq->curPtr     = savePtr;
        seq->lastStatus = saveStatus;
        seq->lastTicks  = saveTicks;

    }    
}

s32 alSeqGetTicks(ALSeq *seq)
{
    return seq->lastTicks;
}

void alSeqSetLoc(ALSeq *seq, ALSeqMarker *m)
{
    seq->curPtr     = m->curPtr;
    seq->lastStatus = m->lastStatus;
    seq->lastTicks  = m->lastTicks;
}

void alSeqGetLoc(ALSeq *seq, ALSeqMarker *m)
{
    m->curPtr = seq->curPtr;
    m->lastStatus = seq->lastStatus;
    m->lastTicks = seq->lastTicks;
}

/* non-aligned byte reading routines */
static u8 read8(ALSeq *seq)
{
    return *seq->curPtr++;
}

static s16 read16(ALSeq *seq)
{
    s16 tmp;

    tmp  = *seq->curPtr++ << 8;
    tmp |= *seq->curPtr++;
    
    return tmp;
}

static s32 read32(ALSeq *seq)
{
    s32 tmp;

    tmp  = *seq->curPtr++ << 24;
    tmp |= *seq->curPtr++ << 16;
    tmp |= *seq->curPtr++ <<  8;
    tmp |= *seq->curPtr++;

    return tmp;
}

static s32 readVarLen(ALSeq *seq)
{
    s32 value;
    s32 c;

    c = *seq->curPtr++;
    value = c;
    if ( c & 0x80 ) {
        value &= 0x7f;
        do {
            c = *seq->curPtr++;
            value = (value << 7) + (c & 0x7f);
        } while (c & 0x80);
    }
    return (value);
}










