#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(MoveHasAdditionalEffectSelf(MOVE_UPROAR, MOVE_EFFECT_UPROAR));
}

DOUBLE_BATTLE_TEST("Uproar status causes sleeping Pokémon to wake up before they move except those with Soundproof (Gen 3-4)")
{
    GIVEN {
        WITH_CONFIG(B_UPROAR, GEN_4);
        WITH_CONFIG(B_UPROAR_IGNORE_SOUNDPROOF, GEN_4);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET) { Status1(STATUS1_SLEEP); }
        OPPONENT(SPECIES_VOLTORB) { Ability(ABILITY_SOUNDPROOF); Status1(STATUS1_SLEEP); }
        OPPONENT(SPECIES_WOBBUFFET) { Status1(STATUS1_SLEEP); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_UPROAR, target: opponentRight); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_UPROAR, playerLeft);
        HP_BAR(opponentRight);
        MESSAGE("The uproar woke Wobbuffet!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, playerRight);
        NONE_OF {
            MESSAGE("The uproar woke the opposing Voltorb!");
            ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponentLeft);
        }
        MESSAGE("The uproar woke the opposing Wobbuffet!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponentRight);
    }
}

DOUBLE_BATTLE_TEST("Uproar status causes sleeping Pokémon to wake up immediately after damage is dealt on the first turn (Gen 5+)")
{
    GIVEN {
        WITH_CONFIG(B_UPROAR, GEN_5);
        WITH_CONFIG(B_UPROAR_IGNORE_SOUNDPROOF, GEN_5);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET) { Status1(STATUS1_SLEEP); }
        OPPONENT(SPECIES_VOLTORB) { Ability(ABILITY_SOUNDPROOF); Status1(STATUS1_SLEEP); }
        OPPONENT(SPECIES_WOBBUFFET) { Status1(STATUS1_SLEEP); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_UPROAR, target: opponentRight); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_UPROAR, playerLeft);
        HP_BAR(opponentRight);
        MESSAGE("The opposing Voltorb woke up!");
        STATUS_ICON(opponentLeft, sleep: FALSE);
        MESSAGE("Wobbuffet woke up!");
        STATUS_ICON(playerRight, sleep: FALSE);
        MESSAGE("The opposing Wobbuffet woke up!");
        STATUS_ICON(opponentRight, sleep: FALSE);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, playerRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponentRight);
    }
}

DOUBLE_BATTLE_TEST("Uproar status prevents any battler from falling asleep")
{
    u32 config;

    PARAMETRIZE { config = GEN_4; }
    PARAMETRIZE { config = GEN_5; }

    GIVEN {
        WITH_CONFIG(B_UPROAR, config);
        ASSUME(GetMoveEffect(MOVE_REST) == EFFECT_REST);
        ASSUME(GetMoveEffect(MOVE_SPORE) == EFFECT_NON_VOLATILE_STATUS);
        ASSUME(GetMoveNonVolatileStatus(MOVE_SPORE) == MOVE_EFFECT_SLEEP);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_UPROAR, target: opponentRight);
               MOVE(opponentLeft, MOVE_REST);
               MOVE(opponentRight, MOVE_SPORE, target: playerLeft);
               MOVE(playerRight, MOVE_SPORE, target: opponentRight); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_UPROAR, playerLeft);
        HP_BAR(opponentRight);
        NONE_OF {
            STATUS_ICON(opponentLeft, sleep: TRUE);
            STATUS_ICON(opponentRight, sleep: TRUE);
            STATUS_ICON(playerLeft, sleep: TRUE);
        }
    }
}

SINGLE_BATTLE_TEST("Uproar doesn't wake up other pokemon on field after first turn (Gen 5+)")
{
    GIVEN {
        WITH_CONFIG(B_UPROAR, GEN_5);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET) { Status1(STATUS1_SLEEP); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_UPROAR); MOVE(player, MOVE_CELEBRATE); }
        TURN { SWITCH(player, 1); SKIP_TURN(opponent); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_UPROAR, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_UPROAR, opponent);
        NONE_OF {
            MESSAGE("Wobbuffet woke up!");
            STATUS_ICON(opponent, sleep: FALSE);
        }
    } THEN {
        EXPECT_NE(player->status1, STATUS1_NONE);
    }
}
