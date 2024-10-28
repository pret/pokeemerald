#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Steam Engine raises speed when hit by a Fire or Water move")
{
    u16 move;

    PARAMETRIZE { move = MOVE_EMBER; }
    PARAMETRIZE { move = MOVE_WATER_GUN; }
    
    GIVEN {
        PLAYER(SPECIES_COALOSSAL) { Ability(ABILITY_STEAM_ENGINE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, opponent);
        ABILITY_POPUP(player, ABILITY_STEAM_ENGINE);
        MESSAGE("Coalossal's Speed drastically rose!");
    } THEN {
        EXPECT_EQ(player->statStages[STAT_SPEED], DEFAULT_STAT_STAGE + 6);
    }
}
