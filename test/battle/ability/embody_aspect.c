#include "global.h"
#include "test/battle.h"


SINGLE_BATTLE_TEST("Embodoy Aspect raises a stat depending on the users form by one stage")
{
    u16 species, ability;

    PARAMETRIZE { species = SPECIES_OGERPON_TEAL_MASK_TERA; ability = ABILITY_EMBODY_ASPECT_TEAL; }
    PARAMETRIZE { species = SPECIES_OGERPON_HEARTHFLAME_MASK_TERA; ability = ABILITY_EMBODY_ASPECT_HEARTHFLAME; }
    PARAMETRIZE { species = SPECIES_OGERPON_WELLSPRING_MASK_TERA; ability = ABILITY_EMBODY_ASPECT_WELLSPRING; }
    PARAMETRIZE { species = SPECIES_OGERPON_CORNERSTONE_MASK_TERA; ability = ABILITY_EMBODY_ASPECT_CORNERSTONE; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(species) { Ability(ability); }
    } WHEN {
        TURN { }
    } SCENE {
        ABILITY_POPUP(opponent, ability);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        if (ability == ABILITY_EMBODY_ASPECT_TEAL)
            MESSAGE("Foe Ogerpon's Embody Aspect raised its Sp. Atk!");
        else if (ability == ABILITY_EMBODY_ASPECT_HEARTHFLAME)
            MESSAGE("Foe Ogerpon's Embody Aspect raised its Attack!");
        else if (ability == ABILITY_EMBODY_ASPECT_WELLSPRING)
            MESSAGE("Foe Ogerpon's Embody Aspect raised its Sp. Def!");
        else if (ability == ABILITY_EMBODY_ASPECT_CORNERSTONE)
            MESSAGE("Foe Ogerpon's Embody Aspect raised its Defense!");
    } THEN {
        if (ability == ABILITY_EMBODY_ASPECT_TEAL)
            EXPECT_EQ(opponent->statStages[STAT_SPATK], DEFAULT_STAT_STAGE + 1);
        else if (ability == ABILITY_EMBODY_ASPECT_HEARTHFLAME)
            EXPECT_EQ(opponent->statStages[STAT_ATK], DEFAULT_STAT_STAGE + 1);
        else if (ability == ABILITY_EMBODY_ASPECT_WELLSPRING)
            EXPECT_EQ(opponent->statStages[STAT_SPDEF], DEFAULT_STAT_STAGE + 1);
        else if (ability == ABILITY_EMBODY_ASPECT_CORNERSTONE)
            EXPECT_EQ(opponent->statStages[STAT_DEF], DEFAULT_STAT_STAGE + 1);
    }
}

SINGLE_BATTLE_TEST("Embodoy Aspect activates when it's no longer effected by Neutralizing Gas")
{
    GIVEN {
        PLAYER(SPECIES_WEEZING) { Ability(ABILITY_NEUTRALIZING_GAS); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_OGERPON_TEAL_MASK_TERA) { Ability(ABILITY_EMBODY_ASPECT_TEAL); }
    } WHEN {
        TURN { SWITCH(player, 1); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_NEUTRALIZING_GAS);
        MESSAGE("Neutralizing Gas filled the area!");
        MESSAGE("Weezing, that's enough! Come back!");
        MESSAGE("The effects of Neutralizing Gas wore off!");
        ABILITY_POPUP(opponent, ABILITY_EMBODY_ASPECT_TEAL);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        MESSAGE("Foe Ogerpon's Embody Aspect raised its Sp. Atk!");
    }
}
