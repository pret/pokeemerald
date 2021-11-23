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

#define CONDITION_MONS_LOADED 3

struct Pokenav_ConditionMenu
{
    u32 monPal[CONDITION_MONS_LOADED][0x20];
    u8 fill[0x180];
    u32 monPicGfx[CONDITION_MONS_LOADED][MON_PIC_SIZE];
    bool8 inSearchMode;
    s16 toLoadListIndex;
    u32 (*callback)(struct Pokenav_ConditionMenu *);
    u8 fill2[0x18];
    u8 locationText[CONDITION_MONS_LOADED][24];
    u8 nameText[CONDITION_MONS_LOADED][64];
    struct ConditionGraph graph;
    u8 numSparkles[CONDITION_MONS_LOADED];
    u8 monMarks[CONDITION_MONS_LOADED];
    s8 loadId;
    s8 nextLoadIdDown;
    s8 nextLoadIdUp;
    s8 toLoadId;
    u8 state;
};

static void InitPartyConditionListParameters(void);
static void InitSearchResultsConditionList(void);
static u32 HandleConditionMenuInput(struct Pokenav_ConditionMenu *);
static u32 GetConditionReturnCallback(struct Pokenav_ConditionMenu *);
static u32 OpenMarkingsMenu(struct Pokenav_ConditionMenu *);
static u8 ConditionGraphHandleDpadInput(struct Pokenav_ConditionMenu *);
static u8 SwitchConditionSummaryIndex(bool8);
static void CopyMonNameGenderLocation(s16, u8);
static void GetMonConditionGraphData(s16, u8);
static void ConditionGraphDrawMonPic(s16, u8);

bool32 PokenavCallback_Init_ConditionGraph_Party(void)
{
    struct Pokenav_ConditionMenu *menu = AllocSubstruct(POKENAV_SUBSTRUCT_CONDITION_GRAPH_MENU, sizeof(struct Pokenav_ConditionMenu));

    if (menu == NULL)
        return FALSE;

    ConditionGraph_Init(&menu->graph);
    InitPartyConditionListParameters();
    gKeyRepeatStartDelay = 20;
    menu->callback = HandleConditionMenuInput;
    return TRUE;
}

bool32 PokenavCallback_Init_ConditionGraph_Search(void)
{
    struct Pokenav_ConditionMenu *menu = AllocSubstruct(POKENAV_SUBSTRUCT_CONDITION_GRAPH_MENU, sizeof(struct Pokenav_ConditionMenu));

    if (menu == NULL)
        return FALSE;

    ConditionGraph_Init(&menu->graph);
    InitSearchResultsConditionList();
    gKeyRepeatStartDelay = 20;
    menu->callback = HandleConditionMenuInput;
    return TRUE;
}

u32 GetConditionGraphMenuCallback(void)
{
    struct Pokenav_ConditionMenu *menu = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_GRAPH_MENU);

    return menu->callback(menu);
}

static u32 HandleConditionMenuInput(struct Pokenav_ConditionMenu *menu)
{
    struct PokenavMonList *monListPtr = GetSubstructPtr(POKENAV_SUBSTRUCT_MON_LIST);
    u32 ret = ConditionGraphHandleDpadInput(menu);

    if (ret == CONDITION_FUNC_NONE)
    {
        if (JOY_NEW(B_BUTTON))
        {
            PlaySE(SE_SELECT);
            menu->callback = GetConditionReturnCallback;
            ret = CONDITION_FUNC_RETURN;
        }
        else if (JOY_NEW(A_BUTTON))
        {
            if (!menu->inSearchMode)
            {
                // In Party mode, pressing A only applies to the Cancel button
                if (monListPtr->currIndex == monListPtr->listCount - 1)
                {
                    // Cancel
                    PlaySE(SE_SELECT);
                    menu->callback = GetConditionReturnCallback;
                    ret = CONDITION_FUNC_RETURN;
                }
            }
            else
            {
                // In Search mode pressing A brings up the markings menu
                PlaySE(SE_SELECT);
                ret = CONDITION_FUNC_ADD_MARKINGS;
                menu->callback = OpenMarkingsMenu;
            }
        }
    }

    return ret;
}

static u32 OpenMarkingsMenu(struct Pokenav_ConditionMenu *menu)
{
    struct PokenavMonList *monListPtr;
    u8 markings;
    u32 ret = CONDITION_FUNC_NONE, boxId, monId;

    if (!HandleMonMarkingsMenuInput())
    {
        menu->monMarks[menu->loadId] = GetMonMarkingsData();
        monListPtr = GetSubstructPtr(POKENAV_SUBSTRUCT_MON_LIST);
        boxId = monListPtr->monData[monListPtr->currIndex].boxId;
        monId = monListPtr->monData[monListPtr->currIndex].monId;
        markings = menu->monMarks[menu->loadId];

        if (boxId == TOTAL_BOXES_COUNT)
            SetMonData(&gPlayerParty[monId], MON_DATA_MARKINGS, &markings);
        else
            SetBoxMonDataAt(boxId, monId, MON_DATA_MARKINGS, &markings);

        menu->callback = HandleConditionMenuInput;
        ret = CONDITION_FUNC_CLOSE_MARKINGS;
    }

    return ret;
}

static u32 GetConditionReturnCallback(struct Pokenav_ConditionMenu *menu)
{
    if (!menu->inSearchMode)
        return POKENAV_CONDITION_MENU;
    else
        return POKENAV_RETURN_CONDITION_SEARCH;
}

void FreeConditionGraphMenuSubstruct1(void)
{
    struct Pokenav_ConditionMenu *menu = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_GRAPH_MENU);
    if (!menu->inSearchMode)
        FreePokenavSubstruct(POKENAV_SUBSTRUCT_MON_LIST);

    FreePokenavSubstruct(POKENAV_SUBSTRUCT_CONDITION_GRAPH_MENU);
}

static u8 ConditionGraphHandleDpadInput(struct Pokenav_ConditionMenu *menu)
{
    struct PokenavMonList *monListPtr = GetSubstructPtr(POKENAV_SUBSTRUCT_MON_LIST);
    u8 ret = CONDITION_FUNC_NONE;

    if (JOY_HELD(DPAD_UP))
    {
        // Prevent input wrapping in search mode
        if (!menu->inSearchMode || monListPtr->currIndex != 0)
        {
            PlaySE(SE_SELECT);
            ret = SwitchConditionSummaryIndex(TRUE);
        }
    }
    else if (JOY_HELD(DPAD_DOWN))
    {
        // Prevent input wrapping in search mode
        if (!menu->inSearchMode || monListPtr->currIndex < monListPtr->listCount - 1)
        {
            PlaySE(SE_SELECT);
            ret = SwitchConditionSummaryIndex(FALSE);
        }
    }

    return ret;
}

static u8 SwitchConditionSummaryIndex(u8 moveUp)
{
    u16 newLoadId;
    bool8 wasNotLastMon, isNotLastMon;
    struct Pokenav_ConditionMenu *menu = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_GRAPH_MENU);
    struct PokenavMonList *monListPtr = GetSubstructPtr(POKENAV_SUBSTRUCT_MON_LIST);

    newLoadId = (moveUp) ? menu->nextLoadIdUp : menu->nextLoadIdDown;
    ConditionGraph_SetNewPositions(&menu->graph, menu->graph.savedPositions[menu->loadId], menu->graph.savedPositions[newLoadId]);
    wasNotLastMon = (monListPtr->currIndex != (IsConditionMenuSearchMode() ? monListPtr->listCount : monListPtr->listCount - 1));
    if (moveUp)
    {
        menu->nextLoadIdUp = menu->nextLoadIdDown;
        menu->nextLoadIdDown = menu->loadId;
        menu->loadId = newLoadId;
        menu->toLoadId = menu->nextLoadIdUp;

        monListPtr->currIndex = (monListPtr->currIndex == 0) ? monListPtr->listCount - 1 : monListPtr->currIndex - 1;
        menu->toLoadListIndex = (monListPtr->currIndex != 0) ? monListPtr->currIndex - 1 : monListPtr->listCount - 1;
    }
    else
    {
        menu->nextLoadIdDown = menu->nextLoadIdUp;
        menu->nextLoadIdUp = menu->loadId;
        menu->loadId = newLoadId;
        menu->toLoadId = menu->nextLoadIdDown;

        monListPtr->currIndex = (monListPtr->currIndex < monListPtr->listCount - 1) ? monListPtr->currIndex + 1 : 0;
        menu->toLoadListIndex = (monListPtr->currIndex < monListPtr->listCount - 1) ? monListPtr->currIndex + 1 : 0;
    }

    isNotLastMon = (monListPtr->currIndex != (IsConditionMenuSearchMode() ? monListPtr->listCount : monListPtr->listCount - 1));

    if (!wasNotLastMon)
        return CONDITION_FUNC_NO_TRANSITION;
    else if (!isNotLastMon)
        return CONDITION_FUNC_SLIDE_MON_OUT;
    else
        return CONDITION_FUNC_SLIDE_MON_IN;
}

bool32 LoadConditionGraphMenuGfx(void)
{
    s32 var;
    struct Pokenav_ConditionMenu *menu = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_GRAPH_MENU);
    struct PokenavMonList *monListPtr = GetSubstructPtr(POKENAV_SUBSTRUCT_MON_LIST);

    switch (menu->state)
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
            menu->loadId = 0;
            menu->nextLoadIdDown = 0;
            menu->nextLoadIdUp = 0;
            menu->state = 0;
            return TRUE;
        }
        else
        {
            menu->loadId = 0;
            menu->nextLoadIdDown = 1;
            menu->nextLoadIdUp = 2;
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
        menu->state = 0;
        return TRUE;
    }

    menu->state++;
    return FALSE;
}

bool32 LoadNextConditionMenuMonData(u8 mode)
{
    struct Pokenav_ConditionMenu *menu = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_GRAPH_MENU);

    switch (mode)
    {
    case CONDITION_LOAD_MON_INFO:
        CopyMonNameGenderLocation(menu->toLoadListIndex, menu->toLoadId);
        break;
    case CONDITION_LOAD_GRAPH:
        GetMonConditionGraphData(menu->toLoadListIndex, menu->toLoadId);
        break;
    case CONDITION_LOAD_MON_PIC:
        ConditionGraphDrawMonPic(menu->toLoadListIndex, menu->toLoadId);
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

static u8 *CopyConditionMonNameGender(u8 *str, u16 listId, bool8 arg3)
{
    u16 boxId, monId, gender, species, level, lvlDigits;
    struct BoxPokemon *boxMon;
    u8 *txtPtr, *str_;
    struct PokenavMonList *monListPtr = GetSubstructPtr(POKENAV_SUBSTRUCT_MON_LIST);

    boxId = monListPtr->monData[listId].boxId;
    monId = monListPtr->monData[listId].monId;
    *(str++) = EXT_CTRL_CODE_BEGIN;
    *(str++) = EXT_CTRL_CODE_COLOR_HIGHLIGHT_SHADOW;
    *(str++) = TEXT_COLOR_BLUE;
    *(str++) = TEXT_COLOR_TRANSPARENT;
    *(str++) = TEXT_COLOR_LIGHT_BLUE;

    if (GetBoxOrPartyMonData(boxId, monId, MON_DATA_IS_EGG, NULL))
        return StringCopyPadded(str, gText_EggNickname, CHAR_SPACE, 12);

    GetBoxOrPartyMonData(boxId, monId, MON_DATA_NICKNAME, str);
    StringGet_Nickname(str);
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
        *(str_++) = CHAR_SPACER; // Genderless
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

static void CopyMonNameGenderLocation(s16 listId, u8 loadId)
{
    u16 boxId, i;
    struct Pokenav_ConditionMenu *menu = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_GRAPH_MENU);
    struct PokenavMonList *monListPtr = GetSubstructPtr(POKENAV_SUBSTRUCT_MON_LIST);

    if (listId != (IsConditionMenuSearchMode() ? monListPtr->listCount : monListPtr->listCount - 1))
    {
        CopyConditionMonNameGender(menu->nameText[loadId], listId, FALSE);
        boxId = monListPtr->monData[listId].boxId;
        menu->locationText[loadId][0] = EXT_CTRL_CODE_BEGIN;
        menu->locationText[loadId][1] = EXT_CTRL_CODE_COLOR_HIGHLIGHT_SHADOW;
        menu->locationText[loadId][2] = TEXT_COLOR_BLUE;
        menu->locationText[loadId][3] = TEXT_COLOR_TRANSPARENT;
        menu->locationText[loadId][4] = TEXT_COLOR_LIGHT_BLUE;
        if (boxId == TOTAL_BOXES_COUNT)
            CopyStringLeftAlignedToConditionData(&menu->locationText[loadId][5], gText_InParty, BOX_NAME_LENGTH);
        else
            CopyStringLeftAlignedToConditionData(&menu->locationText[loadId][5], GetBoxNamePtr(boxId), BOX_NAME_LENGTH);
    }
    else
    {
        for (i = 0; i < 12; i++)
            menu->nameText[loadId][i] = CHAR_SPACE;
        menu->nameText[loadId][i] = EOS;

        for (i = 0; i < BOX_NAME_LENGTH; i++)
            menu->locationText[loadId][i] = CHAR_SPACE;
        menu->locationText[loadId][i] = EOS;
    }
}

static void InitPartyConditionListParameters(void)
{
    u16 i, count;
    struct Pokenav_ConditionMenu *menu = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_GRAPH_MENU);
    struct PokenavMonList *monListPtr = AllocSubstruct(POKENAV_SUBSTRUCT_MON_LIST, sizeof(struct PokenavMonList));

    menu->inSearchMode = FALSE;
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
    menu->state = 0;
}

static void InitSearchResultsConditionList(void)
{
    struct Pokenav_ConditionMenu *menu = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_GRAPH_MENU);
    menu->inSearchMode = TRUE;
    menu->state = 0;
}

static void GetMonConditionGraphData(s16 listId, u8 loadId)
{
    u16 boxId, monId, i;
    struct Pokenav_ConditionMenu *menu = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_GRAPH_MENU);
    struct PokenavMonList *monListPtr = GetSubstructPtr(POKENAV_SUBSTRUCT_MON_LIST);

    if (listId != (IsConditionMenuSearchMode() ? monListPtr->listCount : monListPtr->listCount - 1))
    {
        boxId = monListPtr->monData[listId].boxId;
        monId = monListPtr->monData[listId].monId;
        menu->graph.conditions[loadId][CONDITION_COOL] = GetBoxOrPartyMonData(boxId, monId, MON_DATA_COOL, NULL);
        menu->graph.conditions[loadId][CONDITION_TOUGH] = GetBoxOrPartyMonData(boxId, monId, MON_DATA_TOUGH, NULL);
        menu->graph.conditions[loadId][CONDITION_SMART] = GetBoxOrPartyMonData(boxId, monId, MON_DATA_SMART, NULL);
        menu->graph.conditions[loadId][CONDITION_CUTE] = GetBoxOrPartyMonData(boxId, monId, MON_DATA_CUTE, NULL);
        menu->graph.conditions[loadId][CONDITION_BEAUTY] = GetBoxOrPartyMonData(boxId, monId, MON_DATA_BEAUTY, NULL);
        menu->numSparkles[loadId] = GET_NUM_CONDITION_SPARKLES(GetBoxOrPartyMonData(boxId, monId, MON_DATA_SHEEN, NULL));
        menu->monMarks[loadId] = GetBoxOrPartyMonData(boxId, monId, MON_DATA_MARKINGS, NULL);
        ConditionGraph_CalcPositions(menu->graph.conditions[loadId], menu->graph.savedPositions[loadId]);
    }
    else
    {
        // Set empty graph point
        for (i = 0; i < CONDITION_COUNT; i++)
        {
            menu->graph.conditions[loadId][i] = 0;
            menu->graph.savedPositions[loadId][i].x = CONDITION_GRAPH_CENTER_X;
            menu->graph.savedPositions[loadId][i].y = CONDITION_GRAPH_CENTER_Y;
        }
    }
}

static void ConditionGraphDrawMonPic(s16 listId, u8 loadId)
{
    u16 boxId, monId, species;
    u32 personality, tid;
    struct Pokenav_ConditionMenu *menu = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_GRAPH_MENU);
    struct PokenavMonList *monListPtr = GetSubstructPtr(POKENAV_SUBSTRUCT_MON_LIST);

    if (listId == (IsConditionMenuSearchMode() ? monListPtr->listCount : monListPtr->listCount - 1))
        return;

    boxId = monListPtr->monData[listId].boxId;
    monId = monListPtr->monData[listId].monId;
    species = GetBoxOrPartyMonData(boxId, monId, MON_DATA_SPECIES2, NULL);
    tid = GetBoxOrPartyMonData(boxId, monId, MON_DATA_OT_ID, NULL);
    personality = GetBoxOrPartyMonData(boxId, monId, MON_DATA_PERSONALITY, NULL);
    LoadSpecialPokePic(&gMonFrontPicTable[species], menu->monPicGfx[loadId], species, personality, TRUE);
    LZ77UnCompWram(GetMonSpritePalFromSpeciesAndPersonality(species, tid, personality), menu->monPal[loadId]);
}

u16 GetMonListCount(void)
{
    struct PokenavMonList *monListPtr = GetSubstructPtr(POKENAV_SUBSTRUCT_MON_LIST);
    return monListPtr->listCount;
}

u16 GetConditionGraphCurrentListIndex(void)
{
    struct PokenavMonList *monListPtr = GetSubstructPtr(POKENAV_SUBSTRUCT_MON_LIST);
    return monListPtr->currIndex;
}

struct ConditionGraph *GetConditionGraphPtr(void)
{
    struct Pokenav_ConditionMenu *menu = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_GRAPH_MENU);
    return &menu->graph;
}

u8 GetConditionGraphMenuCurrentLoadIndex(void)
{
    struct Pokenav_ConditionMenu *menu = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_GRAPH_MENU);
    return menu->loadId;
}

u8 GetConditionGraphMenuToLoadListIndex(void)
{
    struct Pokenav_ConditionMenu *menu = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_GRAPH_MENU);
    return menu->toLoadListIndex;
}

void *GetConditionMonPicGfx(u8 loadId)
{
    struct Pokenav_ConditionMenu *menu = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_GRAPH_MENU);
    return menu->monPicGfx[loadId];
}

void *GetConditionMonPal(u8 loadId)
{
    struct Pokenav_ConditionMenu *menu = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_GRAPH_MENU);
    return menu->monPal[loadId];
}

u8 GetConditionGraphMenuToLoadId(void)
{
    struct Pokenav_ConditionMenu *menu = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_GRAPH_MENU);
    return menu->toLoadId;
}

u8 *GetConditionMonNameText(u8 loadId)
{
    struct Pokenav_ConditionMenu *menu = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_GRAPH_MENU);
    return menu->nameText[loadId];
}

u8 *GetConditionMonLocationText(u8 loadId)
{
    struct Pokenav_ConditionMenu *menu = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_GRAPH_MENU);
    return menu->locationText[loadId];
}

u16 GetConditionMonDataBuffer(void)
{
    struct PokenavMonList *monListPtr = GetSubstructPtr(POKENAV_SUBSTRUCT_MON_LIST);
    return monListPtr->monData[monListPtr->currIndex].data;
}

bool32 IsConditionMenuSearchMode(void)
{
    struct Pokenav_ConditionMenu *menu = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_GRAPH_MENU);
    if (menu->inSearchMode == TRUE)
        return TRUE;
    else
        return FALSE;
}

// Markings are only shown in search mode
u8 TryGetMonMarkId(void)
{
    struct Pokenav_ConditionMenu *menu = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_GRAPH_MENU);
    if (menu->inSearchMode == TRUE)
        return menu->monMarks[menu->loadId];
    else
        return 0;
}

u8 GetNumConditionMonSparkles(void)
{
    struct Pokenav_ConditionMenu *menu = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_GRAPH_MENU);
    return menu->numSparkles[menu->loadId];
}
