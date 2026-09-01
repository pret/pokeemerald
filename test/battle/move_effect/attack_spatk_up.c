#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME_STAT_CHANGE(MOVE_WORK_UP, attack: +1, spAtk: +1);
}

SINGLE_BATTLE_TEST("Work Up raises Attack and Sp. Attack by 1 stage each", s16 damage)
{
    bool32 raiseStats;
    enum Move move;
    PARAMETRIZE { raiseStats = FALSE; move = MOVE_SCRATCH; }
    PARAMETRIZE { raiseStats = TRUE;  move = MOVE_SCRATCH; }
    PARAMETRIZE { raiseStats = FALSE; move = MOVE_SWIFT; }
    PARAMETRIZE { raiseStats = TRUE;  move = MOVE_SWIFT; }
    GIVEN {
        ASSUME(GetMoveCategory(MOVE_SCRATCH) == DAMAGE_CATEGORY_PHYSICAL);
        ASSUME(GetMoveCategory(MOVE_SWIFT) == DAMAGE_CATEGORY_SPECIAL);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        if (raiseStats) TURN { MOVE(player, MOVE_WORK_UP); }
        TURN { MOVE(player, move); }
    } SCENE {
        if (raiseStats) {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_WORK_UP, player);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
            MESSAGE("Wobbuffet's Attack rose!");
            MESSAGE("Wobbuffet's Sp. Atk rose!");
        }
        ANIMATION(ANIM_TYPE_MOVE, move, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.5), results[1].damage);
        EXPECT_MUL_EQ(results[2].damage, Q_4_12(1.5), results[3].damage);
    }
}
