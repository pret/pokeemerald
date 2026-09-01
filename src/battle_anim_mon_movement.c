#include "global.h"
#include "battle.h"
#include "battle_anim.h"
#include "sprite.h"
#include "task.h"
#include "trig.h"

static void AnimTask_ShakeMon_Step(u8 taskId);
static void AnimTask_ShakeMon2_Step(u8 taskId);
static void AnimTask_ShakeMonInPlace_Step(u8 taskId);
static void AnimTask_ShakeAndSinkMon_Step(u8 taskId);
static void AnimTask_TranslateMonElliptical_Step(u8 taskId);
static void DoHorizontalLunge(struct Sprite *sprite);
static void ReverseHorizontalLungeDirection(struct Sprite *sprite);
static void DoVerticalDip(struct Sprite *sprite);
static void ReverseVerticalDipDirection(struct Sprite *sprite);
static void SlideMonToOriginalPos(struct Sprite *sprite);
static void SlideMonToOriginalPosPartner(struct Sprite *sprite);
static void SlideMonToOriginalPos_Step(struct Sprite *sprite);
static void SlideMonToOffset(struct Sprite *sprite);
static void SlideMonToOffsetPartner(struct Sprite *sprite);
static void SlideMonToOffsetAndBack(struct Sprite *sprite);
static void SlideMonToOffsetAndBack_End(struct Sprite *sprite);
static void AnimTask_WindUpLunge_Step1(u8 taskId);
static void AnimTask_WindUpLunge_Step2(u8 taskId);
static void AnimTask_DuckDownHop_Step1(u8 taskId);
static void AnimTask_DuckDownHop_Step2(u8 taskId);
static void AnimTask_SwayMonStep(u8 taskId);
static void AnimTask_ScaleMonAndRestore_Step(u8 taskId);
static void AnimTask_RotateMonSpriteToSide_Step(u8 taskId);
static void AnimTask_ShakeTargetBasedOnMovePowerOrDmg_Step(u8 taskId);
static void AnimTask_SlideOffScreen_Step(u8 taskId);
static void AnimTask_RotateVerticallyStep(u8 taskId);

const struct SpriteTemplate gHorizontalLungeSpriteTemplate =
{
    .tileTag = 0,
    .paletteTag = 0,
    .oam = &gDummyOamData,
    .callback = DoHorizontalLunge,
};

const struct SpriteTemplate gVerticalDipSpriteTemplate =
{
    .tileTag = 0,
    .paletteTag = 0,
    .oam = &gDummyOamData,
    .callback = DoVerticalDip,
};

const struct SpriteTemplate gSlideMonToOriginalPosSpriteTemplate =
{
    .tileTag = 0,
    .paletteTag = 0,
    .oam = &gDummyOamData,
    .callback = SlideMonToOriginalPos,
};

const struct SpriteTemplate gSlideMonToOriginalPosPartnerSpriteTemplate =
{
    .tileTag = 0,
    .paletteTag = 0,
    .oam = &gDummyOamData,
    .callback = SlideMonToOriginalPosPartner,
};

const struct SpriteTemplate gSlideMonToOffsetSpriteTemplate =
{
    .tileTag = 0,
    .paletteTag = 0,
    .oam = &gDummyOamData,
    .callback = SlideMonToOffset,
};

const struct SpriteTemplate gSlideMonToOffsetPartnerSpriteTemplate =
{
    .tileTag = 0,
    .paletteTag = 0,
    .oam = &gDummyOamData,
    .callback = SlideMonToOffsetPartner,
};

const struct SpriteTemplate gSlideMonToOffsetAndBackSpriteTemplate =
{
    .tileTag = 0,
    .paletteTag = 0,
    .oam = &gDummyOamData,
    .callback = SlideMonToOffsetAndBack,
};

// Task to facilitate simple shaking of a Pokémon's picture in battle.
// The shaking alternates between the original position and the target position.
// arg 0: anim battler
// arg 1: x pixel offset
// arg 2: y pixel offset
// arg 3: num times to shake
// arg 4: frame delay
void AnimTask_ShakeMon(u8 taskId)
{
    enum AnimBattler animBattler = gBattleAnimArgs[0];
    u8 spriteId = GetAnimBattlerSpriteId(animBattler);
    if (spriteId == SPRITE_NONE)
    {
        DestroyAnimVisualTask(taskId);
        return;
    }
    gSprites[spriteId].x2 = gBattleAnimArgs[1];
    gSprites[spriteId].y2 = gBattleAnimArgs[2];
    gTasks[taskId].data[0] = spriteId;
    gTasks[taskId].data[1] = gBattleAnimArgs[3];
    gTasks[taskId].data[2] = gBattleAnimArgs[4];
    gTasks[taskId].data[3] = gBattleAnimArgs[4];
    gTasks[taskId].data[4] = gBattleAnimArgs[1];
    gTasks[taskId].data[5] = gBattleAnimArgs[2];
    gTasks[taskId].func = AnimTask_ShakeMon_Step;
    gTasks[taskId].func(taskId);
}

static void AnimTask_ShakeMon_Step(u8 taskId)
{
    if (gTasks[taskId].data[3] == 0)
    {
        if (gSprites[gTasks[taskId].data[0]].x2 == 0)
        {
            gSprites[gTasks[taskId].data[0]].x2 = gTasks[taskId].data[4];
        }
        else
        {
            gSprites[gTasks[taskId].data[0]].x2 = 0;
        }
        if (gSprites[gTasks[taskId].data[0]].y2 == 0)
        {
            gSprites[gTasks[taskId].data[0]].y2 = gTasks[taskId].data[5];
        }
        else
        {
            gSprites[gTasks[taskId].data[0]].y2 = 0;
        }
        gTasks[taskId].data[3] = gTasks[taskId].data[2];
        if (--gTasks[taskId].data[1] == 0)
        {
            gSprites[gTasks[taskId].data[0]].x2 = 0;
            gSprites[gTasks[taskId].data[0]].y2 = 0;
            DestroyAnimVisualTask(taskId);
            return;
        }
    }
    else
    {
        gTasks[taskId].data[3]--;
    }
}

// Task to facilitate simple shaking of a Pokémon's picture in battle.
// The shaking alternates between the positive and negative versions of the specified pixel offsets.
// arg 0: anim battler
// arg 1: x pixel offset
// arg 2: y pixel offset
// arg 3: num times to shake
// arg 4: frame delay
void AnimTask_ShakeMon2(u8 taskId)
{
    u8 spriteId;
    bool8 abort = FALSE;
    enum BattlerId battler;
    enum AnimBattler animBattler = gBattleAnimArgs[0];

    if (animBattler < ANIM_PLAYER_LEFT)
    {
        spriteId = GetAnimBattlerSpriteId(animBattler);
        if (spriteId == SPRITE_NONE)
            abort = TRUE;
    }
    else if (animBattler != ANIM_ATTACKER_FORCE)
    {
        switch (animBattler)
        {
        case ANIM_PLAYER_LEFT:
            battler = GetBattlerAtPosition(B_POSITION_PLAYER_LEFT);
            break;
        case ANIM_PLAYER_RIGHT:
            battler = GetBattlerAtPosition(B_POSITION_PLAYER_RIGHT);
            break;
        case ANIM_OPPONENT_LEFT:
            battler = GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT);
            break;
        case ANIM_OPPONENT_RIGHT:
        default:
            battler = GetBattlerAtPosition(B_POSITION_OPPONENT_RIGHT);
            break;
        }

        if (IsBattlerSpriteVisible(battler) == FALSE)
            abort = TRUE;

        spriteId = gBattlerSpriteIds[battler];
    }
    else
    {
        spriteId = gBattlerSpriteIds[gBattleAnimAttacker];
    }

    if (abort)
    {
        DestroyAnimVisualTask(taskId);
        return;
    }

    gSprites[spriteId].x2 = gBattleAnimArgs[1];
    gSprites[spriteId].y2 = gBattleAnimArgs[2];
    gTasks[taskId].data[0] = spriteId;
    gTasks[taskId].data[1] = gBattleAnimArgs[3];
    gTasks[taskId].data[2] = gBattleAnimArgs[4];
    gTasks[taskId].data[3] = gBattleAnimArgs[4];
    gTasks[taskId].data[4] = gBattleAnimArgs[1];
    gTasks[taskId].data[5] = gBattleAnimArgs[2];
    gTasks[taskId].func = AnimTask_ShakeMon2_Step;
    gTasks[taskId].func(taskId);
}

static void AnimTask_ShakeMon2_Step(u8 taskId)
{
    if (gTasks[taskId].data[3] == 0)
    {
        if (gSprites[gTasks[taskId].data[0]].x2 == gTasks[taskId].data[4])
            gSprites[gTasks[taskId].data[0]].x2 = -gTasks[taskId].data[4];
        else
            gSprites[gTasks[taskId].data[0]].x2 = gTasks[taskId].data[4];

        if (gSprites[gTasks[taskId].data[0]].y2 == gTasks[taskId].data[5])
            gSprites[gTasks[taskId].data[0]].y2 = -gTasks[taskId].data[5];
        else
            gSprites[gTasks[taskId].data[0]].y2 = gTasks[taskId].data[5];

        gTasks[taskId].data[3] = gTasks[taskId].data[2];
        if (--gTasks[taskId].data[1] == 0)
        {
            gSprites[gTasks[taskId].data[0]].x2 = 0;
            gSprites[gTasks[taskId].data[0]].y2 = 0;
            DestroyAnimVisualTask(taskId);
            return;
        }
    }
    else
    {
        gTasks[taskId].data[3]--;
    }
}

// Task to facilitate simple shaking of a Pokémon's picture in battle.
// The shaking alternates between the positive and negative versions of the specified pixel offsets
// with respect to the current location of the mon's picture.
// arg 0: battler
// arg 1: x offset
// arg 2: y offset
// arg 3: num shakes
// arg 4: delay
void AnimTask_ShakeMonInPlace(u8 taskId)
{
    enum AnimBattler animBattler = gBattleAnimArgs[0];
    u8 spriteId = GetAnimBattlerSpriteId(animBattler);
    if (spriteId == SPRITE_NONE)
    {
        DestroyAnimVisualTask(taskId);
        return;
    }

    gSprites[spriteId].x2 += gBattleAnimArgs[1];
    gSprites[spriteId].y2 += gBattleAnimArgs[2];
    gTasks[taskId].data[0] = spriteId;
    gTasks[taskId].data[1] = 0;
    gTasks[taskId].data[2] = gBattleAnimArgs[3];
    gTasks[taskId].data[3] = 0;
    gTasks[taskId].data[4] = gBattleAnimArgs[4];
    gTasks[taskId].data[5] = gBattleAnimArgs[1] * 2;
    gTasks[taskId].data[6] = gBattleAnimArgs[2] * 2;
    gTasks[taskId].func = AnimTask_ShakeMonInPlace_Step;
    gTasks[taskId].func(taskId);
}

static void AnimTask_ShakeMonInPlace_Step(u8 taskId)
{
    if (gTasks[taskId].data[3] == 0)
    {
        if (gTasks[taskId].data[1] & 1)
        {
            gSprites[gTasks[taskId].data[0]].x2 += gTasks[taskId].data[5];
            gSprites[gTasks[taskId].data[0]].y2 += gTasks[taskId].data[6];
        }
        else
        {
            gSprites[gTasks[taskId].data[0]].x2 -= gTasks[taskId].data[5];
            gSprites[gTasks[taskId].data[0]].y2 -= gTasks[taskId].data[6];
        }
        gTasks[taskId].data[3] = gTasks[taskId].data[4];
        if (++gTasks[taskId].data[1] >= gTasks[taskId].data[2])
        {
            if (gTasks[taskId].data[1] & 1)
            {
                gSprites[gTasks[taskId].data[0]].x2 += gTasks[taskId].data[5] / 2;
                gSprites[gTasks[taskId].data[0]].y2 += gTasks[taskId].data[6] / 2;
            }
            else
            {
                gSprites[gTasks[taskId].data[0]].x2 -= gTasks[taskId].data[5] / 2;
                gSprites[gTasks[taskId].data[0]].y2 -= gTasks[taskId].data[6] / 2;
            }
            DestroyAnimVisualTask(taskId);
            return;
        }
    }
    else
    {
        gTasks[taskId].data[3]--;
    }
}

// Shakes a mon bg horizontally and moves it downward linearly.
// arg 0: battler
// arg 1: x offset
// arg 2: frame delay between each movement
// arg 3: downward speed (subpixel)
// arg 4: duration
void AnimTask_ShakeAndSinkMon(u8 taskId)
{
    enum AnimBattler animBattler = gBattleAnimArgs[0];
    u8 spriteId = GetAnimBattlerSpriteId(animBattler);

    if (spriteId == SPRITE_NONE)
    {
        DestroyAnimVisualTask(taskId);
        return;
    }

    gSprites[spriteId].x2 = gBattleAnimArgs[1];
    gTasks[taskId].data[0] = spriteId;
    gTasks[taskId].data[1] = gBattleAnimArgs[1];
    gTasks[taskId].data[2] = gBattleAnimArgs[2];
    gTasks[taskId].data[3] = gBattleAnimArgs[3];
    gTasks[taskId].data[4] = gBattleAnimArgs[4];
    gTasks[taskId].func = AnimTask_ShakeAndSinkMon_Step;
    gTasks[taskId].func(taskId);
}

static void AnimTask_ShakeAndSinkMon_Step(u8 taskId)
{
    u8 spriteId = gTasks[taskId].data[0];
    s16 x = gTasks[taskId].data[1];
    if (gTasks[taskId].data[2] == gTasks[taskId].data[8]++)
    {
        gTasks[taskId].data[8] = 0;
        if (gSprites[spriteId].x2 == x)
            x = -x;

        gSprites[spriteId].x2 += x;
    }

    gTasks[taskId].data[1] = x;
    gTasks[taskId].data[9] += gTasks[taskId].data[3];
    gSprites[spriteId].y2 = gTasks[taskId].data[9] >> 8;
    if (--gTasks[taskId].data[4] == 0)
    {
        DestroyAnimVisualTask(taskId);
        return;
    }
}

// Moves a mon bg picture along an elliptical path that begins
// and ends at the mon's origin location.
// arg 0: battler
// arg 1: ellipse width
// arg 2: ellipse height
// arg 3: num loops
// arg 4: speed (valid values are 0-5)
void AnimTask_TranslateMonElliptical(u8 taskId)
{
    u8 i;
    u8 wavePeriod = 1;
    enum AnimBattler animBattler = gBattleAnimArgs[0];
    u8 spriteId = GetAnimBattlerSpriteId(animBattler);
    if (gBattleAnimArgs[4] > 5)
        gBattleAnimArgs[4] = 5;

    for (i = 0; i < gBattleAnimArgs[4]; i++)
    {
        wavePeriod <<= 1;
    }

    gTasks[taskId].data[0] = spriteId;
    gTasks[taskId].data[1] = gBattleAnimArgs[1];
    gTasks[taskId].data[2] = gBattleAnimArgs[2];
    gTasks[taskId].data[3] = gBattleAnimArgs[3];
    gTasks[taskId].data[4] = wavePeriod;
    gTasks[taskId].func = AnimTask_TranslateMonElliptical_Step;
    gTasks[taskId].func(taskId);
}

static void AnimTask_TranslateMonElliptical_Step(u8 taskId)
{
    u8 spriteId = gTasks[taskId].data[0];
    gSprites[spriteId].x2 = Sin(gTasks[taskId].data[5], gTasks[taskId].data[1]);
    gSprites[spriteId].y2 = -Cos(gTasks[taskId].data[5], gTasks[taskId].data[2]);
    gSprites[spriteId].y2 += gTasks[taskId].data[2];
    gTasks[taskId].data[5] += gTasks[taskId].data[4];
    gTasks[taskId].data[5] &= 0xff;

    if (gTasks[taskId].data[5] == 0)
        gTasks[taskId].data[3]--;

    if (gTasks[taskId].data[3] == 0)
    {
        gSprites[spriteId].x2 = 0;
        gSprites[spriteId].y2 = 0;
        DestroyAnimVisualTask(taskId);
        return;
    }
}

// Moves a mon bg picture along an elliptical path that begins
// and ends at the mon's origin location. Reverses the direction
// of the path if it's not on the player's side of the battle.
// arg 0: battler
// arg 1: ellipse width
// arg 2: ellipse height
// arg 3: num loops
// arg 4: speed (valid values are 0-5)
void AnimTask_TranslateMonEllipticalRespectSide(u8 taskId)
{
    if (!IsOnPlayerSide(gBattleAnimAttacker))
        gBattleAnimArgs[1] = -gBattleAnimArgs[1];

    AnimTask_TranslateMonElliptical(taskId);
}

// Performs a simple horizontal lunge, where the mon moves
// horizontally, and then moves back in the opposite direction.
// arg 0: duration of single lunge direction
// arg 1: x pixel delta that is applied each frame
static void DoHorizontalLunge(struct Sprite *sprite)
{
    sprite->invisible = TRUE;
    if (!IsOnPlayerSide(gBattleAnimAttacker))
        sprite->data[1] = -gBattleAnimArgs[1];
    else
        sprite->data[1] = gBattleAnimArgs[1];

    sprite->data[0] = gBattleAnimArgs[0];
    sprite->data[2] = 0;
    sprite->data[3] = gBattlerSpriteIds[gBattleAnimAttacker];
    sprite->data[4] = gBattleAnimArgs[0];
    StoreSpriteCallbackInData6(sprite, ReverseHorizontalLungeDirection);
    sprite->callback = TranslateSpriteLinearById;
}

static void ReverseHorizontalLungeDirection(struct Sprite *sprite)
{
    sprite->data[0] = sprite->data[4];
    sprite->data[1] = -sprite->data[1];
    sprite->callback = TranslateSpriteLinearById;
    StoreSpriteCallbackInData6(sprite, DestroyAnimSprite);
}

// Performs a simple vertical dipping motion, where moves vertically, and then
// moves back in the opposite direction.
// arg 0: duration of single dip direction
// arg 1: y pixel delta that is applied each frame
// arg 2: battler
static void DoVerticalDip(struct Sprite *sprite)
{
    u8 spriteId;
    sprite->invisible = TRUE;
    enum AnimBattler animBattler = gBattleAnimArgs[2];
    spriteId = GetAnimBattlerSpriteId(animBattler);
    sprite->data[0] = gBattleAnimArgs[0];
    sprite->data[1] = 0;
    sprite->data[2] = gBattleAnimArgs[1];
    sprite->data[3] = spriteId;
    sprite->data[4] = gBattleAnimArgs[0];
    StoreSpriteCallbackInData6(sprite, ReverseVerticalDipDirection);
    sprite->callback = TranslateSpriteLinearById;
}

static void ReverseVerticalDipDirection(struct Sprite *sprite)
{
    sprite->data[0] = sprite->data[4];
    sprite->data[2] = -sprite->data[2];
    sprite->callback = TranslateSpriteLinearById;
    StoreSpriteCallbackInData6(sprite, DestroyAnimSprite);
}

// Linearly slides a mon's bg picture back to its original sprite position.
// The sprite parameter is a dummy sprite used for facilitating the movement with its callback.
// arg 0: 1 = target or 0 = attacker
// arg 1: direction (0 = horizontal and vertical, 1 = horizontal only, 2 = vertical only)
// arg 2: duration
static void SlideMonToOriginalPos(struct Sprite *sprite)
{
    u32 monSpriteId;
    if (!gBattleAnimArgs[0])
        monSpriteId = gBattlerSpriteIds[gBattleAnimAttacker];
    else
        monSpriteId = gBattlerSpriteIds[gBattleAnimTarget];

    sprite->data[0] = gBattleAnimArgs[2];
    sprite->data[1] = gSprites[monSpriteId].x + gSprites[monSpriteId].x2;
    sprite->data[2] = gSprites[monSpriteId].x;
    sprite->data[3] = gSprites[monSpriteId].y + gSprites[monSpriteId].y2;
    sprite->data[4] = gSprites[monSpriteId].y;
    InitSpriteDataForLinearTranslation(sprite);
    sprite->data[3] = 0;
    sprite->data[4] = 0;
    sprite->data[5] = gSprites[monSpriteId].x2;
    sprite->data[6] = gSprites[monSpriteId].y2;
    sprite->invisible = TRUE;

    if (gBattleAnimArgs[1] == 1)
        sprite->data[2] = 0;
    else if (gBattleAnimArgs[1] == 2)
        sprite->data[1] = 0;

    sprite->data[7] = gBattleAnimArgs[1];
    sprite->data[7] |= monSpriteId << 8;
    sprite->callback = SlideMonToOriginalPos_Step;
}

static void SlideMonToOriginalPosPartner(struct Sprite *sprite)
{
    u32 monSpriteId;
    if (!gBattleAnimArgs[0])
        monSpriteId = gBattlerSpriteIds[GetPartnerBattler(gBattleAnimAttacker)];
    else
        monSpriteId = gBattlerSpriteIds[GetPartnerBattler(gBattleAnimTarget)];

    sprite->data[0] = gBattleAnimArgs[2];
    sprite->data[1] = gSprites[monSpriteId].x + gSprites[monSpriteId].x2;
    sprite->data[2] = gSprites[monSpriteId].x;
    sprite->data[3] = gSprites[monSpriteId].y + gSprites[monSpriteId].y2;
    sprite->data[4] = gSprites[monSpriteId].y;
    InitSpriteDataForLinearTranslation(sprite);
    sprite->data[3] = 0;
    sprite->data[4] = 0;
    sprite->data[5] = gSprites[monSpriteId].x2;
    sprite->data[6] = gSprites[monSpriteId].y2;
    sprite->invisible = TRUE;

    if (gBattleAnimArgs[1] == 1)
        sprite->data[2] = 0;
    else if (gBattleAnimArgs[1] == 2)
        sprite->data[1] = 0;

    sprite->data[7] = gBattleAnimArgs[1];
    sprite->data[7] |= monSpriteId << 8;
    sprite->callback = SlideMonToOriginalPos_Step;
}

static void SlideMonToOriginalPos_Step(struct Sprite *sprite)
{
    s8 monSpriteId;
    u8 lo;
    struct Sprite *monSprite;

    lo = sprite->data[7] & 0xff;
    monSpriteId = sprite->data[7] >> 8;
    monSprite = &gSprites[monSpriteId];
    if (sprite->data[0] == 0)
    {
        if (lo < 2)
            monSprite->x2 = 0;

        if (lo == 2 || lo == 0)
            monSprite->y2 = 0;

        DestroyAnimSprite(sprite);
    }
    else
    {
        sprite->data[0]--;
        sprite->data[3] += sprite->data[1];
        sprite->data[4] += sprite->data[2];
        monSprite->x2 = (s8)(sprite->data[3] >> 8) + sprite->data[5];
        monSprite->y2 = (s8)(sprite->data[4] >> 8) + sprite->data[6];
    }
}

// Linearly translates a mon to a target offset. The horizontal offset
// is mirrored for the opponent's Pokémon, and the vertical offset
// is only mirrored if arg 3 is set to 1.
// arg 0: 0 = attacker, 1 = target
// arg 1: target x pixel offset
// arg 2: target y pixel offset
// arg 3: mirror vertical translation for opposite battle side
// arg 4: duration
static void SlideMonToOffset(struct Sprite *sprite)
{
    enum BattlerId battler;
    u8 monSpriteId;
    if (!gBattleAnimArgs[0])
        battler = gBattleAnimAttacker;
    else
        battler = gBattleAnimTarget;

    monSpriteId = gBattlerSpriteIds[battler];
    if (!IsOnPlayerSide(battler))
    {
        gBattleAnimArgs[1] = -gBattleAnimArgs[1];
        if (gBattleAnimArgs[3] == 1)
        {
            gBattleAnimArgs[2] = -gBattleAnimArgs[2];
        }
    }

    sprite->data[0] = gBattleAnimArgs[4];
    sprite->data[1] = gSprites[monSpriteId].x;
    sprite->data[2] = gSprites[monSpriteId].x + gBattleAnimArgs[1];
    sprite->data[3] = gSprites[monSpriteId].y;
    sprite->data[4] = gSprites[monSpriteId].y + gBattleAnimArgs[2];
    InitSpriteDataForLinearTranslation(sprite);
    sprite->data[3] = 0;
    sprite->data[4] = 0;
    sprite->data[5] = monSpriteId;
    sprite->invisible = TRUE;
    StoreSpriteCallbackInData6(sprite, DestroyAnimSprite);
    sprite->callback = TranslateSpriteLinearByIdFixedPoint;
}

static void SlideMonToOffsetPartner(struct Sprite *sprite)
{
    enum BattlerId battler;
    u8 monSpriteId;
    if (!gBattleAnimArgs[0])
        battler = GetPartnerBattler(gBattleAnimAttacker);
    else
        battler = GetPartnerBattler(gBattleAnimTarget);

    monSpriteId = gBattlerSpriteIds[battler];
    if (!IsOnPlayerSide(battler))
    {
        gBattleAnimArgs[1] = -gBattleAnimArgs[1];
        if (gBattleAnimArgs[3] == 1)
        {
            gBattleAnimArgs[2] = -gBattleAnimArgs[2];
        }
    }

    sprite->data[0] = gBattleAnimArgs[4];
    sprite->data[1] = gSprites[monSpriteId].x;
    sprite->data[2] = gSprites[monSpriteId].x + gBattleAnimArgs[1];
    sprite->data[3] = gSprites[monSpriteId].y;
    sprite->data[4] = gSprites[monSpriteId].y + gBattleAnimArgs[2];
    InitSpriteDataForLinearTranslation(sprite);
    sprite->data[3] = 0;
    sprite->data[4] = 0;
    sprite->data[5] = monSpriteId;
    sprite->invisible = TRUE;
    StoreSpriteCallbackInData6(sprite, DestroyAnimSprite);
    sprite->callback = TranslateSpriteLinearByIdFixedPoint;
}

static void SlideMonToOffsetAndBack(struct Sprite *sprite)
{
    u8 spriteId;
    enum BattlerId battler;
    sprite->invisible = TRUE;

    if (gBattleAnimArgs[0] == ANIM_ATTACKER)
        battler = gBattleAnimAttacker;
    else
        battler = gBattleAnimTarget;

    spriteId = gBattlerSpriteIds[battler];
    if (!IsOnPlayerSide(battler))
    {
        gBattleAnimArgs[1] = -gBattleAnimArgs[1];
        if (gBattleAnimArgs[3] == 1)
        {
            gBattleAnimArgs[2] = -gBattleAnimArgs[2];
        }
    }
    sprite->data[0] = gBattleAnimArgs[4];
    sprite->data[1] = gSprites[spriteId].x + gSprites[spriteId].x2;
    sprite->data[2] = sprite->data[1] + gBattleAnimArgs[1];
    sprite->data[3] = gSprites[spriteId].y + gSprites[spriteId].y2;
    sprite->data[4] = sprite->data[3] + gBattleAnimArgs[2];
    InitSpriteDataForLinearTranslation(sprite);
    sprite->data[3] = gSprites[spriteId].x2 << 8;
    sprite->data[4] = gSprites[spriteId].y2 << 8;
    sprite->data[5] = spriteId;
    sprite->data[6] = gBattleAnimArgs[5];
    if (!gBattleAnimArgs[5])
    {
        StoreSpriteCallbackInData6(sprite, DestroyAnimSprite);
    }
    else
    {
        StoreSpriteCallbackInData6(sprite, SlideMonToOffsetAndBack_End);
    }
    sprite->callback = TranslateSpriteLinearByIdFixedPoint;
}


static void SlideMonToOffsetAndBack_End(struct Sprite *sprite)
{
    gSprites[sprite->data[5]].x2 = 0;
    gSprites[sprite->data[5]].y2 = 0;
    DestroyAnimSprite(sprite);
}

// Task to facilitate a two-part translation animation, in which the sprite
// is first translated in an arc to one position.  Then, it "lunges" to a target
// x offset.  Used in TAKE_DOWN, for example.
// arg 0: anim bank
// arg 1: horizontal speed (subpixel)
// arg 2: wave amplitude
// arg 3: first duration
// arg 4: delay before starting lunge
// arg 5: target x offset for lunge
// arg 6: lunge duration
void AnimTask_WindUpLunge(u8 taskId)
{
    s16 wavePeriod = 0x8000 / gBattleAnimArgs[3];
    enum AnimBattler animBattler = gBattleAnimArgs[0];
    if (!IsOnPlayerSide(gBattleAnimAttacker))
    {
        gBattleAnimArgs[1] = -gBattleAnimArgs[1];
        gBattleAnimArgs[5] = -gBattleAnimArgs[5];
    }
    gTasks[taskId].data[0] = GetAnimBattlerSpriteId(animBattler);
    gTasks[taskId].data[1] = (gBattleAnimArgs[1] << 8) / gBattleAnimArgs[3];
    gTasks[taskId].data[2] = gBattleAnimArgs[2];
    gTasks[taskId].data[3] = gBattleAnimArgs[3];
    gTasks[taskId].data[4] = gBattleAnimArgs[4];
    gTasks[taskId].data[5] = (gBattleAnimArgs[5] << 8) / gBattleAnimArgs[6];
    gTasks[taskId].data[6] = gBattleAnimArgs[6];
    gTasks[taskId].data[7] = wavePeriod;
    gTasks[taskId].func = AnimTask_WindUpLunge_Step1;
}

static void AnimTask_WindUpLunge_Step1(u8 taskId)
{
    u8 spriteId;
    spriteId = gTasks[taskId].data[0];
    gTasks[taskId].data[11] += gTasks[taskId].data[1];
    gSprites[spriteId].x2 = gTasks[taskId].data[11] >> 8;
    gSprites[spriteId].y2 = Sin((u8)(gTasks[taskId].data[10] >> 8), gTasks[taskId].data[2]);
    gTasks[taskId].data[10] += gTasks[taskId].data[7];
    if (--gTasks[taskId].data[3] == 0)
    {
        gTasks[taskId].func = AnimTask_WindUpLunge_Step2;
    }
}

static void AnimTask_WindUpLunge_Step2(u8 taskId)
{
    u8 spriteId;
    if (gTasks[taskId].data[4] > 0)
    {
        gTasks[taskId].data[4]--;
    }
    else
    {
        spriteId = gTasks[taskId].data[0];
        gTasks[taskId].data[12] += gTasks[taskId].data[5];
        gSprites[spriteId].x2 = (gTasks[taskId].data[12] >> 8) + (gTasks[taskId].data[11] >> 8);
        if (--gTasks[taskId].data[6] == 0)
        {
            DestroyAnimVisualTask(taskId);
            return;
        }
    }
}

// Task to facilitate a two-part translation animation, in which the sprite
// is first translated linearly down.  Then, it hops in an arc.
// Used for POUNCE.
// arg 0: anim bank
// arg 1: horizontal speed (subpixel)
// arg 2: wave amplitude
// arg 3: hop duration
// arg 4: delay before starting hop
// arg 5: target y offset for ducking
// arg 6: ducking duration

void AnimTask_DuckDownHop(u8 taskId)
{
    s16 wavePeriod = 0x8000 / gBattleAnimArgs[3];
    enum AnimBattler animBattler = gBattleAnimArgs[0];
    if (!IsOnPlayerSide(gBattleAnimAttacker))
    {
        gBattleAnimArgs[1] = -gBattleAnimArgs[1];
    }
    gTasks[taskId].data[0] = GetAnimBattlerSpriteId(animBattler);
    gTasks[taskId].data[1] = (gBattleAnimArgs[1] << 8) / gBattleAnimArgs[3];
    gTasks[taskId].data[2] = gBattleAnimArgs[2];
    gTasks[taskId].data[3] = gBattleAnimArgs[3];
    gTasks[taskId].data[4] = gBattleAnimArgs[4];
    gTasks[taskId].data[5] = (gBattleAnimArgs[5] << 8) / gBattleAnimArgs[6];
    gTasks[taskId].data[6] = gBattleAnimArgs[6];
    gTasks[taskId].data[7] = wavePeriod;
    gTasks[taskId].func = AnimTask_DuckDownHop_Step1;
}

static void AnimTask_DuckDownHop_Step1(u8 taskId)
{
    u8 spriteId;

    spriteId = gTasks[taskId].data[0];
    gTasks[taskId].data[12] += gTasks[taskId].data[5];
    gSprites[spriteId].y2 = (gTasks[taskId].data[12] >> 8);
    if (--gTasks[taskId].data[6] == 0)
    {
        gTasks[taskId].func = AnimTask_DuckDownHop_Step2;
    }
}

static void AnimTask_DuckDownHop_Step2(u8 taskId)
{
    u8 spriteId;
    if (gTasks[taskId].data[4] > 0)
    {
        gTasks[taskId].data[4]--;
    }
    else
    {
        spriteId = gTasks[taskId].data[0];
        gTasks[taskId].data[11] += gTasks[taskId].data[1];
        gSprites[spriteId].x2 = gTasks[taskId].data[11] >> 8;
        gSprites[spriteId].y2 = Sin((u8)(gTasks[taskId].data[10] >> 8), gTasks[taskId].data[2]) + (gTasks[taskId].data[12] >> 8);
        gTasks[taskId].data[10] += gTasks[taskId].data[7];
        if (--gTasks[taskId].data[3] == 0)
        {
            DestroyAnimVisualTask(taskId);
            return;
        }
    }
}

// To move a mon off-screen when pushed out by Roar/Whirlwind
void AnimTask_SlideOffScreen(u8 taskId)
{
    u8 spriteId;
    enum AnimBattler animBattler = gBattleAnimArgs[0];
    switch (animBattler)
    {
    case ANIM_ATTACKER:
    case ANIM_TARGET:
        spriteId = GetAnimBattlerSpriteId(animBattler);
        break;
    case ANIM_ATK_PARTNER:
        if (!IsBattlerSpriteVisible(GetPartnerBattler(gBattleAnimAttacker)))
        {
            DestroyAnimVisualTask(taskId);
            return;
        }
        spriteId = gBattlerSpriteIds[GetPartnerBattler(gBattleAnimAttacker)];
        break;
    case ANIM_DEF_PARTNER:
        if (!IsBattlerSpriteVisible(GetPartnerBattler(gBattleAnimTarget)))
        {
            DestroyAnimVisualTask(taskId);
            return;
        }
        spriteId = gBattlerSpriteIds[GetPartnerBattler(gBattleAnimTarget)];
        break;
    default:
        DestroyAnimVisualTask(taskId);
        return;
    }
    gTasks[taskId].data[0] = spriteId;
    if (!IsOnPlayerSide(gBattleAnimTarget))
    {
        gTasks[taskId].data[1] = gBattleAnimArgs[1];
    }
    else
    {
        gTasks[taskId].data[1] = -gBattleAnimArgs[1];
    }
    gTasks[taskId].func = AnimTask_SlideOffScreen_Step;
}

static void AnimTask_SlideOffScreen_Step(u8 taskId)
{
    u8 spriteId = gTasks[taskId].data[0];
    gSprites[spriteId].x2 += gTasks[taskId].data[1];
    if (gSprites[spriteId].x2 + gSprites[spriteId].x < -32 || gSprites[spriteId].x2 + gSprites[spriteId].x > DISPLAY_WIDTH + 32)
    {
        DestroyAnimVisualTask(taskId);
        return;
    }
}

// Task that facilitates translating the mon bg picture back and forth
// in a swaying motion (uses Sine wave). It can sway either horizontally
// or vertically, but not both.
// arg 0: direction (0 = horizontal, 1 = vertical)
// arg 1: wave amplitude
// arg 2: wave period
// arg 3: num sways
// arg 4: which mon (0 = attacker, 1 = target)
void AnimTask_SwayMon(u8 taskId)
{
    u8 spriteId;
    enum AnimBattler animBattler = gBattleAnimArgs[4];
    if (!IsOnPlayerSide(gBattleAnimAttacker))
        gBattleAnimArgs[1] = -gBattleAnimArgs[1];

    spriteId = GetAnimBattlerSpriteId(animBattler);
    if (spriteId == 0xff)
    {
        DestroyAnimVisualTask(taskId);
        return;
    }
    gTasks[taskId].data[0] = gBattleAnimArgs[0];
    gTasks[taskId].data[1] = gBattleAnimArgs[1];
    gTasks[taskId].data[2] = gBattleAnimArgs[2];
    gTasks[taskId].data[3] = gBattleAnimArgs[3];
    gTasks[taskId].data[4] = spriteId;

    if (animBattler == ANIM_ATTACKER)
        gTasks[taskId].data[5] = gBattleAnimAttacker;
    else
        gTasks[taskId].data[5] = gBattleAnimTarget;

    gTasks[taskId].data[12] = 1;
    gTasks[taskId].func = AnimTask_SwayMonStep;
}

static void AnimTask_SwayMonStep(u8 taskId)
{
    s16 sineValue;
    u8 spriteId;
    int waveIndex;
    u16 sineIndex;

    spriteId = gTasks[taskId].data[4];
    sineIndex = gTasks[taskId].data[10] + gTasks[taskId].data[2];
    gTasks[taskId].data[10] = sineIndex;
    waveIndex = sineIndex >> 8;
    sineValue = Sin(waveIndex, gTasks[taskId].data[1]);

    if (gTasks[taskId].data[0] == 0)
    {
        gSprites[spriteId].x2 = sineValue;
    }
    else
    {
        if (IsOnPlayerSide(gTasks[taskId].data[5]))
        {
            gSprites[spriteId].y2 = (sineValue >= 0) ? sineValue : -sineValue;
        }
        else
        {
            gSprites[spriteId].y2 = (sineValue >= 0) ? -sineValue : sineValue;
        }
    }

    if (((waveIndex >= 0x80u) && (gTasks[taskId].data[11] == 0) && (gTasks[taskId].data[12] == 1))
        || ((waveIndex < 0x7fu) && (gTasks[taskId].data[11] == 1) && (gTasks[taskId].data[12] == 0)))
    {
        gTasks[taskId].data[11] ^= 1;
        gTasks[taskId].data[12] ^= 1;
        if (--gTasks[taskId].data[3] == 0)
        {
            gSprites[spriteId].x2 = 0;
            gSprites[spriteId].y2 = 0;
            DestroyAnimVisualTask(taskId);
            return;
        }
    }
}

// Scales a mon's sprite, and then scales back to its original dimensions.
// arg 0: x scale delta
// arg 1: y scale delta
// arg 2: duration
// arg 3: anim bank
// arg 4: sprite object mode
void AnimTask_ScaleMonAndRestore(u8 taskId)
{
    enum AnimBattler animBattler = gBattleAnimArgs[3];
    u8 spriteId = GetAnimBattlerSpriteId(animBattler);
    PrepareBattlerSpriteForRotScale(spriteId, gBattleAnimArgs[4]);
    gTasks[taskId].data[0] = gBattleAnimArgs[0];
    gTasks[taskId].data[1] = gBattleAnimArgs[1];
    gTasks[taskId].data[2] = gBattleAnimArgs[2];
    gTasks[taskId].data[3] = gBattleAnimArgs[2];
    gTasks[taskId].data[4] = spriteId;
    gTasks[taskId].data[10] = 0x100;
    gTasks[taskId].data[11] = 0x100;
    gTasks[taskId].func = AnimTask_ScaleMonAndRestore_Step;
}

static void AnimTask_ScaleMonAndRestore_Step(u8 taskId)
{
    u8 spriteId;
    gTasks[taskId].data[10] += gTasks[taskId].data[0];
    gTasks[taskId].data[11] += gTasks[taskId].data[1];
    spriteId = gTasks[taskId].data[4];
    SetSpriteRotScale(spriteId, gTasks[taskId].data[10], gTasks[taskId].data[11], 0);
    if (--gTasks[taskId].data[2] == 0)
    {
        if (gTasks[taskId].data[3] > 0)
        {
            gTasks[taskId].data[0] = -gTasks[taskId].data[0];
            gTasks[taskId].data[1] = -gTasks[taskId].data[1];
            gTasks[taskId].data[2] = gTasks[taskId].data[3];
            gTasks[taskId].data[3] = 0;
        }
        else
        {
            ResetSpriteRotScale(spriteId);
            DestroyAnimVisualTask(taskId);
            return;
        }
    }
}

void AnimTask_RotateMonSpriteToSide(u8 taskId)
{
    enum AnimBattler animBattler = gBattleAnimArgs[2];
    u8 spriteId = GetAnimBattlerSpriteId(animBattler);
    PrepareBattlerSpriteForRotScale(spriteId, ST_OAM_OBJ_NORMAL);
    gTasks[taskId].data[1] = 0;
    gTasks[taskId].data[2] = gBattleAnimArgs[0];
    if (gBattleAnimArgs[3] != 1)
    {
        gTasks[taskId].data[3] = 0;
    }
    else
    {
        gTasks[taskId].data[3] = gBattleAnimArgs[0] * gBattleAnimArgs[1];
    }
    gTasks[taskId].data[4] = gBattleAnimArgs[1];
    gTasks[taskId].data[5] = spriteId;
    gTasks[taskId].data[6] = gBattleAnimArgs[3];
    if (IsContest())
    {
        gTasks[taskId].data[7] = 1;
    }
    else
    {
        if (animBattler == ANIM_ATTACKER)
            gTasks[taskId].data[7] = IsOnPlayerSide(gBattleAnimAttacker);
        else
            gTasks[taskId].data[7] = IsOnPlayerSide(gBattleAnimTarget);
    }
    if (gTasks[taskId].data[7])
    {
        if (!IsContest())
        {
            gTasks[taskId].data[3] *= -1;
            gTasks[taskId].data[4] *= -1;
        }
    }
    gTasks[taskId].func = AnimTask_RotateMonSpriteToSide_Step;
}

// Rotates mon to side and back to original position. For Peck and when a held item activates
void AnimTask_RotateMonToSideAndRestore(u8 taskId)
{
    enum AnimBattler animBattler = gBattleAnimArgs[2];
    u8 spriteId = GetAnimBattlerSpriteId(animBattler);
    PrepareBattlerSpriteForRotScale(spriteId, ST_OAM_OBJ_NORMAL);
    gTasks[taskId].data[1] = 0;
    gTasks[taskId].data[2] = gBattleAnimArgs[0];
    if (animBattler == ANIM_ATTACKER)
    {
        if (!IsOnPlayerSide(gBattleAnimAttacker))
            gBattleAnimArgs[1] = -gBattleAnimArgs[1];
    }
    else
    {
        if (!IsOnPlayerSide(gBattleAnimTarget))
            gBattleAnimArgs[1] = -gBattleAnimArgs[1];
    }
    if (gBattleAnimArgs[3] != 1)
    {
        gTasks[taskId].data[3] = 0;
    }
    else
    {
        gTasks[taskId].data[3] = gBattleAnimArgs[0] * gBattleAnimArgs[1];
    }
    gTasks[taskId].data[4] = gBattleAnimArgs[1];
    gTasks[taskId].data[5] = spriteId;
    gTasks[taskId].data[6] = gBattleAnimArgs[3];
    gTasks[taskId].data[7] = 1;
    gTasks[taskId].data[3] *= -1;
    gTasks[taskId].data[4] *= -1;
    gTasks[taskId].func = AnimTask_RotateMonSpriteToSide_Step;
}

static void AnimTask_RotateMonSpriteToSide_Step(u8 taskId)
{
    gTasks[taskId].data[3] += gTasks[taskId].data[4];
    SetSpriteRotScale(gTasks[taskId].data[5], 0x100, 0x100, gTasks[taskId].data[3]);
    if (gTasks[taskId].data[7])
    {
        SetBattlerSpriteYOffsetFromRotation(gTasks[taskId].data[5]);
    }
    if (++gTasks[taskId].data[1] >= gTasks[taskId].data[2])
    {
        switch (gTasks[taskId].data[6])
        {
        case 1:
            ResetSpriteRotScale(gTasks[taskId].data[5]);
        case 0:
        default:
            DestroyAnimVisualTask(taskId);
            return;
        case 2:
            gTasks[taskId].data[1] = 0;
            gTasks[taskId].data[4] *= -1;
            gTasks[taskId].data[6] = 1;
            break;
        }
    }
}

void SetupShakeBattlerBasedOnMovePowerOrDmg(u8 taskId, u8 animBattlerId)
{
    if (!gBattleAnimArgs[0])
    {
        gTasks[taskId].data[15] = gAnimMovePower / 12;
        if (gTasks[taskId].data[15] < 1)
        {
            gTasks[taskId].data[15] = 1;
        }
        if (gTasks[taskId].data[15] > 16)
        {
            gTasks[taskId].data[15] = 16;
        }
    }
    else
    {
        gTasks[taskId].data[15] = gAnimMoveDmg / 12;
        if (gTasks[taskId].data[15] < 1)
        {
            gTasks[taskId].data[15] = 1;
        }
        if (gTasks[taskId].data[15] > 16)
        {
            gTasks[taskId].data[15] = 16;
        }
    }
    gTasks[taskId].data[14] = gTasks[taskId].data[15] / 2;
    gTasks[taskId].data[13] = gTasks[taskId].data[14] + (gTasks[taskId].data[15] & 1);
    gTasks[taskId].data[12] = 0;
    gTasks[taskId].data[10] = gBattleAnimArgs[3];
    gTasks[taskId].data[11] = gBattleAnimArgs[4];
    gTasks[taskId].data[7] = GetAnimBattlerSpriteId(animBattlerId);
    gTasks[taskId].data[8] = gSprites[gTasks[taskId].data[7]].x2;
    gTasks[taskId].data[9] = gSprites[gTasks[taskId].data[7]].y2;
    gTasks[taskId].data[0] = 0;
    gTasks[taskId].data[1] = gBattleAnimArgs[1];
    gTasks[taskId].data[2] = gBattleAnimArgs[2];
}

// args[0] - 0 if scale on move power, 1 if scale on move damage
// args[1] - delay before starting anim
// args[2] - duration of anim (after anim starts from above counter)
// args[3] - 1 if do horizontal shake
// args[4] - 1 if do vertical shake
void AnimTask_ShakeTargetPartnerBasedOnMovePowerOrDmg(u8 taskId)
{
    SetupShakeBattlerBasedOnMovePowerOrDmg(taskId, ANIM_DEF_PARTNER);
    gTasks[taskId].func = AnimTask_ShakeTargetBasedOnMovePowerOrDmg_Step;
}

void AnimTask_ShakeTargetBasedOnMovePowerOrDmg(u8 taskId)
{
    SetupShakeBattlerBasedOnMovePowerOrDmg(taskId, ANIM_TARGET);
    gTasks[taskId].func = AnimTask_ShakeTargetBasedOnMovePowerOrDmg_Step;
}

static void AnimTask_ShakeTargetBasedOnMovePowerOrDmg_Step(u8 taskId)
{
    struct Task *task = &gTasks[taskId];
    if (++task->data[0] > task->data[1])
    {
        task->data[0] = 0;
        task->data[12] = (task->data[12] + 1) & 1;
        if (task->data[10])
        {
            if (task->data[12])
            {
                gSprites[task->data[7]].x2 = task->data[8] + task->data[13];
            }
            else
            {
                gSprites[task->data[7]].x2 = task->data[8] - task->data[14];
            }
        }
        if (task->data[11])
        {
            if (task->data[12])
            {
                gSprites[task->data[7]].y2 = task->data[15];
            }
            else
            {
                gSprites[task->data[7]].y2 = 0;
            }
        }
        if (!--task->data[2])
        {
            gSprites[task->data[7]].x2 = 0;
            gSprites[task->data[7]].y2 = 0;
            DestroyAnimVisualTask(taskId);
            return;
        }
    }
}

#define tSpriteId   data[0]
#define tRotSpeed   data[1]
#define tRotCurr    data[2]
#define tPhase      data[3]
#define tFrames     data[4]
#define tPlayerSide data[5]
#define tRotMax     data[6] // Can't fully flip back sprites

void AnimTask_RotateVertically(u8 taskId)
{
    enum AnimBattler animBattler = gBattleAnimArgs[0];
    u8 spriteId = GetAnimBattlerSpriteId(animBattler);

    PrepareBattlerSpriteForRotScale(spriteId, ST_OAM_OBJ_NORMAL);
    gTasks[taskId].tSpriteId = spriteId;
    gTasks[taskId].tRotCurr = 0;
    gTasks[taskId].tPlayerSide = IsOnPlayerSide(GetAnimBattlerId(animBattler));
    gTasks[taskId].tRotMax = gTasks[taskId].tPlayerSide ? 0x1FFF : 0x7FFE;
    gTasks[taskId].tRotSpeed = gBattleAnimArgs[1];
    gTasks[taskId].func = AnimTask_RotateVerticallyStep;
}

static void AnimTask_RotateVerticallyStep(u8 taskId)
{
    switch (gTasks[taskId].tPhase)
    {
    case 0: // flip upside-down
        gTasks[taskId].tRotCurr = min(abs(gTasks[taskId].tRotCurr + gTasks[taskId].tRotSpeed), gTasks[taskId].tRotMax);
        SetSpriteRotScale(gTasks[taskId].tSpriteId, 0x100, 0x100, gTasks[taskId].tRotCurr);
        if (gTasks[taskId].tPlayerSide)
            SetBattlerSpriteYOffsetFromRotation(gTasks[taskId].tSpriteId);

        if (gTasks[taskId].tRotCurr == gTasks[taskId].tRotMax)
            gTasks[taskId].tPhase++;
        break;
    case 1: // Wait a bit
        if (++gTasks[taskId].tFrames >= 75)
            gTasks[taskId].tPhase++;
        break;
    case 2: // rotate back
        if (gTasks[taskId].tRotCurr < gTasks[taskId].tRotSpeed)
            gTasks[taskId].tRotCurr = 0;
        else
            gTasks[taskId].tRotCurr = gTasks[taskId].tRotCurr - gTasks[taskId].tRotSpeed;
        SetSpriteRotScale(gTasks[taskId].tSpriteId, 0x100, 0x100, gTasks[taskId].tRotCurr);
        if (gTasks[taskId].tPlayerSide)
            SetBattlerSpriteYOffsetFromRotation(gTasks[taskId].tSpriteId);

        if (gTasks[taskId].tRotCurr == 0)
            gTasks[taskId].tPhase++;
        break;
    case 3: // end
        ResetSpriteRotScale(gTasks[taskId].tSpriteId);
        DestroyAnimVisualTask(taskId);
        break;
    }
}

#undef tSpriteId
#undef tRotSpeed
#undef tRotCurr
#undef tPhase
#undef tFrames
#undef tPlayerSide
#undef tRotMax
