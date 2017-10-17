
// Includes
#include "global.h"
#include "string_util.h"
#include "international_string_util.h"
#include "script.h"
#include "task.h"
#include "palette.h"
#include "songs.h"
#include "new_menu_helpers.h"
#include "sound.h"
#include "decoration.h"
#include "decoration_inventory.h"
#include "strings.h"

// Static type declarations

// Static RAM declarations

extern EWRAM_DATA u8 *gUnknown_0203A14C;
extern EWRAM_DATA u8 gUnknown_0203A150;
extern EWRAM_DATA u8 gUnknown_0203A173;
extern EWRAM_DATA struct DecoPCPointers gUnknown_0203A17C;
extern EWRAM_DATA u8 gUnknown_0203A188[4];

// Static ROM declarations

void sub_8126B80(u8 taskId);
void sub_8126C08(void);
void sub_8126DA4(u8 taskId);
void sub_8126D6C(u8 taskId);
void sub_8126DCC(u8 taskId);

// .rodata

extern const struct WindowTemplate gUnknown_085A6B90[4];
extern const struct MenuAction gUnknown_085A6B48[];
extern const u8 *gUnknown_085A6B68[];

// .text

void sub_8126968(void)
{
    if (gUnknown_0203A173 < 8)
    {
        gUnknown_0203A14C = gDecorationInventories[gUnknown_0203A173].items;
    }
    if (gUnknown_0203A17C.isPlayerRoom == FALSE)
    {
        gUnknown_0203A17C.items = gSaveBlock1Ptr->secretBases[0].decorations;
        gUnknown_0203A17C.pos = gSaveBlock1Ptr->secretBases[0].decorationPos;
    }
    if (gUnknown_0203A17C.isPlayerRoom == TRUE)
    {
        gUnknown_0203A17C.items = gSaveBlock1Ptr->playerRoomDecor;
        gUnknown_0203A17C.pos = gSaveBlock1Ptr->playerRoomDecorPos;
    }
}

u8 sub_81269D4(u8 idx)
{
    u8 *winidx;
    struct WindowTemplate template;

    winidx = &gUnknown_0203A188[idx];
    if (idx == 0)
    {
        template = gUnknown_085A6B90[0];
        template.width = GetMaxWidthInMenuTable(gUnknown_085A6B48, 4);
        if (template.width > 18)
        {
            template.width = 18;
        }
        *winidx = AddWindow(&template);
    }
    else
    {
        *winidx = AddWindow(&gUnknown_085A6B90[idx]);
    }
    SetWindowBorderStyle(*winidx, 0, 0x214, 0xe);
    schedule_bg_copy_tilemap_to_vram(0);
    return *winidx;
}

void sub_8126A58(u8 idx)
{
    sub_8198070(gUnknown_0203A188[idx], FALSE);
    ClearWindowTilemap(gUnknown_0203A188[idx]);
    RemoveWindow(gUnknown_0203A188[idx]);
    schedule_bg_copy_tilemap_to_vram(0);
}

void sub_8126A88(void)
{
    u8 idx;

    idx = sub_81269D4(0);
    PrintMenuTable(idx, 4, gUnknown_085A6B48);
    InitMenuInUpperLeftCornerPlaySoundWhenAPressed(idx, 4, gUnknown_0203A150);
}

void sub_8126ABC(void)
{
    gUnknown_0203A150 = 0;
    ScriptContext2_Enable();
    sub_8126A88();
    sub_8126C08();
}

void sub_8126AD8(u8 taskId)
{
    sub_8126ABC();
    gUnknown_0203A17C.items = gSaveBlock1Ptr->secretBases[0].decorations;
    gUnknown_0203A17C.pos = gSaveBlock1Ptr->secretBases[0].decorationPos;
    gUnknown_0203A17C.size = sizeof(gSaveBlock1Ptr->secretBases[0].decorations);
    gUnknown_0203A17C.isPlayerRoom = FALSE;
    gTasks[taskId].func = sub_8126B80;
}

void sub_8126B2C(u8 taskId)
{
    sub_8126ABC();
    gUnknown_0203A17C.items = gSaveBlock1Ptr->playerRoomDecor;
    gUnknown_0203A17C.pos = gSaveBlock1Ptr->playerRoomDecorPos;
    gUnknown_0203A17C.size = sizeof(gSaveBlock1Ptr->playerRoomDecor);
    gUnknown_0203A17C.isPlayerRoom = TRUE;
    gTasks[taskId].func = sub_8126B80;
}

void sub_8126B80(u8 taskId)
{
    u8 menuPos;

    if (!gPaletteFade.active)
    {
        menuPos = GetMenuCursorPos();
        switch (ProcessMenuInput())
        {
            default:
                PlaySE(SE_SELECT);
                gUnknown_085A6B48[gUnknown_0203A150].func.void_u8(taskId);
                break;
            case -2:
                gUnknown_0203A150 = GetMenuCursorPos();
                if ((s8)menuPos != gUnknown_0203A150)
                {
                    sub_8126C08();
                }
                break;
            case -1:
                PlaySE(SE_SELECT);
                sub_8126D6C(taskId);
                break;
        }
    }
}

void sub_8126C08(void)
{
    FillWindowPixelBuffer(0, 0x11);
    AddTextPrinterParametrized(0, 1, gUnknown_085A6B68[gUnknown_0203A150], 0, 0, 2, 1, 3);
}

void sub_8126C48(u8 taskId)
{
    if (CountDecorations() == 0)
    {
        StringExpandPlaceholders(gStringVar4, gText_NoDecorations);
        DisplayItemMessageOnField(taskId, gStringVar4, sub_8126DA4);
    }
    else
    {
        gTasks[taskId].data[11] = 0;
        gUnknown_0203A173 = DECORCAT_DESK;
        sub_8126DCC(taskId);
    }
}
