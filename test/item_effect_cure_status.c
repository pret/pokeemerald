#include "global.h"
#include "test_battle.h"

SINGLE_BATTLE_TEST("Cure Status: Paralyze Heal heals a battler from being paralyzed")
{
    GIVEN {
        ASSUME(gItems[ITEM_PARALYZE_HEAL].battleUsage == EFFECT_ITEM_CURE_STATUS);
        PLAYER(SPECIES_WOBBUFFET) { Status1(STATUS1_PARALYSIS); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { USE_ITEM(player, ITEM_PARALYZE_HEAL, partyIndex: 0); }
    } SCENE {
        MESSAGE("Wobbuffet had its status healed!");
    }
}

SINGLE_BATTLE_TEST("Cure Status: Antidote heals a battler from being poisoned")
{
    GIVEN {
        ASSUME(gItems[ITEM_ANTIDOTE].battleUsage == EFFECT_ITEM_CURE_STATUS);
        PLAYER(SPECIES_WOBBUFFET) { Status1(STATUS1_POISON); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { USE_ITEM(player, ITEM_ANTIDOTE, partyIndex: 0); }
    } SCENE {
        MESSAGE("Wobbuffet had its status healed!");
    }
}

SINGLE_BATTLE_TEST("Cure Status: Antidote heals a battler from being badly poisoned")
{
    GIVEN {
        ASSUME(gItems[ITEM_ANTIDOTE].battleUsage == EFFECT_ITEM_CURE_STATUS);
        PLAYER(SPECIES_WOBBUFFET) { Status1(STATUS1_TOXIC_POISON); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { USE_ITEM(player, ITEM_ANTIDOTE, partyIndex: 0); }
    } SCENE {
        MESSAGE("Wobbuffet had its status healed!");
    }
}

SINGLE_BATTLE_TEST("Cure Status: Awakening heals a battler from being asleep")
{
    GIVEN {
        ASSUME(gItems[ITEM_AWAKENING].battleUsage == EFFECT_ITEM_CURE_STATUS);
        PLAYER(SPECIES_WOBBUFFET) { Status1(STATUS1_SLEEP); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { USE_ITEM(player, ITEM_AWAKENING, partyIndex: 0); }
    } SCENE {
        MESSAGE("Wobbuffet had its status healed!");
    }
}

SINGLE_BATTLE_TEST("Cure Status: Burn Heal heals a battler from being burned")
{
    GIVEN {
        ASSUME(gItems[ITEM_BURN_HEAL].battleUsage == EFFECT_ITEM_CURE_STATUS);
        PLAYER(SPECIES_WOBBUFFET) { Status1(STATUS1_BURN); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { USE_ITEM(player, ITEM_BURN_HEAL, partyIndex: 0); }
    } SCENE {
        MESSAGE("Wobbuffet had its status healed!");
    }
}

SINGLE_BATTLE_TEST("Cure Status: Ice Heal heals a battler from being paralyzed")
{
    GIVEN {
        ASSUME(gItems[ITEM_ICE_HEAL].battleUsage == EFFECT_ITEM_CURE_STATUS);
        PLAYER(SPECIES_WOBBUFFET) { Status1(STATUS1_FREEZE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { USE_ITEM(player, ITEM_ICE_HEAL, partyIndex: 0); }
    } SCENE {
        MESSAGE("Wobbuffet had its status healed!");
    }
}

SINGLE_BATTLE_TEST("Cure Status: Full Heal heals a battler from any primary status")
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
        MESSAGE("Wobbuffet had its status healed!");
    }
}

SINGLE_BATTLE_TEST("Cure Status: Pewter Crunchies heals a battler from any primary status")
{
    u16 status;
    PARAMETRIZE{ status = STATUS1_BURN; }
    PARAMETRIZE{ status = STATUS1_FREEZE; }
    PARAMETRIZE{ status = STATUS1_PARALYSIS; }
    PARAMETRIZE{ status = STATUS1_POISON; }
    PARAMETRIZE{ status = STATUS1_TOXIC_POISON; }
    PARAMETRIZE{ status = STATUS1_SLEEP; }
    GIVEN {
        ASSUME(gItems[ITEM_PEWTER_CRUNCHIES].battleUsage == EFFECT_ITEM_CURE_STATUS);
        PLAYER(SPECIES_WOBBUFFET) { Status1(status); }
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { USE_ITEM(player, ITEM_PEWTER_CRUNCHIES, partyIndex: 0); }
    } SCENE {
        MESSAGE("Wobbuffet had its status healed!");
    }
}

SINGLE_BATTLE_TEST("Cure Status: Lava Cookies heals a battler from any primary status")
{
    u16 status;
    PARAMETRIZE{ status = STATUS1_BURN; }
    PARAMETRIZE{ status = STATUS1_FREEZE; }
    PARAMETRIZE{ status = STATUS1_PARALYSIS; }
    PARAMETRIZE{ status = STATUS1_POISON; }
    PARAMETRIZE{ status = STATUS1_TOXIC_POISON; }
    PARAMETRIZE{ status = STATUS1_SLEEP; }
    GIVEN {
        ASSUME(gItems[ITEM_LAVA_COOKIE].battleUsage == EFFECT_ITEM_CURE_STATUS);
        PLAYER(SPECIES_WOBBUFFET) { Status1(status); }
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { USE_ITEM(player, ITEM_LAVA_COOKIE, partyIndex: 0); }
    } SCENE {
        MESSAGE("Wobbuffet had its status healed!");
    }
}

SINGLE_BATTLE_TEST("Cure Status: Rage Candy Bar heals a battler from any primary status")
{
    u16 status;
    PARAMETRIZE{ status = STATUS1_BURN; }
    PARAMETRIZE{ status = STATUS1_FREEZE; }
    PARAMETRIZE{ status = STATUS1_PARALYSIS; }
    PARAMETRIZE{ status = STATUS1_POISON; }
    PARAMETRIZE{ status = STATUS1_TOXIC_POISON; }
    PARAMETRIZE{ status = STATUS1_SLEEP; }
    GIVEN {
        ASSUME(gItems[ITEM_RAGE_CANDY_BAR].battleUsage == EFFECT_ITEM_CURE_STATUS);
        PLAYER(SPECIES_WOBBUFFET) { Status1(status); }
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { USE_ITEM(player, ITEM_RAGE_CANDY_BAR, partyIndex: 0); }
    } SCENE {
        MESSAGE("Wobbuffet had its status healed!");
    }
}

SINGLE_BATTLE_TEST("Cure Status: Old Gateu heals a battler from any primary status")
{
    u16 status;
    PARAMETRIZE{ status = STATUS1_BURN; }
    PARAMETRIZE{ status = STATUS1_FREEZE; }
    PARAMETRIZE{ status = STATUS1_PARALYSIS; }
    PARAMETRIZE{ status = STATUS1_POISON; }
    PARAMETRIZE{ status = STATUS1_TOXIC_POISON; }
    PARAMETRIZE{ status = STATUS1_SLEEP; }
    GIVEN {
        ASSUME(gItems[ITEM_OLD_GATEAU].battleUsage == EFFECT_ITEM_CURE_STATUS);
        PLAYER(SPECIES_WOBBUFFET) { Status1(status); }
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { USE_ITEM(player, ITEM_OLD_GATEAU, partyIndex: 0); }
    } SCENE {
        MESSAGE("Wobbuffet had its status healed!");
    }
}

SINGLE_BATTLE_TEST("Cure Status: Casteliacone heals a battler from any primary status")
{
    u16 status;
    PARAMETRIZE{ status = STATUS1_BURN; }
    PARAMETRIZE{ status = STATUS1_FREEZE; }
    PARAMETRIZE{ status = STATUS1_PARALYSIS; }
    PARAMETRIZE{ status = STATUS1_POISON; }
    PARAMETRIZE{ status = STATUS1_TOXIC_POISON; }
    PARAMETRIZE{ status = STATUS1_SLEEP; }
    GIVEN {
        ASSUME(gItems[ITEM_CASTELIACONE].battleUsage == EFFECT_ITEM_CURE_STATUS);
        PLAYER(SPECIES_WOBBUFFET) { Status1(status); }
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { USE_ITEM(player, ITEM_CASTELIACONE, partyIndex: 0); }
    } SCENE {
        MESSAGE("Wobbuffet had its status healed!");
    }
}

SINGLE_BATTLE_TEST("Cure Status: Lumiose Galette heals a battler from any primary status")
{
    u16 status;
    PARAMETRIZE{ status = STATUS1_BURN; }
    PARAMETRIZE{ status = STATUS1_FREEZE; }
    PARAMETRIZE{ status = STATUS1_PARALYSIS; }
    PARAMETRIZE{ status = STATUS1_POISON; }
    PARAMETRIZE{ status = STATUS1_TOXIC_POISON; }
    PARAMETRIZE{ status = STATUS1_SLEEP; }
    GIVEN {
        ASSUME(gItems[ITEM_LUMIOSE_GALETTE].battleUsage == EFFECT_ITEM_CURE_STATUS);
        PLAYER(SPECIES_WOBBUFFET) { Status1(status); }
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { USE_ITEM(player, ITEM_LUMIOSE_GALETTE, partyIndex: 0); }
    } SCENE {
        MESSAGE("Wobbuffet had its status healed!");;
    }
}

SINGLE_BATTLE_TEST("Cure Status: Shalour Sable heals a battler from any primary status")
{
    u16 status;
    PARAMETRIZE{ status = STATUS1_BURN; }
    PARAMETRIZE{ status = STATUS1_FREEZE; }
    PARAMETRIZE{ status = STATUS1_PARALYSIS; }
    PARAMETRIZE{ status = STATUS1_POISON; }
    PARAMETRIZE{ status = STATUS1_TOXIC_POISON; }
    PARAMETRIZE{ status = STATUS1_SLEEP; }
    GIVEN {
        ASSUME(gItems[ITEM_SHALOUR_SABLE].battleUsage == EFFECT_ITEM_CURE_STATUS);
        PLAYER(SPECIES_WOBBUFFET) { Status1(status); }
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { USE_ITEM(player, ITEM_SHALOUR_SABLE, partyIndex: 0); }
    } SCENE {
        MESSAGE("Wobbuffet had its status healed!");
    }
}

SINGLE_BATTLE_TEST("Cure Status: Big Malasada heals a battler from any primary status")
{
    u16 status;
    PARAMETRIZE{ status = STATUS1_BURN; }
    PARAMETRIZE{ status = STATUS1_FREEZE; }
    PARAMETRIZE{ status = STATUS1_PARALYSIS; }
    PARAMETRIZE{ status = STATUS1_POISON; }
    PARAMETRIZE{ status = STATUS1_TOXIC_POISON; }
    PARAMETRIZE{ status = STATUS1_SLEEP; }
    GIVEN {
        ASSUME(gItems[ITEM_BIG_MALASADA].battleUsage == EFFECT_ITEM_CURE_STATUS);
        PLAYER(SPECIES_WOBBUFFET) { Status1(status); }
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { USE_ITEM(player, ITEM_BIG_MALASADA, partyIndex: 0); }
    } SCENE {
        MESSAGE("Wobbuffet had its status healed!");
    }
}

SINGLE_BATTLE_TEST("Cure Status: Full Heal and local specialties heal a battler from being confused")
{
    u16 item;
    PARAMETRIZE { item = ITEM_FULL_HEAL; }
    PARAMETRIZE { item = ITEM_PEWTER_CRUNCHIES; }
    PARAMETRIZE { item = ITEM_LAVA_COOKIE; }
    PARAMETRIZE { item = ITEM_RAGE_CANDY_BAR; }
    PARAMETRIZE { item = ITEM_OLD_GATEAU; }
    PARAMETRIZE { item = ITEM_CASTELIACONE; }
    PARAMETRIZE { item = ITEM_LUMIOSE_GALETTE; }
    PARAMETRIZE { item = ITEM_SHALOUR_SABLE; }
    PARAMETRIZE { item = ITEM_BIG_MALASADA; }
    GIVEN {
        ASSUME(gItems[item].battleUsage == EFFECT_ITEM_CURE_STATUS);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_GENGAR);
    } WHEN {
        TURN { MOVE(opponent, MOVE_CONFUSE_RAY); }
        TURN { USE_ITEM(player, item, partyIndex: 0); }
    } SCENE {
        MESSAGE("Wobbuffet had its status healed!");
    }
}
