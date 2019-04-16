#include "global.h"
#include "bg.h"
#include "menu.h"
#include "pokenav.h"
#include "sound.h"
#include "window.h"
#include "constants/songs.h"

struct Pokenav4Struct
{
    u32 (*unk0)(void);
    u32 unk4;
    u8 filler8[0x8];
    u8 unk10;
    u8 filler11[0x1];
    u8 unk12;
    u8 filler13[0x1];
    u8 unk14;
    u8 filler15[0x4];
    u8 unk19;
    u8 filler1A[0xA];
    u8 unk24[0x800];
    u8 unk824[0x800];
    u8 unk1024[0x800];
    u8 unk1824[0x824];
};

static bool32 sub_81CB310(void);
static u32 sub_81CB324(int);
void sub_81CBC1C(void);
void sub_81CC2B4(void);
void sub_81CC034(struct Pokenav4Struct *);
void sub_81CBBB8(void);
void sub_81CBD78(struct Pokenav4Struct *);
void sub_81CBDC0(struct Pokenav4Struct *);
void sub_81CBEF8(struct Pokenav4Struct *, int);
void sub_81CC214(void);
void sub_81CBC38(int);

extern const LoopedTask gUnknown_08622798[];
extern const struct BgTemplate gUnknown_0862278C[3];
extern const u16 gUnknown_08622510[];
extern const u32 gUnknown_08622530[];
extern const u32 gUnknown_08622760[];
extern const u16 gUnknown_08622700[];
extern const u16 gUnknown_08622720[];
extern const u8 gUnknown_086225D4[];
extern const u16 gUnknown_086226E0[];

bool32 sub_81CB260(void)
{
    struct Pokenav4Struct *state = AllocSubstruct(6, sizeof(struct Pokenav4Struct));
    if (!state)
        return FALSE;

    state->unk19 = 0;
    state->unk4 = CreateLoopedTask(sub_81CB324, 1);
    state->unk0 = sub_81CB310;
    return TRUE;
}

void sub_81CB29C(int index)
{
    struct Pokenav4Struct *state = GetSubstructPtr(6);
    state->unk4 = CreateLoopedTask(gUnknown_08622798[index], 1);
    state->unk0 = sub_81CB310;
}

u32 sub_81CB2CC(void)
{
    struct Pokenav4Struct *state = GetSubstructPtr(6);
    return state->unk0();
}

void sub_81CB2E0(void)
{
    struct Pokenav4Struct *state = GetSubstructPtr(6);
    sub_81CC2B4();
    sub_81CBC1C();
    RemoveWindow(state->unk12);
    RemoveWindow(state->unk10);
    RemoveWindow(state->unk14);
    FreePokenavSubstruct(6);
}

static bool32 sub_81CB310(void)
{
    struct Pokenav4Struct *state = GetSubstructPtr(6);
    return IsLoopedTaskActive(state->unk4);
}

static u32 sub_81CB324(int taskState)
{
    struct Pokenav4Struct *state = GetSubstructPtr(6);
    switch (taskState)
    {
    case 0:
        InitBgTemplates(gUnknown_0862278C, ARRAY_COUNT(gUnknown_0862278C));
        ChangeBgX(2, 0, 0);
        ChangeBgY(2, 0, 0);
        decompress_and_copy_tile_data_to_vram(2, gUnknown_08622530, 0, 0, 0);
        SetBgTilemapBuffer(2, state->unk1024);
        CopyToBgTilemapBuffer(2, gUnknown_086225D4, 0, 0);
        CopyBgTilemapBufferToVram(2);
        CopyPaletteIntoBufferUnfaded(gUnknown_08622510, 0x20, 0x20);
        CopyBgTilemapBufferToVram(2);
        return 0;
    case 1:
        if (free_temp_tile_data_buffers_if_possible())
            return 2;

        sub_8199DF0(1, 0, 0, 1);
        SetBgTilemapBuffer(1, state->unk24);
        FillBgTilemapBufferRect_Palette0(1, 0x1000, 0, 0, 32, 20);
        CopyPaletteIntoBufferUnfaded(gUnknown_086226E0, 0x10, 0x20);
        CopyBgTilemapBufferToVram(1);
        return 0;
    case 2:
        if (free_temp_tile_data_buffers_if_possible())
            return 2;

        sub_81CC034(state);
        decompress_and_copy_tile_data_to_vram(3, gUnknown_08622760, 0, 0, 0);
        CopyPaletteIntoBufferUnfaded(gUnknown_08622700, 0x30, 0x20);
        CopyPaletteIntoBufferUnfaded(gUnknown_08622720, 0x50, 0x20);
        return 0;
    case 3:
        if (free_temp_tile_data_buffers_if_possible() || !sub_81CAE28())
            return 2;

        sub_81CBBB8();
        return 0;
    case 4:
        if (sub_81C8224())
            return 2;

        sub_81CBD78(state);
        return 0;
    case 5:
        sub_81CBDC0(state);
        sub_81CBEF8(state, 0);
        return 0;
    case 6:
        ChangeBgX(1, 0, 0);
        ChangeBgY(1, 0, 0);
        ShowBg(2);
        ShowBg(3);
        ShowBg(1);
        sub_81CC214();
        LoadLeftHeaderGfxForIndex(3);
        sub_81C7FA0(3, 1, 0);
        sub_81C7AC0(1);
        return 0;
    case 7:
        if (IsPaletteFadeActive() || sub_81C8010())
            return 2;

        sub_81CBC38(1);
        return 4;
    default:
        return 4;
    }
}

u32 sub_81CB510(int taskState)
{
    struct Pokenav4Struct *state = GetSubstructPtr(6);
    switch (taskState)
    {
    case 0:
        switch (MatchCall_MoveCursorDown())
        {
            case 0:
                break;
            case 1:
                PlaySE(SE_SELECT);
                return 7;
            case 2:
                PlaySE(SE_SELECT);
                // fall through
            default:
                return 0;
        }
        break;
    case 1:
        if (sub_81C8630())
            return 2;

        sub_81CBEF8(state, 0);
        return 0;
    case 2:
        sub_81CBEF8(state, 0);
        return 0;
    case 3:
        if (IsDma3ManagerBusyWithBgCopy())
            return 2;
        break;
    }
    return 4;
}

u32 sub_81CB588(int taskState)
{
    struct Pokenav4Struct *state = GetSubstructPtr(6);
    switch (taskState)
    {
    case 0:
        switch (MatchCall_MoveCursorUp())
        {
            case 0:
                break;
            case 1:
                PlaySE(SE_SELECT);
                return 7;
            case 2:
                PlaySE(SE_SELECT);
                // fall through
            default:
                return 0;
        }
        break;
    case 1:
        if (sub_81C8630())
            return 2;

        sub_81CBEF8(state, 0);
        return 0;
    case 2:
        sub_81CBEF8(state, 0);
        return 0;
    case 3:
        if (IsDma3ManagerBusyWithBgCopy())
            return 2;
        break;
    }
    return 4;
}

u32 sub_81CB600(int taskState)
{
    struct Pokenav4Struct *state = GetSubstructPtr(6);
    switch (taskState)
    {
    case 0:
        switch (MatchCall_PageDown())
        {
            case 0:
                break;
            case 1:
                PlaySE(SE_SELECT);
                return 7;
            case 2:
                PlaySE(SE_SELECT);
                // fall through
            default:
                return 0;
        }
        break;
    case 1:
        if (sub_81C8630())
            return 2;

        sub_81CBEF8(state, 0);
        return 0;
    case 2:
        sub_81CBEF8(state, 0);
        return 0;
    case 3:
        if (IsDma3ManagerBusyWithBgCopy())
            return 2;
        break;
    }
    return 4;
}

u32 sub_81CB678(int taskState)
{
    struct Pokenav4Struct *state = GetSubstructPtr(6);
    switch (taskState)
    {
    case 0:
        switch (MatchCall_PageUp())
        {
            case 0:
                break;
            case 1:
                PlaySE(SE_SELECT);
                return 7;
            case 2:
                PlaySE(SE_SELECT);
                // fall through
            default:
                return 0;
        }
        break;
    case 1:
        if (sub_81C8630())
            return 2;

        sub_81CBEF8(state, 0);
        return 0;
    case 2:
        sub_81CBEF8(state, 0);
        return 0;
    case 3:
        if (IsDma3ManagerBusyWithBgCopy())
            return 2;
        break;
    }
    return 4;
}
