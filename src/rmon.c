/*
 * THIS FILE IS AN OS FILE (PR\libultra\rmon\rmonMain.c)
 */
#include <stdarg.h>
#include <ultra64.h>
#include "libultra/libc/xstdio.h"
#include "deb_print.h"
#include "rmon.h" /*<PR/rmon.h>*/



/************************************************************************
Function: rmonMain
Args: none
Type: void
Purpose: This is the main loop of the rmon debugger. It is mostly a protocol
	parser/dispatcher.
************************************************************************/
void rmonMain(void) {
    #ifdef DEBUG
    register int newChars;

    somethingToDo = 0;
    cmdinptr = cmdoutptr = 0;

    __rmonInit();
    __rmonActive = 1;

    /*
     *     Loop forever acquiring commands
     */

    for (state = 0, newChars = 0, inPointer = (char *)inbuffer;;)
    {
        OSMesg work;

        osRecvMesg(&__rmonMQ, &work, OS_MESG_BLOCK);
        somethingToDo |= (u32)work;

        if (somethingToDo & MSG_BREAKPOINT)
        {
            somethingToDo &= ~MSG_BREAKPOINT;
            __rmonHitBreak();
        }

        if (somethingToDo & MSG_SPBREAKPOINT)
        {
            somethingToDo &= ~MSG_SPBREAKPOINT;
            __rmonHitSpBreak();
        }

        if (somethingToDo & MSG_CPUFAULT)
        {
            somethingToDo &= ~MSG_CPUFAULT;
            __rmonHitCpuFault();
        }

        if (somethingToDo & MSG_THREADCREATE)
        {
            Debug("rmon: Thread %d created\n", somethingToDo >> 8);
            somethingToDo &= ~(MSG_THREADCREATE | 0xffffff00);
        }

        if (somethingToDo & MSG_THREADDESTROY)
        {
            Debug("rmon: Thread %d destroyed\n", somethingToDo >> 8);
            somethingToDo &= ~(MSG_THREADDESTROY | 0xffffff00);
        }
    }
#    endif
}

/**
 * rmonIsDisabled
 * returns true if this if rmon is disabled
 */
s32 rmonIsDisabled(void) {
    #if defined(DEBUG)
        return FALSE;
    #else
        return TRUE;
    #endif
}

/**
 * REMOVED
 * rmonStatus
 * returns the status of rmon
 */
s32 rmonStatus(void) {
    #ifdef DEBUG
        //removed
    #else
        return -1;
    #endif

}



/**
 * Removed
 * reimpliment osWriteHost
 * target rmon and usb
*/
void osWriteHost(void * buffer, u32 size)
{
    if (buffer);
	if (size);
}


/**
 * Removed
 * reimpliment osReadHost
 * target rmon and usb
*/
void osReadHost(void * buffer, u32 size)
{
    if (buffer);
	if (size);
}


/**
 * Removed
 * rmon7000CEC8
 * unknown function
 */
void rmon7000CEC8(void) {
    #ifdef DEBUG
        //removed
    #endif
}

/**
 * Removed
 * rmon7000CED0
 * unknown function
 */
void rmon7000CED0(void) {
    #ifdef DEBUG
        //removed
    #endif
}

/**
 * Removed
 * rmon7000CED8
 * unknown function
 */
void rmon7000CED8(void) {
    #ifdef DEBUG
        //removed
    #endif
}



/**
 * Removed
 * rmonPrintf
 */
void rmon7000CEE0(void)
{
}
#if 0 /* rmonPrintf no longer supported !! */
void rmonPrintf(const char *fmt, ...)
{    
        /* print formatted to stdout */
        int     ans;
        va_list ap;

        if (osGetThreadPri(0) < 128)
            __rmonAcquirePrintf();
        va_start(ap, fmt);
        ans = _Printf(&proutPrintf, NULL, fmt, ap);
        va_end(ap);
        rmonFlush();
        if (osGetThreadPri(0) < 128)
            __rmonReleasePrintf();
}
#endif

/*
 * ----------------------------------------------------------------- 
 * This is a new file (PR/libultra/libc/syncprintf.c)
*/


/**
 * Send text to Remote Debugger, GE redirects to screen (deboutWriteChar)
 */
static void *proutSyncPrintf(void *str, const char *buf, size_t n)
{
    u32 sent = 0;

#ifndef _FINALROM
    while (sent < n)
    {
#    ifdef USERDB
        sent += __osRdbSend((u8 *)&buf[sent], n - sent, RDB_TYPE_GtoH_PRINT);
#    endif
        deboutWriteChar(buf[sent++]);
    }    
#endif
    return ((void *)1); /* return a fake pointer so that it's not NULL */
}

/**
 * Print formatted string to Debugger
 */
void osSyncPrintf(const char *fmt, ...)
{
    int     ans;
    va_list args;
    va_start(args, fmt);
    ans = _Printf(&proutSyncPrintf, NULL, fmt, args);
    va_end(args);
}
