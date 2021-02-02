#include "global.h"
#include "pokenav.h"
#include "bg.h"
#include "menu.h"
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


struct PokenavSub9
{
    u32 (*callback)(struct PokenavSub9*);
    u32 loopedTaskId;
    u16 winid;
    s32 boxId;
    s32 monId;
    u32 changeBgs;
    u32 saveMonList;
    struct PokenavSub18 *monList;
};

struct PokenavSub10
{
    bool32 (*callback)(void);
    u32 ltid;
    u16 winid;
    bool32 fromSummary;
    u8 buff[BG_SCREEN_SIZE];
};

static u32 HandleRibbonsMonListInput_WaitListInit(struct PokenavSub9 *structPtr);
static u32 HandleRibbonsMonListInput(struct PokenavSub9 *structPtr);
static u32 RibbonsMonMenu_ReturnToMainMenu(struct PokenavSub9 *structPtr);
static u32 sub_81CFB10(struct PokenavSub9 *structPtr);
static u32 BuildPartyMonRibbonList(s32 state);
static u32 InitBoxMonRibbonList(s32 state);
static u32 BuildBoxMonRibbonList(s32 state);
static u32 GetMonRibbonListLoopTaskFunc(s32 state);
static void sub_81CFCEC(struct PokenavSub9 *structPtr, struct PokenavMonList *item);
static u32 LoopedTask_OpenRibbonsMonList(s32 state);
static bool32 GetRibbonsMonCurrentLoopedTaskActive(void);
static u32 LoopedTask_RibbonsListMoveCursorUp(s32 state);
static u32 LoopedTask_RibbonsListMoveCursorDown(s32 state);
static u32 LoopedTask_RibbonsListMovePageUp(s32 state);
static u32 LoopedTask_RibbonsListMovePageDown(s32 state);
static u32 LoopedTask_RibbonsListReturnToMainMenu(s32 state);
static u32 LoopedTask_RibbonsListOpenSummary(s32 state);
static void sub_81D02B0(s32 windowId, s32 val1, s32 val2);
static void AddRibbonsMonListWindow(struct PokenavSub10 *ptr);
static void sub_81D0288(struct PokenavSub10 *ptr);
static void InitMonRibbonPokenavListMenuTemplate(void);
static void BufferRibbonMonInfoText(struct PokenavMonList *, u8 *);

static const LoopedTask sMonRibbonListLoopTaskFuncs[] =
{
    BuildPartyMonRibbonList,
    InitBoxMonRibbonList,
    BuildBoxMonRibbonList
};

static const u16 sMonRibbonListFramePal[] = INCBIN_U16("graphics/pokenav/ui_ribbons.gbapal");
static const u32 sMonRibbonListFrameTiles[] = INCBIN_U32("graphics/pokenav/ui_ribbons.4bpp.lz");
static const u32 sMonRibbonListFrameTilemap[] = INCBIN_U32("graphics/pokenav/ui_ribbons.bin.lz");
static const u16 gUnknown_08623790[] = INCBIN_U16("graphics/pokenav/8623790.gbapal");

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

static const u8 sText_MaleSymbol[] = _("{COLOR_HIGHLIGHT_SHADOW}{LIGHT_RED}{WHITE}{GREEN}♂{COLOR_HIGHLIGHT_SHADOW}{DARK_GREY}{WHITE}{LIGHT_GREY}");
static const u8 sText_FemaleSymbol[] = _("{COLOR_HIGHLIGHT_SHADOW}{LIGHT_GREEN}{WHITE}{BLUE}♀{COLOR_HIGHLIGHT_SHADOW}{DARK_GREY}{WHITE}{LIGHT_GREY}");
static const u8 sText_NoGenderSymbol[] = _("{UNK_SPACER}");

bool32 PokenavCallback_Init_MonRibbonList(void)
{
    struct PokenavSub9 *structPtr = AllocSubstruct(POKENAV_SUBSTRUCT_RIBBONS_MON_LIST, sizeof(struct PokenavSub9));
    if (structPtr == NULL)
        return FALSE;

    structPtr->monList = AllocSubstruct(POKENAV_SUBSTRUCT_MON_LIST, sizeof(struct PokenavSub18));
    if (structPtr->monList == NULL)
        return FALSE;

    structPtr->callback = HandleRibbonsMonListInput_WaitListInit;
    structPtr->loopedTaskId = CreateLoopedTask(GetMonRibbonListLoopTaskFunc, 1);
    structPtr->changeBgs = 0;
    return TRUE;
}

bool32 PokenavCallback_Init_RibbonsMonListFromSummary(void)
{
    struct PokenavSub9 *structPtr = AllocSubstruct(POKENAV_SUBSTRUCT_RIBBONS_MON_LIST, sizeof(struct PokenavSub9));
    if (structPtr == NULL)
        return FALSE;

    structPtr->monList = GetSubstructPtr(POKENAV_SUBSTRUCT_MON_LIST);
    structPtr->callback = HandleRibbonsMonListInput;
    structPtr->changeBgs = 1;
    return TRUE;
}

u32 GetRibbonsMonListCallback(void)
{
    struct PokenavSub9 *structPtr = GetSubstructPtr(POKENAV_SUBSTRUCT_RIBBONS_MON_LIST);
    return structPtr->callback(structPtr);
}

void FreeRibbonsMonList1(void)
{
    struct PokenavSub9 *structPtr = GetSubstructPtr(POKENAV_SUBSTRUCT_RIBBONS_MON_LIST);
    if (!structPtr->saveMonList)
        FreePokenavSubstruct(POKENAV_SUBSTRUCT_MON_LIST);
    FreePokenavSubstruct(POKENAV_SUBSTRUCT_RIBBONS_MON_LIST);
}

static u32 HandleRibbonsMonListInput_WaitListInit(struct PokenavSub9 *structPtr)
{
    if (!IsLoopedTaskActive(structPtr->loopedTaskId))
        structPtr->callback = HandleRibbonsMonListInput;
    return 0;
}

static u32 HandleRibbonsMonListInput(struct PokenavSub9 *structPtr)
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
        structPtr->saveMonList = 0;
        structPtr->callback = RibbonsMonMenu_ReturnToMainMenu;
        return RIBBONS_MON_LIST_FUNC_EXIT;
    }
    if (JOY_NEW(A_BUTTON))
    {
        structPtr->monList->currIndex = GetSelectedPokenavListIndex();
        structPtr->saveMonList = 1;
        structPtr->callback = sub_81CFB10;
        return RIBBONS_MON_LIST_FUNC_OPEN_RIBBONS_SUMMARY;
    }
    return RIBBONS_MON_LIST_FUNC_NONE;
}

static u32 RibbonsMonMenu_ReturnToMainMenu(struct PokenavSub9 *structPtr)
{
    return POKENAV_MAIN_MENU_CURSOR_ON_RIBBONS;
}

static u32 sub_81CFB10(struct PokenavSub9 *structPtr)
{
    return POKENAV_RIBBONS_SUMMARY_SCREEN;
}

static u32 UpdateMonListBgs(void)
{
    struct PokenavSub9 *structPtr = GetSubstructPtr(POKENAV_SUBSTRUCT_RIBBONS_MON_LIST);
    return structPtr->changeBgs;
}

static struct PokenavMonList *GetMonRibbonMonListData(void)
{
    struct PokenavSub9 * ptr = GetSubstructPtr(POKENAV_SUBSTRUCT_RIBBONS_MON_LIST);
    return ptr->monList->monData;
}

static s32 GetRibbonsMonListCount(void)
{
    struct PokenavSub9 * ptr = GetSubstructPtr(POKENAV_SUBSTRUCT_RIBBONS_MON_LIST);
    return ptr->monList->listCount;
}

//unused
static s32 GetMonRibbonSelectedMonData(void)
{
    struct PokenavSub9 * ptr = GetSubstructPtr(POKENAV_SUBSTRUCT_RIBBONS_MON_LIST);
    s32 idx = GetSelectedPokenavListIndex();
    return ptr->monList->monData[idx].data;
}

static s32 GetRibbonListMenuCurrIndex(void)
{
    struct PokenavSub9 * ptr = GetSubstructPtr(POKENAV_SUBSTRUCT_RIBBONS_MON_LIST);
    return ptr->monList->currIndex;
}

static u32 GetMonRibbonListLoopTaskFunc(s32 state)
{
    return sMonRibbonListLoopTaskFuncs[state](state);
}

static u32 BuildPartyMonRibbonList(s32 state)
{
    s32 i;
    struct PokenavMonList item;
    struct PokenavSub9 * ptr = GetSubstructPtr(POKENAV_SUBSTRUCT_RIBBONS_MON_LIST);

    ptr->monList->listCount = 0;
    ptr->monList->currIndex = 0;
    item.boxId = TOTAL_BOXES_COUNT;
    for (i = 0; i < PARTY_SIZE; i++)
    {
        struct Pokemon * pokemon = &gPlayerParty[i];
        if (!GetMonData(pokemon, MON_DATA_SANITY_HAS_SPECIES))
            return LT_INC_AND_CONTINUE;
        if (!GetMonData(pokemon, MON_DATA_SANITY_IS_EGG) && !GetMonData(pokemon, MON_DATA_SANITY_IS_BAD_EGG))
        {
            u32 ribbonCount = GetMonData(pokemon, MON_DATA_RIBBON_COUNT);
            if (ribbonCount != 0)
            {
                item.monId = i;
                item.data = ribbonCount;
                sub_81CFCEC(ptr, &item);
            }
        }
    }

    return LT_INC_AND_CONTINUE;
}

static u32 InitBoxMonRibbonList(s32 state)
{
    struct PokenavSub9 *ptr = GetSubstructPtr(POKENAV_SUBSTRUCT_RIBBONS_MON_LIST);
    ptr->monId = 0;
    ptr->boxId = 0;
    return LT_INC_AND_CONTINUE;
}

static u32 BuildBoxMonRibbonList(s32 state)
{
    struct PokenavSub9 * ptr = GetSubstructPtr(POKENAV_SUBSTRUCT_RIBBONS_MON_LIST);
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
                u32 ribbonCount = GetBoxMonDataAt(boxId, monId, MON_DATA_RIBBON_COUNT);
                if (ribbonCount != 0)
                {
                    item.boxId = boxId;
                    item.monId = monId;
                    item.data = ribbonCount;
                    sub_81CFCEC(ptr, &item);
                }
            }
            boxCount++;
            monId++;
            if (boxCount > TOTAL_BOXES_COUNT)
            {
                ptr->boxId = boxId;
                ptr->monId = monId;
                return LT_CONTINUE;
            }
        }
        monId = 0;
        boxId++;
    }

    ptr->changeBgs = 1;
    return LT_FINISH;
}

static void sub_81CFCEC(struct PokenavSub9 *structPtr, struct PokenavMonList *item)
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

//unused
static bool32 Unused_PlayerHasRibbonsMon(void)
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
    struct PokenavSub10 *ptr = AllocSubstruct(POKENAV_SUBSTRUCT_RIBBONS_MON_MENU, sizeof(struct PokenavSub10));
    if (ptr == NULL)
        return FALSE;
    ptr->ltid = CreateLoopedTask(LoopedTask_OpenRibbonsMonList, 1);
    ptr->callback = GetRibbonsMonCurrentLoopedTaskActive;
    ptr->fromSummary = FALSE;
    return TRUE;
}

bool32 OpenRibbonsMonListFromRibbonsSummary(void)
{
    struct PokenavSub10 *monMenu = AllocSubstruct(POKENAV_SUBSTRUCT_RIBBONS_MON_MENU, sizeof(struct PokenavSub10));
    if (monMenu == NULL)
        return FALSE;
    monMenu->ltid = CreateLoopedTask(LoopedTask_OpenRibbonsMonList, 1);
    monMenu->callback = GetRibbonsMonCurrentLoopedTaskActive;
    monMenu->fromSummary = TRUE;
    return TRUE;
}

void CreateRibbonsMonListLoopedTask(s32 idx)
{
    struct PokenavSub10 *monMenu = GetSubstructPtr(POKENAV_SUBSTRUCT_RIBBONS_MON_MENU);
    monMenu->ltid = CreateLoopedTask(sRibbonsMonMenuLoopTaskFuncs[idx], 1);
    monMenu->callback = GetRibbonsMonCurrentLoopedTaskActive;
}

bool32 IsRibbonsMonListLoopedTaskActive(void)
{
    struct PokenavSub10 *monMenu = GetSubstructPtr(POKENAV_SUBSTRUCT_RIBBONS_MON_MENU);
    return monMenu->callback();
}

bool32 GetRibbonsMonCurrentLoopedTaskActive(void)
{
    struct PokenavSub10 * ptr = GetSubstructPtr(POKENAV_SUBSTRUCT_RIBBONS_MON_MENU);
    return IsLoopedTaskActive(ptr->ltid);
}

void FreeRibbonsMonList2(void)
{
    struct PokenavSub10 * ptr = GetSubstructPtr(POKENAV_SUBSTRUCT_RIBBONS_MON_MENU);
    sub_81C8234();
    RemoveWindow(ptr->winid);
    FreePokenavSubstruct(POKENAV_SUBSTRUCT_RIBBONS_MON_MENU);
}

static u32 LoopedTask_OpenRibbonsMonList(s32 state)
{
    struct PokenavSub10 *monMenu = GetSubstructPtr(POKENAV_SUBSTRUCT_RIBBONS_MON_MENU);
    switch (state)
    {
    case 0:
        InitBgTemplates(sMonRibbonListBgTemplates, ARRAY_COUNT(sMonRibbonListBgTemplates));
        DecompressAndCopyTileDataToVram(1, sMonRibbonListFrameTiles, 0, 0, 0);
        SetBgTilemapBuffer(1, monMenu->buff);
        CopyToBgTilemapBuffer(1, sMonRibbonListFrameTilemap, 0, 0);
        CopyPaletteIntoBufferUnfaded(sMonRibbonListFramePal, 0x10, 0x20);
        CopyBgTilemapBufferToVram(1);
        return LT_INC_AND_PAUSE;
    case 1:
        if (FreeTempTileDataBuffersIfPossible())
            return LT_PAUSE;
        if (!UpdateMonListBgs())
            return LT_PAUSE;
        ChangeBgX(1, 0, 0);
        ChangeBgY(1, 0, 0);
        ShowBg(1);
        return LT_INC_AND_PAUSE;
    case 2:
        if (FreeTempTileDataBuffersIfPossible())
            return LT_PAUSE;
        CopyPaletteIntoBufferUnfaded(gUnknown_08623790, 0x20, 0x20);
        InitMonRibbonPokenavListMenuTemplate();
        return LT_INC_AND_PAUSE;
    case 3:
        if (sub_81C8224())
            return LT_PAUSE;
        AddRibbonsMonListWindow(monMenu);
        return LT_INC_AND_PAUSE;
    case 4:
        if (FreeTempTileDataBuffersIfPossible())
            return LT_PAUSE;
        ShowBg(2);
        HideBg(3);
        PrintHelpBarText(HELPBAR_RIBBONS_MON_LIST);
        PokenavFadeScreen(1);
        if (!monMenu->fromSummary)
        {
            LoadLeftHeaderGfxForIndex(POKENAV_GFX_RIBBONS_MENU);
            ShowLeftHeaderGfx(POKENAV_GFX_RIBBONS_MENU, 1, 0);
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
    struct PokenavSub10 *monMenu = GetSubstructPtr(POKENAV_SUBSTRUCT_RIBBONS_MON_MENU);
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
        sub_81D0288(monMenu);
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
    struct PokenavSub10 *monMenu = GetSubstructPtr(POKENAV_SUBSTRUCT_RIBBONS_MON_MENU);
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
        sub_81D0288(monMenu);
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
    struct PokenavSub10 *monMenu = GetSubstructPtr(POKENAV_SUBSTRUCT_RIBBONS_MON_MENU);
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
        sub_81D0288(monMenu);
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
    struct PokenavSub10 *monMenu = GetSubstructPtr(POKENAV_SUBSTRUCT_RIBBONS_MON_MENU);
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
        sub_81D0288(monMenu);
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

static u32 LoopedTask_RibbonsListOpenSummary(s32 state)
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

static void AddRibbonsMonListWindow(struct PokenavSub10 *monMenu)
{
    s32 r2;
    monMenu->winid = AddWindow(&sRibbonsMonListWindowTemplate);
    PutWindowTilemap(monMenu->winid);
    r2 = GetRibbonsMonListCount();
    sub_81D02B0(monMenu->winid, 0, r2);
    CopyWindowToVram(monMenu->winid, 1);
    sub_81D0288(monMenu);
}

static void sub_81D0288(struct PokenavSub10 *monMenu)
{
    s32 r4 = GetSelectedPokenavListIndex();
    s32 r2 = GetRibbonsMonListCount();
    sub_81D02B0(monMenu->winid, r4 + 1, r2);
    CopyWindowToVram(monMenu->winid, 2);
}

static void sub_81D02B0(s32 windowId, s32 val1, s32 val2)
{
    u8 strbuf[16];
    u32 x;

    u8 * ptr = strbuf;
    ptr = ConvertIntToDecimalStringN(ptr, val1, STR_CONV_MODE_RIGHT_ALIGN, 3);
    *ptr++ = CHAR_SLASH;
    ConvertIntToDecimalStringN(ptr, val2, STR_CONV_MODE_RIGHT_ALIGN, 3);
    x = GetStringCenterAlignXOffset(1, strbuf, 56);
    AddTextPrinterParameterized(windowId, 1, strbuf, x, 1, 0xFF, NULL);
}

static void InitMonRibbonPokenavListMenuTemplate(void)
{
    struct PokenavListTemplate template;
    template.list.monList = GetMonRibbonMonListData();
    template.count = GetRibbonsMonListCount();
    template.unk8 = 4;
    template.unk6 = GetRibbonListMenuCurrIndex();
    template.item_X = 13;
    template.windowWidth = 17;
    template.listTop = 1;
    template.maxShowed = 8;
    template.fillValue = 2;
    template.fontId = 1;
    template.listFunc.printMonFunc = BufferRibbonMonInfoText;
    template.unk14 = NULL;
    sub_81C81D4(&sMonRibbonListBgTemplates[1], &template, 0);
}

// Buffers the "Nickname gender/level" text for the ribbon mon list
static void BufferRibbonMonInfoText(struct PokenavMonList * item0, u8 * dest)
{
    u8 gender;
    u8 level;
    u8 * s;
    const u8 * genderStr;
    struct PokenavMonList * item = item0;

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
    dest = sub_81DB494(dest, 1, gStringVar1, 54);
    ConvertIntToDecimalStringN(dest, item->data, STR_CONV_MODE_RIGHT_ALIGN, 2);
}
