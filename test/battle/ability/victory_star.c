#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveAccuracy(MOVE_ZEN_HEADBUTT) == 90);
}

SINGLE_BATTLE_TEST("Victory Star raises the accuracy of the user")
{
    PASSES_RANDOMLY(100, 100, RNG_ACCURACY);
    GIVEN {
        PLAYER(SPECIES_VICTINI) { Ability(ABILITY_VICTORY_STAR); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_ZEN_HEADBUTT); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ZEN_HEADBUTT, player);
        HP_BAR(opponent);
    }
}

DOUBLE_BATTLE_TEST("Victory Star raises the accuracy of an ally")
{
    PASSES_RANDOMLY(100, 100, RNG_ACCURACY);
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_VICTINI) { Ability(ABILITY_VICTORY_STAR); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_ZEN_HEADBUTT, target: opponentLeft); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ZEN_HEADBUTT, playerLeft);
        HP_BAR(opponentLeft);
    }
}

DOUBLE_BATTLE_TEST("Victory Start is not Mold Breaker ignored by ally")
{
    PASSES_RANDOMLY(100, 100, RNG_ACCURACY);
    GIVEN {
        PLAYER(SPECIES_PINSIR) { Ability(ABILITY_MOLD_BREAKER); }
        PLAYER(SPECIES_VICTINI) { Ability(ABILITY_VICTORY_STAR); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_ZEN_HEADBUTT, target: opponentLeft); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ZEN_HEADBUTT, playerLeft);
        HP_BAR(opponentLeft);
    }
}
