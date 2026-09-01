#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Toxic Chain inflicts bad poison when attacking")
{
    PASSES_RANDOMLY(3, 10, RNG_TOXIC_CHAIN);
    GIVEN {
        ASSUME(GetMoveCategory(MOVE_SCRATCH) != DAMAGE_CATEGORY_STATUS);
        ASSUME(GetMovePower(MOVE_SCRATCH) > 0);
        PLAYER(SPECIES_OKIDOGI) { Ability(ABILITY_TOXIC_CHAIN); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_TOXIC_CHAIN);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PSN, opponent);
        MESSAGE("The opposing Wobbuffet was badly poisoned!");
        STATUS_ICON(opponent, badPoison: TRUE);
    } THEN {
        EXPECT(opponent->status1 & STATUS1_TOXIC_POISON);
    }
}

SINGLE_BATTLE_TEST("Toxic Chain is checked before the move's additional effect")
{
    GIVEN {
        ASSUME(GetMoveCategory(MOVE_NUZZLE) != DAMAGE_CATEGORY_STATUS);
        ASSUME(GetMovePower(MOVE_NUZZLE) > 0);
        ASSUME(MoveHasAdditionalEffectWithChance(MOVE_NUZZLE, MOVE_EFFECT_PARALYSIS, 100) == TRUE);
        PLAYER(SPECIES_OKIDOGI) { Ability(ABILITY_TOXIC_CHAIN); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_NUZZLE, WITH_RNG(RNG_TOXIC_CHAIN, TRUE)); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_NUZZLE, player);
        NONE_OF {
            ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PRZ, opponent);
            STATUS_ICON(opponent, paralysis: TRUE);
        }
        ABILITY_POPUP(player, ABILITY_TOXIC_CHAIN);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PSN, opponent);
        STATUS_ICON(opponent, badPoison: TRUE);    
    } THEN {
        EXPECT(opponent->status1 & STATUS1_TOXIC_POISON);
    }
}

SINGLE_BATTLE_TEST("Toxic Chain inflicts bad poison on any hit of a multi-hit move")
{
    GIVEN {
        ASSUME(GetMoveCategory(MOVE_DOUBLE_SLAP) != DAMAGE_CATEGORY_STATUS);
        ASSUME(IsMultiHitMove(MOVE_DOUBLE_SLAP));
        ASSUME(GetMovePower(MOVE_DOUBLE_SLAP) > 0);
        ASSUME(gItemsInfo[ITEM_PECHA_BERRY].holdEffect == HOLD_EFFECT_CURE_PSN);
        PLAYER(SPECIES_OKIDOGI) { Ability(ABILITY_TOXIC_CHAIN); }
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_PECHA_BERRY); }
    } WHEN {
        TURN { MOVE(player, MOVE_DOUBLE_SLAP); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_TOXIC_CHAIN);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PSN, opponent);
        MESSAGE("The opposing Wobbuffet was badly poisoned!");
        STATUS_ICON(opponent, badPoison: TRUE);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_BERRY, opponent);
        STATUS_ICON(opponent, badPoison: FALSE);
        ABILITY_POPUP(player, ABILITY_TOXIC_CHAIN);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PSN, opponent);
        MESSAGE("The opposing Wobbuffet was badly poisoned!");
        STATUS_ICON(opponent, badPoison: TRUE);
    } THEN {
        EXPECT(opponent->status1 & STATUS1_TOXIC_POISON);
    }
}

DOUBLE_BATTLE_TEST("Toxic Chain can inflict bad poison on both foes")
{
    GIVEN {
        ASSUME(GetMoveCategory(MOVE_RAZOR_LEAF) != DAMAGE_CATEGORY_STATUS);
        ASSUME(GetMoveTarget(MOVE_RAZOR_LEAF) == TARGET_BOTH);
        ASSUME(GetMovePower(MOVE_RAZOR_LEAF) > 0);
        PLAYER(SPECIES_OKIDOGI) { Ability(ABILITY_TOXIC_CHAIN); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_RAZOR_LEAF, WITH_RNG(RNG_TOXIC_CHAIN, TRUE)); }
    } SCENE {
        HP_BAR(opponentLeft);
        HP_BAR(opponentRight);
        ABILITY_POPUP(playerLeft, ABILITY_TOXIC_CHAIN);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PSN, opponentLeft);
        MESSAGE("The opposing Wobbuffet was badly poisoned!");
        STATUS_ICON(opponentLeft, badPoison: TRUE);
        ABILITY_POPUP(playerLeft, ABILITY_TOXIC_CHAIN);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PSN, opponentRight);
        MESSAGE("The opposing Wynaut was badly poisoned!");
        STATUS_ICON(opponentRight, badPoison: TRUE);
    } THEN {
        EXPECT(opponentLeft->status1 & STATUS1_TOXIC_POISON);
        EXPECT(opponentRight->status1 & STATUS1_TOXIC_POISON);
    }
}

SINGLE_BATTLE_TEST("Toxic Chain makes Lum/Pecha Berry trigger before being knocked off")
{
    enum Item item = ITEM_NONE;

    PARAMETRIZE { item = ITEM_PECHA_BERRY; }
    PARAMETRIZE { item = ITEM_LUM_BERRY; }

    GIVEN {
        ASSUME(GetMoveCategory(MOVE_KNOCK_OFF) != DAMAGE_CATEGORY_STATUS);
        ASSUME(GetMoveEffect(MOVE_KNOCK_OFF) == EFFECT_KNOCK_OFF);
        ASSUME(GetMovePower(MOVE_KNOCK_OFF) > 0);
        ASSUME(gItemsInfo[ITEM_PECHA_BERRY].holdEffect == HOLD_EFFECT_CURE_PSN);
        ASSUME(gItemsInfo[ITEM_LUM_BERRY].holdEffect == HOLD_EFFECT_CURE_STATUS);
        PLAYER(SPECIES_OKIDOGI) { Ability(ABILITY_TOXIC_CHAIN); }
        OPPONENT(SPECIES_WOBBUFFET) { Item(item); }
    } WHEN {
        TURN { MOVE(player, MOVE_KNOCK_OFF, WITH_RNG(RNG_TOXIC_CHAIN, TRUE)); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_TOXIC_CHAIN);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PSN, opponent);
        MESSAGE("The opposing Wobbuffet was badly poisoned!");
        STATUS_ICON(opponent, badPoison: TRUE);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_BERRY, opponent);
        STATUS_ICON(opponent, badPoison: FALSE);
        NONE_OF {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_ITEM_KNOCKOFF);
            MESSAGE("Okidogi knocked off the opposing Wobbuffet's Pecha Berry!");
            MESSAGE("Okidogi knocked off the opposing Wobbuffet's Lum Berry!");
        }
    } THEN {
        EXPECT(opponent->status1 == 0);
    }
}

SINGLE_BATTLE_TEST("Toxic Chain does not trigger if attack is blocked by Substitute")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_SUBSTITUTE) == EFFECT_SUBSTITUTE);
        ASSUME(GetMoveCategory(MOVE_SCRATCH) != DAMAGE_CATEGORY_STATUS);
        PLAYER(SPECIES_OKIDOGI) { Ability(ABILITY_TOXIC_CHAIN); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SUBSTITUTE); }
        TURN { MOVE(player, MOVE_SCRATCH, WITH_RNG(RNG_TOXIC_CHAIN, TRUE)); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SUBSTITUTE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        NONE_OF {
            ABILITY_POPUP(player, ABILITY_TOXIC_CHAIN);
            ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PSN, opponent);
            STATUS_ICON(opponent, badPoison: TRUE);
        }
    } THEN {
        EXPECT(opponent->status1 == 0);
    }
}

SINGLE_BATTLE_TEST("Toxic Chain is blocked by Shield Dust")
{
    GIVEN {
        ASSUME(GetMoveCategory(MOVE_SCRATCH) != DAMAGE_CATEGORY_STATUS);
        PLAYER(SPECIES_OKIDOGI) { Ability(ABILITY_TOXIC_CHAIN); }
        OPPONENT(SPECIES_VIVILLON) { Ability(ABILITY_SHIELD_DUST); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH, WITH_RNG(RNG_TOXIC_CHAIN, TRUE)); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        HP_BAR(opponent);
        NONE_OF {
            ABILITY_POPUP(player, ABILITY_TOXIC_CHAIN);
            ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PSN, opponent);
            STATUS_ICON(opponent, badPoison: TRUE);
        }
    } THEN {
        EXPECT(opponent->status1 == 0);
    }
}

SINGLE_BATTLE_TEST("Toxic Chain is blocked by Covert Cloak")
{
    GIVEN {
        ASSUME(gItemsInfo[ITEM_COVERT_CLOAK].holdEffect == HOLD_EFFECT_COVERT_CLOAK);
        ASSUME(GetMoveCategory(MOVE_SCRATCH) != DAMAGE_CATEGORY_STATUS);
        PLAYER(SPECIES_OKIDOGI) { Ability(ABILITY_TOXIC_CHAIN); }
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_COVERT_CLOAK); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH, WITH_RNG(RNG_TOXIC_CHAIN, TRUE)); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        HP_BAR(opponent);
        NONE_OF {
            ABILITY_POPUP(player, ABILITY_TOXIC_CHAIN);
            ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PSN, opponent);
            STATUS_ICON(opponent, badPoison: TRUE);
        }
    } THEN {
        EXPECT(opponent->status1 == 0);
    }
}
