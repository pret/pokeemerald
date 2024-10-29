#include "global.h"
#include "test/battle.h"

DOUBLE_BATTLE_TEST("Curious Medicine resets ally's stat stages upon entering battle")
{
    u32 ability;

    PARAMETRIZE { ability = ABILITY_CURIOUS_MEDICINE; }
    PARAMETRIZE { ability = ABILITY_OWN_TEMPO; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_SCOLIPEDE);
        OPPONENT(SPECIES_WYNAUT);
        OPPONENT(SPECIES_SLOWKING_GALAR) { Ability(ability); }
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_QUIVER_DANCE); MOVE(playerLeft, MOVE_CHARM, target: opponentLeft); }
        TURN { SWITCH(opponentRight, 2); MOVE(playerLeft, MOVE_CELEBRATE); }
    } SCENE {
        // Turn 1 - buff up
        MESSAGE("Foe Scolipede used Quiver Dance!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentLeft);
        // Turn 2 - Switch into Slowking
        MESSAGE("2 sent out Slowking!");
        if (ability == ABILITY_CURIOUS_MEDICINE)
        {
            ABILITY_POPUP(opponentRight, ABILITY_CURIOUS_MEDICINE);
            MESSAGE("Foe Scolipede's stat changes were reset!");
        }
    } THEN {
        EXPECT_EQ(opponentLeft->statStages[STAT_ATK], (ability == ABILITY_CURIOUS_MEDICINE) ? DEFAULT_STAT_STAGE : DEFAULT_STAT_STAGE - 2);
        EXPECT_EQ(opponentLeft->statStages[STAT_DEF], DEFAULT_STAT_STAGE);
        EXPECT_EQ(opponentLeft->statStages[STAT_SPEED], (ability == ABILITY_CURIOUS_MEDICINE) ? DEFAULT_STAT_STAGE : DEFAULT_STAT_STAGE + 1);
        EXPECT_EQ(opponentLeft->statStages[STAT_SPATK], (ability == ABILITY_CURIOUS_MEDICINE) ? DEFAULT_STAT_STAGE : DEFAULT_STAT_STAGE + 1);
        EXPECT_EQ(opponentLeft->statStages[STAT_SPDEF], (ability == ABILITY_CURIOUS_MEDICINE) ? DEFAULT_STAT_STAGE : DEFAULT_STAT_STAGE + 1);
        EXPECT_EQ(opponentLeft->statStages[STAT_ACC], DEFAULT_STAT_STAGE);
        EXPECT_EQ(opponentLeft->statStages[STAT_EVASION], DEFAULT_STAT_STAGE);
    }
}
