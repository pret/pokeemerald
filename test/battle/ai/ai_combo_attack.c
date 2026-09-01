#include "global.h"
#include "test/battle.h"
#include "battle_ai_util.h"

AI_DOUBLE_BATTLE_TEST("Combo Attack: Round will not be incentivised on lower battlerId if higher battlerId subsequently does not choose Round")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_ROUND) == EFFECT_ROUND);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_POWERFUL_STATUS);
        TIE_BREAK_TARGET(TARGET_TIE_LO,0);
        PLAYER(SPECIES_WOBBUFFET) { Speed(6); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(5); }
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_ROUND, MOVE_TRI_ATTACK); Speed(4); }
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_ROUND, MOVE_TAILWIND); Speed(3); }
    } WHEN {
        TURN {
            EXPECT_MOVE(opponentLeft, MOVE_TRI_ATTACK, target:playerLeft);
            EXPECT_MOVE(opponentRight, MOVE_TAILWIND);
            SCORE_EQ_VAL(opponentLeft, MOVE_TRI_ATTACK, AI_SCORE_DEFAULT + BEST_DAMAGE_MOVE, target:playerLeft);
            SCORE_EQ_VAL(opponentRight, MOVE_TAILWIND, AI_SCORE_DEFAULT + POWERFUL_STATUS_MOVE + 4, target:playerLeft); // + 4 from "regular" Tailwind AI
            SCORE_EQ_VAL(opponentLeft, MOVE_ROUND, AI_SCORE_DEFAULT, target:playerLeft);
            SCORE_EQ_VAL(opponentRight, MOVE_ROUND, AI_SCORE_DEFAULT + BEST_DAMAGE_MOVE + BEST_EFFECT, target:playerLeft);
        }
    }
}

AI_DOUBLE_BATTLE_TEST("Combo Attack: Round is incentivised over higher damaging moves if present on both battlers")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_ROUND) == EFFECT_ROUND);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        TIE_BREAK_TARGET(TARGET_TIE_LO,0);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_ROUND, MOVE_TRI_ATTACK); }
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_ROUND, MOVE_TRI_ATTACK); }
    } WHEN {
        TURN {
            EXPECT_MOVE(opponentLeft, MOVE_ROUND, target:playerLeft);
            EXPECT_MOVE(opponentRight, MOVE_ROUND, target:playerLeft);
            SCORE_GT(opponentLeft, MOVE_ROUND, MOVE_TRI_ATTACK, target:playerLeft);
            SCORE_GT(opponentRight, MOVE_ROUND, MOVE_TRI_ATTACK, target:playerLeft);
            SCORE_EQ_VAL(opponentLeft, MOVE_ROUND, AI_SCORE_DEFAULT + BEST_EFFECT, target:playerLeft);
            SCORE_EQ_VAL(opponentRight, MOVE_ROUND, AI_SCORE_DEFAULT + BEST_EFFECT, target:playerLeft);
            SCORE_EQ_VAL(opponentLeft, MOVE_TRI_ATTACK, AI_SCORE_DEFAULT + BEST_DAMAGE_MOVE, target:playerLeft);
            SCORE_EQ_VAL(opponentRight, MOVE_TRI_ATTACK, AI_SCORE_DEFAULT + BEST_DAMAGE_MOVE, target:playerLeft);
        }
    }
}

AI_DOUBLE_BATTLE_TEST("Combo Attack: Round is not disincentivised due to partner not also having Round when Round is the best available move")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_ROUND) == EFFECT_ROUND);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        TIE_BREAK_TARGET(TARGET_TIE_LO,0);
        PLAYER(SPECIES_WOBBUFFET) { Speed(1); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(2); }
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_ROUND, MOVE_SCRATCH); Speed(4); }
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_SCRATCH); Speed(3); }
    } WHEN {
        TURN {
            EXPECT_MOVE(opponentLeft, MOVE_ROUND, target:playerLeft);
            EXPECT_MOVE(opponentRight, MOVE_SCRATCH, target:playerLeft);
            SCORE_EQ_VAL(opponentLeft, MOVE_ROUND, AI_SCORE_DEFAULT + BEST_DAMAGE_MOVE, target:playerLeft);
            SCORE_EQ_VAL(opponentRight, MOVE_SCRATCH, AI_SCORE_DEFAULT + BEST_DAMAGE_MOVE, target:playerLeft);
            SCORE_EQ_VAL(opponentLeft, MOVE_SCRATCH, AI_SCORE_DEFAULT, target:playerLeft);
        }
    }
}


AI_DOUBLE_BATTLE_TEST("Combo Attack: Fusion moves are only incentivised when partners are adjacent in turn order")
{
    u32 playerLeftSpeed, opponentLeftSpeed, playerRightSpeed, opponentRightSpeed;
    bool32 partnersAreAdjacent;
    // Turn order: opponentLeft, opponentRight, playerRight, playerLeft.
    PARAMETRIZE { playerLeftSpeed = 10; opponentLeftSpeed = 40; playerRightSpeed = 20; opponentRightSpeed = 30; partnersAreAdjacent = TRUE; }
    // Turn order: opponentLeft, playerRight, playerLeft, opponentRight.
    PARAMETRIZE { playerLeftSpeed = 20; opponentLeftSpeed = 40; playerRightSpeed = 30; opponentRightSpeed = 10; partnersAreAdjacent = FALSE; }

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_FUSION_FLARE) == EFFECT_FUSION_COMBO);
        ASSUME(GetMoveEffect(MOVE_FUSION_BOLT) == EFFECT_FUSION_COMBO);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        TIE_BREAK_TARGET(TARGET_TIE_LO,0);
        PLAYER(SPECIES_WOBBUFFET) { Speed(playerLeftSpeed); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(playerRightSpeed); }
        OPPONENT(SPECIES_RESHIRAM) { Speed(opponentLeftSpeed); Moves(MOVE_FUSION_FLARE, MOVE_FLAMETHROWER); }
        OPPONENT(SPECIES_ZEKROM) { Speed(opponentRightSpeed); Moves(MOVE_FUSION_BOLT); }
    } WHEN {
        TURN {
            if (partnersAreAdjacent) {
                EXPECT_MOVE(opponentLeft, MOVE_FUSION_FLARE, target:playerLeft);
                EXPECT_MOVE(opponentRight, MOVE_FUSION_BOLT, target:playerLeft);
            } else {
                EXPECT_MOVE(opponentLeft, MOVE_FLAMETHROWER, target:playerLeft);
                EXPECT_MOVE(opponentRight, MOVE_FUSION_BOLT, target:playerLeft);
            }
        }
    }
}
