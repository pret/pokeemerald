#include "global.h"
#include "bg.h"
#include "data.h"
#include "decompress.h"
#include "decoration.h"
#include "decoration_inventory.h"
#include "event_object_movement.h"
#include "field_player_avatar.h"
#include "field_screen_effect.h"
#include "field_weather.h"
#include "fieldmap.h"
#include "gpu_regs.h"
#include "graphics.h"
#include "international_string_util.h"
#include "item.h"
#include "item_icon.h"
#include "item_menu.h"
#include "list_menu.h"
#include "main.h"
#include "malloc.h"
#include "menu.h"
#include "menu_helpers.h"
#include "money.h"
#include "overworld.h"
#include "palette.h"
#include "party_menu.h"
#include "scanline_effect.h"
#include "script.h"
#include "shop.h"
#include "sound.h"
#include "sprite.h"
#include "string_util.h"
#include "strings.h"
#include "text_window.h"
#include "tv.h"
#include "constants/decorations.h"
#include "constants/items.h"
#include "constants/metatile_behaviors.h"
#include "constants/rgb.h"
#include "constants/songs.h"
#include "constants/tv.h"

EWRAM_DATA struct MartInfo gMartInfo = {0};
EWRAM_DATA struct ShopData *gShopDataPtr = NULL;
EWRAM_DATA struct ListMenuItem *gUnknown_02039F74 = NULL;
EWRAM_DATA u8 (*gUnknown_02039F78)[16] = {0};
EWRAM_DATA u8 gMartPurchaseHistoryId = 0;
EWRAM_DATA struct ItemSlot gMartPurchaseHistory[3] = {0};

static void Task_ShopMenu(u8 taskId);
static void Task_HandleShopMenuQuit(u8 taskId);
static void CB2_InitBuyMenu(void);
static void Task_GoToBuyOrSellMenu(u8 taskId);
static void MapPostLoadHook_ReturnToShopMenu(void);
static void Task_ReturnToShopMenu(u8 taskId);
static void ShowShopMenuAfterExitingBuyOrSellMenu(u8 taskId);
static void BuyMenuDrawGraphics(void);
static void BuyMenuAddScrollIndicatorArrows(void);
static void Task_BuyMenu(u8 taskId);
static void BuyMenuBuildListMenuTemplate(void);
static void BuyMenuInitBgs(void);
static void BuyMenuInitWindows(void);
static void BuyMenuDecompressBgGraphics(void);
static void BuyMenuSetListEntry(struct ListMenuItem*, u16, u8*);
static void BuyMenuAddItemIcon(u16, u8);
static void BuyMenuRemoveItemIcon(u16, u8);
static void BuyMenuPrint(u8 windowId, const u8 *text, u8 x, u8 y, s8 speed, u8 colorSet);
static void BuyMenuDrawMapGraphics(void);
static void BuyMenuCopyMenuBgToBg1TilemapBuffer(void);
static void BuyMenuCollectObjectEventData(void);
static void BuyMenuDrawObjectEvents(void);
static void BuyMenuDrawMapBg(void);
static bool8 BuyMenuCheckForOverlapWithMenuBg(int, int);
static void BuyMenuDrawMapMetatile(s16, s16, const u16*, u8);
static void BuyMenuDrawMapMetatileLayer(u16 *dest, s16 offset1, s16 offset2, const u16 *src);
static bool8 BuyMenuCheckIfObjectEventOverlapsMenuBg(s16 *);
static void ExitBuyMenu(u8 taskId);
static void Task_ExitBuyMenu(u8 taskId);
static void BuyMenuTryMakePurchase(u8 taskId);
static void BuyMenuReturnToItemList(u8 taskId);
static void Task_BuyHowManyDialogueInit(u8 taskId);
static void BuyMenuConfirmPurchase(u8 taskId);
static void BuyMenuPrintItemQuantityAndPrice(u8 taskId);
static void Task_BuyHowManyDialogueHandleInput(u8 taskId);
static void BuyMenuSubtractMoney(u8 taskId);
static void RecordItemPurchase(u8 taskId);
static void Task_ReturnToItemListAfterItemPurchase(u8 taskId);
static void Task_ReturnToItemListAfterDecorationPurchase(u8 taskId);
static void Task_HandleShopMenuBuy(u8 taskId);
static void Task_HandleShopMenuSell(u8 taskId);
static void BuyMenuPrintItemDescriptionAndShowItemIcon(s32 item, bool8 onInit, struct ListMenu *list);
static void BuyMenuPrintPriceInList(u8 windowId, s32 item, u8 y);

static const struct YesNoFuncTable sShopPurchaseYesNoFuncs =
{
    BuyMenuTryMakePurchase,
    BuyMenuReturnToItemList
};

static const struct MenuAction sShopMenuActions_BuySellQuit[] =
{
    { gText_ShopBuy, {.void_u8=Task_HandleShopMenuBuy} },
    { gText_ShopSell, {.void_u8=Task_HandleShopMenuSell} },
    { gText_ShopQuit, {.void_u8=Task_HandleShopMenuQuit} }
};

static const struct MenuAction sShopMenuActions_BuyQuit[] =
{
    { gText_ShopBuy, {.void_u8=Task_HandleShopMenuBuy} },
    { gText_ShopQuit, {.void_u8=Task_HandleShopMenuQuit} }
};

static const struct WindowTemplate sShopMenuWindowTemplates[] =
{
    {
        .bg = 0,
        .tilemapLeft = 2,
        .tilemapTop = 1,
        .width = 9,
        .height = 6,
        .paletteNum = 15,
        .baseBlock = 0x0008,
    },
    {
        .bg = 0,
        .tilemapLeft = 2,
        .tilemapTop = 1,
        .width = 9,
        .height = 4,
        .paletteNum = 15,
        .baseBlock = 0x0008,
    }
};

static const struct ListMenuTemplate sShopBuyMenuListTemplate =
{
    .items = NULL,
    .moveCursorFunc = BuyMenuPrintItemDescriptionAndShowItemIcon,
    .itemPrintFunc = BuyMenuPrintPriceInList,
    .totalItems = 0,
    .maxShowed = 0,
    .windowId = 1,
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

static const struct BgTemplate sShopBuyMenuBgTemplates[] =
{
    {
        .bg = 0,
        .charBaseIndex = 2,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0
    },
    {
        .bg = 1,
        .charBaseIndex = 0,
        .mapBaseIndex = 30,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0
    },
    {
        .bg = 2,
        .charBaseIndex = 0,
        .mapBaseIndex = 29,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 0
    },
    {
        .bg = 3,
        .charBaseIndex = 0,
        .mapBaseIndex = 28,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 3,
        .baseTile = 0
    }
};

static const struct WindowTemplate sShopBuyMenuWindowTemplates[] =
{
    {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 1,
        .width = 10,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 0x001E,
    },
    {
        .bg = 0,
        .tilemapLeft = 14,
        .tilemapTop = 2,
        .width = 15,
        .height = 16,
        .paletteNum = 15,
        .baseBlock = 0x0032,
    },
    {
        .bg = 0,
        .tilemapLeft = 0,
        .tilemapTop = 13,
        .width = 14,
        .height = 6,
        .paletteNum = 15,
        .baseBlock = 0x0122,
    },
    {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 11,
        .width = 12,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 0x0176,
    },
    {
        .bg = 0,
        .tilemapLeft = 18,
        .tilemapTop = 11,
        .width = 10,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 0x018E,
    },
    {
        .bg = 0,
        .tilemapLeft = 2,
        .tilemapTop = 15,
        .width = 27,
        .height = 4,
        .paletteNum = 15,
        .baseBlock = 0x01A2,
    },
    DUMMY_WIN_TEMPLATE
};

static const struct WindowTemplate sShopBuyMenuYesNoWindowTemplates =
{
    .bg = 0,
    .tilemapLeft = 21,
    .tilemapTop = 9,
    .width = 5,
    .height = 4,
    .paletteNum = 15,
    .baseBlock = 0x020E,
};

static const u8 sShopBuyMenuTextColors[][3] =
{
    {1, 2, 3},
    {0, 2, 3},
    {0, 3, 2}
};

static u8 CreateShopMenu(u8 martType)
{
    int numMenuItems;

    ScriptContext2_Enable();
    gMartInfo.martType = martType;

    if (martType == MART_TYPE_NORMAL)
    {
        struct WindowTemplate winTemplate;
        winTemplate = sShopMenuWindowTemplates[0];
        winTemplate.width = GetMaxWidthInMenuTable(sShopMenuActions_BuySellQuit, ARRAY_COUNT(sShopMenuActions_BuySellQuit));
        gMartInfo.windowId = AddWindow(&winTemplate);
        gMartInfo.menuActions = sShopMenuActions_BuySellQuit;
        numMenuItems = ARRAY_COUNT(sShopMenuActions_BuySellQuit);
    }
    else
    {
        struct WindowTemplate winTemplate;
        winTemplate = sShopMenuWindowTemplates[1];
        winTemplate.width = GetMaxWidthInMenuTable(sShopMenuActions_BuyQuit, ARRAY_COUNT(sShopMenuActions_BuyQuit));
        gMartInfo.windowId = AddWindow(&winTemplate);
        gMartInfo.menuActions = sShopMenuActions_BuyQuit;
        numMenuItems = ARRAY_COUNT(sShopMenuActions_BuyQuit);
    }

    SetStandardWindowBorderStyle(gMartInfo.windowId, 0);
    PrintMenuTable(gMartInfo.windowId, numMenuItems, gMartInfo.menuActions);
    InitMenuInUpperLeftCornerPlaySoundWhenAPressed(gMartInfo.windowId, numMenuItems, 0);
    PutWindowTilemap(gMartInfo.windowId);
    CopyWindowToVram(gMartInfo.windowId, 1);

    return CreateTask(Task_ShopMenu, 8);
}

static void SetShopMenuCallback(void (* callback)(void))
{
    gMartInfo.callback = callback;
}

static void SetShopItemsForSale(const u16 *items)
{
    u16 i = 0;

    gMartInfo.itemList = items;
    gMartInfo.itemCount = 0;

    while (gMartInfo.itemList[i])
    {
        gMartInfo.itemCount++;
        i++;
    }
}

static void Task_ShopMenu(u8 taskId)
{
    s8 inputCode = Menu_ProcessInputNoWrap();
    switch (inputCode)
    {
    case MENU_NOTHING_CHOSEN:
        break;
    case MENU_B_PRESSED:
        PlaySE(SE_SELECT);
        Task_HandleShopMenuQuit(taskId);
        break;
    default:
        gMartInfo.menuActions[inputCode].func.void_u8(taskId);
        break;
    }
}

static void Task_HandleShopMenuBuy(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    data[8] = (u32)CB2_InitBuyMenu >> 16;
    data[9] = (u32)CB2_InitBuyMenu;
    gTasks[taskId].func = Task_GoToBuyOrSellMenu;
    FadeScreen(FADE_TO_BLACK, 0);
}

static void Task_HandleShopMenuSell(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    data[8] = (u32)CB2_GoToSellMenu >> 16;
    data[9] = (u32)CB2_GoToSellMenu;
    gTasks[taskId].func = Task_GoToBuyOrSellMenu;
    FadeScreen(FADE_TO_BLACK, 0);
}

void CB2_ExitSellMenu(void)
{
    gFieldCallback = MapPostLoadHook_ReturnToShopMenu;
    SetMainCallback2(CB2_ReturnToField);
}

static void Task_HandleShopMenuQuit(u8 taskId)
{
    ClearStdWindowAndFrameToTransparent(gMartInfo.windowId, 2);
    RemoveWindow(gMartInfo.windowId);
    SaveRecordedItemPurchasesForTVShow();
    ScriptContext2_Disable();
    DestroyTask(taskId);

    if (gMartInfo.callback)
        gMartInfo.callback();
}

static void Task_GoToBuyOrSellMenu(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    if (!gPaletteFade.active)
    {
        DestroyTask(taskId);
        SetMainCallback2((void *)((u16)data[8] << 16 | (u16)data[9]));
    }
}

static void MapPostLoadHook_ReturnToShopMenu(void)
{
    FadeInFromBlack();
    CreateTask(Task_ReturnToShopMenu, 8);
}

static void Task_ReturnToShopMenu(u8 taskId)
{
    if (IsWeatherNotFadingIn() == TRUE)
    {
        if (gMartInfo.martType == MART_TYPE_DECOR2)
            DisplayItemMessageOnField(taskId, gText_CanIHelpWithAnythingElse, ShowShopMenuAfterExitingBuyOrSellMenu);
        else
            DisplayItemMessageOnField(taskId, gText_AnythingElseICanHelp, ShowShopMenuAfterExitingBuyOrSellMenu);
    }
}

static void ShowShopMenuAfterExitingBuyOrSellMenu(u8 taskId)
{
    CreateShopMenu(gMartInfo.martType);
    DestroyTask(taskId);
}

static void CB2_BuyMenu(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    DoScheduledBgTilemapCopiesToVram();
    UpdatePaletteFade();
}

static void VBlankCB_BuyMenu(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

#define tItemCount data[1]
#define tItemId data[5]
#define tListTaskId data[7]

static void CB2_InitBuyMenu(void)
{
    u8 taskId;

    switch (gMain.state)
    {
    case 0:
        SetVBlankHBlankCallbacksToNull();
        CpuFastFill(0, (void *)OAM, OAM_SIZE);
        ScanlineEffect_Stop();
        ResetTempTileDataBuffers();
        FreeAllSpritePalettes();
        ResetPaletteFade();
        ResetSpriteData();
        ResetTasks();
        ClearScheduledBgCopiesToVram();
        gShopDataPtr = AllocZeroed(sizeof(struct ShopData));
        gShopDataPtr->scrollIndicatorsTaskId = 0xFF;
        gShopDataPtr->itemSpriteIds[0] = 0xFF;
        gShopDataPtr->itemSpriteIds[1] = 0xFF;
        BuyMenuBuildListMenuTemplate();
        BuyMenuInitBgs();
        FillBgTilemapBufferRect_Palette0(0, 0, 0, 0, 0x20, 0x20);
        FillBgTilemapBufferRect_Palette0(1, 0, 0, 0, 0x20, 0x20);
        FillBgTilemapBufferRect_Palette0(2, 0, 0, 0, 0x20, 0x20);
        FillBgTilemapBufferRect_Palette0(3, 0, 0, 0, 0x20, 0x20);
        BuyMenuInitWindows();
        BuyMenuDecompressBgGraphics();
        gMain.state++;
        break;
    case 1:
        if (!FreeTempTileDataBuffersIfPossible())
            gMain.state++;
        break;
    default:
        BuyMenuDrawGraphics();
        BuyMenuAddScrollIndicatorArrows();
        taskId = CreateTask(Task_BuyMenu, 8);
        gTasks[taskId].tListTaskId = ListMenuInit(&gMultiuseListMenuTemplate, 0, 0);
        BlendPalettes(0xFFFFFFFF, 0x10, RGB_BLACK);
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0x10, 0, RGB_BLACK);
        SetVBlankCallback(VBlankCB_BuyMenu);
        SetMainCallback2(CB2_BuyMenu);
        break;
    }
}

static void BuyMenuFreeMemory(void)
{
    Free(gShopDataPtr);
    Free(gUnknown_02039F74);
    Free(gUnknown_02039F78);
    FreeAllWindowBuffers();
}

static void BuyMenuBuildListMenuTemplate(void)
{
    u16 i;

    gUnknown_02039F74 = Alloc((gMartInfo.itemCount + 1) * sizeof(*gUnknown_02039F74));
    gUnknown_02039F78 = Alloc((gMartInfo.itemCount + 1) * sizeof(*gUnknown_02039F78));
    for (i = 0; i < gMartInfo.itemCount; i++)
        BuyMenuSetListEntry(&gUnknown_02039F74[i], gMartInfo.itemList[i], gUnknown_02039F78[i]);

    StringCopy(gUnknown_02039F78[i], gText_Cancel2);
    gUnknown_02039F74[i].name = gUnknown_02039F78[i];
    gUnknown_02039F74[i].id = -2;

    gMultiuseListMenuTemplate = sShopBuyMenuListTemplate;
    gMultiuseListMenuTemplate.items = gUnknown_02039F74;
    gMultiuseListMenuTemplate.totalItems = gMartInfo.itemCount + 1;
    if (gMultiuseListMenuTemplate.totalItems > 8)
        gMultiuseListMenuTemplate.maxShowed = 8;
    else
        gMultiuseListMenuTemplate.maxShowed = gMultiuseListMenuTemplate.totalItems;

    gShopDataPtr->itemsShowed = gMultiuseListMenuTemplate.maxShowed;
}

static void BuyMenuSetListEntry(struct ListMenuItem *menuItem, u16 item, u8 *name)
{
    if (gMartInfo.martType == MART_TYPE_NORMAL)
        CopyItemName(item, name);
    else
        StringCopy(name, gDecorations[item].name);

    menuItem->name = name;
    menuItem->id = item;
}

static void BuyMenuPrintItemDescriptionAndShowItemIcon(s32 item, bool8 onInit, struct ListMenu *list)
{
    const u8 *description;
    if (onInit != TRUE)
        PlaySE(SE_SELECT);

    if (item != -2)
        BuyMenuAddItemIcon(item, gShopDataPtr->iconSlot);
    else
        BuyMenuAddItemIcon(-1, gShopDataPtr->iconSlot);

    BuyMenuRemoveItemIcon(item, gShopDataPtr->iconSlot ^ 1);
    gShopDataPtr->iconSlot ^= 1;
    if (item != -2)
    {
        if (gMartInfo.martType == MART_TYPE_NORMAL)
            description = ItemId_GetDescription(item);
        else
            description = gDecorations[item].description;
    }
    else
    {
        description = gText_QuitShopping;
    }

    FillWindowPixelBuffer(2, PIXEL_FILL(0));
    BuyMenuPrint(2, description, 3, 1, 0, 0);
}

static void BuyMenuPrintPriceInList(u8 windowId, s32 item, u8 y)
{
    u8 x;

    if (item != -2)
    {
        if (gMartInfo.martType == MART_TYPE_NORMAL)
        {
            ConvertIntToDecimalStringN(
                gStringVar1,
                ItemId_GetPrice(item) >> GetPriceReduction(POKENEWS_SLATEPORT),
                STR_CONV_MODE_LEFT_ALIGN,
                5);
        }
        else
        {
            ConvertIntToDecimalStringN(
                gStringVar1,
                gDecorations[item].price,
                STR_CONV_MODE_LEFT_ALIGN,
                5);
        }

        StringExpandPlaceholders(gStringVar4, gText_PokedollarVar1);
        x = GetStringRightAlignXOffset(7, gStringVar4, 0x78);
        AddTextPrinterParameterized4(windowId, 7, x, y, 0, 0, sShopBuyMenuTextColors[1], -1, gStringVar4);
    }
}

static void BuyMenuAddScrollIndicatorArrows(void)
{
    if (gShopDataPtr->scrollIndicatorsTaskId == 0xFF && gMartInfo.itemCount + 1 > 8)
    {
        gShopDataPtr->scrollIndicatorsTaskId = AddScrollIndicatorArrowPairParameterized(
            SCROLL_ARROW_UP,
            0xAC,
            0xC,
            0x94,
            gMartInfo.itemCount - 7,
            2100,
            2100,
            &gShopDataPtr->scrollOffset);
    }
}

static void BuyMenuRemoveScrollIndicatorArrows(void)
{
    if (gShopDataPtr->scrollIndicatorsTaskId != 0xFF)
    {
        RemoveScrollIndicatorArrowPair(gShopDataPtr->scrollIndicatorsTaskId);
        gShopDataPtr->scrollIndicatorsTaskId = 0xFF;
    }
}

static void BuyMenuPrintCursor(u8 scrollIndicatorsTaskId, u8 colorSet)
{
    u8 y = ListMenuGetYCoordForPrintingArrowCursor(scrollIndicatorsTaskId);
    BuyMenuPrint(1, gText_SelectorArrow2, 0, y, 0, colorSet);
}

static void BuyMenuAddItemIcon(u16 item, u8 iconSlot)
{
    u8 spriteId;
    u8 *spriteIdPtr = &gShopDataPtr->itemSpriteIds[iconSlot];
    if (*spriteIdPtr != 0xFF)
        return;

    if (gMartInfo.martType == MART_TYPE_NORMAL || item == 0xFFFF)
    {
        spriteId = AddItemIconSprite(iconSlot + 2110, iconSlot + 2110, item);
        if (spriteId != MAX_SPRITES)
        {
            *spriteIdPtr = spriteId;
            gSprites[spriteId].pos2.x = 24;
            gSprites[spriteId].pos2.y = 88;
        }
    }
    else
    {
        spriteId = AddDecorationIconObject(item, 20, 84, 1, iconSlot + 2110, iconSlot + 2110);
        if (spriteId != MAX_SPRITES)
            *spriteIdPtr = spriteId;
    }
}

static void BuyMenuRemoveItemIcon(u16 item, u8 iconSlot)
{
    u8 *spriteIdPtr = &gShopDataPtr->itemSpriteIds[iconSlot];
    if (*spriteIdPtr == 0xFF)
        return;

    FreeSpriteTilesByTag(iconSlot + 2110);
    FreeSpritePaletteByTag(iconSlot + 2110);
    DestroySprite(&gSprites[*spriteIdPtr]);
    *spriteIdPtr = 0xFF;
}

static void BuyMenuInitBgs(void)
{
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, sShopBuyMenuBgTemplates, ARRAY_COUNT(sShopBuyMenuBgTemplates));
    SetBgTilemapBuffer(1, gShopDataPtr->tilemapBuffers[1]);
    SetBgTilemapBuffer(2, gShopDataPtr->tilemapBuffers[3]);
    SetBgTilemapBuffer(3, gShopDataPtr->tilemapBuffers[2]);
    SetGpuReg(REG_OFFSET_BG0HOFS, 0);
    SetGpuReg(REG_OFFSET_BG0VOFS, 0);
    SetGpuReg(REG_OFFSET_BG1HOFS, 0);
    SetGpuReg(REG_OFFSET_BG1VOFS, 0);
    SetGpuReg(REG_OFFSET_BG2HOFS, 0);
    SetGpuReg(REG_OFFSET_BG2VOFS, 0);
    SetGpuReg(REG_OFFSET_BG3HOFS, 0);
    SetGpuReg(REG_OFFSET_BG3VOFS, 0);
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0 | DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
    ShowBg(0);
    ShowBg(1);
    ShowBg(2);
    ShowBg(3);
}

static void BuyMenuDecompressBgGraphics(void)
{
    DecompressAndCopyTileDataToVram(1, gBuyMenuFrame_Gfx, 0x3A0, 0x3E3, 0);
    LZDecompressWram(gBuyMenuFrame_Tilemap, gShopDataPtr->tilemapBuffers[0]);
    LoadCompressedPalette(gMenuMoneyPal, 0xC0, 0x20);
}

static void BuyMenuInitWindows(void)
{
    InitWindows(sShopBuyMenuWindowTemplates);
    DeactivateAllTextPrinters();
    LoadUserWindowBorderGfx(0, 1, 0xD0);
    LoadMessageBoxGfx(0, 0xA, 0xE0);
    PutWindowTilemap(0);
    PutWindowTilemap(1);
    PutWindowTilemap(2);
}

static void BuyMenuPrint(u8 windowId, const u8 *text, u8 x, u8 y, s8 speed, u8 colorSet)
{
    AddTextPrinterParameterized4(windowId, 1, x, y, 0, 0, sShopBuyMenuTextColors[colorSet], speed, text);
}

static void BuyMenuDisplayMessage(u8 taskId, const u8 *text, TaskFunc callback)
{
    DisplayMessageAndContinueTask(taskId, 5, 10, 14, 1, GetPlayerTextSpeedDelay(), text, callback);
    ScheduleBgCopyTilemapToVram(0);
}

static void BuyMenuDrawGraphics(void)
{
    BuyMenuDrawMapGraphics();
    BuyMenuCopyMenuBgToBg1TilemapBuffer();
    AddMoneyLabelObject(19, 11);
    PrintMoneyAmountInMoneyBoxWithBorder(0, 1, 13, GetMoney(&gSaveBlock1Ptr->money));
    ScheduleBgCopyTilemapToVram(0);
    ScheduleBgCopyTilemapToVram(1);
    ScheduleBgCopyTilemapToVram(2);
    ScheduleBgCopyTilemapToVram(3);
}

static void BuyMenuDrawMapGraphics(void)
{
    BuyMenuCollectObjectEventData();
    BuyMenuDrawObjectEvents();
    BuyMenuDrawMapBg();
}

static void BuyMenuDrawMapBg(void)
{
    s16 i;
    s16 j;
    s16 x;
    s16 y;
    const struct MapLayout *mapLayout;
    u16 metatile;
    u8 metatileLayerType;

    mapLayout = gMapHeader.mapLayout;
    GetXYCoordsOneStepInFrontOfPlayer(&x, &y);
    x -= 4;
    y -= 4;

    for (j = 0; j < 10; j++)
    {
        for (i = 0; i < 15; i++)
        {
            metatile = MapGridGetMetatileIdAt(x + i, y + j);
            if (BuyMenuCheckForOverlapWithMenuBg(i, j) == TRUE)
                metatileLayerType = MapGridGetMetatileLayerTypeAt(x + i, y + j);
            else
                metatileLayerType = 1;

            if (metatile < NUM_METATILES_IN_PRIMARY)
            {
                BuyMenuDrawMapMetatile(i, j, (u16*)mapLayout->primaryTileset->metatiles + metatile * 8, metatileLayerType);
            }
            else
            {
                BuyMenuDrawMapMetatile(i, j, (u16*)mapLayout->secondaryTileset->metatiles + ((metatile - NUM_METATILES_IN_PRIMARY) * 8), metatileLayerType);
            }
        }
    }
}

static void BuyMenuDrawMapMetatile(s16 x, s16 y, const u16 *src, u8 metatileLayerType)
{
    u16 offset1 = x * 2;
    u16 offset2 = y * 64;

    switch (metatileLayerType)
    {
    case 0:
        BuyMenuDrawMapMetatileLayer(gShopDataPtr->tilemapBuffers[3], offset1, offset2, src);
        BuyMenuDrawMapMetatileLayer(gShopDataPtr->tilemapBuffers[1], offset1, offset2, src + 4);
        break;
    case 1:
        BuyMenuDrawMapMetatileLayer(gShopDataPtr->tilemapBuffers[2], offset1, offset2, src);
        BuyMenuDrawMapMetatileLayer(gShopDataPtr->tilemapBuffers[3], offset1, offset2, src + 4);
        break;
    case 2:
        BuyMenuDrawMapMetatileLayer(gShopDataPtr->tilemapBuffers[2], offset1, offset2, src);
        BuyMenuDrawMapMetatileLayer(gShopDataPtr->tilemapBuffers[1], offset1, offset2, src + 4);
        break;
    }
}

static void BuyMenuDrawMapMetatileLayer(u16 *dest, s16 offset1, s16 offset2, const u16 *src)
{
    // This function draws a whole 2x2 metatile.
    dest[offset1 + offset2] = src[0]; // top left
    dest[offset1 + offset2 + 1] = src[1]; // top right
    dest[offset1 + offset2 + 32] = src[2]; // bottom left
    dest[offset1 + offset2 + 33] = src[3]; // bottom right
}

static void BuyMenuCollectObjectEventData(void)
{
    s16 facingX;
    s16 facingY;
    u8 y;
    u8 x;
    u8 r8 = 0;

    GetXYCoordsOneStepInFrontOfPlayer(&facingX, &facingY);
    for (y = 0; y < OBJECT_EVENTS_COUNT; y++)
        gShopDataPtr->viewportObjects[y][OBJ_EVENT_ID] = OBJECT_EVENTS_COUNT;
    for (y = 0; y < 5; y++)
    {
        for (x = 0; x < 7; x++)
        {
            u8 objEventId = GetObjectEventIdByXY(facingX - 4 + x, facingY - 2 + y);

            if (objEventId != OBJECT_EVENTS_COUNT)
            {
                gShopDataPtr->viewportObjects[r8][OBJ_EVENT_ID] = objEventId;
                gShopDataPtr->viewportObjects[r8][X_COORD] = x;
                gShopDataPtr->viewportObjects[r8][Y_COORD] = y;
                gShopDataPtr->viewportObjects[r8][LAYER_TYPE] = MapGridGetMetatileLayerTypeAt(facingX - 4 + x, facingY - 2 + y);

                switch (gObjectEvents[objEventId].facingDirection)
                {
                    case DIR_SOUTH:
                        gShopDataPtr->viewportObjects[r8][ANIM_NUM] = 0;
                        break;
                    case DIR_NORTH:
                        gShopDataPtr->viewportObjects[r8][ANIM_NUM] = 1;
                        break;
                    case DIR_WEST:
                        gShopDataPtr->viewportObjects[r8][ANIM_NUM] = 2;
                        break;
                    case DIR_EAST:
                    default:
                        gShopDataPtr->viewportObjects[r8][ANIM_NUM] = 3;
                        break;
                }
                r8++;
            }
        }
    }
}

static void BuyMenuDrawObjectEvents(void)
{
    u8 i;
    u8 spriteId;
    const struct ObjectEventGraphicsInfo *graphicsInfo;

    for (i = 0; i < OBJECT_EVENTS_COUNT; i++)
    {
        if (gShopDataPtr->viewportObjects[i][OBJ_EVENT_ID] == OBJECT_EVENTS_COUNT)
            continue;

        graphicsInfo = GetObjectEventGraphicsInfo(gObjectEvents[gShopDataPtr->viewportObjects[i][OBJ_EVENT_ID]].graphicsId);

        spriteId = AddPseudoObjectEvent(
            gObjectEvents[gShopDataPtr->viewportObjects[i][OBJ_EVENT_ID]].graphicsId,
            SpriteCallbackDummy,
            (u16)gShopDataPtr->viewportObjects[i][X_COORD] * 16 + 8,
            (u16)gShopDataPtr->viewportObjects[i][Y_COORD] * 16 + 48 - graphicsInfo->height / 2,
            2);

        if (BuyMenuCheckIfObjectEventOverlapsMenuBg(gShopDataPtr->viewportObjects[i]) == TRUE)
        {
            gSprites[spriteId].subspriteTableNum = 4;
            gSprites[spriteId].subspriteMode = SUBSPRITES_ON;
        }

        StartSpriteAnim(&gSprites[spriteId], gShopDataPtr->viewportObjects[i][ANIM_NUM]);
    }
}

static bool8 BuyMenuCheckIfObjectEventOverlapsMenuBg(s16 *object)
{
    if (!BuyMenuCheckForOverlapWithMenuBg(object[X_COORD], object[Y_COORD] + 2) && object[LAYER_TYPE] != MB_SECRET_BASE_WALL)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

static void BuyMenuCopyMenuBgToBg1TilemapBuffer(void)
{
    s16 i;
    u16 *dest = gShopDataPtr->tilemapBuffers[1];
    const u16 *src = gShopDataPtr->tilemapBuffers[0];

    for (i = 0; i < 1024; i++)
    {
        if (src[i] != 0)
        {
            dest[i] = src[i] + 0xC3E3;
        }
    }
}

static bool8 BuyMenuCheckForOverlapWithMenuBg(int x, int y)
{
    const u16 *metatile = gShopDataPtr->tilemapBuffers[0];
    int offset1 = x * 2;
    int offset2 = y * 64;

    if (metatile[offset2 + offset1] == 0 &&
        metatile[offset2 + offset1 + 32] == 0 &&
        metatile[offset2 + offset1 + 1] == 0 &&
        metatile[offset2 + offset1 + 33] == 0)
    {
        return TRUE;
    }

    return FALSE;
}

static void Task_BuyMenu(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    if (!gPaletteFade.active)
    {
        s32 itemId = ListMenu_ProcessInput(tListTaskId);
        ListMenuGetScrollAndRow(tListTaskId, &gShopDataPtr->scrollOffset, &gShopDataPtr->selectedRow);

        switch (itemId)
        {
        case LIST_NOTHING_CHOSEN:
            break;
        case LIST_CANCEL:
            PlaySE(SE_SELECT);
            ExitBuyMenu(taskId);
            break;
        default:
            PlaySE(SE_SELECT);
            tItemId = itemId;
            ClearWindowTilemap(2);
            BuyMenuRemoveScrollIndicatorArrows();
            BuyMenuPrintCursor(tListTaskId, 2);

            if (gMartInfo.martType == MART_TYPE_NORMAL)
            {
                gShopDataPtr->totalCost = (ItemId_GetPrice(itemId) >> GetPriceReduction(POKENEWS_SLATEPORT));
            }
            else
            {
                gShopDataPtr->totalCost = gDecorations[itemId].price;
            }

            if (!IsEnoughMoney(&gSaveBlock1Ptr->money, gShopDataPtr->totalCost))
            {
                BuyMenuDisplayMessage(taskId, gText_YouDontHaveMoney, BuyMenuReturnToItemList);
            }
            else
            {
                if (gMartInfo.martType == MART_TYPE_NORMAL)
                {
                    CopyItemName(itemId, gStringVar1);
                    if (ItemId_GetPocket(itemId) == POCKET_TM_HM)
                    {
                        StringCopy(gStringVar2, gMoveNames[ItemIdToBattleMoveId(itemId)]);
                        BuyMenuDisplayMessage(taskId, gText_Var1CertainlyHowMany2, Task_BuyHowManyDialogueInit);
                    }
                    else
                    {
                        BuyMenuDisplayMessage(taskId, gText_Var1CertainlyHowMany, Task_BuyHowManyDialogueInit);
                    }
                }
                else
                {
                    StringCopy(gStringVar1, gDecorations[itemId].name);
                    ConvertIntToDecimalStringN(gStringVar2, gShopDataPtr->totalCost, STR_CONV_MODE_LEFT_ALIGN, 6);

                    if (gMartInfo.martType == MART_TYPE_DECOR)
                        StringExpandPlaceholders(gStringVar4, gText_Var1IsItThatllBeVar2);
                    else
                        StringExpandPlaceholders(gStringVar4, gText_YouWantedVar1ThatllBeVar2);
                    BuyMenuDisplayMessage(taskId, gStringVar4, BuyMenuConfirmPurchase);
                }
            }
            break;
        }
    }
}

static void Task_BuyHowManyDialogueInit(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    u16 quantityInBag = CountTotalItemQuantityInBag(tItemId);
    u16 maxQuantity;

    DrawStdFrameWithCustomTileAndPalette(3, FALSE, 1, 13);
    ConvertIntToDecimalStringN(gStringVar1, quantityInBag, STR_CONV_MODE_RIGHT_ALIGN, MAX_ITEM_DIGITS + 1);
    StringExpandPlaceholders(gStringVar4, gText_InBagVar1);
    BuyMenuPrint(3, gStringVar4, 0, 1, 0, 0);
    tItemCount = 1;
    DrawStdFrameWithCustomTileAndPalette(4, FALSE, 1, 13);
    BuyMenuPrintItemQuantityAndPrice(taskId);
    ScheduleBgCopyTilemapToVram(0);

    maxQuantity = GetMoney(&gSaveBlock1Ptr->money) / gShopDataPtr->totalCost;

    if (maxQuantity > MAX_BAG_ITEM_CAPACITY)
    {
        gShopDataPtr->maxQuantity = MAX_BAG_ITEM_CAPACITY;
    }
    else
    {
        gShopDataPtr->maxQuantity = maxQuantity;
    }

    gTasks[taskId].func = Task_BuyHowManyDialogueHandleInput;
}

static void Task_BuyHowManyDialogueHandleInput(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    if (AdjustQuantityAccordingToDPadInput(&tItemCount, gShopDataPtr->maxQuantity) == TRUE)
    {
        gShopDataPtr->totalCost = (ItemId_GetPrice(tItemId) >> GetPriceReduction(POKENEWS_SLATEPORT)) * tItemCount;
        BuyMenuPrintItemQuantityAndPrice(taskId);
    }
    else
    {
        if (JOY_NEW(A_BUTTON))
        {
            PlaySE(SE_SELECT);
            ClearStdWindowAndFrameToTransparent(4, 0);
            ClearStdWindowAndFrameToTransparent(3, 0);
            ClearWindowTilemap(4);
            ClearWindowTilemap(3);
            PutWindowTilemap(1);
            CopyItemName(tItemId, gStringVar1);
            ConvertIntToDecimalStringN(gStringVar2, tItemCount, STR_CONV_MODE_LEFT_ALIGN, BAG_ITEM_CAPACITY_DIGITS);
            ConvertIntToDecimalStringN(gStringVar3, gShopDataPtr->totalCost, STR_CONV_MODE_LEFT_ALIGN, 6);
            BuyMenuDisplayMessage(taskId, gText_Var1AndYouWantedVar2, BuyMenuConfirmPurchase);
        }
        else if (JOY_NEW(B_BUTTON))
        {
            PlaySE(SE_SELECT);
            ClearStdWindowAndFrameToTransparent(4, 0);
            ClearStdWindowAndFrameToTransparent(3, 0);
            ClearWindowTilemap(4);
            ClearWindowTilemap(3);
            BuyMenuReturnToItemList(taskId);
        }
    }
}

static void BuyMenuConfirmPurchase(u8 taskId)
{
    CreateYesNoMenuWithCallbacks(taskId, &sShopBuyMenuYesNoWindowTemplates, 1, 0, 0, 1, 13, &sShopPurchaseYesNoFuncs);
}

static void BuyMenuTryMakePurchase(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    PutWindowTilemap(1);

    if (gMartInfo.martType == MART_TYPE_NORMAL)
    {
        if (AddBagItem(tItemId, tItemCount) == TRUE)
        {
            BuyMenuDisplayMessage(taskId, gText_HereYouGoThankYou, BuyMenuSubtractMoney);
            RecordItemPurchase(taskId);
        }
        else
        {
            BuyMenuDisplayMessage(taskId, gText_NoMoreRoomForThis, BuyMenuReturnToItemList);
        }
    }
    else
    {
        if (DecorationAdd(tItemId))
        {
            if (gMartInfo.martType == MART_TYPE_DECOR)
            {
                BuyMenuDisplayMessage(taskId, gText_ThankYouIllSendItHome, BuyMenuSubtractMoney);
            }
            else
            {
                BuyMenuDisplayMessage(taskId, gText_ThanksIllSendItHome, BuyMenuSubtractMoney);
            }
        }
        else
        {
            BuyMenuDisplayMessage(taskId, gText_SpaceForVar1Full, BuyMenuReturnToItemList);
        }
    }
}

static void BuyMenuSubtractMoney(u8 taskId)
{
    IncrementGameStat(GAME_STAT_SHOPPED);
    RemoveMoney(&gSaveBlock1Ptr->money, gShopDataPtr->totalCost);
    PlaySE(SE_SHOP);
    PrintMoneyAmountInMoneyBox(0, GetMoney(&gSaveBlock1Ptr->money), 0);

    if (gMartInfo.martType == MART_TYPE_NORMAL)
    {
        gTasks[taskId].func = Task_ReturnToItemListAfterItemPurchase;
    }
    else
    {
        gTasks[taskId].func = Task_ReturnToItemListAfterDecorationPurchase;
    }
}

static void Task_ReturnToItemListAfterItemPurchase(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    if (JOY_NEW(A_BUTTON | B_BUTTON))
    {
        PlaySE(SE_SELECT);
        if (tItemId == ITEM_POKE_BALL && tItemCount > 9 && AddBagItem(ITEM_PREMIER_BALL, 1) == TRUE)
        {
            BuyMenuDisplayMessage(taskId, gText_ThrowInPremierBall, BuyMenuReturnToItemList);
        }
        else
        {
            BuyMenuReturnToItemList(taskId);
        }
    }
}

static void Task_ReturnToItemListAfterDecorationPurchase(u8 taskId)
{
    if (JOY_NEW(A_BUTTON | B_BUTTON))
    {
        PlaySE(SE_SELECT);
        BuyMenuReturnToItemList(taskId);
    }
}

static void BuyMenuReturnToItemList(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    ClearDialogWindowAndFrameToTransparent(5, 0);
    BuyMenuPrintCursor(tListTaskId, 1);
    PutWindowTilemap(1);
    PutWindowTilemap(2);
    ScheduleBgCopyTilemapToVram(0);
    BuyMenuAddScrollIndicatorArrows();
    gTasks[taskId].func = Task_BuyMenu;
}

static void BuyMenuPrintItemQuantityAndPrice(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    FillWindowPixelBuffer(4, PIXEL_FILL(1));
    PrintMoneyAmount(4, 38, 1, gShopDataPtr->totalCost, TEXT_SPEED_FF);
    ConvertIntToDecimalStringN(gStringVar1, tItemCount, STR_CONV_MODE_LEADING_ZEROS, BAG_ITEM_CAPACITY_DIGITS);
    StringExpandPlaceholders(gStringVar4, gText_xVar1);
    BuyMenuPrint(4, gStringVar4, 0, 1, 0, 0);
}

static void ExitBuyMenu(u8 taskId)
{
    gFieldCallback = MapPostLoadHook_ReturnToShopMenu;
    BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
    gTasks[taskId].func = Task_ExitBuyMenu;
}

static void Task_ExitBuyMenu(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        RemoveMoneyLabelObject();
        BuyMenuFreeMemory();
        SetMainCallback2(CB2_ReturnToField);
        DestroyTask(taskId);
    }
}

static void ClearItemPurchases(void)
{
    gMartPurchaseHistoryId = 0;
    memset(gMartPurchaseHistory, 0, sizeof(gMartPurchaseHistory));
}

static void RecordItemPurchase(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    u16 i;

    for (i = 0; i < 3; i++)
    {
        if (gMartPurchaseHistory[i].itemId == tItemId && gMartPurchaseHistory[i].quantity != 0)
        {
            if (gMartPurchaseHistory[i].quantity + tItemCount > 255)
            {
                gMartPurchaseHistory[i].quantity = 255;
            }
            else
            {
                gMartPurchaseHistory[i].quantity += tItemCount;
            }
            return;
        }
    }

    if (gMartPurchaseHistoryId < 3)
    {
        gMartPurchaseHistory[gMartPurchaseHistoryId].itemId = tItemId;
        gMartPurchaseHistory[gMartPurchaseHistoryId].quantity = tItemCount;
        gMartPurchaseHistoryId++;
    }
}

#undef tItemCount
#undef tItemId
#undef tListTaskId

void CreatePokemartMenu(const u16 *itemsForSale)
{
    CreateShopMenu(MART_TYPE_NORMAL);
    SetShopItemsForSale(itemsForSale);
    ClearItemPurchases();
    SetShopMenuCallback(EnableBothScriptContexts);
}

void CreateDecorationShop1Menu(const u16 *itemsForSale)
{
    CreateShopMenu(MART_TYPE_DECOR);
    SetShopItemsForSale(itemsForSale);
    SetShopMenuCallback(EnableBothScriptContexts);
}

void CreateDecorationShop2Menu(const u16 *itemsForSale)
{
    CreateShopMenu(MART_TYPE_DECOR2);
    SetShopItemsForSale(itemsForSale);
    SetShopMenuCallback(EnableBothScriptContexts);
}
