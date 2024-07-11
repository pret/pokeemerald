#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gMovesInfo[MOVE_FLAME_BURST].additionalEffects->moveEffect == MOVE_EFFECT_FLAME_BURST);
}

//  Flame Burst AoE is supposed to hit through Substitute
DOUBLE_BATTLE_TEST("Flame Burst Substitute")
{
    GIVEN {
        ASSUME(gMovesInfo[MOVE_SUBSTITUTE].effect == EFFECT_SUBSTITUTE);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_SUBSTITUTE); MOVE(playerRight, MOVE_FLAME_BURST, target: opponentRight); }
    } SCENE {
        MESSAGE("The bursting flames hit Foe Wynaut!");
        NOT MESSAGE("The SUBSTITUTE took damage for Foe Wynaut!");
    }
}
