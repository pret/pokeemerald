#include "spylog.h"
#include "debug.h"
#include "global.h"
#include "main.h"

static int sLastOverworld;
static int sLastBattle;

static void SpyState(const char *tag, int current, int *last) {
    if (current != *last) {
        DEBUG_PRINT("[%s] state -> %d", tag, current);
        *last = current;
    }
}

extern struct Main gMain;  // already defined in engine

void DebugHook_Overworld(void) {
    SpyState("Overworld", gMain.state, &sLastOverworld);
}

void DebugHook_Battle(void) {
    SpyState("Battle", gMain.state, &sLastBattle);
}
