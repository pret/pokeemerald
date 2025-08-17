#pragma once

/* Keep this header tiny and C-only to avoid polluting the whole tree. */

enum SpyLogLevel {
    SPY_LOG_FATAL = 0,
    SPY_LOG_ERROR,
    SPY_LOG_WARN,
    SPY_LOG_INFO,
    SPY_LOG_DEBUG,
    SPY_LOG_STUB
};

/* Implemented in src/mgba.c */
void SpyMgbaOpen(void);
int  SpyMgbaPrintf(int level, const char *fmt, ...);

/* Parse-friendly helper used only by your spy code */
#define DEBUG_PRINT(fmt, ...) do { \
    SpyMgbaPrintf(SPY_LOG_INFO, fmt, ##__VA_ARGS__); \
} while (0)
