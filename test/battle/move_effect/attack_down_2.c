#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME_STAT_CHANGE(MOVE_CHARM, attack: -2);
}

SINGLE_BATTLE_TEST("Charm lowers Attack by 2 stages", s16 damage)
{
    bool32 lowerAttack;
    PARAMETRIZE { lowerAttack = FALSE; }
    PARAMETRIZE { lowerAttack = TRUE; }
    GIVEN {
        ASSUME(GetMoveCategory(MOVE_SCRATCH) == DAMAGE_CATEGORY_PHYSICAL);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        if (lowerAttack) TURN { MOVE(player, MOVE_CHARM); }
        TURN { MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        if (lowerAttack) {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_CHARM, player);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
            MESSAGE("The opposing Wobbuffet's Attack harshly fell!");
        }
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        HP_BAR(player, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[1].damage, Q_4_12(2.0), results[0].damage);
    }
}
