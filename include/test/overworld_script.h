/* Embedded DSL for testing overworld scripts in isolation.
 * The overworld is not available, so it is only possible to test
 * commands which don't affect the overworld itself, e.g. givemon can
 * be tested because it only alters gPlayerParty, but addobject cannot
 * because it affects object events (which aren't loaded).
 *
 * OVERWORLD_SCRIPT(instructions...)
 * Returns a pointer to a compiled overworld script. Cannot be used to
 * initialize global const data, although the pointer IS to const data.
 * Note that each script command must be followed by a ;, e.g.:
 *     const u8 *myScript = OVERWORLD_SCRIPT(
 *         random 2;
 *         addvar VAR_RESULT, 1;
 *     );
 *
 * RUN_OVERWORLD_SCRIPT(instructions...)
 * Runs an overworld script in the immediate script context, which means
 * that commands like waitstate are not supported.
 *     RUN_OVERWORLD_SCRIPT(
 *         setvar VAR_RESULT, 3;
 *     );
 *     EXPECT_EQ(GetVar(VAR_RESULT), 3); */
#ifndef GUARD_TEST_OVERWORLD_SCRIPT
#define GUARD_TEST_OVERWORLD_SCRIPT

#include "script.h"
#include "test/test.h"

#define OVERWORLD_SCRIPT(...) \
    ({ \
        const u8 *_script; \
        asm("mov %0, pc\n" \
            "b .Lend" STR(__LINE__) "\n" \
            STR(__VA_ARGS__) \
            "\n" \
            "end\n" \
            ".balign 2\n" \
            ".Lend" STR(__LINE__) ":\n" \
        : "=r" (_script)); \
        _script; \
    })

#define RUN_OVERWORLD_SCRIPT(...) RunScriptImmediately(OVERWORLD_SCRIPT(__VA_ARGS__))

// Make overworld script macros available.
asm(".include \"asm/macros/event.inc\"\n");

#endif
