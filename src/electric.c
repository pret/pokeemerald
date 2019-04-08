#include "global.h"
#include "battle_anim.h"
#include "constants/rgb.h"
#include "trig.h"
#include "constants/songs.h"
#include "sound.h"

static void sub_810A1A8(struct Sprite *);
static void sub_810A1F8(struct Sprite *);
static void sub_810A214(struct Sprite *);
static void sub_810A258(struct Sprite *);
static void sub_810A274(struct Sprite *);
static void sub_810A308(struct Sprite *);
static void sub_810A46C(struct Sprite *);
static void sub_810A4F4(struct Sprite *);
static void sub_810A56C(struct Sprite *);
static void sub_810A5BC(struct Sprite *);
static void sub_810A628(struct Sprite *);
static void sub_810A6EC(struct Sprite *);
static void sub_810A75C(struct Sprite *);
static void sub_810A834(u8 taskId);
static void sub_810A9DC(struct Sprite *);
static void sub_810AA2C(struct Sprite *);
static void sub_810AAB0(struct Sprite *);
static void sub_810AB78(u8 taskId);
static void sub_810AC8C(struct Sprite *);
static void sub_810ACC0(struct Sprite *);
static void sub_810ACD8(struct Sprite *);
static void sub_810AD30(struct Sprite *);
static void sub_810AD98(struct Sprite *);
static void sub_810ADF8(struct Sprite *);
static bool8 sub_810B154(struct Task *task, u8 taskId);
static void sub_810B1F0(struct Sprite *);
static void sub_810B23C(struct Sprite *);
static bool8 sub_810B430(struct Task *task, u8 taskId);
static void sub_810B51C(struct Sprite *);
static bool8 sub_810B614(struct Task *task, u8 taskId);
static void sub_810B684(struct Sprite *sprite);

const union AnimCmd gUnknown_085956A4[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(16, 5),
    ANIMCMD_FRAME(32, 8),
    ANIMCMD_FRAME(48, 5),
    ANIMCMD_FRAME(64, 5),
    ANIMCMD_END,
};

const union AnimCmd *const gUnknown_085956BC[] =
{
    gUnknown_085956A4,
};

const struct SpriteTemplate gUnknown_085956C0 =
{
    .tileTag = ANIM_TAG_LIGHTNING,
    .paletteTag = ANIM_TAG_LIGHTNING,
    .oam = &gUnknown_08524914,
    .anims = gUnknown_085956BC,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_810A1A8,
};

const union AffineAnimCmd gUnknown_085956D8[] =
{
    AFFINEANIMCMD_FRAME(0x100, 0x100, 0, 0),
    AFFINEANIMCMD_FRAME(0x0, 0x0, 0, 20),
    AFFINEANIMCMD_FRAME(0x0, 0x0, -16, 60),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd *const gUnknown_085956F8[] =
{
    gUnknown_085956D8,
};

const struct SpriteTemplate gUnknown_085956FC =
{
    .tileTag = ANIM_TAG_HANDS_AND_FEET,
    .paletteTag = ANIM_TAG_HANDS_AND_FEET,
    .oam = &gUnknown_08524974,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gUnknown_085956F8,
    .callback = sub_810A214,
};

const union AnimCmd gUnknown_08595714[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(16, 5),
    ANIMCMD_FRAME(32, 5),
    ANIMCMD_FRAME(48, 5),
    ANIMCMD_FRAME(64, 5),
    ANIMCMD_FRAME(80, 5),
    ANIMCMD_JUMP(0),
};

const union AnimCmd *const gUnknown_08595730[] =
{
    gUnknown_08595714,
};

const struct SpriteTemplate gUnknown_08595734 =
{
    .tileTag = ANIM_TAG_SHOCK,
    .paletteTag = ANIM_TAG_SHOCK,
    .oam = &gUnknown_08524914,
    .anims = gUnknown_08595730,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_810A274,
};

const struct SpriteTemplate gBattleAnimSpriteTemplate_859574C =
{
    .tileTag = ANIM_TAG_SPARK_2,
    .paletteTag = ANIM_TAG_SPARK_2,
    .oam = &gUnknown_0852496C,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_810A308,
};

const struct SpriteTemplate gUnknown_08595764 =
{
    .tileTag = ANIM_TAG_BLACK_BALL_2,
    .paletteTag = ANIM_TAG_BLACK_BALL_2,
    .oam = &gUnknown_0852490C,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = TranslateAnimSpriteToTargetMonLocation,
};

const union AffineAnimCmd gUnknown_0859577C[] =
{
    AFFINEANIMCMD_FRAME(0x0, 0x0, 20, 1),
    AFFINEANIMCMD_JUMP(0),
};

const union AffineAnimCmd *const gUnknown_0859578C[] =
{
    gUnknown_0859577C,
};

const struct SpriteTemplate gUnknown_08595790 =
{
    .tileTag = ANIM_TAG_SPARK_2,
    .paletteTag = ANIM_TAG_SPARK_2,
    .oam = &gUnknown_0852496C,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gUnknown_0859578C,
    .callback = sub_810A46C,
};

const union AnimCmd gUnknown_085957A8[] =
{
    ANIMCMD_FRAME(0, 6),
    ANIMCMD_FRAME(16, 6),
    ANIMCMD_FRAME(32, 6),
    ANIMCMD_JUMP(0),
};

const union AnimCmd *const gUnknown_085957B8[] =
{
    gUnknown_085957A8,
};

const union AffineAnimCmd gUnknown_085957BC[] =
{
    AFFINEANIMCMD_FRAME(0xE8, 0xE8, 0, 0),
    AFFINEANIMCMD_FRAME(0xFFF8, 0xFFF8, 0, 10),
    AFFINEANIMCMD_FRAME(0x8, 0x8, 0, 10),
    AFFINEANIMCMD_JUMP(1),
};

const union AffineAnimCmd *const gUnknown_085957DC[] =
{
    gUnknown_085957BC,
};

const struct SpriteTemplate gBattleAnimSpriteTemplate_85957E0 =
{
    .tileTag = ANIM_TAG_SHOCK_3,
    .paletteTag = ANIM_TAG_SHOCK_3,
    .oam = &gUnknown_08524974,
    .anims = gUnknown_085957B8,
    .images = NULL,
    .affineAnims = gUnknown_085957DC,
    .callback = sub_810A5BC,
};

const struct SpriteTemplate gBattleAnimSpriteTemplate_85957F8 =
{
    .tileTag = ANIM_TAG_SPARK_2,
    .paletteTag = ANIM_TAG_SPARK_2,
    .oam = &gUnknown_0852496C,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gUnknown_0859578C,
    .callback = sub_810A628,
};

const struct SpriteTemplate gElectricitySpriteTemplate =
{
    .tileTag = ANIM_TAG_SPARK_2,
    .paletteTag = ANIM_TAG_SPARK_2,
    .oam = &gUnknown_0852490C,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_810A75C,
};

const struct SpriteTemplate gUnknown_08595828 =
{
    .tileTag = ANIM_TAG_SPARK,
    .paletteTag = ANIM_TAG_SPARK,
    .oam = &gUnknown_08524904,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_810A9DC,
};

const struct SpriteTemplate gUnknown_08595840 =
{
    .tileTag = ANIM_TAG_SPARK_H,
    .paletteTag = ANIM_TAG_SPARK_H,
    .oam = &gUnknown_08524934,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_810AA2C,
};

const s8 gUnknown_08595858[][2] =
{
    { 58, -60},
    {-56, -36},
    {  8, -56},
    {-16,  56},
    { 58, -10},
    {-58,  10},
    { 48, -18},
    {-8,   56},
    { 16, -56},
    {-58, -42},
    { 58,  30},
    {-48,  40},
    { 12, -48},
    { 48, -12},
    {-56,  18},
    { 48,  48},
};

const union AnimCmd gUnknown_08595878[] =
{
    ANIMCMD_FRAME(3, 1),
    ANIMCMD_FRAME(2, 1),
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

const union AnimCmd gUnknown_0859588C[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(2, 5),
    ANIMCMD_FRAME(3, 5),
    ANIMCMD_END,
};

const union AnimCmd *const gUnknown_085958A0[] =
{
    gUnknown_08595878,
    gUnknown_0859588C,
};

const struct SpriteTemplate gUnknown_085958A8 =
{
    .tileTag = ANIM_TAG_ELECTRIC_ORBS,
    .paletteTag = ANIM_TAG_ELECTRIC_ORBS,
    .oam = &gUnknown_08524904,
    .anims = gUnknown_085958A0,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

const union AffineAnimCmd gUnknown_085958C0[] =
{
    AFFINEANIMCMD_FRAME(0x10, 0x10, 0, 0),
    AFFINEANIMCMD_FRAME(0x4, 0x4, 0, 60),
    AFFINEANIMCMD_FRAME(0x100, 0x100, 0, 0),
    AFFINEANIMCMD_LOOP(0),
    AFFINEANIMCMD_FRAME(0xFFFC, 0xFFFC, 0, 5),
    AFFINEANIMCMD_FRAME(0x4, 0x4, 0, 5),
    AFFINEANIMCMD_LOOP(10),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd gUnknown_08595900[] =
{
    AFFINEANIMCMD_FRAME(0x10, 0x10, 0, 0),
    AFFINEANIMCMD_FRAME(0x8, 0x8, 0, 30),
    AFFINEANIMCMD_FRAME(0x100, 0x100, 0, 0),
    AFFINEANIMCMD_FRAME(0xFFFC, 0xFFFC, 0, 5),
    AFFINEANIMCMD_FRAME(0x4, 0x4, 0, 5),
    AFFINEANIMCMD_JUMP(3),
};

const union AffineAnimCmd gUnknown_08595930[] =
{
    AFFINEANIMCMD_FRAME(0x10, 0x10, 0, 0),
    AFFINEANIMCMD_FRAME(0x8, 0x8, 0, 30),
    AFFINEANIMCMD_FRAME(0xFFF8, 0xFFF8, 0, 30),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd *const gUnknown_08595950[] =
{
    gUnknown_085958C0,
    gUnknown_08595900,
    gUnknown_08595930,
};

const struct SpriteTemplate gUnknown_0859595C =
{
    .tileTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .paletteTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .oam = &gUnknown_08524A9C,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gUnknown_08595950,
    .callback = sub_810ACD8,
};

const union AnimCmd gUnknown_08595974[] =
{
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(16, 3),
    ANIMCMD_FRAME(32, 3),
    ANIMCMD_FRAME(48, 3),
    ANIMCMD_END,
};

const union AnimCmd *const gUnknown_08595988[] =
{
    gUnknown_08595974,
};

const struct SpriteTemplate gUnknown_0859598C =
{
    .tileTag = ANIM_TAG_ELECTRICITY,
    .paletteTag = ANIM_TAG_ELECTRICITY,
    .oam = &gUnknown_08524914,
    .anims = gUnknown_08595988,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_810AD30,
};

const struct SpriteTemplate gUnknown_085959A4 =
{
    .tileTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .paletteTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .oam = &gUnknown_08524A9C,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gUnknown_08595950,
    .callback = sub_810AD98,
};

const union AnimCmd gUnknown_085959BC[] =
{
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_END,
};

const union AnimCmd gUnknown_085959C4[] =
{
    ANIMCMD_FRAME(2, 3),
    ANIMCMD_END,
};

const union AnimCmd gUnknown_085959CC[] =
{
    ANIMCMD_FRAME(4, 3),
    ANIMCMD_END,
};

const union AnimCmd gUnknown_085959D4[] =
{
    ANIMCMD_FRAME(6, 3),
    ANIMCMD_END,
};

const union AnimCmd *const gUnknown_085959DC[] =
{
    gUnknown_085959BC,
    gUnknown_085959C4,
    gUnknown_085959CC,
    gUnknown_085959D4,
};

const union AffineAnimCmd gUnknown_085959EC[] =
{
    AFFINEANIMCMD_FRAME(0x100, 0x100, 64, 0),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd *const gUnknown_085959FC[] =
{
    gUnknown_085959EC,
};

const struct SpriteTemplate gUnknown_08595A00 =
{
    .tileTag = ANIM_TAG_SPARK,
    .paletteTag = ANIM_TAG_SPARK,
    .oam = &gUnknown_08524A04,
    .anims = gUnknown_085959DC,
    .images = NULL,
    .affineAnims = gUnknown_085959FC,
    .callback = sub_810B1F0,
};

const struct SpriteTemplate gUnknown_08595A18 =
{
    .tileTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .paletteTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .oam = &gUnknown_08524A9C,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gUnknown_08595950,
    .callback = sub_810B23C,
};

const struct SpriteTemplate gUnknown_08595A30 =
{
    .tileTag = ANIM_TAG_SPARK,
    .paletteTag = ANIM_TAG_SPARK,
    .oam = &gUnknown_08524904,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_810B51C,
};

static void sub_810A1A8(struct Sprite *sprite)
{
    if (GetBattlerSide(gBattleAnimAttacker) != B_SIDE_PLAYER)
        sprite->pos1.x -= gBattleAnimArgs[0];
    else
        sprite->pos1.x += gBattleAnimArgs[0];

    sprite->pos1.y += gBattleAnimArgs[1];
    sprite->callback = sub_810A1F8;
}

static void sub_810A1F8(struct Sprite *sprite)
{
    if (sprite->animEnded)
        DestroyAnimSprite(sprite);
}

static void sub_810A214(struct Sprite *sprite)
{
    if (GetBattlerSide(gBattleAnimAttacker) != B_SIDE_PLAYER)
        sprite->pos1.x -= gBattleAnimArgs[0];
    else
        sprite->pos1.x += gBattleAnimArgs[0];

    sprite->callback = sub_810A258;
}

static void sub_810A258(struct Sprite *sprite)
{
    if (sprite->affineAnimEnded)
        DestroySpriteAndMatrix(sprite);
}

static void sub_810A274(struct Sprite *sprite)
{
    sprite->pos1.x = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X_2);
    sprite->pos1.y = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y_PIC_OFFSET);

    if (GetBattlerSide(gBattleAnimAttacker) != B_SIDE_PLAYER)
    {
        sprite->pos1.x -= gBattleAnimArgs[0];
        sprite->pos1.y -= gBattleAnimArgs[1];
    }
    else
    {
        sprite->pos1.x += gBattleAnimArgs[0];
        sprite->pos1.y += gBattleAnimArgs[1];
    }
    sprite->data[0] = 0;
    sprite->data[1] = gBattleAnimArgs[2];
    sprite->data[2] = gBattleAnimArgs[3];
    sprite->data[3] = gBattleAnimArgs[4];
    StoreSpriteCallbackInData6(sprite, DestroySpriteAndMatrix);
    sprite->callback = TranslateSpriteInCircleOverDuration;
}

static void sub_810A308(struct Sprite *sprite)
{
    u8 battler;
    u32 matrixNum;
    s16 sineVal;

    switch (gBattleAnimArgs[4])
    {
    case 0:
        battler = gBattleAnimAttacker;
        break;
    case 1:
    default:
        battler = gBattleAnimTarget;
        break;
    case 2:
        if (!IsBattlerSpriteVisible(BATTLE_PARTNER(gBattleAnimAttacker)))
            battler = gBattleAnimAttacker;
        else
            battler = BATTLE_PARTNER(gBattleAnimAttacker);
        break;
    case 3:
        if (IsBattlerSpriteVisible(BATTLE_PARTNER(gBattleAnimAttacker)))
            battler = BATTLE_PARTNER(gBattleAnimTarget);
        else
            battler = gBattleAnimTarget;
        break;
    }

    if (gBattleAnimArgs[5] == 0)
    {
        sprite->pos1.x = GetBattlerSpriteCoord(battler, BATTLER_COORD_X);
        sprite->pos1.y = GetBattlerSpriteCoord(battler, BATTLER_COORD_Y);
    }
    else
    {
        sprite->pos1.x = GetBattlerSpriteCoord(battler, BATTLER_COORD_X_2);
        sprite->pos1.y = GetBattlerSpriteCoord(battler, BATTLER_COORD_Y_PIC_OFFSET);
    }

    sprite->pos2.x = (gSineTable[gBattleAnimArgs[0]] * gBattleAnimArgs[1]) >> 8;
    sprite->pos2.y = (gSineTable[gBattleAnimArgs[0] + 64] * gBattleAnimArgs[1]) >> 8;

    if (gBattleAnimArgs[6] & 1)
        sprite->oam.priority = GetBattlerSpriteBGPriority(battler) + 1;

    matrixNum = sprite->oam.matrixNum;
    sineVal = gSineTable[gBattleAnimArgs[2]];

    gOamMatrices[matrixNum].a = gOamMatrices[matrixNum].d =  gSineTable[gBattleAnimArgs[2] + 64];
    gOamMatrices[matrixNum].b =  sineVal;
    gOamMatrices[matrixNum].c = -sineVal;

    sprite->data[0] = gBattleAnimArgs[3];
    sprite->callback = sub_810E2C8;
}

static void sub_810A46C(struct Sprite *sprite)
{
    InitSpritePosToAnimAttacker(sprite, 1);
    sprite->data[0] = gBattleAnimArgs[3];
    sprite->data[1] = sprite->pos1.x;
    sprite->data[2] = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X_2);
    sprite->data[3] = sprite->pos1.y;
    sprite->data[4] = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y_PIC_OFFSET);
    InitAnimLinearTranslation(sprite);
    sprite->data[5] = gBattleAnimArgs[2];
    sprite->data[6] = gBattleAnimArgs[5];
    sprite->data[7] = gBattleAnimArgs[4];
    sprite->oam.tileNum += gBattleAnimArgs[6] * 4;
    sprite->callback = sub_810A4F4;
    sub_810A4F4(sprite);
}

static void sub_810A4F4(struct Sprite *sprite)
{
    if (!AnimTranslateLinear(sprite))
    {
        sprite->pos2.x += Sin(sprite->data[7], sprite->data[5]);
        sprite->pos2.y += Cos(sprite->data[7], sprite->data[5]);
        sprite->data[7] = (sprite->data[7] + sprite->data[6]) & 0xFF;
        if(!(sprite->data[7] % 3))
            sprite->invisible ^= 1;
    }
    else
        DestroyAnimSprite(sprite);
}

static void sub_810A56C(struct Sprite *sprite)
{
    if (--sprite->data[5] == -1)
    {
        sprite->invisible ^= 1;
        sprite->data[5] = sprite->data[4];
    }
    if (sprite->data[3]-- <= 0)
        DestroyAnimSprite(sprite);
}

static void sub_810A5BC(struct Sprite *sprite)
{
    if (IsContest() || GetBattlerSide(gBattleAnimTarget) == B_SIDE_PLAYER)
        gBattleAnimArgs[1] = -gBattleAnimArgs[1];

    sprite->pos1.x = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X_2) + gBattleAnimArgs[1];
    sprite->pos1.y = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y_PIC_OFFSET) + gBattleAnimArgs[2];
    sprite->data[3] = gBattleAnimArgs[0];
    sprite->data[4] = gBattleAnimArgs[3];
    sprite->data[5] = gBattleAnimArgs[3];
    sprite->callback = sub_810A56C;
}

static void sub_810A628(struct Sprite *sprite)
{
    u8 battler;

    sprite->data[0] = gBattleAnimArgs[3];
    if (gBattleAnimArgs[7] & 0x8000)
        battler = gBattleAnimTarget;
    else
        battler = gBattleAnimAttacker;

    if (IsContest() || GetBattlerSide(battler) == B_SIDE_PLAYER)
        gBattleAnimArgs[0] = -gBattleAnimArgs[0];

    sprite->pos1.x = GetBattlerSpriteCoord(battler, BATTLER_COORD_X_2) + gBattleAnimArgs[0];
    sprite->pos1.y = GetBattlerSpriteCoord(battler, BATTLER_COORD_Y_PIC_OFFSET) + gBattleAnimArgs[1];

    sprite->data[4] = gBattleAnimArgs[7] & 0x7FFF;
    sprite->data[5] = gBattleAnimArgs[2];
    sprite->data[6] = gBattleAnimArgs[5];
    sprite->data[7] = gBattleAnimArgs[4];

    sprite->oam.tileNum += gBattleAnimArgs[6] * 4;
    sprite->callback = sub_810A6EC;
    sprite->callback(sprite);
}

static void sub_810A6EC(struct Sprite *sprite)
{
    sprite->pos2.x = Sin(sprite->data[7], sprite->data[5]);
    sprite->pos2.y = Cos(sprite->data[7], sprite->data[5]);

    sprite->data[7] = (sprite->data[7] + sprite->data[6]) & 0xFF;
    if (sprite->data[7] % sprite->data[4] == 0)
        sprite->invisible ^= 1;

    if (sprite->data[0]-- <= 0)
        DestroyAnimSprite(sprite);
}

static void sub_810A75C(struct Sprite *sprite)
{
    InitSpritePosToAnimTarget(sprite, FALSE);
    sprite->oam.tileNum += gBattleAnimArgs[3] * 4;

    if (gBattleAnimArgs[3] == 1)
        sprite->oam.matrixNum = 8;
    else if (gBattleAnimArgs[3] == 2)
        sprite->oam.matrixNum = 16;

    sprite->data[0] = gBattleAnimArgs[2];
    sprite->callback = WaitAnimForDuration;
    StoreSpriteCallbackInData6(sprite, DestroyAnimSprite);
}

void sub_810A7DC(u8 taskId)
{
    gTasks[taskId].data[0] = GetBattlerSpriteCoord(gBattleAnimTarget, 0) + gBattleAnimArgs[0];
    gTasks[taskId].data[1] = GetBattlerSpriteCoord(gBattleAnimTarget, 1) + gBattleAnimArgs[1];
    gTasks[taskId].data[2] = gBattleAnimArgs[2];
    gTasks[taskId].func = sub_810A834;
}

static void sub_810A834(u8 taskId)
{
    u16 r8;
    u16 r2;
    s16 r12;
    u8 spriteId = 0;
    u8 r7 = 0;
    u8 sp = gTasks[taskId].data[2];
    s16 x = gTasks[taskId].data[0];
    s16 y = gTasks[taskId].data[1];

    if (!gTasks[taskId].data[2])
    {
        r8 = 0;
        r2 = 1;
        r12 = 16;
    }
    else
    {
        r12 = 16;
        r8 = 8;
        r2 = 4;
    }

    switch (gTasks[taskId].data[10])
    {
    case 0:
        r12 *= 1;
        spriteId = CreateSprite(&gUnknown_08595828, x, y + r12, 2);
        r7++;
        break;
    case 2:
        r12 *= 2;
        r8 += r2;
        spriteId = CreateSprite(&gUnknown_08595828, x, y + r12, 2);
        r7++;
        break;
    case 4:
        r12 *= 3;
        r8 += r2 * 2;
        spriteId = CreateSprite(&gUnknown_08595828, x, y + r12, 2);
        r7++;
        break;
    case 6:
        r12 *= 4;
        r8 += r2 * 3;
        spriteId = CreateSprite(&gUnknown_08595828, x, y + r12, 2);
        r7++;
        break;
    case 8:
        r12 *= 5;
        spriteId = CreateSprite(&gUnknown_08595828, x, y + r12, 2);
        r7++;
        break;
    case 10:
        DestroyAnimVisualTask(taskId);
        return;
    }

    if (r7)
    {
        gSprites[spriteId].oam.tileNum += r8;
        gSprites[spriteId].data[0] = sp;
        gSprites[spriteId].callback(&gSprites[spriteId]);
    }

    gTasks[taskId].data[10]++;
}

static void sub_810A9DC(struct Sprite *sprite)
{
    if (!sprite->data[0])
    {
        sprite->oam.shape = 2;
        sprite->oam.size = 0;
    }
    else
    {
        sprite->oam.shape = 0;
        sprite->oam.size = 1;
    }
    if (++sprite->data[1] == 15)
        DestroySprite(sprite);
}

static void sub_810AA2C(struct Sprite *sprite)
{
    u8 spriteId;

    sprite->pos1.x += gBattleAnimArgs[0];
    sprite->pos1.y += gBattleAnimArgs[1];
    spriteId = CreateSprite(&gUnknown_08595840, sprite->pos1.x + 32, sprite->pos1.y, sprite->subpriority);
    gSprites[spriteId].oam.tileNum += 8;
    gAnimVisualTaskCount++;
    gSprites[spriteId].callback = sub_810AAB0;
    sprite->callback = sub_810AAB0;
}

static void sub_810AAB0(struct Sprite *sprite)
{
    if (++sprite->data[0] == 3)
    {
        sprite->data[0] = 0;
        sprite->invisible ^= 1;
    }

    if (++sprite->data[1] == 51)
        DestroyAnimSprite(sprite);
}

void sub_810AAFC(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    if (!gBattleAnimArgs[0])
    {
        task->data[14] = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_X_2);
        task->data[15] = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_Y_PIC_OFFSET);
    }
    else
    {
        task->data[14] = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X_2);
        task->data[15] = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y_PIC_OFFSET);
    }

    task->data[6] = gBattleAnimArgs[1];
    task->data[7] = 0;
    task->data[8] = 0;
    task->data[9] = 0;
    task->data[10] = 0;
    task->data[11] = gBattleAnimArgs[3];
    task->data[12] = 0;
    task->data[13] = gBattleAnimArgs[2];
    task->func = sub_810AB78;
}

void sub_810AB78(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    if (task->data[6])
    {
        if (++task->data[12] > task->data[13])
        {
            u8 spriteId;
            task->data[12] = 0;
            spriteId = CreateSprite(&gUnknown_085958A8, task->data[14], task->data[15], 2);
            if (spriteId != MAX_SPRITES)
            {
                struct Sprite *sprite = &gSprites[spriteId];
                sprite->pos1.x += gUnknown_08595858[task->data[9]][0];
                sprite->pos1.y += gUnknown_08595858[task->data[9]][1];

                sprite->data[0] = 40 - task->data[8] * 5;
                sprite->data[1] = sprite->pos1.x;
                sprite->data[2] = task->data[14];
                sprite->data[3] = sprite->pos1.y;
                sprite->data[4] = task->data[15];
                sprite->data[5] = taskId;

                InitAnimLinearTranslation(sprite);
                StoreSpriteCallbackInData6(sprite, sub_810ACC0);
                sprite->callback = RunStoredCallbackWhenAnimEnds;

                if (++task->data[9] > 15)
                    task->data[9] = 0;

                if (++task->data[10] >= task->data[11])
                {
                    task->data[10] = 0;
                    if (task->data[8] <= 5)
                        task->data[8]++;
                }

                task->data[7]++;
                task->data[6]--;
            }
        }
    }
    else if(task->data[7] == 0)
        DestroyAnimVisualTask(taskId);
}

static void sub_810AC8C(struct Sprite *sprite)
{
    if (AnimTranslateLinear(sprite))
    {
        gTasks[sprite->data[5]].data[7]--;
        DestroySprite(sprite);
    }
}

static void sub_810ACC0(struct Sprite *sprite)
{
    StartSpriteAnim(sprite, 1);
    sprite->callback = sub_810AC8C;
}

static void sub_810ACD8(struct Sprite *sprite)
{
    if (!gBattleAnimArgs[0])
    {
        sprite->pos1.x = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_X_2);
        sprite->pos1.y = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_Y_PIC_OFFSET);
    }
    else
    {
        sprite->pos1.x = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X_2);
        sprite->pos1.y = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y_PIC_OFFSET);
    }

    StoreSpriteCallbackInData6(sprite, DestroySpriteAndMatrix);
    sprite->callback = RunStoredCallbackWhenAffineAnimEnds;
}

static void sub_810AD30(struct Sprite *sprite)
{
    if (!gBattleAnimArgs[0])
    {
        sprite->pos1.x = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_X_2);
        sprite->pos1.y = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_Y_PIC_OFFSET);
    }
    else
    {
        sprite->pos1.x = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X_2);
        sprite->pos1.y = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y_PIC_OFFSET);
    }

    sprite->pos2.x = gBattleAnimArgs[1];
    sprite->pos2.y = gBattleAnimArgs[2];
    StoreSpriteCallbackInData6(sprite, DestroyAnimSprite);
    sprite->callback = RunStoredCallbackWhenAnimEnds;
}

static void sub_810AD98(struct Sprite *sprite)
{
    StartSpriteAffineAnim(sprite, 1);
    sprite->pos1.x = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_X_2);
    sprite->pos1.y = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_Y_PIC_OFFSET);
    sprite->data[6] = GetAnimBattlerSpriteId(0);
    sprite->data[7] = 16;

    if (GetBattlerSide(gBattleAnimAttacker) == B_SIDE_OPPONENT)
        sprite->data[7] *= -1;

    sprite->callback = sub_810ADF8;
}

static void sub_810ADF8(struct Sprite *sprite)
{
    switch (sprite->data[0])
    {
    case 0:
        if (++sprite->data[1] > 40)
            sprite->data[0]++;
        break;
    case 1:
        sprite->pos1.x += sprite->data[7];
        gSprites[sprite->data[6]].pos2.x += sprite->data[7];
        if ((u16)(sprite->pos1.x + 80) > 400)
            DestroySpriteAndMatrix(sprite);
    }
}

void sub_810AE5C(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    switch (task->data[0])
    {
    case 0:
        task->data[15] = GetAnimBattlerSpriteId(0);
        task->data[14] = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_X_2);
        if (GetBattlerSide(gBattleAnimAttacker) == B_SIDE_PLAYER)
        {
            task->data[14] = -32;
            task->data[13] = 2;
        }
        else
        {
            task->data[14] = 32;
            task->data[13] = -2;
        }

        gSprites[task->data[15]].pos2.x = task->data[14];
        task->data[0]++;
        break;
    case 1:
        if (++task->data[1] > 1)
        {
            task->data[1] = 0;
            gSprites[task->data[15]].invisible ^= 1;

            if (task->data[14])
            {
                task->data[14] += task->data[13];
                gSprites[task->data[15]].pos2.x = task->data[14];
            }
            else
                task->data[0]++;

        }
        break;
    case 2:
        if (++task->data[1] > 1)
        {
            task->data[1] = 0;
            gSprites[task->data[15]].invisible ^= 1;

            if (++task->data[2] == 8)
                task->data[0]++;
        }
        break;
    case 3:
        gSprites[task->data[15]].invisible = 0;
        DestroyAnimVisualTask(taskId);
    }
}

void sub_810AFCC(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    switch(task->data[0])
    {
    case 0:
        task->data[1] = GetBattlerSide(gBattleAnimAttacker) == B_SIDE_PLAYER ? 1 : -1;

        switch (gBattleAnimArgs[0])
        {
        case 0:
            task->data[3] = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_X_2);
            task->data[5] = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_Y_PIC_OFFSET);
            task->data[4] = (task->data[1] * 128) + 120;
            break;
        case 4:
            task->data[3] = 120 - (task->data[1] * 128);
            task->data[5] = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y_PIC_OFFSET);
            task->data[4] = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X_2) - (task->data[1] * 32);
            break;
        default:
            if ((gBattleAnimArgs[0] & 1) != 0)
            {
                task->data[3] = 256;
                task->data[4] = -16;
            }
            else
            {
                task->data[3] = -16;
                task->data[4] = 256;
            }

            if (task->data[1] == 1)
            {
                task->data[5] = 80 - gBattleAnimArgs[0] * 10;
            }
            else
            {
                u16 temp;
                task->data[5] = gBattleAnimArgs[0] * 10 + 40;
                temp = task->data[3];
                task->data[3] = task->data[4];
                task->data[4] = temp;
            }
        }

        if (task->data[3] < task->data[4])
        {
            task->data[1] = 1;
            task->data[6] = 0;
        }
        else
        {
            task->data[1] = -1;
            task->data[6] = 3;
        }

        task->data[0]++;
        break;
    case 1:
        if (++task->data[2] > 0)
        {
            task->data[2] = 0;
            if (sub_810B154(task, taskId) || sub_810B154(task, taskId))
                task->data[0]++;
        }
        break;
    case 2:
        if (task->data[7] == 0)
            DestroyAnimVisualTask(taskId);
    }
}

static bool8 sub_810B154(struct Task *task, u8 taskId)
{
    u8 spriteId = CreateSprite(&gUnknown_08595A00, task->data[3], task->data[5], 35);
    if (spriteId != MAX_SPRITES)
    {
        gSprites[spriteId].data[6] = taskId;
        gSprites[spriteId].data[7] = 7;
        task->data[7]++;
    }

    task->data[6] += task->data[1];
    if (task->data[6] < 0)
        task->data[6] = 3;

    if (task->data[6] > 3)
        task->data[6] = 0;

    task->data[3] += task->data[1] * 16;

    if ((task->data[1] == 1 && task->data[3] >= task->data[4])
        || (task->data[1] == -1 && task->data[3] <= task->data[4]))
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

static void sub_810B1F0(struct Sprite *sprite)
{
    if (++sprite->data[0] > 12)
    {
        gTasks[sprite->data[6]].data[sprite->data[7]]--;
        FreeOamMatrix(sprite->oam.matrixNum);
        DestroySprite(sprite);
    }
}

static void sub_810B23C(struct Sprite *sprite)
{
    switch (sprite->data[0])
    {
    case 0:
        sprite->pos1.x = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_X_2);
        sprite->pos1.y = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_Y_PIC_OFFSET);
        StartSpriteAffineAnim(sprite, 2);
        sprite->data[0]++;
        break;
    case 1:
        if (sprite->affineAnimEnded)
            DestroySpriteAndMatrix(sprite);
        break;
    }
}

void sub_810B29C(u8 taskId)
{
    struct Task *task = &gTasks[taskId];
    u8 target = GetAnimBattlerId(gBattleAnimArgs[0]);

    switch (task->data[0])
    {
    case 0:
        task->data[6] = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_X_2);
        task->data[7] = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_Y_PIC_OFFSET);
        task->data[8] = 4;
        task->data[10] = GetBattlerSpriteCoord(target, BATTLER_COORD_X_2);
        task->data[9] = (task->data[10] - task->data[6]) / 5;
        task->data[4] = 7;
        task->data[5] = -1;
        task->data[11] = 12;
        task->data[12] = BattleAnimAdjustPanning(task->data[11] - 76);
        task->data[13] = BattleAnimAdjustPanning(SOUND_PAN_TARGET);
        task->data[14] = task->data[12];
        task->data[15] = (task->data[13] - task->data[12]) / 3;
        task->data[0]++;
        break;
    case 1:
        if (++task->data[1] > 0)
        {
            task->data[1] = 0;
            if (sub_810B430(task, taskId))
            {
                if (task->data[2] == 5)
                    task->data[0] = 3;
                else
                    task->data[0]++;
            }
        }

        if (task->data[11])
            task->data[11]--;
        break;
    case 2:
        if (task->data[11])
            task->data[11]--;

        if (++task->data[1] > 4)
        {
            task->data[1] = 0;
            if (task->data[2] & 1)
            {
                task->data[7] = 4;
                task->data[8] = 68;
                task->data[4] = 0;
                task->data[5] = 1;
            }
            else
            {
                task->data[7] = 68;
                task->data[8] = 4;
                task->data[4] = 7;
                task->data[5] = -1;
            }

            if (task->data[11])
                task->data[0] = 4;
            else
                task->data[0] = 1;
        }
        break;
    case 3:
        if (task->data[3] == 0)
            DestroyAnimVisualTask(taskId);
        break;
    case 4:
        if (task->data[11])
            task->data[11]--;
        else
            task->data[0] = 1;
        break;
    }
}

static bool8 sub_810B430(struct Task *task, u8 taskId)
{
    u8 spriteId = CreateSprite(&gUnknown_08595A30, task->data[6], task->data[7], 35);
    if (spriteId != MAX_SPRITES)
    {
        gSprites[spriteId].oam.tileNum += task->data[4];
        task->data[4] += task->data[5];
        if (task->data[4] < 0)
            task->data[4] = 7;
        if (task->data[4] > 7)
            task->data[4] = 0;

        gSprites[spriteId].data[6] = taskId;
        gSprites[spriteId].data[7] = 3;
        task->data[3]++;
    }

    if (task->data[4] == 0 && task->data[5] > 0)
    {
        task->data[14] += task->data[15];
        PlaySE12WithPanning(SE_W085, task->data[14]);
    }

    if ((task->data[5] < 0 && task->data[7] <= task->data[8])
        || (task->data[5] > 0 && task->data[7] >= task->data[8]))
    {
        task->data[2]++;
        task->data[6] += task->data[9];
        return TRUE;
    }
    else
    {
        task->data[7] += task->data[5] * 8;
        return FALSE;
    }
}

static void sub_810B51C(struct Sprite *sprite)
{
    if (++sprite->data[0] > 12)
    {
        gTasks[sprite->data[6]].data[sprite->data[7]]--;
        DestroySprite(sprite);
    }
}

void sub_810B55C(u8 taskId)
{
    struct Task *task = &gTasks[taskId];
    u8 target = GetAnimBattlerId(gBattleAnimArgs[0]);

    switch (task->data[0])
    {
    case 0:
        task->data[15] = GetBattlerSpriteCoord(target, BATTLER_COORD_Y) + 32;
        task->data[14] = task->data[15];
        while (task->data[14] > 16)
        {
            task->data[14] -= 32;
        }

        task->data[13] = GetBattlerSpriteCoord(target, BATTLER_COORD_X_2);
        task->data[12] = GetBattlerSpriteSubpriority(target) - 2;
        task->data[0]++;
        break;
    case 1:
        if (++task->data[1] > 1)
        {
            task->data[1] = 0;
            if (sub_810B614(task, taskId))
                task->data[0]++;
        }
        break;
    case 2:
        if (task->data[10] == 0)
            DestroyAnimVisualTask(taskId);
        break;
    }
}

bool8 sub_810B614(struct Task *task, u8 taskId)
{
    u8 spriteId = CreateSprite(&gUnknown_085956C0, task->data[13], task->data[14], task->data[12]);

    if (spriteId != MAX_SPRITES)
    {
        gSprites[spriteId].callback = sub_810B684;
        gSprites[spriteId].data[6] = taskId;
        gSprites[spriteId].data[7] = 10;
        task->data[10]++;
    }
    if (task->data[14] >= task->data[15])
        return TRUE;
    task->data[14] += 32;
    return FALSE;
}

static void sub_810B684(struct Sprite *sprite)
{
    if (sprite->animEnded)
    {
        gTasks[sprite->data[6]].data[sprite->data[7]]--;
        DestroySprite(sprite);
    }
}
