#include "global.h"
#include "main.h"
#include "battle_controllers.h"
#include "bg.h"
#include "field_effect.h"
#include "field_weather.h"
#include "gpu_regs.h"
#include "malloc.h"
#include "menu.h"
#include "overworld.h"
#include "menu_helpers.h"
#include "overworld.h"
#include "palette.h"
#include "party_menu.h"
#include "scanline_effect.h"
#include "script.h"
#include "task.h"
#include "decompress.h"
#include "graphics.h"
#include "string_util.h"
#include "list_menu.h"
#include "strings.h"
#include "item.h"
#include "sound.h"
#include "item_menu.h"
#include "mail.h"
#include "item_use.h"
#include "event_data.h"
#include "text_window.h"
#include "international_string_util.h"
#include "constants/items.h"
#include "constants/rgb.h"
#include "constants/songs.h"

EWRAM_DATA struct
{
    MainCallback callback2;
    u8 tilemapBuffer[0x800];
    u8 itemsSpriteIds[PYRAMID_BAG_ITEMS_COUNT + 1];
    u8 windowIds[5];
    u8 unk814;
    u8 unk815;
    u8 unk816;
    const u8 *menuActionIds;
    u8 filler81C;
    u8 filler81D;
    u8 filler81E;
    u8 filler81F;
    u8 menuActionsCount;
    u8 listMenuCount;
    u8 listMenuMaxShown;
    struct ListMenuItem bagListItems[PYRAMID_BAG_ITEMS_COUNT + 1];
    u8 itemStrings[PYRAMID_BAG_ITEMS_COUNT + 1][ITEM_NAME_LENGTH + 10];
    s16 unk984;
    u8 filler986[0x98C - 0x986];
} *gUnknown_0203CF2C = NULL;

EWRAM_DATA struct
{
    void (*callback)(void);
    u8 unk4;
    u16 unk6;
    u16 unk8;
} gUnknown_0203CF30 = {0};

extern const struct BgTemplate gUnknown_0861F2B4[3];
extern const struct WindowTemplate gUnknown_0861F328[];
extern const struct WindowTemplate gUnknown_0861F350[];
extern const struct CompressedSpriteSheet gUnknown_0861F3CC;
extern const struct ListMenuTemplate gUnknown_0861F2C0;
extern const u8 gUnknown_0861F310[1];
extern const u8 gUnknown_0861F308[4];
extern const u8 gUnknown_0861F30E[2];
extern const u8 gUnknown_0861F30C[2];
extern const struct MenuAction gUnknown_0861F2D8[];
extern const struct YesNoFuncTable gUnknown_0861F314;
extern const u16 gUnknown_0860F074[];
extern const u8 gUnknown_0861F31C[][3];

// This file's functions.
void sub_81C4F98(u8 a0, void (*callback)(void));
void sub_81C4F44(u8 taskId);
void Task_HandlePyramidBagInput(u8 taskId);
void sub_81C5B4C(u8 taskId);
void sub_81C67CC(u8 taskId);
void sub_81C5D20(u8 taskId);
void sub_81C674C(u8 taskId);
void sub_81C5FE4(u8 taskId);
void sub_81C5F68(u8 taskId);
void sub_81C6714(u8 taskId);
void sub_81C66EC(u8 taskId);
void sub_81C629C(u8 taskId);
void sub_81C6350(u8 taskId);
void sub_81C64B4(u8 taskId);
void sub_81C65CC(u8 taskId);
void sub_81C66AC(u8 taskId);
void sub_81C6964(u8 taskId);
void sub_81C68B0(u8 taskId);
void sub_81C6A14(u8 taskId);
void sub_81C504C(void);
bool8 sub_81C5078(void);
void sub_81C51DC(void);
bool8 sub_81C5238(void);
void SetBagItemsListTemplate(void);
void sub_81C5674(void);
void sub_81C56F8(void);
void sub_81C5924(void);
void sub_81C59BC(void);
void sub_81C5A20(void);
void sub_81C6BD8(void);
void sub_81C6EF4(void);
void sub_81C700C(void);
void sub_81C6E98(void);
void sub_81C6F20(void);
void sub_81C6404(void);
void sub_81C6E1C(void);
void ShowItemImage(u16 itemId, u8 tagIdAdder);
void PyramidBag_CopyItemName(u8 *dst, u16 itemId);
void sub_81C6FF8(u8 arg0);
void PrintItemDescription(s32 listMenuId);
void sub_81C5AB8(u8 y, u8 arg1);
void PrintOnWindow_Font1(u8 windowId, const u8 *src, u8 x, u8 y, u8 letterSpacing, u8 lineSpacing, u8 speed, u8 colorTableId);
void PrintOnWindow_Font7(u8 windowId, const u8 *src, u8 x, u8 y, u8 letterSpacing, u8 lineSpacing, u8 speed, u8 colorTableId);
u8 sub_81C6D24(u8 windowArrayId);
void sub_81C6D6C(u8 windowArrayId);
void sub_81C5EAC(u8 windowId);
void sub_81C5F08(u8 windowId, u8 horizontalCount, u8 verticalCount);
bool8 sub_81C616C(s8 arg0);
void sub_81C6DAC(u8 taskId, const struct YesNoFuncTable *yesNoTable);
void sub_81C6CEC(u8 windowId);
void sub_81C704C(u8 arg0);
void sub_81C7028(u8 arg0);

// code
void sub_81C4EEC(void)
{
    gUnknown_0203CF30.unk6 = 0;
    gUnknown_0203CF30.unk8 = 0;
}

void sub_81C4EFC(void)
{
    sub_81C4F98(0, CB2_ReturnToFieldWithOpenMenu);
}

void sub_81C4F10(void)
{
    sub_81C4F98(1, SetCB2ToReshowScreenAfterMenu2);
}

void sub_81C4F24(void)
{
    ScriptContext2_Enable();
    FadeScreen(1, 0);
    CreateTask(sub_81C4F44, 10);
}

void sub_81C4F44(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        overworld_free_bg_tilemaps();
        gFieldCallback2 = hm_add_c3_without_phase_2;
        sub_81C4F98(3, CB2_ReturnToField);
        DestroyTask(taskId);
    }
}

void sub_81C4F84(void)
{
    sub_81C4F98(4, gUnknown_0203CF30.callback);
}

void sub_81C4F98(u8 a0, void (*callback)(void))
{
    gUnknown_0203CF2C = AllocZeroed(sizeof(*gUnknown_0203CF2C));

    if (a0 != 4)
        gUnknown_0203CF30.unk4 = a0;

    if (callback != NULL)
        gUnknown_0203CF30.callback = callback;

    gUnknown_0203CF2C->callback2 = NULL;
    gUnknown_0203CF2C->unk814 = 0xFF;
    gUnknown_0203CF2C->unk816 = 0xFF;

    memset(gUnknown_0203CF2C->itemsSpriteIds, 0xFF, sizeof(gUnknown_0203CF2C->itemsSpriteIds));
    memset(gUnknown_0203CF2C->windowIds, 0xFF, sizeof(gUnknown_0203CF2C->windowIds));

    SetMainCallback2(sub_81C504C);
}

void sub_81C501C(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    do_scheduled_bg_tilemap_copies_to_vram();
    UpdatePaletteFade();
}

void sub_81C5038(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

void sub_81C504C(void)
{
    while (sub_81221EC() != TRUE && sub_81C5078() != TRUE && sub_81221AC() != TRUE);
}

bool8 sub_81C5078(void)
{
    switch (gMain.state)
    {
        case 0:
            SetVBlankHBlankCallbacksToNull();
            clear_scheduled_bg_copies_to_vram();
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
            if (!sub_81221AC())
            {
                ResetTasks();
            }
            gMain.state++;
            break;
        case 6:
            sub_81C51DC();
            gUnknown_0203CF2C->unk984 = 0;
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
            sub_81C5674();
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

void sub_81C51DC(void)
{
    ResetVramOamAndBgCntRegs();
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, gUnknown_0861F2B4, ARRAY_COUNT(gUnknown_0861F2B4));
    SetBgTilemapBuffer(2, gUnknown_0203CF2C->tilemapBuffer);
    ResetAllBgsCoordinates();
    schedule_bg_copy_tilemap_to_vram(2);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0 |
                                  DISPCNT_OBJ_1D_MAP |
                                  DISPCNT_OBJ_ON);
    ShowBg(0);
    ShowBg(1);
    ShowBg(2);
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
}

extern const u8 gUnknown_08D9AE04[];
extern const u8 gUnknown_08D9AF44[];

bool8 sub_81C5238(void)
{
    switch (gUnknown_0203CF2C->unk984)
    {
    case 0:
        reset_temp_tile_data_buffers();
        decompress_and_copy_tile_data_to_vram(2, gBagScreen_Gfx, 0, 0, 0);
        gUnknown_0203CF2C->unk984++;
        break;
    case 1:
        if (free_temp_tile_data_buffers_if_possible() != TRUE)
        {
            LZDecompressWram(gUnknown_08D9AE04, gUnknown_0203CF2C->tilemapBuffer);
            gUnknown_0203CF2C->unk984++;
        }
        break;
    case 2:
        LoadCompressedPalette(gUnknown_08D9AF44, 0, 0x20);
        gUnknown_0203CF2C->unk984++;
        break;
    case 3:
        LoadCompressedObjectPic(&gUnknown_0861F3CC);
        gUnknown_0203CF2C->unk984++;
        break;
    case 4:
        sub_81C6E98();
        gUnknown_0203CF2C->unk984++;
        break;
    default:
        LoadListMenuArrowsGfx();
        gUnknown_0203CF2C->unk984 = 0;
        return TRUE;
    }

    return FALSE;
}

void SetBagItemsListTemplate(void)
{
    u16 i;
    u16 *pyramidItems = gSaveBlock2Ptr->frontier.pyramidBag.itemId[gSaveBlock2Ptr->frontier.lvlMode];

    for (i = 0; i < gUnknown_0203CF2C->listMenuCount - 1; i++)
    {
        PyramidBag_CopyItemName(gUnknown_0203CF2C->itemStrings[i], pyramidItems[i]);
        gUnknown_0203CF2C->bagListItems[i].name = gUnknown_0203CF2C->itemStrings[i];
        gUnknown_0203CF2C->bagListItems[i].id = i;
    }
    StringCopy(gUnknown_0203CF2C->itemStrings[i], gText_CloseBag);
    gUnknown_0203CF2C->bagListItems[i].name = gUnknown_0203CF2C->itemStrings[i];
    gUnknown_0203CF2C->bagListItems[i].id = LIST_B_PRESSED;
    gMultiuseListMenuTemplate = gUnknown_0861F2C0;
    gMultiuseListMenuTemplate.totalItems = gUnknown_0203CF2C->listMenuCount;
    gMultiuseListMenuTemplate.items = gUnknown_0203CF2C->bagListItems;
    gMultiuseListMenuTemplate.maxShowed = gUnknown_0203CF2C->listMenuMaxShown;
}

void PyramidBag_CopyItemName(u8 *dst, u16 itemId)
{
    if (ItemId_GetPocket(itemId) == POCKET_BERRIES)
    {
        ConvertIntToDecimalStringN(gStringVar1, ITEM_TO_BERRY(itemId), STR_CONV_MODE_LEADING_ZEROS, 2);
        CopyItemName(itemId, gStringVar2);
        StringExpandPlaceholders(dst, gText_UnkF908Var1Clear7Var2);
    }
    else
    {
        CopyItemName(itemId, dst);
    }
}

void PyramidBagMoveCursorFunc(s32 itemIndex, bool8 onInit, struct ListMenu *list)
{
    if (onInit != TRUE)
    {
        PlaySE(SE_SELECT);
        sub_81C6F20();
    }
    if (gUnknown_0203CF2C->unk814 == 0xFF)
    {
        sub_81C6FF8(gUnknown_0203CF2C->unk815 ^ 1);
        if (itemIndex != LIST_B_PRESSED)
            ShowItemImage(gSaveBlock2Ptr->frontier.pyramidBag.itemId[gSaveBlock2Ptr->frontier.lvlMode][itemIndex], gUnknown_0203CF2C->unk815);
        else
            ShowItemImage(0xFFFF, gUnknown_0203CF2C->unk815);
        gUnknown_0203CF2C->unk815 ^= 1;
        PrintItemDescription(itemIndex);
    }
}

void PrintItemQuantity(u8 windowId, s32 itemIndex, u8 y)
{
    s32 xAlign;
    if (itemIndex == LIST_B_PRESSED)
        return;

    if (gUnknown_0203CF2C->unk814 != 0xFF)
    {
        if (gUnknown_0203CF2C->unk814 == (u8)(itemIndex))
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

void PrintItemDescription(s32 listMenuId)
{
    const u8 *desc;
    if (listMenuId != LIST_B_PRESSED)
    {
        desc = ItemId_GetDescription(gSaveBlock2Ptr->frontier.pyramidBag.itemId[gSaveBlock2Ptr->frontier.lvlMode][listMenuId]);
    }
    else
    {
        StringCopy(gStringVar1, gReturnToXStringsTable2[gUnknown_0203CF30.unk4]);
        StringExpandPlaceholders(gStringVar4, gText_ReturnToVar1);
        desc = gStringVar4;
    }
    FillWindowPixelBuffer(1, 0);
    PrintOnWindow_Font1(1, desc, 3, 0, 0, 1, 0, 0);
}

void sub_81C5674(void)
{
    if (gUnknown_0203CF2C->unk816 == 0xFF)
        gUnknown_0203CF2C->unk816 = AddScrollIndicatorArrowPairParameterized(2, 172, 12, 148, gUnknown_0203CF2C->listMenuCount - gUnknown_0203CF2C->listMenuMaxShown, 0xB5E, 0xB5E, &gUnknown_0203CF30.unk8);
}

void sub_81C56CC(void)
{
    if (gUnknown_0203CF2C->unk816 != 0xFF)
    {
        RemoveScrollIndicatorArrowPair(gUnknown_0203CF2C->unk816);
        gUnknown_0203CF2C->unk816 = 0xFF;
    }
}

void sub_81C56F8(void)
{
    u8 taskId = CreateTask(Task_HandlePyramidBagInput, 0);
    s16 *data = gTasks[taskId].data;
    data[0] = ListMenuInit(&gMultiuseListMenuTemplate, gUnknown_0203CF30.unk8, gUnknown_0203CF30.unk6);
}

void SwapItems(u8 id1, u8 id2)
{
    u16 temp;
    u16 *itemIds = gSaveBlock2Ptr->frontier.pyramidBag.itemId[gSaveBlock2Ptr->frontier.lvlMode];
    u8 *quantities = gSaveBlock2Ptr->frontier.pyramidBag.quantity[gSaveBlock2Ptr->frontier.lvlMode];

    SWAP(itemIds[id1], itemIds[id2], temp);
    SWAP(quantities[id1], quantities[id2], temp);
}

void MovePyramidBagItemSlotInList(u8 from, u8 to)
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

void CompactItems(void)
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
    gUnknown_0203CF2C->listMenuCount = 0;
    for (i = 0; i < PYRAMID_BAG_ITEMS_COUNT; i++)
    {
        if (itemIds[i] != 0)
            gUnknown_0203CF2C->listMenuCount++;
    }
    gUnknown_0203CF2C->listMenuCount++;
    if (gUnknown_0203CF2C->listMenuCount > 8)
        gUnknown_0203CF2C->listMenuMaxShown = 8;
    else
        gUnknown_0203CF2C->listMenuMaxShown = gUnknown_0203CF2C->listMenuCount;
}

void sub_81C59BC(void)
{
    if (gUnknown_0203CF30.unk8 != 0 && gUnknown_0203CF30.unk8 + gUnknown_0203CF2C->listMenuMaxShown > gUnknown_0203CF2C->listMenuCount)
        gUnknown_0203CF30.unk8 = gUnknown_0203CF2C->listMenuCount - gUnknown_0203CF2C->listMenuMaxShown;
    if (gUnknown_0203CF30.unk8 + gUnknown_0203CF30.unk6 >= gUnknown_0203CF2C->listMenuCount)
    {
        if (gUnknown_0203CF2C->listMenuCount == 0)
            gUnknown_0203CF30.unk6 = 0;
        else
            gUnknown_0203CF30.unk6 = gUnknown_0203CF2C->listMenuCount - 1;
    }
}

void sub_81C5A20(void)
{
    u8 i;

    if (gUnknown_0203CF30.unk6 > 4)
    {
        for (i = 0; i <= gUnknown_0203CF30.unk6 - 4; i++)
        {
            if (gUnknown_0203CF30.unk8 + gUnknown_0203CF2C->listMenuMaxShown == gUnknown_0203CF2C->listMenuCount)
            {
                // daycare.c sends its regards.
                break;
            }
            gUnknown_0203CF30.unk6--;
            gUnknown_0203CF30.unk8++;
        }
    }
}

void sub_81C5A98(u8 listMenuTaskId, u8 arg1)
{
    u8 y = ListMenuGetYCoordForPrintingArrowCursor(listMenuTaskId);
    sub_81C5AB8(y, arg1);
}

void sub_81C5AB8(u8 y, u8 arg1)
{
    if (arg1 == 0xFF)
        FillWindowPixelRect(0, 0, 0, y, GetMenuCursorDimensionByFont(1, 0), GetMenuCursorDimensionByFont(1, 1));
    else
        PrintOnWindow_Font1(0, gText_SelectorArrow2, 0, y, 0, 0, 0, arg1);
}

void sub_81C5B14(u8 taskId)
{
    BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 0x10, RGB_BLACK);
    gTasks[taskId].func = sub_81C5B4C;
}

void sub_81C5B4C(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    if (!gPaletteFade.active)
    {
        DestroyListMenuTask(data[0], &gUnknown_0203CF30.unk8, &gUnknown_0203CF30.unk6);
        if (gUnknown_0203CF2C->callback2 != NULL)
            SetMainCallback2(gUnknown_0203CF2C->callback2);
        else
            SetMainCallback2(gUnknown_0203CF30.callback);
        sub_81C56CC();
        ResetSpriteData();
        FreeAllSpritePalettes();
        FreeAllWindowBuffers();
        Free(gUnknown_0203CF2C);
        DestroyTask(taskId);
    }
}

void Task_HandlePyramidBagInput(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    if (sub_81221EC() != TRUE && !gPaletteFade.active)
    {
        if (gMain.newKeys & SELECT_BUTTON)
        {
            if (gUnknown_0203CF30.unk4 != 2)
            {
                ListMenuGetScrollAndRow(data[0], &gUnknown_0203CF30.unk8, &gUnknown_0203CF30.unk6);
                if (gUnknown_0203CF30.unk8 + gUnknown_0203CF30.unk6 != gUnknown_0203CF2C->listMenuCount - 1)
                {
                    PlaySE(SE_SELECT);
                    sub_81C67CC(taskId);
                }
            }
        }
        else
        {
            s32 listId = ListMenuHandleInputGetItemId(data[0]);
            ListMenuGetScrollAndRow(data[0], &gUnknown_0203CF30.unk8, &gUnknown_0203CF30.unk6);
            switch (listId)
            {
            case LIST_NOTHING_CHOSEN:
                break;
            case LIST_B_PRESSED:
                PlaySE(SE_SELECT);
                gSpecialVar_ItemId = 0;
                sub_81C5B14(taskId);
                break;
            default:
                PlaySE(SE_SELECT);
                gSpecialVar_ItemId = gSaveBlock2Ptr->frontier.pyramidBag.itemId[gSaveBlock2Ptr->frontier.lvlMode][listId];
                data[1] = listId;
                data[2] = gSaveBlock2Ptr->frontier.pyramidBag.quantity[gSaveBlock2Ptr->frontier.lvlMode][listId];
                if (gUnknown_0203CF30.unk4 == 2)
                    sub_81C674C(taskId);
                else
                    sub_81C5D20(taskId);
                break;
            }
        }
    }
}

void sub_81C5D20(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    sub_81C56CC();
    sub_81C5A98(data[0], 1);
    switch (gUnknown_0203CF30.unk4)
    {
    default:
        gUnknown_0203CF2C->menuActionIds = gUnknown_0861F308;
        gUnknown_0203CF2C->menuActionsCount = ARRAY_COUNT(gUnknown_0861F308);
        break;
    case 1:
        if (ItemId_GetBattleUsage(gSpecialVar_ItemId))
        {
            gUnknown_0203CF2C->menuActionIds = gUnknown_0861F30E;
            gUnknown_0203CF2C->menuActionsCount = ARRAY_COUNT(gUnknown_0861F30E);
        }
        else
        {
            gUnknown_0203CF2C->menuActionIds = gUnknown_0861F310;
            gUnknown_0203CF2C->menuActionsCount = ARRAY_COUNT(gUnknown_0861F310);
        }
        break;
    case 3:
        gUnknown_0203CF2C->menuActionIds = gUnknown_0861F30C;
        gUnknown_0203CF2C->menuActionsCount = ARRAY_COUNT(gUnknown_0861F30C);
        break;
    }

    CopyItemName(gSpecialVar_ItemId, gStringVar1);
    StringExpandPlaceholders(gStringVar4, gText_Var1IsSelected);
    FillWindowPixelBuffer(1, 0);
    PrintOnWindow_Font1(1, gStringVar4, 3, 0, 0, 1, 0, 0);
    if (gUnknown_0203CF2C->menuActionsCount == 1)
        sub_81C5EAC(sub_81C6D24(0));
    else if (gUnknown_0203CF2C->menuActionsCount == 2)
        sub_81C5EAC(sub_81C6D24(1));
    else
        sub_81C5F08(sub_81C6D24(2), 2, 2);

    if (gUnknown_0203CF2C->menuActionsCount == 4)
        gTasks[taskId].func = sub_81C5FE4;
    else
        gTasks[taskId].func = sub_81C5F68;
}

void sub_81C5EAC(u8 windowId)
{
    AddItemMenuActionTextPrinters(windowId, 7, 8, 1, 0, 0x10, gUnknown_0203CF2C->menuActionsCount, gUnknown_0861F2D8, gUnknown_0203CF2C->menuActionIds);
    InitMenuInUpperLeftCornerPlaySoundWhenAPressed(windowId, gUnknown_0203CF2C->menuActionsCount, 0);
}

void sub_81C5F08(u8 windowId, u8 horizontalCount, u8 verticalCount)
{
    sub_8198DBC(windowId, 7, 8, 1, 0x38, horizontalCount, verticalCount, gUnknown_0861F2D8, gUnknown_0203CF2C->menuActionIds);
    sub_8199944(windowId, 0x38, horizontalCount, verticalCount, 0);
}

void sub_81C5F68(u8 taskId)
{
    if (sub_81221EC() != TRUE)
    {
        s32 id = Menu_ProcessInputNoWrapAround();
        switch (id)
        {
        case -2:
            break;
        case -1:
            PlaySE(SE_SELECT);
            gUnknown_0861F2D8[3].func.void_u8(taskId);
            break;
        default:
            PlaySE(SE_SELECT);
            if (gUnknown_0861F2D8[gUnknown_0203CF2C->menuActionIds[id]].func.void_u8 != NULL)
                gUnknown_0861F2D8[gUnknown_0203CF2C->menuActionIds[id]].func.void_u8(taskId);
            break;
        }
    }
}

void sub_81C5FE4(u8 taskId)
{
    if (sub_81221EC() != TRUE)
    {
        s8 id = GetMenuCursorPos();
        if (gMain.newKeys & DPAD_UP)
        {
            if (id > 0 && sub_81C616C(id - 2))
            {
                PlaySE(SE_SELECT);
                sub_8199134(0, -1);
            }
        }
        else if (gMain.newKeys & DPAD_DOWN)
        {
            if (id < gUnknown_0203CF2C->menuActionsCount - 2 && sub_81C616C(id + 2))
            {
                PlaySE(SE_SELECT);
                sub_8199134(0, 1);
            }
        }
        else if (gMain.newKeys & DPAD_LEFT || GetLRKeysState() == 1)
        {
            if (id & 1 && sub_81C616C(id - 1))
            {
                PlaySE(SE_SELECT);
                sub_8199134(-1, 0);
            }
        }
        else if (gMain.newKeys & DPAD_RIGHT || GetLRKeysState() == 2)
        {
            if (!(id & 1) && sub_81C616C(id + 1))
            {
                PlaySE(SE_SELECT);
                sub_8199134(1, 0);
            }
        }
        else if (gMain.newKeys & A_BUTTON)
        {
            PlaySE(SE_SELECT);
            if (gUnknown_0861F2D8[gUnknown_0203CF2C->menuActionIds[id]].func.void_u8 != NULL)
                gUnknown_0861F2D8[gUnknown_0203CF2C->menuActionIds[id]].func.void_u8(taskId);
        }
        else if (gMain.newKeys & B_BUTTON)
        {
            PlaySE(SE_SELECT);
            gUnknown_0861F2D8[3].func.void_u8(taskId);
        }
    }
}

bool8 sub_81C616C(s8 arg0)
{
    if (arg0 < 0)
        return FALSE;
    else if (arg0 > gUnknown_0203CF2C->menuActionsCount)
        return FALSE;
    else if (gUnknown_0203CF2C->menuActionIds[arg0] == 5)
        return FALSE;
    else
        return TRUE;
}

void sub_81C61A8(void)
{
    if (gUnknown_0203CF2C->menuActionsCount == 1)
        sub_81C6D6C(0);
    else if (gUnknown_0203CF2C->menuActionsCount == 2)
        sub_81C6D6C(1);
    else
        sub_81C6D6C(2);
}

void sub_81C61E0(u8 taskId)
{
    u8 pocketId = ItemId_GetPocket(gSpecialVar_ItemId);

    if (pocketId == POCKET_KEY_ITEMS
        || pocketId == POCKET_POKE_BALLS
        || pocketId == POCKET_TM_HM
        || ItemIsMail(gSpecialVar_ItemId) == TRUE)
    {
        sub_81C61A8();
        DisplayItemMessageInBattlePyramid(taskId, gText_DadsAdvice, sub_81C6714);
    }
    else if (ItemId_GetFieldFunc(gSpecialVar_ItemId) != NULL)
    {
        sub_81C61A8();
        FillWindowPixelBuffer(1, 0);
        schedule_bg_copy_tilemap_to_vram(0);
        ItemId_GetFieldFunc(gSpecialVar_ItemId)(taskId);
    }
}

void sub_81C6258(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    sub_81C61A8();
    PrintItemDescription(data[1]);
    schedule_bg_copy_tilemap_to_vram(0);
    schedule_bg_copy_tilemap_to_vram(1);
    sub_81C5A98(data[0], 0);
    sub_81C629C(taskId);
}

void sub_81C629C(u8 taskId)
{
    sub_81C5674();
    gTasks[taskId].func = Task_HandlePyramidBagInput;
}

void sub_81C62C4(u8 taskId)
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
        FillWindowPixelBuffer(1, 0);
        PrintOnWindow_Font1(1, gStringVar4, 3, 0, 0, 1, 0, 0);
        sub_81C6404();
        gTasks[taskId].func = sub_81C64B4;
    }
}

void sub_81C6350(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    CopyItemName(gSpecialVar_ItemId, gStringVar1);
    ConvertIntToDecimalStringN(gStringVar2, data[8], STR_CONV_MODE_LEFT_ALIGN, 2);
    StringExpandPlaceholders(gStringVar4, gText_ConfirmTossItems);
    FillWindowPixelBuffer(1, 0);
    PrintOnWindow_Font1(1, gStringVar4, 3, 0, 0, 1, 0, 0);
    sub_81C6DAC(taskId, &gUnknown_0861F314);
}

void sub_81C63D0(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    PrintItemDescription(data[1]);
    sub_81C5A98(data[0], 0);
    sub_81C629C(taskId);
}

void sub_81C6404(void)
{
    s32 x;

    ConvertIntToDecimalStringN(gStringVar1, 1, STR_CONV_MODE_LEADING_ZEROS, 2);
    StringExpandPlaceholders(gStringVar4, gText_xVar1);
    sub_81C6CEC(3);
    x = GetStringCenterAlignXOffset(1, gStringVar4, 0x28);
    PrintTextOnWindow(3, 1, gStringVar4, x, 2, 0, NULL);
}

void sub_81C645C(s16 value)
{
    s32 x;

    ConvertIntToDecimalStringN(gStringVar1, value, STR_CONV_MODE_LEADING_ZEROS, 2);
    StringExpandPlaceholders(gStringVar4, gText_xVar1);
    x = GetStringCenterAlignXOffset(1, gStringVar4, 0x28);
    PrintTextOnWindow(3, 1, gStringVar4, x, 2, 0, NULL);
}

void sub_81C64B4(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    if (AdjustQuantityAccordingToDPadInput(&data[8], data[2]) == TRUE)
    {
        sub_81C645C(data[8]);
    }
    else if (gMain.newKeys & A_BUTTON)
    {
        PlaySE(SE_SELECT);
        sub_8198070(3, 0);
        ClearWindowTilemap(3);
        schedule_bg_copy_tilemap_to_vram(1);
        sub_81C6350(taskId);
    }
    else if (gMain.newKeys & B_BUTTON)
    {
        PlaySE(SE_SELECT);
        sub_8198070(3, 0);
        ClearWindowTilemap(3);
        schedule_bg_copy_tilemap_to_vram(1);
        sub_81C63D0(taskId);
    }
}

void sub_81C654C(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    CopyItemName(gSpecialVar_ItemId, gStringVar1);
    ConvertIntToDecimalStringN(gStringVar2, data[8], STR_CONV_MODE_LEFT_ALIGN, 2);
    StringExpandPlaceholders(gStringVar4, gText_ThrewAwayVar2Var1s);
    FillWindowPixelBuffer(1, 0);
    PrintOnWindow_Font1(1, gStringVar4, 3, 0, 0, 1, 0, 0);
    gTasks[taskId].func = sub_81C65CC;
}

void sub_81C65CC(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    u16 *scrollOffset = &gUnknown_0203CF30.unk8;
    u16 *selectedRow = &gUnknown_0203CF30.unk6;

    if (gMain.newKeys & (A_BUTTON | B_BUTTON))
    {
        PlaySE(SE_SELECT);
        RemovePyramidBagItem(gSpecialVar_ItemId, data[8]);
        DestroyListMenuTask(data[0], scrollOffset, selectedRow);
        sub_81C5924();
        sub_81C59BC();
        SetBagItemsListTemplate();
        data[0] = ListMenuInit(&gMultiuseListMenuTemplate, *scrollOffset, *selectedRow);
        schedule_bg_copy_tilemap_to_vram(0);
        sub_81C629C(taskId);
    }
}

void sub_81C6648(u8 taskId)
{
    sub_81C61A8();
    if (ItemIsMail(gSpecialVar_ItemId) == TRUE)
    {
        DisplayItemMessageInBattlePyramid(taskId, gText_CantWriteMail, sub_81C66EC);
    }
    else if (!ItemId_GetImportance(gSpecialVar_ItemId))
    {
        gUnknown_0203CF2C->callback2 = sub_81B7F60;
        sub_81C5B14(taskId);
    }
    else
    {
        sub_81C66AC(taskId);
    }
}

void sub_81C66AC(u8 taskId)
{
    CopyItemName(gSpecialVar_ItemId, gStringVar1);
    StringExpandPlaceholders(gStringVar4, gText_Var1CantBeHeld);
    DisplayItemMessageInBattlePyramid(taskId, gStringVar4, sub_81C66EC);
}

void sub_81C66EC(u8 taskId)
{
    if (gMain.newKeys & A_BUTTON)
    {
        PlaySE(SE_SELECT);
        sub_81C6714(taskId);
    }
}

void sub_81C6714(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    sub_81C6E1C();
    PrintItemDescription(data[1]);
    sub_81C5A98(data[0], 0);
    sub_81C629C(taskId);
}

void sub_81C674C(u8 taskId)
{
    if (!itemid_80BF6D8_mail_related(gSpecialVar_ItemId))
        DisplayItemMessageInBattlePyramid(taskId, gText_CantWriteMail, sub_81C66EC);
    else if (!ItemId_GetImportance(gSpecialVar_ItemId))
        sub_81C5B14(taskId);
    else
        sub_81C66AC(taskId);
}

void sub_81C679C(u8 taskId)
{
    if (ItemId_GetBattleFunc(gSpecialVar_ItemId) != NULL)
    {
        sub_81C61A8();
        ItemId_GetBattleFunc(gSpecialVar_ItemId)(taskId);
    }
}

void sub_81C67CC(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    data[1] = gUnknown_0203CF30.unk8 + gUnknown_0203CF30.unk6;
    gUnknown_0203CF2C->unk814 = data[1];
    ListMenuSetUnkIndicatorsStructField(data[0], 0x10, 1);
    CopyItemName(gSaveBlock2Ptr->frontier.pyramidBag.itemId[gSaveBlock2Ptr->frontier.lvlMode][data[1]], gStringVar1);
    StringExpandPlaceholders(gStringVar4, gText_MoveVar1Where);
    FillWindowPixelBuffer(1, 0);
    PrintOnWindow_Font1(1, gStringVar4, 3, 0, 0, 1, 0, 0);
    sub_81C5A98(data[0], 1);
    sub_81C704C(data[1]);
    gTasks[taskId].func = sub_81C68B0;
}

void sub_81C68B0(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    if (sub_81221EC() != TRUE)
    {
        if (gMain.newKeys & SELECT_BUTTON)
        {
            PlaySE(SE_SELECT);
            ListMenuGetScrollAndRow(data[0], &gUnknown_0203CF30.unk8, &gUnknown_0203CF30.unk6);
            sub_81C6964(taskId);
        }
        else
        {
            s32 id = ListMenuHandleInputGetItemId(data[0]);
            ListMenuGetScrollAndRow(data[0], &gUnknown_0203CF30.unk8, &gUnknown_0203CF30.unk6);
            sub_81C7028(0);
            sub_81C704C(gUnknown_0203CF30.unk6);
            switch (id)
            {
            case LIST_NOTHING_CHOSEN:
                break;
            case LIST_B_PRESSED:
                PlaySE(SE_SELECT);
                if (gMain.newKeys & A_BUTTON)
                    sub_81C6964(taskId);
                else
                    sub_81C6A14(taskId);
                break;
            default:
                PlaySE(SE_SELECT);
                sub_81C6964(taskId);
                break;
            }
        }
    }
}

void sub_81C6964(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    u16 *scrollOffset = &gUnknown_0203CF30.unk8;
    u16 *selectedRow = &gUnknown_0203CF30.unk6;
    u16 var = *scrollOffset + *selectedRow;

    if (data[1] == var || data[1] == var - 1)
    {
        sub_81C6A14(taskId);
    }
    else
    {
        MovePyramidBagItemSlotInList(data[1], var);
        gUnknown_0203CF2C->unk814 = 0xFF;
        sub_81C7028(1);
        DestroyListMenuTask(data[0], scrollOffset, selectedRow);
        if (data[1] < var)
            gUnknown_0203CF30.unk6--;
        SetBagItemsListTemplate();
        data[0] = ListMenuInit(&gMultiuseListMenuTemplate, *scrollOffset, *selectedRow);
        sub_81C629C(taskId);
    }
}

void sub_81C6A14(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    u16 *scrollOffset = &gUnknown_0203CF30.unk8;
    u16 *selectedRow = &gUnknown_0203CF30.unk6;

    gUnknown_0203CF2C->unk814 = 0xFF;
    sub_81C7028(1);
    DestroyListMenuTask(data[0], scrollOffset, selectedRow);
    if (data[1] < *scrollOffset + *selectedRow)
        gUnknown_0203CF30.unk6--;
    SetBagItemsListTemplate();
    data[0] = ListMenuInit(&gMultiuseListMenuTemplate, *scrollOffset, *selectedRow);
    sub_81C629C(taskId);
}

void sub_81C6A94(void)
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
        if (heldItem != 0 && !AddBagItem(heldItem, 1))
        {
            memcpy(gSaveBlock2Ptr->frontier.pyramidBag.itemId[gSaveBlock2Ptr->frontier.lvlMode], newItems, PYRAMID_BAG_ITEMS_COUNT * sizeof(u16));
            memcpy(gSaveBlock2Ptr->frontier.pyramidBag.quantity[gSaveBlock2Ptr->frontier.lvlMode], newQuantities, PYRAMID_BAG_ITEMS_COUNT * sizeof(u8));
            Free(newItems);
            Free(newQuantities);
            gSpecialVar_Result = 1;
            return;
        }
    }

    heldItem = 0;
    for (i = 0; i < 3; i++)
    {
        SetMonData(&party[i], MON_DATA_HELD_ITEM, &heldItem);
    }
    gSpecialVar_Result = 0;
    Free(newItems);
    Free(newQuantities);
}

void sub_81C6BD8(void)
{
    u8 i;

    InitWindows(gUnknown_0861F328);
    DeactivateAllTextPrinters();
    LoadUserWindowBorderGfx(0, 0x1, 0xE0);
    LoadMessageBoxGfx(0, 0xA, 0xD0);
    LoadPalette(gUnknown_0860F074, 0xF0, 0x20);

    for (i = 0; i < 5; i++)
        FillWindowPixelBuffer(i, 0);

    PutWindowTilemap(0);
    PutWindowTilemap(1);
    schedule_bg_copy_tilemap_to_vram(0);
    schedule_bg_copy_tilemap_to_vram(1);
}

void PrintOnWindow_Font1(u8 windowId, const u8 *src, u8 x, u8 y, u8 letterSpacing, u8 lineSpacing, u8 speed, u8 colorTableId)
{
    AddTextPrinterParameterized2(windowId, 1, x, y, letterSpacing, lineSpacing, gUnknown_0861F31C[colorTableId], speed, src);
}

void PrintOnWindow_Font7(u8 windowId, const u8 *src, u8 x, u8 y, u8 letterSpacing, u8 lineSpacing, u8 speed, u8 colorTableId)
{
    AddTextPrinterParameterized2(windowId, 7, x, y, letterSpacing, lineSpacing, gUnknown_0861F31C[colorTableId], speed, src);
}

void sub_81C6CEC(u8 windowId)
{
    SetWindowBorderStyle(windowId, 0, 1, 0xE);
    schedule_bg_copy_tilemap_to_vram(1);
}

u8 sub_81C6D08(u8 windowArrayId)
{
    return gUnknown_0203CF2C->windowIds[windowArrayId];
}

u8 sub_81C6D24(u8 windowArrayId)
{
    u8 *windowId = &gUnknown_0203CF2C->windowIds[windowArrayId];
    if (*windowId == 0xFF)
    {
        *windowId = AddWindow(&gUnknown_0861F350[windowArrayId]);
        SetWindowBorderStyle(*windowId, FALSE, 1, 0xE);
        schedule_bg_copy_tilemap_to_vram(1);
    }
    return *windowId;
}

void sub_81C6D6C(u8 windowArrayId)
{
    u8 *windowId = &gUnknown_0203CF2C->windowIds[windowArrayId];
    if (*windowId != 0xFF)
    {
        sub_8198070(*windowId, FALSE);
        ClearWindowTilemap(*windowId);
        RemoveWindow(*windowId);
        schedule_bg_copy_tilemap_to_vram(1);
        *windowId = 0xFF;
    }
}
