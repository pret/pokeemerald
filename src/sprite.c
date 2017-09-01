#include "global.h"
#include "sprite.h"

#define OAM_MATRIX_COUNT 32

struct SpriteCopyRequest
{
    const u8 *src;
    u8 *dest;
    u16 size;
};

EWRAM_DATA struct Sprite gSprites[MAX_SPRITES + 1] = {0};
EWRAM_DATA u16 gSpritePriorities[MAX_SPRITES] = {0};
EWRAM_DATA u8 gSpriteOrder[MAX_SPRITES] = {0};
EWRAM_DATA bool8 gShouldProcessSpriteCopyRequests = 0;
EWRAM_DATA u8 gSpriteCopyRequestCount = 0;
EWRAM_DATA struct SpriteCopyRequest gSpriteCopyRequests[MAX_SPRITES] = {0};
EWRAM_DATA u8 gOamLimit = 0;
EWRAM_DATA u16 gReservedSpriteTileCount = 0;
EWRAM_DATA u8 gSpriteTileAllocBitmap[128] = {0};
EWRAM_DATA s16 gSpriteCoordOffsetX = 0;
EWRAM_DATA s16 gSpriteCoordOffsetY = 0;
EWRAM_DATA struct OamMatrix gOamMatrices[OAM_MATRIX_COUNT] = {0};
EWRAM_DATA bool8 gAffineAnimsDisabled = 0;
