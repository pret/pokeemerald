#include "global.h"
#include "test/battle.h"

// These tests cover all 3 effects: Stockpile, Spit up and Swallow.
ASSUMPTIONS
{
    ASSUME(gMovesInfo[MOVE_STOCKPILE].effect == EFFECT_STOCKPILE);
    ASSUME(gMovesInfo[MOVE_SWALLOW].effect == EFFECT_SWALLOW);
    ASSUME(gMovesInfo[MOVE_SPIT_UP].effect == EFFECT_SPIT_UP);
}

SINGLE_BATTLE_TEST("Stockpile's count can go up only to 3")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_STOCKPILE); }
        TURN { MOVE(player, MOVE_STOCKPILE); }
        TURN { MOVE(player, MOVE_STOCKPILE); }
        TURN { MOVE(player, MOVE_STOCKPILE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STOCKPILE, player);
        MESSAGE("Wobbuffet stockpiled 1!");

        ANIMATION(ANIM_TYPE_MOVE, MOVE_STOCKPILE, player);
        MESSAGE("Wobbuffet stockpiled 2!");

        ANIMATION(ANIM_TYPE_MOVE, MOVE_STOCKPILE, player);
        MESSAGE("Wobbuffet stockpiled 3!");

        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_STOCKPILE, player);
        MESSAGE("Wobbuffet can't stockpile any more!");
    }
}

SINGLE_BATTLE_TEST("Spit Up and Swallow don't work if used without Stockpile")
{
    u32 move;
    PARAMETRIZE { move = MOVE_SWALLOW; }
    PARAMETRIZE { move = MOVE_SPIT_UP; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { HP(10), MaxHP(400); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, move); }
        TURN { MOVE(player, MOVE_STOCKPILE); }
        TURN { MOVE(player, move); }
    } SCENE {
        NOT ANIMATION(ANIM_TYPE_MOVE, move, player);
        if (move == MOVE_SWALLOW)
            MESSAGE("But it failed to swallow a thing!");
        else
            MESSAGE("But it failed to spit up a thing!");

        ANIMATION(ANIM_TYPE_MOVE, MOVE_STOCKPILE, player);
        MESSAGE("Wobbuffet stockpiled 1!");

        ANIMATION(ANIM_TYPE_MOVE, move, player);
        if (move == MOVE_SPIT_UP) {
            HP_BAR(opponent);
        }
        else {
            HP_BAR(player);
        }
    }
}

SINGLE_BATTLE_TEST("Spit Up's power raises depending on Stockpile's count", s16 damage)
{
    u8 count;
    PARAMETRIZE { count = 1; }
    PARAMETRIZE { count = 2; }
    PARAMETRIZE { count = 3; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_STOCKPILE); }
        if (count != 1){
            TURN { MOVE(player, MOVE_STOCKPILE); }
            if (count == 3) {
                TURN { MOVE(player, MOVE_STOCKPILE); }
            }
        }
        TURN { MOVE(player, MOVE_SPIT_UP); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STOCKPILE, player);
        MESSAGE("Wobbuffet stockpiled 1!");
        if (count != 1) {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_STOCKPILE, player);
            MESSAGE("Wobbuffet stockpiled 2!");
            if (count == 3) {
                ANIMATION(ANIM_TYPE_MOVE, MOVE_STOCKPILE, player);
                MESSAGE("Wobbuffet stockpiled 3!");
            }
        }
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPIT_UP, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(2.0), results[1].damage);
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(3.0), results[2].damage);
    }
}

SINGLE_BATTLE_TEST("Swallow heals HP depending on Stockpile's count", s16 hpHeal)
{
    u8 count;
    PARAMETRIZE { count = 1; }
    PARAMETRIZE { count = 2; }
    PARAMETRIZE { count = 3; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { HP(1), MaxHP(400); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_STOCKPILE); }
        if (count != 1){
            TURN { MOVE(player, MOVE_STOCKPILE); }
            if (count == 3) {
                TURN { MOVE(player, MOVE_STOCKPILE); }
            }
        }
        TURN { MOVE(player, MOVE_SWALLOW); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STOCKPILE, player);
        MESSAGE("Wobbuffet stockpiled 1!");
        if (count != 1) {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_STOCKPILE, player);
            MESSAGE("Wobbuffet stockpiled 2!");
            if (count == 3) {
                ANIMATION(ANIM_TYPE_MOVE, MOVE_STOCKPILE, player);
                MESSAGE("Wobbuffet stockpiled 3!");
            }
        }
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SWALLOW, player);
        HP_BAR(player, captureDamage: &results[i].hpHeal);
    } FINALLY {
        EXPECT_EQ(results[0].hpHeal, -100);
        EXPECT_EQ(results[1].hpHeal, -200);
        EXPECT_EQ(results[2].hpHeal, -399); // 400 - 1.
    }
}

SINGLE_BATTLE_TEST("Stockpile temporarily raises Def and Sp. Def", s16 dmgPyhsical, s16 dmgSpecial)
{
    u16 move;
    PARAMETRIZE { move = MOVE_STOCKPILE; }
    PARAMETRIZE { move = MOVE_CELEBRATE; }
    GIVEN {
        ASSUME(B_STOCKPILE_RAISES_DEFS >= GEN_4);
        ASSUME(gMovesInfo[MOVE_TACKLE].category == DAMAGE_CATEGORY_PHYSICAL);
        ASSUME(gMovesInfo[MOVE_GUST].category == DAMAGE_CATEGORY_SPECIAL);
        PLAYER(SPECIES_WOBBUFFET) { Speed(2); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(1); }
    } WHEN {
        TURN { MOVE(player, move); MOVE(opponent, MOVE_TACKLE); }
        TURN { MOVE(opponent, MOVE_GUST); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, player);
        if (move == MOVE_STOCKPILE) {
            MESSAGE("Wobbuffet stockpiled 1!");
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
            MESSAGE("Wobbuffet's Defense rose!");
            MESSAGE("Wobbuffet's Sp. Def rose!");
        }

        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, opponent);
        HP_BAR(player, captureDamage: &results[i].dmgPyhsical);

        ANIMATION(ANIM_TYPE_MOVE, MOVE_GUST, opponent);
        HP_BAR(player, captureDamage: &results[i].dmgSpecial);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].dmgPyhsical, Q_4_12(1.5), results[1].dmgPyhsical);
        EXPECT_MUL_EQ(results[0].dmgSpecial,  Q_4_12(1.5), results[1].dmgSpecial);
    }
}

DOUBLE_BATTLE_TEST("Stockpile's Def and Sp. Def boost is lost after using Spit Up or Swallow", s16 dmgPyhsicalBefore, s16 dmgPhysicalAfter, s16 dmgSpecialBefore, s16 dmgSpecialAfter)
{
    u8 count;
    u16 move;
    PARAMETRIZE { count = 1; move = MOVE_SPIT_UP; }
    PARAMETRIZE { count = 2; move = MOVE_SWALLOW; }
    PARAMETRIZE { count = 3; move = MOVE_SPIT_UP; }
    GIVEN {
        ASSUME(B_STOCKPILE_RAISES_DEFS >= GEN_4);
        ASSUME(gMovesInfo[MOVE_TACKLE].category == DAMAGE_CATEGORY_PHYSICAL);
        ASSUME(gMovesInfo[MOVE_GUST].category == DAMAGE_CATEGORY_SPECIAL);
        PLAYER(SPECIES_WOBBUFFET) { Speed(4); HP(399); MaxHP(400); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(3); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(2); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(1); }
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_TACKLE, target: playerLeft); MOVE(opponentRight, MOVE_GUST, target: playerLeft); }
        TURN { MOVE(playerLeft, MOVE_STOCKPILE); }
        if (count != 1) {
            TURN { MOVE(playerLeft, MOVE_STOCKPILE); }
            if (count == 3) {
                 TURN { MOVE(playerLeft, MOVE_STOCKPILE); }
            }
        }
        TURN { MOVE(playerLeft, move, target: opponentLeft); MOVE(opponentLeft, MOVE_TACKLE, target: playerLeft); MOVE(opponentRight, MOVE_GUST, target: playerLeft); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, opponentLeft);
        HP_BAR(playerLeft, captureDamage: &results[i].dmgPyhsicalBefore);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GUST, opponentRight);
        HP_BAR(playerLeft, captureDamage: &results[i].dmgSpecialBefore);

        ANIMATION(ANIM_TYPE_MOVE, MOVE_STOCKPILE, playerLeft);
        if (count != 1) {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_STOCKPILE, playerLeft);
            if (count == 3) {
                ANIMATION(ANIM_TYPE_MOVE, MOVE_STOCKPILE, playerLeft);
            }
        }
        ANIMATION(ANIM_TYPE_MOVE, move, playerLeft);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerLeft);
        if (count == 1) {
            MESSAGE("Wobbuffet's Defense fell!");
        }
        else if (count == 2) {
            MESSAGE("Wobbuffet's Defense harshly fell!");
        }
        else {
            MESSAGE("Wobbuffet's Defense severely fell!");
        }

        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerLeft);
        if (count == 1) {
            MESSAGE("Wobbuffet's Sp. Def fell!");
        }
        else if (count == 2) {
            MESSAGE("Wobbuffet's Sp. Def harshly fell!");
        }
        else {
            MESSAGE("Wobbuffet's Sp. Def severely fell!");
        }
        MESSAGE("Wobbuffet's stockpiled effect wore off!");

        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, opponentLeft);
        HP_BAR(playerLeft, captureDamage: &results[i].dmgPhysicalAfter);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GUST, opponentRight);
        HP_BAR(playerLeft, captureDamage: &results[i].dmgSpecialAfter);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].dmgPyhsicalBefore, UQ_4_12(1.0), results[0].dmgPhysicalAfter);
        EXPECT_MUL_EQ(results[0].dmgSpecialBefore,  UQ_4_12(1.0), results[0].dmgSpecialAfter);
        EXPECT_MUL_EQ(results[1].dmgPyhsicalBefore, UQ_4_12(1.0), results[1].dmgPhysicalAfter);
        EXPECT_MUL_EQ(results[1].dmgSpecialBefore,  UQ_4_12(1.0), results[1].dmgSpecialAfter);
        EXPECT_MUL_EQ(results[2].dmgPyhsicalBefore, UQ_4_12(1.0), results[2].dmgPhysicalAfter);
        EXPECT_MUL_EQ(results[2].dmgSpecialBefore,  UQ_4_12(1.0), results[2].dmgSpecialAfter);
    }
}
