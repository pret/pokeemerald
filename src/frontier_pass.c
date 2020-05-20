#include "global.h"
#include "gpu_regs.h"
#include "main.h"
#include "trainer_card.h"
#include "battle_anim.h"
#include "event_data.h"
#include "recorded_battle.h"
#include "malloc.h"
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
#include "constants/maps.h"
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

// Windows displayed in the facilities map view.
enum
{
    MAP_WINDOW_0,
    MAP_WINDOW_NAME,
    MAP_WINDOW_DESCRIPTION,
    MAP_WINDOW_COUNT
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

struct FrontierMapData
{
    void (*callback)(void);
    struct Sprite *cursorSprite;
    struct Sprite *playerHeadSprite;
    struct Sprite *mapIndicatorSprite;
    u8 cursorPos;
    u8 unused;
    u8 tilemapBuff0[0x1000];
    u8 tilemapBuff1[0x1000];
    u8 tilemapBuff2[0x1000];
};

static EWRAM_DATA struct FrontierPassData *sPassData = NULL;
static EWRAM_DATA struct FrontierPassGfx *sPassGfx = NULL;
static EWRAM_DATA struct FrontierMapData *sMapData = NULL;
static EWRAM_DATA struct FrontierPassSaved sSavedPassData = {0};

// This file's functions.
static u32 AllocateFrontierPassData(void (*callback)(void));
static void ShowFrontierMap(void (*callback)(void));
static void CB2_InitFrontierPass(void);
static void sub_80C629C(void);
static void FreeCursorAndSymbolSprites(void);
static void LoadCursorAndSymbolSprites(void);
static u32 FreeFrontierPassData(void);
static bool32 InitFrontierPass(void);
static bool32 HideFrontierPass(void);
static void Task_HandleFrontierPassInput(u8 taskId);
static void Task_DoFadeEffect(u8 taskId);
static void sub_80C6104(u8 cursorArea, u8 previousCursorArea);
static void PrintAreaDescription(u8 cursorArea);
static void sub_80C5F58(bool8 arg0, bool8 arg1);
static void SpriteCb_Dummy(struct Sprite *sprite);

// Const rom data.
static const u16 sMaleHeadPalette[] = INCBIN_U16("graphics/frontier_pass/map_heads.gbapal");
static const u16 sFemaleHeadPalette[] = INCBIN_U16("graphics/frontier_pass/map_heads_female.gbapal");
static const u32 gUnknown_0856FBBC[] = INCBIN_U32("graphics/frontier_pass/map_screen.4bpp.lz");
static const u32 sCursorGfx[] = INCBIN_U32("graphics/frontier_pass/cursor.4bpp.lz");
static const u32 sHeadsGfx[] = INCBIN_U32("graphics/frontier_pass/map_heads.4bpp.lz");
static const u32 sMapCursorGfx[] = INCBIN_U32("graphics/frontier_pass/map_cursor.4bpp.lz");
static const u32 gUnknown_08570E00[] = INCBIN_U32("graphics/frontier_pass/map_screen.bin.lz");
static const u32 gUnknown_08571060[] = INCBIN_U32("graphics/frontier_pass/small_map_and_card.bin.lz");
static const u32 gUnknown_08571298[] = INCBIN_U32("graphics/frontier_pass/unknown_571298.bin");
static const u32 gUnknown_085712C0[] = INCBIN_U32("graphics/frontier_pass/record_frame.bin.lz");
static const u32 gUnknown_085712F8[] = INCBIN_U32("graphics/frontier_pass/small_map_and_card_affine.bin.lz");

static const s16 gUnknown_085713E0[][2] = {{216, 32}, {216, 128}};

static const struct BgTemplate sPassBgTemplates[] =
{
    {
        .bg = 0,
        .charBaseIndex = 2,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0
    },
    {
        .bg = 1,
        .charBaseIndex = 0,
        .mapBaseIndex = 30,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 0
    },
    {
        .bg = 2,
        .charBaseIndex = 1,
        .mapBaseIndex = 29,
        .screenSize = 1,
        .paletteMode = 1,
        .priority = 0,
        .baseTile = 0
    },
};

static const struct BgTemplate sMapBgTemplates[] =
{
    {
        .bg = 0,
        .charBaseIndex = 2,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0
    },
    {
        .bg = 1,
        .charBaseIndex = 0,
        .mapBaseIndex = 30,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0
    },
    {
        .bg = 2,
        .charBaseIndex = 0,
        .mapBaseIndex = 29,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 0
    },
};

static const struct WindowTemplate sPassWindowTemplates[] =
{
    {
        .bg = 0,
        .tilemapLeft = 2,
        .tilemapTop = 3,
        .width = 12,
        .height = 3,
        .paletteNum = 15,
        .baseBlock = 0x1,
    },
    {
        .bg = 0,
        .tilemapLeft = 2,
        .tilemapTop = 10,
        .width = 12,
        .height = 3,
        .paletteNum = 15,
        .baseBlock = 0x26,
    },
    {
        .bg = 0,
        .tilemapLeft = 2,
        .tilemapTop = 13,
        .width = 12,
        .height = 4,
        .paletteNum = 15,
        .baseBlock = 0x4B,
    },
    {
        .bg = 0,
        .tilemapLeft = 0,
        .tilemapTop = 18,
        .width = 30,
        .height = 3,
        .paletteNum = 15,
        .baseBlock = 0x7C,
    },
    DUMMY_WIN_TEMPLATE
};

static const struct WindowTemplate sMapWindowTemplates[] =
{
    {
        .bg = 0,
        .tilemapLeft = 0,
        .tilemapTop = 1,
        .width = 15,
        .height = 5,
        .paletteNum = 15,
        .baseBlock = 0x1,
    },
    {
        .bg = 0,
        .tilemapLeft = 20,
        .tilemapTop = 1,
        .width = 10,
        .height = 14,
        .paletteNum = 15,
        .baseBlock = 0x4D,
    },
    {
        .bg = 0,
        .tilemapLeft = 2,
        .tilemapTop = 16,
        .width = 26,
        .height = 4,
        .paletteNum = 15,
        .baseBlock = 0xDA,
    },
    DUMMY_WIN_TEMPLATE
};

static const u8 sTextColors[][3] =
{
    {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_DARK_GREY, TEXT_COLOR_LIGHT_GREY},
    {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_WHITE, TEXT_COLOR_LIGHT_BLUE},
    {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_RED, TEXT_COLOR_LIGHT_RED},
};

struct
{
    s16 yStart;
    s16 yEnd;
    s16 xStart;
    s16 xEnd;
}
static const sPassAreasLayout[] =
{
    {28, 76, 132, 220},
    {84, 132, 132, 220},
    {80, 102, 20, 108},
    {0, 16, 152, 240},
    {108, 134, 20, 108},
    {24, 48, 20, 108},
    {50, 66, 20, 36},
    {66, 82, 32, 48},
    {50, 66, 44, 60},
    {66, 82, 56, 72},
    {50, 66, 68, 84},
    {66, 82, 80, 96},
    {50, 66, 92, 108},
};

static const struct CompressedSpriteSheet sCursorSpriteSheets[] =
{
    {sCursorGfx, 0x100, 0},
    {sMapCursorGfx, 0x400, 1},
    {gFrontierPassMedals_Gfx, 0x380, 2},
};

static const struct CompressedSpriteSheet sHeadsSpriteSheet[] =
{
    {sHeadsGfx, 0x100, 4},
    {}
};

static const struct SpritePalette sSpritePalettes[] =
{
    {gFrontierPassCursor_Pal, 0},
    {gFrontierPassMapCursor_Pal, 1},
    {gFrontierPassMedalsSilver_Pal, 2},
    {gFrontierPassMedalsGold_Pal, 3},
    {sMaleHeadPalette, 4},
    {sFemaleHeadPalette, 5},
    {}
};

static const union AnimCmd sSpriteAnim_857151C[] =
{
    ANIMCMD_FRAME(0, 0),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_8571524[] =
{
    ANIMCMD_FRAME(0, 0),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_857152C[] =
{
    ANIMCMD_FRAME(4, 0),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_8571534[] =
{
    ANIMCMD_FRAME(8, 0),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_857153C[] =
{
    ANIMCMD_FRAME(12, 0),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_8571544[] =
{
    ANIMCMD_FRAME(16, 0),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_857154C[] =
{
    ANIMCMD_FRAME(20, 0),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_8571554[] =
{
    ANIMCMD_FRAME(24, 0),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_857155C[] =
{
    ANIMCMD_FRAME(0, 45),
    ANIMCMD_FRAME(8, 45),
    ANIMCMD_JUMP(0)
};

static const union AnimCmd sSpriteAnim_8571568[] =
{
    ANIMCMD_FRAME(16, 45),
    ANIMCMD_FRAME(24, 45),
    ANIMCMD_JUMP(0)
};

static const union AnimCmd *const sSpriteAnimTable_8571574[] =
{
    sSpriteAnim_8571524,
    sSpriteAnim_857152C
};

static const union AnimCmd *const sSpriteAnimTable_857157C[] =
{
    sSpriteAnim_8571524,
    sSpriteAnim_857152C,
    sSpriteAnim_8571534,
    sSpriteAnim_857153C,
    sSpriteAnim_8571544,
    sSpriteAnim_857154C,
    sSpriteAnim_8571554
};

static const union AnimCmd *const sSpriteAnimTable_8571598[] =
{
    sSpriteAnim_857155C,
    sSpriteAnim_8571568
};

static const union AffineAnimCmd sSpriteAffineAnim_85715A0[] =
{
    AFFINEANIMCMD_FRAME(256, 256, 0, 0),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd *const sSpriteAffineAnimTable_85715B0[] =
{
    sSpriteAffineAnim_85715A0
};

static const struct SpriteTemplate sSpriteTemplates_Cursors[] =
{
    {
        .tileTag = 0,
        .paletteTag = 0,
        .oam = &gOamData_AffineOff_ObjNormal_16x16,
        .anims = sSpriteAnimTable_8571574,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCallbackDummy,
    },
    {
        .tileTag = 1,
        .paletteTag = 1,
        .oam = &gOamData_AffineOff_ObjNormal_32x16,
        .anims = sSpriteAnimTable_8571598,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCallbackDummy,
    },
};

static const struct SpriteTemplate sSpriteTemplate_Medal =
{
    .tileTag = 2,
    .paletteTag = 2,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = sSpriteAnimTable_857157C,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const struct SpriteTemplate sSpriteTemplate_Head =
{
    .tileTag = 4,
    .paletteTag = 4,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = sSpriteAnimTable_8571574,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCb_Dummy,
};

static const u8 *const sPassAreaDescriptions[] =
{
    gText_ThereIsNoBattleRecord,
    gText_CheckFrontierMap,
    gText_CheckTrainerCard,
    gText_ViewRecordedBattle,
    gText_PutAwayFrontierPass,
    gText_CurrentBattlePoints,
    gText_CollectedSymbols,
    gText_BattleTowerAbilitySymbol,
    gText_BattleDomeTacticsSymbol,
    gText_BattlePalaceSpiritsSymbol,
    gText_BattleArenaGutsSymbol,
    gText_BattleFactoryKnowledgeSymbol,
    gText_BattlePikeLuckSymbol,
    gText_BattlePyramidBraveSymbol,
    gText_EmptyString7,
};

struct
{
    const u8 *name;
    const u8 *description;
    s16 x;
    s16 y;
    u8 animNum;
} static const sMapLandmarks[] =
{
    {gText_BattleTower3,   gText_BattleTowerDesc,   0x59, 0x28, 1},
    {gText_BattleDome2,    gText_BattleDomeDesc,    0x21, 0x2A, 1},
    {gText_BattlePalace2,  gText_BattlePalaceDesc,  0x78, 0x56, 0},
    {gText_BattleArena2,   gText_BattleArenaDesc,   0x72, 0x3B, 0},
    {gText_BattleFactory2, gText_BattleFactoryDesc, 0x19, 0x43, 0},
    {gText_BattlePike2,    gText_BattlePikeDesc,    0x39, 0x39, 1},
    {gText_BattlePyramid2, gText_BattlePyramidDesc, 0x86, 0x29, 1},
};

// code
static void ResetGpuRegsAndBgs(void)
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

static void LeaveFrontierPass(void)
{
    SetMainCallback2(sPassData->callback);
    FreeFrontierPassData();
}

static u32 AllocateFrontierPassData(void (*callback)(void))
{
    u8 i;

    if (sPassData != NULL)
        return 1;

    sPassData = AllocZeroed(sizeof(*sPassData));
    if (sPassData == NULL)
        return 2;

    sPassData->callback = callback;
    i = GetCurrentRegionMapSectionId();
    if (i != MAPSEC_BATTLE_FRONTIER && i != MAPSEC_ARTISAN_CAVE)
    {
        sPassData->cursorX = 176;
        sPassData->cursorY = 104;
    }
    else
    {
        sPassData->cursorX = 176;
        sPassData->cursorY = 48;
    }

    sPassData->battlePoints = gSaveBlock2Ptr->frontier.battlePoints;
    sPassData->hasBattleRecord = CanCopyRecordedBattleSaveData();
    sPassData->unkE = 0;
    sPassData->trainerStars = CountPlayerTrainerStars();
    for (i = 0; i < 7; i++)
    {
        if (FlagGet(FLAG_SYS_TOWER_SILVER + i * 2))
            sPassData->facilitySymbols[i]++;
        if (FlagGet(FLAG_SYS_TOWER_GOLD + i * 2))
            sPassData->facilitySymbols[i]++;
    }

    return 0;
}

static u32 FreeFrontierPassData(void)
{
    if (sPassData == NULL)
        return 1;

    memset(sPassData, 0, sizeof(*sPassData)); // Why clear data, if it's going to be freed anyway?
    FREE_AND_SET_NULL(sPassData);
    return 0;
}

static u32 AllocateFrontierPassGfx(void)
{
    if (sPassGfx != NULL)
        return 1;

    sPassGfx = AllocZeroed(sizeof(*sPassGfx));
    if (sPassGfx == NULL)
        return 2;

    return 0;
}

static u32 FreeFrontierPassGfx(void)
{
    FreeAllWindowBuffers();
    if (sPassGfx == NULL)
        return 1;

    if (sPassGfx->unk28 != NULL)
        FREE_AND_SET_NULL(sPassGfx->unk28);
    if (sPassGfx->unk24 != NULL)
        FREE_AND_SET_NULL(sPassGfx->unk24);
    if (sPassGfx->unk20 != NULL)
        FREE_AND_SET_NULL(sPassGfx->unk20);

    memset(sPassGfx, 0, sizeof(*sPassGfx)); // Why clear data, if it's going to be freed anyway?
    FREE_AND_SET_NULL(sPassGfx);
    return 0;
}

static void VblankCb_FrontierPass(void)
{
    if (sPassGfx->setAffine)
    {
        SetBgAffine(2,
                    gUnknown_085713E0[sPassData->unkE - 1][0] << 8,
                    gUnknown_085713E0[sPassData->unkE - 1][1] << 8,
                    gUnknown_085713E0[sPassData->unkE - 1][0],
                    gUnknown_085713E0[sPassData->unkE - 1][1],
                    sPassGfx->unk2E,
                    sPassGfx->unk30,
                    0);
    }
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static void CB2_FrontierPass(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
}

static void CB2_InitFrontierPass(void)
{
    if (InitFrontierPass())
    {
        CreateTask(Task_HandleFrontierPassInput, 0);
        SetMainCallback2(CB2_FrontierPass);
    }
}

static void CB2_HideFrontierPass(void)
{
    if (HideFrontierPass())
        LeaveFrontierPass();
}

static bool32 InitFrontierPass(void)
{
    u32 sizeOut = 0;

    switch (sPassData->state)
    {
    case 0:
        SetVBlankCallback(NULL);
        ScanlineEffect_Stop();
        SetVBlankHBlankCallbacksToNull();
        DisableInterrupts(INTR_FLAG_HBLANK);
        break;
    case 1:
        ResetGpuRegsAndBgs();
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
        InitBgsFromTemplates(1, sPassBgTemplates, ARRAY_COUNT(sPassBgTemplates));
        SetBgTilemapBuffer(1, sPassGfx->tilemapBuff1);
        SetBgTilemapBuffer(2, sPassGfx->tilemapBuff2);
        SetBgTilemapBuffer(3, sPassGfx->tilemapBuff3);
        SetBgAttribute(2, BG_ATTR_WRAPAROUND, 1);
        break;
    case 5:
        InitWindows(sPassWindowTemplates);
        DeactivateAllTextPrinters();
        break;
    case 6:
        sPassGfx->unk20 = malloc_and_decompress(gUnknown_085712F8, &sizeOut);
        sPassGfx->unk24 = malloc_and_decompress(gUnknown_08571060, &sizeOut);
        sPassGfx->unk28 = malloc_and_decompress(gUnknown_085712C0, &sizeOut);
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
        LoadPalette(gUnknown_08DE07C8[1 + sPassData->trainerStars], 0x10, 0x20);
        LoadPalette(stdpal_get(0), 0xF0, 0x20);
        sub_80C629C();
        sub_80C6104(sPassData->cursorArea, sPassData->previousCursorArea);
        if (sPassData->unkE == 1 || sPassData->unkE == 2)
        {
            sPassData->state = 0;
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
        BlendPalettes(0xFFFFFFFF, 0x10, RGB_BLACK);
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0x10, 0, RGB_BLACK);
        break;
    case 10:
        AnimateSprites();
        BuildOamBuffer();
        if (UpdatePaletteFade())
            return FALSE;

        sPassData->state = 0;
        return TRUE;
    }

    sPassData->state++;
    return FALSE;
}

static bool32 HideFrontierPass(void)
{
    switch (sPassData->state)
    {
    case 0:
        if (sPassData->unkE != 1 && sPassData->unkE != 2)
        {
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 0x10, RGB_BLACK);
        }
        else
        {
            sPassData->state = 2;
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
        ResetGpuRegsAndBgs();
        ResetTasks();
        ResetSpriteData();
        FreeAllSpritePalettes();
        break;
    case 5:
        UnsetBgTilemapBuffer(0);
        UnsetBgTilemapBuffer(1);
        UnsetBgTilemapBuffer(2);
        FreeFrontierPassGfx();
        sPassData->state = 0;
        return TRUE;
    }

    sPassData->state++;
    return FALSE;
}

static u8 GetCursorAreaFromCoords(s16 x, s16 y)
{
    u8 i;

    // Minus/Plus 1, because the table doesn't take into account the nothing field.
    for (i = 0; i < CURSOR_AREA_COUNT - 1; i++)
    {
        if (sPassAreasLayout[i].yStart <= y && sPassAreasLayout[i].yEnd >= y
            && sPassAreasLayout[i].xStart <= x && sPassAreasLayout[i].xEnd >= x)
        {
            if (i >= CURSOR_AREA_SYMBOL - 1 && sPassData->facilitySymbols[i - CURSOR_AREA_SYMBOL + 1] == 0)
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

    switch (sPassData->unkE)
    {
    case 1:
    case 2:
        taskId = CreateTask(Task_DoFadeEffect, 0);
        gTasks[taskId].data[0] = TRUE;
        break;
    case 3:
    default:
        sPassData->unkE = 0;
        taskId = CreateTask(Task_HandleFrontierPassInput, 0);
        break;
    }

    SetMainCallback2(CB2_FrontierPass);
}

static void CB2_ReturnFromRecord(void)
{
    AllocateFrontierPassData(sSavedPassData.callback);
    sPassData->cursorX = sSavedPassData.cursorX;
    sPassData->cursorY = sSavedPassData.cursorY;
    memset(&sSavedPassData, 0, sizeof(sSavedPassData));
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

static void CB2_ShowFrontierPassFeature(void)
{
    if (!HideFrontierPass())
        return;

    switch (sPassData->unkE)
    {
    case 1:
        ShowFrontierMap(CB2_ReshowFrontierPass);
        break;
    case 3:
        sSavedPassData.callback = sPassData->callback;
        sSavedPassData.cursorX = sPassData->cursorX;
        sSavedPassData.cursorY = sPassData->cursorY;
        FreeFrontierPassData();
        PlayRecordedBattle(CB2_ReturnFromRecord);
        break;
    case 2:
        ShowPlayerTrainerCard(CB2_ReshowFrontierPass);
        break;
    }
}

static bool32 TryCallPassAreaFunction(u8 taskId, u8 cursorArea)
{
    switch (cursorArea)
    {
    case CURSOR_AREA_RECORD:
        if (!sPassData->hasBattleRecord)
            return FALSE;
        sPassData->unkE = 3;
        DestroyTask(taskId);
        SetMainCallback2(CB2_ShowFrontierPassFeature);
        break;
    case CURSOR_AREA_MAP:
    case CURSOR_AREA_CARD:
        sPassData->unkE = cursorArea;
        gTasks[taskId].func = Task_DoFadeEffect;
        gTasks[taskId].data[0] = FALSE;
        break;
    default:
        return FALSE;
    }

    sPassData->cursorX = sPassGfx->cursorSprite->pos1.x;
    sPassData->cursorY = sPassGfx->cursorSprite->pos1.y;
    return TRUE;
}

static void Task_HandleFrontierPassInput(u8 taskId)
{
    u8 var = FALSE; // Reused, first informs whether the cursor moves, then used as the new cursor area.

    if (gMain.heldKeys & DPAD_UP && sPassGfx->cursorSprite->pos1.y >= 9)
    {
        sPassGfx->cursorSprite->pos1.y -= 2;
        if (sPassGfx->cursorSprite->pos1.y <= 7)
            sPassGfx->cursorSprite->pos1.y = 2;
        var = TRUE;
    }
    if (gMain.heldKeys & DPAD_DOWN && sPassGfx->cursorSprite->pos1.y <= 135)
    {
        sPassGfx->cursorSprite->pos1.y += 2;
        if (sPassGfx->cursorSprite->pos1.y >= 137)
            sPassGfx->cursorSprite->pos1.y = 136;
        var = TRUE;
    }

    if (gMain.heldKeys & DPAD_LEFT && sPassGfx->cursorSprite->pos1.x >= 6)
    {
        sPassGfx->cursorSprite->pos1.x -= 2;
        if (sPassGfx->cursorSprite->pos1.x <= 4)
            sPassGfx->cursorSprite->pos1.x = 5;
        var = TRUE;
    }
    if (gMain.heldKeys & DPAD_RIGHT && sPassGfx->cursorSprite->pos1.x <= 231)
    {
        sPassGfx->cursorSprite->pos1.x += 2;
        if (sPassGfx->cursorSprite->pos1.x >= 233)
            sPassGfx->cursorSprite->pos1.x = 232;
        var = TRUE;
    }

    if (!var) // Cursor did not change.
    {
        if (sPassData->cursorArea != CURSOR_AREA_NOTHING && gMain.newKeys & A_BUTTON)
        {
            if (sPassData->cursorArea <= CURSOR_AREA_RECORD) // Map, Card, Record
            {
                PlaySE(SE_SELECT);
                if (TryCallPassAreaFunction(taskId, sPassData->cursorArea))
                    return;
            }
            else if (sPassData->cursorArea == CURSOR_AREA_CANCEL)
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
        var = GetCursorAreaFromCoords(sPassGfx->cursorSprite->pos1.x - 5, sPassGfx->cursorSprite->pos1.y + 5);
        if (sPassData->cursorArea != var)
        {
            PrintAreaDescription(var);
            sPassData->previousCursorArea = sPassData->cursorArea;
            sPassData->cursorArea = var;
            sub_80C6104(sPassData->cursorArea, sPassData->previousCursorArea);
        }
    }
}

static void Task_DoFadeEffect(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    switch (sPassData->state)
    {
    case 0:
        if (!data[0])
        {
            sub_80C5F58(TRUE, FALSE);
            data[1] = Q_8_8(1);
            data[2] = Q_8_8(1);
            data[3] = 0x15;
            data[4] = 0x15;
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 0x10, RGB_WHITE);
        }
        else
        {
            data[1] = Q_8_8(1.984375); // 1 and 63/64
            data[2] = Q_8_8(1.984375);
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
        sPassGfx->setAffine = TRUE;
        sPassGfx->unk2E = MathUtil_Inv16(data[1]);
        sPassGfx->unk30 = MathUtil_Inv16(data[2]);
        break;
    case 1:
        UpdatePaletteFade();
        data[1] += data[3];
        data[2] += data[4];
        sPassGfx->unk2E = MathUtil_Inv16(data[1]);
        sPassGfx->unk30 = MathUtil_Inv16(data[2]);
        if (!data[0])
        {
            if (data[1] <= Q_8_8(1.984375))
                return;
        }
        else
        {
            if (data[1] != Q_8_8(1))
                return;
        }
        break;
    case 2:
        if (sPassGfx->setAffine) // Nonsensical check.
            sPassGfx->setAffine = FALSE;
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
            sPassData->unkE = 0;
            gTasks[taskId].func = Task_HandleFrontierPassInput;
        }
        SetBgAttribute(2, BG_ATTR_WRAPAROUND, 0);
        sPassData->state = 0;
        return;
    }

    sPassData->state++;
}

static void ShowAndPrintWindows(void)
{
    s32 x;
    u8 i;

    for (i = 0; i < WINDOW_COUNT; i++)
    {
        PutWindowTilemap(i);
        FillWindowPixelBuffer(i, PIXEL_FILL(0));
    }

    x = GetStringCenterAlignXOffset(1, gText_SymbolsEarned, 96);
    AddTextPrinterParameterized3(WINDOW_EARNED_SYMBOLS, 1, x, 5, sTextColors[0], 0, gText_SymbolsEarned);

    x = GetStringCenterAlignXOffset(1, gText_BattleRecord, 96);
    AddTextPrinterParameterized3(WINDOW_BATTLE_RECORD, 1, x, 5, sTextColors[0], 0, gText_BattleRecord);

    AddTextPrinterParameterized3(WINDOW_BATTLE_POINTS, 8, 5, 4, sTextColors[0], 0, gText_BattlePoints);
    ConvertIntToDecimalStringN(gStringVar4, sPassData->battlePoints, STR_CONV_MODE_LEFT_ALIGN, 5);
    x = GetStringRightAlignXOffset(8, gStringVar4, 91);
    AddTextPrinterParameterized3(WINDOW_BATTLE_POINTS, 8, x, 16, sTextColors[0], 0, gStringVar4);

    sPassData->cursorArea = GetCursorAreaFromCoords(sPassData->cursorX - 5, sPassData->cursorY + 5);
    sPassData->previousCursorArea = CURSOR_AREA_NOTHING;
    PrintAreaDescription(sPassData->cursorArea);

    for (i = 0; i < WINDOW_COUNT; i++)
        CopyWindowToVram(i, 3);

    CopyBgTilemapBufferToVram(0);
}

static void PrintAreaDescription(u8 cursorArea)
{
    FillWindowPixelBuffer(WINDOW_DESCRIPTION, PIXEL_FILL(0));
    if (cursorArea == CURSOR_AREA_RECORD && !sPassData->hasBattleRecord)
        AddTextPrinterParameterized3(WINDOW_DESCRIPTION, 1, 2, 0, sTextColors[1], 0, sPassAreaDescriptions[0]);
    else if (cursorArea != CURSOR_AREA_NOTHING)
        AddTextPrinterParameterized3(WINDOW_DESCRIPTION, 1, 2, 0, sTextColors[1], 0, sPassAreaDescriptions[cursorArea]);

    CopyWindowToVram(WINDOW_DESCRIPTION, 3);
    CopyBgTilemapBufferToVram(0);
}

static void sub_80C5F58(bool8 arg0, bool8 arg1)
{
    switch (sPassData->unkE)
    {
    case 1:
        if (arg0)
            CopyToBgTilemapBufferRect_ChangePalette(2, sPassGfx->unk20, 16, 3, 12, 7, 16);
        else
            FillBgTilemapBufferRect(2, 0, 16, 3, 12, 7, 16);
        break;
    case 2:
        if (arg0)
            CopyToBgTilemapBufferRect_ChangePalette(2, sPassGfx->unk20 + 84, 16, 10, 12, 7, 16);
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
                    gUnknown_085713E0[sPassData->unkE - 1][0] << 8,
                    gUnknown_085713E0[sPassData->unkE - 1][1] << 8,
                    gUnknown_085713E0[sPassData->unkE - 1][0],
                    gUnknown_085713E0[sPassData->unkE - 1][1],
                    MathUtil_Inv16(Q_8_8(1.984375)), // 1 and 63/64
                    MathUtil_Inv16(Q_8_8(1.984375)),
                    0);
    }
    else
    {
        SetBgAffine(2,
                    gUnknown_085713E0[sPassData->unkE - 1][0] << 8,
                    gUnknown_085713E0[sPassData->unkE - 1][1] << 8,
                    gUnknown_085713E0[sPassData->unkE - 1][0],
                    gUnknown_085713E0[sPassData->unkE - 1][1],
                    MathUtil_Inv16(Q_8_8(1)),
                    MathUtil_Inv16(Q_8_8(1)),
                    0);
    }
}

static void sub_80C6104(u8 cursorArea, u8 previousCursorArea)
{
    bool32 var;

    switch (previousCursorArea)
    {
    case CURSOR_AREA_MAP:
        CopyToBgTilemapBufferRect_ChangePalette(1, sPassGfx->unk24, 16, 3, 12, 7, 17);
        var = TRUE;
        break;
    case CURSOR_AREA_CARD:
        CopyToBgTilemapBufferRect_ChangePalette(1, sPassGfx->unk24 + 336, 16, 10, 12, 7, 17);
        var = TRUE;
        break;
    case CURSOR_AREA_RECORD:
        if (!sPassData->hasBattleRecord)
        {
            var = FALSE;
        }
        else
        {
            CopyToBgTilemapBufferRect_ChangePalette(1, sPassGfx->unk28, 2, 10, 12, 3, 17);
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
        CopyToBgTilemapBufferRect_ChangePalette(1, sPassGfx->unk24 + 168, 16, 3, 12, 7, 17);
        var = TRUE;
        break;
    case CURSOR_AREA_CARD:
        CopyToBgTilemapBufferRect_ChangePalette(1, sPassGfx->unk24 + 504, 16, 10, 12, 7, 17);
        var = TRUE;
        break;
    case CURSOR_AREA_RECORD:
        if (!sPassData->hasBattleRecord)
            return;

        CopyToBgTilemapBufferRect_ChangePalette(1, sPassGfx->unk28 + 72, 2, 10, 12, 3, 17);
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

static void sub_80C629C(void)
{
    CopyToBgTilemapBuffer(1, gUnknown_08DE3060, 0, 0);
    sub_80C6104(sPassData->cursorArea, sPassData->previousCursorArea);
    sub_80C5F58(TRUE, sPassData->unkE);
    ShowAndPrintWindows();
    CopyBgTilemapBufferToVram(1);
}

static void LoadCursorAndSymbolSprites(void)
{
    u8 spriteId;
    u8 i = 0;

    FreeAllSpritePalettes();
    ResetAffineAnimData();
    LoadSpritePalettes(sSpritePalettes);
    LoadCompressedSpriteSheet(&sCursorSpriteSheets[0]);
    LoadCompressedSpriteSheet(&sCursorSpriteSheets[2]);
    spriteId = CreateSprite(&sSpriteTemplates_Cursors[0], sPassData->cursorX, sPassData->cursorY, 0);
    sPassGfx->cursorSprite = &gSprites[spriteId];
    sPassGfx->cursorSprite->oam.priority = 0;

    for (i = 0; i < NUM_FRONTIER_FACILITIES; i++)
    {
        if (sPassData->facilitySymbols[i] != 0)
        {
            struct SpriteTemplate sprite = sSpriteTemplate_Medal;

            sprite.paletteTag += sPassData->facilitySymbols[i] - 1;
            spriteId = CreateSprite(&sprite, sPassAreasLayout[i + CURSOR_AREA_SYMBOL - 1].xStart + 8, sPassAreasLayout[i + CURSOR_AREA_SYMBOL - 1].yStart + 6, i + 1);
            sPassGfx->symbolSprites[i] = &gSprites[spriteId];
            sPassGfx->symbolSprites[i]->oam.priority = 2;
            StartSpriteAnim(sPassGfx->symbolSprites[i], i);
        }
    }
}

static void FreeCursorAndSymbolSprites(void)
{
    u8 i = 0;

    DestroySprite(sPassGfx->cursorSprite);
    sPassGfx->cursorSprite = NULL;
    for (i = 0; i < NUM_FRONTIER_FACILITIES; i++)
    {
        if (sPassGfx->symbolSprites[i] != NULL)
        {
            DestroySprite(sPassGfx->symbolSprites[i]);
            sPassGfx->symbolSprites[i] = NULL;
        }
    }
    FreeAllSpritePalettes();
    FreeSpriteTilesByTag(2);
    FreeSpriteTilesByTag(0);
}

static void SpriteCb_Dummy(struct Sprite *sprite)
{

}

// Frontier Map code.

// Forward declarations.
static void Task_HandleFrontierMap(u8 taskId);
static void PrintOnFrontierMap(void);
static void InitFrontierMapSprites(void);
static void HandleFrontierMapCursorMove(u8 direction);

static void ShowFrontierMap(void (*callback)(void))
{
    if (sMapData != NULL)
        SetMainCallback2(callback); // This line doesn't make sense at all, since it gets overwritten later anyway.

    sMapData = AllocZeroed(sizeof(*sMapData));
    sMapData->callback = callback;
    ResetTasks();
    CreateTask(Task_HandleFrontierMap, 0);
    SetMainCallback2(CB2_FrontierPass);
}

static void FreeFrontierMap(void)
{
    ResetTasks();
    SetMainCallback2(sMapData->callback);
    memset(sMapData, 0, sizeof(*sMapData)); // Pointless memory clear.
    FREE_AND_SET_NULL(sMapData);
}

static bool32 InitFrontierMap(void)
{
    switch (sPassData->state)
    {
    case 0:
        SetVBlankCallback(NULL);
        ScanlineEffect_Stop();
        SetVBlankHBlankCallbacksToNull();
        break;
    case 1:
        ResetGpuRegsAndBgs();
        break;
    case 2:
        ResetSpriteData();
        FreeAllSpritePalettes();
        ResetPaletteFade();
        reset_temp_tile_data_buffers();
        break;
    case 3:
        ResetBgsAndClearDma3BusyFlags(0);
        InitBgsFromTemplates(0, sMapBgTemplates, ARRAY_COUNT(sMapBgTemplates));
        SetBgTilemapBuffer(0, sMapData->tilemapBuff0);
        SetBgTilemapBuffer(1, sMapData->tilemapBuff1);
        SetBgTilemapBuffer(2, sMapData->tilemapBuff2);
        FillBgTilemapBufferRect_Palette0(0, 0, 0, 0, 30, 20);
        FillBgTilemapBufferRect_Palette0(1, 0, 0, 0, 30, 20);
        FillBgTilemapBufferRect_Palette0(2, 0, 0, 0, 30, 20);
        CopyBgTilemapBufferToVram(0);
        CopyBgTilemapBufferToVram(1);
        CopyBgTilemapBufferToVram(2);
        break;
    case 4:
        InitWindows(sMapWindowTemplates);
        DeactivateAllTextPrinters();
        PrintOnFrontierMap();
        decompress_and_copy_tile_data_to_vram(1, gUnknown_0856FBBC, 0, 0, 0);
        break;
    case 5:
        if (free_temp_tile_data_buffers_if_possible())
            return FALSE;
        LoadPalette(gUnknown_08DE07C8[0], 0, 0x1A0);
        LoadPalette(stdpal_get(0), 0xF0, 0x20);
        CopyToBgTilemapBuffer(2, gUnknown_08570E00, 0, 0);
        CopyBgTilemapBufferToVram(2);
        break;
    case 6:
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
        ShowBg(0);
        ShowBg(1);
        ShowBg(2);
        InitFrontierMapSprites();
        SetVBlankCallback(VblankCb_FrontierPass);
        BlendPalettes(0xFFFFFFFF, 0x10, RGB_WHITE);
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0x10, 0, RGB_WHITE);
        break;
    case 7:
        if (UpdatePaletteFade())
            return FALSE;
        sPassData->state = 0;
        return TRUE;
    }

    sPassData->state++;
    return FALSE;
}

static bool32 ExitFrontierMap(void)
{
    switch (sPassData->state)
    {
    case 0:
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 0x10, RGB_WHITE);
        break;
    case 1:
        if (UpdatePaletteFade())
            return FALSE;
        SetGpuReg(REG_OFFSET_DISPCNT, 0);
        HideBg(0);
        HideBg(1);
        HideBg(2);
        break;
    case 2:
        SetVBlankCallback(NULL);
        ScanlineEffect_Stop();
        SetVBlankHBlankCallbacksToNull();
        break;
    case 3:
        if (sMapData->cursorSprite != NULL)
        {
            DestroySprite(sMapData->cursorSprite);
            FreeSpriteTilesByTag(0);
        }
        if (sMapData->mapIndicatorSprite != NULL)
        {
            DestroySprite(sMapData->mapIndicatorSprite);
            FreeSpriteTilesByTag(1);
        }
        if (sMapData->playerHeadSprite != NULL)
        {
            DestroySprite(sMapData->playerHeadSprite);
            FreeSpriteTilesByTag(4);
        }
        FreeAllWindowBuffers();
        break;
    case 4:
        ResetGpuRegsAndBgs();
        ResetSpriteData();
        FreeAllSpritePalettes();
        break;
    case 5:
        UnsetBgTilemapBuffer(0);
        UnsetBgTilemapBuffer(1);
        UnsetBgTilemapBuffer(2);
        sPassData->state = 0;
        return TRUE;
    }

    sPassData->state++;
    return FALSE;
}

static void Task_HandleFrontierMap(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    switch (data[0])
    {
    case 0:
        if (InitFrontierMap())
            break;
        return;
    case 1:
        if (gMain.newKeys & B_BUTTON)
        {
            PlaySE(SE_PC_OFF);
            data[0] = 4;
        }
        else if (gMain.newKeys & DPAD_DOWN)
        {
            if (sMapData->cursorPos >= NUM_FRONTIER_FACILITIES - 1)
                HandleFrontierMapCursorMove(0);
            else
                data[0] = 2;
        }
        else if (gMain.newKeys & DPAD_UP)
        {
            if (sMapData->cursorPos == 0)
                HandleFrontierMapCursorMove(1);
            else
                data[0] = 3;
        }
        return;
    case 2:
        if (data[1] > 3)
        {
            HandleFrontierMapCursorMove(0);
            data[1] = 0;
            data[0] = 1;
        }
        else
        {
            sMapData->cursorSprite->pos1.y += 4;
            data[1]++;
        }
        return;
    case 3:
        if (data[1] > 3)
        {
            HandleFrontierMapCursorMove(1);
            data[1] = 0;
            data[0] = 1;
        }
        else
        {
            sMapData->cursorSprite->pos1.y -= 4;
            data[1]++;
        }
        return;
    case 4:
        if (ExitFrontierMap())
            break;
        return;
    case 5:
        DestroyTask(taskId);
        FreeFrontierMap();
        return;
    }

    data[0]++;
}

static u8 MapNumToFrontierFacilityId(u16 mapNum) // id + 1, zero means not a frontier map number
{
    if ((mapNum >= MAP_NUM(BATTLE_FRONTIER_BATTLE_TOWER_LOBBY) && mapNum <= MAP_NUM(BATTLE_FRONTIER_BATTLE_TOWER_BATTLE_ROOM))
        || (mapNum >= MAP_NUM(BATTLE_FRONTIER_BATTLE_TOWER_MULTI_PARTNER_ROOM) && mapNum <= MAP_NUM(BATTLE_FRONTIER_BATTLE_TOWER_MULTI_BATTLE_ROOM)))
        return FRONTIER_FACILITY_TOWER + 1;
    else if (mapNum == MAP_NUM(BATTLE_FRONTIER_BATTLE_DOME_LOBBY)
             || mapNum == MAP_NUM(BATTLE_FRONTIER_BATTLE_DOME_CORRIDOR)
             || mapNum == MAP_NUM(BATTLE_FRONTIER_BATTLE_DOME_PRE_BATTLE_ROOM)
             || mapNum == MAP_NUM(BATTLE_FRONTIER_BATTLE_DOME_BATTLE_ROOM))
        return FRONTIER_FACILITY_DOME + 1;
    else if (mapNum == MAP_NUM(BATTLE_FRONTIER_BATTLE_PALACE_LOBBY)
        || mapNum == MAP_NUM(BATTLE_FRONTIER_BATTLE_PALACE_CORRIDOR)
        || mapNum == MAP_NUM(BATTLE_FRONTIER_BATTLE_PALACE_BATTLE_ROOM))
        return FRONTIER_FACILITY_PALACE + 1;
    else if (mapNum == MAP_NUM(BATTLE_FRONTIER_BATTLE_ARENA_LOBBY)
        || mapNum == MAP_NUM(BATTLE_FRONTIER_BATTLE_ARENA_CORRIDOR)
        || mapNum == MAP_NUM(BATTLE_FRONTIER_BATTLE_ARENA_BATTLE_ROOM))
        return FRONTIER_FACILITY_ARENA + 1;
    else if (mapNum == MAP_NUM(BATTLE_FRONTIER_BATTLE_FACTORY_LOBBY)
        || mapNum == MAP_NUM(BATTLE_FRONTIER_BATTLE_FACTORY_PRE_BATTLE_ROOM)
        || mapNum == MAP_NUM(BATTLE_FRONTIER_BATTLE_FACTORY_BATTLE_ROOM))
        return FRONTIER_FACILITY_FACTORY + 1;
    else if (mapNum == MAP_NUM(BATTLE_FRONTIER_BATTLE_PIKE_LOBBY)
             || mapNum == MAP_NUM(BATTLE_FRONTIER_BATTLE_PIKE_CORRIDOR)
             || mapNum == MAP_NUM(BATTLE_FRONTIER_BATTLE_PIKE_THREE_PATH_ROOM)
             || mapNum == MAP_NUM(BATTLE_FRONTIER_BATTLE_PIKE_ROOM_NORMAL)
             || mapNum == MAP_NUM(BATTLE_FRONTIER_BATTLE_PIKE_ROOM_FINAL)
             || mapNum == MAP_NUM(BATTLE_FRONTIER_BATTLE_PIKE_ROOM_WILD_MONS))
        return FRONTIER_FACILITY_PIKE + 1;
    else if (mapNum == MAP_NUM(BATTLE_FRONTIER_BATTLE_PYRAMID_LOBBY)
        || mapNum == MAP_NUM(BATTLE_FRONTIER_BATTLE_PYRAMID_FLOOR)
        || mapNum == MAP_NUM(BATTLE_FRONTIER_BATTLE_PYRAMID_TOP))
        return FRONTIER_FACILITY_PYRAMID + 1;
    else
        return 0;
}

static void InitFrontierMapSprites(void)
{
    struct SpriteTemplate sprite;
    u8 spriteId;
    u8 id;
    s16 x = 0, y;

    FreeAllSpritePalettes();
    LoadSpritePalettes(sSpritePalettes);

    LoadCompressedSpriteSheet(&sCursorSpriteSheets[0]);
    spriteId = CreateSprite(&sSpriteTemplates_Cursors[0], 155, (sMapData->cursorPos * 16) + 8, 2);
    sMapData->cursorSprite = &gSprites[spriteId];
    sMapData->cursorSprite->oam.priority = 0;
    sMapData->cursorSprite->hFlip = TRUE;
    StartSpriteAnim(sMapData->cursorSprite, 1);

    LoadCompressedSpriteSheet(&sCursorSpriteSheets[1]);
    spriteId = CreateSprite(&sSpriteTemplates_Cursors[1], sMapLandmarks[sMapData->cursorPos].x, sMapLandmarks[sMapData->cursorPos].y, 1);
    sMapData->mapIndicatorSprite = &gSprites[spriteId];
    sMapData->mapIndicatorSprite->oam.priority = 0;
    StartSpriteAnim(sMapData->mapIndicatorSprite, sMapLandmarks[sMapData->cursorPos].animNum);

    // Create player indicator head sprite only if it's in vicinity of battle frontier.
    id = GetCurrentRegionMapSectionId();
    if (id == MAPSEC_BATTLE_FRONTIER || id == MAPSEC_ARTISAN_CAVE)
    {
        s8 mapNum = gSaveBlock1Ptr->location.mapNum;

        if (mapNum == MAP_NUM(BATTLE_FRONTIER_OUTSIDE_WEST)
            || (mapNum == MAP_NUM(BATTLE_FRONTIER_OUTSIDE_EAST) && (x = 55)))
        {
            x += gSaveBlock1Ptr->pos.x;
            y = gSaveBlock1Ptr->pos.y;

            x /= 8;
            y /= 8;

            id = 0;
        }
        else
        {
            id = MapNumToFrontierFacilityId(mapNum);
            if (id != 0)
            {
                x = sMapLandmarks[id - 1].x;
                y = sMapLandmarks[id - 1].y;
            }
            else
            {
                // Handle Artisan Cave.
                if (gSaveBlock1Ptr->escapeWarp.mapNum == MAP_NUM(BATTLE_FRONTIER_OUTSIDE_EAST))
                    x = gSaveBlock1Ptr->escapeWarp.x + 55;
                else
                    x = gSaveBlock1Ptr->escapeWarp.x;

                y = gSaveBlock1Ptr->escapeWarp.y;

                x /= 8;
                y /= 8;
            }
        }

        LoadCompressedSpriteSheet(sHeadsSpriteSheet);
        sprite = sSpriteTemplate_Head;
        sprite.paletteTag = gSaveBlock2Ptr->playerGender + 4;
        if (id != 0)
        {
            spriteId = CreateSprite(&sprite, x, y, 0);
        }
        else
        {
            x *= 8;
            y *= 8;
            spriteId = CreateSprite(&sprite, x + 20, y + 36, 0);
        }

        sMapData->playerHeadSprite = &gSprites[spriteId];
        sMapData->playerHeadSprite->oam.priority = 0;
        if (gSaveBlock2Ptr->playerGender != MALE)
            StartSpriteAnim(sMapData->playerHeadSprite, 1);
    }
}

static void PrintOnFrontierMap(void)
{
    u8 i;

    for (i = 0; i < MAP_WINDOW_COUNT; i++)
    {
        PutWindowTilemap(i);
        FillWindowPixelBuffer(i, PIXEL_FILL(0));
    }

    for (i = 0; i < NUM_FRONTIER_FACILITIES; i++)
    {
        if (i == sMapData->cursorPos)
            AddTextPrinterParameterized3(MAP_WINDOW_NAME, 7, 4, (i * 16) + 1, sTextColors[2], 0, sMapLandmarks[i].name);
        else
            AddTextPrinterParameterized3(MAP_WINDOW_NAME, 7, 4, (i * 16) + 1, sTextColors[1], 0, sMapLandmarks[i].name);
    }

    AddTextPrinterParameterized3(MAP_WINDOW_DESCRIPTION, 1, 4, 0, sTextColors[0], 0, sMapLandmarks[sMapData->cursorPos].description);

    for (i = 0; i < MAP_WINDOW_COUNT; i++)
        CopyWindowToVram(i, 3);

    CopyBgTilemapBufferToVram(0);
}

static void HandleFrontierMapCursorMove(u8 direction)
{
    u8 oldCursorPos, i;

    if (direction)
    {
        oldCursorPos = sMapData->cursorPos;
        sMapData->cursorPos = (oldCursorPos + 6) % NUM_FRONTIER_FACILITIES;
    }
    else
    {
        oldCursorPos = sMapData->cursorPos;
        sMapData->cursorPos = (oldCursorPos + 1) % NUM_FRONTIER_FACILITIES;
    }

    AddTextPrinterParameterized3(MAP_WINDOW_NAME, 7, 4, (oldCursorPos * 16) + 1, sTextColors[1], 0, sMapLandmarks[oldCursorPos].name);
    AddTextPrinterParameterized3(MAP_WINDOW_NAME, 7, 4, (sMapData->cursorPos * 16) + 1, sTextColors[2], 0, sMapLandmarks[sMapData->cursorPos].name);

    sMapData->cursorSprite->pos1.y = (sMapData->cursorPos * 16) + 8;

    StartSpriteAnim(sMapData->mapIndicatorSprite, sMapLandmarks[sMapData->cursorPos].animNum);
    sMapData->mapIndicatorSprite->pos1.x = sMapLandmarks[sMapData->cursorPos].x;
    sMapData->mapIndicatorSprite->pos1.y = sMapLandmarks[sMapData->cursorPos].y;
    FillWindowPixelBuffer(MAP_WINDOW_DESCRIPTION, PIXEL_FILL(0));
    AddTextPrinterParameterized3(MAP_WINDOW_DESCRIPTION, 1, 4, 0, sTextColors[0], 0, sMapLandmarks[sMapData->cursorPos].description);

    for (i = 0; i < 3; i++)
        CopyWindowToVram(i, 3);

    CopyBgTilemapBufferToVram(0);
    PlaySE(SE_Z_SCROLL);
}
