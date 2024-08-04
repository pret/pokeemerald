#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Flame Body inflicts burn on contact")
{
    u32 move;
    PARAMETRIZE { move = MOVE_TACKLE; }
    PARAMETRIZE { move = MOVE_SWIFT; }
    GIVEN {
        ASSUME(gMovesInfo[MOVE_TACKLE].makesContact);
        ASSUME(!gMovesInfo[MOVE_SWIFT].makesContact);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_MAGMAR) { Ability(ABILITY_FLAME_BODY); }
    } WHEN {
        TURN { MOVE(player, move); }
    } SCENE {
        if (gMovesInfo[move].makesContact) {
            ABILITY_POPUP(opponent, ABILITY_FLAME_BODY);
            ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_BRN, player);
            MESSAGE("Foe Magmar's Flame Body burned Wobbuffet!");
            STATUS_ICON(player, burn: TRUE);
        } else {
            NONE_OF {
                ABILITY_POPUP(opponent, ABILITY_FLAME_BODY);
                ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_BRN, player);
                MESSAGE("Foe Magmar's Flame Body burned Wobbuffet!");
                STATUS_ICON(player, burn: TRUE);
            }
        }
    }
}

SINGLE_BATTLE_TEST("Flame Body triggers 30% of the time")
{
    PASSES_RANDOMLY(3, 10, RNG_FLAME_BODY);
    GIVEN {
        ASSUME(B_ABILITY_TRIGGER_CHANCE >= GEN_4);
        ASSUME(gMovesInfo[MOVE_TACKLE].makesContact);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_MAGMAR) { Ability(ABILITY_FLAME_BODY); }
    } WHEN {
        TURN { MOVE(player, MOVE_TACKLE); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_FLAME_BODY);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_BRN, player);
        MESSAGE("Foe Magmar's Flame Body burned Wobbuffet!");
        STATUS_ICON(player, burn: TRUE);
    }
}
