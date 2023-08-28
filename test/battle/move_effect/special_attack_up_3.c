#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gBattleMoves[MOVE_TAIL_GLOW].effect == EFFECT_SPECIAL_ATTACK_UP_3);
}

SINGLE_BATTLE_TEST("Tail Glow drastically raises Special Attack", s16 damage)
{
    bool32 raiseSpecialAttack;
    PARAMETRIZE { raiseSpecialAttack = FALSE; }
    PARAMETRIZE { raiseSpecialAttack = TRUE; }
    GIVEN {
        ASSUME(gBattleMoves[MOVE_GUST].split == SPLIT_SPECIAL);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        if (raiseSpecialAttack) TURN { MOVE(player, MOVE_TAIL_GLOW); }
        TURN { MOVE(player, MOVE_GUST); }
    } SCENE {
        if (raiseSpecialAttack) {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_TAIL_GLOW, player);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
            MESSAGE("Wobbuffet's Sp. Atk drastically rose!");
        }
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GUST, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(2.5), results[1].damage);
    }
}
