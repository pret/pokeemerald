#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Lucky Chant prevents critical hits on the user's side")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_LUCKY_CHANT) == EFFECT_LUCKY_CHANT);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_LUCKY_CHANT); MOVE(player, MOVE_SCRATCH, criticalHit: TRUE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        NOT MESSAGE("A critical hit!");
    }
}
