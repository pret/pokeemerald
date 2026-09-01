#ifndef GUARD_TEST_RESULT_H
#define GUARD_TEST_RESULT_H

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
    TEST_RESULT_KNOWN_FAIL,
    TEST_RESULT_FLAKY,
};

void Test_ExitWithResult_(enum TestResult, u32 stopLine, const void *return0, const char *fmt, ...);
#define Test_ExitWithResult(result, stopLine, ...) Test_ExitWithResult_(result, stopLine, __builtin_return_address(0), __VA_ARGS__)

#endif
