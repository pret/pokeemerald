#include "global.h"
#include "gpu_regs.h"
#include "main.h"
#include "trainer_card.h"
#include "event_data.h"
#include "recorded_battle.h"
#include "alloc.h"
#include "sprite.h"
#include "scanline_effect.h"
#include "text_window.h"
#include "task.h"
#include "graphics.h"
#include "palette.h"
#include "window.h"
#include "menu_helpers.h"
#include "menu.h"
#include "bg.h"
#include "sound.h"
#include "battle_pyramid.h"
#include "overworld.h"
#include "constants/battle_frontier.h"
#include "constants/rgb.h"
#include "constants/region_map_sections.h"
#include "constants/songs.h"

enum
{
    CURSOR_AREA_NOTHING,
    CURSOR_AREA_MAP,
    CURSOR_AREA_CARD,
    CURSOR_AREA_RECORD,
    CURSOR_AREA_CANCEL,
    CURSOR_AREA_POINTS,
    CURSOR_AREA_EARNED_SYMBOLS, // The window.
    CURSOR_AREA_SYMBOL, // All 7 symbols.
    CURSOR_AREA_COUNT = CURSOR_AREA_SYMBOL + NUM_FRONTIER_FACILITIES,
};

struct FrontierPassData
{
    void (*callback)(void);
    u16 state;
    u16 battlePoints;
    s16 x;
    s16 y;
    u8 cursorArea;
    u8 previousCursorArea;
    u8 hasBattleRecord:1;
    u8 unkE:3;
    u8 trainerStars:4;
    u8 facilitySymbols[NUM_FRONTIER_FACILITIES];
};

struct FrontierPassUnk
{
    u32 unk0[8];
    u8 *unk20;
    u8 *unk24;
    u8 *unk28;
    bool8 unk2C;
    s16 unk2E;
    s16 unk30;
    u8 tilemapBuff1[0x1000];
    u8 tilemapBuff2[0x1000];
    u8 tilemapBuff3[0x400];
};

struct FrontierPassSaved
{
    void (*callback)(void);
    s16 x;
    s16 y;
};

extern struct FrontierPassData *gUnknown_02039CEC;
extern struct FrontierPassUnk *gUnknown_02039CF0;
extern struct FrontierPassSaved gUnknown_02039CF8;

// This file's functions.
u32 sub_80C51F0(void (*callback)(void));
void sub_80C544C(void);
void sub_80C629C(void);
void sub_80C63FC(void);
void sub_80C62DC(void);
u32 sub_80C52E4(void);
bool32 sub_80C5484(void);
bool32 sub_80C570C(void);
void sub_80C5A48(u8 taskId);
void sub_80C5BD8(u8 taskId);
void sub_80C6104(u8 cursorArea, u8 previousCursorArea);

// Const rom data.
extern const s16 gUnknown_085713E0[][2];
extern const struct BgTemplate gUnknown_085713E8[3];
extern const struct WindowTemplate gUnknown_08571400[];
extern const u32 gUnknown_085712F8[];
extern const u32 gUnknown_085712C0[];
extern const u32 gUnknown_08571060[];

// code
void sub_80C50D0(void)
{
    SetGpuReg(REG_OFFSET_DISPCNT, 0);
    SetGpuReg(REG_OFFSET_BG3CNT, 0);
    SetGpuReg(REG_OFFSET_BG2CNT, 0);
    SetGpuReg(REG_OFFSET_BG1CNT, 0);
    SetGpuReg(REG_OFFSET_BG0CNT, 0);
    ChangeBgX(0, 0, 0);
    ChangeBgY(0, 0, 0);
    ChangeBgX(1, 0, 0);
    ChangeBgY(1, 0, 0);
    ChangeBgX(2, 0, 0);
    ChangeBgY(2, 0, 0);
    ChangeBgX(3, 0, 0);
    ChangeBgY(3, 0, 0);
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
    SetGpuReg(REG_OFFSET_BLDY, 0);
    SetGpuReg(REG_OFFSET_BLDALPHA, 0);
    SetGpuReg(REG_OFFSET_WIN0H, 0);
    SetGpuReg(REG_OFFSET_WIN0V, 0);
    SetGpuReg(REG_OFFSET_WIN1H, 0);
    SetGpuReg(REG_OFFSET_WIN1V, 0);
    SetGpuReg(REG_OFFSET_WININ, 0);
    SetGpuReg(REG_OFFSET_WINOUT, 0);
    CpuFill16(0, (void *)VRAM, VRAM_SIZE);
    CpuFill32(0, (void *)OAM, OAM_SIZE);
}

void sub_80C51C4(void (*callback)(void))
{
    sub_80C51F0(callback);
    SetMainCallback2(sub_80C544C);
}

void sub_80C51D8(void)
{
    SetMainCallback2(gUnknown_02039CEC->callback);
    sub_80C52E4();
}

u32 sub_80C51F0(void (*callback)(void))
{
    u8 i;

    if (gUnknown_02039CEC != NULL)
        return 1;

    gUnknown_02039CEC = AllocZeroed(sizeof(*gUnknown_02039CEC));
    if (gUnknown_02039CEC == NULL)
        return 2;

    gUnknown_02039CEC->callback = callback;
    i = GetCurrentRegionMapSectionId();
    if (i != MAPSEC_BATTLE_FRONTIER && i != MAPSEC_ARTISAN_CAVE)
    {
        gUnknown_02039CEC->x = 176;
        gUnknown_02039CEC->y = 104;
    }
    else
    {
        gUnknown_02039CEC->x = 176;
        gUnknown_02039CEC->y = 48;
    }

    gUnknown_02039CEC->battlePoints = gSaveBlock2Ptr->frontier.battlePoints;
    gUnknown_02039CEC->hasBattleRecord = CanCopyRecordedBattleSaveData();
    gUnknown_02039CEC->unkE = 0;
    gUnknown_02039CEC->trainerStars = CountPlayerTrainerStars();
    for (i = 0; i < 7; i++)
    {
        if (FlagGet(FLAG_SYS_TOWER_SILVER + i * 2))
            gUnknown_02039CEC->facilitySymbols[i]++;
        if (FlagGet(FLAG_SYS_TOWER_GOLD + i * 2))
            gUnknown_02039CEC->facilitySymbols[i]++;
    }

    return 0;
}

u32 sub_80C52E4(void)
{
    if (gUnknown_02039CEC == NULL)
        return 1;

    memset(gUnknown_02039CEC, 0, sizeof(*gUnknown_02039CEC)); // Why clear data, if it's going to be freed anyway?
    FREE_AND_SET_NULL(gUnknown_02039CEC);
    return 0;
}

u32 sub_80C5310(void)
{
    if (gUnknown_02039CF0 != NULL)
        return 1;

    gUnknown_02039CF0 = AllocZeroed(sizeof(*gUnknown_02039CF0));
    if (gUnknown_02039CF0 == NULL)
        return 2;

    return 0;
}

u32 sub_80C5340(void)
{
    FreeAllWindowBuffers();
    if (gUnknown_02039CF0 == NULL)
        return 1;

    if (gUnknown_02039CF0->unk28 != NULL)
        FREE_AND_SET_NULL(gUnknown_02039CF0->unk28);
    if (gUnknown_02039CF0->unk24 != NULL)
        FREE_AND_SET_NULL(gUnknown_02039CF0->unk24);
    if (gUnknown_02039CF0->unk20 != NULL)
        FREE_AND_SET_NULL(gUnknown_02039CF0->unk20);

    memset(gUnknown_02039CF0, 0, sizeof(*gUnknown_02039CF0)); // Why clear data, if it's going to be freed anyway?
    FREE_AND_SET_NULL(gUnknown_02039CF0);
    return 0;
}

void sub_80C53AC(void)
{
    if (gUnknown_02039CF0->unk2C)
    {
        SetBgAffine(2,
                    gUnknown_085713E0[gUnknown_02039CEC->unkE - 1][0] << 8,
                    gUnknown_085713E0[gUnknown_02039CEC->unkE - 1][1] << 8,
                    gUnknown_085713E0[gUnknown_02039CEC->unkE - 1][0],
                    gUnknown_085713E0[gUnknown_02039CEC->unkE - 1][1],
                    gUnknown_02039CF0->unk2E,
                    gUnknown_02039CF0->unk30,
                    0);
    }
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

void sub_80C5438(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
}

void sub_80C544C(void)
{
    if (sub_80C5484())
    {
        CreateTask(sub_80C5A48, 0);
        SetMainCallback2(sub_80C5438);
    }
}

void sub_80C5470(void)
{
    if (sub_80C570C())
    {
        sub_80C51D8();
    }
}

bool32 sub_80C5484(void)
{
    u32 sizeOut = 0;

    switch (gUnknown_02039CEC->state)
    {
    case 0:
        SetVBlankCallback(NULL);
        ScanlineEffect_Stop();
        SetVBlankHBlankCallbacksToNull();
        DisableInterrupts(INTR_FLAG_HBLANK);
        break;
    case 1:
        sub_80C50D0();
        break;
    case 2:
        ResetTasks();
        ResetSpriteData();
        FreeAllSpritePalettes();
        ResetPaletteFade();
        reset_temp_tile_data_buffers();
        break;
    case 3:
        sub_80C5310();
        break;
    case 4:
        ResetBgsAndClearDma3BusyFlags(0);
        InitBgsFromTemplates(1, gUnknown_085713E8, ARRAY_COUNT(gUnknown_085713E8));
        SetBgTilemapBuffer(1, gUnknown_02039CF0->tilemapBuff1);
        SetBgTilemapBuffer(2, gUnknown_02039CF0->tilemapBuff2);
        SetBgTilemapBuffer(3, gUnknown_02039CF0->tilemapBuff3);
        SetBgAttribute(2, BG_ATTR_WRAPAROUND, 1);
        break;
    case 5:
        InitWindows(gUnknown_08571400);
        DeactivateAllTextPrinters();
        break;
    case 6:
        gUnknown_02039CF0->unk20 = malloc_and_decompress(gUnknown_085712F8, &sizeOut);
        gUnknown_02039CF0->unk24 = malloc_and_decompress(gUnknown_08571060, &sizeOut);
        gUnknown_02039CF0->unk28 = malloc_and_decompress(gUnknown_085712C0, &sizeOut);
        decompress_and_copy_tile_data_to_vram(1, gUnknown_08DE08C8, 0, 0, 0);
        decompress_and_copy_tile_data_to_vram(2, gUnknown_08DE2084, 0, 0, 0);
        break;
    case 7:
        if (free_temp_tile_data_buffers_if_possible())
            return FALSE;
        FillBgTilemapBufferRect_Palette0(0, 0, 0, 0, 30, 20);
        FillBgTilemapBufferRect_Palette0(1, 0, 0, 0, 30, 20);
        FillBgTilemapBufferRect_Palette0(2, 0, 0, 0, 30, 20);
        CopyBgTilemapBufferToVram(0);
        CopyBgTilemapBufferToVram(1);
        CopyBgTilemapBufferToVram(2);
        break;
    case 8:
        LoadPalette(gUnknown_08DE07C8[0], 0, 0x1A0);
        LoadPalette(gUnknown_08DE07C8[1 + gUnknown_02039CEC->trainerStars], 0x10, 0x20);
        LoadPalette(stdpal_get(0), 0xF0, 0x20);
        sub_80C629C();
        sub_80C6104(gUnknown_02039CEC->cursorArea, gUnknown_02039CEC->previousCursorArea);
        if (gUnknown_02039CEC->unkE == 1 || gUnknown_02039CEC->unkE == 2)
        {
            gUnknown_02039CEC->state = 0;
            return TRUE;
        }
        break;
    case 9:
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
        ShowBg(0);
        ShowBg(1);
        ShowBg(2);
        sub_80C62DC();
        SetVBlankCallback(sub_80C53AC);
        BlendPalettes(0xFFFFFFFF, 0x10, 0);
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0x10, 0, RGB_BLACK);
        break;
    case 10:
        AnimateSprites();
        BuildOamBuffer();
        if (UpdatePaletteFade())
            return FALSE;

        gUnknown_02039CEC->state = 0;
        return TRUE;
    }

    gUnknown_02039CEC->state++;
    return FALSE;
}

bool32 sub_80C570C(void)
{
    switch (gUnknown_02039CEC->state)
    {
    case 0:
        if (gUnknown_02039CEC->unkE != 1 && gUnknown_02039CEC->unkE != 2)
        {
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 0x10, RGB_BLACK);
        }
        else
        {
            gUnknown_02039CEC->state = 2;
            return FALSE;
        }
        break;
    case 1:
        if (UpdatePaletteFade())
            return FALSE;
        break;
    case 2:
        SetGpuReg(REG_OFFSET_DISPCNT, 0);
        HideBg(0);
        HideBg(1);
        HideBg(2);
        SetVBlankCallback(NULL);
        ScanlineEffect_Stop();
        SetVBlankHBlankCallbacksToNull();
        break;
    case 3:
        sub_80C63FC();
        break;
    case 4:
        sub_80C50D0();
        ResetTasks();
        ResetSpriteData();
        FreeAllSpritePalettes();
        break;
    case 5:
        UnsetBgTilemapBuffer(0);
        UnsetBgTilemapBuffer(1);
        UnsetBgTilemapBuffer(2);
        sub_80C5340();
        gUnknown_02039CEC->state = 0;
        return TRUE;
    }

    gUnknown_02039CEC->state++;
    return FALSE;
}

struct
{
    s16 yStart;
    s16 yEnd;
    s16 xStart;
    s16 xEnd;
}
extern const gUnknown_08571454[];

u8 sub_80C57FC(s16 x, s16 y)
{
    u8 i;

    // Minus/Plus 1, because the table doesn't take into account the nothing field.
    for (i = 0; i < CURSOR_AREA_COUNT - 1; i++)
    {
        if (gUnknown_08571454[i].yStart <= y && gUnknown_08571454[i].yEnd >= y
            && gUnknown_08571454[i].xStart <= x && gUnknown_08571454[i].xEnd >= x)
        {
            if (i >= CURSOR_AREA_SYMBOL - 1 && gUnknown_02039CEC->facilitySymbols[i - CURSOR_AREA_SYMBOL + 1] == 0)
                break;

            return i + 1;
        }
    }

    return 0;
}

void sub_80C5868(void)
{
    u8 taskId;

    if (!sub_80C5484())
        return;

    switch (gUnknown_02039CEC->unkE)
    {
    case 1:
    case 2:
        taskId = CreateTask(sub_80C5BD8, 0);
        gTasks[taskId].data[0] = 1;
        break;
    case 3:
    default:
        gUnknown_02039CEC->unkE = 0;
        taskId = CreateTask(sub_80C5A48, 0);
        break;
    }

    SetMainCallback2(sub_80C5438);
}

void sub_80C58D4(void)
{
    sub_80C51F0(gUnknown_02039CF8.callback);
    gUnknown_02039CEC->x = gUnknown_02039CF8.x;
    gUnknown_02039CEC->y = gUnknown_02039CF8.y;
    memset(&gUnknown_02039CF8, 0, sizeof(gUnknown_02039CF8));
    switch (InBattlePyramid())
    {
    case 1:
        PlayBGM(MUS_PYRAMID);
        break;
    case 2:
        PlayBGM(MUS_PYRAMID_TOP);
        break;
    default:
        Overworld_PlaySpecialMapMusic();
        break;
    }

    SetMainCallback2(sub_80C5868);
}
