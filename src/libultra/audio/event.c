/*====================================================================
 * event.c
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
#include <os.h>
#include <ultraerror.h>


void alEvtqNew(ALEventQueue *evtq, ALEventListItem *items, s32 itemCount)
{
    s32 i;
    
    evtq->eventCount     = 0;
    evtq->allocList.next = 0;
    evtq->allocList.prev = 0;
    evtq->freeList.next  = 0;
    evtq->freeList.prev  = 0;

    for (i = 0; i < itemCount; i++) {
        alLink((ALLink *)&items[i], &evtq->freeList);
    }
}

ALMicroTime alEvtqNextEvent(ALEventQueue *evtq, ALEvent *evt) 
{
    ALEventListItem *item;
    ALMicroTime delta;
    OSIntMask mask;

    mask = osSetIntMask(OS_IM_NONE);
    
    item = (ALEventListItem *)evtq->allocList.next;

    if (item)
    {
        alUnlink((ALLink *)item);
        alCopy(&item->evt, evt, sizeof(*evt));
        alLink((ALLink *)item, &evtq->freeList);
	delta = item->delta;
    }
    else
    {
        /* sct 11/28/95 - If we get here, most like we overflowed the event queue */
	/* with non-self-perpetuating events.  Eg. if we filled the evtq with volume */
	/* events, then when the seqp is told to play it will handle all the events */
	/* at once completely emptying out the queue.  At this point this problem */
	/* must be treated as an out of resource error and the evtq should be increased. */
	evt->type = -1;
	delta = 0;	    
    }

    osSetIntMask(mask);
    
    return delta;
}

void alEvtqPostEvent(ALEventQueue *evtq, ALEvent *evt, ALMicroTime delta)
{
    ALEventListItem     *item;
    ALEventListItem     *nextItem;
    ALLink              *node;
    s32                 postAtEnd=0;
    OSIntMask           mask;

    mask = osSetIntMask(OS_IM_NONE);

    item = (ALEventListItem *)evtq->freeList.next;
    if (!item) {
        osSetIntMask(mask);
#ifdef _DEBUG
        __osError(ERR_ALEVENTNOFREE, 0);
#endif        
        return;
    }
    
    alUnlink((ALLink *)item);
    alCopy(evt, &item->evt, sizeof(*evt));

    if (delta == AL_EVTQ_END)
        postAtEnd = -1;
    
    for (node = &evtq->allocList; node != 0; node = node->next) {
        if (!node->next) { /* end of the list */
            if (postAtEnd)
                item->delta = 0;
            else
                item->delta = delta;
            alLink((ALLink *)item, node);
            break;
        } else {
            nextItem = (ALEventListItem *)node->next;

            if (delta < nextItem->delta) {
                item->delta = delta;
                nextItem->delta -= delta;
                    
                alLink((ALLink *)item, node);
                break;
            }
                
            delta -= nextItem->delta;

        }
    }

    osSetIntMask(mask);
    
}

void alEvtqFlush(ALEventQueue *evtq)
{
    ALLink      *thisNode;
    ALLink      *nextNode;
    OSIntMask   mask;

    mask = osSetIntMask(OS_IM_NONE);

    thisNode = evtq->allocList.next;
    while( thisNode != 0 ) {
	nextNode = thisNode->next;
	alUnlink(thisNode);
	alLink(thisNode, &evtq->freeList);
	thisNode = nextNode;
    }
    
    osSetIntMask(mask);
}


/*
  This routine flushes events according their type.
*/
void alEvtqFlushType(ALEventQueue *evtq, s16 type)
{
    ALLink      	*thisNode;
    ALLink      	*nextNode;
    ALEventListItem     *thisItem, *nextItem;
    OSIntMask   	mask;

    mask = osSetIntMask(OS_IM_NONE);

    thisNode = evtq->allocList.next;
    while( thisNode != 0 )
    {
	nextNode = thisNode->next;
	thisItem = (ALEventListItem *)thisNode;
	nextItem = (ALEventListItem *)nextNode;
	if (thisItem->evt.type == type)
	{
	    if (nextItem)
		nextItem->delta += thisItem->delta;
	    alUnlink(thisNode);
	    alLink(thisNode, &evtq->freeList);
	}
	thisNode = nextNode;
    }

    osSetIntMask(mask);
}


#ifdef _DEBUG_INTERNAL
void alEvtqPrintEvtQueue(ALEventQueue *evtq) 
{
    s32 count1 = 0;
    s32 count2 = 0;
    ALLink *node;
    ALEventListItem *item;
    
    /* count free events */
    for (node = evtq->freeList.next; node != 0; node= node->next) {
        count1++;
    }

    PRINTF("----- Allocated Events -----\n");
    for (node = evtq->allocList.next; node != 0; node= node->next) {
        item = (ALEventListItem *)node;
        
        PRINTF("\tdelta: %d\ttype %d\n", item->delta, item->evt.type);
        count2++;
    }
    PRINTF("\n");

    PRINTF("free  events\t %d\n", count1);
    PRINTF("alloc events\t %d\n", count2);
    PRINTF("total events\t %d\n", count1 + count2);
}

char *MidiStatus2Str (char status, char *str);

void
alEvtqPrintAllocEvts(ALEventQueue *evtq) 
{
    ALLink *node;
    ALEventListItem *item;
    ALMicroTime itemTime = 0;
    char str[32];

    PRINTF("----- Allocated Events -----\n");
    for (node = evtq->allocList.next; node != 0; node= node->next)
    {
        item = (ALEventListItem *)node;
        itemTime += item->delta;

        PRINTF("\tdelta: %d\tabs: %d\t", item->delta, itemTime);

	switch (item->evt.type)
	{
	    case AL_NOTE_END_EVT:
	        PRINTF("NOTE_END\tvox: %x\n", item->evt.msg.note.voice);
	    break;

	    case AL_SEQP_MIDI_EVT:
		PRINTF("SEQP_MIDI\t%s\n", MidiStatus2Str(item->evt.msg.midi.status & AL_MIDI_StatusMask, str));
	    break;

	    case AL_SEQP_PRIORITY_EVT:
		PRINTF("SEQP_PRIORITY\n");
	    break;

	    default:
	        PRINTF("type: %d\n", item->evt.type);
	    break;
	}

    }
    PRINTF("\n");

}

char *
MidiStatus2Str (char status, char *str)
{
    switch (status)
    {
        case AL_MIDI_NoteOn:
	    sprintf(str, "note on");
	break;

        case AL_MIDI_NoteOff:
	    sprintf(str, "note off");
	break;

        default:
	    sprintf(str, "status:%d", status);
	break;
    }

    return str;
}

#endif /* _DEBUG_INTERNAL */
