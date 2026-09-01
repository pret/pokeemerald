#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Bulletproof makes ballistic moves fail against the ability user")
{
    GIVEN {
        ASSUME(IsBallisticMove(MOVE_ELECTRO_BALL));
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_CHESPIN) { Ability(ABILITY_BULLETPROOF); }
    } WHEN {
        TURN { MOVE(player, MOVE_ELECTRO_BALL); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_BULLETPROOF);
        MESSAGE("It doesn't affect the opposing Chespin…");
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_ELECTRO_BALL, player);
            HP_BAR(opponent);
        }
    }
}
