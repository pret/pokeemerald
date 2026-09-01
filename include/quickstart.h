#ifndef GUARD_QUICKSTART_H
#define GUARD_QUICKSTART_H

#include "config/quickstart.h"

#if RELEASE
    #define QUICKSTART FALSE
#else
    #define QUICKSTART ENABLE_QUICKSTART
#endif

void CreateQuickstartHud(void);
void Quickstart(void);

#endif // GUARD_QUICKSTART_H
