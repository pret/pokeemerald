#ifndef GUARD_GBA_ISAGBPRINT_H
#define GUARD_GBA_ISAGBPRINT_H

#ifdef NDEBUG
#define AGBPrintInit()
#define AGBPutc(cChr)
#define AGBPrint(pBuf)
#define AGBPrintf(pBuf, ...)
#define AGBPrintFlush1Block()
#define AGBPrintFlush()
#define AGBAssert(pFile, nLine, pExpression, nStopProgram)
#else
void AGBPrintInit(void);
void AGBPutc(const char cChr);
void AGBPrint(const char *pBuf);
void AGBPrintf(const char *pBuf, ...);
void AGBPrintFlush1Block(void);
void AGBPrintFlush(void);
void AGBAssert(const char *pFile, int nLine, const char *pExpression, int nStopProgram);
#endif

#undef AGB_ASSERT
#ifdef NDEBUG
#define AGB_ASSERT(exp)
#else
#define AGB_ASSERT(exp) (exp) ? ((void *)0) : AGBAssert(__FILE__, __LINE__, #exp, 1);
#endif

#undef AGB_WARNING
#ifdef NDEBUG
#define AGB_WARNING(exp)
#else
#define AGB_WARNING(exp) (exp) ? ((void *)0) : AGBAssert(__FILE__, __LINE__, #exp, 0);
#endif

// for matching purposes

#ifdef NDEBUG
#define    AGB_ASSERT_EX(exp, file, line)
#else
#define    AGB_ASSERT_EX(exp, file, line) (exp) ? ((void *)0) : AGBAssert(file, line, #exp, 1);
#endif

#ifdef NDEBUG
#define    AGB_WARNING_EX(exp, file, line)
#else
#define    AGB_WARNING_EX(exp, file, line) (exp) ? ((void *)0) : AGBAssert(file, line, #exp, 0);
#endif

#endif // GUARD_GBA_ISAGBPRINT_H
