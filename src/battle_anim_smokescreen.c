#include "global.h"
#include "battle_gfx_sfx_util.h"
#include "data.h"
#include "decompress.h"
#include "graphics.h"
#include "sprite.h"
#include "util.h"
#include "constants/battle_palace.h"

#define TAG_SMOKESCREEN 55019

#define PALTAG_SHADOW 55039
#define GFXTAG_SHADOW 55129

static void SpriteCB_SmokescreenImpactMain(struct Sprite *);
static void SpriteCB_SmokescreenImpact(struct Sprite *);

// The below data for smokescreen starts and ends with some data that belongs to battle_gfx_sfx_util.c

const u8 gBattlePalaceNatureToMoveTarget[NUM_NATURES] =
{
    [NATURE_HARDY]   = PALACE_TARGET_STRONGER,
    [NATURE_LONELY]  = PALACE_TARGET_STRONGER,
    [NATURE_BRAVE]   = PALACE_TARGET_WEAKER,
    [NATURE_ADAMANT] = PALACE_TARGET_STRONGER,
    [NATURE_NAUGHTY] = PALACE_TARGET_WEAKER,
    [NATURE_BOLD]    = PALACE_TARGET_WEAKER,
    [NATURE_DOCILE]  = PALACE_TARGET_RANDOM,
    [NATURE_RELAXED] = PALACE_TARGET_STRONGER,
    [NATURE_IMPISH]  = PALACE_TARGET_STRONGER,
    [NATURE_LAX]     = PALACE_TARGET_STRONGER,
    [NATURE_TIMID]   = PALACE_TARGET_WEAKER,
    [NATURE_HASTY]   = PALACE_TARGET_WEAKER,
    [NATURE_SERIOUS] = PALACE_TARGET_WEAKER,
    [NATURE_JOLLY]   = PALACE_TARGET_STRONGER,
    [NATURE_NAIVE]   = PALACE_TARGET_RANDOM,
    [NATURE_MODEST]  = PALACE_TARGET_WEAKER,
    [NATURE_MILD]    = PALACE_TARGET_STRONGER,
    [NATURE_QUIET]   = PALACE_TARGET_WEAKER,
    [NATURE_BASHFUL] = PALACE_TARGET_WEAKER,
    [NATURE_RASH]    = PALACE_TARGET_STRONGER,
    [NATURE_CALM]    = PALACE_TARGET_STRONGER,
    [NATURE_GENTLE]  = PALACE_TARGET_STRONGER,
    [NATURE_SASSY]   = PALACE_TARGET_WEAKER,
    [NATURE_CAREFUL] = PALACE_TARGET_WEAKER,
    [NATURE_QUIRKY]  = PALACE_TARGET_STRONGER,
};

static const struct CompressedSpriteSheet sSmokescreenImpactSpriteSheet =
{
    .data = gSmokescreenImpactTiles, .size = 0x180, .tag = TAG_SMOKESCREEN
};

static const struct CompressedSpritePalette sSmokescreenImpactSpritePalette =
{
    .data = gSmokescreenImpactPalette, .tag = TAG_SMOKESCREEN
};

static const struct OamData sOamData_SmokescreenImpact =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(16x16),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(16x16),
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0
};

static const union AnimCmd sAnim_SmokescreenImpact_0[] =
{
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(4, 4),
    ANIMCMD_FRAME(8, 4),
    ANIMCMD_END
};

static const union AnimCmd sAnim_SmokescreenImpact_1[] =
{
    ANIMCMD_FRAME(0, 4, .hFlip = TRUE),
    ANIMCMD_FRAME(4, 4, .hFlip = TRUE),
    ANIMCMD_FRAME(8, 4, .hFlip = TRUE),
    ANIMCMD_END
};

static const union AnimCmd sAnim_SmokescreenImpact_2[] =
{
    ANIMCMD_FRAME(0, 4, .vFlip = TRUE),
    ANIMCMD_FRAME(4, 4, .vFlip = TRUE),
    ANIMCMD_FRAME(8, 4, .vFlip = TRUE),
    ANIMCMD_END
};

static const union AnimCmd sAnim_SmokescreenImpact_3[] =
{
    ANIMCMD_FRAME(0, 4, .hFlip = TRUE, .vFlip = TRUE),
    ANIMCMD_FRAME(4, 4, .hFlip = TRUE, .vFlip = TRUE),
    ANIMCMD_FRAME(8, 4, .hFlip = TRUE, .vFlip = TRUE),
    ANIMCMD_END
};

static const union AnimCmd *const sAnims_SmokescreenImpact[] =
{
    sAnim_SmokescreenImpact_0,
    sAnim_SmokescreenImpact_1,
    sAnim_SmokescreenImpact_2,
    sAnim_SmokescreenImpact_3,
};

static const struct SpriteTemplate sSmokescreenImpactSpriteTemplate =
{
    .tileTag = TAG_SMOKESCREEN,
    .paletteTag = TAG_SMOKESCREEN,
    .oam = &sOamData_SmokescreenImpact,
    .anims = sAnims_SmokescreenImpact,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_SmokescreenImpact
};

const struct CompressedSpriteSheet gSpriteSheet_EnemyShadow =
{
    .data = gEnemyMonShadow_Gfx, .size = 0x80, .tag = GFXTAG_SHADOW
};

static const struct OamData sOamData_EnemyShadow =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x8),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(32x8),
    .tileNum = 0,
    .priority = 3,
    .paletteNum = 0,
    .affineParam = 0
};

const struct SpriteTemplate gSpriteTemplate_EnemyShadow =
{
    .tileTag = GFXTAG_SHADOW,
    .paletteTag = PALTAG_SHADOW,
    .oam = &sOamData_EnemyShadow,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_SetInvisible
};

#define sActiveSprites data[0]
#define sPersist       data[1]

#define sMainSpriteId data[0]

u8 SmokescreenImpact(s16 x, s16 y, bool8 persist)
{
    u8 mainSpriteId;
    u8 spriteId1, spriteId2, spriteId3, spriteId4;
    struct Sprite *mainSprite;

    if (GetSpriteTileStartByTag(sSmokescreenImpactSpriteSheet.tag) == 0xFFFF)
    {
        LoadCompressedSpriteSheetUsingHeap(&sSmokescreenImpactSpriteSheet);
        LoadCompressedSpritePaletteUsingHeap(&sSmokescreenImpactSpritePalette);
    }

    mainSpriteId = CreateInvisibleSpriteWithCallback(SpriteCB_SmokescreenImpactMain);
    mainSprite = &gSprites[mainSpriteId];
    mainSprite->sPersist = persist;

    // Top left sprite
    spriteId1 = CreateSprite(&sSmokescreenImpactSpriteTemplate, x - 16, y - 16, 2);
    gSprites[spriteId1].sMainSpriteId = mainSpriteId;
    mainSprite->sActiveSprites++;
    AnimateSprite(&gSprites[spriteId1]);

    // Top right sprite
    spriteId2 = CreateSprite(&sSmokescreenImpactSpriteTemplate, x, y - 16, 2);
    gSprites[spriteId2].sMainSpriteId = mainSpriteId;
    mainSprite->sActiveSprites++;
    StartSpriteAnim(&gSprites[spriteId2], 1);
    AnimateSprite(&gSprites[spriteId2]);

    // Bottom left sprite
    spriteId3 = CreateSprite(&sSmokescreenImpactSpriteTemplate, x - 16, y, 2);
    gSprites[spriteId3].sMainSpriteId = mainSpriteId;
    mainSprite->sActiveSprites++;
    StartSpriteAnim(&gSprites[spriteId3], 2);
    AnimateSprite(&gSprites[spriteId3]);

    // Bottom right sprite
    spriteId4 = CreateSprite(&sSmokescreenImpactSpriteTemplate, x, y, 2);
    gSprites[spriteId4].sMainSpriteId = mainSpriteId;
    mainSprite->sActiveSprites++;
    StartSpriteAnim(&gSprites[spriteId4], 3);
    AnimateSprite(&gSprites[spriteId4]);

    return mainSpriteId;
}

static void SpriteCB_SmokescreenImpactMain(struct Sprite *sprite)
{
    if (sprite->sActiveSprites == 0)
    {
        FreeSpriteTilesByTag(sSmokescreenImpactSpriteSheet.tag);
        FreeSpritePaletteByTag(sSmokescreenImpactSpritePalette.tag);
        if (!sprite->sPersist)
            DestroySprite(sprite);
        else
            sprite->callback = SpriteCallbackDummy;
    }
}

static void SpriteCB_SmokescreenImpact(struct Sprite *sprite)
{
    if (sprite->animEnded)
    {
        gSprites[sprite->sMainSpriteId].sActiveSprites--;
        DestroySprite(sprite);
    }
}
