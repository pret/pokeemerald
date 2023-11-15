#include "global.h"
#include "pokenav.h"
#include "bg.h"
#include "menu.h"
#include "palette.h"
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

struct Pokenav_SearchResults
{
    u32 (*callback)(struct Pokenav_SearchResults *);
    u32 loopedTaskId;
    u8 fill1[4];
    s32 boxId;
    s32 monId;
    u32 conditionDataId;
    bool32 returnFromGraph;
    bool32 saveResultsList;
    struct PokenavMonList *monList;
};

struct Pokenav_SearchResultsGfx
{
    bool32 (*callback)(void);
    u32 loopedTaskId;
    u16 winid;
    bool32 fromGraph;
    u8 buff[BG_SCREEN_SIZE];
}; // size: 0x810

static u32 HandleConditionSearchInput_WaitSetup(struct Pokenav_SearchResults *);
static u32 HandleConditionSearchInput(struct Pokenav_SearchResults *);
static u32 OpenConditionGraphFromSearchList(struct Pokenav_SearchResults *);
static u32 ReturnToConditionSearchList(struct Pokenav_SearchResults *);
static u32 GetConditionSearchLoopedTask(s32);
static u32 BuildPartyMonSearchResults(s32);
static u32 InitBoxMonSearchResults(s32);
static u32 BuildBoxMonSearchResults(s32);
static u32 ConvertConditionsToListRanks(s32);
static u32 LoopedTask_MoveSearchListCursorUp(s32);
static u32 LoopedTask_MoveSearchListCursorDown(s32);
static u32 LoopedTask_MoveSearchListPageUp(s32);
static u32 LoopedTask_MoveSearchListPageDown(s32);
static u32 LoopedTask_ExitConditionSearchMenu(s32);
static u32 LoopedTask_SelectSearchResult(s32);
static void InsertMonListItem(struct Pokenav_SearchResults *, struct PokenavMonListItem *);
static bool32 GetSearchResultCurrentLoopedTaskActive(void);
static u32 LoopedTask_OpenConditionSearchResults(s32);
static void AddSearchResultListMenuWindow(struct Pokenav_SearchResultsGfx *);
static void PrintSearchResultListMenuItems(struct Pokenav_SearchResultsGfx *);
static void CreateSearchResultsList(void);
static void BufferSearchMonListItem(struct PokenavMonListItem *, u8 *);

static const u32 sSearchMonDataIds[] = {MON_DATA_COOL, MON_DATA_BEAUTY, MON_DATA_CUTE, MON_DATA_SMART, MON_DATA_TOUGH};

static const LoopedTask sConditionSearchLoopedTaskFuncs[] =
{
    BuildPartyMonSearchResults,
    InitBoxMonSearchResults,
    BuildBoxMonSearchResults,
    ConvertConditionsToListRanks
};

static const u16 sConditionSearchResultFramePal[] = INCBIN_U16("graphics/pokenav/condition/search_results.gbapal");
static const u32 sConditionSearchResultTiles[] = INCBIN_U32("graphics/pokenav/condition/search_results.4bpp.lz");
static const u32 sConditionSearchResultTilemap[] = INCBIN_U32("graphics/pokenav/condition/search_results.bin.lz");
static const u16 sListBg_Pal[] = INCBIN_U16("graphics/pokenav/condition/search_results_list.gbapal");

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

static const u8 sText_MaleSymbol[] = _("{COLOR_HIGHLIGHT_SHADOW}{LIGHT_RED}{WHITE}{GREEN}♂{COLOR_HIGHLIGHT_SHADOW}{DARK_GRAY}{WHITE}{LIGHT_GRAY}");
static const u8 sText_FemaleSymbol[] = _("{COLOR_HIGHLIGHT_SHADOW}{LIGHT_GREEN}{WHITE}{BLUE}♀{COLOR_HIGHLIGHT_SHADOW}{DARK_GRAY}{WHITE}{LIGHT_GRAY}");
static const u8 sText_NoGenderSymbol[] = _("{UNK_SPACER}");

bool32 PokenavCallback_Init_ConditionSearch(void)
{
    struct Pokenav_SearchResults *menu = AllocSubstruct(POKENAV_SUBSTRUCT_CONDITION_SEARCH_RESULTS, sizeof(struct Pokenav_SearchResults));
    if (menu == NULL)
        return FALSE;

    menu->monList = AllocSubstruct(POKENAV_SUBSTRUCT_MON_LIST, sizeof(struct PokenavMonList));
    if (menu->monList == NULL)
        return FALSE;

    menu->callback = HandleConditionSearchInput_WaitSetup;
    menu->loopedTaskId = CreateLoopedTask(GetConditionSearchLoopedTask, 1);
    menu->returnFromGraph = FALSE;
    menu->conditionDataId = sSearchMonDataIds[GetSelectedConditionSearch()];
    return TRUE;
}

// return to search results from condition graph
bool32 PokenavCallback_Init_ReturnToMonSearchList(void)
{
    struct Pokenav_SearchResults *menu = AllocSubstruct(POKENAV_SUBSTRUCT_CONDITION_SEARCH_RESULTS, sizeof(struct Pokenav_SearchResults));
    if (menu == NULL)
        return FALSE;

    menu->monList = GetSubstructPtr(POKENAV_SUBSTRUCT_MON_LIST);
    menu->callback = HandleConditionSearchInput;
    menu->returnFromGraph = TRUE;
    menu->conditionDataId = sSearchMonDataIds[GetSelectedConditionSearch()];
    return TRUE;
}

u32 GetConditionSearchResultsCallback(void)
{
    struct Pokenav_SearchResults *menu = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_SEARCH_RESULTS);
    return menu->callback(menu);
}

void FreeSearchResultSubstruct1(void)
{
    struct Pokenav_SearchResults *menu = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_SEARCH_RESULTS);
    if (!menu->saveResultsList)
        FreePokenavSubstruct(POKENAV_SUBSTRUCT_MON_LIST);
    FreePokenavSubstruct(POKENAV_SUBSTRUCT_CONDITION_SEARCH_RESULTS);
}

static bool32 HandleConditionSearchInput_WaitSetup(struct Pokenav_SearchResults *menu)
{
    if (!IsLoopedTaskActive(menu->loopedTaskId))
        menu->callback = HandleConditionSearchInput;
    return FALSE;
}

static u32 HandleConditionSearchInput(struct Pokenav_SearchResults *menu)
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
        // Exiting back to main search menu
        menu->saveResultsList = FALSE;
        menu->callback = ReturnToConditionSearchList;
        return CONDITION_SEARCH_FUNC_EXIT;
    }
    else if (JOY_NEW(A_BUTTON))
    {
        // Entering graph menu
        menu->monList->currIndex = PokenavList_GetSelectedIndex();
        menu->saveResultsList = TRUE;
        menu->callback = OpenConditionGraphFromSearchList;
        return CONDITION_SEARCH_FUNC_SELECT_MON;
    }
    else
        return CONDITION_SEARCH_FUNC_NONE;
}

static u32 ReturnToConditionSearchList(struct Pokenav_SearchResults *menu)
{
    return POKENAV_CONDITION_SEARCH_MENU;
}

static u32 OpenConditionGraphFromSearchList(struct Pokenav_SearchResults *menu)
{
    return POKENAV_CONDITION_GRAPH_SEARCH;
}

static u32 GetReturningFromGraph(void)
{
    struct Pokenav_SearchResults *menu = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_SEARCH_RESULTS);
    return menu->returnFromGraph;
}

static struct PokenavMonListItem * GetSearchResultsMonDataList(void)
{
    struct Pokenav_SearchResults * menu = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_SEARCH_RESULTS);
    return menu->monList->monData;
}

static u16 GetSearchResultsMonListCount(void)
{
    struct Pokenav_SearchResults * menu = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_SEARCH_RESULTS);
    return menu->monList->listCount;
}

// data below has been set by ConvertConditionsToListRanks
static s32 GetSearchResultsSelectedMonRank(void)
{
    struct Pokenav_SearchResults * menu = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_SEARCH_RESULTS);
    s32 i = PokenavList_GetSelectedIndex();
    return menu->monList->monData[i].data;
}

static u16 GetSearchResultsCurrentListIndex(void)
{
    struct Pokenav_SearchResults * menu = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_SEARCH_RESULTS);
    return menu->monList->currIndex;
}

static u32 GetConditionSearchLoopedTask(s32 state)
{
    return sConditionSearchLoopedTaskFuncs[state](state);
}

static u32 BuildPartyMonSearchResults(s32 state)
{
    s32 i;
    struct PokenavMonListItem item;
    struct Pokenav_SearchResults * menu = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_SEARCH_RESULTS);

    menu->monList->listCount = 0;
    menu->monList->currIndex = 0;
    item.boxId = TOTAL_BOXES_COUNT;
    for (i = 0; i < PARTY_SIZE; i++)
    {
        struct Pokemon *pokemon = &gPlayerParty[i];
        if (!GetMonData(pokemon, MON_DATA_SANITY_HAS_SPECIES))
            return LT_INC_AND_CONTINUE;
        if (!GetMonData(pokemon, MON_DATA_SANITY_IS_EGG))
        {
            item.monId = i;
            item.data = GetMonData(pokemon, menu->conditionDataId);
            InsertMonListItem(menu, &item);
        }
    }

    return LT_INC_AND_CONTINUE;
}

static u32 InitBoxMonSearchResults(s32 state)
{
    struct Pokenav_SearchResults * menu = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_SEARCH_RESULTS);
    menu->monId = 0;
    menu->boxId = 0;
    return LT_INC_AND_CONTINUE;
}

static u32 BuildBoxMonSearchResults(s32 state)
{
    struct Pokenav_SearchResults * menu = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_SEARCH_RESULTS);
    s32 boxId = menu->boxId;
    s32 monId = menu->monId;
    s32 boxCount = 0;
    struct PokenavMonListItem item;

    while (boxId < TOTAL_BOXES_COUNT)
    {
        while (monId < IN_BOX_COUNT)
        {
            if (CheckBoxMonSanityAt(boxId, monId))
            {
                item.boxId = boxId;
                item.monId = monId;
                item.data = GetBoxMonDataAt(boxId, monId, menu->conditionDataId);
                InsertMonListItem(menu, &item);
            }
            boxCount++;
            monId++;
            if (boxCount > TOTAL_BOXES_COUNT)
            {
                menu->boxId = boxId;
                menu->monId = monId;
                return LT_CONTINUE;
            }
        }
        monId = 0;
        boxId++;
    }

    return LT_INC_AND_CONTINUE;
}

// Data below is initially set by BuildPartyMonSearchResults / BuildBoxMonSearchResults, and
// is the Pokémon's condition value for the condition they are sorted by.
// The condition value in data is then overwritten with their ranking.
static u32 ConvertConditionsToListRanks(s32 state)
{
    struct Pokenav_SearchResults * menu = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_SEARCH_RESULTS);
    s32 listCount = menu->monList->listCount;
    s32 prevCondition = menu->monList->monData[0].data;
    s32 i;
    menu->monList->monData[0].data = 1;
    for (i = 1; i < listCount; i++)
    {
        if (menu->monList->monData[i].data == prevCondition)
        {
            // Same condition value as prev, share rank
            menu->monList->monData[i].data = menu->monList->monData[i - 1].data;
        }
        else
        {
            prevCondition = menu->monList->monData[i].data;
            menu->monList->monData[i].data = i + 1;
        }
    }
    menu->returnFromGraph = TRUE;
    return LT_FINISH;
}

static void InsertMonListItem(struct Pokenav_SearchResults *menu, struct PokenavMonListItem *item)
{
    u32 left = 0;
    u32 right = menu->monList->listCount;
    u32 insertionIdx = left + (right - left) / 2;

    while (right != insertionIdx)
    {
        if (item->data > menu->monList->monData[insertionIdx].data)
            right = insertionIdx;
        else
            left = insertionIdx + 1;
        insertionIdx = left + (right - left) / 2;
    }
    for (right = menu->monList->listCount; right > insertionIdx; right--)
        menu->monList->monData[right] = menu->monList->monData[right - 1];
    menu->monList->monData[insertionIdx] = *item;
    menu->monList->listCount++;
}

bool32 OpenConditionSearchResults(void)
{
    struct Pokenav_SearchResultsGfx *gfx = AllocSubstruct(POKENAV_SUBSTRUCT_CONDITION_SEARCH_RESULTS_GFX, sizeof(struct Pokenav_SearchResultsGfx));
    if (gfx == NULL)
        return FALSE;
    gfx->loopedTaskId = CreateLoopedTask(LoopedTask_OpenConditionSearchResults, 1);
    gfx->callback = GetSearchResultCurrentLoopedTaskActive;
    gfx->fromGraph = FALSE;
    return TRUE;
}

bool32 OpenConditionSearchListFromGraph(void)
{
    struct Pokenav_SearchResultsGfx *gfx = AllocSubstruct(POKENAV_SUBSTRUCT_CONDITION_SEARCH_RESULTS_GFX, sizeof(struct Pokenav_SearchResultsGfx));
    if (gfx == NULL)
        return FALSE;
    gfx->loopedTaskId = CreateLoopedTask(LoopedTask_OpenConditionSearchResults, 1);
    gfx->callback = GetSearchResultCurrentLoopedTaskActive;
    gfx->fromGraph = TRUE;
    return TRUE;
}

void CreateSearchResultsLoopedTask(s32 idx)
{
    struct Pokenav_SearchResultsGfx *gfx = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_SEARCH_RESULTS_GFX);
    gfx->loopedTaskId = CreateLoopedTask(sSearchResultLoopTaskFuncs[idx], 1);
    gfx->callback = GetSearchResultCurrentLoopedTaskActive;
}

bool32 IsSearchResultLoopedTaskActive(void)
{
    struct Pokenav_SearchResultsGfx *gfx = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_SEARCH_RESULTS_GFX);
    return gfx->callback();
}

bool32 GetSearchResultCurrentLoopedTaskActive(void)
{
    struct Pokenav_SearchResultsGfx *gfx = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_SEARCH_RESULTS_GFX);
    return IsLoopedTaskActive(gfx->loopedTaskId);
}

void FreeSearchResultSubstruct2(void)
{
    struct Pokenav_SearchResultsGfx *gfx = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_SEARCH_RESULTS_GFX);
    DestroyPokenavList();
    RemoveWindow(gfx->winid);
    FreePokenavSubstruct(POKENAV_SUBSTRUCT_CONDITION_SEARCH_RESULTS_GFX);
}

static u32 LoopedTask_OpenConditionSearchResults(s32 state)
{
    struct Pokenav_SearchResultsGfx *gfx = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_SEARCH_RESULTS_GFX);
    switch (state)
    {
    case 0:
        InitBgTemplates(sConditionSearchResultBgTemplates, ARRAY_COUNT(sConditionSearchResultBgTemplates));
        DecompressAndCopyTileDataToVram(1, sConditionSearchResultTiles, 0, 0, 0);
        SetBgTilemapBuffer(1, gfx->buff);
        CopyToBgTilemapBuffer(1, sConditionSearchResultTilemap, 0, 0);
        CopyBgTilemapBufferToVram(1);
        CopyPaletteIntoBufferUnfaded(sConditionSearchResultFramePal, BG_PLTT_ID(1), sizeof(sConditionSearchResultFramePal));
        CopyBgTilemapBufferToVram(1);
        return LT_INC_AND_PAUSE;
    case 1:
        if (FreeTempTileDataBuffersIfPossible())
            return LT_PAUSE;
        if (!GetReturningFromGraph())
            return LT_PAUSE;
        return LT_INC_AND_PAUSE;
    case 2:
        if (FreeTempTileDataBuffersIfPossible())
            return LT_PAUSE;
        CopyPaletteIntoBufferUnfaded(sListBg_Pal, BG_PLTT_ID(2), sizeof(sListBg_Pal));
        CreateSearchResultsList();
        return LT_INC_AND_PAUSE;
    case 3:
        if (IsCreatePokenavListTaskActive())
            return LT_PAUSE;
        AddSearchResultListMenuWindow(gfx);
        PrintHelpBarText(HELPBAR_CONDITION_MON_LIST);
        return LT_INC_AND_PAUSE;
    case 4:
        if (FreeTempTileDataBuffersIfPossible())
            return LT_PAUSE;
        ChangeBgX(1, 0, BG_COORD_SET);
        ChangeBgY(1, 0, BG_COORD_SET);
        ShowBg(1);
        ShowBg(2);
        HideBg(3);
        if (!gfx->fromGraph)
        {
            u8 searchGfxId = GetSelectedConditionSearch() + POKENAV_MENUITEM_CONDITION_SEARCH_COOL;
            LoadLeftHeaderGfxForIndex(searchGfxId);
            ShowLeftHeaderGfx(searchGfxId, TRUE, FALSE);
            ShowLeftHeaderGfx(POKENAV_GFX_CONDITION_MENU, TRUE, FALSE);
        }
        PokenavFadeScreen(POKENAV_FADE_FROM_BLACK);
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
    struct Pokenav_SearchResultsGfx *gfx = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_SEARCH_RESULTS_GFX);
    switch (state)
    {
    case 0:
        switch (PokenavList_MoveCursorUp())
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
        if (PokenavList_IsMoveWindowTaskActive())
            return LT_PAUSE;
        // fallthrough
    case 2:
        PrintSearchResultListMenuItems(gfx);
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
    struct Pokenav_SearchResultsGfx *gfx = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_SEARCH_RESULTS_GFX);
    switch (state)
    {
    case 0:
        switch (PokenavList_MoveCursorDown())
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
        if (PokenavList_IsMoveWindowTaskActive())
            return LT_PAUSE;
        // fallthrough
    case 2:
        PrintSearchResultListMenuItems(gfx);
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
    struct Pokenav_SearchResultsGfx *gfx = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_SEARCH_RESULTS_GFX);
    switch (state)
    {
    case 0:
        switch (PokenavList_PageUp())
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
        if (PokenavList_IsMoveWindowTaskActive())
            return LT_PAUSE;
        // fallthrough
    case 2:
        PrintSearchResultListMenuItems(gfx);
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
    struct Pokenav_SearchResultsGfx *gfx = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_SEARCH_RESULTS_GFX);
    switch (state)
    {
    case 0:
        switch (PokenavList_PageDown())
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
        if (PokenavList_IsMoveWindowTaskActive())
            return LT_PAUSE;
        // fallthrough
    case 2:
        PrintSearchResultListMenuItems(gfx);
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
        PokenavFadeScreen(POKENAV_FADE_TO_BLACK);
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
        PokenavFadeScreen(POKENAV_FADE_TO_BLACK);
        return LT_INC_AND_PAUSE;
    case 1:
        if (IsPaletteFadeActive())
            return LT_PAUSE;
        break;
    }
    return LT_FINISH;
}

static void AddSearchResultListMenuWindow(struct Pokenav_SearchResultsGfx *gfx)
{
    gfx->winid = AddWindow(&sSearchResultListMenuWindowTemplate);
    PutWindowTilemap(gfx->winid);
    CopyWindowToVram(gfx->winid, COPYWIN_MAP);
    PrintSearchResultListMenuItems(gfx);
}

static void PrintSearchResultListMenuItems(struct Pokenav_SearchResultsGfx *gfx)
{
    s32 rank = GetSearchResultsSelectedMonRank();
    DynamicPlaceholderTextUtil_Reset();
    DynamicPlaceholderTextUtil_SetPlaceholderPtr(0, gStringVar1);
    *gStringVar1 = EOS;
    DynamicPlaceholderTextUtil_ExpandPlaceholders(gStringVar2, gText_NumberIndex);
    AddTextPrinterParameterized(gfx->winid, FONT_NORMAL, gStringVar2, 4, 1, TEXT_SKIP_DRAW, NULL);
    ConvertIntToDecimalStringN(gStringVar1, rank, STR_CONV_MODE_RIGHT_ALIGN, 3);
    AddTextPrinterParameterized(gfx->winid, FONT_NORMAL, gStringVar1, 34, 1, TEXT_SKIP_DRAW, NULL);
    CopyWindowToVram(gfx->winid, COPYWIN_GFX);
}

static void CreateSearchResultsList(void)
{
    struct PokenavListTemplate template;

    template.list = (struct PokenavListItem *)GetSearchResultsMonDataList();
    template.count = GetSearchResultsMonListCount();
    template.itemSize = sizeof(struct PokenavListItem);
    template.startIndex = GetSearchResultsCurrentListIndex();
    template.item_X = 13;
    template.windowWidth = 17;
    template.listTop = 1;
    template.maxShowed = 8;
    template.fillValue = 2;
    template.fontId = FONT_NORMAL;
    template.bufferItemFunc = (PokenavListBufferItemFunc)BufferSearchMonListItem;
    template.iconDrawFunc = NULL;
    CreatePokenavList(&sConditionSearchResultBgTemplates[1], &template, 0);
}

static void BufferSearchMonListItem(struct PokenavMonListItem * item, u8 *dest)
{
    u8 gender;
    u8 level;
    u8 *s;
    const u8 *genderStr;

    // Mon is in party
    if (item->boxId == TOTAL_BOXES_COUNT)
    {
        struct Pokemon *mon = &gPlayerParty[item->monId];
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

    StringGet_Nickname(gStringVar3);
    dest = GetStringClearToWidth(dest, FONT_NORMAL, gStringVar3, 60);
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
    GetStringClearToWidth(dest, FONT_NORMAL, gStringVar1, 40);
}
