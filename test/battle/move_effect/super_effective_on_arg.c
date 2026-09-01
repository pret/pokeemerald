#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_FREEZE_DRY) == EFFECT_SUPER_EFFECTIVE_ON_ARG);
}

SINGLE_BATTLE_TEST("Freeze Dry is super effective on water types")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_SHELLDER);
    } WHEN {
        TURN { MOVE(player, MOVE_FREEZE_DRY); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FREEZE_DRY, player);
        HP_BAR(opponent);
        MESSAGE("It's super effective!");
    }
}
