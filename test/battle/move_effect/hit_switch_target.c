#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_DRAGON_TAIL) == EFFECT_HIT_SWITCH_TARGET);
    ASSUME(GetMoveEffect(MOVE_LOCK_ON) == EFFECT_LOCK_ON);
}

SINGLE_BATTLE_TEST("Dragon Tail switches the target with a random non-fainted replacement")
{
    PASSES_RANDOMLY(1, 2, RNG_FORCE_RANDOM_SWITCH);
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_BULBASAUR);
        OPPONENT(SPECIES_CHARMANDER);
        OPPONENT(SPECIES_SQUIRTLE) { HP(0); }
    } WHEN {
        TURN { MOVE(player, MOVE_DRAGON_TAIL); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_TAIL, player);
        MESSAGE("The opposing Bulbasaur was dragged out!");
    }
}

DOUBLE_BATTLE_TEST("Dragon Tail switches the target with a random non-battler, non-fainted replacement")
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
        TURN { MOVE(playerLeft, MOVE_DRAGON_TAIL, target: opponentRight); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_TAIL, playerLeft);
        MESSAGE("The opposing Bulbasaur was dragged out!");
    }
}

SINGLE_BATTLE_TEST("Dragon Tail fails if no replacements")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_DRAGON_TAIL); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_TAIL, player);
        NOT MESSAGE("But it failed!");
    }
}

SINGLE_BATTLE_TEST("Dragon Tail fails if replacements fainted")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT) { HP(0); }
    } WHEN {
        TURN { MOVE(player, MOVE_DRAGON_TAIL); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_TAIL, player);
        NOT MESSAGE("But it failed!");
    }
}

SINGLE_BATTLE_TEST("Dragon Tail switches the target after Rocky Helmet and Iron Barbs")
{
    PASSES_RANDOMLY(1, 2, RNG_FORCE_RANDOM_SWITCH);
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_TOGEDEMARU) { Ability(ABILITY_IRON_BARBS); Item(ITEM_ROCKY_HELMET); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_CHARMANDER);
    } WHEN {
        TURN { MOVE(player, MOVE_DRAGON_TAIL); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_TAIL, player);
        HP_BAR(player);
        HP_BAR(player);
        MESSAGE("Wobbuffet was hurt by the opposing Togedemaru's Rocky Helmet!");
        MESSAGE("The opposing Charmander was dragged out!");
    }
}

SINGLE_BATTLE_TEST("Dragon Tail effect fails against target with Guard Dog")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_OKIDOGI) { Ability(ABILITY_GUARD_DOG); }
        OPPONENT(SPECIES_CHARMANDER);
    } WHEN {
        TURN { MOVE(player, MOVE_DRAGON_TAIL); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_TAIL, player);
        NOT MESSAGE("The opposing Charmander was dragged out!");
    }
}

SINGLE_BATTLE_TEST("Dragon Tail effect fails against target with Suction Cups")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_OCTILLERY) { Ability(ABILITY_SUCTION_CUPS); }
        OPPONENT(SPECIES_CHARMANDER);
    } WHEN {
        TURN { MOVE(player, MOVE_DRAGON_TAIL); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_TAIL, player);
        ABILITY_POPUP(opponent, ABILITY_SUCTION_CUPS);
        MESSAGE("The opposing Octillery is anchored in place with its suction cups!");
        NOT MESSAGE("The opposing Charmander was dragged out!");
    }
}

SINGLE_BATTLE_TEST("Dragon Tail switches target out and incoming mon has Immunity negated by Mold Breaker")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_TOXIC_SPIKES) == EFFECT_TOXIC_SPIKES);
        PLAYER(SPECIES_PANCHAM) { Ability(ABILITY_MOLD_BREAKER); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_SNORLAX) { Ability(ABILITY_IMMUNITY); }
    } WHEN {
        TURN { MOVE(player, MOVE_TOXIC_SPIKES); }
        TURN { MOVE(player, MOVE_DRAGON_TAIL); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TOXIC_SPIKES, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_TAIL, player);
        HP_BAR(opponent);
        MESSAGE("The opposing Snorlax was dragged out!");
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PSN, opponent);
        STATUS_ICON(opponent, poison: TRUE);
    }
}

SINGLE_BATTLE_TEST("Dragon Tail switches target out and incoming mon has Levitate negated by Mold Breaker")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_TOXIC_SPIKES) == EFFECT_TOXIC_SPIKES);
        ASSUME(GetMoveEffect(MOVE_SPIKES) == EFFECT_SPIKES);
        ASSUME(GetSpeciesType(SPECIES_WEEZING, 0) == TYPE_POISON || GetSpeciesType(SPECIES_WEEZING, 1) == TYPE_POISON);
        PLAYER(SPECIES_PANCHAM) { Ability(ABILITY_MOLD_BREAKER); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WEEZING) { Ability(ABILITY_LEVITATE); }
    } WHEN {
        TURN { MOVE(player, MOVE_TOXIC_SPIKES); }
        TURN { MOVE(player, MOVE_SPIKES); }
        TURN { MOVE(player, MOVE_DRAGON_TAIL); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TOXIC_SPIKES, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPIKES, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_TAIL, player);
        HP_BAR(opponent);
        MESSAGE("The opposing Weezing was dragged out!");
        MESSAGE("The toxic spikes disappeared from the ground around the opposing side!");
        NOT STATUS_ICON(opponent, poison: TRUE);
        HP_BAR(opponent);
    }
}
