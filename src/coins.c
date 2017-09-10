#include "global.h"
#include "coins.h"
#include "text.h"
#include "window.h"
#include "text_window.h"
#include "string_util.h"

#define MAX_COINS 9999

EWRAM_DATA u8 sCoinsWindowId = 0;

extern s32 GetStringRightAlignXOffset(u8 fontId, u8 *str, s32 totalWidth);
extern void SetWindowTemplateFields(struct WindowTemplate* template, u8 priority, u8 tilemapLeft, u8 tilemapTop, u8 width, u8 height, u8 palNum, u16 baseBlock);
extern void SetWindowBorderStyle(u8 windowId, bool8 copyToVram, s16 tileStart, s8 palette);
extern void sub_819746C(u8 windowId, bool8 copyToVram);

extern const u8 gOtherText_Coins2[];

void PrintCoinsString(u32 coinAmount)
{
    u32 xAlign;

    ConvertIntToDecimalStringN(gStringVar1, coinAmount, STR_CONV_MODE_RIGHT_ALIGN, 4);
    StringExpandPlaceholders(gStringVar4, gOtherText_Coins2);

    xAlign = GetStringRightAlignXOffset(1, gStringVar4, 0x40);
    PrintTextOnWindow(sCoinsWindowId, 1, gStringVar4, xAlign, 1, 0, NULL);
}

void ShowCoinsWindow(u32 coinAmount, u8 x, u8 y)
{
    struct WindowTemplate template;
    SetWindowTemplateFields(&template, 0, x, y, 8, 2, 0xF, 0x141);
    sCoinsWindowId = AddWindow(&template);
    FillWindowPixelBuffer(sCoinsWindowId, 0);
    PutWindowTilemap(sCoinsWindowId);
    SetWindowBorderStyle(sCoinsWindowId, FALSE, 0x214, 0xE);
    PrintCoinsString(coinAmount);
}

void HideCoinsWindow(void)
{
    sub_819746C(sCoinsWindowId, TRUE);
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

/* Can't match it lol
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
        newAmount = ownedCoins + toAdd;
        if (newAmount > MAX_COINS)
            newAmount = MAX_COINS;
    }
    SetCoins(newAmount);
    return TRUE;
}*/
