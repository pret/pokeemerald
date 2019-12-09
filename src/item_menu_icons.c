#include "global.h"
#include "berry.h"
#include "decompress.h"
#include "graphics.h"
#include "item.h"
#include "item_menu.h"
#include "item_icon.h"
#include "item_menu_icons.h"
#include "menu_helpers.h"
#include "sprite.h"
#include "window.h"
#include "constants/items.h"

struct CompressedTilesPal
{
    const u32 *tiles;
    const u32 *pal;
};

// this file's functions
static void SpriteCB_BagVisualSwitchingPockets(struct Sprite *sprite);
static void SpriteCB_ShakeBagVisual(struct Sprite *sprite);
static void SpriteCB_SwitchPocketRotatingBallInit(struct Sprite *sprite);
static void SpriteCB_SwitchPocketRotatingBallContinue(struct Sprite *sprite);

// static const rom data
static const u16 gRotatingBall_Pal[] = INCBIN_U16("graphics/interface/bag_spinner.gbapal");
static const u8 gRotatingBall[] = INCBIN_U8("graphics/interface/bag_spinner.4bpp");
static const u8 gCherryUnused[] = INCBIN_U8("graphics/unused/cherry.4bpp");
static const u16 gCherryUnused_Pal[] = INCBIN_U16("graphics/unused/cherry.gbapal");

static const struct OamData sBagOamData =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_NORMAL,
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
    .affineParam = 0
};

static const union AnimCmd sSpriteAnim_Bag_Closed[] =
{
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_Bag_Items[] =
{
    ANIMCMD_FRAME(64, 4),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_Bag_KeyItems[] =
{
    ANIMCMD_FRAME(128, 4),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_Bag_Pokeballs[] =
{
    ANIMCMD_FRAME(192, 4),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_Bag_TMsHMs[] =
{
    ANIMCMD_FRAME(256, 4),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_Bag_Berries[] =
{
    ANIMCMD_FRAME(320, 4),
    ANIMCMD_END
};

static const union AnimCmd *const sBagSpriteAnimTable[] =
{
    sSpriteAnim_Bag_Closed,
    sSpriteAnim_Bag_Items,
    sSpriteAnim_Bag_Pokeballs,
    sSpriteAnim_Bag_TMsHMs,
    sSpriteAnim_Bag_Berries,
    sSpriteAnim_Bag_KeyItems
};

static const union AffineAnimCmd sSpriteAffineAnim_BagNormal[] =
{
    AFFINEANIMCMD_FRAME(256, 256, 0, 0),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd sSpriteAffineAnim_BagShake[] =
{
    AFFINEANIMCMD_FRAME(0, 0, 254, 2),
    AFFINEANIMCMD_FRAME(0, 0, 2, 4),
    AFFINEANIMCMD_FRAME(0, 0, 254, 4),
    AFFINEANIMCMD_FRAME(0, 0, 2, 2),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd *const sBagAffineAnimCmds[] =
{
    sSpriteAffineAnim_BagNormal,
    sSpriteAffineAnim_BagShake
};

const struct CompressedSpriteSheet gBagMaleSpriteSheet =
{
    gBagMaleTiles, 0x3000, TAG_BAG_GFX
};

const struct CompressedSpriteSheet gBagFemaleSpriteSheet =
{
    gBagFemaleTiles, 0x3000, TAG_BAG_GFX
};

const struct CompressedSpritePalette gBagPaletteTable =
{
    gBagPalette, TAG_BAG_GFX
};

static const struct SpriteTemplate gBagSpriteTemplate =
{
    .tileTag = TAG_BAG_GFX,
    .paletteTag = TAG_BAG_GFX,
    .oam = &sBagOamData,
    .anims = sBagSpriteAnimTable,
    .images = NULL,
    .affineAnims = sBagAffineAnimCmds,
    .callback = SpriteCallbackDummy,
};

static const struct OamData sRotatingBallOamData =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = 0,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(16x16),
    .x = 0,
    .matrixNum = 4,
    .size = SPRITE_SIZE(16x16),
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0,
    .affineParam = 0
};

static const union AnimCmd sSpriteAffineAnim_RotatingBallStationary[] =
{
    ANIMCMD_FRAME(0, 0),
    ANIMCMD_END
};

static const union AnimCmd *const sRotatingBallSpriteAnimTable[] =
{
    sSpriteAffineAnim_RotatingBallStationary
};

static const union AffineAnimCmd sSpriteAffineAnim_RotatingBallRotation1[] =
{
    AFFINEANIMCMD_FRAME(0, 0, 8, 16),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd sSpriteAffineAnim_RotatingBallRotation2[] =
{
    AFFINEANIMCMD_FRAME(0, 0, 248, 16),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd *const sRotatingBallAnimCmds[] =
{
    sSpriteAffineAnim_RotatingBallRotation1,
};

static const union AffineAnimCmd *const sRotatingBallAnimCmds_FullRotation[] =
{
    sSpriteAffineAnim_RotatingBallRotation2,
};

static const struct SpriteSheet gRotatingBallTable =
{
    gRotatingBall, 0x80, TAG_ROTATING_BALL_GFX
};

static const struct SpritePalette gRotatingBallPaletteTable =
{
    gRotatingBall_Pal, TAG_ROTATING_BALL_GFX
};

static const struct SpriteTemplate gRotatingBallSpriteTemplate =
{
    .tileTag = TAG_ROTATING_BALL_GFX,
    .paletteTag = TAG_ROTATING_BALL_GFX,
    .oam = &sRotatingBallOamData,
    .anims = sRotatingBallSpriteAnimTable,
    .images = NULL,
    .affineAnims = sRotatingBallAnimCmds,
    .callback = SpriteCB_SwitchPocketRotatingBallInit,
};

static const struct OamData sBerryPicOamData =
{
    .y = 0,
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
    .paletteNum = 7,
    .affineParam = 0
};

static const struct OamData sBerryPicRotatingOamData =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_DOUBLE,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = 0,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(64x64),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(64x64),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 7,
    .affineParam = 0
};

static const union AnimCmd sSpriteAnim_857FBD8[] =
{
    ANIMCMD_FRAME(0, 0),
    ANIMCMD_END
};

static const union AnimCmd *const sBerryPicSpriteAnimTable[] =
{
    sSpriteAnim_857FBD8
};

static const struct SpriteFrameImage sBerryPicSpriteImageTable[] =
{
    {&gDecompressionBuffer[0], 0x800},
};

static const struct SpriteTemplate gBerryPicSpriteTemplate =
{
    .tileTag = TAG_BERRY_PIC_TILE,
    .paletteTag = TAG_BERRY_PIC_PAL,
    .oam = &sBerryPicOamData,
    .anims = sBerryPicSpriteAnimTable,
    .images = sBerryPicSpriteImageTable,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const union AffineAnimCmd sSpriteAffineAnim_BerryPicRotation1[] =
{
    AFFINEANIMCMD_FRAME(-1, -1, 253, 96),
    AFFINEANIMCMD_FRAME(0, 0, 0, 16),
    AFFINEANIMCMD_FRAME(-2, -2, 255, 64),
    AFFINEANIMCMD_FRAME(-8, 0, 0, 16),
    AFFINEANIMCMD_FRAME(0, -8, 0, 16),
    AFFINEANIMCMD_FRAME(256, 256, 0, 0),
    AFFINEANIMCMD_JUMP(0)
};

static const union AffineAnimCmd sSpriteAffineAnim_BerryPicRotation2[] =
{
    AFFINEANIMCMD_FRAME(-1, -1, 3, 96),
    AFFINEANIMCMD_FRAME(0, 0, 0, 16),
    AFFINEANIMCMD_FRAME(-2, -2, 1, 64),
    AFFINEANIMCMD_FRAME(-8, 0, 0, 16),
    AFFINEANIMCMD_FRAME(0, -8, 0, 16),
    AFFINEANIMCMD_FRAME(256, 256, 0, 0),
    AFFINEANIMCMD_JUMP(0)
};

static const union AffineAnimCmd *const sBerryPicRotatingAnimCmds[] =
{
    sSpriteAffineAnim_BerryPicRotation1,
    sSpriteAffineAnim_BerryPicRotation2
};

static const struct SpriteTemplate gBerryPicRotatingSpriteTemplate =
{
    .tileTag = TAG_BERRY_PIC_TILE,
    .paletteTag = TAG_BERRY_PIC_PAL,
    .oam = &sBerryPicRotatingOamData,
    .anims = sBerryPicSpriteAnimTable,
    .images = sBerryPicSpriteImageTable,
    .affineAnims = sBerryPicRotatingAnimCmds,
    .callback = SpriteCallbackDummy,
};

static const struct CompressedTilesPal gBerryPicTable[] =
{
     [ITEM_CHERI_BERRY - FIRST_BERRY_INDEX] = {gBerryPic_Cheri, gBerryPalette_Cheri},
     [ITEM_CHESTO_BERRY - FIRST_BERRY_INDEX] = {gBerryPic_Chesto, gBerryPalette_Chesto},
     [ITEM_PECHA_BERRY - FIRST_BERRY_INDEX] = {gBerryPic_Pecha, gBerryPalette_Pecha},
     [ITEM_RAWST_BERRY - FIRST_BERRY_INDEX] = {gBerryPic_Rawst, gBerryPalette_Rawst},
     [ITEM_ASPEAR_BERRY - FIRST_BERRY_INDEX] = {gBerryPic_Aspear, gBerryPalette_Aspear},
     [ITEM_LEPPA_BERRY - FIRST_BERRY_INDEX] = {gBerryPic_Leppa, gBerryPalette_Leppa},
     [ITEM_ORAN_BERRY - FIRST_BERRY_INDEX] = {gBerryPic_Oran, gBerryPalette_Oran},
     [ITEM_PERSIM_BERRY - FIRST_BERRY_INDEX] = {gBerryPic_Persim, gBerryPalette_Persim},
     [ITEM_LUM_BERRY - FIRST_BERRY_INDEX] = {gBerryPic_Lum, gBerryPalette_Lum},
     [ITEM_SITRUS_BERRY - FIRST_BERRY_INDEX] = {gBerryPic_Sitrus, gBerryPalette_Sitrus},
     [ITEM_FIGY_BERRY - FIRST_BERRY_INDEX] = {gBerryPic_Figy, gBerryPalette_Figy},
     [ITEM_WIKI_BERRY - FIRST_BERRY_INDEX] = {gBerryPic_Wiki, gBerryPalette_Wiki},
     [ITEM_MAGO_BERRY - FIRST_BERRY_INDEX] = {gBerryPic_Mago, gBerryPalette_Mago},
     [ITEM_AGUAV_BERRY - FIRST_BERRY_INDEX] = {gBerryPic_Aguav, gBerryPalette_Aguav},
     [ITEM_IAPAPA_BERRY - FIRST_BERRY_INDEX] = {gBerryPic_Iapapa, gBerryPalette_Iapapa},
     [ITEM_RAZZ_BERRY - FIRST_BERRY_INDEX] = {gBerryPic_Razz, gBerryPalette_Razz},
     [ITEM_BLUK_BERRY - FIRST_BERRY_INDEX] = {gBerryPic_Bluk, gBerryPalette_Bluk},
     [ITEM_NANAB_BERRY - FIRST_BERRY_INDEX] = {gBerryPic_Nanab, gBerryPalette_Nanab},
     [ITEM_WEPEAR_BERRY - FIRST_BERRY_INDEX] = {gBerryPic_Wepear, gBerryPalette_Wepear},
     [ITEM_PINAP_BERRY - FIRST_BERRY_INDEX] = {gBerryPic_Pinap, gBerryPalette_Pinap},
     [ITEM_POMEG_BERRY - FIRST_BERRY_INDEX] = {gBerryPic_Pomeg, gBerryPalette_Pomeg},
     [ITEM_KELPSY_BERRY - FIRST_BERRY_INDEX] = {gBerryPic_Kelpsy, gBerryPalette_Kelpsy},
     [ITEM_QUALOT_BERRY - FIRST_BERRY_INDEX] = {gBerryPic_Qualot, gBerryPalette_Qualot},
     [ITEM_HONDEW_BERRY - FIRST_BERRY_INDEX] = {gBerryPic_Hondew, gBerryPalette_Hondew},
     [ITEM_GREPA_BERRY - FIRST_BERRY_INDEX] = {gBerryPic_Grepa, gBerryPalette_Grepa},
     [ITEM_TAMATO_BERRY - FIRST_BERRY_INDEX] = {gBerryPic_Tamato, gBerryPalette_Tamato},
     [ITEM_CORNN_BERRY - FIRST_BERRY_INDEX] = {gBerryPic_Cornn, gBerryPalette_Cornn},
     [ITEM_MAGOST_BERRY - FIRST_BERRY_INDEX] = {gBerryPic_Magost, gBerryPalette_Magost},
     [ITEM_RABUTA_BERRY - FIRST_BERRY_INDEX] = {gBerryPic_Rabuta, gBerryPalette_Rabuta},
     [ITEM_NOMEL_BERRY - FIRST_BERRY_INDEX] = {gBerryPic_Nomel, gBerryPalette_Nomel},
     [ITEM_SPELON_BERRY - FIRST_BERRY_INDEX] = {gBerryPic_Spelon, gBerryPalette_Spelon},
     [ITEM_PAMTRE_BERRY - FIRST_BERRY_INDEX] = {gBerryPic_Pamtre, gBerryPalette_Pamtre},
     [ITEM_WATMEL_BERRY - FIRST_BERRY_INDEX] = {gBerryPic_Watmel, gBerryPalette_Watmel},
     [ITEM_DURIN_BERRY - FIRST_BERRY_INDEX] = {gBerryPic_Durin, gBerryPalette_Durin},
     [ITEM_BELUE_BERRY - FIRST_BERRY_INDEX] = {gBerryPic_Belue, gBerryPalette_Belue},
     [ITEM_LIECHI_BERRY - FIRST_BERRY_INDEX] = {gBerryPic_Liechi, gBerryPalette_Liechi},
     [ITEM_GANLON_BERRY - FIRST_BERRY_INDEX] = {gBerryPic_Ganlon, gBerryPalette_Ganlon},
     [ITEM_SALAC_BERRY - FIRST_BERRY_INDEX] = {gBerryPic_Salac, gBerryPalette_Salac},
     [ITEM_PETAYA_BERRY - FIRST_BERRY_INDEX] = {gBerryPic_Petaya, gBerryPalette_Petaya},
     [ITEM_APICOT_BERRY - FIRST_BERRY_INDEX] = {gBerryPic_Apicot, gBerryPalette_Apicot},
     [ITEM_LANSAT_BERRY - FIRST_BERRY_INDEX] = {gBerryPic_Lansat, gBerryPalette_Lansat},
     [ITEM_STARF_BERRY - FIRST_BERRY_INDEX] = {gBerryPic_Starf, gBerryPalette_Starf},
     [ITEM_ENIGMA_BERRY - FIRST_BERRY_INDEX] = {gBerryPic_Enigma, gBerryPalette_Enigma},
     [ITEM_OCCA_BERRY - FIRST_BERRY_INDEX] = {gBerryPic_Occa, gBerryPalette_Occa},
     [ITEM_PASSHO_BERRY - FIRST_BERRY_INDEX] = {gBerryPic_Passho, gBerryPalette_Passho},
     [ITEM_WACAN_BERRY - FIRST_BERRY_INDEX] = {gBerryPic_Wacan, gBerryPalette_Wacan},
     [ITEM_RINDO_BERRY - FIRST_BERRY_INDEX] = {gBerryPic_Rindo, gBerryPalette_Rindo},
     [ITEM_YACHE_BERRY - FIRST_BERRY_INDEX] = {gBerryPic_Yache, gBerryPalette_Yache},
     [ITEM_CHOPLE_BERRY - FIRST_BERRY_INDEX] = {gBerryPic_Chople, gBerryPalette_Chople},
     [ITEM_KEBIA_BERRY - FIRST_BERRY_INDEX] = {gBerryPic_Kebia, gBerryPalette_Kebia},
     [ITEM_SHUCA_BERRY - FIRST_BERRY_INDEX] = {gBerryPic_Shuca, gBerryPalette_Shuca},
     [ITEM_COBA_BERRY - FIRST_BERRY_INDEX] = {gBerryPic_Coba, gBerryPalette_Coba},
     [ITEM_PAYAPA_BERRY - FIRST_BERRY_INDEX] = {gBerryPic_Payapa, gBerryPalette_Payapa},
     [ITEM_TANGA_BERRY - FIRST_BERRY_INDEX] = {gBerryPic_Tanga, gBerryPalette_Tanga},
     [ITEM_CHARTI_BERRY - FIRST_BERRY_INDEX] = {gBerryPic_Charti, gBerryPalette_Charti},
     [ITEM_KASIB_BERRY - FIRST_BERRY_INDEX] = {gBerryPic_Kasib, gBerryPalette_Kasib},
     [ITEM_HABAN_BERRY - FIRST_BERRY_INDEX] = {gBerryPic_Haban, gBerryPalette_Haban},
     [ITEM_COLBUR_BERRY - FIRST_BERRY_INDEX] = {gBerryPic_Colbur, gBerryPalette_Colbur},
     [ITEM_BABIRI_BERRY - FIRST_BERRY_INDEX] = {gBerryPic_Babiri, gBerryPalette_Babiri},
     [ITEM_CHILAN_BERRY - FIRST_BERRY_INDEX] = {gBerryPic_Chilan, gBerryPalette_Chilan},
     [ITEM_ROSELI_BERRY - FIRST_BERRY_INDEX] = {gBerryPic_Roseli, gBerryPalette_Roseli},
     [ITEM_MICLE_BERRY - FIRST_BERRY_INDEX] = {},
     [ITEM_CUSTAP_BERRY - FIRST_BERRY_INDEX] = {},
     [ITEM_JABOCA_BERRY - FIRST_BERRY_INDEX] = {},
     [ITEM_ROWAP_BERRY - FIRST_BERRY_INDEX] = {},
     [ITEM_KEE_BERRY - FIRST_BERRY_INDEX] = {},
     [ITEM_MARANGA_BERRY - FIRST_BERRY_INDEX] = {},
};

const struct CompressedSpriteSheet gBerryCheckCircleSpriteSheet =
{
    gBerryCheckCircle_Gfx, 0x800, TAG_BERRY_CHECK_CIRCLE_GFX
};

const struct CompressedSpritePalette gBerryCheckCirclePaletteTable =
{
    gBerryCheck_Pal, TAG_BERRY_CHECK_CIRCLE_GFX
};

static const struct OamData sBerryCheckCircleOamData =
{
    .y = 0,
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
    .affineParam = 0
};

static const union AnimCmd sSpriteAnim_BerryCheckCircle[] =
{
    ANIMCMD_FRAME(0, 0),
    ANIMCMD_END
};

static const union AnimCmd *const sBerryCheckCircleSpriteAnimTable[] =
{
    sSpriteAnim_BerryCheckCircle
};

static const struct SpriteTemplate gBerryCheckCircleSpriteTemplate =
{
    .tileTag = TAG_BERRY_CHECK_CIRCLE_GFX,
    .paletteTag = TAG_BERRY_CHECK_CIRCLE_GFX,
    .oam = &sBerryCheckCircleOamData,
    .anims = sBerryCheckCircleSpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

// code
void RemoveBagSprite(u8 id)
{
    u8 *spriteId = &gBagMenu->spriteId[id];
    if (*spriteId != 0xFF)
    {
        FreeSpriteTilesByTag(id + 100);
        FreeSpritePaletteByTag(id + 100);
        FreeSpriteOamMatrix(&gSprites[*spriteId]);
        DestroySprite(&gSprites[*spriteId]);
        *spriteId = 0xFF;
    }
}

void AddBagVisualSprite(u8 bagPocketId)
{
    u8 *spriteId = &gBagMenu->spriteId[0];
    *spriteId = CreateSprite(&gBagSpriteTemplate, 68, 66, 0);
    SetBagVisualPocketId(bagPocketId, FALSE);
}

void SetBagVisualPocketId(u8 bagPocketId, bool8 isSwitchingPockets)
{
    struct Sprite *sprite = &gSprites[gBagMenu->spriteId[0]];
    if (isSwitchingPockets)
    {
        sprite->pos2.y = -5;
        sprite->callback = SpriteCB_BagVisualSwitchingPockets;
        sprite->data[0] = bagPocketId + 1;
        StartSpriteAnim(sprite, 0);
    }
    else
    {
        StartSpriteAnim(sprite, bagPocketId + 1);
    }
}

static void SpriteCB_BagVisualSwitchingPockets(struct Sprite *sprite)
{
    if (sprite->pos2.y != 0)
    {
        sprite->pos2.y++;
    }
    else
    {
        StartSpriteAnim(sprite, sprite->data[0]);
        sprite->callback = SpriteCallbackDummy;
    }
}

void ShakeBagVisual(void)
{
    struct Sprite *sprite = &gSprites[gBagMenu->spriteId[0]];
    if (sprite->affineAnimEnded)
    {
        StartSpriteAffineAnim(sprite, 1);
        sprite->callback = SpriteCB_ShakeBagVisual;
    }
}

static void SpriteCB_ShakeBagVisual(struct Sprite *sprite)
{
    if (sprite->affineAnimEnded)
    {
        StartSpriteAffineAnim(sprite, 0);
        sprite->callback = SpriteCallbackDummy;
    }
}

void AddSwitchPocketRotatingBallSprite(s16 rotationDirection)
{
    u8 *spriteId = &gBagMenu->spriteId[1];
    LoadSpriteSheet(&gRotatingBallTable);
    LoadSpritePalette(&gRotatingBallPaletteTable);
    *spriteId = CreateSprite(&gRotatingBallSpriteTemplate, 16, 16, 0);
    gSprites[*spriteId].data[0] = rotationDirection;
}

static void UpdateSwitchPocketRotatingBallCoords(struct Sprite *sprite)
{
    sprite->centerToCornerVecX = sprite->data[1] - ((sprite->data[3] + 1) & 1);
    sprite->centerToCornerVecY = sprite->data[1] - ((sprite->data[3] + 1) & 1);
}

static void SpriteCB_SwitchPocketRotatingBallInit(struct Sprite *sprite)
{
    sprite->oam.affineMode = ST_OAM_AFFINE_NORMAL;
    if (sprite->data[0] == -1)
        sprite->affineAnims = sRotatingBallAnimCmds;
    else
        sprite->affineAnims = sRotatingBallAnimCmds_FullRotation;

    InitSpriteAffineAnim(sprite);
    sprite->data[1] = sprite->centerToCornerVecX;
    sprite->data[1] = sprite->centerToCornerVecY;
    UpdateSwitchPocketRotatingBallCoords(sprite);
    sprite->callback = SpriteCB_SwitchPocketRotatingBallContinue;
}

static void SpriteCB_SwitchPocketRotatingBallContinue(struct Sprite *sprite)
{
    sprite->data[3]++;
    UpdateSwitchPocketRotatingBallCoords(sprite);
    if (sprite->data[3] == 16)
        RemoveBagSprite(1);
}

void AddBagItemIconSprite(u16 itemId, u8 id)
{
    u8 *spriteId = &gBagMenu->spriteId[id + 2];
    if (*spriteId == 0xFF)
    {
        u8 iconSpriteId;

        FreeSpriteTilesByTag(id + 102);
        FreeSpritePaletteByTag(id + 102);
        iconSpriteId = AddItemIconSprite(id + 102, id + 102, itemId);
        if (iconSpriteId != MAX_SPRITES)
        {
            *spriteId = iconSpriteId;
            gSprites[iconSpriteId].pos2.x = 24;
            gSprites[iconSpriteId].pos2.y = 88;
        }
    }
}

void RemoveBagItemIconSprite(u8 id)
{
    RemoveBagSprite(id + 2);
}

void sub_80D4FAC(void)
{
    sub_8122344(&gBagMenu->spriteId[4], 8);
}

void sub_80D4FC8(u8 arg0)
{
    sub_81223FC(&gBagMenu->spriteId[4], 8, arg0);
}

void sub_80D4FEC(u8 arg0)
{
    sub_8122448(&gBagMenu->spriteId[4], 136, 120, (arg0 + 1) * 16);
}

static void sub_80D5018(void *mem0, void *mem1)
{
    u8 i, j;

    memset(mem1, 0, 0x800);
    mem1 += 0x100;
    for (i = 0; i < 6; i++)
    {
        mem1 += 0x20;
        for (j = 0; j < 6; j++)
        {
            memcpy(mem1, mem0, 0x20);
            mem1 += 0x20;
            mem0 += 0x20;
        }
        if (i != 5)
            mem1 += 0x20;
    }
}

static void LoadBerryGfx(u8 berryId)
{
    struct CompressedSpritePalette pal;

    if (berryId == ITEM_TO_BERRY(ITEM_ENIGMA_BERRY) - 1 && IsEnigmaBerryValid())
    {
        // unknown empty if statement
    }

    pal.data = gBerryPicTable[berryId].pal;
    pal.tag = TAG_BERRY_PIC_PAL;
    LoadCompressedSpritePalette(&pal);
    LZDecompressWram(gBerryPicTable[berryId].tiles, &gDecompressionBuffer[0x1000]);
    sub_80D5018(&gDecompressionBuffer[0x1000], &gDecompressionBuffer[0]);
}

u8 CreateBerryTagSprite(u8 id, s16 x, s16 y)
{
    LoadBerryGfx(id);
    return CreateSprite(&gBerryPicSpriteTemplate, x, y, 0);
}

void FreeBerryTagSpritePalette(void)
{
    FreeSpritePaletteByTag(TAG_BERRY_PIC_PAL);
}

u8 LoadSpinningBerryPicGfx(u8 berryId, u8 x, u8 y, bool8 startAffine)
{
    u8 spriteId;

    FreeSpritePaletteByTag(TAG_BERRY_PIC_PAL);
    LoadBerryGfx(berryId);
    spriteId = CreateSprite(&gBerryPicRotatingSpriteTemplate, x, y, 0);
    if (startAffine == TRUE)
        StartSpriteAffineAnim(&gSprites[spriteId], 1);

    return spriteId;
}

u8 CreateBerryFlavorCircleSprite(s16 x)
{
    return CreateSprite(&gBerryCheckCircleSpriteTemplate, x, 116, 0);
}
