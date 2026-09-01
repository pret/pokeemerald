#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_LAST_RESORT) == EFFECT_LAST_RESORT);
}

SINGLE_BATTLE_TEST("Last Resort always fails if it's the only known move (Gen9)")
{
    GIVEN {
        WITH_CONFIG(B_LAST_RESORT_SELECTABLE, GEN_9);
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_LAST_RESORT); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_LAST_RESORT); }
        TURN { MOVE(player, MOVE_LAST_RESORT); }
    } SCENE {
        MESSAGE("Wobbuffet used Last Resort!");
        MESSAGE("But it failed!");
        MESSAGE("Wobbuffet used Last Resort!");
        MESSAGE("But it failed!");
        NOT HP_BAR(opponent);
    }
}

SINGLE_BATTLE_TEST("Last Resort as the only known move results in Struggle (Champions)")
{
    GIVEN {
        WITH_CONFIG(B_LAST_RESORT_SELECTABLE, GEN_CHAMPIONS);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_LAST_RESORT); }
    } WHEN {
        TURN {
            MOVE(opponent, MOVE_LAST_RESORT, allowed: FALSE);
        }
    } SCENE {
        MESSAGE("The opposing Wobbuffet used Struggle!");
    }
}

SINGLE_BATTLE_TEST("Last Resort works only when all of the known moves have been used - 2 moves")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_LAST_RESORT, MOVE_SCRATCH); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_LAST_RESORT); }
        TURN { MOVE(player, MOVE_SCRATCH); }
        TURN { MOVE(player, MOVE_LAST_RESORT); }
    } SCENE {
        MESSAGE("Wobbuffet used Last Resort!");
        MESSAGE("But it failed!");
        MESSAGE("Wobbuffet used Scratch!");
        MESSAGE("Wobbuffet used Last Resort!");
        HP_BAR(opponent);
    }
}

SINGLE_BATTLE_TEST("Last Resort works only when all of the known moves have been used - 3 moves")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_LAST_RESORT, MOVE_QUICK_ATTACK, MOVE_SCRATCH); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_LAST_RESORT); }
        TURN { MOVE(player, MOVE_QUICK_ATTACK); }
        TURN { MOVE(player, MOVE_LAST_RESORT); }
        TURN { MOVE(player, MOVE_SCRATCH); }
        TURN { MOVE(player, MOVE_LAST_RESORT); }
    } SCENE {
        MESSAGE("Wobbuffet used Last Resort!");
        MESSAGE("But it failed!");
        MESSAGE("Wobbuffet used Quick Attack!");
        MESSAGE("Wobbuffet used Last Resort!");
        MESSAGE("But it failed!");
        MESSAGE("Wobbuffet used Scratch!");
        MESSAGE("Wobbuffet used Last Resort!");
        HP_BAR(opponent);
    }
}

SINGLE_BATTLE_TEST("Last Resort works only when all of the known moves have been used - 4 moves")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_LAST_RESORT, MOVE_QUICK_ATTACK, MOVE_SCRATCH, MOVE_GUST); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_LAST_RESORT); }
        TURN { MOVE(player, MOVE_QUICK_ATTACK); }
        TURN { MOVE(player, MOVE_LAST_RESORT); }
        TURN { MOVE(player, MOVE_SCRATCH); }
        TURN { MOVE(player, MOVE_LAST_RESORT); }
        TURN { MOVE(player, MOVE_GUST); }
        TURN { MOVE(player, MOVE_LAST_RESORT); }
    } SCENE {
        MESSAGE("Wobbuffet used Last Resort!");
        MESSAGE("But it failed!");
        MESSAGE("Wobbuffet used Quick Attack!");
        MESSAGE("Wobbuffet used Last Resort!");
        MESSAGE("But it failed!");
        MESSAGE("Wobbuffet used Scratch!");
        MESSAGE("Wobbuffet used Last Resort!");
        MESSAGE("But it failed!");
        MESSAGE("Wobbuffet used Gust!");
        MESSAGE("Wobbuffet used Last Resort!");
        HP_BAR(opponent);
    }
}

// PP needs to be deducted for Last Resort to work
SINGLE_BATTLE_TEST("Last Resort fails if mon was paralyzed last turn")
{
    GIVEN {
        WITH_CONFIG(B_LAST_RESORT_SELECTABLE, GEN_9);
        PLAYER(SPECIES_WOBBUFFET) { Status1(STATUS1_PARALYSIS); Moves(MOVE_LAST_RESORT, MOVE_CELEBRATE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE, WITH_RNG(RNG_PARALYSIS, TRUE)); }
        TURN { MOVE(player, MOVE_LAST_RESORT); }
    } SCENE {
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_LAST_RESORT, player);
        }
    }
}

SINGLE_BATTLE_TEST("Last Resort does not fail if previous move was blocked by Dazzling")
{
    GIVEN {
        ASSUME(GetMovePriority(MOVE_QUICK_ATTACK) > 0);
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_LAST_RESORT, MOVE_QUICK_ATTACK); }
        OPPONENT(SPECIES_BRUXISH) { Ability(ABILITY_DAZZLING); }
    } WHEN {
        TURN { MOVE(player, MOVE_QUICK_ATTACK); }
        TURN { MOVE(player, MOVE_LAST_RESORT); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_DAZZLING);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_QUICK_ATTACK, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_LAST_RESORT, player);
    }
}

SINGLE_BATTLE_TEST("Last Resort works with Sleep Talk")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_SLEEP_TALK) == EFFECT_SLEEP_TALK);
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_LAST_RESORT, MOVE_SLEEP_TALK); Status1(STATUS1_SLEEP_TURN(3)); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SLEEP_TALK); }
        TURN { MOVE(player, MOVE_SLEEP_TALK); }
    } SCENE {
        // Turn 1
        MESSAGE("Wobbuffet used Sleep Talk!");
        MESSAGE("Wobbuffet used Last Resort!");
        NOT MESSAGE("But it failed!");
        HP_BAR(opponent);
        // Turn 2
        MESSAGE("Wobbuffet used Sleep Talk!");
        MESSAGE("Wobbuffet used Last Resort!");
        NOT MESSAGE("But it failed!");
        HP_BAR(opponent);
    }
}

AI_SINGLE_BATTLE_TEST("AI uses Last Resort - 2 moves")
{
    AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_LAST_RESORT, MOVE_SCRATCH); }
    } WHEN {
        TURN { NOT_EXPECT_MOVE(opponent, MOVE_LAST_RESORT); }
        TURN { EXPECT_MOVE(opponent, MOVE_LAST_RESORT); }
    }
}

AI_SINGLE_BATTLE_TEST("AI uses Last Resort - 3 moves")
{
    AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { MovesWithPP({MOVE_LAST_RESORT, 5}, {MOVE_QUICK_ATTACK, 1}, {MOVE_SCRATCH, 35}); }
    } WHEN {
        TURN { NOT_EXPECT_MOVE(opponent, MOVE_LAST_RESORT); }
        TURN { NOT_EXPECT_MOVE(opponent, MOVE_LAST_RESORT); }
        TURN { EXPECT_MOVE(opponent, MOVE_LAST_RESORT); }
    }
}

AI_SINGLE_BATTLE_TEST("AI uses Last Resort - 4 moves")
{
    AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { MovesWithPP({MOVE_LAST_RESORT, 5}, {MOVE_QUICK_ATTACK, 1}, {MOVE_SCRATCH, 1}, {MOVE_GUST, 35}); }
    } WHEN {
        TURN { NOT_EXPECT_MOVE(opponent, MOVE_LAST_RESORT); }
        TURN { NOT_EXPECT_MOVE(opponent, MOVE_LAST_RESORT); }
        TURN { NOT_EXPECT_MOVE(opponent, MOVE_LAST_RESORT); }
        TURN { EXPECT_MOVE(opponent, MOVE_LAST_RESORT); }
    }
}
