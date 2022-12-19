#ifndef GUARD_BATTLE_PYRAMID_BAG_H
#define GUARD_BATTLE_PYRAMID_BAG_H

#include "list_menu.h"

enum {
    PYRAMIDBAG_LOC_FIELD,
    PYRAMIDBAG_LOC_BATTLE,
    PYRAMIDBAG_LOC_PARTY,
    PYRAMIDBAG_LOC_CHOOSE_TOSS,
    PYRAMIDBAG_LOC_PREV,
};

enum {
    PBAG_SPRITE_BAG,
    PBAG_SPRITE_ITEM_ICON,
    PBAG_SPRITE_ITEM_ICON_ALT,
    PBAG_SPRITE_SWAP_LINE_START, // Swap line consists of 8 sprites
    PBAG_SPRITE_SWAP_LINE_2,
    PBAG_SPRITE_SWAP_LINE_3,
    PBAG_SPRITE_SWAP_LINE_4,
    PBAG_SPRITE_SWAP_LINE_5,
    PBAG_SPRITE_SWAP_LINE_6,
    PBAG_SPRITE_SWAP_LINE_7,
    PBAG_SPRITE_SWAP_LINE_END,
    PBAG_SPRITE_COUNT
};
#define NUM_SWAP_LINE_SPRITES (1 + PBAG_SPRITE_SWAP_LINE_END - PBAG_SPRITE_SWAP_LINE_START)

struct PyramidBagMenu
{
    void (*newScreenCallback)(void);
    u8 tilemapBuffer[BG_SCREEN_SIZE];
    u8 spriteIds[PBAG_SPRITE_COUNT];
    u8 windowIds[5];
    u8 toSwapPos;
    bool8 isAltIcon; // Two item icons loaded at a time. Tracks which to show next
    u8 scrollIndicatorsTaskId;
    const u8 *menuActionIds;
    u8 unused1[4];
    u8 menuActionsCount;
    u8 listMenuCount;
    u8 listMenuMaxShown;
    struct ListMenuItem bagListItems[PYRAMID_BAG_ITEMS_COUNT + 1];
    u8 itemStrings[PYRAMID_BAG_ITEMS_COUNT + 1][ITEM_NAME_LENGTH + 10];
    s16 state;
    u8 unused2[4];
};

struct PyramidBagMenuState
{
    void (*exitCallback)(void);
    u8 location;
    u16 cursorPosition;
    u16 scrollPosition;
};

extern struct PyramidBagMenu *gPyramidBagMenu;
extern struct PyramidBagMenuState gPyramidBagMenuState;

void InitBattlePyramidBagCursorPosition(void);
void CB2_PyramidBagMenuFromStartMenu(void);
void CB2_ReturnToPyramidBagMenu(void);
void UpdatePyramidBagList(void);
void UpdatePyramidBagCursorPos(void);
void GoToBattlePyramidBagMenu(u8 location, void (*exitCallback)(void));
void Task_CloseBattlePyramidBagMessage(u8 taskId);
void TryStoreHeldItemsInPyramidBag(void);
void ChooseItemsToTossFromPyramidBag(void);
void CloseBattlePyramidBag(u8 taskId);
void DisplayItemMessageInBattlePyramid(u8 taskId, const u8 *str, void (*callback)(u8 taskId));

#endif // GUARD_BATTLE_PYRAMID_BAG_H
