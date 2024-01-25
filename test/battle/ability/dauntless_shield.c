#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(P_GEN_8_POKEMON == TRUE);
    ASSUME(B_PROTEAN_LIBERO == GEN_9);
}

SINGLE_BATTLE_TEST("Dauntless Shield raises Attack by one stage")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_ZAMAZENTA) { Ability(ABILITY_DAUNTLESS_SHIELD); }
    } WHEN {
        TURN { }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_DAUNTLESS_SHIELD);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        MESSAGE("Foe Zamazenta's Dauntless Shield raised its Defense!");
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_DEF], DEFAULT_STAT_STAGE + 1);
    }
}

SINGLE_BATTLE_TEST("Dauntless Shield raises Attack by one stage only once per battle")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_ZAMAZENTA) { Ability(ABILITY_DAUNTLESS_SHIELD); }
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { SWITCH(opponent, 1); }
        TURN { SWITCH(opponent, 0); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_DAUNTLESS_SHIELD);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        MESSAGE("Foe Zamazenta's Dauntless Shield raised its Defense!");
        NONE_OF {
            ABILITY_POPUP(opponent, ABILITY_DAUNTLESS_SHIELD);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
            MESSAGE("Foe Zamazenta's Dauntless Shield raised its Defense!");
        }
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_DEF], DEFAULT_STAT_STAGE);
    }
}
