#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME_STAT_CHANGE(MOVE_SWORDS_DANCE, attack: +2);
}

SINGLE_BATTLE_TEST("Swords Dance raises Attack by 2 stages", s16 damage)
{
    bool32 raiseAttack;
    PARAMETRIZE { raiseAttack = FALSE; }
    PARAMETRIZE { raiseAttack = TRUE; }
    GIVEN {
        ASSUME(GetMoveCategory(MOVE_SCRATCH) == DAMAGE_CATEGORY_PHYSICAL);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        if (raiseAttack) TURN { MOVE(player, MOVE_SWORDS_DANCE); }
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        if (raiseAttack) {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_SWORDS_DANCE, player);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
            MESSAGE("Wobbuffet's Attack rose sharply!");
        }
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(2.0), results[1].damage);
    }
}
