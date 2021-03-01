#include "global.h"
#include "malloc.h"
#include "battle.h"
#include "bg.h"
#include "data.h"
#include "decompress.h"
#include "event_data.h"
#include "gpu_regs.h"
#include "graphics.h"
#include "item_menu.h"
#include "main.h"
#include "menu.h"
#include "menu_helpers.h"
#include "m4a.h"
#include "palette.h"
#include "party_menu.h"
#include "pokeblock.h"
#include "pokemon.h"
#include "sprite.h"
#include "string_util.h"
#include "strings.h"
#include "sound.h"
#include "task.h"
#include "text_window.h"
#include "trig.h"
#include "util.h"
#include "constants/rgb.h"

struct PokeblockFeedStruct
{
    struct Sprite *monSpritePtr;
    struct Sprite savedMonSprite;
    u8 tilemapBuffer[0x808];
    s16 field_850[0x200];
    s16 field_C50[0x200];
    u8 field_1050;
    u8 animId;
    u8 field_1052;
    bool8 noMonFlip;
    u16 species;
    u16 field_1056;
    u16 field_1058;
    u8 nature;
    u8 monSpriteId_;
    u8 field_105C;
    u8 monSpriteId;
    u8 pokeblockCaseSpriteId;
    u8 pokeblockSpriteId;
    s16 field_1060[15];
    s16 loadGfxState;
    u8 unused;
};

extern struct MusicPlayerInfo gMPlayInfo_BGM;

extern const u16 gUnknown_0860F074[];

// this file's functions
static void HandleInitBackgrounds(void);
static void HandleInitWindows(void);
static void LaunchPokeblockFeedTask(void);
static void SetPokeblockSpritePal(u8 pokeblockCaseId);
static void sub_817A5CC(void);
static void DoPokeblockCaseThrowEffect(u8 spriteId, bool8 arg1);
static void PrepareMonToMoveToPokeblock(u8 spriteId);
static void Task_HandleMonAtePokeblock(u8 taskId);
static void Task_PaletteFadeToReturn(u8 taskId);
static void sub_817A634(void);
static void sub_817A468(struct Sprite *sprite);
static void sub_817AB68(void);
static void sub_817AA54(void);
static bool8 sub_817A91C(void);
static bool8 FreeMonSpriteOamMatrix(void);
static bool8 sub_817A9E4(void);
static bool8 LoadMonAndSceneGfx(struct Pokemon *mon);
static u8 CreatePokeblockSprite(void);
static u8 CreatePokeblockCaseSpriteForFeeding(void);
static u8 CreateMonSprite(struct Pokemon *mon);
static void SpriteCB_ThrownPokeblock(struct Sprite* sprite);

// ram variables
EWRAM_DATA static struct PokeblockFeedStruct *sPokeblockFeed = NULL;
EWRAM_DATA static struct CompressedSpritePalette sPokeblockSpritePal = {0};

// const rom data
static const u8 sNatureToMonPokeblockAnim[NUM_NATURES][2] =
{
    [NATURE_HARDY] = {  0, 0 },
    [NATURE_LONELY] = {  3, 0 },
    [NATURE_BRAVE] = {  4, 1 },
    [NATURE_ADAMANT] = {  5, 0 },
    [NATURE_NAUGHTY] = { 10, 0 },
    [NATURE_BOLD] = { 13, 0 },
    [NATURE_DOCILE] = { 15, 0 },
    [NATURE_RELAXED] = { 16, 2 },
    [NATURE_IMPISH] = { 18, 0 },
    [NATURE_LAX] = { 19, 0 },
    [NATURE_TIMID] = { 20, 0 },
    [NATURE_HASTY] = { 25, 0 },
    [NATURE_SERIOUS] = { 27, 3 },
    [NATURE_JOLLY] = { 28, 0 },
    [NATURE_NAIVE] = { 29, 0 },
    [NATURE_MODEST] = { 33, 4 },
    [NATURE_MILD] = { 36, 0 },
    [NATURE_QUIET] = { 37, 0 },
    [NATURE_BASHFUL] = { 39, 0 },
    [NATURE_RASH] = { 42, 0 },
    [NATURE_CALM] = { 45, 0 },
    [NATURE_GENTLE] = { 46, 5 },
    [NATURE_SASSY] = { 47, 6 },
    [NATURE_CAREFUL] = { 48, 0 },
    [NATURE_QUIRKY] = { 53, 0 },
};

static const s16 sMonPokeblockAnims[][10] =
{
    // HARDY
    {   0,   4,   0,   8,  24,   0,   0,   0,  12,   0},
    {   0,   4,   0,  16,  24,   0,   0,   0,  12,   0},
    {   0,   4,   0,  32,  32,   0,   0,   0,  16,   1},

    // LONELY
    {   0,   3,   6,   0,  48,   0,   0,   0,  24,   1},

    // BRAVE
    {  64,  16, -24,   0,  32,   0,   0,   0,   0,   1},

    // ADAMANT
    {   0,   4,   8,   0,  16,   0,  -8,   0,   0,   0},
    {   0,   0,   0,   0,  16,   0,   0,   0,   0,   0},
    {   0,   4,   8,   0,  16,   0,  -8,   0,   0,   0},
    {   0,   0,   0,   0,  16,   0,   0,   0,   0,   0},
    {   0,   4, -16,   0,   4,   0,  16,   0,   0,   1},

    // NAUGHTY
    {   0,   3,   6,   0,  12,   0,   0,   0,   6,   0},
    {   0,   3,  -6,   0,  12,   0,   0,   0,   6,   0},
    {   0,  16,  16,   0,  45,   1,   0,   0,   0,   1},

    // BOLD
    {   0,  16,   0,  24,  32,   0,   0,   0,  16,   0},
    {   0,  16,   0,  23,  32,   0,   0,   0,  16,   1},

    // DOCILE
    {   0,   0,   0,   0,  80,   0,   0,   0,   0,   1},

    // RELAXED
    {   0,   2,   8,   0,  32,   0,   0,   0,   0,   0},
    {   0,   2,  -8,   0,  32,   0,   0,   0,   0,   1},

    // IMPISH
    {   0,  32,   2,   1,  48,   1,   0,   0,  24,   1},

    // LAX
    {   0,   2,  16,  16, 128,   0,   0,   0,   0,   1},

    // TIMID
    {   0,   2,  -8,   0,  48,   0, -24,   0,   0,   0},
    {   0,   0,   0,   0,   8,   0,   0,   0,   0,   0},
    {  64,  32,   2,   0,  36,   0,   0,   0,   0,   0},
    {   0,   0,   0,   0,   8,   0,   0,   0,   0,   0},
    {   0,   2,   8,   0,  48,   0,  24,   0,   0,   1},

    // HASTY
    {  64,  24,  16,   0,  32,   0,   0,   0,   0,   0},
    {   0,  28,   2,   1,  32,   1,   0,   0,  16,   1},

    // SERIOUS
    {   0,   0,   0,   0,  32,   0,   0,   0,   0,   1},

    // JOLLY
    {  64,  16, -16,   2,  48,   0,   0,   0,  32,   1},

    // NAIVE
    {   0,  12,  -8,   4,  24,   0,   8,   0,  12,   0},
    {   0,  12,   8,   8,  24,   0, -16,   0,  12,   0},
    {   0,  12,  -8,  16,  24,   0,  16,   0,  12,   0},
    {   0,  12,   8,  28,  24,   0,  -8,   0,  12,   1},

    // MODEST
    {   0,   0,   0,   0,   8,   0,   0,   0,   0,   0},
    {  64,  16,  -4,   0,  32,   0,   0,   0,   0,   0},
    {   0,   0,   0,   0,   8,   0,   0,   0,   0,   1},

    // MILD
    { 128,   4,   0,   8,  64,   0,   0,   0,   0,   1},

    // QUIET
    {   0,   2,  16,   0,  48,   0,   0,   0,   0,   0},
    { 128,   2,  16,   0,  48,   0,   0,   0,   0,   1},

    // BASHFUL
    {   0,   2,  -4,   0,  48,   0, -48,   0,   0,   0},
    {   0,   0,   0,   0,  80,   0,   0,   0,   0,   0},
    {   0,   2,   8,   0,  24,   0,  48,   0,   0,   1},

    // RASH
    {  64,   4,  64,  58,  52,   0, -88,   0,   0,   0},
    {   0,   0,   0,   0,  80,   0,   0,   0,   0,   0},
    {   0,  24,  80,   0,  32,   0,  88,   0,   0,   1},

    // CALM
    {   0,   2,  16,   4,  64,   0,   0,   0,   0,   1},

    // GENTLE
    {   0,   0,   0,   0,  32,   0,   0,   0,   0,   1},

    // SASSY
    {   0,   0,   0,   0,  42,   0,   0,   0,   0,   1},

    // CAREFUL
    {   0,   4,   0,   8,  24,   0,   0,   0,  12,   0},
    {   0,   0,   0,   0,  12,   0,   0,   0,   0,   0},
    {   0,   4,   0,  12,  24,   0,   0,   0,  12,   0},
    {   0,   0,   0,   0,  12,   0,   0,   0,   0,   0},
    {   0,   4,   0,   4,  24,   0,   0,   0,  12,   1},

    // QUIRKY
    {   0,   4,  16,  12,  64,   0,   0,   0,   0,   0},
    {   0,  -4,  16,  12,  64,   0,   0,   0,   0,   1},
};

static const union AffineAnimCmd sSpriteAffineAnim_8411E90[] =
{
    AFFINEANIMCMD_FRAME(-0x100, 0x100, 0, 0),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd sSpriteAffineAnim_8411EA0[] =
{
    AFFINEANIMCMD_FRAME(0, 0, 12, 1),
    AFFINEANIMCMD_FRAME(0, 0, 0, 30),
    AFFINEANIMCMD_FRAME(0, 0, -12, 1),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd sSpriteAffineAnim_8411EC0[] =
{
    AFFINEANIMCMD_FRAME(-0x100, 0x100, 0, 0),
    AFFINEANIMCMD_FRAME(0, 0, 12, 1),
    AFFINEANIMCMD_FRAME(0, 0, 0, 28),
    AFFINEANIMCMD_FRAME(0, 0, -4, 3),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd sSpriteAffineAnim_8411EE8[] =
{
    AFFINEANIMCMD_FRAME(0x0, 0x0, 1, 16),
    AFFINEANIMCMD_FRAME(0x0, 0x0, -1, 32),
    AFFINEANIMCMD_FRAME(0x0, 0x0, 1, 16),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd sSpriteAffineAnim_8411F08[] =
{
    AFFINEANIMCMD_FRAME(-0x100, 0x100, 0, 0),
    AFFINEANIMCMD_FRAME(0x0, 0x0, 1, 16),
    AFFINEANIMCMD_FRAME(0x0, 0x0, -1, 32),
    AFFINEANIMCMD_FRAME(0x0, 0x0, 1, 16),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd sSpriteAffineAnim_8411F30[] =
{
    AFFINEANIMCMD_FRAME(0x0, 0x0, -1, 8),
    AFFINEANIMCMD_FRAME(0x0, 0x0, 0, 16),
    AFFINEANIMCMD_FRAME(0x0, 0x0, 1, 8),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd sSpriteAffineAnim_8411F50[] =
{
    AFFINEANIMCMD_FRAME(-0x100, 0x100, 0, 0),
    AFFINEANIMCMD_FRAME(0x0, 0x0, -1, 8),
    AFFINEANIMCMD_FRAME(0x0, 0x0, 0, 16),
    AFFINEANIMCMD_FRAME(0x0, 0x0, 1, 8),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd sSpriteAffineAnim_8411F78[] =
{
    AFFINEANIMCMD_FRAME(0x0, 0x0, -1, 8),
    AFFINEANIMCMD_FRAME(0x0, 0x0, 0, 32),
    AFFINEANIMCMD_FRAME(0x0, 0x0, 1, 8),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd sSpriteAffineAnim_8411F98[] =
{
    AFFINEANIMCMD_FRAME(-0x100, 0x100, 0, 0),
    AFFINEANIMCMD_FRAME(0x0, 0x0, -1, 8),
    AFFINEANIMCMD_FRAME(0x0, 0x0, 0, 32),
    AFFINEANIMCMD_FRAME(0x0, 0x0, 1, 8),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd sSpriteAffineAnim_8411FC0[] =
{
    AFFINEANIMCMD_FRAME(0x0, 0x0, -1, 4),
    AFFINEANIMCMD_FRAME(0x0, 0x0, 0, 24),
    AFFINEANIMCMD_FRAME(0x0, 0x0, 1, 4),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd sSpriteAffineAnim_8411FE0[] =
{
    AFFINEANIMCMD_FRAME(-0x100, 0x100, 0, 0),
    AFFINEANIMCMD_FRAME(0x0, 0x0, -1, 4),
    AFFINEANIMCMD_FRAME(0x0, 0x0, 0, 24),
    AFFINEANIMCMD_FRAME(0x0, 0x0, 1, 4),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd sSpriteAffineAnim_8412008[] =
{
    AFFINEANIMCMD_FRAME(0x0, 0x0, 1, 24),
    AFFINEANIMCMD_FRAME(0x0, 0x0, 0, 16),
    AFFINEANIMCMD_FRAME(0x0, 0x0, -12, 2),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd sSpriteAffineAnim_8412028[] =
{
    AFFINEANIMCMD_FRAME(-0x100, 0x100, 0, 0),
    AFFINEANIMCMD_FRAME(0x0, 0x0, 1, 24),
    AFFINEANIMCMD_FRAME(0x0, 0x0, 0, 16),
    AFFINEANIMCMD_FRAME(0x0, 0x0, -12, 2),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd *const sSpriteAffineAnimTable_85F04FC[] =
{
    sSpriteAffineAnim_8411E90,
    sSpriteAffineAnim_8411EA0,
    sSpriteAffineAnim_8411EE8,
    sSpriteAffineAnim_8411F30,
    sSpriteAffineAnim_8411F78,
    sSpriteAffineAnim_8411FC0,
    sSpriteAffineAnim_8412008,
    sSpriteAffineAnim_8411E90,
    sSpriteAffineAnim_8411E90,
    sSpriteAffineAnim_8411E90,
    sSpriteAffineAnim_8411E90,
    sSpriteAffineAnim_8411EC0,
    sSpriteAffineAnim_8411F08,
    sSpriteAffineAnim_8411F50,
    sSpriteAffineAnim_8411F98,
    sSpriteAffineAnim_8411FE0,
    sSpriteAffineAnim_8412028,
    sSpriteAffineAnim_8411E90,
    sSpriteAffineAnim_8411E90,
    sSpriteAffineAnim_8411E90,
    sSpriteAffineAnim_8411E90,
};

static const struct BgTemplate sBackgroundTemplates[] =
{
    {
        .bg = 0,
        .charBaseIndex = 0,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0
    },
    {
        .bg = 1,
        .charBaseIndex = 2,
        .mapBaseIndex = 30,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 3,
        .baseTile = 0
    }
};

static const struct WindowTemplate sWindowTemplates[] =
{
    {0, 1, 0xF, 0x1C, 4, 0xF, 0xA},
    DUMMY_WIN_TEMPLATE
};

// - 1 excludes PBLOCK_CLR_NONE
static const u32* const sPokeblocksPals[] =
{
    [PBLOCK_CLR_RED - 1]       = gPokeblockRed_Pal,
    [PBLOCK_CLR_BLUE - 1]      = gPokeblockBlue_Pal,
    [PBLOCK_CLR_PINK - 1]      = gPokeblockPink_Pal,
    [PBLOCK_CLR_GREEN - 1]     = gPokeblockGreen_Pal,
    [PBLOCK_CLR_YELLOW - 1]    = gPokeblockYellow_Pal,
    [PBLOCK_CLR_PURPLE - 1]    = gPokeblockPurple_Pal,
    [PBLOCK_CLR_INDIGO - 1]    = gPokeblockIndigo_Pal,
    [PBLOCK_CLR_BROWN - 1]     = gPokeblockBrown_Pal,
    [PBLOCK_CLR_LITE_BLUE - 1] = gPokeblockLiteBlue_Pal,
    [PBLOCK_CLR_OLIVE - 1]     = gPokeblockOlive_Pal,
    [PBLOCK_CLR_GRAY - 1]      = gPokeblockGray_Pal,
    [PBLOCK_CLR_BLACK - 1]     = gPokeblockBlack_Pal,
    [PBLOCK_CLR_WHITE - 1]     = gPokeblockWhite_Pal,
    [PBLOCK_CLR_GOLD - 1]      = gPokeblockGold_Pal
};

static const union AffineAnimCmd sSpriteAffineAnim_84120DC[] =
{
    AFFINEANIMCMD_FRAME(-0x100, 0x100, 0, 0),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd *const sSpriteAffineAnimTable_MonNoFlip[] =
{
    sSpriteAffineAnim_84120DC
};

static const union AffineAnimCmd sSpriteAffineAnim_84120F0[] =
{
    AFFINEANIMCMD_FRAME(-0x100, 0x100, 0, 0),
    AFFINEANIMCMD_FRAME(0x0, 0x0, -8, 1),
    AFFINEANIMCMD_FRAME(0x0, 0x0, -8, 1),
    AFFINEANIMCMD_FRAME(0x0, 0x0, -8, 1),
    AFFINEANIMCMD_FRAME(0x0, 0x0, -8, 1),
    AFFINEANIMCMD_FRAME(0x0, 0x0, 0, 8),
    AFFINEANIMCMD_FRAME(0x0, 0x0, 16, 1),
    AFFINEANIMCMD_FRAME(0x0, 0x0, 16, 1),
    AFFINEANIMCMD_FRAME(0x0, 0x0, 16, 1),
    AFFINEANIMCMD_FRAME(-0x100, 0x100, 0, 0),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd sSpriteAffineAnim_8412148[] =
{
    AFFINEANIMCMD_FRAME(-0x100, 0x100, 0, 0),
    AFFINEANIMCMD_FRAME(0x0, 0x0, 8, 1),
    AFFINEANIMCMD_FRAME(0x0, 0x0, 8, 1),
    AFFINEANIMCMD_FRAME(0x0, 0x0, 8, 1),
    AFFINEANIMCMD_FRAME(0x0, 0x0, 8, 1),
    AFFINEANIMCMD_FRAME(0x0, 0x0, 0, 8),
    AFFINEANIMCMD_FRAME(0x0, 0x0, -16, 1),
    AFFINEANIMCMD_FRAME(0x0, 0x0, -16, 1),
    AFFINEANIMCMD_FRAME(0x0, 0x0, -16, 1),
    AFFINEANIMCMD_FRAME(-0x100, 0x100, 0, 0),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd *const sSpriteAffineAnimTable_85F0664[] =
{
    sSpriteAffineAnim_84120DC
};

static const union AffineAnimCmd *const sSpriteAffineAnimTable_85F0668[] =
{
    sSpriteAffineAnim_84120F0
};

static const union AffineAnimCmd *const sSpriteAffineAnimTable_85F066C[] =
{
    sSpriteAffineAnim_8412148
};

static const struct OamData sThrownPokeblockOamData =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_DOUBLE,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = 0,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(8x8),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(8x8),
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0,
};

static const union AnimCmd sThrownPokeblockSpriteAnim[] =
{
    ANIMCMD_FRAME(0, 0),
    ANIMCMD_END
};

static const union AnimCmd *const sThrownPokeblockAnimTable[] =
{
    sThrownPokeblockSpriteAnim,
};

static const union AffineAnimCmd sSpriteAffineAnim_84121C0[] =
{
    AFFINEANIMCMD_FRAME(0x100, 0x100, 0, 0),
    AFFINEANIMCMD_FRAME(-8, -8, 0, 1),
    AFFINEANIMCMD_JUMP(1)
};

static const union AffineAnimCmd *const sThrownPokeblockAffineAnimTable[] =
{
    sSpriteAffineAnim_84121C0
};

static const struct CompressedSpriteSheet sPokeblock_SpriteSheet =
{
    gPokeblock_Gfx, 0x20, GFX_TAG_POKEBLOCK
};

static const struct SpriteTemplate sThrownPokeblockSpriteTemplate =
{
    .tileTag = GFX_TAG_POKEBLOCK,
    .paletteTag = GFX_TAG_POKEBLOCK,
    .oam = &sThrownPokeblockOamData,
    .anims = sThrownPokeblockAnimTable,
    .images = NULL,
    .affineAnims = sThrownPokeblockAffineAnimTable,
    .callback = SpriteCB_ThrownPokeblock
};

// code
static void CB2_PokeblockFeed(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    DoScheduledBgTilemapCopiesToVram();
    UpdatePaletteFade();
}

static void VBlankCB_PokeblockFeed(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static bool8 TransitionToPokeblockFeedScene(void)
{
    switch (gMain.state)
    {
    case 0:
        sPokeblockFeed = AllocZeroed(sizeof(*sPokeblockFeed));
        SetVBlankHBlankCallbacksToNull();
        ClearScheduledBgCopiesToVram();
        gMain.state++;
        break;
    case 1:
        ResetPaletteFade();
        gPaletteFade.bufferTransferDisabled = 1;
        gMain.state++;
        break;
    case 2:
        ResetSpriteData();
        gMain.state++;
        break;
    case 3:
        FreeAllSpritePalettes();
        gMain.state++;
        break;
    case 4:
        AllocateMonSpritesGfx();
        gMain.state++;
        break;
    case 5:
        HandleInitBackgrounds();
        gMain.state++;
        break;
    case 6:
        HandleInitWindows();
        gMain.state++;
        break;
    case 7:
        if (LoadMonAndSceneGfx(&gPlayerParty[gPokeblockMonId]))
        {
            gMain.state++;
        }
        break;
    case 8:
        sPokeblockFeed->pokeblockCaseSpriteId = CreatePokeblockCaseSpriteForFeeding();
        gMain.state++;
        break;
    case 9:
        sPokeblockFeed->monSpriteId = CreateMonSprite(&gPlayerParty[gPokeblockMonId]);
        gMain.state++;
        break;
    case 10:
        DrawStdFrameWithCustomTileAndPalette(0, 1, 1, 14);
        gMain.state++;
        break;
    case 11:
        LaunchPokeblockFeedTask();
        gMain.state++;
        break;
    case 12:
        BlendPalettes(-1, 0x10, 0);
        gMain.state++;
        break;
    case 13:
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0x10, 0, RGB_BLACK);
        gPaletteFade.bufferTransferDisabled = 0;
        gMain.state++;
        break;
    default:
        SetVBlankCallback(VBlankCB_PokeblockFeed);
        SetMainCallback2(CB2_PokeblockFeed);
        return TRUE;
    }
    return FALSE;
}

void CB2_PreparePokeblockFeedScene(void)
{
    while (1)
    {
        if (MenuHelpers_CallLinkSomething() == TRUE)
            break;
        if (TransitionToPokeblockFeedScene() == TRUE)
            break;
        if (MenuHelpers_LinkSomething() == TRUE)
            break;
    }
}

static void HandleInitBackgrounds(void)
{
    ResetVramOamAndBgCntRegs();

    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, sBackgroundTemplates, ARRAY_COUNT(sBackgroundTemplates));
    SetBgTilemapBuffer(1, sPokeblockFeed->tilemapBuffer);
    ResetAllBgsCoordinates();
    ScheduleBgCopyTilemapToVram(1);

    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);

    ShowBg(0);
    ShowBg(1);

    SetGpuReg(REG_OFFSET_BLDCNT, 0);
}

static bool8 LoadMonAndSceneGfx(struct Pokemon *mon)
{
    u16 species;
    u32 personality, trainerId;
    const struct CompressedSpritePalette *palette;

    switch (sPokeblockFeed->loadGfxState)
    {
    case 0:
        species = GetMonData(mon, MON_DATA_SPECIES2);
        personality = GetMonData(mon, MON_DATA_PERSONALITY);
        HandleLoadSpecialPokePic_2(&gMonFrontPicTable[species], gMonSpritesGfxPtr->sprites.ptr[1], species, personality);
        sPokeblockFeed->loadGfxState++;
        break;
    case 1:
        species = GetMonData(mon, MON_DATA_SPECIES2);
        personality = GetMonData(mon, MON_DATA_PERSONALITY);
        trainerId = GetMonData(mon, MON_DATA_OT_ID);
        palette = GetMonSpritePalStructFromOtIdPersonality(species, trainerId, personality);

        LoadCompressedSpritePalette(palette);
        SetMultiuseSpriteTemplateToPokemon(palette->tag, 1);
        sPokeblockFeed->loadGfxState++;
        break;
    case 2:
        LoadCompressedSpriteSheet(&gPokeblockCase_SpriteSheet);
        sPokeblockFeed->loadGfxState++;
        break;
    case 3:
        LoadCompressedSpritePalette(&gPokeblockCase_SpritePal);
        sPokeblockFeed->loadGfxState++;
        break;
    case 4:
        LoadCompressedSpriteSheet(&sPokeblock_SpriteSheet);
        sPokeblockFeed->loadGfxState++;
        break;
    case 5:
        SetPokeblockSpritePal(gSpecialVar_ItemId);
        LoadCompressedSpritePalette(&sPokeblockSpritePal);
        sPokeblockFeed->loadGfxState++;
        break;
    case 6:
        ResetTempTileDataBuffers();
        DecompressAndCopyTileDataToVram(1, gBattleTerrainTiles_Building, 0, 0, 0);
        sPokeblockFeed->loadGfxState++;
        break;
    case 7:
        if (FreeTempTileDataBuffersIfPossible() != TRUE)
        {
            LZDecompressWram(gUnknown_08D9BA44, sPokeblockFeed->tilemapBuffer);
            sPokeblockFeed->loadGfxState++;
        }
        break;
    case 8:
        LoadCompressedPalette(gBattleTerrainPalette_Frontier, 0x20, 0x60);
        sPokeblockFeed->loadGfxState = 0;
        return TRUE;
    }

    return FALSE;
}

static void HandleInitWindows(void)
{
    InitWindows(sWindowTemplates);
    DeactivateAllTextPrinters();
    LoadUserWindowBorderGfx(0, 1, 0xE0);
    LoadPalette(gUnknown_0860F074, 0xF0, 0x20);
    FillWindowPixelBuffer(0, PIXEL_FILL(0));
    PutWindowTilemap(0);
    ScheduleBgCopyTilemapToVram(0);
}

static void SetPokeblockSpritePal(u8 pokeblockCaseId)
{
    u8 colorId = GetPokeblockData(&gSaveBlock1Ptr->pokeblocks[pokeblockCaseId], PBLOCK_COLOR);
    sPokeblockSpritePal.data = sPokeblocksPals[colorId - 1];
    sPokeblockSpritePal.tag = GFX_TAG_POKEBLOCK;
}

// defines for task data fields

#define tFrames     data[0]
#define tData1      data[1]

static void Task_HandlePokeblockFeed(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        switch (gTasks[taskId].tFrames)
        {
        case 0:
            sPokeblockFeed->field_1050 = 0;
            sPokeblockFeed->field_1058 = 0;
            sub_817A5CC();
            break;
        case 255:
            DoPokeblockCaseThrowEffect(sPokeblockFeed->pokeblockCaseSpriteId, gTasks[taskId].tData1);
            break;
        case 269:
            sPokeblockFeed->pokeblockSpriteId = CreatePokeblockSprite();
            break;
        case 281:
            PrepareMonToMoveToPokeblock(sPokeblockFeed->monSpriteId);
            break;
        case 297:
            gTasks[taskId].func = Task_HandleMonAtePokeblock;
            return;
        }

        if (sPokeblockFeed->field_1058 < sPokeblockFeed->field_1056)
            sub_817A634();
        else if (sPokeblockFeed->field_1058 == sPokeblockFeed->field_1056)
            gTasks[taskId].tFrames = 254;

        sPokeblockFeed->field_1058++;
        gTasks[taskId].tFrames++;
    }
}

static void LaunchPokeblockFeedTask(void)
{
    u8 taskId = CreateTask(Task_HandlePokeblockFeed, 0);
    gTasks[taskId].tFrames = 0;
    gTasks[taskId].tData1 = 1;
}

static void Task_WaitForAtePokeblockText(u8 taskId)
{
    if (RunTextPrintersRetIsActive(0) != TRUE)
        gTasks[taskId].func = Task_PaletteFadeToReturn;
}

static void Task_HandleMonAtePokeblock(u8 taskId)
{
    struct Pokemon *mon = &gPlayerParty[gPokeblockMonId];
    struct Pokeblock *pokeblock = &gSaveBlock1Ptr->pokeblocks[gSpecialVar_ItemId];

    gPokeblockGain = PokeblockGetGain(GetNature(mon), pokeblock);
    GetMonNickname(mon, gStringVar1);
    PokeblockCopyName(pokeblock, gStringVar2);

    if (gPokeblockGain == 0)
        StringExpandPlaceholders(gStringVar4, gText_Var1AteTheVar2);
    else if (gPokeblockGain > 0)
        StringExpandPlaceholders(gStringVar4, gText_Var1HappilyAteVar2);
    else
        StringExpandPlaceholders(gStringVar4, gText_Var1DisdainfullyAteVar2);

    gTextFlags.canABSpeedUpPrint = 1;
    AddTextPrinterParameterized2(0, 1, gStringVar4, GetPlayerTextSpeedDelay(), NULL, 2, 1, 3);
    gTasks[taskId].func = Task_WaitForAtePokeblockText;
}

static void Task_ReturnAfterPaletteFade(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        ResetSpriteData();
        FreeAllSpritePalettes();
        m4aMPlayVolumeControl(&gMPlayInfo_BGM, -1, 0x100);
        SetMainCallback2(gMain.savedCallback);
        DestroyTask(taskId);
        FreeAllWindowBuffers();
        Free(sPokeblockFeed);
        FreeMonSpritesGfx();
    }
}

static void Task_PaletteFadeToReturn(u8 taskId)
{
    BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 0x10, RGB_BLACK);
    gTasks[taskId].func = Task_ReturnAfterPaletteFade;
}

#undef tFrames
#undef tData1

// defines for mon sprite data fields

#define tDelta          data[0]
#define tDeltaMod       data[1]
#define tSpecies        data[2]

static u8 CreateMonSprite(struct Pokemon* mon)
{
    u16 species = GetMonData(mon, MON_DATA_SPECIES2);
    u8 spriteId = CreateSprite(&gMultiuseSpriteTemplate, 48, 80, 2);

    sPokeblockFeed->species = species;
    sPokeblockFeed->monSpriteId_ = spriteId;
    sPokeblockFeed->nature = GetNature(mon);
    gSprites[spriteId].tSpecies = species;
    gSprites[spriteId].callback = SpriteCallbackDummy;

    sPokeblockFeed->noMonFlip = TRUE;
    if (!IsMonSpriteNotFlipped(species))
    {
        gSprites[spriteId].affineAnims = sSpriteAffineAnimTable_MonNoFlip;
        gSprites[spriteId].oam.affineMode = ST_OAM_AFFINE_DOUBLE;
        CalcCenterToCornerVec(&gSprites[spriteId], gSprites[spriteId].oam.shape, gSprites[spriteId].oam.size, gSprites[spriteId].oam.affineMode);
        sPokeblockFeed->noMonFlip = FALSE;
    }

    return spriteId;
}

static void PrepareMonToMoveToPokeblock(u8 spriteId)
{
    gSprites[spriteId].pos1.x = 48;
    gSprites[spriteId].pos1.y = 80;
    gSprites[spriteId].tDelta = -8;
    gSprites[spriteId].tDeltaMod = 1;
    gSprites[spriteId].callback = sub_817A468;
}

static void sub_817A468(struct Sprite* sprite)
{
    sprite->pos1.x += 4;
    sprite->pos1.y += sprite->tDelta;
    sprite->tDelta += sprite->tDeltaMod;

    if (sprite->tDelta == 0)
        PlayCry1(sprite->tSpecies, 0);
    if (sprite->tDelta == 9)
        sprite->callback = SpriteCallbackDummy;
}

#undef tDelta
#undef tDeltaMod
#undef tSpecies

static u8 CreatePokeblockCaseSpriteForFeeding(void)
{
    u8 spriteId = CreatePokeblockCaseSprite(188, 100, 2);
    gSprites[spriteId].oam.affineMode = ST_OAM_AFFINE_NORMAL;
    gSprites[spriteId].affineAnims = sSpriteAffineAnimTable_85F0664;
    gSprites[spriteId].callback = SpriteCallbackDummy;
    InitSpriteAffineAnim(&gSprites[spriteId]);
    return spriteId;
}

static void DoPokeblockCaseThrowEffect(u8 spriteId, bool8 a1)
{
    FreeOamMatrix(gSprites[spriteId].oam.matrixNum);
    gSprites[spriteId].oam.affineMode = ST_OAM_AFFINE_DOUBLE;

    if (!a1)
        gSprites[spriteId].affineAnims = sSpriteAffineAnimTable_85F0668;
    else
        gSprites[spriteId].affineAnims = sSpriteAffineAnimTable_85F066C;

    InitSpriteAffineAnim(&gSprites[spriteId]);
}

// defines for the pokeblock sprite data fields
#define tDelta          data[0]
#define tDeltaMod       data[1]

static u8 CreatePokeblockSprite(void)
{
    u8 spriteId = CreateSprite(&sThrownPokeblockSpriteTemplate, 174, 84, 1);
    gSprites[spriteId].tDelta = -12;
    gSprites[spriteId].tDeltaMod = 1;
    return spriteId;
}

static void SpriteCB_ThrownPokeblock(struct Sprite* sprite)
{
    sprite->pos1.x -= 4;
    sprite->pos1.y += sprite->tDelta;
    sprite->tDelta += sprite->tDeltaMod;
    if (sprite->tDelta == 10)
        DestroySprite(sprite);
}

#undef tDelta
#undef tDeltaMod

static void sub_817A5CC(void)
{
    u8 animId, i;
    struct PokeblockFeedStruct *pokeblockFeed;

    pokeblockFeed = sPokeblockFeed;
    pokeblockFeed->field_1056 = 1;
    animId = sNatureToMonPokeblockAnim[pokeblockFeed->nature][0];
    for (i = 0; i < 8; i++, animId++)
    {
        pokeblockFeed->field_1056 += sMonPokeblockAnims[animId][4];
        if (sMonPokeblockAnims[animId][9] == 1)
            break;
    }
}

static void sub_817A634(void)
{
    struct PokeblockFeedStruct *pokeblockFeed = sPokeblockFeed;

    switch (pokeblockFeed->field_1050)
    {
    case 0:
        pokeblockFeed->animId = sNatureToMonPokeblockAnim[pokeblockFeed->nature][0];
        pokeblockFeed->monSpritePtr = &gSprites[pokeblockFeed->monSpriteId_];
        pokeblockFeed->savedMonSprite = *pokeblockFeed->monSpritePtr;
        pokeblockFeed->field_1050 = 10;
        break;
    case 1 ... 9:
        break;
    case 10:
        sub_817A91C();
        if (sNatureToMonPokeblockAnim[pokeblockFeed->nature][1] != 0)
        {
            pokeblockFeed->monSpritePtr->oam.affineMode = ST_OAM_AFFINE_DOUBLE;
            pokeblockFeed->monSpritePtr->oam.matrixNum = 0;
            pokeblockFeed->monSpritePtr->affineAnims = sSpriteAffineAnimTable_85F04FC;
            InitSpriteAffineAnim(pokeblockFeed->monSpritePtr);
        }
        pokeblockFeed->field_1050 = 50;
    case 50:
        if (sNatureToMonPokeblockAnim[pokeblockFeed->nature][1] != 0)
        {
            if (!pokeblockFeed->noMonFlip) // double negation, so mon's sprite is flipped
                StartSpriteAffineAnim(pokeblockFeed->monSpritePtr, sNatureToMonPokeblockAnim[pokeblockFeed->nature][1] + 10);
            else
                StartSpriteAffineAnim(pokeblockFeed->monSpritePtr, sNatureToMonPokeblockAnim[pokeblockFeed->nature][1]);
        }
        pokeblockFeed->field_1050 = 60;
        break;
    case 60:
        if (sub_817A9E4() == TRUE)
        {
            if (pokeblockFeed->field_1060[9] == 0)
            {
                pokeblockFeed->animId++;
                sub_817A91C();
                pokeblockFeed->field_1050 = 60;
            }
            else
            {
                FreeOamMatrix(pokeblockFeed->monSpritePtr->oam.matrixNum);
                pokeblockFeed->field_1050 = 70;
            }
        }
        break;
    case 70:
        FreeMonSpriteOamMatrix();
        pokeblockFeed->animId = 0;
        pokeblockFeed->field_1050 = 0;
        break;
    case 71 ... 90:
        break;
    }
}

static bool8 sub_817A91C(void)
{
    struct PokeblockFeedStruct *pokeblockFeed = sPokeblockFeed;
    u8 i;

    for (i = 0; i < 10; i++)
        pokeblockFeed->field_1060[i] = sMonPokeblockAnims[pokeblockFeed->animId][i];

    if (pokeblockFeed->field_1060[4] == 0)
    {
        return TRUE;
    }
    else
    {
        pokeblockFeed->field_1060[10] = Sin(pokeblockFeed->field_1060[0], pokeblockFeed->field_1060[2]);
        pokeblockFeed->field_1060[11] = Cos(pokeblockFeed->field_1060[0], pokeblockFeed->field_1060[3]);
        pokeblockFeed->field_1060[12] = pokeblockFeed->field_1060[4];
        pokeblockFeed->field_1060[13] = pokeblockFeed->monSpritePtr->pos2.x;
        pokeblockFeed->field_1060[14] = pokeblockFeed->monSpritePtr->pos2.y;
        sub_817AB68();
        pokeblockFeed->field_1060[4] = pokeblockFeed->field_1060[12];
        sub_817AA54();
        pokeblockFeed->field_1060[4] = pokeblockFeed->field_1060[12];
        return FALSE;
    }
}

static bool8 sub_817A9E4(void)
{
    u16 var = sPokeblockFeed->field_1060[12] - sPokeblockFeed->field_1060[4];

    sPokeblockFeed->monSpritePtr->pos2.x = sPokeblockFeed->field_850[var];
    sPokeblockFeed->monSpritePtr->pos2.y = sPokeblockFeed->field_C50[var];

    if (--sPokeblockFeed->field_1060[4] == 0)
        return TRUE;
    else
        return FALSE;
}

static bool8 FreeMonSpriteOamMatrix(void)
{
    FreeSpriteOamMatrix(sPokeblockFeed->monSpritePtr);
    return FALSE;
}

static void sub_817AA54(void)
{
    struct PokeblockFeedStruct *pokeblockFeed = sPokeblockFeed;
    u16 i;
    u16 r8 = pokeblockFeed->field_1060[8];
    u16 r7 = pokeblockFeed->field_1060[12] - r8;
    s16 var3 = pokeblockFeed->field_1060[13] + pokeblockFeed->field_1060[6];
    s16 r9 = pokeblockFeed->field_1060[14] + pokeblockFeed->field_1060[7];

    for (i = 0; i < r7 - 1; i++)
    {
        s16 r1 = pokeblockFeed->field_850[r8 + i] - (var3);
        s16 r4 = pokeblockFeed->field_C50[r8 + i] - r9;

        pokeblockFeed->field_850[r8 + i] -= r1 * (i + 1) / r7;
        pokeblockFeed->field_C50[r8 + i] -= r4 * (i + 1) / r7;
    }

    pokeblockFeed->field_850[(r8 + r7) - 1] = var3;
    pokeblockFeed->field_C50[(r8 + r7) - 1] = r9;
}

static void sub_817AB68(void)
{
    struct PokeblockFeedStruct *pokeblockFeed = sPokeblockFeed;
    bool8 var_24 = FALSE;
    s16 r8 = pokeblockFeed->field_1060[13] - pokeblockFeed->field_1060[10];
    s16 r7 = pokeblockFeed->field_1060[14] - pokeblockFeed->field_1060[11];

    while (1)
    {
        u16 r5;
        u16 r4;
        u16 var;

        var = abs(pokeblockFeed->field_1060[5]);
        r5 = var + pokeblockFeed->field_1060[3];
        pokeblockFeed->field_1060[3] = r5;

        if (pokeblockFeed->field_1060[2] < 0)
            var_24 = TRUE;

        r4 = pokeblockFeed->field_1060[12] - pokeblockFeed->field_1060[4];

        if (pokeblockFeed->field_1060[4] == 0)
            break;

        if (!var_24)
        {
            pokeblockFeed->field_850[r4] = Sin(pokeblockFeed->field_1060[0], pokeblockFeed->field_1060[2] + r5 / 0x100) + r8;
            pokeblockFeed->field_C50[r4] = Cos(pokeblockFeed->field_1060[0], pokeblockFeed->field_1060[3] + r5 / 0x100) + r7;
        }
        else
        {
            pokeblockFeed->field_850[r4] = Sin(pokeblockFeed->field_1060[0], pokeblockFeed->field_1060[2] - r5 / 0x100) + r8;
            pokeblockFeed->field_C50[r4] = Cos(pokeblockFeed->field_1060[0], pokeblockFeed->field_1060[3] - r5 / 0x100) + r7;
        }

        pokeblockFeed->field_1060[0] += pokeblockFeed->field_1060[1];
        pokeblockFeed->field_1060[0] &= 0xFF;
        pokeblockFeed->field_1060[4]--;
    }
}
