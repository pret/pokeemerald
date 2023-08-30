#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Full Restore restores a battler's HP and cures any primary status")
{
    u16 status;
    PARAMETRIZE{ status = STATUS1_BURN; }
    PARAMETRIZE{ status = STATUS1_FREEZE; }
    PARAMETRIZE{ status = STATUS1_PARALYSIS; }
    PARAMETRIZE{ status = STATUS1_POISON; }
    PARAMETRIZE{ status = STATUS1_TOXIC_POISON; }
    PARAMETRIZE{ status = STATUS1_SLEEP; }
    GIVEN {
        ASSUME(gItems[ITEM_FULL_RESTORE].battleUsage == EFFECT_ITEM_HEAL_AND_CURE_STATUS);
        PLAYER(SPECIES_WOBBUFFET) { HP(1); MaxHP(300); Status1(status); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN{ USE_ITEM(player, ITEM_FULL_RESTORE, partyIndex: 0); }
    } SCENE {
        MESSAGE("Wobbuffet had its HP restored!");
    } THEN {
        EXPECT_EQ(player->hp, player->maxHP);
        EXPECT_EQ(player->status1, STATUS1_NONE);
    }
}

SINGLE_BATTLE_TEST("Full Restore restores a battler's HP and cures confusion")
{
    GIVEN {
        ASSUME(gItems[ITEM_FULL_RESTORE].battleUsage == EFFECT_ITEM_HEAL_AND_CURE_STATUS);
        PLAYER(SPECIES_WOBBUFFET) { HP(1); MaxHP(300); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN{ MOVE(opponent, MOVE_CONFUSE_RAY); }
        TURN{ USE_ITEM(player, ITEM_FULL_RESTORE, partyIndex: 0); }
        TURN{ MOVE(player, MOVE_TACKLE); }
    } SCENE {
        MESSAGE("Wobbuffet had its HP restored!");
        NONE_OF { MESSAGE("Wobbuffet is confused!"); }
    } THEN {
        EXPECT_EQ(player->hp, player->maxHP);
    }
}
