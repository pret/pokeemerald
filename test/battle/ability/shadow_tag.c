#include "global.h"
#include "test/battle.h"

TO_DO_BATTLE_TEST("TODO: Write Shadow Tag (Ability) test titles")

WILD_BATTLE_TEST("Shadow Tag prevents wild Pokemon from fleeing with Teleport")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_TELEPORT) == EFFECT_TELEPORT);
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_SHADOW_TAG); }
        OPPONENT(SPECIES_ABRA);
    } WHEN {
        TURN { MOVE(opponent, MOVE_TELEPORT); }
    } SCENE {
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_TELEPORT, opponent);
        ABILITY_POPUP(player, ABILITY_SHADOW_TAG);
        MESSAGE("Wobbuffet made it ineffective!");
    }
}
