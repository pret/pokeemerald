#include "global.h"
#include "pokenav.h"
#include "window.h"
#include "strings.h"
#include "text.h"
#include "bg.h"
#include "menu.h"
#include "decompress.h"
#include "international_string_util.h"

#define GFXTAG_ARROW 10
#define PALTAG_ARROW 20

struct PokenavListMenuWindow {
    u8 bg;
    u8 fillValue;
    u8 x;
    u8 y;
    u8 width;
    u8 fontId;
    u16 tileOffset;
    u16 windowId;
    u16 unkA;
    u16 numPrinted;
    u16 numToPrint;
};

struct PokenavListWindowState {
    // The index of the element at the top of the window.
    u16 windowTopIndex;
    u16 listLength;
    u16 entriesOffscreen;
    // The index of the cursor, relative to the top of the window.
    u16 selectedIndexOffset;
    u16 entriesOnscreen;
    u32 listItemSize;
    void * listPtr;
};

struct PokenavListSub
{
    struct PokenavListMenuWindow listWindow;
    u32 printStart;
    u32 printIndex;
    u32 itemSize;
    void * listPtr;
    s32 startBgY;
    s32 endBgY;
    u32 loopedTaskId;
    s32 moveDelta;
    u32 bgMoveType;
    PokenavListBufferItemFunc bufferItemFunc;
    void (*iconDrawFunc)(u16, u32, u32);
    struct Sprite *rightArrow;
    struct Sprite *upArrow;
    struct Sprite *downArrow;
    u8 itemTextBuffer[64];
};

struct PokenavList
{
    struct PokenavListSub sub;
    u8 tilemapBuffer[BG_SCREEN_SIZE];
    struct PokenavListWindowState windowState;
    s32 eraseIndex;
    u32 loopedTaskId;
};

static void InitPokenavListBg(struct PokenavList *);
static bool32 CopyPokenavListMenuTemplate(struct PokenavListSub *, const struct BgTemplate *, struct PokenavListTemplate *, s32);
static void InitPokenavListWindowState(struct PokenavListWindowState *, struct PokenavListTemplate *);
static void SpriteCB_UpArrow(struct Sprite *);
static void SpriteCB_DownArrow(struct Sprite *);
static void SpriteCB_RightArrow(struct Sprite *);
static void ToggleListArrows(struct PokenavListSub *, u32);
static void DestroyListArrows(struct PokenavListSub *);
static void CreateListArrowSprites(struct PokenavListWindowState *, struct PokenavListSub *);
static void LoadListArrowGfx(void);
static void PrintMatchCallFlavorText(struct PokenavListWindowState *, struct PokenavListSub *, u32);
static void PrintMatchCallFieldNames(struct PokenavListSub *, u32);
static void PrintMatchCallListTrainerName(struct PokenavListWindowState *, struct PokenavListSub *);
static void PrintCheckPageTrainerName(struct PokenavListWindowState *, struct PokenavListSub *);
static void EraseListEntry(struct PokenavListMenuWindow *, s32, s32);
static void CreateMoveListWindowTask(s32, struct PokenavListSub *);
static void PrintListItems(void *, u32, u32, u32, u32, struct PokenavListSub *);
static void InitListItems(struct PokenavListWindowState *, struct PokenavListSub *);
static void InitPokenavListWindow(struct PokenavListMenuWindow *);
static u32 LoopedTask_CreatePokenavList(s32);
static bool32 IsPrintListItemsTaskActive(void);
static u32 LoopedTask_PrintListItems(s32);
static u32 LoopedTask_MoveListWindow(s32);
static u32 LoopedTask_EraseListForCheckPage(s32);
static u32 LoopedTask_ReshowListFromCheckPage(s32);
static u32 LoopedTask_PrintCheckPageInfo(s32);

static const u16 sListArrow_Pal[] = INCBIN_U16("graphics/pokenav/list_arrows.gbapal");
static const u32 sListArrow_Gfx[] = INCBIN_U32("graphics/pokenav/list_arrows.4bpp.lz");

static EWRAM_DATA u32 sMoveWindowDownIndex = 0; // Read, but pointlessly

bool32 CreatePokenavList(const struct BgTemplate *bgTemplate, struct PokenavListTemplate *listTemplate, s32 tileOffset)
{
    struct PokenavList *list = AllocSubstruct(POKENAV_SUBSTRUCT_LIST, sizeof(struct PokenavList));
    if (list == NULL)
        return FALSE;

    InitPokenavListWindowState(&list->windowState, listTemplate);
    if (!CopyPokenavListMenuTemplate(&list->sub, bgTemplate, listTemplate, tileOffset))
        return FALSE;

    CreateLoopedTask(LoopedTask_CreatePokenavList, 6);
    return TRUE;
}

bool32 IsCreatePokenavListTaskActive(void)
{
    return FuncIsActiveLoopedTask(LoopedTask_CreatePokenavList);
}

void DestroyPokenavList(void)
{
    struct PokenavList *list = GetSubstructPtr(POKENAV_SUBSTRUCT_LIST);
    DestroyListArrows(&list->sub);
    RemoveWindow(list->sub.listWindow.windowId);
    FreePokenavSubstruct(POKENAV_SUBSTRUCT_LIST);
}

static u32 LoopedTask_CreatePokenavList(s32 state)
{
    struct PokenavList *list;

    if (IsDma3ManagerBusyWithBgCopy())
        return LT_PAUSE;

    list = GetSubstructPtr(POKENAV_SUBSTRUCT_LIST);

    switch (state)
    {
    case 0:
        InitPokenavListBg(list);
        return LT_INC_AND_PAUSE;
    case 1:
        InitPokenavListWindow(&list->sub.listWindow);
        return LT_INC_AND_PAUSE;
    case 2:
        InitListItems(&list->windowState, &list->sub);
        return LT_INC_AND_PAUSE;
    case 3:
        if (IsPrintListItemsTaskActive())
        {
            return LT_PAUSE;
        }
        else
        {
            LoadListArrowGfx();
            return LT_INC_AND_CONTINUE;
        }
    case 4:
        CreateListArrowSprites(&list->windowState, &list->sub);
        return LT_FINISH;
    default:
        return LT_FINISH;
    }
}

static void InitPokenavListBg(struct PokenavList *list)
{
    u16 tileNum = (list->sub.listWindow.fillValue << 12) | list->sub.listWindow.tileOffset;
    BgDmaFill(list->sub.listWindow.bg, PIXEL_FILL(1), list->sub.listWindow.tileOffset, 1);
    BgDmaFill(list->sub.listWindow.bg, PIXEL_FILL(4), list->sub.listWindow.tileOffset + 1, 1);
    SetBgTilemapBuffer(list->sub.listWindow.bg, list->tilemapBuffer);
    FillBgTilemapBufferRect_Palette0(list->sub.listWindow.bg, tileNum, 0, 0, 32, 32);
    ChangeBgY(list->sub.listWindow.bg, 0, BG_COORD_SET);
    ChangeBgX(list->sub.listWindow.bg, 0, BG_COORD_SET);
    ChangeBgY(list->sub.listWindow.bg, list->sub.listWindow.y << 11, BG_COORD_SUB);
    CopyBgTilemapBufferToVram(list->sub.listWindow.bg);
}

static void InitPokenavListWindow(struct PokenavListMenuWindow *listWindow)
{
    FillWindowPixelBuffer(listWindow->windowId, PIXEL_FILL(1));
    PutWindowTilemap(listWindow->windowId);
    CopyWindowToVram(listWindow->windowId, COPYWIN_MAP);
}

static void InitListItems(struct PokenavListWindowState *windowState, struct PokenavListSub *subPtr)
{
    s32 numToPrint = windowState->listLength - windowState->windowTopIndex;
    if (numToPrint > windowState->entriesOnscreen)
        numToPrint = windowState->entriesOnscreen;

    PrintListItems(windowState->listPtr, windowState->windowTopIndex, numToPrint, windowState->listItemSize, 0, subPtr);
}

static void PrintListItems(void * listPtr, u32 topIndex, u32 numItems, u32 itemSize, u32 printStart, struct PokenavListSub *list)
{
    if (numItems == 0)
        return;

    list->listPtr = listPtr + topIndex * itemSize;
    list->itemSize = itemSize;
    list->listWindow.numPrinted = 0;
    list->listWindow.numToPrint = numItems;
    list->printIndex = topIndex;
    list->printStart = printStart;
    CreateLoopedTask(LoopedTask_PrintListItems, 5);
}

static bool32 IsPrintListItemsTaskActive(void)
{
    return FuncIsActiveLoopedTask(LoopedTask_PrintListItems);
}

static u32 LoopedTask_PrintListItems(s32 state)
{
    u32 row;
    struct PokenavListSub *listSub = GetSubstructPtr(POKENAV_SUBSTRUCT_LIST);

    switch (state)
    {
    case 0:
        row = (listSub->listWindow.unkA + listSub->listWindow.numPrinted + listSub->printStart) & 0xF;
        listSub->bufferItemFunc(listSub->listPtr, listSub->itemTextBuffer);
        if (listSub->iconDrawFunc != NULL)
            listSub->iconDrawFunc(listSub->listWindow.windowId, listSub->printIndex, row);

        AddTextPrinterParameterized(listSub->listWindow.windowId, listSub->listWindow.fontId, listSub->itemTextBuffer, 8, (row << 4) + 1, TEXT_SKIP_DRAW, NULL);
        if (++listSub->listWindow.numPrinted >= listSub->listWindow.numToPrint)
        {
            // Finished printing items. If icons were being drawn, draw the
            // window tilemap and graphics. Otherwise just do the graphics
            if (listSub->iconDrawFunc != NULL)
                CopyWindowToVram(listSub->listWindow.windowId, COPYWIN_FULL);
            else
                CopyWindowToVram(listSub->listWindow.windowId, COPYWIN_GFX);
            return LT_INC_AND_PAUSE;
        }
        else
        {
            listSub->listPtr += listSub->itemSize;
            listSub->printIndex++;
            return LT_CONTINUE;
        }
    case 1:
        if (IsDma3ManagerBusyWithBgCopy())
            return LT_PAUSE;
        return LT_FINISH;
    }
    return LT_FINISH;
}

static bool32 ShouldShowUpArrow(void)
{
    struct PokenavList *list = GetSubstructPtr(POKENAV_SUBSTRUCT_LIST);

    return (list->windowState.windowTopIndex != 0);
}

static bool32 ShouldShowDownArrow(void)
{
    struct PokenavList *list = GetSubstructPtr(POKENAV_SUBSTRUCT_LIST);
    struct PokenavListWindowState *windowState = &list->windowState;

    return (windowState->windowTopIndex + windowState->entriesOnscreen < windowState->listLength);
}

static void MoveListWindow(s32 delta, bool32 printItems)
{
    struct PokenavList *list = GetSubstructPtr(POKENAV_SUBSTRUCT_LIST);
    struct PokenavListWindowState *windowState = &list->windowState;

    if (delta < 0)
    {
        if (windowState->windowTopIndex + delta < 0)
            delta = -1 * windowState->windowTopIndex;
        if (printItems)
            PrintListItems(windowState->listPtr, windowState->windowTopIndex + delta, delta * -1, windowState->listItemSize, delta, &list->sub);
    }
    else if (printItems)
    {
        s32 index = sMoveWindowDownIndex = windowState->windowTopIndex + windowState->entriesOnscreen;
        if (index + delta >= windowState->listLength)
            delta = windowState->listLength - index;

        PrintListItems(windowState->listPtr, index, delta, windowState->listItemSize, windowState->entriesOnscreen, &list->sub);
    }

    CreateMoveListWindowTask(delta, &list->sub);
    windowState->windowTopIndex += delta;
}

static void CreateMoveListWindowTask(s32 delta, struct PokenavListSub *list)
{
    list->startBgY = GetBgY(list->listWindow.bg);
    list->endBgY = list->startBgY + (delta << 12);
    if (delta > 0)
        list->bgMoveType = BG_COORD_ADD;
    else
        list->bgMoveType = BG_COORD_SUB;
    list->moveDelta = delta;
    list->loopedTaskId = CreateLoopedTask(LoopedTask_MoveListWindow, 6);
}

static u32 LoopedTask_MoveListWindow(s32 state)
{
    s32 oldY, newY;
    bool32 finished;
    struct PokenavList *list = GetSubstructPtr(POKENAV_SUBSTRUCT_LIST);
    struct PokenavListSub *subPtr = &list->sub;

    switch (state)
    {
    case 0:
        if (!IsPrintListItemsTaskActive())
            return LT_INC_AND_CONTINUE;
        return LT_PAUSE;
    case 1:
        finished = FALSE;
        oldY = GetBgY(subPtr->listWindow.bg);
        newY = ChangeBgY(subPtr->listWindow.bg, 0x1000, subPtr->bgMoveType);
        if (subPtr->bgMoveType == BG_COORD_SUB)
        {
            if ((oldY > subPtr->endBgY || oldY <= subPtr->startBgY) && newY <= subPtr->endBgY)
                finished = TRUE;
        }
        else // BG_COORD_ADD
        {
            if ((oldY < subPtr->endBgY || oldY >= subPtr->startBgY) && newY >= subPtr->endBgY)
                finished = TRUE;
        }

        if (finished)
        {
            subPtr->listWindow.unkA = (subPtr->listWindow.unkA + subPtr->moveDelta) & 0xF;
            ChangeBgY(subPtr->listWindow.bg, subPtr->endBgY, BG_COORD_SET);
            return LT_FINISH;
        }
        return LT_PAUSE;
    }
    return LT_FINISH;
}

bool32 PokenavList_IsMoveWindowTaskActive(void)
{
    struct PokenavList *list = GetSubstructPtr(POKENAV_SUBSTRUCT_LIST);
    return IsLoopedTaskActive(list->sub.loopedTaskId);
}

static struct PokenavListWindowState *GetPokenavListWindowState(void)
{
    struct PokenavList *list = GetSubstructPtr(POKENAV_SUBSTRUCT_LIST);
    return &list->windowState;
}

int PokenavList_MoveCursorUp(void)
{
    struct PokenavListWindowState *windowState = GetPokenavListWindowState();

    if (windowState->selectedIndexOffset != 0)
    {
        windowState->selectedIndexOffset--;
        return 1;
    }
    if (ShouldShowUpArrow())
    {
        MoveListWindow(-1, TRUE);
        return 2;
    }
    return 0;
}

int PokenavList_MoveCursorDown(void)
{
    struct PokenavListWindowState *windowState = GetPokenavListWindowState();

    if (windowState->windowTopIndex + windowState->selectedIndexOffset >= windowState->listLength - 1)
        return 0;
    if (windowState->selectedIndexOffset < windowState->entriesOnscreen - 1)
    {
        windowState->selectedIndexOffset++;
        return 1;
    }
    if (ShouldShowDownArrow())
    {
        MoveListWindow(1, TRUE);
        return 2;
    }
    return 0;
}

int PokenavList_PageUp(void)
{
    s32 scroll;
    struct PokenavListWindowState *windowState = GetPokenavListWindowState();

    if (ShouldShowUpArrow())
    {
        if (windowState->windowTopIndex >= windowState->entriesOnscreen)
            scroll = windowState->entriesOnscreen;
        else
            scroll = windowState->windowTopIndex;
        MoveListWindow(scroll * -1, TRUE);
        return 2;
    }
    else if (windowState->selectedIndexOffset != 0)
    {
        windowState->selectedIndexOffset = 0;
        return 1;
    }
    return 0;
}

int PokenavList_PageDown(void)
{
    struct PokenavListWindowState *windowState = GetPokenavListWindowState();

    if (ShouldShowDownArrow())
    {
        s32 windowBottomIndex = windowState->windowTopIndex + windowState->entriesOnscreen;
        s32 scroll = windowState->entriesOffscreen - windowState->windowTopIndex;

        if (windowBottomIndex <= windowState->entriesOffscreen)
            scroll = windowState->entriesOnscreen;
        MoveListWindow(scroll, TRUE);
        return 2;
    }
    else
    {
        s32 cursor, lastVisibleIndex;
        if (windowState->listLength >= windowState->entriesOnscreen)
        {
            cursor = windowState->selectedIndexOffset;
            lastVisibleIndex = windowState->entriesOnscreen;
        }
        else
        {
            cursor = windowState->selectedIndexOffset;
            lastVisibleIndex = windowState->listLength;
        }
        lastVisibleIndex -= 1;
        if (cursor >= lastVisibleIndex)
            return 0;

        windowState->selectedIndexOffset = lastVisibleIndex;
        return 1;
    }
}

u32 PokenavList_GetSelectedIndex(void)
{
    struct PokenavListWindowState *windowState = GetPokenavListWindowState();

    return windowState->windowTopIndex + windowState->selectedIndexOffset;
}

u32 PokenavList_GetTopIndex(void)
{
    struct PokenavListWindowState *windowState = GetPokenavListWindowState();

    return windowState->windowTopIndex;
}

void PokenavList_EraseListForCheckPage(void)
{
    struct PokenavList *list = GetSubstructPtr(POKENAV_SUBSTRUCT_LIST);
    list->eraseIndex = 0;
    list->loopedTaskId = CreateLoopedTask(LoopedTask_EraseListForCheckPage, 6);
}

void PrintCheckPageInfo(s16 delta)
{
    struct PokenavList *list = GetSubstructPtr(POKENAV_SUBSTRUCT_LIST);
    list->windowState.windowTopIndex += delta;
    list->eraseIndex = 0;
    list->loopedTaskId = CreateLoopedTask(LoopedTask_PrintCheckPageInfo, 6);
}

void PokenavList_ReshowListFromCheckPage(void)
{
    struct PokenavList *list = GetSubstructPtr(POKENAV_SUBSTRUCT_LIST);
    list->eraseIndex = 0;
    list->loopedTaskId = CreateLoopedTask(LoopedTask_ReshowListFromCheckPage, 6);
}

bool32 PokenavList_IsTaskActive(void)
{
    struct PokenavList *list = GetSubstructPtr(POKENAV_SUBSTRUCT_LIST);
    return IsLoopedTaskActive(list->loopedTaskId);
}

void PokenavList_DrawCurrentItemIcon(void)
{
    struct PokenavList *list = GetSubstructPtr(POKENAV_SUBSTRUCT_LIST);
    struct PokenavListWindowState *windowState = &list->windowState;
    list->sub.iconDrawFunc(list->sub.listWindow.windowId, windowState->windowTopIndex + windowState->selectedIndexOffset, (list->sub.listWindow.unkA + windowState->selectedIndexOffset) & 0xF);
    CopyWindowToVram(list->sub.listWindow.windowId, COPYWIN_MAP);
}

static u32 LoopedTask_EraseListForCheckPage(s32 state)
{
    struct PokenavList *list = GetSubstructPtr(POKENAV_SUBSTRUCT_LIST);

    switch (state)
    {
    case 0:
        ToggleListArrows(&list->sub, 1);
        // fall-through
    case 1:
        if (list->eraseIndex != list->windowState.selectedIndexOffset)
            EraseListEntry(&list->sub.listWindow, list->eraseIndex, 1);

        list->eraseIndex++;
        return LT_INC_AND_PAUSE;
    case 2:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            if (list->eraseIndex != list->windowState.entriesOnscreen)
                return LT_SET_STATE(1);
            if (list->windowState.selectedIndexOffset != 0)
                EraseListEntry(&list->sub.listWindow, list->eraseIndex, list->windowState.selectedIndexOffset);

            return LT_INC_AND_PAUSE;
        }
        return LT_PAUSE;
    case 3:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            if (list->windowState.selectedIndexOffset != 0)
            {
                MoveListWindow(list->windowState.selectedIndexOffset, FALSE);
                return LT_INC_AND_PAUSE;
            }
            return LT_FINISH;
        }
        return LT_PAUSE;
    case 4:
         if (PokenavList_IsMoveWindowTaskActive())
            return LT_PAUSE;

        list->windowState.selectedIndexOffset = 0;
        return LT_FINISH;
    }
    return LT_FINISH;
}

static u32 LoopedTask_PrintCheckPageInfo(s32 state)
{
    struct PokenavList *list = GetSubstructPtr(POKENAV_SUBSTRUCT_LIST);
    if (IsDma3ManagerBusyWithBgCopy())
        return LT_PAUSE;

    switch (state)
    {
    case 0:
        PrintCheckPageTrainerName(&list->windowState, &list->sub);
        break;
    case 1:
        PrintMatchCallFieldNames(&list->sub, 0);
        break;
    case 2:
        PrintMatchCallFlavorText(&list->windowState, &list->sub, CHECK_PAGE_STRATEGY);
        break;
    case 3:
        PrintMatchCallFieldNames(&list->sub, 1);
        break;
    case 4:
        PrintMatchCallFlavorText(&list->windowState, &list->sub, CHECK_PAGE_POKEMON);
        break;
    case 5:
        PrintMatchCallFieldNames(&list->sub, 2);
        break;
    case 6:
        PrintMatchCallFlavorText(&list->windowState, &list->sub, CHECK_PAGE_INTRO_1);
        break;
    case 7:
        PrintMatchCallFlavorText(&list->windowState, &list->sub, CHECK_PAGE_INTRO_2);
        break;
    default:
        return LT_FINISH;
    }
    return LT_INC_AND_PAUSE;
}

static u32 LoopedTask_ReshowListFromCheckPage(s32 state)
{
    struct PokenavList *list;
    struct PokenavListWindowState *windowState;
    struct PokenavListSub *subPtr;
    s32 r5, *ptr;

    if (IsDma3ManagerBusyWithBgCopy())
        return LT_PAUSE;

    list = GetSubstructPtr(POKENAV_SUBSTRUCT_LIST);
    windowState = &list->windowState;
    subPtr = &list->sub;

    switch (state)
    {
    case 0:
        // Rewrite the name of the trainer whose check page was just being viewed.
        // This is done to erase the red background it had.
        PrintMatchCallListTrainerName(windowState, subPtr);
        return LT_INC_AND_PAUSE;
    case 1:
        ptr = &list->eraseIndex;
        if (++(*ptr) < list->windowState.entriesOnscreen)
        {
            EraseListEntry(&subPtr->listWindow, *ptr, 1);
            return LT_PAUSE;
        }

        *ptr = 0;
        if (windowState->listLength <= windowState->entriesOnscreen)
        {
            if (windowState->windowTopIndex != 0)
            {
                s32 r4 = windowState->windowTopIndex;
                r5 = -r4;
                EraseListEntry(&subPtr->listWindow, r5, r4);
                windowState->selectedIndexOffset = r4;
                *ptr = r5;
                return LT_INC_AND_PAUSE;
            }
        }
        else
        {
            if (windowState->windowTopIndex + windowState->entriesOnscreen > windowState->listLength)
            {
                s32 r4 = windowState->windowTopIndex + windowState->entriesOnscreen - windowState->listLength;
                r5 = -r4;
                EraseListEntry(&subPtr->listWindow, r5, r4);
                windowState->selectedIndexOffset = r4;
                *ptr = r5;
                return LT_INC_AND_PAUSE;
            }
        }
        return LT_SET_STATE(4);
    case 2:
        MoveListWindow(list->eraseIndex, FALSE);
        return LT_INC_AND_PAUSE;
    case 3:
        if (!PokenavList_IsMoveWindowTaskActive())
        {
            list->eraseIndex = 0;
            return LT_INC_AND_CONTINUE;
        }
        return LT_PAUSE;
    case 4:
        PrintListItems(windowState->listPtr, windowState->windowTopIndex + list->eraseIndex, 1, windowState->listItemSize, list->eraseIndex, &list->sub);
        return LT_INC_AND_PAUSE;
    case 5:
        if (IsPrintListItemsTaskActive())
            return LT_PAUSE;
        if (++list->eraseIndex >= windowState->listLength || list->eraseIndex >= windowState->entriesOnscreen)
            return LT_INC_AND_CONTINUE;
        return LT_SET_STATE(4);
    case 6:
        ToggleListArrows(subPtr, 0);
        return LT_FINISH;
    }

    return LT_FINISH;
}

static void EraseListEntry(struct PokenavListMenuWindow *listWindow, s32 offset, s32 entries)
{
    u8 *tileData = (u8*)GetWindowAttribute(listWindow->windowId, WINDOW_TILE_DATA);
    u32 width = listWindow->width * 64;

    offset = (listWindow->unkA + offset) & 0xF;
    if (offset + entries <= 16)
    {
        CpuFastFill8(PIXEL_FILL(1), tileData + offset * width, entries * width);
        CopyWindowToVram(listWindow->windowId, COPYWIN_GFX);
    }
    else
    {
        u32 v3 = 16 - offset;
        u32 v4 = entries - v3;

        CpuFastFill8(PIXEL_FILL(1), tileData + offset * width, v3 * width);
        CpuFastFill8(PIXEL_FILL(1), tileData, v4 * width);
        CopyWindowToVram(listWindow->windowId, COPYWIN_GFX);
    }

    for (entries--; entries != -1; offset = (offset + 1) & 0xF, entries--)
        ClearRematchPokeballIcon(listWindow->windowId, offset);

    CopyWindowToVram(listWindow->windowId, COPYWIN_MAP);
}

// Pointless
static void SetListMarginTile(struct PokenavListMenuWindow *listWindow, bool32 draw)
{
    u16 var;
    u16 *tilemapBuffer = (u16*)GetBgTilemapBuffer(GetWindowAttribute(listWindow->windowId, WINDOW_BG));
    tilemapBuffer += (listWindow->unkA << 6) + listWindow->x - 1;

    if (draw)
        var = (listWindow->fillValue << 12) | (listWindow->tileOffset + 1);
    else
        var = (listWindow->fillValue << 12) | (listWindow->tileOffset);

    tilemapBuffer[0] = var;
    tilemapBuffer[0x20] = var;
}

// Print the trainer's name and title at the top of their check page
static void PrintCheckPageTrainerName(struct PokenavListWindowState *state, struct PokenavListSub *list)
{
    u8 colors[3] = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_DARK_GRAY, TEXT_COLOR_LIGHT_RED};

    list->bufferItemFunc(state->listPtr + state->listItemSize * state->windowTopIndex, list->itemTextBuffer);
    list->iconDrawFunc(list->listWindow.windowId, state->windowTopIndex, list->listWindow.unkA);
    FillWindowPixelRect(list->listWindow.windowId, PIXEL_FILL(4), 0, list->listWindow.unkA * 16, list->listWindow.width * 8, 16);
    AddTextPrinterParameterized3(list->listWindow.windowId, list->listWindow.fontId, 8, (list->listWindow.unkA * 16) + 1, colors, TEXT_SKIP_DRAW, list->itemTextBuffer);
    SetListMarginTile(&list->listWindow, TRUE);
    CopyWindowRectToVram(list->listWindow.windowId, COPYWIN_FULL, 0, list->listWindow.unkA * 2, list->listWindow.width, 2);
}

// Print the trainer's name and title for the list (to replace the check page name and title, which has a red background)
static void PrintMatchCallListTrainerName(struct PokenavListWindowState *state, struct PokenavListSub *list)
{
    list->bufferItemFunc(state->listPtr + state->listItemSize * state->windowTopIndex, list->itemTextBuffer);
    FillWindowPixelRect(list->listWindow.windowId, PIXEL_FILL(1), 0, list->listWindow.unkA * 16, list->listWindow.width * 8, 16);
    AddTextPrinterParameterized(list->listWindow.windowId, list->listWindow.fontId, list->itemTextBuffer, 8, list->listWindow.unkA * 16 + 1, TEXT_SKIP_DRAW, NULL);
    SetListMarginTile(&list->listWindow, FALSE);
    CopyWindowToVram(list->listWindow.windowId, COPYWIN_FULL);
}

static void PrintMatchCallFieldNames(struct PokenavListSub *list, u32 fieldId)
{
    const u8 *fieldNames[] = {
        gText_PokenavMatchCall_Strategy,
        gText_PokenavMatchCall_TrainerPokemon,
        gText_PokenavMatchCall_SelfIntroduction
    };
    u8 colors[3] = {TEXT_COLOR_WHITE, TEXT_COLOR_RED, TEXT_COLOR_LIGHT_RED};
    u32 top = (list->listWindow.unkA + 1 + (fieldId * 2)) & 0xF;

    FillWindowPixelRect(list->listWindow.windowId, PIXEL_FILL(1), 0, top << 4, list->listWindow.width, 16);
    AddTextPrinterParameterized3(list->listWindow.windowId, FONT_NARROW, 2, (top << 4) + 1, colors, TEXT_SKIP_DRAW, fieldNames[fieldId]);
    CopyWindowRectToVram(list->listWindow.windowId, COPYWIN_GFX, 0, top << 1, list->listWindow.width, 2);
}

static void PrintMatchCallFlavorText(struct PokenavListWindowState *windowState, struct PokenavListSub *list, u32 checkPageEntry)
{
    // lines 1, 3, and 5 are the field names printed by PrintMatchCallFieldNames
    static const u8 lineOffsets[CHECK_PAGE_ENTRY_COUNT] = {
        [CHECK_PAGE_STRATEGY] = 2,
        [CHECK_PAGE_POKEMON]  = 4,
        [CHECK_PAGE_INTRO_1]  = 6,
        [CHECK_PAGE_INTRO_2]  = 7
    };

    u32 r6 = (list->listWindow.unkA + lineOffsets[checkPageEntry]) & 0xF;
    const u8 *str = GetMatchCallFlavorText(windowState->windowTopIndex, checkPageEntry);

    if (str != NULL)
    {
        FillWindowTilesByRow(list->listWindow.windowId, 1, r6 * 2, list->listWindow.width - 1, 2);
        AddTextPrinterParameterized(list->listWindow.windowId, FONT_NARROW, str, 2, (r6 << 4) + 1, TEXT_SKIP_DRAW, NULL);
        CopyWindowRectToVram(list->listWindow.windowId, COPYWIN_GFX, 0, r6 * 2, list->listWindow.width, 2);
    }
}

static const struct CompressedSpriteSheet sListArrowSpriteSheets[] =
{
    {
        .data = sListArrow_Gfx,
        .size = 0xC0,
        .tag = GFXTAG_ARROW
    }
};

static const struct SpritePalette sListArrowPalettes[] =
{
    {
        .data = sListArrow_Pal,
        .tag = PALTAG_ARROW
    },
    {}
};

static const struct OamData sOamData_RightArrow =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(8x16),
    .x = 0,
    .size = SPRITE_SIZE(8x16),
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0
};

static const struct SpriteTemplate sSpriteTemplate_RightArrow =
{
    .tileTag = GFXTAG_ARROW,
    .paletteTag = PALTAG_ARROW,
    .oam = &sOamData_RightArrow,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_RightArrow
};

static const struct OamData sOamData_UpDownArrow =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(16x8),
    .x = 0,
    .size = SPRITE_SIZE(16x8),
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0
};

static const struct SpriteTemplate sSpriteTemplate_UpDownArrow =
{
    .tileTag = GFXTAG_ARROW,
    .paletteTag = PALTAG_ARROW,
    .oam = &sOamData_UpDownArrow,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static void LoadListArrowGfx(void)
{
    u32 i;
    const struct CompressedSpriteSheet *ptr;

    for (i = 0, ptr = sListArrowSpriteSheets; i < ARRAY_COUNT(sListArrowSpriteSheets); ptr++, i++)
        LoadCompressedSpriteSheet(ptr);

    Pokenav_AllocAndLoadPalettes(sListArrowPalettes);
}

static void CreateListArrowSprites(struct PokenavListWindowState *windowState, struct PokenavListSub *list)
{
    u32 spriteId;
    s16 x;

    spriteId = CreateSprite(&sSpriteTemplate_RightArrow, list->listWindow.x * 8 + 3, (list->listWindow.y + 1) * 8, 7);
    list->rightArrow = &gSprites[spriteId];

    x = list->listWindow.x * 8 + (list->listWindow.width - 1) * 4;
    spriteId = CreateSprite(&sSpriteTemplate_UpDownArrow, x, list->listWindow.y * 8 + windowState->entriesOnscreen * 16, 7);
    list->downArrow = &gSprites[spriteId];
    list->downArrow->oam.tileNum += 2;
    list->downArrow->callback = SpriteCB_DownArrow;

    spriteId = CreateSprite(&sSpriteTemplate_UpDownArrow, x, list->listWindow.y * 8, 7);
    list->upArrow = &gSprites[spriteId];
    list->upArrow->oam.tileNum += 4;
    list->upArrow->callback = SpriteCB_UpArrow;
}

static void DestroyListArrows(struct PokenavListSub *list)
{
    DestroySprite(list->rightArrow);
    DestroySprite(list->upArrow);
    DestroySprite(list->downArrow);
    FreeSpriteTilesByTag(GFXTAG_ARROW);
    FreeSpritePaletteByTag(PALTAG_ARROW);
}

static void ToggleListArrows(struct PokenavListSub *list, bool32 invisible)
{
    if (invisible)
    {
        list->rightArrow->callback = SpriteCallbackDummy;
        list->upArrow->callback = SpriteCallbackDummy;
        list->downArrow->callback = SpriteCallbackDummy;
    }
    else
    {
        list->rightArrow->callback = SpriteCB_RightArrow;
        list->upArrow->callback = SpriteCB_UpArrow;
        list->downArrow->callback = SpriteCB_DownArrow;
    }
    list->rightArrow->invisible = invisible;
    list->upArrow->invisible = invisible;
    list->downArrow->invisible = invisible;
}

static void SpriteCB_RightArrow(struct Sprite *sprite)
{
    struct PokenavList *list = GetSubstructPtr(POKENAV_SUBSTRUCT_LIST);
    sprite->y2 = list->windowState.selectedIndexOffset << 4;
}

#define sTimer data[0]
#define sOffset data[1]
#define sInvisible data[7]

static void SpriteCB_DownArrow(struct Sprite *sprite)
{
    if (!sprite->sInvisible && ShouldShowDownArrow())
        sprite->invisible = FALSE;
    else
        sprite->invisible = TRUE;

    if (++sprite->sTimer > 3)
    {
        s16 offset;

        sprite->sTimer = 0;
        offset = (sprite->sOffset + 1) & 7;
        sprite->sOffset = offset;
        sprite->y2 = offset;
    }
}

static void SpriteCB_UpArrow(struct Sprite *sprite)
{
    if (!sprite->sInvisible && ShouldShowUpArrow())
        sprite->invisible = FALSE;
    else
        sprite->invisible = TRUE;

    if (++sprite->sTimer > 3)
    {
        s16 offset;

        sprite->sTimer = 0;
        offset = (sprite->sOffset + 1) & 7;
        sprite->sOffset = offset;
        sprite->y2 = -1 * offset;
    }
}

void PokenavList_ToggleVerticalArrows(bool32 invisible)
{
    struct PokenavList *list = GetSubstructPtr(POKENAV_SUBSTRUCT_LIST);
    list->sub.upArrow->sInvisible = invisible;
    list->sub.downArrow->sInvisible = invisible;
}

#undef sTimer
#undef sOffset
#undef sInvisible

static void InitPokenavListWindowState(struct PokenavListWindowState *dst, struct PokenavListTemplate *template)
{
    dst->listPtr = template->list;
    dst->windowTopIndex = template->startIndex;
    dst->listLength = template->count;
    dst->listItemSize = template->itemSize;
    dst->entriesOnscreen = template->maxShowed;
    if (dst->entriesOnscreen >= dst->listLength)
    {
        dst->windowTopIndex = 0;
        dst->entriesOffscreen = 0;
        dst->selectedIndexOffset = template->startIndex;
    }
    else
    {
        dst->entriesOffscreen = dst->listLength - dst->entriesOnscreen;
        if (dst->windowTopIndex + dst->entriesOnscreen > dst->listLength)
        {
            dst->selectedIndexOffset = dst->windowTopIndex + dst->entriesOnscreen - dst->listLength;
            dst->windowTopIndex = template->startIndex - dst->selectedIndexOffset;
        }
        else
        {
            dst->selectedIndexOffset = 0;
        }
    }
}

static bool32 CopyPokenavListMenuTemplate(struct PokenavListSub *dest, const struct BgTemplate *bgTemplate, struct PokenavListTemplate *template, s32 tileOffset)
{
    struct WindowTemplate window;

    dest->listWindow.bg = bgTemplate->bg;
    dest->listWindow.tileOffset = tileOffset;
    dest->bufferItemFunc = template->bufferItemFunc;
    dest->iconDrawFunc = template->iconDrawFunc;
    dest->listWindow.fillValue = template->fillValue;
    dest->listWindow.x = template->item_X;
    dest->listWindow.y = template->listTop;
    dest->listWindow.width = template->windowWidth;
    dest->listWindow.fontId = template->fontId;

    window.bg = bgTemplate->bg;
    window.tilemapLeft = template->item_X;
    window.tilemapTop = 0;
    window.width = template->windowWidth;
    window.height = 32;
    window.paletteNum = template->fillValue;
    window.baseBlock = tileOffset + 2;

    dest->listWindow.windowId = AddWindow(&window);
    if (dest->listWindow.windowId == WINDOW_NONE)
        return FALSE;

    dest->listWindow.unkA = 0;
    dest->rightArrow = NULL;
    dest->upArrow = NULL;
    dest->downArrow = NULL;
    return 1;
}
