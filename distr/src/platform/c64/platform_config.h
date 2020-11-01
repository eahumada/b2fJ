#ifndef _PLATFORM_CONFIG_H
#define _PLATFORM_CONFIG_H

#include <time.h>
#include "compiler_config.h"

/*
Using cc65

sizeof primitive types

char 1
short 2
int 2
long 4
*/
typedef unsigned char byte;
typedef signed char JBYTE;
typedef signed short JSHORT;
typedef signed long JINT;
typedef unsigned short TWOBYTES;
typedef unsigned long FOURBYTES;

/* This returns current time in millis */
#define get_sys_time() ((FOURBYTES)(clock() * 1000 / CLOCKS_PER_SEC))

#ifndef LITTLE_ENDIAN
#define LITTLE_ENDIAN 1
#endif

#define FP_ARITHMETIC 0
#define TICKS_PER_TIME_SLICE          16 /* Actually instructions per timeslice */
#define VERIFY
#define RECORD_REFERENCES 1

#endif // _PLATFORM_CONFIG_H
