#pragma once

enum MgbaLogLevel {
    MGBA_LOG_FATAL,
    MGBA_LOG_ERROR,
    MGBA_LOG_WARN,
    MGBA_LOG_INFO,
    MGBA_LOG_DEBUG,
    MGBA_LOG_STUB,
};

#ifdef __cplusplus
extern "C" {
#endif

void SpyMgbaOpen(void);
int SpyMgbaPrintf(enum MgbaLogLevel level, const char *fmt, ...);

#ifdef __cplusplus
}
#endif
