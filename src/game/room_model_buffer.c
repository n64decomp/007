#include "ultra64.h"

//TODO this is not correct size afaik, but it fills a gap this way
//shrinking slightly from 0x271CA0 to allow some room for shifting, 
// eventually we will know real sizes and other buffers
u8 room_model_buffer[0x270000];
