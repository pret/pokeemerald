#ifndef GUARD_MENU_H
#define GUARD_MENU_H

#include "text.h"

struct MenuAction
{
   const u8 *text;
   u8 (*func)();
};

struct MenuAction2
{
    const u8 *text;
    void (*func)(u8);
};

void box_print(u8, u8, u8, u8, const void *, s8, const u8 *);

#endif // GUARD_MENU_H
