#include "global.h"
#include "test/battle.h"
#include "battle_ai_util.h"

AI_SINGLE_BATTLE_TEST("AI_FLAG_ASSUME_STAB sees the player's STAB moves")
{
    u32 aiFlag = 0;
    PARAMETRIZE { aiFlag = AI_FLAG_ASSUME_STAB; }
    PARAMETRIZE { aiFlag = AI_FLAG_OMNISCIENT; }
    PARAMETRIZE { aiFlag = 0; }
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_SMART_MON_CHOICES | aiFlag);
        PLAYER(SPECIES_TYPHLOSION) { Speed(5); Moves(MOVE_TACKLE, MOVE_FLAMETHROWER); }
        OPPONENT(SPECIES_ZIGZAGOON) { Speed(1); Moves(MOVE_TACKLE); Level(1); }
        OPPONENT(SPECIES_SCIZOR) { Speed(4); Moves(MOVE_TACKLE); }
        OPPONENT(SPECIES_BLISSEY) { Speed(4); Moves(MOVE_TACKLE); }
    } WHEN {
        if (aiFlag == AI_FLAG_ASSUME_STAB || aiFlag == AI_FLAG_OMNISCIENT)
            TURN { MOVE(player, MOVE_TACKLE); EXPECT_MOVE(opponent, MOVE_TACKLE); EXPECT_SEND_OUT(opponent, 2); }
        else
            TURN { MOVE(player, MOVE_TACKLE); EXPECT_MOVE(opponent, MOVE_TACKLE); EXPECT_SEND_OUT(opponent, 1); }
    }
}

AI_SINGLE_BATTLE_TEST("AI_FLAG_ASSUME_STAB does not see the player's non-STAB moves")
{
    u32 aiFlag = 0;
    PARAMETRIZE { aiFlag = AI_FLAG_ASSUME_STAB; }
    PARAMETRIZE { aiFlag = AI_FLAG_OMNISCIENT; }
    PARAMETRIZE { aiFlag = 0; }
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_SMART_MON_CHOICES | aiFlag);
        PLAYER(SPECIES_GOREBYSS) { Speed(5); Moves(MOVE_TACKLE, MOVE_FLAMETHROWER); }
        OPPONENT(SPECIES_ZIGZAGOON) { Speed(1); Moves(MOVE_TACKLE); Level(1); }
        OPPONENT(SPECIES_SCIZOR) { Speed(4); Moves(MOVE_TACKLE); }
        OPPONENT(SPECIES_BLISSEY) { Speed(4); Moves(MOVE_TACKLE); }
    } WHEN {
        if (aiFlag == AI_FLAG_OMNISCIENT)
            TURN { MOVE(player, MOVE_TACKLE); EXPECT_MOVE(opponent, MOVE_TACKLE); EXPECT_SEND_OUT(opponent, 2); }
        else
            TURN { MOVE(player, MOVE_TACKLE); EXPECT_MOVE(opponent, MOVE_TACKLE); EXPECT_SEND_OUT(opponent, 1); }
    }
}

AI_DOUBLE_BATTLE_TEST("AI correctly records assumed STAB moves")
{
    u32 aiFlag = 0;
    // Not checking Omniscient here because it doesn't change the battle history
    PARAMETRIZE { aiFlag = AI_FLAG_ASSUME_STAB; }
    PARAMETRIZE { aiFlag = 0; }
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | aiFlag);
        PLAYER(SPECIES_TYPHLOSION) { Moves(MOVE_TACKLE, MOVE_FLAMETHROWER, MOVE_SMOG); }
        PLAYER(SPECIES_ZIGZAGOON) { Moves(MOVE_TACKLE, MOVE_HEADBUTT, MOVE_THUNDERBOLT); }
        OPPONENT(SPECIES_ZIGZAGOON) { Moves(MOVE_TACKLE); }
        OPPONENT(SPECIES_ZIGZAGOON) { Moves(MOVE_TACKLE); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_TACKLE, target:opponentLeft); MOVE(playerRight, MOVE_THUNDERBOLT, target:opponentRight); }
    } THEN {
        if (aiFlag == AI_FLAG_ASSUME_STAB)
        {
            EXPECT_EQ(gBattleHistory->usedMoves[B_POSITION_PLAYER_LEFT][0], MOVE_TACKLE);
            EXPECT_EQ(gBattleHistory->usedMoves[B_POSITION_PLAYER_LEFT][1], MOVE_FLAMETHROWER);
            EXPECT_EQ(gBattleHistory->usedMoves[B_POSITION_PLAYER_LEFT][2], MOVE_NONE);
            EXPECT_EQ(gBattleHistory->usedMoves[B_POSITION_PLAYER_LEFT][3], MOVE_NONE);

            EXPECT_EQ(gBattleHistory->usedMoves[B_POSITION_PLAYER_RIGHT][0], MOVE_TACKLE);
            EXPECT_EQ(gBattleHistory->usedMoves[B_POSITION_PLAYER_RIGHT][1], MOVE_HEADBUTT);
            EXPECT_EQ(gBattleHistory->usedMoves[B_POSITION_PLAYER_RIGHT][2], MOVE_THUNDERBOLT);
            EXPECT_EQ(gBattleHistory->usedMoves[B_POSITION_PLAYER_RIGHT][3], MOVE_NONE);
        }
        else if (aiFlag == 0)
        {
            EXPECT_EQ(gBattleHistory->usedMoves[B_POSITION_PLAYER_LEFT][0], MOVE_TACKLE);
            EXPECT_EQ(gBattleHistory->usedMoves[B_POSITION_PLAYER_LEFT][1], MOVE_NONE);
            EXPECT_EQ(gBattleHistory->usedMoves[B_POSITION_PLAYER_LEFT][2], MOVE_NONE);
            EXPECT_EQ(gBattleHistory->usedMoves[B_POSITION_PLAYER_LEFT][3], MOVE_NONE);

            EXPECT_EQ(gBattleHistory->usedMoves[B_POSITION_PLAYER_RIGHT][0], MOVE_NONE);
            EXPECT_EQ(gBattleHistory->usedMoves[B_POSITION_PLAYER_RIGHT][1], MOVE_NONE);
            EXPECT_EQ(gBattleHistory->usedMoves[B_POSITION_PLAYER_RIGHT][2], MOVE_THUNDERBOLT);
            EXPECT_EQ(gBattleHistory->usedMoves[B_POSITION_PLAYER_RIGHT][3], MOVE_NONE);
        }
    }
}
