#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(MoveHasAdditionalEffectSelf(MOVE_RAPID_SPIN, MOVE_EFFECT_RAPID_SPIN) == TRUE);
#if B_SPEED_BUFFING_RAPID_SPIN >= GEN_8
    ASSUME(MoveHasAdditionalEffectSelf(MOVE_RAPID_SPIN, MOVE_EFFECT_SPD_PLUS_1) == TRUE);
#endif
    ASSUME(MoveHasAdditionalEffectSelf(MOVE_MORTAL_SPIN, MOVE_EFFECT_RAPID_SPIN) == TRUE);
    ASSUME(MoveHasAdditionalEffect(MOVE_MORTAL_SPIN, MOVE_EFFECT_POISON) == TRUE);
}

SINGLE_BATTLE_TEST("Rapin Spin blows away Wrap, hazards and raises Speed (Gen 8+)")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_WRAP); }
        TURN { MOVE(opponent, MOVE_STEALTH_ROCK); MOVE(player, MOVE_RAPID_SPIN); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STEALTH_ROCK, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_RAPID_SPIN, player);
        MESSAGE("Wobbuffet got free of Foe Wobbuffet's Wrap!");
        MESSAGE("Wobbuffet blew away Stealth Rock!");
    #if B_SPEED_BUFFING_RAPID_SPIN >= GEN_8
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        MESSAGE("Wobbuffet's Speed rose!");
    #endif
    }
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

