#include "global.h"
#include "pokenav.h"
#include "window.h"
#include "strings.h"
#include "text.h"
#include "bg.h"
#include "menu.h"
#include "decompress.h"

// TODO: This UI isnt just for match call, seems to be the general pokenav list UI

struct PokenavListMenuWindow {
    u8 bg;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    u8 unk4;
    u8 fontId;
    u16 unk6;
    u16 windowId;
    u16 unkA;
    u16 unkC;
    u16 unkE;
};

struct MatchCallWindowState {
    // The index of the element at the top of the window.
    u16 windowTopIndex;
    u16 listLength;
    u16 unk4;
    // The index of the cursor, relative to the top of the window.
    u16 selectedIndexOffset;
    u16 visibleEntries;
    u16 unkA;
    u32 unkC;
    void * unk10;
};

struct PokenavSub17Substruct
{
    struct PokenavListMenuWindow listWindow;
    u32 unk10;
    u32 unk14;
    u32 unk18;
    void * unk1C;
    s32 unk20;
    s32 unk24;
    u32 loopedTaskId;
    s32 unk2C;
    u32 unk30;
    void (*unk34)(struct PokenavMatchCallEntries *, u8*);
    void (*unk38)(u16, u32, u32);
    struct Sprite *rightArrow;
    struct Sprite *upArrow;
    struct Sprite *downArrow;
    u8 unkTextBuffer[0x40];
};

// Generally at index 0x11 (17)
struct PokenavSub17
{
    struct PokenavSub17Substruct list;
    u8 tilemapBuffer[0x800];
    struct MatchCallWindowState unk888;
    s32 unk89C;
    u32 loopedTaskId;
};

extern void sub_81DB620(u32 windowId, u32 a1, u32 a2, u32 a3, u32 a4);

void sub_81C82E4(struct PokenavSub17 *matchCall);
bool32 CopyPokenavListMenuTemplate(struct PokenavSub17Substruct *a0, const struct BgTemplate *a1, struct PokenavListTemplate *a2, s32 a3);
void InitMatchCallWindowState(struct MatchCallWindowState *a0, struct PokenavListTemplate *a1);
void SpriteCB_MatchCallUpArrow(struct Sprite *sprite);
void SpriteCB_MatchCallDownArrow(struct Sprite *sprite);
void SpriteCB_MatchCallRightArrow(struct Sprite *sprite);
void ToggleMatchCallArrows(struct PokenavSub17Substruct *a0, u32 a1);
void DestroyMatchCallListArrows(struct PokenavSub17Substruct *a0);
void CreateMatchCallArrowSprites(struct MatchCallWindowState *a0, struct PokenavSub17Substruct *a1);
void sub_81C8ED0(void);
static void PrintMatchCallFlavorText(struct MatchCallWindowState *a0, struct PokenavSub17Substruct *a1, u32 a2);
void PrintMatchCallFieldNames(struct PokenavSub17Substruct *a0, u32 a1);
void sub_81C8D4C(struct MatchCallWindowState *a0, struct PokenavSub17Substruct *a1);
void sub_81C8CB4(struct MatchCallWindowState *a0, struct PokenavSub17Substruct *a1);
void sub_81C8B70(struct PokenavListMenuWindow *a0, s32 a1, s32 a2);
void sub_81C8568(s32 a0, struct PokenavSub17Substruct *a1);
void sub_81C83AC(void * a0, u32 a1, u32 a2, u32 a3, u32 a4, struct PokenavSub17Substruct *a5);
void sub_81C837C(struct MatchCallWindowState *a0, struct PokenavSub17Substruct *a1);
void sub_81C835C(struct PokenavListMenuWindow *a0);
u32 LoopedTask_sub_81C8254(s32 state);
bool32 sub_81C83E0(void);
u32 LoopedTask_sub_81C83F0(s32 state);
u32 LoopedTask_sub_81C85A0(s32 state);
u32 LoopedTask_sub_81C8870(s32 state);
u32 LoopedTask_sub_81C8A28(s32 state);
u32 LoopedTask_PrintCheckPageInfo(s32 state);

static const u16 sMatchcallArrowPaletteData[] = INCBIN_U16("graphics/pokenav/arrows_matchcall.gbapal");
static const u32 sMatchcallArrowSpriteSheetData[] = INCBIN_U32("graphics/pokenav/arrows_matchcall.4bpp.lz");

EWRAM_DATA u32 gUnknown_0203CF44 = 0;

bool32 sub_81C81D4(const struct BgTemplate *arg0, struct PokenavListTemplate *arg1, s32 arg2)
{
    struct PokenavSub17 *structPtr = AllocSubstruct(POKENAV_SUBSTRUCT_MATCH_CALL_LIST, sizeof(struct PokenavSub17));
    if (structPtr == NULL)
        return FALSE;

    InitMatchCallWindowState(&structPtr->unk888, arg1);
    if (!CopyPokenavListMenuTemplate(&structPtr->list, arg0, arg1, arg2))
        return FALSE;

    CreateLoopedTask(LoopedTask_sub_81C8254, 6);
    return TRUE;
}

bool32 sub_81C8224(void)
{
    return FuncIsActiveLoopedTask(LoopedTask_sub_81C8254);
}

void sub_81C8234(void)
{
    struct PokenavSub17 *structPtr;

    structPtr = GetSubstructPtr(POKENAV_SUBSTRUCT_MATCH_CALL_LIST);
    DestroyMatchCallListArrows(&structPtr->list);
    RemoveWindow(structPtr->list.listWindow.windowId);
    FreePokenavSubstruct(POKENAV_SUBSTRUCT_MATCH_CALL_LIST);
}

u32 LoopedTask_sub_81C8254(s32 state)
{
    struct PokenavSub17 *structPtr;

    if (IsDma3ManagerBusyWithBgCopy())
        return LT_PAUSE;

    structPtr = GetSubstructPtr(POKENAV_SUBSTRUCT_MATCH_CALL_LIST);

    switch (state)
    {
    case 0:
        sub_81C82E4(structPtr);
        return LT_INC_AND_PAUSE;
    case 1:
        sub_81C835C(&structPtr->list.listWindow);
        return LT_INC_AND_PAUSE;
    case 2:
        sub_81C837C(&structPtr->unk888, &structPtr->list);
        return LT_INC_AND_PAUSE;
    case 3:
        if (sub_81C83E0())
        {
            return LT_PAUSE;
        }
        else
        {
            sub_81C8ED0();
            return LT_INC_AND_CONTINUE;
        }
    case 4:
        CreateMatchCallArrowSprites(&structPtr->unk888, &structPtr->list);
        return LT_FINISH;
    default:
        return LT_FINISH;
    }
}

void sub_81C82E4(struct PokenavSub17 *matchCall)
{
    u16 tileNum = (matchCall->list.listWindow.unk1 << 12) | matchCall->list.listWindow.unk6;
    sub_8199DF0(matchCall->list.listWindow.bg, PIXEL_FILL(1), matchCall->list.listWindow.unk6, 1);
    sub_8199DF0(matchCall->list.listWindow.bg, PIXEL_FILL(4), matchCall->list.listWindow.unk6 + 1, 1);
    SetBgTilemapBuffer(matchCall->list.listWindow.bg, matchCall->tilemapBuffer);
    FillBgTilemapBufferRect_Palette0(matchCall->list.listWindow.bg, tileNum, 0, 0, 32, 32);
    ChangeBgY(matchCall->list.listWindow.bg, 0, 0);
    ChangeBgX(matchCall->list.listWindow.bg, 0, 0);
    ChangeBgY(matchCall->list.listWindow.bg, matchCall->list.listWindow.unk3 << 11, 2);
    CopyBgTilemapBufferToVram(matchCall->list.listWindow.bg);
}

void sub_81C835C(struct PokenavListMenuWindow *listWindow)
{
    FillWindowPixelBuffer(listWindow->windowId, PIXEL_FILL(1));
    PutWindowTilemap(listWindow->windowId);
    CopyWindowToVram(listWindow->windowId, 1);
}

void sub_81C837C(struct MatchCallWindowState *state, struct PokenavSub17Substruct *a1)
{
    s32 arg2 = state->listLength - state->windowTopIndex;
    if (arg2 > state->visibleEntries)
        arg2 = state->visibleEntries;

    sub_81C83AC(state->unk10, state->windowTopIndex, arg2, state->unkC, 0, a1);
}

void sub_81C83AC(void * a0, u32 a1, u32 a2, u32 a3, u32 a4, struct PokenavSub17Substruct *list)
{
    if (a2 == 0)
        return;

    list->unk1C = a0 + a1 * a3;
    list->unk18 = a3;
    list->listWindow.unkC = 0;
    list->listWindow.unkE = a2;
    list->unk14 = a1;
    list->unk10 = a4;
    CreateLoopedTask(LoopedTask_sub_81C83F0, 5);
}

bool32 sub_81C83E0(void)
{
    return FuncIsActiveLoopedTask(LoopedTask_sub_81C83F0);
}

u32 LoopedTask_sub_81C83F0(s32 state)
{
    u32 v1;
    struct PokenavSub17Substruct *structPtr = GetSubstructPtr(POKENAV_SUBSTRUCT_MATCH_CALL_LIST);

    switch (state)
    {
    case 0:
        v1 = (structPtr->listWindow.unkA + structPtr->listWindow.unkC + structPtr->unk10) & 0xF;
        structPtr->unk34(structPtr->unk1C, structPtr->unkTextBuffer);
        if (structPtr->unk38 != NULL)
            structPtr->unk38(structPtr->listWindow.windowId, structPtr->unk14, v1);

        AddTextPrinterParameterized(structPtr->listWindow.windowId, structPtr->listWindow.fontId, structPtr->unkTextBuffer, 8, (v1 << 4) + 1, 255, NULL);
        if (++structPtr->listWindow.unkC >= structPtr->listWindow.unkE)
        {
            if (structPtr->unk38 != NULL)
                CopyWindowToVram(structPtr->listWindow.windowId, 3);
            else
                CopyWindowToVram(structPtr->listWindow.windowId, 2);
            return LT_INC_AND_PAUSE;
        }
        else
        {
            structPtr->unk1C += structPtr->unk18;
            structPtr->unk14++;
            return LT_CONTINUE;
        }
    case 1:
        if (IsDma3ManagerBusyWithBgCopy())
            return LT_PAUSE;
        return LT_FINISH;
    }
    return LT_FINISH;
}

bool32 ShouldShowUpArrow(void)
{
    struct PokenavSub17 *structPtr = GetSubstructPtr(POKENAV_SUBSTRUCT_MATCH_CALL_LIST);

    return (structPtr->unk888.windowTopIndex != 0);
}

bool32 ShouldShowDownArrow(void)
{
    struct PokenavSub17 *structPtr = GetSubstructPtr(POKENAV_SUBSTRUCT_MATCH_CALL_LIST);
    struct MatchCallWindowState *subPtr = &structPtr->unk888;

    return (subPtr->windowTopIndex + subPtr->visibleEntries < subPtr->listLength);
}

void MatchCall_MoveWindow(s32 a0, bool32 a1)
{
    struct PokenavSub17 *structPtr = GetSubstructPtr(POKENAV_SUBSTRUCT_MATCH_CALL_LIST);
    struct MatchCallWindowState *subPtr = &structPtr->unk888;

    if (a0 < 0)
    {
        if (subPtr->windowTopIndex + a0 < 0)
            a0 = -1 * subPtr->windowTopIndex;
        if (a1)
            sub_81C83AC(subPtr->unk10, subPtr->windowTopIndex + a0, a0 * -1, subPtr->unkC, a0, &structPtr->list);
    }
    else if (a1)
    {
        s32 temp = gUnknown_0203CF44 = subPtr->windowTopIndex + subPtr->visibleEntries;
        if (temp + a0 >= subPtr->listLength)
            a0 = subPtr->listLength - temp;

        sub_81C83AC(subPtr->unk10, gUnknown_0203CF44, a0, subPtr->unkC, subPtr->visibleEntries, &structPtr->list);
    }

    sub_81C8568(a0, &structPtr->list);
    subPtr->windowTopIndex += a0;
}

void sub_81C8568(s32 a0, struct PokenavSub17Substruct *list)
{
    list->unk20 = GetBgY(list->listWindow.bg);
    list->unk24 = list->unk20 + (a0 << 12);
    if (a0 > 0)
        list->unk30 = 1;
    else
        list->unk30 = 2;
    list->unk2C = a0;
    list->loopedTaskId = CreateLoopedTask(LoopedTask_sub_81C85A0, 6);
}

u32 LoopedTask_sub_81C85A0(s32 state)
{
    s32 y, v1;
    bool32 flag;
    struct PokenavSub17 *structPtr = GetSubstructPtr(POKENAV_SUBSTRUCT_MATCH_CALL_LIST);
    struct PokenavSub17Substruct *subPtr = &structPtr->list;

    switch (state)
    {
    case 0:
        if (!sub_81C83E0())
            return LT_INC_AND_CONTINUE;
        return LT_PAUSE;
    case 1:
        flag = FALSE;
        y = GetBgY(subPtr->listWindow.bg);
        v1 = ChangeBgY(subPtr->listWindow.bg, 0x1000, subPtr->unk30);
        if (subPtr->unk30 == 2)
        {
            if ((y > subPtr->unk24 || y <= subPtr->unk20) && v1 <= subPtr->unk24)
                flag = TRUE;
        }
        else
        {
            if ((y < subPtr->unk24 || y >= subPtr->unk20) && v1 >= subPtr->unk24)
                flag = TRUE;
        }

        if (flag)
        {
            subPtr->listWindow.unkA = (subPtr->listWindow.unkA + subPtr->unk2C) & 0xF;
            ChangeBgY(subPtr->listWindow.bg, subPtr->unk24, 0);
            return LT_FINISH;
        }
        return LT_PAUSE;
    }
    return LT_FINISH;
}

bool32 IsMonListLoopedTaskActive(void)
{
    struct PokenavSub17 *structPtr = GetSubstructPtr(POKENAV_SUBSTRUCT_MATCH_CALL_LIST);
    return IsLoopedTaskActive(structPtr->list.loopedTaskId);
}

struct MatchCallWindowState *GetMatchCallWindowStruct(void)
{
    struct PokenavSub17 *structPtr = GetSubstructPtr(POKENAV_SUBSTRUCT_MATCH_CALL_LIST);
    return &structPtr->unk888;
}

int MatchCall_MoveCursorUp(void)
{
    struct MatchCallWindowState *structPtr = GetMatchCallWindowStruct();

    if (structPtr->selectedIndexOffset != 0)
    {
        structPtr->selectedIndexOffset--;
        return 1;
    }
    if (ShouldShowUpArrow())
    {
        MatchCall_MoveWindow(-1, TRUE);
        return 2;
    }
    return 0;
}

int MatchCall_MoveCursorDown(void)
{
    struct MatchCallWindowState *structPtr = GetMatchCallWindowStruct();

    if (structPtr->windowTopIndex + structPtr->selectedIndexOffset >= structPtr->listLength - 1)
        return 0;
    if (structPtr->selectedIndexOffset < structPtr->visibleEntries - 1)
    {
        structPtr->selectedIndexOffset++;
        return 1;
    }
    if (ShouldShowDownArrow())
    {
        MatchCall_MoveWindow(1, TRUE);
        return 2;
    }
    return 0;
}

int MatchCall_PageUp(void)
{
    s32 scroll;
    struct MatchCallWindowState *structPtr = GetMatchCallWindowStruct();

    if (ShouldShowUpArrow())
    {
        if (structPtr->windowTopIndex >= structPtr->visibleEntries)
            scroll = structPtr->visibleEntries;
        else
            scroll = structPtr->windowTopIndex;
        MatchCall_MoveWindow(scroll * -1, TRUE);
        return 2;
    }
    else if (structPtr->selectedIndexOffset != 0)
    {
        structPtr->selectedIndexOffset = 0;
        return 1;
    }
    return 0;
}

int MatchCall_PageDown(void)
{
    struct MatchCallWindowState *structPtr = GetMatchCallWindowStruct();

    if (ShouldShowDownArrow())
    {
        s32 windowBottomIndex = structPtr->windowTopIndex + structPtr->visibleEntries;
        s32 scroll = structPtr->unk4 - structPtr->windowTopIndex;

        if (windowBottomIndex <= structPtr->unk4)
            scroll = structPtr->visibleEntries;
        MatchCall_MoveWindow(scroll, TRUE);
        return 2;
    }
    else
    {
        s32 cursor, lastVisibleIndex;
        if (structPtr->listLength >= structPtr->visibleEntries)
        {
            cursor = structPtr->selectedIndexOffset;
            lastVisibleIndex = structPtr->visibleEntries;
        }
        else
        {
            cursor = structPtr->selectedIndexOffset;
            lastVisibleIndex = structPtr->listLength;
        }
        lastVisibleIndex -= 1;
        if (cursor >= lastVisibleIndex)
            return 0;

        structPtr->selectedIndexOffset = lastVisibleIndex;
        return 1;
    }
}

u32 GetSelectedPokenavListIndex(void)
{
    struct MatchCallWindowState *structPtr = GetMatchCallWindowStruct();

    return structPtr->windowTopIndex + structPtr->selectedIndexOffset;
}

u32 GetMatchCallListTopIndex(void)
{
    struct MatchCallWindowState *structPtr = GetMatchCallWindowStruct();

    return structPtr->windowTopIndex;
}

void sub_81C877C(void)
{
    struct PokenavSub17 *structPtr = GetSubstructPtr(POKENAV_SUBSTRUCT_MATCH_CALL_LIST);
    structPtr->unk89C = 0;
    structPtr->loopedTaskId = CreateLoopedTask(LoopedTask_sub_81C8870, 6);
}

void PrintCheckPageInfo(s16 a0)
{
    struct PokenavSub17 *structPtr = GetSubstructPtr(POKENAV_SUBSTRUCT_MATCH_CALL_LIST);
    structPtr->unk888.windowTopIndex += a0;
    structPtr->unk89C = 0;
    structPtr->loopedTaskId = CreateLoopedTask(LoopedTask_PrintCheckPageInfo, 6);
}

void sub_81C87F0(void)
{
    struct PokenavSub17 *structPtr = GetSubstructPtr(POKENAV_SUBSTRUCT_MATCH_CALL_LIST);
    structPtr->unk89C = 0;
    structPtr->loopedTaskId = CreateLoopedTask(LoopedTask_sub_81C8A28, 6);
}

bool32 IsMatchCallListTaskActive(void)
{
    struct PokenavSub17 *structPtr = GetSubstructPtr(POKENAV_SUBSTRUCT_MATCH_CALL_LIST);
    return IsLoopedTaskActive(structPtr->loopedTaskId);
}

void sub_81C8838(void)
{
    struct PokenavSub17 *structPtr = GetSubstructPtr(POKENAV_SUBSTRUCT_MATCH_CALL_LIST);
    struct MatchCallWindowState *subPtr = &structPtr->unk888;
    structPtr->list.unk38(structPtr->list.listWindow.windowId, subPtr->windowTopIndex + subPtr->selectedIndexOffset, (structPtr->list.listWindow.unkA + subPtr->selectedIndexOffset) & 0xF);
    CopyWindowToVram(structPtr->list.listWindow.windowId, 1);
}

// TODO:
u32 LoopedTask_sub_81C8870(s32 state)
{
    struct PokenavSub17 *structPtr = GetSubstructPtr(POKENAV_SUBSTRUCT_MATCH_CALL_LIST);

    switch (state)
    {
    case 0:
        ToggleMatchCallArrows(&structPtr->list, 1);
        // fall-through
    case 1:
        if (structPtr->unk89C != structPtr->unk888.selectedIndexOffset)
            sub_81C8B70(&structPtr->list.listWindow, structPtr->unk89C, 1);

        structPtr->unk89C++;
        return LT_INC_AND_PAUSE;
    case 2:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            if (structPtr->unk89C != structPtr->unk888.visibleEntries)
                return 6;
            if (structPtr->unk888.selectedIndexOffset != 0)
                sub_81C8B70(&structPtr->list.listWindow, structPtr->unk89C, structPtr->unk888.selectedIndexOffset);

            return LT_INC_AND_PAUSE;
        }
        return LT_PAUSE;
    case 3:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            if (structPtr->unk888.selectedIndexOffset != 0)
            {
                MatchCall_MoveWindow(structPtr->unk888.selectedIndexOffset, FALSE);
                return LT_INC_AND_PAUSE;
            }
            return LT_FINISH;
        }
        return LT_PAUSE;
    case 4:
         if (IsMonListLoopedTaskActive())
            return LT_PAUSE;

        structPtr->unk888.selectedIndexOffset = 0;
        return LT_FINISH;
    }
    return LT_FINISH;
}

u32 LoopedTask_PrintCheckPageInfo(s32 state)
{
    struct PokenavSub17 *structPtr = GetSubstructPtr(POKENAV_SUBSTRUCT_MATCH_CALL_LIST);
    if (IsDma3ManagerBusyWithBgCopy())
        return LT_PAUSE;

    switch (state)
    {
    case 0:
        sub_81C8CB4(&structPtr->unk888, &structPtr->list);
        break;
    case 1:
        PrintMatchCallFieldNames(&structPtr->list, 0);
        break;
    case 2:
        PrintMatchCallFlavorText(&structPtr->unk888, &structPtr->list, CHECK_PAGE_STRATEGY);
        break;
    case 3:
        PrintMatchCallFieldNames(&structPtr->list, 1);
        break;
    case 4:
        PrintMatchCallFlavorText(&structPtr->unk888, &structPtr->list, CHECK_PAGE_POKEMON);
        break;
    case 5:
        PrintMatchCallFieldNames(&structPtr->list, 2);
        break;
    case 6:
        PrintMatchCallFlavorText(&structPtr->unk888, &structPtr->list, CHECK_PAGE_INTRO_1);
        break;
    case 7:
        PrintMatchCallFlavorText(&structPtr->unk888, &structPtr->list, CHECK_PAGE_INTRO_2);
        break;
    default:
        return LT_FINISH;
    }
    return LT_INC_AND_PAUSE;
}

u32 LoopedTask_sub_81C8A28(s32 state)
{
    struct PokenavSub17 *structPtr;
    struct MatchCallWindowState *subPtr888;
    struct PokenavSub17Substruct *subPtr0;
    s32 r5, *ptr;

    if (IsDma3ManagerBusyWithBgCopy())
        return LT_PAUSE;

    structPtr = GetSubstructPtr(POKENAV_SUBSTRUCT_MATCH_CALL_LIST);
    subPtr888 = &structPtr->unk888;
    subPtr0 = &structPtr->list;

    switch (state)
    {
    case 0:
        sub_81C8D4C(subPtr888, subPtr0);
        return LT_INC_AND_PAUSE;
    case 1:
        ptr = &structPtr->unk89C;
        if (++(*ptr) < structPtr->unk888.visibleEntries)
        {
            sub_81C8B70(&subPtr0->listWindow, *ptr, 1);
            return LT_PAUSE;
        }

        *ptr = 0;
        if (subPtr888->listLength <= subPtr888->visibleEntries)
        {
            if (subPtr888->windowTopIndex != 0)
            {
                s32 r4 = subPtr888->windowTopIndex;
                r5 = -r4;
                sub_81C8B70(&subPtr0->listWindow, r5, r4);
                subPtr888->selectedIndexOffset = r4;
                *ptr = r5;
                return LT_INC_AND_PAUSE;
            }
        }
        else
        {
            if (subPtr888->windowTopIndex + subPtr888->visibleEntries > subPtr888->listLength)
            {
                s32 r4 = subPtr888->windowTopIndex + subPtr888->visibleEntries - subPtr888->listLength;
                r5 = -r4;
                sub_81C8B70(&subPtr0->listWindow, r5, r4);
                subPtr888->selectedIndexOffset = r4;
                *ptr = r5;
                return LT_INC_AND_PAUSE;
            }
        }
        return 9;
    case 2:
        MatchCall_MoveWindow(structPtr->unk89C, FALSE);
        return LT_INC_AND_PAUSE;
    case 3:
        if (!IsMonListLoopedTaskActive())
        {
            structPtr->unk89C = 0;
            return 1;
        }
        return 2;
    case 4:
        sub_81C83AC(subPtr888->unk10, subPtr888->windowTopIndex + structPtr->unk89C, 1, subPtr888->unkC, structPtr->unk89C, &structPtr->list);
        return LT_INC_AND_PAUSE;
    case 5:
        if (sub_81C83E0())
            return LT_PAUSE;
        if (++structPtr->unk89C >= subPtr888->listLength || structPtr->unk89C >= subPtr888->visibleEntries)
            return LT_INC_AND_CONTINUE;
        return 9;
    case 6:
        ToggleMatchCallArrows(subPtr0, 0);
        return LT_FINISH;
    }

    return LT_FINISH;
}

void sub_81C8B70(struct PokenavListMenuWindow *listWindow, s32 a1, s32 a2)
{
    u8 *v1 = (u8*)GetWindowAttribute(listWindow->windowId, WINDOW_TILE_DATA);
    u32 v2 = listWindow->unk4 * 64;

    a1 = (listWindow->unkA + a1) & 0xF;
    if (a1 + a2 <= 16)
    {
        CpuFastFill8(PIXEL_FILL(1), v1 + a1 * v2, a2 * v2);
        CopyWindowToVram(listWindow->windowId, 2);
    }
    else
    {
        u32 v3 = 16 - a1;
        u32 v4 = a2 - v3;

        CpuFastFill8(PIXEL_FILL(1), v1 + a1 * v2, v3 * v2);
        CpuFastFill8(PIXEL_FILL(1), v1, v4 * v2);
        CopyWindowToVram(listWindow->windowId, 2);
    }

    for (a2--; a2 != -1; a1 = (a1 + 1) & 0xF, a2--)
        ClearRematchPokeballIcon(listWindow->windowId, a1);

    CopyWindowToVram(listWindow->windowId, 1);
}

void sub_81C8C64(struct PokenavListMenuWindow *listWindow, u32 a1)
{
    u16 var;
    u16 *v1 = (u16*)GetBgTilemapBuffer(GetWindowAttribute(listWindow->windowId, WINDOW_BG));
    v1 += ((listWindow->unkA << 6) + listWindow->unk2) - 1;

    if (a1 != 0)
        var = (listWindow->unk1 << 12) | (listWindow->unk6 + 1);
    else
        var = (listWindow->unk1 << 12) | (listWindow->unk6);

    v1[0] = var;
    v1[0x20] = var;
}

void sub_81C8CB4(struct MatchCallWindowState *state, struct PokenavSub17Substruct *list)
{
    u8 colors[3] = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_DARK_GREY, TEXT_COLOR_LIGHT_RED};

    list->unk34(state->unk10 + state->unkC * state->windowTopIndex, list->unkTextBuffer);
    list->unk38(list->listWindow.windowId, state->windowTopIndex, list->listWindow.unkA);
    FillWindowPixelRect(list->listWindow.windowId, PIXEL_FILL(4), 0, list->listWindow.unkA * 16, list->listWindow.unk4 * 8, 16);
    AddTextPrinterParameterized3(list->listWindow.windowId, list->listWindow.fontId, 8, (list->listWindow.unkA * 16) + 1, colors, TEXT_SPEED_FF, list->unkTextBuffer);
    sub_81C8C64(&list->listWindow, 1);
    CopyWindowRectToVram(list->listWindow.windowId, 3, 0, list->listWindow.unkA * 2, list->listWindow.unk4, 2);
}

void sub_81C8D4C(struct MatchCallWindowState *state, struct PokenavSub17Substruct *list)
{
    list->unk34(state->unk10 + state->unkC * state->windowTopIndex, list->unkTextBuffer);
    FillWindowPixelRect(list->listWindow.windowId, PIXEL_FILL(1), 0, list->listWindow.unkA * 16, list->listWindow.unk4 * 8, 16);
    AddTextPrinterParameterized(list->listWindow.windowId, list->listWindow.fontId, list->unkTextBuffer, 8, list->listWindow.unkA * 16 + 1, TEXT_SPEED_FF, NULL);
    sub_81C8C64(&list->listWindow, 0);
    CopyWindowToVram(list->listWindow.windowId, 3);
}

void PrintMatchCallFieldNames(struct PokenavSub17Substruct *list, u32 fieldId)
{
    const u8 *fieldNames[] = {gText_PokenavMatchCall_Strategy, gText_PokenavMatchCall_TrainerPokemon, gText_PokenavMatchCall_SelfIntroduction};
    u8 colors[3] = {TEXT_COLOR_WHITE, TEXT_COLOR_RED, TEXT_COLOR_LIGHT_RED};
    u32 top = (list->listWindow.unkA + 1 + (fieldId * 2)) & 0xF;

    FillWindowPixelRect(list->listWindow.windowId, PIXEL_FILL(1), 0, top << 4, list->listWindow.unk4, 16);
    AddTextPrinterParameterized3(list->listWindow.windowId, 7, 2, (top << 4) + 1, colors, -1, fieldNames[fieldId]);
    CopyWindowRectToVram(list->listWindow.windowId, 2, 0, top << 1, list->listWindow.unk4, 2);
}

static void PrintMatchCallFlavorText(struct MatchCallWindowState *a0, struct PokenavSub17Substruct *list, u32 checkPageEntry)
{
    // lines 1, 3, and 5 are the field names printed by PrintMatchCallFieldNames
    static const u8 lineOffsets[CHECK_PAGE_ENTRY_COUNT] = 
    {
        [CHECK_PAGE_STRATEGY] = 2, 
        [CHECK_PAGE_POKEMON]  = 4, 
        [CHECK_PAGE_INTRO_1]  = 6, 
        [CHECK_PAGE_INTRO_2]  = 7
    };

    u32 r6 = (list->listWindow.unkA + lineOffsets[checkPageEntry]) & 0xF;
    const u8 *str = GetMatchCallFlavorText(a0->windowTopIndex, checkPageEntry);

    if (str != NULL)
    {
        sub_81DB620(list->listWindow.windowId, 1, r6 * 2, list->listWindow.unk4 - 1, 2);
        AddTextPrinterParameterized(list->listWindow.windowId, 7, str, 2, (r6 << 4) + 1, TEXT_SPEED_FF, NULL);
        CopyWindowRectToVram(list->listWindow.windowId, 2, 0, r6 * 2, list->listWindow.unk4, 2);
    }
}

static const struct CompressedSpriteSheet sMatchcallArrowSpriteSheets[] =
{
    {
        .data = sMatchcallArrowSpriteSheetData,
        .size = 192,
        .tag = 0xA
    }
};

static const struct SpritePalette sMatchcallArrowPalettes[] =
{
    {
        .data = sMatchcallArrowPaletteData,
        .tag = 0x14
    },
    {}
};

static const struct OamData sMatchCallRightArrowSpriteOam =
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

static const struct SpriteTemplate sMatchCallRightArrowSprite =
{
    .tileTag = 0xA,
    .paletteTag = 0x14,
    .oam = &sMatchCallRightArrowSpriteOam,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_MatchCallRightArrow
};

static const struct OamData sMatchCallUpDownArrowSpriteOam =
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

static const struct SpriteTemplate sMatchCallUpDownArrowSprite =
{
    .tileTag = 0xA,
    .paletteTag = 0x14,
    .oam = &sMatchCallUpDownArrowSpriteOam,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

void sub_81C8ED0(void)
{
    u32 i;
    const struct CompressedSpriteSheet *ptr;

    for (i = 0, ptr = sMatchcallArrowSpriteSheets; i < ARRAY_COUNT(sMatchcallArrowSpriteSheets); ptr++, i++)
        LoadCompressedSpriteSheet(ptr);

    Pokenav_AllocAndLoadPalettes(sMatchcallArrowPalettes);
}

void CreateMatchCallArrowSprites(struct MatchCallWindowState *windowState, struct PokenavSub17Substruct *list)
{
    u32 spriteId;
    s16 x;

    spriteId = CreateSprite(&sMatchCallRightArrowSprite, list->listWindow.unk2 * 8 + 3, (list->listWindow.unk3 + 1) * 8, 7);
    list->rightArrow = &gSprites[spriteId];

    x = list->listWindow.unk2 * 8 + (list->listWindow.unk4 - 1) * 4;
    spriteId = CreateSprite(&sMatchCallUpDownArrowSprite, x, list->listWindow.unk3 * 8 + windowState->visibleEntries * 16, 7);
    list->downArrow = &gSprites[spriteId];
    list->downArrow->oam.tileNum += 2;
    list->downArrow->callback = SpriteCB_MatchCallDownArrow;

    spriteId = CreateSprite(&sMatchCallUpDownArrowSprite, x, list->listWindow.unk3 * 8, 7);
    list->upArrow = &gSprites[spriteId];
    list->upArrow->oam.tileNum += 4;
    list->upArrow->callback = SpriteCB_MatchCallUpArrow;
}

void DestroyMatchCallListArrows(struct PokenavSub17Substruct *list)
{
    DestroySprite(list->rightArrow);
    DestroySprite(list->upArrow);
    DestroySprite(list->downArrow);
    FreeSpriteTilesByTag(0xA);
    FreeSpritePaletteByTag(0x14);
}

void ToggleMatchCallArrows(struct PokenavSub17Substruct *list, bool32 shouldHide)
{
    if (shouldHide)
    {
        list->rightArrow->callback = SpriteCallbackDummy;
        list->upArrow->callback = SpriteCallbackDummy;
        list->downArrow->callback = SpriteCallbackDummy;
    }
    else
    {
        list->rightArrow->callback = SpriteCB_MatchCallRightArrow;
        list->upArrow->callback = SpriteCB_MatchCallUpArrow;
        list->downArrow->callback = SpriteCB_MatchCallDownArrow;
    }
    list->rightArrow->invisible = shouldHide;
    list->upArrow->invisible = shouldHide;
    list->downArrow->invisible = shouldHide;
}

void SpriteCB_MatchCallRightArrow(struct Sprite *sprite)
{
    struct PokenavSub17 *structPtr = GetSubstructPtr(POKENAV_SUBSTRUCT_MATCH_CALL_LIST);
    sprite->pos2.y = structPtr->unk888.selectedIndexOffset << 4;
}

void SpriteCB_MatchCallDownArrow(struct Sprite *sprite)
{
    if (sprite->data[7] == 0 && ShouldShowDownArrow())
        sprite->invisible = FALSE;
    else
        sprite->invisible = TRUE;

    if (++sprite->data[0] > 3)
    {
        s16 offset;

        sprite->data[0] = 0;
        offset = (sprite->data[1] + 1) & 7;
        sprite->data[1] = offset;
        sprite->pos2.y = offset;
    }
}

void SpriteCB_MatchCallUpArrow(struct Sprite *sprite)
{
    if (sprite->data[7] == 0 && ShouldShowUpArrow())
        sprite->invisible = FALSE;
    else
        sprite->invisible = TRUE;

    if (++sprite->data[0] > 3)
    {
        s16 offset;

        sprite->data[0] = 0;
        offset = (sprite->data[1] + 1) & 7;
        sprite->data[1] = offset;
        sprite->pos2.y = -1 * offset;
    }
}

void ToggleMatchCallVerticalArrows(bool32 shouldHide)
{
    struct PokenavSub17 *structPtr = GetSubstructPtr(POKENAV_SUBSTRUCT_MATCH_CALL_LIST);
    structPtr->list.upArrow->data[7] = shouldHide;
    structPtr->list.downArrow->data[7] = shouldHide;
}

void InitMatchCallWindowState(struct MatchCallWindowState *dst, struct PokenavListTemplate *template)
{
    dst->unk10 = template->list.matchCallEntries;
    dst->windowTopIndex = template->unk6;
    dst->listLength = template->count;
    dst->unkC = template->unk8;
    dst->visibleEntries = template->maxShowed;
    if (dst->visibleEntries >= dst->listLength)
    {
        dst->windowTopIndex = 0;
        dst->unk4 = 0;
        dst->selectedIndexOffset = template->unk6;
    }
    else
    {
        dst->unk4 = dst->listLength - dst->visibleEntries;
        if (dst->windowTopIndex + dst->visibleEntries > dst->listLength)
        {
            dst->selectedIndexOffset = dst->windowTopIndex + dst->visibleEntries - dst->listLength;
            dst->windowTopIndex = template->unk6 - dst->selectedIndexOffset;
        }
        else
        {
            dst->selectedIndexOffset = 0;
        }
    }
}

bool32 CopyPokenavListMenuTemplate(struct PokenavSub17Substruct *dest, const struct BgTemplate *bgTemplate, struct PokenavListTemplate *template, s32 a3)
{
    struct WindowTemplate window;

    dest->listWindow.bg = bgTemplate->bg;
    dest->listWindow.unk6 = a3;
    dest->unk34 = template->listFunc.unk10_2;
    dest->unk38 = template->unk14;
    dest->listWindow.unk1 = template->fillValue;
    dest->listWindow.unk2 = template->item_X;
    dest->listWindow.unk3 = template->listTop;
    dest->listWindow.unk4 = template->windowWidth;
    dest->listWindow.fontId = template->fontId;

    window.bg = bgTemplate->bg;
    window.tilemapLeft = template->item_X;
    window.tilemapTop = 0;
    window.width = template->windowWidth;
    window.height = 32;
    window.paletteNum = template->fillValue;
    window.baseBlock = a3 + 2;

    dest->listWindow.windowId = AddWindow(&window);
    if (dest->listWindow.windowId == 0xFF)
        return FALSE;

    dest->listWindow.unkA = 0;
    dest->rightArrow = NULL;
    dest->upArrow = NULL;
    dest->downArrow = NULL;
    return 1;
}
