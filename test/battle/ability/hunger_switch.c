#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Hunger Switch switches Morpeko's forms at the end of the turn")
{
    enum Species species;
    PARAMETRIZE { species = SPECIES_MORPEKO_FULL_BELLY; }
    PARAMETRIZE { species = SPECIES_MORPEKO_HANGRY; }
    GIVEN {
        PLAYER(species) { Speed(2); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(1); }
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); }
    } SCENE {
        MESSAGE("Morpeko used Celebrate!");
        MESSAGE("The opposing Wobbuffet used Celebrate!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FORM_CHANGE, player);
    } THEN {
        if (species == SPECIES_MORPEKO_FULL_BELLY)
            EXPECT_EQ(player->species, SPECIES_MORPEKO_HANGRY);
        else
            EXPECT_EQ(player->species, SPECIES_MORPEKO_FULL_BELLY);
    }
}

SINGLE_BATTLE_TEST("Hunger Switch does not switch a mon transformed into Morpeko's form")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_TRANSFORM) == EFFECT_TRANSFORM);
        PLAYER(SPECIES_MORPEKO) { Ability(ABILITY_HUNGER_SWITCH); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_TRANSFORM); }
    } SCENE {
        NOT ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FORM_CHANGE, opponent);
    }
}

SINGLE_BATTLE_TEST("Hunger Switch does not switch Morpeko's form when Terastallized")
{
    GIVEN {
        PLAYER(SPECIES_MORPEKO) { Ability(ABILITY_HUNGER_SWITCH); TeraType(TYPE_NORMAL); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {}
        TURN { MOVE(player, MOVE_SCRATCH, gimmick: GIMMICK_TERA); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FORM_CHANGE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        NOT ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FORM_CHANGE, player);
    }
}

SINGLE_BATTLE_TEST("Hunger Switch does not switch Morpeko's form after switching out while Terastallized")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_ROAR) == EFFECT_ROAR);
        PLAYER(SPECIES_MORPEKO) { Ability(ABILITY_HUNGER_SWITCH); TeraType(TYPE_NORMAL); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {}
        TURN { MOVE(player, MOVE_SCRATCH, gimmick: GIMMICK_TERA); MOVE(opponent, MOVE_ROAR); }
        TURN { SWITCH(player, 0); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FORM_CHANGE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        NOT ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FORM_CHANGE, player);
    } THEN {
        EXPECT_EQ(player->species, SPECIES_MORPEKO_HANGRY);
    }
}
