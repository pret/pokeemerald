#include "global.h"
#include "test_battle.h"

#define TEST_MAX_HP (100)

SINGLE_BATTLE_TEST("Rain Dish recovers 1/16th of Max HP in Rain")
{
    GIVEN {
        PLAYER(SPECIES_LUDICOLO) { Ability(ABILITY_RAIN_DISH); HP(1); MaxHP(TEST_MAX_HP); };
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_RAIN_DANCE); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_RAIN_DISH);
        MESSAGE("Ludicolo's Rain Dish restored its HP a little!");
        HP_BAR(player, hp: TEST_MAX_HP / 16 + 1);
    }
}
