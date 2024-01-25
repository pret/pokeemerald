#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Ether restores the PP of one of a battler's moves by 10 ")
{
    GIVEN {
        ASSUME(gItems[ITEM_ETHER].battleUsage == EFFECT_ITEM_RESTORE_PP);
        ASSUME(gItems[ITEM_ETHER].type == ITEM_USE_PARTY_MENU_MOVES);
        PLAYER(SPECIES_WOBBUFFET) { MovesWithPP({MOVE_TACKLE, 0}, {MOVE_CONFUSION, 20}); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { USE_ITEM(player, ITEM_ETHER, partyIndex: 0, move: MOVE_TACKLE); }
    } THEN {
        EXPECT_EQ(player->pp[0], 10);
        EXPECT_EQ(player->pp[1], 20);
    }
}

SINGLE_BATTLE_TEST("Max Ether restores the PP of one of a battler's moves fully")
{
    GIVEN {
        ASSUME(gItems[ITEM_MAX_ETHER].battleUsage == EFFECT_ITEM_RESTORE_PP);
        ASSUME(gItems[ITEM_MAX_ETHER].type == ITEM_USE_PARTY_MENU_MOVES);
        PLAYER(SPECIES_WOBBUFFET) { MovesWithPP({MOVE_TACKLE, 0}, {MOVE_CONFUSION, 20}); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { USE_ITEM(player, ITEM_MAX_ETHER, partyIndex: 0, move: MOVE_TACKLE); }
    } THEN {
        EXPECT_EQ(player->pp[0], 35);
        EXPECT_EQ(player->pp[1], 20);
    }
}

SINGLE_BATTLE_TEST("Elixir restores the PP of all of a battler's moves by 10")
{
    GIVEN {
        ASSUME(gItems[ITEM_ELIXIR].battleUsage == EFFECT_ITEM_RESTORE_PP);
        ASSUME(gItems[ITEM_ELIXIR].type == ITEM_USE_PARTY_MENU);
        PLAYER(SPECIES_WOBBUFFET) { MovesWithPP({MOVE_TACKLE, 0}, {MOVE_CONFUSION, 0}, {MOVE_SCRATCH, 0}, {MOVE_GROWL, 0}); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { USE_ITEM(player, ITEM_ELIXIR, partyIndex: 0); }
    } THEN {
        EXPECT_EQ(player->pp[0], 10);
        EXPECT_EQ(player->pp[1], 10);
        EXPECT_EQ(player->pp[2], 10);
        EXPECT_EQ(player->pp[3], 10);
    }
}

SINGLE_BATTLE_TEST("Max Elixir restores the PP of all of a battler's moves fully")
{
    GIVEN {
        ASSUME(gItems[ITEM_MAX_ELIXIR].battleUsage == EFFECT_ITEM_RESTORE_PP);
        ASSUME(gItems[ITEM_MAX_ELIXIR].type == ITEM_USE_PARTY_MENU);
        PLAYER(SPECIES_WOBBUFFET) { MovesWithPP({MOVE_TACKLE, 0}, {MOVE_CONFUSION, 0}, {MOVE_SCRATCH, 0}, {MOVE_GROWL, 0}); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { USE_ITEM(player, ITEM_MAX_ELIXIR, partyIndex: 0); }
    } THEN {
        EXPECT_EQ(player->pp[0], 35);
        EXPECT_EQ(player->pp[1], 25);
        EXPECT_EQ(player->pp[2], 35);
        EXPECT_EQ(player->pp[3], 40);
    }
}

TO_DO_BATTLE_TEST("Ether won't work if the selected move has all its PP")
