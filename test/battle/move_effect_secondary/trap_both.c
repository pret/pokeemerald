#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(MoveHasAdditionalEffect(MOVE_JAW_LOCK, MOVE_EFFECT_TRAP_BOTH) == TRUE);
}

SINGLE_BATTLE_TEST("Jaw Lock traps both opponents")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_JAW_LOCK); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_JAW_LOCK, player);
        MESSAGE("Neither Pokémon can run away!");
    } THEN { // Can't find good way to test trapping
        EXPECT(opponent->volatiles.escapePrevention);
        EXPECT(player->volatiles.escapePrevention);
    }
}
