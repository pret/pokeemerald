#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Dauntless Shield raises Defense by one stage")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_ZAMAZENTA) { Ability(ABILITY_DAUNTLESS_SHIELD); }
    } WHEN {
        TURN {}
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_DAUNTLESS_SHIELD);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        MESSAGE("The opposing Zamazenta's Defense rose!");
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_DEF], DEFAULT_STAT_STAGE + 1);
    }
}

SINGLE_BATTLE_TEST("Dauntless Shield raises Defense by one stage every time it switches in (Gen8)")
{
    GIVEN {
        WITH_CONFIG(B_DAUNTLESS_SHIELD, GEN_8);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_ZAMAZENTA) { Ability(ABILITY_DAUNTLESS_SHIELD); }
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { SWITCH(opponent, 1); }
        TURN { SWITCH(opponent, 0); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_DAUNTLESS_SHIELD);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        MESSAGE("The opposing Zamazenta's Defense rose!");
        ABILITY_POPUP(opponent, ABILITY_DAUNTLESS_SHIELD);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        MESSAGE("The opposing Zamazenta's Defense rose!");
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_DEF], DEFAULT_STAT_STAGE + 1);
    }
}

SINGLE_BATTLE_TEST("Dauntless Shield raises Defense by one stage only once per battle (Gen 9+)")
{
    GIVEN {
        WITH_CONFIG(B_DAUNTLESS_SHIELD, GEN_9);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_ZAMAZENTA) { Ability(ABILITY_DAUNTLESS_SHIELD); }
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { SWITCH(opponent, 1); }
        TURN { SWITCH(opponent, 0); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_DAUNTLESS_SHIELD);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        MESSAGE("The opposing Zamazenta's Defense rose!");
        NONE_OF {
            ABILITY_POPUP(opponent, ABILITY_DAUNTLESS_SHIELD);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
            MESSAGE("The opposing Zamazenta's Defense rose!");
        }
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_DEF], DEFAULT_STAT_STAGE);
    }
}

SINGLE_BATTLE_TEST("Dauntless Shield activates when it's no longer effected by Neutralizing Gas")
{
    GIVEN {
        PLAYER(SPECIES_WEEZING) { Ability(ABILITY_NEUTRALIZING_GAS); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_ZAMAZENTA) { Ability(ABILITY_DAUNTLESS_SHIELD); }
    } WHEN {
        TURN { SWITCH(player, 1); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_NEUTRALIZING_GAS);
        MESSAGE("Neutralizing gas filled the area!");
        SWITCH_OUT_MESSAGE("Weezing");
        MESSAGE("The effects of the neutralizing gas wore off!");
        ABILITY_POPUP(opponent, ABILITY_DAUNTLESS_SHIELD);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        MESSAGE("The opposing Zamazenta's Defense rose!");
    }
}
