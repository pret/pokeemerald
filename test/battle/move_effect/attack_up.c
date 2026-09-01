#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME_STAT_CHANGE(MOVE_MEDITATE, attack: +1);
}

SINGLE_BATTLE_TEST("Meditate raises Attack by 1 stage", s16 damage)
{
    bool32 raiseAttack;
    PARAMETRIZE { raiseAttack = FALSE; }
    PARAMETRIZE { raiseAttack = TRUE; }
    GIVEN {
        ASSUME(GetMoveCategory(MOVE_SCRATCH) == DAMAGE_CATEGORY_PHYSICAL);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        if (raiseAttack) TURN { MOVE(player, MOVE_MEDITATE); }
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        if (raiseAttack) {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_MEDITATE, player);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
            MESSAGE("Wobbuffet's Attack rose!");
        }
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.5), results[1].damage);
    }
}
