#include <ultra64.h>
#include "zlib.h"
#include "include/string.h"
#include "include/bstring.h"

#define GETBYTE()   (rz_inbuf[rz_inptr++])
#define NEXTBYTE()  (u8)GETBYTE()
#define NEEDBITS(n) {while(k<(n)){b|=((u32)NEXTBYTE())<<k;k+=8;}}
#define DUMPBITS(n) {b>>=(n);k-=(n);}

#define WSIZE 0x8000U
#define BMAX 16
#define N_MAX 288

//.bss

//bss:8008D350
u8 *rz_inbuf;
//bss:8008D354
u8 *rz_outbuf;
//bss:8008D358
u32 rz_inptr;
//bss:8008D35C
u32 rz_wp;
//bss:8008D360
struct huft *rz_hlist;
//bss:8008D364
u32 rz_bb;
//bss:8008D368
u32 rz_bk;
//bss:8008D36C
u32 rz_hufts;


//.data
u8 rz_border[0x14] = {
        16, 17, 18, 0, 8, 7, 9, 6, 10, 5, 11, 4, 12, 3, 13, 2, 14, 1, 15};

u16 rz_cplens[0x20] = {
        3, 4, 5, 6, 7, 8, 9, 10, 11, 13, 15, 17, 19, 23, 27, 31,
        35, 43, 51, 59, 67, 83, 99, 115, 131, 163, 195, 227, 258, 0, 0};

u8 rz_cplext[0x20] = {
        0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 2,
        3, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 0, 99, 99};

u16 rz_cpdist[0x1E] = {
        1, 2, 3, 4, 5, 7, 9, 13, 17, 25, 33, 49, 65, 97, 129, 193,
        257, 385, 513, 769, 1025, 1537, 2049, 3073, 4097, 6145,
        8193, 12289, 16385, 24577};

u8 rz_cpdext[0x20] = {
        0, 0, 0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6,
        7, 7, 8, 8, 9, 9, 10, 10, 11, 11,
        12, 12, 13, 13};

u16 rz_mask_bits[] = {
    0, 1, 3, 7, 0xF, 0x1F, 0x3F, 0x7F, 0xFF, 0x1FF, 0x3FF, 0x7FF, 0xFFF, 0x1FFF, 0x3FFF, 0x7FFF, 0xFFFF, 0
};

s32 rz_lbits = 9;
s32 rz_dbits = 6;

//.rodata


/* Given a list of code lengths and a maximum table size, make a set of
   tables to decode that set of codes.  Return zero on success, one if
   the given code set is incomplete (the tables are still built in this
   case), two if the input is invalid (all zero length codes or an
   oversubscribed set of lengths), and three if not enough memory. */
s32 zlib_huft_build(u32 *b, u32 n, u32 s, u16 *d, u8 *e, struct huft **t, s32 *m)
{
	u32 a;                   /* counter for codes of length k */
	u32 c[BMAX+1];           /* bit length count table */
	u32 f;                   /* i repeats in table every f entries */
	s32 g;                   /* maximum code length */
	s32 h;                   /* table level */
	register u32 i;          /* counter, current code */
	register u32 j;          /* counter */
	register s32 k;          /* number of bits in current code */
	s32 l;                   /* bits per table (returned in m) */
	register u32 *p;         /* pointer into c[], b[], or v[] */
	register struct huft *q; /* points to current table */
	struct huft r;           /* table entry for structure assignment */
	struct huft *u[BMAX];    /* table stack */
	u32 v[N_MAX];            /* values in order of bit length */
	register s32 w;          /* bits before this table == (l * h) */
	u32 x[BMAX+1];           /* bit offsets, then code stack */
	u32 *xp;                 /* pointer into x */
	s32 y;                   /* number of dummy codes added */
	u32 z;                   /* number of entries in current table */

	/* Generate counts for each bit length */
    bzero(c, sizeof(c));

	p = b;
	i = n;

	do {
		c[*p]++;                  /* assume all entries <= BMAX */
		p++;                      /* Can't combine with above line (Solaris bug) */
	} while (--i);

	if (c[0] == n) {              /* null input--all zero length codes */
		*t = NULL;
		*m = 0;
		return 0;
	}

	/* Find minimum and maximum length, bound *m by those */
	l = *m;

	for (j = 1; j <= BMAX; j++) {
		if (c[j]) {
			break;
		}
	}

	k = j;                        /* minimum code length */

	if (l < j) {
		l = j;
	}

	for (i = BMAX; i; i--) {
		if (c[i]) {
			break;
		}
	}

	g = i;                        /* maximum code length */

	if (l > i) {
		l = i;
	}

	*m = l;

	/* Adjust last length count to fill out codes, if needed */
	for (y = 1 << j; j < i; j++, y <<= 1) {
		y -= c[j];
	}

	y -= c[i];
	c[i] += y;

	/* Generate starting offsets into the value table for each length */
	x[1] = j = 0;
	p = c + 1;
	xp = x + 2;

	while (--i) {                 /* note that i == g from above */
		*xp++ = (j += *p++);
	}

	/* Make a table of values in order of bit lengths */
	p = b;
	i = 0;

	do {
		if ((j = *p++) != 0) {
			v[x[j]++] = i;
		}
	} while (++i < n);

	/* Generate the Huffman codes and for each, make the table entries */
	x[0] = i = 0;                 /* first Huffman code is zero */
	p = v;                        /* grab values in bit order */
	h = -1;                       /* no tables yet--level -1 */
	w = -l;                       /* bits decoded == (l * h) */
	u[0] = (struct huft *)NULL;   /* just to keep compilers happy */
	q = (struct huft *)NULL;      /* ditto */
	z = 0;                        /* ditto */

	/* go through the bit lengths (k already is bits in shortest code) */
	for (; k <= g; k++) {
		a = c[k];

		while (a--) {
			/* here i is the Huffman code of length k bits for value *p */
			/* make tables up to required level */
			while (k > w + l) {
				h++;
				w += l;                 /* previous table always l bits */

				/* compute minimum size table less than or equal to l bits */
				z = (z = g - w) > l ? l : z;  /* upper limit on table size */

				if ((f = 1 << (j = k - w)) > a + 1) {   /* try a k-w bit table */
				                          /* too few codes for k-w bit table */
					f -= a + 1;           /* deduct codes from patterns left */
					xp = c + k;

					while (++j < z) {     /* try smaller tables up to z bits */
						if ((f <<= 1) <= *++xp) {
							break;            /* enough codes to use up j bits */
						}

						f -= *xp;           /* else deduct codes from patterns */
					}
				}

				z = 1 << j;             /* table entries for j-bit table */

				/* allocate and link in new table */
				q = &rz_hlist[rz_hufts];

				rz_hufts += z + 1;         /* track memory usage */
				*t = q + 1;             /* link to list for huft_free() */
				*(t = &(q->v.t)) = (struct huft *)NULL;
				u[h] = ++q;             /* table starts after link */

				/* connect to last table, if there is one */
				if (h) {
					x[h] = i;             /* save pattern for backing up */
					r.b = l;              /* bits to dump before this table */
					r.e = 16 + j;         /* bits in this table */
					r.v.t = q;            /* pointer to this table */
					j = i >> (w - l);     /* (get around Turbo C bug) */
					u[h-1][j] = r;        /* connect to last table */
				}
			}

			/* set up table entry in r */
			r.b = (k - w);

			if (p >= v + n) {
				r.e = 99;               /* out of values--invalid code */
			} else if (*p < s) {
				r.e = (*p < 256 ? 16 : 15);    /* 256 is end-of-block code */
				r.v.n = *p;             /* simple code is just the value */
				p++;                    /* one compiler does not like *p++ */
			} else {
				r.e = e[*p - s];   /* non-simple--look up in lists */
				r.v.n = d[*p++ - s];
			}

			/* fill code-like entries with r */
			f = 1 << (k - w);

			for (j = i >> w; j < z; j += f) {
				q[j] = r;
			}

			/* backwards increment the k-bit code i */
			for (j = 1 << (k - 1); i & j; j >>= 1) {
				i ^= j;
			}

			i ^= j;

			/* backup over finished tables */
			while ((i & ((1 << w) - 1)) != x[h]) {
				h--;                    /* don't need to update q */
				w -= l;
			}
		}
	}

	/* Return true (1) if we were given an incomplete table */
	return y != 0 && g != 1;
}





#ifdef NONMATCHING
/**
 * copy and paste from inflate.c, this is only like 60% correct.
*/
s32 zlib_inflate_codes(struct huft *tl, struct huft *td, s32 bl, s32 bd)
{
    register u32 e;    /* table entry flag/number of extra bits */
    u32 n, d;          /* length and index for copy */
    u32 w;             /* current window position */
    struct huft *t;    /* pointer to table entry */
    u32 ml, md;        /* masks for bl and bd bits */
    register u32 b;    /* bit buffer */
    register u32 k;    /* number of bits in bit buffer */
    u16 *maskbits = rz_mask_bits;


    /* make local copies of globals */
    b = rz_bb;                       /* initialize bit buffer */
    k = rz_bk;
    w = rz_wp;                       /* initialize window position */

    /* inflate the coded data */
    //ml = rz_mask_bits[bl];           /* precompute masks for speed */
    //md = rz_mask_bits[bd];

    for (;;)                      /* do until end of block */
    {
        u8 *outbuf = rz_outbuf;

        ml = maskbits[bl];
        md = maskbits[bd];

        NEEDBITS((u32)bl)

        if ((e = (t = tl + ((u32)b & ml))->e) > 16)
        {
            do
            {
                DUMPBITS(t->b)
                e -= 16;
                NEEDBITS(e)

            } while ((e = (t = t->v.t + ((u32)b & maskbits[e]))->e) > 16);
        }

        DUMPBITS(t->b)

        if (e == 16)                /* then it's a literal */
        {
            rz_outbuf[w++] = (u8)t->v.n;

            if ((&outbuf[w] >= &rz_inbuf[rz_inptr]) && (u32)(&outbuf[w] - &rz_inbuf[rz_inptr]) < WSIZE)
            {
                while(1)
                    ;
            }
        }
        else                        /* it's an EOB or a length */
        {
            /* exit if end of block */
            if (e == 15)
            {
                break;
            }

            /* get length of block to copy */
            NEEDBITS(e)
            n = t->v.n + ((u32)b & maskbits[e]);
            DUMPBITS(e);

            /* decode distance of block to copy */
            NEEDBITS((u32)bd)

            if ((e = (t = td + ((u32)b & md))->e) > 16)
            {
                do
                {
                    DUMPBITS(t->b)
                    e -= 16;
                    NEEDBITS(e)

                } while ((e = (t = t->v.t + ((u32)b & maskbits[e]))->e) > 16);
            }

            DUMPBITS(t->b)
            NEEDBITS(e)
            d = w - t->v.n - ((u32)b & maskbits[e]);
            DUMPBITS(e)

            if ((&outbuf[w] >= &rz_inbuf[rz_inptr]) && (u32)(&outbuf[w] - &rz_inbuf[rz_inptr]) < WSIZE)
            {
                while(1)
                    ;
            }

            /* do the copy */
            do
            {
                e = n;
				n = 0;
                //n -= (e = (e = WSIZE - ((d &= WSIZE-1) > w ? d : w)) > n ? n : e);

                if (w - d >= e)         /* (this test assumes unsigned comparison) */
                {
                    memcpy(rz_outbuf + w, rz_outbuf + d, e);
                    w += e;
                    d += e;
                }
                else                      /* do it slow to avoid memcpy() overlap */
                {
                    do
                    {
                        rz_outbuf[w++] = rz_outbuf[d++];
                    } while (--e);
                }

                if ((&outbuf[w] >= &rz_inbuf[rz_inptr]) && (u32)(&outbuf[w] - &rz_inbuf[rz_inptr]) < WSIZE)
                {
                    while(1)
                        ;
                }
            } while (n);
        }
    }

    /* restore the globals from the locals */
    rz_wp = w;                       /* restore global window pointer */
    rz_bb = b;                       /* restore global bit buffer */
    rz_bk = k;

    /* done */
    return 0;
}
#else
GLOBAL_ASM(
.text
glabel zlib_inflate_codes
/* 103A20 7F0CEEF0 27BDFF90 */  addiu $sp, $sp, -0x70
/* 103A24 7F0CEEF4 3C098005 */  lui   $t1, %hi(rz_mask_bits) 
/* 103A28 7F0CEEF8 2529E9B0 */  addiu $t1, %lo(rz_mask_bits) # addiu $t1, $t1, -0x1650
/* 103A2C 7F0CEEFC AFBE0038 */  sw    $fp, 0x38($sp)
/* 103A30 7F0CEF00 AFB70034 */  sw    $s7, 0x34($sp)
/* 103A34 7F0CEF04 AFB5002C */  sw    $s5, 0x2c($sp)
/* 103A38 7F0CEF08 AFB40028 */  sw    $s4, 0x28($sp)
/* 103A3C 7F0CEF0C AFB30024 */  sw    $s3, 0x24($sp)
/* 103A40 7F0CEF10 AFB1001C */  sw    $s1, 0x1c($sp)
/* 103A44 7F0CEF14 00067840 */  sll   $t7, $a2, 1
/* 103A48 7F0CEF18 0007C840 */  sll   $t9, $a3, 1
/* 103A4C 7F0CEF1C AFBF003C */  sw    $ra, 0x3c($sp)
/* 103A50 7F0CEF20 AFA7007C */  sw    $a3, 0x7c($sp)
/* 103A54 7F0CEF24 3C148009 */  lui   $s4, %hi(rz_bb)
/* 103A58 7F0CEF28 3C118009 */  lui   $s1, %hi(rz_bk)
/* 103A5C 7F0CEF2C 3C158009 */  lui   $s5, %hi(rz_wp)
/* 103A60 7F0CEF30 012F6021 */  addu  $t4, $t1, $t7
/* 103A64 7F0CEF34 01396821 */  addu  $t5, $t1, $t9
/* 103A68 7F0CEF38 3C138009 */  lui   $s3, %hi(rz_inptr)
/* 103A6C 7F0CEF3C 3C178009 */  lui   $s7, %hi(rz_outbuf) 
/* 103A70 7F0CEF40 3C1E8009 */  lui   $fp, %hi(rz_inbuf) 
/* 103A74 7F0CEF44 AFB60030 */  sw    $s6, 0x30($sp)
/* 103A78 7F0CEF48 AFB20020 */  sw    $s2, 0x20($sp)
/* 103A7C 7F0CEF4C AFB00018 */  sw    $s0, 0x18($sp)
/* 103A80 7F0CEF50 AFA40070 */  sw    $a0, 0x70($sp)
/* 103A84 7F0CEF54 AFA50074 */  sw    $a1, 0x74($sp)
/* 103A88 7F0CEF58 AFA60078 */  sw    $a2, 0x78($sp)
/* 103A8C 7F0CEF5C 8E94D364 */  lw    $s4, %lo(rz_bb)($s4)
/* 103A90 7F0CEF60 8E31D368 */  lw    $s1, %lo(rz_bk)($s1)
/* 103A94 7F0CEF64 8EB5D35C */  lw    $s5, %lo(rz_wp)($s5)
/* 103A98 7F0CEF68 958A0000 */  lhu   $t2, ($t4)
/* 103A9C 7F0CEF6C 95AB0000 */  lhu   $t3, ($t5)
/* 103AA0 7F0CEF70 27DED350 */  addiu $fp, %lo(rz_inbuf) # addiu $fp, $fp, -0x2cb0
/* 103AA4 7F0CEF74 26F7D354 */  addiu $s7, %lo(rz_outbuf) # addiu $s7, $s7, -0x2cac
/* 103AA8 7F0CEF78 2673D358 */  addiu $s3, %lo(rz_inptr) # addiu $s3, $s3, -0x2ca8
/* 103AAC 7F0CEF7C 34078000 */  li    $a3, 32768
/* 103AB0 7F0CEF80 00C0F825 */  move  $ra, $a2
.L7F0CEF84:
/* 103AB4 7F0CEF84 023F082B */  sltu  $at, $s1, $ra
.L7F0CEF88:
/* 103AB8 7F0CEF88 5020000D */  beql  $at, $zero, .L7F0CEFC0
/* 103ABC 7F0CEF8C 8FB90070 */   lw    $t9, 0x70($sp)
/* 103AC0 7F0CEF90 8FC30000 */  lw    $v1, ($fp)
.L7F0CEF94:
/* 103AC4 7F0CEF94 8E620000 */  lw    $v0, ($s3)
/* 103AC8 7F0CEF98 00627821 */  addu  $t7, $v1, $v0
/* 103ACC 7F0CEF9C 91F80000 */  lbu   $t8, ($t7)
/* 103AD0 7F0CEFA0 244E0001 */  addiu $t6, $v0, 1
/* 103AD4 7F0CEFA4 AE6E0000 */  sw    $t6, ($s3)
/* 103AD8 7F0CEFA8 0238C804 */  sllv  $t9, $t8, $s1
/* 103ADC 7F0CEFAC 26310008 */  addiu $s1, $s1, 8
/* 103AE0 7F0CEFB0 023F082B */  sltu  $at, $s1, $ra
/* 103AE4 7F0CEFB4 1420FFF7 */  bnez  $at, .L7F0CEF94
/* 103AE8 7F0CEFB8 0299A025 */   or    $s4, $s4, $t9
/* 103AEC 7F0CEFBC 8FB90070 */  lw    $t9, 0x70($sp)
.L7F0CEFC0:
/* 103AF0 7F0CEFC0 028A7824 */  and   $t7, $s4, $t2
/* 103AF4 7F0CEFC4 000FC0C0 */  sll   $t8, $t7, 3
/* 103AF8 7F0CEFC8 03193021 */  addu  $a2, $t8, $t9
/* 103AFC 7F0CEFCC 90D20000 */  lbu   $s2, ($a2)
/* 103B00 7F0CEFD0 2E410011 */  sltiu $at, $s2, 0x11
/* 103B04 7F0CEFD4 5420001E */  bnezl $at, .L7F0CF050
/* 103B08 7F0CEFD8 90C20001 */   lbu   $v0, 1($a2)
/* 103B0C 7F0CEFDC 90C20001 */  lbu   $v0, 1($a2)
.L7F0CEFE0:
/* 103B10 7F0CEFE0 2652FFF0 */  addiu $s2, $s2, -0x10
/* 103B14 7F0CEFE4 02228823 */  subu  $s1, $s1, $v0
/* 103B18 7F0CEFE8 0232082B */  sltu  $at, $s1, $s2
/* 103B1C 7F0CEFEC 1020000C */  beqz  $at, .L7F0CF020
/* 103B20 7F0CEFF0 0054A006 */   srlv  $s4, $s4, $v0
/* 103B24 7F0CEFF4 8FC30000 */  lw    $v1, ($fp)
.L7F0CEFF8:
/* 103B28 7F0CEFF8 8E620000 */  lw    $v0, ($s3)
/* 103B2C 7F0CEFFC 00627021 */  addu  $t6, $v1, $v0
/* 103B30 7F0CF000 91CF0000 */  lbu   $t7, ($t6)
/* 103B34 7F0CF004 24590001 */  addiu $t9, $v0, 1
/* 103B38 7F0CF008 AE790000 */  sw    $t9, ($s3)
/* 103B3C 7F0CF00C 022FC004 */  sllv  $t8, $t7, $s1
/* 103B40 7F0CF010 26310008 */  addiu $s1, $s1, 8
/* 103B44 7F0CF014 0232082B */  sltu  $at, $s1, $s2
/* 103B48 7F0CF018 1420FFF7 */  bnez  $at, .L7F0CEFF8
/* 103B4C 7F0CF01C 0298A025 */   or    $s4, $s4, $t8
.L7F0CF020:
/* 103B50 7F0CF020 00127040 */  sll   $t6, $s2, 1
/* 103B54 7F0CF024 012E7821 */  addu  $t7, $t1, $t6
/* 103B58 7F0CF028 95F80000 */  lhu   $t8, ($t7)
/* 103B5C 7F0CF02C 8CCF0004 */  lw    $t7, 4($a2)
/* 103B60 7F0CF030 0314C824 */  and   $t9, $t8, $s4
/* 103B64 7F0CF034 001970C0 */  sll   $t6, $t9, 3
/* 103B68 7F0CF038 01CF3021 */  addu  $a2, $t6, $t7
/* 103B6C 7F0CF03C 90D20000 */  lbu   $s2, ($a2)
/* 103B70 7F0CF040 2E410011 */  sltiu $at, $s2, 0x11
/* 103B74 7F0CF044 5020FFE6 */  beql  $at, $zero, .L7F0CEFE0
/* 103B78 7F0CF048 90C20001 */   lbu   $v0, 1($a2)
/* 103B7C 7F0CF04C 90C20001 */  lbu   $v0, 1($a2)
.L7F0CF050:
/* 103B80 7F0CF050 24010010 */  li    $at, 16
/* 103B84 7F0CF054 0054A006 */  srlv  $s4, $s4, $v0
/* 103B88 7F0CF058 16410013 */  bne   $s2, $at, .L7F0CF0A8
/* 103B8C 7F0CF05C 02228823 */   subu  $s1, $s1, $v0
/* 103B90 7F0CF060 8EF80000 */  lw    $t8, ($s7)
/* 103B94 7F0CF064 8FD90000 */  lw    $t9, ($fp)
/* 103B98 7F0CF068 8E6E0000 */  lw    $t6, ($s3)
/* 103B9C 7F0CF06C 03152821 */  addu  $a1, $t8, $s5
/* 103BA0 7F0CF070 00A01025 */  move  $v0, $a1
/* 103BA4 7F0CF074 032E2021 */  addu  $a0, $t9, $t6
/* 103BA8 7F0CF078 00A4082B */  sltu  $at, $a1, $a0
/* 103BAC 7F0CF07C 14200006 */  bnez  $at, .L7F0CF098
/* 103rz_bb0 7F0CF080 00447823 */   subu  $t7, $v0, $a0
/* 103rz_bb4 7F0CF084 01E7082B */  sltu  $at, $t7, $a3
/* 103rz_bb8 7F0CF088 50200004 */  beql  $at, $zero, .L7F0CF09C
/* 103rz_bbC 7F0CF08C 94D80004 */   lhu   $t8, 4($a2)
.L7F0CF090:
/* 103BC0 7F0CF090 1000FFFF */  b     .L7F0CF090
/* 103BC4 7F0CF094 00000000 */   nop   
.L7F0CF098:
/* 103BC8 7F0CF098 94D80004 */  lhu   $t8, 4($a2)
.L7F0CF09C:
/* 103BCC 7F0CF09C 26B50001 */  addiu $s5, $s5, 1
/* 103BD0 7F0CF0A0 1000FFB8 */  b     .L7F0CEF84
/* 103BD4 7F0CF0A4 A0B80000 */   sb    $t8, ($a1)
.L7F0CF0A8:
/* 103BD8 7F0CF0A8 2401000F */  li    $at, 15
/* 103BDC 7F0CF0AC 124100A4 */  beq   $s2, $at, .L7F0CF340
/* 103BE0 7F0CF0B0 0232082B */   sltu  $at, $s1, $s2
/* 103BE4 7F0CF0B4 5020000D */  beql  $at, $zero, .L7F0CF0EC
/* 103BE8 7F0CF0B8 0012C840 */   sll   $t9, $s2, 1
/* 103BEC 7F0CF0BC 8FC30000 */  lw    $v1, ($fp)
.L7F0CF0C0:
/* 103BF0 7F0CF0C0 8E620000 */  lw    $v0, ($s3)
/* 103BF4 7F0CF0C4 0062C821 */  addu  $t9, $v1, $v0
/* 103BF8 7F0CF0C8 932E0000 */  lbu   $t6, ($t9)
/* 103BFC 7F0CF0CC 24580001 */  addiu $t8, $v0, 1
/* 103C00 7F0CF0D0 AE780000 */  sw    $t8, ($s3)
/* 103C04 7F0CF0D4 022E7804 */  sllv  $t7, $t6, $s1
/* 103C08 7F0CF0D8 26310008 */  addiu $s1, $s1, 8
/* 103C0C 7F0CF0DC 0232082B */  sltu  $at, $s1, $s2
/* 103C10 7F0CF0E0 1420FFF7 */  bnez  $at, .L7F0CF0C0
/* 103C14 7F0CF0E4 028FA025 */   or    $s4, $s4, $t7
/* 103C18 7F0CF0E8 0012C840 */  sll   $t9, $s2, 1
.L7F0CF0EC:
/* 103C1C 7F0CF0EC 01397021 */  addu  $t6, $t1, $t9
/* 103C20 7F0CF0F0 95CF0000 */  lhu   $t7, ($t6)
/* 103C24 7F0CF0F4 8FAE007C */  lw    $t6, 0x7c($sp)
/* 103C28 7F0CF0F8 94D90004 */  lhu   $t9, 4($a2)
/* 103C2C 7F0CF0FC 02328823 */  subu  $s1, $s1, $s2
/* 103C30 7F0CF100 01F4C024 */  and   $t8, $t7, $s4
/* 103C34 7F0CF104 022E082B */  sltu  $at, $s1, $t6
/* 103C38 7F0CF108 0254A006 */  srlv  $s4, $s4, $s2
/* 103C3C 7F0CF10C 1020000D */  beqz  $at, .L7F0CF144
/* 103C40 7F0CF110 03194021 */   addu  $t0, $t8, $t9
/* 103C44 7F0CF114 8FC30000 */  lw    $v1, ($fp)
/* 103C48 7F0CF118 01C02025 */  move  $a0, $t6
.L7F0CF11C:
/* 103C4C 7F0CF11C 8E620000 */  lw    $v0, ($s3)
/* 103C50 7F0CF120 00627821 */  addu  $t7, $v1, $v0
/* 103C54 7F0CF124 91F80000 */  lbu   $t8, ($t7)
/* 103C58 7F0CF128 244E0001 */  addiu $t6, $v0, 1
/* 103C5C 7F0CF12C AE6E0000 */  sw    $t6, ($s3)
/* 103C60 7F0CF130 0238C804 */  sllv  $t9, $t8, $s1
/* 103C64 7F0CF134 26310008 */  addiu $s1, $s1, 8
/* 103C68 7F0CF138 0224082B */  sltu  $at, $s1, $a0
/* 103C6C 7F0CF13C 1420FFF7 */  bnez  $at, .L7F0CF11C
/* 103C70 7F0CF140 0299A025 */   or    $s4, $s4, $t9
.L7F0CF144:
/* 103C74 7F0CF144 8FB90074 */  lw    $t9, 0x74($sp)
/* 103C78 7F0CF148 028B7824 */  and   $t7, $s4, $t3
/* 103C7C 7F0CF14C 000FC0C0 */  sll   $t8, $t7, 3
/* 103C80 7F0CF150 03193021 */  addu  $a2, $t8, $t9
/* 103C84 7F0CF154 90D20000 */  lbu   $s2, ($a2)
/* 103C88 7F0CF158 2E410011 */  sltiu $at, $s2, 0x11
/* 103C8C 7F0CF15C 5420001E */  bnezl $at, .L7F0CF1D8
/* 103C90 7F0CF160 90C20001 */   lbu   $v0, 1($a2)
/* 103C94 7F0CF164 90C20001 */  lbu   $v0, 1($a2)
.L7F0CF168:
/* 103C98 7F0CF168 2652FFF0 */  addiu $s2, $s2, -0x10
/* 103C9C 7F0CF16C 02228823 */  subu  $s1, $s1, $v0
/* 103CA0 7F0CF170 0232082B */  sltu  $at, $s1, $s2
/* 103CA4 7F0CF174 1020000C */  beqz  $at, .L7F0CF1A8
/* 103CA8 7F0CF178 0054A006 */   srlv  $s4, $s4, $v0
/* 103CAC 7F0CF17C 8FC30000 */  lw    $v1, ($fp)
.L7F0CF180:
/* 103CB0 7F0CF180 8E620000 */  lw    $v0, ($s3)
/* 103CB4 7F0CF184 00627021 */  addu  $t6, $v1, $v0
/* 103CB8 7F0CF188 91CF0000 */  lbu   $t7, ($t6)
/* 103CBC 7F0CF18C 24590001 */  addiu $t9, $v0, 1
/* 103CC0 7F0CF190 AE790000 */  sw    $t9, ($s3)
/* 103CC4 7F0CF194 022FC004 */  sllv  $t8, $t7, $s1
/* 103CC8 7F0CF198 26310008 */  addiu $s1, $s1, 8
/* 103CCC 7F0CF19C 0232082B */  sltu  $at, $s1, $s2
/* 103CD0 7F0CF1A0 1420FFF7 */  bnez  $at, .L7F0CF180
/* 103CD4 7F0CF1A4 0298A025 */   or    $s4, $s4, $t8
.L7F0CF1A8:
/* 103CD8 7F0CF1A8 00127040 */  sll   $t6, $s2, 1
/* 103CDC 7F0CF1AC 012E7821 */  addu  $t7, $t1, $t6
/* 103CE0 7F0CF1B0 95F80000 */  lhu   $t8, ($t7)
/* 103CE4 7F0CF1B4 8CCF0004 */  lw    $t7, 4($a2)
/* 103CE8 7F0CF1B8 0314C824 */  and   $t9, $t8, $s4
/* 103CEC 7F0CF1BC 001970C0 */  sll   $t6, $t9, 3
/* 103CF0 7F0CF1C0 01CF3021 */  addu  $a2, $t6, $t7
/* 103CF4 7F0CF1C4 90D20000 */  lbu   $s2, ($a2)
/* 103CF8 7F0CF1C8 2E410011 */  sltiu $at, $s2, 0x11
/* 103CFC 7F0CF1CC 5020FFE6 */  beql  $at, $zero, .L7F0CF168
/* 103D00 7F0CF1D0 90C20001 */   lbu   $v0, 1($a2)
/* 103D04 7F0CF1D4 90C20001 */  lbu   $v0, 1($a2)
.L7F0CF1D8:
/* 103D08 7F0CF1D8 02228823 */  subu  $s1, $s1, $v0
/* 103D0C 7F0CF1DC 0232082B */  sltu  $at, $s1, $s2
/* 103D10 7F0CF1E0 1020000C */  beqz  $at, .L7F0CF214
/* 103D14 7F0CF1E4 0054A006 */   srlv  $s4, $s4, $v0
/* 103D18 7F0CF1E8 8FC30000 */  lw    $v1, ($fp)
.L7F0CF1EC:
/* 103D1C 7F0CF1EC 8E620000 */  lw    $v0, ($s3)
/* 103D20 7F0CF1F0 0062C021 */  addu  $t8, $v1, $v0
/* 103D24 7F0CF1F4 93190000 */  lbu   $t9, ($t8)
/* 103D28 7F0CF1F8 244F0001 */  addiu $t7, $v0, 1
/* 103D2C 7F0CF1FC AE6F0000 */  sw    $t7, ($s3)
/* 103D30 7F0CF200 02397004 */  sllv  $t6, $t9, $s1
/* 103D34 7F0CF204 26310008 */  addiu $s1, $s1, 8
/* 103D38 7F0CF208 0232082B */  sltu  $at, $s1, $s2
/* 103D3C 7F0CF20C 1420FFF7 */  bnez  $at, .L7F0CF1EC
/* 103D40 7F0CF210 028EA025 */   or    $s4, $s4, $t6
.L7F0CF214:
/* 103D44 7F0CF214 94D80004 */  lhu   $t8, 4($a2)
/* 103D48 7F0CF218 00127040 */  sll   $t6, $s2, 1
/* 103D4C 7F0CF21C 012E7821 */  addu  $t7, $t1, $t6
/* 103D50 7F0CF220 02B8C823 */  subu  $t9, $s5, $t8
/* 103D54 7F0CF224 95F80000 */  lhu   $t8, ($t7)
/* 103D58 7F0CF228 02328823 */  subu  $s1, $s1, $s2
/* 103D5C 7F0CF22C 03147024 */  and   $t6, $t8, $s4
/* 103D60 7F0CF230 032E8023 */  subu  $s0, $t9, $t6
/* 103D64 7F0CF234 0254A006 */  srlv  $s4, $s4, $s2
/* 103D68 7F0CF238 01009025 */  move  $s2, $t0
.L7F0CF23C:
/* 103D6C 7F0CF23C 02B07823 */  subu  $t7, $s5, $s0
/* 103D70 7F0CF240 01F2082B */  sltu  $at, $t7, $s2
/* 103D74 7F0CF244 14200025 */  bnez  $at, .L7F0CF2DC
/* 103D78 7F0CF248 00004025 */   move  $t0, $zero
/* 103D7C 7F0CF24C 8EE30000 */  lw    $v1, ($s7)
/* 103D80 7F0CF250 8FD80000 */  lw    $t8, ($fp)
/* 103D84 7F0CF254 8E790000 */  lw    $t9, ($s3)
/* 103D88 7F0CF258 02B2B021 */  addu  $s6, $s5, $s2
/* 103D8C 7F0CF25C 02C31021 */  addu  $v0, $s6, $v1
/* 103D90 7F0CF260 2442FFFF */  addiu $v0, $v0, -1
/* 103D94 7F0CF264 03192021 */  addu  $a0, $t8, $t9
/* 103D98 7F0CF268 0044082B */  sltu  $at, $v0, $a0
/* 103D9C 7F0CF26C 14200006 */  bnez  $at, .L7F0CF288
/* 103DA0 7F0CF270 00447023 */   subu  $t6, $v0, $a0
/* 103DA4 7F0CF274 01C7082B */  sltu  $at, $t6, $a3
/* 103DA8 7F0CF278 50200004 */  beql  $at, $zero, .L7F0CF28C
/* 103DAC 7F0CF27C 00752021 */   addu  $a0, $v1, $s5
.L7F0CF280:
/* 103DB0 7F0CF280 1000FFFF */  b     .L7F0CF280
/* 103DB4 7F0CF284 00000000 */   nop   
.L7F0CF288:
/* 103DB8 7F0CF288 00752021 */  addu  $a0, $v1, $s5
.L7F0CF28C:
/* 103DBC 7F0CF28C 00702821 */  addu  $a1, $v1, $s0
/* 103DC0 7F0CF290 02403025 */  move  $a2, $s2
/* 103DC4 7F0CF294 AFA80068 */  sw    $t0, 0x68($sp)
/* 103DC8 7F0CF298 AFAA0058 */  sw    $t2, 0x58($sp)
/* 103DCC 7F0CF29C AFAB0054 */  sw    $t3, 0x54($sp)
/* 103DD0 7F0CF2A0 AFAC0044 */  sw    $t4, 0x44($sp)
/* 103DD4 7F0CF2A4 0C004E14 */  jal   memcpy
/* 103DD8 7F0CF2A8 AFAD0040 */   sw    $t5, 0x40($sp)
/* 103DDC 7F0CF2AC 3C098005 */  lui   $t1, %hi(rz_mask_bits) 
/* 103DE0 7F0CF2B0 2529E9B0 */  addiu $t1, %lo(rz_mask_bits) # addiu $t1, $t1, -0x1650
/* 103DE4 7F0CF2B4 34078000 */  li    $a3, 32768
/* 103DE8 7F0CF2B8 8FA80068 */  lw    $t0, 0x68($sp)
/* 103DEC 7F0CF2BC 8FAA0058 */  lw    $t2, 0x58($sp)
/* 103DF0 7F0CF2C0 8FAB0054 */  lw    $t3, 0x54($sp)
/* 103DF4 7F0CF2C4 8FAC0044 */  lw    $t4, 0x44($sp)
/* 103DF8 7F0CF2C8 8FAD0040 */  lw    $t5, 0x40($sp)
/* 103DFC 7F0CF2CC 8FBF0078 */  lw    $ra, 0x78($sp)
/* 103E00 7F0CF2D0 02C0A825 */  move  $s5, $s6
/* 103E04 7F0CF2D4 10000016 */  b     .L7F0CF330
/* 103E08 7F0CF2D8 02128021 */   addu  $s0, $s0, $s2
.L7F0CF2DC:
/* 103E0C 7F0CF2DC 8EE30000 */  lw    $v1, ($s7)
/* 103E10 7F0CF2E0 8FCF0000 */  lw    $t7, ($fp)
/* 103E14 7F0CF2E4 8E780000 */  lw    $t8, ($s3)
/* 103E18 7F0CF2E8 00752821 */  addu  $a1, $v1, $s5
/* 103E1C 7F0CF2EC 00A01025 */  move  $v0, $a1
/* 103E20 7F0CF2F0 01F82021 */  addu  $a0, $t7, $t8
/* 103E24 7F0CF2F4 00A4082B */  sltu  $at, $a1, $a0
/* 103E28 7F0CF2F8 14200006 */  bnez  $at, .L7F0CF314
/* 103E2C 7F0CF2FC 0044C823 */   subu  $t9, $v0, $a0
/* 103E30 7F0CF300 0327082B */  sltu  $at, $t9, $a3
/* 103E34 7F0CF304 50200004 */  beql  $at, $zero, .L7F0CF318
/* 103E38 7F0CF308 02037021 */   addu  $t6, $s0, $v1
.L7F0CF30C:
/* 103E3C 7F0CF30C 1000FFFF */  b     .L7F0CF30C
/* 103E40 7F0CF310 00000000 */   nop   
.L7F0CF314:
/* 103E44 7F0CF314 02037021 */  addu  $t6, $s0, $v1
.L7F0CF318:
/* 103E48 7F0CF318 91CF0000 */  lbu   $t7, ($t6)
/* 103E4C 7F0CF31C 2652FFFF */  addiu $s2, $s2, -1
/* 103E50 7F0CF320 26100001 */  addiu $s0, $s0, 1
/* 103E54 7F0CF324 26B50001 */  addiu $s5, $s5, 1
/* 103E58 7F0CF328 1640FFEC */  bnez  $s2, .L7F0CF2DC
/* 103E5C 7F0CF32C A0AF0000 */   sb    $t7, ($a1)
.L7F0CF330:
/* 103E60 7F0CF330 5500FFC2 */  bnezl $t0, .L7F0CF23C
/* 103E64 7F0CF334 01009025 */   move  $s2, $t0
/* 103E68 7F0CF338 1000FF13 */  b     .L7F0CEF88
/* 103E6C 7F0CF33C 023F082B */   sltu  $at, $s1, $ra
.L7F0CF340:
/* 103E70 7F0CF340 3C018009 */  lui   $at, %hi(rz_wp)
/* 103E74 7F0CF344 AC35D35C */  sw    $s5, %lo(rz_wp)($at)
/* 103E78 7F0CF348 3C018009 */  lui   $at, %hi(rz_bb)
/* 103E7C 7F0CF34C AC34D364 */  sw    $s4, %lo(rz_bb)($at)
/* 103E80 7F0CF350 8FBF003C */  lw    $ra, 0x3c($sp)
/* 103E84 7F0CF354 3C018009 */  lui   $at, %hi(rz_bk)
/* 103E88 7F0CF358 AC31D368 */  sw    $s1, %lo(rz_bk)($at)
/* 103E8C 7F0CF35C 8FB1001C */  lw    $s1, 0x1c($sp)
/* 103E90 7F0CF360 8FB40028 */  lw    $s4, 0x28($sp)
/* 103E94 7F0CF364 8FB5002C */  lw    $s5, 0x2c($sp)
/* 103E98 7F0CF368 8FB00018 */  lw    $s0, 0x18($sp)
/* 103E9C 7F0CF36C 8FB20020 */  lw    $s2, 0x20($sp)
/* 103EA0 7F0CF370 8FB30024 */  lw    $s3, 0x24($sp)
/* 103EA4 7F0CF374 8FB60030 */  lw    $s6, 0x30($sp)
/* 103EA8 7F0CF378 8FB70034 */  lw    $s7, 0x34($sp)
/* 103EAC 7F0CF37C 8FBE0038 */  lw    $fp, 0x38($sp)
/* 103EB0 7F0CF380 27BD0070 */  addiu $sp, $sp, 0x70
/* 103EB4 7F0CF384 03E00008 */  jr    $ra
/* 103EB8 7F0CF388 00001025 */   move  $v0, $zero
)
#endif





#ifdef NONMATCHING
s32 zlib_inflate_stored(void)
{
	s32 n;           /* number of bytes in block */
	s32 w;           /* current window position */
	register u32 b;  /* bit buffer */
	register u32 k;  /* number of bits in bit buffer */
    
	/* make local copies of globals */
	b = rz_bb;                       /* initialize bit buffer */
	k = rz_bk;
	w = rz_wp;                       /* initialize window position */

	/* go to byte boundary */
	n = k & 7;
	DUMPBITS(n);

	/* get the length and its complement */
	NEEDBITS(16)
	n = (b & 0xffff);
	DUMPBITS(16)

	NEEDBITS(16)
    if (n != (unsigned)((~b) & 0xffff))
    {
        // removed
    }
	DUMPBITS(16)

	/* read and output the compressed data */
	while (n--)
    {
        /**
         * decomp problem area.
         * This while loop is incorrect.* 
        */

        u8 *outbuf = rz_outbuf;
        
		NEEDBITS(8)

        b >>= 8;

        if ((&outbuf[w] >= &rz_inbuf[rz_inptr]) && (u32)(&outbuf[w]) - (u32)(&rz_inbuf[rz_inptr]) < WSIZE) { while(1){} }

		outbuf[w++] = (u8)b;

        k -= 8;
        
        //DUMPBITS(8)
	}

	/* restore the globals from the locals */
	rz_wp = w;                       /* restore global window pointer */
	rz_bb = b;                       /* restore global bit buffer */
	rz_bk = k;

	return 0;
}
#else
GLOBAL_ASM(
.text
glabel zlib_inflate_stored
/* 103EBC 7F0CF38C 3C0B8009 */  lui   $t3, %hi(rz_bk) 
/* 103EC0 7F0CF390 256BD368 */  addiu $t3, %lo(rz_bk) # addiu $t3, $t3, -0x2c98
/* 103EC4 7F0CF394 8D640000 */  lw    $a0, ($t3)
/* 103EC8 7F0CF398 3C0A8009 */  lui   $t2, %hi(rz_bb) 
/* 103ECC 7F0CF39C 254AD364 */  addiu $t2, %lo(rz_bb) # addiu $t2, $t2, -0x2c9c
/* 103ED0 7F0CF3A0 30820007 */  andi  $v0, $a0, 7
/* 103ED4 7F0CF3A4 8D430000 */  lw    $v1, ($t2)
/* 103ED8 7F0CF3A8 3C0C8009 */  lui   $t4, %hi(rz_wp) 
/* 103EDC 7F0CF3AC 00822023 */  subu  $a0, $a0, $v0
/* 103EE0 7F0CF3B0 258CD35C */  addiu $t4, %lo(rz_wp) # addiu $t4, $t4, -0x2ca4
/* 103EE4 7F0CF3B4 27BDFFF0 */  addiu $sp, $sp, -0x10
/* 103EE8 7F0CF3B8 2C810010 */  sltiu $at, $a0, 0x10
/* 103EEC 7F0CF3BC AFB1000C */  sw    $s1, 0xc($sp)
/* 103EF0 7F0CF3C0 AFB00008 */  sw    $s0, 8($sp)
/* 103EF4 7F0CF3C4 8D850000 */  lw    $a1, ($t4)
/* 103EF8 7F0CF3C8 1020000F */  beqz  $at, .L7F0CF408
/* 103EFC 7F0CF3CC 00431806 */   srlv  $v1, $v1, $v0
/* 103F00 7F0CF3D0 3C068009 */  lui   $a2, %hi(rz_inbuf)
/* 103F04 7F0CF3D4 3C0D8009 */  lui   $t5, %hi(rz_inptr) 
/* 103F08 7F0CF3D8 25ADD358 */  addiu $t5, %lo(rz_inptr) # addiu $t5, $t5, -0x2ca8
/* 103F0C 7F0CF3DC 8CC6D350 */  lw    $a2, %lo(rz_inbuf)($a2)
.L7F0CF3E0:
/* 103F10 7F0CF3E0 8DA70000 */  lw    $a3, ($t5)
/* 103F14 7F0CF3E4 00C77021 */  addu  $t6, $a2, $a3
/* 103F18 7F0CF3E8 91CF0000 */  lbu   $t7, ($t6)
/* 103F1C 7F0CF3EC 24F90001 */  addiu $t9, $a3, 1
/* 103F20 7F0CF3F0 ADB90000 */  sw    $t9, ($t5)
/* 103F24 7F0CF3F4 008FC004 */  sllv  $t8, $t7, $a0
/* 103F28 7F0CF3F8 24840008 */  addiu $a0, $a0, 8
/* 103F2C 7F0CF3FC 2C810010 */  sltiu $at, $a0, 0x10
/* 103F30 7F0CF400 1420FFF7 */  bnez  $at, .L7F0CF3E0
/* 103F34 7F0CF404 00781825 */   or    $v1, $v1, $t8
.L7F0CF408:
/* 103F38 7F0CF408 2484FFF0 */  addiu $a0, $a0, -0x10
/* 103F3C 7F0CF40C 3C0D8009 */  lui   $t5, %hi(rz_inptr) 
/* 103F40 7F0CF410 3062FFFF */  andi  $v0, $v1, 0xffff
/* 103F44 7F0CF414 00037402 */  srl   $t6, $v1, 0x10
/* 103F48 7F0CF418 2C810010 */  sltiu $at, $a0, 0x10
/* 103F4C 7F0CF41C 25ADD358 */  addiu $t5, %lo(rz_inptr) # addiu $t5, $t5, -0x2ca8
/* 103F50 7F0CF420 1020000D */  beqz  $at, .L7F0CF458
/* 103F54 7F0CF424 01C01825 */   move  $v1, $t6
/* 103F58 7F0CF428 3C068009 */  lui   $a2, %hi(rz_inbuf)
/* 103F5C 7F0CF42C 8CC6D350 */  lw    $a2, %lo(rz_inbuf)($a2)
.L7F0CF430:
/* 103F60 7F0CF430 8DA70000 */  lw    $a3, ($t5)
/* 103F64 7F0CF434 00C77821 */  addu  $t7, $a2, $a3
/* 103F68 7F0CF438 91F80000 */  lbu   $t8, ($t7)
/* 103F6C 7F0CF43C 24EE0001 */  addiu $t6, $a3, 1
/* 103F70 7F0CF440 ADAE0000 */  sw    $t6, ($t5)
/* 103F74 7F0CF444 0098C804 */  sllv  $t9, $t8, $a0
/* 103F78 7F0CF448 24840008 */  addiu $a0, $a0, 8
/* 103F7C 7F0CF44C 2C810010 */  sltiu $at, $a0, 0x10
/* 103F80 7F0CF450 1420FFF7 */  bnez  $at, .L7F0CF430
/* 103F84 7F0CF454 00791825 */   or    $v1, $v1, $t9
.L7F0CF458:
/* 103F88 7F0CF458 00403025 */  move  $a2, $v0
/* 103F8C 7F0CF45C 00037C02 */  srl   $t7, $v1, 0x10
/* 103F90 7F0CF460 01E01825 */  move  $v1, $t7
/* 103F94 7F0CF464 2484FFF0 */  addiu $a0, $a0, -0x10
/* 103F98 7F0CF468 10400027 */  beqz  $v0, .L7F0CF508
/* 103F9C 7F0CF46C 2442FFFF */   addiu $v0, $v0, -1
/* 103FA0 7F0CF470 3C108009 */  lui   $s0, %hi(rz_outbuf)
/* 103FA4 7F0CF474 2610D354 */  addiu $s0, %lo(rz_outbuf) # addiu $s0, $s0, -0x2cac
/* 103FA8 7F0CF478 34118000 */  li    $s1, 32768
.L7F0CF47C:
/* 103FAC 7F0CF47C 3C068009 */  lui   $a2, %hi(rz_inbuf)
/* 103FB0 7F0CF480 2C810008 */  sltiu $at, $a0, 8
/* 103FB4 7F0CF484 1020000B */  beqz  $at, .L7F0CF4B4
/* 103FB8 7F0CF488 8CC6D350 */   lw    $a2, %lo(rz_inbuf)($a2)
.L7F0CF48C:
/* 103FBC 7F0CF48C 8DA70000 */  lw    $a3, ($t5)
/* 103FC0 7F0CF490 00C7C021 */  addu  $t8, $a2, $a3
/* 103FC4 7F0CF494 93190000 */  lbu   $t9, ($t8)
/* 103FC8 7F0CF498 24EF0001 */  addiu $t7, $a3, 1
/* 103FCC 7F0CF49C ADAF0000 */  sw    $t7, ($t5)
/* 103FD0 7F0CF4A0 00997004 */  sllv  $t6, $t9, $a0
/* 103FD4 7F0CF4A4 24840008 */  addiu $a0, $a0, 8
/* 103FD8 7F0CF4A8 2C810008 */  sltiu $at, $a0, 8
/* 103FDC 7F0CF4AC 1420FFF7 */  bnez  $at, .L7F0CF48C
/* 103FE0 7F0CF4B0 006E1825 */   or    $v1, $v1, $t6
.L7F0CF4B4:
/* 103FE4 7F0CF4B4 8E180000 */  lw    $t8, ($s0)
/* 103FE8 7F0CF4B8 8DB90000 */  lw    $t9, ($t5)
/* 103FEC 7F0CF4BC 00037A02 */  srl   $t7, $v1, 8
/* 103FF0 7F0CF4C0 03053821 */  addu  $a3, $t8, $a1
/* 103FF4 7F0CF4C4 00D94821 */  addu  $t1, $a2, $t9
/* 103FF8 7F0CF4C8 00E9082B */  sltu  $at, $a3, $t1
/* 103FFC 7F0CF4CC 14200007 */  bnez  $at, .L7F0CF4EC
/* 104000 7F0CF4D0 00E04025 */   move  $t0, $a3
/* 104004 7F0CF4D4 01097023 */  subu  $t6, $t0, $t1
/* 104008 7F0CF4D8 01D1082B */  sltu  $at, $t6, $s1
/* 10400C 7F0CF4DC 50200004 */  beql  $at, $zero, .L7F0CF4F0
/* 104010 7F0CF4E0 00403025 */   move  $a2, $v0
.L7F0CF4E4:
/* 104014 7F0CF4E4 1000FFFF */  b     .L7F0CF4E4
/* 104018 7F0CF4E8 00000000 */   nop   
.L7F0CF4EC:
/* 10401C 7F0CF4EC 00403025 */  move  $a2, $v0
.L7F0CF4F0:
/* 104020 7F0CF4F0 A0E30000 */  sb    $v1, ($a3)
/* 104024 7F0CF4F4 24A50001 */  addiu $a1, $a1, 1
/* 104028 7F0CF4F8 01E01825 */  move  $v1, $t7
/* 10402C 7F0CF4FC 2484FFF8 */  addiu $a0, $a0, -8
/* 104030 7F0CF500 1440FFDE */  bnez  $v0, .L7F0CF47C
/* 104034 7F0CF504 2442FFFF */   addiu $v0, $v0, -1
.L7F0CF508:
/* 104038 7F0CF508 8FB00008 */  lw    $s0, 8($sp)
/* 10403C 7F0CF50C 8FB1000C */  lw    $s1, 0xc($sp)
/* 104040 7F0CF510 AD850000 */  sw    $a1, ($t4)
/* 104044 7F0CF514 AD430000 */  sw    $v1, ($t2)
/* 104048 7F0CF518 AD640000 */  sw    $a0, ($t3)
/* 10404C 7F0CF51C 27BD0010 */  addiu $sp, $sp, 0x10
/* 104050 7F0CF520 03E00008 */  jr    $ra
/* 104054 7F0CF524 00001025 */   move  $v0, $zero
)
#endif






s32 zlib_inflate_fixed(void)
{
	s32 i;                /* temporary variable */
	struct huft *tl;      /* literal/length code table */
	struct huft *td;      /* distance code table */
	s32 bl;               /* lookup bits for tl */
	s32 bd;               /* lookup bits for td */
	u32 l[288];           /* length list for zlib_huft_build */

	/* set up literal table */
	for (i = 0; i < 144; i++) {
		l[i] = 8;
	}
	for (; i < 256; i++) {
		l[i] = 9;
	}
	for (; i < 280; i++) {
		l[i] = 7;
	}
	for (; i < 288; i++) {
		l[i] = 8;
	}

	bl = 7;

	zlib_huft_build(l, 288, 257, rz_cplens, rz_cplext, &tl, &bl);

	/* set up distance table */
	for (i = 0; i < 30; i++) {
		l[i] = 5;
	}

	bd = 5;

	/* decompress until an end-of-block code */
	zlib_huft_build(l, 30, 0, rz_cpdist, rz_cpdext, &td, &bd);

	zlib_inflate_codes(tl, td, bl, bd);

	return 0;
}


s32 zlib_inflate_dynamic(void)
{
	s32 i;                /* temporary variables */
	u32 j;
	u32 l;           /* last length */
	u32 m;           /* mask for bit lengths table */
	u32 n;           /* number of lengths to get */
	struct huft *tl;      /* literal/length code table */
	struct huft *td;      /* distance code table */
	s32 bl;               /* lookup bits for tl */
	s32 bd;               /* lookup bits for td */
	u32 nb;          /* number of bit length codes */
	u32 nl;          /* number of literal/length codes */
	u32 nd;          /* number of distance codes */
	register u32 k;  /* number of bits in bit buffer */
	register u32 b;  /* bit buffer */
	u32 ll[286+30];  /* literal/length and distance code lengths */

	/* make local bit buffer */
	b = rz_bb;
	k = rz_bk;

	/* read in table lengths */
	NEEDBITS(5)
	nl = 257 + (b & 0x1f);      /* number of literal/length codes */
	DUMPBITS(5)
	NEEDBITS(5)
	nd = 1 + (b & 0x1f);        /* number of distance codes */
	DUMPBITS(5)
	NEEDBITS(4)
	nb = 4 + (b & 0xf);         /* number of bit length codes */
	DUMPBITS(4)

	/* read in bit-length-code lengths */
	for (j = 0; j < nb; j++)
    {
		NEEDBITS(3)
		ll[rz_border[j]] = b & 7;
		DUMPBITS(3)
	}

	for (; j < 19; j++)
    {
		ll[rz_border[j]] = 0;
	}

	/* build decoding table for trees--single level, 7 bit lookup */
	bl = 7;

	zlib_huft_build(ll, 19, 19, NULL, NULL, &tl, &bl);

	/* read in literal and distance code lengths */
	n = nl + nd;
	m = rz_mask_bits[bl];
	i = l = 0;

	while (i < n) {
		NEEDBITS(bl)
		j = (td = tl + (b & m))->b;
		DUMPBITS(j)

		j = td->v.n;

		if (j < 16) {                 /* length of code in bits (0..15) */
			ll[i++] = l = j;          /* save last length in l */
		} else if (j == 16) {         /* repeat last length 3 to 6 times */
			NEEDBITS(2)
			j = 3 + (b & 3);
			DUMPBITS(2)

			while (j--) {
				ll[i++] = l;
			}
		} else if (j == 17) {         /* 3 to 10 zero length codes */
			NEEDBITS(3)
			j = 3 + (b & 7);
			DUMPBITS(3)

			while (j--) {
				ll[i++] = 0;
			}

			l = 0;
		} else {                      /* j == 18: 11 to 138 zero length codes */
			NEEDBITS(7)
			j = 11 + (b & 0x7f);
			DUMPBITS(7)

			while (j--) {
				ll[i++] = 0;
			}

			l = 0;
		}
	}

	/* restore the global bit buffer */
	rz_bb = b;
	rz_bk = k;

	/* build the decoding tables for literal/length and distance codes */
	bl = rz_lbits;

	zlib_huft_build(ll, nl, 257, rz_cplens, rz_cplext, &tl, &bl);

	bd = rz_dbits;

	zlib_huft_build(ll + nl, nd, 0, rz_cpdist, rz_cpdext, &td, &bd);

	/* decompress until an end-of-block code */
	zlib_inflate_codes(tl, td, bl, bd);

	return 0;
}


s32 zlib_inflate_block(s32 *e)
{
	u32 t;                   /* block type */
	register u32 b = rz_bb;  /* bit buffer */
	register u32 k = rz_bk;  /* number of bits in bit buffer */

	/* make local bit buffer */
	b = rz_bb;
	k = rz_bk;

	/* read in last block bit */
	NEEDBITS(1)
	*e = b & 1;
	DUMPBITS(1)

	/* read in last block type */
	NEEDBITS(2)
	t = b & 3;
	DUMPBITS(2)

	/* restore the global bit buffer */
	rz_bb = b;
	rz_bk = k;

	/* inflate that block type */
	if (t == 2)
    {
		return zlib_inflate_dynamic();
	}

	if (t == 0)
    {
		return zlib_inflate_stored();
	}

	if (t == 1)
    {
		return zlib_inflate_fixed();
	}

	/* bad block type */
	return 2;
}



int zlib_inflate(void)
{
    /* last block flag */
    int e;

    /* result code */
    int r;

    /* maximum struct huft's malloc'ed */
    unsigned h;

    /* initialize window, bit buffer */
    rz_wp = 0;
    rz_bk = 0;
    rz_bb = 0;

    /* decompress until the last block */
    h = 0;

    do
    {
        rz_hufts = 0;
        
        if ((r = zlib_inflate_block(&e)) != 0)
        {
            return r;
        }
        
        if (rz_hufts > h)
        {
            h = rz_hufts;
        }
    } while (!e);

    /* Undo too much lookahead. The next read will be byte aligned so we
    * can discard unused bits in the last meaningful byte.
    */
    while (rz_bk >= 8)
    {
        rz_bk -= 8;
        rz_inptr--;
    }

    return 0;
}
