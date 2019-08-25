#include "global.h"
#include "battle_anim.h"
#include "gpu_regs.h"
#include "graphics.h"
#include "palette.h"
#include "sound.h"
#include "task.h"
#include "trig.h"
#include "constants/rgb.h"
#include "constants/songs.h"

extern const union AnimCmd *const gUnknown_085950E0[];
extern const union AnimCmd *const gUnknown_085954D0[];

void sub_81109F0(struct Sprite *);
void sub_8110AB4(struct Sprite *);
void AnimDirtParticleAcrossScreen(struct Sprite *);
void AnimRaiseSprite(struct Sprite *);
void sub_81110A4(u8 taskId);
void sub_811131C(struct Sprite *);
void sub_8111388(struct Sprite *);
void sub_8111418(struct Sprite *);
void sub_8111444(struct Sprite *);
void sub_8110B38(struct Sprite *);
static void sub_8110A70(struct Sprite *);
static void sub_8110B80(struct Sprite *sprite);
static void sub_8110CB0(u8 taskId);
static void sub_8111214(struct Task *task);
static u8 sub_811135C(void);
static void sub_81113C8(struct Sprite *sprite);
static void sub_811149C(struct Sprite *sprite);
static void AnimPowerGemOrbitFastStep(struct Sprite *sprite);
void AnimPowerGemOrbitFast(struct Sprite *sprite);
static void AnimPowerGemScatterStep(struct Sprite *sprite);
void AnimPowerGemScatter(struct Sprite *sprite);
static void AnimStealthRockStep2(struct Sprite *sprite);
static void AnimStealthRockStep(struct Sprite *sprite);
void AnimStealthRock(struct Sprite *sprite);

const union AnimCmd gUnknown_08596AE0[] =
{
    ANIMCMD_FRAME(32, 1),
    ANIMCMD_END,
};

const union AnimCmd gUnknown_08596AE8[] =
{
    ANIMCMD_FRAME(48, 1),
    ANIMCMD_END,
};

const union AnimCmd gUnknown_08596AF0[] =
{
    ANIMCMD_FRAME(64, 1),
    ANIMCMD_END,
};

const union AnimCmd *const gUnknown_08596AF8[] =
{
    gUnknown_08596AE0,
    gUnknown_08596AE8,
    gUnknown_08596AF0,
};

const struct SpriteTemplate gUnknown_08596B04 =
{
    .tileTag = ANIM_TAG_ROCKS,
    .paletteTag = ANIM_TAG_ROCKS,
    .oam = &gUnknown_08524914,
    .anims = gUnknown_08596AF8,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_81109F0,
};

const struct SpriteTemplate gUnknown_08596B1C =
{
    .tileTag = ANIM_TAG_ROCKS,
    .paletteTag = ANIM_TAG_ROCKS,
    .oam = &gUnknown_08524914,
    .anims = gUnknown_08596AF8,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_8110AB4,
};

const struct SpriteTemplate gUnknown_08596B34 =
{
    .tileTag = ANIM_TAG_MUD_SAND,
    .paletteTag = ANIM_TAG_MUD_SAND,
    .oam = &gUnknown_08524904,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_8110B38,
};

const union AffineAnimCmd gUnknown_08596B4C[] =
{
    AFFINEANIMCMD_FRAME(0xC0, 0xC0, 0, 0),
    AFFINEANIMCMD_FRAME(0x2, 0xFFFD, 0, 5),
    AFFINEANIMCMD_FRAME(0xFFFE, 0x3, 0, 5),
    AFFINEANIMCMD_JUMP(1),
};

const union AffineAnimCmd *const gUnknown_08596B6C[] =
{
    gUnknown_08596B4C,
};

const struct SpriteTemplate gUnknown_08596B70 =
{
    .tileTag = ANIM_TAG_WATER_ORB,
    .paletteTag = ANIM_TAG_WATER_ORB,
    .oam = &gUnknown_08524A8C,
    .anims = gUnknown_085950E0,
    .images = NULL,
    .affineAnims = gUnknown_08596B6C,
    .callback = sub_8110B38,
};

const struct SpriteTemplate gUnknown_08596B88 =
{
    .tileTag = ANIM_TAG_SMALL_EMBER,
    .paletteTag = ANIM_TAG_SMALL_EMBER,
    .oam = &gUnknown_08524914,
    .anims = gUnknown_085954D0,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_8110B38,
};

const struct SpriteTemplate gBattleAnimSpriteTemplate_8596BA0 =
{
    .tileTag = ANIM_TAG_FLYING_DIRT,
    .paletteTag = ANIM_TAG_FLYING_DIRT,
    .oam = &gUnknown_08524934,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimDirtParticleAcrossScreen,
};

const struct Subsprite gUnknown_08596BB8[] =
{
    {.x = -16, .y = 0, .shape = ST_OAM_H_RECTANGLE, .size = 2, .tileOffset = 0, .priority = 1},
    {.x =  16, .y = 0, .shape = ST_OAM_H_RECTANGLE, .size = 2, .tileOffset = 8, .priority = 1},
};

const struct SubspriteTable gUnknown_08596BC0[] =
{
    {ARRAY_COUNT(gUnknown_08596BB8), gUnknown_08596BB8},
};

const union AnimCmd gUnknown_08596BC8[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

const union AnimCmd gUnknown_08596BD0[] =
{
    ANIMCMD_FRAME(16, 1),
    ANIMCMD_END,
};

const union AnimCmd gUnknown_08596BD8[] =
{
    ANIMCMD_FRAME(32, 1),
    ANIMCMD_END,
};

const union AnimCmd gUnknown_08596BE0[] =
{
    ANIMCMD_FRAME(48, 1),
    ANIMCMD_END,
};

const union AnimCmd gUnknown_08596BE8[] =
{
    ANIMCMD_FRAME(64, 1),
    ANIMCMD_END,
};

const union AnimCmd gUnknown_08596BF0[] =
{
    ANIMCMD_FRAME(80, 1),
    ANIMCMD_END,
};

const union AnimCmd *const gUnknown_08596BF8[] =
{
    gUnknown_08596BC8,
    gUnknown_08596BD0,
};

const union AnimCmd *const gUnknown_08596C00[] =
{
    gUnknown_08596BD8,
    gUnknown_08596BE0,
};

const union AnimCmd *const gUnknown_08596C08[] =
{
    gUnknown_08596BE8,
    gUnknown_08596BF0,
};

const struct SpriteTemplate gUnknown_08596C10 =
{
    .tileTag = ANIM_TAG_ROCKS,
    .paletteTag = ANIM_TAG_ROCKS,
    .oam = &gUnknown_08524914,
    .anims = gUnknown_08596BF8,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimRaiseSprite,
};

const struct SpriteTemplate gUnknown_08596C28 =
{
    .tileTag = ANIM_TAG_MUD_SAND,
    .paletteTag = ANIM_TAG_MUD_SAND,
    .oam = &gUnknown_08524904,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_811131C,
};

const struct SpriteTemplate gUnknown_08596C40 =
{
    .tileTag = ANIM_TAG_ROCKS,
    .paletteTag = ANIM_TAG_ROCKS,
    .oam = &gUnknown_08524914,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_811131C,
};

const struct SpriteTemplate gUnknown_08596C58 =
{
    .tileTag = ANIM_TAG_ROCKS,
    .paletteTag = ANIM_TAG_ROCKS,
    .oam = &gUnknown_08524914,
    .anims = gUnknown_08596BF8,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_8111388,
};

const union AffineAnimCmd gUnknown_08596C70[] =
{
    AFFINEANIMCMD_FRAME(0x0, 0x0, -5, 5),
    AFFINEANIMCMD_JUMP(0),
};

const union AffineAnimCmd gUnknown_08596C80[] =
{
    AFFINEANIMCMD_FRAME(0x0, 0x0, 5, 5),
    AFFINEANIMCMD_JUMP(0),
};

const union AffineAnimCmd *const gUnknown_08596C90[] =
{
    gUnknown_08596C70,
    gUnknown_08596C80,
};

const struct SpriteTemplate gUnknown_08596C98 =
{
    .tileTag = ANIM_TAG_ROCKS,
    .paletteTag = ANIM_TAG_ROCKS,
    .oam = &gUnknown_08524974,
    .anims = gUnknown_08596BF8,
    .images = NULL,
    .affineAnims = gUnknown_08596C90,
    .callback = sub_8111418,
};

const struct SpriteTemplate gUnknown_08596CB0 =
{
    .tileTag = ANIM_TAG_ROCKS,
    .paletteTag = ANIM_TAG_ROCKS,
    .oam = &gUnknown_08524974,
    .anims = gUnknown_08596BF8,
    .images = NULL,
    .affineAnims = gUnknown_08596C90,
    .callback = sub_8111444,
};

const struct SpriteTemplate gUnknown_08596CC8 =
{
    .tileTag = ANIM_TAG_ROCKS,
    .paletteTag = ANIM_TAG_ROCKS,
    .oam = &gUnknown_08524914,
    .anims = gUnknown_08596C08,
    .images = NULL,
    .affineAnims = gUnknown_08596C90,
    .callback = AnimMoveTwisterParticle,
};

const struct SpriteTemplate gUnknown_08596CE0 =
{
    .tileTag = ANIM_TAG_ROCKS,
    .paletteTag = ANIM_TAG_ROCKS,
    .oam = &gUnknown_08524974,
    .anims = gUnknown_08596C00,
    .images = NULL,
    .affineAnims = gUnknown_08596C90,
    .callback = sub_80A8EE4,
};

const union AffineAnimCmd gPowerGemScatterAffineAnimCmd[] =
{
    AFFINEANIMCMD_FRAME(0x80, 0x80, 0, 0),
    AFFINEANIMCMD_FRAME(0x8, 0x8, 0, 1),
    AFFINEANIMCMD_JUMP(1),
};

const union AffineAnimCmd *const gPowerGemScatterAffineAnims[] =
{
    gPowerGemScatterAffineAnimCmd,
};

const union AffineAnimCmd gPowerGemOrbAffineAnimCmd[] =
{
    AFFINEANIMCMD_FRAME(0x80, 0x80, 0, 0),
    AFFINEANIMCMD_FRAME(0x8, 0x8, 0, 1),
    AFFINEANIMCMD_JUMP(1),
};

const union AffineAnimCmd *const gPowerGemOrbAffineAnims[] =
{
    gPowerGemOrbAffineAnimCmd,
};

const struct SpriteTemplate gPowerGemScatterSpriteTemplate =
{
    .tileTag = ANIM_TAG_POWER_GEM,
    .paletteTag = ANIM_TAG_POWER_GEM,
    .oam = &gUnknown_085249CC,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gPowerGemScatterAffineAnims,
    .callback = AnimPowerGemScatter,
};

const struct SpriteTemplate gPowerGemOrbSpriteTemplate =
{
    .tileTag = ANIM_TAG_POWER_GEM,
    .paletteTag = ANIM_TAG_POWER_GEM,
    .oam = &gUnknown_0852496C,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gPowerGemOrbAffineAnims,
    .callback = AnimPowerGemOrbitFast,
};

const struct SpriteTemplate gStoneEdgeSpriteTemplate =
{
    .tileTag = ANIM_TAG_STONE_EDGE,
    .paletteTag = ANIM_TAG_STONE_EDGE,
    .oam = &gUnknown_08524914,
    .anims = gUnknown_085954D0,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_8110B38,
};

const struct SpriteTemplate gStealthRockSpriteTemplate =
{
    .tileTag = ANIM_TAG_STEALTH_ROCK,
    .paletteTag = ANIM_TAG_STEALTH_ROCK,
    .oam = &gUnknown_0852490C,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimStealthRock,
};

void AnimStealthRock(struct Sprite *sprite)
{
    u16 x;
    u16 y;

    InitSpritePosToAnimAttacker(sprite, TRUE);
    SetAverageBattlerPositions(gBattleAnimTarget, FALSE, &x, &y);

    if (GetBattlerSide(gBattleAnimAttacker) != B_SIDE_PLAYER)
        gBattleAnimArgs[2] = -gBattleAnimArgs[2];

    sprite->data[0] = gBattleAnimArgs[4];
    sprite->data[2] = x + gBattleAnimArgs[2];
    sprite->data[4] = y + gBattleAnimArgs[3];
    sprite->data[5] = -50;

    InitAnimArcTranslation(sprite);
    sprite->callback = AnimStealthRockStep;
}

static void AnimStealthRockStep(struct Sprite *sprite)
{
    if (TranslateAnimHorizontalArc(sprite))
    {
        sprite->data[0] = 30;
        sprite->data[1] = 0;
        sprite->callback = WaitAnimForDuration;
        StoreSpriteCallbackInData6(sprite, AnimStealthRockStep2);
    }
}

static void AnimStealthRockStep2(struct Sprite *sprite)
{
    if (sprite->data[1] & 1)
        sprite->invisible ^= 1;

    if (++sprite->data[1] == 16)
        DestroyAnimSprite(sprite);
}

void AnimPowerGemScatter(struct Sprite *sprite)
{
    sprite->pos1.x = GetBattlerSpriteCoord(gBattleAnimAttacker, 2);
    sprite->pos1.y = GetBattlerSpriteCoord(gBattleAnimAttacker, 3);
    sprite->data[0] = Sin(gBattleAnimArgs[0], 10);
    sprite->data[1] = Cos(gBattleAnimArgs[0], 7);
    sprite->callback = AnimPowerGemScatterStep;
}

static void AnimPowerGemScatterStep(struct Sprite *sprite)
{
    sprite->pos2.x += sprite->data[0];
    sprite->pos2.y += sprite->data[1];
    if (sprite->pos1.x + sprite->pos2.x + 16 > 272u || sprite->pos1.y + sprite->pos2.y > 160 || sprite->pos1.y + sprite->pos2.y < -16)
        DestroyAnimSprite(sprite);
}

void AnimPowerGemOrbitFast(struct Sprite *sprite)
{
    sprite->pos1.x = GetBattlerSpriteCoord(gBattleAnimAttacker, 2);
    sprite->pos1.y = GetBattlerSpriteCoord(gBattleAnimAttacker, 3);
    sprite->affineAnimPaused = 1;
    sprite->data[0] = gBattleAnimArgs[0];
    sprite->data[1] = gBattleAnimArgs[1];
    sprite->data[7] = GetBattlerSpriteSubpriority(gBattleAnimAttacker);
    sprite->callback = AnimPowerGemOrbitFastStep;
    sprite->callback(sprite);
}

static void AnimPowerGemOrbitFastStep(struct Sprite *sprite)
{
    if (sprite->data[1] >= 64 && sprite->data[1] <= 191)
        sprite->subpriority = sprite->data[7] + 1;
    else
        sprite->subpriority = sprite->data[7] - 1;

    sprite->pos2.x = Sin(sprite->data[1], sprite->data[2] >> 8);
    sprite->pos2.y = Cos(sprite->data[1], sprite->data[3] >> 8);
    sprite->data[1] = (sprite->data[1] + 9) & 0xFF;
    switch (sprite->data[5])
    {
    case 1:
        sprite->data[2] -= 0x400;
        sprite->data[3] -= 0x100;
        if (++sprite->data[4] == sprite->data[0])
        {
            sprite->data[5] = 2;
            return;
        }
        break;
    case 0:
        sprite->data[2] += 0x400;
        sprite->data[3] += 0x100;
        if (++sprite->data[4] == sprite->data[0])
        {
            sprite->data[4] = 0;
            sprite->data[5] = 1;
        }
        break;
    }

    if ((u16)gBattleAnimArgs[7] == 0xFFFF)
        DestroyAnimSprite(sprite);
}

void sub_81109F0(struct Sprite *sprite)
{
    if (gBattleAnimArgs[3] != 0)
        SetAverageBattlerPositions(gBattleAnimTarget, 0, &sprite->pos1.x, &sprite->pos1.y);

    sprite->pos1.x += gBattleAnimArgs[0];
    sprite->pos1.y += 14;

    StartSpriteAnim(sprite, gBattleAnimArgs[1]);
    AnimateSprite(sprite);

    sprite->data[0] = 0;
    sprite->data[1] = 0;
    sprite->data[2] = 4;
    sprite->data[3] = 16;
    sprite->data[4] = -70;
    sprite->data[5] = gBattleAnimArgs[2];

    StoreSpriteCallbackInData6(sprite, sub_8110A70);
    sprite->callback = TranslateSpriteInEllipseOverDuration;
    sprite->callback(sprite);
}

static void sub_8110A70(struct Sprite *sprite)
{
    sprite->pos1.x += sprite->data[5];

    sprite->data[0] = 192;
    sprite->data[1] = sprite->data[5];
    sprite->data[2] = 4;
    sprite->data[3] = 32;
    sprite->data[4] = -24;

    StoreSpriteCallbackInData6(sprite, DestroySpriteAndMatrix);
    sprite->callback = TranslateSpriteInEllipseOverDuration;
    sprite->callback(sprite);
}

void sub_8110AB4(struct Sprite *sprite)
{
    StartSpriteAnim(sprite, gBattleAnimArgs[5]);
    AnimateSprite(sprite);

    if (GetBattlerSide(gBattleAnimAttacker) != B_SIDE_PLAYER)
        sprite->pos1.x -= gBattleAnimArgs[0];
    else
        sprite->pos1.x += gBattleAnimArgs[0];

    sprite->pos1.y += gBattleAnimArgs[1];

    sprite->data[0] = gBattleAnimArgs[4];
    sprite->data[1] = sprite->pos1.x;
    sprite->data[2] = sprite->pos1.x + gBattleAnimArgs[2];
    sprite->data[3] = sprite->pos1.y;
    sprite->data[4] = sprite->pos1.y + gBattleAnimArgs[3];

    InitSpriteDataForLinearTranslation(sprite);
    sprite->data[3] = 0;
    sprite->data[4] = 0;

    sprite->callback = TranslateSpriteLinearFixedPoint;
    StoreSpriteCallbackInData6(sprite, DestroySpriteAndMatrix);
}

void sub_8110B38(struct Sprite *sprite)
{
    if (gBattleAnimArgs[6] == 0)
        InitSpritePosToAnimAttacker(sprite, 0);
    else
        InitSpritePosToAnimTarget(sprite, FALSE);

    sprite->data[0] = gBattleAnimArgs[3];
    sprite->data[1] = gBattleAnimArgs[2];
    sprite->data[2] = gBattleAnimArgs[4];
    sprite->data[3] = gBattleAnimArgs[5];

    sprite->callback = sub_8110B80;
}

static void sub_8110B80(struct Sprite *sprite)
{
    sprite->data[4] += sprite->data[1];
    sprite->pos2.y = -(sprite->data[4] >> 8);
    sprite->pos2.x = Sin(sprite->data[5], sprite->data[3]);
    sprite->data[5] = (sprite->data[5] + sprite->data[2]) & 0xFF;

    if (--sprite->data[0] == -1)
    {
        DestroyAnimSprite(sprite);
    }
}

void AnimTask_LoadSandstormBackground(u8 taskId)
{
    int var0;
    struct BattleAnimBgData animBg;

    var0 = 0;
    SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG1 | BLDCNT_TGT2_ALL | BLDCNT_EFFECT_BLEND);
    SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(0, 16));
    SetAnimBgAttribute(1, BG_ANIM_PRIORITY, 1);
    SetAnimBgAttribute(1, BG_ANIM_SCREEN_SIZE, 0);

    if (!IsContest())
        SetAnimBgAttribute(1, BG_ANIM_CHAR_BASE_BLOCK, 1);

    gBattle_BG1_X = 0;
    gBattle_BG1_Y = 0;
    SetGpuReg(REG_OFFSET_BG1HOFS, gBattle_BG1_X);
    SetGpuReg(REG_OFFSET_BG1VOFS, gBattle_BG1_Y);

    sub_80A6B30(&animBg);
    AnimLoadCompressedBgGfx(animBg.bgId, gUnknown_08D8D58C, animBg.tilesOffset);
    sub_80A6D60(&animBg, gUnknown_08D8D410, 0);
    LoadCompressedPalette(gBattleAnimSpritePal_FlyingDirt, animBg.paletteId * 16, 32);

    if (gBattleAnimArgs[0] && GetBattlerSide(gBattleAnimAttacker) != B_SIDE_PLAYER)
        var0 = 1;

    gTasks[taskId].data[0] = var0;
    gTasks[taskId].func = sub_8110CB0;
}

static void sub_8110CB0(u8 taskId)
{
    struct BattleAnimBgData animBg;

    if (gTasks[taskId].data[0] == 0)
        gBattle_BG1_X += -6;
    else
        gBattle_BG1_X += 6;

    gBattle_BG1_Y += -1;

    switch (gTasks[taskId].data[12])
    {
    case 0:
        if (++gTasks[taskId].data[10] == 4)
        {
            gTasks[taskId].data[10] = 0;
            gTasks[taskId].data[11]++;
            SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(gTasks[taskId].data[11], 16 - gTasks[taskId].data[11]));
            if (gTasks[taskId].data[11] == 7)
            {
                gTasks[taskId].data[12]++;
                gTasks[taskId].data[11] = 0;
            }
        }
        break;
    case 1:
        if (++gTasks[taskId].data[11] == 101)
        {
            gTasks[taskId].data[11] = 7;
            gTasks[taskId].data[12]++;
        }
        break;
    case 2:
        if (++gTasks[taskId].data[10] == 4)
        {
            gTasks[taskId].data[10] = 0;
            gTasks[taskId].data[11]--;
            SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(gTasks[taskId].data[11], 16 - gTasks[taskId].data[11]));
            if (gTasks[taskId].data[11] == 0)
            {
                gTasks[taskId].data[12]++;
                gTasks[taskId].data[11] = 0;
            }
        }
        break;
    case 3:
        sub_80A6B30(&animBg);
        sub_80A6C68(animBg.bgId);
        gTasks[taskId].data[12]++;
        break;
    case 4:
        if (!IsContest())
            SetAnimBgAttribute(1, BG_ANIM_CHAR_BASE_BLOCK, 0);

        gBattle_BG1_X = 0;
        gBattle_BG1_Y = 0;
        SetGpuReg(REG_OFFSET_BLDCNT, 0);
        SetGpuReg(REG_OFFSET_BLDALPHA, 0);
        SetAnimBgAttribute(1, BG_ANIM_PRIORITY, 1);
        DestroyAnimVisualTask(taskId);
        break;
    }
}

// Animates the sprites that fly diagonally across the screen
// in Sandstorm and Heat Wave.
// arg 0: initial y pixel offset
// arg 1: projectile speed
// arg 2: y pixel drop
// arg 3: ??? unknown (possibly a color bit)
void AnimDirtParticleAcrossScreen(struct Sprite *sprite)
{
    if (sprite->data[0] == 0)
    {
        if (gBattleAnimArgs[3] != 0 && GetBattlerSide(gBattleAnimAttacker) != B_SIDE_PLAYER)
        {
            sprite->pos1.x = 304;
            gBattleAnimArgs[1] = -gBattleAnimArgs[1];
            sprite->data[5] = 1;
            sprite->oam.matrixNum = ST_OAM_HFLIP;
        }
        else
        {
            sprite->pos1.x = -64;
        }

        sprite->pos1.y = gBattleAnimArgs[0];
        SetSubspriteTables(sprite, gUnknown_08596BC0);
        sprite->data[1] = gBattleAnimArgs[1];
        sprite->data[2] = gBattleAnimArgs[2];
        sprite->data[0]++;
    }
    else
    {
        sprite->data[3] += sprite->data[1];
        sprite->data[4] += sprite->data[2];
        sprite->pos2.x += (sprite->data[3] >> 8);
        sprite->pos2.y += (sprite->data[4] >> 8);
        sprite->data[3] &= 0xFF;
        sprite->data[4] &= 0xFF;

        if (sprite->data[5] == 0)
        {
            if (sprite->pos1.x + sprite->pos2.x > 272)
            {
                sprite->callback = DestroyAnimSprite;
            }
        }
        else if (sprite->pos1.x + sprite->pos2.x < -32)
        {
            sprite->callback = DestroyAnimSprite;
        }
    }
}

// Animates the rising rocks in Ancient Power.
// arg 0: initial x pixel offset
// arg 1: initial y pixel offset
// arg 2: terminal y offset
// arg 3: duration
// arg 4: sprite size [1,5]
void AnimRaiseSprite(struct Sprite *sprite)
{
    StartSpriteAnim(sprite, gBattleAnimArgs[4]);
    InitSpritePosToAnimAttacker(sprite, 0);

    sprite->data[0] = gBattleAnimArgs[3];
    sprite->data[2] = sprite->pos1.x;
    sprite->data[4] = sprite->pos1.y + gBattleAnimArgs[2];

    sprite->callback = StartAnimLinearTranslation;
    StoreSpriteCallbackInData6(sprite, DestroyAnimSprite);
}

void sub_8110F74(u8 taskId)
{
    u16 var0, var1, var2, var3;
    u8 var4;
    int var5;
    s16 pan1, pan2;
    struct Task *task;

    task = &gTasks[taskId];

    var0 = GetBattlerSpriteCoord(gBattleAnimAttacker, 2);
    var1 = GetBattlerSpriteCoord(gBattleAnimAttacker, 1) + 24;
    var2 = GetBattlerSpriteCoord(gBattleAnimTarget, 2);
    var3 = GetBattlerSpriteCoord(gBattleAnimTarget, 1) + 24;

    if (BATTLE_PARTNER(gBattleAnimAttacker) == gBattleAnimTarget)
        var3 = var1;

    var4 = sub_811135C();
    if (var4 == 1)
        task->data[8] = 32;
    else
        task->data[8] = 48 - (var4 * 8);

    task->data[0] = 0;
    task->data[11] = 0;
    task->data[9] = 0;
    task->data[12] = 1;

    var5 = task->data[8];
    if (var5 < 0)
        var5 += 7;

    task->data[10] = (var5 >> 3) - 1;

    task->data[2] = var0 * 8;
    task->data[3] = var1 * 8;
    task->data[4] = ((var2 - var0) * 8) / task->data[8];
    task->data[5] = ((var3 - var1) * 8) / task->data[8];
    task->data[6] = 0;
    task->data[7] = 0;

    pan1 = BattleAnimAdjustPanning(-64);
    pan2 = BattleAnimAdjustPanning(63);

    task->data[13] = pan1;
    task->data[14] = (pan2 - pan1) / task->data[8];
    task->data[1] = var4;
    task->data[15] = GetAnimBattlerSpriteId(0);

    task->func = sub_81110A4;
}

void sub_81110A4(u8 taskId)
{
    struct Task *task;

    task = &gTasks[taskId];

    switch (task->data[0])
    {
    case 0:
        task->data[6] -= task->data[4];
        task->data[7] -= task->data[5];
        gSprites[task->data[15]].pos2.x = task->data[6] >> 3;
        gSprites[task->data[15]].pos2.y = task->data[7] >> 3;

        if (++task->data[9] == 10)
        {
            task->data[11] = 20;
            task->data[0]++;
        }

        PlaySE12WithPanning(SE_W029, task->data[13]);
        break;
    case 1:
        if (--task->data[11] == 0)
            task->data[0]++;
        break;
    case 2:
        if (--task->data[9] != 0)
        {
            task->data[6] += task->data[4];
            task->data[7] += task->data[5];
        }
        else
        {
            task->data[6] = 0;
            task->data[7] = 0;
            task->data[0]++;
        }

        gSprites[task->data[15]].pos2.x = task->data[6] >> 3;
        gSprites[task->data[15]].pos2.y = task->data[7] >> 3;
        break;
    case 3:
        task->data[2] += task->data[4];
        task->data[3] += task->data[5];
        if (++task->data[9] >= task->data[10])
        {
            task->data[9] = 0;
            sub_8111214(task);
            task->data[13] += task->data[14];
            PlaySE12WithPanning(SE_W091, task->data[13]);
        }

        if (--task->data[8] == 0)
        {
            task->data[0]++;
        }
        break;
    case 4:
        if (task->data[11] == 0)
            DestroyAnimVisualTask(taskId);
        break;
    }
}

static void sub_8111214(struct Task *task)
{
    const struct SpriteTemplate *spriteTemplate;
    int var0;
    u16 x, y;
    u8 spriteId;

    switch (task->data[1])
    {
    case 1:
        spriteTemplate = &gUnknown_08596C28;
        var0 = 0;
        break;
    case 2:
    case 3:
        spriteTemplate = &gUnknown_08596C40;
        var0 = 80;
        break;
    case 4:
        spriteTemplate = &gUnknown_08596C40;
        var0 = 64;
        break;
    case 5:
        spriteTemplate = &gUnknown_08596C40;
        var0 = 48;
        break;
    default:
        return;
    }

    x = task->data[2] >> 3;
    y = task->data[3] >> 3;
    x += (task->data[12] * 4);

    spriteId = CreateSprite(spriteTemplate, x, y, 35);
    if (spriteId != MAX_SPRITES)
    {
        gSprites[spriteId].data[0] = 18;
        gSprites[spriteId].data[2] = ((task->data[12] * 20) + x) + (task->data[1] * 3);
        gSprites[spriteId].data[4] = y;
        gSprites[spriteId].data[5] = -16 - (task->data[1] * 2);
        gSprites[spriteId].oam.tileNum += var0;

        InitAnimArcTranslation(&gSprites[spriteId]);
        task->data[11]++;
    }

    task->data[12] *= -1;
}

void sub_811131C(struct Sprite *sprite)
{
    if (TranslateAnimHorizontalArc(sprite))
    {
        u8 taskId = FindTaskIdByFunc(sub_81110A4);
        if (taskId != 0xFF)
            gTasks[taskId].data[11]--;

        DestroySprite(sprite);
    }
}

static u8 sub_811135C(void)
{
    u8 retVal = gAnimDisableStructPtr->rolloutTimerStartValue - gAnimDisableStructPtr->rolloutTimer;
    u8 var0 = retVal - 1;
    if (var0 > 4)
        retVal = 1;

    return retVal;
}

void sub_8111388(struct Sprite *sprite)
{
    StartSpriteAnim(sprite, gBattleAnimArgs[4]);

    sprite->pos2.x = gBattleAnimArgs[0];
    sprite->data[2] = gBattleAnimArgs[1];
    sprite->data[3] -= gBattleAnimArgs[2];
    sprite->data[0] = 3;
    sprite->data[1] = gBattleAnimArgs[3];
    sprite->callback = sub_81113C8;
    sprite->invisible = 1;
}

static void sub_81113C8(struct Sprite *sprite)
{
    sprite->invisible = 0;
    if (sprite->data[3] != 0)
    {
        sprite->pos2.y = sprite->data[2] + sprite->data[3];
        sprite->data[3] += sprite->data[0];
        sprite->data[0]++;
        if (sprite->data[3] > 0)
        {
            sprite->data[3] = 0;
        }
    }
    else
    {
        if (--sprite->data[1] == 0)
            DestroyAnimSprite(sprite);
    }
}

void sub_8111418(struct Sprite *sprite)
{
    if (GetBattlerSide(gBattleAnimAttacker) == B_SIDE_OPPONENT)
        StartSpriteAffineAnim(sprite, 1);

    TranslateAnimSpriteToTargetMonLocation(sprite);
}

void sub_8111444(struct Sprite *sprite)
{
    sprite->pos1.x = GetBattlerSpriteCoord(gBattleAnimTarget, 0);
    sprite->pos1.y = GetBattlerSpriteCoord(gBattleAnimTarget, 1);
    sprite->pos1.x += gBattleAnimArgs[0];
    sprite->pos1.y += gBattleAnimArgs[1];

    sprite->data[1] = gBattleAnimArgs[0];
    sprite->data[2] = gBattleAnimArgs[1];
    sprite->data[5] = gBattleAnimArgs[2];

    StartSpriteAnim(sprite, gBattleAnimArgs[3]);
    sprite->callback = sub_811149C;
}

static void sub_811149C(struct Sprite *sprite)
{
    sprite->data[0] += 8;
    sprite->data[3] += sprite->data[1];
    sprite->data[4] += sprite->data[2];

    sprite->pos2.x += sprite->data[3] / 40;
    sprite->pos2.y -= Sin(sprite->data[0], sprite->data[5]);

    if (sprite->data[0] > 140)
        DestroyAnimSprite(sprite);
}

void AnimTask_GetSeismicTossDamageLevel(u8 taskId)
{
    if (gAnimMoveDmg < 33)
        gBattleAnimArgs[7] = 0;
    if ((u32)gAnimMoveDmg - 33 < 33)
        gBattleAnimArgs[7] = 1;
    if (gAnimMoveDmg > 65)
        gBattleAnimArgs[7] = 2;

    DestroyAnimVisualTask(taskId);
}

void sub_811152C(u8 taskId)
{
    if (gTasks[taskId].data[0] == 0)
    {
        sub_80A6DAC(0);
        gTasks[taskId].data[1] = 200;
    }

    gBattle_BG3_Y += gTasks[taskId].data[1] / 10;
    gTasks[taskId].data[1] -= 3;

    if (gTasks[taskId].data[0] == 120)
    {
        sub_80A6DAC(1);
        DestroyAnimVisualTask(taskId);
    }

    gTasks[taskId].data[0]++;
}

void sub_8111590(u8 taskId)
{
    if (gTasks[taskId].data[0] == 0)
    {
        sub_80A6DAC(0);
        gTasks[taskId].data[0]++;
        gTasks[taskId].data[2] = gBattle_BG3_Y;
    }

    gTasks[taskId].data[1] += 80;
    gTasks[taskId].data[1] &= 0xFF;
    gBattle_BG3_Y = gTasks[taskId].data[2] + Cos(4, gTasks[taskId].data[1]);

    if (gBattleAnimArgs[7] == 0xFFF)
    {
        gBattle_BG3_Y = 0;
        sub_80A6DAC(1);
        DestroyAnimVisualTask(taskId);
    }
}
