#include "global.h"
#include "berry_powder.h"
#include "bg.h"
#include "event_data.h"
#include "load_save.h"
#include "menu.h"
#include "string_util.h"
#include "strings.h"
#include "text.h"
#include "text_window.h"
#include "window.h"

#define MAX_BERRY_POWDER 99999

static EWRAM_DATA u8 sBerryPowderVendorWindowId = 0;

// Unused
static const struct BgTemplate sBerryPowderBgTemplates[] =
{
    {
        .bg = 0,
        .charBaseIndex = 0,
        .mapBaseIndex = 30,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0
    },
    {
        .bg = 1,
        .charBaseIndex = 2,
        .mapBaseIndex = 12,
        .screenSize = 1,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0
    },
    {
        .bg = 2,
        .charBaseIndex = 2,
        .mapBaseIndex = 14,
        .screenSize = 1,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0
    },
    {
        .bg = 3,
        .charBaseIndex = 3,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 0
    },
};

// ? Part of the BG templates?
static const u32 sUnknown[] = {0xFF, 0x00};

// Unused
static const struct WindowTemplate sBerryPowderWindowTemplates[] =
{
    {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 1,
        .width = 28,
        .height = 2,
        .paletteNum = 13,
        .baseBlock = 19
    },
    {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 5,
        .width = 28,
        .height = 14,
        .paletteNum = 13,
        .baseBlock = 75
    },
    {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 5,
        .width = 28,
        .height = 7,
        .paletteNum = 13,
        .baseBlock = 75
    },
    {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 8,
        .width = 19,
        .height = 3,
        .paletteNum = 13,
        .baseBlock = 19
    },
    {
        .bg = 0,
        .tilemapLeft = 22,
        .tilemapTop = 7,
        .width = 6,
        .height = 4,
        .paletteNum = 13,
        .baseBlock = 76
    },
    {
        .bg = 0,
        .tilemapLeft = 4,
        .tilemapTop = 6,
        .width = 22,
        .height = 5,
        .paletteNum = 13,
        .baseBlock = 19
    },
    {
        .bg = 0,
        .tilemapLeft = 5,
        .tilemapTop = 8,
        .width = 19,
        .height = 3,
        .paletteNum = 13,
        .baseBlock = 19
    },
};

static u32 DecryptBerryPowder(u32 *powder)
{
    return *powder ^ gSaveBlock2Ptr->encryptionKey;
}

void SetBerryPowder(u32 *powder, u32 amount)
{
    *powder = amount ^ gSaveBlock2Ptr->encryptionKey;
}

void ApplyNewEncryptionKeyToBerryPowder(u32 encryptionKey)
{
    u32 *powder = &gSaveBlock2Ptr->berryCrush.berryPowderAmount;
    ApplyNewEncryptionKeyToWord(powder, encryptionKey);
}

static bool8 HasEnoughBerryPowder_(u32 cost)
{
    u32 *powder = &gSaveBlock2Ptr->berryCrush.berryPowderAmount;
    if (DecryptBerryPowder(powder) < cost)
        return FALSE;
    else
        return TRUE;
}

bool8 HasEnoughBerryPowder(void)
{
    u32 *powder = &gSaveBlock2Ptr->berryCrush.berryPowderAmount;
    if (DecryptBerryPowder(powder) < gSpecialVar_0x8004)
        return FALSE;
    else
        return TRUE;
}

bool8 GiveBerryPowder(u32 amountToAdd)
{
    u32 *powder = &gSaveBlock2Ptr->berryCrush.berryPowderAmount;
    u32 amount = DecryptBerryPowder(powder) + amountToAdd;
    if (amount > MAX_BERRY_POWDER)
    {
        SetBerryPowder(powder, MAX_BERRY_POWDER);
        return FALSE;
    }
    else
    {
        SetBerryPowder(powder, amount);
        return TRUE;
    }
}

static bool8 TakeBerryPowder_(u32 cost)
{
    u32 *powder = &gSaveBlock2Ptr->berryCrush.berryPowderAmount;
    if (!HasEnoughBerryPowder_(cost))
        return FALSE;

    SetBerryPowder(powder, DecryptBerryPowder(powder) - cost);
    return TRUE;
}

bool8 TakeBerryPowder(void)
{
    u32 *powder = &gSaveBlock2Ptr->berryCrush.berryPowderAmount;
    if (!HasEnoughBerryPowder_(gSpecialVar_0x8004))
        return FALSE;

    SetBerryPowder(powder, DecryptBerryPowder(powder) - gSpecialVar_0x8004);
    return TRUE;
}

u32 GetBerryPowder(void)
{
    u32 *powder = &gSaveBlock2Ptr->berryCrush.berryPowderAmount;
    return DecryptBerryPowder(powder);
}

static void PrintBerryPowderAmount(u8 windowId, int amount, u8 x, u8 y, u8 speed)
{
    ConvertIntToDecimalStringN(gStringVar1, amount, STR_CONV_MODE_RIGHT_ALIGN, 5);
    AddTextPrinterParameterized(windowId, FONT_NORMAL, gStringVar1, x, y, speed, NULL);
}

static void DrawPlayerPowderAmount(u8 windowId, u16 baseTileOffset, u8 paletteNum, u32 amount)
{
    DrawStdFrameWithCustomTileAndPalette(windowId, FALSE, baseTileOffset, paletteNum);
    AddTextPrinterParameterized(windowId, FONT_NORMAL, gText_Powder, 0, 1, TEXT_SKIP_DRAW, NULL);
    PrintBerryPowderAmount(windowId, amount, 26, 17, 0);
}

void PrintPlayerBerryPowderAmount(void)
{
    u32 amount = GetBerryPowder();
    PrintBerryPowderAmount(sBerryPowderVendorWindowId, amount, 26, 17, 0);
}

void DisplayBerryPowderVendorMenu(void)
{
    struct WindowTemplate template;
    SetWindowTemplateFields(&template, 0, 1, 1, 7, 4, 15, 0x1C);
    sBerryPowderVendorWindowId = AddWindow(&template);
    FillWindowPixelBuffer(sBerryPowderVendorWindowId, PIXEL_FILL(0));
    PutWindowTilemap(sBerryPowderVendorWindowId);
    LoadUserWindowBorderGfx_(sBerryPowderVendorWindowId, 0x21D, 0xD0);
    DrawPlayerPowderAmount(sBerryPowderVendorWindowId, 0x21D, 13, GetBerryPowder());
}

void RemoveBerryPowderVendorMenu(void)
{
    ClearWindowTilemap(sBerryPowderVendorWindowId);
    ClearStdWindowAndFrameToTransparent(sBerryPowderVendorWindowId, TRUE);
    RemoveWindow(sBerryPowderVendorWindowId);
}
