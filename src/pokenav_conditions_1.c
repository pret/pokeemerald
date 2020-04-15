#include "global.h"
#include "data.h"
#include "decompress.h"
#include "main.h"
#include "menu_specialized.h"
#include "mon_markings.h"
#include "pokenav.h"
#include "pokemon.h"
#include "pokemon_storage_system.h"
#include "sound.h"
#include "string_util.h"
#include "strings.h"
#include "text.h"
#include "constants/songs.h"
#include "constants/species.h"

struct PokenavSub11
{
    u32 monPal[3][0x20];
    u8 fill[0x180];
    u32 monPicGfx[3][0x800];
    u8 unk6300;
    s16 unk6302;
    u32 (*unk6304)(struct PokenavSub11 *);
    u8 fill2[0x6320 - 0x6308];
    u8 unk6320[3][24];
    u8 unk6368[3][64];
    struct UnknownStruct_81D1ED4 unk6428;
    u8 unk6780[3];
    u8 unk6783[3];
    s8 unk6786;
    s8 unk6787;
    s8 unk6788;
    s8 unk6789;
    u8 unk678A;
};

void sub_81CD970(void);
void sub_81CD9F8(void);
u32 sub_81CD08C(struct PokenavSub11 *structPtr);
u32 sub_81CD19C(struct PokenavSub11 *structPtr);
u32 sub_81CD110(struct PokenavSub11 *structPtr);
u8 sub_81CD1E4(struct PokenavSub11 *structPtr);
u8 sub_81CD258(u8 arg0);
void sub_81CD824(s16 arg0, u8 arg1);
void sub_81CDA1C(s16 arg0, u8 arg1);
void sub_81CDB98(s16 arg0, u8 arg1);

// code
bool32 PokenavCallback_Init_7(void)
{
    struct PokenavSub11 *structPtr = AllocSubstruct(11, sizeof(struct PokenavSub11));

    if (structPtr == NULL)
        return FALSE;

    sub_81D1ED4(&structPtr->unk6428);
    sub_81CD970();
    gKeyRepeatStartDelay = 20;
    structPtr->unk6304 = sub_81CD08C;
    return TRUE;
}

bool32 PokenavCallback_Init_9(void)
{
    struct PokenavSub11 *structPtr = AllocSubstruct(11, sizeof(struct PokenavSub11));

    if (structPtr == NULL)
        return FALSE;

    sub_81D1ED4(&structPtr->unk6428);
    sub_81CD9F8();
    gKeyRepeatStartDelay = 20;
    structPtr->unk6304 = sub_81CD08C;
    return TRUE;
}

u32 sub_81CD070(void)
{
    struct PokenavSub11 *structPtr = GetSubstructPtr(11);

    return structPtr->unk6304(structPtr);
}

u32 sub_81CD08C(struct PokenavSub11 *structPtr)
{
    struct PokenavSub18 *unkPtr = GetSubstructPtr(18);
    u32 ret = sub_81CD1E4(structPtr);

    if (ret == 0)
    {
        if (gMain.newKeys & B_BUTTON)
        {
            PlaySE(SE_SELECT);
            structPtr->unk6304 = sub_81CD19C;
            ret = 2;
        }
        else if (gMain.newKeys & A_BUTTON)
        {
            if (structPtr->unk6300 == 0)
            {
                if (unkPtr->unk2 == unkPtr->unk0 - 1)
                {
                    PlaySE(SE_SELECT);
                    structPtr->unk6304 = sub_81CD19C;
                    ret = 2;
                }
            }
            else
            {
                PlaySE(SE_SELECT);
                ret = 5;
                structPtr->unk6304 = sub_81CD110;
            }
        }
    }

    return ret;
}

u32 sub_81CD110(struct PokenavSub11 *structPtr)
{
    struct PokenavSub18 *unkPtr;
    u8 markings;
    u32 ret = 0, boxId, monId;

    if (!sub_811FBA4())
    {
        structPtr->unk6783[structPtr->unk6786] = sub_81CEF14();
        unkPtr = GetSubstructPtr(18);
        boxId = unkPtr->unk4[unkPtr->unk2].boxId;
        monId = unkPtr->unk4[unkPtr->unk2].monId;
        markings = structPtr->unk6783[structPtr->unk6786];

        if (boxId == TOTAL_BOXES_COUNT)
            SetMonData(&gPlayerParty[monId], MON_DATA_MARKINGS, &markings);
        else
            SetBoxMonDataAt(boxId, monId, MON_DATA_MARKINGS, &markings);

        structPtr->unk6304 = sub_81CD08C;
        ret = 6;
    }

    return ret;
}

u32 sub_81CD19C(struct PokenavSub11 *structPtr)
{
    if (structPtr->unk6300 == 0)
        return POKENAV_CONDITION_MENU;
    else
        return POKENAV_MENU_A;
}

void sub_81CD1C0(void)
{
    struct PokenavSub11 *structPtr = GetSubstructPtr(11);
    if (structPtr->unk6300 == 0)
        FreePokenavSubstruct(18);

    FreePokenavSubstruct(11);
}

u8 sub_81CD1E4(struct PokenavSub11 *structPtr)
{
    struct PokenavSub18 *unkPtr = GetSubstructPtr(18);
    u8 ret = 0;

    if (gMain.heldKeys & DPAD_UP)
    {
        if (structPtr->unk6300 == 0 || unkPtr->unk2 != 0)
        {
            PlaySE(SE_SELECT);
            ret = sub_81CD258(1);
        }
    }
    else if (gMain.heldKeys & DPAD_DOWN)
    {
        if (structPtr->unk6300 == 0 || unkPtr->unk2 < unkPtr->unk0 - 1)
        {
            PlaySE(SE_SELECT);
            ret = sub_81CD258(0);
        }
    }

    return ret;
}

u8 sub_81CD258(u8 arg0)
{
    u16 r7;
    bool8 r6, r0;
    struct PokenavSub11 *structPtr = GetSubstructPtr(11);
    struct PokenavSub18 *unkPtr = GetSubstructPtr(18);

    r7 = (arg0) ? structPtr->unk6788 : structPtr->unk6787;
    sub_81D1F84(&structPtr->unk6428, structPtr->unk6428.unk14[structPtr->unk6786], structPtr->unk6428.unk14[r7]);
    r6 = (unkPtr->unk2 != ((sub_81CDD5C() != 0) ? unkPtr->unk0 : unkPtr->unk0 - 1));
    if (arg0)
    {
        structPtr->unk6788 = structPtr->unk6787;
        structPtr->unk6787 = structPtr->unk6786;
        structPtr->unk6786 = r7;
        structPtr->unk6789 = structPtr->unk6788;

        unkPtr->unk2 = (unkPtr->unk2 == 0) ? unkPtr->unk0 - 1 : unkPtr->unk2 - 1;
        structPtr->unk6302 = (unkPtr->unk2 != 0) ? unkPtr->unk2 - 1 : unkPtr->unk0 - 1;
    }
    else
    {
        structPtr->unk6787 = structPtr->unk6788;
        structPtr->unk6788 = structPtr->unk6786;
        structPtr->unk6786 = r7;
        structPtr->unk6789 = structPtr->unk6787;

        unkPtr->unk2 = (unkPtr->unk2 < unkPtr->unk0 - 1) ? unkPtr->unk2 + 1 : 0;
        structPtr->unk6302 = (unkPtr->unk2 < unkPtr->unk0 - 1) ? unkPtr->unk2 + 1 : 0;
    }

    r0 = (unkPtr->unk2 != ((sub_81CDD5C() != 0) ? unkPtr->unk0 : unkPtr->unk0 - 1));

    if (!r6)
        return 3;
    else if (!r0)
        return 4;
    else
        return 1;
}

bool32 sub_81CD3C4(void)
{
    s32 var;
    struct PokenavSub11 *structPtr = GetSubstructPtr(11);
    struct PokenavSub18 *unkPtr = GetSubstructPtr(18);

    switch (structPtr->unk678A)
    {
    case 0:
        sub_81CD824(unkPtr->unk2, 0);
        break;
    case 1:
        sub_81CDA1C(unkPtr->unk2, 0);
        break;
    case 2:
        sub_81CDB98(unkPtr->unk2, 0);
        break;
    case 3:
        if (unkPtr->unk0 == 1)
        {
            structPtr->unk6786 = 0;
            structPtr->unk6787 = 0;
            structPtr->unk6788 = 0;
            structPtr->unk678A = 0;
            return TRUE;
        }
        else
        {
            structPtr->unk6786 = 0;
            structPtr->unk6787 = 1;
            structPtr->unk6788 = 2;
        }
        break;
    // These were probably ternaries just like cases 7-9, but couldn't match it any other way.
    case 4:
        var = unkPtr->unk2 + 1;
        if (var >= unkPtr->unk0)
            var = 0;
        sub_81CD824(var, 1);
        break;
    case 5:
        var = unkPtr->unk2 + 1;
        if (var >= unkPtr->unk0)
            var = 0;
        sub_81CDA1C(var, 1);
        break;
    case 6:
        var = unkPtr->unk2 + 1;
        if (var >= unkPtr->unk0)
            var = 0;
        sub_81CDB98(var, 1);
        break;
    case 7:
        sub_81CD824((unkPtr->unk2 - 1 >= 0) ? unkPtr->unk2 - 1 : unkPtr->unk0 - 1, 2);
        break;
    case 8:
        sub_81CDA1C((unkPtr->unk2 - 1 >= 0) ? unkPtr->unk2 - 1 : unkPtr->unk0 - 1, 2);
        break;
    case 9:
        sub_81CDB98((unkPtr->unk2 - 1 >= 0) ? unkPtr->unk2 - 1 : unkPtr->unk0 - 1, 2);
        structPtr->unk678A = 0;
        return TRUE;
    }

    structPtr->unk678A++;
    return FALSE;
}

bool32 sub_81CD548(u8 arg0)
{
    struct PokenavSub11 *structPtr = GetSubstructPtr(11);

    switch (arg0)
    {
    case 0:
        sub_81CD824(structPtr->unk6302, structPtr->unk6789);
        break;
    case 1:
        sub_81CDA1C(structPtr->unk6302, structPtr->unk6789);
        break;
    case 2:
        sub_81CDB98(structPtr->unk6302, structPtr->unk6789);
        return TRUE;
    }

    return FALSE;
}

u8 *sub_81CD5CC(u8 *dst, const u8 *src, s16 n)
{
    while (*src != EOS)
        *dst++ = *src++, n--;

    while (n-- > 0)
        *dst++ = CHAR_SPACE;

    *dst = EOS;
    return dst;
}

u8 *sub_81CD624(u8 *str, u16 id, bool8 arg3)
{
    u16 boxId, monId, gender, species, level, lvlDigits;
    struct BoxPokemon *boxMon;
    u8 *txtPtr, *str_;
    struct PokenavSub18 *unkPtr = GetSubstructPtr(18);

    boxId = unkPtr->unk4[id].boxId;
    monId = unkPtr->unk4[id].monId;
    *(str++) = EXT_CTRL_CODE_BEGIN;
    *(str++) = 4;
    *(str++) = 8;
    *(str++) = 0;
    *(str++) = 9;

    if (GetBoxOrPartyMonData(boxId, monId, MON_DATA_IS_EGG, NULL))
        return StringCopyPadded(str, gText_EggNickname, CHAR_SPACE, 12);

    GetBoxOrPartyMonData(boxId, monId, MON_DATA_NICKNAME, str);
    StringGetEnd10(str);
    species = GetBoxOrPartyMonData(boxId, monId, MON_DATA_SPECIES, NULL);
    if (boxId == TOTAL_BOXES_COUNT)
    {
        level = GetMonData(&gPlayerParty[monId], MON_DATA_LEVEL);
        gender = GetMonGender(&gPlayerParty[monId]);
    }
    else
    {
        boxMon = GetBoxedMonPtr(boxId, monId);
        gender = GetBoxMonGender(boxMon);
        level = GetLevelFromBoxMonExp(boxMon);
    }

    if ((species == SPECIES_NIDORAN_F || species == SPECIES_NIDORAN_M) && !StringCompare(str, gSpeciesNames[species]))
        gender = MON_GENDERLESS;

    str_ = str; // For some reason, a variable is needed to match.
    while (*str_ != EOS)
        (str_++);

    *(str_++) = EXT_CTRL_CODE_BEGIN;
    *(str_++) = 0x12;
    *(str_++) = 0x3C;
    switch (gender)
    {
    default:
        *(str_++) = 0x77;
        break;
    case MON_MALE:
        *(str_++) = EXT_CTRL_CODE_BEGIN;
        *(str_++) = EXT_CTRL_CODE_COLOR;
        *(str_++) = 4;
        *(str_++) = EXT_CTRL_CODE_BEGIN;
        *(str_++) = 3;
        *(str_++) = 5;
        *(str_++) = CHAR_MALE;
        break;
    case MON_FEMALE:
        *(str_++) = EXT_CTRL_CODE_BEGIN;
        *(str_++) = EXT_CTRL_CODE_COLOR;
        *(str_++) = 6;
        *(str_++) = EXT_CTRL_CODE_BEGIN;
        *(str_++) = 3;
        *(str_++) = 7;
        *(str_++) = CHAR_FEMALE;
        break;
    }

    *(str_++) = EXT_CTRL_CODE_BEGIN;
    *(str_++) = 4;
    *(str_++) = 8;
    *(str_++) = 0;
    *(str_++) = 9;
    *(str_++) = CHAR_SLASH;
    *(str_++) = CHAR_SPECIAL_F9;
    *(str_++) = CHAR_LV_2;
    txtPtr = str_;
    str_ = ConvertIntToDecimalStringN(str_, level, STR_CONV_MODE_LEFT_ALIGN, 3);
    lvlDigits = str_ - txtPtr;
    *(str_++) = CHAR_SPACE;
    if (!arg3)
    {
        lvlDigits = 3 - lvlDigits;
        while (lvlDigits-- != 0)
            *(str_++) = CHAR_SPACE;
    }

    *str_ = EOS;
    return str_;
}

void sub_81CD824(s16 arg0, u8 arg1)
{
    u16 boxId, i;
    struct PokenavSub11 *structPtr = GetSubstructPtr(11);
    struct PokenavSub18 *unkPtr = GetSubstructPtr(18);

    if (arg0 != (sub_81CDD5C() != 0 ? unkPtr->unk0 : unkPtr->unk0 - 1))
    {
        sub_81CD624(structPtr->unk6368[arg1], arg0, FALSE);
        boxId = unkPtr->unk4[arg0].boxId;
        structPtr->unk6320[arg1][0] = EXT_CTRL_CODE_BEGIN;
        structPtr->unk6320[arg1][1] = 4;
        structPtr->unk6320[arg1][2] = 8;
        structPtr->unk6320[arg1][3] = 0;
        structPtr->unk6320[arg1][4] = 9;
        if (boxId == TOTAL_BOXES_COUNT)
            sub_81CD5CC(&structPtr->unk6320[arg1][5], gText_InParty, 8);
        else
            sub_81CD5CC(&structPtr->unk6320[arg1][5], GetBoxNamePtr(boxId), 8);
    }
    else
    {
        for (i = 0; i < 12; i++)
            structPtr->unk6368[arg1][i] = CHAR_SPACE;
        structPtr->unk6368[arg1][i] = EOS;

        for (i = 0; i < 8; i++)
            structPtr->unk6320[arg1][i] = CHAR_SPACE;
        structPtr->unk6320[arg1][i] = EOS;
    }
}

void sub_81CD970(void)
{
    u16 i, count;
    struct PokenavSub11 *structPtr = GetSubstructPtr(11);
    struct PokenavSub18 *unkPtr = AllocSubstruct(18, sizeof(struct PokenavSub18));

    structPtr->unk6300 = 0;
    for (i = 0, count = 0; i < CalculatePlayerPartyCount(); i++)
    {
        if (!GetMonData(&gPlayerParty[i], MON_DATA_IS_EGG))
        {
            unkPtr->unk4[count].boxId = TOTAL_BOXES_COUNT;
            unkPtr->unk4[count].monId = i;
            unkPtr->unk4[count].data = 0;
            count++;
        }
    }

    unkPtr->unk4[count].boxId = 0;
    unkPtr->unk4[count].monId = 0;
    unkPtr->unk4[count].data = 0;
    unkPtr->unk2 = 0;
    unkPtr->unk0 = count + 1;
    structPtr->unk678A = 0;
}

void sub_81CD9F8(void)
{
    struct PokenavSub11 *structPtr = GetSubstructPtr(11);
    structPtr->unk6300 = 1;
    structPtr->unk678A = 0;
}

void sub_81CDA1C(s16 arg0, u8 arg1)
{
    u16 boxId, monId, i;
    struct PokenavSub11 *structPtr = GetSubstructPtr(11);
    struct PokenavSub18 *unkPtr = GetSubstructPtr(18);

    if (arg0 != (sub_81CDD5C() != 0 ? unkPtr->unk0 : unkPtr->unk0 - 1))
    {
        boxId = unkPtr->unk4[arg0].boxId;
        monId = unkPtr->unk4[arg0].monId;
        structPtr->unk6428.unk0[arg1][0] = GetBoxOrPartyMonData(boxId, monId, MON_DATA_COOL, NULL);
        structPtr->unk6428.unk0[arg1][1] = GetBoxOrPartyMonData(boxId, monId, MON_DATA_TOUGH, NULL);
        structPtr->unk6428.unk0[arg1][2] = GetBoxOrPartyMonData(boxId, monId, MON_DATA_SMART, NULL);
        structPtr->unk6428.unk0[arg1][3] = GetBoxOrPartyMonData(boxId, monId, MON_DATA_CUTE, NULL);
        structPtr->unk6428.unk0[arg1][4] = GetBoxOrPartyMonData(boxId, monId, MON_DATA_BEAUTY, NULL);
        structPtr->unk6780[arg1] = (GetBoxOrPartyMonData(boxId, monId, MON_DATA_SHEEN, NULL) != 255)
                                 ? GetBoxOrPartyMonData(boxId, monId, MON_DATA_SHEEN, NULL) / 29u
                                 : 9;
        structPtr->unk6783[arg1] = GetBoxOrPartyMonData(boxId, monId, MON_DATA_MARKINGS, NULL);
        sub_81D2754(structPtr->unk6428.unk0[arg1], structPtr->unk6428.unk14[arg1]);
    }
    else
    {
        for (i = 0; i < 5; i++)
        {
            structPtr->unk6428.unk0[arg1][i] = 0;
            structPtr->unk6428.unk14[arg1][i].unk0 = 155;
            structPtr->unk6428.unk14[arg1][i].unk2 = 91;
        }
    }
}

void sub_81CDB98(s16 arg0, u8 arg1)
{
    u16 boxId, monId, species;
    u32 personality, tid;
    struct PokenavSub11 *structPtr = GetSubstructPtr(11);
    struct PokenavSub18 *unkPtr = GetSubstructPtr(18);

    if (arg0 == (sub_81CDD5C() != 0 ? unkPtr->unk0 : unkPtr->unk0 - 1))
        return;

    boxId = unkPtr->unk4[arg0].boxId;
    monId = unkPtr->unk4[arg0].monId;
    species = GetBoxOrPartyMonData(boxId, monId, MON_DATA_SPECIES2, NULL);
    tid = GetBoxOrPartyMonData(boxId, monId, MON_DATA_OT_ID, NULL);
    personality = GetBoxOrPartyMonData(boxId, monId, MON_DATA_PERSONALITY, NULL);
    LoadSpecialPokePic(&gMonFrontPicTable[species], structPtr->monPicGfx[arg1], species, personality, TRUE);
    LZ77UnCompWram(GetMonSpritePalFromSpeciesAndPersonality(species, tid, personality), structPtr->monPal[arg1]);
}

u16 sub_81CDC50(void)
{
    struct PokenavSub18 *unkPtr = GetSubstructPtr(18);
    return unkPtr->unk0;
}

u16 sub_81CDC60(void)
{
    struct PokenavSub18 *unkPtr = GetSubstructPtr(18);
    return unkPtr->unk2;
}

struct UnknownStruct_81D1ED4 *sub_81CDC70(void)
{
    struct PokenavSub11 *structPtr = GetSubstructPtr(11);
    return &structPtr->unk6428;
}

u8 sub_81CDC84(void)
{
    struct PokenavSub11 *structPtr = GetSubstructPtr(11);
    return structPtr->unk6786;
}

u8 sub_81CDC9C(void)
{
    struct PokenavSub11 *structPtr = GetSubstructPtr(11);
    return structPtr->unk6302;
}

void *sub_81CDCB4(u8 id)
{
    struct PokenavSub11 *structPtr = GetSubstructPtr(11);
    return structPtr->monPicGfx[id];
}

void *sub_81CDCD4(u8 id)
{
    struct PokenavSub11 *structPtr = GetSubstructPtr(11);
    return structPtr->monPal[id];
}

u8 sub_81CDCEC(void)
{
    struct PokenavSub11 *structPtr = GetSubstructPtr(11);
    return structPtr->unk6789;
}

u8 *sub_81CDD04(u8 id)
{
    struct PokenavSub11 *structPtr = GetSubstructPtr(11);
    return structPtr->unk6368[id];
}

u8 *sub_81CDD24(u8 id)
{
    struct PokenavSub11 *structPtr = GetSubstructPtr(11);
    return structPtr->unk6320[id];
}

u16 sub_81CDD48(void)
{
    struct PokenavSub18 *unkPtr = GetSubstructPtr(18);
    return unkPtr->unk4[unkPtr->unk2].data;
}

bool32 sub_81CDD5C(void)
{
    struct PokenavSub11 *structPtr = GetSubstructPtr(11);
    if (structPtr->unk6300 == 1)
        return TRUE;
    else
        return FALSE;
}

u8 sub_81CDD7C(void)
{
    struct PokenavSub11 *structPtr = GetSubstructPtr(11);
    if (structPtr->unk6300 == 1)
        return structPtr->unk6783[structPtr->unk6786];
    else
        return 0;
}

u8 sub_81CDDB0(void)
{
    struct PokenavSub11 *structPtr = GetSubstructPtr(11);
    return structPtr->unk6780[structPtr->unk6786];
}
