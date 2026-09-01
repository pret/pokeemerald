#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_SNORE) == EFFECT_SNORE);
}

SINGLE_BATTLE_TEST("Snore fails if not asleep")
{
    u32 status;
    PARAMETRIZE { status = STATUS1_SLEEP; }
    PARAMETRIZE { status = STATUS1_NONE; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Status1(status); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SNORE); }
    } SCENE {
        if (status == STATUS1_SLEEP) {
            MESSAGE("Wobbuffet is fast asleep.");
            ANIMATION(ANIM_TYPE_MOVE, MOVE_SNORE, player);
            NOT MESSAGE("But it failed!");
        }
        else {
            NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_SNORE, player);
            MESSAGE("But it failed!");
        }
    }
}

SINGLE_BATTLE_TEST("Snore works if user has Comatose")
{

    GIVEN {
        PLAYER(SPECIES_KOMALA);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SNORE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SNORE, player);
        NOT MESSAGE("But it failed!");
    }
}

SINGLE_BATTLE_TEST("Snore fails if user is throat chopped")
{
    GIVEN {
        ASSUME(MoveHasAdditionalEffect(MOVE_THROAT_CHOP, MOVE_EFFECT_THROAT_CHOP));
        ASSUME(IsSoundMove(MOVE_SNORE) == TRUE);
        PLAYER(SPECIES_WOBBUFFET) { Status1(STATUS1_SLEEP); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_THROAT_CHOP); MOVE(player, MOVE_SNORE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_THROAT_CHOP, opponent);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_SNORE, player);
    }
}
