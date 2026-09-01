#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_AURORA_VEIL) == EFFECT_AURORA_VEIL);
}

SINGLE_BATTLE_TEST("Aurora Veil can only be used in Hail and Snow")
{
    enum Move move;
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

SINGLE_BATTLE_TEST("Aurora Veil will prevent Protean activation if it fails due to no Snow/Hail")
{
    GIVEN {
        PLAYER(SPECIES_KECLEON) { Ability(ABILITY_PROTEAN); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_AURORA_VEIL); }
    } SCENE {
        MESSAGE("But it failed!");
        NOT ABILITY_POPUP(player, ABILITY_PROTEAN);
    }
}

SINGLE_BATTLE_TEST("Aurora Veil wont prevent Protean activation when it fails due to being set up already")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_KECLEON) { Ability(ABILITY_PROTEAN); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SNOWSCAPE); MOVE(player, MOVE_AURORA_VEIL); }
        TURN { SWITCH(player, 1); }
        TURN { MOVE(player, MOVE_AURORA_VEIL); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_PROTEAN);
        MESSAGE("But it failed!");
    }
}

TO_DO_BATTLE_TEST("Aurora Veil reduces damage done to the user by half in singles")
TO_DO_BATTLE_TEST("Aurora Veil reduces damage done to the user by roughly a third in doubles")
TO_DO_BATTLE_TEST("Aurora Veil's damage reduction is ignored by Critical Hits")
TO_DO_BATTLE_TEST("Aurora Veil's damage reduction doesn't stack with Reflect or Light Screen")
TO_DO_BATTLE_TEST("Aurora Veil doesn't reduce confusion damage")
TO_DO_BATTLE_TEST("Aurora Veil doesn't reduce damage done by moves that do direct damage") // Bide, Counter, Endeavor, Final Gambit, Metal Burst, Mirror Coat, Psywave, Seismic Toss, Sonic Boom, Super Fang
