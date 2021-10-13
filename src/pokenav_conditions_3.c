#include "global.h"
#include "pokenav.h"
#include "bg.h"
#include "menu.h"
#include "window.h"
#include "sound.h"
#include "dynamic_placeholder_text_util.h"
#include "strings.h"
#include "string_util.h"
#include "international_string_util.h"
#include "constants/songs.h"

enum
{
    CONDITION_SEARCH_FUNC_NONE,
    CONDITION_SEARCH_FUNC_MOVE_UP,
    CONDITION_SEARCH_FUNC_MOVE_DOWN,
    CONDITION_SEARCH_FUNC_PAGE_UP,
    CONDITION_SEARCH_FUNC_PAGE_DOWN,
    CONDITION_SEARCH_FUNC_EXIT,
    CONDITION_SEARCH_FUNC_SELECT_MON,
};

struct PokenavSub7
{
    u32 (*callback)(struct PokenavSub7 *);
    u32 loopedTaskId;
    u8 fill1[4];
    s32 boxId;
    s32 monId;
    u32 conditionDataId;
    u32 returnFromGraph;
    u32 isPartyCondition;
    struct PokenavSub18 *monList;
};

struct PokenavSub8
{
    bool32 (*callback)(void);
    u32 ltid;   //looped task Id
    u16 winid;
    bool32 fromGraph;
    u8 buff[BG_SCREEN_SIZE];
}; // size: 0x810

static u32 HandleConditionSearchInput_WaitSetup(struct PokenavSub7 *structPtr);
static u32 HandleConditionSearchInput(struct PokenavSub7 *structPtr);
static u32 OpenConditionGraphFromSearchList(struct PokenavSub7 *structPtr);
static u32 ReturnToConditionSearchList(struct PokenavSub7 *structPtr);
static u32 GetConditionSearchLoopedTask(s32 state);
static u32 BuildPartyMonSearchResults(s32 state);
static u32 InitBoxMonSearchResults(s32 state);
static u32 BuildBoxMonSearchResults(s32 state);
static u32 sub_81CF278(s32 state);
static u32 LoopedTask_MoveSearchListCursorUp(s32 state);
static u32 LoopedTask_MoveSearchListCursorDown(s32 state);
static u32 LoopedTask_MoveSearchListPageUp(s32 state);
static u32 LoopedTask_MoveSearchListPageDown(s32 state);
static u32 LoopedTask_ExitConditionSearchMenu(s32 state);
static u32 LoopedTask_SelectSearchResult(s32 state);
static void sub_81CF2C4(struct PokenavSub7 *structPtr, struct PokenavMonList *item);
static bool32 GetSearchResultCurrentLoopedTaskActive(void);
static u32 LoopedTask_OpenConditionSearchResults(s32 state);
static void AddSearchResultListMenuWindow(struct PokenavSub8 *);
static void PrintSearchResultListMenuItems(struct PokenavSub8 *);
static void InitConditionSearchListMenuTemplate(void);
static void PrintSearchMonListItem(struct PokenavMonList *, u8 *);

static const u32 sSearchMonDataIds[] = {MON_DATA_COOL, MON_DATA_BEAUTY, MON_DATA_CUTE, MON_DATA_SMART, MON_DATA_TOUGH};

static const LoopedTask sConditionSearchLoopedTaskFuncs[] =
{
    BuildPartyMonSearchResults,
    InitBoxMonSearchResults,
    BuildBoxMonSearchResults,
    sub_81CF278
};

static const u16 sConditionSearchResultFramePal[] = INCBIN_U16("graphics/pokenav/condition_search2.gbapal");
static const u32 sConditionSearchResultTiles[] = INCBIN_U32("graphics/pokenav/condition_search2.4bpp.lz");
static const u32 sConditionSearchResultTilemap[] = INCBIN_U32("graphics/pokenav/condition_search2.bin.lz");
static const u16 gUnknown_08623570[] = INCBIN_U16("graphics/pokenav/8623570.gbapal");

static const struct BgTemplate sConditionSearchResultBgTemplates[] =
{
    {
        .bg = 1,
        .charBaseIndex = 1,
        .mapBaseIndex = 0x06,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 0
    }, {
        .bg = 2,
        .charBaseIndex = 2,
        .mapBaseIndex = 0x07,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 3,
        .baseTile = 0
    }
};

static const LoopedTask sSearchResultLoopTaskFuncs[] = 
{
    [CONDITION_SEARCH_FUNC_NONE]       = NULL,
    [CONDITION_SEARCH_FUNC_MOVE_UP]    = LoopedTask_MoveSearchListCursorUp,
    [CONDITION_SEARCH_FUNC_MOVE_DOWN]  = LoopedTask_MoveSearchListCursorDown,
    [CONDITION_SEARCH_FUNC_PAGE_UP]    = LoopedTask_MoveSearchListPageUp,
    [CONDITION_SEARCH_FUNC_PAGE_DOWN]  = LoopedTask_MoveSearchListPageDown,
    [CONDITION_SEARCH_FUNC_EXIT]       = LoopedTask_ExitConditionSearchMenu,
    [CONDITION_SEARCH_FUNC_SELECT_MON] = LoopedTask_SelectSearchResult
};

static const struct WindowTemplate sSearchResultListMenuWindowTemplate = 
{
    .bg = 1,
    .tilemapLeft = 1,
    .tilemapTop = 6,
    .width = 7,
    .height = 2,
    .paletteNum = 1,
    .baseBlock = 20
};

static const u8 sText_MaleSymbol[] = _("{COLOR_HIGHLIGHT_SHADOW}{LIGHT_RED}{WHITE}{GREEN}♂{COLOR_HIGHLIGHT_SHADOW}{DARK_GREY}{WHITE}{LIGHT_GREY}");
static const u8 sText_FemaleSymbol[] = _("{COLOR_HIGHLIGHT_SHADOW}{LIGHT_GREEN}{WHITE}{BLUE}♀{COLOR_HIGHLIGHT_SHADOW}{DARK_GREY}{WHITE}{LIGHT_GREY}");
static const u8 sText_NoGenderSymbol[] = _("{UNK_SPACER}");

bool32 PokenavCallback_Init_ConditionSearch(void)
{
    struct PokenavSub7 *structPtr = AllocSubstruct(7, sizeof(struct PokenavSub7));
    if (structPtr == NULL)
        return FALSE;

    structPtr->monList = AllocSubstruct(POKENAV_SUBSTRUCT_MON_LIST, sizeof(struct PokenavSub18));
    if (structPtr->monList == NULL)
        return FALSE;

    structPtr->callback = HandleConditionSearchInput_WaitSetup;
    structPtr->loopedTaskId = CreateLoopedTask(GetConditionSearchLoopedTask, 1);
    structPtr->returnFromGraph = 0;
    structPtr->conditionDataId = sSearchMonDataIds[GetSelectedConditionSearch()];
    return TRUE;
}

// return to search results from condition graph
bool32 PokenavCallback_Init_ReturnToMonSearchList(void)
{
    struct PokenavSub7 *structPtr = AllocSubstruct(POKENAV_SUBSTRUCT_CONDITION_SEARCH_RESULTS, sizeof(struct PokenavSub7));
    if (structPtr == NULL)
        return FALSE;

    structPtr->monList = GetSubstructPtr(POKENAV_SUBSTRUCT_MON_LIST);
    structPtr->callback = HandleConditionSearchInput;
    structPtr->returnFromGraph = 1;
    structPtr->conditionDataId = sSearchMonDataIds[GetSelectedConditionSearch()];
    return TRUE;
}

u32 GetConditionSearchResultsCallback(void)
{
    struct PokenavSub7 *structPtr = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_SEARCH_RESULTS);
    return structPtr->callback(structPtr);
}

void FreeSearchResultSubstruct1(void)
{
    struct PokenavSub7 *structPtr = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_SEARCH_RESULTS);
    if (structPtr->isPartyCondition == 0)
        FreePokenavSubstruct(POKENAV_SUBSTRUCT_MON_LIST);
    FreePokenavSubstruct(POKENAV_SUBSTRUCT_CONDITION_SEARCH_RESULTS);
}

static bool32 HandleConditionSearchInput_WaitSetup(struct PokenavSub7 *structPtr)
{
    if (!IsLoopedTaskActive(structPtr->loopedTaskId))
        structPtr->callback = HandleConditionSearchInput;
    return FALSE;
}

static u32 HandleConditionSearchInput(struct PokenavSub7 *structPtr)
{
    if (JOY_REPEAT(DPAD_UP))
        return CONDITION_SEARCH_FUNC_MOVE_UP;
    else if (JOY_REPEAT(DPAD_DOWN))
        return CONDITION_SEARCH_FUNC_MOVE_DOWN;
    else if (JOY_NEW(DPAD_LEFT))
        return CONDITION_SEARCH_FUNC_PAGE_UP;
    else if (JOY_NEW(DPAD_RIGHT))
        return CONDITION_SEARCH_FUNC_PAGE_DOWN;
    else if (JOY_NEW(B_BUTTON))
    {
        structPtr->isPartyCondition = 0;
        structPtr->callback = ReturnToConditionSearchList;
        return CONDITION_SEARCH_FUNC_EXIT;
    }
    else if (JOY_NEW(A_BUTTON))
    {
        structPtr->monList->currIndex = GetSelectedPokenavListIndex();
        structPtr->isPartyCondition = 1;
        structPtr->callback = OpenConditionGraphFromSearchList;
        return CONDITION_SEARCH_FUNC_SELECT_MON;
    }
    else
        return CONDITION_SEARCH_FUNC_NONE;
}

static u32 ReturnToConditionSearchList(struct PokenavSub7 *structPtr)
{
    return POKENAV_CONDITION_SEARCH_MENU;
}

static u32 OpenConditionGraphFromSearchList(struct PokenavSub7 *structPtr)
{
    return POKENAV_CONDITION_GRAPH_FROM_SEARCH;
}

static u32 sub_81CF0C0(void)
{
    struct PokenavSub7 *structPtr = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_SEARCH_RESULTS);
    return structPtr->returnFromGraph;
}

static struct PokenavMonList * GetSearchResultsMonDataList(void)
{
    struct PokenavSub7 * ptr = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_SEARCH_RESULTS);
    return ptr->monList->monData;
}

static u16 GetSearchResultsMonListCount(void)
{
    struct PokenavSub7 * ptr = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_SEARCH_RESULTS);
    return ptr->monList->listCount;
}

static s32 GetSearchResultsSelectedMonData(void)
{
    struct PokenavSub7 * ptr = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_SEARCH_RESULTS);
    s32 i = GetSelectedPokenavListIndex();
    return ptr->monList->monData[i].data;
}

static u16 sub_81CF10C(void)
{
    struct PokenavSub7 * ptr = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_SEARCH_RESULTS);
    return ptr->monList->currIndex;
}

static u32 GetConditionSearchLoopedTask(s32 state)
{
    return sConditionSearchLoopedTaskFuncs[state](state);
}

static u32 BuildPartyMonSearchResults(s32 state)
{
    s32 i;
    struct PokenavMonList item;
    struct PokenavSub7 * ptr = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_SEARCH_RESULTS);

    ptr->monList->listCount = 0;
    ptr->monList->currIndex = 0;
    item.boxId = 14;
    for (i = 0; i < PARTY_SIZE; i++)
    {
        struct Pokemon * pokemon = &gPlayerParty[i];
        if (!GetMonData(pokemon, MON_DATA_SANITY_HAS_SPECIES))
            return LT_INC_AND_CONTINUE;
        if (!GetMonData(pokemon, MON_DATA_SANITY_IS_EGG))
        {
            item.monId = i;
            item.data = GetMonData(pokemon, ptr->conditionDataId);
            sub_81CF2C4(ptr, &item);
        }
    }

    return LT_INC_AND_CONTINUE;
}

static u32 InitBoxMonSearchResults(s32 state)
{
    struct PokenavSub7 * ptr = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_SEARCH_RESULTS);
    ptr->monId = 0;
    ptr->boxId = 0;
    return LT_INC_AND_CONTINUE;
}

static u32 BuildBoxMonSearchResults(s32 state)
{
    struct PokenavSub7 * ptr = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_SEARCH_RESULTS);
    s32 boxId = ptr->boxId;
    s32 monId = ptr->monId;
    s32 boxCount = 0;
    struct PokenavMonList item;

    while (boxId < TOTAL_BOXES_COUNT)
    {
        while (monId < IN_BOX_COUNT)
        {
            if (CheckBoxMonSanityAt(boxId, monId))
            {
                item.boxId = boxId;
                item.monId = monId;
                item.data = GetBoxMonDataAt(boxId, monId, ptr->conditionDataId);
                sub_81CF2C4(ptr, &item);
            }
            boxCount++;
            monId++;
            if (boxCount > 14)
            {
                ptr->boxId = boxId;
                ptr->monId = monId;
                return LT_CONTINUE;
            }
        }
        monId = 0;
        boxId++;
    }

    return LT_INC_AND_CONTINUE;
}

static u32 sub_81CF278(s32 state)
{
    struct PokenavSub7 * ptr = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_SEARCH_RESULTS);
    s32 r6 = ptr->monList->listCount;
    s32 r4 = ptr->monList->monData[0].data;
    s32 i;
    ptr->monList->monData[0].data = 1;
    for (i = 1; i < r6; i++)
    {
        if (ptr->monList->monData[i].data == r4)
        {
            ptr->monList->monData[i].data = ptr->monList->monData[i - 1].data;
        }
        else
        {
            r4 = ptr->monList->monData[i].data;
            ptr->monList->monData[i].data = i + 1;
        }
    }
    ptr->returnFromGraph = 1;
    return LT_FINISH;
}

static void sub_81CF2C4(struct PokenavSub7 *structPtr, struct PokenavMonList *item)
{
    u32 left = 0;
    u32 right = structPtr->monList->listCount;
    u32 insertionIdx = left + (right - left) / 2;

    while (right != insertionIdx)
    {
        if (item->data > structPtr->monList->monData[insertionIdx].data)
            right = insertionIdx;
        else
            left = insertionIdx + 1;
        insertionIdx = left + (right - left) / 2;
    }
    for (right = structPtr->monList->listCount; right > insertionIdx; right--)
        structPtr->monList->monData[right] = structPtr->monList->monData[right - 1];
    structPtr->monList->monData[insertionIdx] = *item;
    structPtr->monList->listCount++;
}

bool32 OpenConditionSearchResults(void)
{
    struct PokenavSub8 *searchList = AllocSubstruct(POKENAV_SUBSTRUCT_CONDITION_SEARCH_RESULT_LIST, sizeof(struct PokenavSub8));
    if (searchList == NULL)
        return FALSE;
    searchList->ltid = CreateLoopedTask(LoopedTask_OpenConditionSearchResults, 1);
    searchList->callback = GetSearchResultCurrentLoopedTaskActive;
    searchList->fromGraph = FALSE;
    return TRUE;
}

bool32 OpenConditionSearchListFromGraph(void)
{
    struct PokenavSub8 *searchList = AllocSubstruct(POKENAV_SUBSTRUCT_CONDITION_SEARCH_RESULT_LIST, sizeof(struct PokenavSub8));
    if (searchList == NULL)
        return FALSE;
    searchList->ltid = CreateLoopedTask(LoopedTask_OpenConditionSearchResults, 1);
    searchList->callback = GetSearchResultCurrentLoopedTaskActive;
    searchList->fromGraph = TRUE;
    return TRUE;
}

void CreateSearchResultsLoopedTask(s32 idx)
{
    struct PokenavSub8 *searchList = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_SEARCH_RESULT_LIST);
    searchList->ltid = CreateLoopedTask(sSearchResultLoopTaskFuncs[idx], 1);
    searchList->callback = GetSearchResultCurrentLoopedTaskActive;
}

bool32 IsSearchResultLoopedTaskActive(void)
{
    struct PokenavSub8 *searchList = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_SEARCH_RESULT_LIST);
    return searchList->callback();
}

bool32 GetSearchResultCurrentLoopedTaskActive(void)
{
    struct PokenavSub8 *searchList = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_SEARCH_RESULT_LIST);
    return IsLoopedTaskActive(searchList->ltid);
}

void FreeSearchResultSubstruct2(void)
{
    struct PokenavSub8 *searchList = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_SEARCH_RESULT_LIST);
    sub_81C8234();
    RemoveWindow(searchList->winid);
    FreePokenavSubstruct(POKENAV_SUBSTRUCT_CONDITION_SEARCH_RESULT_LIST);
}

static u32 LoopedTask_OpenConditionSearchResults(s32 state)
{
    struct PokenavSub8 *searchList = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_SEARCH_RESULT_LIST);
    switch (state)
    {
    case 0:
        InitBgTemplates(sConditionSearchResultBgTemplates, ARRAY_COUNT(sConditionSearchResultBgTemplates));
        DecompressAndCopyTileDataToVram(1, sConditionSearchResultTiles, 0, 0, 0);
        SetBgTilemapBuffer(1, searchList->buff);
        CopyToBgTilemapBuffer(1, sConditionSearchResultTilemap, 0, 0);
        CopyBgTilemapBufferToVram(1);
        CopyPaletteIntoBufferUnfaded(sConditionSearchResultFramePal, 0x10, 0x20);
        CopyBgTilemapBufferToVram(1);
        return LT_INC_AND_PAUSE;
    case 1:
        if (FreeTempTileDataBuffersIfPossible())
            return LT_PAUSE;
        if (!sub_81CF0C0())
            return LT_PAUSE;
        return LT_INC_AND_PAUSE;
    case 2:
        if (FreeTempTileDataBuffersIfPossible())
            return LT_PAUSE;
        CopyPaletteIntoBufferUnfaded(gUnknown_08623570, 0x20, 32);
        InitConditionSearchListMenuTemplate();
        return LT_INC_AND_PAUSE;
    case 3:
        if (sub_81C8224())
            return LT_PAUSE;
        AddSearchResultListMenuWindow(searchList);
        PrintHelpBarText(HELPBAR_CONDITION_MON_LIST);
        return LT_INC_AND_PAUSE;
    case 4:
        if (FreeTempTileDataBuffersIfPossible())
            return LT_PAUSE;
        ChangeBgX(1, 0, 0);
        ChangeBgY(1, 0, 0);
        ShowBg(1);
        ShowBg(2);
        HideBg(3);
        if (!searchList->fromGraph)
        {
            u8 searchGfxId = GetSelectedConditionSearch() + POKENAV_MENUITEM_CONDITION_SEARCH_COOL;
            LoadLeftHeaderGfxForIndex(searchGfxId);
            ShowLeftHeaderGfx(searchGfxId, 1, 0);
            ShowLeftHeaderGfx(POKENAV_GFX_CONDITION_MENU, 1, 0);
        }
        PokenavFadeScreen(1);
        return LT_INC_AND_PAUSE;
    case 5:
        if (IsPaletteFadeActive())
            return LT_PAUSE;
        if (AreLeftHeaderSpritesMoving())
            return LT_PAUSE;
        break;
    }
    return LT_FINISH;
}

static u32 LoopedTask_MoveSearchListCursorUp(s32 state)
{
    struct PokenavSub8 *searchList = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_SEARCH_RESULT_LIST);
    switch (state)
    {
    case 0:
        switch (MatchCall_MoveCursorUp())
        {
        case 0:
            return LT_FINISH;
        case 1:
            PlaySE(SE_SELECT);
            return LT_SET_STATE(2);
        case 2:
            PlaySE(SE_SELECT);
            break;
        }
        return LT_INC_AND_PAUSE;
    case 1:
        if (IsMonListLoopedTaskActive())
            return LT_PAUSE;
        // fallthrough
    case 2:
        PrintSearchResultListMenuItems(searchList);
        return LT_INC_AND_PAUSE;
    case 3:
        if (IsDma3ManagerBusyWithBgCopy())
            return LT_PAUSE;
        break;
    }
    return LT_FINISH;
}

static u32 LoopedTask_MoveSearchListCursorDown(s32 state)
{
    struct PokenavSub8 *searchList = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_SEARCH_RESULT_LIST);
    switch (state)
    {
    case 0:
        switch (MatchCall_MoveCursorDown())
        {
        case 0:
            return LT_FINISH;
        case 1:
            PlaySE(SE_SELECT);
            return LT_SET_STATE(2);
        case 2:
            PlaySE(SE_SELECT);
            break;
        }
        return LT_INC_AND_PAUSE;
    case 1:
        if (IsMonListLoopedTaskActive())
            return LT_PAUSE;
        // fallthrough
    case 2:
        PrintSearchResultListMenuItems(searchList);
        return LT_INC_AND_PAUSE;
    case 3:
        if (IsDma3ManagerBusyWithBgCopy())
            return LT_PAUSE;
        break;
    }
    return LT_FINISH;
}

static u32 LoopedTask_MoveSearchListPageUp(s32 state)
{
    struct PokenavSub8 *searchList = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_SEARCH_RESULT_LIST);
    switch (state)
    {
    case 0:
        switch (MatchCall_PageUp())
        {
        case 0:
            return LT_FINISH;
        case 1:
            PlaySE(SE_SELECT);
            return LT_SET_STATE(2);
        case 2:
            PlaySE(SE_SELECT);
            break;
        }
        return LT_INC_AND_PAUSE;
    case 1:
        if (IsMonListLoopedTaskActive())
            return LT_PAUSE;
        // fallthrough
    case 2:
        PrintSearchResultListMenuItems(searchList);
        return LT_INC_AND_PAUSE;
    case 3:
        if (IsDma3ManagerBusyWithBgCopy())
            return LT_PAUSE;
        break;
    }
    return LT_FINISH;
}

static u32 LoopedTask_MoveSearchListPageDown(s32 state)
{
    struct PokenavSub8 *searchList = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_SEARCH_RESULT_LIST);
    switch (state)
    {
    case 0:
        switch (MatchCall_PageDown())
        {
        case 0:
            return LT_FINISH;
        case 1:
            PlaySE(SE_SELECT);
            return LT_SET_STATE(2);
        case 2:
            PlaySE(SE_SELECT);
            break;
        }
        return LT_INC_AND_PAUSE;
    case 1:
        if (IsMonListLoopedTaskActive())
            return LT_PAUSE;
        // fallthrough
    case 2:
        PrintSearchResultListMenuItems(searchList);
        return LT_INC_AND_PAUSE;
    case 3:
        if (IsDma3ManagerBusyWithBgCopy())
            return LT_PAUSE;
        break;
    }
    return LT_FINISH;
}

static u32 LoopedTask_ExitConditionSearchMenu(s32 state)
{
    switch (state)
    {
    case 0:
        PlaySE(SE_SELECT);
        PokenavFadeScreen(0);
        SlideMenuHeaderDown();
        return LT_INC_AND_PAUSE;
    case 1:
        if (IsPaletteFadeActive())
            return LT_PAUSE;
        if (MainMenuLoopedTaskIsBusy())
            return LT_PAUSE;
        SetLeftHeaderSpritesInvisibility();
        break;
    }
    return LT_FINISH;
}

static u32 LoopedTask_SelectSearchResult(s32 state)
{
    switch (state)
    {
    case 0:
        PlaySE(SE_SELECT);
        PokenavFadeScreen(0);
        return LT_INC_AND_PAUSE;
    case 1:
        if (IsPaletteFadeActive())
            return LT_PAUSE;
        break;
    }
    return LT_FINISH;
}

static void AddSearchResultListMenuWindow(struct PokenavSub8 *searchList)
{
    searchList->winid = AddWindow(&sSearchResultListMenuWindowTemplate);
    PutWindowTilemap(searchList->winid);
    CopyWindowToVram(searchList->winid, 1);
    PrintSearchResultListMenuItems(searchList);
}

static void PrintSearchResultListMenuItems(struct PokenavSub8 *searchList)
{
    s32 r7 = GetSearchResultsSelectedMonData();
    DynamicPlaceholderTextUtil_Reset();
    DynamicPlaceholderTextUtil_SetPlaceholderPtr(0, gStringVar1);
    *gStringVar1 = EOS;
    DynamicPlaceholderTextUtil_ExpandPlaceholders(gStringVar2, gText_NumberF700);
    AddTextPrinterParameterized(searchList->winid, 1, gStringVar2, 4, 1, 0xFF, NULL);
    ConvertIntToDecimalStringN(gStringVar1, r7, STR_CONV_MODE_RIGHT_ALIGN, 3);
    AddTextPrinterParameterized(searchList->winid, 1, gStringVar1, 34, 1, 0xFF, NULL);
    CopyWindowToVram(searchList->winid, 2);
}

static void InitConditionSearchListMenuTemplate(void)
{
    struct PokenavListTemplate template;
    
    template.list.monList = GetSearchResultsMonDataList();
    template.count = GetSearchResultsMonListCount();
    template.unk8 = 4;
    template.unk6 = sub_81CF10C();
    template.item_X = 13;
    template.windowWidth = 17;
    template.listTop = 1;
    template.maxShowed = 8;
    template.fillValue = 2;
    template.fontId = 1;
    template.listFunc.printMonFunc = PrintSearchMonListItem;
    template.unk14 = NULL;
    sub_81C81D4(&sConditionSearchResultBgTemplates[1], &template, 0);
}

static void PrintSearchMonListItem(struct PokenavMonList * item, u8 * dest)
{
    u8 gender;
    u8 level;
    u8 * s;
    const u8 * genderStr;

    // Mon is in party
    if (item->boxId == TOTAL_BOXES_COUNT)
    {
        struct Pokemon * mon = &gPlayerParty[item->monId];
        gender = GetMonGender(mon);
        level = GetLevelFromMonExp(mon);
        GetMonData(mon, MON_DATA_NICKNAME, gStringVar3);
    }
    // Mon is in PC
    else
    {
        struct BoxPokemon * mon = GetBoxedMonPtr(item->boxId, item->monId);
        gender = GetBoxMonGender(mon);
        level = GetLevelFromBoxMonExp(mon);
        GetBoxMonData(mon, MON_DATA_NICKNAME, gStringVar3);
    }

    StringGetEnd10(gStringVar3);
    dest = sub_81DB494(dest, 1, gStringVar3, 60);
    switch (gender)
    {
    default:
        genderStr = sText_NoGenderSymbol;
        break;
    case MON_MALE:
        genderStr = sText_MaleSymbol;
        break;
    case MON_FEMALE:
        genderStr = sText_FemaleSymbol;
        break;
    }
    s = StringCopy(gStringVar1, genderStr);
    *s++ = CHAR_SLASH;
    *s++ = CHAR_EXTRA_SYMBOL;
    *s++ = CHAR_LV_2;
    ConvertIntToDecimalStringN(s, level, STR_CONV_MODE_LEFT_ALIGN, 3);
    sub_81DB494(dest, 1, gStringVar1, 40);
}
