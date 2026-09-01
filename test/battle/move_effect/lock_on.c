#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_LOCK_ON) == EFFECT_LOCK_ON);
}

SINGLE_BATTLE_TEST("Lock-On volatile allows to hit through semi-invulnerability")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_LOCK_ON); MOVE(opponent, MOVE_FLY); }
        TURN { MOVE(player, MOVE_POUND); SKIP_TURN(opponent); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_LOCK_ON, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FLY, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POUND, player);
        HP_BAR(opponent); // Pound hit
    }
}

SINGLE_BATTLE_TEST("Lock-On skips the accuracy check for 2 turns (Player uses Lock-On)")
{
    PASSES_RANDOMLY(10, 10, RNG_ACCURACY);
    GIVEN {
        ASSUME(GetMoveAccuracy(MOVE_SKY_UPPERCUT) == 90);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_LOCK_ON); }
        TURN { MOVE(player, MOVE_SKY_UPPERCUT); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_LOCK_ON, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SKY_UPPERCUT, player);
    } THEN {
        u32 lockOn = gBattleMons[B_BATTLER_0].volatiles.lockOn;
        u32 battlerWithSureHit = gBattleMons[B_BATTLER_0].volatiles.battlerWithSureHit;
        EXPECT_EQ(lockOn, 0);
        EXPECT_EQ(battlerWithSureHit, 0);
    }
}

SINGLE_BATTLE_TEST("Lock-On skips the accuracy check for 2 turns (Opponent uses Lock-On)")
{
    PASSES_RANDOMLY(10, 10, RNG_ACCURACY);
    GIVEN {
        ASSUME(GetMoveAccuracy(MOVE_SKY_UPPERCUT) == 90);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_LOCK_ON); }
        TURN { MOVE(opponent, MOVE_SKY_UPPERCUT); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_LOCK_ON, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SKY_UPPERCUT, opponent);
    } THEN {
        u32 lockOn = gBattleMons[B_BATTLER_1].volatiles.lockOn;
        u32 battlerWithSureHit = gBattleMons[B_BATTLER_1].volatiles.battlerWithSureHit;
        EXPECT_EQ(lockOn, 0);
        EXPECT_EQ(battlerWithSureHit, 0);
    }
}

SINGLE_BATTLE_TEST("Lock-On: Baton Pass does not transfer Lock-On volatile")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_BATON_PASS) == EFFECT_BATON_PASS);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(player, MOVE_LOCK_ON); MOVE(opponent, MOVE_BATON_PASS); SEND_OUT(opponent, 1); }
        TURN { MOVE(player, MOVE_SKY_UPPERCUT); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_LOCK_ON, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BATON_PASS, opponent);
    } THEN {
        u32 battlerWithSureHit = gBattleMons[B_BATTLER_0].volatiles.battlerWithSureHit;
        EXPECT_EQ(battlerWithSureHit, 0);
    }
}

SINGLE_BATTLE_TEST("Lock-On: When locked on attacker faints, the volatile will be removed")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { HP(1); }
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_LOCK_ON); MOVE(opponent, MOVE_POUND); SEND_OUT(player, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_LOCK_ON, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POUND, opponent);
    } THEN {
        u32 battlerWithSureHit = gBattleMons[B_BATTLER_0].volatiles.battlerWithSureHit;
        EXPECT_EQ(battlerWithSureHit, 0);
    }
}

SINGLE_BATTLE_TEST("Lock-On: When locked on target faints, the volatile will be removed")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { HP(1); }
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(player, MOVE_LOCK_ON); }
        TURN { MOVE(player, MOVE_POUND); SEND_OUT(opponent, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_LOCK_ON, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POUND, player);
    } THEN {
        u32 battlerWithSureHit = gBattleMons[B_BATTLER_0].volatiles.battlerWithSureHit;
        EXPECT_EQ(battlerWithSureHit, 0);
    }
}

DOUBLE_BATTLE_TEST("Lock-On fails if a target has been locked on")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_LOCK_ON, target: opponentLeft); }
        TURN { MOVE(playerLeft, MOVE_LOCK_ON, target: opponentRight); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_LOCK_ON, playerLeft);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_LOCK_ON, playerLeft);
    }
}

TO_DO_BATTLE_TEST("TODO: Write Lock-On/Mind Reader (Move Effect) test titles")
