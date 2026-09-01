#include "global.h"
#include "test/battle.h"
#include "battle_ai_util.h"

AI_SINGLE_BATTLE_TEST("AI uses Dynamax")
{
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_OMNISCIENT );
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_SCRATCH); DynamaxLevel(10); }
    } WHEN {
        TURN { EXPECT_MOVE(opponent, MOVE_SCRATCH, gimmick: GIMMICK_DYNAMAX); }
    }
}

AI_SINGLE_BATTLE_TEST("AI uses Dynamax -- Max Moves are scored based on max move effects, not base effects")
{
    KNOWN_FAILING;
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_OMNISCIENT );
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_SCRATCH, MOVE_EXPLOSION); DynamaxLevel(10); }
    } WHEN {
        TURN { EXPECT_MOVE(opponent, MOVE_EXPLOSION, gimmick: GIMMICK_DYNAMAX); }
    }
}

AI_SINGLE_BATTLE_TEST("AI uses Dynamax -- AI does not dynamax before using a utility move")
{
    KNOWN_FAILING;
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_OMNISCIENT );
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_FAKE_OUT); DynamaxLevel(10); }
    } WHEN {
        TURN { EXPECT_MOVE(opponent, MOVE_FAKE_OUT, gimmick: GIMMICK_NONE); }
    }
}

AI_TWO_VS_ONE_BATTLE_TEST("AI only Dynamaxes once per trainer in 2v1 multi battles")
{
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_OMNISCIENT);
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_SPLASH); }
        PARTNER(SPECIES_WOBBUFFET) { Moves(MOVE_SPLASH); }
        OPPONENT_A(SPECIES_WOBBUFFET) { Moves(MOVE_SPLASH); DynamaxLevel(10); }
        OPPONENT_A(SPECIES_WOBBUFFET) { Moves(MOVE_SPLASH); DynamaxLevel(10); }
    } WHEN {
        TURN {
            MOVE(playerLeft, MOVE_SPLASH);
            MOVE(playerRight, MOVE_SPLASH);
            EXPECT_MOVE(opponentLeft, MOVE_SPLASH, gimmick: GIMMICK_DYNAMAX);
            EXPECT_MOVE(opponentRight, MOVE_SPLASH, gimmick: GIMMICK_NONE);
        }
        TURN {
            MOVE(playerLeft, MOVE_SPLASH);
            MOVE(playerRight, MOVE_SPLASH);
            EXPECT_MOVE(opponentLeft, MOVE_SPLASH, gimmick: GIMMICK_NONE);
            EXPECT_MOVE(opponentRight, MOVE_SPLASH, gimmick: GIMMICK_NONE);
        }
    }
}

AI_SINGLE_BATTLE_TEST("AI uses the best Max Move")
{
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_OMNISCIENT );
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_SCRATCH, MOVE_HEADBUTT); DynamaxLevel(10); }
    } WHEN {
        TURN { EXPECT_MOVE(opponent, MOVE_HEADBUTT, gimmick: GIMMICK_DYNAMAX); }
    }
}

// Copycatting an ally's Max Guard rendition of Trick Room was a notable strategy.
TO_DO_BATTLE_TEST("TODO: AI uses Dynamax -- AI uses Copycat against a Dynamaxed Pokemon intelligently")
