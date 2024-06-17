#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Toxic Chain inflicts bad poison when attacking")
{
    GIVEN {
        ASSUME(gMovesInfo[MOVE_TACKLE].category != DAMAGE_CATEGORY_STATUS);
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
        ASSUME(gMovesInfo[MOVE_BLIZZARD].category != DAMAGE_CATEGORY_STATUS);
        ASSUME(gMovesInfo[MOVE_BLIZZARD].target == MOVE_TARGET_BOTH);
        PLAYER(SPECIES_OKIDOGI) { Ability(ABILITY_TOXIC_CHAIN); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_BLIZZARD); }
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

TO_DO_BATTLE_TEST("Toxic Chain makes Lum/Pecha Berry trigger before being knocked off");
