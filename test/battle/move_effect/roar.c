#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_ROAR) == EFFECT_ROAR);
}

SINGLE_BATTLE_TEST("Roar switches the target with a random non-fainted replacement")
{
    PASSES_RANDOMLY(1, 2, RNG_FORCE_RANDOM_SWITCH);
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_BULBASAUR);
        OPPONENT(SPECIES_CHARMANDER);
        OPPONENT(SPECIES_SQUIRTLE) { HP(0); }
    } WHEN {
        TURN { MOVE(player, MOVE_ROAR); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ROAR, player);
        MESSAGE("The opposing Bulbasaur was dragged out!");
    } THEN {
        EXPECT_EQ(gLastUsedMove, MOVE_ROAR);
    }
}

DOUBLE_BATTLE_TEST("Roar switches the target with a random non-battler, non-fainted replacement")
{
    PASSES_RANDOMLY(1, 2, RNG_FORCE_RANDOM_SWITCH);
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
        OPPONENT(SPECIES_BULBASAUR);
        OPPONENT(SPECIES_CHARMANDER);
        OPPONENT(SPECIES_SQUIRTLE) { HP(0); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_ROAR, target: opponentRight); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ROAR, playerLeft);
        MESSAGE("The opposing Bulbasaur was dragged out!");
    }
}

SINGLE_BATTLE_TEST("Roar fails if no replacements")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_ROAR); }
    } SCENE {
        MESSAGE("Wobbuffet used Roar!");
        MESSAGE("But it failed!");
    }
}

SINGLE_BATTLE_TEST("Roar fails if replacements fainted")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT) { HP(0); }
    } WHEN {
        TURN { MOVE(player, MOVE_ROAR); }
    } SCENE {
        MESSAGE("Wobbuffet used Roar!");
        MESSAGE("But it failed!");
    }
}

SINGLE_BATTLE_TEST("Roar fails against target with Guard Dog")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_OKIDOGI) { Ability(ABILITY_GUARD_DOG); }
        OPPONENT(SPECIES_CHARMANDER);
    } WHEN {
        TURN { MOVE(player, MOVE_ROAR); }
    } SCENE {
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_ROAR, player);
            MESSAGE("The opposing Charmander was dragged out!");
        }
        MESSAGE("Wobbuffet used Roar!");
        MESSAGE("But it failed!");
    }
}

SINGLE_BATTLE_TEST("Roar fails to switch out target with Suction Cups")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_OCTILLERY) { Ability(ABILITY_SUCTION_CUPS); }
        OPPONENT(SPECIES_CHARMANDER);
    } WHEN {
        TURN { MOVE(player, MOVE_ROAR); }
    } SCENE {
        MESSAGE("Wobbuffet used Roar!");
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_ROAR, player);
        ABILITY_POPUP(opponent, ABILITY_SUCTION_CUPS);
        MESSAGE("The opposing Octillery is anchored in place with its suction cups!");
        NOT MESSAGE("The opposing Charmander was dragged out!");
    }
}
