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
