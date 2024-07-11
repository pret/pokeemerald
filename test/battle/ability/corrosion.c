#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Corrosion can poison or badly poison a Pokemon regardless of its typing")
{
    u16 species;

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
    u16 move;

    PARAMETRIZE { move = MOVE_POISON_POWDER; }
    PARAMETRIZE { move = MOVE_TOXIC; }

    GIVEN {
        ASSUME(gMovesInfo[MOVE_POISON_POWDER].effect == EFFECT_POISON);
        ASSUME(gMovesInfo[MOVE_TOXIC].effect == EFFECT_TOXIC);
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

SINGLE_BATTLE_TEST("Corrosion can poison Poison- and Steel-type targets if it uses Fling while holding a Toxic Orb or a Poison Barb")
{
    u16 heldItem;

    PARAMETRIZE { heldItem = ITEM_POISON_BARB; }
    PARAMETRIZE { heldItem = ITEM_TOXIC_ORB; }

    GIVEN {
        ASSUME(gMovesInfo[MOVE_FLING].effect == EFFECT_FLING);
        ASSUME(gItemsInfo[ITEM_POISON_BARB].holdEffect == HOLD_EFFECT_POISON_POWER);
        ASSUME(gItemsInfo[ITEM_TOXIC_ORB].holdEffect == HOLD_EFFECT_TOXIC_ORB);
        PLAYER(SPECIES_SALANDIT) { Ability(ABILITY_CORROSION); Item(heldItem); }
        OPPONENT(SPECIES_ODDISH);
    } WHEN {
        TURN { MOVE(player, MOVE_FLING); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FLING, player);
        HP_BAR(opponent);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PSN, opponent);
        if (heldItem == ITEM_POISON_BARB)
            STATUS_ICON(opponent, poison: TRUE);
        else
            STATUS_ICON(opponent, badPoison: TRUE);
    }
}

SINGLE_BATTLE_TEST("If a Poison- or Steel-type Pokémon with Corrosion holds a Toxic Orb, it will badly poison itself")
{
    GIVEN {
        ASSUME(gItemsInfo[ITEM_TOXIC_ORB].holdEffect == HOLD_EFFECT_TOXIC_ORB);
        PLAYER(SPECIES_SALANDIT) { Ability(ABILITY_CORROSION); Item(ITEM_TOXIC_ORB); }
        OPPONENT(SPECIES_ODDISH);
    } WHEN {
        TURN { }
    } SCENE {
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PSN, player);
        STATUS_ICON(player, badPoison: TRUE);
    }
}

SINGLE_BATTLE_TEST("If a Poison- or Steel-type Pokémon with Corrosion poisons a target with Synchronize, Synchronize will not poison Poison- or Steel-type Pokémon")
{
    u16 move;
    PARAMETRIZE { move = MOVE_TOXIC; }
    PARAMETRIZE { move = MOVE_POISON_POWDER; }
    GIVEN {
        ASSUME(gMovesInfo[MOVE_TOXIC].effect == EFFECT_TOXIC);
        ASSUME(gMovesInfo[MOVE_POISON_POWDER].effect == EFFECT_POISON);
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
    u16 move;
    PARAMETRIZE { move = MOVE_TOXIC; }
    PARAMETRIZE { move = MOVE_POISON_POWDER; }
    GIVEN {
        ASSUME(gMovesInfo[MOVE_TOXIC].effect == EFFECT_TOXIC);
        ASSUME(gMovesInfo[MOVE_POISON_POWDER].effect == EFFECT_POISON);
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
    u16 move;
    PARAMETRIZE { move = MOVE_TOXIC; }
    PARAMETRIZE { move = MOVE_POISON_POWDER; }
    GIVEN {
        ASSUME(gMovesInfo[MOVE_TOXIC].effect == EFFECT_TOXIC);
        ASSUME(gMovesInfo[MOVE_POISON_POWDER].effect == EFFECT_POISON);
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
    u16 move;
    PARAMETRIZE { move = MOVE_TOXIC; }
    PARAMETRIZE { move = MOVE_POISON_POWDER; }
    GIVEN {
        ASSUME(gMovesInfo[MOVE_TOXIC].effect == EFFECT_TOXIC);
        ASSUME(gMovesInfo[MOVE_POISON_POWDER].effect == EFFECT_POISON);
        ASSUME(gMovesInfo[MOVE_MAGIC_COAT].effect == EFFECT_MAGIC_COAT);
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
    u16 move;
    PARAMETRIZE { move = MOVE_TOXIC; }
    PARAMETRIZE { move = MOVE_POISON_POWDER; }
    GIVEN {
        ASSUME(gMovesInfo[MOVE_TOXIC].effect == EFFECT_TOXIC);
        ASSUME(gMovesInfo[MOVE_POISON_POWDER].effect == EFFECT_POISON);
        ASSUME(gMovesInfo[MOVE_MAGIC_COAT].effect == EFFECT_MAGIC_COAT);
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
