#include "global.h"
#include "test/battle.h"
#include "berry.h"

SINGLE_BATTLE_TEST("Gale Wings only grants priority at full HP (Gen 7+)")
{
    u32 hp, config;
    PARAMETRIZE { hp = 100; config = GEN_7; }
    PARAMETRIZE { hp = 99;  config = GEN_7; }
    PARAMETRIZE { hp = 100; config = GEN_6; }
    PARAMETRIZE { hp = 99;  config = GEN_6; }
    GIVEN {
        WITH_CONFIG(B_GALE_WINGS, config);
        ASSUME(GetMoveType(MOVE_AERIAL_ACE) == TYPE_FLYING);
        PLAYER(SPECIES_TALONFLAME) { Ability(ABILITY_GALE_WINGS); HP(hp); MaxHP(100); Speed(1); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(100); }
    } WHEN {
        TURN { MOVE(player, MOVE_AERIAL_ACE); }
    } SCENE {
        if (hp == 100 || config <= GEN_6) {
            MESSAGE("Talonflame used Aerial Ace!");
            MESSAGE("The opposing Wobbuffet used Celebrate!");
        }
        else {
            MESSAGE("The opposing Wobbuffet used Celebrate!");
            MESSAGE("Talonflame used Aerial Ace!");
        }
    }
}

SINGLE_BATTLE_TEST("Gale Wings only grants priority to Flying-type moves")
{
    enum Move move;
    PARAMETRIZE { move = MOVE_AERIAL_ACE; }
    PARAMETRIZE { move = MOVE_FLARE_BLITZ; }
    GIVEN {
        ASSUME(GetMoveType(MOVE_AERIAL_ACE) == TYPE_FLYING);
        ASSUME(GetMoveType(MOVE_FLARE_BLITZ) == TYPE_FIRE);
        PLAYER(SPECIES_TALONFLAME) { Ability(ABILITY_GALE_WINGS); HP(100); MaxHP(100); Speed(1); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(100); }
    } WHEN {
        TURN { MOVE(player, move); }
    } SCENE {
        if (move == MOVE_AERIAL_ACE) {
            MESSAGE("Talonflame used Aerial Ace!");
            MESSAGE("The opposing Wobbuffet used Celebrate!");
        }
        else {
            MESSAGE("The opposing Wobbuffet used Celebrate!");
            MESSAGE("Talonflame used Flare Blitz!");
        }
    }
}

SINGLE_BATTLE_TEST("Gale Wings doesn't increase priority of Flying-type Natural Gift, Judgment, Hidden Power, or Tera Blast")
{
    enum Move move;
    enum Item heldItem;
    PARAMETRIZE { move = MOVE_NATURAL_GIFT; heldItem = ITEM_LUM_BERRY; }
    PARAMETRIZE { move = MOVE_JUDGMENT; heldItem = ITEM_SKY_PLATE; }
    PARAMETRIZE { move = MOVE_HIDDEN_POWER; heldItem = ITEM_NONE; }
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_NATURAL_GIFT) == EFFECT_NATURAL_GIFT);
        ASSUME(GetMoveEffect(MOVE_JUDGMENT) == EFFECT_CHANGE_TYPE_ON_ITEM);
        // IV combinations sourced from https://www.smogon.com/forums/threads/hidden-power-iv-combinations.78083/
        ASSUME(GetMoveEffect(MOVE_HIDDEN_POWER) == EFFECT_HIDDEN_POWER);
        ASSUME(GetMoveEffect(MOVE_TERA_BLAST) == EFFECT_TERA_BLAST);
        ASSUME(gItemsInfo[ITEM_SKY_PLATE].holdEffect == HOLD_EFFECT_PLATE);
        ASSUME(gItemsInfo[ITEM_SKY_PLATE].secondaryId == TYPE_FLYING);
        ASSUME(gBerries[ItemIdToBerryType(ITEM_LUM_BERRY)].naturalGiftType == TYPE_FLYING);
        OPPONENT(SPECIES_TALONFLAME) { Ability(ABILITY_GALE_WINGS); Speed(1); Item(heldItem); HPIV(31); AttackIV(3); DefenseIV(31); SpAttackIV(30); SpDefenseIV(30); SpeedIV(30); TeraType(TYPE_FLYING); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(100); }
    } WHEN {
        TURN { MOVE(opponent, move); }
    } SCENE {
            MESSAGE("Wobbuffet used Celebrate!");
        if (move == MOVE_NATURAL_GIFT) {
            MESSAGE("The opposing Talonflame used Natural Gift!");
        }
        else if (move == MOVE_JUDGMENT) {
            MESSAGE("The opposing Talonflame used Judgment!");
        }
        else if (move == MOVE_HIDDEN_POWER) {
            MESSAGE("The opposing Talonflame used Hidden Power!");
        }
        else {
            MESSAGE("The opposing Talonflame used Tera Blast!");
        }
    }
}
