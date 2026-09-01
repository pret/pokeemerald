#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(MoveHasAdditionalEffect(MOVE_FREEZY_FROST, MOVE_EFFECT_HAZE) == TRUE);
}

SINGLE_BATTLE_TEST("Freeze Frost restores stat changes when it was succesful")
{
    bool32 moveSuccess;
    PARAMETRIZE { moveSuccess = FALSE; }
    PARAMETRIZE { moveSuccess = TRUE; }

    GIVEN {
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {
            MOVE(opponent, MOVE_SAND_ATTACK);
            MOVE(player, MOVE_FREEZY_FROST, hit: moveSuccess);
        }
    } SCENE {
        if (moveSuccess == TRUE)
        {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_FREEZY_FROST, player);
            MESSAGE("All stat changes were eliminated!");
        } else {
            NONE_OF {
                ANIMATION(ANIM_TYPE_MOVE, MOVE_FREEZY_FROST, player);
                MESSAGE("All stat changes were eliminated!");
            }
        }
    }
}
