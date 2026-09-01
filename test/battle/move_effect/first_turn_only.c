#include "global.h"
#include "test/battle.h"
#include "battle_ai_util.h"

SINGLE_BATTLE_TEST("Fake Out can only be used on the user's first turn")
{
    GIVEN {
        WITH_CONFIG(B_FIRST_TURN_MOVE, GEN_9);
        PLAYER(SPECIES_WOBBUFFET) { Speed(1); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(1); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(2); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_FAKE_OUT); SWITCH(player, 1); }
        TURN { MOVE(player, MOVE_FAKE_OUT); MOVE(opponent, MOVE_FAKE_OUT); }
        TURN { MOVE(player, MOVE_FAKE_OUT); MOVE(opponent, MOVE_FAKE_OUT); }
    } SCENE {
        MESSAGE("The opposing Wobbuffet used Fake Out!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FAKE_OUT, opponent);
        MESSAGE("The opposing Wobbuffet used Fake Out!");
        NONE_OF { ANIMATION(ANIM_TYPE_MOVE, MOVE_FAKE_OUT, opponent); }
        MESSAGE("Wobbuffet used Fake Out!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FAKE_OUT, player);
        MESSAGE("The opposing Wobbuffet used Fake Out!");
        NONE_OF { ANIMATION(ANIM_TYPE_MOVE, MOVE_FAKE_OUT, opponent); }
        MESSAGE("Wobbuffet used Fake Out!");
        NONE_OF { ANIMATION(ANIM_TYPE_MOVE, MOVE_FAKE_OUT, player); }
    }
}

SINGLE_BATTLE_TEST("Fake Out fails if it's called via Instruct")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_ORANGURU) { Ability(ABILITY_INNER_FOCUS); }
    } WHEN {
        TURN { MOVE(player, MOVE_FAKE_OUT); MOVE(opponent, MOVE_INSTRUCT); }
    } SCENE {
        MESSAGE("Wobbuffet used Fake Out!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FAKE_OUT, player);
        NONE_OF { MESSAGE("The opposing Oranguru flinched and couldn't move!"); }
        ANIMATION(ANIM_TYPE_MOVE, MOVE_INSTRUCT, opponent);
        MESSAGE("Wobbuffet used Fake Out!");
        NONE_OF { ANIMATION(ANIM_TYPE_MOVE, MOVE_FAKE_OUT, player); }
    }
}

AI_DOUBLE_BATTLE_TEST("AI will Fake Out either opponent if one has a slower Fake Out")
{
    PASSES_RANDOMLY(50, 100, RNG_AI_SCORE_TIE_DOUBLES_TARGET);

    GIVEN {
        WITH_CONFIG(AI_REVERSE_BATTLER_LOGIC_ORDER_CHANCE, 0);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY | AI_FLAG_DOUBLE_BATTLE | AI_FLAG_OMNISCIENT);
        TIE_BREAK_TARGET(TARGET_TIE_RANDOM, 0);
        PLAYER(SPECIES_WOBBUFFET) { Speed(1); Moves(MOVE_CELEBRATE); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(1); Moves(MOVE_SEISMIC_TOSS, MOVE_FAKE_OUT, MOVE_CELEBRATE); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(2); Moves(MOVE_SEISMIC_TOSS, MOVE_FAKE_OUT); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(2); Moves(MOVE_CELEBRATE); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_CELEBRATE); MOVE(playerRight, MOVE_CELEBRATE);
            EXPECT_MOVE(opponentLeft, MOVE_FAKE_OUT, target:playerRight);
            SCORE_EQ_VAL(opponentLeft, MOVE_FAKE_OUT, AI_SCORE_DEFAULT + FAST_KILL + 2, target:playerLeft);
            SCORE_EQ_VAL(opponentLeft, MOVE_FAKE_OUT, AI_SCORE_DEFAULT + FAST_KILL + 2, target:playerRight);
            SCORE_EQ_VAL(opponentLeft, MOVE_SEISMIC_TOSS, AI_SCORE_DEFAULT + BEST_DAMAGE_MOVE, target:playerLeft);
            SCORE_EQ_VAL(opponentLeft, MOVE_SEISMIC_TOSS, AI_SCORE_DEFAULT + BEST_DAMAGE_MOVE, target:playerRight);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FAKE_OUT, opponentLeft);
    }
}

AI_DOUBLE_BATTLE_TEST("AI will Fake Out either opponent if one has a slower Fake Out (reversed)")
{
    PASSES_RANDOMLY(50, 100, RNG_AI_SCORE_TIE_DOUBLES_TARGET);

    GIVEN {
        WITH_CONFIG(AI_REVERSE_BATTLER_LOGIC_ORDER_CHANCE, 100);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY | AI_FLAG_DOUBLE_BATTLE | AI_FLAG_OMNISCIENT);
        TIE_BREAK_TARGET(TARGET_TIE_RANDOM, 0);
        PLAYER(SPECIES_WOBBUFFET) { Speed(1); Moves(MOVE_CELEBRATE); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(1); Moves(MOVE_SEISMIC_TOSS, MOVE_FAKE_OUT, MOVE_CELEBRATE); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(2); Moves(MOVE_SEISMIC_TOSS, MOVE_FAKE_OUT); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(2); Moves(MOVE_CELEBRATE); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_CELEBRATE); MOVE(playerRight, MOVE_CELEBRATE);
            EXPECT_MOVE(opponentLeft, MOVE_FAKE_OUT, target:playerRight);
            SCORE_EQ_VAL(opponentLeft, MOVE_FAKE_OUT, AI_SCORE_DEFAULT + FAST_KILL + 2, target:playerLeft);
            SCORE_EQ_VAL(opponentLeft, MOVE_FAKE_OUT, AI_SCORE_DEFAULT + FAST_KILL + 2, target:playerRight);
            SCORE_EQ_VAL(opponentLeft, MOVE_SEISMIC_TOSS, AI_SCORE_DEFAULT + BEST_DAMAGE_MOVE, target:playerLeft);
            SCORE_EQ_VAL(opponentLeft, MOVE_SEISMIC_TOSS, AI_SCORE_DEFAULT + BEST_DAMAGE_MOVE, target:playerRight);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FAKE_OUT, opponentLeft);
    }
}

AI_DOUBLE_BATTLE_TEST("AI will Fake Out a target if its ally has slow KO on the target's partner and the user cannot fast KO the target")
{
    u32 speed = 2;

    PARAMETRIZE { speed = 2; }
    PARAMETRIZE { speed = 4; }

    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY | AI_FLAG_DOUBLE_BATTLE | AI_FLAG_OMNISCIENT);
        PLAYER(SPECIES_WOBBUFFET) { Speed(3); Moves(MOVE_CELEBRATE); HP(40); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(5); Moves(MOVE_DRAGON_RAGE, MOVE_CELEBRATE); HP(100); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(speed); Moves(MOVE_DRAGON_RAGE, MOVE_CELEBRATE); HP(40); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(4); Level(39); Moves(MOVE_SEISMIC_TOSS, MOVE_FAKE_OUT); }
    } WHEN {
        TURN { EXPECT_MOVE(opponentRight, MOVE_FAKE_OUT, target:playerRight);
            SCORE_EQ_VAL(opponentRight, MOVE_SEISMIC_TOSS, AI_SCORE_DEFAULT + BEST_DAMAGE_MOVE, target:playerLeft);
            SCORE_EQ_VAL(opponentRight, MOVE_SEISMIC_TOSS, AI_SCORE_DEFAULT + BEST_DAMAGE_MOVE, target:playerRight);
            if (speed == 2)
            {
                SCORE_EQ_VAL(opponentRight, MOVE_FAKE_OUT, AI_SCORE_DEFAULT + GOOD_EFFECT, target:playerLeft); 
                SCORE_EQ_VAL(opponentRight, MOVE_FAKE_OUT, AI_SCORE_DEFAULT + SLOW_KILL + 2, target:playerRight);
            }
            else
            {
                SCORE_EQ_VAL(opponentRight, MOVE_FAKE_OUT, AI_SCORE_DEFAULT + DECENT_EFFECT, target:playerLeft); 
                SCORE_EQ_VAL(opponentRight, MOVE_FAKE_OUT, AI_SCORE_DEFAULT + FAST_KILL + 2, target:playerRight);
            }
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FAKE_OUT, opponentRight);
    }
}

AI_DOUBLE_BATTLE_TEST("AI may prioritize Fake Out over fast KO when its ally is fast KO'd by both opponents but has a slow KO on target's partner")
{
    PASSES_RANDOMLY(FAKE_OUT_SAVE_ALLY_CHANCE, 100, RNG_AI_FAKE_OUT_SAVE_ALLY);
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY | AI_FLAG_DOUBLE_BATTLE | AI_FLAG_OMNISCIENT);
        TIE_BREAK_TARGET(TARGET_TIE_HI, 0);
        PLAYER(SPECIES_WOBBUFFET) { Speed(3); Moves(MOVE_DRAGON_RAGE, MOVE_CELEBRATE); HP(40); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(3); Moves(MOVE_DRAGON_RAGE, MOVE_CELEBRATE); HP(100); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(2); Moves(MOVE_DRAGON_RAGE, MOVE_CELEBRATE); HP(40); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(4); Level(40); Moves(MOVE_SEISMIC_TOSS, MOVE_FAKE_OUT); }
    } WHEN {
        TURN { EXPECT_MOVE(opponentRight, MOVE_FAKE_OUT, target:playerRight);
            SCORE_EQ_VAL(opponentRight, MOVE_SEISMIC_TOSS, AI_SCORE_DEFAULT + BEST_DAMAGE_MOVE + FAST_KILL, target:playerLeft);
            SCORE_EQ_VAL(opponentRight, MOVE_SEISMIC_TOSS, AI_SCORE_DEFAULT + BEST_DAMAGE_MOVE, target:playerRight);
            SCORE_EQ_VAL(opponentRight, MOVE_FAKE_OUT, AI_SCORE_DEFAULT + DECENT_EFFECT, target:playerLeft); 
            SCORE_EQ_VAL(opponentRight, MOVE_FAKE_OUT, AI_SCORE_DEFAULT + FAST_KILL + 2, target:playerRight);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FAKE_OUT, opponentRight);
    }
}

AI_DOUBLE_BATTLE_TEST("AI will Fake Out a target that its ally has slow KO on when seeing no fast KOs")
{
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY | AI_FLAG_DOUBLE_BATTLE | AI_FLAG_OMNISCIENT);
        PLAYER(SPECIES_WOBBUFFET) { Speed(2); Moves(MOVE_DRAGON_RAGE, MOVE_CELEBRATE); HP(40); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(2); Moves(MOVE_DRAGON_RAGE, MOVE_CELEBRATE); HP(100); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(1); Moves(MOVE_DRAGON_RAGE, MOVE_CELEBRATE); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(3); Level(39); Moves(MOVE_SEISMIC_TOSS, MOVE_FAKE_OUT); }
    } WHEN {
        TURN { EXPECT_MOVE(opponentRight, MOVE_FAKE_OUT, target:playerLeft);
            SCORE_EQ_VAL(opponentRight, MOVE_SEISMIC_TOSS, AI_SCORE_DEFAULT + BEST_DAMAGE_MOVE, target:playerLeft);
            SCORE_EQ_VAL(opponentRight, MOVE_SEISMIC_TOSS, AI_SCORE_DEFAULT + BEST_DAMAGE_MOVE, target:playerRight);
            SCORE_EQ_VAL(opponentRight, MOVE_FAKE_OUT, AI_SCORE_DEFAULT + GOOD_EFFECT, target:playerLeft);
            SCORE_EQ_VAL(opponentRight, MOVE_FAKE_OUT, AI_SCORE_DEFAULT + DECENT_EFFECT, target:playerRight); 
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FAKE_OUT, opponentRight);
    }
}

AI_DOUBLE_BATTLE_TEST("AI will not Fake Out a target that its ally has slow KO on when seeing fast KO")
{
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY | AI_FLAG_DOUBLE_BATTLE | AI_FLAG_OMNISCIENT);
        PLAYER(SPECIES_WOBBUFFET) { Speed(2); Moves(MOVE_DRAGON_RAGE, MOVE_CELEBRATE); HP(40); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(2); Moves(MOVE_DRAGON_RAGE, MOVE_CELEBRATE); HP(100); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(1); Moves(MOVE_SEISMIC_TOSS, MOVE_CELEBRATE); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(3); Level(40); Moves(MOVE_SEISMIC_TOSS, MOVE_FAKE_OUT); }
    } WHEN {
        TURN { EXPECT_MOVE(opponentRight, MOVE_SEISMIC_TOSS, target:playerLeft);
            SCORE_EQ_VAL(opponentRight, MOVE_SEISMIC_TOSS, AI_SCORE_DEFAULT + BEST_DAMAGE_MOVE + FAST_KILL, target:playerLeft);
            SCORE_EQ_VAL(opponentRight, MOVE_SEISMIC_TOSS, AI_SCORE_DEFAULT + BEST_DAMAGE_MOVE, target:playerRight);
            SCORE_EQ_VAL(opponentRight, MOVE_FAKE_OUT, AI_SCORE_DEFAULT + DECENT_EFFECT, target:playerLeft);
            SCORE_EQ_VAL(opponentRight, MOVE_FAKE_OUT, AI_SCORE_DEFAULT + DECENT_EFFECT, target:playerRight); 
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SEISMIC_TOSS, opponentRight);
    }
}

SINGLE_BATTLE_TEST("First Impression can only be used on the user's first turn and will fail on subsequent turns (Gen9-)")
{
    GIVEN {
        WITH_CONFIG(B_FIRST_TURN_MOVE, GEN_9);
        PLAYER(SPECIES_WOBBUFFET) { Speed(1); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(1); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(2); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_FIRST_IMPRESSION); SWITCH(player, 1); }
        TURN { MOVE(player, MOVE_FIRST_IMPRESSION); MOVE(opponent, MOVE_FIRST_IMPRESSION); }
        TURN { MOVE(player, MOVE_FIRST_IMPRESSION); MOVE(opponent, MOVE_FIRST_IMPRESSION); }
    } SCENE {
        MESSAGE("The opposing Wobbuffet used First Impression!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FIRST_IMPRESSION, opponent);
        MESSAGE("The opposing Wobbuffet used First Impression!");
        NONE_OF { ANIMATION(ANIM_TYPE_MOVE, MOVE_FIRST_IMPRESSION, opponent); }
        MESSAGE("Wobbuffet used First Impression!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FIRST_IMPRESSION, player);
        MESSAGE("The opposing Wobbuffet used First Impression!");
        NONE_OF { ANIMATION(ANIM_TYPE_MOVE, MOVE_FIRST_IMPRESSION, opponent); }
        MESSAGE("Wobbuffet used First Impression!");
        NONE_OF { ANIMATION(ANIM_TYPE_MOVE, MOVE_FIRST_IMPRESSION, player); }
    }
}

SINGLE_BATTLE_TEST("First Impression fails if it's called via Instruct")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_ORANGURU);
    } WHEN {
        TURN { MOVE(player, MOVE_FIRST_IMPRESSION); MOVE(opponent, MOVE_INSTRUCT); }
    } SCENE {
        MESSAGE("Wobbuffet used First Impression!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FIRST_IMPRESSION, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_INSTRUCT, opponent);
        MESSAGE("Wobbuffet used First Impression!");
        NONE_OF { ANIMATION(ANIM_TYPE_MOVE, MOVE_FIRST_IMPRESSION, player); }
    }
}
