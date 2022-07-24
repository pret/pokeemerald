#include "global.h"
#include "pokenav.h"
#include "constants/songs.h"
#include "sound.h"
#include "constants/rgb.h"
#include "palette.h"
#include "bg.h"
#include "window.h"
#include "strings.h"
#include "graphics.h"
#include "decompress.h"
#include "gpu_regs.h"
#include "menu.h"
#include "dma3.h"

struct Pokenav_MainMenu
{
    void (*loopTask)(u32);
    u32 (*isLoopTaskActiveFunc)(void);
    u32 unused;
    u32 currentTaskId;
    u32 helpBarWindowId;
    u32 palettes;
    struct Sprite *spinningPokenav;
    struct Sprite *leftHeaderSprites[2];
    struct Sprite *submenuLeftHeaderSprites[2];
    u8 tilemapBuffer[BG_SCREEN_SIZE];
};

// This struct uses a 32bit tag, and doesn't have a size field.
// Needed to match LoadLeftHeaderGfxForSubMenu.
struct CompressedSpriteSheetNoSize
{
    const u32 *data;  // LZ77 compressed palette data
    u32 tag;
};

static void CleanupPokenavMainMenuResources(void);
static void LoadLeftHeaderGfxForSubMenu(u32);
static void LoadLeftHeaderGfxForMenu(u32);
static void HideLeftHeaderSubmenuSprites(bool32);
static void HideLeftHeaderSprites(bool32);
static void ShowLeftHeaderSprites(u32, bool32);
static void ShowLeftHeaderSubmenuSprites(u32, bool32);
static void MoveLeftHeader(struct Sprite *, s32, s32, s32);
static void SpriteCB_MoveLeftHeader(struct Sprite *);
static void InitPokenavMainMenuResources(void);
static void CreateLeftHeaderSprites(void);
static void InitHelpBar(void);
static u32 LoopedTask_SlideMenuHeaderUp(s32);
static u32 LoopedTask_SlideMenuHeaderDown(s32);
static void DrawHelpBar(u32);
static void SpriteCB_SpinningPokenav(struct Sprite*);
static u32 LoopedTask_InitPokenavMenu(s32);

static const u16 sSpinningPokenav_Pal[] = INCBIN_U16("graphics/pokenav/nav_icon.gbapal");
static const u32 sSpinningPokenav_Gfx[] = INCBIN_U32("graphics/pokenav/nav_icon.4bpp.lz");
static const u32 sBlueLightCopy[] = INCBIN_U32("graphics/pokenav/blue_light.4bpp.lz"); // Unused copy of sMatchCallBlueLightTiles

const struct BgTemplate gPokenavMainMenuBgTemplates[] =
{
    {
        .bg = 0,
        .charBaseIndex = 0,
        .mapBaseIndex = 5,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0,
    }
};

static const struct WindowTemplate sHelpBarWindowTemplate[] =
{
    {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 22,
        .width = 16,
        .height = 2,
        .paletteNum = 0,
        .baseBlock = 0x36,
    },
    DUMMY_WIN_TEMPLATE
};

static const u8 *const sHelpBarTexts[HELPBAR_COUNT] =
{
    [HELPBAR_NONE]                 = gText_Pokenav_ClearButtonList,
    [HELPBAR_MAP_ZOOMED_OUT]       = gText_PokenavMap_ZoomedOutButtons,
    [HELPBAR_MAP_ZOOMED_IN]        = gText_PokenavMap_ZoomedInButtons,
    [HELPBAR_CONDITION_MON_LIST]   = gText_PokenavCondition_MonListButtons,
    [HELPBAR_CONDITION_MON_STATUS] = gText_PokenavCondition_MonStatusButtons,
    [HELPBAR_CONDITION_MARKINGS]   = gText_PokenavCondition_MarkingButtons,
    [HELPBAR_MC_TRAINER_LIST]      = gText_PokenavMatchCall_TrainerListButtons,
    [HELPBAR_MC_CALL_MENU]         = gText_PokenavMatchCall_CallMenuButtons,
    [HELPBAR_MC_CHECK_PAGE]        = gText_PokenavMatchCall_CheckTrainerButtons,
    [HELPBAR_RIBBONS_MON_LIST]     = gText_PokenavRibbons_MonListButtons,
    [HELPBAR_RIBBONS_LIST]         = gText_PokenavRibbons_RibbonListButtons,
    [HELPBAR_RIBBONS_CHECK]        = gText_PokenavRibbons_RibbonCheckButtons,
};

static const u8 sHelpBarTextColors[3] =
{
    TEXT_COLOR_RED, TEXT_COLOR_WHITE, TEXT_COLOR_DARK_GRAY
};

static const struct CompressedSpriteSheet sSpinningPokenavSpriteSheet[] =
{
    {
        .data = sSpinningPokenav_Gfx,
        .size = 0x1000,
        .tag = 0,
    }
};

static const struct SpritePalette sSpinningNavgearPalettes[] =
{
    {
        .data = sSpinningPokenav_Pal,
        .tag = 0,
    },
    {}
};

static const struct CompressedSpriteSheet sMenuLeftHeaderSpriteSheet =
{
    .data = gPokenavLeftHeaderHoennMap_Gfx, // Hoenn map is the first of the headers listed
    .size = 0xC00,
    .tag = 2
};

static const struct CompressedSpriteSheet sMenuLeftHeaderSpriteSheets[] =
{
    [POKENAV_GFX_MAIN_MENU] = {
        .data = gPokenavLeftHeaderMainMenu_Gfx,
        .size = 0x20,
        .tag = 3
    },
    [POKENAV_GFX_CONDITION_MENU] = {
        .data = gPokenavLeftHeaderCondition_Gfx,
        .size = 0x20,
        .tag = 1
    },
    [POKENAV_GFX_RIBBONS_MENU] = {
        .data = gPokenavLeftHeaderRibbons_Gfx,
        .size = 0x20,
        .tag = 2
    },
    [POKENAV_GFX_MATCH_CALL_MENU] = {
        .data = gPokenavLeftHeaderMatchCall_Gfx,
        .size = 0x20,
        .tag = 4
    },
    [POKENAV_GFX_MAP_MENU_ZOOMED_OUT] = {
        .data = gPokenavLeftHeaderHoennMap_Gfx,
        .size = 0x20,
        .tag = 0
    },
    [POKENAV_GFX_MAP_MENU_ZOOMED_IN] = {
        .data = gPokenavLeftHeaderHoennMap_Gfx,
        .size = 0x40,
        .tag = 0
    }
};

static const struct CompressedSpriteSheetNoSize sPokenavSubMenuLeftHeaderSpriteSheets[] =
{
    [POKENAV_GFX_PARTY_MENU - POKENAV_GFX_SUBMENUS_START] = {
        .data = gPokenavLeftHeaderParty_Gfx,
        .tag = 1
    },
    [POKENAV_GFX_SEARCH_MENU - POKENAV_GFX_SUBMENUS_START] = {
        .data = gPokenavLeftHeaderSearch_Gfx,
        .tag = 1
    },
    [POKENAV_GFX_COOL_MENU - POKENAV_GFX_SUBMENUS_START] = {
        .data = gPokenavLeftHeaderCool_Gfx,
        .tag = 4
    },
    [POKENAV_GFX_BEAUTY_MENU - POKENAV_GFX_SUBMENUS_START] = {
        .data = gPokenavLeftHeaderBeauty_Gfx,
        .tag = 1
    },
    [POKENAV_GFX_CUTE_MENU - POKENAV_GFX_SUBMENUS_START] = {
        .data = gPokenavLeftHeaderCute_Gfx,
        .tag = 2
    },
    [POKENAV_GFX_SMART_MENU - POKENAV_GFX_SUBMENUS_START] = {
        .data = gPokenavLeftHeaderSmart_Gfx,
        .tag = 0
    },
    [POKENAV_GFX_TOUGH_MENU - POKENAV_GFX_SUBMENUS_START] = {
        .data = gPokenavLeftHeaderTough_Gfx,
        .tag = 0
    }
};

static const struct OamData sSpinningPokenavSpriteOam =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x32),
    .x = 0,
    .size = SPRITE_SIZE(32x32),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
};

static const union AnimCmd sSpinningPokenavAnims[] =
{
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(16, 8),
    ANIMCMD_FRAME(32, 8),
    ANIMCMD_FRAME(48, 8),
    ANIMCMD_FRAME(64, 8),
    ANIMCMD_FRAME(80, 8),
    ANIMCMD_FRAME(96, 8),
    ANIMCMD_FRAME(112, 8),
    ANIMCMD_JUMP(0)
};

static const union AnimCmd *const sSpinningPokenavAnimTable[] =
{
    sSpinningPokenavAnims
};

static const struct SpriteTemplate sSpinningPokenavSpriteTemplate =
{
    .tileTag = 0,
    .paletteTag = 0,
    .oam = &sSpinningPokenavSpriteOam,
    .anims = sSpinningPokenavAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_SpinningPokenav
};

static const struct OamData sOamData_LeftHeader =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(64x32),
    .x = 0,
    .size = SPRITE_SIZE(64x32),
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
};

static const struct OamData sOamData_SubmenuLeftHeader =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x16),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(32x16),
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
};

static const struct SpriteTemplate sLeftHeaderSpriteTemplate =
{
    .tileTag = 2,
    .paletteTag = 1,
    .oam = &sOamData_LeftHeader,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate sSubmenuLeftHeaderSpriteTemplate =
{
    .tileTag = 2,
    .paletteTag = 2,
    .oam = &sOamData_SubmenuLeftHeader,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

bool32 InitPokenavMainMenu(void)
{
    struct Pokenav_MainMenu *menu;

    menu = AllocSubstruct(POKENAV_SUBSTRUCT_MAIN_MENU, sizeof(struct Pokenav_MainMenu));
    if (menu == NULL)
        return FALSE;

    ResetSpriteData();
    FreeAllSpritePalettes();
    menu->currentTaskId = CreateLoopedTask(LoopedTask_InitPokenavMenu, 1);
    return TRUE;
}

u32 PokenavMainMenuLoopedTaskIsActive(void)
{
    struct Pokenav_MainMenu *menu = GetSubstructPtr(POKENAV_SUBSTRUCT_MAIN_MENU);
    return IsLoopedTaskActive(menu->currentTaskId);
}

void ShutdownPokenav(void)
{
    PlaySE(SE_POKENAV_OFF);
    ResetBldCnt_();
    BeginNormalPaletteFade(PALETTES_ALL, -1, 0, 16, RGB_BLACK);
}

bool32 WaitForPokenavShutdownFade(void)
{
    if (!gPaletteFade.active)
    {
        FreeMenuHandlerSubstruct2();
        CleanupPokenavMainMenuResources();
        FreeAllWindowBuffers();
        return FALSE;
    }

    return TRUE;
}

static u32 LoopedTask_InitPokenavMenu(s32 state)
{
    struct Pokenav_MainMenu *menu;

    switch (state)
    {
    case 0:
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
        FreeAllWindowBuffers();
        ResetBgsAndClearDma3BusyFlags(0);
        InitBgsFromTemplates(0, gPokenavMainMenuBgTemplates, ARRAY_COUNT(gPokenavMainMenuBgTemplates));
        ResetBgPositions();
        ResetTempTileDataBuffers();
        return LT_INC_AND_CONTINUE;
    case 1:
        menu = GetSubstructPtr(POKENAV_SUBSTRUCT_MAIN_MENU);
        DecompressAndCopyTileDataToVram(0, &gPokenavHeader_Gfx, 0, 0, 0);
        SetBgTilemapBuffer(0, menu->tilemapBuffer);
        CopyToBgTilemapBuffer(0, &gPokenavHeader_Tilemap, 0, 0);
        CopyPaletteIntoBufferUnfaded(gPokenavHeader_Pal, 0, 0x20);
        CopyBgTilemapBufferToVram(0);
        return LT_INC_AND_PAUSE;
    case 2:
        if (FreeTempTileDataBuffersIfPossible())
            return LT_PAUSE;

        InitHelpBar();
        return LT_INC_AND_PAUSE;
    case 3:
        if (IsDma3ManagerBusyWithBgCopy())
            return LT_PAUSE;

        InitPokenavMainMenuResources();
        CreateLeftHeaderSprites();
        ShowBg(0);
        return LT_FINISH;
    default:
        return LT_FINISH;
    }
}

void SetActiveMenuLoopTasks(void *createLoopTask, void *isLoopTaskActive) // Fix types later.
{
    struct Pokenav_MainMenu *menu = GetSubstructPtr(POKENAV_SUBSTRUCT_MAIN_MENU);
    menu->loopTask = createLoopTask;
    menu->isLoopTaskActiveFunc = isLoopTaskActive;
    menu->unused = 0;
}

void RunMainMenuLoopedTask(u32 state)
{
    struct Pokenav_MainMenu *menu = GetSubstructPtr(POKENAV_SUBSTRUCT_MAIN_MENU);
    menu->unused = 0;
    menu->loopTask(state);
}

u32 IsActiveMenuLoopTaskActive(void)
{
    struct Pokenav_MainMenu *menu = GetSubstructPtr(POKENAV_SUBSTRUCT_MAIN_MENU);
    return menu->isLoopTaskActiveFunc();
}

void SlideMenuHeaderUp(void)
{
    struct Pokenav_MainMenu *menu = GetSubstructPtr(POKENAV_SUBSTRUCT_MAIN_MENU);
    menu->currentTaskId = CreateLoopedTask(LoopedTask_SlideMenuHeaderUp, 4);
}

void SlideMenuHeaderDown(void)
{
    struct Pokenav_MainMenu *menu = GetSubstructPtr(POKENAV_SUBSTRUCT_MAIN_MENU);
    menu->currentTaskId = CreateLoopedTask(LoopedTask_SlideMenuHeaderDown, 4);
}

bool32 MainMenuLoopedTaskIsBusy(void)
{
    struct Pokenav_MainMenu *menu = GetSubstructPtr(POKENAV_SUBSTRUCT_MAIN_MENU);
    return IsLoopedTaskActive(menu->currentTaskId);
}

static u32 LoopedTask_SlideMenuHeaderUp(s32 state)
{
    switch (state)
    {
    default:
        return LT_FINISH;
    case 1:
        return LT_INC_AND_PAUSE;
    case 0:
        return LT_INC_AND_PAUSE;
    case 2:
        if (ChangeBgY(0, 384, BG_COORD_ADD) >= 0x2000u)
        {
            ChangeBgY(0, 0x2000, BG_COORD_SET);
            return LT_FINISH;
        }

        return LT_PAUSE;
    }
}

static u32 LoopedTask_SlideMenuHeaderDown(s32 state)
{
    if (ChangeBgY(0, 384, BG_COORD_SUB) <= 0)
    {
        ChangeBgY(0, 0, BG_COORD_SET);
        return LT_FINISH;
    }
    return LT_PAUSE;
}

void CopyPaletteIntoBufferUnfaded(const u16 *palette, u32 bufferOffset, u32 size)
{
    CpuCopy16(palette, gPlttBufferUnfaded + bufferOffset, size);
}

void Pokenav_AllocAndLoadPalettes(const struct SpritePalette *palettes)
{
    const struct SpritePalette *current;
    u32 index;

    for (current = palettes; current->data != NULL; current++)
    {
        index = AllocSpritePalette(current->tag);
        if (index == 0xFF)
        {
            break;
        }
        else
        {
            index = (index * 16) + 0x100;
            CopyPaletteIntoBufferUnfaded(current->data, index, 0x20);
        }
    }
}

void PokenavFillPalette(u32 palIndex, u16 fillValue)
{
    CpuFill16(fillValue, gPlttBufferFaded + 0x100 + (palIndex * 16), 16 * sizeof(u16));
}

void PokenavCopyPalette(const u16 *src, const u16 *dest, int size, int a3, int a4, u16 *palette)
{
    if (a4 == 0)
    {
        CpuCopy16(src, palette, size * 2);
    }
    else if (a4 >= a3)
    {
        CpuCopy16(dest, palette, size * 2);
    }
    else
    {
        int r, g, b;
        int r1, g1, b1;
        while (size--)
        {
            r = GET_R(*src);
            g = GET_G(*src);
            b = GET_B(*src);

            r1 = ((((GET_R(*dest) << 8) - (r << 8)) / a3) * a4) >> 8;
            g1 = ((((GET_G(*dest) << 8) - (g << 8)) / a3) * a4) >> 8;
            b1 = ((((GET_B(*dest) << 8) - (b << 8)) / a3) * a4) >> 8;

            r = (r + r1) & 0x1F; //_RGB(r + r1, g + g1, b + b1); doesn't match
            g = (g + g1) & 0x1F;
            b = (b + b1) & 0x1F;

            *palette = RGB2(r, g, b);

            src++, dest++;
            palette++;
        }
    }
}

void PokenavFadeScreen(s32 fadeType)
{
    struct Pokenav_MainMenu *menu = GetSubstructPtr(POKENAV_SUBSTRUCT_MAIN_MENU);

    switch (fadeType)
    {
    case POKENAV_FADE_TO_BLACK:
        BeginNormalPaletteFade(menu->palettes, -2, 0, 16, RGB_BLACK);
        break;
    case POKENAV_FADE_FROM_BLACK:
        BeginNormalPaletteFade(menu->palettes, -2, 16, 0, RGB_BLACK);
        break;
    case POKENAV_FADE_TO_BLACK_ALL:
        BeginNormalPaletteFade(PALETTES_ALL, -2, 0, 16, RGB_BLACK);
        break;
    case POKENAV_FADE_FROM_BLACK_ALL:
        BeginNormalPaletteFade(PALETTES_ALL, -2, 16, 0, RGB_BLACK);
        break;
    }
}

bool32 IsPaletteFadeActive(void)
{
    return gPaletteFade.active;
}

// Excludes the first obj and bg palettes
void FadeToBlackExceptPrimary(void)
{
    BlendPalettes(PALETTES_ALL & ~(1 << 16 | 1), 16, RGB_BLACK);
}

void InitBgTemplates(const struct BgTemplate *templates, int count)
{
    int i;

    for (i = 0; i < count; i++)
        InitBgFromTemplate(templates++);
}

static void InitHelpBar(void)
{
    struct Pokenav_MainMenu *menu = GetSubstructPtr(POKENAV_SUBSTRUCT_MAIN_MENU);

    InitWindows(&sHelpBarWindowTemplate[0]);
    menu->helpBarWindowId = 0;
    DrawHelpBar(menu->helpBarWindowId);
    PutWindowTilemap(menu->helpBarWindowId);
    CopyWindowToVram(menu->helpBarWindowId, COPYWIN_FULL);
}

void PrintHelpBarText(u32 textId)
{
    struct Pokenav_MainMenu *menu = GetSubstructPtr(POKENAV_SUBSTRUCT_MAIN_MENU);

    DrawHelpBar(menu->helpBarWindowId);
    AddTextPrinterParameterized3(menu->helpBarWindowId, FONT_NORMAL, 0, 1, sHelpBarTextColors, 0, sHelpBarTexts[textId]);
}

bool32 WaitForHelpBar(void)
{
    return IsDma3ManagerBusyWithBgCopy();
}

static void DrawHelpBar(u32 windowId)
{
    FillWindowPixelBuffer(windowId, PIXEL_FILL(4));
    FillWindowPixelRect(windowId, PIXEL_FILL(5), 0, 0, 0x80, 1);
}

static void InitPokenavMainMenuResources(void)
{
    s32 i;
    u8 spriteId;
    struct Pokenav_MainMenu *menu = GetSubstructPtr(POKENAV_SUBSTRUCT_MAIN_MENU);

    for (i = 0; i < ARRAY_COUNT(sSpinningPokenavSpriteSheet); i++)
        LoadCompressedSpriteSheet(&sSpinningPokenavSpriteSheet[i]);

    Pokenav_AllocAndLoadPalettes(sSpinningNavgearPalettes);
    menu->palettes = ~1 & ~(0x10000 << IndexOfSpritePaletteTag(0));
    spriteId = CreateSprite(&sSpinningPokenavSpriteTemplate, 220, 12, 0);
    menu->spinningPokenav = &gSprites[spriteId];
}

static void CleanupPokenavMainMenuResources(void)
{
    struct Pokenav_MainMenu *menu = GetSubstructPtr(POKENAV_SUBSTRUCT_MAIN_MENU);

    DestroySprite(menu->spinningPokenav);
    FreeSpriteTilesByTag(0);
    FreeSpritePaletteByTag(0);
}

static void SpriteCB_SpinningPokenav(struct Sprite *sprite)
{
    // If the background starts scrolling, follow it.
    sprite->y2 = (GetBgY(0) / 256u) * -1;
}

struct Sprite *GetSpinningPokenavSprite(void)
{
    struct Pokenav_MainMenu *menu = GetSubstructPtr(POKENAV_SUBSTRUCT_MAIN_MENU);

    menu->spinningPokenav->callback = SpriteCallbackDummy;
    return menu->spinningPokenav;
}

void HideSpinningPokenavSprite(void)
{
    struct Pokenav_MainMenu *menu = GetSubstructPtr(POKENAV_SUBSTRUCT_MAIN_MENU);

    // Move sprite so it's no longer visible
    menu->spinningPokenav->x = 220;
    menu->spinningPokenav->y = 12;
    menu->spinningPokenav->callback = SpriteCB_SpinningPokenav;
    menu->spinningPokenav->invisible = FALSE;
    menu->spinningPokenav->oam.priority = 0;
    menu->spinningPokenav->subpriority = 0;
}

static void CreateLeftHeaderSprites(void)
{
    s32 i, spriteId;
    struct Pokenav_MainMenu *menu = GetSubstructPtr(POKENAV_SUBSTRUCT_MAIN_MENU);

    LoadCompressedSpriteSheet(&sMenuLeftHeaderSpriteSheet);
    AllocSpritePalette(1);
    AllocSpritePalette(2);
    for (i = 0; i < (s32)ARRAY_COUNT(menu->leftHeaderSprites); i++)
    {
        // Create main left header
        spriteId = CreateSprite(&sLeftHeaderSpriteTemplate, 0, 0, 1);
        menu->leftHeaderSprites[i] = &gSprites[spriteId];
        menu->leftHeaderSprites[i]->invisible = TRUE;
        menu->leftHeaderSprites[i]->x2 = i * 64;

        // Create submenu left header
        spriteId = CreateSprite(&sSubmenuLeftHeaderSpriteTemplate, 0, 0, 2);
        menu->submenuLeftHeaderSprites[i] = &gSprites[spriteId];
        menu->submenuLeftHeaderSprites[i]->invisible = TRUE;
        menu->submenuLeftHeaderSprites[i]->x2 = i * 32;
        menu->submenuLeftHeaderSprites[i]->y2 = 18;
        menu->submenuLeftHeaderSprites[i]->oam.tileNum += (i * 8) + 64;
    }
}

void LoadLeftHeaderGfxForIndex(u32 menuGfxId)
{
    if (menuGfxId < POKENAV_GFX_SUBMENUS_START)
        LoadLeftHeaderGfxForMenu(menuGfxId);
    else
        LoadLeftHeaderGfxForSubMenu(menuGfxId - POKENAV_GFX_SUBMENUS_START);
}

void UpdateRegionMapRightHeaderTiles(u32 menuGfxId)
{
    struct Pokenav_MainMenu *menu = GetSubstructPtr(POKENAV_SUBSTRUCT_MAIN_MENU);

    if (menuGfxId == POKENAV_GFX_MAP_MENU_ZOOMED_OUT)
        menu->leftHeaderSprites[1]->oam.tileNum = GetSpriteTileStartByTag(2) + 32;
    else
        menu->leftHeaderSprites[1]->oam.tileNum = GetSpriteTileStartByTag(2) + 64;
}

static void LoadLeftHeaderGfxForMenu(u32 menuGfxId)
{
    struct Pokenav_MainMenu *menu;
    u32 size, tag;

    if (menuGfxId >= POKENAV_GFX_SUBMENUS_START)
        return;

    menu = GetSubstructPtr(POKENAV_SUBSTRUCT_MAIN_MENU);
    tag = sMenuLeftHeaderSpriteSheets[menuGfxId].tag;
    size = GetDecompressedDataSize(sMenuLeftHeaderSpriteSheets[menuGfxId].data);
    LoadPalette(&gPokenavLeftHeader_Pal[tag * 16], (IndexOfSpritePaletteTag(1) * 16) + 0x100, 0x20);
    LZ77UnCompWram(sMenuLeftHeaderSpriteSheets[menuGfxId].data, gDecompressionBuffer);
    RequestDma3Copy(gDecompressionBuffer, (void *)OBJ_VRAM0 + (GetSpriteTileStartByTag(2) * 32), size, 1);
    menu->leftHeaderSprites[1]->oam.tileNum = GetSpriteTileStartByTag(2) + sMenuLeftHeaderSpriteSheets[menuGfxId].size;

    if (menuGfxId == POKENAV_GFX_MAP_MENU_ZOOMED_OUT || menuGfxId == POKENAV_GFX_MAP_MENU_ZOOMED_IN)
        menu->leftHeaderSprites[1]->x2 = 56;
    else
        menu->leftHeaderSprites[1]->x2 = 64;
}

static void LoadLeftHeaderGfxForSubMenu(u32 menuGfxId)
{
    u32 size, tag;

    if (menuGfxId >= POKENAV_GFX_MENUS_END - POKENAV_GFX_SUBMENUS_START)
        return;

    tag = sPokenavSubMenuLeftHeaderSpriteSheets[menuGfxId].tag;
    size = GetDecompressedDataSize(sPokenavSubMenuLeftHeaderSpriteSheets[menuGfxId].data);
    LoadPalette(&gPokenavLeftHeader_Pal[tag * 16], (IndexOfSpritePaletteTag(2) * 16) + 0x100, 0x20);
    LZ77UnCompWram(sPokenavSubMenuLeftHeaderSpriteSheets[menuGfxId].data, &gDecompressionBuffer[0x1000]);
    RequestDma3Copy(&gDecompressionBuffer[0x1000], (void *)OBJ_VRAM0 + 0x800 + (GetSpriteTileStartByTag(2) * 32), size, 1);
}

void ShowLeftHeaderGfx(u32 menuGfxId, bool32 isMain, bool32 isOnRightSide)
{
    u32 tileTop;

    if (!isMain)
        tileTop = 0x30;
    else
        tileTop = 0x10;

    if (menuGfxId < POKENAV_GFX_SUBMENUS_START)
        ShowLeftHeaderSprites(tileTop, isOnRightSide);
    else
        ShowLeftHeaderSubmenuSprites(tileTop, isOnRightSide);
}

void HideMainOrSubMenuLeftHeader(u32 id, bool32 onRightSide)
{
    if (id < POKENAV_GFX_PARTY_MENU)
        HideLeftHeaderSprites(onRightSide);
    else
        HideLeftHeaderSubmenuSprites(onRightSide);
}

void SetLeftHeaderSpritesInvisibility(void)
{
    s32 i;
    struct Pokenav_MainMenu *menu = GetSubstructPtr(POKENAV_SUBSTRUCT_MAIN_MENU);

    for (i = 0; i < (s32)ARRAY_COUNT(menu->leftHeaderSprites); i++)
    {
        menu->leftHeaderSprites[i]->invisible = TRUE;
        menu->submenuLeftHeaderSprites[i]->invisible = TRUE;
    }
}

bool32 AreLeftHeaderSpritesMoving(void)
{
    struct Pokenav_MainMenu *menu = GetSubstructPtr(POKENAV_SUBSTRUCT_MAIN_MENU);

    if (menu->leftHeaderSprites[0]->callback == SpriteCallbackDummy && menu->submenuLeftHeaderSprites[0]->callback == SpriteCallbackDummy)
        return FALSE;
    else
        return TRUE;
}

static void ShowLeftHeaderSprites(u32 startY, bool32 isOnRightSide)
{
    s32 start, end, i;
    struct Pokenav_MainMenu *menu = GetSubstructPtr(POKENAV_SUBSTRUCT_MAIN_MENU);

    if (!isOnRightSide)
        start = -96, end = 32;
    else
        start = 256, end = 160;

    for (i = 0; i < (s32)ARRAY_COUNT(menu->leftHeaderSprites); i++)
    {
        menu->leftHeaderSprites[i]->y = startY;
        MoveLeftHeader(menu->leftHeaderSprites[i], start, end, 12);
    }
}

static void ShowLeftHeaderSubmenuSprites(u32 startY, bool32 isOnRightSide)
{
    s32 start, end, i;
    struct Pokenav_MainMenu *menu = GetSubstructPtr(POKENAV_SUBSTRUCT_MAIN_MENU);

    if (!isOnRightSide)
        start = -96, end = 16;
    else
        start = 256, end = 192;

    for (i = 0; i < (s32)ARRAY_COUNT(menu->submenuLeftHeaderSprites); i++)
    {
        menu->submenuLeftHeaderSprites[i]->y = startY;
        MoveLeftHeader(menu->submenuLeftHeaderSprites[i], start, end, 12);
    }
}

static void HideLeftHeaderSprites(bool32 isOnRightSide)
{
    s32 start, end, i;
    struct Pokenav_MainMenu *menu = GetSubstructPtr(POKENAV_SUBSTRUCT_MAIN_MENU);

    if (!isOnRightSide)
        start = 32, end = -96;
    else
        start = 192, end = 256;

    for (i = 0; i < (s32)ARRAY_COUNT(menu->leftHeaderSprites); i++)
    {
        MoveLeftHeader(menu->leftHeaderSprites[i], start, end, 12);
    }
}

static void HideLeftHeaderSubmenuSprites(bool32 isOnRightSide)
{
    s32 start, end, i;
    struct Pokenav_MainMenu *menu = GetSubstructPtr(POKENAV_SUBSTRUCT_MAIN_MENU);

    if (!isOnRightSide)
        start = 16, end = -96;
    else
        start = 192, end = 256;

    for (i = 0; i < (s32)ARRAY_COUNT(menu->submenuLeftHeaderSprites); i++)
    {
        MoveLeftHeader(menu->submenuLeftHeaderSprites[i], start, end, 12);
    }
}

static void MoveLeftHeader(struct Sprite *sprite, s32 startX, s32 endX, s32 duration)
{
    sprite->x = startX;
    sprite->data[0] = startX * 16;
    sprite->data[1] = (endX - startX) * 16 / duration;
    sprite->data[2] = duration;
    sprite->data[7] = endX;
    sprite->callback = SpriteCB_MoveLeftHeader;
}

static void SpriteCB_MoveLeftHeader(struct Sprite *sprite)
{
    if (sprite->data[2] != 0)
    {
        sprite->data[2]--;
        sprite->data[0] += sprite->data[1];
        sprite->x = sprite->data[0] >> 4;
        if (sprite->x < -16 || sprite->x > 256)
            sprite->invisible = TRUE;
        else
            sprite->invisible = FALSE;
    }
    else
    {
        sprite->x = sprite->data[7];
        sprite->callback = SpriteCallbackDummy;
    }
}
