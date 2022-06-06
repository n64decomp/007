#ifndef _BONDGAME_H_
#define _BONDGAME_H_
#include <ultra64.h>

extern u32 *_codeSegmentStart;
extern u32 *_codeSegmentEnd;
extern u32 *_codeSegmentRomStart;
extern u32 *_codeSegmentRomEnd;

extern u32 *_csegmentSegmentStart;
extern u32 *_csegmentSegmentEnd;
extern u32 *_cdataSegmentRomStart;
extern u32 *_cdataSegmentRomEnd;

extern u32 *_inflateSegmentVaddrStart;
extern u32 *_inflateSegmentVaddrEnd;
extern u32 *_inflateSegmentRomStart;
extern u32 *_inflateSegmentRomEnd;

extern u32 *_gameSegmentVaddrStart;
extern u32 *_gameSegmentVaddrEnd;
extern u32 *_gameSegmentRomStart;
extern u32 *_gameSegmentRomEnd;


extern u8 sp_boot[];
extern u8 sp_rmon[];
extern u8 sp_idle[];
extern u8 sp_shed[];
extern u8 sp_main[];
extern u8 sp_audi[];
extern u8 sp_debug[];

//#include <bondaicommands.h> // game ai commands actually... this shouldnt be here as they are only needed by setups
#include <bondconstants.h>  // game constants
#include <bondtypes.h>      // game structs and types

#endif
