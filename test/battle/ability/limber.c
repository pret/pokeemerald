#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Limber prevents paralysis")
{
    GIVEN {
        ASSUME(MoveHasAdditionalEffect(MOVE_THUNDER_SHOCK, MOVE_EFFECT_PARALYSIS) == TRUE);
        PLAYER(SPECIES_PERSIAN) { Ability(ABILITY_LIMBER); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_THUNDER_SHOCK); }
    } SCENE {
        HP_BAR(player);
        NONE_OF {
            ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PRZ, player);
            STATUS_ICON(player, paralysis: TRUE);
        }
    }
}


SINGLE_BATTLE_TEST("Limber prevents paralysis from Thunder Wave")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_THUNDER_WAVE) == EFFECT_NON_VOLATILE_STATUS);
        ASSUME(GetMoveNonVolatileStatus(MOVE_THUNDER_WAVE) == MOVE_EFFECT_PARALYSIS);
        PLAYER(SPECIES_PERSIAN) { Ability(ABILITY_LIMBER); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_THUNDER_WAVE); }
    } SCENE {
        MESSAGE("It doesn't affect Persian…");
        NONE_OF {
            ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PRZ, player);
            STATUS_ICON(player, paralysis: TRUE);
        }
    }
}
