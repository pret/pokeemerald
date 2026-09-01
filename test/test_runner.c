#include <stdarg.h>
#include "global.h"
#include "fake_rtc.h"
#include "gpu_regs.h"
#include "load_save.h"
#include "main.h"
#include "malloc.h"
#include "random.h"
#include "task.h"
#include "union_room_chat.h"
#include "constants/characters.h"
#include "test_runner.h"
#include "test/test.h"
#include "test/battle.h"

#define TIMEOUT_SECONDS 60

void CB2_TestRunner(void);
static void ReinitCallbacks(void);
static void ResetGlobalVariables(void);

EWRAM_DATA struct TestRunnerState gTestRunnerState;
EWRAM_DATA struct FunctionTestRunnerState *gFunctionTestRunnerState;

enum {
    CURRENT_TEST_STATE_ESTIMATE,
    CURRENT_TEST_STATE_RUN,
};

__attribute__((section(".persistent"))) struct PersistentTestRunnerState gPersistentTestRunnerState = {0};

void TestRunner_Battle(const struct Test *);

static bool32 MgbaOpen_(void);
static void MgbaExit_(u8 exitCode);
static s32 MgbaVPrintf_(const char *fmt, va_list va);
static void Intr_Timer2(void);

extern const struct Test __start_tests[];
extern const struct Test __stop_tests[];

static enum TestFilterMode DetectFilterMode(const char *pattern)
{
    size_t n = strlen(pattern);
    if (n > 2 && pattern[n-2] == '.' && pattern[n-1] == 'c')
        return TEST_FILTER_MODE_FILENAME_EXACT;
    else if (pattern[0] == '*') // TODO: Support '*pattern*'.
        return TEST_FILTER_MODE_TEST_NAME_INFIX;
    else
        return TEST_FILTER_MODE_TEST_NAME_PREFIX;
}

static bool32 ExactMatch(const char *pattern, const char *string)
{
    if (string == NULL)
        return TRUE;

    return strcmp(pattern, string) == 0;
}

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

static bool32 InfixMatch(const char *pattern, const char *string)
{
    if (string == NULL)
        return TRUE;

    return strstr(string, &pattern[1]) != NULL;
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

void TestRunner_CheckMemory(void)
{
    if (gTestRunnerState.result == TEST_RESULT_PASS
     && !gTestRunnerState.expectLeaks)
    {
        TestFreeConfigData();

        int i;
        const struct MemBlock *head = HeapHead();
        const struct MemBlock *block = head;
        do
        {
            if (block->magic != MALLOC_SYSTEM_ID
             || !(EWRAM_START <= (uintptr_t)block->next && (uintptr_t)block->next < EWRAM_END)
             || (block->next <= block && block->next != head))
            {
                Test_MgbaPrintf("gHeap corrupted block at %p", block);
                gTestRunnerState.result = TEST_RESULT_ERROR;
                break;
            }

            if (block->allocated)
            {
                const char *location = MemBlockLocation(block);
                if (location)
                {
                    Test_MgbaPrintf("%s: %d bytes not freed", location, block->size);
                    gTestRunnerState.result = TEST_RESULT_FAIL;

                    if (gTestRunnerState.expectedFailState == EXPECT_FAIL_OPEN)
                        gTestRunnerState.expectedFailState = EXPECT_FAIL_SUCCESS;
                }
                else
                {
                    Test_MgbaPrintf("<unknown>: %d bytes not freed", block->size);
                    gTestRunnerState.result = TEST_RESULT_FAIL;

                    if (gTestRunnerState.expectedFailState == EXPECT_FAIL_OPEN)
                        gTestRunnerState.expectedFailState = EXPECT_FAIL_SUCCESS;
                }
            }
            block = block->next;
        }
        while (block != head);

        for (i = 0; i < NUM_TASKS; i++)
        {
            if (gTasks[i].isActive)
            {
                Test_MgbaPrintf("%s:%d: %p: task not freed", gTestRunnerState.test->filename, SourceLine(0), gTasks[i].func);
                gTestRunnerState.result = TEST_RESULT_FAIL;

                if (gTestRunnerState.expectedFailState == EXPECT_FAIL_OPEN)
                    gTestRunnerState.expectedFailState = EXPECT_FAIL_SUCCESS;
            }
        }
    }
}

static void ClearSaveBlocks(void)
{
    ClearSav1();
    ClearSav2();
    ClearSav3();
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

        gTestRunnerState.filterMode = DetectFilterMode(gTestRunnerArgv);

        MoveSaveBlocks_ResetHeap();

        gIntrTable[7] = Intr_Timer2;

        // The current test restarted the ROM (e.g. by jumping to NULL).
        if (gPersistentTestRunnerState.address != 0)
        {
            ClearSaveBlocks();
            gTestRunnerState.test = __start_tests;
            while ((uintptr_t)gTestRunnerState.test != gPersistentTestRunnerState.address)
            {
                AssignCostToRunner();
                gTestRunnerState.test++;
            }

            if (gPersistentTestRunnerState.state == CURRENT_TEST_STATE_ESTIMATE)
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
                // Cost must be assigned to the test that crashed, otherwise tests will be desynched
                AssignCostToRunner();
                gTestRunnerState.state = STATE_REPORT_RESULT;
                gTestRunnerState.result = TEST_RESULT_CRASH;
            }

            if (gPersistentTestRunnerState.expectCrash)
                gTestRunnerState.expectedResult = TEST_RESULT_CRASH;

            gTestRunnerState.expectedFailLine = 0;
            gTestRunnerState.expectedFailState = NO_EXPECT_FAIL;
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
        ClearSaveBlocks();
        while (1)
        {
            if (gTestRunnerState.test == __stop_tests)
            {
                gTestRunnerState.state = STATE_EXIT;
                return;
            }
            if (gTestRunnerState.filterMode == TEST_FILTER_MODE_FILENAME_EXACT
             && !ExactMatch(gTestRunnerArgv, gTestRunnerState.test->filename))
            {
                ++gTestRunnerState.test;
                continue;
            }
            // Run all assumption blocks when filtering on test name
            // because it's possible that a test in this file could
            // match.
            // TODO: Delay running the assumptions block until we find a
            // test name that matches.
            else if (gTestRunnerState.test->runner != &gAssumptionsRunner)
            {
                if ((gTestRunnerState.filterMode == TEST_FILTER_MODE_TEST_NAME_PREFIX && !PrefixMatch(gTestRunnerArgv, gTestRunnerState.test->name))
                 || (gTestRunnerState.filterMode == TEST_FILTER_MODE_TEST_NAME_INFIX && !InfixMatch(gTestRunnerArgv, gTestRunnerState.test->name)))
                {
                    ++gTestRunnerState.test;
                    continue;
                }
            }
            break;
        }

        Test_MgbaPrintf(":N%s", gTestRunnerState.test->name);
        Test_MgbaPrintf(":L%s:%d", gTestRunnerState.test->filename, SourceLine(0));
        gTestRunnerState.result = TEST_RESULT_PASS;
        gTestRunnerState.expectedResult = TEST_RESULT_PASS;
        gTestRunnerState.expectLeaks = FALSE;
        gTestRunnerState.expectedFailLine = 0;
        gTestRunnerState.expectedFailState = NO_EXPECT_FAIL;
        if (gTestRunnerHeadless)
            gTestRunnerState.timeoutSeconds = TIMEOUT_SECONDS;
        else
            gTestRunnerState.timeoutSeconds = UINT_MAX;
        InitHeap(gHeap, HEAP_SIZE);
        ResetTasks();
        EnableInterrupts(INTR_FLAG_TIMER2);
        REG_TM2CNT_L = UINT16_MAX - (274 * 60); // Approx. 1 second.
        REG_TM2CNT_H = TIMER_ENABLE | TIMER_INTR_ENABLE | TIMER_1024CLK;

        gPersistentTestRunnerState.address = (uintptr_t)gTestRunnerState.test;
        gPersistentTestRunnerState.state = CURRENT_TEST_STATE_ESTIMATE;

        // If AssignCostToRunner fails, we want to report the failure.
        gTestRunnerState.state = STATE_REPORT_RESULT;
        if (AssignCostToRunner() == gTestRunnerI)
            gTestRunnerState.state = STATE_RUN_TEST;
        else
            gTestRunnerState.state = STATE_NEXT_TEST;

        break;

    case STATE_RUN_TEST:
        gTestRunnerState.state = STATE_REPORT_RESULT;
        gPersistentTestRunnerState.state = CURRENT_TEST_STATE_RUN;
        gPersistentTestRunnerState.expectCrash = FALSE;
        ResetGlobalVariables();
        SeedRng(0);
        SeedRng2(0);
        if (gTestRunnerState.test->runner->setUp)
            gTestRunnerState.test->runner->setUp(gTestRunnerState.test->data);
        gTestRunnerState.tearDown = TRUE;
        // NOTE: Assumes that the compiler interns __FILE__.
        if (gTestRunnerState.skipFilename == gTestRunnerState.test->filename) // Assumption fails for tests in this file.
        {
            Test_MgbaPrintf(":L%s:%d", gTestRunnerState.test->filename, gTestRunnerState.failedAssumptionsBlockLine);
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
            gTestRunnerState.test->runner->tearDown(gTestRunnerState.test->data);
        gTestRunnerState.tearDown = FALSE;

        TestRunner_CheckMemory();

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
            bool32 expectedFailOnCorrectLine = FALSE;

            if (gTestRunnerState.expectedFailState == EXPECT_FAIL_SUCCESS)
            {
                // Failed within expected block; pass
                expectedFailOnCorrectLine = TRUE;
                color = "\e[32m";
                Test_MgbaPrintf(":N%s", gTestRunnerState.test->name);
            }
            else if (gTestRunnerState.expectedFailState == EXPECT_FAIL_CLOSED
             && gTestRunnerState.result == TEST_RESULT_FAIL)
            {
                // Failed outside expected block; fail
                gTestRunnerState.exitCode = 1;
                color = "\e[31m";
            }
            else if (gTestRunnerState.result == gTestRunnerState.expectedResult
             || (gTestRunnerState.result == TEST_RESULT_FAIL
              && gTestRunnerState.expectedResult == TEST_RESULT_KNOWN_FAIL))
            {
                color = "\e[32m";
                Test_MgbaPrintf(":N%s", gTestRunnerState.test->name);
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
                if (gTestRunnerState.expectedResult == TEST_RESULT_KNOWN_FAIL)
                {
                    result = "KNOWN_FAILING";
                    color = "\e[33m";
                }
                else if (expectedFailOnCorrectLine)
                {
                    color = "\e[32m";
                    result = "EXPECTED_FAIL";
                }
                else if (gTestRunnerState.expectedResult == TEST_RESULT_FAIL
                 && gTestRunnerState.expectedFailState != EXPECT_FAIL_SUCCESS)
                {
                    // Failed on wrong line
                    result = "UNEXPECTED_FAIL_LINE";
                }
                else
                {
                    result = "FAIL";
                }
                break;
            case TEST_RESULT_PASS:
                if (gTestRunnerState.result != gTestRunnerState.expectedResult
                 && gTestRunnerState.expectedFailLine == 0)
                    result = "KNOWN_FAILING_PASS";
                else if (gTestRunnerState.result != gTestRunnerState.expectedResult
                 && gTestRunnerState.expectedFailLine != 0)
                    result = "EXPECTED_FAIL_PASS";
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
            case TEST_RESULT_FLAKY:
                result = "FLAKY";
                break;
            default:
                result = "UNKNOWN";
                break;
            }

            if (gTestRunnerState.result == TEST_RESULT_PASS)
            {
                if (gTestRunnerState.result != gTestRunnerState.expectedResult)
                {
                    Test_MgbaPrintf(":L%s:%d", gTestRunnerState.test->filename, SourceLine(0));
                    if (gTestRunnerState.expectedFailLine == 0)
                        Test_MgbaPrintf(":U%s%s\e[0m", color, result);
                    else
                        Test_MgbaPrintf(":V%s%s\e[0m", color, result);
                }
                else
                {
                    Test_MgbaPrintf(":P%s%s\e[0m", color, result);
                }
            }
            else if (expectedFailOnCorrectLine)
                Test_MgbaPrintf(":E%s%s\e[0m", color, result);
            else if (gTestRunnerState.result == TEST_RESULT_ASSUMPTION_FAIL)
                Test_MgbaPrintf(":A%s%s\e[0m", color, result);
            else if (gTestRunnerState.result == TEST_RESULT_TODO)
                Test_MgbaPrintf(":T%s%s\e[0m", color, result);
            else if (gTestRunnerState.expectedResult == gTestRunnerState.result
                 && gTestRunnerState.result == TEST_RESULT_CRASH)
                Test_MgbaPrintf(":E%s%s\e[0m", color, result);
            else if (gTestRunnerState.expectedResult == gTestRunnerState.result
                 && gTestRunnerState.result == TEST_RESULT_FAIL
                 && gTestRunnerState.expectedFailLine == 0)
                Test_MgbaPrintf(":K%s%s\e[0m", color, result);
            else if ((gTestRunnerState.expectedResult == gTestRunnerState.result
                  && gTestRunnerState.expectedFailState == NO_EXPECT_FAIL)
                 || (gTestRunnerState.result == TEST_RESULT_FAIL
                  && gTestRunnerState.expectedResult == TEST_RESULT_KNOWN_FAIL))
                Test_MgbaPrintf(":K%s%s\e[0m", color, result);
            else
                Test_MgbaPrintf(":F%s%s\e[0m", color, result);
        }
        gTestRunnerState.expectedFailLine = 0;
        gTestRunnerState.expectedFailState = NO_EXPECT_FAIL;
        break;

    case STATE_NEXT_TEST:
        gTestRunnerState.state = STATE_ASSIGN_TEST;
        gTestRunnerState.test++;
        break;

    case STATE_EXIT:
        MgbaExit_(gTestRunnerState.exitCode);
        break;
    default:
        MgbaOpen_();
        Test_MgbaPrintf("\e[31mInvalid TestRunner state, exiting\e[0m");
        gTestRunnerState.exitCode = 1;
        gTestRunnerState.state = STATE_EXIT;
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

void Test_ExpectCrash(bool32 expectCrash)
{
    gPersistentTestRunnerState.expectCrash = expectCrash;
    if (expectCrash)
        Test_ExpectedResult(TEST_RESULT_CRASH);
}

void Test_ExpectFail(u32 failLine)
{
    // If expecting a fail and fail has not already been encountered
    if ((gTestRunnerState.expectedFailState != EXPECT_FAIL_SUCCESS)
     && (gTestRunnerState.expectedFailState != EXPECT_FAIL_TURN_OPEN)
     && (gTestRunnerState.expectedFailState != EXPECT_FAIL_SCENE_OPEN))
    {
        if (failLine == -1)
        {
            Test_ExpectedResult(TEST_RESULT_FAIL);
            gTestRunnerState.expectedFailState = EXPECT_FAIL_OPEN;
        }
        else
        {
            gTestRunnerState.expectedFailLine = failLine;
            gTestRunnerState.expectedFailState = EXPECT_FAIL_CLOSED;
        }
    }
}

static void ResetGlobalVariables(void)
{
    ReinitCallbacks();
    gBattleTypeFlags = 0;
}

static void FunctionTest_SetUp(void *data)
{
    (void)data;
    TestInitConfigData();
    ClearRiggedRng();
    gFunctionTestRunnerState = AllocZeroed(sizeof(*gFunctionTestRunnerState));
    SeedRng(0);
}

static void FunctionTest_Run(void *data)
{
    void (*function)(void) = data;
    do
    {
        if (gFunctionTestRunnerState->parameters)
            Test_MgbaPrintf(":N%s %d/%d", gTestRunnerState.test->name, gFunctionTestRunnerState->runParameter + 1, gFunctionTestRunnerState->parameters);
        gFunctionTestRunnerState->parameters = 0;
        function();
    } while (++gFunctionTestRunnerState->runParameter < gFunctionTestRunnerState->parameters);
}

static void FunctionTest_TearDown(void *data)
{
    (void)data;
    TestFreeConfigData();
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

static u32 FunctionTest_RandomUniform(enum RandomTag tag, u32 lo, u32 hi, bool32 (*reject)(u32), void *caller)
{
    //rigged
    for (u32 i = 0; i < RIGGED_RNG_COUNT; i++)
    {
        if (gFunctionTestRunnerState->rngList[i].tag == tag)
        {
            if (reject && reject(gFunctionTestRunnerState->rngList[i].value))
                Test_ExitWithResult(TEST_RESULT_INVALID, SourceLine(0), "WITH_RNG specified a rejected value (%d)", gFunctionTestRunnerState->rngList[i].value);
            return gFunctionTestRunnerState->rngList[i].value;
        }
    }
    //trials
    /*
    if (tag == STATE->rngTag)
        return RandomUniformTrials(tag, lo, hi, reject);
    */

    //default
    return RandomUniformDefaultValue(tag, lo, hi, reject, caller);
}

static u32 FunctionTest_RandomWeightedArray(enum RandomTag tag, u32 sum, u32 n, const u16 *weights, void *caller)
{
    //rigged
    for (u32 i = 0; i < RIGGED_RNG_COUNT; i++)
    {
        if (gFunctionTestRunnerState->rngList[i].tag == tag)
            return gFunctionTestRunnerState->rngList[i].value;
    }

    //trials
    /*
    if (tag == STATE->rngTag)
        return RandomWeightedArrayTrials(tag, sum, n, weights);
    */

    //default
    return RandomWeightedArrayDefaultValue(tag, n, weights, caller);
}

static const void* FunctionTest_RandomElementArray(enum RandomTag tag, const void *array, size_t size, size_t count, void *caller)
{
    //rigged
    for (u32 i = 0; i < RIGGED_RNG_COUNT; i++)
    {
        if (gFunctionTestRunnerState->rngList[i].tag == tag)
        {
            u32 element = 0;
            for (u32 index = 0; index < count; index++)
            {
                memcpy(&element, (const u8 *)array + size * index, size);
                if (element == gFunctionTestRunnerState->rngList[i].value)
                    return (const u8 *)array + size * index;
            }
            Test_ExitWithResult(TEST_RESULT_ERROR, SourceLine(0), "%s: RandomElement illegal value requested: %d", gTestRunnerState.test->filename, gFunctionTestRunnerState->rngList[i].value);
        }
    }

    //trials
    /*
    if (tag == STATE->rngTag)
        return RandomElementTrials(tag, array, size, count);
    */

    //default
    return RandomElementArrayDefaultValue(tag, array, size, count, caller);
}

const struct TestRunner gFunctionTestRunner =
{
    .setUp = FunctionTest_SetUp,
    .run = FunctionTest_Run,
    .tearDown = FunctionTest_TearDown,
    .checkProgress = FunctionTest_CheckProgress,
    .randomUniform = FunctionTest_RandomUniform,
    .randomWeightedArray = FunctionTest_RandomWeightedArray,
    .randomElementArray = FunctionTest_RandomElementArray,
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

static void ReinitCallbacks(void)
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
            Test_MgbaPrintf("%s:%d: TIMEOUT", gTestRunnerState.test->filename, SourceLine(0));
            ReinitCallbacks();
            IRQ_LR = ((uintptr_t)JumpToAgbMainLoop & ~1) + 4;
        }
    }
}

void Test_ExitWithResult_(enum TestResult result, u32 stopLine, const void *return1, const char *fmt, ...)
{
    gTestRunnerState.result = result;
    gTestRunnerState.failedAssumptionsBlockLine = stopLine;

    if (result == TEST_RESULT_FAIL)
    {
        switch (gTestRunnerState.expectedFailState)
        {
            case EXPECT_FAIL_OPEN:
            case EXPECT_FAIL_TURN_OPEN:
                gTestRunnerState.expectedFailState = EXPECT_FAIL_SUCCESS;
                break;
            case EXPECT_FAIL_SCENE_OPEN: // EXPECT_FAIL_SUCCESS set in individual Queue functions
                gTestRunnerState.expectedFailState = EXPECT_FAIL_CLOSED;
                break;
            default:
                break;
        }
    }

    if (gTestRunnerState.expectedFailState == EXPECT_FAIL_CLOSED
     && gTestRunnerState.expectedResult == TEST_RESULT_FAIL
     && result == TEST_RESULT_FAIL)
    {
        Test_MgbaPrintf("%s:%d: Expected failure in block from line %d, but failed on line %d",
         gTestRunnerState.test->filename, stopLine,
         gTestRunnerState.expectedFailLine, stopLine);
    }

    ReinitCallbacks();
    if (gTestRunnerState.state == STATE_REPORT_RESULT
     && gTestRunnerState.result != gTestRunnerState.expectedResult)
    {
        if (!gTestRunnerState.test->runner->handleExitWithResult
         || !gTestRunnerState.test->runner->handleExitWithResult(gTestRunnerState.test->data, result))
        {
            if (result == TEST_RESULT_INVALID)
            {
                const void *return0 = __builtin_return_address(0);
                Test_MgbaPrintf("in %p\nin %p", return1, return0);
            }
            // TODO: If 'fmt' starts with ':', insert a space to prevent
            // Hydra interpreting it as a command.
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

s32 Test_MgbaPrintf(const char *fmt, ...)
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

// Bare-bones, supports:
// - %c: print an ASCII character.
// - %C: print a GF-encoded character.
// - %s, %.*s: print an ASCII string.
// - %S, %.*S: print a GF-encoded string.
// - %U: print a GF-encoded upper-case string.
// - %d: print a signed integer.
// - %q: print a Q20.12 fixed-point number.
// - %p: print a pointer (which mgba-rom-test-hydra will convert into a
//   symbol, if possible).
static s32 MgbaVPrintf_(const char *fmt, va_list va)
{
    extern char mini_pchar_decode(u8);

    s32 i = 0;
    s32 n;
    s32 c, d;
    u32 p;
    const char *s;
    const u8 *pokeS;
    while (*fmt)
    {
        switch ((c = *fmt++))
        {
        case '%':
            if (fmt[0] == '.' && fmt[1] == '*')
            {
                fmt += 2;
                n = va_arg(va, int);
            }
            else
            {
                n = INT_MAX;
            }

            switch (*fmt++)
            {
            case '%':
                i = MgbaPutchar_(i, '%');
                break;
            case 'c':
                c = va_arg(va, int);
                i = MgbaPutchar_(i, c);
                break;
            case 'C':
                c = va_arg(va, unsigned);
                i = MgbaPutchar_(i, mini_pchar_decode(c));
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
                    i = MgbaPutchar_(i, '<');
                    i = MgbaPutchar_(i, '0');
                    i = MgbaPutchar_(i, 'x');
                    for (n = 0; n < 7; n++)
                    {
                        unsigned nybble = (p >> (24 - (4*n))) & 0xF;
                        if (nybble <= 9)
                            i = MgbaPutchar_(i, '0' + nybble);
                        else
                            i = MgbaPutchar_(i, 'a' + nybble - 10);
                    }
                    i = MgbaPutchar_(i, '>');
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
                            // TODO: 'min' is a hack, we should have
                            // rounded up the previous number.
                            i = MgbaPutchar_(i, min('0' + ((u + UQ_4_12_ROUND) >> 12), '9'));
                            break;
                        }
                    }
                }
                break;
            case 's':
                s = va_arg(va, const char *);
                while ((c = *s++) != '\0' && n-- > 0)
                    i = MgbaPutchar_(i, c);
                break;
            case 'S':
                pokeS = va_arg(va, const u8 *);
                if (pokeS == NULL)
                {
                    i = MgbaPutchar_(i, 'N');
                    i = MgbaPutchar_(i, 'U');
                    i = MgbaPutchar_(i, 'L');
                    i = MgbaPutchar_(i, 'L');
                }
                else
                {
                    while ((c = *pokeS++) != EOS && n-- > 0)
                        i = MgbaPutchar_(i, mini_pchar_decode(c));
                }
                break;
            case 'U':
                pokeS = va_arg(va, const u8 *);
                bool32 wasUnderscore = FALSE;
                while (*pokeS != EOS)
                {
                    u8 c = *pokeS++;
                    if (CHAR_a <= c && c <= CHAR_z)
                    {
                        i = MgbaPutchar_(i, mini_pchar_decode(gCaseToggleTable[c]));
                        wasUnderscore = FALSE;
                    }
                    else if (CHAR_A <= c && c <= CHAR_Z)
                    {
                        i = MgbaPutchar_(i, mini_pchar_decode(c));
                        wasUnderscore = FALSE;
                    }
                    else if (!wasUnderscore)
                    {
                        i = MgbaPutchar_(i, '_');
                        wasUnderscore = TRUE;
                    }
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

u32 RandomUniform(enum RandomTag tag, u32 lo, u32 hi)
{
    void *caller = __builtin_extract_return_addr(__builtin_return_address(0));
    if (gTestRunnerState.test->runner->randomUniform)
        return gTestRunnerState.test->runner->randomUniform(tag, lo, hi, NULL, caller);
    else
        return RandomUniformDefault(tag, lo, hi);
}

u32 RandomUniformExcept(enum RandomTag tag, u32 lo, u32 hi, bool32 (*reject)(u32))
{
    void *caller = __builtin_extract_return_addr(__builtin_return_address(0));
    if (gTestRunnerState.test->runner->randomUniform)
        return gTestRunnerState.test->runner->randomUniform(tag, lo, hi, reject, caller);
    else
        return RandomUniformExceptDefault(tag, lo, hi, reject);
}

u32 RandomWeightedArray(enum RandomTag tag, u32 sum, u32 n, const u16 *weights)
{
    void *caller = __builtin_extract_return_addr(__builtin_return_address(0));
    if (gTestRunnerState.test->runner->randomWeightedArray)
        return gTestRunnerState.test->runner->randomWeightedArray(tag, sum, n, weights, caller);
    else
        return RandomWeightedArrayDefault(tag, sum, n, weights);
}

const void *RandomElementArray(enum RandomTag tag, const void *array, size_t size, size_t count)
{
    void *caller = __builtin_extract_return_addr(__builtin_return_address(0));
    if (gTestRunnerState.test->runner->randomElementArray)
        return gTestRunnerState.test->runner->randomElementArray(tag, array, size, count, caller);
    else
        return RandomElementArrayDefault(tag, array, size, count);
}

u32 RandomUniformDefaultValue(enum RandomTag tag, u32 lo, u32 hi, bool32 (*reject)(u32), void *caller)
{
    u32 default_ = hi;
    if (reject)
    {
        while (reject(default_))
        {
            if (default_ == lo)
                Test_ExitWithResult(TEST_RESULT_ERROR, SourceLine(0), "RandomUniformExcept called from %p with tag %d rejected all values", caller, tag);
            default_--;
        }
    }
    return default_;
}

u32 RandomWeightedArrayDefaultValue(enum RandomTag tag, u32 n, const u16 *weights, void *caller)
{
    while (weights[n-1] == 0)
    {
        if (n == 1)
            Test_ExitWithResult(TEST_RESULT_ERROR, SourceLine(0), "RandomWeightedArray called from %p with tag %d and all zero weights", caller, tag);
        n--;
    }
    return n-1;
}

const void *RandomElementArrayDefaultValue(enum RandomTag tag, const void *array, size_t size, size_t count, void *caller)
{
    return (const u8 *)array + size * (count - 1);
}

void ClearRiggedRng(void)
{
    struct RiggedRNG zeroRng = {.tag = RNG_NONE, .value = 0};
    for (u32 i = 0; i < RIGGED_RNG_COUNT; i++)
        memcpy(&gFunctionTestRunnerState->rngList[i], &zeroRng, sizeof(zeroRng));
}

void SetupRiggedRng(u32 sourceLine, enum RandomTag randomTag, u32 value)
{
    struct RiggedRNG rng = {.tag = randomTag, .value = value};
    u32 i;
    for (i = 0; i < RIGGED_RNG_COUNT; i++)
    {
        if (gFunctionTestRunnerState->rngList[i].tag == randomTag)
        {
            memcpy(&gFunctionTestRunnerState->rngList[i], &rng, sizeof(rng));
            break;
        }
        else if (gFunctionTestRunnerState->rngList[i].tag > RNG_NONE)
        {
            continue;
        }
        else
        {
            memcpy(&gFunctionTestRunnerState->rngList[i], &rng, sizeof(rng));
            break;
        }
    }
    if (i == RIGGED_RNG_COUNT)
        Test_ExitWithResult(TEST_RESULT_FAIL, __LINE__, "%s:%d: Too many rigged RNGs to set up", gTestRunnerState.test->filename, sourceLine);
}
