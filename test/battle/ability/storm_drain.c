#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Storm Drain absorbs Water-type moves and increases the Sp. Attack [Gen5+]")
{
    GIVEN {
        ASSUME(gMovesInfo[MOVE_WATER_GUN].type == TYPE_WATER);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_GASTRODON_EAST_SEA) { Ability(ABILITY_STORM_DRAIN); }
    } WHEN {
        TURN { MOVE(player, MOVE_WATER_GUN); MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
        if (B_REDIRECT_ABILITY_IMMUNITY >= GEN_5) {
            NONE_OF {
                ANIMATION(ANIM_TYPE_MOVE, MOVE_WATER_GUN, player);
                HP_BAR(opponent);
            };
            ABILITY_POPUP(opponent, ABILITY_STORM_DRAIN);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
            MESSAGE("Foe Gastrodon's Sp. Atk rose!");
        } else {
            NONE_OF {
                ABILITY_POPUP(opponent, ABILITY_STORM_DRAIN);
                ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
                MESSAGE("Foe Gastrodon's Sp. Atk rose!");
            };
            ANIMATION(ANIM_TYPE_MOVE, MOVE_WATER_GUN, player);
            HP_BAR(opponent);
        }
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
    }
}

DOUBLE_BATTLE_TEST("Storm Drain forces single-target Water-type moves to target the Pokémon with this Ability.")
{
    GIVEN {
        ASSUME(gMovesInfo[MOVE_WATER_GUN].type == TYPE_WATER);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_GASTRODON_EAST_SEA) { Ability(ABILITY_STORM_DRAIN); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {
            MOVE(playerLeft, MOVE_WATER_GUN, target: opponentRight);
            MOVE(playerRight, MOVE_WATER_GUN, target: opponentRight);
            MOVE(opponentLeft, MOVE_CELEBRATE);
            MOVE(opponentRight, MOVE_CELEBRATE);
        }
    } SCENE {
        if (B_REDIRECT_ABILITY_IMMUNITY >= GEN_5) {
            NONE_OF {
                HP_BAR(opponentLeft);
                HP_BAR(opponentRight);
            };
            ABILITY_POPUP(opponentLeft, ABILITY_STORM_DRAIN);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentLeft);
            MESSAGE("Foe Gastrodon's Sp. Atk rose!");
            ABILITY_POPUP(opponentLeft, ABILITY_STORM_DRAIN);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentLeft);
            MESSAGE("Foe Gastrodon's Sp. Atk rose!");
        } else {
            NONE_OF {
                HP_BAR(opponentRight);
            };
            ANIMATION(ANIM_TYPE_MOVE, MOVE_WATER_GUN, playerLeft);
            HP_BAR(opponentLeft);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_WATER_GUN, playerRight);
            HP_BAR(opponentLeft);
        }
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponentRight);
    }
}
