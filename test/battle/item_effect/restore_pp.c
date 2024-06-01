#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Ether restores the PP of one of a battler's moves by 10 ")
{
    GIVEN {
        ASSUME(gItemsInfo[ITEM_ETHER].battleUsage == EFFECT_ITEM_RESTORE_PP);
        ASSUME(gItemsInfo[ITEM_ETHER].type == ITEM_USE_PARTY_MENU_MOVES);
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
        ASSUME(gItemsInfo[ITEM_MAX_ETHER].battleUsage == EFFECT_ITEM_RESTORE_PP);
        ASSUME(gItemsInfo[ITEM_MAX_ETHER].type == ITEM_USE_PARTY_MENU_MOVES);
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
        ASSUME(gItemsInfo[ITEM_ELIXIR].battleUsage == EFFECT_ITEM_RESTORE_PP);
        ASSUME(gItemsInfo[ITEM_ELIXIR].type == ITEM_USE_PARTY_MENU);
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
        ASSUME(gItemsInfo[ITEM_MAX_ELIXIR].battleUsage == EFFECT_ITEM_RESTORE_PP);
        ASSUME(gItemsInfo[ITEM_MAX_ELIXIR].type == ITEM_USE_PARTY_MENU);
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

TO_DO_BATTLE_TEST("Elixir can be used if at least one move is missing PP in any slot") // The test system can't currently test this, in a test the item is used without running useability checks
/*
{
    u8 move1PP;
    u8 move2PP;
    u8 move3PP;
    u8 move4PP;
    PARAMETRIZE { move1PP = 30; move2PP = 30; move3PP = 20; move4PP = 10; }
    PARAMETRIZE { move1PP = 40; move2PP = 20; move3PP = 20; move4PP = 10; }
    PARAMETRIZE { move1PP = 40; move2PP = 30; move3PP = 10; move4PP = 10; }
    PARAMETRIZE { move1PP = 40; move2PP = 30; move3PP = 20; move4PP = 0; }
    GIVEN {
        ASSUME(gItemsInfo[ITEM_ELIXIR].battleUsage == EFFECT_ITEM_RESTORE_PP);
        ASSUME(gItemsInfo[ITEM_ELIXIR].type == ITEM_USE_PARTY_MENU);
        PLAYER(SPECIES_WOBBUFFET) { MovesWithPP({MOVE_MEDITATE, move1PP}, {MOVE_AGILITY, move2PP}, {MOVE_PSYBEAM, move3PP}, {MOVE_TRICK, move4PP}); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { USE_ITEM(player, ITEM_ELIXIR, partyIndex: 0); }
    } THEN {
        EXPECT_EQ(player->pp[0], 40);
        EXPECT_EQ(player->pp[1], 30);
        EXPECT_EQ(player->pp[2], 20);
        EXPECT_EQ(player->pp[3], 10);
    }
}
*/
