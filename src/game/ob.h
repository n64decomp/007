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

void  obBlankResourcesLoadedInBank(u8 i);
void  obBlankResourcesInBank5(void);

void *fileIndexLoadToBank(s32 index, FILELOADMETHOD loadMethod, s32 size, u8 bank);
void *fileIndexLoadToAddr(s32 index, FILELOADMETHOD loadMethod, void *ptrdata, s32 bytes);

void *_fileNameLoadToAddr(char *filename, FILELOADMETHOD loadMethod, u8 *ptrdata, s32 size);
void *_fileNameLoadToBank(char *filename, FILELOADMETHOD loadMethod, s32 size, u8 bank);

#if defined(LEFTOVERDEBUG)
void *_fileIndexLoadToAddr(int index, FILELOADMETHOD param_2, u8 *ptrdata, int size);
void *_fileIndexLoadToBank(s32 index, FILELOADMETHOD param_2, s32 size, u8 bank);
#endif

s32 get_pc_buffer_remaining_value(u8 *name);
s32 get_rom_remaining_buffer_for_index(s32 index);
s32 get_pc_remaining_buffer_for_index(s32 index);
s32 fileGetIndex(char *resname);
s32 get_pc_remaining_buffer_for_index(s32 index);

#endif
