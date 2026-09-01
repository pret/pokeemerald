#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Poison Touch has a 30% chance to poison when attacking with contact moves")
{
    PASSES_RANDOMLY(3, 10, RNG_POISON_TOUCH);
    GIVEN {
        ASSUME(GetMovePower(MOVE_SCRATCH) > 0);
        ASSUME(MoveMakesContact(MOVE_SCRATCH));
        PLAYER(SPECIES_GRIMER) { Ability(ABILITY_POISON_TOUCH); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        ABILITY_POPUP(player, ABILITY_POISON_TOUCH);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PSN, opponent);
        MESSAGE("The opposing Wobbuffet was poisoned!");
        STATUS_ICON(opponent, poison: TRUE);
    }
}

SINGLE_BATTLE_TEST("Poison Touch is checked after the move's additional effect")
{
    GIVEN {
        ASSUME(GetMovePower(MOVE_NUZZLE) > 0);
        ASSUME(MoveMakesContact(MOVE_NUZZLE));
        ASSUME(MoveHasAdditionalEffectWithChance(MOVE_NUZZLE, MOVE_EFFECT_PARALYSIS, 100) == TRUE);
        PLAYER(SPECIES_GRIMER) { Ability(ABILITY_POISON_TOUCH); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_NUZZLE, WITH_RNG(RNG_POISON_TOUCH, TRUE)); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_NUZZLE, player);
        NONE_OF {
            ABILITY_POPUP(player, ABILITY_POISON_TOUCH);
            ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PSN, opponent);
            STATUS_ICON(opponent, poison: TRUE);
        }
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PRZ, opponent);
        STATUS_ICON(opponent, paralysis: TRUE);
    } THEN {
        EXPECT(opponent->status1 & STATUS1_PARALYSIS);
    }
}

SINGLE_BATTLE_TEST("Poison Touch only applies when using contact moves")
{
    enum Move move;

    PARAMETRIZE { move = MOVE_SCRATCH; }
    PARAMETRIZE { move = MOVE_SWIFT; }
    GIVEN {
        ASSUME(MoveMakesContact(MOVE_SCRATCH));
        ASSUME(!MoveMakesContact(MOVE_SWIFT));
        PLAYER(SPECIES_GRIMER) { Ability(ABILITY_POISON_TOUCH); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, player);
        if (MoveMakesContact(move)) {
            ABILITY_POPUP(player, ABILITY_POISON_TOUCH);
            ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PSN, opponent);
            MESSAGE("The opposing Wobbuffet was poisoned!");
            STATUS_ICON(opponent, poison: TRUE);
        } else {
            NONE_OF {
                ABILITY_POPUP(player, ABILITY_POISON_TOUCH);
                ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PSN, opponent);
                STATUS_ICON(opponent, poison: TRUE);
            }
        }
    }
}

SINGLE_BATTLE_TEST("Poison Touch applies between multi-hit move hits")
{
    GIVEN {
        ASSUME(IsMultiHitMove(MOVE_ARM_THRUST));
        ASSUME(MoveMakesContact(MOVE_ARM_THRUST));
        ASSUME(gItemsInfo[ITEM_PECHA_BERRY].holdEffect == HOLD_EFFECT_CURE_PSN);
        PLAYER(SPECIES_GRIMER) { Ability(ABILITY_POISON_TOUCH); }
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_PECHA_BERRY); }
    } WHEN {
        TURN { MOVE(player, MOVE_ARM_THRUST); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ARM_THRUST, player);
        ABILITY_POPUP(player, ABILITY_POISON_TOUCH);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PSN, opponent);
        MESSAGE("The opposing Wobbuffet was poisoned!");
        STATUS_ICON(opponent, poison: TRUE);
        MESSAGE("The opposing Wobbuffet's Pecha Berry cured its poison!");
        STATUS_ICON(opponent, poison: FALSE);
        ABILITY_POPUP(player, ABILITY_POISON_TOUCH);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PSN, opponent);
        MESSAGE("The opposing Wobbuffet was poisoned!");
        STATUS_ICON(opponent, poison: TRUE);
    }
}

SINGLE_BATTLE_TEST("Poison Touch activates when user has Protective Pads, but not with Punching Glove")
{
    enum Item item;

    PARAMETRIZE { item = ITEM_PROTECTIVE_PADS; }
    PARAMETRIZE { item = ITEM_PUNCHING_GLOVE; }

    GIVEN {
        ASSUME(MoveMakesContact(MOVE_MACH_PUNCH));
        ASSUME(IsPunchingMove(MOVE_MACH_PUNCH));
        ASSUME(GetItemHoldEffect(ITEM_PROTECTIVE_PADS) == HOLD_EFFECT_PROTECTIVE_PADS);
        ASSUME(GetItemHoldEffect(ITEM_PUNCHING_GLOVE) == HOLD_EFFECT_PUNCHING_GLOVE);
        PLAYER(SPECIES_GRIMER) { Ability(ABILITY_POISON_TOUCH); Item(item); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_MACH_PUNCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MACH_PUNCH, player);

        if (item != ITEM_PUNCHING_GLOVE) {
            ABILITY_POPUP(player, ABILITY_POISON_TOUCH);
            ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PSN, opponent);
            MESSAGE("The opposing Wobbuffet was poisoned!");
            STATUS_ICON(opponent, poison: TRUE);
        } else {
            NONE_OF {
                ABILITY_POPUP(player, ABILITY_POISON_TOUCH);
                ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PSN, opponent);
                STATUS_ICON(opponent, poison: TRUE);
            }
        }
    }
}

SINGLE_BATTLE_TEST("Poison Touch does not trigger if attack is blocked by Substitute")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_SUBSTITUTE) == EFFECT_SUBSTITUTE);
        ASSUME(GetMoveCategory(MOVE_SCRATCH) != DAMAGE_CATEGORY_STATUS);
        ASSUME(MoveMakesContact(MOVE_SCRATCH));
        PLAYER(SPECIES_GRIMER) { Ability(ABILITY_POISON_TOUCH); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SUBSTITUTE); }
        TURN { MOVE(player, MOVE_SCRATCH, WITH_RNG(RNG_POISON_TOUCH, TRUE)); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SUBSTITUTE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        NONE_OF {
            ABILITY_POPUP(player, ABILITY_POISON_TOUCH);
            ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PSN, opponent);
            STATUS_ICON(opponent, poison: TRUE);
        }
    } THEN {
        EXPECT(opponent->status1 == 0);
    }
}

SINGLE_BATTLE_TEST("Poison Touch is blocked by Shield Dust")
{
    GIVEN {
        ASSUME(GetMoveCategory(MOVE_SCRATCH) != DAMAGE_CATEGORY_STATUS);
        ASSUME(MoveMakesContact(MOVE_SCRATCH));
        PLAYER(SPECIES_GRIMER) { Ability(ABILITY_POISON_TOUCH); }
        OPPONENT(SPECIES_VIVILLON) { Ability(ABILITY_SHIELD_DUST); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH, WITH_RNG(RNG_POISON_TOUCH, TRUE)); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        HP_BAR(opponent);
        NONE_OF {
            ABILITY_POPUP(player, ABILITY_POISON_TOUCH);
            ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PSN, opponent);
            STATUS_ICON(opponent, poison: TRUE);
        }
    } THEN {
        EXPECT(opponent->status1 == 0);
    }
}

SINGLE_BATTLE_TEST("Poison Touch is blocked by Covert Cloak")
{
    GIVEN {
        ASSUME(gItemsInfo[ITEM_COVERT_CLOAK].holdEffect == HOLD_EFFECT_COVERT_CLOAK);
        ASSUME(GetMoveCategory(MOVE_SCRATCH) != DAMAGE_CATEGORY_STATUS);
        ASSUME(MoveMakesContact(MOVE_SCRATCH));
        PLAYER(SPECIES_GRIMER) { Ability(ABILITY_POISON_TOUCH); }
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_COVERT_CLOAK); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH, WITH_RNG(RNG_POISON_TOUCH, TRUE)); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        HP_BAR(opponent);
        NONE_OF {
            ABILITY_POPUP(player, ABILITY_POISON_TOUCH);
            ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PSN, opponent);
            STATUS_ICON(opponent, poison: TRUE);
        }
    } THEN {
        EXPECT(opponent->status1 == 0);
    }
}
