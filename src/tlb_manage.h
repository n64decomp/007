#ifndef _TLB_MANAGE_H_
#define _TLB_MANAGE_H_
#include "ultra64.h"

struct s_tlbmanage_table_entry
{
    s32 context_value;
    s32 pagenum;
    s64 RESERVED;
};

struct s_tlbmapping_table_entry
{
    u8 entry0;
    u8 entry1;
};

#endif
