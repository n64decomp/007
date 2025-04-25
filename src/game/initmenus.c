#include <ultra64.h>
#include <memp.h>
#include "front.h"
#include "initmenus.h"
#include "initintromatrices.h"
#include <macro.h>

void init_menus_or_reset(void)
{
    s32 i;
    current_menu = ~MENU_LEGAL_SCREEN;
    maybe_prev_menu = ~MENU_LEGAL_SCREEN;
    screen_size = SCREEN_SIZE_320x240;
    spectrum_related_flag = TRUE;
    is_emulating_spectrum = FALSE;
    folder_selection_screen_option_icon = 0;
    folder_selected_for_deletion = -1;
    folder_selected_for_deletion_choice = 1;
    tab_start_highlight = FALSE;
    tab_next_highlight = FALSE;
    tab_prev_highlight = FALSE;
    maybe_is_in_menu = TRUE;

    if (prev_keypresses)
    {
        menu_update = MENU_FILE_SELECT;
    }

    if (menu_update < 0)
    {
        menu_update = MENU_FILE_SELECT;
    }

    ptr_logo_and_walletbond_DL = (u8 *)mempAllocBytesInBank(0x78000, MEMPOOL_STAGE);

#if defined(VERSION_EU)
    ptr_menu_videobuffer = mempAllocBytesInBank(0x55040, MEMPOOL_STAGE);
#else
    ptr_menu_videobuffer = mempAllocBytesInBank(0x4b040, MEMPOOL_STAGE);
#endif

    ptr_menu_videobuffer = ALIGN64_V1(ptr_menu_videobuffer);

    for (i = 0; i < 4; i++)
    {
        walletinst[i] = NULL;
    }

    alloc_intro_matrices();
}
