#pragma once

// EXTERNAL INCLUDES
#include <cassert>
#include <cstdio>
// INTERNAL INCLUDES
#include "basetypes.h"

#if defined(ENGINE_COMPILE_DEBUG)
#   define DebugLog(str, ...)                      \
{                                               \
    ansichar string[256];                       \
    snprintf(string, 256, str, __VA_ARGS__);    \
    printf("[INFO]: %s\n", string);             \
}
#define DebugWarn(str, ...)                                                \
{                                                                       \
    ansichar string[256];                                               \
    snprintf(string, 256, str, __VA_ARGS__);                            \
    printf("[WARNING]: %s (%s #%i)\n", string, __FILE__, __LINE__);     \
}
#define DebugErr(str, ...)                                                 \
{                                                                       \
    ansichar string[256];                                               \
    snprintf(string, 256, str, ##__VA_ARGS__);                          \
    printf("[ERROR]: %s (%s #%i)\n", string, __FILE__, __LINE__);       \
	exit(EXIT_FAILURE);													\
}
#else
#   define DebugLog(str, ...) NULL
#   define DebugWarn(str, ...) NULL
#   define DebugErr(str, ...) NULL
#endif

#if defined(ENGINE_COMPILE_DEBUG)
#define DebugAssert(expr) assert(expr)
#else
#define DebugAssert(expr)
#endif
