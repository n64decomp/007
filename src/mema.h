#ifndef _MEMA_H_
#define _MEMA_H_

#include "ultra64.h"


typedef struct s_mem_alloc_entry {
    s32 addr;
    s32 size;
} s_mem_alloc_entry;

typedef struct s_mem_alloc_table {
    struct s_mem_alloc_entry entries[0x200];
} s_mem_alloc_table;

extern struct s_mem_alloc_table ptr_table_allocated_mem_blocks;

void memaSwap(u8 *a,u8 *b);
void memaMerge(void *arg0, void *arg1);
u32 memaSortMergeEntries(struct s_mem_alloc_table *param_1);
void memaSortMergeAllEntries(void);
u32 mem_related(s32 arg0);
void memaAllocRoomBuffer(u32 addr,u32 size);
void something_with_mema_c_debug(void);
void mempInitMallocTable(void *ptr_allocmem,u32 size);
void mem_related_calls_sort_merge_entries(void);
s32 mem_related_something_find_first(u32 arg0);
s32 mem_related_something_find_first_0(s32 arg0, u32 arg1);
void mem_related_model_room_buffers_0(u32 addr,u32 size) ;
void mem_related_allocated_table_related(void);
f32 mem_related_something_first_related(void);
void generate_list_alloc_mem(void);
void memaGenerateListsBeforeAfterMerge(void);
void mem_related_something_first_related_0(void *arg0);
u32 mem_related_0(void);
u32 mem_related_1(u32 addr,u32 length,u32 maxsize);


#endif
