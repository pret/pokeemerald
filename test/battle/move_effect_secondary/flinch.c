#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(MoveHasAdditionalEffect(MOVE_HEADBUTT, MOVE_EFFECT_FLINCH) == TRUE);
}

SINGLE_BATTLE_TEST("Headbutt flinches the target if attacker is faster")
{
    bool8 isFaster;
    u16 spdPlayer, spdOpponent;

    PARAMETRIZE { isFaster = TRUE; spdPlayer = 10; spdOpponent = 5; }
    PARAMETRIZE { isFaster = FALSE; spdPlayer = 5; spdOpponent = 10; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(spdPlayer); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(spdOpponent); }
    } WHEN {
        TURN { MOVE(player, MOVE_HEADBUTT); }
        TURN { MOVE(player, MOVE_HEADBUTT); }
    } SCENE {
        // 1st turn
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HEADBUTT, player);
        HP_BAR(opponent);
        if (isFaster) {
            MESSAGE("The opposing Wobbuffet flinched and couldn't move!");
            NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
        } else {
            NOT MESSAGE("The opposing Wobbuffet flinched and couldn't move!");
        }

        // 2nd turn
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HEADBUTT, player);
        HP_BAR(opponent);
        if (isFaster) {
            MESSAGE("The opposing Wobbuffet flinched and couldn't move!");
            NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
        } else {
            NOT MESSAGE("The opposing Wobbuffet flinched and couldn't move!");
        }
    }
}

SINGLE_BATTLE_TEST("Protect always works when used after flinching")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(5); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(100); }
    } WHEN {
        TURN { MOVE(player, MOVE_PROTECT); MOVE(opponent, MOVE_HEADBUTT); }
        TURN { MOVE(player, MOVE_SCRATCH); MOVE(opponent, MOVE_HEADBUTT); }
        TURN { MOVE(player, MOVE_PROTECT); MOVE(opponent, MOVE_HEADBUTT); }
    } SCENE {
        // 1st turn
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PROTECT, player);
        MESSAGE("Wobbuffet protected itself!");

        // 2nd turn
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HEADBUTT, opponent);
        HP_BAR(player);
        MESSAGE("Wobbuffet flinched and couldn't move!");
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);

        // 3rd turn
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PROTECT, player);
        MESSAGE("Wobbuffet protected itself!");
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_HEADBUTT, opponent);
    }
}

SINGLE_BATTLE_TEST("Headbutt flinches 30% of the time")
{
    PASSES_RANDOMLY(30, 100, RNG_SECONDARY_EFFECT);
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_HEADBUTT); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HEADBUTT, player);
        MESSAGE("The opposing Wobbuffet flinched and couldn't move!");
    }
}
