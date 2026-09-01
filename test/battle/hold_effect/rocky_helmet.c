#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetItemHoldEffect(ITEM_ROCKY_HELMET) == HOLD_EFFECT_ROCKY_HELMET);
    ASSUME(MoveMakesContact(MOVE_SCRATCH));
    ASSUME(MoveMakesContact(MOVE_SHADOW_SNEAK));
}

SINGLE_BATTLE_TEST("Rocky Helmet damages attacker even if damage is blocked by Disguise")
{
    GIVEN {
        PLAYER(SPECIES_MIMIKYU) { Item(ITEM_ROCKY_HELMET); Ability(ABILITY_DISGUISE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SHADOW_SNEAK); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SHADOW_SNEAK, opponent);
        HP_BAR(opponent);
    }
}

SINGLE_BATTLE_TEST("Rocky Helmet does not trigger contact damage again after a later strike misses")
{
    const u32 maxHP = 600;

    GIVEN {
        ASSUME(MoveMakesContact(MOVE_POPULATION_BOMB));
        ASSUME(GetMoveEffect(MOVE_POPULATION_BOMB) == EFFECT_POPULATION_BOMB);
        ASSUME(GetItemHoldEffect(ITEM_ROCKY_HELMET) == HOLD_EFFECT_ROCKY_HELMET);
        PLAYER(SPECIES_MACHAMP) { Ability(ABILITY_NO_GUARD); MaxHP(maxHP); HP(maxHP); }
        OPPONENT(SPECIES_OINKOLOGNE) { Ability(ABILITY_LINGERING_AROMA); Item(ITEM_ROCKY_HELMET); }
    } WHEN {
        TURN { MOVE(player, MOVE_POPULATION_BOMB, WITH_RNG(RNG_ACCURACY, FALSE)); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POPULATION_BOMB, player);
        ABILITY_POPUP(opponent, ABILITY_LINGERING_AROMA);
        HP_BAR(player, damage: maxHP / 6);
        MESSAGE("Machamp was hurt by the opposing Oinkologne's Rocky Helmet!");
        MESSAGE("The Pokémon was hit 1 time!");
        NONE_OF {
            HP_BAR(player);
            MESSAGE("Machamp was hurt by the opposing Oinkologne's Rocky Helmet!");
        }
    }
}

TO_DO_BATTLE_TEST("TODO: Write Rocky Helmet (Hold Effect) test titles")
