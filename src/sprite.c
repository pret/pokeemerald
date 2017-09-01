#include "global.h"
#include "sprite.h"
#include "main.h"

#define OAM_MATRIX_COUNT 32

struct SpriteCopyRequest
{
    const u8 *src;
    u8 *dest;
    u16 size;
};

// this file's functions
void UpdateOamCoords(void);
void BuildSpritePriorities(void);
void SortSprites(void);
void CopyMatricesToOamBuffer(void);
void AddSpritesToOamBuffer(void);
u8 CreateSpriteAt(u8 index, const struct SpriteTemplate *template, s16 x, s16 y, u8 subpriority);
void ClearSpriteCopyRequests(void);
void ResetOamMatrices(void);
void ResetSprite(struct Sprite *sprite);
s16 AllocSpriteTiles(u16 tileCount);
void RequestSpriteFrameImageCopy(u16 index, u16 tileNum, const struct SpriteFrameImage *images);
void ResetAllSprites(void);
void BeginAnim(struct Sprite *sprite);
void ContinueAnim(struct Sprite *sprite);
void AnimCmd_frame(struct Sprite *sprite);
void AnimCmd_end(struct Sprite *sprite);
void AnimCmd_jump(struct Sprite *sprite);
void AnimCmd_loop(struct Sprite *sprite);
void BeginAnimLoop(struct Sprite *sprite);
void ContinueAnimLoop(struct Sprite *sprite);
void JumpToTopOfAnimLoop(struct Sprite *sprite);
void BeginAffineAnim(struct Sprite *sprite);
void ContinueAffineAnim(struct Sprite *sprite);
void AffineAnimDelay(u8 matrixNum, struct Sprite *sprite);
void AffineAnimCmd_loop(u8 matrixNum, struct Sprite *sprite);
void BeginAffineAnimLoop(u8 matrixNum, struct Sprite *sprite);
void ContinueAffineAnimLoop(u8 matrixNum, struct Sprite *sprite);
void JumpToTopOfAffineAnimLoop(u8 matrixNum, struct Sprite *sprite);
void AffineAnimCmd_jump(u8 matrixNum, struct Sprite *sprite);
void AffineAnimCmd_end(u8 matrixNum, struct Sprite *sprite);
void AffineAnimCmd_frame(u8 matrixNum, struct Sprite *sprite);
void CopyOamMatrix(u8 destMatrixIndex, struct OamMatrix *srcMatrix);
u8 GetSpriteMatrixNum(struct Sprite *sprite);
void SetSpriteOamFlipBits(struct Sprite *sprite, u8 hFlip, u8 vFlip);
void AffineAnimStateRestartAnim(u8 matrixNum);
void AffineAnimStateStartAnim(u8 matrixNum, u8 animNum);
void AffineAnimStateReset(u8 matrixNum);
void ApplyAffineAnimFrameAbsolute(u8 matrixNum, struct AffineAnimFrameCmd *frameCmd);
void DecrementAnimDelayCounter(struct Sprite *sprite);
bool8 DecrementAffineAnimDelayCounter(struct Sprite *sprite, u8 matrixNum);
void ApplyAffineAnimFrameRelativeAndUpdateMatrix(u8 matrixNum, struct AffineAnimFrameCmd *frameCmd);
s16 ConvertScaleParam(s16 scale);
void GetAffineAnimFrame(u8 matrixNum, struct Sprite *sprite, struct AffineAnimFrameCmd *frameCmd);
void ApplyAffineAnimFrame(u8 matrixNum, struct AffineAnimFrameCmd *frameCmd);
void ResetAffineAnimData(void);
u8 IndexOfSpriteTileTag(u16 tag);
void AllocSpriteTileRange(u16 tag, u16 start, u16 count);
void DoLoadSpritePalette(const u16 *src, u16 paletteOffset);

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

void ResetSpriteData(void)
{
    ResetOamRange(0, 128);
    ResetAllSprites();
    ClearSpriteCopyRequests();
    ResetAffineAnimData();
    FreeSpriteTileRanges();
    gOamLimit = 64;
    gReservedSpriteTileCount = 0;
    AllocSpriteTiles(0);
    gSpriteCoordOffsetX = 0;
    gSpriteCoordOffsetY = 0;
}

void AnimateSprites(void)
{
    u8 i;
    for (i = 0; i < MAX_SPRITES; i++)
    {
        struct Sprite *sprite = &gSprites[i];

        if (sprite->inUse)
        {
            sprite->callback(sprite);

            if (sprite->inUse)
                AnimateSprite(sprite);
        }
    }
}

void BuildOamBuffer(void)
{
    u8 temp;
    UpdateOamCoords();
    BuildSpritePriorities();
    SortSprites();
    temp = gMain.oamLoadDisabled;
    gMain.oamLoadDisabled = TRUE;
    AddSpritesToOamBuffer();
    CopyMatricesToOamBuffer();
    gMain.oamLoadDisabled = temp;
    gShouldProcessSpriteCopyRequests = TRUE;
}

void UpdateOamCoords(void)
{
    u8 i;
    for (i = 0; i < MAX_SPRITES; i++)
    {
        struct Sprite *sprite = &gSprites[i];
        if (sprite->inUse && !sprite->invisible)
        {
            if (sprite->coordOffsetEnabled)
            {
                sprite->oam.x = sprite->pos1.x + sprite->pos2.x + sprite->centerToCornerVecX + gSpriteCoordOffsetX;
                sprite->oam.y = sprite->pos1.y + sprite->pos2.y + sprite->centerToCornerVecY + gSpriteCoordOffsetY;
            }
            else
            {
                sprite->oam.x = sprite->pos1.x + sprite->pos2.x + sprite->centerToCornerVecX;
                sprite->oam.y = sprite->pos1.y + sprite->pos2.y + sprite->centerToCornerVecY;
            }
        }
    }
}

void BuildSpritePriorities(void)
{
    u16 i;
    for (i = 0; i < MAX_SPRITES; i++)
    {
        struct Sprite *sprite = &gSprites[i];
        u16 priority = sprite->subpriority | (sprite->oam.priority << 8);
        gSpritePriorities[i] = priority;
    }
}

void SortSprites(void)
{
    u8 i;
    for (i = 1; i < MAX_SPRITES; i++)
    {
        u8 j = i;
        struct Sprite *sprite1 = &gSprites[gSpriteOrder[i - 1]];
        struct Sprite *sprite2 = &gSprites[gSpriteOrder[i]];
        u16 sprite1Priority = gSpritePriorities[gSpriteOrder[i - 1]];
        u16 sprite2Priority = gSpritePriorities[gSpriteOrder[i]];
        s16 sprite1Y = sprite1->oam.y;
        s16 sprite2Y = sprite2->oam.y;

        if (sprite1Y >= DISPLAY_HEIGHT)
            sprite1Y = sprite1Y - 256;

        if (sprite2Y >= DISPLAY_HEIGHT)
            sprite2Y = sprite2Y - 256;

        if (sprite1->oam.affineMode == ST_OAM_AFFINE_DOUBLE
         && sprite1->oam.size == 3)
        {
            u32 shape = sprite1->oam.shape;
            if (shape == ST_OAM_SQUARE || shape == 2)
            {
                if (sprite1Y > 128)
                    sprite1Y = sprite1Y - 256;
            }
        }

        if (sprite2->oam.affineMode == ST_OAM_AFFINE_DOUBLE
         && sprite2->oam.size == 3)
        {
            u32 shape = sprite2->oam.shape;
            if (shape == ST_OAM_SQUARE || shape == ST_OAM_V_RECTANGLE)
            {
                if (sprite2Y > 128)
                    sprite2Y = sprite2Y - 256;
            }
        }

        while (j > 0
            && ((sprite1Priority > sprite2Priority)
             || (sprite1Priority == sprite2Priority && sprite1Y < sprite2Y)))
        {
            u8 temp = gSpriteOrder[j];
            gSpriteOrder[j] = gSpriteOrder[j - 1];
            gSpriteOrder[j - 1] = temp;

            // UB: If j equals 1, then j-- makes j equal 0.
            // Then, gSpriteOrder[-1] gets accessed below.
            // Although this doesn't result in a bug in the ROM,
            // the behavior is undefined.
            j--;

            sprite1 = &gSprites[gSpriteOrder[j - 1]];
            sprite2 = &gSprites[gSpriteOrder[j]];
            sprite1Priority = gSpritePriorities[gSpriteOrder[j - 1]];
            sprite2Priority = gSpritePriorities[gSpriteOrder[j]];
            sprite1Y = sprite1->oam.y;
            sprite2Y = sprite2->oam.y;

            if (sprite1Y >= DISPLAY_HEIGHT)
                sprite1Y = sprite1Y - 256;

            if (sprite2Y >= DISPLAY_HEIGHT)
                sprite2Y = sprite2Y - 256;

            if (sprite1->oam.affineMode == ST_OAM_AFFINE_DOUBLE
             && sprite1->oam.size == 3)
            {
                u32 shape = sprite1->oam.shape;
                if (shape == ST_OAM_SQUARE || shape == ST_OAM_V_RECTANGLE)
                {
                    if (sprite1Y > 128)
                        sprite1Y = sprite1Y - 256;
                }
            }

            if (sprite2->oam.affineMode == ST_OAM_AFFINE_DOUBLE
             && sprite2->oam.size == 3)
            {
                u32 shape = sprite2->oam.shape;
                if (shape == ST_OAM_SQUARE || shape == ST_OAM_V_RECTANGLE)
                {
                    if (sprite2Y > 128)
                        sprite2Y = sprite2Y - 256;
                }
            }
        }
    }
}

void CopyMatricesToOamBuffer(void)
{
    u8 i;
    for (i = 0; i < OAM_MATRIX_COUNT; i++)
    {
        u32 base = 4 * i;
        gMain.oamBuffer[base + 0].affineParam = gOamMatrices[i].a;
        gMain.oamBuffer[base + 1].affineParam = gOamMatrices[i].b;
        gMain.oamBuffer[base + 2].affineParam = gOamMatrices[i].c;
        gMain.oamBuffer[base + 3].affineParam = gOamMatrices[i].d;
    }
}

