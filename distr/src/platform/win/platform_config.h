/*
 * This headers defines setting and functions that might be different for each
 * different platform b2fJ is ported to.
 *
*/
#ifndef _PLATFORM_CONFIG_H_
#define _PLATFORM_CONFIG_H_

#include <stddef.h>
#include <stdint.h>

/***********************************************************************************************************
 * Compiler specific settings.
 ***********************************************************************************************************/

 /* Primitive data types */

typedef uint8_t		byte;		/* 8 bit unsigned */
typedef int8_t		JBYTE;		/* Java byte (8 bit signed) */
typedef int16_t		JSHORT;		/* Java short (16 bit signed) */
typedef int32_t		JINT;		/* Java int (32 bit signed) */
typedef uint16_t	TWOBYTES;	/* 2 bytes (unsigned) */
typedef uint32_t	FOURBYTES;	/* 4 bytes (unsigned) */
typedef FOURBYTES   NATIVEWORD; /* 8 bytes (unsigned) */

#define __INLINED			inline		/* Used to mark a method "inline" */

/* To align with Java, the C structures we use must be packed. */
#define __PACKED(DEC)		__pragma(pack(push, 1)) DEC __pragma(pack(pop))

#define __TWOBYTE_BITFIELD	uint16_t	/* A 16 bits bitfield */

/***********************************************************************************************************
* Platform specific settings.
***********************************************************************************************************/

#define LITTLE_ENDIAN	1	/* Is the platform little endian? */


/***********************************************************************************************************
* VM settings.
***********************************************************************************************************/

/* Max size (in TWOBYTES words) for Java Heap. The JVM will try to allocate this much memory for heap at startup. */
#define MAX_HEAP_SIZE		((size_t)(65536 / sizeof(TWOBYTES)))

#define SEGMENTED_HEAP		0	/* If not 0 allow multiple heap segments (heap split in pieces) */
#define COALESCE			0	/* If not 0, coalesce adjacent free blocks in the heap */

#define FIXED_STACK_SIZE	0
#if FIXED_STACK_SIZE
	/**
	* Initial level of recursion.
	*/
	#define INITIAL_STACK_FRAMES	10

	/**
	* Initial number of words in a thread's stack
	* (for both locals and operands). Needs to be an
	* even number.
	*/
	#define INITIAL_STACK_SIZE		70
#else
	#define INITIAL_STACK_FRAMES	4
	#define INITIAL_STACK_SIZE		10
#endif

/* If not 0, threads in the DEAD state are  removed from the circular list. Recommended. */
#define REMOVE_DEAD_THREADS			1	

/* Set to non-zero if we want the scheduler to perform priority inversion avoidance (???) */
#define PI_AVOIDANCE				1

#define TICKS_PER_TIME_SLICE		16	/* After this number of instructions, switch thread */

#define FP_ARITHMETIC				0	/* Used to enable/disable floating point math */
#define WIMPY_MATH					0	/* ??? leave this 0 */

#define RECORD_REFERENCES			1	/* ??? leave this 1 */

#define SAFE                        1	/* Slightly safer code (???) leave this 1 */

/**
 * If not 0, use a garbage collector. It consumes about
 * 1000 bytes of code and about 1800 bytes of working ram .
 */
#define GARBAGE_COLLECTOR                1

 /**
  * Max number of VM objects that we need to protect, from the gc.
  */
#define MAX_VM_REFS                      8

/* VM debug settings */

#define ASSERTIONS_ENABLED	0	/* If false, disables all assertions */

#define DEBUG_STARTUP		0
#define DEBUG_MEMORY		0
#define DEBUG_THREADS		0
#define DEBUG_METHODS		0
#define DEBUG_BYTECODE		0
#define DEBUG_FIELDS		0
#define DEBUG_OBJECTS		0
#define DEBUG_EXCEPTIONS	0
#define DEBUG_MONITOR		0
#define DEBUG_JAVA			0
#define DEBUG_COLLECTOR     0
#define DEBUG_MAPPING       0

#endif // _PLATFORM_CONFIG_H_
