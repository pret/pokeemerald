#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Poison Puppeteer confuses target if it was poisoned by a damaging move")
{
    GIVEN {
        ASSUME(MoveHasAdditionalEffect(MOVE_POISON_STING, MOVE_EFFECT_POISON) == TRUE);
        PLAYER(SPECIES_PECHARUNT) { Ability(ABILITY_POISON_PUPPETEER); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_POISON_STING); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POISON_STING, player);
        HP_BAR(opponent);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PSN, opponent);
        STATUS_ICON(opponent, poison: TRUE);
        ABILITY_POPUP(player, ABILITY_POISON_PUPPETEER);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_CONFUSION, opponent);
        MESSAGE("The opposing Wobbuffet became confused!");
    }
}

SINGLE_BATTLE_TEST("Poison Puppeteer confuses target if it was (badly) poisoned by a status move")
{
    enum Move move;

    PARAMETRIZE { move = MOVE_POISON_POWDER; }
    PARAMETRIZE { move = MOVE_TOXIC; }

    GIVEN {
        ASSUME(MoveHasAdditionalEffect(MOVE_POISON_STING, MOVE_EFFECT_POISON) == TRUE);
        PLAYER(SPECIES_PECHARUNT) { Ability(ABILITY_POISON_PUPPETEER); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, player);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PSN, opponent);
        if (move == MOVE_POISON_POWDER)
            STATUS_ICON(opponent, poison: TRUE);
        else
            STATUS_ICON(opponent, badPoison: TRUE);
        ABILITY_POPUP(player, ABILITY_POISON_PUPPETEER);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_CONFUSION, opponent);
        MESSAGE("The opposing Wobbuffet became confused!");
    }
}

SINGLE_BATTLE_TEST("Poison Puppeteer does not trigger if poison is Toxic Spikes induced")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_TOXIC_SPIKES) == EFFECT_TOXIC_SPIKES);
        PLAYER(SPECIES_PECHARUNT) { Ability(ABILITY_POISON_PUPPETEER); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_TOXIC_SPIKES); }
        TURN { SWITCH(opponent, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TOXIC_SPIKES, player);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PSN, opponent);
        STATUS_ICON(opponent, poison: TRUE);
        NONE_OF {
            ABILITY_POPUP(player, ABILITY_POISON_PUPPETEER);
            ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_CONFUSION, opponent);
            MESSAGE("The opposing Wobbuffet became confused!");
        }
    }
}

SINGLE_BATTLE_TEST("Poison Puppeteer does not trigger when poison came from Poison Point")
{
    GIVEN {
        ASSUME(MoveMakesContact(MOVE_SCRATCH));
        ASSUME(GetMoveEffect(MOVE_SOAK) == EFFECT_SOAK);
        ASSUME(GetMoveArgType(MOVE_SOAK) == TYPE_WATER);
        ASSUME(GetSpeciesType(SPECIES_SKRELP, 0) == TYPE_POISON || GetSpeciesType(SPECIES_SKRELP, 1) == TYPE_POISON);
        PLAYER(SPECIES_PECHARUNT) { Ability(ABILITY_POISON_PUPPETEER); }
        OPPONENT(SPECIES_SKRELP) { Ability(ABILITY_POISON_POINT); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SOAK); }
        TURN { MOVE(player, MOVE_SCRATCH, WITH_RNG(RNG_POISON_POINT, TRUE)); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SOAK, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        HP_BAR(opponent);
        ABILITY_POPUP(opponent, ABILITY_POISON_POINT);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PSN, player);
        STATUS_ICON(player, poison: TRUE);
        NONE_OF {
            ABILITY_POPUP(player, ABILITY_POISON_PUPPETEER);
            ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_CONFUSION, opponent);
        }
    } THEN {
        EXPECT_EQ(player->types[0], TYPE_WATER);
        EXPECT_EQ(player->types[1], TYPE_WATER);
        EXPECT(player->status1 & STATUS1_POISON);
        EXPECT(opponent->volatiles.confusionTimer == 0);
    }
}

SINGLE_BATTLE_TEST("Poison Puppeteer confuses target (not user) after Flame Body also triggers")
{
    GIVEN {
        ASSUME(MoveMakesContact(MOVE_MORTAL_SPIN));
        ASSUME(MoveHasAdditionalEffect(MOVE_MORTAL_SPIN, MOVE_EFFECT_POISON));
        PLAYER(SPECIES_PECHARUNT) { Ability(ABILITY_POISON_PUPPETEER); }
        OPPONENT(SPECIES_MOLTRES) { Ability(ABILITY_FLAME_BODY); }
    } WHEN {
        TURN { MOVE(player, MOVE_MORTAL_SPIN, WITH_RNG(RNG_FLAME_BODY, TRUE)); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MORTAL_SPIN, player);
        HP_BAR(opponent);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PSN, opponent);
        STATUS_ICON(opponent, poison: TRUE);

        ABILITY_POPUP(opponent, ABILITY_FLAME_BODY);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_BRN, player);
        STATUS_ICON(player, burn: TRUE);

        ABILITY_POPUP(player, ABILITY_POISON_PUPPETEER);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_CONFUSION, opponent);
        NOT ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_CONFUSION, player);
    } THEN {
        EXPECT(player->status1 & STATUS1_BURN);
        EXPECT(opponent->status1 & STATUS1_POISON);
        EXPECT(player->volatiles.confusionTimer == 0);
        EXPECT(opponent->volatiles.confusionTimer > 0);
    }
}

SINGLE_BATTLE_TEST("Poison Puppeteer consumes its pending target after triggering")
{
    GIVEN {
        ASSUME(GetMoveStrikeCount(MOVE_TWINEEDLE) == 2);
        ASSUME(MoveHasAdditionalEffect(MOVE_TWINEEDLE, MOVE_EFFECT_POISON));
        ASSUME(gItemsInfo[ITEM_PERSIM_BERRY].holdEffect == HOLD_EFFECT_CURE_CONFUSION);
        PLAYER(SPECIES_PECHARUNT) { Ability(ABILITY_POISON_PUPPETEER); }
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_PERSIM_BERRY); }
    } WHEN {
        TURN { MOVE(player, MOVE_TWINEEDLE, WITH_RNG(RNG_SECONDARY_EFFECT, TRUE)); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TWINEEDLE, player);
        HP_BAR(opponent);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PSN, opponent);
        STATUS_ICON(opponent, poison: TRUE);

        ABILITY_POPUP(player, ABILITY_POISON_PUPPETEER);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_CONFUSION, opponent);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_BERRY, opponent);

        ANIMATION(ANIM_TYPE_MOVE, MOVE_TWINEEDLE, player);
        HP_BAR(opponent);
        NONE_OF {
            ABILITY_POPUP(player, ABILITY_POISON_PUPPETEER);
            ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_CONFUSION, opponent);
        }
    } THEN {
        EXPECT_EQ(opponent->item, ITEM_NONE);
        EXPECT(opponent->status1 & STATUS1_POISON);
        EXPECT(opponent->volatiles.confusionTimer == 0);
    }
}

DOUBLE_BATTLE_TEST("Poison Puppeteer does not leak confusion to second target")
{
    GIVEN {
        ASSUME(MoveMakesContact(MOVE_MORTAL_SPIN));
        ASSUME(MoveHasAdditionalEffect(MOVE_MORTAL_SPIN, MOVE_EFFECT_POISON));
        ASSUME(GetSpeciesType(SPECIES_FERROSEED, 0) == TYPE_STEEL || GetSpeciesType(SPECIES_FERROSEED, 1) == TYPE_STEEL);
        PLAYER(SPECIES_PECHARUNT) { Ability(ABILITY_POISON_PUPPETEER); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_SLOWBRO) { Ability(ABILITY_OWN_TEMPO); } // can be poisoned, cannot be confused
        OPPONENT(SPECIES_FERROSEED); // Steel-type, cannot be poisoned, can be confused
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_MORTAL_SPIN); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MORTAL_SPIN, playerLeft);
        HP_BAR(opponentLeft);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PSN, opponentLeft);
        NONE_OF {
            ABILITY_POPUP(playerLeft, ABILITY_POISON_PUPPETEER);
            ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_CONFUSION, opponentRight);
        }
    } THEN {
        EXPECT(opponentLeft->status1 & STATUS1_POISON);
        EXPECT_EQ(opponentRight->status1, STATUS1_NONE);
        EXPECT(opponentLeft->volatiles.confusionTimer == 0);
        EXPECT(opponentRight->volatiles.confusionTimer == 0);
    }
}
