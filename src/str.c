#include "str.h"

char *strcpy(char *dst, const char *src) {
    unsigned char *ptr = dst;
    while(*ptr++ = *src++);
    return dst;
}

char *strncpy(char *dst, const char *src, size_t n) {
    unsigned char *ptr = dst;
    while((*ptr++ = *src++)) { 
        if (--n == 0) {
            break;
        }
    }
    while(n--) {
        (*ptr++) = '\0';
    }
    return dst;
}

char *strcat(char *dst, const char *src) {
    unsigned char *ptr = dst;
    while (*ptr) { ptr++; };
    while(*ptr++ = *src++);
    return dst;
}

int strcmp(const char* str1, const char* str2) {
    unsigned int var;
    unsigned char c1;
    unsigned char c2;
    while (TRUE) {
        var = c1 = *(str1++);
        if (var != (c2 = *str2)) {
            if (c1 < c2) {
                return -1;
            } else {
                return 1;
            }
        }
        if (c1 == '\0') {
            return 0;
        }
        str2++;
    }
}

int strncmp(const char *str1, const char *str2, size_t n) {
    unsigned int var;
    unsigned char c1;
    unsigned char c2;
    while (TRUE) {
        if (n == 0) {
            return 0;
        }
        n--;
        var = c1 = *str1++;
        if (var != (c2 = *str2)) {
            if (c1 < c2) {
                return -1;
            } else {
                return 1;
            }
        }
        if (c1 == '\0') {
            return 0;
        }
        str2++;
    }
}

unsigned char toupper(unsigned char c) {
    if ((c >= 'a') && (c <= 'z')) {
        return ('A' + c - 'a');
    } else {
        return c;
    }
}

int isdigit(unsigned char c) {
    return ((c >= '0') && (c <= '9'));
}

int isalpha(unsigned char c) {
    return (((c >= 'a') && (c <= 'z')) || 
            ((c >= 'A') && (c <= 'Z')));
}

int isspace(unsigned char c) {
    return ((c == ' ') || (c == '\t') || (c == '\n') || (c == '\f') || (c == '\v'));
}

#define	ULONG_MAX ((unsigned long)(~0L)) /* 0xFFFFFFFF */
long int strtol(const char *str, char **endptr, int base) {
    int neg;
    unsigned char *ptr;
    unsigned int cutoff;
    unsigned int cutlim;
    unsigned int accum;
    unsigned char c;
    unsigned char *before;
    int overflow;
    if ((base < 0) || (base == 1) || (base > 36)) {
        base = 10;
    }
    ptr = str;
    while (isspace(*ptr)) { ptr++; };
    if ((int)*ptr) {
        if (*ptr == '-') {
            neg = 1;
            ptr++;
        } else if (*ptr == '+') {
            neg = 0;
            ptr++;
        } else {
            neg = 0;
        }
        if (base == 16) {
            if ((ptr[0] == '0') && (toupper(ptr[1]) == 'X')) {
                ptr += 2;
            }
        }
        if (base == 0) {
            if (ptr[0] == '0') {
                if (toupper(ptr[1]) == 'X') {
                    ptr += 2;
                    base = 16;
                } else {                    
                    base = 8;
                }
            } else {
                base = 10;
            }
        }
        before = ptr;
        overflow = 0;
        accum = 0;
        cutoff = ULONG_MAX / base;
        cutlim = ULONG_MAX % base;
        for (; (int)(c = *ptr); ptr++) {
            if (isdigit(c)) {
                c -= '0';
            } else if (isalpha(c)) {
                c = (toupper(c) - ('A' - 0xA));
            } else {
                break;
            }
            if (c >= base) {
                break;
            }
            if ((accum > cutoff) || ((accum == cutoff) && ((unsigned int)c > cutlim))) {
                overflow = 1;
            } else {
                accum *= base;
                accum += (unsigned int)c;
            }
        }
        if (ptr != before) {
            if (endptr != NULL) {
                *endptr = ptr;
            }
            if (overflow) {
                return -1;
            }
            return (neg ? -accum : accum);
        }
    }
    if (endptr != NULL) {
        *endptr = str;
    }
    return 0;
}
