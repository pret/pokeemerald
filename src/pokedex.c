#include "global.h"
#include "gba/m4a_internal.h"
#include "pokedex.h"
#include "sprite.h"
#include "graphics.h"
#include "decompress.h"
#include "bg.h"
#include "window.h"
#include "event_data.h"
#include "palette.h"
#include "main.h"
#include "sound.h"
#include "task.h"
#include "battle_dome_cards.h"
#include "scanline_effect.h"
#include "malloc.h"
#include "gpu_regs.h"
#include "constants/songs.h"
#include "constants/rgb.h"
#include "overworld.h"
#include "menu.h"
#include "text_window.h"
#include "data2.h"
#include "string_util.h"
#include "trig.h"
#include "pokedex_area_screen.h"
#include "pokedex_cry_screen.h"
#include "strings.h"
#include "m4a.h"
#include "international_string_util.h"

extern struct PokedexView *gUnknown_02039B4C;
extern u16 gUnknown_02039B50;
extern u8 gUnknown_02039B52;
extern struct PokedexListItem *gUnknown_02039B54;

extern u8 gUnknown_030060B0;
extern MainCallback gUnknown_030060B4;
extern u8 gUnknown_030061EC;

struct PokedexEntry
{
    /*0x00*/ u8 categoryName[12];
    /*0x0C*/ u16 height; //in decimeters
    /*0x0E*/ u16 weight; //in hectograms
    /*0x10*/ const u8 *description;
    /*0x14*/ u16 unused;
    /*0x16*/ u16 pokemonScale;
    /*0x18*/ u16 pokemonOffset;
    /*0x1A*/ u16 trainerScale;
    /*0x1C*/ u16 trainerOffset;
};  /*size = 0x20*/

extern struct BgTemplate gUnknown_0856E630[];
extern struct WindowTemplate gUnknown_0856E640[];
extern const u16 gUnknown_0856E610[16];
extern const struct PokedexEntry gPokedexEntries[];

#define HOENN_DEX_COUNT 202
#define NATIONAL_DEX_COUNT 386

extern struct MusicPlayerInfo gMPlayInfo_BGM;

struct PokedexListItem
{
    u16 dexNum;
    u16 seen:1;
    u16 owned:1;
};

struct PokedexView
{
    struct PokedexListItem unk0[NATIONAL_DEX_COUNT];
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
    u16 unk61A;
    u16 unk61C;
    u16 unk61E[4];
    u16 selectedMonSpriteId;
    u16 unk628;
    u16 unk62A;
    u8 unk62C;
    u8 unk62D;
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
    DEX_MODE_HOENN,
    DEX_MODE_NATIONAL
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
void sub_80BC0F8(u8);
void sub_80BC2D4(u8);
void sub_80BC360(u8);
void sub_80BC3DC(u8);
void sub_80BC47C(u8);
bool8 sub_80BC514(u8);
void sub_80BC844(u8);
void sub_80BC890(void);
void sub_80BC8D4(u8, u8);
void sub_80BD154(u16, u8, u8, u16);
void sub_80BD1F4(u16, u8, u8, u16);
u8 sub_80BD23C(u16, u8, u8);
void sub_80BD28C(u8, u8, u16);
void sub_80BD2B4(u16, u16);
bool8 sub_80BD404(u8, u8, u8);
u16 sub_80BD69C(u16, u16);
void sub_80BD8D0(void);
bool8 sub_80BD930(void);
u8 sub_80BDA40(void);
u16 sub_80BDA8C(u16);
u32 sub_80BDACC(u16, s16, s16);
void sub_80BDB7C(u8);
void sub_80BE470(struct Sprite *sprite);
void sub_80BE604(struct Sprite *sprite);
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
void sub_80C020C(u16, u8, u8, u8);
void sub_80C09B0(u16);
void sub_80C0B44(u8, u16, u8, u8);
void sub_80C0D30(u8, u16);
u8 sub_80C0EF8(u16, u8, u8, u8);
u16 sub_80C0E0C(u8, u16, u16, u16);
u8 sub_80C1258();

// const rom data
#include "data/pokedex_orders.h"

static const struct OamData sOamData_855CFE4 =
{
    .y = 160,
    .affineMode = 0,
    .objMode = 0,
    .mosaic = 0,
    .bpp = 0,
    .shape = 0,
    .x = 0,
    .matrixNum = 0,
    .size = 0,
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
    .shape = 1,
    .x = 0,
    .matrixNum = 0,
    .size = 0,
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
    .shape = 1,
    .x = 0,
    .matrixNum = 0,
    .size = 2,
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
    .shape = 0,
    .x = 0,
    .matrixNum = 0,
    .size = 2,
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
    .shape = 1,
    .x = 0,
    .matrixNum = 0,
    .size = 3,
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
    .shape = 2,
    .x = 0,
    .matrixNum = 0,
    .size = 0,
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

const struct SpriteTemplate gUnknown_0855D194 =
{
    .tileTag = 4096,
    .paletteTag = 4096,
    .oam = &sOamData_855CFE4,
    .anims = sSpriteAnimTable_855D114,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_80BE604,
};

const struct SpriteTemplate gUnknown_0855D1AC =
{
    .tileTag = 4096,
    .paletteTag = 4096,
    .oam = &sOamData_855CFEC,
    .anims = sSpriteAnimTable_855D118,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_80BE658,
};

const struct SpriteTemplate gUnknown_0855D1C4 =
{
    .tileTag = 4096,
    .paletteTag = 4096,
    .oam = &sOamData_855CFF4,
    .anims = sSpriteAnimTable_855D120,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_80BE758,
};

const struct SpriteTemplate gUnknown_0855D1DC =
{
    .tileTag = 4096,
    .paletteTag = 4096,
    .oam = &sOamData_855CFFC,
    .anims = sSpriteAnimTable_855D11C,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_80BE780,
};

const struct SpriteTemplate gUnknown_0855D1F4 =
{
    .tileTag = 4096,
    .paletteTag = 4096,
    .oam = &sOamData_855D004,
    .anims = sSpriteAnimTable_855D130,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_80BE44C,
};

const struct SpriteTemplate gUnknown_0855D20C =
{
    .tileTag = 4096,
    .paletteTag = 4096,
    .oam = &sOamData_855CFF4,
    .anims = sSpriteAnimTable_855D138,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_80BE44C,
};

const struct SpriteTemplate gUnknown_0855D224 =
{
    .tileTag = 4096,
    .paletteTag = 4096,
    .oam = &sOamData_855D00C,
    .anims = sSpriteAnimTable_855D140,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_80BE44C,
};

const struct SpriteTemplate gUnknown_0855D23C =
{
    .tileTag = 4096,
    .paletteTag = 4096,
    .oam = &sOamData_855D00C,
    .anims = sSpriteAnimTable_855D168,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_80BE44C,
};

const struct SpriteTemplate gUnknown_0855D254 =
{
    .tileTag = 4096,
    .paletteTag = 4096,
    .oam = &sOamData_855D00C,
    .anims = sSpriteAnimTable_855D190,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_80BE834,
};

const struct CompressedSpriteSheet gSpriteSheets_0855D26C[] =
{
    {gPokedexMenu2_Gfx, 0x2000, 4096},
    {0}
};

const struct SpritePalette gSpritePalettes_0855D26C[] =
{
    {gPokedexText_Pal, 4096},
    {0}
};

const u8 gUnknown_0855D28C[] = {0x4, 0x8, 0x10, 0x20, 0x20};
const u8 gUnknown_0855D291[] = {0x8, 0x4, 0x2, 0x1, 0x1};

const struct BgTemplate gBgTemplates_0855D298[] =
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

const struct WindowTemplate sWindowTemplates_0855D2A8[] =
{
    {2, 0, 0, 0x20, 0x20, 0, 1},
    DUMMY_WIN_TEMPLATE
};

const u8 gUnknown_0855D2B8[] = _("{UNK_CTRL_F9 8}000");
const u8 gUnknown_0855D2BE[] = INCBIN_U8("graphics/pokedex/caught_ball.4bpp");
const u8 sText_TenDashes[] = _("----------");

// .text

#define DEX_FLAGS_NO ((POKEMON_SLOTS_NUMBER / 8) + ((POKEMON_SLOTS_NUMBER % 8) ? 1 : 0))

void ResetPokedex(void)
{
    u16 i;
    
    gUnknown_02039B50 = 0;
    gUnknown_02039B52 = 64;
    gUnknown_030060B0 = 0;
    gSaveBlock2Ptr->pokedex.unknown1 = 0;
    gSaveBlock2Ptr->pokedex.order = 0;
    gSaveBlock2Ptr->pokedex.nationalMagic = 0;
    gSaveBlock2Ptr->pokedex.unknown2 = 0;
    gSaveBlock2Ptr->pokedex.unownPersonality = 0;
    gSaveBlock2Ptr->pokedex.spindaPersonality = 0;
    gSaveBlock2Ptr->pokedex.unknown3 = 0;
    DisableNationalPokedex();
    for (i = 0; i < DEX_FLAGS_NO; i++)
    {
        gSaveBlock2Ptr->pokedex.owned[i] = 0;
        gSaveBlock2Ptr->pokedex.seen[i] = 0;
        gSaveBlock1Ptr->seen1[i] = 0;
        gSaveBlock1Ptr->seen2[i] = 0;
    }
}

void sub_80BB358(void)
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

void sub_80BB384(struct PokedexView *pokedexView)
{
    u16 i;

    for (i = 0; i < NATIONAL_DEX_COUNT; i++)
    {
        pokedexView->unk0[i].dexNum |= 0xFFFF;
        pokedexView->unk0[i].seen = 0;
        pokedexView->unk0[i].owned = 0;
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
    pokedexView->unk61A = 0;
    pokedexView->unk61C = 0;
    for (i = 0; i <= 3; i++)
        pokedexView->unk61E[i] |= 0xFFFF;
    pokedexView->unk628 = 0;
    pokedexView->unk62A = 0;
    pokedexView->unk62C = 0;
    pokedexView->unk62D = 0;
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

void sub_80BB534(void)
{
    u8 *addr;
    u32 size;
        
    switch (gMain.state)
    {
    case 0:
    default:
        SetVBlankCallback(NULL);
        sub_80C09B0(0);
        addr = (u8 *)VRAM;
        size = VRAM_SIZE;
        while (1)
        {
            DmaFill16(3, 0, addr, 0x1000);
            addr += 0x1000;
            size -= 0x1000;
            if (size <= 0x1000)
            {
                DmaFill16(3, 0, addr, size);
                break;
            }
        }
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
        dp13_810BB8C();
        gMain.state++;
        break;
    case 2:
        gUnknown_02039B4C = AllocZeroed(sizeof(struct PokedexView));
        sub_80BB384(gUnknown_02039B4C);
        CreateTask(sub_80BB78C, 0);
        gUnknown_02039B4C->dexMode = gSaveBlock2Ptr->pokedex.unknown1;
        if (!IsNationalPokedexEnabled())
            gUnknown_02039B4C->dexMode = DEX_MODE_HOENN;
        gUnknown_02039B4C->dexOrder = gSaveBlock2Ptr->pokedex.order;
        gUnknown_02039B4C->selectedPokemon = gUnknown_02039B50;
        gUnknown_02039B4C->unk62C = gUnknown_02039B52;
        gUnknown_02039B4C->selectedScreen = 0;
        if (!IsNationalPokedexEnabled())
        {
            gUnknown_02039B4C->unk61A = GetHoennPokedexCount(0);
            gUnknown_02039B4C->unk61C = GetHoennPokedexCount(1);
        }
        else
        {
            gUnknown_02039B4C->unk61A = GetNationalPokedexCount(0);
            gUnknown_02039B4C->unk61C = GetNationalPokedexCount(1);
        }
        gUnknown_02039B4C->unk62D = 8;
        gMain.state++;
        break;
    case 3:
        EnableInterrupts(1);
        SetVBlankCallback(sub_80BB370);
        SetMainCallback2(sub_80BB774);
        sub_80BC8D4(gUnknown_02039B4C->dexMode, gUnknown_02039B4C->dexOrder);
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
    gUnknown_02039B4C->unk64C_1 = FALSE;
    if (sub_80BC514(0))
        gTasks[taskId].func = sub_80BB7D4;
}

void sub_80BB7D4(u8 taskId)
{
    SetGpuReg(REG_OFFSET_BG0VOFS, gUnknown_02039B4C->menuY);
    
    if (gUnknown_02039B4C->menuY)
    {
        gUnknown_02039B4C->menuY -= 8;
    }
    else
    {
        if ((gMain.newKeys & A_BUTTON) && gUnknown_02039B4C->unk0[gUnknown_02039B4C->selectedPokemon].seen)
        {
            sub_80BD8D0();
            BeginNormalPaletteFade(~(1 << (gSprites[gUnknown_02039B4C->selectedMonSpriteId].oam.paletteNum + 16)), 0, 0, 0x10, RGB_BLACK);
            gSprites[gUnknown_02039B4C->selectedMonSpriteId].callback = sub_80BE470;
            gTasks[taskId].func = sub_80BBBF4;
            PlaySE(SE_PIN);
            sub_80BC890();
        }
        else if (gMain.newKeys & START_BUTTON)
        {
            //Open menu
            gUnknown_02039B4C->menuY = 0;
            gUnknown_02039B4C->menuIsOpen = 1;
            gUnknown_02039B4C->menuCursorPos = 0;
            gTasks[taskId].func = sub_80BBA78;
            PlaySE(SE_SELECT);
        }
        else if (gMain.newKeys & SELECT_BUTTON)
        {
            PlaySE(SE_SELECT);
            BeginNormalPaletteFade(-1, 0, 0, 0x10, RGB_BLACK);
            gTasks[taskId].data[0] = sub_80C1258();
            gUnknown_02039B4C->unk64E = 0;
            gUnknown_02039B4C->unk62A = gUnknown_02039B4C->unk62C;
            gUnknown_02039B4C->unk610 = gUnknown_02039B4C->selectedPokemon;
            gUnknown_02039B4C->unk614 = gUnknown_02039B4C->dexMode;
            gUnknown_02039B4C->unk618 = gUnknown_02039B4C->dexOrder;
            gTasks[taskId].func = sub_80BBD1C;
            PlaySE(SE_PC_LOGIN);
            sub_80BC890();
        }
        else if (gMain.newKeys & B_BUTTON)
        {
            BeginNormalPaletteFade(-1, 0, 0, 0x10, RGB_BLACK);
            gTasks[taskId].func = sub_80BBDE8;
            PlaySE(SE_PC_OFF);
        }
        else
        {
            //Handle D-pad
            gUnknown_02039B4C->selectedPokemon = sub_80BD69C(gUnknown_02039B4C->selectedPokemon, 0xE);
            if (gUnknown_02039B4C->unk62E)
                gTasks[taskId].func = sub_80BBA28;
        }
    }
}

void sub_80BBA28(u8 taskId)
{
    if (sub_80BD404(gUnknown_02039B4C->unk62F, gUnknown_02039B4C->unk634, gUnknown_02039B4C->unk636))
        gTasks[taskId].func = sub_80BB7D4;
}

void sub_80BBA78(u8 taskId)
{
    SetGpuReg(REG_OFFSET_BG0VOFS, gUnknown_02039B4C->menuY);

    //If menu is not open, slide it up, on screen
    if (gUnknown_02039B4C->menuY != 80)
        gUnknown_02039B4C->menuY += 8;
    else
    {
        if (gMain.newKeys & A_BUTTON)
        {
            switch (gUnknown_02039B4C->menuCursorPos)
            {
                case 0: //BACK TO LIST
                default:
                    gMain.newKeys |= START_BUTTON;  //Exit menu
                    break;
                case 1: //LIST TOP
                    gUnknown_02039B4C->selectedPokemon = 0;
                    gUnknown_02039B4C->unk62C = 0x40;
                    sub_80BDA40();
                    sub_80BD2B4(gUnknown_02039B4C->selectedPokemon, 0xE);
                    gMain.newKeys |= START_BUTTON;  //Exit menu
                    break;
                case 2: //LIST BOTTOM
                    gUnknown_02039B4C->selectedPokemon = gUnknown_02039B4C->pokemonListCount - 1;
                    gUnknown_02039B4C->unk62C = gUnknown_02039B4C->pokemonListCount * 16 + 0x30;
                    sub_80BDA40();
                    sub_80BD2B4(gUnknown_02039B4C->selectedPokemon, 0xE);
                    gMain.newKeys |= START_BUTTON;  //Exit menu
                    break;
                case 3: //CLOSE POKEDEX
                    BeginNormalPaletteFade(-1, 0, 0, 0x10, RGB_BLACK);
                    gTasks[taskId].func = sub_80BBDE8;
                    PlaySE(SE_PC_OFF);
                    break;
            }
        }

        //Exit menu when Start or B is pressed
        if (gMain.newKeys & (START_BUTTON | B_BUTTON))
        {
            gUnknown_02039B4C->menuIsOpen = 0;
            gTasks[taskId].func = sub_80BB7D4;
            PlaySE(SE_SELECT);
        }
        else if ((gMain.newAndRepeatedKeys & DPAD_UP) && gUnknown_02039B4C->menuCursorPos != 0)
        {
            gUnknown_02039B4C->menuCursorPos--;
            PlaySE(SE_SELECT);
        }
        else if ((gMain.newAndRepeatedKeys & DPAD_DOWN) && gUnknown_02039B4C->menuCursorPos <= 2)
        {
            gUnknown_02039B4C->menuCursorPos++;
            PlaySE(SE_SELECT);
        }
    }
}

void sub_80BBBF4(u8 taskId)
{
    if (gSprites[gUnknown_02039B4C->selectedMonSpriteId].pos1.x == 48 && gSprites[gUnknown_02039B4C->selectedMonSpriteId].pos1.y == 56)
    {
        gUnknown_02039B4C->unk64B = gUnknown_02039B4C->unk64A;
        gTasks[taskId].data[0] = sub_80BE91C(&gUnknown_02039B4C->unk0[gUnknown_02039B4C->selectedPokemon], gUnknown_02039B4C->selectedMonSpriteId);
        gTasks[taskId].func = sub_80BBC74;
    }
}

void sub_80BBC74(u8 taskId)
{
    if (gTasks[gTasks[taskId].data[0]].isActive)
    {
        if (gUnknown_02039B4C->unk64A == 1 && !sub_80BE9C4(gTasks[taskId].data[0]) && sub_80BD930())
            sub_80BE9F8(&gUnknown_02039B4C->unk0[gUnknown_02039B4C->selectedPokemon], gTasks[taskId].data[0]);
    }
    else
    {
        gUnknown_02039B50 = gUnknown_02039B4C->selectedPokemon;
        gUnknown_02039B52 = gUnknown_02039B4C->unk62C;
        gTasks[taskId].func = sub_80BB78C;
    }
}

void sub_80BBD1C(u8 taskId)
{
    if (!gTasks[gTasks[taskId].data[0]].isActive)
    {
        sub_80BDA40();
        if (gUnknown_02039B4C->unk64E != 0)
        {
            gUnknown_02039B4C->selectedPokemon = 0;
            gUnknown_02039B4C->unk62C = 0x40;
            gTasks[taskId].func = sub_80BBE70;
        }
        else
        {
            gUnknown_02039B4C->unk62C = gUnknown_02039B4C->unk62A;
            gUnknown_02039B4C->selectedPokemon = gUnknown_02039B4C->unk610;
            gUnknown_02039B4C->dexMode = gUnknown_02039B4C->unk614;
            if (!IsNationalPokedexEnabled())
                gUnknown_02039B4C->dexMode = DEX_MODE_HOENN;
            gUnknown_02039B4C->dexOrder = gUnknown_02039B4C->unk618;
            gTasks[taskId].func = sub_80BB78C;
        }
    }
}

void sub_80BBDE8(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        gSaveBlock2Ptr->pokedex.unknown1 = gUnknown_02039B4C->dexMode;
        if (!IsNationalPokedexEnabled())
            gSaveBlock2Ptr->pokedex.unknown1 = DEX_MODE_HOENN;
        gSaveBlock2Ptr->pokedex.order = gUnknown_02039B4C->dexOrder;
        sub_80BDA40();
        sub_80BC890();
        DestroyTask(taskId);
        SetMainCallback2(CB2_ReturnToFieldWithOpenMenu);
        m4aMPlayVolumeControl(&gMPlayInfo_BGM, 0xFFFF, 0x100);
        Free(gUnknown_02039B4C);
    }
}

void sub_80BBE70(u8 taskId)
{
    gUnknown_02039B4C->unk64C_1 = TRUE;
    if (sub_80BC514(3))
        gTasks[taskId].func = sub_80BBEB8;
}

void sub_80BBEB8(u8 taskId)
{
    SetGpuReg(REG_OFFSET_BG0VOFS, gUnknown_02039B4C->menuY);

    if (gUnknown_02039B4C->menuY)
    {
        gUnknown_02039B4C->menuY -= 8;
    }
    else
    {
        if ((gMain.newKeys & A_BUTTON) && gUnknown_02039B4C->unk0[gUnknown_02039B4C->selectedPokemon].seen)
        {
            u32 a;

            sub_80BD8D0();
            a = (1 << (gSprites[gUnknown_02039B4C->selectedMonSpriteId].oam.paletteNum + 16));
            gSprites[gUnknown_02039B4C->selectedMonSpriteId].callback = sub_80BE470;
            BeginNormalPaletteFade(~a, 0, 0, 0x10, RGB_BLACK);
            gTasks[taskId].func = sub_80BC2D4;
            PlaySE(SE_PIN);
            sub_80BC890();
        }
        else if (gMain.newKeys & START_BUTTON)
        {
            gUnknown_02039B4C->menuY = 0;
            gUnknown_02039B4C->menuIsOpen = 1;
            gUnknown_02039B4C->menuCursorPos = 0;
            gTasks[taskId].func = sub_80BC0F8;
            PlaySE(SE_SELECT);
        }
        else if (gMain.newKeys & SELECT_BUTTON)
        {
            BeginNormalPaletteFade(-1, 0, 0, 0x10, RGB_BLACK);
            gTasks[taskId].data[0] = sub_80C1258();
            gUnknown_02039B4C->unk64E = 0;
            gTasks[taskId].func = sub_80BBD1C;
            PlaySE(SE_PC_LOGIN);
            sub_80BC890();
        }
        else if (gMain.newKeys & B_BUTTON)
        {
            BeginNormalPaletteFade(-1, 0, 0, 0x10, RGB_BLACK);
            gTasks[taskId].func = sub_80BC3DC;
            PlaySE(SE_PC_OFF);
        }
        else
        {
            //Handle D-pad
            gUnknown_02039B4C->selectedPokemon = sub_80BD69C(gUnknown_02039B4C->selectedPokemon, 0xE);
            if (gUnknown_02039B4C->unk62E)
                gTasks[taskId].func = sub_80BC0A8;
        }
    }
}

void sub_80BC0A8(u8 taskId)
{
    if (sub_80BD404(gUnknown_02039B4C->unk62F, gUnknown_02039B4C->unk634, gUnknown_02039B4C->unk636))
        gTasks[taskId].func = sub_80BBEB8;
}

void sub_80BC0F8(u8 taskId)
{
    SetGpuReg(REG_OFFSET_BG0VOFS, gUnknown_02039B4C->menuY);

    if (gUnknown_02039B4C->menuY != 96)
    {
        gUnknown_02039B4C->menuY += 8;
    }
    else
    {
        if (gMain.newKeys & A_BUTTON)
        {
            switch (gUnknown_02039B4C->menuCursorPos)
            {
            case 0: //BACK TO LIST
            default:
                gMain.newKeys |= START_BUTTON;
                break;
            case 1: //LIST TOP
                gUnknown_02039B4C->selectedPokemon = 0;
                gUnknown_02039B4C->unk62C = 0x40;
                sub_80BDA40();
                sub_80BD2B4(gUnknown_02039B4C->selectedPokemon, 0xE);
                gMain.newKeys |= START_BUTTON;
                break;
            case 2: //LIST BOTTOM
                gUnknown_02039B4C->selectedPokemon = gUnknown_02039B4C->pokemonListCount - 1;
                gUnknown_02039B4C->unk62C = gUnknown_02039B4C->pokemonListCount * 16 + 0x30;
                sub_80BDA40();
                sub_80BD2B4(gUnknown_02039B4C->selectedPokemon, 0xE);
                gMain.newKeys |= START_BUTTON;
                break;
            case 3: //BACK TO POKEDEX
                BeginNormalPaletteFade(-1, 0, 0, 0x10, RGB_BLACK);
                gTasks[taskId].func = sub_80BC3DC;
                PlaySE(SE_TRACK_DOOR);
                break;
            case 4: //CLOSE POKEDEX
                BeginNormalPaletteFade(-1, 0, 0, 0x10, RGB_BLACK);
                gTasks[taskId].func = sub_80BC47C;
                PlaySE(SE_PC_OFF);
                break;
            }
        }

        //Exit menu when Start or B is pressed
        if (gMain.newKeys & (START_BUTTON | B_BUTTON))
        {
            gUnknown_02039B4C->menuIsOpen = 0;
            gTasks[taskId].func = sub_80BBEB8;
            PlaySE(SE_SELECT);
        }
        else if ((gMain.newAndRepeatedKeys & DPAD_UP) && gUnknown_02039B4C->menuCursorPos)
        {
            gUnknown_02039B4C->menuCursorPos--;
            PlaySE(SE_SELECT);
        }
        else if ((gMain.newAndRepeatedKeys & DPAD_DOWN) && gUnknown_02039B4C->menuCursorPos <= 3)
        {
            gUnknown_02039B4C->menuCursorPos++;
            PlaySE(SE_SELECT);
        }
    }
}

void sub_80BC2D4(u8 taskId)
{
    if (gSprites[gUnknown_02039B4C->selectedMonSpriteId].pos1.x == 48 && gSprites[gUnknown_02039B4C->selectedMonSpriteId].pos1.y == 56)
    {
        gUnknown_02039B4C->unk64B = gUnknown_02039B4C->unk64A;
        gTasks[taskId].data[0] = sub_80BE91C(&gUnknown_02039B4C->unk0[gUnknown_02039B4C->selectedPokemon], gUnknown_02039B4C->selectedMonSpriteId);
        gUnknown_02039B4C->selectedMonSpriteId = -1;
        gTasks[taskId].func = sub_80BC360;
    }
}

void sub_80BC360(u8 taskId)
{
    if (gTasks[gTasks[taskId].data[0]].isActive)
    {
        if (gUnknown_02039B4C->unk64A == 1 && !sub_80BE9C4(gTasks[taskId].data[0]) && sub_80BD930())
            sub_80BE9F8(&gUnknown_02039B4C->unk0[gUnknown_02039B4C->selectedPokemon], gTasks[taskId].data[0]);
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
        gUnknown_02039B4C->unk62C = gUnknown_02039B4C->unk62A;
        gUnknown_02039B4C->selectedPokemon = gUnknown_02039B4C->unk610;
        gUnknown_02039B4C->dexMode = gUnknown_02039B4C->unk614;
        if (!IsNationalPokedexEnabled())
            gUnknown_02039B4C->dexMode = DEX_MODE_HOENN;
        gUnknown_02039B4C->dexOrder = gUnknown_02039B4C->unk618;
        gTasks[taskId].func = sub_80BB78C;
        sub_80BDA40();
        sub_80BC890();
    }
}

void sub_80BC47C(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        gUnknown_02039B4C->unk62C = gUnknown_02039B4C->unk62A;
        gUnknown_02039B4C->selectedPokemon = gUnknown_02039B4C->unk610;
        gUnknown_02039B4C->dexMode = gUnknown_02039B4C->unk614;
        if (!IsNationalPokedexEnabled())
            gUnknown_02039B4C->dexMode = DEX_MODE_HOENN;
        gUnknown_02039B4C->dexOrder = gUnknown_02039B4C->unk618;
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
        gUnknown_02039B4C->unk64A = a;
        sub_80C09B0(0);
        SetGpuReg(REG_OFFSET_BG2VOFS, gUnknown_02039B4C->unk62D);
        ResetBgsAndClearDma3BusyFlags(0);
        InitBgsFromTemplates(0, gBgTemplates_0855D298, 4);
        SetBgTilemapBuffer(3, AllocZeroed(0x800));
        SetBgTilemapBuffer(2, AllocZeroed(0x800));
        SetBgTilemapBuffer(1, AllocZeroed(0x800));
        SetBgTilemapBuffer(0, AllocZeroed(0x800));
        copy_decompressed_tile_data_to_vram_autofree(3, gPokedexMenu_Gfx, 0x2000, 0, 0);
        CopyToBgTilemapBuffer(1, gUnknown_08DC2C5C, 0, 0);
        CopyToBgTilemapBuffer(3, gUnknown_08DC2DAC, 0, 0);
        if (a == 0)
            CopyToBgTilemapBuffer(0, gUnknown_08DC2A08, 0, 0x280);
        else
            CopyToBgTilemapBuffer(0, gUnknown_08DC2B1C, 0, 0x280);
        ResetPaletteFade();
        if (a == 0)
            gUnknown_02039B4C->unk64C_1 = FALSE;
        else
            gUnknown_02039B4C->unk64C_1 = TRUE;
        sub_80BC844(gUnknown_02039B4C->unk64C_1);
        InitWindows(sWindowTemplates_0855D2A8);
        DeactivateAllTextPrinters();
        PutWindowTilemap(0);
        CopyWindowToVram(0, 3);
        gMain.state = 1;
        break;
    case 1:
        ResetSpriteData();
        FreeAllSpritePalettes();
        gReservedSpritePaletteCount = 8;
        LoadCompressedObjectPic(&gSpriteSheets_0855D26C[0]);
        LoadSpritePalettes(gSpritePalettes_0855D26C);
        sub_80BDB7C(a);
        gMain.state++;
        break;
    case 2:
        gMain.state++;
        break;
    case 3:
        if (a == 0)
            sub_80BC8D4(gUnknown_02039B4C->dexMode, gUnknown_02039B4C->dexOrder);
        sub_80BD2B4(gUnknown_02039B4C->selectedPokemon, 0xE);
        gUnknown_02039B4C->menuIsOpen = 0;
        gUnknown_02039B4C->menuY = 0;
        CopyBgTilemapBufferToVram(0);
        CopyBgTilemapBufferToVram(1);
        CopyBgTilemapBufferToVram(2);
        CopyBgTilemapBufferToVram(3);
        gMain.state++;
        break;
    case 4:
        BeginNormalPaletteFade(-1, 0, 0x10, 0, RGB_BLACK);
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

void sub_80BC844(u8 a)
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
    u16 vars[3]; //I have no idea why three regular variables are stored in an array, but whatever.
    s16 i;
    
    gUnknown_02039B4C->pokemonListCount = 0;

    switch (dexMode)
    {
    default:
    case DEX_MODE_HOENN:
        vars[0] = HOENN_DEX_COUNT;
        vars[1] = 1;
        break;
    case DEX_MODE_NATIONAL:
        if (IsNationalPokedexEnabled())
        {
            vars[0] = NATIONAL_DEX_COUNT;
            vars[1] = 0;
        }
        else
        {
            vars[0] = HOENN_DEX_COUNT;
            vars[1] = 1;
        }
        break;
    }

    switch (sortMode)
    {
    case 0:
        if (vars[1])
        {
            for (i = 0; i < vars[0]; i++)
            {
                vars[2] = HoennToNationalOrder(i + 1);
                gUnknown_02039B4C->unk0[i].dexNum = vars[2];
                gUnknown_02039B4C->unk0[i].seen = GetSetPokedexFlag(vars[2], 0);
                gUnknown_02039B4C->unk0[i].owned = GetSetPokedexFlag(vars[2], 1);
                if (gUnknown_02039B4C->unk0[i].seen)
                    gUnknown_02039B4C->pokemonListCount = i + 1;
            }
        }
        else
        {
            bool32 r10;
            s16 r5;

            r10 = r5 = i = 0;
            for (i = 0; i < vars[0]; i++)
            {
                vars[2] = i + 1;
                if (GetSetPokedexFlag(vars[2], 0))
                    r10 = 1;
                if (r10)
                {
                    asm("");    //Needed to match for some reason
                    gUnknown_02039B4C->unk0[r5].dexNum = vars[2];
                    gUnknown_02039B4C->unk0[r5].seen = GetSetPokedexFlag(vars[2], 0);
                    gUnknown_02039B4C->unk0[r5].owned = GetSetPokedexFlag(vars[2], 1);
                    if (gUnknown_02039B4C->unk0[r5].seen)
                        gUnknown_02039B4C->pokemonListCount = r5 + 1;
                    r5++;
                }
            }
        }
        break;
    case 1:
        for (i = 0; i < POKEMON_SLOTS_NUMBER - 1; i++)
        {
            vars[2] = gPokedexOrder_Alphabetical[i];

            if (NationalToHoennOrder(vars[2]) <= vars[0] && GetSetPokedexFlag(vars[2], 0))
            {
                gUnknown_02039B4C->unk0[gUnknown_02039B4C->pokemonListCount].dexNum = vars[2];
                gUnknown_02039B4C->unk0[gUnknown_02039B4C->pokemonListCount].seen = 1;
                gUnknown_02039B4C->unk0[gUnknown_02039B4C->pokemonListCount].owned = GetSetPokedexFlag(vars[2], 1);
                gUnknown_02039B4C->pokemonListCount++;
            }
        }
        break;
    case 2:
        for (i = NATIONAL_DEX_COUNT - 1; i >= 0; i--)
        {
            vars[2] = gPokedexOrder_Weight[i];

            if (NationalToHoennOrder(vars[2]) <= vars[0] && GetSetPokedexFlag(vars[2], 1))
            {
                gUnknown_02039B4C->unk0[gUnknown_02039B4C->pokemonListCount].dexNum = vars[2];
                gUnknown_02039B4C->unk0[gUnknown_02039B4C->pokemonListCount].seen = 1;
                gUnknown_02039B4C->unk0[gUnknown_02039B4C->pokemonListCount].owned = 1;
                gUnknown_02039B4C->pokemonListCount++;
            }
        }
        break;
    case 3:
        for (i = 0; i < NATIONAL_DEX_COUNT; i++)
        {
            vars[2] = gPokedexOrder_Weight[i];

            if (NationalToHoennOrder(vars[2]) <= vars[0] && GetSetPokedexFlag(vars[2], 1))
            {
                gUnknown_02039B4C->unk0[gUnknown_02039B4C->pokemonListCount].dexNum = vars[2];
                gUnknown_02039B4C->unk0[gUnknown_02039B4C->pokemonListCount].seen = 1;
                gUnknown_02039B4C->unk0[gUnknown_02039B4C->pokemonListCount].owned = 1;
                gUnknown_02039B4C->pokemonListCount++;
            }
        }
        break;
    case 4:
        for (i = NATIONAL_DEX_COUNT - 1; i >=0; i--)
        {
            vars[2] = gPokedexOrder_Height[i];

            if (NationalToHoennOrder(vars[2]) <= vars[0] && GetSetPokedexFlag(vars[2], 1))
            {
                gUnknown_02039B4C->unk0[gUnknown_02039B4C->pokemonListCount].dexNum = vars[2];
                gUnknown_02039B4C->unk0[gUnknown_02039B4C->pokemonListCount].seen = 1;
                gUnknown_02039B4C->unk0[gUnknown_02039B4C->pokemonListCount].owned = 1;
                gUnknown_02039B4C->pokemonListCount++;
            }
        }
        break;
    case 5:
        for (i = 0; i < NATIONAL_DEX_COUNT; i++)
        {
            vars[2] = gPokedexOrder_Height[i];

            if (NationalToHoennOrder(vars[2]) <= vars[0] && GetSetPokedexFlag(vars[2], 1))
            {
                gUnknown_02039B4C->unk0[gUnknown_02039B4C->pokemonListCount].dexNum = vars[2];
                gUnknown_02039B4C->unk0[gUnknown_02039B4C->pokemonListCount].seen = 1;
                gUnknown_02039B4C->unk0[gUnknown_02039B4C->pokemonListCount].owned = 1;
                gUnknown_02039B4C->pokemonListCount++;
            }
        }
        break;
    }

    for (i = gUnknown_02039B4C->pokemonListCount; i < NATIONAL_DEX_COUNT; i++)
    {
        gUnknown_02039B4C->unk0[i].dexNum |= 0xFFFF;
        gUnknown_02039B4C->unk0[i].seen = 0;
        gUnknown_02039B4C->unk0[i].owned = 0;
    }
}

void sub_80BCE2C(u8 a, u8 b, const u8* str, u8 c, u8 d)
{
    u8 sp14[3];
    
    sp14[0] = 0;
    sp14[1] = 15;
    sp14[2] = 3;
    AddTextPrinterParameterized2(a, b, c * 8, (d * 8) + 1, 0, 0, sp14, -1, str);
}

void sub_80BCE84(u8 a, u16 b, u16 c)
{
    s16 _b;
    u16 i;
    u16 r2;

    switch (a)
    {
    case 0:
    default:
        _b = b - 5;
        for (i = 0; i <= 10; i++)
        {
            if (_b < 0 || _b >= NATIONAL_DEX_COUNT || gUnknown_02039B4C->unk0[_b].dexNum == 0xFFFF)
            {
                sub_80BD28C(0x11, i * 2, c);
            }
            else
            {
                sub_80BD28C(0x11, i * 2, c);
                if (gUnknown_02039B4C->unk0[_b].seen)
                {
                    sub_80BD154(_b, 0x12, i * 2, c);
                    sub_80BD1F4(gUnknown_02039B4C->unk0[_b].owned, 0x11, i * 2, c);
                    sub_80BD23C(gUnknown_02039B4C->unk0[_b].dexNum, 0x16, i * 2);
                }
                else
                {
                    sub_80BD154(_b, 0x12, i * 2, c);
                    sub_80BD1F4(0, 0x11, i * 2, c);
                    sub_80BD23C(0, 0x16, i * 2);
                }
            }
            _b++;
        }
        break;
    case 1:
        _b = b - 5;
        if (_b < 0 || _b >= NATIONAL_DEX_COUNT || gUnknown_02039B4C->unk0[_b].dexNum == 0xFFFF)
        {
            sub_80BD28C(0x11, gUnknown_02039B4C->unk630 * 2, c);
        }
        else
        {
            sub_80BD28C(0x11, gUnknown_02039B4C->unk630 * 2, c);
            if (gUnknown_02039B4C->unk0[_b].seen)
            {
                sub_80BD154(_b, 0x12, gUnknown_02039B4C->unk630 * 2, c);
                sub_80BD1F4(gUnknown_02039B4C->unk0[_b].owned, 0x11, gUnknown_02039B4C->unk630 * 2, c);
                sub_80BD23C(gUnknown_02039B4C->unk0[_b].dexNum, 0x16, gUnknown_02039B4C->unk630 * 2);
            }
            else
            {
                sub_80BD154(_b, 0x12, gUnknown_02039B4C->unk630 * 2, c);
                sub_80BD1F4(0, 0x11, gUnknown_02039B4C->unk630 * 2, c);
                sub_80BD23C(0, 0x16, gUnknown_02039B4C->unk630 * 2);
            }
        }
        break;
    case 2:
        _b = b + 5;
        r2 = gUnknown_02039B4C->unk630 + 10;
        if (r2 > 15)
            r2 -= 16;
        if (_b < 0 || _b >= NATIONAL_DEX_COUNT || gUnknown_02039B4C->unk0[_b].dexNum == 0xFFFF)
            sub_80BD28C(0x11, r2 * 2, c);
        else
        {
            sub_80BD28C(0x11, r2 * 2, c);
            if (gUnknown_02039B4C->unk0[_b].seen)
            {
                sub_80BD154(_b, 0x12, r2 * 2, c);
                sub_80BD1F4(gUnknown_02039B4C->unk0[_b].owned, 0x11, r2 * 2, c);
                sub_80BD23C(gUnknown_02039B4C->unk0[_b].dexNum, 0x16, r2 * 2);
            }
            else
            {
                sub_80BD154(_b, 0x12, r2 * 2, c);
                sub_80BD1F4(0, 0x11, r2 * 2, c);
                sub_80BD23C(0, 0x16, r2 * 2);
            }
        }
        break;
    }
    CopyWindowToVram(0, 2);
}

void sub_80BD154(u16 a, u8 b, u8 c, u16 unused)
{
    u8 text[6];
    u16 r6;
    
    memcpy(text, gUnknown_0855D2B8, 6);
    r6 = gUnknown_02039B4C->unk0[a].dexNum;
    if (gUnknown_02039B4C->dexMode == DEX_MODE_HOENN)
        r6 = NationalToHoennOrder(r6);
    text[2] = CHAR_0 + r6 / 100;
    text[3] = CHAR_0 + (r6 % 100) / 10;
    text[4] = CHAR_0 + (r6 % 100) % 10;
    sub_80BCE2C(0, 7, text, b, c);
}

void sub_80BD1F4(u16 a, u8 b, u8 c, u16 unused)
{
    if (a)
        BlitBitmapToWindow(0, gUnknown_0855D2BE, b * 8, c * 8, 8, 16);
    else
        FillWindowPixelRect(0, 0, b * 8, c * 8, 8, 16);
}

u8 sub_80BD23C(u16 num, u8 b, u8 c)
{
    const u8* str;
    
    num = NationalPokedexNumToSpecies(num);
    if (num)
        str = gSpeciesNames[num];
    else
        str = sText_TenDashes;
    sub_80BCE2C(0, 7, str, b, c);
    return StringLength(str);
}

void sub_80BD28C(u8 a, u8 b, u16 unused)
{
    FillWindowPixelRect(0, 0, a * 8, b * 8, 0x60, 16);
}

void sub_80BD2B4(u16 a, u16 b)
{
    u8 i;
    u16 unk;
    u8 spriteId;
    
    gPaletteFade.bufferTransferDisabled = TRUE;

    for (i = 0; i < 4; i++)
        gUnknown_02039B4C->unk61E[i] = 0xFFFF;
    gUnknown_02039B4C->selectedMonSpriteId = 0xFFFF;

    unk = sub_80BDA8C(a - 1);
    if (unk != 0xFFFF)
    {
        spriteId = sub_80BDACC(unk, 0x60, 0x50);
        gSprites[spriteId].callback = sub_80BE4E0;
        gSprites[spriteId].data[5] = -32;
    }

    unk = sub_80BDA8C(a);
    if (unk != 0xFFFF)
    {
        spriteId = sub_80BDACC(unk, 0x60, 0x50);
        gSprites[spriteId].callback = sub_80BE4E0;
        gSprites[spriteId].data[5] = 0;
    }

    unk = sub_80BDA8C(a + 1);
    if (unk != 0xFFFF)
    {
        spriteId = sub_80BDACC(unk, 0x60, 0x50);
        gSprites[spriteId].callback = sub_80BE4E0;
        gSprites[spriteId].data[5] = 32;
    }
    
    sub_80BCE84(0, a, b);
    SetGpuReg(REG_OFFSET_BG2VOFS, gUnknown_02039B4C->unk62D);

    gUnknown_02039B4C->unk630 = 0;
    gUnknown_02039B4C->unk632 = 0;
    
    gPaletteFade.bufferTransferDisabled = FALSE;
}

bool8 sub_80BD404(u8 a, u8 b, u8 c)
{
    u16 i;
    u8 foo;

    if (gUnknown_02039B4C->unk62E)
    {
        gUnknown_02039B4C->unk62E--;
        switch (a)
        {
        case 1:
            for (i = 0; i < 4; i++)
            {
                if (gUnknown_02039B4C->unk61E[i] != 0xFFFF)
                    gSprites[gUnknown_02039B4C->unk61E[i]].data[5] += b;
            }
            foo = 16 * (c - gUnknown_02039B4C->unk62E) / c;
            SetGpuReg(REG_OFFSET_BG2VOFS, gUnknown_02039B4C->unk62D + gUnknown_02039B4C->unk632 * 16 - foo);
            gUnknown_02039B4C->unk62C -= gUnknown_02039B4C->unk628;
            break;
        case 2:
            for (i = 0; i < 4; i++)
            {
                if (gUnknown_02039B4C->unk61E[i] != 0xFFFF)
                    gSprites[gUnknown_02039B4C->unk61E[i]].data[5] -= b;
            }
            foo = 16 * (c - gUnknown_02039B4C->unk62E) / c;
            SetGpuReg(REG_OFFSET_BG2VOFS, gUnknown_02039B4C->unk62D + gUnknown_02039B4C->unk632 * 16 + foo);
            gUnknown_02039B4C->unk62C += gUnknown_02039B4C->unk628;
            break;
        }
        return FALSE;
    }
    else
    {
        SetGpuReg(REG_OFFSET_BG2VOFS, gUnknown_02039B4C->unk62D + gUnknown_02039B4C->unk630 * 16);
        return TRUE;
    }
}

void sub_80BD5A8(u8 a, u16 b)
{
    u16 unk;
    u8 spriteId;

    gUnknown_02039B4C->unk632 = gUnknown_02039B4C->unk630;
    switch (a)
    {
    case 1:
        unk = sub_80BDA8C(b - 1);
        if (unk != 0xFFFF)
        {
            spriteId = sub_80BDACC(unk, 0x60, 0x50);
            gSprites[spriteId].callback = sub_80BE4E0;
            gSprites[spriteId].data[5] = -64;
        }
        if (gUnknown_02039B4C->unk630 > 0)
            gUnknown_02039B4C->unk630--;
        else
            gUnknown_02039B4C->unk630 = 15;
        break;
    case 2:
        unk = sub_80BDA8C(b + 1);
        if (unk != 0xFFFF)
        {
            spriteId = sub_80BDACC(unk, 0x60, 0x50);
            gSprites[spriteId].callback = sub_80BE4E0;
            gSprites[spriteId].data[5] = 0x40;
        }
        if (gUnknown_02039B4C->unk630 <= 0xE)
            gUnknown_02039B4C->unk630++;
        else
            gUnknown_02039B4C->unk630 = 0;
        break;
    }
}

u16 sub_80BD69C(u16 a, u16 b)
{
    u8 r3;
    u8 r5;
    u8 i;
    u16 r6;
    u8 r10 = 0;
    
    if ((gMain.heldKeys & DPAD_UP) && (a > 0))
    {
        r10 = 1;
        a = sub_80C0E0C(1, a, 0, gUnknown_02039B4C->pokemonListCount - 1);
        sub_80BD5A8(1, a);
        sub_80BCE84(1, a, b);
        PlaySE(SE_Z_SCROLL);
    }
    else if ((gMain.heldKeys & DPAD_DOWN) && (a < gUnknown_02039B4C->pokemonListCount - 1))
    {
        r10 = 2;
        a = sub_80C0E0C(0, a, 0, gUnknown_02039B4C->pokemonListCount - 1);
        sub_80BD5A8(2, a);
        sub_80BCE84(2, a, b);
        PlaySE(SE_Z_SCROLL);
    }
    else if ((gMain.newKeys & DPAD_LEFT) && (a > 0))
    {
        r6 = a;
                
        for (i = 0; i < 7; i++)
            a = sub_80C0E0C(1, a, 0, gUnknown_02039B4C->pokemonListCount - 1);
        gUnknown_02039B4C->unk62C += 16 * (a - r6);
        sub_80BDA40();
        sub_80BD2B4(a, 0xE);
        PlaySE(SE_Z_PAGE);
    }
    else if ((gMain.newKeys & DPAD_RIGHT) && (a < gUnknown_02039B4C->pokemonListCount - 1))
    {
        r6 = a;
        for (i = 0; i < 7; i++)
            a = sub_80C0E0C(0, a, 0, gUnknown_02039B4C->pokemonListCount - 1);
        gUnknown_02039B4C->unk62C += (a - r6) * 16;
        sub_80BDA40();
        sub_80BD2B4(a, 0xE);
        PlaySE(SE_Z_PAGE);
    }
    
    if (r10 == 0)
    {
        gUnknown_02039B4C->unk638 = 0;
        return a;
    }
    
    r5 = gUnknown_0855D28C[gUnknown_02039B4C->unk638 / 4];
    r3 = gUnknown_0855D291[gUnknown_02039B4C->unk638 / 4];
    gUnknown_02039B4C->unk62E = r3;
    gUnknown_02039B4C->unk636 = r3;
    gUnknown_02039B4C->unk634 = r5;
    gUnknown_02039B4C->unk62F = r10;
    gUnknown_02039B4C->unk628 = r5 / 2;
    sub_80BD404(gUnknown_02039B4C->unk62F, gUnknown_02039B4C->unk634, gUnknown_02039B4C->unk636);
    if (gUnknown_02039B4C->unk638 <= 0xB)
        gUnknown_02039B4C->unk638++;
    return a;
}

void sub_80BD8D0(void)
{
    u16 i;

    for (i = 0; i < 4; i++)
    {
        u16 spriteId = gUnknown_02039B4C->unk61E[i];

        if (gSprites[spriteId].pos2.x == 0 && gSprites[spriteId].pos2.y == 0 && spriteId != 0xFFFF)
            gUnknown_02039B4C->selectedMonSpriteId = spriteId;
    }
}

u8 sub_80BD930(void)
{
    u16 r2;
    u16 r4 = gUnknown_02039B4C->selectedPokemon;

    if ((gMain.newKeys & DPAD_UP) && r4)
    {
        r2 = r4;
        while (r2 != 0)
        {
            r2 = sub_80C0E0C(1, r2, 0, gUnknown_02039B4C->pokemonListCount - 1);

            if (gUnknown_02039B4C->unk0[r2].seen)
            {
                r4 = r2;
                break;
            }
        }

        if (gUnknown_02039B4C->selectedPokemon == r4)
            return FALSE;
        else
        {
            gUnknown_02039B4C->selectedPokemon = r4;
            gUnknown_02039B4C->unk62C -= 16;
            return TRUE;
        }
    }
    else if ((gMain.newKeys & DPAD_DOWN) && r4 < gUnknown_02039B4C->pokemonListCount - 1)
    {
        r2 = r4;
        while (r2 < gUnknown_02039B4C->pokemonListCount - 1)
        {
            r2 = sub_80C0E0C(0, r2, 0, gUnknown_02039B4C->pokemonListCount - 1);

            if (gUnknown_02039B4C->unk0[r2].seen)
            {
                r4 = r2;
                break;
            }
        }

        if (gUnknown_02039B4C->selectedPokemon == r4)
            return FALSE;
        else
        {
            gUnknown_02039B4C->selectedPokemon = r4;
            gUnknown_02039B4C->unk62C += 16;
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
        if (gUnknown_02039B4C->unk61E[i] != 0xFFFF)
        {
            sub_818D820(gUnknown_02039B4C->unk61E[i]);
            gUnknown_02039B4C->unk61E[i] |= 0xFFFF;
        }
    }
    return FALSE;
}

u16 sub_80BDA8C(u16 a1)
{
    if (a1 >= NATIONAL_DEX_COUNT || gUnknown_02039B4C->unk0[a1].dexNum == 0xFFFF)
        return 0xFFFF;
    else if (gUnknown_02039B4C->unk0[a1].seen)
        return gUnknown_02039B4C->unk0[a1].dexNum;
    else
        return 0;
}

u32 sub_80BDACC(u16 a, s16 b, s16 c)
{
    u8 i;

    for (i = 0; i < 4; i++)
    {
        if (gUnknown_02039B4C->unk61E[i] == 0xFFFF)
        {
            u8 spriteId = sub_80C0E9C(a, b, c, i);

            gSprites[spriteId].oam.affineMode = 1;
            gSprites[spriteId].oam.priority = 3;
            gSprites[spriteId].data[0] = 0;
            gSprites[spriteId].data[1] = i;
            gSprites[spriteId].data[2] = NationalPokedexNumToSpecies(a);
            gUnknown_02039B4C->unk61E[i] = spriteId;
            return spriteId;
        }
    }
    return 0xFFFF;
}

void sub_80BDB7C(u8 a)
{
    u8 spriteId;
    u16 r5;

    spriteId = CreateSprite(&gUnknown_0855D1AC, 184, 4, 0);
    gSprites[spriteId].data[1] = 0;

    spriteId = CreateSprite(&gUnknown_0855D1AC, 184, 156, 0);
    gSprites[spriteId].data[1] = 1;
    gSprites[spriteId].vFlip = TRUE;

    CreateSprite(&gUnknown_0855D194, 230, 20, 0);
    CreateSprite(&gUnknown_0855D1C4, 16, 120, 0);

    spriteId = CreateSprite(&gUnknown_0855D1C4, 48, 120, 0);
    StartSpriteAnim(&gSprites[spriteId], 3);

    spriteId = CreateSprite(&gUnknown_0855D1C4, 16, 144, 0);
    StartSpriteAnim(&gSprites[spriteId], 2);
    gSprites[spriteId].data[2] = 0x80;

    spriteId = CreateSprite(&gUnknown_0855D1C4, 48, 144, 0);
    StartSpriteAnim(&gSprites[spriteId], 1);

    spriteId = CreateSprite(&gUnknown_0855D1DC, 0, 80, 2);
    gSprites[spriteId].oam.affineMode = 1;
    gSprites[spriteId].oam.matrixNum = 30;
    gSprites[spriteId].data[0] = 0x1E;
    gSprites[spriteId].data[1] = 0;

    spriteId = CreateSprite(&gUnknown_0855D1DC, 0, 80, 2);
    gSprites[spriteId].oam.affineMode = 1;
    gSprites[spriteId].oam.matrixNum = 31;
    gSprites[spriteId].data[0] = 0x1F;
    gSprites[spriteId].data[1] = 0x80;

    if (a == 0)
    {
        u32 _a;
        
        if (!IsNationalPokedexEnabled())
        {
            CreateSprite(&gUnknown_0855D1F4, 32, 40, 1);

            spriteId = CreateSprite(&gUnknown_0855D1F4, 32, 72, 1);
            StartSpriteAnim(&gSprites[spriteId], 1);
            _a = 0;

            spriteId = CreateSprite(&gUnknown_0855D224, 24, 48, 1);
            r5 = gUnknown_02039B4C->unk61A / 100;
            StartSpriteAnim(&gSprites[spriteId], r5);
            if (r5 != 0)
                _a = 1;
            else
                gSprites[spriteId].invisible = TRUE;

            spriteId = CreateSprite(&gUnknown_0855D224, 32, 48, 1);
            r5 = (gUnknown_02039B4C->unk61A % 100) / 10;
            if (r5 != 0 || _a != 0)
                StartSpriteAnim(&gSprites[spriteId], r5);
            else
                gSprites[spriteId].invisible = TRUE;

            spriteId = CreateSprite(&gUnknown_0855D224, 40, 48, 1);
            r5 = (gUnknown_02039B4C->unk61A % 100) % 10;
            StartSpriteAnim(&gSprites[spriteId], r5);
            _a = 0;

            spriteId = CreateSprite(&gUnknown_0855D224, 24, 80, 1);
            r5 = gUnknown_02039B4C->unk61C / 100;
            StartSpriteAnim(&gSprites[spriteId], r5);
            if (r5 != 0)
                _a = 1;
            else
                gSprites[spriteId].invisible = TRUE;

            spriteId = CreateSprite(&gUnknown_0855D224, 32, 80, 1);
            r5 = (gUnknown_02039B4C->unk61C % 100) / 10;
            if (r5 != 0 || _a != 0)
                StartSpriteAnim(&gSprites[spriteId], r5);
            else
                gSprites[spriteId].invisible = TRUE;

            spriteId = CreateSprite(&gUnknown_0855D224, 40, 80, 1);
            r5 = (gUnknown_02039B4C->unk61C % 100) % 10;
            StartSpriteAnim(&gSprites[spriteId], r5);
        }
        else
        {
            u16 r6;
            
            CreateSprite(&gUnknown_0855D1F4, 32, 40, 1);

            spriteId = CreateSprite(&gUnknown_0855D1F4, 32, 76, 1);
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
            r5 = gUnknown_02039B4C->unk61A / 100;
            StartSpriteAnim(&gSprites[spriteId], r5);
            if (r5 != 0)
                _a = 1;
            else
                gSprites[spriteId].invisible = TRUE;
            
            spriteId = CreateSprite(&gUnknown_0855D23C, 48, 55, 1);
            r5 = (gUnknown_02039B4C->unk61A % 100) / 10;
            if (r5 != 0 || _a != 0)
                StartSpriteAnim(&gSprites[spriteId], r5);
            else
                gSprites[spriteId].invisible = TRUE;
            
            spriteId = CreateSprite(&gUnknown_0855D23C, 56, 55, 1);
            r5 = (gUnknown_02039B4C->unk61A % 100) % 10;
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
            r5 = gUnknown_02039B4C->unk61C / 100;
            StartSpriteAnim(&gSprites[spriteId], r5);
            if (r5 != 0)
                _a = 1;
            else
                gSprites[spriteId].invisible = TRUE;
            
            spriteId = CreateSprite(&gUnknown_0855D23C, 48, 91, 1);
            r5 = (gUnknown_02039B4C->unk61C % 100) / 10;
            if (r5 != 0 || _a != 0)
                StartSpriteAnim(&gSprites[spriteId], r5);
            else
                gSprites[spriteId].invisible = TRUE;
            
            spriteId = CreateSprite(&gUnknown_0855D23C, 56, 91, 1);
            r5 = (gUnknown_02039B4C->unk61C % 100) % 10;
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
    if (gUnknown_02039B4C->unk64A != 0)
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

    if (gUnknown_02039B4C->unk64A != 0 && gUnknown_02039B4C->unk64A != 3)
    {
        sub_818D820(gUnknown_02039B4C->unk61E[data1]);
        gUnknown_02039B4C->unk61E[data1] = 0xFFFF;
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
            sub_818D820(gUnknown_02039B4C->unk61E[data1]);
            gUnknown_02039B4C->unk61E[data1] = 0xFFFF;
        }
    }
}

void sub_80BE604(struct Sprite *sprite)
{
    if (gUnknown_02039B4C->unk64A != 0 && gUnknown_02039B4C->unk64A != 3)
        DestroySprite(sprite);
    else
        sprite->pos2.y = gUnknown_02039B4C->selectedPokemon * 120 / (gUnknown_02039B4C->pokemonListCount - 1);
}

void sub_80BE658(struct Sprite *sprite)
{
    if (gUnknown_02039B4C->unk64A != 0 && gUnknown_02039B4C->unk64A != 3)
    {
        DestroySprite(sprite);
    }
    else
    {
        u8 r0;

        if (sprite->data[1] != 0)
        {
            if (gUnknown_02039B4C->selectedPokemon == gUnknown_02039B4C->pokemonListCount - 1)
                sprite->invisible = TRUE;
            else
                sprite->invisible = FALSE;
            r0 = sprite->data[2];
        }
        else
        {
            if (gUnknown_02039B4C->selectedPokemon == 0)
                sprite->invisible = TRUE;
            else
                sprite->invisible = FALSE;
            r0 = sprite->data[2] - 128;
        }
        sprite->pos2.y = gSineTable[r0] / 64;
        sprite->data[2] = sprite->data[2] + 8;
        if (gUnknown_02039B4C->menuIsOpen == 0 && gUnknown_02039B4C->menuY == 0 && sprite->invisible == 0)
            sprite->invisible = FALSE;
        else
            sprite->invisible = TRUE;
    }
}

void sub_80BE758(struct Sprite *sprite)
{
    if (gUnknown_02039B4C->unk64A != 0 && gUnknown_02039B4C->unk64A != 3)
        DestroySprite(sprite);
}

void sub_80BE780(struct Sprite *sprite)
{
    if (gUnknown_02039B4C->unk64A != 0 && gUnknown_02039B4C->unk64A != 3)
    {
        DestroySprite(sprite);
    }
    else
    {
        u8 val;
        s16 r3;
        s16 r0;

        val = gUnknown_02039B4C->unk62C + sprite->data[1];
        r3 = gSineTable[val];
        r0 = gSineTable[val + 0x40];
        SetOamMatrix(sprite->data[0], r0, r3, -r3, r0);

        val = gUnknown_02039B4C->unk62C + (sprite->data[1] + 0x40);
        r3 = gSineTable[val];
        r0 = gSineTable[val + 0x40];
        sprite->pos2.x = r0 * 40 / 256;
        sprite->pos2.y = r3 * 40 / 256;
    }
}

void sub_80BE834(struct Sprite *sprite)
{
    if (gUnknown_02039B4C->unk64A != 0 && gUnknown_02039B4C->unk64A != 3)
    {
        DestroySprite(sprite);
    }
    else
    {
        u16 r1 = gUnknown_02039B4C->unk64A == 0 ? 80 : 96;

        if (gUnknown_02039B4C->menuIsOpen != 0 && gUnknown_02039B4C->menuY == r1)
        {
            sprite->invisible = FALSE;
            sprite->pos2.y = gUnknown_02039B4C->menuCursorPos * 16;
            sprite->pos2.x = gSineTable[(u8)sprite->data[2]] / 64;
            sprite->data[2] += 8;
        }
        else
        {
            sprite->invisible = TRUE;
        }
    }
}

void sub_80BE8DC(const u8* a, u8 b, u8 c)
{
    u8 sp14[3];
    sp14[0] = 0;
    sp14[1] = 15;
    sp14[2] = 3;
    
    AddTextPrinterParameterized2(0, 1, b, c, 0, 0, sp14, -1, a);
}

u8 sub_80BE91C(struct PokedexListItem* item, u8 b)
{
    u8 taskId;
    
    gUnknown_02039B54 = item;
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
    gUnknown_02039B54 = item;
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

                gUnknown_02039B4C->unk64A = 1;
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
            copy_decompressed_tile_data_to_vram_autofree(3, gPokedexMenu_Gfx, 0x2000, 0, 0);
            CopyToBgTilemapBuffer(3, gUnknown_08DC3080, 0, 0);
            FillWindowPixelBuffer(0, 0);
            PutWindowTilemap(0);
            PutWindowTilemap(1);
            sub_80C0D30(1, gUnknown_02039B54->dexNum);
            CopyWindowToVram(1, 2);
            gMain.state++;
            break;
        case 2:
            sub_80BFCDC(0xD);
            sub_80BFD0C(gUnknown_02039B4C->selectedScreen, 0xD);
            sub_80BC844(gUnknown_02039B4C->unk64C_1);
            gMain.state++;
            break;
        case 3:
            gMain.state++;
            break;
        case 4:
            sub_80C020C(gUnknown_02039B54->dexNum, gUnknown_02039B4C->dexMode == 0 ? 0 : 1, gUnknown_02039B54->owned, 0);
            if (!gUnknown_02039B54->owned)
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
                gTasks[taskId].data[4] = (u16)sub_80C0E9C(gUnknown_02039B54->dexNum, 0x30, 0x38, 0);
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
                BeginNormalPaletteFade(~r3, 0, 16, 0, 0);
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
                    PlayCry2(NationalPokedexNumToSpecies(gUnknown_02039B54->dexNum), 0, 0x7D, 0xA);
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
        BeginNormalPaletteFade(-1, 0, 0, 16, 0);
        gTasks[taskId].func = sub_80BF038;
        PlaySE(SE_Z_SCROLL);
        return;
    }
    if (gMain.newKeys & B_BUTTON)
    {
        BeginNormalPaletteFade(-1, 0, 0, 16, 0);
        gTasks[taskId].func = sub_80BF070;
        PlaySE(SE_PC_OFF);
        return;
    }
    if (gMain.newKeys & A_BUTTON)
    {
        switch (gUnknown_02039B4C->selectedScreen)
        {
        case AREA_SCREEN:
            BeginNormalPaletteFade(-0x15, 0, 0, 16, 0);
            gUnknown_02039B4C->unk64E = 1;
            gTasks[taskId].func = sub_80BEFD0;
            PlaySE(SE_PIN);
            break;
        case CRY_SCREEN:
            BeginNormalPaletteFade(-0x15, 0, 0, 0x10, 0);
            gUnknown_02039B4C->unk64E = 2;
            gTasks[taskId].func = sub_80BEFD0;
            PlaySE(SE_PIN);
            break;
        case SIZE_SCREEN:
            if (!gUnknown_02039B54->owned)
            {
                PlaySE(SE_HAZURE);
            }
            else
            {
                BeginNormalPaletteFade(-0x15, 0, 0, 0x10, 0);
                gUnknown_02039B4C->unk64E = 3;
                gTasks[taskId].func = sub_80BEFD0;
                PlaySE(SE_PIN);
            }
            break;
        case CANCEL_SCREEN:
            BeginNormalPaletteFade(-1, 0, 0, 0x10, 0);
            gTasks[taskId].func = sub_80BF070;
            PlaySE(SE_PC_OFF);
            break;
        }
        return;
    }
    if (((gMain.newKeys & DPAD_LEFT)
     || ((gMain.newKeys & L_BUTTON) && gSaveBlock2Ptr->optionsButtonMode == OPTIONS_BUTTON_MODE_LR))
     && gUnknown_02039B4C->selectedScreen > 0)
    {
        gUnknown_02039B4C->selectedScreen--;
        sub_80BFD0C(gUnknown_02039B4C->selectedScreen, 0xD);
        PlaySE(SE_Z_PAGE);
        return;
    }
    if (((gMain.newKeys & DPAD_RIGHT)
     || ((gMain.newKeys & R_BUTTON) && gSaveBlock2Ptr->optionsButtonMode == OPTIONS_BUTTON_MODE_LR))
     && gUnknown_02039B4C->selectedScreen < 3)
    {
        gUnknown_02039B4C->selectedScreen++;
        sub_80BFD0C(gUnknown_02039B4C->selectedScreen, 0xD);
        PlaySE(SE_Z_PAGE);
        return;
    }
}

void sub_80BEFD0(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        sub_818D820(gTasks[taskId].data[4]);
        switch (gUnknown_02039B4C->unk64E)
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
        sub_818D820(gTasks[taskId].data[4]);
        gTasks[taskId].func = sub_80BEA24;
    }
}

void sub_80BF070(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        sub_818D820(gTasks[taskId].data[4]);
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
                gUnknown_02039B4C->unk64A = 5;
                gUnknown_030060B4 = gMain.vblankCallback;
                SetVBlankCallback(NULL);
                sub_80C09B0(0x200);
                gUnknown_02039B4C->selectedScreen = AREA_SCREEN;
                gMain.state = 1;
            }
            break;
        case 1:
            sub_80BFCF4(0xD);
            sub_80BFD7C(0, 0xD);
            sub_80BC844(gUnknown_02039B4C->unk64C_1);
            SetGpuReg(REG_OFFSET_BG1CNT, BGCNT_PRIORITY(0) | BGCNT_CHARBASE(0) | BGCNT_SCREENBASE(13) | BGCNT_16COLOR | BGCNT_TXT256x256);
            gMain.state++;
            break;
        case 2:
            sub_813D3D8(NationalPokedexNumToSpecies(gUnknown_02039B54->dexNum), &gUnknown_02039B4C->unk64E);
            SetVBlankCallback(gUnknown_030060B4);
            gUnknown_02039B4C->unk64E = 0;
            gMain.state = 0;
            gTasks[taskId].func = sub_80BF1B4;
            break;
    }
}

void sub_80BF1B4(u8 taskId)
{
    if (gUnknown_02039B4C->unk64E != 0)
        gTasks[taskId].func = sub_80BF1EC;
}

void sub_80BF1EC(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        switch (gUnknown_02039B4C->unk64E)
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
                gUnknown_02039B4C->unk64A = 6;
                gUnknown_030060B4 = gMain.vblankCallback;
                SetVBlankCallback(NULL);
                sub_80C09B0(0x200);
                gUnknown_02039B4C->selectedScreen = CRY_SCREEN;
                gMain.state = 1;
            }
            break;
        case 1:
            copy_decompressed_tile_data_to_vram_autofree(3, &gPokedexMenu_Gfx, 0x2000, 0, 0);
            CopyToBgTilemapBuffer(3, &gUnknown_08DC3198, 0, 0);
            FillWindowPixelBuffer(0, 0);
            PutWindowTilemap(0);
            PutWindowTilemap(3);
            PutWindowTilemap(2);
            gMain.state++;
            break;
        case 2:
            sub_80BFCF4(0xD);
            sub_80BFD7C(1, 0xD);
            sub_80BC844(gUnknown_02039B4C->unk64C_1);
            gMain.state++;
            break;
        case 3:
            ResetPaletteFade();
            gMain.state++;
            break;
        case 4:
            sub_80BE8DC(gText_CryOf, 0x52, 33);
            sub_80C0B44(0, gUnknown_02039B54->dexNum, 0x52, 49);
            gMain.state++;
            break;
        case 5:
            gTasks[taskId].data[4] = sub_80C0E9C(gUnknown_02039B54->dexNum, 48, 56, 0);
            gSprites[gTasks[taskId].data[4]].oam.priority = 0;
            gUnknown_030061EC = 0;
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
                    gUnknown_030061EC = 0;
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
            BeginNormalPaletteFade(-0x15, 0, 0x10, 0, 0);
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
            gUnknown_02039B4C->unk64E = 0;
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
        sub_8145534(NationalPokedexNumToSpecies(gUnknown_02039B54->dexNum));
        return;
    }
    else if (!gPaletteFade.active)
    {
        if (gMain.newKeys & B_BUTTON)
        {
            BeginNormalPaletteFade(-0x15, 0, 0, 0x10, 0);
            m4aMPlayContinue(&gMPlayInfo_BGM);
            gUnknown_02039B4C->unk64E = 1;
            gTasks[taskId].func = sub_80BF790;
            PlaySE(SE_PC_OFF);
            return;
        }
        if ((gMain.newKeys & DPAD_LEFT)
         || ((gMain.newKeys & L_BUTTON) && gSaveBlock2Ptr->optionsButtonMode == OPTIONS_BUTTON_MODE_LR))
        {
            BeginNormalPaletteFade(-0x15, 0, 0, 0x10, 0);
            m4aMPlayContinue(&gMPlayInfo_BGM);
            gUnknown_02039B4C->unk64E = 2;
            gTasks[taskId].func = sub_80BF790;
            PlaySE(SE_Z_PAGE);
            return;
        }
        if ((gMain.newKeys & DPAD_RIGHT)
         || ((gMain.newKeys & R_BUTTON) && gSaveBlock2Ptr->optionsButtonMode == OPTIONS_BUTTON_MODE_LR))
        {
            if (!gUnknown_02039B54->owned)
            {
                PlaySE(SE_HAZURE);
            }
            else
            {
                BeginNormalPaletteFade(-0x15, 0, 0, 0x10, 0);
                m4aMPlayContinue(&gMPlayInfo_BGM);
                gUnknown_02039B4C->unk64E = 3;
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
        sub_818D820(gTasks[taskId].data[4]);
        switch (gUnknown_02039B4C->unk64E)
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
        unk = 0x392;
    else
        unk = 0x2AF;
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
            gUnknown_02039B4C->unk64A = 7;
            gUnknown_030060B4 = gMain.vblankCallback;
            SetVBlankCallback(NULL);
            sub_80C09B0(0x200);
            gUnknown_02039B4C->selectedScreen = SIZE_SCREEN;
            gMain.state = 1;
        }
        break;
    case 1:
        copy_decompressed_tile_data_to_vram_autofree(3, gPokedexMenu_Gfx, 0x2000, 0, 0);
        CopyToBgTilemapBuffer(3, gUnknown_08DC2E6C, 0, 0);
        FillWindowPixelBuffer(0, 0);
        PutWindowTilemap(0);
        gMain.state++;
        break;
    case 2:
        sub_80BFCF4(0xD);
        sub_80BFD7C(2, 0xD);
        sub_80BC844(gUnknown_02039B4C->unk64C_1);
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
        gSprites[spriteId].pos2.y = gPokedexEntries[gUnknown_02039B54->dexNum].trainerOffset;
        SetOamMatrix(1, gPokedexEntries[gUnknown_02039B54->dexNum].trainerScale, 0, 0, gPokedexEntries[gUnknown_02039B54->dexNum].trainerScale);
        LoadPalette(gUnknown_0856E610, (gSprites[spriteId].oam.paletteNum + 16) * 16, 0x20);
        gTasks[taskId].data[5] = spriteId;
        gMain.state++;
        break;
    case 6:
        spriteId = sub_80C0E9C(gUnknown_02039B54->dexNum, 88, 56, 1);
        gSprites[spriteId].oam.affineMode = 1;
        gSprites[spriteId].oam.matrixNum = 2;
        gSprites[spriteId].oam.priority = 0;
        gSprites[spriteId].pos2.y = gPokedexEntries[gUnknown_02039B54->dexNum].pokemonOffset;
        SetOamMatrix(2, gPokedexEntries[gUnknown_02039B54->dexNum].pokemonScale, 0, 0, gPokedexEntries[gUnknown_02039B54->dexNum].pokemonScale);
        LoadPalette(gUnknown_0856E610, (gSprites[spriteId].oam.paletteNum + 16) * 16, 0x20);
        gTasks[taskId].data[4] = spriteId;
        CopyWindowToVram(0, 3);
        CopyBgTilemapBufferToVram(1);
        CopyBgTilemapBufferToVram(2);
        CopyBgTilemapBufferToVram(3);
        gMain.state++;
        break;
    case 7:
        BeginNormalPaletteFade(-0x15, 0, 0x10, 0, 0);
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
            gUnknown_02039B4C->unk64E = 0;
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
        BeginNormalPaletteFade(-0x15, 0, 0, 0x10, 0);
        gUnknown_02039B4C->unk64E = 1;
        gTasks[taskId].func = sub_80BFC78;
        PlaySE(SE_PC_OFF);
    }
    else if ((gMain.newKeys & DPAD_LEFT)
     || ((gMain.newKeys & L_BUTTON) && gSaveBlock2Ptr->optionsButtonMode == OPTIONS_BUTTON_MODE_LR))
    {
        BeginNormalPaletteFade(-0x15, 0, 0, 0x10, 0);
        gUnknown_02039B4C->unk64E = 2;
        gTasks[taskId].func = sub_80BFC78;
        PlaySE(SE_Z_PAGE);
    }
}

void sub_80BFC78(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        sub_818D820(gTasks[taskId].data[4]);
        sub_818D8F0(gTasks[taskId].data[5]);
        switch (gUnknown_02039B4C->unk64E)
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
    CopyToBgTilemapBuffer(1, gUnknown_08DC2F5C, 0, 0);
}

void sub_80BFCF4(u16 a)
{
    CopyToBgTilemapBuffer(1, gUnknown_08DC2FEC, 0, 0);
}

/* void sub_80BFD0C(u8 a, u16 unused)
{
    u8 i;
    u8 j;
    u16* r7 = GetBgTilemapBuffer(1);
    u8 r5;
    u16 r3;
    
    for (i = 0; i < 4; i++)
    {
        r5 = i * 7 + 1;
        if (i == a)
            r3 = 0x2000;
        else
            r3 = 0x4000;
        
        for (j = 0; j < 7; j++)
        {
            u32 r1 = (r5 + j);
            
            *(r7 + r1) = (*(r7 + r1) & 0xFFF) | r3;
            *(r7 + 0x40 + r1) = (*(r7 + 0x40 + r1) & 0xFFF) | r3;
        }
    }
    CopyBgTilemapBufferToVram(1);
} */
