#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Thunder and Bleakwind/Wildbolt/Sandsear Storm bypass accuracy checks in Rain")
{
    enum Move move;
    PARAMETRIZE { move = MOVE_THUNDER; }
    PARAMETRIZE { move = MOVE_BLEAKWIND_STORM; }
    PARAMETRIZE { move = MOVE_WILDBOLT_STORM; }
    PARAMETRIZE { move = MOVE_SANDSEAR_STORM; }
    PASSES_RANDOMLY(100, 100, RNG_ACCURACY);
    GIVEN {
        ASSUME(GetMoveAccuracy(move) < 100 && GetMoveAccuracy(move) > 0);
        ASSUME(MoveAlwaysHitsInRain(move) == TRUE);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_RAIN_DANCE); MOVE(player, move); }
    } SCENE {
        NONE_OF { MESSAGE("The opposing Wobbuffet avoided the attack!"); }
    }
}
