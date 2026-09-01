#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_PSYCH_UP) == EFFECT_PSYCH_UP);
}

SINGLE_BATTLE_TEST("Psych Up displays the correct battlers when used by the player")
{
    GIVEN {
        ASSUME_STAT_CHANGE(MOVE_SWORDS_DANCE, attack: +2);
        PLAYER(SPECIES_TORNADUS) { Speed(66); }
        OPPONENT(SPECIES_LANDORUS) { Speed(99); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SWORDS_DANCE); MOVE(player, MOVE_CELEBRATE); }
        TURN { MOVE(player, MOVE_PSYCH_UP); MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SWORDS_DANCE, opponent);
        MESSAGE("Tornadus copied the opposing Landorus's stat changes!");
    } THEN {
        EXPECT_EQ(player->statStages[STAT_ATK], opponent->statStages[STAT_ATK]);
        EXPECT_EQ(player->statStages[STAT_ATK], DEFAULT_STAT_STAGE + 2);
    }
}

SINGLE_BATTLE_TEST("Psych Up displays the correct battlers when used by the opponent")
{
    GIVEN {
        ASSUME_STAT_CHANGE(MOVE_SWORDS_DANCE, attack: +2);
        PLAYER(SPECIES_TORNADUS) { Speed(66); }
        OPPONENT(SPECIES_LANDORUS) { Speed(99); }
    } WHEN {
        TURN { MOVE(player, MOVE_SWORDS_DANCE); MOVE(opponent, MOVE_CELEBRATE); }
        TURN { MOVE(opponent, MOVE_PSYCH_UP); MOVE(player, MOVE_CELEBRATE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SWORDS_DANCE, player);
        MESSAGE("The opposing Landorus copied Tornadus's stat changes!");
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_ATK], player->statStages[STAT_ATK]);
        EXPECT_EQ(opponent->statStages[STAT_ATK], DEFAULT_STAT_STAGE + 2);
    }
}

SINGLE_BATTLE_TEST("Psych Up ignores Spiky Shield and Baneful Bunker but fails against Crafty Shield")
{
    enum Move protectMove = MOVE_NONE;
    bool32 shouldFail = FALSE;

    PARAMETRIZE { protectMove = MOVE_SPIKY_SHIELD; shouldFail = FALSE; }
    PARAMETRIZE { protectMove = MOVE_BANEFUL_BUNKER; shouldFail = FALSE; }
    PARAMETRIZE { protectMove = MOVE_CRAFTY_SHIELD; shouldFail = TRUE; }

    GIVEN {
        ASSUME_STAT_CHANGE(MOVE_SWORDS_DANCE, attack: +2);
        ASSUME(GetMoveEffect(MOVE_SPIKY_SHIELD) == EFFECT_PROTECT);
        ASSUME(GetMoveEffect(MOVE_BANEFUL_BUNKER) == EFFECT_PROTECT);
        ASSUME(GetMoveEffect(MOVE_CRAFTY_SHIELD) == EFFECT_PROTECT);
        PLAYER(SPECIES_TORNADUS) { Speed(66); }
        OPPONENT(SPECIES_LANDORUS) { Speed(99); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SWORDS_DANCE); MOVE(player, MOVE_CELEBRATE); }
        TURN { MOVE(opponent, protectMove); MOVE(player, MOVE_PSYCH_UP); }
    } SCENE {
        if (shouldFail) {
            NONE_OF {
                ANIMATION(ANIM_TYPE_MOVE, MOVE_PSYCH_UP, player);
                MESSAGE("Tornadus copied the opposing Landorus's stat changes!");
            }
        } else {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_PSYCH_UP, player);
            MESSAGE("Tornadus copied the opposing Landorus's stat changes!");
        }
    } THEN {
        if (shouldFail) {
            EXPECT_EQ(player->statStages[STAT_ATK], DEFAULT_STAT_STAGE);
        } else {
            EXPECT_EQ(player->statStages[STAT_ATK], opponent->statStages[STAT_ATK]);
            EXPECT_EQ(player->statStages[STAT_ATK], DEFAULT_STAT_STAGE + 2);
        }
    }
}

SINGLE_BATTLE_TEST("Psych Up does not copy the target's critical hit ratio (Gen5)")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_FOCUS_ENERGY) == EFFECT_FOCUS_ENERGY);
        WITH_CONFIG(B_PSYCH_UP_CRIT_RATIO, GEN_5);
        WITH_CONFIG(B_FOCUS_ENERGY_CRIT_RATIO, GEN_9);
        PLAYER(SPECIES_TORNADUS) { Speed(66); }
        OPPONENT(SPECIES_LANDORUS) { Speed(99); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_FOCUS_ENERGY); MOVE(player, MOVE_CELEBRATE); }
        TURN { MOVE(player, MOVE_PSYCH_UP); MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PSYCH_UP, player);
        MESSAGE("Tornadus copied the opposing Landorus's stat changes!");
    } THEN {
        EXPECT(opponent->volatiles.focusEnergy);
        EXPECT(!player->volatiles.focusEnergy);
    }
}

SINGLE_BATTLE_TEST("Psych Up copies the target's critical hit ratio (Gen6+)")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_FOCUS_ENERGY) == EFFECT_FOCUS_ENERGY);
        WITH_CONFIG(B_PSYCH_UP_CRIT_RATIO, GEN_6);
        WITH_CONFIG(B_FOCUS_ENERGY_CRIT_RATIO, GEN_9);
        PLAYER(SPECIES_TORNADUS) { Speed(66); }
        OPPONENT(SPECIES_LANDORUS) { Speed(99); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_FOCUS_ENERGY); MOVE(player, MOVE_CELEBRATE); }
        TURN { MOVE(player, MOVE_PSYCH_UP); MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PSYCH_UP, player);
        MESSAGE("Tornadus copied the opposing Landorus's stat changes!");
    } THEN {
        EXPECT(opponent->volatiles.focusEnergy);
        EXPECT(player->volatiles.focusEnergy);
    }
}
