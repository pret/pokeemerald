#include "global.h"
#include "test/battle.h"

TO_DO_BATTLE_TEST("TODO: Write Wandering Spirit (Ability) test titles")

SINGLE_BATTLE_TEST("Wandering Spirit copied ability triggers on fainted mon")
{
    GIVEN {
        PLAYER(SPECIES_EKANS) { Ability(ABILITY_INTIMIDATE); }
        PLAYER(SPECIES_WOBBUFFET)
        OPPONENT(SPECIES_YAMASK_GALAR) { HP(1); Ability(ABILITY_WANDERING_SPIRIT); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_POISON_FANG); SEND_OUT(opponent, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POISON_FANG, player);
        ABILITY_POPUP(opponent, ABILITY_INTIMIDATE);
    }
}
