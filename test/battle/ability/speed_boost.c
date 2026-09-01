#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Speed Boost gradually boosts Speed")
{
    GIVEN {
        PLAYER(SPECIES_TORCHIC) { Ability(ABILITY_SPEED_BOOST); Speed(99); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(100); }
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_CELEBRATE); }
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
        MESSAGE("The opposing Wobbuffet used Celebrate!");
        MESSAGE("Torchic used Celebrate!");
        ABILITY_POPUP(player, ABILITY_SPEED_BOOST);
        MESSAGE("Torchic's Speed rose!");
        MESSAGE("Torchic used Celebrate!");
        MESSAGE("The opposing Wobbuffet used Celebrate!");
    }
}
