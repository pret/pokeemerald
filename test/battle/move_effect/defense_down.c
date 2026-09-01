#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME_STAT_CHANGE(MOVE_TAIL_WHIP, defense: -1);
}

SINGLE_BATTLE_TEST("Tail Whip lowers Defense by 1 stage", s16 damage)
{
    bool32 lowerDefense;
    PARAMETRIZE { lowerDefense = FALSE; }
    PARAMETRIZE { lowerDefense = TRUE; }
    GIVEN {
        ASSUME(GetMoveCategory(MOVE_SCRATCH) == DAMAGE_CATEGORY_PHYSICAL);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        if (lowerDefense) TURN { MOVE(player, MOVE_TAIL_WHIP); }
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        if (lowerDefense) {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_TAIL_WHIP, player);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
            MESSAGE("The opposing Wobbuffet's Defense fell!");
        }
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.5), results[1].damage);
    }
}
