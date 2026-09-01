#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME_STAT_CHANGE(MOVE_GROWL, attack: -1);
}

SINGLE_BATTLE_TEST("Growl lowers Attack by 1 stage", s16 damage)
{
    bool32 lowerAttack;
    PARAMETRIZE { lowerAttack = FALSE; }
    PARAMETRIZE { lowerAttack = TRUE; }
    GIVEN {
        ASSUME(GetMoveCategory(MOVE_SCRATCH) == DAMAGE_CATEGORY_PHYSICAL);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        if (lowerAttack) TURN { MOVE(player, MOVE_GROWL); }
        TURN { MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        if (lowerAttack) {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_GROWL, player);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
            MESSAGE("The opposing Wobbuffet's Attack fell!");
        }
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        HP_BAR(player, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[1].damage, Q_4_12(1.5), results[0].damage);
    }
}
