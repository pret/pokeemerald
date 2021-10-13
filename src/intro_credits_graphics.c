#include "global.h"
#include "intro_credits_graphics.h"
#include "palette.h"
#include "decompress.h"
#include "gpu_regs.h"
#include "task.h"
#include "main.h"
#include "graphics.h"

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

static const u16 gUnknown_085F06E0[] = INCBIN_U16("graphics/intro/intro2_grass.gbapal");
static const u16 gUnknown_085F0700[] = INCBIN_U16("graphics/intro/intro2_grass_afternoon.gbapal");
static const u16 gUnknown_085F0720[] = INCBIN_U16("graphics/intro/intro2_grass_night.gbapal");
static const u32 gUnknown_085F0740[] = INCBIN_U32("graphics/intro/intro2_grass.4bpp.lz");
static const u32 gUnknown_085F0BC0[] = INCBIN_U32("graphics/intro/intro2_grass_map.bin.lz");
static const u16 gUnknown_085F0CFC[] = INCBIN_U16("graphics/intro/85F0CFC.gbapal");
static const u16 gUnknown_085F0D5C[] = INCBIN_U16("graphics/intro/85F0D5C.gbapal");
static const u32 gUnknown_085F0DBC[] = INCBIN_U32("graphics/intro/intro2_bgclouds.4bpp.lz");
static const u32 gUnknown_085F1398[] = INCBIN_U32("graphics/intro/intro2_bgclouds_map.bin.lz");
static const u16 gUnknown_085F1668[] = INCBIN_U16("graphics/intro/intro2_bgclouds.gbapal");
static const u16 gUnknown_085F1688[] = INCBIN_U16("graphics/intro/intro2_bgclouds_afternoon.gbapal");
static const u32 gUnknown_085F16A8[] = INCBIN_U32("graphics/intro/intro2_bgclouds2.4bpp.lz");
static const u16 gUnknown_085F17E4[] = INCBIN_U16("graphics/intro/intro2_bgtrees2.gbapal");
static const u16 gUnknown_085F1804[] = INCBIN_U16("graphics/intro/intro2_bgtrees2_afternoon.gbapal");
static const u32 gUnknown_085F1824[] = INCBIN_U32("graphics/intro/intro2_bgtrees.4bpp.lz");
static const u32 gUnknown_085F1EAC[] = INCBIN_U32("graphics/intro/intro2_bgtrees_map.bin.lz");
static const u16 gUnknown_085F21B0[] = INCBIN_U16("graphics/intro/intro2_bgtrees.gbapal");
static const u32 gIntro2TreeTiles[] = INCBIN_U32("graphics/intro/intro2_bgtreessmall.4bpp.lz");
static const u16 gUnknown_085F231C[] = INCBIN_U16("graphics/intro/85F231C.gbapal");
static const u32 gUnknown_085F235C[] = INCBIN_U32("graphics/intro/intro2_bgnight.4bpp.lz");
static const u16 gUnknown_085F2548[] = INCBIN_U16("graphics/intro/intro2_bgnight.gbapal");
static const u32 gUnknown_085F2568[] = INCBIN_U32("graphics/intro/intro2_bgnight_map.bin.lz");
static const u32 gIntro2NightTiles[] = INCBIN_U32("graphics/intro/intro2_night.4bpp.lz");
static const u16 gIntro2BrendanPalette[] = INCBIN_U16("graphics/intro/intro2_brendan.gbapal");
static const u32 gIntro2BrendanTiles[] = INCBIN_U32("graphics/intro/intro2_brendan.4bpp.lz");
static const u16 gIntro2MayPalette[] = INCBIN_U16("graphics/intro/intro2_may.gbapal");
static const u16 gUnknown_085F3490[0xF0] = {0};
static const u32 gIntro2MayTiles[] = INCBIN_U32("graphics/intro/intro2_may.4bpp.lz");
static const u32 gIntro2BicycleTiles[] = INCBIN_U32("graphics/intro/intro2_bicycle.4bpp.lz");
static const u16 gIntro2LatiosPalette[] = INCBIN_U16("graphics/intro/intro2_latios.gbapal");
static const u32 gIntro2LatiosTiles[] = INCBIN_U32("graphics/intro/intro2_latios.4bpp.lz");
static const u16 gIntro2LatiasPalette[] = INCBIN_U16("graphics/intro/intro2_latias.gbapal");
static const u32 gIntro2LatiasTiles[] = INCBIN_U32("graphics/intro/intro2_latias.4bpp.lz");

static void sub_817B62C(struct Sprite *sprite);
static void nullsub_65(struct Sprite *sprite);
static void sub_817B7C4(struct Sprite *sprite);
static void nullsub_66(struct Sprite *sprite);

static const struct SpriteTemplate gUnknown_085F504C =
{
    .tileTag = 2000,
    .paletteTag = 0xFFFF,
    .oam = &gDummyOamData,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_817B62C
};

static const struct CompressedSpriteSheet gUnknown_085F5064[] =
{
    {
        .data = gUnknown_085F16A8,
        .size = 0x400,
        .tag = 2000
    },
    {}
};

static const union AnimCmd gUnknown_085F5074[] =
{
    ANIMCMD_FRAME( 0, 30),
    ANIMCMD_END
};

static const union AnimCmd gUnknown_085F507C[] =
{
    ANIMCMD_FRAME(16, 30),
    ANIMCMD_END
};

static const union AnimCmd gUnknown_085F5084[] =
{
    ANIMCMD_FRAME(20, 30),
    ANIMCMD_END
};

static const union AnimCmd gUnknown_085F508C[] =
{
    ANIMCMD_FRAME(22, 30),
    ANIMCMD_END
};

static const union AnimCmd *const gUnknown_085F5094[] =
{
    gUnknown_085F5074,
    gUnknown_085F507C,
    gUnknown_085F5084,
    gUnknown_085F508C
};

static const struct IntroCreditsSpriteMetadata gUnknown_085F50A4[] =
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

static const struct CompressedSpriteSheet gUnknown_085F50EC[] =
{
    {
        .data = gIntro2TreeTiles,
        .size = 0x400,
        .tag = 2000
    },
    {}
};

static const union AnimCmd gUnknown_085F50FC[] =
{
    ANIMCMD_FRAME( 0, 30),
    ANIMCMD_END
};

static const union AnimCmd gUnknown_085F5104[] =
{
    ANIMCMD_FRAME(16, 30),
    ANIMCMD_END
};

static const union AnimCmd gUnknown_085F510C[] =
{
    ANIMCMD_FRAME(24, 30),
    ANIMCMD_END
};

static const union AnimCmd *const gUnknown_085F5114[] =
{
    gUnknown_085F50FC,
    gUnknown_085F5104,
    gUnknown_085F510C
};

static const struct IntroCreditsSpriteMetadata gUnknown_085F5120[] =
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

static const struct CompressedSpriteSheet gUnknown_085F5180[] =
{
    {
        .data = gIntro2NightTiles,
        .size = 0x400,
        .tag = 2000
    },
    {}
};

static const union AnimCmd gUnknown_085F5190[] =
{
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_END
};

static const union AnimCmd *const gUnknown_085F5198[] =
{
    gUnknown_085F5190
};

static const struct IntroCreditsSpriteMetadata gUnknown_085F519C[] =
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

static const struct OamData gOamData_85F51CC =
{
    .y = 160,
    .shape = SPRITE_SHAPE(64x64),
    .size = SPRITE_SIZE(64x64),
    .priority = 1
};

static const union AnimCmd gUnknown_085F51D4[] =
{
    ANIMCMD_FRAME(  0, 8),
    ANIMCMD_FRAME( 64, 8),
    ANIMCMD_FRAME(128, 8),
    ANIMCMD_FRAME(192, 8),
    ANIMCMD_JUMP(0)
};

static const union AnimCmd *const gUnknown_085F51E8[] =
{
    gUnknown_085F51D4
};

static const struct SpriteTemplate gUnknown_085F51EC =
{
    .tileTag = 1002,
    .paletteTag = 1002,
    .oam = &gOamData_85F51CC,
    .anims = gUnknown_085F51E8,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = nullsub_65
};

static const struct SpriteTemplate gUnknown_085F5204 =
{
    .tileTag = 1003,
    .paletteTag = 1003,
    .oam = &gOamData_85F51CC,
    .anims = gUnknown_085F51E8,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = nullsub_65
};

static const struct OamData gUnknown_085F521C =
{
    .y = 160,
    .shape = SPRITE_SHAPE(64x32),
    .size = SPRITE_SIZE(64x32),
    .priority = 1
};

static const union AnimCmd gUnknown_085F5224[] =
{
    ANIMCMD_FRAME(  0, 8),
    ANIMCMD_FRAME( 32, 8),
    ANIMCMD_FRAME( 64, 8),
    ANIMCMD_FRAME( 96, 8),
    ANIMCMD_JUMP(0)
};

static const union AnimCmd *const gUnknown_085F5238[] =
{
    gUnknown_085F5224
};

static const struct SpriteTemplate gUnknown_085F523C =
{
    .tileTag = 1001,
    .paletteTag = 1002,
    .oam = &gUnknown_085F521C,
    .anims = gUnknown_085F5238,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_817B7C4
};

static const struct SpriteTemplate gUnknown_085F5254 =
{
    .tileTag = 1001,
    .paletteTag = 1003,
    .oam = &gUnknown_085F521C,
    .anims = gUnknown_085F5238,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_817B7C4
};

static const struct OamData gUnknown_085F526C =
{
    .y = 160,
    .shape = SPRITE_SHAPE(64x64),
    .size = SPRITE_SIZE(64x64),
    .priority = 1
};

static const union AnimCmd gUnknown_085F5274[] =
{
    ANIMCMD_FRAME(  0, 16),
    ANIMCMD_END
};

static const union AnimCmd gUnknown_085F527C[] =
{
    ANIMCMD_FRAME( 64, 16),
    ANIMCMD_END
};

static const union AnimCmd *const gUnknown_085F5284[] =
{
    gUnknown_085F5274,
    gUnknown_085F527C
};

static const struct SpriteTemplate gUnknown_085F528C =
{
    .tileTag = 1004,
    .paletteTag = 1004,
    .oam = &gUnknown_085F526C,
    .anims = gUnknown_085F5284,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = nullsub_66
};

static const struct SpriteTemplate gUnknown_085F52A4 =
{
    .tileTag = 1005,
    .paletteTag = 1005,
    .oam = &gUnknown_085F526C,
    .anims = gUnknown_085F5284,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = nullsub_66
};

const struct CompressedSpriteSheet gIntro2BrendanSpriteSheet[] =
{
    {
        .data = gIntro2BrendanNoTurnGfx,
        .size = 0x2000,
        .tag = 1002
    },
    {}
};

const struct CompressedSpriteSheet gIntro2MaySpriteSheet[] =
{
    {
        .data = gIntro2MayNoTurnGfx,
        .size = 0x2000,
        .tag = 1003
    },
    {}
};

const struct CompressedSpriteSheet gIntro2BicycleSpriteSheet[] =
{
    {
        .data = gIntro2BicycleTiles,
        .size = 0x1000,
        .tag = 1001
    },
    {}
};

static const struct CompressedSpriteSheet gUnknown_085F52EC[] =
{
    {
        .data = gIntro2FlygonGfx,
        .size = 0x1000,
        .tag = 1004
    },
    {}
};

const struct CompressedSpriteSheet gIntro2FlygonSpriteSheet[] =
{
    {
        .data = gIntro2FlygonGfx,
        .size = 0x1000,
        .tag = 1005
    },
    {}
};

const struct SpritePalette gIntroBikeAndFlygonPalette[] =
{
    { .data = gIntro2BrendanNoTurnPal, .tag = 1002 },
    { .data = gIntro2BrendanNoTurnPal, .tag = 1003 },
    { .data = gIntro2FlygonPal,        .tag = 1004 },
    { .data = gIntro2FlygonPal,        .tag = 1005 },
    {}
};

const struct CompressedSpriteSheet gUnknown_085F5334[] =
{
    {
        .data = gIntro2BrendanTiles,
        .size = 0x3800,
        .tag = 1002
    },
    {}
};

const struct CompressedSpriteSheet gUnknown_085F5344[] =
{
    {
        .data = gIntro2MayTiles,
        .size = 0x3800,
        .tag = 1003
    },
    {}
};

const struct CompressedSpriteSheet gUnknown_085F5354[] =
{
    {
        .data = gIntro2BicycleTiles,
        .size = 0x1000,
        .tag = 1001
    },
    {}
};

static const struct CompressedSpriteSheet gUnknown_085F5364[] =
{
    {
        .data = gIntro2LatiosTiles,
        .size = 0x1000,
        .tag = 1004
    },
    {}
};

static const struct CompressedSpriteSheet gUnknown_085F5374[] =
{
    {
        .data = gIntro2LatiasTiles,
        .size = 0x1000,
        .tag = 1005
    },
    {}
};

const struct SpritePalette gUnknown_085F5384[] =
{
    { .data = gIntro2BrendanPalette, .tag = 1002 },
    { .data = gIntro2MayPalette,     .tag = 1003 },
    { .data = gIntro2LatiosPalette,  .tag = 1004 },
    { .data = gIntro2LatiasPalette,  .tag = 1005 },
    {}
};

const struct CompressedSpriteSheet gUnknown_085F53AC[] =
{
    {
        .data = gIntro2BrendanTiles,
        .size = 0x2000,
        .tag = 1002
    },
    {}
};

const struct CompressedSpriteSheet gUnknown_085F53BC[] =
{
    {
        .data = gIntro2MayTiles,
        .size = 0x2000,
        .tag = 1003
    },
    {}
};

EWRAM_DATA u16 gUnknown_0203BD24 = 0;
EWRAM_DATA s16 gUnknown_0203BD26 = 0;
EWRAM_DATA s16 gUnknown_0203BD28 = 0;

static void sub_817B76C(void);
static void sub_817B788(void);
static void sub_817B7A4(void);
static void sub_817B458(u8);

void load_intro_part2_graphics(u8 a)
{
    LZ77UnCompVram(gUnknown_085F0740, (void *)(BG_CHAR_ADDR(1)));
    LZ77UnCompVram(gUnknown_085F0BC0, (void *)(BG_SCREEN_ADDR(15)));
    LoadPalette(&gUnknown_085F06E0, 240, 32);
    switch (a)
    {
    case 0:
    default:
        LZ77UnCompVram(gUnknown_085F0DBC, (void *)(VRAM));
        LZ77UnCompVram(gUnknown_085F1398, (void *)(BG_SCREEN_ADDR(6)));
        LoadPalette(&gUnknown_085F0CFC, 0, 96);
        LoadCompressedSpriteSheet(gUnknown_085F5064);
        LoadPalette(&gUnknown_085F1668, 256, 32);
        sub_817B76C();
        break;
    case 1:
        LZ77UnCompVram(gUnknown_085F1824, (void *)(VRAM));
        LZ77UnCompVram(gUnknown_085F1EAC, (void *)(BG_SCREEN_ADDR(6)));
        LoadPalette(&gUnknown_085F17E4, 0, 32);
        LoadCompressedSpriteSheet(gUnknown_085F50EC);
        LoadPalette(&gUnknown_085F21B0, 256, 32);
        sub_817B788();
        break;
    }
    gUnknown_0203BD28 = 0;
    gReservedSpritePaletteCount = 8;
}

// Note: This is only called with a=1.
void sub_817B150(u8 a)
{
    switch (a)
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

void sub_817B1C8(u8 a)
{
    LZ77UnCompVram(gUnknown_085F0740, (void *)(BG_CHAR_ADDR(1)));
    LZ77UnCompVram(gUnknown_085F0BC0, (void *)(BG_SCREEN_ADDR(15)));
    switch (a)
    {
    case 0:
    default:
        LoadPalette(&gUnknown_085F06E0, 240, 32);
        LZ77UnCompVram(gUnknown_085F0DBC, (void *)(VRAM));
        LZ77UnCompVram(gUnknown_085F1398, (void *)(BG_SCREEN_ADDR(6)));
        LoadPalette(&gUnknown_085F0CFC, 0, 96);
        LoadCompressedSpriteSheet(gUnknown_085F5064);
        LZ77UnCompVram(gUnknown_085F16A8, (void *)(OBJ_VRAM0));
        LoadPalette(&gUnknown_085F1668, 256, 32);
        sub_817B76C();
        break;
    case 1:
        LoadPalette(&gUnknown_085F0700, 240, 32);
        LZ77UnCompVram(gUnknown_085F0DBC, (void *)(VRAM));
        LZ77UnCompVram(gUnknown_085F1398, (void *)(BG_SCREEN_ADDR(6)));
        LoadPalette(&gUnknown_085F0D5C, 0, 96);
        LoadCompressedSpriteSheet(gUnknown_085F5064);
        LZ77UnCompVram(gUnknown_085F16A8, (void *)(OBJ_VRAM0));
        LoadPalette(&gUnknown_085F1688, 256, 32);
        sub_817B76C();
        break;
    case 2:
    case 3:
        LoadPalette(&gUnknown_085F0700, 240, 32);
        LZ77UnCompVram(gUnknown_085F1824, (void *)(VRAM));
        LZ77UnCompVram(gUnknown_085F1EAC, (void *)(BG_SCREEN_ADDR(6)));
        LoadPalette(&gUnknown_085F1804, 0, 32);
        LoadCompressedSpriteSheet(gUnknown_085F50EC);
        LoadPalette(&gUnknown_085F1804, 256, 32);
        sub_817B788();
        break;
    case 4:
        LoadPalette(&gUnknown_085F0720, 240, 32);
        LZ77UnCompVram(gUnknown_085F235C, (void *)(VRAM));
        LZ77UnCompVram(gUnknown_085F2568, (void *)(BG_SCREEN_ADDR(6)));
        LoadPalette(&gUnknown_085F231C, 0, 64);
        LoadCompressedSpriteSheet(gUnknown_085F5180);
        LoadPalette(&gUnknown_085F2548, 256, 32);
        sub_817B7A4();
        break;
    }
    gReservedSpritePaletteCount = 8;
    gUnknown_0203BD28 = 0;
}

void sub_817B3A8(u8 a)
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

u8 CreateBicycleAnimationTask(u8 a, u16 b, u16 c, u16 d)
{
    u8 taskId = CreateTask(&sub_817B458, 0);

    gTasks[taskId].data[0] = a;
    gTasks[taskId].data[1] = b;
    gTasks[taskId].data[2] = 0;
    gTasks[taskId].data[3] = 0;
    gTasks[taskId].data[4] = c;
    gTasks[taskId].data[5] = 0;
    gTasks[taskId].data[6] = 0;
    gTasks[taskId].data[7] = d;
    gTasks[taskId].data[8] = 8;
    gTasks[taskId].data[9] = 0;
    sub_817B458(taskId);
    return taskId;
}

static void sub_817B458(u8 taskId)
{
    s16 data1;
    s16 data4;
    s16 data7;
    s32 r2;

    data1 = gTasks[taskId].data[1];
    if (data1 != 0)
    {
        r2 = (gTasks[taskId].data[2] << 16) + (u16)gTasks[taskId].data[3];
        r2 -= (u16)data1 << 4;
        gTasks[taskId].data[2] = r2 >> 16;
        gTasks[taskId].data[3] = r2;
        SetGpuReg(REG_OFFSET_BG1HOFS, gTasks[taskId].data[2]);
        SetGpuReg(REG_OFFSET_BG1VOFS, gUnknown_0203BD24 + gUnknown_0203BD26);
    }

    data4 = gTasks[taskId].data[4];
    if (data4 != 0)
    {
        r2 = (gTasks[taskId].data[5] << 16) + (u16)gTasks[taskId].data[6];
        r2 -= (u16)data4 << 4;
        gTasks[taskId].data[5] = r2 >> 16;
        gTasks[taskId].data[6] = r2;
        SetGpuReg(REG_OFFSET_BG2HOFS, gTasks[taskId].data[5]);
        if (gTasks[taskId].data[0] != 0)
            SetGpuReg(REG_OFFSET_BG2VOFS, gUnknown_0203BD24 + gUnknown_0203BD26);
        else
            SetGpuReg(REG_OFFSET_BG2VOFS, gUnknown_0203BD24);
    }

    data7 = gTasks[taskId].data[7];
    if (data7 != 0)
    {
        r2 = (gTasks[taskId].data[8] << 16) + (u16)gTasks[taskId].data[9];
        r2 -= (u16)data7 << 4;
        gTasks[taskId].data[8] = r2 >> 16;
        gTasks[taskId].data[9] = r2;
        SetGpuReg(REG_OFFSET_BG3HOFS, gTasks[taskId].data[8]);
        SetGpuReg(REG_OFFSET_BG3VOFS, gUnknown_0203BD24);
    }
}

void sub_817B540(u8 mode)
{
    u16 x;
    u16 y;
    switch (mode)
    {
        case 0:
        default:
            /* stuff */
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
            LoadPalette(&x, 9, 2);
            LoadPalette(&y, 10, 2);
            break;
        case 2:
            if (gMain.vblankCounter1 & 3 || gPaletteFade.active)
                break;
            if (gMain.vblankCounter1 & 4)
            {
                x = 0x3D27;
                y = 0x295;
            }
            else
            {
                x = 0x31C;
                y = 0x3D27;
            }
            LoadPalette(&x, 12, 2);
            LoadPalette(&y, 13, 2);
            break;
        case 1:
            break;
    }
}

static void sub_817B62C(struct Sprite *sprite)
{
    s32 var;
    s16 var2 = gUnknown_0203BD28;
    
    if (var2 != 2)
    {
        switch (var2)
        {
        default:
            DestroySprite(sprite);
            break;
        case 0:
            var = ((sprite->pos1.x << 16) | (u16)sprite->data[2]) + (u16)sprite->data[1];
            sprite->pos1.x = var >> 16;
            sprite->data[2] = var;
            if (sprite->pos1.x > 0xFF)
                sprite->pos1.x = -0x20;
            if (sprite->data[0])
                sprite->pos2.y = -(gUnknown_0203BD24 + gUnknown_0203BD26);
            else
                sprite->pos2.y = -gUnknown_0203BD24;
            break;
        }
    }
}

static void sub_817B698(u8 a, const struct IntroCreditsSpriteMetadata *b, const union AnimCmd *const *c, u8 d)
{
    u8 i;

    for(i = 0; i < d; i++)
    {
        u8 sprite = CreateSprite(&gUnknown_085F504C, b[i].x, b[i].y, b[i].subpriority);
        CalcCenterToCornerVec(&gSprites[sprite], b[i].shape, b[i].size, ST_OAM_AFFINE_OFF);
        gSprites[sprite].oam.priority = 3;
        gSprites[sprite].oam.shape = b[i].shape;
        gSprites[sprite].oam.size = b[i].size;
        gSprites[sprite].oam.paletteNum = 0;
        gSprites[sprite].anims = c;
        StartSpriteAnim(&gSprites[sprite], b[i].animNum);
        gSprites[sprite].data[0] = a;
        gSprites[sprite].data[1] = b[i].xOff;
        gSprites[sprite].data[2] = 0;
    }
}

static void sub_817B76C(void)
{
    sub_817B698(0, gUnknown_085F50A4, gUnknown_085F5094, 9);
}

static void sub_817B788(void)
{
    sub_817B698(1, gUnknown_085F5120, gUnknown_085F5114, 12);
}

static void sub_817B7A4(void)
{
    sub_817B698(1, gUnknown_085F519C, gUnknown_085F5198, 6);
}

static void nullsub_65(struct Sprite *sprite)
{
}

static void sub_817B7C4(struct Sprite* sprite)
{
    sprite->invisible = gSprites[sprite->data[0]].invisible;
    sprite->pos1.x = gSprites[sprite->data[0]].pos1.x;
    sprite->pos1.y = gSprites[sprite->data[0]].pos1.y + 8;
    sprite->pos2.x = gSprites[sprite->data[0]].pos2.x;
    sprite->pos2.y = gSprites[sprite->data[0]].pos2.y;
}

u8 intro_create_brendan_sprite(s16 a, s16 b)
{
    u8 sprite = CreateSprite(&gUnknown_085F51EC, a, b, 2);
    u8 brendan = CreateSprite(&gUnknown_085F523C, a, b + 8, 3);
    gSprites[brendan].data[0] = sprite;
    return sprite;
}

u8 intro_create_may_sprite(s16 a, s16 b)
{
    u8 sprite = CreateSprite(&gUnknown_085F5204, a, b, 2);
    u8 may = CreateSprite(&gUnknown_085F5254, a, b + 8, 3);
    gSprites[may].data[0] = sprite;
    return sprite;
}

static void nullsub_66(struct Sprite *sprite)
{
}

static void sub_817B8E8(struct Sprite* sprite)
{
    sprite->invisible = gSprites[sprite->data[0]].invisible;
    sprite->pos1.y = gSprites[sprite->data[0]].pos1.y;
    sprite->pos2.x = gSprites[sprite->data[0]].pos2.x;
    sprite->pos2.y = gSprites[sprite->data[0]].pos2.y;
}

static u8 sub_817B948(s16 a, s16 b)
{
    u8 sprite = CreateSprite(&gUnknown_085F528C, a - 32, b, 5);
    u8 latios = CreateSprite(&gUnknown_085F528C, a + 32, b, 6);
    gSprites[latios].data[0] = sprite;
    StartSpriteAnim(&gSprites[latios], 1);
    gSprites[latios].callback = &sub_817B8E8;
    return sprite;
}

u8 intro_create_flygon_sprite(s16 a, s16 b)
{
    u8 sprite = CreateSprite(&gUnknown_085F52A4, a - 32, b, 5);
    u8 flygon = CreateSprite(&gUnknown_085F52A4, a + 32, b, 6);
    gSprites[flygon].data[0] = sprite;
    StartSpriteAnim(&gSprites[flygon], 1);
    gSprites[flygon].callback = &sub_817B8E8;
    return sprite;
}
