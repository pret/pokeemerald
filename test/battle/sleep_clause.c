#include "global.h"
#include "test/battle.h"

AI_SINGLE_BATTLE_TEST("Sleep Clause: AI will not use sleep moves while sleep clause is active")
{
    GIVEN {
        FLAG_SET(B_FLAG_SLEEP_CLAUSE);
        ASSUME(GetMoveEffect(MOVE_SPORE) == EFFECT_NON_VOLATILE_STATUS);
        ASSUME(GetMoveNonVolatileStatus(MOVE_SPORE) == MOVE_EFFECT_SLEEP);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_BRELOOM) { Moves(MOVE_SPORE, MOVE_MACH_PUNCH); }
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); EXPECT_MOVE(opponent, MOVE_SPORE); }
        TURN { SWITCH(player, 1); EXPECT_MOVE(opponent, MOVE_MACH_PUNCH); }
        TURN { MOVE(player, MOVE_CELEBRATE); EXPECT_MOVE(opponent, MOVE_MACH_PUNCH); }
    }
}

AI_DOUBLE_BATTLE_TEST("Sleep Clause: AI will not use sleep moves while sleep clause is active (Doubles)")
{
    GIVEN {
        FLAG_SET(B_FLAG_SLEEP_CLAUSE);
        ASSUME(GetMoveEffect(MOVE_SPORE) == EFFECT_NON_VOLATILE_STATUS);
        ASSUME(GetMoveNonVolatileStatus(MOVE_SPORE) == MOVE_EFFECT_SLEEP);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_BRELOOM) { Moves(MOVE_SPORE, MOVE_MACH_PUNCH); }
        OPPONENT(SPECIES_BRELOOM) { Moves(MOVE_MACH_PUNCH); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_CELEBRATE); MOVE(playerRight, MOVE_CELEBRATE); EXPECT_MOVE(opponentLeft, MOVE_SPORE); EXPECT_MOVE(opponentRight, MOVE_MACH_PUNCH); }
        TURN { SWITCH(playerLeft, 2); MOVE(playerRight, MOVE_CELEBRATE); EXPECT_MOVE(opponentLeft, MOVE_MACH_PUNCH); EXPECT_MOVE(opponentRight, MOVE_MACH_PUNCH); }
        TURN { MOVE(playerLeft, MOVE_CELEBRATE); MOVE(playerRight, MOVE_CELEBRATE); EXPECT_MOVE(opponentLeft, MOVE_MACH_PUNCH); EXPECT_MOVE(opponentRight, MOVE_MACH_PUNCH); }
    }
}

AI_DOUBLE_BATTLE_TEST("Sleep Clause: AI will not use sleep move if partner is already using a sleep move")
{
    u32 chance = 0;

    PARAMETRIZE { chance = 0; }
    PARAMETRIZE { chance = 100; }

    GIVEN {
        WITH_CONFIG(AI_REVERSE_BATTLER_LOGIC_ORDER_CHANCE, chance);
        FLAG_SET(B_FLAG_SLEEP_CLAUSE);
        ASSUME(GetMoveEffect(MOVE_SPORE) == EFFECT_NON_VOLATILE_STATUS);
        ASSUME(GetMoveNonVolatileStatus(MOVE_SPORE) == MOVE_EFFECT_SLEEP);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_BRELOOM) { Moves(MOVE_SPORE, MOVE_MACH_PUNCH); }
        OPPONENT(SPECIES_BRELOOM) { Moves(MOVE_SPORE, MOVE_MACH_PUNCH); }
    } WHEN {
        TURN {
            MOVE(playerLeft, MOVE_CELEBRATE);
            MOVE(playerRight, MOVE_CELEBRATE);
            if (chance == 100) {
                EXPECT_MOVE(opponentLeft, MOVE_SPORE);
                EXPECT_MOVE(opponentRight, MOVE_MACH_PUNCH);
            } else {
                EXPECT_MOVE(opponentLeft, MOVE_MACH_PUNCH);
                EXPECT_MOVE(opponentRight, MOVE_SPORE);
            }
        }
    }
}

SINGLE_BATTLE_TEST("Sleep Clause: Sleep moves fail when sleep clause is active")
{
    GIVEN {
        FLAG_SET(B_FLAG_SLEEP_CLAUSE);
        ASSUME(GetMoveEffect(MOVE_SPORE) == EFFECT_NON_VOLATILE_STATUS);
        ASSUME(GetMoveNonVolatileStatus(MOVE_SPORE) == MOVE_EFFECT_SLEEP);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SPORE); }
        TURN { MOVE(player, MOVE_SPORE); SWITCH(opponent, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPORE, player);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_SLP, opponent);
        MESSAGE("The opposing Wobbuffet fell asleep!");
        STATUS_ICON(opponent, sleep: TRUE);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_SLP, opponent);
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_SPORE, player);
            ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_SLP, opponent);
            MESSAGE("The opposing Wobbuffet fell asleep!");
            STATUS_ICON(opponent, sleep: TRUE);
        }
        MESSAGE("Sleep Clause kept the opposing Wobbuffet awake!");
    }
}

DOUBLE_BATTLE_TEST("Sleep Clause: Sleep moves fail when sleep clause is active (Doubles)")
{
    GIVEN {
        FLAG_SET(B_FLAG_SLEEP_CLAUSE);
        ASSUME(GetMoveEffect(MOVE_SPORE) == EFFECT_NON_VOLATILE_STATUS);
        ASSUME(GetMoveNonVolatileStatus(MOVE_SPORE) == MOVE_EFFECT_SLEEP);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { HP(1); MaxHP(100); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_SPORE, target: opponentRight); MOVE(playerRight, MOVE_SPORE, target: opponentLeft); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPORE, playerLeft);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_SLP, opponentRight);
        MESSAGE("The opposing Wobbuffet fell asleep!");
        STATUS_ICON(opponentRight, sleep: TRUE);
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_SPORE, playerRight);
            ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_SLP, opponentLeft);
            MESSAGE("The opposing Wobbuffet fell asleep!");
            STATUS_ICON(opponentLeft, sleep: TRUE);
        }
        MESSAGE("Sleep Clause kept the opposing Wobbuffet awake!");
    }
}

SINGLE_BATTLE_TEST("Sleep Clause: Rest does not activate sleep clause")
{
    GIVEN {
        FLAG_SET(B_FLAG_SLEEP_CLAUSE);
        ASSUME(GetMoveEffect(MOVE_SPORE) == EFFECT_NON_VOLATILE_STATUS);
        ASSUME(GetMoveNonVolatileStatus(MOVE_SPORE) == MOVE_EFFECT_SLEEP);
        ASSUME(GetMoveEffect(MOVE_REST) == EFFECT_REST);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); MOVE(opponent, MOVE_REST); }
        TURN { MOVE(player, MOVE_SPORE); SWITCH(opponent, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPORE, player);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_SLP, opponent);
        MESSAGE("The opposing Wobbuffet fell asleep!");
        STATUS_ICON(opponent, sleep: TRUE);
    }
}

DOUBLE_BATTLE_TEST("Sleep Clause: Rest does not activate sleep clause (Doubles)")
{
    GIVEN {
        FLAG_SET(B_FLAG_SLEEP_CLAUSE);
        ASSUME(GetMoveEffect(MOVE_SPORE) == EFFECT_NON_VOLATILE_STATUS);
        ASSUME(GetMoveNonVolatileStatus(MOVE_SPORE) == MOVE_EFFECT_SLEEP);
        ASSUME(GetMoveEffect(MOVE_REST) == EFFECT_REST);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { HP(1); MaxHP(100); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_REST); MOVE(playerLeft, MOVE_SPORE, target: opponentRight); }
    } SCENE {
        STATUS_ICON(opponentLeft, sleep: TRUE);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_REST, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPORE, playerLeft);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_SLP, opponentRight);
        MESSAGE("The opposing Wobbuffet fell asleep!");
        STATUS_ICON(opponentRight, sleep: TRUE);
    }
}

SINGLE_BATTLE_TEST("Sleep Clause: Rest can still be used when sleep clause is active")
{
    GIVEN {
        FLAG_SET(B_FLAG_SLEEP_CLAUSE);
        ASSUME(GetMoveEffect(MOVE_SPORE) == EFFECT_NON_VOLATILE_STATUS);
        ASSUME(GetMoveNonVolatileStatus(MOVE_SPORE) == MOVE_EFFECT_SLEEP);
        ASSUME(GetMoveEffect(MOVE_REST) == EFFECT_REST);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SPORE); }
        TURN { MOVE(player, MOVE_SCRATCH); SWITCH(opponent, 1); }
        TURN { MOVE(opponent, MOVE_REST); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPORE, player);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_SLP, opponent);
        MESSAGE("The opposing Wobbuffet fell asleep!");
        STATUS_ICON(opponent, sleep: TRUE);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_SLP, opponent);
        STATUS_ICON(opponent, sleep: TRUE);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_REST, opponent);
    }
}

DOUBLE_BATTLE_TEST("Sleep Clause: Rest can still be used when sleep clause is active (Doubles)")
{
    GIVEN {
        FLAG_SET(B_FLAG_SLEEP_CLAUSE);
        ASSUME(GetMoveEffect(MOVE_SPORE) == EFFECT_NON_VOLATILE_STATUS);
        ASSUME(GetMoveNonVolatileStatus(MOVE_SPORE) == MOVE_EFFECT_SLEEP);
        ASSUME(GetMoveEffect(MOVE_REST) == EFFECT_REST);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { HP(1); MaxHP(100); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_SPORE, target: opponentRight); MOVE(opponentLeft, MOVE_REST); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPORE, playerLeft);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_SLP, opponentRight);
        MESSAGE("The opposing Wobbuffet fell asleep!");
        STATUS_ICON(opponentRight, sleep: TRUE);
        STATUS_ICON(opponentLeft, sleep: TRUE);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_REST, opponentLeft);
    }
}

SINGLE_BATTLE_TEST("Sleep Clause: Psycho Shift'ing sleep will fail if sleep clause is active")
{
    GIVEN {
        FLAG_SET(B_FLAG_SLEEP_CLAUSE);
        ASSUME(GetMoveEffect(MOVE_SPORE) == EFFECT_NON_VOLATILE_STATUS);
        ASSUME(GetMoveNonVolatileStatus(MOVE_SPORE) == MOVE_EFFECT_SLEEP);
        ASSUME(GetMoveEffect(MOVE_SLEEP_TALK) == EFFECT_SLEEP_TALK);
        ASSUME(GetMoveEffect(MOVE_PSYCHO_SHIFT) == EFFECT_PSYCHO_SHIFT);
        PLAYER(SPECIES_WOBBUFFET)
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_SLEEP_TALK, MOVE_PSYCHO_SHIFT); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SPORE); }
        TURN { SWITCH(player, 1); SWITCH(opponent, 1); }
        TURN { MOVE(opponent, MOVE_SPORE); MOVE(player, MOVE_SLEEP_TALK); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SLEEP_TALK, player);
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_PSYCHO_SHIFT, player);
            ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_SLP, opponent);
            STATUS_ICON(opponent, sleep: TRUE);
        }
        MESSAGE("Sleep Clause kept the opposing Wobbuffet awake!");
    }
}

SINGLE_BATTLE_TEST("Sleep Clause: Psycho Shift'ing sleep will activate sleep clause")
{
    GIVEN {
        FLAG_SET(B_FLAG_SLEEP_CLAUSE);
        ASSUME(GetMoveEffect(MOVE_SPORE) == EFFECT_NON_VOLATILE_STATUS);
        ASSUME(GetMoveNonVolatileStatus(MOVE_SPORE) == MOVE_EFFECT_SLEEP);
        ASSUME(GetMoveEffect(MOVE_SLEEP_TALK) == EFFECT_SLEEP_TALK);
        ASSUME(GetMoveEffect(MOVE_PSYCHO_SHIFT) == EFFECT_PSYCHO_SHIFT);
        PLAYER(SPECIES_ZIGZAGOON)
        PLAYER(SPECIES_ZIGZAGOON);
        OPPONENT(SPECIES_ZIGZAGOON) { Moves(MOVE_SLEEP_TALK, MOVE_PSYCHO_SHIFT); }
        OPPONENT(SPECIES_ZIGZAGOON);
    } WHEN {
        TURN { MOVE(player, MOVE_SPORE); MOVE(opponent, MOVE_SLEEP_TALK); }
        TURN { SWITCH(player, 1); SWITCH(opponent, 1); }
        TURN { MOVE(opponent, MOVE_SPORE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SLEEP_TALK, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PSYCHO_SHIFT, opponent);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_SLP, player);
        STATUS_ICON(player, sleep: TRUE);
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_SPORE, player);
            ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_SLP, opponent);
            MESSAGE("The opposing Wobbuffet fell asleep!");
            STATUS_ICON(opponent, sleep: TRUE);
        }
        MESSAGE("Sleep Clause kept Zigzagoon awake!");
    }
}

AI_SINGLE_BATTLE_TEST("Sleep Clause: AI will not use Yawn while sleep clause is active")
{
    GIVEN {
        FLAG_SET(B_FLAG_SLEEP_CLAUSE);
        ASSUME(GetMoveEffect(MOVE_YAWN) == EFFECT_YAWN);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_BRELOOM) { Moves(MOVE_YAWN, MOVE_MACH_PUNCH); }
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); EXPECT_MOVE(opponent, MOVE_YAWN); }
        TURN { MOVE(player, MOVE_CELEBRATE); EXPECT_MOVE(opponent, MOVE_MACH_PUNCH); }
        TURN { SWITCH(player, 1); EXPECT_MOVE(opponent, MOVE_MACH_PUNCH); }
        TURN { MOVE(player, MOVE_CELEBRATE); EXPECT_MOVE(opponent, MOVE_MACH_PUNCH); }
    }
}

SINGLE_BATTLE_TEST("Sleep Clause: Yawn will fail when sleep clause is active")
{
    GIVEN {
        FLAG_SET(B_FLAG_SLEEP_CLAUSE);
        ASSUME(GetMoveEffect(MOVE_YAWN) == EFFECT_YAWN);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_YAWN); }
        TURN {}
        TURN { SWITCH(player, 1); MOVE(opponent, MOVE_YAWN); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_YAWN, opponent);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_SLP, player);
        MESSAGE("Wobbuffet fell asleep!");
        STATUS_ICON(player, sleep: TRUE);
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_YAWN, opponent);
            ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_SLP, player);
            STATUS_ICON(player, sleep: TRUE);
        }
        MESSAGE("Sleep Clause kept Wobbuffet awake!");
    }
}

SINGLE_BATTLE_TEST("Sleep Clause: Effect Spore causes sleep 11% (Gen5+) of the time with sleep clause active")
{
    PASSES_RANDOMLY(11, 100, RNG_EFFECT_SPORE);
    GIVEN {
        FLAG_SET(B_FLAG_SLEEP_CLAUSE);
        WITH_CONFIG(B_ABILITY_TRIGGER_CHANCE, GEN_5);
        ASSUME(MoveMakesContact(MOVE_SCRATCH));
        ASSUME(GetMoveEffect(MOVE_SPORE) == EFFECT_NON_VOLATILE_STATUS);
        ASSUME(GetMoveNonVolatileStatus(MOVE_SPORE) == MOVE_EFFECT_SLEEP);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_BRELOOM) { Ability(ABILITY_EFFECT_SPORE); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SPORE); }
        TURN { SWITCH(player, 1); }
        TURN { MOVE(player, MOVE_SCRATCH); }
        TURN {}
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_EFFECT_SPORE);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_SLP, player);
        MESSAGE("Wobbuffet fell asleep!");
        STATUS_ICON(player, sleep: TRUE);
    }
}

DOUBLE_BATTLE_TEST("Sleep Clause: Effect Spore causes sleep 11% (Gen5+) of the time with sleep clause active (Doubles)")
{
    PASSES_RANDOMLY(11, 100, RNG_EFFECT_SPORE);
    GIVEN {
        FLAG_SET(B_FLAG_SLEEP_CLAUSE);
        WITH_CONFIG(B_ABILITY_TRIGGER_CHANCE, GEN_5);
        ASSUME(MoveMakesContact(MOVE_SCRATCH));
        ASSUME(GetMoveEffect(MOVE_SPORE) == EFFECT_NON_VOLATILE_STATUS);
        ASSUME(GetMoveNonVolatileStatus(MOVE_SPORE) == MOVE_EFFECT_SLEEP);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_BRELOOM) { Ability(ABILITY_EFFECT_SPORE); }
        OPPONENT(SPECIES_BRELOOM) { Ability(ABILITY_EFFECT_SPORE); }
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_SPORE, target:playerRight); MOVE(playerLeft, MOVE_SCRATCH, target:opponentLeft); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPORE, opponentLeft);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_SLP, playerRight);
        MESSAGE("Wobbuffet fell asleep!");
        STATUS_ICON(playerRight, sleep: TRUE);
        ABILITY_POPUP(opponentLeft, ABILITY_EFFECT_SPORE);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_SLP, playerLeft);
        MESSAGE("Wobbuffet fell asleep!");
        STATUS_ICON(playerLeft, sleep: TRUE);
    }
}


SINGLE_BATTLE_TEST("Sleep Clause: Sleep from Effect Spore will not activate sleep clause")
{
    PASSES_RANDOMLY(11, 100, RNG_EFFECT_SPORE);
    GIVEN {
        FLAG_SET(B_FLAG_SLEEP_CLAUSE);
        WITH_CONFIG(B_ABILITY_TRIGGER_CHANCE, GEN_5);
        ASSUME(MoveMakesContact(MOVE_SCRATCH));
        ASSUME(GetMoveEffect(MOVE_SPORE) == EFFECT_NON_VOLATILE_STATUS);
        ASSUME(GetMoveNonVolatileStatus(MOVE_SPORE) == MOVE_EFFECT_SLEEP);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_BRELOOM) { Ability(ABILITY_EFFECT_SPORE); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
        TURN {}
        TURN { SWITCH(player, 1); MOVE(opponent, MOVE_SPORE); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_EFFECT_SPORE);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_SLP, player);
        MESSAGE("Wobbuffet fell asleep!");
        STATUS_ICON(player, sleep: TRUE);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPORE, opponent);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_SLP, player);
        MESSAGE("Wobbuffet fell asleep!");
        STATUS_ICON(player, sleep: TRUE);
    }
}

DOUBLE_BATTLE_TEST("Sleep Clause: Sleep from Effect Spore will not activate sleep clause (Doubles)")
{
    PASSES_RANDOMLY(11, 100, RNG_EFFECT_SPORE);
    GIVEN {
        FLAG_SET(B_FLAG_SLEEP_CLAUSE);
        WITH_CONFIG(B_ABILITY_TRIGGER_CHANCE, GEN_5);
        ASSUME(MoveMakesContact(MOVE_SCRATCH));
        ASSUME(GetMoveEffect(MOVE_SPORE) == EFFECT_NON_VOLATILE_STATUS);
        ASSUME(GetMoveNonVolatileStatus(MOVE_SPORE) == MOVE_EFFECT_SLEEP);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_BRELOOM) { Ability(ABILITY_EFFECT_SPORE); }
        OPPONENT(SPECIES_BRELOOM) { Ability(ABILITY_EFFECT_SPORE); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_SCRATCH, target:opponentLeft); MOVE(opponentLeft, MOVE_SPORE, target:playerRight); }
    } SCENE {
        ABILITY_POPUP(opponentLeft, ABILITY_EFFECT_SPORE);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_SLP, playerLeft);
        MESSAGE("Wobbuffet fell asleep!");
        STATUS_ICON(playerLeft, sleep: TRUE);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPORE, opponentLeft);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_SLP, playerRight);
        MESSAGE("Wobbuffet fell asleep!");
        STATUS_ICON(playerRight, sleep: TRUE);
    }
}

SINGLE_BATTLE_TEST("Sleep Clause: Moves with sleep effect chance will activate sleep clause")
{
    PASSES_RANDOMLY(10, 100, RNG_SECONDARY_EFFECT);
    GIVEN {
        FLAG_SET(B_FLAG_SLEEP_CLAUSE);
        ASSUME(MoveHasAdditionalEffect(MOVE_RELIC_SONG, MOVE_EFFECT_SLEEP));
        ASSUME(GetMoveEffect(MOVE_SPORE) == EFFECT_NON_VOLATILE_STATUS);
        ASSUME(GetMoveNonVolatileStatus(MOVE_SPORE) == MOVE_EFFECT_SLEEP);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_RELIC_SONG); }
        TURN { MOVE(player, MOVE_SPORE); SWITCH(opponent, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_RELIC_SONG, player);
        HP_BAR(opponent);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_SLP, opponent);
        STATUS_ICON(opponent, sleep: TRUE);
        MESSAGE("Wobbuffet used Spore!");
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_SPORE, player);
            ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_SLP, opponent);
            MESSAGE("The opposing Wobbuffet fell asleep!");
            STATUS_ICON(opponent, sleep: TRUE);
        }
    }
}

SINGLE_BATTLE_TEST("Sleep Clause: Moves with sleep effect chance will still do damage when sleep clause active, but won't sleep")
{
    PASSES_RANDOMLY(100, 100, RNG_SECONDARY_EFFECT);
    GIVEN {
        FLAG_SET(B_FLAG_SLEEP_CLAUSE);
        ASSUME(MoveHasAdditionalEffect(MOVE_RELIC_SONG, MOVE_EFFECT_SLEEP));
        ASSUME(GetMoveEffect(MOVE_SPORE) == EFFECT_NON_VOLATILE_STATUS);
        ASSUME(GetMoveNonVolatileStatus(MOVE_SPORE) == MOVE_EFFECT_SLEEP);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SPORE); }
        TURN { MOVE(player, MOVE_RELIC_SONG); SWITCH(opponent, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPORE, player);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_SLP, opponent);
        STATUS_ICON(opponent, sleep: TRUE);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_RELIC_SONG, player);
        HP_BAR(opponent);
        NONE_OF {
            ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_SLP, opponent);
            MESSAGE("The opposing Wobbuffet fell asleep!");
            STATUS_ICON(opponent, sleep: TRUE);
        }
    }
}

SINGLE_BATTLE_TEST("Sleep Clause: Dire Claw cannot sleep a mon when sleep clause is active")
{
    PASSES_RANDOMLY(100, 100, RNG_SECONDARY_EFFECT);
    GIVEN {
        FLAG_SET(B_FLAG_SLEEP_CLAUSE);
        ASSUME(MoveHasAdditionalEffect(MOVE_DIRE_CLAW, MOVE_EFFECT_RANDOM_FROM_LIST));
        ASSUME(GetMoveEffect(MOVE_SPORE) == EFFECT_NON_VOLATILE_STATUS);
        ASSUME(GetMoveNonVolatileStatus(MOVE_SPORE) == MOVE_EFFECT_SLEEP);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SPORE); }
        TURN { MOVE(player, MOVE_DIRE_CLAW); SWITCH(opponent, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPORE, player);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_SLP, opponent);
        STATUS_ICON(opponent, sleep: TRUE);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DIRE_CLAW, player);
        HP_BAR(opponent);
        NONE_OF {
            ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_SLP, opponent);
            MESSAGE("The opposing Wobbuffet fell asleep!");
            STATUS_ICON(opponent, sleep: TRUE);
        }
    }
}

DOUBLE_BATTLE_TEST("Sleep Clause: Dark Void can only sleep one opposing mon if sleep clause is active")
{
    // Source: https://bulbapedia.bulbagarden.net/wiki/Dark_Void_(move)
    GIVEN {
        FLAG_SET(B_FLAG_SLEEP_CLAUSE);
        ASSUME(GetMoveEffect(MOVE_DARK_VOID) == EFFECT_DARK_VOID);
        PLAYER(SPECIES_DARKRAI);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_DARK_VOID); }
        TURN { MOVE(playerLeft, MOVE_DARK_VOID); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DARK_VOID, playerLeft);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_SLP, opponentLeft);
        MESSAGE("The opposing Wobbuffet fell asleep!");
        STATUS_ICON(opponentLeft, sleep: TRUE);
        NONE_OF {
            ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_SLP, opponentRight);
            STATUS_ICON(opponentRight, sleep: TRUE);
            MESSAGE("The opposing Wobbuffet fell asleep!");
        }
    }
}

DOUBLE_BATTLE_TEST("Sleep Clause: G-Max Befuddle can only sleep one opposing mon if sleep clause is active")
{
    GIVEN {
        FLAG_SET(B_FLAG_SLEEP_CLAUSE);
        ASSUME(MoveHasAdditionalEffect(MOVE_G_MAX_BEFUDDLE, MOVE_EFFECT_EFFECT_SPORE_SIDE));
        PLAYER(SPECIES_BUTTERFREE) { GigantamaxFactor(TRUE); }
        PLAYER(SPECIES_CATERPIE);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_BUG_BITE, target: opponentLeft, gimmick: GIMMICK_DYNAMAX,
               WITH_RNG(RNG_G_MAX_BEFUDDLE, STATUS1_SLEEP)); }
    } SCENE {
        MESSAGE("Butterfree used G-Max Befuddle!");
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_SLP, opponentLeft);
        MESSAGE("The opposing Wobbuffet fell asleep!");
        STATUS_ICON(opponentLeft, sleep: TRUE);
        NONE_OF {
            ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_SLP, opponentRight);
            STATUS_ICON(opponentRight, sleep: TRUE);
            MESSAGE("The opposing Wobbuffet fell asleep!");
        }
    }
}

SINGLE_BATTLE_TEST("Sleep Clause: Sleep clause is deactivated when a sleeping mon wakes up")
{
    GIVEN {
        FLAG_SET(B_FLAG_SLEEP_CLAUSE);
        ASSUME(GetMoveEffect(MOVE_SPORE) == EFFECT_NON_VOLATILE_STATUS);
        ASSUME(GetMoveNonVolatileStatus(MOVE_SPORE) == MOVE_EFFECT_SLEEP);
        ASSUME(B_SLEEP_TURNS >= GEN_5);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SPORE); }
        TURN {}
        TURN {}
        TURN {}
        TURN { MOVE(player, MOVE_SPORE); }
    } SCENE {
        MESSAGE("The opposing Wobbuffet woke up!");
        MESSAGE("Wobbuffet used Spore!");
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_SLP, opponent);
        MESSAGE("The opposing Wobbuffet fell asleep!");
        STATUS_ICON(opponent, sleep: TRUE);
    }
}

DOUBLE_BATTLE_TEST("Sleep Clause: Sleep clause is deactivated when a sleeping mon is woken up with Aromatherapy / Heal Bell / Sparkly Swirl")
{
    enum Move move = MOVE_NONE;
    u32 switchIndex = 0;
    struct BattlePokemon *healingSlot = opponentRight;
    struct BattlePokemon *sporedSlot = opponentLeft;
    PARAMETRIZE { move = MOVE_AROMATHERAPY;     healingSlot = opponentRight;    sporedSlot = opponentLeft;      switchIndex = 0; }
    PARAMETRIZE { move = MOVE_HEAL_BELL;        healingSlot = opponentRight;    sporedSlot = opponentLeft;      switchIndex = 0; }
    PARAMETRIZE { move = MOVE_SPARKLY_SWIRL;    healingSlot = opponentRight;    sporedSlot = opponentLeft;      switchIndex = 0; }
    PARAMETRIZE { move = MOVE_AROMATHERAPY;     healingSlot = opponentLeft;     sporedSlot = opponentRight;     switchIndex = 1; }
    PARAMETRIZE { move = MOVE_HEAL_BELL;        healingSlot = opponentLeft;     sporedSlot = opponentRight;     switchIndex = 1; }
    PARAMETRIZE { move = MOVE_SPARKLY_SWIRL;    healingSlot = opponentLeft;     sporedSlot = opponentRight;     switchIndex = 1; }
    GIVEN {
        FLAG_SET(B_FLAG_SLEEP_CLAUSE);
        ASSUME(GetMoveEffect(MOVE_SPORE) == EFFECT_NON_VOLATILE_STATUS);
        ASSUME(GetMoveNonVolatileStatus(MOVE_SPORE) == MOVE_EFFECT_SLEEP);
        ASSUME(GetMoveEffect(MOVE_AROMATHERAPY) == EFFECT_HEAL_BELL);
        ASSUME(GetMoveEffect(MOVE_HEAL_BELL) == EFFECT_HEAL_BELL);
        ASSUME(MoveHasAdditionalEffectSelf(MOVE_SPARKLY_SWIRL, MOVE_EFFECT_AROMATHERAPY));
        ASSUME(B_SLEEP_TURNS >= GEN_5);
        PLAYER(SPECIES_ZIGZAGOON);
        PLAYER(SPECIES_ZIGZAGOON);
        OPPONENT(SPECIES_ZIGZAGOON);
        OPPONENT(SPECIES_ZIGZAGOON);
        OPPONENT(SPECIES_ZIGZAGOON);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_SPORE, target:sporedSlot); }
        TURN { SWITCH(sporedSlot, 2); MOVE(playerLeft, MOVE_SPORE, target:healingSlot); }
        if (move == MOVE_SPARKLY_SWIRL)
            TURN { SWITCH(sporedSlot, switchIndex); MOVE(healingSlot, move, target: playerRight); MOVE(playerLeft, MOVE_SPORE, target:sporedSlot); }
        else
            TURN { SWITCH(sporedSlot, switchIndex); MOVE(healingSlot, move); MOVE(playerLeft, MOVE_SPORE, target:sporedSlot); }
    } SCENE {
        MESSAGE("Zigzagoon used Spore!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPORE, playerLeft);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_SLP, sporedSlot);
        MESSAGE("The opposing Zigzagoon fell asleep!");
        STATUS_ICON(sporedSlot, sleep: TRUE);
        MESSAGE("Zigzagoon used Spore!");
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_SPORE, playerLeft);
            ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_SLP, healingSlot);
            STATUS_ICON(healingSlot, sleep: TRUE);
            MESSAGE("The opposing Zigzagoon fell asleep!");
        }
        MESSAGE("Sleep Clause kept the opposing Zigzagoon awake!");
        if (move == MOVE_AROMATHERAPY)
        {
            MESSAGE("The opposing Zigzagoon used Aromatherapy!");
            ANIMATION(ANIM_TYPE_MOVE, MOVE_AROMATHERAPY, healingSlot);
        }
        else if (move == MOVE_HEAL_BELL)
        {
            MESSAGE("The opposing Zigzagoon used Heal Bell!");
            ANIMATION(ANIM_TYPE_MOVE, MOVE_HEAL_BELL, healingSlot);
        }
        else
        {
            MESSAGE("The opposing Zigzagoon used Sparkly Swirl!");
            ANIMATION(ANIM_TYPE_MOVE, MOVE_SPARKLY_SWIRL, healingSlot);
        }
        STATUS_ICON(sporedSlot, sleep: FALSE);
        MESSAGE("Zigzagoon used Spore!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPORE, playerLeft);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_SLP, sporedSlot);
        MESSAGE("The opposing Zigzagoon fell asleep!");
    }
}

DOUBLE_BATTLE_TEST("Sleep Clause: Sleep clause is deactivated when a sleeping mon is woken up forcefully by a move from an opponent")
{
    GIVEN {
        FLAG_SET(B_FLAG_SLEEP_CLAUSE);
        ASSUME(GetMoveEffect(MOVE_SPORE) == EFFECT_NON_VOLATILE_STATUS);
        ASSUME(GetMoveNonVolatileStatus(MOVE_SPORE) == MOVE_EFFECT_SLEEP);
        ASSUME(MoveHasAdditionalEffect(MOVE_WAKE_UP_SLAP, MOVE_EFFECT_REMOVE_STATUS));
        PLAYER(SPECIES_ZIGZAGOON);
        PLAYER(SPECIES_ZIGZAGOON);
        OPPONENT(SPECIES_ZIGZAGOON);
        OPPONENT(SPECIES_ZIGZAGOON);
        OPPONENT(SPECIES_ZIGZAGOON);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_SPORE, target:opponentLeft); }
        TURN { SWITCH(opponentLeft, 2); MOVE(playerLeft, MOVE_SPORE, target:opponentRight); }
        TURN { SWITCH(opponentLeft, 0); MOVE(playerLeft, MOVE_WAKE_UP_SLAP, target:opponentLeft); }
        TURN { MOVE(playerLeft, MOVE_SPORE, target:opponentLeft); }
    } SCENE {
        MESSAGE("Zigzagoon used Spore!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPORE, playerLeft);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_SLP, opponentLeft);
        MESSAGE("The opposing Zigzagoon fell asleep!");
        STATUS_ICON(opponentLeft, sleep: TRUE);
        MESSAGE("Zigzagoon used Spore!");
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_SPORE, playerLeft);
            ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_SLP, opponentRight);
            STATUS_ICON(opponentRight, sleep: TRUE);
            MESSAGE("The opposing Zigzagoon fell asleep!");
        }
        MESSAGE("Sleep Clause kept the opposing Zigzagoon awake!");
        MESSAGE("Zigzagoon used Wake-Up Slap!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_WAKE_UP_SLAP, playerLeft);
        MESSAGE("The opposing Zigzagoon woke up!");
        STATUS_ICON(opponentLeft, sleep: FALSE);
        MESSAGE("Zigzagoon used Spore!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPORE, playerLeft);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_SLP, opponentLeft);
        MESSAGE("The opposing Zigzagoon fell asleep!");
        STATUS_ICON(opponentLeft, sleep: TRUE);
    }
}

DOUBLE_BATTLE_TEST("Sleep Clause: Sleep clause is deactivated when a sleeping mon is woken up forcefully by Uproar")
{
    GIVEN {
        FLAG_SET(B_FLAG_SLEEP_CLAUSE);
        WITH_CONFIG(B_UPROAR, GEN_5);
        ASSUME(GetMoveEffect(MOVE_SPORE) == EFFECT_NON_VOLATILE_STATUS);
        ASSUME(GetMoveNonVolatileStatus(MOVE_SPORE) == MOVE_EFFECT_SLEEP);
        ASSUME(MoveHasAdditionalEffectSelf(MOVE_UPROAR, MOVE_EFFECT_UPROAR));
        PLAYER(SPECIES_ZIGZAGOON);
        PLAYER(SPECIES_ZIGZAGOON);
        PLAYER(SPECIES_ZIGZAGOON) { Moves(MOVE_CELEBRATE); }
        OPPONENT(SPECIES_ZIGZAGOON);
        OPPONENT(SPECIES_ZIGZAGOON);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_SPORE, target: opponentLeft);
               MOVE(playerRight, MOVE_UPROAR);
               MOVE(opponentRight, MOVE_ROAR, target: playerRight); }
        TURN { MOVE(playerLeft, MOVE_SPORE, target: opponentLeft); }
    } SCENE {
        MESSAGE("Zigzagoon used Spore!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPORE, playerLeft);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_SLP, opponentLeft);
        MESSAGE("The opposing Zigzagoon fell asleep!");
        STATUS_ICON(opponentLeft, sleep: TRUE);
        MESSAGE("Zigzagoon used Uproar!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_UPROAR, playerRight);
        MESSAGE("Zigzagoon caused an uproar!");
        MESSAGE("The opposing Zigzagoon woke up!");
        STATUS_ICON(opponentLeft, sleep: FALSE);
        MESSAGE("The opposing Zigzagoon used Roar!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ROAR, opponentRight);
        MESSAGE("Zigzagoon used Spore!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPORE, playerLeft);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_SLP, opponentLeft);
        MESSAGE("The opposing Zigzagoon fell asleep!");
        STATUS_ICON(opponentLeft, sleep: TRUE);
    }
}

SINGLE_BATTLE_TEST("Sleep Clause: Sleep clause is deactivated when a sleeping mon is woken up by using Sleep Talk into a status curing move")
{
    enum Move move;
    PARAMETRIZE { move = MOVE_PSYCHO_SHIFT; }
    PARAMETRIZE { move = MOVE_JUNGLE_HEALING; }
    PARAMETRIZE { move = MOVE_LUNAR_BLESSING; }
    PARAMETRIZE { move = MOVE_TAKE_HEART; }
    PARAMETRIZE { move = MOVE_AROMATHERAPY; }
    GIVEN {
        FLAG_SET(B_FLAG_SLEEP_CLAUSE);
        ASSUME(GetMoveEffect(MOVE_SPORE) == EFFECT_NON_VOLATILE_STATUS);
        ASSUME(GetMoveNonVolatileStatus(MOVE_SPORE) == MOVE_EFFECT_SLEEP);
        ASSUME(GetMoveEffect(MOVE_SLEEP_TALK) == EFFECT_SLEEP_TALK);
        ASSUME(GetMoveEffect(MOVE_PSYCHO_SHIFT) == EFFECT_PSYCHO_SHIFT);
        ASSUME(GetMoveEffect(MOVE_JUNGLE_HEALING) == EFFECT_JUNGLE_HEALING);
        ASSUME(GetMoveEffect(MOVE_LUNAR_BLESSING) == EFFECT_JUNGLE_HEALING);
        ASSUME(GetMoveEffect(MOVE_PURIFY) == EFFECT_PURIFY);
        ASSUME(GetMoveEffect(MOVE_TAKE_HEART) == EFFECT_TAKE_HEART);
        ASSUME(GetMoveEffect(MOVE_AROMATHERAPY) == EFFECT_HEAL_BELL);
        ASSUME(gItemsInfo[ITEM_CHESTO_BERRY].holdEffect == HOLD_EFFECT_CURE_SLP);
        PLAYER(SPECIES_ZIGZAGOON) { Item(ITEM_CHESTO_BERRY); }
        OPPONENT(SPECIES_ZIGZAGOON) { Moves(MOVE_SLEEP_TALK, move); }
    } WHEN {
        TURN { MOVE(player, MOVE_SPORE); MOVE(opponent, MOVE_SLEEP_TALK); }
        TURN { MOVE(player, MOVE_SPORE); MOVE(opponent, move); }
    } SCENE {
        MESSAGE("Zigzagoon used Spore!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPORE, player);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_SLP, opponent);
        MESSAGE("The opposing Zigzagoon fell asleep!");
        MESSAGE("The opposing Zigzagoon used Sleep Talk!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SLEEP_TALK, opponent);
        if (move == MOVE_PSYCHO_SHIFT)
        {
            MESSAGE("The opposing Zigzagoon used Psycho Shift!");
            ANIMATION(ANIM_TYPE_MOVE, MOVE_PSYCHO_SHIFT, opponent);
        }
        else if (move == MOVE_JUNGLE_HEALING)
        {
            MESSAGE("The opposing Zigzagoon used Jungle Healing!");
            ANIMATION(ANIM_TYPE_MOVE, MOVE_JUNGLE_HEALING, opponent);
        }
        else if (move == MOVE_LUNAR_BLESSING)
        {
            MESSAGE("The opposing Zigzagoon used Lunar Blessing!");
            ANIMATION(ANIM_TYPE_MOVE, MOVE_LUNAR_BLESSING, opponent);
        }
        else if (move == MOVE_TAKE_HEART)
        {
            MESSAGE("The opposing Zigzagoon used Take Heart!");
            ANIMATION(ANIM_TYPE_MOVE, MOVE_TAKE_HEART, opponent);
        }
        else if (move == MOVE_AROMATHERAPY)
        {
            MESSAGE("The opposing Zigzagoon used Aromatherapy!");
            ANIMATION(ANIM_TYPE_MOVE, MOVE_AROMATHERAPY, opponent);
        }
        MESSAGE("Zigzagoon used Spore!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPORE, player);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_SLP, opponent);
    }
}

SINGLE_BATTLE_TEST("Sleep Clause: Sleep clause is deactivated when a sleeping mon is woken up by Hydration in the rain")
{
    GIVEN {
        FLAG_SET(B_FLAG_SLEEP_CLAUSE);
        ASSUME(GetMoveEffect(MOVE_SPORE) == EFFECT_NON_VOLATILE_STATUS);
        ASSUME(GetMoveNonVolatileStatus(MOVE_SPORE) == MOVE_EFFECT_SLEEP);
        PLAYER(SPECIES_PELIPPER) { Ability(ABILITY_DRIZZLE); }
        OPPONENT(SPECIES_LUVDISC) { Ability(ABILITY_HYDRATION); }
    } WHEN {
        TURN { MOVE(player, MOVE_SPORE); }
        TURN { MOVE(player, MOVE_SPORE); }
    } SCENE {
        MESSAGE("Pelipper used Spore!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPORE, player);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_SLP, opponent);
        MESSAGE("The opposing Luvdisc fell asleep!");
        MESSAGE("The opposing Luvdisc woke up!");
        STATUS_ICON(opponent, sleep: FALSE);
        MESSAGE("Pelipper used Spore!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPORE, player);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_SLP, opponent);
        MESSAGE("The opposing Luvdisc fell asleep!");
    }
}

SINGLE_BATTLE_TEST("Sleep Clause: Sleep clause is deactivated when a sleeping mon is woken up by Natural Cure")
{
    GIVEN {
        FLAG_SET(B_FLAG_SLEEP_CLAUSE);
        ASSUME(GetMoveEffect(MOVE_SPORE) == EFFECT_NON_VOLATILE_STATUS);
        ASSUME(GetMoveNonVolatileStatus(MOVE_SPORE) == MOVE_EFFECT_SLEEP);
        PLAYER(SPECIES_ZIGZAGOON);
        OPPONENT(SPECIES_SWABLU) { Ability(ABILITY_NATURAL_CURE); }
        OPPONENT(SPECIES_ZIGZAGOON);
    } WHEN {
        TURN { MOVE(player, MOVE_SPORE); }
        TURN { SWITCH(opponent, 1); }
        TURN { SWITCH(opponent, 0); MOVE(player, MOVE_SPORE); }
    } SCENE {
        MESSAGE("Zigzagoon used Spore!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPORE, player);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_SLP, opponent);
        MESSAGE("The opposing Swablu fell asleep!");
        MESSAGE("2 withdrew Swablu!");
        MESSAGE("2 sent out Swablu!");
        MESSAGE("Zigzagoon used Spore!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPORE, player);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_SLP, opponent);
        MESSAGE("The opposing Swablu fell asleep!");
    }
}

SINGLE_BATTLE_TEST("Sleep Clause: Sleep clause is deactivated when a sleeping mon is woken up by Shed Skin")
{
    u32 config, passes;
    PARAMETRIZE { config = GEN_3; passes = 33; }
    PARAMETRIZE { config = GEN_4; passes = 30; }
    PARAMETRIZE { config = GEN_5; passes = 33; }

    PASSES_RANDOMLY(passes, 100, RNG_SHED_SKIN);
    GIVEN {
        WITH_CONFIG(B_ABILITY_TRIGGER_CHANCE, config);
        FLAG_SET(B_FLAG_SLEEP_CLAUSE);
        ASSUME(GetMoveEffect(MOVE_SPORE) == EFFECT_NON_VOLATILE_STATUS);
        ASSUME(GetMoveNonVolatileStatus(MOVE_SPORE) == MOVE_EFFECT_SLEEP);
        PLAYER(SPECIES_ZIGZAGOON);
        OPPONENT(SPECIES_DRATINI) { Ability(ABILITY_SHED_SKIN); }
    } WHEN {
        TURN { MOVE(player, MOVE_SPORE); }
        TURN { MOVE(player, MOVE_SPORE); }
    } SCENE {
        MESSAGE("Zigzagoon used Spore!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPORE, player);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_SLP, opponent);
        MESSAGE("The opposing Dratini fell asleep!");
        MESSAGE("The opposing Dratini woke up!");
        MESSAGE("Zigzagoon used Spore!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPORE, player);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_SLP, opponent);
        MESSAGE("The opposing Dratini fell asleep!");
    }
}

DOUBLE_BATTLE_TEST("Sleep Clause: Sleep clause is deactivated when a sleeping mon is woken up by Healer")
{
    PASSES_RANDOMLY(30, 100, RNG_HEALER);
    GIVEN {
        FLAG_SET(B_FLAG_SLEEP_CLAUSE);
        ASSUME(GetMoveEffect(MOVE_SPORE) == EFFECT_NON_VOLATILE_STATUS);
        ASSUME(GetMoveNonVolatileStatus(MOVE_SPORE) == MOVE_EFFECT_SLEEP);
        PLAYER(SPECIES_ZIGZAGOON);
        PLAYER(SPECIES_ZIGZAGOON);
        OPPONENT(SPECIES_ZIGZAGOON);
        OPPONENT(SPECIES_CHANSEY) { Ability(ABILITY_HEALER); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_SPORE, target:opponentLeft); }
        TURN { MOVE(playerLeft, MOVE_SPORE, target:opponentLeft); }
    } SCENE {
        MESSAGE("Zigzagoon used Spore!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPORE, playerLeft);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_SLP, opponentLeft);
        MESSAGE("The opposing Zigzagoon fell asleep!");
        MESSAGE("The opposing Zigzagoon woke up!");
        MESSAGE("Zigzagoon used Spore!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPORE, playerLeft);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_SLP, opponentLeft);
        MESSAGE("The opposing Zigzagoon fell asleep!");
    }
}

SINGLE_BATTLE_TEST("Sleep Clause: Sleep clause is deactivated when a sleeping mon is woken up by using a held item")
{
    enum Item heldItem = ITEM_NONE;
    PARAMETRIZE { heldItem = ITEM_CHESTO_BERRY; }
    PARAMETRIZE { heldItem = ITEM_LUM_BERRY; }
    GIVEN {
        FLAG_SET(B_FLAG_SLEEP_CLAUSE);
        ASSUME(GetMoveEffect(MOVE_SPORE) == EFFECT_NON_VOLATILE_STATUS);
        ASSUME(GetMoveNonVolatileStatus(MOVE_SPORE) == MOVE_EFFECT_SLEEP);
        ASSUME(gItemsInfo[ITEM_CHESTO_BERRY].holdEffect == HOLD_EFFECT_CURE_SLP);
        ASSUME(gItemsInfo[ITEM_LUM_BERRY].holdEffect == HOLD_EFFECT_CURE_STATUS);
        PLAYER(SPECIES_ZIGZAGOON);
        OPPONENT(SPECIES_ZIGZAGOON) { Item(heldItem); }
    } WHEN {
        TURN { MOVE(player, MOVE_SPORE); }
        TURN { MOVE(player, MOVE_SPORE); }
    } SCENE {
        MESSAGE("Zigzagoon used Spore!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPORE, player);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_SLP, opponent);
        MESSAGE("The opposing Zigzagoon fell asleep!");
        if (heldItem == ITEM_CHESTO_BERRY)
            MESSAGE("The opposing Zigzagoon's Chesto Berry woke it up!");
        else
            MESSAGE("The opposing Zigzagoon's Lum Berry woke it up!");
        MESSAGE("Zigzagoon used Spore!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPORE, player);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_SLP, opponent);
        MESSAGE("The opposing Zigzagoon fell asleep!");
    }
}

DOUBLE_BATTLE_TEST("Sleep Clause: Sleep clause is deactivated when a sleeping mon is woken up by Flinging a held item")
{
    enum Item heldItem = ITEM_NONE;
    PARAMETRIZE { heldItem = ITEM_CHESTO_BERRY; }
    PARAMETRIZE { heldItem = ITEM_LUM_BERRY; }
    GIVEN {
        FLAG_SET(B_FLAG_SLEEP_CLAUSE);
        ASSUME(GetMoveEffect(MOVE_SPORE) == EFFECT_NON_VOLATILE_STATUS);
        ASSUME(GetMoveNonVolatileStatus(MOVE_SPORE) == MOVE_EFFECT_SLEEP);
        ASSUME(GetMoveEffect(MOVE_FLING) == EFFECT_FLING);
        ASSUME(gItemsInfo[ITEM_CHESTO_BERRY].holdEffect == HOLD_EFFECT_CURE_SLP);
        ASSUME(gItemsInfo[ITEM_LUM_BERRY].holdEffect == HOLD_EFFECT_CURE_STATUS);
        PLAYER(SPECIES_ZIGZAGOON);
        PLAYER(SPECIES_ZIGZAGOON) { Item(heldItem); }
        OPPONENT(SPECIES_ZIGZAGOON);
        OPPONENT(SPECIES_ZIGZAGOON);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_SPORE, target: opponentLeft); MOVE(playerRight, MOVE_FLING, target: opponentLeft); }
        TURN { MOVE(playerLeft, MOVE_SPORE, target: opponentLeft); }
    } SCENE {
        MESSAGE("Zigzagoon used Spore!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPORE, playerLeft);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_SLP, opponentLeft);
        MESSAGE("The opposing Zigzagoon fell asleep!");
        MESSAGE("Zigzagoon used Fling!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FLING, playerRight);
        if (heldItem == ITEM_CHESTO_BERRY)
            MESSAGE("The opposing Zigzagoon's Chesto Berry woke it up!");
        else
            MESSAGE("The opposing Zigzagoon's Lum Berry woke it up!");
        MESSAGE("Zigzagoon used Spore!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPORE, playerLeft);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_SLP, opponentLeft);
        MESSAGE("The opposing Zigzagoon fell asleep!");
    }
}

SINGLE_BATTLE_TEST("Sleep Clause: Sleep clause is deactivated when a sleeping mon is woken up by using an item")
{
    GIVEN {
        FLAG_SET(B_FLAG_SLEEP_CLAUSE);
        ASSUME(GetMoveEffect(MOVE_SPORE) == EFFECT_NON_VOLATILE_STATUS);
        ASSUME(GetMoveNonVolatileStatus(MOVE_SPORE) == MOVE_EFFECT_SLEEP);
        ASSUME(gItemsInfo[ITEM_AWAKENING].battleUsage == EFFECT_ITEM_CURE_STATUS);
        PLAYER(SPECIES_ZIGZAGOON);
        OPPONENT(SPECIES_ZIGZAGOON);
    } WHEN {
        TURN { MOVE(player, MOVE_SPORE); }
        TURN { USE_ITEM(opponent, ITEM_AWAKENING, partyIndex: 0); MOVE(player, MOVE_SPORE); }
    } SCENE {
        MESSAGE("Zigzagoon used Spore!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPORE, player);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_SLP, opponent);
        MESSAGE("The opposing Zigzagoon fell asleep!");
        MESSAGE("The opposing Zigzagoon woke up!");
        MESSAGE("Zigzagoon used Spore!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPORE, player);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_SLP, opponent);
        MESSAGE("The opposing Zigzagoon fell asleep!");
    }
}

SINGLE_BATTLE_TEST("Sleep Clause: Sleep clause is deactivated when a sleeping mon faints")
{
    GIVEN {
        FLAG_SET(B_FLAG_SLEEP_CLAUSE);
        ASSUME(GetMoveEffect(MOVE_SPORE) == EFFECT_NON_VOLATILE_STATUS);
        ASSUME(GetMoveNonVolatileStatus(MOVE_SPORE) == MOVE_EFFECT_SLEEP);
        PLAYER(SPECIES_ZIGZAGOON);
        OPPONENT(SPECIES_ZIGZAGOON) { Level(5); }
        OPPONENT(SPECIES_ZIGZAGOON);
    } WHEN {
        TURN { MOVE(player, MOVE_SPORE); }
        TURN { MOVE(player, MOVE_SCRATCH); SEND_OUT(opponent, 1); }
        TURN { MOVE(player, MOVE_SPORE); }
    } SCENE {
        MESSAGE("Zigzagoon used Spore!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPORE, player);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_SLP, opponent);
        MESSAGE("The opposing Zigzagoon fell asleep!");
        MESSAGE("The opposing Zigzagoon fainted!");
        MESSAGE("Zigzagoon used Spore!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPORE, player);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_SLP, opponent);
        MESSAGE("The opposing Zigzagoon fell asleep!");
    }
}

DOUBLE_BATTLE_TEST("Sleep Clause: Sleep clause is deactivated when a sleeping mon faints (Doubles)")
{
    GIVEN {
        FLAG_SET(B_FLAG_SLEEP_CLAUSE);
        ASSUME(GetMoveEffect(MOVE_SPORE) == EFFECT_NON_VOLATILE_STATUS);
        ASSUME(GetMoveNonVolatileStatus(MOVE_SPORE) == MOVE_EFFECT_SLEEP);
        PLAYER(SPECIES_ZIGZAGOON);
        PLAYER(SPECIES_ZIGZAGOON);
        OPPONENT(SPECIES_ZIGZAGOON) { Level(5); }
        OPPONENT(SPECIES_ZIGZAGOON);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_SPORE, target: opponentLeft); MOVE(playerRight, MOVE_SCRATCH, target: opponentLeft); }
        TURN { MOVE(playerLeft, MOVE_SPORE, target: opponentRight); }
    } SCENE {
        MESSAGE("Zigzagoon used Spore!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPORE, playerLeft);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_SLP, opponentLeft);
        MESSAGE("The opposing Zigzagoon fell asleep!");
        MESSAGE("The opposing Zigzagoon fainted!");
        MESSAGE("Zigzagoon used Spore!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPORE, playerLeft);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_SLP, opponentRight);
        MESSAGE("The opposing Zigzagoon fell asleep!");
    }
}

SINGLE_BATTLE_TEST("Sleep Clause: Sleep clause is deactivated when a sleeping mon is woken up by gaining the ability Insomnia / Vital Spirit")
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_VITAL_SPIRIT; }
    PARAMETRIZE { ability = ABILITY_INSOMNIA; }
    GIVEN {
        FLAG_SET(B_FLAG_SLEEP_CLAUSE);
        ASSUME(GetMoveEffect(MOVE_SPORE) == EFFECT_NON_VOLATILE_STATUS);
        ASSUME(GetMoveNonVolatileStatus(MOVE_SPORE) == MOVE_EFFECT_SLEEP);
        PLAYER(SPECIES_DELIBIRD) { Ability(ability); }
        OPPONENT(SPECIES_ZIGZAGOON) { Moves(MOVE_SLEEP_TALK, MOVE_SKILL_SWAP); }
    } WHEN {
        TURN { MOVE(player, MOVE_SPORE); MOVE(opponent, MOVE_SLEEP_TALK); }
        TURN { MOVE(opponent, MOVE_SKILL_SWAP); }
        TURN { MOVE(player, MOVE_SPORE); MOVE(opponent, MOVE_SKILL_SWAP); }
    } SCENE {
        MESSAGE("Delibird used Spore!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPORE, player);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_SLP, opponent);
        MESSAGE("The opposing Zigzagoon fell asleep!");
        MESSAGE("The opposing Zigzagoon used Sleep Talk!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SLEEP_TALK, opponent);
        MESSAGE("The opposing Zigzagoon used Skill Swap!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SKILL_SWAP, opponent);
        MESSAGE("The opposing Zigzagoon woke up!");
        MESSAGE("The opposing Zigzagoon used Skill Swap!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SKILL_SWAP, opponent);
        MESSAGE("Delibird used Spore!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPORE, player);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_SLP, opponent);
        MESSAGE("The opposing Zigzagoon fell asleep!");
    }
}

SINGLE_BATTLE_TEST("Sleep Clause: Sleep clause is deactivated when a sleeping mon is sent out, has Trace, and Traces Insomnia / Vital spirit")
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_VITAL_SPIRIT; }
    PARAMETRIZE { ability = ABILITY_INSOMNIA; }

    GIVEN {
        FLAG_SET(B_FLAG_SLEEP_CLAUSE);
        ASSUME(GetMoveEffect(MOVE_SPORE) == EFFECT_NON_VOLATILE_STATUS);
        ASSUME(GetMoveNonVolatileStatus(MOVE_SPORE) == MOVE_EFFECT_SLEEP);
        PLAYER(SPECIES_ZIGZAGOON)
        PLAYER(SPECIES_DELIBIRD) { Ability(ability); }
        OPPONENT(SPECIES_RALTS) { Ability(ABILITY_TRACE); }
        OPPONENT(SPECIES_ZIGZAGOON);
    } WHEN {
        TURN { MOVE(player, MOVE_SPORE); }
        TURN { SWITCH(player, 1); SWITCH(opponent, 1); }
        TURN { SWITCH(opponent, 0); }
        TURN { SWITCH(opponent, 1); MOVE(player, MOVE_SPORE); }
    } SCENE {
        MESSAGE("Zigzagoon used Spore!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPORE, player);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_SLP, opponent);
        MESSAGE("The opposing Ralts fell asleep!");
        MESSAGE("2 sent out Zigzagoon!");
        MESSAGE("2 sent out Ralts!");
        MESSAGE("The opposing Ralts woke up!");
        MESSAGE("2 sent out Zigzagoon!");
        MESSAGE("Delibird used Spore!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPORE, player);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_SLP, opponent);
        MESSAGE("The opposing Zigzagoon fell asleep!");
    }
}

SINGLE_BATTLE_TEST("Sleep Clause: Sleep clause is deactivated when a sleeping mon is sent out and transforms into a mon with Insomnia / Vital spirit")
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_VITAL_SPIRIT; }
    PARAMETRIZE { ability = ABILITY_INSOMNIA; }
    KNOWN_FAILING; // Sleep Clause parts work, but Imposter seems broken with battle messages / targeting. Issue #5565 https://github.com/rh-hideout/pokeemerald-expansion/issues/5565
    GIVEN {
        FLAG_SET(B_FLAG_SLEEP_CLAUSE);
        ASSUME(GetMoveEffect(MOVE_SPORE) == EFFECT_NON_VOLATILE_STATUS);
        ASSUME(GetMoveNonVolatileStatus(MOVE_SPORE) == MOVE_EFFECT_SLEEP);
        ASSUME(gItemsInfo[ITEM_LAGGING_TAIL].holdEffect == HOLD_EFFECT_LAGGING_TAIL);
        PLAYER(SPECIES_ZIGZAGOON)
        PLAYER(SPECIES_DELIBIRD) { Ability(ability); }
        OPPONENT(SPECIES_DITTO) { Ability(ABILITY_IMPOSTER); }
        OPPONENT(SPECIES_ZIGZAGOON);
    } WHEN {
        TURN { MOVE(player, MOVE_SPORE); }
        TURN { SWITCH(player, 1); SWITCH(opponent, 1); }
        TURN { SWITCH(opponent, 0); }
        TURN { SWITCH(opponent, 1); MOVE(player, MOVE_SPORE); }
    } SCENE {
        MESSAGE("The opposing Ditto transformed into Zigzagoon using Imposter!");
        MESSAGE("Zigzagoon used Spore!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPORE, player);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_SLP, opponent);
        MESSAGE("The opposing Ditto fell asleep!");
        MESSAGE("2 sent out Zigzagoon!");
        MESSAGE("2 sent out Ditto!");
        MESSAGE("The opposing Ditto woke up!");
        MESSAGE("2 sent out Zigzagoon!");
        MESSAGE("Delibird used Spore!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPORE, player);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_SLP, opponent);
        MESSAGE("The opposing Zigzagoon fell asleep!");
    }
}

AI_SINGLE_BATTLE_TEST("Sleep Clause: AI will use sleep moves again when sleep clause has been deactivated")
{
    GIVEN {
        FLAG_SET(B_FLAG_SLEEP_CLAUSE);
        ASSUME(GetMoveEffect(MOVE_SPORE) == EFFECT_NON_VOLATILE_STATUS);
        ASSUME(GetMoveNonVolatileStatus(MOVE_SPORE) == MOVE_EFFECT_SLEEP);
        ASSUME(gItemsInfo[ITEM_CHESTO_BERRY].holdEffect == HOLD_EFFECT_CURE_SLP);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_CHESTO_BERRY); }
        OPPONENT(SPECIES_BRELOOM) { Moves(MOVE_SPORE, MOVE_MACH_PUNCH); }
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); EXPECT_MOVE(opponent, MOVE_SPORE); }
        TURN { MOVE(player, MOVE_CELEBRATE); EXPECT_MOVE(opponent, MOVE_SPORE); }
    }
}

DOUBLE_BATTLE_TEST("Sleep Clause: Sleep clause is deactivated when a sleeping mon is woken up with G-Max Sweetness")
{
    GIVEN {
        FLAG_SET(B_FLAG_SLEEP_CLAUSE);
        ASSUME(MoveHasAdditionalEffectSelf(MOVE_G_MAX_SWEETNESS, MOVE_EFFECT_AROMATHERAPY));
        ASSUME(GetMoveEffect(MOVE_SPORE) == EFFECT_NON_VOLATILE_STATUS);
        ASSUME(GetMoveNonVolatileStatus(MOVE_SPORE) == MOVE_EFFECT_SLEEP);
        PLAYER(SPECIES_APPLETUN) { GigantamaxFactor(TRUE); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponentRight, MOVE_SPORE, target: playerRight); }
        TURN { MOVE(playerLeft, MOVE_VINE_WHIP, target: opponentLeft, gimmick: GIMMICK_DYNAMAX); }
        TURN { MOVE(opponentRight, MOVE_SPORE, target: playerRight); }
    } SCENE {
        MESSAGE("The opposing Wobbuffet used Spore!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPORE, opponentRight);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_SLP, playerRight);
        MESSAGE("Wobbuffet fell asleep!");
        MESSAGE("Appletun used G-Max Sweetness!");
        MESSAGE("The opposing Wobbuffet used Spore!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPORE, opponentRight);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_SLP, playerRight);
        MESSAGE("Wobbuffet fell asleep!");
    }
}

SINGLE_BATTLE_TEST("Sleep Clause: Pre-existing sleep condition doesn't activate sleep clause")
{
    GIVEN {
        FLAG_SET(B_FLAG_SLEEP_CLAUSE);
        ASSUME(GetMoveEffect(MOVE_SPORE) == EFFECT_NON_VOLATILE_STATUS);
        ASSUME(GetMoveNonVolatileStatus(MOVE_SPORE) == MOVE_EFFECT_SLEEP);
        PLAYER(SPECIES_ZIGZAGOON);
        OPPONENT(SPECIES_ZIGZAGOON) { Status1(STATUS1_SLEEP); }
        OPPONENT(SPECIES_ZIGZAGOON);
    } WHEN {
        TURN { SWITCH(opponent, 1); MOVE(player, MOVE_SPORE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPORE, player);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_SLP, opponent);
        MESSAGE("The opposing Zigzagoon fell asleep!");
        STATUS_ICON(opponent, sleep: TRUE);
    }
}

SINGLE_BATTLE_TEST("Sleep Clause: Sleep caused by Effect Spore does not prevent sleep clause from ever activating") // checks that sleepClauseEffectExempt works properly
{
    PASSES_RANDOMLY(11, 100, RNG_EFFECT_SPORE);
    GIVEN {
        FLAG_SET(B_FLAG_SLEEP_CLAUSE);
        WITH_CONFIG(B_ABILITY_TRIGGER_CHANCE, GEN_5);
        ASSUME(GetMoveEffect(MOVE_SPORE) == EFFECT_NON_VOLATILE_STATUS);
        ASSUME(GetMoveNonVolatileStatus(MOVE_SPORE) == MOVE_EFFECT_SLEEP);
        ASSUME(GetMoveEffect(MOVE_AROMATHERAPY) == EFFECT_HEAL_BELL);
        ASSUME(MoveMakesContact(MOVE_SCRATCH));
        PLAYER(SPECIES_ZIGZAGOON);
        PLAYER(SPECIES_ZIGZAGOON);
        PLAYER(SPECIES_ZIGZAGOON);
        OPPONENT(SPECIES_BRELOOM) { Ability(ABILITY_EFFECT_SPORE); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
        TURN { SWITCH(player, 1); MOVE(opponent, MOVE_SPORE); }
        TURN { SWITCH(player, 2); MOVE(opponent, MOVE_SPORE); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_EFFECT_SPORE);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_SLP, player);
        MESSAGE("Zigzagoon fell asleep!");
        STATUS_ICON(player, sleep: TRUE);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPORE, opponent);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_SLP, player);
        MESSAGE("Zigzagoon fell asleep!");
        STATUS_ICON(player, sleep: TRUE);
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_SPORE, opponent);
            ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_SLP, player);
            MESSAGE("Zigzagoon fell asleep!");
            STATUS_ICON(player, sleep: TRUE);
        }
        MESSAGE("Sleep Clause kept Zigzagoon awake!");
    }
}

SINGLE_BATTLE_TEST("Sleep Clause: Waking up after Effect Spore doesn't deactivate sleep clause")
{
    PASSES_RANDOMLY(11, 100, RNG_EFFECT_SPORE);
    GIVEN {
        FLAG_SET(B_FLAG_SLEEP_CLAUSE);
        WITH_CONFIG(B_ABILITY_TRIGGER_CHANCE, GEN_5);
        ASSUME(GetMoveEffect(MOVE_SPORE) == EFFECT_NON_VOLATILE_STATUS);
        ASSUME(GetMoveNonVolatileStatus(MOVE_SPORE) == MOVE_EFFECT_SLEEP);
        ASSUME(MoveMakesContact(MOVE_SCRATCH));
        PLAYER(SPECIES_ZIGZAGOON);
        PLAYER(SPECIES_ZIGZAGOON);
        OPPONENT(SPECIES_BRELOOM) { Ability(ABILITY_EFFECT_SPORE); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
        TURN {}
        TURN {}
        TURN {}
        TURN {}
        TURN {}
        TURN { MOVE(opponent, MOVE_SPORE); }
        TURN { SWITCH(player, 1); MOVE(opponent, MOVE_SPORE); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_EFFECT_SPORE);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_SLP, player);
        MESSAGE("Zigzagoon fell asleep!");
        STATUS_ICON(player, sleep: TRUE);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPORE, opponent);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_SLP, player);
        MESSAGE("Zigzagoon fell asleep!");
        STATUS_ICON(player, sleep: TRUE);
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_SPORE, opponent);
            ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_SLP, player);
            MESSAGE("Zigzagoon fell asleep!");
            STATUS_ICON(player, sleep: TRUE);
        }
        MESSAGE("Sleep Clause kept Zigzagoon awake!");
    }
}

DOUBLE_BATTLE_TEST("Sleep Clause: Waking up after Effect Spore doesn't deactivate sleep clause (Doubles)")
{
    PASSES_RANDOMLY(11, 100, RNG_EFFECT_SPORE);
    GIVEN {
        FLAG_SET(B_FLAG_SLEEP_CLAUSE);
        WITH_CONFIG(B_ABILITY_TRIGGER_CHANCE, GEN_5);
        ASSUME(GetMoveEffect(MOVE_SPORE) == EFFECT_NON_VOLATILE_STATUS);
        ASSUME(GetMoveNonVolatileStatus(MOVE_SPORE) == MOVE_EFFECT_SLEEP);
        ASSUME(GetMoveEffect(MOVE_AROMATHERAPY) == EFFECT_HEAL_BELL);
        ASSUME(MoveMakesContact(MOVE_SCRATCH));
        PLAYER(SPECIES_ZIGZAGOON);
        PLAYER(SPECIES_ZIGZAGOON);
        PLAYER(SPECIES_ZIGZAGOON);
        OPPONENT(SPECIES_BRELOOM) { Ability(ABILITY_EFFECT_SPORE); }
        OPPONENT(SPECIES_ZIGZAGOON);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_SCRATCH, target: opponentLeft); MOVE(opponentRight, MOVE_SPORE, target:playerRight); }
        TURN { SWITCH(playerLeft, 2); }
        TURN { MOVE(playerLeft, MOVE_AROMATHERAPY); MOVE(opponentRight, MOVE_SPORE, target:playerRight); MOVE(opponentLeft, MOVE_SPORE, target:playerLeft); }
    } SCENE {
        ABILITY_POPUP(opponentLeft, ABILITY_EFFECT_SPORE);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_SLP, playerLeft);
        MESSAGE("Zigzagoon fell asleep!");
        STATUS_ICON(playerLeft, sleep: TRUE);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPORE, opponentRight);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_SLP, playerRight);
        MESSAGE("Zigzagoon fell asleep!");
        STATUS_ICON(playerRight, sleep: TRUE);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_AROMATHERAPY, playerLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPORE, opponentRight);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_SLP, playerRight);
        MESSAGE("Zigzagoon fell asleep!");
        STATUS_ICON(playerRight, sleep: TRUE);
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_SPORE, opponentLeft);
            ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_SLP, playerLeft);
            MESSAGE("Zigzagoon fell asleep!");
            STATUS_ICON(playerLeft, sleep: TRUE);
        }
        MESSAGE("Sleep Clause kept Zigzagoon awake!");
    }
}

SINGLE_BATTLE_TEST("Sleep Clause: Waking up after Rest doesn't deactivate sleep clause")
{
    GIVEN {
        FLAG_SET(B_FLAG_SLEEP_CLAUSE);
        ASSUME(GetMoveEffect(MOVE_SPORE) == EFFECT_NON_VOLATILE_STATUS);
        ASSUME(GetMoveNonVolatileStatus(MOVE_SPORE) == MOVE_EFFECT_SLEEP);
        ASSUME(GetMoveEffect(MOVE_REST) == EFFECT_REST);
        PLAYER(SPECIES_ZIGZAGOON) { HP(1); MaxHP(100); }
        PLAYER(SPECIES_ZIGZAGOON);
        OPPONENT(SPECIES_ZIGZAGOON);
    } WHEN {
        TURN { MOVE(player, MOVE_REST); }
        TURN {}
        TURN {}
        TURN {}
        TURN { MOVE(opponent, MOVE_SPORE); }
        TURN { SWITCH(player, 1); MOVE(opponent, MOVE_SPORE); }
    } SCENE {
        MESSAGE("Zigzagoon slept and restored its HP!");
        STATUS_ICON(player, sleep: TRUE);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_REST, player);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_SLP, player);
        MESSAGE("Zigzagoon woke up!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPORE, opponent);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_SLP, player);
        MESSAGE("Zigzagoon fell asleep!");
        STATUS_ICON(player, sleep: TRUE);
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_SPORE, opponent);
            ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_SLP, player);
            MESSAGE("Zigzagoon fell asleep!");
            STATUS_ICON(player, sleep: TRUE);
        }
        MESSAGE("Sleep Clause kept Zigzagoon awake!");
    }
}

DOUBLE_BATTLE_TEST("Sleep Clause: Waking up after Rest doesn't deactivate sleep clause (Doubles)")
{
    GIVEN {
        FLAG_SET(B_FLAG_SLEEP_CLAUSE);
        ASSUME(GetMoveEffect(MOVE_SPORE) == EFFECT_NON_VOLATILE_STATUS);
        ASSUME(GetMoveNonVolatileStatus(MOVE_SPORE) == MOVE_EFFECT_SLEEP);
        ASSUME(GetMoveEffect(MOVE_REST) == EFFECT_REST);
        PLAYER(SPECIES_ZIGZAGOON) { HP(1); MaxHP(100); }
        PLAYER(SPECIES_ZIGZAGOON);
        PLAYER(SPECIES_ZIGZAGOON);
        OPPONENT(SPECIES_ZIGZAGOON);
        OPPONENT(SPECIES_ZIGZAGOON);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_REST); MOVE(opponentRight, MOVE_SPORE, target:playerRight); }
        TURN { SWITCH(playerRight, 2); }
        TURN {}
        TURN {}
        TURN { MOVE(opponentRight, MOVE_SPORE, target:playerRight); }
    } SCENE {
        MESSAGE("Zigzagoon slept and restored its HP!");
        STATUS_ICON(playerLeft, sleep: TRUE);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_REST, playerLeft);
        MESSAGE("The opposing Zigzagoon used Spore!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPORE, opponentRight);
        MESSAGE("Zigzagoon fell asleep!");
        STATUS_ICON(playerRight, sleep: TRUE);
        MESSAGE("Zigzagoon woke up!");
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_SPORE, opponentRight);
            MESSAGE("Zigzagoon fell asleep!");
            STATUS_ICON(playerRight, sleep: TRUE);
        }
        MESSAGE("Sleep Clause kept Zigzagoon awake!");
    }
}

SINGLE_BATTLE_TEST("Sleep Clause: Suppressing and then sleeping Vital Spirit / Insomnia and switching back in deactivates sleep clause")
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_VITAL_SPIRIT; }
    PARAMETRIZE { ability = ABILITY_INSOMNIA; }
    GIVEN {
        FLAG_SET(B_FLAG_SLEEP_CLAUSE);
        ASSUME(GetMoveEffect(MOVE_SPORE) == EFFECT_NON_VOLATILE_STATUS);
        ASSUME(GetMoveNonVolatileStatus(MOVE_SPORE) == MOVE_EFFECT_SLEEP);
        PLAYER(SPECIES_ZIGZAGOON);
        OPPONENT(SPECIES_DELIBIRD) { Ability(ability); }
        OPPONENT(SPECIES_ZIGZAGOON);
    } WHEN {
        TURN { MOVE(player, MOVE_GASTRO_ACID); }
        TURN { MOVE(player, MOVE_SPORE); }
        TURN { SWITCH(opponent, 1); MOVE(player, MOVE_SPORE); }
        TURN { SWITCH(opponent, 0); }
        TURN { SWITCH(opponent, 1); MOVE(player, MOVE_SPORE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPORE, player);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_SLP, opponent);
        MESSAGE("The opposing Delibird fell asleep!");
        STATUS_ICON(opponent, sleep: TRUE);
        MESSAGE("Sleep Clause kept the opposing Zigzagoon awake!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPORE, player);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_SLP, opponent);
        MESSAGE("The opposing Zigzagoon fell asleep!");
        STATUS_ICON(opponent, sleep: TRUE);
    }
}

SINGLE_BATTLE_TEST("Sleep Clause: Mold Breaker Pokémon sleeping Vital Spirit / Insomnia activates sleep clause")
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_VITAL_SPIRIT; }
    PARAMETRIZE { ability = ABILITY_INSOMNIA; }
    GIVEN {
        FLAG_SET(B_FLAG_SLEEP_CLAUSE);
        ASSUME(GetMoveEffect(MOVE_SPORE) == EFFECT_NON_VOLATILE_STATUS);
        ASSUME(GetMoveNonVolatileStatus(MOVE_SPORE) == MOVE_EFFECT_SLEEP);
        PLAYER(SPECIES_PANCHAM) { Ability(ABILITY_MOLD_BREAKER); }
        OPPONENT(SPECIES_DELIBIRD) { Ability(ability); }
        OPPONENT(SPECIES_ZIGZAGOON);
    } WHEN {
        TURN { MOVE(player, MOVE_SPORE); }
        TURN { SWITCH(opponent, 1); MOVE(player, MOVE_SPORE); }
        TURN { SWITCH(opponent, 0); }
        TURN { SWITCH(opponent, 1); MOVE(player, MOVE_SPORE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPORE, player);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_SLP, opponent);
        MESSAGE("The opposing Delibird fell asleep!");
        STATUS_ICON(opponent, sleep: TRUE);
        ABILITY_POPUP(opponent, ability);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPORE, player);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_SLP, opponent);
        MESSAGE("The opposing Zigzagoon fell asleep!");
        STATUS_ICON(opponent, sleep: TRUE);
    }
}

SINGLE_BATTLE_TEST("Sleep Clause: Yawn'd Pokémon slept due to Effect Spore before Yawn triggers does not activate sleep clause")
{
    PASSES_RANDOMLY(11, 100, RNG_EFFECT_SPORE);
    GIVEN {
        FLAG_SET(B_FLAG_SLEEP_CLAUSE);
        WITH_CONFIG(B_ABILITY_TRIGGER_CHANCE, GEN_5);
        ASSUME(GetMoveEffect(MOVE_SPORE) == EFFECT_NON_VOLATILE_STATUS);
        ASSUME(GetMoveNonVolatileStatus(MOVE_SPORE) == MOVE_EFFECT_SLEEP);
        ASSUME(GetMoveEffect(MOVE_YAWN) == EFFECT_YAWN);
        ASSUME(MoveMakesContact(MOVE_SCRATCH));
        PLAYER(SPECIES_BRELOOM) { Ability(ABILITY_EFFECT_SPORE); }
        OPPONENT(SPECIES_ZIGZAGOON);
        OPPONENT(SPECIES_ZIGZAGOON);
    } WHEN {
        TURN { MOVE(player, MOVE_YAWN); }
        TURN { MOVE(opponent, MOVE_SCRATCH); }
        TURN { SWITCH(opponent, 1); MOVE(player, MOVE_SPORE); }
    } SCENE {
        MESSAGE("The opposing Zigzagoon grew drowsy!");
        ABILITY_POPUP(player, ABILITY_EFFECT_SPORE);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_SLP, opponent);
        MESSAGE("The opposing Zigzagoon fell asleep!");
        STATUS_ICON(opponent, sleep: TRUE);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPORE, player);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_SLP, opponent);
        MESSAGE("The opposing Zigzagoon fell asleep!");
        STATUS_ICON(opponent, sleep: TRUE);
    }
}

DOUBLE_BATTLE_TEST("Sleep Clause: Yawn'd Pokémon who's partner is slept before Yawn triggers will not fall asleep due to sleep clause being activated")
{
    GIVEN {
        FLAG_SET(B_FLAG_SLEEP_CLAUSE);
        ASSUME(GetMoveEffect(MOVE_SPORE) == EFFECT_NON_VOLATILE_STATUS);
        ASSUME(GetMoveNonVolatileStatus(MOVE_SPORE) == MOVE_EFFECT_SLEEP);
        ASSUME(GetMoveEffect(MOVE_YAWN) == EFFECT_YAWN);
        PLAYER(SPECIES_ZIGZAGOON);
        PLAYER(SPECIES_ZIGZAGOON);
        OPPONENT(SPECIES_ZIGZAGOON);
        OPPONENT(SPECIES_ZIGZAGOON);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_YAWN, target: opponentLeft); MOVE(playerRight, MOVE_YAWN, target: opponentRight); }
        TURN { MOVE(playerLeft, MOVE_SPORE, target: opponentLeft); }
    } SCENE {
        MESSAGE("The opposing Zigzagoon grew drowsy!");
        MESSAGE("The opposing Zigzagoon grew drowsy!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPORE, playerLeft);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_SLP, opponentLeft);
        MESSAGE("The opposing Zigzagoon fell asleep!");
        STATUS_ICON(opponentLeft, sleep: TRUE);
        NONE_OF {
            MESSAGE( "The opposing Zigzagoon fell asleep!");
            STATUS_ICON(opponentRight, sleep: TRUE);
        }
    }
}

DOUBLE_BATTLE_TEST("Sleep Clause: If both Pokémon on one side are Yawn'd at the same time, one will fall asleep and the other will not")
{
    GIVEN {
        FLAG_SET(B_FLAG_SLEEP_CLAUSE);
        ASSUME(GetMoveEffect(MOVE_SPORE) == EFFECT_NON_VOLATILE_STATUS);
        ASSUME(GetMoveNonVolatileStatus(MOVE_SPORE) == MOVE_EFFECT_SLEEP);
        ASSUME(GetMoveEffect(MOVE_YAWN) == EFFECT_YAWN);
        PLAYER(SPECIES_ZIGZAGOON) { Speed(5); }
        PLAYER(SPECIES_ZIGZAGOON) { Speed(4); }
        OPPONENT(SPECIES_ZIGZAGOON) { Speed(3); }
        OPPONENT(SPECIES_ZIGZAGOON) { Speed(2); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_YAWN, target: opponentLeft); MOVE(playerRight, MOVE_YAWN, target: opponentRight); }
        TURN {}
    } SCENE {
        MESSAGE("The opposing Zigzagoon grew drowsy!");
        MESSAGE("The opposing Zigzagoon grew drowsy!");
        MESSAGE("The opposing Zigzagoon fell asleep!");
        STATUS_ICON(opponentLeft, sleep: TRUE);
        NONE_OF {
            MESSAGE( "The opposing Zigzagoon fell asleep!");
            STATUS_ICON(opponentRight, sleep: TRUE);
        }
    }
}

SINGLE_BATTLE_TEST("Sleep Clause: Reflection moves (ie. Magic Coat) fail if sleep clause is active and they reflect a sleep move")
{
    GIVEN {
        FLAG_SET(B_FLAG_SLEEP_CLAUSE);
        ASSUME(GetMoveEffect(MOVE_SPORE) == EFFECT_NON_VOLATILE_STATUS);
        ASSUME(GetMoveNonVolatileStatus(MOVE_SPORE) == MOVE_EFFECT_SLEEP);
        ASSUME(GetMoveEffect(MOVE_MAGIC_COAT) == EFFECT_MAGIC_COAT);
        PLAYER(SPECIES_ZIGZAGOON);
        PLAYER(SPECIES_ZIGZAGOON);
        OPPONENT(SPECIES_ZIGZAGOON);
        OPPONENT(SPECIES_ZIGZAGOON);
    } WHEN {
        TURN { MOVE(player, MOVE_SPORE); }
        TURN { SWITCH(opponent, 1); }
        TURN { MOVE(player, MOVE_MAGIC_COAT); MOVE(opponent, MOVE_SPORE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPORE, player);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_SLP, opponent);
        MESSAGE("The opposing Zigzagoon fell asleep!");
        STATUS_ICON(opponent, sleep: TRUE);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MAGIC_COAT, player);
        MESSAGE("Zigzagoon bounced the Spore back!");
        MESSAGE("Sleep Clause kept the opposing Zigzagoon awake!");
    }
}

SINGLE_BATTLE_TEST("Sleep Clause: Reflection moves (ie. Magic Coat) that reflect a sleep move activate sleep clause")
{
    GIVEN {
        FLAG_SET(B_FLAG_SLEEP_CLAUSE);
        ASSUME(GetMoveEffect(MOVE_SPORE) == EFFECT_NON_VOLATILE_STATUS);
        ASSUME(GetMoveNonVolatileStatus(MOVE_SPORE) == MOVE_EFFECT_SLEEP);
        ASSUME(GetMoveEffect(MOVE_MAGIC_COAT) == EFFECT_MAGIC_COAT);
        PLAYER(SPECIES_ZIGZAGOON);
        PLAYER(SPECIES_ZIGZAGOON);
        OPPONENT(SPECIES_ZIGZAGOON);
        OPPONENT(SPECIES_ZIGZAGOON);
    } WHEN {
        TURN { MOVE(player, MOVE_MAGIC_COAT); MOVE(opponent, MOVE_SPORE); }
        TURN { SWITCH(opponent, 1); }
        TURN { MOVE(player, MOVE_SPORE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MAGIC_COAT, player);
        MESSAGE("Zigzagoon bounced the Spore back!");
        MESSAGE("The opposing Zigzagoon fell asleep!");
        STATUS_ICON(opponent, sleep: TRUE);
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_SPORE, player);
            ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_SLP, opponent);
            MESSAGE("The opposing Zigzagoon fell asleep!");
            STATUS_ICON(opponent, sleep: TRUE);
        }
        MESSAGE("Sleep Clause kept the opposing Zigzagoon awake!");
    }
}

DOUBLE_BATTLE_TEST("Sleep Clause: Reflection moves (ie. Magic Coat) that reflect Dark Void only sleep one opposing Pokémon")
{
    // Source: https://bulbapedia.bulbagarden.net/wiki/Dark_Void_(move)
    GIVEN {
        FLAG_SET(B_FLAG_SLEEP_CLAUSE);
        ASSUME(GetMoveEffect(MOVE_MAGIC_COAT) == EFFECT_MAGIC_COAT);
        ASSUME(GetMoveEffect(MOVE_DARK_VOID) == EFFECT_DARK_VOID);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_DARKRAI);
        OPPONENT(SPECIES_DARKRAI);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_MAGIC_COAT); MOVE(opponentLeft, MOVE_DARK_VOID); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DARK_VOID, playerLeft);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_SLP, opponentLeft);
        MESSAGE("The opposing Darkrai fell asleep!");
        STATUS_ICON(opponentLeft, sleep: TRUE);
        NONE_OF {
            ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_SLP, opponentRight);
            STATUS_ICON(opponentRight, sleep: TRUE);
            MESSAGE("The opposing Darkrai fell asleep!");
        }
    }
}

SINGLE_BATTLE_TEST("Sleep Clause: Magic Bounce'ing a sleep move activates sleep clause, and fails if sleep clause is active")
{
    GIVEN {
        FLAG_SET(B_FLAG_SLEEP_CLAUSE);
        ASSUME(GetMoveEffect(MOVE_SPORE) == EFFECT_NON_VOLATILE_STATUS);
        ASSUME(GetMoveNonVolatileStatus(MOVE_SPORE) == MOVE_EFFECT_SLEEP);
        PLAYER(SPECIES_ESPEON) { Ability(ABILITY_MAGIC_BOUNCE); }
        PLAYER(SPECIES_ZIGZAGOON);
        OPPONENT(SPECIES_ZIGZAGOON);
        OPPONENT(SPECIES_ZIGZAGOON);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SPORE); }
        TURN { SWITCH(opponent, 1); }
        TURN { MOVE(opponent, MOVE_SPORE); }
    } SCENE {
        MESSAGE("The opposing Zigzagoon's Spore was bounced back!");
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_SLP, opponent);
        MESSAGE("The opposing Zigzagoon fell asleep!");
        STATUS_ICON(opponent, sleep: TRUE);
        MESSAGE("The opposing Zigzagoon's Spore was bounced back!");
        NONE_OF {
            ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_SLP, opponent);
            MESSAGE("The opposing Zigzagoon fell asleep!");
            STATUS_ICON(opponent, sleep: TRUE);
        }
        MESSAGE("Sleep Clause kept the opposing Zigzagoon awake!");
    }
}

DOUBLE_BATTLE_TEST("Sleep Clause: Magic Bounce reflecting Dark Void only sleeps one opposing Pokémon")
{
    // Source: https://bulbapedia.bulbagarden.net/wiki/Dark_Void_(move)
    GIVEN {
        FLAG_SET(B_FLAG_SLEEP_CLAUSE);
        ASSUME(GetMoveEffect(MOVE_DARK_VOID) == EFFECT_DARK_VOID);
        PLAYER(SPECIES_ESPEON) { Ability(ABILITY_MAGIC_BOUNCE); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_DARKRAI);
        OPPONENT(SPECIES_DARKRAI);
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_DARK_VOID); }
    } SCENE {
        MESSAGE("The opposing Darkrai's Dark Void was bounced back!");
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_SLP, opponentLeft);
        MESSAGE("The opposing Darkrai fell asleep!");
        STATUS_ICON(opponentLeft, sleep: TRUE);
        NONE_OF {
            ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_SLP, opponentRight);
            STATUS_ICON(opponentRight, sleep: TRUE);
            MESSAGE("The opposing Darkrai fell asleep!");
        }
    }
}

DOUBLE_BATTLE_TEST("Sleep Clause: Sleep Clause does not prevent sleeping your partner Pokémon with sleep effects")
{
    GIVEN {
        FLAG_SET(B_FLAG_SLEEP_CLAUSE);
        ASSUME(GetMoveEffect(MOVE_SPORE) == EFFECT_NON_VOLATILE_STATUS);
        ASSUME(GetMoveNonVolatileStatus(MOVE_SPORE) == MOVE_EFFECT_SLEEP);
        PLAYER(SPECIES_ZIGZAGOON);
        PLAYER(SPECIES_ZIGZAGOON);
        PLAYER(SPECIES_ZIGZAGOON);
        PLAYER(SPECIES_ZIGZAGOON);
        PLAYER(SPECIES_ZIGZAGOON);
        PLAYER(SPECIES_ZIGZAGOON);
        OPPONENT(SPECIES_ZIGZAGOON);
        OPPONENT(SPECIES_ZIGZAGOON);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_SPORE, target: playerRight); }
        TURN { SWITCH(playerRight, 2); MOVE(playerLeft, MOVE_SPORE, target: playerRight); }
        TURN { SWITCH(playerRight, 3); MOVE(playerLeft, MOVE_SPORE, target: playerRight); }
        TURN { SWITCH(playerRight, 4); MOVE(playerLeft, MOVE_SPORE, target: playerRight); }
        TURN { SWITCH(playerRight, 5); MOVE(playerLeft, MOVE_SPORE, target: playerRight); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPORE, playerLeft);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_SLP, playerRight);
        MESSAGE("Zigzagoon fell asleep!");
        STATUS_ICON(playerRight, sleep: TRUE);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPORE, playerLeft);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_SLP, playerRight);
        MESSAGE("Zigzagoon fell asleep!");
        STATUS_ICON(playerRight, sleep: TRUE);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPORE, playerLeft);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_SLP, playerRight);
        MESSAGE("Zigzagoon fell asleep!");
        STATUS_ICON(playerRight, sleep: TRUE);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPORE, playerLeft);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_SLP, playerRight);
        MESSAGE("Zigzagoon fell asleep!");
        STATUS_ICON(playerRight, sleep: TRUE);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPORE, playerLeft);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_SLP, playerRight);
        MESSAGE("Zigzagoon fell asleep!");
        STATUS_ICON(playerRight, sleep: TRUE);
    }
}

DOUBLE_BATTLE_TEST("Sleep Clause: Sleep Clause does not prevent sleeping your partner Pokémon with Yawn")
{
    GIVEN {
        FLAG_SET(B_FLAG_SLEEP_CLAUSE);
        ASSUME(GetMoveEffect(MOVE_YAWN) == EFFECT_YAWN);
        PLAYER(SPECIES_ZIGZAGOON);
        PLAYER(SPECIES_ZIGZAGOON);
        PLAYER(SPECIES_ZIGZAGOON);
        PLAYER(SPECIES_ZIGZAGOON);
        PLAYER(SPECIES_ZIGZAGOON);
        PLAYER(SPECIES_ZIGZAGOON);
        OPPONENT(SPECIES_ZIGZAGOON);
        OPPONENT(SPECIES_ZIGZAGOON);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_YAWN, target: playerRight); }
        TURN {}
        TURN { SWITCH(playerRight, 2); MOVE(playerLeft, MOVE_YAWN, target: playerRight); }
        TURN {}
        TURN { SWITCH(playerRight, 3); MOVE(playerLeft, MOVE_YAWN, target: playerRight); }
        TURN {}
        TURN { SWITCH(playerRight, 4); MOVE(playerLeft, MOVE_YAWN, target: playerRight); }
        TURN {}
        TURN { SWITCH(playerRight, 5); MOVE(playerLeft, MOVE_YAWN, target: playerRight); }
        TURN {}
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_YAWN, playerLeft);
        MESSAGE("Zigzagoon grew drowsy!");
        STATUS_ICON(playerRight, sleep: TRUE);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_YAWN, playerLeft);
        MESSAGE("Zigzagoon grew drowsy!");
        STATUS_ICON(playerRight, sleep: TRUE);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_YAWN, playerLeft);
        MESSAGE("Zigzagoon grew drowsy!");
        STATUS_ICON(playerRight, sleep: TRUE);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_YAWN, playerLeft);
        MESSAGE("Zigzagoon grew drowsy!");
        STATUS_ICON(playerRight, sleep: TRUE);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_YAWN, playerLeft);
        MESSAGE("Zigzagoon grew drowsy!");
        STATUS_ICON(playerRight, sleep: TRUE);
    }
}

DOUBLE_BATTLE_TEST("Sleep Clause: Sleep moves used after being Encore'd are prevented when sleep clause is active")
{
    GIVEN {
        WITH_CONFIG(B_ENCORE_TARGET, GEN_3);
        FLAG_SET(B_FLAG_SLEEP_CLAUSE);
        ASSUME(GetMoveEffect(MOVE_SPORE) == EFFECT_NON_VOLATILE_STATUS);
        ASSUME(GetMoveNonVolatileStatus(MOVE_SPORE) == MOVE_EFFECT_SLEEP);
        PLAYER(SPECIES_ZIGZAGOON);
        PLAYER(SPECIES_ZIGZAGOON);
        PLAYER(SPECIES_ZIGZAGOON);
        OPPONENT(SPECIES_ZIGZAGOON);
        OPPONENT(SPECIES_ZIGZAGOON);
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_SPORE, target: playerLeft); MOVE(playerRight, MOVE_ENCORE, target: opponentLeft); }
        TURN { SWITCH(playerLeft, 2); FORCED_MOVE(opponentLeft); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPORE, opponentLeft);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_SLP, playerLeft);
        MESSAGE("Zigzagoon fell asleep!");
        STATUS_ICON(playerLeft, sleep: TRUE);
        MESSAGE("Zigzagoon used Encore!");
        MESSAGE("Go! Zigzagoon!");
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_SPORE, opponentLeft);
            ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_SLP, playerLeft);
            MESSAGE("Zigzagoon fell asleep!");
            STATUS_ICON(playerLeft, sleep: TRUE);
        }
    }
}

DOUBLE_BATTLE_TEST("Sleep Clause: Spore'ing opponent after Yawn'ing partner does not prevent Yawn's effect from sleeping partner")
{
    GIVEN {
        FLAG_SET(B_FLAG_SLEEP_CLAUSE);
        ASSUME(GetMoveEffect(MOVE_SPORE) == EFFECT_NON_VOLATILE_STATUS);
        ASSUME(GetMoveNonVolatileStatus(MOVE_SPORE) == MOVE_EFFECT_SLEEP);
        ASSUME(GetMoveEffect(MOVE_YAWN) == EFFECT_YAWN);
        PLAYER(SPECIES_ZIGZAGOON);
        PLAYER(SPECIES_ZIGZAGOON);
        PLAYER(SPECIES_ZIGZAGOON);
        OPPONENT(SPECIES_ZIGZAGOON);
        OPPONENT(SPECIES_ZIGZAGOON);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_SPORE, target: playerRight); }
        TURN { SWITCH(playerRight, 2); MOVE(playerLeft, MOVE_YAWN, target: playerRight); }
        TURN { MOVE(playerLeft, MOVE_SPORE, target: opponentLeft); MOVE(playerRight, MOVE_SPORE, target: opponentRight); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPORE, playerLeft);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_SLP, playerRight);
        MESSAGE("Zigzagoon fell asleep!");
        STATUS_ICON(playerRight, sleep: TRUE);
        MESSAGE("Go! Zigzagoon!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_YAWN, playerLeft);
        MESSAGE("Zigzagoon grew drowsy!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPORE, playerLeft);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_SLP, opponentLeft);
        MESSAGE("The opposing Zigzagoon fell asleep!");
        STATUS_ICON(opponentLeft, sleep: TRUE);
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_SPORE, playerRight);
            ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_SLP, opponentRight);
            MESSAGE("The opposing Zigzagoon fell asleep!");
            STATUS_ICON(opponentRight, sleep: TRUE);
        }
        MESSAGE("Zigzagoon fell asleep!");
    }
}

DOUBLE_BATTLE_TEST("Sleep Clause: Opponent Spore'ing player's partner after partner was Yawn'd by player does not prevent Spore's effect from sleeping partner and activating clause")
{
    GIVEN {
        FLAG_SET(B_FLAG_SLEEP_CLAUSE);
        ASSUME(GetMoveEffect(MOVE_SPORE) == EFFECT_NON_VOLATILE_STATUS);
        ASSUME(GetMoveNonVolatileStatus(MOVE_SPORE) == MOVE_EFFECT_SLEEP);
        ASSUME(GetMoveEffect(MOVE_YAWN) == EFFECT_YAWN);
        PLAYER(SPECIES_ZIGZAGOON);
        PLAYER(SPECIES_ZIGZAGOON);
        PLAYER(SPECIES_ZIGZAGOON);
        OPPONENT(SPECIES_ZIGZAGOON);
        OPPONENT(SPECIES_ZIGZAGOON);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_YAWN, target: playerRight); }
        TURN { MOVE(opponentLeft, MOVE_SPORE, target: playerRight); MOVE(opponentRight, MOVE_SPORE, target:playerLeft); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_YAWN, playerLeft);
        MESSAGE("Zigzagoon grew drowsy!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPORE, opponentLeft);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_SLP, playerRight);
        MESSAGE("Zigzagoon fell asleep!");
        STATUS_ICON(playerRight, sleep: TRUE);
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_SPORE, opponentRight);
            ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_SLP, playerLeft);
            MESSAGE("Zigzagoon fell asleep!");
            STATUS_ICON(playerLeft, sleep: TRUE);
        }
        MESSAGE("Sleep Clause kept Zigzagoon awake!");
    }
}

MULTI_BATTLE_TEST("Sleep Clause remains active when a partner's Chesto Berry cures sleep")
{
    GIVEN {
        FLAG_SET(B_FLAG_SLEEP_CLAUSE);
        ASSUME(GetMoveEffect(MOVE_SPORE) == EFFECT_NON_VOLATILE_STATUS);
        ASSUME(GetMoveNonVolatileStatus(MOVE_SPORE) == MOVE_EFFECT_SLEEP);
        ASSUME(GetMoveEffect(MOVE_REST) == EFFECT_REST);
        ASSUME(gItemsInfo[ITEM_CHESTO_BERRY].holdEffect == HOLD_EFFECT_CURE_SLP);
        PLAYER(SPECIES_WOBBUFFET);
        PARTNER(SPECIES_WOBBUFFET) { HP(1); Item(ITEM_CHESTO_BERRY); }
        OPPONENT_A(SPECIES_WOBBUFFET);
        OPPONENT_B(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_SPORE, target: playerLeft); }
        TURN { MOVE(playerRight, MOVE_REST); }
        TURN { MOVE(opponentLeft, MOVE_SPORE, target: playerRight); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPORE, opponentLeft);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_SLP, playerLeft);
        STATUS_ICON(playerLeft, sleep: TRUE);

        STATUS_ICON(playerRight, sleep: TRUE);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_REST, playerRight);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_BERRY, playerRight);
        STATUS_ICON(playerRight, sleep: FALSE);

        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_SPORE, opponentLeft);
            ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_SLP, playerRight);
            STATUS_ICON(playerRight, sleep: TRUE);
        }
    }
}
