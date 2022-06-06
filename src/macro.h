#ifndef _MACRO_H_
#define _MACRO_H_

/*
* contains common macros used in the code base.
*/

#define ALIGN64_V1(val) (((val) + 0x3F) & ~0x3F)

#define ALIGN64_V2(val) ((((u32)val) + 0x3f | 0x3f) ^ 0x3f)

#endif
