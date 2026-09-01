#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveCategory(MOVE_AERIAL_ACE) == DAMAGE_CATEGORY_PHYSICAL);
}

SINGLE_BATTLE_TEST("Disguised Mimikyu doesn't lose 1/8 of its max HP upon changing to its busted form (Gen7)")
{
    enum Species species, newSpecies;
    PARAMETRIZE { species = SPECIES_MIMIKYU_DISGUISED;       newSpecies = SPECIES_MIMIKYU_BUSTED; }
    PARAMETRIZE { species = SPECIES_MIMIKYU_TOTEM_DISGUISED; newSpecies = SPECIES_MIMIKYU_BUSTED_TOTEM; }
    GIVEN {
        WITH_CONFIG(B_DISGUISE_HP_LOSS, GEN_7);
        PLAYER(species) { Ability(ABILITY_DISGUISE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_AERIAL_ACE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_AERIAL_ACE, opponent);
        NOT HP_BAR(player);
        ABILITY_POPUP(player, ABILITY_DISGUISE);
    } THEN {
        EXPECT_EQ(player->species, newSpecies);
        EXPECT_EQ(player->hp, player->maxHP);
    }
}

SINGLE_BATTLE_TEST("Disguised Mimikyu will lose 1/8 of its max HP upon changing to its busted form (Gen8+)")
{
    s16 disguiseDamage;
    enum Species species, newSpecies;
    PARAMETRIZE { species = SPECIES_MIMIKYU_DISGUISED;       newSpecies = SPECIES_MIMIKYU_BUSTED; }
    PARAMETRIZE { species = SPECIES_MIMIKYU_TOTEM_DISGUISED; newSpecies = SPECIES_MIMIKYU_BUSTED_TOTEM; }
    GIVEN {
        WITH_CONFIG(B_DISGUISE_HP_LOSS, GEN_8);
        PLAYER(species) { Ability(ABILITY_DISGUISE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_AERIAL_ACE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_AERIAL_ACE, opponent);
        ABILITY_POPUP(player, ABILITY_DISGUISE);
        HP_BAR(player, captureDamage: &disguiseDamage);
    } THEN {
        EXPECT_EQ(player->species, newSpecies);
        EXPECT_EQ(disguiseDamage, player->maxHP / 8);
    }
}

SINGLE_BATTLE_TEST("Disguised Mimikyu takes no damage from a confusion hit and changes to its busted form")
{
    enum Species species, newSpecies;
    PARAMETRIZE { species = SPECIES_MIMIKYU_DISGUISED;       newSpecies = SPECIES_MIMIKYU_BUSTED; }
    PARAMETRIZE { species = SPECIES_MIMIKYU_TOTEM_DISGUISED; newSpecies = SPECIES_MIMIKYU_BUSTED_TOTEM; }
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_CONFUSE_RAY) == EFFECT_CONFUSE);
        PLAYER(species) { Ability(ABILITY_DISGUISE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_CONFUSE_RAY); }
        TURN {}
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CONFUSE_RAY, opponent);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_CONFUSION, player);
        MESSAGE("Mimikyu became confused!");
        MESSAGE("Mimikyu is confused!");
        MESSAGE("It hurt itself in its confusion!");
        NOT HP_BAR(player);
        ABILITY_POPUP(player, ABILITY_DISGUISE);
    } THEN {
        EXPECT_EQ(player->species, newSpecies);
    }
}

SINGLE_BATTLE_TEST("Disguised Mimikyu takes damage from secondary damage without breaking the disguise - Stealth Rock")
{
    enum Species species;
    PARAMETRIZE { species = SPECIES_MIMIKYU_DISGUISED; }
    PARAMETRIZE { species = SPECIES_MIMIKYU_TOTEM_DISGUISED; }
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_STEALTH_ROCK) == EFFECT_STEALTH_ROCK);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(species) { Ability(ABILITY_DISGUISE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_STEALTH_ROCK); }
        TURN { SWITCH(player, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STEALTH_ROCK, opponent);
        HP_BAR(player);
        MESSAGE("Pointed stones dug into Mimikyu!");
    } THEN {
        EXPECT_EQ(player->species, species);
    }
}

SINGLE_BATTLE_TEST("Disguised Mimikyu takes damage from secondary damage without breaking the disguise - Weather")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_SANDSTORM) == EFFECT_WEATHER);
        ASSUME(GetMoveWeatherType(MOVE_SANDSTORM) == BATTLE_WEATHER_SANDSTORM);
        ASSUME(GetSpeciesType(SPECIES_GEODUDE, 0) == TYPE_ROCK || GetSpeciesType(SPECIES_GEODUDE, 1) == TYPE_ROCK);
        PLAYER(SPECIES_GEODUDE);
        PLAYER(SPECIES_MIMIKYU_DISGUISED) { Ability(ABILITY_DISGUISE); }
        OPPONENT(SPECIES_GEODUDE);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SANDSTORM); }
        TURN { SWITCH(player, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SANDSTORM, opponent);
        HP_BAR(player);
    } THEN {
        EXPECT_EQ(player->species, SPECIES_MIMIKYU_DISGUISED);
    }
}

SINGLE_BATTLE_TEST("Disguised Mimikyu takes damage from Rocky Helmet without breaking the disguise")
{
    enum Species species;
    PARAMETRIZE { species = SPECIES_MIMIKYU_DISGUISED; }
    PARAMETRIZE { species = SPECIES_MIMIKYU_TOTEM_DISGUISED; }
    GIVEN {
        ASSUME(gItemsInfo[ITEM_ROCKY_HELMET].holdEffect == HOLD_EFFECT_ROCKY_HELMET);
        PLAYER(species) { Ability(ABILITY_DISGUISE); }
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_ROCKY_HELMET); }
    } WHEN {
        TURN { MOVE(player, MOVE_AERIAL_ACE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_AERIAL_ACE, player);
        HP_BAR(opponent);
        HP_BAR(player);
        MESSAGE("Mimikyu was hurt by the opposing Wobbuffet's Rocky Helmet!");
    } THEN {
        EXPECT_EQ(player->species, species);
    }
}

SINGLE_BATTLE_TEST("Disguised Mimikyu takes damage from Rough Skin without breaking the disguise")
{
    enum Species species;
    PARAMETRIZE { species = SPECIES_MIMIKYU_DISGUISED; }
    PARAMETRIZE { species = SPECIES_MIMIKYU_TOTEM_DISGUISED; }
    GIVEN {
        PLAYER(species) { Ability(ABILITY_DISGUISE); }
        OPPONENT(SPECIES_CARVANHA) { Ability(ABILITY_ROUGH_SKIN); }
    } WHEN {
        TURN { MOVE(player, MOVE_AERIAL_ACE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_AERIAL_ACE, player);
        HP_BAR(opponent);
        ABILITY_POPUP(opponent, ABILITY_ROUGH_SKIN);
        HP_BAR(player);
    } THEN {
        EXPECT_EQ(player->species, species);
    }
}

SINGLE_BATTLE_TEST("Disguised Mimikyu is ignored by Mold Breaker")
{
    enum Species species;
    PARAMETRIZE { species = SPECIES_MIMIKYU_DISGUISED; }
    PARAMETRIZE { species = SPECIES_MIMIKYU_TOTEM_DISGUISED; }
    GIVEN {
        PLAYER(species) { Ability(ABILITY_DISGUISE); }
        OPPONENT(SPECIES_PINSIR) { Ability(ABILITY_MOLD_BREAKER); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_AERIAL_ACE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_AERIAL_ACE, opponent);
        NOT ABILITY_POPUP(player, ABILITY_DISGUISE);
    } THEN {
        EXPECT_EQ(player->species, species);
    }
}

SINGLE_BATTLE_TEST("Disguised Mimikyu's types revert back to Ghost/Fairy when Disguise is broken")
{
    enum Species species;
    PARAMETRIZE { species = SPECIES_MIMIKYU_DISGUISED; }
    PARAMETRIZE { species = SPECIES_MIMIKYU_TOTEM_DISGUISED; }
    GIVEN {
        ASSUME(GetMoveType(MOVE_SHADOW_CLAW) == TYPE_GHOST);
        PLAYER(species) { Ability(ABILITY_DISGUISE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SOAK); }
        TURN { MOVE(opponent, MOVE_SCRATCH); }
        TURN { MOVE(opponent, MOVE_SHADOW_CLAW); }
    } SCENE {
        MESSAGE("The opposing Wobbuffet used Soak!");
        MESSAGE("Mimikyu transformed into the Water type!");
        MESSAGE("The opposing Wobbuffet used Scratch!");
        ABILITY_POPUP(player, ABILITY_DISGUISE);
        MESSAGE("The opposing Wobbuffet used Shadow Claw!");
        MESSAGE("It's super effective!");
    }
}

SINGLE_BATTLE_TEST("Disguised Mimikyu blocks a move after getting Gastro Acid Batton Passed")
{
    enum Species species, newSpecies;
    PARAMETRIZE { species = SPECIES_MIMIKYU_DISGUISED;       newSpecies = SPECIES_MIMIKYU_BUSTED; }
    PARAMETRIZE { species = SPECIES_MIMIKYU_TOTEM_DISGUISED; newSpecies = SPECIES_MIMIKYU_BUSTED_TOTEM; }
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_BATON_PASS) == EFFECT_BATON_PASS);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(species) { Ability(ABILITY_DISGUISE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_GASTRO_ACID); MOVE(player, MOVE_BATON_PASS); SEND_OUT(player, 1); }
        TURN { MOVE(opponent, MOVE_SHADOW_CLAW); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GASTRO_ACID, opponent);
        MESSAGE("Wobbuffet's Ability was suppressed!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BATON_PASS, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SHADOW_CLAW, opponent);
        ABILITY_POPUP(player, ABILITY_DISGUISE);
    } THEN {
        EXPECT_EQ(player->species, newSpecies);
    }
}

SINGLE_BATTLE_TEST("Disguise does not break from a teammate's Wish")
{
    enum Species species;
    PARAMETRIZE { species = SPECIES_MIMIKYU_DISGUISED; }
    PARAMETRIZE { species = SPECIES_MIMIKYU_TOTEM_DISGUISED; }
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_WISH) == EFFECT_WISH);
        PLAYER(SPECIES_JIRACHI);
        PLAYER(species) { Ability(ABILITY_DISGUISE); HP(219); MaxHP(220); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_WISH); }
        TURN { SWITCH(player, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_WISH, player);
        NOT ABILITY_POPUP(player, ABILITY_DISGUISE);
    } THEN {
        EXPECT_EQ(player->species, species);
    }
}
