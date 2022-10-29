#ifndef _INITACTORPROPSTUFF_H_
#define _INITACTORPROPSTUFF_H_

#include <ultra64.h>

struct attackanimconfig {
	/*0x00*/ s16 animnum;
	/*0x04*/ f32 unk04;
	/*0x08*/ f32 unk08;
	/*0x0c*/ f32 unk0c;
	/*0x10*/ f32 unk10; // frame number
	/*0x14*/ f32 unk14; // frame number
	/*0x18*/ f32 unk18; // frame number
	/*0x1c*/ f32 unk1c; // frame number
	/*0x20*/ f32 unk20; // frame number
	/*0x24*/ f32 unk24; // frame number
	/*0x28*/ f32 unk28; // frame number
	/*0x2c*/ f32 unk2c; // frame number
	/*0x30*/ f32 unk30;
	/*0x34*/ f32 unk34;
	/*0x38*/ f32 unk38;
	/*0x3c*/ f32 unk3c;
	/*0x40*/ f32 unk40;
	/*0x44*/ f32 unk44;
};
struct attackanimgroup {
	struct attackanimconfig *animcfg;
	s32 len;
};

void sub_GAME_7F0009A0(void);

#endif
