#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Destiny Bond faints the opposing mon if it fainted from the attack")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { HP(1); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_DESTINY_BOND); MOVE(opponent, MOVE_TACKLE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DESTINY_BOND, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, opponent);
        MESSAGE("Wobbuffet took Foe Wobbuffet with it!");
        MESSAGE("Foe Wobbuffet fainted!");
    }
}
