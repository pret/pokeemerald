#include "global.h"
#include "intro_credits_graphics.h"
#include "palette.h"
#include "decompress.h"
#include "gpu_regs.h"
#include "task.h"
#include "main.h"
#include "graphics.h"
#include "constants/rgb.h"

/*
    The graphics here are used by both the second scene of the intro
    and the credit sequence, where the player bikes along a grassy path.

    These graphics are placed in graphics/intro/scene_2 to keep
    all of the intro graphics files together, though it includes
    the related graphics that are used only by the credits.
*/

#define TAG_BICYCLE 1001
#define TAG_BRENDAN 1002
#define TAG_MAY     1003
#define TAG_FLYGON_LATIOS  1004
#define TAG_FLYGON_LATIAS  1005

// Used for the Clouds/Trees/Houses sprites that pass by in the background
#define TAG_MOVING_SCENERY 2000

struct IntroCreditsSpriteMetadata
{
    u8 animNum:4;
    u8 shape:2;
    u8 size:2;
    u8 x;
    u8 y;
    u8 subpriority;
    u16 xOff;
};

static const u16 sGrass_Pal[]             = INCBIN_U16("graphics/intro/scene_2/grass.gbapal");
static const u16 sGrassSunset_Pal[]       = INCBIN_U16("graphics/intro/scene_2/grass_sunset.gbapal");
static const u16 sGrassNight_Pal[]        = INCBIN_U16("graphics/intro/scene_2/grass_night.gbapal");
static const u32 sGrass_Gfx[]             = INCBIN_U32("graphics/intro/scene_2/grass.4bpp.lz");
static const u32 sGrass_Tilemap[]         = INCBIN_U32("graphics/intro/scene_2/grass_map.bin.lz");
static const u16 sCloudsBg_Pal[]          = INCBIN_U16("graphics/intro/scene_2/clouds_bg.gbapal");
static const u16 sCloudsBgSunset_Pal[]    = INCBIN_U16("graphics/intro/scene_2/clouds_bg_sunset.gbapal");
static const u32 sCloudsBg_Gfx[]          = INCBIN_U32("graphics/intro/scene_2/clouds_bg.4bpp.lz");
static const u32 sCloudsBg_Tilemap[]      = INCBIN_U32("graphics/intro/scene_2/clouds_bg_map.bin.lz");
static const u16 sClouds_Pal[]            = INCBIN_U16("graphics/intro/scene_2/clouds.gbapal");
static const u16 sCloudsSunset_Pal[]      = INCBIN_U16("graphics/intro/scene_2/clouds_sunset.gbapal");
static const u32 sClouds_Gfx[]            = INCBIN_U32("graphics/intro/scene_2/clouds.4bpp.lz");
static const u16 sTrees_Pal[]             = INCBIN_U16("graphics/intro/scene_2/trees.gbapal");
static const u16 sTreesSunset_Pal[]       = INCBIN_U16("graphics/intro/scene_2/trees_sunset.gbapal");
static const u32 sTrees_Gfx[]             = INCBIN_U32("graphics/intro/scene_2/trees.4bpp.lz");
static const u32 sTrees_Tilemap[]         = INCBIN_U32("graphics/intro/scene_2/trees_map.bin.lz");
static const u16 sTreesSmall_Pal[]        = INCBIN_U16("graphics/intro/scene_2/trees_small.gbapal");
static const u32 sTreesSmall_Gfx[]        = INCBIN_U32("graphics/intro/scene_2/trees_small.4bpp.lz");
static const u16 sHouses_Pal[]            = INCBIN_U16("graphics/intro/scene_2/houses.gbapal");
static const u32 sHouses_Gfx[]            = INCBIN_U32("graphics/intro/scene_2/houses.4bpp.lz");
static const u16 sHouseSilhouette_Pal[]   = INCBIN_U16("graphics/intro/scene_2/house_silhouette.gbapal");
static const u32 sHouses_Tilemap[]        = INCBIN_U32("graphics/intro/scene_2/houses_map.bin.lz");
static const u32 sHouseSilhouette_Gfx[]   = INCBIN_U32("graphics/intro/scene_2/house_silhouette.4bpp.lz");
static const u16 sBrendanCredits_Pal[]    = INCBIN_U16("graphics/intro/scene_2/brendan_credits.gbapal");
static const u32 sBrendanCredits_Gfx[]    = INCBIN_U32("graphics/intro/scene_2/brendan_credits.4bpp.lz");
static const u16 sMayCredits_Pal[]        = INCBIN_U16("graphics/intro/scene_2/may_credits.gbapal");
static const u16 sUnused[0xF0]            = {0};
static const u32 sMayCredits_Gfx[]        = INCBIN_U32("graphics/intro/scene_2/may_credits.4bpp.lz");
static const u32 sBicycle_Gfx[]           = INCBIN_U32("graphics/intro/scene_2/bicycle.4bpp.lz");
static const u16 sLatios_Pal[]            = INCBIN_U16("graphics/intro/scene_2/latios.gbapal");
static const u32 sLatios_Gfx[]            = INCBIN_U32("graphics/intro/scene_2/latios.4bpp.lz");
static const u16 sLatias_Pal[]            = INCBIN_U16("graphics/intro/scene_2/latias.gbapal");
static const u32 sLatias_Gfx[]            = INCBIN_U32("graphics/intro/scene_2/latias.4bpp.lz");

static void SpriteCB_MovingScenery(struct Sprite *sprite);
static void SpriteCB_Player(struct Sprite *sprite);
static void SpriteCB_Bicycle(struct Sprite *sprite);
static void SpriteCB_FlygonLeftHalf(struct Sprite *sprite);

static const struct SpriteTemplate sSpriteTemplate_MovingScenery =
{
    .tileTag = TAG_MOVING_SCENERY,
    .paletteTag = 0xFFFF,
    .oam = &gDummyOamData,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_MovingScenery
};

static const struct CompressedSpriteSheet sSpriteSheet_Clouds[] =
{
    {
        .data = sClouds_Gfx,
        .size = 0x400,
        .tag = TAG_MOVING_SCENERY
    },
    {}
};

static const union AnimCmd sAnim_Cloud_Largest[] =
{
    ANIMCMD_FRAME( 0, 30),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Cloud_Large[] =
{
    ANIMCMD_FRAME(16, 30),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Cloud_Small[] =
{
    ANIMCMD_FRAME(20, 30),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Cloud_Smallest[] =
{
    ANIMCMD_FRAME(22, 30),
    ANIMCMD_END
};

static const union AnimCmd *const sAnims_Clouds[] =
{
    sAnim_Cloud_Largest,
    sAnim_Cloud_Large,
    sAnim_Cloud_Small,
    sAnim_Cloud_Smallest
};

static const struct IntroCreditsSpriteMetadata sSpriteMetadata_Clouds[] =
{
    {
        .animNum = 0,
        .shape = SPRITE_SHAPE(32x32),
        .size = SPRITE_SIZE(32x32),
        .x = 72,
        .y = 32,
        .subpriority = 100,
        .xOff = 0xc00
    },
    {
        .animNum = 0,
        .shape = SPRITE_SHAPE(32x32),
        .size = SPRITE_SIZE(32x32),
        .x = 158,
        .y = 32,
        .subpriority = 100,
        .xOff = 0xc00
    },
    {
        .animNum = 1,
        .shape = SPRITE_SHAPE(16x16),
        .size = SPRITE_SIZE(16x16),
        .x = 192,
        .y = 40,
        .subpriority = 101,
        .xOff = 0x800
    },
    {
        .animNum = 1,
        .shape = SPRITE_SHAPE(16x16),
        .size = SPRITE_SIZE(16x16),
        .x = 56,
        .y = 40,
        .subpriority = 101,
        .xOff = 0x800
    },
    {
        .animNum = 2,
        .shape = SPRITE_SHAPE(16x8),
        .size = SPRITE_SIZE(16x8),
        .x = 100,
        .y = 44,
        .subpriority = 102,
        .xOff = 0x400
    },
    {
        .animNum = 2,
        .shape = SPRITE_SHAPE(16x8),
        .size = SPRITE_SIZE(16x8),
        .x = 152,
        .y = 44,
        .subpriority = 102,
        .xOff = 0x400
    },
    {
        .animNum = 3,
        .shape = SPRITE_SHAPE(16x8),
        .size = SPRITE_SIZE(16x8),
        .x = 8,
        .y = 46,
        .subpriority = 103,
        .xOff = 0x100
    },
    {
        .animNum = 3,
        .shape = SPRITE_SHAPE(16x8),
        .size = SPRITE_SIZE(16x8),
        .x = 56,
        .y = 46,
        .subpriority = 103,
        .xOff = 0x100
    },
    {
        .animNum = 3,
        .shape = SPRITE_SHAPE(16x8),
        .size = SPRITE_SIZE(16x8),
        .x = 240,
        .y = 46,
        .subpriority = 103,
        .xOff = 0x100
    },
};

static const struct CompressedSpriteSheet sSpriteSheet_TreesSmall[] =
{
    {
        .data = sTreesSmall_Gfx,
        .size = 0x400,
        .tag = TAG_MOVING_SCENERY
    },
    {}
};

static const union AnimCmd sAnim_Trees_0[] =
{
    ANIMCMD_FRAME( 0, 30),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Trees_1[] =
{
    ANIMCMD_FRAME(16, 30),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Trees_2[] =
{
    ANIMCMD_FRAME(24, 30),
    ANIMCMD_END
};

static const union AnimCmd *const sAnims_Trees[] =
{
    sAnim_Trees_0,
    sAnim_Trees_1,
    sAnim_Trees_2
};

static const struct IntroCreditsSpriteMetadata sSpriteMetadata_Trees[] =
{
    {
        .animNum = 0,
        .shape = SPRITE_SHAPE(32x32),
        .size = SPRITE_SIZE(32x32),
        .x = 16,
        .y = 88,
        .subpriority = 100,
        .xOff = 0x2000,
    },
    {
        .animNum = 0,
        .shape = SPRITE_SHAPE(32x32),
        .size = SPRITE_SIZE(32x32),
        .x = 80,
        .y = 88,
        .subpriority = 100,
        .xOff = 0x2000,
    },
    {
        .animNum = 0,
        .shape = SPRITE_SHAPE(32x32),
        .size = SPRITE_SIZE(32x32),
        .x = 144,
        .y = 88,
        .subpriority = 100,
        .xOff = 0x2000,
    },
    {
        .animNum = 0,
        .shape = SPRITE_SHAPE(32x32),
        .size = SPRITE_SIZE(32x32),
        .x = 208,
        .y = 88,
        .subpriority = 100,
        .xOff = 0x2000,
    },
    {
        .animNum = 1,
        .shape = SPRITE_SHAPE(16x32),
        .size = SPRITE_SIZE(16x32),
        .x = 40,
        .y = 88,
        .subpriority = 101,
        .xOff = 0x1000,
    },
    {
        .animNum = 1,
        .shape = SPRITE_SHAPE(16x32),
        .size = SPRITE_SIZE(16x32),
        .x = 104,
        .y = 88,
        .subpriority = 101,
        .xOff = 0x1000,
    },
    {
        .animNum = 1,
        .shape = SPRITE_SHAPE(16x32),
        .size = SPRITE_SIZE(16x32),
        .x = 168,
        .y = 88,
        .subpriority = 101,
        .xOff = 0x1000,
    },
    {
        .animNum = 1,
        .shape = SPRITE_SHAPE(16x32),
        .size = SPRITE_SIZE(16x32),
        .x = 232,
        .y = 88,
        .subpriority = 101,
        .xOff = 0x1000,
    },
    {
        .animNum = 2,
        .shape = SPRITE_SHAPE(16x32),
        .size = SPRITE_SIZE(16x32),
        .x = 56,
        .y = 88,
        .subpriority = 102,
        .xOff = 0x800,
    },
    {
        .animNum = 2,
        .shape = SPRITE_SHAPE(16x32),
        .size = SPRITE_SIZE(16x32),
        .x = 120,
        .y = 88,
        .subpriority = 102,
        .xOff = 0x800,
    },
    {
        .animNum = 2,
        .shape = SPRITE_SHAPE(16x32),
        .size = SPRITE_SIZE(16x32),
        .x = 184,
        .y = 88,
        .subpriority = 102,
        .xOff = 0x800,
    },
    {
        .animNum = 2,
        .shape = SPRITE_SHAPE(16x32),
        .size = SPRITE_SIZE(16x32),
        .x = 248,
        .y = 88,
        .subpriority = 102,
        .xOff = 0x800,
    }
};

static const struct CompressedSpriteSheet sSpriteSheet_HouseSilhouette[] =
{
    {
        .data = sHouseSilhouette_Gfx,
        .size = 0x400,
        .tag = TAG_MOVING_SCENERY
    },
    {}
};

static const union AnimCmd sAnim_HouseSilhouette[] =
{
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_END
};

static const union AnimCmd *const sAnims_HouseSilhouette[] =
{
    sAnim_HouseSilhouette
};

static const struct IntroCreditsSpriteMetadata sSpriteMetadata_HouseSilhouette[] =
{
    {
        .animNum = 0,
        .shape = SPRITE_SHAPE(32x32),
        .size = SPRITE_SIZE(32x32),
        .x = 24,
        .y = 88,
        .subpriority = 100,
        .xOff = 0x1000,
    },
    {
        .animNum = 0,
        .shape = SPRITE_SHAPE(32x32),
        .size = SPRITE_SIZE(32x32),
        .x = 64,
        .y = 88,
        .subpriority = 100,
        .xOff = 0x1000,
    },
    {
        .animNum = 0,
        .shape = SPRITE_SHAPE(32x32),
        .size = SPRITE_SIZE(32x32),
        .x = 104,
        .y = 88,
        .subpriority = 100,
        .xOff = 0x1000,
    },
    {
        .animNum = 0,
        .shape = SPRITE_SHAPE(32x32),
        .size = SPRITE_SIZE(32x32),
        .x = 144,
        .y = 88,
        .subpriority = 100,
        .xOff = 0x1000,
    },
    {
        .animNum = 0,
        .shape = SPRITE_SHAPE(32x32),
        .size = SPRITE_SIZE(32x32),
        .x = 184,
        .y = 88,
        .subpriority = 100,
        .xOff = 0x1000,
    },
    {
        .animNum = 0,
        .shape = SPRITE_SHAPE(32x32),
        .size = SPRITE_SIZE(32x32),
        .x = 224,
        .y = 88,
        .subpriority = 100,
        .xOff = 0x1000,
    }
};

static const struct OamData sOamData_Player =
{
    .y = DISPLAY_HEIGHT,
    .shape = SPRITE_SHAPE(64x64),
    .size = SPRITE_SIZE(64x64),
    .priority = 1
};

static const union AnimCmd sAnim_Player[] =
{
    ANIMCMD_FRAME(  0, 8),
    ANIMCMD_FRAME( 64, 8),
    ANIMCMD_FRAME(128, 8),
    ANIMCMD_FRAME(192, 8),
    ANIMCMD_JUMP(0)
};

static const union AnimCmd *const sAnims_Player[] =
{
    sAnim_Player
};

static const struct SpriteTemplate sSpriteTemplate_Brendan =
{
    .tileTag = TAG_BRENDAN,
    .paletteTag = TAG_BRENDAN,
    .oam = &sOamData_Player,
    .anims = sAnims_Player,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_Player
};

static const struct SpriteTemplate sSpriteTemplate_May =
{
    .tileTag = TAG_MAY,
    .paletteTag = TAG_MAY,
    .oam = &sOamData_Player,
    .anims = sAnims_Player,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_Player
};

static const struct OamData sOamData_Bicycle =
{
    .y = DISPLAY_HEIGHT,
    .shape = SPRITE_SHAPE(64x32),
    .size = SPRITE_SIZE(64x32),
    .priority = 1
};

static const union AnimCmd sAnim_Bicycle[] =
{
    ANIMCMD_FRAME(  0, 8),
    ANIMCMD_FRAME( 32, 8),
    ANIMCMD_FRAME( 64, 8),
    ANIMCMD_FRAME( 96, 8),
    ANIMCMD_JUMP(0)
};

static const union AnimCmd *const sAnims_Bicycle[] =
{
    sAnim_Bicycle
};

static const struct SpriteTemplate sSpriteTemplate_BrendanBicycle =
{
    .tileTag = TAG_BICYCLE,
    .paletteTag = TAG_BRENDAN,
    .oam = &sOamData_Bicycle,
    .anims = sAnims_Bicycle,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_Bicycle
};

static const struct SpriteTemplate sSpriteTemplate_MayBicycle =
{
    .tileTag = TAG_BICYCLE,
    .paletteTag = TAG_MAY,
    .oam = &sOamData_Bicycle,
    .anims = sAnims_Bicycle,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_Bicycle
};

static const struct OamData sOamData_Flygon =
{
    .y = DISPLAY_HEIGHT,
    .shape = SPRITE_SHAPE(64x64),
    .size = SPRITE_SIZE(64x64),
    .priority = 1
};

static const union AnimCmd sAnim_FlygonLeft[] =
{
    ANIMCMD_FRAME(0, 16),
    ANIMCMD_END
};

static const union AnimCmd sAnim_FlygonRight[] =
{
    ANIMCMD_FRAME(64, 16),
    ANIMCMD_END
};

static const union AnimCmd *const sAnims_Flygon[] =
{
    sAnim_FlygonLeft,
    sAnim_FlygonRight
};

static const struct SpriteTemplate sSpriteTemplate_FlygonLatios =
{
    .tileTag = TAG_FLYGON_LATIOS,
    .paletteTag = TAG_FLYGON_LATIOS,
    .oam = &sOamData_Flygon,
    .anims = sAnims_Flygon,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_FlygonLeftHalf
};

static const struct SpriteTemplate sSpriteTemplate_FlygonLatias =
{
    .tileTag = TAG_FLYGON_LATIAS,
    .paletteTag = TAG_FLYGON_LATIAS,
    .oam = &sOamData_Flygon,
    .anims = sAnims_Flygon,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_FlygonLeftHalf
};

const struct CompressedSpriteSheet gSpriteSheet_IntroBrendan[] =
{
    {
        .data = gIntroBrendan_Gfx,
        .size = 0x2000,
        .tag = TAG_BRENDAN
    },
    {}
};

const struct CompressedSpriteSheet gSpriteSheet_IntroMay[] =
{
    {
        .data = gIntroMay_Gfx,
        .size = 0x2000,
        .tag = TAG_MAY
    },
    {}
};

const struct CompressedSpriteSheet gSpriteSheet_IntroBicycle[] =
{
    {
        .data = sBicycle_Gfx,
        .size = 0x1000,
        .tag = TAG_BICYCLE
    },
    {}
};

// In RS these were Latios/Latias. In Emerald both are replaced with Flygon and now only 1 is used
static const struct CompressedSpriteSheet sSpriteSheet_IntroFlygon_Unused[] =
{
    {
        .data = gIntroFlygon_Gfx,
        .size = 0x1000,
        .tag = TAG_FLYGON_LATIOS
    },
    {}
};

const struct CompressedSpriteSheet gSpriteSheet_IntroFlygon[] =
{
    {
        .data = gIntroFlygon_Gfx,
        .size = 0x1000,
        .tag = TAG_FLYGON_LATIAS
    },
    {}
};

const struct SpritePalette gSpritePalettes_IntroPlayerFlygon[] =
{
    { .data = gIntroPlayer_Pal, .tag = TAG_BRENDAN },
    { .data = gIntroPlayer_Pal, .tag = TAG_MAY },
    { .data = gIntroFlygon_Pal, .tag = TAG_FLYGON_LATIOS },
    { .data = gIntroFlygon_Pal, .tag = TAG_FLYGON_LATIAS },
    {}
};

const struct CompressedSpriteSheet gSpriteSheet_CreditsBrendan[] =
{
    {
        .data = sBrendanCredits_Gfx,
        .size = 0x3800,
        .tag = TAG_BRENDAN
    },
    {}
};

const struct CompressedSpriteSheet gSpriteSheet_CreditsMay[] =
{
    {
        .data = sMayCredits_Gfx,
        .size = 0x3800,
        .tag = TAG_MAY
    },
    {}
};

const struct CompressedSpriteSheet gSpriteSheet_CreditsBicycle[] =
{
    {
        .data = sBicycle_Gfx,
        .size = 0x1000,
        .tag = TAG_BICYCLE
    },
    {}
};

// Unused
static const struct CompressedSpriteSheet sSpriteSheet_Latios[] =
{
    {
        .data = sLatios_Gfx,
        .size = 0x1000,
        .tag = TAG_FLYGON_LATIOS
    },
    {}
};

// Unused
static const struct CompressedSpriteSheet sSpriteSheet_Latias[] =
{
    {
        .data = sLatias_Gfx,
        .size = 0x1000,
        .tag = TAG_FLYGON_LATIAS
    },
    {}
};

const struct SpritePalette gSpritePalettes_Credits[] =
{
    { .data = sBrendanCredits_Pal, .tag = TAG_BRENDAN },
    { .data = sMayCredits_Pal,     .tag = TAG_MAY },
    { .data = sLatios_Pal,         .tag = TAG_FLYGON_LATIOS },
    { .data = sLatias_Pal,         .tag = TAG_FLYGON_LATIAS },
    {}
};

const struct CompressedSpriteSheet gSpriteSheet_CreditsRivalBrendan[] =
{
    {
        .data = sBrendanCredits_Gfx,
        .size = 0x2000,
        .tag = TAG_BRENDAN
    },
    {}
};

const struct CompressedSpriteSheet gSpriteSheet_CreditsRivalMay[] =
{
    {
        .data = sMayCredits_Gfx,
        .size = 0x2000,
        .tag = TAG_MAY
    },
    {}
};

EWRAM_DATA u16 gIntroCredits_MovingSceneryVBase = 0;
EWRAM_DATA s16 gIntroCredits_MovingSceneryVOffset = 0;
EWRAM_DATA s16 gIntroCredits_MovingSceneryState = 0;

static void CreateCloudSprites(void);
static void CreateTreeSprites(void);
static void CreateHouseSprites(void);
static void Task_BicycleBgAnimation(u8);

void LoadIntroPart2Graphics(u8 scenery)
{
    LZ77UnCompVram(sGrass_Gfx, (void *)(BG_CHAR_ADDR(1)));
    LZ77UnCompVram(sGrass_Tilemap, (void *)(BG_SCREEN_ADDR(15)));
    LoadPalette(&sGrass_Pal, 240, sizeof(sGrass_Pal));
    switch (scenery)
    {
    case 0:
    default:
        // Never reached, only called with an argument of 1
        // Clouds are never used in this part of the intro
        LZ77UnCompVram(sCloudsBg_Gfx, (void *)(VRAM));
        LZ77UnCompVram(sCloudsBg_Tilemap, (void *)(BG_SCREEN_ADDR(6)));
        LoadPalette(&sCloudsBg_Pal, 0, sizeof(sCloudsBg_Pal));
        LoadCompressedSpriteSheet(sSpriteSheet_Clouds);
        LoadPalette(&sClouds_Pal, 256, sizeof(sClouds_Pal));
        CreateCloudSprites();
        break;
    case 1:
        LZ77UnCompVram(sTrees_Gfx, (void *)(VRAM));
        LZ77UnCompVram(sTrees_Tilemap, (void *)(BG_SCREEN_ADDR(6)));
        LoadPalette(&sTrees_Pal, 0, sizeof(sTrees_Pal));
        LoadCompressedSpriteSheet(sSpriteSheet_TreesSmall);
        LoadPalette(&sTreesSmall_Pal, 256, sizeof(sTreesSmall_Pal));
        CreateTreeSprites();
        break;
    }
    gIntroCredits_MovingSceneryState = INTROCRED_SCENERY_NORMAL;
    gReservedSpritePaletteCount = 8;
}

// Note: This is only called with a=1.
void SetIntroPart2BgCnt(u8 scenery)
{
    // Only called with scenery = 1
    switch (scenery)
    {
    default:
    case 0:
        SetGpuReg(REG_OFFSET_BG3CNT, BGCNT_PRIORITY(3)
                                   | BGCNT_CHARBASE(0)
                                   | BGCNT_16COLOR
                                   | BGCNT_SCREENBASE(6)
                                   | BGCNT_TXT256x256);
        SetGpuReg(REG_OFFSET_BG2CNT, BGCNT_PRIORITY(2)
                                   | BGCNT_CHARBASE(0)
                                   | BGCNT_16COLOR
                                   | BGCNT_SCREENBASE(7)
                                   | BGCNT_TXT256x256);
        SetGpuReg(REG_OFFSET_BG1CNT, BGCNT_PRIORITY(1)
                                   | BGCNT_CHARBASE(1)
                                   | BGCNT_16COLOR
                                   | BGCNT_SCREENBASE(15)
                                   | BGCNT_TXT256x256);
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0
                                    | DISPCNT_OBJ_1D_MAP
                                    | DISPCNT_BG1_ON
                                    | DISPCNT_BG2_ON
                                    | DISPCNT_BG3_ON
                                    | DISPCNT_OBJ_ON);
        break;
    case 1:
        SetGpuReg(REG_OFFSET_BG3CNT, BGCNT_PRIORITY(3)
                                   | BGCNT_CHARBASE(0)
                                   | BGCNT_16COLOR
                                   | BGCNT_SCREENBASE(6)
                                   | BGCNT_TXT256x256);
        SetGpuReg(REG_OFFSET_BG2CNT, BGCNT_PRIORITY(2)
                                   | BGCNT_CHARBASE(0)
                                   | BGCNT_16COLOR
                                   | BGCNT_SCREENBASE(7)
                                   | BGCNT_TXT256x256);
        SetGpuReg(REG_OFFSET_BG1CNT, BGCNT_PRIORITY(1)
                                   | BGCNT_CHARBASE(1)
                                   | BGCNT_16COLOR
                                   | BGCNT_SCREENBASE(15)
                                   | BGCNT_TXT256x256);
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0
                                    | DISPCNT_OBJ_1D_MAP
                                    | DISPCNT_BG1_ON
                                    | DISPCNT_BG2_ON
                                    | DISPCNT_BG3_ON
                                    | DISPCNT_OBJ_ON);
        break;
    case 2:
        SetGpuReg(REG_OFFSET_BG3CNT, BGCNT_PRIORITY(3)
                                   | BGCNT_CHARBASE(0)
                                   | BGCNT_16COLOR
                                   | BGCNT_SCREENBASE(6)
                                   | BGCNT_TXT256x256);
        SetGpuReg(REG_OFFSET_BG2CNT, BGCNT_PRIORITY(2)
                                   | BGCNT_CHARBASE(0)
                                   | BGCNT_16COLOR
                                   | BGCNT_SCREENBASE(7)
                                   | BGCNT_TXT256x256);
        SetGpuReg(REG_OFFSET_BG1CNT, BGCNT_PRIORITY(1)
                                   | BGCNT_CHARBASE(1)
                                   | BGCNT_16COLOR
                                   | BGCNT_SCREENBASE(15)
                                   | BGCNT_TXT256x256);
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0
                                    | DISPCNT_OBJ_1D_MAP
                                    | DISPCNT_BG1_ON
                                    | DISPCNT_BG2_ON
                                    | DISPCNT_BG3_ON
                                    | DISPCNT_OBJ_ON);
        break;
    }
}

void LoadCreditsSceneGraphics(u8 scene)
{
    LZ77UnCompVram(sGrass_Gfx, (void *)(BG_CHAR_ADDR(1)));
    LZ77UnCompVram(sGrass_Tilemap, (void *)(BG_SCREEN_ADDR(15)));
    switch (scene)
    {
    case SCENE_OCEAN_MORNING:
    default:
        LoadPalette(&sGrass_Pal, 240, sizeof(sGrass_Pal));
        LZ77UnCompVram(sCloudsBg_Gfx, (void *)(VRAM));
        LZ77UnCompVram(sCloudsBg_Tilemap, (void *)(BG_SCREEN_ADDR(6)));
        LoadPalette(&sCloudsBg_Pal, 0, sizeof(sCloudsBg_Pal));
        LoadCompressedSpriteSheet(sSpriteSheet_Clouds);
        LZ77UnCompVram(sClouds_Gfx, (void *)(OBJ_VRAM0));
        LoadPalette(&sClouds_Pal, 256, sizeof(sClouds_Pal));
        CreateCloudSprites();
        break;
    case SCENE_OCEAN_SUNSET:
        LoadPalette(&sGrassSunset_Pal, 240, sizeof(sGrassSunset_Pal));
        LZ77UnCompVram(sCloudsBg_Gfx, (void *)(VRAM));
        LZ77UnCompVram(sCloudsBg_Tilemap, (void *)(BG_SCREEN_ADDR(6)));
        LoadPalette(&sCloudsBgSunset_Pal, 0, sizeof(sCloudsBgSunset_Pal));
        LoadCompressedSpriteSheet(sSpriteSheet_Clouds);
        LZ77UnCompVram(sClouds_Gfx, (void *)(OBJ_VRAM0));
        LoadPalette(&sCloudsSunset_Pal, 256, sizeof(sCloudsSunset_Pal));
        CreateCloudSprites();
        break;
    case SCENE_FOREST_RIVAL_ARRIVE:
    case SCENE_FOREST_CATCH_RIVAL:
        LoadPalette(&sGrassSunset_Pal, 240, sizeof(sGrassSunset_Pal));
        LZ77UnCompVram(sTrees_Gfx, (void *)(VRAM));
        LZ77UnCompVram(sTrees_Tilemap, (void *)(BG_SCREEN_ADDR(6)));
        LoadPalette(&sTreesSunset_Pal, 0, sizeof(sTreesSunset_Pal));
        LoadCompressedSpriteSheet(sSpriteSheet_TreesSmall);
        LoadPalette(&sTreesSunset_Pal, 256, sizeof(sTreesSunset_Pal));
        CreateTreeSprites();
        break;
    case SCENE_CITY_NIGHT:
        LoadPalette(&sGrassNight_Pal, 240, sizeof(sGrassNight_Pal));
        LZ77UnCompVram(sHouses_Gfx, (void *)(VRAM));
        LZ77UnCompVram(sHouses_Tilemap, (void *)(BG_SCREEN_ADDR(6)));
        LoadPalette(&sHouses_Pal, 0, sizeof(sHouses_Pal));
        LoadCompressedSpriteSheet(sSpriteSheet_HouseSilhouette);
        LoadPalette(&sHouseSilhouette_Pal, 256, sizeof(sHouseSilhouette_Pal));
        CreateHouseSprites();
        break;
    }
    gReservedSpritePaletteCount = 8;
    gIntroCredits_MovingSceneryState = INTROCRED_SCENERY_NORMAL;
}

void SetCreditsSceneBgCnt(u8 scene)
{
    SetGpuReg(REG_OFFSET_BG3CNT, BGCNT_PRIORITY(3)
                               | BGCNT_CHARBASE(0)
                               | BGCNT_16COLOR
                               | BGCNT_SCREENBASE(6)
                               | BGCNT_TXT256x256);
    SetGpuReg(REG_OFFSET_BG2CNT, BGCNT_PRIORITY(2)
                               | BGCNT_CHARBASE(0)
                               | BGCNT_16COLOR
                               | BGCNT_SCREENBASE(7)
                               | BGCNT_TXT256x256);
    SetGpuReg(REG_OFFSET_BG1CNT, BGCNT_PRIORITY(1)
                               | BGCNT_CHARBASE(1)
                               | BGCNT_16COLOR
                               | BGCNT_SCREENBASE(15)
                               | BGCNT_TXT256x256);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0
                                | DISPCNT_OBJ_1D_MAP
                                | DISPCNT_BG_ALL_ON
                                | DISPCNT_OBJ_ON);
}

#define tMode     data[0] // Can be 0-2, but only != 0 matters. Determines vertical movement for bg2
#define tBg1Speed data[1]
#define tBg1PosHi data[2]
#define tBg1PosLo data[3]
#define tBg2Speed data[4]
#define tBg2PosHi data[5]
#define tBg2PosLo data[6]
#define tBg3Speed data[7]
#define tBg3PosHi data[8]
#define tBg3PosLo data[9]

// Create task that manages the moving backgrounds during the bicycle ride
u8 CreateBicycleBgAnimationTask(u8 mode, u16 bg1Speed, u16 bg2Speed, u16 bg3Speed)
{
    u8 taskId = CreateTask(Task_BicycleBgAnimation, 0);

    gTasks[taskId].tMode = mode;
    gTasks[taskId].tBg1Speed = bg1Speed;
    gTasks[taskId].tBg1PosHi = 0;
    gTasks[taskId].tBg1PosLo = 0;
    gTasks[taskId].tBg2Speed = bg2Speed;
    gTasks[taskId].tBg2PosHi = 0;
    gTasks[taskId].tBg2PosLo = 0;
    gTasks[taskId].tBg3Speed = bg3Speed;
    gTasks[taskId].tBg3PosHi = 8;
    gTasks[taskId].tBg3PosLo = 0;
    Task_BicycleBgAnimation(taskId);
    return taskId;
}

static void Task_BicycleBgAnimation(u8 taskId)
{
    s16 bg1Speed;
    s16 bg2Speed;
    s16 bg3Speed;
    s32 offset;

    // Move BG1
    bg1Speed = gTasks[taskId].tBg1Speed;
    if (bg1Speed != 0)
    {
        offset = (gTasks[taskId].tBg1PosHi << 16) + (u16)gTasks[taskId].tBg1PosLo;
        offset -= (u16)bg1Speed << 4;
        gTasks[taskId].tBg1PosHi = offset >> 16;
        gTasks[taskId].tBg1PosLo = offset;
        SetGpuReg(REG_OFFSET_BG1HOFS, gTasks[taskId].tBg1PosHi);
        SetGpuReg(REG_OFFSET_BG1VOFS, gIntroCredits_MovingSceneryVBase + gIntroCredits_MovingSceneryVOffset);
    }

    // Move BG2
    bg2Speed = gTasks[taskId].tBg2Speed;
    if (bg2Speed != 0)
    {
        offset = (gTasks[taskId].tBg2PosHi << 16) + (u16)gTasks[taskId].tBg2PosLo;
        offset -= (u16)bg2Speed << 4;
        gTasks[taskId].tBg2PosHi = offset >> 16;
        gTasks[taskId].tBg2PosLo = offset;
        SetGpuReg(REG_OFFSET_BG2HOFS, gTasks[taskId].tBg2PosHi);
        if (gTasks[taskId].tMode != 0)
            SetGpuReg(REG_OFFSET_BG2VOFS, gIntroCredits_MovingSceneryVBase + gIntroCredits_MovingSceneryVOffset);
        else
            SetGpuReg(REG_OFFSET_BG2VOFS, gIntroCredits_MovingSceneryVBase);
    }

    // Move BG3
    bg3Speed = gTasks[taskId].tBg3Speed;
    if (bg3Speed != 0)
    {
        offset = (gTasks[taskId].tBg3PosHi << 16) + (u16)gTasks[taskId].tBg3PosLo;
        offset -= (u16)bg3Speed << 4;
        gTasks[taskId].tBg3PosHi = offset >> 16;
        gTasks[taskId].tBg3PosLo = offset;
        SetGpuReg(REG_OFFSET_BG3HOFS, gTasks[taskId].tBg3PosHi);
        SetGpuReg(REG_OFFSET_BG3VOFS, gIntroCredits_MovingSceneryVBase);
    }
}

void CycleSceneryPalette(u8 mode)
{
    u16 x;
    u16 y;
    switch (mode)
    {
        case 0:
        default:
            if (gMain.vblankCounter1 & 3 || gPaletteFade.active)
                break;
            if (gMain.vblankCounter1 & 4)
            {
                x = gPlttBufferUnfaded[9];
                y = gPlttBufferUnfaded[10];
            }
            else
            {
                x = gPlttBufferUnfaded[10];
                y = gPlttBufferUnfaded[9];
            }
            LoadPalette(&x, 9, sizeof(x));
            LoadPalette(&y, 10, sizeof(y));
            break;
        case 2:
            if (gMain.vblankCounter1 & 3 || gPaletteFade.active)
                break;
            if (gMain.vblankCounter1 & 4)
            {
                x = RGB(7, 9, 15);
                y = RGB(21, 20, 0);
            }
            else
            {
                x = RGB(28, 24, 0);
                y = RGB(7, 9, 15);
            }
            LoadPalette(&x, 12, sizeof(x));
            LoadPalette(&y, 13, sizeof(y));
            break;
        case 1:
            break;
    }
}

#define tHasVerticalMove data[0]
#define tXOffset         data[1]
#define tXPos            data[2]

static void SpriteCB_MovingScenery(struct Sprite *sprite)
{
    s32 x;
    s16 state = gIntroCredits_MovingSceneryState;

    if (state != INTROCRED_SCENERY_FROZEN)
    {
        switch (state)
        {
        default: // INTROCRED_SCENERY_DESTROY
            DestroySprite(sprite);
            break;
        case INTROCRED_SCENERY_NORMAL:
            x = ((sprite->x << 16) | (u16)sprite->tXPos) + (u16)sprite->tXOffset;
            sprite->x = x >> 16;
            sprite->tXPos = x;
            if (sprite->x > 255)
                sprite->x = -32;
            if (sprite->tHasVerticalMove)
                sprite->y2 = -(gIntroCredits_MovingSceneryVBase + gIntroCredits_MovingSceneryVOffset);
            else
                sprite->y2 = -gIntroCredits_MovingSceneryVBase;
            break;
        }
    }
}

static void CreateMovingScenerySprites(bool8 hasVerticalMove, const struct IntroCreditsSpriteMetadata *metadata, const union AnimCmd *const *anims, u8 numSprites)
{
    u8 i;

    for(i = 0; i < numSprites; i++)
    {
        u8 sprite = CreateSprite(&sSpriteTemplate_MovingScenery, metadata[i].x, metadata[i].y, metadata[i].subpriority);
        CalcCenterToCornerVec(&gSprites[sprite], metadata[i].shape, metadata[i].size, ST_OAM_AFFINE_OFF);
        gSprites[sprite].oam.priority = 3;
        gSprites[sprite].oam.shape = metadata[i].shape;
        gSprites[sprite].oam.size = metadata[i].size;
        gSprites[sprite].oam.paletteNum = 0;
        gSprites[sprite].anims = anims;
        StartSpriteAnim(&gSprites[sprite], metadata[i].animNum);
        gSprites[sprite].tHasVerticalMove = hasVerticalMove;
        gSprites[sprite].tXOffset = metadata[i].xOff;
        gSprites[sprite].tXPos = 0;
    }
}

#undef tHasVerticalMove
#undef tXOffset
#undef tXPos

static void CreateCloudSprites(void)
{
    CreateMovingScenerySprites(FALSE, sSpriteMetadata_Clouds, sAnims_Clouds, 9);
}

static void CreateTreeSprites(void)
{
    CreateMovingScenerySprites(TRUE, sSpriteMetadata_Trees, sAnims_Trees, 12);
}

static void CreateHouseSprites(void)
{
    CreateMovingScenerySprites(TRUE, sSpriteMetadata_HouseSilhouette, sAnims_HouseSilhouette, 6);
}

static void SpriteCB_Player(struct Sprite *sprite)
{
}

#define sPlayerSpriteId data[0]

static void SpriteCB_Bicycle(struct Sprite* sprite)
{
    sprite->invisible = gSprites[sprite->sPlayerSpriteId].invisible;
    sprite->x = gSprites[sprite->sPlayerSpriteId].x;
    sprite->y = gSprites[sprite->sPlayerSpriteId].y + 8;
    sprite->x2 = gSprites[sprite->sPlayerSpriteId].x2;
    sprite->y2 = gSprites[sprite->sPlayerSpriteId].y2;
}

u8 CreateIntroBrendanSprite(s16 x, s16 y)
{
    u8 playerSpriteId = CreateSprite(&sSpriteTemplate_Brendan, x, y, 2);
    u8 bicycleSpriteId = CreateSprite(&sSpriteTemplate_BrendanBicycle, x, y + 8, 3);
    gSprites[bicycleSpriteId].sPlayerSpriteId = playerSpriteId;
    return playerSpriteId;
}

u8 CreateIntroMaySprite(s16 x, s16 y)
{
    u8 playerSpriteId = CreateSprite(&sSpriteTemplate_May, x, y, 2);
    u8 bicycleSpriteId = CreateSprite(&sSpriteTemplate_MayBicycle, x, y + 8, 3);
    gSprites[bicycleSpriteId].sPlayerSpriteId = playerSpriteId;
    return playerSpriteId;
}

#undef sPlayerSpriteId

static void SpriteCB_FlygonLeftHalf(struct Sprite *sprite)
{
}

#define sLeftSpriteId data[0]

static void SpriteCB_FlygonRightHalf(struct Sprite* sprite)
{
    sprite->invisible = gSprites[sprite->sLeftSpriteId].invisible;
    sprite->y = gSprites[sprite->sLeftSpriteId].y;
    sprite->x2 = gSprites[sprite->sLeftSpriteId].x2;
    sprite->y2 = gSprites[sprite->sLeftSpriteId].y2;
}

// In RS these were for Latios/Latias. In Emerald both are replaced with Flygon and now only 1 is used
static u8 CreateIntroFlygonSprite_Unused(s16 x, s16 y)
{
    u8 leftSpriteId = CreateSprite(&sSpriteTemplate_FlygonLatios, x - 32, y, 5);
    u8 rightSpriteId = CreateSprite(&sSpriteTemplate_FlygonLatios, x + 32, y, 6);
    gSprites[rightSpriteId].sLeftSpriteId = leftSpriteId;
    StartSpriteAnim(&gSprites[rightSpriteId], 1);
    gSprites[rightSpriteId].callback = &SpriteCB_FlygonRightHalf;
    return leftSpriteId;
}


u8 CreateIntroFlygonSprite(s16 x, s16 y)
{
    u8 leftSpriteId = CreateSprite(&sSpriteTemplate_FlygonLatias, x - 32, y, 5);
    u8 rightSpriteId = CreateSprite(&sSpriteTemplate_FlygonLatias, x + 32, y, 6);
    gSprites[rightSpriteId].sLeftSpriteId = leftSpriteId;
    StartSpriteAnim(&gSprites[rightSpriteId], 1);
    gSprites[rightSpriteId].callback = &SpriteCB_FlygonRightHalf;
    return leftSpriteId;
}

#undef sLeftSpriteId
