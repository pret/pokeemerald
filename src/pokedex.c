#include "global.h"
#include "battle_main.h"
#include "bg.h"
#include "data.h"
#include "decompress.h"
#include "event_data.h"
#include "gpu_regs.h"
#include "graphics.h"
#include "international_string_util.h"
#include "main.h"
#include "alloc.h"
#include "menu.h"
#include "m4a.h"
#include "overworld.h"
#include "palette.h"
#include "pokedex.h"
#include "pokedex_area_screen.h"
#include "pokedex_cry_screen.h"
#include "scanline_effect.h"
#include "sound.h"
#include "sprite.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"
#include "text_window.h"
#include "trainer_pokemon_sprites.h"
#include "trig.h"
#include "window.h"
#include "constants/rgb.h"
#include "constants/songs.h"
#include "constants/species.h"

// EWRAM
static EWRAM_DATA struct PokedexView *sPokedexView = NULL;
static EWRAM_DATA u16 gUnknown_02039B50 = 0;
static EWRAM_DATA u8 gUnknown_02039B52 = 0;
static EWRAM_DATA struct PokedexListItem *sPokedexListItem = NULL;

// IWRAM common
// This is written to, but never read.
u8 gUnusedPokedexU8;
void (*gUnknown_030060B4)(void);

struct PokedexOption
{
    const u8 *description;
    const u8 *title;
};

struct UnknownStruct1
{
    const struct PokedexOption *pokedexList;
    u8 unk4;
    u8 unk5;
    u16 unk6;
};

struct UnknownStruct3
{
    const u8 *text;
    u8 unk4;
    u8 unk5;
    u8 unk6;
};

struct UnknownStruct4
{
    const u8 *text;
    u8 unk4;
    u8 unk5;
    u8 unk6;
    u8 unk7;
    u8 unk8;
    u8 unk9;
};

extern struct MusicPlayerInfo gMPlayInfo_BGM;

struct PokedexListItem
{
    u16 dexNum;
    u16 seen:1;
    u16 owned:1;
};

struct PokedexView
{
    struct PokedexListItem pokedexList[NATIONAL_DEX_COUNT];
    u16 unk608;
    u8 unk60A_1:1;
    u8 unk60A_2:1;
    u8 unk60B;
    u16 pokemonListCount;
    u16 selectedPokemon;
    u16 unk610;
    u16 dexMode;
    u16 unk614;
    u16 dexOrder;
    u16 unk618;
    u16 seenCount;
    u16 ownCount;
    u16 unk61E[4];
    u16 selectedMonSpriteId;
    u16 unk628;
    u16 unk62A;
    u8 unk62C;
    u8 initialVOffset;
    u8 unk62E;
    u8 unk62F;
    s16 unk630;
    s16 unk632;
    u16 unk634;
    u16 unk636;
    u16 unk638;
    u16 unk63A[4];
    u8 filler642[8];
    u8 unk64A;
    u8 unk64B;
    u8 unk64C_1:1;
    u8 selectedScreen;
    u8 unk64E;
    u8 menuIsOpen;      //menuIsOpen
    u16 menuCursorPos;     //Menu cursor position
    s16 menuY;     //Menu Y position (inverted because we use REG_BG0VOFS for this)
    u8 unk654[8];
    u8 unk65C[8];
};

enum
{
    AREA_SCREEN,
    CRY_SCREEN,
    SIZE_SCREEN,
    CANCEL_SCREEN,
};

// this file's functions
void sub_80BB774(void);
void sub_80BB78C(u8);
void sub_80BB7D4(u8);
void sub_80BBA28(u8);
void sub_80BBA78(u8);
void sub_80BBBF4(u8);
void sub_80BBC74(u8);
void sub_80BBD1C(u8);
void sub_80BBDE8(u8);
void sub_80BBE70(u8);
void sub_80BBEB8(u8);
void sub_80BC0A8(u8);
static void HandleButtonPress_StartMenu(u8);
void sub_80BC2D4(u8);
void sub_80BC360(u8);
void sub_80BC3DC(u8);
void sub_80BC47C(u8);
bool8 sub_80BC514(u8);
static void LoadPokedexBgPalette(u8);
void sub_80BC890(void);
void sub_80BC8D4(u8, u8);
static void CreateMonDexNum(u16, u8, u8, u16);
static void CreateCaughtBall(u16, u8, u8, u16);
static u8 CreateMonName(u16, u8, u8);
void sub_80BD28C(u8, u8, u16);
static void CreateInitialPokemonSprites(u16, u16);
bool8 sub_80BD404(u8, u8, u8);
u16 sub_80BD69C(u16, u16);
void sub_80BD8D0(void);
bool8 sub_80BD930(void);
u8 sub_80BDA40(void);
u16 GetPokemonSpriteToDisplay(u16);
u32 sub_80BDACC(u16, s16, s16);
static void CreateInterfaceSprites(u8);
void sub_80BE470(struct Sprite *sprite);
static void SpriteCB_Scrollbar(struct Sprite *sprite);
void sub_80BE658(struct Sprite *sprite);
void sub_80BE758(struct Sprite *sprite);
void sub_80BE780(struct Sprite *sprite);
void sub_80BE44C(struct Sprite *sprite);
void sub_80BE834(struct Sprite *sprite);
void sub_80BE4E0(struct Sprite *sprite);
u8 sub_80BE91C(struct PokedexListItem*, u8);
bool8 sub_80BE9C4(u8);
u8 sub_80BE9F8(struct PokedexListItem*, u8);
void sub_80BEA24(u8);
void sub_80BEDF4(u8);
void sub_80BEFD0(u8);
void sub_80BF038(u8);
void sub_80BF070(u8);
void sub_80BF0AC(u8);
void sub_80BF1B4(u8);
void sub_80BF1EC(u8);
void sub_80BF250(u8);
void sub_80BF5CC(u8);
void sub_80BF790(u8);
void sub_80BF7FC(u8);
void sub_80BF82C(u8);
void sub_80BFBB0(u8);
void sub_80BFC78(u8);
void sub_80BFCDC(u16);
void sub_80BFCF4(u16);
void sub_80BFD0C(u8, u16);
void sub_80BFD7C(u8, u16);
void sub_80BFE38(u8);
void sub_80C0088(u8);
void blockset_load_palette_to_gpu(u8);
void sub_80C01CC(struct Sprite *sprite);
void sub_80C020C(u32, u32, u32, u32);
void sub_80C0354(u16, u8, u8);
void sub_80C0460(u16 weight, u8 left, u8 top);
void sub_80C09B0(u16);
u8 sub_80C0B44(u8, u16, u8, u8);
void sub_80C0D30(u8, u16);
u16 sub_80C0EF8(u16, s16, s16, s8);
u16 sub_80C0E0C(u8, u16, u16, u16);
u8 sub_80C1258();
void sub_80C12E0(u8);
void sub_80C1570(u8);
void sub_80C15B0(u8);
void sub_80C16CC(u8);
void sub_80C170C(u8);
void sub_80C19A4(u8);
void sub_80C1A4C(u8);
void sub_80C1AB8(u8);
void sub_80C1B64(u8);
void sub_80C1BCC(u8);
void sub_80C1D38(u8);
void sub_80C1D70(u8);
void sub_80C2040(u8);
void sub_80C2064(u8, u8);
void sub_80C20F8(u8);
void sub_80C21D4(u8);
void sub_80C2294(u8);
u8 sub_80C2318(u8, u8);
void sub_80C23B8(u8);
void sub_80C2594(u8);
void sub_80C2618(const u8*);
void sub_80C2638(u32);
void sub_80C2650(u32);
void sub_80C2668(u32, const u8*);
void sub_80C267C(void);

// const rom data
#include "data/pokemon/pokedex_orders.h"

static const struct OamData sOamData_855CFE4 =
{
    .y = 160,
    .affineMode = 0,
    .objMode = 0,
    .mosaic = 0,
    .bpp = 0,
    .shape = SPRITE_SHAPE(8x8),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(8x8),
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0
};

static const struct OamData sOamData_855CFEC =
{
    .y = 160,
    .affineMode = 0,
    .objMode = 0,
    .mosaic = 0,
    .bpp = 0,
    .shape = SPRITE_SHAPE(16x8),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(16x8),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0
};

static const struct OamData sOamData_855CFF4 =
{
    .y = 160,
    .affineMode = 0,
    .objMode = 0,
    .mosaic = 0,
    .bpp = 0,
    .shape = SPRITE_SHAPE(32x16),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(32x16),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0
};

static const struct OamData sOamData_855CFFC =
{
    .y = 160,
    .affineMode = 0,
    .objMode = 2,
    .mosaic = 0,
    .bpp = 0,
    .shape = SPRITE_SHAPE(32x32),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(32x32),
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0
};

static const struct OamData sOamData_855D004 =
{
    .y = 160,
    .affineMode = 0,
    .objMode = 0,
    .mosaic = 0,
    .bpp = 0,
    .shape = SPRITE_SHAPE(64x32),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(64x32),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0
};

static const struct OamData sOamData_855D00C =
{
    .y = 160,
    .affineMode = 0,
    .objMode = 0,
    .mosaic = 0,
    .bpp = 0,
    .shape = SPRITE_SHAPE(8x16),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(8x16),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0
};

static const union AnimCmd sSpriteAnim_855D014[] =
{
    ANIMCMD_FRAME(3, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_855D01C[] =
{
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_855D024[] =
{
    ANIMCMD_FRAME(16, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_855D02C[] =
{
    ANIMCMD_FRAME(48, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_855D034[] =
{
    ANIMCMD_FRAME(40, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_855D03C[] =
{
    ANIMCMD_FRAME(32, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_855D044[] =
{
    ANIMCMD_FRAME(56, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_855D04C[] =
{
    ANIMCMD_FRAME(64, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_855D054[] =
{
    ANIMCMD_FRAME(96, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_855D05C[] =
{
    ANIMCMD_FRAME(160, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_855D064[] =
{
    ANIMCMD_FRAME(168, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_855D06C[] =
{
    ANIMCMD_FRAME(128, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_855D074[] =
{
    ANIMCMD_FRAME(130, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_855D07C[] =
{
    ANIMCMD_FRAME(132, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_855D084[] =
{
    ANIMCMD_FRAME(134, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_855D08C[] =
{
    ANIMCMD_FRAME(136, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_855D094[] =
{
    ANIMCMD_FRAME(138, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_855D09C[] =
{
    ANIMCMD_FRAME(140, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_855D0A4[] =
{
    ANIMCMD_FRAME(142, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_855D0AC[] =
{
    ANIMCMD_FRAME(144, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_855D0B4[] =
{
    ANIMCMD_FRAME(146, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_855D0BC[] =
{
    ANIMCMD_FRAME(176, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_855D0C4[] =
{
    ANIMCMD_FRAME(178, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_855D0CC[] =
{
    ANIMCMD_FRAME(180, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_855D0D4[] =
{
    ANIMCMD_FRAME(182, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_855D0DC[] =
{
    ANIMCMD_FRAME(184, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_855D0E4[] =
{
    ANIMCMD_FRAME(186, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_855D0EC[] =
{
    ANIMCMD_FRAME(188, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_855D0F4[] =
{
    ANIMCMD_FRAME(190, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_855D0FC[] =
{
    ANIMCMD_FRAME(192, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_855D104[] =
{
    ANIMCMD_FRAME(194, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_855D10C[] =
{
    ANIMCMD_FRAME(4, 30),
    ANIMCMD_END
};

static const union AnimCmd *const sSpriteAnimTable_855D114[] =
{
    sSpriteAnim_855D014
};

static const union AnimCmd *const sSpriteAnimTable_855D118[] =
{
    sSpriteAnim_855D01C
};

static const union AnimCmd *const sSpriteAnimTable_855D11C[] =
{
    sSpriteAnim_855D024
};

static const union AnimCmd *const sSpriteAnimTable_855D120[] =
{
    sSpriteAnim_855D02C,
    sSpriteAnim_855D034,
    sSpriteAnim_855D03C,
    sSpriteAnim_855D044
};

static const union AnimCmd *const sSpriteAnimTable_855D130[] =
{
    sSpriteAnim_855D04C,
    sSpriteAnim_855D054
};

static const union AnimCmd *const sSpriteAnimTable_855D138[] =
{
    sSpriteAnim_855D05C,
    sSpriteAnim_855D064
};

static const union AnimCmd *const sSpriteAnimTable_855D140[] =
{
    sSpriteAnim_855D06C,
    sSpriteAnim_855D074,
    sSpriteAnim_855D07C,
    sSpriteAnim_855D084,
    sSpriteAnim_855D08C,
    sSpriteAnim_855D094,
    sSpriteAnim_855D09C,
    sSpriteAnim_855D0A4,
    sSpriteAnim_855D0AC,
    sSpriteAnim_855D0B4
};

static const union AnimCmd *const sSpriteAnimTable_855D168[] =
{
    sSpriteAnim_855D0BC,
    sSpriteAnim_855D0C4,
    sSpriteAnim_855D0CC,
    sSpriteAnim_855D0D4,
    sSpriteAnim_855D0DC,
    sSpriteAnim_855D0E4,
    sSpriteAnim_855D0EC,
    sSpriteAnim_855D0F4,
    sSpriteAnim_855D0FC,
    sSpriteAnim_855D104
};

static const union AnimCmd *const sSpriteAnimTable_855D190[] =
{
    sSpriteAnim_855D10C
};

static const struct SpriteTemplate sScrollBarSpriteTemplate =
{
    .tileTag = 4096,
    .paletteTag = 4096,
    .oam = &sOamData_855CFE4,
    .anims = sSpriteAnimTable_855D114,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_Scrollbar,
};

static const struct SpriteTemplate sArrowSpriteTemplate =
{
    .tileTag = 4096,
    .paletteTag = 4096,
    .oam = &sOamData_855CFEC,
    .anims = sSpriteAnimTable_855D118,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_80BE658,
};

static const struct SpriteTemplate sInterfaceTextSpriteTemplate =
{
    .tileTag = 4096,
    .paletteTag = 4096,
    .oam = &sOamData_855CFF4,
    .anims = sSpriteAnimTable_855D120,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_80BE758,
};

static const struct SpriteTemplate sRotatingPokeballSpriteTemplate =
{
    .tileTag = 4096,
    .paletteTag = 4096,
    .oam = &sOamData_855CFFC,
    .anims = sSpriteAnimTable_855D11C,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_80BE780,
};

static const struct SpriteTemplate sSeenOwnTextSpriteTemplate =
{
    .tileTag = 4096,
    .paletteTag = 4096,
    .oam = &sOamData_855D004,
    .anims = sSpriteAnimTable_855D130,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_80BE44C,
};

static const struct SpriteTemplate gUnknown_0855D20C =
{
    .tileTag = 4096,
    .paletteTag = 4096,
    .oam = &sOamData_855CFF4,
    .anims = sSpriteAnimTable_855D138,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_80BE44C,
};

static const struct SpriteTemplate gUnknown_0855D224 =
{
    .tileTag = 4096,
    .paletteTag = 4096,
    .oam = &sOamData_855D00C,
    .anims = sSpriteAnimTable_855D140,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_80BE44C,
};

static const struct SpriteTemplate gUnknown_0855D23C =
{
    .tileTag = 4096,
    .paletteTag = 4096,
    .oam = &sOamData_855D00C,
    .anims = sSpriteAnimTable_855D168,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_80BE44C,
};

static const struct SpriteTemplate gUnknown_0855D254 =
{
    .tileTag = 4096,
    .paletteTag = 4096,
    .oam = &sOamData_855D00C,
    .anims = sSpriteAnimTable_855D190,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_80BE834,
};

static const struct CompressedSpriteSheet sInterfaceSpriteSheet[] =
{
    {gPokedexMenu2_Gfx, 0x2000, 4096},
    {0}
};

static const struct SpritePalette sInterfaceSpritePalette[] =
{
    {gPokedexText_Pal, 4096},
    {0}
};

static const u8 gUnknown_0855D28C[] = {0x4, 0x8, 0x10, 0x20, 0x20};
static const u8 gUnknown_0855D291[] = {0x8, 0x4, 0x2, 0x1, 0x1};

static const struct BgTemplate gBgTemplates_0855D298[] =
{
    {
        .bg = 0,
        .charBaseIndex = 0,
        .mapBaseIndex = 12,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0
    },
    {
        .bg = 1,
        .charBaseIndex = 0,
        .mapBaseIndex = 13,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0
    },
    {
        .bg = 2,
        .charBaseIndex = 2,
        .mapBaseIndex = 14,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 0
    },
    {
        .bg = 3,
        .charBaseIndex = 0,
        .mapBaseIndex = 15,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 3,
        .baseTile = 0
    }
};

static const struct WindowTemplate sPokemonList_WindowTemplate[] =
{
    {
        .bg = 2,
        .tilemapLeft = 0,
        .tilemapTop = 0,
        .width = 32,
        .height = 32,
        .paletteNum = 0,
        .baseBlock = 1,
    },
    DUMMY_WIN_TEMPLATE
};

static const u8 sText_No000[] = _("{NO}000");
static const u8 gUnknown_0855D2BE[] = INCBIN_U8("graphics/pokedex/caught_ball.4bpp");
static const u8 sText_TenDashes[] = _("----------");

ALIGNED(4) static const u8 gExpandedPlaceholder_PokedexDescription[] = _("");

#include "data/pokemon/pokedex_text.h"
#include "data/pokemon/pokedex_entries.h"

static const u16 gUnknown_0856E610[] = INCBIN_U16("graphics/pokedex/black.gbapal");

static const struct BgTemplate gUnknown_0856E630[] =
{
    {
        .bg = 0,
        .charBaseIndex = 2,
        .mapBaseIndex = 12,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 3,
        .baseTile = 0
    },
    {
        .bg = 1,
        .charBaseIndex = 0,
        .mapBaseIndex = 13,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0
    },
    {
        .bg = 2,
        .charBaseIndex = 2,
        .mapBaseIndex = 14,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0
    },
    {
        .bg = 3,
        .charBaseIndex = 0,
        .mapBaseIndex = 15,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 0
    }
};

static const struct WindowTemplate gUnknown_0856E640[] =
{
    {
        .bg = 2,
        .tilemapLeft = 0,
        .tilemapTop = 0,
        .width = 32,
        .height = 20,
        .paletteNum = 0,
        .baseBlock = 0x0001,
    },
    {
        .bg = 2,
        .tilemapLeft = 25,
        .tilemapTop = 8,
        .width = 2,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 0x0281,
    },
    {
        .bg = 0,
        .tilemapLeft = 0,
        .tilemapTop = 12,
        .width = 32,
        .height = 7,
        .paletteNum = 8,
        .baseBlock = 0x0285,
    },
    {
        .bg = 2,
        .tilemapLeft = 18,
        .tilemapTop = 3,
        .width = 10,
        .height = 8,
        .paletteNum = 9,
        .baseBlock = 0x0365,
    },
    DUMMY_WIN_TEMPLATE
};

static const struct BgTemplate gUnknown_0856E668[] =
{
    {
        .bg = 2,
        .charBaseIndex = 2,
        .mapBaseIndex = 14,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 0
    },
    {
        .bg = 3,
        .charBaseIndex = 1,
        .mapBaseIndex = 15,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 3,
        .baseTile = 0
    },
};

static const struct WindowTemplate gUnknown_0856E670[] =
{
    {
        .bg = 2,
        .tilemapLeft = 0,
        .tilemapTop = 0,
        .width = 32,
        .height = 20,
        .paletteNum = 0,
        .baseBlock = 0x0001,
    },
    {
        .bg = 2,
        .tilemapLeft = 25,
        .tilemapTop = 8,
        .width = 2,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 0x0281,
    },
    DUMMY_WIN_TEMPLATE
};

static const u8 sText_TenDashes2[] = _("----------");

#include "data/pokemon_graphics/footprint_table.h"

static const u8 gUnknown_0856ED08[][4] =
{
    {0x00, 0x00, 0x00, 0x00},
    {0xbb, 0x03, 0xd5, 0x03},
    {0xbe, 0x03, 0xd8, 0x03},
    {0xc1, 0x03, 0xdb, 0x03},
    {0xc4, 0x03, 0xde, 0x03},
    {0xc7, 0x03, 0xe1, 0x03},
    {0xca, 0x03, 0xe4, 0x03},
    {0xcd, 0x03, 0xe7, 0x03},
    {0xd0, 0x03, 0xea, 0x03},
    {0xd3, 0x02, 0xed, 0x02},
};

static const struct UnknownStruct3 gUnknown_0856ED30[] =
{
    {
        .text = gUnknown_085E87A5,
        .unk4 = 0,
        .unk5 = 0,
        .unk6 = 5,
    },
    {
        .text = gUnknown_085E87D6,
        .unk4 = 6,
        .unk5 = 0,
        .unk6 = 5,
    },
    {
        .text = gUnknown_085E87EF,
        .unk4 = 12,
        .unk5 = 0,
        .unk6 = 5,
    },
};

static const struct UnknownStruct4 gUnknown_0856ED48[] =
{
    {
        .text = gUnknown_085E8840,
        .unk4 = 0,
        .unk5 = 2,
        .unk6 = 5,
        .unk7 = 5,
        .unk8 = 2,
        .unk9 = 12,
    },
    {
        .text = gUnknown_085E887C,
        .unk4 = 0,
        .unk5 = 4,
        .unk6 = 5,
        .unk7 = 5,
        .unk8 = 4,
        .unk9 = 12,
    },
    {
        .text = gUnknown_085E88A6,
        .unk4 = 0,
        .unk5 = 6,
        .unk6 = 5,
        .unk7 = 5,
        .unk8 = 6,
        .unk9 = 6,
    },
    {
        .text = gUnknown_085E88A6,
        .unk4 = 0,
        .unk5 = 6,
        .unk6 = 5,
        .unk7 = 11,
        .unk8 = 6,
        .unk9 = 6,
    },
    {
        .text = gUnknown_085E881F,
        .unk4 = 0,
        .unk5 = 8,
        .unk6 = 5,
        .unk7 = 5,
        .unk8 = 8,
        .unk9 = 12,
    },
    {
        .text = gUnknown_085E8806,
        .unk4 = 0,
        .unk5 = 10,
        .unk6 = 5,
        .unk7 = 5,
        .unk8 = 10,
        .unk9 = 12,
    },
    {
        .text = gUnknown_085E88C8,
        .unk4 = 0,
        .unk5 = 12,
        .unk6 = 5,
        .unk7 = 0,
        .unk8 = 0,
        .unk9 = 0,
    },
};

static const u8 gUnknown_0856ED9C[][4] =
{
    {0xFF, 0xFF, 0xFF,    1},
    {0xFF, 0xFF,    0,    2},
    {0xFF,    3,    1,    4},
    {   2, 0xFF,    1,    4},
    {0xFF, 0xFF,    2,    5},
    {0xFF, 0xFF,    4,    6},
    {0xFF, 0xFF,    5, 0xFF},
};

static const u8 gUnknown_0856EDB8[][4] =
{
    {0xFF, 0xFF, 0xFF, 0xFF},
    {0xFF, 0xFF, 0xFF, 0xFF},
    {0xFF, 0xFF, 0xFF, 0xFF},
    {0xFF, 0xFF, 0xFF, 0xFF},
    {0xFF, 0xFF, 0xFF,    5},
    {0xFF, 0xFF,    4,    6},
    {0xFF, 0xFF,    5, 0xFF},
};

static const u8 gUnknown_0856EDD4[][4] =
{
    {0xFF, 0xFF, 0xFF,    1},
    {0xFF, 0xFF,    0,    2},
    {0xFF,    3,    1,    4},
    {   2, 0xFF,    1,    4},
    {0xFF, 0xFF,    2,    6},
    {0xFF, 0xFF, 0xFF, 0xFF},
    {0xFF, 0xFF,    4, 0xFF},
};

static const u8 gUnknown_0856EDF0[][4] =
{
    {0xFF, 0xFF, 0xFF, 0xFF},
    {0xFF, 0xFF, 0xFF, 0xFF},
    {0xFF, 0xFF, 0xFF, 0xFF},
    {0xFF, 0xFF, 0xFF, 0xFF},
    {0xFF, 0xFF, 0xFF,    6},
    {0xFF, 0xFF, 0xFF, 0xFF},
    {0xFF, 0xFF,    4, 0xFF},
};

static const struct PokedexOption gDexModeOptions[] =
{
    {gText_DexHoennDescription, gText_DexHoennTitle},
    {gText_DexNatDescription, gText_DexNatTitle},
    {NULL, NULL},
};

static const struct PokedexOption gDexSortOptions[] =
{
    {gText_DexSortNumericalDescription, gText_DexSortNumericalTitle},
    {gText_DexSortAtoZDescription, gText_DexSortAtoZTitle},
    {gText_DexSortHeaviestDescription, gText_DexSortHeaviestTitle},
    {gText_DexSortLightestDescription, gText_DexSortLightestTitle},
    {gText_DexSortTallestDescription, gText_DexSortTallestTitle},
    {gText_DexSortSmallestDescription, gText_DexSortSmallestTitle},
    {NULL, NULL},
};

static const struct PokedexOption gDexSearchAlphaOptions[] =
{
    {gText_DexEmptyString, gText_DexSearchDontSpecify},
    {gText_DexEmptyString, gText_DexSearchAlphaABC},
    {gText_DexEmptyString, gText_DexSearchAlphaDEF},
    {gText_DexEmptyString, gText_DexSearchAlphaGHI},
    {gText_DexEmptyString, gText_DexSearchAlphaJKL},
    {gText_DexEmptyString, gText_DexSearchAlphaMNO},
    {gText_DexEmptyString, gText_DexSearchAlphaPQR},
    {gText_DexEmptyString, gText_DexSearchAlphaSTU},
    {gText_DexEmptyString, gText_DexSearchAlphaVWX},
    {gText_DexEmptyString, gText_DexSearchAlphaYZ},
    {NULL, NULL},
};

static const struct PokedexOption gDexSearchColorOptions[] =
{
    {gText_DexEmptyString, gText_DexSearchDontSpecify},
    {gText_DexEmptyString, gText_DexSearchColorRed},
    {gText_DexEmptyString, gText_DexSearchColorBlue},
    {gText_DexEmptyString, gText_DexSearchColorYellow},
    {gText_DexEmptyString, gText_DexSearchColorGreen},
    {gText_DexEmptyString, gText_DexSearchColorBlack},
    {gText_DexEmptyString, gText_DexSearchColorBrown},
    {gText_DexEmptyString, gText_DexSearchColorPurple},
    {gText_DexEmptyString, gText_DexSearchColorGray},
    {gText_DexEmptyString, gText_DexSearchColorWhite},
    {gText_DexEmptyString, gText_DexSearchColorPink},
    {NULL, NULL},
};

static const struct PokedexOption gDexSearchTypeOptions[] =
{
    {gText_DexEmptyString, gText_DexSearchTypeNone},
    {gText_DexEmptyString, gTypeNames[TYPE_NORMAL]},
    {gText_DexEmptyString, gTypeNames[TYPE_FIGHTING]},
    {gText_DexEmptyString, gTypeNames[TYPE_FLYING]},
    {gText_DexEmptyString, gTypeNames[TYPE_POISON]},
    {gText_DexEmptyString, gTypeNames[TYPE_GROUND]},
    {gText_DexEmptyString, gTypeNames[TYPE_ROCK]},
    {gText_DexEmptyString, gTypeNames[TYPE_BUG]},
    {gText_DexEmptyString, gTypeNames[TYPE_GHOST]},
    {gText_DexEmptyString, gTypeNames[TYPE_STEEL]},
    {gText_DexEmptyString, gTypeNames[TYPE_FIRE]},
    {gText_DexEmptyString, gTypeNames[TYPE_WATER]},
    {gText_DexEmptyString, gTypeNames[TYPE_GRASS]},
    {gText_DexEmptyString, gTypeNames[TYPE_ELECTRIC]},
    {gText_DexEmptyString, gTypeNames[TYPE_PSYCHIC]},
    {gText_DexEmptyString, gTypeNames[TYPE_ICE]},
    {gText_DexEmptyString, gTypeNames[TYPE_DRAGON]},
    {gText_DexEmptyString, gTypeNames[TYPE_DARK]},
    {NULL, NULL},
};

static const u8 gUnknown_0856EFAC[] = {0x00, 0x01};
static const u8 gUnknown_0856EFAE[] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05};
static const u8 gDexSearchTypeIds[] = {
    TYPE_NONE,
    TYPE_NORMAL,
    TYPE_FIGHTING,
    TYPE_FLYING,
    TYPE_POISON,
    TYPE_GROUND,
    TYPE_ROCK,
    TYPE_BUG,
    TYPE_GHOST,
    TYPE_STEEL,
    TYPE_FIRE,
    TYPE_WATER,
    TYPE_GRASS,
    TYPE_ELECTRIC,
    TYPE_PSYCHIC,
    TYPE_ICE,
    TYPE_DRAGON,
    TYPE_DARK,
};

static const struct UnknownStruct1 gUnknown_0856EFC8[] =
{
    {gDexSearchAlphaOptions, 6, 7, 10},
    {gDexSearchColorOptions, 8, 9, 11},
    {gDexSearchTypeOptions, 10, 11, NUMBER_OF_MON_TYPES},
    {gDexSearchTypeOptions, 12, 13, NUMBER_OF_MON_TYPES},
    {gDexSortOptions, 4, 5, 6},
    {gDexModeOptions, 2, 3, 2},
};

static const struct BgTemplate gUnknown_0856EFF8[] =
{
    {
        .bg = 0,
        .charBaseIndex = 2,
        .mapBaseIndex = 12,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0
    },
    {
        .bg = 1,
        .charBaseIndex = 0,
        .mapBaseIndex = 13,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0
    },
    {
        .bg = 2,
        .charBaseIndex = 2,
        .mapBaseIndex = 14,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 0
    },
    {
        .bg = 3,
        .charBaseIndex = 0,
        .mapBaseIndex = 15,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 3,
        .baseTile = 0
    }
};

static const struct WindowTemplate gUnknown_0856F008[] =
{
    {
        .bg = 2,
        .tilemapLeft = 0,
        .tilemapTop = 0,
        .width = 32,
        .height = 20,
        .paletteNum = 0,
        .baseBlock = 0x0001,
    },
    DUMMY_WIN_TEMPLATE
};

// .text

void ResetPokedex(void)
{
    u16 i;

    gUnknown_02039B50 = 0;
    gUnknown_02039B52 = 64;
    gUnusedPokedexU8 = 0;
    gSaveBlock2Ptr->pokedex.mode = DEX_MODE_HOENN;
    gSaveBlock2Ptr->pokedex.order = 0;
    gSaveBlock2Ptr->pokedex.nationalMagic = 0;
    gSaveBlock2Ptr->pokedex.unknown2 = 0;
    gSaveBlock2Ptr->pokedex.unownPersonality = 0;
    gSaveBlock2Ptr->pokedex.spindaPersonality = 0;
    gSaveBlock2Ptr->pokedex.unknown3 = 0;
    DisableNationalPokedex();
    for (i = 0; i < DEX_FLAGS_NO; i++)
    {
        gSaveBlock1Ptr->dexCaught[i] = 0;
        gSaveBlock1Ptr->dexSeen[i] = 0;
    }
}

void ResetPokedexScrollPositions(void)
{
    gUnknown_02039B50 = 0;
    gUnknown_02039B52 = 64;
}

void sub_80BB370(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static void ResetPokedexView(struct PokedexView *pokedexView)
{
    u16 i;

    for (i = 0; i < NATIONAL_DEX_COUNT; i++)
    {
        pokedexView->pokedexList[i].dexNum = 0xFFFF;
        pokedexView->pokedexList[i].seen = 0;
        pokedexView->pokedexList[i].owned = 0;
    }
    pokedexView->unk608 = 0;
    pokedexView->unk60A_1 = 0;
    pokedexView->unk60A_2 = 0;
    pokedexView->pokemonListCount = 0;
    pokedexView->selectedPokemon = 0;
    pokedexView->unk610 = 0;
    pokedexView->dexMode = 0;
    pokedexView->unk614 = 0;
    pokedexView->dexOrder = 0;
    pokedexView->unk618 = 0;
    pokedexView->seenCount = 0;
    pokedexView->ownCount = 0;
    for (i = 0; i < 4; i++)
        pokedexView->unk61E[i] = 0xFFFF;
    pokedexView->unk628 = 0;
    pokedexView->unk62A = 0;
    pokedexView->unk62C = 0;
    pokedexView->initialVOffset = 0;
    pokedexView->unk62E = 0;
    pokedexView->unk62F = 0;
    pokedexView->unk630 = 0;
    pokedexView->unk632 = 0;
    pokedexView->unk634 = 0;
    pokedexView->unk636 = 0;
    pokedexView->unk638 = 0;
    for (i = 0; i <= 3; i++)
        pokedexView->unk63A[i] = 0;
    pokedexView->unk64A = 0;
    pokedexView->unk64B = 0;
    pokedexView->unk64C_1 = 0;
    pokedexView->selectedScreen = 0;
    pokedexView->unk64E = 0;
    pokedexView->menuIsOpen = 0;
    pokedexView->menuCursorPos = 0;
    pokedexView->menuY = 0;
    for (i = 0; i <= 7; i++)
        pokedexView->unk654[i] = 0;
    for (i = 0; i <= 7; i++)
        pokedexView->unk65C[i] = 0;
}

void CB2_Pokedex(void)
{
    u8 *addr;
    u32 size;

    switch (gMain.state)
    {
        case 0:
        default:
            SetVBlankCallback(NULL);
            sub_80C09B0(0);
            DmaFillLarge16(3, 0, (u8 *)VRAM, VRAM_SIZE, 0x1000)
            DmaClear32(3, OAM, OAM_SIZE);
            DmaClear16(3, PLTT, PLTT_SIZE);
            gMain.state = 1;
            break;
        case 1:
            ScanlineEffect_Stop();
            ResetTasks();
            ResetSpriteData();
            ResetPaletteFade();
            FreeAllSpritePalettes();
            gReservedSpritePaletteCount = 8;
            ResetAllPicSprites();
            gMain.state++;
            break;
        case 2:
            sPokedexView = AllocZeroed(sizeof(struct PokedexView));
            ResetPokedexView(sPokedexView);
            CreateTask(sub_80BB78C, 0);
            sPokedexView->dexMode = gSaveBlock2Ptr->pokedex.mode;
            if (!IsNationalPokedexEnabled())
                sPokedexView->dexMode = DEX_MODE_HOENN;
            sPokedexView->dexOrder = gSaveBlock2Ptr->pokedex.order;
            sPokedexView->selectedPokemon = gUnknown_02039B50;
            sPokedexView->unk62C = gUnknown_02039B52;
            sPokedexView->selectedScreen = 0;
            if (!IsNationalPokedexEnabled())
            {
                sPokedexView->seenCount = GetHoennPokedexCount(0);
                sPokedexView->ownCount = GetHoennPokedexCount(1);
            }
            else
            {
                sPokedexView->seenCount = GetNationalPokedexCount(0);
                sPokedexView->ownCount = GetNationalPokedexCount(1);
            }
            sPokedexView->initialVOffset = 8;
            gMain.state++;
            break;
        case 3:
            EnableInterrupts(1);
            SetVBlankCallback(sub_80BB370);
            SetMainCallback2(sub_80BB774);
            sub_80BC8D4(sPokedexView->dexMode, sPokedexView->dexOrder);
            m4aMPlayVolumeControl(&gMPlayInfo_BGM, 0xFFFF, 0x80);
            break;
    }
}

void sub_80BB774(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

void sub_80BB78C(u8 taskId)
{
    sPokedexView->unk64C_1 = FALSE;
    if (sub_80BC514(0))
        gTasks[taskId].func = sub_80BB7D4;
}

void sub_80BB7D4(u8 taskId)
{
    SetGpuReg(REG_OFFSET_BG0VOFS, sPokedexView->menuY);

    if (sPokedexView->menuY)
    {
        sPokedexView->menuY -= 8;
    }
    else
    {
        if ((gMain.newKeys & A_BUTTON) && sPokedexView->pokedexList[sPokedexView->selectedPokemon].seen)
        {
            sub_80BD8D0();
            BeginNormalPaletteFade(~(1 << (gSprites[sPokedexView->selectedMonSpriteId].oam.paletteNum + 16)), 0, 0, 0x10, RGB_BLACK);
            gSprites[sPokedexView->selectedMonSpriteId].callback = sub_80BE470;
            gTasks[taskId].func = sub_80BBBF4;
            PlaySE(SE_PIN);
            sub_80BC890();
        }
        else if (gMain.newKeys & START_BUTTON)
        {
            //Open menu
            sPokedexView->menuY = 0;
            sPokedexView->menuIsOpen = 1;
            sPokedexView->menuCursorPos = 0;
            gTasks[taskId].func = sub_80BBA78;
            PlaySE(SE_SELECT);
        }
        else if (gMain.newKeys & SELECT_BUTTON)
        {
            PlaySE(SE_SELECT);
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 0x10, RGB_BLACK);
            gTasks[taskId].data[0] = sub_80C1258();
            sPokedexView->unk64E = 0;
            sPokedexView->unk62A = sPokedexView->unk62C;
            sPokedexView->unk610 = sPokedexView->selectedPokemon;
            sPokedexView->unk614 = sPokedexView->dexMode;
            sPokedexView->unk618 = sPokedexView->dexOrder;
            gTasks[taskId].func = sub_80BBD1C;
            PlaySE(SE_PC_LOGIN);
            sub_80BC890();
        }
        else if (gMain.newKeys & B_BUTTON)
        {
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 0x10, RGB_BLACK);
            gTasks[taskId].func = sub_80BBDE8;
            PlaySE(SE_PC_OFF);
        }
        else
        {
            //Handle D-pad
            sPokedexView->selectedPokemon = sub_80BD69C(sPokedexView->selectedPokemon, 0xE);
            if (sPokedexView->unk62E)
                gTasks[taskId].func = sub_80BBA28;
        }
    }
}

void sub_80BBA28(u8 taskId)
{
    if (sub_80BD404(sPokedexView->unk62F, sPokedexView->unk634, sPokedexView->unk636))
        gTasks[taskId].func = sub_80BB7D4;
}

void sub_80BBA78(u8 taskId)
{
    SetGpuReg(REG_OFFSET_BG0VOFS, sPokedexView->menuY);

    //If menu is not open, slide it up, on screen
    if (sPokedexView->menuY != 80)
    {
        sPokedexView->menuY += 8;
    }
    else
    {
        if (gMain.newKeys & A_BUTTON)
        {
            switch (sPokedexView->menuCursorPos)
            {
                case 0: //BACK TO LIST
                default:
                    gMain.newKeys |= START_BUTTON;  //Exit menu
                    break;
                case 1: //LIST TOP
                    sPokedexView->selectedPokemon = 0;
                    sPokedexView->unk62C = 0x40;
                    sub_80BDA40();
                    CreateInitialPokemonSprites(sPokedexView->selectedPokemon, 0xE);
                    gMain.newKeys |= START_BUTTON;  //Exit menu
                    break;
                case 2: //LIST BOTTOM
                    sPokedexView->selectedPokemon = sPokedexView->pokemonListCount - 1;
                    sPokedexView->unk62C = sPokedexView->pokemonListCount * 16 + 0x30;
                    sub_80BDA40();
                    CreateInitialPokemonSprites(sPokedexView->selectedPokemon, 0xE);
                    gMain.newKeys |= START_BUTTON;  //Exit menu
                    break;
                case 3: //CLOSE POKEDEX
                    BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 0x10, RGB_BLACK);
                    gTasks[taskId].func = sub_80BBDE8;
                    PlaySE(SE_PC_OFF);
                    break;
            }
        }

        //Exit menu when Start or B is pressed
        if (gMain.newKeys & (START_BUTTON | B_BUTTON))
        {
            sPokedexView->menuIsOpen = 0;
            gTasks[taskId].func = sub_80BB7D4;
            PlaySE(SE_SELECT);
        }
        else if ((gMain.newAndRepeatedKeys & DPAD_UP) && sPokedexView->menuCursorPos != 0)
        {
            sPokedexView->menuCursorPos--;
            PlaySE(SE_SELECT);
        }
        else if ((gMain.newAndRepeatedKeys & DPAD_DOWN) && sPokedexView->menuCursorPos <= 2)
        {
            sPokedexView->menuCursorPos++;
            PlaySE(SE_SELECT);
        }
    }
}

void sub_80BBBF4(u8 taskId)
{
    if (gSprites[sPokedexView->selectedMonSpriteId].pos1.x == 48 && gSprites[sPokedexView->selectedMonSpriteId].pos1.y == 56)
    {
        sPokedexView->unk64B = sPokedexView->unk64A;
        gTasks[taskId].data[0] = sub_80BE91C(&sPokedexView->pokedexList[sPokedexView->selectedPokemon], sPokedexView->selectedMonSpriteId);
        gTasks[taskId].func = sub_80BBC74;
    }
}

void sub_80BBC74(u8 taskId)
{
    if (gTasks[gTasks[taskId].data[0]].isActive)
    {
        if (sPokedexView->unk64A == 1 && !sub_80BE9C4(gTasks[taskId].data[0]) && sub_80BD930())
            sub_80BE9F8(&sPokedexView->pokedexList[sPokedexView->selectedPokemon], gTasks[taskId].data[0]);
    }
    else
    {
        gUnknown_02039B50 = sPokedexView->selectedPokemon;
        gUnknown_02039B52 = sPokedexView->unk62C;
        gTasks[taskId].func = sub_80BB78C;
    }
}

void sub_80BBD1C(u8 taskId)
{
    if (!gTasks[gTasks[taskId].data[0]].isActive)
    {
        sub_80BDA40();
        if (sPokedexView->unk64E != 0)
        {
            sPokedexView->selectedPokemon = 0;
            sPokedexView->unk62C = 0x40;
            gTasks[taskId].func = sub_80BBE70;
        }
        else
        {
            sPokedexView->unk62C = sPokedexView->unk62A;
            sPokedexView->selectedPokemon = sPokedexView->unk610;
            sPokedexView->dexMode = sPokedexView->unk614;
            if (!IsNationalPokedexEnabled())
                sPokedexView->dexMode = DEX_MODE_HOENN;
            sPokedexView->dexOrder = sPokedexView->unk618;
            gTasks[taskId].func = sub_80BB78C;
        }
    }
}

void sub_80BBDE8(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        gSaveBlock2Ptr->pokedex.mode = sPokedexView->dexMode;
        if (!IsNationalPokedexEnabled())
            gSaveBlock2Ptr->pokedex.mode = DEX_MODE_HOENN;
        gSaveBlock2Ptr->pokedex.order = sPokedexView->dexOrder;
        sub_80BDA40();
        sub_80BC890();
        DestroyTask(taskId);
        SetMainCallback2(CB2_ReturnToFieldWithOpenMenu);
        m4aMPlayVolumeControl(&gMPlayInfo_BGM, 0xFFFF, 0x100);
        Free(sPokedexView);
    }
}

void sub_80BBE70(u8 taskId)
{
    sPokedexView->unk64C_1 = TRUE;
    if (sub_80BC514(3))
        gTasks[taskId].func = sub_80BBEB8;
}

void sub_80BBEB8(u8 taskId)
{
    SetGpuReg(REG_OFFSET_BG0VOFS, sPokedexView->menuY);

    if (sPokedexView->menuY)
    {
        sPokedexView->menuY -= 8;
    }
    else
    {
        if ((gMain.newKeys & A_BUTTON) && sPokedexView->pokedexList[sPokedexView->selectedPokemon].seen)
        {
            u32 a;

            sub_80BD8D0();
            a = (1 << (gSprites[sPokedexView->selectedMonSpriteId].oam.paletteNum + 16));
            gSprites[sPokedexView->selectedMonSpriteId].callback = sub_80BE470;
            BeginNormalPaletteFade(~a, 0, 0, 0x10, RGB_BLACK);
            gTasks[taskId].func = sub_80BC2D4;
            PlaySE(SE_PIN);
            sub_80BC890();
        }
        else if (gMain.newKeys & START_BUTTON)
        {
            sPokedexView->menuY = 0;
            sPokedexView->menuIsOpen = 1;
            sPokedexView->menuCursorPos = 0;
            gTasks[taskId].func = HandleButtonPress_StartMenu;
            PlaySE(SE_SELECT);
        }
        else if (gMain.newKeys & SELECT_BUTTON)
        {
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 0x10, RGB_BLACK);
            gTasks[taskId].data[0] = sub_80C1258();
            sPokedexView->unk64E = 0;
            gTasks[taskId].func = sub_80BBD1C;
            PlaySE(SE_PC_LOGIN);
            sub_80BC890();
        }
        else if (gMain.newKeys & B_BUTTON)
        {
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 0x10, RGB_BLACK);
            gTasks[taskId].func = sub_80BC3DC;
            PlaySE(SE_PC_OFF);
        }
        else
        {
            //Handle D-pad
            sPokedexView->selectedPokemon = sub_80BD69C(sPokedexView->selectedPokemon, 0xE);
            if (sPokedexView->unk62E)
                gTasks[taskId].func = sub_80BC0A8;
        }
    }
}

void sub_80BC0A8(u8 taskId)
{
    if (sub_80BD404(sPokedexView->unk62F, sPokedexView->unk634, sPokedexView->unk636))
        gTasks[taskId].func = sub_80BBEB8;
}

static void HandleButtonPress_StartMenu(u8 taskId)
{
    SetGpuReg(REG_OFFSET_BG0VOFS, sPokedexView->menuY);

    if (sPokedexView->menuY != 96)
    {
        sPokedexView->menuY += 8;
    }
    else
    {
        if (gMain.newKeys & A_BUTTON)
        {
            switch (sPokedexView->menuCursorPos)
            {
            case 0: //BACK TO LIST
                default:
                    gMain.newKeys |= START_BUTTON;
                    break;
                case 1: //LIST TOP
                    sPokedexView->selectedPokemon = 0;
                    sPokedexView->unk62C = 0x40;
                    sub_80BDA40();
                    CreateInitialPokemonSprites(sPokedexView->selectedPokemon, 0xE);
                    gMain.newKeys |= START_BUTTON;
                    break;
                case 2: //LIST BOTTOM
                    sPokedexView->selectedPokemon = sPokedexView->pokemonListCount - 1;
                    sPokedexView->unk62C = sPokedexView->pokemonListCount * 16 + 0x30;
                    sub_80BDA40();
                    CreateInitialPokemonSprites(sPokedexView->selectedPokemon, 0xE);
                    gMain.newKeys |= START_BUTTON;
                    break;
                case 3: //BACK TO POKEDEX
                    BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 0x10, RGB_BLACK);
                    gTasks[taskId].func = sub_80BC3DC;
                    PlaySE(SE_TRACK_DOOR);
                    break;
                case 4: //CLOSE POKEDEX
                    BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 0x10, RGB_BLACK);
                    gTasks[taskId].func = sub_80BC47C;
                    PlaySE(SE_PC_OFF);
                    break;
            }
        }

        //Exit menu when Start or B is pressed
        if (gMain.newKeys & (START_BUTTON | B_BUTTON))
        {
            sPokedexView->menuIsOpen = 0;
            gTasks[taskId].func = sub_80BBEB8;
            PlaySE(SE_SELECT);
        }
        else if ((gMain.newAndRepeatedKeys & DPAD_UP) && sPokedexView->menuCursorPos)
        {
            sPokedexView->menuCursorPos--;
            PlaySE(SE_SELECT);
        }
        else if ((gMain.newAndRepeatedKeys & DPAD_DOWN) && sPokedexView->menuCursorPos <= 3)
        {
            sPokedexView->menuCursorPos++;
            PlaySE(SE_SELECT);
        }
    }
}

void sub_80BC2D4(u8 taskId)
{
    if (gSprites[sPokedexView->selectedMonSpriteId].pos1.x == 48 && gSprites[sPokedexView->selectedMonSpriteId].pos1.y == 56)
    {
        sPokedexView->unk64B = sPokedexView->unk64A;
        gTasks[taskId].data[0] = sub_80BE91C(&sPokedexView->pokedexList[sPokedexView->selectedPokemon], sPokedexView->selectedMonSpriteId);
        sPokedexView->selectedMonSpriteId = -1;
        gTasks[taskId].func = sub_80BC360;
    }
}

void sub_80BC360(u8 taskId)
{
    if (gTasks[gTasks[taskId].data[0]].isActive)
    {
        if (sPokedexView->unk64A == 1 && !sub_80BE9C4(gTasks[taskId].data[0]) && sub_80BD930())
            sub_80BE9F8(&sPokedexView->pokedexList[sPokedexView->selectedPokemon], gTasks[taskId].data[0]);
    }
    else
    {
        gTasks[taskId].func = sub_80BBE70;
    }
}

void sub_80BC3DC(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        sPokedexView->unk62C = sPokedexView->unk62A;
        sPokedexView->selectedPokemon = sPokedexView->unk610;
        sPokedexView->dexMode = sPokedexView->unk614;
        if (!IsNationalPokedexEnabled())
            sPokedexView->dexMode = DEX_MODE_HOENN;
        sPokedexView->dexOrder = sPokedexView->unk618;
        gTasks[taskId].func = sub_80BB78C;
        sub_80BDA40();
        sub_80BC890();
    }
}

void sub_80BC47C(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        sPokedexView->unk62C = sPokedexView->unk62A;
        sPokedexView->selectedPokemon = sPokedexView->unk610;
        sPokedexView->dexMode = sPokedexView->unk614;
        if (!IsNationalPokedexEnabled())
            sPokedexView->dexMode = DEX_MODE_HOENN;
        sPokedexView->dexOrder = sPokedexView->unk618;
        gTasks[taskId].func = sub_80BBDE8;
    }
}

bool8 sub_80BC514(u8 a)
{
    switch (gMain.state)
    {
        case 0:
        default:
            if (gPaletteFade.active)
                return 0;
            SetVBlankCallback(NULL);
            sPokedexView->unk64A = a;
            sub_80C09B0(0);
            SetGpuReg(REG_OFFSET_BG2VOFS, sPokedexView->initialVOffset);
            ResetBgsAndClearDma3BusyFlags(0);
            InitBgsFromTemplates(0, gBgTemplates_0855D298, 4);
            SetBgTilemapBuffer(3, AllocZeroed(0x800));
            SetBgTilemapBuffer(2, AllocZeroed(0x800));
            SetBgTilemapBuffer(1, AllocZeroed(0x800));
            SetBgTilemapBuffer(0, AllocZeroed(0x800));
            DecompressAndLoadBgGfxUsingHeap(3, gPokedexMenu_Gfx, 0x2000, 0, 0);
            CopyToBgTilemapBuffer(1, gPokedexTilemap_Main, 0, 0);
            CopyToBgTilemapBuffer(3, gPokedexTilemap_MainUnderlay, 0, 0);
            if (a == 0)
                CopyToBgTilemapBuffer(0, gPokedexTilemap_StartMenu1, 0, 0x280);
            else
                CopyToBgTilemapBuffer(0, gPokedexTilemap_StartMenu2, 0, 0x280);
            ResetPaletteFade();
            if (a == 0)
                sPokedexView->unk64C_1 = FALSE;
            else
                sPokedexView->unk64C_1 = TRUE;
            LoadPokedexBgPalette(sPokedexView->unk64C_1);
            InitWindows(sPokemonList_WindowTemplate);
            DeactivateAllTextPrinters();
            PutWindowTilemap(0);
            CopyWindowToVram(0, 3);
            gMain.state = 1;
            break;
        case 1:
            ResetSpriteData();
            FreeAllSpritePalettes();
            gReservedSpritePaletteCount = 8;
            LoadCompressedSpriteSheet(&sInterfaceSpriteSheet[0]);
            LoadSpritePalettes(sInterfaceSpritePalette);
            CreateInterfaceSprites(a);
            gMain.state++;
            break;
        case 2:
            gMain.state++;
            break;
        case 3:
            if (a == 0)
                sub_80BC8D4(sPokedexView->dexMode, sPokedexView->dexOrder);
            CreateInitialPokemonSprites(sPokedexView->selectedPokemon, 0xE);
            sPokedexView->menuIsOpen = 0;
            sPokedexView->menuY = 0;
            CopyBgTilemapBufferToVram(0);
            CopyBgTilemapBufferToVram(1);
            CopyBgTilemapBufferToVram(2);
            CopyBgTilemapBufferToVram(3);
            gMain.state++;
            break;
        case 4:
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 0x10, 0, RGB_BLACK);
            SetVBlankCallback(sub_80BB370);
            gMain.state++;
            break;
        case 5:
            SetGpuReg(REG_OFFSET_WININ, 0x3F3F);
            SetGpuReg(REG_OFFSET_WINOUT, 0x1D3F);
            SetGpuReg(REG_OFFSET_WIN0H, 0);
            SetGpuReg(REG_OFFSET_WIN0V, 0);
            SetGpuReg(REG_OFFSET_WIN1H, 0);
            SetGpuReg(REG_OFFSET_WIN1V, 0);
            SetGpuReg(REG_OFFSET_BLDCNT, 0);
            SetGpuReg(REG_OFFSET_BLDALPHA, 0);
            SetGpuReg(REG_OFFSET_BLDY, 0);
            SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0 | DISPCNT_OBJ_1D_MAP | DISPCNT_OBJ_ON | DISPCNT_OBJWIN_ON);
            ShowBg(0);
            ShowBg(1);
            ShowBg(2);
            ShowBg(3);
            gMain.state++;
            break;
        case 6:
            if (!gPaletteFade.active)
            {
                gMain.state = 0;
                return TRUE;
            }
            break;
    }
    return FALSE;
}

static void LoadPokedexBgPalette(u8 a)
{
    if (a == 1)
        LoadPalette(gPokedexHoennBg_Pal + 1, 1, 0xBE);
    else if (!IsNationalPokedexEnabled())
        LoadPalette(gPokedexText_Pal + 1, 1, 0xBE);
    else
        LoadPalette(gPokedexNationalBg_Pal + 1, 1, 0xBE);
    LoadPalette(GetOverworldTextboxPalettePtr(), 0xF0, 32);
}

void sub_80BC890(void)
{
    void* tilemapBuffer;

    FreeAllWindowBuffers();
    tilemapBuffer = GetBgTilemapBuffer(0);
    if (tilemapBuffer)
        Free(tilemapBuffer);
    tilemapBuffer = GetBgTilemapBuffer(1);
    if (tilemapBuffer)
        Free(tilemapBuffer);
    tilemapBuffer = GetBgTilemapBuffer(2);
    if (tilemapBuffer)
        Free(tilemapBuffer);
    tilemapBuffer = GetBgTilemapBuffer(3);
    if (tilemapBuffer)
        Free(tilemapBuffer);
}

void sub_80BC8D4(u8 dexMode, u8 sortMode)
{
    u32 vars[3]; //I have no idea why three regular variables are stored in an array, but whatever.
#define temp_dexCount   vars[0]
#define temp_isHoennDex vars[1]
#define temp_dexNum     vars[2]
    s32 i;

    sPokedexView->pokemonListCount = 0;

    switch (dexMode)
    {
        default:
        case DEX_MODE_HOENN:
            temp_dexCount = HOENN_DEX_COUNT;
            temp_isHoennDex = TRUE;
            break;
        case DEX_MODE_NATIONAL:
            if (IsNationalPokedexEnabled())
            {
                temp_dexCount = NATIONAL_DEX_COUNT;
                temp_isHoennDex = FALSE;
            }
            else
            {
                temp_dexCount = HOENN_DEX_COUNT;
                temp_isHoennDex = TRUE;
            }
            break;
    }

    switch (sortMode)
    {
        case 0:
            if (temp_isHoennDex)
            {
                for (i = 0; i < temp_dexCount; i++)
                {
                    temp_dexNum = HoennToNationalOrder(i + 1);
                    sPokedexView->pokedexList[i].dexNum = temp_dexNum;
                    sPokedexView->pokedexList[i].seen = GetSetPokedexFlag(temp_dexNum, FLAG_GET_SEEN);
                    sPokedexView->pokedexList[i].owned = GetSetPokedexFlag(temp_dexNum, FLAG_GET_CAUGHT);
                    if (sPokedexView->pokedexList[i].seen)
                        sPokedexView->pokemonListCount = i + 1;
                }
            }
            else
            {
                bool32 r10;
                s16 r5;

                r10 = r5 = i = 0;
                for (i = 0; i < temp_dexCount; i++)
                {
                    temp_dexNum = i + 1;
                    if (GetSetPokedexFlag(temp_dexNum, FLAG_GET_SEEN))
                        r10 = 1;
                    if (r10)
                    {
                        asm("");    //Needed to match for some reason
                        sPokedexView->pokedexList[r5].dexNum = temp_dexNum;
                        sPokedexView->pokedexList[r5].seen = GetSetPokedexFlag(temp_dexNum, FLAG_GET_SEEN);
                        sPokedexView->pokedexList[r5].owned = GetSetPokedexFlag(temp_dexNum, FLAG_GET_CAUGHT);
                        if (sPokedexView->pokedexList[r5].seen)
                            sPokedexView->pokemonListCount = r5 + 1;
                        r5++;
                    }
                }
            }
            break;
        case 1:
            for (i = 0; i < ARRAY_COUNT(gPokedexOrder_Alphabetical); i++)
            {
                temp_dexNum = gPokedexOrder_Alphabetical[i];

                if (NationalToHoennOrder(temp_dexNum) != 0 && GetSetPokedexFlag(temp_dexNum, FLAG_GET_SEEN))
                {
                    sPokedexView->pokedexList[sPokedexView->pokemonListCount].dexNum = temp_dexNum;
                    sPokedexView->pokedexList[sPokedexView->pokemonListCount].seen = TRUE;
                    sPokedexView->pokedexList[sPokedexView->pokemonListCount].owned = GetSetPokedexFlag(temp_dexNum, FLAG_GET_CAUGHT);
                    sPokedexView->pokemonListCount++;
                }
            }
            break;
        case 2:
            for (i = ARRAY_COUNT(gPokedexOrder_Weight) - 1; i >= 0; i--)
            {
                temp_dexNum = gPokedexOrder_Weight[i];

                if (NationalToHoennOrder(temp_dexNum) != 0 && GetSetPokedexFlag(temp_dexNum, FLAG_GET_CAUGHT))
                {
                    sPokedexView->pokedexList[sPokedexView->pokemonListCount].dexNum = temp_dexNum;
                    sPokedexView->pokedexList[sPokedexView->pokemonListCount].seen = TRUE;
                    sPokedexView->pokedexList[sPokedexView->pokemonListCount].owned = TRUE;
                    sPokedexView->pokemonListCount++;
                }
            }
            break;
        case 3:
            for (i = 0; i < ARRAY_COUNT(gPokedexOrder_Weight); i++)
            {
                temp_dexNum = gPokedexOrder_Weight[i];

                if (NationalToHoennOrder(temp_dexNum) != 0 && GetSetPokedexFlag(temp_dexNum, FLAG_GET_CAUGHT))
                {
                    sPokedexView->pokedexList[sPokedexView->pokemonListCount].dexNum = temp_dexNum;
                    sPokedexView->pokedexList[sPokedexView->pokemonListCount].seen = TRUE;
                    sPokedexView->pokedexList[sPokedexView->pokemonListCount].owned = TRUE;
                    sPokedexView->pokemonListCount++;
                }
            }
            break;
        case 4:
            for (i = ARRAY_COUNT(gPokedexOrder_Height) - 1; i >= 0; i--)
            {
                temp_dexNum = gPokedexOrder_Height[i];

                if (NationalToHoennOrder(temp_dexNum) != 0 && GetSetPokedexFlag(temp_dexNum, FLAG_GET_CAUGHT))
                {
                    sPokedexView->pokedexList[sPokedexView->pokemonListCount].dexNum = temp_dexNum;
                    sPokedexView->pokedexList[sPokedexView->pokemonListCount].seen = TRUE;
                    sPokedexView->pokedexList[sPokedexView->pokemonListCount].owned = TRUE;
                    sPokedexView->pokemonListCount++;
                }
            }
            break;
        case 5:
            for (i = 0; i < ARRAY_COUNT(gPokedexOrder_Height); i++)
            {
                temp_dexNum = gPokedexOrder_Height[i];

                if (NationalToHoennOrder(temp_dexNum) != 0 && GetSetPokedexFlag(temp_dexNum, FLAG_GET_CAUGHT))
                {
                    sPokedexView->pokedexList[sPokedexView->pokemonListCount].dexNum = temp_dexNum;
                    sPokedexView->pokedexList[sPokedexView->pokemonListCount].seen = TRUE;
                    sPokedexView->pokedexList[sPokedexView->pokemonListCount].owned = TRUE;
                    sPokedexView->pokemonListCount++;
                }
            }
            break;
    }

    for (i = sPokedexView->pokemonListCount; i < NATIONAL_DEX_COUNT; i++)
    {
        sPokedexView->pokedexList[i].dexNum = 0xFFFF;
        sPokedexView->pokedexList[i].seen = FALSE;
        sPokedexView->pokedexList[i].owned = FALSE;
    }
}

static void PrintMonDexNumAndName(u8 windowId, u8 fontId, const u8* str, u8 left, u8 top)
{
    u8 color[3];

    color[0] = 0;
    color[1] = 15;
    color[2] = 3;
    AddTextPrinterParameterized4(windowId, fontId, left * 8, (top * 8) + 1, 0, 0, color, -1, str);
}

static void CreateMonListEntry(u8 direction, u16 b, u16 c)
{
    s16 _b;
    u16 i;
    u16 r2;

    switch (direction)
    {
        case 0: // Initial
        default:
            _b = b - 5;
            for (i = 0; i <= 10; i++)
            {
                if (_b < 0 || _b >= NATIONAL_DEX_COUNT || sPokedexView->pokedexList[_b].dexNum == 0xFFFF)
                {
                    sub_80BD28C(0x11, i * 2, c);
                }
                else
                {
                    sub_80BD28C(0x11, i * 2, c);
                    if (sPokedexView->pokedexList[_b].seen)
                    {
                        CreateMonDexNum(_b, 0x12, i * 2, c);
                        CreateCaughtBall(sPokedexView->pokedexList[_b].owned, 0x11, i * 2, c);
                        CreateMonName(sPokedexView->pokedexList[_b].dexNum, 0x16, i * 2);
                    }
                    else
                    {
                        CreateMonDexNum(_b, 0x12, i * 2, c);
                        CreateCaughtBall(0, 0x11, i * 2, c);
                        CreateMonName(0, 0x16, i * 2);
                    }
                }
                _b++;
            }
            break;
        case 1: // Up
            _b = b - 5;
            if (_b < 0 || _b >= NATIONAL_DEX_COUNT || sPokedexView->pokedexList[_b].dexNum == 0xFFFF)
            {
                sub_80BD28C(0x11, sPokedexView->unk630 * 2, c);
            }
            else
            {
                sub_80BD28C(0x11, sPokedexView->unk630 * 2, c);
                if (sPokedexView->pokedexList[_b].seen)
                {
                    CreateMonDexNum(_b, 0x12, sPokedexView->unk630 * 2, c);
                    CreateCaughtBall(sPokedexView->pokedexList[_b].owned, 0x11, sPokedexView->unk630 * 2, c);
                    CreateMonName(sPokedexView->pokedexList[_b].dexNum, 0x16, sPokedexView->unk630 * 2);
                }
                else
                {
                    CreateMonDexNum(_b, 0x12, sPokedexView->unk630 * 2, c);
                    CreateCaughtBall(0, 0x11, sPokedexView->unk630 * 2, c);
                    CreateMonName(0, 0x16, sPokedexView->unk630 * 2);
                }
            }
            break;
        case 2: // Down
            _b = b + 5;
            r2 = sPokedexView->unk630 + 10;
            if (r2 > 15)
                r2 -= 16;
            if (_b < 0 || _b >= NATIONAL_DEX_COUNT || sPokedexView->pokedexList[_b].dexNum == 0xFFFF)
                sub_80BD28C(0x11, r2 * 2, c);
            else
            {
                sub_80BD28C(0x11, r2 * 2, c);
                if (sPokedexView->pokedexList[_b].seen)
                {
                    CreateMonDexNum(_b, 0x12, r2 * 2, c);
                    CreateCaughtBall(sPokedexView->pokedexList[_b].owned, 0x11, r2 * 2, c);
                    CreateMonName(sPokedexView->pokedexList[_b].dexNum, 0x16, r2 * 2);
                }
                else
                {
                    CreateMonDexNum(_b, 0x12, r2 * 2, c);
                    CreateCaughtBall(0, 0x11, r2 * 2, c);
                    CreateMonName(0, 0x16, r2 * 2);
                }
            }
            break;
    }
    CopyWindowToVram(0, 2);
}

static void CreateMonDexNum(u16 a, u8 left, u8 top, u16 unused)
{
    u8 text[6];
    u16 r6;

    memcpy(text, sText_No000, 6);
    r6 = sPokedexView->pokedexList[a].dexNum;
    if (sPokedexView->dexMode == DEX_MODE_HOENN)
        r6 = NationalToHoennOrder(r6);
    text[2] = CHAR_0 + r6 / 100;
    text[3] = CHAR_0 + (r6 % 100) / 10;
    text[4] = CHAR_0 + (r6 % 100) % 10;
    PrintMonDexNumAndName(0, 7, text, left, top);
}

static void CreateCaughtBall(u16 a, u8 x, u8 y, u16 unused)
{
    if (a)
        BlitBitmapToWindow(0, gUnknown_0855D2BE, x * 8, y * 8, 8, 16);
    else
        FillWindowPixelRect(0, PIXEL_FILL(0), x * 8, y * 8, 8, 16);
}

static u8 CreateMonName(u16 num, u8 left, u8 top)
{
    const u8* str;

    num = NationalPokedexNumToSpecies(num);
    if (num)
        str = gSpeciesNames[num];
    else
        str = sText_TenDashes;
    PrintMonDexNumAndName(0, 7, str, left, top);
    return StringLength(str);
}

void sub_80BD28C(u8 x, u8 y, u16 unused)
{
    FillWindowPixelRect(0, PIXEL_FILL(0), x * 8, y * 8, 0x60, 16);
}

static void CreateInitialPokemonSprites(u16 selectedMon, u16 b)
{
    u8 i;
    u16 unk;
    u8 spriteId;

    gPaletteFade.bufferTransferDisabled = TRUE;

    for (i = 0; i < 4; i++)
        sPokedexView->unk61E[i] = 0xFFFF;
    sPokedexView->selectedMonSpriteId = 0xFFFF;

    unk = GetPokemonSpriteToDisplay(selectedMon - 1);
    if (unk != 0xFFFF)
    {
        spriteId = sub_80BDACC(unk, 0x60, 0x50);
        gSprites[spriteId].callback = sub_80BE4E0;
        gSprites[spriteId].data[5] = -32;
    }

    unk = GetPokemonSpriteToDisplay(selectedMon);
    if (unk != 0xFFFF)
    {
        spriteId = sub_80BDACC(unk, 0x60, 0x50);
        gSprites[spriteId].callback = sub_80BE4E0;
        gSprites[spriteId].data[5] = 0;
    }

    unk = GetPokemonSpriteToDisplay(selectedMon + 1);
    if (unk != 0xFFFF)
    {
        spriteId = sub_80BDACC(unk, 0x60, 0x50);
        gSprites[spriteId].callback = sub_80BE4E0;
        gSprites[spriteId].data[5] = 32;
    }

    CreateMonListEntry(0, selectedMon, b);
    SetGpuReg(REG_OFFSET_BG2VOFS, sPokedexView->initialVOffset);

    sPokedexView->unk630 = 0;
    sPokedexView->unk632 = 0;

    gPaletteFade.bufferTransferDisabled = FALSE;
}

bool8 sub_80BD404(u8 a, u8 b, u8 c)
{
    u16 i;
    u8 foo;

    if (sPokedexView->unk62E)
    {
        sPokedexView->unk62E--;
        switch (a)
        {
            case 1:
                for (i = 0; i < 4; i++)
                {
                    if (sPokedexView->unk61E[i] != 0xFFFF)
                        gSprites[sPokedexView->unk61E[i]].data[5] += b;
                }
                foo = 16 * (c - sPokedexView->unk62E) / c;
                SetGpuReg(REG_OFFSET_BG2VOFS, sPokedexView->initialVOffset + sPokedexView->unk632 * 16 - foo);
                sPokedexView->unk62C -= sPokedexView->unk628;
                break;
            case 2:
                for (i = 0; i < 4; i++)
                {
                    if (sPokedexView->unk61E[i] != 0xFFFF)
                        gSprites[sPokedexView->unk61E[i]].data[5] -= b;
                }
                foo = 16 * (c - sPokedexView->unk62E) / c;
                SetGpuReg(REG_OFFSET_BG2VOFS, sPokedexView->initialVOffset + sPokedexView->unk632 * 16 + foo);
                sPokedexView->unk62C += sPokedexView->unk628;
                break;
        }
        return FALSE;
    }
    else
    {
        SetGpuReg(REG_OFFSET_BG2VOFS, sPokedexView->initialVOffset + sPokedexView->unk630 * 16);
        return TRUE;
    }
}

static void CreateNewPokemonSprite(u8 direction, u16 selectedMon)
{
    u16 unk;
    u8 spriteId;

    sPokedexView->unk632 = sPokedexView->unk630;
    switch (direction)
    {
        case 1: // up
            unk = GetPokemonSpriteToDisplay(selectedMon - 1);
            if (unk != 0xFFFF)
            {
                spriteId = sub_80BDACC(unk, 0x60, 0x50);
                gSprites[spriteId].callback = sub_80BE4E0;
                gSprites[spriteId].data[5] = -64;
            }
            if (sPokedexView->unk630 > 0)
                sPokedexView->unk630--;
            else
                sPokedexView->unk630 = 15;
            break;
        case 2: // down
            unk = GetPokemonSpriteToDisplay(selectedMon + 1);
            if (unk != 0xFFFF)
            {
                spriteId = sub_80BDACC(unk, 0x60, 0x50);
                gSprites[spriteId].callback = sub_80BE4E0;
                gSprites[spriteId].data[5] = 0x40;
            }
            if (sPokedexView->unk630 <= 0xE)
                sPokedexView->unk630++;
            else
                sPokedexView->unk630 = 0;
            break;
    }
}

u16 sub_80BD69C(u16 selectedMon, u16 b)
{
    u8 r3;
    u8 r5;
    u8 i;
    u16 r6;
    u8 r10 = 0;

    if ((gMain.heldKeys & DPAD_UP) && (selectedMon > 0))
    {
        r10 = 1;
        selectedMon = sub_80C0E0C(1, selectedMon, 0, sPokedexView->pokemonListCount - 1);
        CreateNewPokemonSprite(1, selectedMon);
        CreateMonListEntry(1, selectedMon, b);
        PlaySE(SE_Z_SCROLL);
    }
    else if ((gMain.heldKeys & DPAD_DOWN) && (selectedMon < sPokedexView->pokemonListCount - 1))
    {
        r10 = 2;
        selectedMon = sub_80C0E0C(0, selectedMon, 0, sPokedexView->pokemonListCount - 1);
        CreateNewPokemonSprite(2, selectedMon);
        CreateMonListEntry(2, selectedMon, b);
        PlaySE(SE_Z_SCROLL);
    }
    else if ((gMain.newKeys & DPAD_LEFT) && (selectedMon > 0))
    {
        r6 = selectedMon;

        for (i = 0; i < 7; i++)
            selectedMon = sub_80C0E0C(1, selectedMon, 0, sPokedexView->pokemonListCount - 1);
        sPokedexView->unk62C += 16 * (selectedMon - r6);
        sub_80BDA40();
        CreateInitialPokemonSprites(selectedMon, 0xE);
        PlaySE(SE_Z_PAGE);
    }
    else if ((gMain.newKeys & DPAD_RIGHT) && (selectedMon < sPokedexView->pokemonListCount - 1))
    {
        r6 = selectedMon;
        for (i = 0; i < 7; i++)
            selectedMon = sub_80C0E0C(0, selectedMon, 0, sPokedexView->pokemonListCount - 1);
        sPokedexView->unk62C += (selectedMon - r6) * 16;
        sub_80BDA40();
        CreateInitialPokemonSprites(selectedMon, 0xE);
        PlaySE(SE_Z_PAGE);
    }

    if (r10 == 0)
    {
        sPokedexView->unk638 = 0;
        return selectedMon;
    }

    r5 = gUnknown_0855D28C[sPokedexView->unk638 / 4];
    r3 = gUnknown_0855D291[sPokedexView->unk638 / 4];
    sPokedexView->unk62E = r3;
    sPokedexView->unk636 = r3;
    sPokedexView->unk634 = r5;
    sPokedexView->unk62F = r10;
    sPokedexView->unk628 = r5 / 2;
    sub_80BD404(sPokedexView->unk62F, sPokedexView->unk634, sPokedexView->unk636);
    if (sPokedexView->unk638 <= 0xB)
        sPokedexView->unk638++;
    return selectedMon;
}

void sub_80BD8D0(void)
{
    u16 i;

    for (i = 0; i < 4; i++)
    {
        u16 spriteId = sPokedexView->unk61E[i];

        if (gSprites[spriteId].pos2.x == 0 && gSprites[spriteId].pos2.y == 0 && spriteId != 0xFFFF)
            sPokedexView->selectedMonSpriteId = spriteId;
    }
}

u8 sub_80BD930(void)
{
    u16 r2;
    u16 r4 = sPokedexView->selectedPokemon;

    if ((gMain.newKeys & DPAD_UP) && r4)
    {
        r2 = r4;
        while (r2 != 0)
        {
            r2 = sub_80C0E0C(1, r2, 0, sPokedexView->pokemonListCount - 1);

            if (sPokedexView->pokedexList[r2].seen)
            {
                r4 = r2;
                break;
            }
        }

        if (sPokedexView->selectedPokemon == r4)
            return FALSE;
        else
        {
            sPokedexView->selectedPokemon = r4;
            sPokedexView->unk62C -= 16;
            return TRUE;
        }
    }
    else if ((gMain.newKeys & DPAD_DOWN) && r4 < sPokedexView->pokemonListCount - 1)
    {
        r2 = r4;
        while (r2 < sPokedexView->pokemonListCount - 1)
        {
            r2 = sub_80C0E0C(0, r2, 0, sPokedexView->pokemonListCount - 1);

            if (sPokedexView->pokedexList[r2].seen)
            {
                r4 = r2;
                break;
            }
        }

        if (sPokedexView->selectedPokemon == r4)
            return FALSE;
        else
        {
            sPokedexView->selectedPokemon = r4;
            sPokedexView->unk62C += 16;
            return TRUE;
        }
    }
    return FALSE;
}

u8 sub_80BDA40(void)
{
    u16 i;

    for (i = 0; i < 4; i++)
    {
        if (sPokedexView->unk61E[i] != 0xFFFF)
        {
            FreeAndDestroyMonPicSprite(sPokedexView->unk61E[i]);
            sPokedexView->unk61E[i] = 0xFFFF;
        }
    }
    return FALSE;
}

u16 GetPokemonSpriteToDisplay(u16 species)
{
    if (species >= NATIONAL_DEX_COUNT || sPokedexView->pokedexList[species].dexNum == 0xFFFF)
        return 0xFFFF;
    else if (sPokedexView->pokedexList[species].seen)
        return sPokedexView->pokedexList[species].dexNum;
    else
        return 0;
}

u32 sub_80BDACC(u16 num, s16 x, s16 y)
{
    u8 i;

    for (i = 0; i < 4; i++)
    {
        if (sPokedexView->unk61E[i] == 0xFFFF)
        {
            u8 spriteId = CreateMonSpriteFromNationalDexNumber(num, x, y, i);

            gSprites[spriteId].oam.affineMode = 1;
            gSprites[spriteId].oam.priority = 3;
            gSprites[spriteId].data[0] = 0;
            gSprites[spriteId].data[1] = i;
            gSprites[spriteId].data[2] = NationalPokedexNumToSpecies(num);
            sPokedexView->unk61E[i] = spriteId;
            return spriteId;
        }
    }
    return 0xFFFF;
}

static void CreateInterfaceSprites(u8 a)
{
    u8 spriteId;
    u16 r5;
// Up arrow
    spriteId = CreateSprite(&sArrowSpriteTemplate, 184, 4, 0);
    gSprites[spriteId].data[1] = 0;
// Down arrow
    spriteId = CreateSprite(&sArrowSpriteTemplate, 184, 156, 0);
    gSprites[spriteId].data[1] = 1;
    gSprites[spriteId].vFlip = TRUE;

    CreateSprite(&sScrollBarSpriteTemplate, 230, 20, 0);
// Start button
    CreateSprite(&sInterfaceTextSpriteTemplate, 16, 120, 0);
// Menu text
    spriteId = CreateSprite(&sInterfaceTextSpriteTemplate, 48, 120, 0);
    StartSpriteAnim(&gSprites[spriteId], 3);
// Select button
    spriteId = CreateSprite(&sInterfaceTextSpriteTemplate, 16, 144, 0);
    StartSpriteAnim(&gSprites[spriteId], 2);
    gSprites[spriteId].data[2] = 0x80;
// Search text
    spriteId = CreateSprite(&sInterfaceTextSpriteTemplate, 48, 144, 0);
    StartSpriteAnim(&gSprites[spriteId], 1);

    spriteId = CreateSprite(&sRotatingPokeballSpriteTemplate, 0, 80, 2);
    gSprites[spriteId].oam.affineMode = 1;
    gSprites[spriteId].oam.matrixNum = 30;
    gSprites[spriteId].data[0] = 0x1E;
    gSprites[spriteId].data[1] = 0;

    spriteId = CreateSprite(&sRotatingPokeballSpriteTemplate, 0, 80, 2);
    gSprites[spriteId].oam.affineMode = 1;
    gSprites[spriteId].oam.matrixNum = 31;
    gSprites[spriteId].data[0] = 0x1F;
    gSprites[spriteId].data[1] = 0x80;

    if (a == 0)
    {
        u32 _a;

        if (!IsNationalPokedexEnabled())
        {
// Seen text
            CreateSprite(&sSeenOwnTextSpriteTemplate, 32, 40, 1);
// Own text
            spriteId = CreateSprite(&sSeenOwnTextSpriteTemplate, 32, 72, 1);
            StartSpriteAnim(&gSprites[spriteId], 1);
            _a = 0;
// Seen value - 100s
            spriteId = CreateSprite(&gUnknown_0855D224, 24, 48, 1);
            r5 = sPokedexView->seenCount / 100;
            StartSpriteAnim(&gSprites[spriteId], r5);
            if (r5 != 0)
                _a = 1;
            else
                gSprites[spriteId].invisible = TRUE;
// Seen value - 10s
            spriteId = CreateSprite(&gUnknown_0855D224, 32, 48, 1);
            r5 = (sPokedexView->seenCount % 100) / 10;
            if (r5 != 0 || _a != 0)
                StartSpriteAnim(&gSprites[spriteId], r5);
            else
                gSprites[spriteId].invisible = TRUE;
// Seen value - 1s
            spriteId = CreateSprite(&gUnknown_0855D224, 40, 48, 1);
            r5 = (sPokedexView->seenCount % 100) % 10;
            StartSpriteAnim(&gSprites[spriteId], r5);
            _a = 0;
// Owned value - 100s
            spriteId = CreateSprite(&gUnknown_0855D224, 24, 80, 1);
            r5 = sPokedexView->ownCount / 100;
            StartSpriteAnim(&gSprites[spriteId], r5);
            if (r5 != 0)
                _a = 1;
            else
                gSprites[spriteId].invisible = TRUE;
// Owned value - 10s
            spriteId = CreateSprite(&gUnknown_0855D224, 32, 80, 1);
            r5 = (sPokedexView->ownCount % 100) / 10;
            if (r5 != 0 || _a != 0)
                StartSpriteAnim(&gSprites[spriteId], r5);
            else
                gSprites[spriteId].invisible = TRUE;
// Owned value -1s
            spriteId = CreateSprite(&gUnknown_0855D224, 40, 80, 1);
            r5 = (sPokedexView->ownCount % 100) % 10;
            StartSpriteAnim(&gSprites[spriteId], r5);
        }
        else
        {
            u16 r6;

            CreateSprite(&sSeenOwnTextSpriteTemplate, 32, 40, 1);

            spriteId = CreateSprite(&sSeenOwnTextSpriteTemplate, 32, 76, 1);
            StartSpriteAnim(&gSprites[spriteId], 1);

            CreateSprite(&gUnknown_0855D20C, 17, 45, 1);

            spriteId = CreateSprite(&gUnknown_0855D20C, 17, 55, 1);
            StartSpriteAnim(&gSprites[spriteId], 1);

            CreateSprite(&gUnknown_0855D20C, 17, 81, 1);

            spriteId = CreateSprite(&gUnknown_0855D20C, 17, 91, 1);
            StartSpriteAnim(&gSprites[spriteId], 1);

            r6 = GetHoennPokedexCount(0);
            _a = 0;

            spriteId = CreateSprite(&gUnknown_0855D23C, 40, 45, 1);
            r5 = r6 / 100;
            StartSpriteAnim(&gSprites[spriteId], r5);
            if (r5 != 0)
                _a = 1;
            else
                gSprites[spriteId].invisible = TRUE;

            spriteId = CreateSprite(&gUnknown_0855D23C, 48, 45, 1);
            r5 = (r6 % 100) / 10;
            if (r5 != 0 || _a != 0)
                StartSpriteAnim(&gSprites[spriteId], r5);
            else
                gSprites[spriteId].invisible = TRUE;

            spriteId = CreateSprite(&gUnknown_0855D23C, 56, 45, 1);
            r5 = (r6 % 100) % 10;
            StartSpriteAnim(&gSprites[spriteId], r5);

            _a = 0;

            spriteId = CreateSprite(&gUnknown_0855D23C, 40, 55, 1);
            r5 = sPokedexView->seenCount / 100;
            StartSpriteAnim(&gSprites[spriteId], r5);
            if (r5 != 0)
                _a = 1;
            else
                gSprites[spriteId].invisible = TRUE;

            spriteId = CreateSprite(&gUnknown_0855D23C, 48, 55, 1);
            r5 = (sPokedexView->seenCount % 100) / 10;
            if (r5 != 0 || _a != 0)
                StartSpriteAnim(&gSprites[spriteId], r5);
            else
                gSprites[spriteId].invisible = TRUE;

            spriteId = CreateSprite(&gUnknown_0855D23C, 56, 55, 1);
            r5 = (sPokedexView->seenCount % 100) % 10;
            StartSpriteAnim(&gSprites[spriteId], r5);

            r6 = GetHoennPokedexCount(1);
            _a = 0;

            spriteId = CreateSprite(&gUnknown_0855D23C, 40, 81, 1);
            r5 = r6 / 100;
            StartSpriteAnim(&gSprites[spriteId], r5);
            if (r5 != 0)
                _a = 1;
            else
                gSprites[spriteId].invisible = TRUE;

            spriteId = CreateSprite(&gUnknown_0855D23C, 48, 81, 1);
            r5 = (r6 % 100) / 10;
            if (r5 != 0 || _a != 0)
                StartSpriteAnim(&gSprites[spriteId], r5);
            else
                gSprites[spriteId].invisible = TRUE;

            spriteId = CreateSprite(&gUnknown_0855D23C, 56, 81, 1);
            r5 = (r6 % 100) % 10;
            StartSpriteAnim(&gSprites[spriteId], r5);

            _a = 0;

            spriteId = CreateSprite(&gUnknown_0855D23C, 40, 91, 1);
            r5 = sPokedexView->ownCount / 100;
            StartSpriteAnim(&gSprites[spriteId], r5);
            if (r5 != 0)
                _a = 1;
            else
                gSprites[spriteId].invisible = TRUE;

            spriteId = CreateSprite(&gUnknown_0855D23C, 48, 91, 1);
            r5 = (sPokedexView->ownCount % 100) / 10;
            if (r5 != 0 || _a != 0)
                StartSpriteAnim(&gSprites[spriteId], r5);
            else
                gSprites[spriteId].invisible = TRUE;

            spriteId = CreateSprite(&gUnknown_0855D23C, 56, 91, 1);
            r5 = (sPokedexView->ownCount % 100) % 10;
            StartSpriteAnim(&gSprites[spriteId], r5);
        }
        spriteId = CreateSprite(&gUnknown_0855D254, 136, 96, 1);
        gSprites[spriteId].invisible = TRUE;
    }
    else
    {
        spriteId = CreateSprite(&gUnknown_0855D254, 136, 80, 1);
        gSprites[spriteId].invisible = TRUE;
    }
}

void nullsub_38(struct Sprite *sprite)
{
}

void sub_80BE44C(struct Sprite *sprite)
{
    if (sPokedexView->unk64A != 0)
        DestroySprite(sprite);
}

//Move Pokemon into position for description page
void sub_80BE470(struct Sprite *sprite)
{
    sprite->oam.priority = 0;
    sprite->oam.affineMode = 0;
    sprite->pos2.x = 0;
    sprite->pos2.y = 0;
    if (sprite->pos1.x != 48 || sprite->pos1.y != 56)
    {
        if (sprite->pos1.x > 48)
            sprite->pos1.x--;
        if (sprite->pos1.x < 48)
            sprite->pos1.x++;

        if (sprite->pos1.y > 56)
            sprite->pos1.y--;
        if (sprite->pos1.y < 56)
            sprite->pos1.y++;
    }
    else
    {
        sprite->callback = nullsub_38;
    }
}

void sub_80BE4E0(struct Sprite *sprite)
{
    u8 data1 = sprite->data[1];

    if (sPokedexView->unk64A != 0 && sPokedexView->unk64A != 3)
    {
        FreeAndDestroyMonPicSprite(sPokedexView->unk61E[data1]);
        sPokedexView->unk61E[data1] = 0xFFFF;
    }
    else
    {
        u32 var;

        sprite->pos2.y = gSineTable[(u8)sprite->data[5]] * 76 / 256;
        var = 0x10000 / gSineTable[sprite->data[5] + 0x40];
        if (var > 0xFFFF)
            var = 0xFFFF;
        SetOamMatrix(sprite->data[1] + 1, 0x100, 0, 0, var);
        sprite->oam.matrixNum = data1 + 1;

        if (sprite->data[5] > -64 && sprite->data[5] < 64)
        {
            sprite->invisible = FALSE;
            sprite->data[0] = 1;
        }
        else
        {
            sprite->invisible = TRUE;
        }

        if ((sprite->data[5] <= -64 || sprite->data[5] >= 64) && sprite->data[0] != 0)
        {
            FreeAndDestroyMonPicSprite(sPokedexView->unk61E[data1]);
            sPokedexView->unk61E[data1] = 0xFFFF;
        }
    }
}

static void SpriteCB_Scrollbar(struct Sprite *sprite)
{
    if (sPokedexView->unk64A != 0 && sPokedexView->unk64A != 3)
        DestroySprite(sprite);
    else
        sprite->pos2.y = sPokedexView->selectedPokemon * 120 / (sPokedexView->pokemonListCount - 1);
}

void sub_80BE658(struct Sprite *sprite)
{
    if (sPokedexView->unk64A != 0 && sPokedexView->unk64A != 3)
    {
        DestroySprite(sprite);
    }
    else
    {
        u8 r0;

        if (sprite->data[1] != 0)
        {
            if (sPokedexView->selectedPokemon == sPokedexView->pokemonListCount - 1)
                sprite->invisible = TRUE;
            else
                sprite->invisible = FALSE;
            r0 = sprite->data[2];
        }
        else
        {
            if (sPokedexView->selectedPokemon == 0)
                sprite->invisible = TRUE;
            else
                sprite->invisible = FALSE;
            r0 = sprite->data[2] - 128;
        }
        sprite->pos2.y = gSineTable[r0] / 64;
        sprite->data[2] = sprite->data[2] + 8;
        if (sPokedexView->menuIsOpen == 0 && sPokedexView->menuY == 0 && sprite->invisible == 0)
            sprite->invisible = FALSE;
        else
            sprite->invisible = TRUE;
    }
}

void sub_80BE758(struct Sprite *sprite)
{
    if (sPokedexView->unk64A != 0 && sPokedexView->unk64A != 3)
        DestroySprite(sprite);
}

void sub_80BE780(struct Sprite *sprite)
{
    if (sPokedexView->unk64A != 0 && sPokedexView->unk64A != 3)
    {
        DestroySprite(sprite);
    }
    else
    {
        u8 val;
        s16 r3;
        s16 r0;

        val = sPokedexView->unk62C + sprite->data[1];
        r3 = gSineTable[val];
        r0 = gSineTable[val + 0x40];
        SetOamMatrix(sprite->data[0], r0, r3, -r3, r0);

        val = sPokedexView->unk62C + (sprite->data[1] + 0x40);
        r3 = gSineTable[val];
        r0 = gSineTable[val + 0x40];
        sprite->pos2.x = r0 * 40 / 256;
        sprite->pos2.y = r3 * 40 / 256;
    }
}

void sub_80BE834(struct Sprite *sprite)
{
    if (sPokedexView->unk64A != 0 && sPokedexView->unk64A != 3)
    {
        DestroySprite(sprite);
    }
    else
    {
        u16 r1 = sPokedexView->unk64A == 0 ? 80 : 96;

        if (sPokedexView->menuIsOpen != 0 && sPokedexView->menuY == r1)
        {
            sprite->invisible = FALSE;
            sprite->pos2.y = sPokedexView->menuCursorPos * 16;
            sprite->pos2.x = gSineTable[(u8)sprite->data[2]] / 64;
            sprite->data[2] += 8;
        }
        else
        {
            sprite->invisible = TRUE;
        }
    }
}

void sub_80BE8DC(const u8* str, u8 left, u8 top)
{
    u8 color[3];
    color[0] = 0;
    color[1] = 15;
    color[2] = 3;

    AddTextPrinterParameterized4(0, 1, left, top, 0, 0, color, -1, str);
}

u8 sub_80BE91C(struct PokedexListItem* item, u8 b)
{
    u8 taskId;

    sPokedexListItem = item;
    taskId = CreateTask(sub_80BEA24, 0);
    gTasks[taskId].data[0] = 0;
    gTasks[taskId].data[1] = 1;
    gTasks[taskId].data[2] = 0;
    gTasks[taskId].data[3] = 0;
    gTasks[taskId].data[4] = b;
    gTasks[taskId].data[5] = 255;
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, gUnknown_0856E630, 4);
    SetBgTilemapBuffer(3, AllocZeroed(0x800));
    SetBgTilemapBuffer(2, AllocZeroed(0x800));
    SetBgTilemapBuffer(1, AllocZeroed(0x800));
    SetBgTilemapBuffer(0, AllocZeroed(0x800));
    InitWindows(gUnknown_0856E640);
    DeactivateAllTextPrinters();

    return taskId;
}

bool8 sub_80BE9C4(u8 taskId)
{
    if (gTasks[taskId].data[0] == 0 && gTasks[taskId].func == sub_80BEDF4)
        return FALSE;
    else
        return TRUE;
}

u8 sub_80BE9F8(struct PokedexListItem *item, u8 b)
{
    sPokedexListItem = item;
    gTasks[b].data[0] = 1;
    gTasks[b].data[1] = 0;
    gTasks[b].data[2] = 0;
    gTasks[b].data[3] = 0;
    return b;
}

void sub_80BEA24(u8 taskId)
{
    switch (gMain.state)
    {
        case 0:
        default:
            if (!gPaletteFade.active)
            {
                u16 r2;

                sPokedexView->unk64A = 1;
                gUnknown_030060B4 = gMain.vblankCallback;
                SetVBlankCallback(NULL);
                r2 = 0;
                if (gTasks[taskId].data[1] != 0)
                    r2 += 0x1000;
                if (gTasks[taskId].data[2] != 0)
                    r2 |= 0x200;
                sub_80C09B0(r2);
                gMain.state = 1;
            }
            break;
        case 1:
            DecompressAndLoadBgGfxUsingHeap(3, gPokedexMenu_Gfx, 0x2000, 0, 0);
            CopyToBgTilemapBuffer(3, gPokedexTilemap_DescriptionScreen, 0, 0);
            FillWindowPixelBuffer(0, PIXEL_FILL(0));
            PutWindowTilemap(0);
            PutWindowTilemap(1);
            sub_80C0D30(1, sPokedexListItem->dexNum);
            CopyWindowToVram(1, 2);
            gMain.state++;
            break;
        case 2:
            sub_80BFCDC(0xD);
            sub_80BFD0C(sPokedexView->selectedScreen, 0xD);
            LoadPokedexBgPalette(sPokedexView->unk64C_1);
            gMain.state++;
            break;
        case 3:
            gMain.state++;
            break;
        case 4:
            sub_80C020C(sPokedexListItem->dexNum, sPokedexView->dexMode == 0 ? 0 : 1, sPokedexListItem->owned, 0);
            if (!sPokedexListItem->owned)
                LoadPalette(gPlttBufferUnfaded + 1, 0x31, 0x1E);
            CopyWindowToVram(0, 3);
            CopyBgTilemapBufferToVram(1);
            CopyBgTilemapBufferToVram(2);
            CopyBgTilemapBufferToVram(3);
            gMain.state++;
            break;
        case 5:
            if (gTasks[taskId].data[1] == 0)
            {
                gTasks[taskId].data[4] = (u16)CreateMonSpriteFromNationalDexNumber(sPokedexListItem->dexNum, 48, 56, 0);
                gSprites[gTasks[taskId].data[4]].oam.priority = 0;
            }
            gMain.state++;
            break;
        case 6:
            {
                u32 r3 = 0;

                if (gTasks[taskId].data[2] != 0)
                    r3 = 0x14;
                if (gTasks[taskId].data[1] != 0)
                    r3 |= (1 << (gSprites[gTasks[taskId].data[4]].oam.paletteNum + 16));
                BeginNormalPaletteFade(~r3, 0, 16, 0, RGB_BLACK);
                SetVBlankCallback(gUnknown_030060B4);
                gMain.state++;
            }
            break;
        case 7:
            SetGpuReg(REG_OFFSET_BLDCNT, 0);
            SetGpuReg(REG_OFFSET_BLDALPHA, 0);
            SetGpuReg(REG_OFFSET_BLDY, 0);
            SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_1D_MAP | DISPCNT_OBJ_ON);
            HideBg(0);
            ShowBg(1);
            ShowBg(2);
            ShowBg(3);
            gMain.state++;
            break;
        case 8:
            if (!gPaletteFade.active)
            {
                gMain.state++;
                if (gTasks[taskId].data[3] == 0)
                {
                    StopCryAndClearCrySongs();
                    PlayCry2(NationalPokedexNumToSpecies(sPokedexListItem->dexNum), 0, 0x7D, 0xA);
                }
                else
                {
                    gMain.state++;
                }
            }
            break;
        case 9:
            if (!IsCryPlayingOrClearCrySongs())
                gMain.state++;
            break;
        case 10:
            gTasks[taskId].data[0] = 0;
            gTasks[taskId].data[1] = 0;
            gTasks[taskId].data[2] = 1;
            gTasks[taskId].data[3] = 1;
            gTasks[taskId].func = sub_80BEDF4;
            gMain.state = 0;
            break;
    }
}

void sub_80BEDB0(void)
{
    void *r0;
    FreeAllWindowBuffers();
    r0 = GetBgTilemapBuffer(0);
    if (r0)
        Free(r0);
    r0 = GetBgTilemapBuffer(1);
    if (r0)
        Free(r0);
    r0 = GetBgTilemapBuffer(2);
    if (r0)
        Free(r0);
    r0 = GetBgTilemapBuffer(3);
    if (r0)
        Free(r0);
}

void sub_80BEDF4(u8 taskId)
{
    if (gTasks[taskId].data[0] != 0)
    {
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
        gTasks[taskId].func = sub_80BF038;
        PlaySE(SE_Z_SCROLL);
        return;
    }
    if (gMain.newKeys & B_BUTTON)
    {
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
        gTasks[taskId].func = sub_80BF070;
        PlaySE(SE_PC_OFF);
        return;
    }
    if (gMain.newKeys & A_BUTTON)
    {
        switch (sPokedexView->selectedScreen)
        {
            case AREA_SCREEN:
                BeginNormalPaletteFade(0xFFFFFFEB, 0, 0, 16, RGB_BLACK);
                sPokedexView->unk64E = 1;
                gTasks[taskId].func = sub_80BEFD0;
                PlaySE(SE_PIN);
                break;
            case CRY_SCREEN:
                BeginNormalPaletteFade(0xFFFFFFEB, 0, 0, 0x10, RGB_BLACK);
                sPokedexView->unk64E = 2;
                gTasks[taskId].func = sub_80BEFD0;
                PlaySE(SE_PIN);
                break;
            case SIZE_SCREEN:
                if (!sPokedexListItem->owned)
                {
                    PlaySE(SE_HAZURE);
                }
                else
                {
                    BeginNormalPaletteFade(0xFFFFFFEB, 0, 0, 0x10, RGB_BLACK);
                    sPokedexView->unk64E = 3;
                    gTasks[taskId].func = sub_80BEFD0;
                    PlaySE(SE_PIN);
                }
                break;
            case CANCEL_SCREEN:
                BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 0x10, RGB_BLACK);
                gTasks[taskId].func = sub_80BF070;
                PlaySE(SE_PC_OFF);
                break;
        }
        return;
    }
    if (((gMain.newKeys & DPAD_LEFT)
     || ((gMain.newKeys & L_BUTTON) && gSaveBlock2Ptr->optionsButtonMode == OPTIONS_BUTTON_MODE_LR))
     && sPokedexView->selectedScreen > 0)
    {
        sPokedexView->selectedScreen--;
        sub_80BFD0C(sPokedexView->selectedScreen, 0xD);
        PlaySE(SE_Z_PAGE);
        return;
    }
    if (((gMain.newKeys & DPAD_RIGHT)
     || ((gMain.newKeys & R_BUTTON) && gSaveBlock2Ptr->optionsButtonMode == OPTIONS_BUTTON_MODE_LR))
     && sPokedexView->selectedScreen < 3)
    {
        sPokedexView->selectedScreen++;
        sub_80BFD0C(sPokedexView->selectedScreen, 0xD);
        PlaySE(SE_Z_PAGE);
        return;
    }
}

void sub_80BEFD0(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        FreeAndDestroyMonPicSprite(gTasks[taskId].data[4]);
        switch (sPokedexView->unk64E)
        {
            case 1:
            default:
                gTasks[taskId].func = sub_80BF0AC;
                break;
            case 2:
                gTasks[taskId].func = sub_80BF250;
                break;
            case 3:
                gTasks[taskId].func = sub_80BF82C;
                break;
        }
    }
}

void sub_80BF038(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        FreeAndDestroyMonPicSprite(gTasks[taskId].data[4]);
        gTasks[taskId].func = sub_80BEA24;
    }
}

void sub_80BF070(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        FreeAndDestroyMonPicSprite(gTasks[taskId].data[4]);
        sub_80BEDB0();
        DestroyTask(taskId);
    }
}

void sub_80BF0AC(u8 taskId)
{
    switch (gMain.state)
    {
        case 0:
        default:
            if (!gPaletteFade.active)
            {
                sPokedexView->unk64A = 5;
                gUnknown_030060B4 = gMain.vblankCallback;
                SetVBlankCallback(NULL);
                sub_80C09B0(0x200);
                sPokedexView->selectedScreen = AREA_SCREEN;
                gMain.state = 1;
            }
            break;
        case 1:
            sub_80BFCF4(0xD);
            sub_80BFD7C(0, 0xD);
            LoadPokedexBgPalette(sPokedexView->unk64C_1);
            SetGpuReg(REG_OFFSET_BG1CNT, BGCNT_PRIORITY(0) | BGCNT_CHARBASE(0) | BGCNT_SCREENBASE(13) | BGCNT_16COLOR | BGCNT_TXT256x256);
            gMain.state++;
            break;
        case 2:
            ShowPokedexAreaScreen(NationalPokedexNumToSpecies(sPokedexListItem->dexNum), &sPokedexView->unk64E);
            SetVBlankCallback(gUnknown_030060B4);
            sPokedexView->unk64E = 0;
            gMain.state = 0;
            gTasks[taskId].func = sub_80BF1B4;
            break;
    }
}

void sub_80BF1B4(u8 taskId)
{
    if (sPokedexView->unk64E != 0)
        gTasks[taskId].func = sub_80BF1EC;
}

void sub_80BF1EC(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        switch (sPokedexView->unk64E)
        {
            case 1:
            default:
                gTasks[taskId].func = sub_80BEA24;
                break;
            case 2:
                gTasks[taskId].func = sub_80BF250;
                break;
        }
    }
}

void sub_80BF250(u8 taskId)
{
    switch (gMain.state)
    {
        case 0:
        default:
            if (!gPaletteFade.active)
            {
                m4aMPlayStop(&gMPlayInfo_BGM);
                sPokedexView->unk64A = 6;
                gUnknown_030060B4 = gMain.vblankCallback;
                SetVBlankCallback(NULL);
                sub_80C09B0(0x200);
                sPokedexView->selectedScreen = CRY_SCREEN;
                gMain.state = 1;
            }
            break;
        case 1:
            DecompressAndLoadBgGfxUsingHeap(3, &gPokedexMenu_Gfx, 0x2000, 0, 0);
            CopyToBgTilemapBuffer(3, &gPokedexTilemap_CryScreen, 0, 0);
            FillWindowPixelBuffer(0, PIXEL_FILL(0));
            PutWindowTilemap(0);
            PutWindowTilemap(3);
            PutWindowTilemap(2);
            gMain.state++;
            break;
        case 2:
            sub_80BFCF4(0xD);
            sub_80BFD7C(1, 0xD);
            LoadPokedexBgPalette(sPokedexView->unk64C_1);
            gMain.state++;
            break;
        case 3:
            ResetPaletteFade();
            gMain.state++;
            break;
        case 4:
            sub_80BE8DC(gText_CryOf, 0x52, 33);
            sub_80C0B44(0, sPokedexListItem->dexNum, 0x52, 49);
            gMain.state++;
            break;
        case 5:
            gTasks[taskId].data[4] = CreateMonSpriteFromNationalDexNumber(sPokedexListItem->dexNum, 48, 56, 0);
            gSprites[gTasks[taskId].data[4]].oam.priority = 0;
            gDexCryScreenState = 0;
            gMain.state++;
            break;
        case 6:
            {
                struct CryRelatedStruct sp4;

                sp4.unk0 = 0x4020;
                sp4.unk2 = 0x1F;
                sp4.paletteNo = 8;
                sp4.yPos = 0x1E;
                sp4.xPos = 0xC;
                if (sub_8145354(&sp4, 2) != 0)
                {
                    gMain.state++;
                    gDexCryScreenState = 0;
                }
            }
            break;
        case 7:
            {
                struct CryRelatedStruct spC;

                spC.paletteNo = 9;
                spC.xPos = 0x12;
                spC.yPos = 3;
                if (sub_8145850(&spC, 3) != 0)
                    gMain.state++;
                CopyWindowToVram(3, 2);
                CopyWindowToVram(0, 3);
                CopyBgTilemapBufferToVram(0);
                CopyBgTilemapBufferToVram(1);
                CopyBgTilemapBufferToVram(2);
                CopyBgTilemapBufferToVram(3);
            }
            break;
        case 8:
            BeginNormalPaletteFade(0xFFFFFFEB, 0, 0x10, 0, RGB_BLACK);
            SetVBlankCallback(gUnknown_030060B4);
            gMain.state++;
            break;
        case 9:
            SetGpuReg(REG_OFFSET_BLDCNT, 0);
            SetGpuReg(REG_OFFSET_BLDALPHA, 0);
            SetGpuReg(REG_OFFSET_BLDY, 0);
            SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_1D_MAP | DISPCNT_OBJ_ON);
            ShowBg(0);
            ShowBg(1);
            ShowBg(2);
            ShowBg(3);
            gMain.state++;
            break;
        case 10:
            sPokedexView->unk64E = 0;
            gMain.state = 0;
            gTasks[taskId].func = sub_80BF5CC;
            break;
    }
}

void sub_80BF5CC(u8 taskId)
{
    sub_814545C(2);

    if (IsCryPlaying())
        sub_80BF7FC(1);
    else
        sub_80BF7FC(0);

    if (gMain.newKeys & A_BUTTON)
    {
        sub_80BF7FC(1);
        sub_8145534(NationalPokedexNumToSpecies(sPokedexListItem->dexNum));
        return;
    }
    else if (!gPaletteFade.active)
    {
        if (gMain.newKeys & B_BUTTON)
        {
            BeginNormalPaletteFade(0xFFFFFFEB, 0, 0, 0x10, RGB_BLACK);
            m4aMPlayContinue(&gMPlayInfo_BGM);
            sPokedexView->unk64E = 1;
            gTasks[taskId].func = sub_80BF790;
            PlaySE(SE_PC_OFF);
            return;
        }
        if ((gMain.newKeys & DPAD_LEFT)
         || ((gMain.newKeys & L_BUTTON) && gSaveBlock2Ptr->optionsButtonMode == OPTIONS_BUTTON_MODE_LR))
        {
            BeginNormalPaletteFade(0xFFFFFFEB, 0, 0, 0x10, RGB_BLACK);
            m4aMPlayContinue(&gMPlayInfo_BGM);
            sPokedexView->unk64E = 2;
            gTasks[taskId].func = sub_80BF790;
            PlaySE(SE_Z_PAGE);
            return;
        }
        if ((gMain.newKeys & DPAD_RIGHT)
         || ((gMain.newKeys & R_BUTTON) && gSaveBlock2Ptr->optionsButtonMode == OPTIONS_BUTTON_MODE_LR))
        {
            if (!sPokedexListItem->owned)
            {
                PlaySE(SE_HAZURE);
            }
            else
            {
                BeginNormalPaletteFade(0xFFFFFFEB, 0, 0, 0x10, RGB_BLACK);
                m4aMPlayContinue(&gMPlayInfo_BGM);
                sPokedexView->unk64E = 3;
                gTasks[taskId].func = sub_80BF790;
                PlaySE(SE_Z_PAGE);
            }
            return;
        }
    }
}

void sub_80BF790(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        sub_8145914();
        FreeAndDestroyMonPicSprite(gTasks[taskId].data[4]);
        switch (sPokedexView->unk64E)
        {
            default:
            case 1:
                gTasks[taskId].func = sub_80BEA24;
                break;
            case 2:
                gTasks[taskId].func = sub_80BF0AC;
                break;
            case 3:
                gTasks[taskId].func = sub_80BF82C;
                break;
        }
    }
}

void sub_80BF7FC(u8 a)
{
    u16 unk;

    if (a != 0)
        unk = RGB(18, 28, 0);
    else
        unk = RGB(15, 21, 0);
    LoadPalette(&unk, 0x5D, 2);
}

void sub_80BF82C(u8 taskId)
{
    u8 spriteId;

    switch (gMain.state)
    {
        default:
        case 0:
            if (!gPaletteFade.active)
            {
                sPokedexView->unk64A = 7;
                gUnknown_030060B4 = gMain.vblankCallback;
                SetVBlankCallback(NULL);
                sub_80C09B0(0x200);
                sPokedexView->selectedScreen = SIZE_SCREEN;
                gMain.state = 1;
            }
            break;
        case 1:
            DecompressAndLoadBgGfxUsingHeap(3, gPokedexMenu_Gfx, 0x2000, 0, 0);
            CopyToBgTilemapBuffer(3, gPokedexTilemap_SizeScreen, 0, 0);
            FillWindowPixelBuffer(0, PIXEL_FILL(0));
            PutWindowTilemap(0);
            gMain.state++;
            break;
        case 2:
            sub_80BFCF4(0xD);
            sub_80BFD7C(2, 0xD);
            LoadPokedexBgPalette(sPokedexView->unk64C_1);
            gMain.state++;
            break;
        case 3:
            {
                u8 string[0x40];  //I hope this is the correct size

                StringCopy(string, gText_SizeComparedTo);
                StringAppend(string, gSaveBlock2Ptr->playerName);
                sub_80BE8DC(string, GetStringCenterAlignXOffset(1, string, 0xF0), 0x79);
                gMain.state++;
            }
            break;
        case 4:
            ResetPaletteFade();
            gMain.state++;
            break;
        case 5:
            spriteId = sub_80C0EF8(PlayerGenderToFrontTrainerPicId(gSaveBlock2Ptr->playerGender), 152, 56, 0);
            gSprites[spriteId].oam.affineMode = 1;
            gSprites[spriteId].oam.matrixNum = 1;
            gSprites[spriteId].oam.priority = 0;
            gSprites[spriteId].pos2.y = gPokedexEntries[sPokedexListItem->dexNum].trainerOffset;
            SetOamMatrix(1, gPokedexEntries[sPokedexListItem->dexNum].trainerScale, 0, 0, gPokedexEntries[sPokedexListItem->dexNum].trainerScale);
            LoadPalette(gUnknown_0856E610, (gSprites[spriteId].oam.paletteNum + 16) * 16, 0x20);
            gTasks[taskId].data[5] = spriteId;
            gMain.state++;
            break;
        case 6:
            spriteId = CreateMonSpriteFromNationalDexNumber(sPokedexListItem->dexNum, 88, 56, 1);
            gSprites[spriteId].oam.affineMode = 1;
            gSprites[spriteId].oam.matrixNum = 2;
            gSprites[spriteId].oam.priority = 0;
            gSprites[spriteId].pos2.y = gPokedexEntries[sPokedexListItem->dexNum].pokemonOffset;
            SetOamMatrix(2, gPokedexEntries[sPokedexListItem->dexNum].pokemonScale, 0, 0, gPokedexEntries[sPokedexListItem->dexNum].pokemonScale);
            LoadPalette(gUnknown_0856E610, (gSprites[spriteId].oam.paletteNum + 16) * 16, 0x20);
            gTasks[taskId].data[4] = spriteId;
            CopyWindowToVram(0, 3);
            CopyBgTilemapBufferToVram(1);
            CopyBgTilemapBufferToVram(2);
            CopyBgTilemapBufferToVram(3);
            gMain.state++;
            break;
        case 7:
            BeginNormalPaletteFade(0xFFFFFFEB, 0, 0x10, 0, RGB_BLACK);
            SetVBlankCallback(gUnknown_030060B4);
            gMain.state++;
            break;
        case 8:
            SetGpuReg(REG_OFFSET_BLDCNT, 0);
            SetGpuReg(REG_OFFSET_BLDALPHA, 0);
            SetGpuReg(REG_OFFSET_BLDY, 0);
            SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_1D_MAP | DISPCNT_OBJ_ON);
            HideBg(0);
            ShowBg(1);
            ShowBg(2);
            ShowBg(3);
            gMain.state++;
            break;
        case 9:
            if (!gPaletteFade.active)
            {
                sPokedexView->unk64E = 0;
                gMain.state = 0;
                gTasks[taskId].func = sub_80BFBB0;
            }
            break;
    }
}

void sub_80BFBB0(u8 taskId)
{
    if (gMain.newKeys & B_BUTTON)
    {
        BeginNormalPaletteFade(0xFFFFFFEB, 0, 0, 0x10, RGB_BLACK);
        sPokedexView->unk64E = 1;
        gTasks[taskId].func = sub_80BFC78;
        PlaySE(SE_PC_OFF);
    }
    else if ((gMain.newKeys & DPAD_LEFT)
     || ((gMain.newKeys & L_BUTTON) && gSaveBlock2Ptr->optionsButtonMode == OPTIONS_BUTTON_MODE_LR))
    {
        BeginNormalPaletteFade(0xFFFFFFEB, 0, 0, 0x10, RGB_BLACK);
        sPokedexView->unk64E = 2;
        gTasks[taskId].func = sub_80BFC78;
        PlaySE(SE_Z_PAGE);
    }
}

void sub_80BFC78(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        FreeAndDestroyMonPicSprite(gTasks[taskId].data[4]);
        FreeAndDestroyTrainerPicSprite(gTasks[taskId].data[5]);
        switch (sPokedexView->unk64E)
        {
            default:
            case 1:
                gTasks[taskId].func = sub_80BEA24;
                break;
            case 2:
                gTasks[taskId].func = sub_80BF250;
                break;
        }
    }
}

void sub_80BFCDC(u16 a)
{
    CopyToBgTilemapBuffer(1, gPokedexTilemap_ScreenSelectBar1, 0, 0);
}

void sub_80BFCF4(u16 a)
{
    CopyToBgTilemapBuffer(1, gPokedexTilemap_ScreenSelectBar2, 0, 0);
}
#ifdef NONMATCHING
// This doesn't match because gcc flips the naming of the r3 and r4
// registers.
void sub_80BFD0C(u8 a, u16 unused)
{
    u8 i;
    u8 j;
    u16* ptr = GetBgTilemapBuffer(1);

    for (i = 0; i < 4; i++)
    {
        u8 row = (i * 7) + 1;
        u16 newPalette = 0x4000;

        if (i == a)
            newPalette = 0x2000;

        for (j = 0; j < 7; j++)
        {
            ptr[row + j] = (ptr[row + j] % 0x1000) | newPalette;
            ptr[row + j + 0x20] = (ptr[row + j + 0x20] % 0x1000) | newPalette;
        }
    }
    CopyBgTilemapBufferToVram(1);
}
#else
__attribute__((naked))
void sub_80BFD0C(u8 a, u16 unused)
{
    asm(".syntax unified\n\
    push {r4-r7,lr}\n\
    mov r7, r8\n\
    push {r7}\n\
    lsls r0, 24\n\
    lsrs r0, 24\n\
    mov r8, r0\n\
    movs r0, 0x1\n\
    bl GetBgTilemapBuffer\n\
    adds r7, r0, 0\n\
    movs r1, 0\n\
_080BFD22:\n\
    lsls r0, r1, 3\n\
    subs r0, r1\n\
    adds r0, 0x1\n\
    lsls r0, 24\n\
    lsrs r5, r0, 24\n\
    movs r3, 0x80\n\
    lsls r3, 7\n\
    cmp r1, r8\n\
    bne _080BFD38\n\
    movs r3, 0x80\n\
    lsls r3, 6\n\
_080BFD38:\n\
    movs r2, 0\n\
    adds r6, r1, 0x1\n\
    ldr r4, =0x00000fff\n\
_080BFD3E:\n\
    adds r1, r5, r2\n\
    lsls r1, 1\n\
    adds r1, r7\n\
    ldrh r0, [r1]\n\
    ands r0, r4\n\
    orrs r0, r3\n\
    strh r0, [r1]\n\
    adds r1, 0x40\n\
    ldrh r0, [r1]\n\
    ands r0, r4\n\
    orrs r0, r3\n\
    strh r0, [r1]\n\
    adds r0, r2, 0x1\n\
    lsls r0, 24\n\
    lsrs r2, r0, 24\n\
    cmp r2, 0x6\n\
    bls _080BFD3E\n\
    lsls r0, r6, 24\n\
    lsrs r1, r0, 24\n\
    cmp r1, 0x3\n\
    bls _080BFD22\n\
    movs r0, 0x1\n\
    bl CopyBgTilemapBufferToVram\n\
    pop {r3}\n\
    mov r8, r3\n\
    pop {r4-r7}\n\
    pop {r0}\n\
    bx r0\n\
    .pool\n\
    .syntax divided\n");
}
#endif

#ifdef NONMATCHING
// This doesn't match because gcc flips the naming of the r3 and r4
// registers.
void sub_80BFD7C(u8 a, u16 b)
{
    u8 i;
    u8 j;
    u16* ptr = GetBgTilemapBuffer(1);

    for (i = 0; i < 4; i++)
    {
        u8 row = i * 7 + 1;
        u32 newPalette;

        if (i == a || i == 3)
            newPalette = 0x2000;
        else
            newPalette = 0x4000;

        for (j = 0; j < 7; j++)
        {
            ptr[row + j] = (ptr[row + j] % 0x1000) | newPalette;
            ptr[row + j + 0x20] = (ptr[row + j + 0x20] % 0x1000) | newPalette;
        }
    }
    CopyBgTilemapBufferToVram(1);
}
#else
__attribute__((naked))
void sub_80BFD7C(u8 a, u16 b)
{
    asm(".syntax unified\n\
    push {r4-r7,lr}\n\
    mov r7, r8\n\
    push {r7}\n\
    lsls r0, 24\n\
    lsrs r0, 24\n\
    mov r8, r0\n\
    movs r0, 0x1\n\
    bl GetBgTilemapBuffer\n\
    adds r7, r0, 0\n\
    movs r1, 0\n\
_080BFD92:\n\
    lsls r0, r1, 3\n\
    subs r0, r1\n\
    adds r0, 0x1\n\
    lsls r0, 24\n\
    lsrs r6, r0, 24\n\
    cmp r1, r8\n\
    beq _080BFDA4\n\
    cmp r1, 0x3\n\
    bne _080BFDAA\n\
_080BFDA4:\n\
    movs r3, 0x80\n\
    lsls r3, 6\n\
    b _080BFDAE\n\
_080BFDAA:\n\
    movs r3, 0x80\n\
    lsls r3, 7\n\
_080BFDAE:\n\
    movs r2, 0\n\
    adds r5, r1, 0x1\n\
    ldr r4, =0x00000fff\n\
_080BFDB4:\n\
    adds r1, r6, r2\n\
    lsls r1, 1\n\
    adds r1, r7\n\
    ldrh r0, [r1]\n\
    ands r0, r4\n\
    orrs r0, r3\n\
    strh r0, [r1]\n\
    adds r1, 0x40\n\
    ldrh r0, [r1]\n\
    ands r0, r4\n\
    orrs r0, r3\n\
    strh r0, [r1]\n\
    adds r0, r2, 0x1\n\
    lsls r0, 24\n\
    lsrs r2, r0, 24\n\
    cmp r2, 0x6\n\
    bls _080BFDB4\n\
    lsls r0, r5, 24\n\
    lsrs r1, r0, 24\n\
    cmp r1, 0x3\n\
    bls _080BFD92\n\
    movs r0, 0x1\n\
    bl CopyBgTilemapBufferToVram\n\
    pop {r3}\n\
    mov r8, r3\n\
    pop {r4-r7}\n\
    pop {r0}\n\
    bx r0\n\
    .pool\n\
    .syntax divided\n");
}
#endif

u8 CreateDexDisplayMonDataTask(u16 dexNum, u32 b, u32 c)
{
    u8 taskId = CreateTask(sub_80BFE38, 0);

    gTasks[taskId].data[0] = 0;
    gTasks[taskId].data[1] = dexNum;
    gTasks[taskId].data[12] = b;
    gTasks[taskId].data[13] = b >> 16;
    gTasks[taskId].data[14] = c;
    gTasks[taskId].data[15] = c >> 16;
    return taskId;
}

void sub_80BFE38(u8 taskId)
{
    u8 spriteId;
    u16 dexNum = gTasks[taskId].data[1];

    switch (gTasks[taskId].data[0])
    {
        case 0:
        default:
            if (!gPaletteFade.active)
            {
                gUnknown_030060B4 = gMain.vblankCallback;
                SetVBlankCallback(NULL);
                sub_80C09B0(0x100);
                ResetBgsAndClearDma3BusyFlags(0);
                InitBgsFromTemplates(0, gUnknown_0856E668, 2);
                SetBgTilemapBuffer(3, AllocZeroed(0x800));
                SetBgTilemapBuffer(2, AllocZeroed(0x800));
                InitWindows(gUnknown_0856E670);
                DeactivateAllTextPrinters();
                gTasks[taskId].data[0] = 1;
            }
            break;
        case 1:
            DecompressAndLoadBgGfxUsingHeap(3, gPokedexMenu_Gfx, 0x2000, 0, 0);
            CopyToBgTilemapBuffer(3, gPokedexTilemap_DescriptionScreen, 0, 0);
            FillWindowPixelBuffer(0, PIXEL_FILL(0));
            PutWindowTilemap(0);
            PutWindowTilemap(1);
            sub_80C0D30(1, gTasks[taskId].data[1]);
            CopyWindowToVram(1, 2);
            ResetPaletteFade();
            LoadPokedexBgPalette(0);
            gTasks[taskId].data[0]++;
            break;
        case 2:
            gTasks[taskId].data[0]++;
            break;
        case 3:
            sub_80C020C(dexNum, IsNationalPokedexEnabled(), 1, 1);
            CopyWindowToVram(0, 3);
            CopyBgTilemapBufferToVram(2);
            CopyBgTilemapBufferToVram(3);
            gTasks[taskId].data[0]++;
            break;
        case 4:
            spriteId = CreateMonSpriteFromNationalDexNumber(dexNum, 48, 56, 0);
            gSprites[spriteId].oam.priority = 0;
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 0x10, 0, RGB_BLACK);
            SetVBlankCallback(gUnknown_030060B4);
            gTasks[taskId].data[3] = spriteId;
            gTasks[taskId].data[0]++;
            break;
        case 5:
            SetGpuReg(REG_OFFSET_BLDCNT, 0);
            SetGpuReg(REG_OFFSET_BLDALPHA, 0);
            SetGpuReg(REG_OFFSET_BLDY, 0);
            SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_1D_MAP | DISPCNT_OBJ_ON);
            ShowBg(2);
            ShowBg(3);
            gTasks[taskId].data[0]++;
            break;
        case 6:
            if (!gPaletteFade.active)
            {
                PlayCry1(NationalPokedexNumToSpecies(dexNum), 0);
                gTasks[taskId].data[2] = 0;
                gTasks[taskId].func = sub_80C0088;
            }
            break;
    }
}

void sub_80C0088(u8 taskId)
{
    if (gMain.newKeys & (A_BUTTON | B_BUTTON))
    {
        BeginNormalPaletteFade(0x0000FFFF, 0, 0, 16, RGB_BLACK);
        gSprites[gTasks[taskId].data[3]].callback = sub_80C01CC;
        gTasks[taskId].func = blockset_load_palette_to_gpu;
    }
    else if (++gTasks[taskId].data[2] & 0x10)
    {
        LoadPalette(gPokedexText_Pal + 1, 0x31, 14);
    }
    else
    {
        LoadPalette(gPokedexCaughtScreenFade_Pal + 1, 0x31, 14);
    }
}

void blockset_load_palette_to_gpu(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        u16 species;
        u32 otId;
        u32 personality;
        u8 paletteNum;
        const u32 *lzPaletteData;
        void *buffer;

        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_1D_MAP | DISPCNT_OBJ_ON);
        FreeAllWindowBuffers();
        buffer = GetBgTilemapBuffer(2);
        if (buffer)
            Free(buffer);
        buffer = GetBgTilemapBuffer(3);
        if (buffer)
            Free(buffer);

        species = NationalPokedexNumToSpecies(gTasks[taskId].data[1]);
        otId = ((u16)gTasks[taskId].data[13] << 16) | (u16)gTasks[taskId].data[12];
        personality = ((u16)gTasks[taskId].data[15] << 16) | (u16)gTasks[taskId].data[14];
        paletteNum = gSprites[gTasks[taskId].data[3]].oam.paletteNum;
        lzPaletteData = GetFrontSpritePalFromSpeciesAndPersonality(species, otId, personality);
        LoadCompressedPalette(lzPaletteData, 0x100 | paletteNum * 16, 32);
        DestroyTask(taskId);
    }
}

void sub_80C01CC(struct Sprite *sprite)
{
    if (sprite->pos1.x < 0x78)
        sprite->pos1.x += 2;
    if (sprite->pos1.x > 0x78)
        sprite->pos1.x -= 2;

    if (sprite->pos1.y < 0x50)
        sprite->pos1.y += 1;
    if (sprite->pos1.y > 0x50)
        sprite->pos1.y -= 1;
}

void sub_80C020C(u32 num, u32 value, u32 c, u32 d)
{
    u8 str[0x10];
    u8 str2[0x30];
    u16 natNum;
    const u8 *text;
    const u8 *text2;
    const u8 *text3;

    if (d)
        sub_80BE8DC(gText_PokedexRegistration, GetStringCenterAlignXOffset(1, gText_PokedexRegistration, 0xF0), 0);
    if (value == 0)
        value = NationalToHoennOrder(num);
    else
        value = num;
    ConvertIntToDecimalStringN(StringCopy(str, gText_UnkCtrlF908Clear01), value, 2, 3);
    sub_80BE8DC(str, 0x60, 0x19);
    natNum = NationalPokedexNumToSpecies(num);
    if (natNum)
        text = gSpeciesNames[natNum];
    else
        text = sText_TenDashes2;
    sub_80BE8DC(text, 0x84, 0x19);
    if (c)
    {
        CopyMonCategoryText(num, str2);
        text2 = str2;
    }
    else
    {
        text2 = gText_5MarksPokemon;
    }
    sub_80BE8DC(text2, 0x64, 0x29);
    sub_80BE8DC(gText_HTHeight, 0x60, 0x39);
    sub_80BE8DC(gText_WTWeight, 0x60, 0x49);
    if (c)
    {
        sub_80C0354(gPokedexEntries[num].height, 0x81, 0x39);
        sub_80C0460(gPokedexEntries[num].weight, 0x81, 0x49);
    }
    else
    {
        sub_80BE8DC(gText_UnkHeight, 0x81, 0x39);
        sub_80BE8DC(gText_UnkWeight, 0x81, 0x49);
    }
    if (c)
        text3 = gPokedexEntries[num].description;
    else
        text3 = gExpandedPlaceholder_PokedexDescription;
    sub_80BE8DC(text3, GetStringCenterAlignXOffset(1, text3, 0xF0), 0x5F);
}

void sub_80C0354(u16 height, u8 left, u8 top)
{
    u8 buffer[16];
    u32 inches, feet;
    u8 i = 0;

    inches = (height * 10000) / 254;
    if (inches % 10 >= 5)
        inches += 10;
    feet = inches / 120;
    inches = (inches - (feet * 120)) / 10;

    buffer[i++] = EXT_CTRL_CODE_BEGIN;
    buffer[i++] = 0x13;
    if (feet / 10 == 0)
    {
        buffer[i++] = 18;
        buffer[i++] = feet + CHAR_0;
    }
    else
    {
        buffer[i++] = 12;
        buffer[i++] = feet / 10 + CHAR_0;
        buffer[i++] = (feet % 10) + CHAR_0;
    }
    buffer[i++] = CHAR_SGL_QUOT_RIGHT;
    buffer[i++] = (inches / 10) + CHAR_0;
    buffer[i++] = (inches % 10) + CHAR_0;
    buffer[i++] = CHAR_DBL_QUOT_RIGHT;
    buffer[i++] = EOS;
    sub_80BE8DC(buffer, left, top);
}

#ifdef NONMATCHING
// This doesn't match because gcc manages to avoid using the stack
// to store local variables.
void sub_80C0460(u16 weight, u8 left, u8 top)
{
    u8 buffer[16];
    bool8 output;
    u8 i = 0;
    u32 lbs = (weight * 100000) / 4536;

    if (lbs % 10u >= 5)
        lbs += 10;
    output = FALSE;

    buffer[i] = (lbs / 100000) + CHAR_0;
    if (buffer[i] == CHAR_0)
    {
        buffer[i++] = 0x77;
    }
    else
    {
        output = TRUE;
        i++;
    }

    lbs %= 100000;
    buffer[i] = (lbs / 10000) + CHAR_0;
    if (buffer[i] == CHAR_0 && !output)
    {
        buffer[i++] = 0x77;
    }
    else
    {
        output = TRUE;
        i++;
    }

    lbs %= 10000;
    buffer[i] = (lbs / 1000) + CHAR_0;
    if (buffer[i] == CHAR_0 && !output)
    {
        buffer[i++] = 0x77;
    }
    else
    {
        i++;
    }

    lbs %= 1000;
    buffer[i++] = (lbs / 100) + CHAR_0;
    lbs %= 100;
    buffer[i++] = CHAR_PERIOD;
    buffer[i++] = (lbs / 10) + CHAR_0;
    buffer[i++] = CHAR_SPACE;
    buffer[i++] = CHAR_l;
    buffer[i++] = CHAR_b;
    buffer[i++] = CHAR_s;
    buffer[i++] = CHAR_PERIOD;
    buffer[i++] = EOS;
    sub_80BE8DC(buffer, left, top);
}
#else
__attribute__((naked))
void sub_80C0460(u16 weight, u8 left, u8 top)
{
    asm(".syntax unified\n\
    push {r4-r7,lr}\n\
    mov r7, r10\n\
    mov r6, r9\n\
    mov r5, r8\n\
    push {r5-r7}\n\
    sub sp, 0x14\n\
    lsls r0, 16\n\
    lsrs r0, 16\n\
    lsls r1, 24\n\
    lsrs r1, 24\n\
    mov r10, r1\n\
    lsls r2, 24\n\
    lsrs r2, 24\n\
    str r2, [sp, 0x10]\n\
    ldr r5, =0x000186a0\n\
    muls r0, r5\n\
    ldr r1, =0x000011b8\n\
    bl __divsi3\n\
    adds r7, r0, 0\n\
    movs r1, 0xA\n\
    bl __umodsi3\n\
    cmp r0, 0x4\n\
    bls _080C0494\n\
    adds r7, 0xA\n\
_080C0494:\n\
    movs r0, 0\n\
    mov r8, r0\n\
    mov r4, sp\n\
    adds r0, r7, 0\n\
    adds r1, r5, 0\n\
    bl __udivsi3\n\
    adds r0, 0xA1\n\
    strb r0, [r4]\n\
    lsls r0, 24\n\
    lsrs r0, 24\n\
    cmp r0, 0xA1\n\
    bne _080C04C0\n\
    movs r6, 0x1\n\
    mov r1, sp\n\
    movs r0, 0x77\n\
    strb r0, [r1]\n\
    b _080C04C6\n\
    .pool\n\
_080C04C0:\n\
    movs r1, 0x1\n\
    mov r8, r1\n\
    movs r6, 0x1\n\
_080C04C6:\n\
    ldr r1, =0x000186a0\n\
    adds r0, r7, 0\n\
    bl __umodsi3\n\
    adds r7, r0, 0\n\
    mov r4, sp\n\
    adds r4, 0x1\n\
    ldr r1, =0x00002710\n\
    bl __udivsi3\n\
    adds r0, 0xA1\n\
    strb r0, [r4]\n\
    lsls r0, 24\n\
    lsrs r0, 24\n\
    cmp r0, 0xA1\n\
    bne _080C0504\n\
    mov r2, r8\n\
    cmp r2, 0\n\
    bne _080C0504\n\
    adds r1, r6, 0\n\
    adds r0, r1, 0x1\n\
    lsls r0, 24\n\
    lsrs r6, r0, 24\n\
    add r1, sp\n\
    movs r0, 0x77\n\
    strb r0, [r1]\n\
    b _080C050E\n\
    .pool\n\
_080C0504:\n\
    movs r3, 0x1\n\
    mov r8, r3\n\
    adds r0, r6, 0x1\n\
    lsls r0, 24\n\
    lsrs r6, r0, 24\n\
_080C050E:\n\
    ldr r1, =0x00002710\n\
    adds r0, r7, 0\n\
    bl __umodsi3\n\
    adds r7, r0, 0\n\
    mov r0, sp\n\
    adds r4, r0, r6\n\
    movs r1, 0xFA\n\
    lsls r1, 2\n\
    adds r0, r7, 0\n\
    bl __udivsi3\n\
    adds r0, 0xA1\n\
    strb r0, [r4]\n\
    lsls r0, 24\n\
    lsrs r0, 24\n\
    cmp r0, 0xA1\n\
    bne _080C054C\n\
    mov r1, r8\n\
    cmp r1, 0\n\
    bne _080C054C\n\
    adds r1, r6, 0\n\
    adds r0, r1, 0x1\n\
    lsls r0, 24\n\
    lsrs r6, r0, 24\n\
    add r1, sp\n\
    movs r0, 0x77\n\
    strb r0, [r1]\n\
    b _080C0552\n\
    .pool\n\
_080C054C:\n\
    adds r0, r6, 0x1\n\
    lsls r0, 24\n\
    lsrs r6, r0, 24\n\
_080C0552:\n\
    movs r1, 0xFA\n\
    lsls r1, 2\n\
    adds r0, r7, 0\n\
    bl __umodsi3\n\
    adds r7, r0, 0\n\
    adds r1, r6, 0\n\
    adds r0, r1, 0x1\n\
    lsls r0, 24\n\
    lsrs r6, r0, 24\n\
    adds r5, r6, 0\n\
    mov r2, sp\n\
    adds r4, r2, r1\n\
    adds r0, r7, 0\n\
    movs r1, 0x64\n\
    bl __udivsi3\n\
    adds r0, 0xA1\n\
    movs r3, 0\n\
    mov r9, r3\n\
    strb r0, [r4]\n\
    adds r0, r7, 0\n\
    movs r1, 0x64\n\
    bl __umodsi3\n\
    adds r7, r0, 0\n\
    adds r0, r5, 0x1\n\
    lsls r0, 24\n\
    lsrs r6, r0, 24\n\
    adds r1, r6, 0\n\
    mov r2, sp\n\
    adds r0, r2, r5\n\
    movs r3, 0xAD\n\
    mov r8, r3\n\
    mov r2, r8\n\
    strb r2, [r0]\n\
    adds r0, r1, 0x1\n\
    lsls r0, 24\n\
    lsrs r6, r0, 24\n\
    adds r5, r6, 0\n\
    mov r3, sp\n\
    adds r4, r3, r1\n\
    adds r0, r7, 0\n\
    movs r1, 0xA\n\
    bl __udivsi3\n\
    adds r0, 0xA1\n\
    strb r0, [r4]\n\
    adds r0, r5, 0x1\n\
    lsls r0, 24\n\
    lsrs r6, r0, 24\n\
    adds r1, r6, 0\n\
    mov r2, sp\n\
    adds r0, r2, r5\n\
    mov r3, r9\n\
    strb r3, [r0]\n\
    adds r0, r1, 0x1\n\
    lsls r0, 24\n\
    lsrs r6, r0, 24\n\
    adds r2, r6, 0\n\
    add r1, sp\n\
    movs r0, 0xE0\n\
    strb r0, [r1]\n\
    adds r0, r2, 0x1\n\
    lsls r0, 24\n\
    lsrs r6, r0, 24\n\
    adds r3, r6, 0\n\
    mov r0, sp\n\
    adds r1, r0, r2\n\
    movs r0, 0xD6\n\
    strb r0, [r1]\n\
    adds r0, r3, 0x1\n\
    lsls r0, 24\n\
    lsrs r6, r0, 24\n\
    adds r2, r6, 0\n\
    mov r0, sp\n\
    adds r1, r0, r3\n\
    movs r0, 0xE7\n\
    strb r0, [r1]\n\
    adds r0, r2, 0x1\n\
    lsls r0, 24\n\
    lsrs r0, 24\n\
    mov r3, sp\n\
    adds r1, r3, r2\n\
    mov r2, r8\n\
    strb r2, [r1]\n\
    adds r1, r3, r0\n\
    movs r0, 0xFF\n\
    strb r0, [r1]\n\
    mov r0, sp\n\
    mov r1, r10\n\
    ldr r2, [sp, 0x10]\n\
    bl sub_80BE8DC\n\
    add sp, 0x14\n\
    pop {r3-r5}\n\
    mov r8, r3\n\
    mov r9, r4\n\
    mov r10, r5\n\
    pop {r4-r7}\n\
    pop {r0}\n\
    bx r0\n\
    .syntax divided\n");
}
#endif

const u8 *sub_80C0620(u16 dexNum)
{
    return gPokedexEntries[dexNum].categoryName;
}

u16 GetPokedexHeightWeight(u16 dexNum, u8 data)
{
    switch (data)
    {
        case 0:  // height
            return gPokedexEntries[dexNum].height;
        case 1:  // weight
            return gPokedexEntries[dexNum].weight;
        default:
            return 1;
    }
}

s8 GetSetPokedexFlag(u16 nationalDexNo, u8 caseID)
{
    u32 index, bit, mask;
    s8 retVal = 0;

    nationalDexNo--;
    index = nationalDexNo / 8;
    bit = nationalDexNo % 8;
    mask = 1 << bit;

    switch (caseID)
    {
    case FLAG_GET_SEEN:
        retVal = ((gSaveBlock1Ptr->dexSeen[index] & mask) != 0);
        break;
    case FLAG_GET_CAUGHT:
         retVal = ((gSaveBlock1Ptr->dexCaught[index] & mask) != 0);
        break;
    case FLAG_SET_SEEN:
        gSaveBlock1Ptr->dexSeen[index] |= mask;
        break;
    case FLAG_SET_CAUGHT:
        gSaveBlock1Ptr->dexCaught[index] |= mask;
        break;
    }

    return retVal;
}

u16 GetNationalPokedexCount(u8 caseID)
{
    u16 count = 0;
    u16 i;

    for (i = 0; i < NATIONAL_DEX_COUNT; i++)
    {
        switch (caseID)
        {
        case FLAG_GET_SEEN:
            if (GetSetPokedexFlag(i + 1, FLAG_GET_SEEN))
                count++;
            break;
        case FLAG_GET_CAUGHT:
            if (GetSetPokedexFlag(i + 1, FLAG_GET_CAUGHT))
                count++;
            break;
        }
    }
    return count;
}

u16 GetHoennPokedexCount(u8 caseID)
{
    u16 count = 0;
    u16 i;

    for (i = 0; i < HOENN_DEX_COUNT; i++)
    {
        switch (caseID)
        {
        case FLAG_GET_SEEN:
            if (GetSetPokedexFlag(HoennToNationalOrder(i + 1), FLAG_GET_SEEN))
                count++;
            break;
        case FLAG_GET_CAUGHT:
            if (GetSetPokedexFlag(HoennToNationalOrder(i + 1), FLAG_GET_CAUGHT))
                count++;
            break;
        }
    }
    return count;
}

u16 sub_80C089C(u8 caseID)
{
    u16 count = 0;
    u16 i;

    for (i = 0; i < 151; i++)
    {
        switch (caseID)
        {
            case FLAG_GET_SEEN:
                if (GetSetPokedexFlag(i + 1, FLAG_GET_SEEN))
                    count++;
                break;
            case FLAG_GET_CAUGHT:
                if (GetSetPokedexFlag(i + 1, FLAG_GET_CAUGHT))
                    count++;
                break;
        }
    }
    return count;
}

bool16 HasAllHoennMons(void)
{
    u16 i;

    for (i = 0; i < 200; i++)
    {
        if (!GetSetPokedexFlag(HoennToNationalOrder(i + 1), FLAG_GET_CAUGHT))
            return FALSE;
    }
    return TRUE;
}

bool8 sub_80C0918(void)
{
    u16 i;

    for (i = 0; i < 150; i++)
    {
        if (!GetSetPokedexFlag(i + 1, FLAG_GET_CAUGHT))
            return FALSE;
    }
    return TRUE;
}

u16 sub_80C0944(void)
{
    u16 i;

    for (i = 0; i < 150; i++)
    {
        if (!GetSetPokedexFlag(i + 1, FLAG_GET_CAUGHT))
            return 0;
    }
    for (i = 151; i < 248; i++)
    {
        if (!GetSetPokedexFlag(i + 1, FLAG_GET_CAUGHT))
            return 0;
    }
    for (i = 251; i < 384; i++)
    {
        if (!GetSetPokedexFlag(i + 1, FLAG_GET_CAUGHT))
            return 0;
    }
    return 1;
}

void sub_80C09B0(u16 a)
{
    if (!(a & DISPCNT_BG0_ON))
    {
        ClearGpuRegBits(0, DISPCNT_BG0_ON);
        SetGpuReg(REG_OFFSET_BG0CNT, 0);
        SetGpuReg(REG_OFFSET_BG0HOFS, 0);
        SetGpuReg(REG_OFFSET_BG0VOFS, 0);
    }
    if (!(a & DISPCNT_BG1_ON))
    {
        ClearGpuRegBits(0, DISPCNT_BG1_ON);
        SetGpuReg(REG_OFFSET_BG1CNT, 0);
        SetGpuReg(REG_OFFSET_BG1HOFS, 0);
        SetGpuReg(REG_OFFSET_BG1VOFS, 0);
    }
    if (!(a & DISPCNT_BG2_ON))
    {
        ClearGpuRegBits(0, DISPCNT_BG2_ON);
        SetGpuReg(REG_OFFSET_BG2CNT, 0);
        SetGpuReg(REG_OFFSET_BG2HOFS, 0);
        SetGpuReg(REG_OFFSET_BG2VOFS, 0);
    }
    if (!(a & DISPCNT_BG3_ON))
    {
        ClearGpuRegBits(0, DISPCNT_BG3_ON);
        SetGpuReg(REG_OFFSET_BG3CNT, 0);
        SetGpuReg(REG_OFFSET_BG3HOFS, 0);
        SetGpuReg(REG_OFFSET_BG3VOFS, 0);
    }
    if (!(a & DISPCNT_OBJ_ON))
    {
        ClearGpuRegBits(0, DISPCNT_OBJ_ON);
        ResetSpriteData();
        FreeAllSpritePalettes();
        gReservedSpritePaletteCount = 8;
    }
}

void sub_80C0A88(u8 windowId, const u8 *str, u8 left, u8 top)
{
    u8 color[3];
    color[0] = 0;
    color[1] = 15;
    color[2] = 3;

    AddTextPrinterParameterized4(windowId, 1, left, top, 0, 0, color, -1, str);
}

void sub_80C0AC4(u8 windowId, u16 order, u8 left, u8 top)
{
    u8 str[4];

    str[0] = CHAR_0 + order / 100;
    str[1] = CHAR_0 + (order % 100) / 10;
    str[2] = CHAR_0 + (order % 100) % 10;
    str[3] = EOS;
    sub_80C0A88(windowId, str, left, top);
}

u8 sub_80C0B44(u8 windowId, u16 num, u8 left, u8 top)
{
    u8 str[11];
    u8 i;

    for (i = 0; i < 11; i++)
        str[i] = EOS;
    num = NationalPokedexNumToSpecies(num);
    switch (num)
    {
        default:
            for (i = 0; gSpeciesNames[num][i] != EOS && i < 10; i++)
                str[i] = gSpeciesNames[num][i];
            break;
        case 0:
            for (i = 0; i < 5; i++)
                str[i] = CHAR_HYPHEN;
            break;
    }
    sub_80C0A88(windowId, str, left, top);
    return i;
}

void sub_80C0BF0(u8 windowId, const u8* str, u8 left, u8 top)
{
    u8 str2[11];
    u8 i;
    u8 count;

    for (i = 0; i < 11; i++)
        str2[i] = CHAR_SPACE;
    for (count = 0; str[count] != CHAR_SPACE && count < 11; count++)
        ;
    for (i = 0; i < count; i++)
        str2[11 - count + i] = str[i];
    str2[11] = EOS;
    sub_80C0A88(windowId, str2, left, top);
}

void sub_80C0C6C(u8 windowId, u16 b, u8 left, u8 top)
{
    u8 str[6];
    bool8 outputted = FALSE;
    u8 result;

    result = b / 1000;
    if (result == 0)
    {
        str[0] = 0x77;
        outputted = FALSE;
    }
    else
    {
        str[0] = CHAR_0 + result;
        outputted = TRUE;
    }

    result = (b % 1000) / 100;
    if (result == 0 && !outputted)
    {
        str[1] = 0x77;
        outputted = FALSE;
    }
    else
    {
        str[1] = CHAR_0 + result;
        outputted = TRUE;
    }

    str[2] = CHAR_0 + ((b % 1000) % 100) / 10;
    str[3] = CHAR_PERIOD;
    str[4] = CHAR_0 + ((b % 1000) % 100) % 10;
    str[5] = EOS;
    sub_80C0A88(windowId, str, left, top);
}

void sub_80C0D30(u8 windowId, u16 a1)
{
    u8 image[32 * 4] = {0};
    const u8 * r12 = gMonFootprintTable[NationalPokedexNumToSpecies(a1)];
    u16 r5 = 0;
    u16 i;
    u16 j;

    if (r12 != NULL)
    {
        for (i = 0; i < 32; i++)
        {
            u8 r3 = r12[i];
            for (j = 0; j < 4; j++)
            {
                u8 value = ((r3 >> (2 * j)) & 1 ? 2 : 0);
                if ((2 << (2 * j)) & r3)
                    value |= 0x20;
                image[r5] = value;
                r5++;
            }
        }
    }
    CopyToWindowPixelBuffer(windowId, image, sizeof(image), 0);
}

void sub_80C0DC0(u16 a, u16 b)
{
    *(u16 *)(VRAM + a * 0x800 + 0x232) = 0xF000 + b + 0;
    *(u16 *)(VRAM + a * 0x800 + 0x234) = 0xF000 + b + 1;
    *(u16 *)(VRAM + a * 0x800 + 0x272) = 0xF000 + b + 2;
    *(u16 *)(VRAM + a * 0x800 + 0x274) = 0xF000 + b + 3;
}

u16 sub_80C0E0C(u8 a, u16 b, u16 c, u16 d)
{
    switch (a)
    {
        case 1:
            if (b > c)
                b--;
            break;
        case 0:
            if (b < d)
                b++;
            break;
        case 3:
            if (b > c)
                b--;
            else
                b = d;
            break;
        case 2:
            if (b < d)
                b++;
            else
                b = c;
            break;
    }
    return b;
}

u32 sub_80C0E68(u16 a)
{
    if (a == SPECIES_UNOWN || a == SPECIES_SPINDA)
    {
        if (a == SPECIES_UNOWN)
            return gSaveBlock2Ptr->pokedex.unownPersonality;
        else
            return gSaveBlock2Ptr->pokedex.spindaPersonality;
    }
    else
    {
        return 0;
    }
}

u16 CreateMonSpriteFromNationalDexNumber(u16 nationalNum, s16 x, s16 y, u16 paletteSlot)
{
    nationalNum = NationalPokedexNumToSpecies(nationalNum);
    return CreateMonPicSprite_HandleDeoxys(nationalNum, 8, sub_80C0E68(nationalNum), TRUE, x, y, paletteSlot, 0xFFFF);
}

u16 sub_80C0EF8(u16 species, s16 x, s16 y, s8 paletteSlot)
{
    return CreateTrainerPicSprite(species, TRUE, x, y, paletteSlot, 0xFFFF);
}

int sub_80C0F30(u8 dexMode, u8 sortMode, u8 abcGroup, u8 bodyColor, u8 type1, u8 type2)
{
    u16 species;
    u16 i;
    u16 resultsCount;
    u8 types[2];

    sub_80BC8D4(dexMode, sortMode);

    for (i = 0, resultsCount = 0; i < NATIONAL_DEX_COUNT; i++)
    {
        if (sPokedexView->pokedexList[i].seen)
        {
            sPokedexView->pokedexList[resultsCount] = sPokedexView->pokedexList[i];
            resultsCount++;
        }
    }
    sPokedexView->pokemonListCount = resultsCount;

    // Search by name
    if (abcGroup != 0xFF)
    {
        for (i = 0, resultsCount = 0; i < sPokedexView->pokemonListCount; i++)
        {
            u8 r3;

            species = NationalPokedexNumToSpecies(sPokedexView->pokedexList[i].dexNum);
            r3 = gSpeciesNames[species][0];
            if ((r3 >= gUnknown_0856ED08[abcGroup][0] && r3 < gUnknown_0856ED08[abcGroup][0] + gUnknown_0856ED08[abcGroup][1])
             || (r3 >= gUnknown_0856ED08[abcGroup][2] && r3 < gUnknown_0856ED08[abcGroup][2] + gUnknown_0856ED08[abcGroup][3]))
            {
                sPokedexView->pokedexList[resultsCount] = sPokedexView->pokedexList[i];
                resultsCount++;
            }
        }
        sPokedexView->pokemonListCount = resultsCount;
    }

    // Search by body color
    if (bodyColor != 0xFF)
    {
        for (i = 0, resultsCount = 0; i < sPokedexView->pokemonListCount; i++)
        {
            species = NationalPokedexNumToSpecies(sPokedexView->pokedexList[i].dexNum);

            if (bodyColor == gBaseStats[species].bodyColor)
            {
                sPokedexView->pokedexList[resultsCount] = sPokedexView->pokedexList[i];
                resultsCount++;
            }
        }
        sPokedexView->pokemonListCount = resultsCount;
    }

    // Search by type
    if (type1 != TYPE_NONE || type2 != TYPE_NONE)
    {
        if (type1 == TYPE_NONE)
        {
            type1 = type2;
            type2 = TYPE_NONE;
        }

        if (type2 == TYPE_NONE)
        {
            for (i = 0, resultsCount = 0; i < sPokedexView->pokemonListCount; i++)
            {
                if (sPokedexView->pokedexList[i].owned)
                {
                    species = NationalPokedexNumToSpecies(sPokedexView->pokedexList[i].dexNum);

                    types[0] = gBaseStats[species].type1;
                    types[1] = gBaseStats[species].type2;
                    if (types[0] == type1 || types[1] == type1)
                    {
                        sPokedexView->pokedexList[resultsCount] = sPokedexView->pokedexList[i];
                        resultsCount++;
                    }
                }
            }
        }
        else
        {
            for (i = 0, resultsCount = 0; i < sPokedexView->pokemonListCount; i++)
            {
                if (sPokedexView->pokedexList[i].owned)
                {
                    species = NationalPokedexNumToSpecies(sPokedexView->pokedexList[i].dexNum);

                    types[0] = gBaseStats[species].type1;
                    types[1] = gBaseStats[species].type2;
                    if ((types[0] == type1 && types[1] == type2) || (types[0] == type2 && types[1] == type1))
                    {
                        sPokedexView->pokedexList[resultsCount] = sPokedexView->pokedexList[i];
                        resultsCount++;
                    }
                }
            }
        }
        sPokedexView->pokemonListCount = resultsCount;
    }

    if (sPokedexView->pokemonListCount != 0)
    {
        for (i = sPokedexView->pokemonListCount; i < NATIONAL_DEX_COUNT; i++)
        {
            sPokedexView->pokedexList[i].dexNum = 0xFFFF;
            sPokedexView->pokedexList[i].seen = FALSE;
            sPokedexView->pokedexList[i].owned = FALSE;
        }
    }

    return resultsCount;
}

u8 sub_80C1258(void)
{
    return CreateTask(sub_80C12E0, 0);
}

void sub_80C1270(const u8 *str, u32 left, u32 top)
{
    u8 color[3];

    color[0] = 0;
    color[1] = 15;
    color[2] = 2;
    AddTextPrinterParameterized4(0, 1, left, top, 0, 0, color, -1, str);
}

void sub_80C12B0(u32 x, u32 y, u32 width, u32 height)
{
    FillWindowPixelRect(0, PIXEL_FILL(0), x, y, width, height);
}

void sub_80C12E0(u8 taskId)
{
    u16 i;

    switch (gMain.state)
    {
        default:
        case 0:
            if (!gPaletteFade.active)
            {
                sPokedexView->unk64A = 2;
                sub_80C09B0(0);
                ResetBgsAndClearDma3BusyFlags(0);
                InitBgsFromTemplates(0, gUnknown_0856EFF8, 4);
                SetBgTilemapBuffer(3, AllocZeroed(0x800));
                SetBgTilemapBuffer(2, AllocZeroed(0x800));
                SetBgTilemapBuffer(1, AllocZeroed(0x800));
                SetBgTilemapBuffer(0, AllocZeroed(0x800));
                InitWindows(gUnknown_0856F008);
                DeactivateAllTextPrinters();
                PutWindowTilemap(0);
                DecompressAndLoadBgGfxUsingHeap(3, gPokedexSearchMenu_Gfx, 0x2000, 0, 0);

                if (!IsNationalPokedexEnabled())
                    CopyToBgTilemapBuffer(3, gPokedexSearch2_Tilemap, 0, 0);
                else
                    CopyToBgTilemapBuffer(3, gPokedexSearch1_Tilemap, 0, 0);
                LoadPalette(gPokedexSearchMenu_Pal + 1, 1, 0x7E);
                gMain.state = 1;
            }
            break;
        case 1:
            LoadCompressedSpriteSheet(sInterfaceSpriteSheet);
            LoadSpritePalettes(sInterfaceSpritePalette);
            sub_80C2594(taskId);
            for (i = 0; i < 16; i++)
                gTasks[taskId].data[i] = 0;
            sub_80C23B8(taskId);
            sub_80C2040(0);
            sub_80C20F8(taskId);
            CopyWindowToVram(0, 3);
            CopyBgTilemapBufferToVram(1);
            CopyBgTilemapBufferToVram(2);
            CopyBgTilemapBufferToVram(3);
            gMain.state++;
            break;
        case 2:
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 16, 0, RGB_BLACK);
            gMain.state++;
            break;
        case 3:
            SetGpuReg(REG_OFFSET_BLDCNT, 0);
            SetGpuReg(REG_OFFSET_BLDALPHA, 0);
            SetGpuReg(REG_OFFSET_BLDY, 0);
            SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_1D_MAP | DISPCNT_OBJ_ON);
            HideBg(0);
            ShowBg(1);
            ShowBg(2);
            ShowBg(3);
            gMain.state++;
            break;
        case 4:
            if (!gPaletteFade.active)
            {
                gTasks[taskId].func = sub_80C1570;
                gMain.state = 0;
            }
            break;
    }
}

void sub_80C152C(void)
{
    void* tilemapBuffer;

    FreeAllWindowBuffers();
    tilemapBuffer = GetBgTilemapBuffer(0);
    if (tilemapBuffer)
        Free(tilemapBuffer);
    tilemapBuffer = GetBgTilemapBuffer(1);
    if (tilemapBuffer)
        Free(tilemapBuffer);
    tilemapBuffer = GetBgTilemapBuffer(2);
    if (tilemapBuffer)
        Free(tilemapBuffer);
    tilemapBuffer = GetBgTilemapBuffer(3);
    if (tilemapBuffer)
        Free(tilemapBuffer);
}

void sub_80C1570(u8 taskId)
{
    sub_80C2040(gTasks[taskId].data[0]);
    sub_80C20F8(taskId);
    CopyWindowToVram(0, 2);
    CopyBgTilemapBufferToVram(3);
    gTasks[taskId].func = sub_80C15B0;
}

void sub_80C15B0(u8 taskId)
{
    if (gMain.newKeys & B_BUTTON)
    {
        PlaySE(SE_PC_OFF);
        gTasks[taskId].func = sub_80C1D38;
        return;
    }
    if (gMain.newKeys & A_BUTTON)
    {
        switch (gTasks[taskId].data[0])
        {
            case 0:
                PlaySE(SE_PIN);
                gTasks[taskId].data[1] = 0;
                gTasks[taskId].func = sub_80C16CC;
                break;
            case 1:
                PlaySE(SE_PIN);
                gTasks[taskId].data[1] = 4;
                gTasks[taskId].func = sub_80C16CC;
                break;
            case 2:
                PlaySE(SE_PC_OFF);
                gTasks[taskId].func = sub_80C1D38;
                break;
        }
        return;
    }
    if ((gMain.newKeys & DPAD_LEFT) && gTasks[taskId].data[0] > 0)
    {
        PlaySE(SE_Z_PAGE);
        gTasks[taskId].data[0]--;
        sub_80C2040(gTasks[taskId].data[0]);
        CopyWindowToVram(0, 2);
        CopyBgTilemapBufferToVram(3);
    }
    if ((gMain.newKeys & DPAD_RIGHT) && gTasks[taskId].data[0] < 2)
    {
        PlaySE(SE_Z_PAGE);
        gTasks[taskId].data[0]++;
        sub_80C2040(gTasks[taskId].data[0]);
        CopyWindowToVram(0, 2);
        CopyBgTilemapBufferToVram(3);
    }
}

void sub_80C16CC(u8 taskId)
{
    sub_80C2064(gTasks[taskId].data[0], gTasks[taskId].data[1]);
    sub_80C20F8(taskId);
    CopyWindowToVram(0, 2);
    CopyBgTilemapBufferToVram(3);
    gTasks[taskId].func = sub_80C170C;
}

void sub_80C170C(u8 taskId)
{
    const u8 (*r6)[4];

    if (gTasks[taskId].data[0] != 0)
    {
        if (!IsNationalPokedexEnabled())
            r6 = gUnknown_0856EDF0;
        else
            r6 = gUnknown_0856EDB8;
    }
    else
    {
        if (!IsNationalPokedexEnabled())
            r6 = gUnknown_0856EDD4;
        else
            r6 = gUnknown_0856ED9C;
    }

    if (gMain.newKeys & B_BUTTON)
    {
        PlaySE(SE_BOWA);
        sub_80C23B8(taskId);
        gTasks[taskId].func = sub_80C1570;
        return;
    }
    if (gMain.newKeys & A_BUTTON)
    {
        if (gTasks[taskId].data[1] == 6)
        {
            if (gTasks[taskId].data[0] != 0)
            {
                gUnknown_02039B52 = 0x40;
                sPokedexView->unk62A = 0x40;
                gUnknown_02039B50 = 0;
                sPokedexView->unk610 = 0;
                gSaveBlock2Ptr->pokedex.mode = sub_80C2318(taskId, 5);
                if (!IsNationalPokedexEnabled())
                    gSaveBlock2Ptr->pokedex.mode = DEX_MODE_HOENN;
                sPokedexView->unk614 = gSaveBlock2Ptr->pokedex.mode;
                gSaveBlock2Ptr->pokedex.order = sub_80C2318(taskId, 4);
                sPokedexView->unk618 = gSaveBlock2Ptr->pokedex.order;
                PlaySE(SE_PC_OFF);
                gTasks[taskId].func = sub_80C1D38;
            }
            else
            {
                sub_80C2618(gText_SearchingPleaseWait);
                gTasks[taskId].func = sub_80C19A4;
                PlaySE(SE_Z_SEARCH);
                CopyWindowToVram(0, 2);
            }
        }
        else
        {
            PlaySE(SE_PIN);
            gTasks[taskId].func = sub_80C1B64;
        }
        return;
    }

    if ((gMain.newKeys & DPAD_LEFT) && r6[gTasks[taskId].data[1]][0] != 0xFF)
    {
        PlaySE(SE_SELECT);
        gTasks[taskId].data[1] = r6[gTasks[taskId].data[1]][0];
        sub_80C2064(gTasks[taskId].data[0], gTasks[taskId].data[1]);
        CopyWindowToVram(0, 2);
        CopyBgTilemapBufferToVram(3);
    }
    if ((gMain.newKeys & DPAD_RIGHT) && r6[gTasks[taskId].data[1]][1] != 0xFF)
    {
        PlaySE(SE_SELECT);
        gTasks[taskId].data[1] = r6[gTasks[taskId].data[1]][1];
        sub_80C2064(gTasks[taskId].data[0], gTasks[taskId].data[1]);
        CopyWindowToVram(0, 2);
        CopyBgTilemapBufferToVram(3);
    }
    if ((gMain.newKeys & DPAD_UP) && r6[gTasks[taskId].data[1]][2] != 0xFF)
    {
        PlaySE(SE_SELECT);
        gTasks[taskId].data[1] = r6[gTasks[taskId].data[1]][2];
        sub_80C2064(gTasks[taskId].data[0], gTasks[taskId].data[1]);
        CopyWindowToVram(0, 2);
        CopyBgTilemapBufferToVram(3);
    }
    if ((gMain.newKeys & DPAD_DOWN) && r6[gTasks[taskId].data[1]][3] != 0xFF)
    {
        PlaySE(SE_SELECT);
        gTasks[taskId].data[1] = r6[gTasks[taskId].data[1]][3];
        sub_80C2064(gTasks[taskId].data[0], gTasks[taskId].data[1]);
        CopyWindowToVram(0, 2);
        CopyBgTilemapBufferToVram(3);
    }
}

void sub_80C19A4(u8 taskId)
{
    u8 r10 = sub_80C2318(taskId, 5);
    u8 r9 = sub_80C2318(taskId, 4);
    u8 r8 = sub_80C2318(taskId, 0);
    u8 r6 = sub_80C2318(taskId, 1);
    u8 r4 = sub_80C2318(taskId, 2);
    u8 r0 = sub_80C2318(taskId, 3);

    sub_80C0F30(r10, r9, r8, r6, r4, r0);
    gTasks[taskId].func = sub_80C1A4C;
}

void sub_80C1A4C(u8 taskId)
{
    if (!IsSEPlaying())
    {
        if (sPokedexView->pokemonListCount != 0)
        {
            PlaySE(SE_SEIKAI);
            sub_80C2618(gText_SearchCompleted);
        }
        else
        {
            PlaySE(SE_HAZURE);
            sub_80C2618(gUnknown_085E8785);
        }
        gTasks[taskId].func = sub_80C1AB8;
        CopyWindowToVram(0, 2);
    }
}

void sub_80C1AB8(u8 taskId)
{
    if (gMain.newKeys & A_BUTTON)
    {
        if (sPokedexView->pokemonListCount != 0)
        {
            sPokedexView->unk64E = 1;
            sPokedexView->dexMode = sub_80C2318(taskId, 5);
            sPokedexView->dexOrder = sub_80C2318(taskId, 4);
            gTasks[taskId].func = sub_80C1D38;
            PlaySE(SE_PC_OFF);
        }
        else
        {
            gTasks[taskId].func = sub_80C16CC;
            PlaySE(SE_BOWA);
        }
    }
}

void sub_80C1B64(u8 taskId)
{
    u8 r0;
    u16 *p1;
    u16 *p2;

    sub_80C21D4(0);
    r0 = gTasks[taskId].data[1];
    p1 = &gTasks[taskId].data[gUnknown_0856EFC8[r0].unk4];
    p2 = &gTasks[taskId].data[gUnknown_0856EFC8[r0].unk5];
    gTasks[taskId].data[14] = *p1;
    gTasks[taskId].data[15] = *p2;
    sub_80C2294(taskId);
    sub_80C2650(*p1);
    gTasks[taskId].func = sub_80C1BCC;
    CopyWindowToVram(0, 2);
    CopyBgTilemapBufferToVram(3);
}

void sub_80C1BCC(u8 taskId)
{
    u8 r1;
    const struct PokedexOption *r8;
    u16 *p1;
    u16 *p2;
    u16 r2;
    bool8 r3;

    r1 = gTasks[taskId].data[1];
    r8 = gUnknown_0856EFC8[r1].pokedexList;
    p1 = &gTasks[taskId].data[gUnknown_0856EFC8[r1].unk4];
    p2 = &gTasks[taskId].data[gUnknown_0856EFC8[r1].unk5];
    r2 = gUnknown_0856EFC8[r1].unk6 - 1;
    if (gMain.newKeys & A_BUTTON)
    {
        PlaySE(SE_PIN);
        sub_80C267C();
        sub_80C21D4(1);
        gTasks[taskId].func = sub_80C16CC;
        CopyWindowToVram(0, 2);
        CopyBgTilemapBufferToVram(3);
        return;
    }
    if (gMain.newKeys & B_BUTTON)
    {
        PlaySE(SE_BOWA);
        sub_80C267C();
        sub_80C21D4(1);
        *p1 = gTasks[taskId].data[14];
        *p2 = gTasks[taskId].data[15];
        gTasks[taskId].func = sub_80C16CC;
        CopyWindowToVram(0, 2);
        CopyBgTilemapBufferToVram(3);
        return;
    }
    r3 = FALSE;
    if (gMain.newAndRepeatedKeys & DPAD_UP)
    {
        if (*p1 != 0)
        {
            sub_80C2638(*p1);
            (*p1)--;
            sub_80C2650(*p1);
            r3 = TRUE;
        }
        else if (*p2 != 0)
        {
            (*p2)--;
            sub_80C2294(taskId);
            sub_80C2650(*p1);
            r3 = TRUE;
        }
        if (r3)
        {
            PlaySE(SE_SELECT);
            sub_80C2618(r8[*p1 + *p2].description);
            CopyWindowToVram(0, 2);
        }
        return;
    }
    if (gMain.newAndRepeatedKeys & DPAD_DOWN)
    {
        if (*p1 < 5 && *p1 < r2)
        {
            sub_80C2638(*p1);
            (*p1)++;
            sub_80C2650(*p1);
            r3 = TRUE;
        }
        else if (r2 > 5 && *p2 < r2 - 5)
        {
            (*p2)++;
            sub_80C2294(taskId);
            sub_80C2650(5);
            r3 = TRUE;
        }
        if (r3)
        {
            PlaySE(SE_SELECT);
            sub_80C2618(r8[*p1 + *p2].description);
            CopyWindowToVram(0, 2);
        }
        return;
    }
}

void sub_80C1D38(u8 taskId)
{
    BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
    gTasks[taskId].func = sub_80C1D70;
}

void sub_80C1D70(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        sub_80C152C();
        DestroyTask(taskId);
    }
}

#ifdef NONMATCHING
// This doesn't match because gcc flips the naming of the r7 and r6
// registers. It also does one of the additions backwards.
void sub_80C1D98(u8 a, u8 b, u8 c, u8 d)
{
    u16 i;
    u16* ptr = GetBgTilemapBuffer(3);

    u16* temp;
    for (i = 0; i < d; i++)
    {
        // This addition is supposed to be done in this order; however,
        // gcc will always do it in ptr + (c << 5) order.
        temp = (c << 5) + ptr;
        temp[b + i] %= 0x1000;
        temp[b + i] |= a * 4096;

        temp[b + i + 32] %= 0x1000;
        temp[b + i + 32] |= a * 4096;
    }
}
#else
__attribute__((naked))
void sub_80C1D98(u8 a, u8 b, u8 c, u8 d)
{
    asm(".syntax unified\n\
    push {r4-r7,lr}\n\
    mov r7, r8\n\
    push {r7}\n\
    adds r4, r3, 0\n\
    lsls r0, 24\n\
    lsrs r6, r0, 24\n\
    lsls r1, 24\n\
    lsrs r1, 24\n\
    mov r8, r1\n\
    lsls r2, 24\n\
    lsrs r5, r2, 24\n\
    lsls r4, 24\n\
    lsrs r4, 24\n\
    movs r0, 0x3\n\
    bl GetBgTilemapBuffer\n\
    adds r2, r0, 0\n\
    movs r3, 0\n\
    cmp r3, r4\n\
    bcs _080C1DEC\n\
    lsls r0, r5, 6\n\
    adds r7, r0, r2\n\
    ldr r5, =0x00000fff\n\
    lsls r2, r6, 12\n\
_080C1DC8:\n\
    mov r0, r8\n\
    adds r1, r0, r3\n\
    lsls r1, 1\n\
    adds r1, r7\n\
    ldrh r0, [r1]\n\
    ands r0, r5\n\
    orrs r0, r2\n\
    strh r0, [r1]\n\
    adds r1, 0x40\n\
    ldrh r0, [r1]\n\
    ands r0, r5\n\
    orrs r0, r2\n\
    strh r0, [r1]\n\
    adds r0, r3, 0x1\n\
    lsls r0, 16\n\
    lsrs r3, r0, 16\n\
    cmp r3, r4\n\
    bcc _080C1DC8\n\
_080C1DEC:\n\
    pop {r3}\n\
    mov r8, r3\n\
    pop {r4-r7}\n\
    pop {r0}\n\
    bx r0\n\
    .pool\n\
    .syntax divided\n");
}
#endif

void sub_80C1DFC(u8 a, u8 b, u8 c)
{
    u8 r5 = (b & 1) | ((c & 1) << 1);

    switch (a)
    {
        case 0:
        case 1:
        case 2:
            sub_80C1D98(r5, gUnknown_0856ED30[a].unk4, gUnknown_0856ED30[a].unk5, gUnknown_0856ED30[a].unk6);
            break;
        case 3:
        case 4:
        case 7:
        case 8:
            sub_80C1D98(r5, gUnknown_0856ED48[a - 3].unk4, gUnknown_0856ED48[a - 3].unk5, gUnknown_0856ED48[a - 3].unk6);
            // fall through
        case 5:
        case 6:
            sub_80C1D98(r5, gUnknown_0856ED48[a - 3].unk7, gUnknown_0856ED48[a - 3].unk8, gUnknown_0856ED48[a - 3].unk9);
            break;
        case 10:
            sub_80C1D98(r5, gUnknown_0856ED48[2].unk4, gUnknown_0856ED48[2].unk5, gUnknown_0856ED48[2].unk6);
            break;
        case 9:
            if (!IsNationalPokedexEnabled())
                sub_80C1D98(r5, gUnknown_0856ED48[a - 3].unk4, gUnknown_0856ED48[a - 3].unk5 - 2, gUnknown_0856ED48[a - 3].unk6);
            else
                sub_80C1D98(r5, gUnknown_0856ED48[a - 3].unk4, gUnknown_0856ED48[a - 3].unk5, gUnknown_0856ED48[a - 3].unk6);
            break;
    }
}

void sub_80C1EF4(u8 a)
{
    switch (a)
    {
        case 0:
            sub_80C1DFC(0, 0, 0);
            sub_80C1DFC(1, 1, 0);
            sub_80C1DFC(2, 1, 0);
            sub_80C1DFC(3, 1, 0);
            sub_80C1DFC(4, 1, 0);
            sub_80C1DFC(10, 1, 0);
            sub_80C1DFC(5, 1, 0);
            sub_80C1DFC(6, 1, 0);
            sub_80C1DFC(7, 1, 0);
            sub_80C1DFC(8, 1, 0);
            sub_80C1DFC(9, 1, 0);
            break;
        case 1:
            sub_80C1DFC(0, 1, 0);
            sub_80C1DFC(1, 0, 0);
            sub_80C1DFC(2, 1, 0);
            sub_80C1DFC(3, 1, 1);
            sub_80C1DFC(4, 1, 1);
            sub_80C1DFC(10, 1, 1);
            sub_80C1DFC(5, 1, 1);
            sub_80C1DFC(6, 1, 1);
            sub_80C1DFC(7, 1, 0);
            sub_80C1DFC(8, 1, 0);
            sub_80C1DFC(9, 1, 0);
            break;
        case 2:
            sub_80C1DFC(0, 1, 0);
            sub_80C1DFC(1, 1, 0);
            sub_80C1DFC(2, 0, 0);
            sub_80C1DFC(3, 1, 1);
            sub_80C1DFC(4, 1, 1);
            sub_80C1DFC(10, 1, 1);
            sub_80C1DFC(5, 1, 1);
            sub_80C1DFC(6, 1, 1);
            sub_80C1DFC(7, 1, 1);
            sub_80C1DFC(8, 1, 1);
            sub_80C1DFC(9, 1, 1);
            break;
    }
}

void sub_80C2040(u8 a)
{
    sub_80C1EF4(a);
    sub_80C2618(gUnknown_0856ED30[a].text);
}

void sub_80C2064(u8 a, u8 b)
{
    sub_80C1EF4(a);
    switch (b)
    {
        case 0:
            sub_80C1DFC(3, 0, 0);
            break;
        case 1:
            sub_80C1DFC(4, 0, 0);
            break;
        case 2:
            sub_80C1DFC(10, 0, 0);
            sub_80C1DFC(5, 0, 0);
            break;
        case 3:
            sub_80C1DFC(10, 0, 0);
            sub_80C1DFC(6, 0, 0);
            break;
        case 4:
            sub_80C1DFC(7, 0, 0);
            break;
        case 5:
            sub_80C1DFC(8, 0, 0);
            break;
        case 6:
            sub_80C1DFC(9, 0, 0);
            break;
    }
    sub_80C2618(gUnknown_0856ED48[b].text);
}

void sub_80C20F8(u8 taskId)
{
    u16 var;

    sub_80C12B0(0x28, 0x10, 0x60, 0x50);

    var = gTasks[taskId].data[6] + gTasks[taskId].data[7];
    sub_80C1270(gDexSearchAlphaOptions[var].title, 0x2D, 0x11);

    var = gTasks[taskId].data[8] + gTasks[taskId].data[9];
    sub_80C1270(gDexSearchColorOptions[var].title, 0x2D, 0x21);

    var = gTasks[taskId].data[10] + gTasks[taskId].data[11];
    sub_80C1270(gDexSearchTypeOptions[var].title, 0x2D, 0x31);

    var = gTasks[taskId].data[12] + gTasks[taskId].data[13];
    sub_80C1270(gDexSearchTypeOptions[var].title, 0x5D, 0x31);

    var = gTasks[taskId].data[4] + gTasks[taskId].data[5];
    sub_80C1270(gDexSortOptions[var].title, 0x2D, 0x41);

    if (IsNationalPokedexEnabled())
    {
        var = gTasks[taskId].data[2] + gTasks[taskId].data[3];
        sub_80C1270(gDexModeOptions[var].title, 0x2D, 0x51);
    }
}

void sub_80C21D4(u8 a)
{
    u16 i;
    u16 j;
    u16* ptr = GetBgTilemapBuffer(3);

    if (a == 0)
    {
        *(ptr + 0x11) = 0xC0B;
        for (i = 0x12; i < 0x1F; i++)
            *(ptr + i) = 0x80D;
        for (j = 1; j < 13; j++)
        {
            *(ptr + 0x11 + j * 32) = 0x40A;
            for (i = 0x12; i < 0x1F; i++)
                *(ptr + j * 32 + i) = 2;
        }
        *(ptr + 0x1B1) = 0x40B;
        for (i = 0x12; i < 0x1F; i++)
            *(ptr + 0x1A0 + i) = 0xD;
    }
    else
    {
        for (j = 0; j < 14; j++)
        {
            for (i = 0x11; i < 0x1E; i++)
            {
                *(ptr + j * 32 + i) = 0x4F;
            }
        }
    }
}

void sub_80C2294(u8 taskId)
{
    const struct PokedexOption *r6 = gUnknown_0856EFC8[gTasks[taskId].data[1]].pokedexList;
    const u16 *r8 = &gTasks[taskId].data[gUnknown_0856EFC8[gTasks[taskId].data[1]].unk4];
    const u16 *r7 = &gTasks[taskId].data[gUnknown_0856EFC8[gTasks[taskId].data[1]].unk5];
    u16 i;
    u16 j;

    sub_80C267C();
    for (i = 0, j = *r7; i < 6 && r6[j].title != NULL; i++, j++)
        sub_80C2668(i, r6[j].title);
    sub_80C2618(r6[*r8 + *r7].description);
}

u8 sub_80C2318(u8 taskId, u8 b)
{
    const u16 *ptr1 = &gTasks[taskId].data[gUnknown_0856EFC8[b].unk4];
    const u16 *ptr2 = &gTasks[taskId].data[gUnknown_0856EFC8[b].unk5];
    u16 type = *ptr1 + *ptr2;

    switch (b)
    {
        default:
            return 0;
        case 5:
            return gUnknown_0856EFAC[type];
        case 4:
            return gUnknown_0856EFAE[type];
        case 0:
            if (type == 0)
                return 0xFF;
            else
                return type;
        case 1:
            if (type == 0)
                return 0xFF;
            else
                return type - 1;
        case 2:
        case 3:
            return gDexSearchTypeIds[type];
    }
}

void sub_80C23B8(u8 taskId)
{
    u16 r3;

    switch (sPokedexView->unk614)
    {
        default:
        case 0:
            r3 = 0;
            break;
        case 1:
            r3 = 1;
            break;
    }
    gTasks[taskId].data[2] = r3;

    switch (sPokedexView->unk618)
    {
        default:
        case 0:
            r3 = 0;
            break;
        case 1:
            r3 = 1;
            break;
        case 2:
            r3 = 2;
            break;
        case 3:
            r3 = 3;
            break;
        case 4:
            r3 = 4;
            break;
        case 5:
            r3 = 5;
            break;
    }
    gTasks[taskId].data[4] = r3;
}

bool8 sub_80C244C(u8 taskId)
{
    u8 val1 = gTasks[taskId].data[1];
    const u16 *ptr = &gTasks[taskId].data[gUnknown_0856EFC8[val1].unk5];
    u16 val2 = gUnknown_0856EFC8[val1].unk6 - 1;

    if (val2 > 5 && *ptr != 0)
        return FALSE;
    else
        return TRUE;
}

bool8 sub_80C2494(u8 taskId)
{
    u8 val1 = gTasks[taskId].data[1];
    const u16 *ptr = &gTasks[taskId].data[gUnknown_0856EFC8[val1].unk5];
    u16 val2 = gUnknown_0856EFC8[val1].unk6 - 1;

    if (val2 > 5 && *ptr < val2 - 5)
        return FALSE;
    else
        return TRUE;
}

void sub_80C24E0(struct Sprite *sprite)
{
    if (gTasks[sprite->data[0]].func == sub_80C1BCC)
    {
        u8 val;

        if (sprite->data[1] != 0)
        {
            if (sub_80C2494(sprite->data[0]))
                sprite->invisible = TRUE;
            else
                sprite->invisible = FALSE;
        }
        else
        {
            if (sub_80C244C(sprite->data[0]))
                sprite->invisible = TRUE;
            else
                sprite->invisible = FALSE;
        }
        val = sprite->data[2] + sprite->data[1] * 128;
        sprite->pos2.y = gSineTable[val] / 128;
        sprite->data[2] += 8;
    }
    else
    {
        sprite->invisible = TRUE;
    }
}

void sub_80C2594(u8 taskId)
{
    u8 spriteId;

    spriteId = CreateSprite(&sArrowSpriteTemplate, 184, 4, 0);
    gSprites[spriteId].data[0] = taskId;
    gSprites[spriteId].data[1] = 0;
    gSprites[spriteId].callback = sub_80C24E0;

    spriteId = CreateSprite(&sArrowSpriteTemplate, 184, 108, 0);
    gSprites[spriteId].data[0] = taskId;
    gSprites[spriteId].data[1] = 1;
    gSprites[spriteId].vFlip = TRUE;
    gSprites[spriteId].callback = sub_80C24E0;
}

void sub_80C2618(const u8* str)
{
    sub_80C12B0(8, 0x78, 0xE0, 0x20);
    sub_80C1270(str, 8, 0x79);
}

void sub_80C2638(u32 y)
{
    sub_80C12B0(0x90, y * 16 + 8, 8, 16);
}

void sub_80C2650(u32 left)
{
    sub_80C1270(gText_SelectorArrow, 0x90, left * 16 + 9);
}

void sub_80C2668(u32 left, const u8* str)
{
    sub_80C1270(str, 0x98, left * 16 + 9);
}

void sub_80C267C(void)
{
    sub_80C12B0(0x90, 8, 0x60, 0x60);
}
