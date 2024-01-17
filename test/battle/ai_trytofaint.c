#include "global.h"
#include "test/battle.h"
#include "battle_ai_util.h"

AI_SINGLE_BATTLE_TEST("AI prefers priority moves if it's slower and can kill target")
{
    GIVEN {
        ASSUME(gBattleMoves[MOVE_QUICK_ATTACK].priority == 1);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(SPECIES_WOBBUFFET) { HP(1); Speed(100); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(100); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(1); Moves(MOVE_QUICK_ATTACK, MOVE_STRENGTH); }
    } WHEN {
        TURN { EXPECT_MOVE(opponent, MOVE_QUICK_ATTACK); SEND_OUT(player, 1); }
    } SCENE {
        MESSAGE("Wobbuffet fainted!");
    }
}

AI_SINGLE_BATTLE_TEST("AI will choose a random move if it's faster and can kill target")
{
    GIVEN {
        ASSUME(gBattleMoves[MOVE_QUICK_ATTACK].priority == 1);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(SPECIES_WOBBUFFET) { HP(1); Speed(1); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(1); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(100); Moves(MOVE_QUICK_ATTACK, MOVE_STRENGTH); }
    } WHEN {
        TURN { EXPECT_MOVES(opponent, MOVE_QUICK_ATTACK, MOVE_STRENGTH); SEND_OUT(player, 1); }
    } SCENE {
        MESSAGE("Wobbuffet fainted!");
    }
}

AI_SINGLE_BATTLE_TEST("AI will choose a priority move if it is slower then the target and will be killed")
{
    GIVEN {
        ASSUME(gBattleMoves[MOVE_QUICK_ATTACK].priority == 1);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(SPECIES_WOBBUFFET) { Speed(100); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(60); Speed(1); Moves(MOVE_QUICK_ATTACK, MOVE_STRENGTH); }
    } WHEN {
        TURN { MOVE(player, MOVE_STRENGTH); EXPECT_MOVE(opponent, MOVE_STRENGTH); }
        TURN { MOVE(player, MOVE_STRENGTH); EXPECT_MOVE(opponent, MOVE_QUICK_ATTACK); }
    } SCENE {
        MESSAGE("Foe Wobbuffet fainted!");
    }
}
