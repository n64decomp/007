#include <ultra64.h>
#include "initcheattext.h"
#include "player.h"
#include "cheat_buttons.h"

void initCheatTextBuffer(void) {
    int i;
    
    for(i=0;i<75;i++)
    {
        g_CheatPlayerTextRelated[i] = 0;
    }

}


void disableOnscreenCheatText(void)
{
  g_CurrentPlayer->something_with_cheat_text = 0;
  g_CurrentPlayer->can_display_cheat_text = 0;
}

