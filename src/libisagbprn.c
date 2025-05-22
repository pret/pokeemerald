#include <stdarg.h>
#include <stdio.h>
#include "gba/gba.h"
#include "config.h"
#include "malloc.h"
#include "mini_printf.h"

#define AGB_PRINT_FLUSH_ADDR 0x9FE209D
#define AGB_PRINT_STRUCT_ADDR 0x9FE20F8
#define AGB_PRINT_PROTECT_ADDR 0x9FE2FFE
#define WSCNT_DATA (WAITCNT_PHI_OUT_16MHZ | WAITCNT_WS0_S_2 | WAITCNT_WS0_N_4)

// originally for auto no$gba support, the string "no$gba" should be at this address,
// the user needs to read this string out as the memory viewer won't show it.
#define NOCASHGBAIDADDR 0x4FFFA00
#define NOCASHGBAPRINTADDR1 0x4FFFA10 // automatically adds a newline after the string has finished
#define NOCASHGBAPRINTADDR2 0x4FFFA14 // does not automatically add the newline. by default, NOCASHGBAPRINTADDR2 is used. this is used to keep strings consistent between no$gba and VBA-RR, but a user can choose to forgo this.

// hardware extensions for LOG_HANDLER_MGBA_PRINT
#define REG_DEBUG_ENABLE ((vu16*) (0x4FFF780)) // handshake: (w)[0xC0DE] -> (r)[0x1DEA]
#define REG_DEBUG_FLAGS  ((vu16*) (0x4FFF700))
#define REG_DEBUG_STRING ((char*) (0x4FFF600))

struct AGBPrintStruct
{
    u16 m_nRequest;
    u16 m_nBank;
    u16 m_nGet;
    u16 m_nPut;
};

typedef void (*LPFN_PRINT_FLUSH)(void);

#ifndef NDEBUG

// AGBPrint print functions
#if (LOG_HANDLER == LOG_HANDLER_AGB_PRINT)
void AGBPrintFlush1Block(void);

void AGBPrintInit(void)
{
    volatile struct AGBPrintStruct *pPrint = (struct AGBPrintStruct *)AGB_PRINT_STRUCT_ADDR;
    vu16 *pWSCNT = &REG_WAITCNT;
    u16 *pProtect = (u16 *)AGB_PRINT_PROTECT_ADDR;
    u16 nOldWSCNT = *pWSCNT;
    *pWSCNT = WSCNT_DATA;
    *pProtect = 0x20;
    pPrint->m_nRequest = pPrint->m_nGet = pPrint->m_nPut = 0;
    pPrint->m_nBank = 0xFD;
    *pProtect = 0;
    *pWSCNT = nOldWSCNT;
}

static void AGBPutcInternal(const char cChr)
{
    volatile struct AGBPrintStruct *pPrint = (struct AGBPrintStruct *)AGB_PRINT_STRUCT_ADDR;
    u16 *pPrintBuf = (u16 *)(0x8000000 + (pPrint->m_nBank << 16));
    u16 *pProtect = (u16 *)AGB_PRINT_PROTECT_ADDR;
    u16 nData = pPrintBuf[pPrint->m_nPut / 2];
    *pProtect = 0x20;
    nData = (pPrint->m_nPut & 1) ? (nData & 0xFF) | (cChr << 8) : (nData & 0xFF00) | cChr;
    pPrintBuf[pPrint->m_nPut / 2] = nData;
    pPrint->m_nPut++;
    *pProtect = 0;
}

void AGBPutc(const char cChr)
{
    vu16 *pWSCNT = &REG_WAITCNT;
    u16 nOldWSCNT = *pWSCNT;
    volatile struct AGBPrintStruct *pPrint;
    *pWSCNT = WSCNT_DATA;
    AGBPutcInternal(cChr);
    *pWSCNT = nOldWSCNT;
    pPrint = (struct AGBPrintStruct *)AGB_PRINT_STRUCT_ADDR;
    if (pPrint->m_nPut == ((pPrint->m_nGet - 1) & 0xFFFF))
        AGBPrintFlush1Block();
}

void AGBPrint(const char *pBuf)
{
    volatile struct AGBPrintStruct *pPrint = (struct AGBPrintStruct *)AGB_PRINT_STRUCT_ADDR;
    vu16 *pWSCNT = &REG_WAITCNT;
    u16 nOldWSCNT = *pWSCNT;
    *pWSCNT = WSCNT_DATA;
    while (*pBuf)
    {
        AGBPutc(*pBuf);
        pBuf++;
    }
    *pWSCNT = nOldWSCNT;
}

void AGBPrintf(const char *pBuf, ...)
{
    char bufPrint[0x100];
    va_list vArgv;
    va_start(vArgv, pBuf);
    #if (PRETTY_PRINT_HANDLER == PRETTY_PRINT_MINI_PRINTF)
    mini_vsnprintf(bufPrint, 0x100, pBuf, vArgv);
    #elif (PRETTY_PRINT_HANDLER == PRETTY_PRINT_LIBC)
    vsnprintf(bufPrint, 0x100, pBuf, vArgv);
    #else
    #error "unspecified pretty printing handler."
    #endif
    va_end(vArgv);
    AGBPrint(bufPrint);
}

static void AGBPrintTransferDataInternal(u32 bAllData)
{
    LPFN_PRINT_FLUSH lpfnFuncFlush;
    vu16 *pIME;
    u16 nIME;
    vu16 *pWSCNT;
    u16 nOldWSCNT;
    u16 *pProtect;
    volatile struct AGBPrintStruct *pPrint;

    pProtect = (u16 *)AGB_PRINT_PROTECT_ADDR;
    pPrint = (struct AGBPrintStruct *)AGB_PRINT_STRUCT_ADDR;
    lpfnFuncFlush = (LPFN_PRINT_FLUSH)AGB_PRINT_FLUSH_ADDR;
    pIME = &REG_IME;
    nIME = *pIME;
    pWSCNT = &REG_WAITCNT;
    nOldWSCNT = *pWSCNT;
    *pIME = nIME & ~1;
    *pWSCNT = WSCNT_DATA;

    if (bAllData)
    {
        while (pPrint->m_nPut != pPrint->m_nGet)
        {
            *pProtect = 0x20;
            lpfnFuncFlush();
            *pProtect = 0;
        }
    }
    else if (pPrint->m_nPut != pPrint->m_nGet)
    {
        *pProtect = 0x20;
        lpfnFuncFlush();
        *pProtect = 0;
    }

    *pWSCNT = nOldWSCNT;
    *pIME = nIME;
}

void AGBPrintFlush1Block(void)
{
    AGBPrintTransferDataInternal(FALSE);
}

void AGBPrintFlush(void)
{
    AGBPrintTransferDataInternal(TRUE);
}

void AGBAssert(const char *pFile, int nLine, const char *pExpression, int nStopProgram)
{
    if (nStopProgram)
    {
        AGBPrintf("ASSERTION FAILED  FILE=[%s] LINE=[%d]  EXP=[%s] \n", pFile, nLine, pExpression);
        AGBPrintFlush();
        asm(".hword 0xEFFF");
    }
    else
    {
        AGBPrintf("WARING FILE=[%s] LINE=[%d]  EXP=[%s] \n", pFile, nLine, pExpression);
    }
}
#endif

// no$gba print functions
#if (LOG_HANDLER == LOG_HANDLER_NOCASH_PRINT)
void NoCashGBAPrint(const char *pBuf)
{
    *(volatile u32 *)NOCASHGBAPRINTADDR2 = (u32)pBuf;
}

void NoCashGBAPrintf(const char *pBuf, ...)
{
    char bufPrint[0x100];
    va_list vArgv;
    va_start(vArgv, pBuf);
    #if (PRETTY_PRINT_HANDLER == PRETTY_PRINT_MINI_PRINTF)
    mini_vsnprintf(bufPrint, 0x100, pBuf, vArgv);
    #elif (PRETTY_PRINT_HANDLER == PRETTY_PRINT_LIBC)
    vsnprintf(bufPrint, 0x100, pBuf, vArgv);
    #else
    #error "unspecified pretty printing handler."
    #endif
    va_end(vArgv);
    NoCashGBAPrint(bufPrint);
}

void NoCashGBAAssert(const char *pFile, s32 nLine, const char *pExpression, bool32 nStopProgram)
{
    if (nStopProgram)
    {
        NoCashGBAPrintf("ASSERTION FAILED  FILE=[%s] LINE=[%d]  EXP=[%s]", pFile, nLine, pExpression);
        asm(".hword 0xEFFF");
    }
    else
    {
        NoCashGBAPrintf("WARING FILE=[%s] LINE=[%d]  EXP=[%s]", pFile, nLine, pExpression);
    }
}
#endif

// mgba print functions
#if (LOG_HANDLER == LOG_HANDLER_MGBA_PRINT)
#define MGBA_REG_DEBUG_MAX (256)

bool32 MgbaOpen(void)
{
    *REG_DEBUG_ENABLE = 0xC0DE;
    return *REG_DEBUG_ENABLE == 0x1DEA;
}

void MgbaClose(void)
{
    *REG_DEBUG_ENABLE = 0;
}

void MgbaPrintf(s32 level, const char *ptr, ...)
{
    va_list args;

    level &= 0x7;
    va_start(args, ptr);
    #if (PRETTY_PRINT_HANDLER == PRETTY_PRINT_MINI_PRINTF)
    mini_vsnprintf(REG_DEBUG_STRING, MGBA_REG_DEBUG_MAX, ptr, args);
    #elif (PRETTY_PRINT_HANDLER == PRETTY_PRINT_LIBC)
    vsnprintf(REG_DEBUG_STRING, MGBA_REG_DEBUG_MAX, ptr, args);
    #else
    #error "unspecified pretty printing handler."
    #endif
    va_end(args);
    *REG_DEBUG_FLAGS = level | 0x100;
}

void MgbaAssert(const char *pFile, s32 nLine, const char *pExpression, bool32 nStopProgram)
{
    if (nStopProgram)
    {
        MgbaPrintf(MGBA_LOG_ERROR, "ASSERTION FAILED  FILE=[%s] LINE=[%d]  EXP=[%s]", pFile, nLine, pExpression);
        asm(".hword 0xEFFF");
    }
    else
    {
        MgbaPrintf(MGBA_LOG_WARN, "WARING FILE=[%s] LINE=[%d]  EXP=[%s]", pFile, nLine, pExpression);
    }
}
#endif
#endif
