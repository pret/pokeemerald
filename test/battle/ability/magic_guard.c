#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Magic Guard prevents recoil damage to the user")
{
    GIVEN {
        ASSUME(GetMoveRecoil(MOVE_DOUBLE_EDGE) == 33);
        PLAYER(SPECIES_CLEFABLE) { Ability(ABILITY_MAGIC_GUARD); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_DOUBLE_EDGE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DOUBLE_EDGE, player);
        HP_BAR(opponent);
        NOT HP_BAR(player);
    }
}

SINGLE_BATTLE_TEST("Magic Guard ignores immobilization that can be caused by paralysis")
{
    if (B_MAGIC_GUARD == GEN_4)
        PASSES_RANDOMLY(1, 1, RNG_PARALYSIS);
    else if (B_PARALYSIS_CHANCE >= GEN_CHAMPIONS)
        PASSES_RANDOMLY(7, 8, RNG_PARALYSIS);
    else
        PASSES_RANDOMLY(75, 100, RNG_PARALYSIS);
    GIVEN {
        PLAYER(SPECIES_CLEFABLE) { Ability(ABILITY_MAGIC_GUARD); Status1(STATUS1_PARALYSIS); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
    }
}

SINGLE_BATTLE_TEST("Magic Guard does not ignore speed stat changes caused by paralysis")
{
    GIVEN {
        PLAYER(SPECIES_CLEFABLE) { Speed(100); Ability(ABILITY_MAGIC_GUARD); Status1(STATUS1_PARALYSIS); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(99); }
    } WHEN {
        TURN {
            MOVE(opponent, MOVE_CELEBRATE);
            MOVE(player, MOVE_CELEBRATE, WITH_RNG(RNG_PARALYSIS, FALSE));
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
    }
}

SINGLE_BATTLE_TEST("Magic Guard prevents Rough Skin damage")
{
    GIVEN {
        ASSUME(MoveMakesContact(MOVE_POUND));
        PLAYER(SPECIES_CLEFABLE) { Ability(ABILITY_MAGIC_GUARD); }
        OPPONENT(SPECIES_CARVANHA) { Ability(ABILITY_ROUGH_SKIN); }
    } WHEN {
        TURN { MOVE(player, MOVE_POUND); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POUND, player);
        HP_BAR(opponent);
        ABILITY_POPUP(opponent, ABILITY_ROUGH_SKIN);
        NOT HP_BAR(player);
    }
}
