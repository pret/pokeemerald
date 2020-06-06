#include "global.h"
#include "sprite.h"
#include "main.h"
#include "palette.h"

#define MAX_SPRITE_COPY_REQUESTS 64

#define OAM_MATRIX_COUNT 32

#define SET_SPRITE_TILE_RANGE(index, start, count) \
{                                                  \
    sSpriteTileRanges[index * 2] = start;          \
    (sSpriteTileRanges + 1)[index * 2] = count;    \
}

#define ALLOC_SPRITE_TILE(n)                             \
{                                                        \
    sSpriteTileAllocBitmap[(n) / 8] |= (1 << ((n) % 8)); \
}

#define FREE_SPRITE_TILE(n)                               \
{                                                         \
    sSpriteTileAllocBitmap[(n) / 8] &= ~(1 << ((n) % 8)); \
}

#define SPRITE_TILE_IS_ALLOCATED(n) ((sSpriteTileAllocBitmap[(n) / 8] >> ((n) % 8)) & 1)


struct SpriteCopyRequest
{
    const u8 *src;
    u8 *dest;
    u16 size;
};

struct OamDimensions
{
    s8 width;
    s8 height;
};

static void UpdateOamCoords(void);
static void BuildSpritePriorities(void);
static void SortSprites(void);
static void CopyMatricesToOamBuffer(void);
static void AddSpritesToOamBuffer(void);
static u8 CreateSpriteAt(u8 index, const struct SpriteTemplate *template, s16 x, s16 y, u8 subpriority);
static void ResetOamMatrices(void);
static void ResetSprite(struct Sprite *sprite);
static s16 AllocSpriteTiles(u16 tileCount);
static void RequestSpriteFrameImageCopy(u16 index, u16 tileNum, const struct SpriteFrameImage *images);
static void ResetAllSprites(void);
static void BeginAnim(struct Sprite *sprite);
static void ContinueAnim(struct Sprite *sprite);
static void AnimCmd_frame(struct Sprite *sprite);
static void AnimCmd_end(struct Sprite *sprite);
static void AnimCmd_jump(struct Sprite *sprite);
static void AnimCmd_loop(struct Sprite *sprite);
static void BeginAnimLoop(struct Sprite *sprite);
static void ContinueAnimLoop(struct Sprite *sprite);
static void JumpToTopOfAnimLoop(struct Sprite *sprite);
static void BeginAffineAnim(struct Sprite *sprite);
static void ContinueAffineAnim(struct Sprite *sprite);
static void AffineAnimDelay(u8 matrixNum, struct Sprite *sprite);
static void AffineAnimCmd_loop(u8 matrixNum, struct Sprite *sprite);
static void BeginAffineAnimLoop(u8 matrixNum, struct Sprite *sprite);
static void ContinueAffineAnimLoop(u8 matrixNum, struct Sprite *sprite);
static void JumpToTopOfAffineAnimLoop(u8 matrixNum, struct Sprite *sprite);
static void AffineAnimCmd_jump(u8 matrixNum, struct Sprite *sprite);
static void AffineAnimCmd_end(u8 matrixNum, struct Sprite *sprite);
static void AffineAnimCmd_frame(u8 matrixNum, struct Sprite *sprite);
static void CopyOamMatrix(u8 destMatrixIndex, struct OamMatrix *srcMatrix);
static u8 GetSpriteMatrixNum(struct Sprite *sprite);
static void SetSpriteOamFlipBits(struct Sprite *sprite, u8 hFlip, u8 vFlip);
static void AffineAnimStateRestartAnim(u8 matrixNum);
static void AffineAnimStateStartAnim(u8 matrixNum, u8 animNum);
static void AffineAnimStateReset(u8 matrixNum);
static void ApplyAffineAnimFrameAbsolute(u8 matrixNum, struct AffineAnimFrameCmd *frameCmd);
static void DecrementAnimDelayCounter(struct Sprite *sprite);
static bool8 DecrementAffineAnimDelayCounter(struct Sprite *sprite, u8 matrixNum);
static void ApplyAffineAnimFrameRelativeAndUpdateMatrix(u8 matrixNum, struct AffineAnimFrameCmd *frameCmd);
static s16 ConvertScaleParam(s16 scale);
static void GetAffineAnimFrame(u8 matrixNum, struct Sprite *sprite, struct AffineAnimFrameCmd *frameCmd);
static void ApplyAffineAnimFrame(u8 matrixNum, struct AffineAnimFrameCmd *frameCmd);
static u8 IndexOfSpriteTileTag(u16 tag);
static void AllocSpriteTileRange(u16 tag, u16 start, u16 count);
static void DoLoadSpritePalette(const u16 *src, u16 paletteOffset);
static void obj_update_pos2(struct Sprite* sprite, s32 a1, s32 a2);

typedef void (*AnimFunc)(struct Sprite *);
typedef void (*AnimCmdFunc)(struct Sprite *);
typedef void (*AffineAnimCmdFunc)(u8 matrixNum, struct Sprite *);

#define DUMMY_OAM_DATA                      \
{                                           \
    .y = 160,                               \
    .affineMode = 0,                        \
    .objMode = 0,                           \
    .mosaic = 0,                            \
    .bpp = 0,                               \
    .shape = SPRITE_SHAPE(8x8),             \
    .x = 304,                               \
    .matrixNum = 0,                         \
    .size = SPRITE_SIZE(8x8),               \
    .tileNum = 0,                           \
    .priority = 3, /* lowest priority */    \
    .paletteNum = 0,                        \
    .affineParam = 0                        \
}

#define ANIM_END        0xFFFF
#define AFFINE_ANIM_END 0x7FFF

// forward declarations
const union AnimCmd * const gDummySpriteAnimTable[];
const union AffineAnimCmd * const gDummySpriteAffineAnimTable[];
const struct SpriteTemplate gDummySpriteTemplate;

// Unreferenced data. Also unreferenced in R/S.
static const u8 sUnknownData[24] =
{
    0x01, 0x04, 0x10, 0x40,
    0x02, 0x04, 0x08, 0x20,
    0x02, 0x04, 0x08, 0x20,
    0x01, 0x04, 0x10, 0x40,
    0x02, 0x04, 0x08, 0x20,
    0x02, 0x04, 0x08, 0x20,
};

static const u8 sCenterToCornerVecTable[3][4][2] =
{
    {   // square
        {  -4,  -4 },
        {  -8,  -8 },
        { -16, -16 },
        { -32, -32 },
    },
    {   // horizontal rectangle
        {  -8,  -4 },
        { -16,  -4 },
        { -16,  -8 },
        { -32, -16 },
    },
    {   // vertical rectangle
        {  -4,  -8 },
        {  -4, -16 },
        {  -8, -16 },
        { -16, -32 },
    },
};

static const struct Sprite sDummySprite =
{
    .oam = DUMMY_OAM_DATA,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .template = &gDummySpriteTemplate,
    .subspriteTables = NULL,
    .callback = SpriteCallbackDummy,
    .pos1 = { 304, 160 },
    .pos2 = {   0,   0 },
    .centerToCornerVecX = 0,
    .centerToCornerVecY = 0,
    .animNum = 0,
    .animCmdIndex = 0,
    .animDelayCounter = 0,
    .animPaused = 0,
    .affineAnimPaused = 0,
    .animLoopCounter = 0,
    .data = {0, 0, 0, 0, 0, 0, 0},
    .inUse = 0,
    .coordOffsetEnabled = 0,
    .invisible = FALSE,
    .flags_3 = 0,
    .flags_4 = 0,
    .flags_5 = 0,
    .flags_6 = 0,
    .flags_7 = 0,
    .hFlip = 0,
    .vFlip = 0,
    .animBeginning = 0,
    .affineAnimBeginning = 0,
    .animEnded = 0,
    .affineAnimEnded = 0,
    .usingSheet = 0,
    .flags_f = 0,
    .sheetTileStart = 0,
    .subspriteTableNum = 0,
    .subspriteMode = 0,
    .subpriority = 0xFF
};

const struct OamData gDummyOamData = DUMMY_OAM_DATA;

static const union AnimCmd sDummyAnim = { ANIM_END };

const union AnimCmd * const gDummySpriteAnimTable[] = { &sDummyAnim };

static const union AffineAnimCmd sDummyAffineAnim = { AFFINE_ANIM_END };

const union AffineAnimCmd * const gDummySpriteAffineAnimTable[] = { &sDummyAffineAnim };

const struct SpriteTemplate gDummySpriteTemplate =
{
    .tileTag = 0,
    .paletteTag = 0xFFFF,
    .oam = &gDummyOamData,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const AnimFunc sAnimFuncs[] =
{
    ContinueAnim,
    BeginAnim,
};

static const AnimFunc sAffineAnimFuncs[] =
{
    ContinueAffineAnim,
    BeginAffineAnim,
};

static const AnimCmdFunc sAnimCmdFuncs[] =
{
    AnimCmd_loop,
    AnimCmd_jump,
    AnimCmd_end,
    AnimCmd_frame,
};

static const AffineAnimCmdFunc sAffineAnimCmdFuncs[] =
{
    AffineAnimCmd_loop,
    AffineAnimCmd_jump,
    AffineAnimCmd_end,
    AffineAnimCmd_frame,
};

static const s32 sUnknown_082EC6F4[3][4][2] =
{
    {
        {8, 8},
        {0x10, 0x10},
        {0x20, 0x20},
        {0x40, 0x40},
    },
    {
        {0x10, 8},
        {0x20, 8},
        {0x20, 0x10},
        {0x40, 0x20},
    },
    {
        {8, 0x10},
        {8, 0x20},
        {0x10, 0x20},
        {0x20, 0x40},
    },
};

static const struct OamDimensions sOamDimensions[3][4] =
{
    [ST_OAM_SQUARE] = 
    {
        [SPRITE_SIZE(8x8)]   = {  8,  8 },
        [SPRITE_SIZE(16x16)] = { 16, 16 },
        [SPRITE_SIZE(32x32)] = { 32, 32 },
        [SPRITE_SIZE(64x64)] = { 64, 64 },
    },
    [ST_OAM_H_RECTANGLE] =
    {
        [SPRITE_SIZE(16x8)]  = { 16,  8 },
        [SPRITE_SIZE(32x8)]  = { 32,  8 },
        [SPRITE_SIZE(32x16)] = { 32, 16 },
        [SPRITE_SIZE(64x32)] = { 64, 32 },
    },
    [ST_OAM_V_RECTANGLE] = 
    {
        [SPRITE_SIZE(8x16)]  = {  8, 16 },
        [SPRITE_SIZE(8x32)]  = {  8, 32 },
        [SPRITE_SIZE(16x32)] = { 16, 32 },
        [SPRITE_SIZE(32x64)] = { 32, 64 },
    },
};

// iwram bss
static u16 sSpriteTileRangeTags[MAX_SPRITES];
static u16 sSpriteTileRanges[MAX_SPRITES * 2];
static struct AffineAnimState sAffineAnimStates[OAM_MATRIX_COUNT];
static u16 sSpritePaletteTags[16];

// iwram common
u32 gOamMatrixAllocBitmap;
u8 gReservedSpritePaletteCount;

EWRAM_DATA struct Sprite gSprites[MAX_SPRITES + 1] = {0};
EWRAM_DATA static u16 sSpritePriorities[MAX_SPRITES] = {0};
EWRAM_DATA static u8 sSpriteOrder[MAX_SPRITES] = {0};
EWRAM_DATA static bool8 sShouldProcessSpriteCopyRequests = 0;
EWRAM_DATA static u8 sSpriteCopyRequestCount = 0;
EWRAM_DATA static struct SpriteCopyRequest sSpriteCopyRequests[MAX_SPRITES] = {0};
EWRAM_DATA u8 gOamLimit = 0;
EWRAM_DATA u16 gReservedSpriteTileCount = 0;
EWRAM_DATA static u8 sSpriteTileAllocBitmap[128] = {0};
EWRAM_DATA s16 gSpriteCoordOffsetX = 0;
EWRAM_DATA s16 gSpriteCoordOffsetY = 0;
EWRAM_DATA struct OamMatrix gOamMatrices[OAM_MATRIX_COUNT] = {0};
EWRAM_DATA bool8 gAffineAnimsDisabled = FALSE;

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
    sShouldProcessSpriteCopyRequests = TRUE;
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
        sSpritePriorities[i] = priority;
    }
}

void SortSprites(void)
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

void AddSpritesToOamBuffer(void)
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

u8 CreateSprite(const struct SpriteTemplate *template, s16 x, s16 y, u8 subpriority)
{
    u8 i;

    for (i = 0; i < MAX_SPRITES; i++)
        if (!gSprites[i].inUse)
            return CreateSpriteAt(i, template, x, y, subpriority);

    return MAX_SPRITES;
}

u8 CreateSpriteAtEnd(const struct SpriteTemplate *template, s16 x, s16 y, u8 subpriority)
{
    s16 i;

    for (i = MAX_SPRITES - 1; i > -1; i--)
        if (!gSprites[i].inUse)
            return CreateSpriteAt(i, template, x, y, subpriority);

    return MAX_SPRITES;
}

u8 CreateInvisibleSprite(void (*callback)(struct Sprite *))
{
    u8 index = CreateSprite(&gDummySpriteTemplate, 0, 0, 31);

    if (index == MAX_SPRITES)
    {
        return MAX_SPRITES;
    }
    else
    {
        gSprites[index].invisible = TRUE;
        gSprites[index].callback = callback;
        return index;
    }
}

u8 CreateSpriteAt(u8 index, const struct SpriteTemplate *template, s16 x, s16 y, u8 subpriority)
{
    struct Sprite *sprite = &gSprites[index];

    ResetSprite(sprite);

    sprite->inUse = TRUE;
    sprite->animBeginning = TRUE;
    sprite->affineAnimBeginning = TRUE;
    sprite->usingSheet = TRUE;

    sprite->subpriority = subpriority;
    sprite->oam = *template->oam;
    sprite->anims = template->anims;
    sprite->affineAnims = template->affineAnims;
    sprite->template = template;
    sprite->callback = template->callback;
    sprite->pos1.x = x;
    sprite->pos1.y = y;

    CalcCenterToCornerVec(sprite, sprite->oam.shape, sprite->oam.size, sprite->oam.affineMode);

    if (template->tileTag == 0xFFFF)
    {
        s16 tileNum;
        sprite->images = template->images;
        tileNum = AllocSpriteTiles((u8)(sprite->images->size / TILE_SIZE_4BPP));
        if (tileNum == -1)
        {
            ResetSprite(sprite);
            return MAX_SPRITES;
        }
        sprite->oam.tileNum = tileNum;
        sprite->usingSheet = FALSE;
        sprite->sheetTileStart = 0;
    }
    else
    {
        sprite->sheetTileStart = GetSpriteTileStartByTag(template->tileTag);
        SetSpriteSheetFrameTileNum(sprite);
    }

    if (sprite->oam.affineMode & ST_OAM_AFFINE_ON_MASK)
        InitSpriteAffineAnim(sprite);

    if (template->paletteTag != 0xFFFF)
        sprite->oam.paletteNum = IndexOfSpritePaletteTag(template->paletteTag);

    return index;
}

u8 CreateSpriteAndAnimate(const struct SpriteTemplate *template, s16 x, s16 y, u8 subpriority)
{
    u8 i;

    for (i = 0; i < MAX_SPRITES; i++)
    {
        struct Sprite *sprite = &gSprites[i];

        if (!gSprites[i].inUse)
        {
            u8 index = CreateSpriteAt(i, template, x, y, subpriority);

            if (index == MAX_SPRITES)
                return MAX_SPRITES;

            gSprites[i].callback(sprite);

            if (gSprites[i].inUse)
                AnimateSprite(sprite);

            return index;
        }
    }

    return MAX_SPRITES;
}

void DestroySprite(struct Sprite *sprite)
{
    if (sprite->inUse)
    {
        if (!sprite->usingSheet)
        {
            u16 i;
            u16 tileEnd = (sprite->images->size / TILE_SIZE_4BPP) + sprite->oam.tileNum;
            for (i = sprite->oam.tileNum; i < tileEnd; i++)
                FREE_SPRITE_TILE(i);
        }
        ResetSprite(sprite);
    }
}

void ResetOamRange(u8 a, u8 b)
{
    u8 i;

    for (i = a; i < b; i++)
    {
        struct OamData *oamBuffer = gMain.oamBuffer;
        oamBuffer[i] = *(struct OamData *)&gDummyOamData;
    }
}

void LoadOam(void)
{
    if (!gMain.oamLoadDisabled)
        CpuCopy32(gMain.oamBuffer, (void *)OAM, sizeof(gMain.oamBuffer));
}

void ClearSpriteCopyRequests(void)
{
    u8 i;

    sShouldProcessSpriteCopyRequests = FALSE;
    sSpriteCopyRequestCount = 0;

    for (i = 0; i < MAX_SPRITE_COPY_REQUESTS; i++)
    {
        sSpriteCopyRequests[i].src = 0;
        sSpriteCopyRequests[i].dest = 0;
        sSpriteCopyRequests[i].size = 0;
    }
}

void ResetOamMatrices(void)
{
    u8 i;
    for (i = 0; i < OAM_MATRIX_COUNT; i++)
    {
        // set to identity matrix
        gOamMatrices[i].a = 0x0100;
        gOamMatrices[i].b = 0x0000;
        gOamMatrices[i].c = 0x0000;
        gOamMatrices[i].d = 0x0100;
    }
}

void SetOamMatrix(u8 matrixNum, u16 a, u16 b, u16 c, u16 d)
{
    gOamMatrices[matrixNum].a = a;
    gOamMatrices[matrixNum].b = b;
    gOamMatrices[matrixNum].c = c;
    gOamMatrices[matrixNum].d = d;
}

void ResetSprite(struct Sprite *sprite)
{
    *sprite = sDummySprite;
}

void CalcCenterToCornerVec(struct Sprite *sprite, u8 shape, u8 size, u8 affineMode)
{
    u8 x = sCenterToCornerVecTable[shape][size][0];
    u8 y = sCenterToCornerVecTable[shape][size][1];

    if (affineMode & ST_OAM_AFFINE_DOUBLE_MASK)
    {
        x *= 2;
        y *= 2;
    }

    sprite->centerToCornerVecX = x;
    sprite->centerToCornerVecY = y;
}

s16 AllocSpriteTiles(u16 tileCount)
{
    u16 i;
    s16 start;
    u16 numTilesFound;

    if (tileCount == 0)
    {
        // Free all unreserved tiles if the tile count is 0.
        for (i = gReservedSpriteTileCount; i < TOTAL_OBJ_TILE_COUNT; i++)
            FREE_SPRITE_TILE(i);

        return 0;
    }

    i = gReservedSpriteTileCount;

    for (;;)
    {
        while (SPRITE_TILE_IS_ALLOCATED(i))
        {
            i++;

            if (i == TOTAL_OBJ_TILE_COUNT)
                return -1;
        }

        start = i;
        numTilesFound = 1;

        while (numTilesFound != tileCount)
        {
            i++;

            if (i == TOTAL_OBJ_TILE_COUNT)
                return -1;

            if (!SPRITE_TILE_IS_ALLOCATED(i))
                numTilesFound++;
            else
                break;
        }

        if (numTilesFound == tileCount)
            break;
    }

    for (i = start; i < tileCount + start; i++)
        ALLOC_SPRITE_TILE(i);

    return start;
}

u8 SpriteTileAllocBitmapOp(u16 bit, u8 op)
{
    u8 index = bit / 8;
    u8 shift = bit % 8;
    u8 val = bit % 8;
    u8 retVal = 0;

    if (op == 0)
    {
        val = ~(1 << val);
        sSpriteTileAllocBitmap[index] &= val;
    }
    else if (op == 1)
    {
        val = (1 << val);
        sSpriteTileAllocBitmap[index] |= val;
    }
    else
    {
        retVal = 1 << shift;
        retVal &= sSpriteTileAllocBitmap[index];
    }

    return retVal;
}

void SpriteCallbackDummy(struct Sprite *sprite)
{
}

void ProcessSpriteCopyRequests(void)
{
    if (sShouldProcessSpriteCopyRequests)
    {
        u8 i = 0;

        while (sSpriteCopyRequestCount > 0)
        {
            CpuCopy16(sSpriteCopyRequests[i].src, sSpriteCopyRequests[i].dest, sSpriteCopyRequests[i].size);
            sSpriteCopyRequestCount--;
            i++;
        }

        sShouldProcessSpriteCopyRequests = FALSE;
    }
}

void RequestSpriteFrameImageCopy(u16 index, u16 tileNum, const struct SpriteFrameImage *images)
{
    if (sSpriteCopyRequestCount < MAX_SPRITE_COPY_REQUESTS)
    {
        sSpriteCopyRequests[sSpriteCopyRequestCount].src = images[index].data;
        sSpriteCopyRequests[sSpriteCopyRequestCount].dest = (u8 *)OBJ_VRAM0 + TILE_SIZE_4BPP * tileNum;
        sSpriteCopyRequests[sSpriteCopyRequestCount].size = images[index].size;
        sSpriteCopyRequestCount++;
    }
}

void RequestSpriteCopy(const u8 *src, u8 *dest, u16 size)
{
    if (sSpriteCopyRequestCount < MAX_SPRITE_COPY_REQUESTS)
    {
        sSpriteCopyRequests[sSpriteCopyRequestCount].src = src;
        sSpriteCopyRequests[sSpriteCopyRequestCount].dest = dest;
        sSpriteCopyRequests[sSpriteCopyRequestCount].size = size;
        sSpriteCopyRequestCount++;
    }
}

void CopyFromSprites(u8 *dest)
{
    u32 i;
    u8 *src = (u8 *)gSprites;
    for (i = 0; i < sizeof(struct Sprite) * MAX_SPRITES; i++)
    {
        *dest = *src;
        dest++;
        src++;
    }
}

void CopyToSprites(u8 *src)
{
    u32 i;
    u8 *dest = (u8 *)gSprites;
    for (i = 0; i < sizeof(struct Sprite) * MAX_SPRITES; i++)
    {
        *dest = *src;
        src++;
        dest++;
    }
}

void ResetAllSprites(void)
{
    u8 i;

    for (i = 0; i < MAX_SPRITES; i++)
    {
        ResetSprite(&gSprites[i]);
        sSpriteOrder[i] = i;
    }

    ResetSprite(&gSprites[i]);
}

// UB: template pointer may point to freed temporary storage
void FreeSpriteTiles(struct Sprite *sprite)
{
    if (sprite->template->tileTag != 0xFFFF)
        FreeSpriteTilesByTag(sprite->template->tileTag);
}

// UB: template pointer may point to freed temporary storage
void FreeSpritePalette(struct Sprite *sprite)
{
    FreeSpritePaletteByTag(sprite->template->paletteTag);
}

void FreeSpriteOamMatrix(struct Sprite *sprite)
{
    if (sprite->oam.affineMode & ST_OAM_AFFINE_ON_MASK)
    {
        FreeOamMatrix(sprite->oam.matrixNum);
        sprite->oam.affineMode = ST_OAM_AFFINE_OFF;
    }
}

void DestroySpriteAndFreeResources(struct Sprite *sprite)
{
    FreeSpriteTiles(sprite);
    FreeSpritePalette(sprite);
    FreeSpriteOamMatrix(sprite);
    DestroySprite(sprite);
}

void AnimateSprite(struct Sprite *sprite)
{
    sAnimFuncs[sprite->animBeginning](sprite);

    if (!gAffineAnimsDisabled)
        sAffineAnimFuncs[sprite->affineAnimBeginning](sprite);
}

void BeginAnim(struct Sprite *sprite)
{
    s16 imageValue;
    u8 duration;
    u8 hFlip;
    u8 vFlip;

    sprite->animCmdIndex = 0;
    sprite->animEnded = FALSE;
    sprite->animLoopCounter = 0;
    imageValue = sprite->anims[sprite->animNum][sprite->animCmdIndex].frame.imageValue;

    if (imageValue != -1)
    {
        sprite->animBeginning = FALSE;
        duration = sprite->anims[sprite->animNum][sprite->animCmdIndex].frame.duration;
        hFlip = sprite->anims[sprite->animNum][sprite->animCmdIndex].frame.hFlip;
        vFlip = sprite->anims[sprite->animNum][sprite->animCmdIndex].frame.vFlip;

        if (duration)
            duration--;

        sprite->animDelayCounter = duration;

        if (!(sprite->oam.affineMode & ST_OAM_AFFINE_ON_MASK))
            SetSpriteOamFlipBits(sprite, hFlip, vFlip);

        if (sprite->usingSheet)
            sprite->oam.tileNum = sprite->sheetTileStart + imageValue;
        else
            RequestSpriteFrameImageCopy(imageValue, sprite->oam.tileNum, sprite->images);
    }
}

void ContinueAnim(struct Sprite *sprite)
{
    if (sprite->animDelayCounter)
    {
        u8 hFlip;
        u8 vFlip;
        DecrementAnimDelayCounter(sprite);
        hFlip = sprite->anims[sprite->animNum][sprite->animCmdIndex].frame.hFlip;
        vFlip = sprite->anims[sprite->animNum][sprite->animCmdIndex].frame.vFlip;
        if (!(sprite->oam.affineMode & ST_OAM_AFFINE_ON_MASK))
            SetSpriteOamFlipBits(sprite, hFlip, vFlip);
    }
    else if (!sprite->animPaused)
    {
        s16 type;
        s16 funcIndex;
        sprite->animCmdIndex++;
        type = sprite->anims[sprite->animNum][sprite->animCmdIndex].type;
        funcIndex = 3;
        if (type < 0)
            funcIndex = type + 3;
        sAnimCmdFuncs[funcIndex](sprite);
    }
}

void AnimCmd_frame(struct Sprite *sprite)
{
    s16 imageValue;
    u8 duration;
    u8 hFlip;
    u8 vFlip;

    imageValue = sprite->anims[sprite->animNum][sprite->animCmdIndex].frame.imageValue;
    duration = sprite->anims[sprite->animNum][sprite->animCmdIndex].frame.duration;
    hFlip = sprite->anims[sprite->animNum][sprite->animCmdIndex].frame.hFlip;
    vFlip = sprite->anims[sprite->animNum][sprite->animCmdIndex].frame.vFlip;

    if (duration)
        duration--;

    sprite->animDelayCounter = duration;

    if (!(sprite->oam.affineMode & ST_OAM_AFFINE_ON_MASK))
        SetSpriteOamFlipBits(sprite, hFlip, vFlip);

    if (sprite->usingSheet)
        sprite->oam.tileNum = sprite->sheetTileStart + imageValue;
    else
        RequestSpriteFrameImageCopy(imageValue, sprite->oam.tileNum, sprite->images);
}

void AnimCmd_end(struct Sprite *sprite)
{
    sprite->animCmdIndex--;
    sprite->animEnded = TRUE;
}

void AnimCmd_jump(struct Sprite *sprite)
{
    s16 imageValue;
    u8 duration;
    u8 hFlip;
    u8 vFlip;

    sprite->animCmdIndex = sprite->anims[sprite->animNum][sprite->animCmdIndex].jump.target;

    imageValue = sprite->anims[sprite->animNum][sprite->animCmdIndex].frame.imageValue;
    duration = sprite->anims[sprite->animNum][sprite->animCmdIndex].frame.duration;
    hFlip = sprite->anims[sprite->animNum][sprite->animCmdIndex].frame.hFlip;
    vFlip = sprite->anims[sprite->animNum][sprite->animCmdIndex].frame.vFlip;

    if (duration)
        duration--;

    sprite->animDelayCounter = duration;

    if (!(sprite->oam.affineMode & ST_OAM_AFFINE_ON_MASK))
        SetSpriteOamFlipBits(sprite, hFlip, vFlip);

    if (sprite->usingSheet)
        sprite->oam.tileNum = sprite->sheetTileStart + imageValue;
    else
        RequestSpriteFrameImageCopy(imageValue, sprite->oam.tileNum, sprite->images);
}

void AnimCmd_loop(struct Sprite *sprite)
{
    if (sprite->animLoopCounter)
        ContinueAnimLoop(sprite);
    else
        BeginAnimLoop(sprite);
}

void BeginAnimLoop(struct Sprite *sprite)
{
    sprite->animLoopCounter = sprite->anims[sprite->animNum][sprite->animCmdIndex].loop.count;
    JumpToTopOfAnimLoop(sprite);
    ContinueAnim(sprite);
}

void ContinueAnimLoop(struct Sprite *sprite)
{
    sprite->animLoopCounter--;
    JumpToTopOfAnimLoop(sprite);
    ContinueAnim(sprite);
}

void JumpToTopOfAnimLoop(struct Sprite *sprite)
{
    if (sprite->animLoopCounter)
    {
        sprite->animCmdIndex--;

        while (sprite->anims[sprite->animNum][sprite->animCmdIndex - 1].type != -3)
        {
            if (sprite->animCmdIndex == 0)
                break;
            sprite->animCmdIndex--;
        }

        sprite->animCmdIndex--;
    }
}

void BeginAffineAnim(struct Sprite *sprite)
{
    if ((sprite->oam.affineMode & ST_OAM_AFFINE_ON_MASK) && sprite->affineAnims[0][0].type != 32767)
    {
        struct AffineAnimFrameCmd frameCmd;
        u8 matrixNum = GetSpriteMatrixNum(sprite);
        AffineAnimStateRestartAnim(matrixNum);
        GetAffineAnimFrame(matrixNum, sprite, &frameCmd);
        sprite->affineAnimBeginning = FALSE;
        sprite->affineAnimEnded = FALSE;
        ApplyAffineAnimFrame(matrixNum, &frameCmd);
        sAffineAnimStates[matrixNum].delayCounter = frameCmd.duration;
        if (sprite->flags_f)
            obj_update_pos2(sprite, sprite->data[6], sprite->data[7]);
    }
}

void ContinueAffineAnim(struct Sprite *sprite)
{
    if (sprite->oam.affineMode & ST_OAM_AFFINE_ON_MASK)
    {
        u8 matrixNum = GetSpriteMatrixNum(sprite);

        if (sAffineAnimStates[matrixNum].delayCounter)
            AffineAnimDelay(matrixNum, sprite);
        else if (sprite->affineAnimPaused)
            return;
        else
        {
            s16 type;
            s16 funcIndex;
            sAffineAnimStates[matrixNum].animCmdIndex++;
            type = sprite->affineAnims[sAffineAnimStates[matrixNum].animNum][sAffineAnimStates[matrixNum].animCmdIndex].type;
            funcIndex = 3;
            if (type >= 32765)
                funcIndex = type - 32765;
            sAffineAnimCmdFuncs[funcIndex](matrixNum, sprite);
        }
        if (sprite->flags_f)
            obj_update_pos2(sprite, sprite->data[6], sprite->data[7]);
    }
}

void AffineAnimDelay(u8 matrixNum, struct Sprite *sprite)
{
    if (!DecrementAffineAnimDelayCounter(sprite, matrixNum))
    {
        struct AffineAnimFrameCmd frameCmd;
        GetAffineAnimFrame(matrixNum, sprite, &frameCmd);
        ApplyAffineAnimFrameRelativeAndUpdateMatrix(matrixNum, &frameCmd);
    }
}

void AffineAnimCmd_loop(u8 matrixNum, struct Sprite *sprite)
{
    if (sAffineAnimStates[matrixNum].loopCounter)
        ContinueAffineAnimLoop(matrixNum, sprite);
    else
        BeginAffineAnimLoop(matrixNum, sprite);
}

void BeginAffineAnimLoop(u8 matrixNum, struct Sprite *sprite)
{
    sAffineAnimStates[matrixNum].loopCounter = sprite->affineAnims[sAffineAnimStates[matrixNum].animNum][sAffineAnimStates[matrixNum].animCmdIndex].loop.count;
    JumpToTopOfAffineAnimLoop(matrixNum, sprite);
    ContinueAffineAnim(sprite);
}

void ContinueAffineAnimLoop(u8 matrixNum, struct Sprite *sprite)
{
    sAffineAnimStates[matrixNum].loopCounter--;
    JumpToTopOfAffineAnimLoop(matrixNum, sprite);
    ContinueAffineAnim(sprite);
}

void JumpToTopOfAffineAnimLoop(u8 matrixNum, struct Sprite *sprite)
{
    if (sAffineAnimStates[matrixNum].loopCounter)
    {
        sAffineAnimStates[matrixNum].animCmdIndex--;

        while (sprite->affineAnims[sAffineAnimStates[matrixNum].animNum][sAffineAnimStates[matrixNum].animCmdIndex - 1].type != 32765)
        {
            if (sAffineAnimStates[matrixNum].animCmdIndex == 0)
                break;
            sAffineAnimStates[matrixNum].animCmdIndex--;
        }

        sAffineAnimStates[matrixNum].animCmdIndex--;
    }
}

void AffineAnimCmd_jump(u8 matrixNum, struct Sprite *sprite)
{
    struct AffineAnimFrameCmd frameCmd;
    sAffineAnimStates[matrixNum].animCmdIndex = sprite->affineAnims[sAffineAnimStates[matrixNum].animNum][sAffineAnimStates[matrixNum].animCmdIndex].jump.target;
    GetAffineAnimFrame(matrixNum, sprite, &frameCmd);
    ApplyAffineAnimFrame(matrixNum, &frameCmd);
    sAffineAnimStates[matrixNum].delayCounter = frameCmd.duration;
}

void AffineAnimCmd_end(u8 matrixNum, struct Sprite *sprite)
{
    struct AffineAnimFrameCmd dummyFrameCmd = {0};
    sprite->affineAnimEnded = TRUE;
    sAffineAnimStates[matrixNum].animCmdIndex--;
    ApplyAffineAnimFrameRelativeAndUpdateMatrix(matrixNum, &dummyFrameCmd);
}

void AffineAnimCmd_frame(u8 matrixNum, struct Sprite *sprite)
{
    struct AffineAnimFrameCmd frameCmd;
    GetAffineAnimFrame(matrixNum, sprite, &frameCmd);
    ApplyAffineAnimFrame(matrixNum, &frameCmd);
    sAffineAnimStates[matrixNum].delayCounter = frameCmd.duration;
}

void CopyOamMatrix(u8 destMatrixIndex, struct OamMatrix *srcMatrix)
{
    gOamMatrices[destMatrixIndex].a = srcMatrix->a;
    gOamMatrices[destMatrixIndex].b = srcMatrix->b;
    gOamMatrices[destMatrixIndex].c = srcMatrix->c;
    gOamMatrices[destMatrixIndex].d = srcMatrix->d;
}

u8 GetSpriteMatrixNum(struct Sprite *sprite)
{
    u8 matrixNum = 0;
    if (sprite->oam.affineMode & ST_OAM_AFFINE_ON_MASK)
        matrixNum = sprite->oam.matrixNum;
    return matrixNum;
}

void sub_8007E18(struct Sprite* sprite, s16 a2, s16 a3)
{
    sprite->data[6] = a2;
    sprite->data[7] = a3;
    sprite->flags_f = 1;
}

s32 sub_8007E28(s32 a0, s32 a1, s32 a2)
{
    s32 subResult, var1;

    subResult = a1 - a0;
    if (subResult < 0)
        var1 = -(subResult) >> 9;
    else
        var1 = -(subResult >> 9);
    return a2 - ((u32)(a2 * a1) / (u32)(a0) + var1);
}

void obj_update_pos2(struct Sprite *sprite, s32 a1, s32 a2)
{
    s32 var0, var1, var2;

    u32 matrixNum = sprite->oam.matrixNum;
    if (a1 != 0x800)
    {
        var0 = sUnknown_082EC6F4[sprite->oam.shape][sprite->oam.size][0];
        var1 = var0 << 8;
        var2 = (var0 << 16) / gOamMatrices[matrixNum].a;
        sprite->pos2.x = sub_8007E28(var1, var2, a1);
    }
    if (a2 != 0x800)
    {
        var0 = sUnknown_082EC6F4[sprite->oam.shape][sprite->oam.size][1];
        var1 = var0 << 8;
        var2 = (var0 << 16) / gOamMatrices[matrixNum].d;
        sprite->pos2.y = sub_8007E28(var1, var2, a2);
    }
}

void SetSpriteOamFlipBits(struct Sprite *sprite, u8 hFlip, u8 vFlip)
{
    sprite->oam.matrixNum &= 0x7;
    sprite->oam.matrixNum |= (((hFlip ^ sprite->hFlip) & 1) << 3);
    sprite->oam.matrixNum |= (((vFlip ^ sprite->vFlip) & 1) << 4);
}

void AffineAnimStateRestartAnim(u8 matrixNum)
{
    sAffineAnimStates[matrixNum].animCmdIndex = 0;
    sAffineAnimStates[matrixNum].delayCounter = 0;
    sAffineAnimStates[matrixNum].loopCounter = 0;
}

void AffineAnimStateStartAnim(u8 matrixNum, u8 animNum)
{
    sAffineAnimStates[matrixNum].animNum = animNum;
    sAffineAnimStates[matrixNum].animCmdIndex = 0;
    sAffineAnimStates[matrixNum].delayCounter = 0;
    sAffineAnimStates[matrixNum].loopCounter = 0;
    sAffineAnimStates[matrixNum].xScale = 0x0100;
    sAffineAnimStates[matrixNum].yScale = 0x0100;
    sAffineAnimStates[matrixNum].rotation = 0;
}

void AffineAnimStateReset(u8 matrixNum)
{
    sAffineAnimStates[matrixNum].animNum = 0;
    sAffineAnimStates[matrixNum].animCmdIndex = 0;
    sAffineAnimStates[matrixNum].delayCounter = 0;
    sAffineAnimStates[matrixNum].loopCounter = 0;
    sAffineAnimStates[matrixNum].xScale = 0x0100;
    sAffineAnimStates[matrixNum].yScale = 0x0100;
    sAffineAnimStates[matrixNum].rotation = 0;
}

void ApplyAffineAnimFrameAbsolute(u8 matrixNum, struct AffineAnimFrameCmd *frameCmd)
{
    sAffineAnimStates[matrixNum].xScale = frameCmd->xScale;
    sAffineAnimStates[matrixNum].yScale = frameCmd->yScale;
    sAffineAnimStates[matrixNum].rotation = frameCmd->rotation << 8;
}

void DecrementAnimDelayCounter(struct Sprite *sprite)
{
    if (!sprite->animPaused)
        sprite->animDelayCounter--;
}

bool8 DecrementAffineAnimDelayCounter(struct Sprite *sprite, u8 matrixNum)
{
    if (!sprite->affineAnimPaused)
        --sAffineAnimStates[matrixNum].delayCounter;
    return sprite->affineAnimPaused;
}

void ApplyAffineAnimFrameRelativeAndUpdateMatrix(u8 matrixNum, struct AffineAnimFrameCmd *frameCmd)
{
    struct ObjAffineSrcData srcData;
    struct OamMatrix matrix;
    sAffineAnimStates[matrixNum].xScale += frameCmd->xScale;
    sAffineAnimStates[matrixNum].yScale += frameCmd->yScale;
    sAffineAnimStates[matrixNum].rotation = (sAffineAnimStates[matrixNum].rotation + (frameCmd->rotation << 8)) & ~0xFF;
    srcData.xScale = ConvertScaleParam(sAffineAnimStates[matrixNum].xScale);
    srcData.yScale = ConvertScaleParam(sAffineAnimStates[matrixNum].yScale);
    srcData.rotation = sAffineAnimStates[matrixNum].rotation;
    ObjAffineSet(&srcData, &matrix, 1, 2);
    CopyOamMatrix(matrixNum, &matrix);
}

s16 ConvertScaleParam(s16 scale)
{
    s32 val = 0x10000;
    return val / scale;
}

void GetAffineAnimFrame(u8 matrixNum, struct Sprite *sprite, struct AffineAnimFrameCmd *frameCmd)
{
    frameCmd->xScale = sprite->affineAnims[sAffineAnimStates[matrixNum].animNum][sAffineAnimStates[matrixNum].animCmdIndex].frame.xScale;
    frameCmd->yScale = sprite->affineAnims[sAffineAnimStates[matrixNum].animNum][sAffineAnimStates[matrixNum].animCmdIndex].frame.yScale;
    frameCmd->rotation = sprite->affineAnims[sAffineAnimStates[matrixNum].animNum][sAffineAnimStates[matrixNum].animCmdIndex].frame.rotation;
    frameCmd->duration = sprite->affineAnims[sAffineAnimStates[matrixNum].animNum][sAffineAnimStates[matrixNum].animCmdIndex].frame.duration;
}

void ApplyAffineAnimFrame(u8 matrixNum, struct AffineAnimFrameCmd *frameCmd)
{
    struct AffineAnimFrameCmd dummyFrameCmd = {0};

    if (frameCmd->duration)
    {
        frameCmd->duration--;
        ApplyAffineAnimFrameRelativeAndUpdateMatrix(matrixNum, frameCmd);
    }
    else
    {
        ApplyAffineAnimFrameAbsolute(matrixNum, frameCmd);
        ApplyAffineAnimFrameRelativeAndUpdateMatrix(matrixNum, &dummyFrameCmd);
    }
}

void StartSpriteAnim(struct Sprite *sprite, u8 animNum)
{
    sprite->animNum = animNum;
    sprite->animBeginning = TRUE;
    sprite->animEnded = FALSE;
}

void StartSpriteAnimIfDifferent(struct Sprite *sprite, u8 animNum)
{
    if (sprite->animNum != animNum)
        StartSpriteAnim(sprite, animNum);
}

void SeekSpriteAnim(struct Sprite *sprite, u8 animCmdIndex)
{
    u8 temp = sprite->animPaused;
    sprite->animCmdIndex = animCmdIndex - 1;
    sprite->animDelayCounter = 0;
    sprite->animBeginning = FALSE;
    sprite->animEnded = FALSE;
    sprite->animPaused = FALSE;
    ContinueAnim(sprite);
    if (sprite->animDelayCounter)
        sprite->animDelayCounter++;
    sprite->animPaused = temp;
}

void StartSpriteAffineAnim(struct Sprite *sprite, u8 animNum)
{
    u8 matrixNum = GetSpriteMatrixNum(sprite);
    AffineAnimStateStartAnim(matrixNum, animNum);
    sprite->affineAnimBeginning = TRUE;
    sprite->affineAnimEnded = FALSE;
}

void StartSpriteAffineAnimIfDifferent(struct Sprite *sprite, u8 animNum)
{
    u8 matrixNum = GetSpriteMatrixNum(sprite);
    if (sAffineAnimStates[matrixNum].animNum != animNum)
        StartSpriteAffineAnim(sprite, animNum);
}

void ChangeSpriteAffineAnim(struct Sprite *sprite, u8 animNum)
{
    u8 matrixNum = GetSpriteMatrixNum(sprite);
    sAffineAnimStates[matrixNum].animNum = animNum;
    sprite->affineAnimBeginning = TRUE;
    sprite->affineAnimEnded = FALSE;
}

void ChangeSpriteAffineAnimIfDifferent(struct Sprite *sprite, u8 animNum)
{
    u8 matrixNum = GetSpriteMatrixNum(sprite);
    if (sAffineAnimStates[matrixNum].animNum != animNum)
        ChangeSpriteAffineAnim(sprite, animNum);
}

void SetSpriteSheetFrameTileNum(struct Sprite *sprite)
{
    if (sprite->usingSheet)
    {
        s16 tileOffset = sprite->anims[sprite->animNum][sprite->animCmdIndex].frame.imageValue;
        if (tileOffset < 0)
            tileOffset = 0;
        sprite->oam.tileNum = sprite->sheetTileStart + tileOffset;
    }
}

void ResetAffineAnimData(void)
{
    u8 i;

    gAffineAnimsDisabled = FALSE;
    gOamMatrixAllocBitmap = 0;

    ResetOamMatrices();

    for (i = 0; i < OAM_MATRIX_COUNT; i++)
        AffineAnimStateReset(i);
}

u8 AllocOamMatrix(void)
{
    u8 i = 0;
    u32 bit = 1;
    u32 bitmap = gOamMatrixAllocBitmap;

    while (i < OAM_MATRIX_COUNT)
    {
        if (!(bitmap & bit))
        {
            gOamMatrixAllocBitmap |= bit;
            return i;
        }

        i++;
        bit <<= 1;
    }

    return 0xFF;
}

void FreeOamMatrix(u8 matrixNum)
{
    u8 i = 0;
    u32 bit = 1;

    while (i < matrixNum)
    {
        i++;
        bit <<= 1;
    }

    gOamMatrixAllocBitmap &= ~bit;
    SetOamMatrix(matrixNum, 0x100, 0, 0, 0x100);
}

void InitSpriteAffineAnim(struct Sprite *sprite)
{
    u8 matrixNum = AllocOamMatrix();
    if (matrixNum != 0xFF)
    {
        CalcCenterToCornerVec(sprite, sprite->oam.shape, sprite->oam.size, sprite->oam.affineMode);
        sprite->oam.matrixNum = matrixNum;
        sprite->affineAnimBeginning = TRUE;
        AffineAnimStateReset(matrixNum);
    }
}

void SetOamMatrixRotationScaling(u8 matrixNum, s16 xScale, s16 yScale, u16 rotation)
{
    struct ObjAffineSrcData srcData;
    struct OamMatrix matrix;
    srcData.xScale = ConvertScaleParam(xScale);
    srcData.yScale = ConvertScaleParam(yScale);
    srcData.rotation = rotation;
    ObjAffineSet(&srcData, &matrix, 1, 2);
    CopyOamMatrix(matrixNum, &matrix);
}

u16 LoadSpriteSheet(const struct SpriteSheet *sheet)
{
    s16 tileStart = AllocSpriteTiles(sheet->size / TILE_SIZE_4BPP);

    if (tileStart < 0)
    {
        return 0;
    }
    else
    {
        AllocSpriteTileRange(sheet->tag, (u16)tileStart, sheet->size / TILE_SIZE_4BPP);
        CpuCopy16(sheet->data, (u8 *)OBJ_VRAM0 + TILE_SIZE_4BPP * tileStart, sheet->size);
        return (u16)tileStart;
    }
}

void LoadSpriteSheets(const struct SpriteSheet *sheets)
{
    u8 i;
    for (i = 0; sheets[i].data != NULL; i++)
        LoadSpriteSheet(&sheets[i]);
}

void FreeSpriteTilesByTag(u16 tag)
{
    u8 index = IndexOfSpriteTileTag(tag);
    if (index != 0xFF)
    {
        u16 i;
        u16 *rangeStarts;
        u16 *rangeCounts;
        u16 start;
        u16 count;
        rangeStarts = sSpriteTileRanges;
        start = rangeStarts[index * 2];
        rangeCounts = sSpriteTileRanges + 1;
        count = rangeCounts[index * 2];

        for (i = start; i < start + count; i++)
            FREE_SPRITE_TILE(i);

        sSpriteTileRangeTags[index] = 0xFFFF;
    }
}

void FreeSpriteTileRanges(void)
{
    u8 i;

    for (i = 0; i < MAX_SPRITES; i++)
    {
        sSpriteTileRangeTags[i] = 0xFFFF;
        SET_SPRITE_TILE_RANGE(i, 0, 0);
    }
}

u16 GetSpriteTileStartByTag(u16 tag)
{
    u8 index = IndexOfSpriteTileTag(tag);
    if (index == 0xFF)
        return 0xFFFF;
    return sSpriteTileRanges[index * 2];
}

u8 IndexOfSpriteTileTag(u16 tag)
{
    u8 i;

    for (i = 0; i < MAX_SPRITES; i++)
        if (sSpriteTileRangeTags[i] == tag)
            return i;

    return 0xFF;
}

u16 GetSpriteTileTagByTileStart(u16 start)
{
    u8 i;

    for (i = 0; i < MAX_SPRITES; i++)
    {
        if (sSpriteTileRangeTags[i] != 0xFFFF && sSpriteTileRanges[i * 2] == start)
            return sSpriteTileRangeTags[i];
    }

    return 0xFFFF;
}

void AllocSpriteTileRange(u16 tag, u16 start, u16 count)
{
    u8 freeIndex = IndexOfSpriteTileTag(0xFFFF);
    sSpriteTileRangeTags[freeIndex] = tag;
    SET_SPRITE_TILE_RANGE(freeIndex, start, count);
}

void FreeAllSpritePalettes(void)
{
    u8 i;
    gReservedSpritePaletteCount = 0;
    for (i = 0; i < 16; i++)
        sSpritePaletteTags[i] = 0xFFFF;
}

u8 LoadSpritePalette(const struct SpritePalette *palette)
{
    u8 index = IndexOfSpritePaletteTag(palette->tag);

    if (index != 0xFF)
        return index;

    index = IndexOfSpritePaletteTag(0xFFFF);

    if (index == 0xFF)
    {
        return 0xFF;
    }
    else
    {
        sSpritePaletteTags[index] = palette->tag;
        DoLoadSpritePalette(palette->data, index * 16);
        return index;
    }
}

void LoadSpritePalettes(const struct SpritePalette *palettes)
{
    u8 i;
    for (i = 0; palettes[i].data != NULL; i++)
        if (LoadSpritePalette(&palettes[i]) == 0xFF)
            break;
}

void DoLoadSpritePalette(const u16 *src, u16 paletteOffset)
{
    LoadPalette(src, paletteOffset + 0x100, 32);
}

u8 AllocSpritePalette(u16 tag)
{
    u8 index = IndexOfSpritePaletteTag(0xFFFF);
    if (index == 0xFF)
    {
        return 0xFF;
    }
    else
    {
        sSpritePaletteTags[index] = tag;
        return index;
    }
}

u8 IndexOfSpritePaletteTag(u16 tag)
{
    u8 i;
    for (i = gReservedSpritePaletteCount; i < 16; i++)
        if (sSpritePaletteTags[i] == tag)
            return i;

    return 0xFF;
}

u16 GetSpritePaletteTagByPaletteNum(u8 paletteNum)
{
    return sSpritePaletteTags[paletteNum];
}

void FreeSpritePaletteByTag(u16 tag)
{
    u8 index = IndexOfSpritePaletteTag(tag);
    if (index != 0xFF)
        sSpritePaletteTags[index] = 0xFFFF;
}

void SetSubspriteTables(struct Sprite *sprite, const struct SubspriteTable *subspriteTables)
{
    sprite->subspriteTables = subspriteTables;
    sprite->subspriteTableNum = 0;
    sprite->subspriteMode = SUBSPRITES_ON;
}

bool8 AddSpriteToOamBuffer(struct Sprite *sprite, u8 *oamIndex)
{
    if (*oamIndex >= gOamLimit)
        return 1;

    if (!sprite->subspriteTables || sprite->subspriteMode == SUBSPRITES_OFF)
    {
        gMain.oamBuffer[*oamIndex] = sprite->oam;
        (*oamIndex)++;
        return 0;
    }
    else
    {
        return AddSubspritesToOamBuffer(sprite, &gMain.oamBuffer[*oamIndex], oamIndex);
    }
}

bool8 AddSubspritesToOamBuffer(struct Sprite *sprite, struct OamData *destOam, u8 *oamIndex)
{
    const struct SubspriteTable *subspriteTable;
    struct OamData *oam;

    if (*oamIndex >= gOamLimit)
        return 1;

    subspriteTable = &sprite->subspriteTables[sprite->subspriteTableNum];
    oam = &sprite->oam;

    if (!subspriteTable || !subspriteTable->subsprites)
    {
        *destOam = *oam;
        (*oamIndex)++;
        return 0;
    }
    else
    {
        u16 tileNum;
        u16 baseX;
        u16 baseY;
        u8 subspriteCount;
        u8 hFlip;
        u8 vFlip;
        u8 i;

        tileNum = oam->tileNum;
        subspriteCount = subspriteTable->subspriteCount;
        hFlip = ((s32)oam->matrixNum >> 3) & 1;
        vFlip = ((s32)oam->matrixNum >> 4) & 1;
        baseX = oam->x - sprite->centerToCornerVecX;
        baseY = oam->y - sprite->centerToCornerVecY;

        for (i = 0; i < subspriteCount; i++, (*oamIndex)++)
        {
            u16 x;
            u16 y;

            if (*oamIndex >= gOamLimit)
                return 1;

            x = subspriteTable->subsprites[i].x;
            y = subspriteTable->subsprites[i].y;

            if (hFlip)
            {
                s8 width = sOamDimensions[subspriteTable->subsprites[i].shape][subspriteTable->subsprites[i].size].width;
                s16 right = x;
                right += width;
                x = right;
                x = ~x + 1;
            }

            if (vFlip)
            {
                s8 height = sOamDimensions[subspriteTable->subsprites[i].shape][subspriteTable->subsprites[i].size].height;
                s16 bottom = y;
                bottom += height;
                y = bottom;
                y = ~y + 1;
            }

            destOam[i] = *oam;
            destOam[i].shape = subspriteTable->subsprites[i].shape;
            destOam[i].size = subspriteTable->subsprites[i].size;
            destOam[i].x = (s16)baseX + (s16)x;
            destOam[i].y = baseY + y;
            destOam[i].tileNum = tileNum + subspriteTable->subsprites[i].tileOffset;

            if (sprite->subspriteMode != SUBSPRITES_IGNORE_PRIORITY)
                destOam[i].priority = subspriteTable->subsprites[i].priority;
        }
    }

    return 0;
}
