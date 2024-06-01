#include "global.h"
#include "test/battle.h"


ASSUMPTIONS
{
    ASSUME(gMovesInfo[MOVE_WORK_UP].effect == EFFECT_ATTACK_SPATK_UP);
}

SINGLE_BATTLE_TEST("Work Up raises Attack and Sp. Attack by 1 stage each", s16 damage)
{
    bool32 raiseStats;
    u32 move;
    PARAMETRIZE { raiseStats = FALSE; move = MOVE_TACKLE; }
    PARAMETRIZE { raiseStats = TRUE;  move = MOVE_TACKLE; }
    PARAMETRIZE { raiseStats = FALSE; move = MOVE_SWIFT; }
    PARAMETRIZE { raiseStats = TRUE;  move = MOVE_SWIFT; }
    GIVEN {
        ASSUME(gMovesInfo[MOVE_TACKLE].category == DAMAGE_CATEGORY_PHYSICAL);
        ASSUME(gMovesInfo[MOVE_SWIFT].category == DAMAGE_CATEGORY_SPECIAL);
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
