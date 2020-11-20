#include "ultra64.h"
#include "game/compiletime.h"

#ifdef VERSION_US
char *get_compile_time(void) {
    return "Jun 29 1997 20:46:05";
}
#endif

#ifdef VERSION_JP
char *get_compile_time(void) {
    return "Jul 10 1997 14:53:37";
}
#endif

