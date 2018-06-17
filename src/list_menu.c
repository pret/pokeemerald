#include "global.h"
#include "menu.h"
#include "list_menu.h"
#include "window.h"
#include "text_window.h"
#include "main.h"
#include "task.h"
#include "trig.h"
#include "decompress.h"
#include "palette.h"
#include "malloc.h"
#include "strings.h"
#include "sound.h"
#include "constants/songs.h"

// This file needs better labels and function names.

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

struct UnkIndicatorsStruct
{
    u8 field_0;
    u16 *field_4;
    u16 field_8;
    u16 field_A;
    u16 field_C;
    u16 field_E;
    u8 field_10;
    u8 field_11;
    u8 field_12;
    u8 field_13;
    u8 field_14_0:4;
    u8 field_14_1:4;
    u8 field_15_0:4;
    u8 field_15_1:4;
    u8 field_16_0:3;
    u8 field_16_1:3;
    u8 field_16_2:2;
    u8 field_17_0:6;
    u8 field_17_1:2;
};

struct UnkIndicatorsStruct2
{
    u8 field_0;
    u16 *field_4;
    u16 field_8;
    u16 field_A;
    u8 field_C;
    u8 field_D;
    u16 tileTag;
    u16 palTag;
    u16 field_12;
    u16 field_14;
    u16 field_16;
    u16 field_18;
    u16 field_1A;
    u16 field_1C;
    s16 field_1E;
};

struct UnkIndicatorsStruct3
{
    struct SubspriteTable subspriteTable;
    struct Subsprite *subspritesPtr; // not a const pointer
    u8 spriteId;
    u16 tileTag;
    u16 palTag;
};

struct UnkIndicatorsStruct4
{
    u8 field_0;
    u16 tileTag;
    u16 palTag;
};

struct UnkSmallIndicatorsStruct
{
    u8 field_0_0:4;
    u8 field_0_1:4;
    u8 field_1;
    u16 field_2;
};

// this file's functions
static u8 ListMenuInitInternal(struct ListMenuTemplate *listMenuTemplate, u16 scrollOffset, u16 selectedRow);
static bool8 ListMenuChangeSelection(struct ListMenu *list, bool8 updateCursorAndCallCallback, u8 count, bool8 movingDown);
static void ListMenuPrintEntries(struct ListMenu *list, u16 startIndex, u16 yOffset, u16 count);
static void ListMenuDrawCursor(struct ListMenu *list);
static void ListMenuCallSelectionChangedCallback(struct ListMenu *list, u8 a2);
static u8 ListMenuAddCursorObject(struct ListMenu *list, u32 cursorKind);
static void Task_ScrollIndicatorArrowPair(u8 taskId);
static u8 ListMenuAddRedOutlineCursorObject(struct CursorStruct *cursor);
static u8 ListMenuAddRedArrowCursorObject(struct CursorStruct *cursor);
static void ListMenuUpdateRedOutlineCursorObject(u8 taskId, u16 x, u16 y);
static void ListMenuUpdateRedArrowCursorObject(u8 taskId, u16 x, u16 y);
static void ListMenuRemoveRedOutlineCursorObject(u8 taskId);
static void ListMenuRemoveRedArrowCursorObject(u8 taskId);
static u8 ListMenuAddCursorObjectInternal(struct CursorStruct *cursor, u32 cursorKind);
static void ListMenuUpdateCursorObject(u8 taskId, u16 x, u16 y, u32 cursorKind);
static void ListMenuRemoveCursorObject(u8 taskId, u32 cursorKind);
static void sub_81AF264(struct Sprite *sprite);
static void ObjectCB_RedArrowCursor(struct Sprite *sprite);

// EWRAM vars
 EWRAM_DATA struct UnknownMysteryGiftLinkMenuStruct gUnknown_0203CE84 = {0};
 EWRAM_DATA struct ArrowStruct gUnknown_0203CE8C = {0};

// IWRAM common
struct UnknownListMenuPals gUnknown_03006300;
struct ListMenuTemplate gMultiuseListMenuTemplate;

// const rom data
static const struct UnkSmallIndicatorsStruct gUnknown_086141FC[] =
{
    {0, 0, 2, 8},
    {1, 0, 2, -8},
    {2, 1, 2, 8},
    {3, 1, 2, -8},
};

static const struct OamData sOamData_861420C =
{
    .y = 0,
    .affineMode = 0,
    .objMode = 0,
    .mosaic = 0,
    .bpp = 0,
    .shape = 0,
    .x = 0,
    .matrixNum = 0,
    .size = 1,
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0
};

static const union AnimCmd sSpriteAnim_8614214[] =
{
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_861421C[] =
{
    ANIMCMD_FRAME(0, 30, 1, 0),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_8614224[] =
{
    ANIMCMD_FRAME(4, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_861422C[] =
{
    ANIMCMD_FRAME(4, 30, 0, 1),
    ANIMCMD_END
};

static const union AnimCmd *const sSpriteAnimTable_8614234[] =
{
    sSpriteAnim_8614214,
    sSpriteAnim_861421C,
    sSpriteAnim_8614224,
    sSpriteAnim_861422C
};

static const struct SpriteTemplate gUnknown_08614244 =
{
    .tileTag = 0,
    .paletteTag = 0,
    .oam = &sOamData_861420C,
    .anims = sSpriteAnimTable_8614234,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_81AF264,
};

static const struct Subsprite sSubsprite_861425C =
{
    .x = 0,
    .y = 0,
    .shape = 0,
    .size = 0,
    .tileOffset = 0,
    .priority = 0,
};

static const struct Subsprite sSubsprite_8614260 =
{
    .x = 0,
    .y = 0,
    .shape = 0,
    .size = 0,
    .tileOffset = 1,
    .priority = 0,
};

static const struct Subsprite sSubsprite_8614264 =
{
    .x = 0,
    .y = 0,
    .shape = 0,
    .size = 0,
    .tileOffset = 2,
    .priority = 0,
};

static const struct Subsprite sSubsprite_8614268 =
{
    .x = 0,
    .y = 0,
    .shape = 0,
    .size = 0,
    .tileOffset = 3,
    .priority = 0,
};

static const struct Subsprite sSubsprite_861426C =
{
    .x = 0,
    .y = 0,
    .shape = 0,
    .size = 0,
    .tileOffset = 4,
    .priority = 0,
};

static const struct Subsprite sSubsprite_8614270 =
{
    .x = 0,
    .y = 0,
    .shape = 0,
    .size = 0,
    .tileOffset = 5,
    .priority = 0,
};

static const struct Subsprite sSubsprite_8614274 =
{
    .x = 0,
    .y = 0,
    .shape = 0,
    .size = 0,
    .tileOffset = 6,
    .priority = 0,
};

static const struct Subsprite sSubsprite_8614278 =
{
    .x = 0,
    .y = 0,
    .shape = 0,
    .size = 0,
    .tileOffset = 7,
    .priority = 0,
};

static const struct OamData sOamData_861427C =
{
    .y = 0,
    .affineMode = 0,
    .objMode = 0,
    .mosaic = 0,
    .bpp = 0,
    .shape = 0,
    .x = 0,
    .matrixNum = 0,
    .size = 1,
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0
};

static const union AnimCmd sSpriteAnim_8614284[] =
{
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_END
};

static const union AnimCmd *const sSpriteAnimTable_861428C[] =
{
    sSpriteAnim_8614284
};

static const struct SpriteTemplate gUnknown_08614290 =
{
    .tileTag = 0,
    .paletteTag = 0,
    .oam = &sOamData_861427C,
    .anims = sSpriteAnimTable_861428C,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = ObjectCB_RedArrowCursor,
};

static const u16 gUnknown_086142A8[] = INCBIN_U16("graphics/interface/red_arrow.gbapal");
static const u8 gUnknown_086142C8[] = INCBIN_U8("graphics/interface/red_arrow_other.4bpp.lz");
static const u8 gUnknown_08614338[] = INCBIN_U8("graphics/interface/selector_outline.4bpp.lz");
static const u8 gUnknown_08614378[] = INCBIN_U8("graphics/interface/red_arrow.4bpp.lz");

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
            LoadSav2WindowGfx(gUnknown_0203CE84.field_5, tileNum, palNum);
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
    cursor.tileTag = 0x4000;
    cursor.palTag = 0xFFFF;
    cursor.palNum = 0xF;

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

// unused
s32 sub_81AF08C(u8 taskId, u8 field)
{
    struct UnkIndicatorsStruct *data = (void*) gTasks[taskId].data;

    switch (field)
    {
    case 0:
    case 1:
        return (s32)(data->field_4);
    case 2:
        return data->field_C;
    case 3:
        return data->field_E;
    case 4:
        return data->field_10;
    case 5:
        return data->field_11;
    case 6:
        return data->field_12;
    case 7:
        return data->field_13;
    case 8:
        return data->field_14_0;
    case 9:
        return data->field_14_1;
    case 10:
        return data->field_15_0;
    case 11:
        return data->field_15_1;
    case 12:
        return data->field_16_0;
    case 13:
        return data->field_16_1;
    case 14:
        return data->field_16_2;
    case 15:
        return data->field_17_0;
    case 16:
        return data->field_17_1;
    default:
        return -1;
    }
}

// unused
void sub_81AF15C(u8 taskId, u8 field, s32 value)
{
    struct UnkIndicatorsStruct *data = (void*) &gTasks[taskId].data;

    switch (field)
    {
    case 0:
    case 1:
        data->field_4 = (void*)(value);
		break;
    case 2:
        data->field_C = value;
		break;
    case 3:
        data->field_E = value;
		break;
    case 4:
        data->field_10 = value;
		break;
    case 5:
        data->field_11 = value;
		break;
    case 6:
        data->field_12 = value;
		break;
    case 7:
        data->field_13 = value;
		break;
    case 8:
        data->field_14_0 = value;
		break;
    case 9:
        data->field_14_1 = value;
		break;
    case 10:
        data->field_15_0 = value;
		break;
    case 11:
        data->field_15_1 = value;
		break;
    case 12:
        data->field_16_0 = value;
		break;
    case 13:
        data->field_16_1 = value;
		break;
    case 14:
        data->field_16_2 = value;
		break;
    case 15:
        data->field_17_0 = value;
		break;
    case 16:
        data->field_17_1 = value;
		break;
    }
}

static void sub_81AF264(struct Sprite *sprite)
{
    s32 multiplier;

    switch (sprite->data[0])
    {
    case 0:
        StartSpriteAnim(sprite, sprite->data[1]);
        sprite->data[0]++;
        break;
    case 1:
        switch (sprite->data[2])
        {
        case 0:
            multiplier = sprite->data[3];
            sprite->pos2.x = (gSineTable[(u8)(sprite->data[5])] * multiplier) / 256;
            break;
        case 1:
            multiplier = sprite->data[3];
            sprite->pos2.y = (gSineTable[(u8)(sprite->data[5])] * multiplier) / 256;
            break;
        }
        sprite->data[5] += sprite->data[4];
        break;
    }
}

static u8 AddScrollIndicatorArrowObject(u8 arg0, u8 x, u8 y, u16 tileTag, u16 palTag)
{
    u8 spriteId;
    struct SpriteTemplate spriteTemplate;

    spriteTemplate = gUnknown_08614244;
    spriteTemplate.tileTag = tileTag;
    spriteTemplate.paletteTag = palTag;

    spriteId = CreateSprite(&spriteTemplate, x, y, 0);
    gSprites[spriteId].invisible = 1;
    gSprites[spriteId].data[0] = 0;
    gSprites[spriteId].data[1] = gUnknown_086141FC[arg0].field_0_0;
    gSprites[spriteId].data[2] = gUnknown_086141FC[arg0].field_0_1;
    gSprites[spriteId].data[3] = gUnknown_086141FC[arg0].field_1;
    gSprites[spriteId].data[4] = gUnknown_086141FC[arg0].field_2;
    gSprites[spriteId].data[5] = 0;

    return spriteId;
}

u8 AddScrollIndicatorArrowPair(const struct ArrowStruct *arrowInfo, u16 *arg1)
{
    struct CompressedSpriteSheet spriteSheet;
    struct SpritePalette spritePal;
    struct UnkIndicatorsStruct2 *data;
    u8 taskId;

    spriteSheet.data = gUnknown_086142C8;
    spriteSheet.size = 0x100;
    spriteSheet.tag = arrowInfo->tileTag;
    LoadCompressedObjectPic(&spriteSheet);

    if (arrowInfo->palTag == 0xFFFF)
    {
        LoadPalette(gUnknown_086142A8, (16 * arrowInfo->palNum) + 0x100, 0x20);
    }
    else
    {
        spritePal.data = gUnknown_086142A8;
        spritePal.tag = arrowInfo->palTag;
        LoadSpritePalette(&spritePal);
    }

    taskId = CreateTask(Task_ScrollIndicatorArrowPair, 0);
    data = (void*) gTasks[taskId].data;

    data->field_0 = 0;
    data->field_4 = arg1;
    data->field_8 = arrowInfo->unk6;
    data->field_A = arrowInfo->unk8;
    data->tileTag = arrowInfo->tileTag;
    data->palTag = arrowInfo->palTag;
    data->field_C = AddScrollIndicatorArrowObject(arrowInfo->unk0, arrowInfo->unk1, arrowInfo->unk2, arrowInfo->tileTag, arrowInfo->palTag);
    data->field_D = AddScrollIndicatorArrowObject(arrowInfo->unk3, arrowInfo->unk4, arrowInfo->unk5, arrowInfo->tileTag, arrowInfo->palTag);

    if (arrowInfo->palTag == 0xFFFF)
    {
        gSprites[data->field_C].oam.paletteNum = arrowInfo->palNum;
        gSprites[data->field_D].oam.paletteNum = arrowInfo->palNum;
    }

    return taskId;
}

u8 AddScrollIndicatorArrowPairParametrized(u32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 tileTag, s32 palTag, void *arg7)
{
    if (arg0 == 2 || arg0 == 3)
    {
        gUnknown_0203CE8C.unk0 = 2;
        gUnknown_0203CE8C.unk1 = arg1;
        gUnknown_0203CE8C.unk2 = arg2;
        gUnknown_0203CE8C.unk3 = 3;
        gUnknown_0203CE8C.unk4 = arg1;
        gUnknown_0203CE8C.unk5 = arg3;
    }
    else
    {
        gUnknown_0203CE8C.unk0 = 0;
        gUnknown_0203CE8C.unk1 = arg2;
        gUnknown_0203CE8C.unk2 = arg1;
        gUnknown_0203CE8C.unk3 = 1;
        gUnknown_0203CE8C.unk4 = arg3;
        gUnknown_0203CE8C.unk5 = arg1;
    }

    gUnknown_0203CE8C.unk6 = 0;
    gUnknown_0203CE8C.unk8 = arg4;
    gUnknown_0203CE8C.tileTag = tileTag;
    gUnknown_0203CE8C.palTag = palTag;
    gUnknown_0203CE8C.palNum = 0;

    return AddScrollIndicatorArrowPair(&gUnknown_0203CE8C, arg7);
}

static void Task_ScrollIndicatorArrowPair(u8 taskId)
{
    struct UnkIndicatorsStruct2 *data = (void*) gTasks[taskId].data;
    u16 var = (*data->field_4);

    if (var == data->field_8 && var != 0xFFFF)
        gSprites[data->field_C].invisible = 1;
    else
        gSprites[data->field_C].invisible = 0;

    if (var == data->field_A)
        gSprites[data->field_D].invisible = 1;
    else
        gSprites[data->field_D].invisible = 0;
}

void Task_ScrollIndicatorArrowPairOnMainMenu(u8 taskId)
{
    struct UnkIndicatorsStruct2 *data = (void*) gTasks[taskId].data;

    if (data->field_1E != 0)
    {
        gSprites[data->field_C].invisible = 0;
        gSprites[data->field_D].invisible = 1;
    }
    else
    {
        gSprites[data->field_C].invisible = 1;
        gSprites[data->field_D].invisible = 0;
    }
}

void RemoveScrollIndicatorArrowPair(u8 taskId)
{
    struct UnkIndicatorsStruct2 *data = (void*) gTasks[taskId].data;

    if (data->tileTag != 0xFFFF)
        FreeSpriteTilesByTag(data->tileTag);
    if (data->palTag != 0xFFFF)
        FreeSpritePaletteByTag(data->palTag);

    DestroySprite(&gSprites[data->field_C]);
    DestroySprite(&gSprites[data->field_D]);

    DestroyTask(taskId);
}

static u8 ListMenuAddCursorObjectInternal(struct CursorStruct *cursor, u32 cursorKind)
{
    switch (cursorKind)
    {
    case 0:
    default:
        return ListMenuAddRedOutlineCursorObject(cursor);
    case 1:
        return ListMenuAddRedArrowCursorObject(cursor);
    }
}

static void ListMenuUpdateCursorObject(u8 taskId, u16 x, u16 y, u32 cursorKind)
{
    switch (cursorKind)
    {
    case 0:
        ListMenuUpdateRedOutlineCursorObject(taskId, x, y);
        break;
    case 1:
        ListMenuUpdateRedArrowCursorObject(taskId, x, y);
        break;
    }
}

static void ListMenuRemoveCursorObject(u8 taskId, u32 cursorKind)
{
    switch (cursorKind)
    {
    case 0:
        ListMenuRemoveRedOutlineCursorObject(taskId);
        break;
    case 1:
        ListMenuRemoveRedArrowCursorObject(taskId);
        break;
    }
}

static void Task_RedOutlineCursor(u8 taskId)
{

}

u8 ListMenuGetRedOutlineCursorSpriteCount(u16 arg0, u16 arg1)
{
    s32 i;
    s32 count = 4;

    if (arg0 > 16)
    {
        for (i = 8; i < (arg0 - 8); i += 8)
            count += 2;
    }
    if (arg1 > 16)
    {
        for (i = 8; i < (arg1 - 8); i += 8)
            count += 2;
    }

    return count;
}

void ListMenuSetUpRedOutlineCursorSpriteOamTable(u16 arg0, u16 arg1, struct Subsprite *subsprites)
{
    s32 i, j, id = 0;

    subsprites[id] = sSubsprite_861425C;
    subsprites[id].x = 136;
    subsprites[id].y = 136;
    id++;

    subsprites[id] = sSubsprite_8614260;
    subsprites[id].x = arg0 + 128;
    subsprites[id].y = 136;
    id++;

    subsprites[id] = sSubsprite_8614274;
    subsprites[id].x = 136;
    subsprites[id].y = arg1 + 128;
    id++;

    subsprites[id] = sSubsprite_8614278;
    subsprites[id].x = arg0 + 128;
    subsprites[id].y = arg1 + 128;
    id++;

    if (arg0 > 16)
    {
        for (i = 8; i < arg0 - 8; i += 8)
        {
            subsprites[id] = sSubsprite_8614264;
            subsprites[id].x = i - 120;
            subsprites[id].y = 136;
            id++;

            subsprites[id] = sSubsprite_8614270;
            subsprites[id].x = i - 120;
            subsprites[id].y = arg1 + 128;
            id++;
        }
    }

    if (arg1 > 16)
    {
        for (j = 8; j < arg1 - 8; j += 8)
        {
            subsprites[id] = sSubsprite_8614268;
            subsprites[id].x = 136;
            subsprites[id].y = j - 120;
            id++;

            subsprites[id] = sSubsprite_861426C;
            subsprites[id].x = arg0 + 128;
            subsprites[id].y = j - 120;
            id++;
        }
    }
}

static u8 ListMenuAddRedOutlineCursorObject(struct CursorStruct *cursor)
{
    struct CompressedSpriteSheet spriteSheet;
    struct SpritePalette spritePal;
    struct UnkIndicatorsStruct3 *data;
    struct SpriteTemplate spriteTemplate;
    u8 taskId;

    spriteSheet.data = gUnknown_08614338;
    spriteSheet.size = 0x100;
    spriteSheet.tag = cursor->tileTag;
    LoadCompressedObjectPic(&spriteSheet);

    if (cursor->palTag == 0xFFFF)
    {
        LoadPalette(gUnknown_086142A8, (16 * cursor->palNum) + 0x100, 0x20);
    }
    else
    {
        spritePal.data = gUnknown_086142A8;
        spritePal.tag = cursor->palTag;
        LoadSpritePalette(&spritePal);
    }

    taskId = CreateTask(Task_RedOutlineCursor, 0);
    data = (void*) gTasks[taskId].data;

    data->tileTag = cursor->tileTag;
    data->palTag = cursor->palTag;
    data->subspriteTable.subspriteCount = ListMenuGetRedOutlineCursorSpriteCount(cursor->unk2, cursor->unk4);
    data->subspriteTable.subsprites = data->subspritesPtr = Alloc(data->subspriteTable.subspriteCount * 4);
    ListMenuSetUpRedOutlineCursorSpriteOamTable(cursor->unk2, cursor->unk4, data->subspritesPtr);

    spriteTemplate = gDummySpriteTemplate;
    spriteTemplate.tileTag = cursor->tileTag;
    spriteTemplate.paletteTag = cursor->palTag;

    data->spriteId = CreateSprite(&spriteTemplate, cursor->unk0 + 120, cursor->unk1 + 120, 0);
    SetSubspriteTables(&gSprites[data->spriteId], &data->subspriteTable);
    gSprites[data->spriteId].oam.priority = 0;
    gSprites[data->spriteId].subpriority = 0;
    gSprites[data->spriteId].subspriteTableNum = 0;

    if (cursor->palTag == 0xFFFF)
    {
        gSprites[data->spriteId].oam.paletteNum = cursor->palNum;
    }

    return taskId;
}

static void ListMenuUpdateRedOutlineCursorObject(u8 taskId, u16 x, u16 y)
{
    struct UnkIndicatorsStruct3 *data = (void*) gTasks[taskId].data;

    gSprites[data->spriteId].pos1.x = x + 120;
    gSprites[data->spriteId].pos1.y = y + 120;
}

static void ListMenuRemoveRedOutlineCursorObject(u8 taskId)
{
    struct UnkIndicatorsStruct3 *data = (void*) gTasks[taskId].data;

    Free(data->subspritesPtr);

    if (data->tileTag != 0xFFFF)
        FreeSpriteTilesByTag(data->tileTag);
    if (data->palTag != 0xFFFF)
        FreeSpritePaletteByTag(data->palTag);

    DestroySprite(&gSprites[data->spriteId]);
    DestroyTask(taskId);
}

static void ObjectCB_RedArrowCursor(struct Sprite *sprite)
{
    sprite->pos2.x = gSineTable[(u8)(sprite->data[0])] / 64;
    sprite->data[0] += 8;
}

static void Task_RedArrowCursor(u8 taskId)
{

}

static u8 ListMenuAddRedArrowCursorObject(struct CursorStruct *cursor)
{
    struct CompressedSpriteSheet spriteSheet;
    struct SpritePalette spritePal;
    struct UnkIndicatorsStruct4 *data;
    struct SpriteTemplate spriteTemplate;
    u8 taskId;

    spriteSheet.data = gUnknown_08614378;
    spriteSheet.size = 0x80;
    spriteSheet.tag = cursor->tileTag;
    LoadCompressedObjectPic(&spriteSheet);

    if (cursor->palTag == 0xFFFF)
    {
        LoadPalette(gUnknown_086142A8, (16 * cursor->palNum) + 0x100, 0x20);
    }
    else
    {
        spritePal.data = gUnknown_086142A8;
        spritePal.tag = cursor->palTag;
        LoadSpritePalette(&spritePal);
    }

    taskId = CreateTask(Task_RedArrowCursor, 0);
    data = (void*) gTasks[taskId].data;

    data->tileTag = cursor->tileTag;
    data->palTag = cursor->palTag;

    spriteTemplate = gUnknown_08614290;
    spriteTemplate.tileTag = cursor->tileTag;
    spriteTemplate.paletteTag = cursor->palTag;

    data->field_0 = CreateSprite(&spriteTemplate, cursor->unk0, cursor->unk1, 0);
    gSprites[data->field_0].pos2.x = 8;
    gSprites[data->field_0].pos2.y = 8;

    if (cursor->palTag == 0xFFFF)
    {
        gSprites[data->field_0].oam.paletteNum = cursor->palNum;
    }

    return taskId;
}

static void ListMenuUpdateRedArrowCursorObject(u8 taskId, u16 x, u16 y)
{
    struct UnkIndicatorsStruct4 *data = (void*) gTasks[taskId].data;

    gSprites[data->field_0].pos1.x = x;
    gSprites[data->field_0].pos1.y = y;
}

static void ListMenuRemoveRedArrowCursorObject(u8 taskId)
{
    struct UnkIndicatorsStruct4 *data = (void*) gTasks[taskId].data;

    if (data->tileTag != 0xFFFF)
        FreeSpriteTilesByTag(data->tileTag);
    if (data->palTag != 0xFFFF)
        FreeSpritePaletteByTag(data->palTag);

    DestroySprite(&gSprites[data->field_0]);
    DestroyTask(taskId);
}
