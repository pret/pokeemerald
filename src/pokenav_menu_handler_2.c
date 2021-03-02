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

struct Pokenav2Struct
{
    bool32 (*isTaskActiveCB)(void);
    u32 loopedTaskId;
    u16 optionDescWindowId;
    u8 bg3ScrollTaskId;
    u8 cursorPos;
    bool8 otherIconsInMotion;
    bool8 pokenavAlreadyOpen;
    bool32 iconVisible[MAX_POKENAV_MENUITEMS];
    struct Sprite * blueLightSpriteId;
    struct Sprite * iconSprites[MAX_POKENAV_MENUITEMS][4];
    u16 bg1TilemapBuffer[0x400];
};

static struct Pokenav2Struct * OpenPokenavMenu(void);
static bool32 GetCurrentLoopedTaskActive(void);
static u32 LoopedTask_OpenMenu(s32 state);
static u32 LoopedTask_MoveMenuCursor(s32 state);
static u32 LoopedTask_OpenConditionMenu(s32 state);
static u32 LoopedTask_ReturnToMainMenu(s32 state);
static u32 LoopedTask_OpenConditionSearchMenu(s32 state);
static u32 LoopedTask_ReturnToConditionMenu(s32 state);
static u32 LoopedTask_SelectRibbonsNoWinners(s32 state);
static u32 LoopedTask_ReShowDescription(s32 state);
static u32 LoopedTask_OpenPokenavFeature(s32 state);
static void LoadPokenavOptionPalettes(void);
static void FreeAndDestroyMainMenuSprites(void);
static void CreateMenuOptionSprites(void);
static void DestroyMenuOptionSprites(void);
static void sub_81CA0C8(void);
static void DrawOptionLabelGfx(const u16 *const * a0, s32 yPos, s32 a2);
static void SetupCurrentMenuOptionsGfx(void);
static void SetMenuOptionGfxParams_CursorMoved(void);
static void SetMenuOptionGfxParamsInactive(struct Sprite ** sprites, s32 x, s32 a2, s32 a3);
static void SetMenuOptionGfxParamsActive(struct Sprite ** sprites);
static void SetupPokenavMenuOptions(void);
static bool32 AreMenuOptionSpritesMoving(void);
static void SetMenuOptionGfxInvisibility(struct Sprite ** sprites, bool32 a1);
static void sub_81CA474(struct Sprite * sprite);
static void sub_81CA4AC(struct Sprite * sprite);
static void sub_81CA580(u8 taskId);
static void CreateMatchCallBlueLightSprite(void);
static void SpriteCB_BlinkingBlueLight(struct Sprite * sprite);
static void DestroyRematchBlueLightSpriteId(void);
static void AddOptionDescriptionWindow(void);
static void PrintCurrentOptionDescription(void);
static void PrintNoRibbonWinners(void);
static bool32 IsDma3ManagerBusyWithBgCopy_(void);
static void CreateMovingBgDotsTask(void);
static void DestroyMovingDotsBgTask(void);
static void Task_MoveBgDots(u8 taskId);
static void CreateBgDotPurplePalTask(void);
static void ChangeBgDotsColorToPurple(void);
static void CreateBgDotLightBluePalTask(void);
static bool32 IsTaskActive_UpdateBgDotsPalette(void);
static void Task_UpdateBgDotsPalette(u8 taskId);
static void SetupPokenavMenuScanlineEffects(void);
static void DestroyMenuOptionGlowTask(void);
static void ResetBldCnt(void);
static void InitMenuOptionGlow(void);
static void Task_CurrentMenuOptionGlow(u8 taskId);
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
        .tag = 0x0003
    },
    {
        .data = sMatchCallBlueLightTiles,
        .size = 0x0100,
        .tag = 0x0001
    }
};

static const struct SpritePalette sPokenavOptionsSpritePalettes[] =
{
    {gPokenavOptions_Pal + 0x00, 4},
    {gPokenavOptions_Pal + 0x10, 5},
    {gPokenavOptions_Pal + 0x20, 6},
    {gPokenavOptions_Pal + 0x30, 7},
    {gPokenavOptions_Pal + 0x40, 8},
    {sMatchCallBlueLightPal, 3},
    {}
};

static const u16 sOptionsLabelGfx_RegionMap[] = {0, 0};
static const u16 sOptionsLabelGfx_Condition[] = {0x20, 1};
static const u16 sOptionsLabelGfx_MatchCall[] = {0x40, 4};
static const u16 sOptionsLabelGfx_Ribbons[] = {0x60, 2};
static const u16 sOptionsLabelGfx_SwitchOff[] = {0x80, 3};
static const u16 sOptionsLabelGfx_Party[] = {0xA0, 1};
static const u16 sOptionsLabelGfx_Search[] = {0xC0, 1};
static const u16 sOptionsLabelGfx_Cool[] = {0xE0, 4};
static const u16 sOptionsLabelGfx_Beauty[] = {0x100, 1};
static const u16 sOptionsLabelGfx_Cute[] = {0x120, 2};
static const u16 sOptionsLabelGfx_Smart[] = {0x140, 0};
static const u16 sOptionsLabelGfx_Tough[] = {0x160, 0};
static const u16 sOptionsLabelGfx_Cancel[] = {0x180, 3};

struct OptionsLabelGfx
{
    u16 yStart;
    u16 deltaY;
    const u16 *tiles[MAX_POKENAV_MENUITEMS];
};

static const struct OptionsLabelGfx sPokenavMenuOptionLabelGfx[POKENAV_MENU_TYPE_COUNT] =
{
    [POKENAV_MENU_TYPE_DEFAULT] = 
    {
        .yStart = 42,
        .deltaY = 20,
        {sOptionsLabelGfx_RegionMap, sOptionsLabelGfx_Condition, sOptionsLabelGfx_SwitchOff}
    },
    [POKENAV_MENU_TYPE_UNLOCK_MC] = 
    {
        .yStart = 42,
        .deltaY = 20,
        {sOptionsLabelGfx_RegionMap, sOptionsLabelGfx_Condition, sOptionsLabelGfx_MatchCall, sOptionsLabelGfx_SwitchOff}
    },
    [POKENAV_MENU_TYPE_UNLOCK_MC_RIBBONS] = 
    {
        .yStart = 42,
        .deltaY = 20,
        {sOptionsLabelGfx_RegionMap, sOptionsLabelGfx_Condition, sOptionsLabelGfx_MatchCall, sOptionsLabelGfx_Ribbons, sOptionsLabelGfx_SwitchOff}
    },
    [POKENAV_MENU_TYPE_CONDITION] = 
    {
        .yStart = 56,
        .deltaY = 20,
        {sOptionsLabelGfx_Party, sOptionsLabelGfx_Search, sOptionsLabelGfx_Cancel}
    },
    [POKENAV_MENU_TYPE_CONDITION_SEARCH] = 
    {
        .yStart = 40,
        .deltaY = 16,
        {sOptionsLabelGfx_Cool, sOptionsLabelGfx_Beauty, sOptionsLabelGfx_Cute, sOptionsLabelGfx_Smart, sOptionsLabelGfx_Tough, sOptionsLabelGfx_Cancel}
    },
};

static const struct WindowTemplate sOptionDescWindowTemplate =
{
    .bg = 1,
    .tilemapLeft = 3,
    .tilemapTop = 17,
    .width = 0x18,
    .height = 0x2,
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

static const union AffineAnimCmd gUnknown_0862031C[] =
{
    AFFINEANIMCMD_FRAME(0x100, 0x100, 0, 0),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd gUnknown_0862032C[] =
{
    AFFINEANIMCMD_FRAME(0x100, 0x100, 0, 0),
    AFFINEANIMCMD_FRAME(0x10, 0x10, 0, 0x12),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd *const sSpriteAnims_MenuOption[] =
{
    gUnknown_0862031C,
    gUnknown_0862032C
};

static const struct SpriteTemplate sMenuOptionSpriteTemplate =
{
    .tileTag = 3,
    .paletteTag = 4,
    .oam = &sOamData_MenuOption,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = sSpriteAnims_MenuOption,
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
    .tileTag = 1,
    .paletteTag = 3,
    .oam = &sBlueLightOamData,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const struct ScanlineEffectParams sPokenavMainMenuScanlineEffectParams =
{
    (void *)REG_ADDR_WIN0H,
        ((DMA_ENABLE | DMA_START_HBLANK | DMA_REPEAT | DMA_DEST_RELOAD) << 16) | 1,
        1,
        0
};

static bool32 PlayerHasTrainerRematches(void)
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
    struct Pokenav2Struct * state = OpenPokenavMenu();

    if (state == NULL)
        return FALSE;
    
    state->pokenavAlreadyOpen = FALSE;
    return TRUE;
}

bool32 OpenPokenavMenuNotInitial(void)
{
    struct Pokenav2Struct * state = OpenPokenavMenu();

    if (state == NULL)
        return FALSE;

    state->pokenavAlreadyOpen = TRUE;
    return TRUE;
}

static struct Pokenav2Struct * OpenPokenavMenu(void)
{
    struct Pokenav2Struct * state = AllocSubstruct(2, sizeof(struct Pokenav2Struct));

    if (state != NULL)
    {
        state->otherIconsInMotion = FALSE;
        state->loopedTaskId = CreateLoopedTask(LoopedTask_OpenMenu, 1);
        state->isTaskActiveCB = GetCurrentLoopedTaskActive;
    }

    return state;
}

void CreateMenuHandlerLoopedTask(s32 ltIdx)
{
    struct Pokenav2Struct * state = GetSubstructPtr(POKENAV_SUBSTRUCT_MENU_ICONS);
    state->loopedTaskId = CreateLoopedTask(sMenuHandlerLoopTaskFuncs[ltIdx], 1);
    state->isTaskActiveCB = GetCurrentLoopedTaskActive;
}

bool32 IsMenuHandlerLoopedTaskActive(void)
{
    struct Pokenav2Struct * state = GetSubstructPtr(POKENAV_SUBSTRUCT_MENU_ICONS);
    return state->isTaskActiveCB();
}

void FreeMenuHandlerSubstruct2(void)
{
    struct Pokenav2Struct * unk = GetSubstructPtr(POKENAV_SUBSTRUCT_MENU_ICONS);

    DestroyMovingDotsBgTask();
    RemoveWindow(unk->optionDescWindowId);
    FreeAndDestroyMainMenuSprites();
    DestroyMenuOptionGlowTask();
    FreePokenavSubstruct(POKENAV_SUBSTRUCT_MENU_ICONS);
}

static bool32 GetCurrentLoopedTaskActive(void)
{
    struct Pokenav2Struct * unk = GetSubstructPtr(POKENAV_SUBSTRUCT_MENU_ICONS);

    return IsLoopedTaskActive(unk->loopedTaskId);
}

static u32 LoopedTask_OpenMenu(s32 state)
{
    struct Pokenav2Struct * unk = GetSubstructPtr(POKENAV_SUBSTRUCT_MENU_ICONS);

    switch (state)
    {
    case 0:
        InitBgTemplates(sPokenavMainMenuBgTemplates, ARRAY_COUNT(sPokenavMainMenuBgTemplates));
        DecompressAndCopyTileDataToVram(1, gPokenavMessageBox_Gfx, 0, 0, 0);
        SetBgTilemapBuffer(1, unk->bg1TilemapBuffer);
        CopyToBgTilemapBuffer(1, gPokenavMessageBox_Tilemap, 0, 0);
        CopyBgTilemapBufferToVram(1);
        CopyPaletteIntoBufferUnfaded(gPokenavMessageBox_Pal, 0x10, 0x20);
        ChangeBgX(1, 0, 0);
        ChangeBgY(1, 0, 0);
        ChangeBgX(2, 0, 0);
        ChangeBgY(2, 0, 0);
        ChangeBgX(3, 0, 0);
        ChangeBgY(3, 0, 0);
        return LT_INC_AND_PAUSE;
    case 1:
        if (FreeTempTileDataBuffersIfPossible())
            return LT_PAUSE;
        DecompressAndCopyTileDataToVram(2, sPokenavDeviceBgTiles, 0, 0, 0);
        DecompressAndCopyTileDataToVram(2, sPokenavDeviceBgTilemap, 0, 0, 1);
        CopyPaletteIntoBufferUnfaded(sPokenavDeviceBgPal, 0x20, 0x20);
        return LT_INC_AND_PAUSE;
    case 2:
        if (FreeTempTileDataBuffersIfPossible())
            return LT_PAUSE;
        DecompressAndCopyTileDataToVram(3, sPokenavBgDotsTiles, 0, 0, 0);
        DecompressAndCopyTileDataToVram(3, sPokenavBgDotsTilemap, 0, 0, 1);
        CopyPaletteIntoBufferUnfaded(sPokenavBgDotsPal, 0x30, 0x20);
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
        sub_81CA0C8();
        return LT_INC_AND_PAUSE;
    case 6:
        if (IsDma3ManagerBusyWithBgCopy_())
            return LT_PAUSE;
        return LT_INC_AND_CONTINUE;
    case 7:
        ShowBg(1);
        ShowBg(2);
        ShowBg(3);
        if (unk->pokenavAlreadyOpen)
            PokenavFadeScreen(1);
        else
        {
            PlaySE(SE_POKENAV_ON);
            PokenavFadeScreen(3);
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
        SetupCurrentMenuOptionsGfx();
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
        SetMenuOptionGfxParams_CursorMoved();
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
        SetupPokenavMenuOptions();
        HideMainOrSubMenuLeftHeader(POKENAV_GFX_MAIN_MENU, 0);
        PlaySE(SE_SELECT);
        return LT_INC_AND_PAUSE;
    case 1:
        if (AreMenuOptionSpritesMoving())
            return LT_PAUSE;
        if (AreLeftHeaderSpritesMoving())
            return LT_PAUSE;
        sub_81CA0C8();
        LoadLeftHeaderGfxForIndex(1);
        return LT_INC_AND_PAUSE;
    case 2:
        SetupCurrentMenuOptionsGfx();
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
        SetupPokenavMenuOptions();
        HideMainOrSubMenuLeftHeader(POKENAV_GFX_CONDITION_MENU, 0);
        return LT_INC_AND_PAUSE;
    case 1:
        if (AreMenuOptionSpritesMoving())
            return LT_PAUSE;
        if (AreLeftHeaderSpritesMoving())
            return LT_PAUSE;
        sub_81CA0C8();
        LoadLeftHeaderGfxForIndex(0);
        return LT_INC_AND_PAUSE;
    case 2:
        SetupCurrentMenuOptionsGfx();
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
        SetupPokenavMenuOptions();
        PlaySE(SE_SELECT);
        return LT_INC_AND_PAUSE;
    case 1:
        if (AreMenuOptionSpritesMoving())
            return LT_PAUSE;
        LoadLeftHeaderGfxForIndex(7);
        sub_81CA0C8();
        return LT_INC_AND_PAUSE;
    case 2:
        SetupCurrentMenuOptionsGfx();
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
        SetupPokenavMenuOptions();
        HideMainOrSubMenuLeftHeader(POKENAV_GFX_SEARCH_MENU, 0);
        return LT_INC_AND_PAUSE;
    case 1:
        if (AreMenuOptionSpritesMoving())
            return LT_PAUSE;
        if (AreLeftHeaderSpritesMoving())
            return LT_PAUSE;
        sub_81CA0C8();
        return LT_INC_AND_PAUSE;
    case 2:
        SetupCurrentMenuOptionsGfx();
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
        SetupPokenavMenuOptions();
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
        PokenavFadeScreen(0);
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
    FreeSpriteTilesByTag(3);
    FreeSpriteTilesByTag(1);
    FreeSpritePaletteByTag(4);
    FreeSpritePaletteByTag(5);
    FreeSpritePaletteByTag(6);
    FreeSpritePaletteByTag(7);
    FreeSpritePaletteByTag(8);
    FreeSpritePaletteByTag(3);
    DestroyMenuOptionSprites();
    DestroyRematchBlueLightSpriteId();
}

static void CreateMenuOptionSprites(void)
{
    s32 i, j;
    struct Pokenav2Struct * unk = GetSubstructPtr(POKENAV_SUBSTRUCT_MENU_ICONS);

    for (i = 0; i < MAX_POKENAV_MENUITEMS; i++)
    {
        // Each menu option is 4 subsprites
        for (j = 0; j < 4; j++)
        {
            u8 spriteId = CreateSprite(&sMenuOptionSpriteTemplate, 0x8c, 20 * i + 40, 3);
            unk->iconSprites[i][j] = &gSprites[spriteId];
            gSprites[spriteId].pos2.x = 32 * j;
        }
    }
}

static void DestroyMenuOptionSprites(void)
{
    s32 i, j;
    struct Pokenav2Struct * unk = GetSubstructPtr(POKENAV_SUBSTRUCT_MENU_ICONS);

    for (i = 0; i < MAX_POKENAV_MENUITEMS; i++)
    {
        for (j = 0; j < 4; j++)
        {
            FreeSpriteOamMatrix(unk->iconSprites[i][j]);
            DestroySprite(unk->iconSprites[i][j]);
        }
    }
}

static void sub_81CA0C8(void)
{
    s32 menuType = GetPokenavMenuType();
    DrawOptionLabelGfx(sPokenavMenuOptionLabelGfx[menuType].tiles, sPokenavMenuOptionLabelGfx[menuType].yStart, sPokenavMenuOptionLabelGfx[menuType].deltaY);
}

static void DrawOptionLabelGfx(const u16 *const *tiles, s32 yPos, s32 deltaY)
{
    s32 i, j;
    struct Pokenav2Struct * unk = GetSubstructPtr(POKENAV_SUBSTRUCT_MENU_ICONS);
    s32 sp04 = GetSpriteTileStartByTag(3);

    for (i = 0; i < MAX_POKENAV_MENUITEMS; i++)
    {
        if (*tiles != NULL)
        {
            for (j = 0; j < 4; j++)
            {
                unk->iconSprites[i][j]->oam.tileNum = (*tiles)[0] + sp04 + 8 * j;
                unk->iconSprites[i][j]->oam.paletteNum = IndexOfSpritePaletteTag((*tiles)[1] + 4);
                unk->iconSprites[i][j]->invisible = TRUE;
                unk->iconSprites[i][j]->pos1.y = yPos;
                unk->iconSprites[i][j]->pos1.x = 0x8c;
                unk->iconSprites[i][j]->pos2.x = 32 * j;
            }
            unk->iconVisible[i] = TRUE;
        }
        else
        {
            for (j = 0; j < 4; j++)
            {
                unk->iconSprites[i][j]->invisible = TRUE;
            }
            unk->iconVisible[i] = FALSE;
        }
        tiles++;
        yPos += deltaY;
    }
}

static void SetupCurrentMenuOptionsGfx(void)
{
    s32 i;
    struct Pokenav2Struct *icons = GetSubstructPtr(POKENAV_SUBSTRUCT_MENU_ICONS);
    s32 r8 = GetPokenavCursorPos();
    s32 r7 = 0;
    s32 r2;

    for (i = 0; i < MAX_POKENAV_MENUITEMS; i++)
    {
        if (icons->iconVisible[i])
        {
            if (r7++ == r8)
            {
                r2 = 0x82;
                icons->cursorPos = i;
            }
            else
                r2 = 0x8c;
            SetMenuOptionGfxParamsInactive(icons->iconSprites[i], 0x100, r2, 0xC);
            SetMenuOptionGfxInvisibility(icons->iconSprites[i], FALSE);
        }
        else
        {
            SetMenuOptionGfxInvisibility(icons->iconSprites[i], TRUE);
        }
    }
}

static void SetMenuOptionGfxParams_CursorMoved(void)
{
    s32 i;
    struct Pokenav2Struct *icons = GetSubstructPtr(POKENAV_SUBSTRUCT_MENU_ICONS);
    s32 prevPos = GetPokenavCursorPos();
    s32 newPos;

    for (i = 0, newPos = 0; i < MAX_POKENAV_MENUITEMS; i++)
    {
        if (icons->iconVisible[i])
        {
            if (newPos == prevPos)
            {
                newPos = i;
                break;
            }
            newPos++;
        }
    }

    SetMenuOptionGfxParamsInactive(icons->iconSprites[icons->cursorPos], 0x82, 0x8c, 0x4);
    SetMenuOptionGfxParamsInactive(icons->iconSprites[newPos], 0x8c, 0x82, 0x4);
    icons->cursorPos = newPos;
}

static void SetupPokenavMenuOptions(void)
{
    s32 i;
    struct Pokenav2Struct *optionIcons = GetSubstructPtr(POKENAV_SUBSTRUCT_MENU_ICONS);

    for (i = 0; i < MAX_POKENAV_MENUITEMS; i++)
    {
        if (optionIcons->iconVisible[i])
        {
            if (optionIcons->cursorPos != i)
                SetMenuOptionGfxParamsInactive(optionIcons->iconSprites[i], 0x8C, 0x100, 0x8);
            else
                SetMenuOptionGfxParamsActive(optionIcons->iconSprites[i]);
        }
    }
}

static bool32 AreMenuOptionSpritesMoving(void)
{
    s32 i;
    struct Pokenav2Struct *icons = GetSubstructPtr(POKENAV_SUBSTRUCT_MENU_ICONS);

    for (i = 0; i < MAX_POKENAV_MENUITEMS; i++)
    {
        if (icons->iconSprites[i][0]->callback != SpriteCallbackDummy)
            return TRUE;
    }

    if (icons->otherIconsInMotion)
        return TRUE;

    return FALSE;
}

static void SetMenuOptionGfxParamsInactive(struct Sprite ** sprites, s32 x, s32 a2, s32 a3)
{
    s32 i;

    for (i = 0; i < 4; i++)
    {
        (*sprites)->pos1.x = x;
        (*sprites)->data[0] = a3;
        (*sprites)->data[1] = 16 * (a2 - x) / a3;
        (*sprites)->data[2] = 16 * x;
        (*sprites)->data[7] = a2;
        (*sprites)->callback = sub_81CA474;
        sprites++;
    }
}

static void SetMenuOptionGfxParamsActive(struct Sprite ** sprites)
{
    s32 i;
    struct Pokenav2Struct * unk = GetSubstructPtr(POKENAV_SUBSTRUCT_MENU_ICONS);
    u8 taskId;

    for (i = 0; i < 4; i++)
    {
        (*sprites)->oam.objMode = ST_OAM_OBJ_BLEND;
        (*sprites)->oam.affineMode = ST_OAM_AFFINE_DOUBLE;
        (*sprites)->callback = sub_81CA4AC;
        (*sprites)->data[0] = 8;
        (*sprites)->data[1] = 0;
        (*sprites)->data[7] = i;
        InitSpriteAffineAnim(sprites[0]);
        StartSpriteAffineAnim(sprites[0], 0);
        sprites++;
    }

    SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(0x10, 0x00));
    taskId = CreateTask(sub_81CA580, 3);
    gTasks[taskId].data[0] = 8;
    unk->otherIconsInMotion++;
}

static void SetMenuOptionGfxInvisibility(struct Sprite ** sprites, bool32 invisible)
{
    s32 i;

    for (i = 0; i < 4; i++)
    {
        (*sprites)->invisible = invisible;
        sprites++;
    }
}

static void sub_81CA474(struct Sprite * sprite)
{
    sprite->data[0]--;
    if (sprite->data[0] != -1)
    {
        sprite->data[2] += sprite->data[1];
        sprite->pos1.x = sprite->data[2] >> 4;
    }
    else
    {
        sprite->pos1.x = sprite->data[7];
        sprite->callback = SpriteCallbackDummy;
    }
}

static void sub_81CA4AC(struct Sprite * sprite)
{
    s32 r0;
    s32 r1;
    if (sprite->data[0] == 0)
    {
        if (sprite->data[1] == 0)
        {
            StartSpriteAffineAnim(sprite, 1);
            sprite->data[1]++;
            sprite->data[2] = 0x100;
            sprite->pos1.x += sprite->pos2.x;
            sprite->pos2.x = 0;
        }
        else
        {
            sprite->data[2] += 16;
            r0 = sprite->data[2];
            r1 = r0 >> 3;
            r1 = (r1 - 32) / 2;
            switch (sprite->data[7])
            {
            case 0:
                sprite->pos2.x = -r1 * 3;
                break;
            case 1:
                sprite->pos2.x = -r1;
                break;
            case 2:
                sprite->pos2.x = r1;
                break;
            case 3:
                sprite->pos2.x = r1 * 3;
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
        sprite->data[0]--;
    }
}

static void sub_81CA580(u8 taskId)
{
    s16 * data = gTasks[taskId].data;

    if (data[0] == 0)
    {
        switch (data[1])
        {
        case 0:
            data[2] = 16;
            data[3] = 0;
            SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_EFFECT_NONE | BLDCNT_TGT2_ALL);
            SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(0x10, 0x00));
            data[1]++;
            break;
        case 1:
            if (data[4] & 1)
            {
                data[2] -= 3;
                if (data[2] < 0)
                    data[2] = 0;
            }
            else
            {
                data[3] += 3;
                if (data[3] > 16)
                    data[3] = 16;
            }
            SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(data[2], data[3]));
            data[4]++;
            if (data[4] == 12)
            {
                ((struct Pokenav2Struct *)GetSubstructPtr(POKENAV_SUBSTRUCT_MENU_ICONS))->otherIconsInMotion--;
                SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(0x00, 0x10));
                DestroyTask(taskId);
            }
            break;
        }
    }
    else
        data[0]--;
}

static void CreateMatchCallBlueLightSprite(void)
{
    struct Pokenav2Struct * ptr = GetSubstructPtr(POKENAV_SUBSTRUCT_MENU_ICONS);
    u8 spriteId = CreateSprite(&sMatchCallBlueLightSpriteTemplate, 0x10, 0x60, 4);
    ptr->blueLightSpriteId = &gSprites[spriteId];
    if (PlayerHasTrainerRematches())
        ptr->blueLightSpriteId->callback = SpriteCB_BlinkingBlueLight;
    else
        ptr->blueLightSpriteId->invisible = TRUE;
}

static void DestroyRematchBlueLightSpriteId(void)
{
    struct Pokenav2Struct *ptr = GetSubstructPtr(POKENAV_SUBSTRUCT_MENU_ICONS);
    DestroySprite(ptr->blueLightSpriteId);
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
    struct Pokenav2Struct * ptr = GetSubstructPtr(POKENAV_SUBSTRUCT_MENU_ICONS);

    ptr->optionDescWindowId = AddWindow(&sOptionDescWindowTemplate);
    PutWindowTilemap(ptr->optionDescWindowId);
    FillWindowPixelBuffer(ptr->optionDescWindowId, PIXEL_FILL(6));
    CopyWindowToVram(ptr->optionDescWindowId, 3);
}

static void PrintCurrentOptionDescription(void)
{
    struct Pokenav2Struct * ptr = GetSubstructPtr(POKENAV_SUBSTRUCT_MENU_ICONS);
    int menuItem = GetCurrentMenuItemId();
    const u8 * s = sPageDescriptions[menuItem];
    u32 width = GetStringWidth(1, s, -1);
    FillWindowPixelBuffer(ptr->optionDescWindowId, PIXEL_FILL(6));
    AddTextPrinterParameterized3(ptr->optionDescWindowId, 1, (192 - width) / 2, 1, sOptionDescTextColors, 0, s);
}

// Printed when Ribbons is selected if no PC/party mons have ribbons
// Can occur by obtaining a mon with a ribbon and then releasing all ribbon winners
static void PrintNoRibbonWinners(void)
{
    struct Pokenav2Struct * ptr = GetSubstructPtr(POKENAV_SUBSTRUCT_MENU_ICONS);
    const u8 * s = gText_NoRibbonWinners;
    u32 width = GetStringWidth(1, s, -1);
    FillWindowPixelBuffer(ptr->optionDescWindowId, PIXEL_FILL(6));
    AddTextPrinterParameterized3(ptr->optionDescWindowId, 1, (192 - width) / 2, 1, sOptionDescTextColors2, 0, s);
}

static bool32 IsDma3ManagerBusyWithBgCopy_(void)
{
    return IsDma3ManagerBusyWithBgCopy();
}

static void CreateMovingBgDotsTask(void)
{
    struct Pokenav2Struct * ptr = GetSubstructPtr(POKENAV_SUBSTRUCT_MENU_ICONS);
    ptr->bg3ScrollTaskId = CreateTask(Task_MoveBgDots, 2);
}

static void DestroyMovingDotsBgTask(void)
{
    struct Pokenav2Struct * ptr = GetSubstructPtr(POKENAV_SUBSTRUCT_MENU_ICONS);
    DestroyTask(ptr->bg3ScrollTaskId);
}

static void Task_MoveBgDots(u8 taskId)
{
    ChangeBgX(3, 0x80, 1);
}

static void CreateBgDotPurplePalTask(void)
{
    u8 taskId = CreateTask(Task_UpdateBgDotsPalette, 3);
    SetWordTaskArg(taskId, 1, (uintptr_t)(sPokenavBgDotsPal + 1));
    SetWordTaskArg(taskId, 3, (uintptr_t)(sPokenavBgDotsPal + 7));
}

static void ChangeBgDotsColorToPurple(void)
{
    CopyPaletteIntoBufferUnfaded(sPokenavBgDotsPal + 7, 0x31, 4);
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
    LoadPalette(sp8, 0x31, 4);
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
    SetGpuRegBits(REG_OFFSET_WININ, 0x3F);
    SetGpuRegBits(REG_OFFSET_WINOUT, 0x1F);
    SetGpuRegBits(REG_OFFSET_WIN0V, 0xA0);
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
    CpuFill16(0, gScanlineEffectRegBuffers[0], 0x140);
    CpuFill16(0, gScanlineEffectRegBuffers[1], 0x140);
    CpuFill16(RGB(16, 23, 28), &gScanlineEffectRegBuffers[0][r4], 0x20);
    CpuFill16(RGB(16, 23, 28), &gScanlineEffectRegBuffers[1][r4], 0x20);
}

void ResetBldCnt_(void)
{
    ResetBldCnt();
}
