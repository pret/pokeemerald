
// Includes
#include "global.h"
#include "menu.h"
#include "decoration.h"
#include "decoration_inventory.h"
#include "international_string_util.h"

// Static type declarations

// Static RAM declarations

extern EWRAM_DATA u8 *gUnknown_0203A14C;
extern EWRAM_DATA u8 gUnknown_0203A150;
extern EWRAM_DATA u8 gUnknown_0203A173;
extern EWRAM_DATA struct DecoPCPointers gUnknown_0203A17C;
extern EWRAM_DATA u8 gUnknown_0203A188[4];

// Static ROM declarations

// .rodata

extern const struct WindowTemplate gUnknown_085A6B90[4];
extern const u8 *const gUnknown_085A6B48[];

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
