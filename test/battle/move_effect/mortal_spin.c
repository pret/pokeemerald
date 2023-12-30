#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(MoveHasMoveEffectSelf(MOVE_MORTAL_SPIN, MOVE_EFFECT_RAPIDSPIN) == TRUE);
    ASSUME(MoveHasMoveEffect(MOVE_MORTAL_SPIN, MOVE_EFFECT_POISON, FALSE) == TRUE);
}

SINGLE_BATTLE_TEST("Mortal Spin blows away Wrap, hazards and poisons foe")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_WRAP); }
        TURN { MOVE(opponent, MOVE_STEALTH_ROCK); MOVE(player, MOVE_MORTAL_SPIN); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STEALTH_ROCK, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MORTAL_SPIN, player);
        MESSAGE("Wobbuffet got free of Foe Wobbuffet's Wrap!");
        MESSAGE("Wobbuffet blew away Stealth Rock!");
        MESSAGE("Foe Wobbuffet was poisoned!");
        STATUS_ICON(opponent, poison: TRUE);
    }
}

