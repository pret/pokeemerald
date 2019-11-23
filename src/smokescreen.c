#include "global.h"
#include "data.h"
#include "decompress.h"
#include "sprite.h"
#include "util.h"

static void SmokescreenImpact_Callback(struct Sprite *);

extern const struct CompressedSpriteSheet gSmokescreenImpactSpriteSheet;
extern const struct CompressedSpritePalette gSmokescreenlImpactSpritePalette;
extern const struct SpriteTemplate gSmokescreenImpactSpriteTemplate;

u8 SmokescreenImpact(s16 x, s16 y, u8 a3)
{
    u8 mainSpriteId;
    u8 spriteId1, spriteId2, spriteId3, spriteId4;
    struct Sprite *mainSprite;

    if (GetSpriteTileStartByTag(gSmokescreenImpactSpriteSheet.tag) == 0xFFFF)
    {
        LoadCompressedSpriteSheetUsingHeap(&gSmokescreenImpactSpriteSheet);
        LoadCompressedSpritePaletteUsingHeap(&gSmokescreenlImpactSpritePalette);
    }

    mainSpriteId = CreateInvisibleSpriteWithCallback(SmokescreenImpact_Callback);
    mainSprite = &gSprites[mainSpriteId];
    mainSprite->data[1] = a3;

    spriteId1 = CreateSprite(&gSmokescreenImpactSpriteTemplate, x - 16, y - 16, 2);
    gSprites[spriteId1].data[0] = mainSpriteId;
    mainSprite->data[0]++;
    AnimateSprite(&gSprites[spriteId1]);

    spriteId2 = CreateSprite(&gSmokescreenImpactSpriteTemplate, x, y - 16, 2);
    gSprites[spriteId2].data[0] = mainSpriteId;
    mainSprite->data[0]++;
    StartSpriteAnim(&gSprites[spriteId2], 1);
    AnimateSprite(&gSprites[spriteId2]);

    spriteId3 = CreateSprite(&gSmokescreenImpactSpriteTemplate, x - 16, y, 2);
    gSprites[spriteId3].data[0] = mainSpriteId;
    mainSprite->data[0]++;
    StartSpriteAnim(&gSprites[spriteId3], 2);
    AnimateSprite(&gSprites[spriteId3]);

    spriteId4 = CreateSprite(&gSmokescreenImpactSpriteTemplate, x, y, 2);
    gSprites[spriteId4].data[0] = mainSpriteId;
    mainSprite->data[0]++;
    StartSpriteAnim(&gSprites[spriteId4], 3);
    AnimateSprite(&gSprites[spriteId4]);

    return mainSpriteId;
}

static void SmokescreenImpact_Callback(struct Sprite *sprite)
{
    if (!sprite->data[0])
    {
        FreeSpriteTilesByTag(gSmokescreenImpactSpriteSheet.tag);
        FreeSpritePaletteByTag(gSmokescreenlImpactSpritePalette.tag);
        if (!sprite->data[1])
            DestroySprite(sprite);
        else
            sprite->callback = SpriteCallbackDummy;
    }
}

void SpriteCB_DestroySprite(struct Sprite *sprite)
{
    if (sprite->animEnded)
    {
        gSprites[sprite->data[0]].data[0]--;
        DestroySprite(sprite);
    }
}
