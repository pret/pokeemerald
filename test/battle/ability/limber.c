#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Limber prevents paralysis")
{
    GIVEN {
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
