#include "global.h"
#include "pokenav.h"
#include "window.h"
#include "strings.h"
#include "text.h"
#include "bg.h"
#include "menu.h"
#include "decompress.h"

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
    u32 unk10;
};

struct UnknownInnerStruct_81C81D4
{
    struct UnknownSubSubStruct_0203CF40 unk0;
    u32 unk10;
    u32 unk14;
    u32 unk18;
    u32 unk1C;
    s32 unk20;
    s32 unk24;
    u32 unk28;
    s32 unk2C;
    u32 unk30;
    void (*unk34)(u32, u8*);
    void (*unk38)(u16, u32, u32);
    struct Sprite *rightArrow;
    struct Sprite *upArrow;
    struct Sprite *downArrow;
    u8 unkTextBuffer[0x40];
};

// Generally at index 0x11 (17)
struct UnknownSubStruct_81C81D4
{
    struct UnknownInnerStruct_81C81D4 unk0;
    u8 tilemapBuffer[0x800];
    struct MatchCallWindowState unk888;
    u32 unk89C;
    u32 unk8A0;
};

extern void sub_81DB620(u32 windowId, u32 a1, u32 a2, u32 a3, u32 a4);

void sub_81C82E4(struct UnknownSubStruct_81C81D4 *a0);
u32 sub_81C91AC(struct UnknownInnerStruct_81C81D4 *a0, const struct BgTemplate *a1, struct MatchCallListTemplate *a2, s32 a3);
void sub_81C9160(struct MatchCallWindowState *a0, struct MatchCallListTemplate *a1);
void SpriteCB_MatchCallUpArrow(struct Sprite *sprite);
void SpriteCB_MatchCallDownArrow(struct Sprite *sprite);
void SpriteCB_MatchCallRightArrow(struct Sprite *sprite);
void ToggleMatchCallArrows(struct UnknownInnerStruct_81C81D4 *a0, u32 a1);
void sub_81C8FE0(struct UnknownInnerStruct_81C81D4 *a0);
void sub_81C8EF8(struct MatchCallWindowState *a0, struct UnknownInnerStruct_81C81D4 *a1);
void sub_81C8ED0(void);
void sub_81C8E54(struct MatchCallWindowState *a0, struct UnknownInnerStruct_81C81D4 *a1, u32 a2);
void PrintMatchCallFieldNames(struct UnknownInnerStruct_81C81D4 *a0, u32 a1);
void sub_81C8D4C(struct MatchCallWindowState *a0, struct UnknownInnerStruct_81C81D4 *a1);
void sub_81C8CB4(struct MatchCallWindowState *a0, struct UnknownInnerStruct_81C81D4 *a1);
void sub_81C8B70(struct UnknownSubSubStruct_0203CF40 *a0, u32 a1, u32 a2);
void sub_81C8568(s32 a0, struct UnknownInnerStruct_81C81D4 *a1);
void sub_81C83AC(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, struct UnknownInnerStruct_81C81D4 *a5);
void sub_81C837C(struct MatchCallWindowState *a0, struct UnknownInnerStruct_81C81D4 *a1);
void sub_81C835C(struct UnknownSubSubStruct_0203CF40 *a0);
u32 LoopedTask_sub_81C8254(s32 a0);
bool32 sub_81C83E0(void);
u32 LoopedTask_sub_81C83F0(s32 a0);
u32 LoopedTask_sub_81C85A0(s32 a0);
u32 LoopedTask_sub_81C8870(s32 a0);
u32 LoopedTask_sub_81C8A28(s32 a0);
u32 LoopedTask_sub_81C8958(s32 a0);

static const u16 sMatchcallArrowPaletteData[] = INCBIN_U16("graphics/pokenav/arrows_matchcall.gbapal");
static const u32 sMatchcallArrowSpriteSheetData[] = INCBIN_U32("graphics/pokenav/arrows_matchcall.4bpp.lz");

static const u8 sPokenavColors_0861FBE4[] =
{
    0, 2, 5
};

static const u8 *const sMatchCallFieldNames[] =
{
    gText_PokenavMatchCall_Strategy,
    gText_PokenavMatchCall_TrainerPokemon,
    gText_PokenavMatchCall_SelfIntroduction
};

static const u8 sMatchCallFieldColors[] =
{
    1, 4, 5
};

static const u8 sUnknown_0861FBF7[] =
{
    2, 4, 6, 7, 0
};

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

EWRAM_DATA u32 gUnknown_0203CF44 = 0;

bool32 sub_81C81D4(const struct BgTemplate *arg0, struct MatchCallListTemplate *arg1, s32 arg2)
{
    u32 v1;
    struct UnknownSubStruct_81C81D4 *structPtr;
    
    structPtr = AllocSubstruct(0x11, sizeof(struct UnknownSubStruct_81C81D4));

    if (structPtr == NULL)
        return FALSE;
    
    sub_81C9160(&structPtr->unk888, arg1);

    v1 = sub_81C91AC(&structPtr->unk0, arg0, arg1, arg2);
    if (v1 == 0)
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
    struct UnknownSubStruct_81C81D4 *structPtr;

    structPtr = GetSubstructPtr(0x11);
    sub_81C8FE0(&structPtr->unk0);
    RemoveWindow(structPtr->unk0.unk0.windowId);
    FreePokenavSubstruct(0x11);
}

u32 LoopedTask_sub_81C8254(s32 a0)
{
    struct UnknownSubStruct_81C81D4 *structPtr;

    if (IsDma3ManagerBusyWithBgCopy())
        return 2;
    
    structPtr = GetSubstructPtr(0x11);

    switch (a0)
    {
        case 0:
            sub_81C82E4(structPtr);
            return 0;
        case 1:
            sub_81C835C(&structPtr->unk0.unk0);
            return 0;
        case 2:
            sub_81C837C(&structPtr->unk888, &structPtr->unk0);
            return 0;
        case 3:
            if (sub_81C83E0())
            {
                return 2;
            }
            else
            {
                sub_81C8ED0();
                return 1;
            }
        case 4:
            sub_81C8EF8(&structPtr->unk888, &structPtr->unk0);
            return 4;
        default:
            return 4;
    }
}

void sub_81C82E4(struct UnknownSubStruct_81C81D4 *a0)
{
    u16 v1 = (a0->unk0.unk0.unk1 << 12) | a0->unk0.unk0.unk6;
    sub_8199DF0(a0->unk0.unk0.bg, PIXEL_FILL(1), a0->unk0.unk0.unk6, 1);
    sub_8199DF0(a0->unk0.unk0.bg, PIXEL_FILL(4), a0->unk0.unk0.unk6 + 1, 1);
    SetBgTilemapBuffer(a0->unk0.unk0.bg, a0->tilemapBuffer);
    FillBgTilemapBufferRect_Palette0(a0->unk0.unk0.bg, v1, 0, 0, 32, 32);
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

void sub_81C837C(struct MatchCallWindowState *a0, struct UnknownInnerStruct_81C81D4 *a1)
{
    s32 v1;
    s32 v2;

    // TODO: Clean this up.
    v1 = a0->listLength - a0->windowTopIndex;
    v2 = a0->visibleEntries;
    if (v1 > a0->visibleEntries)
        v1 = v2;
    sub_81C83AC(a0->unk10, a0->windowTopIndex, v1, a0->unkC, 0, a1);
}

void sub_81C83AC(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, struct UnknownInnerStruct_81C81D4 *a5)
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

u32 LoopedTask_sub_81C83F0(s32 a0)
{
    struct UnknownInnerStruct_81C81D4 *structPtr;
    u32 v1;

    structPtr = &((struct UnknownSubStruct_81C81D4*)GetSubstructPtr(0x11))->unk0;
    switch (a0)
    {
    case 0:
        v1 = (structPtr->unk0.unkA + structPtr->unk0.unkC + structPtr->unk10) & 0xF;
        structPtr->unk34(structPtr->unk1C, structPtr->unkTextBuffer);
        if (structPtr->unk38 != NULL)
            // Accessing unk0.windowId as if it were a u16...?
            // It's accessed as a u8 again in the very next line...
            structPtr->unk38(*(u16*)(&structPtr->unk0.windowId), structPtr->unk14, v1);
        
        AddTextPrinterParameterized(structPtr->unk0.windowId, structPtr->unk0.fontId, structPtr->unkTextBuffer, 8, (v1 << 4) + 1, 255, NULL);
        
        if (++structPtr->unk0.unkC >= structPtr->unk0.unkE)
        {
            if (structPtr->unk38 != NULL)
                CopyWindowToVram(structPtr->unk0.windowId, 3);
            else
                CopyWindowToVram(structPtr->unk0.windowId, 2);
            return 0;
        }
        else
        {
            structPtr->unk1C += structPtr->unk18;
            structPtr->unk14++;
            return 3;
        }
    case 1:
        if (IsDma3ManagerBusyWithBgCopy())
            return 2;
        else
            return 4;
    default:
        return 4;
    }
}

bool32 ShouldShowUpArrow(void)
{
    u16 v1;
    s32 v2;
    struct UnknownSubStruct_81C81D4 *structPtr;
    structPtr = GetSubstructPtr(0x11);

    return structPtr->unk888.windowTopIndex != 0;
}

bool32 ShouldShowDownArrow(void)
{
    struct MatchCallWindowState *subPtr;
    struct UnknownSubStruct_81C81D4 *structPtr;
    structPtr = GetSubstructPtr(0x11);
    subPtr = &structPtr->unk888;
    
    return subPtr->windowTopIndex + subPtr->visibleEntries < subPtr->listLength;
}

void MatchCall_MoveWindow(s32 a0, bool32 a1_)
{
    register bool32 a1 asm("r4")= a1_;
    s32 v1;
    struct UnknownSubStruct_81C81D4 *structPtr = GetSubstructPtr(0x11);
    register struct MatchCallWindowState *subPtr asm("r5") = &structPtr->unk888;

    if (a0 < 0)
    {
        u16 temp = subPtr->windowTopIndex;
        if (temp + a0 < 0)
            v1 = -1 * temp;
        else
            v1 = a0;
        if (a1)
            sub_81C83AC(subPtr->unk10, temp + v1, v1 * -1, subPtr->unkC, v1, &structPtr->unk0);
    }
    else if (a1)
    {
        s32 temp = gUnknown_0203CF44 = subPtr->windowTopIndex + subPtr->visibleEntries;
        s32 listLength;
        if (temp + a0 >= (listLength = subPtr->listLength))
            v1 = listLength - temp;
        else
            v1 = a0;
        
        sub_81C83AC(subPtr->unk10, gUnknown_0203CF44, v1, subPtr->unkC, subPtr->visibleEntries, &structPtr->unk0);
        // Needed to prevent GCC from combining the two sub_81C83AC calls.
        asm("");
    }
    else
    {
        v1 = a0;
    }
    
    sub_81C8568(v1, &structPtr->unk0);
    subPtr->windowTopIndex += v1;
}

void sub_81C8568(s32 a0, struct UnknownInnerStruct_81C81D4 *a1)
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

u32 LoopedTask_sub_81C85A0(s32 a0)
{
    s32 y;
    s32 v1;
    bool32 flag;
    struct UnknownInnerStruct_81C81D4 *structPtr;
    structPtr = &((struct UnknownSubStruct_81C81D4 *)GetSubstructPtr(0x11))->unk0;
    
    switch (a0)
    {
    case 0:
        if (sub_81C83E0() == FALSE)
            return 1;
        else
            return 2;
    case 1:
        flag = FALSE;
        y = GetBgY(structPtr->unk0.bg);
        v1 = ChangeBgY(structPtr->unk0.bg, 0x1000, structPtr->unk30);
        if (structPtr->unk30 == 2)
        {
            if ((y > structPtr->unk24 || y <= structPtr->unk20) && v1 <= structPtr->unk24)
            {
                flag = TRUE;
            }
        }
        else
        {
            if ((y < structPtr->unk24 || y >= structPtr->unk20) && v1 >= structPtr->unk24)
            {
                flag = TRUE;
            }
        }
        if (flag)
        {
            structPtr->unk0.unkA = (structPtr->unk0.unkA + structPtr->unk2C) & 0xF;
            ChangeBgY(structPtr->unk0.bg, structPtr->unk24, 0);
            return 4;
        }
        else
        {
            return 2;
        }
    default:
        return 4;
    }
}

bool32 sub_81C8630(void)
{
    struct UnknownSubStruct_81C81D4 *structPtr;
    structPtr = GetSubstructPtr(0x11);
    return IsLoopedTaskActive(structPtr->unk0.unk28);
}

struct MatchCallWindowState *GetMatchCallWindowStruct(void)
{
    struct UnknownSubStruct_81C81D4 *structPtr;
    structPtr = GetSubstructPtr(0x11);
    return &structPtr->unk888;
}

int MatchCall_MoveCursorUp(void)
{
    struct MatchCallWindowState *structPtr;
    structPtr = GetMatchCallWindowStruct();

    if (structPtr->selectedIndexOffset != 0)
    {
        structPtr->selectedIndexOffset--;
        return 1;
    }
    else
    {
        if (ShouldShowUpArrow())
        {
            MatchCall_MoveWindow(-1, TRUE);
            return 2;
        }
        else
        {
            return 0;
        }
    }
}

int MatchCall_MoveCursorDown(void)
{
    struct MatchCallWindowState *structPtr;
    structPtr = GetMatchCallWindowStruct();

    if (structPtr->windowTopIndex + structPtr->selectedIndexOffset < structPtr->listLength - 1)
    {
        if (structPtr->selectedIndexOffset < structPtr->visibleEntries - 1)
        {
            structPtr->selectedIndexOffset++;
            return 1;
        }
        else if (!ShouldShowDownArrow())
        {
            return 0;
        }
    }
    else
    {
        return 0;
    }
    MatchCall_MoveWindow(1, TRUE);
    return 2;
}

int MatchCall_PageUp(void)
{
    struct MatchCallWindowState *structPtr;
    s32 scroll;
    
    structPtr = GetMatchCallWindowStruct();
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
    else
    {
        return 0;
    }
}

int MatchCall_PageDown(void)
{
    struct MatchCallWindowState *structPtr;
    structPtr = GetMatchCallWindowStruct();

    if (ShouldShowDownArrow())
    {
        s32 scroll;
        s32 windowBottomIndex;
        s32 v3;
        windowBottomIndex = structPtr->windowTopIndex + structPtr->visibleEntries;
        scroll = structPtr->unk4 - structPtr->windowTopIndex;
        if (windowBottomIndex <= structPtr->unk4)
            scroll = structPtr->visibleEntries;
        MatchCall_MoveWindow(scroll, TRUE);
        return 2;
    }
    else
    {
        s32 cursor;
        s32 lastVisibleIndex;
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
        {
            return 0;
        }
        else
        {
            structPtr->selectedIndexOffset = lastVisibleIndex;
            return 1;
        }
    }
}

u32 GetSelectedMatchCall(void)
{
    struct MatchCallWindowState *structPtr;
    structPtr = GetMatchCallWindowStruct();

    return structPtr->windowTopIndex + structPtr->selectedIndexOffset;
}

u32 GetMatchCallListTopIndex(void)
{
    struct MatchCallWindowState *structPtr;
    structPtr = GetMatchCallWindowStruct();
    
    return structPtr->windowTopIndex;
}

void sub_81C877C(void)
{
    struct UnknownSubStruct_81C81D4 *structPtr;
    structPtr = GetSubstructPtr(0x11);
    structPtr->unk89C = 0;
    structPtr->unk8A0 = CreateLoopedTask(LoopedTask_sub_81C8870, 6);
}

void sub_81C87AC(s16 a0)
{
    u16 temp;
    struct UnknownSubStruct_81C81D4 *structPtr;
    structPtr = GetSubstructPtr(0x11);
    temp = structPtr->unk888.windowTopIndex;
    temp += a0;
    structPtr->unk888.windowTopIndex = temp;
    structPtr->unk89C = 0;
    structPtr->unk8A0 = CreateLoopedTask(LoopedTask_sub_81C8958, 6);
}

void sub_81C87F0(void)
{
    struct UnknownSubStruct_81C81D4 *structPtr;
    structPtr = GetSubstructPtr(0x11);
    structPtr->unk89C = 0;
    structPtr->unk8A0 = CreateLoopedTask(LoopedTask_sub_81C8A28, 6);
}

bool32 sub_81C8820(void)
{
    struct UnknownSubStruct_81C81D4 *structPtr;
    structPtr = GetSubstructPtr(0x11);
    return IsLoopedTaskActive(structPtr->unk8A0);
}

void sub_81C8838(void)
{
    struct UnknownSubStruct_81C81D4 *structPtr;
    struct MatchCallWindowState *subStr;
    structPtr = GetSubstructPtr(0x11);
    subStr = &structPtr->unk888;
    structPtr->unk0.unk38(structPtr->unk0.unk0.windowId, subStr->windowTopIndex + subStr->selectedIndexOffset, (structPtr->unk0.unk0.unkA + subStr->selectedIndexOffset) & 0xF);
    CopyWindowToVram(structPtr->unk0.unk0.windowId, 1);
}

u32 LoopedTask_sub_81C8870(s32 a0)
{
    struct UnknownSubStruct_81C81D4 *structPtr;
    u16 v1;
    u32 v2;

    // Needed to fix a register renaming issue.
    register u16* temp asm("r1");
    structPtr = GetSubstructPtr(0x11);

    switch (a0)
    {
    case 0:
        ToggleMatchCallArrows(&structPtr->unk0, 1);
        // fall-through
    case 1:
        if (structPtr->unk89C != structPtr->unk888.selectedIndexOffset)
            sub_81C8B70(&structPtr->unk0.unk0, structPtr->unk89C, 1);
        
        structPtr->unk89C++;
        return 0;
    case 2:
        if (IsDma3ManagerBusyWithBgCopy())
            return 2;
        
        if (structPtr->unk89C != structPtr->unk888.visibleEntries)
            return 6;
        
        if (structPtr->unk888.selectedIndexOffset != 0)
            sub_81C8B70(&structPtr->unk0.unk0, structPtr->unk89C, structPtr->unk888.selectedIndexOffset);
        
        return 0;
    case 3:
        if (IsDma3ManagerBusyWithBgCopy())
            return 2;
        temp = &structPtr->unk888.selectedIndexOffset;
        v1 = *temp;
        if (v1 == 0)
            return 4;
        
        MatchCall_MoveWindow(v1, FALSE);
        return 0;
    case 4:
         v2 = sub_81C8630();
         if (v2)
            return 2;

        structPtr->unk888.selectedIndexOffset = v2;
        return 4;
    default:
        return 4;
    }
}

u32 LoopedTask_sub_81C8958(s32 a0)
{
    struct UnknownSubStruct_81C81D4 *structPtr;
    structPtr = GetSubstructPtr(0x11);
    if (IsDma3ManagerBusyWithBgCopy())
        return 2;
    
    switch (a0)
    {
    case 0:
        sub_81C8CB4(&structPtr->unk888, &structPtr->unk0);
        break;
    case 1:
        PrintMatchCallFieldNames(&structPtr->unk0, 0);
        break;
    case 2:
        sub_81C8E54(&structPtr->unk888, &structPtr->unk0, 0);
        break;
    case 3:
        PrintMatchCallFieldNames(&structPtr->unk0, 1);
        break;
    case 4:
        sub_81C8E54(&structPtr->unk888, &structPtr->unk0, 1);
        break;
    case 5:
        PrintMatchCallFieldNames(&structPtr->unk0, 2);
        break;
    case 6:
        sub_81C8E54(&structPtr->unk888, &structPtr->unk0, 2);
        break;
    case 7:
        sub_81C8E54(&structPtr->unk888, &structPtr->unk0, 3);
        break;
    default:
        return 4;
    }
    return 0;
}

u32 LoopedTask_sub_81C8A28(s32 a0)
{
    struct UnknownSubStruct_81C81D4 *structPtr;
    struct MatchCallWindowState *subPtr888;
    register struct UnknownInnerStruct_81C81D4 *subPtr0 asm("r2");
    s32 v4;

    if (IsDma3ManagerBusyWithBgCopy())
    {
        return 2;
    }
    
    structPtr = GetSubstructPtr(0x11);
    subPtr888 = &structPtr->unk888;
    subPtr0 = &structPtr->unk0;

    switch (a0)
    {
    default:
        return 4;
    case 0:
        sub_81C8D4C(subPtr888, subPtr0);
        return 0;
    case 1:
    {
        s32 v1;
        s32 v2;
        u32 *v3;
        register s32 v4 asm("r5");

        v3 = &structPtr->unk89C;
        v1 = *v3 + 1;
        *v3 = v1;
        if (v1 < structPtr->unk888.visibleEntries)
        {
            sub_81C8B70(&subPtr0->unk0, v1, 1);
            return 2;
        }

        *v3 = 0;
        if (subPtr888->listLength <= subPtr888->visibleEntries)
        {
            register u32 temp asm("r0");
            temp = subPtr888->windowTopIndex;
            if (temp == 0)
                return 9;
            v2 = temp;
        }
        else
        {
            register s32 temp asm("r1");
            v2 = subPtr888->windowTopIndex + subPtr888->visibleEntries;
            temp = (s32)subPtr888->listLength;
            if (v2 <= temp)
                return 9;
            v2 -= temp;
        }
        v4 = v2 * -1;
        sub_81C8B70(&subPtr0->unk0, v4, v2);
        subPtr888->selectedIndexOffset = v2;
        *v3 = v4;
        return 0;
    }
    case 2:
        MatchCall_MoveWindow(structPtr->unk89C, FALSE);
        return 0;
    case 3:
        if (sub_81C8630())
            return 2;
        
        structPtr->unk89C = 0;
        return 1;
    case 4:
        sub_81C83AC(subPtr888->unk10, subPtr888->windowTopIndex + structPtr->unk89C, 1, subPtr888->unkC, structPtr->unk89C, &structPtr->unk0);
        return 0;
    case 5:
        if (sub_81C83E0())
            return 2;
        
        v4 = ++structPtr->unk89C;
        if (v4 >= subPtr888->listLength || v4 >= subPtr888->visibleEntries)
            return 1;
        return 9;
    case 6:
        ToggleMatchCallArrows(subPtr0, 0);
        return 4;
    }
}

void sub_81C8B70(struct UnknownSubSubStruct_0203CF40 *a0, u32 a1, u32 a2)
{
    u8 *v1;
    u32 v2;

    v1 = (u8*)GetWindowAttribute(a0->windowId, WINDOW_TILE_DATA);
    v2 = a0->unk4 * 64;

    a1 = (a0->unkA + a1) & 0xF;
    if ((s32)(a1 + a2) <= 16)
    {
        CpuFastFill8(PIXEL_FILL(1), v1 + a1 * v2, a2 * v2);
        CopyWindowToVram(a0->windowId, 2);
    }
    else
    {
        u32 v3;
        u32 v4;

        v3 = 16 - a1;
        v4 = a2 - v3;

        CpuFastFill8(PIXEL_FILL(1), v1 + a1 * v2, v3 * v2);
        CpuFastFill8(PIXEL_FILL(1), v1, v4 * v2);
        CopyWindowToVram(a0->windowId, 2);
    }

    a2 -= 1;
    for (a2; a2 != -1; a1 = (a1 + 1) & 0xF, a2--)
    {
        sub_81CBD48(a0->windowId, a1);
    }

    CopyWindowToVram(a0->windowId, 1);
}

void sub_81C8C64(struct UnknownSubSubStruct_0203CF40 *a0, u32 a1)
{
    u16 *v1;
    register u32 v2 asm("r0");
    u32 v3;

    v1 = (u16*)GetBgTilemapBuffer(GetWindowAttribute(a0->windowId, WINDOW_BG));

    v1 = &v1[(a0->unkA << 6) + a0->unk2 - 1];

    if (a1 != 0)
    {
        v2 = a0->unk1 << 12;
        v3 = a0->unk6 + 1;
    }
    else
    {
        v2 = a0->unk1 << 12;
        v3 = a0->unk6;
    }
    {
        register u16 v5 asm("r1");
        register u32 v6 asm("r0");
        v6 = (v3 | v2);
        v6 = v6 << 16;
        v5 = v6 >> 16;
        v1[0] = v5;
        v1[0x20] = v5;
    }
}

void sub_81C8CB4(struct MatchCallWindowState *a0, struct UnknownInnerStruct_81C81D4 *a1)
{
    u8 colors[3];


    memcpy(colors, sPokenavColors_0861FBE4, ARRAY_COUNT(sPokenavColors_0861FBE4));

    a1->unk34(a0->unk10 + a0->unkC * a0->windowTopIndex, a1->unkTextBuffer);
    a1->unk38(a1->unk0.windowId, a0->windowTopIndex, a1->unk0.unkA);
    FillWindowPixelRect(a1->unk0.windowId, PIXEL_FILL(4), 0, a1->unk0.unkA * 16, a1->unk0.unk4 * 8, 16);
    AddTextPrinterParameterized3(a1->unk0.windowId, a1->unk0.fontId, 8, (a1->unk0.unkA * 16) + 1, colors, TEXT_SPEED_FF, a1->unkTextBuffer);
    sub_81C8C64(&a1->unk0, 1);
    CopyWindowRectToVram(a1->unk0.windowId, 3, 0, a1->unk0.unkA * 2, a1->unk0.unk4, 2);
}

void sub_81C8D4C(struct MatchCallWindowState *a0, struct UnknownInnerStruct_81C81D4 *a1)
{
    a1->unk34(a0->unk10 + a0->unkC * a0->windowTopIndex, a1->unkTextBuffer);
    FillWindowPixelRect(a1->unk0.windowId, PIXEL_FILL(1), 0, a1->unk0.unkA * 16, a1->unk0.unk4 * 8, 16);
    AddTextPrinterParameterized(a1->unk0.windowId, a1->unk0.fontId, a1->unkTextBuffer, 8, a1->unk0.unkA * 16 + 1, TEXT_SPEED_FF, NULL);
    sub_81C8C64(&a1->unk0, 0);
    CopyWindowToVram(a1->unk0.windowId, 3);
}

void PrintMatchCallFieldNames(struct UnknownInnerStruct_81C81D4 *a0, u32 fieldId)
{
    const u8 *fieldNames[3];
    u8 colors[3];
    u32 r4;
    u32 r5;
    u32 tmp;
    u32 one;

    memcpy(fieldNames, sMatchCallFieldNames, sizeof(sMatchCallFieldNames));
    memcpy(colors, sMatchCallFieldColors, sizeof(sMatchCallFieldColors));

    r4 = a0->unk0.unkA;
    tmp = fieldId * 2 + 1;
    r4 += tmp;
    r4 &= 0xF;
    FillWindowPixelRect(a0->unk0.windowId, PIXEL_FILL(1), 0, r4 << 4, a0->unk0.unk4, 16);
    
    // This is a fake match. It should be this:
    // AddTextPrinterParameterized3(a0->unk0.windowId, 7, 2, r4 << 4 + 1, colors, TEXT_SPEED_FF, fieldNames[fieldId]);
    // But the original GCC does some clever reuse of the `1` constant that the current GCC doesn't.
    one = 1;
    AddTextPrinterParameterized3(a0->unk0.windowId, 7, 2, (r4 << 4) + one, colors, one - 2, fieldNames[fieldId]);
    CopyWindowRectToVram(a0->unk0.windowId, 2, 0, r4 << 1, a0->unk0.unk4, 2);
}

void sub_81C8E54(struct MatchCallWindowState *a0, struct UnknownInnerStruct_81C81D4 *a1, u32 a2)
{
    const u8 *str;
    u32 r6;

    r6 = (a1->unk0.unkA + sUnknown_0861FBF7[a2]) & 0xF;

    str = sub_81CAFD8(a0->windowTopIndex, a2);
    if (str != NULL) {
        sub_81DB620(a1->unk0.windowId, 1, r6 * 2, a1->unk0.unk4 - 1, 2);
        AddTextPrinterParameterized(a1->unk0.windowId, 7, str, 2, (r6 << 4) + 1, TEXT_SPEED_FF, NULL);
        CopyWindowRectToVram(a1->unk0.windowId, 2, 0, r6 * 2, a1->unk0.unk4, 2);
    }
}

void sub_81C8ED0(void)
{
    u32 i;
    const struct CompressedSpriteSheet *ptr;
    
    for (i = 0, ptr = sMatchcallArrowSpriteSheets; i < ARRAY_COUNT(sMatchcallArrowSpriteSheets); ptr++, i++)
    {
        LoadCompressedSpriteSheet(ptr);
    }
    Pokenav_AllocAndLoadPalettes(sMatchcallArrowPalettes);
}

void sub_81C8EF8(struct MatchCallWindowState *a0, struct UnknownInnerStruct_81C81D4 *a1)
{
    register u32 spriteId asm("r3");
    s16 temp;

    spriteId = (u8)CreateSprite(&sMatchCallRightArrowSprite, a1->unk0.unk2 * 8 + 3, (a1->unk0.unk3 + 1) * 8, 7);
    a1->rightArrow = &gSprites[spriteId];

    temp = a1->unk0.unk2 * 8 + (a1->unk0.unk4 - 1) * 4;
    spriteId = (u8)CreateSprite(&sMatchCallUpDownArrowSprite, temp, a1->unk0.unk3 * 8 + a0->visibleEntries * 16, 7);
    a1->downArrow = &gSprites[spriteId];
    a1->downArrow->oam.tileNum += 2;
    a1->downArrow->callback = SpriteCB_MatchCallDownArrow;

    spriteId = (u8)CreateSprite(&sMatchCallUpDownArrowSprite, temp, a1->unk0.unk3 * 8, 7);
    a1->upArrow = &gSprites[spriteId];
    a1->upArrow->oam.tileNum += 4;
    a1->upArrow->callback = SpriteCB_MatchCallUpArrow;
}

void sub_81C8FE0(struct UnknownInnerStruct_81C81D4 *a0)
{
    DestroySprite(a0->rightArrow);
    DestroySprite(a0->upArrow);
    DestroySprite(a0->downArrow);
    FreeSpriteTilesByTag(0xA);
    FreeSpritePaletteByTag(0x14);
}

void ToggleMatchCallArrows(struct UnknownInnerStruct_81C81D4 *a0, bool32 shouldHide)
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
    struct UnknownSubStruct_81C81D4 *structPtr;
    structPtr = GetSubstructPtr(0x11);
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
    struct UnknownSubStruct_81C81D4 *structPtr;
    structPtr = GetSubstructPtr(0x11);
    structPtr->unk0.upArrow->data[7] = shouldHide;
    structPtr->unk0.downArrow->data[7] = shouldHide;
}

void sub_81C9160(struct MatchCallWindowState *a0, struct MatchCallListTemplate *a1)
{
    u32 unused1 = a0->unk10 = a1->unk0;
    u32 v0 = a1->unk6;
    u32 zero = 0;
    u32 unused2 = a0->windowTopIndex = v0;
    u32 v1 = a0->listLength = a1->unk4;

    a0->unkC = a1->unk8;
    a0->visibleEntries = a1->unkC;
    if (a0->visibleEntries >= (u16)v1)
    {
        a0->windowTopIndex = 0;
        a0->unk4 = 0;
        a0->selectedIndexOffset = v0; 
    }
    else
    {
        s32 v2;
        a0->unk4 = a0->listLength - a0->visibleEntries;
        v2 = a0->windowTopIndex + a0->visibleEntries;
        if (v2 > a0->listLength) {
            a0->selectedIndexOffset = v2 - a0->listLength;
            a0->windowTopIndex = v0 - a0->selectedIndexOffset;
        }
        else
        {
            a0->selectedIndexOffset = 0;
        }
    }
}

u32 sub_81C91AC(struct UnknownInnerStruct_81C81D4 *a0, const struct BgTemplate *a1, struct MatchCallListTemplate *a2, s32 a3)
{
    register u32 raw_bg asm("r4") = ((a1->bg) << 30);
    u8 bg = raw_bg >> 30;
    u32 unknown = 0;
    struct WindowTemplate window;
    u8 bg_again;

    a0->unk0.bg = bg;
    a0->unk0.unk6 = a3;
    a0->unk34 = a2->unk10;
    a0->unk38 = a2->unk14;
    a0->unk0.unk1 = a2->unkD;
    a0->unk0.unk2 = a2->unk9;
    a0->unk0.unk3 = a2->unkB;
    a0->unk0.unk4 = a2->unkA;
    a0->unk0.fontId = a2->unkE;
    
    window.bg = raw_bg >> 30;
    window.tilemapLeft = a2->unk9;
    window.tilemapTop = 0;
    window.width = a2->unkA;
    window.height = 32;
    window.paletteNum = a2->unkD;
    window.baseBlock = a3 + 2;

    a0->unk0.windowId = AddWindow(&window);
    if (a0->unk0.windowId == 0xFF)
    {
        return 0;
    }
    else
    {
        a0->unk0.unkA = unknown;
        a0->rightArrow = NULL;
        a0->upArrow = NULL;
        a0->downArrow = NULL;
        return 1;
    }
}
