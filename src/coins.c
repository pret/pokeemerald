#include "global.h"
#include "coins.h"
#include "text.h"
#include "window.h"
#include "strings.h"
#include "string_util.h"
#include "menu.h"
#include "international_string_util.h"
#include "constants/coins.h"

static EWRAM_DATA u8 sCoinsWindowId = 0;

void PrintCoinsString(u32 coinAmount)
{
    u32 xAlign;

    ConvertIntToDecimalStringN(gStringVar1, coinAmount, STR_CONV_MODE_RIGHT_ALIGN, MAX_COIN_DIGITS);
    StringExpandPlaceholders(gStringVar4, gText_Coins);

#if ENGLISH
    xAlign = GetStringRightAlignXOffset(FONT_NORMAL, gStringVar4, 0x40);
    AddTextPrinterParameterized(sCoinsWindowId, FONT_NORMAL, gStringVar4, xAlign, 1, 0, NULL);
#elif FRENCH
    xAlign = GetStringRightAlignXOffset(FONT_NARROW, gStringVar4, 0x38);
    AddTextPrinterParameterized(sCoinsWindowId, FONT_NARROW, gStringVar4, xAlign, 1, 0, NULL);
#elif ITALIAN
    xAlign = GetStringRightAlignXOffset(FONT_NARROW, gStringVar4, 0x30);
    AddTextPrinterParameterized(sCoinsWindowId, FONT_NARROW, gStringVar4, xAlign, 1, 0, NULL);
#endif
}

void ShowCoinsWindow(u32 coinAmount, u8 x, u8 y)
{
    struct WindowTemplate template;

#if ENGLISH
    SetWindowTemplateFields(&template, 0, x, y, 8, 2, 0xF, 0x141);
#elif FRENCH
    SetWindowTemplateFields(&template, 0, x, y, 7, 2, 0xF, 0x141);
#elif ITALIAN
    SetWindowTemplateFields(&template, 0, x, y, 6, 2, 0xF, 0x141);
#endif
    sCoinsWindowId = AddWindow(&template);
    FillWindowPixelBuffer(sCoinsWindowId, PIXEL_FILL(0));
    PutWindowTilemap(sCoinsWindowId);
    DrawStdFrameWithCustomTileAndPalette(sCoinsWindowId, FALSE, 0x214, 0xE);
    PrintCoinsString(coinAmount);
}

void HideCoinsWindow(void)
{
    ClearStdWindowAndFrame(sCoinsWindowId, TRUE);
    RemoveWindow(sCoinsWindowId);
}

u16 GetCoins(void)
{
    return gSaveBlock1Ptr->coins ^ gSaveBlock2Ptr->encryptionKey;
}

void SetCoins(u16 coinAmount)
{
    gSaveBlock1Ptr->coins = coinAmount ^ gSaveBlock2Ptr->encryptionKey;
}

bool8 AddCoins(u16 toAdd)
{
    u16 newAmount;
    u16 ownedCoins = GetCoins();
    if (ownedCoins >= MAX_COINS)
        return FALSE;
    // check overflow, can't have less coins than previously
    if (ownedCoins > ownedCoins + toAdd)
    {
        newAmount = MAX_COINS;
    }
    else
    {
        ownedCoins += toAdd;
        if (ownedCoins > MAX_COINS)
            ownedCoins = MAX_COINS;
        newAmount = ownedCoins;
    }
    SetCoins(newAmount);
    return TRUE;
}

bool8 RemoveCoins(u16 toSub)
{
    u16 ownedCoins = GetCoins();
    if (ownedCoins >= toSub)
    {
        SetCoins(ownedCoins - toSub);
        return TRUE;
    }
    return FALSE;
}
