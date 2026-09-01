#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Hyper Cutter prevents intimidate")
{
    s16 turnOneHit;
    s16 turnTwoHit;

    GIVEN {
        PLAYER(SPECIES_EKANS) { Ability(ABILITY_SHED_SKIN); }
        PLAYER(SPECIES_EKANS) { Ability(ABILITY_INTIMIDATE); }
        OPPONENT(SPECIES_KRABBY) { Ability(ABILITY_HYPER_CUTTER); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SCRATCH); }
        TURN { SWITCH(player, 1); MOVE(opponent, MOVE_SCRATCH); }

    } SCENE {
        HP_BAR(player, captureDamage: &turnOneHit);
        ABILITY_POPUP(player, ABILITY_INTIMIDATE);
        NONE_OF { ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player); }
        ABILITY_POPUP(opponent, ABILITY_HYPER_CUTTER);
        MESSAGE("The opposing Krabby's Attack was not lowered!");
        HP_BAR(player, captureDamage: &turnTwoHit);
    } THEN {
        EXPECT_EQ(turnOneHit, turnTwoHit);
    }
}

SINGLE_BATTLE_TEST("Hyper Cutter prevents Attack stage reduction from moves")
{
    GIVEN {
        ASSUME_STAT_CHANGE(MOVE_GROWL, attack: -1);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_KRABBY) { Ability(ABILITY_HYPER_CUTTER); }
    } WHEN {
        TURN { MOVE(player, MOVE_GROWL); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_HYPER_CUTTER);
        MESSAGE("The opposing Krabby's Attack was not lowered!");
    }
}

SINGLE_BATTLE_TEST("Hyper Cutter doesn't prevent Attack reduction from burn")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_WILL_O_WISP) == EFFECT_NON_VOLATILE_STATUS);
        ASSUME(GetMoveNonVolatileStatus(MOVE_WILL_O_WISP) == MOVE_EFFECT_BURN);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_KRABBY) { Ability(ABILITY_HYPER_CUTTER); }
    } WHEN {
        TURN { MOVE(player, MOVE_WILL_O_WISP); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_WILL_O_WISP, player);
        MESSAGE("The opposing Krabby was burned!");
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_ATK], DEFAULT_STAT_STAGE);
    }
}

SINGLE_BATTLE_TEST("Hyper Cutter is ignored by Mold Breaker")
{
    GIVEN {
        ASSUME_STAT_CHANGE(MOVE_GROWL, attack: -1);
        PLAYER(SPECIES_PINSIR) { Ability(ABILITY_MOLD_BREAKER); }
        OPPONENT(SPECIES_KRABBY) { Ability(ABILITY_HYPER_CUTTER); }
    } WHEN {
        TURN { MOVE(player, MOVE_GROWL); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_MOLD_BREAKER);
        MESSAGE("Pinsir breaks the mold!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GROWL, player);
        MESSAGE("The opposing Krabby's Attack fell!");
        NONE_OF {
            ABILITY_POPUP(opponent, ABILITY_HYPER_CUTTER);
            MESSAGE("The opposing Krabby's Attack was not lowered!");
        }
    }
}

SINGLE_BATTLE_TEST("Hyper Cutter doesn't prevent Attack stage reduction from moves used by the user")
{
    GIVEN {
        ASSUME_MOVE_EFFECT_STAT_CHANGE(MOVE_SUPERPOWER, self: TRUE, attack: -1, defense: -1);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_KRABBY) { Ability(ABILITY_HYPER_CUTTER); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SUPERPOWER); }
        TURN {}
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SUPERPOWER, opponent);
        MESSAGE("The opposing Krabby's Attack fell!");
        MESSAGE("The opposing Krabby's Defense fell!");
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_ATK], DEFAULT_STAT_STAGE - 1);
    }
}

SINGLE_BATTLE_TEST("Hyper Cutter doesn't prevent Topsy-Turvy")
{
    GIVEN {
        ASSUME_STAT_CHANGE(MOVE_SWORDS_DANCE, attack: +2);
        ASSUME(GetMoveEffect(MOVE_TOPSY_TURVY) == EFFECT_TOPSY_TURVY);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_KRABBY) { Ability(ABILITY_HYPER_CUTTER); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SWORDS_DANCE); MOVE(player, MOVE_TOPSY_TURVY); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SWORDS_DANCE, opponent);
        MESSAGE("The opposing Krabby's Attack rose sharply!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TOPSY_TURVY, player);
        MESSAGE("All stat changes on the opposing Krabby were inverted!");
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_ATK], DEFAULT_STAT_STAGE - 2);
    }
}

SINGLE_BATTLE_TEST("Hyper Cutter doesn't prevent Spectral Thief from resetting positive Attack stage changes")
{
    GIVEN {
        ASSUME_STAT_CHANGE(MOVE_SWORDS_DANCE, attack: +2);
		ASSUME(MoveHasAdditionalEffect(MOVE_SPECTRAL_THIEF, MOVE_EFFECT_STEAL_STATS));
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_KRABBY) { Ability(ABILITY_HYPER_CUTTER); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SWORDS_DANCE); MOVE(player, MOVE_SPECTRAL_THIEF); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SWORDS_DANCE, opponent);
        MESSAGE("The opposing Krabby's Attack rose sharply!");
        MESSAGE("Wobbuffet stole the target's boosted stats!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPECTRAL_THIEF, player);
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_ATK], DEFAULT_STAT_STAGE);
    }
}

SINGLE_BATTLE_TEST("Hyper Cutter doesn't prevent receiving negative Attack stage changes from Baton Pass")
{
    GIVEN {
        ASSUME_STAT_CHANGE(MOVE_GROWL, attack: -1);
        ASSUME(GetMoveEffect(MOVE_BATON_PASS) == EFFECT_BATON_PASS);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_KRABBY) { Ability(ABILITY_HYPER_CUTTER); }
    } WHEN {
        TURN { MOVE(player, MOVE_GROWL);
               MOVE(opponent, MOVE_BATON_PASS);
               SEND_OUT(opponent, 1);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GROWL, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BATON_PASS, opponent);
        MESSAGE("2 sent out Krabby!");
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_ATK], DEFAULT_STAT_STAGE - 1);
    }
}
