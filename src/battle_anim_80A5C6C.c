#include "global.h"
#include "constants/battle_anim.h"
#include "constants/species.h"
#include "battle.h"
#include "battle_anim.h"
#include "blend_palette.h"
#include "contest.h"
#include "data2.h"
#include "decompress.h"
#include "palette.h"
#include "pokemon_icon.h"
#include "sprite.h"
#include "task.h"
#include "trig.h"
#include "util.h"
#include "gpu_regs.h"

#define GET_UNOWN_LETTER(personality) ((\
      (((personality & 0x03000000) >> 24) << 6) \
    | (((personality & 0x00030000) >> 16) << 4) \
    | (((personality & 0x00000300) >> 8) << 2) \
    | (((personality & 0x00000003) >> 0) << 0) \
) % 28)

#define IS_DOUBLE_BATTLE() ((gBattleTypeFlags & BATTLE_TYPE_DOUBLE))

extern const struct OamData gUnknown_0852497C;
extern const struct MonCoords gMonFrontPicCoords[];
extern const struct MonCoords gMonBackPicCoords[];
extern const u8 gEnemyMonElevation[];

// This file's functions.
void sub_80A64EC(struct Sprite *sprite);
void sub_80A653C(struct Sprite *sprite);
void InitAnimLinearTranslation(struct Sprite *sprite);
bool8 TranslateAnimLinear(struct Sprite *sprite);

// Const rom data
const struct UCoords8 sBattlerCoords[][4] =
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
    { 0x44, 17 }, // NORMAL
    { 0x66, 9 }, // SUN
    { 0x46, 9 }, // RAIN
    { 0x86, 8 }, // HAIL
};

const u8 gCastformElevations[] =
{
    13, // NORMAL
    14, // SUN
    13, // RAIN
    13, // HAIL
};

// Y position of the backsprite for each of the four Castform forms.
const u8 gCastformBackSpriteYCoords[] =
{
    0, // NORMAL
    0, // SUN
    0, // RAIN
    0, // HAIL
};

const struct SpriteTemplate gUnknown_08525F90[] =
{
    {
        .tileTag = 55125,
        .paletteTag = 55125,
        .oam = &gUnknown_0852497C,
        .anims = gDummySpriteAnimTable,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCallbackDummy,
    },
    {
        .tileTag = 55126,
        .paletteTag = 55126,
        .oam = &gUnknown_0852497C,
        .anims = gDummySpriteAnimTable,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCallbackDummy,
    }
};

const struct SpriteSheet gUnknown_08525FC0[] =
{
    { gMiscBlank_Gfx, 0x800, 55125, },
    { gMiscBlank_Gfx, 0x800, 55126, },
};

// code
u8 GetBattlerSpriteCoord(u8 battlerId, u8 attributeId)
{
    u8 retVal;
    u16 species;
    struct BattleSpriteInfo *spriteInfo;

    if (IsContest())
    {
        if (attributeId == BATTLER_COORD_3 && battlerId == 3)
            attributeId = BATTLER_COORD_Y;
    }

    switch (attributeId)
    {
    case BATTLER_COORD_X:
    case BATTLER_COORD_X_2:
        retVal = sBattlerCoords[IS_DOUBLE_BATTLE()][GetBattlerPosition(battlerId)].x;
        break;
    case BATTLER_COORD_Y:
        retVal = sBattlerCoords[IS_DOUBLE_BATTLE()][GetBattlerPosition(battlerId)].y;
        break;
    case BATTLER_COORD_3:
    case BATTLER_COORD_4:
    default:
        if (IsContest())
        {
            if (shared19348.unk4_0)
                species = shared19348.unk2;
            else
                species = shared19348.unk0;
        }
        else
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
        }
        if (attributeId == BATTLER_COORD_3)
            retVal = GetBattlerSpriteFinal_Y(battlerId, species, TRUE);
        else
            retVal = GetBattlerSpriteFinal_Y(battlerId, species, FALSE);
        break;
    }

    return retVal;
}

u8 GetBattlerYDelta(u8 battlerId, u16 species)
{
    u16 letter;
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
                if (shared19348.unk4_0)
                    personality = shared19348.unk10;
                else
                    personality = shared19348.unk8;
            }
            else
            {
                spriteInfo = gBattleSpritesDataPtr->battlerData;
                if (!spriteInfo[battlerId].transformSpecies)
                    personality = GetMonData(&gPlayerParty[gBattlerPartyIndexes[battlerId]], MON_DATA_PERSONALITY);
                else
                    personality = gTransformedPersonalities[battlerId];
            }
            letter = GET_UNOWN_LETTER(personality);
            if (!letter)
                coordSpecies = species;
            else
                coordSpecies = letter + SPECIES_UNOWN_B - 1;
            ret = gMonBackPicCoords[coordSpecies].y_offset;
        }
        else if (species == SPECIES_CASTFORM)
        {
            ret = gCastformBackSpriteYCoords[gBattleMonForms[battlerId]];
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
            letter = GET_UNOWN_LETTER(personality);
            if (!letter)
                coordSpecies = species;
            else
                coordSpecies = letter + SPECIES_UNOWN_B - 1;
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
                ret = gCastformElevations[gBattleMonForms[battlerId]];
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

u8 GetBattlerSpriteCoord2(u8 battlerId, u8 attributeId)
{
    u16 species;
    struct BattleSpriteInfo *spriteInfo;

    if (attributeId == BATTLER_COORD_3 || attributeId == BATTLER_COORD_4)
    {
        if (IsContest())
        {
            if (shared19348.unk4_0)
                species = shared19348.unk2;
            else
                species = shared19348.unk0;
        }
        else
        {
            spriteInfo = gBattleSpritesDataPtr->battlerData;
            if (!spriteInfo[battlerId].transformSpecies)
                species = gAnimBattlerSpecies[battlerId];
            else
                species = spriteInfo[battlerId].transformSpecies;
        }
        if (attributeId == BATTLER_COORD_3)
            return GetBattlerSpriteFinal_Y(battlerId, species, TRUE);
        else
            return GetBattlerSpriteFinal_Y(battlerId, species, FALSE);
    }
    else
    {
        return GetBattlerSpriteCoord(battlerId, attributeId);
    }
}

u8 GetBattlerSpriteDefault_Y(u8 battlerId)
{
    return GetBattlerSpriteCoord(battlerId, BATTLER_COORD_4);
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

u8 GetAnimBattlerSpriteId(u8 which)
{
    u8 *sprites;

    if (which == ANIM_ATTACKER)
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
    else if (which == ANIM_TARGET)
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
    else if (which == ANIM_ATK_PARTNER)
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

void sub_80A62EC(struct Sprite *sprite)
{
    if (sprite->data[3])
    {
        sprite->pos2.x = Sin(sprite->data[0], sprite->data[1]);
        sprite->pos2.y = Cos(sprite->data[0], sprite->data[1]);
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

void sub_80A634C(struct Sprite *sprite)
{
    if (sprite->data[3])
    {
        sprite->pos2.x = Sin(sprite->data[0], (sprite->data[5] >> 8) + sprite->data[1]);
        sprite->pos2.y = Cos(sprite->data[0], (sprite->data[5] >> 8) + sprite->data[1]);
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
        sprite->pos2.x = Sin(sprite->data[0], sprite->data[1]);
        sprite->pos2.y = Cos(sprite->data[4], sprite->data[1]);
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

void sub_80A6450(struct Sprite *sprite)
{
    if (sprite->data[3])
    {
        sprite->pos2.x = Sin(sprite->data[0], sprite->data[1]);
        sprite->pos2.y = Cos(sprite->data[0], sprite->data[4]);
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
void sub_80A64B0(struct Sprite *sprite)
{
    if (sprite->data[0] > 0)
        sprite->data[0]--;
    else
        SetCallbackToStoredInData6(sprite);
}

void sub_80A64D0(struct Sprite *sprite)
{
    sub_80A64EC(sprite);
    sprite->callback = sub_80A653C;
    sprite->callback(sprite);
}

void sub_80A64EC(struct Sprite *sprite)
{
    s16 old;
    int v1;

    if (sprite->data[1] > sprite->data[2])
        sprite->data[0] = -sprite->data[0];
    v1 = sprite->data[2] - sprite->data[1];
    old = sprite->data[0];
    sprite->data[0] = abs(v1 / sprite->data[0]);
    sprite->data[2] = (sprite->data[4] - sprite->data[3]) / sprite->data[0];
    sprite->data[1] = old;
}

void sub_80A653C(struct Sprite *sprite)
{
    if (sprite->data[0] > 0)
    {
        sprite->data[0]--;
        sprite->pos2.x += sprite->data[1];
        sprite->pos2.y += sprite->data[2];
    }
    else
    {
        SetCallbackToStoredInData6(sprite);
    }
}

void sub_80A656C(struct Sprite *sprite)
{
    if (sprite->data[0] > 0)
    {
        sprite->data[0]--;
        sprite->data[3] += sprite->data[1];
        sprite->data[4] += sprite->data[2];
        sprite->pos2.x = sprite->data[3] >> 8;
        sprite->pos2.y = sprite->data[4] >> 8;
    }
    else
    {
        SetCallbackToStoredInData6(sprite);
    }
}

void sub_80A65A8(struct Sprite *sprite)
{
    if (sprite->data[0] > 0)
    {
        sprite->data[0]--;
        sprite->data[3] += sprite->data[1];
        sprite->data[4] += sprite->data[2];
        sprite->pos2.x = sprite->data[3] >> 8;
        sprite->pos2.y = sprite->data[4] >> 8;
    }
    else
    {
        SetCallbackToStoredInData6(sprite);
    }
    UpdateMonIconFrame(sprite);
}

void sub_80A65EC(struct Sprite *sprite)
{
    sprite->data[1] = sprite->pos1.x + sprite->pos2.x;
    sprite->data[3] = sprite->pos1.y + sprite->pos2.y;
    sprite->data[2] = GetBattlerSpriteCoord(gBattleAnimTarget, 2);
    sprite->data[4] = GetBattlerSpriteCoord(gBattleAnimTarget, 3);
    sprite->callback = sub_80A64D0;
}

void sub_80A6630(struct Sprite *sprite)
{
    if (sprite->data[0] > 0)
    {
        sprite->data[0]--;
        gSprites[sprite->data[3]].pos2.x += sprite->data[1];
        gSprites[sprite->data[3]].pos2.y += sprite->data[2];
    }
    else
    {
        SetCallbackToStoredInData6(sprite);
    }
}

// Same as sub_80A6630, but it operates on sub-pixel values
// to handle slower translations.
void sub_80A6680(struct Sprite *sprite)
{
    if (sprite->data[0] > 0)
    {
        sprite->data[0]--;
        sprite->data[3] += sprite->data[1];
        sprite->data[4] += sprite->data[2];
        gSprites[sprite->data[5]].pos2.x = sprite->data[3] >> 8;
        gSprites[sprite->data[5]].pos2.y = sprite->data[4] >> 8;
    }
    else
    {
        SetCallbackToStoredInData6(sprite);
    }
}

void sub_80A66DC(struct Sprite *sprite)
{
    if (sprite->data[0] > 0)
    {
        sprite->data[0]--;
        sprite->pos2.x = sprite->data[2] >> 8;
        sprite->data[2] += sprite->data[1];
        sprite->pos2.y = sprite->data[4] >> 8;
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

void move_anim_8074EE0(struct Sprite *sprite)
{
    FreeSpriteOamMatrix(sprite);
    DestroyAnimSprite(sprite);
}

void sub_80A6760(struct Sprite *sprite)
{
    sprite->data[1] = sprite->pos1.x + sprite->pos2.x;
    sprite->data[3] = sprite->pos1.y + sprite->pos2.y;
    sprite->data[2] = GetBattlerSpriteCoord(gBattleAnimAttacker, 2);
    sprite->data[4] = GetBattlerSpriteCoord(gBattleAnimAttacker, 3);
    sprite->callback = sub_80A64D0;
}

void sub_80A67A4(struct Sprite *sprite)
{
    ResetPaletteStructByUid(sprite->data[5]);
    move_anim_8074EE0(sprite);
}

void sub_80A67BC(struct Sprite *sprite)
{
    if (sprite->affineAnimEnded)
        SetCallbackToStoredInData6(sprite);
}

void sub_80A67D8(struct Sprite *sprite)
{
    if (sprite->animEnded)
        SetCallbackToStoredInData6(sprite);
}

void sub_80A67F4(struct Sprite *sprite)
{
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
    SetGpuReg(REG_OFFSET_BLDALPHA, 0);
    DestroyAnimSprite(sprite);
}

void sub_80A6814(u8 taskId)
{
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
    SetGpuReg(REG_OFFSET_BLDALPHA, 0);
    DestroyAnimVisualTask(taskId);
}

void sub_80A6838(struct Sprite *sprite)
{
    sprite->pos1.x = GetBattlerSpriteCoord(gBattleAnimAttacker, 2);
    sprite->pos1.y = GetBattlerSpriteCoord(gBattleAnimAttacker, 3);
}

void sub_80A6864(struct Sprite *sprite, s16 a2)
{
    u16 v1 = GetBattlerSpriteCoord(gBattleAnimAttacker, 0);
    u16 v2 = GetBattlerSpriteCoord(gBattleAnimTarget, 0);

    if (v1 > v2)
    {
        sprite->pos1.x -= a2;
    }
    else if (v1 < v2)
    {
        sprite->pos1.x += a2;
    }
    else
    {
        if (GetBattlerSide(gBattleAnimAttacker) != 0)
            sprite->pos1.x -= a2;
        else
            sprite->pos1.x += a2;
    }
}

void sub_80A68D4(struct Sprite *sprite)
{
    sprite->data[1] = sprite->pos1.x;
    sprite->data[3] = sprite->pos1.y;
    InitAnimLinearTranslation(sprite);
    sprite->data[6] = 0x8000 / sprite->data[0];
    sprite->data[7] = 0;
}

bool8 TranslateAnimArc(struct Sprite *sprite)
{
    if (TranslateAnimLinear(sprite))
        return TRUE;
    sprite->data[7] += sprite->data[6];
    sprite->pos2.y += Sin((u8)(sprite->data[7] >> 8), sprite->data[5]);
    return FALSE;
}
