#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME_STAT_CHANGE(MOVE_HARDEN, defense: +1);
}

SINGLE_BATTLE_TEST("Harden raises Defense by 1 stage", s16 damage)
{
    bool32 raiseDefense;
    PARAMETRIZE { raiseDefense = FALSE; }
    PARAMETRIZE { raiseDefense = TRUE; }
    GIVEN {
        ASSUME(GetMoveCategory(MOVE_SCRATCH) == DAMAGE_CATEGORY_PHYSICAL);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        if (raiseDefense) TURN { MOVE(player, MOVE_HARDEN); }
        TURN { MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        if (raiseDefense) {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_HARDEN, player);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
            MESSAGE("Wobbuffet's Defense rose!");
        }
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        HP_BAR(player, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[1].damage, Q_4_12(1.5), results[0].damage);
    }
}
