#include "global.h"
#include "battle_anim.h"
#include "palette.h"
#include "trig.h"
#include "constants/battle_anim.h"
#include "constants/rgb.h"

void sub_810DE70(struct Sprite *);
void sub_810DFA8(struct Sprite *);
void sub_810E044(struct Sprite *);
void sub_810E13C(struct Sprite *);
void sub_810E1C8(struct Sprite *);
void sub_810E314(struct Sprite *);
extern void sub_810EA4C(struct Sprite *);
extern void sub_810EAA0(struct Sprite *);
extern void sub_810EC34(struct Sprite *);
extern void sub_810EC94(struct Sprite *);
extern void sub_810ED28(struct Sprite *);
extern void sub_810EE14(struct Sprite *);
extern void sub_810EEF8(struct Sprite *);
extern void sub_810F004(struct Sprite *);
extern void sub_810F084(struct Sprite *);

static void sub_810DE98(struct Sprite *);
static void sub_810DF18(u8);
static void sub_810E028(struct Sprite *);
static void sub_810E184(struct Sprite *);
static void sub_810E24C(struct Sprite *);
void sub_810E520(struct Sprite *);

const struct SpriteTemplate gUnknown_08596270 =
{
    .tileTag = ANIM_TAG_GUST,
    .paletteTag = ANIM_TAG_GUST,
    .oam = &gUnknown_0852495C,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_810DE70,
};

const union AffineAnimCmd gUnknown_08596288[] =
{
    AFFINEANIMCMD_FRAME(0x10, 0x100, 0, 0),
    AFFINEANIMCMD_FRAME(0xA, 0x0, 0, 24),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd *const gUnknown_085962A0[] =
{
    gUnknown_08596288,
};

const struct SpriteTemplate gBattleAnimSpriteTemplate_85962A4 =
{
    .tileTag = ANIM_TAG_GUST,
    .paletteTag = ANIM_TAG_GUST,
    .oam = &gUnknown_085249BC,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gUnknown_085962A0,
    .callback = sub_810DFA8,
};

const union AnimCmd gUnknown_085962BC[] =
{
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(0, 3, .hFlip = TRUE),
    ANIMCMD_FRAME(0, 3, .vFlip = TRUE),
    ANIMCMD_FRAME(0, 3, .vFlip = TRUE, .hFlip = TRUE),
    ANIMCMD_JUMP(0),
};

const union AnimCmd *const gUnknown_085962D0[] =
{
    gUnknown_085962BC,
};

const struct SpriteTemplate gUnknown_085962D4 =
{
    .tileTag = ANIM_TAG_AIR_WAVE_2,
    .paletteTag = ANIM_TAG_AIR_WAVE_2,
    .oam = &gUnknown_08524934,
    .anims = gUnknown_085962D0,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_810E044,
};

const union AffineAnimCmd gUnknown_085962EC[] =
{
    AFFINEANIMCMD_FRAME(0x10, 0x100, 0, 0),
    AFFINEANIMCMD_FRAME(0x28, 0x0, 0, 6),
    AFFINEANIMCMD_FRAME(0x0, 0xFFE0, 0, 5),
    AFFINEANIMCMD_FRAME(0xFFF0, 0x20, 0, 10),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd *const gUnknown_08596314[] =
{
        gUnknown_085962EC,
};

const union AffineAnimCmd gUnknown_08596318[] =
{
    AFFINEANIMCMD_FRAME(0x0, 0x0, 50, 1),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd gUnknown_08596328[] =
{
    AFFINEANIMCMD_FRAME(0x0, 0x0, -40, 1),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd *const gUnknown_08596338[] =
{
    gUnknown_08596318,
    gUnknown_08596328,
};

const struct SpriteTemplate gUnknown_08596340 =
{
    .tileTag = ANIM_TAG_ROUND_SHADOW,
    .paletteTag = ANIM_TAG_ROUND_SHADOW,
    .oam = &gUnknown_085249DC,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gUnknown_08596314,
    .callback = sub_810E13C,
};

const struct SpriteTemplate gUnknown_08596358 =
{
    .tileTag = ANIM_TAG_ROUND_SHADOW,
    .paletteTag = ANIM_TAG_ROUND_SHADOW,
    .oam = &gUnknown_0852497C,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gUnknown_08596338,
    .callback = sub_810E1C8,
};

const union AnimCmd gUnknown_08596370[] =
{
    ANIMCMD_FRAME(0, 0),
    ANIMCMD_END,
};

const union AnimCmd gUnknown_08596378[] =
{
    ANIMCMD_FRAME(16, 0, .hFlip = TRUE),
    ANIMCMD_END,
};

const union AnimCmd *const gUnknown_08596380[] =
{
    gUnknown_08596370,
    gUnknown_08596378,
};

const struct SpriteTemplate gUnknown_08596388 =
{
    .tileTag = ANIM_TAG_WHITE_FEATHER,
    .paletteTag = ANIM_TAG_WHITE_FEATHER,
    .oam = &gUnknown_08524974,
    .anims = gUnknown_08596380,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_810E314,
};

const struct SpriteTemplate gUnknown_085963A0 =
{
    .tileTag = ANIM_TAG_SMALL_BUBBLES,
    .paletteTag = ANIM_TAG_SMALL_BUBBLES,
    .oam = &gUnknown_0852490C,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_810EA4C,
};

const union AnimCmd gUnknown_085963B8[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_FRAME(8, 1),
    ANIMCMD_FRAME(16, 1),
    ANIMCMD_FRAME(8, 1, .hFlip = TRUE),
    ANIMCMD_FRAME(0, 1, .hFlip = TRUE),
    ANIMCMD_END,
};

const union AnimCmd *const gUnknown_085963D0[] =
{
    gUnknown_085963B8,
};

const struct SpriteTemplate gUnknown_085963D4 =
{
    .tileTag = ANIM_TAG_WHIRLWIND_LINES,
    .paletteTag = ANIM_TAG_WHIRLWIND_LINES,
    .oam = &gUnknown_08524934,
    .anims = gUnknown_085963D0,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_810EAA0,
};

const union AffineAnimCmd gUnknown_085963EC[] =
{
    AFFINEANIMCMD_FRAME(0x10, 0x100, 0, 0),
    AFFINEANIMCMD_FRAME(0x28, 0x0, 0, 6),
    AFFINEANIMCMD_FRAME(0x0, 0xFFE0, 0, 5),
    AFFINEANIMCMD_FRAME(0xFFEC, 0x0, 0, 7),
    AFFINEANIMCMD_FRAME(0xFFEC, 0xFFEC, 0, 5),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd *const gUnknown_0859641C[] =
{
    gUnknown_085963EC,
};

const struct SpriteTemplate gUnknown_08596420 =
{
    .tileTag = ANIM_TAG_ROUND_SHADOW,
    .paletteTag = ANIM_TAG_ROUND_SHADOW,
    .oam = &gUnknown_085249DC,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gUnknown_0859641C,
    .callback = sub_810EC34,
};

const union AffineAnimCmd gUnknown_08596438[] =
{
    AFFINEANIMCMD_FRAME(0xA0, 0x100, 0, 0),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd *const gUnknown_08596448[] =
{
    gUnknown_08596438,
};

const struct SpriteTemplate gUnknown_0859644C =
{
    .tileTag = ANIM_TAG_ROUND_SHADOW,
    .paletteTag = ANIM_TAG_ROUND_SHADOW,
    .oam = &gUnknown_085249DC,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gUnknown_08596448,
    .callback = sub_810EC94,
};

const union AffineAnimCmd gUnknown_08596464[] =
{
    AFFINEANIMCMD_FRAME(0x10, 0x100, 0, 0),
    AFFINEANIMCMD_FRAME(0x28, 0x0, 0, 6),
    AFFINEANIMCMD_FRAME(0x0, 0xFFE0, 0, 5),
    AFFINEANIMCMD_FRAME(0xFFF0, 0x20, 0, 10),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd *const gUnknown_0859648C[] =
{
    gUnknown_08596464,
};

const struct SpriteTemplate gUnknown_08596490 =
{
    .tileTag = ANIM_TAG_ROUND_SHADOW,
    .paletteTag = ANIM_TAG_ROUND_SHADOW,
    .oam = &gUnknown_085249DC,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gUnknown_0859648C,
    .callback = sub_810ED28,
};

const union AffineAnimCmd gUnknown_085964A8[] =
{
    AFFINEANIMCMD_FRAME(0x100, 0x0, 0, 0),
    AFFINEANIMCMD_FRAME(0x0, 0x20, 0, 12),
    AFFINEANIMCMD_FRAME(0x0, 0xFFE0, 0, 11),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd *const gUnknown_085964C8[] =
{
    gUnknown_085964A8,
};

const struct SpriteTemplate gUnknown_085964CC =
{
    .tileTag = ANIM_TAG_SPLASH,
    .paletteTag = ANIM_TAG_SPLASH,
    .oam = &gUnknown_085249DC,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_810EE14,
};

const struct SpriteTemplate gUnknown_085964E4 =
{
    .tileTag = ANIM_TAG_SWEAT_BEAD,
    .paletteTag = ANIM_TAG_SWEAT_BEAD,
    .oam = &gUnknown_08524904,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_810EEF8,
};

const struct SpriteTemplate gUnknown_085964FC =
{
    .tileTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .paletteTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .oam = &gUnknown_08524A3C,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_810F004,
};

const struct SpriteTemplate gUnknown_08596514 =
{
    .tileTag = ANIM_TAG_BIRD,
    .paletteTag = ANIM_TAG_BIRD,
    .oam = &gUnknown_085249DC,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_810F084,
};


void sub_810DE70(struct Sprite *sprite)
{
    InitSpritePosToAnimTarget(sprite, FALSE);
    sprite->pos1.y += 20;
    sprite->data[1] = 191;
    sprite->callback = sub_810DE98;
    sprite->callback(sprite);
}

static void sub_810DE98(struct Sprite *sprite) {
    sprite->pos2.x = Sin(sprite->data[1], 32);
    sprite->pos2.y = Cos(sprite->data[1], 8);
    sprite->data[1] += 5;
    sprite->data[1] &= 0xFF;
    if (++sprite->data[0] == 71)
        DestroyAnimSprite(sprite);
}

void sub_810DED8(u8 taskId)
{
    gTasks[taskId].data[0] = gBattleAnimArgs[1];
    gTasks[taskId].data[1] = gBattleAnimArgs[0];
    gTasks[taskId].data[2] = IndexOfSpritePaletteTag(ANIM_TAG_GUST);
    gTasks[taskId].func = sub_810DF18;
}

static void sub_810DF18(u8 taskId)
{
    u8 data2;
    u16 temp;
    int i, base;

    if (gTasks[taskId].data[10]++ == gTasks[taskId].data[1])
    {
        gTasks[taskId].data[10] = 0;
        data2 = gTasks[taskId].data[2];
        temp = gPlttBufferFaded[16 * data2 + 0x108];
        i = 7;
        base = data2 * 16;

        do
        {
            gPlttBufferFaded[base + 0x101 + i] = gPlttBufferFaded[base + 0x100 + i];
            i--;
        }
        while (i > 0);

        gPlttBufferFaded[base + 0x101] = temp;
    }

    if (--gTasks[taskId].data[0] == 0)
        DestroyAnimVisualTask(taskId);
}

void sub_810DFA8(struct Sprite *sprite)
{
    InitSpritePosToAnimAttacker(sprite, TRUE);
    if (GetBattlerSide(gBattleAnimAttacker) != B_SIDE_PLAYER)
        gBattleAnimArgs[2] = -gBattleAnimArgs[2];

    sprite->data[0] = gBattleAnimArgs[4];
    sprite->data[1] = sprite->pos1.x;
    sprite->data[2] = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X_2) + gBattleAnimArgs[2];
    sprite->data[3] = sprite->pos1.y;
    sprite->data[4] = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y_PIC_OFFSET) + gBattleAnimArgs[3];
    InitAnimLinearTranslation(sprite);
    sprite->callback = RunStoredCallbackWhenAffineAnimEnds;
    StoreSpriteCallbackInData6(sprite, sub_810E028);
}

static void sub_810E028(struct Sprite *sprite)
{
    if (AnimTranslateLinear(sprite))
        DestroyAnimSprite(sprite);
}

void sub_810E044(struct Sprite *sprite)
{
    if (GetBattlerSide(gBattleAnimAttacker) != B_SIDE_PLAYER)
    {
        gBattleAnimArgs[0] = -gBattleAnimArgs[0];
        gBattleAnimArgs[1] = -gBattleAnimArgs[1];
        gBattleAnimArgs[2] = -gBattleAnimArgs[2];
        gBattleAnimArgs[3] = -gBattleAnimArgs[3];
    }

    if (IsContest())
    {
        gBattleAnimArgs[1] = -gBattleAnimArgs[1];
        gBattleAnimArgs[3] = -gBattleAnimArgs[3];
    }

    sprite->pos1.x = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_X_2);
    sprite->pos1.y = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_Y_PIC_OFFSET);
    sprite->pos1.x += gBattleAnimArgs[0];
    sprite->pos1.y += gBattleAnimArgs[1];
    sprite->data[0] = gBattleAnimArgs[4];

    if (gBattleAnimArgs[6] == 0)
    {
        sprite->data[2] = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X_2);
        sprite->data[4] = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y_PIC_OFFSET);
    }
    else
    {
        SetAverageBattlerPositions(gBattleAnimTarget, 1, &sprite->data[2], &sprite->data[4]);
    }

    sprite->data[2] = sprite->data[2] + gBattleAnimArgs[2];
    sprite->data[4] = sprite->data[4] + gBattleAnimArgs[3];
    sprite->callback = StartAnimLinearTranslation;

    StoreSpriteCallbackInData6(sprite, DestroyAnimSprite);
    SeekSpriteAnim(sprite, gBattleAnimArgs[5]);
}

void sub_810E13C(struct Sprite *sprite)
{
    InitSpritePosToAnimAttacker(sprite, TRUE);
    sprite->data[0] = gBattleAnimArgs[2];
    sprite->data[1] = gBattleAnimArgs[3];
    sprite->callback = sub_810E184;
    gSprites[GetAnimBattlerSpriteId(ANIM_ATTACKER)].invisible = 1;
}

static void sub_810E184(struct Sprite *sprite)
{
    if (sprite->data[0] > 0)
    {
        sprite->data[0]--;
    }
    else
    {
        sprite->data[2] += sprite->data[1];
        sprite->pos2.y -= (sprite->data[2] >> 8);
    }

    if (sprite->pos1.y + sprite->pos2.y < -32)
        DestroyAnimSprite(sprite);
}

void sub_810E1C8(struct Sprite *sprite)
{
    if (GetBattlerSide(gBattleAnimAttacker) != B_SIDE_PLAYER)
    {
        sprite->pos1.x = 272;
        sprite->pos1.y = -32;
        StartSpriteAffineAnim(sprite, 1);
    }
    else
    {
        sprite->pos1.x = -32;
        sprite->pos1.y = -32;
    }

    sprite->data[0] = gBattleAnimArgs[0];
    sprite->data[1] = sprite->pos1.x;
    sprite->data[2] = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X_2);
    sprite->data[3] = sprite->pos1.y;
    sprite->data[4] = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y_PIC_OFFSET);

    InitAnimLinearTranslation(sprite);
    sprite->callback = sub_810E24C;
}

static void sub_810E24C(struct Sprite *sprite)
{
    sprite->data[0] = 1;
    AnimTranslateLinear(sprite);
    if (((u16)sprite->data[3] >> 8) > 200)
    {
        sprite->pos1.x += sprite->pos2.x;
        sprite->pos2.x = 0;
        sprite->data[3] &= 0xFF;
    }

    if ((u32)(sprite->pos1.x + sprite->pos2.x + 32) > 304 || sprite->pos1.y + sprite->pos2.y > 160)
    {
        gSprites[GetAnimBattlerSpriteId(ANIM_ATTACKER)].invisible = 0;
        DestroyAnimSprite(sprite);
    }
}

void sub_810E2C8(struct Sprite *sprite)
{
    if (sprite->data[0]-- <= 0)
    {
        if (sprite->oam.affineMode & ST_OAM_AFFINE_ON_MASK)
        {
            FreeOamMatrix(sprite->oam.matrixNum);
            sprite->oam.affineMode = 0;
        }

        DestroySprite(sprite);
        gAnimVisualTaskCount--;
    }
}

// FAKEMATCHING
void sub_810E314(struct Sprite *sprite)
{
    s16 *data;
    u8 slot;
    s16 spriteCoord;
    int t1, t2;
    u32 arg2;
    u32 matrixNum;
    u8 sinIndex;
    register s16 sinVal asm ("r4");
    register int sinVal2 asm ("r0");

    data = sprite->data;

    if (gBattleAnimArgs[7] & 0x100)
        slot = gBattleAnimAttacker;
    else
        slot = gBattleAnimTarget;

    if (GetBattlerSide(slot) == B_SIDE_PLAYER)
        gBattleAnimArgs[0] = -gBattleAnimArgs[0];

    sprite->pos1.x = GetBattlerSpriteCoord(slot, 0) + gBattleAnimArgs[0];
    spriteCoord = GetBattlerSpriteCoord(slot, 1);
    sprite->pos1.y = spriteCoord + gBattleAnimArgs[1];
    data[4] = sprite->pos1.y << 8;

    t1 = (spriteCoord + (u16) gBattleAnimArgs[6]) << 1;
    data[7] = (data[7] & 1) | t1;
    ((u8 *) data)[0] |= 4;

    arg2 = (u16) gBattleAnimArgs[2];
    data[1] = (u8) gBattleAnimArgs[2];
    arg2 <<= 16;
    data[5] = arg2 >> 24;
    data[2] = gBattleAnimArgs[3];
    data[3] = gBattleAnimArgs[4];
    data[6] = gBattleAnimArgs[5];

    if ((u16) (data[1] - 64) <= 0x7f)
    {
        if (!IsContest())
            sprite->oam.priority = GetBattlerSpriteBGPriority(slot) + 1;
        else
            sprite->oam.priority = GetBattlerSpriteBGPriority(slot);

        ((u8 *) data)[14] = data[7] & -2;

        if (!(data[2] & 0x8000))
        {
            sprite->hFlip ^= 1;
            sprite->animNum = sprite->hFlip;

            sprite->animBeginning = 1;
            sprite->animEnded = 0;
        }
    }
    else
    {
        sprite->oam.priority = GetBattlerSpriteBGPriority(slot);
        ((u8 *) data)[14] |= 1;

        if (data[2] & 0x8000)
        {
            sprite->hFlip ^= 1;
            sprite->animNum = sprite->hFlip;

            sprite->animBeginning = 1;
            sprite->animEnded = 0;
        }
    }

    t2 = (u16) data[1] >> 6 << 4;
    ((u8 *) data)[0] = (15 & data[0]) | t2;

    sprite->pos2.x = (gSineTable[(u16) data[1]] * (u8) data[6]) >> 8;

    matrixNum = sprite->oam.matrixNum;

    sinIndex = (-sprite->pos2.x >> 1) + data[5];
    sinVal = gSineTable[sinIndex];

    gOamMatrices[matrixNum].a = gOamMatrices[matrixNum].d = gSineTable[sinIndex + 64];
    gOamMatrices[matrixNum].b = sinVal;
    sinVal2 = -sinVal;
    gOamMatrices[matrixNum].c = sinVal2;

    sprite->callback = sub_810E520;
}
