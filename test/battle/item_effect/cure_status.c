#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Paralyze Heal heals a battler from being paralyzed")
{
    GIVEN {
        ASSUME(gItemsInfo[ITEM_PARALYZE_HEAL].battleUsage == EFFECT_ITEM_CURE_STATUS);
        PLAYER(SPECIES_WOBBUFFET) { Status1(STATUS1_PARALYSIS); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { USE_ITEM(player, ITEM_PARALYZE_HEAL, partyIndex: 0); }
    } SCENE {
        MESSAGE("Wobbuffet was cured of paralysis!");
    } THEN {
        EXPECT_EQ(player->status1, STATUS1_NONE);
    }
}

SINGLE_BATTLE_TEST("Antidote heals a battler from being poisoned")
{
    GIVEN {
        ASSUME(gItemsInfo[ITEM_ANTIDOTE].battleUsage == EFFECT_ITEM_CURE_STATUS);
        PLAYER(SPECIES_WOBBUFFET) { Status1(STATUS1_POISON); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { USE_ITEM(player, ITEM_ANTIDOTE, partyIndex: 0); }
    } SCENE {
        MESSAGE("Wobbuffet was cured of its poisoning!");
    } THEN {
        EXPECT_EQ(player->status1, STATUS1_NONE);
    }
}

DOUBLE_BATTLE_TEST("Antidote heals a battler from being poisoned (doubles)")
{
    u32 index;
    struct BattlePokemon *user = NULL;
    struct BattlePokemon *target = NULL;
    PARAMETRIZE { index = 0; user = playerRight; target = playerLeft; }
    PARAMETRIZE { index = 1; user = playerLeft; target = playerRight; }
    PARAMETRIZE { index = 0; user = playerLeft; target = playerLeft; }
    PARAMETRIZE { index = 1; user = playerRight; target = playerRight; }

    GIVEN {
        ASSUME(gItemsInfo[ITEM_ANTIDOTE].battleUsage == EFFECT_ITEM_CURE_STATUS);
        PLAYER(SPECIES_WOBBUFFET) { Status1(STATUS1_POISON); }
        PLAYER(SPECIES_WYNAUT) { }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { USE_ITEM(user, ITEM_ANTIDOTE, partyIndex: index); }
    } THEN {
        EXPECT_EQ(target->status1, STATUS1_NONE);
    }
}

SINGLE_BATTLE_TEST("Antidote heals a battler from being badly poisoned")
{
    GIVEN {
        ASSUME(gItemsInfo[ITEM_ANTIDOTE].battleUsage == EFFECT_ITEM_CURE_STATUS);
        PLAYER(SPECIES_WOBBUFFET) { Status1(STATUS1_TOXIC_POISON); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { USE_ITEM(player, ITEM_ANTIDOTE, partyIndex: 0); }
    } SCENE {
        MESSAGE("Wobbuffet was cured of its poisoning!");
    } THEN {
        EXPECT_EQ(player->status1, STATUS1_NONE);
    }
}

SINGLE_BATTLE_TEST("Antidote resets Toxic Counter")
{
    GIVEN {
        ASSUME(gItemsInfo[ITEM_ANTIDOTE].battleUsage == EFFECT_ITEM_CURE_STATUS);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_TOXIC); }
        TURN {}
        TURN { USE_ITEM(player, ITEM_ANTIDOTE, partyIndex: 0); }
    } SCENE {
        MESSAGE("The opposing Wobbuffet used Toxic!");
        MESSAGE("Wobbuffet was cured of its poisoning!");
    } THEN {
        EXPECT_EQ(player->status1, STATUS1_NONE);
    }
}

SINGLE_BATTLE_TEST("Awakening heals a battler from being asleep")
{
    GIVEN {
        ASSUME(gItemsInfo[ITEM_AWAKENING].battleUsage == EFFECT_ITEM_CURE_STATUS);
        PLAYER(SPECIES_WOBBUFFET) { Status1(STATUS1_SLEEP); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { USE_ITEM(player, ITEM_AWAKENING, partyIndex: 0); }
    } SCENE {
        MESSAGE("Wobbuffet woke up!");
    } THEN {
        EXPECT_EQ(player->status1, STATUS1_NONE);
    }
}

SINGLE_BATTLE_TEST("Burn Heal heals a battler from being burned")
{
    GIVEN {
        ASSUME(gItemsInfo[ITEM_BURN_HEAL].battleUsage == EFFECT_ITEM_CURE_STATUS);
        PLAYER(SPECIES_WOBBUFFET) { Status1(STATUS1_BURN); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { USE_ITEM(player, ITEM_BURN_HEAL, partyIndex: 0); }
    } SCENE {
        MESSAGE("Wobbuffet's burn was cured!");
    } THEN {
        EXPECT_EQ(player->status1, STATUS1_NONE);
    }
}

SINGLE_BATTLE_TEST("Ice Heal heals a battler from being frozen")
{
    GIVEN {
        ASSUME(gItemsInfo[ITEM_ICE_HEAL].battleUsage == EFFECT_ITEM_CURE_STATUS);
        PLAYER(SPECIES_WOBBUFFET) { Status1(STATUS1_FREEZE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { USE_ITEM(player, ITEM_ICE_HEAL, partyIndex: 0); }
    } SCENE {
        MESSAGE("Wobbuffet thawed out!");
    } THEN {
        EXPECT_EQ(player->status1, STATUS1_NONE);
    }
}

SINGLE_BATTLE_TEST("Ice Heal heals a battler from frostbite")
{
    GIVEN {
        ASSUME(gItemsInfo[ITEM_ICE_HEAL].battleUsage == EFFECT_ITEM_CURE_STATUS);
        PLAYER(SPECIES_WOBBUFFET) { Status1(STATUS1_FROSTBITE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { USE_ITEM(player, ITEM_ICE_HEAL, partyIndex: 0); }
    } SCENE {
        MESSAGE("Wobbuffet's frostbite was cured!");
    } THEN {
        EXPECT_EQ(player->status1, STATUS1_NONE);
    }
}

SINGLE_BATTLE_TEST("Full Heal heals a battler from any primary status")
{
    u16 status;
    PARAMETRIZE { status = STATUS1_SLEEP; }
    PARAMETRIZE { status = STATUS1_POISON; }
    PARAMETRIZE { status = STATUS1_BURN; }
    PARAMETRIZE { status = STATUS1_FREEZE; }
    PARAMETRIZE { status = STATUS1_PARALYSIS; }
    PARAMETRIZE { status = STATUS1_TOXIC_POISON; }
    PARAMETRIZE { status = STATUS1_FROSTBITE; }
    GIVEN {
        ASSUME(gItemsInfo[ITEM_FULL_HEAL].battleUsage == EFFECT_ITEM_CURE_STATUS);
        PLAYER(SPECIES_WOBBUFFET) { Status1(status); }
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { USE_ITEM(player, ITEM_FULL_HEAL, partyIndex: 0); }
    } SCENE {
        switch (status)
        {
            case STATUS1_SLEEP:
                MESSAGE("Wobbuffet woke up!");
                break;
            case STATUS1_POISON:
                MESSAGE("Wobbuffet was cured of its poisoning!");
                break;
            case STATUS1_BURN:
                MESSAGE("Wobbuffet's burn was cured!");
                break;
            case STATUS1_FREEZE:
                MESSAGE("Wobbuffet thawed out!");
                break;
            case STATUS1_PARALYSIS:
                MESSAGE("Wobbuffet was cured of paralysis!");
                break;
            case STATUS1_TOXIC_POISON:
                MESSAGE("Wobbuffet was cured of its poisoning!");
                break;
            case STATUS1_FROSTBITE:
                MESSAGE("Wobbuffet's frostbite was cured!");
                break;
        }
    } THEN {
        EXPECT_EQ(player->status1, STATUS1_NONE);
    }
}

DOUBLE_BATTLE_TEST("Full Heal heals a battler from any primary status (doubles)")
{
    u32 statusParameters[7] =
    {
        STATUS1_SLEEP,
        STATUS1_POISON,
        STATUS1_BURN,
        STATUS1_FREEZE,
        STATUS1_PARALYSIS,
        STATUS1_TOXIC_POISON,
        STATUS1_FROSTBITE
    };

    u16 status = 0;
    u32 index = 0;
    struct BattlePokemon *user = NULL;
    struct BattlePokemon *target = NULL;
    for (u32 j = 0; j < 7; j++)
    {
        PARAMETRIZE { status = statusParameters[j]; user = playerRight; target = playerLeft; index = 0; }
        PARAMETRIZE { status = statusParameters[j]; user = playerLeft; target = playerRight; index = 1; }
        PARAMETRIZE { status = statusParameters[j]; user = playerLeft; target = playerLeft; index = 0; }
        PARAMETRIZE { status = statusParameters[j]; user = playerRight; target = playerRight; index = 1; }
    }
    GIVEN {
        ASSUME(gItemsInfo[ITEM_FULL_HEAL].battleUsage == EFFECT_ITEM_CURE_STATUS);
        PLAYER(SPECIES_WOBBUFFET) { Status1(status); }
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { USE_ITEM(user, ITEM_FULL_HEAL, partyIndex: index); }
    } THEN {
        EXPECT_EQ(target->status1, STATUS1_NONE);
    }
}

SINGLE_BATTLE_TEST("Heal Powder heals a battler from any primary status")
{
    u16 status;
    PARAMETRIZE { status = STATUS1_SLEEP; }
    PARAMETRIZE { status = STATUS1_POISON; }
    PARAMETRIZE { status = STATUS1_BURN; }
    PARAMETRIZE { status = STATUS1_FREEZE; }
    PARAMETRIZE { status = STATUS1_PARALYSIS; }
    PARAMETRIZE { status = STATUS1_TOXIC_POISON; }
    PARAMETRIZE { status = STATUS1_FROSTBITE; }
    GIVEN {
        ASSUME(gItemsInfo[ITEM_HEAL_POWDER].battleUsage == EFFECT_ITEM_CURE_STATUS);
        PLAYER(SPECIES_WOBBUFFET) { Status1(status); }
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { USE_ITEM(player, ITEM_HEAL_POWDER, partyIndex: 0); }
    } SCENE {
        switch (status)
        {
            case STATUS1_SLEEP:
                MESSAGE("Wobbuffet woke up!");
                break;
            case STATUS1_POISON:
                MESSAGE("Wobbuffet was cured of its poisoning!");
                break;
            case STATUS1_BURN:
                MESSAGE("Wobbuffet's burn was cured!");
                break;
            case STATUS1_FREEZE:
                MESSAGE("Wobbuffet thawed out!");
                break;
            case STATUS1_PARALYSIS:
                MESSAGE("Wobbuffet was cured of paralysis!");
                break;
            case STATUS1_TOXIC_POISON:
                MESSAGE("Wobbuffet was cured of its poisoning!");
                break;
            case STATUS1_FROSTBITE:
                MESSAGE("Wobbuffet's frostbite was cured!");
                break;
        }
    } THEN {
        EXPECT_EQ(player->status1, STATUS1_NONE);
    }
}

DOUBLE_BATTLE_TEST("Heal Powder heals a battler from any primary status (doubles)")
{
    u32 statusParameters[7] =
    {
        STATUS1_SLEEP,
        STATUS1_POISON,
        STATUS1_BURN,
        STATUS1_FREEZE,
        STATUS1_PARALYSIS,
        STATUS1_TOXIC_POISON,
        STATUS1_FROSTBITE
    };

    u16 status = 0;
    u32 index = 0;
    struct BattlePokemon *user = NULL;
    struct BattlePokemon *target = NULL;
    for (u32 j = 0; j < 7; j++)
    {
        PARAMETRIZE { status = statusParameters[j]; user = playerRight; target = playerLeft; index = 0; }
        PARAMETRIZE { status = statusParameters[j]; user = playerLeft; target = playerRight; index = 1; }
        PARAMETRIZE { status = statusParameters[j]; user = playerLeft; target = playerLeft; index = 0; }
        PARAMETRIZE { status = statusParameters[j]; user = playerRight; target = playerRight; index = 1; }
    }
    GIVEN {
        ASSUME(gItemsInfo[ITEM_HEAL_POWDER].battleUsage == EFFECT_ITEM_CURE_STATUS);
        PLAYER(SPECIES_WOBBUFFET) { Status1(status); }
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { USE_ITEM(user, ITEM_HEAL_POWDER, partyIndex: index); }
    } THEN {
        EXPECT_EQ(target->status1, STATUS1_NONE);
    }
}

SINGLE_BATTLE_TEST("Pewter Crunchies heals a battler from any primary status")
{
    u16 status;
    PARAMETRIZE { status = STATUS1_SLEEP; }
    PARAMETRIZE { status = STATUS1_POISON; }
    PARAMETRIZE { status = STATUS1_BURN; }
    PARAMETRIZE { status = STATUS1_FREEZE; }
    PARAMETRIZE { status = STATUS1_PARALYSIS; }
    PARAMETRIZE { status = STATUS1_TOXIC_POISON; }
    PARAMETRIZE { status = STATUS1_FROSTBITE; }
    GIVEN {
        ASSUME(gItemsInfo[ITEM_PEWTER_CRUNCHIES].battleUsage == EFFECT_ITEM_CURE_STATUS);
        PLAYER(SPECIES_WOBBUFFET) { Status1(status); }
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { USE_ITEM(player, ITEM_PEWTER_CRUNCHIES, partyIndex: 0); }
    } SCENE {
        switch (status)
        {
            case STATUS1_SLEEP:
                MESSAGE("Wobbuffet woke up!");
                break;
            case STATUS1_POISON:
                MESSAGE("Wobbuffet was cured of its poisoning!");
                break;
            case STATUS1_BURN:
                MESSAGE("Wobbuffet's burn was cured!");
                break;
            case STATUS1_FREEZE:
                MESSAGE("Wobbuffet thawed out!");
                break;
            case STATUS1_PARALYSIS:
                MESSAGE("Wobbuffet was cured of paralysis!");
                break;
            case STATUS1_TOXIC_POISON:
                MESSAGE("Wobbuffet was cured of its poisoning!");
                break;
            case STATUS1_FROSTBITE:
                MESSAGE("Wobbuffet's frostbite was cured!");
                break;
        }
    } THEN {
        EXPECT_EQ(player->status1, STATUS1_NONE);
    }
}

SINGLE_BATTLE_TEST("Lava Cookies heals a battler from any primary status")
{
    u16 status;
    PARAMETRIZE { status = STATUS1_SLEEP; }
    PARAMETRIZE { status = STATUS1_POISON; }
    PARAMETRIZE { status = STATUS1_BURN; }
    PARAMETRIZE { status = STATUS1_FREEZE; }
    PARAMETRIZE { status = STATUS1_PARALYSIS; }
    PARAMETRIZE { status = STATUS1_TOXIC_POISON; }
    PARAMETRIZE { status = STATUS1_FROSTBITE; }
    GIVEN {
        ASSUME(gItemsInfo[ITEM_LAVA_COOKIE].battleUsage == EFFECT_ITEM_CURE_STATUS);
        PLAYER(SPECIES_WOBBUFFET) { Status1(status); }
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { USE_ITEM(player, ITEM_LAVA_COOKIE, partyIndex: 0); }
    } SCENE {
        switch (status)
        {
            case STATUS1_SLEEP:
                MESSAGE("Wobbuffet woke up!");
                break;
            case STATUS1_POISON:
                MESSAGE("Wobbuffet was cured of its poisoning!");
                break;
            case STATUS1_BURN:
                MESSAGE("Wobbuffet's burn was cured!");
                break;
            case STATUS1_FREEZE:
                MESSAGE("Wobbuffet thawed out!");
                break;
            case STATUS1_PARALYSIS:
                MESSAGE("Wobbuffet was cured of paralysis!");
                break;
            case STATUS1_TOXIC_POISON:
                MESSAGE("Wobbuffet was cured of its poisoning!");
                break;
            case STATUS1_FROSTBITE:
                MESSAGE("Wobbuffet's frostbite was cured!");
                break;
        }
    } THEN {
        EXPECT_EQ(player->status1, STATUS1_NONE);
    }
}

SINGLE_BATTLE_TEST("Rage Candy Bar heals a battler from any primary status")
{
    u16 status;
    PARAMETRIZE { status = STATUS1_SLEEP; }
    PARAMETRIZE { status = STATUS1_POISON; }
    PARAMETRIZE { status = STATUS1_BURN; }
    PARAMETRIZE { status = STATUS1_FREEZE; }
    PARAMETRIZE { status = STATUS1_PARALYSIS; }
    PARAMETRIZE { status = STATUS1_TOXIC_POISON; }
    PARAMETRIZE { status = STATUS1_FROSTBITE; }
    GIVEN {
        ASSUME(gItemsInfo[ITEM_RAGE_CANDY_BAR].battleUsage == EFFECT_ITEM_CURE_STATUS);
        PLAYER(SPECIES_WOBBUFFET) { Status1(status); }
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { USE_ITEM(player, ITEM_RAGE_CANDY_BAR, partyIndex: 0); }
    } SCENE {
        switch (status)
        {
            case STATUS1_SLEEP:
                MESSAGE("Wobbuffet woke up!");
                break;
            case STATUS1_POISON:
                MESSAGE("Wobbuffet was cured of its poisoning!");
                break;
            case STATUS1_BURN:
                MESSAGE("Wobbuffet's burn was cured!");
                break;
            case STATUS1_FREEZE:
                MESSAGE("Wobbuffet thawed out!");
                break;
            case STATUS1_PARALYSIS:
                MESSAGE("Wobbuffet was cured of paralysis!");
                break;
            case STATUS1_TOXIC_POISON:
                MESSAGE("Wobbuffet was cured of its poisoning!");
                break;
            case STATUS1_FROSTBITE:
                MESSAGE("Wobbuffet's frostbite was cured!");
                break;
        }
    } THEN {
        EXPECT_EQ(player->status1, STATUS1_NONE);
    }
}

SINGLE_BATTLE_TEST("Old Gateau heals a battler from any primary status")
{
    u16 status;
    PARAMETRIZE { status = STATUS1_SLEEP; }
    PARAMETRIZE { status = STATUS1_POISON; }
    PARAMETRIZE { status = STATUS1_BURN; }
    PARAMETRIZE { status = STATUS1_FREEZE; }
    PARAMETRIZE { status = STATUS1_PARALYSIS; }
    PARAMETRIZE { status = STATUS1_TOXIC_POISON; }
    PARAMETRIZE { status = STATUS1_FROSTBITE; }
    GIVEN {
        ASSUME(gItemsInfo[ITEM_OLD_GATEAU].battleUsage == EFFECT_ITEM_CURE_STATUS);
        PLAYER(SPECIES_WOBBUFFET) { Status1(status); }
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { USE_ITEM(player, ITEM_OLD_GATEAU, partyIndex: 0); }
    } SCENE {
        switch (status)
        {
            case STATUS1_SLEEP:
                MESSAGE("Wobbuffet woke up!");
                break;
            case STATUS1_POISON:
                MESSAGE("Wobbuffet was cured of its poisoning!");
                break;
            case STATUS1_BURN:
                MESSAGE("Wobbuffet's burn was cured!");
                break;
            case STATUS1_FREEZE:
                MESSAGE("Wobbuffet thawed out!");
                break;
            case STATUS1_PARALYSIS:
                MESSAGE("Wobbuffet was cured of paralysis!");
                break;
            case STATUS1_TOXIC_POISON:
                MESSAGE("Wobbuffet was cured of its poisoning!");
                break;
            case STATUS1_FROSTBITE:
                MESSAGE("Wobbuffet's frostbite was cured!");
                break;
        }
    } THEN {
        EXPECT_EQ(player->status1, STATUS1_NONE);
    }
}

SINGLE_BATTLE_TEST("Casteliacone heals a battler from any primary status")
{
    u16 status;
    PARAMETRIZE { status = STATUS1_SLEEP; }
    PARAMETRIZE { status = STATUS1_POISON; }
    PARAMETRIZE { status = STATUS1_BURN; }
    PARAMETRIZE { status = STATUS1_FREEZE; }
    PARAMETRIZE { status = STATUS1_PARALYSIS; }
    PARAMETRIZE { status = STATUS1_TOXIC_POISON; }
    PARAMETRIZE { status = STATUS1_FROSTBITE; }
    GIVEN {
        ASSUME(gItemsInfo[ITEM_CASTELIACONE].battleUsage == EFFECT_ITEM_CURE_STATUS);
        PLAYER(SPECIES_WOBBUFFET) { Status1(status); }
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { USE_ITEM(player, ITEM_CASTELIACONE, partyIndex: 0); }
    } SCENE {
        switch (status)
        {
            case STATUS1_SLEEP:
                MESSAGE("Wobbuffet woke up!");
                break;
            case STATUS1_POISON:
                MESSAGE("Wobbuffet was cured of its poisoning!");
                break;
            case STATUS1_BURN:
                MESSAGE("Wobbuffet's burn was cured!");
                break;
            case STATUS1_FREEZE:
                MESSAGE("Wobbuffet thawed out!");
                break;
            case STATUS1_PARALYSIS:
                MESSAGE("Wobbuffet was cured of paralysis!");
                break;
            case STATUS1_TOXIC_POISON:
                MESSAGE("Wobbuffet was cured of its poisoning!");
                break;
            case STATUS1_FROSTBITE:
                MESSAGE("Wobbuffet's frostbite was cured!");
                break;
        }
    } THEN {
        EXPECT_EQ(player->status1, STATUS1_NONE);
    }
}

SINGLE_BATTLE_TEST("Lumiose Galette heals a battler from any primary status")
{
    u16 status;
    PARAMETRIZE { status = STATUS1_SLEEP; }
    PARAMETRIZE { status = STATUS1_POISON; }
    PARAMETRIZE { status = STATUS1_BURN; }
    PARAMETRIZE { status = STATUS1_FREEZE; }
    PARAMETRIZE { status = STATUS1_PARALYSIS; }
    PARAMETRIZE { status = STATUS1_TOXIC_POISON; }
    PARAMETRIZE { status = STATUS1_FROSTBITE; }
    GIVEN {
        ASSUME(gItemsInfo[ITEM_LUMIOSE_GALETTE].battleUsage == EFFECT_ITEM_CURE_STATUS);
        PLAYER(SPECIES_WOBBUFFET) { Status1(status); }
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { USE_ITEM(player, ITEM_LUMIOSE_GALETTE, partyIndex: 0); }
    } SCENE {
        switch (status)
        {
            case STATUS1_SLEEP:
                MESSAGE("Wobbuffet woke up!");
                break;
            case STATUS1_POISON:
                MESSAGE("Wobbuffet was cured of its poisoning!");
                break;
            case STATUS1_BURN:
                MESSAGE("Wobbuffet's burn was cured!");
                break;
            case STATUS1_FREEZE:
                MESSAGE("Wobbuffet thawed out!");
                break;
            case STATUS1_PARALYSIS:
                MESSAGE("Wobbuffet was cured of paralysis!");
                break;
            case STATUS1_TOXIC_POISON:
                MESSAGE("Wobbuffet was cured of its poisoning!");
                break;
            case STATUS1_FROSTBITE:
                MESSAGE("Wobbuffet's frostbite was cured!");
                break;
        }
    } THEN {
        EXPECT_EQ(player->status1, STATUS1_NONE);
    }
}

SINGLE_BATTLE_TEST("Shalour Sable heals a battler from any primary status")
{
    u16 status;
    PARAMETRIZE { status = STATUS1_SLEEP; }
    PARAMETRIZE { status = STATUS1_POISON; }
    PARAMETRIZE { status = STATUS1_BURN; }
    PARAMETRIZE { status = STATUS1_FREEZE; }
    PARAMETRIZE { status = STATUS1_PARALYSIS; }
    PARAMETRIZE { status = STATUS1_TOXIC_POISON; }
    PARAMETRIZE { status = STATUS1_FROSTBITE; }
    GIVEN {
        ASSUME(gItemsInfo[ITEM_SHALOUR_SABLE].battleUsage == EFFECT_ITEM_CURE_STATUS);
        PLAYER(SPECIES_WOBBUFFET) { Status1(status); }
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { USE_ITEM(player, ITEM_SHALOUR_SABLE, partyIndex: 0); }
    } SCENE {
        switch (status)
        {
            case STATUS1_SLEEP:
                MESSAGE("Wobbuffet woke up!");
                break;
            case STATUS1_POISON:
                MESSAGE("Wobbuffet was cured of its poisoning!");
                break;
            case STATUS1_BURN:
                MESSAGE("Wobbuffet's burn was cured!");
                break;
            case STATUS1_FREEZE:
                MESSAGE("Wobbuffet thawed out!");
                break;
            case STATUS1_PARALYSIS:
                MESSAGE("Wobbuffet was cured of paralysis!");
                break;
            case STATUS1_TOXIC_POISON:
                MESSAGE("Wobbuffet was cured of its poisoning!");
                break;
            case STATUS1_FROSTBITE:
                MESSAGE("Wobbuffet's frostbite was cured!");
                break;
        }
    } THEN {
        EXPECT_EQ(player->status1, STATUS1_NONE);
    }
}

SINGLE_BATTLE_TEST("Big Malasada heals a battler from any primary status")
{
    u16 status;
    PARAMETRIZE { status = STATUS1_SLEEP; }
    PARAMETRIZE { status = STATUS1_POISON; }
    PARAMETRIZE { status = STATUS1_BURN; }
    PARAMETRIZE { status = STATUS1_FREEZE; }
    PARAMETRIZE { status = STATUS1_PARALYSIS; }
    PARAMETRIZE { status = STATUS1_TOXIC_POISON; }
    PARAMETRIZE { status = STATUS1_FROSTBITE; }
    GIVEN {
        ASSUME(gItemsInfo[ITEM_BIG_MALASADA].battleUsage == EFFECT_ITEM_CURE_STATUS);
        PLAYER(SPECIES_WOBBUFFET) { Status1(status); }
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { USE_ITEM(player, ITEM_BIG_MALASADA, partyIndex: 0); }
    } SCENE {
        switch (status)
        {
            case STATUS1_SLEEP:
                MESSAGE("Wobbuffet woke up!");
                break;
            case STATUS1_POISON:
                MESSAGE("Wobbuffet was cured of its poisoning!");
                break;
            case STATUS1_BURN:
                MESSAGE("Wobbuffet's burn was cured!");
                break;
            case STATUS1_FREEZE:
                MESSAGE("Wobbuffet thawed out!");
                break;
            case STATUS1_PARALYSIS:
                MESSAGE("Wobbuffet was cured of paralysis!");
                break;
            case STATUS1_TOXIC_POISON:
                MESSAGE("Wobbuffet was cured of its poisoning!");
                break;
            case STATUS1_FROSTBITE:
                MESSAGE("Wobbuffet's frostbite was cured!");
                break;
        }
    } THEN {
        EXPECT_EQ(player->status1, STATUS1_NONE);
    }
}

SINGLE_BATTLE_TEST("Jubilife Muffin heals a battler from any primary status")
{
    u16 status;
    PARAMETRIZE { status = STATUS1_SLEEP; }
    PARAMETRIZE { status = STATUS1_POISON; }
    PARAMETRIZE { status = STATUS1_BURN; }
    PARAMETRIZE { status = STATUS1_FREEZE; }
    PARAMETRIZE { status = STATUS1_PARALYSIS; }
    PARAMETRIZE { status = STATUS1_TOXIC_POISON; }
    PARAMETRIZE { status = STATUS1_FROSTBITE; }
    GIVEN {
        ASSUME(gItemsInfo[ITEM_JUBILIFE_MUFFIN].battleUsage == EFFECT_ITEM_CURE_STATUS);
        PLAYER(SPECIES_WOBBUFFET) { Status1(status); }
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { USE_ITEM(player, ITEM_JUBILIFE_MUFFIN, partyIndex: 0); }
    } SCENE {
        switch (status)
        {
            case STATUS1_SLEEP:
                MESSAGE("Wobbuffet woke up!");
                break;
            case STATUS1_POISON:
                MESSAGE("Wobbuffet was cured of its poisoning!");
                break;
            case STATUS1_BURN:
                MESSAGE("Wobbuffet's burn was cured!");
                break;
            case STATUS1_FREEZE:
                MESSAGE("Wobbuffet thawed out!");
                break;
            case STATUS1_PARALYSIS:
                MESSAGE("Wobbuffet was cured of paralysis!");
                break;
            case STATUS1_TOXIC_POISON:
                MESSAGE("Wobbuffet was cured of its poisoning!");
                break;
            case STATUS1_FROSTBITE:
                MESSAGE("Wobbuffet's frostbite was cured!");
                break;
        }
    } THEN {
        EXPECT_EQ(player->status1, STATUS1_NONE);
    }
}

SINGLE_BATTLE_TEST("Full Heal, Heal Powder and Local Specialties heal a battler from being confused")
{
    enum Item item;
    PARAMETRIZE { item = ITEM_FULL_HEAL; }
    PARAMETRIZE { item = ITEM_HEAL_POWDER; }
    PARAMETRIZE { item = ITEM_PEWTER_CRUNCHIES; }
    PARAMETRIZE { item = ITEM_LAVA_COOKIE; }
    PARAMETRIZE { item = ITEM_RAGE_CANDY_BAR; }
    PARAMETRIZE { item = ITEM_OLD_GATEAU; }
    PARAMETRIZE { item = ITEM_CASTELIACONE; }
    PARAMETRIZE { item = ITEM_LUMIOSE_GALETTE; }
    PARAMETRIZE { item = ITEM_SHALOUR_SABLE; }
    PARAMETRIZE { item = ITEM_BIG_MALASADA; }
    PARAMETRIZE { item = ITEM_JUBILIFE_MUFFIN; }
    GIVEN {
        ASSUME(gItemsInfo[item].battleUsage == EFFECT_ITEM_CURE_STATUS);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_GENGAR);
    } WHEN {
        TURN { MOVE(opponent, MOVE_CONFUSE_RAY); }
        TURN { USE_ITEM(player, item, partyIndex: 0); }
    } SCENE {
        MESSAGE("Wobbuffet snapped out of its confusion!");
    } THEN {
        EXPECT(player->volatiles.confusionTimer == 0);
    }
}
