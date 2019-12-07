#ifndef GUARD_item_menu_H
#define GUARD_item_menu_H

#include "item.h"
#include "menu_helpers.h"

#define RETURN_LOCATION_FIELD 0
#define RETURN_LOCATION_BATTLE 1
#define RETURN_LOCATION_POKEMON_LIST 2
#define RETURN_LOCATION_SHOP 3
#define RETURN_LOCATION_FIELD_2 4
#define RETURN_LOCATION_FIELD_3 5
#define RETURN_LOCATION_PC 6
#define RETURN_LOCATION_FIELD_4 7
#define RETURN_LOCATION_FIELD_5 8
#define RETURN_LOCATION_FIELD_6 9
#define RETURN_LOCATION_BATTLE_2 10
#define RETURN_LOCATION_PC_2 11
#define RETURN_LOCATION_UNCHANGED 12

// Exported type declarations
struct BagStruct
{
    void (*bagCallback)(void);
    u8 location;
    u8 pocket;
    u16 unk6;
    u16 cursorPosition[POCKETS_COUNT];
    u16 scrollPosition[POCKETS_COUNT];
};

extern struct BagStruct gBagPositionStruct;

struct BagMenuStruct
{
    void (*mainCallback2)(void);
    u8 tilemapBuffer[0x800];
    u8 spriteId[12];
    u8 windowPointers[7];
    u8 unk817;
    u8 unk818;
    u8 unk819;
    u8 unk81A;
    u8 unk81B:4;
    u8 unk81B_1:2;
    u8 unk81B_3:1;
    u8 hideCloseBagText:1;
    u8 filler3[2];
    u8 unk81E;
    u8 unk81F;
    const u8* unk820;
    u8 unk824;
    u8 unk825;
    u8 filler[2];
    u8 unk828;
    u8 numItemStacks[POCKETS_COUNT];
    u8 numShownItems[6];
    s16 unk834;
    u8 filler4[0xE];
    u8 pocketNameBuffer[32][32];
    u8 filler2[4];
};

extern struct BagMenuStruct *gBagMenu;

// Exported RAM declarations

extern u16 gSpecialVar_ItemId;

// Exported ROM declarations
void sub_81AAC14(void);
void FavorLadyOpenBagMenu(void);
void QuizLadyOpenBagMenu(void);
void ApprenticeOpenBagMenu(void);
void sub_81AABB0(void);
void SetInitialScrollAndCursorPositions(u8 pocketId);
void bag_menu_mail_related(void);
void CB2_BagMenuFromStartMenu(void);
u8 GetItemListPosition(u8 pocketId);
bool8 UseRegisteredKeyItemOnField(void);
void CB2_GoToSellMenu(void);
void GoToBagMenu(u8 bagMenuType, u8 pocketId, void ( *postExitMenuMainCallback2)());
void DoWallyTutorialBagMenu(void);
void ResetBagScrollPositions(void);
void ChooseBerrySetCallback(void (*callback)(void));
void CB2_ChooseBerry(void);
void unknown_ItemMenu_Confirm(u8 taskId);
void BagMenu_YesNo(u8, u8, const struct YesNoFuncTable*);
void sub_81AB9A8(u8 pocketId);


#endif //GUARD_item_menu_H
