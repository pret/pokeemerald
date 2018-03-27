#ifndef GUARD_START_MENU_H
#define GUARD_START_MENU_H

extern bool8 (*gMenuCallback)(void);   // Defined in sym_common.txt

void AppendToList(u8* list, u8* pos, u8 newEntry);

#endif // GUARD_START_MENU_H
