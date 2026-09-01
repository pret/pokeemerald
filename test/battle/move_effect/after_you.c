#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_AFTER_YOU) == EFFECT_AFTER_YOU);
}

DOUBLE_BATTLE_TEST("After You makes the target move after user")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(4); }
        PLAYER(SPECIES_WYNAUT) { Speed(1); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(3); }
        OPPONENT(SPECIES_WYNAUT) { Speed(2); }
    } WHEN {
        TURN {
            MOVE(playerLeft, MOVE_AFTER_YOU, target: playerRight);
            MOVE(playerRight, MOVE_CELEBRATE);
            MOVE(opponentLeft, MOVE_CELEBRATE);
            MOVE(opponentRight, MOVE_CELEBRATE);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_AFTER_YOU, playerLeft);
        MESSAGE("Wynaut took the kind offer!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, playerRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponentRight);
    }
}

DOUBLE_BATTLE_TEST("After You does nothing if the target has already moved")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(4); }
        PLAYER(SPECIES_WYNAUT) { Speed(1); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(3); }
        OPPONENT(SPECIES_WYNAUT) { Speed(2); }
    } WHEN {
        TURN {
            MOVE(playerLeft, MOVE_CELEBRATE);
            MOVE(playerRight, MOVE_CELEBRATE);
            MOVE(opponentLeft, MOVE_CELEBRATE);
            MOVE(opponentRight, MOVE_AFTER_YOU, target: opponentLeft);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, playerLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponentLeft);
        MESSAGE("The opposing Wynaut used After You!");
        MESSAGE("But it failed!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, playerRight);
    }
}

DOUBLE_BATTLE_TEST("After You calculates correct turn order if only one Pokémon is left on the opposing side")
{
    GIVEN {
        PLAYER(SPECIES_GRENINJA) { Speed(120); }
        PLAYER(SPECIES_REGIROCK) { Speed(10); }
        OPPONENT(SPECIES_PIDGEOT) { Speed(100); }
        OPPONENT(SPECIES_DRAGONITE) { Speed(60); }
    } WHEN {
        TURN {
            MOVE(playerLeft, MOVE_AFTER_YOU, target: playerRight);
            MOVE(playerRight, MOVE_STONE_EDGE, target: opponentLeft);
            MOVE(opponentRight, MOVE_CELEBRATE);
        }
        TURN {
            MOVE(playerLeft, MOVE_AFTER_YOU, target: playerRight);
            MOVE(playerRight, MOVE_STONE_EDGE, target: opponentRight);
            MOVE(opponentRight, MOVE_CELEBRATE);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_AFTER_YOU, playerLeft);
        MESSAGE("Regirock took the kind offer!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STONE_EDGE, playerRight);
        HP_BAR(opponentLeft);
        MESSAGE("The opposing Pidgeot fainted!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponentRight);

        ANIMATION(ANIM_TYPE_MOVE, MOVE_AFTER_YOU, playerLeft);
        MESSAGE("Regirock took the kind offer!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STONE_EDGE, playerRight);
        HP_BAR(opponentRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponentRight);
    }
}

DOUBLE_BATTLE_TEST("After You fails if the turn order remains the same after After You (Gen5-7)")
{
    GIVEN {
        WITH_CONFIG(B_AFTER_YOU_TURN_ORDER, GEN_7);
        PLAYER(SPECIES_WOBBUFFET) { Speed(4); }
        PLAYER(SPECIES_WYNAUT) { Speed(1); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(2); }
        OPPONENT(SPECIES_WYNAUT) { Speed(3); }
    } WHEN {
        TURN {
            MOVE(playerLeft, MOVE_CELEBRATE);
            MOVE(playerRight, MOVE_CELEBRATE);
            MOVE(opponentLeft, MOVE_CELEBRATE);
            MOVE(opponentRight, MOVE_AFTER_YOU, target: opponentLeft);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, playerLeft);
        MESSAGE("The opposing Wynaut used After You!");
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_AFTER_YOU, opponentRight);
        MESSAGE("But it failed!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, playerRight);
    }
}

DOUBLE_BATTLE_TEST("After You doesn't fail if the turn order remains the same after After You (Gen8+)")
{
    GIVEN {
        WITH_CONFIG(B_AFTER_YOU_TURN_ORDER, GEN_8);
        PLAYER(SPECIES_WOBBUFFET) { Speed(4); }
        PLAYER(SPECIES_WYNAUT) { Speed(1); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(2); }
        OPPONENT(SPECIES_WYNAUT) { Speed(3); }
    } WHEN {
        TURN {
            MOVE(playerLeft, MOVE_CELEBRATE);
            MOVE(playerRight, MOVE_CELEBRATE);
            MOVE(opponentLeft, MOVE_CELEBRATE);
            MOVE(opponentRight, MOVE_AFTER_YOU, target: opponentLeft);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, playerLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_AFTER_YOU, opponentRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, playerRight);
    }
}

DOUBLE_BATTLE_TEST("After You ignores the effects of Quash")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_QUASH) == EFFECT_QUASH);
        PLAYER(SPECIES_WOBBUFFET) { Speed(4); }
        PLAYER(SPECIES_WYNAUT) { Speed(1); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(2); }
        OPPONENT(SPECIES_WYNAUT) { Speed(3); }
    } WHEN {
        TURN {
            MOVE(playerLeft, MOVE_QUASH, target: opponentLeft);
            MOVE(playerRight, MOVE_CELEBRATE);
            MOVE(opponentLeft, MOVE_CELEBRATE);
            MOVE(opponentRight, MOVE_AFTER_YOU, target: opponentLeft);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_QUASH, playerLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_AFTER_YOU, opponentRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, playerRight);
    }
}
