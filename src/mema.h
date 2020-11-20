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

void memaSwap(s_mem_alloc_entry *a,s_mem_alloc_entry *b);
void memaMerge(s_mem_alloc_entry *a, s_mem_alloc_entry *b);
u32 memaSortMergeEntries(struct s_mem_alloc_table *param_1);
void memaSortMergeAllEntries(void);
s_mem_alloc_entry * memaFindOpening(s_mem_alloc_table *param_1);
void memaAllocRoomBuffer(u32 addr,u32 size);
void memaInitDebugNoticeList(void);
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
