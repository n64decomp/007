#ifndef _BONDGAME_H_
#define _BONDGAME_H_
#include <ultra64.h>
//#include <bondaicommands.h> // game ai commands actually... this shouldnt be here as they are only needed by setups
#include <bondconstants.h>  // game constants
#include <bondtypes.h>      // game structs and types

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

extern u32* _alt_startSegmentRomStart;
extern u32* _alt_startSegmentStart;

extern u8 sp_boot[SP_BOOT_SZ];
extern u8 sp_rmon[SP_RMON_SZ];
extern u8 sp_idle[SP_IDLE_SZ];
extern u8 sp_shed[SP_SHED_SZ];
extern u8 sp_main[SP_MAIN_SZ];
extern u8 sp_audi[SP_AUDI_SZ];
extern u8 sp_debug[SP_DEBUG_SZ];



#endif
