#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Burn Up user loses its Fire-type")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_BURN_UP) == EFFECT_FAIL_IF_NOT_ARG_TYPE);
        ASSUME(IsMoveEffectRemoveSpeciesType(MOVE_BURN_UP, MOVE_EFFECT_REMOVE_ARG_TYPE, TYPE_FIRE) == TRUE);
        ASSUME(GetSpeciesType(SPECIES_WOBBUFFET, 0) != TYPE_FIRE || GetSpeciesType(SPECIES_WOBBUFFET, 1) != TYPE_FIRE);
        ASSUME(GetSpeciesType(SPECIES_CYNDAQUIL, 0) == TYPE_FIRE || GetSpeciesType(SPECIES_CYNDAQUIL, 1) == TYPE_FIRE);
        PLAYER(SPECIES_CYNDAQUIL);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_BURN_UP); }
        TURN { MOVE(opponent, MOVE_WATER_GUN); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BURN_UP, player);
        MESSAGE("Cyndaquil burned itself out!");
        NONE_OF {
            MESSAGE("It's super effective!");
        }
    }
}

SINGLE_BATTLE_TEST("Burn Up fails if the user isn't a Fire-type (Gen9)")
{
    GIVEN {
        WITH_CONFIG(B_MOVES_THAT_REMOVE_TYPE, GEN_9);
        ASSUME(GetMoveEffect(MOVE_BURN_UP) == EFFECT_FAIL_IF_NOT_ARG_TYPE);
        ASSUME(IsMoveEffectRemoveSpeciesType(MOVE_BURN_UP, MOVE_EFFECT_REMOVE_ARG_TYPE, TYPE_FIRE) == TRUE);
        ASSUME(GetSpeciesType(SPECIES_WOBBUFFET, 0) != TYPE_FIRE || GetSpeciesType(SPECIES_WOBBUFFET, 1) != TYPE_FIRE);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_BURN_UP); }
    } SCENE {
        MESSAGE("Wobbuffet used Burn Up!");
        NONE_OF { ANIMATION(ANIM_TYPE_MOVE, MOVE_BURN_UP, player); }
        MESSAGE("But it failed!");
    }
}

TO_DO_BATTLE_TEST("Burn Up doesn't thaw the user if it fails due to the user not being Fire-type")

SINGLE_BATTLE_TEST("Burn Up fails if the user has Protean/Libero and is not a Fire-type (Gen9)")
{
    GIVEN {
        WITH_CONFIG(B_MOVES_THAT_REMOVE_TYPE, GEN_9);
        WITH_CONFIG(B_PROTEAN_LIBERO, GEN_6);
        PLAYER(SPECIES_REGIROCK);
        OPPONENT(SPECIES_KECLEON) { Ability(ABILITY_PROTEAN); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_BURN_UP); }
    } SCENE {
        MESSAGE("The opposing Kecleon used Burn Up!");
        NONE_OF {
            ABILITY_POPUP(opponent, ABILITY_PROTEAN);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_BURN_UP, player);
        }
        MESSAGE("But it failed!");
    }
}

TO_DO_BATTLE_TEST("(TERA) Burn Up user does not lose their Fire type if they've Terastallized into Fire type")

SINGLE_BATTLE_TEST("Burn Up user loses its Fire-type if enemy faints")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_BURN_UP) == EFFECT_FAIL_IF_NOT_ARG_TYPE);
        ASSUME(IsMoveEffectRemoveSpeciesType(MOVE_BURN_UP, MOVE_EFFECT_REMOVE_ARG_TYPE, TYPE_FIRE) == TRUE);
        ASSUME(GetSpeciesType(SPECIES_WOBBUFFET, 0) != TYPE_FIRE || GetSpeciesType(SPECIES_WOBBUFFET, 1) != TYPE_FIRE);
        ASSUME(GetSpeciesType(SPECIES_CYNDAQUIL, 0) == TYPE_FIRE || GetSpeciesType(SPECIES_CYNDAQUIL, 1) == TYPE_FIRE);
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
        ASSUME(GetMoveEffect(MOVE_DOUBLE_SHOCK) == EFFECT_FAIL_IF_NOT_ARG_TYPE);
        ASSUME(IsMoveEffectRemoveSpeciesType(MOVE_DOUBLE_SHOCK, MOVE_EFFECT_REMOVE_ARG_TYPE, TYPE_ELECTRIC) == TRUE);
        ASSUME(GetSpeciesType(SPECIES_WOBBUFFET, 0) != TYPE_ELECTRIC || GetSpeciesType(SPECIES_WOBBUFFET, 1) != TYPE_ELECTRIC);
        ASSUME(GetSpeciesType(SPECIES_PIKACHU, 0) == TYPE_ELECTRIC || GetSpeciesType(SPECIES_PIKACHU, 1) == TYPE_ELECTRIC);
        PLAYER(SPECIES_PIKACHU);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_DOUBLE_SHOCK); }
        TURN { MOVE(opponent, MOVE_STOMPING_TANTRUM); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DOUBLE_SHOCK, player);
        MESSAGE("Pikachu used up all its electricity!");
        NONE_OF {
            MESSAGE("It's super effective!");
        }
    }
}

SINGLE_BATTLE_TEST("Double Shock fails if the user isn't an Electric-type (Gen9)")
{
    GIVEN {
        WITH_CONFIG(B_MOVES_THAT_REMOVE_TYPE, GEN_9);
        ASSUME(GetMoveEffect(MOVE_DOUBLE_SHOCK) == EFFECT_FAIL_IF_NOT_ARG_TYPE);
        ASSUME(IsMoveEffectRemoveSpeciesType(MOVE_DOUBLE_SHOCK, MOVE_EFFECT_REMOVE_ARG_TYPE, TYPE_ELECTRIC) == TRUE);
        ASSUME(GetSpeciesType(SPECIES_WOBBUFFET, 0) != TYPE_ELECTRIC || GetSpeciesType(SPECIES_WOBBUFFET, 1) != TYPE_ELECTRIC);
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
        ASSUME(GetMoveEffect(MOVE_DOUBLE_SHOCK) == EFFECT_FAIL_IF_NOT_ARG_TYPE);
        ASSUME(IsMoveEffectRemoveSpeciesType(MOVE_DOUBLE_SHOCK, MOVE_EFFECT_REMOVE_ARG_TYPE, TYPE_ELECTRIC) == TRUE);
        ASSUME(GetSpeciesType(SPECIES_WOBBUFFET, 0) != TYPE_ELECTRIC || GetSpeciesType(SPECIES_WOBBUFFET, 1) != TYPE_ELECTRIC);
        ASSUME(GetSpeciesType(SPECIES_PIKACHU, 0) == TYPE_ELECTRIC || GetSpeciesType(SPECIES_PIKACHU, 1) == TYPE_ELECTRIC);
        PLAYER(SPECIES_PIKACHU);
        OPPONENT(SPECIES_WOBBUFFET) { HP(1); }
    } WHEN {
        TURN { MOVE(player, MOVE_DOUBLE_SHOCK); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DOUBLE_SHOCK, player);
        HP_BAR(opponent, hp: 0);
        MESSAGE("Pikachu used up all its electricity!");
    }
}

SINGLE_BATTLE_TEST("Burn Up cannot be selected if the user is not Fire-type (Champions)")
{
    GIVEN {
        WITH_CONFIG(B_MOVES_THAT_REMOVE_TYPE, GEN_CHAMPIONS);
        ASSUME(GetMoveEffect(MOVE_BURN_UP) == EFFECT_FAIL_IF_NOT_ARG_TYPE);
        ASSUME(IsMoveEffectRemoveSpeciesType(MOVE_BURN_UP, MOVE_EFFECT_REMOVE_ARG_TYPE, TYPE_FIRE) == TRUE);
        ASSUME(GetSpeciesType(SPECIES_WOBBUFFET, 0) != TYPE_FIRE || GetSpeciesType(SPECIES_WOBBUFFET, 1) != TYPE_FIRE);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_BURN_UP); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_BURN_UP, allowed: FALSE); }
    } SCENE {
        NONE_OF { ANIMATION(ANIM_TYPE_MOVE, MOVE_BURN_UP, player); }
        MESSAGE("The opposing Wobbuffet used Struggle!");
    }
}

SINGLE_BATTLE_TEST("Double Shock cannot be selected if the user is not Electric-type (Champions)")
{
    GIVEN {
        WITH_CONFIG(B_MOVES_THAT_REMOVE_TYPE, GEN_CHAMPIONS);
        ASSUME(GetMoveEffect(MOVE_DOUBLE_SHOCK) == EFFECT_FAIL_IF_NOT_ARG_TYPE);
        ASSUME(IsMoveEffectRemoveSpeciesType(MOVE_DOUBLE_SHOCK, MOVE_EFFECT_REMOVE_ARG_TYPE, TYPE_ELECTRIC) == TRUE);
        ASSUME(GetSpeciesType(SPECIES_WOBBUFFET, 0) != TYPE_ELECTRIC || GetSpeciesType(SPECIES_WOBBUFFET, 1) != TYPE_ELECTRIC);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_DOUBLE_SHOCK); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_DOUBLE_SHOCK, allowed: FALSE); }
    } SCENE {
        NONE_OF { ANIMATION(ANIM_TYPE_MOVE, MOVE_DOUBLE_SHOCK, player); }
        MESSAGE("The opposing Wobbuffet used Struggle!");
    }
}
