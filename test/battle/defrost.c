#include "global.h"
#include "test/battle.h"

DOUBLE_BATTLE_TEST("Defrost: A fire type spread move will thaw both targets")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Status1(STATUS1_FREEZE); }
        OPPONENT(SPECIES_WOBBUFFET) { Status1(STATUS1_FREEZE); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_HEAT_WAVE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HEAT_WAVE, playerLeft);
        STATUS_ICON(opponentLeft, freeze: FALSE);
        STATUS_ICON(opponentRight, freeze: FALSE);
    }
}

SINGLE_BATTLE_TEST("Defrost: Scald does not thaw targets if user is asleep")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Status1(STATUS1_FROSTBITE); }
        OPPONENT(SPECIES_WOBBUFFET) { Status1(STATUS1_SLEEP_TURN(3)); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SCALD); MOVE(player, MOVE_CELEBRATE); }
    } SCENE {
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_SCALD, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
        HP_BAR(player);
    }
}
