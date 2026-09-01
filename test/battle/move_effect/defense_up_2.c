#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME_STAT_CHANGE(MOVE_IRON_DEFENSE, defense: +2);
}

SINGLE_BATTLE_TEST("Iron Defense raises Defense by 2 stages", s16 damage)
{
    bool32 raiseDefense;
    PARAMETRIZE { raiseDefense = FALSE; }
    PARAMETRIZE { raiseDefense = TRUE; }
    GIVEN {
        ASSUME(GetMoveCategory(MOVE_SCRATCH) == DAMAGE_CATEGORY_PHYSICAL);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        if (raiseDefense) TURN { MOVE(player, MOVE_IRON_DEFENSE); }
        TURN { MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        if (raiseDefense) {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_IRON_DEFENSE, player);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
            MESSAGE("Wobbuffet's Defense rose sharply!");
        }
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        HP_BAR(player, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[1].damage, Q_4_12(2.0), results[0].damage);
    }
}
