#ifndef _OB_H_
#define _OB_H_
#include <ultra64.h>

typedef struct resource_lookup_data_entry
{
    u32 rom_size;
    u32 poolRemaining;
    u32 pc_size;
    u32 rom_remaining;
    u8  loaded_bank;
    u8  unk_11;
    u16 reserved;
} resource_lookup_data_entry;

typedef struct fileentry
{
    s32   index;
    char *filename;
    u8   *hw_address;
} fileentry;

typedef enum FILELOADMETHOD
{
    FILELOADMETHOD_EXTRAMEM,
    FILELOADMETHOD_DEFAULT,
    FILELOADMETHOD_UNK2
} FILELOADMETHOD;

void  load_resource(u8 *ptrdata, s32 bytes,  fileentry *srcfile,  resource_lookup_data_entry *lookupdata);
void  resource_load_from_indy(u8 *ptrdata, s32 bytes,  fileentry *srcfile,  resource_lookup_data_entry *lookupdata);
void *load_rom_resource_index_to_membank(s32 index, FILELOADMETHOD loadMethod, s32 size, u8 bank);
void *load_resource_index_to_buffer(s32 index, FILELOADMETHOD loadMethod, void *ptrdata, s32 bytes);
void  obBlankResourcesLoadedInBank(u8 i);
void  obBlankResourcesInBank5(void);

#endif
