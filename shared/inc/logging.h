#pragma once

// EXTERNAL INCLUDES
#include <cassert>
#include <cstdio>
// INTERNAL INCLUDES
#include "basetypes.h"

#if defined(ENGINE_COMPILE_DEBUG)
#   define AELog(str, ...)                      \
{                                               \
    ansichar string[256];                       \
    snprintf(string, 256, str, __VA_ARGS__);    \
    printf("[INFO]: %s\n", string);             \
}
#define AEWarn(str, ...)                                                \
{                                                                       \
    ansichar string[256];                                               \
    snprintf(string, 256, str, __VA_ARGS__);                            \
    printf("[WARNING]: %s (%s #%i)\n", string, __FILE__, __LINE__);     \
}
#define AEErr(str, ...)                                                 \
{                                                                       \
    ansichar string[256];                                               \
    snprintf(string, 256, str, ##__VA_ARGS__);                          \
    printf("[ERROR]: %s (%s #%i)\n", string, __FILE__, __LINE__);       \
	exit(EXIT_FAILURE);													\
}
#else
#   define AELog(str, ...) NULL
#   define AEWarn(str, ...) NULL
#   define AEErr(str, ...) NULL
#endif

#if defined(ENGINE_COMPILE_DEBUG)
#define AEDebugAssert(expr) assert(expr)
#else
#define AEDebugAssert(expr)
#endif
