#include "global.h"
#include "bg.h"
#include "decompress.h"
#include "expansion_intro.h"
#include "gpu_regs.h"
#include "libgcnmultiboot.h"
#include "link.h"
#include "load_save.h"
#include "m4a.h"
#include "main.h"
#include "intro_frlg.h"
#include "malloc.h"
#include "menu.h"
#include "new_game.h"
#include "palette.h"
#include "random.h"
#include "save.h"
#include "scanline_effect.h"
#include "sound.h"
#include "task.h"
#include "title_screen.h"
#include "trig.h"
#include "util.h"
#include "constants/rgb.h"
#include "constants/songs.h"
#include "constants/sound.h"

/*
    The intro is grouped into the following scenes
    - Copyright screen
    - GF Logo
    Scene 1. Brief close up shot of grass
    Scene 2. A panning wide shot followed by a close-up of Gengar/Nidorino
    Scene 3. A fight between Gengar/Nidorino

    After this it progresses to the title screen
*/

enum {
    GFXTAG_STAR,
    GFXTAG_SPARKLES_SMALL,
    GFXTAG_SPARKLES_BIG,
    GFXTAG_GF_LOGO,
    GFXTAG_PRESENTS,
    GFXTAG_SCENE3_NIDORINO,
    GFXTAG_SCENE2_GENGAR,
    GFXTAG_SCENE2_NIDORINO,
    GFXTAG_SCENE3_GRASS,
    GFXTAG_SCENE3_GENGAR,
    GFXTAG_SCENE3_SWIPE,
    GFXTAG_SCENE3_RECOIL_DUST,
};

enum {
    PALTAG_STAR,
    PALTAG_SPARKLES,
    PALTAG_UNUSED_2,
    PALTAG_GF,
    PALTAG_UNUSED_4,
    PALTAG_UNUSED_5,
    PALTAG_GENGAR,
    PALTAG_NIDORINO,
    PALTAG_SCENE3_GRASS,
    PALTAG_UNUSED_9,
    PALTAG_SCENE3_SWIPE,
    PALTAG_SCENE3_RECOIL_DUST,
};

// Background IDs for Game Freak logo scene
enum {
    BG_GF_TEXT_LOGO = 2,
    BG_GF_BACKGROUND
};


// Background IDs for Scene 1
enum {
    BG_SCENE1_GRASS,
    BG_SCENE1_BACKGROUND,
    BG_SCENE1_UNUSED1,
    BG_SCENE1_UNUSED2
};

#define PALSLOT_SCENE1_GRASS 1
#define PALSLOT_SCENE1_BG    2

// Background IDs for Scene 2
enum {
    BG_SCENE2_PLANTS,
    BG_SCENE2_NIDORINO,
    BG_SCENE2_GENGAR,
    BG_SCENE2_BACKGROUND // Bg for wide shot on upper half, close up on lower half
};

// Background IDs for Scene 3
enum {
    BG_SCENE3_GENGAR,
    BG_SCENE3_BACKGROUND,
    BG_SCENE3_UNUSED1,
    BG_SCENE3_UNUSED2
};

enum {
    ANIM_NIDORINO_NORMAL,
    ANIM_NIDORINO_CRY,
    ANIM_NIDORINO_CROUCH,
    ANIM_NIDORINO_HOP,
    ANIM_NIDORINO_ATTACK,
};

enum {
    ANIM_SPARKLE_LOOP,
    ANIM_SPARKLE_ONCE,
};

enum {
    ANIM_SWIPE_TOP,
    ANIM_SWIPE_BOTTOM,
};

enum {
    AFFINEANIM_NORMAL,
    AFFINEANIM_ZOOM,
};

// Window ids for sWindowTemplates (only one)
enum {
    WIN_GF_TEXT_LOGO,
    WIN_COUNT
};

#define NUM_GENGAR_BACK_SPRITES 4

#define COLOSSEUM_GAME_CODE 0x65366347 // "Gc6e" in ASCII

struct IntroSequenceData;

typedef void (*IntroCallback)(struct IntroSequenceData *);

struct IntroSequenceData
{
    IntroCallback callback;
    u8 state;
    u8 taskId;
    bool8 gengarAttackLanded;
    u16 data[5]; // [0] and [1] are set but never read, the rest are unused
    u16 timer;
    struct Sprite *gameFreakLogoArtSprite;
    struct Sprite *scene3NidorinoSprite;
    struct Sprite *scene2GengarSprite;
    struct Sprite *scene2NidorinoSprite;
    struct Sprite *scene3GrassSprite;
    struct Sprite *scene3GengarSprites[NUM_GENGAR_BACK_SPRITES];
    u8 unused0[4];
    u8 gameFreakLogoGfx[0x400];
    u8 gameFreakTextGfx[0x400];
    u8 unused1[0x2080];
}; // size: 0x28BC

static EWRAM_DATA struct GcmbStruct sGcmb = {0};
static EWRAM_DATA u16 sNidorinoJumpMult = 0;
static EWRAM_DATA u16 sNidorinoAnimDelayTime = 0;
static EWRAM_DATA u16 sNidorinoJumpDiv = 0;
static EWRAM_DATA u16 sNidorinoRecoilReturnTime = 0;
static EWRAM_DATA u16 sStarSpeedX = 0;
static EWRAM_DATA u16 sStarSpeedY = 0;
static EWRAM_DATA u16 sStarSparklesXmodMask = 0;
static EWRAM_DATA u16 sStarSparklesSpawnRate = 0;
static EWRAM_DATA u16 sStarSparklesFlickerStartTime = 0;
static EWRAM_DATA u16 sStarSparklesDestroySpriteTime = 0;
static EWRAM_DATA u16 sStarSparklesGravityShift = 0;
static EWRAM_DATA u16 sStarSparklesXspeed = 0;
static EWRAM_DATA u16 sStarSparklesYspeed = 0;
static EWRAM_DATA u16 sStarSparklesXprecision = 0;
static EWRAM_DATA u16 sStarSparklesYprecision = 0;

// General
static void CB2_Intro(void);
static void VBlankCB_Intro(void);
static void Intro_ResetGpuRegs(void);
static void StartIntroSequence(void);
static void Task_CallIntroCallback(u8 taskId);
static void SetIntroCB(struct IntroSequenceData * ptr, IntroCallback cb);
static void IntroCB_Init(struct IntroSequenceData * ptr);
static void LoadFightSceneSpriteGraphics(void);
static void IntroCB_ExitToTitleScreen(struct IntroSequenceData * ptr);

// GF scene
static void IntroCB_GF_OpenWindow(struct IntroSequenceData * ptr);
static void IntroCB_GF_Star(struct IntroSequenceData * ptr);
static void IntroCB_GF_RevealName(struct IntroSequenceData * ptr);
static void IntroCB_GF_RevealLogo(struct IntroSequenceData * ptr);
static void GFScene_LoadGfxCreateStar(void);
static void GFScene_StartNameSparklesSmall(void);
static void GFScene_StartNameSparklesBig(void);
static void GFScene_Task_NameSparklesSmall(u8 taskId);
static void GFScene_Task_NameSparklesBig(u8 taskId);
static struct Sprite *GFScene_CreateLogoSprite(void);
static void GFScene_CreatePresentsSprite(void);
static void SpriteCB_Star(struct Sprite *sprite);
static void SpriteCB_SparklesSmall_Star(struct Sprite *sprite);
static void SpriteCB_SparklesSmall_Name(struct Sprite *sprite);
static void SpriteCB_SparklesBig(struct Sprite *sprite);

// Scene 1
static void IntroCB_Scene1(struct IntroSequenceData * ptr);
static void Scene1_Task_AnimateGrass(u8 taskId);
static void Scene1_StartGrassScrolling(void);
static void Scene1_Task_BgZoom(u8 taskId);

// Scene 2
static void IntroCB_Scene2(struct IntroSequenceData * ptr);
static void Scene2_Task_PanForest(u8 taskId);
static void Scene2_Task_PanMons(u8 taskId);
static void Scene2_CreateMonSprites(struct IntroSequenceData * ptr);
static void Scene2_DestroyMonSprites(struct IntroSequenceData * ptr);

// Scene 3
static void IntroCB_Scene3_Entrance(struct IntroSequenceData * ptr);
static void IntroCB_Scene3_Fight(struct IntroSequenceData * ptr);
static void Scene3_StartBgScroll(void);
static void Scene3_Task_GengarBounce(u8 taskId);
static void Scene3_CreateGrassSprite(struct IntroSequenceData * ptr);
static void Scene3_CreateGengarSprite(struct IntroSequenceData * ptr);
static void Scene3_StartNidorinoCry(struct IntroSequenceData * ptr);
static void Scene3_StartNidorinoHop(struct Sprite *sprite, u16 time, s16 targetX, u8 heightShift);
static void Scene3_StartGengarAttack(struct IntroSequenceData * ptr);
static void Scene3_Task_GengarAttack(u8 taskId);
static void Scene3_NidorinoZoom(struct IntroSequenceData * ptr);
static void Scene3_GengarZoom(struct IntroSequenceData * ptr);
static void Scene3_CreateGengarSwipeSprites(void);
static void Scene3_Task_GengarEnter(u8 taskId);
static void Scene3_CreateNidorinoSprite(struct IntroSequenceData * ptr);
static void Scene3_StartNidorinoEntrance(struct Sprite *sprite, s16 xStart, s16 xEnd, u16 speed);
static void Scene3_SpriteCB_NidorinoEnter(struct Sprite *sprite);
static bool32 Scene3_IsNidorinoEntering(struct IntroSequenceData * ptr);
static void Scene3_StartNidorinoRecoil(struct IntroSequenceData * ptr);
static bool8 Scene3_NidorinoAnimIsRunning(struct IntroSequenceData * ptr);
static void CreateNidorinoRecoilDustSprites(s16 x, s16 y, s16 seed);
static void Scene3_StartNidorinoAttack(struct IntroSequenceData * ptr);
static void SpriteCB_Grass(struct Sprite *sprite);
static void SpriteCB_GengarSwipe(struct Sprite *sprite);
static void SpriteCB_RecoilDust(struct Sprite *sprite);
static void SpriteCB_NidorinoCry(struct Sprite *sprite);
static void SpriteCB_NidorinoRecoil(struct Sprite *sprite);
static void SpriteCB_NidorinoHop(struct Sprite *sprite);
static void SpriteCB_NidorinoAttack(struct Sprite *sprite);

extern const u32 gMultiBootProgram_PokemonColosseum_Start[];
extern const u32 gMultiBootProgram_PokemonColosseum_End[];

static const u16 sCopyright_Pal[] = INCGFX_U16("graphics/intro_frlg/copyright.pal", ".gbapal");
static const u32 sCopyright_Gfx[]  = INCGFX_U32("graphics/intro_frlg/copyright.png", ".4bpp.smol");
static const u32 sCopyright_Map[]  = INCBIN_U32( "graphics/intro_frlg/copyright.bin.smolTM");

// Game Freak
static const u16 sGameFreakBg_Pal[]   = INCGFX_U16("graphics/intro_frlg/game_freak/bg.pal", ".gbapal");
static const u8 sGameFreakBg_Gfx[]    = INCGFX_U8("graphics/intro_frlg/game_freak/bg.png", ".4bpp.smol");
static const u8 sGameFreakBg_Map[]    = INCBIN_U8( "graphics/intro_frlg/game_freak/bg.bin.smolTM");
static const u16 sGameFreakLogo_Pal[] = INCGFX_U16("graphics/intro_frlg/game_freak/logo.png", ".gbapal");
static const u32 sGameFreakText_Gfx[] = INCGFX_U32("graphics/intro_frlg/game_freak/game_freak.png", ".4bpp.smol");
static const u32 sGameFreakLogo_Gfx[] = INCGFX_U32("graphics/intro_frlg/game_freak/logo.png", ".4bpp.smol");
static const u16 sStar_Pal[]          = INCGFX_U16("graphics/intro_frlg/game_freak/star.png", ".gbapal");
static const u32 sStar_Gfx[]          = INCGFX_U32("graphics/intro_frlg/game_freak/star.png", ".4bpp.smol");
static const u16 sSparkles_Pal[]      = INCGFX_U16("graphics/intro_frlg/game_freak/sparkles.pal", ".gbapal");
static const u32 sSparklesSmall_Gfx[] = INCGFX_U32("graphics/intro_frlg/game_freak/sparkles_small.png", ".4bpp.smol");
static const u32 sSparklesBig_Gfx[]   = INCGFX_U32("graphics/intro_frlg/game_freak/sparkles_big.png", ".4bpp.smol");
static const u32 sPresents_Gfx[]      = INCGFX_U32("graphics/intro_frlg/game_freak/presents.png", ".4bpp.smol");

// Scene 1 (Grass close up)
static const u16 sScene1_Grass_Pal[] = INCGFX_U16("graphics/intro_frlg/scene_1/grass.png", ".gbapal");
static const u8 sScene1_Grass_Gfx[]  = INCGFX_U8("graphics/intro_frlg/scene_1/grass.png", ".4bpp.smol");
static const u8 sScene1_Grass_Map[]  = INCBIN_U8( "graphics/intro_frlg/scene_1/grass.bin.smolTM");
static const u16 sScene1_Bg_Pal[]    = INCGFX_U16("graphics/intro_frlg/scene_1/bg.png", ".gbapal");
static const u8 sScene1_Bg_Gfx[]     = INCGFX_U8("graphics/intro_frlg/scene_1/bg.png", ".4bpp.smol");
static const u8 sScene1_Bg_Map[]     = INCBIN_U8( "graphics/intro_frlg/scene_1/bg.bin.smolTM");

// Scenes 2 and 3 (Gengar and Nidorino)
static const u16 sScene2_Bg_Pal[]            = INCGFX_U16("graphics/intro_frlg/scene_2/bg.pal", ".gbapal");
static const u8 sScene2_Bg_Gfx[]             = INCGFX_U8("graphics/intro_frlg/scene_2/bg.png", ".4bpp.smol");
static const u8 sScene2_Bg_Map[]             = INCBIN_U8( "graphics/intro_frlg/scene_2/bg.bin.smolTM");
static const u16 sScene2_Plants_Pal[]        = INCGFX_U16("graphics/intro_frlg/scene_2/plants.png", ".gbapal"); // Unused
static const u8 sScene2_Plants_Gfx[]         = INCGFX_U8("graphics/intro_frlg/scene_2/plants.png", ".4bpp.smol");
static const u8 sScene2_Plants_Map[]         = INCBIN_U8( "graphics/intro_frlg/scene_2/plants.bin.smolTM");
static const u16 sGengar_Pal[]               = INCGFX_U16("graphics/intro_frlg/gengar.pal", ".gbapal"); // Used by multiple scenes
static const u8 sScene2_GengarClose_Gfx[]    = INCGFX_U8("graphics/intro_frlg/scene_2/gengar_close.png", ".4bpp.smol");
static const u8 sScene2_GengarClose_Map[]    = INCBIN_U8( "graphics/intro_frlg/scene_2/gengar_close.bin.smolTM");
static const u16 sScene2_NidorinoClose_Pal[] = INCGFX_U16("graphics/intro_frlg/scene_2/nidorino_close.pal", ".gbapal");
static const u8 sScene2_NidorinoClose_Gfx[]  = INCGFX_U8("graphics/intro_frlg/scene_2/nidorino_close.png", ".4bpp.smol");
static const u8 sScene2_NidorinoClose_Map[]  = INCBIN_U8( "graphics/intro_frlg/scene_2/nidorino_close.bin.smolTM");
static const u16 sScene3_Bg_Pal[]            = INCGFX_U16("graphics/intro_frlg/scene_3/bg.pal", ".gbapal");
static const u8 sScene3_Bg_Gfx[]             = INCGFX_U8("graphics/intro_frlg/scene_3/bg.png", ".4bpp.smol");
static const u8 sScene3_Bg_Map[]             = INCBIN_U8( "graphics/intro_frlg/scene_3/bg.bin.smolTM");
static const u8 sScene3_GengarAnim_Gfx[]     = INCGFX_U8("graphics/intro_frlg/scene_3/gengar_anim.png", ".4bpp.smol");
static const u8 sScene3_GengarAnim_Map[]     = INCBIN_U8( "graphics/intro_frlg/scene_3/gengar_anim.bin.smolTM");
static const u32 sScene2_Gengar_Gfx[]        = INCGFX_U32("graphics/intro_frlg/scene_2/gengar.png", ".4bpp.smol");
static const u16 sNidorino_Pal[]             = INCGFX_U16("graphics/intro_frlg/nidorino.pal", ".gbapal"); // Used by multiple scenes
static const u32 sScene2_Nidorino_Gfx[]      = INCGFX_U32("graphics/intro_frlg/scene_2/nidorino.png", ".4bpp.smol");
static const u16 sScene3_Grass_Pal[]         = INCGFX_U16("graphics/intro_frlg/scene_3/grass.png", ".gbapal");
static const u32 sScene3_Grass_Gfx[]         = INCGFX_U32("graphics/intro_frlg/scene_3/grass.png", ".4bpp.smol");
static const u32 sScene3_GengarStatic_Gfx[]  = INCGFX_U32("graphics/intro_frlg/scene_3/gengar_static.png", ".4bpp.smol");
static const u32 sScene3_Nidorino_Gfx[]      = INCGFX_U32("graphics/intro_frlg/scene_3/nidorino.png", ".4bpp.smol");
static const u16 sScene3_Swipe_Pal[]         = INCGFX_U16("graphics/intro_frlg/scene_3/swipe.png", ".gbapal");
static const u16 sScene3_RecoilDust_Pal[]    = INCGFX_U16("graphics/intro_frlg/scene_3/recoil_dust.png", ".gbapal");
static const u32 sScene3_Swipe_Gfx[]         = INCGFX_U32("graphics/intro_frlg/scene_3/swipe.png", ".4bpp.smol");
static const u32 sScene3_RecoilDust_Gfx[]    = INCGFX_U32("graphics/intro_frlg/scene_3/recoil_dust.png", ".4bpp.smol");

static const struct BgTemplate sBgTemplates_GameFreakScene[] = {
    {
        .bg = BG_GF_BACKGROUND,
        .charBaseIndex = 3,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 3,
        .baseTile = 0x000
    }, {
        .bg = BG_GF_TEXT_LOGO,
        .charBaseIndex = 3,
        .mapBaseIndex = 30,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 0x010
    }
};

static const struct BgTemplate sBgTemplates_Scene1[] = {
    {
        .bg = BG_SCENE1_GRASS,
        .charBaseIndex = 0,
        .mapBaseIndex = 28,
        .screenSize = 2,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0x000
    }, {
        .bg = BG_SCENE1_BACKGROUND,
        .charBaseIndex = 1,
        .mapBaseIndex = 30,
        .screenSize = 2,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0x000
    }
};

static const struct BgTemplate sBgTemplates_Scene2[] = {
    {
        .bg = BG_SCENE2_BACKGROUND,
        .charBaseIndex = 1,
        .mapBaseIndex = 30,
        .screenSize = 2,
        .paletteMode = 0,
        .priority = 3,
        .baseTile = 0x000
    }, {
        .bg = BG_SCENE2_PLANTS,
        .charBaseIndex = 0,
        .mapBaseIndex = 29,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0x000
    }, {
        .bg = BG_SCENE2_GENGAR,
        .charBaseIndex = 3,
        .mapBaseIndex = 27,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 0x000
    }, {
        .bg = BG_SCENE2_NIDORINO,
        .charBaseIndex = 2,
        .mapBaseIndex = 28,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0x000
    }
};

static const struct BgTemplate sBgTemplates_Scene3[] = {
    {
        .bg = BG_SCENE3_BACKGROUND,
        .charBaseIndex = 0,
        .mapBaseIndex = 29,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0x000
    }, {
        .bg = BG_SCENE3_GENGAR,
        .charBaseIndex = 1,
        .mapBaseIndex = 30,
        .screenSize = 2,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0x000
    }
};

static const struct WindowTemplate sWindowTemplates[WIN_COUNT + 1] = {
    [WIN_GF_TEXT_LOGO] = {
        .bg = BG_GF_TEXT_LOGO,
        .tilemapLeft = 6,
        .tilemapTop = 4,
        .width = 18,
        .height = 9,
        .paletteNum = 13,
        .baseBlock = 0x000
    },
    [WIN_COUNT] = DUMMY_WIN_TEMPLATE
};

static const u8 sGengarZoomMatrixAnchors[NUM_GENGAR_BACK_SPRITES][2] = {
    {63, 63},
    { 0, 63},
    {63,  0},
    { 0,  0}
};

static const struct CompressedSpriteSheet sSpriteSheets_GameFreakScene[] = {
    {sStar_Gfx,          0x80,  GFXTAG_STAR},
    {sSparklesSmall_Gfx, 0x80,  GFXTAG_SPARKLES_SMALL},
    {sSparklesBig_Gfx,   0x800, GFXTAG_SPARKLES_BIG},
    {sGameFreakLogo_Gfx, 0x400, GFXTAG_GF_LOGO},
    {sPresents_Gfx,      0x100, GFXTAG_PRESENTS}
};

static const struct SpritePalette sSpritePalettes_GameFreakScene[] = {
    {sStar_Pal,          PALTAG_STAR},
    {sSparkles_Pal,      PALTAG_SPARKLES},
    {sGameFreakLogo_Pal, PALTAG_GF},
    {0}
};

static const struct Coords16 sTextSparkleCoords[] = {
    { 72,  80},
    {136,  74},
    {168,  80},
    {120,  80},
    {104,  86},
    { 88,  74},
    {184,  74},
    { 56,  86},
    {152,  86}
};

static const struct OamData sOam_Star = {
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(16x16),
    .matrixNum = 0,
    .size = SPRITE_SIZE(16x16),
    .tileNum = 0x000,
    .priority = 2,
    .paletteNum = 0
};

static const struct OamData sOam_SparklesSmall = {
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(8x8),
    .matrixNum = 0,
    .size = SPRITE_SIZE(8x8),
    .tileNum = 0x000,
    .priority = 2,
    .paletteNum = 0
};

static const union AnimCmd sAnim_SparklesSmall_Loop[] = {
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(1, 4),
    ANIMCMD_FRAME(2, 4),
    ANIMCMD_FRAME(3, 4),
    ANIMCMD_JUMP(0)
};

static const union AnimCmd sAnim_SparklesSmall_Once[] = {
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(1, 4),
    ANIMCMD_FRAME(2, 4),
    ANIMCMD_FRAME(3, 4),
    ANIMCMD_END
};

static const union AnimCmd *const sAnims_SparklesSmall[] = {
    [ANIM_SPARKLE_LOOP] = sAnim_SparklesSmall_Loop,
    [ANIM_SPARKLE_ONCE] = sAnim_SparklesSmall_Once
};

static const struct SpriteTemplate sSpriteTemplate_Star = {
    .tileTag = GFXTAG_STAR,
    .paletteTag = PALTAG_STAR,
    .oam = &sOam_Star,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_Star
};

static const struct SpriteTemplate sSpriteTemplate_SparklesSmall = {
    .tileTag = GFXTAG_SPARKLES_SMALL,
    .paletteTag = PALTAG_SPARKLES,
    .oam = &sOam_SparklesSmall,
    .anims = sAnims_SparklesSmall,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_SparklesSmall_Star
};

static const struct OamData sOam_SparklesBig = {
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x32),
    .matrixNum = 0,
    .size = SPRITE_SIZE(32x32),
    .tileNum = 0x000,
    .priority = 2,
    .paletteNum = 0
};

static const union AnimCmd sAnim_SparklesBig[] = {
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(16, 8),
    ANIMCMD_FRAME(32, 8),
    ANIMCMD_FRAME(48, 8),
    ANIMCMD_END
};

static const union AnimCmd *const sAnims_SparklesBig[] = {
    sAnim_SparklesBig
};

static const struct SpriteTemplate sSpriteTemplate_SparklesBig = {
    .tileTag = GFXTAG_SPARKLES_BIG,
    .paletteTag = PALTAG_SPARKLES,
    .oam = &sOam_SparklesBig,
    .anims = sAnims_SparklesBig,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_SparklesBig
};

static const struct OamData sOam_GameFreakLogo = {
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_BLEND,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x64),
    .matrixNum = 0,
    .size = SPRITE_SIZE(32x64),
    .tileNum = 0x000,
    .priority = 3,
    .paletteNum = 0
};

static const struct SpriteTemplate sSpriteTemplate_GameFreakLogoArt = {
    .tileTag = GFXTAG_GF_LOGO,
    .paletteTag = PALTAG_GF,
    .oam = &sOam_GameFreakLogo,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct OamData sOam_PresentsText = {
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_BLEND,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x8),
    .matrixNum = 0,
    .size = SPRITE_SIZE(32x8),
    .tileNum = 0x000,
    .priority = 3,
    .paletteNum = 0
};

static const struct SpriteTemplate sSpriteTemplate_Presents = {
    .tileTag = GFXTAG_PRESENTS,
    .paletteTag = PALTAG_GF,
    .oam = &sOam_PresentsText,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct OamData sOam_Scene3_Nidorino = {
    .affineMode = ST_OAM_AFFINE_DOUBLE,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(64x64),
    .matrixNum = 0,
    .size = SPRITE_SIZE(64x64),
    .tileNum = 0x000,
    .priority = 1,
    .paletteNum = 0
};

static const union AnimCmd sAnim_Scene3_Nidorino_Normal[] = {
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Scene3_Nidorino_Cry[] = {
    ANIMCMD_FRAME(64, 1),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Scene3_Nidorino_Crouch[] = {
    ANIMCMD_FRAME(128, 1),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Scene3_Nidorino_Hop[] = {
    ANIMCMD_FRAME(192, 1),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Scene3_Nidorino_Attack[] = {
    ANIMCMD_FRAME(256, 1),
    ANIMCMD_END
};

static const union AnimCmd *const sAnims_Scene3_Nidorino[] = {
    [ANIM_NIDORINO_NORMAL] = sAnim_Scene3_Nidorino_Normal,
    [ANIM_NIDORINO_CRY]    = sAnim_Scene3_Nidorino_Cry,
    [ANIM_NIDORINO_CROUCH] = sAnim_Scene3_Nidorino_Crouch,
    [ANIM_NIDORINO_HOP]    = sAnim_Scene3_Nidorino_Hop,
    [ANIM_NIDORINO_ATTACK] = sAnim_Scene3_Nidorino_Attack
};

static const union AffineAnimCmd sAffineAnim_Scene3_Mons_Normal[] = {
    AFFINEANIMCMD_FRAME(256, 256, 0, 0),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd sAffineAnim_Scene3_Mons_Zoom[] = {
    AFFINEANIMCMD_FRAME(256, 256, 0, 0),
    AFFINEANIMCMD_FRAME(32, 32, 0, 8),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd *const sAffineAnims_Scene3_Mons[] = {
    [AFFINEANIM_NORMAL] = sAffineAnim_Scene3_Mons_Normal,
    [AFFINEANIM_ZOOM]   = sAffineAnim_Scene3_Mons_Zoom
};

static const struct SpriteTemplate sSpriteTemplate_Scene3_Nidorino = {
    .tileTag = GFXTAG_SCENE3_NIDORINO,
    .paletteTag = PALTAG_NIDORINO,
    .oam = &sOam_Scene3_Nidorino,
    .anims = sAnims_Scene3_Nidorino,
    .images = NULL,
    .affineAnims = sAffineAnims_Scene3_Mons,
    .callback = SpriteCallbackDummy
};

static const struct OamData sOam_Scene2_Mons = {
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(64x64),
    .matrixNum = 0,
    .size = SPRITE_SIZE(64x64),
    .tileNum = 0x000,
    .priority = 1,
    .paletteNum = 0
};

static const struct SpriteTemplate sSpriteTemplate_Scene2_Nidorino = {
    .tileTag = GFXTAG_SCENE2_NIDORINO,
    .paletteTag = PALTAG_NIDORINO,
    .oam = &sOam_Scene2_Mons,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate sSpriteTemplate_Scene2_Gengar = {
    .tileTag = GFXTAG_SCENE2_GENGAR,
    .paletteTag = PALTAG_GENGAR,
    .oam = &sOam_Scene2_Mons,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct OamData sOam_Grass = {
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(64x32),
    .matrixNum = 0,
    .size = SPRITE_SIZE(64x32),
    .tileNum = 0x000,
    .priority = 0,
    .paletteNum = 0
};

static const union AnimCmd sAnim_Grass_Static[] = {
    ANIMCMD_FRAME(0, 0),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Grass_Rustle[] = {
    ANIMCMD_FRAME(32, 4),
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_END
};

static const union AnimCmd *const sAnims_Grass[] = {
    sAnim_Grass_Static,
    sAnim_Grass_Rustle // Unused
};

static const struct SpriteTemplate sSpriteTemplate_Grass = {
    .tileTag = GFXTAG_SCENE3_GRASS,
    .paletteTag = PALTAG_SCENE3_GRASS,
    .oam = &sOam_Grass,
    .anims = sAnims_Grass,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct OamData sOam_Scene3_Gengar = {
    .affineMode = ST_OAM_AFFINE_DOUBLE,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(64x64),
    .matrixNum = 0,
    .size = SPRITE_SIZE(64x64),
    .tileNum = 0x000,
    .priority = 1,
    .paletteNum = 0
};

static const union AnimCmd sAnim_Scene3_Gengar_TopLeft[] = {
    ANIMCMD_FRAME(0, 0),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Scene3_Gengar_TopRight[] = {
    ANIMCMD_FRAME(64, 0),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Scene3_Gengar_BottomLeft[] = {
    ANIMCMD_FRAME(96, 0),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Scene3_Gengar_BottomRight[] = {
    ANIMCMD_FRAME(160, 0),
    ANIMCMD_END
};

static const union AnimCmd *const sAnims_Scene3_Gengar[NUM_GENGAR_BACK_SPRITES] = {
    sAnim_Scene3_Gengar_TopLeft,
    sAnim_Scene3_Gengar_TopRight,
    sAnim_Scene3_Gengar_BottomLeft,
    sAnim_Scene3_Gengar_BottomRight
};

static const struct SpriteTemplate sSpriteTemplate_Scene3_Gengar = {
    .tileTag = GFXTAG_SCENE3_GENGAR,
    .paletteTag = PALTAG_GENGAR,
    .oam = &sOam_Scene3_Gengar,
    .anims = sAnims_Scene3_Gengar,
    .images = NULL,
    .affineAnims = sAffineAnims_Scene3_Mons,
    .callback = SpriteCallbackDummy
};

static const struct OamData sOam_Swipe = {
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x64),
    .matrixNum = 0,
    .size = SPRITE_SIZE(32x64),
    .tileNum = 0x000,
    .priority = 1,
    .paletteNum = 0
};

static const union AnimCmd sAnim_Swipe_Top[] = {
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(32, 4),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Swipe_Bottom[] = {
    ANIMCMD_FRAME(64, 8),
    ANIMCMD_FRAME(72, 4),
    ANIMCMD_END
};

static const union AnimCmd *const sAnims_Swipe[] = {
    [ANIM_SWIPE_TOP]    = sAnim_Swipe_Top,
    [ANIM_SWIPE_BOTTOM] = sAnim_Swipe_Bottom
};

static const struct SpriteTemplate sSpriteTemplate_GengarSwipe = {
    .tileTag = GFXTAG_SCENE3_SWIPE,
    .paletteTag = PALTAG_SCENE3_SWIPE,
    .oam = &sOam_Swipe,
    .anims = sAnims_Swipe,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_GengarSwipe
};

static const struct OamData sOam_RecoilDust = {
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(16x16),
    .matrixNum = 0,
    .size = SPRITE_SIZE(16x16),
    .tileNum = 0x000,
    .priority = 1,
    .paletteNum = 0
};

static const union AnimCmd sAnim_RecoilDust[] = {
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(4, 10),
    ANIMCMD_FRAME(8, 10),
    ANIMCMD_FRAME(12, 8),
    ANIMCMD_END
};

static const union AnimCmd *const sAnims_RecoilDust[] = {
    sAnim_RecoilDust
};

static const struct SpriteTemplate sSpriteTemplate_NidorinoRecoilDust = {
    .tileTag = GFXTAG_SCENE3_RECOIL_DUST,
    .paletteTag = PALTAG_SCENE3_RECOIL_DUST,
    .oam = &sOam_RecoilDust,
    .anims = sAnims_RecoilDust,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_RecoilDust
};

static const struct CompressedSpriteSheet sFightSceneSpriteSheets[] = {
    {sScene2_Gengar_Gfx,       0x800,  GFXTAG_SCENE2_GENGAR},
    {sScene2_Nidorino_Gfx,     0x800,  GFXTAG_SCENE2_NIDORINO},
    {sScene3_Nidorino_Gfx,     0x2800, GFXTAG_SCENE3_NIDORINO},
    {sScene3_Grass_Gfx,        0x800,  GFXTAG_SCENE3_GRASS},
    {sScene3_GengarStatic_Gfx, 0x1800, GFXTAG_SCENE3_GENGAR},
    {sScene3_Swipe_Gfx,        0xA00,  GFXTAG_SCENE3_SWIPE},
    {sScene3_RecoilDust_Gfx,   0x200,  GFXTAG_SCENE3_RECOIL_DUST}
};

// POTENTIAL UB
// This array is passed to LoadSpritePalettes in LoadFightSceneSpriteGraphics.
// LoadSpritePalettes uses a {0} entry to signal end of array.
// Because such an entry is absent in this case, the function
// continues reading into the next .rodata section.
static const struct SpritePalette sFightSceneSpritePalettes[] = {
    {sGengar_Pal,            PALTAG_GENGAR},
    {sNidorino_Pal,          PALTAG_NIDORINO},
    {sScene3_Grass_Pal,      PALTAG_SCENE3_GRASS},
    {sScene3_Swipe_Pal,      PALTAG_SCENE3_SWIPE},
    {sScene3_RecoilDust_Pal, PALTAG_SCENE3_RECOIL_DUST},
#ifdef BUGFIX
    {0}
#endif
};

static void VBlankCB_Copyright(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static void CB2_WaitFadeBeforeSetUpIntro(void)
{
    if (!UpdatePaletteFade())
    {
#if EXPANSION_INTRO == TRUE
        SetMainCallback2(CB2_ExpansionIntro);
        CreateTask(Task_HandleExpansionIntro, 0);
#else
        SetMainCallback2(CB2_SetUpIntroFrlg);
#endif
    }
}

static void LoadCopyrightGraphics(u16 charBase, u16 screenBase, u16 palOffset)
{
    DecompressDataWithHeaderVram(sCopyright_Gfx, (void *)BG_VRAM + charBase);
    DecompressDataWithHeaderVram(sCopyright_Map, (void *)BG_VRAM + screenBase);
    LoadPalette(sCopyright_Pal, palOffset, sizeof(sCopyright_Pal));
}

static void SerialCB_CopyrightScreen(void)
{
    GameCubeMultiBoot_HandleSerialInterrupt(&sGcmb);
}

bool8 SetUpCopyrightScreenFrlg(void)
{
    switch (gMain.state)
    {
    case 0:
        SetVBlankCallback(NULL);
        SetGpuReg(REG_OFFSET_BLDCNT, 0);
        SetGpuReg(REG_OFFSET_BLDALPHA, 0);
        SetGpuReg(REG_OFFSET_BLDY, 0);
        ((vu16*)PLTT)[0] = RGB_WHITE;
        SetGpuReg(REG_OFFSET_DISPCNT, 0);
        SetGpuReg(REG_OFFSET_BG0HOFS, 0);
        SetGpuReg(REG_OFFSET_BG0VOFS, 0);
        DmaFill16(3, 0, VRAM, VRAM_SIZE);
        DmaFill32(3, 0, OAM, OAM_SIZE);
        DmaFill16(3, 0, PLTT + sizeof(vu16), PLTT_SIZE - sizeof(vu16));
        ResetPaletteFade();
        LoadCopyrightGraphics(0 * BG_CHAR_SIZE, 7 * BG_SCREEN_SIZE, BG_PLTT_ID(0));
        ScanlineEffect_Stop();
        ResetTasks();
        ResetSpriteData();
        FreeAllSpritePalettes();
        BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_WHITEALPHA);
        SetGpuReg(REG_OFFSET_BG0CNT, BGCNT_PRIORITY(0) | BGCNT_CHARBASE(0) | BGCNT_16COLOR | BGCNT_SCREENBASE(7));
        EnableInterrupts(INTR_FLAG_VBLANK);
        SetVBlankCallback(VBlankCB_Copyright);
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_1D_MAP | DISPCNT_BG0_ON);
        SetSerialCallback(SerialCB_CopyrightScreen);
        GameCubeMultiBoot_Init(&sGcmb);
        // fallthrough
    default:
        UpdatePaletteFade();
        gMain.state++;
        GameCubeMultiBoot_Main(&sGcmb);
        break;
    case 140:
        GameCubeMultiBoot_Main(&sGcmb);
        if (sGcmb.gcmb_field_2 != 1)
        {
            BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
            gMain.state++;
        }
        break;
    case 141:
        if (!UpdatePaletteFade())
        {
            gMain.state++;
            if (sGcmb.gcmb_field_2 != 0)
            {
                if (sGcmb.gcmb_field_2 == 2)
                {
                    if (*(u32 *)(EWRAM_START + 0xAC) == COLOSSEUM_GAME_CODE)
                    {
                        CpuCopy16(gMultiBootProgram_PokemonColosseum_Start, (void *)EWRAM_START, 0x28000);
                        *(u32 *)(EWRAM_START + 0xAC) = COLOSSEUM_GAME_CODE;
                    }
                    GameCubeMultiBoot_ExecuteProgram(&sGcmb);
                }
            }
            else
            {
                GameCubeMultiBoot_Quit();
                SetSerialCallback(SerialCB);
            }
            return FALSE;
        }
        break;
    case 142:
        ResetSerial();
        SetMainCallback2(CB2_WaitFadeBeforeSetUpIntro);
        break;
    }
    return TRUE;
}

void CB2_SetUpIntroFrlg(void)
{
    switch (gMain.state)
    {
    default:
        gMain.state = 0;
        // fallthrough
    case 0:
        SetVBlankCallback(NULL);
        SetGpuReg(REG_OFFSET_DISPCNT, 0);
        InitHeap(gHeap, HEAP_SIZE);
        ResetTasks();
        ResetSpriteData();
        ResetPaletteFade();
        ResetTempTileDataBuffers();
        Intro_ResetGpuRegs();
        DmaFill16(3, 0, VRAM, VRAM_SIZE);
        DmaFill32(3, 0, OAM, OAM_SIZE);
        DmaFill16(3, 0, PLTT, PLTT_SIZE);
        FillPalette(RGB_BLACK, 0, PLTT_SIZE);
        ResetBgsAndClearDma3BusyFlags(FALSE);
        InitBgsFromTemplates(0, sBgTemplates_GameFreakScene, ARRAY_COUNT(sBgTemplates_GameFreakScene));
        break;
    case 1:
        LoadPalette(sGameFreakBg_Pal, BG_PLTT_ID(0), sizeof(sGameFreakBg_Pal));
        DecompressAndCopyTileDataToVram(BG_GF_BACKGROUND, sGameFreakBg_Gfx, 0, 0, 0);
        DecompressAndCopyTileDataToVram(BG_GF_BACKGROUND, sGameFreakBg_Map, 0, 0, 1);
        LoadPalette(sGameFreakLogo_Pal, BG_PLTT_ID(13), sizeof(sGameFreakLogo_Pal));
        break;
    case 2:
        if (!FreeTempTileDataBuffersIfPossible())
        {
            StartIntroSequence();
            BlendPalettes(PALETTES_ALL, 16, RGB_BLACK);
            SetMainCallback2(CB2_Intro);
            SetVBlankCallback(VBlankCB_Intro);
        }
        return;
    }
    gMain.state++;
}

static void CB2_Intro(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

static void VBlankCB_Intro(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static void Intro_ResetGpuRegs(void)
{
    SetGpuReg(REG_OFFSET_DISPCNT, 0);
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
    SetGpuReg(REG_OFFSET_BLDALPHA, 0);
    SetGpuReg(REG_OFFSET_BLDY, 0);
    SetGpuReg(REG_OFFSET_BG0HOFS, 0);
    SetGpuReg(REG_OFFSET_BG0VOFS, 0);
    SetGpuReg(REG_OFFSET_BG1HOFS, 0);
    SetGpuReg(REG_OFFSET_BG1VOFS, 0);
    SetGpuReg(REG_OFFSET_BG2HOFS, 0);
    SetGpuReg(REG_OFFSET_BG2VOFS, 0);
    SetGpuReg(REG_OFFSET_BG3HOFS, 0);
    SetGpuReg(REG_OFFSET_BG3VOFS, 0);
    SetGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_OBJ_1D_MAP | DISPCNT_OBJ_ON);
}

static void StartIntroSequence(void)
{
    struct IntroSequenceData * ptr = Alloc(sizeof(*ptr));
    SetIntroCB(ptr, IntroCB_Init);
    ptr->taskId = CreateTask(Task_CallIntroCallback, 3);
    SetWordTaskArg(ptr->taskId, 0, (uintptr_t)ptr);
}

static void SetIntroCB(struct IntroSequenceData * ptr, IntroCallback cb)
{
    ptr->callback = cb;
    ptr->state = 0;
}

static void Task_CallIntroCallback(u8 taskId)
{
    struct IntroSequenceData * ptr = (void *)GetWordTaskArg(taskId, 0);

    // End intro early if player presses A/Start/Select
    if (JOY_NEW(A_BUTTON | START_BUTTON | SELECT_BUTTON) && ptr->callback != IntroCB_ExitToTitleScreen)
        SetIntroCB(ptr, IntroCB_ExitToTitleScreen);

    ptr->callback(ptr);
}

static void IntroCB_Init(struct IntroSequenceData * this)
{
    switch (this->state)
    {
    case 0:
        InitWindows(sWindowTemplates);
        DecompressDataWithHeaderWram(sGameFreakText_Gfx, this->gameFreakTextGfx);
        DecompressDataWithHeaderWram(sGameFreakLogo_Gfx, this->gameFreakLogoGfx);
        FillBgTilemapBufferRect(BG_GF_TEXT_LOGO, 0x000, 0, 0, 32, 32, 17);
        FillWindowPixelBuffer(WIN_GF_TEXT_LOGO, PIXEL_FILL(0));
        BlitBitmapToWindow(WIN_GF_TEXT_LOGO, this->gameFreakTextGfx, 0, 40, 144, 16);
        PutWindowTilemap(WIN_GF_TEXT_LOGO);
        CopyWindowToVram(WIN_GF_TEXT_LOGO, COPYWIN_FULL);
        this->state++;
        break;
    case 1:
        if (!IsDma3ManagerBusyWithBgCopy())
            SetIntroCB(this, IntroCB_GF_OpenWindow);
        break;
    }
}

static void IntroCB_GF_OpenWindow(struct IntroSequenceData * this)
{
    switch (this->state)
    {
    case 0:
        SetGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_WIN1_ON);
        SetGpuReg(REG_OFFSET_WININ, WININ_WIN1_ALL);
        SetGpuReg(REG_OFFSET_WINOUT, 0);
        SetGpuReg(REG_OFFSET_WIN1H, DISPLAY_WIDTH);
        SetGpuReg(REG_OFFSET_WIN1V, 0);
        this->timer = 0;
        this->state++;
        break;
    case 1:
        ShowBg(BG_GF_BACKGROUND);
        BlendPalettes(PALETTES_ALL, 0, RGB_BLACK);
        this->state++;
        break;
    case 2:
        // Extend window height in both directions from midpoint until it reaches a narrow "theatric" view
        this->timer += 8;
        if (this->timer >= 48)
            this->timer = 48;
        SetGpuReg(REG_OFFSET_WIN1V, WIN_RANGE(DISPLAY_HEIGHT / 2 - this->timer, DISPLAY_HEIGHT / 2 + this->timer));
        if (this->timer == 48)
            SetIntroCB(this, IntroCB_GF_Star);
        break;
    }
}

static void IntroCB_GF_Star(struct IntroSequenceData * this)
{
    switch (this->state)
    {
    case 0:
        PlaySE(MUS_RG_GAME_FREAK);
        GFScene_LoadGfxCreateStar();
        this->timer = 0;
        this->state++;
        break;
    case 1:
        if (++this->timer == 30)
        {
            GFScene_StartNameSparklesSmall();
            this->timer = 0;
            this->state++;
        }
        break;
    case 2:
        this->timer++;
        if (this->timer == 90)
            SetIntroCB(this, IntroCB_GF_RevealName);
        break;
    }
}

static void IntroCB_GF_RevealName(struct IntroSequenceData * this)
{
    switch (this->state)
    {
    case 0:
        GFScene_StartNameSparklesBig();
        this->timer = 0;
        this->state++;
        break;
    case 1:
        if (++this->timer >= 40)
            this->state++;
        break;
    case 2:
        SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG2 | BLDCNT_EFFECT_BLEND | BLDCNT_TGT2_ALL);
        StartBlendTask(0, 16, 16, 0, 48, 0);
        this->state++;
        break;
    case 3:
        ShowBg(BG_GF_TEXT_LOGO);
        this->state++;
        break;
    case 4:
        if (!IsBlendTaskActive())
        {
            SetGpuReg(REG_OFFSET_BLDCNT, 0);
            this->timer = 0;
            this->state++;
        }
        break;
    case 5:
        if (++this->timer > 50)
            SetIntroCB(this, IntroCB_GF_RevealLogo);
        break;
    }
}

static void IntroCB_GF_RevealLogo(struct IntroSequenceData * this)
{
    switch (this->state)
    {
    case 0:
        SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_OBJ | BLDCNT_EFFECT_BLEND | BLDCNT_TGT2_ALL);
        StartBlendTask(0, 16, 16, 0, 16, 0);
        this->data[0] = 0; // Never read
        this->data[1] = 16; // Never read
        this->timer = 0;
        this->state++;
        break;
    case 1:
        this->gameFreakLogoArtSprite = GFScene_CreateLogoSprite();
        this->state++;
        break;
    case 2:
        if (!IsBlendTaskActive())
        {
            BlitBitmapToWindow(WIN_GF_TEXT_LOGO, this->gameFreakLogoGfx, 0x38, 0x06, 0x20, 0x40);
            BlitBitmapToWindow(WIN_GF_TEXT_LOGO, this->gameFreakTextGfx, 0x00, 0x28, 0x90, 0x10);
            CopyWindowToVram(WIN_GF_TEXT_LOGO, COPYWIN_GFX);
            this->state++;
        }
        break;
    case 3:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            DestroySprite(this->gameFreakLogoArtSprite);
            GFScene_CreatePresentsSprite();
            this->timer = 0;
            this->state++;
        }
        break;
    case 4:
        if (++this->timer > 90)
        {
            SetGpuRegBits(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG2);
            StartBlendTask(16, 0, 0, 16, 20, 0);
            this->state++;
        }
        break;
    case 5:
        if (!IsBlendTaskActive())
        {
            HideBg(BG_GF_TEXT_LOGO);
            this->state++;
        }
        break;
    case 6:
        ResetSpriteData();
        FreeAllSpritePalettes();
        this->timer = 0;
        this->state++;
        break;
    case 7:
        if (++this->timer > 20)
        {
            SetGpuReg(REG_OFFSET_BLDCNT, 0);
            SetIntroCB(this, IntroCB_Scene1);
        }
        break;
    }
}

static void IntroCB_Scene1(struct IntroSequenceData * this)
{
    switch (this->state)
    {
    case 0:
        SetVBlankCallback(NULL);
        LoadPalette(sScene1_Grass_Pal, BG_PLTT_ID(PALSLOT_SCENE1_GRASS), sizeof(sScene1_Grass_Pal));
        LoadPalette(sScene1_Bg_Pal, BG_PLTT_ID(PALSLOT_SCENE1_BG), sizeof(sScene1_Bg_Pal));
        BlendPalettes((1 << PALSLOT_SCENE1_GRASS) | (1 << PALSLOT_SCENE1_BG), 16, RGB_WHITE);
        InitBgsFromTemplates(0, sBgTemplates_Scene1, ARRAY_COUNT(sBgTemplates_Scene1));
        DecompressAndCopyTileDataToVram(BG_SCENE1_BACKGROUND, sScene1_Bg_Gfx, 0, 0, 0);
        DecompressAndCopyTileDataToVram(BG_SCENE1_BACKGROUND, sScene1_Bg_Map, 0, 0, 1);
        ShowBg(BG_SCENE1_BACKGROUND);
        HideBg(BG_SCENE1_GRASS);
        HideBg(BG_SCENE1_UNUSED1);
        HideBg(BG_SCENE1_UNUSED2);
        LoadFightSceneSpriteGraphics();
        SetVBlankCallback(VBlankCB_Intro);
        this->state++;
        break;
    case 1:
        if (!FreeTempTileDataBuffersIfPossible())
        {
            DecompressAndCopyTileDataToVram(BG_SCENE1_GRASS, sScene1_Grass_Gfx, 0, 0, 0);
            DecompressAndCopyTileDataToVram(BG_SCENE1_GRASS, sScene1_Grass_Map, 0, 0, 1);
            ResetBgPositions();
            ShowBg(BG_SCENE1_BACKGROUND);
            this->state++;
        }
        break;
    case 2:
        if (!FreeTempTileDataBuffersIfPossible())
        {
            ShowBg(BG_SCENE1_GRASS);
            CreateTask(Scene1_Task_AnimateGrass, 0);
            BeginNormalPaletteFade((1 << PALSLOT_SCENE1_GRASS) | (1 << PALSLOT_SCENE1_BG), -2, 16, 0, RGB_WHITE);
            this->state++;
        }
        break;
    case 3:
        if (!gPaletteFade.active)
        {
            m4aSongNumStart(MUS_RG_INTRO_FIGHT);
            this->timer = 0;
            this->state++;
        }
        break;
    case 4:
        if (++this->timer == 20)
        {
            // Start animation for transitioning to the next scene
            CreateTask(Scene1_Task_BgZoom, 0);
            Scene1_StartGrassScrolling();
        }
        if (this->timer >= 30)
        {
            // End scene
            BlendPalettes(PALETTES_ALL & ~1, 16, RGB_WHITE);
            DestroyTask(FindTaskIdByFunc(Scene1_Task_AnimateGrass));
            DestroyTask(FindTaskIdByFunc(Scene1_Task_BgZoom));
            SetIntroCB(this, IntroCB_Scene2);
        }
        break;
    case 5:
        // Never reached
        if (!gPaletteFade.active)
        {
            DestroyTask(FindTaskIdByFunc(Scene1_Task_AnimateGrass));
            DestroyTask(FindTaskIdByFunc(Scene1_Task_BgZoom));
            SetIntroCB(this, IntroCB_Scene2);
        }
        break;
    }
}

#define tTimer   data[0]
#define tFrame   data[1]
#define tExiting data[2]
#define tScroll  data[3]

static void Scene1_Task_AnimateGrass(u8 taskId)
{
    s16 * data = gTasks[taskId].data;

    // Each of the 3 frames of the bg grass animation is separated vertically on the tilemap.
    // The conditional below changes the frame by setting the y coordinate of the bg.
    if (++tTimer > 5)
    {
        tTimer = 0;
        if (++tFrame >= 3)
            tFrame = 0;
        ChangeBgY(BG_SCENE1_GRASS, tFrame << 15, BG_COORD_SET);
    }

    // When it's time to progress to the next scene, the grass is meant to scroll downward offscreen.
    // This scrolling is overwritten by the coord change above, and so the grass "stutters" back upward.
    // They don't mask the bg, so if it were to continue scrolling offscreen it would reveal the frame above on the tilemap.
    if (tExiting)
    {
        tScroll += 0x120;
        ChangeBgY(BG_SCENE1_GRASS, tScroll, BG_COORD_SUB);
    }
}

static void Scene1_StartGrassScrolling(void)
{
    u8 taskId = FindTaskIdByFunc(Scene1_Task_AnimateGrass);
    gTasks[taskId].tExiting = TRUE;
}

#undef tTimer
#undef tFrame
#undef tExiting
#undef tScroll

#define tTimer data[0]
#define tFrame data[1]

// Have the silhouetted forest background "zoom in" during the transition to the next scene.
// Same as the grass animation above, this achieved by separating frames vertically on the bg tilemap.
static void Scene1_Task_BgZoom(u8 taskId)
{
    s16 * data = gTasks[taskId].data;

    if (++tTimer > 3)
    {
        tTimer = 0;
        if (tFrame < 2)
            tFrame++;
        ChangeBgY(BG_SCENE1_BACKGROUND, tFrame << 15, BG_COORD_SET);
    }
}

#undef tTimer
#undef tFrame

static void IntroCB_Scene2(struct IntroSequenceData * this)
{
    switch (this->state)
    {
    case 0:
        BlendPalettes(PALETTES_ALL & ~1, 16, RGB_WHITE);
        InitBgsFromTemplates(0, sBgTemplates_Scene2, ARRAY_COUNT(sBgTemplates_Scene2));
        DecompressAndCopyTileDataToVram(BG_SCENE2_BACKGROUND, sScene2_Bg_Gfx, 0, 0, 0);
        DecompressAndCopyTileDataToVram(BG_SCENE2_BACKGROUND, sScene2_Bg_Map, 0, 0, 1);
        ShowBg(BG_SCENE2_BACKGROUND);
        this->state++;
        break;
    case 1:
        if (!FreeTempTileDataBuffersIfPossible())
        {
            SetVBlankCallback(NULL);
            LoadPalette(sScene2_Bg_Pal, BG_PLTT_ID(1), sizeof(sScene2_Bg_Pal));
            LoadPalette(sGengar_Pal, BG_PLTT_ID(5), sizeof(sGengar_Pal));
            LoadPalette(sScene2_NidorinoClose_Pal, BG_PLTT_ID(6), sizeof(sScene2_NidorinoClose_Pal));
            BlendPalettes(PALETTES_ALL & ~1, 16, RGB_WHITE);
            DecompressAndCopyTileDataToVram(BG_SCENE2_PLANTS, sScene2_Plants_Gfx, 0, 0, 0);
            DecompressAndCopyTileDataToVram(BG_SCENE2_PLANTS, sScene2_Plants_Map, 0, 0, 1);
            DecompressAndCopyTileDataToVram(BG_SCENE2_NIDORINO, sScene2_NidorinoClose_Gfx, 0, 0, 0);
            DecompressAndCopyTileDataToVram(BG_SCENE2_NIDORINO, sScene2_NidorinoClose_Map, 0, 0, 1);
            DecompressAndCopyTileDataToVram(BG_SCENE2_GENGAR, sScene2_GengarClose_Gfx, 0, 0, 0);
            DecompressAndCopyTileDataToVram(BG_SCENE2_GENGAR, sScene2_GengarClose_Map, 0, 0, 1);
            ResetBgPositions();
            ShowBg(BG_SCENE2_PLANTS);
            HideBg(BG_SCENE2_NIDORINO); // Hide bgs for the close up shot
            HideBg(BG_SCENE2_GENGAR);
            ChangeBgY(BG_SCENE2_GENGAR, 0x0001CE00, BG_COORD_SET);
            ChangeBgY(BG_SCENE2_NIDORINO, 0x00002800, BG_COORD_SET);
            CreateTask(Scene2_Task_PanForest, 0);
            Scene2_CreateMonSprites(this);
            BlendPalettes(PALETTES_ALL & ~1, 16, RGB_WHITE);
            SetVBlankCallback(VBlankCB_Intro);
            this->state++;
        }
        break;
    case 2:
        if (!FreeTempTileDataBuffersIfPossible())
        {
            BeginNormalPaletteFade(PALETTES_ALL & ~1, -2, 16, 0, RGB_WHITE);
            this->state++;
        }
        break;
    case 3:
        if (!gPaletteFade.active)
        {
            this->timer = 0;
            this->state++;
        }
        break;
    case 4:
        if (++this->timer >= 60)
        {
            this->timer = 0;
            DestroyTask(FindTaskIdByFunc(Scene2_Task_PanForest));
            Scene2_DestroyMonSprites(this);
            CreateTask(Scene2_Task_PanMons, 0);
            ChangeBgY(BG_SCENE2_BACKGROUND, 0x00010000, BG_COORD_SET); // Move background from upper half (wide shot) to lower half (close up)
            HideBg(BG_SCENE2_PLANTS);
            ShowBg(BG_SCENE2_BACKGROUND);
            ShowBg(BG_SCENE2_NIDORINO);
            ShowBg(BG_SCENE2_GENGAR);
            this->state++;
        }
        break;
    case 5:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            this->timer = 0;
            this->state++;
        }
        break;
    case 6:
        if (++this->timer >= 60)
        {
            DestroyTask(FindTaskIdByFunc(Scene2_Task_PanMons));
            SetIntroCB(this, IntroCB_Scene3_Entrance);
        }
        break;
    }
}

// Pan the background trees right and the foreground plants left in the wide shot
static void Scene2_Task_PanForest(u8 taskId)
{
    ChangeBgX(BG_SCENE2_BACKGROUND, 0x0E0, BG_COORD_SUB);
    ChangeBgX(BG_SCENE2_PLANTS, 0x110, BG_COORD_ADD);
}

// Pan Gengar up and Nidorino down in the close up shot
static void Scene2_Task_PanMons(u8 taskId)
{
    ChangeBgY(BG_SCENE2_GENGAR, 0x020, BG_COORD_ADD);
    ChangeBgY(BG_SCENE2_NIDORINO, 0x024, BG_COORD_SUB);
}

// Create the Gengar/Nidorino sprites for the wide shot in scene 2
static void Scene2_CreateMonSprites(struct IntroSequenceData * this)
{
    u8 spriteId;

    this->scene2GengarSprite = NULL;
    this->scene2NidorinoSprite = NULL;

    spriteId = CreateSpriteUnchecked(&sSpriteTemplate_Scene2_Nidorino, 168, 80, 11);
    if (spriteId != MAX_SPRITES)
        this->scene2NidorinoSprite = &gSprites[spriteId];

    spriteId = CreateSpriteUnchecked(&sSpriteTemplate_Scene2_Gengar, 72, 80, 12);
    if (spriteId != MAX_SPRITES)
        this->scene2GengarSprite = &gSprites[spriteId];
}

static void Scene2_DestroyMonSprites(struct IntroSequenceData * this)
{
    if (this->scene2GengarSprite != NULL)
        DestroySprite(this->scene2GengarSprite);
    if (this->scene2NidorinoSprite != NULL)
        DestroySprite(this->scene2NidorinoSprite);
}

// Set up the scene 3 graphics, then start the scrolling to get Gengar and Nidorino in their fight positions
static void IntroCB_Scene3_Entrance(struct IntroSequenceData * this)
{
    switch (this->state)
    {
    case 0:
        LoadPalette(sScene3_Bg_Pal, BG_PLTT_ID(1), sizeof(sScene3_Bg_Pal));
        LoadPalette(sGengar_Pal, BG_PLTT_ID(5), sizeof(sGengar_Pal));
        BlendPalettes(PALETTES_ALL & ~1, 16, RGB_WHITE);
        InitBgsFromTemplates(0, sBgTemplates_Scene3, ARRAY_COUNT(sBgTemplates_Scene3));
        DecompressAndCopyTileDataToVram(BG_SCENE3_BACKGROUND, sScene3_Bg_Gfx, 0, 0, 0);
        DecompressAndCopyTileDataToVram(BG_SCENE3_BACKGROUND, sScene3_Bg_Map, 0, 0, 1);
        ShowBg(BG_SCENE3_BACKGROUND);
        HideBg(BG_SCENE3_GENGAR);
        HideBg(BG_SCENE3_UNUSED1);
        HideBg(BG_SCENE3_UNUSED2);
        ResetBgPositions();
        this->state++;
        SetGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_WIN0_ON);
        SetGpuRegBits(REG_OFFSET_WININ, WININ_WIN0_BG1 | WININ_WIN0_OBJ);
        ClearGpuRegBits(REG_OFFSET_WININ, WININ_WIN0_BG0);
        SetGpuRegBits(REG_OFFSET_WINOUT, 0);
        SetGpuReg(REG_OFFSET_WIN0V, WIN_RANGE(32, DISPLAY_HEIGHT - 32));
        SetGpuReg(REG_OFFSET_WIN0H, WIN_RANGE(0, DISPLAY_WIDTH / 2));
        break;
    case 1:
        if (!FreeTempTileDataBuffersIfPossible())
        {
            DecompressAndCopyTileDataToVram(BG_SCENE3_GENGAR, sScene3_GengarAnim_Gfx, 0, 0, 0);
            DecompressAndCopyTileDataToVram(BG_SCENE3_GENGAR, sScene3_GengarAnim_Map, 0, 0, 1);
            ChangeBgX(BG_SCENE3_GENGAR, 0x00001800, BG_COORD_SET);
            ChangeBgY(BG_SCENE3_GENGAR, 0x0001F000, BG_COORD_SET);
            this->state++;
        }
        break;
    case 2:
        if (!FreeTempTileDataBuffersIfPossible())
        {
            BlendPalettes(PALETTES_ALL & ~1, 0, RGB_WHITE);
            ShowBg(BG_SCENE3_GENGAR);
            CreateTask(Scene3_Task_GengarBounce, 0);
            Scene3_CreateNidorinoSprite(this);
            Scene3_StartNidorinoEntrance(this->scene3NidorinoSprite, 0, 180, 52);
            CreateTask(Scene3_Task_GengarEnter, 0);
            Scene3_StartBgScroll();
            this->timer = 0;
            this->state++;
        }
        break;
    case 3:
        if (++this->timer == 16)
            Scene3_CreateGrassSprite(this);
        if (!Scene3_IsNidorinoEntering(this) && !FuncIsActiveTask(Scene3_Task_GengarEnter))
            SetIntroCB(this, IntroCB_Scene3_Fight);
        break;
    }
}

#define tSlow data[0]

// Pan the background trees right during the fight scene.
// It pans quickly while Gengar/Nidorino are sliding onscreen, and it pans slowly thereafter.
static void Scene3_Task_BgScroll(u8 taskId)
{
    if (!gTasks[taskId].tSlow)
        ChangeBgX(BG_SCENE3_BACKGROUND, 0x400, BG_COORD_SUB);
    else
        ChangeBgX(BG_SCENE3_BACKGROUND, 0x020, BG_COORD_SUB);
}

static void Scene3_StartBgScroll(void)
{
    CreateTask(Scene3_Task_BgScroll, 0);
}

static void Scene3_SlowBgScroll(void)
{
    u8 taskId = FindTaskIdByFunc(Scene3_Task_BgScroll);
    gTasks[taskId].tSlow = TRUE;
}

#undef tSlow

#define tPaused data[0]
#define tTimer  data[1]
#define tState  data[2]

// Gengar has an "idle" animation where it bounces a little
static void Scene3_Task_GengarBounce(u8 taskId)
{
    s16 * data = gTasks[taskId].data;
    if (!tPaused)
    {
        if (++tTimer >= 30)
        {
            tTimer = 0;
            tState ^= 1; // Alternate between the 0th (normal) and 1st (slightly crouched) bg frames
            ChangeBgY(BG_SCENE3_GENGAR, (tState << 15) + 0x1F000, BG_COORD_SET);
        }
    }
}

static void Scene3_PauseGengarBounce(void)
{
    u8 taskId = FindTaskIdByFunc(Scene3_Task_GengarBounce);
    gTasks[taskId].tPaused = TRUE;
}

static void Scene3_ResumeGengarBounce(void)
{
    u8 taskId = FindTaskIdByFunc(Scene3_Task_GengarBounce);
    gTasks[taskId].tPaused = FALSE;
}

static bool8 Scene3_IsGengarMidBounce(void)
{
    u8 taskId = FindTaskIdByFunc(Scene3_Task_GengarBounce);
    return gTasks[taskId].tState;
}

#undef tPaused
#undef tTimer
#undef tState

// The small clump of grass that passes by in the foreground during the fight
static void Scene3_CreateGrassSprite(struct IntroSequenceData * this)
{
    u8 spriteId = CreateSpriteUnchecked(&sSpriteTemplate_Grass, 296, 112, 7);
    if (spriteId != MAX_SPRITES)
    {
        this->scene3GrassSprite = &gSprites[spriteId];
        this->scene3GrassSprite->callback = SpriteCB_Grass;
    }
    else
        this->scene3GrassSprite = NULL;
}

#define sState data[0]
#define sBaseX data[1]
#define sVeloc data[2]

static void SpriteCB_Grass(struct Sprite *sprite)
{
    s16 * data = sprite->data;

    switch (sState)
    {
    case 0:
        sBaseX = sprite->x << 5;
        sVeloc = 160;
        sState++;
        // fallthrough
    case 1:
        sBaseX -= sVeloc;
        sprite->x = sBaseX >> 5;
        if (sprite->x <= 52)
        {
            Scene3_SlowBgScroll();
            sState++;
        }
        break;
    case 2:
        sBaseX -= 32;
        sprite->x = sBaseX >> 5;
        if (sprite->x <= -32)
        {
            sprite->invisible = TRUE;
            sprite->sState++;
            DestroySprite(sprite);
        }
        break;
    }
}

#undef sState
#undef sBaseX
#undef sVeloc

static void IntroCB_Scene3_Fight(struct IntroSequenceData * this)
{
    switch (this->state)
    {
    case 0:
        this->timer = 0;
        this->state++;
        break;
    case 1:
        if (++this->timer > 30)
        {
            Scene3_StartNidorinoCry(this);
            this->state++;
        }
        break;
    case 2:
        if (!Scene3_NidorinoAnimIsRunning(this))
        {
            this->timer = 0;
            this->state++;
        }
        break;
    case 3:
        if (++this->timer > 30)
        {
            Scene3_PauseGengarBounce();
            Scene3_StartGengarAttack(this);
            this->timer = 0;
            this->state++;
        }
        break;
    case 4:
        if (this->gengarAttackLanded)
        {
            Scene3_StartNidorinoRecoil(this);
            this->state++;
        }
        break;
    case 5:
        if (!Scene3_NidorinoAnimIsRunning(this))
        {
            Scene3_ResumeGengarBounce();
            this->timer = 0;
            this->state++;
        }
        break;
    case 6:
        if (++this->timer > 16)
        {
            // Nidorino's 1st hop backwards in preparation to attack
            Scene3_StartNidorinoHop(this->scene3NidorinoSprite, 8, 12, 5);
            this->state++;
        }
        break;
    case 7:
        if (!Scene3_NidorinoAnimIsRunning(this))
        {
            // Nidorino's 2nd hop backwards in preparation to attack
            Scene3_StartNidorinoHop(this->scene3NidorinoSprite, 8, 12, 5);
            this->state++;
        }
        break;
    case 8:
        if (!Scene3_NidorinoAnimIsRunning(this))
        {
            this->timer = 0;
            this->state++;
        }
        break;
    case 9:
        if (++this->timer > 20)
        {
            Scene3_StartNidorinoAttack(this);
            this->timer = 0;
            this->state++;
        }
        break;
    case 10:
        if (!Scene3_IsGengarMidBounce())
        {
            Scene3_PauseGengarBounce();
            Scene3_CreateGengarSprite(this);
            this->state++;
        }
        break;
    case 11:
        HideBg(BG_SCENE3_GENGAR);
        this->timer = 0;
        this->state++;
        break;
    case 12:
        if (++this->timer == 48)
            BeginNormalPaletteFade((1 << 1) | (1 << 2), 2, 0, 16, RGB_WHITE);
        if (this->timer > 120)
        {
            Scene3_NidorinoZoom(this);
            Scene3_GengarZoom(this);
            this->state++;
            this->timer = 0;
        }
        break;
    case 13:
        if (++this->timer > 8)
        {
            CpuFill16(RGB_WHITE, &gPlttBufferUnfaded[BG_PLTT_ID(1)], 2 * PLTT_SIZE_4BPP);
            BeginNormalPaletteFade(PALETTES_ALL & ~1, -2, 0, 16, RGB_BLACK);
            this->state++;
        }
        break;
    case 14:
        if (!gPaletteFade.active)
        {
            this->timer = 0;
            this->state++;
        }
        break;
    case 15:
        if (++this->timer > 60)
            SetIntroCB(this, IntroCB_ExitToTitleScreen);
        break;
    default:
        if (JOY_NEW(R_BUTTON))
        {
            BlendPalettes(PALETTES_OBJECTS | (1 << 2) | (1 << 5) | (1 << 6), 0, RGB_WHITE);
            this->scene3NidorinoSprite->x2 = 0;
            this->scene3NidorinoSprite->x = 180;
            this->state = 1;
            this->timer = 30;
        }
        break;
    }
}

static void Scene3_CalcCenterToCornerVec(struct Sprite *sprite)
{
    CalcCenterToCornerVec(sprite, sprite->oam.shape, sprite->oam.size, sprite->oam.affineMode);
}

static void Scene3_CreateGengarSprite(struct IntroSequenceData * this)
{
    int i;

    // Not using a subsprite table for this
    for (i = 0; i < NUM_GENGAR_BACK_SPRITES; i++)
    {
        int x = (i & 1) * 48 + 49;
        int y = (i / 2) * 64 + 72;
        u8 spriteId = CreateSpriteUnchecked(&sSpriteTemplate_Scene3_Gengar, x, y, 8);
        if (spriteId != MAX_SPRITES)
        {
            StartSpriteAnim(&gSprites[spriteId], i);
            this->scene3GengarSprites[i] = &gSprites[spriteId];
            if (i & 1)
                this->scene3GengarSprites[i]->oam.shape = ST_OAM_V_RECTANGLE;
            Scene3_CalcCenterToCornerVec(this->scene3GengarSprites[i]);
        }
    }
}

static void Scene3_NidorinoZoom(struct IntroSequenceData * this)
{
    this->scene3NidorinoSprite->x += this->scene3NidorinoSprite->x2;
    this->scene3NidorinoSprite->y += this->scene3NidorinoSprite->y2;
    SetSpriteMatrixAnchor(this->scene3NidorinoSprite, 0, 42);
    this->scene3NidorinoSprite->callback = SpriteCallbackDummy;
    StartSpriteAffineAnim(this->scene3NidorinoSprite, AFFINEANIM_ZOOM);
}

static void SpriteCB_Idle(struct Sprite *sprite)
{
}

static void Scene3_GengarZoom(struct IntroSequenceData * this)
{
    int i;

    for (i = 0; i < NUM_GENGAR_BACK_SPRITES; i++)
    {
        StartSpriteAffineAnim(this->scene3GengarSprites[i], AFFINEANIM_ZOOM);
        this->scene3GengarSprites[i]->callback = SpriteCB_Idle;
        SetSpriteMatrixAnchor(this->scene3GengarSprites[i], sGengarZoomMatrixAnchors[i][0], sGengarZoomMatrixAnchors[i][1]);
    }
}

static void IntroCB_ExitToTitleScreen(struct IntroSequenceData * this)
{
    switch (this->state)
    {
    case 0:
        FillPalette(RGB_BLACK, 0, PLTT_SIZE);
        this->state++;
        break;
    case 1:
        if (!FreeTempTileDataBuffersIfPossible())
        {
            DestroyTask(this->taskId);
            Free(this);
            DisableInterrupts(INTR_FLAG_HBLANK);
            SetHBlankCallback(NULL);
            SetMainCallback2(CB2_InitTitleScreen);
        }
        break;
    }
}

// Sprite data for SpriteCB_Star
#define sStar_BaseX          data[0]
#define sStar_BaseY          data[1]
#define sStar_SpeedX         data[2]
#define sStar_SpeedY         data[3]
#define sStar_SinIdx         data[4]
#define sStar_SparkleTimer   data[5]
#define sStar_SparkleRngSeed data[6]

static void GFScene_LoadGfxCreateStar(void)
{
    int i;
    u8 spriteId;
    static EWRAM_DATA u32 sStarSparklesRngSeed = 0;

    for (i = 0; i < ARRAY_COUNT(sSpriteSheets_GameFreakScene); i++)
        LoadCompressedSpriteSheet(&sSpriteSheets_GameFreakScene[i]);
    LoadSpritePalettes(sSpritePalettes_GameFreakScene);
    sStarSpeedX = 96;
    sStarSpeedY = 16;
    sStarSparklesXmodMask = 0x07;
    sStarSparklesSpawnRate = 8;
    sStarSparklesFlickerStartTime = 90;
    sStarSparklesDestroySpriteTime = 120;
    sStarSparklesXspeed = 1;
    sStarSparklesYspeed = 1;
    sStarSparklesXprecision = 5;
    sStarSparklesYprecision = 5;
    if (sStarSparklesRngSeed == 0)
        sStarSparklesRngSeed = 354128453;
    spriteId = CreateSpriteUnchecked(&sSpriteTemplate_Star, 248, 55, 0);
    if (spriteId != MAX_SPRITES)
    {
        gSprites[spriteId].sStar_BaseX = 248 << 4;
        gSprites[spriteId].sStar_BaseY = 55 << 4;
        gSprites[spriteId].sStar_SpeedX = sStarSpeedX;
        gSprites[spriteId].sStar_SpeedY = sStarSpeedY;
        StoreWordInTwoHalfwords((u16 *)&gSprites[spriteId].sStar_SparkleRngSeed, sStarSparklesRngSeed);
    }
}

// Sprite data for SpriteCB_SparklesSmall_Star
#define sSmSparkleStar_BaseX     data[0]
#define sSmSparkleStar_BaseY     data[1]
#define sSmSparkleStar_SpeedX    data[2]
#define sSmSparkleStar_SpeedY    data[3]
#define sSmSparkleStar_FallSpeed data[4]
#define sSmSparkleStar_FallDist  data[5]
#define sSmSparkleStar_Timer     data[7]

static void GFScene_CreateStarSparkle(s16 x, s16 y, u16 random)
{
    static EWRAM_DATA s16 sYmod = 0;

    u8 spriteId;
    s16 xMod = (random & sStarSparklesXmodMask) + 2;
    s16 yMod = sYmod;
    if (++sYmod > 3)
        sYmod = -3;
    x += xMod;
    y += yMod;
    if (x > 0 && x < DISPLAY_WIDTH)
    {
        spriteId = CreateSpriteUnchecked(&sSpriteTemplate_SparklesSmall, x, y, 1);
        if (spriteId != MAX_SPRITES)
        {
            gSprites[spriteId].sSmSparkleStar_BaseX = x << sStarSparklesXprecision;
            gSprites[spriteId].sSmSparkleStar_BaseY = y << sStarSparklesYprecision;
            gSprites[spriteId].sSmSparkleStar_SpeedX = sStarSparklesXspeed * xMod;
            gSprites[spriteId].sSmSparkleStar_SpeedY = sStarSparklesYspeed * yMod;
        }
    }
}

#define tSparkleIdx data[0]
#define tNumLoops   data[1]
#define tTimer      data[2]

static void GFScene_StartNameSparklesSmall(void)
{
    CreateTask(GFScene_Task_NameSparklesSmall, 1);
}

// Sprite data for SpriteCB_SparklesSmall_Name
#define sSmSparkleName_State        data[0]
#define sSmSparkleName_BaseY        data[1]
#define sSmSparkleName_AnimTimer    data[2]
#define sSmSparkleName_NumLoops     data[3]
#define sSmSparkleName_DestroyTimer data[4]

static void GFScene_Task_NameSparklesSmall(u8 taskId)
{
    s16 * data = gTasks[taskId].data;
    u8 i;
    u8 spriteId;

    tTimer++;
    data[3]++; // Unused
    if (tTimer > 6)
    {
        tTimer = 0;
        i = tSparkleIdx;
        spriteId = CreateSprite(&sSpriteTemplate_SparklesSmall, sTextSparkleCoords[i].x, sTextSparkleCoords[i].y, 2);
        StartSpriteAnim(&gSprites[spriteId], ANIM_SPARKLE_ONCE);
        gSprites[spriteId].callback = SpriteCB_SparklesSmall_Name;
        gSprites[spriteId].sSmSparkleName_BaseY = sTextSparkleCoords[i].y << 4;
        gSprites[spriteId].sSmSparkleName_AnimTimer = 120;
        gSprites[spriteId].sSmSparkleName_NumLoops = tNumLoops;
        if (gSprites[spriteId].sSmSparkleName_NumLoops < 0)
            gSprites[spriteId].sSmSparkleName_NumLoops = 1;
        if (++tSparkleIdx >= ARRAY_COUNT(sTextSparkleCoords))
        {
            if (++tNumLoops > 1)
                DestroyTask(taskId);
            else
                tSparkleIdx = 0;
        }
    }
}

#undef tSparkleIdx
#undef tNumLoops
#undef tTimer

#define tTimer       data[0]
#define tSparkleIdx  data[1]
#define tNumSparkles data[2]

static void GFScene_StartNameSparklesBig(void)
{
    CreateTask(GFScene_Task_NameSparklesBig, 2);
}

static void GFScene_Task_NameSparklesBig(u8 taskId)
{
    s16 * data = gTasks[taskId].data;
    u8 i;

    if (tTimer == 0)
    {
        i = tSparkleIdx;
        tSparkleIdx += 4;
        if (tSparkleIdx >= ARRAY_COUNT(sTextSparkleCoords))
            tSparkleIdx -= ARRAY_COUNT(sTextSparkleCoords);
        CreateSprite(&sSpriteTemplate_SparklesBig, sTextSparkleCoords[i].x, sTextSparkleCoords[i].y, 3);
        if (++tNumSparkles >= (int)ARRAY_COUNT(sTextSparkleCoords))
            DestroyTask(taskId);
    }
    if (++tTimer > 9)
        tTimer = 0;
}

#undef tTimer
#undef tSparkleIdx
#undef tNumSparkles

static struct Sprite *GFScene_CreateLogoSprite(void)
{
    u8 spriteId = CreateSprite(&sSpriteTemplate_GameFreakLogoArt, 120, 70, 4);
    return &gSprites[spriteId];
}

static void GFScene_CreatePresentsSprite(void)
{
    int i;
    for (i = 0; i < 2; i++)
        gSprites[CreateSprite(&sSpriteTemplate_Presents, 104 + 32 * i, 108, 5)].oam.tileNum += i * 4;
}

#define tState  data[0]
#define tTimer  data[1]
#define tSinIdx data[3]
#define tBaseX  data[4]
#define IDX_INTRO_DATA 5  // A pointer to the IntroSequenceData will be stored at data[5] and data[6]
#define tFrame  data[7]
#define tMultY  data[8]
#define tMultX  data[9]

static void Scene3_StartGengarAttack(struct IntroSequenceData * this)
{
    u8 taskId;
    this->gengarAttackLanded = FALSE;
    taskId = CreateTask(Scene3_Task_GengarAttack, 4);
    SetWordTaskArg(taskId, IDX_INTRO_DATA, (uintptr_t)this);
    gTasks[taskId].tSinIdx = 64;
    gTasks[taskId].tBaseX = GetBgX(BG_SCENE3_GENGAR);
}

static void Scene3_ApplyGengarAnim(int frame, int xSub, int ySub, int xBase)
{
    ChangeBgY(BG_SCENE3_GENGAR, (frame << 15) + 0x1F000, BG_COORD_SET);
    ChangeBgX(BG_SCENE3_GENGAR, xBase, BG_COORD_SET);
    ChangeBgX(BG_SCENE3_GENGAR, xSub << 8, BG_COORD_SUB);
    ChangeBgY(BG_SCENE3_GENGAR, ySub << 8, BG_COORD_SUB);
}

static void Scene3_Task_GengarAttack(u8 taskId)
{
    s16 * data = gTasks[taskId].data;
    s32 xSub, ySub;
    s32 sinIdx;
    switch (tState)
    {
    case 0:
        tFrame = 2; // Gengar raises arm up
        tTimer = 0;
        tMultY = 6;
        tMultX = 32;
        tState++;
        break;
    case 1:
        // Gengar moves in a backward arc
        tSinIdx -= 2;
        if (++tTimer > 15)
        {
            tTimer = 0;
            tState++;
        }
        break;
    case 2:
        // Gengar pauses at end of backward arc
        if (++tTimer == 14)
            ((struct IntroSequenceData *)GetWordTaskArg(taskId, IDX_INTRO_DATA))->gengarAttackLanded = TRUE;
        if (tTimer > 15)
        {
            tTimer = 0;
            tState++;
        }
        break;
    case 3:
        // Gengar moves in a forward arc
        tSinIdx += 8;
        if (++tTimer == 4)
        {
            Scene3_CreateGengarSwipeSprites();
            tMultY = 32;
            tMultX = 48;
            tFrame = 3; // Gengar swipes arm down
        }
        if (tTimer > 7)
        {
            tTimer = 0;
            tState++;
        }
        break;
    case 4:
        // Gengar moves in a backward arc to its original position
        tSinIdx -= 8;
        if (++tTimer > 3)
        {
            tFrame = 0; // Gengar returns to normal posture
            tSinIdx = 64;
            tTimer = 0;
            tState++;
        }
        break;
    case 5:
        DestroyTask(taskId);
        return;
    }

    // Animate current movement arc / frame change
    sinIdx = tSinIdx;
    xSub = -((gSineTable[sinIdx + 64] * tMultX) >> 8);
    ySub = tMultY - ((gSineTable[sinIdx] * tMultY) >> 8);
    Scene3_ApplyGengarAnim(tFrame, xSub, ySub, tBaseX);
}

#undef tState
#undef tTimer
#undef tSinIdx
#undef tBaseX
#undef IDX_INTRO_DATA
#undef tFrame
#undef tMultY
#undef tMultX

static void Scene3_CreateGengarSwipeSprites(void)
{
    u8 spriteId = CreateSprite(&sSpriteTemplate_GengarSwipe, 132, 78, 6); // Implicitly ANIM_SWIPE_TOP
    spriteId = CreateSpriteUnchecked(&sSpriteTemplate_GengarSwipe, 132, 118, 6);
    if (spriteId != MAX_SPRITES)
    {
        gSprites[spriteId].oam.shape = SPRITE_SHAPE(32x16);
        gSprites[spriteId].oam.size = SPRITE_SIZE(32x16);
        Scene3_CalcCenterToCornerVec(&gSprites[spriteId]);
        StartSpriteAnim(&gSprites[spriteId], ANIM_SWIPE_BOTTOM);
    }
}

static void SpriteCB_GengarSwipe(struct Sprite *sprite)
{
    sprite->invisible ^= 1;
    if (sprite->animEnded)
        DestroySprite(sprite);
}

#define tState data[0]
#define tSpeed data[1]
#define tMoves data[2]

// Scroll Gengar into position for the fight
static void Scene3_Task_GengarEnter(u8 taskId)
{
    s16 * data = gTasks[taskId].data;
    static EWRAM_DATA u32 sGengarScroll = 0;

    switch (tState)
    {
    case 0:
        tSpeed = 0x400;
        tState++;
        // fallthrough
    case 1:
        // Don't decelerate for the first 40 movements
        if (++tMoves >= 40 && tSpeed > 16)
            tSpeed -= 16;
        sGengarScroll = ChangeBgX(BG_SCENE3_GENGAR, tSpeed, BG_COORD_ADD);

        if (sGengarScroll >= 0x8000)
            ClearGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_WIN0_ON);

        if (sGengarScroll >= 0xEF00)
        {
            ChangeBgX(BG_SCENE3_GENGAR, 0xEF00, BG_COORD_SET);
            DestroyTask(taskId);
        }
        break;
    }
}

#undef tState
#undef tSpeed
#undef tMoves

static void SpriteCB_Star(struct Sprite *sprite)
{
    u32 random;
    sprite->sStar_BaseX -= sprite->sStar_SpeedX;
    sprite->sStar_BaseY += sprite->sStar_SpeedY;
    sprite->sStar_SinIdx += 48;
    sprite->x = sprite->sStar_BaseX >> 4;
    sprite->y = sprite->sStar_BaseY >> 4;
    sprite->y2 = gSineTable[(sprite->sStar_SinIdx >> 4) + 64] >> 5;
    sprite->sStar_SparkleTimer++;
    if (sprite->sStar_SparkleTimer % sStarSparklesSpawnRate)
    {
        LoadWordFromTwoHalfwords((u16*)&sprite->sStar_SparkleRngSeed, &random);
        random = ISO_RANDOMIZE1(random);
        StoreWordInTwoHalfwords((u16*)&sprite->sStar_SparkleRngSeed, random);
        random >>= 16;
        GFScene_CreateStarSparkle(sprite->x, sprite->y + sprite->y2, random);
    }
    if (sprite->x < -8)
        DestroySprite(sprite);
}

// Callback for the sparkles that trail behind the star
static void SpriteCB_SparklesSmall_Star(struct Sprite *sprite)
{
    sprite->sSmSparkleStar_BaseX += sprite->sSmSparkleStar_SpeedX;
    sprite->sSmSparkleStar_BaseY += sprite->sSmSparkleStar_SpeedY;
    sprite->sSmSparkleStar_FallDist += ++sprite->sSmSparkleStar_FallSpeed;
    sprite->sSmSparkleStar_Timer++;
    sprite->x = (u16)sprite->sSmSparkleStar_BaseX >> sStarSparklesXprecision;
    sprite->y = sprite->sSmSparkleStar_BaseY >> sStarSparklesYprecision;
    if (sStarSparklesGravityShift && sprite->sSmSparkleStar_SpeedY < 0)
        sprite->y2 = sprite->sSmSparkleStar_FallDist >> sStarSparklesGravityShift;
    if (sprite->sSmSparkleStar_Timer > sStarSparklesFlickerStartTime)
    {
        sprite->invisible = !sprite->invisible;
        if (sprite->sSmSparkleStar_Timer > sStarSparklesDestroySpriteTime)
            DestroySprite(sprite);
    }
    if (sprite->y + sprite->y2 < 0 || sprite->y + sprite->y2 > DISPLAY_HEIGHT)
        DestroySprite(sprite);
}

#undef sSmSparkleStar_BaseX
#undef sSmSparkleStar_BaseY
#undef sSmSparkleStar_SpeedX
#undef sSmSparkleStar_SpeedY
#undef sSmSparkleStar_FallSpeed
#undef sSmSparkleStar_FallDist
#undef sSmSparkleStar_Timer

// Callback for the small sparkles during the "Game Freak" text reveal
static void SpriteCB_SparklesSmall_Name(struct Sprite *sprite)
{
    if (sprite->sSmSparkleName_AnimTimer)
    {
        sprite->sSmSparkleName_AnimTimer--;
        sprite->sSmSparkleName_BaseY++;
        sprite->y = sprite->sSmSparkleName_BaseY >> 4;
        if (sprite->y > 86)
        {
            sprite->y = 74;
            sprite->sSmSparkleName_BaseY = 74 << 4;
        }
        if (sprite->animEnded)
        {
            if (sprite->sSmSparkleName_State == 0)
            {
                sprite->x += 26;
                if (sprite->x > 188)
                {
                    sprite->x = (188 * 2) - sprite->x;
                    sprite->sSmSparkleName_State = 1;
                }
            }
            else
            {
                sprite->x -= 26;
                if (sprite->x < 52)
                {
                    sprite->x = (52 * 2) - sprite->x;
                    sprite->sSmSparkleName_State = 0;
                }
            }
            StartSpriteAnim(sprite, ANIM_SPARKLE_ONCE);
        }
    }
    else
    {
        if (sprite->sSmSparkleName_NumLoops)
            DestroySprite(sprite);
        if (sprite->animEnded)
            StartSpriteAnim(sprite, ANIM_SPARKLE_LOOP);
        sprite->sSmSparkleName_BaseY += 4;
        sprite->y = sprite->sSmSparkleName_BaseY >> 4;
        if (++sprite->sSmSparkleName_DestroyTimer > 50)
            DestroySprite(sprite);
    }
}

#undef sStar_BaseX
#undef sStar_BaseY
#undef sStar_SpeedX
#undef sStar_SpeedY
#undef sStar_SinIdx
#undef sStar_SparkleTimer
#undef sStar_SparkleRngSeed

// Callback for the big sparkles during the "Game Freak" text reveal
static void SpriteCB_SparklesBig(struct Sprite *sprite)
{
    if (sprite->animEnded)
        DestroySprite(sprite);
}

static void Scene3_CreateNidorinoSprite(struct IntroSequenceData * this)
{
    u8 spriteId = CreateSprite(&sSpriteTemplate_Scene3_Nidorino, 0, 0, 9);
    this->scene3NidorinoSprite = &gSprites[spriteId];
}

#define sX       data[0]
#define sSpeed   data[1]
#define sTime    data[2] // Not read
#define sTargetX data[3]
#define sTimer   data[4]

static void Scene3_StartNidorinoEntrance(struct Sprite *sprite, s16 xStart, s16 x1, u16 time)
{
    sprite->sX = xStart << 4;
    sprite->sSpeed = ((x1 - xStart) << 4) / time;
    sprite->sTime = time;
    sprite->sTargetX = x1;
    sprite->sTimer = 0;
    sprite->x = xStart;
    sprite->y = 100;
    sprite->callback = Scene3_SpriteCB_NidorinoEnter;
}

static void Scene3_SpriteCB_NidorinoEnter(struct Sprite *sprite)
{
    if (++sprite->sTimer >= 40)
    {
        // Start decelerating after 40 frames
        if (sprite->sSpeed > 1)
            sprite->sSpeed--;
    }
    sprite->sX += sprite->sSpeed;
    sprite->x = sprite->sX >> 4;
    if (sprite->x >= sprite->sTargetX)
    {
        // Reached final position
        sprite->x = sprite->sTargetX;
        sprite->callback = SpriteCallbackDummy;
    }
}

static bool32 Scene3_IsNidorinoEntering(struct IntroSequenceData * ptr)
{
    return ptr->scene3NidorinoSprite->callback == Scene3_SpriteCB_NidorinoEnter ? TRUE : FALSE;
}

#undef sX
#undef sSpeed
#undef sTime
#undef sTargetX
#undef sTimer

#define sState       data[0]
#define sStateTimer  data[1]
#define sBounceTimer data[2]

static void Scene3_StartNidorinoCry(struct IntroSequenceData * ptr)
{
    StartSpriteAnim(ptr->scene3NidorinoSprite, ANIM_NIDORINO_CROUCH);
    ptr->scene3NidorinoSprite->sState = 0;
    ptr->scene3NidorinoSprite->sStateTimer = 0;
    ptr->scene3NidorinoSprite->y2 = 3;
    ptr->scene3NidorinoSprite->callback = SpriteCB_NidorinoCry;
}

static void SpriteCB_NidorinoCry(struct Sprite *sprite)
{
    switch (sprite->sState)
    {
    case 0:
        if (++sprite->sStateTimer > 8)
        {
            StartSpriteAnim(sprite, ANIM_NIDORINO_CRY);
            sprite->y2 = 0;
            sprite->sState++;
        }
        break;
    case 1:
        PlayCry_ByMode(SPECIES_NIDORINO, 0x3F, CRY_MODE_DOUBLES);
        sprite->sStateTimer = 0;
        sprite->sState++;
        break;
    case 2:
        if (++sprite->sBounceTimer > 1)
        {
            // Nidorino bounces slightly while crying
            sprite->sBounceTimer = 0;
            sprite->y2 = sprite->y2 == 0 ? 1 : 0;
        }
        if (++sprite->sStateTimer > 48)
        {
            StartSpriteAnim(sprite, ANIM_NIDORINO_NORMAL);
            sprite->y2 = 0;
            sprite->callback = SpriteCallbackDummy;
        }
        break;
    }
}

#undef sState
#undef sStateTimer
#undef sBounceTimer

#define sState         data[0]
#define sStateTimer    data[1]
#define sOffsetX       data[2]
#define sSinIdx        data[3]
#define sLandTimer     data[4]
#define sSlowdownTimer data[5]
#define sRandSeed      data[6]
#define sSpeedX        data[7]

static void Scene3_StartNidorinoRecoil(struct IntroSequenceData * ptr)
{
    sNidorinoRecoilReturnTime = 16;
    sNidorinoJumpMult = 3;
    sNidorinoJumpDiv = 5;
    sNidorinoAnimDelayTime = 0;
    StartSpriteAnim(ptr->scene3NidorinoSprite, ANIM_NIDORINO_CROUCH);
    ptr->scene3NidorinoSprite->sState = 0;
    ptr->scene3NidorinoSprite->sStateTimer = 0;
    ptr->scene3NidorinoSprite->sOffsetX = 0;
    ptr->scene3NidorinoSprite->sSinIdx = 0;
    ptr->scene3NidorinoSprite->sLandTimer = 0;
    ptr->scene3NidorinoSprite->sSpeedX = 40;
    ptr->scene3NidorinoSprite->callback = SpriteCB_NidorinoRecoil;
}

static void SpriteCB_NidorinoRecoil(struct Sprite *sprite)
{
    switch (sprite->sState)
    {
    case 0:
        if (++sprite->sStateTimer > 4)
        {
            StartSpriteAnim(sprite, ANIM_NIDORINO_HOP);
            sprite->sState++;
        }
        break;
    case 1:
        // Nidorino jumping backwards in the air
        sprite->sOffsetX += sprite->sSpeedX;
        sprite->sSinIdx += 8;
        sprite->x2 = sprite->sOffsetX >> 4;
        sprite->y2 = -((gSineTable[sprite->sSinIdx] * sNidorinoJumpMult) >> sNidorinoJumpDiv);
        sprite->sSlowdownTimer++;
        if (sprite->sSlowdownTimer > sNidorinoAnimDelayTime)
        {
            sprite->sSlowdownTimer = 0;
            sprite->sSpeedX--;
        }
        if (++sprite->sLandTimer > 15)
        {
            // Nidorino hits the ground
            StartSpriteAnim(sprite, ANIM_NIDORINO_CROUCH);
            sprite->sStateTimer = 0;
            sprite->sRandSeed = 0x4757;
            sprite->sSpeedX = 28;
            sprite->sState++;
        }
        break;
    case 2:
        // Nidorino sliding on the ground
        sprite->sOffsetX += sprite->sSpeedX;
        sprite->x2 = sprite->sOffsetX >> 4;
        if (++sprite->sStateTimer > 6)
        {
            // The position of each subsequent dust sprite is "random", but with a fixed
            // initial seed so that they'll be in the same positions between intro runs
            CreateNidorinoRecoilDustSprites(sprite->x + sprite->x2, sprite->y + sprite->y2, sprite->sRandSeed);
            sprite->sRandSeed *= 1103515245;
        }
        if (sprite->sStateTimer > 12)
        {
            StartSpriteAnim(sprite, ANIM_NIDORINO_NORMAL);
            sprite->sStateTimer = 0;
            sprite->sState++;
        }
        break;
    case 3:
        // Nidorino hops back to its original position
        if (++sprite->sStateTimer > 16)
            Scene3_StartNidorinoHop(sprite, sNidorinoRecoilReturnTime, -sprite->x2, 4);
        break;
    }
}

#undef sState
#undef sStateTimer
#undef sOffsetX
#undef sSinIdx
#undef sLandTimer
#undef sSlowdownTimer
#undef sRandSeed
#undef sSpeedX

static bool8 Scene3_NidorinoAnimIsRunning(struct IntroSequenceData * ptr)
{
    return ptr->scene3NidorinoSprite->callback == SpriteCallbackDummy ? FALSE : TRUE;
}

#define sState          data[0]
#define sX              data[1]
#define sY              data[2]
#define sSpeedX         data[3]
#define sSpeedY         data[4]
#define sInvisibleTimer data[7]

static void CreateNidorinoRecoilDustSprites(s16 x, s16 y, s16 seed)
{
    int i;
    u8 spriteId;

    // Recoil dust sprites are created in pairs at the same initial position but with different speeds.
    // Only one of each pair will be visible at a time.
    for (i = 0; i < 2; i++)
    {
        spriteId = CreateSpriteUnchecked(&sSpriteTemplate_NidorinoRecoilDust, x - 22, y + 24, 10);
        if (spriteId != MAX_SPRITES)
        {
            gSprites[spriteId].sSpeedX = (seed % 13) + 8;
            gSprites[spriteId].sSpeedY = seed % 3;
            gSprites[spriteId].sInvisibleTimer = i;
            seed *= 1103515245;
        }
    }
}

static void SpriteCB_RecoilDust(struct Sprite *sprite)
{
    s16 * data = sprite->data;

    switch (sprite->sState)
    {
    case 0:
        sX = sprite->x << 4;
        sY = sprite->y << 4;
        sprite->sState++;
        // fallthrough
    case 1:
        sX -= sSpeedX;
        sY += sSpeedY;
        sprite->x = sX >> 4;
        sprite->y = sY >> 4;
        if (sprite->animEnded)
            DestroySprite(sprite);
        break;
    }

    // Recoil dust flashes in and out
    if (++sInvisibleTimer > 1)
    {
        sInvisibleTimer = 0;
        sprite->invisible ^= 1;
    }
}

#undef sState
#undef sX
#undef sY
#undef sSpeedX
#undef sSpeedY
#undef sInvisibleTimer

#define sState       data[0]
#define sAirTime     data[1]
#define sOffsetX     data[2]
#define sSpeedX      data[3]
#define sSinIdx      data[4]
#define sSpeedY      data[5]
#define sTimer       data[6]
#define sHeightShift data[7]

static void Scene3_StartNidorinoHop(struct Sprite *sprite, u16 time, s16 targetX, u8 heightShift)
{
    sprite->sState = 0;
    sprite->sAirTime = time;
    sprite->sOffsetX = sprite->x2 << 4;
    sprite->sSpeedX = (targetX << 4) / time;
    sprite->sSinIdx = 0;
    sprite->sSpeedY = 0x800 / time;
    sprite->sTimer = 0;
    sprite->sHeightShift = heightShift;
    StartSpriteAnim(sprite, ANIM_NIDORINO_CROUCH);
    sprite->callback = SpriteCB_NidorinoHop;
}

static void SpriteCB_NidorinoHop(struct Sprite *sprite)
{
    switch (sprite->sState)
    {
    case 0:
        if (++sprite->sTimer > 4)
        {
            StartSpriteAnim(sprite, ANIM_NIDORINO_HOP);
            sprite->sTimer = 0;
            sprite->sState++;
        }
        break;
    case 1:
        if (--sprite->sAirTime)
        {
            // Nidorino moving through the air
            sprite->sOffsetX += sprite->sSpeedX;
            sprite->sSinIdx += sprite->sSpeedY;
            sprite->x2 = sprite->sOffsetX >> 4;
            sprite->y2 = -(gSineTable[sprite->sSinIdx >> 4] >> sprite->sHeightShift);
        }
        else
        {
            // Nidorino lands
            sprite->x2 = (u16)sprite->sOffsetX >> 4;
            sprite->y2 = 0;
            StartSpriteAnim(sprite, ANIM_NIDORINO_CROUCH);
            if (sprite->sHeightShift == 5)
            {
                // This is used by the short hops before Nidorino's attack.
                // The last state is skipped so that Nidorino will stay in the crouched animation.
                sprite->callback = SpriteCallbackDummy;
            }
            else
            {
                sprite->sTimer = 0;
                sprite->sState++;
            }
        }
        break;
    case 2:
        if (++sprite->sTimer > 4)
        {
            StartSpriteAnim(sprite, ANIM_NIDORINO_NORMAL);
            sprite->callback = SpriteCallbackDummy;
        }
        break;
    }
}

#undef sState
#undef sAirTime
#undef sOffsetX
#undef sSpeedX
#undef sSinIdx
#undef sSpeedY
#undef sTimer
#undef sHeightShift

#define sState      data[0]
#define sTimer      data[1]
#define sShakeTimer data[2]
#define sSpeed      data[7]

static void Scene3_StartNidorinoAttack(struct IntroSequenceData * ptr)
{
    ptr->scene3NidorinoSprite->sState = 0;
    ptr->scene3NidorinoSprite->sTimer = 0;
    ptr->scene3NidorinoSprite->sShakeTimer = 0;
    ptr->scene3NidorinoSprite->data[3] = 0; // Unused
    ptr->scene3NidorinoSprite->data[4] = 0; // Unused
    ptr->scene3NidorinoSprite->data[5] = 0; // Unused
    ptr->scene3NidorinoSprite->x += ptr->scene3NidorinoSprite->x2;
    ptr->scene3NidorinoSprite->x2 = 0;
    sNidorinoAnimDelayTime = 40;
    sNidorinoJumpMult = 3;
    sNidorinoJumpDiv = 4;
    ptr->scene3NidorinoSprite->sSpeed = 36;
    StartSpriteAnim(ptr->scene3NidorinoSprite, ANIM_NIDORINO_CROUCH);
    ptr->scene3NidorinoSprite->callback = SpriteCB_NidorinoAttack;
}

static void SpriteCB_NidorinoAttack(struct Sprite *sprite)
{
    switch (sprite->sState)
    {
    case 0:
        if (++sprite->sTimer & 1)
        {
            // Nidorino shakes horizontally before attacking
            if (++sprite->sShakeTimer & 1)
                sprite->x2++;
            else
                sprite->x2--;
        }
        if (sprite->sTimer > 17)
        {
            sprite->sTimer = 0;
            sprite->sState++;
        }
        break;
    case 1:
        if (++sprite->sTimer >= sNidorinoAnimDelayTime)
        {
            StartSpriteAnim(sprite, ANIM_NIDORINO_ATTACK);
            sprite->sTimer = 0;
            sprite->sShakeTimer = 0;
            sprite->sState++;
        }
        break;
    case 2:
        // Nidorino jumps at Gengar
        sprite->sTimer += sprite->sSpeed;
        sprite->x2 = -(sprite->sTimer >> 4);
        sprite->y2 = -((gSineTable[sprite->sTimer >> 4] * sNidorinoJumpMult) >> sNidorinoJumpDiv);
        sprite->sShakeTimer++; // Does nothing
        if (sprite->sSpeed > 12)
            sprite->sSpeed--; // Decelerate as jump progresses
        if ((sprite->sTimer >> 4) > 63)
            sprite->callback = SpriteCallbackDummy;
        break;
    }
}

#undef sState
#undef sTimer
#undef sShakeTimer
#undef sSpeed

static void LoadFightSceneSpriteGraphics(void)
{
    int i;
    for (i = 0; i < ARRAY_COUNT(sFightSceneSpriteSheets); i++)
        LoadCompressedSpriteSheet(&sFightSceneSpriteSheets[i]);
    LoadSpritePalettes(sFightSceneSpritePalettes);
}
