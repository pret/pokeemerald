#include "global.h"
#include "menu.h"
#include "list_menu.h"
#include "window.h"
#include "text_window.h"
#include "main.h"
#include "task.h"
#include "menu_indicators.h"
#include "strings.h"
#include "sound.h"
#include "constants/songs.h"

struct UnknownMysteryGiftLinkMenuStruct
{
    s32 field_0;
    u8 field_4;
    u8 field_5;
    u8 field_6;
};

struct UnknownListMenuPals
{
    u8 cursorPal:4;
    u8 fillValue:4;
    u8 cursorShadowPal:4;
    u8 lettersSpacing:6;
    u8 field_2_2:6; // unused
    u8 fontId:7;
    u8 field_3_7:1;
};

extern struct UnknownMysteryGiftLinkMenuStruct gUnknown_0203CE84;

// this file's functions
static u8 ListMenuInitInternal(struct ListMenuTemplate *listMenuTemplate, u16 scrollOffset, u16 selectedRow);
static bool8 ListMenuChangeSelection(struct ListMenu *list, bool8 updateCursorAndCallCallback, u8 count, bool8 movingDown);
static void ListMenuPrintEntries(struct ListMenu *list, u16 startIndex, u16 yOffset, u16 count);
static void ListMenuDrawCursor(struct ListMenu *list);
static void ListMenuCallSelectionChangedCallback(struct ListMenu *list, u8 a2);
static u8 ListMenuAddCursorObject(struct ListMenu *list, u32 cursorKind);

// IWRAM common
struct UnknownListMenuPals gUnknown_03006300;
struct ListMenuTemplate gMultiuseListMenuTemplate;

// code
static void ListMenuDummyTask(u8 taskId)
{

}

s32 DoMysteryGiftListMenu(struct WindowTemplate *windowTemplate, struct ListMenuTemplate *listMenuTemplate, u8 arg2, u16 tileNum, u16 palNum)
{
    switch (gUnknown_0203CE84.field_4)
    {
    case 0:
    default:
        gUnknown_0203CE84.field_5 = AddWindow(windowTemplate);
        switch (arg2)
        {
        case 2:
            sub_809882C(gUnknown_0203CE84.field_5, tileNum, palNum);
        case 1:
            sub_8098858(gUnknown_0203CE84.field_5, tileNum, palNum / 16);
            break;
        }
        gMultiuseListMenuTemplate = *listMenuTemplate;
        gMultiuseListMenuTemplate.windowId = gUnknown_0203CE84.field_5;
        gUnknown_0203CE84.field_6 = ListMenuInit(&gMultiuseListMenuTemplate, 0, 0);
        CopyWindowToVram(gUnknown_0203CE84.field_5, 1);
        gUnknown_0203CE84.field_4 = 1;
        break;
    case 1:
        gUnknown_0203CE84.field_0 = ListMenuHandleInputGetItemId(gUnknown_0203CE84.field_6);
        if (gMain.newKeys & A_BUTTON)
        {
            gUnknown_0203CE84.field_4 = 2;
        }
        if (gMain.newKeys & B_BUTTON)
        {
            gUnknown_0203CE84.field_0 = LIST_B_PRESSED;
            gUnknown_0203CE84.field_4 = 2;
        }
        if (gUnknown_0203CE84.field_4 == 2)
        {
            if (arg2 == 0)
            {
                ClearWindowTilemap(gUnknown_0203CE84.field_5);
            }
            else
            {
                switch (arg2)
                {
                case 0: // can never be reached, because of the if statement above
                    sub_819746C(gUnknown_0203CE84.field_5, FALSE);
                    break;
                case 2:
                case 1:
                    sub_819746C(gUnknown_0203CE84.field_5, FALSE);
                    break;
                }
            }

            CopyWindowToVram(gUnknown_0203CE84.field_5, 1);
        }
        break;
    case 2:
        DestroyListMenuTask(gUnknown_0203CE84.field_6, NULL, NULL);
        RemoveWindow(gUnknown_0203CE84.field_5);
        gUnknown_0203CE84.field_4 = 0;
        return gUnknown_0203CE84.field_0;
    }

    return -1;
}

u8 ListMenuInit(struct ListMenuTemplate *listMenuTemplate, u16 scrollOffset, u16 selectedRow)
{
    u8 taskId = ListMenuInitInternal(listMenuTemplate, scrollOffset, selectedRow);
    PutWindowTilemap(listMenuTemplate->windowId);
    CopyWindowToVram(listMenuTemplate->windowId, 2);

    return taskId;
}

// unused
u8 ListMenuInitWithWindows(struct ListMenuTemplate *listMenuTemplate, struct UnknownListMenuWindowStruct *arg1, u16 scrollOffset, u16 selectedRow)
{
    s32 i;

    u8 taskId = ListMenuInitInternal(listMenuTemplate, scrollOffset, selectedRow);
    for (i = 0; arg1[i].palNum != 0xFF; i++)
    {
        PutWindowRectTilemapOverridePalette(listMenuTemplate->windowId,
                                            arg1[i].x,
                                            arg1[i].y,
                                            arg1[i].width,
                                            arg1[i].height,
                                            arg1[i].palNum);
    }
    CopyWindowToVram(listMenuTemplate->windowId, 2);

    return taskId;
}

s32 ListMenuHandleInputGetItemId(u8 listTaskId)
{
    struct ListMenu *list = (void*) gTasks[listTaskId].data;

    if (gMain.newKeys & A_BUTTON)
    {
        return list->template.items[list->scrollOffset + list->selectedRow].id;
    }
    else if (gMain.newKeys & B_BUTTON)
    {
        return LIST_B_PRESSED;
    }
    else if (gMain.newAndRepeatedKeys & DPAD_UP)
    {
        ListMenuChangeSelection(list, TRUE, 1, FALSE);
        return LIST_NOTHING_CHOSEN;
    }
    else if (gMain.newAndRepeatedKeys & DPAD_DOWN)
    {
        ListMenuChangeSelection(list, TRUE, 1, TRUE);
        return LIST_NOTHING_CHOSEN;
    }
    else // try to move by one window scroll
    {
        bool16 rightButton, leftButton;
        switch (list->template.scrollMultiple)
        {
        case LIST_NO_MULTIPLE_SCROLL:
        default:
            leftButton = FALSE;
            rightButton = FALSE;
            break;
        case LIST_MULTIPLE_SCROLL_DPAD:
            leftButton = gMain.newAndRepeatedKeys & DPAD_LEFT;
            rightButton = gMain.newAndRepeatedKeys & DPAD_RIGHT;
            break;
        case LIST_MULTIPLE_SCROLL_L_R:
            leftButton = gMain.newAndRepeatedKeys & L_BUTTON;
            rightButton = gMain.newAndRepeatedKeys & R_BUTTON;
            break;
        }

        if (leftButton)
        {
            ListMenuChangeSelection(list, TRUE, list->template.maxShowed, FALSE);
            return LIST_NOTHING_CHOSEN;
        }
        else if (rightButton)
        {
            ListMenuChangeSelection(list, TRUE, list->template.maxShowed, TRUE);
            return LIST_NOTHING_CHOSEN;
        }
        else
        {
            return LIST_NOTHING_CHOSEN;
        }
    }
}

void DestroyListMenuTask(u8 listTaskId, u16 *scrollOffset, u16 *selectedRow)
{
    struct ListMenu *list = (void*) gTasks[listTaskId].data;

    if (scrollOffset != NULL)
        *scrollOffset = list->scrollOffset;
    if (selectedRow != NULL)
        *selectedRow = list->selectedRow;

    if (list->unk_1E != 0xFF)
        ListMenuRemoveCursorObject(list->unk_1E, list->template.cursorKind - 2);

    DestroyTask(listTaskId);
}

void sub_81AE70C(u8 listTaskId)
{
    struct ListMenu *list = (void*) gTasks[listTaskId].data;

    FillWindowPixelBuffer(list->template.windowId, (list->template.fillValue << 4) | (list->template.fillValue));
    ListMenuPrintEntries(list, list->scrollOffset, 0, list->template.maxShowed);
    ListMenuDrawCursor(list);
    CopyWindowToVram(list->template.windowId, 2);
}

// unused
void ChangeListMenuPals(u8 listTaskId, u8 cursorPal, u8 fillValue, u8 cursorShadowPal)
{
    struct ListMenu *list = (void*) gTasks[listTaskId].data;

    list->template.cursorPal = cursorPal;
    list->template.fillValue = fillValue;
    list->template.cursorShadowPal = cursorShadowPal;
}

// unused
void ChangeListMenuCoords(u8 listTaskId, u8 x, u8 y)
{
    struct ListMenu *list = (void*) gTasks[listTaskId].data;

    SetWindowAttribute(list->template.windowId, WINDOW_TILEMAP_LEFT, x);
    SetWindowAttribute(list->template.windowId, WINDOW_TILEMAP_TOP, y);
}

// unused
s32 ListMenuTestInput(struct ListMenuTemplate *template, u32 scrollOffset, u32 selectedRow, u16 keys, u16 *newScrollOffset, u16 *newSelectedRow)
{
    struct ListMenu list;

    list.template = *template;
    list.scrollOffset = scrollOffset;
    list.selectedRow = selectedRow;
    list.unk_1C = 0;
    list.unk_1D = 0;

    if (keys == DPAD_UP)
        ListMenuChangeSelection(&list, FALSE, 1, FALSE);
    if (keys == DPAD_DOWN)
        ListMenuChangeSelection(&list, FALSE, 1, TRUE);

    if (newScrollOffset != NULL)
        *newScrollOffset = list.scrollOffset;
    if (newSelectedRow != NULL)
        *newSelectedRow = list.selectedRow;

    return LIST_NOTHING_CHOSEN;
}

void ListMenuGetCurrentItemArrayId(u8 listTaskId, u16 *arrayId)
{
    struct ListMenu *list = (void*) gTasks[listTaskId].data;

    if (arrayId != NULL)
        *arrayId = list->scrollOffset + list->selectedRow;
}

void ListMenuGetScrollAndRow(u8 listTaskId, u16 *scrollOffset, u16 *selectedRow)
{
    struct ListMenu *list = (void*) gTasks[listTaskId].data;

    if (scrollOffset != NULL)
        *scrollOffset = list->scrollOffset;
    if (selectedRow != NULL)
        *selectedRow = list->selectedRow;
}

u16 ListMenuGetYCoordForPrintingArrowCursor(u8 listTaskId)
{
    struct ListMenu *list = (void*) gTasks[listTaskId].data;
    u8 yMultiplier = GetFontAttribute(list->template.fontId, 1) + list->template.unk_16_3;

    return list->selectedRow * yMultiplier + list->template.upText_Y;
}

static u8 ListMenuInitInternal(struct ListMenuTemplate *listMenuTemplate, u16 scrollOffset, u16 selectedRow)
{
    u8 listTaskId = CreateTask(ListMenuDummyTask, 0);
    struct ListMenu *list = (void*) gTasks[listTaskId].data;

    list->template = *listMenuTemplate;
    list->scrollOffset = scrollOffset;
    list->selectedRow = selectedRow;
    list->unk_1C = 0;
    list->unk_1D = 0;
    list->unk_1E = 0xFF;
    list->unk_1F = 0;

    gUnknown_03006300.cursorPal = list->template.cursorPal;
    gUnknown_03006300.fillValue = list->template.fillValue;
    gUnknown_03006300.cursorShadowPal = list->template.cursorShadowPal;
    gUnknown_03006300.lettersSpacing = list->template.lettersSpacing;
    gUnknown_03006300.fontId = list->template.fontId;
    gUnknown_03006300.field_3_7 = 0;

    if (list->template.totalItems < list->template.maxShowed)
        list->template.maxShowed = list->template.totalItems;

    FillWindowPixelBuffer(list->template.windowId, (list->template.fillValue << 4) | (list->template.fillValue));
    ListMenuPrintEntries(list, list->scrollOffset, 0, list->template.maxShowed);
    ListMenuDrawCursor(list);
    ListMenuCallSelectionChangedCallback(list, 1);

    return listTaskId;
}

static void ListMenuPrint(struct ListMenu *list, const u8 *str, u8 x, u8 y)
{
    u8 colors[3];
    if (gUnknown_03006300.field_3_7)
    {
        colors[0] = gUnknown_03006300.fillValue;
        colors[1] = gUnknown_03006300.cursorPal;
        colors[2] = gUnknown_03006300.cursorShadowPal;
        AddTextPrinterParameterized2(list->template.windowId,
                                     gUnknown_03006300.fontId,
                                     x, y,
                                     gUnknown_03006300.lettersSpacing,
                                     0, colors, TEXT_SPEED_FF, str);

        gUnknown_03006300.field_3_7 = 0;
    }
    else
    {
        colors[0] = list->template.fillValue;
        colors[1] = list->template.cursorPal;
        colors[2] = list->template.cursorShadowPal;
        AddTextPrinterParameterized2(list->template.windowId,
                                     list->template.fontId,
                                     x, y,
                                     list->template.lettersSpacing,
                                     0, colors, TEXT_SPEED_FF, str);
    }
}

static void ListMenuPrintEntries(struct ListMenu *list, u16 startIndex, u16 yOffset, u16 count)
{
    s32 i;
    u8 x, y;
    u8 yMultiplier = GetFontAttribute(list->template.fontId, 1) + list->template.unk_16_3;

    for (i = 0; i < count; i++)
    {
        if (list->template.items[startIndex].id != -3)
            x = list->template.unk_12;
        else
            x = list->template.unk_11;

        y = (yOffset + i) * yMultiplier + list->template.upText_Y;
        if (list->template.unk_08 != NULL)
            list->template.unk_08(list->template.windowId, list->template.items[startIndex].id, y);

        ListMenuPrint(list, list->template.items[startIndex].name, x, y);
        startIndex++;
    }
}

static void ListMenuDrawCursor(struct ListMenu *list)
{
    u8 yMultiplier = GetFontAttribute(list->template.fontId, 1) + list->template.unk_16_3;
    u8 x = list->template.cursor_X;
    u8 y = list->selectedRow * yMultiplier + list->template.upText_Y;
    switch (list->template.cursorKind)
    {
    case 0:
        ListMenuPrint(list, gText_SelectorArrow2, x, y);
        break;
    case 1:
        break;
    case 2:
        if (list->unk_1E == 0xFF)
            list->unk_1E = ListMenuAddCursorObject(list, 0);
        ListMenuUpdateCursorObject(list->unk_1E,
                                   GetWindowAttribute(list->template.windowId, WINDOW_TILEMAP_LEFT) * 8 - 1,
                                   GetWindowAttribute(list->template.windowId, WINDOW_TILEMAP_TOP) * 8 + y - 1, 0);
        break;
    case 3:
        if (list->unk_1E == 0xFF)
            list->unk_1E = ListMenuAddCursorObject(list, 1);
        ListMenuUpdateCursorObject(list->unk_1E,
                                   GetWindowAttribute(list->template.windowId, WINDOW_TILEMAP_LEFT) * 8 + x,
                                   GetWindowAttribute(list->template.windowId, WINDOW_TILEMAP_TOP) * 8 + y, 1);
        break;
    }
}

static u8 ListMenuAddCursorObject(struct ListMenu *list, u32 cursorKind)
{
    struct CursorStruct cursor;

    cursor.unk0 = 0;
    cursor.unk1 = 0xA0;
    cursor.unk2 = GetWindowAttribute(list->template.windowId, WINDOW_WIDTH) * 8 + 2;
    cursor.unk4 = GetFontAttribute(list->template.fontId, 1) + 2;
    cursor.unk6 = 0x4000;
    cursor.unk8 = 0xFFFF;
    cursor.unkA = 0xF;

    return ListMenuAddCursorObjectInternal(&cursor, cursorKind);
}

static void ListMenuErasePrintedCursor(struct ListMenu *list, u16 selectedRow)
{
    u8 cursorKind = list->template.cursorKind;
    if (cursorKind == 0)
    {
        u8 yMultiplier = GetFontAttribute(list->template.fontId, 1) + list->template.unk_16_3;
        u8 width  = GetMenuCursorDimensionByFont(list->template.fontId, 0);
        u8 height = GetMenuCursorDimensionByFont(list->template.fontId, 1);
        FillWindowPixelRect(list->template.windowId,
                            (list->template.fillValue << 4) | (list->template.fillValue),
                            list->template.cursor_X,
                            selectedRow * yMultiplier + list->template.upText_Y,
                            width,
                            height);
    }
}

static u8 ListMenuUpdateSelectedRowIndexAndScrollOffset(struct ListMenu *list, bool8 movingDown)
{
    u16 selectedRow = list->selectedRow;
    u16 scrollOffset = list->scrollOffset;
    u16 newRow;
    u32 newScroll;

    if (!movingDown)
    {
        if (list->template.maxShowed == 1)
            newRow = 0;
        else
            newRow = list->template.maxShowed - ((list->template.maxShowed / 2) + (list->template.maxShowed % 2)) - 1;

        if (scrollOffset == 0)
        {
            while (selectedRow != 0)
            {
                selectedRow--;
                if (list->template.items[scrollOffset + selectedRow].id != -3)
                {
                    list->selectedRow = selectedRow;
                    return 1;
                }
            }

            return 0;
        }
        else
        {
            while (selectedRow > newRow)
            {
                selectedRow--;
                if (list->template.items[scrollOffset + selectedRow].id != -3)
                {
                    list->selectedRow = selectedRow;
                    return 1;
                }
            }

            newScroll = scrollOffset - 1;
        }
    }
    else
    {
        if (list->template.maxShowed == 1)
            newRow = 0;
        else
            newRow = ((list->template.maxShowed / 2) + (list->template.maxShowed % 2));

        if (scrollOffset == list->template.totalItems - list->template.maxShowed)
        {
            while (selectedRow < list->template.maxShowed - 1)
            {
                selectedRow++;
                if (list->template.items[scrollOffset + selectedRow].id != -3)
                {
                    list->selectedRow = selectedRow;
                    return 1;
                }
            }

            return 0;
        }
        else
        {
            while (selectedRow < newRow)
            {
                selectedRow++;
                if (list->template.items[scrollOffset + selectedRow].id != -3)
                {
                    list->selectedRow = selectedRow;
                    return 1;
                }
            }

            newScroll = scrollOffset + 1;
        }
    }

    list->selectedRow = newRow;
    list->scrollOffset = newScroll;
    return 2;
}

static void ListMenuScroll(struct ListMenu *list, u8 count, bool8 movingDown)
{
    if (count >= list->template.maxShowed)
    {
        FillWindowPixelBuffer(list->template.windowId, (list->template.fillValue << 4) | (list->template.fillValue));
        ListMenuPrintEntries(list, list->scrollOffset, 0, list->template.maxShowed);
    }
    else
    {
        u8 yMultiplier = GetFontAttribute(list->template.fontId, 1) + list->template.unk_16_3;

        if (!movingDown)
        {
            u16 y, width, height;

            ScrollWindow(list->template.windowId, 1, count * yMultiplier, (list->template.fillValue << 4) | (list->template.fillValue));
            ListMenuPrintEntries(list, list->scrollOffset, 0, count);

            y = (list->template.maxShowed * yMultiplier) + list->template.upText_Y;
            width = GetWindowAttribute(list->template.windowId, WINDOW_WIDTH) * 8;
            height = (GetWindowAttribute(list->template.windowId, WINDOW_HEIGHT) * 8) - y;
            FillWindowPixelRect(list->template.windowId,
                                (list->template.fillValue << 4) | (list->template.fillValue),
                                0, y, width, height);
        }
        else
        {
            u16 width;

            ScrollWindow(list->template.windowId, 0, count * yMultiplier, (list->template.fillValue << 4) | (list->template.fillValue));
            ListMenuPrintEntries(list, list->scrollOffset + (list->template.maxShowed - count), list->template.maxShowed - count, count);

            width = GetWindowAttribute(list->template.windowId, WINDOW_WIDTH) * 8;
            FillWindowPixelRect(list->template.windowId,
                                (list->template.fillValue << 4) | (list->template.fillValue),
                                0, 0, width, list->template.upText_Y);
        }
    }
}

static bool8 ListMenuChangeSelection(struct ListMenu *list, bool8 updateCursorAndCallCallback, u8 count, bool8 movingDown)
{
    u16 oldSelectedRow;
    u8 selectionChange, i, cursorCount;

    oldSelectedRow = list->selectedRow;
    cursorCount = 0;
    selectionChange = 0;
    for (i = 0; i < count; i++)
    {
        do
        {
            u8 ret = ListMenuUpdateSelectedRowIndexAndScrollOffset(list, movingDown);
            selectionChange |= ret;
            if (ret != 2)
                break;
            cursorCount++;
        } while (list->template.items[list->scrollOffset + list->selectedRow].id == -3);
    }

    if (updateCursorAndCallCallback)
    {
        switch (selectionChange)
        {
        case 0:
        default:
            return TRUE;
        case 1:
            ListMenuErasePrintedCursor(list, oldSelectedRow);
            ListMenuDrawCursor(list);
            ListMenuCallSelectionChangedCallback(list, 0);
            CopyWindowToVram(list->template.windowId, 2);
            break;
        case 2:
        case 3:
            ListMenuErasePrintedCursor(list, oldSelectedRow);
            ListMenuScroll(list, cursorCount, movingDown);
            ListMenuDrawCursor(list);
            ListMenuCallSelectionChangedCallback(list, 0);
            CopyWindowToVram(list->template.windowId, 2);
            break;
        }
    }

    return FALSE;
}

static void ListMenuCallSelectionChangedCallback(struct ListMenu *list, u8 a2)
{
    if (list->template.moveCursorFunc != NULL)
        list->template.moveCursorFunc(list->template.items[list->scrollOffset + list->selectedRow].id, a2, list);
}

// unused
void sub_81AF028(u8 cursorPal, u8 fillValue, u8 cursorShadowPal)
{
    gUnknown_03006300.cursorPal = cursorPal;
    gUnknown_03006300.fillValue = fillValue;
    gUnknown_03006300.cursorShadowPal = cursorShadowPal;
    gUnknown_03006300.field_3_7 = 1;
}

void sub_81AF078(s32 arg0, u8 arg1, struct ListMenu *list)
{
    if (!arg1)
        PlaySE(SE_SELECT);
}
