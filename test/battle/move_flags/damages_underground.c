#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Being underground causes the target to take double damage from certain moves", s16 damage)
{
    bool32 useDig;
    PARAMETRIZE { useDig = FALSE; }
    PARAMETRIZE { useDig = TRUE; }
    GIVEN {
        ASSUME(gBattleMoves[MOVE_EARTHQUAKE].damagesUnderground);
        PLAYER(SPECIES_WOBBUFFET) { Speed(1); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(2); }
    } WHEN {
        if (useDig)
            TURN { MOVE(opponent, MOVE_DIG); MOVE(player, MOVE_EARTHQUAKE); }
        else
            TURN { MOVE(player, MOVE_EARTHQUAKE); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, UQ_4_12(2.0), results[1].damage);
    }
}
