#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gItemsInfo[ITEM_FULL_RESTORE].battleUsage == EFFECT_ITEM_HEAL_AND_CURE_STATUS);
}

SINGLE_BATTLE_TEST("Full Restore restores a battler's HP and cures any primary status")
{
    u16 status;
    PARAMETRIZE { status = STATUS1_BURN; }
    PARAMETRIZE { status = STATUS1_FREEZE; }
    PARAMETRIZE { status = STATUS1_PARALYSIS; }
    PARAMETRIZE { status = STATUS1_POISON; }
    PARAMETRIZE { status = STATUS1_TOXIC_POISON; }
    PARAMETRIZE { status = STATUS1_SLEEP; }
    PARAMETRIZE { status = STATUS1_FROSTBITE; }
    PARAMETRIZE { status = STATUS1_NONE; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { HP(1); MaxHP(300); Status1(status); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { USE_ITEM(player, ITEM_FULL_RESTORE, partyIndex: 0); }
    } SCENE {
        MESSAGE("Wobbuffet had its HP restored.");
        if (status != STATUS1_NONE) {
            switch (status)
            {
                case STATUS1_BURN:
                    MESSAGE("Wobbuffet's burn was cured!");
                    break;
                case STATUS1_FREEZE:
                    MESSAGE("Wobbuffet thawed out!");
                    break;
                case STATUS1_PARALYSIS:
                    MESSAGE("Wobbuffet was cured of paralysis!");
                    break;
                case STATUS1_POISON:
                case STATUS1_TOXIC_POISON:
                    MESSAGE("Wobbuffet was cured of its poisoning!");
                    break;
                case STATUS1_SLEEP:
                    MESSAGE("Wobbuffet woke up!");
                    break;
                case STATUS1_FROSTBITE:
                    MESSAGE("Wobbuffet's frostbite was cured!");
                    break;
            } // The message is not printed if status wasn't healed.
        }
    } THEN {
        EXPECT_EQ(player->hp, player->maxHP);
        EXPECT_EQ(player->status1, STATUS1_NONE);
    }
}

SINGLE_BATTLE_TEST("Full Restore restores a party members HP and cures any primary status")
{
    u16 status;
    PARAMETRIZE { status = STATUS1_BURN; }
    PARAMETRIZE { status = STATUS1_FREEZE; }
    PARAMETRIZE { status = STATUS1_PARALYSIS; }
    PARAMETRIZE { status = STATUS1_POISON; }
    PARAMETRIZE { status = STATUS1_TOXIC_POISON; }
    PARAMETRIZE { status = STATUS1_SLEEP; }
    PARAMETRIZE { status = STATUS1_FROSTBITE; }
    PARAMETRIZE { status = STATUS1_NONE; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { HP(100); MaxHP(300); Status1(status); }
        PLAYER(SPECIES_WYNAUT) { HP(100); MaxHP(300); Status1(status); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { USE_ITEM(player, ITEM_FULL_RESTORE, partyIndex: 1); }
        TURN { SWITCH(player, 1); }
    } SCENE {
        MESSAGE("Wynaut had its HP restored.");
        if (status != STATUS1_NONE) {
            switch (status)
            {
                case STATUS1_BURN:
                    MESSAGE("Wynaut's burn was cured!");
                    break;
                case STATUS1_FREEZE:
                    MESSAGE("Wynaut thawed out!");
                    break;
                case STATUS1_PARALYSIS:
                    MESSAGE("Wynaut was cured of paralysis!");
                    break;
                case STATUS1_POISON:
                case STATUS1_TOXIC_POISON:
                    MESSAGE("Wynaut was cured of its poisoning!");
                    break;
                case STATUS1_SLEEP:
                    MESSAGE("Wynaut woke up!");
                    break;
                case STATUS1_FROSTBITE:
                    MESSAGE("Wynaut's frostbite was cured!");
                    break;
            } // The message is not printed if status wasn't healed.
        }
    } THEN {
        EXPECT_EQ(player->hp, player->maxHP);
        EXPECT_EQ(player->species, SPECIES_WYNAUT);
        EXPECT_EQ(player->status1, STATUS1_NONE);
    }
}

SINGLE_BATTLE_TEST("Full Restore heals a battler from any primary status")
{
    u16 status;
    PARAMETRIZE { status = STATUS1_BURN; }
    PARAMETRIZE { status = STATUS1_FREEZE; }
    PARAMETRIZE { status = STATUS1_PARALYSIS; }
    PARAMETRIZE { status = STATUS1_POISON; }
    PARAMETRIZE { status = STATUS1_TOXIC_POISON; }
    PARAMETRIZE { status = STATUS1_SLEEP; }
    PARAMETRIZE { status = STATUS1_FROSTBITE; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Status1(status); }
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { USE_ITEM(player, ITEM_FULL_RESTORE, partyIndex: 0); }
    } SCENE {
        NOT MESSAGE("Wobbuffet had its HP restored."); // The message is not printed if mon has max HP.
        switch (status)
        {
            case STATUS1_BURN:
                MESSAGE("Wobbuffet's burn was cured!");
                break;
            case STATUS1_FREEZE:
                MESSAGE("Wobbuffet thawed out!");
                break;
            case STATUS1_PARALYSIS:
                MESSAGE("Wobbuffet was cured of paralysis!");
                break;
            case STATUS1_POISON:
            case STATUS1_TOXIC_POISON:
                MESSAGE("Wobbuffet was cured of its poisoning!");
                break;
            case STATUS1_SLEEP:
                MESSAGE("Wobbuffet woke up!");
                break;
            case STATUS1_FROSTBITE:
                MESSAGE("Wobbuffet's frostbite was cured!");
                break;
        }
    } THEN {
        EXPECT_EQ(player->status1, STATUS1_NONE);
    }
}

SINGLE_BATTLE_TEST("Full Restore heals a party member from any primary status")
{
    u16 status;
    PARAMETRIZE { status = STATUS1_BURN; }
    PARAMETRIZE { status = STATUS1_FREEZE; }
    PARAMETRIZE { status = STATUS1_PARALYSIS; }
    PARAMETRIZE { status = STATUS1_POISON; }
    PARAMETRIZE { status = STATUS1_TOXIC_POISON; }
    PARAMETRIZE { status = STATUS1_SLEEP; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT) { Status1(status); }
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { USE_ITEM(player, ITEM_FULL_RESTORE, partyIndex: 1); }
        TURN { SWITCH(player, 1); }
    } SCENE {
        NOT MESSAGE("Wynaut had its HP restored."); // The message is not printed if mon has max HP.
        switch (status)
        {
            case STATUS1_BURN:
                MESSAGE("Wynaut's burn was cured!");
                break;
            case STATUS1_FREEZE:
                MESSAGE("Wynaut thawed out!");
                break;
            case STATUS1_PARALYSIS:
                MESSAGE("Wynaut was cured of paralysis!");
                break;
            case STATUS1_POISON:
            case STATUS1_TOXIC_POISON:
                MESSAGE("Wynaut was cured of its poisoning!");
                break;
            case STATUS1_SLEEP:
                MESSAGE("Wynaut woke up!");
                break;
        }
    } THEN {
        EXPECT_EQ(player->species, SPECIES_WYNAUT);
        EXPECT_EQ(player->status1, STATUS1_NONE);
    }
}

SINGLE_BATTLE_TEST("Full Restore restores a battler's HP and cures confusion")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { HP(1); MaxHP(300); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_CONFUSE_RAY); }
        TURN { USE_ITEM(player, ITEM_FULL_RESTORE, partyIndex: 0); }
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        MESSAGE("Wobbuffet had its HP restored.");
        NONE_OF { MESSAGE("Wobbuffet is confused!"); }
    } THEN {
        EXPECT_EQ(player->hp, player->maxHP);
    }
}

SINGLE_BATTLE_TEST("Full Restore resets Toxic Counter")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_TOXIC); }
        TURN {}
        TURN { USE_ITEM(player, ITEM_FULL_RESTORE, partyIndex: 0); }
    } SCENE {
        MESSAGE("The opposing Wobbuffet used Toxic!");
        MESSAGE("Wobbuffet had its HP restored.");
        MESSAGE("Wobbuffet was cured of its poisoning!");
    } THEN {
        EXPECT_EQ(player->status1, STATUS1_NONE);
    }
}
