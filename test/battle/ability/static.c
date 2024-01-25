#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Static inflicts paralysis on contact")
{
    u32 move;
    PARAMETRIZE { move = MOVE_TACKLE; }
    PARAMETRIZE { move = MOVE_SWIFT; }
    GIVEN {
        ASSUME(gBattleMoves[MOVE_TACKLE].makesContact);
        ASSUME(!gBattleMoves[MOVE_SWIFT].makesContact);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_PIKACHU) { Ability(ABILITY_STATIC); }
    } WHEN {
        TURN { MOVE(player, move); }
    } SCENE {
        if (gBattleMoves[move].makesContact) {
            ABILITY_POPUP(opponent, ABILITY_STATIC);
            ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PRZ, player);
            MESSAGE("Foe Pikachu's Static paralyzed Wobbuffet! It may be unable to move!");
            STATUS_ICON(player, paralysis: TRUE);
        } else {
            NONE_OF {
                ABILITY_POPUP(opponent, ABILITY_STATIC);
                ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PRZ, player);
                MESSAGE("Foe Pikachu's Static paralyzed Wobbuffet! It may be unable to move!");
                STATUS_ICON(player, paralysis: TRUE);
            }
        }
    }
}
