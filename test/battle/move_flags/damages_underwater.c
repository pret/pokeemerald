#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Being underwater causes the target to take double damage from certain moves", s16 damage)
{
    bool32 useDive;
    PARAMETRIZE { useDive = FALSE; }
    PARAMETRIZE { useDive = TRUE; }
    GIVEN {
        ASSUME(gMovesInfo[MOVE_SURF].damagesUnderwater);
        PLAYER(SPECIES_WOBBUFFET) { Speed(1); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(2); }
    } WHEN {
        if (useDive)
            TURN { MOVE(opponent, MOVE_DIVE); MOVE(player, MOVE_SURF); }
        else
            TURN { MOVE(player, MOVE_SURF); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, UQ_4_12(2.0), results[1].damage);
    }
}
