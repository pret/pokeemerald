#include "global.h"
#include "test_battle.h"

SINGLE_BATTLE_TEST("Ether restores the PP of one of a battler's moves")
{
    GIVEN {
        ASSUME(gItems[ITEM_ETHER].battleUsage == EFFECT_ITEM_RESTORE_PP);
        ASSUME(gItems[ITEM_ETHER].type == ITEM_USE_PARTY_MENU_MOVES);
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_TACKLE, MOVE_CONFUSION); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_TACKLE); }
        TURN { MOVE(player, MOVE_CONFUSION); }
        TURN { USE_ITEM(player, ITEM_ETHER, partyIndex: 0, move: MOVE_TACKLE); }
    } FINALLY {
        EXPECT_EQ(player->pp[0], 35);
        EXPECT_EQ(player->pp[1], 24);
    }
}
