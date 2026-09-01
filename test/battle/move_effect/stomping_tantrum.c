#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_STOMPING_TANTRUM) == EFFECT_STOMPING_TANTRUM);
}

SINGLE_BATTLE_TEST("Stomping Tantrum will deal double damage if user flinched on the previous turn")
{
    s16 damage[3];
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_STOMPING_TANTRUM); SWITCH(opponent, 1); }
        TURN { MOVE(opponent, MOVE_FAKE_OUT); MOVE(player, MOVE_CELEBRATE); }
        TURN { MOVE(player, MOVE_STOMPING_TANTRUM); }
        TURN { MOVE(player, MOVE_STOMPING_TANTRUM); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STOMPING_TANTRUM, player);
        HP_BAR(opponent, captureDamage: &damage[0]);

        ANIMATION(ANIM_TYPE_MOVE, MOVE_FAKE_OUT, opponent);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);

        ANIMATION(ANIM_TYPE_MOVE, MOVE_STOMPING_TANTRUM, player);
        HP_BAR(opponent, captureDamage: &damage[1]);

        ANIMATION(ANIM_TYPE_MOVE, MOVE_STOMPING_TANTRUM, player);
        HP_BAR(opponent, captureDamage: &damage[2]);
    } THEN {
        EXPECT_MUL_EQ(damage[0], Q_4_12(2.0), damage[1]);
        EXPECT_EQ(damage[0], damage[2]);
    }
}

SINGLE_BATTLE_TEST("Stomping Tantrum will deal double damage if user failed to attack due to paralysis")
{
    s16 damage[3];
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(100); Item(ITEM_POTION); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(10); Item(ITEM_LUM_BERRY); }
    } WHEN {
        TURN { MOVE(player, MOVE_STOMPING_TANTRUM); MOVE(opponent, MOVE_THUNDER_WAVE); }
        TURN { MOVE(player, MOVE_CELEBRATE, WITH_RNG(RNG_PARALYSIS, TRUE)); MOVE(opponent, MOVE_TRICK); }
        TURN { MOVE(player, MOVE_STOMPING_TANTRUM); }
        TURN { MOVE(player, MOVE_STOMPING_TANTRUM); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STOMPING_TANTRUM, player);
        HP_BAR(opponent, captureDamage: &damage[0]);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_THUNDER_WAVE, opponent);

        ANIMATION(ANIM_TYPE_MOVE, MOVE_TRICK, opponent);

        ANIMATION(ANIM_TYPE_MOVE, MOVE_STOMPING_TANTRUM, player);
        HP_BAR(opponent, captureDamage: &damage[1]);

        ANIMATION(ANIM_TYPE_MOVE, MOVE_STOMPING_TANTRUM, player);
        HP_BAR(opponent, captureDamage: &damage[2]);
    } THEN {
        EXPECT_MUL_EQ(damage[0], Q_4_12(2.0), damage[1]);
        EXPECT_EQ(damage[0], damage[2]);
    }
}

SINGLE_BATTLE_TEST("Stomping Tantrum will not deal double damage if target protects")
{
    s16 damage[2];
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_STOMPING_TANTRUM); }
        TURN { MOVE(opponent, MOVE_PROTECT); MOVE(player, MOVE_STOMPING_TANTRUM); }
        TURN { MOVE(player, MOVE_STOMPING_TANTRUM); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STOMPING_TANTRUM, player);
        HP_BAR(opponent, captureDamage: &damage[0]);

        ANIMATION(ANIM_TYPE_MOVE, MOVE_PROTECT, opponent);
        MESSAGE("The opposing Wobbuffet protected itself!");

        ANIMATION(ANIM_TYPE_MOVE, MOVE_STOMPING_TANTRUM, player);
        HP_BAR(opponent, captureDamage: &damage[1]);
    } THEN {
        EXPECT_EQ(damage[0], damage[1]);
    }
}

SINGLE_BATTLE_TEST("Stomping Tantrum will deal double damage if user failed a Protect")
{
    s16 damage[2];
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_STOMPING_TANTRUM); }
        TURN { MOVE(player, MOVE_PROTECT); }
        TURN { MOVE(player, MOVE_PROTECT, WITH_RNG(RNG_PROTECT_FAIL, USHRT_MAX)); }
        TURN { MOVE(player, MOVE_STOMPING_TANTRUM); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STOMPING_TANTRUM, player);
        HP_BAR(opponent, captureDamage: &damage[0]);

        ANIMATION(ANIM_TYPE_MOVE, MOVE_PROTECT, player);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_PROTECT, player);

        ANIMATION(ANIM_TYPE_MOVE, MOVE_STOMPING_TANTRUM, player);
        HP_BAR(opponent, captureDamage: &damage[1]);
    } THEN {
        EXPECT_MUL_EQ(damage[0], Q_4_12(2.0), damage[1]);
    }
}

SINGLE_BATTLE_TEST("Stomping Tantrum will not deal double if it missed")
{
    s16 damage[2];
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_BRIGHTPOWDER); }
    } WHEN {
        TURN { MOVE(player, MOVE_STOMPING_TANTRUM); }
        TURN { MOVE(player, MOVE_STOMPING_TANTRUM, hit: FALSE); }
        TURN { MOVE(player, MOVE_STOMPING_TANTRUM); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STOMPING_TANTRUM, player);
        HP_BAR(opponent, captureDamage: &damage[0]);
        MESSAGE("The opposing Wobbuffet avoided the attack!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STOMPING_TANTRUM, player);
        HP_BAR(opponent, captureDamage: &damage[1]);
    } THEN {
        EXPECT_MUL_EQ(damage[0], Q_4_12(2.0), damage[1]);
    }
}

SINGLE_BATTLE_TEST("Stomping Tantrum will deal double damage if user was immune to previous move")
{
    s16 damage[2];
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_PIDGEY);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_STOMPING_TANTRUM); SWITCH(opponent, 1); }
        TURN { MOVE(player, MOVE_STOMPING_TANTRUM); SWITCH(opponent, 0); }
        TURN { MOVE(player, MOVE_STOMPING_TANTRUM); SWITCH(opponent, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STOMPING_TANTRUM, player);
        HP_BAR(opponent, captureDamage: &damage[0]);
        MESSAGE("It doesn't affect the opposing Pidgey…");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STOMPING_TANTRUM, player);
        HP_BAR(opponent, captureDamage: &damage[1]);
    } THEN {
        EXPECT_MUL_EQ(damage[0], Q_4_12(2.0), damage[1]);
    }
}

DOUBLE_BATTLE_TEST("Stomping Tantrum will not deal double damage if spread moved failed one target")
{
    s16 damage[2];
    GIVEN {
        ASSUME(GetMoveTarget(MOVE_EARTHQUAKE) == TARGET_FOES_AND_ALLY);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_PIDGEY);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_STOMPING_TANTRUM, target: opponentLeft); }
        TURN { MOVE(playerLeft, MOVE_EARTHQUAKE); }
        TURN { MOVE(playerLeft, MOVE_STOMPING_TANTRUM, target: opponentLeft); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STOMPING_TANTRUM, playerLeft);
        HP_BAR(opponentLeft, captureDamage: &damage[0]);

        ANIMATION(ANIM_TYPE_MOVE, MOVE_EARTHQUAKE, playerLeft);

        ANIMATION(ANIM_TYPE_MOVE, MOVE_STOMPING_TANTRUM, playerLeft);
        HP_BAR(opponentLeft, captureDamage: &damage[1]);
    } THEN {
        EXPECT_EQ(damage[0], damage[1]);
    }
}

SINGLE_BATTLE_TEST("Stomping Tantrum will deal double damage if hit into an immunity ability")
{
    s16 damage[2];
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_ELECTRIFY) == EFFECT_ELECTRIFY);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_ELECTIVIRE) { Ability(ABILITY_MOTOR_DRIVE); }
    } WHEN {
        TURN { MOVE(player, MOVE_STOMPING_TANTRUM); }
        TURN { MOVE(opponent, MOVE_ELECTRIFY); MOVE(player, MOVE_STOMPING_TANTRUM); }
        TURN { MOVE(player, MOVE_STOMPING_TANTRUM); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STOMPING_TANTRUM, player);
        HP_BAR(opponent, captureDamage: &damage[0]);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ELECTRIFY, opponent);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_STOMPING_TANTRUM, player);
        ABILITY_POPUP(opponent, ABILITY_MOTOR_DRIVE);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STOMPING_TANTRUM, player);
        HP_BAR(opponent, captureDamage: &damage[1]);
    } THEN {
        EXPECT_MUL_EQ(damage[0], Q_4_12(2.0), damage[1]);
    }
}

