#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(MoveHasAdditionalEffect(MOVE_THROAT_CHOP, MOVE_EFFECT_THROAT_CHOP) == TRUE);
}

SINGLE_BATTLE_TEST("Throat Chop prevents the usage of sound moves")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(100); };
        OPPONENT(SPECIES_WOBBUFFET) { Speed(50); };
    } WHEN {
        TURN { MOVE(player, MOVE_THROAT_CHOP); MOVE(opponent, MOVE_HYPER_VOICE); }
        TURN {}
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_THROAT_CHOP, player);
        HP_BAR(opponent);
        MESSAGE("Foe Wobbuffet can't use Hyper Voice due to Throat Chop!");
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_HYPER_VOICE, opponent);
        }
    }
}

SINGLE_BATTLE_TEST("Throat Chop won't work through a substitute")
{
    GIVEN {
        PLAYER(SPECIES_INCINEROAR) { Speed(100); };
        OPPONENT(SPECIES_WOBBUFFET) { Speed(50); };
    } WHEN {
        TURN { MOVE(opponent, MOVE_SUBSTITUTE); }
        TURN { MOVE(player, MOVE_THROAT_CHOP); MOVE(opponent, MOVE_HYPER_VOICE); }
        TURN {}
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SUBSTITUTE, opponent);
        HP_BAR(opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_THROAT_CHOP, player);
        NONE_OF {
            MESSAGE("Foe Wobbuffet can't use Hyper Voice due to Throat Chop!");
        }
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HYPER_VOICE, opponent);
    }
}
