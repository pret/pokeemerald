#include "global.h"
#include "battle.h"
#include "battle_anim.h"
#include "bg.h"
#include "contest.h"
#include "data.h"
#include "decompress.h"
#include "dma3.h"
#include "gpu_regs.h"
#include "malloc.h"
#include "palette.h"
#include "pokemon_icon.h"
#include "sprite.h"
#include "task.h"
#include "trig.h"
#include "util.h"
#include "constants/battle_anim.h"

#define IS_DOUBLE_BATTLE() ((gBattleTypeFlags & BATTLE_TYPE_DOUBLE))

extern const struct OamData gOamData_AffineNormal_ObjNormal_64x64;

static void sub_80A6FB4(struct Sprite *sprite);
static void AnimFastTranslateLinearWaitEnd(struct Sprite *sprite);
static void AnimThrowProjectile_Step(struct Sprite *sprite);
static void sub_80A8DFC(struct Sprite *sprite);
static void AnimWeatherBallUp_Step(struct Sprite *sprite);
static u16 GetBattlerYDeltaFromSpriteId(u8 spriteId);
static void AnimTask_BlendPalInAndOutSetup(struct Task *task);
static void AnimTask_AlphaFadeIn_Step(u8 taskId);
static void AnimTask_AttackerPunchWithTrace_Step(u8 taskId);
static void AnimTask_BlendMonInAndOut_Step(u8 taskId);
static bool8 sub_80A7238(void);
static void sub_80A8D78(struct Task *task, u8 taskId);

// EWRAM vars
EWRAM_DATA static union AffineAnimCmd *gAnimTaskAffineAnim = NULL;

// Const rom data
static const struct UCoords8 sBattlerCoords[][4] =
{
    {
        { 72, 80 },
        { 176, 40 },
        { 48, 40 },
        { 112, 80 },
    },
    {
        { 32, 80 },
        { 200, 40 },
        { 90, 88 },
        { 152, 32 },
    },
};

// One entry for each of the four Castform forms.
const struct MonCoords gCastformFrontSpriteCoords[] =
{
    { .size = 0x44, .y_offset = 17 }, // NORMAL
    { .size = 0x66, .y_offset =  9 }, // SUN
    { .size = 0x46, .y_offset =  9 }, // RAIN
    { .size = 0x86, .y_offset =  8 }, // HAIL
};

static const u8 sCastformElevations[] =
{
    13, // NORMAL
    14, // SUN
    13, // RAIN
    13, // HAIL
};

// Y position of the backsprite for each of the four Castform forms.
static const u8 sCastformBackSpriteYCoords[] =
{
    0, // NORMAL
    0, // SUN
    0, // RAIN
    0, // HAIL
};

// Placeholders for pokemon sprites to be created for a move animation effect (e.g. Role Play / Snatch)
#define TAG_MOVE_EFFECT_MON_1 55125
#define TAG_MOVE_EFFECT_MON_2 55126

static const struct SpriteTemplate sSpriteTemplate_MoveEffectMons[] =
{
    {
        .tileTag = TAG_MOVE_EFFECT_MON_1,
        .paletteTag = TAG_MOVE_EFFECT_MON_1,
        .oam = &gOamData_AffineNormal_ObjNormal_64x64,
        .anims = gDummySpriteAnimTable,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCallbackDummy,
    },
    {
        .tileTag = TAG_MOVE_EFFECT_MON_2,
        .paletteTag = TAG_MOVE_EFFECT_MON_2,
        .oam = &gOamData_AffineNormal_ObjNormal_64x64,
        .anims = gDummySpriteAnimTable,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCallbackDummy,
    }
};

static const struct SpriteSheet sSpriteSheet_MoveEffectMons[] =
{
    { gMiscBlank_Gfx, MON_PIC_SIZE, TAG_MOVE_EFFECT_MON_1, },
    { gMiscBlank_Gfx, MON_PIC_SIZE, TAG_MOVE_EFFECT_MON_2, },
};

u8 GetBattlerSpriteCoord(u8 battlerId, u8 coordType)
{
    u8 retVal;
    u16 species;
    struct Pokemon *mon, *illusionMon;
    struct BattleSpriteInfo *spriteInfo;

    if (IsContest())
    {
        if (coordType == BATTLER_COORD_Y_PIC_OFFSET && battlerId == 3)
            coordType = BATTLER_COORD_Y;
    }

    switch (coordType)
    {
    case BATTLER_COORD_X:
    case BATTLER_COORD_X_2:
        retVal = sBattlerCoords[IS_DOUBLE_BATTLE()][GetBattlerPosition(battlerId)].x;
        break;
    case BATTLER_COORD_Y:
        retVal = sBattlerCoords[IS_DOUBLE_BATTLE()][GetBattlerPosition(battlerId)].y;
        break;
    case BATTLER_COORD_Y_PIC_OFFSET:
    case BATTLER_COORD_Y_PIC_OFFSET_DEFAULT:
    default:
        if (IsContest())
        {
            if (gContestResources->moveAnim->hasTargetAnim)
                species = gContestResources->moveAnim->targetSpecies;
            else
                species = gContestResources->moveAnim->species;
        }
        else
        {
            if (GetBattlerSide(battlerId) != B_SIDE_PLAYER)
                mon = &gEnemyParty[gBattlerPartyIndexes[battlerId]];
            else
                mon = &gPlayerParty[gBattlerPartyIndexes[battlerId]];

            illusionMon = GetIllusionMonPtr(battlerId);
            if (illusionMon != NULL)
                mon = illusionMon;
            spriteInfo = gBattleSpritesDataPtr->battlerData;
            if (!spriteInfo[battlerId].transformSpecies)
                species = GetMonData(mon, MON_DATA_SPECIES);
            else
                species = spriteInfo[battlerId].transformSpecies;
        }
        if (coordType == BATTLER_COORD_Y_PIC_OFFSET)
            retVal = GetBattlerSpriteFinal_Y(battlerId, species, TRUE);
        else
            retVal = GetBattlerSpriteFinal_Y(battlerId, species, FALSE);
        break;
    }

    return retVal;
}

u8 GetBattlerYDelta(u8 battlerId, u16 species)
{
    u32 personality;
    struct BattleSpriteInfo *spriteInfo;
    u8 ret;
    u16 coordSpecies;

    if (GetBattlerSide(battlerId) == B_SIDE_PLAYER || IsContest())
    {
        if (species == SPECIES_UNOWN)
        {
            if (IsContest())
            {
                if (gContestResources->moveAnim->hasTargetAnim)
                    personality = gContestResources->moveAnim->targetPersonality;
                else
                    personality = gContestResources->moveAnim->personality;
            }
            else
            {
                spriteInfo = gBattleSpritesDataPtr->battlerData;
                if (!spriteInfo[battlerId].transformSpecies)
                    personality = GetMonData(&gPlayerParty[gBattlerPartyIndexes[battlerId]], MON_DATA_PERSONALITY);
                else
                    personality = gTransformedPersonalities[battlerId];
            }
            coordSpecies = GetUnownSpeciesId(personality);
            ret = gMonBackPicCoords[coordSpecies].y_offset;
        }
        else if (species == SPECIES_CASTFORM)
        {
            ret = sCastformBackSpriteYCoords[gBattleMonForms[battlerId]];
        }
        else if (species > NUM_SPECIES)
        {
            ret = gMonBackPicCoords[0].y_offset;
        }
        else
        {
            ret = gMonBackPicCoords[species].y_offset;
        }
    }
    else
    {
        if (species == SPECIES_UNOWN)
        {
            spriteInfo = gBattleSpritesDataPtr->battlerData;
            if (!spriteInfo[battlerId].transformSpecies)
                personality = GetMonData(&gEnemyParty[gBattlerPartyIndexes[battlerId]], MON_DATA_PERSONALITY);
            else
                personality = gTransformedPersonalities[battlerId];

            coordSpecies = GetUnownSpeciesId(personality);
            ret = gMonFrontPicCoords[coordSpecies].y_offset;
        }
        else if (species == SPECIES_CASTFORM)
        {
            ret = gCastformFrontSpriteCoords[gBattleMonForms[battlerId]].y_offset;
        }
        else if (species > NUM_SPECIES)
        {
            ret = gMonFrontPicCoords[0].y_offset;
        }
        else
        {
            ret = gMonFrontPicCoords[species].y_offset;
        }
    }
    return ret;
}

u8 GetBattlerElevation(u8 battlerId, u16 species)
{
    u8 ret = 0;
    if (GetBattlerSide(battlerId) == B_SIDE_OPPONENT)
    {
        if (!IsContest())
        {
            if (species == SPECIES_CASTFORM)
                ret = sCastformElevations[gBattleMonForms[battlerId]];
            else if (species > NUM_SPECIES)
                ret = gEnemyMonElevation[0];
            else
                ret = gEnemyMonElevation[species];
        }
    }
    return ret;
}

u8 GetBattlerSpriteFinal_Y(u8 battlerId, u16 species, bool8 a3)
{
    u16 offset;
    u8 y;

    if (GetBattlerSide(battlerId) == B_SIDE_PLAYER || IsContest())
    {
        offset = GetBattlerYDelta(battlerId, species);
    }
    else
    {
        offset = GetBattlerYDelta(battlerId, species);
        offset -= GetBattlerElevation(battlerId, species);
    }
    y = offset + sBattlerCoords[IS_DOUBLE_BATTLE()][GetBattlerPosition(battlerId)].y;
    if (a3)
    {
        if (GetBattlerSide(battlerId) == B_SIDE_PLAYER)
            y += 8;
        if (y > 104)
            y = 104;
    }
    return y;
}

u8 GetBattlerSpriteCoord2(u8 battlerId, u8 coordType)
{
    u16 species;
    struct BattleSpriteInfo *spriteInfo;

    if (coordType == BATTLER_COORD_Y_PIC_OFFSET || coordType == BATTLER_COORD_Y_PIC_OFFSET_DEFAULT)
    {
        if (IsContest())
        {
            if (gContestResources->moveAnim->hasTargetAnim)
                species = gContestResources->moveAnim->targetSpecies;
            else
                species = gContestResources->moveAnim->species;
        }
        else
        {
            spriteInfo = gBattleSpritesDataPtr->battlerData;
            if (!spriteInfo[battlerId].transformSpecies)
                species = gAnimBattlerSpecies[battlerId];
            else
                species = spriteInfo[battlerId].transformSpecies;
        }
        if (coordType == BATTLER_COORD_Y_PIC_OFFSET)
            return GetBattlerSpriteFinal_Y(battlerId, species, TRUE);
        else
            return GetBattlerSpriteFinal_Y(battlerId, species, FALSE);
    }
    else
    {
        return GetBattlerSpriteCoord(battlerId, coordType);
    }
}

u8 GetBattlerSpriteDefault_Y(u8 battlerId)
{
    return GetBattlerSpriteCoord(battlerId, BATTLER_COORD_Y_PIC_OFFSET_DEFAULT);
}

u8 GetSubstituteSpriteDefault_Y(u8 battlerId)
{
    u16 y;
    if (GetBattlerSide(battlerId) != B_SIDE_PLAYER)
        y = GetBattlerSpriteCoord(battlerId, BATTLER_COORD_Y) + 16;
    else
        y = GetBattlerSpriteCoord(battlerId, BATTLER_COORD_Y) + 17;
    return y;
}

u8 GetBattlerYCoordWithElevation(u8 battlerId)
{
    u16 species;
    u8 y;
    struct BattleSpriteInfo *spriteInfo;

    y = GetBattlerSpriteCoord(battlerId, BATTLER_COORD_Y);
    if (!IsContest())
    {
        if (GetBattlerSide(battlerId) != B_SIDE_PLAYER)
        {
            spriteInfo = gBattleSpritesDataPtr->battlerData;
            if (!spriteInfo[battlerId].transformSpecies)
                species = GetMonData(&gEnemyParty[gBattlerPartyIndexes[battlerId]], MON_DATA_SPECIES);
            else
                species = spriteInfo[battlerId].transformSpecies;
        }
        else
        {
            spriteInfo = gBattleSpritesDataPtr->battlerData;
            if (!spriteInfo[battlerId].transformSpecies)
                species = GetMonData(&gPlayerParty[gBattlerPartyIndexes[battlerId]], MON_DATA_SPECIES);
            else
                species = spriteInfo[battlerId].transformSpecies;
        }
        if (GetBattlerSide(battlerId) != B_SIDE_PLAYER)
            y -= GetBattlerElevation(battlerId, species);
    }
    return y;
}

u8 GetAnimBattlerSpriteId(u8 animBattler)
{
    u8 *sprites;

    if (animBattler == ANIM_ATTACKER)
    {
        if (IsBattlerSpritePresent(gBattleAnimAttacker))
        {
            sprites = gBattlerSpriteIds;
            return sprites[gBattleAnimAttacker];
        }
        else
        {
            return 0xff;
        }
    }
    else if (animBattler == ANIM_TARGET)
    {
        if (IsBattlerSpritePresent(gBattleAnimTarget))
        {
            sprites = gBattlerSpriteIds;
            return sprites[gBattleAnimTarget];
        }
        else
        {
            return 0xff;
        }
    }
    else if (animBattler == ANIM_ATK_PARTNER)
    {
        if (!IsBattlerSpriteVisible(BATTLE_PARTNER(gBattleAnimAttacker)))
            return 0xff;
        else
            return gBattlerSpriteIds[BATTLE_PARTNER(gBattleAnimAttacker)];
    }
    else
    {
        if (IsBattlerSpriteVisible(BATTLE_PARTNER(gBattleAnimTarget)))
            return gBattlerSpriteIds[BATTLE_PARTNER(gBattleAnimTarget)];
        else
            return 0xff;
    }
}

void StoreSpriteCallbackInData6(struct Sprite *sprite, void (*callback)(struct Sprite*))
{
    sprite->data[6] = (u32)(callback) & 0xffff;
    sprite->data[7] = (u32)(callback) >> 16;
}

void SetCallbackToStoredInData6(struct Sprite *sprite)
{
    u32 callback = (u16)sprite->data[6] | (sprite->data[7] << 16);
    sprite->callback = (void (*)(struct Sprite *))callback;
}

void TranslateSpriteInCircleOverDuration(struct Sprite *sprite)
{
    if (sprite->data[3])
    {
        sprite->x2 = Sin(sprite->data[0], sprite->data[1]);
        sprite->y2 = Cos(sprite->data[0], sprite->data[1]);
        sprite->data[0] += sprite->data[2];
        if (sprite->data[0] >= 0x100)
            sprite->data[0] -= 0x100;
        else if (sprite->data[0] < 0)
            sprite->data[0] += 0x100;
        sprite->data[3]--;
    }
    else
    {
        SetCallbackToStoredInData6(sprite);
    }
}

void TranslateSpriteInGrowingCircleOverDuration(struct Sprite *sprite)
{
    if (sprite->data[3])
    {
        sprite->x2 = Sin(sprite->data[0], (sprite->data[5] >> 8) + sprite->data[1]);
        sprite->y2 = Cos(sprite->data[0], (sprite->data[5] >> 8) + sprite->data[1]);
        sprite->data[0] += sprite->data[2];
        sprite->data[5] += sprite->data[4];
        if (sprite->data[0] >= 0x100)
            sprite->data[0] -= 0x100;
        else if (sprite->data[0] < 0)
            sprite->data[0] += 0x100;
        sprite->data[3]--;
    }
    else
    {
        SetCallbackToStoredInData6(sprite);
    }
}

void sub_80A63C8(struct Sprite *sprite)
{
    if (sprite->data[3])
    {
        sprite->x2 = Sin(sprite->data[0], sprite->data[1]);
        sprite->y2 = Cos(sprite->data[4], sprite->data[1]);
        sprite->data[0] += sprite->data[2];
        sprite->data[4] += sprite->data[5];
        if (sprite->data[0] >= 0x100)
            sprite->data[0] -= 0x100;
        else if (sprite->data[0] < 0)
            sprite->data[0] += 0x100;
        if (sprite->data[4] >= 0x100)
            sprite->data[4] -= 0x100;
        else if (sprite->data[4] < 0)
            sprite->data[4] += 0x100;
        sprite->data[3]--;
    }
    else
    {
        SetCallbackToStoredInData6(sprite);
    }
}

void TranslateSpriteInEllipseOverDuration(struct Sprite *sprite)
{
    if (sprite->data[3])
    {
        sprite->x2 = Sin(sprite->data[0], sprite->data[1]);
        sprite->y2 = Cos(sprite->data[0], sprite->data[4]);
        sprite->data[0] += sprite->data[2];
        if (sprite->data[0] >= 0x100)
            sprite->data[0] -= 0x100;
        else if (sprite->data[0] < 0)
            sprite->data[0] += 0x100;
        sprite->data[3]--;
    }
    else
    {
        SetCallbackToStoredInData6(sprite);
    }
}

// Simply waits until the sprite's data[0] hits zero.
// This is used to let sprite anims or affine anims to run for a designated
// duration.
void WaitAnimForDuration(struct Sprite *sprite)
{
    if (sprite->data[0] > 0)
        sprite->data[0]--;
    else
        SetCallbackToStoredInData6(sprite);
}

static void sub_80A64D0(struct Sprite *sprite)
{
    sub_80A64EC(sprite);
    sprite->callback = TranslateSpriteLinear;
    sprite->callback(sprite);
}

void sub_80A64EC(struct Sprite *sprite)
{
    s16 old;
    int xDiff;

    if (sprite->data[1] > sprite->data[2])
        sprite->data[0] = -sprite->data[0];
    xDiff = sprite->data[2] - sprite->data[1];
    old = sprite->data[0];
    sprite->data[0] = abs(xDiff / sprite->data[0]);
    sprite->data[2] = (sprite->data[4] - sprite->data[3]) / sprite->data[0];
    sprite->data[1] = old;
}

void TranslateSpriteLinear(struct Sprite *sprite)
{
    if (sprite->data[0] > 0)
    {
        sprite->data[0]--;
        sprite->x2 += sprite->data[1];
        sprite->y2 += sprite->data[2];
    }
    else
    {
        SetCallbackToStoredInData6(sprite);
    }
}

void TranslateSpriteLinearFixedPoint(struct Sprite *sprite)
{
    if (sprite->data[0] > 0)
    {
        sprite->data[0]--;
        sprite->data[3] += sprite->data[1];
        sprite->data[4] += sprite->data[2];
        sprite->x2 = sprite->data[3] >> 8;
        sprite->y2 = sprite->data[4] >> 8;
    }
    else
    {
        SetCallbackToStoredInData6(sprite);
    }
}

static void TranslateSpriteLinearFixedPointIconFrame(struct Sprite *sprite)
{
    if (sprite->data[0] > 0)
    {
        sprite->data[0]--;
        sprite->data[3] += sprite->data[1];
        sprite->data[4] += sprite->data[2];
        sprite->x2 = sprite->data[3] >> 8;
        sprite->y2 = sprite->data[4] >> 8;
    }
    else
    {
        SetCallbackToStoredInData6(sprite);
    }

    UpdateMonIconFrame(sprite);
}

void sub_80A65EC(struct Sprite *sprite)
{
    sprite->data[1] = sprite->x + sprite->x2;
    sprite->data[3] = sprite->y + sprite->y2;
    sprite->data[2] = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X_2);
    sprite->data[4] = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y_PIC_OFFSET);
    sprite->callback = sub_80A64D0;
}

void TranslateMonSpriteLinear(struct Sprite *sprite)
{
    if (sprite->data[0] > 0)
    {
        sprite->data[0]--;
        gSprites[sprite->data[3]].x2 += sprite->data[1];
        gSprites[sprite->data[3]].y2 += sprite->data[2];
    }
    else
    {
        SetCallbackToStoredInData6(sprite);
    }
}

void TranslateMonSpriteLinearFixedPoint(struct Sprite *sprite)
{
    if (sprite->data[0] > 0)
    {
        sprite->data[0]--;
        sprite->data[3] += sprite->data[1];
        sprite->data[4] += sprite->data[2];
        gSprites[sprite->data[5]].x2 = sprite->data[3] >> 8;
        gSprites[sprite->data[5]].y2 = sprite->data[4] >> 8;
    }
    else
    {
        SetCallbackToStoredInData6(sprite);
    }
}

void TranslateSpriteLinearAndFlicker(struct Sprite *sprite)
{
    if (sprite->data[0] > 0)
    {
        sprite->data[0]--;
        sprite->x2 = sprite->data[2] >> 8;
        sprite->data[2] += sprite->data[1];
        sprite->y2 = sprite->data[4] >> 8;
        sprite->data[4] += sprite->data[3];
        if (sprite->data[0] % sprite->data[5] == 0)
        {
            if (sprite->data[5])
                sprite->invisible ^= 1;
        }
    }
    else
    {
        SetCallbackToStoredInData6(sprite);
    }
}

void DestroySpriteAndMatrix(struct Sprite *sprite)
{
    FreeSpriteOamMatrix(sprite);
    DestroyAnimSprite(sprite);
}

void sub_80A6760(struct Sprite *sprite)
{
    sprite->data[1] = sprite->x + sprite->x2;
    sprite->data[3] = sprite->y + sprite->y2;
    sprite->data[2] = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_X_2);
    sprite->data[4] = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_Y_PIC_OFFSET);
    sprite->callback = sub_80A64D0;
}

void sub_80A67A4(struct Sprite *sprite)
{
    ResetPaletteStructByUid(sprite->data[5]);
    DestroySpriteAndMatrix(sprite);
}

void RunStoredCallbackWhenAffineAnimEnds(struct Sprite *sprite)
{
    if (sprite->affineAnimEnded)
        SetCallbackToStoredInData6(sprite);
}

void RunStoredCallbackWhenAnimEnds(struct Sprite *sprite)
{
    if (sprite->animEnded)
        SetCallbackToStoredInData6(sprite);
}

void DestroyAnimSpriteAndDisableBlend(struct Sprite *sprite)
{
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
    SetGpuReg(REG_OFFSET_BLDALPHA, 0);
    DestroyAnimSprite(sprite);
}

void DestroyAnimVisualTaskAndDisableBlend(u8 taskId)
{
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
    SetGpuReg(REG_OFFSET_BLDALPHA, 0);
    DestroyAnimVisualTask(taskId);
}

void SetSpriteCoordsToAnimAttackerCoords(struct Sprite *sprite)
{
    sprite->x = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_X_2);
    sprite->y = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_Y_PIC_OFFSET);
}

// Sets the initial x offset of the anim sprite depending on the horizontal orientation
// of the two involved mons.
void SetAnimSpriteInitialXOffset(struct Sprite *sprite, s16 xOffset)
{
    u16 attackerX = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_X);
    u16 targetX = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X);

    if (attackerX > targetX)
    {
        sprite->x -= xOffset;
    }
    else if (attackerX < targetX)
    {
        sprite->x += xOffset;
    }
    else
    {
        if (GetBattlerSide(gBattleAnimAttacker) != B_SIDE_PLAYER)
            sprite->x -= xOffset;
        else
            sprite->x += xOffset;
    }
}

void InitAnimArcTranslation(struct Sprite *sprite)
{
    sprite->data[1] = sprite->x;
    sprite->data[3] = sprite->y;
    InitAnimLinearTranslation(sprite);
    sprite->data[6] = 0x8000 / sprite->data[0];
    sprite->data[7] = 0;
}

bool8 TranslateAnimHorizontalArc(struct Sprite *sprite)
{
    if (AnimTranslateLinear(sprite))
        return TRUE;
    sprite->data[7] += sprite->data[6];
    sprite->y2 += Sin((u8)(sprite->data[7] >> 8), sprite->data[5]);
    return FALSE;
}

bool8 TranslateAnimVerticalArc(struct Sprite *sprite)
{
    if (AnimTranslateLinear(sprite))
        return TRUE;
    sprite->data[7] += sprite->data[6];
    sprite->x2 += Sin((u8)(sprite->data[7] >> 8), sprite->data[5]);
    return FALSE;
}

void SetSpritePrimaryCoordsFromSecondaryCoords(struct Sprite *sprite)
{
    sprite->x += sprite->x2;
    sprite->y += sprite->y2;
    sprite->x2 = 0;
    sprite->y2 = 0;
}

void InitSpritePosToAnimTarget(struct Sprite *sprite, bool8 respectMonPicOffsets)
{
    // Battle anim sprites are automatically created at the anim target's center, which
    // is why there is no else clause for the "respectMonPicOffsets" check.
    if (!respectMonPicOffsets)
    {
        sprite->x = GetBattlerSpriteCoord2(gBattleAnimTarget, BATTLER_COORD_X);
        sprite->y = GetBattlerSpriteCoord2(gBattleAnimTarget, BATTLER_COORD_Y);
    }
    SetAnimSpriteInitialXOffset(sprite, gBattleAnimArgs[0]);
    sprite->y += gBattleAnimArgs[1];
}

void InitSpritePosToAnimAttacker(struct Sprite *sprite, bool8 respectMonPicOffsets)
{
    if (!respectMonPicOffsets)
    {
        sprite->x = GetBattlerSpriteCoord2(gBattleAnimAttacker, BATTLER_COORD_X);
        sprite->y = GetBattlerSpriteCoord2(gBattleAnimAttacker, BATTLER_COORD_Y);
    }
    else
    {
        sprite->x = GetBattlerSpriteCoord2(gBattleAnimAttacker, BATTLER_COORD_X_2);
        sprite->y = GetBattlerSpriteCoord2(gBattleAnimAttacker, BATTLER_COORD_Y_PIC_OFFSET);
    }
    SetAnimSpriteInitialXOffset(sprite, gBattleAnimArgs[0]);
    sprite->y += gBattleAnimArgs[1];
}

void InitSpritePosToAnimAttackerPartner(struct Sprite *sprite, bool8 respectMonPicOffsets)
{
    if (!respectMonPicOffsets)
    {
        sprite->x = GetBattlerSpriteCoord2(BATTLE_PARTNER(gBattleAnimAttacker), BATTLER_COORD_X);
        sprite->y = GetBattlerSpriteCoord2(BATTLE_PARTNER(gBattleAnimAttacker), BATTLER_COORD_Y);
    }
    else
    {
        sprite->x = GetBattlerSpriteCoord2(BATTLE_PARTNER(gBattleAnimAttacker), BATTLER_COORD_X_2);
        sprite->y = GetBattlerSpriteCoord2(BATTLE_PARTNER(gBattleAnimAttacker), BATTLER_COORD_Y_PIC_OFFSET);
    }
    SetAnimSpriteInitialXOffset(sprite, gBattleAnimArgs[0]);
    sprite->y += gBattleAnimArgs[1];
}

bool32 InitSpritePosToAnimBattler(u32 animBattlerId, struct Sprite *sprite, bool8 respectMonPicOffsets)
{
    u32 battlerId = GetAnimBattlerId(animBattlerId);
    if (GetAnimBattlerSpriteId(animBattlerId) == 0xFF || !IsBattlerSpriteVisible(battlerId))
    {
        DestroyAnimSprite(sprite);
        return FALSE;
    }

    if (!respectMonPicOffsets)
    {
        sprite->x = GetBattlerSpriteCoord2(battlerId, BATTLER_COORD_X);
        sprite->y = GetBattlerSpriteCoord2(battlerId, BATTLER_COORD_Y);
    }
    else if (animBattlerId != ANIM_TARGET)
    {
        sprite->x = GetBattlerSpriteCoord2(battlerId, BATTLER_COORD_X_2);
        sprite->y = GetBattlerSpriteCoord2(battlerId, BATTLER_COORD_Y_PIC_OFFSET);
    }
    SetAnimSpriteInitialXOffset(sprite, gBattleAnimArgs[0]);
    sprite->y += gBattleAnimArgs[1];
    return TRUE;
}

u8 GetBattlerSide(u8 battlerId)
{
    return GET_BATTLER_SIDE2(battlerId);
}

u8 GetBattlerPosition(u8 battlerId)
{
    return GET_BATTLER_POSITION(battlerId);
}

u8 GetBattlerAtPosition(u8 position)
{
    u8 i;

    for (i = 0; i < gBattlersCount; i++)
    {
        if (gBattlerPositions[i] == position)
            break;
    }
    return i;
}

bool8 IsBattlerSpritePresent(u8 battlerId)
{
    if (IsContest())
    {
        if (gBattleAnimAttacker == battlerId)
            return TRUE;
        else if (gBattleAnimTarget == battlerId)
            return TRUE;
        else
            return FALSE;
    }
    else
    {
        if (gBattlerPositions[battlerId] == 0xff)
            return FALSE;

        if (!gBattleStruct->spriteIgnore0Hp)
        {
            if (GetBattlerSide(battlerId) == B_SIDE_OPPONENT)
            {
                if (GetMonData(&gEnemyParty[gBattlerPartyIndexes[battlerId]], MON_DATA_HP) == 0)
                    return FALSE;
            }
            else
            {
                if (GetMonData(&gPlayerParty[gBattlerPartyIndexes[battlerId]], MON_DATA_HP) == 0)
                    return FALSE;
            }
        }
        return TRUE;
    }
}

bool8 IsDoubleBattle(void)
{
    return IS_DOUBLE_BATTLE();
}

void GetBattleAnimBg1Data(struct BattleAnimBgData *out)
{
    if (IsContest())
    {
        out->bgTiles = gUnknown_0202305C;
        out->bgTilemap = (u16 *)gUnknown_02023060;
        out->paletteId = 14;
        out->bgId = 1;
        out->tilesOffset = 0;
        out->unused = 0;
    }
    else
    {
        out->bgTiles = gUnknown_0202305C;
        out->bgTilemap = (u16 *)gUnknown_02023060;
        out->paletteId = 8;
        out->bgId = 1;
        out->tilesOffset = 0x200;
        out->unused = 0;
    }
}

void GetBattleAnimBgData(struct BattleAnimBgData *out, u32 bgId)
{
    if (IsContest())
    {
        out->bgTiles = gUnknown_0202305C;
        out->bgTilemap = (u16 *)gUnknown_02023060;
        out->paletteId = 14;
        out->bgId = 1;
        out->tilesOffset = 0;
        out->unused = 0;
    }
    else if (bgId == 1)
    {
        GetBattleAnimBg1Data(out);
    }
    else
    {
        out->bgTiles = gUnknown_0202305C;
        out->bgTilemap = (u16 *)gUnknown_02023060;
        out->paletteId = 9;
        out->bgId = 2;
        out->tilesOffset = 0x300;
        out->unused = 0;
    }
}

void sub_80A6BFC(struct BattleAnimBgData *out, u8 unused)
{
    out->bgTiles = gUnknown_0202305C;
    out->bgTilemap = (u16 *)gUnknown_02023060;
    if (IsContest())
    {
        out->paletteId = 14;
        out->bgId = 1;
        out->tilesOffset = 0;
        out->unused = 0;
    }
    else if (GetBattlerSpriteBGPriorityRank(gBattleAnimAttacker) == 1)
    {
        out->paletteId = 8;
        out->bgId = 1;
        out->tilesOffset = 0x200;
        out->unused = 0;
    }
    else
    {
        out->paletteId = 9;
        out->bgId = 2;
        out->tilesOffset = 0x300;
        out->unused = 0;
    }
}

void ClearBattleAnimBg(u32 bgId)
{
    struct BattleAnimBgData bgAnimData;

    GetBattleAnimBgData(&bgAnimData, bgId);
    CpuFill32(0, bgAnimData.bgTiles, 0x2000);
    LoadBgTiles(bgAnimData.bgId, bgAnimData.bgTiles, 0x2000, bgAnimData.tilesOffset);
    FillBgTilemapBufferRect(bgAnimData.bgId, 0, 0, 0, 32, 64, 17);
    CopyBgTilemapBufferToVram(bgAnimData.bgId);
}

void AnimLoadCompressedBgGfx(u32 bgId, const u32 *src, u32 tilesOffset)
{
    CpuFill32(0, gUnknown_0202305C, 0x2000);
    LZDecompressWram(src, gUnknown_0202305C);
    LoadBgTiles(bgId, gUnknown_0202305C, 0x2000, tilesOffset);
}

static void InitAnimBgTilemapBuffer(u32 bgId, const void *src)
{
    FillBgTilemapBufferRect(bgId, 0, 0, 0, 32, 64, 17);
    CopyToBgTilemapBuffer(bgId, src, 0, 0);
}

void AnimLoadCompressedBgTilemap(u32 bgId, const void *src)
{
    InitAnimBgTilemapBuffer(bgId, src);
    CopyBgTilemapBufferToVram(bgId);
}

void AnimLoadCompressedBgTilemapHandleContest(struct BattleAnimBgData *unk, const void *src, u32 arg2)
{
    InitAnimBgTilemapBuffer(unk->bgId, src);
    if (IsContest() == TRUE)
        sub_80A4720(unk->paletteId, unk->bgTilemap, 0, arg2);
    CopyBgTilemapBufferToVram(unk->bgId);
}

u8 GetBattleBgPaletteNum(void)
{
    if (IsContest())
        return 1;
    else
        return 2;
}

void UpdateAnimBg3ScreenSize(bool8 largeScreenSize)
{
    if (!largeScreenSize || IsContest())
    {
        SetAnimBgAttribute(3, BG_ANIM_SCREEN_SIZE, 0);
        SetAnimBgAttribute(3, BG_ANIM_AREA_OVERFLOW_MODE, 1);
    }
    else
    {
        SetAnimBgAttribute(3, BG_ANIM_SCREEN_SIZE, 1);
        SetAnimBgAttribute(3, BG_ANIM_AREA_OVERFLOW_MODE, 0);
    }
}

void TradeMenuBouncePartySprites(struct Sprite *sprite)
{
    sprite->data[1] = sprite->x;
    sprite->data[3] = sprite->y;
    InitSpriteDataForLinearTranslation(sprite);
    sprite->callback = TranslateSpriteLinearFixedPointIconFrame;
    sprite->callback(sprite);
}

void InitSpriteDataForLinearTranslation(struct Sprite *sprite)
{
    s16 x = (sprite->data[2] - sprite->data[1]) << 8;
    s16 y = (sprite->data[4] - sprite->data[3]) << 8;
    sprite->data[1] = x / sprite->data[0];
    sprite->data[2] = y / sprite->data[0];
    sprite->data[4] = 0;
    sprite->data[3] = 0;
}

void InitAnimLinearTranslation(struct Sprite *sprite)
{
    int x = sprite->data[2] - sprite->data[1];
    int y = sprite->data[4] - sprite->data[3];
    bool8 movingLeft = x < 0;
    bool8 movingUp = y < 0;
    u16 xDelta = abs(x) << 8;
    u16 yDelta = abs(y) << 8;

    xDelta = xDelta / sprite->data[0];
    yDelta = yDelta / sprite->data[0];

    if (movingLeft)
        xDelta |= 1;
    else
        xDelta &= ~1;

    if (movingUp)
        yDelta |= 1;
    else
        yDelta &= ~1;

    sprite->data[1] = xDelta;
    sprite->data[2] = yDelta;
    sprite->data[4] = 0;
    sprite->data[3] = 0;
}

void StartAnimLinearTranslation(struct Sprite *sprite)
{
    sprite->data[1] = sprite->x;
    sprite->data[3] = sprite->y;
    InitAnimLinearTranslation(sprite);
    sprite->callback = AnimTranslateLinear_WaitEnd;
    sprite->callback(sprite);
}

void sub_80A6F14(struct Sprite *sprite)
{
    sprite->data[1] = sprite->x;
    sprite->data[3] = sprite->y;
    InitAnimLinearTranslation(sprite);
    sprite->callback = sub_80A6FB4;
    sprite->callback(sprite);
}

bool8 AnimTranslateLinear(struct Sprite *sprite)
{
    u16 v1, v2, x, y;

    if (!sprite->data[0])
        return TRUE;

    v1 = sprite->data[1];
    v2 = sprite->data[2];
    x = sprite->data[3];
    y = sprite->data[4];
    x += v1;
    y += v2;

    if (v1 & 1)
        sprite->x2 = -(x >> 8);
    else
        sprite->x2 = x >> 8;

    if (v2 & 1)
        sprite->y2 = -(y >> 8);
    else
        sprite->y2 = y >> 8;

    sprite->data[3] = x;
    sprite->data[4] = y;
    sprite->data[0]--;
    return FALSE;
}

void AnimTranslateLinear_WaitEnd(struct Sprite *sprite)
{
    if (AnimTranslateLinear(sprite))
        SetCallbackToStoredInData6(sprite);
}

static void sub_80A6FB4(struct Sprite *sprite)
{
    sub_8039E9C(sprite);
    if (AnimTranslateLinear(sprite))
        SetCallbackToStoredInData6(sprite);
}

void InitAnimLinearTranslationWithSpeed(struct Sprite *sprite)
{
    int v1 = abs(sprite->data[2] - sprite->data[1]) << 8;
    sprite->data[0] = v1 / sprite->data[0];
    InitAnimLinearTranslation(sprite);
}

void InitAnimLinearTranslationWithSpeedAndPos(struct Sprite *sprite)
{
    sprite->data[1] = sprite->x;
    sprite->data[3] = sprite->y;
    InitAnimLinearTranslationWithSpeed(sprite);
    sprite->callback = AnimTranslateLinear_WaitEnd;
    sprite->callback(sprite);
}

static void InitAnimFastLinearTranslation(struct Sprite *sprite)
{
    int xDiff = sprite->data[2] - sprite->data[1];
    int yDiff = sprite->data[4] - sprite->data[3];
    bool8 x_sign = xDiff < 0;
    bool8 y_sign = yDiff < 0;
    u16 x2 = abs(xDiff) << 4;
    u16 y2 = abs(yDiff) << 4;

    x2 /= sprite->data[0];
    y2 /= sprite->data[0];

    if (x_sign)
        x2 |= 1;
    else
        x2 &= ~1;

    if (y_sign)
        y2 |= 1;
    else
        y2 &= ~1;

    sprite->data[1] = x2;
    sprite->data[2] = y2;
    sprite->data[4] = 0;
    sprite->data[3] = 0;
}

void InitAndRunAnimFastLinearTranslation(struct Sprite *sprite)
{
    sprite->data[1] = sprite->x;
    sprite->data[3] = sprite->y;
    InitAnimFastLinearTranslation(sprite);
    sprite->callback = AnimFastTranslateLinearWaitEnd;
    sprite->callback(sprite);
}

bool8 AnimFastTranslateLinear(struct Sprite *sprite)
{
    u16 v1, v2, x, y;

    if (!sprite->data[0])
        return TRUE;

    v1 = sprite->data[1];
    v2 = sprite->data[2];
    x = sprite->data[3];
    y = sprite->data[4];
    x += v1;
    y += v2;

    if (v1 & 1)
        sprite->x2 = -(x >> 4);
    else
        sprite->x2 = x >> 4;

    if (v2 & 1)
        sprite->y2 = -(y >> 4);
    else
        sprite->y2 = y >> 4;

    sprite->data[3] = x;
    sprite->data[4] = y;
    sprite->data[0]--;
    return FALSE;
}

static void AnimFastTranslateLinearWaitEnd(struct Sprite *sprite)
{
    if (AnimFastTranslateLinear(sprite))
        SetCallbackToStoredInData6(sprite);
}

void InitAnimFastLinearTranslationWithSpeed(struct Sprite *sprite)
{
    int xDiff = abs(sprite->data[2] - sprite->data[1]) << 4;
    sprite->data[0] = xDiff / sprite->data[0];
    InitAnimFastLinearTranslation(sprite);
}

void InitAnimFastLinearTranslationWithSpeedAndPos(struct Sprite *sprite)
{
    sprite->data[1] = sprite->x;
    sprite->data[3] = sprite->y;
    InitAnimFastLinearTranslationWithSpeed(sprite);
    sprite->callback = AnimFastTranslateLinearWaitEnd;
    sprite->callback(sprite);
}

void SetSpriteRotScale(u8 spriteId, s16 xScale, s16 yScale, u16 rotation)
{
    int i;
    struct ObjAffineSrcData src;
    struct OamMatrix matrix;

    src.xScale = xScale;
    src.yScale = yScale;
    src.rotation = rotation;
    if (sub_80A7238())
        src.xScale = -src.xScale;
    i = gSprites[spriteId].oam.matrixNum;
    ObjAffineSet(&src, &matrix, 1, 2);
    gOamMatrices[i].a = matrix.a;
    gOamMatrices[i].b = matrix.b;
    gOamMatrices[i].c = matrix.c;
    gOamMatrices[i].d = matrix.d;
}

static bool8 sub_80A7238(void)
{
    if (IsContest())
    {
        if (gSprites[GetAnimBattlerSpriteId(ANIM_ATTACKER)].data[2] == SPECIES_UNOWN)
            return FALSE;
        else
            return TRUE;
    }
    else
    {
        return FALSE;
    }
}

void PrepareBattlerSpriteForRotScale(u8 spriteId, u8 objMode)
{
    u8 battlerId = gSprites[spriteId].data[0];

    if (IsContest() || IsBattlerSpriteVisible(battlerId))
        gSprites[spriteId].invisible = FALSE;
    gSprites[spriteId].oam.objMode = objMode;
    gSprites[spriteId].affineAnimPaused = TRUE;
    if (!IsContest() && !gSprites[spriteId].oam.affineMode)
        gSprites[spriteId].oam.matrixNum = gBattleSpritesDataPtr->healthBoxesData[battlerId].matrixNum;
    gSprites[spriteId].oam.affineMode = ST_OAM_AFFINE_DOUBLE;
    CalcCenterToCornerVec(&gSprites[spriteId], gSprites[spriteId].oam.shape, gSprites[spriteId].oam.size, gSprites[spriteId].oam.affineMode);
}

void ResetSpriteRotScale(u8 spriteId)
{
    SetSpriteRotScale(spriteId, 0x100, 0x100, 0);
    gSprites[spriteId].oam.affineMode = ST_OAM_AFFINE_NORMAL;
    gSprites[spriteId].oam.objMode = ST_OAM_OBJ_NORMAL;
    gSprites[spriteId].affineAnimPaused = FALSE;
    CalcCenterToCornerVec(&gSprites[spriteId], gSprites[spriteId].oam.shape, gSprites[spriteId].oam.size, gSprites[spriteId].oam.affineMode);
}

// Sets the sprite's y offset equal to the y displacement caused by the
// matrix's rotation.
void SetBattlerSpriteYOffsetFromRotation(u8 spriteId)
{
    u16 matrixNum = gSprites[spriteId].oam.matrixNum;
    // The "c" component of the battler sprite matrix contains the sine of the rotation angle divided by some scale amount.
    s16 c = gOamMatrices[matrixNum].c;
    if (c < 0)
        c = -c;

    gSprites[spriteId].y2 = c >> 3;
}

void TrySetSpriteRotScale(struct Sprite *sprite, bool8 recalcCenterVector, s16 xScale, s16 yScale, u16 rotation)
{
    int i;
    struct ObjAffineSrcData src;
    struct OamMatrix matrix;

    if (sprite->oam.affineMode & 1)
    {
        sprite->affineAnimPaused = TRUE;
        if (recalcCenterVector)
            CalcCenterToCornerVec(sprite, sprite->oam.shape, sprite->oam.size, sprite->oam.affineMode);
        src.xScale = xScale;
        src.yScale = yScale;
        src.rotation = rotation;
        if (sub_80A7238())
            src.xScale = -src.xScale;
        i = sprite->oam.matrixNum;
        ObjAffineSet(&src, &matrix, 1, 2);
        gOamMatrices[i].a = matrix.a;
        gOamMatrices[i].b = matrix.b;
        gOamMatrices[i].c = matrix.c;
        gOamMatrices[i].d = matrix.d;
    }
}

void ResetSpriteRotScale_PreserveAffine(struct Sprite *sprite)
{
    TrySetSpriteRotScale(sprite, TRUE, 0x100, 0x100, 0);
    sprite->affineAnimPaused = FALSE;
    CalcCenterToCornerVec(sprite, sprite->oam.shape, sprite->oam.size, sprite->oam.affineMode);
}

static u16 ArcTan2_(s16 a, s16 b)
{
    return ArcTan2(a, b);
}

u16 ArcTan2Neg(s16 a, s16 b)
{
    u16 var = ArcTan2_(a, b);
    return -var;
}

void SetGrayscaleOrOriginalPalette(u16 paletteNum, bool8 restoreOriginalColor)
{
    int i;
    struct PlttData *originalColor;
    struct PlttData *destColor;
    u16 average;

    paletteNum *= 16;

    if (!restoreOriginalColor)
    {
        for (i = 0; i < 16; i++)
        {
            originalColor = (struct PlttData *)&gPlttBufferUnfaded[paletteNum + i];
            average = originalColor->r + originalColor->g + originalColor->b;
            average /= 3;

            destColor = (struct PlttData *)&gPlttBufferFaded[paletteNum + i];
            destColor->r = average;
            destColor->g = average;
            destColor->b = average;
        }
    }
    else
    {
        CpuCopy32(&gPlttBufferUnfaded[paletteNum], &gPlttBufferFaded[paletteNum], 32);
    }
}

u32 GetBattleBgPalettesMask(u8 battleBackground, u8 attacker, u8 target, u8 attackerPartner, u8 targetPartner, u8 a6, u8 a7)
{
    u32 selectedPalettes = 0;
    u32 shift;

    if (battleBackground)
    {
        if (!IsContest())
            selectedPalettes = 0xe;
        else
            selectedPalettes = 1 << GetBattleBgPaletteNum();
    }
    if (attacker)
    {
        shift = gBattleAnimAttacker + 16;
        selectedPalettes |= 1 << shift;
    }
    if (target)
    {
        shift = gBattleAnimTarget + 16;
        selectedPalettes |= 1 << shift;
    }
    if (attackerPartner)
    {
        if (IsBattlerSpriteVisible(BATTLE_PARTNER(gBattleAnimAttacker)))
        {
            shift = BATTLE_PARTNER(gBattleAnimAttacker) + 16;
            selectedPalettes |= 1 << shift;
        }
    }
    if (targetPartner)
    {
        if (IsBattlerSpriteVisible(BATTLE_PARTNER(gBattleAnimTarget)))
        {
            shift = BATTLE_PARTNER(gBattleAnimTarget) + 16;
            selectedPalettes |= 1 << shift;
        }
    }
    if (a6)
    {
        if (!IsContest())
            selectedPalettes |= 0x100;
        else
            selectedPalettes |= 0x4000;
    }
    if (a7)
    {
        if (!IsContest())
            selectedPalettes |= 0x200;
    }
    return selectedPalettes;
}

u32 GetBattleMonSpritePalettesMask(u8 playerLeft, u8 playerRight, u8 opponentLeft, u8 opponentRight)
{
    u32 selectedPalettes = 0;
    u32 shift;

    if (IsContest())
    {
        if (playerLeft)
        {
            selectedPalettes |= 1 << 18;
            return selectedPalettes;
        }
    }
    else
    {
        if (playerLeft)
        {
            if (IsBattlerSpriteVisible(GetBattlerAtPosition(B_POSITION_PLAYER_LEFT)))
            {
                selectedPalettes |= 1 << (GetBattlerAtPosition(B_POSITION_PLAYER_LEFT) + 16);
            }
        }
        if (playerRight)
        {
            if (IsBattlerSpriteVisible(GetBattlerAtPosition(B_POSITION_PLAYER_RIGHT)))
            {
                shift = GetBattlerAtPosition(B_POSITION_PLAYER_RIGHT) + 16;
                selectedPalettes |= 1 << shift;
            }
        }
        if (opponentLeft)
        {
            if (IsBattlerSpriteVisible(GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT)))
            {
                shift = GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT) + 16;
                selectedPalettes |= 1 << shift;
            }
        }
        if (opponentRight)
        {
            if (IsBattlerSpriteVisible(GetBattlerAtPosition(B_POSITION_OPPONENT_RIGHT)))
            {
                shift = GetBattlerAtPosition(B_POSITION_OPPONENT_RIGHT) + 16;
                selectedPalettes |= 1 << shift;
            }
        }
    }
    return selectedPalettes;
}

// Presumably something commented here, just returns arg
u8 AnimDummyReturnArg(u8 battler)
{
    return battler;
}

static u8 GetBattlerAtPosition_(u8 position)
{
    return GetBattlerAtPosition(position);
}

void AnimSpriteOnMonPos(struct Sprite *sprite)
{
    bool8 var;

    if (!sprite->data[0])
    {
        if (!gBattleAnimArgs[3])
            var = TRUE;
        else
            var = FALSE;

        if (gBattleAnimArgs[2] == 0)
            InitSpritePosToAnimAttacker(sprite, var);
        else if (gBattleAnimArgs[2] == 1)
            InitSpritePosToAnimTarget(sprite, var);
        else if (gBattleAnimArgs[2] == 2)
            InitSpritePosToAnimAttackerPartner(sprite, var);

        sprite->data[0]++;

    }
    else if (sprite->animEnded || sprite->affineAnimEnded)
    {
        DestroySpriteAndMatrix(sprite);
    }
}

// Linearly translates a sprite to a target position on the
// other mon's sprite.
// arg 0: initial x offset
// arg 1: initial y offset
// arg 2: target x offset
// arg 3: target y offset
// arg 4: duration
// arg 5: lower 8 bits = location on attacking mon, upper 8 bits = location on target mon pick to target
void TranslateAnimSpriteToTargetMonLocation(struct Sprite *sprite)
{
    bool8 v1;
    u8 coordType;

    if (!(gBattleAnimArgs[5] & 0xff00))
        v1 = TRUE;
    else
        v1 = FALSE;

    if (!(gBattleAnimArgs[5] & 0xff))
        coordType = BATTLER_COORD_Y_PIC_OFFSET;
    else
        coordType = BATTLER_COORD_Y;

    InitSpritePosToAnimAttacker(sprite, v1);
    if (GetBattlerSide(gBattleAnimAttacker) != B_SIDE_PLAYER)
        gBattleAnimArgs[2] = -gBattleAnimArgs[2];

    sprite->data[0] = gBattleAnimArgs[4];
    sprite->data[2] = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X_2) + gBattleAnimArgs[2];
    sprite->data[4] = GetBattlerSpriteCoord(gBattleAnimTarget, coordType) + gBattleAnimArgs[3];
    sprite->callback = StartAnimLinearTranslation;
    StoreSpriteCallbackInData6(sprite, DestroyAnimSprite);
}

void AnimThrowProjectile(struct Sprite *sprite)
{
    InitSpritePosToAnimAttacker(sprite, 1);
    if (GetBattlerSide(gBattleAnimAttacker))
        gBattleAnimArgs[2] = -gBattleAnimArgs[2];
    sprite->data[0] = gBattleAnimArgs[4];
    sprite->data[2] = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X_2) + gBattleAnimArgs[2];
    sprite->data[4] = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y_PIC_OFFSET) + gBattleAnimArgs[3];
    sprite->data[5] = gBattleAnimArgs[5];
    InitAnimArcTranslation(sprite);
    sprite->callback = AnimThrowProjectile_Step;
}

static void AnimThrowProjectile_Step(struct Sprite *sprite)
{
    if (TranslateAnimHorizontalArc(sprite))
        DestroyAnimSprite(sprite);
}

void AnimTravelDiagonally(struct Sprite *sprite)
{
    bool8 r4;
    u8 battlerId, coordType;

    if (!gBattleAnimArgs[6])
    {
        r4 = TRUE;
        coordType = BATTLER_COORD_Y_PIC_OFFSET;
    }
    else
    {
        r4 = FALSE;
        coordType = BATTLER_COORD_Y;
    }
    if (gBattleAnimArgs[5] == ANIM_ATTACKER)
    {
        InitSpritePosToAnimAttacker(sprite, r4);
        battlerId = gBattleAnimAttacker;
    }
    else
    {
        InitSpritePosToAnimTarget(sprite, r4);
        battlerId = gBattleAnimTarget;
    }
    if (GetBattlerSide(gBattleAnimAttacker))
        gBattleAnimArgs[2] = -gBattleAnimArgs[2];
    InitSpritePosToAnimTarget(sprite, r4);
    sprite->data[0] = gBattleAnimArgs[4];
    sprite->data[2] = GetBattlerSpriteCoord(battlerId, BATTLER_COORD_X_2) + gBattleAnimArgs[2];
    sprite->data[4] = GetBattlerSpriteCoord(battlerId, coordType) + gBattleAnimArgs[3];
    sprite->callback = StartAnimLinearTranslation;
    StoreSpriteCallbackInData6(sprite, DestroyAnimSprite);
}

s16 CloneBattlerSpriteWithBlend(u8 animBattler)
{
    u16 i;
    u8 spriteId = GetAnimBattlerSpriteId(animBattler);

    if (spriteId != SPRITE_NONE)
    {
        for (i = 0; i < MAX_SPRITES; i++)
        {
            if (!gSprites[i].inUse)
            {
                gSprites[i] = gSprites[spriteId];
                gSprites[i].oam.objMode = ST_OAM_OBJ_BLEND;
                gSprites[i].invisible = FALSE;
                return i;
            }
        }
    }
    return -1;
}

void obj_delete_but_dont_free_vram(struct Sprite *sprite)
{
    sprite->usingSheet = TRUE;
    DestroySprite(sprite);
}

// Only used to fade Moonlight moon sprite in
void AnimTask_AlphaFadeIn(u8 taskId)
{
    s16 v1 = 0;
    s16 v2 = 0;

    if (gBattleAnimArgs[2] > gBattleAnimArgs[0])
        v2 = 1;
    if (gBattleAnimArgs[2] < gBattleAnimArgs[0])
        v2 = -1;
    if (gBattleAnimArgs[3] > gBattleAnimArgs[1])
        v1 = 1;
    if (gBattleAnimArgs[3] < gBattleAnimArgs[1])
        v1 = -1;

    gTasks[taskId].data[0] = 0;
    gTasks[taskId].data[1] = gBattleAnimArgs[4];
    gTasks[taskId].data[2] = 0;
    gTasks[taskId].data[3] = gBattleAnimArgs[0];
    gTasks[taskId].data[4] = gBattleAnimArgs[1];
    gTasks[taskId].data[5] = v2;
    gTasks[taskId].data[6] = v1;
    gTasks[taskId].data[7] = gBattleAnimArgs[2];
    gTasks[taskId].data[8] = gBattleAnimArgs[3];
    SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(gBattleAnimArgs[0], gBattleAnimArgs[1]));
    gTasks[taskId].func = AnimTask_AlphaFadeIn_Step;
}

static void AnimTask_AlphaFadeIn_Step(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    if (++task->data[0] > task->data[1])
    {
        task->data[0] = 0;
        if (++task->data[2] & 1)
        {
            if (task->data[3] != task->data[7])
                task->data[3] += task->data[5];
        }
        else
        {
            if (task->data[4] != task->data[8])
                task->data[4] += task->data[6];
        }
        SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(task->data[3], task->data[4]));
        if (task->data[3] == task->data[7] && task->data[4] == task->data[8])
        {
            DestroyAnimVisualTask(taskId);
            return;
        }
    }
}

// Linearly blends a mon's sprite colors with a target color with increasing
// strength, and then blends out to the original color.
// arg 0: anim bank
// arg 1: blend color
// arg 2: target blend coefficient
// arg 3: initial delay
// arg 4: number of times to blend in and out
void AnimTask_BlendMonInAndOut(u8 task)
{
    u8 spriteId = GetAnimBattlerSpriteId(gBattleAnimArgs[0]);
    if (spriteId == SPRITE_NONE)
    {
        DestroyAnimVisualTask(task);
        return;
    }
    gTasks[task].data[0] = (gSprites[spriteId].oam.paletteNum * 0x10) + 0x101;
    AnimTask_BlendPalInAndOutSetup(&gTasks[task]);
}

static void AnimTask_BlendPalInAndOutSetup(struct Task *task)
{
    task->data[1] = gBattleAnimArgs[1];
    task->data[2] = 0;
    task->data[3] = gBattleAnimArgs[2];
    task->data[4] = 0;
    task->data[5] = gBattleAnimArgs[3];
    task->data[6] = 0;
    task->data[7] = gBattleAnimArgs[4];
    task->func = AnimTask_BlendMonInAndOut_Step;
}

static void AnimTask_BlendMonInAndOut_Step(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    if (++task->data[4] >= task->data[5])
    {
        task->data[4] = 0;
        if (!task->data[6])
        {
            task->data[2]++;
            BlendPalette(task->data[0], 15, task->data[2], task->data[1]);
            if (task->data[2] == task->data[3])
                task->data[6] = 1;
        }
        else
        {
            task->data[2]--;
            BlendPalette(task->data[0], 15, task->data[2], task->data[1]);
            if (!task->data[2])
            {
                if (--task->data[7])
                {
                    task->data[4] = 0;
                    task->data[6] = 0;
                }
                else
                {
                    DestroyAnimVisualTask(taskId);
                    return;
                }
            }
        }
    }
}

// See AnimTask_BlendMonInAndOut. Same, but ANIM_TAG_* instead of mon
void AnimTask_BlendPalInAndOutByTag(u8 task)
{
    u8 palette = IndexOfSpritePaletteTag(gBattleAnimArgs[0]);

    if (palette == 0xff)
    {
        DestroyAnimVisualTask(task);
        return;
    }
    gTasks[task].data[0] = (palette * 0x10) + 0x101;
    AnimTask_BlendPalInAndOutSetup(&gTasks[task]);
}

void PrepareAffineAnimInTaskData(struct Task *task, u8 spriteId, const union AffineAnimCmd *affineAnimCmds)
{
    task->data[7] = 0;
    task->data[8] = 0;
    task->data[9] = 0;
    task->data[15] = spriteId;
    task->data[10] = 0x100;
    task->data[11] = 0x100;
    task->data[12] = 0;
    StorePointerInVars(&task->data[13], &task->data[14], affineAnimCmds);
    PrepareBattlerSpriteForRotScale(spriteId, ST_OAM_OBJ_NORMAL);
}

bool8 RunAffineAnimFromTaskData(struct Task *task)
{
    gAnimTaskAffineAnim = &((union AffineAnimCmd *)LoadPointerFromVars(task->data[13], task->data[14]))[task->data[7]];
    switch (gAnimTaskAffineAnim->type)
    {
    default:
        if (!gAnimTaskAffineAnim->frame.duration)
        {
            task->data[10] = gAnimTaskAffineAnim->frame.xScale;
            task->data[11] = gAnimTaskAffineAnim->frame.yScale;
            task->data[12] = gAnimTaskAffineAnim->frame.rotation;
            task->data[7]++;
            gAnimTaskAffineAnim++;
        }
        task->data[10] += gAnimTaskAffineAnim->frame.xScale;
        task->data[11] += gAnimTaskAffineAnim->frame.yScale;
        task->data[12] += gAnimTaskAffineAnim->frame.rotation;
        SetSpriteRotScale(task->data[15], task->data[10], task->data[11], task->data[12]);
        SetBattlerSpriteYOffsetFromYScale(task->data[15]);
        if (++task->data[8] >= gAnimTaskAffineAnim->frame.duration)
        {
            task->data[8] = 0;
            task->data[7]++;
        }
        break;
    case AFFINEANIMCMDTYPE_JUMP:
        task->data[7] = gAnimTaskAffineAnim->jump.target;
        break;
    case AFFINEANIMCMDTYPE_LOOP:
        if (gAnimTaskAffineAnim->loop.count)
        {
            if (task->data[9])
            {
                if (!--task->data[9])
                {
                    task->data[7]++;
                    break;
                }
            }
            else
            {
                task->data[9] = gAnimTaskAffineAnim->loop.count;
            }
            if (!task->data[7])
            {
                break;
            }
            for (;;)
            {
                task->data[7]--;
                gAnimTaskAffineAnim--;
                if (gAnimTaskAffineAnim->type == AFFINEANIMCMDTYPE_LOOP)
                {
                    task->data[7]++;
                    return TRUE;
                }
                if (!task->data[7])
                    return TRUE;
            }
        }
        task->data[7]++;
        break;
    case AFFINEANIMCMDTYPE_END:
        gSprites[task->data[15]].y2 = 0;
        ResetSpriteRotScale(task->data[15]);
        return FALSE;
    }

    return TRUE;
}

// Sets the sprite's y offset equal to the y displacement caused by the
// matrix's scale in the y dimension.
void SetBattlerSpriteYOffsetFromYScale(u8 spriteId)
{
    int var = 64 - GetBattlerYDeltaFromSpriteId(spriteId) * 2;
    u16 matrix = gSprites[spriteId].oam.matrixNum;
    int var2 = SAFE_DIV(var << 8, gOamMatrices[matrix].d);

    if (var2 > 128)
        var2 = 128;
    gSprites[spriteId].y2 = (var - var2) / 2;
}

// Sets the sprite's y offset equal to the y displacement caused by another sprite
// matrix's scale in the y dimension.
void SetBattlerSpriteYOffsetFromOtherYScale(u8 spriteId, u8 otherSpriteId)
{
    int var = 64 - GetBattlerYDeltaFromSpriteId(otherSpriteId) * 2;
    u16 matrix = gSprites[spriteId].oam.matrixNum;
    int var2 = SAFE_DIV(var << 8, gOamMatrices[matrix].d);

    if (var2 > 128)
        var2 = 128;
    gSprites[spriteId].y2 = (var - var2) / 2;
}

static u16 GetBattlerYDeltaFromSpriteId(u8 spriteId)
{
    struct BattleSpriteInfo *spriteInfo;
    u8 battlerId = gSprites[spriteId].data[0];
    u16 species;
    u16 i;

    for (i = 0; i < MAX_BATTLERS_COUNT; i++)
    {
        if (gBattlerSpriteIds[i] == spriteId)
        {
            if (IsContest())
            {
                species = gContestResources->moveAnim->species;
                return gMonBackPicCoords[species].y_offset;
            }
            else
            {
                if (GetBattlerSide(i) == B_SIDE_PLAYER)
                {
                    spriteInfo = gBattleSpritesDataPtr->battlerData;
                    if (!spriteInfo[battlerId].transformSpecies)
                        species = GetMonData(&gPlayerParty[gBattlerPartyIndexes[i]], MON_DATA_SPECIES);
                    else
                        species = spriteInfo[battlerId].transformSpecies;

                    if (species == SPECIES_CASTFORM)
                        return sCastformBackSpriteYCoords[gBattleMonForms[battlerId]];
                    else
                        return gMonBackPicCoords[species].y_offset;
                }
                else
                {
                    spriteInfo = gBattleSpritesDataPtr->battlerData;
                    if (!spriteInfo[battlerId].transformSpecies)
                        species = GetMonData(&gEnemyParty[gBattlerPartyIndexes[i]], MON_DATA_SPECIES);
                    else
                        species = spriteInfo[battlerId].transformSpecies;

                    if (species == SPECIES_CASTFORM)
                        return sCastformElevations[gBattleMonForms[battlerId]];
                    else
                        return gMonFrontPicCoords[species].y_offset;
                }
            }
        }
    }
    return 64;
}

void StorePointerInVars(s16 *lo, s16 *hi, const void *ptr)
{
    *lo = ((intptr_t) ptr) & 0xffff;
    *hi = (((intptr_t) ptr) >> 16) & 0xffff;
}

void *LoadPointerFromVars(s16 lo, s16 hi)
{
    return (void *)((u16)lo | ((u16)hi << 16));
}

void PrepareEruptAnimTaskData(struct Task *task, u8 spriteId, s16 xScaleStart, s16 yScaleStart, s16 xScaleEnd, s16 yScaleEnd, u16 duration)
{
    task->data[8] = duration;
    task->data[15] = spriteId;
    task->data[9] = xScaleStart;
    task->data[10] = yScaleStart;
    task->data[13] = xScaleEnd;
    task->data[14] = yScaleEnd;
    task->data[11] = (xScaleEnd - xScaleStart) / duration;
    task->data[12] = (yScaleEnd - yScaleStart) / duration;
}

u8 UpdateEruptAnimTask(struct Task *task)
{
    if (!task->data[8])
        return 0;

    if (--task->data[8] != 0)
    {
        task->data[9] += task->data[11];
        task->data[10] += task->data[12];
    }
    else
    {
        task->data[9] = task->data[13];
        task->data[10] = task->data[14];
    }
    SetSpriteRotScale(task->data[15], task->data[9], task->data[10], 0);
    if (task->data[8])
        SetBattlerSpriteYOffsetFromYScale(task->data[15]);
    else
        gSprites[task->data[15]].y2 = 0;
    return task->data[8];
}

void AnimTask_GetFrustrationPowerLevel(u8 taskId)
{
    u16 powerLevel;

    if (gAnimFriendship <= 30)
        powerLevel = 0;
    else if (gAnimFriendship <= 100)
        powerLevel = 1;
    else if (gAnimFriendship <= 200)
        powerLevel = 2;
    else
        powerLevel = 3;
    gBattleAnimArgs[ARG_RET_ID] = powerLevel;
    DestroyAnimVisualTask(taskId);
}

void sub_80A8174(u8 priority)
{
    if (IsBattlerSpriteVisible(gBattleAnimTarget))
        gSprites[gBattlerSpriteIds[gBattleAnimTarget]].oam.priority = priority;
    if (IsBattlerSpriteVisible(gBattleAnimAttacker))
        gSprites[gBattlerSpriteIds[gBattleAnimAttacker]].oam.priority = priority;
    if (IsBattlerSpriteVisible(BATTLE_PARTNER(gBattleAnimTarget)))
        gSprites[gBattlerSpriteIds[BATTLE_PARTNER(gBattleAnimTarget)]].oam.priority = priority;
    if (IsBattlerSpriteVisible(BATTLE_PARTNER(gBattleAnimAttacker)))
        gSprites[gBattlerSpriteIds[BATTLE_PARTNER(gBattleAnimAttacker)]].oam.priority = priority;
}

void sub_80A8278(void)
{
    int i;

    for (i = 0; i < gBattlersCount; i++)
    {
        if (IsBattlerSpriteVisible(i))
        {
            gSprites[gBattlerSpriteIds[i]].subpriority = GetBattlerSpriteSubpriority(i);
            gSprites[gBattlerSpriteIds[i]].oam.priority = 2;
        }
    }
}

u8 GetBattlerSpriteSubpriority(u8 battlerId)
{
    u8 position;
    u8 subpriority;

    if (IsContest())
    {
        if (battlerId == 2)
            return 30;
        else
            return 40;
    }
    else
    {
        position = GetBattlerPosition(battlerId);
        if (position == B_POSITION_PLAYER_LEFT)
            subpriority = 30;
        else if (position == B_POSITION_PLAYER_RIGHT)
            subpriority = 20;
        else if (position == B_POSITION_OPPONENT_LEFT)
            subpriority = 40;
        else
            subpriority = 50;
    }

    return subpriority;
}

u8 GetBattlerSpriteBGPriority(u8 battlerId)
{
    u8 position = GetBattlerPosition(battlerId);

    if (IsContest())
        return 2;
    else if (position == B_POSITION_PLAYER_LEFT || position == B_POSITION_OPPONENT_RIGHT)
        return GetAnimBgAttribute(2, BG_ANIM_PRIORITY);
    else
        return GetAnimBgAttribute(1, BG_ANIM_PRIORITY);
}

u8 GetBattlerSpriteBGPriorityRank(u8 battlerId)
{
    if (!IsContest())
    {
        u8 position = GetBattlerPosition(battlerId);
        if (position == B_POSITION_PLAYER_LEFT || position == B_POSITION_OPPONENT_RIGHT)
            return 2;
        else
            return 1;
    }
    return 1;
}

// Create pokemon sprite to be used for a move animation effect (e.g. Role Play / Snatch)
u8 CreateAdditionalMonSpriteForMoveAnim(u16 species, bool8 isBackpic, u8 id, s16 x, s16 y, u8 subpriority, u32 personality, u32 trainerId, u32 battlerId)
{
    u8 spriteId;
    u16 sheet = LoadSpriteSheet(&sSpriteSheet_MoveEffectMons[id]);
    u16 palette = AllocSpritePalette(sSpriteTemplate_MoveEffectMons[id].paletteTag);

    if (gMonSpritesGfxPtr != NULL && gMonSpritesGfxPtr->buffer == NULL)
        gMonSpritesGfxPtr->buffer = AllocZeroed(0x2000);
    if (!isBackpic)
    {
        LoadCompressedPalette(GetMonSpritePalFromSpeciesAndPersonality(species, trainerId, personality), (palette * 0x10) + 0x100, 0x20);
        LoadSpecialPokePic(&gMonFrontPicTable[species],
                           gMonSpritesGfxPtr->buffer,
                           species,
                           personality,
                           TRUE);
    }
    else
    {
        LoadCompressedPalette(GetMonSpritePalFromSpeciesAndPersonality(species, trainerId, personality), (palette * 0x10) + 0x100, 0x20);
        LoadSpecialPokePic(&gMonBackPicTable[species],
                           gMonSpritesGfxPtr->buffer,
                           species,
                           personality,
                           FALSE);
    }

    RequestDma3Copy(gMonSpritesGfxPtr->buffer, (void *)(OBJ_VRAM0 + (sheet * 0x20)), MON_PIC_SIZE, 1);
    FREE_AND_SET_NULL(gMonSpritesGfxPtr->buffer);

    if (!isBackpic)
        spriteId = CreateSprite(&sSpriteTemplate_MoveEffectMons[id], x, y + gMonFrontPicCoords[species].y_offset, subpriority);
    else
        spriteId = CreateSprite(&sSpriteTemplate_MoveEffectMons[id], x, y + gMonBackPicCoords[species].y_offset, subpriority);

    if (IsContest())
    {
        gSprites[spriteId].affineAnims = gAffineAnims_BattleSpriteContest;
        StartSpriteAffineAnim(&gSprites[spriteId], BATTLER_AFFINE_NORMAL);
    }
    return spriteId;
}

void DestroySpriteAndFreeResources_(struct Sprite *sprite)
{
    DestroySpriteAndFreeResources(sprite);
}

s16 GetBattlerSpriteCoordAttr(u8 battlerId, u8 attr)
{
    u16 species;
    u32 personality;
    int ret;
    const struct MonCoords *coords;
    struct BattleSpriteInfo *spriteInfo;

    if (IsContest())
    {
        if (gContestResources->moveAnim->hasTargetAnim)
        {
            species = gContestResources->moveAnim->targetSpecies;
            personality = gContestResources->moveAnim->targetPersonality;
        }
        else
        {
            species = gContestResources->moveAnim->species;
            personality = gContestResources->moveAnim->personality;
        }
        if (species == SPECIES_UNOWN)
        {
            species = GetUnownSpeciesId(personality);
            coords = &gMonBackPicCoords[species];
        }
        else if (species == SPECIES_CASTFORM)
        {
            coords = &gCastformFrontSpriteCoords[gBattleMonForms[battlerId]];
        }
        else if (species <= SPECIES_EGG)
        {
            coords = &gMonBackPicCoords[species];
        }
        else
        {
            coords = &gMonBackPicCoords[0];
        }
    }
    else
    {
        if (GetBattlerSide(battlerId) == B_SIDE_PLAYER)
        {
            spriteInfo = gBattleSpritesDataPtr->battlerData;
            if (!spriteInfo[battlerId].transformSpecies)
            {
                species = GetMonData(&gPlayerParty[gBattlerPartyIndexes[battlerId]], MON_DATA_SPECIES);
                personality = GetMonData(&gPlayerParty[gBattlerPartyIndexes[battlerId]], MON_DATA_PERSONALITY);
            }
            else
            {
                species = spriteInfo[battlerId].transformSpecies;
                personality = gTransformedPersonalities[battlerId];
            }

            if (species == SPECIES_UNOWN)
            {
                species = GetUnownSpeciesId(personality);
                coords = &gMonBackPicCoords[species];
            }
            else if (species > NUM_SPECIES)
            {
                coords = &gMonBackPicCoords[0];
            }
            else
            {
                coords = &gMonBackPicCoords[species];
            }
        }
        else
        {
            spriteInfo = gBattleSpritesDataPtr->battlerData;
            if (!spriteInfo[battlerId].transformSpecies)
            {
                species = GetMonData(&gEnemyParty[gBattlerPartyIndexes[battlerId]], MON_DATA_SPECIES);
                personality = GetMonData(&gEnemyParty[gBattlerPartyIndexes[battlerId]], MON_DATA_PERSONALITY);
            }
            else
            {
                species = spriteInfo[battlerId].transformSpecies;
                personality = gTransformedPersonalities[battlerId];
            }

            if (species == SPECIES_UNOWN)
            {
                species = GetUnownSpeciesId(personality);
                coords = &gMonFrontPicCoords[species];
            }
            else if (species == SPECIES_CASTFORM)
            {
                coords = &gCastformFrontSpriteCoords[gBattleMonForms[battlerId]];
            }
            else if (species > NUM_SPECIES)
            {
                coords = &gMonFrontPicCoords[0];
            }
            else
            {
                coords = &gMonFrontPicCoords[species];
            }
        }
    }

    switch (attr)
    {
    case BATTLER_COORD_ATTR_HEIGHT:
        return (coords->size & 0xf) * 8;
    case BATTLER_COORD_ATTR_WIDTH:
        return (coords->size >> 4) * 8;
    case BATTLER_COORD_ATTR_LEFT:
        return GetBattlerSpriteCoord(battlerId, BATTLER_COORD_X_2) - ((coords->size >> 4) * 4);
    case BATTLER_COORD_ATTR_RIGHT:
        return GetBattlerSpriteCoord(battlerId, BATTLER_COORD_X_2) + ((coords->size >> 4) * 4);
    case BATTLER_COORD_ATTR_TOP:
        return GetBattlerSpriteCoord(battlerId, BATTLER_COORD_Y_PIC_OFFSET) - ((coords->size & 0xf) * 4);
    case BATTLER_COORD_ATTR_BOTTOM:
        return GetBattlerSpriteCoord(battlerId, BATTLER_COORD_Y_PIC_OFFSET) + ((coords->size & 0xf) * 4);
    case BATTLER_COORD_ATTR_RAW_BOTTOM:
        ret = GetBattlerSpriteCoord(battlerId, BATTLER_COORD_Y) + 31;
        return ret - coords->y_offset;
    default:
        return 0;
    }
}

void SetAverageBattlerPositions(u8 battlerId, bool8 respectMonPicOffsets, s16 *x, s16 *y)
{
    u8 xCoordType, yCoordType;
    s16 battlerX, battlerY;
    s16 partnerX, partnerY;

    if (!respectMonPicOffsets)
    {
        xCoordType = BATTLER_COORD_X;
        yCoordType = BATTLER_COORD_Y;
    }
    else
    {
        xCoordType = BATTLER_COORD_X_2;
        yCoordType = BATTLER_COORD_Y_PIC_OFFSET;
    }

    battlerX = GetBattlerSpriteCoord(battlerId, xCoordType);
    battlerY = GetBattlerSpriteCoord(battlerId, yCoordType);
    if (IsDoubleBattle() && !IsContest())
    {
        partnerX = GetBattlerSpriteCoord(BATTLE_PARTNER(battlerId), xCoordType);
        partnerY = GetBattlerSpriteCoord(BATTLE_PARTNER(battlerId), yCoordType);
    }
    else
    {
        partnerX = battlerX;
        partnerY = battlerY;
    }

    *x = (battlerX + partnerX) / 2;
    *y = (battlerY + partnerY) / 2;
}

u8 CreateInvisibleSpriteCopy(int battlerId, u8 spriteId, int species)
{
    u8 newSpriteId = CreateInvisibleSpriteWithCallback(SpriteCallbackDummy);
    gSprites[newSpriteId] = gSprites[spriteId];
    gSprites[newSpriteId].usingSheet = TRUE;
    gSprites[newSpriteId].oam.priority = 0;
    gSprites[newSpriteId].oam.objMode = ST_OAM_OBJ_WINDOW;
    gSprites[newSpriteId].oam.tileNum = gSprites[spriteId].oam.tileNum;
    gSprites[newSpriteId].callback = SpriteCallbackDummy;
    return newSpriteId;
}

void AnimTranslateLinearAndFlicker_Flipped(struct Sprite *sprite)
{
    SetSpriteCoordsToAnimAttackerCoords(sprite);
    if (GetBattlerSide(gBattleAnimAttacker))
    {
        sprite->x -= gBattleAnimArgs[0];
        gBattleAnimArgs[3] = -gBattleAnimArgs[3];
        sprite->hFlip = TRUE;
    }
    else
    {
        sprite->x += gBattleAnimArgs[0];
    }
    sprite->y += gBattleAnimArgs[1];
    sprite->data[0] = gBattleAnimArgs[2];
    sprite->data[1] = gBattleAnimArgs[3];
    sprite->data[3] = gBattleAnimArgs[4];
    sprite->data[5] = gBattleAnimArgs[5];
    StoreSpriteCallbackInData6(sprite, DestroySpriteAndMatrix);
    sprite->callback = TranslateSpriteLinearAndFlicker;
}

// Used by three different unused battle anim sprite templates.
void AnimTranslateLinearAndFlicker(struct Sprite *sprite)
{
    if (GetBattlerSide(gBattleAnimAttacker) != B_SIDE_PLAYER)
    {
        sprite->x -= gBattleAnimArgs[0];
        gBattleAnimArgs[3] *= -1;
    }
    else
    {
        sprite->x += gBattleAnimArgs[0];
    }
    sprite->y += gBattleAnimArgs[1];
    sprite->data[0] = gBattleAnimArgs[2];
    sprite->data[1] = gBattleAnimArgs[3];
    sprite->data[3] = gBattleAnimArgs[4];
    sprite->data[5] = gBattleAnimArgs[5];
    StartSpriteAnim(sprite, gBattleAnimArgs[6]);
    StoreSpriteCallbackInData6(sprite, DestroySpriteAndMatrix);
    sprite->callback = TranslateSpriteLinearAndFlicker;
}

// Used by Detect/Disable
void AnimSpinningSparkle(struct Sprite *sprite)
{
    SetSpriteCoordsToAnimAttackerCoords(sprite);
    if (GetBattlerSide(gBattleAnimAttacker))
        sprite->x -= gBattleAnimArgs[0];
    else
        sprite->x += gBattleAnimArgs[0];
    sprite->y += gBattleAnimArgs[1];
    sprite->callback = RunStoredCallbackWhenAnimEnds;
    StoreSpriteCallbackInData6(sprite, DestroyAnimSprite);
}

// Slides attacker to right and back with a cloned trace of the specified color
// arg0: Trace palette blend color
// arg1: Trace palette blend coeff
void AnimTask_AttackerPunchWithTrace(u8 taskId)
{
    u16 src;
    u16 dest;
    struct Task *task = &gTasks[taskId];

    task->data[0] = GetAnimBattlerSpriteId(ANIM_ATTACKER);
    task->data[1] = ((GetBattlerSide(gBattleAnimAttacker)) != B_SIDE_PLAYER) ? -8 : 8;
    task->data[2] = 0;
    task->data[3] = 0;
    gSprites[task->data[0]].x2 -= task->data[0];
    task->data[4] = AllocSpritePalette(ANIM_TAG_BENT_SPOON);
    task->data[5] = 0;

    dest = (task->data[4] + 0x10) * 0x10;
    src = (gSprites[task->data[0]].oam.paletteNum + 0x10) * 0x10;
    task->data[6] = GetBattlerSpriteSubpriority(gBattleAnimAttacker);
    if (task->data[6] == 20 || task->data[6] == 40)
        task->data[6] = 2;
    else
        task->data[6] = 3;
    CpuCopy32(&gPlttBufferUnfaded[src], &gPlttBufferFaded[dest], 0x20);
    BlendPalette(dest, 16, gBattleAnimArgs[1], gBattleAnimArgs[0]);
    task->func = AnimTask_AttackerPunchWithTrace_Step;
}

static void AnimTask_AttackerPunchWithTrace_Step(u8 taskId)
{
    struct Task *task = &gTasks[taskId];
    switch (task->data[2])
    {
    case 0:
        sub_80A8D78(task, taskId);
        gSprites[task->data[0]].x2 += task->data[1];
        if (++task->data[3] == 5)
        {
            task->data[3]--;
            task->data[2]++;
        }
        break;
    case 1:
        sub_80A8D78(task, taskId);
        gSprites[task->data[0]].x2 -= task->data[1];
        if (--task->data[3] == 0)
        {
            gSprites[task->data[0]].x2 = 0;
            task->data[2]++;
        }
        break;
    case 2:
        if (!task->data[5])
        {
            FreeSpritePaletteByTag(ANIM_TAG_BENT_SPOON);
            DestroyAnimVisualTask(taskId);
        }
        break;
    }
}

static void sub_80A8D78(struct Task *task, u8 taskId)
{
    s16 spriteId = CloneBattlerSpriteWithBlend(0);
    if (spriteId >= 0)
    {
        gSprites[spriteId].oam.priority = task->data[6];
        gSprites[spriteId].oam.paletteNum = task->data[4];
        gSprites[spriteId].data[0] = 8;
        gSprites[spriteId].data[1] = taskId;
        gSprites[spriteId].data[2] = spriteId;
        gSprites[spriteId].x2 = gSprites[task->data[0]].x2;
        gSprites[spriteId].callback = sub_80A8DFC;
        task->data[5]++;
    }
}

static void sub_80A8DFC(struct Sprite *sprite)
{
    if (--sprite->data[0] == 0)
    {
        gTasks[sprite->data[1]].data[5]--;
        obj_delete_but_dont_free_vram(sprite);
    }
}

void AnimWeatherBallUp(struct Sprite *sprite)
{
    sprite->x = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_X_2);
    sprite->y = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_Y_PIC_OFFSET);
    if (!GetBattlerSide(gBattleAnimAttacker))
        sprite->data[0] = 5;
    else
        sprite->data[0] = -10;
    sprite->data[1] = -40;
    sprite->callback = AnimWeatherBallUp_Step;
}

static void AnimWeatherBallUp_Step(struct Sprite *sprite)
{
    sprite->data[2] += sprite->data[0];
    sprite->data[3] += sprite->data[1];
    sprite->x2 = sprite->data[2] / 10;
    sprite->y2 = sprite->data[3] / 10;
    if (sprite->data[1] < -20)
        sprite->data[1]++;
    if (sprite->y + sprite->y2 < -32)
        DestroyAnimSprite(sprite);
}

void AnimWeatherBallDown(struct Sprite *sprite)
{
    int x;
    sprite->data[0] = gBattleAnimArgs[2];
    sprite->data[2] = sprite->x + gBattleAnimArgs[4];
    sprite->data[4] = sprite->y + gBattleAnimArgs[5];
    if (!GetBattlerSide(gBattleAnimTarget))
    {
        x = (u16)gBattleAnimArgs[4] + 30;
        sprite->x += x;
        sprite->y = gBattleAnimArgs[5] - 20;
    }
    else
    {
        x = (u16)gBattleAnimArgs[4] - 30;
        sprite->x += x;
        sprite->y = gBattleAnimArgs[5] - 80;
    }
    sprite->callback = StartAnimLinearTranslation;
    StoreSpriteCallbackInData6(sprite, DestroyAnimSprite);
}
