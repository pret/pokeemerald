#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_SMACK_DOWN) == EFFECT_SMACK_DOWN);
}

SINGLE_BATTLE_TEST("Smack Down does not ground mons behind substitutes")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_SKARMORY);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SUBSTITUTE); MOVE(player, MOVE_SMACK_DOWN); }
    } SCENE {
        NOT MESSAGE("The opposing Skarmory fell straight down!");
    }
}

SINGLE_BATTLE_TEST("Thousand Arrows does not ground mons behind substitutes")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_THOUSAND_ARROWS) == EFFECT_SMACK_DOWN);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_SKARMORY);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SUBSTITUTE); MOVE(player, MOVE_THOUSAND_ARROWS); }
    } SCENE {
        NOT MESSAGE("The opposing Skarmory fell straight down!");
    }
}

SINGLE_BATTLE_TEST("Smack Down does not ground mons through Protect")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_SKARMORY);
    } WHEN {
        TURN { MOVE(opponent, MOVE_PROTECT); MOVE(player, MOVE_SMACK_DOWN); }
    } SCENE {
        NOT MESSAGE("The opposing Skarmory fell straight down!");
    }
}

SINGLE_BATTLE_TEST("Smack Down does not ground target if target is immune")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_ELECTRIFY) == EFFECT_ELECTRIFY);
        ASSUME(GetSpeciesType(SPECIES_GLISCOR, 0) == TYPE_GROUND || GetSpeciesType(SPECIES_GLISCOR, 1) == TYPE_GROUND);
        ASSUME(GetSpeciesType(SPECIES_GLISCOR, 0) == TYPE_FLYING || GetSpeciesType(SPECIES_GLISCOR, 1) == TYPE_FLYING);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_GLISCOR);
    } WHEN {
        TURN { MOVE(opponent, MOVE_ELECTRIFY); MOVE(player, MOVE_SMACK_DOWN); }
    } SCENE {
        NOT MESSAGE("The opposing Gliscor fell straight down!");
    }
}
