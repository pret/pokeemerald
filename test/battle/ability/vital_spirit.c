#include "global.h"
#include "test/battle.h"

TO_DO_BATTLE_TEST("TODO: Write Vital Spirit (Ability) test titles")

SINGLE_BATTLE_TEST("Vital Spirit prevents sleep")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_SPORE) == EFFECT_NON_VOLATILE_STATUS);
        ASSUME(GetMoveNonVolatileStatus(MOVE_SPORE) == MOVE_EFFECT_SLEEP);
        PLAYER(SPECIES_MANKEY) { Ability(ABILITY_VITAL_SPIRIT); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SPORE); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_VITAL_SPIRIT);
        MESSAGE("Mankey made it ineffective!");
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_SPORE, opponent);
            ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_SLP, player);
            STATUS_ICON(player, sleep: TRUE);
        }
    }
}
