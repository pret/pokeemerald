#include "global.h"
#include "test/battle.h"

DOUBLE_BATTLE_TEST("Speed Down: Cotton Spore does not fail if it is blocked by one target")
{
    enum Ability abilityOne, abilityTwo;

    PARAMETRIZE { abilityOne = ABILITY_OVERCOAT; abilityTwo = ABILITY_SKILL_LINK; }
    PARAMETRIZE { abilityOne = ABILITY_SKILL_LINK; abilityTwo = ABILITY_OVERCOAT; }

    GIVEN {
        ASSUME_STAT_CHANGE(MOVE_COTTON_SPORE, speed: -2);
        ASSUME(GetMoveTarget(MOVE_COTTON_SPORE) == TARGET_BOTH);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_SHELLDER) { Ability(abilityOne); }
        OPPONENT(SPECIES_SHELLDER) { Ability(abilityTwo); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_COTTON_SPORE); }
    } SCENE {
        if (abilityOne == ABILITY_OVERCOAT) {
            ABILITY_POPUP(opponentLeft, ABILITY_OVERCOAT);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_COTTON_SPORE, playerLeft);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentRight);
        }
        else if (abilityTwo == ABILITY_OVERCOAT) {
            ABILITY_POPUP(opponentRight, ABILITY_OVERCOAT);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_COTTON_SPORE, playerLeft);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentLeft);
        }
    }
}
