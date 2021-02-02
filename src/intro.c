#include "global.h"
#include "main.h"
#include "palette.h"
#include "scanline_effect.h"
#include "task.h"
#include "title_screen.h"
#include "libgcnmultiboot.h"
#include "malloc.h"
#include "gpu_regs.h"
#include "link.h"
#include "multiboot_pokemon_colosseum.h"
#include "load_save.h"
#include "save.h"
#include "new_game.h"
#include "m4a.h"
#include "random.h"
#include "decompress.h"
#include "constants/songs.h"
#include "intro_credits_graphics.h"
#include "trig.h"
#include "intro.h"
#include "graphics.h"
#include "sound.h"
#include "util.h"
#include "title_screen.h"
#include "constants/rgb.h"
#include "constants/battle_anim.h"

/*
 * Intro animation sequence state machine
 * --------------------------------------
 * 
 * Entry Point: CB2_InitCopyrightScreenAfterBootup
 * 
 * Note: States advance sequentially unless otherwise stated.
 * 
 * CB2_InitCopyrightScreenAfterBootup
 *  - Registers a serial interrupt handler that listens for a GameCube.
 *  - Waits for 140 frames, and then until palette fading completes.
 *  - Stops looking for a GameCube for dualboot.
 *  - Check the save file for corruption
 *  - Setup global pointers to save file
 *  - Initialize gHeap
 * 
 * MainCB2_Intro
 *  - Spawn Task_IntroLoadPart1Graphics
 *  - If any keys are pressed during the intro, advance to
 *    MainCB2_EndIntro (which will then kill all tasks).
 * 
 * Task_IntroLoadPart1Graphics
 * Task_IntroFadeIn (frame counter starts at 0 here)
 * Task_IntroWaterDrops
 *  - At frame 128 of this state, spawn Task_IntroWaterDrops_1
 *  - At frame 256 of this state, spawn Task_IntroWaterDrops_2
 *  - At frame 560 of this state, spawn Task_IntroWaterDrops_3
 * Task_IntroScrollDownAndShowFlygon
 * Task_IntroWaitToSetupPart2
 * Task_IntroLoadPart2Graphics
 * Task_IntroStartBikeRide
 *  - Spawn Task_AdvanceBicycleAnimation
 * Task_IntroHandleBikeAndFlygonMovement
 *  - At frame 1856, kills the bicycle animation task
 * Task_IntroWaitToSetupPart3
 * Task_IntroLoadPart3Graphics (frame counter resets to 0 here)
 * Task_IntroSpinAndZoomPokeball
 *  - Continues until the zoom reaches a certain point
 * Task_IntroWaitToSetupPart3LegendsFight
 * Task_IntroLoadGroudonScene
 * Task_IntroLoadPart3Graphics1
 * Task_IntroLoadPart3Graphics2
 * Task_IntroLoadPart3Graphics3
 * Task_IntroLoadPart3Graphics4
 * Task_IntroGroudonScene
 * Task_IntroLoadKyogreScene
 * Task_IntroKyogreScene
 * Task_IntroLoadClouds1
 * Task_IntroLoadClouds2
 * Task_IntroLoadClouds3
 * Task_IntroCloudsScene
 * Task_IntroLoadRayquazaLightningScene
 * Task_IntroRayquazaLightningScene
 * Task_IntroLoadRayquazaGlowScene
 * Task_IntroRayquazaGlowScene_0
 *  - Runs concurrently with Task_IntroRayquazaGlowScene_1
 * Task_EndIntroMovie
 * MainCB2_EndIntro
 *  - Advances to CB2_InitTitleScreen
 */

extern const struct CompressedSpriteSheet gBattleAnimPicTable[];
extern const struct CompressedSpritePalette gBattleAnimPaletteTable[];
extern const struct SpriteTemplate gAncientPowerRockSpriteTemplate[];

//ewram
EWRAM_DATA u16 gIntroCharacterGender = 0;
EWRAM_DATA u16 gUnknown_0203BCCA = 0;
EWRAM_DATA u16 gIntroGraphicsFlygonYOffset = 0;

//iwram
u32 gIntroFrameCounter;
struct GcmbStruct gMultibootProgramStruct;

//.rodata
static const u16 gIntro1DropsPal[] = INCBIN_U16("graphics/intro/intro1_drops.gbapal");
static const u16 gIntro1GFLogoPal[] = INCBIN_U16("graphics/intro/intro1_gflogo.gbapal");
static const u32 gIntroTiles[] = INCBIN_U32("graphics/intro/intro.4bpp.lz");
static const u16 gIntro1BGPals[16][16] = INCBIN_U16("graphics/intro/intro1_bgpal.gbapal");
static const u32 gIntro1BG0_Tilemap[] = INCBIN_U32("graphics/intro/intro1_bg0_map.bin.lz");
static const u32 gIntro1BG1_Tilemap[] = INCBIN_U32("graphics/intro/intro1_bg1_map.bin.lz");
static const u32 gIntro1BG2_Tilemap[] = INCBIN_U32("graphics/intro/intro1_bg2_map.bin.lz");
static const u32 gIntro1BG3_Tilemap[] = INCBIN_U32("graphics/intro/intro1_bg3_map.bin.lz");
static const u32 gIntro1BGLeavesGfx[] = INCBIN_U32("graphics/intro/introgfx.4bpp.lz");
static const u16 gIntro3PokeballPal[] = INCBIN_U16("graphics/intro/intro3_pokeball.gbapal");
static const u32 gIntro3Pokeball_Tilemap[] = INCBIN_U32("graphics/intro/intro3_pokeball_map.bin.lz");
static const u32 gIntro3Pokeball_Gfx[] = INCBIN_U32("graphics/intro/intro3_pokeball.8bpp.lz");
static const u16 gIntro3Streaks_Pal_Unused[] = INCBIN_U16("graphics/intro/intro3_streaks.gbapal");
static const u32 gIntro3Streaks_Gfx_Unused[] = INCBIN_U32("graphics/intro/intro3_streaks.4bpp.lz");
static const u32 gIntro3Streaks_Tilemap_Unused[] = INCBIN_U32("graphics/intro/intro3_streaks_map.bin.lz");
static const u16 gIntro3Misc1Palette[] = INCBIN_U16("graphics/intro/intro3_misc1.gbapal");
static const u16 gIntro3Misc2Palette_Unused[] = INCBIN_U16("graphics/intro/intro3_misc2.gbapal");
static const u32 gIntro3MiscTiles[] = INCBIN_U32("graphics/intro/intro3_misc.4bpp.lz");
static const u16 gIntro1FlygonPalette[] = INCBIN_U16("graphics/intro/intro1_flygon.gbapal");
static const u32 gIntro1EonTiles_Unused[] = INCBIN_U32("graphics/intro/intro1_eon.4bpp.lz");
static const u8 sUnknownBytes[] = {
    0x02, 0x03, 0x04, 0x05, 0x01, 0x01, 0x01, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x02, 0x0D,
    0x0E, 0x0F, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x02, 0x0D, 0x0E, 0x0F,
    0x10, 0x11, 0x12, 0x1A, 0x1B, 0x1C, 0x1D, 0x1E, 0x1F, 0x20, 0x21, 0x02, 0x0D, 0x0E, 0x0F, 0x10,
    0x11, 0x12, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29, 0x2A, 0x00
};
static const struct CompressedSpriteSheet gIntroSpriteSheet_Sparkle[] =
{
    {gIntro1SparkleGfx, 0x400, 1505},
    {NULL},
};
static const struct SpritePalette gIntroPalette_Lightning[] =
{
    {gIntro3LightningPal, 1505},
    {NULL},
};
static const struct OamData gUnknown_085E4A94 =
{
    .y = 160,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = 0,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(16x16),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(16x16),
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0,
};
static const union AnimCmd gUnknown_085E4A9C[] =
{
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(4, 2),
    ANIMCMD_FRAME(8, 2),
    ANIMCMD_FRAME(12, 2),
    ANIMCMD_FRAME(16, 2),
    ANIMCMD_JUMP(0),
};
static const union AnimCmd *const gUnknown_085E4AB4[] =
{
    gUnknown_085E4A9C,
};
static void sub_816D338(struct Sprite *sprite);
static const struct SpriteTemplate gUnknown_085E4AB8 =
{
    .tileTag = 1505,
    .paletteTag = 1505,
    .oam = &gUnknown_085E4A94,
    .anims = gUnknown_085E4AB4,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_816D338,
};
static const u8 gUnknown_085E4AD0[][2] =
{
    {0x7C, 0x28},
    {0x66, 0x1E},
    {0x4D, 0x1E},
    {0x36, 0x0F},
    {0x94, 0x09},
    {0x3F, 0x1C},
    {0x5D, 0x28},
    {0x94, 0x20},
    {0xAD, 0x29},
    {0x5E, 0x14},
    {0xD0, 0x26},
    {0x00, 0x00},
};
static const struct CompressedSpriteSheet gIntroPokemonRunningSpriteSheet[] =
{
    {gIntro2VolbeatGfx, 0x400, 1500},
    {gIntro2TorchicGfx, 0xC00, 1501},
    {gIntro2ManectricGfx, 0x2000, 1502},
    {NULL},
};
static const struct SpritePalette gIntroPokemonRunningPalette[] =
{
    {gIntro2VolbeatPal, 1500},
    {gIntro2TorchicPal, 1501},
    {gIntro2ManectricPal, 1502},
    {NULL},
};
static const struct OamData gUnknown_085E4B28 =
{
    .y = 160,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = 0,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x32),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(32x32),
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0,
};
static const union AnimCmd gUnknown_085E4B30[] =
{
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(16, 2),
    ANIMCMD_JUMP(0),
};
static const union AnimCmd *const gUnknown_085E4B3C[] =
{
    gUnknown_085E4B30,
};
static void sub_816D81C(struct Sprite *sprite);
static const struct SpriteTemplate gUnknown_085E4B40 =
{
    .tileTag = 1500,
    .paletteTag = 1500,
    .oam = &gUnknown_085E4B28,
    .anims = gUnknown_085E4B3C,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_816D81C,
};
static const struct OamData gUnknown_085E4B58 =
{
    .y = 160,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = 0,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x32),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(32x32),
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0,
};
static const union AnimCmd gUnknown_085E4B60[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(16, 5),
    ANIMCMD_FRAME(32, 5),
    ANIMCMD_FRAME(16, 5),
    ANIMCMD_JUMP(0),
};
static const union AnimCmd gUnknown_085E4B74[] =
{
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(16, 3),
    ANIMCMD_FRAME(32, 3),
    ANIMCMD_FRAME(16, 3),
    ANIMCMD_JUMP(0),
};
static const union AnimCmd gUnknown_085E4B88[] =
{
    ANIMCMD_FRAME(48, 4),
    ANIMCMD_FRAME(64, 6),
    ANIMCMD_FRAME(80, 0),
    ANIMCMD_END,
};
static const union AnimCmd *const gUnknown_085E4B98[] =
{
    gUnknown_085E4B60,
    gUnknown_085E4B74,
    gUnknown_085E4B88,
};
static void sub_816D9C0(struct Sprite *sprite);
static const struct SpriteTemplate gUnknown_085E4BA4 =
{
    .tileTag = 1501,
    .paletteTag = 1501,
    .oam = &gUnknown_085E4B58,
    .anims = gUnknown_085E4B98,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_816D9C0,
};
static const struct OamData gUnknown_085E4BBC =
{
    .y = 160,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = 0,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(64x64),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(64x64),
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0,
};
static const union AnimCmd gUnknown_085E4BC4[] =
{
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(64, 4),
    ANIMCMD_FRAME(128, 4),
    ANIMCMD_FRAME(192, 4),
    ANIMCMD_JUMP(0),
};
static const union AnimCmd *const gUnknown_085E4BD8[] =
{
    gUnknown_085E4BC4,
};
static void sub_816DAE8(struct Sprite *sprite);
static const struct SpriteTemplate gUnknown_085E4BDC =
{
    .tileTag = 1502,
    .paletteTag = 1502,
    .oam = &gUnknown_085E4BBC,
    .anims = gUnknown_085E4BD8,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_816DAE8,
};
static const struct CompressedSpriteSheet gIntroRayquazaLightningSpriteSheet[] =
{
    {gIntro3LightningGfx, 0xC00, 1503},
    {NULL},
};
static const struct SpritePalette gIntroRayquazaLightningPalette[] =
{
    {gIntro3LightningPal, 1503},
    {NULL},
};
static const struct OamData gUnknown_085E4C14 =
{
    .y = 160,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = 0,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x32),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(32x32),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0,
};
static const union AnimCmd gUnknown_085E4C1C[] =
{
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(48, 2),
    ANIMCMD_END,
};
static const union AnimCmd gUnknown_085E4C28[] =
{
    ANIMCMD_FRAME(16, 2),
    ANIMCMD_FRAME(64, 2),
    ANIMCMD_END,
};
static const union AnimCmd gUnknown_085E4C34[] =
{
    ANIMCMD_FRAME(32, 2),
    ANIMCMD_FRAME(80, 2),
    ANIMCMD_END,
};
static const union AnimCmd *const gUnknown_085E4C40[] =
{
    gUnknown_085E4C1C,
    gUnknown_085E4C28,
    gUnknown_085E4C34,
};
static void SpriteCB_IntroRayquazaLightning(struct Sprite *sprite);
static const struct SpriteTemplate gIntroLightningSprite =
{
    .tileTag = 1503,
    .paletteTag = 1503,
    .oam = &gUnknown_085E4C14,
    .anims = gUnknown_085E4C40,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_IntroRayquazaLightning,
};
static const s16 gIntroGroudonRockData[][3] =
{
    {0x68, 0x00, 0x0C0},
    {0x8E, 0x03, 0x280},
    {0x53, 0x01, 0x180},
    {0x9B, 0x00, 0x080},
    {0x38, 0x02, 0x200},
    {0xAE, 0x01, 0x100},
};
static const struct CompressedSpriteSheet gUnknown_085E4C88[] =
{
    {gIntro2BubblesGfx, 0x600, 1504},
    {NULL},
};
static const struct SpritePalette gUnknown_085E4C98[] =
{
    {gIntro2BubblesPal, 1504},
    {NULL},
};
static const s16 gIntroKyogreBubbleData[][3] =
{
    {0x42, 0x40, 0x1},
    {0x60, 0x60, 0x8},
    {0x80, 0x40, 0x1},
    {0x90, 0x30, 0x8},
    {0xA0, 0x48, 0x1},
    {0xB0, 0x60, 0x8},
    {0x60, 0x60, 0x4},
    {0x70, 0x68, 0x8},
    {0x80, 0x60, 0x4},
    {0x58, 0x20, 0x4},
    {0x68, 0x18, 0x8},
    {0x78, 0x20, 0x4},
};
static const struct OamData gUnknown_085E4CF0 =
{
    .y = 160,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = 0,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(16x32),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(16x32),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0,
};
static const union AnimCmd gUnknown_085E4CF8[] =
{
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(8, 4),
    ANIMCMD_FRAME(16, 4),
    ANIMCMD_FRAME(24, 4),
    ANIMCMD_FRAME(32, 4),
    ANIMCMD_END,
};
static const union AnimCmd *const gUnknown_085E4D10[] =
{
    gUnknown_085E4CF8,
};
static void SpriteCB_IntroKyogreBubbles(struct Sprite *sprite);
static const struct SpriteTemplate gUnknown_085E4D14 =
{
    .tileTag = 1504,
    .paletteTag = 1504,
    .oam = &gUnknown_085E4CF0,
    .anims = gUnknown_085E4D10,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_IntroKyogreBubbles,
};
static const struct OamData gUnknown_085E4D2C =
{
    .y = 160,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = 0,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x32),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(32x32),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0,
};
static const union AnimCmd gUnknown_085E4D34[] =
{
    ANIMCMD_FRAME(16, 8),
    ANIMCMD_END,
};
static const union AnimCmd gUnknown_085E4D3C[] =
{
    ANIMCMD_FRAME(24, 8),
    ANIMCMD_END,
};
static const union AnimCmd gUnknown_085E4D44[] =
{
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_END,
};
static const union AnimCmd gUnknown_085E4D4C[] =
{
    ANIMCMD_FRAME(48, 8),
    ANIMCMD_END,
};
static const union AnimCmd *const gUnknown_085E4D54[] =
{
    gUnknown_085E4D34,
    gUnknown_085E4D3C,
    gUnknown_085E4D44,
    gUnknown_085E4D4C,
};
static void sub_816F454(struct Sprite *sprite);
static const struct SpriteTemplate gIntroWaterDropSprite =
{
    .tileTag = 2000,
    .paletteTag = 2000,
    .oam = &gUnknown_085E4D2C,
    .anims = gUnknown_085E4D54,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_816F454,
};
static const union AnimCmd gUnknown_085E4D7C[] =
{
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(64, 4),
    ANIMCMD_FRAME(128, 4),
    ANIMCMD_FRAME(192, 4),
    ANIMCMD_JUMP(0),
};
static const union AnimCmd gUnknown_085E4D90[] =
{
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(64, 8),
    ANIMCMD_FRAME(128, 8),
    ANIMCMD_FRAME(192, 8),
    ANIMCMD_JUMP(0),
};
static const union AnimCmd gUnknown_085E4DA4[] =
{
    ANIMCMD_FRAME(256, 4),
    ANIMCMD_FRAME(0x140, 4),
    ANIMCMD_FRAME(0x180, 4),
    ANIMCMD_END,
};
static const union AnimCmd gUnknown_085E4DB4[] =
{
    ANIMCMD_FRAME(0x180, 16),
    ANIMCMD_FRAME(0x140, 16),
    ANIMCMD_FRAME(256, 16),
    ANIMCMD_END,
};
static const union AnimCmd *const gIntroBicycleAnimationCommands[] =
{
    gUnknown_085E4D7C,
    gUnknown_085E4D90,
    gUnknown_085E4DA4,
    gUnknown_085E4DB4,
};
static const struct OamData gUnknown_085E4DD4 =
{
    .y = 160,
    .affineMode = ST_OAM_AFFINE_DOUBLE,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = 0,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(16x16),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(16x16),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0,
};
static const struct OamData gUnknown_085E4DDC =
{
    .y = 160,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = 0,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(8x8),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(8x8),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0,
};
static const struct OamData gUnknown_085E4DE4 =
{
    .y = 160,
    .affineMode = ST_OAM_AFFINE_DOUBLE,
    .objMode = ST_OAM_OBJ_BLEND,
    .mosaic = 0,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x64),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(32x64),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0,
};
static const union AnimCmd gUnknown_085E4DEC[] =
{
    ANIMCMD_FRAME(80, 8),
    ANIMCMD_END,
};
static const union AnimCmd gUnknown_085E4DF4[] =
{
    ANIMCMD_FRAME(84, 8),
    ANIMCMD_END,
};
static const union AnimCmd gUnknown_085E4DFC[] =
{
    ANIMCMD_FRAME(88, 8),
    ANIMCMD_END,
};
static const union AnimCmd gUnknown_085E4E04[] =
{
    ANIMCMD_FRAME(92, 8),
    ANIMCMD_END,
};
static const union AnimCmd gUnknown_085E4E0C[] =
{
    ANIMCMD_FRAME(96, 8),
    ANIMCMD_END,
};
static const union AnimCmd gUnknown_085E4E14[] =
{
    ANIMCMD_FRAME(100, 8),
    ANIMCMD_END,
};
static const union AnimCmd gUnknown_085E4E1C[] =
{
    ANIMCMD_FRAME(104, 8),
    ANIMCMD_END,
};
static const union AnimCmd gUnknown_085E4E24[] =
{
    ANIMCMD_FRAME(112, 8),
    ANIMCMD_END,
};
static const union AnimCmd gUnknown_085E4E2C[] =
{
    ANIMCMD_FRAME(113, 8),
    ANIMCMD_END,
};
static const union AnimCmd gUnknown_085E4E34[] =
{
    ANIMCMD_FRAME(114, 8),
    ANIMCMD_END,
};
static const union AnimCmd gUnknown_085E4E3C[] =
{
    ANIMCMD_FRAME(115, 8),
    ANIMCMD_END,
};
static const union AnimCmd gUnknown_085E4E44[] =
{
    ANIMCMD_FRAME(116, 8),
    ANIMCMD_END,
};
static const union AnimCmd gUnknown_085E4E4C[] =
{
    ANIMCMD_FRAME(117, 8),
    ANIMCMD_END,
};
static const union AnimCmd gUnknown_085E4E54[] =
{
    ANIMCMD_FRAME(128, 8),
    ANIMCMD_END,
};
static const union AnimCmd *const gUnknown_085E4E5C[] =
{
    gUnknown_085E4DEC,
    gUnknown_085E4DF4,
    gUnknown_085E4DFC,
    gUnknown_085E4E04,
    gUnknown_085E4E0C,
    gUnknown_085E4E14,
    gUnknown_085E4E1C,
};
static const union AnimCmd *const gUnknown_085E4E78[] =
{
    gUnknown_085E4E24,
    gUnknown_085E4E2C,
    gUnknown_085E4E34,
    gUnknown_085E4E3C,
    gUnknown_085E4E44,
    gUnknown_085E4E4C,
};
static const union AnimCmd *const gUnknown_085E4E90[] =
{
    gUnknown_085E4E54,
};
static const s16 gUnknown_085E4E94[][2] =
{
    {0, -72},
    {1, -56},
    {2, -40},
    {3, -24},
    {4, 8},
    {5, 24},
    {3, 40},
    {1, 56},
    {6, 72},
    {0, -28},
    {1, -20},
    {2, -12},
    {3, -4},
    {2, 4},
    {4, 12},
    {5, 20},
    {3, 28},
};
static const union AffineAnimCmd gUnknown_085E4ED8[] =
{
    AFFINEANIMCMD_FRAME(128, 128, 0, 0),
    AFFINEANIMCMD_END,
};
static const union AffineAnimCmd gUnknown_085E4EE8[] =
{
    AFFINEANIMCMD_FRAME(128, 128, 0, 0),
    AFFINEANIMCMD_FRAME(16, 16, 0, 16),
    AFFINEANIMCMD_FRAME(-16, -16, 0, 8),
    AFFINEANIMCMD_END,
};
static const union AffineAnimCmd gUnknown_085E4F08[] =
{
    AFFINEANIMCMD_FRAME(256, 256, 0, 0),
    AFFINEANIMCMD_FRAME(8, 8, 0, 48),
    AFFINEANIMCMD_END,
};
static const union AffineAnimCmd gUnknown_085E4F20[] =
{
    AFFINEANIMCMD_FRAME(256, 256, 0, 0),
    AFFINEANIMCMD_FRAME(2, 2, 0, 48),
    AFFINEANIMCMD_END,
};
static const union AffineAnimCmd *const gUnknown_085E4F38[] =
{
    gUnknown_085E4ED8,
    gUnknown_085E4EE8,
    gUnknown_085E4F08,
    gUnknown_085E4F20,
};
static const u16 gUnknown_085E4F48[] =
{
    0x100, 0xC0, 0x80, 0x40, 0x00, 0x40, 0x80, 0xC0, 0x100
};
static void sub_816FB38(struct Sprite *sprite);
static const struct SpriteTemplate gUnknown_085E4F5C =
{
    .tileTag = 2000,
    .paletteTag = 2001,
    .oam = &gUnknown_085E4DD4,
    .anims = gUnknown_085E4E5C,
    .images = NULL,
    .affineAnims = gUnknown_085E4F38,
    .callback = sub_816FB38,
};
static const struct SpriteTemplate gUnknown_085E4F74 =
{
    .tileTag = 2000,
    .paletteTag = 2001,
    .oam = &gUnknown_085E4DDC,
    .anims = gUnknown_085E4E78,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_816FB38,
};
static void sub_816FD44(struct Sprite *sprite);
static const struct SpriteTemplate gUnknown_085E4F8C =
{
    .tileTag = 2000,
    .paletteTag = 2001,
    .oam = &gUnknown_085E4DE4,
    .anims = gUnknown_085E4E90,
    .images = NULL,
    .affineAnims = gUnknown_085E4F38,
    .callback = sub_816FD44,
};
static const u8 gUnknown_085E4FA4[] =
{
    0x00, 0x17, 0x17, 0x31, 0x3E, 0x24, 0x24, 0x0A, 0x0A
};
static const struct OamData gUnknown_085E4FB0 =
{
    .y = 160,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = 0,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(64x32),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(64x32),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0,
};
static const union AnimCmd gUnknown_085E4FB8[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_JUMP(0),
};
static const union AnimCmd *const gUnknown_085E4FC0[] =
{
    gUnknown_085E4FB8,
};
static void sub_816FEDC(struct Sprite *sprite);
static const struct SpriteTemplate gUnknown_085E4FC4 =
{
    .tileTag = 2002,
    .paletteTag = 2002,
    .oam = &gUnknown_085E4FB0,
    .anims = gUnknown_085E4FC0,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_816FEDC,
};
static const struct CompressedSpriteSheet gIntroSpriteSheet_WaterDropAndLogo[] =
{
    {gIntroTiles, 0x1400, 2000},
    {NULL},
};
static const struct CompressedSpriteSheet gIntroSpriteSheet_Flygon[] =
{
    {gIntro1FlygonGfx, 0x400, 2002},
    {NULL},
};
static const struct SpritePalette gIntroPalette_DropLogoFlygon[] =
{
    {gIntro1DropsPal, 2000},
    {gIntro1GFLogoPal, 2001},
    {gIntro1FlygonPalette, 2002},
    {NULL},
};
static const struct OamData gUnknown_085E501C =
{
    .y = 160,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = 0,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(64x64),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(64x64),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0,
};
static const union AnimCmd gUnknown_085E5024[] =
{
    ANIMCMD_FRAME(16, 8),
    ANIMCMD_END,
};
static const union AnimCmd *const gUnknown_085E502C[] =
{
    gUnknown_085E5024,
};
static void SpriteCB_IntroRayquazaHyperbeam(struct Sprite *sprite);
static const struct SpriteTemplate gIntroRayquazaHyperbeamSprite =
{
    .tileTag = 2003,
    .paletteTag = 2003,
    .oam = &gUnknown_085E501C,
    .anims = gUnknown_085E502C,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_IntroRayquazaHyperbeam,
};
static const struct CompressedSpriteSheet gIntroRayquazaGlowSpriteSheet[] =
{
    {gIntro3MiscTiles, 0xA00, 2003},
    {NULL},
};
static const struct SpritePalette gIntroRayquazaGlowPalette[] =
{
    {gIntro3Misc1Palette, 2003},
    {NULL},
};

// this file's functions
static void MainCB2_EndIntro(void);
static void Task_IntroLoadPart1Graphics(u8);
static u8 CreateWaterDrop(s16, s16, u16, u16, u16, u8);
static void Task_IntroFadeIn(u8);
static void intro_reset_and_hide_bgs(void);
static void Task_IntroWaterDrops(u8);
static void Task_IntroWaterDrops_1(u8);
static void Task_IntroWaterDrops_2(u8);
static void Task_IntroWaterDrops_3(u8);
static void Task_IntroScrollDownAndShowFlygon(u8);
static void Task_IntroWaitToSetupPart2(u8);
static void Task_IntroLoadPart2Graphics(u8);
static void Task_IntroStartBikeRide(u8);
static void Task_IntroHandleBikeAndFlygonMovement(u8);
static void Task_IntroWaitToSetupPart3(u8);
static void Task_IntroLoadPart3Graphics(u8);
static void Task_IntroSpinAndZoomPokeball(u8);
static void Task_IntroWaitToSetupPart3LegendsFight(u8);
static void Task_IntroLoadGroudonScene(u8);
static void Task_IntroLoadPart3Graphics1(u8);
static void Task_IntroLoadPart3Graphics2(u8);
static void Task_IntroLoadPart3Graphics3(u8);
static void Task_IntroLoadPart3Graphics4(u8);
static void Task_IntroGroudonScene(u8);
static void Task_IntroLoadKyogreScene(u8);
static void Task_IntroKyogreScene(u8);
static void Task_IntroLoadClouds1(u8);
static void Task_IntroLoadClouds2(u8);
static void Task_IntroLoadClouds3(u8);
static void Task_IntroCloudScene(u8);
static void Task_IntroLoadRayquazaLightningScene(u8);
static void Task_IntroRayquazaLightningScene(u8);
static void Task_IntroLoadRayquazaGlowScene(u8);
static void Task_IntroRayquazaGlowScene_0(u8);
static void Task_EndIntroMovie(u8);
static void CreateGroudonRockSprites(u8);
static void SpriteCB_IntroGroudonRocks(struct Sprite *);
static void CreateKyogreBubbleSprites_0(u8);
static void CreateKyogreBubbleSprites_1(void);
static void Task_IntroRayquazaGlowScene_1(u8);
static void sub_816F46C(struct Sprite *);
static void sub_816F5B4(struct Sprite *);
static void sub_816F660(struct Sprite *);
static void SpriteCB_WaterDropFall(struct Sprite *);
static void sub_816F318(struct Sprite *);
static void SpriteCB_IntroGraphicsBicycle(struct Sprite *);
static void SpriteCB_IntroGraphicsFlygon(struct Sprite *);
static u8 CreatePart1Animations(s16, s16, s16);

static void VBlankCB_Intro(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
    ScanlineEffect_InitHBlankDmaTransfer();
}

static void MainCB2_Intro(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
    if (gMain.newKeys && !gPaletteFade.active)
        SetMainCallback2(MainCB2_EndIntro);
    else if (gIntroFrameCounter != -1)
        gIntroFrameCounter++;
}

static void MainCB2_EndIntro(void)
{
    if (!UpdatePaletteFade())
        SetMainCallback2(CB2_InitTitleScreen);
}

static void LoadCopyrightGraphics(u16 tilesetAddress, u16 tilemapAddress, u16 paletteAddress)
{
    LZ77UnCompVram(gIntroCopyright_Gfx, (void *)(VRAM + tilesetAddress));
    LZ77UnCompVram(gIntroCopyright_Tilemap, (void *)(VRAM + tilemapAddress));
    LoadPalette(gIntroCopyright_Pal, paletteAddress, 0x20);
}

static void SerialCB_CopyrightScreen(void)
{
    GameCubeMultiBoot_HandleSerialInterrupt(&gMultibootProgramStruct);
}

static u8 SetUpCopyrightScreen(void)
{
    switch (gMain.state)
    {
    case 0:
        SetVBlankCallback(NULL);
        SetGpuReg(REG_OFFSET_BLDCNT, 0);
        SetGpuReg(REG_OFFSET_BLDALPHA, 0);
        SetGpuReg(REG_OFFSET_BLDY, 0);
        *(u16 *)PLTT = 0x7FFF;
        SetGpuReg(REG_OFFSET_DISPCNT, 0);
        SetGpuReg(REG_OFFSET_BG0HOFS, 0);
        SetGpuReg(REG_OFFSET_BG0VOFS, 0);
        CpuFill32(0, (void *)VRAM, VRAM_SIZE);
        CpuFill32(0, (void *)OAM, OAM_SIZE);
        CpuFill16(0, (void *)(PLTT + 2), PLTT_SIZE - 2);
        ResetPaletteFade();
        LoadCopyrightGraphics(0, 0x3800, 0);
        ScanlineEffect_Stop();
        ResetTasks();
        ResetSpriteData();
        FreeAllSpritePalettes();
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0x10, 0, RGB_WHITEALPHA);
        SetGpuReg(REG_OFFSET_BG0CNT, BGCNT_PRIORITY(0)
                                   | BGCNT_CHARBASE(0)
                                   | BGCNT_SCREENBASE(7)
                                   | BGCNT_16COLOR
                                   | BGCNT_TXT256x256);
        EnableInterrupts(INTR_FLAG_VBLANK);
        SetVBlankCallback(VBlankCB_Intro);
        REG_DISPCNT = DISPCNT_MODE_0 | DISPCNT_OBJ_1D_MAP | DISPCNT_BG0_ON;
        SetSerialCallback(SerialCB_CopyrightScreen);
        GameCubeMultiBoot_Init(&gMultibootProgramStruct);
    default:
        UpdatePaletteFade();
        gMain.state++;
        GameCubeMultiBoot_Main(&gMultibootProgramStruct);
        break;
    case 140:
        GameCubeMultiBoot_Main(&gMultibootProgramStruct);
        if (gMultibootProgramStruct.gcmb_field_2 != 1)
        {
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 0x10, RGB_BLACK);
            gMain.state++;
        }
        break;
    case 141:
        if (UpdatePaletteFade())
            break;
        CreateTask(Task_IntroLoadPart1Graphics, 0);
        SetMainCallback2(MainCB2_Intro);
        if (gMultibootProgramStruct.gcmb_field_2 != 0)
        {
            if (gMultibootProgramStruct.gcmb_field_2 == 2)
            {
                // check the multiboot ROM header game code to see if we already did this
                if (*(u32 *)(EWRAM_START + 0xAC) == 0x65366347) // "Gc6e" in ASCII
                {
                    CpuCopy16(&gMultiBootProgram_PokemonColosseum_Start, (void *)EWRAM_START, sizeof(gMultiBootProgram_PokemonColosseum_Start));
                    *(u32 *)(EWRAM_START + 0xAC) = 0x65366347;
                }
                GameCubeMultiBoot_ExecuteProgram(&gMultibootProgramStruct);
            }
        }
        else
        {
            GameCubeMultiBoot_Quit();
            SetSerialCallback(SerialCB);
        }
        return 0;
    }

    return 1;
}

void CB2_InitCopyrightScreenAfterBootup(void)
{
    if (!SetUpCopyrightScreen())
    {
        SetSaveBlocksPointers(sub_815355C());
        ResetMenuAndMonGlobals();
        Save_ResetSaveCounters();
        Save_LoadGameData(SAVE_NORMAL);
        if (gSaveFileStatus == SAVE_STATUS_EMPTY || gSaveFileStatus == SAVE_STATUS_CORRUPT)
            Sav2_ClearSetDefault();
        SetPokemonCryStereo(gSaveBlock2Ptr->optionsSound);
        InitHeap(gHeap, HEAP_SIZE);
    }
}

void CB2_InitCopyrightScreenAfterTitleScreen(void)
{
    SetUpCopyrightScreen();
}

static void Task_IntroLoadPart1Graphics(u8 taskId)
{
    SetVBlankCallback(NULL);
    gIntroCharacterGender = Random() & 1;
    intro_reset_and_hide_bgs();
    SetGpuReg(REG_OFFSET_BG3VOFS, 0);
    SetGpuReg(REG_OFFSET_BG2VOFS, 0x50);
    SetGpuReg(REG_OFFSET_BG1VOFS, 0x18);
    SetGpuReg(REG_OFFSET_BG0VOFS, 0x28);
    LZ77UnCompVram(gIntro1BGLeavesGfx, (void *)VRAM);
    LZ77UnCompVram(gIntro1BG0_Tilemap, (void *)(BG_CHAR_ADDR(2)));
    DmaClear16(3, BG_SCREEN_ADDR(17), 0x800);
    LZ77UnCompVram(gIntro1BG1_Tilemap, (void *)(BG_SCREEN_ADDR(18)));
    DmaClear16(3, BG_SCREEN_ADDR(19), 0x800);
    LZ77UnCompVram(gIntro1BG2_Tilemap, (void *)(BG_SCREEN_ADDR(20)));
    DmaClear16(3, BG_SCREEN_ADDR(21), 0x800);
    LZ77UnCompVram(gIntro1BG3_Tilemap, (void *)(BG_SCREEN_ADDR(22)));
    DmaClear16(3, BG_SCREEN_ADDR(23), 0x800);
    LoadPalette(gIntro1BGPals, 0, sizeof(gIntro1BGPals));
    SetGpuReg(REG_OFFSET_BG3CNT, BGCNT_PRIORITY(3) | BGCNT_CHARBASE(0) | BGCNT_SCREENBASE(22) | BGCNT_16COLOR | BGCNT_TXT256x512);
    SetGpuReg(REG_OFFSET_BG2CNT, BGCNT_PRIORITY(2) | BGCNT_CHARBASE(0) | BGCNT_SCREENBASE(20) | BGCNT_16COLOR | BGCNT_TXT256x512);
    SetGpuReg(REG_OFFSET_BG1CNT, BGCNT_PRIORITY(1) | BGCNT_CHARBASE(0) | BGCNT_SCREENBASE(18) | BGCNT_16COLOR | BGCNT_TXT256x512);
    SetGpuReg(REG_OFFSET_BG0CNT, BGCNT_PRIORITY(0) | BGCNT_CHARBASE(0) | BGCNT_SCREENBASE(16) | BGCNT_16COLOR | BGCNT_TXT256x512);
    LoadCompressedSpriteSheet(gIntroSpriteSheet_WaterDropAndLogo);
    LoadCompressedSpriteSheet(gIntroSpriteSheet_Flygon);
    LoadSpritePalettes(gIntroPalette_DropLogoFlygon);
    LoadCompressedSpriteSheet(gIntroSpriteSheet_Sparkle);
    LoadSpritePalettes(gIntroPalette_Lightning);
    CpuCopy16(gPlttBufferUnfaded + 0x100, gPlttBufferUnfaded + 0x1F0, 0x20);
    CpuCopy16(gPlttBufferUnfaded + 0x100, gPlttBufferUnfaded + 0x1E1, 0x1E);
    CpuCopy16(gPlttBufferUnfaded + 0x100, gPlttBufferUnfaded + 0x1D2, 0x1C);
    CpuCopy16(gPlttBufferUnfaded + 0x100, gPlttBufferUnfaded + 0x1C3, 0x1A);
    CpuCopy16(gPlttBufferUnfaded + 0x100, gPlttBufferUnfaded + 0x1B4, 0x18);
    CpuCopy16(gPlttBufferUnfaded + 0x100, gPlttBufferUnfaded + 0x1A5, 0x16);
    CpuCopy16(gPlttBufferUnfaded + 0x100, gPlttBufferUnfaded + 0x196, 0x14);
    CreatePart1Animations(0x78, 0x50, 0);
    gTasks[taskId].data[0] = CreateWaterDrop(236, -14, 0x200, 1, 0x78, FALSE);
    gTasks[taskId].func = Task_IntroFadeIn;
}

static void Task_IntroFadeIn(u8 taskId)
{
    BeginNormalPaletteFade(0xFFFFFFFF, 0, 16, 0, RGB_BLACK);
    SetVBlankCallback(VBlankCB_Intro);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0 | DISPCNT_OBJ_1D_MAP | DISPCNT_BG_ALL_ON | DISPCNT_OBJ_ON);
    gTasks[taskId].func = Task_IntroWaterDrops;
    gIntroFrameCounter = 0;
    m4aSongNumStart(MUS_INTRO);
    ResetSerial();
}

static void Task_IntroWaterDrops(u8 taskId)
{
    //start moving rock
    if (gIntroFrameCounter == 76)
        gSprites[gTasks[taskId].data[0]].data[0] = 1;

    if (gIntroFrameCounter == 128)
        CreateTask(Task_IntroWaterDrops_1, 0);

    //drop rock
    if (gIntroFrameCounter == 251)
        gSprites[gTasks[taskId].data[0]].data[0] = 2;

    if (gIntroFrameCounter == 256)
        CreateTask(Task_IntroWaterDrops_2, 0);

    if (gIntroFrameCounter == 368)
        CreateWaterDrop(48, 0, 0x400, 5, 0x70, TRUE);

    if (gIntroFrameCounter == 384)
        CreateWaterDrop(200, 60, 0x400, 9, 0x80, TRUE);

    if (gIntroFrameCounter == 560)
        CreateTask(Task_IntroWaterDrops_3, 0);

    if (gIntroFrameCounter > 560)
    {
        gTasks[taskId].data[1] = 0x50;
        gTasks[taskId].data[2] = 0;
        gTasks[taskId].data[3] = 0x18;
        gTasks[taskId].data[4] = 0;
        gTasks[taskId].data[5] = 0x28;
        gTasks[taskId].data[6] = 0;
        gTasks[taskId].func = Task_IntroScrollDownAndShowFlygon;
    }
}

static void Task_IntroWaterDrops_3(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    if (++data[2] & 1)
        data[3]++;

    switch (data[0])
    {
    case 0:
        CreateSprite(&gUnknown_085E4AB8, gUnknown_085E4AD0[data[4]][0], gUnknown_085E4AD0[data[4]][1] + data[3], 0);
        data[0]++;
        data[1] = 0xC;
        data[4]++;
        break;
    case 1:
        if (!--data[1])
            data[0] = 0;
        break;
    }

    if (data[3] > 0x3C)
        DestroyTask(taskId);
}

static void sub_816D338(struct Sprite *sprite)
{
    if (++sprite->data[0] == 0xC)
        DestroySprite(sprite);
}

static void Task_IntroScrollDownAndShowFlygon(u8 taskId)
{
    if (gIntroFrameCounter < 904)
    {
        s32 r2;

        //slide backgrounds downward
        r2 = (gTasks[taskId].data[1] << 16) + (u16)gTasks[taskId].data[2];
        r2 -= 0x6000;
        gTasks[taskId].data[1] = r2 >> 16;
        gTasks[taskId].data[2] = r2;
        SetGpuReg(REG_OFFSET_BG2VOFS, gTasks[taskId].data[1]);
        r2 = (gTasks[taskId].data[3] << 16) + (u16)gTasks[taskId].data[4];
        r2 -= 0x8000;
        gTasks[taskId].data[3] = r2 >> 16;
        gTasks[taskId].data[4] = r2;
        SetGpuReg(REG_OFFSET_BG1VOFS, gTasks[taskId].data[3]);
        r2 = (gTasks[taskId].data[5] << 16) + (u16)gTasks[taskId].data[6];
        r2 -= 0xC000;
        gTasks[taskId].data[5] = r2 >> 16;
        gTasks[taskId].data[6] = r2;
        SetGpuReg(REG_OFFSET_BG0VOFS, gTasks[taskId].data[5]);

        //show Flygon sprite
        if (gIntroFrameCounter == 832)
        {
            u8 spriteId = CreateSprite(&gUnknown_085E4FC4, 120, 160, 10);
            gSprites[spriteId].invisible = TRUE;
        }
    }
    else
    {
        //fade to white
        if (gIntroFrameCounter > 1007)
        {
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_WHITEALPHA);
            gTasks[taskId].func = Task_IntroWaitToSetupPart2;
        }
    }
}

static void Task_IntroWaitToSetupPart2(u8 taskId)
{
    if (gIntroFrameCounter > 1026)
        gTasks[taskId].func = Task_IntroLoadPart2Graphics;
}

static void Task_IntroLoadPart2Graphics(u8 taskId)
{
    intro_reset_and_hide_bgs();
    SetVBlankCallback(NULL);
    ResetSpriteData();
    FreeAllSpritePalettes();
    gUnknown_0203BD24 = 0;
    gUnknown_0203BD26 = 0;
    gIntroGraphicsFlygonYOffset = 0;
    load_intro_part2_graphics(1);
    gTasks[taskId].func = Task_IntroStartBikeRide;
}

static void Task_IntroStartBikeRide(u8 taskId)
{
    u8 spriteId;

    if (gIntroCharacterGender == 0)
        LoadCompressedSpriteSheet(gIntro2BrendanSpriteSheet);
    else
        LoadCompressedSpriteSheet(gIntro2MaySpriteSheet);

    LoadCompressedSpriteSheet(gIntro2BicycleSpriteSheet);
    LoadCompressedSpriteSheet(gIntro2FlygonSpriteSheet);

    for (spriteId = 0; spriteId < 3; spriteId++)
    {
        LoadCompressedSpriteSheet(&gIntroPokemonRunningSpriteSheet[spriteId]);
    }

    LoadSpritePalettes(gIntroBikeAndFlygonPalette);
    LoadSpritePalettes(gIntroPokemonRunningPalette);
    CreateSprite(&gUnknown_085E4BDC, 0x110, 0x80, 0);
    CreateSprite(&gUnknown_085E4BA4, 0x120, 0x6E, 1);

    if (gIntroCharacterGender == 0)
        spriteId = intro_create_brendan_sprite(0x110, 100);
    else
        spriteId = intro_create_may_sprite(0x110, 100);

    gSprites[spriteId].callback = SpriteCB_IntroGraphicsBicycle;
    gSprites[spriteId].anims = gIntroBicycleAnimationCommands;
    gTasks[taskId].data[1] = spriteId;
    CreateSprite(&gUnknown_085E4B40, 0x110, 0x50, 0x4);
    spriteId = intro_create_flygon_sprite(-0x40, 0x3C);
    gSprites[spriteId].callback = SpriteCB_IntroGraphicsFlygon;
    gTasks[taskId].data[2] = spriteId;
    BeginNormalPaletteFade(0xFFFFFFFF, 0, 16, 0, RGB_WHITEALPHA);
    SetVBlankCallback(VBlankCB_Intro);
    gTasks[taskId].data[0] = CreateBicycleAnimationTask(1, 0x4000, 0x400, 0x10);
    sub_817B150(1);
    gTasks[taskId].func = Task_IntroHandleBikeAndFlygonMovement;
}

static void Task_IntroHandleBikeAndFlygonMovement(u8 taskId)
{
    u16 offset;

    if (gIntroFrameCounter == 1856)
    {
        gUnknown_0203BD28 = 2;
        // Destroys the CreateBicycleAnimationTask created earlier.
        DestroyTask(gTasks[taskId].data[0]);
    }
    if (gIntroFrameCounter > 1946)
    {
        BeginNormalPaletteFade(0xFFFFFFFF, 8, 0, 16, RGB_WHITEALPHA);
        gTasks[taskId].func = Task_IntroWaitToSetupPart3;
    }
    if (gIntroFrameCounter == 1109)
        gSprites[gTasks[taskId].data[1]].data[0] = 1;
    if (gIntroFrameCounter == 1214)
        gSprites[gTasks[taskId].data[1]].data[0] = 0;
    if (gIntroFrameCounter == 1394)
        gSprites[gTasks[taskId].data[2]].data[0] = 1;
    if (gIntroFrameCounter == 1398)
        gSprites[gTasks[taskId].data[1]].data[0] = 2;
    if (gIntroFrameCounter == 1576)
        gSprites[gTasks[taskId].data[1]].data[0] = 3;
    if (gIntroFrameCounter == 1727)
        gSprites[gTasks[taskId].data[1]].data[0] = 4;

    offset = Sin(gTasks[taskId].data[3] >> 2 & 0x7F, 48);
    gIntroGraphicsFlygonYOffset = offset;
    if (gTasks[taskId].data[3] < 512)
        gTasks[taskId].data[3]++;
    sub_817B540(0);
}

static void Task_IntroWaitToSetupPart3(u8 taskId)
{
    if (gIntroFrameCounter > 2068)
        gTasks[taskId].func = Task_IntroLoadPart3Graphics;
}

static void sub_816D81C(struct Sprite *sprite)
{
    sprite->data[3] += 4;
    switch (sprite->data[0])
    {
    case 0:
        if (++sprite->data[1] < 180)
            break;
        ++sprite->data[0];
    case 1:
        sprite->pos1.x -= 4;
        if (sprite->pos1.x == 0x3C)
        {
            sprite->data[0] = 8;
            sprite->data[1] = 20;
            sprite->data[2] = 2;
        }
        break;
    case 2:
        sprite->pos1.x += 8;
        sprite->pos1.y -= 2;
        if (sprite->pos1.x == 0x7C)
        {
            sprite->data[0] = 8;
            sprite->data[1] = 20;
            sprite->data[2] = 3;
        }
        break;
    case 3:
        sprite->pos1.y += 4;
        if (sprite->pos1.y == 0x50)
        {
            sprite->data[0] = 8;
            sprite->data[1] = 10;
            sprite->data[2] = 4;
        }
        break;
    case 4:
        sprite->pos1.x -= 8;
        sprite->pos1.y -= 2;
        if (sprite->pos1.x == 0x3C)
        {
            sprite->data[0] = 8;
            sprite->data[1] = 10;
            sprite->data[2] = 5;
        }
        break;
    case 5:
        sprite->pos1.x += 0x3C;
        sprite->data[4] = 0xC0;
        sprite->data[5] = 0x80;
        sprite->data[6] = 0x3;
        sprite->data[0]++;
    case 6:
        sprite->pos2.x = Sin((u8)sprite->data[4], 0x3C);
        sprite->pos2.y = Sin((u8)sprite->data[5], 0x14);
        sprite->data[4] += 2;
        sprite->data[5] += 4;
        if ((sprite->data[4] & 0xFF) == 0x40)
        {
            sprite->hFlip = FALSE;
            if (!--sprite->data[6])
            {
                sprite->pos1.x += sprite->pos2.x;
                sprite->pos2.x = 0;
                sprite->data[0]++;
            }
        }
        break;
    case 7:
        sprite->pos1.x -= 2;
        sprite->pos2.y = Sin((u8)sprite->data[5], 0x14);
        sprite->data[5] += 4;
        if (sprite->pos1.x < -16)
            DestroySprite(sprite);
        break;
    case 8:
        sprite->pos2.y = Cos((u8)sprite->data[3], 2);
        if (!--sprite->data[1])
            sprite->data[0] = sprite->data[2];
        break;
    }
}

static void sub_816D9C0(struct Sprite *sprite)
{
    switch (sprite->data[0])
    {
    case 0:
        if (gIntroFrameCounter == 1224)
        {
            StartSpriteAnim(sprite, 1);
            sprite->data[0]++;
        }
        break;
    case 1:
        if (gIntroFrameCounter == 1576)
        {
            StartSpriteAnim(sprite, 0);
            sprite->data[0]++;
        }
        else
        {
            sprite->data[1] += 0x40;
            if (sprite->data[1] & 0xFF00)
            {
                sprite->pos1.x--;
                sprite->data[1] &= 0xFF;
            }
        }
        break;
    case 2:
        if (gIntroFrameCounter != 1735)
        {
            sprite->data[1] += 0x20;
            if (sprite->data[1] & 0xFF00)
            {
                sprite->pos1.x++;
                sprite->data[1] &= 0xFF;
            }
        }
        else
        {
            StartSpriteAnim(sprite, 1);
            sprite->data[0]++;
            sprite->data[2] = 0x50;
        }
        break;
    case 3:
        if (--sprite->data[2])
        {
            sprite->data[1] += 0x40;
            if (sprite->data[1] & 0xFF00)
            {
                sprite->pos1.x--;
                sprite->data[1] &= 0xFF;
            }
        }
        else
        {
            StartSpriteAnim(sprite, 2);
            sprite->data[0]++;
        }
        break;
    case 4:
        if (sprite->animEnded)
            sprite->pos1.x += 4;

        if (sprite->pos1.x > 336)
        {
            StartSpriteAnim(sprite, 1);
            sprite->data[0]++;
        }
        break;
    case 5:
        if (gIntroFrameCounter > 1855)
            sprite->pos1.x -= 2;
        break;
    }
}

static void sub_816DAE8(struct Sprite *sprite)
{
    switch (sprite->data[0])
    {
    case 0:
        if (gIntroFrameCounter == 1088)
            sprite->data[0]++;
        break;
    case 1:
        sprite->pos1.x -= 2;
        if (gIntroFrameCounter != 1168)
            break;
        sprite->pos1.y -= 12;
        sprite->data[1] = 0x80;
        sprite->data[2] = 0;
        sprite->data[0]++;
    case 2:
        if (sprite->pos1.x + sprite->pos2.x <= -0x20)
        {
            DestroySprite(sprite);
        }
        else
        {
            if ((sprite->data[1] & 0xFF) < 0x40)
            {
                sprite->pos2.x = Sin((u8)sprite->data[1], 0x10);
            }
            else
            {
                if ((sprite->data[1] & 0xFF) == 0x40)
                    sprite->pos1.x -= 0x30;
                sprite->pos2.x = Sin((u8)sprite->data[1], 0x40);
            }
            sprite->data[1]++;
            sprite->pos2.y = Cos((u8)sprite->data[2], 0xC);
            sprite->data[2]++;
        }
        break;
    }
}

static void Task_IntroLoadPart3Graphics(u8 taskId)
{
    intro_reset_and_hide_bgs();
    LZ77UnCompVram(gIntro3Pokeball_Gfx, (void *)VRAM);
    LZ77UnCompVram(gIntro3Pokeball_Tilemap, (void *)(BG_CHAR_ADDR(1)));
    LoadPalette(gIntro3PokeballPal, 0, 0x200);
    gTasks[taskId].data[0] = 0;
    gTasks[taskId].data[1] = 0;
    gTasks[taskId].data[2] = 0;
    gTasks[taskId].data[3] = 0;
    PanFadeAndZoomScreen(0x78, 0x50, 0, 0);
    ResetSpriteData();
    FreeAllSpritePalettes();
    BeginNormalPaletteFade(0xFFFFFFFF, 0, 0x10, 0, RGB_WHITEALPHA);
    SetGpuReg(REG_OFFSET_BG2CNT, BGCNT_PRIORITY(3) | BGCNT_CHARBASE(0) | BGCNT_SCREENBASE(8) | BGCNT_256COLOR | BGCNT_AFF256x256);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_1 | DISPCNT_OBJ_1D_MAP | DISPCNT_BG2_ON | DISPCNT_OBJ_ON);
    gTasks[taskId].func = Task_IntroSpinAndZoomPokeball;
    gIntroFrameCounter = 0;
    m4aSongNumStart(MUS_INTRO_BATTLE);
}

static void Task_IntroSpinAndZoomPokeball(u8 taskId)
{
    gTasks[taskId].data[0] += 0x400;

    if (gTasks[taskId].data[1] <= 0x6BF)
    {
        gTasks[taskId].data[1] += gTasks[taskId].data[2];
        gTasks[taskId].data[2] += 2;
    }
    else
    {
        gTasks[taskId].func = Task_IntroWaitToSetupPart3LegendsFight;
    }

    PanFadeAndZoomScreen(0x78, 0x50, 0x10000 / gTasks[taskId].data[1], gTasks[taskId].data[0]);

    if (gIntroFrameCounter == 28)
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 0x10, RGB_WHITEALPHA);
}

static void Task_IntroWaitToSetupPart3LegendsFight(u8 taskId)
{
    if (gIntroFrameCounter > 43)
        gTasks[taskId].func = Task_IntroLoadGroudonScene;
}

static void Task_IntroLoadGroudonScene(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        intro_reset_and_hide_bgs();
        ResetSpriteData();
        FreeAllSpritePalettes();
        gReservedSpritePaletteCount = 8;
        LZDecompressVram(gIntro3GroudonGfx, (void *)VRAM);
        LZDecompressVram(gIntro3GroudonTilemap, (void *)(BG_CHAR_ADDR(3)));
        LZDecompressVram(gIntro3LegendBgGfx, (void *)(BG_CHAR_ADDR(1)));
        LZDecompressVram(gIntro3GroudonBgTilemap, (void *)(BG_SCREEN_ADDR(28)));
        LoadCompressedSpriteSheetUsingHeap(&gBattleAnimPicTable[GET_TRUE_SPRITE_INDEX(ANIM_TAG_ROCKS)]);
        LoadCompressedSpritePaletteUsingHeap(&gBattleAnimPaletteTable[GET_TRUE_SPRITE_INDEX(ANIM_TAG_ROCKS)]);
        CpuCopy16(gIntro3BgPal, gPlttBufferUnfaded, sizeof(gIntro3BgPal));
        gTasks[taskId].func = Task_IntroLoadPart3Graphics1;
    }
}

static void Task_IntroLoadPart3Graphics1(u8 taskId)
{
    SetGpuReg(REG_OFFSET_WIN0H, 0xF0);
    SetGpuReg(REG_OFFSET_WIN0V, 0xA0);
    SetGpuReg(REG_OFFSET_WININ, 0x3F);
    SetGpuReg(REG_OFFSET_WINOUT, 0);
    SetGpuReg(REG_OFFSET_BG2CNT, BGCNT_PRIORITY(0)
                               | BGCNT_CHARBASE(0)
                               | BGCNT_SCREENBASE(24)
                               | BGCNT_256COLOR
                               | BGCNT_WRAP
                               | BGCNT_AFF512x512);
    SetGpuReg(REG_OFFSET_BG1CNT, BGCNT_PRIORITY(1)
                               | BGCNT_CHARBASE(1)
                               | BGCNT_SCREENBASE(28)
                               | BGCNT_16COLOR
                               | BGCNT_TXT256x256);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_1
                                | DISPCNT_OBJ_1D_MAP
                                | DISPCNT_BG1_ON
                                | DISPCNT_BG2_ON
                                | DISPCNT_OBJ_ON
                                | DISPCNT_WIN0_ON);
    BeginNormalPaletteFade(0xFFFFFFFF, 0, 0x10, 0, RGB_WHITEALPHA);
    gTasks[taskId].data[0] = 0;
    gTasks[taskId].data[1] = 0xFFA0;
    gTasks[taskId].data[2] = 0xFF51;
    gTasks[taskId].data[3] = 0x100;
    PanFadeAndZoomScreen(0xFFA0, 0xFF51, 0x100, 0);
    gTasks[taskId].func = Task_IntroLoadPart3Graphics2;
}

static void Task_IntroLoadPart3Graphics2(u8 taskId)
{
    if (gTasks[taskId].data[0] != 32)
    {
        gTasks[taskId].data[0] += 4;
        SetGpuReg(REG_OFFSET_WIN0V, (gTasks[taskId].data[0] * 256) - (gTasks[taskId].data[0] - 160));
    }
    else
    {
        SetGpuReg(REG_OFFSET_WIN0V, 0x2080);
        gTasks[taskId].func = Task_IntroLoadPart3Graphics3;
    }
}

static void Task_IntroLoadPart3Graphics3(u8 taskId)
{
    gTasks[taskId].func = Task_IntroLoadPart3Graphics4;
}

static void Task_IntroLoadPart3Graphics4(u8 taskId)
{
    gTasks[taskId].data[0] = 0;
    gTasks[taskId].func = Task_IntroGroudonScene;
    ScanlineEffect_InitWave(0, 0xA0, 0x4, 4, 1, 4, 0);
}

static void Task_IntroGroudonScene(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    data[5]++;
    if ((u16)(data[0] - 1) < 7 && data[5] % 2 == 0)
        data[4] ^= 3;
    PanFadeAndZoomScreen(data[1], data[2] + data[4], data[3], 0);
    switch (data[0])
    {
    case 0:
        data[1] += 0x10;
        if (data[1] == 0xA0)
        {
            data[0]++;
            data[6] = 2;
            data[7] = 0x1E2;
            CreateGroudonRockSprites(taskId);
        }
        break;
    case 1:
        if (--data[6] == 0)
        {
            data[6] = 2;
            CpuCopy16(&gIntro3BgPal[data[7]], &gPlttBufferFaded[31], sizeof(u16));
            data[7] += 2;
            if (data[7] == 0x1EC)
                data[0]++;
        }
        break;
    case 2:
        if (--data[6] == 0)
        {
            data[6] = 2;
            data[0]++;
        }
        break;
    case 3:
        if (--data[6] == 0)
        {
            data[6] = 2;
            CpuCopy16(&gIntro3BgPal[data[7]], &gPlttBufferFaded[31], sizeof(u16));
            data[7] -= 2;
            if (data[7] == 0x1E0)
            {
                data[6] = 8;
                data[0]++;
            }
        }
        break;
    case 4:
        if (--data[6] == 0)
        {
            data[1] = -0x60;
            data[2] = 0xA9;
            data[6] = 3;
            data[0]++;
        }
        break;
    case 5:
        if (--data[6] == 0)
        {
            data[1] = 0x50;
            data[2] = 0x29;
            data[6] = 0x10;
            PlayCryInternal(SPECIES_GROUDON, 0, 100, 10, 0);
            data[0]++;
        }
        break;
    case 6:
        if (--data[6] == 0)
        {
            data[1] = 0x50;
            data[2] = 0x28;
            data[0]++;
        }
        break;
    case 7:
        data[1] += 4;
        data[2] += 4;
        data[6] += 0x666;
        data[3] = Sin((data[6] & 0xFF00) >> 8, 0x40) + 0x100;
        if (data[1] == 0x78)
        {
            BeginNormalPaletteFade(0xFFFFFFFE, 3, 0, 16, RGB_WHITE);
            data[3] = 0x100;
            data[4] = 0;
            data[0]++;
        }
        break;
    case 8:
        if (data[3])
            data[3] -= 8;
        else
            data[0]++;
        break;
    case 9:
        if (!gPaletteFade.active)
        {
            gTasks[taskId].func = Task_IntroLoadKyogreScene;
            gScanlineEffect.state = 3;
        }
        break;
    }
}

static void CreateGroudonRockSprites(u8 a0)
{
    int i;
    u8 spriteId;

    for (i = 0; i < 6; i++)
    {
        spriteId = CreateSprite(gAncientPowerRockSpriteTemplate, gIntroGroudonRockData[i][0], 0xA0, i);
        gSprites[spriteId].callback = SpriteCB_IntroGroudonRocks;
        gSprites[spriteId].oam.priority = 0;
        gSprites[spriteId].data[1] = i;
        gSprites[spriteId].data[4] = a0;
        StartSpriteAnim(&gSprites[spriteId], gIntroGroudonRockData[i][1]);
    }
}

static void SpriteCB_IntroGroudonRocks(struct Sprite *sprite)
{
    sprite->data[3]++;
    if (sprite->data[3] % 2 == 0)
        sprite->pos2.y ^= 3;

    switch(sprite->data[0])
    {
    case 0:
        sprite->data[2] += gIntroGroudonRockData[sprite->data[1]][2];
        sprite->pos1.y -= (sprite->data[2] & 0xFF00) >> 8;
        sprite->data[2] &= 0xFF;
        if (gTasks[sprite->data[4]].data[0] > 7)
            sprite->data[0]++;
        break;
    case 1:
        if (sprite->pos1.x < 0x78)
            sprite->pos1.x -= 2;
        else
            sprite->pos1.x += 2;

        if (sprite->pos1.y < 0x50)
            sprite->pos1.y -= 2;
        else
            sprite->pos1.y += 2;
        break;
    }
}

static void Task_IntroLoadKyogreScene(u8 taskId)
{
    ResetSpriteData();
    LZDecompressVram(gIntro3KyogreGfx, (void *)VRAM);
    LZDecompressVram(gIntro3KyogreTilemap, (void *)(BG_CHAR_ADDR(3)));
    LZDecompressVram(gIntro3KyogreBgTilemap, (void *)(BG_SCREEN_ADDR(28)));
    LoadCompressedSpriteSheet(gUnknown_085E4C88);
    LoadSpritePalette(gUnknown_085E4C98);
    BeginNormalPaletteFade(0xFFFFFFFE, 0, 0x10, 0, RGB_WHITEALPHA);
    gTasks[taskId].func = Task_IntroKyogreScene;
    gTasks[taskId].data[0] = 0;
    gTasks[taskId].data[1] = 0x150;
    gTasks[taskId].data[2] = 0x50;
    gTasks[taskId].data[6] = 0x10;
    gTasks[taskId].data[3] = 0x100;
    PanFadeAndZoomScreen(0x150, 0x50, 0x100, 0);
    ScanlineEffect_InitWave(0, 0xA0, 4, 4, 1, 6, 0);
}

static void Task_IntroKyogreScene(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    PanFadeAndZoomScreen(data[1], data[2], data[3], 0);

    switch (data[0])
    {
    case 0:
        if (--data[6] != 0)
            break;
        data[0]++;
    case 1:
        data[6] += 4;
        gTasks[taskId].data[1] = 0x158 - Sin(data[6], 0x100);
        gTasks[taskId].data[2] = 0x54 - Cos(data[6], 0x40);
        if (data[6] == 0x40)
        {
            data[6] = 0x19;
            data[7] = 1;
            data[0]++;
            CreateKyogreBubbleSprites_0(0);
        }
        break;
    case 2:
        if (--data[6] == 0)
        {
            gTasks[taskId].data[1] += 0x100;
            gTasks[taskId].data[2] -= 0x102;
            data[6] = 8;
            data[0]++;
            CreateKyogreBubbleSprites_0(0);
            CreateKyogreBubbleSprites_1();
        }
        break;
    case 3:
        if (--data[6] == 0)
        {
            gTasks[taskId].data[1] -= 0x100;
            gTasks[taskId].data[2] += 0x102;
            data[6] = 8;
            data[0]++;
        }
        break;
    case 4:
        if (--data[6] == 0)
        {
            gTasks[taskId].data[2] -= 0xFC;
            data[6] = 8;
            data[0]++;
        }
        break;
    case 5:
        if (--data[6] == 0)
        {
            gTasks[taskId].data[2] += 0xFC;
            if (data[7] != 0)
            {
                data[6] = 12;
                data[7]--;
                data[0] = 2;
            }
            else
            {
                data[6] = 1;
                data[0]++;
                PlayCryInternal(SPECIES_KYOGRE, 0, 120, 10, 0);
            }
        }
        break;
    case 6:
        if (--data[6] == 0)
        {
            data[6] = 4;
            data[7] = 0x1EA;
            data[0]++;
        }
        break;
    case 7:
        if (--data[6] == 0)
        {
            data[6] = 4;
            CpuCopy16(&gIntro3BgPal[data[7]], &gPlttBufferFaded[47], sizeof(u16));
            data[7] -= 2;
            if (data[7] == 0x1E0)
                data[0]++;
        }
        break;
    case 8:
        if (--data[6] == 0)
        {
            data[6] = 4;
            data[7] = 0x1E2;
            data[0]++;
        }
        break;
    case 9:
        if (--data[6] == 0)
        {
            data[6] = 4;
            CpuCopy16(&gIntro3BgPal[data[7]], &gPlttBufferFaded[47], sizeof(u16));
            data[7] += 2;
            if (data[7] == 0x1EE)
            {
                data[6] = 0x10;
                data[0]++;
            }
        }
        break;
    case 10:
        if (--data[6] == 0)
        {
            data[6] = 0;
            data[0]++;
            CreateKyogreBubbleSprites_0(taskId);
        }
        break;
    case 11:
        data[6] += 4;
        data[3] -= 8;
        gTasks[taskId].data[1] = Sin(data[6], 0x3C) + 0x58;
        if (data[6] == 0x40)
        {
            BeginNormalPaletteFade(0xFFFFFFFE, 3, 0, 16, RGB_WHITE);
            data[0]++;
        }
        break;
    case 12:
        data[6] += 4;
        data[3] -= 8;
        gTasks[taskId].data[1] = Sin(data[6], 0x14) + 0x80;
        if (data[6] == 0x80)
            data[0]++;
        break;
    case 13:
        if (!gPaletteFade.active)
        {
            gTasks[taskId].func = Task_IntroLoadClouds1;
            gScanlineEffect.state = 3;
        }
        break;
    }
}

static void CreateKyogreBubbleSprites_0(u8 taskId)
{
    int i;
    u8 spriteId;

    for (i = 0; i < 6; i++)
    {
        spriteId = CreateSprite(&gUnknown_085E4D14, gIntroKyogreBubbleData[i][0], gIntroKyogreBubbleData[i][1], i);
        gSprites[spriteId].invisible = TRUE;
        gSprites[spriteId].data[5] = taskId;
        gSprites[spriteId].data[6] = gIntroKyogreBubbleData[i][2];
        gSprites[spriteId].data[7] = 0x40;
    }
}

static void CreateKyogreBubbleSprites_1(void)
{
    int i;
    u8 spriteId;

    for (i = 0; i < 6; i++)
    {
        spriteId = CreateSprite(&gUnknown_085E4D14, gIntroKyogreBubbleData[i + 6][0], gIntroKyogreBubbleData[i + 6][1], i);
        gSprites[spriteId].invisible = TRUE;
        gSprites[spriteId].data[6] = gIntroKyogreBubbleData[i][2];
        gSprites[spriteId].data[7] = 0x40;
    }
}

static void SpriteCB_IntroKyogreBubbles(struct Sprite *sprite)
{
    switch(sprite->data[0])
    {
    case 0:
        if (sprite->data[6] == 0)
        {
            sprite->data[1] = (sprite->data[1] + 11) & 0xFF;
            sprite->pos2.x = Sin(sprite->data[1], 4);
            sprite->data[2] += 0x30;
            sprite->pos2.y = -(sprite->data[2] >> 8);
            if (sprite->animEnded)
                DestroySprite(sprite);
        }
        else if (--sprite->data[6] == 0)
        {
            StartSpriteAnim(sprite, 0);
            sprite->invisible = FALSE;
        }
        if (gTasks[sprite->data[5]].data[0] > 11)
            sprite->data[0]++;
        break;
    case 1:
        if (sprite->pos1.x < 120)
            sprite->pos1.x -= 3;
        else
            sprite->pos1.x += 3;

        if (sprite->pos1.y < 80)
            sprite->pos1.y -= 3;
        else
            sprite->pos1.y += 3;
        if ((u16)(sprite->pos1.y - 20) > 140)
            DestroySprite(sprite);
        break;
    }
}

static void Task_IntroLoadClouds1(u8 taskId)
{
    SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG0
                               | BLDCNT_TGT1_BG1
                               | BLDCNT_TGT1_BG2
                               | BLDCNT_EFFECT_LIGHTEN);
    SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(31, 31));
    SetGpuReg(REG_OFFSET_BLDY, 31);
    SetGpuReg(REG_OFFSET_BG0CNT, BGCNT_PRIORITY(0)
                               | BGCNT_CHARBASE(0)
                               | BGCNT_SCREENBASE(24)
                               | BGCNT_16COLOR
                               | BGCNT_TXT512x256);
    SetGpuReg(REG_OFFSET_BG1CNT, BGCNT_PRIORITY(0)
                               | BGCNT_CHARBASE(1)
                               | BGCNT_SCREENBASE(26)
                               | BGCNT_16COLOR
                               | BGCNT_TXT512x256);
    SetGpuReg(REG_OFFSET_BG2CNT, BGCNT_PRIORITY(2)
                               | BGCNT_CHARBASE(1)
                               | BGCNT_SCREENBASE(28)
                               | BGCNT_16COLOR
                               | BGCNT_TXT256x256);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0
                                | DISPCNT_OBJ_1D_MAP
                                | DISPCNT_BG0_ON
                                | DISPCNT_BG1_ON
                                | DISPCNT_BG2_ON
                                | DISPCNT_OBJ_ON
                                | DISPCNT_WIN0_ON);
    SetGpuReg(REG_OFFSET_BG0HOFS, 80);
    SetGpuReg(REG_OFFSET_BG0VOFS, 0);
    SetGpuReg(REG_OFFSET_BG1HOFS, -80);
    SetGpuReg(REG_OFFSET_BG1VOFS, 0);
    SetGpuReg(REG_OFFSET_BG2HOFS, 0);
    SetGpuReg(REG_OFFSET_BG2VOFS, 0);
    LZDecompressVram(gIntro3CloudsGfx, (void *)VRAM);
    LZDecompressVram(gIntro3CloudsGfx, (void *)(BG_CHAR_ADDR(1)));
    LZDecompressVram(gIntro3Clouds3Tilemap, (void *)(BG_SCREEN_ADDR(28)));
    gTasks[taskId].func = Task_IntroLoadClouds2;
}

static void Task_IntroLoadClouds2(u8 taskId)
{
    LZDecompressVram(gIntro3Clouds1Tilemap, (void *)(BG_CHAR_ADDR(3)));
    LZDecompressVram(gIntro3Clouds2Tilemap, (void *)(BG_SCREEN_ADDR(26)));
    gTasks[taskId].func = Task_IntroLoadClouds3;
}

static void Task_IntroLoadClouds3(u8 taskId)
{
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
    SetGpuReg(REG_OFFSET_BLDALPHA, 0);
    SetGpuReg(REG_OFFSET_BLDY, 0);
    gTasks[taskId].func = Task_IntroCloudScene;
    gTasks[taskId].data[0] = 0;
    gTasks[taskId].data[6] = 16;
}

static void Task_IntroCloudScene(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    SetGpuReg(REG_OFFSET_BG0HOFS, (data[6] >> 8));
    SetGpuReg(REG_OFFSET_BG1HOFS, -(data[6] >> 8));

    switch (data[0])
    {
    case 0:
        if (--data[6] == 0)
        {
            BeginNormalPaletteFade(0xFFFFFFFE, 0, 16, 0, RGB_WHITEALPHA);
            data[6] = 0x5000;
            data[0]++;
        }
        break;
    case 1:
        if (data[6] == 0x2800)
            BeginNormalPaletteFade(0x0000FFFE, 3, 0, 16, RGB(9, 10, 10));

        if (data[6] != 0)
            data[6] -= 0x80;
        else if (!gPaletteFade.active)
            gTasks[taskId].func = Task_IntroLoadRayquazaLightningScene;
        break;
    }
}

static void Task_IntroLoadRayquazaLightningScene(u8 taskId)
{
    LZDecompressVram(gIntro3RayquazaTilemap, (void *)(BG_SCREEN_ADDR(28)));
    LZDecompressVram(gIntro3Clouds4Tilemap, (void *)(BG_CHAR_ADDR(3)));
    LZDecompressVram(gIntro3RayquazaGfx, (void *)(BG_CHAR_ADDR(1)));
    LZDecompressVram(gIntro3Clouds2Gfx, (void *)VRAM);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0
                                | DISPCNT_OBJ_1D_MAP
                                | DISPCNT_BG0_ON
                                | DISPCNT_BG2_ON
                                | DISPCNT_OBJ_ON
                                | DISPCNT_WIN0_ON);
    gTasks[taskId].func = Task_IntroRayquazaLightningScene;
    gTasks[taskId].data[0] = 0;
    gTasks[taskId].data[6] = 1;
    gTasks[taskId].data[7] = 0;
    LoadCompressedSpriteSheetUsingHeap(gIntroRayquazaLightningSpriteSheet);
    LoadSpritePalettes(gIntroRayquazaLightningPalette);
}

static void Task_IntroRayquazaLightningScene(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    u8 spriteId;

    switch (data[0])
    {
    case 0:
        if (--data[6] == 0)
        {
            CreateSprite(&gIntroLightningSprite, 200, 48, 0);
            spriteId = CreateSprite(&gIntroLightningSprite, 200, 80, 1);
            StartSpriteAnim(&gSprites[spriteId], 1);
            spriteId = CreateSprite(&gIntroLightningSprite, 200, 112, 2);
            StartSpriteAnim(&gSprites[spriteId], 2);
            data[0]++;
            data[6] = 72;
        }
        break;
    case 1:
        if (--data[6] == 0)
        {
            CreateSprite(&gIntroLightningSprite, 40, 48, 0);
            spriteId = CreateSprite(&gIntroLightningSprite, 40, 80, 1);
            StartSpriteAnim(&gSprites[spriteId], 1);
            spriteId = CreateSprite(&gIntroLightningSprite, 40, 112, 2);
            StartSpriteAnim(&gSprites[spriteId], 2);
            data[0]++;
            data[6] = 48;
        }
        break;
    case 2:
        if (--data[6] == 0)
            gTasks[taskId].func = Task_IntroLoadRayquazaGlowScene;
        break;
    }
}

static void SpriteCB_IntroRayquazaLightning(struct Sprite *sprite)
{
    if (sprite->animEnded)
        sprite->invisible = TRUE;

    switch(sprite->data[0])
    {
    case 0:
        sprite->data[1] = 0x1C2;
        sprite->data[0]++;
    case 1:
        CpuCopy16(&gIntro3BgPal[sprite->data[1]], &gPlttBufferFaded[93], 2);
        sprite->data[1] += 2;
        if (sprite->data[1] != 0x1CE)
            break;
        sprite->data[1] = 0x1CC;
        sprite->data[2] = 4;
        sprite->data[0]++;
    case 2:
        if (--sprite->data[2] == 0)
        {
            sprite->data[2] = 4;
            CpuCopy16(&gIntro3BgPal[sprite->data[1]], &gPlttBufferFaded[93], 2);
            sprite->data[1] -= 2;
            if (sprite->data[1] == 0x1C0)
                DestroySprite(sprite);
        }
        break;
    }
}

static void Task_IntroLoadRayquazaGlowScene(u8 taskId)
{
    u8 newTaskId;

    LoadCompressedSpriteSheet(gIntroRayquazaGlowSpriteSheet);
    LoadSpritePalettes(gIntroRayquazaGlowPalette);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0
                                | DISPCNT_OBJ_1D_MAP
                                | DISPCNT_BG0_ON
                                | DISPCNT_BG2_ON
                                | DISPCNT_OBJ_ON
                                | DISPCNT_WIN0_ON);
    gTasks[taskId].func = Task_IntroRayquazaGlowScene_0;
    BeginNormalPaletteFade(0x0000FFDE, 0, 16, 0, RGB(9, 10, 10));
    gTasks[taskId].data[0] = 0;
    gTasks[taskId].data[1] = 0xA8;
    gTasks[taskId].data[2] = -0x10;
    gTasks[taskId].data[3] = -0x88;
    gTasks[taskId].data[4] = -0x10;
    newTaskId = CreateTask(Task_IntroRayquazaGlowScene_1, 0);
    gTasks[newTaskId].data[4] = taskId;
}

static void Task_IntroRayquazaGlowScene_0(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    if (data[7] % 2 == 0)
        data[6] ^= 2;

    data[7]++;

    switch(data[0])
    {
    case 0:
        if ((data[7] & 1) != 0)
        {
            data[1] -= 2;
            data[2]++;
            data[3] += 2;
            data[4]++;
        }
        if (data[1] == 0x68)
        {
            data[0]++;
            data[5] = 1;
        }
        break;
    case 1:
        data[0]++;
        data[5] = 4;
        break;
    case 2:
        data[1] += 4;
        data[2] -= 2;
        data[3] -= 4;
        data[4] -= 2;
        if (!gPaletteFade.active)
        {
            data[5] = 0x8C;
            data[0]++;
        }
        break;
    case 3:
        if (--data[5] == 0)
            gTasks[taskId].func = Task_EndIntroMovie;
        break;
    }
}

static void Task_EndIntroMovie(u8 taskId)
{
    DestroyTask(taskId);
    SetMainCallback2(MainCB2_EndIntro);
}

static void Task_IntroRayquazaGlowScene_1(u8 taskId)
{
    // Note: data[4] contains the taskId of Task_IntroRayquazaGlowScene_0
    u8 spriteId;
    s16 *data = gTasks[taskId].data;
    data[2]++;

    switch(data[0])
    {
    case 0:
        if ((data[2] & 1) != 0)
        {
            CpuCopy16(&gIntro3BgPal[0x1A2 + data[1] * 2], &gPlttBufferFaded[94], 2);
            data[1]++;
        }
        if (data[1] == 6)
        {
            data[0]++;
            data[1] = 0;
            data[3] = 10;
        }
        break;
    case 1:
        if (data[3] == 0)
        {
            if ((data[2] & 1) != 0)
            {
                CpuCopy16(&gIntro3BgPal[0x1A2 + data[1] * 2], &gPlttBufferFaded[88], 2);
                data[1]++;
            }
            if (data[1] == 6)
            {
                data[0]++;
                data[3] = 10;
            }
        }
        else
        {
            data[3]--;
        }
        break;
    case 2:
        if (data[3] == 0)
        {
            if ((data[2] & 1) != 0)
            {
                CpuCopy16(&gIntro3BgPal[0x182 + data[1] * 2], &gPlttBufferFaded[92], 2);
                data[1]++;
            }
            if (data[1] == 6)
            {
                spriteId = CreateSprite(&gIntroRayquazaHyperbeamSprite, 120, 88, 15);
                PlaySE(SE_INTRO_BLAST);
                gSprites[spriteId].invisible = TRUE;
                gSprites[spriteId].data[3] = data[4];
                data[0]++;
                data[3] = 16;
            }
        }
        else
        {
            data[3]--;
        }
        break;
    case 3:
        if ((data[2] & 1) != 0)
        {
            if (--data[3] != 0)
            {
                BlendPalette(0x50, 16, data[3], RGB(9, 10, 10));
                CpuCopy16(&gIntro3BgPal[0x1AC], &gPlttBufferFaded[94], 2);
                CpuCopy16(&gIntro3BgPal[0x1AC], &gPlttBufferFaded[88], 2);
                CpuCopy16(&gIntro3BgPal[0x18C], &gPlttBufferFaded[92], 2);
            }
            else
            {
                data[0]++;
                data[3] = 53;
            }
        }
        break;
    case 4:
        if (--data[3] == 0)
        {
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_WHITE);
            data[0]++;
        }
        break;
    case 5:
        if (!gPaletteFade.active)
            DestroyTask(taskId);
        break;
    }
}

static void intro_reset_and_hide_bgs(void)
{
    SetGpuReg(REG_OFFSET_DISPCNT, 0);
    SetGpuReg(REG_OFFSET_BG3HOFS, 0);
    SetGpuReg(REG_OFFSET_BG3VOFS, 0);
    SetGpuReg(REG_OFFSET_BG2HOFS, 0);
    SetGpuReg(REG_OFFSET_BG2VOFS, 0);
    SetGpuReg(REG_OFFSET_BG1HOFS, 0);
    SetGpuReg(REG_OFFSET_BG1VOFS, 0);
    SetGpuReg(REG_OFFSET_BG0HOFS, 0);
    SetGpuReg(REG_OFFSET_BG0VOFS, 0);
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
    SetGpuReg(REG_OFFSET_BLDALPHA, 0);
    SetGpuReg(REG_OFFSET_BLDY, 0);
}

static void Task_IntroWaterDrops_1(u8 taskId)
{
    switch (gTasks[taskId].data[0])
    {
    case 0:
    default:
        SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_EFFECT_BLEND
                                   | BLDCNT_TGT2_BG0
                                   | BLDCNT_TGT2_BG1
                                   | BLDCNT_TGT2_BG2
                                   | BLDCNT_TGT2_BG3
                                   | BLDCNT_TGT2_OBJ
                                   | BLDCNT_TGT2_BD);
        SetGpuReg(REG_OFFSET_BLDALPHA, gIntroWaterDropAlphaBlend[31]);
        SetGpuReg(REG_OFFSET_BLDY, 0);
        gTasks[taskId].data[1] = 0x40;
        gTasks[taskId].data[0]++;
        break;
    case 1:
        if (gTasks[taskId].data[1] != 0)
        {
            u8 tmp;

            gTasks[taskId].data[1]--;
            tmp = gTasks[taskId].data[1] / 2;
            SetGpuReg(REG_OFFSET_BLDALPHA, gIntroWaterDropAlphaBlend[tmp]);
        }
        else
        {
            SetGpuReg(REG_OFFSET_BLDALPHA, gIntroWaterDropAlphaBlend[0]);
            gTasks[taskId].data[1] = 0x10;
            gTasks[taskId].data[0]++;
        }
        break;
    case 2:
        SetGpuReg(REG_OFFSET_BLDCNT, 0);
        SetGpuReg(REG_OFFSET_BLDALPHA, 0);
        SetGpuReg(REG_OFFSET_BLDY, 0);
        DestroyTask(taskId);
        break;
    }
}

static void Task_IntroWaterDrops_2(u8 taskId)
{
    switch (gTasks[taskId].data[0])
    {
    case 0:
    default:
        SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_EFFECT_BLEND
                                   | BLDCNT_TGT2_BG0
                                   | BLDCNT_TGT2_BG1
                                   | BLDCNT_TGT2_BG2
                                   | BLDCNT_TGT2_BG3
                                   | BLDCNT_TGT2_OBJ
                                   | BLDCNT_TGT2_BD);
        SetGpuReg(REG_OFFSET_BLDALPHA, gIntroWaterDropAlphaBlend[0]);
        SetGpuReg(REG_OFFSET_BLDY, 0);
        gTasks[taskId].data[1] = 0;
        gTasks[taskId].data[0]++;
        break;
    case 1:
        if (gTasks[taskId].data[1] < 62)
        {
            u8 tmp;

            gTasks[taskId].data[1]++;
            tmp = gTasks[taskId].data[1] / 2;
            SetGpuReg(REG_OFFSET_BLDALPHA, gIntroWaterDropAlphaBlend[tmp]);
        }
        else
        {
            SetGpuReg(REG_OFFSET_BLDALPHA, gIntroWaterDropAlphaBlend[31]);
            gTasks[taskId].data[1] = 0x10;
            gTasks[taskId].data[0]++;
        }
        break;
    case 2:
        if (gTasks[taskId].data[1] != 0)
        {
            gTasks[taskId].data[1]--;
        }
        else
        {
            SetGpuReg(REG_OFFSET_BLDCNT, 0);
            SetGpuReg(REG_OFFSET_BLDALPHA, 0);
            SetGpuReg(REG_OFFSET_BLDY, 0);
            DestroyTask(taskId);
        }
        break;
    }
}

void PanFadeAndZoomScreen(u16 screenX, u16 screenY, u16 zoom, u16 alpha)
{
    struct BgAffineSrcData src;
    struct BgAffineDstData dest;

    src.texX = 0x8000;
    src.texY = 0x8000;
    src.scrX = screenX;
    src.scrY = screenY;
    src.sx = zoom;
    src.sy = zoom;
    src.alpha = alpha;
    BgAffineSet(&src, &dest, 1);
    SetGpuReg(REG_OFFSET_BG2PA, dest.pa);
    SetGpuReg(REG_OFFSET_BG2PB, dest.pb);
    SetGpuReg(REG_OFFSET_BG2PC, dest.pc);
    SetGpuReg(REG_OFFSET_BG2PD, dest.pd);
    SetGpuReg(REG_OFFSET_BG2X_L, dest.dx);
    SetGpuReg(REG_OFFSET_BG2X_H, dest.dx >> 16);
    SetGpuReg(REG_OFFSET_BG2Y_L, dest.dy);
    SetGpuReg(REG_OFFSET_BG2Y_H, dest.dy >> 16);
}

static void sub_816F318(struct Sprite *sprite)
{
    u8 r0;

    if (sprite->data[2] >= 192)
    {
        if (sprite->data[3] != 0)
        {
            sprite->data[3]--;
        }
        else
        {
            sprite->invisible = FALSE;
            SetOamMatrix(sprite->data[1], sprite->data[2], 0, 0, sprite->data[2]);
            sprite->data[2] = (sprite->data[2] * 95) / 100;
            r0 = (sprite->data[2] - 192) / 128 + 9;
            if (r0 > 15)
                r0 = 15;
            sprite->oam.paletteNum = r0;
        }
    }
    else
    {
        DestroySprite(sprite);
    }
}

static void sub_816F3A4(struct Sprite *sprite)
{
    if (gSprites[sprite->data[7]].data[7] != 0)
    {
        sprite->invisible = TRUE;
        sprite->pos1.x += sprite->pos2.x;
        sprite->pos1.y += sprite->pos2.y;
        StartSpriteAnim(sprite, 3);
        sprite->data[2] = 1024;
        sprite->data[3] = 8 * (sprite->data[1] & 3);
        sprite->callback = sub_816F318;
        sprite->oam.shape = SPRITE_SHAPE(64x32);
        sprite->oam.size = SPRITE_SIZE(64x32);
        CalcCenterToCornerVec(sprite, SPRITE_SHAPE(64x32), SPRITE_SIZE(64x32), ST_OAM_AFFINE_ERASE);
    }
    else
    {
        sprite->pos2.x = gSprites[sprite->data[7]].pos2.x;
        sprite->pos2.y = gSprites[sprite->data[7]].pos2.y;
        sprite->pos1.x = gSprites[sprite->data[7]].pos1.x;
        sprite->pos1.y = gSprites[sprite->data[7]].pos1.y;
    }
}

static void sub_816F454(struct Sprite *sprite)
{
    if (sprite->data[0] != 0)
        sprite->callback = sub_816F46C;
}

static void sub_816F46C(struct Sprite *sprite)
{
    if (sprite->pos1.x <= 116)
    {
        sprite->pos1.y += sprite->pos2.y;
        sprite->pos2.y = 0;
        sprite->pos1.x += 4;
        sprite->pos2.x = -4;
        sprite->data[4] = 128;
        sprite->callback = sub_816F5B4;
    }
    else
    {
        u16 data2;
        u16 data3;
        u16 data4;
        s16 sin1;
        s16 sin2;
        s16 sin3;
        s16 sin4;
        s16 var1;
        s16 var2;
        s16 var3;
        s16 var4;
        s16 temp;

        data4 = sprite->data[4];
        sin1 = gSineTable[(u8)data4];
        sin2 = gSineTable[(u8)(data4 + 64)];
        sprite->data[4] += 2;
        sprite->pos2.y = sin1 / 32;
        sprite->pos1.x--;
        if (sprite->pos1.x & 1)
            sprite->pos1.y++;
        temp = -sin2 / 16;
        data2 = sprite->data[2];
        data3 = sprite->data[3];
        sin3 = gSineTable[(u8)(temp - 16)];
        sin4 = gSineTable[(u8)(temp + 48)];
        var1 = sin4 * data2 / 256;
        var2 = -sin3 * data3 / 256;
        var3 = sin3 * data2 / 256;
        var4 = sin4 * data3 / 256;
        SetOamMatrix(sprite->data[1], data2, 0, 0, data3);
        SetOamMatrix(sprite->data[1] + 1, var1, var3, var2, var4);
        SetOamMatrix(sprite->data[1] + 2, var1, var3, var2 * 2, var4 * 2);
    }
}

static void sub_816F5B4(struct Sprite *sprite)
{
    SetOamMatrix(sprite->data[1], sprite->data[6] + 64, 0, 0, sprite->data[6] + 64);
    SetOamMatrix(sprite->data[1] + 1, sprite->data[6] + 64, 0, 0, sprite->data[6] + 64);
    SetOamMatrix(sprite->data[1] + 2, sprite->data[6] + 64, 0, 0, sprite->data[6] + 64);
    if (sprite->data[4] != 64)
    {
        u16 data4;

        sprite->data[4] -= 8;
        data4 = sprite->data[4];
        sprite->pos2.x = gSineTable[(u8)(data4 + 64)] / 64;
        sprite->pos2.y = gSineTable[(u8)data4] / 64;
    }
    else
    {
        sprite->data[4] = 0;
        sprite->callback = sub_816F660;
    }
}

static void sub_816F660(struct Sprite *sprite)
{
    if (sprite->data[0] != 2)
    {
        s16 r2;

        sprite->data[4] += 8;
        r2 = gSineTable[(u8)sprite->data[4]] / 16 + 64;
        sprite->pos2.x = gSineTable[(u8)(r2 + 64)] / 64;
        sprite->pos2.y = gSineTable[(u8)r2] / 64;
    }
    else
    {
        sprite->callback = SpriteCB_WaterDropFall;
    }
}

static void SpriteCB_WaterDropFall(struct Sprite *sprite)
{
    if (sprite->pos1.y < sprite->data[5])
    {
        sprite->pos1.y += 4;
    }
    else
    {
        sprite->data[7] = 1;
        sprite->invisible = TRUE;
        sprite->pos1.x += sprite->pos2.x;
        sprite->pos1.y += sprite->pos2.y;
        StartSpriteAnim(sprite, 3);
        sprite->data[2] = 1024;
        sprite->data[3] = 8 * (sprite->data[1] & 3);
        sprite->callback = sub_816F318;
        sprite->oam.shape = SPRITE_SHAPE(64x32);
        sprite->oam.size = SPRITE_SIZE(64x32);
        CalcCenterToCornerVec(sprite, SPRITE_SHAPE(64x32), SPRITE_SIZE(64x32), ST_OAM_AFFINE_ERASE);
    }
}

//Duplicate function
static void SpriteCB_WaterDropFall_2(struct Sprite *sprite)
{
    if (sprite->pos1.y < sprite->data[5])
    {
        sprite->pos1.y += 4;
    }
    else
    {
        sprite->data[7] = 1;
        sprite->invisible = TRUE;
        sprite->pos1.x += sprite->pos2.x;
        sprite->pos1.y += sprite->pos2.y;
        StartSpriteAnim(sprite, 3);
        sprite->data[2] = 1024;
        sprite->data[3] = 8 * (sprite->data[1] & 3);
        sprite->callback = sub_816F318;
        sprite->oam.shape = SPRITE_SHAPE(64x32);
        sprite->oam.size = SPRITE_SIZE(64x32);
        CalcCenterToCornerVec(sprite, SPRITE_SHAPE(64x32), SPRITE_SIZE(64x32), ST_OAM_AFFINE_ERASE);
    }
}

static u8 CreateWaterDrop(s16 x, s16 y, u16 c, u16 d, u16 e, u8 fallImmediately)
{
    u8 spriteId;
    u8 oldSpriteId;

    spriteId = CreateSprite(&gIntroWaterDropSprite, x, y, 1);
    gSprites[spriteId].data[0] = 0;
    gSprites[spriteId].data[7] = 0;
    gSprites[spriteId].data[1] = d;
    gSprites[spriteId].data[2] = c;
    gSprites[spriteId].data[3] = c;
    gSprites[spriteId].data[5] = e;
    gSprites[spriteId].data[6] = c;
    gSprites[spriteId].oam.affineMode = ST_OAM_AFFINE_DOUBLE;
    gSprites[spriteId].oam.matrixNum = d;
    CalcCenterToCornerVec(&gSprites[spriteId], SPRITE_SHAPE(32x32), SPRITE_SIZE(32x32), ST_OAM_AFFINE_ERASE);
    StartSpriteAnim(&gSprites[spriteId], 2);
    if (!fallImmediately)
        gSprites[spriteId].callback = sub_816F454;
    else
        gSprites[spriteId].callback = SpriteCB_WaterDropFall_2;
    oldSpriteId = spriteId;

    spriteId = CreateSprite(&gIntroWaterDropSprite, x, y, 1);
    gSprites[spriteId].data[7] = oldSpriteId;
    gSprites[spriteId].data[1] = d + 1;
    gSprites[spriteId].oam.affineMode = ST_OAM_AFFINE_DOUBLE;
    gSprites[spriteId].oam.matrixNum = d + 1;
    CalcCenterToCornerVec(&gSprites[spriteId], SPRITE_SHAPE(32x32), SPRITE_SIZE(32x32), ST_OAM_AFFINE_ERASE);
    gSprites[spriteId].callback = sub_816F3A4;

    spriteId = CreateSprite(&gIntroWaterDropSprite, x, y, 1);
    gSprites[spriteId].data[7] = oldSpriteId;
    gSprites[spriteId].data[1] = d + 2;
    StartSpriteAnim(&gSprites[spriteId], 1);
    gSprites[spriteId].oam.affineMode = ST_OAM_AFFINE_DOUBLE;
    gSprites[spriteId].oam.matrixNum = d + 2;
    CalcCenterToCornerVec(&gSprites[spriteId], SPRITE_SHAPE(32x32), SPRITE_SIZE(32x32), ST_OAM_AFFINE_ERASE);
    gSprites[spriteId].callback = sub_816F3A4;

    SetOamMatrix(d, c + 32, 0, 0, c + 32);
    SetOamMatrix(d + 1, c + 32, 0, 0, c + 32);
    SetOamMatrix(d + 2, c + 32, 0, 0, 2 * (c + 32));

    return oldSpriteId;
}

static void SpriteCB_IntroGraphicsBicycle(struct Sprite *sprite)
{
    switch (sprite->data[0])
    {
    case 0:
        StartSpriteAnimIfDifferent(sprite, 0);
        sprite->pos1.x--;
        break;
    case 1:
        StartSpriteAnimIfDifferent(sprite, 0);
        if (gIntroFrameCounter & 7)
            return;
        sprite->pos1.x++;
        break;
    case 2:
        if (sprite->pos1.x <= 120 || gIntroFrameCounter & 7)
            sprite->pos1.x++;
        break;
    case 3:
        break;
    case 4:
        if (sprite->pos1.x > -32)
            sprite->pos1.x -= 2;
        break;
    }
    if (gIntroFrameCounter & 7)
        return;
    if (sprite->pos2.y != 0)
    {
        sprite->pos2.y = 0;
    }
    else
    {
        switch (Random() & 3)
        {
        case 0:
            sprite->pos2.y = -1;
            break;
        case 1:
            sprite->pos2.y = 1;
            break;
        case 2:
        case 3:
            sprite->pos2.y = 0;
            break;
        }
    }
}

static void SpriteCB_IntroGraphicsFlygon(struct Sprite *sprite)
{
    switch (sprite->data[0])
    {
    case 0:
        break;
    case 1:
        if (sprite->pos2.x + sprite->pos1.x < 304)
            sprite->pos2.x += 8;
        else
            sprite->data[0] = 2;
        break;
    case 2:
        if (sprite->pos2.x + sprite->pos1.x > 120)
            sprite->pos2.x -= 1;
        else
            sprite->data[0] = 3;
        break;
    case 3:
        if (sprite->pos2.x > 0)
            sprite->pos2.x -= 2;
        break;
    }
    sprite->pos2.y = Sin((u8)sprite->data[1], 8) - gIntroGraphicsFlygonYOffset;
    sprite->data[1] += 4;
}

static void sub_816FB38(struct Sprite *sprite)
{
    switch (sprite->data[0])
    {
    case 0:
        if (sprite->data[1] != 0)
        {
            sprite->data[1]--;
        }
        else
        {
            sprite->invisible = FALSE;
            StartSpriteAffineAnim(sprite, 1);
            sprite->data[0]++;
        }
        break;
    case 1:
        if (gIntroFrameCounter == 0x90)
        {
            sprite->data[0]++;
            sprite->data[1] = 9;
            sprite->data[3] = 2;
        }
        break;
    case 2:
        if (sprite->data[3] == 0)
        {
            sprite->data[3] = 2;
            if (sprite->data[1] != 0)
            {
                CpuCopy16(&gIntro1GameFreakTextFadePal[sprite->data[1]], &gPlttBufferFaded[0x11F], 2);
                CpuCopy16(&gIntro1GameFreakTextFadePal[sprite->data[1] + 0x10], &gPlttBufferFaded[0x114], 2);
                CpuCopy16(&gIntro1GameFreakTextFadePal[sprite->data[1] + 0x20], &gPlttBufferFaded[0x11A], 2);
                sprite->data[1]--;
            }
            else
            {
                CpuCopy16(&gIntro1GameFreakTextFadePal[sprite->data[1]], &gPlttBufferFaded[0x11F], 2);
                CpuCopy16(&gIntro1GameFreakTextFadePal[sprite->data[1] + 0x10], &gPlttBufferFaded[0x114], 2);
                CpuCopy16(&gIntro1GameFreakTextFadePal[sprite->data[1] + 0x20], &gPlttBufferFaded[0x11A], 2);
                sprite->data[0]++;
            }
        }
        else
        {
            sprite->data[3]--;
        }
        break;
    case 3:
        if (sprite->data[3] != 0)
        {
            sprite->data[3]--;
        }
        else
        {
            sprite->data[3] = 2;
            if (sprite->data[1] < 10)
            {
                CpuCopy16(&gIntro1GameFreakTextFadePal[sprite->data[1]], &gPlttBufferFaded[0x11F], 2);
                CpuCopy16(&gIntro1GameFreakTextFadePal[sprite->data[1] + 0x10], &gPlttBufferFaded[0x114], 2);
                CpuCopy16(&gIntro1GameFreakTextFadePal[sprite->data[1] + 0x20], &gPlttBufferFaded[0x11A], 2);
                sprite->data[1]++;
            }
            else
            {
                sprite->data[0]++;
            }
        }
        break;
    case 4:
        if (gIntroFrameCounter == 0x110)
        {
            StartSpriteAffineAnim(sprite, 2);
            sprite->oam.objMode = ST_OAM_OBJ_BLEND;
            sprite->data[0]++;
        }
        break;
    case 5:
        sprite->data[3] += gUnknown_085E4F48[sprite->data[2]];
        sprite->pos2.x = (sprite->data[3] & 0xFF00) >> 8;
        if (sprite->data[2] < 4)
        {
            s16 temp = sprite->pos2.x;
            sprite->pos2.x = -temp;
        }
        if (sprite->affineAnimEnded)
            DestroySprite(sprite);
        break;
    }
}

static void sub_816FD44(struct Sprite *sprite)
{
    switch(sprite->data[0])
    {
    case 0:
        if (gIntroFrameCounter == 0x80)
        {
            sprite->invisible = FALSE;
            sprite->data[0]++;
        }
        break;
    case 1:
        if (gIntroFrameCounter == 0x110)
        {
            StartSpriteAffineAnim(sprite, 3);
            sprite->data[0]++;
        }
        break;
    case 2:
        if (sprite->affineAnimEnded)
            DestroySprite(sprite);
        break;
    }
}

static u8 CreatePart1Animations(s16 a0, s16 a1, s16 a2)
{
    u16 i;
    u8 spriteId;

    for (i = 0; i < 9; i++)
    {
        spriteId = CreateSprite(&gUnknown_085E4F5C, gUnknown_085E4E94[i][1] + a0, a1 - 4, 0);
        gSprites[spriteId].data[0] = 0;
        gSprites[spriteId].data[1] = gUnknown_085E4FA4[i];
        gSprites[spriteId].data[2] = i;
        gSprites[spriteId].invisible = TRUE;
        gSprites[spriteId].oam.matrixNum = i + 12;
        StartSpriteAnim(&gSprites[spriteId], gUnknown_085E4E94[i][0]);
        StartSpriteAffineAnim(&gSprites[spriteId], 0);
    }
    spriteId = CreateSprite(&gUnknown_085E4F8C, 120, a1 - 6, 0);
    gSprites[spriteId].data[0] = 0;
    gSprites[spriteId].invisible = TRUE;
    gSprites[spriteId].oam.matrixNum = i + 12;
    StartSpriteAffineAnim(&gSprites[spriteId], 1);
    return spriteId;
}

static void sub_816FEDC(struct Sprite *sprite)
{
    sprite->data[7]++;

    if (sprite->data[0] != 0)
    {
        s16 sin1;
        s16 sin2;

        s16 a, b, c, d;

        sin1 = gSineTable[(u8)sprite->data[2]];
        sin2 = gSineTable[(u8)(sprite->data[2] + 64)];

        d = Q_8_8_TO_INT(sin2 * sprite->data[1]);
        c = Q_8_8_TO_INT(-sin1 * sprite->data[1]);
        b = Q_8_8_TO_INT(sin1 * sprite->data[1]);
        a = Q_8_8_TO_INT(sin2 * sprite->data[1]);

        SetOamMatrix(1, a, b, c, d);
    }

    switch (sprite->data[0])
    {
    case 0:
    default:
        sprite->oam.affineMode = ST_OAM_AFFINE_DOUBLE;
        sprite->oam.matrixNum = 1;
        CalcCenterToCornerVec(sprite, SPRITE_SHAPE(64x32), SPRITE_SIZE(64x32), ST_OAM_AFFINE_DOUBLE);
        sprite->invisible = FALSE;
        sprite->data[0] = 1;
        sprite->data[1] = 0x80;
        sprite->data[2] = 0;
        sprite->data[3] = 0;
        break;
    case 1:
        sprite->pos2.x = -Sin((u8)sprite->data[3], 140);
        sprite->pos2.y = -Sin((u8)sprite->data[3], 120);
        sprite->data[1] += 7;
        sprite->data[3] += 3;
        if (sprite->pos1.x + sprite->pos2.x <= -16)
        {
            sprite->oam.priority = 3;
            sprite->data[0]++;
            sprite->pos1.x = 20;
            sprite->pos1.y = 40;
            sprite->data[1] = 0x200;
            sprite->data[2] = 0;
            sprite->data[3] = 0x10;
        }
        break;
    case 2:
        sprite->pos2.x = Sin((u8)sprite->data[3], 34);
        sprite->pos2.y = -Cos((u8)sprite->data[3], 60);
        sprite->data[1] += 2;
        if (sprite->data[7] % 5 == 0)
            sprite->data[3]++;
        break;
    }
}

static void SpriteCB_IntroRayquazaHyperbeam(struct Sprite *sprite)
{
    u16 foo;

    //I'm not sure why a switch statement was used here.
    //if (sprite->data[0] != 1) would have been more appropriate.
    switch (sprite->data[0])
    {
    case 0:
    default:
        sprite->invisible = FALSE;
        sprite->oam.affineMode = ST_OAM_AFFINE_DOUBLE;
        sprite->oam.matrixNum = 18;
        CalcCenterToCornerVec(sprite, SPRITE_SHAPE(64x64), SPRITE_SIZE(64x64), ST_OAM_AFFINE_DOUBLE);
        sprite->data[1] = 0;
        sprite->data[0] = 1;
        //fall through
    case 1:
        sprite->data[7]++;
        if (sprite->data[7] & 1)
        {
            sprite->invisible = TRUE;
        }
        else
        {
            sprite->invisible = FALSE;
            if (sprite->data[1] < 64)
                sprite->data[1]++;
        }
        foo = 256 - gSineTable[(u8)sprite->data[1]] / 2;
        SetOamMatrix(18, foo, 0, 0, foo);
        break;
    }
}
