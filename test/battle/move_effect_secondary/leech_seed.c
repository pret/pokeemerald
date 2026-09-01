#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(MoveHasAdditionalEffect(MOVE_SAPPY_SEED, MOVE_EFFECT_LEECH_SEED) == TRUE);
}

SINGLE_BATTLE_TEST("Sappy Seed can seed the target")
{
    GIVEN {
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SAPPY_SEED); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SAPPY_SEED, player);
        MESSAGE("The opposing Wobbuffet was seeded!");
        MESSAGE("The opposing Wobbuffet's health is sapped by Leech Seed!");
    }
}

SINGLE_BATTLE_TEST("Sappy Seed is not going to seed the target if it fails")
{
    GIVEN {
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {
            MOVE(opponent, MOVE_SAND_ATTACK);
            MOVE(player, MOVE_SAPPY_SEED, hit: FALSE);
        }
    } SCENE {
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_SAPPY_SEED, player);
            MESSAGE("The opposing Wobbuffet was seeded!");
            MESSAGE("The opposing Wobbuffet's health is sapped by Leech Seed!");
        }
    }
}
