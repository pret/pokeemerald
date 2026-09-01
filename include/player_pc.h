#ifndef GUARD_PLAYER_PC_H
#define GUARD_PLAYER_PC_H

#include "menu.h"

struct PlayerPCItemPageStruct
{
    u16 cursorPos;
    u16 itemsAbove;
    u8 pageItems;
    u8 count;
    u8 scrollIndicatorTaskId;
};

extern struct PlayerPCItemPageStruct gPlayerPCItemPageInfo;

extern const struct MenuAction gMailboxMailOptions[];

void ReshowPlayerPC(u8 var);
void CB2_PlayerPCExitBagMenu(void);
void Mailbox_ReturnToMailListAfterDeposit(void);
void NewGameInitPCItems(void);


#endif //GUARD_PLAYER_PC_H
