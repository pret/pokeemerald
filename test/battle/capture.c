#include "global.h"
#include "event_data.h"
#include "pokedex.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gSpeciesInfo[SPECIES_CLEFFA].catchRate == 150);
    ASSUME(gSpeciesInfo[SPECIES_DITTO].catchRate == 35);
}

WILD_BATTLE_TEST("Capture: Incapacitated catch bonus apply correcly with all gen configs")
{
    u32 expectedOdds;
    u32 recordedOdds;
    u32 status;
    u32 gen;

    PARAMETRIZE(expectedOdds = 100, status = STATUS1_SLEEP, gen = GEN_4);
    PARAMETRIZE(expectedOdds = 100, status = STATUS1_FREEZE, gen = GEN_4);
    PARAMETRIZE(expectedOdds = 125, status = STATUS1_SLEEP, gen = GEN_5);
    PARAMETRIZE(expectedOdds = 125, status = STATUS1_FREEZE, gen = GEN_5);

    GIVEN {
        WITH_CONFIG(B_INCAPACITATED_CATCH_BONUS, gen);
        WITH_CONFIG(B_MISSING_BADGE_CATCH_MALUS, GEN_7);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_CLEFFA) {Status1(status);}
    } WHEN {
        TURN { USE_ITEM(player, ITEM_POKE_BALL); }
    } SCENE {
        CATCHING_CHANCE(&recordedOdds);
    } THEN {
        EXPECT_EQ(expectedOdds, recordedOdds);
    }
}

WILD_BATTLE_TEST("Capture: Low level catch bonus apply correcly with all gen configs")
{
    u32 expectedOdds;
    u32 recordedOdds;
    u32 level;
    u32 gen;

    PARAMETRIZE(expectedOdds = 50, level = 10, gen = GEN_7);
    PARAMETRIZE(expectedOdds = 50, level = 15, gen = GEN_7);
    PARAMETRIZE(expectedOdds = 50, level = 30, gen = GEN_7);
    PARAMETRIZE(expectedOdds = 100, level = 10, gen = GEN_8);
    PARAMETRIZE(expectedOdds = 75, level = 15, gen = GEN_8);
    PARAMETRIZE(expectedOdds = 50, level = 30, gen = GEN_8);
    PARAMETRIZE(expectedOdds = 80, level = 10, gen = GEN_9);
    PARAMETRIZE(expectedOdds = 50, level = 15, gen = GEN_9);
    PARAMETRIZE(expectedOdds = 50, level = 30, gen = GEN_9);

    GIVEN {
        WITH_CONFIG(B_LOW_LEVEL_CATCH_BONUS, gen);
        WITH_CONFIG(B_MISSING_BADGE_CATCH_MALUS, GEN_7);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_CLEFFA) {Level(level);}
    } WHEN {
        TURN { USE_ITEM(player, ITEM_POKE_BALL); }
    } SCENE {
        CATCHING_CHANCE(&recordedOdds);
    } THEN {
        EXPECT_EQ(expectedOdds, recordedOdds);
    }
}

WILD_BATTLE_TEST("Capture: Missing badge malus apply correcly in gen 8")
{
    u32 expectedOdds = 0;
    u32 recordedOdds;
    u32 playerLevel = 0;
    u32 numBadges = 0;

    for (u32 j = 0; j < 8; j++)
    {
        PARAMETRIZE(expectedOdds = 50, playerLevel = 100, numBadges = j);
        PARAMETRIZE(expectedOdds = 5, playerLevel = 99, numBadges = j);
    }
    PARAMETRIZE(expectedOdds = 50, playerLevel = 100, numBadges = 8);
    PARAMETRIZE(expectedOdds = 50, playerLevel = 99, numBadges = 8);
    PARAMETRIZE(expectedOdds = 50, playerLevel = 21, numBadges = 8);

    GIVEN {
        for (u32 j = 0; j < 8; j++)
        {
            if (j < numBadges)
                FlagSet(FLAG_BADGE01_GET + j);
            else
                FlagClear(FLAG_BADGE01_GET + j);
        }
        WITH_CONFIG(B_MISSING_BADGE_CATCH_MALUS, GEN_8);
        PLAYER(SPECIES_WOBBUFFET) {Level(playerLevel);}
        OPPONENT(SPECIES_CLEFFA);
    } WHEN {
        TURN { USE_ITEM(player, ITEM_POKE_BALL); }
    } SCENE {
        CATCHING_CHANCE(&recordedOdds);
    } THEN {
        EXPECT_EQ(expectedOdds, recordedOdds);
    }
}

WILD_BATTLE_TEST("Capture: Missing badge malus apply correcly in gen 9")
{
    u32 expectedOdds;
    u32 recordedOdds;
    u32 level = 0;
    u32 numBadges = 0;

    PARAMETRIZE(expectedOdds = 250, level = 100, numBadges = 8);
    PARAMETRIZE(expectedOdds = 200, level = 100, numBadges = 7);
    PARAMETRIZE(expectedOdds = 160, level = 100, numBadges = 6);
    PARAMETRIZE(expectedOdds = 128, level = 100, numBadges = 5);
    PARAMETRIZE(expectedOdds = 250, level = 40, numBadges = 4);
    PARAMETRIZE(expectedOdds = 250, level = 40, numBadges = 3);
    PARAMETRIZE(expectedOdds = 200, level = 40, numBadges = 2);
    PARAMETRIZE(expectedOdds = 160, level = 40, numBadges = 1);
    PARAMETRIZE(expectedOdds = 128, level = 40, numBadges = 0);

    GIVEN {
        for (u32 j = 0; j < 8; j++)
        {
            if (j < numBadges)
                FlagSet(FLAG_BADGE01_GET + j);
            else
                FlagClear(FLAG_BADGE01_GET + j);
        }
        WITH_CONFIG(B_MISSING_BADGE_CATCH_MALUS, GEN_9);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_CLEFFA)  {Level(level);};
    } WHEN {
        TURN { USE_ITEM(player, ITEM_QUICK_BALL); }
    } SCENE {
        CATCHING_CHANCE(&recordedOdds);
    } THEN {
        EXPECT_EQ(expectedOdds, recordedOdds);
    }
}

WILD_BATTLE_TEST("Capture: Tranformed Pokemon get the catch rate of the copied species in gen 3/4")
{
    u32 recordedOdds;
    u32 expectedOdds = 0;
    u32 gen = 0;

    const u32 DittoOdds = 11;
    const u32 CleffaOdds = 50;
    for (u32 j = GEN_1; j <= GEN_LATEST; j++)
    {
        if (j == GEN_3 || j == GEN_4)
        {
            PARAMETRIZE(expectedOdds = CleffaOdds, gen = j);
        }
        else
        {
            PARAMETRIZE(expectedOdds = DittoOdds, gen = j);
        }
    }

    GIVEN {
        WITH_CONFIG(B_TRANSFORM_CATCH_RATE, gen);
        WITH_CONFIG(B_MISSING_BADGE_CATCH_MALUS, GEN_7);
        PLAYER(SPECIES_CLEFFA);
        OPPONENT(SPECIES_DITTO) {Ability(ABILITY_IMPOSTER);}
    } WHEN {
        TURN { USE_ITEM(player, ITEM_POKE_BALL); }
    } SCENE {
        CATCHING_CHANCE(&recordedOdds);
    } THEN {
        EXPECT_EQ(expectedOdds, recordedOdds);
    }
}

WILD_BATTLE_TEST("Capture: when CRITICAL_CAPTURE_IF_OWNED is enabled, capture of owned pokemon always appear critical")
{
    enum Item item;
    bool32 alreadyOwned;
    u32 catchingChance;

    PARAMETRIZE(item = ITEM_POKE_BALL, alreadyOwned = FALSE);
    PARAMETRIZE(item = ITEM_QUICK_BALL, alreadyOwned = FALSE);
    PARAMETRIZE(item = ITEM_MASTER_BALL, alreadyOwned = FALSE);
    PARAMETRIZE(item = ITEM_POKE_BALL, alreadyOwned = TRUE);
    PARAMETRIZE(item = ITEM_QUICK_BALL, alreadyOwned = TRUE);
    PARAMETRIZE(item = ITEM_MASTER_BALL, alreadyOwned = TRUE);

    GIVEN {
        ASSUME(gSpeciesInfo[SPECIES_CATERPIE].catchRate > 155);
        if (alreadyOwned)
            GetSetPokedexFlag(NATIONAL_DEX_CATERPIE, FLAG_SET_CAUGHT);
        WITH_CONFIG(B_MISSING_BADGE_CATCH_MALUS, GEN_7);
        WITH_CONFIG(B_CRITICAL_CAPTURE_IF_OWNED, GEN_9);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_CATERPIE);
    } WHEN {
        TURN { USE_ITEM(player, item, WITH_RNG(RNG_BALLTHROW_SHAKE, 0)); }
    } SCENE {
        CATCHING_CHANCE(&catchingChance);
        if (alreadyOwned)
        {
            ANIMATION(ANIM_TYPE_SPECIAL, B_ANIM_CRITICAL_CAPTURE_THROW);
            NOT ANIMATION(ANIM_TYPE_SPECIAL, B_ANIM_BALL_THROW);
        }
        else
        {
            NOT ANIMATION(ANIM_TYPE_SPECIAL, B_ANIM_CRITICAL_CAPTURE_THROW);
            ANIMATION(ANIM_TYPE_SPECIAL, B_ANIM_BALL_THROW);
        }
    } THEN {
        if (item == ITEM_POKE_BALL)
            EXPECT_LT(catchingChance, 255);
        else
            EXPECT_GT(catchingChance, 255);
    }
}

WILD_BATTLE_TEST("Capture: when CRITICAL_CAPTURE_IF_OWNED is enabled, failed capture of owned pokemon does not appear critical")
{
    bool32 success;
    PARAMETRIZE(success = TRUE);
    PARAMETRIZE(success = FALSE);

    GIVEN {
        GetSetPokedexFlag(NATIONAL_DEX_CATERPIE, FLAG_SET_CAUGHT);
        WITH_CONFIG(B_MISSING_BADGE_CATCH_MALUS, GEN_7);
        WITH_CONFIG(B_CRITICAL_CAPTURE_IF_OWNED, GEN_9);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_CATERPIE);
    } WHEN {
        TURN { USE_ITEM(player, ITEM_POKE_BALL, WITH_RNG(RNG_BALLTHROW_SHAKE, success ? 0 : MAX_u16)); }
    } SCENE {
        if (success)
        {
            ANIMATION(ANIM_TYPE_SPECIAL, B_ANIM_CRITICAL_CAPTURE_THROW);
            NOT ANIMATION(ANIM_TYPE_SPECIAL, B_ANIM_BALL_THROW);
        }
        else
        {
            NOT ANIMATION(ANIM_TYPE_SPECIAL, B_ANIM_CRITICAL_CAPTURE_THROW);
            ANIMATION(ANIM_TYPE_SPECIAL, B_ANIM_BALL_THROW);
        }
    }
}

WILD_BATTLE_TEST("Capture: ball data is properly set in captured pokemon")
{
    enum Item item = ITEM_NONE;
    for (enum PokeBall ballId = BALL_STRANGE; ballId < POKEBALL_COUNT; ballId++)
    {
        PARAMETRIZE(item = gPokeBalls[ballId].itemId);
    }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { USE_ITEM(player, item, WITH_RNG(RNG_BALLTHROW_SHAKE, 0)); }
    } SCENE {
        ONE_OF
        {
            ANIMATION(ANIM_TYPE_SPECIAL, B_ANIM_CRITICAL_CAPTURE_THROW);
            ANIMATION(ANIM_TYPE_SPECIAL, B_ANIM_BALL_THROW);
        }
    } THEN {
        EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][1], MON_DATA_POKEBALL), GetItemSecondaryId(item));
    }
}
