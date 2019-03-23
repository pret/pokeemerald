//
// Created by Scott Norton on 9/19/17.
//

#include "global.h"
#include "main.h"
#include "overworld.h"
#include "fldeff.h"
#include "field_specials.h"
#include "pokeblock.h"
#include "event_data.h"
#include "script.h"
#include "random.h"
#include "string_util.h"
#include "item.h"
#include "constants/items.h"
#include "item_menu.h"
#include "text.h"
#include "easy_chat.h"
#include "lilycove_lady.h"

static void SetLilycoveQuizLady(void);
static void SetLilycoveFavourLady(void);
static void SetLilycoveContestLady(void);
static void sub_818E004(void);
static void sub_818DBC4(void);
static void sub_818E674(void);
static u8 sub_818E13C(void);
static bool8 sub_818E1F4(void);
static u8 sub_818E258(const u8 *);

extern const u8 gText_Lady2[];

static const u16 sUnknown_0860B074[] = {
        0x62, 0xcb, 0xdc, 0xcc, 0xd1
};
static const u16 sUnknown_0860B07E[] = {
        0x1a, 0x14, 0x0a
};

static const u16 Unknown_0860B084[] = {
        0x101b, 0x1623, 0x1812, 0x102c, 0x020e, 0x0c03, 0x1a0b, 0x0210, 0x020d
};

static const u16 Unknown_0860B096[] = {
        0x101b, 0x1013, 0x1020, 0x1a0f, 0x020c, 0x0c03, 0x0211, 0x0203, 0x0400
};

static const u16 Unknown_0860B0A8[] = {
        0x0e0f, 0x1018, 0x020e, 0x0204, 0x0c03, 0xffff, 0x0212, 0x0451, 0x0463
};

static const u16 Unknown_0860B0BA[] = {
        0x101b, 0x100b, 0x0e0d, 0x141a, 0x181d, 0x0c03, 0x141e, 0x1a26, 0x1823
};

static const u16 Unknown_0860B0CC[] = {
        0x101b, 0x181d, 0x1018, 0x0a02, 0x2014, 0x0c03, 0x0208, 0x1824, 0x181c
};

static const u16 Unknown_0860B0DE[] = {
        0x101b, 0x1000, 0x1c19, 0x265d, 0x0c03, 0xffff, 0x0447, 0x045d, 0x042c
};

static const u16 Unknown_0860B0F0[] = {
        0x101b, 0x1034, 0x1e11, 0x100b, 0x1a08, 0x0c03, 0x044b, 0x0446, 0x040a
};

static const u16 Unknown_0860B102[] = {
        0x101b, 0x1000, 0x274f, 0x0626, 0x0c03, 0xffff, 0x0442, 0x0411, 0x0450
};

static const u16 Unknown_0860B114[] = {
        0x101b, 0x1000, 0x1c19, 0x043c, 0x0c03, 0xffff, 0x0421, 0x0464, 0x0435
};

static const u16 Unknown_0860B126[] = {
        0x101b, 0x1203, 0x1030, 0x0207, 0x0c03, 0xffff, 0x0210, 0x020e, 0x020d
};

static const u16 Unknown_0860B138[] = {
        0x101b, 0x1623, 0x0a05, 0x020e, 0x0c03, 0xffff, 0x1a25, 0x181a, 0x181b
};

static const u16 Unknown_0860B14A[] = {
        0x101b, 0x1823, 0x1603, 0x0a02, 0x1812, 0x0c03, 0x1a15, 0x1a23, 0x181b
};

static const u16 Unknown_0860B15C[] = {
        0x1020, 0x020e, 0x1010, 0x1043, 0x1e0f, 0x0c03, 0x181c, 0x1a24, 0x1816
};

static const u16 Unknown_0860B16E[] = {
        0x0446, 0x100b, 0x0620, 0x061c, 0x101b, 0x0c03, 0x0420, 0x0426, 0xffff
};

static const u16 Unknown_0860B180[] = {
        0x0400, 0x100b, 0x0639, 0x061c, 0x101b, 0x0c03, 0x040e, 0x0410, 0xffff
};

static const u16 Unknown_0860B192[] = {
        0x041f, 0x100b, 0x0639, 0x061c, 0x101b, 0x0c03, 0x0445, 0x0400, 0xffff
};

static const u16 *const gUnknown_0860B1A4[] = {
        Unknown_0860B084,
        Unknown_0860B096,
        Unknown_0860B0A8,
        Unknown_0860B0BA,
        Unknown_0860B0CC,
        Unknown_0860B0DE,
        Unknown_0860B0F0,
        Unknown_0860B102,
        Unknown_0860B114,
        Unknown_0860B126,
        Unknown_0860B138,
        Unknown_0860B14A,
        Unknown_0860B15C,
        Unknown_0860B16E,
        Unknown_0860B180,
        Unknown_0860B192
};

static const u16 sUnknown_0860B1E4[] = {
        0x0210, 0x0400, 0x0212, 0x1a26, 0x0208, 0x045d, 0x040a, 0x0411, 0x0464, 0x020e, 0x1a25, 0x181b, 0x1a24, 0x0420, 0x0410, 0x0400
};

static const u16 sUnknown_0860B204[] = {
        0x007b, 0x007f, 0x0081, 0x0023, 0x0023, 0x0023, 0x00a5, 0x00a7, 0x00a6, 0x000b, 0x012f, 0x006b, 0x006d, 0x0044, 0x0044, 0x000c
};

extern const u8 gUnknown_085EEB83[];
extern const u8 gUnknown_085EEB8C[];
extern const u8 gUnknown_085EEB95[];
extern const u8 gUnknown_085EEB9E[];
extern const u8 gUnknown_085EEBA4[];
extern const u8 gUnknown_085EEBAB[];

static const u8 *const gUnknown_0860B224[] = {
        gUnknown_085EEB83,
        gUnknown_085EEB8C,
        gUnknown_085EEB95,
        gUnknown_085EEB9E,
        gUnknown_085EEBA4,
        gUnknown_085EEBAB
};

static const u16 Unknown_0860B23C[] = {
        0x0056, 0x0053, 0x0054, 0x000e, 0x0012, 0x000f, 0x00a7, 0x0011, 0x0010, 0x0018, 0x0019, 0x001e, 0x0000
};

static const u16 Unknown_0860B256[] = {
        0x0051, 0x006a, 0x006b, 0x00cc, 0x00c2, 0x002f, 0x0067, 0x0068, 0x0087, 0x0089, 0x008b, 0x009d, 0x00a0, 0x00a5, 0x0004, 0x0002, 0x0000
};

static const u16 Unknown_0860B278[] = {
        0x0021, 0x000d, 0x001a, 0x001b, 0x001c, 0x00cc, 0x00ca, 0x0026, 0x0086, 0x0096, 0x0097, 0x009a, 0x00a2, 0x00a6, 0x0000
};

static const u16 Unknown_0860B296[] = {
        0x0020, 0x004d, 0x004b, 0x004c, 0x0027, 0x0028, 0x0029, 0x002a, 0x002b, 0x006e, 0x005d, 0x006c, 0x006d, 0x006a, 0x006b, 0x00d6, 0x00bc, 0x00b3, 0x000b, 0x000c, 0x0000
};

static const u16 Unknown_0860B2C0[] = {
        0x001f, 0x0013, 0x0014, 0x004a, 0x004e, 0x0049, 0x00a5, 0x00c8, 0x0067, 0x006f, 0x0000
};

static const u16 Unknown_0860B2D6[] = {
        0x00b7, 0x00d3, 0x00d2, 0x00d8, 0x009e, 0x00a6, 0x00ab, 0x00aa, 0x006c, 0x006d, 0x0000
};

static const u16 *const gUnknown_0860B2EC[] = {
        Unknown_0860B23C,
        Unknown_0860B256,
        Unknown_0860B278,
        Unknown_0860B296,
        Unknown_0860B2C0,
        Unknown_0860B2D6
};

static const u16 sUnknown_0860B304[] = {
        0x0b, 0x6e, 0x40, 0x6f, 0x44, 0x47
};

extern const u8 gUnknown_085EEB2B[];
extern const u8 gUnknown_085EEB34[];
extern const u8 gUnknown_085EEB3A[];
extern const u8 gUnknown_085EEB41[];
extern const u8 gUnknown_085EEB4A[];
extern const u8 gUnknown_085EEB51[];
extern const u8 gUnknown_085EEB5A[];
extern const u8 gUnknown_085EEB61[];
extern const u8 gUnknown_085EEB6A[];
extern const u8 gUnknown_085EEB74[];
extern const u8 gUnknown_085EADA4[];
extern const u8 gUnknown_085EADB5[];
extern const u8 gUnknown_085EADC4[];
extern const u8 gUnknown_085EADD5[];
extern const u8 gUnknown_085EADE7[];

static const u8 *const gUnknown_0860B310[] = {
        gUnknown_085EEB2B,
        gUnknown_085EEB34,
        gUnknown_085EEB3A,
        gUnknown_085EEB41,
        gUnknown_085EEB4A
};
static const u8 *const gUnknown_0860B324[] = {
        gUnknown_085EEB51,
        gUnknown_085EEB5A,
        gUnknown_085EEB61,
        gUnknown_085EEB6A,
        gUnknown_085EEB74
};
static const u8 *const gUnknown_0860B338[] = {
        gUnknown_085EADA4,
        gUnknown_085EADB5,
        gUnknown_085EADC4,
        gUnknown_085EADD5,
        gUnknown_085EADE7
};

static const u16 sUnknown_0860B34C[] = {
        0x0120, 0x013b, 0x011e, 0x013d, 0x0019
};

static EWRAM_DATA struct LilycoveLadyFavour *gUnknown_0203CD64 = NULL;
static EWRAM_DATA struct LilycoveLadyQuiz *gUnknown_0203CD68 = NULL;
static EWRAM_DATA struct LilycoveLadyContest *gUnknown_0203CD6C = NULL;

extern EWRAM_DATA u16 gSpecialVar_ItemId;

u8 GetLilycoveLadyId(void)
{
    return gSaveBlock1Ptr->lilycoveLady.id;
}

void sub_818D9C0(void)
{
    LilycoveLady *lilycoveLady;

    VarSet(VAR_OBJ_GFX_ID_0, sUnknown_0860B07E[GetLilycoveLadyId()]);
    if (GetLilycoveLadyId() == LILYCOVE_LADY_CONTEST)
    {
        lilycoveLady = &gSaveBlock1Ptr->lilycoveLady;
        VarSet(VAR_OBJ_GFX_ID_1, sUnknown_0860B074[lilycoveLady->contest.category]);
        gSpecialVar_Result = TRUE;
    }
    else
    {
        gSpecialVar_Result = FALSE;
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
    gSpecialVar_Result = GetLilycoveLadyId();
}

static u8 sub_818DB04(const u16 *data)
{
    u8 len;

    for (len = 0; *data != 0; len ++, data ++);
    return len;
}

static void sub_818DB20(void)
{
    u8 size;
    u8 idx;

    gUnknown_0203CD64->unk_00c = Random() % 6;
    size = sub_818DB04(gUnknown_0860B2EC[gUnknown_0203CD64->unk_00c]);
    idx = Random() % size;
    gUnknown_0203CD64->unk_010 = gUnknown_0860B2EC[gUnknown_0203CD64->unk_00c][idx];
}

static void SetLilycoveFavourLady(void)
{
    gUnknown_0203CD64 = &gSaveBlock1Ptr->lilycoveLady.favour;
    gUnknown_0203CD64->id = LILYCOVE_LADY_FAVOUR;
    gUnknown_0203CD64->phase = 0;
    gUnknown_0203CD64->playerName[0] = EOS;
    gUnknown_0203CD64->unk_002 = 0;
    gUnknown_0203CD64->unk_003= 0;
    gUnknown_0203CD64->itemId = ITEM_NONE;
    gUnknown_0203CD64->language = gGameLanguage;
    sub_818DB20();
}

static void sub_818DBC4(void)
{
    gUnknown_0203CD64 = &gSaveBlock1Ptr->lilycoveLady.favour;
    gUnknown_0203CD64->id = LILYCOVE_LADY_FAVOUR;
    gUnknown_0203CD64->phase = 0;
}

u8 sub_818DBE8(void)
{
    gUnknown_0203CD64 = &gSaveBlock1Ptr->lilycoveLady.favour;
    if (gUnknown_0203CD64->phase == 2)
    {
        return 2;
    }
    else if (gUnknown_0203CD64->phase == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

static const u8 *sub_818DC1C(u8 idx)
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

static void sub_818DCAC(u8 *dest, u16 itemId)
{
    StringCopy(dest, ItemId_GetName(itemId));
}

void sub_818DCC8(void)
{
    gUnknown_0203CD64 = &gSaveBlock1Ptr->lilycoveLady.favour;
    sub_818DCAC(gStringVar2, gUnknown_0203CD64->itemId);
}

static void sub_818DCF4(const u8 *src, u8 *dest)
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

static bool8 sub_818DD84(u16 itemId)
{
    u8 len;
    u8 i;
    bool8 response;

    gUnknown_0203CD64 = &gSaveBlock1Ptr->lilycoveLady.favour;
    len = sub_818DB04(gUnknown_0860B2EC[gUnknown_0203CD64->unk_00c]);
    gUnknown_0203CD64->phase = 1;
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
    return sub_818DD84(gSpecialVar_ItemId);
}

bool8 sub_818DE5C(void)
{
    u8 checkval;

    gUnknown_0203CD64 = &gSaveBlock1Ptr->lilycoveLady.favour;
    checkval = gUnknown_0203CD64->unk_003;
    return checkval < 5 ? FALSE : TRUE;
}

static void sub_818DE88(u16 itemId)
{
    sub_818DCAC(gStringVar2, itemId);
}

u16 sub_818DEA0(void)
{
    u16 itemId;

    gUnknown_0203CD64 = &gSaveBlock1Ptr->lilycoveLady.favour;
    itemId = sUnknown_0860B304[gUnknown_0203CD64->unk_00c];
    sub_818DE88(itemId);
    gUnknown_0203CD64->phase = 2;
    return itemId;
}

void sub_818DEDC(void)
{
    SetLilycoveFavourLady();
    gUnknown_0203CD64->phase = 1;
}

void sub_818DEF4(void)
{
    EnableBothScriptContexts();
}

static void sub_818DF00(void)
{
    u8 v0;
    u8 i;

    v0 = Random() % 16;
    for (i = 0; i < 9; i ++)
    {
        gUnknown_0203CD68->unk_002[i] = gUnknown_0860B1A4[v0][i];
    }
    gUnknown_0203CD68->unk_014 = sUnknown_0860B1E4[v0];
    gUnknown_0203CD68->itemId = sUnknown_0860B204[v0];
    gUnknown_0203CD68->unk_02b = v0;
    gUnknown_0203CD68->playerName[0] = EOS;
}

static void SetLilycoveQuizLady(void)
{
    u8 i;

    gUnknown_0203CD68 = &gSaveBlock1Ptr->lilycoveLady.quiz;
    gUnknown_0203CD68->id = LILYCOVE_LADY_QUIZ;
    gUnknown_0203CD68->phase = 0;
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

static void sub_818E004(void)
{
    gUnknown_0203CD68 = &gSaveBlock1Ptr->lilycoveLady.quiz;
    gUnknown_0203CD68->id = LILYCOVE_LADY_QUIZ;
    gUnknown_0203CD68->phase = 0;
    gUnknown_0203CD68->unk_02a = 0;
    gUnknown_0203CD68->unk_016 = -1;
}

u8 sub_818E038(void)
{
    gUnknown_0203CD68 = &gSaveBlock1Ptr->lilycoveLady.quiz;
    if (gUnknown_0203CD68->phase == 2)
    {
        return 2;
    }
    else if (gUnknown_0203CD68->phase == 1)
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
        } while (sub_811F8D8(sUnknown_0860B1E4[i]) == 0);
        for (j = 0; j < 9; j ++)
        {
            quiz->unk_002[j] = gUnknown_0860B1A4[i][j];
        }
        quiz->unk_014 = sUnknown_0860B1E4[i];
        quiz->itemId = sUnknown_0860B204[i];
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

static u8 sub_818E13C(void)
{
    u8 retval;
    u8 len;
    u8 i;

    retval = 1;
    gUnknown_0203CD68 = &gSaveBlock1Ptr->lilycoveLady.quiz;
    if (gUnknown_0203CD68->playerName[0] == EOS)
    {
        StringCopy7(gStringVar1, gText_Lady2);
        retval = 0;
    }
    else
    {
        StringCopy7(gStringVar1, gUnknown_0203CD68->playerName);
        ConvertInternationalString(gStringVar1, gUnknown_0203CD68->language);
        len = sub_818E258(gUnknown_0203CD68->playerName);
        if (len == sub_818E258(gSaveBlock2Ptr->playerName))
        {
            u8 *name = gUnknown_0203CD68->playerName;
            for (i = 0; i < len; i ++)
            {
                name = gUnknown_0203CD68->playerName;
                if (name[i] != gSaveBlock2Ptr->playerName[i])
                {
                    retval = 2;
                    break;
                }
            }
        }

    }
    return retval;
}

static u8 sub_818E1F4(void)
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

static u8 sub_818E258(const u8 *str)
{
    u8 len;
    const u8 *ptr;

    for (len = 0, ptr = str; *ptr != EOS; len ++, ptr ++);
    return len;
}

void sub_818E274(void)
{
    StringCopy(gStringVar1, ItemId_GetName(gUnknown_0203CD68->itemId));
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
    ShowEasyChatScreen();
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
    gUnknown_0203CD68->phase = 1;
}

void sub_818E39C(void)
{
    gUnknown_0203CD68 = &gSaveBlock1Ptr->lilycoveLady.quiz;
    gUnknown_0203CD68->phase = 2;
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

void sub_818E3EC(void)
{
    gUnknown_0203CD68 = &gSaveBlock1Ptr->lilycoveLady.quiz;
    if (sub_818E298())
    {
        gUnknown_0203CD68->unk_02c = gUnknown_0203CD68->unk_02b;
    }
    else
    {
        gUnknown_0203CD68->unk_02c = 0x10;
    }
    sub_818DF00();
}

void sub_818E430(void)
{
    u8 i;

    gUnknown_0203CD68 = &gSaveBlock1Ptr->lilycoveLady.quiz;
    for (i = 0; i < 9; i ++)
    {
        gUnknown_0203CD68->unk_002[i] = -1;
    }
    gUnknown_0203CD68->unk_014 = -1;
}

void sub_818E47C(void)
{
    gSpecialVar_0x8004 = EASY_CHAT_TYPE_QUIZ_SET_QUESTION;
    ShowEasyChatScreen();
}

void sub_818E490(void)
{
    RemoveBagItem(gSpecialVar_ItemId, 1);
}

void sub_818E4A4(void)
{
    u8 i;

    gUnknown_0203CD68 = &gSaveBlock1Ptr->lilycoveLady.quiz;
    gUnknown_0203CD68->itemId = gSpecialVar_ItemId;
    for (i = 0; i < 4; i ++)
    {
        gUnknown_0203CD68->playerTrainerId[i] = gSaveBlock2Ptr->playerTrainerId[i];
    }
    StringCopy7(gUnknown_0203CD68->playerName, gSaveBlock2Ptr->playerName);
    gUnknown_0203CD68->language = gGameLanguage;
}

void sub_818E510(void)
{
    gUnknown_0203CD68 = &gSaveBlock1Ptr->lilycoveLady.quiz;
    gUnknown_0203CD68->unk_02a = 1;
}

void sub_818E538(void)
{
    gUnknown_0203CD68 = &gSaveBlock1Ptr->lilycoveLady.quiz;
    CopyEasyChatWord(gStringVar3, gUnknown_0203CD68->unk_014);
}

void sub_818E564(void)
{
    EnableBothScriptContexts();
}

void sub_818E570(const LilycoveLady *lilycoveLady)
{
    u8 i;

    gUnknown_0203CD68 = &gSaveBlock1Ptr->lilycoveLady.quiz;
    if (lilycoveLady->quiz.unk_02c < 16 && gUnknown_0203CD68->id == LILYCOVE_LADY_QUIZ)
    {
        for (i = 0; i < 4; i ++)
        {
            if (lilycoveLady->quiz.unk_02c != gUnknown_0203CD68->unk_02b)
            {
                break;
            }
            gUnknown_0203CD68->unk_02b = Random() % 16;
        }
        if (lilycoveLady->quiz.unk_02c == gUnknown_0203CD68->unk_02b)
        {
            gUnknown_0203CD68->unk_02b = (gUnknown_0203CD68->unk_02b + 1) % 16;
        }
        gUnknown_0203CD68->unk_02c = lilycoveLady->quiz.unk_02c;
    }
}

static void sub_818E604(void)
{
    gUnknown_0203CD6C->playerName[0] = EOS;
    gUnknown_0203CD6C->fave_pkblk = 0;
    gUnknown_0203CD6C->other_pkblk = 0;
    gUnknown_0203CD6C->max_sheen = 0;
    gUnknown_0203CD6C->category = Random() % 5;
}

static void SetLilycoveContestLady(void)
{
    gUnknown_0203CD6C = &gSaveBlock1Ptr->lilycoveLady.contest;
    gUnknown_0203CD6C->id = LILYCOVE_LADY_CONTEST;
    gUnknown_0203CD6C->phase = 0;
    sub_818E604();
    gUnknown_0203CD6C->language = gGameLanguage;
}

static void sub_818E674(void)
{
    gUnknown_0203CD6C = &gSaveBlock1Ptr->lilycoveLady.contest;
    gUnknown_0203CD6C->id = LILYCOVE_LADY_CONTEST;
    gUnknown_0203CD6C->phase = 0;
    if (gUnknown_0203CD6C->fave_pkblk == 5 || gUnknown_0203CD6C->other_pkblk == 5)
    {
        sub_818E604();
    }
}

static void sub_818E6B0(u8 sheen)
{
    gUnknown_0203CD6C = &gSaveBlock1Ptr->lilycoveLady.contest;
    if (gUnknown_0203CD6C->max_sheen <= sheen)
    {
        gUnknown_0203CD6C->max_sheen = sheen;
        memset(gUnknown_0203CD6C->playerName, EOS, sizeof(gUnknown_0203CD6C->playerName));
        memcpy(gUnknown_0203CD6C->playerName, gSaveBlock2Ptr->playerName, sizeof(gUnknown_0203CD6C->playerName));
        gUnknown_0203CD6C->language = gGameLanguage;
    }
}

bool8 GivePokeblockToContestLady(struct Pokeblock *pokeblock)
{
    u8 sheen;
    bool8 response;

    sheen = 0;
    response = FALSE;
    gUnknown_0203CD6C = &gSaveBlock1Ptr->lilycoveLady.contest;
    switch (gUnknown_0203CD6C->category)
    {
        case 0:
            if (pokeblock->spicy != 0)
            {
                sheen = pokeblock->spicy;
                response = TRUE;
            }
            break;
        case 1:
            if (pokeblock->dry != 0)
            {
                sheen = pokeblock->dry;
                response = TRUE;
            }
            break;
        case 2:
            if (pokeblock->sweet != 0)
            {
                sheen = pokeblock->sweet;
                response = TRUE;
            }
            break;
        case 3:
            if (pokeblock->bitter != 0)
            {
                sheen = pokeblock->bitter;
                response = TRUE;
            }
            break;
        case 4:
            if (pokeblock->sour != 0)
            {
                sheen = pokeblock->sour;
                response = TRUE;
            }
            break;
    }
    if (response == TRUE)
    {
        sub_818E6B0(sheen);
        gUnknown_0203CD6C->fave_pkblk ++;
    }
    else
    {
        gUnknown_0203CD6C->other_pkblk ++;
    }
    return response;
}

static void sub_818E794(u8 *dest1, u8 *dest2)
{
    gUnknown_0203CD6C = &gSaveBlock1Ptr->lilycoveLady.contest;
    StringCopy(dest1, gUnknown_0860B324[gUnknown_0203CD6C->category]);
    StringCopy10(dest2, gUnknown_0860B310[gUnknown_0203CD6C->category]);
}

void sub_818E7E0(u8 *dest1, u8 *dest2)
{
    gUnknown_0203CD6C = &gSaveBlock1Ptr->lilycoveLady.contest;
    *dest1 = gUnknown_0203CD6C->category;
    StringCopy(dest2, gUnknown_0860B310[gUnknown_0203CD6C->category]);
}

void sub_818E81C(u8 *dest)
{
    gUnknown_0203CD6C = &gSaveBlock1Ptr->lilycoveLady.contest;
    StringCopy(dest, gUnknown_0203CD6C->playerName);
}

void sub_818E848(u8 *dest)
{
    gUnknown_0203CD6C = &gSaveBlock1Ptr->lilycoveLady.contest;
    *dest = gUnknown_0203CD6C->language;
}

void sub_818E868(u8 *dest, u8 category)
{
    StringCopy(dest, gUnknown_0860B338[category]);
}

u8 sub_818E880(void)
{
    gUnknown_0203CD6C = &gSaveBlock1Ptr->lilycoveLady.contest;
    if (gUnknown_0203CD6C->fave_pkblk >= 5)
    {
        return 1;
    }
    else if (gUnknown_0203CD6C->fave_pkblk == 0)
    {
        return 2;
    }
    else
    {
        return 0;
    }
}

bool8 sub_818E8B4(void)
{
    gUnknown_0203CD6C = &gSaveBlock1Ptr->lilycoveLady.contest;
    if (gUnknown_0203CD6C->phase == 1)
    {
        return TRUE;
    }
    return FALSE;
}

bool8 sub_818E8E0(void)
{
    bool8 response;

    response = FALSE;
    gUnknown_0203CD6C = &gSaveBlock1Ptr->lilycoveLady.contest;
    if (gUnknown_0203CD6C->fave_pkblk >= 5 || gUnknown_0203CD6C->other_pkblk >= 5)
    {
        response = TRUE;
    }
    return response;
}

void sub_818E914(void)
{
    sub_818E794(gStringVar2, gStringVar1);
}

void sub_818E92C(void)
{
    OpenPokeblockCase(3, CB2_ReturnToField);
}

void sub_818E940(void)
{
    gUnknown_0203CD6C = &gSaveBlock1Ptr->lilycoveLady.contest;
    gUnknown_0203CD6C->phase = 1;
}

void sub_818E960(void)
{
    gUnknown_0203CD6C = &gSaveBlock1Ptr->lilycoveLady.contest;
    gSpecialVar_0x8005 = sUnknown_0860B34C[gUnknown_0203CD6C->category];
}

u8 sub_818E990(void)
{
    gUnknown_0203CD6C = &gSaveBlock1Ptr->lilycoveLady.contest;
    return gUnknown_0203CD6C->category;
}
