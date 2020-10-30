#pragma once

// EXTERNAL INCLUDES
#include <inttypes.h>
// INTERNAL INCLUDES

typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef uint64_t size;

typedef unsigned char byte;

typedef char ansichar;
typedef const char* ansistring;
typedef void* voidptr;

#ifdef GE_DOUBLE_PRECISION
typedef double real;
#else
typedef float real;
#endif
