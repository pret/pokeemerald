#include <stdarg.h>
#include "global.h"
#include "characters.h"
#include "gpu_regs.h"
#include "load_save.h"
#include "main.h"
#include "malloc.h"
#include "random.h"
#include "test_runner.h"
#include "test/test.h"

#define TIMEOUT_SECONDS 55

void CB2_TestRunner(void);

EWRAM_DATA struct TestRunnerState gTestRunnerState;
EWRAM_DATA struct FunctionTestRunnerState *gFunctionTestRunnerState;

enum {
    CURRENT_TEST_STATE_ESTIMATE,
    CURRENT_TEST_STATE_RUN,
};

__attribute__((section(".persistent"))) static struct {
    u32 address:28;
    u32 state:1;
} sCurrentTest = {0};

void TestRunner_Battle(const struct Test *);

static bool32 MgbaOpen_(void);
static void MgbaExit_(u8 exitCode);
static s32 MgbaVPrintf_(const char *fmt, va_list va);
static void Intr_Timer2(void);

extern const struct Test __start_tests[];
extern const struct Test __stop_tests[];

static bool32 PrefixMatch(const char *pattern, const char *string)
{
    if (string == NULL)
        return TRUE;

    while (TRUE)
    {
        if (!*pattern)
            return TRUE;
        if (*pattern != *string)
            return FALSE;
        pattern++;
        string++;
    }
}

enum
{
    STATE_INIT,
    STATE_ASSIGN_TEST,
    STATE_RUN_TEST,
    STATE_REPORT_RESULT,
    STATE_NEXT_TEST,
    STATE_EXIT,
};

static u32 MinCostProcess(void)
{
    u32 i;
    u32 minCost, minCostProcess;

    minCost = gTestRunnerState.processCosts[0];
    minCostProcess = 0;
    for (i = 1; i < gTestRunnerN; i++)
    {
        if (gTestRunnerState.processCosts[i] < minCost)
        {
            minCost = gTestRunnerState.processCosts[i];
            minCostProcess = i;
        }
    }

    return minCostProcess;
}

// Greedily assign tests to processes based on estimated cost.
// TODO: Make processCosts a min heap.
static u32 AssignCostToRunner(void)
{
    u32 minCostProcess;

    if (gTestRunnerState.test->runner == &gAssumptionsRunner)
        return gTestRunnerI;

    minCostProcess = MinCostProcess();

    // XXX: If estimateCost returns only on some processes, or
    // returns inconsistent results then processCosts will be
    // inconsistent and some tests may not run.
    if (gTestRunnerState.test->runner->estimateCost)
        gTestRunnerState.processCosts[minCostProcess] += gTestRunnerState.test->runner->estimateCost(gTestRunnerState.test->data);
    else
        gTestRunnerState.processCosts[minCostProcess] += 1;

    return minCostProcess;
}

void CB2_TestRunner(void)
{
top:

    switch (gTestRunnerState.state)
    {
    case STATE_INIT:
        if (!MgbaOpen_())
        {
            gTestRunnerState.state = STATE_EXIT;
            gTestRunnerState.exitCode = 2;
            return;
        }

        MoveSaveBlocks_ResetHeap();
        ClearSav1();
        ClearSav2();
        ClearSav3();

        gIntrTable[7] = Intr_Timer2;

        // The current test restarted the ROM (e.g. by jumping to NULL).
        if (sCurrentTest.address != 0)
        {
            gTestRunnerState.test = __start_tests;
            while ((uintptr_t)gTestRunnerState.test != sCurrentTest.address)
            {
                AssignCostToRunner();
                gTestRunnerState.test++;
            }
            if (sCurrentTest.state == CURRENT_TEST_STATE_ESTIMATE)
            {
                u32 runner = MinCostProcess();
                gTestRunnerState.processCosts[runner] += 1;
                if (runner == gTestRunnerI)
                {
                    gTestRunnerState.state = STATE_REPORT_RESULT;
                    gTestRunnerState.result = TEST_RESULT_CRASH;
                }
                else
                {
                    gTestRunnerState.state = STATE_NEXT_TEST;
                }
            }
            else
            {
                gTestRunnerState.state = STATE_REPORT_RESULT;
                gTestRunnerState.result = TEST_RESULT_CRASH;
            }
        }
        else
        {
            gTestRunnerState.state = STATE_ASSIGN_TEST;
            gTestRunnerState.test = __start_tests;
        }
        gTestRunnerState.exitCode = 0;
        gTestRunnerState.skipFilename = NULL;

        break;

    case STATE_ASSIGN_TEST:
        while (1)
        {
            if (gTestRunnerState.test == __stop_tests)
            {
                gTestRunnerState.state = STATE_EXIT;
                return;
            }
            if (gTestRunnerState.test->runner != &gAssumptionsRunner
              && !PrefixMatch(gTestRunnerArgv, gTestRunnerState.test->name))
                ++gTestRunnerState.test;
            else
                break;
        }

        MgbaPrintf_(":N%s", gTestRunnerState.test->name);
        MgbaPrintf_(":L%s:%d", gTestRunnerState.test->filename);
        gTestRunnerState.result = TEST_RESULT_PASS;
        gTestRunnerState.expectedResult = TEST_RESULT_PASS;
        gTestRunnerState.expectLeaks = FALSE;
        if (gTestRunnerHeadless)
            gTestRunnerState.timeoutSeconds = TIMEOUT_SECONDS;
        else
            gTestRunnerState.timeoutSeconds = UINT_MAX;
        InitHeap(gHeap, HEAP_SIZE);
        EnableInterrupts(INTR_FLAG_TIMER2);
        REG_TM2CNT_L = UINT16_MAX - (274 * 60); // Approx. 1 second.
        REG_TM2CNT_H = TIMER_ENABLE | TIMER_INTR_ENABLE | TIMER_1024CLK;

        sCurrentTest.address = (uintptr_t)gTestRunnerState.test;
        sCurrentTest.state = CURRENT_TEST_STATE_ESTIMATE;

        // If AssignCostToRunner fails, we want to report the failure.
        gTestRunnerState.state = STATE_REPORT_RESULT;
        if (AssignCostToRunner() == gTestRunnerI)
            gTestRunnerState.state = STATE_RUN_TEST;
        else
            gTestRunnerState.state = STATE_NEXT_TEST;

        break;

    case STATE_RUN_TEST:
        gTestRunnerState.state = STATE_REPORT_RESULT;
        sCurrentTest.state = CURRENT_TEST_STATE_RUN;
        SeedRng(0);
        SeedRng2(0);
        if (gTestRunnerState.test->runner->setUp)
        {
            gTestRunnerState.test->runner->setUp(gTestRunnerState.test->data);
            gTestRunnerState.tearDown = TRUE;
        }
        // NOTE: Assumes that the compiler interns __FILE__.
        if (gTestRunnerState.skipFilename == gTestRunnerState.test->filename) // Assumption fails for tests in this file.
        {
            MgbaPrintf_(":L%s:%d", gTestRunnerState.test->filename, gTestRunnerState.failedAssumptionsBlockLine);
            gTestRunnerState.result = TEST_RESULT_ASSUMPTION_FAIL;
            return;
        }
        else
        {
            gTestRunnerState.test->runner->run(gTestRunnerState.test->data);
        }
        break;

    case STATE_REPORT_RESULT:
        REG_TM2CNT_H = 0;

        gTestRunnerState.state = STATE_NEXT_TEST;

        if (gTestRunnerState.tearDown && gTestRunnerState.test->runner->tearDown)
        {
            gTestRunnerState.test->runner->tearDown(gTestRunnerState.test->data);
            gTestRunnerState.tearDown = FALSE;
        }

        if (gTestRunnerState.result == TEST_RESULT_PASS
         && !gTestRunnerState.expectLeaks)
        {
            const struct MemBlock *head = HeapHead();
            const struct MemBlock *block = head;
            do
            {
                if (block->magic != MALLOC_SYSTEM_ID
                 || !(EWRAM_START <= (uintptr_t)block->next && (uintptr_t)block->next < EWRAM_END)
                 || (block->next <= block && block->next != head))
                {
                    MgbaPrintf_("gHeap corrupted block at 0x%p", block);
                    gTestRunnerState.result = TEST_RESULT_ERROR;
                    break;
                }

                if (block->allocated)
                {
                    const char *location = MemBlockLocation(block);
                    if (location)
                        MgbaPrintf_("%s: %d bytes not freed", location, block->size);
                    else
                        MgbaPrintf_("<unknown>: %d bytes not freed", block->size);
                    gTestRunnerState.result = TEST_RESULT_FAIL;
                }
                block = block->next;
            }
            while (block != head);
        }

        if (gTestRunnerState.test->runner == &gAssumptionsRunner)
        {
            if (gTestRunnerState.result != TEST_RESULT_PASS)
            {
                gTestRunnerState.skipFilename = gTestRunnerState.test->filename;
            }
        }
        else
        {
            const char *color;
            const char *result;

            if (gTestRunnerState.result == gTestRunnerState.expectedResult)
            {
                color = "\e[32m";
                MgbaPrintf_(":N%s", gTestRunnerState.test->name);
            }
            else if (gTestRunnerState.result != TEST_RESULT_ASSUMPTION_FAIL || gTestRunnerSkipIsFail)
            {
                gTestRunnerState.exitCode = 1;
                color = "\e[31m";
            }
            else
            {
                color = "";
            }

            switch (gTestRunnerState.result)
            {
            case TEST_RESULT_FAIL:
                if (gTestRunnerState.expectedResult == TEST_RESULT_FAIL)
                {
                    result = "KNOWN_FAILING";
                    color = "\e[33m";
                }
                else
                {
                    result = "FAIL";
                }
                break;
            case TEST_RESULT_PASS:
                if (gTestRunnerState.result != gTestRunnerState.expectedResult)
                    result = "KNOWN_FAILING_PASS";
                else
                    result = "PASS";
                break;
            case TEST_RESULT_ASSUMPTION_FAIL:
                result = "ASSUMPTION_FAIL";
                color = "\e[33m";
                break;
            case TEST_RESULT_TODO:
                result = "TO_DO";
                color = "\e[33m";
                break;
            case TEST_RESULT_INVALID:
                result = "INVALID";
                break;
            case TEST_RESULT_ERROR:
                result = "ERROR";
                break;
            case TEST_RESULT_TIMEOUT:
                result = "TIMEOUT";
                break;
            case TEST_RESULT_CRASH:
                result = "CRASH";
                break;
            default:
                result = "UNKNOWN";
                break;
            }

            if (gTestRunnerState.result == TEST_RESULT_PASS)
            {
                if (gTestRunnerState.result != gTestRunnerState.expectedResult)
                    MgbaPrintf_(":U%s%s\e[0m", color, result);
                else
                    MgbaPrintf_(":P%s%s\e[0m", color, result);
            }
            else if (gTestRunnerState.result == TEST_RESULT_ASSUMPTION_FAIL)
                MgbaPrintf_(":A%s%s\e[0m", color, result);
            else if (gTestRunnerState.result == TEST_RESULT_TODO)
                MgbaPrintf_(":T%s%s\e[0m", color, result);
            else if (gTestRunnerState.expectedResult == gTestRunnerState.result)
                MgbaPrintf_(":K%s%s\e[0m", color, result);
            else
                MgbaPrintf_(":F%s%s\e[0m", color, result);
        }

        break;

    case STATE_NEXT_TEST:
        gTestRunnerState.state = STATE_ASSIGN_TEST;
        gTestRunnerState.test++;
        break;

    case STATE_EXIT:
        MgbaExit_(gTestRunnerState.exitCode);
        break;
    }

    if (gMain.callback2 == CB2_TestRunner)
        goto top;
}

void Test_ExpectedResult(enum TestResult result)
{
    gTestRunnerState.expectedResult = result;
}

void Test_ExpectLeaks(bool32 expectLeaks)
{
    gTestRunnerState.expectLeaks = expectLeaks;
}

static void FunctionTest_SetUp(void *data)
{
    (void)data;
    gFunctionTestRunnerState = AllocZeroed(sizeof(*gFunctionTestRunnerState));
    SeedRng(0);
}

static void FunctionTest_Run(void *data)
{
    void (*function)(void) = data;
    do
    {
        if (gFunctionTestRunnerState->parameters)
            MgbaPrintf_(":N%s %d/%d", gTestRunnerState.test->name, gFunctionTestRunnerState->runParameter + 1, gFunctionTestRunnerState->parameters);
        gFunctionTestRunnerState->parameters = 0;
        function();
    } while (++gFunctionTestRunnerState->runParameter < gFunctionTestRunnerState->parameters);
}

static void FunctionTest_TearDown(void *data)
{
    (void)data;
    FREE_AND_SET_NULL(gFunctionTestRunnerState);
}

static bool32 FunctionTest_CheckProgress(void *data)
{
    bool32 madeProgress;
    (void)data;
    madeProgress = gFunctionTestRunnerState->checkProgressParameter < gFunctionTestRunnerState->runParameter;
    gFunctionTestRunnerState->checkProgressParameter = gFunctionTestRunnerState->runParameter;
    return madeProgress;
}

const struct TestRunner gFunctionTestRunner =
{
    .setUp = FunctionTest_SetUp,
    .run = FunctionTest_Run,
    .tearDown = FunctionTest_TearDown,
    .checkProgress = FunctionTest_CheckProgress,
};

static void Assumptions_Run(void *data)
{
    void (*function)(void) = data;
    function();
}

const struct TestRunner gAssumptionsRunner =
{
    .run = Assumptions_Run,
};

#define IRQ_LR (*(vu32 *)0x3007F9C)

/* Returns to AgbMainLoop.
 * Similar to a longjmp except that we only restore sp (and cpsr via
 * overwriting the value of lr_irq on the stack).
 *
 * WARNING: This could potentially be flaky because other global state
 * will not be cleaned up, we may decide to Exit on a timeout instead. */
static NAKED void JumpToAgbMainLoop(void)
{
    asm(".arm\n\
         .word 0xe3104778\n\
         ldr r0, =gAgbMainLoop_sp\n\
         ldr sp, [r0]\n\
         ldr r0, =AgbMainLoop\n\
         bx r0\n\
         .pool");
}

void ReinitCallbacks(void)
{
    gMain.callback1 = NULL;
    SetMainCallback2(CB2_TestRunner);
    gMain.vblankCallback = NULL;
    gMain.hblankCallback = NULL;
}

static void Intr_Timer2(void)
{
    if (--gTestRunnerState.timeoutSeconds == 0)
    {
        if (gTestRunnerState.test->runner->checkProgress
         && gTestRunnerState.test->runner->checkProgress(gTestRunnerState.test->data))
        {
            gTestRunnerState.timeoutSeconds = TIMEOUT_SECONDS;
        }
        else
        {
            if (gTestRunnerState.state == STATE_RUN_TEST)
                gTestRunnerState.state = STATE_REPORT_RESULT;
            gTestRunnerState.result = TEST_RESULT_TIMEOUT;
            ReinitCallbacks();
            IRQ_LR = ((uintptr_t)JumpToAgbMainLoop & ~1) + 4;
        }
    }
}

void Test_ExitWithResult(enum TestResult result, u32 stopLine, const char *fmt, ...)
{
    gTestRunnerState.result = result;
    gTestRunnerState.failedAssumptionsBlockLine = stopLine;
    ReinitCallbacks();
    if (gTestRunnerState.state == STATE_REPORT_RESULT
     && gTestRunnerState.result != gTestRunnerState.expectedResult)
    {
        if (!gTestRunnerState.test->runner->handleExitWithResult
         || !gTestRunnerState.test->runner->handleExitWithResult(gTestRunnerState.test->data, result))
        {
            va_list va;
            va_start(va, fmt);
            MgbaVPrintf_(fmt, va);
            va_end(va);
        }
    }
    JumpToAgbMainLoop();
}

#define REG_DEBUG_ENABLE (*(vu16 *)0x4FFF780)
#define REG_DEBUG_FLAGS  (*(vu16 *)0x4FFF700)
#define REG_DEBUG_STRING ((char *)0x4FFF600)

static bool32 MgbaOpen_(void)
{
    REG_DEBUG_ENABLE = 0xC0DE;
    return REG_DEBUG_ENABLE == 0x1DEA;
}

static void MgbaExit_(u8 exitCode)
{
    register u32 _exitCode asm("r0") = exitCode;
    asm("swi 0x3" :: "r" (_exitCode));
}

s32 MgbaPrintf_(const char *fmt, ...)
{
    va_list va;
    va_start(va, fmt);
    return MgbaVPrintf_(fmt, va);
}

static s32 MgbaPutchar_(s32 i, s32 c)
{
    REG_DEBUG_STRING[i++] = c;
    if (i == 255)
    {
        REG_DEBUG_STRING[i] = '\0';
        REG_DEBUG_FLAGS = MGBA_LOG_INFO | 0x100;
        i = 0;
    }
    return i;
}

extern const u8 gWireless_RSEtoASCIITable[];

// Bare-bones, only supports plain %s, %S, and %d.
static s32 MgbaVPrintf_(const char *fmt, va_list va)
{
    s32 i = 0;
    s32 c, d;
    u32 p;
    const char *s;
    const u8 *pokeS;
    while (*fmt)
    {
        switch ((c = *fmt++))
        {
        case '%':
            switch (*fmt++)
            {
            case '%':
                i = MgbaPutchar_(i, '%');
                break;
            case 'd':
                d = va_arg(va, int);
                if (d == 0)
                {
                    i = MgbaPutchar_(i, '0');
                }
                else
                {
                    char buffer[10];
                    s32 n = 0;
                    u32 u = abs(d);
                    if (d < 0)
                        i = MgbaPutchar_(i, '-');
                    while (u > 0)
                    {
                        buffer[n++] = '0' + (u % 10);
                        u /= 10;
                    }
                    while (n > 0)
                        i = MgbaPutchar_(i, buffer[--n]);
                }
                break;
            case 'p':
                p = va_arg(va, unsigned);
                {
                    s32 n;
                    for (n = 0; n < 7; n++)
                    {
                        unsigned nybble = (p >> (24 - (4*n))) & 0xF;
                        if (nybble <= 9)
                            i = MgbaPutchar_(i, '0' + nybble);
                        else
                            i = MgbaPutchar_(i, 'a' + nybble - 10);
                    }
                }
                break;
            case 'q':
                d = va_arg(va, int);
                {
                    char buffer[10];
                    s32 n = 0;
                    u32 u = abs(d) >> 12;
                    if (u == 0)
                    {
                        i = MgbaPutchar_(i, '0');
                    }
                    else
                    {
                        if (d < 0)
                            i = MgbaPutchar_(i, '-');
                        while (u > 0)
                        {
                            buffer[n++] = '0' + (u % 10);
                            u /= 10;
                        }
                        while (n > 0)
                            i = MgbaPutchar_(i, buffer[--n]);
                    }

                    n = 0;
                    i = MgbaPutchar_(i, '.');
                    u = d & 0xFFF;
                    while (TRUE)
                    {
                        u *= 10;
                        i = MgbaPutchar_(i, '0' + (u >> 12));
                        u &= 0xFFF;
                        if (u == 0)
                            break;
                        if (++n == 2)
                        {
                            u *= 10;
                            i = MgbaPutchar_(i, '0' + ((u + UQ_4_12_ROUND) >> 12));
                            break;
                        }
                    }
                }
                break;
            case 's':
                s = va_arg(va, const char *);
                while ((c = *s++) != '\0')
                    i = MgbaPutchar_(i, c);
                break;
            case 'S':
                pokeS = va_arg(va, const u8 *);
                while ((c = *pokeS++) != EOS)
                {
                    if ((c = gWireless_RSEtoASCIITable[c]) != '\0')
                        i = MgbaPutchar_(i, c);
                    else
                        i = MgbaPutchar_(i, '?');
                }
                break;
            }
            break;
        case '\n':
            i = 254;
            i = MgbaPutchar_(i, '\0');
            break;
        default:
            i = MgbaPutchar_(i, c);
            break;
        }
    }
    if (i != 0)
    {
        REG_DEBUG_FLAGS = MGBA_LOG_INFO | 0x100;
    }
    return i;
}

/* Entry point for the Debugging and Control System. Handles illegal
 * instructions, which are typically caused by branching to an invalid
 * address. */
#if MODERN
__attribute__((naked, section(".dacs"), target("arm")))
#else
__attribute__((naked, section(".dacs")))
#endif
void DACSEntry(void)
{
    asm(".arm\n\
         ldr r0, =(DACSHandle + 1)\n\
         bx r0\n");
}

#define DACS_LR (*(vu32 *)0x3007FEC)

void DACSHandle(void)
{
    if (gTestRunnerState.state == STATE_RUN_TEST)
        gTestRunnerState.state = STATE_REPORT_RESULT;
    gTestRunnerState.result = TEST_RESULT_CRASH;
    ReinitCallbacks();
    DACS_LR = ((uintptr_t)JumpToAgbMainLoop & ~1) + 4;
}

static const struct Test *GetTest(void)
{
    const struct Test *test = gTestRunnerState.test;
    return test;
}

u32 SourceLine(u32 sourceLineOffset)
{
    const struct Test *test = GetTest();
    return test->sourceLine + sourceLineOffset;
}

u32 SourceLineOffset(u32 sourceLine)
{
    const struct Test *test = GetTest();
    if (sourceLine - test->sourceLine > 0xFF)
        return 0;
    else
        return sourceLine - test->sourceLine;
}
