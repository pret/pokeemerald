#include "global.h"
#include "test_battle.h"

#define MAX_HP 200

SINGLE_BATTLE_TEST("Revive restores a fainted battler's HP to half")
{
    GIVEN {
        ASSUME(gItems[ITEM_REVIVE].battleUsage == EFFECT_ITEM_REVIVE);
        PLAYER(SPECIES_WYNAUT) { HP(1); MaxHP(MAX_HP); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_TACKLE); SEND_OUT(player, 1); }
        TURN { USE_ITEM(player, ITEM_REVIVE, partyIndex: 0); }
        TURN { SWITCH(player, 0); }
    } SCENE {
        MESSAGE("Wynaut had its HP restored!");
    } THEN {
        EXPECT_EQ(player->hp, MAX_HP/2);
    }
}

SINGLE_BATTLE_TEST("Max Revive restores a fainted battler's HP fully")
{
    GIVEN {
        ASSUME(gItems[ITEM_MAX_REVIVE].battleUsage == EFFECT_ITEM_REVIVE);
        PLAYER(SPECIES_WYNAUT) { HP(1); MaxHP(MAX_HP); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_TACKLE); SEND_OUT(player, 1); }
        TURN { USE_ITEM(player, ITEM_MAX_REVIVE, partyIndex: 0); }
        TURN { SWITCH(player, 0); }
    } SCENE {
        MESSAGE("Wynaut had its HP restored!");
    } THEN {
        EXPECT_EQ(player->hp, MAX_HP);
    }
}

SINGLE_BATTLE_TEST("Revival Herb restores a fainted battler's HP fully")
{
    GIVEN {
        ASSUME(gItems[ITEM_REVIVAL_HERB].battleUsage == EFFECT_ITEM_REVIVE);
        PLAYER(SPECIES_WYNAUT) { HP(1); MaxHP(MAX_HP); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_TACKLE); SEND_OUT(player, 1); }
        TURN { USE_ITEM(player, ITEM_REVIVAL_HERB, partyIndex: 0); }
        TURN { SWITCH(player, 0); }
    } SCENE {
        MESSAGE("Wynaut had its HP restored!");
    } THEN {
        EXPECT_EQ(player->hp, MAX_HP);
    }
}

SINGLE_BATTLE_TEST("Max Honey restores a fainted battler's HP fully")
{
    GIVEN {
        ASSUME(gItems[ITEM_MAX_HONEY].battleUsage == EFFECT_ITEM_REVIVE);
        PLAYER(SPECIES_WYNAUT) { HP(1); MaxHP(MAX_HP); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_TACKLE); SEND_OUT(player, 1); }
        TURN { USE_ITEM(player, ITEM_MAX_HONEY, partyIndex: 0); }
        TURN { SWITCH(player, 0); }
    } SCENE {
        MESSAGE("Wynaut had its HP restored!");
    } THEN {
        EXPECT_EQ(player->hp, MAX_HP);
    }
}

#undef MAX_HP
