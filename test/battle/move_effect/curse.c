#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gMovesInfo[MOVE_CURSE].effect == EFFECT_CURSE);
}

SINGLE_BATTLE_TEST("Curse lowers Speed, raises Attack, and raises Defense when used by non-Ghost-types")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_CURSE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CURSE, player);
        MESSAGE("Wobbuffet's Speed fell!");
        MESSAGE("Wobbuffet's Attack rose!");
        MESSAGE("Wobbuffet's Defense rose!");
    }
}

SINGLE_BATTLE_TEST("Curse cuts the user's HP in half when used by Ghost-types")
{
    GIVEN {
        PLAYER(SPECIES_MISDREAVUS);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_CURSE); }
    } SCENE {
        s32 maxHP = GetMonData(&PLAYER_PARTY[0], MON_DATA_MAX_HP);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CURSE, player);
        HP_BAR(player, hp: maxHP / 2);
    }
}
