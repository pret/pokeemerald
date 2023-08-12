#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Three-strike flag turns a move into a 3-hit move")
{
    s16 firstHit;
    s16 secondHit;
    s16 thirdHit;

    GIVEN {
        ASSUME(gBattleMoves[MOVE_TRIPLE_DIVE].flags & FLAG_THREE_STRIKES);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_TRIPLE_DIVE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TRIPLE_DIVE, player);
        HP_BAR(opponent, captureDamage: &firstHit);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TRIPLE_DIVE, player);
        HP_BAR(opponent, captureDamage: &secondHit);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TRIPLE_DIVE, player);
        HP_BAR(opponent, captureDamage: &thirdHit);
    } THEN {
        EXPECT_EQ(firstHit, secondHit);
        EXPECT_EQ(secondHit, thirdHit);
        EXPECT_EQ(firstHit, thirdHit);
    }
}

SINGLE_BATTLE_TEST("Surging Strikes hits 3 times with each hit being a critical hit")
{
    s16 firstHit;
    s16 secondHit;
    s16 thirdHit;

    GIVEN {
        ASSUME(gBattleMoves[MOVE_SURGING_STRIKES].flags & FLAG_THREE_STRIKES);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SURGING_STRIKES); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SURGING_STRIKES, player);
        HP_BAR(opponent, captureDamage: &firstHit);
        MESSAGE("A critical hit!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SURGING_STRIKES, player);
        HP_BAR(opponent, captureDamage: &secondHit);
        MESSAGE("A critical hit!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SURGING_STRIKES, player);
        HP_BAR(opponent, captureDamage: &thirdHit);
        MESSAGE("A critical hit!");
    } THEN {
        EXPECT_EQ(firstHit, secondHit);
        EXPECT_EQ(secondHit, thirdHit);
        EXPECT_EQ(firstHit, thirdHit);
    }
}
