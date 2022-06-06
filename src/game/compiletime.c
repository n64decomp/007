#include <ultra64.h>
#include "compiletime.h"

#ifdef VERSION_US
char *get_compile_time(void) {
    return "Jun 29 1997 20:46:05";
}
#elif VERSION_EU
char *get_compile_time(void) {
    return "Jul 31 1997 14:53:03";
}
#elif VERSION_JP
char *get_compile_time(void) {
    return "Jul 10 1997 14:53:37";
}
#else
char *get_compile_time(void) {
    return __DATE__" " __TIME__;
}
#endif

