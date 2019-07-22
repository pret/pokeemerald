#ifndef GUARD_PLAYER_PC_H
#define GUARD_PLAYER_PC_H

#include "menu.h"

// local task defines
#define PAGE_INDEX data[0]
#define ITEMS_ABOVE_TOP data[1]
#define NUM_ITEMS data[1]
#define NUM_QUANTITY_ROLLER data[3]
#define NUM_PAGE_ITEMS data[4]
// not used
#define CURRENT_ITEM_STORAGE_MENU data[3]
// not used
#define SWAP_ITEM_INDEX data[8]
#define SWITCH_MODE_ACTIVE data[9]

// this is potentially an ewram access occuring in high ewram. TODO: investigate this further.
#define NEW_GAME_PC_ITEMS(i, type) ((u16)((u16 *)gNewGamePCItems + type)[i * 2])

// defined and used in the above macro
enum
{
    PC_ITEM_ID,
    PC_QUANTITY
};

// player PC menu options
enum
{
    PLAYERPC_MENU_ITEMSTORAGE,
    PLAYERPC_MENU_MAILBOX,
    PLAYERPC_MENU_DECORATION,
    PLAYERPC_MENU_TURNOFF
};

// item storage menus
enum
{
    ITEMPC_MENU_WITHDRAW,
    ITEMPC_MENU_DEPOSIT,
    ITEMPC_MENU_TOSS,
    ITEMPC_MENU_EXIT
};

// mailbox mail options
enum
{
    MAILBOX_READ,
    MAILBOX_MOVE_TO_BAG,
    MAILBOX_GIVE,
    MAILBOX_CANCEL,
};

// special item description handlers
enum
{
    ITEMPC_SWITCH_WHICH_ITEM = 0xFFF7,
    ITEMPC_OKAY_TO_THROW_AWAY,
    ITEMPC_TOO_IMPORTANT,
    ITEMPC_NO_MORE_ROOM,
    ITEMPC_THREW_AWAY_ITEM,
    ITEMPC_HOW_MANY_TO_TOSS,
    ITEMPC_WITHDREW_THING,
    ITEMPC_HOW_MANY_TO_WITHDRAW,
    ITEMPC_GO_BACK_TO_PREV
};

struct PlayerPCItemPageStruct
{
    u16 cursorPos;
    u16 itemsAbove;
    u8 pageItems;
    u8 count;
    u8 filler[3];
    u8 scrollIndicatorId;
};

// Exported type declarations

// Exported RAM declarations
extern struct PlayerPCItemPageStruct playerPCItemPageInfo;

// Exported ROM declarations
extern const struct MenuAction gMailboxMailOptions[];

void ReshowPlayerPC(u8 taskId);
void sub_816B31C(void);
void Mailbox_ReturnToMailListAfterDeposit(void);
void NewGameInitPCItems(void);


#endif //GUARD_PLAYER_PC_H
