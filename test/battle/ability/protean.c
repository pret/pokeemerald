#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Protean/Libero changes the type of the user to the move used every time (Gen6-8)")
{
    enum Ability ability;
    enum Species species;
    PARAMETRIZE { ability = ABILITY_PROTEAN; species = SPECIES_KECLEON; }
    PARAMETRIZE { ability = ABILITY_LIBERO;  species = SPECIES_RABOOT; }
    GIVEN {
        WITH_CONFIG(B_PROTEAN_LIBERO, GEN_6);
        PLAYER(SPECIES_REGIROCK);
        OPPONENT(species) { Ability(ability); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_WATER_GUN); }
        TURN { MOVE(opponent, MOVE_SCRATCH); }
        TURN { SWITCH(opponent, 1); }
        TURN { SWITCH(opponent, 0); }
        TURN { MOVE(opponent, MOVE_WATER_GUN); }
    } SCENE {
        ABILITY_POPUP(opponent, ability);
        if (species == SPECIES_KECLEON)
            MESSAGE("The opposing Kecleon transformed into the Water type!");
        else
            MESSAGE("The opposing Raboot transformed into the Water type!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_WATER_GUN, opponent);
        ABILITY_POPUP(opponent, ability);
        if (species == SPECIES_KECLEON)
            MESSAGE("The opposing Kecleon transformed into the Normal type!");
        else
            MESSAGE("The opposing Raboot transformed into the Normal type!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        ABILITY_POPUP(opponent, ability);
        if (species == SPECIES_KECLEON)
            MESSAGE("The opposing Kecleon transformed into the Water type!");
        else
            MESSAGE("The opposing Raboot transformed into the Water type!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_WATER_GUN, opponent);
    }
}

SINGLE_BATTLE_TEST("Protean/Libero changes the type of the user only once per switch in (Gen9+)")
{
    enum Ability ability; enum Species species;
    PARAMETRIZE { ability = ABILITY_PROTEAN; species = SPECIES_KECLEON; }
    PARAMETRIZE { ability = ABILITY_LIBERO;  species = SPECIES_RABOOT; }
    GIVEN {
        WITH_CONFIG(B_PROTEAN_LIBERO, GEN_9);
        PLAYER(SPECIES_REGIROCK);
        OPPONENT(species) { Ability(ability); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_WATER_GUN); }
        TURN { MOVE(opponent, MOVE_SCRATCH); }
        TURN { SWITCH(opponent, 1); }
        TURN { SWITCH(opponent, 0); }
        TURN { MOVE(opponent, MOVE_WATER_GUN); }
    } SCENE {
        ABILITY_POPUP(opponent, ability);
        if (species == SPECIES_KECLEON)
            MESSAGE("The opposing Kecleon transformed into the Water type!");
        else
            MESSAGE("The opposing Raboot transformed into the Water type!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_WATER_GUN, opponent);
        NONE_OF {
            ABILITY_POPUP(opponent, ability);
            MESSAGE("The opposing Kecleon transformed into the Normal type!");
            MESSAGE("The opposing Raboot transformed into the Normal type!");
        }
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        ABILITY_POPUP(opponent, ability);
        if (species == SPECIES_KECLEON)
            MESSAGE("The opposing Kecleon transformed into the Water type!");
        else
            MESSAGE("The opposing Raboot transformed into the Water type!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_WATER_GUN, opponent);
    }
}

SINGLE_BATTLE_TEST("Protean/Libero does not change the user's type when using Struggle")
{
    enum Ability ability; enum Species species;
    PARAMETRIZE { ability = ABILITY_PROTEAN; species = SPECIES_GRENINJA; }
    PARAMETRIZE { ability = ABILITY_LIBERO;  species = SPECIES_RABOOT; }
    GIVEN {
        PLAYER(SPECIES_REGIROCK);
        OPPONENT(species) { Ability(ability); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_STRUGGLE); }
    } SCENE {
        NONE_OF {
            ABILITY_POPUP(opponent, ability);
            MESSAGE("The opposing Greninja transformed into the Normal type!");
            MESSAGE("The opposing Raboot transformed into the Normal type!");
        }
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STRUGGLE, opponent);
    }
}
