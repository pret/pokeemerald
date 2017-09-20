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
#include "easy_chat.h"
#include "lilycove_lady.h"

void SetLilycoveQuizLady(void);
void SetLilycoveFavourLady(void);
void SetLilycoveContestLady(void);
void sub_818E004(void);
void sub_818DBC4(void);
void sub_818E674(void);
bool32 sub_811F8D8(u16);
u8 sub_818E13C(void);
bool8 sub_818E1F4(void);
u8 sub_818E258(const u8 *);

extern const u16 gUnknown_0860B074[5];
extern const u16 gUnknown_0860B07E[3];
extern const u8 *const gUnknown_0860B224[];
extern const u16 *const gUnknown_0860B2EC[6];
extern const u16 gUnknown_0860B304[6];
extern const u16 *const gUnknown_0860B1A4[16];
extern const u16 gUnknown_0860B1E4[16];
extern const u16 gUnknown_0860B204[16];
extern const u8 gUnknown_085EEB7E[8];

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
    gUnknown_0203CD64->playerName[0] = EOS;
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
    if (gUnknown_0203CD64->playerName[0] != EOS)
    {
        StringCopy7(gStringVar3, gUnknown_0203CD64->playerName);
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
    sub_818DCF4(gUnknown_0203CD64->playerName, gStringVar3);
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
    sub_818DCF4(gSaveBlock2Ptr->playerName, gUnknown_0203CD64->playerName);
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
    gUnknown_0203CD68->itemId = gUnknown_0860B204[v0];
    gUnknown_0203CD68->unk_02b = v0;
    gUnknown_0203CD68->playerName[0] = EOS;
}

void SetLilycoveQuizLady(void)
{
    u8 i;

    gUnknown_0203CD68 = &gSaveBlock1Ptr->lilycoveLady.quiz;
    gUnknown_0203CD68->id = LILYCOVE_LADY_QUIZ;
    gUnknown_0203CD68->unk_001 = 0;
    for (i = 0; i < 9; i ++)
    {
        gUnknown_0203CD68->unk_002[i] = -1;
    }
    gUnknown_0203CD68->unk_014 = -1;
    gUnknown_0203CD68->unk_016 = -1;
    for (i = 0; i < 4; i ++)
    {
        gUnknown_0203CD68->playerTrainerId[i] = 0;
    }
    gUnknown_0203CD68->itemId = ITEM_NONE;
    gUnknown_0203CD68->unk_02a = 0;
    gUnknown_0203CD68->unk_02c = 0x10;
    gUnknown_0203CD68->language = gGameLanguage;
    sub_818DF00();
}

void sub_818E004(void)
{
    gUnknown_0203CD68 = &gSaveBlock1Ptr->lilycoveLady.quiz;
    gUnknown_0203CD68->id = LILYCOVE_LADY_QUIZ;
    gUnknown_0203CD68->unk_001 = 0;
    gUnknown_0203CD68->unk_02a = 0;
    gUnknown_0203CD68->unk_016 = -1;
}

u8 sub_818E038(void)
{
    gUnknown_0203CD68 = &gSaveBlock1Ptr->lilycoveLady.quiz;
    if (gUnknown_0203CD68->unk_001 == 2)
    {
        return 2;
    }
    else if (gUnknown_0203CD68->unk_001 == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

u8 sub_818E06C(void)
{
    int i;
    int j;
    u8 rv;
    struct LilycoveLadyQuiz *quiz;

    quiz = &gSaveBlock1Ptr->lilycoveLady.quiz;
    if (sub_811F8D8(quiz->unk_014) == 0)
   {
        i = quiz->unk_02b;
        do
        {
            if (++ i >= 16)
            {
                i = 0;
            }
        } while (sub_811F8D8(gUnknown_0860B1E4[i]) == 0);
        for (j = 0; j < 9; j ++)
        {
            quiz->unk_002[j] = gUnknown_0860B1A4[i][j];
        }
        quiz->unk_014 = gUnknown_0860B1E4[i];
        quiz->itemId = gUnknown_0860B204[i];
        quiz->unk_02b = i;
        quiz->playerName[0] = EOS;
    }
    rv = sub_818E13C();
    if (rv == 0)
    {
        return 2;
    }
    else if (rv == 2 || sub_818E1F4())
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

#ifdef NONMATCHING
u8 sub_818E13C(void)
{
    u8 retval;
    u8 len;
    u8 i;

    retval = 1;
    gUnknown_0203CD68 = &gSaveBlock1Ptr->lilycoveLady.quiz;
    if (gUnknown_0203CD68->playerName[0] == EOS)
    {
        StringCopy7(gStringVar1, gUnknown_085EEB7E);
        retval = 0;
    }
    else
    {
        StringCopy7(gStringVar1, gUnknown_0203CD68->playerName);
        ConvertInternationalString(gStringVar1, gUnknown_0203CD68->language);
        len = sub_818E258(gUnknown_0203CD68->playerName);
        if (len == sub_818E258(gSaveBlock2Ptr->playerName))
        {
            for (i = 0; i < len; i ++)
            {
                if (gUnknown_0203CD68->playerName[i] != gSaveBlock2Ptr->playerName[i])
                {
                    retval = 2;
                    break;
                }
            }
        }

    }
    return retval;
}
#else
__attribute__((naked)) u8 sub_818E13C(void)
{
    asm_unified("\tpush {r4-r7,lr}\n"
                    "\tmovs r7, 0x1\n"
                    "\tldr r5, =gUnknown_0203CD68\n"
                    "\tldr r0, =gSaveBlock1Ptr\n"
                    "\tldr r1, [r0]\n"
                    "\tldr r2, =0x00003b58\n"
                    "\tadds r0, r1, r2\n"
                    "\tstr r0, [r5]\n"
                    "\tldrb r0, [r0, 0x18]\n"
                    "\tcmp r0, 0xFF\n"
                    "\tbne _0818E174\n"
                    "\tldr r0, =gStringVar1\n"
                    "\tldr r1, =gUnknown_085EEB7E\n"
                    "\tbl StringCopy7\n"
                    "\tmovs r7, 0\n"
                    "\tb _0818E1DC\n"
                    "\t.pool\n"
                    "_0818E174:\n"
                    "\tldr r4, =gStringVar1\n"
                    "\tldr r0, =0x00003b70\n"
                    "\tadds r1, r0\n"
                    "\tadds r0, r4, 0\n"
                    "\tbl StringCopy7\n"
                    "\tldr r0, [r5]\n"
                    "\tadds r0, 0x2D\n"
                    "\tldrb r1, [r0]\n"
                    "\tadds r0, r4, 0\n"
                    "\tbl ConvertInternationalString\n"
                    "\tldr r0, [r5]\n"
                    "\tadds r0, 0x18\n"
                    "\tbl sub_818E258\n"
                    "\tlsls r0, 24\n"
                    "\tlsrs r4, r0, 24\n"
                    "\tldr r6, =gSaveBlock2Ptr\n"
                    "\tldr r0, [r6]\n"
                    "\tbl sub_818E258\n"
                    "\tlsls r0, 24\n"
                    "\tlsrs r0, 24\n"
                    "\tcmp r4, r0\n"
                    "\tbne _0818E1DC\n"
                    "\tldr r0, [r5]\n"
                    "\tmovs r2, 0\n"
                    "\tcmp r2, r4\n"
                    "\tbcs _0818E1DC\n"
                    "\tldr r1, [r6]\n"
                    "\tldrb r0, [r0, 0x18]\n"
                    "\tldrb r1, [r1]\n"
                    "\tcmp r0, r1\n"
                    "\tbne _0818E1DA\n"
                    "_0818E1BA:\n"
                    "\tadds r0, r2, 0x1\n"
                    "\tlsls r0, 24\n"
                    "\tlsrs r2, r0, 24\n"
                    "\tcmp r2, r4\n"
                    "\tbcs _0818E1DC\n"
                    "\tldr r0, =gUnknown_0203CD68\n"
                    "\tldr r1, [r0]\n"
                    "\tadds r1, 0x18\n"
                    "\tadds r1, r2\n"
                    "\tldr r0, =gSaveBlock2Ptr\n"
                    "\tldr r0, [r0]\n"
                    "\tadds r0, r2\n"
                    "\tldrb r1, [r1]\n"
                    "\tldrb r0, [r0]\n"
                    "\tcmp r1, r0\n"
                    "\tbeq _0818E1BA\n"
                    "_0818E1DA:\n"
                    "\tmovs r7, 0x2\n"
                    "_0818E1DC:\n"
                    "\tadds r0, r7, 0\n"
                    "\tpop {r4-r7}\n"
                    "\tpop {r1}\n"
                    "\tbx r1\n"
                    "\t.pool");
}
#endif

u8 sub_818E1F4(void)
{
    bool8 response;
    u8 i;

    gUnknown_0203CD68 = &gSaveBlock1Ptr->lilycoveLady.quiz;
    response = FALSE;
    for (i = 0; i < 4; i ++)
    {
        if (gUnknown_0203CD68->playerTrainerId[i] != gSaveBlock2Ptr->playerTrainerId[i])
        {
            response = TRUE;
            break;
        }
    }
    return response;
}

u8 sub_818E258(const u8 *str)
{
    u8 len;
    const u8 *ptr;

    for (len = 0, ptr = str; *ptr != EOS; len ++, ptr ++);
    return len;
}

void sub_818E274(void)
{
    StringCopy(gStringVar1, ItemId_GetItem(gUnknown_0203CD68->itemId)->name);
}

bool8 sub_818E298(void)
{
    gUnknown_0203CD68 = &gSaveBlock1Ptr->lilycoveLady.quiz;
    if (!sub_818E13C())
    {
        gUnknown_0203CD68->language = gGameLanguage;
        return TRUE;
    }
    return FALSE;
}

u8 sub_818E2D8(void)
{
    gUnknown_0203CD68 = &gSaveBlock1Ptr->lilycoveLady.quiz;
    return gUnknown_0203CD68->unk_02a;
}

void sub_818E2FC(void)
{
    easy_chat_input_maybe();
}

bool8 sub_818E308(void)
{
    gUnknown_0203CD68 = &gSaveBlock1Ptr->lilycoveLady.quiz;
    CopyEasyChatWord(gStringVar1, gUnknown_0203CD68->unk_014);
    CopyEasyChatWord(gStringVar2, gUnknown_0203CD68->unk_016);
    return StringCompare(gStringVar1, gStringVar2) ? FALSE : TRUE;
}

void sub_818E358(void)
{
    gUnknown_0203CD68 = &gSaveBlock1Ptr->lilycoveLady.quiz;
    gSpecialVar_0x8005 = gUnknown_0203CD68->itemId;
}

void sub_818E37C(void)
{
    gUnknown_0203CD68 = &gSaveBlock1Ptr->lilycoveLady.quiz;
    gUnknown_0203CD68->unk_001 = 1;
}

void sub_818E39C(void)
{
    gUnknown_0203CD68 = &gSaveBlock1Ptr->lilycoveLady.quiz;
    gUnknown_0203CD68->unk_001 = 2;
}

void sub_818E3BC(void)
{
    gUnknown_0203CD68 = &gSaveBlock1Ptr->lilycoveLady.quiz;
    gUnknown_0203CD68->unk_016 = -1;
}

void sub_818E3E0(void)
{
    sub_81AAC70();
}
