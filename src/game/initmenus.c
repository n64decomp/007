#include <ultra64.h>
#include <memp.h>
#include "front.h"
#include "initmenus.h"
#include "initintromatrices.h"
#include <macro.h>

void init_menus_or_reset(void)
{
    current_menu = ~MENU_LEGAL_SCREEN;
    maybe_prev_menu = ~MENU_LEGAL_SCREEN;
    screen_size = SCREEN_SIZE_320x240;
    spectrum_related_flag = TRUE;
    is_emulating_spectrum = FALSE;
    folder_selection_screen_option_icon = 0;
    folder_selected_for_deletion = -1;
    folder_selected_for_deletion_choice = 1;
    tab_1_highlight = FALSE;
    tab_2_highlight = FALSE;
    tab_3_highlight = FALSE;
    maybe_is_in_menu = TRUE;

    if (prev_keypresses)
    {
        menu_update = MENU_FILE_SELECT;
    }

    if (menu_update < 0)
    {
        menu_update = MENU_FILE_SELECT;
    }

    ptr_logo_and_walletbond_DL = (Gfx *)mempAllocBytesInBank(0x78000, 4);

#if defined(VERSION_EU)
    ptr_menu_videobuffer = mempAllocBytesInBank(0x55040, 4);
#else
    ptr_menu_videobuffer = mempAllocBytesInBank(0x4b040, 4);
#endif
    ptr_menu_videobuffer = ALIGN64_V1(ptr_menu_videobuffer);

    ptr_folder_object_instance = 0x0;
    set0_never_used = 0;
    set0_never_used_0 = 0;
    D_8002A968 = 0;

    alloc_intro_matrices();
}
