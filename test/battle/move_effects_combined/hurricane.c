#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveAccuracy(MOVE_HURRICANE) == 70);
    ASSUME(MoveAlwaysHitsInRain(MOVE_HURRICANE) == TRUE);
    ASSUME(MoveHas50AccuracyInSun(MOVE_HURRICANE) == TRUE);
}

SINGLE_BATTLE_TEST("Hurricane's accuracy is lowered to 50% in Sunlight")
{
    PASSES_RANDOMLY(50, 100, RNG_ACCURACY);
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SUNNY_DAY); MOVE(opponent, MOVE_HURRICANE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HURRICANE, opponent);
    }
}

SINGLE_BATTLE_TEST("Hurricane bypasses accuracy checks in Rain")
{
    PASSES_RANDOMLY(100, 100, RNG_ACCURACY);
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_RAIN_DANCE); MOVE(player, MOVE_HURRICANE); }
    } SCENE {
        NONE_OF { MESSAGE("The opposing Wobbuffet avoided the attack!"); }
    }
}

SINGLE_BATTLE_TEST("Hurricane can hit airborne targets (Fly, Bounce)")
{
    enum Move move;
    PARAMETRIZE { move = MOVE_FLY; }
    PARAMETRIZE { move = MOVE_BOUNCE; }
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_FLY) == EFFECT_SEMI_INVULNERABLE);
        ASSUME(GetTwoTurnMoveSemiInvulnerability(MOVE_FLY) == STATE_ON_AIR);
        ASSUME(GetMoveEffect(MOVE_BOUNCE) == EFFECT_SEMI_INVULNERABLE);
        ASSUME(GetTwoTurnMoveSemiInvulnerability(MOVE_BOUNCE) == STATE_ON_AIR);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Moves(move); }
    } WHEN {
        TURN { MOVE(opponent, move); MOVE(player, MOVE_HURRICANE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HURRICANE, player);
        NONE_OF { MESSAGE("The opposing Wobbuffet avoided the attack!"); }
    }
}

DOUBLE_BATTLE_TEST("Hurricane can hit airborne targets (Sky Drop)")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_SKY_DROP) == EFFECT_SKY_DROP);
        ASSUME(GetTwoTurnMoveSemiInvulnerability(MOVE_SKY_DROP) == STATE_ON_AIR);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_SKY_DROP, target: opponentLeft); MOVE(playerRight, MOVE_HURRICANE, target: playerLeft); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SKY_DROP, playerLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HURRICANE, playerRight);
        NONE_OF { MESSAGE("The opposing Wobbuffet avoided the attack!"); }
    }
}
