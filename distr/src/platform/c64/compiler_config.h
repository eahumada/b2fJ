/*
 * This defines some macro related to different compile behaviors.
 * 
 * __PACKED() macro that can be used to pack structs using both VS and GCC that use different approaces.
 * 
*/
#ifndef _COMPILER_CONFIG_H_
#define _COMPILER_CONFIG_H_

#define __INLINED 
#define __BYTE_BITFIELD int 
#define __TWOBYTE_BITFIELD int

// GCC (original code)
// #define __INLINED inline
// #define __BITFIELD byte
// #define __TWOBYTE_BITFIELD TWOBYTES

#endif // _COMPILER_CONFIG_H_
