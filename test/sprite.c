#include "global.h"
#include "main.h"
#include "malloc.h"
#include "random.h"
#include "sprite.h"
#include "test/test.h"

#define OAM_MATRIX_COUNT 32

EWRAM_DATA static u16 sSpritePriorities[MAX_SPRITES] = {0};
EWRAM_DATA static u8 sSpriteOrder[MAX_SPRITES] = {0};

static void Old_BuildOamBuffer(void);

static void ExpectEqOamBuffers(const struct OamData *oldOamBuffer, const struct OamData *newOamBuffer)
{
    u32 i;
    u32 matrices = 0;

    // Compare the non-matrix data.
    for (i = 0; i < gOamLimit; i++)
    {
        EXPECT(memcmp(&oldOamBuffer[i], &newOamBuffer[i], 6) == 0);
        if (newOamBuffer[i].affineMode & ST_OAM_AFFINE_ON_MASK)
            matrices |= 1 << newOamBuffer[i].matrixNum;
    }

    // Compare the matrix data.
    for (i = 0; i < OAM_MATRIX_COUNT; i++)
    {
        if (matrices & (1 << i))
        {
            u32 base = 4 * i;
            EXPECT_EQ(oldOamBuffer[base + 0].affineParam, newOamBuffer[base + 0].affineParam);
            EXPECT_EQ(oldOamBuffer[base + 1].affineParam, newOamBuffer[base + 1].affineParam);
            EXPECT_EQ(oldOamBuffer[base + 2].affineParam, newOamBuffer[base + 2].affineParam);
            EXPECT_EQ(oldOamBuffer[base + 3].affineParam, newOamBuffer[base + 3].affineParam);
        }
    }
}

static void ResetSpriteData_(void)
{
    u32 i;
    ResetSpriteData();
    for (i = 0; i < MAX_SPRITES; i++)
        sSpriteOrder[i] = i;
}

static void BenchmarkBuildOamBuffer(bool32 preSort)
{
    struct Benchmark oldBuildOamBuffer, newBuildOamBuffer;
    struct OamData *oldOamBuffer = Alloc(sizeof(gMain.oamBuffer));

    if (preSort)
        Old_BuildOamBuffer();
    BENCHMARK(&oldBuildOamBuffer)
    {
        Old_BuildOamBuffer();
    }
    memcpy(oldOamBuffer, gMain.oamBuffer, sizeof(gMain.oamBuffer));

    if (preSort)
        BuildOamBuffer();
    BENCHMARK(&newBuildOamBuffer)
    {
        BuildOamBuffer();
    }

    ExpectEqOamBuffers(oldOamBuffer, gMain.oamBuffer);
    EXPECT_FASTER(newBuildOamBuffer, oldBuildOamBuffer);
    Free(oldOamBuffer);
}

TEST("BuildOamBuffer faster with no sprites")
{
    ResetSpriteData_();
    BenchmarkBuildOamBuffer(FALSE);
}

TEST("BuildOamBuffer faster with max sprites (equal y/subpriority)")
{
    u32 i;

    ResetSpriteData_();
    for (i = 0; i < MAX_SPRITES; i++)
        CreateSprite(&gDummySpriteTemplate, 0, 0, 0);
    BenchmarkBuildOamBuffer(FALSE);
}

TEST("BuildOamBuffer faster with max sprites (random y/subpriority)")
{
    u32 i;
    ResetSpriteData_();
    SeedRng(0);
    for (i = 0; i < MAX_SPRITES; i++)
        CreateSprite(&gDummySpriteTemplate, 0, Random() % 256, Random() % 256);
    BenchmarkBuildOamBuffer(FALSE);
}

TEST("BuildOamBuffer faster on already-sorted max sprites")
{
    u32 i;
    ResetSpriteData_();
    SeedRng(0);
    for (i = 0; i < MAX_SPRITES; i++)
        CreateSprite(&gDummySpriteTemplate, 0, Random() % 256, Random() % 256);
    BenchmarkBuildOamBuffer(TRUE);
}

TEST("BuildOamBuffer faster with mix of sprites")
{
    u32 i;
    ResetSpriteData_();
    SeedRng(0);
    for (i = 0; i < MAX_SPRITES / 2; i++)
    {
        u32 spriteId = CreateSprite(&gDummySpriteTemplate, 0, Random() % 256, Random() % 256);
        gSprites[spriteId].invisible = Random() % 4 == 0;
    }
    BenchmarkBuildOamBuffer(FALSE);
}

// Old implementation.

#define UBFIX

static void UpdateOamCoords(void)
{
    u8 i;
    for (i = 0; i < MAX_SPRITES; i++)
    {
        struct Sprite *sprite = &gSprites[i];
        if (sprite->inUse && !sprite->invisible)
        {
            if (sprite->coordOffsetEnabled)
            {
                sprite->oam.x = sprite->x + sprite->x2 + sprite->centerToCornerVecX + gSpriteCoordOffsetX;
                sprite->oam.y = sprite->y + sprite->y2 + sprite->centerToCornerVecY + gSpriteCoordOffsetY;
            }
            else
            {
                sprite->oam.x = sprite->x + sprite->x2 + sprite->centerToCornerVecX;
                sprite->oam.y = sprite->y + sprite->y2 + sprite->centerToCornerVecY;
            }
        }
    }
}

static void BuildSpritePriorities(void)
{
    u16 i;
    for (i = 0; i < MAX_SPRITES; i++)
    {
        struct Sprite *sprite = &gSprites[i];
        u16 priority = sprite->subpriority | (sprite->oam.priority << 8);
        sSpritePriorities[i] = priority;
    }
}

static void SortSprites(void)
{
    u8 i;
    for (i = 1; i < MAX_SPRITES; i++)
    {
        u8 j = i;
        struct Sprite *sprite1 = &gSprites[sSpriteOrder[i - 1]];
        struct Sprite *sprite2 = &gSprites[sSpriteOrder[i]];
        u16 sprite1Priority = sSpritePriorities[sSpriteOrder[i - 1]];
        u16 sprite2Priority = sSpritePriorities[sSpriteOrder[i]];
        s16 sprite1Y = sprite1->oam.y;
        s16 sprite2Y = sprite2->oam.y;

        if (sprite1Y >= DISPLAY_HEIGHT)
            sprite1Y = sprite1Y - 256;

        if (sprite2Y >= DISPLAY_HEIGHT)
            sprite2Y = sprite2Y - 256;

        if (sprite1->oam.affineMode == ST_OAM_AFFINE_DOUBLE
         && sprite1->oam.size == ST_OAM_SIZE_3)
        {
            u32 shape = sprite1->oam.shape;
            if (shape == ST_OAM_SQUARE || shape == ST_OAM_V_RECTANGLE)
            {
                if (sprite1Y > 128)
                    sprite1Y = sprite1Y - 256;
            }
        }

        if (sprite2->oam.affineMode == ST_OAM_AFFINE_DOUBLE
         && sprite2->oam.size == ST_OAM_SIZE_3)
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
            u8 temp = sSpriteOrder[j];
            sSpriteOrder[j] = sSpriteOrder[j - 1];
            sSpriteOrder[j - 1] = temp;

            // UB: If j equals 1, then j-- makes j equal 0.
            // Then, sSpriteOrder[-1] gets accessed below.
            // Although this doesn't result in a bug in the ROM,
            // the behavior is undefined.
            j--;
#ifdef UBFIX
            if (j == 0)
                break;
#endif

            sprite1 = &gSprites[sSpriteOrder[j - 1]];
            sprite2 = &gSprites[sSpriteOrder[j]];
            sprite1Priority = sSpritePriorities[sSpriteOrder[j - 1]];
            sprite2Priority = sSpritePriorities[sSpriteOrder[j]];
            sprite1Y = sprite1->oam.y;
            sprite2Y = sprite2->oam.y;

            if (sprite1Y >= DISPLAY_HEIGHT)
                sprite1Y = sprite1Y - 256;

            if (sprite2Y >= DISPLAY_HEIGHT)
                sprite2Y = sprite2Y - 256;

            if (sprite1->oam.affineMode == ST_OAM_AFFINE_DOUBLE
             && sprite1->oam.size == ST_OAM_SIZE_3)
            {
                u32 shape = sprite1->oam.shape;
                if (shape == ST_OAM_SQUARE || shape == ST_OAM_V_RECTANGLE)
                {
                    if (sprite1Y > 128)
                        sprite1Y = sprite1Y - 256;
                }
            }

            if (sprite2->oam.affineMode == ST_OAM_AFFINE_DOUBLE
             && sprite2->oam.size == ST_OAM_SIZE_3)
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

static void CopyMatricesToOamBuffer(void)
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

static void AddSpritesToOamBuffer(void)
{
    u8 i = 0;
    u8 oamIndex = 0;

    while (i < MAX_SPRITES)
    {
        struct Sprite *sprite = &gSprites[sSpriteOrder[i]];
        if (sprite->inUse && !sprite->invisible && AddSpriteToOamBuffer(sprite, &oamIndex))
            return;
        i++;
    }

    while (oamIndex < gOamLimit)
    {
        gMain.oamBuffer[oamIndex] = gDummyOamData;
        oamIndex++;
    }
}

static void Old_BuildOamBuffer(void)
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
    //sShouldProcessSpriteCopyRequests = TRUE;
}
