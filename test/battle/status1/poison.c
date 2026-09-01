#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Poison deals 1/8th damage per turn")
{
    u32 j;
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Status1(STATUS1_POISON); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        for (j = 0; j < 4; j++)
            TURN {}
    } SCENE {
        s32 maxHP = GetMonData(&PLAYER_PARTY[0], MON_DATA_MAX_HP);
        for (j = 0; j < 4; j++)
            HP_BAR(player, damage: maxHP / 8);
    }
}

SINGLE_BATTLE_TEST("Poison can't bad poison a poison or steel type")
{
    enum Species species;

    PARAMETRIZE { species = SPECIES_BELDUM; }
    PARAMETRIZE { species = SPECIES_BULBASAUR; }

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_POISON_GAS) == EFFECT_NON_VOLATILE_STATUS);
        ASSUME(GetMoveNonVolatileStatus(MOVE_POISON_GAS) == MOVE_EFFECT_POISON);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(species);
    } WHEN {
        TURN { MOVE(player, MOVE_POISON_GAS); }
    } SCENE {
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_POISON_GAS, player);
            ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PSN, opponent);
            STATUS_ICON(opponent, poison: TRUE);
        }
    }
}
