#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Items can restore a battler's HP by a fixed amount")
{
    u32 item, hp;
    PARAMETRIZE { item = ITEM_POTION; hp = 20; }
    PARAMETRIZE { item = ITEM_SUPER_POTION; hp = I_HEALTH_RECOVERY >= GEN_7 ? 60 : 50; }
    PARAMETRIZE { item = ITEM_HYPER_POTION; hp = I_HEALTH_RECOVERY >= GEN_7 ? 120 : 200; }
    PARAMETRIZE { item = ITEM_FRESH_WATER; hp = I_HEALTH_RECOVERY >= GEN_7 ? 30 : 50; }
    PARAMETRIZE { item = ITEM_SODA_POP; hp = I_HEALTH_RECOVERY >= GEN_7 ? 50 : 60; }
    PARAMETRIZE { item = ITEM_LEMONADE; hp = I_HEALTH_RECOVERY >= GEN_7 ? 70 : 80; }
    PARAMETRIZE { item = ITEM_MOOMOO_MILK; hp = 100; }
    PARAMETRIZE { item = ITEM_ENERGY_POWDER; hp = I_HEALTH_RECOVERY >= GEN_7 ? 60 : 50; }
    PARAMETRIZE { item = ITEM_ENERGY_ROOT; hp = I_HEALTH_RECOVERY >= GEN_7 ? 120 : 200; }
    PARAMETRIZE { item = ITEM_SWEET_HEART; hp = 20; }
    PARAMETRIZE { item = ITEM_ORAN_BERRY; hp = 10; }
#if I_SITRUS_BERRY_HEAL < GEN_4
    PARAMETRIZE { item = ITEM_SITRUS_BERRY; hp = 30; }
#endif
    GIVEN {
        ASSUME(gItemsInfo[item].battleUsage == EFFECT_ITEM_RESTORE_HP);
        PLAYER(SPECIES_WOBBUFFET) { HP(1); MaxHP(400); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { USE_ITEM(player, item, partyIndex: 0); }
    } SCENE {
        HP_BAR(player, damage: -hp);
    }
}

SINGLE_BATTLE_TEST("Items can restore a battler's HP by a percentage")
{
    u32 item, percentage;
    PARAMETRIZE { item = ITEM_MAX_POTION; percentage = 100; }
#if I_SITRUS_BERRY_HEAL >= GEN_4
    PARAMETRIZE { item = ITEM_SITRUS_BERRY; percentage = 25; }
#endif
    GIVEN {
        ASSUME(gItemsInfo[item].battleUsage == EFFECT_ITEM_RESTORE_HP);
        PLAYER(SPECIES_WOBBUFFET) { HP(1); MaxHP(400); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { USE_ITEM(player, item, partyIndex: 0); }
    } SCENE {
        HP_BAR(player, damage: -min(399, 400 * percentage / 100));
    }
}
