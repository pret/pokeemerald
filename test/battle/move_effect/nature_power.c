#include "global.h"
#include "test/battle.h"
#include "battle_environment.h"

//TO_DO_BATTLE_TEST("TODO: Write Nature Power (Move Effect) test titles")

SINGLE_BATTLE_TEST("Nature power plays a move correctly in any background")
{
    u32 environment = 0;
    enum Move move = MOVE_TRI_ATTACK;

    for (u32 j = 0; j < BATTLE_ENVIRONMENT_COUNT; j++) {
        PARAMETRIZE { environment = i; }
    }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        Environment(environment);
        if (gBattleEnvironmentInfo[environment].naturePower)
            move = gBattleEnvironmentInfo[environment].naturePower;
    } WHEN {
        TURN { MOVE(player, MOVE_NATURE_POWER); }
    } SCENE {
        NOT MESSAGE("Nature Power turned into Nature Power!");
        ANIMATION(ANIM_TYPE_MOVE, move, player);
    }
}

#if B_UPDATED_MOVE_FLAGS >= GEN_6
DOUBLE_BATTLE_TEST("Nature Power can target ally (Gen6+)")
{
    GIVEN {
        PLAYER(SPECIES_WYNAUT);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_NATURE_POWER, target: playerRight); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TRI_ATTACK, playerLeft);
    }
}
#endif
