#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gMovesInfo[MOVE_VENOSHOCK].effect == EFFECT_DOUBLE_POWER_ON_ARG_STATUS);
    ASSUME(gMovesInfo[MOVE_VENOSHOCK].argument == STATUS1_PSN_ANY);
}

SINGLE_BATTLE_TEST("Venoshock's power doubles if the target is poisoned/badly poisoned", s16 damage)
{
    u32 status1;
    PARAMETRIZE { status1 = 0; }
    PARAMETRIZE { status1 = STATUS1_POISON; }
    PARAMETRIZE { status1 = STATUS1_TOXIC_POISON; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Status1(status1); }
    } WHEN {
        TURN { MOVE(player, MOVE_VENOSHOCK); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_VENOSHOCK, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(2.0), results[1].damage);
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(2.0), results[2].damage);
    }
}
