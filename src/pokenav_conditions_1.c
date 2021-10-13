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

struct PokenavSub11
{
    u32 monPal[3][0x20];
    u8 fill[0x180];
    u32 monPicGfx[3][MON_PIC_SIZE];
    u8 searchMode;
    s16 monIndex;
    u32 (*callback)(struct PokenavSub11 *);
    u8 fill2[0x6320 - 0x6308];
    u8 searchLocBuffer[3][24];
    u8 nameBuffer[3][64];
    struct ConditionGraph conditionData;
    u8 sheen[3];
    u8 monMarks[3];
    s8 mark;
    s8 unk6787;
    s8 unk6788;
    s8 unk6789;
    u8 state;
};

void InitPartyConditionListParameters(void);
void sub_81CD9F8(void);
u32 HandlePartyConditionInput(struct PokenavSub11 *structPtr);
u32 GetConditionReturnCallback(struct PokenavSub11 *structPtr);
u32 ConditionMenu_OpenMarkingsMenu(struct PokenavSub11 *structPtr);
u8 ConditionGraphHandleDpadInput(struct PokenavSub11 *structPtr);
u8 SwitchConditionSummaryIndex(u8 moveUp);
void CopyMonNameGenderLocation(s16 id, u8 arg1);
void GetMonConditionGraphData(s16 id, u8 arg1);
void ConditionGraphDrawMonPic(s16 id, u8 arg1);

// code
bool32 PokenavCallback_Init_PartyCondition(void)
{
    struct PokenavSub11 *structPtr = AllocSubstruct(POKENAV_SUBSTRUCT_CONDITION_GRAPH, sizeof(struct PokenavSub11));

    if (structPtr == NULL)
        return FALSE;

    InitConditionGraphData(&structPtr->conditionData);
    InitPartyConditionListParameters();
    gKeyRepeatStartDelay = 20;
    structPtr->callback = HandlePartyConditionInput;
    return TRUE;
}

bool32 PokenavCallback_Init_ConditionGraphFromSearch(void)
{
    struct PokenavSub11 *structPtr = AllocSubstruct(POKENAV_SUBSTRUCT_CONDITION_GRAPH, sizeof(struct PokenavSub11));

    if (structPtr == NULL)
        return FALSE;

    InitConditionGraphData(&structPtr->conditionData);
    sub_81CD9F8();
    gKeyRepeatStartDelay = 20;
    structPtr->callback = HandlePartyConditionInput;
    return TRUE;
}

u32 GetPartyConditionCallback(void)
{
    struct PokenavSub11 *structPtr = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_GRAPH);

    return structPtr->callback(structPtr);
}

u32 HandlePartyConditionInput(struct PokenavSub11 *structPtr)
{
    struct PokenavSub18 *monListPtr = GetSubstructPtr(POKENAV_SUBSTRUCT_MON_LIST);
    u32 ret = ConditionGraphHandleDpadInput(structPtr);

    if (ret == PARTY_CONDITION_FUNC_NONE)
    {
        if (JOY_NEW(B_BUTTON))
        {
            PlaySE(SE_SELECT);
            structPtr->callback = GetConditionReturnCallback;
            ret = PARTY_CONDITION_FUNC_RETURN;
        }
        else if (JOY_NEW(A_BUTTON))
        {
            if (structPtr->searchMode == 0)
            {
                if (monListPtr->currIndex == monListPtr->listCount - 1)
                {
                    PlaySE(SE_SELECT);
                    structPtr->callback = GetConditionReturnCallback;
                    ret = PARTY_CONDITION_FUNC_RETURN;
                }
            }
            else
            {
                PlaySE(SE_SELECT);
                ret = PARTY_CONDITION_FUNC_ADD_MARKINGS;
                structPtr->callback = ConditionMenu_OpenMarkingsMenu;
            }
        }
    }

    return ret;
}

u32 ConditionMenu_OpenMarkingsMenu(struct PokenavSub11 *structPtr)
{
    struct PokenavSub18 *monListPtr;
    u8 markings;
    u32 ret = PARTY_CONDITION_FUNC_NONE, boxId, monId;

    if (!HandleMonMarkingsMenuInput())
    {
        structPtr->monMarks[structPtr->mark] = GetMonMarkingsData();
        monListPtr = GetSubstructPtr(POKENAV_SUBSTRUCT_MON_LIST);
        boxId = monListPtr->monData[monListPtr->currIndex].boxId;
        monId = monListPtr->monData[monListPtr->currIndex].monId;
        markings = structPtr->monMarks[structPtr->mark];

        if (boxId == TOTAL_BOXES_COUNT)
            SetMonData(&gPlayerParty[monId], MON_DATA_MARKINGS, &markings);
        else
            SetBoxMonDataAt(boxId, monId, MON_DATA_MARKINGS, &markings);

        structPtr->callback = HandlePartyConditionInput;
        ret = PARTY_CONDITION_FUNC_CLOSE_MARKINGS;
    }

    return ret;
}

u32 GetConditionReturnCallback(struct PokenavSub11 *structPtr)
{
    if (structPtr->searchMode == 0)
        return POKENAV_CONDITION_MENU;
    else
        return POKENAV_RETURN_CONDITION_SEARCH;
}

void FreePartyConditionSubstruct1(void)
{
    struct PokenavSub11 *structPtr = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_GRAPH);
    if (structPtr->searchMode == 0)
        FreePokenavSubstruct(POKENAV_SUBSTRUCT_MON_LIST);

    FreePokenavSubstruct(POKENAV_SUBSTRUCT_CONDITION_GRAPH);
}

u8 ConditionGraphHandleDpadInput(struct PokenavSub11 *structPtr)
{
    struct PokenavSub18 *monListPtr = GetSubstructPtr(POKENAV_SUBSTRUCT_MON_LIST);
    u8 ret = 0;

    if (JOY_HELD(DPAD_UP))
    {
        if (structPtr->searchMode == 0 || monListPtr->currIndex != 0)
        {
            PlaySE(SE_SELECT);
            ret = SwitchConditionSummaryIndex(1);
        }
    }
    else if (JOY_HELD(DPAD_DOWN))
    {
        if (structPtr->searchMode == 0 || monListPtr->currIndex < monListPtr->listCount - 1)
        {
            PlaySE(SE_SELECT);
            ret = SwitchConditionSummaryIndex(0);
        }
    }

    return ret;
}

u8 SwitchConditionSummaryIndex(u8 moveUp)
{
    u16 r7;
    bool8 wasNotLastMon, isNotLastMon;
    struct PokenavSub11 *structPtr = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_GRAPH);
    struct PokenavSub18 *monListPtr = GetSubstructPtr(POKENAV_SUBSTRUCT_MON_LIST);

    r7 = (moveUp) ? structPtr->unk6788 : structPtr->unk6787;
    sub_81D1F84(&structPtr->conditionData, structPtr->conditionData.unk14[structPtr->mark], structPtr->conditionData.unk14[r7]);
    wasNotLastMon = (monListPtr->currIndex != ((IsConditionMenuSearchMode() != 0) ? monListPtr->listCount : monListPtr->listCount - 1));
    if (moveUp)
    {
        structPtr->unk6788 = structPtr->unk6787;
        structPtr->unk6787 = structPtr->mark;
        structPtr->mark = r7;
        structPtr->unk6789 = structPtr->unk6788;

        monListPtr->currIndex = (monListPtr->currIndex == 0) ? monListPtr->listCount - 1 : monListPtr->currIndex - 1;
        structPtr->monIndex = (monListPtr->currIndex != 0) ? monListPtr->currIndex - 1 : monListPtr->listCount - 1;
    }
    else
    {
        structPtr->unk6787 = structPtr->unk6788;
        structPtr->unk6788 = structPtr->mark;
        structPtr->mark = r7;
        structPtr->unk6789 = structPtr->unk6787;

        monListPtr->currIndex = (monListPtr->currIndex < monListPtr->listCount - 1) ? monListPtr->currIndex + 1 : 0;
        structPtr->monIndex = (monListPtr->currIndex < monListPtr->listCount - 1) ? monListPtr->currIndex + 1 : 0;
    }

    isNotLastMon = (monListPtr->currIndex != ((IsConditionMenuSearchMode() != 0) ? monListPtr->listCount : monListPtr->listCount - 1));

    if (!wasNotLastMon)
        return PARTY_CONDITION_FUNC_NO_TRANSITION;
    else if (!isNotLastMon)
        return PARTY_CONDITION_FUNC_SLIDE_MON_OUT;
    else
        return PARTY_CONDITION_FUNC_SLIDE_MON_IN;
}

bool32 LoadPartyConditionMenuGfx(void)
{
    s32 var;
    struct PokenavSub11 *structPtr = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_GRAPH);
    struct PokenavSub18 *monListPtr = GetSubstructPtr(POKENAV_SUBSTRUCT_MON_LIST);

    switch (structPtr->state)
    {
    case 0:
        CopyMonNameGenderLocation(monListPtr->currIndex, 0);
        break;
    case 1:
        GetMonConditionGraphData(monListPtr->currIndex, 0);
        break;
    case 2:
        ConditionGraphDrawMonPic(monListPtr->currIndex, 0);
        break;
    case 3:
        if (monListPtr->listCount == 1)
        {
            structPtr->mark = 0;
            structPtr->unk6787 = 0;
            structPtr->unk6788 = 0;
            structPtr->state = 0;
            return TRUE;
        }
        else
        {
            structPtr->mark = 0;
            structPtr->unk6787 = 1;
            structPtr->unk6788 = 2;
        }
        break;
    // These were probably ternaries just like cases 7-9, but couldn't match it any other way.
    case 4:
        var = monListPtr->currIndex + 1;
        if (var >= monListPtr->listCount)
            var = 0;
        CopyMonNameGenderLocation(var, 1);
        break;
    case 5:
        var = monListPtr->currIndex + 1;
        if (var >= monListPtr->listCount)
            var = 0;
        GetMonConditionGraphData(var, 1);
        break;
    case 6:
        var = monListPtr->currIndex + 1;
        if (var >= monListPtr->listCount)
            var = 0;
        ConditionGraphDrawMonPic(var, 1);
        break;
    case 7:
        CopyMonNameGenderLocation((monListPtr->currIndex - 1 >= 0) ? monListPtr->currIndex - 1 : monListPtr->listCount - 1, 2);
        break;
    case 8:
        GetMonConditionGraphData((monListPtr->currIndex - 1 >= 0) ? monListPtr->currIndex - 1 : monListPtr->listCount - 1, 2);
        break;
    case 9:
        ConditionGraphDrawMonPic((monListPtr->currIndex - 1 >= 0) ? monListPtr->currIndex - 1 : monListPtr->listCount - 1, 2);
        structPtr->state = 0;
        return TRUE;
    }

    structPtr->state++;
    return FALSE;
}

bool32 SetConditionGraphData(u8 mode)
{
    struct PokenavSub11 *structPtr = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_GRAPH);

    switch (mode)
    {
    case 0:
        CopyMonNameGenderLocation(structPtr->monIndex, structPtr->unk6789);
        break;
    case 1:
        GetMonConditionGraphData(structPtr->monIndex, structPtr->unk6789);
        break;
    case 2:
        ConditionGraphDrawMonPic(structPtr->monIndex, structPtr->unk6789);
        return TRUE;
    }

    return FALSE;
}

u8 *CopyStringLeftAlignedToConditionData(u8 *dst, const u8 *src, s16 n)
{
    while (*src != EOS)
        *dst++ = *src++, n--;

    while (n-- > 0)
        *dst++ = CHAR_SPACE;

    *dst = EOS;
    return dst;
}

u8 *CopyMonConditionNameGender(u8 *str, u16 id, bool8 arg3)
{
    u16 boxId, monId, gender, species, level, lvlDigits;
    struct BoxPokemon *boxMon;
    u8 *txtPtr, *str_;
    struct PokenavSub18 *monListPtr = GetSubstructPtr(POKENAV_SUBSTRUCT_MON_LIST);

    boxId = monListPtr->monData[id].boxId;
    monId = monListPtr->monData[id].monId;
    *(str++) = EXT_CTRL_CODE_BEGIN;
    *(str++) = EXT_CTRL_CODE_COLOR_HIGHLIGHT_SHADOW;
    *(str++) = TEXT_COLOR_BLUE;
    *(str++) = TEXT_COLOR_TRANSPARENT;
    *(str++) = TEXT_COLOR_LIGHT_BLUE;

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
    *(str_++) = EXT_CTRL_CODE_SKIP;
    *(str_++) = 60;
    switch (gender)
    {
    default:
        *(str_++) = CHAR_GENDERLESS;
        break;
    case MON_MALE:
        *(str_++) = EXT_CTRL_CODE_BEGIN;
        *(str_++) = EXT_CTRL_CODE_COLOR;
        *(str_++) = TEXT_COLOR_RED;
        *(str_++) = EXT_CTRL_CODE_BEGIN;
        *(str_++) = EXT_CTRL_CODE_SHADOW;
        *(str_++) = TEXT_COLOR_LIGHT_RED;
        *(str_++) = CHAR_MALE;
        break;
    case MON_FEMALE:
        *(str_++) = EXT_CTRL_CODE_BEGIN;
        *(str_++) = EXT_CTRL_CODE_COLOR;
        *(str_++) = TEXT_COLOR_GREEN;
        *(str_++) = EXT_CTRL_CODE_BEGIN;
        *(str_++) = EXT_CTRL_CODE_SHADOW;
        *(str_++) = TEXT_COLOR_LIGHT_GREEN;
        *(str_++) = CHAR_FEMALE;
        break;
    }

    *(str_++) = EXT_CTRL_CODE_BEGIN;
    *(str_++) = EXT_CTRL_CODE_COLOR_HIGHLIGHT_SHADOW;
    *(str_++) = TEXT_COLOR_BLUE;
    *(str_++) = TEXT_COLOR_TRANSPARENT;
    *(str_++) = TEXT_COLOR_LIGHT_BLUE;
    *(str_++) = CHAR_SLASH;
    *(str_++) = CHAR_EXTRA_SYMBOL;
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

void CopyMonNameGenderLocation(s16 id, u8 arg1)
{
    u16 boxId, i;
    struct PokenavSub11 *structPtr = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_GRAPH);
    struct PokenavSub18 *monListPtr = GetSubstructPtr(POKENAV_SUBSTRUCT_MON_LIST);

    if (id != (IsConditionMenuSearchMode() != 0 ? monListPtr->listCount : monListPtr->listCount - 1))
    {
        CopyMonConditionNameGender(structPtr->nameBuffer[arg1], id, FALSE);
        boxId = monListPtr->monData[id].boxId;
        structPtr->searchLocBuffer[arg1][0] = EXT_CTRL_CODE_BEGIN;
        structPtr->searchLocBuffer[arg1][1] = EXT_CTRL_CODE_COLOR_HIGHLIGHT_SHADOW;
        structPtr->searchLocBuffer[arg1][2] = TEXT_COLOR_BLUE;
        structPtr->searchLocBuffer[arg1][3] = TEXT_COLOR_TRANSPARENT;
        structPtr->searchLocBuffer[arg1][4] = TEXT_COLOR_LIGHT_BLUE;
        if (boxId == TOTAL_BOXES_COUNT)
            CopyStringLeftAlignedToConditionData(&structPtr->searchLocBuffer[arg1][5], gText_InParty, 8);
        else
            CopyStringLeftAlignedToConditionData(&structPtr->searchLocBuffer[arg1][5], GetBoxNamePtr(boxId), BOX_NAME_LENGTH);
    }
    else
    {
        for (i = 0; i < 12; i++)
            structPtr->nameBuffer[arg1][i] = CHAR_SPACE;
        structPtr->nameBuffer[arg1][i] = EOS;

        for (i = 0; i < 8; i++)
            structPtr->searchLocBuffer[arg1][i] = CHAR_SPACE;
        structPtr->searchLocBuffer[arg1][i] = EOS;
    }
}

void InitPartyConditionListParameters(void)
{
    u16 i, count;
    struct PokenavSub11 *structPtr = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_GRAPH);
    struct PokenavSub18 *monListPtr = AllocSubstruct(POKENAV_SUBSTRUCT_MON_LIST, sizeof(struct PokenavSub18));

    structPtr->searchMode = 0;
    for (i = 0, count = 0; i < CalculatePlayerPartyCount(); i++)
    {
        if (!GetMonData(&gPlayerParty[i], MON_DATA_IS_EGG))
        {
            monListPtr->monData[count].boxId = TOTAL_BOXES_COUNT;
            monListPtr->monData[count].monId = i;
            monListPtr->monData[count].data = 0;
            count++;
        }
    }

    monListPtr->monData[count].boxId = 0;
    monListPtr->monData[count].monId = 0;
    monListPtr->monData[count].data = 0;
    monListPtr->currIndex = 0;
    monListPtr->listCount = count + 1;
    structPtr->state = 0;
}

void sub_81CD9F8(void)
{
    struct PokenavSub11 *structPtr = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_GRAPH);
    structPtr->searchMode = 1;
    structPtr->state = 0;
}

void GetMonConditionGraphData(s16 id, u8 arg1)
{
    u16 boxId, monId, i;
    struct PokenavSub11 *structPtr = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_GRAPH);
    struct PokenavSub18 *monListPtr = GetSubstructPtr(POKENAV_SUBSTRUCT_MON_LIST);

    if (id != (IsConditionMenuSearchMode() != 0 ? monListPtr->listCount : monListPtr->listCount - 1))
    {
        boxId = monListPtr->monData[id].boxId;
        monId = monListPtr->monData[id].monId;
        structPtr->conditionData.stat[arg1][0] = GetBoxOrPartyMonData(boxId, monId, MON_DATA_COOL, NULL);
        structPtr->conditionData.stat[arg1][1] = GetBoxOrPartyMonData(boxId, monId, MON_DATA_TOUGH, NULL);
        structPtr->conditionData.stat[arg1][2] = GetBoxOrPartyMonData(boxId, monId, MON_DATA_SMART, NULL);
        structPtr->conditionData.stat[arg1][3] = GetBoxOrPartyMonData(boxId, monId, MON_DATA_CUTE, NULL);
        structPtr->conditionData.stat[arg1][4] = GetBoxOrPartyMonData(boxId, monId, MON_DATA_BEAUTY, NULL);
        structPtr->sheen[arg1] = (GetBoxOrPartyMonData(boxId, monId, MON_DATA_SHEEN, NULL) != 255)
                                 ? GetBoxOrPartyMonData(boxId, monId, MON_DATA_SHEEN, NULL) / 29u
                                 : 9;
        structPtr->monMarks[arg1] = GetBoxOrPartyMonData(boxId, monId, MON_DATA_MARKINGS, NULL);
        sub_81D2754(structPtr->conditionData.stat[arg1], structPtr->conditionData.unk14[arg1]);
    }
    else
    {
        for (i = 0; i < FLAVOR_COUNT; i++)
        {
            structPtr->conditionData.stat[arg1][i] = 0;
            structPtr->conditionData.unk14[arg1][i].unk0 = 155;
            structPtr->conditionData.unk14[arg1][i].unk2 = 91;
        }
    }
}

void ConditionGraphDrawMonPic(s16 index, u8 arg1)
{
    u16 boxId, monId, species;
    u32 personality, tid;
    struct PokenavSub11 *structPtr = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_GRAPH);
    struct PokenavSub18 *monListPtr = GetSubstructPtr(POKENAV_SUBSTRUCT_MON_LIST);

    if (index == (IsConditionMenuSearchMode() != 0 ? monListPtr->listCount : monListPtr->listCount - 1))
        return;

    boxId = monListPtr->monData[index].boxId;
    monId = monListPtr->monData[index].monId;
    species = GetBoxOrPartyMonData(boxId, monId, MON_DATA_SPECIES2, NULL);
    tid = GetBoxOrPartyMonData(boxId, monId, MON_DATA_OT_ID, NULL);
    personality = GetBoxOrPartyMonData(boxId, monId, MON_DATA_PERSONALITY, NULL);
    LoadSpecialPokePic(&gMonFrontPicTable[species], structPtr->monPicGfx[arg1], species, personality, TRUE);
    LZ77UnCompWram(GetMonSpritePalFromSpeciesAndPersonality(species, tid, personality), structPtr->monPal[arg1]);
}

u16 GetMonListCount(void)
{
    struct PokenavSub18 *monListPtr = GetSubstructPtr(POKENAV_SUBSTRUCT_MON_LIST);
    return monListPtr->listCount;
}

u16 GetConditionGraphCurrentMonIndex(void)
{
    struct PokenavSub18 *monListPtr = GetSubstructPtr(POKENAV_SUBSTRUCT_MON_LIST);
    return monListPtr->currIndex;
}

struct ConditionGraph *GetConditionGraphDataPtr(void)
{
    struct PokenavSub11 *structPtr = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_GRAPH);
    return &structPtr->conditionData;
}

u8 GetMonMarkIndex(void)
{
    struct PokenavSub11 *structPtr = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_GRAPH);
    return structPtr->mark;
}

u8 sub_81CDC9C(void)
{
    struct PokenavSub11 *structPtr = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_GRAPH);
    return structPtr->monIndex;
}

void *GetConditionMonPicGfx(u8 id)
{
    struct PokenavSub11 *structPtr = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_GRAPH);
    return structPtr->monPicGfx[id];
}

void *GetConditionMonPal(u8 id)
{
    struct PokenavSub11 *structPtr = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_GRAPH);
    return structPtr->monPal[id];
}

u8 sub_81CDCEC(void)
{
    struct PokenavSub11 *structPtr = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_GRAPH);
    return structPtr->unk6789;
}

u8 *GetConditionMonNameBuffer(u8 id)
{
    struct PokenavSub11 *structPtr = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_GRAPH);
    return structPtr->nameBuffer[id];
}

u8 *GetConditionMonLocationBuffer(u8 id)
{
    struct PokenavSub11 *structPtr = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_GRAPH);
    return structPtr->searchLocBuffer[id];
}

u16 GetConditionMonDataBuffer(void)
{
    struct PokenavSub18 *monListPtr = GetSubstructPtr(POKENAV_SUBSTRUCT_MON_LIST);
    return monListPtr->monData[monListPtr->currIndex].data;
}

bool32 IsConditionMenuSearchMode(void)
{
    struct PokenavSub11 *structPtr = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_GRAPH);
    if (structPtr->searchMode == 1)
        return TRUE;
    else
        return FALSE;
}

u8 TryGetMonMarkId(void)
{
    struct PokenavSub11 *structPtr = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_GRAPH);
    if (structPtr->searchMode == 1)
        return structPtr->monMarks[structPtr->mark];
    else
        return 0;
}

u8 GetMonSheen(void)
{
    struct PokenavSub11 *structPtr = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_GRAPH);
    return structPtr->sheen[structPtr->mark];
}
