#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gMovesInfo[MOVE_SMACK_DOWN].additionalEffects->moveEffect == MOVE_EFFECT_SMACK_DOWN);
}

SINGLE_BATTLE_TEST("Smack Down does not ground mons behind substitutes")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_SKARMORY);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SUBSTITUTE); MOVE(player, MOVE_SMACK_DOWN); }
    } SCENE {
        NOT MESSAGE("Foe Skarmory fell straight down!");
    }
}
