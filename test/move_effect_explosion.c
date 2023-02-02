#include "global.h"
#include "test_battle.h"

ASSUMPTIONS
{
    ASSUME(gBattleMoves[MOVE_EXPLOSION].effect == EFFECT_EXPLOSION);
}

SINGLE_BATTLE_TEST("Explosion causes the user to faint")
{
    u16 remainingHP;
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_EXPLOSION); }
    } SCENE {
        HP_BAR(player, hp: 0);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EXPLOSION, player);
    }
}

SINGLE_BATTLE_TEST("Explosion causes the user to faint even if it misses")
{
    u16 remainingHP;
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_EXPLOSION, hit: FALSE); }
    } SCENE {
        HP_BAR(player, hp: 0);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EXPLOSION, player);
    }
}

SINGLE_BATTLE_TEST("Explosion causes the user to faint even if it has no effect")
{
    u16 remainingHP;
    GIVEN {
        ASSUME(gBattleMoves[MOVE_EXPLOSION].type == TYPE_NORMAL);
        ASSUME(gSpeciesInfo[SPECIES_GASTLY].types[0] == TYPE_GHOST);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_GASTLY);
    } WHEN {
        TURN { MOVE(player, MOVE_EXPLOSION); }
    } SCENE {
        HP_BAR(player, hp: 0);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EXPLOSION, player);
        MESSAGE("It doesn't affect Foe Gastly…");
        NOT HP_BAR(opponent);
    }
}
