#include "global.h"
#include "test/battle.h"

ASSUMPTIONS {
    ASSUME(gMovesInfo[MOVE_HAIL].effect == EFFECT_HAIL);
    ASSUME(gMovesInfo[MOVE_SNOWSCAPE].effect == EFFECT_SNOWSCAPE);
}

SINGLE_BATTLE_TEST("Ice Body prevents damage from hail")
{
    u32 move;
    PARAMETRIZE { move = MOVE_HAIL; }
    PARAMETRIZE { move = MOVE_SNOWSCAPE; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_GLALIE) { Ability(ABILITY_ICE_BODY); }
    } WHEN {
        TURN { MOVE(player, move); MOVE(opponent, MOVE_SKILL_SWAP); }
    } SCENE {
        NONE_OF { HP_BAR(player); }
    }
}

SINGLE_BATTLE_TEST("Ice Body recovers 1/16th of Max HP in hail.")
{
    u32 move;
    PARAMETRIZE { move = MOVE_HAIL; }
    PARAMETRIZE { move = MOVE_SNOWSCAPE; }
    GIVEN {
        PLAYER(SPECIES_GLALIE) { Ability(ABILITY_ICE_BODY); HP(1); MaxHP(100); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, move); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_ICE_BODY);
        HP_BAR(player, damage: -(100 / 16));
        MESSAGE("Glalie's Ice Body healed it a little bit!");
    }
}

SINGLE_BATTLE_TEST("Ice Body doesn't recover HP if Cloud Nine/Air Lock is on the field")
{
    u32 move;
    PARAMETRIZE { move = MOVE_HAIL; }
    PARAMETRIZE { move = MOVE_SNOWSCAPE; }
    GIVEN {
        PLAYER(SPECIES_GLALIE) { Ability(ABILITY_ICE_BODY); HP(1); MaxHP(100); }
        OPPONENT(SPECIES_GOLDUCK) { Ability(ABILITY_CLOUD_NINE); }
    } WHEN {
        TURN { MOVE(opponent, move); }
    } SCENE {
        NOT ABILITY_POPUP(player, ABILITY_ICE_BODY);
    }
}
