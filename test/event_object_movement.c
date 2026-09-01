#include "global.h"
#include "event_object_movement.h"
#include "sprite.h"
#include "test/test.h"

static const u32 sFrame16x32[256 / sizeof(u32)] = {0};
static const u32 sFrame32x32[512 / sizeof(u32)] = {0};

static const struct OamData sOam16x32 = {
    .shape = SPRITE_SHAPE(16x32),
    .size = SPRITE_SIZE(16x32),
};

static const struct OamData sOam32x32 = {
    .shape = SPRITE_SHAPE(32x32),
    .size = SPRITE_SIZE(32x32),
};

static const struct SpriteFrameImage sImages16x32[] = {
    {.data = sFrame16x32, .size = sizeof(sFrame16x32)},
};

static const struct SpriteFrameImage sImages32x32[] = {
    {.data = sFrame32x32, .size = sizeof(sFrame32x32)},
};

static const struct SpriteTemplate sSpriteTemplate16x32 = {
    .tileTag = TAG_NONE,
    .paletteTag = TAG_NONE,
    .oam = &sOam16x32,
    .images = sImages16x32,
    .callback = SpriteCallbackDummy,
};

static const struct ObjectEventGraphicsInfo sGraphicsInfo32x32 = {
    .tileTag = TAG_NONE,
    .size = sizeof(sFrame32x32),
    .oam = &sOam32x32,
    .images = sImages32x32,
};

extern u16 LoadSheetGraphicsInfo(const struct ObjectEventGraphicsInfo *info, u16 uuid, struct Sprite *sprite);

TEST("LoadSheetGraphicsInfo reallocates non-sheet sprites when frame size changes")
{
    u16 i;
    u16 tileNum;
    u16 tileCount;
    u8 spriteId;
    struct Sprite *sprite;

    ASSUME(sOam16x32.size == sOam32x32.size);
    ASSUME(sOam16x32.shape != sOam32x32.shape);

    ResetSpriteData();
    spriteId = CreateSprite(&sSpriteTemplate16x32, 0, 0, 0);
    ASSUME(spriteId != MAX_SPRITES);

    sprite = &gSprites[spriteId];
    tileNum = sprite->oam.tileNum;
    tileCount = sGraphicsInfo32x32.images->size / TILE_SIZE_4BPP;

    EXPECT_EQ(sprite->images->size, sizeof(sFrame16x32));
    EXPECT_EQ(sGraphicsInfo32x32.images->size, sizeof(sFrame32x32));

    LoadSheetGraphicsInfo(&sGraphicsInfo32x32, 0, sprite);

    for (i = 0; i < tileCount; i++)
        EXPECT(SpriteTileAllocBitmapOp(tileNum + i, 2) != 0);

    DestroySprite(sprite);
}
