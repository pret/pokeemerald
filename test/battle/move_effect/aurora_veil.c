#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gBattleMoves[MOVE_AURORA_VEIL].effect == EFFECT_AURORA_VEIL);
}

SINGLE_BATTLE_TEST("Aurora Veil can only be used in Hail and Snow")
{
    u32 move;
    PARAMETRIZE { move = MOVE_CELEBRATE; }
    PARAMETRIZE { move = MOVE_HAIL; }
    PARAMETRIZE { move = MOVE_SNOWSCAPE; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, move); MOVE(player, MOVE_AURORA_VEIL); }
    } SCENE {
        if (move == MOVE_CELEBRATE)
            MESSAGE("But it failed!");
        else
            NOT MESSAGE("But it failed!");
    }
}

TO_DO_BATTLE_TEST("Aurora Veil reduces damage done to the user by half in singles")
TO_DO_BATTLE_TEST("Aurora Veil reduces damage done to the user by roughly a third in doubles")
TO_DO_BATTLE_TEST("Aurora Veil's damage reduction is ignored by Critical Hits")
TO_DO_BATTLE_TEST("Aurora Veil's damage reduction doesn't stack with Reflect or Light Screen")
TO_DO_BATTLE_TEST("Aurora Veil doesn't reduce confusion damage")
TO_DO_BATTLE_TEST("Aurora Veil doesn't reduce damage done by moves that do direct damage") // Bide, Counter, Endeavor, Final Gambit, Metal Burst, Mirror Coat, Psywave, Seismic Toss, Sonic Boom, Super Fang
