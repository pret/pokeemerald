#include "global.h"
#include "test/battle.h"

// Please add Hail interactions with move, item and ability effects on their respective files.
ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_HAIL) == EFFECT_WEATHER);
    ASSUME(GetMoveWeatherType(MOVE_HAIL) == BATTLE_WEATHER_HAIL);
    ASSUME(GetSpeciesType(SPECIES_WOBBUFFET, 0) != TYPE_ICE && GetSpeciesType(SPECIES_WOBBUFFET, 1) != TYPE_ICE);
    ASSUME(GetSpeciesType(SPECIES_WYNAUT, 0) != TYPE_ICE && GetSpeciesType(SPECIES_WYNAUT, 1) != TYPE_ICE);
    ASSUME(GetSpeciesType(SPECIES_GLALIE, 0) == TYPE_ICE || GetSpeciesType(SPECIES_GLALIE, 1) == TYPE_ICE);
}

SINGLE_BATTLE_TEST("Hail deals 1/16 damage per turn")
{
    s16 hailDamage;

    GIVEN {
        PLAYER(SPECIES_GLALIE);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_HAIL); }
    } SCENE {
        MESSAGE("The opposing Wobbuffet is buffeted by the hail!");
        HP_BAR(opponent, captureDamage: &hailDamage);
   } THEN { EXPECT_EQ(hailDamage, opponent->maxHP / 16); }
}

SINGLE_BATTLE_TEST("Hail damage does not affect Ice-type Pokémon")
{
    GIVEN {
        ASSUME(GetSpeciesType(SPECIES_GLALIE, 0) == TYPE_ICE);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_GLALIE);
    } WHEN {
        TURN { MOVE(player, MOVE_HAIL); }
    } SCENE {
        NOT MESSAGE("The opposing Glalie is buffeted by the hail!");
    }
}

SINGLE_BATTLE_TEST("Hail fails if Desolate Land or Primordial Sea are active")
{
    enum Species species;
    enum Item item;

    PARAMETRIZE { species = SPECIES_WOBBUFFET; item = ITEM_NONE; }
    PARAMETRIZE { species = SPECIES_GROUDON; item = ITEM_RED_ORB; }
    PARAMETRIZE { species = SPECIES_KYOGRE; item = ITEM_BLUE_ORB; }

    GIVEN {
        PLAYER(species) { Item(item); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_HAIL); }
    } SCENE {
        if (item == ITEM_RED_ORB || item == ITEM_BLUE_ORB) {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_PRIMAL_REVERSION, player);
            NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_HAIL, opponent);
        } else {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_HAIL, opponent);
        }
    }
}

DOUBLE_BATTLE_TEST("Hail deals damage based on turn order")
{
    GIVEN {
        PLAYER(SPECIES_GLALIE) { Speed(4); }
        PLAYER(SPECIES_WYNAUT) { Speed(1); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(2); }
        OPPONENT(SPECIES_WYNAUT) { Speed(3); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_HAIL); }
    } SCENE {
        NOT HP_BAR(playerLeft);
        HP_BAR(opponentRight);
        HP_BAR(opponentLeft);
        HP_BAR(playerRight);
   }
}

SINGLE_BATTLE_TEST("Hail damage rounds properly when maxHP < 16")
{
    GIVEN {
        PLAYER(SPECIES_MAGIKARP) { Level(1); MaxHP(11); HP(11); }
        OPPONENT(SPECIES_GLALIE);
    } WHEN {
        TURN { MOVE(opponent, MOVE_HAIL); }
    } SCENE {
        HP_BAR(player, damage: 1);
    }
}

SINGLE_BATTLE_TEST("Hail doesn't do damage when weather is negated")
{
    GIVEN {
        ASSUME(GetSpeciesType(SPECIES_WOBBUFFET, 0) != TYPE_ICE);
        ASSUME(GetSpeciesType(SPECIES_WOBBUFFET, 1) != TYPE_ICE);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_GOLDUCK) { Ability(ABILITY_CLOUD_NINE); }
    } WHEN {
        TURN { MOVE(player, MOVE_HAIL); }
    } SCENE {
        NOT HP_BAR(player);
    }
}
