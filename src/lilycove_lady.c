//
// Created by Scott Norton on 9/19/17.
//

#include "global.h"
#include "main.h"
#include "event_data.h"
#include "script.h"
#include "rng.h"
#include "string_util.h"
#include "item.h"
#include "items.h"
#include "item_menu.h"
#include "text.h"
#include "lilycove_lady.h"

void SetLilycoveQuizLady(void);
void SetLilycoveFavourLady(void);
void SetLilycoveContestLady(void);
void sub_818E004(void);
void sub_818DBC4(void);
void sub_818E674(void);

extern const u16 gUnknown_0860B074[5];
extern const u16 gUnknown_0860B07E[3];
extern const u8 *const gUnknown_0860B224[];
extern const u16 *const gUnknown_0860B2EC[6];
extern const u16 gUnknown_0860B304[6];
extern const u16 *const gUnknown_0860B1A4[16];
extern const u16 gUnknown_0860B1E4[16];
extern const u16 gUnknown_0860B204[16];

EWRAM_DATA struct LilycoveLadyFavour *gUnknown_0203CD64 = NULL;
EWRAM_DATA struct LilycoveLadyQuiz *gUnknown_0203CD68 = NULL;
extern EWRAM_DATA u16 gScriptItemId;

u8 GetLilycoveLadyId(void)
{
    return gSaveBlock1Ptr->lilycoveLady.common.id;
}

void sub_818D9C0(void)
{
    LilycoveLady *lilycoveLady;

    VarSet(VAR_0x4010, gUnknown_0860B07E[GetLilycoveLadyId()]);
    if (GetLilycoveLadyId() == LILYCOVE_LADY_CONTEST)
    {
        lilycoveLady = &gSaveBlock1Ptr->lilycoveLady;
        VarSet(VAR_0x4011, gUnknown_0860B074[lilycoveLady->contest.category]);
        gScriptResult = TRUE;
    }
    else
    {
        gScriptResult = FALSE;
    }
}

void SetLilycoveLady(void)
{
    u16 id;

    id = ((gSaveBlock2Ptr->playerTrainerId[1] << 8) | gSaveBlock2Ptr->playerTrainerId[0]);
    id %= 6;
    id >>= 1;
    switch (id)
    {
        case LILYCOVE_LADY_QUIZ:
            SetLilycoveQuizLady();
            break;
        case LILYCOVE_LADY_FAVOUR:
            SetLilycoveFavourLady();
            break;
        case LILYCOVE_LADY_CONTEST:
            SetLilycoveContestLady();
            break;
    }
}

void sub_818DA78(void)
{
    switch (GetLilycoveLadyId())
    {
        case LILYCOVE_LADY_QUIZ:
            sub_818E004();
            break;
        case LILYCOVE_LADY_FAVOUR:
            sub_818DBC4();
            break;
        case LILYCOVE_LADY_CONTEST:
            sub_818E674();
            break;
    }
}

void SetLilycoveLadyRandomly(void)
{
    u8 id;

    id = Random() % 3;
    switch (id)
    {
        case LILYCOVE_LADY_QUIZ:
            SetLilycoveQuizLady();
            break;
        case LILYCOVE_LADY_FAVOUR:
            SetLilycoveFavourLady();
            break;
        case LILYCOVE_LADY_CONTEST:
            SetLilycoveContestLady();
            break;
    }
}

void sub_818DAEC(void)
{
    gScriptResult = GetLilycoveLadyId();
}

u8 sub_818DB04(const u16 *data)
{
    u8 len;

    for (len = 0; *data != 0; len ++, data ++);
    return len;
}

void sub_818DB20(void)
{
    u8 size;
    u8 idx;

    gUnknown_0203CD64->unk_00c = Random() % 6;
    size = sub_818DB04(gUnknown_0860B2EC[gUnknown_0203CD64->unk_00c]);
    idx = Random() % size;
    gUnknown_0203CD64->unk_010 = gUnknown_0860B2EC[gUnknown_0203CD64->unk_00c][idx];
}

void SetLilycoveFavourLady(void)
{
    gUnknown_0203CD64 = &gSaveBlock1Ptr->lilycoveLady.favour;
    gUnknown_0203CD64->id = LILYCOVE_LADY_FAVOUR;
    gUnknown_0203CD64->unk_001 = 0;
    gUnknown_0203CD64->unk_004[0] = EOS;
    gUnknown_0203CD64->unk_002 = 0;
    gUnknown_0203CD64->unk_003= 0;
    gUnknown_0203CD64->itemId = ITEM_NONE;
    gUnknown_0203CD64->language = gGameLanguage;
    sub_818DB20();
}

void sub_818DBC4(void)
{
    gUnknown_0203CD64 = &gSaveBlock1Ptr->lilycoveLady.favour;
    gUnknown_0203CD64->id = LILYCOVE_LADY_FAVOUR;
    gUnknown_0203CD64->unk_001 = 0;
}

u8 sub_818DBE8(void)
{
    gUnknown_0203CD64 = &gSaveBlock1Ptr->lilycoveLady.favour;
    if (gUnknown_0203CD64->unk_001 == 2)
    {
        return 2;
    }
    else if (gUnknown_0203CD64->unk_001 == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

const u8 *sub_818DC1C(u8 idx)
{
    return gUnknown_0860B224[idx];
}

void sub_818DC2C(void)
{
    gUnknown_0203CD64 = &gSaveBlock1Ptr->lilycoveLady.favour;
    StringCopy(gStringVar1, sub_818DC1C(gUnknown_0203CD64->unk_00c));
}

bool8 sub_818DC60(void)
{
    gUnknown_0203CD64 = &gSaveBlock1Ptr->lilycoveLady.favour;
    if (gUnknown_0203CD64->unk_004[0] != EOS)
    {
        StringCopy7(gStringVar3, gSaveBlock1Ptr->lilycoveLady.favour.unk_004);
        ConvertInternationalString(gStringVar3, gUnknown_0203CD64->language);
        return TRUE;
    }
    return FALSE;
}

void sub_818DCAC(u8 *dest, u16 itemId)
{
    StringCopy(dest, ItemId_GetItem(itemId)->name);
}

void sub_818DCC8(void)
{
    gUnknown_0203CD64 = &gSaveBlock1Ptr->lilycoveLady.favour;
    sub_818DCAC(gStringVar2, gUnknown_0203CD64->itemId);
}

void sub_818DCF4(const u8 *src, u8 *dest)
{
    memset(dest, 0xFF, 8);
    StringCopy7(dest, src);
}

void sub_818DD14(void)
{
    gUnknown_0203CD64 = &gSaveBlock1Ptr->lilycoveLady.favour;
    sub_818DCF4(gSaveBlock1Ptr->lilycoveLady.favour.unk_004, gStringVar3);
    ConvertInternationalString(gStringVar3, gUnknown_0203CD64->language);
}

bool8 sub_818DD54(void)
{
    gUnknown_0203CD64 = &gSaveBlock1Ptr->lilycoveLady.favour;
    return gUnknown_0203CD64->unk_002 ? TRUE : FALSE;
}

void sub_818DD78(void)
{
    sub_81AAC50();
}

bool8 sub_818DD84(u16 itemId)
{
    u8 len;
    u8 i;
    bool8 response;

    gUnknown_0203CD64 = &gSaveBlock1Ptr->lilycoveLady.favour;
    len = sub_818DB04(gUnknown_0860B2EC[gUnknown_0203CD64->unk_00c]);
    gUnknown_0203CD64->unk_001 = 1;
    sub_818DCAC(gStringVar2, itemId);
    gUnknown_0203CD64->itemId = itemId;
    sub_818DCF4(gSaveBlock2Ptr->playerName, gUnknown_0203CD64->unk_004);
    gUnknown_0203CD64->language = gGameLanguage;
    response = FALSE;
    for (i = 0; i < len; i ++)
    {
        if (gUnknown_0860B2EC[gUnknown_0203CD64->unk_00c][i] == itemId)
        {
            response = TRUE;
            gUnknown_0203CD64->unk_003 ++;
            gUnknown_0203CD64->unk_002 = 1;
            if (gUnknown_0203CD64->unk_010 == itemId)
            {
                gUnknown_0203CD64->unk_003 = 5;
            }
            break;
        }
        gUnknown_0203CD64->unk_002 = 0;
    }
    return response;
}

bool8 sub_818DE44(void)
{
    return sub_818DD84(gScriptItemId);
}

bool8 sub_818DE5C(void)
{
    u8 checkval;

    gUnknown_0203CD64 = &gSaveBlock1Ptr->lilycoveLady.favour;
    checkval = gUnknown_0203CD64->unk_003;
    return checkval < 5 ? FALSE : TRUE;
}

void sub_818DE88(u16 itemId)
{
    sub_818DCAC(gStringVar2, itemId);
}

u16 sub_818DEA0(void)
{
    u16 itemId;

    gUnknown_0203CD64 = &gSaveBlock1Ptr->lilycoveLady.favour;
    itemId = gUnknown_0860B304[gUnknown_0203CD64->unk_00c];
    sub_818DE88(itemId);
    gUnknown_0203CD64->unk_001 = 2;
    return itemId;
}

void sub_818DEDC(void)
{
    SetLilycoveFavourLady();
    gUnknown_0203CD64->unk_001 = 1;
}

void sub_818DEF4(void)
{
    EnableBothScriptContexts();
}

void sub_818DF00(void)
{
    u8 v0;
    u8 i;
    
    v0 = Random() % 16;
    for (i = 0; i < 9; i ++)
    {
        gUnknown_0203CD68->unk_002[i] = gUnknown_0860B1A4[v0][i];
    }
    gUnknown_0203CD68->unk_014 = gUnknown_0860B1E4[v0];
    gUnknown_0203CD68->unk_028 = gUnknown_0860B204[v0];
    gUnknown_0203CD68->unk_02b = v0;
    gUnknown_0203CD68->unk_018 = 0xFF;
}
