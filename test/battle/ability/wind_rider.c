#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gMovesInfo[MOVE_TAILWIND].effect == EFFECT_TAILWIND);
    ASSUME(gMovesInfo[MOVE_TAILWIND].windMove == TRUE);
}

SINGLE_BATTLE_TEST("Wind Rider raises Attack by one stage if it sets up Tailwind")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_BRAMBLIN) { Ability(ABILITY_WIND_RIDER); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_TAILWIND); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TAILWIND, opponent);
        ABILITY_POPUP(opponent, ABILITY_WIND_RIDER);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        MESSAGE("Foe Bramblin's Attack rose!");
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_ATK], DEFAULT_STAT_STAGE + 1);
    }
}

DOUBLE_BATTLE_TEST("Wind Rider raises Attack by one stage if Tailwind is setup by its partner")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_BRAMBLIN) { Ability(ABILITY_WIND_RIDER); }
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_TAILWIND); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TAILWIND, opponentLeft);
        ABILITY_POPUP(opponentRight, ABILITY_WIND_RIDER);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentRight);
        MESSAGE("Foe Bramblin's Attack rose!");
    } THEN {
        EXPECT_EQ(opponentRight->statStages[STAT_ATK], DEFAULT_STAT_STAGE + 1);
    }
}

SINGLE_BATTLE_TEST("Wind Rider doesn't raise Attack if opponent sets up Tailwind")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_BRAMBLIN) { Ability(ABILITY_WIND_RIDER); }
    } WHEN {
        TURN { MOVE(player, MOVE_TAILWIND); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TAILWIND, player);
        NONE_OF {
            ABILITY_POPUP(opponent, ABILITY_WIND_RIDER);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
            MESSAGE("Foe Bramblin's Attack rose!");
        }
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_ATK], DEFAULT_STAT_STAGE);
    }
}

SINGLE_BATTLE_TEST("Wind Rider raises Attack by one stage if switched into Tailwind on its side of the field")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
        OPPONENT(SPECIES_BRAMBLIN) { Ability(ABILITY_WIND_RIDER); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_TAILWIND); }
        TURN { SWITCH(opponent, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TAILWIND, opponent);
        ABILITY_POPUP(opponent, ABILITY_WIND_RIDER);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        MESSAGE("Foe Bramblin's Wind Rider raised its Attack!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_ATK], DEFAULT_STAT_STAGE + 1);
    }
}

SINGLE_BATTLE_TEST("Wind Rider activates when it's no longer effected by Neutralizing Gas")
{
    GIVEN {
        PLAYER(SPECIES_WEEZING) { Ability(ABILITY_NEUTRALIZING_GAS); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_BRAMBLIN) { Ability(ABILITY_WIND_RIDER); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_TAILWIND); }
        TURN { SWITCH(player, 1); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_NEUTRALIZING_GAS);
        MESSAGE("Neutralizing Gas filled the area!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TAILWIND, opponent);
        SWITCH_OUT_MESSAGE("Weezing");
        MESSAGE("The effects of Neutralizing Gas wore off!");
        ABILITY_POPUP(opponent, ABILITY_WIND_RIDER);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        MESSAGE("Foe Bramblin's Wind Rider raised its Attack!");
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_ATK], DEFAULT_STAT_STAGE + 1);
    }
}

SINGLE_BATTLE_TEST("Wind Rider absorbs Wind moves and raises Attack by one stage")
{
    ASSUME(gMovesInfo[MOVE_GUST].windMove == TRUE);
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_BRAMBLIN) { Ability(ABILITY_WIND_RIDER); }
    } WHEN {
        TURN { MOVE(player, MOVE_GUST); }
    } SCENE {
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_GUST, player);
            HP_BAR(opponent);
        }
        ABILITY_POPUP(opponent, ABILITY_WIND_RIDER);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        MESSAGE("Foe Bramblin's Attack rose!");
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_ATK], DEFAULT_STAT_STAGE + 1);
    }
}
