#include "global.h"
#include "pokenav.h"
#include "window.h"
#include "strings.h"
#include "text.h"
#include "bg.h"
#include "menu.h"
#include "decompress.h"

// TODO: This UI isnt just for match call, seems to be the general pokenav list UI

struct UnknownSubSubStruct_0203CF40 {
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
    struct UnknownSubSubStruct_0203CF40 unk0;
    u32 unk10;
    u32 unk14;
    u32 unk18;
    void * unk1C;
    s32 unk20;
    s32 unk24;
    u32 unk28;
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
    struct PokenavSub17Substruct unk0;
    u8 tilemapBuffer[0x800];
    struct MatchCallWindowState unk888;
    s32 unk89C;
    u32 unk8A0;
};

extern void sub_81DB620(u32 windowId, u32 a1, u32 a2, u32 a3, u32 a4);

void sub_81C82E4(struct PokenavSub17 *a0);
bool32 sub_81C91AC(struct PokenavSub17Substruct *a0, const struct BgTemplate *a1, struct PokenavListTemplate *a2, s32 a3);
void sub_81C9160(struct MatchCallWindowState *a0, struct PokenavListTemplate *a1);
void SpriteCB_MatchCallUpArrow(struct Sprite *sprite);
void SpriteCB_MatchCallDownArrow(struct Sprite *sprite);
void SpriteCB_MatchCallRightArrow(struct Sprite *sprite);
void ToggleMatchCallArrows(struct PokenavSub17Substruct *a0, u32 a1);
void sub_81C8FE0(struct PokenavSub17Substruct *a0);
void sub_81C8EF8(struct MatchCallWindowState *a0, struct PokenavSub17Substruct *a1);
void sub_81C8ED0(void);
static void PrintMatchCallFlavorText(struct MatchCallWindowState *a0, struct PokenavSub17Substruct *a1, u32 a2);
void PrintMatchCallFieldNames(struct PokenavSub17Substruct *a0, u32 a1);
void sub_81C8D4C(struct MatchCallWindowState *a0, struct PokenavSub17Substruct *a1);
void sub_81C8CB4(struct MatchCallWindowState *a0, struct PokenavSub17Substruct *a1);
void sub_81C8B70(struct UnknownSubSubStruct_0203CF40 *a0, s32 a1, s32 a2);
void sub_81C8568(s32 a0, struct PokenavSub17Substruct *a1);
void sub_81C83AC(void * a0, u32 a1, u32 a2, u32 a3, u32 a4, struct PokenavSub17Substruct *a5);
void sub_81C837C(struct MatchCallWindowState *a0, struct PokenavSub17Substruct *a1);
void sub_81C835C(struct UnknownSubSubStruct_0203CF40 *a0);
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
    struct PokenavSub17 *structPtr = AllocSubstruct(17, sizeof(struct PokenavSub17));
    if (structPtr == NULL)
        return FALSE;

    sub_81C9160(&structPtr->unk888, arg1);
    if (!sub_81C91AC(&structPtr->unk0, arg0, arg1, arg2))
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

    structPtr = GetSubstructPtr(17);
    sub_81C8FE0(&structPtr->unk0);
    RemoveWindow(structPtr->unk0.unk0.windowId);
    FreePokenavSubstruct(17);
}

u32 LoopedTask_sub_81C8254(s32 state)
{
    struct PokenavSub17 *structPtr;

    if (IsDma3ManagerBusyWithBgCopy())
        return 2;

    structPtr = GetSubstructPtr(17);

    switch (state)
    {
    case 0:
        sub_81C82E4(structPtr);
        return LT_INC_AND_PAUSE;
    case 1:
        sub_81C835C(&structPtr->unk0.unk0);
        return LT_INC_AND_PAUSE;
    case 2:
        sub_81C837C(&structPtr->unk888, &structPtr->unk0);
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
        sub_81C8EF8(&structPtr->unk888, &structPtr->unk0);
        return LT_FINISH;
    default:
        return LT_FINISH;
    }
}

void sub_81C82E4(struct PokenavSub17 *a0)
{
    u16 tileNum = (a0->unk0.unk0.unk1 << 12) | a0->unk0.unk0.unk6;
    sub_8199DF0(a0->unk0.unk0.bg, PIXEL_FILL(1), a0->unk0.unk0.unk6, 1);
    sub_8199DF0(a0->unk0.unk0.bg, PIXEL_FILL(4), a0->unk0.unk0.unk6 + 1, 1);
    SetBgTilemapBuffer(a0->unk0.unk0.bg, a0->tilemapBuffer);
    FillBgTilemapBufferRect_Palette0(a0->unk0.unk0.bg, tileNum, 0, 0, 32, 32);
    ChangeBgY(a0->unk0.unk0.bg, 0, 0);
    ChangeBgX(a0->unk0.unk0.bg, 0, 0);
    ChangeBgY(a0->unk0.unk0.bg, a0->unk0.unk0.unk3 << 11, 2);
    CopyBgTilemapBufferToVram(a0->unk0.unk0.bg);
}

void sub_81C835C(struct UnknownSubSubStruct_0203CF40 *a0)
{
    FillWindowPixelBuffer(a0->windowId, PIXEL_FILL(1));
    PutWindowTilemap(a0->windowId);
    CopyWindowToVram(a0->windowId, 1);
}

void sub_81C837C(struct MatchCallWindowState *a0, struct PokenavSub17Substruct *a1)
{
    s32 arg2 = a0->listLength - a0->windowTopIndex;
    if (arg2 > a0->visibleEntries)
        arg2 = a0->visibleEntries;

    sub_81C83AC(a0->unk10, a0->windowTopIndex, arg2, a0->unkC, 0, a1);
}

void sub_81C83AC(void * a0, u32 a1, u32 a2, u32 a3, u32 a4, struct PokenavSub17Substruct *a5)
{
    if (a2 == 0)
        return;

    a5->unk1C = a0 + a1 * a3;
    a5->unk18 = a3;
    a5->unk0.unkC = 0;
    a5->unk0.unkE = a2;
    a5->unk14 = a1;
    a5->unk10 = a4;
    CreateLoopedTask(LoopedTask_sub_81C83F0, 5);
}

bool32 sub_81C83E0(void)
{
    return FuncIsActiveLoopedTask(LoopedTask_sub_81C83F0);
}

u32 LoopedTask_sub_81C83F0(s32 state)
{
    u32 v1;
    struct PokenavSub17Substruct *structPtr = GetSubstructPtr(17);

    switch (state)
    {
    case 0:
        v1 = (structPtr->unk0.unkA + structPtr->unk0.unkC + structPtr->unk10) & 0xF;
        structPtr->unk34(structPtr->unk1C, structPtr->unkTextBuffer);
        if (structPtr->unk38 != NULL)
            structPtr->unk38(structPtr->unk0.windowId, structPtr->unk14, v1);

        AddTextPrinterParameterized(structPtr->unk0.windowId, structPtr->unk0.fontId, structPtr->unkTextBuffer, 8, (v1 << 4) + 1, 255, NULL);
        if (++structPtr->unk0.unkC >= structPtr->unk0.unkE)
        {
            if (structPtr->unk38 != NULL)
                CopyWindowToVram(structPtr->unk0.windowId, 3);
            else
                CopyWindowToVram(structPtr->unk0.windowId, 2);
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
    struct PokenavSub17 *structPtr = GetSubstructPtr(17);

    return (structPtr->unk888.windowTopIndex != 0);
}

bool32 ShouldShowDownArrow(void)
{
    struct PokenavSub17 *structPtr = GetSubstructPtr(17);
    struct MatchCallWindowState *subPtr = &structPtr->unk888;

    return (subPtr->windowTopIndex + subPtr->visibleEntries < subPtr->listLength);
}

void MatchCall_MoveWindow(s32 a0, bool32 a1)
{
    struct PokenavSub17 *structPtr = GetSubstructPtr(17);
    struct MatchCallWindowState *subPtr = &structPtr->unk888;

    if (a0 < 0)
    {
        if (subPtr->windowTopIndex + a0 < 0)
            a0 = -1 * subPtr->windowTopIndex;
        if (a1)
            sub_81C83AC(subPtr->unk10, subPtr->windowTopIndex + a0, a0 * -1, subPtr->unkC, a0, &structPtr->unk0);
    }
    else if (a1)
    {
        s32 temp = gUnknown_0203CF44 = subPtr->windowTopIndex + subPtr->visibleEntries;
        if (temp + a0 >= subPtr->listLength)
            a0 = subPtr->listLength - temp;

        sub_81C83AC(subPtr->unk10, gUnknown_0203CF44, a0, subPtr->unkC, subPtr->visibleEntries, &structPtr->unk0);
    }

    sub_81C8568(a0, &structPtr->unk0);
    subPtr->windowTopIndex += a0;
}

void sub_81C8568(s32 a0, struct PokenavSub17Substruct *a1)
{
    a1->unk20 = GetBgY(a1->unk0.bg);
    a1->unk24 = a1->unk20 + (a0 << 12);
    if (a0 > 0)
        a1->unk30 = 1;
    else
        a1->unk30 = 2;
    a1->unk2C = a0;
    a1->unk28 = CreateLoopedTask(LoopedTask_sub_81C85A0, 6);
}

u32 LoopedTask_sub_81C85A0(s32 state)
{
    s32 y, v1;
    bool32 flag;
    struct PokenavSub17 *structPtr = GetSubstructPtr(17);
    struct PokenavSub17Substruct *subPtr = &structPtr->unk0;

    switch (state)
    {
    case 0:
        if (!sub_81C83E0())
            return LT_INC_AND_CONTINUE;
        return LT_PAUSE;
    case 1:
        flag = FALSE;
        y = GetBgY(subPtr->unk0.bg);
        v1 = ChangeBgY(subPtr->unk0.bg, 0x1000, subPtr->unk30);
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
            subPtr->unk0.unkA = (subPtr->unk0.unkA + subPtr->unk2C) & 0xF;
            ChangeBgY(subPtr->unk0.bg, subPtr->unk24, 0);
            return LT_FINISH;
        }
        return LT_PAUSE;
    }
    return LT_FINISH;
}

bool32 sub_81C8630(void)
{
    struct PokenavSub17 *structPtr = GetSubstructPtr(17);
    return IsLoopedTaskActive(structPtr->unk0.unk28);
}

struct MatchCallWindowState *GetMatchCallWindowStruct(void)
{
    struct PokenavSub17 *structPtr = GetSubstructPtr(17);
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

u32 GetSelectedMatchCall(void)
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
    struct PokenavSub17 *structPtr = GetSubstructPtr(17);
    structPtr->unk89C = 0;
    structPtr->unk8A0 = CreateLoopedTask(LoopedTask_sub_81C8870, 6);
}

void PrintCheckPageInfo(s16 a0)
{
    struct PokenavSub17 *structPtr = GetSubstructPtr(17);
    structPtr->unk888.windowTopIndex += a0;
    structPtr->unk89C = 0;
    structPtr->unk8A0 = CreateLoopedTask(LoopedTask_PrintCheckPageInfo, 6);
}

void sub_81C87F0(void)
{
    struct PokenavSub17 *structPtr = GetSubstructPtr(17);
    structPtr->unk89C = 0;
    structPtr->unk8A0 = CreateLoopedTask(LoopedTask_sub_81C8A28, 6);
}

bool32 sub_81C8820(void)
{
    struct PokenavSub17 *structPtr = GetSubstructPtr(17);
    return IsLoopedTaskActive(structPtr->unk8A0);
}

void sub_81C8838(void)
{
    struct PokenavSub17 *structPtr = GetSubstructPtr(17);
    struct MatchCallWindowState *subPtr = &structPtr->unk888;
    structPtr->unk0.unk38(structPtr->unk0.unk0.windowId, subPtr->windowTopIndex + subPtr->selectedIndexOffset, (structPtr->unk0.unk0.unkA + subPtr->selectedIndexOffset) & 0xF);
    CopyWindowToVram(structPtr->unk0.unk0.windowId, 1);
}

// TODO:
u32 LoopedTask_sub_81C8870(s32 state)
{
    struct PokenavSub17 *structPtr = GetSubstructPtr(17);

    switch (state)
    {
    case 0:
        ToggleMatchCallArrows(&structPtr->unk0, 1);
        // fall-through
    case 1:
        if (structPtr->unk89C != structPtr->unk888.selectedIndexOffset)
            sub_81C8B70(&structPtr->unk0.unk0, structPtr->unk89C, 1);

        structPtr->unk89C++;
        return LT_INC_AND_PAUSE;
    case 2:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            if (structPtr->unk89C != structPtr->unk888.visibleEntries)
                return 6;
            if (structPtr->unk888.selectedIndexOffset != 0)
                sub_81C8B70(&structPtr->unk0.unk0, structPtr->unk89C, structPtr->unk888.selectedIndexOffset);

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
         if (sub_81C8630())
            return LT_PAUSE;

        structPtr->unk888.selectedIndexOffset = 0;
        return LT_FINISH;
    }
    return LT_FINISH;
}

u32 LoopedTask_PrintCheckPageInfo(s32 state)
{
    struct PokenavSub17 *structPtr = GetSubstructPtr(17);
    if (IsDma3ManagerBusyWithBgCopy())
        return LT_PAUSE;

    switch (state)
    {
    case 0:
        sub_81C8CB4(&structPtr->unk888, &structPtr->unk0);
        break;
    case 1:
        PrintMatchCallFieldNames(&structPtr->unk0, 0);
        break;
    case 2:
        PrintMatchCallFlavorText(&structPtr->unk888, &structPtr->unk0, CHECK_PAGE_STRATEGY);
        break;
    case 3:
        PrintMatchCallFieldNames(&structPtr->unk0, 1);
        break;
    case 4:
        PrintMatchCallFlavorText(&structPtr->unk888, &structPtr->unk0, CHECK_PAGE_POKEMON);
        break;
    case 5:
        PrintMatchCallFieldNames(&structPtr->unk0, 2);
        break;
    case 6:
        PrintMatchCallFlavorText(&structPtr->unk888, &structPtr->unk0, CHECK_PAGE_INTRO_1);
        break;
    case 7:
        PrintMatchCallFlavorText(&structPtr->unk888, &structPtr->unk0, CHECK_PAGE_INTRO_2);
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

    structPtr = GetSubstructPtr(17);
    subPtr888 = &structPtr->unk888;
    subPtr0 = &structPtr->unk0;

    switch (state)
    {
    case 0:
        sub_81C8D4C(subPtr888, subPtr0);
        return LT_INC_AND_PAUSE;
    case 1:
        ptr = &structPtr->unk89C;
        if (++(*ptr) < structPtr->unk888.visibleEntries)
        {
            sub_81C8B70(&subPtr0->unk0, *ptr, 1);
            return LT_PAUSE;
        }

        *ptr = 0;
        if (subPtr888->listLength <= subPtr888->visibleEntries)
        {
            if (subPtr888->windowTopIndex != 0)
            {
                s32 r4 = subPtr888->windowTopIndex;
                r5 = -r4;
                sub_81C8B70(&subPtr0->unk0, r5, r4);
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
                sub_81C8B70(&subPtr0->unk0, r5, r4);
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
        if (!sub_81C8630())
        {
            structPtr->unk89C = 0;
            return 1;
        }
        return 2;
    case 4:
        sub_81C83AC(subPtr888->unk10, subPtr888->windowTopIndex + structPtr->unk89C, 1, subPtr888->unkC, structPtr->unk89C, &structPtr->unk0);
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

void sub_81C8B70(struct UnknownSubSubStruct_0203CF40 *a0, s32 a1, s32 a2)
{
    u8 *v1 = (u8*)GetWindowAttribute(a0->windowId, WINDOW_TILE_DATA);
    u32 v2 = a0->unk4 * 64;

    a1 = (a0->unkA + a1) & 0xF;
    if (a1 + a2 <= 16)
    {
        CpuFastFill8(PIXEL_FILL(1), v1 + a1 * v2, a2 * v2);
        CopyWindowToVram(a0->windowId, 2);
    }
    else
    {
        u32 v3 = 16 - a1;
        u32 v4 = a2 - v3;

        CpuFastFill8(PIXEL_FILL(1), v1 + a1 * v2, v3 * v2);
        CpuFastFill8(PIXEL_FILL(1), v1, v4 * v2);
        CopyWindowToVram(a0->windowId, 2);
    }

    for (a2--; a2 != -1; a1 = (a1 + 1) & 0xF, a2--)
        ClearRematchPokeballIcon(a0->windowId, a1);

    CopyWindowToVram(a0->windowId, 1);
}

void sub_81C8C64(struct UnknownSubSubStruct_0203CF40 *a0, u32 a1)
{
    u16 var;
    u16 *v1 = (u16*)GetBgTilemapBuffer(GetWindowAttribute(a0->windowId, WINDOW_BG));
    v1 += ((a0->unkA << 6) + a0->unk2) - 1;

    if (a1 != 0)
        var = (a0->unk1 << 12) | (a0->unk6 + 1);
    else
        var = (a0->unk1 << 12) | (a0->unk6);

    v1[0] = var;
    v1[0x20] = var;
}

void sub_81C8CB4(struct MatchCallWindowState *a0, struct PokenavSub17Substruct *a1)
{
    u8 colors[3] = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_DARK_GREY, TEXT_COLOR_LIGHT_RED};

    a1->unk34(a0->unk10 + a0->unkC * a0->windowTopIndex, a1->unkTextBuffer);
    a1->unk38(a1->unk0.windowId, a0->windowTopIndex, a1->unk0.unkA);
    FillWindowPixelRect(a1->unk0.windowId, PIXEL_FILL(4), 0, a1->unk0.unkA * 16, a1->unk0.unk4 * 8, 16);
    AddTextPrinterParameterized3(a1->unk0.windowId, a1->unk0.fontId, 8, (a1->unk0.unkA * 16) + 1, colors, TEXT_SPEED_FF, a1->unkTextBuffer);
    sub_81C8C64(&a1->unk0, 1);
    CopyWindowRectToVram(a1->unk0.windowId, 3, 0, a1->unk0.unkA * 2, a1->unk0.unk4, 2);
}

void sub_81C8D4C(struct MatchCallWindowState *a0, struct PokenavSub17Substruct *a1)
{
    a1->unk34(a0->unk10 + a0->unkC * a0->windowTopIndex, a1->unkTextBuffer);
    FillWindowPixelRect(a1->unk0.windowId, PIXEL_FILL(1), 0, a1->unk0.unkA * 16, a1->unk0.unk4 * 8, 16);
    AddTextPrinterParameterized(a1->unk0.windowId, a1->unk0.fontId, a1->unkTextBuffer, 8, a1->unk0.unkA * 16 + 1, TEXT_SPEED_FF, NULL);
    sub_81C8C64(&a1->unk0, 0);
    CopyWindowToVram(a1->unk0.windowId, 3);
}

void PrintMatchCallFieldNames(struct PokenavSub17Substruct *a0, u32 fieldId)
{
    const u8 *fieldNames[] = {gText_PokenavMatchCall_Strategy, gText_PokenavMatchCall_TrainerPokemon, gText_PokenavMatchCall_SelfIntroduction};
    u8 colors[3] = {TEXT_COLOR_WHITE, TEXT_COLOR_RED, TEXT_COLOR_LIGHT_RED};
    u32 top = (a0->unk0.unkA + 1 + (fieldId * 2)) & 0xF;

    FillWindowPixelRect(a0->unk0.windowId, PIXEL_FILL(1), 0, top << 4, a0->unk0.unk4, 16);
    AddTextPrinterParameterized3(a0->unk0.windowId, 7, 2, (top << 4) + 1, colors, -1, fieldNames[fieldId]);
    CopyWindowRectToVram(a0->unk0.windowId, 2, 0, top << 1, a0->unk0.unk4, 2);
}

static void PrintMatchCallFlavorText(struct MatchCallWindowState *a0, struct PokenavSub17Substruct *a1, u32 checkPageEntry)
{
    // lines 1, 3, and 5 are the field names printed by PrintMatchCallFieldNames
    static const u8 lineOffsets[CHECK_PAGE_ENTRY_COUNT] = 
    {
        [CHECK_PAGE_STRATEGY] = 2, 
        [CHECK_PAGE_POKEMON]  = 4, 
        [CHECK_PAGE_INTRO_1]  = 6, 
        [CHECK_PAGE_INTRO_2]  = 7
    };

    u32 r6 = (a1->unk0.unkA + lineOffsets[checkPageEntry]) & 0xF;
    const u8 *str = GetMatchCallFlavorText(a0->windowTopIndex, checkPageEntry);

    if (str != NULL)
    {
        sub_81DB620(a1->unk0.windowId, 1, r6 * 2, a1->unk0.unk4 - 1, 2);
        AddTextPrinterParameterized(a1->unk0.windowId, 7, str, 2, (r6 << 4) + 1, TEXT_SPEED_FF, NULL);
        CopyWindowRectToVram(a1->unk0.windowId, 2, 0, r6 * 2, a1->unk0.unk4, 2);
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

void sub_81C8EF8(struct MatchCallWindowState *a0, struct PokenavSub17Substruct *a1)
{
    u32 spriteId;
    s16 x;

    spriteId = CreateSprite(&sMatchCallRightArrowSprite, a1->unk0.unk2 * 8 + 3, (a1->unk0.unk3 + 1) * 8, 7);
    a1->rightArrow = &gSprites[spriteId];

    x = a1->unk0.unk2 * 8 + (a1->unk0.unk4 - 1) * 4;
    spriteId = CreateSprite(&sMatchCallUpDownArrowSprite, x, a1->unk0.unk3 * 8 + a0->visibleEntries * 16, 7);
    a1->downArrow = &gSprites[spriteId];
    a1->downArrow->oam.tileNum += 2;
    a1->downArrow->callback = SpriteCB_MatchCallDownArrow;

    spriteId = CreateSprite(&sMatchCallUpDownArrowSprite, x, a1->unk0.unk3 * 8, 7);
    a1->upArrow = &gSprites[spriteId];
    a1->upArrow->oam.tileNum += 4;
    a1->upArrow->callback = SpriteCB_MatchCallUpArrow;
}

void sub_81C8FE0(struct PokenavSub17Substruct *a0)
{
    DestroySprite(a0->rightArrow);
    DestroySprite(a0->upArrow);
    DestroySprite(a0->downArrow);
    FreeSpriteTilesByTag(0xA);
    FreeSpritePaletteByTag(0x14);
}

void ToggleMatchCallArrows(struct PokenavSub17Substruct *a0, bool32 shouldHide)
{
    if (shouldHide)
    {
        a0->rightArrow->callback = SpriteCallbackDummy;
        a0->upArrow->callback = SpriteCallbackDummy;
        a0->downArrow->callback = SpriteCallbackDummy;
    }
    else
    {
        a0->rightArrow->callback = SpriteCB_MatchCallRightArrow;
        a0->upArrow->callback = SpriteCB_MatchCallUpArrow;
        a0->downArrow->callback = SpriteCB_MatchCallDownArrow;
    }
    a0->rightArrow->invisible = shouldHide;
    a0->upArrow->invisible = shouldHide;
    a0->downArrow->invisible = shouldHide;
}

void SpriteCB_MatchCallRightArrow(struct Sprite *sprite)
{
    struct PokenavSub17 *structPtr = GetSubstructPtr(17);
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
    struct PokenavSub17 *structPtr = GetSubstructPtr(17);
    structPtr->unk0.upArrow->data[7] = shouldHide;
    structPtr->unk0.downArrow->data[7] = shouldHide;
}

void sub_81C9160(struct MatchCallWindowState *a0, struct PokenavListTemplate *a1)
{
    a0->unk10 = a1->list.matchCallEntries;
    a0->windowTopIndex = a1->unk6;
    a0->listLength = a1->unk4;
    a0->unkC = a1->unk8;
    a0->visibleEntries = a1->unkC;
    if (a0->visibleEntries >= a0->listLength)
    {
        a0->windowTopIndex = 0;
        a0->unk4 = 0;
        a0->selectedIndexOffset = a1->unk6;
    }
    else
    {
        a0->unk4 = a0->listLength - a0->visibleEntries;
        if (a0->windowTopIndex + a0->visibleEntries > a0->listLength)
        {
            a0->selectedIndexOffset = a0->windowTopIndex + a0->visibleEntries - a0->listLength;
            a0->windowTopIndex = a1->unk6 - a0->selectedIndexOffset;
        }
        else
        {
            a0->selectedIndexOffset = 0;
        }
    }
}

bool32 sub_81C91AC(struct PokenavSub17Substruct *a0, const struct BgTemplate *a1, struct PokenavListTemplate *a2, s32 a3)
{
    struct WindowTemplate window;

    a0->unk0.bg = a1->bg;
    a0->unk0.unk6 = a3;
    a0->unk34 = a2->listFunc.unk10_2;
    a0->unk38 = a2->unk14;
    a0->unk0.unk1 = a2->unkD;
    a0->unk0.unk2 = a2->unk9;
    a0->unk0.unk3 = a2->unkB;
    a0->unk0.unk4 = a2->unkA;
    a0->unk0.fontId = a2->unkE;

    window.bg = a1->bg;
    window.tilemapLeft = a2->unk9;
    window.tilemapTop = 0;
    window.width = a2->unkA;
    window.height = 32;
    window.paletteNum = a2->unkD;
    window.baseBlock = a3 + 2;

    a0->unk0.windowId = AddWindow(&window);
    if (a0->unk0.windowId == 0xFF)
        return FALSE;

    a0->unk0.unkA = 0;
    a0->rightArrow = NULL;
    a0->upArrow = NULL;
    a0->downArrow = NULL;
    return 1;
}
