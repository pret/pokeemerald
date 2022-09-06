#ifndef GUARD_GBA_ISAGBPRINT_H
#define GUARD_GBA_ISAGBPRINT_H

#include "gba/types.h"

#ifdef NDEBUG
#define DebugPrintf(pBuf, ...)
#define MgbaOpen()
#define MgbaClose()
#define AGB_ASSERT(exp)
#define AGB_WARNING(exp)
#define AGBPrintInit()
#else
#if (LOG_HANDLER == LOG_HANDLER_MGBA_PRINT)
bool32 MgbaOpen(void);
void MgbaClose(void);
void MgbaPrintf(const char *pBuf, ...);
void MgbaAssert(const char *pFile, s32 nLine, const char *pExpression, bool32 nStopProgram);
#define DebugPrintf(pBuf, ...) MgbaPrintf(pBuf, __VA_ARGS__)
#define AGB_ASSERT(exp) (exp) ? ((void*)0) : MgbaAssert(__FILE__, __LINE__, #exp, 1)
#define AGB_WARNING(exp) (exp) ? ((void*)0) : MgbaAssert(__FILE__, __LINE__, #exp, 0)

// Not used in this configuration
#define AGBPrintfInit()
#elif (LOG_HANDLER == LOG_HANDLER_NOCASH_PRINT)
void NoCashGBAPrintf(const char *pBuf, ...)
void NoCashGBAAssert(const char *pFile, s32 nLine, const char *pExpression, bool32 nStopProgram)
#define DebugPrintf(pBuf, ...) NoCashGBAPrintf(pBuf, __VA_ARGS__)
#define AGB_ASSERT(exp) (exp) ? ((void*)0) : NoCashGBAAssert(__FILE__, __LINE__, #exp, 1);
#define AGB_WARNING(exp) (exp) ? ((void*)0) : NoCashGBAAssert(__FILE__, __LINE__, #exp, 0)

// Not used in this configuration
#define MgbaOpen()
#define MgbaClose()
#define AGBPrintInit()
#else // Default to AGBPrint
void AGBPrintf(const char *pBuf, ...);
void AGBAssert(const char *pFile, int nLine, const char *pExpression, int nStopProgram);
void AGBPrintInit(void);
#define DebugPrintf(pBuf, ...) AGBPrintf(const char *pBuf, ...)
#define AGB_ASSERT(exp) (exp) ? ((void*)0) : AGBAssert(__FILE__, __LINE__, #exp, 1)
#define AGB_WARNING(exp) (exp) ? ((void*)0) : NoCashGBAAssert(__FILE__, __LINE__, #exp, 0)

// Not used in this configuration
#define MgbaOpen()
#define MgbaClose()
#endif
#endif

// for matching purposes

#ifdef NDEBUG
#define    AGB_ASSERT_EX(exp, file, line)
#else
#define    AGB_ASSERT_EX(exp, file, line) AGB_ASSERT(exp);
#endif

#endif // GUARD_GBA_ISAGBPRINT_H
