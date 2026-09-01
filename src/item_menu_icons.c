#include "global.h"
#include "berry.h"
#include "decompress.h"
#include "graphics.h"
#include "item.h"
#include "item_menu.h"
#include "item_icon.h"
#include "item_menu_icons.h"
#include "malloc.h"
#include "menu_helpers.h"
#include "menu.h"
#include "sprite.h"
#include "window.h"
#include "util.h"
#include "constants/items.h"

enum {
    TAG_BAG_GFX = 100,
    TAG_ROTATING_BALL_GFX,
    TAG_ITEM_ICON,
    TAG_ITEM_ICON_ALT,
};
#define TAG_BERRY_CHECK_CIRCLE_GFX 10000
#define TAG_BERRY_PIC_PAL 30020

// this file's functions
static void SpriteCB_BagVisualSwitchingPockets(struct Sprite *sprite);
static void SpriteCB_ShakeBagSprite(struct Sprite *sprite);
static void SpriteCB_SwitchPocketRotatingBallInit(struct Sprite *sprite);
static void SpriteCB_SwitchPocketRotatingBallContinue(struct Sprite *sprite);

// static const rom data
static const u16 sRotatingBall_Pal[] = INCGFX_U16("graphics/bag/rotating_ball.png", ".gbapal");
static const u8 sRotatingBall_Gfx[] = INCGFX_U8("graphics/bag/rotating_ball.png", ".4bpp");
static const u8 sCherryUnused[] = INCGFX_U8("graphics/unused/cherry.png", ".4bpp");
static const u16 sCherryUnused_Pal[] = INCGFX_U16("graphics/unused/cherry.png", ".gbapal");

static const struct OamData sBagOamData =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_NORMAL,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
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
    [POCKET_ITEMS]      = sSpriteAnim_Bag_Items,
    [POCKET_POKE_BALLS] = sSpriteAnim_Bag_Pokeballs,
    [POCKET_TM_HM]      = sSpriteAnim_Bag_TMsHMs,
    [POCKET_BERRIES]    = sSpriteAnim_Bag_Berries,
    [POCKET_KEY_ITEMS]  = sSpriteAnim_Bag_KeyItems,
    [POCKET_DUMMY]       = sSpriteAnim_Bag_Closed,
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

enum {
    ANIM_BAG_NORMAL,
    ANIM_BAG_SHAKE,
};

static const union AffineAnimCmd *const sBagAffineAnimCmds[] =
{
    [ANIM_BAG_NORMAL] = sSpriteAffineAnim_BagNormal,
    [ANIM_BAG_SHAKE]  = sSpriteAffineAnim_BagShake
};

const struct CompressedSpriteSheet gBagMaleSpriteSheet =
{
    gBagMaleTiles, 0x3000, TAG_BAG_GFX
};

const struct CompressedSpriteSheet gBagFemaleSpriteSheet =
{
    gBagFemaleTiles, 0x3000, TAG_BAG_GFX
};

const struct SpritePalette gBagPaletteTable =
{
    gBagPalette, TAG_BAG_GFX
};

static const struct SpriteTemplate sBagSpriteTemplate =
{
    .tileTag = TAG_BAG_GFX,
    .paletteTag = TAG_BAG_GFX,
    .oam = &sBagOamData,
    .anims = sBagSpriteAnimTable,
    .affineAnims = sBagAffineAnimCmds,
};

static const struct OamData sRotatingBallOamData =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
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
    sRotatingBall_Gfx, sizeof(sRotatingBall_Gfx), TAG_ROTATING_BALL_GFX
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
    .affineAnims = sRotatingBallAnimCmds,
    .callback = SpriteCB_SwitchPocketRotatingBallInit,
};

static const struct OamData sBerryPicOamData =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
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
    .mosaic = FALSE,
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

static const struct SpriteTemplate sBerryPicSpriteTemplate =
{
    .tileTag = TAG_NONE,
    .paletteTag = TAG_BERRY_PIC_PAL,
    .oam = &sBerryPicOamData,
    .anims = sBerryPicSpriteAnimTable,
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
    .affineAnims = sBerryPicRotatingAnimCmds,
};

const struct CompressedSpriteSheet gBerryCheckCircleSpriteSheet =
{
    gBerryCheckCircle_Gfx, 0x800, TAG_BERRY_CHECK_CIRCLE_GFX
};

const struct SpritePalette gBerryCheckCirclePaletteTable =
{
    gBerryCheck_Pal, TAG_BERRY_CHECK_CIRCLE_GFX
};

static const struct OamData sBerryCheckCircleOamData =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
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

#define sPocketId data[0]

void SetBagVisualPocketId(u8 bagPocketId, bool8 isSwitchingPockets)
{
    struct Sprite *sprite = &gSprites[gBagMenu->spriteIds[ITEMMENUSPRITE_BAG]];
    if (isSwitchingPockets)
    {
        sprite->y2 = -5;
        sprite->callback = SpriteCB_BagVisualSwitchingPockets;
        sprite->sPocketId = bagPocketId;
        StartSpriteAnim(sprite, POCKET_DUMMY);
    }
    else
    {
        StartSpriteAnim(sprite, bagPocketId);
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
        StartSpriteAnim(sprite, sprite->sPocketId);
        sprite->callback = SpriteCallbackDummy;
    }
}

#undef sPocketId

void ShakeBagSprite(void)
{
    struct Sprite *sprite = &gSprites[gBagMenu->spriteIds[ITEMMENUSPRITE_BAG]];
    if (sprite->affineAnimEnded)
    {
        StartSpriteAffineAnim(sprite, ANIM_BAG_SHAKE);
        sprite->callback = SpriteCB_ShakeBagSprite;
    }
}

static void SpriteCB_ShakeBagSprite(struct Sprite *sprite)
{
    // Wait for shaking to end
    if (sprite->affineAnimEnded)
    {
        StartSpriteAffineAnim(sprite, ANIM_BAG_NORMAL);
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

void AddBagItemIconSprite(enum Item itemId, u8 id)
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

#define BERRY_SPRITE_SIZE ((64*64)/2) // 0x800

struct BerryDynamicGfx
{
    ALIGNED(4) u8 gfx[BERRY_SPRITE_SIZE];
    struct SpriteFrameImage images[1];
};

static struct BerryDynamicGfx *LoadBerryGfx(u8 berryId)
{
    struct SpritePalette pal;

    pal.data = gBerries[berryId].berryPal;
    pal.tag = TAG_BERRY_PIC_PAL + berryId;
    LoadSpritePalette(&pal);
    struct BerryDynamicGfx *gfxAlloced = Alloc(sizeof(struct BerryDynamicGfx));
    void *buffer = malloc_and_decompress(gBerries[berryId].berryPic, NULL);
    ArrangeBerryGfx(buffer, gfxAlloced->gfx);
    Free(buffer);

    return gfxAlloced;
}

static u32 CreateBerrySprite(const struct SpriteTemplate *sprTemplate, u32 berryId, s32 x, s32 y)
{
    u32 spriteId;
    struct BerryDynamicGfx *dynamicGfx = LoadBerryGfx(berryId);
    struct SpriteTemplate newSprTemplate = *sprTemplate;

    newSprTemplate.paletteTag += berryId;
    newSprTemplate.images = dynamicGfx->images;

    dynamicGfx->images[0].data = dynamicGfx->gfx;
    dynamicGfx->images[0].size = BERRY_SPRITE_SIZE;
    dynamicGfx->images[0].relativeFrames = FALSE;

    spriteId = CreateSprite(&newSprTemplate, x, y, 0);
    StoreWordInTwoHalfwords((u16 *) &gSprites[spriteId].data[BERRY_ICON_GFX_PTR_DATA_ID], (u32) dynamicGfx);
    return spriteId;
}

u32 CreateBerryTagSprite(u32 id, s32 x, s32 y)
{
    return CreateBerrySprite(&sBerryPicSpriteTemplate, id, x, y);
}

// For throwing berries into the Berry Blender
u32 CreateSpinningBerrySprite(u32 berryId, s32 x, s32 y, bool32 startAffine)
{
    u32 spriteId = CreateBerrySprite(&sBerryPicRotatingSpriteTemplate, berryId, x, y);
    if (startAffine)
        StartSpriteAffineAnim(&gSprites[spriteId], 1);

    return spriteId;
}

void DestroyBerryIconSprite(u32 spriteId, u32 berryId, bool32 freePal)
{
    DestroyBerryIconSpritePtr(&gSprites[spriteId], berryId, freePal);
}

void DestroyBerryIconSpritePtr(struct Sprite *sprite, u32 berryId, bool32 freePal)
{
    u32 gfxBuffer;

    LoadWordFromTwoHalfwords((u16 *) &sprite->data[BERRY_ICON_GFX_PTR_DATA_ID], &gfxBuffer);
    Free((void *)gfxBuffer);
    DestroySprite(sprite);
    if (freePal)
        FreeBerryIconSpritePalette(berryId);
}

void FreeBerryIconSpritePalette(u32 berryId)
{
    FreeSpritePaletteByTag(TAG_BERRY_PIC_PAL + berryId);
}

u8 CreateBerryFlavorCircleSprite(s16 x)
{
    return CreateSprite(&sBerryCheckCircleSpriteTemplate, x, 116, 0);
}
