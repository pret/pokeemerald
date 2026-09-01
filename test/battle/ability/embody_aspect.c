#include "global.h"
#include "test/battle.h"


SINGLE_BATTLE_TEST("Embody Aspect raises a stat depending on the users form by one stage")
{
    enum Species species;
    enum Ability ability;

    PARAMETRIZE { species = SPECIES_OGERPON_TEAL_TERA; ability = ABILITY_EMBODY_ASPECT_TEAL_MASK; }
    PARAMETRIZE { species = SPECIES_OGERPON_HEARTHFLAME_TERA; ability = ABILITY_EMBODY_ASPECT_HEARTHFLAME_MASK; }
    PARAMETRIZE { species = SPECIES_OGERPON_WELLSPRING_TERA; ability = ABILITY_EMBODY_ASPECT_WELLSPRING_MASK; }
    PARAMETRIZE { species = SPECIES_OGERPON_CORNERSTONE_TERA; ability = ABILITY_EMBODY_ASPECT_CORNERSTONE_MASK; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(species) { Ability(ability); }
    } WHEN {
        TURN {}
    } SCENE {
        ABILITY_POPUP(opponent, ability);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        if (ability == ABILITY_EMBODY_ASPECT_TEAL_MASK)
            MESSAGE("The opposing Ogerpon's Speed rose!");
        else if (ability == ABILITY_EMBODY_ASPECT_HEARTHFLAME_MASK)
            MESSAGE("The opposing Ogerpon's Attack rose!");
        else if (ability == ABILITY_EMBODY_ASPECT_WELLSPRING_MASK)
            MESSAGE("The opposing Ogerpon's Sp. Def rose!");
        else if (ability == ABILITY_EMBODY_ASPECT_CORNERSTONE_MASK)
            MESSAGE("The opposing Ogerpon's Defense rose!");
    } THEN {
        if (ability == ABILITY_EMBODY_ASPECT_TEAL_MASK)
            EXPECT_EQ(opponent->statStages[STAT_SPEED], DEFAULT_STAT_STAGE + 1);
        else if (ability == ABILITY_EMBODY_ASPECT_HEARTHFLAME_MASK)
            EXPECT_EQ(opponent->statStages[STAT_ATK], DEFAULT_STAT_STAGE + 1);
        else if (ability == ABILITY_EMBODY_ASPECT_WELLSPRING_MASK)
            EXPECT_EQ(opponent->statStages[STAT_SPDEF], DEFAULT_STAT_STAGE + 1);
        else if (ability == ABILITY_EMBODY_ASPECT_CORNERSTONE_MASK)
            EXPECT_EQ(opponent->statStages[STAT_DEF], DEFAULT_STAT_STAGE + 1);
    }
}

SINGLE_BATTLE_TEST("Embody Aspect activates when it's no longer effected by Neutralizing Gas")
{
    GIVEN {
        PLAYER(SPECIES_WEEZING) { Ability(ABILITY_NEUTRALIZING_GAS); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_OGERPON_TEAL_TERA) { Ability(ABILITY_EMBODY_ASPECT_TEAL_MASK); }
    } WHEN {
        TURN { SWITCH(player, 1); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_NEUTRALIZING_GAS);
        MESSAGE("Neutralizing gas filled the area!");
        SWITCH_OUT_MESSAGE("Weezing");
        MESSAGE("The effects of the neutralizing gas wore off!");
        ABILITY_POPUP(opponent, ABILITY_EMBODY_ASPECT_TEAL_MASK);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        MESSAGE("The opposing Ogerpon's Speed rose!");
    }
}

SINGLE_BATTLE_TEST("Embody Aspect does not reactivate after Neutralizing Gas ends if it already activated this switch-in")
{
    GIVEN {
        PLAYER(SPECIES_OGERPON_TEAL_TERA) { Ability(ABILITY_EMBODY_ASPECT_TEAL_MASK); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WEEZING) { Ability(ABILITY_NEUTRALIZING_GAS); }
    } WHEN {
        TURN { SWITCH(opponent, 1); }
        TURN { SWITCH(opponent, 0); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_EMBODY_ASPECT_TEAL_MASK);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        MESSAGE("Ogerpon's Speed rose!");

        ABILITY_POPUP(opponent, ABILITY_NEUTRALIZING_GAS);
        MESSAGE("Neutralizing gas filled the area!");

        MESSAGE("The effects of the neutralizing gas wore off!");
        NOT ABILITY_POPUP(player, ABILITY_EMBODY_ASPECT_TEAL_MASK);
    } THEN {
        EXPECT_EQ(player->statStages[STAT_SPEED], DEFAULT_STAT_STAGE + 1);
    }
}
