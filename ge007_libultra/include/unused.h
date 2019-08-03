#ifndef _UNUSED_H_
#define _UNUSED_H_

// Avoid compiler warnings for unused variables
#ifdef __GNUC__
#define UNUSED __attribute__((unused))
#else
#define UNUSED
#endif


#endif 
