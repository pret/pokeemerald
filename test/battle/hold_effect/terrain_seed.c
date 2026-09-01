#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gItemsInfo[ITEM_ELECTRIC_SEED].holdEffect == HOLD_EFFECT_TERRAIN_SEED);
    ASSUME(gItemsInfo[ITEM_ELECTRIC_SEED].holdEffectParam == HOLD_EFFECT_PARAM_ELECTRIC_TERRAIN);
    ASSUME(gItemsInfo[ITEM_GRASSY_SEED].holdEffect == HOLD_EFFECT_TERRAIN_SEED);
    ASSUME(gItemsInfo[ITEM_GRASSY_SEED].holdEffectParam == HOLD_EFFECT_PARAM_GRASSY_TERRAIN);
    ASSUME(gItemsInfo[ITEM_MISTY_SEED].holdEffect == HOLD_EFFECT_TERRAIN_SEED);
    ASSUME(gItemsInfo[ITEM_MISTY_SEED].holdEffectParam == HOLD_EFFECT_PARAM_MISTY_TERRAIN);
    ASSUME(gItemsInfo[ITEM_PSYCHIC_SEED].holdEffect == HOLD_EFFECT_TERRAIN_SEED);
    ASSUME(gItemsInfo[ITEM_PSYCHIC_SEED].holdEffectParam == HOLD_EFFECT_PARAM_PSYCHIC_TERRAIN);

}

SINGLE_BATTLE_TEST("Electric Seed raises the holder's Defense on Electric Terrain")
{
    enum Ability ability;
    enum Item item;
    PARAMETRIZE { ability = ABILITY_TELEPATHY; item = ITEM_NONE; }
    PARAMETRIZE { ability = ABILITY_TELEPATHY; item = ITEM_ELECTRIC_SEED; }
    PARAMETRIZE { ability = ABILITY_ELECTRIC_SURGE; item = ITEM_NONE; }
    PARAMETRIZE { ability = ABILITY_ELECTRIC_SURGE; item = ITEM_ELECTRIC_SEED; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_ELECTRIC_SEED); }
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_ELECTRIC_SEED); }
        OPPONENT(SPECIES_TAPU_KOKO) { Ability(ability); Item(item); }
    } WHEN {
        if (ability == ABILITY_TELEPATHY)
            TURN { MOVE(player, MOVE_ELECTRIC_TERRAIN); }
        TURN { SWITCH(player, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        MESSAGE("The Electric Seed boosted Wobbuffet's Defense!");
        if (item == ITEM_ELECTRIC_SEED) {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
            MESSAGE("The Electric Seed boosted the opposing Tapu Koko's Defense!");
        }
        SWITCH_OUT_MESSAGE("Wobbuffet");
        SEND_IN_MESSAGE("Wobbuffet");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        MESSAGE("The Electric Seed boosted Wobbuffet's Defense!");
    } THEN {
        EXPECT_EQ(player->statStages[STAT_DEF], DEFAULT_STAT_STAGE + 1);
    }
}

SINGLE_BATTLE_TEST("Grassy Seed raises the holder's Defense on Grassy Terrain")
{
    enum Ability ability;
    enum Item item;
    PARAMETRIZE { ability = ABILITY_TELEPATHY; item = ITEM_NONE; }
    PARAMETRIZE { ability = ABILITY_TELEPATHY; item = ITEM_GRASSY_SEED; }
    PARAMETRIZE { ability = ABILITY_GRASSY_SURGE; item = ITEM_NONE; }
    PARAMETRIZE { ability = ABILITY_GRASSY_SURGE; item = ITEM_GRASSY_SEED; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_GRASSY_SEED); }
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_GRASSY_SEED); }
        OPPONENT(SPECIES_TAPU_BULU) { Ability(ability); Item(item); }
    } WHEN {
        if (ability == ABILITY_TELEPATHY)
            TURN { MOVE(player, MOVE_GRASSY_TERRAIN); }
        TURN { SWITCH(player, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        MESSAGE("The Grassy Seed boosted Wobbuffet's Defense!");
        if (item == ITEM_GRASSY_SEED) {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
            MESSAGE("The Grassy Seed boosted the opposing Tapu Bulu's Defense!");
        }
        SWITCH_OUT_MESSAGE("Wobbuffet");
        SEND_IN_MESSAGE("Wobbuffet");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        MESSAGE("The Grassy Seed boosted Wobbuffet's Defense!");
    } THEN {
        EXPECT_EQ(player->statStages[STAT_DEF], DEFAULT_STAT_STAGE + 1);
    }
}

SINGLE_BATTLE_TEST("Misty Seed raises the holder's Sp. Defense on Misty Terrain")
{
    enum Ability ability;
    enum Item item;
    PARAMETRIZE { ability = ABILITY_TELEPATHY; item = ITEM_NONE; }
    PARAMETRIZE { ability = ABILITY_TELEPATHY; item = ITEM_MISTY_SEED; }
    PARAMETRIZE { ability = ABILITY_MISTY_SURGE; item = ITEM_NONE; }
    PARAMETRIZE { ability = ABILITY_MISTY_SURGE; item = ITEM_MISTY_SEED; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_MISTY_SEED); }
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_MISTY_SEED); }
        OPPONENT(SPECIES_TAPU_FINI) { Ability(ability); Item(item); }
    } WHEN {
        if (ability == ABILITY_TELEPATHY)
            TURN { MOVE(player, MOVE_MISTY_TERRAIN); }
        TURN { SWITCH(player, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        MESSAGE("The Misty Seed boosted Wobbuffet's Sp. Def!");
        if (item == ITEM_MISTY_SEED) {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
            MESSAGE("The Misty Seed boosted the opposing Tapu Fini's Sp. Def!");
        }
        SWITCH_OUT_MESSAGE("Wobbuffet");
        SEND_IN_MESSAGE("Wobbuffet");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        MESSAGE("The Misty Seed boosted Wobbuffet's Sp. Def!");
    } THEN {
        EXPECT_EQ(player->statStages[STAT_SPDEF], DEFAULT_STAT_STAGE + 1);
    }
}

SINGLE_BATTLE_TEST("Psychic Seed raises the holder's Sp. Defense on Psychic Terrain")
{
    enum Ability ability;
    enum Item item;
    PARAMETRIZE { ability = ABILITY_TELEPATHY; item = ITEM_NONE; }
    PARAMETRIZE { ability = ABILITY_TELEPATHY; item = ITEM_PSYCHIC_SEED; }
    PARAMETRIZE { ability = ABILITY_PSYCHIC_SURGE; item = ITEM_NONE; }
    PARAMETRIZE { ability = ABILITY_PSYCHIC_SURGE; item = ITEM_PSYCHIC_SEED; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_PSYCHIC_SEED); }
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_PSYCHIC_SEED); }
        OPPONENT(SPECIES_TAPU_LELE) { Ability(ability); Item(item); }
    } WHEN {
        if (ability == ABILITY_TELEPATHY)
            TURN { MOVE(player, MOVE_PSYCHIC_TERRAIN); }
        TURN { SWITCH(player, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        MESSAGE("The Psychic Seed boosted Wobbuffet's Sp. Def!");
        if (item == ITEM_PSYCHIC_SEED) {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
            MESSAGE("The Psychic Seed boosted the opposing Tapu Lele's Sp. Def!");
        }
        SWITCH_OUT_MESSAGE("Wobbuffet");
        SEND_IN_MESSAGE("Wobbuffet");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        MESSAGE("The Psychic Seed boosted Wobbuffet's Sp. Def!");
    } THEN {
        EXPECT_EQ(player->statStages[STAT_SPDEF], DEFAULT_STAT_STAGE + 1);
    }
}

SINGLE_BATTLE_TEST("Seeds get consumed in Terrain even if holder is not affected by Terrain")
{
    enum Species species;
    enum Item item;
    enum Ability ability;
    PARAMETRIZE { species = SPECIES_TAPU_KOKO; ability = ABILITY_ELECTRIC_SURGE; item = ITEM_ELECTRIC_SEED; }
    PARAMETRIZE { species = SPECIES_TAPU_BULU; ability = ABILITY_GRASSY_SURGE; item = ITEM_GRASSY_SEED; }
    PARAMETRIZE { species = SPECIES_TAPU_FINI; ability = ABILITY_MISTY_SURGE; item = ITEM_MISTY_SEED; }
    PARAMETRIZE { species = SPECIES_TAPU_LELE; ability = ABILITY_PSYCHIC_SURGE; item = ITEM_PSYCHIC_SEED; }
    GIVEN {
        ASSUME(GetSpeciesType(SPECIES_PIDGEY, 0) == TYPE_FLYING || GetSpeciesType(SPECIES_PIDGEY, 1) == TYPE_FLYING);
        PLAYER(SPECIES_PIDGEY) { Item(item); }
        OPPONENT(species) { Ability(ability); }
    } WHEN {
        TURN {}
    } SCENE {
        ABILITY_POPUP(opponent, ability);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
    } THEN {
        EXPECT_EQ(player->item, ITEM_NONE);
    }
}

SINGLE_BATTLE_TEST("Electric Seed is consumed on Electric Terrain before other abilities change the terrain")
{
    GIVEN {
        PLAYER(SPECIES_TAPU_BULU) { Ability(ABILITY_GRASSY_SURGE); Item(ITEM_ELECTRIC_SEED); Speed(5); }
        OPPONENT(SPECIES_TAPU_KOKO) { Ability(ABILITY_ELECTRIC_SURGE); Item(ITEM_ELECTRIC_SEED); Speed(10); }
    } WHEN {
        TURN {}
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_ELECTRIC_SURGE);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        MESSAGE("The Electric Seed boosted the opposing Tapu Koko's Defense!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        MESSAGE("The Electric Seed boosted Tapu Bulu's Defense!");
        ABILITY_POPUP(player, ABILITY_GRASSY_SURGE);
    }
}

SINGLE_BATTLE_TEST("Electric Seed doesn't activate on existing Electric Terrain before user's ability changes the terrain")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_TAPU_BULU) { Ability(ABILITY_GRASSY_SURGE); Item(ITEM_ELECTRIC_SEED); }
        OPPONENT(SPECIES_TAPU_KOKO) { Ability(ABILITY_ELECTRIC_SURGE); }
    } WHEN {
        TURN { SWITCH(player, 1); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_ELECTRIC_SURGE);
        SWITCH_OUT_MESSAGE("Wobbuffet");
        SEND_IN_MESSAGE("Tapu Bulu");
        NONE_OF {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
            MESSAGE("The Electric Seed boosted Tapu Bulu's Defense!");
        }
        ABILITY_POPUP(player, ABILITY_GRASSY_SURGE);
    }
}
