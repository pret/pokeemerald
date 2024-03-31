#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gMovesInfo[MOVE_BODY_PRESS].effect == EFFECT_BODY_PRESS);
}

SINGLE_BATTLE_TEST("Body Press uses physical defense stat of target", s16 damage)
{
    u32 move;

    PARAMETRIZE { move = MOVE_DRILL_PECK; }
    PARAMETRIZE { move = MOVE_BODY_PRESS; }

    GIVEN {
        ASSUME(gMovesInfo[MOVE_DRILL_PECK].power == gMovesInfo[MOVE_BODY_PRESS].power);
        ASSUME(gMovesInfo[MOVE_CHARM].effect == EFFECT_ATTACK_DOWN_2);
        PLAYER(SPECIES_MEW);
        OPPONENT(SPECIES_SHELLDER);
    } WHEN {
        TURN { MOVE(opponent, MOVE_CHARM); MOVE(player, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(2.0), results[1].damage);
    }
}
