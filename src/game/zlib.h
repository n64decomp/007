#ifndef _ZLIB_H_
#define _ZLIB_H_
#include "ultra64.h"

extern u8 *rz_inbuf;
extern u8 *rz_outbuf;
extern u32 rz_inptr;
extern u32 rz_wp;
extern struct huft *rz_hlist;

#endif
