#ifndef GUARD_ITEM_MENU_H
#define GUARD_ITEM_MENU_H

#include "item.h"
#include "menu_helpers.h"

enum {
    ITEMMENULOCATION_FIELD,
    ITEMMENULOCATION_BATTLE,
    ITEMMENULOCATION_PARTY,
    ITEMMENULOCATION_SHOP,
    ITEMMENULOCATION_BERRY_TREE,
    ITEMMENULOCATION_BERRY_BLENDER_CRUSH,
    ITEMMENULOCATION_ITEMPC,
    ITEMMENULOCATION_FAVOR_LADY,
    ITEMMENULOCATION_QUIZ_LADY,
    ITEMMENULOCATION_APPRENTICE,
    ITEMMENULOCATION_WALLY,
    ITEMMENULOCATION_PCBOX,
    ITEMMENULOCATION_LAST,
};

// Window IDs for the item menu
enum {
    ITEMWIN_1x1,
    ITEMWIN_1x2,
    ITEMWIN_2x2,
    ITEMWIN_2x3,
    ITEMWIN_MESSAGE,
    ITEMWIN_YESNO_LOW,
    ITEMWIN_YESNO_HIGH,
    ITEMWIN_QUANTITY,
    ITEMWIN_QUANTITY_WIDE,
    ITEMWIN_MONEY,
    ITEMWIN_COUNT
};

#define ITEMMENU_SWAP_LINE_LENGTH 8  // Swap line is 8 sprites long
enum {
    ITEMMENUSPRITE_BAG,
    ITEMMENUSPRITE_BALL,
    ITEMMENUSPRITE_ITEM,
    ITEMMENUSPRITE_ITEM_ALT, // Need two when selecting new item
    ITEMMENUSPRITE_SWAP_LINE,
    ITEMMENUSPRITE_COUNT = ITEMMENUSPRITE_SWAP_LINE + ITEMMENU_SWAP_LINE_LENGTH,
};

struct BagPosition
{
    void (*exitCallback)(void);
    u8 location;
    u8 pocket;
    u16 pocketSwitchArrowPos;
    u16 cursorPosition[POCKETS_COUNT];
    u16 scrollPosition[POCKETS_COUNT];
};

extern struct BagPosition gBagPosition;

struct BagMenu
{
    void (*newScreenCallback)(void);
    u8 tilemapBuffer[BG_SCREEN_SIZE];
    u8 spriteIds[ITEMMENUSPRITE_COUNT];
    u8 windowIds[ITEMWIN_COUNT];
    u8 toSwapPos;
    u8 pocketSwitchDisabled:4;
    u8 itemIconSlot:2;
    u8 inhibitItemDescriptionPrint:1;
    u8 hideCloseBagText:1;
    u8 unused1[2];
    u8 pocketScrollArrowsTask;
    u8 pocketSwitchArrowsTask;
    const u8 *contextMenuItemsPtr;
    u8 contextMenuItemsBuffer[4];
    u8 contextMenuNumItems;
    u8 numItemStacks[POCKETS_COUNT];
    u8 numShownItems[POCKETS_COUNT];
    s16 graphicsLoadState;
    u8 unused2[14];
    u8 ALIGNED(4) pocketNameBuffer[32][32];
    u8 unused3[4];
};

extern struct BagMenu *gBagMenu;
extern u16 gSpecialVar_ItemId;

void CB2_GoToItemDepositMenu(void);
void FavorLadyOpenBagMenu(void);
void QuizLadyOpenBagMenu(void);
void ApprenticeOpenBagMenu(void);
void CB2_BagMenuFromBattle(void);
void UpdatePocketListPosition(u8 pocketId);
void CB2_ReturnToBagMenuPocket(void);
void CB2_BagMenuFromStartMenu(void);
u8 GetItemListPosition(u8 pocketId);
bool8 UseRegisteredKeyItemOnField(void);
void CB2_GoToSellMenu(void);
void GoToBagMenu(u8 bagMenuType, u8 pocketId, void ( *exitCallback)());
void DoWallyTutorialBagMenu(void);
void ResetBagScrollPositions(void);
void ChooseBerryForMachine(void (*exitCallback)(void));
void CB2_ChooseBerry(void);
void Task_FadeAndCloseBagMenu(u8 taskId);
void BagMenu_YesNo(u8 taskId, u8 windowType, const struct YesNoFuncTable* funcTable);
void UpdatePocketItemList(u8 pocketId);
void DisplayItemMessage(u8 taskId, u8 fontId, const u8 *str, void ( *callback)(u8 taskId));
void DisplayItemMessageOnField(u8 taskId, const u8 *src, TaskFunc callback);
void CloseItemMessage(u8 taskId);
void ItemMenu_RotomCatalog(u8 taskId);

#endif //GUARD_ITEM_MENU_H
