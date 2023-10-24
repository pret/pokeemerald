#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Poison Point inflicts poison on contact")
{
    u32 move;
    PARAMETRIZE { move = MOVE_TACKLE; }
    PARAMETRIZE { move = MOVE_SWIFT; }
    GIVEN {
        ASSUME(gBattleMoves[MOVE_TACKLE].makesContact);
        ASSUME(!gBattleMoves[MOVE_SWIFT].makesContact);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_NIDORAN_M) { Ability(ABILITY_POISON_POINT); }
    } WHEN {
        TURN { MOVE(player, move); }
        TURN {}
    } SCENE {
        if (gBattleMoves[move].makesContact) {
            ABILITY_POPUP(opponent, ABILITY_POISON_POINT);
            ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PSN, player);
            MESSAGE("Wobbuffet was poisoned by Foe Nidoran♂'s Poison Point!");
            STATUS_ICON(player, poison: TRUE);
        } else {
            NONE_OF {
                ABILITY_POPUP(opponent, ABILITY_POISON_POINT);
                ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PSN, player);
                MESSAGE("Wobbuffet was poisoned by Foe Nidoran♂'s Poison Point!");
                STATUS_ICON(player, poison: TRUE);
            }
        }
    }
}
