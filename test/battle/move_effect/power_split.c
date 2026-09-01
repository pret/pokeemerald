#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_POWER_SPLIT) == EFFECT_POWER_SPLIT);
}

SINGLE_BATTLE_TEST("Power Split averages user and targets Atk and Sp. Atk stats")
{
    GIVEN {
        PLAYER(SPECIES_BULBASAUR);
        OPPONENT(SPECIES_IVYSAUR);
    } WHEN {
        TURN { MOVE(player, MOVE_POWER_SPLIT); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POWER_SPLIT, player);
    } THEN {
        EXPECT_EQ(player->attack, opponent->attack);
        EXPECT_EQ(player->spAttack, opponent->spAttack);
    }
}
