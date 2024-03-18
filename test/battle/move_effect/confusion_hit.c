#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Alluring Voice confuses the target if the target raised a stat this turn")
{
    u16 move;

    PARAMETRIZE { move = MOVE_CELEBRATE; }
    PARAMETRIZE { move = MOVE_SWORDS_DANCE; }

    GIVEN {
        ASSUME(MoveHasAdditionalEffect(MOVE_ALLURING_VOICE, MOVE_EFFECT_CONFUSION));
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, move); MOVE(player, MOVE_ALLURING_VOICE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ALLURING_VOICE, player);
        HP_BAR(opponent);
        if (move == MOVE_SWORDS_DANCE) {
            ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_CONFUSION, opponent);
            MESSAGE("Foe Wobbuffet became confused!");
        } else {
            NONE_OF {
                ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_CONFUSION, opponent);
                MESSAGE("Foe Wobbuffet became confused!");
            }
        }
    }
}

SINGLE_BATTLE_TEST("Alluring Voice confuse effect is removed if it is Sheer Force boosted")
{
    GIVEN {
        ASSUME(MoveHasAdditionalEffect(MOVE_ALLURING_VOICE, MOVE_EFFECT_CONFUSION));
        PLAYER(SPECIES_NIDOKING) { Ability(ABILITY_SHEER_FORCE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SWORDS_DANCE); MOVE(player, MOVE_ALLURING_VOICE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SWORDS_DANCE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ALLURING_VOICE, player);
        HP_BAR(opponent);
        NONE_OF {
            ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_CONFUSION, opponent);
            MESSAGE("Foe Wobbuffet became confused!");
        }
    }
}
