#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Items can restore a battler's HP by a fixed amount (singles, player)")
{
    enum Item item;
    u32 hp;
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

SINGLE_BATTLE_TEST("Items can restore a battler's HP by a fixed amount (singles, opponent)")
{
    enum Item item;
    u32 hp;
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
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { HP(1); MaxHP(400); }
    } WHEN {
        TURN { USE_ITEM(opponent, item, partyIndex: 0); }
    } SCENE {
        HP_BAR(opponent, damage: -hp);
    }
}

DOUBLE_BATTLE_TEST("Items can restore a battler's HP (doubles, playerLeft)")
{
    s32 hp = gItemsInfo[ITEM_POTION].holdEffectParam;
    GIVEN {
        ASSUME(gItemsInfo[ITEM_POTION].battleUsage == EFFECT_ITEM_RESTORE_HP);
        PLAYER(SPECIES_WOBBUFFET) { HP(1); MaxHP(400); }
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { USE_ITEM(playerLeft, ITEM_POTION, partyIndex: 0); }
    } SCENE {
        HP_BAR(playerLeft, damage: -hp);
    }
}

DOUBLE_BATTLE_TEST("Items can restore a battler's HP (doubles, playerRight)")
{
    s32 hp = gItemsInfo[ITEM_POTION].holdEffectParam;
    GIVEN {
        ASSUME(gItemsInfo[ITEM_POTION].battleUsage == EFFECT_ITEM_RESTORE_HP);
        PLAYER(SPECIES_WYNAUT);
        PLAYER(SPECIES_WOBBUFFET) { HP(1); MaxHP(400); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { USE_ITEM(playerRight, ITEM_POTION, partyIndex: 1); }
    } SCENE {
        HP_BAR(playerRight, damage: -hp);
    }
}

DOUBLE_BATTLE_TEST("Items can restore a battler's HP (doubles, opponentLeft)")
{
    s32 hp = gItemsInfo[ITEM_POTION].holdEffectParam;
    GIVEN {
        ASSUME(gItemsInfo[ITEM_POTION].battleUsage == EFFECT_ITEM_RESTORE_HP);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET) { HP(1); MaxHP(400); }
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { USE_ITEM(opponentLeft, ITEM_POTION, partyIndex: 0); }
    } SCENE {
        HP_BAR(opponentLeft, damage: -hp);
    }
}

DOUBLE_BATTLE_TEST("Items can restore a battler's HP (doubles, opponentRight)")
{
    s32 hp = gItemsInfo[ITEM_POTION].holdEffectParam;
    GIVEN {
        ASSUME(gItemsInfo[ITEM_POTION].battleUsage == EFFECT_ITEM_RESTORE_HP);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET) { HP(1); MaxHP(400); }
    } WHEN {
        TURN { USE_ITEM(opponentRight, ITEM_POTION, partyIndex: 1); }
    } SCENE {
        HP_BAR(opponentRight, damage: -hp);
    }
}

DOUBLE_BATTLE_TEST("Items can restore a partner battler's HP (playerRight to playerLeft)")
{
    s32 hp = gItemsInfo[ITEM_POTION].holdEffectParam;
    GIVEN {
        ASSUME(gItemsInfo[ITEM_POTION].battleUsage == EFFECT_ITEM_RESTORE_HP);
        PLAYER(SPECIES_WOBBUFFET) { HP(1); MaxHP(400); }
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { USE_ITEM(playerRight, ITEM_POTION, partyIndex: 0); }
    } SCENE {
        HP_BAR(playerLeft, damage: -hp);
    }
}

DOUBLE_BATTLE_TEST("Items can restore a partner battler's HP (playerLeft to playerRight)")
{
    s32 hp = gItemsInfo[ITEM_POTION].holdEffectParam;
    GIVEN {
        ASSUME(gItemsInfo[ITEM_POTION].battleUsage == EFFECT_ITEM_RESTORE_HP);
        PLAYER(SPECIES_WYNAUT);
        PLAYER(SPECIES_WOBBUFFET) { HP(1); MaxHP(400); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { USE_ITEM(playerLeft, ITEM_POTION, partyIndex: 1); }
    } SCENE {
        HP_BAR(playerRight, damage: -hp);
    }
}

DOUBLE_BATTLE_TEST("Items can restore a partner battler's HP (opponentRight to opponentLeft)")
{
    s32 hp = gItemsInfo[ITEM_POTION].holdEffectParam;
    GIVEN {
        ASSUME(gItemsInfo[ITEM_POTION].battleUsage == EFFECT_ITEM_RESTORE_HP);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET) { HP(1); MaxHP(400); }
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { USE_ITEM(opponentRight, ITEM_POTION, partyIndex: 0); }
    } SCENE {
        HP_BAR(opponentLeft, damage: -hp);
    }
}

DOUBLE_BATTLE_TEST("Items can restore a partner battler's HP (opponentLeft to opponentRight)")
{
    s32 hp = gItemsInfo[ITEM_POTION].holdEffectParam;
    GIVEN {
        ASSUME(gItemsInfo[ITEM_POTION].battleUsage == EFFECT_ITEM_RESTORE_HP);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET) { HP(1); MaxHP(400); }
    } WHEN {
        TURN { USE_ITEM(opponentLeft, ITEM_POTION, partyIndex: 1); }
    } SCENE {
        HP_BAR(opponentRight, damage: -hp);
    }
}

SINGLE_BATTLE_TEST("Items can restore a battler's HP by a percentage")
{
    enum Item item;
    u32 percentage;
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
