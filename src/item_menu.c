#include "global.h"
#include "item_menu.h"
#include "battle.h"
#include "battle_controllers.h"
#include "battle_pyramid.h"
#include "frontier_util.h"
#include "battle_pyramid_bag.h"
#include "berry_tag_screen.h"
#include "bg.h"
#include "constants/items.h"
#include "constants/songs.h"
#include "data.h"
#include "decompress.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "field_player_avatar.h"
#include "field_specials.h"
#include "graphics.h"
#include "gpu_regs.h"
#include "international_string_util.h"
#include "item.h"
#include "item_menu_icons.h"
#include "item_use.h"
#include "lilycove_lady.h"
#include "list_menu.h"
#include "link.h"
#include "mail.h"
#include "main.h"
#include "malloc.h"
#include "map_name_popup.h"
#include "menu.h"
#include "money.h"
#include "overworld.h"
#include "palette.h"
#include "party_menu.h"
#include "player_pc.h"
#include "pokemon.h"
#include "pokemon_summary_screen.h"
#include "scanline_effect.h"
#include "script.h"
#include "shop.h"
#include "sound.h"
#include "sprite.h"
#include "strings.h"
#include "string_util.h"
#include "task.h"
#include "text_window.h"
#include "menu_helpers.h"
#include "window.h"
#include "apprentice.h"
#include "battle_pike.h"
#include "constants/rgb.h"

enum
{
    SWITCH_POCKET_NONE,
    SWITCH_POCKET_LEFT,
    SWITCH_POCKET_RIGHT
};

void GoToBagMenu(u8 bagMenuType, u8 pocketId, void (*postExitMenuMainCallback2)());
void CB2_Bag(void);
bool8 SetupBagMenu(void);
void BagMenu_InitBGs(void);
bool8 LoadBagMenu_Graphics(void);
void SetupBagMenu_Textboxes(void);
void AllocateBagItemListBuffers(void);
void LoadBagItemListBuffers(u8);
void BagMenu_PrintPocketNames(const u8*, const u8*);
void BagMenu_CopyPocketNameToWindow(u32);
static void DrawPocketIndicatorSquare(u8 x, bool8 isCurrentPocket);
void CreatePocketScrollArrowPair(void);
void CreatePocketSwitchArrowPair(void);
void BagMenu_PrepareTMHMMoveWindow(void);
bool8 IsWallysBag(void);
void Task_WallyTutorialBagMenu(u8);
void Task_BagMenu_HandleInput(u8);
void GetItemName(s8*, u16);
u16 ItemIdToBattleMoveId(u16);
u16 BagGetItemIdByPocketPosition(u8, u16);
void BagMenu_PrintDescription(int);
void BagMenu_PrintCursor(u8, u8);
void BagMenu_Print(u8, u8, const u8*, u8, u8, u8, u8, u8, u8);
bool8 ItemId_GetImportance(u16);
u16 BagGetQuantityByPocketPosition(u8, u16);
void BagDestroyPocketSwitchArrowPair(void);
void TaskCloseBagMenu_2(u8);
u8 AddItemMessageWindow(u8);
void BagMenu_RemoveBagItemMessageindow(u8);
void set_callback3_to_bag(u8);
void PrintItemDepositAmount(u8, s16);
static u8 BagMenu_AddWindow(u8);
static u8 GetSwitchBagPocketDirection(void);
static void SwitchBagPocket(u8, s16, u16);
static bool8 CanSwapItems(void);
static void BagMenu_SwapItems(u8 taskId);
static void sub_81AC10C(u8);
static void Task_HandleSwappingItemsInput(u8);
void sub_81AC498(u8);
void sub_81AC590(u8);
void PrintTMHMMoveData(u16);
void sub_81ACAF8(u8);
void sub_81ACB54(u8, u8, u8);
void Task_HandleInBattleItemMenuInput(u8);
void Task_HandleOutOfBattleItemMenuInput(u8);
bool8 sub_81ACDFC(s8);
void BagMenu_RemoveWindow(u8);
void BagMenu_PrintThereIsNoPokemon(u8);
void Task_ChooseHowManyToToss(u8);
void BagMenu_TossItems(u8);
void BagMenu_YesNo(u8, u8, const struct YesNoFuncTable*);
void Task_ActuallyToss(u8);
void ItemMenu_Cancel(u8);
void sub_81AD350(u8);
static void BagMenu_PrintItemCantBeHeld(u8);
static void DisplayCurrentMoneyWindow(void);
static void DisplaySellItemPriceAndConfirm(u8);
void sub_81AD730(u8);
void sub_81AD6E4(u8);
static void RemoveMoneyWindow(void);
static void Task_SellHowManyDialogueHandleInput(u8);
static void BagMenu_Sell_UpdateItemListAndMoney(u8);
static void BagMenu_Sell_WaitForABPress(u8);
static void BagMenu_TryDepositItem(u8);
static void Task_ChooseHowManyToDeposit(u8 taskId);
static void BagMenu_Deposit_WaitForABPress(u8);
void CB2_ApprenticeExitBagMenu(void);
void CB2_FavorLadyExitBagMenu(void);
void CB2_QuizLadyExitBagMenu(void);
void All_CalculateNItemsAndMaxShowed(void);
static void SetPocketListPositions(void);
void UpdatePocketScrollPositions(void);
u8 CreateBagInputHandlerTask(u8);
void sub_81AC23C(u8);
void BagMenu_MoveCursorCallback(s32 a, bool8 b, struct ListMenu*);
void BagMenu_ItemPrintCallback(u8 windowId, s32 itemIndex, u8 a);
void ItemMenu_UseOutOfBattle(u8 taskId);
void ItemMenu_Toss(u8 taskId);
void ItemMenu_Register(u8 taskId);
void ItemMenu_Give(u8 taskId);
void ItemMenu_Cancel(u8 taskId);
void ItemMenu_UseInBattle(u8 taskId);
void ItemMenu_CheckTag(u8 taskId);
void Task_FadeAndCloseBagMenu(u8 taskId);
void unknown_ItemMenu_Show(u8 taskId);
void unknown_ItemMenu_Give2(u8 taskId);
void unknown_ItemMenu_Confirm2(u8 taskId);
void Task_ItemContext_FieldOrBattle(u8 taskId);
void Task_ItemContext_FieldGive(u8 taskId);
void Task_ItemContext_Sell(u8 taskId);
void Task_ItemContext_Deposit(u8 taskId);
void Task_ItemContext_ItemPC_2(u8 taskId);
void BagMenu_ConfirmToss(u8 taskId);
void BagMenu_CancelToss(u8 taskId);
void BagMenu_ConfirmSell(u8 taskId);
void BagMenu_CancelSell(u8 taskId);

// .rodata

static const struct BgTemplate sBgTemplates_ItemMenu[] =
{
    {
        .bg = 0,
        .charBaseIndex = 0,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0,
    },
    {
        .bg = 1,
        .charBaseIndex = 0,
        .mapBaseIndex = 30,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0,
    },
    {
        .bg = 2,
        .charBaseIndex = 3,
        .mapBaseIndex = 29,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 0,
    },
};

static const struct ListMenuTemplate sItemListMenu =
{
    .items = NULL,
    .moveCursorFunc = BagMenu_MoveCursorCallback,
    .itemPrintFunc = BagMenu_ItemPrintCallback,
    .totalItems = 0,
    .maxShowed = 0,
    .windowId = 0,
    .header_X = 0,
    .item_X = 8,
    .cursor_X = 0,
    .upText_Y = 1,
    .cursorPal = 1,
    .fillValue = 0,
    .cursorShadowPal = 3,
    .lettersSpacing = 0,
    .itemVerticalPadding = 0,
    .scrollMultiple = 0,
    .fontId = 7,
    .cursorKind = 0
};

static const struct MenuAction sItemMenuActions[] = {
    [ITEMMENUACTION_USE] =          {gMenuText_Use, ItemMenu_UseOutOfBattle},
    [ITEMMENUACTION_TOSS] =         {gMenuText_Toss, ItemMenu_Toss},
    [ITEMMENUACTION_REGISTER] =     {gMenuText_Register, ItemMenu_Register},
    [ITEMMENUACTION_GIVE] =         {gMenuText_Give, ItemMenu_Give},
    [ITEMMENUACTION_CANCEL] =       {gText_Cancel2, ItemMenu_Cancel},
    [ITEMMENUACTION_BATTLE_USE] =   {gMenuText_Use, ItemMenu_UseInBattle},
    [ITEMMENUACTION_CHECK] =        {gMenuText_Check, ItemMenu_UseOutOfBattle},
    [ITEMMENUACTION_WALK] =         {gMenuText_Walk, ItemMenu_UseOutOfBattle},
    [ITEMMENUACTION_DESELECT] =     {gMenuText_Deselect, ItemMenu_Register},
    [ITEMMENUACTION_CHECK_TAG] =    {gMenuText_CheckTag, ItemMenu_CheckTag},
    [ITEMMENUACTION_CONFIRM] =      {gMenuText_Confirm, Task_FadeAndCloseBagMenu},
    [ITEMMENUACTION_SHOW] =         {gMenuText_Show, unknown_ItemMenu_Show},
    [ITEMMENUACTION_GIVE_2] =       {gMenuText_Give2, unknown_ItemMenu_Give2},
    [ITEMMENUACTION_CONFIRM_2] =    {gMenuText_Confirm, unknown_ItemMenu_Confirm2},
    [ITEMMENUACTION_DUMMY] =        {gText_EmptyString2, NULL}
};

// these are all 2D arrays with a width of 2 but are represented as 1D arrays
// ITEMMENUACTION_DUMMY is used to represent blank spaces
static const u8 sContextMenuItems_ItemsPocket[] = {
    ITEMMENUACTION_USE,         ITEMMENUACTION_GIVE,
    ITEMMENUACTION_TOSS,        ITEMMENUACTION_CANCEL
};

static const u8 sContextMenuItems_KeyItemsPocket[] = {
    ITEMMENUACTION_USE,         ITEMMENUACTION_REGISTER,
    ITEMMENUACTION_DUMMY,       ITEMMENUACTION_CANCEL
};

static const u8 sContextMenuItems_BallsPocket[] = {
    ITEMMENUACTION_GIVE,        ITEMMENUACTION_DUMMY,
    ITEMMENUACTION_TOSS,        ITEMMENUACTION_CANCEL
};

static const u8 sContextMenuItems_TmHmPocket[] = {
    ITEMMENUACTION_USE,         ITEMMENUACTION_GIVE,
    ITEMMENUACTION_DUMMY,       ITEMMENUACTION_CANCEL
};

static const u8 sContextMenuItems_BerriesPocket[] = {
    ITEMMENUACTION_CHECK_TAG,   ITEMMENUACTION_DUMMY,
    ITEMMENUACTION_USE,         ITEMMENUACTION_GIVE,
    ITEMMENUACTION_TOSS,        ITEMMENUACTION_CANCEL
};

static const u8 sContextMenuItems_BattleUse[] = {
    ITEMMENUACTION_BATTLE_USE,  ITEMMENUACTION_CANCEL
};

static const u8 sContextMenuItems_Give[] = {
    ITEMMENUACTION_GIVE,        ITEMMENUACTION_CANCEL
};

static const u8 sContextMenuItems_Cancel[] = {
    ITEMMENUACTION_CANCEL
};

static const u8 sContextMenuItems_BerryBlenderCrush[] = {
    ITEMMENUACTION_CONFIRM,     ITEMMENUACTION_CHECK_TAG,
    ITEMMENUACTION_DUMMY,       ITEMMENUACTION_CANCEL
};

static const u8 sContextMenuItems_Apprentice[] = {
    ITEMMENUACTION_SHOW,        ITEMMENUACTION_CANCEL
};

static const u8 sContextMenuItems_FavorLady[] = {
    ITEMMENUACTION_GIVE_2,      ITEMMENUACTION_CANCEL
};

static const u8 sContextMenuItems_QuizLady[] = {
    ITEMMENUACTION_CONFIRM_2,   ITEMMENUACTION_CANCEL
};

static const TaskFunc gUnknown_08614054[] = {
    [ITEMMENULOCATION_FIELD] =                  Task_ItemContext_FieldOrBattle,
    [ITEMMENULOCATION_BATTLE] =                 Task_ItemContext_FieldOrBattle,
    [ITEMMENULOCATION_PARTY] =                  Task_ItemContext_FieldGive,
    [ITEMMENULOCATION_SHOP] =                   Task_ItemContext_Sell,
    [ITEMMENULOCATION_BERRY_TREE] =             Task_FadeAndCloseBagMenu,
    [ITEMMENULOCATION_BERRY_BLENDER_CRUSH] =    Task_ItemContext_FieldOrBattle,
    [ITEMMENULOCATION_ITEMPC] =                 Task_ItemContext_Deposit,
    [ITEMMENULOCATION_FAVOR_LADY] =             Task_ItemContext_FieldOrBattle,
    [ITEMMENULOCATION_QUIZ_LADY] =              Task_ItemContext_FieldOrBattle,
    [ITEMMENULOCATION_APPRENTICE] =             Task_ItemContext_FieldOrBattle,
    [ITEMMENULOCATION_WALLY] =                  NULL,
    [ITEMMENULOCATION_PCBOX] =                  Task_ItemContext_ItemPC_2
};

static const struct YesNoFuncTable sYesNoTossFunctions = {BagMenu_ConfirmToss, BagMenu_CancelToss};

static const struct YesNoFuncTable sYesNoSellItemFunctions = {BagMenu_ConfirmSell, BagMenu_CancelSell};

static const struct ScrollArrowsTemplate sBagScrollArrowsTemplate = {
    .firstArrowType = SCROLL_ARROW_LEFT,
    .firstX = 28,
    .firstY = 16,
    .secondArrowType = SCROLL_ARROW_RIGHT,
    .secondX = 100,
    .secondY = 16,
    .fullyUpThreshold = -1,
    .fullyDownThreshold = -1,
    .tileTag = 111,
    .palTag = 111,
    .palNum = 0,
};

static const u8 sRegisteredSelect_Gfx[] = INCBIN_U8("graphics/interface/select_button.4bpp");

static const u8 sFontColorTable[][3] = {
// bgColor, textColor, shadowColor
    {0, 1, 3},
    {0, 1, 4},
    {0, 3, 6},
    {2, 1, 3},
    {0, 14, 10}
};

const struct WindowTemplate sDefaultBagWindows[] =
{
    { // Item names
        .bg = 0,
        .tilemapLeft = 14,
        .tilemapTop = 2,
        .width = 15,
        .height = 16,
        .paletteNum = 1,
        .baseBlock = 0x27,
    },
    { // Description
        .bg = 0,
        .tilemapLeft = 0,
        .tilemapTop = 13,
        .width = 14,
        .height = 6,
        .paletteNum = 1,
        .baseBlock = 0x117,
    },
    { // Pocket name
        .bg = 0,
        .tilemapLeft = 4,
        .tilemapTop = 1,
        .width = 8,
        .height = 2,
        .paletteNum = 1,
        .baseBlock = 0x1A1,
    },
    { // TM/HM info icons
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 13,
        .width = 5,
        .height = 6,
        .paletteNum = 12,
        .baseBlock = 0x16B,
    },
    {// TM/HM info
        .bg = 0,
        .tilemapLeft = 7,
        .tilemapTop = 13,
        .width = 4,
        .height = 6,
        .paletteNum = 12,
        .baseBlock = 0x189,
    },
    { // Field message box
        .bg = 1,
        .tilemapLeft = 2,
        .tilemapTop = 15,
        .width = 27,
        .height = 4,
        .paletteNum = 15,
        .baseBlock = 0x1B1,
    },
    DUMMY_WIN_TEMPLATE,
};

const struct WindowTemplate sContextMenuWindowTemplates[] =
{
    {
        .bg = 1,
        .tilemapLeft = 22,
        .tilemapTop = 17,
        .width = 7,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 0x21D,
    },
    {
        .bg = 1,
        .tilemapLeft = 22,
        .tilemapTop = 15,
        .width = 7,
        .height = 4,
        .paletteNum = 15,
        .baseBlock = 0x21D,
    },
    {
        .bg = 1,
        .tilemapLeft = 15,
        .tilemapTop = 15,
        .width = 14,
        .height = 4,
        .paletteNum = 15,
        .baseBlock = 0x21D,
    },
    {
        .bg = 1,
        .tilemapLeft = 15,
        .tilemapTop = 13,
        .width = 14,
        .height = 6,
        .paletteNum = 15,
        .baseBlock = 0x21D,
    },
    {
        .bg = 1,
        .tilemapLeft = 2,
        .tilemapTop = 15,
        .width = 27,
        .height = 4,
        .paletteNum = 15,
        .baseBlock = 0x1B1,
    },
    {
        .bg = 1,
        .tilemapLeft = 24,
        .tilemapTop = 15,
        .width = 5,
        .height = 4,
        .paletteNum = 15,
        .baseBlock = 0x21D,
    },
    {
        .bg = 1,
        .tilemapLeft = 21,
        .tilemapTop = 9,
        .width = 5,
        .height = 4,
        .paletteNum = 15,
        .baseBlock = 0x21D,
    },
    {
        .bg = 1,
        .tilemapLeft = 24,
        .tilemapTop = 17,
        .width = 5,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 0x21D,
    },
    {
        .bg = 1,
        .tilemapLeft = 18,
        .tilemapTop = 11,
        .width = 10,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 0x245,
    },
    {
        .bg = 1,
        .tilemapLeft = 1,
        .tilemapTop = 1,
        .width = 10,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 0x231,
    },
};

// .text

struct ListBuffer1 {
    struct ListMenuItem subBuffers[MAX_POCKET_ITEMS];
};

struct ListBuffer2 {
    s8 name[MAX_POCKET_ITEMS][24];
};

struct TempWallyStruct {
    struct ItemSlot bagPocket_Items[BAG_ITEMS_COUNT];
    struct ItemSlot bagPocket_PokeBalls[BAG_POKEBALLS_COUNT];
    u16 cursorPosition[POCKETS_COUNT];
    u16 scrollPosition[POCKETS_COUNT];
    u8 filler[2];
    u16 pocket;
};

EWRAM_DATA struct BagMenuStruct *gBagMenu = 0;
EWRAM_DATA struct BagStruct gBagPositionStruct = {0};
static EWRAM_DATA struct ListBuffer1 *sListBuffer1 = 0;
static EWRAM_DATA struct ListBuffer2 *sListBuffer2 = 0;
EWRAM_DATA u16 gSpecialVar_ItemId = 0;
static EWRAM_DATA struct TempWallyStruct *sTempWallyBag = 0;

extern u8 *const gPocketNamesStringsTable[];
extern u8* gReturnToXStringsTable[];
extern const u8 EventScript_SelectWithoutRegisteredItem[];
extern const u16 gUnknown_0860F074[];

void ResetBagScrollPositions(void)
{
    gBagPositionStruct.pocket = ITEMS_POCKET;
    memset(gBagPositionStruct.cursorPosition, 0, 10);
    memset(gBagPositionStruct.scrollPosition, 0, 10);
}

void CB2_BagMenuFromStartMenu(void)
{
    GoToBagMenu(ITEMMENULOCATION_FIELD, POCKETS_COUNT, CB2_ReturnToFieldWithOpenMenu);
}

void CB2_BagMenuFromBattle(void)
{
    if (!InBattlePyramid())
        GoToBagMenu(ITEMMENULOCATION_BATTLE, POCKETS_COUNT, CB2_SetUpReshowBattleScreenAfterMenu2);
    else
        GoToBattlePyramidBagMenu(1, CB2_SetUpReshowBattleScreenAfterMenu2);
}

// Choosing berry to plant
void CB2_ChooseBerry(void)
{
    GoToBagMenu(ITEMMENULOCATION_BERRY_TREE, BERRIES_POCKET, CB2_ReturnToFieldContinueScript);
}

// Choosing berry for Berry Blender or Berry Crush
void ChooseBerryForMachine(void (*exitCallback)(void))
{
    GoToBagMenu(ITEMMENULOCATION_BERRY_BLENDER_CRUSH, BERRIES_POCKET, exitCallback);
}

void CB2_GoToSellMenu(void)
{
    GoToBagMenu(ITEMMENULOCATION_SHOP, POCKETS_COUNT, CB2_ExitSellMenu);
}

void CB2_GoToItemDepositMenu(void)
{
    GoToBagMenu(ITEMMENULOCATION_ITEMPC, POCKETS_COUNT, sub_816B31C);
}

void ApprenticeOpenBagMenu(void)
{
    GoToBagMenu(ITEMMENULOCATION_APPRENTICE, POCKETS_COUNT, CB2_ApprenticeExitBagMenu);
    gSpecialVar_0x8005 = ITEM_NONE;
    gSpecialVar_Result = FALSE;
}

void FavorLadyOpenBagMenu(void)
{
    GoToBagMenu(ITEMMENULOCATION_FAVOR_LADY, POCKETS_COUNT, CB2_FavorLadyExitBagMenu);
    gSpecialVar_Result = FALSE;
}

void QuizLadyOpenBagMenu(void)
{
    GoToBagMenu(ITEMMENULOCATION_QUIZ_LADY, POCKETS_COUNT, CB2_QuizLadyExitBagMenu);
    gSpecialVar_Result = FALSE;
}

void GoToBagMenu(u8 location, u8 pocket, void ( *postExitMenuMainCallback2)())
{
    gBagMenu = AllocZeroed(sizeof(struct BagMenuStruct));
    if (gBagMenu == NULL)
    {
        SetMainCallback2(postExitMenuMainCallback2);
    }
    else
    {
        if (location != ITEMMENULOCATION_LAST)
            gBagPositionStruct.location = location;
        if (postExitMenuMainCallback2)
            gBagPositionStruct.bagCallback = postExitMenuMainCallback2;
        if (pocket < POCKETS_COUNT)
            gBagPositionStruct.pocket = pocket;
        if (gBagPositionStruct.location == ITEMMENULOCATION_BERRY_TREE ||
            gBagPositionStruct.location == ITEMMENULOCATION_BERRY_BLENDER_CRUSH)
            gBagMenu->pocketSwitchDisabled = TRUE;
        gBagMenu->exitCallback = NULL;
        gBagMenu->itemOriginalLocation = 0xFF;
        gBagMenu->pocketScrollArrowsTask = 0xFF;
        gBagMenu->pocketSwitchArrowsTask = 0xFF;
        memset(gBagMenu->spriteId, 0xFF, sizeof(gBagMenu->spriteId));
        memset(gBagMenu->windowPointers, 0xFF, 10);
        SetMainCallback2(CB2_Bag);
    }
}

void CB2_BagMenuRun(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    DoScheduledBgTilemapCopiesToVram();
    UpdatePaletteFade();
}

void VBlankCB_BagMenuRun(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

#define tItemCount data[8]

void CB2_Bag(void)
{
    while(MenuHelpers_CallLinkSomething() != TRUE && SetupBagMenu() != TRUE && MenuHelpers_LinkSomething() != TRUE) {};
}

bool8 SetupBagMenu(void)
{
    u8 taskId;

    switch (gMain.state)
    {
    case 0:
        SetVBlankHBlankCallbacksToNull();
        ClearScheduledBgCopiesToVram();
        gMain.state++;
        break;
    case 1:
        ScanlineEffect_Stop();
        gMain.state++;
        break;
    case 2:
        FreeAllSpritePalettes();
        gMain.state++;
        break;
    case 3:
        ResetPaletteFade();
        gPaletteFade.bufferTransferDisabled = TRUE;
        gMain.state++;
        break;
    case 4:
        ResetSpriteData();
        gMain.state++;
        break;
    case 5:
        gMain.state++;
        break;
    case 6:
        if (!MenuHelpers_LinkSomething())
            ResetTasks();
        gMain.state++;
        break;
    case 7:
        BagMenu_InitBGs();
        gBagMenu->graphicsLoadState = 0;
        gMain.state++;
        break;
    case 8:
        if (!LoadBagMenu_Graphics())
            break;
        gMain.state++;
        break;
    case 9:
        SetupBagMenu_Textboxes();
        gMain.state++;
        break;
    case 10:
        All_CalculateNItemsAndMaxShowed();
        SetPocketListPositions();
        UpdatePocketScrollPositions();
        gMain.state++;
        break;
    case 11:
        AllocateBagItemListBuffers();
        gMain.state++;
        break;
    case 12:
        LoadBagItemListBuffers(gBagPositionStruct.pocket);
        gMain.state++;
        break;
    case 13:
        BagMenu_PrintPocketNames(gPocketNamesStringsTable[gBagPositionStruct.pocket], 0);
        BagMenu_CopyPocketNameToWindow(0);
        DrawPocketIndicatorSquare(gBagPositionStruct.pocket, TRUE);
        gMain.state++;
        break;
    case 14:
        taskId = CreateBagInputHandlerTask(gBagPositionStruct.location);
        gTasks[taskId].data[0] = ListMenuInit(&gMultiuseListMenuTemplate, gBagPositionStruct.scrollPosition[gBagPositionStruct.pocket], gBagPositionStruct.cursorPosition[gBagPositionStruct.pocket]);
        gTasks[taskId].data[3] = 0;
        gTasks[taskId].tItemCount = 0;
        gMain.state++;
        break;
    case 15:
        AddBagVisualSprite(gBagPositionStruct.pocket);
        gMain.state++;
        break;
    case 16:
        sub_80D4FAC();
        gMain.state++;
        break;
    case 17:
        CreatePocketScrollArrowPair();
        CreatePocketSwitchArrowPair();
        gMain.state++;
        break;
    case 18:
        BagMenu_PrepareTMHMMoveWindow();
        gMain.state++;
        break;
    case 19:
        BlendPalettes(0xFFFFFFFF, 16, 0);
        gMain.state++;
        break;
    case 20:
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 16, 0, RGB_BLACK);
        gPaletteFade.bufferTransferDisabled = FALSE;
        gMain.state++;
        break;
    default:
        SetVBlankCallback(VBlankCB_BagMenuRun);
        SetMainCallback2(CB2_BagMenuRun);
        return TRUE;
    }
    return FALSE;
}

void BagMenu_InitBGs(void)
{
    ResetVramOamAndBgCntRegs();
    memset(gBagMenu->tilemapBuffer, 0, 0x800);
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, sBgTemplates_ItemMenu, ARRAY_COUNT(sBgTemplates_ItemMenu));
    SetBgTilemapBuffer(2, gBagMenu->tilemapBuffer);
    ResetAllBgsCoordinates();
    ScheduleBgCopyTilemapToVram(2);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
    ShowBg(0);
    ShowBg(1);
    ShowBg(2);
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
}

bool8 LoadBagMenu_Graphics(void)
{
    switch (gBagMenu->graphicsLoadState)
    {
        case 0:
            ResetTempTileDataBuffers();
            DecompressAndCopyTileDataToVram(2, gBagScreen_Gfx, 0, 0, 0);
            gBagMenu->graphicsLoadState++;
            break;
        case 1:
            if (FreeTempTileDataBuffersIfPossible() != TRUE)
            {
                LZDecompressWram(gBagScreen_GfxTileMap, gBagMenu->tilemapBuffer);
                gBagMenu->graphicsLoadState++;
            }
            break;
        case 2:
            if (!IsWallysBag() && gSaveBlock2Ptr->playerGender != MALE)
                LoadCompressedPalette(gBagScreenFemale_Pal, 0, 0x40);
            else
                LoadCompressedPalette(gBagScreenMale_Pal, 0, 0x40);
            gBagMenu->graphicsLoadState++;
            break;
        case 3:
            if (IsWallysBag() == TRUE || gSaveBlock2Ptr->playerGender == MALE)
                LoadCompressedSpriteSheet(&gBagMaleSpriteSheet);
            else
                LoadCompressedSpriteSheet(&gBagFemaleSpriteSheet);
            gBagMenu->graphicsLoadState++;
            break;
        case 4:
            LoadCompressedSpritePalette(&gBagPaletteTable);
            gBagMenu->graphicsLoadState++;
            break;
        default:
            LoadListMenuArrowsGfx();
            gBagMenu->graphicsLoadState = 0;
            return TRUE;
    }
    return FALSE;
}

u8 CreateBagInputHandlerTask(u8 location)
{
    u8 taskId;
    if (location == ITEMMENULOCATION_WALLY)
        taskId = CreateTask(Task_WallyTutorialBagMenu, 0);
    else
        taskId = CreateTask(Task_BagMenu_HandleInput, 0);
    return taskId;
}

void AllocateBagItemListBuffers(void)
{
    sListBuffer1 = Alloc(sizeof(struct ListBuffer1));
    sListBuffer2 = Alloc(sizeof(struct ListBuffer2));
}

void LoadBagItemListBuffers(u8 pocketId)
{
    u16 i;
    struct BagPocket *pocket = &gBagPockets[pocketId];
    struct ListMenuItem *subBuffer;

    if (!gBagMenu->hideCloseBagText)
    {
        for (i = 0; i < gBagMenu->numItemStacks[pocketId] - 1; i++)
        {
            GetItemName(sListBuffer2->name[i], pocket->itemSlots[i].itemId);
            subBuffer = sListBuffer1->subBuffers;
            subBuffer[i].name = sListBuffer2->name[i];
            subBuffer[i].id = i;
        }
        StringCopy(sListBuffer2->name[i], gText_CloseBag);
        subBuffer = sListBuffer1->subBuffers;
        subBuffer[i].name = sListBuffer2->name[i];
        subBuffer[i].id = LIST_CANCEL;
    }
    else
    {
        for (i = 0; i < gBagMenu->numItemStacks[pocketId]; i++)
        {
            GetItemName(sListBuffer2->name[i], pocket->itemSlots[i].itemId);
            subBuffer = sListBuffer1->subBuffers;
            subBuffer[i].name = sListBuffer2->name[i];
            subBuffer[i].id = i;
        }
    }
    gMultiuseListMenuTemplate = sItemListMenu;
    gMultiuseListMenuTemplate.totalItems = gBagMenu->numItemStacks[pocketId];
    gMultiuseListMenuTemplate.items = sListBuffer1->subBuffers;
    gMultiuseListMenuTemplate.maxShowed = gBagMenu->numShownItems[pocketId];
}

void GetItemName(s8 *dest, u16 itemId)
{
    switch (gBagPositionStruct.pocket)
    {
        case TMHM_POCKET:
            StringCopy(gStringVar2, gMoveNames[ItemIdToBattleMoveId(itemId)]);
            if (itemId >= ITEM_HM01)
            {
                ConvertIntToDecimalStringN(gStringVar1, itemId - ITEM_HM01 + 1, STR_CONV_MODE_LEADING_ZEROS, 1);
                StringExpandPlaceholders(dest, gText_ClearTo11Var1Clear5Var2);
            }
            else
            {
                ConvertIntToDecimalStringN(gStringVar1, itemId - ITEM_TM01 + 1, STR_CONV_MODE_LEADING_ZEROS, 2);
                StringExpandPlaceholders(dest, gText_NumberVar1Clear7Var2);
            }
            break;
        case BERRIES_POCKET:
            ConvertIntToDecimalStringN(gStringVar1, itemId - FIRST_BERRY_INDEX + 1, STR_CONV_MODE_LEADING_ZEROS, 2);
            CopyItemName(itemId, gStringVar2);
            StringExpandPlaceholders(dest, gText_NumberVar1Clear7Var2);
            break;
        default:
            CopyItemName(itemId, dest);
            break;
    }
}

void BagMenu_MoveCursorCallback(s32 itemIndex, bool8 onInit, struct ListMenu *list)
{
    if (onInit != TRUE)
    {
        PlaySE(SE_SELECT);
        ShakeBagSprite();
    }
    if (gBagMenu->itemOriginalLocation == 0xFF)
    {
        RemoveBagItemIconSprite(gBagMenu->itemIconSlot ^ 1);
        if (itemIndex != LIST_CANCEL)
           AddBagItemIconSprite(BagGetItemIdByPocketPosition(gBagPositionStruct.pocket + 1, itemIndex), gBagMenu->itemIconSlot);
        else
           AddBagItemIconSprite(-1, gBagMenu->itemIconSlot);
        gBagMenu->itemIconSlot ^= 1;
        if (!gBagMenu->inhibitItemDescriptionPrint)
            BagMenu_PrintDescription(itemIndex);
    }
}

void BagMenu_ItemPrintCallback(u8 windowId, s32 itemIndex, u8 y)
{
    u16 itemId;
    u16 itemQuantity;
    int offset;

    if (itemIndex != LIST_CANCEL)
    {
        if (gBagMenu->itemOriginalLocation != 0xFF)
        {
            if (gBagMenu->itemOriginalLocation == (u8)itemIndex)
                BagMenu_PrintCursor(y, 2);
            else
                BagMenu_PrintCursor(y, 0xFF);
        }

        itemId = BagGetItemIdByPocketPosition(gBagPositionStruct.pocket + 1, itemIndex);
        itemQuantity = BagGetQuantityByPocketPosition(gBagPositionStruct.pocket + 1, itemIndex);

        if (itemId >= ITEM_HM01 && itemId <= ITEM_HM08)
            BlitBitmapToWindow(windowId, gBagMenuHMIcon_Gfx, 8, y - 1, 16, 16);

        if (gBagPositionStruct.pocket == BERRIES_POCKET)
        {
            ConvertIntToDecimalStringN(gStringVar1, itemQuantity, STR_CONV_MODE_RIGHT_ALIGN, BERRY_CAPACITY_DIGITS);
            StringExpandPlaceholders(gStringVar4, gText_xVar1);
            offset = GetStringRightAlignXOffset(7, gStringVar4, 119);
            BagMenu_Print(windowId, 7, gStringVar4, offset, y, 0, 0, -1, 0);
        }
        else if (gBagPositionStruct.pocket != KEYITEMS_POCKET && ItemId_GetImportance(itemId) == FALSE)
        {
            ConvertIntToDecimalStringN(gStringVar1, itemQuantity, STR_CONV_MODE_RIGHT_ALIGN, BAG_ITEM_CAPACITY_DIGITS);
            StringExpandPlaceholders(gStringVar4, gText_xVar1);
            offset = GetStringRightAlignXOffset(7, gStringVar4, 119);
            BagMenu_Print(windowId, 7, gStringVar4, offset, y, 0, 0, -1, 0);
        }
        else
        {
            if (gSaveBlock1Ptr->registeredItem && gSaveBlock1Ptr->registeredItem == itemId)
                BlitBitmapToWindow(windowId, sRegisteredSelect_Gfx, 96, y - 1, 24, 16);
        }
    }
}

void BagMenu_PrintDescription(int itemIndex)
{
    const u8 *str;
    if (itemIndex != LIST_CANCEL)
    {
        str = ItemId_GetDescription(BagGetItemIdByPocketPosition(gBagPositionStruct.pocket + 1, itemIndex));
    }
    else
    {
        StringCopy(gStringVar1, gReturnToXStringsTable[gBagPositionStruct.location]);
        StringExpandPlaceholders(gStringVar4, gText_ReturnToVar1);
        str = gStringVar4;
    }
    FillWindowPixelBuffer(1, PIXEL_FILL(0));
    BagMenu_Print(1, 1, str, 3, 1, 0, 0, 0, 0);
}

void BagMenu_PrintCursor_(u8 listTaskId, u8 colorIndex)
{
    BagMenu_PrintCursor(ListMenuGetYCoordForPrintingArrowCursor(listTaskId), colorIndex);
}

void BagMenu_PrintCursor(u8 y, u8 colorIndex)
{
    if (colorIndex == 0xFF)
        FillWindowPixelRect(0, PIXEL_FILL(0), 0, y, GetMenuCursorDimensionByFont(1, 0), GetMenuCursorDimensionByFont(1, 1));
    else
        BagMenu_Print(0, 1, gText_SelectorArrow2, 0, y, 0, 0, 0, colorIndex);

}

void CreatePocketScrollArrowPair(void)
{
    if (gBagMenu->pocketScrollArrowsTask == 0xFF)
        gBagMenu->pocketScrollArrowsTask = AddScrollIndicatorArrowPairParameterized(
            SCROLL_ARROW_UP,
            172,
            12,
            148,
            gBagMenu->numItemStacks[gBagPositionStruct.pocket] - gBagMenu->numShownItems[gBagPositionStruct.pocket],
            110,
            110,
            &gBagPositionStruct.scrollPosition[gBagPositionStruct.pocket]);
}

void BagDestroyPocketScrollArrowPair(void)
{
    if (gBagMenu->pocketScrollArrowsTask != 0xFF)
    {
        RemoveScrollIndicatorArrowPair(gBagMenu->pocketScrollArrowsTask);
        gBagMenu->pocketScrollArrowsTask = 0xFF;
    }
    BagDestroyPocketSwitchArrowPair();
}

void CreatePocketSwitchArrowPair(void)
{
    if (gBagMenu->pocketSwitchDisabled != TRUE && gBagMenu->pocketSwitchArrowsTask == 0xFF)
        gBagMenu->pocketSwitchArrowsTask = AddScrollIndicatorArrowPair(&sBagScrollArrowsTemplate, &gBagPositionStruct.unk6);
}

void BagDestroyPocketSwitchArrowPair(void)
{
    if (gBagMenu->pocketSwitchArrowsTask != 0xFF)
    {
        RemoveScrollIndicatorArrowPair(gBagMenu->pocketSwitchArrowsTask);
        gBagMenu->pocketSwitchArrowsTask = 0xFF;
    }
}

void FreeBagItemListBuffers(void)
{
    Free(sListBuffer2);
    Free(sListBuffer1);
    FreeAllWindowBuffers();
    Free(gBagMenu);
}

void Task_FadeAndCloseBagMenu(u8 taskId)
{
    BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
    gTasks[taskId].func = TaskCloseBagMenu_2;
}

void TaskCloseBagMenu_2(u8 taskId)
{
    s16* data = gTasks[taskId].data;
    if (!gPaletteFade.active)
    {
        DestroyListMenuTask(data[0], &gBagPositionStruct.scrollPosition[gBagPositionStruct.pocket], &gBagPositionStruct.cursorPosition[gBagPositionStruct.pocket]);
        if (gBagMenu->exitCallback != NULL)
            SetMainCallback2(gBagMenu->exitCallback);
        else
            SetMainCallback2(gBagPositionStruct.bagCallback);
        BagDestroyPocketScrollArrowPair();
        ResetSpriteData();
        FreeAllSpritePalettes();
        FreeBagItemListBuffers();
        DestroyTask(taskId);
    }
}

void UpdatePocketItemList(u8 pocketId)
{
    u16 i;
    struct BagPocket *pocket = &gBagPockets[pocketId];
    switch (pocketId)
    {
        case TMHM_POCKET:
        case BERRIES_POCKET:
            SortBerriesOrTMHMs(pocket);
            break;
        default:
            CompactItemsInBagPocket(pocket);
            break;
    }

    gBagMenu->numItemStacks[pocketId] = 0;

    for (i = 0; i < pocket->capacity && pocket->itemSlots[i].itemId; i++)
        gBagMenu->numItemStacks[pocketId]++;

    if (!gBagMenu->hideCloseBagText)
        gBagMenu->numItemStacks[pocketId]++;

    if (gBagMenu->numItemStacks[pocketId] > 8)
        gBagMenu->numShownItems[pocketId] = 8;
    else
        gBagMenu->numShownItems[pocketId] = gBagMenu->numItemStacks[pocketId];
}

void All_CalculateNItemsAndMaxShowed(void)
{
    u8 i;
    for (i = 0; i < POCKETS_COUNT; i++)
        UpdatePocketItemList(i);
}

void SetInitialScrollAndCursorPositions(u8 pocketId)
{
    sub_812225C(&gBagPositionStruct.scrollPosition[pocketId], &gBagPositionStruct.cursorPosition[pocketId], gBagMenu->numShownItems[pocketId], gBagMenu->numItemStacks[pocketId]);
}

static void SetPocketListPositions(void)
{
    u8 i;
    for (i = 0; i < POCKETS_COUNT; i++)
        SetInitialScrollAndCursorPositions(i);
}

void UpdatePocketScrollPositions(void)
{
    u8 i;
    for (i = 0; i < POCKETS_COUNT; i++)
        sub_8122298(&gBagPositionStruct.scrollPosition[i], &gBagPositionStruct.cursorPosition[i], gBagMenu->numShownItems[i], gBagMenu->numItemStacks[i], 8);
}

u8 GetItemListPosition(u8 pocketId)
{
    return gBagPositionStruct.scrollPosition[pocketId] + gBagPositionStruct.cursorPosition[pocketId];
}

void DisplayItemMessage(u8 taskId, u8 fontId, const u8 *str, void (*callback)(u8 taskId))
{
    s16* data = gTasks[taskId].data;

    data[10] = AddItemMessageWindow(4);
    FillWindowPixelBuffer(data[10], PIXEL_FILL(1));
    DisplayMessageAndContinueTask(taskId, data[10], 10, 13, fontId, GetPlayerTextSpeedDelay(), str, callback);
    ScheduleBgCopyTilemapToVram(1);
}

void BagMenu_InitListsMenu(u8 taskId)
{
    s16* data = gTasks[taskId].data;
    u16* scrollPos = &gBagPositionStruct.scrollPosition[gBagPositionStruct.pocket];
    u16* cursorPos = &gBagPositionStruct.cursorPosition[gBagPositionStruct.pocket];
    BagMenu_RemoveBagItemMessageindow(4);
    DestroyListMenuTask(data[0], scrollPos, cursorPos);
    UpdatePocketItemList(gBagPositionStruct.pocket);
    SetInitialScrollAndCursorPositions(gBagPositionStruct.pocket);
    LoadBagItemListBuffers(gBagPositionStruct.pocket);
    data[0] = ListMenuInit(&gMultiuseListMenuTemplate, *scrollPos, *cursorPos);
    ScheduleBgCopyTilemapToVram(0);
    set_callback3_to_bag(taskId);
}

void sub_81ABC3C(u8 a)
{
    PrintItemDepositAmount(BagMenu_AddWindow(a), 1);
}

void PrintItemDepositAmount(u8 windowId, s16 numDeposited)
{
    u8 numDigits = (gBagPositionStruct.pocket == BERRIES_POCKET) ? BERRY_CAPACITY_DIGITS : BAG_ITEM_CAPACITY_DIGITS;
    ConvertIntToDecimalStringN(gStringVar1, numDeposited, STR_CONV_MODE_LEADING_ZEROS, numDigits);
    StringExpandPlaceholders(gStringVar4, gText_xVar1);
    AddTextPrinterParameterized(windowId, 1, gStringVar4, GetStringCenterAlignXOffset(1, gStringVar4, 0x28), 2, 0, 0);
}

void PrintItemSoldAmount(int windowId, int numSold, int moneyEarned)
{
    u8 numDigits = (gBagPositionStruct.pocket == BERRIES_POCKET) ? BERRY_CAPACITY_DIGITS : BAG_ITEM_CAPACITY_DIGITS;
    ConvertIntToDecimalStringN(gStringVar1, numSold, STR_CONV_MODE_LEADING_ZEROS, numDigits);
    StringExpandPlaceholders(gStringVar4, gText_xVar1);
    AddTextPrinterParameterized(windowId, 1, gStringVar4, 0, 1, -1, 0);
    PrintMoneyAmount(windowId, 38, 1, moneyEarned, 0);
}

void Task_BagMenu_HandleInput(u8 taskId)
{
    s16* data = gTasks[taskId].data;
    u16* scrollPos = &gBagPositionStruct.scrollPosition[gBagPositionStruct.pocket];
    u16* cursorPos = &gBagPositionStruct.cursorPosition[gBagPositionStruct.pocket];
    s32 listPosition;

    if (MenuHelpers_CallLinkSomething() != TRUE && !gPaletteFade.active)
    {
        switch (GetSwitchBagPocketDirection())
        {
            case SWITCH_POCKET_LEFT:
                SwitchBagPocket(taskId, MENU_CURSOR_DELTA_LEFT, 0);
                return;
            case SWITCH_POCKET_RIGHT:
                SwitchBagPocket(taskId, MENU_CURSOR_DELTA_RIGHT, 0);
                return;
            default:
                if (JOY_NEW(SELECT_BUTTON))
                {
                    if (CanSwapItems() == TRUE)
                    {
                        ListMenuGetScrollAndRow(data[0], scrollPos, cursorPos);
                        if ((*scrollPos + *cursorPos) != gBagMenu->numItemStacks[gBagPositionStruct.pocket] - 1)
                        {
                            PlaySE(SE_SELECT);
                            BagMenu_SwapItems(taskId);
                        }
                    }
                    return;
                }
                break;
        }

        listPosition = ListMenu_ProcessInput(data[0]);
        ListMenuGetScrollAndRow(data[0], scrollPos, cursorPos);
        switch (listPosition)
        {
            case LIST_NOTHING_CHOSEN:
                break;
            case LIST_CANCEL:
                if (gBagPositionStruct.location == ITEMMENULOCATION_BERRY_BLENDER_CRUSH)
                {
                    PlaySE(SE_FAILURE);
                    break;
                }
                PlaySE(SE_SELECT);
                gSpecialVar_ItemId = ITEM_NONE;
                gTasks[taskId].func = Task_FadeAndCloseBagMenu;
                break;
            default: // A_BUTTON
                PlaySE(SE_SELECT);
                BagDestroyPocketScrollArrowPair();
                BagMenu_PrintCursor_(data[0], 2);
                data[1] = listPosition;
                data[2] = BagGetQuantityByPocketPosition(gBagPositionStruct.pocket + 1, listPosition);
                gSpecialVar_ItemId = BagGetItemIdByPocketPosition(gBagPositionStruct.pocket + 1, listPosition);
                gUnknown_08614054[gBagPositionStruct.location](taskId);
                break;
        }
    }
}

void set_callback3_to_bag(u8 taskId)
{
    CreatePocketScrollArrowPair();
    CreatePocketSwitchArrowPair();
    ClearWindowTilemap(3);
    ClearWindowTilemap(4);
    PutWindowTilemap(1);
    ScheduleBgCopyTilemapToVram(0);
    gTasks[taskId].func = Task_BagMenu_HandleInput;
}

static u8 GetSwitchBagPocketDirection(void)
{
    u8 LRKeys;
    if (gBagMenu->pocketSwitchDisabled)
        return SWITCH_POCKET_NONE;
    LRKeys = GetLRKeysPressed();
    if ((JOY_NEW(DPAD_LEFT)) || LRKeys == MENU_L_PRESSED)
    {
        PlaySE(SE_SELECT);
        return SWITCH_POCKET_LEFT;
    }
    if ((JOY_NEW(DPAD_RIGHT)) || LRKeys == MENU_R_PRESSED)
    {
        PlaySE(SE_SELECT);
        return SWITCH_POCKET_RIGHT;
    }
    return SWITCH_POCKET_NONE;
}

static void ChangeBagPocketId(u8 *bagPocketId, s8 deltaBagPocketId)
{
    if (deltaBagPocketId == 1 && *bagPocketId == POCKETS_COUNT - 1)
        *bagPocketId = 0;
    else if (deltaBagPocketId == -1 && *bagPocketId == 0)
        *bagPocketId = POCKETS_COUNT - 1;
    else
        *bagPocketId += deltaBagPocketId;
}

static void SwitchBagPocket(u8 taskId, s16 deltaBagPocketId, u16 a3)
{
    s16* data = gTasks[taskId].data;
    u8 pocketId;

    data[13] = 0;
    data[12] = 0;
    data[11] = deltaBagPocketId;
    if (a3 == 0)
    {
        ClearWindowTilemap(0);
        ClearWindowTilemap(1);
        DestroyListMenuTask(data[0], &gBagPositionStruct.scrollPosition[gBagPositionStruct.pocket], &gBagPositionStruct.cursorPosition[gBagPositionStruct.pocket]);
        ScheduleBgCopyTilemapToVram(0);
        gSprites[gBagMenu->spriteId[2 + (gBagMenu->itemIconSlot ^ 1)]].invisible = TRUE;
        BagDestroyPocketScrollArrowPair();
    }
    pocketId = gBagPositionStruct.pocket;
    ChangeBagPocketId(&pocketId, deltaBagPocketId);
    if (deltaBagPocketId == MENU_CURSOR_DELTA_RIGHT)
    {
        BagMenu_PrintPocketNames(gPocketNamesStringsTable[gBagPositionStruct.pocket], gPocketNamesStringsTable[pocketId]);
        BagMenu_CopyPocketNameToWindow(0);
    }
    else
    {
        BagMenu_PrintPocketNames(gPocketNamesStringsTable[pocketId], gPocketNamesStringsTable[gBagPositionStruct.pocket]);
        BagMenu_CopyPocketNameToWindow(8);
    }
    DrawPocketIndicatorSquare(gBagPositionStruct.pocket, FALSE);
    DrawPocketIndicatorSquare(pocketId, TRUE);
    FillBgTilemapBufferRect_Palette0(2, 11, 14, 2, 15, 16);
    ScheduleBgCopyTilemapToVram(2);
    SetBagVisualPocketId(pocketId, 1);
    RemoveBagSprite(1);
    AddSwitchPocketRotatingBallSprite(deltaBagPocketId);
    SetTaskFuncWithFollowupFunc(taskId, sub_81AC10C, gTasks[taskId].func);
}

void sub_81AC10C(u8 taskId)
{
    s16* data = gTasks[taskId].data;

    if (!MenuHelpers_LinkSomething() && !IsWallysBag())
    {
        switch (GetSwitchBagPocketDirection())
        {
            case SWITCH_POCKET_LEFT:
                ChangeBagPocketId(&gBagPositionStruct.pocket, data[11]);
                SwitchTaskToFollowupFunc(taskId);
                SwitchBagPocket(taskId, MENU_CURSOR_DELTA_LEFT, 1);
                return;
            case SWITCH_POCKET_RIGHT:
                ChangeBagPocketId(&gBagPositionStruct.pocket, data[11]);
                SwitchTaskToFollowupFunc(taskId);
                SwitchBagPocket(taskId, MENU_CURSOR_DELTA_RIGHT, 1);
                return;
        }
    }
    switch (data[13])
    {
        case 0:
            sub_81AC23C(data[12]);
            if (!(++data[12] & 1))
            {
                if (data[11] == 1)
                    BagMenu_CopyPocketNameToWindow((u8)(data[12] >> 1));
                else
                    BagMenu_CopyPocketNameToWindow((u8)(8 - (data[12] >> 1)));
            }
            if (data[12] == 16)
                data[13]++;
            break;
        case 1:
            ChangeBagPocketId(&gBagPositionStruct.pocket, data[11]);
            LoadBagItemListBuffers(gBagPositionStruct.pocket);
            data[0] = ListMenuInit(&gMultiuseListMenuTemplate, gBagPositionStruct.scrollPosition[gBagPositionStruct.pocket], gBagPositionStruct.cursorPosition[gBagPositionStruct.pocket]);
            PutWindowTilemap(1);
            PutWindowTilemap(2);
            ScheduleBgCopyTilemapToVram(0);
            CreatePocketScrollArrowPair();
            CreatePocketSwitchArrowPair();
            SwitchTaskToFollowupFunc(taskId);
    }
}

void sub_81AC23C(u8 a)
{
    FillBgTilemapBufferRect_Palette0(2, 17, 14, a + 2, 15, 1);
    ScheduleBgCopyTilemapToVram(2);
}

static void DrawPocketIndicatorSquare(u8 x, bool8 isCurrentPocket)
{
    if (!isCurrentPocket)
        FillBgTilemapBufferRect_Palette0(2, 0x1017, x + 5, 3, 1, 1);
    else
        FillBgTilemapBufferRect_Palette0(2, 0x102B, x + 5, 3, 1, 1);
    ScheduleBgCopyTilemapToVram(2);
}

static bool8 CanSwapItems(void)
{
    if (gBagPositionStruct.location <= ITEMMENULOCATION_BATTLE)
    {
        u8 temp = gBagPositionStruct.pocket - 2;
        if (temp > 1)
            return TRUE;
    }
    return FALSE;
}

void BagMenu_SwapItems(u8 taskId)
{
    s16* data = gTasks[taskId].data;

    ListMenuSetUnkIndicatorsStructField(data[0], 16, 1);
    data[1] = gBagPositionStruct.scrollPosition[gBagPositionStruct.pocket] + gBagPositionStruct.cursorPosition[gBagPositionStruct.pocket];
    gBagMenu->itemOriginalLocation = data[1];
    CopyItemName(BagGetItemIdByPocketPosition(gBagPositionStruct.pocket + 1, data[1]), gStringVar1);
    StringExpandPlaceholders(gStringVar4, gText_MoveVar1Where);
    FillWindowPixelBuffer(1, PIXEL_FILL(0));
    BagMenu_Print(1, 1, gStringVar4, 3, 1, 0, 0, 0, 0);
    sub_80D4FEC(data[1]);
    BagDestroyPocketSwitchArrowPair();
    BagMenu_PrintCursor_(data[0], 2);
    gTasks[taskId].func = Task_HandleSwappingItemsInput;
}

static void Task_HandleSwappingItemsInput(u8 taskId)
{
    s16* data = gTasks[taskId].data;
    int input;

    if (MenuHelpers_CallLinkSomething() != TRUE)
    {
        if (JOY_NEW(SELECT_BUTTON))
        {
            PlaySE(SE_SELECT);
            ListMenuGetScrollAndRow(data[0], &gBagPositionStruct.scrollPosition[gBagPositionStruct.pocket], &gBagPositionStruct.cursorPosition[gBagPositionStruct.pocket]);
            sub_81AC498(taskId);
        }
        else
        {
            input = ListMenu_ProcessInput(data[0]);
            ListMenuGetScrollAndRow(data[0], &gBagPositionStruct.scrollPosition[gBagPositionStruct.pocket], &gBagPositionStruct.cursorPosition[gBagPositionStruct.pocket]);
            sub_80D4FC8(0);
            sub_80D4FEC(gBagPositionStruct.cursorPosition[gBagPositionStruct.pocket]);
            switch (input)
            {
                case LIST_NOTHING_CHOSEN:
                    break;
                case LIST_CANCEL:
                    PlaySE(SE_SELECT);
                    if (JOY_NEW(A_BUTTON))
                        sub_81AC498(taskId);
                    else
                        sub_81AC590(taskId);
                    break;
                default:
                    PlaySE(SE_SELECT);
                    sub_81AC498(taskId);
            }
        }
    }
}

void sub_81AC498(u8 taskId)
{
    s16* data = gTasks[taskId].data;
    u16* scrollPos = &gBagPositionStruct.scrollPosition[gBagPositionStruct.pocket];
    u16* cursorPos = &gBagPositionStruct.cursorPosition[gBagPositionStruct.pocket];
    u16 realPos = (*scrollPos + *cursorPos);

    if (data[1] == realPos || data[1] == (realPos - 1))
        sub_81AC590(taskId);
    else
    {
        MoveItemSlotInList(gBagPockets[gBagPositionStruct.pocket].itemSlots, data[1], realPos);
        gBagMenu->itemOriginalLocation = -1;
        DestroyListMenuTask(data[0], scrollPos, cursorPos);
        if (data[1] < realPos)
            gBagPositionStruct.cursorPosition[gBagPositionStruct.pocket]--;
        LoadBagItemListBuffers(gBagPositionStruct.pocket);
        data[0] = ListMenuInit(&gMultiuseListMenuTemplate, *scrollPos, *cursorPos);
        sub_80D4FC8(1);
        CreatePocketSwitchArrowPair();
        gTasks[taskId].func = Task_BagMenu_HandleInput;
    }
}

void sub_81AC590(u8 taskId)
{
    s16* data = gTasks[taskId].data;
    u16* scrollPos = &gBagPositionStruct.scrollPosition[gBagPositionStruct.pocket];
    u16* cursorPos = &gBagPositionStruct.cursorPosition[gBagPositionStruct.pocket];

    gBagMenu->itemOriginalLocation = -1;
    DestroyListMenuTask(data[0], scrollPos, cursorPos);
    if (data[1] < (*scrollPos + *cursorPos))
        gBagPositionStruct.cursorPosition[gBagPositionStruct.pocket]--;
    LoadBagItemListBuffers(gBagPositionStruct.pocket);
    data[0] = ListMenuInit(&gMultiuseListMenuTemplate, *scrollPos, *cursorPos);
    sub_80D4FC8(1);
    CreatePocketSwitchArrowPair();
    gTasks[taskId].func = Task_BagMenu_HandleInput;
}

void OpenContextMenu(u8 unused)
{
    switch (gBagPositionStruct.location)
    {
        case ITEMMENULOCATION_BATTLE:
        case ITEMMENULOCATION_WALLY:
            if (ItemId_GetBattleUsage(gSpecialVar_ItemId))
            {
                gBagMenu->contextMenuItemsPtr = sContextMenuItems_BattleUse;
                gBagMenu->contextMenuNumItems = ARRAY_COUNT(sContextMenuItems_BattleUse);
            }
            else
            {
                gBagMenu->contextMenuItemsPtr = sContextMenuItems_Cancel;
                gBagMenu->contextMenuNumItems = ARRAY_COUNT(sContextMenuItems_Cancel);
            }
            break;
        case ITEMMENULOCATION_BERRY_BLENDER_CRUSH:
            gBagMenu->contextMenuItemsPtr = sContextMenuItems_BerryBlenderCrush;
            gBagMenu->contextMenuNumItems = ARRAY_COUNT(sContextMenuItems_BerryBlenderCrush);
            break;
        case ITEMMENULOCATION_APPRENTICE:
            if (!ItemId_GetImportance(gSpecialVar_ItemId) && gSpecialVar_ItemId != ITEM_ENIGMA_BERRY)
            {
                gBagMenu->contextMenuItemsPtr = sContextMenuItems_Apprentice;
                gBagMenu->contextMenuNumItems = ARRAY_COUNT(sContextMenuItems_Apprentice);
            }
            else
            {
                gBagMenu->contextMenuItemsPtr = sContextMenuItems_Cancel;
                gBagMenu->contextMenuNumItems = ARRAY_COUNT(sContextMenuItems_Cancel);
            }
            break;
        case ITEMMENULOCATION_FAVOR_LADY:
            if (!ItemId_GetImportance(gSpecialVar_ItemId) && gSpecialVar_ItemId != ITEM_ENIGMA_BERRY)
            {
                gBagMenu->contextMenuItemsPtr = sContextMenuItems_FavorLady;
                gBagMenu->contextMenuNumItems = ARRAY_COUNT(sContextMenuItems_FavorLady);
            }
            else
            {
                gBagMenu->contextMenuItemsPtr = sContextMenuItems_Cancel;
                gBagMenu->contextMenuNumItems = ARRAY_COUNT(sContextMenuItems_Cancel);
            }
            break;
        case ITEMMENULOCATION_QUIZ_LADY:
            if (!ItemId_GetImportance(gSpecialVar_ItemId) && gSpecialVar_ItemId != ITEM_ENIGMA_BERRY)
            {
                gBagMenu->contextMenuItemsPtr = sContextMenuItems_QuizLady;
                gBagMenu->contextMenuNumItems = ARRAY_COUNT(sContextMenuItems_QuizLady);
            }
            else
            {
                gBagMenu->contextMenuItemsPtr = sContextMenuItems_Cancel;
                gBagMenu->contextMenuNumItems = ARRAY_COUNT(sContextMenuItems_Cancel);
            }
            break;
        case ITEMMENULOCATION_PARTY:
        case ITEMMENULOCATION_SHOP:
        case ITEMMENULOCATION_BERRY_TREE:
        case ITEMMENULOCATION_ITEMPC:
        default:
            if (MenuHelpers_LinkSomething() == TRUE || InUnionRoom() == TRUE)
            {
                if (gBagPositionStruct.pocket == KEYITEMS_POCKET || !sub_8122148(gSpecialVar_ItemId))
                {
                    gBagMenu->contextMenuItemsPtr = sContextMenuItems_Cancel;
                    gBagMenu->contextMenuNumItems = ARRAY_COUNT(sContextMenuItems_Cancel);
                }
                else
                {
                    gBagMenu->contextMenuItemsPtr = sContextMenuItems_Give;
                    gBagMenu->contextMenuNumItems = ARRAY_COUNT(sContextMenuItems_Give);
                }
            }
            else
            {
                switch (gBagPositionStruct.pocket)
                {
                    case ITEMS_POCKET:
                        gBagMenu->contextMenuItemsPtr = gBagMenu->contextMenuItemsBuffer;
                        gBagMenu->contextMenuNumItems = ARRAY_COUNT(sContextMenuItems_ItemsPocket);
                        memcpy(&gBagMenu->contextMenuItemsBuffer, &sContextMenuItems_ItemsPocket, sizeof(sContextMenuItems_ItemsPocket));
                        if (ItemIsMail(gSpecialVar_ItemId) == TRUE)
                            gBagMenu->contextMenuItemsBuffer[0] = ITEMMENUACTION_CHECK;
                        break;
                    case KEYITEMS_POCKET:
                        gBagMenu->contextMenuItemsPtr = gBagMenu->contextMenuItemsBuffer;
                        gBagMenu->contextMenuNumItems = ARRAY_COUNT(sContextMenuItems_KeyItemsPocket);
                        memcpy(&gBagMenu->contextMenuItemsBuffer, &sContextMenuItems_KeyItemsPocket, sizeof(sContextMenuItems_KeyItemsPocket));
                        if (gSaveBlock1Ptr->registeredItem == gSpecialVar_ItemId)
                            gBagMenu->contextMenuItemsBuffer[1] = ITEMMENUACTION_DESELECT;
                        if (gSpecialVar_ItemId == ITEM_MACH_BIKE || gSpecialVar_ItemId == ITEM_ACRO_BIKE)
                        {
                            if (TestPlayerAvatarFlags(PLAYER_AVATAR_FLAG_MACH_BIKE | PLAYER_AVATAR_FLAG_ACRO_BIKE))
                                gBagMenu->contextMenuItemsBuffer[0] = ITEMMENUACTION_WALK;
                        }
                        break;
                    case BALLS_POCKET:
                        gBagMenu->contextMenuItemsPtr = sContextMenuItems_BallsPocket;
                        gBagMenu->contextMenuNumItems = ARRAY_COUNT(sContextMenuItems_BallsPocket);
                        break;
                    case TMHM_POCKET:
                        gBagMenu->contextMenuItemsPtr = sContextMenuItems_TmHmPocket;
                        gBagMenu->contextMenuNumItems = ARRAY_COUNT(sContextMenuItems_TmHmPocket);
                        break;
                    case BERRIES_POCKET:
                        gBagMenu->contextMenuItemsPtr = sContextMenuItems_BerriesPocket;
                        gBagMenu->contextMenuNumItems = ARRAY_COUNT(sContextMenuItems_BerriesPocket);
                        break;
                }
            }
    }
    if (gBagPositionStruct.pocket == TMHM_POCKET)
    {
        ClearWindowTilemap(1);
        PrintTMHMMoveData(gSpecialVar_ItemId);
        PutWindowTilemap(3);
        PutWindowTilemap(4);
        ScheduleBgCopyTilemapToVram(0);
    }
    else
    {
        CopyItemName(gSpecialVar_ItemId, gStringVar1);
        StringExpandPlaceholders(gStringVar4, gText_Var1IsSelected);
        FillWindowPixelBuffer(1, PIXEL_FILL(0));
        BagMenu_Print(1, 1, gStringVar4, 3, 1, 0, 0, 0, 0);
    }
    if (gBagMenu->contextMenuNumItems == 1)
        sub_81ACAF8(BagMenu_AddWindow(0));
    else if (gBagMenu->contextMenuNumItems == 2)
        sub_81ACAF8(BagMenu_AddWindow(1));
    else if (gBagMenu->contextMenuNumItems == 4)
        sub_81ACB54(BagMenu_AddWindow(2), 2, 2);
    else
        sub_81ACB54(BagMenu_AddWindow(3), 2, 3);
}

void sub_81ACAF8(u8 a)
{
    AddItemMenuActionTextPrinters(a, 7, 8, 1, 0, 16, gBagMenu->contextMenuNumItems, sItemMenuActions, gBagMenu->contextMenuItemsPtr);
    InitMenuInUpperLeftCornerPlaySoundWhenAPressed(a, gBagMenu->contextMenuNumItems, 0);
}

void sub_81ACB54(u8 a, u8 b, u8 c)
{
    sub_8198DBC(a, 7, 8, 1, 0x38, b, c, sItemMenuActions, gBagMenu->contextMenuItemsPtr);
    sub_8199944(a, 0x38, b, c, 0);
}

void Task_ItemContext_FieldOrBattle(u8 taskId)
{
    OpenContextMenu(taskId);
    if (gBagMenu->contextMenuNumItems <= 2)
        gTasks[taskId].func = Task_HandleInBattleItemMenuInput;
    else
        gTasks[taskId].func = Task_HandleOutOfBattleItemMenuInput;
}

void Task_HandleInBattleItemMenuInput(u8 taskId)
{
    if (MenuHelpers_CallLinkSomething() != TRUE)
    {
        s8 selection = Menu_ProcessInputNoWrap();
        switch (selection)
        {
            case MENU_NOTHING_CHOSEN:
                break;
            case MENU_B_PRESSED:
                PlaySE(SE_SELECT);
                sItemMenuActions[ITEMMENUACTION_CANCEL].func.void_u8(taskId);
                break;
            default:
                PlaySE(SE_SELECT);
                sItemMenuActions[gBagMenu->contextMenuItemsPtr[selection]].func.void_u8(taskId);
                break;
        }
    }
}

void Task_HandleOutOfBattleItemMenuInput(u8 taskId)
{
    if (MenuHelpers_CallLinkSomething() != TRUE)
    {
        s8 cursorPos = Menu_GetCursorPos();
        if (JOY_NEW(DPAD_UP))
        {
            if (cursorPos > 0 && sub_81ACDFC(cursorPos - 2))
            {
                PlaySE(SE_SELECT);
                ChangeListMenuCursorPosition(MENU_CURSOR_DELTA_NONE, MENU_CURSOR_DELTA_UP);
            }
        }
        else if (JOY_NEW(DPAD_DOWN))
        {
            if (cursorPos < (gBagMenu->contextMenuNumItems - 2) && sub_81ACDFC(cursorPos + 2))
            {
                PlaySE(SE_SELECT);
                ChangeListMenuCursorPosition(MENU_CURSOR_DELTA_NONE, MENU_CURSOR_DELTA_DOWN);
            }
        }
        else if ((JOY_NEW(DPAD_LEFT)) || GetLRKeysPressed() == MENU_L_PRESSED)
        {
            if ((cursorPos & 1) && sub_81ACDFC(cursorPos - 1))
            {
                PlaySE(SE_SELECT);
                ChangeListMenuCursorPosition(MENU_CURSOR_DELTA_LEFT, MENU_CURSOR_DELTA_NONE);
            }
        }
        else if ((JOY_NEW(DPAD_RIGHT)) || GetLRKeysPressed() == MENU_R_PRESSED)
        {
            if (!(cursorPos & 1) && sub_81ACDFC(cursorPos + 1))
            {
                PlaySE(SE_SELECT);
                ChangeListMenuCursorPosition(MENU_CURSOR_DELTA_RIGHT, MENU_CURSOR_DELTA_NONE);
            }
        }
        else if (JOY_NEW(A_BUTTON))
        {
            PlaySE(SE_SELECT);
            sItemMenuActions[gBagMenu->contextMenuItemsPtr[cursorPos]].func.void_u8(taskId);
        }
        else if (JOY_NEW(B_BUTTON))
        {
            PlaySE(SE_SELECT);
            sItemMenuActions[ITEMMENUACTION_CANCEL].func.void_u8(taskId);
        }
    }
}

bool8 sub_81ACDFC(s8 a)
{
    if (a < 0)
        return FALSE;
    if (a > gBagMenu->contextMenuNumItems)
        return FALSE;
    if (gBagMenu->contextMenuItemsPtr[a] == 14)
        return FALSE;
    return TRUE;
}

void BagMenu_RemoveSomeWindow(void)
{
    if (gBagMenu->contextMenuNumItems == 1)
        BagMenu_RemoveWindow(0);
    else if (gBagMenu->contextMenuNumItems == 2)
    {
        BagMenu_RemoveWindow(1);
    }
    else if (gBagMenu->contextMenuNumItems == 4)
    {
        BagMenu_RemoveWindow(2);
    }
    else
        BagMenu_RemoveWindow(3);
}

void ItemMenu_UseOutOfBattle(u8 taskId)
{
    if (ItemId_GetFieldFunc(gSpecialVar_ItemId))
    {
        BagMenu_RemoveSomeWindow();
        if (CalculatePlayerPartyCount() == 0 && ItemId_GetType(gSpecialVar_ItemId) == ITEM_USE_PARTY_MENU)
            BagMenu_PrintThereIsNoPokemon(taskId);
        else
        {
            FillWindowPixelBuffer(1, PIXEL_FILL(0));
            ScheduleBgCopyTilemapToVram(0);
            if (gBagPositionStruct.pocket != BERRIES_POCKET)
                ItemId_GetFieldFunc(gSpecialVar_ItemId)(taskId);
            else
                ItemUseOutOfBattle_Berry(taskId);
        }
    }
}

void ItemMenu_Toss(u8 taskId)
{
    s16* data = gTasks[taskId].data;

    BagMenu_RemoveSomeWindow();
    tItemCount = 1;
    if (data[2] == 1)
    {
        BagMenu_TossItems(taskId);
    }
    else
    {
        CopyItemName(gSpecialVar_ItemId, gStringVar1);
        StringExpandPlaceholders(gStringVar4, gText_TossHowManyVar1s);
        FillWindowPixelBuffer(1, PIXEL_FILL(0));
        BagMenu_Print(1, 1, gStringVar4, 3, 1, 0, 0, 0, 0);
        sub_81ABC3C(7);
        gTasks[taskId].func = Task_ChooseHowManyToToss;
    }
}

void BagMenu_TossItems(u8 taskId)
{
    s16* data = gTasks[taskId].data;

    CopyItemName(gSpecialVar_ItemId, gStringVar1);
    ConvertIntToDecimalStringN(gStringVar2, tItemCount, STR_CONV_MODE_LEFT_ALIGN, MAX_ITEM_DIGITS);
    StringExpandPlaceholders(gStringVar4, gText_ConfirmTossItems);
    FillWindowPixelBuffer(1, PIXEL_FILL(0));
    BagMenu_Print(1, 1, gStringVar4, 3, 1, 0, 0, 0, 0);
    BagMenu_YesNo(taskId, 5, &sYesNoTossFunctions);
}

void BagMenu_CancelToss(u8 taskId)
{
    s16* data = gTasks[taskId].data;

    BagMenu_PrintDescription(data[1]);
    BagMenu_PrintCursor_(data[0], 0);
    set_callback3_to_bag(taskId);
}

void Task_ChooseHowManyToToss(u8 taskId)
{
    s16* data = gTasks[taskId].data;

    if (AdjustQuantityAccordingToDPadInput(&tItemCount, data[2]) == TRUE)
    {
        PrintItemDepositAmount(gBagMenu->windowPointers[7], tItemCount);
    }
    else if (JOY_NEW(A_BUTTON))
    {
        PlaySE(SE_SELECT);
        BagMenu_RemoveWindow(7);
        BagMenu_TossItems(taskId);
    }
    else if (JOY_NEW(B_BUTTON))
    {
        PlaySE(SE_SELECT);
        BagMenu_RemoveWindow(7);
        BagMenu_CancelToss(taskId);
    }
}

void BagMenu_ConfirmToss(u8 taskId)
{
    s16* data = gTasks[taskId].data;

    CopyItemName(gSpecialVar_ItemId, gStringVar1);
    ConvertIntToDecimalStringN(gStringVar2, tItemCount, STR_CONV_MODE_LEFT_ALIGN, MAX_ITEM_DIGITS);
    StringExpandPlaceholders(gStringVar4, gText_ThrewAwayVar2Var1s);
    FillWindowPixelBuffer(1, PIXEL_FILL(0));
    BagMenu_Print(1, 1, gStringVar4, 3, 1, 0, 0, 0, 0);
    gTasks[taskId].func = Task_ActuallyToss;
}

void Task_ActuallyToss(u8 taskId)
{
    s16* data = gTasks[taskId].data;
    u16* scrollPos = &gBagPositionStruct.scrollPosition[gBagPositionStruct.pocket];
    u16* cursorPos = &gBagPositionStruct.cursorPosition[gBagPositionStruct.pocket];

    if (JOY_NEW(A_BUTTON | B_BUTTON))
    {
        PlaySE(SE_SELECT);
        RemoveBagItem(gSpecialVar_ItemId, tItemCount);
        DestroyListMenuTask(data[0], scrollPos, cursorPos);
        UpdatePocketItemList(gBagPositionStruct.pocket);
        SetInitialScrollAndCursorPositions(gBagPositionStruct.pocket);
        LoadBagItemListBuffers(gBagPositionStruct.pocket);
        data[0] = ListMenuInit(&gMultiuseListMenuTemplate, *scrollPos, *cursorPos);
        ScheduleBgCopyTilemapToVram(0);
        set_callback3_to_bag(taskId);
    }
}

void ItemMenu_Register(u8 taskId)
{
    s16* data = gTasks[taskId].data;
    u16* scrollPos = &gBagPositionStruct.scrollPosition[gBagPositionStruct.pocket];
    u16* cursorPos = &gBagPositionStruct.cursorPosition[gBagPositionStruct.pocket];

    if (gSaveBlock1Ptr->registeredItem == gSpecialVar_ItemId)
        gSaveBlock1Ptr->registeredItem = 0;
    else
        gSaveBlock1Ptr->registeredItem = gSpecialVar_ItemId;
    DestroyListMenuTask(data[0], scrollPos, cursorPos);
    LoadBagItemListBuffers(gBagPositionStruct.pocket);
    data[0] = ListMenuInit(&gMultiuseListMenuTemplate, *scrollPos, *cursorPos);
    ScheduleBgCopyTilemapToVram(0);
    ItemMenu_Cancel(taskId);
}

void ItemMenu_Give(u8 taskId)
{
    BagMenu_RemoveSomeWindow();
    if (!itemid_80BF6D8_mail_related(gSpecialVar_ItemId))
    {
        DisplayItemMessage(taskId, 1, gText_CantWriteMail, sub_81AD350);
    }
    else if (!ItemId_GetImportance(gSpecialVar_ItemId))
    {
        if (CalculatePlayerPartyCount() == 0)
            BagMenu_PrintThereIsNoPokemon(taskId);
        else
        {
            gBagMenu->exitCallback = CB2_ChooseMonToGiveItem;
            Task_FadeAndCloseBagMenu(taskId);
        }
    }
    else
    {
        BagMenu_PrintItemCantBeHeld(taskId);
    }
}

void BagMenu_PrintThereIsNoPokemon(u8 taskId)
{
    DisplayItemMessage(taskId, 1, gText_NoPokemon, sub_81AD350);
}

static void BagMenu_PrintItemCantBeHeld(u8 taskId)
{
    CopyItemName(gSpecialVar_ItemId, gStringVar1);
    StringExpandPlaceholders(gStringVar4, gText_Var1CantBeHeld);
    DisplayItemMessage(taskId, 1, gStringVar4, sub_81AD350);
}

void sub_81AD350(u8 taskId)
{
    if (JOY_NEW(A_BUTTON))
    {
        PlaySE(SE_SELECT);
        BagMenu_InitListsMenu(taskId);
    }
}

void ItemMenu_CheckTag(u8 taskId)
{
    gBagMenu->exitCallback = DoBerryTagScreen;
    Task_FadeAndCloseBagMenu(taskId);
}

void ItemMenu_Cancel(u8 taskId)
{
    s16* data = gTasks[taskId].data;

    BagMenu_RemoveSomeWindow();
    BagMenu_PrintDescription(data[1]);
    ScheduleBgCopyTilemapToVram(0);
    ScheduleBgCopyTilemapToVram(1);
    BagMenu_PrintCursor_(data[0], 0);
    set_callback3_to_bag(taskId);
}

void ItemMenu_UseInBattle(u8 taskId)
{
    if (ItemId_GetBattleFunc(gSpecialVar_ItemId))
    {
        BagMenu_RemoveSomeWindow();
        ItemId_GetBattleFunc(gSpecialVar_ItemId)(taskId);
    }
}

void CB2_ReturnToBagMenuPocket(void)
{
    GoToBagMenu(ITEMMENULOCATION_LAST, POCKETS_COUNT, NULL);
}

void Task_ItemContext_FieldGive(u8 taskId)
{
    if (!itemid_80BF6D8_mail_related(gSpecialVar_ItemId))
    {
        DisplayItemMessage(taskId, 1, gText_CantWriteMail, sub_81AD350);
    }
    else if (!sub_8122148(gSpecialVar_ItemId))
    {
        CopyItemName(gSpecialVar_ItemId, gStringVar1);
        StringExpandPlaceholders(gStringVar4, gText_Var1CantBeHeldHere);
        DisplayItemMessage(taskId, 1, gStringVar4, sub_81AD350);
    }
    else if (gBagPositionStruct.pocket != KEYITEMS_POCKET && !ItemId_GetImportance(gSpecialVar_ItemId))
    {
        Task_FadeAndCloseBagMenu(taskId);
    }
    else
    {
        BagMenu_PrintItemCantBeHeld(taskId);
    }
}

void Task_ItemContext_ItemPC_2(u8 taskId)
{
    if (ItemIsMail(gSpecialVar_ItemId) == TRUE)
        DisplayItemMessage(taskId, 1, gText_CantWriteMail, sub_81AD350);
    else if (gBagPositionStruct.pocket != KEYITEMS_POCKET && !ItemId_GetImportance(gSpecialVar_ItemId))
        gTasks[taskId].func = Task_FadeAndCloseBagMenu;
    else
        BagMenu_PrintItemCantBeHeld(taskId);
}

#define tUsingRegisteredKeyItem data[3]

bool8 UseRegisteredKeyItemOnField(void)
{
    u8 taskId;

    if (InUnionRoom() == TRUE || InBattlePyramid() || InBattlePike() || InMultiPartnerRoom() == TRUE)
        return FALSE;
    HideMapNamePopUpWindow();
    ChangeBgY_ScreenOff(0, 0, 0);
    if (gSaveBlock1Ptr->registeredItem != ITEM_NONE)
    {
        if (CheckBagHasItem(gSaveBlock1Ptr->registeredItem, 1) == TRUE)
        {
            ScriptContext2_Enable();
            FreezeObjectEvents();
            sub_808B864();
            sub_808BCF4();
            gSpecialVar_ItemId = gSaveBlock1Ptr->registeredItem;
            taskId = CreateTask(ItemId_GetFieldFunc(gSaveBlock1Ptr->registeredItem), 8);
            gTasks[taskId].tUsingRegisteredKeyItem = TRUE;
            return TRUE;
        }
        else
        {
            gSaveBlock1Ptr->registeredItem = ITEM_NONE;
        }
    }
    ScriptContext1_SetupScript(EventScript_SelectWithoutRegisteredItem);
    return TRUE;
}

#undef tUsingRegisteredKeyItem

void Task_ItemContext_Sell(u8 taskId)
{
    s16* data = gTasks[taskId].data;

    if (ItemId_GetPrice(gSpecialVar_ItemId) == 0)
    {
        CopyItemName(gSpecialVar_ItemId, gStringVar2);
        StringExpandPlaceholders(gStringVar4, gText_CantBuyKeyItem);
        DisplayItemMessage(taskId, 1, gStringVar4, BagMenu_InitListsMenu);
    }
    else
    {
        tItemCount = 1;
        if (data[2] == 1)
        {
            DisplayCurrentMoneyWindow();
            DisplaySellItemPriceAndConfirm(taskId);
        }
        else
        {
            CopyItemName(gSpecialVar_ItemId, gStringVar2);
            StringExpandPlaceholders(gStringVar4, gText_HowManyToSell);
            DisplayItemMessage(taskId, 1, gStringVar4, sub_81AD730);
        }
    }
}

static void DisplaySellItemPriceAndConfirm(u8 taskId)
{
    s16* data = gTasks[taskId].data;

    ConvertIntToDecimalStringN(gStringVar1, (ItemId_GetPrice(gSpecialVar_ItemId) / 2) * tItemCount, STR_CONV_MODE_LEFT_ALIGN, 6);
    StringExpandPlaceholders(gStringVar4, gText_ICanPayVar1);
    DisplayItemMessage(taskId, 1, gStringVar4, sub_81AD6E4);
}

void sub_81AD6E4(u8 taskId)
{
    BagMenu_YesNo(taskId, 6, &sYesNoSellItemFunctions);
}

void BagMenu_CancelSell(u8 taskId)
{
    s16* data = gTasks[taskId].data;

    RemoveMoneyWindow();
    BagMenu_RemoveBagItemMessageindow(4);
    BagMenu_PrintCursor_(data[0], 0);
    set_callback3_to_bag(taskId);
}

void sub_81AD730(u8 taskId)
{
    s16* data = gTasks[taskId].data;
    u8 windowId = BagMenu_AddWindow(8);

    PrintItemSoldAmount(windowId, 1, (ItemId_GetPrice(gSpecialVar_ItemId) / 2) * tItemCount);
    DisplayCurrentMoneyWindow();
    gTasks[taskId].func = Task_SellHowManyDialogueHandleInput;
}

static void Task_SellHowManyDialogueHandleInput(u8 taskId)
{
    s16* data = gTasks[taskId].data;

    if (AdjustQuantityAccordingToDPadInput(&tItemCount, data[2]) == TRUE)
    {
        PrintItemSoldAmount(gBagMenu->windowPointers[8], tItemCount, (ItemId_GetPrice(gSpecialVar_ItemId) / 2) * tItemCount);
    }
    else if (JOY_NEW(A_BUTTON))
    {
        PlaySE(SE_SELECT);
        BagMenu_RemoveWindow(8);
        DisplaySellItemPriceAndConfirm(taskId);
    }
    else if (JOY_NEW(B_BUTTON))
    {
        PlaySE(SE_SELECT);
        BagMenu_PrintCursor_(data[0], 0);
        RemoveMoneyWindow();
        BagMenu_RemoveWindow(8);
        BagMenu_RemoveBagItemMessageindow(4);
        set_callback3_to_bag(taskId);
    }
}

void BagMenu_ConfirmSell(u8 taskId)
{
    s16* data = gTasks[taskId].data;

    CopyItemName(gSpecialVar_ItemId, gStringVar2);
    ConvertIntToDecimalStringN(gStringVar1, (ItemId_GetPrice(gSpecialVar_ItemId) / 2) * tItemCount, STR_CONV_MODE_LEFT_ALIGN, 6);
    StringExpandPlaceholders(gStringVar4, gText_TurnedOverVar1ForVar2);
    DisplayItemMessage(taskId, 1, gStringVar4, BagMenu_Sell_UpdateItemListAndMoney);
}

static void BagMenu_Sell_UpdateItemListAndMoney(u8 taskId)
{
    s16* data = gTasks[taskId].data;
    u16* scrollPos = &gBagPositionStruct.scrollPosition[gBagPositionStruct.pocket];
    u16* cursorPos = &gBagPositionStruct.cursorPosition[gBagPositionStruct.pocket];

    PlaySE(SE_SHOP);
    RemoveBagItem(gSpecialVar_ItemId, tItemCount);
    AddMoney(&gSaveBlock1Ptr->money, (ItemId_GetPrice(gSpecialVar_ItemId) / 2) * tItemCount);
    DestroyListMenuTask(data[0], scrollPos, cursorPos);
    UpdatePocketItemList(gBagPositionStruct.pocket);
    SetInitialScrollAndCursorPositions(gBagPositionStruct.pocket);
    LoadBagItemListBuffers(gBagPositionStruct.pocket);
    data[0] = ListMenuInit(&gMultiuseListMenuTemplate, *scrollPos, *cursorPos);
    BagMenu_PrintCursor_(data[0], 2);
    PrintMoneyAmountInMoneyBox(gBagMenu->windowPointers[9], GetMoney(&gSaveBlock1Ptr->money), 0);
    gTasks[taskId].func = BagMenu_Sell_WaitForABPress;
}

static void BagMenu_Sell_WaitForABPress(u8 taskId)
{
    if (JOY_NEW(A_BUTTON | B_BUTTON))
    {
        PlaySE(SE_SELECT);
        RemoveMoneyWindow();
        BagMenu_InitListsMenu(taskId);
    }
}

void Task_ItemContext_Deposit(u8 taskId)
{
    s16* data = gTasks[taskId].data;

    tItemCount = 1;
    if (data[2] == 1)
    {
        BagMenu_TryDepositItem(taskId);
    }
    else
    {
        CopyItemName(gSpecialVar_ItemId, gStringVar1);
        StringExpandPlaceholders(gStringVar4, gText_DepositHowManyVar1);
        FillWindowPixelBuffer(1, PIXEL_FILL(0));
        BagMenu_Print(1, 1, gStringVar4, 3, 1, 0, 0, 0, 0);
        sub_81ABC3C(7);
        gTasks[taskId].func = Task_ChooseHowManyToDeposit;
    }
}

static void Task_ChooseHowManyToDeposit(u8 taskId)
{
    s16* data = gTasks[taskId].data;

    if (AdjustQuantityAccordingToDPadInput(&tItemCount, data[2]) == TRUE)
    {
        PrintItemDepositAmount(gBagMenu->windowPointers[7], tItemCount);
    }
    else if (JOY_NEW(A_BUTTON))
    {
        PlaySE(SE_SELECT);
        BagMenu_RemoveWindow(7);
        BagMenu_TryDepositItem(taskId);
    }
    else if (JOY_NEW(B_BUTTON))
    {
        PlaySE(SE_SELECT);
        BagMenu_PrintDescription(data[1]);
        BagMenu_PrintCursor_(data[0], 0);
        BagMenu_RemoveWindow(7);
        set_callback3_to_bag(taskId);
    }
}

static void BagMenu_TryDepositItem(u8 taskId)
{
    s16* data = gTasks[taskId].data;

    FillWindowPixelBuffer(1, PIXEL_FILL(0));
    if (ItemId_GetImportance(gSpecialVar_ItemId))
    {
        BagMenu_Print(1, 1, gText_CantStoreImportantItems, 3, 1, 0, 0, 0, 0);
        gTasks[taskId].func = BagMenu_Deposit_WaitForABPress;
    }
    else if (AddPCItem(gSpecialVar_ItemId, tItemCount) == TRUE)
    {
        CopyItemName(gSpecialVar_ItemId, gStringVar1);
        ConvertIntToDecimalStringN(gStringVar2, tItemCount, STR_CONV_MODE_LEFT_ALIGN, MAX_ITEM_DIGITS);
        StringExpandPlaceholders(gStringVar4, gText_DepositedVar2Var1s);
        BagMenu_Print(1, 1, gStringVar4, 3, 1, 0, 0, 0, 0);
        gTasks[taskId].func = Task_ActuallyToss;
    }
    else
    {
        BagMenu_Print(1, 1, gText_NoRoomForItems, 3, 1, 0, 0, 0, 0);
        gTasks[taskId].func = BagMenu_Deposit_WaitForABPress;
    }
}

static void BagMenu_Deposit_WaitForABPress(u8 taskId)
{
    s16* data = gTasks[taskId].data;

    if (JOY_NEW(A_BUTTON | B_BUTTON))
    {
        PlaySE(SE_SELECT);
        BagMenu_PrintDescription(data[1]);
        BagMenu_PrintCursor_(data[0], 0);
        set_callback3_to_bag(taskId);
    }
}

bool8 IsWallysBag(void)
{
    if (gBagPositionStruct.location == 10)
        return TRUE;
    return FALSE;
}

void PrepareBagForWallyTutorial(void)
{
    u32 i;

    sTempWallyBag = AllocZeroed(sizeof(struct TempWallyStruct));
    memcpy(sTempWallyBag->bagPocket_Items, gSaveBlock1Ptr->bagPocket_Items, sizeof(gSaveBlock1Ptr->bagPocket_Items));
    memcpy(sTempWallyBag->bagPocket_PokeBalls, gSaveBlock1Ptr->bagPocket_PokeBalls, sizeof(gSaveBlock1Ptr->bagPocket_PokeBalls));
    sTempWallyBag->pocket = gBagPositionStruct.pocket;
    for (i = 0; i <= 4; i++)
    {
        sTempWallyBag->cursorPosition[i] = gBagPositionStruct.cursorPosition[i];
        sTempWallyBag->scrollPosition[i] = gBagPositionStruct.scrollPosition[i];
    }
    ClearItemSlots(gSaveBlock1Ptr->bagPocket_Items, BAG_ITEMS_COUNT);
    ClearItemSlots(gSaveBlock1Ptr->bagPocket_PokeBalls, BAG_POKEBALLS_COUNT);
    ResetBagScrollPositions();
}

void RestoreBagAfterWallyTutorial(void)
{
    u32 i;

    memcpy(gSaveBlock1Ptr->bagPocket_Items, sTempWallyBag->bagPocket_Items, sizeof(sTempWallyBag->bagPocket_Items));
    memcpy(gSaveBlock1Ptr->bagPocket_PokeBalls, sTempWallyBag->bagPocket_PokeBalls, sizeof(sTempWallyBag->bagPocket_PokeBalls));
    gBagPositionStruct.pocket = sTempWallyBag->pocket;
    for (i = 0; i <= 4; i++)
    {
        gBagPositionStruct.cursorPosition[i] = sTempWallyBag->cursorPosition[i];
        gBagPositionStruct.scrollPosition[i] = sTempWallyBag->scrollPosition[i];
    }
    Free(sTempWallyBag);
}

void DoWallyTutorialBagMenu(void)
{
    PrepareBagForWallyTutorial();
    AddBagItem(ITEM_POTION, 1);
    AddBagItem(ITEM_POKE_BALL, 1);
    GoToBagMenu(ITEMMENULOCATION_WALLY, ITEMS_POCKET, CB2_SetUpReshowBattleScreenAfterMenu2);
}

void Task_WallyTutorialBagMenu(u8 taskId)
{
    s16* data = gTasks[taskId].data;

    if (!gPaletteFade.active)
    {
        switch (data[8])
        {
            case 0x66:
                PlaySE(SE_SELECT);
                SwitchBagPocket(taskId, MENU_CURSOR_DELTA_RIGHT, 0);
                data[8]++;
                break;
            case 0xCC:
                PlaySE(SE_SELECT);
                BagMenu_PrintCursor_(data[0], 2);
                gSpecialVar_ItemId = ITEM_POKE_BALL;
                OpenContextMenu(taskId);
                data[8]++;
                break;
            case 0x132:
                PlaySE(SE_SELECT);
                BagMenu_RemoveSomeWindow();
                DestroyListMenuTask(data[0], 0, 0);
                RestoreBagAfterWallyTutorial();
                Task_FadeAndCloseBagMenu(taskId);
                break;
            default:
                data[8]++;
                break;
        }
    }
}

#undef tItemCount

void unknown_ItemMenu_Show(u8 taskId)
{
    gSpecialVar_0x8005 = gSpecialVar_ItemId;
    gSpecialVar_Result = 1;
    BagMenu_RemoveSomeWindow();
    Task_FadeAndCloseBagMenu(taskId);
}

void CB2_ApprenticeExitBagMenu(void)
{
    gFieldCallback = Apprentice_EnableBothScriptContexts;
    SetMainCallback2(CB2_ReturnToField);
}

void unknown_ItemMenu_Give2(u8 taskId)
{
    RemoveBagItem(gSpecialVar_ItemId, 1);
    gSpecialVar_Result = 1;
    BagMenu_RemoveSomeWindow();
    Task_FadeAndCloseBagMenu(taskId);
}

void CB2_FavorLadyExitBagMenu(void)
{
    gFieldCallback = FieldCallback_FavorLadyEnableScriptContexts;
    SetMainCallback2(CB2_ReturnToField);
}

void unknown_ItemMenu_Confirm2(u8 taskId)
{
    gSpecialVar_Result = 1;
    BagMenu_RemoveSomeWindow();
    Task_FadeAndCloseBagMenu(taskId);
}

void CB2_QuizLadyExitBagMenu(void)
{
    gFieldCallback = FieldCallback_QuizLadyEnableScriptContexts;
    SetMainCallback2(CB2_ReturnToField);
}

void BagMenu_PrintPocketNames(const u8 *pocketName1, const u8 *pocketName2)
{
    struct WindowTemplate window = {0, 0, 0, 0, 0, 0, 0};
    u16 windowId;
    int offset;

    window.width = 16;
    window.height = 2;
    windowId = AddWindow(&window);
    FillWindowPixelBuffer(windowId, PIXEL_FILL(0));
    offset = GetStringCenterAlignXOffset(1, pocketName1, 0x40);
    BagMenu_Print(windowId, 1, pocketName1, offset, 1, 0, 0, -1, 1);
    if (pocketName2)
    {
        offset = GetStringCenterAlignXOffset(1, pocketName2, 0x40);
        BagMenu_Print(windowId, 1, pocketName2, offset + 0x40, 1, 0, 0, -1, 1);
    }
    CpuCopy32((u8*)GetWindowAttribute(windowId, WINDOW_TILE_DATA), gBagMenu->pocketNameBuffer, 0x400);
    RemoveWindow(windowId);
}

void BagMenu_CopyPocketNameToWindow(u32 a)
{
    u8 (* r4)[32][32];
    u8* windowAttribute;
    int b;
    if (a > 8)
        a = 8;
    r4 = &gBagMenu->pocketNameBuffer;
    windowAttribute = (u8*)GetWindowAttribute(2, WINDOW_TILE_DATA);
    CpuCopy32(r4[0][a], windowAttribute, 0x100);
    b = a + 16;
    CpuCopy32(r4[0][b], windowAttribute + 0x100, 0x100);
    CopyWindowToVram(2, 2);
}

void SetupBagMenu_Textboxes(void)
{
    u8 i;

    InitWindows(sDefaultBagWindows);
    DeactivateAllTextPrinters();
    LoadUserWindowBorderGfx(0, 1, 0xE0);
    LoadMessageBoxGfx(0, 10, 0xD0);
    ListMenuLoadStdPalAt(0xC0, 1);
    LoadPalette(&gUnknown_0860F074, 0xF0, 0x20);
    for (i = 0; i < 3; i++)
    {
        FillWindowPixelBuffer(i, PIXEL_FILL(0));
        PutWindowTilemap(i);
    }
    ScheduleBgCopyTilemapToVram(0);
    ScheduleBgCopyTilemapToVram(1);
}

void BagMenu_Print(u8 windowId, u8 fontId, const u8 *str, u8 left, u8 top, u8 letterSpacing, u8 lineSpacing, u8 speed, u8 colorIndex)
{
    AddTextPrinterParameterized4(windowId, fontId, left, top, letterSpacing, lineSpacing, sFontColorTable[colorIndex], speed, str);
}

//Unused
u8 sub_81AE124(u8 which)
{
    return gBagMenu->windowPointers[which];
}

u8 BagMenu_AddWindow(u8 which)
{
    u8 *ptr = &gBagMenu->windowPointers[which];
    if (*ptr == 0xFF)
    {
        *ptr = AddWindow(&sContextMenuWindowTemplates[which]);
        DrawStdFrameWithCustomTileAndPalette(*ptr, 0, 1, 14);
        ScheduleBgCopyTilemapToVram(1);
    }
    return *ptr;
}

void BagMenu_RemoveWindow(u8 which)
{
    u8 *ptr = &gBagMenu->windowPointers[which];
    if (*ptr != 0xFF)
    {
        ClearStdWindowAndFrameToTransparent(*ptr, FALSE);
        ClearWindowTilemap(*ptr);
        RemoveWindow(*ptr);
        ScheduleBgCopyTilemapToVram(1);
        *ptr = 0xFF;
    }
}

u8 AddItemMessageWindow(u8 which)
{
    u8 *ptr = &gBagMenu->windowPointers[which];
    if (*ptr == 0xFF)
        *ptr = AddWindow(&sContextMenuWindowTemplates[which]);
    return *ptr;
}

void BagMenu_RemoveBagItemMessageindow(u8 which)
{
    u8 *ptr = &gBagMenu->windowPointers[which];
    if (*ptr != 0xFF)
    {
        ClearDialogWindowAndFrameToTransparent(*ptr, FALSE);
        // This ClearWindowTilemap call is redundant, since ClearDialogWindowAndFrameToTransparent already calls it.
        ClearWindowTilemap(*ptr);
        RemoveWindow(*ptr);
        ScheduleBgCopyTilemapToVram(1);
        *ptr = 0xFF;
    }
}

void BagMenu_YesNo(u8 a, u8 b, const struct YesNoFuncTable *funcTable)
{
    CreateYesNoMenuWithCallbacks(a, &sContextMenuWindowTemplates[b], 1, 0, 2, 1, 14, funcTable);
}

static void DisplayCurrentMoneyWindow(void)
{
    u8 windowId = BagMenu_AddWindow(9);
    PrintMoneyAmountInMoneyBoxWithBorder(windowId, 1, 14, GetMoney(&gSaveBlock1Ptr->money));
    AddMoneyLabelObject(19, 11);
}

static void RemoveMoneyWindow(void)
{
    BagMenu_RemoveWindow(9);
    RemoveMoneyLabelObject();
}

void BagMenu_PrepareTMHMMoveWindow(void)
{
    FillWindowPixelBuffer(3, PIXEL_FILL(0));
    BlitMenuInfoIcon(3, MENU_INFO_ICON_TYPE, 0, 0);
    BlitMenuInfoIcon(3, MENU_INFO_ICON_POWER, 0, 12);
    BlitMenuInfoIcon(3, MENU_INFO_ICON_ACCURACY, 0, 24);
    BlitMenuInfoIcon(3, MENU_INFO_ICON_PP, 0, 36);
    CopyWindowToVram(3, 2);
}

void PrintTMHMMoveData(u16 itemId)
{
    u8 i;
    u16 moveId;
    const u8* text;

    FillWindowPixelBuffer(4, PIXEL_FILL(0));
    if (itemId == ITEM_NONE)
    {
        for (i = 0; i < 4; i++)
            BagMenu_Print(4, 1, gText_ThreeDashes, 7, i * 12, 0, 0, -1, 4);
        CopyWindowToVram(4, 2);
    }
    else
    {
        moveId = ItemIdToBattleMoveId(itemId);
        BlitMenuInfoIcon(4, gBattleMoves[moveId].type + 1, 0, 0);
        if (gBattleMoves[moveId].power <= 1)
        {
            text = gText_ThreeDashes;
        }
        else
        {
            ConvertIntToDecimalStringN(gStringVar1, gBattleMoves[moveId].power, STR_CONV_MODE_RIGHT_ALIGN, 3);
            text = gStringVar1;
        }
        BagMenu_Print(4, 1, text, 7, 12, 0, 0, -1, 4);
        if (gBattleMoves[moveId].accuracy == 0)
        {
            text = gText_ThreeDashes;
        }
        else
        {
            ConvertIntToDecimalStringN(gStringVar1, gBattleMoves[moveId].accuracy, STR_CONV_MODE_RIGHT_ALIGN, 3);
            text = gStringVar1;
        }
        BagMenu_Print(4, 1, text, 7, 24, 0, 0, -1, 4);
        ConvertIntToDecimalStringN(gStringVar1, gBattleMoves[moveId].pp, STR_CONV_MODE_RIGHT_ALIGN, 3);
        BagMenu_Print(4, 1, gStringVar1, 7, 36, 0, 0, -1, 4);
        CopyWindowToVram(4, 2);
    }
}
