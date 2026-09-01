#include "global.h"
#include "test/battle.h"
#include "battle_ai_util.h"

AI_SINGLE_BATTLE_TEST("AI_FLAG_PP_STALL_PREVENTION: AI will stop using moves that has hit into immunities due to switches sometimes")
{
    PASSES_RANDOMLY(PP_STALL_DISREGARD_MOVE_PERCENTAGE, 100, RNG_AI_PP_STALL_DISREGARD_MOVE);
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY | AI_FLAG_PP_STALL_PREVENTION);
        PLAYER(SPECIES_RATICATE);
        PLAYER(SPECIES_GENGAR);
        OPPONENT(SPECIES_KARTANA) { Moves(MOVE_SHADOW_CLAW, MOVE_SACRED_SWORD, MOVE_ROCK_SLIDE); }
    } WHEN {
        TURN { SWITCH(player, 1); EXPECT_MOVE(opponent, MOVE_SACRED_SWORD); }
        TURN { SWITCH(player, 0); EXPECT_MOVE(opponent, MOVE_SHADOW_CLAW); }
        TURN { SWITCH(player, 1); EXPECT_MOVE(opponent, MOVE_SACRED_SWORD); }
    }
}
