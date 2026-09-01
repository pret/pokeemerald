#include "global.h"
#include "test/battle.h"

AI_SINGLE_BATTLE_TEST("Type-absorbing ability checks don't queue stat increases")
{
    enum Ability ability;
    enum Move absorbedMove;
    enum Species species;
    enum Stat boostedStat;

    PARAMETRIZE { species = SPECIES_TATSUGIRI; ability = ABILITY_STORM_DRAIN;   absorbedMove = MOVE_WATER_GUN;   boostedStat = STAT_SPATK; }
    PARAMETRIZE { species = SPECIES_RAICHU;    ability = ABILITY_LIGHTNING_ROD; absorbedMove = MOVE_THUNDERBOLT; boostedStat = STAT_SPATK; }
    PARAMETRIZE { species = SPECIES_MARILL;    ability = ABILITY_SAP_SIPPER;    absorbedMove = MOVE_VINE_WHIP;   boostedStat = STAT_ATK; }

    GIVEN {
        ASSUME(GetMoveType(MOVE_WATER_GUN) == TYPE_WATER);
        ASSUME(GetMoveType(MOVE_THUNDERBOLT) == TYPE_ELECTRIC);
        ASSUME(GetMoveType(MOVE_VINE_WHIP) == TYPE_GRASS);
        ASSUME_STAT_CHANGE(MOVE_GROWL, attack: -1);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_OMNISCIENT);
        PLAYER(species) { Ability(ability); Speed(1); }
        OPPONENT(SPECIES_WOBBUFFET) { Moves(absorbedMove, MOVE_GROWL); Speed(2); }
    } WHEN {
        TURN { EXPECT_MOVE(opponent, MOVE_GROWL); }
    } THEN {
        EXPECT_EQ(player->statStages[STAT_ATK], DEFAULT_STAT_STAGE - 1);
        if (boostedStat != STAT_ATK)
            EXPECT_EQ(player->statStages[boostedStat], DEFAULT_STAT_STAGE);
    }
}

AI_SINGLE_BATTLE_TEST("Type-absorbing abilities only increase a stat once after AI checks")
{
    enum Ability ability;
    enum Move absorbedMove;
    enum Species species;
    enum Stat boostedStat;

    PARAMETRIZE { species = SPECIES_TATSUGIRI; ability = ABILITY_STORM_DRAIN;   absorbedMove = MOVE_WATER_GUN;   boostedStat = STAT_SPATK; }
    PARAMETRIZE { species = SPECIES_RAICHU;    ability = ABILITY_LIGHTNING_ROD; absorbedMove = MOVE_THUNDERBOLT; boostedStat = STAT_SPATK; }
    PARAMETRIZE { species = SPECIES_MARILL;    ability = ABILITY_SAP_SIPPER;    absorbedMove = MOVE_VINE_WHIP;   boostedStat = STAT_ATK; }

    GIVEN {
        ASSUME(GetMoveType(MOVE_WATER_GUN) == TYPE_WATER);
        ASSUME(GetMoveType(MOVE_THUNDERBOLT) == TYPE_ELECTRIC);
        ASSUME(GetMoveType(MOVE_VINE_WHIP) == TYPE_GRASS);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_OMNISCIENT);
        PLAYER(species) { Ability(ability); Speed(1); }
        OPPONENT(SPECIES_WOBBUFFET) { Moves(absorbedMove); Speed(2); }
    } WHEN {
        TURN { EXPECT_MOVE(opponent, absorbedMove); }
    } THEN {
        EXPECT_EQ(player->statStages[boostedStat], DEFAULT_STAT_STAGE + 1);
    }
}
