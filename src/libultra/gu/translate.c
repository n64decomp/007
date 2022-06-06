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

void guTranslateF(float mf[4][4], float x, float y, float z)
{
	guMtxIdentF(mf);

	mf[3][0] = x;
	mf[3][1] = y;
	mf[3][2] = z;
}

void guTranslate(Mtx *m, float x, float y, float z)
{
	Matrix	mf;

	guTranslateF(mf, x, y, z);

	guMtxF2L(mf, m);
}
