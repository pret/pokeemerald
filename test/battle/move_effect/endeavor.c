#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_ENDEAVOR) == EFFECT_ENDEAVOR);
}

SINGLE_BATTLE_TEST("Endeavor causes the target's HP to equal the user's current HP")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { HP(1); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_ENDEAVOR); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ENDEAVOR, player);
    } THEN {
        EXPECT_EQ(player->hp, opponent->hp);
    }
}

SINGLE_BATTLE_TEST("Endeavor fails on Ghost-type Pokémon")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { HP(1); }
        OPPONENT(SPECIES_GASTLY);
    } WHEN {
        TURN { MOVE(player, MOVE_ENDEAVOR); }
    } SCENE {
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_ENDEAVOR, player);
    }
}

SINGLE_BATTLE_TEST("Endeavor fails to change HP if the target has less HP than the user")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { HP(10); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(9); }
    } WHEN {
        TURN { MOVE(player, MOVE_ENDEAVOR); }
    } SCENE {
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_ENDEAVOR, player);
    }
}
