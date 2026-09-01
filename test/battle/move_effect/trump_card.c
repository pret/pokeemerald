#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_TRUMP_CARD) == EFFECT_TRUMP_CARD);
}

SINGLE_BATTLE_TEST("Trump Card increases in power if its PP is low", s16 damage)
{
    // pp + 1 is assigned as the move's PP as it will be reduced before its base power is determined
    u32 pp;

    PARAMETRIZE { pp = 4; } // 40 power
    PARAMETRIZE { pp = 3; } // 50 power
    PARAMETRIZE { pp = 2; } // 60 power
    PARAMETRIZE { pp = 1; } // 80 power
    PARAMETRIZE { pp = 0; } // 200 power

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { MovesWithPP({MOVE_TRUMP_CARD, pp + 1}); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_TRUMP_CARD); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TRUMP_CARD, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, UQ_4_12(1.25), results[1].damage);
        EXPECT_MUL_EQ(results[0].damage, UQ_4_12(1.5), results[2].damage);
        EXPECT_MUL_EQ(results[0].damage, UQ_4_12(2.0), results[3].damage);
        EXPECT_MUL_EQ(results[0].damage, UQ_4_12(5.0), results[4].damage);
    }
}

SINGLE_BATTLE_TEST("Trump Card doesn't increase in power if its PP is low when called by a different move", s16 damage)
{
    u32 pp;

    PARAMETRIZE { pp = 4; } // would be 40 power
    PARAMETRIZE { pp = 0; } // would be 200 power

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_SLEEP_TALK) == EFFECT_SLEEP_TALK);
        PLAYER(SPECIES_WOBBUFFET) { MovesWithPP({MOVE_TRUMP_CARD, pp}, {MOVE_SLEEP_TALK, 10}); Status1(STATUS1_SLEEP); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SLEEP_TALK); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SLEEP_TALK, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TRUMP_CARD, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_EQ(results[0].damage, results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Trump Card increases in power if the move that called it has low PP", s16 damage)
{
    // pp + 1 is assigned as the move's PP as it will be reduced before its base power is determined
    u32 pp;

    PARAMETRIZE { pp = 4; } // 40 power
    PARAMETRIZE { pp = 0; } // 200 power

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_SLEEP_TALK) == EFFECT_SLEEP_TALK);
        PLAYER(SPECIES_WOBBUFFET) { MovesWithPP({MOVE_TRUMP_CARD, 5}, {MOVE_SLEEP_TALK, pp + 1}); Status1(STATUS1_SLEEP); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SLEEP_TALK); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SLEEP_TALK, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TRUMP_CARD, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, UQ_4_12(5.0), results[1].damage);
    }
}
