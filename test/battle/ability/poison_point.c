#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Poison Point inflicts poison on contact")
{
    u32 move;
    PARAMETRIZE { move = MOVE_TACKLE; }
    PARAMETRIZE { move = MOVE_SWIFT; }
    GIVEN {
        ASSUME(gBattleMoves[MOVE_TACKLE].flags & FLAG_MAKES_CONTACT);
        ASSUME(!(gBattleMoves[MOVE_SWIFT].flags & FLAG_MAKES_CONTACT));
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_NIDORAN_M) { Ability(ABILITY_POISON_POINT); }
    } WHEN {
        TURN { MOVE(player, move); }
        TURN {}
    } SCENE {
        if (gBattleMoves[move].flags & FLAG_MAKES_CONTACT) {
            ABILITY_POPUP(opponent, ABILITY_POISON_POINT);
            ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PSN, player);
            MESSAGE("Wobbuffet was poisoned by Foe Nidoran♂'s Poison Point!");
            STATUS_ICON(player, poison: TRUE);
        } else {
            NOT ABILITY_POPUP(opponent, ABILITY_POISON_POINT);
            NOT ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PSN, player);
            NOT MESSAGE("Wobbuffet was poisoned by Foe Nidoran♂'s Poison Point!");
            NOT STATUS_ICON(player, poison: TRUE);
        }
    }
}
