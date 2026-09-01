#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Big Pecks prevents Defense stage reduction from moves")
{
    GIVEN {
        ASSUME_STAT_CHANGE(MOVE_LEER, defense: -1);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_PIDGEY) { Ability(ABILITY_BIG_PECKS); }
    } WHEN {
        TURN { MOVE(player, MOVE_LEER); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_BIG_PECKS);
        MESSAGE("The opposing Pidgey's Defense was not lowered!");
    }
}

SINGLE_BATTLE_TEST("Big Pecks is ignored by Mold Breaker")
{
    GIVEN {
        ASSUME_STAT_CHANGE(MOVE_LEER, defense: -1);
        PLAYER(SPECIES_PINSIR) { Ability(ABILITY_MOLD_BREAKER); }
        OPPONENT(SPECIES_PIDGEY) { Ability(ABILITY_BIG_PECKS); }
    } WHEN {
        TURN { MOVE(player, MOVE_LEER); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_MOLD_BREAKER);
        MESSAGE("Pinsir breaks the mold!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_LEER, player);
        MESSAGE("The opposing Pidgey's Defense fell!");
        NONE_OF {
            ABILITY_POPUP(opponent, ABILITY_BIG_PECKS);
            MESSAGE("The opposing Pidgey's Defense was not lowered!");
        }
    }
}

SINGLE_BATTLE_TEST("Big Pecks doesn't prevent Defense stage reduction from moves used by the user")
{
    GIVEN {
        ASSUME_MOVE_EFFECT_STAT_CHANGE(MOVE_SUPERPOWER, self: TRUE, attack: -1, defense: -1);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_PIDGEY) { Ability(ABILITY_BIG_PECKS); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SUPERPOWER); }
        TURN {}
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SUPERPOWER, opponent);
        MESSAGE("The opposing Pidgey's Attack fell!");
        MESSAGE("The opposing Pidgey's Defense fell!");
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_DEF], DEFAULT_STAT_STAGE - 1);
    }
}

SINGLE_BATTLE_TEST("Big Pecks doesn't prevent Topsy-Turvy")
{
    GIVEN {
        ASSUME_STAT_CHANGE(MOVE_HARDEN, defense: +1);
        ASSUME(GetMoveEffect(MOVE_TOPSY_TURVY) == EFFECT_TOPSY_TURVY);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_PIDGEY) { Ability(ABILITY_BIG_PECKS); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_HARDEN); MOVE(player, MOVE_TOPSY_TURVY); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HARDEN, opponent);
        MESSAGE("The opposing Pidgey's Defense rose!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TOPSY_TURVY, player);
        MESSAGE("All stat changes on the opposing Pidgey were inverted!");
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_DEF], DEFAULT_STAT_STAGE - 1);
    }
}

SINGLE_BATTLE_TEST("Big Pecks doesn't prevent Spectral Thief from resetting positive Defense stage changes")
{
    GIVEN {
        ASSUME_STAT_CHANGE(MOVE_HARDEN, defense: +1);
        ASSUME(MoveHasAdditionalEffect(MOVE_SPECTRAL_THIEF, MOVE_EFFECT_STEAL_STATS));
        ASSUME(GetMoveEffect(MOVE_SOAK) == EFFECT_SOAK);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_PIDGEY) { Ability(ABILITY_BIG_PECKS); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_CELEBRATE); MOVE(player,MOVE_SOAK); }
        TURN { MOVE(opponent, MOVE_HARDEN); MOVE(player, MOVE_SPECTRAL_THIEF); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HARDEN, opponent);
        MESSAGE("The opposing Pidgey's Defense rose!");
        MESSAGE("Wobbuffet stole the target's boosted stats!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPECTRAL_THIEF, player);
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_DEF], DEFAULT_STAT_STAGE);
    }
}

SINGLE_BATTLE_TEST("Big Pecks doesn't prevent receiving negative Defense stage changes from Baton Pass")
{
    GIVEN {
        ASSUME_STAT_CHANGE(MOVE_LEER, defense: -1);
        ASSUME(GetMoveEffect(MOVE_BATON_PASS) == EFFECT_BATON_PASS);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_PIDGEY) { Ability(ABILITY_BIG_PECKS); }
    } WHEN {
        TURN { MOVE(player, MOVE_LEER);
               MOVE(opponent, MOVE_BATON_PASS);
               SEND_OUT(opponent, 1);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_LEER, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BATON_PASS, opponent);
        MESSAGE("2 sent out Pidgey!");
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_DEF], DEFAULT_STAT_STAGE - 1);
    }
}
