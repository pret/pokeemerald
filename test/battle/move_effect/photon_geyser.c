#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gMovesInfo[MOVE_PHOTON_GEYSER].effect == EFFECT_PHOTON_GEYSER);
}

SINGLE_BATTLE_TEST("Photon Geyser can be mirror coated if it is a special move")
{
    GIVEN {
        // EFFECT_PHOTON_GEYSER requires the move data to be Special to work
        ASSUME(gMovesInfo[MOVE_PHOTON_GEYSER].category == DAMAGE_CATEGORY_SPECIAL);
        PLAYER(SPECIES_WOBBUFFET) { Attack(100); SpAttack(110); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_PHOTON_GEYSER); MOVE(opponent, MOVE_MIRROR_COAT); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PHOTON_GEYSER, player);
        HP_BAR(opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MIRROR_COAT, opponent);
        HP_BAR(player);
    }
}

SINGLE_BATTLE_TEST("Photon Geyser can be countered if it is a physical move")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Attack(110); SpAttack(100); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_PHOTON_GEYSER); MOVE(opponent, MOVE_COUNTER); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PHOTON_GEYSER, player);
        HP_BAR(opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_COUNTER, opponent);
        HP_BAR(player);
    }
}

SINGLE_BATTLE_TEST("Photon Geyser ignores ignorable Abilities like Battle Armor")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_LAPRAS) { Ability(ABILITY_SHELL_ARMOR); }
    } WHEN {
        TURN { MOVE(player, MOVE_PHOTON_GEYSER, criticalHit: TRUE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PHOTON_GEYSER, player, );
        HP_BAR(opponent);
        MESSAGE("A critical hit!");
    }
}
