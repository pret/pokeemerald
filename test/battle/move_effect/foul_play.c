#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gMovesInfo[MOVE_FOUL_PLAY].effect == EFFECT_FOUL_PLAY);
}

SINGLE_BATTLE_TEST("Foul Play uses physical attack stat of target", s16 damage)
{
    u32 move;

    PARAMETRIZE { move = MOVE_HIGH_HORSEPOWER; }
    PARAMETRIZE { move = MOVE_FOUL_PLAY; }

    GIVEN {
        ASSUME(gMovesInfo[MOVE_HIGH_HORSEPOWER].power == gMovesInfo[MOVE_FOUL_PLAY].power);
        ASSUME(gMovesInfo[MOVE_SWORDS_DANCE].effect == EFFECT_ATTACK_UP_2);
        PLAYER(SPECIES_SHELLDER);
        OPPONENT(SPECIES_SHELLDER);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SWORDS_DANCE); MOVE(player, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(2.0), results[1].damage);
    }
}
