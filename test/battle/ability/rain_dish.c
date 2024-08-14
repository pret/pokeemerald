#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Rain Dish recovers 1/16th of Max HP in Rain")
{
    GIVEN {
        PLAYER(SPECIES_LUDICOLO) { Ability(ABILITY_RAIN_DISH); HP(1); MaxHP(100); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_RAIN_DANCE); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_RAIN_DISH);
        MESSAGE("Ludicolo's Rain Dish restored its HP a little!");
        HP_BAR(player, damage: -(100 / 16));
    }
}

TO_DO_BATTLE_TEST("Rain Dish doesn't recover HP if Cloud Nine/Air Lock is on the field");
