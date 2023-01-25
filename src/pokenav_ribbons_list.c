#include "global.h"
#include "pokenav.h"
#include "bg.h"
#include "menu.h"
#include "palette.h"
#include "window.h"
#include "sound.h"
#include "string_util.h"
#include "international_string_util.h"
#include "constants/songs.h"

enum
{
    RIBBONS_MON_LIST_FUNC_NONE,
    RIBBONS_MON_LIST_FUNC_MOVE_UP,
    RIBBONS_MON_LIST_FUNC_MOVE_DOWN,
    RIBBONS_MON_LIST_FUNC_PAGE_UP,
    RIBBONS_MON_LIST_FUNC_PAGE_DOWN,
    RIBBONS_MON_LIST_FUNC_EXIT,
    RIBBONS_MON_LIST_FUNC_OPEN_RIBBONS_SUMMARY
};


struct Pokenav_RibbonsMonList
{
    u32 (*callback)(struct Pokenav_RibbonsMonList *);
    u32 loopedTaskId;
    u16 winid;
    s32 boxId;
    s32 monId;
    u32 changeBgs;
    u32 saveMonList;
    struct PokenavMonList *monList;
};

struct Pokenav_RibbonsMonMenu
{
    bool32 (*callback)(void);
    u32 loopedTaskId;
    u16 winid;
    bool32 fromSummary;
    u8 buff[BG_SCREEN_SIZE];
};

static u32 HandleRibbonsMonListInput_WaitListInit(struct Pokenav_RibbonsMonList *);
static u32 HandleRibbonsMonListInput(struct Pokenav_RibbonsMonList *);
static u32 RibbonsMonMenu_ReturnToMainMenu(struct Pokenav_RibbonsMonList *);
static u32 RibbonsMonMenu_ToSummaryScreen(struct Pokenav_RibbonsMonList *);
static u32 BuildPartyMonRibbonList(s32);
static u32 InitBoxMonRibbonList(s32);
static u32 BuildBoxMonRibbonList(s32);
static u32 GetMonRibbonListLoopTaskFunc(s32);
static void InsertMonListItem(struct Pokenav_RibbonsMonList *, struct PokenavMonListItem *);
static u32 LoopedTask_OpenRibbonsMonList(s32);
static bool32 GetRibbonsMonCurrentLoopedTaskActive(void);
static u32 LoopedTask_RibbonsListMoveCursorUp(s32);
static u32 LoopedTask_RibbonsListMoveCursorDown(s32);
static u32 LoopedTask_RibbonsListMovePageUp(s32);
static u32 LoopedTask_RibbonsListMovePageDown(s32);
static u32 LoopedTask_RibbonsListReturnToMainMenu(s32);
static u32 LoopedTask_RibbonsListOpenSummary(s32);
static void DrawListIndexNumber(s32, s32, s32);
static void AddRibbonsMonListWindow(struct Pokenav_RibbonsMonMenu *);
static void UpdateIndexNumberDisplay(struct Pokenav_RibbonsMonMenu *);
static void CreateRibbonMonsList(void);
static void BufferRibbonMonInfoText(struct PokenavListItem *, u8 *);

static const LoopedTask sMonRibbonListLoopTaskFuncs[] =
{
    BuildPartyMonRibbonList,
    InitBoxMonRibbonList,
    BuildBoxMonRibbonList
};

static const u16 sMonRibbonListFramePal[] = INCBIN_U16("graphics/pokenav/ribbons/list_bg.gbapal");
static const u32 sMonRibbonListFrameTiles[] = INCBIN_U32("graphics/pokenav/ribbons/list_bg.4bpp.lz");
static const u32 sMonRibbonListFrameTilemap[] = INCBIN_U32("graphics/pokenav/ribbons/list_bg.bin.lz");
static const u16 sMonRibbonListUi_Pal[] = INCBIN_U16("graphics/pokenav/ribbons/list_ui.gbapal");

static const struct BgTemplate sMonRibbonListBgTemplates[] =
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

static const LoopedTask sRibbonsMonMenuLoopTaskFuncs[] =
{
    [RIBBONS_MON_LIST_FUNC_NONE]                 = NULL,
    [RIBBONS_MON_LIST_FUNC_MOVE_UP]              = LoopedTask_RibbonsListMoveCursorUp,
    [RIBBONS_MON_LIST_FUNC_MOVE_DOWN]            = LoopedTask_RibbonsListMoveCursorDown,
    [RIBBONS_MON_LIST_FUNC_PAGE_UP]              = LoopedTask_RibbonsListMovePageUp,
    [RIBBONS_MON_LIST_FUNC_PAGE_DOWN]            = LoopedTask_RibbonsListMovePageDown,
    [RIBBONS_MON_LIST_FUNC_EXIT]                 = LoopedTask_RibbonsListReturnToMainMenu,
    [RIBBONS_MON_LIST_FUNC_OPEN_RIBBONS_SUMMARY] = LoopedTask_RibbonsListOpenSummary
};

static const struct WindowTemplate sRibbonsMonListWindowTemplate =
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

bool32 PokenavCallback_Init_MonRibbonList(void)
{
    struct Pokenav_RibbonsMonList *list = AllocSubstruct(POKENAV_SUBSTRUCT_RIBBONS_MON_LIST, sizeof(struct Pokenav_RibbonsMonList));
    if (list == NULL)
        return FALSE;

    list->monList = AllocSubstruct(POKENAV_SUBSTRUCT_MON_LIST, sizeof(struct PokenavMonList));
    if (list->monList == NULL)
        return FALSE;

    list->callback = HandleRibbonsMonListInput_WaitListInit;
    list->loopedTaskId = CreateLoopedTask(GetMonRibbonListLoopTaskFunc, 1);
    list->changeBgs = 0;
    return TRUE;
}

bool32 PokenavCallback_Init_RibbonsMonListFromSummary(void)
{
    struct Pokenav_RibbonsMonList *list = AllocSubstruct(POKENAV_SUBSTRUCT_RIBBONS_MON_LIST, sizeof(struct Pokenav_RibbonsMonList));
    if (list == NULL)
        return FALSE;

    list->monList = GetSubstructPtr(POKENAV_SUBSTRUCT_MON_LIST);
    list->callback = HandleRibbonsMonListInput;
    list->changeBgs = 1;
    return TRUE;
}

u32 GetRibbonsMonListCallback(void)
{
    struct Pokenav_RibbonsMonList *list = GetSubstructPtr(POKENAV_SUBSTRUCT_RIBBONS_MON_LIST);
    return list->callback(list);
}

void FreeRibbonsMonList(void)
{
    struct Pokenav_RibbonsMonList *list = GetSubstructPtr(POKENAV_SUBSTRUCT_RIBBONS_MON_LIST);
    if (!list->saveMonList)
        FreePokenavSubstruct(POKENAV_SUBSTRUCT_MON_LIST);
    FreePokenavSubstruct(POKENAV_SUBSTRUCT_RIBBONS_MON_LIST);
}

static u32 HandleRibbonsMonListInput_WaitListInit(struct Pokenav_RibbonsMonList *list)
{
    if (!IsLoopedTaskActive(list->loopedTaskId))
        list->callback = HandleRibbonsMonListInput;
    return 0;
}

static u32 HandleRibbonsMonListInput(struct Pokenav_RibbonsMonList *list)
{
    if (JOY_REPEAT(DPAD_UP))
        return RIBBONS_MON_LIST_FUNC_MOVE_UP;
    if (JOY_REPEAT(DPAD_DOWN))
        return RIBBONS_MON_LIST_FUNC_MOVE_DOWN;
    if (JOY_NEW(DPAD_LEFT))
        return RIBBONS_MON_LIST_FUNC_PAGE_UP;
    if (JOY_NEW(DPAD_RIGHT))
        return RIBBONS_MON_LIST_FUNC_PAGE_DOWN;
    if (JOY_NEW(B_BUTTON))
    {
        list->saveMonList = 0;
        list->callback = RibbonsMonMenu_ReturnToMainMenu;
        return RIBBONS_MON_LIST_FUNC_EXIT;
    }
    if (JOY_NEW(A_BUTTON))
    {
        list->monList->currIndex = PokenavList_GetSelectedIndex();
        list->saveMonList = 1;
        list->callback = RibbonsMonMenu_ToSummaryScreen;
        return RIBBONS_MON_LIST_FUNC_OPEN_RIBBONS_SUMMARY;
    }
    return RIBBONS_MON_LIST_FUNC_NONE;
}

static u32 RibbonsMonMenu_ReturnToMainMenu(struct Pokenav_RibbonsMonList *list)
{
    return POKENAV_MAIN_MENU_CURSOR_ON_RIBBONS;
}

static u32 RibbonsMonMenu_ToSummaryScreen(struct Pokenav_RibbonsMonList *list)
{
    return POKENAV_RIBBONS_SUMMARY_SCREEN;
}

static u32 UpdateMonListBgs(void)
{
    struct Pokenav_RibbonsMonList *list = GetSubstructPtr(POKENAV_SUBSTRUCT_RIBBONS_MON_LIST);
    return list->changeBgs;
}

static struct PokenavMonListItem *GetMonRibbonMonListData(void)
{
    struct Pokenav_RibbonsMonList * list = GetSubstructPtr(POKENAV_SUBSTRUCT_RIBBONS_MON_LIST);
    return list->monList->monData;
}

static s32 GetRibbonsMonListCount(void)
{
    struct Pokenav_RibbonsMonList * list = GetSubstructPtr(POKENAV_SUBSTRUCT_RIBBONS_MON_LIST);
    return list->monList->listCount;
}

//unused
static s32 GetMonRibbonSelectedMonData(void)
{
    struct Pokenav_RibbonsMonList * list = GetSubstructPtr(POKENAV_SUBSTRUCT_RIBBONS_MON_LIST);
    s32 idx = PokenavList_GetSelectedIndex();
    return list->monList->monData[idx].data;
}

static s32 GetRibbonListMenuCurrIndex(void)
{
    struct Pokenav_RibbonsMonList * list = GetSubstructPtr(POKENAV_SUBSTRUCT_RIBBONS_MON_LIST);
    return list->monList->currIndex;
}

static u32 GetMonRibbonListLoopTaskFunc(s32 state)
{
    return sMonRibbonListLoopTaskFuncs[state](state);
}

static u32 BuildPartyMonRibbonList(s32 state)
{
    s32 i;
    struct PokenavMonListItem item;
    struct Pokenav_RibbonsMonList * list = GetSubstructPtr(POKENAV_SUBSTRUCT_RIBBONS_MON_LIST);

    list->monList->listCount = 0;
    list->monList->currIndex = 0;
    item.boxId = TOTAL_BOXES_COUNT;
    for (i = 0; i < PARTY_SIZE; i++)
    {
        struct Pokemon *pokemon = &gPlayerParty[i];
        if (!GetMonData(pokemon, MON_DATA_SANITY_HAS_SPECIES))
            return LT_INC_AND_CONTINUE;
        if (!GetMonData(pokemon, MON_DATA_SANITY_IS_EGG) && !GetMonData(pokemon, MON_DATA_SANITY_IS_BAD_EGG))
        {
            u32 ribbonCount = GetMonData(pokemon, MON_DATA_RIBBON_COUNT);
            if (ribbonCount != 0)
            {
                item.monId = i;
                item.data = ribbonCount;
                InsertMonListItem(list, &item);
            }
        }
    }

    return LT_INC_AND_CONTINUE;
}

static u32 InitBoxMonRibbonList(s32 state)
{
    struct Pokenav_RibbonsMonList *list = GetSubstructPtr(POKENAV_SUBSTRUCT_RIBBONS_MON_LIST);
    list->monId = 0;
    list->boxId = 0;
    return LT_INC_AND_CONTINUE;
}

static u32 BuildBoxMonRibbonList(s32 state)
{
    struct Pokenav_RibbonsMonList * list = GetSubstructPtr(POKENAV_SUBSTRUCT_RIBBONS_MON_LIST);
    s32 boxId = list->boxId;
    s32 monId = list->monId;
    s32 boxCount = 0;
    struct PokenavMonListItem item;

    while (boxId < TOTAL_BOXES_COUNT)
    {
        while (monId < IN_BOX_COUNT)
        {
            if (CheckBoxMonSanityAt(boxId, monId))
            {
                u32 ribbonCount = GetBoxMonDataAt(boxId, monId, MON_DATA_RIBBON_COUNT);
                if (ribbonCount != 0)
                {
                    item.boxId = boxId;
                    item.monId = monId;
                    item.data = ribbonCount;
                    InsertMonListItem(list, &item);
                }
            }
            boxCount++;
            monId++;
            if (boxCount > TOTAL_BOXES_COUNT)
            {
                list->boxId = boxId;
                list->monId = monId;
                return LT_CONTINUE;
            }
        }
        monId = 0;
        boxId++;
    }

    list->changeBgs = 1;
    return LT_FINISH;
}

static void InsertMonListItem(struct Pokenav_RibbonsMonList *list, struct PokenavMonListItem *item)
{
    u32 left = 0;
    u32 right = list->monList->listCount;
    u32 insertionIdx = left + (right - left) / 2;

    while (right != insertionIdx)
    {
        if (item->data > list->monList->monData[insertionIdx].data)
            right = insertionIdx;
        else
            left = insertionIdx + 1;
        insertionIdx = left + (right - left) / 2;
    }
    for (right = list->monList->listCount; right > insertionIdx; right--)
        list->monList->monData[right] = list->monList->monData[right - 1];
    list->monList->monData[insertionIdx] = *item;
    list->monList->listCount++;
}

// Unused
static bool32 PlayerHasRibbonsMon(void)
{
    s32 i, j;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        struct Pokemon *mon = &gPlayerParty[i];
        if (!GetMonData(mon, MON_DATA_SANITY_HAS_SPECIES))
            continue;
        if (GetMonData(mon, MON_DATA_SANITY_IS_EGG))
            continue;
        if (GetMonData(mon, MON_DATA_RIBBONS))
            return TRUE;
    }

    for (i = 0; i < TOTAL_BOXES_COUNT; i++)
    {
        for (j = 0; j < IN_BOX_COUNT; j++)
        {
            if (!CheckBoxMonSanityAt(i, j))
                continue;
            if (GetBoxMonDataAt(i, j, MON_DATA_RIBBONS))
                return TRUE;
        }
    }

    return FALSE;
}

bool32 OpenRibbonsMonList(void)
{
    struct Pokenav_RibbonsMonMenu *menu = AllocSubstruct(POKENAV_SUBSTRUCT_RIBBONS_MON_MENU, sizeof(struct Pokenav_RibbonsMonMenu));
    if (menu == NULL)
        return FALSE;
    menu->loopedTaskId = CreateLoopedTask(LoopedTask_OpenRibbonsMonList, 1);
    menu->callback = GetRibbonsMonCurrentLoopedTaskActive;
    menu->fromSummary = FALSE;
    return TRUE;
}

bool32 OpenRibbonsMonListFromRibbonsSummary(void)
{
    struct Pokenav_RibbonsMonMenu *menu = AllocSubstruct(POKENAV_SUBSTRUCT_RIBBONS_MON_MENU, sizeof(struct Pokenav_RibbonsMonMenu));
    if (menu == NULL)
        return FALSE;
    menu->loopedTaskId = CreateLoopedTask(LoopedTask_OpenRibbonsMonList, 1);
    menu->callback = GetRibbonsMonCurrentLoopedTaskActive;
    menu->fromSummary = TRUE;
    return TRUE;
}

void CreateRibbonsMonListLoopedTask(s32 idx)
{
    struct Pokenav_RibbonsMonMenu *menu = GetSubstructPtr(POKENAV_SUBSTRUCT_RIBBONS_MON_MENU);
    menu->loopedTaskId = CreateLoopedTask(sRibbonsMonMenuLoopTaskFuncs[idx], 1);
    menu->callback = GetRibbonsMonCurrentLoopedTaskActive;
}

bool32 IsRibbonsMonListLoopedTaskActive(void)
{
    struct Pokenav_RibbonsMonMenu *menu = GetSubstructPtr(POKENAV_SUBSTRUCT_RIBBONS_MON_MENU);
    return menu->callback();
}

bool32 GetRibbonsMonCurrentLoopedTaskActive(void)
{
    struct Pokenav_RibbonsMonMenu * menu = GetSubstructPtr(POKENAV_SUBSTRUCT_RIBBONS_MON_MENU);
    return IsLoopedTaskActive(menu->loopedTaskId);
}

void FreeRibbonsMonMenu(void)
{
    struct Pokenav_RibbonsMonMenu * menu = GetSubstructPtr(POKENAV_SUBSTRUCT_RIBBONS_MON_MENU);
    DestroyPokenavList();
    RemoveWindow(menu->winid);
    FreePokenavSubstruct(POKENAV_SUBSTRUCT_RIBBONS_MON_MENU);
}

static u32 LoopedTask_OpenRibbonsMonList(s32 state)
{
    struct Pokenav_RibbonsMonMenu *menu = GetSubstructPtr(POKENAV_SUBSTRUCT_RIBBONS_MON_MENU);
    switch (state)
    {
    case 0:
        InitBgTemplates(sMonRibbonListBgTemplates, ARRAY_COUNT(sMonRibbonListBgTemplates));
        DecompressAndCopyTileDataToVram(1, sMonRibbonListFrameTiles, 0, 0, 0);
        SetBgTilemapBuffer(1, menu->buff);
        CopyToBgTilemapBuffer(1, sMonRibbonListFrameTilemap, 0, 0);
        CopyPaletteIntoBufferUnfaded(sMonRibbonListFramePal, BG_PLTT_ID(1), PLTT_SIZE_4BPP);
        CopyBgTilemapBufferToVram(1);
        return LT_INC_AND_PAUSE;
    case 1:
        if (FreeTempTileDataBuffersIfPossible())
            return LT_PAUSE;
        if (!UpdateMonListBgs())
            return LT_PAUSE;
        ChangeBgX(1, 0, BG_COORD_SET);
        ChangeBgY(1, 0, BG_COORD_SET);
        ShowBg(1);
        return LT_INC_AND_PAUSE;
    case 2:
        if (FreeTempTileDataBuffersIfPossible())
            return LT_PAUSE;
        CopyPaletteIntoBufferUnfaded(sMonRibbonListUi_Pal, BG_PLTT_ID(2), PLTT_SIZE_4BPP);
        CreateRibbonMonsList();
        return LT_INC_AND_PAUSE;
    case 3:
        if (IsCreatePokenavListTaskActive())
            return LT_PAUSE;
        AddRibbonsMonListWindow(menu);
        return LT_INC_AND_PAUSE;
    case 4:
        if (FreeTempTileDataBuffersIfPossible())
            return LT_PAUSE;
        ShowBg(2);
        HideBg(3);
        PrintHelpBarText(HELPBAR_RIBBONS_MON_LIST);
        PokenavFadeScreen(POKENAV_FADE_FROM_BLACK);
        if (!menu->fromSummary)
        {
            LoadLeftHeaderGfxForIndex(POKENAV_GFX_RIBBONS_MENU);
            ShowLeftHeaderGfx(POKENAV_GFX_RIBBONS_MENU, TRUE, FALSE);
        }
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

static u32 LoopedTask_RibbonsListMoveCursorUp(s32 state)
{
    struct Pokenav_RibbonsMonMenu *menu = GetSubstructPtr(POKENAV_SUBSTRUCT_RIBBONS_MON_MENU);
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
        UpdateIndexNumberDisplay(menu);
        return LT_INC_AND_PAUSE;
    case 3:
        if (IsDma3ManagerBusyWithBgCopy())
            return LT_PAUSE;
        break;
    }
    return LT_FINISH;
}

static u32 LoopedTask_RibbonsListMoveCursorDown(s32 state)
{
    struct Pokenav_RibbonsMonMenu *menu = GetSubstructPtr(POKENAV_SUBSTRUCT_RIBBONS_MON_MENU);
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
        UpdateIndexNumberDisplay(menu);
        return LT_INC_AND_PAUSE;
    case 3:
        if (IsDma3ManagerBusyWithBgCopy())
            return LT_PAUSE;
        break;
    }
    return LT_FINISH;
}

static u32 LoopedTask_RibbonsListMovePageUp(s32 state)
{
    struct Pokenav_RibbonsMonMenu *menu = GetSubstructPtr(POKENAV_SUBSTRUCT_RIBBONS_MON_MENU);
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
        UpdateIndexNumberDisplay(menu);
        return LT_INC_AND_PAUSE;
    case 3:
        if (IsDma3ManagerBusyWithBgCopy())
            return LT_PAUSE;
        break;
    }
    return LT_FINISH;
}

static u32 LoopedTask_RibbonsListMovePageDown(s32 state)
{
    struct Pokenav_RibbonsMonMenu *menu = GetSubstructPtr(POKENAV_SUBSTRUCT_RIBBONS_MON_MENU);
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
        UpdateIndexNumberDisplay(menu);
        return LT_INC_AND_PAUSE;
    case 3:
        if (IsDma3ManagerBusyWithBgCopy())
            return LT_PAUSE;
        break;
    }
    return LT_FINISH;
}

static u32 LoopedTask_RibbonsListReturnToMainMenu(s32 state)
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

static u32 LoopedTask_RibbonsListOpenSummary(s32 state)
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

static void AddRibbonsMonListWindow(struct Pokenav_RibbonsMonMenu *menu)
{
    s32 listCount;
    menu->winid = AddWindow(&sRibbonsMonListWindowTemplate);
    PutWindowTilemap(menu->winid);
    listCount = GetRibbonsMonListCount();
    DrawListIndexNumber(menu->winid, 0, listCount);
    CopyWindowToVram(menu->winid, COPYWIN_MAP);
    UpdateIndexNumberDisplay(menu);
}

static void UpdateIndexNumberDisplay(struct Pokenav_RibbonsMonMenu *menu)
{
    s32 listIndex = PokenavList_GetSelectedIndex();
    s32 listCount = GetRibbonsMonListCount();
    DrawListIndexNumber(menu->winid, listIndex + 1, listCount);
    CopyWindowToVram(menu->winid, COPYWIN_GFX);
}

static void DrawListIndexNumber(s32 windowId, s32 index, s32 max)
{
    u8 strbuf[16];
    u32 x;

    u8 * ptr = strbuf;
    ptr = ConvertIntToDecimalStringN(ptr, index, STR_CONV_MODE_RIGHT_ALIGN, 3);
    *ptr++ = CHAR_SLASH;
    ConvertIntToDecimalStringN(ptr, max, STR_CONV_MODE_RIGHT_ALIGN, 3);
    x = GetStringCenterAlignXOffset(FONT_NORMAL, strbuf, 56);
    AddTextPrinterParameterized(windowId, FONT_NORMAL, strbuf, x, 1, TEXT_SKIP_DRAW, NULL);
}

static void CreateRibbonMonsList(void)
{
    struct PokenavListTemplate template;
    template.list = (struct PokenavListItem *)GetMonRibbonMonListData();
    template.count = GetRibbonsMonListCount();
    template.itemSize = sizeof(struct PokenavListItem);
    template.startIndex = GetRibbonListMenuCurrIndex();
    template.item_X = 13;
    template.windowWidth = 17;
    template.listTop = 1;
    template.maxShowed = 8;
    template.fillValue = 2;
    template.fontId = FONT_NORMAL;
    template.bufferItemFunc = BufferRibbonMonInfoText;
    template.iconDrawFunc = NULL;
    CreatePokenavList(&sMonRibbonListBgTemplates[1], &template, 0);
}

// Buffers the "Nickname gender/level" text for the ribbon mon list
static void BufferRibbonMonInfoText(struct PokenavListItem * listItem, u8 * dest)
{
    u8 gender;
    u8 level;
    u8 * s;
    const u8 * genderStr;
    struct PokenavMonListItem * item = (struct PokenavMonListItem *)listItem;

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
    dest = GetStringClearToWidth(dest, FONT_NORMAL, gStringVar1, 54);
    ConvertIntToDecimalStringN(dest, item->data, STR_CONV_MODE_RIGHT_ALIGN, 2);
}
