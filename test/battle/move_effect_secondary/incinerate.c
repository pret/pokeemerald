#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(MoveHasAdditionalEffect(MOVE_INCINERATE, MOVE_EFFECT_INCINERATE));
}

SINGLE_BATTLE_TEST("Incinerate destroys Berries and Gems even if the holder has Klutz")
{
    enum Item item;

    PARAMETRIZE { item = ITEM_CHERI_BERRY; }
    PARAMETRIZE { item = ITEM_GHOST_GEM; }

    GIVEN {
        ASSUME(GetItemPocket(ITEM_CHERI_BERRY) == POCKET_BERRIES);
        ASSUME(GetItemHoldEffect(ITEM_GHOST_GEM) == HOLD_EFFECT_GEMS);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_CAPSAKID) { Ability(ABILITY_KLUTZ); Item(item); }
    } WHEN {
        TURN { MOVE(player, MOVE_INCINERATE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_INCINERATE, player);
    } THEN {
        EXPECT_EQ(opponent->item, ITEM_NONE);
    }
}

SINGLE_BATTLE_TEST("Incinerate activates Occa Berry before destroying it")
{
    GIVEN {
        ASSUME(GetMoveType(MOVE_INCINERATE) == TYPE_FIRE);
        ASSUME(IsSpeciesOfType(SPECIES_CAPSAKID, TYPE_GRASS));
        ASSUME(GetItemHoldEffect(ITEM_OCCA_BERRY) == HOLD_EFFECT_RESIST_BERRY);
        ASSUME(GetItemHoldEffectParam(ITEM_OCCA_BERRY) == TYPE_FIRE);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_CAPSAKID) { Item(ITEM_OCCA_BERRY); }
    } WHEN {
        TURN { MOVE(player, MOVE_INCINERATE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_BERRY, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_INCINERATE, player);
        HP_BAR(opponent);
    } THEN {
        EXPECT_EQ(opponent->item, ITEM_NONE);
    }
}

SINGLE_BATTLE_TEST("Incinerate destroys Oran Berry before it can restore HP")
{
    s16 damage;

    GIVEN {
        ASSUME(GetItemHoldEffect(ITEM_ORAN_BERRY) == HOLD_EFFECT_RESTORE_HP);
        ASSUME(GetItemHoldEffectParam(ITEM_ORAN_BERRY) == 10);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_ORAN_BERRY); HP(201); MaxHP(400); }
    } WHEN {
        TURN { MOVE(player, MOVE_INCINERATE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_INCINERATE, player);
        HP_BAR(opponent, captureDamage: &damage);
        NOT ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_BERRY, opponent);
    } THEN {
        EXPECT_EQ(opponent->hp, 201 - damage);
        EXPECT_EQ(opponent->item, ITEM_NONE);
    }
}

SINGLE_BATTLE_TEST("Incinerate destroys Rowap Berry before it can damage the attacker")
{
    GIVEN {
        ASSUME(GetMoveCategory(MOVE_INCINERATE) == DAMAGE_CATEGORY_SPECIAL);
        ASSUME(GetItemHoldEffect(ITEM_ROWAP_BERRY) == HOLD_EFFECT_ROWAP_BERRY);
        PLAYER(SPECIES_WOBBUFFET) { HP(400); MaxHP(400); }
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_ROWAP_BERRY); }
    } WHEN {
        TURN { MOVE(player, MOVE_INCINERATE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_INCINERATE, player);
        HP_BAR(opponent);
        NOT ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_BERRY, opponent);
    } THEN {
        EXPECT_EQ(player->hp, 400);
        EXPECT_EQ(opponent->item, ITEM_NONE);
    }
}
