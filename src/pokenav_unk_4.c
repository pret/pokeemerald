#include "global.h"
#include "bg.h"
#include "data.h"
#include "decompress.h"
#include "dma3.h"
#include "international_string_util.h"
#include "main.h"
#include "match_call.h"
#include "menu.h"
#include "overworld.h"
#include "palette.h"
#include "pokenav.h"
#include "region_map.h"
#include "sound.h"
#include "sprite.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"
#include "text.h"
#include "text_window.h"
#include "trig.h"
#include "window.h"
#include "constants/game_stat.h"
#include "constants/region_map_sections.h"
#include "constants/songs.h"
#include "constants/species.h"

struct Pokenav4Struct
{
    bool32 (*unk0)(void);
    u32 unk4;
    u8 filler8[0x6];
    u8 unkE;
    u8 unkF;
    u16 unk10;
    u16 unk12;
    u16 unk14;
    s16 unk16;
    u8 unused18;
    u8 unk19;
    u16 unk1A;
    struct Sprite *unk1C;
    struct Sprite *unk20;
    u8 unk24[0x800];
    u8 unk824[0x800];
    u8 unk1024[0x800];
    u8 *unk1824;
    u8 unk1828[0x800];
    u8 unk2028[0x20];
};

static bool32 sub_81CB310(void);
static u32 sub_81CB324(int);
static void sub_81CBBB8(void);
static void sub_81CBC1C(void);
static void sub_81CC2B4(void);
static void sub_81CC034(struct Pokenav4Struct *);
static void sub_81CBD78(struct Pokenav4Struct *);
static void sub_81CBDC0(struct Pokenav4Struct *);
static void sub_81CBEF8(struct Pokenav4Struct *, int);
static void sub_81CC214(void);
static void sub_81CBC38(int);
static void sub_81CBF60(struct Pokenav4Struct *);
static bool32 sub_81CBFC4(struct Pokenav4Struct *);
static void sub_81CC344(struct Pokenav4Struct *, int);
static bool32 sub_81CC004(struct Pokenav4Struct *);
static void sub_81CBFF0(struct Pokenav4Struct *);
static void sub_81CC058(struct Pokenav4Struct *);
static bool32 sub_81CC0D0(struct Pokenav4Struct *);
static void sub_81CC0E0(struct Pokenav4Struct *);
static bool32 sub_81CC104(struct Pokenav4Struct *);
static void sub_81CC158(struct Pokenav4Struct *);
static bool32 sub_81CC194(struct Pokenav4Struct *);
static void sub_81CC09C(struct Pokenav4Struct *);
static void sub_81CC11C(struct Pokenav4Struct *);
static bool32 sub_81CC140(struct Pokenav4Struct *);
static void sub_81CC1DC(struct Pokenav4Struct *);
static bool32 sub_81CC204(struct Pokenav4Struct *);
static void sub_81CC014(struct Pokenav4Struct *);
static void sub_81CC39C(struct Pokenav4Struct *);
static bool32 sub_81CC42C(struct Pokenav4Struct *);
static void sub_81CC420(struct Pokenav4Struct *);
static void sub_81CBC64(u8 taskId);
static void sub_81CBCEC(u16 windowId, u32, u32);
static void sub_81CBDF4(u16 windowId);
static void sub_81CBE0C(u16 windowId);
static void sub_81CBE38(u16 windowId);
static void sub_81CBE50(u16 windowId);
static void sub_81CBE88(u16 windowId, const u8 *str, int top);
static void sub_81CBEB4(u16 windowId, const u8 *str, int top);
static void sub_81CC2F0(struct Pokenav4Struct *, int);
static void sub_81CC330(struct Pokenav4Struct *);
static struct Sprite *sub_81CC370(void);
static void sub_81CC440(struct Sprite *sprite);
static void sub_81CC4A4(struct Sprite *sprite);

extern const LoopedTask gUnknown_08622798[];
extern const struct BgTemplate gUnknown_0862278C[3];
extern const u16 gUnknown_08622510[];
extern const u32 gUnknown_08622530[];
extern const u32 gUnknown_08622760[];
extern const u16 gUnknown_08622700[];
extern const u16 gUnknown_08622720[];
extern const u8 gUnknown_086225D4[];
extern const u16 gUnknown_086226E0[];
extern const struct BgTemplate gUnknown_08622794;
extern const struct WindowTemplate gUnknown_086227D8;
extern const struct WindowTemplate gUnknown_086227E0;
extern const u8 *const gUnknown_086227E8[];
extern const struct WindowTemplate gUnknown_08622808;
extern const u8 gUnknown_086227F4[];
extern const struct CompressedSpriteSheet gUnknown_08622810[1];
extern const struct SpritePalette gUnknown_08622818[];
extern const struct SpriteTemplate gUnknown_08622830;
extern const struct SpriteTemplate gUnknown_08622850;

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

u32 sub_81CB6F0(int taskState)
{
    struct Pokenav4Struct *state = GetSubstructPtr(6);
    switch (taskState)
    {
    case 0:
        PlaySE(SE_SELECT);
        sub_81CBF60(state);
        sub_81C7BA4(7);
        return 0;
    case 1:
        if (sub_81CBFC4(state))
            return 2;
        break;
    }

    return 4;
}

u32 sub_81CB734(int taskState)
{
    struct Pokenav4Struct *state;
    u16 var0;

    PlaySE(SE_SELECT);
    state = GetSubstructPtr(6);
    var0 = sub_81CB01C();
    sub_81CC344(state, var0);
    return 4;
}

u32 sub_81CB75C(int taskState)
{
    struct Pokenav4Struct *state = GetSubstructPtr(6);
    switch (taskState)
    {
    case 0:
        PlaySE(SE_SELECT);
        sub_81CBFF0(state);
        sub_81C7BA4(6);
        return 0;
    case 1:
        if (sub_81CC004(state))
            return 2;
        break;
    }

    return 4;
}

u32 sub_81CB7A0(int taskState)
{
    struct Pokenav4Struct *state = GetSubstructPtr(6);
    switch (taskState)
    {
    case 0:
        ToggleMatchCallVerticalArrows(TRUE);
        sub_81CC058(state);
        return 0;
    case 1:
        if (sub_81CC0D0(state))
            return 2;

        sub_81CC0E0(state);
        PlaySE(SE_TOREEYE);
        state->unkE = 0;
        return 0;
    case 2:
        if (sub_81CC104(state))
            return 2;

        sub_81CC158(state);
        return 0;
    case 3:
        if (sub_81CC194(state))
            return 2;
        break;
    }

    return 4;
}

u32 sub_81CB824(int taskState)
{
    struct Pokenav4Struct *state = GetSubstructPtr(6);
    switch (taskState)
    {
    case 0:
        PlaySE(SE_SELECT);
        sub_81CC09C(state);
        ToggleMatchCallVerticalArrows(TRUE);
        state->unkE = 1;
        return 0;
    case 1:
        if (sub_81CC0D0(state))
            return 2;

        sub_81CC11C(state);
        return 0;
    case 2:
        if (sub_81CC140(state))
            return 2;
        break;
    }

    return 4;
}

u32 sub_81CB888(int taskState)
{
    struct Pokenav4Struct *state = GetSubstructPtr(6);
    u32 result = 0;

    switch (taskState)
    {
    case 0:
        if (!state->unkE)
            PlaySE(SE_TOREOFF);

        PlaySE(SE_SELECT);
        break;
    case 1:
        sub_81CC1DC(state);
        break;
    case 2:
        if (sub_81CC204(state))
            result = 2;
        break;
    case 3:
        sub_81CBFF0(state);
        break;
    case 4:
        if (sub_81CC004(state))
            result = 2;

        sub_81C7BA4(6);
        break;
    case 5:
        if (IsDma3ManagerBusyWithBgCopy_())
        {
            result = 2;
        }
        else
        {
            if (state->unkF)
            {
                sub_81C8838();
                result = 1;
            }
            else
            {
                ToggleMatchCallVerticalArrows(FALSE);
                result = 4;
            }
        }
        break;
    case 6:
        if (IsDma3ManagerBusyWithBgCopy())
        {
            result = 2;
        }
        else
        {
            ToggleMatchCallVerticalArrows(FALSE);
            result = 4;
        }
        break;
    }

    return result;
}

u32 sub_81CB93C(int taskState)
{
    struct Pokenav4Struct *state = GetSubstructPtr(6);
    switch (taskState)
    {
    case 0:
        PlaySE(SE_SELECT);
        sub_81C877C();
        sub_81CC014(state);
        return 0;
    case 1:
        if (sub_81C8820() || sub_81CC004(state))
            return 2;

        sub_81C7BA4(8);
        return 0;
    case 2:
        sub_81C87AC(0);
        sub_81CC39C(state);
        return 0;
    case 3:
        if (sub_81C8820() || sub_81CC42C(state) || IsDma3ManagerBusyWithBgCopy_())
            return 2;
        break;
    }

    return 4;
}

u32 sub_81CB9C8(int taskState)
{
    int index;
    int var0;
    struct Pokenav4Struct *state = GetSubstructPtr(6);
    switch (taskState)
    {
    case 0:
        index = GetMatchCallListTopIndex();
        var0 = sub_81CB0E4(index);
        if (var0)
        {
            PlaySE(SE_SELECT);
            state->unk16 = var0;
            sub_81CC420(state);
            return 0;
        }
        break;
    case 1:
        if (sub_81CC42C(state))
            return 2;

        sub_81CBEF8(state, state->unk16);
        return 0;
    case 2:
        sub_81C87AC(state->unk16);
        return 0;
    case 3:
        sub_81CC39C(state);
        return 0;
    case 4:
        if (sub_81C8820() || sub_81CC42C(state))
            return 2;
        break;
    }

    return 4;
}

u32 sub_81CBA68(int taskState)
{
    struct Pokenav4Struct *state = GetSubstructPtr(6);
    switch (taskState)
    {
    case 0:
        PlaySE(SE_SELECT);
        sub_81CC420(state);
        sub_81C87F0();
        return 0;
    case 1:
        if (sub_81C8820() || sub_81CC42C(state))
            return 2;

        sub_81C7BA4(6);
        sub_81CBDC0(state);
        return 0;
    case 2:
        if (IsDma3ManagerBusyWithBgCopy())
            return 2;
        break;
    }

    return 4;
}

u32 sub_81CBAD4(int taskState)
{
    int index;
    int var0;
    struct Pokenav4Struct *state = GetSubstructPtr(6);
    switch (taskState)
    {
    case 0:
        index = GetMatchCallListTopIndex();
        var0 = sub_81CB128(index);
        if (var0)
        {
            PlaySE(SE_SELECT);
            state->unk16 = var0;
            sub_81CC420(state);
            return 0;
        }
        break;
    case 1:
        if (sub_81CC42C(state))
            return 2;

        sub_81CBEF8(state, state->unk16);
        return 0;
    case 2:
        sub_81C87AC(state->unk16);
        return 0;
    case 3:
        sub_81CC39C(state);
        return 0;
    case 4:
        if (sub_81C8820() || sub_81CC42C(state))
            return 2;
        break;
    }

    return 4;
}

u32 sub_81CBB74(int taskState)
{
    switch (taskState)
    {
    case 0:
        PlaySE(SE_SELECT);
        sub_81CBC38(0);
        sub_81C7AC0(0);
        sub_81C78A0();
        return 0;
    case 1:
        if (IsPaletteFadeActive() || MainMenuLoopedTaskIsBusy())
            return 2;

        sub_81C7FDC();
        break;
    }

    return 4;
}

static void sub_81CBBB8(void)
{
    struct MatchCallListTemplate template;
    template.unk0 = (u32)sub_81CAE94();
    template.unk4 = sub_81CAE38();
    template.unk8 = 4;
    template.unk6 = 0;
    template.unk9 = 13;
    template.unkA = 16;
    template.unkB = 1;
    template.unkC = 8;
    template.unkD = 3;
    template.unkE = 7;
    template.unk10 = sub_81CB050;
    template.unk14 = sub_81CBCEC;
    sub_81C81D4(&gUnknown_08622794, &template, 2);
    CreateTask(sub_81CBC64, 7);
}

static void sub_81CBC1C(void)
{
    sub_81C8234();
    DestroyTask(FindTaskIdByFunc(sub_81CBC64));
}

static void sub_81CBC38(int arg0)
{
    u8 taskId = FindTaskIdByFunc(sub_81CBC64);
    if (taskId != 0xFF)
        gTasks[taskId].data[15] = arg0;
}

static void sub_81CBC64(u8 taskId)
{
    s16 *taskData = gTasks[taskId].data;
    if (taskData[15])
    {
        taskData[0] += 4;
        taskData[0] &= 0x7F;
        taskData[1] = gSineTable[taskData[0]] >> 4;
        sub_81C79BC(gUnknown_08622720, gUnknown_08622720 + 0x10, 0x10, 0x10, taskData[1], gPlttBufferUnfaded + 0x50);
        if (!gPaletteFade.active)
            CpuCopy32(gPlttBufferUnfaded + 0x50, gPlttBufferFaded + 0x50, 0x20);
    }
}

static void sub_81CBCEC(u16 windowId, u32 arg1, u32 arg2)
{
    u8 bg = GetWindowAttribute(windowId, WINDOW_BG);
    u16 *tilemap = GetBgTilemapBuffer(bg);
    tilemap += arg2 * 0x40 + 0x1D;
    if (sub_81CAEBC(arg1))
    {
        tilemap[0] = 0x5000;
        tilemap[0x20] = 0x5001;
    }
    else
    {
        tilemap[0] = 0x5002;
        tilemap[0x20] = 0x5002;
    }
}

void sub_81CBD48(u16 windowId, u32 arg0)
{
    u8 bg = GetWindowAttribute(windowId, WINDOW_BG);
    u16 *tilemap = GetBgTilemapBuffer(bg);
    tilemap += arg0 * 0x40 + 0x1D;
    tilemap[0] = 0x5002;
    tilemap[0x20] = 0x5002;
}

static void sub_81CBD78(struct Pokenav4Struct *state)
{
    state->unk10 = AddWindow(&gUnknown_086227D8);
    state->unk12 = AddWindow(&gUnknown_086227E0);
    FillWindowPixelBuffer(state->unk10, PIXEL_FILL(1));
    PutWindowTilemap(state->unk10);
    FillWindowPixelBuffer(state->unk12, PIXEL_FILL(1));
    PutWindowTilemap(state->unk12);
    CopyWindowToVram(state->unk10, 1);
}

static void sub_81CBDC0(struct Pokenav4Struct *state)
{
    FillWindowPixelBuffer(state->unk12, PIXEL_FILL(1));
    sub_81CBDF4(state->unk12);
    sub_81CBE0C(state->unk12);
    sub_81CBE38(state->unk12);
    sub_81CBE50(state->unk12);
    CopyWindowToVram(state->unk12, 2);
}

static void sub_81CBDF4(u16 windowId)
{
    sub_81CBE88(windowId, gText_NumberRegistered, 0);
}

static void sub_81CBE0C(u16 windowId)
{
    u8 str[3];
    ConvertIntToDecimalStringN(str, sub_81CAE38(), STR_CONV_MODE_LEFT_ALIGN, 3);
    sub_81CBEB4(windowId, str, 1);
}

static void sub_81CBE38(u16 windowId)
{
    sub_81CBE88(windowId, gText_NumberOfBattles, 2);
}

static void sub_81CBE50(u16 windowId)
{
    u8 str[5];
    int numTrainerBattles = GetGameStat(GAME_STAT_TRAINER_BATTLES);
    if (numTrainerBattles > 99999)
        numTrainerBattles = 99999;

    ConvertIntToDecimalStringN(str, numTrainerBattles, STR_CONV_MODE_LEFT_ALIGN, 5);
    sub_81CBEB4(windowId, str, 3);
}

static void sub_81CBE88(u16 windowId, const u8 *str, int top)
{
    int y = top * 16 + 1;
    AddTextPrinterParameterized(windowId, 7, str, 2, y, TEXT_SPEED_FF, NULL);
}

static void sub_81CBEB4(u16 windowId, const u8 *str, int top)
{
    int x = GetStringRightAlignXOffset(7, str, 86);
    int y = top * 16 + 1;
    AddTextPrinterParameterized(windowId, 7, str, x, y, TEXT_SPEED_FF, NULL);
}

static void sub_81CBEF8(struct Pokenav4Struct *state, int arg1)
{
    u8 mapName[32];
    int x;
    int index = GetSelectedMatchCall() + arg1;
    int regionMapSection = sub_81CAEA4(index);
    if (regionMapSection != MAPSEC_NONE)
        GetMapName(mapName, regionMapSection, 0);
    else
        StringCopy(mapName, gText_Unknown);
    
    x = GetStringCenterAlignXOffset(7, mapName, 88);
    FillWindowPixelBuffer(state->unk10, PIXEL_FILL(1));
    AddTextPrinterParameterized(state->unk10, 7, mapName, x, 1, 0, NULL);
}

static void sub_81CBF60(struct Pokenav4Struct *state)
{
    u32 i;

    FillWindowPixelBuffer(state->unk12, PIXEL_FILL(1));
    for (i = 0; i < 3; i++)
    {
        int messageId = sub_81CB02C(i);
        if (messageId == 3)
            break;

        AddTextPrinterParameterized(state->unk12, 7, gUnknown_086227E8[messageId], 16, i * 16 + 1, TEXT_SPEED_FF, NULL);
    }

    CopyWindowToVram(state->unk12, 2);
}

static bool32 sub_81CBFC4(struct Pokenav4Struct *state)
{
    if (!IsDma3ManagerBusyWithBgCopy())
    {
        sub_81CC2F0(state, sub_81CB01C());
        return FALSE;
    }

    return TRUE;
}

static void sub_81CBFF0(struct Pokenav4Struct *state)
{
    sub_81CC330(state);
    sub_81CBDC0(state);
}

static bool32 sub_81CC004(struct Pokenav4Struct *state)
{
    return IsDma3ManagerBusyWithBgCopy();
}

static void sub_81CC014(struct Pokenav4Struct *state)
{
    sub_81CC330(state);
    FillWindowPixelBuffer(state->unk12, PIXEL_FILL(1));
    CopyWindowToVram(state->unk12, 2);
}

static void sub_81CC034(struct Pokenav4Struct *state)
{
    state->unk14 = AddWindow(&gUnknown_08622808);
    sub_8197184(state->unk14, 1, 4);
    sub_81C7B40();
}

static void sub_81CC058(struct Pokenav4Struct *state)
{
    struct Sprite *sprite;
    sub_8197184(state->unk14, 1, 4);
    sub_81971C4(state->unk14, 1, 4);
    FillWindowPixelBuffer(state->unk14, PIXEL_FILL(1));
    PutWindowTilemap(state->unk14);
    CopyWindowToVram(state->unk14, 3);
    sprite = PauseSpinningPokenavSprite();
    sprite->pos1.x = 24;
    sprite->pos1.y = 112;
    sprite->pos2.y = 0;
}

static void sub_81CC09C(struct Pokenav4Struct *state)
{
    LoadUserWindowBorderGfx(state->unk14, 1, 0x40);
    DrawTextBorderOuter(state->unk14, 1, 4);
    FillWindowPixelBuffer(state->unk14, PIXEL_FILL(1));
    PutWindowTilemap(state->unk14);
    CopyWindowToVram(state->unk14, 3);
}

static bool32 sub_81CC0D0(struct Pokenav4Struct *state)
{
    return IsDma3ManagerBusyWithBgCopy();
}

static void sub_81CC0E0(struct Pokenav4Struct *state)
{
    AddTextPrinterParameterized(state->unk14, 1, gUnknown_086227F4, 32, 1, 1, NULL);
}

static bool32 sub_81CC104(struct Pokenav4Struct *state)
{
    RunTextPrinters();
    return IsTextPrinterActive(state->unk14);
}

static void sub_81CC11C(struct Pokenav4Struct *state)
{
    AddTextPrinterParameterized(state->unk14, 1, gText_TrainerCloseBy, 0, 1, 1, NULL);
}

static bool32 sub_81CC140(struct Pokenav4Struct *state)
{
    RunTextPrinters();
    return IsTextPrinterActive(state->unk14);
}

static void sub_81CC158(struct Pokenav4Struct *state)
{
    int index = GetSelectedMatchCall();
    const u8 *str = sub_81CAF78(index, &state->unkF);
    u8 speed = GetPlayerTextSpeedDelay();
    AddTextPrinterParameterized(state->unk14, 1, str, 32, 1, speed, NULL);
}

static bool32 sub_81CC194(struct Pokenav4Struct *state)
{
    if (gMain.heldKeys & A_BUTTON)
        gTextFlags.canABSpeedUpPrint = 1;
    else
        gTextFlags.canABSpeedUpPrint = 0;

    RunTextPrinters();
    return IsTextPrinterActive(state->unk14);
}

static void sub_81CC1DC(struct Pokenav4Struct *state)
{
    ResumeSpinningPokenavSprite();
    FillBgTilemapBufferRect_Palette0(1, 0, 0, 0, 32, 20);
    CopyBgTilemapBufferToVram(1);
}

static bool32 sub_81CC204(struct Pokenav4Struct *state)
{
    return  IsDma3ManagerBusyWithBgCopy();
}

static void sub_81CC214(void)
{
    int i;
    u8 paletteNum;
    struct SpriteSheet spriteSheet;
    struct Pokenav4Struct *state = GetSubstructPtr(6);

    for (i = 0; i < ARRAY_COUNT(gUnknown_08622810); i++)
        LoadCompressedSpriteSheet(&gUnknown_08622810[i]);

    Pokenav_AllocAndLoadPalettes(gUnknown_08622818);
    state->unk1C = NULL;
    spriteSheet.data = state->unk1828;
    spriteSheet.size = 0x800;
    spriteSheet.tag = 8;
    state->unk1824 = (u8 *)OBJ_VRAM0 + LoadSpriteSheet(&spriteSheet) * 0x20;
    paletteNum = AllocSpritePalette(13);
    state->unk1A = 0x100 + paletteNum * 0x10;
    state->unk20 = sub_81CC370();
    state->unk20->invisible = 1;
}

static void sub_81CC2B4(void)
{
    struct Pokenav4Struct *state = GetSubstructPtr(6);
    if (state->unk1C)
        DestroySprite(state->unk1C);
    if (state->unk20)
        DestroySprite(state->unk20);

    FreeSpriteTilesByTag(8);
    FreeSpriteTilesByTag(7);
    FreeSpritePaletteByTag(12);
    FreeSpritePaletteByTag(13);
}

static void sub_81CC2F0(struct Pokenav4Struct *state, int top)
{
    if (!state->unk1C)
    {
        u8 spriteId = CreateSprite(&gUnknown_08622830, 4, 80, 5);
        state->unk1C = &gSprites[spriteId];
        sub_81CC344(state, top);
    }
}

static void sub_81CC330(struct Pokenav4Struct *state)
{
    DestroySprite(state->unk1C);
    state->unk1C = NULL;
}

static void sub_81CC344(struct Pokenav4Struct *state, int top)
{
    state->unk1C->pos2.y = top * 16;
}

void sub_81CC34C(struct Sprite *sprite)
{
    if (++sprite->data[0] > 3)
    {
        sprite->data[0] = 0;
        sprite->pos2.x = (sprite->pos2.x + 1) & 0x7;
    }
}

static struct Sprite *sub_81CC370(void)
{
    u8 spriteId = CreateSprite(&gUnknown_08622850, 44, 104, 6);
    return &gSprites[spriteId];
}

static void sub_81CC39C(struct Pokenav4Struct *state)
{
    u16 cursor;
    int trainerId = sub_81CAF04(GetSelectedMatchCall());
    if (trainerId >= 0)
    {
        DecompressPicFromTable(&gTrainerFrontPicTable[trainerId], state->unk1828, SPECIES_NONE);
        LZ77UnCompWram(gTrainerFrontPicPaletteTable[trainerId].data, state->unk2028);
        cursor = RequestDma3Copy(state->unk1828, state->unk1824, 0x800, 1);
        LoadPalette(state->unk2028, state->unk1A, 0x20);
        state->unk20->data[0] = 0;
        state->unk20->data[7] = cursor;
        state->unk20->callback = sub_81CC440;
    }
}

static void sub_81CC420(struct Pokenav4Struct *state)
{
    state->unk20->callback = sub_81CC4A4;
}

static bool32 sub_81CC42C(struct Pokenav4Struct *state)
{
    return state->unk20->callback != SpriteCallbackDummy;
}

static void sub_81CC440(struct Sprite *sprite)
{
    switch (sprite->data[0])
    {
    case 0:
        if (CheckForSpaceForDma3Request(sprite->data[7]) != -1)
        {
            sprite->pos2.x = -80;
            sprite->invisible = 0;
            sprite->data[0]++;
        }
        break;
    case 1:
        sprite->pos2.x += 8;
        if (sprite->pos2.x >= 0)
        {
            sprite->pos2.x = 0;
            sprite->callback = SpriteCallbackDummy;
        }
        break;
    }
}

static void sub_81CC4A4(struct Sprite *sprite)
{
    sprite->pos2.x -= 8;
    if (sprite->pos2.x <= -80)
    {
        sprite->invisible = 1;
        sprite->callback = SpriteCallbackDummy;
    }
}
