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
    .oam = &gOamData_AffineOff_ObjNormal_32x64,
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
    .oam = &gOamData_AffineNormal_ObjNormal_32x64,
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
    .oam = &gOamData_AffineOff_ObjNormal_32x16,
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
    .oam = &gOamData_AffineDouble_ObjNormal_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gUnknown_08596314,
    .callback = sub_810E13C,
};

const struct SpriteTemplate gUnknown_08596358 =
{
    .tileTag = ANIM_TAG_ROUND_SHADOW,
    .paletteTag = ANIM_TAG_ROUND_SHADOW,
    .oam = &gOamData_AffineNormal_ObjNormal_64x64,
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
    .oam = &gOamData_AffineNormal_ObjNormal_32x32,
    .anims = gUnknown_08596380,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_810E314,
};

const struct SpriteTemplate gUnknown_085963A0 =
{
    .tileTag = ANIM_TAG_SMALL_BUBBLES,
    .paletteTag = ANIM_TAG_SMALL_BUBBLES,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
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
    .oam = &gOamData_AffineOff_ObjNormal_32x16,
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
    .oam = &gOamData_AffineDouble_ObjNormal_64x64,
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
    .oam = &gOamData_AffineDouble_ObjNormal_64x64,
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
    .oam = &gOamData_AffineDouble_ObjNormal_64x64,
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
    .oam = &gOamData_AffineDouble_ObjNormal_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_810EE14,
};

const struct SpriteTemplate gUnknown_085964E4 =
{
    .tileTag = ANIM_TAG_SWEAT_BEAD,
    .paletteTag = ANIM_TAG_SWEAT_BEAD,
    .oam = &gOamData_AffineOff_ObjNormal_8x8,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_810EEF8,
};

const struct SpriteTemplate gUnknown_085964FC =
{
    .tileTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .paletteTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .oam = &gOamData_AffineOff_ObjBlend_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_810F004,
};

const struct SpriteTemplate gUnknown_08596514 =
{
    .tileTag = ANIM_TAG_BIRD,
    .paletteTag = ANIM_TAG_BIRD,
    .oam = &gOamData_AffineDouble_ObjNormal_64x64,
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
    u16 unk0_0a:1;
    u16 unk0_0b:1;
    u16 unk0_0c:1;
    u16 unk0_0d:1;
    u16 unk0_1:4;
    u16 unk1:8;
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

void sub_810E520(struct Sprite *sprite)
{
    u8 matrixNum, sinIndex;
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
        switch (data->unk2 / 64)
        {
        case 0: 
            if (data->unk0_1 << 24 >> 24 == 1) // the shifts have to be here
            {
                data->unk0_0d = 1;
                data->unk0_0a = 1;
                data->unk1 = 0;
            }
            else if (data->unk0_1 << 24 >> 24 == 3)
            {
                data->unk0_0b ^= 1;
                data->unk0_0a = 1;
                data->unk1 = 0;
            }
            else if (data->unk0_0d)
            {
                sprite->hFlip ^= 1;
                sprite->animNum = sprite->hFlip;
                sprite->animBeginning = TRUE;
                sprite->animEnded = FALSE;
                if (data->unk0_0c)
                {
                    if (!IsContest())
                    {
                        if (!data->unkE_0)
                        {
                            sprite->oam.priority--;
                            data->unkE_0 ^= 1;
                        }
                        else
                        {
                            sprite->oam.priority++;
                            data->unkE_0 ^= 1;
                        }
                    }
                    else
                    {
                        if (!data->unkE_0)
                        {
                            sprite->subpriority -= 12;
                            data->unkE_0 ^= 1;
                        }
                        else
                        {
                            sprite->subpriority += 12;
                            data->unkE_0 ^= 1;
                        }
                    }
                }
                data->unk0_0d = 0;
                data->unk2;
            }
            data->unk0_1 = 0;
            break;
        case 1:
            if (data->unk0_1 << 24 >> 24 == 0)
            {
                data->unk0_0d = 1;
                data->unk0_0a = 1;
                data->unk1 = 0;
            }
            else if (data->unk0_1 << 24 >> 24 == 2)
            {
                data->unk0_0a = 1;
                data->unk1 = 0;
            }
            else if (data->unk0_0d)
            {
                sprite->hFlip ^= 1;
                sprite->animNum = sprite->hFlip;
                sprite->animBeginning = TRUE;
                sprite->animEnded = FALSE;
                if (data->unk0_0c)
                {
                    if (!IsContest())
                    {
                        if (!data->unkE_0)
                        {
                            sprite->oam.priority--;
                            data->unkE_0 ^= 1;
                        }
                        else
                        {
                            sprite->oam.priority++;
                            data->unkE_0 ^= 1;
                        }
                    }
                    else
                    {
                        if (!data->unkE_0)
                        {
                            sprite->subpriority -= 12;
                            data->unkE_0 ^= 1;
                        }
                        else
                        {
                            sprite->subpriority += 12;
                            data->unkE_0 ^= 1;
                        }
                    }
                }
                data->unk0_0d = 0;
            }
            data->unk0_1 = 1;
            break;
        case 2:
            if (data->unk0_1 << 24 >> 24 == 3)
            {
                data->unk0_0d = 1;
                data->unk0_0a = 1;
                data->unk1 = 0;
            }
            else if (data->unk0_1 << 24 >> 24 == 1)
            {
                data->unk0_0a = 1;
                data->unk1 = 0;
            }
            else if (data->unk0_0d)
            {
                sprite->hFlip ^= 1;
                sprite->animNum = sprite->hFlip;
                sprite->animBeginning = TRUE;
                sprite->animEnded = FALSE;
                if (data->unk0_0c)
                {
                    if (!IsContest())
                    {
                        if (!data->unkE_0)
                        {
                            sprite->oam.priority--;
                            data->unkE_0 ^= 1;
                        }
                        else
                        {
                            sprite->oam.priority++;
                            data->unkE_0 ^= 1;
                        }
                    }
                    else
                    {
                        if (!data->unkE_0)
                        {
                            sprite->subpriority -= 12;
                            data->unkE_0 ^= 1;
                        }
                        else
                        {
                            sprite->subpriority += 12;
                            data->unkE_0 ^= 1;
                        }
                    }
                }
                data->unk0_0d = 0;
            }
            data->unk0_1 = 2;
            break;
        case 3:
            if (data->unk0_1 << 24 >> 24 == 2)
            {
                data->unk0_0d = 1;
            }
            else if (data->unk0_1 << 24 >> 24 == 0)
            {
                data->unk0_0b ^= 1;
                data->unk0_0a = 1;
                data->unk1 = 0;
            }
            else if (data->unk0_0d)
            {
                sprite->hFlip ^= 1;
                sprite->animNum = sprite->hFlip;
                sprite->animBeginning = TRUE;
                sprite->animEnded = FALSE;
                if (data->unk0_0c)
                {
                    if (!IsContest())
                    {
                        if (!data->unkE_0)
                        {
                            sprite->oam.priority--;
                            data->unkE_0 ^= 1;
                        }
                        else
                        {
                            sprite->oam.priority++;
                            data->unkE_0 ^= 1;
                        }
                    }
                    else
                    {
                        if (!data->unkE_0)
                        {
                            sprite->subpriority -= 12;
                            data->unkE_0 ^= 1;
                        }
                        else
                        {
                            sprite->subpriority += 12;
                            data->unkE_0 ^= 1;
                        }
                    }
                }
                data->unk0_0d = 0;
            }
            data->unk0_1 = 3;
            break;
        }
        #ifndef NONMATCHING
            asm("":::"r8");
        #endif
        sprite->pos2.x = (data->unkC[data->unk0_0b] * gSineTable[data->unk2]) >> 8;
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

        if (sprite->pos1.y + sprite->pos2.y >= data->unkE_1)
        {
            sprite->data[0] = 0;
            sprite->callback = sub_810E2C8;
        }
    }
}

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
        sprite->oam.matrixNum = ST_OAM_HFLIP;

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
