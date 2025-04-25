#ifndef _LVL_TEXT_H_
#define _LVL_TEXT_H_
#include <ultra64.h>
#include "bondconstants.h"

struct jpncharpixels {
	/*0x00*/ u32 unk00;
	/*0x04*/ u32 unk04;
	/*0x08*/ u32 unk08;
};

struct jpncacheitem {
	u16 ttl : 2; //cannonically timeleft
	u16 codepoint : 14;
};


extern s32 j_text_trigger;

void langLoadToAddr(u32 id);
void langTick(void);
u8 * langGet(s32 slotID);
void langLoadToBank(int id, u8 *target, int size);
LEVELID langGetLangBankIndexFromStagenum(LEVELID level);

#endif
