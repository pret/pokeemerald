#include "global.h"
#include "battle_anim.h"
#include "palette.h"
#include "trig.h"
#include "constants/battle_anim.h"
#include "constants/rgb.h"
#include "random.h"

extern const struct SpriteTemplate gUnknown_085973E8;

void sub_810DE70(struct Sprite *);
void sub_810DFA8(struct Sprite *);
void sub_810E044(struct Sprite *);
void sub_810E13C(struct Sprite *);
void sub_810E1C8(struct Sprite *);
void sub_810E314(struct Sprite *);
void sub_810E520(struct Sprite *);
void sub_810EB40(struct Sprite *);
void sub_810EA4C(struct Sprite *);
void sub_810EAA0(struct Sprite *);
void sub_810EC34(struct Sprite *);
void sub_810EC94(struct Sprite *);
void sub_810ED28(struct Sprite *);
void sub_810ED70(struct Sprite *);
void sub_810EDD0(struct Sprite *);
void sub_810EE14(struct Sprite *);
void sub_810EEF8(struct Sprite *);
void sub_810EFA8(struct Sprite *);
void sub_810F004(struct Sprite *);
void sub_810F018(struct Sprite *);
void sub_810F084(struct Sprite *);
void sub_810F140(struct Sprite *);

static void sub_810DE98(struct Sprite *);
static void sub_810DF18(u8);
static void sub_810E028(struct Sprite *);
static void sub_810E184(struct Sprite *);
static void sub_810E24C(struct Sprite *);


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

static void sub_810DE98(struct Sprite *sprite)
{
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
        } while (i > 0);

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

    if (sprite->pos1.x + sprite->pos2.x < -32
        || sprite->pos1.x + sprite->pos2.x > 272
        || sprite->pos1.y + sprite->pos2.y > 160)
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

struct FeatherDanceData
{
    u8 unk0_0a:1;
    u8 unk0_0b:1;
    u8 unk0_0c:1;
    u8 unk0_0d:1;
    u8 unk0_1:4;
    u8 unk1;
    u16 unk2;
    s16 unk4;
    u16 unk6;
    u16 unk8;
    u16 unkA;
    u8 unkC[2];
    u16 unkE_0:1;
    u16 unkE_1:15;
};

void sub_810E314(struct Sprite *sprite)
{
    u8 battler, matrixNum, sinIndex;
    s16 spriteCoord, sinVal;

    struct FeatherDanceData *data = (struct FeatherDanceData *)sprite->data;

    if (gBattleAnimArgs[7] & 0x100)
        battler = gBattleAnimAttacker;
    else
        battler = gBattleAnimTarget;

    if (GetBattlerSide(battler) == B_SIDE_PLAYER)
        gBattleAnimArgs[0] = -gBattleAnimArgs[0];

    sprite->pos1.x = GetBattlerSpriteCoord(battler, BATTLER_COORD_ATTR_HEIGHT) + gBattleAnimArgs[0];
    spriteCoord = GetBattlerSpriteCoord(battler, BATTLER_COORD_ATTR_WIDTH);
    sprite->pos1.y = spriteCoord + gBattleAnimArgs[1];

    data->unk8 = sprite->pos1.y << 8;
    data->unkE_1 = spriteCoord + gBattleAnimArgs[6];
    data->unk0_0c = 1;
    data->unk2 = gBattleAnimArgs[2] & 0xFF;
    data->unkA = (gBattleAnimArgs[2] >> 8) & 0xFF;
    data->unk4 = gBattleAnimArgs[3];
    data->unk6 = gBattleAnimArgs[4];
    *(u16*)(data->unkC) = gBattleAnimArgs[5];

    if (data->unk2 >= 64 && data->unk2 <= 191)
    {
        if (!IsContest())
            sprite->oam.priority = GetBattlerSpriteBGPriority(battler) + 1;
        else
            sprite->oam.priority = GetBattlerSpriteBGPriority(battler);

        data->unkE_0 = 0;

        if (!(data->unk4 & 0x8000))
        {
            sprite->hFlip ^= 1;
            sprite->animNum = sprite->hFlip;

            sprite->animBeginning = 1;
            sprite->animEnded = 0;
        }
    }
    else
    {
        sprite->oam.priority = GetBattlerSpriteBGPriority(battler);
        data->unkE_0 = 1;

        if (data->unk4 & 0x8000)
        {
            sprite->hFlip ^= 1;
            sprite->animNum = sprite->hFlip;

            sprite->animBeginning = 1;
            sprite->animEnded = 0;
        }
    }

    data->unk0_1 = data->unk2 >> 6;
    sprite->pos2.x = (gSineTable[data->unk2] * data->unkC[0]) >> 8;
    matrixNum = sprite->oam.matrixNum;

    sinIndex = (-sprite->pos2.x >> 1) + data->unkA;
    sinVal = gSineTable[sinIndex];

    gOamMatrices[matrixNum].a = gOamMatrices[matrixNum].d = gSineTable[sinIndex + 64];
    // The comparison below is completely pointless. 'sprite' is sure to be a valid pointer and
    // both the 'if' and 'else' parts are exactly the same.
    // The only reason for this is making sure the compiler generates the exact ASM.
    if (sprite)
    {
        gOamMatrices[matrixNum].b = sinVal;
        gOamMatrices[matrixNum].c = -sinVal;
    }
    else
    {
        gOamMatrices[matrixNum].b = sinVal;
        gOamMatrices[matrixNum].c = -sinVal;
    }

    sprite->callback = sub_810E520;
}

#ifdef NONMATCHING
/*
Things I can't get to match:
1. data->unk0_1 bitfield behaviour. The way bits are read is different.
2. sprite->oam.priority--; sprite->oam.priority++; Nonmatching version tail-merges these, original does not.
3. sprite->pos2.x = (gSineTable[data->unk2] * var) >> 8; data->unk2 is very weirdly read at seemingly random moments inside the switch.
4. sinVal r6/r7 mismatch.
*/
void sub_810E520(struct Sprite *sprite)
{
    u8 matrixNum, sinIndex, var;
    s16 sinVal = 0;
    struct FeatherDanceData *data = (struct FeatherDanceData *)sprite->data;

    if (data->unk0_0a)
    {
        if (data->unk1-- % 256 == 0)
        {
            data->unk0_0a = 0;
            data->unk1 = 0;
        }
    }
    else
    {
        switch (data->unk2 >> 6)
        {
        case 0:
            if (data->unk0_1 == 1)
            {
                data->unk0_0d = 1;
                data->unk0_0a = 1;
                data->unk1 = 0;
            }
            else if (data->unk0_1 == 3)
            {
                data->unk0_0b ^= 1;
                data->unk1 = 0;
            }
            else if (data->unk0_0d)
            {
                sprite->hFlip ^= 1;
                sprite->animNum = sprite->hFlip;
                sprite->animBeginning = 1;
                sprite->animEnded = 0;
                if (data->unk0_0c)
                {
                    if (!IsContest())
                    {
                        if (!data->unkE_0)
                            sprite->oam.priority--;
                        else
                            sprite->oam.priority++;
                    }
                    else
                    {
                        if (!data->unkE_0)
                            sprite->subpriority -= 12;
                        else
                            sprite->subpriority += 12;
                    }
                    data->unkE_0 ^= 1;
                }
                data->unk0_0d = 0;
            }
            data->unk0_1 = 0;
            break;
        case 1:
            if (data->unk0_1 == 0)
            {
                data->unk0_0d = 1;
                data->unk0_0a = 1;
                data->unk1 = 0;
            }
            else if (data->unk0_1 == 2)
            {
                data->unk0_0a = 1;
                data->unk1 = 0;
            }
            else if (data->unk0_0d)
            {
                sprite->hFlip ^= 1;
                sprite->animNum = sprite->hFlip;
                sprite->animBeginning = 1;
                sprite->animEnded = 0;
                if (data->unk0_0c)
                {
                    if (!IsContest())
                    {
                        if (!data->unkE_0)
                            sprite->oam.priority--;
                        else
                            sprite->oam.priority++;
                    }
                    else
                    {
                        if (!data->unkE_0)
                            sprite->subpriority -= 12;
                        else
                            sprite->subpriority += 12;
                    }
                    data->unkE_0 ^= 1;
                }
                data->unk0_0d = 0;
            }
            data->unk0_1 = 1;
            break;
        case 2:
            if (data->unk0_1 == 0)
            {
                data->unk0_0d = 1;
                data->unk0_0a = 1;
                data->unk1 = 0;
            }
            else if (data->unk0_1 == 2)
            {
                data->unk0_0a = 1;
                data->unk1 = 0;
            }
            else if (data->unk0_0d)
            {
                sprite->hFlip ^= 1;
                sprite->animNum = sprite->hFlip;
                sprite->animBeginning = 1;
                sprite->animEnded = 0;
                if (data->unk0_0c)
                {
                    if (!IsContest())
                    {
                        if (!data->unkE_0)
                            sprite->oam.priority--;
                        else
                            sprite->oam.priority++;
                    }
                    else
                    {
                        if (!data->unkE_0)
                            sprite->subpriority -= 12;
                        else
                            sprite->subpriority += 12;
                    }
                    data->unkE_0 ^= 1;
                }
                data->unk0_0d = 0;
            }
            data->unk0_1 = 2;
            break;
        case 3:
            if (data->unk0_1 == 2)
            {
                data->unk0_0d = 1;
            }
            else if (data->unk0_1 == 0)
            {
                data->unk0_0b ^= 1;
                data->unk1 = 0;
            }
            else if (data->unk0_0d)
            {
                sprite->hFlip ^= 1;
                sprite->animNum = sprite->hFlip;
                sprite->animBeginning = 1;
                sprite->animEnded = 0;
                if (data->unk0_0c)
                {
                    if (!IsContest())
                    {
                        if (!data->unkE_0)
                            sprite->oam.priority--;
                        else
                            sprite->oam.priority++;
                    }
                    else
                    {
                        if (!data->unkE_0)
                            sprite->subpriority -= 12;
                        else
                            sprite->subpriority += 12;
                    }
                    data->unkE_0 ^= 1;
                }
                data->unk0_0d = 0;
            }
            data->unk0_1 = 3;
            break;
        }

        var = data->unkC[data->unk0_0b];
        sprite->pos2.x = (gSineTable[data->unk2] * var) >> 8;
        matrixNum = sprite->oam.matrixNum;

        sinIndex = (-sprite->pos2.x >> 1) + data->unkA;
        sinVal = gSineTable[sinIndex];

        gOamMatrices[matrixNum].a = gOamMatrices[matrixNum].d = gSineTable[sinIndex + 64];
        gOamMatrices[matrixNum].b = sinVal;
        gOamMatrices[matrixNum].c = -sinVal;

        data->unk8 += data->unk6;
        sprite->pos1.y = data->unk8 >> 8;
        if (data->unk4 & 0x8000)
            data->unk2 = (data->unk2 - (data->unk4 & 0x7FFF)) & 0xFF;
        else
            data->unk2 = (data->unk2 + (data->unk4 & 0x7FFF)) & 0xFF;

        if (sprite->pos1.y + sprite->pos2.y > data->unkE_1)
        {
            sprite->data[0] = 0;
            sprite->callback = sub_810E2C8;
        }
    }
}
#else
NAKED
void sub_810E520(struct Sprite *sprite)
{
    asm_unified("push {r4-r7,lr}\n\
    mov r7, r9\n\
    mov r6, r8\n\
    push {r6,r7}\n\
    adds r5, r0, 0\n\
    movs r6, 0\n\
    adds r4, r5, 0\n\
    adds r4, 0x2E\n\
    ldrb r2, [r4]\n\
    movs r7, 0x1\n\
    movs r0, 0x1\n\
    mov r9, r0\n\
    ands r0, r2\n\
    cmp r0, 0\n\
    beq _0810E55A\n\
    ldrb r0, [r4, 0x1]\n\
    adds r1, r0, 0\n\
    adds r1, 0xFF\n\
    strb r1, [r4, 0x1]\n\
    lsls r0, 24\n\
    cmp r0, 0\n\
    beq _0810E54E\n\
    b _0810EA36\n\
_0810E54E:\n\
    movs r0, 0x2\n\
    negs r0, r0\n\
    ands r0, r2\n\
    strb r0, [r4]\n\
    strb r6, [r4, 0x1]\n\
    b _0810EA36\n\
_0810E55A:\n\
    ldrh r0, [r4, 0x2]\n\
    lsrs r1, r0, 6\n\
    mov r12, r0\n\
    cmp r1, 0x1\n\
    bne _0810E566\n\
    b _0810E68A\n\
_0810E566:\n\
    cmp r1, 0x1\n\
    bgt _0810E570\n\
    cmp r1, 0\n\
    beq _0810E57E\n\
    b _0810E97C\n\
_0810E570:\n\
    cmp r1, 0x2\n\
    bne _0810E576\n\
    b _0810E77E\n\
_0810E576:\n\
    cmp r1, 0x3\n\
    bne _0810E57C\n\
    b _0810E872\n\
_0810E57C:\n\
    b _0810E97C\n\
_0810E57E:\n\
    lsls r1, r2, 24\n\
    lsrs r0, r1, 28\n\
    cmp r0, 0x1\n\
    bne _0810E592\n\
    movs r0, 0x8\n\
    orrs r0, r2\n\
    orrs r0, r7\n\
    strb r0, [r4]\n\
    strb r6, [r4, 0x1]\n\
    b _0810E680\n\
_0810E592:\n\
    lsrs r0, r1, 28\n\
    cmp r0, 0x3\n\
    bne _0810E5B4\n\
    lsls r0, r2, 30\n\
    lsrs r0, 31\n\
    movs r1, 0x1\n\
    eors r0, r1\n\
    ands r0, r7\n\
    lsls r0, 1\n\
    movs r1, 0x3\n\
    negs r1, r1\n\
    ands r1, r2\n\
    orrs r1, r0\n\
    orrs r1, r7\n\
    strb r1, [r4]\n\
    strb r6, [r4, 0x1]\n\
    b _0810E680\n\
_0810E5B4:\n\
    movs r0, 0x8\n\
    ands r0, r2\n\
    cmp r0, 0\n\
    beq _0810E680\n\
    adds r3, r5, 0\n\
    adds r3, 0x3F\n\
    ldrb r2, [r3]\n\
    lsls r1, r2, 31\n\
    lsrs r1, 31\n\
    movs r6, 0x1\n\
    eors r1, r6\n\
    ands r1, r7\n\
    movs r0, 0x2\n\
    negs r0, r0\n\
    mov r8, r0\n\
    ands r0, r2\n\
    orrs r0, r1\n\
    strb r0, [r3]\n\
    lsls r0, 31\n\
    lsrs r0, 31\n\
    adds r1, r5, 0\n\
    adds r1, 0x2A\n\
    strb r0, [r1]\n\
    ldrb r0, [r3]\n\
    movs r1, 0x4\n\
    orrs r0, r1\n\
    movs r1, 0x11\n\
    negs r1, r1\n\
    ands r0, r1\n\
    strb r0, [r3]\n\
    ldrb r1, [r4]\n\
    movs r0, 0x4\n\
    ands r0, r1\n\
    cmp r0, 0\n\
    beq _0810E672\n\
    bl IsContest\n\
    lsls r0, 24\n\
    cmp r0, 0\n\
    bne _0810E642\n\
    ldrb r1, [r4, 0xE]\n\
    mov r0, r9\n\
    ands r0, r1\n\
    cmp r0, 0\n\
    bne _0810E628\n\
    ldrb r2, [r5, 0x5]\n\
    lsls r1, r2, 28\n\
    lsrs r1, 30\n\
    subs r1, 0x1\n\
    movs r0, 0x3\n\
    ands r1, r0\n\
    lsls r1, 2\n\
    movs r0, 0xD\n\
    negs r0, r0\n\
    ands r0, r2\n\
    orrs r0, r1\n\
    strb r0, [r5, 0x5]\n\
    b _0810E660\n\
_0810E628:\n\
    ldrb r2, [r5, 0x5]\n\
    lsls r1, r2, 28\n\
    lsrs r1, 30\n\
    adds r1, 0x1\n\
    movs r0, 0x3\n\
    ands r1, r0\n\
    lsls r1, 2\n\
    movs r0, 0xD\n\
    negs r0, r0\n\
    ands r0, r2\n\
    orrs r0, r1\n\
    strb r0, [r5, 0x5]\n\
    b _0810E660\n\
_0810E642:\n\
    ldrb r1, [r4, 0xE]\n\
    mov r0, r9\n\
    ands r0, r1\n\
    cmp r0, 0\n\
    bne _0810E656\n\
    adds r1, r5, 0\n\
    adds r1, 0x43\n\
    ldrb r0, [r1]\n\
    subs r0, 0xC\n\
    b _0810E65E\n\
_0810E656:\n\
    adds r1, r5, 0\n\
    adds r1, 0x43\n\
    ldrb r0, [r1]\n\
    adds r0, 0xC\n\
_0810E65E:\n\
    strb r0, [r1]\n\
_0810E660:\n\
    ldrb r2, [r4, 0xE]\n\
    lsls r0, r2, 31\n\
    lsrs r0, 31\n\
    eors r0, r6\n\
    ands r0, r7\n\
    mov r1, r8\n\
    ands r1, r2\n\
    orrs r1, r0\n\
    strb r1, [r4, 0xE]\n\
_0810E672:\n\
    ldrb r1, [r4]\n\
    movs r0, 0x9\n\
    negs r0, r0\n\
    ands r0, r1\n\
    strb r0, [r4]\n\
    ldrh r1, [r4, 0x2]\n\
    mov r12, r1\n\
_0810E680:\n\
    ldrb r1, [r4]\n\
    movs r0, 0xF\n\
    ands r0, r1\n\
    strb r0, [r4]\n\
    b _0810E97C\n\
_0810E68A:\n\
    lsls r1, r2, 24\n\
    lsrs r0, r1, 28\n\
    cmp r0, 0\n\
    bne _0810E698\n\
    movs r0, 0x8\n\
    orrs r0, r2\n\
    b _0810E6A0\n\
_0810E698:\n\
    lsrs r0, r1, 28\n\
    cmp r0, 0x2\n\
    bne _0810E6A8\n\
    adds r0, r2, 0\n\
_0810E6A0:\n\
    orrs r0, r7\n\
    strb r0, [r4]\n\
    strb r6, [r4, 0x1]\n\
    b _0810E774\n\
_0810E6A8:\n\
    movs r0, 0x8\n\
    ands r0, r2\n\
    cmp r0, 0\n\
    beq _0810E774\n\
    adds r3, r5, 0\n\
    adds r3, 0x3F\n\
    ldrb r2, [r3]\n\
    lsls r1, r2, 31\n\
    lsrs r1, 31\n\
    movs r6, 0x1\n\
    eors r1, r6\n\
    ands r1, r7\n\
    movs r0, 0x2\n\
    negs r0, r0\n\
    mov r8, r0\n\
    ands r0, r2\n\
    orrs r0, r1\n\
    strb r0, [r3]\n\
    lsls r0, 31\n\
    lsrs r0, 31\n\
    adds r1, r5, 0\n\
    adds r1, 0x2A\n\
    strb r0, [r1]\n\
    ldrb r0, [r3]\n\
    movs r1, 0x4\n\
    orrs r0, r1\n\
    movs r1, 0x11\n\
    negs r1, r1\n\
    ands r0, r1\n\
    strb r0, [r3]\n\
    ldrb r1, [r4]\n\
    movs r0, 0x4\n\
    ands r0, r1\n\
    cmp r0, 0\n\
    beq _0810E766\n\
    bl IsContest\n\
    lsls r0, 24\n\
    cmp r0, 0\n\
    bne _0810E736\n\
    ldrb r1, [r4, 0xE]\n\
    mov r0, r9\n\
    ands r0, r1\n\
    cmp r0, 0\n\
    bne _0810E71C\n\
    ldrb r2, [r5, 0x5]\n\
    lsls r1, r2, 28\n\
    lsrs r1, 30\n\
    subs r1, 0x1\n\
    movs r0, 0x3\n\
    ands r1, r0\n\
    lsls r1, 2\n\
    movs r0, 0xD\n\
    negs r0, r0\n\
    ands r0, r2\n\
    orrs r0, r1\n\
    strb r0, [r5, 0x5]\n\
    b _0810E754\n\
_0810E71C:\n\
    ldrb r2, [r5, 0x5]\n\
    lsls r1, r2, 28\n\
    lsrs r1, 30\n\
    adds r1, 0x1\n\
    movs r0, 0x3\n\
    ands r1, r0\n\
    lsls r1, 2\n\
    movs r0, 0xD\n\
    negs r0, r0\n\
    ands r0, r2\n\
    orrs r0, r1\n\
    strb r0, [r5, 0x5]\n\
    b _0810E754\n\
_0810E736:\n\
    ldrb r1, [r4, 0xE]\n\
    mov r0, r9\n\
    ands r0, r1\n\
    cmp r0, 0\n\
    bne _0810E74A\n\
    adds r1, r5, 0\n\
    adds r1, 0x43\n\
    ldrb r0, [r1]\n\
    subs r0, 0xC\n\
    b _0810E752\n\
_0810E74A:\n\
    adds r1, r5, 0\n\
    adds r1, 0x43\n\
    ldrb r0, [r1]\n\
    adds r0, 0xC\n\
_0810E752:\n\
    strb r0, [r1]\n\
_0810E754:\n\
    ldrb r2, [r4, 0xE]\n\
    lsls r0, r2, 31\n\
    lsrs r0, 31\n\
    eors r0, r6\n\
    ands r0, r7\n\
    mov r1, r8\n\
    ands r1, r2\n\
    orrs r1, r0\n\
    strb r1, [r4, 0xE]\n\
_0810E766:\n\
    ldrb r1, [r4]\n\
    movs r0, 0x9\n\
    negs r0, r0\n\
    ands r0, r1\n\
    strb r0, [r4]\n\
    ldrh r1, [r4, 0x2]\n\
    mov r12, r1\n\
_0810E774:\n\
    ldrb r0, [r4]\n\
    movs r1, 0xF\n\
    ands r1, r0\n\
    movs r0, 0x10\n\
    b _0810E978\n\
_0810E77E:\n\
    lsls r1, r2, 24\n\
    lsrs r0, r1, 28\n\
    cmp r0, 0x3\n\
    bne _0810E78C\n\
    movs r0, 0x8\n\
    orrs r0, r2\n\
    b _0810E794\n\
_0810E78C:\n\
    lsrs r0, r1, 28\n\
    cmp r0, 0x1\n\
    bne _0810E79C\n\
    adds r0, r2, 0\n\
_0810E794:\n\
    orrs r0, r7\n\
    strb r0, [r4]\n\
    strb r6, [r4, 0x1]\n\
    b _0810E868\n\
_0810E79C:\n\
    movs r0, 0x8\n\
    ands r0, r2\n\
    cmp r0, 0\n\
    beq _0810E868\n\
    adds r3, r5, 0\n\
    adds r3, 0x3F\n\
    ldrb r2, [r3]\n\
    lsls r1, r2, 31\n\
    lsrs r1, 31\n\
    movs r6, 0x1\n\
    eors r1, r6\n\
    ands r1, r7\n\
    movs r0, 0x2\n\
    negs r0, r0\n\
    mov r8, r0\n\
    ands r0, r2\n\
    orrs r0, r1\n\
    strb r0, [r3]\n\
    lsls r0, 31\n\
    lsrs r0, 31\n\
    adds r1, r5, 0\n\
    adds r1, 0x2A\n\
    strb r0, [r1]\n\
    ldrb r0, [r3]\n\
    movs r1, 0x4\n\
    orrs r0, r1\n\
    movs r1, 0x11\n\
    negs r1, r1\n\
    ands r0, r1\n\
    strb r0, [r3]\n\
    ldrb r1, [r4]\n\
    movs r0, 0x4\n\
    ands r0, r1\n\
    cmp r0, 0\n\
    beq _0810E85A\n\
    bl IsContest\n\
    lsls r0, 24\n\
    cmp r0, 0\n\
    bne _0810E82A\n\
    ldrb r1, [r4, 0xE]\n\
    mov r0, r9\n\
    ands r0, r1\n\
    cmp r0, 0\n\
    bne _0810E810\n\
    ldrb r2, [r5, 0x5]\n\
    lsls r1, r2, 28\n\
    lsrs r1, 30\n\
    subs r1, 0x1\n\
    movs r0, 0x3\n\
    ands r1, r0\n\
    lsls r1, 2\n\
    movs r0, 0xD\n\
    negs r0, r0\n\
    ands r0, r2\n\
    orrs r0, r1\n\
    strb r0, [r5, 0x5]\n\
    b _0810E848\n\
_0810E810:\n\
    ldrb r2, [r5, 0x5]\n\
    lsls r1, r2, 28\n\
    lsrs r1, 30\n\
    adds r1, 0x1\n\
    movs r0, 0x3\n\
    ands r1, r0\n\
    lsls r1, 2\n\
    movs r0, 0xD\n\
    negs r0, r0\n\
    ands r0, r2\n\
    orrs r0, r1\n\
    strb r0, [r5, 0x5]\n\
    b _0810E848\n\
_0810E82A:\n\
    ldrb r1, [r4, 0xE]\n\
    mov r0, r9\n\
    ands r0, r1\n\
    cmp r0, 0\n\
    bne _0810E83E\n\
    adds r1, r5, 0\n\
    adds r1, 0x43\n\
    ldrb r0, [r1]\n\
    subs r0, 0xC\n\
    b _0810E846\n\
_0810E83E:\n\
    adds r1, r5, 0\n\
    adds r1, 0x43\n\
    ldrb r0, [r1]\n\
    adds r0, 0xC\n\
_0810E846:\n\
    strb r0, [r1]\n\
_0810E848:\n\
    ldrb r2, [r4, 0xE]\n\
    lsls r0, r2, 31\n\
    lsrs r0, 31\n\
    eors r0, r6\n\
    ands r0, r7\n\
    mov r1, r8\n\
    ands r1, r2\n\
    orrs r1, r0\n\
    strb r1, [r4, 0xE]\n\
_0810E85A:\n\
    ldrb r1, [r4]\n\
    movs r0, 0x9\n\
    negs r0, r0\n\
    ands r0, r1\n\
    strb r0, [r4]\n\
    ldrh r1, [r4, 0x2]\n\
    mov r12, r1\n\
_0810E868:\n\
    ldrb r0, [r4]\n\
    movs r1, 0xF\n\
    ands r1, r0\n\
    movs r0, 0x20\n\
    b _0810E978\n\
_0810E872:\n\
    lsls r1, r2, 24\n\
    lsrs r0, r1, 28\n\
    cmp r0, 0x2\n\
    bne _0810E882\n\
    movs r0, 0x8\n\
    orrs r0, r2\n\
    strb r0, [r4]\n\
    b _0810E970\n\
_0810E882:\n\
    lsrs r0, r1, 28\n\
    cmp r0, 0\n\
    bne _0810E8A4\n\
    lsls r0, r2, 30\n\
    lsrs r0, 31\n\
    movs r1, 0x1\n\
    eors r0, r1\n\
    ands r0, r7\n\
    lsls r0, 1\n\
    movs r1, 0x3\n\
    negs r1, r1\n\
    ands r1, r2\n\
    orrs r1, r0\n\
    orrs r1, r7\n\
    strb r1, [r4]\n\
    strb r6, [r4, 0x1]\n\
    b _0810E970\n\
_0810E8A4:\n\
    movs r0, 0x8\n\
    ands r0, r2\n\
    cmp r0, 0\n\
    beq _0810E970\n\
    adds r3, r5, 0\n\
    adds r3, 0x3F\n\
    ldrb r2, [r3]\n\
    lsls r1, r2, 31\n\
    lsrs r1, 31\n\
    movs r6, 0x1\n\
    eors r1, r6\n\
    ands r1, r7\n\
    movs r0, 0x2\n\
    negs r0, r0\n\
    mov r8, r0\n\
    ands r0, r2\n\
    orrs r0, r1\n\
    strb r0, [r3]\n\
    lsls r0, 31\n\
    lsrs r0, 31\n\
    adds r1, r5, 0\n\
    adds r1, 0x2A\n\
    strb r0, [r1]\n\
    ldrb r0, [r3]\n\
    movs r1, 0x4\n\
    orrs r0, r1\n\
    movs r1, 0x11\n\
    negs r1, r1\n\
    ands r0, r1\n\
    strb r0, [r3]\n\
    ldrb r1, [r4]\n\
    movs r0, 0x4\n\
    ands r0, r1\n\
    cmp r0, 0\n\
    beq _0810E962\n\
    bl IsContest\n\
    lsls r0, 24\n\
    cmp r0, 0\n\
    bne _0810E932\n\
    ldrb r1, [r4, 0xE]\n\
    mov r0, r9\n\
    ands r0, r1\n\
    cmp r0, 0\n\
    bne _0810E918\n\
    ldrb r2, [r5, 0x5]\n\
    lsls r1, r2, 28\n\
    lsrs r1, 30\n\
    subs r1, 0x1\n\
    movs r0, 0x3\n\
    ands r1, r0\n\
    lsls r1, 2\n\
    movs r0, 0xD\n\
    negs r0, r0\n\
    ands r0, r2\n\
    orrs r0, r1\n\
    strb r0, [r5, 0x5]\n\
    b _0810E950\n\
_0810E918:\n\
    ldrb r2, [r5, 0x5]\n\
    lsls r1, r2, 28\n\
    lsrs r1, 30\n\
    adds r1, 0x1\n\
    movs r0, 0x3\n\
    ands r1, r0\n\
    lsls r1, 2\n\
    movs r0, 0xD\n\
    negs r0, r0\n\
    ands r0, r2\n\
    orrs r0, r1\n\
    strb r0, [r5, 0x5]\n\
    b _0810E950\n\
_0810E932:\n\
    ldrb r1, [r4, 0xE]\n\
    mov r0, r9\n\
    ands r0, r1\n\
    cmp r0, 0\n\
    bne _0810E946\n\
    adds r1, r5, 0\n\
    adds r1, 0x43\n\
    ldrb r0, [r1]\n\
    subs r0, 0xC\n\
    b _0810E94E\n\
_0810E946:\n\
    adds r1, r5, 0\n\
    adds r1, 0x43\n\
    ldrb r0, [r1]\n\
    adds r0, 0xC\n\
_0810E94E:\n\
    strb r0, [r1]\n\
_0810E950:\n\
    ldrb r2, [r4, 0xE]\n\
    lsls r0, r2, 31\n\
    lsrs r0, 31\n\
    eors r0, r6\n\
    ands r0, r7\n\
    mov r1, r8\n\
    ands r1, r2\n\
    orrs r1, r0\n\
    strb r1, [r4, 0xE]\n\
_0810E962:\n\
    ldrb r1, [r4]\n\
    movs r0, 0x9\n\
    negs r0, r0\n\
    ands r0, r1\n\
    strb r0, [r4]\n\
    ldrh r1, [r4, 0x2]\n\
    mov r12, r1\n\
_0810E970:\n\
    ldrb r0, [r4]\n\
    movs r1, 0xF\n\
    ands r1, r0\n\
    movs r0, 0x30\n\
_0810E978:\n\
    orrs r1, r0\n\
    strb r1, [r4]\n\
_0810E97C:\n\
    ldrb r1, [r4]\n\
    lsls r1, 30\n\
    lsrs r1, 31\n\
    adds r0, r4, 0\n\
    adds r0, 0xC\n\
    adds r0, r1\n\
    ldrb r1, [r0]\n\
    ldr r3, =gSineTable\n\
    mov r2, r12\n\
    lsls r0, r2, 1\n\
    adds r0, r3\n\
    movs r2, 0\n\
    ldrsh r0, [r0, r2]\n\
    muls r0, r1\n\
    asrs r0, 8\n\
    strh r0, [r5, 0x24]\n\
    ldrb r2, [r5, 0x3]\n\
    lsls r2, 26\n\
    lsrs r2, 27\n\
    movs r1, 0x24\n\
    ldrsh r0, [r5, r1]\n\
    negs r0, r0\n\
    asrs r0, 1\n\
    ldrb r1, [r4, 0xA]\n\
    adds r0, r1\n\
    lsls r0, 24\n\
    lsrs r0, 24\n\
    lsls r1, r0, 1\n\
    adds r1, r3\n\
    ldrh r6, [r1]\n\
    ldr r1, =gOamMatrices\n\
    lsls r2, 3\n\
    adds r2, r1\n\
    adds r0, 0x40\n\
    lsls r0, 1\n\
    adds r0, r3\n\
    ldrh r0, [r0]\n\
    strh r0, [r2, 0x6]\n\
    strh r0, [r2]\n\
    strh r6, [r2, 0x2]\n\
    lsls r0, r6, 16\n\
    asrs r0, 16\n\
    negs r0, r0\n\
    strh r0, [r2, 0x4]\n\
    ldrh r0, [r4, 0x6]\n\
    ldrh r2, [r4, 0x8]\n\
    adds r0, r2\n\
    strh r0, [r4, 0x8]\n\
    lsls r0, 16\n\
    lsrs r0, 24\n\
    strh r0, [r5, 0x22]\n\
    movs r1, 0x4\n\
    ldrsh r0, [r4, r1]\n\
    movs r1, 0x80\n\
    lsls r1, 8\n\
    ands r0, r1\n\
    cmp r0, 0\n\
    beq _0810EA0C\n\
    ldrh r0, [r4, 0x4]\n\
    subs r1, 0x1\n\
    ands r1, r0\n\
    ldrh r0, [r4, 0x2]\n\
    subs r0, r1\n\
    movs r1, 0xFF\n\
    ands r0, r1\n\
    strh r0, [r4, 0x2]\n\
    b _0810EA1C\n\
    .pool\n\
_0810EA0C:\n\
    ldrh r0, [r4, 0x4]\n\
    ldr r1, =0x00007fff\n\
    ands r1, r0\n\
    ldrh r2, [r4, 0x2]\n\
    adds r1, r2\n\
    movs r0, 0xFF\n\
    ands r1, r0\n\
    strh r1, [r4, 0x2]\n\
_0810EA1C:\n\
    movs r0, 0x22\n\
    ldrsh r1, [r5, r0]\n\
    movs r2, 0x26\n\
    ldrsh r0, [r5, r2]\n\
    adds r1, r0\n\
    ldrh r0, [r4, 0xE]\n\
    lsrs r0, 1\n\
    cmp r1, r0\n\
    blt _0810EA36\n\
    movs r0, 0\n\
    strh r0, [r5, 0x2E]\n\
    ldr r0, =sub_810E2C8\n\
    str r0, [r5, 0x1C]\n\
_0810EA36:\n\
    pop {r3,r4}\n\
    mov r8, r3\n\
    mov r9, r4\n\
    pop {r4-r7}\n\
    pop {r0}\n\
    bx r0\n\
    .pool\n\
    ");
}
#endif

void sub_810EA4C(struct Sprite *sprite)
{
    sprite->oam.priority = GetBattlerSpriteBGPriority(gBattleAnimTarget);
    sprite->pos1.x = GetBattlerSpriteCoord(gBattleAnimAttacker, 2);
    sprite->pos1.y = GetBattlerSpriteCoord(gBattleAnimAttacker, 3);
    sprite->callback = TranslateAnimSpriteToTargetMonLocation;
}

void sub_810EAA0(struct Sprite * sprite)
{
    u16 arg;
    u8 mult;

    if (!gBattleAnimArgs[2])
        InitSpritePosToAnimAttacker(sprite, 0);
    else
        InitSpritePosToAnimTarget(sprite, FALSE);

    if ((!gBattleAnimArgs[2] && !GetBattlerSide(gBattleAnimAttacker))
        || (gBattleAnimArgs[2] == 1 && !GetBattlerSide(gBattleAnimTarget)))
    {
        sprite->pos1.x += 8;
    }

    SeekSpriteAnim(sprite, gBattleAnimArgs[4]);
    sprite->pos1.x -= 32;
    sprite->data[1] = 0x0ccc;

    arg = gBattleAnimArgs[4];
    mult = 12;
    sprite->pos2.x += mult * arg;
    sprite->data[0] = arg;
    sprite->data[7] = gBattleAnimArgs[3];
    sprite->callback = sub_810EB40;
}

void sub_810EB40(struct Sprite *sprite)
{
    sprite->pos2.x += sprite->data[1] >> 8;

    if (++sprite->data[0] == 6)
    {
        sprite->data[0] = 0;
        sprite->pos2.x = 0;
        StartSpriteAnim(sprite, 0);
    }

    if (--sprite->data[7] == -1)
        DestroyAnimSprite(sprite);
}

void sub_810EB88(u8 task)
{
    if (!(gTasks[task].data[0] % 32))
    {
        gAnimVisualTaskCount++;

        gBattleAnimArgs[0] = Sin(gTasks[task].data[0], -13);
        gBattleAnimArgs[1] = Cos(gTasks[task].data[0], -13);
        gBattleAnimArgs[2] = 1;
        gBattleAnimArgs[3] = 3;

        CreateSpriteAndAnimate(&gUnknown_085973E8,
                               GetBattlerSpriteCoord(gBattleAnimTarget, 2),
                               GetBattlerSpriteCoord(gBattleAnimTarget, 3),
                               3);
    }

    gTasks[task].data[0] += 8;

    if (gTasks[task].data[0] > 255)
        DestroyAnimVisualTask(task);
}

void sub_810EC34(struct Sprite *sprite)
{
    switch (sprite->data[0])
    {
    case 0:
        InitSpritePosToAnimAttacker(sprite, 1);
        gSprites[GetAnimBattlerSpriteId(0)].invisible = 1;
        ++sprite->data[0];
        break;
    case 1:
        if (sprite->affineAnimEnded)
            DestroyAnimSprite(sprite);
        break;
    }
}

void sub_810EC94(struct Sprite *sprite)
{
    switch (sprite->data[0])
    {
    case 0:
        sprite->pos1.y = GetBattlerSpriteCoord(gBattleAnimTarget, 1);
        sprite->pos2.y = -sprite->pos1.y - 32;
        sprite->data[0]++;
        break;
    case 1:
        sprite->pos2.y += 10;
        if (sprite->pos2.y >= 0)
            ++sprite->data[0];
        break;
    case 2:
        sprite->pos2.y -= 10;
        if (sprite->pos1.y + sprite->pos2.y < -32)
        {
            gSprites[GetAnimBattlerSpriteId(0)].invisible = 0;
            DestroyAnimSprite(sprite);
        }
        break;
    }
}

void sub_810ED28(struct Sprite *sprite)
{
    InitSpritePosToAnimAttacker(sprite, 1);
    sprite->data[0] = gBattleAnimArgs[2];
    sprite->data[1] = gBattleAnimArgs[3];
    sprite->callback = sub_810ED70;
    gSprites[GetAnimBattlerSpriteId(0)].invisible = 1;
}

void sub_810ED70(struct Sprite *sprite)
{
    if (sprite->data[0] > 0)
    {
        sprite->data[0]--;
    }
    else if (sprite->pos1.y + sprite->pos2.y > -32)
    {
        sprite->data[2] += sprite->data[1];
        sprite->pos2.y -= (sprite->data[2] >> 8);
    }
    else
    {
        sprite->invisible = 1;
        if (sprite->data[3]++ > 20)
            sprite->callback = sub_810EDD0;
    }
}

void sub_810EDD0(struct Sprite *sprite)
{
    sprite->pos2.y += sprite->data[2] >> 8;

    if (sprite->pos1.y + sprite->pos2.y > -32)
        sprite->invisible = 0;

    if (sprite->pos2.y > 0)
        DestroyAnimSprite(sprite);
}

void sub_810EE14(struct Sprite *sprite)
{
    u32 matrixNum;
    int t1, t2;

    switch (sprite->data[0])
    {
    case 0:
        if (!gBattleAnimArgs[0])
        {
            sprite->pos1.x = GetBattlerSpriteCoord(gBattleAnimAttacker, 0);
            sprite->pos1.y = GetBattlerSpriteCoord(gBattleAnimAttacker, 1);
        }
        else
        {
            sprite->pos1.x = GetBattlerSpriteCoord(gBattleAnimTarget, 0);
            sprite->pos1.y = GetBattlerSpriteCoord(gBattleAnimTarget, 1);
        }

        sprite->data[1] = 512;

        TrySetSpriteRotScale(sprite, 0, 256, sprite->data[1], 0);
        sprite->data[0]++;
        break;
    case 1:
        if (sprite->data[2] <= 11)
            sprite->data[1] -= 40;
        else
            sprite->data[1] += 40;

        sprite->data[2]++;

        TrySetSpriteRotScale(sprite, 0, 256, sprite->data[1], 0);

        matrixNum = sprite->oam.matrixNum;

        t1 = 15616;
        t2 = t1 / gOamMatrices[matrixNum].d + 1;

        if (t2 > 128)
            t2 = 128;

        t2 = (64 - t2) / 2;
        sprite->pos2.y = t2;

        if (sprite->data[2] == 24)
        {
            sub_80A749C(sprite);
            DestroyAnimSprite(sprite);
        }
        break;
    }
}

void sub_810EEF8(struct Sprite *sprite)
{
    int v1 = 0x1ff & Random2();
    int v2 = 0x7f & Random2();

    if (v1 % 2)
        sprite->data[0] = 736 + v1;
    else
        sprite->data[0] = 736 - v1;

    if (v2 % 2)
        sprite->data[1] = 896 + v2;
    else
        sprite->data[1] = 896 - v2;

    sprite->data[2] = gBattleAnimArgs[0];

    if (sprite->data[2])
        sprite->oam.matrixNum = 8;

    if (gBattleAnimArgs[1] == 0)
    {
        sprite->pos1.x = GetBattlerSpriteCoord(gBattleAnimAttacker, 0);
        sprite->pos1.y = GetBattlerSpriteCoord(gBattleAnimAttacker, 1) + 32;
    }
    else
    {
        sprite->pos1.x = GetBattlerSpriteCoord(gBattleAnimTarget, 0);
        sprite->pos1.y = GetBattlerSpriteCoord(gBattleAnimTarget, 1) + 32;
    }

    sprite->callback = sub_810EFA8;
}

void sub_810EFA8(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        sprite->pos2.x += sprite->data[0] >> 8;
        sprite->pos2.y -= sprite->data[1] >> 8;
    }
    else
    {
        sprite->pos2.x -= sprite->data[0] >> 8;
        sprite->pos2.y -= sprite->data[1] >> 8;
    }

    sprite->data[0] = sprite->data[0];
    sprite->data[1] -= 32;

    if (sprite->data[0] < 0)
        sprite->data[0] = 0;

    if (++sprite->data[3] == 31)
        DestroyAnimSprite(sprite);
}

void sub_810F004(struct Sprite *sprite)
{
    sprite->data[6] = 0;
    sprite->data[7] = 64;
    sprite->callback = sub_810F018;
}

void sub_810F018(struct Sprite *sprite)
{
    switch (sprite->data[0])
    {
    case 0:
        if (++sprite->data[1] > 8)
        {
            sprite->data[1] = 0;
            sprite->invisible ^= 1;
            if (++sprite->data[2] > 5 && sprite->invisible)
                sprite->data[0]++;
        }
        break;
    case 1:
        DestroyAnimSprite(sprite);
        break;
    }
}

void sub_810F084(struct Sprite *sprite)
{
    u16 rotation;
    s16 posx = sprite->pos1.x;
    s16 posy = sprite->pos1.y;

    sprite->pos1.x = GetBattlerSpriteCoord(gBattleAnimAttacker, 2);
    sprite->pos1.y = GetBattlerSpriteCoord(gBattleAnimAttacker, 3);

    sprite->data[4] = sprite->pos1.x << 4;
    sprite->data[5] = sprite->pos1.y << 4;

    sprite->data[6] = ((posx - sprite->pos1.x) << 4) / 12;
    sprite->data[7] = ((posy - sprite->pos1.y) << 4) / 12;

    rotation = ArcTan2Neg(posx - sprite->pos1.x, posy - sprite->pos1.y);
    rotation += 49152;

    TrySetSpriteRotScale(sprite, 1, 0x100, 0x100, rotation);

    sprite->callback = sub_810F140;
}

void sub_810F140(struct Sprite *sprite)
{
    sprite->data[4] += sprite->data[6];
    sprite->data[5] += sprite->data[7];

    sprite->pos1.x = sprite->data[4] >> 4;
    sprite->pos1.y = sprite->data[5] >> 4;

    if (sprite->pos1.x > 285 || sprite->pos1.x < -45
        || sprite->pos1.y > 157 || sprite->pos1.y < -45)
        DestroySpriteAndMatrix(sprite);
}

void unref_sub_810F184(u8 taskId)
{
    if (gBattleAnimArgs[0] == 0)
    {
        u8 spriteId = GetAnimBattlerSpriteId(0);
        gSprites[spriteId].invisible = 1;
    }
    else
    {
        u8 spriteId = GetAnimBattlerSpriteId(0);
        gSprites[spriteId].invisible = 0;
    }
    DestroyAnimVisualTask(taskId);
}
