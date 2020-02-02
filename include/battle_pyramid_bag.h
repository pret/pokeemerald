#ifndef GUARD_BATTLE_PYRAMID_BAG_H
#define GUARD_BATTLE_PYRAMID_BAG_H

#include "list_menu.h"

struct PyramidBagResources
{
    void (*callback2)(void);
    u8 tilemapBuffer[0x800];
    u8 itemsSpriteIds[PYRAMID_BAG_ITEMS_COUNT + 1];
    u8 windowIds[5];
    u8 unk814;
    u8 unk815;
    u8 scrollIndicatorsTaskId;
    const u8 *menuActionIds;
    u8 filler81C[0x820 - 0x81C];
    u8 menuActionsCount;
    u8 listMenuCount;
    u8 listMenuMaxShown;
    struct ListMenuItem bagListItems[PYRAMID_BAG_ITEMS_COUNT + 1];
    u8 itemStrings[PYRAMID_BAG_ITEMS_COUNT + 1][ITEM_NAME_LENGTH + 10];
    s16 state;
    u8 filler986[0x98C - 0x986];
};

struct PyramidBagCursorData
{
    void (*callback)(void);
    u8 unk4;
    u16 cursorPosition;
    u16 scrollPosition;
};

extern struct PyramidBagResources *gPyramidBagResources;
extern struct PyramidBagCursorData gPyramidBagCursorData;

void InitBattlePyramidBagCursorPosition(void);
void CB2_PyramidBagMenuFromStartMenu(void);
void CB2_ReturnToPyramidBagMenu(void);
void sub_81C5924(void);
void sub_81C59BC(void);
void sub_81C4EFC(void);
void GoToBattlePyramidBagMenu(u8 a0, void (*callback)(void));
void Task_CloseBattlePyramidBagMessage(u8 taskId);
void TryStoreHeldItemsInPyramidBag(void);
void ChooseItemsToTossFromPyramidBag(void);
void CloseBattlePyramidBagAndSetCallback(u8 taskId);
void DisplayItemMessageInBattlePyramid(u8 taskId, const u8 *str, void (*callback)(u8 taskId));

#endif // GUARD_BATTLE_PYRAMID_BAG_H
