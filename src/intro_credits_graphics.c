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

static const struct SpriteTemplate gUnknown_085F504C = {
    2000, 0xFFFF, &gDummyOamData, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, sub_817B62C
};

static const struct CompressedSpriteSheet gUnknown_085F5064[] = {
    { gUnknown_085F16A8, 0x400, 2000 },
    { NULL }
};

static const union AnimCmd gUnknown_085F5074[] = {
    ANIMCMD_FRAME( 0, 30),
    ANIMCMD_END
};

static const union AnimCmd gUnknown_085F507C[] = {
    ANIMCMD_FRAME(16, 30),
    ANIMCMD_END
};

static const union AnimCmd gUnknown_085F5084[] = {
    ANIMCMD_FRAME(20, 30),
    ANIMCMD_END
};

static const union AnimCmd gUnknown_085F508C[] = {
    ANIMCMD_FRAME(22, 30),
    ANIMCMD_END
};

static const union AnimCmd *const gUnknown_085F5094[] = {
    gUnknown_085F5074,
    gUnknown_085F507C,
    gUnknown_085F5084,
    gUnknown_085F508C
};

static const struct IntroCreditsSpriteMetadata gUnknown_085F50A4[] = {
    {  0, ST_OAM_SQUARE,      2,   72, 32, 100, 0xc00 },
    {  0, ST_OAM_SQUARE,      2,  158, 32, 100, 0xc00 },
    {  1, ST_OAM_SQUARE,      1,  192, 40, 101, 0x800 },
    {  1, ST_OAM_SQUARE,      1,   56, 40, 101, 0x800 },
    {  2, ST_OAM_H_RECTANGLE, 0,  100, 44, 102, 0x400 },
    {  2, ST_OAM_H_RECTANGLE, 0,  152, 44, 102, 0x400 },
    {  3, ST_OAM_H_RECTANGLE, 0,    8, 46, 103, 0x100 },
    {  3, ST_OAM_H_RECTANGLE, 0,   56, 46, 103, 0x100 },
    {  3, ST_OAM_H_RECTANGLE, 0,  240, 46, 103, 0x100 },
};

static const struct CompressedSpriteSheet gUnknown_085F50EC[] = {
    { gIntro2TreeTiles, 0x400, 2000 },
    { NULL }
};

static const union AnimCmd gUnknown_085F50FC[] = {
    ANIMCMD_FRAME( 0, 30),
    ANIMCMD_END
};

static const union AnimCmd gUnknown_085F5104[] = {
    ANIMCMD_FRAME(16, 30),
    ANIMCMD_END
};

static const union AnimCmd gUnknown_085F510C[] = {
    ANIMCMD_FRAME(24, 30),
    ANIMCMD_END
};

static const union AnimCmd *const gUnknown_085F5114[] = {
    gUnknown_085F50FC,
    gUnknown_085F5104,
    gUnknown_085F510C
};

static const struct IntroCreditsSpriteMetadata gUnknown_085F5120[] = {
    {  0, ST_OAM_SQUARE,      2,   16, 88, 100, 0x2000 },
    {  0, ST_OAM_SQUARE,      2,   80, 88, 100, 0x2000 },
    {  0, ST_OAM_SQUARE,      2,  144, 88, 100, 0x2000 },
    {  0, ST_OAM_SQUARE,      2,  208, 88, 100, 0x2000 },
    {  1, ST_OAM_V_RECTANGLE, 2,   40, 88, 101, 0x1000 },
    {  1, ST_OAM_V_RECTANGLE, 2,  104, 88, 101, 0x1000 },
    {  1, ST_OAM_V_RECTANGLE, 2,  168, 88, 101, 0x1000 },
    {  1, ST_OAM_V_RECTANGLE, 2,  232, 88, 101, 0x1000 },
    {  2, ST_OAM_V_RECTANGLE, 2,   56, 88, 102, 0x800  },
    {  2, ST_OAM_V_RECTANGLE, 2,  120, 88, 102, 0x800  },
    {  2, ST_OAM_V_RECTANGLE, 2,  184, 88, 102, 0x800  },
    {  2, ST_OAM_V_RECTANGLE, 2,  248, 88, 102, 0x800  },
};

static const struct CompressedSpriteSheet gUnknown_085F5180[] = {
    { gIntro2NightTiles, 0x400, 2000 },
    { NULL }
};

static const union AnimCmd gUnknown_085F5190[] = {
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_END
};

static const union AnimCmd *const gUnknown_085F5198[] = {
    gUnknown_085F5190
};

static const struct IntroCreditsSpriteMetadata gUnknown_085F519C[] = {
    { 0, ST_OAM_SQUARE, 2,   24, 88, 100, 0x1000 },
    { 0, ST_OAM_SQUARE, 2,   64, 88, 100, 0x1000 },
    { 0, ST_OAM_SQUARE, 2,  104, 88, 100, 0x1000 },
    { 0, ST_OAM_SQUARE, 2,  144, 88, 100, 0x1000 },
    { 0, ST_OAM_SQUARE, 2,  184, 88, 100, 0x1000 },
    { 0, ST_OAM_SQUARE, 2,  224, 88, 100, 0x1000 },
};

static const struct OamData gOamData_85F51CC = {
    .y = 160, .shape = ST_OAM_SQUARE, .size = 3, .priority = 1
};

static const union AnimCmd gUnknown_085F51D4[] = {
    ANIMCMD_FRAME(  0, 8),
    ANIMCMD_FRAME( 64, 8),
    ANIMCMD_FRAME(128, 8),
    ANIMCMD_FRAME(192, 8),
    ANIMCMD_JUMP(0)
};

static const union AnimCmd *const gUnknown_085F51E8[] = {
    gUnknown_085F51D4
};

static const struct SpriteTemplate gUnknown_085F51EC = {
    1002, 1002, &gOamData_85F51CC, gUnknown_085F51E8, NULL, gDummySpriteAffineAnimTable, nullsub_65
};

static const struct SpriteTemplate gUnknown_085F5204 = {
    1003, 1003, &gOamData_85F51CC, gUnknown_085F51E8, NULL, gDummySpriteAffineAnimTable, nullsub_65
};

static const struct OamData gUnknown_085F521C = {
    .y = 160, .shape = ST_OAM_H_RECTANGLE, .size = 3, .priority = 1
};

static const union AnimCmd gUnknown_085F5224[] = {
    ANIMCMD_FRAME(  0, 8),
    ANIMCMD_FRAME( 32, 8),
    ANIMCMD_FRAME( 64, 8),
    ANIMCMD_FRAME( 96, 8),
    ANIMCMD_JUMP(0)
};

static const union AnimCmd *const gUnknown_085F5238[] = {
    gUnknown_085F5224
};

static const struct SpriteTemplate gUnknown_085F523C = {
    1001, 1002, &gUnknown_085F521C, gUnknown_085F5238, NULL, gDummySpriteAffineAnimTable, sub_817B7C4
};

static const struct SpriteTemplate gUnknown_085F5254 = {
    1001, 1003, &gUnknown_085F521C, gUnknown_085F5238, NULL, gDummySpriteAffineAnimTable, sub_817B7C4
};

static const struct OamData gUnknown_085F526C = {
    .y = 160, .shape = ST_OAM_SQUARE, .size = 3, .priority = 1
};

static const union AnimCmd gUnknown_085F5274[] = {
    ANIMCMD_FRAME(  0, 16),
    ANIMCMD_END
};

static const union AnimCmd gUnknown_085F527C[] = {
    ANIMCMD_FRAME( 64, 16),
    ANIMCMD_END
};

static const union AnimCmd *const gUnknown_085F5284[] = {
    gUnknown_085F5274,
    gUnknown_085F527C
};

static const struct SpriteTemplate gUnknown_085F528C = {
    1004, 1004, &gUnknown_085F526C, gUnknown_085F5284, NULL, gDummySpriteAffineAnimTable, nullsub_66
};

static const struct SpriteTemplate gUnknown_085F52A4 = {
    1005, 1005, &gUnknown_085F526C, gUnknown_085F5284, NULL, gDummySpriteAffineAnimTable, nullsub_66
};

const struct CompressedSpriteSheet gIntro2BrendanSpriteSheet[] = {
    { gIntro2BrendanNoTurnGfx, 0x2000, 1002 },
    { NULL }
};

const struct CompressedSpriteSheet gIntro2MaySpriteSheet[] = {
    { gIntro2MayNoTurnGfx, 0x2000, 1003 },
    { NULL }
};

const struct CompressedSpriteSheet gIntro2BicycleSpriteSheet[] = {
    { gIntro2BicycleTiles, 0x1000, 1001 },
    { NULL }
};

static const struct CompressedSpriteSheet gUnknown_085F52EC[] = {
    { gIntro2FlygonGfx, 0x1000, 1004 },
    { NULL }
};

const struct CompressedSpriteSheet gIntro2FlygonSpriteSheet[] = {
    { gIntro2FlygonGfx, 0x1000, 1005 },
    { NULL }
};

const struct SpritePalette gUnknown_085F530C[] = {
    { gIntro2BrendanNoTurnPal, 1002 },
    { gIntro2BrendanNoTurnPal, 1003 },
    { gIntro2FlygonPal,        1004 },
    { gIntro2FlygonPal,        1005 },
    { NULL }
};

const struct CompressedSpriteSheet gUnknown_085F5334[] = {
    { gIntro2BrendanTiles, 0x3800, 1002 },
    { NULL }
};

const struct CompressedSpriteSheet gUnknown_085F5344[] = {
    { gIntro2MayTiles, 0x3800, 1003 },
    { NULL }
};

const struct CompressedSpriteSheet gUnknown_085F5354[] = {
    { gIntro2BicycleTiles, 0x1000, 1001 },
    { NULL }
};

static const struct CompressedSpriteSheet gUnknown_085F5364[] = {
    { gIntro2LatiosTiles, 0x1000, 1004 },
    { NULL }
};

static const struct CompressedSpriteSheet gUnknown_085F5374[] = {
    { gIntro2LatiasTiles, 0x1000, 1005 },
    { NULL }
};

const struct SpritePalette gUnknown_085F5384[] = {
    { gIntro2BrendanPalette, 1002 },
    { gIntro2MayPalette,     1003 },
    { gIntro2LatiosPalette,  1004 },
    { gIntro2LatiasPalette,  1005 },
    { NULL }
};

const struct CompressedSpriteSheet gUnknown_085F53AC[] = {
    { gIntro2BrendanTiles, 0x2000, 1002},
    { NULL }
};

const struct CompressedSpriteSheet gUnknown_085F53BC[] = {
    { gIntro2MayTiles, 0x2000, 1003},
    { NULL }
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
    LZ77UnCompVram(gUnknown_085F0740, (void *)(VRAM + 0x4000));
    LZ77UnCompVram(gUnknown_085F0BC0, (void *)(VRAM + 0x7800));
    LoadPalette(&gUnknown_085F06E0, 240, 32);
    switch (a)
    {
    case 0:
    default:
        LZ77UnCompVram(gUnknown_085F0DBC, (void *)(VRAM));
        LZ77UnCompVram(gUnknown_085F1398, (void *)(VRAM + 0x3000));
        LoadPalette(&gUnknown_085F0CFC, 0, 96);
        LoadCompressedSpriteSheet(gUnknown_085F5064);
        LoadPalette(&gUnknown_085F1668, 256, 32);
        sub_817B76C();
        break;
    case 1:
        LZ77UnCompVram(gUnknown_085F1824, (void *)(VRAM));
        LZ77UnCompVram(gUnknown_085F1EAC, (void *)(VRAM + 0x3000));
        LoadPalette(&gUnknown_085F17E4, 0, 32);
        LoadCompressedSpriteSheet(gUnknown_085F50EC);
        LoadPalette(&gUnknown_085F21B0, 256, 32);
        sub_817B788();
        break;
    }
    gUnknown_0203BD28 = 0;
    gReservedSpritePaletteCount = 8;
}

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
    LZ77UnCompVram(gUnknown_085F0740, (void *)(VRAM + 0x4000));
    LZ77UnCompVram(gUnknown_085F0BC0, (void *)(VRAM + 0x7800));
    switch (a)
    {
    case 0:
    default:
        LoadPalette(&gUnknown_085F06E0, 240, 32);
        LZ77UnCompVram(gUnknown_085F0DBC, (void *)(VRAM));
        LZ77UnCompVram(gUnknown_085F1398, (void *)(VRAM + 0x3000));
        LoadPalette(&gUnknown_085F0CFC, 0, 96);
        LoadCompressedSpriteSheet(gUnknown_085F5064);
        LZ77UnCompVram(gUnknown_085F16A8, (void *)(VRAM + 0x10000));
        LoadPalette(&gUnknown_085F1668, 256, 32);
        sub_817B76C();
        break;
    case 1:
        LoadPalette(&gUnknown_085F0700, 240, 32);
        LZ77UnCompVram(gUnknown_085F0DBC, (void *)(VRAM));
        LZ77UnCompVram(gUnknown_085F1398, (void *)(VRAM + 0x3000));
        LoadPalette(&gUnknown_085F0D5C, 0, 96);
        LoadCompressedSpriteSheet(gUnknown_085F5064);
        LZ77UnCompVram(gUnknown_085F16A8, (void *)(VRAM + 0x10000));
        LoadPalette(&gUnknown_085F1688, 256, 32);
        sub_817B76C();
        break;
    case 2:
    case 3:
        LoadPalette(&gUnknown_085F0700, 240, 32);
        LZ77UnCompVram(gUnknown_085F1824, (void *)(VRAM));
        LZ77UnCompVram(gUnknown_085F1EAC, (void *)(VRAM + 0x3000));
        LoadPalette(&gUnknown_085F1804, 0, 32);
        LoadCompressedSpriteSheet(gUnknown_085F50EC);
        LoadPalette(&gUnknown_085F1804, 256, 32);
        sub_817B788();
        break;
    case 4:
        LoadPalette(&gUnknown_085F0720, 240, 32);
        LZ77UnCompVram(gUnknown_085F235C, (void *)(VRAM));
        LZ77UnCompVram(gUnknown_085F2568, (void *)(VRAM + 0x3000));
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

u8 sub_817B3DC(u8 a, u16 b, u16 c, u16 d)
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
        CalcCenterToCornerVec(&gSprites[sprite], b[i].shape, b[i].size, 0);
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
