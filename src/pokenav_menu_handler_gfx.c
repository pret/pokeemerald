#include "global.h"
#include "malloc.h"
#include "decompress.h"
#include "bg.h"
#include "palette.h"
#include "trig.h"
#include "gpu_regs.h"
#include "menu.h"
#include "window.h"
#include "pokenav.h"
#include "graphics.h"
#include "sound.h"
#include "gym_leader_rematch.h"
#include "window.h"
#include "strings.h"
#include "scanline_effect.h"
#include "constants/songs.h"
#include "constants/rgb.h"

#define GFXTAG_BLUE_LIGHT 1
#define GFXTAG_OPTIONS    3

#define PALTAG_BLUE_LIGHT 3
#define PALTAG_OPTIONS_DEFAULT 4 // Includes green for Smart/Region Map and yellow for Tough
#define PALTAG_OPTIONS_BLUE 5
#define PALTAG_OPTIONS_PINK 6
#define PALTAG_OPTIONS_BEIGE 7
#define PALTAG_OPTIONS_RED 8

#define PALTAG_OPTIONS_START PALTAG_OPTIONS_DEFAULT

#define NUM_OPTION_SUBSPRITES 4

#define OPTION_DEFAULT_X   140
#define OPTION_SELECTED_X  130
#define OPTION_EXIT_X      (DISPLAY_WIDTH + 16)

struct Pokenav_MenuGfx
{
    bool32 (*isTaskActiveCB)(void);
    u32 loopedTaskId;
    u16 optionDescWindowId;
    u8 bg3ScrollTaskId;
    u8 cursorPos;
    u8 numIconsBlending;
    bool8 pokenavAlreadyOpen;
    bool32 iconVisible[MAX_POKENAV_MENUITEMS];
    struct Sprite * blueLightSprite;
    struct Sprite * iconSprites[MAX_POKENAV_MENUITEMS][NUM_OPTION_SUBSPRITES];
    u8 bg1TilemapBuffer[BG_SCREEN_SIZE];
};

static struct Pokenav_MenuGfx * OpenPokenavMenu(void);
static bool32 GetCurrentLoopedTaskActive(void);
static u32 LoopedTask_OpenMenu(s32);
static u32 LoopedTask_MoveMenuCursor(s32);
static u32 LoopedTask_OpenConditionMenu(s32);
static u32 LoopedTask_ReturnToMainMenu(s32);
static u32 LoopedTask_OpenConditionSearchMenu(s32);
static u32 LoopedTask_ReturnToConditionMenu(s32);
static u32 LoopedTask_SelectRibbonsNoWinners(s32);
static u32 LoopedTask_ReShowDescription(s32);
static u32 LoopedTask_OpenPokenavFeature(s32);
static void LoadPokenavOptionPalettes(void);
static void FreeAndDestroyMainMenuSprites(void);
static void CreateMenuOptionSprites(void);
static void DestroyMenuOptionSprites(void);
static void DrawCurrentMenuOptionLabels(void);
static void DrawOptionLabelGfx(const u16 *const *, s32, s32);
static void StartOptionAnimations_Enter(void);
static void StartOptionAnimations_CursorMoved(void);
static void StartOptionAnimations_Exit(void);
static void StartOptionSlide(struct Sprite **, s32, s32, s32);
static void StartOptionZoom(struct Sprite **);
static bool32 AreMenuOptionSpritesMoving(void);
static void SetOptionInvisibility(struct Sprite **, bool32);
static void SpriteCB_OptionSlide(struct Sprite *);
static void SpriteCB_OptionZoom(struct Sprite *);
static void Task_OptionBlend(u8);
static void CreateMatchCallBlueLightSprite(void);
static void SpriteCB_BlinkingBlueLight(struct Sprite *);
static void DestroyRematchBlueLightSprite(void);
static void AddOptionDescriptionWindow(void);
static void PrintCurrentOptionDescription(void);
static void PrintNoRibbonWinners(void);
static bool32 IsDma3ManagerBusyWithBgCopy_(void);
static void CreateMovingBgDotsTask(void);
static void DestroyMovingDotsBgTask(void);
static void Task_MoveBgDots(u8);
static void CreateBgDotPurplePalTask(void);
static void ChangeBgDotsColorToPurple(void);
static void CreateBgDotLightBluePalTask(void);
static bool32 IsTaskActive_UpdateBgDotsPalette(void);
static void Task_UpdateBgDotsPalette(u8);
static void SetupPokenavMenuScanlineEffects(void);
static void DestroyMenuOptionGlowTask(void);
static void ResetBldCnt(void);
static void InitMenuOptionGlow(void);
static void Task_CurrentMenuOptionGlow(u8);
static void SetMenuOptionGlow(void);

static const u16 sPokenavBgDotsPal[] = INCBIN_U16("graphics/pokenav/bg_dots.gbapal");
static const u32 sPokenavBgDotsTiles[] = INCBIN_U32("graphics/pokenav/bg_dots.4bpp.lz");
static const u32 sPokenavBgDotsTilemap[] = INCBIN_U32("graphics/pokenav/bg_dots.bin.lz");
static const u16 sPokenavDeviceBgPal[] = INCBIN_U16("graphics/pokenav/device_outline.gbapal");
static const u32 sPokenavDeviceBgTiles[] = INCBIN_U32("graphics/pokenav/device_outline.4bpp.lz");
static const u32 sPokenavDeviceBgTilemap[] = INCBIN_U32("graphics/pokenav/device_outline_map.bin.lz");
static const u16 sMatchCallBlueLightPal[] = INCBIN_U16("graphics/pokenav/blue_light.gbapal");
static const u32 sMatchCallBlueLightTiles[] = INCBIN_U32("graphics/pokenav/blue_light.4bpp.lz");

static const struct BgTemplate sPokenavMainMenuBgTemplates[] = {
    {
        .bg = 1,
        .charBaseIndex = 1,
        .mapBaseIndex = 15,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0x000
    }, {
        .bg = 2,
        .charBaseIndex = 2,
        .mapBaseIndex = 23,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 0x000
    }, {
        .bg = 3,
        .charBaseIndex = 3,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 3,
        .baseTile = 0x000
    }
};

static const LoopedTask sMenuHandlerLoopTaskFuncs[] =
{
    [POKENAV_MENU_FUNC_NONE]                  = NULL,
    [POKENAV_MENU_FUNC_MOVE_CURSOR]           = LoopedTask_MoveMenuCursor,
    [POKENAV_MENU_FUNC_OPEN_CONDITION]        = LoopedTask_OpenConditionMenu,
    [POKENAV_MENU_FUNC_RETURN_TO_MAIN]        = LoopedTask_ReturnToMainMenu,
    [POKENAV_MENU_FUNC_OPEN_CONDITION_SEARCH] = LoopedTask_OpenConditionSearchMenu,
    [POKENAV_MENU_FUNC_RETURN_TO_CONDITION]   = LoopedTask_ReturnToConditionMenu,
    [POKENAV_MENU_FUNC_NO_RIBBON_WINNERS]     = LoopedTask_SelectRibbonsNoWinners,
    [POKENAV_MENU_FUNC_RESHOW_DESCRIPTION]    = LoopedTask_ReShowDescription,
    [POKENAV_MENU_FUNC_OPEN_FEATURE]          = LoopedTask_OpenPokenavFeature
};

static const struct CompressedSpriteSheet sPokenavOptionsSpriteSheets[] =
{
    {
        .data = gPokenavOptions_Gfx,
        .size = 0x3400,
        .tag = GFXTAG_OPTIONS
    },
    {
        .data = sMatchCallBlueLightTiles,
        .size = 0x0100,
        .tag = GFXTAG_BLUE_LIGHT
    }
};

static const struct SpritePalette sPokenavOptionsSpritePalettes[] =
{
    {&gPokenavOptions_Pal[0x00], PALTAG_OPTIONS_DEFAULT},
    {&gPokenavOptions_Pal[0x10], PALTAG_OPTIONS_BLUE},
    {&gPokenavOptions_Pal[0x20], PALTAG_OPTIONS_PINK},
    {&gPokenavOptions_Pal[0x30], PALTAG_OPTIONS_BEIGE},
    {&gPokenavOptions_Pal[0x40], PALTAG_OPTIONS_RED},
    {sMatchCallBlueLightPal, PALTAG_BLUE_LIGHT},
    {}
};

// Tile number, palette tag offset
static const u16 sOptionsLabelGfx_RegionMap[] = {0x000, PALTAG_OPTIONS_DEFAULT - PALTAG_OPTIONS_START};
static const u16 sOptionsLabelGfx_Condition[] = {0x020, PALTAG_OPTIONS_BLUE - PALTAG_OPTIONS_START};
static const u16 sOptionsLabelGfx_MatchCall[] = {0x040, PALTAG_OPTIONS_RED - PALTAG_OPTIONS_START};
static const u16 sOptionsLabelGfx_Ribbons[]   = {0x060, PALTAG_OPTIONS_PINK - PALTAG_OPTIONS_START};
static const u16 sOptionsLabelGfx_SwitchOff[] = {0x080, PALTAG_OPTIONS_BEIGE - PALTAG_OPTIONS_START};
static const u16 sOptionsLabelGfx_Party[]     = {0x0A0, PALTAG_OPTIONS_BLUE - PALTAG_OPTIONS_START};
static const u16 sOptionsLabelGfx_Search[]    = {0x0C0, PALTAG_OPTIONS_BLUE - PALTAG_OPTIONS_START};
static const u16 sOptionsLabelGfx_Cool[]      = {0x0E0, PALTAG_OPTIONS_RED - PALTAG_OPTIONS_START};
static const u16 sOptionsLabelGfx_Beauty[]    = {0x100, PALTAG_OPTIONS_BLUE - PALTAG_OPTIONS_START};
static const u16 sOptionsLabelGfx_Cute[]      = {0x120, PALTAG_OPTIONS_PINK - PALTAG_OPTIONS_START};
static const u16 sOptionsLabelGfx_Smart[]     = {0x140, PALTAG_OPTIONS_DEFAULT - PALTAG_OPTIONS_START};
static const u16 sOptionsLabelGfx_Tough[]     = {0x160, PALTAG_OPTIONS_DEFAULT - PALTAG_OPTIONS_START};
static const u16 sOptionsLabelGfx_Cancel[]    = {0x180, PALTAG_OPTIONS_BEIGE - PALTAG_OPTIONS_START};

struct
{
    u16 yStart;
    u16 deltaY;
    const u16 *gfx[MAX_POKENAV_MENUITEMS];
} static const sPokenavMenuOptionLabelGfx[POKENAV_MENU_TYPE_COUNT] =
{
    [POKENAV_MENU_TYPE_DEFAULT] =
    {
        .yStart = 42,
        .deltaY = 20,
        .gfx = {
            sOptionsLabelGfx_RegionMap,
            sOptionsLabelGfx_Condition,
            sOptionsLabelGfx_SwitchOff
        }
    },
    [POKENAV_MENU_TYPE_UNLOCK_MC] =
    {
        .yStart = 42,
        .deltaY = 20,
        .gfx = {
            sOptionsLabelGfx_RegionMap,
            sOptionsLabelGfx_Condition,
            sOptionsLabelGfx_MatchCall,
            sOptionsLabelGfx_SwitchOff
        }
    },
    [POKENAV_MENU_TYPE_UNLOCK_MC_RIBBONS] =
    {
        .yStart = 42,
        .deltaY = 20,
        .gfx = {
            sOptionsLabelGfx_RegionMap,
            sOptionsLabelGfx_Condition,
            sOptionsLabelGfx_MatchCall,
            sOptionsLabelGfx_Ribbons,
            sOptionsLabelGfx_SwitchOff
        }
    },
    [POKENAV_MENU_TYPE_CONDITION] =
    {
        .yStart = 56,
        .deltaY = 20,
        .gfx = {
            sOptionsLabelGfx_Party,
            sOptionsLabelGfx_Search,
            sOptionsLabelGfx_Cancel
        }
    },
    [POKENAV_MENU_TYPE_CONDITION_SEARCH] =
    {
        .yStart = 40,
        .deltaY = 16,
        .gfx = {
            sOptionsLabelGfx_Cool,
            sOptionsLabelGfx_Beauty,
            sOptionsLabelGfx_Cute,
            sOptionsLabelGfx_Smart,
            sOptionsLabelGfx_Tough,
            sOptionsLabelGfx_Cancel
        }
    },
};

static const struct WindowTemplate sOptionDescWindowTemplate =
{
    .bg = 1,
    .tilemapLeft = 3,
    .tilemapTop = 17,
    .width = 24,
    .height = 2,
    .paletteNum = 1,
    .baseBlock = 8
};

static const u8 *const sPageDescriptions[] =
{
    [POKENAV_MENUITEM_MAP]                     = gText_CheckMapOfHoenn,
    [POKENAV_MENUITEM_CONDITION]               = gText_CheckPokemonInDetail,
    [POKENAV_MENUITEM_MATCH_CALL]              = gText_CallRegisteredTrainer,
    [POKENAV_MENUITEM_RIBBONS]                 = gText_CheckObtainedRibbons,
    [POKENAV_MENUITEM_SWITCH_OFF]              = gText_PutAwayPokenav,
    [POKENAV_MENUITEM_CONDITION_PARTY]         = gText_CheckPartyPokemonInDetail,
    [POKENAV_MENUITEM_CONDITION_SEARCH]        = gText_CheckAllPokemonInDetail,
    [POKENAV_MENUITEM_CONDITION_CANCEL]        = gText_ReturnToPokenavMenu,
    [POKENAV_MENUITEM_CONDITION_SEARCH_COOL]   = gText_FindCoolPokemon,
    [POKENAV_MENUITEM_CONDITION_SEARCH_BEAUTY] = gText_FindBeautifulPokemon,
    [POKENAV_MENUITEM_CONDITION_SEARCH_CUTE]   = gText_FindCutePokemon,
    [POKENAV_MENUITEM_CONDITION_SEARCH_SMART]  = gText_FindSmartPokemon,
    [POKENAV_MENUITEM_CONDITION_SEARCH_TOUGH]  = gText_FindToughPokemon,
    [POKENAV_MENUITEM_CONDITION_SEARCH_CANCEL] = gText_ReturnToConditionMenu
};

static const u8 sOptionDescTextColors[]  = {TEXT_COLOR_GREEN, TEXT_COLOR_BLUE, TEXT_COLOR_LIGHT_GREEN};
static const u8 sOptionDescTextColors2[] = {TEXT_COLOR_GREEN, TEXT_COLOR_BLUE, TEXT_COLOR_LIGHT_GREEN};

static const struct OamData sOamData_MenuOption =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x16),
    .x = 0,
    .size = SPRITE_SIZE(32x16),
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0,
};

static const union AffineAnimCmd sAffineAnim_MenuOption_Normal[] =
{
    AFFINEANIMCMD_FRAME(0x100, 0x100, 0, 0),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd sAffineAnim_MenuOption_Zoom[] =
{
    AFFINEANIMCMD_FRAME(0x100, 0x100, 0, 0),
    AFFINEANIMCMD_FRAME(0x10, 0x10, 0, 0x12),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd *const sAffineAnims_MenuOption[] =
{
    sAffineAnim_MenuOption_Normal,
    sAffineAnim_MenuOption_Zoom
};

static const struct SpriteTemplate sMenuOptionSpriteTemplate =
{
    .tileTag = GFXTAG_OPTIONS,
    .paletteTag = PALTAG_OPTIONS_START,
    .oam = &sOamData_MenuOption,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = sAffineAnims_MenuOption,
    .callback = SpriteCallbackDummy,
};

static const struct OamData sBlueLightOamData =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x16),
    .x = 0,
    .size = SPRITE_SIZE(32x16),
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0,
};

static const struct SpriteTemplate sMatchCallBlueLightSpriteTemplate =
{
    .tileTag = GFXTAG_BLUE_LIGHT,
    .paletteTag = PALTAG_BLUE_LIGHT,
    .oam = &sBlueLightOamData,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const struct ScanlineEffectParams sPokenavMainMenuScanlineEffectParams =
{
    &REG_WIN0H,
    ((DMA_ENABLE | DMA_START_HBLANK | DMA_REPEAT | DMA_DEST_RELOAD) << 16) | 1,
    1,
    0
};

static bool32 AreAnyTrainerRematchesNearby(void)
{
    s32 i;

    for (i = 0; i < REMATCH_TABLE_ENTRIES; i++)
    {
        if (GetMatchTableMapSectionId(i) == gMapHeader.regionMapSectionId
            && IsRematchEntryRegistered(i)
            && gSaveBlock1Ptr->trainerRematches[i])
            return TRUE;
    }

    return FALSE;
}

bool32 OpenPokenavMenuInitial(void)
{
    struct Pokenav_MenuGfx * gfx = OpenPokenavMenu();

    if (gfx == NULL)
        return FALSE;

    gfx->pokenavAlreadyOpen = FALSE;
    return TRUE;
}

bool32 OpenPokenavMenuNotInitial(void)
{
    struct Pokenav_MenuGfx * gfx = OpenPokenavMenu();

    if (gfx == NULL)
        return FALSE;

    gfx->pokenavAlreadyOpen = TRUE;
    return TRUE;
}

static struct Pokenav_MenuGfx * OpenPokenavMenu(void)
{
    struct Pokenav_MenuGfx * gfx = AllocSubstruct(POKENAV_SUBSTRUCT_MENU_GFX, sizeof(struct Pokenav_MenuGfx));

    if (gfx != NULL)
    {
        gfx->numIconsBlending = 0;
        gfx->loopedTaskId = CreateLoopedTask(LoopedTask_OpenMenu, 1);
        gfx->isTaskActiveCB = GetCurrentLoopedTaskActive;
    }

    return gfx;
}

void CreateMenuHandlerLoopedTask(s32 ltIdx)
{
    struct Pokenav_MenuGfx * gfx = GetSubstructPtr(POKENAV_SUBSTRUCT_MENU_GFX);
    gfx->loopedTaskId = CreateLoopedTask(sMenuHandlerLoopTaskFuncs[ltIdx], 1);
    gfx->isTaskActiveCB = GetCurrentLoopedTaskActive;
}

bool32 IsMenuHandlerLoopedTaskActive(void)
{
    struct Pokenav_MenuGfx * gfx = GetSubstructPtr(POKENAV_SUBSTRUCT_MENU_GFX);
    return gfx->isTaskActiveCB();
}

void FreeMenuHandlerSubstruct2(void)
{
    struct Pokenav_MenuGfx * gfx = GetSubstructPtr(POKENAV_SUBSTRUCT_MENU_GFX);

    DestroyMovingDotsBgTask();
    RemoveWindow(gfx->optionDescWindowId);
    FreeAndDestroyMainMenuSprites();
    DestroyMenuOptionGlowTask();
    FreePokenavSubstruct(POKENAV_SUBSTRUCT_MENU_GFX);
}

static bool32 GetCurrentLoopedTaskActive(void)
{
    struct Pokenav_MenuGfx * gfx = GetSubstructPtr(POKENAV_SUBSTRUCT_MENU_GFX);

    return IsLoopedTaskActive(gfx->loopedTaskId);
}

static u32 LoopedTask_OpenMenu(s32 state)
{
    struct Pokenav_MenuGfx * gfx = GetSubstructPtr(POKENAV_SUBSTRUCT_MENU_GFX);

    switch (state)
    {
    case 0:
        InitBgTemplates(sPokenavMainMenuBgTemplates, ARRAY_COUNT(sPokenavMainMenuBgTemplates));
        DecompressAndCopyTileDataToVram(1, gPokenavMessageBox_Gfx, 0, 0, 0);
        SetBgTilemapBuffer(1, gfx->bg1TilemapBuffer);
        CopyToBgTilemapBuffer(1, gPokenavMessageBox_Tilemap, 0, 0);
        CopyBgTilemapBufferToVram(1);
        CopyPaletteIntoBufferUnfaded(gPokenavMessageBox_Pal, BG_PLTT_ID(1), PLTT_SIZE_4BPP);
        ChangeBgX(1, 0, BG_COORD_SET);
        ChangeBgY(1, 0, BG_COORD_SET);
        ChangeBgX(2, 0, BG_COORD_SET);
        ChangeBgY(2, 0, BG_COORD_SET);
        ChangeBgX(3, 0, BG_COORD_SET);
        ChangeBgY(3, 0, BG_COORD_SET);
        return LT_INC_AND_PAUSE;
    case 1:
        if (FreeTempTileDataBuffersIfPossible())
            return LT_PAUSE;
        DecompressAndCopyTileDataToVram(2, sPokenavDeviceBgTiles, 0, 0, 0);
        DecompressAndCopyTileDataToVram(2, sPokenavDeviceBgTilemap, 0, 0, 1);
        CopyPaletteIntoBufferUnfaded(sPokenavDeviceBgPal, BG_PLTT_ID(2), PLTT_SIZE_4BPP);
        return LT_INC_AND_PAUSE;
    case 2:
        if (FreeTempTileDataBuffersIfPossible())
            return LT_PAUSE;
        DecompressAndCopyTileDataToVram(3, sPokenavBgDotsTiles, 0, 0, 0);
        DecompressAndCopyTileDataToVram(3, sPokenavBgDotsTilemap, 0, 0, 1);
        CopyPaletteIntoBufferUnfaded(sPokenavBgDotsPal, BG_PLTT_ID(3), PLTT_SIZE_4BPP);
        if (GetPokenavMenuType() == POKENAV_MENU_TYPE_CONDITION || GetPokenavMenuType() == POKENAV_MENU_TYPE_CONDITION_SEARCH)
            ChangeBgDotsColorToPurple();
        return LT_INC_AND_PAUSE;
    case 3:
        if (FreeTempTileDataBuffersIfPossible())
            return LT_PAUSE;
        AddOptionDescriptionWindow();
        CreateMovingBgDotsTask();
        return LT_INC_AND_CONTINUE;
    case 4:
        LoadPokenavOptionPalettes();
        return LT_INC_AND_CONTINUE;
    case 5:
        PrintCurrentOptionDescription();
        CreateMenuOptionSprites();
        CreateMatchCallBlueLightSprite();
        DrawCurrentMenuOptionLabels();
        return LT_INC_AND_PAUSE;
    case 6:
        if (IsDma3ManagerBusyWithBgCopy_())
            return LT_PAUSE;
        return LT_INC_AND_CONTINUE;
    case 7:
        ShowBg(1);
        ShowBg(2);
        ShowBg(3);
        if (gfx->pokenavAlreadyOpen)
            PokenavFadeScreen(POKENAV_FADE_FROM_BLACK);
        else
        {
            PlaySE(SE_POKENAV_ON);
            PokenavFadeScreen(POKENAV_FADE_FROM_BLACK_ALL);
        }
        switch (GetPokenavMenuType())
        {
        case POKENAV_MENU_TYPE_CONDITION_SEARCH:
            LoadLeftHeaderGfxForIndex(7);
            // fallthrough
        case POKENAV_MENU_TYPE_CONDITION:
            LoadLeftHeaderGfxForIndex(1);
            break;
        default:
            LoadLeftHeaderGfxForIndex(0);
            break;
        }
        return LT_INC_AND_PAUSE;
    case 8:
        if (IsPaletteFadeActive())
            return LT_PAUSE;
        switch (GetPokenavMenuType())
        {
        case POKENAV_MENU_TYPE_CONDITION_SEARCH:
            ShowLeftHeaderGfx(7, FALSE, FALSE);
            // fallthrough
        case POKENAV_MENU_TYPE_CONDITION:
            ShowLeftHeaderGfx(1, FALSE, FALSE);
            break;
        default:
            ShowLeftHeaderGfx(0, FALSE, FALSE);
            break;
        }
        StartOptionAnimations_Enter();
        SetupPokenavMenuScanlineEffects();
        return LT_INC_AND_CONTINUE;
    case 9:
        if (AreMenuOptionSpritesMoving())
            return LT_PAUSE;
        if (AreLeftHeaderSpritesMoving())
            return LT_PAUSE;
        break;
    }
    return LT_FINISH;
}

static u32 LoopedTask_MoveMenuCursor(s32 state)
{
    switch (state)
    {
    case 0:
        SetMenuOptionGlow();
        StartOptionAnimations_CursorMoved();
        PrintCurrentOptionDescription();
        PlaySE(SE_SELECT);
        return LT_INC_AND_PAUSE;
    case 1:
        if (AreMenuOptionSpritesMoving())
            return LT_PAUSE;
        if (IsDma3ManagerBusyWithBgCopy_())
            return LT_PAUSE;
        break;
    }
    return LT_FINISH;
}

static u32 LoopedTask_OpenConditionMenu(s32 state)
{
    switch (state)
    {
    case 0:
        ResetBldCnt();
        StartOptionAnimations_Exit();
        HideMainOrSubMenuLeftHeader(POKENAV_GFX_MAIN_MENU, FALSE);
        PlaySE(SE_SELECT);
        return LT_INC_AND_PAUSE;
    case 1:
        if (AreMenuOptionSpritesMoving())
            return LT_PAUSE;
        if (AreLeftHeaderSpritesMoving())
            return LT_PAUSE;
        DrawCurrentMenuOptionLabels();
        LoadLeftHeaderGfxForIndex(1);
        return LT_INC_AND_PAUSE;
    case 2:
        StartOptionAnimations_Enter();
        ShowLeftHeaderGfx(1, FALSE, FALSE);
        CreateBgDotPurplePalTask();
        PrintCurrentOptionDescription();
        return LT_INC_AND_PAUSE;
    case 3:
        if (AreMenuOptionSpritesMoving())
            return LT_PAUSE;
        if (AreLeftHeaderSpritesMoving())
            return LT_PAUSE;
        if (IsTaskActive_UpdateBgDotsPalette())
            return LT_PAUSE;
        if (IsDma3ManagerBusyWithBgCopy_())
            return LT_PAUSE;
        InitMenuOptionGlow();
        break;
    }
    return LT_FINISH;
}

static u32 LoopedTask_ReturnToMainMenu(s32 state)
{
    switch (state)
    {
    case 0:
        ResetBldCnt();
        StartOptionAnimations_Exit();
        HideMainOrSubMenuLeftHeader(POKENAV_GFX_CONDITION_MENU, FALSE);
        return LT_INC_AND_PAUSE;
    case 1:
        if (AreMenuOptionSpritesMoving())
            return LT_PAUSE;
        if (AreLeftHeaderSpritesMoving())
            return LT_PAUSE;
        DrawCurrentMenuOptionLabels();
        LoadLeftHeaderGfxForIndex(0);
        return LT_INC_AND_PAUSE;
    case 2:
        StartOptionAnimations_Enter();
        ShowLeftHeaderGfx(0, FALSE, FALSE);
        CreateBgDotLightBluePalTask();
        PrintCurrentOptionDescription();
        return LT_INC_AND_PAUSE;
    case 3:
        if (AreMenuOptionSpritesMoving())
            return LT_PAUSE;
        if (AreLeftHeaderSpritesMoving())
            return LT_PAUSE;
        if (IsTaskActive_UpdateBgDotsPalette())
            return LT_PAUSE;
        if (IsDma3ManagerBusyWithBgCopy_())
            return LT_PAUSE;
        InitMenuOptionGlow();
        break;
    }
    return LT_FINISH;
}

static u32 LoopedTask_OpenConditionSearchMenu(s32 state)
{
    switch (state)
    {
    case 0:
        ResetBldCnt();
        StartOptionAnimations_Exit();
        PlaySE(SE_SELECT);
        return LT_INC_AND_PAUSE;
    case 1:
        if (AreMenuOptionSpritesMoving())
            return LT_PAUSE;
        LoadLeftHeaderGfxForIndex(7);
        DrawCurrentMenuOptionLabels();
        return LT_INC_AND_PAUSE;
    case 2:
        StartOptionAnimations_Enter();
        ShowLeftHeaderGfx(7, FALSE, FALSE);
        PrintCurrentOptionDescription();
        return LT_INC_AND_PAUSE;
    case 3:
        if (AreMenuOptionSpritesMoving())
            return LT_PAUSE;
        if (AreLeftHeaderSpritesMoving())
            return LT_PAUSE;
        if (IsTaskActive_UpdateBgDotsPalette())
            return LT_PAUSE;
        InitMenuOptionGlow();
        break;
    }
    return LT_FINISH;
}

static u32 LoopedTask_ReturnToConditionMenu(s32 state)
{
    switch (state)
    {
    case 0:
        ResetBldCnt();
        StartOptionAnimations_Exit();
        HideMainOrSubMenuLeftHeader(POKENAV_GFX_SEARCH_MENU, FALSE);
        return LT_INC_AND_PAUSE;
    case 1:
        if (AreMenuOptionSpritesMoving())
            return LT_PAUSE;
        if (AreLeftHeaderSpritesMoving())
            return LT_PAUSE;
        DrawCurrentMenuOptionLabels();
        return LT_INC_AND_PAUSE;
    case 2:
        StartOptionAnimations_Enter();
        PrintCurrentOptionDescription();
        return LT_INC_AND_PAUSE;
    case 3:
        if (AreMenuOptionSpritesMoving())
            return LT_PAUSE;
        if (IsTaskActive_UpdateBgDotsPalette())
            return LT_PAUSE;
        InitMenuOptionGlow();
        break;
    }
    return LT_FINISH;
}

static u32 LoopedTask_SelectRibbonsNoWinners(s32 state)
{
    switch (state)
    {
    case 0:
        PlaySE(SE_FAILURE);
        PrintNoRibbonWinners();
        return LT_INC_AND_PAUSE;
    case 1:
        if (IsDma3ManagerBusyWithBgCopy())
            return LT_PAUSE;
        break;
    }
    return LT_FINISH;
}

// For redisplaying the Ribbons description to replace the No Ribbon Winners message
static u32 LoopedTask_ReShowDescription(s32 state)
{
    switch (state)
    {
    case 0:
        PlaySE(SE_SELECT);
        PrintCurrentOptionDescription();
        return LT_INC_AND_PAUSE;
    case 1:
        if (IsDma3ManagerBusyWithBgCopy())
            return LT_PAUSE;
        break;
    }
    return LT_FINISH;
}

// For selecting a feature option from a menu, e.g. the Map, Match Call, Beauty search, etc.
static u32 LoopedTask_OpenPokenavFeature(s32 state)
{
    switch (state)
    {
    case 0:
        PrintHelpBarText(GetHelpBarTextId());
        return LT_INC_AND_PAUSE;
    case 1:
        if (WaitForHelpBar())
            return LT_PAUSE;
        SlideMenuHeaderUp();
        ResetBldCnt();
        StartOptionAnimations_Exit();
        switch (GetPokenavMenuType())
        {
        case POKENAV_MENU_TYPE_CONDITION_SEARCH:
            HideMainOrSubMenuLeftHeader(POKENAV_GFX_SEARCH_MENU, FALSE);
            // fallthrough
        case POKENAV_MENU_TYPE_CONDITION:
            HideMainOrSubMenuLeftHeader(POKENAV_GFX_CONDITION_MENU, FALSE);
            break;
        default:
            HideMainOrSubMenuLeftHeader(POKENAV_GFX_MAIN_MENU, FALSE);
            break;
        }
        PlaySE(SE_SELECT);
        return LT_INC_AND_PAUSE;
    case 2:
        if (AreMenuOptionSpritesMoving())
            return LT_PAUSE;
        if (AreLeftHeaderSpritesMoving())
            return LT_PAUSE;
        PokenavFadeScreen(POKENAV_FADE_TO_BLACK);
        return LT_INC_AND_PAUSE;
    case 3:
        if (IsPaletteFadeActive())
            return LT_PAUSE;
        break;
    }
    return LT_FINISH;
}

static void LoadPokenavOptionPalettes(void)
{
    s32 i;

    for (i = 0; i < ARRAY_COUNT(sPokenavOptionsSpriteSheets); i++)
        LoadCompressedSpriteSheet(&sPokenavOptionsSpriteSheets[i]);
    Pokenav_AllocAndLoadPalettes(sPokenavOptionsSpritePalettes);
}

static void FreeAndDestroyMainMenuSprites(void)
{
    FreeSpriteTilesByTag(GFXTAG_OPTIONS);
    FreeSpriteTilesByTag(GFXTAG_BLUE_LIGHT);
    FreeSpritePaletteByTag(PALTAG_OPTIONS_DEFAULT);
    FreeSpritePaletteByTag(PALTAG_OPTIONS_BLUE);
    FreeSpritePaletteByTag(PALTAG_OPTIONS_PINK);
    FreeSpritePaletteByTag(PALTAG_OPTIONS_BEIGE);
    FreeSpritePaletteByTag(PALTAG_OPTIONS_RED);
    FreeSpritePaletteByTag(PALTAG_BLUE_LIGHT);
    DestroyMenuOptionSprites();
    DestroyRematchBlueLightSprite();
}

static void CreateMenuOptionSprites(void)
{
    s32 i, j;
    struct Pokenav_MenuGfx * gfx = GetSubstructPtr(POKENAV_SUBSTRUCT_MENU_GFX);

    for (i = 0; i < MAX_POKENAV_MENUITEMS; i++)
    {
        for (j = 0; j < NUM_OPTION_SUBSPRITES; j++)
        {
            u8 spriteId = CreateSprite(&sMenuOptionSpriteTemplate, 0x8c, 20 * i + 40, 3);
            gfx->iconSprites[i][j] = &gSprites[spriteId];
            gSprites[spriteId].x2 = 32 * j;
        }
    }
}

static void DestroyMenuOptionSprites(void)
{
    s32 i, j;
    struct Pokenav_MenuGfx * gfx = GetSubstructPtr(POKENAV_SUBSTRUCT_MENU_GFX);

    for (i = 0; i < MAX_POKENAV_MENUITEMS; i++)
    {
        for (j = 0; j < NUM_OPTION_SUBSPRITES; j++)
        {
            FreeSpriteOamMatrix(gfx->iconSprites[i][j]);
            DestroySprite(gfx->iconSprites[i][j]);
        }
    }
}

static void DrawCurrentMenuOptionLabels(void)
{
    s32 menuType = GetPokenavMenuType();
    DrawOptionLabelGfx(sPokenavMenuOptionLabelGfx[menuType].gfx, sPokenavMenuOptionLabelGfx[menuType].yStart, sPokenavMenuOptionLabelGfx[menuType].deltaY);
}

static void DrawOptionLabelGfx(const u16 *const *optionGfx, s32 yPos, s32 deltaY)
{
    s32 i, j;
    struct Pokenav_MenuGfx * gfx = GetSubstructPtr(POKENAV_SUBSTRUCT_MENU_GFX);
    s32 baseTile = GetSpriteTileStartByTag(GFXTAG_OPTIONS);

    for (i = 0; i < MAX_POKENAV_MENUITEMS; i++)
    {
        if (*optionGfx != NULL)
        {
            for (j = 0; j < NUM_OPTION_SUBSPRITES; j++)
            {
                gfx->iconSprites[i][j]->oam.tileNum = (*optionGfx)[0] + baseTile + 8 * j;
                gfx->iconSprites[i][j]->oam.paletteNum = IndexOfSpritePaletteTag((*optionGfx)[1] + PALTAG_OPTIONS_START);
                gfx->iconSprites[i][j]->invisible = TRUE;
                gfx->iconSprites[i][j]->y = yPos;
                gfx->iconSprites[i][j]->x = OPTION_DEFAULT_X;
                gfx->iconSprites[i][j]->x2 = 32 * j;
            }
            gfx->iconVisible[i] = TRUE;
        }
        else
        {
            for (j = 0; j < NUM_OPTION_SUBSPRITES; j++)
                gfx->iconSprites[i][j]->invisible = TRUE;

            gfx->iconVisible[i] = FALSE;
        }
        optionGfx++;
        yPos += deltaY;
    }
}

static void StartOptionAnimations_Enter(void)
{
    s32 i;
    struct Pokenav_MenuGfx *gfx = GetSubstructPtr(POKENAV_SUBSTRUCT_MENU_GFX);
    s32 cursorPos = GetPokenavCursorPos();
    s32 iconCount = 0;
    s32 x;

    for (i = 0; i < MAX_POKENAV_MENUITEMS; i++)
    {
        if (gfx->iconVisible[i])
        {
            if (iconCount++ == cursorPos)
            {
                x = OPTION_SELECTED_X;
                gfx->cursorPos = i;
            }
            else
            {
                // Not selected, set default position
                x = OPTION_DEFAULT_X;
            }

            // Slide new options in
            StartOptionSlide(gfx->iconSprites[i], OPTION_EXIT_X, x, 12);
            SetOptionInvisibility(gfx->iconSprites[i], FALSE);
        }
        else
        {
            SetOptionInvisibility(gfx->iconSprites[i], TRUE);
        }
    }
}

static void StartOptionAnimations_CursorMoved(void)
{
    s32 i;
    struct Pokenav_MenuGfx *gfx = GetSubstructPtr(POKENAV_SUBSTRUCT_MENU_GFX);
    s32 prevPos = GetPokenavCursorPos();
    s32 newPos;

    // Get the index of the next visible option
    for (i = 0, newPos = 0; i < MAX_POKENAV_MENUITEMS; i++)
    {
        if (gfx->iconVisible[i])
        {
            if (newPos == prevPos)
            {
                newPos = i;
                break;
            }
            newPos++;
        }
    }

    // The selected option slides out a bit and the previously
    // selected option slides back to its original position.
    StartOptionSlide(gfx->iconSprites[gfx->cursorPos], OPTION_SELECTED_X, OPTION_DEFAULT_X, 4);
    StartOptionSlide(gfx->iconSprites[newPos], OPTION_DEFAULT_X, OPTION_SELECTED_X, 4);
    gfx->cursorPos = newPos;
}

static void StartOptionAnimations_Exit(void)
{
    s32 i;
    struct Pokenav_MenuGfx *gfx = GetSubstructPtr(POKENAV_SUBSTRUCT_MENU_GFX);

    for (i = 0; i < MAX_POKENAV_MENUITEMS; i++)
    {
        if (gfx->iconVisible[i])
        {
            // Unselected options slide out,
            // selected option zooms in
            if (gfx->cursorPos != i)
                StartOptionSlide(gfx->iconSprites[i], OPTION_DEFAULT_X, OPTION_EXIT_X, 8);
            else
                StartOptionZoom(gfx->iconSprites[i]);
        }
    }
}

static bool32 AreMenuOptionSpritesMoving(void)
{
    s32 i;
    struct Pokenav_MenuGfx *gfx = GetSubstructPtr(POKENAV_SUBSTRUCT_MENU_GFX);

    for (i = 0; i < MAX_POKENAV_MENUITEMS; i++)
    {
        if (gfx->iconSprites[i][0]->callback != SpriteCallbackDummy)
            return TRUE;
    }

    if (gfx->numIconsBlending != 0)
        return TRUE;

    return FALSE;
}

#define sSlideTime  data[0]
#define sSlideAccel data[1]
#define sSlideSpeed data[2]
#define sSlideEndX  data[7]

static void StartOptionSlide(struct Sprite ** sprites, s32 startX, s32 endX, s32 time)
{
    s32 i;

    for (i = 0; i < NUM_OPTION_SUBSPRITES; i++)
    {
        (*sprites)->x = startX;
        (*sprites)->sSlideTime = time;
        (*sprites)->sSlideAccel = 16 * (endX - startX) / time;
        (*sprites)->sSlideSpeed = 16 * startX;
        (*sprites)->sSlideEndX = endX;
        (*sprites)->callback = SpriteCB_OptionSlide;
        sprites++;
    }
}

#define sZoomDelay       data[0]
#define sZoomSetAffine   data[1]
#define sZoomSpeed       data[2]
#define sZoomSubspriteId data[7]

#define tBlendDelay   data[0]
#define tBlendState   data[1]
#define tBlendTarget1 data[2]
#define tBlendTarget2 data[3]
#define tBlendCounter data[4]

// When an option is selected it zooms in and blends away as part
// of the transition to the next screen.
static void StartOptionZoom(struct Sprite ** sprites)
{
    s32 i;
    struct Pokenav_MenuGfx * gfx = GetSubstructPtr(POKENAV_SUBSTRUCT_MENU_GFX);
    u8 taskId;

    for (i = 0; i < NUM_OPTION_SUBSPRITES; i++)
    {
        (*sprites)->oam.objMode = ST_OAM_OBJ_BLEND;
        (*sprites)->oam.affineMode = ST_OAM_AFFINE_DOUBLE;
        (*sprites)->callback = SpriteCB_OptionZoom;
        (*sprites)->sZoomDelay = 8;
        (*sprites)->sZoomSetAffine = FALSE;
        (*sprites)->sZoomSubspriteId = i;
        InitSpriteAffineAnim(sprites[0]);
        StartSpriteAffineAnim(sprites[0], 0);
        sprites++;
    }

    SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(16, 0));
    taskId = CreateTask(Task_OptionBlend, 3);
    gTasks[taskId].tBlendDelay = 8;
    gfx->numIconsBlending++;
}

static void SetOptionInvisibility(struct Sprite ** sprites, bool32 invisible)
{
    s32 i;

    for (i = 0; i < NUM_OPTION_SUBSPRITES; i++)
    {
        (*sprites)->invisible = invisible;
        sprites++;
    }
}

static void SpriteCB_OptionSlide(struct Sprite * sprite)
{
    sprite->sSlideTime--;
    if (sprite->sSlideTime != -1)
    {
        sprite->sSlideSpeed += sprite->sSlideAccel;
        sprite->x = sprite->sSlideSpeed >> 4;
    }
    else
    {
        sprite->x = sprite->sSlideEndX;
        sprite->callback = SpriteCallbackDummy;
    }
}

#undef sSlideTime
#undef sSlideAccel
#undef sSlideSpeed
#undef sSlideEndX

static void SpriteCB_OptionZoom(struct Sprite * sprite)
{
    s32 temp;
    s32 x;
    if (sprite->sZoomDelay == 0)
    {
        if (!sprite->sZoomSetAffine)
        {
            StartSpriteAffineAnim(sprite, 1);
            sprite->sZoomSetAffine++;
            sprite->sZoomSpeed = 0x100;
            sprite->x += sprite->x2;
            sprite->x2 = 0;
        }
        else
        {
            sprite->sZoomSpeed += 16;
            temp = sprite->sZoomSpeed;
            x = temp >> 3;
            x = (x - 32) / 2;

            // Each subsprite needs to zoom to a different degree/direction
            switch (sprite->sZoomSubspriteId)
            {
            case 0:
                sprite->x2 = -x * 3;
                break;
            case 1:
                sprite->x2 = -x;
                break;
            case 2:
                sprite->x2 = x;
                break;
            case 3:
                sprite->x2 = x * 3;
                break;
            }
            if (sprite->affineAnimEnded)
            {
                sprite->invisible = TRUE;
                FreeOamMatrix(sprite->oam.matrixNum);
                CalcCenterToCornerVec(sprite, sprite->oam.shape, sprite->oam.size, ST_OAM_AFFINE_OFF);
                sprite->oam.affineMode = ST_OAM_AFFINE_OFF;
                sprite->oam.objMode = ST_OAM_OBJ_NORMAL;
                sprite->callback = SpriteCallbackDummy;
            }
        }
    }
    else
    {
        sprite->sZoomDelay--;
    }
}

#undef sZoomDelay
#undef sZoomSetAffine
#undef sZoomSpeed
#undef sZoomSubspriteId

static void Task_OptionBlend(u8 taskId)
{
    s16 * data = gTasks[taskId].data;

    if (tBlendDelay == 0)
    {
        switch (tBlendState)
        {
        case 0:
            tBlendTarget1 = 16;
            tBlendTarget2 = 0;
            SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_EFFECT_NONE | BLDCNT_TGT2_ALL);
            SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(16, 0));
            tBlendState++;
            break;
        case 1:
            if (tBlendCounter & 1)
            {
                tBlendTarget1 -= 3;
                if (tBlendTarget1 < 0)
                    tBlendTarget1 = 0;
            }
            else
            {
                tBlendTarget2 += 3;
                if (tBlendTarget2 > 16)
                    tBlendTarget2 = 16;
            }
            SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(tBlendTarget1, tBlendTarget2));
            tBlendCounter++;
            if (tBlendCounter == 12)
            {
                ((struct Pokenav_MenuGfx *)GetSubstructPtr(POKENAV_SUBSTRUCT_MENU_GFX))->numIconsBlending--;
                SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(0, 16));
                DestroyTask(taskId);
            }
            break;
        }
    }
    else
    {
        tBlendDelay--;
    }
}

#undef tBlendDelay
#undef tBlendState
#undef tBlendTarget1
#undef tBlendTarget2
#undef tBlendCounter

// Blue light that blinks if there are available rematches nearby
static void CreateMatchCallBlueLightSprite(void)
{
    struct Pokenav_MenuGfx * gfx = GetSubstructPtr(POKENAV_SUBSTRUCT_MENU_GFX);
    u8 spriteId = CreateSprite(&sMatchCallBlueLightSpriteTemplate, 0x10, 0x60, 4);
    gfx->blueLightSprite = &gSprites[spriteId];
    if (AreAnyTrainerRematchesNearby())
        gfx->blueLightSprite->callback = SpriteCB_BlinkingBlueLight;
    else
        gfx->blueLightSprite->invisible = TRUE;
}

static void DestroyRematchBlueLightSprite(void)
{
    struct Pokenav_MenuGfx *gfx = GetSubstructPtr(POKENAV_SUBSTRUCT_MENU_GFX);
    DestroySprite(gfx->blueLightSprite);
}

static void SpriteCB_BlinkingBlueLight(struct Sprite * sprite)
{
    sprite->data[0]++;
    if (sprite->data[0] > 8)
    {
        sprite->data[0] = 0;
        sprite->invisible ^= 1;
    }
}

static void AddOptionDescriptionWindow(void)
{
    struct Pokenav_MenuGfx * gfx = GetSubstructPtr(POKENAV_SUBSTRUCT_MENU_GFX);

    gfx->optionDescWindowId = AddWindow(&sOptionDescWindowTemplate);
    PutWindowTilemap(gfx->optionDescWindowId);
    FillWindowPixelBuffer(gfx->optionDescWindowId, PIXEL_FILL(6));
    CopyWindowToVram(gfx->optionDescWindowId, COPYWIN_FULL);
}

static void PrintCurrentOptionDescription(void)
{
    struct Pokenav_MenuGfx * gfx = GetSubstructPtr(POKENAV_SUBSTRUCT_MENU_GFX);
    int menuItem = GetCurrentMenuItemId();
    const u8 * desc = sPageDescriptions[menuItem];
    u32 width = GetStringWidth(FONT_NORMAL, desc, -1);
    FillWindowPixelBuffer(gfx->optionDescWindowId, PIXEL_FILL(6));
    AddTextPrinterParameterized3(gfx->optionDescWindowId, FONT_NORMAL, (192 - width) / 2, 1, sOptionDescTextColors, 0, desc);
}

// Printed when Ribbons is selected if no PC/party mons have ribbons
// Can occur by obtaining a mon with a ribbon and then releasing all ribbon winners
static void PrintNoRibbonWinners(void)
{
    struct Pokenav_MenuGfx * gfx = GetSubstructPtr(POKENAV_SUBSTRUCT_MENU_GFX);
    const u8 * s = gText_NoRibbonWinners;
    u32 width = GetStringWidth(FONT_NORMAL, s, -1);
    FillWindowPixelBuffer(gfx->optionDescWindowId, PIXEL_FILL(6));
    AddTextPrinterParameterized3(gfx->optionDescWindowId, FONT_NORMAL, (192 - width) / 2, 1, sOptionDescTextColors2, 0, s);
}

static bool32 IsDma3ManagerBusyWithBgCopy_(void)
{
    return IsDma3ManagerBusyWithBgCopy();
}

static void CreateMovingBgDotsTask(void)
{
    struct Pokenav_MenuGfx * gfx = GetSubstructPtr(POKENAV_SUBSTRUCT_MENU_GFX);
    gfx->bg3ScrollTaskId = CreateTask(Task_MoveBgDots, 2);
}

static void DestroyMovingDotsBgTask(void)
{
    struct Pokenav_MenuGfx * gfx = GetSubstructPtr(POKENAV_SUBSTRUCT_MENU_GFX);
    DestroyTask(gfx->bg3ScrollTaskId);
}

static void Task_MoveBgDots(u8 taskId)
{
    ChangeBgX(3, 0x80, BG_COORD_ADD);
}

static void CreateBgDotPurplePalTask(void)
{
    u8 taskId = CreateTask(Task_UpdateBgDotsPalette, 3);
    SetWordTaskArg(taskId, 1, (uintptr_t)(sPokenavBgDotsPal + 1));
    SetWordTaskArg(taskId, 3, (uintptr_t)(sPokenavBgDotsPal + 7));
}

static void ChangeBgDotsColorToPurple(void)
{
    CopyPaletteIntoBufferUnfaded(sPokenavBgDotsPal + 7, BG_PLTT_ID(3) + 1, PLTT_SIZEOF(2));
}

static void CreateBgDotLightBluePalTask(void)
{
    u8 taskId = CreateTask(Task_UpdateBgDotsPalette, 3);
    SetWordTaskArg(taskId, 1, (uintptr_t)(sPokenavBgDotsPal + 7));
    SetWordTaskArg(taskId, 3, (uintptr_t)(sPokenavBgDotsPal + 1));
}

static bool32 IsTaskActive_UpdateBgDotsPalette(void)
{
    return FuncIsActiveTask(Task_UpdateBgDotsPalette);
}

static void Task_UpdateBgDotsPalette(u8 taskId)
{
    u16 sp8[2];
    s16 * data = gTasks[taskId].data;
    const u16 * pal1 = (const u16 *)GetWordTaskArg(taskId, 1);
    const u16 * pal2 = (const u16 *)GetWordTaskArg(taskId, 3);

    PokenavCopyPalette(pal1, pal2, 2, 12, ++data[0], sp8);
    LoadPalette(sp8, BG_PLTT_ID(3) + 1, PLTT_SIZEOF(2));
    if (data[0] == 12)
        DestroyTask(taskId);
}

static void VBlankCB_PokenavMainMenu(void)
{
    TransferPlttBuffer();
    LoadOam();
    ProcessSpriteCopyRequests();
    ScanlineEffect_InitHBlankDmaTransfer();
}

static void SetupPokenavMenuScanlineEffects(void)
{
    SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_OBJ | BLDCNT_EFFECT_LIGHTEN);
    SetGpuReg(REG_OFFSET_BLDY, 0);
    SetGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_WIN0_ON);
    SetGpuRegBits(REG_OFFSET_WININ, WININ_WIN0_ALL);
    SetGpuRegBits(REG_OFFSET_WINOUT, WINOUT_WIN01_BG_ALL | WINOUT_WIN01_OBJ);
    SetGpuRegBits(REG_OFFSET_WIN0V, DISPLAY_HEIGHT);
    ScanlineEffect_Stop();
    SetMenuOptionGlow();
    ScanlineEffect_SetParams(sPokenavMainMenuScanlineEffectParams);
    SetVBlankCallback_(VBlankCB_PokenavMainMenu);
    CreateTask(Task_CurrentMenuOptionGlow, 3);
}

static void DestroyMenuOptionGlowTask(void)
{
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
    ClearGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_WIN0_ON);
    ScanlineEffect_Stop();
    DestroyTask(FindTaskIdByFunc(Task_CurrentMenuOptionGlow));
    SetPokenavVBlankCallback();
}

static void ResetBldCnt(void)
{
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
}

static void InitMenuOptionGlow(void)
{
    SetMenuOptionGlow();
    SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_OBJ | BLDCNT_EFFECT_LIGHTEN);
}

static void Task_CurrentMenuOptionGlow(u8 taskId)
{
    s16 * data = gTasks[taskId].data;
    data[0]++;
    if (data[0] > 0)
    {
        data[0] = 0;
        data[1] += 3;
        data[1] &= 0x7F;
        SetGpuReg(REG_OFFSET_BLDY, gSineTable[data[1]] >> 5);
    }
}

static void SetMenuOptionGlow(void)
{
    int menuType = GetPokenavMenuType();
    int cursorPos = GetPokenavCursorPos();
    int r4 = sPokenavMenuOptionLabelGfx[menuType].deltaY * cursorPos + sPokenavMenuOptionLabelGfx[menuType].yStart - 8;
    CpuFill16(0, gScanlineEffectRegBuffers[0], DISPLAY_HEIGHT * 2);
    CpuFill16(0, gScanlineEffectRegBuffers[1], DISPLAY_HEIGHT * 2);
    CpuFill16(RGB(16, 23, 28), &gScanlineEffectRegBuffers[0][r4], 0x20);
    CpuFill16(RGB(16, 23, 28), &gScanlineEffectRegBuffers[1][r4], 0x20);
}

void ResetBldCnt_(void)
{
    ResetBldCnt();
}
