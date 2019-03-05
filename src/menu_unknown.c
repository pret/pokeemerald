#include "global.h"
#include "alloc.h"
#include "international_string_util.h"
#include "menu.h"
#include "menu_unknown.h"
#include "player_pc.h"
#include "sound.h"
#include "strings.h"
#include "string_util.h"
#include "window.h"
#include "constants/songs.h"

#define WINDOW_UNK_0 0
#define WINDOW_UNK_1 1
#define WINDOW_UNK_2 2

extern struct ListMenuItem *gUnknown_0203CF4C;
extern u8 gUnknown_0203CF48[3];

void sub_81D1E7C(s32 itemIndex, bool8 onInit, struct ListMenu *list);

const struct WindowTemplate gUnknown_086253E8[] =
{
    [WINDOW_UNK_0] = {
        //0x08010100,
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 1,
        .width = 8,
	    //0x00080F02,
        .height = 2,
        .paletteNum = 0xF,
        .baseBlock = 0x8
    },
    [WINDOW_UNK_1] = {
        //0x08 01 15 00,
        .bg = 0,
        .tilemapLeft = 21,
        .tilemapTop = 1,
        .width = 8,
        //0x0018 0F 12,
        .height = 18,
        .paletteNum = 0xF,
        .baseBlock = 0x18
    },
    [WINDOW_UNK_2] = {
	    //0x0B 01 01 00
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 1,
        .width = 11,
	    //0x0018 0F 08
        .height = 8,
        .paletteNum = 0xF,
        .baseBlock = 0x18
    }
};

const u8 gUnknown_08625400[] = {
    1, 2, 3
};

static const u8 sEmptyItemName[] = _("");

bool8 sub_81D1C44(u8 count)
{
    u32 i;
    struct ListMenuItem **v1;
    v1 = &gUnknown_0203CF4C;
    *v1 = Alloc(count * sizeof(struct ListMenuItem) + sizeof(struct ListMenuItem));
    
    if (gUnknown_0203CF4C == NULL)
        return FALSE;
    
    for (i = 0; i < ARRAY_COUNT(gUnknown_0203CF48); i = (u8)(i + 1))
    {
        gUnknown_0203CF48[i] |= 0xFF;
    }

    return TRUE;
}

u8 sub_81D1C84(u8 a0)
{
    struct WindowTemplate template;

    u8 windowId = gUnknown_0203CF48[a0];
    if (windowId == 0xFF)
    {
        if (a0 == WINDOW_UNK_2)
        {
            u32 v1;
            u32 v2;
            s32 v3;

            template = gUnknown_086253E8[WINDOW_UNK_2];
            v3 = GetMaxWidthInMenuTable(&gMailboxMailOptions[0], 4);
            template.width = v3;
            gUnknown_0203CF48[WINDOW_UNK_2] = AddWindow(&template);
        }
        else
        {
            gUnknown_0203CF48[a0] = AddWindow(&gUnknown_086253E8[a0]);
        }
        SetStandardWindowBorderStyle(gUnknown_0203CF48[a0], 0);
    }
    return gUnknown_0203CF48[a0];
}

void sub_81D1D04(u8 a0)
{
    sub_8198070(gUnknown_0203CF48[a0], 0);
    ClearWindowTilemap(gUnknown_0203CF48[a0]);
    RemoveWindow(gUnknown_0203CF48[a0]);
    gUnknown_0203CF48[a0] = 0xFF;
}

u8 sub_81D1D34(u8 a0)
{
    return gUnknown_0203CF48[a0];
}

void sub_81D1D44(u8 windowId, s32 itemId, u8 y)
{
    u8 buffer[30];
    u16 length;

	if (itemId == LIST_CANCEL)
        return;
    
    StringCopy(buffer, gSaveBlock1Ptr->mail[6 + itemId].playerName);
    sub_81DB52C(buffer);
    length = StringLength(buffer);
    if (length <= 5)
        ConvertInternationalString(buffer, LANGUAGE_JAPANESE);
    AddTextPrinterParameterized4(windowId, 1, 8, y, 0, 0, gUnknown_08625400, -1, buffer);
}

u8 sub_81D1DC0(struct PlayerPCItemPageStruct *page)
{
    u16 i;
    for (i = 0; i < page->count; i++)
    {
        gUnknown_0203CF4C[i].name = sEmptyItemName;
        gUnknown_0203CF4C[i].id = i;
    }

    gUnknown_0203CF4C[i].name = gText_Cancel2;
    gUnknown_0203CF4C[i].id = LIST_CANCEL;

    gMultiuseListMenuTemplate.items = gUnknown_0203CF4C;
    gMultiuseListMenuTemplate.totalItems = page->count + 1;
    gMultiuseListMenuTemplate.windowId = gUnknown_0203CF48[1];
    gMultiuseListMenuTemplate.header_X = 0;
    gMultiuseListMenuTemplate.item_X = 8;
    gMultiuseListMenuTemplate.cursor_X = 0;
    gMultiuseListMenuTemplate.maxShowed = 8;
    gMultiuseListMenuTemplate.upText_Y = 9;
    gMultiuseListMenuTemplate.cursorPal = 2;
    gMultiuseListMenuTemplate.fillValue = 1;
    gMultiuseListMenuTemplate.cursorShadowPal = 3;
    gMultiuseListMenuTemplate.moveCursorFunc = sub_81D1E7C;
    gMultiuseListMenuTemplate.itemPrintFunc = sub_81D1D44;
    gMultiuseListMenuTemplate.fontId = 1;
    gMultiuseListMenuTemplate.cursorKind = 0;
    gMultiuseListMenuTemplate.lettersSpacing = 0;
    gMultiuseListMenuTemplate.itemVerticalPadding = 0;
    gMultiuseListMenuTemplate.scrollMultiple = LIST_NO_MULTIPLE_SCROLL;
    return ListMenuInit(&gMultiuseListMenuTemplate, page->itemsAbove, page->cursorPos);
}

void sub_81D1E7C(s32 itemIndex, bool8 onInit, struct ListMenu *list)
{
    if (onInit != TRUE)
        PlaySE(SE_SELECT);
}

void sub_81D1E90(struct PlayerPCItemPageStruct *page)
{
    page->scrollIndicatorId = AddScrollIndicatorArrowPairParameterized(2, 0xC8, 12, 0x94, page->count - page->pageItems + 1, 0x6E, 0x6E, &page->itemsAbove);
}

void sub_81D1EC0(void)
{
    Free(gUnknown_0203CF4C);
}