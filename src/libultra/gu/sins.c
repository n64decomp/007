/**************************************************************************
 *									  *
 *		 Copyright (C) 1994, Silicon Graphics, Inc.		  *
 *									  *
 *  These coded instructions, statements, and computer programs  contain  *
 *  unpublished  proprietary  information of Silicon Graphics, Inc., and  *
 *  are protected by Federal copyright law.  They  may  not be disclosed  *
 *  to  third  parties  or copied or duplicated in any form, in whole or  *
 *  in part, without the prior written consent of Silicon Graphics, Inc.  *
 *									  *
 **************************************************************************/

#include "guint.h"

/* ====================================================================
 * ====================================================================
 *
 * Module: sins.c
 * $Revision: 1.2 $
 * $Date: 1995/07/12 17:48:02 $
 * $Author: jeffd $
 * $Source: /disk6/Master/cvsmdev2/PR/libultra/gu/sins.c,v $
 *
 * ====================================================================
 * ====================================================================
 */

/* coefficients for polynomial approximation of sin on +/- pi/2 */

/* ====================================================================
 *
 * FunctionName		sins
 *
 * Description		computes sine of arg
 *
 * ====================================================================
 */

#include "sintable.h"

signed short
sins( unsigned short x )
{
	/* 0 <= x < 0x10000  ==>  0 <= x < 2PI */

	signed short	val;

	x >>= 4; /* Now range 0 <= x < 0x1000 */

	if (x & 0x400) {
		val = sintable[0x3ff - (x & 0x3ff)];
	} else {
		val = sintable[x & 0x3ff];
	}

	if (x & 0x800) {
		return -val;
	} else {
		return val;
	}
}
