#include "global.h"
#include "malloc.h"
#include "battle.h"
#include "battle_gfx_sfx_util.h"
#include "bg.h"
#include "contest.h"
#include "contest_painting.h"
#include "data.h"
#include "decompress.h"
#include "gpu_regs.h"
#include "image_processing_effects.h"
#include "international_string_util.h"
#include "main.h"
#include "lilycove_lady.h"
#include "palette.h"
#include "random.h"
#include "scanline_effect.h"
#include "string_util.h"
#include "strings.h"
#include "text.h"
#include "window.h"
#include "constants/rgb.h"

// IWRAM common
u16 (*gContestMonPixels)[][32];
struct ImageProcessingContext gImageProcessingContext;
struct ContestWinner *gContestPaintingWinner;
u16 *gContestPaintingMonPalette;

// IWRAM bss
static u8 gContestPaintingState;
static u16 gContestPaintingMosaicVal;
static u16 gContestPaintingFadeCounter;
static bool8 gUnknown_030011F6;
static u8 gContestPaintingWindowId;

static void ShowContestPainting(void);
static void HoldContestPainting(void);
static void InitContestPaintingWindow(void);
static void InitContestPaintingBg(void);
static void InitContestPaintingVars(bool8);
static void CreateContestPaintingPicture(u8, u8);
static void PrintContestPaintingCaption(u8, u8);
static void VBlankCB_ContestPainting(void);
static void _InitContestMonPixels(u8 *spriteGfx, u16 *palette, u16 (*destPixels)[64][64]);

extern const u8 gUnknown_0827EA0C[];
extern const u8 gContestCoolness[];
extern const u8 gContestBeauty[];
extern const u8 gContestCuteness[];
extern const u8 gContestSmartness[];
extern const u8 gContestToughness[];
extern const u8 gContestRankNormal[];
extern const u8 gContestRankSuper[];
extern const u8 gContestRankHyper[];
extern const u8 gContestRankMaster[];
extern const u8 gContestLink[];
extern const u8 gContestPaintingCool1[];
extern const u8 gContestPaintingCool2[];
extern const u8 gContestPaintingCool3[];
extern const u8 gContestPaintingBeauty1[];
extern const u8 gContestPaintingBeauty2[];
extern const u8 gContestPaintingBeauty3[];
extern const u8 gContestPaintingCute1[];
extern const u8 gContestPaintingCute2[];
extern const u8 gContestPaintingCute3[];
extern const u8 gContestPaintingSmart1[];
extern const u8 gContestPaintingSmart2[];
extern const u8 gContestPaintingSmart3[];
extern const u8 gContestPaintingTough1[];
extern const u8 gContestPaintingTough2[];
extern const u8 gContestPaintingTough3[];

const u16 gPictureFramePalettes[] = INCBIN_U16("graphics/picture_frame/bg.gbapal");
const u8 gPictureFrameTiles_0[] = INCBIN_U8("graphics/picture_frame/frame0.4bpp.rl");
const u8 gPictureFrameTiles_1[] = INCBIN_U8("graphics/picture_frame/frame1.4bpp.rl");
const u8 gPictureFrameTiles_2[] = INCBIN_U8("graphics/picture_frame/frame2.4bpp.rl");
const u8 gPictureFrameTiles_3[] = INCBIN_U8("graphics/picture_frame/frame3.4bpp.rl");
const u8 gPictureFrameTiles_4[] = INCBIN_U8("graphics/picture_frame/frame4.4bpp.rl");
const u8 gPictureFrameTiles_5[] = INCBIN_U8("graphics/picture_frame/frame5.4bpp.rl");
const u8 gPictureFrameTilemap_0[] = INCBIN_U8("graphics/picture_frame/frame0_map.bin.rl");
const u8 gPictureFrameTilemap_1[] = INCBIN_U8("graphics/picture_frame/frame1_map.bin.rl");
const u8 gPictureFrameTilemap_2[] = INCBIN_U8("graphics/picture_frame/frame2_map.bin.rl");
const u8 gPictureFrameTilemap_3[] = INCBIN_U8("graphics/picture_frame/frame3_map.bin.rl");
const u8 gPictureFrameTilemap_4[] = INCBIN_U8("graphics/picture_frame/frame4_map.bin.rl");
const u8 gPictureFrameTilemap_5[] = INCBIN_U8("graphics/picture_frame/frame5_map.bin.rl");

static const u8 *const sContestCategoryNames_Unused[] =
{
    gContestCoolness,
    gContestBeauty,
    gContestCuteness,
    gContestSmartness,
    gContestToughness,
};

static const u8 *const sContestRankNames[] =
{
    gContestRankNormal,
    gContestRankSuper,
    gContestRankHyper,
    gContestRankMaster,
    gContestLink,
};

static const struct BgTemplate sContestPaintingBgTemplates[] =
{
    {
        .bg = 1,
        .charBaseIndex = 1,
        .mapBaseIndex = 10,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0,
    },
};

static const struct WindowTemplate sContestPaintingWindowTemplate =
{
    .bg = 1,
    .tilemapLeft = 2,
    .tilemapTop = 14,
    .width = 26,
    .height = 4,
    .paletteNum = 15,
    .baseBlock = 1,
};

static const u8 *const sContestPaintingDescriptionPointers[] =
{
    gContestPaintingCool1,
    gContestPaintingCool2,
    gContestPaintingCool3,
    gContestPaintingBeauty1,
    gContestPaintingBeauty2,
    gContestPaintingBeauty3,
    gContestPaintingCute1,
    gContestPaintingCute2,
    gContestPaintingCute3,
    gContestPaintingSmart1,
    gContestPaintingSmart2,
    gContestPaintingSmart3,
    gContestPaintingTough1,
    gContestPaintingTough2,
    gContestPaintingTough3,
};

static const struct OamData sContestPaintingMonOamData =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = TRUE,
    .bpp = ST_OAM_8BPP,
    .shape = SPRITE_SHAPE(64x64),
    .x = 0,
    .size = SPRITE_SIZE(64x64),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
};

const u16 gUnknown_085B0838[] = {RGB(0, 0, 0), RGB(0, 0, 0)};

void SetContestWinnerForPainting(int contestWinnerId)
{
    // probably fakematching
    u8 *ptr1 = &gUnknown_02039F5D;
    u8 *ptr2 = &gUnknown_02039F5C;
	gCurContestWinner = gSaveBlock1Ptr->contestWinners[contestWinnerId - 1];
	*ptr1 = contestWinnerId - 1;
	*ptr2 = FALSE;
}

void CB2_ContestPainting(void)
{
    ShowContestPainting();
}

static void CB2_HoldContestPainting(void)
{
    HoldContestPainting();
    RunTextPrinters();
    UpdatePaletteFade();
}

static void CB2_QuitContestPainting(void)
{
    SetMainCallback2(gMain.savedCallback);
    FREE_AND_SET_NULL(gContestPaintingMonPalette);
    FREE_AND_SET_NULL(gContestMonPixels);
    RemoveWindow(gContestPaintingWindowId);
    Free(GetBgTilemapBuffer(1));
    FreeMonSpritesGfx();
}

static void ShowContestPainting(void)
{
    switch (gMain.state)
    {
    case 0:
        ScanlineEffect_Stop();
        SetVBlankCallback(NULL);
        AllocateMonSpritesGfx();
        gContestPaintingWinner = &gCurContestWinner;
        InitContestPaintingVars(1);
        InitContestPaintingBg();
        gMain.state++;
        break;
    case 1:
        ResetPaletteFade();
        DmaFillLarge32(3, 0, (void *)BG_VRAM, 0x18000, 0x1000);
        ResetSpriteData();
        gMain.state++;
        break;
    case 2:
        SeedRng(gMain.vblankCounter1);
        InitKeys();
        InitContestPaintingWindow();
        gMain.state++;
        break;
    case 3:
        CreateContestPaintingPicture(gUnknown_02039F5D, gUnknown_02039F5C);
        gMain.state++;
        break;
    case 4:
        PrintContestPaintingCaption(gUnknown_02039F5D, gUnknown_02039F5C);
        LoadPalette(gUnknown_085B0838, 0, 1 * 2);
        DmaClear32(3, PLTT, PLTT_SIZE);
        BeginFastPaletteFade(2);
        SetVBlankCallback(VBlankCB_ContestPainting);
        gContestPaintingState = 0;
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0 | DISPCNT_OBJ_1D_MAP | DISPCNT_BG0_ON | DISPCNT_BG1_ON | DISPCNT_OBJ_ON);
        SetMainCallback2(CB2_HoldContestPainting);
        break;
    }
}

static void HoldContestPainting(void)
{
    switch (gContestPaintingState)
    {
    case 0:
        if (!gPaletteFade.active)
            gContestPaintingState = 1;
        if (gUnknown_030011F6 && gContestPaintingFadeCounter)
            gContestPaintingFadeCounter--;
        break;
    case 1:
        if ((JOY_NEW(A_BUTTON)) || (JOY_NEW(B_BUTTON)))
        {
            gContestPaintingState++;
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB(0, 0, 0));
        }

        if (gUnknown_030011F6)
            gContestPaintingFadeCounter = 0;
        break;
    case 2:
        if (!gPaletteFade.active)
            SetMainCallback2(CB2_QuitContestPainting);
        if (gUnknown_030011F6 && gContestPaintingFadeCounter < 30)
            gContestPaintingFadeCounter++;
        break;
    }
}

static void InitContestPaintingWindow(void)
{
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, sContestPaintingBgTemplates, ARRAY_COUNT(sContestPaintingBgTemplates));
    ChangeBgX(1, 0, 0);
    ChangeBgY(1, 0, 0);
    SetBgTilemapBuffer(1, AllocZeroed(BG_SCREEN_SIZE));
    gContestPaintingWindowId = AddWindow(&sContestPaintingWindowTemplate);
    DeactivateAllTextPrinters();
    FillWindowPixelBuffer(gContestPaintingWindowId, PIXEL_FILL(0));
    PutWindowTilemap(gContestPaintingWindowId);
    CopyWindowToVram(gContestPaintingWindowId, 3);
    ShowBg(1);
}

static void PrintContestPaintingCaption(u8 contestType, bool8 arg1)
{
    int x;
    u8 category;

    if (arg1 == TRUE)
        return;

    category = gContestPaintingWinner->contestCategory;
    if (contestType < 8)
    {
        BufferContestName(gStringVar1, category);
        StringAppend(gStringVar1, gText_Space);
        StringAppend(gStringVar1, sContestRankNames[gContestPaintingWinner->contestRank]);
        StringCopy(gStringVar2, gContestPaintingWinner->trainerName);
        sub_81DB5AC(gStringVar2);
        StringCopy(gStringVar3, gContestPaintingWinner->monName);
        StringExpandPlaceholders(gStringVar4, gUnknown_0827EA0C);
    }
    else
    {
        StringCopy(gStringVar1, gContestPaintingWinner->monName);
        StringExpandPlaceholders(gStringVar4, sContestPaintingDescriptionPointers[category]);
    }

    x = GetStringCenterAlignXOffset(1, gStringVar4, 208);
    AddTextPrinterParameterized(gContestPaintingWindowId, 1, gStringVar4, x, 1, 0, 0);
    CopyBgTilemapBufferToVram(1);
}

static void InitContestPaintingBg(void)
{
    SetGpuReg(REG_OFFSET_DISPCNT, 0);
    REG_IE |= INTR_FLAG_VBLANK;
    SetGpuReg(REG_OFFSET_BG0CNT, BGCNT_PRIORITY(2) | BGCNT_CHARBASE(0) | BGCNT_SCREENBASE(12) | BGCNT_MOSAIC | BGCNT_16COLOR | BGCNT_TXT256x256);
    SetGpuReg(REG_OFFSET_BG1CNT, BGCNT_PRIORITY(1) | BGCNT_CHARBASE(1) | BGCNT_SCREENBASE(10) | BGCNT_MOSAIC | BGCNT_16COLOR | BGCNT_TXT256x256);
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
    SetGpuReg(REG_OFFSET_BLDALPHA, 0);
    SetGpuReg(REG_OFFSET_BLDY, 0);
}

static void InitContestPaintingVars(bool8 arg0)
{
    if (arg0 == FALSE)
    {
        gUnknown_030011F6 = FALSE;
        gContestPaintingMosaicVal = 0;
        gContestPaintingFadeCounter = 0;
    }
    else
    {
        gUnknown_030011F6 = TRUE;
        gContestPaintingMosaicVal = 15;
        gContestPaintingFadeCounter = 30;
    }
}

static void UpdateContestPaintingMosaicEffect(void)
{
    if (!gUnknown_030011F6)
    {
        SetGpuReg(REG_OFFSET_MOSAIC, 0);
    }
    else
    {
        SetGpuReg(REG_OFFSET_BG1CNT, BGCNT_PRIORITY(1) | BGCNT_CHARBASE(1) | BGCNT_SCREENBASE(10) | BGCNT_MOSAIC | BGCNT_16COLOR | BGCNT_TXT256x256);
        gContestPaintingMosaicVal = gContestPaintingFadeCounter / 2;
        SetGpuReg(REG_OFFSET_MOSAIC, (gContestPaintingMosaicVal << 12) | (gContestPaintingMosaicVal << 8) | (gContestPaintingMosaicVal << 4) | (gContestPaintingMosaicVal << 0));
    }
}

static void VBlankCB_ContestPainting(void)
{
    UpdateContestPaintingMosaicEffect();
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static void InitContestMonPixels(u16 species, u8 whichSprite)
{
    const void *pal = GetMonSpritePalFromSpeciesAndPersonality(species, gContestPaintingWinner->trainerId, gContestPaintingWinner->personality);
    LZDecompressVram(pal, gContestPaintingMonPalette);
    if (whichSprite == 0)
    {
        HandleLoadSpecialPokePic_DontHandleDeoxys(
            &gMonFrontPicTable[species],
            gMonSpritesGfxPtr->sprites.ptr[1],
            species,
            gContestPaintingWinner->personality);
        _InitContestMonPixels(gMonSpritesGfxPtr->sprites.ptr[1], gContestPaintingMonPalette, (void *)gContestMonPixels);
    }
    else
    {
        HandleLoadSpecialPokePic_DontHandleDeoxys(
            &gMonBackPicTable[species],
            gMonSpritesGfxPtr->sprites.ptr[0],
            species,
            gContestPaintingWinner->personality);
        _InitContestMonPixels(gMonSpritesGfxPtr->sprites.ptr[0], gContestPaintingMonPalette, (void *)gContestMonPixels);
    }
}

static void _InitContestMonPixels(u8 *spriteGfx, u16 *palette, u16 (*destPixels)[64][64])
{
    u16 tileY, tileX, pixelY, pixelX;
    u8 colorIndex;

    for (tileY = 0; tileY < 8; tileY++)
    {
        for (tileX = 0; tileX < 8; tileX++)
        {
            for (pixelY = 0; pixelY < 8; pixelY++)
            {
                for (pixelX = 0; pixelX < 8; pixelX++)
                {
                    colorIndex = spriteGfx[32 * (tileY * 8 + tileX) + (pixelY << 2) + (pixelX >> 1)];
                    if (pixelX & 1)
                        colorIndex >>= 4;
                    else
                        colorIndex &= 0xF;

                    if (colorIndex == 0) // transparent pixel
                        (*destPixels)[8 * tileY + pixelY][tileX * 8 + pixelX] = 0x8000;
                    else
                        (*destPixels)[8 * tileY + pixelY][tileX * 8 + pixelX] = palette[colorIndex];
                }
            }
        }
    }
}

#define VRAM_PICTURE_DATA(x, y) (((u16 *)(BG_SCREEN_ADDR(12)))[(y) * 32 + (x)])

static void LoadContestPaintingFrame(u8 contestWinnerId, bool8 arg1)
{
    u8 x, y;

    LoadPalette(gPictureFramePalettes, 0, 0x100);
    if (arg1 == TRUE)
    {
        switch (gContestPaintingWinner->contestCategory / 3)
        {
        case CONTEST_CATEGORY_COOL:
            RLUnCompVram(gPictureFrameTiles_0, (void *)VRAM);
            RLUnCompWram(gPictureFrameTilemap_0, gContestMonPixels);
            break;
        case CONTEST_CATEGORY_BEAUTY:
            RLUnCompVram(gPictureFrameTiles_1, (void *)VRAM);
            RLUnCompWram(gPictureFrameTilemap_1, gContestMonPixels);
            break;
        case CONTEST_CATEGORY_CUTE:
            RLUnCompVram(gPictureFrameTiles_2, (void *)VRAM);
            RLUnCompWram(gPictureFrameTilemap_2, gContestMonPixels);
            break;
        case CONTEST_CATEGORY_SMART:
            RLUnCompVram(gPictureFrameTiles_3, (void *)VRAM);
            RLUnCompWram(gPictureFrameTilemap_3, gContestMonPixels);
            break;
        case CONTEST_CATEGORY_TOUGH:
            RLUnCompVram(gPictureFrameTiles_4, (void *)VRAM);
            RLUnCompWram(gPictureFrameTilemap_4, gContestMonPixels);
            break;
        }

        // Set the background
        for (y = 0; y < 20; y++)
        {
            for (x = 0; x < 32; x++)
                VRAM_PICTURE_DATA(x, y) = 0x1015;
        }

        // Copy the image frame
        for (y = 0; y < 10; y++)
        {
            for (x = 0; x < 18; x++)
                VRAM_PICTURE_DATA(x + 6, y + 2) = (*gContestMonPixels)[y + 2][x + 6];
        }

        // Re-set the entire top row to the first top frame part
        for (x = 0; x < 16; x++)
            VRAM_PICTURE_DATA(x + 7, 2) = (*gContestMonPixels)[2][7];
    }
    else if (contestWinnerId < 8)
    {
        RLUnCompVram(gPictureFrameTiles_5, (void *)VRAM);
        RLUnCompVram(gPictureFrameTilemap_5, (void *)(BG_SCREEN_ADDR(12)));
    }
    else
    {
        switch (gContestPaintingWinner->contestCategory / 3)
        {
        case CONTEST_CATEGORY_COOL:
            RLUnCompVram(gPictureFrameTiles_0, (void *)VRAM);
            RLUnCompVram(gPictureFrameTilemap_0, (void *)(BG_SCREEN_ADDR(12)));
            break;
        case CONTEST_CATEGORY_BEAUTY:
            RLUnCompVram(gPictureFrameTiles_1, (void *)VRAM);
            RLUnCompVram(gPictureFrameTilemap_1, (void *)(BG_SCREEN_ADDR(12)));
            break;
        case CONTEST_CATEGORY_CUTE:
            RLUnCompVram(gPictureFrameTiles_2, (void *)VRAM);
            RLUnCompVram(gPictureFrameTilemap_2, (void *)(BG_SCREEN_ADDR(12)));
            break;
        case CONTEST_CATEGORY_SMART:
            RLUnCompVram(gPictureFrameTiles_3, (void *)VRAM);
            RLUnCompVram(gPictureFrameTilemap_3, (void *)(BG_SCREEN_ADDR(12)));
            break;
        case CONTEST_CATEGORY_TOUGH:
            RLUnCompVram(gPictureFrameTiles_4, (void *)VRAM);
            RLUnCompVram(gPictureFrameTilemap_4, (void *)(BG_SCREEN_ADDR(12)));
            break;
        }
    }
}

#undef VRAM_PICTURE_DATA

static void InitPaintingMonOamData(u8 contestWinnerId)
{
    gMain.oamBuffer[0] = sContestPaintingMonOamData;
    gMain.oamBuffer[0].tileNum = 0;

    if (contestWinnerId > 1)
    {
        gMain.oamBuffer[0].x = 88;
        gMain.oamBuffer[0].y = 24;
    }
    else
    {
        gMain.oamBuffer[0].x = 88; // Duplicated code
        gMain.oamBuffer[0].y = 24;
    }
}

static u8 GetImageEffectForContestWinner(u8 contestWinnerId)
{
    u8 contestCategory;

    if (contestWinnerId < 8)
        contestCategory = gContestPaintingWinner->contestCategory;
    else
        contestCategory = gContestPaintingWinner->contestCategory / 3;

    switch (contestCategory)
    {
    case CONTEST_CATEGORY_COOL:
        return IMAGE_EFFECT_OUTLINE_COLORED;
    case CONTEST_CATEGORY_BEAUTY:
        return IMAGE_EFFECT_SHIMMER;
    case CONTEST_CATEGORY_CUTE:
        return IMAGE_EFFECT_POINTILLISM;
    case CONTEST_CATEGORY_SMART:
        return IMAGE_EFFECT_CHARCOAL;
    case CONTEST_CATEGORY_TOUGH:
        return IMAGE_EFFECT_GRAYSCALE_LIGHT;
    }

    return contestCategory;
}

static void AllocPaintingResources(void)
{
    gContestPaintingMonPalette = AllocZeroed(OBJ_PLTT_SIZE);
    gContestMonPixels = AllocZeroed(0x2000);
}

static void DoContestPaintingImageProcessing(u8 imageEffect)
{
    gImageProcessingContext.canvasPixels = gContestMonPixels;
    gImageProcessingContext.canvasPalette = gContestPaintingMonPalette;
    gImageProcessingContext.paletteStart = 0;
    gImageProcessingContext.personality = gContestPaintingWinner->personality % 256;
    gImageProcessingContext.columnStart = 0;
    gImageProcessingContext.rowStart = 0;
    gImageProcessingContext.columnEnd = 64;
    gImageProcessingContext.rowEnd = 64;
    gImageProcessingContext.canvasWidth = 64;
    gImageProcessingContext.canvasHeight = 64;

    switch (imageEffect)
    {
    case IMAGE_EFFECT_CHARCOAL:
    case IMAGE_EFFECT_GRAYSCALE_LIGHT:
        gImageProcessingContext.quantizeEffect = QUANTIZE_EFFECT_GRAYSCALE;
        break;
    case IMAGE_EFFECT_OUTLINE_COLORED:
    case IMAGE_EFFECT_SHIMMER:
    case IMAGE_EFFECT_POINTILLISM:
    default:
        gImageProcessingContext.quantizeEffect = QUANTIZE_EFFECT_STANDARD_LIMITED_COLORS;
        break;
    }

    gImageProcessingContext.var_16 = 2;
    gImageProcessingContext.effect = imageEffect;
    gImageProcessingContext.dest = (void *)OBJ_VRAM0;

    ApplyImageProcessingEffects(&gImageProcessingContext);
    ApplyImageProcessingQuantization(&gImageProcessingContext);
    ConvertImageProcessingToGBA(&gImageProcessingContext);
    LoadPalette(gContestPaintingMonPalette, 0x100, 0x200);
}

static void CreateContestPaintingPicture(u8 contestWinnerId, bool8 arg1)
{
    AllocPaintingResources();
    InitContestMonPixels(gContestPaintingWinner->species, 0);
    DoContestPaintingImageProcessing(GetImageEffectForContestWinner(contestWinnerId));
    InitPaintingMonOamData(contestWinnerId);
    LoadContestPaintingFrame(contestWinnerId, arg1);
}

