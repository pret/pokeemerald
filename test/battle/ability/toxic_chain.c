#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Toxic Chain inflicts bad poison when attacking")
{
    PASSES_RANDOMLY(3, 10, RNG_TOXIC_CHAIN);
    GIVEN {
        ASSUME(gMovesInfo[MOVE_TACKLE].category != DAMAGE_CATEGORY_STATUS);
        ASSUME(gMovesInfo[MOVE_TACKLE].power > 0);
        PLAYER(SPECIES_OKIDOGI) { Ability(ABILITY_TOXIC_CHAIN); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_TACKLE); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_TOXIC_CHAIN);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PSN, opponent);
        MESSAGE("Foe Wobbuffet is badly poisoned!");
        STATUS_ICON(opponent, badPoison: TRUE);
    } THEN {
        EXPECT(opponent->status1 & STATUS1_TOXIC_POISON);
    }
}

SINGLE_BATTLE_TEST("Toxic Chain inflicts bad poison on any hit of a multi-hit move")
{
    GIVEN {
        ASSUME(gMovesInfo[MOVE_DOUBLE_SLAP].category != DAMAGE_CATEGORY_STATUS);
        ASSUME(gMovesInfo[MOVE_DOUBLE_SLAP].effect == EFFECT_MULTI_HIT);
        ASSUME(gMovesInfo[MOVE_DOUBLE_SLAP].power > 0);
        ASSUME(gItemsInfo[ITEM_PECHA_BERRY].holdEffect == HOLD_EFFECT_CURE_PSN);
        PLAYER(SPECIES_OKIDOGI) { Ability(ABILITY_TOXIC_CHAIN); }
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_PECHA_BERRY); }
    } WHEN {
        TURN { MOVE(player, MOVE_DOUBLE_SLAP); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_TOXIC_CHAIN);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PSN, opponent);
        MESSAGE("Foe Wobbuffet is badly poisoned!");
        STATUS_ICON(opponent, badPoison: TRUE);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, opponent);
        STATUS_ICON(opponent, badPoison: FALSE);
        ABILITY_POPUP(player, ABILITY_TOXIC_CHAIN);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PSN, opponent);
        MESSAGE("Foe Wobbuffet is badly poisoned!");
        STATUS_ICON(opponent, badPoison: TRUE);
    } THEN {
        EXPECT(opponent->status1 & STATUS1_TOXIC_POISON);
    }
}

DOUBLE_BATTLE_TEST("Toxic Chain can inflict bad poison on both foes")
{
    GIVEN {
        ASSUME(gMovesInfo[MOVE_RAZOR_LEAF].category != DAMAGE_CATEGORY_STATUS);
        ASSUME(gMovesInfo[MOVE_RAZOR_LEAF].target == MOVE_TARGET_BOTH);
        ASSUME(gMovesInfo[MOVE_RAZOR_LEAF].power > 0);
        PLAYER(SPECIES_OKIDOGI) { Ability(ABILITY_TOXIC_CHAIN); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_RAZOR_LEAF, WITH_RNG(RNG_TOXIC_CHAIN, TRUE)); }
    } SCENE {
        HP_BAR(opponentLeft);
        ABILITY_POPUP(playerLeft, ABILITY_TOXIC_CHAIN);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PSN, opponentLeft);
        MESSAGE("Foe Wobbuffet is badly poisoned!");
        STATUS_ICON(opponentLeft, badPoison: TRUE);
        HP_BAR(opponentRight);
        ABILITY_POPUP(playerLeft, ABILITY_TOXIC_CHAIN);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PSN, opponentRight);
        MESSAGE("Foe Wynaut is badly poisoned!");
        STATUS_ICON(opponentRight, badPoison: TRUE);
    } THEN {
        EXPECT(opponentLeft->status1 & STATUS1_TOXIC_POISON);
        EXPECT(opponentRight->status1 & STATUS1_TOXIC_POISON);
    }
}

SINGLE_BATTLE_TEST("Toxic Chain makes Lum/Pecha Berry trigger before being knocked off")
{
    u16 item = 0;

    PARAMETRIZE { item = ITEM_PECHA_BERRY; }
    PARAMETRIZE { item = ITEM_LUM_BERRY; }

    GIVEN {
        ASSUME(gMovesInfo[MOVE_KNOCK_OFF].category != DAMAGE_CATEGORY_STATUS);
        ASSUME(gMovesInfo[MOVE_KNOCK_OFF].effect == EFFECT_KNOCK_OFF);
        ASSUME(gMovesInfo[MOVE_KNOCK_OFF].power > 0);
        ASSUME(gItemsInfo[ITEM_PECHA_BERRY].holdEffect == HOLD_EFFECT_CURE_PSN);
        ASSUME(gItemsInfo[ITEM_LUM_BERRY].holdEffect == HOLD_EFFECT_CURE_STATUS);
        PLAYER(SPECIES_OKIDOGI) { Ability(ABILITY_TOXIC_CHAIN); }
        OPPONENT(SPECIES_WOBBUFFET) { Item(item); }
    } WHEN {
        TURN { MOVE(player, MOVE_KNOCK_OFF, WITH_RNG(RNG_TOXIC_CHAIN, TRUE)); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_TOXIC_CHAIN);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PSN, opponent);
        MESSAGE("Foe Wobbuffet is badly poisoned!");
        STATUS_ICON(opponent, badPoison: TRUE);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, opponent);
        STATUS_ICON(opponent, badPoison: FALSE);
        NONE_OF {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_ITEM_KNOCKOFF);
            MESSAGE("Okidogi knocked off Foe Wobbuffet's Pecha Berry!");
            MESSAGE("Okidogi knocked off Foe Wobbuffet's Lum Berry!");
        }
    } THEN {
        EXPECT(opponent->status1 == 0);
    }
}
