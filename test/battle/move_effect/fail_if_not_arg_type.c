#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Burn Up user loses its Fire-type")
{
    GIVEN {
        ASSUME(gMovesInfo[MOVE_BURN_UP].effect == EFFECT_FAIL_IF_NOT_ARG_TYPE);
        ASSUME(MoveHasAdditionalEffectSelfArg(MOVE_BURN_UP, MOVE_EFFECT_REMOVE_ARG_TYPE, TYPE_FIRE) == TRUE);
        ASSUME(gSpeciesInfo[SPECIES_WOBBUFFET].types[0] != TYPE_FIRE || gSpeciesInfo[SPECIES_WOBBUFFET].types[1] != TYPE_FIRE);
        ASSUME(gSpeciesInfo[SPECIES_CYNDAQUIL].types[0] == TYPE_FIRE || gSpeciesInfo[SPECIES_CYNDAQUIL].types[1] == TYPE_FIRE);
        PLAYER(SPECIES_CYNDAQUIL);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_BURN_UP); }
        TURN { MOVE(player, MOVE_BURN_UP); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BURN_UP, player);
        MESSAGE("Cyndaquil burned itself out!");
        MESSAGE("Cyndaquil used Burn Up!");
        MESSAGE("But it failed!");
    }
}

SINGLE_BATTLE_TEST("Burn Up fails if the user isn't a Fire-type")
{
    GIVEN {
        ASSUME(gMovesInfo[MOVE_BURN_UP].effect == EFFECT_FAIL_IF_NOT_ARG_TYPE);
        ASSUME(MoveHasAdditionalEffectSelfArg(MOVE_BURN_UP, MOVE_EFFECT_REMOVE_ARG_TYPE, TYPE_FIRE) == TRUE);
        ASSUME(gSpeciesInfo[SPECIES_WOBBUFFET].types[0] != TYPE_FIRE || gSpeciesInfo[SPECIES_WOBBUFFET].types[1] != TYPE_FIRE);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_BURN_UP); }
    } SCENE {
        NONE_OF { ANIMATION(ANIM_TYPE_MOVE, MOVE_BURN_UP, player); }
        MESSAGE("Wobbuffet used Burn Up!");
        MESSAGE("But it failed!");
    }
}

SINGLE_BATTLE_TEST("Burn Up user loses its Fire-type if enemy faints")
{
    GIVEN {
        ASSUME(gMovesInfo[MOVE_BURN_UP].effect == EFFECT_FAIL_IF_NOT_ARG_TYPE);
        ASSUME(MoveHasAdditionalEffectSelfArg(MOVE_BURN_UP, MOVE_EFFECT_REMOVE_ARG_TYPE, TYPE_FIRE) == TRUE);
        ASSUME(gSpeciesInfo[SPECIES_WOBBUFFET].types[0] != TYPE_FIRE || gSpeciesInfo[SPECIES_WOBBUFFET].types[1] != TYPE_FIRE);
        ASSUME(gSpeciesInfo[SPECIES_CYNDAQUIL].types[0] == TYPE_FIRE || gSpeciesInfo[SPECIES_CYNDAQUIL].types[1] == TYPE_FIRE);
        PLAYER(SPECIES_CYNDAQUIL);
        OPPONENT(SPECIES_WOBBUFFET) { HP(1); }
    } WHEN {
        TURN { MOVE(player, MOVE_BURN_UP); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BURN_UP, player);
        HP_BAR(opponent, hp: 0);
        MESSAGE("Cyndaquil burned itself out!");
    }
}

SINGLE_BATTLE_TEST("Double Shock user loses its Electric-type")
{
    GIVEN {
        ASSUME(gMovesInfo[MOVE_DOUBLE_SHOCK].effect == EFFECT_FAIL_IF_NOT_ARG_TYPE);
        ASSUME(MoveHasAdditionalEffectSelfArg(MOVE_DOUBLE_SHOCK, MOVE_EFFECT_REMOVE_ARG_TYPE, TYPE_ELECTRIC) == TRUE);
        ASSUME(gSpeciesInfo[SPECIES_WOBBUFFET].types[0] != TYPE_ELECTRIC || gSpeciesInfo[SPECIES_WOBBUFFET].types[1] != TYPE_ELECTRIC);
        ASSUME(gSpeciesInfo[SPECIES_PIKACHU].types[0] == TYPE_ELECTRIC || gSpeciesInfo[SPECIES_PIKACHU].types[1] == TYPE_ELECTRIC);
        PLAYER(SPECIES_PIKACHU);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_DOUBLE_SHOCK); }
        TURN { MOVE(player, MOVE_DOUBLE_SHOCK); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DOUBLE_SHOCK, player);
        MESSAGE("Pikachu used up all of its electricity!");
        MESSAGE("Pikachu used Double Shock!");
        MESSAGE("But it failed!");
    }
}

SINGLE_BATTLE_TEST("Double Shock fails if the user isn't an Electric-type")
{
    GIVEN {
        ASSUME(gMovesInfo[MOVE_DOUBLE_SHOCK].effect == EFFECT_FAIL_IF_NOT_ARG_TYPE);
        ASSUME(MoveHasAdditionalEffectSelfArg(MOVE_DOUBLE_SHOCK, MOVE_EFFECT_REMOVE_ARG_TYPE, TYPE_ELECTRIC) == TRUE);
        ASSUME(gSpeciesInfo[SPECIES_WOBBUFFET].types[0] != TYPE_ELECTRIC || gSpeciesInfo[SPECIES_WOBBUFFET].types[1] != TYPE_ELECTRIC);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_DOUBLE_SHOCK); }
    } SCENE {
        NONE_OF { ANIMATION(ANIM_TYPE_MOVE, MOVE_DOUBLE_SHOCK, player); }
        MESSAGE("Wobbuffet used Double Shock!");
        MESSAGE("But it failed!");
    }
}

SINGLE_BATTLE_TEST("Double Shock user loses its Electric-type if enemy faints")
{
    GIVEN {
        ASSUME(gMovesInfo[MOVE_DOUBLE_SHOCK].effect == EFFECT_FAIL_IF_NOT_ARG_TYPE);
        ASSUME(MoveHasAdditionalEffectSelfArg(MOVE_DOUBLE_SHOCK, MOVE_EFFECT_REMOVE_ARG_TYPE, TYPE_ELECTRIC) == TRUE);
        ASSUME(gSpeciesInfo[SPECIES_WOBBUFFET].types[0] != TYPE_ELECTRIC || gSpeciesInfo[SPECIES_WOBBUFFET].types[1] != TYPE_ELECTRIC);
        ASSUME(gSpeciesInfo[SPECIES_PIKACHU].types[0] == TYPE_ELECTRIC || gSpeciesInfo[SPECIES_PIKACHU].types[1] == TYPE_ELECTRIC);
        PLAYER(SPECIES_PIKACHU);
        OPPONENT(SPECIES_WOBBUFFET) { HP(1); }
    } WHEN {
        TURN { MOVE(player, MOVE_DOUBLE_SHOCK); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DOUBLE_SHOCK, player);
        HP_BAR(opponent, hp: 0);
        MESSAGE("Pikachu used up all of its electricity!");
    }
}
