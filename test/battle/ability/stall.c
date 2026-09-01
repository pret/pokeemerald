#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Stall causes the user to move last in its priority bracket")
{
    GIVEN {
        PLAYER(SPECIES_SABLEYE) { Speed(100); Ability(ABILITY_STALL); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(1); }
    } WHEN {
        TURN {}
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
    }
}

SINGLE_BATTLE_TEST("Stall causes the user to move last in its priority bracket (Trick Room)")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_TRICK_ROOM) == EFFECT_TRICK_ROOM);
        PLAYER(SPECIES_SABLEYE) { Speed(1); Ability(ABILITY_STALL); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(100); }
    } WHEN {
        TURN { MOVE(player, MOVE_TRICK_ROOM); }
        TURN {}
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TRICK_ROOM, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
    }
}

SINGLE_BATTLE_TEST("Stall respects Speed when both battlers have Stall")
{
    GIVEN {
        PLAYER(SPECIES_SABLEYE) { Speed(100); Ability(ABILITY_STALL); }
        OPPONENT(SPECIES_SABLEYE) { Speed(1); Ability(ABILITY_STALL); }
    } WHEN {
        TURN {}
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
    }
}

SINGLE_BATTLE_TEST("Stall and Lagging Tail action order depends on Speed")
{
    u32 speed;

    PARAMETRIZE { speed = 99; }
    PARAMETRIZE { speed = 101; }

    GIVEN {
        ASSUME(gItemsInfo[ITEM_LAGGING_TAIL].holdEffect == HOLD_EFFECT_LAGGING_TAIL);
        PLAYER(SPECIES_SABLEYE) { Speed(100); Ability(ABILITY_STALL); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(speed); Item(ITEM_LAGGING_TAIL); }
    } WHEN {
        TURN {}
    } SCENE {
        if (speed < 100)
        {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
        }
        else
        {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
        }
    }
}

SINGLE_BATTLE_TEST("Stall and Lagging Tail action order depends on Speed (Trick Room)")
{
    u32 speed;

    PARAMETRIZE { speed = 99; }
    PARAMETRIZE { speed = 101; }

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_TRICK_ROOM) == EFFECT_TRICK_ROOM);
        ASSUME(gItemsInfo[ITEM_LAGGING_TAIL].holdEffect == HOLD_EFFECT_LAGGING_TAIL);
        PLAYER(SPECIES_SABLEYE) { Speed(100); Ability(ABILITY_STALL); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(speed); Item(ITEM_LAGGING_TAIL); }
    } WHEN {
        TURN { MOVE(player, MOVE_TRICK_ROOM); }
        TURN {}
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TRICK_ROOM, player);
        if (speed < 100)
        {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
        }
        else
        {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
        }
    }
}

SINGLE_BATTLE_TEST("Stall user can move before faster battlers when Quick Claw activates")
{
    PASSES_RANDOMLY(2, 10, RNG_QUICK_CLAW);
    GIVEN {
        ASSUME(gItemsInfo[ITEM_QUICK_CLAW].holdEffect == HOLD_EFFECT_QUICK_CLAW);
        PLAYER(SPECIES_SABLEYE) { Speed(1); Ability(ABILITY_STALL); Item(ITEM_QUICK_CLAW); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(100); }
    } WHEN {
        TURN {}
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
    }
}
