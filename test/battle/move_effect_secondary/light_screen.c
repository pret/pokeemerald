#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(MoveHasAdditionalEffectSelf(MOVE_GLITZY_GLOW, MOVE_EFFECT_LIGHT_SCREEN) == TRUE);
}

SINGLE_BATTLE_TEST("Glitzy Glow sets up Light Screen if it was successful")
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
            MOVE(player, MOVE_GLITZY_GLOW, hit: moveSuccess);
        }
    } SCENE {
        if (moveSuccess == TRUE)
        {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_GLITZY_GLOW, player);
            MESSAGE("Light Screen made your side stronger against special moves!");
        } else {
            NONE_OF {
                ANIMATION(ANIM_TYPE_MOVE, MOVE_GLITZY_GLOW, player);
                MESSAGE("Light Screen made your side stronger against special moves!");
            }
        }
    }
}
