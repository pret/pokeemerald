#include "global.h"
#include "test/battle.h"

TO_DO_BATTLE_TEST("TODO: Write Natural Cure (Ability) test titles")

SINGLE_BATTLE_TEST("Natural Cure cures the user and not another party member when switching out with a hit escape move")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_U_TURN) == EFFECT_HIT_ESCAPE);
        PLAYER(SPECIES_WOBBUFFET) { Status1(STATUS1_POISON); }
        PLAYER(SPECIES_CHANSEY) { Ability(ABILITY_NATURAL_CURE); Status1(STATUS1_POISON); }
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { SWITCH(player, 1); MOVE(opponent, MOVE_CELEBRATE); }
        TURN { MOVE(player, MOVE_U_TURN); MOVE(opponent, MOVE_CELEBRATE); SEND_OUT(player, 2); }
    } THEN {
        EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_STATUS), STATUS1_POISON);
        EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][1], MON_DATA_STATUS), STATUS1_NONE);
    }
}
