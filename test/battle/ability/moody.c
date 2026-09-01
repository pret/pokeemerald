#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Moody randomly raises the user's Attack, Defense, Sp. Atk, Sp. Def, or Speed by two stages")
{
    u32 config, statsNum;

    PARAMETRIZE { config = GEN_8; statsNum = NUM_STATS; }
    PARAMETRIZE { config = GEN_7; statsNum = NUM_BATTLE_STATS; }

    // HP is not included
    PASSES_RANDOMLY(1, statsNum - 1, RNG_MOODY_INCREASE);
    GIVEN {
        WITH_CONFIG(B_MOODY_ACC_EVASION, config);
        PLAYER(SPECIES_OCTILLERY) { Ability(ABILITY_MOODY); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {}
    } SCENE {
        ABILITY_POPUP(player, ABILITY_MOODY);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        MESSAGE("Octillery's Attack rose sharply!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
    } THEN {
        EXPECT_EQ(player->statStages[STAT_ATK], DEFAULT_STAT_STAGE + 2);
    }
}

SINGLE_BATTLE_TEST("Moody randomly lowers the user's Attack, Defense, Sp. Atk, Sp. Def, or Speed by one stage")
{
    u32 config, statsNum;

    PARAMETRIZE { config = GEN_8; statsNum = NUM_STATS; }
    PARAMETRIZE { config = GEN_7; statsNum = NUM_BATTLE_STATS; }

    // One stat becomes unavailable due to it already increasing
    PASSES_RANDOMLY(1, statsNum - 2, RNG_MOODY_DECREASE);
    GIVEN {
        WITH_CONFIG(B_MOODY_ACC_EVASION, config);
        PLAYER(SPECIES_OCTILLERY) { Ability(ABILITY_MOODY); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {}
    } SCENE {
        ABILITY_POPUP(player, ABILITY_MOODY);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        MESSAGE("Octillery's Attack fell!");
    } THEN {
        EXPECT_EQ(player->statStages[STAT_ATK], DEFAULT_STAT_STAGE - 1);
    }
}

SINGLE_BATTLE_TEST("Moody randomly raises the holder's Attack, Defense, Sp. Atk, Sp. Def, or Speed by two stages and lowers a different stat by one stage")
{
    u32 config, statsNum;

    PARAMETRIZE { config = GEN_8; statsNum = NUM_STATS; }
    PARAMETRIZE { config = GEN_7; statsNum = NUM_BATTLE_STATS; }

    PASSES_RANDOMLY(statsNum - 1, statsNum - 1, RNG_MOODY_DECREASE);
    GIVEN {
        WITH_CONFIG(B_MOODY_ACC_EVASION, config);
        PLAYER(SPECIES_OCTILLERY) { Ability(ABILITY_MOODY); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {}
    } SCENE {
        ABILITY_POPUP(player, ABILITY_MOODY);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
    } THEN {
        for (int stat = STAT_ATK; stat < statsNum; stat++)
            EXPECT_NE(player->statStages[stat], DEFAULT_STAT_STAGE + 1); // Both raised and lowered
    }
}

SINGLE_BATTLE_TEST("Moody activates at the end of the turn when switched in")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_OCTILLERY) { Ability(ABILITY_MOODY); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { SWITCH(player, 1); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_MOODY);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
    }
}
