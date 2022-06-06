#ifndef _TOKEN_H_
#define _TOKEN_H_

#include <ultra64.h>

#if defined(LEFTOVERDEBUG)
#define G_TOKEN_STRING_LEN 160
#else
#define G_TOKEN_STRING_LEN 15
#endif

void tokenSetString(const char *str);
s32 tokenReadIo(void);

/**
* Attempts to find the specified token in g_Tokens. If successful,
* returns a pointer to the start of the value following the token,
* otherwise it returns NULL. E.g. if the token string was "-abc 123", then 
* tokenFind(1, "-abc") would return " 123". The index is used in cases where
* the same token appears multiple times. Note that the index is 1-based.
*/
const char *tokenFind(s32 index, const char *token);

#endif
