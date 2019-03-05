#ifndef GUARD_POKENAV_H
#define GUARD_POKENAV_H
#include "list_menu.h"

bool8 sub_81D20BC(void *arg0);
bool8 sub_81D312C(void *arg0);
void sub_81D1ED4(void *arg0);
void sub_81D2108(void *arg0);
void sub_81D20AC(void *arg0);
void sub_81D2230(void *arg0);
void sub_81D3464(void *arg0);
void sub_81D3480(void *arg0, u8 arg1);
void sub_81D2754(void *arg0, void *arg1);
void sub_81D1F84(void *arg0, void *arg1, void *arg2);
bool8 sub_81D4A58(struct EventObject*);
void MoveRelearnerPrintText(u8 *);
u16 MoveRelearnerRunTextPrinters(void);
void MoveRelearnerCreateYesNoMenu(void);
u8 LoadMoveRelearnerMovesList(const struct ListMenuItem *items, u16 numChoices);
void InitMoveRelearnerWindows(bool8 useContextWindow);
bool8 EventObjectIsFarawayIslandMew(struct EventObject *);
u32 sub_81D427C(void);
void sub_81D4998(void);

#endif //GUARD_POKENAV_H
