#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Anger Point raises Attack stage to maximum after receiving a critical hit")
{
    ASSUME(gMovesInfo[MOVE_FROST_BREATH].alwaysCriticalHit);

    GIVEN {
        PLAYER(SPECIES_PRIMEAPE) { Ability(ABILITY_ANGER_POINT); }
        OPPONENT(SPECIES_SNORUNT);
    } WHEN {
        TURN { MOVE(opponent, MOVE_FROST_BREATH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FROST_BREATH, opponent);
        MESSAGE("A critical hit!");
        ABILITY_POPUP(player, ABILITY_ANGER_POINT);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        MESSAGE("Primeape's Anger Point maxed its Attack!");
    } THEN {
        EXPECT_EQ(player->statStages[STAT_ATK], MAX_STAT_STAGE);
    }
}

SINGLE_BATTLE_TEST("Anger Point does not trigger when already at maximum Attack stage")
{
    ASSUME(gMovesInfo[MOVE_FROST_BREATH].alwaysCriticalHit);
    ASSUME(gMovesInfo[MOVE_BELLY_DRUM].effect == EFFECT_BELLY_DRUM);

    GIVEN {
        PLAYER(SPECIES_PRIMEAPE) { Ability(ABILITY_ANGER_POINT); Speed(2); }
        OPPONENT(SPECIES_SNORUNT) { Speed(1); }
    } WHEN {
        TURN { MOVE(player, MOVE_BELLY_DRUM); MOVE(opponent, MOVE_FROST_BREATH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BELLY_DRUM, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        MESSAGE("Primeape cut its own HP and maximized ATTACK!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FROST_BREATH, opponent);
        MESSAGE("A critical hit!");
        NONE_OF {
            ABILITY_POPUP(player, ABILITY_ANGER_POINT);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
            MESSAGE("Primeape's Anger Point maxed its Attack!");
        }
    } THEN {
        EXPECT_EQ(player->statStages[STAT_ATK], MAX_STAT_STAGE);
    }
}

TO_DO_BATTLE_TEST("Anger Point triggers when a substitute takes the hit (Gen4)");

SINGLE_BATTLE_TEST("Anger Point does not trigger when a substitute takes the hit (Gen5+)")
{
    ASSUME(gMovesInfo[MOVE_FROST_BREATH].alwaysCriticalHit);
    ASSUME(gMovesInfo[MOVE_SUBSTITUTE].effect == EFFECT_SUBSTITUTE);

    GIVEN {
        PLAYER(SPECIES_PRIMEAPE) { Ability(ABILITY_ANGER_POINT); Speed(2); }
        OPPONENT(SPECIES_SNORUNT) { Speed(1); }
    } WHEN {
        TURN { MOVE(player, MOVE_SUBSTITUTE); MOVE(opponent, MOVE_FROST_BREATH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SUBSTITUTE, player);
        MESSAGE("Primeape made a SUBSTITUTE!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FROST_BREATH, opponent);
        MESSAGE("A critical hit!");
        NONE_OF {
            ABILITY_POPUP(player, ABILITY_ANGER_POINT);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
            MESSAGE("Primeape's Anger Point maxed its Attack!");
        }
    } THEN {
        EXPECT_EQ(player->statStages[STAT_ATK], DEFAULT_STAT_STAGE);
    }
}
