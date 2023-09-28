#ifndef _MACRO_H_
#define _MACRO_H_

/*
* contains common macros used in the code base.
*/

#define ALIGN64_V1(val) (((val) + 0x3F) & ~0x3F)

#define ALIGN64_V2(val) ((((u32)val) + 0x3f | 0x3f) ^ 0x3f)

/*
* Align to 16 bit boundary. Version "a", with preliminary addition.
*/
#define ALIGN16_a(val)        (((val) + 0xf | 0xf) ^ 0xf)


#define align_addr_even(X) (((X) | 1) ^ 1)

#endif
