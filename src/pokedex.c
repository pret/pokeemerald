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

extern u16 gUnknown_02039B50;
extern u8 gUnknown_02039B52;

extern u8 gUnknown_030060B0;

#define NATIONAL_DEX_COUNT 386

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

// this file's functions
void sub_80BE604(struct Sprite *sprite);
void sub_80BE658(struct Sprite *sprite);
void sub_80BE758(struct Sprite *sprite);
void sub_80BE780(struct Sprite *sprite);
void sub_80BE44C(struct Sprite *sprite);
void sub_80BE834(struct Sprite *sprite);

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

const struct CompressedSpritePalette gSpritePalettes_0855D26C[] =
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
