#include "global.h"
#include "event_data.h"
#include "test/battle.h"

WILD_BATTLE_TEST("Badge boost: B_FLAG_BADGE_BOOST_ATTACK boost Attack", s16 dmg)
{
    u32 badge = 0;
    u32 genConfig = 0;
    for (u32 gen = GEN_1; gen <= GEN_LATEST; gen++)
    {
        PARAMETRIZE { badge = FALSE; genConfig = gen; }
        PARAMETRIZE { badge = TRUE; genConfig = gen; }
    }
    GIVEN {
        if (badge)
            FlagSet(B_FLAG_BADGE_BOOST_ATTACK);
        else
            FlagClear(B_FLAG_BADGE_BOOST_ATTACK);
        WITH_CONFIG(B_BADGE_BOOST, genConfig);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].dmg);
    } FINALLY {
        for (u32 gen = GEN_1; gen <= GEN_LATEST; gen++)
        {
            if (gen <= GEN_3)
                EXPECT_GT(results[2 * gen + 1].dmg, results[2 * gen].dmg);
            else
                EXPECT_EQ(results[2 * gen + 1].dmg, results[2 * gen].dmg);
        }
    }
}

WILD_BATTLE_TEST("Badge boost: B_FLAG_BADGE_BOOST_SPATK boost Special Attack", s16 dmg)
{
    u32 badge = 0;
    u32 genConfig = 0;
    for (u32 gen = GEN_1; gen <= GEN_LATEST; gen++)
    {
        PARAMETRIZE { badge = FALSE; genConfig = gen; }
        PARAMETRIZE { badge = TRUE; genConfig = gen; }
    }
    GIVEN {
        if (badge)
            FlagSet(B_FLAG_BADGE_BOOST_SPATK);
        else
            FlagClear(B_FLAG_BADGE_BOOST_SPATK);
        WITH_CONFIG(B_BADGE_BOOST, genConfig);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_THUNDER_SHOCK); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].dmg);
    } FINALLY {
        for (u32 gen = GEN_1; gen <= GEN_LATEST; gen++)
        {
            if (gen <= GEN_3)
                EXPECT_GT(results[2 * gen + 1].dmg, results[2 * gen].dmg);
            else
                EXPECT_EQ(results[2 * gen + 1].dmg, results[2 * gen].dmg);
        }
    }
}

WILD_BATTLE_TEST("Badge boost: B_FLAG_BADGE_BOOST_DEFENSE boost Defense", s16 dmg)
{
    u32 badge = 0;
    u32 genConfig = 0;
    for (u32 gen = GEN_1; gen <= GEN_LATEST; gen++)
    {
        PARAMETRIZE { badge = FALSE; genConfig = gen; }
        PARAMETRIZE { badge = TRUE; genConfig = gen; }
    }

    GIVEN {
        if (badge)
            FlagSet(B_FLAG_BADGE_BOOST_DEFENSE);
        else
            FlagClear(B_FLAG_BADGE_BOOST_DEFENSE);
        WITH_CONFIG(B_BADGE_BOOST, genConfig);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        HP_BAR(player, captureDamage: &results[i].dmg);
    } FINALLY {
        for (u32 gen = GEN_1; gen <= GEN_LATEST; gen++)
        {
            if (gen <= GEN_3)
                EXPECT_LT(results[2 * gen + 1].dmg, results[2 * gen].dmg);
            else
                EXPECT_EQ(results[2 * gen + 1].dmg, results[2 * gen].dmg);
        }
    }
}

WILD_BATTLE_TEST("Badge boost: B_FLAG_BADGE_BOOST_SPDEF boost Special Defense", s16 dmg)
{
    u32 badge = 0;
    u32 genConfig = 0;
    for (u32 gen = GEN_1; gen <= GEN_LATEST; gen++)
    {
        PARAMETRIZE { badge = FALSE; genConfig = gen; }
        PARAMETRIZE { badge = TRUE; genConfig = gen; }
    }

    GIVEN {
        if (badge)
            FlagSet(B_FLAG_BADGE_BOOST_SPDEF);
        else
            FlagClear(B_FLAG_BADGE_BOOST_SPDEF);
        WITH_CONFIG(B_BADGE_BOOST, genConfig);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_THUNDER_SHOCK); }
    } SCENE {
        HP_BAR(player, captureDamage: &results[i].dmg);
    } FINALLY {
        for (u32 gen = GEN_1; gen <= GEN_LATEST; gen++)
        {
            if (gen <= GEN_3)
                EXPECT_LT(results[2 * gen + 1].dmg, results[2 * gen].dmg);
            else
                EXPECT_EQ(results[2 * gen + 1].dmg, results[2 * gen].dmg);
        }
    }
}

WILD_BATTLE_TEST("Badge boost: B_FLAG_BADGE_BOOST_SPEED boost Speed", s16 dmg)
{
    u32 badge = 0;
    u32 genConfig = 0;
    for (u32 gen = GEN_1; gen <= GEN_LATEST; gen++)
    {
        PARAMETRIZE { badge = FALSE; genConfig = gen; }
        PARAMETRIZE { badge = TRUE; genConfig = gen; }
    }
    GIVEN {
        if (badge)
            FlagSet(B_FLAG_BADGE_BOOST_SPEED);
        else
            FlagClear(B_FLAG_BADGE_BOOST_SPEED);
        WITH_CONFIG(B_BADGE_BOOST, genConfig);
        PLAYER(SPECIES_WOBBUFFET) { Speed(100); HP(1); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(101); HP(1); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); MOVE(opponent, MOVE_SCRATCH); }
    } THEN {
        if (badge && genConfig <= GEN_3)
        {
            EXPECT_EQ(opponent->hp, 0);
            EXPECT_EQ(player->hp, 1);
        }
        else
        {
            EXPECT_EQ(opponent->hp, 1);
            EXPECT_EQ(player->hp, 0);
        }
    }
}
