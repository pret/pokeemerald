#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_MEAN_LOOK) == EFFECT_MEAN_LOOK);
}

SINGLE_BATTLE_TEST("Mean Look: trapped target Baton Pass keeps trapping")
{
    GIVEN {
        PLAYER(SPECIES_PIKACHU) { Moves(MOVE_BATON_PASS, MOVE_CELEBRATE); }
        PLAYER(SPECIES_PICHU);
        OPPONENT(SPECIES_PIKACHU) { Moves(MOVE_MEAN_LOOK, MOVE_CELEBRATE); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_MEAN_LOOK); MOVE(player, MOVE_CELEBRATE); }
        TURN { MOVE(player, MOVE_BATON_PASS); SEND_OUT(player, 1); }
    } THEN {
        EXPECT(player->volatiles.escapePrevention);
    }
}

SINGLE_BATTLE_TEST("Mean Look: user Baton Pass releases target (Gen 5+)")
{
    GIVEN {
        WITH_CONFIG(B_BATON_PASS_TRAPPING, GEN_5);
        PLAYER(SPECIES_PIKACHU);
        OPPONENT(SPECIES_PIKACHU) { Moves(MOVE_MEAN_LOOK, MOVE_BATON_PASS); }
        OPPONENT(SPECIES_PICHU);
    } WHEN {
        TURN { MOVE(opponent, MOVE_MEAN_LOOK); }
        TURN { MOVE(opponent, MOVE_BATON_PASS); SEND_OUT(opponent, 1); }
    } THEN {
        EXPECT(!player->volatiles.escapePrevention);
    }
}

SINGLE_BATTLE_TEST("Mean Look: user Baton Pass keeps target trapped (Gen 2-4)")
{
    GIVEN {
        WITH_CONFIG(B_BATON_PASS_TRAPPING, GEN_4);
        PLAYER(SPECIES_PIKACHU);
        OPPONENT(SPECIES_PIKACHU) { Moves(MOVE_MEAN_LOOK, MOVE_BATON_PASS); }
        OPPONENT(SPECIES_PICHU);
    } WHEN {
        TURN { MOVE(opponent, MOVE_MEAN_LOOK); }
        TURN { MOVE(opponent, MOVE_BATON_PASS); SEND_OUT(opponent, 1); }
    } THEN {
        EXPECT(player->volatiles.escapePrevention);
    }
}
