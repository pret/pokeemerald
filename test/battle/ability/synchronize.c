#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Synchronize will mirror back non volatile status back at opposing mon")
{
    u32 config;
    PARAMETRIZE { config = GEN_4; }
    PARAMETRIZE { config = GEN_5; }
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_TOXIC) == EFFECT_NON_VOLATILE_STATUS);
        ASSUME(GetMoveNonVolatileStatus(MOVE_TOXIC) == MOVE_EFFECT_TOXIC);
        WITH_CONFIG(B_SYNCHRONIZE_TOXIC, config);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_ABRA) { Ability(ABILITY_SYNCHRONIZE); }
    } WHEN {
        TURN { MOVE(player, MOVE_TOXIC); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TOXIC, player);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PSN, opponent);
        STATUS_ICON(opponent, badPoison: TRUE);
        ABILITY_POPUP(opponent, ABILITY_SYNCHRONIZE);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PSN, player);
        if (config >= GEN_5)
            STATUS_ICON(player, badPoison: TRUE);
        else
            STATUS_ICON(player, poison: TRUE);
    }
}

SINGLE_BATTLE_TEST("Synchronize will still show up the ability pop up even if it fails")
{
    GIVEN {
        WITH_CONFIG(B_PARALYZE_ELECTRIC, GEN_6);
        ASSUME(MoveMakesContact(MOVE_TACKLE));
        PLAYER(SPECIES_PIKACHU) { Ability(ABILITY_STATIC); }
        OPPONENT(SPECIES_ABRA) { Ability(ABILITY_SYNCHRONIZE); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_TACKLE); MOVE(player, MOVE_CELEBRATE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, opponent);
        ABILITY_POPUP(player, ABILITY_STATIC);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PRZ, opponent);
        STATUS_ICON(opponent, paralysis: TRUE);
        ABILITY_POPUP(opponent, ABILITY_SYNCHRONIZE);
        NONE_OF {
            ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PRZ, player);
            STATUS_ICON(player, paralysis: TRUE);
        }
    }
}


SINGLE_BATTLE_TEST("Synchronize will mirror back static activation")
{
    GIVEN {
        ASSUME(MoveMakesContact(MOVE_TACKLE));
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_PIKACHU) { Ability(ABILITY_STATIC); }
        OPPONENT(SPECIES_ABRA) { Ability(ABILITY_SYNCHRONIZE); }
    } WHEN {
        TURN { MOVE(player, MOVE_SKILL_SWAP); }
        TURN { SWITCH(opponent, 1); }
        TURN { MOVE(opponent, MOVE_TACKLE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SKILL_SWAP, player);

        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, opponent);
        ABILITY_POPUP(player, ABILITY_STATIC);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PRZ, opponent);
        STATUS_ICON(opponent, paralysis: TRUE);
        ABILITY_POPUP(opponent, ABILITY_SYNCHRONIZE);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PRZ, player);
        STATUS_ICON(player, paralysis: TRUE);
    }
}

SINGLE_BATTLE_TEST("Synchronize does not inflict status on a target with status immunity ability")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_POISON_GAS) == EFFECT_NON_VOLATILE_STATUS);
        ASSUME(GetMoveNonVolatileStatus(MOVE_POISON_GAS) == MOVE_EFFECT_POISON);
        PLAYER(SPECIES_ABRA) { Ability(ABILITY_SYNCHRONIZE); }
        OPPONENT(SPECIES_SNORLAX) { Ability(ABILITY_IMMUNITY); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_POISON_GAS); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POISON_GAS, opponent);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PSN, player);
        STATUS_ICON(player, poison: TRUE);
        ABILITY_POPUP(player, ABILITY_SYNCHRONIZE);
        NONE_OF {
            ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PSN, opponent);
            STATUS_ICON(opponent, poison: TRUE);
        }
    }
}

SINGLE_BATTLE_TEST("Synchronize does not trigger when holder inflicts status with its own move")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_THUNDER_WAVE) == EFFECT_NON_VOLATILE_STATUS);
        ASSUME(GetMoveNonVolatileStatus(MOVE_THUNDER_WAVE) == MOVE_EFFECT_PARALYSIS);
        PLAYER(SPECIES_ABRA) { Ability(ABILITY_SYNCHRONIZE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_THUNDER_WAVE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_THUNDER_WAVE, player);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PRZ, opponent);
        STATUS_ICON(opponent, paralysis: TRUE);
        NONE_OF {
            ABILITY_POPUP(player, ABILITY_SYNCHRONIZE);
            STATUS_ICON(player, paralysis: TRUE);
        }
    }
}

SINGLE_BATTLE_TEST("Synchronize does not trigger from Toxic Spikes")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_TOXIC_SPIKES) == EFFECT_TOXIC_SPIKES);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_ABRA) { Ability(ABILITY_SYNCHRONIZE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_TOXIC_SPIKES); }
        TURN { SWITCH(player, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TOXIC_SPIKES, opponent);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PSN, player);
        STATUS_ICON(player, poison: TRUE);
        NONE_OF {
            ABILITY_POPUP(player, ABILITY_SYNCHRONIZE);
            STATUS_ICON(opponent, poison: TRUE);
        }
    }
}

SINGLE_BATTLE_TEST("Synchronize does not trigger from Toxic Orb or Flame Orb")
{
    enum Item item;
    u32 status1 = STATUS1_NONE;

    PARAMETRIZE { item = ITEM_TOXIC_ORB; status1 = STATUS1_TOXIC_POISON; }
    PARAMETRIZE { item = ITEM_FLAME_ORB; status1 = STATUS1_BURN; }

    GIVEN {
        ASSUME(gItemsInfo[ITEM_TOXIC_ORB].holdEffect == HOLD_EFFECT_TOXIC_ORB);
        ASSUME(gItemsInfo[ITEM_FLAME_ORB].holdEffect == HOLD_EFFECT_FLAME_ORB);
        PLAYER(SPECIES_ABRA) { Ability(ABILITY_SYNCHRONIZE); Item(item); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {}
    } SCENE {
        STATUS_ICON(player, status1);
        NONE_OF {
            ABILITY_POPUP(player, ABILITY_SYNCHRONIZE);
            STATUS_ICON(opponent, poison: TRUE);
            STATUS_ICON(opponent, burn: TRUE);
        }
    }
}

DOUBLE_BATTLE_TEST("Synchronize will trigger on both targets")
{
    GIVEN {
        ASSUME(MoveHasAdditionalEffect(MOVE_MORTAL_SPIN, MOVE_EFFECT_POISON));
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_LUM_BERRY); }
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_ABRA) { Item(ITEM_LUM_BERRY); Ability(ABILITY_SYNCHRONIZE); }
        OPPONENT(SPECIES_ABRA) { Item(ITEM_LUM_BERRY); Ability(ABILITY_SYNCHRONIZE); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_MORTAL_SPIN); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MORTAL_SPIN, playerLeft);
        HP_BAR(opponentLeft);
        HP_BAR(opponentRight);
        ABILITY_POPUP(opponentLeft, ABILITY_SYNCHRONIZE);
        ABILITY_POPUP(opponentRight, ABILITY_SYNCHRONIZE);
    } THEN {
        EXPECT_EQ(gBattleMons[B_BATTLER_0].status1, STATUS1_POISON);
        EXPECT_EQ(gBattleMons[B_BATTLER_1].status1, STATUS1_NONE);
        EXPECT_EQ(gBattleMons[B_BATTLER_3].status1, STATUS1_NONE);

    }
}

SINGLE_BATTLE_TEST("Synchronize can trigger again during the same attack if user cured it's status")
{
    GIVEN {
        ASSUME(MoveHasAdditionalEffect(MOVE_MORTAL_SPIN, MOVE_EFFECT_POISON));
        ASSUME(MoveMakesContact(MOVE_MORTAL_SPIN));
        PLAYER(SPECIES_SEISMITOAD) { Ability(ABILITY_POISON_TOUCH); Item(ITEM_LUM_BERRY); }
        OPPONENT(SPECIES_ABRA) { Ability(ABILITY_SYNCHRONIZE); Item(ITEM_LUM_BERRY); }
    } WHEN {
        TURN { MOVE(player, MOVE_MORTAL_SPIN); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MORTAL_SPIN, player);

        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PSN, opponent);
        STATUS_ICON(opponent, poison: TRUE);
        ABILITY_POPUP(opponent, ABILITY_SYNCHRONIZE);

        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PSN, player);
        STATUS_ICON(player, poison: TRUE);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_BERRY, player);
        STATUS_ICON(player, poison: FALSE);

        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_BERRY, opponent);
        STATUS_ICON(opponent, poison: FALSE);

        ABILITY_POPUP(player, ABILITY_POISON_TOUCH);
        STATUS_ICON(opponent, poison: TRUE);
        ABILITY_POPUP(opponent, ABILITY_SYNCHRONIZE);
        STATUS_ICON(player, poison: TRUE);
    }
}
