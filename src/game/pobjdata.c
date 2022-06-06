#include <ultra64.h>
#include <bondgame.h>
#include "chrobjdata.h"

//D:800375D0
#include <assets/obseg/prop/propModelFileHeaders.inc.c>

//D:8003A050
#include <assets/embedded/skeletons/props.inc.c>



//D:8003A228                     .globl PitemZ_entries
#include <assets/obseg/prop/propItemModelFileRecord.inc.c>

#if defined(VERSION_EU)
#include <assets/obseg/prop/propExplosionDetailsRecords-eu.inc.c>
#else
//D:8003b224
#include <assets/obseg/prop/propExplosionDetailsRecords.inc.c>
#endif
