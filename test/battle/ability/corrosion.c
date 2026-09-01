#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Corrosion can poison or badly poison a Pokemon regardless of its typing")
{
    enum Species species;

    PARAMETRIZE { species = SPECIES_ODDISH; }
    PARAMETRIZE { species = SPECIES_BELDUM; }

    GIVEN {
        ASSUME(MoveHasAdditionalEffect(MOVE_TWINEEDLE, MOVE_EFFECT_POISON) == TRUE);
        PLAYER(SPECIES_SALANDIT) { Ability(ABILITY_CORROSION); }
        OPPONENT(species);
    } WHEN {
        TURN { MOVE(player, MOVE_TWINEEDLE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TWINEEDLE, player);
        HP_BAR(opponent);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PSN, opponent);
        STATUS_ICON(opponent, poison: TRUE);
    }
}

SINGLE_BATTLE_TEST("Corrosion can poison or badly poison a Steel type with a status poison effect")
{
    enum Move move;

    PARAMETRIZE { move = MOVE_POISON_POWDER; }
    PARAMETRIZE { move = MOVE_TOXIC; }

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_POISON_POWDER) == EFFECT_NON_VOLATILE_STATUS);
        ASSUME(GetMoveNonVolatileStatus(MOVE_POISON_POWDER) == MOVE_EFFECT_POISON);
        ASSUME(GetMoveEffect(MOVE_TOXIC) == EFFECT_NON_VOLATILE_STATUS);
        ASSUME(GetMoveNonVolatileStatus(MOVE_TOXIC) == MOVE_EFFECT_TOXIC);
        PLAYER(SPECIES_SALANDIT) { Ability(ABILITY_CORROSION); }
        OPPONENT(SPECIES_BELDUM);
    } WHEN {
        TURN { MOVE(player, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, player);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PSN, opponent);
        if (move == MOVE_POISON_POWDER)
            STATUS_ICON(opponent, poison: TRUE);
        else
            STATUS_ICON(opponent, badPoison: TRUE);
    }
}

SINGLE_BATTLE_TEST("Corrosion does not effect poison type damaging moves if the target is immune to it")
{
    GIVEN {
        ASSUME(MoveHasAdditionalEffect(MOVE_SLUDGE_BOMB, MOVE_EFFECT_POISON) == TRUE);
        PLAYER(SPECIES_SALANDIT) { Ability(ABILITY_CORROSION); }
        OPPONENT(SPECIES_BELDUM);
    } WHEN {
        TURN { MOVE(player, MOVE_SLUDGE_BOMB); }
    } SCENE {
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_SLUDGE_BOMB, player);
            HP_BAR(opponent);
            ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PSN, opponent);
            STATUS_ICON(opponent, poison: TRUE);
        }
    }
}

SINGLE_BATTLE_TEST("Corrosion badly poisons its Poison/Steel-type user who holds a Toxic Orb")
{
    GIVEN {
        ASSUME(gItemsInfo[ITEM_TOXIC_ORB].holdEffect == HOLD_EFFECT_TOXIC_ORB);
        PLAYER(SPECIES_SALANDIT) { Ability(ABILITY_CORROSION); Item(ITEM_TOXIC_ORB); }
        OPPONENT(SPECIES_ODDISH);
    } WHEN {
        TURN {}
    } SCENE {
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PSN, player);
        STATUS_ICON(player, badPoison: TRUE);
    }
}

SINGLE_BATTLE_TEST("Corrosion can poison a target with Synchronize and Synchronize will not poison Poison- or Steel-type Pokémon")
{
    enum Move move;
    PARAMETRIZE { move = MOVE_TOXIC; }
    PARAMETRIZE { move = MOVE_POISON_POWDER; }
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_TOXIC) == EFFECT_NON_VOLATILE_STATUS);
        ASSUME(GetMoveNonVolatileStatus(MOVE_TOXIC) == MOVE_EFFECT_TOXIC);
        ASSUME(GetMoveEffect(MOVE_POISON_POWDER) == EFFECT_NON_VOLATILE_STATUS);
        ASSUME(GetMoveNonVolatileStatus(MOVE_POISON_POWDER) == MOVE_EFFECT_POISON);
        PLAYER(SPECIES_SALANDIT) { Ability(ABILITY_CORROSION); }
        OPPONENT(SPECIES_ABRA) { Ability(ABILITY_SYNCHRONIZE); }
    } WHEN {
        TURN { MOVE(player, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, player);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PSN, opponent);
        if (move == MOVE_TOXIC)
            STATUS_ICON(opponent, badPoison: TRUE);
        else
            STATUS_ICON(opponent, poison: TRUE);
        NONE_OF {
            ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PSN, player);
            STATUS_ICON(player, badPoison: TRUE);
            STATUS_ICON(player, poison: TRUE);
        }
    }
}

SINGLE_BATTLE_TEST("Corrosion cannot bypass moves that prevent poisoning such as Safeguard")
{
    enum Move move;
    PARAMETRIZE { move = MOVE_TOXIC; }
    PARAMETRIZE { move = MOVE_POISON_POWDER; }
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_TOXIC) == EFFECT_NON_VOLATILE_STATUS);
        ASSUME(GetMoveNonVolatileStatus(MOVE_TOXIC) == MOVE_EFFECT_TOXIC);
        ASSUME(GetMoveEffect(MOVE_POISON_POWDER) == EFFECT_NON_VOLATILE_STATUS);
        ASSUME(GetMoveNonVolatileStatus(MOVE_POISON_POWDER) == MOVE_EFFECT_POISON);
        PLAYER(SPECIES_SALANDIT) { Ability(ABILITY_CORROSION); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SAFEGUARD); MOVE(player, move); }
    } SCENE {
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_TOXIC, player);
            ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PSN, opponent);
            STATUS_ICON(opponent, badPoison: TRUE);
            STATUS_ICON(opponent, poison: TRUE);
        }
    }
}

SINGLE_BATTLE_TEST("Corrosion cannot bypass abilities that prevent poisoning such as Immunity")
{
    enum Move move;
    PARAMETRIZE { move = MOVE_TOXIC; }
    PARAMETRIZE { move = MOVE_POISON_POWDER; }
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_TOXIC) == EFFECT_NON_VOLATILE_STATUS);
        ASSUME(GetMoveNonVolatileStatus(MOVE_TOXIC) == MOVE_EFFECT_TOXIC);
        ASSUME(GetMoveEffect(MOVE_POISON_POWDER) == EFFECT_NON_VOLATILE_STATUS);
        ASSUME(GetMoveNonVolatileStatus(MOVE_POISON_POWDER) == MOVE_EFFECT_POISON);
        PLAYER(SPECIES_SALANDIT) { Ability(ABILITY_CORROSION); }
        OPPONENT(SPECIES_SNORLAX) { Ability(ABILITY_IMMUNITY); }
    } WHEN {
        TURN { MOVE(player, move); }
    } SCENE {
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_TOXIC, player);
            ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PSN, opponent);
            STATUS_ICON(opponent, badPoison: TRUE);
            STATUS_ICON(opponent, poison: TRUE);
        }
    }
}

SINGLE_BATTLE_TEST("Corrosion allows the Pokémon with the ability to poison a Steel or Poison-type opponent by using Magic Coat")
{
    enum Move move;
    PARAMETRIZE { move = MOVE_TOXIC; }
    PARAMETRIZE { move = MOVE_POISON_POWDER; }
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_TOXIC) == EFFECT_NON_VOLATILE_STATUS);
        ASSUME(GetMoveNonVolatileStatus(MOVE_TOXIC) == MOVE_EFFECT_TOXIC);
        ASSUME(GetMoveEffect(MOVE_POISON_POWDER) == EFFECT_NON_VOLATILE_STATUS);
        ASSUME(GetMoveNonVolatileStatus(MOVE_POISON_POWDER) == MOVE_EFFECT_POISON);
        ASSUME(GetMoveEffect(MOVE_MAGIC_COAT) == EFFECT_MAGIC_COAT);
        PLAYER(SPECIES_SALANDIT) { Ability(ABILITY_CORROSION); }
        OPPONENT(SPECIES_BELDUM);
    } WHEN {
        TURN { MOVE(player, MOVE_MAGIC_COAT); MOVE(opponent, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MAGIC_COAT, player);
        ANIMATION(ANIM_TYPE_MOVE, move, player); // Bounced by Magic Coat
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PSN, opponent);
        if (move == MOVE_TOXIC)
            STATUS_ICON(opponent, badPoison: TRUE);
        else
            STATUS_ICON(opponent, poison: TRUE);
    }
}

SINGLE_BATTLE_TEST("Corrosion's effect is lost if the move used by the Pokémon with the ability is reflected by Magic Coat")
{
    enum Move move;
    PARAMETRIZE { move = MOVE_TOXIC; }
    PARAMETRIZE { move = MOVE_POISON_POWDER; }
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_TOXIC) == EFFECT_NON_VOLATILE_STATUS);
        ASSUME(GetMoveNonVolatileStatus(MOVE_TOXIC) == MOVE_EFFECT_TOXIC);
        ASSUME(GetMoveEffect(MOVE_POISON_POWDER) == EFFECT_NON_VOLATILE_STATUS);
        ASSUME(GetMoveNonVolatileStatus(MOVE_POISON_POWDER) == MOVE_EFFECT_POISON);
        ASSUME(GetMoveEffect(MOVE_MAGIC_COAT) == EFFECT_MAGIC_COAT);
        PLAYER(SPECIES_SALANDIT) { Ability(ABILITY_CORROSION); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_MAGIC_COAT); MOVE(player, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MAGIC_COAT, opponent);
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, move, player);
            ANIMATION(ANIM_TYPE_MOVE, move, opponent);
            ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PSN, player);
        if (move == MOVE_TOXIC)
            STATUS_ICON(opponent, badPoison: TRUE);
        else
            STATUS_ICON(opponent, poison: TRUE);
        }
    }
}

SINGLE_BATTLE_TEST("Corrosion can poison Poison/Steel types if the Pokémon uses Baneful Bunker")
{
    enum Species species;

    PARAMETRIZE { species = SPECIES_ODDISH; }
    PARAMETRIZE { species = SPECIES_BELDUM; }

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_BANEFUL_BUNKER) == EFFECT_PROTECT);
        ASSUME(MoveMakesContact(MOVE_SCRATCH));
        PLAYER(SPECIES_SALANDIT) { Ability(ABILITY_CORROSION); }
        OPPONENT(species);
    } WHEN {
        TURN { MOVE(player, MOVE_BANEFUL_BUNKER); MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BANEFUL_BUNKER, player);
        MESSAGE("Salandit protected itself!");
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        MESSAGE("Salandit protected itself!");
        STATUS_ICON(opponent, poison: TRUE);
    }
}

SINGLE_BATTLE_TEST("Corrosion can poison Poison/Steel types if the Pokémon uses Psycho Shift while poisoned")
{
    enum Species species;

    PARAMETRIZE { species = SPECIES_ODDISH; }
    PARAMETRIZE { species = SPECIES_BELDUM; }

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_PSYCHO_SHIFT) == EFFECT_PSYCHO_SHIFT);
        PLAYER(SPECIES_SALANDIT) { Ability(ABILITY_CORROSION); Status1(STATUS1_POISON); }
        OPPONENT(species);
    } WHEN {
        TURN { MOVE(player, MOVE_PSYCHO_SHIFT); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PSYCHO_SHIFT, player);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PSN, opponent);
        STATUS_ICON(opponent, poison: TRUE);
        STATUS_ICON(player, none: TRUE);
    }
}

SINGLE_BATTLE_TEST("Corrosion can poison Poison/Steel types if the Pokémon uses Fling while holding a Toxic Orb")
{
    enum Species species;

    PARAMETRIZE { species = SPECIES_ODDISH; }
    PARAMETRIZE { species = SPECIES_BELDUM; }

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_FLING) == EFFECT_FLING);
        ASSUME(gItemsInfo[ITEM_TOXIC_ORB].holdEffect == HOLD_EFFECT_TOXIC_ORB);
        PLAYER(SPECIES_SALANDIT) { Ability(ABILITY_CORROSION); Item(ITEM_TOXIC_ORB); }
        OPPONENT(species);
    } WHEN {
        TURN { MOVE(player, MOVE_FLING); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FLING, player);
        HP_BAR(opponent);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PSN, opponent);
        STATUS_ICON(opponent, badPoison: TRUE);
    }
}

SINGLE_BATTLE_TEST("Corrosion can poison Poison/Steel types if the Pokémon uses Fling while holding a Poison Barb")
{
    enum Species species;

    PARAMETRIZE { species = SPECIES_ODDISH; }
    PARAMETRIZE { species = SPECIES_BELDUM; }

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_FLING) == EFFECT_FLING);
        ASSUME(gItemsInfo[ITEM_POISON_BARB].holdEffect == HOLD_EFFECT_TYPE_POWER);
        ASSUME(gItemsInfo[ITEM_POISON_BARB].secondaryId == TYPE_POISON);
        PLAYER(SPECIES_SALANDIT) { Ability(ABILITY_CORROSION); Item(ITEM_POISON_BARB); }
        OPPONENT(species);
    } WHEN {
        TURN { MOVE(player, MOVE_FLING); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FLING, player);
        HP_BAR(opponent);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PSN, opponent);
        STATUS_ICON(opponent, poison: TRUE);
    }
}

SINGLE_BATTLE_TEST("Corrosion does not affect Poison Spikes")
{
    enum Species species;

    PARAMETRIZE { species = SPECIES_ODDISH; }
    PARAMETRIZE { species = SPECIES_BELDUM; }

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_TOXIC_SPIKES) == EFFECT_TOXIC_SPIKES);
        PLAYER(SPECIES_SALANDIT) { Ability(ABILITY_CORROSION); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(species);
    } WHEN {
        TURN { MOVE(player, MOVE_TOXIC_SPIKES); }
        TURN { SWITCH(opponent, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TOXIC_SPIKES, player);
    } THEN {
        EXPECT_EQ(opponent->status1, STATUS1_NONE);
    }
}

SINGLE_BATTLE_TEST("Corrosion does not make Toxic Spikes poison a Corrosion user Terastallized into Steel")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_TOXIC_SPIKES) == EFFECT_TOXIC_SPIKES);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_SALANDIT) { Ability(ABILITY_CORROSION); TeraType(TYPE_STEEL); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_TOXIC_SPIKES); MOVE(opponent, MOVE_CELEBRATE, gimmick: GIMMICK_TERA); }
        TURN { SWITCH(opponent, 1); }
        TURN { SWITCH(opponent, 0); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TOXIC_SPIKES, player);
    } THEN {
        EXPECT_EQ(opponent->status1, STATUS1_NONE);
    }
}

TO_DO_BATTLE_TEST("Dynamax: Corrosion can poison Poison/Steel types if the Pokémon uses G-Max Malodor")
