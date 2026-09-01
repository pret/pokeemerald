#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_MIRACLE_EYE) == EFFECT_MIRACLE_EYE);
}

SINGLE_BATTLE_TEST("Miracle Eye removes Dark-type immunity to Psychic-type moves")
{
    GIVEN {
        ASSUME(GetMoveType(MOVE_PSYCHIC) == TYPE_PSYCHIC);
        ASSUME(GetSpeciesType(SPECIES_UMBREON, 0) == TYPE_DARK);
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_MIRACLE_EYE, MOVE_PSYCHIC); }
        OPPONENT(SPECIES_UMBREON) { Moves(MOVE_SPLASH); }
    } WHEN {
        TURN { MOVE(player, MOVE_PSYCHIC); MOVE(opponent, MOVE_SPLASH); }
        TURN { MOVE(player, MOVE_MIRACLE_EYE); MOVE(opponent, MOVE_SPLASH); }
        TURN { MOVE(player, MOVE_PSYCHIC); MOVE(opponent, MOVE_SPLASH); }
    } SCENE {
        NOT HP_BAR(opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MIRACLE_EYE, player);
        HP_BAR(opponent);
    }
}

SINGLE_BATTLE_TEST("Miracle Eye always hits unless the target is semi-invulnerable")
{
    bool32 semiInvulnerable = FALSE;
    PARAMETRIZE { semiInvulnerable = FALSE; }
    PARAMETRIZE { semiInvulnerable = TRUE; }

    GIVEN {
        ASSUME_STAT_CHANGE(MOVE_DOUBLE_TEAM, evasion: +1);
        ASSUME(GetMoveEffect(MOVE_FLY) == EFFECT_SEMI_INVULNERABLE);
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_MIRACLE_EYE, MOVE_SPLASH); Speed(10); }
        OPPONENT(SPECIES_SQUAWKABILLY) { Moves(MOVE_DOUBLE_TEAM, MOVE_FLY); Speed(20); }
    } WHEN {
        if (semiInvulnerable)
            TURN { MOVE(player, MOVE_MIRACLE_EYE); MOVE(opponent, MOVE_FLY); }
        else
            TURN { MOVE(player, MOVE_MIRACLE_EYE); MOVE(opponent, MOVE_DOUBLE_TEAM); }

        if (semiInvulnerable)
            TURN { MOVE(player, MOVE_SPLASH); SKIP_TURN(opponent); }
    } SCENE {
        if (semiInvulnerable) {
            NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_MIRACLE_EYE, player);
        } else {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_DOUBLE_TEAM, opponent);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_MIRACLE_EYE, player);
        }
    }
}

SINGLE_BATTLE_TEST("Miracle Eye causes moves against the target to ignore positive evasion stat stages")
{
    PASSES_RANDOMLY(100, 100, RNG_ACCURACY);
    GIVEN {
        ASSUME_STAT_CHANGE(MOVE_DOUBLE_TEAM, evasion: +1);
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_MIRACLE_EYE, MOVE_SCRATCH); Speed(10); }
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_DOUBLE_TEAM, MOVE_SPLASH); Speed(20); }
    } WHEN {
        TURN { MOVE(player, MOVE_MIRACLE_EYE); MOVE(opponent, MOVE_DOUBLE_TEAM); }
        TURN { MOVE(player, MOVE_SCRATCH); MOVE(opponent, MOVE_SPLASH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DOUBLE_TEAM, opponent);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MIRACLE_EYE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        HP_BAR(opponent);
    }
}

SINGLE_BATTLE_TEST("Miracle Eye fails if the target is already affected by Miracle Eye (Gen5+)")
{
    GIVEN {
        WITH_CONFIG(B_MIRACLE_EYE_FAIL, GEN_5);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_MIRACLE_EYE); }
        TURN { MOVE(player, MOVE_MIRACLE_EYE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MIRACLE_EYE, player);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_MIRACLE_EYE, player);
        MESSAGE("But it failed!");
    }
}

SINGLE_BATTLE_TEST("Miracle Eye does not fail if the target is already affected by Miracle Eye (Gen4)")
{
    GIVEN {
        WITH_CONFIG(B_MIRACLE_EYE_FAIL, GEN_4);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_MIRACLE_EYE); }
        TURN { MOVE(player, MOVE_MIRACLE_EYE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MIRACLE_EYE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MIRACLE_EYE, player);
        NOT MESSAGE("But it failed!");
    }
}
