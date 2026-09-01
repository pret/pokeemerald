#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Soundproof makes sound moves fail against the ability user")
{
    GIVEN {
        ASSUME(IsSoundMove(MOVE_BOOMBURST));
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_EXPLOUD) { Ability(ABILITY_SOUNDPROOF); }
    } WHEN {
        TURN { MOVE(player, MOVE_BOOMBURST); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_SOUNDPROOF);
        MESSAGE("It doesn't affect the opposing Exploud…");
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_BOOMBURST, player);
            HP_BAR(opponent);
        }
    }
}
