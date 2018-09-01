#include "global.h"
#include "bg.h"
#include "decoration.h"
#include "field_screen.h"
#include "field_weather.h"
#include "international_string_util.h"
#include "item.h"
#include "list_menu.h"
#include "main.h"
#include "malloc.h"
#include "menu.h"
#include "menu_helpers.h"
#include "overworld.h"
#include "palette.h"
#include "scanline_effect.h"
#include "script.h"
#include "shop.h"
#include "sound.h"
#include "string_util.h"
#include "strings.h"
#include "tv.h"
#include "constants/rgb.h"
#include "constants/songs.h"

extern struct ShopData *gShopDataPtr;
extern struct ListMenuItem *gUnknown_02039F74;
extern u8 (*gUnknown_02039F78)[16];
extern struct MartInfo gMartInfo;

extern const struct WindowTemplate gUnknown_08589A38[2];
extern const struct MenuAction gUnknown_08589A10[3];
extern const struct MenuAction gUnknown_08589A28[2];
extern const struct ListMenuTemplate gUnknown_08589A48;
extern const u8 gUnknown_08589AB3[];

static void Task_ShopMenu(u8 taskId);
void HandleShopMenuQuit(u8 taskId);
void CB2_InitBuyMenu(void);
static void Task_GoToBuyOrSellMenu(u8 taskId);
void CB2_GoToSellMenu(void);
void MapPostLoadHook_ExitBuyOrSellMenu(void);
void Task_ExitSellMenu(u8 taskId);
void ReturnToShopMenuAfterExitingSellMenu(u8 taskId);
void BuyMenuDrawGraphics(void);
void BuyMenuAddScrollIndicatorArrows(void);
void Task_BuyMenu(u8 taskId);
void BuyMenuBuildListMenuTemplate(void);
void BuyMenuInitBgs(void);
void BuyMenuInitWindows(void);
void BuyMenuDecompressBgGraphics(void);
void BuyMenuSetListEntry(struct ListMenuItem*, u16, u8*);
void BuyMenuAddItemIcon(u16, u8);
void BuyMenuRemoveItemIcon(u16, u8);
void BuyMenuPrint(u8, const u8*, u8, u8, u8, u8);


/*static*/ u8 CreateShopMenu(u8 martType)
{
    int numMenuItems;

    ScriptContext2_Enable();
    gMartInfo.martType = martType;

    if (martType == MART_TYPE_0)
    {
        struct WindowTemplate winTemplate;
        winTemplate = gUnknown_08589A38[0];
        winTemplate.width = GetMaxWidthInMenuTable(gUnknown_08589A10, ARRAY_COUNT(gUnknown_08589A10));
        gMartInfo.windowId = AddWindow(&winTemplate);
        gMartInfo.menuActions = gUnknown_08589A10;
        numMenuItems = ARRAY_COUNT(gUnknown_08589A10);
    }
    else
    {
        struct WindowTemplate winTemplate;
        winTemplate = gUnknown_08589A38[1];
        winTemplate.width = GetMaxWidthInMenuTable(gUnknown_08589A28, ARRAY_COUNT(gUnknown_08589A28));
        gMartInfo.windowId = AddWindow(&winTemplate);
        gMartInfo.menuActions = gUnknown_08589A28;
        numMenuItems = ARRAY_COUNT(gUnknown_08589A28);
    }

    SetStandardWindowBorderStyle(gMartInfo.windowId, 0);
    PrintMenuTable(gMartInfo.windowId, numMenuItems, gMartInfo.menuActions);
    InitMenuInUpperLeftCornerPlaySoundWhenAPressed(gMartInfo.windowId, numMenuItems, 0);
    PutWindowTilemap(gMartInfo.windowId);
    CopyWindowToVram(gMartInfo.windowId, 1);

    return CreateTask(Task_ShopMenu, 8);
}

/*static*/ void SetShopMenuCallback(void (* callback)(void))
{
    gMartInfo.callback = callback;
}

/*static*/ void SetShopItemsForSale(const u16 *items)
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
    s8 inputCode = Menu_ProcessInputNoWrapAround();
    switch (inputCode)
    {
    case -2:
        break;
    case -1:
        PlaySE(SE_SELECT);
        HandleShopMenuQuit(taskId);
        break;
    default:
        gMartInfo.menuActions[inputCode].func.void_u8(taskId);
        break;
    }
}

void HandleShopMenuBuy(u8 taskId)
{
    s16 *taskData = gTasks[taskId].data;
    taskData[8] = (u32)CB2_InitBuyMenu >> 16;
    taskData[9] = (u32)CB2_InitBuyMenu;
    gTasks[taskId].func = Task_GoToBuyOrSellMenu;
    FadeScreen(1, 0);
}

void HandleShopMenuSell(u8 taskId)
{
    s16 *taskData = gTasks[taskId].data;
    taskData[8] = (u32)CB2_GoToSellMenu >> 16;
    taskData[9] = (u32)CB2_GoToSellMenu;
    gTasks[taskId].func = Task_GoToBuyOrSellMenu;
    FadeScreen(1, 0);
}

void CB2_ExitSellMenu(void)
{
    gFieldCallback = MapPostLoadHook_ExitBuyOrSellMenu;
    SetMainCallback2(CB2_ReturnToField);
}

/*static*/ void HandleShopMenuQuit(u8 taskId)
{
    sub_8198070(gMartInfo.windowId, 2);
    RemoveWindow(gMartInfo.windowId);
    SaveRecordedItemPurchasesForTVShow();
    ScriptContext2_Disable();
    DestroyTask(taskId);

    if (gMartInfo.callback)
        gMartInfo.callback();
}

static void Task_GoToBuyOrSellMenu(u8 taskId)
{
    s16 *taskData = gTasks[taskId].data;
    if (!gPaletteFade.active)
    {
        DestroyTask(taskId);
        SetMainCallback2((void *)((u16)taskData[8] << 16 | (u16)taskData[9]));
    }
}

void MapPostLoadHook_ExitBuyOrSellMenu(void)
{
    pal_fill_black();
    CreateTask(Task_ExitSellMenu, 8);
}

void Task_ExitSellMenu(u8 taskId)
{
    if (IsWeatherNotFadingIn() == TRUE)
    {
        if (gMartInfo.martType == MART_TYPE_2)
            DisplayItemMessageOnField(taskId, gText_CanIHelpWithAnythingElse, ReturnToShopMenuAfterExitingSellMenu);
        else
            DisplayItemMessageOnField(taskId, gText_AnythingElseICanHelp, ReturnToShopMenuAfterExitingSellMenu);
    }
}

void ReturnToShopMenuAfterExitingSellMenu(u8 taskId)
{
    CreateShopMenu(gMartInfo.martType);
    DestroyTask(taskId);
}

void CB2_BuyMenu(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    do_scheduled_bg_tilemap_copies_to_vram();
    UpdatePaletteFade();
}

void VBlankCB_BuyMenu(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

void CB2_InitBuyMenu(void)
{
    u8 taskId;

    switch (gMain.state)
    {
    case 0:
        SetVBlankHBlankCallbacksToNull();
        CpuFastFill(0, (void *)OAM, 0x400);
        ScanlineEffect_Stop();
        reset_temp_tile_data_buffers();
        FreeAllSpritePalettes();
        ResetPaletteFade();
        ResetSpriteData();
        ResetTasks();
        clear_scheduled_bg_copies_to_vram();
        gShopDataPtr = AllocZeroed(sizeof(struct ShopData));
        gShopDataPtr->unk200B = 0xFF;
        gShopDataPtr->unk200D = -1;
        gShopDataPtr->unk200E = -1;
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
        if (!free_temp_tile_data_buffers_if_possible())
            gMain.state++;
        break;
    default:
        BuyMenuDrawGraphics();
        BuyMenuAddScrollIndicatorArrows();
        taskId = CreateTask(Task_BuyMenu, 8);
        gTasks[taskId].data[7] = ListMenuInit(&gMultiuseListMenuTemplate, 0, 0);
        BlendPalettes(0xFFFFFFFF, 0x10, RGB_BLACK);
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0x10, 0, RGB_BLACK);
        SetVBlankCallback(VBlankCB_BuyMenu);
        SetMainCallback2(CB2_BuyMenu);
        break;
    }
}

void BuyMenuFreeMemory(void)
{
    Free(gShopDataPtr);
    Free(gUnknown_02039F74);
    Free(gUnknown_02039F78);
    FreeAllWindowBuffers();
}

void BuyMenuBuildListMenuTemplate(void)
{
    u16 i;
    u16 itemCount;

    gUnknown_02039F74 = Alloc((gMartInfo.itemCount + 1) * sizeof(*gUnknown_02039F74));
    gUnknown_02039F78 = Alloc((gMartInfo.itemCount + 1) * sizeof(*gUnknown_02039F78));
    for (i = 0; i < gMartInfo.itemCount; i++)
        BuyMenuSetListEntry(&gUnknown_02039F74[i], gMartInfo.itemList[i], gUnknown_02039F78[i]);

    StringCopy(gUnknown_02039F78[i], gText_Cancel2);
    gUnknown_02039F74[i].name = gUnknown_02039F78[i];
    gUnknown_02039F74[i].id = -2;

    gMultiuseListMenuTemplate = gUnknown_08589A48;
    gMultiuseListMenuTemplate.items = gUnknown_02039F74;
    gMultiuseListMenuTemplate.totalItems = gMartInfo.itemCount + 1;
    if (gMultiuseListMenuTemplate.totalItems > 8)
        gMultiuseListMenuTemplate.maxShowed = 8;
    else
        gMultiuseListMenuTemplate.maxShowed = gMultiuseListMenuTemplate.totalItems;

    gShopDataPtr->unk2004 = gMultiuseListMenuTemplate.maxShowed;
}

void BuyMenuSetListEntry(struct ListMenuItem *menuItem, u16 item, u8 *name)
{
    if (gMartInfo.martType == MART_TYPE_0)
        CopyItemName(item, name);
    else
        StringCopy(name, gDecorations[item].name);

    menuItem->name = name;
    menuItem->id = item;
}

void BuyMenuPrintItemDescriptionAndShowItemIcon(int item, bool8 onInit, struct ListMenu *list)
{
    const u8 *description;
    if (onInit != TRUE)
        PlaySE(SE_SELECT);

    if (item != -2)
        BuyMenuAddItemIcon(item, gShopDataPtr->unk200C);
    else
        BuyMenuAddItemIcon(-1, gShopDataPtr->unk200C);

    BuyMenuRemoveItemIcon(item, gShopDataPtr->unk200C ^ 1);
    gShopDataPtr->unk200C ^= 1;
    if (item != -2)
    {
        if (gMartInfo.martType == MART_TYPE_0)
            description = ItemId_GetDescription(item);
        else
            description = gDecorations[item].description;
    }
    else
    {
        description = gText_QuitShopping;
    }

    FillWindowPixelBuffer(2, 0);
    BuyMenuPrint(2, description, 3, 1, 0, 0);
}

void BuyMenuPrintPriceInList(u8 windowId, int item, u8 y)
{
    u8 x;

    if (item != -2)
    {
        if (gMartInfo.martType == MART_TYPE_0)
        {
            ConvertIntToDecimalStringN(
                gStringVar1,
                ItemId_GetPrice(item) >> GetPriceReduction(1),
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
        AddTextPrinterParameterized2(windowId, 7, x, y, 0, 0, gUnknown_08589AB3, -1, gStringVar4);
    }
}
