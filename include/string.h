#ifndef _STRING_H_
#define _STRING_H_
#include <PR/ultratypes.h>

extern void *memcpy(void *, const void *, size_t);
extern unsigned char *strchr(const unsigned char *, int);
extern size_t strlen(const unsigned char *);

#endif
