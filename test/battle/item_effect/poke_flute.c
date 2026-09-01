#include "global.h"
#include "test/battle.h"
#include "constants/item_effects.h"

DOUBLE_BATTLE_TEST("Poke Flute heals all battlers from being asleep")
{
    GIVEN {
        ASSUME(gItemsInfo[ITEM_POKE_FLUTE].battleUsage == EFFECT_ITEM_USE_POKE_FLUTE);
        PLAYER(SPECIES_WOBBUFFET) { Status1(STATUS1_SLEEP); }
        PLAYER(SPECIES_WOBBUFFET) { Status1(STATUS1_SLEEP); }
        OPPONENT(SPECIES_WOBBUFFET) { Status1(STATUS1_SLEEP); }
        OPPONENT(SPECIES_WOBBUFFET) { Status1(STATUS1_SLEEP); }
    } WHEN {
        TURN { USE_ITEM(playerLeft, ITEM_POKE_FLUTE, partyIndex: 0); }
    } SCENE {
        MESSAGE("The Pokémon hearing the flute awoke!");
    } THEN {
        EXPECT_EQ(playerLeft->status1, STATUS1_NONE);
        EXPECT_EQ(playerRight->status1, STATUS1_NONE);
        EXPECT_EQ(opponentLeft->status1, STATUS1_NONE);
        EXPECT_EQ(opponentRight->status1, STATUS1_NONE);
    }
}

DOUBLE_BATTLE_TEST("Poke Flute does not heal battlers with Soundproof from being asleep")
{
    GIVEN {
        ASSUME(gItemsInfo[ITEM_POKE_FLUTE].battleUsage == EFFECT_ITEM_USE_POKE_FLUTE);
        PLAYER(SPECIES_WOBBUFFET) { Status1(STATUS1_SLEEP); }
        PLAYER(SPECIES_EXPLOUD) { Ability(ABILITY_SOUNDPROOF); Status1(STATUS1_SLEEP); }
        OPPONENT(SPECIES_WOBBUFFET) { Status1(STATUS1_SLEEP); }
        OPPONENT(SPECIES_EXPLOUD) { Ability(ABILITY_SOUNDPROOF); Status1(STATUS1_SLEEP); }
    } WHEN {
        TURN { USE_ITEM(playerLeft, ITEM_POKE_FLUTE, partyIndex: 0); }
    } SCENE {
        MESSAGE("The Pokémon hearing the flute awoke!");
    } THEN {
        EXPECT_EQ(playerLeft->status1, STATUS1_NONE);
        EXPECT_NE(playerRight->status1, STATUS1_NONE);
        EXPECT_EQ(opponentLeft->status1, STATUS1_NONE);
        EXPECT_NE(opponentRight->status1, STATUS1_NONE);
    }
}
