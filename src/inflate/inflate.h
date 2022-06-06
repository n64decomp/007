#ifndef _INFLATE_H_
#define _INFLATE_H_
struct huft {
	u8 e;                /* number of extra bits or operation */
	u8 b;                /* number of bits in this code or subcode */
	union {
		u16 n;            /* literal, length base, or distance base */
		struct huft *t;   /* pointer to next level of table */
	} v;
};

u32 decompress_entry(void *src, void *dst, struct huft *hlist);

#endif
