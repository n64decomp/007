#ifndef _CHEAT_BUTTONS_H_
#define _CHEAT_BUTTONS_H_
#include <ultra64.h>

enum CHEAT_MASK {
    CHEAT_MASK_0 = 0,

    /**
     * Title screen related.
     */
    CHEAT_MASK_MENUS = (1 << 0),

    /**
     * Singleplayer in-game
     */
    CHEAT_MASK_SPGAME = (1 << 1),

    /**
     * Multiplayer in-game
     */
    CHEAT_MASK_MPGAME = (1 << 2),
    
    CHEAT_MASK_8 = (1 << 3),

    /**
     * Text related when turning cheats on and off.
     */
    CHEAT_MASK_16 = (1 << 4),

    /**
     * Seems to be a "applies to all players" or "global" flag.
     * Logic branch when turning cheats on (set = single player, vs off = iterate all players)
     * Text related when turning cheats on and off
     */
    CHEAT_MASK_GLOBAL = (1 << 5),

    /**
     * Checked when disabling cheat
     */
    CHEAT_MASK_TOGGLE = (1 << 6),

    CHEAT_MASK_128 = (1 << 7),
    CHEAT_MASK_256 = (1 << 8),
    CHEAT_MASK_512 = (1 << 9),
    CHEAT_MASK_1024 = (1 << 10)

    // ... 
};

typedef struct  {
    /**
     * Offset 0x0.
     */
    u8 cheat_id;

    /**
     * Offset 0x1. //maybe timer to enter code?
     */
    u8 count_of_something;

    /**
     * Offset 0x2.
     */
    u8 field_2;

    /**
     * Offset 0x3.
     */
    u8 field_3;

    /**
     * Seems to be pointer to u16 array.
     * Offset 0x4.
     */
    u16 *cheatbuttons;

    /**
     * Offset 0x8.
     */
    u16 text_bank_id;

    /**
     * Offset 0xa.
     */
    u16 unk_a;

    /**
     * Offset 0xc.
     */
    int maskfield;
} CheatInfo;


extern u8 g_CheatPlayerTextRelated[0x4C];

//public Functions
bool cheatIsEnemyRockets(CHEAT_ID cheatindex);
void cheatButtonTurnOnCheatForPlayers(CHEAT_ID cheatindex);
void cheat_buttons_mp_related(void);
bool cheatIsActive(CHEAT_ID cheatindex);
bool cheatCheckIfMPCheat(CHEAT_ID cheatindex);
void cheatDisableAllCheats(void);
char *cheatGetMenuTextPointer(CHEAT_ID cheatindex);

#endif
