#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Corrosion can poison or badly poison a Pokemon regardless of its typing")
{
    u16 species;

    PARAMETRIZE { species = SPECIES_ODDISH; }
    PARAMETRIZE { species = SPECIES_BELDUM; }

    GIVEN {
        ASSUME(gBattleMoves[MOVE_TWINEEDLE].effect == EFFECT_POISON_HIT);
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
        ASSUME(gBattleMoves[MOVE_POISON_POWDER].effect == EFFECT_POISON);
        ASSUME(gBattleMoves[MOVE_TOXIC].effect == EFFECT_TOXIC);
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
        ASSUME(gBattleMoves[MOVE_SLUDGE_BOMB].effect == EFFECT_POISON_HIT);
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
        ASSUME(gBattleMoves[MOVE_FLING].effect == EFFECT_FLING);
        ASSUME(gItems[ITEM_POISON_BARB].holdEffect == HOLD_EFFECT_POISON_POWER);
        ASSUME(gItems[ITEM_TOXIC_ORB].holdEffect == HOLD_EFFECT_TOXIC_ORB);
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
        ASSUME(gItems[ITEM_TOXIC_ORB].holdEffect == HOLD_EFFECT_TOXIC_ORB);
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
    GIVEN {
        ASSUME(gBattleMoves[MOVE_TOXIC].effect == EFFECT_TOXIC);
        PLAYER(SPECIES_SALANDIT) { Ability(ABILITY_CORROSION); }
        OPPONENT(SPECIES_ABRA) { Ability(ABILITY_SYNCHRONIZE); }
    } WHEN {
        TURN { MOVE(player, MOVE_TOXIC); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TOXIC, player);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PSN, opponent);
        STATUS_ICON(opponent, badPoison: TRUE);
        NONE_OF {
            ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PSN, player);
            STATUS_ICON(player, badPoison: TRUE);
        }
    }
}

TO_DO_BATTLE_TEST("Corrosion cannot bypass moves or Abilities that prevent poisoning, such as Safeguard or Immunity");
TO_DO_BATTLE_TEST("If the Pokémon with this Ability uses Magic Coat to reflect a status move that inflicts poison, the reflected move will be able to poison Poison- or Steel-type Pokémon.");
TO_DO_BATTLE_TEST("Moves used by a Pokémon with Corrosion that are reflected by Magic Coat or Magic Bounce do not retain the ability to poison Poison- or Steel-type Pokémon.")
