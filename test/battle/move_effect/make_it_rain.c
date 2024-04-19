#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(MoveHasAdditionalEffect(MOVE_MAKE_IT_RAIN, MOVE_EFFECT_PAYDAY));
    ASSUME(MoveHasAdditionalEffectSelf(MOVE_MAKE_IT_RAIN, MOVE_EFFECT_SP_ATK_MINUS_1));
}

SINGLE_BATTLE_TEST("Make It Rain lowers special attack by one stage")
{
    s16 damage[2];

    GIVEN {
        ASSUME(gMovesInfo[MOVE_MAKE_IT_RAIN].category == DAMAGE_CATEGORY_SPECIAL);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_MAKE_IT_RAIN); }
        TURN { MOVE(player, MOVE_MAKE_IT_RAIN); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MAKE_IT_RAIN, player);
        HP_BAR(opponent, captureDamage: &damage[0]);
        MESSAGE("Coins scattered everywhere!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        MESSAGE("Wobbuffet's Sp. Atk fell!");

        ANIMATION(ANIM_TYPE_MOVE, MOVE_MAKE_IT_RAIN, player);
        HP_BAR(opponent, captureDamage: &damage[1]);
        MESSAGE("Coins scattered everywhere!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        MESSAGE("Wobbuffet's Sp. Atk fell!");
    } THEN {
        EXPECT_MUL_EQ(damage[0], Q_4_12(0.66), damage[1]);
    }
}

DOUBLE_BATTLE_TEST("Make It Rain lowers special attack by one stage if it hits both targets")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET)
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_MAKE_IT_RAIN); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MAKE_IT_RAIN, playerLeft);
        HP_BAR(opponentLeft);
        NONE_OF {
            MESSAGE("Coins scattered everywhere!");
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerLeft);
            MESSAGE("Wobbuffet's Sp. Atk fell!");
        }
        HP_BAR(opponentRight);
        MESSAGE("Coins scattered everywhere!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerLeft);
        MESSAGE("Wobbuffet's Sp. Atk fell!");
    }
}
