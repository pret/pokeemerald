#include "global.h"
#include "bg.h"
#include "decompress.h"
#include "decoration.h"
#include "field_player_avatar.h"
#include "field_screen.h"
#include "field_weather.h"
#include "fieldmap.h"
#include "gpu_regs.h"
#include "international_string_util.h"
#include "item.h"
#include "item_icon.h"
#include "list_menu.h"
#include "main.h"
#include "malloc.h"
#include "menu.h"
#include "menu_helpers.h"
#include "money.h"
#include "overworld.h"
#include "palette.h"
#include "scanline_effect.h"
#include "script.h"
#include "shop.h"
#include "sound.h"
#include "sprite.h"
#include "string_util.h"
#include "strings.h"
#include "text_window.h"
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
extern const struct BgTemplate gUnknown_08589A60[4];
extern const u8 gBuyMenuFrame_Gfx[];
extern const u8 gBuyMenuFrame_Tilemap[];
extern const u16 gMenuMoneyPal[];
extern const struct WindowTemplate gUnknown_08589A70[];
extern u8 gUnknown_08589AB0[][3];

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
void BuyMenuPrint(u8 windowId, const u8 *text, u8 x, u8 y, s8 speed, u8 colorSet);
void BuyMenuDrawMapGraphics(void);
void BuyMenuCopyMenuBgToBg1TilemapBuffer(void);
void BuyMenuCollectEventObjectData(void);
void BuyMenuDrawEventObjects(void);
void BuyMenuDrawMapBg(void);
bool8 BuyMenuCheckForOverlapWithMenuBg(u16, u16);
void BuyMenuDrawMapMetatile(s16, s16, u16*, u8);


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
        gShopDataPtr->scrollIndicatorsTaskId = 0xFF;
        gShopDataPtr->unk200D[0] = -1;
        gShopDataPtr->unk200D[1] = -1;
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
        AddTextPrinterParameterized4(windowId, 7, x, y, 0, 0, gUnknown_08589AB0[1], -1, gStringVar4);
    }
}

void BuyMenuAddScrollIndicatorArrows(void)
{
    if (gShopDataPtr->scrollIndicatorsTaskId == 0xFF && gMartInfo.itemCount + 1 > 8)
    {
        gShopDataPtr->scrollIndicatorsTaskId = AddScrollIndicatorArrowPairParameterized(
            SCROLL_ARROW_UP,
            0xAC,
            0xC,
            0x94,
            gMartInfo.itemCount - 7,
            0x834,
            0x834,
            &gShopDataPtr->unk2008);
    }
}

void BuyMenuRemoveScrollIndicatorArrows(void)
{
    if (gShopDataPtr->scrollIndicatorsTaskId != 0xFF)
    {
        RemoveScrollIndicatorArrowPair(gShopDataPtr->scrollIndicatorsTaskId);
        gShopDataPtr->scrollIndicatorsTaskId = 0xFF;
    }
}

void BuyMenuPrintCursor(u8 scrollIndicatorsTaskId, u8 colorSet)
{
    u8 y = ListMenuGetYCoordForPrintingArrowCursor(scrollIndicatorsTaskId);
    BuyMenuPrint(1, gText_SelectorArrow2, 0, y, 0, colorSet);
}

void BuyMenuAddItemIcon(u16 item, u8 iconSlot)
{
    u8 spriteId;
    u8 *spriteIdPtr = &gShopDataPtr->unk200D[iconSlot];
    if (*spriteIdPtr != 0xFF)
        return;

    if (gMartInfo.martType == MART_TYPE_0 || item == 0xFFFF)
    {
        spriteId = AddItemIconSprite(iconSlot + 0x83E, iconSlot + 0x83E, item);
        if (spriteId != MAX_SPRITES)
        {
            *spriteIdPtr = spriteId;
            gSprites[spriteId].pos2.x = 24;
            gSprites[spriteId].pos2.y = 88;
        }
    }
    else
    {
        spriteId = AddDecorationIconObject(item, 20, 84, 1, iconSlot + 0x83E, iconSlot + 0x83E);
        if (spriteId != MAX_SPRITES)
            *spriteIdPtr = spriteId;
    }
}

void BuyMenuRemoveItemIcon(u16 item, u8 iconSlot)
{
    u8 *spriteIdPtr = &gShopDataPtr->unk200D[iconSlot];
    if (*spriteIdPtr == 0xFF)
        return;

    FreeSpriteTilesByTag(iconSlot + 0x83E);
    FreeSpritePaletteByTag(iconSlot + 0x83E);
    DestroySprite(&gSprites[*spriteIdPtr]);
    *spriteIdPtr = 0xFF;
}

void BuyMenuInitBgs(void)
{
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, gUnknown_08589A60, ARRAY_COUNT(gUnknown_08589A60));
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

void BuyMenuDecompressBgGraphics(void)
{
    decompress_and_copy_tile_data_to_vram(1, gBuyMenuFrame_Gfx, 0x3A0, 0x3E3, 0);
    LZDecompressWram(gBuyMenuFrame_Tilemap, gShopDataPtr->tilemapBuffers[0]);
    LoadCompressedPalette(gMenuMoneyPal, 0xC0, 0x20);
}

void BuyMenuInitWindows(void)
{
    InitWindows(gUnknown_08589A70);
    DeactivateAllTextPrinters();
    LoadUserWindowBorderGfx(0, 1, 0xD0);
    LoadMessageBoxGfx(0, 0xA, 0xE0);
    PutWindowTilemap(0);
    PutWindowTilemap(1);
    PutWindowTilemap(2);
}

void BuyMenuPrint(u8 windowId, const u8 *text, u8 x, u8 y, s8 speed, u8 colorSet)
{
    AddTextPrinterParameterized4(windowId, 1, x, y, 0, 0, gUnknown_08589AB0[colorSet], speed, text);
}

void BuyMenuDisplayMessage(u8 taskId, const u8 *text, TaskFunc callback)
{
    DisplayMessageAndContinueTask(taskId, 5, 10, 14, 1, GetPlayerTextSpeed(), text, callback);
    schedule_bg_copy_tilemap_to_vram(0);
}

void BuyMenuDrawGraphics(void)
{
    BuyMenuDrawMapGraphics();
    BuyMenuCopyMenuBgToBg1TilemapBuffer();
    AddMoneyLabelObject(19, 11);
    PrintMoneyAmountInMoneyBoxWithBorder(0, 1, 13, GetMoney(&gSaveBlock1Ptr->money));
    schedule_bg_copy_tilemap_to_vram(0);
    schedule_bg_copy_tilemap_to_vram(1);
    schedule_bg_copy_tilemap_to_vram(2);
    schedule_bg_copy_tilemap_to_vram(3);
}

void BuyMenuDrawMapGraphics(void)
{
    BuyMenuCollectEventObjectData();
    BuyMenuDrawEventObjects();
    BuyMenuDrawMapBg();
}

#ifdef NONMATCHING
// functionally equivalent, but couldn't get the loop variables using the 
// stack correctly. Might be related to the tileset metatiles type.
void BuyMenuDrawMapBg(void)
{
    s16 i;
    s16 j;
    s16 x;
    s16 y;
    const struct MapLayout *mapLayout;
    u16 metatile, metatileLayerType;

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

            if (metatile < 0x200)
            {
                BuyMenuDrawMapMetatile(i, j, (u16*)mapLayout->primaryTileset->metatiles + metatile * 8, metatileLayerType);
            }
            else
            {
                BuyMenuDrawMapMetatile(i, j, (u16*)mapLayout->secondaryTileset->metatiles + ((metatile - 0x200) * 8), metatileLayerType);
            }
        }
    }
}
#else
NAKED
void BuyMenuDrawMapBg(void)
{
    asm_unified("\n\
    push {r4-r7,lr}\n\
    mov r7, r10\n\
    mov r6, r9\n\
    mov r5, r8\n\
    push {r5-r7}\n\
    sub sp, 0x4\n\
    ldr r0, =gMapHeader\n\
    ldr r0, [r0]\n\
    mov r9, r0\n\
    mov r4, sp\n\
    adds r4, 0x2\n\
    mov r0, sp\n\
    adds r1, r4, 0\n\
    bl GetXYCoordsOneStepInFrontOfPlayer\n\
    mov r1, sp\n\
    mov r0, sp\n\
    ldrh r0, [r0]\n\
    subs r0, 0x4\n\
    strh r0, [r1]\n\
    ldrh r0, [r4]\n\
    subs r0, 0x4\n\
    strh r0, [r4]\n\
    movs r1, 0\n\
    mov r10, r4\n\
_080E05B6:\n\
    movs r4, 0\n\
    lsls r7, r1, 16\n\
    asrs r0, r7, 16\n\
    mov r8, r0\n\
_080E05BE:\n\
    mov r0, sp\n\
    movs r1, 0\n\
    ldrsh r0, [r0, r1]\n\
    lsls r4, 16\n\
    asrs r5, r4, 16\n\
    adds r0, r5\n\
    mov r2, r10\n\
    movs r3, 0\n\
    ldrsh r1, [r2, r3]\n\
    add r1, r8\n\
    bl MapGridGetMetatileIdAt\n\
    lsls r0, 16\n\
    lsrs r6, r0, 16\n\
    adds r0, r5, 0\n\
    mov r1, r8\n\
    bl BuyMenuCheckForOverlapWithMenuBg\n\
    lsls r0, 24\n\
    lsrs r0, 24\n\
    cmp r0, 0x1\n\
    bne _080E0608\n\
    mov r0, sp\n\
    movs r1, 0\n\
    ldrsh r0, [r0, r1]\n\
    adds r0, r5\n\
    mov r2, r10\n\
    movs r3, 0\n\
    ldrsh r1, [r2, r3]\n\
    add r1, r8\n\
    bl MapGridGetMetatileLayerTypeAt\n\
    lsls r0, 24\n\
    lsrs r5, r0, 24\n\
    b _080E060A\n\
    .pool\n\
_080E0608:\n\
    movs r5, 0x1\n\
_080E060A:\n\
    ldr r0, =0x000001ff\n\
    cmp r6, r0\n\
    bhi _080E062C\n\
    asrs r0, r4, 16\n\
    mov r2, r9\n\
    ldr r1, [r2, 0x10]\n\
    lsls r3, r6, 4\n\
    ldr r2, [r1, 0xC]\n\
    adds r2, r3\n\
    asrs r1, r7, 16\n\
    adds r3, r5, 0\n\
    bl BuyMenuDrawMapMetatile\n\
    b _080E0644\n\
    .pool\n\
_080E062C:\n\
    asrs r0, r4, 16\n\
    mov r3, r9\n\
    ldr r2, [r3, 0x14]\n\
    ldr r3, =0xfffffe00\n\
    adds r1, r6, r3\n\
    lsls r1, 4\n\
    ldr r2, [r2, 0xC]\n\
    adds r2, r1\n\
    asrs r1, r7, 16\n\
    adds r3, r5, 0\n\
    bl BuyMenuDrawMapMetatile\n\
_080E0644:\n\
    movs r1, 0x80\n\
    lsls r1, 9\n\
    adds r0, r4, r1\n\
    lsrs r4, r0, 16\n\
    asrs r0, 16\n\
    cmp r0, 0xE\n\
    ble _080E05BE\n\
    adds r0, r7, r1\n\
    lsrs r1, r0, 16\n\
    asrs r0, 16\n\
    cmp r0, 0x9\n\
    ble _080E05B6\n\
    add sp, 0x4\n\
    pop {r3-r5}\n\
    mov r8, r3\n\
    mov r9, r4\n\
    mov r10, r5\n\
    pop {r4-r7}\n\
    pop {r0}\n\
    bx r0\n\
    .pool");
}
#endif // NONMATCHING
