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

extern struct PokedexView *gUnknown_02039B4C;
extern u16 gUnknown_02039B50;
extern u8 gUnknown_02039B52;

extern u8 gUnknown_030060B0;

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
void sub_80BDA40(void);
u16 sub_80BDA8C(u16);
u16 sub_80BDACC(u16, u16, u16);
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
void sub_80BE9F8(struct PokedexListItem*, u8);
void sub_80C09B0(u8);
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
