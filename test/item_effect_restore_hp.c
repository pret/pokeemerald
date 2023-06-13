#include "global.h"
#include "test_battle.h"

#define TEST_HP 1
#define MAX_HP 400

SINGLE_BATTLE_TEST("Potion restores a battler's HP by 20")
{
    GIVEN {
        ASSUME(gItems[ITEM_POTION].battleUsage == EFFECT_ITEM_RESTORE_HP);
        PLAYER(SPECIES_WOBBUFFET) { HP(TEST_HP); MaxHP(MAX_HP); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { USE_ITEM(player, ITEM_POTION, partyIndex: 0); }
    } SCENE {
        HP_BAR(player, hp: TEST_HP + 20);
    }
}

SINGLE_BATTLE_TEST("Super Potion restores a battler's HP by 60")
{
    GIVEN {
        ASSUME(gItems[ITEM_SUPER_POTION].battleUsage == EFFECT_ITEM_RESTORE_HP);
        PLAYER(SPECIES_WOBBUFFET) { HP(TEST_HP); MaxHP(MAX_HP); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { USE_ITEM(player, ITEM_SUPER_POTION, partyIndex: 0); }
    } SCENE {
        HP_BAR(player, hp: TEST_HP + 60);
    }
}

SINGLE_BATTLE_TEST("Hyper Potion restores a battler's HP by 120")
{
    GIVEN {
        ASSUME(gItems[ITEM_HYPER_POTION].battleUsage == EFFECT_ITEM_RESTORE_HP);
        PLAYER(SPECIES_WOBBUFFET) { HP(TEST_HP); MaxHP(MAX_HP); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { USE_ITEM(player, ITEM_HYPER_POTION, partyIndex: 0); }
    } SCENE {
        HP_BAR(player, hp: TEST_HP + 120);
    }
}

SINGLE_BATTLE_TEST("Max Potion restores a battler's HP fully")
{
    GIVEN {
        ASSUME(gItems[ITEM_MAX_POTION].battleUsage == EFFECT_ITEM_RESTORE_HP);
        PLAYER(SPECIES_WOBBUFFET) { HP(TEST_HP); MaxHP(MAX_HP); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { USE_ITEM(player, ITEM_MAX_POTION, partyIndex: 0); }
    } SCENE {
        HP_BAR(player, hp: MAX_HP);
    }
}

SINGLE_BATTLE_TEST("Fresh Water restores a battler's HP by 30")
{
    GIVEN {
        ASSUME(gItems[ITEM_FRESH_WATER].battleUsage == EFFECT_ITEM_RESTORE_HP);
        PLAYER(SPECIES_WOBBUFFET) { HP(TEST_HP); MaxHP(MAX_HP); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { USE_ITEM(player, ITEM_FRESH_WATER, partyIndex: 0); }
    } SCENE {
        HP_BAR(player, hp: TEST_HP + 30);
    }
}

SINGLE_BATTLE_TEST("Soda Pop restores a battler's HP by 50")
{
    GIVEN {
        ASSUME(gItems[ITEM_SODA_POP].battleUsage == EFFECT_ITEM_RESTORE_HP);
        PLAYER(SPECIES_WOBBUFFET) { HP(TEST_HP); MaxHP(MAX_HP); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { USE_ITEM(player, ITEM_SODA_POP, partyIndex: 0); }
    } SCENE {
        HP_BAR(player, hp: TEST_HP + 50);
    }
}

SINGLE_BATTLE_TEST("Lemonade restores a battler's HP by 70")
{
    GIVEN {
        ASSUME(gItems[ITEM_LEMONADE].battleUsage == EFFECT_ITEM_RESTORE_HP);
        PLAYER(SPECIES_WOBBUFFET) { HP(TEST_HP); MaxHP(MAX_HP); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { USE_ITEM(player, ITEM_LEMONADE, partyIndex: 0); }
    } SCENE {
        HP_BAR(player, hp: TEST_HP + 70);
    }
}

SINGLE_BATTLE_TEST("Moomoo Milk restores a battler's HP by 100")
{
    GIVEN {
        ASSUME(gItems[ITEM_MOOMOO_MILK].battleUsage == EFFECT_ITEM_RESTORE_HP);
        PLAYER(SPECIES_WOBBUFFET) { HP(TEST_HP); MaxHP(MAX_HP); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { USE_ITEM(player, ITEM_MOOMOO_MILK, partyIndex: 0); }
    } SCENE {
        HP_BAR(player, hp: TEST_HP + 100);
    }
}

SINGLE_BATTLE_TEST("Energy Powder restores a battler's HP by 60(50)")
{
    GIVEN {
        ASSUME(gItems[ITEM_ENERGY_POWDER].battleUsage == EFFECT_ITEM_RESTORE_HP);
        PLAYER(SPECIES_WOBBUFFET) { HP(TEST_HP); MaxHP(MAX_HP); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { USE_ITEM(player, ITEM_ENERGY_POWDER, partyIndex: 0); }
    } SCENE {
        if (I_HEALTH_RECOVERY >= GEN_7)
            HP_BAR(player, hp: TEST_HP + 60);
        else
            HP_BAR(player, hp: TEST_HP + 50);
    }
}

SINGLE_BATTLE_TEST("Energy Root restores a battler's HP by 120(200)")
{
    GIVEN {
        ASSUME(gItems[ITEM_ENERGY_ROOT].battleUsage == EFFECT_ITEM_RESTORE_HP);
        PLAYER(SPECIES_WOBBUFFET) { HP(TEST_HP); MaxHP(MAX_HP); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { USE_ITEM(player, ITEM_ENERGY_ROOT, partyIndex: 0); }
    } SCENE {
        if (I_HEALTH_RECOVERY >= GEN_7)
            HP_BAR(player, hp: TEST_HP + 120);
        else
            HP_BAR(player, hp: TEST_HP + 200);
    }
}

SINGLE_BATTLE_TEST("Sweet Heart restores a battler's HP by 20")
{
    GIVEN {
        ASSUME(gItems[ITEM_SWEET_HEART].battleUsage == EFFECT_ITEM_RESTORE_HP);
        PLAYER(SPECIES_WOBBUFFET) { HP(TEST_HP); MaxHP(MAX_HP); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { USE_ITEM(player, ITEM_SWEET_HEART, partyIndex: 0); }
    } SCENE {
        HP_BAR(player, hp: TEST_HP + 20);
    }
}

SINGLE_BATTLE_TEST("Oran Berry restores a battler's HP by 10")
{
    GIVEN {
        ASSUME(gItems[ITEM_ORAN_BERRY].battleUsage == EFFECT_ITEM_RESTORE_HP);
        PLAYER(SPECIES_WOBBUFFET) { HP(TEST_HP); MaxHP(MAX_HP); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { USE_ITEM(player, ITEM_ORAN_BERRY, partyIndex: 0); }
    } SCENE {
        HP_BAR(player, hp: TEST_HP + 10);
    }
}

SINGLE_BATTLE_TEST("Sitrus Berry restores a battler's HP by 25% of its max HP(30HP flat)")
{
    GIVEN {
        ASSUME(gItems[ITEM_SITRUS_BERRY].battleUsage == EFFECT_ITEM_RESTORE_HP);
        PLAYER(SPECIES_WOBBUFFET) { HP(TEST_HP); MaxHP(MAX_HP); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { USE_ITEM(player, ITEM_SITRUS_BERRY, partyIndex: 0); }
    } SCENE {
        if (I_SITRUS_BERRY_HEAL >= GEN_4)
            HP_BAR(player, hp: TEST_HP + MAX_HP * 0.25);
        else
            HP_BAR(player, hp: TEST_HP + 30);
    }
}

#undef TEST_HP
#undef MAX_HP
