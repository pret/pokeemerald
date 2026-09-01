#ifndef GUARD_GBA_ISAGBPRINT_H
#define GUARD_GBA_ISAGBPRINT_H

#include "gba/types.h"

#define MGBA_LOG_FATAL  (0)
#define MGBA_LOG_ERROR  (1)
#define MGBA_LOG_WARN   (2)
#define MGBA_LOG_INFO   (3)
#define MGBA_LOG_DEBUG  (4)

#ifdef NDEBUG
#define DebugPrintf(pBuf, ...)
#define DebugPrintfLevel(level, pBuf, ...)
#define MgbaOpen()
#define MgbaClose()
#define AGBPrintInit()
#define DebugAssert(pFile, nLine, pExpression, nStopProgram)
#else

bool32 MgbaOpen(void);
void MgbaClose(void);
void MgbaPrintf(s32 level, const char *pBuf, ...);
void MgbaAssert(const char *pFile, s32 nLine, const char *pExpression, bool32 nStopProgram);
void NoCashGBAPrintf(const char *pBuf, ...);
void NoCashGBAAssert(const char *pFile, s32 nLine, const char *pExpression, bool32 nStopProgram);
void AGBPrintf(const char *pBuf, ...);
void AGBAssert(const char *pFile, int nLine, const char *pExpression, int nStopProgram);
void AGBPrintInit(void);

#if (LOG_HANDLER == LOG_HANDLER_MGBA_PRINT)

#define DebugPrintf(pBuf, ...) MgbaPrintf(MGBA_LOG_WARN, pBuf, ## __VA_ARGS__)
#define DebugAssert(pFile, nLine, pExpression, nStopProgram) MgbaAssert(pFile, nLine, pExpression, nStopProgram)
#define DebugPrintfLevel(level, pBuf, ...) MgbaPrintf(level, pBuf, ## __VA_ARGS__)

#elif (LOG_HANDLER == LOG_HANDLER_NOCASH_PRINT)

#define DebugPrintf(pBuf, ...) NoCashGBAPrintf(pBuf, ## __VA_ARGS__)
#define DebugAssert(pFile, nLine, pExpression, nStopProgram) NoCashGBAAssert(pFile, nLine, pExpression, nStopProgram)
#define DebugPrintfLevel(level, pBuf, ...) NoCashGBAPrintf(pBuf, ## __VA_ARGS__)

#else // Default to AGBPrint

#define DebugPrintf(pBuf, ...) AGBPrintf(pBuf, ## __VA_ARGS__)
#define DebugAssert(pFile, nLine, pExpression, nStopProgram) AGBAssert(pFile, nLine, pExpression, nStopProgram)
#define DebugPrintfLevel(level, pBuf, ...) AGBPrintf(pBuf, ## __VA_ARGS__)

#endif
#endif

#ifdef NDEBUG

#define AGB_ASSERT(exp)
#define AGB_WARNING(exp)
#define AGB_ASSERT_EX(exp, file, line)
#define AGB_WARNING_EX(exp, file, line)

#else

#define AGB_ASSERT(exp) (exp) ? ((void*)0) : DebugAssert(__FILE__, __LINE__, #exp, TRUE)
#define AGB_WARNING(exp) (exp) ? ((void*)0) : DebugAssert(__FILE__, __LINE__, #exp, FALSE)

#define AGB_WARNING_EX(exp, file, line) (exp) ? ((void *)0) : DebugAssert(file, line, #exp, FALSE);
#define AGB_ASSERT_EX(exp, file, line) (exp) ? ((void *)0) : DebugAssert(file, line, #exp, TRUE);
#endif

#endif // GUARD_GBA_ISAGBPRINT_H
