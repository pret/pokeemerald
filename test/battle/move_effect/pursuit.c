#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_PURSUIT) == EFFECT_PURSUIT);
}

SINGLE_BATTLE_TEST("Pursuit attacks a switching foe")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_ZIGZAGOON);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { SWITCH(player, 1); MOVE(opponent, MOVE_PURSUIT); }
    } SCENE {
        SWITCH_OUT_MESSAGE("Wobbuffet");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PURSUIT, opponent);
        HP_BAR(player);
        SEND_IN_MESSAGE("Zigzagoon");
    }
}

SINGLE_BATTLE_TEST("Pursuit attacks a foe using Volt Switch / U-Turn / Parting Shot to switch out")
{
    enum Move move;
    PARAMETRIZE { move = MOVE_VOLT_SWITCH; }
    PARAMETRIZE { move = MOVE_U_TURN; }
    PARAMETRIZE { move = MOVE_PARTING_SHOT; }
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_VOLT_SWITCH) == EFFECT_HIT_ESCAPE);
        ASSUME(GetMoveEffect(MOVE_U_TURN) == EFFECT_HIT_ESCAPE);
        ASSUME(GetMoveEffect(MOVE_PARTING_SHOT) == EFFECT_PARTING_SHOT);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_ZIGZAGOON);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(player, move); MOVE(opponent, MOVE_PURSUIT); SEND_OUT(player, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, player);
        MESSAGE("Wobbuffet went back to 1!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PURSUIT, opponent);
        SEND_IN_MESSAGE("Zigzagoon");
    }
}

DOUBLE_BATTLE_TEST("Pursuit doesn't attack a foe using Teleport / Baton Pass to switch out")
{
    enum Move move;
    PARAMETRIZE { move = MOVE_TELEPORT; }
    PARAMETRIZE { move = MOVE_BATON_PASS; }
    GIVEN {
        WITH_CONFIG(B_TELEPORT_BEHAVIOR, GEN_8);
        ASSUME(GetMoveEffect(MOVE_QUASH) == EFFECT_QUASH);
        ASSUME(GetMoveEffect(MOVE_TELEPORT) == EFFECT_TELEPORT);
        ASSUME(GetMoveEffect(MOVE_BATON_PASS) == EFFECT_BATON_PASS);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_NIDOKING);
        PLAYER(SPECIES_ZIGZAGOON);
        OPPONENT(SPECIES_WYNAUT);
        OPPONENT(SPECIES_LINOONE);
    } WHEN {
        TURN { MOVE(playerRight, MOVE_QUASH, target: opponentLeft); MOVE(playerLeft, move); MOVE(opponentLeft, MOVE_PURSUIT, target: playerLeft); SEND_OUT(playerLeft, 2); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_QUASH, playerRight);
        ANIMATION(ANIM_TYPE_MOVE, move, playerLeft);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_PURSUIT, opponentLeft);
        SEND_IN_MESSAGE("Zigzagoon");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PURSUIT, opponentLeft);
    }
}

SINGLE_BATTLE_TEST("Pursuit doesn't attack switching foe if user already acted that turn")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_ZIGZAGOON);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(opponent, MOVE_PURSUIT); MOVE(player, MOVE_VOLT_SWITCH); SEND_OUT(player, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PURSUIT, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_VOLT_SWITCH, player);
        MESSAGE("Wobbuffet went back to 1!");
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_PURSUIT, opponent);
        SEND_IN_MESSAGE("Zigzagoon");
    }
}

SINGLE_BATTLE_TEST("Pursuit doubles in power if attacking while target switches out", s16 damage)
{
    u32 speed;
    PARAMETRIZE { speed = 5; }
    PARAMETRIZE { speed = 3; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(4); }
        PLAYER(SPECIES_ZIGZAGOON) { Speed(2); }
        OPPONENT(SPECIES_WYNAUT) { Speed(speed); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_PURSUIT); MOVE(player, MOVE_VOLT_SWITCH); SEND_OUT(player, 1); }
    } SCENE {
        if (speed == 3)
            ANIMATION(ANIM_TYPE_MOVE, MOVE_VOLT_SWITCH, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PURSUIT, opponent);
        HP_BAR(player, captureDamage: &results[i].damage);
        if (speed == 5)
            ANIMATION(ANIM_TYPE_MOVE, MOVE_VOLT_SWITCH, player);
        SEND_IN_MESSAGE("Zigzagoon");
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(2.0), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Pursuit ignores accuracy checks when attacking a switching target")
{
    PASSES_RANDOMLY(100, 100, RNG_ACCURACY);
    GIVEN {
        ASSUME_STAT_CHANGE(MOVE_SAND_ATTACK, accuracy: -1);
        ASSUME(GetMoveEffect(MOVE_HAIL) == EFFECT_WEATHER);
        ASSUME(GetMoveWeatherType(MOVE_HAIL) == BATTLE_WEATHER_HAIL);
        PLAYER(SPECIES_GLACEON) { Ability(ABILITY_SNOW_CLOAK); }
        PLAYER(SPECIES_ZIGZAGOON);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SAND_ATTACK); MOVE(opponent, MOVE_HAIL); }
        TURN { SWITCH(player, 1); MOVE(opponent, MOVE_PURSUIT); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SAND_ATTACK, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HAIL, opponent);
        SWITCH_OUT_MESSAGE("Glaceon");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PURSUIT, opponent);
        SEND_IN_MESSAGE("Zigzagoon");
    }
}

DOUBLE_BATTLE_TEST("Pursuit attacks switching foes even if not targetting them (Gen 4+)")
{
    GIVEN {
        ASSUME(B_PURSUIT_TARGET >= GEN_4);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_ZIGZAGOON);
        PLAYER(SPECIES_GRIMER);
        OPPONENT(SPECIES_WYNAUT);
        OPPONENT(SPECIES_LINOONE);
    } WHEN {
        TURN { SWITCH(playerLeft, 2); MOVE(opponentLeft, MOVE_PURSUIT, target: playerRight); MOVE(opponentRight, MOVE_PURSUIT, target: playerRight); }
    } SCENE {
        SWITCH_OUT_MESSAGE("Wobbuffet");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PURSUIT, opponentLeft);
        HP_BAR(playerLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PURSUIT, opponentRight);
        HP_BAR(playerLeft);
        SEND_IN_MESSAGE("Grimer");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, playerRight);
    }
}

DOUBLE_BATTLE_TEST("Pursuit attacks a switching foe from fastest to slowest")
{
    u32 speedLeft, speedRight;
    PARAMETRIZE { speedLeft = 5; speedRight = 3; }
    PARAMETRIZE { speedLeft = 3; speedRight = 5; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(1); }
        PLAYER(SPECIES_ZIGZAGOON) { Speed(4); }
        PLAYER(SPECIES_GRIMER) { Speed(2); }
        OPPONENT(SPECIES_WYNAUT) { Speed(speedLeft); }
        OPPONENT(SPECIES_LINOONE) { Speed(speedRight); }
    } WHEN {
        TURN { SWITCH(playerLeft, 2); MOVE(opponentLeft, MOVE_PURSUIT, target: playerLeft); MOVE(opponentRight, MOVE_PURSUIT, target: playerLeft); }
    } SCENE {
        SWITCH_OUT_MESSAGE("Wobbuffet");
        if (speedLeft > speedRight) {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_PURSUIT, opponentLeft);
            HP_BAR(playerLeft);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_PURSUIT, opponentRight);
            HP_BAR(playerLeft);
        } else {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_PURSUIT, opponentRight);
            HP_BAR(playerLeft);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_PURSUIT, opponentLeft);
            HP_BAR(playerLeft);
        }
        SEND_IN_MESSAGE("Grimer");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, playerRight);
    }
}

DOUBLE_BATTLE_TEST("Pursuit attacks a switching foe but not switching allies")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_ZIGZAGOON);
        PLAYER(SPECIES_GRIMER);
        OPPONENT(SPECIES_WYNAUT);
        OPPONENT(SPECIES_LINOONE);
        OPPONENT(SPECIES_ABRA);
    } WHEN {
        TURN { SWITCH(playerLeft, 2); SWITCH(opponentRight, 2); MOVE(playerRight, MOVE_PURSUIT, target: opponentRight); MOVE(opponentLeft, MOVE_PURSUIT, target: playerLeft); }
    } SCENE {
        SWITCH_OUT_MESSAGE("Wobbuffet");
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_PURSUIT, playerRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PURSUIT, opponentLeft);
        SEND_IN_MESSAGE("Grimer");
        MESSAGE("2 withdrew Linoone!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PURSUIT, playerRight);
        MESSAGE("2 sent out Abra!");
    }
}

DOUBLE_BATTLE_TEST("Pursuit only attacks the first switching foe")
{
    // This test does not make sense for B_PURSUIT_TARGET < GEN_4
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_ZIGZAGOON);
        PLAYER(SPECIES_GRIMER);
        PLAYER(SPECIES_SUNKERN);
        OPPONENT(SPECIES_WYNAUT);
        OPPONENT(SPECIES_LINOONE);
    } WHEN {
        TURN { SWITCH(playerLeft, 2); SWITCH(playerRight, 3); MOVE(opponentLeft, MOVE_PURSUIT, target: playerLeft); MOVE(opponentRight, MOVE_PURSUIT, target: playerLeft); }
    } SCENE {
        SWITCH_OUT_MESSAGE("Wobbuffet");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PURSUIT, opponentLeft);
        HP_BAR(playerLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PURSUIT, opponentRight);
        HP_BAR(playerLeft);
        SEND_IN_MESSAGE("Grimer");
        SWITCH_OUT_MESSAGE("Zigzagoon");
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_PURSUIT, opponentLeft);
            HP_BAR(playerRight);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_PURSUIT, opponentRight);
            HP_BAR(playerRight);
        }
        SEND_IN_MESSAGE("Sunkern");
    }
}

DOUBLE_BATTLE_TEST("Pursuit only attacks a switching foe if foe is alive")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { HP(1); }
        PLAYER(SPECIES_ZIGZAGOON);
        PLAYER(SPECIES_GRIMER);
        PLAYER(SPECIES_SUNKERN);
        OPPONENT(SPECIES_WYNAUT);
        OPPONENT(SPECIES_LINOONE);
    } WHEN {
        TURN { SWITCH(playerLeft, 2); MOVE(opponentLeft, MOVE_PURSUIT, target: playerLeft); MOVE(opponentRight, MOVE_PURSUIT, target: playerLeft); SEND_OUT(playerLeft, 2); }
    } SCENE {
        SWITCH_OUT_MESSAGE("Wobbuffet");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PURSUIT, opponentLeft);
        HP_BAR(playerLeft);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_PURSUIT, opponentRight);
        MESSAGE("Wobbuffet fainted!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PURSUIT, opponentRight);
        SEND_IN_MESSAGE("Grimer");
    }
}

DOUBLE_BATTLE_TEST("Pursuit attacks the second switching foe if the first faints from pursuit")
{
    // This test does not make sense for B_PURSUIT_TARGET < GEN_4
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { HP(1); }
        PLAYER(SPECIES_ZIGZAGOON);
        PLAYER(SPECIES_GRIMER);
        PLAYER(SPECIES_SUNKERN);
        OPPONENT(SPECIES_WYNAUT);
        OPPONENT(SPECIES_LINOONE);
    } WHEN {
        TURN { SWITCH(playerLeft, 2); SWITCH(playerRight, 3); MOVE(opponentLeft, MOVE_PURSUIT, target: playerLeft); MOVE(opponentRight, MOVE_PURSUIT, target: playerRight); SEND_OUT(playerLeft, 2); }
    } SCENE {
        SWITCH_OUT_MESSAGE("Wobbuffet");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PURSUIT, opponentLeft);
        HP_BAR(playerLeft);
        MESSAGE("Wobbuffet fainted!");
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_PURSUIT, opponentRight);
        SWITCH_OUT_MESSAGE("Zigzagoon");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PURSUIT, opponentRight);
        HP_BAR(playerRight);
        SEND_IN_MESSAGE("Sunkern");
        SEND_IN_MESSAGE("Grimer");
    }
}

DOUBLE_BATTLE_TEST("Pursuit only attacks a switching foe if user is alive")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_ZIGZAGOON);
        PLAYER(SPECIES_GRIMER);
        OPPONENT(SPECIES_WYNAUT) { HP(1); }
        OPPONENT(SPECIES_LINOONE);
        OPPONENT(SPECIES_SUNKERN);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_VOLT_SWITCH, target: opponentLeft); MOVE(opponentLeft, MOVE_PURSUIT, target: playerLeft); SEND_OUT(playerLeft, 2); SEND_OUT(opponentLeft, 2); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_VOLT_SWITCH, playerLeft);
        MESSAGE("The opposing Wynaut fainted!");
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_PURSUIT, opponentLeft);
        SEND_IN_MESSAGE("Grimer");
    }
}

SINGLE_BATTLE_TEST("Pursuit attacks a switching foe but fails if user is asleep")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_ZIGZAGOON);
        OPPONENT(SPECIES_WYNAUT) { Status1(STATUS1_SLEEP_TURN(2)); }
    } WHEN {
        TURN { SWITCH(player, 1); MOVE(opponent, MOVE_PURSUIT); }
    } SCENE {
        SWITCH_OUT_MESSAGE("Wobbuffet");
        MESSAGE("The opposing Wynaut is fast asleep.");
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_PURSUIT, opponent);
        SEND_IN_MESSAGE("Zigzagoon");
    }
}

SINGLE_BATTLE_TEST("Pursuit attacks a switching foe and takes Life Orb damage")
{
    GIVEN {
        ASSUME(gItemsInfo[ITEM_LIFE_ORB].holdEffect == HOLD_EFFECT_LIFE_ORB);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_ZIGZAGOON);
        OPPONENT(SPECIES_WYNAUT) { Item(ITEM_LIFE_ORB); }
    } WHEN {
        TURN { SWITCH(player, 1); MOVE(opponent, MOVE_PURSUIT); }
    } SCENE {
        SWITCH_OUT_MESSAGE("Wobbuffet");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PURSUIT, opponent);
        HP_BAR(opponent);
        SEND_IN_MESSAGE("Zigzagoon");
    }
}

DOUBLE_BATTLE_TEST("Pursuit attacks a switching foe but isn't affected by Follow Me")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_FOLLOW_ME) == EFFECT_FOLLOW_ME);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_CLEFABLE);
        PLAYER(SPECIES_ZIGZAGOON);
        OPPONENT(SPECIES_WYNAUT);
        OPPONENT(SPECIES_LINOONE);
    } WHEN {
        TURN { MOVE(playerRight, MOVE_FOLLOW_ME); MOVE(playerLeft, MOVE_VOLT_SWITCH, target: opponentLeft); MOVE(opponentLeft, MOVE_PURSUIT, target: playerLeft); SEND_OUT(playerLeft, 2); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FOLLOW_ME, playerRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_VOLT_SWITCH, playerLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PURSUIT, opponentLeft);
        SEND_IN_MESSAGE("Zigzagoon");
    }
}

SINGLE_BATTLE_TEST("Pursuit user mega evolves before attacking a switching foe and hits twice if user has Parental Bond")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_ZIGZAGOON);
        OPPONENT(SPECIES_KANGASKHAN) { Item(ITEM_KANGASKHANITE); }
    } WHEN {
        TURN { SWITCH(player, 1); MOVE(opponent, MOVE_PURSUIT, gimmick: GIMMICK_MEGA); }
    } SCENE {
        SWITCH_OUT_MESSAGE("Wobbuffet");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_MEGA_EVOLUTION, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PURSUIT, opponent);
        HP_BAR(player);
        HP_BAR(player);
        SEND_IN_MESSAGE("Zigzagoon");
    }
}

DOUBLE_BATTLE_TEST("Pursuit user mega evolves before attacking a switching foe and others mega evolve after switch")
{
    GIVEN {
        PLAYER(SPECIES_CHARIZARD) { Item(ITEM_CHARIZARDITE_X); }
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_ZIGZAGOON);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_KANGASKHAN) { Item(ITEM_KANGASKHANITE); }
    } WHEN {
        TURN { SWITCH(playerRight, 2); MOVE(opponentRight, MOVE_PURSUIT, gimmick: GIMMICK_MEGA, target: playerRight); MOVE(playerLeft, MOVE_CELEBRATE, gimmick: GIMMICK_MEGA); }
    } SCENE {
        SWITCH_OUT_MESSAGE("Wobbuffet");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_MEGA_EVOLUTION, opponentRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PURSUIT, opponentRight);
        HP_BAR(playerRight);
        HP_BAR(playerRight);
        SEND_IN_MESSAGE("Zigzagoon");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_MEGA_EVOLUTION, playerLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, playerLeft);
    }
}

SINGLE_BATTLE_TEST("Pursuit user terastalizes before attacking a switching foe and gets the damage boost from the tera type", s16 damage)
{
    u32 tera;
    PARAMETRIZE { tera = GIMMICK_NONE; }
    PARAMETRIZE { tera = GIMMICK_TERA; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_ZIGZAGOON);
        OPPONENT(SPECIES_KANGASKHAN) { TeraType(TYPE_DARK); }
    } WHEN {
        TURN { SWITCH(player, 1); MOVE(opponent, MOVE_PURSUIT, gimmick: tera); }
    } SCENE {
        SWITCH_OUT_MESSAGE("Wobbuffet");
        if (tera == GIMMICK_TERA)
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_TERA_ACTIVATE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PURSUIT, opponent);
        HP_BAR(player, captureDamage: &results[i].damage);
        SEND_IN_MESSAGE("Zigzagoon");
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.5), results[1].damage);
    }
}

DOUBLE_BATTLE_TEST("Pursuit affected by Electrify fails against immune target")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_ELECTRIFY) == EFFECT_ELECTRIFY);
        PLAYER(SPECIES_DONPHAN);
        PLAYER(SPECIES_HELIOLISK);
        PLAYER(SPECIES_ZIGZAGOON);
        OPPONENT(SPECIES_WYNAUT);
        OPPONENT(SPECIES_LINOONE);
    } WHEN {
        TURN { MOVE(playerRight, MOVE_ELECTRIFY, target: opponentLeft); MOVE(playerLeft, MOVE_VOLT_SWITCH, target: opponentLeft); MOVE(opponentLeft, MOVE_PURSUIT, target: playerLeft); SEND_OUT(playerLeft, 2); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ELECTRIFY, playerRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_VOLT_SWITCH, playerLeft);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_PURSUIT, opponentLeft);
        SEND_IN_MESSAGE("Zigzagoon");
    }
}

DOUBLE_BATTLE_TEST("Pursuit affected by Electrify fails against target with Volt Absorb")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_ELECTRIFY) == EFFECT_ELECTRIFY);
        PLAYER(SPECIES_LANTURN) { Ability(ABILITY_VOLT_ABSORB); }
        PLAYER(SPECIES_HELIOLISK);
        PLAYER(SPECIES_ZIGZAGOON);
        OPPONENT(SPECIES_WYNAUT);
        OPPONENT(SPECIES_LINOONE);
    } WHEN {
        TURN { MOVE(playerRight, MOVE_ELECTRIFY, target: opponentLeft); MOVE(playerLeft, MOVE_VOLT_SWITCH, target: opponentLeft); MOVE(opponentLeft, MOVE_PURSUIT, target: playerLeft); SEND_OUT(playerLeft, 2); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ELECTRIFY, playerRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_VOLT_SWITCH, playerLeft);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_PURSUIT, opponentLeft);
        ABILITY_POPUP(playerLeft, ABILITY_VOLT_ABSORB);
        SEND_IN_MESSAGE("Zigzagoon");
    }
}

SINGLE_BATTLE_TEST("Pursuited mon correctly switches out after it got hit and activated ability Tangling Hair")
{
    GIVEN {
        PLAYER(SPECIES_DUGTRIO_ALOLA) { Ability(ABILITY_TANGLING_HAIR); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { SWITCH(player, 1); MOVE(opponent, MOVE_PURSUIT); }
    } SCENE {
        SWITCH_OUT_MESSAGE("Dugtrio");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PURSUIT, opponent);
        ABILITY_POPUP(player, ABILITY_TANGLING_HAIR);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        MESSAGE("The opposing Wynaut's Speed fell!");
        SEND_IN_MESSAGE("Wobbuffet");
    }
}

DOUBLE_BATTLE_TEST("Pursuited mon correctly switches out after it got hit and activated ability Tangling Hair - Doubles")
{
    GIVEN {
        PLAYER(SPECIES_DUGTRIO_ALOLA) { Ability(ABILITY_TANGLING_HAIR); }
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { SWITCH(playerLeft, 2); MOVE(opponentLeft, MOVE_PURSUIT, target: playerLeft); MOVE(opponentRight, MOVE_PURSUIT, target: playerLeft); }
    } SCENE {
        SWITCH_OUT_MESSAGE("Dugtrio");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PURSUIT, opponentLeft);
        ABILITY_POPUP(playerLeft, ABILITY_TANGLING_HAIR);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentLeft);
        MESSAGE("The opposing Wynaut's Speed fell!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PURSUIT, opponentRight);
        ABILITY_POPUP(playerLeft, ABILITY_TANGLING_HAIR);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentRight);
        MESSAGE("The opposing Wobbuffet's Speed fell!");
        SEND_IN_MESSAGE("Wobbuffet");
    }
}

SINGLE_BATTLE_TEST("Pursuited mon correctly switches out after it got hit and activated ability Tangling Hair - Mirror Armor")
{
    GIVEN {
        PLAYER(SPECIES_DUGTRIO_ALOLA) { Ability(ABILITY_TANGLING_HAIR); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_CORVIKNIGHT) { Ability(ABILITY_MIRROR_ARMOR); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { SWITCH(player, 1); MOVE(opponent, MOVE_PURSUIT); }
    } SCENE {
        SWITCH_OUT_MESSAGE("Dugtrio");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PURSUIT, opponent);
        ABILITY_POPUP(player, ABILITY_TANGLING_HAIR);
        ABILITY_POPUP(opponent, ABILITY_MIRROR_ARMOR);
        SEND_IN_MESSAGE("Wobbuffet");
    }
}

DOUBLE_BATTLE_TEST("Pursuited mon correctly switches out after it got hit and activated ability Cotton Down")
{
    GIVEN {
        PLAYER(SPECIES_ELDEGOSS) { Ability(ABILITY_COTTON_DOWN); }
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { SWITCH(playerLeft, 2); MOVE(opponentLeft, MOVE_PURSUIT, target: playerLeft); MOVE(opponentRight, MOVE_PURSUIT, target: playerLeft); }
    } SCENE {
        SWITCH_OUT_MESSAGE("Eldegoss");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PURSUIT, opponentLeft);
        ABILITY_POPUP(playerLeft, ABILITY_COTTON_DOWN);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerRight);
        MESSAGE("Wobbuffet's Speed fell!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentLeft);
        MESSAGE("The opposing Wynaut's Speed fell!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentRight);
        MESSAGE("The opposing Wobbuffet's Speed fell!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PURSUIT, opponentRight);
        ABILITY_POPUP(playerLeft, ABILITY_COTTON_DOWN);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerRight);
        MESSAGE("Wobbuffet's Speed fell!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentLeft);
        MESSAGE("The opposing Wynaut's Speed fell!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentRight);
        MESSAGE("The opposing Wobbuffet's Speed fell!");
        SEND_IN_MESSAGE("Wobbuffet");
    }
}

// Checked so that Pursuit has only 1 PP and it forces the player to use Struggle.
SINGLE_BATTLE_TEST("Pursuit becomes a locked move after being used on switch-out while holding a Choice Item")
{
    GIVEN {
        ASSUME(gItemsInfo[ITEM_CHOICE_BAND].holdEffect == HOLD_EFFECT_CHOICE_BAND);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_CHOICE_BAND); MovesWithPP({MOVE_PURSUIT, 1}, {MOVE_CELEBRATE, 10}, {MOVE_WATER_GUN, 10}, {MOVE_SCRATCH, 10}); }
        OPPONENT(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { SWITCH(opponent, 1); MOVE(player, MOVE_PURSUIT); }
        TURN { FORCED_MOVE(player); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PURSUIT, player);
        HP_BAR(opponent);
        MESSAGE("2 sent out Wobbuffet!");

        MESSAGE("Wobbuffet used Struggle!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STRUGGLE, player);
    }
}

SINGLE_BATTLE_TEST("Pursuit attacks a switching foe and switchin is correctly stored")
{
    u32 switchin;
    PARAMETRIZE { switchin = 1; }
    PARAMETRIZE { switchin = 2; }
    PARAMETRIZE { switchin = 3; }
    PARAMETRIZE { switchin = 4; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_ZIGZAGOON);
        PLAYER(SPECIES_AIPOM);
        PLAYER(SPECIES_ABRA);
        PLAYER(SPECIES_VENIPEDE);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { SWITCH(player, switchin); MOVE(opponent, MOVE_PURSUIT); }
    } SCENE {
        SWITCH_OUT_MESSAGE("Wobbuffet");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PURSUIT, opponent);
        switch (switchin)
        {
            case 1:
                SEND_IN_MESSAGE("Zigzagoon");
                break;
            case 2:
                SEND_IN_MESSAGE("Aipom");
                break;
            case 3:
                SEND_IN_MESSAGE("Abra");
                break;
            case 4:
                SEND_IN_MESSAGE("Venipede");
                break;
        }
    }
}

SINGLE_BATTLE_TEST("Pursuit user gets forced out by Red Card and target still switches out")
{
    GIVEN {
        ASSUME(gItemsInfo[ITEM_RED_CARD].holdEffect == HOLD_EFFECT_RED_CARD);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_RED_CARD); }
        PLAYER(SPECIES_VOLTORB);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_VOLTORB);
    } WHEN {
        TURN { SWITCH(player, 1); MOVE(opponent, MOVE_PURSUIT); }
    } SCENE {
        SWITCH_OUT_MESSAGE("Wobbuffet");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PURSUIT, opponent);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
        MESSAGE("The opposing Voltorb was dragged out!");
        SEND_IN_MESSAGE("Voltorb");
    } THEN {
        EXPECT_EQ(player->species, SPECIES_VOLTORB);
        EXPECT_EQ(opponent->species, SPECIES_VOLTORB);
    }
}

SINGLE_BATTLE_TEST("Pursuit user faints to Life Orb and target still switches out")
{
    GIVEN {
        ASSUME(gItemsInfo[ITEM_LIFE_ORB].holdEffect == HOLD_EFFECT_LIFE_ORB);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_VOLTORB);
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_LIFE_ORB); HP(1); }
        OPPONENT(SPECIES_VOLTORB);
    } WHEN {
        TURN { SWITCH(player, 1); MOVE(opponent, MOVE_PURSUIT); SEND_OUT(opponent, 1); }
    } SCENE {
        SWITCH_OUT_MESSAGE("Wobbuffet");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PURSUIT, opponent);
        HP_BAR(opponent);
        MESSAGE("The opposing Wobbuffet fainted!");
        SEND_IN_MESSAGE("Voltorb");
    } THEN {
        EXPECT_EQ(player->species, SPECIES_VOLTORB);
        EXPECT_EQ(opponent->species, SPECIES_VOLTORB);
    }
}

DOUBLE_BATTLE_TEST("Pursuit user switches out due to Red Card and partner's switch is cancelled if switching to same Pokémon")
{
    GIVEN {
        ASSUME(GetItemHoldEffect(ITEM_RED_CARD) == HOLD_EFFECT_RED_CARD);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        PLAYER(SPECIES_ARCEUS);
        OPPONENT(SPECIES_WYNAUT) { Item(ITEM_RED_CARD); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_ARCEUS);
    } WHEN {
        TURN { SWITCH(opponentLeft, 2); SWITCH(playerRight, 2); MOVE(playerLeft, MOVE_PURSUIT, target: opponentLeft); }
    } THEN {
        // playerLeft switches to Arceus
        EXPECT_EQ(playerLeft->species, SPECIES_ARCEUS);
        // playerRight has their switch cancelled
        EXPECT_EQ(playerRight->species, SPECIES_WYNAUT);
    }
}

SINGLE_BATTLE_TEST("Pursuit doesn't trigger a switching mon's Eject Button")
{
    GIVEN {
        ASSUME(GetItemHoldEffect(ITEM_EJECT_BUTTON) == HOLD_EFFECT_EJECT_BUTTON);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_EJECT_BUTTON); }
        PLAYER(SPECIES_ZIGZAGOON);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { SWITCH(player, 1); MOVE(opponent, MOVE_PURSUIT); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PURSUIT, opponent);
        NOT ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
    }
}

// Extrapolated from the previous test's mechanic
SINGLE_BATTLE_TEST("Pursuit doesn't trigger a switching mon's Eject Pack")
{
    GIVEN {
        ASSUME(GetItemHoldEffect(ITEM_EJECT_PACK) == HOLD_EFFECT_EJECT_PACK);
        PLAYER(SPECIES_GOOMY) { Item(ITEM_EJECT_PACK); Ability(ABILITY_GOOEY); }
        PLAYER(SPECIES_ZIGZAGOON);
        OPPONENT(SPECIES_CORVIKNIGHT) { Ability(ABILITY_MIRROR_ARMOR); }
    } WHEN {
        TURN { SWITCH(player, 1); MOVE(opponent, MOVE_PURSUIT); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PURSUIT, opponent);
        ABILITY_POPUP(player, ABILITY_GOOEY);
        NOT ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        ABILITY_POPUP(opponent, ABILITY_MIRROR_ARMOR);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        NOT ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
    }
}

SINGLE_BATTLE_TEST("Pursuit doesn't trigger a switching mon's Emergency Exit")
{
    GIVEN {
        PLAYER(SPECIES_GOLISOPOD) { Ability(ABILITY_EMERGENCY_EXIT); HP(251); MaxHP(500); }
        PLAYER(SPECIES_ZIGZAGOON);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { SWITCH(player, 1); MOVE(opponent, MOVE_PURSUIT); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PURSUIT, opponent);
        NOT ABILITY_POPUP(player, ABILITY_EMERGENCY_EXIT);
    }
}

TO_DO_BATTLE_TEST("Baton Pass doesn't cause Pursuit to increase its power or priority");
