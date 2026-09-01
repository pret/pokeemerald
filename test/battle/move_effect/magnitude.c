#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_MAGNITUDE) == EFFECT_MAGNITUDE);
}

TO_DO_BATTLE_TEST("TODO: Write Magnitude (Move Effect) test titles")

SINGLE_BATTLE_TEST("Magnitude message is printed before failing because of Levitate")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_FLYGON) { Ability(ABILITY_LEVITATE); }
    } WHEN {
        TURN { MOVE(player, MOVE_MAGNITUDE); }
    } SCENE {
        MESSAGE("Magnitude 10!");
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_MAGNITUDE, player);
        ABILITY_POPUP(opponent, ABILITY_LEVITATE);
    }
}
