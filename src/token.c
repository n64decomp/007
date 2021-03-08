#include "token.h"
#include "pi.h"
#include "snd.h"
#include "game/lvl_text.h"
#include "rmon.h"
#include "str.h"

u32 g_TokenString[160];
s32 g_TokenCount = 1;
const char *g_Tokens[35] = {0};

// Splits a string into tokens delimited by spaces and stores 
// them in g_Tokens.
unsigned char *tokenSplit(unsigned char *str)
{
    unsigned char c;
    g_Tokens[0] = "";
    g_TokenCount = 1;
    while ((s32)*str) {
        while (*str == ' ') {
            *str++ = '\0';
        }
        g_Tokens[g_TokenCount++] = str;
        while (*str > ' ') {
            str++; 
        }
    }
    return str;
}

// Sets a new token string.
void tokenSetString(const char *str) {
    strcpy(g_TokenString, str);
    tokenSplit(g_TokenString);
}

// Reads a new token string from the PI device at address 0xFFB000. Also handles the 
// -d (debug), -s (sound) and -j (japanese) switches.
s32 tokenReadIo(void)
{
    u32 *ptr;
    u32 *end;
    u32 address;
    s32 debug = FALSE;
    address = 0xFFB000;
    if (rmonIsFinalBuild()) {
        g_TokenString[0] = 0;
    } else {
        for (ptr = g_TokenString, end = (g_TokenString + 160); (ptr != end); ptr++) {
            osPiReadIo(address, ptr);
            address += sizeof(u32);
        }
    }
    tokenSplit(g_TokenString);
    if (tokenFind(1, "-d") != NULL) {
        debug = TRUE;
    }
    if (tokenFind(1, "-s") != NULL) {
        bootswitch_sound = TRUE;
    }
    if (tokenFind(1, "-j") != NULL) {
        j_text_trigger = TRUE;
    }
    return debug;
}

// Attempts to find the specified token in g_Tokens. If successful,
// returns a pointer to the start of the value following the token,
// otherwise it returns NULL. E.g. if the token string was "-abc 123", then 
// tokenFind(1, "-abc") would return " 123". The index is used in cases where
// the same token appears multiple times. Note that the index is 1-based.
const char *tokenFind(s32 index, const char *token)
{
    s32 length = strlen(token);
    s32 i = 1;
    for (; i < g_TokenCount; i++) {
        if (strncmp(token, g_Tokens[i], length) == 0) {
            if (--index == 0) {
                return (g_Tokens[i] + length);
            }
        }
    }
    return NULL;
}
