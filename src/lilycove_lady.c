//
// Created by Scott Norton on 9/19/17.
//

#include "global.h"
#include "main.h"
#include "event_data.h"
#include "rng.h"
#include "string_util.h"
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

EWRAM_DATA LilycoveLady *gUnknown_0203CD64 = NULL;

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

    gUnknown_0203CD64->favour.unk_00c = Random() % 6;
    size = sub_818DB04(gUnknown_0860B2EC[gUnknown_0203CD64->favour.unk_00c]);
    idx = Random() % size;
    gUnknown_0203CD64->favour.unk_010 = gUnknown_0860B2EC[gUnknown_0203CD64->favour.unk_00c][idx];
}

void SetLilycoveFavourLady(void)
{
    gUnknown_0203CD64 = &gSaveBlock1Ptr->lilycoveLady;
    gUnknown_0203CD64->favour.id = LILYCOVE_LADY_FAVOUR;
    gUnknown_0203CD64->favour.unk_001 = 0;
    gUnknown_0203CD64->favour.unk_004[0] = EOS;
    gUnknown_0203CD64->favour.unk_002 = 0;
    gUnknown_0203CD64->favour.unk_003= 0;
    gUnknown_0203CD64->favour.unk_00e = 0;
    gUnknown_0203CD64->favour.language = gGameLanguage;
    sub_818DB20();
}

void sub_818DBC4(void)
{
    gUnknown_0203CD64 = &gSaveBlock1Ptr->lilycoveLady;
    gUnknown_0203CD64->favour.id = LILYCOVE_LADY_FAVOUR;
    gUnknown_0203CD64->favour.unk_001 = 0;
}

u8 sub_818DBE8(void)
{
    gUnknown_0203CD64 = &gSaveBlock1Ptr->lilycoveLady;
    if (gUnknown_0203CD64->favour.unk_001 == 2)
    {
        return 2;
    }
    else if (gUnknown_0203CD64->favour.unk_001 == 1)
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
    gUnknown_0203CD64 = &gSaveBlock1Ptr->lilycoveLady;
    StringCopy(gStringVar1, sub_818DC1C(gUnknown_0203CD64->favour.unk_00c));
}

bool8 sub_818DC60(void)
{
    gUnknown_0203CD64 = &gSaveBlock1Ptr->lilycoveLady;
    if (gUnknown_0203CD64->favour.unk_004[0] != EOS)
    {
        StringCopy7(gStringVar3, gSaveBlock1Ptr->lilycoveLady.favour.unk_004);
        ConvertInternationalString(gStringVar3, gUnknown_0203CD64->favour.language);
        return TRUE;
    }
    return FALSE;
}
