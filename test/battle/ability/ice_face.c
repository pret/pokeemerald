#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Ice Face blocks physical moves, changing Eiscue into its Noice Face form")
{
    GIVEN {
        ASSUME(gMovesInfo[MOVE_TACKLE].category == DAMAGE_CATEGORY_PHYSICAL);
        PLAYER(SPECIES_EISCUE);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_TACKLE); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_ICE_FACE);
        MESSAGE("Eiscue transformed!");
    }
}

SINGLE_BATTLE_TEST("Ice Face does not block special moves, Eiscue stays in Ice Face form")
{
    GIVEN {
        ASSUME(gMovesInfo[MOVE_TACKLE].category == DAMAGE_CATEGORY_PHYSICAL);
        ASSUME(gMovesInfo[MOVE_EMBER].category == DAMAGE_CATEGORY_SPECIAL);
        PLAYER(SPECIES_EISCUE);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_EMBER); }
    } SCENE {
        NOT ABILITY_POPUP(player, ABILITY_ICE_FACE);
    }
}

SINGLE_BATTLE_TEST("Ice Face is restored if hail or snow begins while Noice Face Eiscue is out")
{
    u32 move;
    PARAMETRIZE { move = MOVE_SNOWSCAPE; }
    PARAMETRIZE { move = MOVE_HAIL; }
    GIVEN {
        ASSUME(gMovesInfo[MOVE_TACKLE].category == DAMAGE_CATEGORY_PHYSICAL);
        ASSUME(gMovesInfo[MOVE_SNOWSCAPE].effect == EFFECT_SNOWSCAPE);
        ASSUME(gMovesInfo[MOVE_HAIL].effect == EFFECT_HAIL);
        PLAYER(SPECIES_EISCUE);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_TACKLE); }
        TURN { MOVE(opponent, move); }
        TURN { MOVE(opponent, MOVE_TACKLE); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_ICE_FACE);
        MESSAGE("Eiscue transformed!");
        ABILITY_POPUP(player, ABILITY_ICE_FACE);
        MESSAGE("Eiscue transformed!");
        ABILITY_POPUP(player, ABILITY_ICE_FACE);
        MESSAGE("Eiscue transformed!");
    }
}

SINGLE_BATTLE_TEST("Ice Face is restored if Noice Face Eiscue is sent in while hail or snow is active")
{
    u32 move;
    PARAMETRIZE { move = MOVE_SNOWSCAPE; }
    PARAMETRIZE { move = MOVE_HAIL; }
    GIVEN {
        ASSUME(gMovesInfo[MOVE_TACKLE].category == DAMAGE_CATEGORY_PHYSICAL);
        ASSUME(gMovesInfo[MOVE_SNOWSCAPE].effect == EFFECT_SNOWSCAPE);
        ASSUME(gMovesInfo[MOVE_HAIL].effect == EFFECT_HAIL);
        PLAYER(SPECIES_EISCUE);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_TACKLE); }
        TURN { SWITCH(player, 1); MOVE(opponent, move); }
        TURN { SWITCH(player, 0); MOVE(opponent, MOVE_TACKLE); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_ICE_FACE);
        MESSAGE("Eiscue transformed!");
        ABILITY_POPUP(player, ABILITY_ICE_FACE);
        MESSAGE("Eiscue transformed!");
        ABILITY_POPUP(player, ABILITY_ICE_FACE);
        MESSAGE("Eiscue transformed!");
    }
}

SINGLE_BATTLE_TEST("Ice Face is not restored if Eiscue changes into Noice Face form while there's already hail or snow")
{
    u32 move;
    PARAMETRIZE { move = MOVE_SNOWSCAPE; }
    PARAMETRIZE { move = MOVE_HAIL; }
    GIVEN {
        ASSUME(gMovesInfo[MOVE_TACKLE].category == DAMAGE_CATEGORY_PHYSICAL);
        ASSUME(gMovesInfo[MOVE_SNOWSCAPE].effect == EFFECT_SNOWSCAPE);
        ASSUME(gMovesInfo[MOVE_HAIL].effect == EFFECT_HAIL);
        PLAYER(SPECIES_EISCUE) { HP(1); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, move); MOVE(opponent, MOVE_TACKLE); }
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_TACKLE); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_ICE_FACE);
        MESSAGE("Eiscue transformed!");
        MESSAGE("Eiscue used Celebrate!");
        MESSAGE("Eiscue fainted!");
    }
}

SINGLE_BATTLE_TEST("Ice Face form change persists after switching out")
{
    GIVEN {
        ASSUME(gMovesInfo[MOVE_TACKLE].category == DAMAGE_CATEGORY_PHYSICAL);
        PLAYER(SPECIES_EISCUE) { HP(1); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_TACKLE); }
        TURN { SWITCH(player, 1); MOVE(opponent, MOVE_CELEBRATE); }
        TURN { SWITCH(player, 0); MOVE(opponent, MOVE_TACKLE); SEND_OUT(player, 1); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_ICE_FACE);
        MESSAGE("Eiscue transformed!");
        MESSAGE("Eiscue fainted!");
    }
}

SINGLE_BATTLE_TEST("Ice Face doesn't transform Eiscue if Cloud Nine/Air Lock is on the field")
{
    GIVEN {
        ASSUME(gMovesInfo[MOVE_TACKLE].category == DAMAGE_CATEGORY_PHYSICAL);
        PLAYER(SPECIES_EISCUE) { HP(1); }
        OPPONENT(SPECIES_RAYQUAZA) { Ability(ABILITY_AIR_LOCK); }
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_TACKLE); }
        TURN { MOVE(player, MOVE_SNOWSCAPE); MOVE(opponent, MOVE_TACKLE); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_ICE_FACE);
        MESSAGE("Eiscue transformed!");
        MESSAGE("Eiscue fainted!");
    }
}
