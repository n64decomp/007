#include <stdarg.h>
#include "ultra64.h"
#include "deb_print.h"

/**
 * Removed
 */
void rmonMain(void) {
    // Removed
}

s32 rmonIsFinalBuild(void) {
    return TRUE;
}

/**
 * Removed
 */
s32 rmon7000CEB0(void) {
    // Removed
    return -1;
}

/**
 * Removed
 */
void rmon7000CEB8(void) {
    // Removed
}

/**
 * Removed
 */
void rmon7000CEC0(void) {
    // Removed
}

/**
 * Removed
 */
void rmon7000CEC8(void) {
    // Removed
}

/**
 * Removed
 */
void rmon7000CED0(void) {
    // Removed
}

/**
 * Removed
 */
void rmon7000CED8(void) {
    // Removed
}

/**
 * Removed
 */
void rmon7000CEE0(void) {
    // Removed
}

char *rmonprout(char *dst, const char *src, size_t count) {
    s32 i = 0;
    while (i != count) {
        deboutWriteChar(src[i++]);
    }    
    return 1;
}

s32 osSyncPrintf(const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    _Printf(&rmonprout, NULL, fmt, args);
}
