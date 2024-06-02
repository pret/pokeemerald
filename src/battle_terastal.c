#include "global.h"
#include "battle.h"
#include "battle_anim.h"
#include "battle_controllers.h"
#include "battle_interface.h"
#include "battle_terastal.h"
#include "event_data.h"
#include "item.h"
#include "palette.h"
#include "pokemon.h"
#include "safari_zone.h"
#include "sprite.h"
#include "util.h"
#include "constants/abilities.h"
#include "constants/hold_effects.h"
#include "constants/rgb.h"

// Sets flags and variables upon a battler's Terastallization.
void PrepareBattlerForTera(u32 battler)
{
    u32 side = GetBattlerSide(battler);
    u32 index = gBattlerPartyIndexes[battler];

    // Update TeraData fields.
    gBattleStruct->tera.isTerastallized[side] |= gBitTable[index];
    gBattleStruct->tera.alreadyTerastallized[battler] = TRUE;

    // Remove Tera Orb charge.    
    if (B_FLAG_TERA_ORB_CHARGED != 0
        && (B_FLAG_TERA_ORB_NO_COST == 0 || !FlagGet(B_FLAG_TERA_ORB_NO_COST))
        && side == B_SIDE_PLAYER
        && !(gBattleTypeFlags & BATTLE_TYPE_DOUBLE && !IsPartnerMonFromSameTrainer(battler)))
    {
        FlagClear(B_FLAG_TERA_ORB_CHARGED);
    }
}

// Applies palette blend and enables UI indicator after animation has played
void ApplyBattlerVisualsForTeraAnim(u32 battler)
{
    struct Pokemon *party = GetBattlerParty(battler);
    u32 index = gBattlerPartyIndexes[battler];

    // Show indicator and do palette blend.
    UpdateHealthboxAttribute(gHealthboxSpriteIds[battler], &party[index], HEALTHBOX_ALL);
    BlendPalette(OBJ_PLTT_ID(battler), 16, 8, GetTeraTypeRGB(GetBattlerTeraType(battler)));
    CpuCopy32(gPlttBufferFaded + OBJ_PLTT_ID(battler), gPlttBufferUnfaded + OBJ_PLTT_ID(battler), PLTT_SIZEOF(16));

    // We apply the animation behind a white screen, so restore the blended color here to avoid a pop
    BlendPalette(OBJ_PLTT_ID(battler), 16, 16, RGB_WHITEALPHA);
}

// Returns whether a battler can Terastallize.
bool32 CanTerastallize(u32 battler)
{
    u32 holdEffect = GetBattlerHoldEffect(battler, FALSE);

    // Check if Player has Tera Orb and has charge.
    if (!CheckBagHasItem(ITEM_TERA_ORB, 1)
        || !((B_FLAG_TERA_ORB_NO_COST != 0 && FlagGet(B_FLAG_TERA_ORB_NO_COST))
        || (B_FLAG_TERA_ORB_CHARGED != 0 && FlagGet(B_FLAG_TERA_ORB_CHARGED)
        && ((battler == B_POSITION_PLAYER_LEFT || (!(gBattleTypeFlags & BATTLE_TYPE_MULTI) && battler == B_POSITION_PLAYER_RIGHT))))))
    {
        return FALSE;
    }

    // Check if Trainer has already Terastallized.
    if (gBattleStruct->tera.alreadyTerastallized[battler])
    {
        return FALSE;
    }

    if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE
        && IsPartnerMonFromSameTrainer(battler)
        && (gBattleStruct->tera.alreadyTerastallized[BATTLE_PARTNER(battler)]
        || (gBattleStruct->tera.toTera & gBitTable[BATTLE_PARTNER(battler)])))
    {
        return FALSE;
    }

    // Check if battler is holding a Z-Crystal or Mega Stone.
    if (holdEffect == HOLD_EFFECT_Z_CRYSTAL || holdEffect == HOLD_EFFECT_MEGA_STONE)
    {
        return FALSE;
    }

    // Every check passed!
    return TRUE;
}

// Returns a battler's Tera type.
u32 GetBattlerTeraType(u32 battler)
{
    struct Pokemon *mon = &GetBattlerParty(battler)[gBattlerPartyIndexes[battler]];
    return GetMonData(mon, MON_DATA_TERA_TYPE);
}

// Returns whether a battler is terastallized.
bool32 IsTerastallized(u32 battler)
{
    return gBattleStruct->tera.isTerastallized[GetBattlerSide(battler)] & gBitTable[gBattlerPartyIndexes[battler]];
}


// Uses up a type's Stellar boost.
void ExpendTypeStellarBoost(u32 battler, u32 type)
{
    if (type < 32) // avoid OOB access
        gBattleStruct->tera.stellarBoostFlags[GetBattlerSide(battler)] |= gBitTable[type];
}

// Checks whether a type's Stellar boost has been expended.
bool32 IsTypeStellarBoosted(u32 battler, u32 type)
{
    if (type < 32) // avoid OOB access
        return !(gBattleStruct->tera.stellarBoostFlags[GetBattlerSide(battler)] & gBitTable[type]);
    else
        return FALSE;
}

// Returns the STAB power multiplier to use when Terastallized.
// Power multipliers from Smogon Research thread.
uq4_12_t GetTeraMultiplier(u32 battler, u32 type)
{
    u32 teraType = GetBattlerTeraType(battler);
    bool32 hasAdaptability = (GetBattlerAbility(battler) == ABILITY_ADAPTABILITY);

    // Safety check.
    if (!IsTerastallized(battler))
        return UQ_4_12(1.0);
    
    // Stellar-type checks.
    if (teraType == TYPE_STELLAR)
    {
        bool32 shouldBoost = IsTypeStellarBoosted(battler, type);
        if (IS_BATTLER_OF_BASE_TYPE(battler, type))
        {
            if (shouldBoost)
                return UQ_4_12(2.0);
            else
                return UQ_4_12(1.5);
        }
        else if (shouldBoost)
            return UQ_4_12(1.2);
        else
            return UQ_4_12(1.0);
    }
    // Base and Tera type.
    if (type == teraType && IS_BATTLER_OF_BASE_TYPE(battler, type))
    {
        if (hasAdaptability)
            return UQ_4_12(2.25);
        else
            return UQ_4_12(2.0);
    }
    // Base or Tera type only.
    else if ((type == teraType && !IS_BATTLER_OF_BASE_TYPE(battler, type))
             || (type != teraType && IS_BATTLER_OF_BASE_TYPE(battler, type)))
    {
        if (hasAdaptability)
            return UQ_4_12(2.0);
        else
            return UQ_4_12(1.5);
    }
    // Neither base or Tera type.
    else
    {
        return UQ_4_12(1.0);
    }
}

u16 GetTeraTypeRGB(u32 type)
{
    return gTypesInfo[type].teraTypeRGBValue;
}

// TERASTAL TRIGGER:
static const u8 ALIGNED(4) sTeraTriggerGfx[] = INCBIN_U8("graphics/battle_interface/tera_trigger.4bpp");
static const u16 sTeraTriggerPal[] = INCBIN_U16("graphics/battle_interface/tera_trigger.gbapal");

static const struct SpriteSheet sSpriteSheet_TeraTrigger =
{
    sTeraTriggerGfx, sizeof(sTeraTriggerGfx), TAG_TERA_TRIGGER_TILE
};
static const struct SpritePalette sSpritePalette_TeraTrigger =
{
    sTeraTriggerPal, TAG_TERA_TRIGGER_PAL
};

static const struct OamData sOamData_TeraTrigger =
{
    .y = 0,
    .affineMode = 0,
    .objMode = 0,
    .mosaic = 0,
    .bpp = 0,
    .shape = ST_OAM_SQUARE,
    .x = 0,
    .matrixNum = 0,
    .size = 2,
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0,
};

static const union AnimCmd sSpriteAnim_TeraTriggerOff[] =
{
    ANIMCMD_FRAME(0, 0),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_TeraTriggerOn[] =
{
    ANIMCMD_FRAME(16, 0),
    ANIMCMD_END
};

static const union AnimCmd *const sSpriteAnimTable_TeraTrigger[] =
{
    sSpriteAnim_TeraTriggerOff,
    sSpriteAnim_TeraTriggerOn,
};

static void SpriteCb_TeraTrigger(struct Sprite *sprite);
static const struct SpriteTemplate sSpriteTemplate_TeraTrigger =
{
    .tileTag = TAG_TERA_TRIGGER_TILE,
    .paletteTag = TAG_TERA_TRIGGER_PAL,
    .oam = &sOamData_TeraTrigger,
    .anims = sSpriteAnimTable_TeraTrigger,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCb_TeraTrigger
};

// Tera Evolution Trigger icon functions.
void ChangeTeraTriggerSprite(u8 spriteId, u8 animId)
{
    StartSpriteAnim(&gSprites[spriteId], animId);
}

#define SINGLES_TERA_TRIGGER_POS_X_OPTIMAL (30)
#define SINGLES_TERA_TRIGGER_POS_X_PRIORITY (31)
#define SINGLES_TERA_TRIGGER_POS_X_SLIDE (15)
#define SINGLES_TERA_TRIGGER_POS_Y_DIFF (-11)

#define DOUBLES_TERA_TRIGGER_POS_X_OPTIMAL (30)
#define DOUBLES_TERA_TRIGGER_POS_X_PRIORITY (31)
#define DOUBLES_TERA_TRIGGER_POS_X_SLIDE (15)
#define DOUBLES_TERA_TRIGGER_POS_Y_DIFF (-4)

#define tBattler    data[0]
#define tHide       data[1]

void CreateTeraTriggerSprite(u8 battler, u8 palId)
{
    LoadSpritePalette(&sSpritePalette_TeraTrigger);
    if (GetSpriteTileStartByTag(TAG_TERA_TRIGGER_TILE) == 0xFFFF)
    {
        LoadSpriteSheet(&sSpriteSheet_TeraTrigger);
    }
    if (gBattleStruct->tera.triggerSpriteId == 0xFF)
    {
        if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
            gBattleStruct->tera.triggerSpriteId = CreateSprite(&sSpriteTemplate_TeraTrigger,
                                                             gSprites[gHealthboxSpriteIds[battler]].x - DOUBLES_TERA_TRIGGER_POS_X_SLIDE,
                                                             gSprites[gHealthboxSpriteIds[battler]].y - DOUBLES_TERA_TRIGGER_POS_Y_DIFF, 0);
        else
            gBattleStruct->tera.triggerSpriteId = CreateSprite(&sSpriteTemplate_TeraTrigger,
                                                             gSprites[gHealthboxSpriteIds[battler]].x - SINGLES_TERA_TRIGGER_POS_X_SLIDE,
                                                             gSprites[gHealthboxSpriteIds[battler]].y - SINGLES_TERA_TRIGGER_POS_Y_DIFF, 0);
    }
    gSprites[gBattleStruct->tera.triggerSpriteId].tBattler = battler;
    gSprites[gBattleStruct->tera.triggerSpriteId].tHide = FALSE;

    ChangeTeraTriggerSprite(gBattleStruct->tera.triggerSpriteId, palId);
}

static void SpriteCb_TeraTrigger(struct Sprite *sprite)
{
    s32 xSlide, xPriority, xOptimal;
    s32 yDiff;

    if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
    {
        xSlide = DOUBLES_TERA_TRIGGER_POS_X_SLIDE;
        xPriority = DOUBLES_TERA_TRIGGER_POS_X_PRIORITY;
        xOptimal = DOUBLES_TERA_TRIGGER_POS_X_OPTIMAL;
        yDiff = DOUBLES_TERA_TRIGGER_POS_Y_DIFF;
    }
    else
    {
        xSlide = SINGLES_TERA_TRIGGER_POS_X_SLIDE;
        xPriority = SINGLES_TERA_TRIGGER_POS_X_PRIORITY;
        xOptimal = SINGLES_TERA_TRIGGER_POS_X_OPTIMAL;
        yDiff = SINGLES_TERA_TRIGGER_POS_Y_DIFF;
    }

    if (sprite->tHide)
    {
        if (sprite->x != gSprites[gHealthboxSpriteIds[sprite->tBattler]].x - xSlide)
            sprite->x++;

        if (sprite->x >= gSprites[gHealthboxSpriteIds[sprite->tBattler]].x - xPriority)
            sprite->oam.priority = 2;
        else
            sprite->oam.priority = 1;

        sprite->y = gSprites[gHealthboxSpriteIds[sprite->tBattler]].y - yDiff;
        sprite->y2 = gSprites[gHealthboxSpriteIds[sprite->tBattler]].y2 - yDiff;
        if (sprite->x == gSprites[gHealthboxSpriteIds[sprite->tBattler]].x - xSlide)
            DestroyTeraTriggerSprite();
    }
    else
    {
        if (sprite->x != gSprites[gHealthboxSpriteIds[sprite->tBattler]].x - xOptimal)
            sprite->x--;

        if (sprite->x >= gSprites[gHealthboxSpriteIds[sprite->tBattler]].x - xPriority)
            sprite->oam.priority = 2;
        else
            sprite->oam.priority = 1;

        sprite->y = gSprites[gHealthboxSpriteIds[sprite->tBattler]].y - yDiff;
        sprite->y2 = gSprites[gHealthboxSpriteIds[sprite->tBattler]].y2 - yDiff;
    }
}

bool32 IsTeraTriggerSpriteActive(void)
{
    if (GetSpriteTileStartByTag(TAG_TERA_TRIGGER_TILE) == 0xFFFF)
        return FALSE;
    else if (IndexOfSpritePaletteTag(TAG_TERA_TRIGGER_PAL) != 0xFF)
        return TRUE;
    else
        return FALSE;
}

void HideTeraTriggerSprite(void)
{
    if (gBattleStruct->tera.triggerSpriteId != 0xFF)
    {
        ChangeTeraTriggerSprite(gBattleStruct->tera.triggerSpriteId, 0);
        gSprites[gBattleStruct->tera.triggerSpriteId].tHide = TRUE;
    }
}

void DestroyTeraTriggerSprite(void)
{
    FreeSpritePaletteByTag(TAG_TERA_TRIGGER_PAL);
    FreeSpriteTilesByTag(TAG_TERA_TRIGGER_TILE);
    if (gBattleStruct->tera.triggerSpriteId != 0xFF)
        DestroySprite(&gSprites[gBattleStruct->tera.triggerSpriteId]);
    gBattleStruct->tera.triggerSpriteId = 0xFF;
}

#undef tBattler
#undef tHide

// TERA INDICATOR:
static const u16 sTeraIndicatorPal[] = INCBIN_U16("graphics/battle_interface/tera_indicator.gbapal");
static const u8 ALIGNED(4) sNormalIndicatorGfx[] = INCBIN_U8("graphics/battle_interface/normal_indicator.4bpp");
static const u8 ALIGNED(4) sFightingIndicatorGfx[] = INCBIN_U8("graphics/battle_interface/fighting_indicator.4bpp");
static const u8 ALIGNED(4) sFlyingIndicatorGfx[] = INCBIN_U8("graphics/battle_interface/flying_indicator.4bpp");
static const u8 ALIGNED(4) sPoisonIndicatorGfx[] = INCBIN_U8("graphics/battle_interface/poison_indicator.4bpp");
static const u8 ALIGNED(4) sGroundIndicatorGfx[] = INCBIN_U8("graphics/battle_interface/ground_indicator.4bpp");
static const u8 ALIGNED(4) sRockIndicatorGfx[] = INCBIN_U8("graphics/battle_interface/rock_indicator.4bpp");
static const u8 ALIGNED(4) sBugIndicatorGfx[] = INCBIN_U8("graphics/battle_interface/bug_indicator.4bpp");
static const u8 ALIGNED(4) sGhostIndicatorGfx[] = INCBIN_U8("graphics/battle_interface/ghost_indicator.4bpp");
static const u8 ALIGNED(4) sSteelIndicatorGfx[] = INCBIN_U8("graphics/battle_interface/steel_indicator.4bpp");
static const u8 ALIGNED(4) sFireIndicatorGfx[] = INCBIN_U8("graphics/battle_interface/fire_indicator.4bpp");
static const u8 ALIGNED(4) sWaterIndicatorGfx[] = INCBIN_U8("graphics/battle_interface/water_indicator.4bpp");
static const u8 ALIGNED(4) sGrassIndicatorGfx[] = INCBIN_U8("graphics/battle_interface/grass_indicator.4bpp");
static const u8 ALIGNED(4) sElectricIndicatorGfx[] = INCBIN_U8("graphics/battle_interface/electric_indicator.4bpp");
static const u8 ALIGNED(4) sPsychicIndicatorGfx[] = INCBIN_U8("graphics/battle_interface/psychic_indicator.4bpp");
static const u8 ALIGNED(4) sIceIndicatorGfx[] = INCBIN_U8("graphics/battle_interface/ice_indicator.4bpp");
static const u8 ALIGNED(4) sDragonIndicatorGfx[] = INCBIN_U8("graphics/battle_interface/dragon_indicator.4bpp");
static const u8 ALIGNED(4) sDarkIndicatorGfx[] = INCBIN_U8("graphics/battle_interface/dark_indicator.4bpp");
static const u8 ALIGNED(4) sFairyIndicatorGfx[] = INCBIN_U8("graphics/battle_interface/fairy_indicator.4bpp");
static const u8 ALIGNED(4) sStellarIndicatorGfx[] = INCBIN_U8("graphics/battle_interface/stellar_indicator.4bpp");

static void SpriteCb_TeraIndicator(struct Sprite *sprite);
static const s8 sIndicatorPositions[][2] =
{
    [B_POSITION_PLAYER_LEFT] = {53, -9},
    [B_POSITION_OPPONENT_LEFT] = {44, -9},
    [B_POSITION_PLAYER_RIGHT] = {52, -9},
    [B_POSITION_OPPONENT_RIGHT] = {44, -9},
};

static const struct SpritePalette sSpritePalette_TeraIndicator =
{
    sTeraIndicatorPal, TAG_TERA_INDICATOR_PAL
};

static const struct OamData sOamData_TeraIndicator =
{
    .shape = SPRITE_SHAPE(16x16),
    .size = SPRITE_SIZE(16x16),
    .priority = 1,
};

static const struct SpriteTemplate sSpriteTemplate_NormalIndicator =
{
    .tileTag = TAG_NORMAL_INDICATOR_TILE,
    .paletteTag = TAG_TERA_INDICATOR_PAL,
    .oam = &sOamData_TeraIndicator,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCb_TeraIndicator,
};

static const struct SpriteTemplate sSpriteTemplate_FightingIndicator =
{
    .tileTag = TAG_FIGHTING_INDICATOR_TILE,
    .paletteTag = TAG_TERA_INDICATOR_PAL,
    .oam = &sOamData_TeraIndicator,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCb_TeraIndicator,
};

static const struct SpriteTemplate sSpriteTemplate_FlyingIndicator =
{
    .tileTag = TAG_FLYING_INDICATOR_TILE,
    .paletteTag = TAG_TERA_INDICATOR_PAL,
    .oam = &sOamData_TeraIndicator,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCb_TeraIndicator,
};

static const struct SpriteTemplate sSpriteTemplate_PoisonIndicator =
{
    .tileTag = TAG_POISON_INDICATOR_TILE,
    .paletteTag = TAG_TERA_INDICATOR_PAL,
    .oam = &sOamData_TeraIndicator,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCb_TeraIndicator,
};

static const struct SpriteTemplate sSpriteTemplate_GroundIndicator =
{
    .tileTag = TAG_GROUND_INDICATOR_TILE,
    .paletteTag = TAG_TERA_INDICATOR_PAL,
    .oam = &sOamData_TeraIndicator,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCb_TeraIndicator,
};

static const struct SpriteTemplate sSpriteTemplate_RockIndicator =
{
    .tileTag = TAG_ROCK_INDICATOR_TILE,
    .paletteTag = TAG_TERA_INDICATOR_PAL,
    .oam = &sOamData_TeraIndicator,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCb_TeraIndicator,
};

static const struct SpriteTemplate sSpriteTemplate_BugIndicator =
{
    .tileTag = TAG_BUG_INDICATOR_TILE,
    .paletteTag = TAG_TERA_INDICATOR_PAL,
    .oam = &sOamData_TeraIndicator,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCb_TeraIndicator,
};

static const struct SpriteTemplate sSpriteTemplate_GhostIndicator =
{
    .tileTag = TAG_GHOST_INDICATOR_TILE,
    .paletteTag = TAG_TERA_INDICATOR_PAL,
    .oam = &sOamData_TeraIndicator,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCb_TeraIndicator,
};

static const struct SpriteTemplate sSpriteTemplate_SteelIndicator =
{
    .tileTag = TAG_STEEL_INDICATOR_TILE,
    .paletteTag = TAG_TERA_INDICATOR_PAL,
    .oam = &sOamData_TeraIndicator,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCb_TeraIndicator,
};

static const struct SpriteTemplate sSpriteTemplate_FireIndicator =
{
    .tileTag = TAG_FIRE_INDICATOR_TILE,
    .paletteTag = TAG_TERA_INDICATOR_PAL,
    .oam = &sOamData_TeraIndicator,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCb_TeraIndicator,
};

static const struct SpriteTemplate sSpriteTemplate_WaterIndicator =
{
    .tileTag = TAG_WATER_INDICATOR_TILE,
    .paletteTag = TAG_TERA_INDICATOR_PAL,
    .oam = &sOamData_TeraIndicator,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCb_TeraIndicator,
};

static const struct SpriteTemplate sSpriteTemplate_GrassIndicator =
{
    .tileTag = TAG_GRASS_INDICATOR_TILE,
    .paletteTag = TAG_TERA_INDICATOR_PAL,
    .oam = &sOamData_TeraIndicator,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCb_TeraIndicator,
};

static const struct SpriteTemplate sSpriteTemplate_ElectricIndicator =
{
    .tileTag = TAG_ELECTRIC_INDICATOR_TILE,
    .paletteTag = TAG_TERA_INDICATOR_PAL,
    .oam = &sOamData_TeraIndicator,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCb_TeraIndicator,
};

static const struct SpriteTemplate sSpriteTemplate_PsychicIndicator =
{
    .tileTag = TAG_PSYCHIC_INDICATOR_TILE,
    .paletteTag = TAG_TERA_INDICATOR_PAL,
    .oam = &sOamData_TeraIndicator,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCb_TeraIndicator,
};

static const struct SpriteTemplate sSpriteTemplate_IceIndicator =
{
    .tileTag = TAG_ICE_INDICATOR_TILE,
    .paletteTag = TAG_TERA_INDICATOR_PAL,
    .oam = &sOamData_TeraIndicator,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCb_TeraIndicator,
};

static const struct SpriteTemplate sSpriteTemplate_DragonIndicator =
{
    .tileTag = TAG_DRAGON_INDICATOR_TILE,
    .paletteTag = TAG_TERA_INDICATOR_PAL,
    .oam = &sOamData_TeraIndicator,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCb_TeraIndicator,
};

static const struct SpriteTemplate sSpriteTemplate_DarkIndicator =
{
    .tileTag = TAG_DARK_INDICATOR_TILE,
    .paletteTag = TAG_TERA_INDICATOR_PAL,
    .oam = &sOamData_TeraIndicator,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCb_TeraIndicator,
};

static const struct SpriteTemplate sSpriteTemplate_FairyIndicator =
{
    .tileTag = TAG_FAIRY_INDICATOR_TILE,
    .paletteTag = TAG_TERA_INDICATOR_PAL,
    .oam = &sOamData_TeraIndicator,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCb_TeraIndicator,
};

static const struct SpriteTemplate sSpriteTemplate_StellarIndicator =
{
    .tileTag = TAG_STELLAR_INDICATOR_TILE,
    .paletteTag = TAG_TERA_INDICATOR_PAL,
    .oam = &sOamData_TeraIndicator,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCb_TeraIndicator,
};

static const struct SpriteSheet sTeraIndicatorSpriteSheets[NUMBER_OF_MON_TYPES + 1] =
{
    {sNormalIndicatorGfx, sizeof(sNormalIndicatorGfx), TAG_NORMAL_INDICATOR_TILE}, // TYPE_NONE
    {sNormalIndicatorGfx, sizeof(sNormalIndicatorGfx), TAG_NORMAL_INDICATOR_TILE},
    {sFightingIndicatorGfx, sizeof(sFightingIndicatorGfx), TAG_FIGHTING_INDICATOR_TILE},
    {sFlyingIndicatorGfx, sizeof(sFlyingIndicatorGfx), TAG_FLYING_INDICATOR_TILE},
    {sPoisonIndicatorGfx, sizeof(sPoisonIndicatorGfx), TAG_POISON_INDICATOR_TILE},
    {sGroundIndicatorGfx, sizeof(sGroundIndicatorGfx), TAG_GROUND_INDICATOR_TILE},
    {sRockIndicatorGfx, sizeof(sRockIndicatorGfx), TAG_ROCK_INDICATOR_TILE},
    {sBugIndicatorGfx, sizeof(sBugIndicatorGfx), TAG_BUG_INDICATOR_TILE},
    {sGhostIndicatorGfx, sizeof(sGhostIndicatorGfx), TAG_GHOST_INDICATOR_TILE},
    {sSteelIndicatorGfx, sizeof(sSteelIndicatorGfx), TAG_STEEL_INDICATOR_TILE},
    {sNormalIndicatorGfx, sizeof(sNormalIndicatorGfx), TAG_NORMAL_INDICATOR_TILE}, // TYPE_MYSTERY
    {sFireIndicatorGfx, sizeof(sFireIndicatorGfx), TAG_FIRE_INDICATOR_TILE},
    {sWaterIndicatorGfx, sizeof(sWaterIndicatorGfx), TAG_WATER_INDICATOR_TILE},
    {sGrassIndicatorGfx, sizeof(sGrassIndicatorGfx), TAG_GRASS_INDICATOR_TILE},
    {sElectricIndicatorGfx, sizeof(sElectricIndicatorGfx), TAG_ELECTRIC_INDICATOR_TILE},
    {sPsychicIndicatorGfx, sizeof(sPsychicIndicatorGfx), TAG_PSYCHIC_INDICATOR_TILE},
    {sIceIndicatorGfx, sizeof(sIceIndicatorGfx), TAG_ICE_INDICATOR_TILE},
    {sDragonIndicatorGfx, sizeof(sDragonIndicatorGfx), TAG_DRAGON_INDICATOR_TILE},
    {sDarkIndicatorGfx, sizeof(sDarkIndicatorGfx), TAG_DARK_INDICATOR_TILE},
    {sFairyIndicatorGfx, sizeof(sFairyIndicatorGfx), TAG_FAIRY_INDICATOR_TILE},
    {sStellarIndicatorGfx, sizeof(sStellarIndicatorGfx), TAG_STELLAR_INDICATOR_TILE},
    {0}
};

static const struct SpriteTemplate * const sTeraIndicatorSpriteTemplates[NUMBER_OF_MON_TYPES] =
{
    [TYPE_NONE] = &sSpriteTemplate_NormalIndicator, // just in case
    [TYPE_NORMAL] = &sSpriteTemplate_NormalIndicator,
    [TYPE_FIGHTING] = &sSpriteTemplate_FightingIndicator,
    [TYPE_FLYING] = &sSpriteTemplate_FlyingIndicator,
    [TYPE_POISON] = &sSpriteTemplate_PoisonIndicator,
    [TYPE_GROUND] = &sSpriteTemplate_GroundIndicator,
    [TYPE_ROCK] = &sSpriteTemplate_RockIndicator,
    [TYPE_BUG] = &sSpriteTemplate_BugIndicator,
    [TYPE_GHOST] = &sSpriteTemplate_GhostIndicator,
    [TYPE_STEEL] = &sSpriteTemplate_SteelIndicator,
    [TYPE_MYSTERY] = &sSpriteTemplate_NormalIndicator, // just in case
    [TYPE_FIRE] = &sSpriteTemplate_FireIndicator,
    [TYPE_WATER] = &sSpriteTemplate_WaterIndicator,
    [TYPE_GRASS] = &sSpriteTemplate_GrassIndicator,
    [TYPE_ELECTRIC] = &sSpriteTemplate_ElectricIndicator,
    [TYPE_PSYCHIC] = &sSpriteTemplate_PsychicIndicator,
    [TYPE_ICE] = &sSpriteTemplate_IceIndicator,
    [TYPE_DRAGON] = &sSpriteTemplate_DragonIndicator,
    [TYPE_DARK] = &sSpriteTemplate_DarkIndicator,
    [TYPE_FAIRY] = &sSpriteTemplate_FairyIndicator,
    [TYPE_STELLAR] = &sSpriteTemplate_StellarIndicator,
};

// for sprite data fields
#define tBattler        data[0]
#define tType           data[1] // Indicator type: tera
#define tPosX           data[2]
#define tLevelXDelta    data[3] // X position depends whether level has 3, 2 or 1 digit

// data fields for healthboxMain
// oam.affineParam holds healthboxRight spriteId
#define hMain_TeraIndicatorId    data[3]
#define hMain_HealthBarSpriteId     data[5]
#define hMain_Battler               data[6]
#define hMain_Data7                 data[7]

// data fields for healthboxRight
#define hOther_HealthBoxSpriteId    data[5]

// data fields for healthbar
#define hBar_HealthBoxSpriteId      data[5]

void TeraIndicator_LoadSpriteGfx(void)
{
    LoadSpriteSheets(sTeraIndicatorSpriteSheets);
    LoadSpritePalette(&sSpritePalette_TeraIndicator);
}

bool32 TeraIndicator_ShouldBeInvisible(u32 battler)
{
    return !IsTerastallized(battler);
}

u8 TeraIndicator_GetSpriteId(u32 healthboxSpriteId)
{
    return gBattleStruct->tera.indicatorSpriteId[gSprites[healthboxSpriteId].hMain_Battler];
}

void TeraIndicator_SetVisibilities(u32 healthboxId, bool32 invisible)
{
    u8 spriteId = TeraIndicator_GetSpriteId(healthboxId);
    u32 battler = gSprites[healthboxId].hMain_Battler;

    if (GetSafariZoneFlag())
        return;

    if (invisible == TRUE)
        gSprites[spriteId].invisible = TRUE;
    else // Try visible.
        gSprites[spriteId].invisible = TeraIndicator_ShouldBeInvisible(battler);
}

void TeraIndicator_UpdateOamPriorities(u32 healthboxId, u32 oamPriority)
{
    u8 spriteId = TeraIndicator_GetSpriteId(healthboxId);
    gSprites[spriteId].oam.priority = oamPriority;
}

void TeraIndicator_UpdateLevel(u32 healthboxId, u32 level)
{
    s16 xDelta = 0;
    u8 spriteId = TeraIndicator_GetSpriteId(healthboxId);

    if (level >= 100)
        xDelta -= 4;
    else if (level < 10)
        xDelta += 5;

    gSprites[spriteId].tLevelXDelta = xDelta;
}

void TeraIndicator_CreateSprite(u32 battler, u32 healthboxSpriteId)
{
    u32 position;
    u8 spriteId;
    s16 xHealthbox = 0, y = 0;
    s32 x = 0;
    u32 type = GetBattlerTeraType(battler);

    position = GetBattlerPosition(battler);
    GetBattlerHealthboxCoords(battler, &xHealthbox, &y);

    x = sIndicatorPositions[position][0];
    y += sIndicatorPositions[position][1];

    spriteId = gBattleStruct->tera.indicatorSpriteId[battler] = CreateSpriteAtEnd(sTeraIndicatorSpriteTemplates[type], 0, y, 0);
    gSprites[spriteId].tBattler = battler;
    gSprites[spriteId].tPosX = x;
    gSprites[spriteId].invisible = TRUE;
}

void TeraIndicator_DestroySprite(u32 healthboxSpriteId)
{
    u8 spriteId = TeraIndicator_GetSpriteId(healthboxSpriteId);
    DestroySprite(&gSprites[spriteId]);
}

void TeraIndicator_UpdateType(u32 battler, u32 healthboxSpriteId)
{
    TeraIndicator_DestroySprite(healthboxSpriteId);
    TeraIndicator_CreateSprite(battler, healthboxSpriteId);
}

static void SpriteCb_TeraIndicator(struct Sprite *sprite)
{
    u32 battler = sprite->tBattler;

    sprite->x = gSprites[gHealthboxSpriteIds[battler]].x + sprite->tPosX + sprite->tLevelXDelta;
    sprite->x2 = gSprites[gHealthboxSpriteIds[battler]].x2;
    sprite->y2 = gSprites[gHealthboxSpriteIds[battler]].y2;
}

#undef tBattler
#undef tType
#undef tPosX
#undef tLevelXDelta
