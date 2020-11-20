#include "ultra64.h"
#include "bondgame.h"
#include "game/lvl_text.h"

// bss
//CODE.bss:8008C640
s32 ptr_text;
//CODE.bss:8008C644
s32 table_text_pointers;
//8008C648
char dword_CODE_bss_8008C648[0x90];
//CODE.bss:8008C6D8
s32 dword_CODE_bss_8008C6D8;
//CODE.bss:8008C6DC
s32 dword_CODE_bss_8008C6DC;
//CODE.bss:8008C6E0
s32 dword_CODE_bss_8008C6E0;
//CODE.bss:8008C6E4
s32 dword_CODE_bss_8008C6E4;
//CODE.bss:8008C6E8
s32 dword_CODE_bss_8008C6E8;
//CODE.bss:8008C6EC
s32 dword_CODE_bss_8008C6EC;
//CODE.bss:8008C6F0
s32 dword_CODE_bss_8008C6F0;
//CODE.bss:8008C6F4
s32 ptr_j_char_data_buf;
//CODE.bss:8008C6F8
s32 ptr_j_char_registry;


#ifdef VERSION_JP
s32 j_text_trigger = 1;
#else
s32 j_text_trigger = 0;
#endif

void *LnameX_lookuptable[] = {
    NULL, NULL,                    /* Null (unused) */
    "LameE", "LameJ",              /* Library (multi) */
    "LarchE", "LarchJ",            /* Archives */
    "LarkE", "LarkJ",              /* Facility */
    "LashE", "LashJ",              /* Stack (multi) */
    "LaztE", "LaztJ",              /* Aztec */
    "LcatE", "LcatJ",              /* Citadel (multi) */
    "LcaveE", "LcaveJ",            /* Caverns */
    "LarecE", "LarecJ",            /* Control */
    "LcradE", "LcradJ",            /* Cradle */
    "LcrypE", "LcrypJ",            /* Egypt */
    "LdamE", "LdamJ",              /* Dam */
    "LdepoE", "LdepoJ",            /* Depot */
    "LdestE", "LdestJ",            /* Frigate */
    "LdishE", "LdishJ",            /* Temple (multi) */
    "LearE", "LearJ",              /* Ear (unused) */
    "LeldE", "LeldJ",              /* Eld (unused) */
    "LimpE", "LimpJ",              /* Basement (multi) */
    "LjunE", "LjunJ",              /* Jungle */
    "LleeE", "LleeJ",              /* Lee (unused) */
    "LlenE", "LlenJ",              /* Cuba */
    "LlipE", "LlipJ",              /* Lip (unused) */
    "LlueE", "LlueJ",              /* Lue (unused) */
    "LoatE", "LoatJ",              /* Cave (multi) */
    "LpamE", "LpamJ",              /* Pam (unused) */
    "LpeteE", "LpeteJ",            /* Streets */
    "LrefE", "LrefJ",              /* Complex (multi) */
    "LritE", "LritJ",              /* Rit (unused) */
    "LrunE", "LrunJ",              /* Runway */
    "LsevbE", "LsevbJ",            /* Bunker 2 */
    "LsevE", "LsevJ",              /* Bunker 1 */
    "LsevxE", "LsevxJ",            /* Surface 1 */
    "LsevxbE", "LsevxbJ",          /* Surface 2 */
    "LshoE", "LshoJ",              /* Sho (unused) */
    "LsiloE", "LsiloJ",            /* Silo */
    "LstatE", "LstatJ",            /* Statue */
    "LtraE", "LtraJ",              /* Train */
    "LwaxE", "LwaxJ",              /* Wax (unused) */
    "LgunE", "LgunJ",              /* Guns */
    "LtitleE", "LtitleJ",          /* Stage and menu titles */
    "LmpmenuE", "LmpmenuJ",        /* Multi menus */
    "LpropobjE", "LpropobjJ",      /* In-game pickups */
    "LmpweaponsE", "LmpweaponsJ",  /* Multi weapon select */
    "LoptionsE", "LoptionsJ",      /* Solo in-game menus */
    "LmiscE", "LmiscJ"};           /* Cheat options */

LEVELID get_textbank_number_for_stagenum(LEVELID level)
{
    LEVELID return_id;

    switch(level)
    {
        case LEVELID_DAM:
            return_id = LDAM;
            break;
        case LEVELID_FACILITY:
            return_id = LARK;
            break;
        case LEVELID_RUNWAY:
            return_id = LRUN;
            break;
        case LEVELID_SURFACE:
            return_id = LSEVX;
            break;
        case LEVELID_BUNKER1:
            return_id = LSEV;
            break;
        case LEVELID_SILO:
            return_id = LSILO;
            break;
        case LEVELID_FRIGATE:
            return_id = LDEST;
            break;
        case LEVELID_SURFACE2:
            return_id = LSEVXB;
            break;
        case LEVELID_BUNKER2:
            return_id = LSEVB;
            break;
        case LEVELID_STATUE:
            return_id = LSTAT;
            break;
        case LEVELID_ARCHIVES:
            return_id = LARCH;
            break;
        case LEVELID_STREETS:
            return_id = LPETE;
            break;
        case LEVELID_DEPOT:
            return_id = LDEPO;
            break;
        case LEVELID_TRAIN:
            return_id = LTRA;
            break;
        case LEVELID_JUNGLE:
            return_id = LJUN;
            break;
        case LEVELID_CONTROL:
            return_id = LAREC;
            break;
        case LEVELID_CAVERNS:
            return_id = LCAVE;
            break;
        case LEVELID_CRADLE:
            return_id = LCRAD;
            break;
        case LEVELID_AZTEC:
            return_id = LAZT;
            break;
        case LEVELID_EGYPT:
            return_id = LCRYP;
            break;
        case LEVELID_TEMPLE:
            return_id = LDISH;
            break;
        case LEVELID_COMPLEX:
            return_id = LREF;
            break;
        case LEVELID_LIBRARY:
            return_id = LAME;
            break;
        case LEVELID_BASEMENT:
            return_id = LIMP;
            break;
        case LEVELID_STACK:
            return_id = LASH;
            break;
        case LEVELID_CAVES:
            return_id = LOAT;
            break;
        case LEVELID_CUBA:
            return_id = LLEN;
            break;
        default:
        {
            /* infinite loop on invalid text bank */
            while(1) {};
        }
    }

    return return_id;
}


#ifdef NONMATCHING
void init_LnameX(void)

{
    undefined *puVar1;
    u8 **ppuVar2;
    int iVar3;
    
    if (j_text_trigger != 0) {
        ptr_char_data_buf = mempAllocBytesInBank(0x2e80,'\x06');
        ptr_char_registry = mempAllocBytesInBank(0x100,'\x06');
        iVar3 = 0;
        do {
            ptr_char_registry[iVar3] = ptr_char_registry[iVar3] & 0x3f;
            *(ushort *)(ptr_char_registry + iVar3) = *(ushort *)(ptr_char_registry + iVar3) | 0x3fff;
            (ptr_char_registry + iVar3)[2] = (ptr_char_registry + iVar3)[2] & 0x3f;
            *(ushort *)(ptr_char_registry + iVar3 + 2) = *(ushort *)(ptr_char_registry + iVar3 + 2) | 0x3fff;
            (ptr_char_registry + iVar3)[4] = (ptr_char_registry + iVar3)[4] & 0x3f;
            *(ushort *)(ptr_char_registry + iVar3 + 4) = *(ushort *)(ptr_char_registry + iVar3 + 4) | 0x3fff;
            (ptr_char_registry + iVar3)[6] = (ptr_char_registry + iVar3)[6] & 0x3f;
            puVar1 = ptr_char_registry + iVar3;
            iVar3 += 8;
            *(ushort *)(puVar1 + 6) = *(ushort *)(puVar1 + 6) | 0x3fff;
        } while (iVar3 != 0xf8);
    }

    ptr_text = 0;
    ppuVar2 = (u8 **)table_text_pointers;
    do {
        ppuVar2 = ppuVar2 + 4;
        ppuVar2[1] = NULL;
        ppuVar2[2] = NULL;
        ppuVar2[3] = NULL;
        *ppuVar2 = NULL;
        ppuVar2 = ppuVar2;
    } while (ppuVar2 != &ptr_char_data_buf);
    table_text_pointers[37] = _load_resource_named_to_membank((&ptr_LgunX)[j_text_trigger],1,0x100,6);
    table_text_pointers[38] = _load_resource_named_to_membank((&ptr_LtitleX)[j_text_trigger],1,0x100,6);
    table_text_pointers[39] = _load_resource_named_to_membank((&ptr_LmpmenuX)[j_text_trigger],1,0x100,6);
    table_text_pointers[40] = _load_resource_named_to_membank((&ptr_LpropobjX)[j_text_trigger],1,0x100,6);
    table_text_pointers[41] =  _load_resource_named_to_membank((&ptr_LmpweaponsX)[j_text_trigger],1,0x100,6);
    table_text_pointers[42] = _load_resource_named_to_membank((&ptr_LoptionsX)[j_text_trigger],1,0x100,6);
    table_text_pointers[43] = _load_resource_named_to_membank((&ptr_LmiscX)[j_text_trigger],1,0x100,6);
    return;
}
#else
GLOBAL_ASM(
.text
glabel init_LnameX
/* 0F621C 7F0C16EC 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 0F6220 7F0C16F0 AFB20020 */  sw    $s2, 0x20($sp)
/* 0F6224 7F0C16F4 3C128005 */  lui   $s2, %hi(j_text_trigger)
/* 0F6228 7F0C16F8 265284D0 */  addiu $s2, %lo(j_text_trigger) # addiu $s2, $s2, -0x7b30
/* 0F622C 7F0C16FC 8E480000 */  lw    $t0, ($s2)
/* 0F6230 7F0C1700 AFBF0024 */  sw    $ra, 0x24($sp)
/* 0F6234 7F0C1704 AFB1001C */  sw    $s1, 0x1c($sp)
/* 0F6238 7F0C1708 11000039 */  beqz  $t0, .L7F0C17F0
/* 0F623C 7F0C170C AFB00018 */   sw    $s0, 0x18($sp)
/* 0F6240 7F0C1710 24042E80 */  li    $a0, 11904
/* 0F6244 7F0C1714 0C0025C8 */  jal   mempAllocBytesInBank
/* 0F6248 7F0C1718 24050006 */   li    $a1, 6
/* 0F624C 7F0C171C 3C018009 */  lui   $at, %hi(ptr_j_char_data_buf)
/* 0F6250 7F0C1720 AC22C6F4 */  sw    $v0, %lo(ptr_j_char_data_buf)($at)
/* 0F6254 7F0C1724 24040100 */  li    $a0, 256
/* 0F6258 7F0C1728 0C0025C8 */  jal   mempAllocBytesInBank
/* 0F625C 7F0C172C 24050006 */   li    $a1, 6
/* 0F6260 7F0C1730 3C048009 */  lui   $a0, %hi(ptr_j_char_registry)
/* 0F6264 7F0C1734 2484C6F8 */  addiu $a0, %lo(ptr_j_char_registry) # addiu $a0, $a0, -0x3908
/* 0F6268 7F0C1738 AC820000 */  sw    $v0, ($a0)
/* 0F626C 7F0C173C 00001825 */  move  $v1, $zero
/* 0F6270 7F0C1740 240500F8 */  li    $a1, 248
.L7F0C1744:
/* 0F6274 7F0C1744 8C8E0000 */  lw    $t6, ($a0)
/* 0F6278 7F0C1748 01C31021 */  addu  $v0, $t6, $v1
/* 0F627C 7F0C174C 904F0000 */  lbu   $t7, ($v0)
/* 0F6280 7F0C1750 31F8FF3F */  andi  $t8, $t7, 0xff3f
/* 0F6284 7F0C1754 A0580000 */  sb    $t8, ($v0)
/* 0F6288 7F0C1758 8C990000 */  lw    $t9, ($a0)
/* 0F628C 7F0C175C 03231021 */  addu  $v0, $t9, $v1
/* 0F6290 7F0C1760 944A0000 */  lhu   $t2, ($v0)
/* 0F6294 7F0C1764 354B3FFF */  ori   $t3, $t2, 0x3fff
/* 0F6298 7F0C1768 A44B0000 */  sh    $t3, ($v0)
/* 0F629C 7F0C176C 8C8C0000 */  lw    $t4, ($a0)
/* 0F62A0 7F0C1770 01831021 */  addu  $v0, $t4, $v1
/* 0F62A4 7F0C1774 904D0002 */  lbu   $t5, 2($v0)
/* 0F62A8 7F0C1778 31AEFF3F */  andi  $t6, $t5, 0xff3f
/* 0F62AC 7F0C177C A04E0002 */  sb    $t6, 2($v0)
/* 0F62B0 7F0C1780 8C8F0000 */  lw    $t7, ($a0)
/* 0F62B4 7F0C1784 01E31021 */  addu  $v0, $t7, $v1
/* 0F62B8 7F0C1788 94590002 */  lhu   $t9, 2($v0)
/* 0F62BC 7F0C178C 37293FFF */  ori   $t1, $t9, 0x3fff
/* 0F62C0 7F0C1790 A4490002 */  sh    $t1, 2($v0)
/* 0F62C4 7F0C1794 8C8A0000 */  lw    $t2, ($a0)
/* 0F62C8 7F0C1798 01431021 */  addu  $v0, $t2, $v1
/* 0F62CC 7F0C179C 904B0004 */  lbu   $t3, 4($v0)
/* 0F62D0 7F0C17A0 316CFF3F */  andi  $t4, $t3, 0xff3f
/* 0F62D4 7F0C17A4 A04C0004 */  sb    $t4, 4($v0)
/* 0F62D8 7F0C17A8 8C8D0000 */  lw    $t5, ($a0)
/* 0F62DC 7F0C17AC 01A31021 */  addu  $v0, $t5, $v1
/* 0F62E0 7F0C17B0 944F0004 */  lhu   $t7, 4($v0)
/* 0F62E4 7F0C17B4 35F83FFF */  ori   $t8, $t7, 0x3fff
/* 0F62E8 7F0C17B8 A4580004 */  sh    $t8, 4($v0)
/* 0F62EC 7F0C17BC 8C990000 */  lw    $t9, ($a0)
/* 0F62F0 7F0C17C0 03231021 */  addu  $v0, $t9, $v1
/* 0F62F4 7F0C17C4 90490006 */  lbu   $t1, 6($v0)
/* 0F62F8 7F0C17C8 312AFF3F */  andi  $t2, $t1, 0xff3f
/* 0F62FC 7F0C17CC A04A0006 */  sb    $t2, 6($v0)
/* 0F6300 7F0C17D0 8C8B0000 */  lw    $t3, ($a0)
/* 0F6304 7F0C17D4 01631021 */  addu  $v0, $t3, $v1
/* 0F6308 7F0C17D8 944D0006 */  lhu   $t5, 6($v0)
/* 0F630C 7F0C17DC 24630008 */  addiu $v1, $v1, 8
/* 0F6310 7F0C17E0 35AE3FFF */  ori   $t6, $t5, 0x3fff
/* 0F6314 7F0C17E4 1465FFD7 */  bne   $v1, $a1, .L7F0C1744
/* 0F6318 7F0C17E8 A44E0006 */   sh    $t6, 6($v0)
/* 0F631C 7F0C17EC 8E480000 */  lw    $t0, ($s2)
.L7F0C17F0:
/* 0F6320 7F0C17F0 3C018009 */  lui   $at, %hi(ptr_text)
/* 0F6324 7F0C17F4 3C028009 */  lui   $v0, %hi(table_text_pointers)
/* 0F6328 7F0C17F8 3C038009 */  lui   $v1, %hi(ptr_j_char_data_buf)
/* 0F632C 7F0C17FC 2463C6F4 */  addiu $v1, %lo(ptr_j_char_data_buf) # addiu $v1, $v1, -0x390c
/* 0F6330 7F0C1800 2442C644 */  addiu $v0, %lo(table_text_pointers) # addiu $v0, $v0, -0x39bc
/* 0F6334 7F0C1804 AC20C640 */  sw    $zero, %lo(ptr_text)($at)
.L7F0C1808:
/* 0F6338 7F0C1808 24420010 */  addiu $v0, $v0, 0x10
/* 0F633C 7F0C180C AC40FFF4 */  sw    $zero, -0xc($v0)
/* 0F6340 7F0C1810 AC40FFF8 */  sw    $zero, -8($v0)
/* 0F6344 7F0C1814 AC40FFFC */  sw    $zero, -4($v0)
/* 0F6348 7F0C1818 1443FFFB */  bne   $v0, $v1, .L7F0C1808
/* 0F634C 7F0C181C AC40FFF0 */   sw    $zero, -0x10($v0)
/* 0F6350 7F0C1820 3C108005 */  lui   $s0, %hi(LnameX_lookuptable)
/* 0F6354 7F0C1824 261084D4 */  addiu $s0, %lo(LnameX_lookuptable) # addiu $s0, $s0, -0x7b2c
/* 0F6358 7F0C1828 00087880 */  sll   $t7, $t0, 2
/* 0F635C 7F0C182C 020FC021 */  addu  $t8, $s0, $t7
/* 0F6360 7F0C1830 8F040130 */  lw    $a0, 0x130($t8)
/* 0F6364 7F0C1834 24050001 */  li    $a1, 1
/* 0F6368 7F0C1838 24060100 */  li    $a2, 256
/* 0F636C 7F0C183C 0FC2F341 */  jal   _load_resource_named_to_membank
/* 0F6370 7F0C1840 24070006 */   li    $a3, 6
/* 0F6374 7F0C1844 8E590000 */  lw    $t9, ($s2)
/* 0F6378 7F0C1848 3C118009 */  lui   $s1, %hi(ptr_text)
/* 0F637C 7F0C184C 2631C640 */  addiu $s1, %lo(ptr_text) # addiu $s1, $s1, -0x39c0
/* 0F6380 7F0C1850 00194880 */  sll   $t1, $t9, 2
/* 0F6384 7F0C1854 02095021 */  addu  $t2, $s0, $t1
/* 0F6388 7F0C1858 AE220098 */  sw    $v0, 0x98($s1)
/* 0F638C 7F0C185C 8D440138 */  lw    $a0, 0x138($t2)
/* 0F6390 7F0C1860 24050001 */  li    $a1, 1
/* 0F6394 7F0C1864 24060100 */  li    $a2, 256
/* 0F6398 7F0C1868 0FC2F341 */  jal   _load_resource_named_to_membank
/* 0F639C 7F0C186C 24070006 */   li    $a3, 6
/* 0F63A0 7F0C1870 8E4B0000 */  lw    $t3, ($s2)
/* 0F63A4 7F0C1874 AE22009C */  sw    $v0, 0x9c($s1)
/* 0F63A8 7F0C1878 24050001 */  li    $a1, 1
/* 0F63AC 7F0C187C 000B6080 */  sll   $t4, $t3, 2
/* 0F63B0 7F0C1880 020C6821 */  addu  $t5, $s0, $t4
/* 0F63B4 7F0C1884 8DA40140 */  lw    $a0, 0x140($t5)
/* 0F63B8 7F0C1888 24060100 */  li    $a2, 256
/* 0F63BC 7F0C188C 0FC2F341 */  jal   _load_resource_named_to_membank
/* 0F63C0 7F0C1890 24070006 */   li    $a3, 6
/* 0F63C4 7F0C1894 8E4E0000 */  lw    $t6, ($s2)
/* 0F63C8 7F0C1898 AE2200A0 */  sw    $v0, 0xa0($s1)
/* 0F63CC 7F0C189C 24050001 */  li    $a1, 1
/* 0F63D0 7F0C18A0 000E7880 */  sll   $t7, $t6, 2
/* 0F63D4 7F0C18A4 020FC021 */  addu  $t8, $s0, $t7
/* 0F63D8 7F0C18A8 8F040148 */  lw    $a0, 0x148($t8)
/* 0F63DC 7F0C18AC 24060100 */  li    $a2, 256
/* 0F63E0 7F0C18B0 0FC2F341 */  jal   _load_resource_named_to_membank
/* 0F63E4 7F0C18B4 24070006 */   li    $a3, 6
/* 0F63E8 7F0C18B8 8E590000 */  lw    $t9, ($s2)
/* 0F63EC 7F0C18BC AE2200A4 */  sw    $v0, 0xa4($s1)
/* 0F63F0 7F0C18C0 24050001 */  li    $a1, 1
/* 0F63F4 7F0C18C4 00194880 */  sll   $t1, $t9, 2
/* 0F63F8 7F0C18C8 02095021 */  addu  $t2, $s0, $t1
/* 0F63FC 7F0C18CC 8D440150 */  lw    $a0, 0x150($t2)
/* 0F6400 7F0C18D0 24060100 */  li    $a2, 256
/* 0F6404 7F0C18D4 0FC2F341 */  jal   _load_resource_named_to_membank
/* 0F6408 7F0C18D8 24070006 */   li    $a3, 6
/* 0F640C 7F0C18DC 8E4B0000 */  lw    $t3, ($s2)
/* 0F6410 7F0C18E0 AE2200A8 */  sw    $v0, 0xa8($s1)
/* 0F6414 7F0C18E4 24050001 */  li    $a1, 1
/* 0F6418 7F0C18E8 000B6080 */  sll   $t4, $t3, 2
/* 0F641C 7F0C18EC 020C6821 */  addu  $t5, $s0, $t4
/* 0F6420 7F0C18F0 8DA40158 */  lw    $a0, 0x158($t5)
/* 0F6424 7F0C18F4 24060100 */  li    $a2, 256
/* 0F6428 7F0C18F8 0FC2F341 */  jal   _load_resource_named_to_membank
/* 0F642C 7F0C18FC 24070006 */   li    $a3, 6
/* 0F6430 7F0C1900 8E4E0000 */  lw    $t6, ($s2)
/* 0F6434 7F0C1904 AE2200AC */  sw    $v0, 0xac($s1)
/* 0F6438 7F0C1908 24050001 */  li    $a1, 1
/* 0F643C 7F0C190C 000E7880 */  sll   $t7, $t6, 2
/* 0F6440 7F0C1910 020FC021 */  addu  $t8, $s0, $t7
/* 0F6444 7F0C1914 8F040160 */  lw    $a0, 0x160($t8)
/* 0F6448 7F0C1918 24060100 */  li    $a2, 256
/* 0F644C 7F0C191C 0FC2F341 */  jal   _load_resource_named_to_membank
/* 0F6450 7F0C1920 24070006 */   li    $a3, 6
/* 0F6454 7F0C1924 8FBF0024 */  lw    $ra, 0x24($sp)
/* 0F6458 7F0C1928 AE2200B0 */  sw    $v0, 0xb0($s1)
/* 0F645C 7F0C192C 8FB1001C */  lw    $s1, 0x1c($sp)
/* 0F6460 7F0C1930 8FB00018 */  lw    $s0, 0x18($sp)
/* 0F6464 7F0C1934 8FB20020 */  lw    $s2, 0x20($sp)
/* 0F6468 7F0C1938 03E00008 */  jr    $ra
/* 0F646C 7F0C193C 27BD0028 */   addiu $sp, $sp, 0x28
)
#endif





#ifdef NONMATCHING
void something_with_LnameJ(void)
{
    ushort uVar1;
    ushort *puVar2;
    int iVar3;
    
    iVar3 = 0;
    if (j_text_trigger != 0) {
        do {
            puVar2 = (ushort *)(ptr_char_registry + iVar3);
            if (*puVar2 >> 0xe == 0) {
                uVar1 = puVar2[1];
            }
            else {
                *(byte *)puVar2 = ((byte)(*puVar2 >> 0xe) - 1) * '@' | *(byte *)puVar2 & 0x3f;
                puVar2 = (ushort *)(ptr_char_registry + iVar3);
                uVar1 = puVar2[1];
            }
            if (uVar1 >> 0xe == 0) {
                uVar1 = puVar2[2];
            }
            else {
                *(byte *)(puVar2 + 1) =
                     ((byte)(uVar1 >> 0xe) - 1) * '@' | *(byte *)(puVar2 + 1) & 0x3f;
                puVar2 = (ushort *)(ptr_char_registry + iVar3);
                uVar1 = puVar2[2];
            }
            if (uVar1 >> 0xe == 0) {
                uVar1 = puVar2[3];
            }
            else {
                *(byte *)(puVar2 + 2) =
                     ((byte)(uVar1 >> 0xe) - 1) * '@' | *(byte *)(puVar2 + 2) & 0x3f;
                puVar2 = (ushort *)(ptr_char_registry + iVar3);
                uVar1 = puVar2[3];
            }
            iVar3 += 8;
            if (uVar1 >> 0xe != 0) {
                *(byte *)(puVar2 + 3) =
                     ((byte)(uVar1 >> 0xe) - 1) * '@' | *(byte *)(puVar2 + 3) & 0x3f;
            }
        } while (iVar3 != 0xf8);
    }
    return;
}
#else
GLOBAL_ASM(
.text
glabel something_with_LnameJ
/* 0F6470 7F0C1940 3C0E8005 */  lui   $t6, %hi(j_text_trigger) 
/* 0F6474 7F0C1944 8DCE84D0 */  lw    $t6, %lo(j_text_trigger)($t6)
/* 0F6478 7F0C1948 00001825 */  move  $v1, $zero
/* 0F647C 7F0C194C 240600F8 */  li    $a2, 248
/* 0F6480 7F0C1950 11C00035 */  beqz  $t6, .L7F0C1A28
/* 0F6484 7F0C1954 3C058009 */   lui   $a1, %hi(ptr_j_char_registry)
/* 0F6488 7F0C1958 24A5C6F8 */  addiu $a1, %lo(ptr_j_char_registry) # addiu $a1, $a1, -0x3908
/* 0F648C 7F0C195C 8CAF0000 */  lw    $t7, ($a1)
.L7F0C1960:
/* 0F6490 7F0C1960 01E31021 */  addu  $v0, $t7, $v1
/* 0F6494 7F0C1964 94440000 */  lhu   $a0, ($v0)
/* 0F6498 7F0C1968 0004C382 */  srl   $t8, $a0, 0xe
/* 0F649C 7F0C196C 5300000A */  beql  $t8, $zero, .L7F0C1998
/* 0F64A0 7F0C1970 94440002 */   lhu   $a0, 2($v0)
/* 0F64A4 7F0C1974 904A0000 */  lbu   $t2, ($v0)
/* 0F64A8 7F0C1978 2719FFFF */  addiu $t9, $t8, -1
/* 0F64AC 7F0C197C 00194980 */  sll   $t1, $t9, 6
/* 0F64B0 7F0C1980 314BFF3F */  andi  $t3, $t2, 0xff3f
/* 0F64B4 7F0C1984 012B6025 */  or    $t4, $t1, $t3
/* 0F64B8 7F0C1988 A04C0000 */  sb    $t4, ($v0)
/* 0F64BC 7F0C198C 8CAD0000 */  lw    $t5, ($a1)
/* 0F64C0 7F0C1990 01A31021 */  addu  $v0, $t5, $v1
/* 0F64C4 7F0C1994 94440002 */  lhu   $a0, 2($v0)
.L7F0C1998:
/* 0F64C8 7F0C1998 00047382 */  srl   $t6, $a0, 0xe
/* 0F64CC 7F0C199C 51C0000A */  beql  $t6, $zero, .L7F0C19C8
/* 0F64D0 7F0C19A0 94440004 */   lhu   $a0, 4($v0)
/* 0F64D4 7F0C19A4 90480002 */  lbu   $t0, 2($v0)
/* 0F64D8 7F0C19A8 25CFFFFF */  addiu $t7, $t6, -1
/* 0F64DC 7F0C19AC 000FC980 */  sll   $t9, $t7, 6
/* 0F64E0 7F0C19B0 310AFF3F */  andi  $t2, $t0, 0xff3f
/* 0F64E4 7F0C19B4 032A4825 */  or    $t1, $t9, $t2
/* 0F64E8 7F0C19B8 A0490002 */  sb    $t1, 2($v0)
/* 0F64EC 7F0C19BC 8CAB0000 */  lw    $t3, ($a1)
/* 0F64F0 7F0C19C0 01631021 */  addu  $v0, $t3, $v1
/* 0F64F4 7F0C19C4 94440004 */  lhu   $a0, 4($v0)
.L7F0C19C8:
/* 0F64F8 7F0C19C8 00046382 */  srl   $t4, $a0, 0xe
/* 0F64FC 7F0C19CC 5180000A */  beql  $t4, $zero, .L7F0C19F8
/* 0F6500 7F0C19D0 94440006 */   lhu   $a0, 6($v0)
/* 0F6504 7F0C19D4 90580004 */  lbu   $t8, 4($v0)
/* 0F6508 7F0C19D8 258DFFFF */  addiu $t5, $t4, -1
/* 0F650C 7F0C19DC 000D7980 */  sll   $t7, $t5, 6
/* 0F6510 7F0C19E0 3308FF3F */  andi  $t0, $t8, 0xff3f
/* 0F6514 7F0C19E4 01E8C825 */  or    $t9, $t7, $t0
/* 0F6518 7F0C19E8 A0590004 */  sb    $t9, 4($v0)
/* 0F651C 7F0C19EC 8CAA0000 */  lw    $t2, ($a1)
/* 0F6520 7F0C19F0 01431021 */  addu  $v0, $t2, $v1
/* 0F6524 7F0C19F4 94440006 */  lhu   $a0, 6($v0)
.L7F0C19F8:
/* 0F6528 7F0C19F8 24630008 */  addiu $v1, $v1, 8
/* 0F652C 7F0C19FC 00044B82 */  srl   $t1, $a0, 0xe
/* 0F6530 7F0C1A00 11200007 */  beqz  $t1, .L7F0C1A20
/* 0F6534 7F0C1A04 00000000 */   nop   
/* 0F6538 7F0C1A08 904E0006 */  lbu   $t6, 6($v0)
/* 0F653C 7F0C1A0C 252BFFFF */  addiu $t3, $t1, -1
/* 0F6540 7F0C1A10 000B6980 */  sll   $t5, $t3, 6
/* 0F6544 7F0C1A14 31D8FF3F */  andi  $t8, $t6, 0xff3f
/* 0F6548 7F0C1A18 01B87825 */  or    $t7, $t5, $t8
/* 0F654C 7F0C1A1C A04F0006 */  sb    $t7, 6($v0)
.L7F0C1A20:
/* 0F6550 7F0C1A20 5466FFCF */  bnel  $v1, $a2, .L7F0C1960
/* 0F6554 7F0C1A24 8CAF0000 */   lw    $t7, ($a1)
.L7F0C1A28:
/* 0F6558 7F0C1A28 03E00008 */  jr    $ra
/* 0F655C 7F0C1A2C 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
int something_with_LnameX(uint param_1)
{
    bool bVar1;
    ushort uVar3;
    u8 *puVar2;
    int iVar4;
    ushort *puVar5;
    int iVar6;
    int iVar7;
    int indexto;
    int iVar8;
    int iVar9;
    int indexfrom;
    
    indexto = -1;
    bVar1 = (param_1 & 0x2000) != 0;
    iVar7 = 0;
    iVar4 = 0;
    iVar9 = -1;
    puVar5 = (ushort *)ptr_char_registry;
    do {
        indexfrom = (int)param_1 >> 1;
        if ((!bVar1) && ((longlong)indexfrom == ((ulonglong)*puVar5 & 0x3fff))) break;
        if ((bVar1) &&
           (((iVar4 + 1 < 0x7c && ((longlong)indexfrom == ((ulonglong)*puVar5 & 0x3fff))) &&
            ((longlong)indexfrom == ((ulonglong)puVar5[1] & 0x3fff))))) break;
        uVar3 = *puVar5 >> 0xe;
        iVar6 = iVar4 + 1;
        if (uVar3 == 0) {
            indexto = iVar4;
        }
        iVar7 += 2;
        iVar8 = iVar9;
        if (((uVar3 == 0) && (puVar5[1] >> 0xe == 0)) && (iVar8 = iVar4, 0x7b < iVar6)) {
            iVar8 = iVar9;
        }
        puVar5 = puVar5 + 1;
        iVar4 = iVar6;
        iVar9 = iVar8;
    } while (iVar6 != 0x7c);
    if (iVar4 < 0x7c) {
        if (bVar1) {
            *(byte *)puVar5 = *(byte *)puVar5 & 0x3f | 0x80;
            (ptr_char_registry + iVar7)[2] = (ptr_char_registry + iVar7)[2] & 0x3f | 0x80;
            puVar2 = ptr_char_data_buf + iVar4 * 0x60;
        }
        else {
            *(byte *)puVar5 = *(byte *)puVar5 & 0x3f | 0x80;
            puVar2 = ptr_char_data_buf + iVar4 * 0x60;
        }
    }
    else {
        if ((bVar1) || (indexto < 0)) {
            puVar2 = ptr_char_data_buf;
            if ((bVar1) && (iVar4 = iVar9 * 2, -1 < iVar9)) {
                ptr_char_registry[iVar4] = ptr_char_registry[iVar4] & 0x3f | 0x80;
                (ptr_char_registry + iVar4)[2] = (ptr_char_registry + iVar4)[2] & 0x3f | 0x80;
                uVar3 = (ushort)indexfrom & 0x3fff;
                *(ushort *)(ptr_char_registry + iVar4) =
                     uVar3 | *(ushort *)(ptr_char_registry + iVar4) & 0xc000;
                *(ushort *)(ptr_char_registry + iVar4 + 2) =
                     uVar3 | *(ushort *)(ptr_char_registry + iVar4 + 2) & 0xc000;
                romCopy((char *)(ptr_char_data_buf + iVar9 * 0x60),
                        (char *)(_efontcharSegmentStart + ((int)(param_1 & 0x1fff) >> 1) * 0x20),
                        0x80);
                puVar2 = ptr_char_data_buf + iVar9 * 0x60;
            }
        }
        else {
            ptr_char_registry[indexto * 2] = ptr_char_registry[indexto * 2] & 0x3f | 0x80;
            *(ushort *)(ptr_char_registry + indexto * 2) =
                 (ushort)indexfrom & 0x3fff | *(ushort *)(ptr_char_registry + indexto * 2) & 0xc000;
            romCopy((char *)(ptr_char_data_buf + indexto * 0x60),
                    (char *)(_jfontcharSegmentStart + indexfrom * 0x18),0x60);
            puVar2 = ptr_char_data_buf + indexto * 0x60;
        }
    }
    return (int)puVar2;
}
#else
GLOBAL_ASM(
.text
glabel something_with_LnameX
/* 0F6560 7F0C1A30 27BDFFC8 */  addiu $sp, $sp, -0x38
/* 0F6564 7F0C1A34 AFB00018 */  sw    $s0, 0x18($sp)
/* 0F6568 7F0C1A38 308E2000 */  andi  $t6, $a0, 0x2000
/* 0F656C 7F0C1A3C 00808025 */  move  $s0, $a0
/* 0F6570 7F0C1A40 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0F6574 7F0C1A44 240AFFFF */  li    $t2, -1
/* 0F6578 7F0C1A48 240BFFFF */  li    $t3, -1
/* 0F657C 7F0C1A4C 11C00002 */  beqz  $t6, .L7F0C1A58
/* 0F6580 7F0C1A50 00004025 */   move  $t0, $zero
/* 0F6584 7F0C1A54 24080001 */  li    $t0, 1
.L7F0C1A58:
/* 0F6588 7F0C1A58 3C0C8009 */  lui   $t4, %hi(ptr_j_char_registry) 
/* 0F658C 7F0C1A5C 8D8CC6F8 */  lw    $t4, %lo(ptr_j_char_registry)($t4)
/* 0F6590 7F0C1A60 00002825 */  move  $a1, $zero
/* 0F6594 7F0C1A64 00003825 */  move  $a3, $zero
/* 0F6598 7F0C1A68 2409007C */  li    $t1, 124
/* 0F659C 7F0C1A6C 01802025 */  move  $a0, $t4
.L7F0C1A70:
/* 0F65A0 7F0C1A70 15000006 */  bnez  $t0, .L7F0C1A8C
/* 0F65A4 7F0C1A74 00000000 */   nop   
/* 0F65A8 7F0C1A78 94980000 */  lhu   $t8, ($a0)
/* 0F65AC 7F0C1A7C 00107843 */  sra   $t7, $s0, 1
/* 0F65B0 7F0C1A80 33193FFF */  andi  $t9, $t8, 0x3fff
/* 0F65B4 7F0C1A84 51F9001F */  beql  $t7, $t9, .L7F0C1B04
/* 0F65B8 7F0C1A88 28A1007C */   slti  $at, $a1, 0x7c
.L7F0C1A8C:
/* 0F65BC 7F0C1A8C 1100000B */  beqz  $t0, .L7F0C1ABC
/* 0F65C0 7F0C1A90 94830000 */   lhu   $v1, ($a0)
/* 0F65C4 7F0C1A94 24AE0001 */  addiu $t6, $a1, 1
/* 0F65C8 7F0C1A98 29C1007C */  slti  $at, $t6, 0x7c
/* 0F65CC 7F0C1A9C 10200007 */  beqz  $at, .L7F0C1ABC
/* 0F65D0 7F0C1AA0 00101043 */   sra   $v0, $s0, 1
/* 0F65D4 7F0C1AA4 30783FFF */  andi  $t8, $v1, 0x3fff
/* 0F65D8 7F0C1AA8 54580005 */  bnel  $v0, $t8, .L7F0C1AC0
/* 0F65DC 7F0C1AAC 00031382 */   srl   $v0, $v1, 0xe
/* 0F65E0 7F0C1AB0 948F0002 */  lhu   $t7, 2($a0)
/* 0F65E4 7F0C1AB4 31F93FFF */  andi  $t9, $t7, 0x3fff
/* 0F65E8 7F0C1AB8 10590011 */  beq   $v0, $t9, .L7F0C1B00
.L7F0C1ABC:
/* 0F65EC 7F0C1ABC 00031382 */   srl   $v0, $v1, 0xe
.L7F0C1AC0:
/* 0F65F0 7F0C1AC0 14400002 */  bnez  $v0, .L7F0C1ACC
/* 0F65F4 7F0C1AC4 24A60001 */   addiu $a2, $a1, 1
/* 0F65F8 7F0C1AC8 00A05025 */  move  $t2, $a1
.L7F0C1ACC:
/* 0F65FC 7F0C1ACC 14400009 */  bnez  $v0, .L7F0C1AF4
/* 0F6600 7F0C1AD0 24E70002 */   addiu $a3, $a3, 2
/* 0F6604 7F0C1AD4 948E0002 */  lhu   $t6, 2($a0)
/* 0F6608 7F0C1AD8 28C1007C */  slti  $at, $a2, 0x7c
/* 0F660C 7F0C1ADC 000EC382 */  srl   $t8, $t6, 0xe
/* 0F6610 7F0C1AE0 57000005 */  bnezl $t8, .L7F0C1AF8
/* 0F6614 7F0C1AE4 00C02825 */   move  $a1, $a2
/* 0F6618 7F0C1AE8 50200003 */  beql  $at, $zero, .L7F0C1AF8
/* 0F661C 7F0C1AEC 00C02825 */   move  $a1, $a2
/* 0F6620 7F0C1AF0 00A05825 */  move  $t3, $a1
.L7F0C1AF4:
/* 0F6624 7F0C1AF4 00C02825 */  move  $a1, $a2
.L7F0C1AF8:
/* 0F6628 7F0C1AF8 14C9FFDD */  bne   $a2, $t1, .L7F0C1A70
/* 0F662C 7F0C1AFC 24840002 */   addiu $a0, $a0, 2
.L7F0C1B00:
/* 0F6630 7F0C1B00 28A1007C */  slti  $at, $a1, 0x7c
.L7F0C1B04:
/* 0F6634 7F0C1B04 10200021 */  beqz  $at, .L7F0C1B8C
/* 0F6638 7F0C1B08 00000000 */   nop   
/* 0F663C 7F0C1B0C 1500000C */  bnez  $t0, .L7F0C1B40
/* 0F6640 7F0C1B10 240D0060 */   li    $t5, 96
/* 0F6644 7F0C1B14 00AD0019 */  multu $a1, $t5
/* 0F6648 7F0C1B18 908F0000 */  lbu   $t7, ($a0)
/* 0F664C 7F0C1B1C 31F9FF3F */  andi  $t9, $t7, 0xff3f
/* 0F6650 7F0C1B20 372E0080 */  ori   $t6, $t9, 0x80
/* 0F6654 7F0C1B24 A08E0000 */  sb    $t6, ($a0)
/* 0F6658 7F0C1B28 3C0F8009 */  lui   $t7, %hi(ptr_j_char_data_buf) 
/* 0F665C 7F0C1B2C 8DEFC6F4 */  lw    $t7, %lo(ptr_j_char_data_buf)($t7)
/* 0F6660 7F0C1B30 0000C012 */  mflo  $t8
/* 0F6664 7F0C1B34 030F1021 */  addu  $v0, $t8, $t7
/* 0F6668 7F0C1B38 1000006F */  b     .L7F0C1CF8
/* 0F666C 7F0C1B3C 8FBF001C */   lw    $ra, 0x1c($sp)
.L7F0C1B40:
/* 0F6670 7F0C1B40 90990000 */  lbu   $t9, ($a0)
/* 0F6674 7F0C1B44 3C098009 */  lui   $t1, %hi(ptr_j_char_registry) 
/* 0F6678 7F0C1B48 2529C6F8 */  addiu $t1, %lo(ptr_j_char_registry) # addiu $t1, $t1, -0x3908
/* 0F667C 7F0C1B4C 332EFF3F */  andi  $t6, $t9, 0xff3f
/* 0F6680 7F0C1B50 35D80080 */  ori   $t8, $t6, 0x80
/* 0F6684 7F0C1B54 A0980000 */  sb    $t8, ($a0)
/* 0F6688 7F0C1B58 8D2F0000 */  lw    $t7, ($t1)
/* 0F668C 7F0C1B5C 240D0060 */  li    $t5, 96
/* 0F6690 7F0C1B60 00AD0019 */  multu $a1, $t5
/* 0F6694 7F0C1B64 01E72021 */  addu  $a0, $t7, $a3
/* 0F6698 7F0C1B68 90990002 */  lbu   $t9, 2($a0)
/* 0F669C 7F0C1B6C 332EFF3F */  andi  $t6, $t9, 0xff3f
/* 0F66A0 7F0C1B70 35D80080 */  ori   $t8, $t6, 0x80
/* 0F66A4 7F0C1B74 A0980002 */  sb    $t8, 2($a0)
/* 0F66A8 7F0C1B78 3C198009 */  lui   $t9, %hi(ptr_j_char_data_buf) 
/* 0F66AC 7F0C1B7C 8F39C6F4 */  lw    $t9, %lo(ptr_j_char_data_buf)($t9)
/* 0F66B0 7F0C1B80 00007812 */  mflo  $t7
/* 0F66B4 7F0C1B84 1000005B */  b     .L7F0C1CF4
/* 0F66B8 7F0C1B88 01F91021 */   addu  $v0, $t7, $t9
.L7F0C1B8C:
/* 0F66BC 7F0C1B8C 15000025 */  bnez  $t0, .L7F0C1C24
/* 0F66C0 7F0C1B90 00000000 */   nop   
/* 0F66C4 7F0C1B94 05400023 */  bltz  $t2, .L7F0C1C24
/* 0F66C8 7F0C1B98 240D0060 */   li    $t5, 96
/* 0F66CC 7F0C1B9C 014D0019 */  multu $t2, $t5
/* 0F66D0 7F0C1BA0 000A3840 */  sll   $a3, $t2, 1
/* 0F66D4 7F0C1BA4 01871821 */  addu  $v1, $t4, $a3
/* 0F66D8 7F0C1BA8 906E0000 */  lbu   $t6, ($v1)
/* 0F66DC 7F0C1BAC 3C098009 */  lui   $t1, %hi(ptr_j_char_registry) 
/* 0F66E0 7F0C1BB0 2529C6F8 */  addiu $t1, %lo(ptr_j_char_registry) # addiu $t1, $t1, -0x3908
/* 0F66E4 7F0C1BB4 31D8FF3F */  andi  $t8, $t6, 0xff3f
/* 0F66E8 7F0C1BB8 370F0080 */  ori   $t7, $t8, 0x80
/* 0F66EC 7F0C1BBC A06F0000 */  sb    $t7, ($v1)
/* 0F66F0 7F0C1BC0 8D390000 */  lw    $t9, ($t1)
/* 0F66F4 7F0C1BC4 00004012 */  mflo  $t0
/* 0F66F8 7F0C1BC8 00101043 */  sra   $v0, $s0, 1
/* 0F66FC 7F0C1BCC 03271821 */  addu  $v1, $t9, $a3
/* 0F6700 7F0C1BD0 004D0019 */  multu $v0, $t5
/* 0F6704 7F0C1BD4 946F0000 */  lhu   $t7, ($v1)
/* 0F6708 7F0C1BD8 30583FFF */  andi  $t8, $v0, 0x3fff
/* 0F670C 7F0C1BDC 24060060 */  li    $a2, 96
/* 0F6710 7F0C1BE0 31F9C000 */  andi  $t9, $t7, 0xc000
/* 0F6714 7F0C1BE4 03197025 */  or    $t6, $t8, $t9
/* 0F6718 7F0C1BE8 A46E0000 */  sh    $t6, ($v1)
/* 0F671C 7F0C1BEC 3C0F8009 */  lui   $t7, %hi(ptr_j_char_data_buf) 
/* 0F6720 7F0C1BF0 8DEFC6F4 */  lw    $t7, %lo(ptr_j_char_data_buf)($t7)
/* 0F6724 7F0C1BF4 3C190011 */  lui   $t9, %hi(_jfontcharSegmentStart) # $t9, 0x11
/* 0F6728 7F0C1BF8 27397940 */  addiu $t9, %lo(_jfontcharSegmentStart) # addiu $t9, $t9, 0x7940
/* 0F672C 7F0C1BFC 0000C012 */  mflo  $t8
/* 0F6730 7F0C1C00 03192821 */  addu  $a1, $t8, $t9
/* 0F6734 7F0C1C04 AFA80024 */  sw    $t0, 0x24($sp)
/* 0F6738 7F0C1C08 0C001707 */  jal   romCopy
/* 0F673C 7F0C1C0C 010F2021 */   addu  $a0, $t0, $t7
/* 0F6740 7F0C1C10 3C0E8009 */  lui   $t6, %hi(ptr_j_char_data_buf) 
/* 0F6744 7F0C1C14 8FA80024 */  lw    $t0, 0x24($sp)
/* 0F6748 7F0C1C18 8DCEC6F4 */  lw    $t6, %lo(ptr_j_char_data_buf)($t6)
/* 0F674C 7F0C1C1C 10000035 */  b     .L7F0C1CF4
/* 0F6750 7F0C1C20 010E1021 */   addu  $v0, $t0, $t6
.L7F0C1C24:
/* 0F6754 7F0C1C24 11000032 */  beqz  $t0, .L7F0C1CF0
/* 0F6758 7F0C1C28 3C028009 */   lui   $v0, %hi(ptr_j_char_data_buf)
/* 0F675C 7F0C1C2C 05600030 */  bltz  $t3, .L7F0C1CF0
/* 0F6760 7F0C1C30 000B1840 */   sll   $v1, $t3, 1
/* 0F6764 7F0C1C34 01831021 */  addu  $v0, $t4, $v1
/* 0F6768 7F0C1C38 904F0000 */  lbu   $t7, ($v0)
/* 0F676C 7F0C1C3C 3C098009 */  lui   $t1, %hi(ptr_j_char_registry) 
/* 0F6770 7F0C1C40 2529C6F8 */  addiu $t1, %lo(ptr_j_char_registry) # addiu $t1, $t1, -0x3908
/* 0F6774 7F0C1C44 31F8FF3F */  andi  $t8, $t7, 0xff3f
/* 0F6778 7F0C1C48 37190080 */  ori   $t9, $t8, 0x80
/* 0F677C 7F0C1C4C A0590000 */  sb    $t9, ($v0)
/* 0F6780 7F0C1C50 8D2E0000 */  lw    $t6, ($t1)
/* 0F6784 7F0C1C54 240D0060 */  li    $t5, 96
/* 0F6788 7F0C1C58 016D0019 */  multu $t3, $t5
/* 0F678C 7F0C1C5C 01C31021 */  addu  $v0, $t6, $v1
/* 0F6790 7F0C1C60 904F0002 */  lbu   $t7, 2($v0)
/* 0F6794 7F0C1C64 24060080 */  li    $a2, 128
/* 0F6798 7F0C1C68 31F8FF3F */  andi  $t8, $t7, 0xff3f
/* 0F679C 7F0C1C6C 37190080 */  ori   $t9, $t8, 0x80
/* 0F67A0 7F0C1C70 A0590002 */  sb    $t9, 2($v0)
/* 0F67A4 7F0C1C74 8D2E0000 */  lw    $t6, ($t1)
/* 0F67A8 7F0C1C78 00107843 */  sra   $t7, $s0, 1
/* 0F67AC 7F0C1C7C 31E73FFF */  andi  $a3, $t7, 0x3fff
/* 0F67B0 7F0C1C80 01C31021 */  addu  $v0, $t6, $v1
/* 0F67B4 7F0C1C84 94590000 */  lhu   $t9, ($v0)
/* 0F67B8 7F0C1C88 00004012 */  mflo  $t0
/* 0F67BC 7F0C1C8C 332EC000 */  andi  $t6, $t9, 0xc000
/* 0F67C0 7F0C1C90 00EE7825 */  or    $t7, $a3, $t6
/* 0F67C4 7F0C1C94 A44F0000 */  sh    $t7, ($v0)
/* 0F67C8 7F0C1C98 8D380000 */  lw    $t8, ($t1)
/* 0F67CC 7F0C1C9C 03031021 */  addu  $v0, $t8, $v1
/* 0F67D0 7F0C1CA0 94590002 */  lhu   $t9, 2($v0)
/* 0F67D4 7F0C1CA4 3C188009 */  lui   $t8, %hi(ptr_j_char_data_buf) 
/* 0F67D8 7F0C1CA8 332EC000 */  andi  $t6, $t9, 0xc000
/* 0F67DC 7F0C1CAC 00EE7825 */  or    $t7, $a3, $t6
/* 0F67E0 7F0C1CB0 A44F0002 */  sh    $t7, 2($v0)
/* 0F67E4 7F0C1CB4 8F18C6F4 */  lw    $t8, %lo(ptr_j_char_data_buf)($t8)
/* 0F67E8 7F0C1CB8 32191FFF */  andi  $t9, $s0, 0x1fff
/* 0F67EC 7F0C1CBC 00197043 */  sra   $t6, $t9, 1
/* 0F67F0 7F0C1CC0 01182021 */  addu  $a0, $t0, $t8
/* 0F67F4 7F0C1CC4 3C180012 */  lui   $t8, %hi(_efontcharSegmentStart) # $t8, 0x12
/* 0F67F8 7F0C1CC8 27183040 */  addiu $t8, %lo(_efontcharSegmentStart) # addiu $t8, $t8, 0x3040
/* 0F67FC 7F0C1CCC 000E79C0 */  sll   $t7, $t6, 7
/* 0F6800 7F0C1CD0 01F82821 */  addu  $a1, $t7, $t8
/* 0F6804 7F0C1CD4 0C001707 */  jal   romCopy
/* 0F6808 7F0C1CD8 AFA80024 */   sw    $t0, 0x24($sp)
/* 0F680C 7F0C1CDC 3C198009 */  lui   $t9, %hi(ptr_j_char_data_buf) 
/* 0F6810 7F0C1CE0 8FA80024 */  lw    $t0, 0x24($sp)
/* 0F6814 7F0C1CE4 8F39C6F4 */  lw    $t9, %lo(ptr_j_char_data_buf)($t9)
/* 0F6818 7F0C1CE8 10000002 */  b     .L7F0C1CF4
/* 0F681C 7F0C1CEC 01191021 */   addu  $v0, $t0, $t9
.L7F0C1CF0:
/* 0F6820 7F0C1CF0 8C42C6F4 */  lw    $v0, %lo(ptr_j_char_data_buf)($v0)
.L7F0C1CF4:
/* 0F6824 7F0C1CF4 8FBF001C */  lw    $ra, 0x1c($sp)
.L7F0C1CF8:
/* 0F6828 7F0C1CF8 8FB00018 */  lw    $s0, 0x18($sp)
/* 0F682C 7F0C1CFC 27BD0038 */  addiu $sp, $sp, 0x38
/* 0F6830 7F0C1D00 03E00008 */  jr    $ra
/* 0F6834 7F0C1D04 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void load_mission_text_bank(u32 param_1)
{
    *(u8 **)(&ptr_text + param_1) = _load_resource_named_to_membank((byte *)(&(&LnameX_lookuptable)[param_1].en_file)[j_text_trigger],1,0x100,4);
}
#else
GLOBAL_ASM(
.text
glabel load_mission_text_bank
/* 0F6838 7F0C1D08 3C188005 */  lui   $t8, %hi(j_text_trigger) 
/* 0F683C 7F0C1D0C 8F1884D0 */  lw    $t8, %lo(j_text_trigger)($t8)
/* 0F6840 7F0C1D10 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0F6844 7F0C1D14 000478C0 */  sll   $t7, $a0, 3
/* 0F6848 7F0C1D18 AFA40018 */  sw    $a0, 0x18($sp)
/* 0F684C 7F0C1D1C 0018C880 */  sll   $t9, $t8, 2
/* 0F6850 7F0C1D20 01F94021 */  addu  $t0, $t7, $t9
/* 0F6854 7F0C1D24 3C048005 */  lui   $a0, %hi(LnameX_lookuptable)
/* 0F6858 7F0C1D28 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0F685C 7F0C1D2C 00882021 */  addu  $a0, $a0, $t0
/* 0F6860 7F0C1D30 8C8484D4 */  lw    $a0, %lo(LnameX_lookuptable)($a0)
/* 0F6864 7F0C1D34 24050001 */  li    $a1, 1
/* 0F6868 7F0C1D38 24060100 */  li    $a2, 256
/* 0F686C 7F0C1D3C 0FC2F341 */  jal   _load_resource_named_to_membank
/* 0F6870 7F0C1D40 24070004 */   li    $a3, 4
/* 0F6874 7F0C1D44 8FA90018 */  lw    $t1, 0x18($sp)
/* 0F6878 7F0C1D48 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0F687C 7F0C1D4C 3C018009 */  lui   $at, %hi(ptr_text)
/* 0F6880 7F0C1D50 00095080 */  sll   $t2, $t1, 2
/* 0F6884 7F0C1D54 002A0821 */  addu  $at, $at, $t2
/* 0F6888 7F0C1D58 AC22C640 */  sw    $v0, %lo(ptr_text)($at)
/* 0F688C 7F0C1D5C 03E00008 */  jr    $ra
/* 0F6890 7F0C1D60 27BD0018 */   addiu $sp, $sp, 0x18
)
#endif





#ifdef NONMATCHING
void load_briefing_text_bank(int lnameID,undefined *target,int size)
{
    *(u8 **)(&ptr_text + lnameID) = _load_resource_named_to_buffer((byte *)(&(&LnameX_lookuptable)[lnameID].en_file)[j_text_trigger],1,target, size);
}
#else
GLOBAL_ASM(
.text
glabel load_briefing_text_bank
/* 0F6894 7F0C1D64 3C188005 */  lui   $t8, %hi(j_text_trigger) 
/* 0F6898 7F0C1D68 8F1884D0 */  lw    $t8, %lo(j_text_trigger)($t8)
/* 0F689C 7F0C1D6C 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0F68A0 7F0C1D70 000478C0 */  sll   $t7, $a0, 3
/* 0F68A4 7F0C1D74 AFA40018 */  sw    $a0, 0x18($sp)
/* 0F68A8 7F0C1D78 0018C880 */  sll   $t9, $t8, 2
/* 0F68AC 7F0C1D7C 00C03825 */  move  $a3, $a2
/* 0F68B0 7F0C1D80 01F94021 */  addu  $t0, $t7, $t9
/* 0F68B4 7F0C1D84 3C048005 */  lui   $a0, %hi(LnameX_lookuptable)
/* 0F68B8 7F0C1D88 00A03025 */  move  $a2, $a1
/* 0F68BC 7F0C1D8C AFBF0014 */  sw    $ra, 0x14($sp)
/* 0F68C0 7F0C1D90 AFA5001C */  sw    $a1, 0x1c($sp)
/* 0F68C4 7F0C1D94 00882021 */  addu  $a0, $a0, $t0
/* 0F68C8 7F0C1D98 8C8484D4 */  lw    $a0, %lo(LnameX_lookuptable)($a0)
/* 0F68CC 7F0C1D9C 0FC2F350 */  jal   _load_resource_named_to_buffer
/* 0F68D0 7F0C1DA0 24050001 */   li    $a1, 1
/* 0F68D4 7F0C1DA4 8FA90018 */  lw    $t1, 0x18($sp)
/* 0F68D8 7F0C1DA8 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0F68DC 7F0C1DAC 3C018009 */  lui   $at, %hi(ptr_text)
/* 0F68E0 7F0C1DB0 00095080 */  sll   $t2, $t1, 2
/* 0F68E4 7F0C1DB4 002A0821 */  addu  $at, $at, $t2
/* 0F68E8 7F0C1DB8 AC22C640 */  sw    $v0, %lo(ptr_text)($at)
/* 0F68EC 7F0C1DBC 03E00008 */  jr    $ra
/* 0F68F0 7F0C1DC0 27BD0018 */   addiu $sp, $sp, 0x18
)
#endif





void blank_text_bank(s32 textBank) {
    (&ptr_text)[textBank] = 0;
}


u8 * get_textptr_for_textID(s32 slotID)
{
    u32 * textbank_ptr = (&ptr_text)[slotID >> 10]; /* get the text file bank ID index the text ptr table */
    u32 textslot_offset = textbank_ptr[slotID & 0x03FF]; /* load the textbank ptr table then get the slot's offset */

    u32 output_slot = textslot_offset; /* add the text slot offset to the base ptr to get the ptr to text file's slot */
    output_slot += (u32)textbank_ptr;
    return (textslot_offset != 0) ? output_slot : NULL;
}
