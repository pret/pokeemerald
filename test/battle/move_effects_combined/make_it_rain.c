#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(MoveHasAdditionalEffectWithChance(MOVE_MAKE_IT_RAIN, MOVE_EFFECT_PAYDAY, 0) == TRUE);
    ASSUME_MOVE_EFFECT_STAT_CHANGE(MOVE_MAKE_IT_RAIN, self: TRUE, spAtk: -1);
}

SINGLE_BATTLE_TEST("Make It Rain lowers special attack by one stage")
{
    s16 damage[2];

    GIVEN {
        ASSUME(GetMoveCategory(MOVE_MAKE_IT_RAIN) == DAMAGE_CATEGORY_SPECIAL);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_MAKE_IT_RAIN); }
        TURN { MOVE(player, MOVE_MAKE_IT_RAIN); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MAKE_IT_RAIN, player);
        HP_BAR(opponent, captureDamage: &damage[0]);
        MESSAGE("Coins were scattered everywhere!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        MESSAGE("Wobbuffet's Sp. Atk fell!");

        ANIMATION(ANIM_TYPE_MOVE, MOVE_MAKE_IT_RAIN, player);
        HP_BAR(opponent, captureDamage: &damage[1]);
        MESSAGE("Coins were scattered everywhere!");
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
            MESSAGE("Coins were scattered everywhere!");
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerLeft);
            MESSAGE("Wobbuffet's Sp. Atk fell!");
        }
        HP_BAR(opponentRight);
        MESSAGE("Coins were scattered everywhere!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerLeft);
        MESSAGE("Wobbuffet's Sp. Atk fell!");
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
            MESSAGE("Coins were scattered everywhere!");
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerLeft);
            MESSAGE("Wobbuffet's Sp. Atk fell!");
        }
        HP_BAR(opponentRight);
        MESSAGE("Coins were scattered everywhere!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerLeft);
        MESSAGE("Wobbuffet's Sp. Atk fell!");
    }
}

DOUBLE_BATTLE_TEST("Make It Rain lowers special attack by one stage if second target Protects")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET)
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponentRight, MOVE_PROTECT); MOVE(playerLeft, MOVE_MAKE_IT_RAIN); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PROTECT, opponentRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MAKE_IT_RAIN, playerLeft);
        NOT HP_BAR(opponentRight);
        HP_BAR(opponentLeft);
        MESSAGE("Coins were scattered everywhere!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerLeft);
        MESSAGE("Wobbuffet's Sp. Atk fell!");
    }
}
