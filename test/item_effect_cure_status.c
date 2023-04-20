#include "global.h"
#include "test_battle.h"

SINGLE_BATTLE_TEST("Paralyze Heal heals a Pokemon from being paralyzed")
{
    GIVEN {
        ASSUME(gItems[ITEM_PARALYZE_HEAL].battleUsage == EFFECT_ITEM_CURE_STATUS);
        PLAYER(SPECIES_WOBBUFFET) { Status1(STATUS1_PARALYSIS); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { USE_ITEM(player, ITEM_PARALYZE_HEAL, partyIndex: 0); }
    } SCENE {
        MESSAGE("Paralyze Heal cured Wobbuffet's status!");
    }
}

SINGLE_BATTLE_TEST("Antidote heals a Pokemon from being poisoned")
{
    GIVEN {
        ASSUME(gItems[ITEM_ANTIDOTE].battleUsage == EFFECT_ITEM_CURE_STATUS);
        PLAYER(SPECIES_WOBBUFFET) { Status1(STATUS1_PSN_ANY); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { USE_ITEM(player, ITEM_ANTIDOTE, partyIndex: 0); }
    } SCENE {
        MESSAGE("Antidote cured Wobbuffet's status!");
    }
}

SINGLE_BATTLE_TEST("Awakening heals a Pokemon from being asleep")
{
    GIVEN {
        ASSUME(gItems[ITEM_AWAKENING].battleUsage == EFFECT_ITEM_CURE_STATUS);
        PLAYER(SPECIES_WOBBUFFET) { Status1(STATUS1_SLEEP); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { USE_ITEM(player, ITEM_AWAKENING, partyIndex: 0); }
    } SCENE {
        MESSAGE("Awakening cured Wobbuffet's status!");
    }
}

SINGLE_BATTLE_TEST("Burn Heal heals a Pokemon from being burned")
{
    GIVEN {
        ASSUME(gItems[ITEM_BURN_HEAL].battleUsage == EFFECT_ITEM_CURE_STATUS);
        PLAYER(SPECIES_WOBBUFFET) { Status1(STATUS1_BURN); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { USE_ITEM(player, ITEM_BURN_HEAL, partyIndex: 0); }
    } SCENE {
        MESSAGE("Burn Heal cured Wobbuffet's status!");
    }
}

SINGLE_BATTLE_TEST("Ice Heal heals a Pokemon from being paralyzed")
{
    GIVEN {
        ASSUME(gItems[ITEM_ICE_HEAL].battleUsage == EFFECT_ITEM_CURE_STATUS);
        PLAYER(SPECIES_WOBBUFFET) { Status1(STATUS1_FREEZE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { USE_ITEM(player, ITEM_ICE_HEAL, partyIndex: 0); }
    } SCENE {
        MESSAGE("Ice Heal cured Wobbuffet's status!");
    }
}

SINGLE_BATTLE_TEST("Full Heal heals a Pokemon from any primary status")
{
    u16 status;
    PARAMETRIZE{ status = STATUS1_BURN; }
    PARAMETRIZE{ status = STATUS1_FREEZE; }
    PARAMETRIZE{ status = STATUS1_PARALYSIS; }
    PARAMETRIZE{ status = STATUS1_POISON; }
    PARAMETRIZE{ status = STATUS1_TOXIC_POISON; }
    PARAMETRIZE{ status = STATUS1_SLEEP; }
    GIVEN {
        ASSUME(gItems[ITEM_FULL_HEAL].battleUsage == EFFECT_ITEM_CURE_STATUS);
        PLAYER(SPECIES_WOBBUFFET) { Status1(status); }
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { USE_ITEM(player, ITEM_FULL_HEAL, partyIndex: 0); }
    } SCENE {
        MESSAGE("Full Heal cured Wobbuffet's status!");
    }
}

SINGLE_BATTLE_TEST("Full Heal heals a Pokemon from being confused")
{
    GIVEN {
        ASSUME(gItems[ITEM_FULL_HEAL].battleUsage == EFFECT_ITEM_CURE_STATUS);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_GENGAR);
    } WHEN {
        TURN { MOVE(opponent, MOVE_CONFUSE_RAY); }
        TURN { USE_ITEM(player, ITEM_FULL_HEAL, partyIndex: 0); }
    } SCENE {
        MESSAGE("Full Heal cured Wobbuffet's status!");
    }
}
