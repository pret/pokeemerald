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

struct PokenavMainMenuResources
{
    void (*unk0)(u32);
    u32 (*unk4)(void);
    u32 unk8;
    u32 currentTaskId;
    u32 helpBarWindowId;
    u32 palettes;
    struct Sprite *spinningPokenav;
    struct Sprite *leftHeaderSprites[2];
    struct Sprite *submenuLeftHeaderSprites[2];
    u8 tilemapBuffer[0x800];
};

// This struct uses a 32bit tag, and doesn't have a size field.
// Needed to match LoadLeftHeaderGfxForSubMenu.
struct CompressedSpriteSheetNoSize
{
    const u32 *data;  // LZ77 compressed palette data
    u32 tag;
};

static void CleanupPokenavMainMenuResources(void);
static void LoadLeftHeaderGfxForSubMenu(u32 arg0);
static void LoadLeftHeaderGfxForMenu(u32 index);
static void HideLeftHeaderSubmenuSprites(bool32 isOnRightSide);
static void HideLeftHeaderSprites(bool32 isOnRightSide);
static void ShowLeftHeaderSprites(u32 startY, bool32 isOnRightSide);
static void ShowLeftHeaderSubmenuSprites(u32 startY, bool32 isOnRightSide);
static void MoveLeftHeader(struct Sprite *sprite, s32 startX, s32 endX, s32 duration);
static void SpriteCB_MoveLeftHeader(struct Sprite *sprite);
static void InitPokenavMainMenuResources(void);
static void InitHoennMapHeaderSprites(void);
static void InitHelpBar(void);
static u32 LoopedTask_ScrollMenuHeaderDown(s32 a0);
static u32 LoopedTask_ScrollMenuHeaderUp(s32 a0);
static void DrawHelpBar(u32 windowId);
static void SpriteCB_SpinningPokenav(struct Sprite* sprite);
static u32 LoopedTask_InitPokenavMenu(s32 a0);

const u16 gSpinningPokenavPaletteData[] = INCBIN_U16("graphics/pokenav/icon2.gbapal");
const u32 gSpinningPokenavGfx[] = INCBIN_U32("graphics/pokenav/icon2.4bpp.lz");
const u32 gUnused_SpinningPokenavGfx2[] = INCBIN_U32("graphics/pokenav/icon2_unused.4bpp.lz");

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
    TEXT_COLOR_RED, TEXT_COLOR_WHITE, TEXT_COLOR_DARK_GREY
};

static const struct CompressedSpriteSheet gSpinningPokenavSpriteSheet[] =
{
    {
        .data = gSpinningPokenavGfx,
        .size = 0x1000,
        .tag = 0,
    }
};

static const struct SpritePalette gSpinningNavgearPalettes[] =
{
    {
        .data = gSpinningPokenavPaletteData,
        .tag = 0,
    },
    {}
};

static const struct CompressedSpriteSheet sPokenavHoennMapLeftHeaderSpriteSheet =
{
    .data = gPokenavLeftHeaderHoennMap_Gfx,
    .size = 0xC00,
    .tag = 2
};

static const struct CompressedSpriteSheet sPokenavMenuLeftHeaderSpriteSheets[] =
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

static const struct OamData sPokenavLeftHeaderHoennMapSpriteOam =
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

static const struct OamData sUnknown_0861FB24 =
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

static const struct SpriteTemplate sPokenavLeftHeaderHoennMapSpriteTemplate =
{
    .tileTag = 2,
    .paletteTag = 1,
    .oam = &sPokenavLeftHeaderHoennMapSpriteOam,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate sUnknown_0861FB44 =
{
    .tileTag = 2,
    .paletteTag = 2,
    .oam = &sUnknown_0861FB24,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

bool32 InitPokenavMainMenu(void)
{
    struct PokenavMainMenuResources *structPtr;
    
    structPtr = AllocSubstruct(0, sizeof(struct PokenavMainMenuResources));
    if (structPtr == NULL)
        return FALSE;

    ResetSpriteData();
    FreeAllSpritePalettes();
    structPtr->currentTaskId = CreateLoopedTask(LoopedTask_InitPokenavMenu, 1);
    return TRUE;
}

u32 PokenavMainMenuLoopedTaskIsActive(void)
{
    struct PokenavMainMenuResources *structPtr = GetSubstructPtr(0);
    return IsLoopedTaskActive(structPtr->currentTaskId);
}

void ShutdownPokenav(void)
{
    PlaySE(SE_PN_OFF);
    sub_81CAADC();
    BeginNormalPaletteFade(0xFFFFFFFF, -1, 0, 16, RGB_BLACK);
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

static u32 LoopedTask_InitPokenavMenu(s32 a0)
{
    struct PokenavMainMenuResources *structPtr;

    switch (a0)
    {
    case 0:
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
        FreeAllWindowBuffers();
        ResetBgsAndClearDma3BusyFlags(0);
        InitBgsFromTemplates(0, gPokenavMainMenuBgTemplates, ARRAY_COUNT(gPokenavMainMenuBgTemplates));
        ResetBgPositions();
        reset_temp_tile_data_buffers();
        return LT_INC_AND_CONTINUE;
    case 1:
        structPtr = GetSubstructPtr(0);
        decompress_and_copy_tile_data_to_vram(0, &gPokenavHeader_Gfx, 0, 0, 0);
        SetBgTilemapBuffer(0, structPtr->tilemapBuffer);
        CopyToBgTilemapBuffer(0, &gPokenavHeader_Tilemap, 0, 0);
        CopyPaletteIntoBufferUnfaded(gPokenavHeader_Pal, 0, 0x20);
        CopyBgTilemapBufferToVram(0);
        return LT_INC_AND_PAUSE;
    case 2:
        if (free_temp_tile_data_buffers_if_possible())
            return LT_PAUSE;

        InitHelpBar();
        return LT_INC_AND_PAUSE;
    case 3:
        if (IsDma3ManagerBusyWithBgCopy())
            return LT_PAUSE;

        InitPokenavMainMenuResources();
        InitHoennMapHeaderSprites();
        ShowBg(0);
        return LT_FINISH;
    default:
        return LT_FINISH;
    }
}

void sub_81C7834(void *func1, void *func2) // Fix types later.
{
    struct PokenavMainMenuResources *structPtr = GetSubstructPtr(0);
    structPtr->unk0 = func1;
    structPtr->unk4 = func2;
    structPtr->unk8 = 0;
}

void sub_81C7850(u32 a0)
{
    struct PokenavMainMenuResources *structPtr = GetSubstructPtr(0);
    structPtr->unk8 = 0;
    structPtr->unk0(a0);
}

u32 sub_81C786C(void)
{
    struct PokenavMainMenuResources *structPtr = GetSubstructPtr(0);
    return structPtr->unk4();
}

void sub_81C7880(void)
{
    struct PokenavMainMenuResources *structPtr = GetSubstructPtr(0);
    structPtr->currentTaskId = CreateLoopedTask(LoopedTask_ScrollMenuHeaderDown, 4);
}

void sub_81C78A0(void)
{
    struct PokenavMainMenuResources *structPtr = GetSubstructPtr(0);
    structPtr->currentTaskId = CreateLoopedTask(LoopedTask_ScrollMenuHeaderUp, 4);
}

bool32 MainMenuLoopedTaskIsBusy(void)
{
    struct PokenavMainMenuResources *structPtr = GetSubstructPtr(0);
    return IsLoopedTaskActive(structPtr->currentTaskId);
}

static u32 LoopedTask_ScrollMenuHeaderDown(s32 a0)
{
    switch (a0)
    {
    default:
        return LT_FINISH;
    case 1:
        return LT_INC_AND_PAUSE;
    case 0:
        return LT_INC_AND_PAUSE;
    case 2:
        if (ChangeBgY(0, 384, 1) >= 0x2000u)
        {
            ChangeBgY(0, 0x2000, 0);
            return LT_FINISH;
        }

        return LT_PAUSE;
    }
}

static u32 LoopedTask_ScrollMenuHeaderUp(s32 a0)
{
    if (ChangeBgY(0, 384, 2) <= 0)
    {
        ChangeBgY(0, 0, 0);
        return 4;
    }
    return 2;
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

void sub_81C7990(u32 a0, u16 a1)
{
    CpuFill16(a1, gPlttBufferFaded + 0x100 + (a0 * 16), 16 * sizeof(u16));
}

NAKED
void sub_81C79BC(const u16 *a0, const u16 *a1, u32 a2, u32 a3, u32 a4, u16 *a5)
{
    asm(".syntax unified\n\
    push {r4-r7,lr}\n\
    mov r7, r10\n\
    mov r6, r9\n\
    mov r5, r8\n\
    push {r5-r7}\n\
    sub sp, 0xC\n\
    str r0, [sp]\n\
    str r1, [sp, 0x4]\n\
    mov r10, r2\n\
    str r3, [sp, 0x8]\n\
    ldr r0, [sp, 0x2C]\n\
    cmp r0, 0\n\
    bne _081C79E4\n\
    ldr r2, =0x001fffff\n\
    mov r1, r10\n\
    ands r2, r1\n\
    ldr r0, [sp]\n\
    b _081C79F4\n\
    .pool\n\
_081C79E4:\n\
    ldr r2, [sp, 0x2C]\n\
    ldr r0, [sp, 0x8]\n\
    cmp r2, r0\n\
    blt _081C7A00\n\
    ldr r2, =0x001fffff\n\
    mov r1, r10\n\
    ands r2, r1\n\
    ldr r0, [sp, 0x4]\n\
_081C79F4:\n\
    ldr r1, [sp, 0x30]\n\
    bl CpuSet\n\
    b _081C7AAE\n\
    .pool\n\
_081C7A00:\n\
    movs r2, 0x1\n\
    negs r2, r2\n\
    add r10, r2\n\
    b _081C7AA6\n\
_081C7A08:\n\
    ldr r1, [sp]\n\
    ldrh r0, [r1]\n\
    movs r2, 0x1F\n\
    mov r9, r2\n\
    mov r1, r9\n\
    ands r1, r0\n\
    mov r9, r1\n\
    lsls r0, 16\n\
    lsrs r2, r0, 21\n\
    movs r1, 0x1F\n\
    ands r1, r2\n\
    mov r8, r1\n\
    lsrs r7, r0, 26\n\
    movs r2, 0x1F\n\
    ands r7, r2\n\
    ldr r0, [sp, 0x4]\n\
    ldrh r4, [r0]\n\
    movs r0, 0x1F\n\
    ands r0, r4\n\
    mov r1, r9\n\
    subs r0, r1\n\
    lsls r0, 8\n\
    ldr r1, [sp, 0x8]\n\
    bl __divsi3\n\
    ldr r2, [sp, 0x2C]\n\
    adds r6, r0, 0\n\
    muls r6, r2\n\
    asrs r6, 8\n\
    lsls r4, 16\n\
    lsrs r0, r4, 21\n\
    movs r1, 0x1F\n\
    ands r0, r1\n\
    mov r2, r8\n\
    subs r0, r2\n\
    lsls r0, 8\n\
    ldr r1, [sp, 0x8]\n\
    bl __divsi3\n\
    ldr r1, [sp, 0x2C]\n\
    adds r5, r0, 0\n\
    muls r5, r1\n\
    asrs r5, 8\n\
    lsrs r4, 26\n\
    movs r2, 0x1F\n\
    ands r4, r2\n\
    subs r4, r7\n\
    lsls r4, 8\n\
    adds r0, r4, 0\n\
    ldr r1, [sp, 0x8]\n\
    bl __divsi3\n\
    ldr r1, [sp, 0x2C]\n\
    muls r0, r1\n\
    asrs r0, 8\n\
    add r6, r9\n\
    movs r2, 0x1F\n\
    ands r6, r2\n\
    add r5, r8\n\
    ands r5, r2\n\
    adds r0, r7, r0\n\
    ands r0, r2\n\
    lsls r0, 10\n\
    lsls r5, 5\n\
    orrs r0, r5\n\
    orrs r0, r6\n\
    ldr r1, [sp, 0x30]\n\
    strh r0, [r1]\n\
    ldr r2, [sp]\n\
    adds r2, 0x2\n\
    str r2, [sp]\n\
    ldr r0, [sp, 0x4]\n\
    adds r0, 0x2\n\
    str r0, [sp, 0x4]\n\
    adds r1, 0x2\n\
    str r1, [sp, 0x30]\n\
    movs r1, 0x1\n\
    negs r1, r1\n\
    add r10, r1\n\
_081C7AA6:\n\
    movs r0, 0x1\n\
    negs r0, r0\n\
    cmp r10, r0\n\
    bne _081C7A08\n\
_081C7AAE:\n\
    add sp, 0xC\n\
    pop {r3-r5}\n\
    mov r8, r3\n\
    mov r9, r4\n\
    mov r10, r5\n\
    pop {r4-r7}\n\
    pop {r0}\n\
    bx r0\n\
    .syntax divided");
}

void PokenavFadeScreen(s32 fadeType)
{
    struct PokenavMainMenuResources *structPtr = GetSubstructPtr(0);

    switch (fadeType)
    {
    case 0:
        BeginNormalPaletteFade(structPtr->palettes, -2, 0, 16, RGB_BLACK);
        break;
    case 1:
        BeginNormalPaletteFade(structPtr->palettes, -2, 16, 0, RGB_BLACK);
        break;
    case 2:
        BeginNormalPaletteFade(0xFFFFFFFF, -2, 0, 16, RGB_BLACK);
        break;
    case 3:
        BeginNormalPaletteFade(0xFFFFFFFF, -2, 16, 0, RGB_BLACK);
        break;
    }
}

bool32 IsPaletteFadeActive(void)
{
    return gPaletteFade.active;
}

void sub_81C7B40(void)
{
    BlendPalettes(0xFFFEFFFE, 16, RGB_BLACK);
}

void InitBgTemplates(const struct BgTemplate *templates, int count)
{
    int i;

    for (i = 0; i < count; i++)
        InitBgFromTemplate(templates++);
}

static void InitHelpBar(void)
{
    struct PokenavMainMenuResources *structPtr = GetSubstructPtr(0);

    InitWindows(&sHelpBarWindowTemplate[0]);
    structPtr->helpBarWindowId = 0;
    DrawHelpBar(structPtr->helpBarWindowId);
    PutWindowTilemap(structPtr->helpBarWindowId);
    CopyWindowToVram(structPtr->helpBarWindowId, 3); // TODO: Use a defined constant here.
}

void PrintHelpBarText(u32 textId)
{
    struct PokenavMainMenuResources *structPtr = GetSubstructPtr(0);

    DrawHelpBar(structPtr->helpBarWindowId);
    AddTextPrinterParameterized3(structPtr->helpBarWindowId, 1, 0, 1, sHelpBarTextColors, 0, sHelpBarTexts[textId]);
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
    struct PokenavMainMenuResources *structPtr = GetSubstructPtr(0);

    for (i = 0; i < ARRAY_COUNT(gSpinningPokenavSpriteSheet); i++)
        LoadCompressedSpriteSheet(&gSpinningPokenavSpriteSheet[i]);

    Pokenav_AllocAndLoadPalettes(gSpinningNavgearPalettes);
    structPtr->palettes = ~1 & ~(0x10000 << IndexOfSpritePaletteTag(0));
    spriteId = CreateSprite(&sSpinningPokenavSpriteTemplate, 220, 12, 0);
    structPtr->spinningPokenav = &gSprites[spriteId];
}

static void CleanupPokenavMainMenuResources(void)
{
    struct PokenavMainMenuResources *structPtr = GetSubstructPtr(0);

    DestroySprite(structPtr->spinningPokenav);
    FreeSpriteTilesByTag(0);
    FreeSpritePaletteByTag(0);
}

static void SpriteCB_SpinningPokenav(struct Sprite *sprite)
{
    // If the background starts scrolling, follow it.
    sprite->pos2.y = (GetBgY(0) / 256u) * -1;
}

struct Sprite *PauseSpinningPokenavSprite(void)
{
    struct PokenavMainMenuResources *structPtr = GetSubstructPtr(0);

    structPtr->spinningPokenav->callback = SpriteCallbackDummy;
    return structPtr->spinningPokenav;
}

void ResumeSpinningPokenavSprite(void)
{
    struct PokenavMainMenuResources *structPtr = GetSubstructPtr(0);

    structPtr->spinningPokenav->pos1.x = 220;
    structPtr->spinningPokenav->pos1.y = 12;
    structPtr->spinningPokenav->callback = SpriteCB_SpinningPokenav;
    structPtr->spinningPokenav->invisible = FALSE;
    structPtr->spinningPokenav->oam.priority = 0;
    structPtr->spinningPokenav->subpriority = 0;
}

static void InitHoennMapHeaderSprites(void)
{
    s32 i, spriteId;
    struct PokenavMainMenuResources *structPtr = GetSubstructPtr(0);

    LoadCompressedSpriteSheet(&sPokenavHoennMapLeftHeaderSpriteSheet);
    AllocSpritePalette(1);
    AllocSpritePalette(2);
    for (i = 0; i < (s32)ARRAY_COUNT(structPtr->leftHeaderSprites); i++)
    {
        spriteId = CreateSprite(&sPokenavLeftHeaderHoennMapSpriteTemplate, 0, 0, 1);
        structPtr->leftHeaderSprites[i] = &gSprites[spriteId];
        structPtr->leftHeaderSprites[i]->invisible = TRUE;
        structPtr->leftHeaderSprites[i]->pos2.x = i * 64;

        spriteId = CreateSprite(&sUnknown_0861FB44, 0, 0, 2);
        structPtr->submenuLeftHeaderSprites[i] = &gSprites[spriteId];
        structPtr->submenuLeftHeaderSprites[i]->invisible = TRUE;
        structPtr->submenuLeftHeaderSprites[i]->pos2.x = i * 32;
        structPtr->submenuLeftHeaderSprites[i]->pos2.y = 18;
        structPtr->submenuLeftHeaderSprites[i]->oam.tileNum += (i * 8) + 64;
    }
}

void LoadLeftHeaderGfxForIndex(u32 menuGfxId)
{
    if (menuGfxId < POKENAV_GFX_SUBMENUS_START)
        LoadLeftHeaderGfxForMenu(menuGfxId);
    else
        LoadLeftHeaderGfxForSubMenu(menuGfxId - POKENAV_GFX_SUBMENUS_START);
}

void sub_81C7E14(u32 menuGfxId)
{
    struct PokenavMainMenuResources *structPtr = GetSubstructPtr(0);

    if (menuGfxId == POKENAV_GFX_MAP_MENU_ZOOMED_OUT)
        structPtr->leftHeaderSprites[1]->oam.tileNum = GetSpriteTileStartByTag(2) + 32;
    else
        structPtr->leftHeaderSprites[1]->oam.tileNum = GetSpriteTileStartByTag(2) + 64;
}

static void LoadLeftHeaderGfxForMenu(u32 menuGfxId)
{
    struct PokenavMainMenuResources *structPtr;
    u32 size, tag;

    if (menuGfxId >= POKENAV_GFX_SUBMENUS_START)
        return;

    structPtr = GetSubstructPtr(0);
    tag = sPokenavMenuLeftHeaderSpriteSheets[menuGfxId].tag;
    size = GetDecompressedDataSize(sPokenavMenuLeftHeaderSpriteSheets[menuGfxId].data);
    LoadPalette(&gPokenavLeftHeader_Pal[tag * 16], (IndexOfSpritePaletteTag(1) * 16) + 0x100, 0x20);
    LZ77UnCompWram(sPokenavMenuLeftHeaderSpriteSheets[menuGfxId].data, gDecompressionBuffer);
    RequestDma3Copy(gDecompressionBuffer, (void *)VRAM + 0x10000 + (GetSpriteTileStartByTag(2) * 32), size, 1);
    structPtr->leftHeaderSprites[1]->oam.tileNum = GetSpriteTileStartByTag(2) + sPokenavMenuLeftHeaderSpriteSheets[menuGfxId].size;

    if (menuGfxId == POKENAV_GFX_MAP_MENU_ZOOMED_OUT || menuGfxId == POKENAV_GFX_MAP_MENU_ZOOMED_IN)
        structPtr->leftHeaderSprites[1]->pos2.x = 56;
    else
        structPtr->leftHeaderSprites[1]->pos2.x = 64;
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
    RequestDma3Copy(&gDecompressionBuffer[0x1000], (void *)VRAM + 0x10800 + (GetSpriteTileStartByTag(2) * 32), size, 1);
}

void sub_81C7FA0(u32 menuGfxId, bool32 arg1, bool32 arg2)
{
    u32 var;

    if (!arg1)
        var = 0x30;
    else
        var = 0x10;

    if (menuGfxId < POKENAV_GFX_SUBMENUS_START)
        ShowLeftHeaderSprites(var, arg2);
    else
        ShowLeftHeaderSubmenuSprites(var, arg2);
}

void sub_81C7FC4(u32 arg0, bool32 arg1)
{
    if (arg0 < 6)
        HideLeftHeaderSprites(arg1);
    else
        HideLeftHeaderSubmenuSprites(arg1);
}

void sub_81C7FDC(void)
{
    s32 i;
    struct PokenavMainMenuResources *structPtr = GetSubstructPtr(0);

    for (i = 0; i < (s32)ARRAY_COUNT(structPtr->leftHeaderSprites); i++)
    {
        structPtr->leftHeaderSprites[i]->invisible = TRUE;
        structPtr->submenuLeftHeaderSprites[i]->invisible = TRUE;
    }
}

bool32 sub_81C8010(void)
{
    struct PokenavMainMenuResources *structPtr = GetSubstructPtr(0);

    if (structPtr->leftHeaderSprites[0]->callback == SpriteCallbackDummy && structPtr->submenuLeftHeaderSprites[0]->callback == SpriteCallbackDummy)
        return FALSE;
    else
        return TRUE;
}

static void ShowLeftHeaderSprites(u32 startY, bool32 isOnRightSide)
{
    s32 start, end, i;
    struct PokenavMainMenuResources *structPtr = GetSubstructPtr(0);

    if (!isOnRightSide)
        start = -96, end = 32;
    else
        start = 256, end = 160;

    for (i = 0; i < (s32)ARRAY_COUNT(structPtr->leftHeaderSprites); i++)
    {
        structPtr->leftHeaderSprites[i]->pos1.y = startY;
        MoveLeftHeader(structPtr->leftHeaderSprites[i], start, end, 12);
    }
}

static void ShowLeftHeaderSubmenuSprites(u32 startY, bool32 isOnRightSide)
{
    s32 start, end, i;
    struct PokenavMainMenuResources *structPtr = GetSubstructPtr(0);

    if (!isOnRightSide)
        start = -96, end = 16;
    else
        start = 256, end = 192;

    for (i = 0; i < (s32)ARRAY_COUNT(structPtr->submenuLeftHeaderSprites); i++)
    {
        structPtr->submenuLeftHeaderSprites[i]->pos1.y = startY;
        MoveLeftHeader(structPtr->submenuLeftHeaderSprites[i], start, end, 12);
    }
}

static void HideLeftHeaderSprites(bool32 isOnRightSide)
{
    s32 start, end, i;
    struct PokenavMainMenuResources *structPtr = GetSubstructPtr(0);

    if (!isOnRightSide)
        start = 32, end = -96;
    else
        start = 192, end = 256;

    for (i = 0; i < (s32)ARRAY_COUNT(structPtr->leftHeaderSprites); i++)
    {
        MoveLeftHeader(structPtr->leftHeaderSprites[i], start, end, 12);
    }
}

static void HideLeftHeaderSubmenuSprites(bool32 isOnRightSide)
{
    s32 start, end, i;
    struct PokenavMainMenuResources *structPtr = GetSubstructPtr(0);

    if (!isOnRightSide)
        start = 16, end = -96;
    else
        start = 192, end = 256;

    for (i = 0; i < (s32)ARRAY_COUNT(structPtr->submenuLeftHeaderSprites); i++)
    {
        MoveLeftHeader(structPtr->submenuLeftHeaderSprites[i], start, end, 12);
    }
}

static void MoveLeftHeader(struct Sprite *sprite, s32 startX, s32 endX, s32 duration)
{
    sprite->pos1.x = startX;
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
        sprite->pos1.x = sprite->data[0] >> 4;
        if (sprite->pos1.x < -16 || sprite->pos1.x > 256)
            sprite->invisible = TRUE;
        else
            sprite->invisible = FALSE;
    }
    else
    {
        sprite->pos1.x = sprite->data[7];
        sprite->callback = SpriteCallbackDummy;
    }
}
