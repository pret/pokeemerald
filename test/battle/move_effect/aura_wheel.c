#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(MoveHasAdditionalEffectSelf(MOVE_AURA_WHEEL, MOVE_EFFECT_SPD_PLUS_1) == TRUE);
    ASSUME(gMovesInfo[MOVE_AURA_WHEEL].effect == EFFECT_AURA_WHEEL);
}

SINGLE_BATTLE_TEST("Aura Wheel raises Speed; fails if the user is not Morpeko")
{
    u16 species;
    PARAMETRIZE{ species = SPECIES_WOBBUFFET; }
    PARAMETRIZE{ species = SPECIES_MORPEKO; }
    GIVEN {
        PLAYER(species);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_AURA_WHEEL); }
    } SCENE {
        if (species != SPECIES_MORPEKO)
        {
            NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_AURA_WHEEL, player);
            MESSAGE("But Wobbuffet can't use the move!");
        }
        else {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_AURA_WHEEL, player);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
            MESSAGE("Morpeko's Speed rose!");
        }
    }
}

SINGLE_BATTLE_TEST("Aura Wheel changes type depending on Morpeko's form")
{
    GIVEN {
        PLAYER(SPECIES_MORPEKO) { Ability(ABILITY_HUNGER_SWITCH); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_AURA_WHEEL); }
        TURN { MOVE(player, MOVE_AURA_WHEEL); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_AURA_WHEEL, player);
        HP_BAR(opponent);
        NOT MESSAGE("It's super effective!");
        // Turn 2 (Hangry)
        ANIMATION(ANIM_TYPE_MOVE, MOVE_AURA_WHEEL, player);
        HP_BAR(opponent);
        MESSAGE("It's super effective!");
    }
}

TO_DO_BATTLE_TEST("Aura Wheel can be used by Pokémon transformed into Morpeko");
