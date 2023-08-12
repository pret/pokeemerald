#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gBattleMoves[MOVE_MORTAL_SPIN].effect == EFFECT_MORTAL_SPIN);
}

SINGLE_BATTLE_TEST("Mortal Spin blows away hazards and poisons foe")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_STEALTH_ROCK); MOVE(player, MOVE_MORTAL_SPIN); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STEALTH_ROCK, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MORTAL_SPIN, player);
        MESSAGE("Wobbuffet blew away Stealth Rock!");
        MESSAGE("Foe Wobbuffet was poisoned!");
        STATUS_ICON(opponent, poison: TRUE);
    }
}

