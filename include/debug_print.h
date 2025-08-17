// near other includes
#include "mgba.h"  // present in pokéemerald trees that support the mGBA logger

#ifndef DEBUG_PRINT
// Info-level by default; tweak to MGBA_LOG_DEBUG if you want more noise.
#define DEBUG_PRINT(fmt, ...) do { \
    MgbaPrintf(MGBA_LOG_INFO, fmt, ##__VA_ARGS__); \
} while (0)
#endif
