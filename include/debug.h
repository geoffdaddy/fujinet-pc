#ifndef _DEBUG_H_
#define _DEBUG_H_

#include <string>

#include "ansi_codes.h"

// __PLATFORMIO_BUILD_DEBUG__ is set when build_type is set to debug in platformio.ini
#if defined(__PLATFORMIO_BUILD_DEBUG__) || defined(__PC_BUILD_DEBUG__) || defined(DBUG2)
#define DEBUG
#endif

#ifdef UNIT_TESTS
#undef DEBUG
#endif

#if defined(DEBUG) || !defined(NO_DEBUG_PRINT)
#include <utils.h>
/*
  Debugging Macros
*/
    #define Debug_print(...) util_debug_printf(nullptr, __VA_ARGS__)
    #define Debug_printf(...) util_debug_printf(__VA_ARGS__)
    #define Debug_println(...) util_debug_printf("%s\n", __VA_ARGS__)
    #define Debug_printv(format, ...) {util_debug_printf( ANSI_YELLOW "[%s:%u] %s(): " ANSI_GREEN_BOLD format ANSI_RESET "\r\n", __FILE__, __LINE__, __FUNCTION__, ##__VA_ARGS__);}

    #define HEAP_CHECK(x) Debug_printf("HEAP CHECK %s " x "\r\n", heap_caps_check_integrity_all(true) ? "PASSED":"FAILED")
#else
    #define Debug_print(...)
    #define Debug_printf(...)
    #define Debug_println(...)
    #define Debug_printv(format, ...)

    #define HEAP_CHECK(x)
#endif

#endif // _DEBUG_H_
