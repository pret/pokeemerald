#include "global.h"
#include "battle.h"
#include "battle_controllers.h"
#include "battle_pyramid_bag.h"
#include "bg.h"
#include "decompress.h"
#include "event_data.h"
#include "field_effect.h"
#include "field_weather.h"
#include "graphics.h"
#include "gpu_regs.h"
#include "international_string_util.h"
#include "item.h"
#include "item_icon.h"
#include "item_menu.h"
#include "item_use.h"
#include "list_menu.h"
#include "mail.h"
#include "main.h"
#include "malloc.h"
#include "menu.h"
#include "menu_helpers.h"
#include "overworld.h"
#include "palette.h"
#include "party_menu.h"
#include "task.h"
#include "text_window.h"
#include "scanline_effect.h"
#include "script.h"
#include "sound.h"
#include "string_util.h"
#include "strings.h"
#include "constants/items.h"
#include "constants/rgb.h"
#include "constants/songs.h"

EWRAM_DATA struct PyramidBagResources *gPyramidBagResources = NULL;
EWRAM_DATA struct PyramidBagCursorData gPyramidBagCursorData = {0};

// This file's functions.
static void Task_HandlePyramidBagInput(u8 taskId);
static void Task_ChooseItemsToTossFromPyramidBag(u8 taskId);
static void sub_81C5B4C(u8 taskId);
static void Task_BeginItemSwap(u8 taskId);
static void sub_81C5D20(u8 taskId);
static void sub_81C674C(u8 taskId);
static void HandleMenuActionInput(u8 taskId);
static void HandleFewMenuActionsInput(u8 taskId);
static void sub_81C66EC(u8 taskId);
static void SetTaskToMainPyramidBagInputHandler(u8 taskId);
static void sub_81C6350(u8 taskId);
static void sub_81C64B4(u8 taskId);
static void sub_81C65CC(u8 taskId);
static void sub_81C66AC(u8 taskId);
static void PerformItemSwap(u8 taskId);
static void Task_ItemSwapHandleInput(u8 taskId);
static void sub_81C6A14(u8 taskId);
static void SetBagItemsListTemplate(void);
static void sub_81C504C(void);
static void sub_81C51DC(void);
static void AddScrollArrow(void);
static void sub_81C56F8(void);
static void sub_81C5A20(void);
static void sub_81C6BD8(void);
static void sub_81C6EF4(void);
static void sub_81C700C(void);
static void sub_81C6E98(void);
static void sub_81C6F20(void);
static void sub_81C6404(void);
static void CloseBattlePyramidBagTextWindow(void);
static bool8 sub_81C5238(void);
static bool8 sub_81C5078(void);
static void ShowItemImage(u16 itemId, u8 itemSpriteArrayId);
static void PyramidBag_CopyItemName(u8 *dst, u16 itemId);
static void sub_81C6FF8(u8 arg0);
static void PrintItemDescription(s32 listMenuId);
static void sub_81C5AB8(u8 y, u8 arg1);
static void PrintOnWindow_Font1(u8 windowId, const u8 *src, u8 x, u8 y, u8 letterSpacing, u8 lineSpacing, u8 speed, u8 colorTableId);
static void PrintOnWindow_Font7(u8 windowId, const u8 *src, u8 x, u8 y, u8 letterSpacing, u8 lineSpacing, u8 speed, u8 colorTableId);
static u8 sub_81C6D24(u8 windowArrayId);
static void sub_81C6D6C(u8 windowArrayId);
static void sub_81C5EAC(u8 windowId);
static void sub_81C5F08(u8 windowId, u8 horizontalCount, u8 verticalCount);
static bool8 IsValidMenuAction(s8 arg0);
static void sub_81C6DAC(u8 taskId, const struct YesNoFuncTable *yesNoTable);
static void sub_81C6CEC(u8 windowId);
static void sub_81C704C(u8 y);
static void sub_81C7028(bool8 invisible);
static void sub_81C6F68(struct Sprite *sprite);
static void BagAction_UseOnField(u8 taskId);
static void BagAction_Toss(u8 taskId);
static void BagAction_Give(u8 taskId);
static void BagAction_Cancel(u8 taskId);
static void BagAction_UseInBattle(u8 taskId);
static void PyramidBagMoveCursorFunc(s32 itemIndex, bool8 onInit, struct ListMenu *list);
static void PrintItemQuantity(u8 windowId, s32 itemIndex, u8 y);
static void TossItem(u8 taskId);
static void DontTossItem(u8 taskId);

// Const rom data.
static const struct BgTemplate gUnknown_0861F2B4[] =
{
    {
        .bg = 0,
        .charBaseIndex = 0,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0
    },
    {
        .bg = 1,
        .charBaseIndex = 0,
        .mapBaseIndex = 30,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0
    },
    {
        .bg = 2,
        .charBaseIndex = 3,
        .mapBaseIndex = 29,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 0
    },
};

static const struct ListMenuTemplate gUnknown_0861F2C0 =
{
    .items = NULL,
    .moveCursorFunc = PyramidBagMoveCursorFunc,
    .itemPrintFunc = PrintItemQuantity,
    .totalItems = 0,
    .maxShowed = 0,
    .windowId = 0,
    .header_X = 0,
    .item_X = 8,
    .cursor_X = 0,
    .upText_Y = 1,
    .cursorPal = 2,
    .fillValue = 0,
    .cursorShadowPal = 3,
    .lettersSpacing = 0,
    .itemVerticalPadding = 0,
    .scrollMultiple = LIST_NO_MULTIPLE_SCROLL,
    .fontId = 7,
    .cursorKind = 0
};

#define ACTION_USE_FIELD 0
#define ACTION_TOSS 1
#define ACTION_GIVE 2
#define ACTION_CANCEL 3
#define ACTION_USE_BATTLE 4
#define ACTION_DUMMY 5

static const struct MenuAction sMenuActions[] =
{
    [ACTION_USE_FIELD] =    { gMenuText_Use, BagAction_UseOnField },
    [ACTION_TOSS] =         { gMenuText_Toss, BagAction_Toss },
    [ACTION_GIVE] =         { gMenuText_Give, BagAction_Give },
    [ACTION_CANCEL] =       { gText_Cancel2, BagAction_Cancel },
    [ACTION_USE_BATTLE] =   { gMenuText_Use, BagAction_UseInBattle },
    [ACTION_DUMMY] =        { gText_EmptyString2, NULL },
};

static const u8 sFieldMenuActionIds[] = {ACTION_USE_FIELD, ACTION_GIVE, ACTION_TOSS, ACTION_CANCEL};
static const u8 gUnknown_0861F30C[] = {ACTION_TOSS, ACTION_CANCEL};
static const u8 sBattleMenuActionIds[] = {ACTION_USE_BATTLE, ACTION_CANCEL};
static const u8 gUnknown_0861F310[] = {ACTION_CANCEL};

static const struct YesNoFuncTable sYesNoTossFuncions =
{
    TossItem, DontTossItem
};

static const u8 sColorTable[][3] =
{
    {0, 2, 3},
    {0, 3, 1},
    {1, 2, 3},
};

static const struct WindowTemplate gUnknown_0861F328[] =
{
    {
        .bg = 0,
        .tilemapLeft = 14,
        .tilemapTop = 2,
        .width = 15,
        .height = 16,
        .paletteNum = 15,
        .baseBlock = 30
    },
    {
        .bg = 0,
        .tilemapLeft = 0,
        .tilemapTop = 13,
        .width = 14,
        .height = 6,
        .paletteNum = 15,
        .baseBlock = 270
    },
    {
        .bg = 1,
        .tilemapLeft = 2,
        .tilemapTop = 15,
        .width = 27,
        .height = 4,
        .paletteNum = 15,
        .baseBlock = 354
    },
    {
        .bg = 1,
        .tilemapLeft = 24,
        .tilemapTop = 17,
        .width = 5,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 462
    },
    DUMMY_WIN_TEMPLATE,
};

static const struct WindowTemplate gUnknown_0861F350[] =
{
    {
        .bg = 1,
        .tilemapLeft = 22,
        .tilemapTop = 17,
        .width = 7,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 472
    },
    {
        .bg = 1,
        .tilemapLeft = 22,
        .tilemapTop = 15,
        .width = 7,
        .height = 4,
        .paletteNum = 15,
        .baseBlock = 472
    },
    {
        .bg = 1,
        .tilemapLeft = 15,
        .tilemapTop = 15,
        .width = 14,
        .height = 4,
        .paletteNum = 15,
        .baseBlock = 472
    },
    {
        .bg = 1,
        .tilemapLeft = 15,
        .tilemapTop = 13,
        .width = 14,
        .height = 6,
        .paletteNum = 15,
        .baseBlock = 472
    },
    {
        .bg = 1,
        .tilemapLeft = 24,
        .tilemapTop = 15,
        .width = 5,
        .height = 4,
        .paletteNum = 15,
        .baseBlock = 472
    },
};

static const struct OamData gOamData_861F378 =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_NORMAL,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = 0,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(64x64),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(64x64),
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0,
};

static const union AnimCmd gSpriteAnim_861F380[] =
{
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_END,
};

static const union AnimCmd * const gSpriteAnimTable_861F388[] =
{
    gSpriteAnim_861F380,
};

static const union AffineAnimCmd gSpriteAffineAnim_861F38C[] =
{
    AFFINEANIMCMD_FRAME(256, 256, 0, 0),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd gSpriteAffineAnim_861F39C[] =
{
    AFFINEANIMCMD_FRAME(0, 0, 254, 2),
    AFFINEANIMCMD_FRAME(0, 0, 2, 4),
    AFFINEANIMCMD_FRAME(0, 0, 254, 4),
    AFFINEANIMCMD_FRAME(0, 0, 2, 2),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd * const gSpriteAffineAnimTable_861F3C4[] =
{
    gSpriteAffineAnim_861F38C,
    gSpriteAffineAnim_861F39C,
};

static const struct CompressedSpriteSheet gPyramidBagSpriteSheet = {gBattleFrontierGfx_PyramidBag, 0x0800, 0x1024};

static const struct SpriteTemplate gUnknown_0861F3D4 =
{
    .tileTag = 0x1024,
    .paletteTag = 0x1024,
    .oam = &gOamData_861F378,
    .anims = gSpriteAnimTable_861F388,
    .images = NULL,
    .affineAnims = gSpriteAffineAnimTable_861F3C4,
    .callback = SpriteCallbackDummy
};

// code
void InitBattlePyramidBagCursorPosition(void)
{
    gPyramidBagCursorData.cursorPosition = 0;
    gPyramidBagCursorData.scrollPosition = 0;
}

void CB2_PyramidBagMenuFromStartMenu(void)
{
    GoToBattlePyramidBagMenu(0, CB2_ReturnToFieldWithOpenMenu);
}

static void sub_81C4F10(void)
{
    GoToBattlePyramidBagMenu(1, CB2_SetUpReshowBattleScreenAfterMenu2);
}

void ChooseItemsToTossFromPyramidBag(void)
{
    ScriptContext2_Enable();
    FadeScreen(FADE_TO_BLACK, 0);
    CreateTask(Task_ChooseItemsToTossFromPyramidBag, 10);
}

static void Task_ChooseItemsToTossFromPyramidBag(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        CleanupOverworldWindowsAndTilemaps();
        gFieldCallback2 = CB2_FadeFromPartyMenu;
        GoToBattlePyramidBagMenu(3, CB2_ReturnToField);
        DestroyTask(taskId);
    }
}

void CB2_ReturnToPyramidBagMenu(void)
{
    GoToBattlePyramidBagMenu(4, gPyramidBagCursorData.callback);
}

void GoToBattlePyramidBagMenu(u8 a0, void (*callback)(void))
{
    gPyramidBagResources = AllocZeroed(sizeof(*gPyramidBagResources));

    if (a0 != 4)
        gPyramidBagCursorData.unk4 = a0;

    if (callback != NULL)
        gPyramidBagCursorData.callback = callback;

    gPyramidBagResources->callback2 = NULL;
    gPyramidBagResources->unk814 = 0xFF;
    gPyramidBagResources->scrollIndicatorsTaskId = 0xFF;

    memset(gPyramidBagResources->itemsSpriteIds, 0xFF, sizeof(gPyramidBagResources->itemsSpriteIds));
    memset(gPyramidBagResources->windowIds, 0xFF, sizeof(gPyramidBagResources->windowIds));

    SetMainCallback2(sub_81C504C);
}

static void sub_81C501C(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    DoScheduledBgTilemapCopiesToVram();
    UpdatePaletteFade();
}

static void sub_81C5038(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static void sub_81C504C(void)
{
    while (MenuHelpers_CallLinkSomething() != TRUE && sub_81C5078() != TRUE && MenuHelpers_LinkSomething() != TRUE);
}

static bool8 sub_81C5078(void)
{
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
            if (!MenuHelpers_LinkSomething())
            {
                ResetTasks();
            }
            gMain.state++;
            break;
        case 6:
            sub_81C51DC();
            gPyramidBagResources->state = 0;
            gMain.state++;
            break;
        case 7:
            if (sub_81C5238())
            {
                gMain.state++;
            }
            break;
        case 8:
            sub_81C6BD8();
            gMain.state++;
            break;
        case 9:
            sub_81C5924();
            sub_81C59BC();
            sub_81C5A20();
            gMain.state++;
            break;
        case 10:
            SetBagItemsListTemplate();
            gMain.state++;
            break;
        case 11:
            sub_81C56F8();
            gMain.state++;
            break;
        case 12:
            sub_81C6EF4();
            gMain.state++;
            break;
        case 13:
            AddScrollArrow();
            gMain.state++;
            break;
        case 14:
            sub_81C700C();
            gMain.state++;
            break;
        case 15:
            BlendPalettes(0xFFFFFFFF, 0x10, 0);
            gMain.state++;
            break;
        case 16:
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 0x10, 0, RGB_BLACK);
            gPaletteFade.bufferTransferDisabled = FALSE;
            gMain.state++;
            break;
        default:
            SetVBlankCallback(sub_81C5038);
            SetMainCallback2(sub_81C501C);
            return TRUE;
    }
    return FALSE;
}

static void sub_81C51DC(void)
{
    ResetVramOamAndBgCntRegs();
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, gUnknown_0861F2B4, ARRAY_COUNT(gUnknown_0861F2B4));
    SetBgTilemapBuffer(2, gPyramidBagResources->tilemapBuffer);
    ResetAllBgsCoordinates();
    ScheduleBgCopyTilemapToVram(2);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0 |
                                  DISPCNT_OBJ_1D_MAP |
                                  DISPCNT_OBJ_ON);
    ShowBg(0);
    ShowBg(1);
    ShowBg(2);
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
}

static bool8 sub_81C5238(void)
{
    switch (gPyramidBagResources->state)
    {
    case 0:
        ResetTempTileDataBuffers();
        DecompressAndCopyTileDataToVram(2, gBagScreen_Gfx, 0, 0, 0);
        gPyramidBagResources->state++;
        break;
    case 1:
        if (FreeTempTileDataBuffersIfPossible() != TRUE)
        {
            LZDecompressWram(gBattleFrontierGfx_PyramidBagTileMap, gPyramidBagResources->tilemapBuffer);
            gPyramidBagResources->state++;
        }
        break;
    case 2:
        LoadCompressedPalette(gUnknown_08D9AF44, 0, 0x20);
        gPyramidBagResources->state++;
        break;
    case 3:
        LoadCompressedSpriteSheet(&gPyramidBagSpriteSheet);
        gPyramidBagResources->state++;
        break;
    case 4:
        sub_81C6E98();
        gPyramidBagResources->state++;
        break;
    default:
        LoadListMenuArrowsGfx();
        gPyramidBagResources->state = 0;
        return TRUE;
    }

    return FALSE;
}

static void SetBagItemsListTemplate(void)
{
    u16 i;
    u16 *pyramidItems = gSaveBlock2Ptr->frontier.pyramidBag.itemId[gSaveBlock2Ptr->frontier.lvlMode];

    for (i = 0; i < gPyramidBagResources->listMenuCount - 1; i++)
    {
        PyramidBag_CopyItemName(gPyramidBagResources->itemStrings[i], pyramidItems[i]);
        gPyramidBagResources->bagListItems[i].name = gPyramidBagResources->itemStrings[i];
        gPyramidBagResources->bagListItems[i].id = i;
    }
    StringCopy(gPyramidBagResources->itemStrings[i], gText_CloseBag);
    gPyramidBagResources->bagListItems[i].name = gPyramidBagResources->itemStrings[i];
    gPyramidBagResources->bagListItems[i].id = LIST_CANCEL;
    gMultiuseListMenuTemplate = gUnknown_0861F2C0;
    gMultiuseListMenuTemplate.totalItems = gPyramidBagResources->listMenuCount;
    gMultiuseListMenuTemplate.items = gPyramidBagResources->bagListItems;
    gMultiuseListMenuTemplate.maxShowed = gPyramidBagResources->listMenuMaxShown;
}

static void PyramidBag_CopyItemName(u8 *dst, u16 itemId)
{
    if (ItemId_GetPocket(itemId) == POCKET_BERRIES)
    {
        ConvertIntToDecimalStringN(gStringVar1, ITEM_TO_BERRY(itemId), STR_CONV_MODE_LEADING_ZEROS, 2);
        CopyItemName(itemId, gStringVar2);
        StringExpandPlaceholders(dst, gText_NumberVar1Clear7Var2);
    }
    else
    {
        CopyItemName(itemId, dst);
    }
}

static void PyramidBagMoveCursorFunc(s32 itemIndex, bool8 onInit, struct ListMenu *list)
{
    if (onInit != TRUE)
    {
        PlaySE(SE_SELECT);
        sub_81C6F20();
    }
    if (gPyramidBagResources->unk814 == 0xFF)
    {
        sub_81C6FF8(gPyramidBagResources->unk815 ^ 1);
        if (itemIndex != LIST_CANCEL)
            ShowItemImage(gSaveBlock2Ptr->frontier.pyramidBag.itemId[gSaveBlock2Ptr->frontier.lvlMode][itemIndex], gPyramidBagResources->unk815);
        else
            ShowItemImage(0xFFFF, gPyramidBagResources->unk815);
        gPyramidBagResources->unk815 ^= 1;
        PrintItemDescription(itemIndex);
    }
}

static void PrintItemQuantity(u8 windowId, s32 itemIndex, u8 y)
{
    s32 xAlign;
    if (itemIndex == LIST_CANCEL)
        return;

    if (gPyramidBagResources->unk814 != 0xFF)
    {
        if (gPyramidBagResources->unk814 == (u8)(itemIndex))
            sub_81C5AB8(y, 1);
        else
            sub_81C5AB8(y, 0xFF);
    }
    ConvertIntToDecimalStringN(gStringVar1,
                               gSaveBlock2Ptr->frontier.pyramidBag.quantity[gSaveBlock2Ptr->frontier.lvlMode][itemIndex],
                               STR_CONV_MODE_RIGHT_ALIGN,
                               2);
    StringExpandPlaceholders(gStringVar4, gText_xVar1);
    xAlign = GetStringRightAlignXOffset(7, gStringVar4, 0x77);
    PrintOnWindow_Font7(windowId, gStringVar4, xAlign, y, 0, 0, TEXT_SPEED_FF, 0);
}

static void PrintItemDescription(s32 listMenuId)
{
    const u8 *desc;
    if (listMenuId != LIST_CANCEL)
    {
        desc = ItemId_GetDescription(gSaveBlock2Ptr->frontier.pyramidBag.itemId[gSaveBlock2Ptr->frontier.lvlMode][listMenuId]);
    }
    else
    {
        StringCopy(gStringVar1, gReturnToXStringsTable2[gPyramidBagCursorData.unk4]);
        StringExpandPlaceholders(gStringVar4, gText_ReturnToVar1);
        desc = gStringVar4;
    }
    FillWindowPixelBuffer(1, PIXEL_FILL(0));
    PrintOnWindow_Font1(1, desc, 3, 0, 0, 1, 0, 0);
}

static void AddScrollArrow(void)
{
    if (gPyramidBagResources->scrollIndicatorsTaskId == 0xFF)
        gPyramidBagResources->scrollIndicatorsTaskId = AddScrollIndicatorArrowPairParameterized(2, 172, 12, 148, gPyramidBagResources->listMenuCount - gPyramidBagResources->listMenuMaxShown, 0xB5E, 0xB5E, &gPyramidBagCursorData.scrollPosition);
}

static void RemoveScrollArrow(void)
{
    if (gPyramidBagResources->scrollIndicatorsTaskId != 0xFF)
    {
        RemoveScrollIndicatorArrowPair(gPyramidBagResources->scrollIndicatorsTaskId);
        gPyramidBagResources->scrollIndicatorsTaskId = 0xFF;
    }
}

static void sub_81C56F8(void)
{
    u8 taskId = CreateTask(Task_HandlePyramidBagInput, 0);
    s16 *data = gTasks[taskId].data;
    data[0] = ListMenuInit(&gMultiuseListMenuTemplate, gPyramidBagCursorData.scrollPosition, gPyramidBagCursorData.cursorPosition);
}

static void SwapItems(u8 id1, u8 id2)
{
    u16 temp;
    u16 *itemIds = gSaveBlock2Ptr->frontier.pyramidBag.itemId[gSaveBlock2Ptr->frontier.lvlMode];
    u8 *quantities = gSaveBlock2Ptr->frontier.pyramidBag.quantity[gSaveBlock2Ptr->frontier.lvlMode];

    SWAP(itemIds[id1], itemIds[id2], temp);
    SWAP(quantities[id1], quantities[id2], temp);
}

static void MovePyramidBagItemSlotInList(u8 from, u8 to)
{
    u16 *itemIds = gSaveBlock2Ptr->frontier.pyramidBag.itemId[gSaveBlock2Ptr->frontier.lvlMode];
    u8 *quantities = gSaveBlock2Ptr->frontier.pyramidBag.quantity[gSaveBlock2Ptr->frontier.lvlMode];

    if (from != to)
    {
        s16 i;
        u16 firstSlotItemId = itemIds[from];
        u8 firstSlotQuantity = quantities[from];

        if (to > from)
        {
            to--;
            for (i = from; i < to; i++)
            {
                itemIds[i] = itemIds[i + 1];
                quantities[i] = quantities[i + 1];
            }
        }
        else
        {
            for (i = from; i > to; i--)
            {
                itemIds[i] = itemIds[i - 1];
                quantities[i] = quantities[i - 1];
            }
        }
        itemIds[to] = firstSlotItemId;
        quantities[to] = firstSlotQuantity;
    }
}

static void CompactItems(void)
{
    u8 i, j;
    u16 *itemIds = gSaveBlock2Ptr->frontier.pyramidBag.itemId[gSaveBlock2Ptr->frontier.lvlMode];
    u8 *quantities = gSaveBlock2Ptr->frontier.pyramidBag.quantity[gSaveBlock2Ptr->frontier.lvlMode];

    for (i = 0; i < PYRAMID_BAG_ITEMS_COUNT; i++)
    {
        if (itemIds[i] == 0 || quantities[i] == 0)
        {
            itemIds[i] = 0;
            quantities[i] = 0;
        }
    }
    for (i = 0; i < PYRAMID_BAG_ITEMS_COUNT - 1; i++)
    {
        for (j = i + 1; j < PYRAMID_BAG_ITEMS_COUNT; j++)
        {
            if (itemIds[i] == 0 || quantities[i] == 0)
                SwapItems(i, j);
        }
    }
}

void sub_81C5924(void)
{
    u16 i;
    u16 *itemIds = gSaveBlock2Ptr->frontier.pyramidBag.itemId[gSaveBlock2Ptr->frontier.lvlMode];

    CompactItems();
    gPyramidBagResources->listMenuCount = 0;
    for (i = 0; i < PYRAMID_BAG_ITEMS_COUNT; i++)
    {
        if (itemIds[i] != 0)
            gPyramidBagResources->listMenuCount++;
    }
    gPyramidBagResources->listMenuCount++;
    if (gPyramidBagResources->listMenuCount > 8)
        gPyramidBagResources->listMenuMaxShown = 8;
    else
        gPyramidBagResources->listMenuMaxShown = gPyramidBagResources->listMenuCount;
}

void sub_81C59BC(void)
{
    if (gPyramidBagCursorData.scrollPosition != 0 && gPyramidBagCursorData.scrollPosition + gPyramidBagResources->listMenuMaxShown > gPyramidBagResources->listMenuCount)
        gPyramidBagCursorData.scrollPosition = gPyramidBagResources->listMenuCount - gPyramidBagResources->listMenuMaxShown;
    if (gPyramidBagCursorData.scrollPosition + gPyramidBagCursorData.cursorPosition >= gPyramidBagResources->listMenuCount)
    {
        if (gPyramidBagResources->listMenuCount == 0)
            gPyramidBagCursorData.cursorPosition = 0;
        else
            gPyramidBagCursorData.cursorPosition = gPyramidBagResources->listMenuCount - 1;
    }
}

static void sub_81C5A20(void)
{
    u8 i;

    if (gPyramidBagCursorData.cursorPosition > 4)
    {
        for (i = 0; i <= gPyramidBagCursorData.cursorPosition - 4; i++)
        {
            if (gPyramidBagCursorData.scrollPosition + gPyramidBagResources->listMenuMaxShown == gPyramidBagResources->listMenuCount)
            {
                // daycare.c sends its regards.
                break;
            }
            gPyramidBagCursorData.cursorPosition--;
            gPyramidBagCursorData.scrollPosition++;
        }
    }
}

static void sub_81C5A98(u8 listMenuTaskId, u8 arg1)
{
    u8 y = ListMenuGetYCoordForPrintingArrowCursor(listMenuTaskId);
    sub_81C5AB8(y, arg1);
}

static void sub_81C5AB8(u8 y, u8 arg1)
{
    if (arg1 == 0xFF)
        FillWindowPixelRect(0, PIXEL_FILL(0), 0, y, GetMenuCursorDimensionByFont(1, 0), GetMenuCursorDimensionByFont(1, 1));
    else
        PrintOnWindow_Font1(0, gText_SelectorArrow2, 0, y, 0, 0, 0, arg1);
}

void CloseBattlePyramidBagAndSetCallback(u8 taskId)
{
    BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 0x10, RGB_BLACK);
    gTasks[taskId].func = sub_81C5B4C;
}

static void sub_81C5B4C(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    if (!gPaletteFade.active)
    {
        DestroyListMenuTask(data[0], &gPyramidBagCursorData.scrollPosition, &gPyramidBagCursorData.cursorPosition);
        if (gPyramidBagResources->callback2 != NULL)
            SetMainCallback2(gPyramidBagResources->callback2);
        else
            SetMainCallback2(gPyramidBagCursorData.callback);
        RemoveScrollArrow();
        ResetSpriteData();
        FreeAllSpritePalettes();
        FreeAllWindowBuffers();
        Free(gPyramidBagResources);
        DestroyTask(taskId);
    }
}

static void Task_HandlePyramidBagInput(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    if (MenuHelpers_CallLinkSomething() != TRUE && !gPaletteFade.active)
    {
        if (JOY_NEW(SELECT_BUTTON))
        {
            if (gPyramidBagCursorData.unk4 != 2)
            {
                ListMenuGetScrollAndRow(data[0], &gPyramidBagCursorData.scrollPosition, &gPyramidBagCursorData.cursorPosition);
                if (gPyramidBagCursorData.scrollPosition + gPyramidBagCursorData.cursorPosition != gPyramidBagResources->listMenuCount - 1)
                {
                    PlaySE(SE_SELECT);
                    Task_BeginItemSwap(taskId);
                }
            }
        }
        else
        {
            s32 listId = ListMenu_ProcessInput(data[0]);
            ListMenuGetScrollAndRow(data[0], &gPyramidBagCursorData.scrollPosition, &gPyramidBagCursorData.cursorPosition);
            switch (listId)
            {
            case LIST_NOTHING_CHOSEN:
                break;
            case LIST_CANCEL:
                PlaySE(SE_SELECT);
                gSpecialVar_ItemId = 0;
                CloseBattlePyramidBagAndSetCallback(taskId);
                break;
            default:
                PlaySE(SE_SELECT);
                gSpecialVar_ItemId = gSaveBlock2Ptr->frontier.pyramidBag.itemId[gSaveBlock2Ptr->frontier.lvlMode][listId];
                data[1] = listId;
                data[2] = gSaveBlock2Ptr->frontier.pyramidBag.quantity[gSaveBlock2Ptr->frontier.lvlMode][listId];
                if (gPyramidBagCursorData.unk4 == 2)
                    sub_81C674C(taskId);
                else
                    sub_81C5D20(taskId);
                break;
            }
        }
    }
}

static void sub_81C5D20(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    RemoveScrollArrow();
    sub_81C5A98(data[0], 1);
    switch (gPyramidBagCursorData.unk4)
    {
    default:
        gPyramidBagResources->menuActionIds = sFieldMenuActionIds;
        gPyramidBagResources->menuActionsCount = ARRAY_COUNT(sFieldMenuActionIds);
        break;
    case 1:
        if (ItemId_GetBattleUsage(gSpecialVar_ItemId))
        {
            gPyramidBagResources->menuActionIds = sBattleMenuActionIds;
            gPyramidBagResources->menuActionsCount = ARRAY_COUNT(sBattleMenuActionIds);
        }
        else
        {
            gPyramidBagResources->menuActionIds = gUnknown_0861F310;
            gPyramidBagResources->menuActionsCount = ARRAY_COUNT(gUnknown_0861F310);
        }
        break;
    case 3:
        gPyramidBagResources->menuActionIds = gUnknown_0861F30C;
        gPyramidBagResources->menuActionsCount = ARRAY_COUNT(gUnknown_0861F30C);
        break;
    }

    CopyItemName(gSpecialVar_ItemId, gStringVar1);
    StringExpandPlaceholders(gStringVar4, gText_Var1IsSelected);
    FillWindowPixelBuffer(1, PIXEL_FILL(0));
    PrintOnWindow_Font1(1, gStringVar4, 3, 0, 0, 1, 0, 0);
    if (gPyramidBagResources->menuActionsCount == 1)
        sub_81C5EAC(sub_81C6D24(0));
    else if (gPyramidBagResources->menuActionsCount == 2)
        sub_81C5EAC(sub_81C6D24(1));
    else
        sub_81C5F08(sub_81C6D24(2), 2, 2);

    if (gPyramidBagResources->menuActionsCount == 4)
        gTasks[taskId].func = HandleMenuActionInput;
    else
        gTasks[taskId].func = HandleFewMenuActionsInput;
}

static void sub_81C5EAC(u8 windowId)
{
    AddItemMenuActionTextPrinters(windowId, 7, 8, 1, 0, 0x10, gPyramidBagResources->menuActionsCount, sMenuActions, gPyramidBagResources->menuActionIds);
    InitMenuInUpperLeftCornerPlaySoundWhenAPressed(windowId, gPyramidBagResources->menuActionsCount, 0);
}

static void sub_81C5F08(u8 windowId, u8 horizontalCount, u8 verticalCount)
{
    sub_8198DBC(windowId, 7, 8, 1, 0x38, horizontalCount, verticalCount, sMenuActions, gPyramidBagResources->menuActionIds);
    sub_8199944(windowId, 0x38, horizontalCount, verticalCount, 0);
}

static void HandleFewMenuActionsInput(u8 taskId)
{
    if (MenuHelpers_CallLinkSomething() != TRUE)
    {
        s32 id = Menu_ProcessInputNoWrap();
        switch (id)
        {
        case MENU_NOTHING_CHOSEN:
            break;
        case MENU_B_PRESSED:
            PlaySE(SE_SELECT);
            sMenuActions[ACTION_CANCEL].func.void_u8(taskId);
            break;
        default:
            PlaySE(SE_SELECT);
            if (sMenuActions[gPyramidBagResources->menuActionIds[id]].func.void_u8 != NULL)
                sMenuActions[gPyramidBagResources->menuActionIds[id]].func.void_u8(taskId);
            break;
        }
    }
}

static void HandleMenuActionInput(u8 taskId)
{
    if (MenuHelpers_CallLinkSomething() != TRUE)
    {
        s8 id = Menu_GetCursorPos();
        if (JOY_NEW(DPAD_UP))
        {
            if (id > 0 && IsValidMenuAction(id - 2))
            {
                PlaySE(SE_SELECT);
                ChangeListMenuCursorPosition(MENU_CURSOR_DELTA_NONE, MENU_CURSOR_DELTA_UP);
            }
        }
        else if (JOY_NEW(DPAD_DOWN))
        {
            if (id < gPyramidBagResources->menuActionsCount - 2 && IsValidMenuAction(id + 2))
            {
                PlaySE(SE_SELECT);
                ChangeListMenuCursorPosition(MENU_CURSOR_DELTA_NONE, MENU_CURSOR_DELTA_DOWN);
            }
        }
        else if (JOY_NEW(DPAD_LEFT) || GetLRKeysPressed() == MENU_L_PRESSED)
        {
            if (id & 1 && IsValidMenuAction(id - 1))
            {
                PlaySE(SE_SELECT);
                ChangeListMenuCursorPosition(MENU_CURSOR_DELTA_LEFT, MENU_CURSOR_DELTA_NONE);
            }
        }
        else if (JOY_NEW(DPAD_RIGHT) || GetLRKeysPressed() == MENU_R_PRESSED)
        {
            if (!(id & 1) && IsValidMenuAction(id + 1))
            {
                PlaySE(SE_SELECT);
                ChangeListMenuCursorPosition(MENU_CURSOR_DELTA_RIGHT, MENU_CURSOR_DELTA_NONE);
            }
        }
        else if (JOY_NEW(A_BUTTON))
        {
            PlaySE(SE_SELECT);
            if (sMenuActions[gPyramidBagResources->menuActionIds[id]].func.void_u8 != NULL)
                sMenuActions[gPyramidBagResources->menuActionIds[id]].func.void_u8(taskId);
        }
        else if (JOY_NEW(B_BUTTON))
        {
            PlaySE(SE_SELECT);
            sMenuActions[ACTION_CANCEL].func.void_u8(taskId);
        }
    }
}

static bool8 IsValidMenuAction(s8 actionTableId)
{
    if (actionTableId < 0)
        return FALSE;
    else if (actionTableId > gPyramidBagResources->menuActionsCount)
        return FALSE;
    else if (gPyramidBagResources->menuActionIds[actionTableId] == ACTION_DUMMY)
        return FALSE;
    else
        return TRUE;
}

static void sub_81C61A8(void)
{
    if (gPyramidBagResources->menuActionsCount == 1)
        sub_81C6D6C(0);
    else if (gPyramidBagResources->menuActionsCount == 2)
        sub_81C6D6C(1);
    else
        sub_81C6D6C(2);
}

static void BagAction_UseOnField(u8 taskId)
{
    u8 pocketId = ItemId_GetPocket(gSpecialVar_ItemId);

    if (pocketId == POCKET_KEY_ITEMS
        || pocketId == POCKET_POKE_BALLS
        || pocketId == POCKET_TM_HM
        || ItemIsMail(gSpecialVar_ItemId) == TRUE)
    {
        sub_81C61A8();
        DisplayItemMessageInBattlePyramid(taskId, gText_DadsAdvice, Task_CloseBattlePyramidBagMessage);
    }
    else if (ItemId_GetFieldFunc(gSpecialVar_ItemId) != NULL)
    {
        sub_81C61A8();
        FillWindowPixelBuffer(1, PIXEL_FILL(0));
        ScheduleBgCopyTilemapToVram(0);
        ItemId_GetFieldFunc(gSpecialVar_ItemId)(taskId);
    }
}

static void BagAction_Cancel(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    sub_81C61A8();
    PrintItemDescription(data[1]);
    ScheduleBgCopyTilemapToVram(0);
    ScheduleBgCopyTilemapToVram(1);
    sub_81C5A98(data[0], 0);
    SetTaskToMainPyramidBagInputHandler(taskId);
}

static void SetTaskToMainPyramidBagInputHandler(u8 taskId)
{
    AddScrollArrow();
    gTasks[taskId].func = Task_HandlePyramidBagInput;
}

static void BagAction_Toss(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    sub_81C61A8();
    data[8] = 1;
    if (data[2] == 1)
    {
        sub_81C6350(taskId);
    }
    else
    {
        CopyItemName(gSpecialVar_ItemId, gStringVar1);
        StringExpandPlaceholders(gStringVar4, gText_TossHowManyVar1s);
        FillWindowPixelBuffer(1, PIXEL_FILL(0));
        PrintOnWindow_Font1(1, gStringVar4, 3, 0, 0, 1, 0, 0);
        sub_81C6404();
        gTasks[taskId].func = sub_81C64B4;
    }
}

static void sub_81C6350(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    CopyItemName(gSpecialVar_ItemId, gStringVar1);
    ConvertIntToDecimalStringN(gStringVar2, data[8], STR_CONV_MODE_LEFT_ALIGN, 2);
    StringExpandPlaceholders(gStringVar4, gText_ConfirmTossItems);
    FillWindowPixelBuffer(1, PIXEL_FILL(0));
    PrintOnWindow_Font1(1, gStringVar4, 3, 0, 0, 1, 0, 0);
    sub_81C6DAC(taskId, &sYesNoTossFuncions);
}

static void DontTossItem(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    PrintItemDescription(data[1]);
    sub_81C5A98(data[0], 0);
    SetTaskToMainPyramidBagInputHandler(taskId);
}

static void sub_81C6404(void)
{
    s32 x;

    ConvertIntToDecimalStringN(gStringVar1, 1, STR_CONV_MODE_LEADING_ZEROS, 2);
    StringExpandPlaceholders(gStringVar4, gText_xVar1);
    sub_81C6CEC(3);
    x = GetStringCenterAlignXOffset(1, gStringVar4, 0x28);
    AddTextPrinterParameterized(3, 1, gStringVar4, x, 2, 0, NULL);
}

static void sub_81C645C(s16 value)
{
    s32 x;

    ConvertIntToDecimalStringN(gStringVar1, value, STR_CONV_MODE_LEADING_ZEROS, 2);
    StringExpandPlaceholders(gStringVar4, gText_xVar1);
    x = GetStringCenterAlignXOffset(1, gStringVar4, 0x28);
    AddTextPrinterParameterized(3, 1, gStringVar4, x, 2, 0, NULL);
}

static void sub_81C64B4(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    if (AdjustQuantityAccordingToDPadInput(&data[8], data[2]) == TRUE)
    {
        sub_81C645C(data[8]);
    }
    else if (JOY_NEW(A_BUTTON))
    {
        PlaySE(SE_SELECT);
        ClearStdWindowAndFrameToTransparent(3, 0);
        ClearWindowTilemap(3);
        ScheduleBgCopyTilemapToVram(1);
        sub_81C6350(taskId);
    }
    else if (JOY_NEW(B_BUTTON))
    {
        PlaySE(SE_SELECT);
        ClearStdWindowAndFrameToTransparent(3, 0);
        ClearWindowTilemap(3);
        ScheduleBgCopyTilemapToVram(1);
        DontTossItem(taskId);
    }
}

static void TossItem(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    CopyItemName(gSpecialVar_ItemId, gStringVar1);
    ConvertIntToDecimalStringN(gStringVar2, data[8], STR_CONV_MODE_LEFT_ALIGN, 2);
    StringExpandPlaceholders(gStringVar4, gText_ThrewAwayVar2Var1s);
    FillWindowPixelBuffer(1, PIXEL_FILL(0));
    PrintOnWindow_Font1(1, gStringVar4, 3, 0, 0, 1, 0, 0);
    gTasks[taskId].func = sub_81C65CC;
}

static void sub_81C65CC(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    u16 *scrollOffset = &gPyramidBagCursorData.scrollPosition;
    u16 *selectedRow = &gPyramidBagCursorData.cursorPosition;

    if (JOY_NEW(A_BUTTON | B_BUTTON))
    {
        PlaySE(SE_SELECT);
        RemovePyramidBagItem(gSpecialVar_ItemId, data[8]);
        DestroyListMenuTask(data[0], scrollOffset, selectedRow);
        sub_81C5924();
        sub_81C59BC();
        SetBagItemsListTemplate();
        data[0] = ListMenuInit(&gMultiuseListMenuTemplate, *scrollOffset, *selectedRow);
        ScheduleBgCopyTilemapToVram(0);
        SetTaskToMainPyramidBagInputHandler(taskId);
    }
}

static void BagAction_Give(u8 taskId)
{
    sub_81C61A8();
    if (ItemIsMail(gSpecialVar_ItemId) == TRUE)
    {
        DisplayItemMessageInBattlePyramid(taskId, gText_CantWriteMail, sub_81C66EC);
    }
    else if (!ItemId_GetImportance(gSpecialVar_ItemId))
    {
        gPyramidBagResources->callback2 = CB2_ChooseMonToGiveItem;
        CloseBattlePyramidBagAndSetCallback(taskId);
    }
    else
    {
        sub_81C66AC(taskId);
    }
}

static void sub_81C66AC(u8 taskId)
{
    CopyItemName(gSpecialVar_ItemId, gStringVar1);
    StringExpandPlaceholders(gStringVar4, gText_Var1CantBeHeld);
    DisplayItemMessageInBattlePyramid(taskId, gStringVar4, sub_81C66EC);
}

static void sub_81C66EC(u8 taskId)
{
    if (JOY_NEW(A_BUTTON))
    {
        PlaySE(SE_SELECT);
        Task_CloseBattlePyramidBagMessage(taskId);
    }
}

void Task_CloseBattlePyramidBagMessage(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    CloseBattlePyramidBagTextWindow();
    PrintItemDescription(data[1]);
    sub_81C5A98(data[0], 0);
    SetTaskToMainPyramidBagInputHandler(taskId);
}

static void sub_81C674C(u8 taskId)
{
    if (!itemid_80BF6D8_mail_related(gSpecialVar_ItemId))
        DisplayItemMessageInBattlePyramid(taskId, gText_CantWriteMail, sub_81C66EC);
    else if (!ItemId_GetImportance(gSpecialVar_ItemId))
        CloseBattlePyramidBagAndSetCallback(taskId);
    else
        sub_81C66AC(taskId);
}

static void BagAction_UseInBattle(u8 taskId)
{
    if (ItemId_GetBattleFunc(gSpecialVar_ItemId) != NULL)
    {
        sub_81C61A8();
        ItemId_GetBattleFunc(gSpecialVar_ItemId)(taskId);
    }
}

static void Task_BeginItemSwap(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    data[1] = gPyramidBagCursorData.scrollPosition + gPyramidBagCursorData.cursorPosition;
    gPyramidBagResources->unk814 = data[1];
    ListMenuSetUnkIndicatorsStructField(data[0], 0x10, 1);
    CopyItemName(gSaveBlock2Ptr->frontier.pyramidBag.itemId[gSaveBlock2Ptr->frontier.lvlMode][data[1]], gStringVar1);
    StringExpandPlaceholders(gStringVar4, gText_MoveVar1Where);
    FillWindowPixelBuffer(1, PIXEL_FILL(0));
    PrintOnWindow_Font1(1, gStringVar4, 3, 0, 0, 1, 0, 0);
    sub_81C5A98(data[0], 1);
    sub_81C704C(data[1]);
    gTasks[taskId].func = Task_ItemSwapHandleInput;
}

static void Task_ItemSwapHandleInput(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    if (MenuHelpers_CallLinkSomething() != TRUE)
    {
        if (JOY_NEW(SELECT_BUTTON))
        {
            PlaySE(SE_SELECT);
            ListMenuGetScrollAndRow(data[0], &gPyramidBagCursorData.scrollPosition, &gPyramidBagCursorData.cursorPosition);
            PerformItemSwap(taskId);
        }
        else
        {
            s32 id = ListMenu_ProcessInput(data[0]);
            ListMenuGetScrollAndRow(data[0], &gPyramidBagCursorData.scrollPosition, &gPyramidBagCursorData.cursorPosition);
            sub_81C7028(FALSE);
            sub_81C704C(gPyramidBagCursorData.cursorPosition);
            switch (id)
            {
            case LIST_NOTHING_CHOSEN:
                break;
            case LIST_CANCEL:
                PlaySE(SE_SELECT);
                if (JOY_NEW(A_BUTTON))
                    PerformItemSwap(taskId);
                else
                    sub_81C6A14(taskId);
                break;
            default:
                PlaySE(SE_SELECT);
                PerformItemSwap(taskId);
                break;
            }
        }
    }
}

static void PerformItemSwap(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    u16 *scrollOffset = &gPyramidBagCursorData.scrollPosition;
    u16 *selectedRow = &gPyramidBagCursorData.cursorPosition;
    u16 var = *scrollOffset + *selectedRow;

    if (data[1] == var || data[1] == var - 1)
    {
        sub_81C6A14(taskId);
    }
    else
    {
        MovePyramidBagItemSlotInList(data[1], var);
        gPyramidBagResources->unk814 = 0xFF;
        sub_81C7028(TRUE);
        DestroyListMenuTask(data[0], scrollOffset, selectedRow);
        if (data[1] < var)
            gPyramidBagCursorData.cursorPosition--;
        SetBagItemsListTemplate();
        data[0] = ListMenuInit(&gMultiuseListMenuTemplate, *scrollOffset, *selectedRow);
        SetTaskToMainPyramidBagInputHandler(taskId);
    }
}

static void sub_81C6A14(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    u16 *scrollOffset = &gPyramidBagCursorData.scrollPosition;
    u16 *selectedRow = &gPyramidBagCursorData.cursorPosition;

    gPyramidBagResources->unk814 = 0xFF;
    sub_81C7028(TRUE);
    DestroyListMenuTask(data[0], scrollOffset, selectedRow);
    if (data[1] < *scrollOffset + *selectedRow)
        gPyramidBagCursorData.cursorPosition--;
    SetBagItemsListTemplate();
    data[0] = ListMenuInit(&gMultiuseListMenuTemplate, *scrollOffset, *selectedRow);
    SetTaskToMainPyramidBagInputHandler(taskId);
}

void TryStoreHeldItemsInPyramidBag(void)
{
    u8 i;
    struct Pokemon *party = gPlayerParty;
    u16 *newItems = Alloc(PYRAMID_BAG_ITEMS_COUNT * sizeof(u16));
    u8 *newQuantities = Alloc(PYRAMID_BAG_ITEMS_COUNT * sizeof(u8));
    u16 heldItem;

    memcpy(newItems, gSaveBlock2Ptr->frontier.pyramidBag.itemId[gSaveBlock2Ptr->frontier.lvlMode], PYRAMID_BAG_ITEMS_COUNT * sizeof(u16));
    memcpy(newQuantities, gSaveBlock2Ptr->frontier.pyramidBag.quantity[gSaveBlock2Ptr->frontier.lvlMode], PYRAMID_BAG_ITEMS_COUNT * sizeof(u8));
    for (i = 0; i < 3; i++)
    {
        heldItem = GetMonData(&party[i], MON_DATA_HELD_ITEM);
        if (heldItem != ITEM_NONE && !AddBagItem(heldItem, 1))
        {
            // Cant store party held items in pyramid bag because bag is full
            memcpy(gSaveBlock2Ptr->frontier.pyramidBag.itemId[gSaveBlock2Ptr->frontier.lvlMode], newItems, PYRAMID_BAG_ITEMS_COUNT * sizeof(u16));
            memcpy(gSaveBlock2Ptr->frontier.pyramidBag.quantity[gSaveBlock2Ptr->frontier.lvlMode], newQuantities, PYRAMID_BAG_ITEMS_COUNT * sizeof(u8));
            Free(newItems);
            Free(newQuantities);
            gSpecialVar_Result = 1;
            return;
        }
    }

    heldItem = ITEM_NONE;
    for (i = 0; i < 3; i++)
    {
        SetMonData(&party[i], MON_DATA_HELD_ITEM, &heldItem);
    }
    gSpecialVar_Result = 0;
    Free(newItems);
    Free(newQuantities);
}

static void sub_81C6BD8(void)
{
    u8 i;

    InitWindows(gUnknown_0861F328);
    DeactivateAllTextPrinters();
    LoadUserWindowBorderGfx(0, 0x1, 0xE0);
    LoadMessageBoxGfx(0, 0xA, 0xD0);
    LoadPalette(gUnknown_0860F074, 0xF0, 0x20);

    for (i = 0; i < 5; i++)
        FillWindowPixelBuffer(i, PIXEL_FILL(0));

    PutWindowTilemap(0);
    PutWindowTilemap(1);
    ScheduleBgCopyTilemapToVram(0);
    ScheduleBgCopyTilemapToVram(1);
}

static void PrintOnWindow_Font1(u8 windowId, const u8 *src, u8 x, u8 y, u8 letterSpacing, u8 lineSpacing, u8 speed, u8 colorTableId)
{
    AddTextPrinterParameterized4(windowId, 1, x, y, letterSpacing, lineSpacing, sColorTable[colorTableId], speed, src);
}

static void PrintOnWindow_Font7(u8 windowId, const u8 *src, u8 x, u8 y, u8 letterSpacing, u8 lineSpacing, u8 speed, u8 colorTableId)
{
    AddTextPrinterParameterized4(windowId, 7, x, y, letterSpacing, lineSpacing, sColorTable[colorTableId], speed, src);
}

static void sub_81C6CEC(u8 windowId)
{
    DrawStdFrameWithCustomTileAndPalette(windowId, 0, 1, 0xE);
    ScheduleBgCopyTilemapToVram(1);
}

static u8 sub_81C6D08(u8 windowArrayId)
{
    return gPyramidBagResources->windowIds[windowArrayId];
}

static u8 sub_81C6D24(u8 windowArrayId)
{
    u8 *windowId = &gPyramidBagResources->windowIds[windowArrayId];
    if (*windowId == 0xFF)
    {
        *windowId = AddWindow(&gUnknown_0861F350[windowArrayId]);
        DrawStdFrameWithCustomTileAndPalette(*windowId, FALSE, 1, 0xE);
        ScheduleBgCopyTilemapToVram(1);
    }
    return *windowId;
}

static void sub_81C6D6C(u8 windowArrayId)
{
    u8 *windowId = &gPyramidBagResources->windowIds[windowArrayId];
    if (*windowId != 0xFF)
    {
        ClearStdWindowAndFrameToTransparent(*windowId, FALSE);
        ClearWindowTilemap(*windowId);
        RemoveWindow(*windowId);
        ScheduleBgCopyTilemapToVram(1);
        *windowId = 0xFF;
    }
}

static void sub_81C6DAC(u8 taskId, const struct YesNoFuncTable *yesNoTable)
{
    CreateYesNoMenuWithCallbacks(taskId, &gUnknown_0861F350[4], 1, 0, 2, 1, 0xE, yesNoTable);
}

void DisplayItemMessageInBattlePyramid(u8 taskId, const u8 *str, void (*callback)(u8 taskId))
{
    FillWindowPixelBuffer(2, PIXEL_FILL(1));
    DisplayMessageAndContinueTask(taskId, 2, 0xA, 0xD, 1, GetPlayerTextSpeedDelay(), str, callback);
    ScheduleBgCopyTilemapToVram(1);
}

static void CloseBattlePyramidBagTextWindow(void)
{
    ClearDialogWindowAndFrameToTransparent(2, FALSE);
    // This ClearWindowTilemap call is redundant, since ClearDialogWindowAndFrameToTransparent already calls it.
    ClearWindowTilemap(2);
    ScheduleBgCopyTilemapToVram(1);
}

#define ITEM_IMAGE_TAG 0x1024

static void sub_81C6E38(u8 itemSpriteArrayId)
{
    u8 *spriteId = &gPyramidBagResources->itemsSpriteIds[itemSpriteArrayId];
    if (*spriteId != 0xFF)
    {
        FreeSpriteTilesByTag(ITEM_IMAGE_TAG + itemSpriteArrayId);
        FreeSpritePaletteByTag(ITEM_IMAGE_TAG + itemSpriteArrayId);
        FreeSpriteOamMatrix(&gSprites[*spriteId]);
        DestroySprite(&gSprites[*spriteId]);
        *spriteId = 0xFF;
    }
}

static void sub_81C6E98(void)
{
    struct SpritePalette spritePalette;
    u16 *palPtr = Alloc(0x40);

    LZDecompressWram(gBattleFrontierGfx_PyramidBag_Pal, palPtr);
    spritePalette.data = palPtr + (gSaveBlock2Ptr->frontier.lvlMode * 16);
    spritePalette.tag = ITEM_IMAGE_TAG;
    LoadSpritePalette(&spritePalette);
    Free(palPtr);
}

static void sub_81C6EF4(void)
{
    u8 *spriteId = &gPyramidBagResources->itemsSpriteIds[0];
    *spriteId = CreateSprite(&gUnknown_0861F3D4, 0x44, 0x38, 0);
}

static void sub_81C6F20(void)
{
    struct Sprite *sprite = &gSprites[gPyramidBagResources->itemsSpriteIds[0]];
    if (sprite->affineAnimEnded)
    {
        StartSpriteAffineAnim(sprite, 1);
        sprite->callback = sub_81C6F68;
    }
}

static void sub_81C6F68(struct Sprite *sprite)
{
    if (sprite->affineAnimEnded)
    {
        StartSpriteAffineAnim(sprite, 0);
        sprite->callback = SpriteCallbackDummy;
    }
}

static void ShowItemImage(u16 itemId, u8 itemSpriteArrayId)
{
    u8 itemSpriteId;
    u8 *spriteId = &gPyramidBagResources->itemsSpriteIds[itemSpriteArrayId + 1];
    if (*spriteId == 0xFF)
    {
        FreeSpriteTilesByTag(ITEM_IMAGE_TAG + 1 + itemSpriteArrayId);
        FreeSpritePaletteByTag(ITEM_IMAGE_TAG + 1 + itemSpriteArrayId);
        itemSpriteId = AddItemIconSprite(ITEM_IMAGE_TAG + 1 + itemSpriteArrayId, ITEM_IMAGE_TAG + 1 + itemSpriteArrayId, itemId);
        if (itemSpriteId != MAX_SPRITES)
        {
            *spriteId = itemSpriteId;
            gSprites[itemSpriteId].pos2.x = 24;
            gSprites[itemSpriteId].pos2.y = 88;
        }
    }
}

static void sub_81C6FF8(u8 itemSpriteArrayId)
{
    sub_81C6E38(itemSpriteArrayId + 1);
}

static void sub_81C700C(void)
{
    sub_8122344(&gPyramidBagResources->itemsSpriteIds[3], 8);
}

static void sub_81C7028(bool8 invisible)
{
    sub_81223FC(&gPyramidBagResources->itemsSpriteIds[3], 8, invisible);
}

static void sub_81C704C(u8 y)
{
    sub_8122448(&gPyramidBagResources->itemsSpriteIds[3], 8 | 0x80, 120, (y + 1) * 16);
}
