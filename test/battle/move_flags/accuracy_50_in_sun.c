#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveAccuracy(MOVE_THUNDER) == 70);
    ASSUME(MoveHas50AccuracyInSun(MOVE_HURRICANE) == TRUE);
}

SINGLE_BATTLE_TEST("Thunder's accuracy is lowered to 50% in Sunlight")
{
    PASSES_RANDOMLY(50, 100, RNG_ACCURACY);
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SUNNY_DAY); MOVE(opponent, MOVE_THUNDER); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_THUNDER, opponent);
    }
}
