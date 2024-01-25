#ifndef GUARD_TEST_H
#define GUARD_TEST_H

#include "test_runner.h"

#define MAX_PROCESSES 32 // See also tools/mgba-rom-test-hydra/main.c

enum TestResult
{
    TEST_RESULT_FAIL,
    TEST_RESULT_PASS,
    TEST_RESULT_ASSUMPTION_FAIL,
    TEST_RESULT_INVALID,
    TEST_RESULT_ERROR,
    TEST_RESULT_TIMEOUT,
    TEST_RESULT_CRASH,
    TEST_RESULT_TODO,
};

struct TestRunner
{
    u32 (*estimateCost)(void *);
    void (*setUp)(void *);
    void (*run)(void *);
    void (*tearDown)(void *);
    bool32 (*checkProgress)(void *);
    bool32 (*handleExitWithResult)(void *, enum TestResult);
};

struct Test
{
    const char *name;
    const char *filename;
    const struct TestRunner *runner;
    void *data;
};

struct TestRunnerState
{
    u8 state;
    u8 exitCode;
    const char *skipFilename;
    const struct Test *test;
    u32 processCosts[MAX_PROCESSES];

    u8 result;
    u8 expectedResult;
    bool8 expectLeaks:1;
    bool8 inBenchmark:1;
    bool8 tearDown:1;
    u32 timeoutSeconds;
};

extern const u8 gTestRunnerN;
extern const u8 gTestRunnerI;
extern const char gTestRunnerArgv[256];

extern const struct TestRunner gAssumptionsRunner;

struct FunctionTestRunnerState
{
    u16 parameters;
    u16 runParameter;
};

extern const struct TestRunner gFunctionTestRunner;
extern struct FunctionTestRunnerState *gFunctionTestRunnerState;

extern struct TestRunnerState gTestRunnerState;

void CB2_TestRunner(void);

void Test_ExpectedResult(enum TestResult);
void Test_ExpectLeaks(bool32);
void Test_ExitWithResult(enum TestResult, const char *fmt, ...);

s32 MgbaPrintf_(const char *fmt, ...);

#define TEST(_name) \
    static void CAT(Test, __LINE__)(void); \
    __attribute__((section(".tests"))) static const struct Test CAT(sTest, __LINE__) = \
    { \
        .name = _name, \
        .filename = __FILE__, \
        .runner = &gFunctionTestRunner, \
        .data = (void *)CAT(Test, __LINE__), \
    }; \
    static void CAT(Test, __LINE__)(void)

#define ASSUMPTIONS \
    static void Assumptions(void); \
    __attribute__((section(".tests"))) static const struct Test sAssumptions = \
    { \
        .name = "ASSUMPTIONS: " __FILE__, \
        .filename = __FILE__, \
        .runner = &gAssumptionsRunner, \
        .data = Assumptions, \
    }; \
    static void Assumptions(void)

#define ASSUME(c) \
    do \
    { \
        if (!(c)) \
            Test_ExitWithResult(TEST_RESULT_ASSUMPTION_FAIL, "%s:%d: ASSUME failed", gTestRunnerState.test->filename, __LINE__); \
    } while (0)

#define EXPECT(c) \
    do \
    { \
        if (!(c)) \
            Test_ExitWithResult(TEST_RESULT_FAIL, "%s:%d: EXPECT failed", gTestRunnerState.test->filename, __LINE__); \
    } while (0)

#define EXPECT_EQ(a, b) \
    do \
    { \
        typeof(a) _a = (a), _b = (b); \
        if (_a != _b) \
            Test_ExitWithResult(TEST_RESULT_FAIL, "%s:%d: EXPECT_EQ(%d, %d) failed", gTestRunnerState.test->filename, __LINE__, _a, _b); \
    } while (0)

#define EXPECT_NE(a, b) \
    do \
    { \
        typeof(a) _a = (a), _b = (b); \
        if (_a == _b) \
            Test_ExitWithResult(TEST_RESULT_FAIL, "%s:%d: EXPECT_NE(%d, %d) failed", gTestRunnerState.test->filename, __LINE__, _a, _b); \
    } while (0)

#define EXPECT_LT(a, b) \
    do \
    { \
        typeof(a) _a = (a), _b = (b); \
        if (_a >= _b) \
            Test_ExitWithResult(TEST_RESULT_FAIL, "%s:%d: EXPECT_LT(%d, %d) failed", gTestRunnerState.test->filename, __LINE__, _a, _b); \
    } while (0)

#define EXPECT_LE(a, b) \
    do \
    { \
        typeof(a) _a = (a), _b = (b); \
        if (_a > _b) \
            Test_ExitWithResult(TEST_RESULT_FAIL, "%s:%d: EXPECT_LE(%d, %d) failed", gTestRunnerState.test->filename, __LINE__, _a, _b); \
    } while (0)

#define EXPECT_GT(a, b) \
    do \
    { \
        typeof(a) _a = (a), _b = (b); \
        if (_a <= _b) \
            Test_ExitWithResult(TEST_RESULT_FAIL, "%s:%d: EXPECT_GT(%d, %d) failed", gTestRunnerState.test->filename, __LINE__, _a, _b); \
    } while (0)

#define EXPECT_GE(a, b) \
    do \
    { \
        typeof(a) _a = (a), _b = (b); \
        if (_a < _b) \
            Test_ExitWithResult(TEST_RESULT_FAIL, "%s:%d: EXPECT_GE(%d, %d) failed", gTestRunnerState.test->filename, __LINE__, _a, _b); \
    } while (0)

struct Benchmark { s32 ticks; };

static inline void BenchmarkStart(void)
{
    gTestRunnerState.inBenchmark = TRUE;
    // Wait for a v-blank so that comparing two benchmarks is not affected
    // by the v-count (different numbers of IRQs may run).
    VBlankIntrWait();
    REG_TM3CNT = (TIMER_ENABLE | TIMER_64CLK) << 16;
}

static inline struct Benchmark BenchmarkStop(void)
{
    REG_TM3CNT_H = 0;
    gTestRunnerState.inBenchmark = FALSE;
    return (struct Benchmark) { REG_TM3CNT_L };
}

#define BENCHMARK(id) \
    for (BenchmarkStart(); gTestRunnerState.inBenchmark; *(id) = BenchmarkStop())

// An approximation of how much overhead benchmarks introduce.
#define BENCHMARK_ABS 2

// An approximation for what percentage faster a benchmark has to be for
// us to be confident that it's faster than another.
#define BENCHMARK_REL 95

#define EXPECT_FASTER(a, b) \
    do \
    { \
        u32 a_ = (a).ticks; u32 b_ = (b).ticks; \
        MgbaPrintf_(#a ": %d ticks, " #b ": %d ticks", a_, b_); \
        if (((a_ - BENCHMARK_ABS) * BENCHMARK_REL) >= (b_ * 100)) \
            Test_ExitWithResult(TEST_RESULT_FAIL, "%s:%d: EXPECT_FASTER(" #a ", " #b ") failed", gTestRunnerState.test->filename, __LINE__); \
    } while (0)

#define EXPECT_SLOWER(a, b) \
    do \
    { \
        u32 a_ = (a).ticks; u32 b_ = (b).ticks; \
        MgbaPrintf_(#a ": %d ticks, " #b ": %d ticks", a_, b_); \
        if ((a_ * 100) <= ((b_ - BENCHMARK_ABS) * BENCHMARK_REL)) \
            Test_ExitWithResult(TEST_RESULT_FAIL, "%s:%d: EXPECT_SLOWER(" #a ", " #b ") failed", gTestRunnerState.test->filename, __LINE__); \
    } while (0)

#define KNOWN_FAILING \
    Test_ExpectedResult(TEST_RESULT_FAIL)

#define KNOWN_LEAKING \
    Test_ExpectLeaks(TRUE)

#define PARAMETRIZE if (gFunctionTestRunnerState->parameters++ == gFunctionTestRunnerState->runParameter)

#define TO_DO \
    do { \
        Test_ExpectedResult(TEST_RESULT_TODO); \
        Test_ExitWithResult(TEST_RESULT_TODO, "%s:%d: EXPECT_TO_DO", gTestRunnerState.test->filename, __LINE__); \
    } while (0)

#endif
