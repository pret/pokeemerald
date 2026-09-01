#ifndef GUARD_TEST_H
#define GUARD_TEST_H

#include "test_result.h"
#include "test_runner.h"
#include "random.h"

#define MAX_PROCESSES 32 // See also tools/mgba-rom-test-hydra/main.c
#define RIGGED_RNG_COUNT 8

struct TestRunner
{
    u32 (*estimateCost)(void *);
    void (*setUp)(void *);
    void (*run)(void *);
    void (*tearDown)(void *);
    bool32 (*checkProgress)(void *);
    bool32 (*handleExitWithResult)(void *, enum TestResult);
    u32 (*randomUniform)(enum RandomTag tag, u32 lo, u32 hi, bool32 (*reject)(u32), void *caller);
    u32 (*randomWeightedArray)(enum RandomTag tag, u32 sum, u32 n, const u16 *weights, void *caller);
    const void* (*randomElementArray)(enum RandomTag tag, const void *array, size_t size, size_t count, void *caller);
};

struct Test
{
    const char *name;
    const char *filename;
    const struct TestRunner *runner;
    void *data;
    u16 sourceLine;
};

enum TestFilterMode
{
    TEST_FILTER_MODE_TEST_NAME_PREFIX,
    TEST_FILTER_MODE_TEST_NAME_INFIX,
    TEST_FILTER_MODE_FILENAME_EXACT,
};

enum ExpectFailState
{
    NO_EXPECT_FAIL,
    EXPECT_FAIL_OPEN,
    EXPECT_FAIL_TURN_OPEN,
    EXPECT_FAIL_SCENE_OPEN,
    EXPECT_FAIL_SUCCESS,
    EXPECT_FAIL_CLOSED
};

struct TestRunnerState
{
    u8 state;
    u8 exitCode;
    enum TestFilterMode filterMode:8;
    const char *skipFilename;
    u32 failedAssumptionsBlockLine;
    const struct Test *test;
    u32 processCosts[MAX_PROCESSES];

    enum TestResult result:8;
    enum TestResult expectedResult:8;
    bool8 expectLeaks:1;
    bool8 inBenchmark:1;
    bool8 tearDown:1;
    u32 timeoutSeconds;
    s32 expectedFailLine;
    enum ExpectFailState expectedFailState;
};

struct PersistentTestRunnerState
{
    u32 address:28;
    u32 state:1;
    u32 expectCrash:1;
    u32 unused_30:2;
};

extern const u8 gTestRunnerN;
extern const u8 gTestRunnerI;
extern const char gTestRunnerArgv[256];

extern const struct TestRunner gAssumptionsRunner;

struct RiggedRNG
{
    u16 tag;
    u16 value;
};

struct FunctionTestRunnerState
{
    u16 parameters;
    u16 runParameter;
    u16 checkProgressParameter;
    struct RiggedRNG rngList[RIGGED_RNG_COUNT];
};

extern const struct TestRunner gFunctionTestRunner;
extern struct FunctionTestRunnerState *gFunctionTestRunnerState;

extern struct TestRunnerState gTestRunnerState;
extern struct PersistentTestRunnerState gPersistentTestRunnerState;

void CB2_TestRunner(void);

void Test_ExpectedResult(enum TestResult);
void Test_ExpectLeaks(bool32);
void Test_ExpectCrash(bool32);
void Test_ExpectFail(u32 failLine);
u32 SourceLine(u32 sourceLineOffset);
u32 SourceLineOffset(u32 sourceLine);
void SetupRiggedRng(u32 sourceLine, enum RandomTag randomTag, u32 value);
void ClearRiggedRng();

s32 Test_MgbaPrintf(const char *fmt, ...);

#define TEST(_name) \
    static void CAT(Test, __LINE__)(void); \
    __attribute__((section(".tests"), used)) static const struct Test CAT(sTest, __LINE__) = \
    { \
        .name = _name, \
        .filename = __FILE__, \
        .runner = &gFunctionTestRunner, \
        .sourceLine = __LINE__, \
        .data = (void *)CAT(Test, __LINE__), \
    }; \
    static void CAT(Test, __LINE__)(void)

#define ASSUMPTIONS \
    static void Assumptions(void); \
    __attribute__((section(".tests"), used, no_reorder)) static const struct Test sAssumptions = \
    { \
        .name = "ASSUMPTIONS: " __FILE__, \
        .filename = __FILE__, \
        .runner = &gAssumptionsRunner, \
        .sourceLine = __LINE__, \
        .data = Assumptions, \
    }; \
    static void Assumptions(void)

#define ASSUME(c) \
    do \
    { \
        if (!(c)) \
            Test_ExitWithResult(TEST_RESULT_ASSUMPTION_FAIL, __LINE__, "%s:%d: ASSUME failed", gTestRunnerState.test->filename, __LINE__); \
    } while (0)

#define EXPECT(c) \
    do \
    { \
        if (!(c)) \
            Test_ExitWithResult(TEST_RESULT_FAIL, __LINE__, "%s:%d: EXPECT failed", gTestRunnerState.test->filename, __LINE__); \
    } while (0)

#define EXPECT_EQ(a, b) \
    do \
    { \
        typeof(a) _a = (a), _b = (b); \
        if (_a != _b) \
            Test_ExitWithResult(TEST_RESULT_FAIL, __LINE__, "%s:%d: EXPECT_EQ(%d, %d) failed", gTestRunnerState.test->filename, __LINE__, a, b); \
    } while (0)

#define EXPECT_NE(a, b) \
    do \
    { \
        typeof(a) _a = (a), _b = (b); \
        if (_a == _b) \
            Test_ExitWithResult(TEST_RESULT_FAIL, __LINE__, "%s:%d: EXPECT_NE(%d, %d) failed", gTestRunnerState.test->filename, __LINE__, a, b); \
    } while (0)

#define EXPECT_LT(a, b) \
    do \
    { \
        typeof(a) _a = (a), _b = (b); \
        if (_a >= _b) \
            Test_ExitWithResult(TEST_RESULT_FAIL, __LINE__, "%s:%d: EXPECT_LT(%d, %d) failed", gTestRunnerState.test->filename, __LINE__, a, b); \
    } while (0)

#define EXPECT_LE(a, b) \
    do \
    { \
        typeof(a) _a = (a), _b = (b); \
        if (_a > _b) \
            Test_ExitWithResult(TEST_RESULT_FAIL, __LINE__, "%s:%d: EXPECT_LE(%d, %d) failed", gTestRunnerState.test->filename, __LINE__, a, b); \
    } while (0)

#define EXPECT_GT(a, b) \
    do \
    { \
        typeof(a) _a = (a), _b = (b); \
        if (_a <= _b) \
            Test_ExitWithResult(TEST_RESULT_FAIL, __LINE__, "%s:%d: EXPECT_GT(%d, %d) failed", gTestRunnerState.test->filename, __LINE__, a, b); \
    } while (0)

#define EXPECT_GE(a, b) \
    do \
    { \
        typeof(a) _a = (a), _b = (b); \
        if (_a < _b) \
            Test_ExitWithResult(TEST_RESULT_FAIL, __LINE__, "%s:%d: EXPECT_GE(%d, %d) failed", gTestRunnerState.test->filename, __LINE__, a, b); \
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
        Test_MgbaPrintf(#a ": %d ticks, " #b ": %d ticks", a_, b_); \
        if (((a_ - BENCHMARK_ABS) * BENCHMARK_REL) >= (b_ * 100)) \
            Test_ExitWithResult(TEST_RESULT_FAIL, __LINE__, "%s:%d: EXPECT_FASTER(" #a ", " #b ") failed", gTestRunnerState.test->filename, __LINE__); \
    } while (0)

#define EXPECT_SLOWER(a, b) \
    do \
    { \
        u32 a_ = (a).ticks; u32 b_ = (b).ticks; \
        Test_MgbaPrintf(#a ": %d ticks, " #b ": %d ticks", a_, b_); \
        if ((a_ * 100) <= ((b_ - BENCHMARK_ABS) * BENCHMARK_REL)) \
            Test_ExitWithResult(TEST_RESULT_FAIL, __LINE__, "%s:%d: EXPECT_SLOWER(" #a ", " #b ") failed", gTestRunnerState.test->filename, __LINE__); \
    } while (0)

#define KNOWN_FAILING \
    Test_ExpectedResult(TEST_RESULT_KNOWN_FAIL)

#define KNOWN_LEAKING \
    Test_ExpectLeaks(TRUE)

#define KNOWN_CRASHING \
    Test_ExpectCrash(TRUE)

#define EXPECT_FAIL for (u32 _expect_fail = (Test_ExpectFail(-1), 1); _expect_fail; Test_ExpectFail(__LINE__), _expect_fail = 0)

#define PARAMETRIZE if (gFunctionTestRunnerState->parameters++ == gFunctionTestRunnerState->runParameter)

#define PARAMETRIZE_LABEL(f, ...) if (gFunctionTestRunnerState->parameters++ == gFunctionTestRunnerState->runParameter && (Test_MgbaPrintf(":N%s: (%d/%d) " f, gTestRunnerState.test->name, gFunctionTestRunnerState->runParameter + 1, gFunctionTestRunnerState->parameters, __VA_ARGS__), 1))

#define SET_RNG(tag, value) SetupRiggedRng(__LINE__, tag, value)

#define TO_DO \
    do { \
        Test_ExpectedResult(TEST_RESULT_TODO); \
        Test_ExitWithResult(TEST_RESULT_TODO, __LINE__, "%s:%d: EXPECT_TO_DO", gTestRunnerState.test->filename, __LINE__); \
    } while (0)

#endif
