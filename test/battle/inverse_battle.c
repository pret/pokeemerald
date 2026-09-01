#include "global.h"
#include "test/battle.h"

static bool32 IsSpeciesMonotypeOf(enum Species species, enum Type type)
{
    return GetSpeciesType(species, 0) == type && GetSpeciesType(species, 1) == type;
}

static u16 GetInverseEffectivenessSound(enum Move move, u32 species)
{
    switch (gTypeEffectivenessTable[GetMoveType(move)][GetSpeciesType(species, 0)])
    {
    case UQ_4_12(2.0):
        return SE_NOT_EFFECTIVE;
    case UQ_4_12(0.0):
    case UQ_4_12(0.5):
        return SE_SUPER_EFFECTIVE;
    case UQ_4_12(1.0):
    default:
        return SE_EFFECTIVE;
    }
}

ASSUMPTIONS
{
    // Pokemon Types
    ASSUME(IsSpeciesMonotypeOf(SPECIES_EEVEE,    TYPE_NORMAL));
    ASSUME(IsSpeciesMonotypeOf(SPECIES_MACHAMP,  TYPE_FIGHTING));
    ASSUME(IsSpeciesMonotypeOf(SPECIES_TORNADUS, TYPE_FLYING));
    ASSUME(IsSpeciesMonotypeOf(SPECIES_ARBOK,    TYPE_POISON));
    ASSUME(IsSpeciesMonotypeOf(SPECIES_DUGTRIO,  TYPE_GROUND));
    ASSUME(IsSpeciesMonotypeOf(SPECIES_SUDOWOODO,TYPE_ROCK));
    ASSUME(IsSpeciesMonotypeOf(SPECIES_PINSIR,   TYPE_BUG));
    ASSUME(IsSpeciesMonotypeOf(SPECIES_DUSKULL,  TYPE_GHOST));
    ASSUME(IsSpeciesMonotypeOf(SPECIES_REGISTEEL,TYPE_STEEL));
    ASSUME(IsSpeciesMonotypeOf(SPECIES_FLAREON,  TYPE_FIRE));
    ASSUME(IsSpeciesMonotypeOf(SPECIES_VAPOREON, TYPE_WATER));
    ASSUME(IsSpeciesMonotypeOf(SPECIES_LEAFEON,  TYPE_GRASS));
    ASSUME(IsSpeciesMonotypeOf(SPECIES_JOLTEON,  TYPE_ELECTRIC));
    ASSUME(IsSpeciesMonotypeOf(SPECIES_ESPEON,   TYPE_PSYCHIC));
    ASSUME(IsSpeciesMonotypeOf(SPECIES_GLACEON,  TYPE_ICE));
    ASSUME(IsSpeciesMonotypeOf(SPECIES_DRUDDIGON,TYPE_DRAGON));
    ASSUME(IsSpeciesMonotypeOf(SPECIES_UMBREON,  TYPE_DARK));
    ASSUME(IsSpeciesMonotypeOf(SPECIES_SYLVEON,  TYPE_FAIRY));

    // Move types
    ASSUME(GetMoveType(MOVE_TACKLE)        == TYPE_NORMAL);
    ASSUME(GetMoveType(MOVE_KARATE_CHOP)   == TYPE_FIGHTING);
    ASSUME(GetMoveType(MOVE_GUST)          == TYPE_FLYING);
    ASSUME(GetMoveType(MOVE_POISON_STING)  == TYPE_POISON);
    ASSUME(GetMoveType(MOVE_MUD_SLAP)      == TYPE_GROUND);
    ASSUME(GetMoveType(MOVE_ROCK_THROW)    == TYPE_ROCK);
    ASSUME(GetMoveType(MOVE_BUG_BITE)      == TYPE_BUG);
    ASSUME(GetMoveType(MOVE_SHADOW_BALL)   == TYPE_GHOST);
    ASSUME(GetMoveType(MOVE_METAL_CLAW)    == TYPE_STEEL);
    ASSUME(GetMoveType(MOVE_EMBER)         == TYPE_FIRE);
    ASSUME(GetMoveType(MOVE_WATER_GUN)     == TYPE_WATER);
    ASSUME(GetMoveType(MOVE_VINE_WHIP)     == TYPE_GRASS);
    ASSUME(GetMoveType(MOVE_THUNDER_SHOCK) == TYPE_ELECTRIC);
    ASSUME(GetMoveType(MOVE_CONFUSION)     == TYPE_PSYCHIC);
    ASSUME(GetMoveType(MOVE_ICE_BEAM)      == TYPE_ICE);
    ASSUME(GetMoveType(MOVE_DRAGON_BREATH) == TYPE_DRAGON);
    ASSUME(GetMoveType(MOVE_BITE)          == TYPE_DARK);
    ASSUME(GetMoveType(MOVE_FAIRY_WIND)    == TYPE_FAIRY);

    // Move power
    ASSUME(GetMovePower(MOVE_TACKLE)        > 0);
    ASSUME(GetMovePower(MOVE_KARATE_CHOP)   > 0);
    ASSUME(GetMovePower(MOVE_GUST)          > 0);
    ASSUME(GetMovePower(MOVE_POISON_STING)  > 0);
    ASSUME(GetMovePower(MOVE_MUD_SLAP)      > 0);
    ASSUME(GetMovePower(MOVE_ROCK_THROW)    > 0);
    ASSUME(GetMovePower(MOVE_BUG_BITE)      > 0);
    ASSUME(GetMovePower(MOVE_SHADOW_BALL)   > 0);
    ASSUME(GetMovePower(MOVE_METAL_CLAW)    > 0);
    ASSUME(GetMovePower(MOVE_EMBER)         > 0);
    ASSUME(GetMovePower(MOVE_WATER_GUN)     > 0);
    ASSUME(GetMovePower(MOVE_VINE_WHIP)     > 0);
    ASSUME(GetMovePower(MOVE_THUNDER_SHOCK) > 0);
    ASSUME(GetMovePower(MOVE_CONFUSION)     > 0);
    ASSUME(GetMovePower(MOVE_ICE_BEAM)      > 0);
    ASSUME(GetMovePower(MOVE_DRAGON_BREATH) > 0);
    ASSUME(GetMovePower(MOVE_BITE)          > 0);
    ASSUME(GetMovePower(MOVE_FAIRY_WIND)    > 0);
}

SINGLE_BATTLE_TEST("Inverse battle reverses type matchups")
{
    enum Species species = SPECIES_NONE;
    enum Move move = MOVE_NONE;

    static const u16 monotypeMons[] = {
        SPECIES_EEVEE,
        SPECIES_MACHAMP,
        SPECIES_TORNADUS,
        SPECIES_ARBOK,
        SPECIES_DUGTRIO,
        SPECIES_SUDOWOODO,
        SPECIES_PINSIR,
        SPECIES_DUSKULL,
        SPECIES_REGISTEEL,
        SPECIES_FLAREON,
        SPECIES_VAPOREON,
        SPECIES_LEAFEON,
        SPECIES_JOLTEON,
        SPECIES_ESPEON,
        SPECIES_GLACEON,
        SPECIES_DRUDDIGON,
        SPECIES_UMBREON,
        SPECIES_SYLVEON,
    };

    static const u16 typeMoves[] = {
        MOVE_TACKLE,
        MOVE_KARATE_CHOP,
        MOVE_GUST,
        MOVE_POISON_STING,
        MOVE_MUD_SLAP,
        MOVE_ROCK_THROW,
        MOVE_BUG_BITE,
        MOVE_SHADOW_BALL,
        MOVE_METAL_CLAW,
        MOVE_EMBER,
        MOVE_WATER_GUN,
        MOVE_VINE_WHIP,
        MOVE_THUNDER_SHOCK,
        MOVE_CONFUSION,
        MOVE_ICE_BEAM,
        MOVE_DRAGON_BREATH,
        MOVE_BITE,
        MOVE_FAIRY_WIND,
    };

    for (u32 monIdx = 0; monIdx < ARRAY_COUNT(monotypeMons); monIdx++)
    {
        for (u32 moveIdx = 0; moveIdx < ARRAY_COUNT(typeMoves); moveIdx++)
        {
            PARAMETRIZE { species = monotypeMons[monIdx]; move = typeMoves[moveIdx]; }
        }
    }

    GIVEN {
        FLAG_SET(B_FLAG_INVERSE_BATTLE);
        ASSUME(GetMoveEffect(MOVE_WORRY_SEED) == EFFECT_OVERWRITE_ABILITY);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(species);
    }
    WHEN {
        TURN { MOVE(player, MOVE_WORRY_SEED); }
        TURN { MOVE(player, move); }
    }
    SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_WORRY_SEED, player);
        ANIMATION(ANIM_TYPE_MOVE, move, player);
        EFFECTIVENESS_SE(opponent, GetInverseEffectivenessSound(move, species));
        HP_BAR(opponent);
    } THEN {
        EXPECT_EQ(opponent->ability, ABILITY_INSOMNIA);
    }
}
