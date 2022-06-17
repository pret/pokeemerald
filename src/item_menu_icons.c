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

enum {
    TAG_BAG_GFX = 100,
    TAG_ROTATING_BALL_GFX,
    TAG_ITEM_ICON,
    TAG_ITEM_ICON_ALT,
};
#define TAG_BERRY_CHECK_CIRCLE_GFX 10000
#define TAG_BERRY_PIC_PAL 30020

struct CompressedTilesPal
{
    const u32 *tiles;
    const u32 *pal;
};

// this file's functions
static void SpriteCB_BagVisualSwitchingPockets(struct Sprite *sprite);
static void SpriteCB_ShakeBagSprite(struct Sprite *sprite);
static void SpriteCB_SwitchPocketRotatingBallInit(struct Sprite *sprite);
static void SpriteCB_SwitchPocketRotatingBallContinue(struct Sprite *sprite);

// static const rom data
static const u16 sRotatingBall_Pal[] = INCBIN_U16("graphics/bag/rotating_ball.gbapal");
static const u8 sRotatingBall_Gfx[] = INCBIN_U8("graphics/bag/rotating_ball.4bpp");
static const u8 sCherryUnused[] = INCBIN_U8("graphics/unused/cherry.4bpp");
static const u16 sCherryUnused_Pal[] = INCBIN_U16("graphics/unused/cherry.gbapal");

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

static const struct SpriteTemplate sBagSpriteTemplate =
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

static const struct SpriteSheet sRotatingBallTable =
{
    sRotatingBall_Gfx, 0x80, TAG_ROTATING_BALL_GFX
};

static const struct SpritePalette sRotatingBallPaletteTable =
{
    sRotatingBall_Pal, TAG_ROTATING_BALL_GFX
};

static const struct SpriteTemplate sRotatingBallSpriteTemplate =
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

static const union AnimCmd sAnim_BerryPic[] =
{
    ANIMCMD_FRAME(0, 0),
    ANIMCMD_END
};

static const union AnimCmd *const sBerryPicSpriteAnimTable[] =
{
    sAnim_BerryPic
};

static const struct SpriteFrameImage sBerryPicSpriteImageTable[] =
{
    {&gDecompressionBuffer[0], 0x800},
};

static const struct SpriteTemplate sBerryPicSpriteTemplate =
{
    .tileTag = TAG_NONE,
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

static const struct SpriteTemplate sBerryPicRotatingSpriteTemplate =
{
    .tileTag = TAG_NONE,
    .paletteTag = TAG_BERRY_PIC_PAL,
    .oam = &sBerryPicRotatingOamData,
    .anims = sBerryPicSpriteAnimTable,
    .images = sBerryPicSpriteImageTable,
    .affineAnims = sBerryPicRotatingAnimCmds,
    .callback = SpriteCallbackDummy,
};

static const struct CompressedTilesPal sBerryPicTable[] =
{
    [ITEM_TO_BERRY(ITEM_CHERI_BERRY)  - 1] = {gBerryPic_Cheri,  gBerryPalette_Cheri},
    [ITEM_TO_BERRY(ITEM_CHESTO_BERRY) - 1] = {gBerryPic_Chesto, gBerryPalette_Chesto},
    [ITEM_TO_BERRY(ITEM_PECHA_BERRY)  - 1] = {gBerryPic_Pecha,  gBerryPalette_Pecha},
    [ITEM_TO_BERRY(ITEM_RAWST_BERRY)  - 1] = {gBerryPic_Rawst,  gBerryPalette_Rawst},
    [ITEM_TO_BERRY(ITEM_ASPEAR_BERRY) - 1] = {gBerryPic_Aspear, gBerryPalette_Aspear},
    [ITEM_TO_BERRY(ITEM_LEPPA_BERRY)  - 1] = {gBerryPic_Leppa,  gBerryPalette_Leppa},
    [ITEM_TO_BERRY(ITEM_ORAN_BERRY)   - 1] = {gBerryPic_Oran,   gBerryPalette_Oran},
    [ITEM_TO_BERRY(ITEM_PERSIM_BERRY) - 1] = {gBerryPic_Persim, gBerryPalette_Persim},
    [ITEM_TO_BERRY(ITEM_LUM_BERRY)    - 1] = {gBerryPic_Lum,    gBerryPalette_Lum},
    [ITEM_TO_BERRY(ITEM_SITRUS_BERRY) - 1] = {gBerryPic_Sitrus, gBerryPalette_Sitrus},
    [ITEM_TO_BERRY(ITEM_FIGY_BERRY)   - 1] = {gBerryPic_Figy,   gBerryPalette_Figy},
    [ITEM_TO_BERRY(ITEM_WIKI_BERRY)   - 1] = {gBerryPic_Wiki,   gBerryPalette_Wiki},
    [ITEM_TO_BERRY(ITEM_MAGO_BERRY)   - 1] = {gBerryPic_Mago,   gBerryPalette_Mago},
    [ITEM_TO_BERRY(ITEM_AGUAV_BERRY)  - 1] = {gBerryPic_Aguav,  gBerryPalette_Aguav},
    [ITEM_TO_BERRY(ITEM_IAPAPA_BERRY) - 1] = {gBerryPic_Iapapa, gBerryPalette_Iapapa},
    [ITEM_TO_BERRY(ITEM_RAZZ_BERRY)   - 1] = {gBerryPic_Razz,   gBerryPalette_Razz},
    [ITEM_TO_BERRY(ITEM_BLUK_BERRY)   - 1] = {gBerryPic_Bluk,   gBerryPalette_Bluk},
    [ITEM_TO_BERRY(ITEM_NANAB_BERRY)  - 1] = {gBerryPic_Nanab,  gBerryPalette_Nanab},
    [ITEM_TO_BERRY(ITEM_WEPEAR_BERRY) - 1] = {gBerryPic_Wepear, gBerryPalette_Wepear},
    [ITEM_TO_BERRY(ITEM_PINAP_BERRY)  - 1] = {gBerryPic_Pinap,  gBerryPalette_Pinap},
    [ITEM_TO_BERRY(ITEM_POMEG_BERRY)  - 1] = {gBerryPic_Pomeg,  gBerryPalette_Pomeg},
    [ITEM_TO_BERRY(ITEM_KELPSY_BERRY) - 1] = {gBerryPic_Kelpsy, gBerryPalette_Kelpsy},
    [ITEM_TO_BERRY(ITEM_QUALOT_BERRY) - 1] = {gBerryPic_Qualot, gBerryPalette_Qualot},
    [ITEM_TO_BERRY(ITEM_HONDEW_BERRY) - 1] = {gBerryPic_Hondew, gBerryPalette_Hondew},
    [ITEM_TO_BERRY(ITEM_GREPA_BERRY)  - 1] = {gBerryPic_Grepa,  gBerryPalette_Grepa},
    [ITEM_TO_BERRY(ITEM_TAMATO_BERRY) - 1] = {gBerryPic_Tamato, gBerryPalette_Tamato},
    [ITEM_TO_BERRY(ITEM_CORNN_BERRY)  - 1] = {gBerryPic_Cornn,  gBerryPalette_Cornn},
    [ITEM_TO_BERRY(ITEM_MAGOST_BERRY) - 1] = {gBerryPic_Magost, gBerryPalette_Magost},
    [ITEM_TO_BERRY(ITEM_RABUTA_BERRY) - 1] = {gBerryPic_Rabuta, gBerryPalette_Rabuta},
    [ITEM_TO_BERRY(ITEM_NOMEL_BERRY)  - 1] = {gBerryPic_Nomel,  gBerryPalette_Nomel},
    [ITEM_TO_BERRY(ITEM_SPELON_BERRY) - 1] = {gBerryPic_Spelon, gBerryPalette_Spelon},
    [ITEM_TO_BERRY(ITEM_PAMTRE_BERRY) - 1] = {gBerryPic_Pamtre, gBerryPalette_Pamtre},
    [ITEM_TO_BERRY(ITEM_WATMEL_BERRY) - 1] = {gBerryPic_Watmel, gBerryPalette_Watmel},
    [ITEM_TO_BERRY(ITEM_DURIN_BERRY)  - 1] = {gBerryPic_Durin,  gBerryPalette_Durin},
    [ITEM_TO_BERRY(ITEM_BELUE_BERRY)  - 1] = {gBerryPic_Belue,  gBerryPalette_Belue},
    [ITEM_TO_BERRY(ITEM_LIECHI_BERRY) - 1] = {gBerryPic_Liechi, gBerryPalette_Liechi},
    [ITEM_TO_BERRY(ITEM_GANLON_BERRY) - 1] = {gBerryPic_Ganlon, gBerryPalette_Ganlon},
    [ITEM_TO_BERRY(ITEM_SALAC_BERRY)  - 1] = {gBerryPic_Salac,  gBerryPalette_Salac},
    [ITEM_TO_BERRY(ITEM_PETAYA_BERRY) - 1] = {gBerryPic_Petaya, gBerryPalette_Petaya},
    [ITEM_TO_BERRY(ITEM_APICOT_BERRY) - 1] = {gBerryPic_Apicot, gBerryPalette_Apicot},
    [ITEM_TO_BERRY(ITEM_LANSAT_BERRY) - 1] = {gBerryPic_Lansat, gBerryPalette_Lansat},
    [ITEM_TO_BERRY(ITEM_STARF_BERRY)  - 1] = {gBerryPic_Starf,  gBerryPalette_Starf},
    [ITEM_TO_BERRY(ITEM_ENIGMA_BERRY) - 1] = {gBerryPic_Enigma, gBerryPalette_Enigma},
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

static const struct SpriteTemplate sBerryCheckCircleSpriteTemplate =
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
    u8 *spriteId = &gBagMenu->spriteIds[id];
    if (*spriteId != SPRITE_NONE)
    {
        FreeSpriteTilesByTag(id + TAG_BAG_GFX);
        FreeSpritePaletteByTag(id + TAG_BAG_GFX);
        FreeSpriteOamMatrix(&gSprites[*spriteId]);
        DestroySprite(&gSprites[*spriteId]);
        *spriteId = SPRITE_NONE;
    }
}

void AddBagVisualSprite(u8 bagPocketId)
{
    u8 *spriteId = &gBagMenu->spriteIds[ITEMMENUSPRITE_BAG];
    *spriteId = CreateSprite(&sBagSpriteTemplate, 68, 66, 0);
    SetBagVisualPocketId(bagPocketId, FALSE);
}

void SetBagVisualPocketId(u8 bagPocketId, bool8 isSwitchingPockets)
{
    struct Sprite *sprite = &gSprites[gBagMenu->spriteIds[ITEMMENUSPRITE_BAG]];
    if (isSwitchingPockets)
    {
        sprite->y2 = -5;
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
    if (sprite->y2 != 0)
    {
        sprite->y2++;
    }
    else
    {
        StartSpriteAnim(sprite, sprite->data[0]);
        sprite->callback = SpriteCallbackDummy;
    }
}

void ShakeBagSprite(void)
{
    struct Sprite *sprite = &gSprites[gBagMenu->spriteIds[ITEMMENUSPRITE_BAG]];
    if (sprite->affineAnimEnded)
    {
        StartSpriteAffineAnim(sprite, 1);
        sprite->callback = SpriteCB_ShakeBagSprite;
    }
}

static void SpriteCB_ShakeBagSprite(struct Sprite *sprite)
{
    if (sprite->affineAnimEnded)
    {
        StartSpriteAffineAnim(sprite, 0);
        sprite->callback = SpriteCallbackDummy;
    }
}

void AddSwitchPocketRotatingBallSprite(s16 rotationDirection)
{
    u8 *spriteId = &gBagMenu->spriteIds[ITEMMENUSPRITE_BALL];
    LoadSpriteSheet(&sRotatingBallTable);
    LoadSpritePalette(&sRotatingBallPaletteTable);
    *spriteId = CreateSprite(&sRotatingBallSpriteTemplate, 16, 16, 0);
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
        RemoveBagSprite(ITEMMENUSPRITE_BALL);
}

void AddBagItemIconSprite(u16 itemId, u8 id)
{
    u8 *spriteId = &gBagMenu->spriteIds[id + ITEMMENUSPRITE_ITEM];
    if (*spriteId == SPRITE_NONE)
    {
        u8 iconSpriteId;

        // Either TAG_ITEM_ICON or TAG_ITEM_ICON_ALT
        FreeSpriteTilesByTag(id + TAG_ITEM_ICON);
        FreeSpritePaletteByTag(id + TAG_ITEM_ICON);
        iconSpriteId = AddItemIconSprite(id + TAG_ITEM_ICON, id + TAG_ITEM_ICON, itemId);
        if (iconSpriteId != MAX_SPRITES)
        {
            *spriteId = iconSpriteId;
            gSprites[iconSpriteId].x2 = 24;
            gSprites[iconSpriteId].y2 = 88;
        }
    }
}

void RemoveBagItemIconSprite(u8 id)
{
// BUG: For one frame, the item you scroll to in the Bag menu
// will have an incorrect palette and may be seen as a flicker.
#ifdef BUGFIX
    u8 *spriteId = &gBagMenu->spriteIds[ITEMMENUSPRITE_ITEM];

    if (spriteId[id ^ 1] != SPRITE_NONE)
        gSprites[spriteId[id ^ 1]].invisible = TRUE;

    if (spriteId[id] != SPRITE_NONE)
    {
        DestroySpriteAndFreeResources(&gSprites[spriteId[id]]);
        spriteId[id] = SPRITE_NONE;
    }
#else
    RemoveBagSprite(id + ITEMMENUSPRITE_ITEM);
#endif
}

void CreateItemMenuSwapLine(void)
{
    CreateSwapLineSprites(&gBagMenu->spriteIds[ITEMMENUSPRITE_SWAP_LINE], ITEMMENU_SWAP_LINE_LENGTH);
}

void SetItemMenuSwapLineInvisibility(bool8 invisible)
{
    SetSwapLineSpritesInvisibility(&gBagMenu->spriteIds[ITEMMENUSPRITE_SWAP_LINE], ITEMMENU_SWAP_LINE_LENGTH, invisible);
}

void UpdateItemMenuSwapLinePos(u8 y)
{
    UpdateSwapLineSpritesPos(&gBagMenu->spriteIds[ITEMMENUSPRITE_SWAP_LINE], ITEMMENU_SWAP_LINE_LENGTH | SWAP_LINE_HAS_MARGIN, 120, (y + 1) * 16);
}

static void ArrangeBerryGfx(void *src, void *dest)
{
    u8 i, j;

    memset(dest, 0, 0x800);

    // Create top margin
    dest += 0x100;

    for (i = 0; i < 6; i++)
    {
        // Create left margin
        dest += 0x20;

        // Copy one row of berry's icon
        for (j = 0; j < 6; j++)
        {
            memcpy(dest, src, 0x20);
            dest += 0x20;
            src += 0x20;
        }

        // Create right margin
        if (i != 5)
            dest += 0x20;
    }
}

static void LoadBerryGfx(u8 berryId)
{
    struct CompressedSpritePalette pal;

    if (berryId == ITEM_TO_BERRY(ITEM_ENIGMA_BERRY) - 1 && IsEnigmaBerryValid())
    {
        // unknown empty if statement
    }

    pal.data = sBerryPicTable[berryId].pal;
    pal.tag = TAG_BERRY_PIC_PAL;
    LoadCompressedSpritePalette(&pal);
    LZDecompressWram(sBerryPicTable[berryId].tiles, &gDecompressionBuffer[0x1000]);
    ArrangeBerryGfx(&gDecompressionBuffer[0x1000], &gDecompressionBuffer[0]);
}

u8 CreateBerryTagSprite(u8 id, s16 x, s16 y)
{
    LoadBerryGfx(id);
    return CreateSprite(&sBerryPicSpriteTemplate, x, y, 0);
}

void FreeBerryTagSpritePalette(void)
{
    FreeSpritePaletteByTag(TAG_BERRY_PIC_PAL);
}

// For throwing berries into the Berry Blender
u8 CreateSpinningBerrySprite(u8 berryId, u8 x, u8 y, bool8 startAffine)
{
    u8 spriteId;

    FreeSpritePaletteByTag(TAG_BERRY_PIC_PAL);
    LoadBerryGfx(berryId);
    spriteId = CreateSprite(&sBerryPicRotatingSpriteTemplate, x, y, 0);
    if (startAffine == TRUE)
        StartSpriteAffineAnim(&gSprites[spriteId], 1);

    return spriteId;
}

u8 CreateBerryFlavorCircleSprite(s16 x)
{
    return CreateSprite(&sBerryCheckCircleSpriteTemplate, x, 116, 0);
}
