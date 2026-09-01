#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(MoveHasAdditionalEffect(MOVE_G_MAX_STONESURGE, MOVE_EFFECT_STEALTH_ROCK));
}

SINGLE_BATTLE_TEST("Stealth Rock: Rock from G-Max Stonesurge are set up before any ability activation")
{
    GIVEN {
        PLAYER(SPECIES_DREDNAW) { GigantamaxFactor(TRUE); }
        OPPONENT(SPECIES_SKARMORY) { Ability(ABILITY_WEAK_ARMOR); }
    } WHEN {
        TURN { MOVE(player, MOVE_WATERFALL, gimmick: GIMMICK_DYNAMAX); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_G_MAX_STONESURGE, player);
        MESSAGE("Pointed stones float in the air on the opposing side!");
        ABILITY_POPUP(opponent, ABILITY_WEAK_ARMOR);
    }
}
