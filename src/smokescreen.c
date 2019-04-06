#include "global.h"
#include "data.h"
#include "decompress.h"
#include "sprite.h"
#include "util.h"

static void sub_8075370(struct Sprite *);

extern const struct CompressedSpriteSheet gUnknown_0831C620;
extern const struct CompressedSpritePalette gUnknown_0831C628;
extern const struct SpriteTemplate gUnknown_0831C688;

u8 sub_807521C(s16 x, s16 y, u8 a3)
{
    u8 mainSpriteId;
    u8 spriteId1, spriteId2, spriteId3, spriteId4;
    struct Sprite *mainSprite;

    if (GetSpriteTileStartByTag(gUnknown_0831C620.tag) == 0xFFFF)
    {
        LoadCompressedSpriteSheetUsingHeap(&gUnknown_0831C620);
        LoadCompressedSpritePaletteUsingHeap(&gUnknown_0831C628);
    }

    mainSpriteId = CreateInvisibleSpriteWithCallback(sub_8075370);
    mainSprite = &gSprites[mainSpriteId];
    mainSprite->data[1] = a3;

    spriteId1 = CreateSprite(&gUnknown_0831C688, x - 16, y - 16, 2);
    gSprites[spriteId1].data[0] = mainSpriteId;
    mainSprite->data[0]++;
    AnimateSprite(&gSprites[spriteId1]);

    spriteId2 = CreateSprite(&gUnknown_0831C688, x, y - 16, 2);
    gSprites[spriteId2].data[0] = mainSpriteId;
    mainSprite->data[0]++;
    StartSpriteAnim(&gSprites[spriteId2], 1);
    AnimateSprite(&gSprites[spriteId2]);

    spriteId3 = CreateSprite(&gUnknown_0831C688, x - 16, y, 2);
    gSprites[spriteId3].data[0] = mainSpriteId;
    mainSprite->data[0]++;
    StartSpriteAnim(&gSprites[spriteId3], 2);
    AnimateSprite(&gSprites[spriteId3]);

    spriteId4 = CreateSprite(&gUnknown_0831C688, x, y, 2);
    gSprites[spriteId4].data[0] = mainSpriteId;
    mainSprite->data[0]++;
    StartSpriteAnim(&gSprites[spriteId4], 3);
    AnimateSprite(&gSprites[spriteId4]);

    return mainSpriteId;
}

static void sub_8075370(struct Sprite *sprite)
{
    if (!sprite->data[0])
    {
        FreeSpriteTilesByTag(gUnknown_0831C620.tag);
        FreeSpritePaletteByTag(gUnknown_0831C628.tag);
        if (!sprite->data[1])
            DestroySprite(sprite);
        else
            sprite->callback = SpriteCallbackDummy;
    }
}

void sub_80753B4(struct Sprite *sprite)
{
    if (sprite->animEnded)
    {
        gSprites[sprite->data[0]].data[0]--;
        DestroySprite(sprite);
    }
}
