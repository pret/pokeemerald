#ifndef ASSERTF_H
#define ASSERTF_H

/* Formatted assert.
 *
 * Asserts are a way to catch programmer errors at run-time. They should
 * be used when both of the following are true:
 * 1. It's impossible to catch the error at compile-time.
 * 2. The error is caused only by the programmer.
 * For example:
 * - removeobject for a local ID that isn't in the object event
 *   templates is a programmer error because the object could never be
 *   spawned.
 * - removeobject for a local ID that isn't spawned is not (necessarily)
 *   a programmer error because the object could have been despawned by
 *   the player.
 * - Trying to choose a move from the Fight menu when it's disabled is
 *   not a programmer error because the player is able to try to choose
 *   the move.
 * - The battle engine receiving a disabled move as the chosen move is
 *   a programmer error because it should have been rejected by the UI.
 *
 * When possible, prefer to catch errors at compile-time with things
 * like STATIC_ASSERT rather than at run-time with assertf.
 *
 * assertf(cond);
 * assertf(cond) { recovery... }
 * assertf(cond, fmt, ...);
 * assertf(cond, fmt, ...) { recovery... }
 *
 * If cond is FALSE:
 * - In a release build: executes the recovery code (if any).
 * - In a debug build: shows a resumable crash screen and executes the
 *   recovery code (if any).
 * - In a test build: causes the test to be INVALID.
 *
 * Usually the recovery code makes the function do nothing, for example:
 * - warp to a map that doesn't exist shouldn't warp anywhere.
 * - addobject of a local ID that doesn't exist shouldn't add anything.
 *
 * But sometimes the function has to return something, in which case the
 * recovery code does something that seems "reasonable", for example:
 * - CreateMonWithGenderNatureLetter should ignore an illegal gender or
 *   letter. */
#define assertf(cond, ...) CAT(_ASSERTF, FIRST(__VA_OPT__(_FMT,) _COND))(cond __VA_OPT__(,) __VA_ARGS__)

/* fatal_assertf(cond);
 * fatal_assertf(cond, fmt, ...);
 *
 * If cond is FALSE:
 * - In a release build: shows an unresumable crash screen.
 * - In a debug build: shows an unresumable crash screen.
 * - In a test build: causes the test to be an ERROR.
 *
 * fatal_assertf is useful in cases where a function cannot recover from
 * an error and callers are assumed not to check for an error. If the
 * caller could recover from the error, offer Foo which calls
 * fatal_assertf and FooUnchecked which returns an error code (e.g.
 * Alloc and AllocUnchecked). */
#define fatal_assertf(cond, ...) CAT(_FATALASSERTF, FIRST(__VA_OPT__(_FMT,) _COND))(cond __VA_OPT__(,) __VA_ARGS__)

/* errorf(fmt, ...);
 *
 * Equivalent to assertf(FALSE, fmt, ...);
 * Useful for situations like:
 *   if (cond1)
 *     code1;
 *   else if (cond2)
 *     code2;
 *   else
 *     errorf("neither cond1 nor cond2");
 * Or:
 *   for (i = 0; i < n; i++)
 *   {
 *     if (array[i].member == value)
 *       return i;
 *   }
 *   errorf("member not found"); */
#define errorf(fmt, ...) _ASSERTF_HANDLE("%s:%d: " fmt, __FILE__, __LINE__ __VA_OPT__(,) __VA_ARGS__)

/* fatalf(fmt, ...);
 *
 * Equivalent to fatal_assertf(FALSE, fmt, ...); */
#define fatalf(fmt, ...) _FATALASSERTF_HANDLE("%s:%d: " fmt, __FILE__, __LINE__ __VA_OPT__(,) __VA_ARGS__)

#define _ASSERTF_COND(cond) for (bool32 _recover = !(cond); _recover && (_ASSERTF_HANDLE("%s:%d: %s", __FILE__, __LINE__, STR(cond)), TRUE); _recover = FALSE)

#define _ASSERTF_FMT(cond, fmt, ...) for (bool32 _recover = !(cond); _recover && (_ASSERTF_HANDLE("%s:%d: " fmt, __FILE__, __LINE__ __VA_OPT__(,) __VA_ARGS__), TRUE); _recover = FALSE)

#define _FATALASSERTF_COND(cond) do { if (!(cond)) _FATALASSERTF_HANDLE("%s:%d: %s", __FILE__, __LINE__, STR(cond)); } while (0)

#define _FATALASSERTF_FMT(cond, fmt, ...) do { if (!(cond)) _FATALASSERTF_HANDLE("%s:%d: " fmt, __FILE__, __LINE__ __VA_OPT__(,) __VA_ARGS__); } while (0)

#if RELEASE
#define _ASSERTF_HANDLE(...) (void)0
#define _FATALASSERTF_HANDLE(fmt, ...) FatalfCrashScreen(__builtin_return_address(0), fmt, __VA_ARGS__)
#elif TESTING
#include "test_result.h"
#define _ASSERTF_HANDLE(fmt, ...) Test_ExitWithResult(TEST_RESULT_INVALID, 0, fmt, __VA_ARGS__)
#define _FATALASSERTF_HANDLE(fmt, ...) Test_ExitWithResult(TEST_RESULT_CRASH, 0, fmt, __VA_ARGS__)
#else
#define _ASSERTF_HANDLE(fmt, ...) AssertfCrashScreen(__builtin_return_address(0), fmt, __VA_ARGS__)
#define _FATALASSERTF_HANDLE(fmt, ...) FatalfCrashScreen(__builtin_return_address(0), fmt, __VA_ARGS__)
#endif

void AssertfCrashScreen(const void *return0, const char *fmt, ...);
_Noreturn void FatalfCrashScreen(const void *return0, const char *fmt, ...);

#endif
