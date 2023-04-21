#include "global.h"
#include "test_battle.h"

SINGLE_BATTLE_TEST("Potion restores a battler's HP by 20")
{
    s16 damage;
    GIVEN {
        ASSUME(gItems[ITEM_POTION].battleUsage == EFFECT_ITEM_RESTORE_HP);
        PLAYER(SPECIES_WOBBUFFET) { HP(50); MaxHP(100); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { USE_ITEM(player, ITEM_POTION, partyIndex: 0); }
    } SCENE {
        HP_BAR(player, captureDamage: &damage);
    } FINALLY {
        EXPECT_EQ(damage, -20);
    }
}

SINGLE_BATTLE_TEST("Super Potion restores a battler's HP by 50")
{
    s16 damage;
    GIVEN {
        ASSUME(gItems[ITEM_SUPER_POTION].battleUsage == EFFECT_ITEM_RESTORE_HP);
        PLAYER(SPECIES_WOBBUFFET) { HP(50); MaxHP(100); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { USE_ITEM(player, ITEM_SUPER_POTION, partyIndex: 0); }
    } SCENE {
        HP_BAR(player, captureDamage: &damage);
    } FINALLY {
        EXPECT_EQ(damage, -50);
    }
}

SINGLE_BATTLE_TEST("Hyper Potion restores a battler's HP by 200")
{
    s16 damage;
    GIVEN {
        ASSUME(gItems[ITEM_HYPER_POTION].battleUsage == EFFECT_ITEM_RESTORE_HP);
        PLAYER(SPECIES_WOBBUFFET) { HP(100); MaxHP(400); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { USE_ITEM(player, ITEM_HYPER_POTION, partyIndex: 0); }
    } SCENE {
        HP_BAR(player, captureDamage: &damage);
    } FINALLY {
        EXPECT_EQ(damage, -200);
    }
}

SINGLE_BATTLE_TEST("Max Potion restores a battler's HP fully")
{
    s16 damage;
    GIVEN {
        ASSUME(gItems[ITEM_MAX_POTION].battleUsage == EFFECT_ITEM_RESTORE_HP);
        PLAYER(SPECIES_WOBBUFFET) { HP(1); MaxHP(400); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { USE_ITEM(player, ITEM_MAX_POTION, partyIndex: 0); }
    } FINALLY {
        EXPECT_EQ(player->hp, player->maxHP);
    }
}

SINGLE_BATTLE_TEST("Fresh Water restores a battler's HP by 30")
{
    s16 damage;
    GIVEN {
        ASSUME(gItems[ITEM_FRESH_WATER].battleUsage == EFFECT_ITEM_RESTORE_HP);
        PLAYER(SPECIES_WOBBUFFET) { HP(50); MaxHP(100); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { USE_ITEM(player, ITEM_FRESH_WATER, partyIndex: 0); }
    } SCENE {
        HP_BAR(player, captureDamage: &damage);
    } FINALLY {
        EXPECT_EQ(damage, -30);
    }
}

SINGLE_BATTLE_TEST("Soda Pop restores a battler's HP by 50")
{
    s16 damage;
    GIVEN {
        ASSUME(gItems[ITEM_SODA_POP].battleUsage == EFFECT_ITEM_RESTORE_HP);
        PLAYER(SPECIES_WOBBUFFET) { HP(50); MaxHP(100); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { USE_ITEM(player, ITEM_SODA_POP, partyIndex: 0); }
    } SCENE {
        HP_BAR(player, captureDamage: &damage);
    } FINALLY {
        EXPECT_EQ(damage, -50);
    }
}

SINGLE_BATTLE_TEST("Lemonade restores a battler's HP by 70")
{
    s16 damage;
    GIVEN {
        ASSUME(gItems[ITEM_LEMONADE].battleUsage == EFFECT_ITEM_RESTORE_HP);
        PLAYER(SPECIES_WOBBUFFET) { HP(50); MaxHP(200); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { USE_ITEM(player, ITEM_LEMONADE, partyIndex: 0); }
    } SCENE {
        HP_BAR(player, captureDamage: &damage);
    } FINALLY {
        EXPECT_EQ(damage, -70);
    }
}

SINGLE_BATTLE_TEST("Moomoo Milk restores a battler's HP by 100")
{
    s16 damage;
    GIVEN {
        ASSUME(gItems[ITEM_MOOMOO_MILK].battleUsage == EFFECT_ITEM_RESTORE_HP);
        PLAYER(SPECIES_WOBBUFFET) { HP(50); MaxHP(200); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { USE_ITEM(player, ITEM_MOOMOO_MILK, partyIndex: 0); }
    } SCENE {
        HP_BAR(player, captureDamage: &damage);
    } FINALLY {
        EXPECT_EQ(damage, -100);
    }
}

SINGLE_BATTLE_TEST("Energy Powder restores a battler's HP by 50(60)")
{
    s16 damage;
    GIVEN {
        ASSUME(gItems[ITEM_ENERGY_POWDER].battleUsage == EFFECT_ITEM_RESTORE_HP);
        PLAYER(SPECIES_WOBBUFFET) { HP(50); MaxHP(200); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { USE_ITEM(player, ITEM_ENERGY_POWDER, partyIndex: 0); }
    } SCENE {
        HP_BAR(player, captureDamage: &damage);
    } FINALLY {
        #if I_HEALTH_RECOVERY >= GEN_7
        EXPECT_EQ(damage, -60);
        #else
        EXPECT_EQ(damage, -50);
        #endif
    }
}

SINGLE_BATTLE_TEST("Energy Root restores a battler's HP by 120(200)")
{
    s16 damage;
    GIVEN {
        ASSUME(gItems[ITEM_ENERGY_ROOT].battleUsage == EFFECT_ITEM_RESTORE_HP);
        PLAYER(SPECIES_WOBBUFFET) { HP(50); MaxHP(300); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { USE_ITEM(player, ITEM_ENERGY_ROOT, partyIndex: 0); }
    } SCENE {
        HP_BAR(player, captureDamage: &damage);
    } FINALLY {
        #if I_HEALTH_RECOVERY >= GEN_7
        EXPECT_EQ(damage, -120);
        #else
        EXPECT_EQ(damage, -200);
        #endif
    }
}

SINGLE_BATTLE_TEST("Sweet Heart restores a battler's HP by 20")
{
    s16 damage;
    GIVEN {
        ASSUME(gItems[ITEM_SWEET_HEART].battleUsage == EFFECT_ITEM_RESTORE_HP);
        PLAYER(SPECIES_WOBBUFFET) { HP(50); MaxHP(100); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { USE_ITEM(player, ITEM_SWEET_HEART, partyIndex: 0); }
    } SCENE {
        HP_BAR(player, captureDamage: &damage);
    } FINALLY {
        EXPECT_EQ(damage, -20);
    }
}

SINGLE_BATTLE_TEST("Oran Berry restores a battler's HP by 10")
{
    s16 damage;
    GIVEN {
        ASSUME(gItems[ITEM_ORAN_BERRY].battleUsage == EFFECT_ITEM_RESTORE_HP);
        PLAYER(SPECIES_WOBBUFFET) { HP(50); MaxHP(100); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { USE_ITEM(player, ITEM_ORAN_BERRY, partyIndex: 0); }
    } SCENE {
        HP_BAR(player, captureDamage: &damage);
    } FINALLY {
            EXPECT_EQ(damage, -10);
    }
}

SINGLE_BATTLE_TEST("Sitrus Berry restores a battler's HP")
{
    s16 damage;
    GIVEN {
        ASSUME(gItems[ITEM_SITRUS_BERRY].battleUsage == EFFECT_ITEM_RESTORE_HP);
        PLAYER(SPECIES_WOBBUFFET) { HP(50); MaxHP(100); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { USE_ITEM(player, ITEM_SITRUS_BERRY, partyIndex: 0); }
    } SCENE {
        HP_BAR(player, captureDamage: &damage);
    } FINALLY {
        if (I_SITRUS_BERRY_HEAL >= GEN_4)
            EXPECT_EQ(damage, -25);
        else
            EXPECT_EQ(damage, -30);
    }
}
