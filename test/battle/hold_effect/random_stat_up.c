#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gItemsInfo[ITEM_STARF_BERRY].holdEffect == HOLD_EFFECT_RANDOM_STAT_UP);
}

SINGLE_BATTLE_TEST("Starf Berry randomly raises the holder's Attack, Defense, Sp. Atk, Sp. Def, or Speed by two stages")
{
    PASSES_RANDOMLY(1, 5, RNG_RANDOM_STAT_UP);
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_STARF_BERRY); HP(100); MaxHP(400); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {}
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_BERRY, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        MESSAGE("The Starf Berry sharply boosted Wobbuffet's Attack!");
    } THEN {
        EXPECT_EQ(player->statStages[STAT_ATK], DEFAULT_STAT_STAGE + 2);
    }
}

SINGLE_BATTLE_TEST("Starf Berry randomly raises the holder's Attack, Defense, Sp. Atk, Sp. Def, or Speed by two stages when the holder's HP drop to 1/4 or below")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_STARF_BERRY); HP(101); MaxHP(400); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        HP_BAR(player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_BERRY, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
    } THEN {
        int boostedStats = 0;
        EXPECT_EQ(player->item, ITEM_NONE);
        EXPECT_LE(player->hp * 4, player->maxHP);
        for (int stat = STAT_ATK; stat < NUM_STATS; stat++)
        {
            if (player->statStages[stat] == DEFAULT_STAT_STAGE + 2)
                boostedStats++;
            else
                EXPECT_EQ(player->statStages[stat], DEFAULT_STAT_STAGE);
        }
        EXPECT_EQ(boostedStats, 1);
    }
}

SINGLE_BATTLE_TEST("Starf Berry randomly raises the holder's Attack, Defense, Sp. Atk, Sp. Def, or Speed by two stages when the holder's HP drop to 1/2 or below if it has Gluttony")
{
    GIVEN {
        PLAYER(SPECIES_MUNCHLAX) { Item(ITEM_STARF_BERRY); HP(201); MaxHP(400); Ability(ABILITY_GLUTTONY); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        HP_BAR(player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_BERRY, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
    } THEN {
        int boostedStats = 0;
        EXPECT_EQ(player->item, ITEM_NONE);
        EXPECT_LE(player->hp * 2, player->maxHP);
        for (int stat = STAT_ATK; stat < NUM_STATS; stat++)
        {
            if (player->statStages[stat] == DEFAULT_STAT_STAGE + 2)
                boostedStats++;
            else
                EXPECT_EQ(player->statStages[stat], DEFAULT_STAT_STAGE);
        }
        EXPECT_EQ(boostedStats, 1);
    }
}

SINGLE_BATTLE_TEST("Starf Berry randomly raises the holder's Attack, Defense, Sp. Atk, Sp. Def, or Speed by four stages when the holder's HP drop to 1/4 or below if it has Ripen")
{
    GIVEN {
        PLAYER(SPECIES_FLAPPLE) { Item(ITEM_STARF_BERRY); HP(101); MaxHP(400); Ability(ABILITY_RIPEN); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        HP_BAR(player);
        ABILITY_POPUP(player, ABILITY_RIPEN);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_BERRY, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
    } THEN {
        int boostedStats = 0;
        EXPECT_EQ(player->item, ITEM_NONE);
        EXPECT_LE(player->hp * 4, player->maxHP);
        for (int stat = STAT_ATK; stat < NUM_STATS; stat++)
        {
            if (player->statStages[stat] == DEFAULT_STAT_STAGE + 4)
                boostedStats++;
            else
                EXPECT_EQ(player->statStages[stat], DEFAULT_STAT_STAGE);
        }
        EXPECT_EQ(boostedStats, 1);
    }
}
