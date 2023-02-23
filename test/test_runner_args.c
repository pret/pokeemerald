#include "global.h"

// These values are patched by patchelf. Therefore we have put them in
// their own TU so that the optimizer cannot inline them.
const bool8 gTestRunnerEnabled = TRUE;
const u8 gTestRunnerN = 0;
const u8 gTestRunnerI = 0;
const char gTestRunnerArgv[256] = {'\0'};
