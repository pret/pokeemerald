#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Move Animation Test: Smack Down works when used 15 times in a row")
{
    u16 j, nTurns = 15;
    FORCE_MOVE_ANIM(TRUE);

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        for (j = 0; j < nTurns; j++)
        {
            TURN { MOVE(player, MOVE_SMACK_DOWN); MOVE(opponent, MOVE_HELPING_HAND); } // Helping Hand, so there's no anim on the opponent's side.
        }
    } SCENE {
        for (j = 0; j < nTurns; j++)
        {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_SMACK_DOWN, player);
        }
    } THEN {
        FORCE_MOVE_ANIM(FALSE);
    }
}
