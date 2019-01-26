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
#include "strings.h"
#include "frontier_pass.h"
#include "international_string_util.h"
#include "palette.h"
#include "window.h"
#include "decompress.h"
#include "menu_helpers.h"
#include "menu.h"
#include "bg.h"
#include "sound.h"
#include "string_util.h"
#include "battle_pyramid.h"
#include "overworld.h"
#include "math_util.h"
#include "constants/battle_frontier.h"
#include "constants/rgb.h"
#include "constants/region_map_sections.h"
#include "constants/songs.h"

// All windows displayed in the frontier pass.
enum
{
	WINDOW_EARNED_SYMBOLS,
	WINDOW_BATTLE_RECORD,
	WINDOW_BATTLE_POINTS,
	WINDOW_DESCRIPTION,
	WINDOW_4,
	WINDOW_COUNT
};

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
    s16 cursorX;
    s16 cursorY;
    u8 cursorArea;
    u8 previousCursorArea;
    u8 hasBattleRecord:1;
    u8 unkE:3;
    u8 trainerStars:4;
    u8 facilitySymbols[NUM_FRONTIER_FACILITIES];
};

struct FrontierPassGfx
{
    struct Sprite *cursorSprite;
    struct Sprite *symbolSprites[NUM_FRONTIER_FACILITIES];
    u8 *unk20;
    u8 *unk24;
    u8 *unk28;
    bool8 setAffine;
    s16 unk2E;
    s16 unk30;
    u8 tilemapBuff1[0x1000];
    u8 tilemapBuff2[0x1000];
    u8 tilemapBuff3[0x400];
};

struct FrontierPassSaved
{
    void (*callback)(void);
    s16 cursorX;
    s16 cursorY;
};

extern struct FrontierPassData *gUnknown_02039CEC;
extern struct FrontierPassGfx *gUnknown_02039CF0;
extern struct FrontierPassSaved gUnknown_02039CF8;

// This file's functions.
u32 AllocateFrontierPassData(void (*callback)(void));
void ShowFrontierMap(void (*callback)(void));
void CB2_InitFrontierPass(void);
void sub_80C629C(void);
void FreeCursorAndSymbolSprites(void);
void LoadCursorAndSymbolSprites(void);
u32 FreeFrontierPassData(void);
bool32 InitFrontierPass(void);
bool32 HideFrontierPass(void);
void Task_HandleFrontierPassInput(u8 taskId);
void Task_DoFadeEffect(u8 taskId);
void sub_80C6104(u8 cursorArea, u8 previousCursorArea);
void PrintAreaDescription(u8 cursorArea);
void sub_80C5F58(bool8 arg0, bool8 arg1);

// Const rom data.
extern const s16 gUnknown_085713E0[][2];
extern const struct BgTemplate gUnknown_085713E8[3];
extern const struct WindowTemplate gUnknown_08571400[];
extern const u32 gUnknown_085712F8[];
extern const u32 gUnknown_085712C0[];
extern const u32 gUnknown_08571060[];
extern const u8 gUnknown_08571448[];
extern const u8 gUnknown_0857144B[];
extern const u8 *const gUnknown_08571614[];
extern const struct SpritePalette gUnknown_085714E4[];
extern const struct CompressedSpriteSheet gUnknown_085714BC[];
extern const struct SpriteTemplate gUnknown_085715B4;
extern const struct SpriteTemplate gUnknown_085715E4;

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

void ShowFrontierPass(void (*callback)(void))
{
    AllocateFrontierPassData(callback);
    SetMainCallback2(CB2_InitFrontierPass);
}

void LeaveFrontierPass(void)
{
    SetMainCallback2(gUnknown_02039CEC->callback);
    FreeFrontierPassData();
}

u32 AllocateFrontierPassData(void (*callback)(void))
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
        gUnknown_02039CEC->cursorX = 176;
        gUnknown_02039CEC->cursorY = 104;
    }
    else
    {
        gUnknown_02039CEC->cursorX = 176;
        gUnknown_02039CEC->cursorY = 48;
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

u32 FreeFrontierPassData(void)
{
    if (gUnknown_02039CEC == NULL)
        return 1;

    memset(gUnknown_02039CEC, 0, sizeof(*gUnknown_02039CEC)); // Why clear data, if it's going to be freed anyway?
    FREE_AND_SET_NULL(gUnknown_02039CEC);
    return 0;
}

u32 AllocateFrontierPassGfx(void)
{
    if (gUnknown_02039CF0 != NULL)
        return 1;

    gUnknown_02039CF0 = AllocZeroed(sizeof(*gUnknown_02039CF0));
    if (gUnknown_02039CF0 == NULL)
        return 2;

    return 0;
}

u32 FreeFrontierPassGfx(void)
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

void VblankCb_FrontierPass(void)
{
    if (gUnknown_02039CF0->setAffine)
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

void CB2_FrontierPass(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
}

void CB2_InitFrontierPass(void)
{
    if (InitFrontierPass())
    {
        CreateTask(Task_HandleFrontierPassInput, 0);
        SetMainCallback2(CB2_FrontierPass);
    }
}

void CB2_HideFrontierPass(void)
{
    if (HideFrontierPass())
    {
        LeaveFrontierPass();
    }
}

bool32 InitFrontierPass(void)
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
        AllocateFrontierPassGfx();
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
        LoadCursorAndSymbolSprites();
        SetVBlankCallback(VblankCb_FrontierPass);
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

bool32 HideFrontierPass(void)
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
        FreeCursorAndSymbolSprites();
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
        FreeFrontierPassGfx();
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

u8 GetCursorAreaFromCoords(s16 x, s16 y)
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

void CB2_ReshowFrontierPass(void)
{
    u8 taskId;

    if (!InitFrontierPass())
        return;

    switch (gUnknown_02039CEC->unkE)
    {
    case 1:
    case 2:
        taskId = CreateTask(Task_DoFadeEffect, 0);
        gTasks[taskId].data[0] = TRUE;
        break;
    case 3:
    default:
        gUnknown_02039CEC->unkE = 0;
        taskId = CreateTask(Task_HandleFrontierPassInput, 0);
        break;
    }

    SetMainCallback2(CB2_FrontierPass);
}

void CB2_ReturnFromRecord(void)
{
    AllocateFrontierPassData(gUnknown_02039CF8.callback);
    gUnknown_02039CEC->cursorX = gUnknown_02039CF8.cursorX;
    gUnknown_02039CEC->cursorY = gUnknown_02039CF8.cursorY;
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

    SetMainCallback2(CB2_ReshowFrontierPass);
}

void CB2_ShowFrontierPassFeature(void)
{
    if (!HideFrontierPass())
        return;

    switch (gUnknown_02039CEC->unkE)
    {
    case 1:
        ShowFrontierMap(CB2_ReshowFrontierPass);
        break;
    case 3:
        gUnknown_02039CF8.callback = gUnknown_02039CEC->callback;
        gUnknown_02039CF8.cursorX = gUnknown_02039CEC->cursorX;
        gUnknown_02039CF8.cursorY = gUnknown_02039CEC->cursorY;
        FreeFrontierPassData();
        PlayRecordedBattle(CB2_ReturnFromRecord);
        break;
    case 2:
        ShowPlayerTrainerCard(CB2_ReshowFrontierPass);
        break;
    }
}

bool32 TryCallPassAreaFunction(u8 taskId, u8 cursorArea)
{
    switch (cursorArea)
    {
    case CURSOR_AREA_RECORD:
        if (!gUnknown_02039CEC->hasBattleRecord)
            return FALSE;
        gUnknown_02039CEC->unkE = 3;
        DestroyTask(taskId);
        SetMainCallback2(CB2_ShowFrontierPassFeature);
        break;
    case CURSOR_AREA_MAP:
    case CURSOR_AREA_CARD:
        gUnknown_02039CEC->unkE = cursorArea;
        gTasks[taskId].func = Task_DoFadeEffect;
        gTasks[taskId].data[0] = FALSE;
        break;
    default:
        return FALSE;
    }

    gUnknown_02039CEC->cursorX = gUnknown_02039CF0->cursorSprite->pos1.x;
    gUnknown_02039CEC->cursorY = gUnknown_02039CF0->cursorSprite->pos1.y;
    return TRUE;
}

void Task_HandleFrontierPassInput(u8 taskId)
{
    u8 var = FALSE; // Reused, first informs whether the cursor moves, then used as the new cursor area.

    if (gMain.heldKeys & DPAD_UP && gUnknown_02039CF0->cursorSprite->pos1.y >= 9)
    {
        gUnknown_02039CF0->cursorSprite->pos1.y -= 2;
        if (gUnknown_02039CF0->cursorSprite->pos1.y <= 7)
            gUnknown_02039CF0->cursorSprite->pos1.y = 2;
        var = TRUE;
    }
    if (gMain.heldKeys & DPAD_DOWN && gUnknown_02039CF0->cursorSprite->pos1.y <= 135)
    {
        gUnknown_02039CF0->cursorSprite->pos1.y += 2;
        if (gUnknown_02039CF0->cursorSprite->pos1.y >= 137)
            gUnknown_02039CF0->cursorSprite->pos1.y = 136;
        var = TRUE;
    }

    if (gMain.heldKeys & DPAD_LEFT && gUnknown_02039CF0->cursorSprite->pos1.x >= 6)
    {
        gUnknown_02039CF0->cursorSprite->pos1.x -= 2;
        if (gUnknown_02039CF0->cursorSprite->pos1.x <= 4)
            gUnknown_02039CF0->cursorSprite->pos1.x = 5;
        var = TRUE;
    }
    if (gMain.heldKeys & DPAD_RIGHT && gUnknown_02039CF0->cursorSprite->pos1.x <= 231)
    {
        gUnknown_02039CF0->cursorSprite->pos1.x += 2;
        if (gUnknown_02039CF0->cursorSprite->pos1.x >= 233)
            gUnknown_02039CF0->cursorSprite->pos1.x = 232;
        var = TRUE;
    }

    if (!var) // Cursor did not change.
    {
        if (gUnknown_02039CEC->cursorArea != CURSOR_AREA_NOTHING && gMain.newKeys & A_BUTTON)
        {
            if (gUnknown_02039CEC->cursorArea <= CURSOR_AREA_RECORD) // Map, Card, Record
            {
                PlaySE(SE_SELECT);
                if (TryCallPassAreaFunction(taskId, gUnknown_02039CEC->cursorArea))
                    return;
            }
            else if (gUnknown_02039CEC->cursorArea == CURSOR_AREA_CANCEL)
            {
                PlaySE(SE_PC_OFF);
                SetMainCallback2(CB2_HideFrontierPass);
                DestroyTask(taskId);
                // BUG. The function should return here. Otherwise, it can play the same sound twice and destroy the same task twice.
            }
        }

        if (gMain.newKeys & B_BUTTON)
        {
            PlaySE(SE_PC_OFF);
            SetMainCallback2(CB2_HideFrontierPass);
            DestroyTask(taskId);
        }
    }
    else
    {
        var = GetCursorAreaFromCoords(gUnknown_02039CF0->cursorSprite->pos1.x - 5, gUnknown_02039CF0->cursorSprite->pos1.y + 5);
        if (gUnknown_02039CEC->cursorArea != var)
        {
            PrintAreaDescription(var);
            gUnknown_02039CEC->previousCursorArea = gUnknown_02039CEC->cursorArea;
            gUnknown_02039CEC->cursorArea = var;
            sub_80C6104(gUnknown_02039CEC->cursorArea, gUnknown_02039CEC->previousCursorArea);
        }
    }
}

void Task_DoFadeEffect(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    switch (gUnknown_02039CEC->state)
    {
    case 0:
        if (!data[0])
        {
            sub_80C5F58(TRUE, FALSE);
            data[1] = 0x100;
            data[2] = 0x100;
            data[3] = 0x15;
            data[4] = 0x15;
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 0x10, RGB_WHITE);
        }
        else
        {
            data[1] = 0x1FC;
            data[2] = 0x1FC;
            data[3] = -0x15;
            data[4] = -0x15;
            SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
            ShowBg(0);
            ShowBg(1);
            ShowBg(2);
            LoadCursorAndSymbolSprites();
            SetVBlankCallback(VblankCb_FrontierPass);
            BlendPalettes(0xFFFFFFFF, 0x10, RGB_WHITE);
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 0x10, 0, RGB_WHITE);
        }
        gUnknown_02039CF0->setAffine = TRUE;
        gUnknown_02039CF0->unk2E = sub_8151624(data[1]);
        gUnknown_02039CF0->unk30 = sub_8151624(data[2]);
        break;
    case 1:
        UpdatePaletteFade();
        data[1] += data[3];
        data[2] += data[4];
        gUnknown_02039CF0->unk2E = sub_8151624(data[1]);
        gUnknown_02039CF0->unk30 = sub_8151624(data[2]);
        if (!data[0])
        {
            if (data[1] <= 0x1FC)
                return;
        }
        else
        {
            if (data[1] != 0x100)
                return;
        }
        break;
    case 2:
        if (gUnknown_02039CF0->setAffine) // Nonsensical check.
            gUnknown_02039CF0->setAffine = FALSE;
        if (UpdatePaletteFade())
            return;
        if (!data[0])
        {
            DestroyTask(taskId);
            SetMainCallback2(CB2_ShowFrontierPassFeature);
        }
        else
        {
            sub_80C5F58(FALSE, FALSE);
            gUnknown_02039CEC->unkE = 0;
            gTasks[taskId].func = Task_HandleFrontierPassInput;
        }
        SetBgAttribute(2, BG_ATTR_WRAPAROUND, 0);
        gUnknown_02039CEC->state = 0;
        return;
    }

    gUnknown_02039CEC->state++;
}

void ShowAndPrintWindows(void)
{
    s32 x;
    u8 i;

    for (i = 0; i < WINDOW_COUNT; i++)
    {
        PutWindowTilemap(i);
        FillWindowPixelBuffer(i, 0);
    }

    x = GetStringCenterAlignXOffset(1, gText_SymbolsEarned, 0x60);
    AddTextPrinterParameterized3(WINDOW_EARNED_SYMBOLS, 1, x, 5, gUnknown_08571448, 0, gText_SymbolsEarned);

    x = GetStringCenterAlignXOffset(1, gText_BattleRecord, 0x60);
    AddTextPrinterParameterized3(WINDOW_BATTLE_RECORD, 1, x, 5, gUnknown_08571448, 0, gText_BattleRecord);

    AddTextPrinterParameterized3(WINDOW_BATTLE_POINTS, 8, 5, 4, gUnknown_08571448, 0, gText_BattlePoints);
    ConvertIntToDecimalStringN(gStringVar4, gUnknown_02039CEC->battlePoints, STR_CONV_MODE_LEFT_ALIGN, 5);
    x = GetStringRightAlignXOffset(8, gStringVar4, 0x5B);
    AddTextPrinterParameterized3(WINDOW_BATTLE_POINTS, 8, x, 16, gUnknown_08571448, 0, gStringVar4);

    gUnknown_02039CEC->cursorArea = GetCursorAreaFromCoords(gUnknown_02039CEC->cursorX - 5, gUnknown_02039CEC->cursorY + 5);
    gUnknown_02039CEC->previousCursorArea = CURSOR_AREA_NOTHING;
    PrintAreaDescription(gUnknown_02039CEC->cursorArea);

    for (i = 0; i < WINDOW_COUNT; i++)
        CopyWindowToVram(i, 3);

    CopyBgTilemapBufferToVram(0);
}

void PrintAreaDescription(u8 cursorArea)
{
    FillWindowPixelBuffer(WINDOW_DESCRIPTION, 0);
    if (cursorArea == CURSOR_AREA_RECORD && !gUnknown_02039CEC->hasBattleRecord)
        AddTextPrinterParameterized3(WINDOW_DESCRIPTION, 1, 2, 0, gUnknown_0857144B, 0, gUnknown_08571614[0]);
    else if (cursorArea != CURSOR_AREA_NOTHING)
        AddTextPrinterParameterized3(WINDOW_DESCRIPTION, 1, 2, 0, gUnknown_0857144B, 0, gUnknown_08571614[cursorArea]);

    CopyWindowToVram(WINDOW_DESCRIPTION, 3);
    CopyBgTilemapBufferToVram(0);
}

void sub_80C5F58(bool8 arg0, bool8 arg1)
{
    switch (gUnknown_02039CEC->unkE)
    {
    case 1:
        if (arg0)
            CopyToBgTilemapBufferRect_ChangePalette(2, gUnknown_02039CF0->unk20, 16, 3, 12, 7, 16);
        else
            FillBgTilemapBufferRect(2, 0, 16, 3, 12, 7, 16);
        break;
    case 2:
        if (arg0)
            CopyToBgTilemapBufferRect_ChangePalette(2, gUnknown_02039CF0->unk20 + 84, 16, 10, 12, 7, 16);
        else
            FillBgTilemapBufferRect(2, 0, 16, 10, 12, 7, 16);
        break;
    default:
        return;
    }

    CopyBgTilemapBufferToVram(2);
    if (arg1)
    {
        SetBgAffine(2,
                    gUnknown_085713E0[gUnknown_02039CEC->unkE - 1][0] << 8,
                    gUnknown_085713E0[gUnknown_02039CEC->unkE - 1][1] << 8,
                    gUnknown_085713E0[gUnknown_02039CEC->unkE - 1][0],
                    gUnknown_085713E0[gUnknown_02039CEC->unkE - 1][1],
                    sub_8151624(0x1FC),
                    sub_8151624(0x1FC),
                    0);
    }
    else
    {
        SetBgAffine(2,
                    gUnknown_085713E0[gUnknown_02039CEC->unkE - 1][0] << 8,
                    gUnknown_085713E0[gUnknown_02039CEC->unkE - 1][1] << 8,
                    gUnknown_085713E0[gUnknown_02039CEC->unkE - 1][0],
                    gUnknown_085713E0[gUnknown_02039CEC->unkE - 1][1],
                    sub_8151624(0x100),
                    sub_8151624(0x100),
                    0);
    }
}

void sub_80C6104(u8 cursorArea, u8 previousCursorArea)
{
    bool32 var;

    switch (previousCursorArea)
    {
    case CURSOR_AREA_MAP:
        CopyToBgTilemapBufferRect_ChangePalette(1, gUnknown_02039CF0->unk24, 16, 3, 12, 7, 17);
        var = TRUE;
        break;
    case CURSOR_AREA_CARD:
        CopyToBgTilemapBufferRect_ChangePalette(1, gUnknown_02039CF0->unk24 + 336, 16, 10, 12, 7, 17);
        var = TRUE;
        break;
    case CURSOR_AREA_RECORD:
        if (!gUnknown_02039CEC->hasBattleRecord)
        {
            var = FALSE;
        }
        else
        {
            CopyToBgTilemapBufferRect_ChangePalette(1, gUnknown_02039CF0->unk28, 2, 10, 12, 3, 17);
            var = TRUE;
        }
        break;
    case CURSOR_AREA_CANCEL:
        CopyToBgTilemapBufferRect_ChangePalette(1, gUnknown_08DE3350, 21, 0, 9, 2, 17);
        var = TRUE;
        break;
    default:
        var = FALSE;
        break;
    }

    if (!var)
    {
        if (cursorArea == CURSOR_AREA_NOTHING || cursorArea > CURSOR_AREA_CANCEL)
            return;
    }

    switch (cursorArea)
    {
    case CURSOR_AREA_MAP:
        CopyToBgTilemapBufferRect_ChangePalette(1, gUnknown_02039CF0->unk24 + 168, 16, 3, 12, 7, 17);
        var = TRUE;
        break;
    case CURSOR_AREA_CARD:
        CopyToBgTilemapBufferRect_ChangePalette(1, gUnknown_02039CF0->unk24 + 504, 16, 10, 12, 7, 17);
        var = TRUE;
        break;
    case CURSOR_AREA_RECORD:
        if (!gUnknown_02039CEC->hasBattleRecord)
            return;

        CopyToBgTilemapBufferRect_ChangePalette(1, gUnknown_02039CF0->unk28 + 72, 2, 10, 12, 3, 17);
        var = TRUE;
        break;
    case CURSOR_AREA_CANCEL:
        CopyToBgTilemapBufferRect_ChangePalette(1, gUnknown_08DE3374, 21, 0, 9, 2, 17);
        var = TRUE;
        break;
    default:
        var = FALSE;
        break;
    }

    if (!var)
    {
        asm("":::"r4");
        if (previousCursorArea == CURSOR_AREA_NOTHING || previousCursorArea > CURSOR_AREA_CANCEL)
            return;
    }

    CopyBgTilemapBufferToVram(1);
}

void sub_80C629C(void)
{
    CopyToBgTilemapBuffer(1, gUnknown_08DE3060, 0, 0);
    sub_80C6104(gUnknown_02039CEC->cursorArea, gUnknown_02039CEC->previousCursorArea);
    sub_80C5F58(TRUE, gUnknown_02039CEC->unkE);
    ShowAndPrintWindows();
    CopyBgTilemapBufferToVram(1);
}

void LoadCursorAndSymbolSprites(void)
{
    u8 spriteId;
    u8 i = 0;

    FreeAllSpritePalettes();
    ResetAffineAnimData();
    LoadSpritePalettes(gUnknown_085714E4);
    LoadCompressedSpriteSheet(&gUnknown_085714BC[0]);
    LoadCompressedSpriteSheet(&gUnknown_085714BC[2]);
    spriteId = CreateSprite(&gUnknown_085715B4, gUnknown_02039CEC->cursorX, gUnknown_02039CEC->cursorY, 0);
    gUnknown_02039CF0->cursorSprite = &gSprites[spriteId];
    gUnknown_02039CF0->cursorSprite->oam.priority = 0;

    for (i = 0; i < NUM_FRONTIER_FACILITIES; i++)
    {
        if (gUnknown_02039CEC->facilitySymbols[i] != 0)
        {
            struct SpriteTemplate sprite = gUnknown_085715E4;

            sprite.paletteTag += gUnknown_02039CEC->facilitySymbols[i] - 1;
            spriteId = CreateSprite(&sprite, gUnknown_08571454[i + CURSOR_AREA_SYMBOL - 1].xStart + 8, gUnknown_08571454[i + CURSOR_AREA_SYMBOL - 1].yStart + 6, i + 1);
            gUnknown_02039CF0->symbolSprites[i] = &gSprites[spriteId];
            gUnknown_02039CF0->symbolSprites[i]->oam.priority = 2;
            StartSpriteAnim(gUnknown_02039CF0->symbolSprites[i], i);
        }
    }
}

void FreeCursorAndSymbolSprites(void)
{
    u8 i = 0;

    DestroySprite(gUnknown_02039CF0->cursorSprite);
    gUnknown_02039CF0->cursorSprite = NULL;
    for (i = 0; i < NUM_FRONTIER_FACILITIES; i++)
    {
        if (gUnknown_02039CF0->symbolSprites[i] != NULL)
        {
            DestroySprite(gUnknown_02039CF0->symbolSprites[i]);
            gUnknown_02039CF0->symbolSprites[i] = NULL;
        }
    }
    FreeAllSpritePalettes();
    FreeSpriteTilesByTag(2);
    FreeSpriteTilesByTag(0);
}

void nullsub_39(void)
{

}

// Frontier Map code.
/*
void ShowFrontierMap(void (*callback)(void));
{

}
*/
