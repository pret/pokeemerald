#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gMovesInfo[MOVE_SLEEP_TALK].effect == EFFECT_SLEEP_TALK);
    ASSUME(gMovesInfo[MOVE_RAZOR_WIND].sleepTalkBanned == TRUE);
    ASSUME(gMovesInfo[MOVE_FLY].sleepTalkBanned == TRUE);
    ASSUME(gMovesInfo[MOVE_DIG].sleepTalkBanned == TRUE);
}

SINGLE_BATTLE_TEST("Sleep Talk fails if not asleep")
{
    u32 status;
    PARAMETRIZE { status = STATUS1_SLEEP; }
    PARAMETRIZE { status = STATUS1_NONE; }
    
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Status1(status); Moves(MOVE_SLEEP_TALK, MOVE_TACKLE, MOVE_POUND, MOVE_SCRATCH); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SLEEP_TALK); }
    } SCENE {
        if (status == STATUS1_SLEEP) {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_SLEEP_TALK, player);
            NOT MESSAGE("But it failed!");
        }
        else {
            NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_SLEEP_TALK, player);
            MESSAGE("But it failed!");
        }
    }
}


SINGLE_BATTLE_TEST("Sleep Talk works if user has Comatose")
{
    
    GIVEN {
        PLAYER(SPECIES_KOMALA) { Moves(MOVE_SLEEP_TALK, MOVE_TACKLE, MOVE_POUND, MOVE_SCRATCH); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SLEEP_TALK); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SLEEP_TALK, player);
        NOT MESSAGE("But it failed!");
    }
}

SINGLE_BATTLE_TEST("Sleep Talk fails if no moves work")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Status1(STATUS1_SLEEP); Moves(MOVE_SLEEP_TALK, MOVE_RAZOR_WIND, MOVE_FLY, MOVE_DIG); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SLEEP_TALK); }
    } SCENE {
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_SLEEP_TALK, player);
        MESSAGE("But it failed!");
    }
}

SINGLE_BATTLE_TEST("Sleep Talk can still use moves with no PP")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Status1(STATUS1_SLEEP); MovesWithPP({MOVE_SLEEP_TALK, 10}, {MOVE_TACKLE, 0}, {MOVE_FLY, 10}, {MOVE_DIG, 10}); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SLEEP_TALK); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SLEEP_TALK, player);
        NOT MESSAGE("But it failed!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE);
    }
}

SINGLE_BATTLE_TEST("Sleep Talk can use moves while choiced into Sleep Talk")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_CHOICE_BAND); Status1(STATUS1_SLEEP); Moves(MOVE_SLEEP_TALK, MOVE_TACKLE, MOVE_FLY, MOVE_DIG); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SLEEP_TALK); }
        TURN { MOVE(player, MOVE_SLEEP_TALK); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SLEEP_TALK, player);
        NOT MESSAGE("But it failed!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SLEEP_TALK, player);
        NOT MESSAGE("But it failed!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE);
    }
}
