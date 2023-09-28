#include <ultra64.h>
#include "ob.h"
#include <deb.h>
#include <memp.h>
#include <assets/obseg/obseg.h>
#include "decompress.h"
#include "indy_comms.h"
#include "assets/obseg/file_resource_id_enums.h"

//bss
//800888b0

 resource_lookup_data_entry resource_lookup_data_array[OBJ_INDEX_MAX];


// data
//D:80046050
s32 ob_c_debug_notice_list_entry = 0;


#include <assets/obseg/file_resource_table.inc.c>
/* struct fileentry file_resource_table[] = 
   {
       blah;
    };
 */


//D:800482D4
s32 file_entry_max = OBJ_INDEX_END;




void load_resource(u8 *ptrdata, s32 bytes,  fileentry *srcfile,  resource_lookup_data_entry *lookupdata)
{
    u8 *source;
    u8  buffer[0x2100];
    s32 unused;
    

    if (bytes == 0)
    {
        romCopy(ptrdata, srcfile->hw_address, lookupdata->rom_size);
        return;
    }
    source = (ptrdata + bytes) - ((lookupdata->rom_size + 7) & -8);
    if ((u32) (source - ptrdata) < 8U)
    {
        lookupdata->poolRemaining = 0;
    }
    else
    {
#if DEBUG
        char sp54[128];
        u32  stack[2];
#endif

        romCopy(source, srcfile->hw_address, lookupdata->rom_size);
        lookupdata->poolRemaining = decompressdata(source, ptrdata, buffer);;
#if DEBUG
        if (result == 0)
        {
            sprintf(sp54, "DMA-Crash %s %d Ram: %02x%02x%02x%02x%02x%02x%02x%02x", "ob.c", 204, scratch[0], scratch[1], scratch[2], scratch[3], scratch[4], scratch[5], scratch[6], scratch[7]);
            crashSetMessage(sp54);
            CRASH();
        }
#endif

    }
}

void resource_load_from_indy(u8 *ptrdata, s32 bytes,  fileentry *srcfile,  resource_lookup_data_entry *lookupdata)
{
    u8 *pPayload;
    u8 buffer[8448];
    s32 size;
    static const u8 rz_header_1[] = {0x11, 0x72, 0x00, 0x00};
    static const u8 rz_header_2[] = {0x11, 0x72, 0x00, 0x00};

    if (!bytes)
    {
        indycommHostLoadFile(srcfile->filename, ptrdata);
        return;
    }
    indycommHostCheckFileExists(srcfile->filename, &lookupdata->pc_size);
    pPayload = (ptrdata + bytes) - ((lookupdata->pc_size + 7) & -8);
    if ((pPayload - ptrdata) < 8U)
    {
        lookupdata->poolRemaining = 0;
    }
    else
    {
        indycommHostLoadFile(srcfile->filename, pPayload);
        if ((pPayload[0] == rz_header_1[0]) && (pPayload[1] == rz_header_2[1]))
        {
            size = decompressdata(pPayload, ptrdata, &buffer);
        }
        else
        {
            bcopy(pPayload, ptrdata, lookupdata->pc_size);
            size = lookupdata->pc_size;
        }
        lookupdata->poolRemaining = size;
    }
}





#ifdef NONMATCHING
void obInit(void)
{
    s32 i;
 
    debTryAdd(&ob_c_debug_notice_list_entry,"ob_c_debug");
    for (i = file_entry_max-1; i > 1 ; i--)
    {
        s32 size = (file_resource_table[i+1].hw_address - file_resource_table[i].hw_address);
        resource_lookup_data_array[i].rom_size = size;
        resource_lookup_data_array[i].poolRemaining = 0;
        resource_lookup_data_array[i].pc_size = 0;
        resource_lookup_data_array[i].rom_remaining = 0;
    }
}
#else
GLOBAL_ASM(
.rdata
/*D:8005B674*/
glabel aOb_c_debug
/*"ob_c_debug"*/
.word 0x6F625F63, 0x5F646562, 0x75670000
.text
glabel obInit
/* 0F1758 7F0BCC28 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0F175C 7F0BCC2C AFBF0014 */  sw    $ra, 0x14($sp)
/* 0F1760 7F0BCC30 3C048004 */  lui   $a0, %hi(ob_c_debug_notice_list_entry)
/* 0F1764 7F0BCC34 3C058006 */  lui   $a1, %hi(aOb_c_debug)
/* 0F1768 7F0BCC38 24A5B674 */  addiu $a1, %lo(aOb_c_debug) # addiu $a1, $a1, -0x498c
/* 0F176C 7F0BCC3C 0C001398 */  jal   debTryAdd
/* 0F1770 7F0BCC40 24846050 */   addiu $a0, %lo(ob_c_debug_notice_list_entry) # addiu $a0, $a0, 0x6050
/* 0F1774 7F0BCC44 3C038005 */  lui   $v1, %hi(file_entry_max)
/* 0F1778 7F0BCC48 8C6382D4 */  lw    $v1, %lo(file_entry_max)($v1)
/* 0F177C 7F0BCC4C 3C048004 */  lui   $a0, %hi(file_resource_table + 0xC)
/* 0F1780 7F0BCC50 24846060 */  addiu $a0, %lo(file_resource_table + 0xC) # addiu $a0, $a0, 0x6060
/* 0F1784 7F0BCC54 2463FFFF */  addiu $v1, $v1, -1
/* 0F1788 7F0BCC58 28610002 */  slti  $at, $v1, 2
/* 0F178C 7F0BCC5C 14200013 */  bnez  $at, .L7F0BCCAC
/* 0F1790 7F0BCC60 3C028009 */   lui   $v0, %hi(resource_lookup_data_array+0x14)
/* 0F1794 7F0BCC64 00037080 */  sll   $t6, $v1, 2
/* 0F1798 7F0BCC68 01C37021 */  addu  $t6, $t6, $v1
/* 0F179C 7F0BCC6C 3C0F8009 */  lui   $t7, %hi(resource_lookup_data_array) 
/* 0F17A0 7F0BCC70 25EF88B0 */  addiu $t7, %lo(resource_lookup_data_array) # addiu $t7, $t7, -0x7750
/* 0F17A4 7F0BCC74 000E7080 */  sll   $t6, $t6, 2
/* 0F17A8 7F0BCC78 01CF2821 */  addu  $a1, $t6, $t7
/* 0F17AC 7F0BCC7C 244288C4 */  addiu $v0, %lo(resource_lookup_data_array+0x14) # addiu $v0, $v0, -0x773c
.L7F0BCC80:
/* 0F17B0 7F0BCC80 8C980014 */  lw    $t8, 0x14($a0)
/* 0F17B4 7F0BCC84 8C990008 */  lw    $t9, 8($a0)
/* 0F17B8 7F0BCC88 24420014 */  addiu $v0, $v0, 0x14
/* 0F17BC 7F0BCC8C 0045082B */  sltu  $at, $v0, $a1
/* 0F17C0 7F0BCC90 03191823 */  subu  $v1, $t8, $t9
/* 0F17C4 7F0BCC94 2484000C */  addiu $a0, $a0, 0xc
/* 0F17C8 7F0BCC98 AC43FFEC */  sw    $v1, -0x14($v0)
/* 0F17CC 7F0BCC9C AC40FFF0 */  sw    $zero, -0x10($v0)
/* 0F17D0 7F0BCCA0 AC40FFF4 */  sw    $zero, -0xc($v0)
/* 0F17D4 7F0BCCA4 1420FFF6 */  bnez  $at, .L7F0BCC80
/* 0F17D8 7F0BCCA8 AC40FFF8 */   sw    $zero, -8($v0)
.L7F0BCCAC:
/* 0F17DC 7F0BCCAC 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0F17E0 7F0BCCB0 27BD0018 */  addiu $sp, $sp, 0x18
/* 0F17E4 7F0BCCB4 03E00008 */  jr    $ra
/* 0F17E8 7F0BCCB8 00000000 */   nop   
)
#endif


#if !defined(LEFTOVERDEBUG)
/* VERSION_EU */
/* same as below version, shuffled in EU */
void obLoadBGFileBytesAtOffset(u8 *bgname, u8 *target, s32 offset, s32 len)
{
  s32 index;
   fileentry *fileentry;

  index = fileGetIndex(bgname);
  fileentry = &file_resource_table[index];
  
  if (resource_lookup_data_array[index].rom_size != 0)
  {
    //if the size of offset data would exceed file size, loop forever
    if ((resource_lookup_data_array[index].rom_size + 0xF) < (offset + len))
    {
      while (1){};
    }
    romCopy(target, &fileentry->hw_address[offset], len, fileentry);
  }

}
#endif

#if defined(LEFTOVERDEBUG)
/* no VERSION_EU */
void *_fileIndexLoadToBank(s32 index, FILELOADMETHOD param_2, s32 size, u8 bank)
{
    return fileIndexLoadToBank(index, param_2, size, bank);
}
#endif

#if defined(LEFTOVERDEBUG)
/* no VERSION_EU */
void *_fileIndexLoadToAddr(int index, FILELOADMETHOD param_2, u8 *ptrdata, int size)
{
    return fileIndexLoadToAddr(index, param_2, ptrdata, size);
}
#endif

void *_fileNameLoadToBank(char *filename, FILELOADMETHOD loadMethod, s32 size, u8 bank)
{
    return fileIndexLoadToBank(fileGetIndex(filename), loadMethod, size, bank);
}

void * _fileNameLoadToAddr(char *filename, FILELOADMETHOD loadMethod, u8 *ptrdata, s32 size)
{
    return fileIndexLoadToAddr(fileGetIndex(filename), loadMethod, ptrdata, size);
}

#if defined(LEFTOVERDEBUG)
/* no VERSION_EU */
/**
 * 0F18AC 7F0BCD7C
 * loads data stored at an offset of a bg file
 */
void obLoadBGFileBytesAtOffset(u8 *bgname, u8 *target, s32 offset, s32 len)
{
  s32 index;
   fileentry *fileentry;

  index = fileGetIndex(bgname);
  fileentry = &file_resource_table[index];
  
  if (resource_lookup_data_array[index].rom_size != 0)
  {
    //if the size of offset data would exceed file size, loop forever
    if ((resource_lookup_data_array[index].rom_size + 0xF) < (offset + len))
    {
      while (1){};
    }
    romCopy(target, &fileentry->hw_address[offset], len, fileentry);
  }

}
#endif





void *fileIndexLoadToBank(s32 index, FILELOADMETHOD loadMethod, s32 size, u8 bank) //#MATCH https://decomp.me/scratch/uqiBe
{
    resource_lookup_data_entry *info = &resource_lookup_data_array[index];
    s32                         bytes;
    void                       *ptrdata = NULL;

    if (loadMethod == FILELOADMETHOD_EXTRAMEM || loadMethod == FILELOADMETHOD_DEFAULT || loadMethod == 2)
    {
        // bytes = info->poolRemaining;
        if (info->poolRemaining == 0)
        { // verify pool remaining is 0
            info->poolRemaining = mempGetBankSizeLeft(bank);
            // info->poolRemaining = bytes;
        }
        // bytes = info->poolRemaining;
        ptrdata             = mempAllocBytesInBank(info->poolRemaining, bank); // get pointer to allocated space
        info->rom_remaining = info->poolRemaining;

        if (file_resource_table[index].hw_address == 0)
        {
            resource_load_from_indy(ptrdata, info->poolRemaining, &file_resource_table[index], info);
        }
        else
        {
            load_resource(ptrdata, info->poolRemaining, &file_resource_table[index], info);
        }
        if (loadMethod != FILELOADMETHOD_EXTRAMEM)
        {
            // mempRealloc
            mempAddEntryOfSizeToBank(ptrdata, info->poolRemaining, bank);
        }
    }
    else // skipped in PD
    {
        if (info->poolRemaining == 0)
        {
            if (info->rom_size != 0)
            {
                info->poolRemaining = info->rom_size;
            }
            else
            {
                info->poolRemaining = info->pc_size;
            }
        }
        ptrdata             = mempAllocBytesInBank(info->poolRemaining, bank);
        info->rom_remaining = info->poolRemaining;

        if (file_resource_table[index].hw_address == 0)
        {
            resource_load_from_indy(ptrdata, 0, &file_resource_table[index], info);
        }
        else
        {
            load_resource(ptrdata, 0, &file_resource_table[index], info);
        }
        if (size == 0)
        {
            info->loaded_bank = bank;
        }
    }
    return ptrdata;
}





void *fileIndexLoadToAddr(s32 index, FILELOADMETHOD loadMethod, void *ptrdata, s32 bytes) //#match https://decomp.me/scratch/YExRh
{
    resource_lookup_data_entry *info = &resource_lookup_data_array[index];

    if (!info->poolRemaining)
    {
        if (info->rom_size)
        {
            info->poolRemaining = info->rom_size;
        }
        else
        {
            info->poolRemaining = info->pc_size;
        }
    }
    if (loadMethod == FILELOADMETHOD_EXTRAMEM || loadMethod == FILELOADMETHOD_DEFAULT || loadMethod == 2)
    {
        if (!file_resource_table[index].hw_address)
        {
            info->rom_remaining = bytes;
            resource_load_from_indy(ptrdata, bytes, &file_resource_table[index], &resource_lookup_data_array[index]);
        }
        else
        {
            info->rom_remaining = bytes;
            //fix a1/a0 inversion by manual pointer "info"
            load_resource(ptrdata, bytes, &file_resource_table[index], &resource_lookup_data_array[index]);
        }
    }
    else
    {
        if (!file_resource_table[index].hw_address)
        {
            resource_load_from_indy(ptrdata, 0, &file_resource_table[index], &resource_lookup_data_array[index]);
        }
        else
        {
            load_resource(ptrdata, 0, &file_resource_table[index], &resource_lookup_data_array[index]);
        }
    }

    return ptrdata;
}






s32 get_pc_remaining_buffer_for_index(s32 index)
{
    return resource_lookup_data_array[index].poolRemaining;
}


s32 get_rom_remaining_buffer_for_index(s32 index)
{
    return resource_lookup_data_array[index].rom_remaining;
}


void fileSetSize(s32 filenum, u8* ptr, u32 size, s32 reallocate)
{
    resource_lookup_data_array[filenum].poolRemaining = size;
    resource_lookup_data_array[filenum].rom_remaining = size;
    if (reallocate != 0)
    {
        mempAddEntryOfSizeToBank(ptr, resource_lookup_data_array[filenum].poolRemaining, 4U);
    }
}


s32 get_pc_buffer_remaining_value(u8 *name)
{
    int index;
    
    index = fileGetIndex(name);
    return resource_lookup_data_array[index].poolRemaining;
}


void obBlankResourcesLoadedInBank(u8 bank)
{
    int i;
    for (i = 1; i < file_entry_max; i++) {
        if (resource_lookup_data_array[i].loaded_bank <= bank) {
            resource_lookup_data_array[i].loaded_bank = '\0';
        }
        if (bank == 4) {
            resource_lookup_data_array[i].poolRemaining = 0;
        }
    }
}

void obBlankResourcesInBank5(void) {
  obBlankResourcesLoadedInBank(MEMPOOL_ME);
}





#ifdef NONMATCHING
//needs work
int fileGetIndex(u8 *resname)
{
    int i;
    int size;
    //if file exists, return index
    for (i = 1; i < file_entry_max; i++)
    {
        if ((file_resource_table[i].filename) && 
            (strcmp(resname,file_resource_table[i].filename) == 0));
        {
            return i;
        }
    }
    i = file_entry_max;
    //too many files exist
    if (file_entry_max >= OBJ_INDEX_MAX) {
        return 0;
    }
    //we have room, see if on indy and make room
    file_entry_max += 1;
    if (indycommHostCheckFileExists(resname,size) == 0) {
        return 0;
    }
    file_resource_table[i].index = i;
    file_resource_table[i].filename = resname;
    resource_lookup_data_array[i].unk_11 = '\0';
    file_resource_table[i].hw_address = 0;
    resource_lookup_data_array[i].rom_size = 0;
    resource_lookup_data_array[i].poolRemaining = 0;
    resource_lookup_data_array[i].rom_remaining = 0;
    resource_lookup_data_array[i].loaded_bank = '\0';
    resource_lookup_data_array[i].pc_size = (size + 0xf | 0xf) ^ 0xf;
    return i;
}
#else

#if defined(LEFTOVERDEBUG)
GLOBAL_ASM(
.text
glabel fileGetIndex
/* 0F1D84 7F0BD254 27BDFFC0 */  addiu $sp, $sp, -0x40
/* 0F1D88 7F0BD258 AFB2001C */  sw    $s2, 0x1c($sp)
/* 0F1D8C 7F0BD25C 3C128005 */  lui   $s2, %hi(file_entry_max)
/* 0F1D90 7F0BD260 265282D4 */  addiu $s2, %lo(file_entry_max) # addiu $s2, $s2, -0x7d2c
/* 0F1D94 7F0BD264 8E420000 */  lw    $v0, ($s2)
/* 0F1D98 7F0BD268 AFB30020 */  sw    $s3, 0x20($sp)
/* 0F1D9C 7F0BD26C AFB10018 */  sw    $s1, 0x18($sp)
/* 0F1DA0 7F0BD270 28410002 */  slti  $at, $v0, 2
/* 0F1DA4 7F0BD274 00809825 */  move  $s3, $a0
/* 0F1DA8 7F0BD278 AFBF0024 */  sw    $ra, 0x24($sp)
/* 0F1DAC 7F0BD27C AFB00014 */  sw    $s0, 0x14($sp)
/* 0F1DB0 7F0BD280 14200012 */  bnez  $at, .L7F0BD2CC
/* 0F1DB4 7F0BD284 24110001 */   li    $s1, 1
/* 0F1DB8 7F0BD288 3C108004 */  lui   $s0, %hi(file_resource_table + 0xC)
/* 0F1DBC 7F0BD28C 26106060 */  addiu $s0, %lo(file_resource_table + 0xC) # addiu $s0, $s0, 0x6060
/* 0F1DC0 7F0BD290 8E050004 */  lw    $a1, 4($s0)
.L7F0BD294:
/* 0F1DC4 7F0BD294 50A00008 */  beql  $a1, $zero, .L7F0BD2B8
/* 0F1DC8 7F0BD298 8E420000 */   lw    $v0, ($s2)
/* 0F1DCC 7F0BD29C 0C002A13 */  jal   strcmp
/* 0F1DD0 7F0BD2A0 02602025 */   move  $a0, $s3
/* 0F1DD4 7F0BD2A4 54400004 */  bnezl $v0, .L7F0BD2B8
/* 0F1DD8 7F0BD2A8 8E420000 */   lw    $v0, ($s2)
/* 0F1DDC 7F0BD2AC 1000002E */  b     .L7F0BD368
/* 0F1DE0 7F0BD2B0 02201025 */   move  $v0, $s1
/* 0F1DE4 7F0BD2B4 8E420000 */  lw    $v0, ($s2)
.L7F0BD2B8:
/* 0F1DE8 7F0BD2B8 26310001 */  addiu $s1, $s1, 1
/* 0F1DEC 7F0BD2BC 2610000C */  addiu $s0, $s0, 0xc
/* 0F1DF0 7F0BD2C0 0222082A */  slt   $at, $s1, $v0
/* 0F1DF4 7F0BD2C4 5420FFF3 */  bnezl $at, .L7F0BD294
/* 0F1DF8 7F0BD2C8 8E050004 */   lw    $a1, 4($s0)
.L7F0BD2CC:
/* 0F1DFC 7F0BD2CC 284102E0 */  slti  $at, $v0, 0x2e0 /*OBJ_INDEX_MAX*/
/* 0F1E00 7F0BD2D0 14200003 */  bnez  $at, .L7F0BD2E0
/* 0F1E04 7F0BD2D4 00408825 */   move  $s1, $v0
/* 0F1E08 7F0BD2D8 10000023 */  b     .L7F0BD368
/* 0F1E0C 7F0BD2DC 00001025 */   move  $v0, $zero
.L7F0BD2E0:
/* 0F1E10 7F0BD2E0 244E0001 */  addiu $t6, $v0, 1
/* 0F1E14 7F0BD2E4 AE4E0000 */  sw    $t6, ($s2)
/* 0F1E18 7F0BD2E8 02602025 */  move  $a0, $s3
/* 0F1E1C 7F0BD2EC 0FC34026 */  jal   indycommHostCheckFileExists
/* 0F1E20 7F0BD2F0 27A50034 */   addiu $a1, $sp, 0x34
/* 0F1E24 7F0BD2F4 14400003 */  bnez  $v0, .L7F0BD304
/* 0F1E28 7F0BD2F8 00117880 */   sll   $t7, $s1, 2
/* 0F1E2C 7F0BD2FC 1000001A */  b     .L7F0BD368
/* 0F1E30 7F0BD300 00001025 */   move  $v0, $zero
.L7F0BD304:
/* 0F1E34 7F0BD304 01F17823 */  subu  $t7, $t7, $s1
/* 0F1E38 7F0BD308 3C188004 */  lui   $t8, %hi(file_resource_table) 
/* 0F1E3C 7F0BD30C 27186054 */  addiu $t8, %lo(file_resource_table) # addiu $t8, $t8, 0x6054
/* 0F1E40 7F0BD310 000F7880 */  sll   $t7, $t7, 2
/* 0F1E44 7F0BD314 0011C880 */  sll   $t9, $s1, 2
/* 0F1E48 7F0BD318 01F88021 */  addu  $s0, $t7, $t8
/* 0F1E4C 7F0BD31C 0331C821 */  addu  $t9, $t9, $s1
/* 0F1E50 7F0BD320 3C088009 */  lui   $t0, %hi(resource_lookup_data_array) 
/* 0F1E54 7F0BD324 250888B0 */  addiu $t0, %lo(resource_lookup_data_array) # addiu $t0, $t0, -0x7750
/* 0F1E58 7F0BD328 0019C880 */  sll   $t9, $t9, 2
/* 0F1E5C 7F0BD32C AE110000 */  sw    $s1, ($s0)
/* 0F1E60 7F0BD330 AE130004 */  sw    $s3, 4($s0)
/* 0F1E64 7F0BD334 03281821 */  addu  $v1, $t9, $t0
/* 0F1E68 7F0BD338 A0600011 */  sb    $zero, 0x11($v1)
/* 0F1E6C 7F0BD33C AE000008 */  sw    $zero, 8($s0)
/* 0F1E70 7F0BD340 AC600000 */  sw    $zero, ($v1)
/* 0F1E74 7F0BD344 AC600004 */  sw    $zero, 4($v1)
/* 0F1E78 7F0BD348 8FA90034 */  lw    $t1, 0x34($sp)
/* 0F1E7C 7F0BD34C AC60000C */  sw    $zero, 0xc($v1)
/* 0F1E80 7F0BD350 A0600010 */  sb    $zero, 0x10($v1)
/* 0F1E84 7F0BD354 252A000F */  addiu $t2, $t1, 0xf
/* 0F1E88 7F0BD358 354B000F */  ori   $t3, $t2, 0xf
/* 0F1E8C 7F0BD35C 396C000F */  xori  $t4, $t3, 0xf
/* 0F1E90 7F0BD360 AC6C0008 */  sw    $t4, 8($v1)
/* 0F1E94 7F0BD364 02201025 */  move  $v0, $s1
.L7F0BD368:
/* 0F1E98 7F0BD368 8FBF0024 */  lw    $ra, 0x24($sp)
/* 0F1E9C 7F0BD36C 8FB00014 */  lw    $s0, 0x14($sp)
/* 0F1EA0 7F0BD370 8FB10018 */  lw    $s1, 0x18($sp)
/* 0F1EA4 7F0BD374 8FB2001C */  lw    $s2, 0x1c($sp)
/* 0F1EA8 7F0BD378 8FB30020 */  lw    $s3, 0x20($sp)
/* 0F1EAC 7F0BD37C 03E00008 */  jr    $ra
/* 0F1EB0 7F0BD380 27BD0040 */   addiu $sp, $sp, 0x40
)
#endif

#if !defined(LEFTOVERDEBUG)
GLOBAL_ASM(
.text
glabel fileGetIndex
/* 0EEFFC 7F0BC60C 27BDFFC0 */  addiu $sp, $sp, -0x40
/* 0EF000 7F0BC610 AFB2001C */  sw    $s2, 0x1c($sp)
/* 0EF004 7F0BC614 3C128004 */  lui   $s2, %hi(file_entry_max) # $s2, 0x8004
/* 0EF008 7F0BC618 26520F54 */  addiu $s2, %lo(file_entry_max) # addiu $s2, $s2, 0xf54
/* 0EF00C 7F0BC61C 8E420000 */  lw    $v0, ($s2)
/* 0EF010 7F0BC620 AFB30020 */  sw    $s3, 0x20($sp)
/* 0EF014 7F0BC624 AFB10018 */  sw    $s1, 0x18($sp)
/* 0EF018 7F0BC628 28410002 */  slti  $at, $v0, 2
/* 0EF01C 7F0BC62C 00809825 */  move  $s3, $a0
/* 0EF020 7F0BC630 AFBF0024 */  sw    $ra, 0x24($sp)
/* 0EF024 7F0BC634 AFB00014 */  sw    $s0, 0x14($sp)
/* 0EF028 7F0BC638 14200012 */  bnez  $at, .L7F0BC684
/* 0EF02C 7F0BC63C 24110001 */   li    $s1, 1
/* 0EF030 7F0BC640 3C108004 */  lui   $s0, %hi(file_resource_table + 0xC) # $s0, 0x8004
/* 0EF034 7F0BC644 2610EAD0 */  addiu $s0, %lo(file_resource_table + 0xC) # addiu $s0, $s0, -0x1530
/* 0EF038 7F0BC648 8E050004 */  lw    $a1, 4($s0)
.L7F0BC64C:
/* 0EF03C 7F0BC64C 50A00008 */  beql  $a1, $zero, .L7F0BC670
/* 0EF040 7F0BC650 8E420000 */   lw    $v0, ($s2)
/* 0EF044 7F0BC654 0C00272B */  jal   strcmp
/* 0EF048 7F0BC658 02602025 */   move  $a0, $s3
/* 0EF04C 7F0BC65C 54400004 */  bnezl $v0, .L7F0BC670
/* 0EF050 7F0BC660 8E420000 */   lw    $v0, ($s2)
/* 0EF054 7F0BC664 1000002E */  b     .L7F0BC720
/* 0EF058 7F0BC668 02201025 */   move  $v0, $s1
/* 0EF05C 7F0BC66C 8E420000 */  lw    $v0, ($s2)
.L7F0BC670:
/* 0EF060 7F0BC670 26310001 */  addiu $s1, $s1, 1
/* 0EF064 7F0BC674 2610000C */  addiu $s0, $s0, 0xc
/* 0EF068 7F0BC678 0222082A */  slt   $at, $s1, $v0
/* 0EF06C 7F0BC67C 5420FFF3 */  bnezl $at, .L7F0BC64C
/* 0EF070 7F0BC680 8E050004 */   lw    $a1, 4($s0)
.L7F0BC684:
/* 0EF074 7F0BC684 2841030C */  slti  $at, $v0, 0x30c
/* 0EF078 7F0BC688 14200003 */  bnez  $at, .L7F0BC698
/* 0EF07C 7F0BC68C 00408825 */   move  $s1, $v0
/* 0EF080 7F0BC690 10000023 */  b     .L7F0BC720
/* 0EF084 7F0BC694 00001025 */   move  $v0, $zero
.L7F0BC698:
/* 0EF088 7F0BC698 244E0001 */  addiu $t6, $v0, 1
/* 0EF08C 7F0BC69C AE4E0000 */  sw    $t6, ($s2)
/* 0EF090 7F0BC6A0 02602025 */  move  $a0, $s3
/* 0EF094 7F0BC6A4 0FC33D6E */  jal   indycommHostCheckFileExists
/* 0EF098 7F0BC6A8 27A50034 */   addiu $a1, $sp, 0x34
/* 0EF09C 7F0BC6AC 14400003 */  bnez  $v0, .L7F0BC6BC
/* 0EF0A0 7F0BC6B0 00117880 */   sll   $t7, $s1, 2
/* 0EF0A4 7F0BC6B4 1000001A */  b     .L7F0BC720
/* 0EF0A8 7F0BC6B8 00001025 */   move  $v0, $zero
.L7F0BC6BC:
/* 0EF0AC 7F0BC6BC 01F17823 */  subu  $t7, $t7, $s1
/* 0EF0B0 7F0BC6C0 3C188004 */  lui   $t8, %hi(file_resource_table) # $t8, 0x8004
/* 0EF0B4 7F0BC6C4 2718EAC4 */  addiu $t8, %lo(file_resource_table) # addiu $t8, $t8, -0x153c
/* 0EF0B8 7F0BC6C8 000F7880 */  sll   $t7, $t7, 2
/* 0EF0BC 7F0BC6CC 0011C880 */  sll   $t9, $s1, 2
/* 0EF0C0 7F0BC6D0 01F88021 */  addu  $s0, $t7, $t8
/* 0EF0C4 7F0BC6D4 0331C821 */  addu  $t9, $t9, $s1
/* 0EF0C8 7F0BC6D8 3C088007 */  lui   $t0, %hi(resource_lookup_data_array) # $t0, 0x8007
/* 0EF0CC 7F0BC6DC 2508F920 */  addiu $t0, %lo(resource_lookup_data_array) # addiu $t0, $t0, -0x6e0
/* 0EF0D0 7F0BC6E0 0019C880 */  sll   $t9, $t9, 2
/* 0EF0D4 7F0BC6E4 AE110000 */  sw    $s1, ($s0)
/* 0EF0D8 7F0BC6E8 AE130004 */  sw    $s3, 4($s0)
/* 0EF0DC 7F0BC6EC 03281821 */  addu  $v1, $t9, $t0
/* 0EF0E0 7F0BC6F0 A0600011 */  sb    $zero, 0x11($v1)
/* 0EF0E4 7F0BC6F4 AE000008 */  sw    $zero, 8($s0)
/* 0EF0E8 7F0BC6F8 AC600000 */  sw    $zero, ($v1)
/* 0EF0EC 7F0BC6FC AC600004 */  sw    $zero, 4($v1)
/* 0EF0F0 7F0BC700 8FA90034 */  lw    $t1, 0x34($sp)
/* 0EF0F4 7F0BC704 AC60000C */  sw    $zero, 0xc($v1)
/* 0EF0F8 7F0BC708 A0600010 */  sb    $zero, 0x10($v1)
/* 0EF0FC 7F0BC70C 252A000F */  addiu $t2, $t1, 0xf
/* 0EF100 7F0BC710 354B000F */  ori   $t3, $t2, 0xf
/* 0EF104 7F0BC714 396C000F */  xori  $t4, $t3, 0xf
/* 0EF108 7F0BC718 AC6C0008 */  sw    $t4, 8($v1)
/* 0EF10C 7F0BC71C 02201025 */  move  $v0, $s1
.L7F0BC720:
/* 0EF110 7F0BC720 8FBF0024 */  lw    $ra, 0x24($sp)
/* 0EF114 7F0BC724 8FB00014 */  lw    $s0, 0x14($sp)
/* 0EF118 7F0BC728 8FB10018 */  lw    $s1, 0x18($sp)
/* 0EF11C 7F0BC72C 8FB2001C */  lw    $s2, 0x1c($sp)
/* 0EF120 7F0BC730 8FB30020 */  lw    $s3, 0x20($sp)
/* 0EF124 7F0BC734 03E00008 */  jr    $ra
/* 0EF128 7F0BC738 27BD0040 */   addiu $sp, $sp, 0x40
)
#endif
#endif





void removed_handle_filetable_entry(u32 index)
{
    return;
}

void removed_loop_handle_filetable_entries(void)
{
    int i;
    for (i = 1; (i < file_entry_max); i++)
    {
        removed_handle_filetable_entry(i);
    }
}

void removed_loop_filetableentries(void)
{
    int i;
    
    for (i = 1; (i < file_entry_max); i++)
    {
        ;
    }
}






#ifdef NONMATCHING
void sub_GAME_7F0BD410(void)
{
  struct resource_lookup_data_entry *entry= &resource_lookup_data_array[1];
  
    if (file_entry_max > 1) 
    {
        for (;&resource_lookup_data_array[file_entry_max] > entry;entry++)
        {
            ;
        }
    }
}

#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0BD410
/* 0F1F40 7F0BD410 3C038005 */  lui   $v1, %hi(file_entry_max)
/* 0F1F44 7F0BD414 8C6382D4 */  lw    $v1, %lo(file_entry_max)($v1)
/* 0F1F48 7F0BD418 3C028009 */  lui   $v0, %hi(resource_lookup_data_array+0x14)
/* 0F1F4C 7F0BD41C 244288C4 */  addiu $v0, %lo(resource_lookup_data_array+0x14) # addiu $v0, $v0, -0x773c
/* 0F1F50 7F0BD420 28610002 */  slti  $at, $v1, 2
/* 0F1F54 7F0BD424 1420000A */  bnez  $at, .L7F0BD450
/* 0F1F58 7F0BD428 00037080 */   sll   $t6, $v1, 2
/* 0F1F5C 7F0BD42C 01C37021 */  addu  $t6, $t6, $v1
/* 0F1F60 7F0BD430 3C0F8009 */  lui   $t7, %hi(resource_lookup_data_array) 
/* 0F1F64 7F0BD434 25EF88B0 */  addiu $t7, %lo(resource_lookup_data_array) # addiu $t7, $t7, -0x7750
/* 0F1F68 7F0BD438 000E7080 */  sll   $t6, $t6, 2
/* 0F1F6C 7F0BD43C 01CF2021 */  addu  $a0, $t6, $t7
/* 0F1F70 7F0BD440 24420014 */  addiu $v0, $v0, 0x14
.L7F0BD444:
/* 0F1F74 7F0BD444 0044082B */  sltu  $at, $v0, $a0
/* 0F1F78 7F0BD448 5420FFFE */  bnezl $at, .L7F0BD444
/* 0F1F7C 7F0BD44C 24420014 */   addiu $v0, $v0, 0x14
.L7F0BD450:
/* 0F1F80 7F0BD450 03E00008 */  jr    $ra
/* 0F1F84 7F0BD454 00000000 */   nop   
)
#endif


 
