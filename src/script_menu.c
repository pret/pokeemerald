#include "global.h"
#include "event_data.h"
#include "menu.h"
#include "script_menu.h"
#include "string_util.h"
#include "task.h"
#include "text.h"

struct MultichoiceListStruct
{
    const struct MenuAction *list;
    u8 count;
};

extern const struct MultichoiceListStruct gUnknown_0858B760[];

IWRAM_DATA u8 gUnknown_03001124[6];
IWRAM_DATA u32 filler_0300112c;

/*static*/ void Task_HandleMultichoiceInput(u8);
/*static*/ void DrawMultichoiceMenu(u8, u8, u8, bool8, u8);
/*static*/ void sub_80E1FBC(u8, u8, u8, u8);

bool8 ScriptMenu_Multichoice(u8 left, u8 top, u8 multichoiceId, u8 ignoreBPress)
{
    if (FuncIsActiveTask(Task_HandleMultichoiceInput) == TRUE)
    {
        return FALSE;
    }
    else
    {
        gSpecialVar_Result = 0xFF;
        DrawMultichoiceMenu(left, top, multichoiceId, ignoreBPress, 0);
        return TRUE;
    }
}

bool8 ScriptMenu_MultichoiceWithDefault(u8 left, u8 top, u8 multichoiceId, bool8 ignoreBPress, u8 defaultChoice)
{
    if (FuncIsActiveTask(Task_HandleMultichoiceInput) == TRUE)
    {
        return FALSE;
    }
    else
    {
        gSpecialVar_Result = 0xFF;
        DrawMultichoiceMenu(left, top, multichoiceId, ignoreBPress, defaultChoice);
        return TRUE;
    }
}

/*static*/ u16 sub_80E1EB8(const u8 *str)
{
    u16 length = 0;

    while (*str != EOS)
    {
        if (*str == PLACEHOLDER_BEGIN)
        {
            str++;
            if (*str == 1)
            {
                length += StringLength(gSaveBlock2Ptr->playerName);
                str++;
            }
        }
        else
        {
            str++;
            length++;
        }
    }

    return length;
}

/*static*/ void DrawMultichoiceMenu(u8 left, u8 top, u8 multichoiceId, u8 ignoreBPress, u8 cursorPos)
{
    int i;
    u8 right;
    u8 bottom;
    u8 windowId;
    int count = gUnknown_0858B760[multichoiceId].count;
    const struct MenuAction *actions = gUnknown_0858B760[multichoiceId].list;
    int width = 0;
    u8 newWidth;
    
    i = count;
    while (0 < i)
    {
        width = display_text_and_get_width(actions[count - i].text, width);
    }

    newWidth = convert_pixel_width_to_tile_width(width);
    left = sub_80E2D5C(left, newWidth);
    windowId = CreateWindowFromRect(left, top, newWidth, count * 2);
    SetStandardWindowBorderStyle(windowId, 0);
    PrintMenuTable(windowId, count, actions);
    InitMenuInUpperLeftCornerPlaySoundWhenAPressed(windowId, count, cursorPos);
    schedule_bg_copy_tilemap_to_vram(0);
    sub_80E1FBC(ignoreBPress, count, windowId, multichoiceId);
}
