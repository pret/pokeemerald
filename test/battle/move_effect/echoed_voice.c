#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_ECHOED_VOICE) == EFFECT_ECHOED_VOICE);
}

SINGLE_BATTLE_TEST("Echoed Voice's power is multiplied for every consecutive turn used, capped at 5")
{
    s16 damage[6];

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_SOFT_BOILED) == EFFECT_SOFTBOILED);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_BLISSEY);
    } WHEN {
        TURN { MOVE(player, MOVE_ECHOED_VOICE); }
        TURN { MOVE(player, MOVE_ECHOED_VOICE); }
        TURN { MOVE(player, MOVE_ECHOED_VOICE); MOVE(opponent, MOVE_SOFT_BOILED); }
        TURN { MOVE(player, MOVE_ECHOED_VOICE); }
        TURN { MOVE(player, MOVE_ECHOED_VOICE); MOVE(opponent, MOVE_SOFT_BOILED); }
        TURN { MOVE(player, MOVE_ECHOED_VOICE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ECHOED_VOICE, player);
        HP_BAR(opponent, captureDamage: &damage[0]);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ECHOED_VOICE, player);
        HP_BAR(opponent, captureDamage: &damage[1]);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ECHOED_VOICE, player);
        HP_BAR(opponent, captureDamage: &damage[2]);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ECHOED_VOICE, player);
        HP_BAR(opponent, captureDamage: &damage[3]);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ECHOED_VOICE, player);
        HP_BAR(opponent, captureDamage: &damage[4]);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ECHOED_VOICE, player);
        HP_BAR(opponent, captureDamage: &damage[5]);
    } THEN {
        EXPECT_MUL_EQ(damage[0], UQ_4_12(2.0), damage[1]);
        EXPECT_MUL_EQ(damage[0], UQ_4_12(3.0), damage[2]);
        EXPECT_MUL_EQ(damage[0], UQ_4_12(4.0), damage[3]);
        EXPECT_MUL_EQ(damage[0], UQ_4_12(5.0), damage[4]);
        EXPECT_EQ(damage[4], damage[5]);
    }
}

SINGLE_BATTLE_TEST("Echoed Voice's power increases even if used by another battler")
{
    s16 damage[2];

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_ECHOED_VOICE); }
        TURN { MOVE(player, MOVE_ECHOED_VOICE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ECHOED_VOICE, opponent);
        HP_BAR(player, captureDamage: &damage[0]);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ECHOED_VOICE, player);
        HP_BAR(opponent, captureDamage: &damage[1]);
    } THEN {
        EXPECT_MUL_EQ(damage[0], UQ_4_12(2.0), damage[1]);
    }
}

SINGLE_BATTLE_TEST("Echoed Voice's power does not change until the end of the turn")
{
    s16 damage[3];

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_ECHOED_VOICE); MOVE(opponent, MOVE_ECHOED_VOICE); }
        TURN { MOVE(player, MOVE_ECHOED_VOICE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ECHOED_VOICE, player);
        HP_BAR(opponent, captureDamage: &damage[0]);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ECHOED_VOICE, opponent);
        HP_BAR(player, captureDamage: &damage[1]);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ECHOED_VOICE, player);
        HP_BAR(opponent, captureDamage: &damage[2]);
    } THEN {
        EXPECT_EQ(damage[0], damage[1]);
        EXPECT_MUL_EQ(damage[0], UQ_4_12(2.0), damage[2]);
    }
}

SINGLE_BATTLE_TEST("Echoed Voice's power increase is reset when no battler uses it successfully during a turn")
{
    s16 damage[3];

    GIVEN {
        ASSUME(MoveHasAdditionalEffect(MOVE_BITE, MOVE_EFFECT_FLINCH));
        PLAYER(SPECIES_WOBBUFFET) { Speed(5); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(10); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_ECHOED_VOICE); }
        TURN { MOVE(player, MOVE_ECHOED_VOICE); }
        TURN { MOVE(opponent, MOVE_BITE); MOVE(player, MOVE_ECHOED_VOICE); }
        TURN { MOVE(player, MOVE_ECHOED_VOICE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ECHOED_VOICE, opponent);
        HP_BAR(player, captureDamage: &damage[0]);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ECHOED_VOICE, player);
        HP_BAR(opponent, captureDamage: &damage[1]);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BITE, opponent);
        MESSAGE("Wobbuffet flinched and couldn't move!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ECHOED_VOICE, player);
        HP_BAR(opponent, captureDamage: &damage[2]);
    } THEN {
        EXPECT_EQ(damage[0], damage[2]);
        EXPECT_NE(damage[1], damage[2]);
    }
}

SINGLE_BATTLE_TEST("Echoed Voice's power is increased even if it misses")
{
    s16 damage[3];

    GIVEN {
        ASSUME_STAT_CHANGE(MOVE_SAND_ATTACK, accuracy: -1);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_ECHOED_VOICE); }
        TURN { MOVE(player, MOVE_ECHOED_VOICE); MOVE(opponent, MOVE_SAND_ATTACK); }
        TURN { MOVE(player, MOVE_ECHOED_VOICE, hit: FALSE); }
        TURN { MOVE(player, MOVE_ECHOED_VOICE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ECHOED_VOICE, player);
        HP_BAR(opponent, captureDamage: &damage[0]);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ECHOED_VOICE, player);
        HP_BAR(opponent, captureDamage: &damage[1]);
        MESSAGE("The opposing Wobbuffet avoided the attack!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ECHOED_VOICE, player);
        HP_BAR(opponent, captureDamage: &damage[2]);
    } THEN {
        EXPECT_MUL_EQ(damage[0], UQ_4_12(2.0), damage[1]);
        EXPECT_MUL_EQ(damage[0], UQ_4_12(4.0), damage[2]);
    }
}

SINGLE_BATTLE_TEST("Echoed Voice's power is increased even if it's blocked by Protect")
{
    s16 damage[3];

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_PROTECT) == EFFECT_PROTECT);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_ECHOED_VOICE); }
        TURN { MOVE(player, MOVE_ECHOED_VOICE); }
        TURN { MOVE(player, MOVE_ECHOED_VOICE); MOVE(opponent, MOVE_PROTECT); }
        TURN { MOVE(player, MOVE_ECHOED_VOICE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ECHOED_VOICE, player);
        HP_BAR(opponent, captureDamage: &damage[0]);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ECHOED_VOICE, player);
        HP_BAR(opponent, captureDamage: &damage[1]);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PROTECT, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ECHOED_VOICE, player);
        HP_BAR(opponent, captureDamage: &damage[2]);
    } THEN {
        EXPECT_MUL_EQ(damage[0], UQ_4_12(2.0), damage[1]);
        EXPECT_MUL_EQ(damage[0], UQ_4_12(4.0), damage[2]);
    }
}
