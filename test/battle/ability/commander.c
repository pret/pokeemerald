#include "global.h"
#include "test/battle.h"

DOUBLE_BATTLE_TEST("Commander will activate once Dondozo switches in")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_TATSUGIRI) { Ability(ABILITY_COMMANDER); }
        PLAYER(SPECIES_DONDOZO);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { SWITCH(playerLeft, 2); }
    } SCENE {
        ABILITY_POPUP(playerRight, ABILITY_COMMANDER);
        MESSAGE("Tatsugiri was swallowed by Dondozo and became Dondozo's commander!");
    }
}

DOUBLE_BATTLE_TEST("Commander increases all stats by 2 stages once it is triggered")
{
    GIVEN {
        PLAYER(SPECIES_TATSUGIRI) { Ability(ABILITY_COMMANDER); }
        PLAYER(SPECIES_DONDOZO);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {}
    } SCENE {
        ABILITY_POPUP(playerLeft, ABILITY_COMMANDER);
        MESSAGE("Tatsugiri was swallowed by Dondozo and became Dondozo's commander!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerRight);
        MESSAGE("Dondozo's Attack rose sharply!");
        MESSAGE("Dondozo's Defense rose sharply!");
        MESSAGE("Dondozo's Sp. Atk rose sharply!");
        MESSAGE("Dondozo's Sp. Def rose sharply!");
        MESSAGE("Dondozo's Speed rose sharply!");
    } THEN {
        EXPECT_EQ(playerRight->statStages[STAT_ATK], DEFAULT_STAT_STAGE + 2);
        EXPECT_EQ(playerRight->statStages[STAT_DEF], DEFAULT_STAT_STAGE + 2);
        EXPECT_EQ(playerRight->statStages[STAT_SPATK], DEFAULT_STAT_STAGE + 2);
        EXPECT_EQ(playerRight->statStages[STAT_SPDEF], DEFAULT_STAT_STAGE + 2);
        EXPECT_EQ(playerRight->statStages[STAT_SPEED], DEFAULT_STAT_STAGE + 2);
    }
}

DOUBLE_BATTLE_TEST("Commander Tatsugiri avoids moves targetted towards it")
{
    GIVEN {
        PLAYER(SPECIES_TATSUGIRI) { Ability(ABILITY_COMMANDER); }
        PLAYER(SPECIES_DONDOZO);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_SCRATCH, target: playerLeft); MOVE(opponentRight, MOVE_SCRATCH, target: playerRight); }
    } SCENE {
        ABILITY_POPUP(playerLeft, ABILITY_COMMANDER);
        MESSAGE("Tatsugiri was swallowed by Dondozo and became Dondozo's commander!");
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponentLeft);
        MESSAGE("Tatsugiri avoided the attack!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponentRight);
    }
}

DOUBLE_BATTLE_TEST("Commander Tatsugiri will still take residual damage from a field effect while inside Dondozo")
{
    GIVEN {
        PLAYER(SPECIES_TATSUGIRI) { Ability(ABILITY_COMMANDER); }
        PLAYER(SPECIES_DONDOZO);
        OPPONENT(SPECIES_TYRANITAR) { Ability(ABILITY_SAND_STREAM); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {}
    } SCENE {
        ABILITY_POPUP(opponentLeft, ABILITY_SAND_STREAM);
        ABILITY_POPUP(playerLeft, ABILITY_COMMANDER);
        MESSAGE("Tatsugiri was swallowed by Dondozo and became Dondozo's commander!");
        HP_BAR(playerRight);
        HP_BAR(playerLeft);
        HP_BAR(opponentRight);
    }
}

DOUBLE_BATTLE_TEST("Commander Tatsugiri will still take poison damage if while inside Dondozo")
{
    GIVEN {
        PLAYER(SPECIES_TATSUGIRI) { Ability(ABILITY_COMMANDER); Status1(STATUS1_POISON); }
        PLAYER(SPECIES_DONDOZO);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {}
    } SCENE {
        ABILITY_POPUP(playerLeft, ABILITY_COMMANDER);
        MESSAGE("Tatsugiri was swallowed by Dondozo and became Dondozo's commander!");
        HP_BAR(playerLeft);
    }
}

DOUBLE_BATTLE_TEST("Commander Tatsugiri still avoids moves even when the attacker has No Guard")
{
    GIVEN {
        PLAYER(SPECIES_TATSUGIRI) { Ability(ABILITY_COMMANDER); }
        PLAYER(SPECIES_DONDOZO);
        OPPONENT(SPECIES_MACHAMP) { Ability(ABILITY_NO_GUARD); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_SCRATCH, target: playerLeft); }
    } SCENE {
        ABILITY_POPUP(playerLeft, ABILITY_COMMANDER);
        MESSAGE("Tatsugiri was swallowed by Dondozo and became Dondozo's commander!");
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponentLeft);
        MESSAGE("Tatsugiri avoided the attack!");
    }
}

DOUBLE_BATTLE_TEST("Commander cannot affect a Dondozo that was previously affected by Commander until it faints and revived")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_DONDOZO);
        PLAYER(SPECIES_TATSUGIRI) { HP(1); Ability(ABILITY_COMMANDER); Status1(STATUS1_POISON); }
        PLAYER(SPECIES_TATSUGIRI) { Ability(ABILITY_COMMANDER); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerRight, MOVE_CELEBRATE); SWITCH(playerLeft, 2); SEND_OUT(playerLeft, 3); }
    } SCENE {
        ABILITY_POPUP(playerLeft, ABILITY_COMMANDER);
        MESSAGE("Tatsugiri was swallowed by Dondozo and became Dondozo's commander!");
        HP_BAR(playerLeft);
        NONE_OF {
            ABILITY_POPUP(playerLeft, ABILITY_COMMANDER);
            MESSAGE("Tatsugiri was swallowed by Dondozo and became Dondozo's commander!");
        }
    }
}

DOUBLE_BATTLE_TEST("Commander prevents Whirlwind from working against Dondozo or Tatsugiri while it's active")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_WHIRLWIND) == EFFECT_ROAR);
        PLAYER(SPECIES_TATSUGIRI) { Ability(ABILITY_COMMANDER); }
        PLAYER(SPECIES_DONDOZO);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_WHIRLWIND, target: playerLeft); }
        TURN { MOVE(opponentRight, MOVE_WHIRLWIND, target: playerRight); }
    } SCENE {
        ABILITY_POPUP(playerLeft, ABILITY_COMMANDER);
        MESSAGE("Tatsugiri was swallowed by Dondozo and became Dondozo's commander!");
        MESSAGE("The opposing Wobbuffet used Whirlwind!");
        MESSAGE("Tatsugiri avoided the attack!");
        MESSAGE("The opposing Wobbuffet used Whirlwind!");
        MESSAGE("But it failed!"); // Avoided on tatsu, but it failed on dozo
    }
}

DOUBLE_BATTLE_TEST("Commander prevents Red Card from working while Commander is active")
{
    GIVEN {
        ASSUME(gItemsInfo[ITEM_RED_CARD].holdEffect == HOLD_EFFECT_RED_CARD);
        PLAYER(SPECIES_TATSUGIRI) { Ability(ABILITY_COMMANDER); }
        PLAYER(SPECIES_DONDOZO);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_RED_CARD); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerRight, MOVE_SCRATCH, target: opponentLeft); }
    } SCENE {
        ABILITY_POPUP(playerLeft, ABILITY_COMMANDER);
        MESSAGE("Tatsugiri was swallowed by Dondozo and became Dondozo's commander!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, opponentLeft);
    } THEN {
        EXPECT(opponentLeft->item == ITEM_NONE);
        EXPECT(playerRight->species == SPECIES_DONDOZO);
    }

}

DOUBLE_BATTLE_TEST("Commander prevents Emergency Exit from switching out Dondozo")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_SKILL_SWAP) == EFFECT_SKILL_SWAP);
        PLAYER(SPECIES_TATSUGIRI) { Ability(ABILITY_COMMANDER); }
        PLAYER(SPECIES_DONDOZO) { MaxHP(200); HP(101); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_GOLISOPOD) { Ability(ABILITY_EMERGENCY_EXIT); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {
            MOVE(opponentLeft, MOVE_SKILL_SWAP, target: playerRight);
            MOVE(opponentRight, MOVE_SCRATCH, target: playerRight);
        }
    } SCENE {
        ABILITY_POPUP(playerLeft, ABILITY_COMMANDER);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SKILL_SWAP, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponentRight);
        HP_BAR(playerRight);
        NOT ABILITY_POPUP(playerRight, ABILITY_EMERGENCY_EXIT);
    } THEN {
        EXPECT_EQ(playerLeft->species, SPECIES_TATSUGIRI);
        EXPECT_EQ(playerRight->species, SPECIES_DONDOZO);
    }
}

DOUBLE_BATTLE_TEST("Commander prevents Eject Button from switching out Dondozo")
{
    GIVEN {
        ASSUME(gItemsInfo[ITEM_EJECT_BUTTON].holdEffect == HOLD_EFFECT_EJECT_BUTTON);
        PLAYER(SPECIES_TATSUGIRI) { Ability(ABILITY_COMMANDER); }
        PLAYER(SPECIES_DONDOZO) { Item(ITEM_EJECT_BUTTON); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_SCRATCH, target: playerRight); }
    } SCENE {
        ABILITY_POPUP(playerLeft, ABILITY_COMMANDER);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponentLeft);
        HP_BAR(playerRight);
        NONE_OF {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, playerRight);
            MESSAGE("Dondozo is switched out with the Eject Button!");
        }
    } THEN {
        EXPECT_EQ(playerLeft->species, SPECIES_TATSUGIRI);
        EXPECT_EQ(playerRight->species, SPECIES_DONDOZO);
    }
}

DOUBLE_BATTLE_TEST("Commander prevents Eject Pack from switching out Dondozo")
{
    GIVEN {
        ASSUME(gItemsInfo[ITEM_EJECT_PACK].holdEffect == HOLD_EFFECT_EJECT_PACK);
        ASSUME_STAT_CHANGE(MOVE_CHARM, attack: -2);
        PLAYER(SPECIES_TATSUGIRI) { Ability(ABILITY_COMMANDER); }
        PLAYER(SPECIES_DONDOZO) { Item(ITEM_EJECT_PACK); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_CHARM, target: playerRight); }
    } SCENE {
        ABILITY_POPUP(playerLeft, ABILITY_COMMANDER);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CHARM, opponentLeft);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerRight);
        NONE_OF {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, playerRight);
            MESSAGE("Dondozo is switched out with the Eject Pack!");
        }
    } THEN {
        EXPECT_EQ(playerLeft->species, SPECIES_TATSUGIRI);
        EXPECT_EQ(playerRight->species, SPECIES_DONDOZO);
    }
}

DOUBLE_BATTLE_TEST("Commander prevents Eject Pack from activating after a switch-in stat drop")
{
    GIVEN {
        ASSUME(gItemsInfo[ITEM_EJECT_PACK].holdEffect == HOLD_EFFECT_EJECT_PACK);
        PLAYER(SPECIES_TATSUGIRI) { Ability(ABILITY_COMMANDER); }
        PLAYER(SPECIES_DONDOZO) { Item(ITEM_EJECT_PACK); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_INCINEROAR) { Ability(ABILITY_INTIMIDATE); }
    } WHEN {
        TURN { SWITCH(opponentLeft, 2); }
    } SCENE {
        ABILITY_POPUP(playerLeft, ABILITY_COMMANDER);
        ABILITY_POPUP(opponentLeft, ABILITY_INTIMIDATE);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerRight);
        NONE_OF {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, playerRight);
            MESSAGE("Dondozo is switched out with the Eject Pack!");
        }
    } THEN {
        EXPECT_EQ(playerLeft->species, SPECIES_TATSUGIRI);
        EXPECT_EQ(playerRight->species, SPECIES_DONDOZO);
    }
}

DOUBLE_BATTLE_TEST("Commander prevents Tatsugiri's Eject Pack from activating after Sticky Web")
{
    GIVEN {
        ASSUME(gItemsInfo[ITEM_EJECT_PACK].holdEffect == HOLD_EFFECT_EJECT_PACK);
        ASSUME(GetMoveEffect(MOVE_STICKY_WEB) == EFFECT_STICKY_WEB);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_DONDOZO);
        PLAYER(SPECIES_TATSUGIRI) { Ability(ABILITY_COMMANDER); Item(ITEM_EJECT_PACK); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_STICKY_WEB); }
        TURN { SWITCH(playerLeft, 2); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STICKY_WEB, opponentLeft);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerLeft);
        ABILITY_POPUP(playerLeft, ABILITY_COMMANDER);
        NONE_OF {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, playerLeft);
            MESSAGE("Tatsugiri is switched out with the Eject Pack!");
        }
    } THEN {
        EXPECT_EQ(playerLeft->species, SPECIES_TATSUGIRI);
        EXPECT_EQ(playerRight->species, SPECIES_DONDOZO);
    }
}

DOUBLE_BATTLE_TEST("Commander prevents pivot moves from switching out Dondozo")
{
    enum Move move;
    enum BattleMoveEffects effect;

    PARAMETRIZE { move = MOVE_BATON_PASS;       effect = EFFECT_BATON_PASS; }
    PARAMETRIZE { move = MOVE_U_TURN;           effect = EFFECT_HIT_ESCAPE; }
    PARAMETRIZE { move = MOVE_PARTING_SHOT;     effect = EFFECT_PARTING_SHOT; }
    PARAMETRIZE { move = MOVE_TELEPORT;         effect = EFFECT_TELEPORT; }
    PARAMETRIZE { move = MOVE_SHED_TAIL;        effect = EFFECT_SHED_TAIL; }
    PARAMETRIZE { move = MOVE_CHILLY_RECEPTION; effect = EFFECT_WEATHER_AND_SWITCH; }

    GIVEN {
        ASSUME(GetMoveEffect(move) == effect);
        PLAYER(SPECIES_TATSUGIRI) { Ability(ABILITY_COMMANDER); }
        PLAYER(SPECIES_DONDOZO);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {
            MOVE(playerRight, move, target: opponentLeft);
        }
    } SCENE {
        ABILITY_POPUP(playerLeft, ABILITY_COMMANDER);
        if (move == MOVE_BATON_PASS || move == MOVE_TELEPORT || move == MOVE_SHED_TAIL)
        {
            NOT ANIMATION(ANIM_TYPE_MOVE, move, playerRight);
            MESSAGE("But it failed!");
        }
        else
        {
            ANIMATION(ANIM_TYPE_MOVE, move, playerRight);
        }
    } THEN {
        EXPECT_EQ(playerLeft->species, SPECIES_TATSUGIRI);
        EXPECT_EQ(playerRight->species, SPECIES_DONDOZO);
    }
}

DOUBLE_BATTLE_TEST("Commander prevents Ally Switch from swapping Dondozo with Tatsugiri")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_ALLY_SWITCH) == EFFECT_ALLY_SWITCH);
        PLAYER(SPECIES_TATSUGIRI) { Ability(ABILITY_COMMANDER); }
        PLAYER(SPECIES_DONDOZO);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {
            MOVE(playerRight, MOVE_ALLY_SWITCH);
        }
    } SCENE {
        ABILITY_POPUP(playerLeft, ABILITY_COMMANDER);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_ALLY_SWITCH, playerRight);
        MESSAGE("But it failed!");
    } THEN {
        EXPECT_EQ(playerLeft->species, SPECIES_TATSUGIRI);
        EXPECT_EQ(playerRight->species, SPECIES_DONDOZO);
    }
}

DOUBLE_BATTLE_TEST("Commander Tatsugiri is not damaged by a double target move if Dondozo faints")
{
    GIVEN {
        ASSUME(GetMoveTarget(MOVE_EARTHQUAKE) == TARGET_FOES_AND_ALLY);
        PLAYER(SPECIES_DONDOZO) { HP(1); }
        PLAYER(SPECIES_TATSUGIRI) { Ability(ABILITY_COMMANDER); }
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_EARTHQUAKE); SEND_OUT(playerLeft, 2); }
    } SCENE {
        ABILITY_POPUP(playerRight, ABILITY_COMMANDER);
        MESSAGE("Tatsugiri was swallowed by Dondozo and became Dondozo's commander!");
        HP_BAR(playerLeft);
        HP_BAR(opponentRight);
        NOT HP_BAR(playerRight);
        MESSAGE("Dondozo fainted!");
    }
}

DOUBLE_BATTLE_TEST("Commander Tatsugiri takes no damage from multi-target damaging moves")
{
    GIVEN {
        ASSUME(GetMoveTarget(MOVE_EARTHQUAKE) == TARGET_FOES_AND_ALLY);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_TATSUGIRI) { Ability(ABILITY_COMMANDER); }
        PLAYER(SPECIES_DONDOZO);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_EARTHQUAKE); MOVE(opponentRight, MOVE_EARTHQUAKE); SWITCH(playerLeft, 2); }
    } SCENE {
        ABILITY_POPUP(playerRight, ABILITY_COMMANDER);
        MESSAGE("Tatsugiri was swallowed by Dondozo and became Dondozo's commander!");

        ANIMATION(ANIM_TYPE_MOVE, MOVE_EARTHQUAKE, opponentLeft);
        HP_BAR(playerLeft);
        NOT HP_BAR(playerRight);
        HP_BAR(opponentRight);

        ANIMATION(ANIM_TYPE_MOVE, MOVE_EARTHQUAKE, opponentRight);
        HP_BAR(playerLeft);
        HP_BAR(opponentLeft);
        NOT HP_BAR(playerRight);
    }
}

DOUBLE_BATTLE_TEST("Commander doesn't prevent Transform from working on a Commander Tatsugiri")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_TRANSFORM) == EFFECT_TRANSFORM);
        PLAYER(SPECIES_DONDOZO);
        PLAYER(SPECIES_TATSUGIRI) { Ability(ABILITY_COMMANDER); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponentRight, MOVE_TRANSFORM, target: playerRight); }
    } SCENE {
        ABILITY_POPUP(playerRight, ABILITY_COMMANDER);
        MESSAGE("Tatsugiri was swallowed by Dondozo and became Dondozo's commander!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TRANSFORM, opponentRight);
    }
}

DOUBLE_BATTLE_TEST("Commander doesn't prevent Imposter from working on a Commander Tatsugiri")
{
    GIVEN {
        PLAYER(SPECIES_DONDOZO);
        PLAYER(SPECIES_TATSUGIRI) { Ability(ABILITY_COMMANDER); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_DITTO) { Ability(ABILITY_IMPOSTER); }
    } WHEN {
        TURN {}
        TURN { SWITCH(opponentLeft, 2); }
    } SCENE {
        ABILITY_POPUP(playerRight, ABILITY_COMMANDER);
        MESSAGE("Tatsugiri was swallowed by Dondozo and became Dondozo's commander!");
        ABILITY_POPUP(opponentLeft, ABILITY_IMPOSTER);
        MESSAGE("The opposing Ditto transformed into Tatsugiri!");
    }
}

DOUBLE_BATTLE_TEST("Commander Tatsugiri faints from Perish Song if it heard the song before being swallowed")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_PERISH_SONG) == EFFECT_PERISH_SONG);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_TATSUGIRI) { Ability(ABILITY_COMMANDER); }
        PLAYER(SPECIES_DONDOZO);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_PERISH_SONG); }
        TURN { SWITCH(playerLeft, 2); }
        TURN {}
        TURN {}
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PERISH_SONG, opponentLeft);
        MESSAGE("All Pokémon that heard the song will faint in three turns!");
        ABILITY_POPUP(playerRight, ABILITY_COMMANDER);
        MESSAGE("Tatsugiri was swallowed by Dondozo and became Dondozo's commander!");
    } THEN {
        EXPECT_GT(playerLeft->hp, 0);
        EXPECT_EQ(playerRight->hp, 0);
    }
}

DOUBLE_BATTLE_TEST("Commander Tatsugiri is still affected by Haze while controlling Dondozo")
{
    GIVEN {
        ASSUME_STAT_CHANGE(MOVE_SWORDS_DANCE, attack: +2);
        ASSUME(GetMoveEffect(MOVE_HAZE) == EFFECT_HAZE);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_TATSUGIRI) { Ability(ABILITY_COMMANDER); }
        PLAYER(SPECIES_DONDOZO);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerRight, MOVE_SWORDS_DANCE); }
        TURN { SWITCH(playerLeft, 2); MOVE(opponentRight, MOVE_HAZE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SWORDS_DANCE, playerRight);
        ABILITY_POPUP(playerRight, ABILITY_COMMANDER);
        MESSAGE("Tatsugiri was swallowed by Dondozo and became Dondozo's commander!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HAZE, opponentRight);
    } THEN {
        EXPECT_EQ(playerRight->statStages[STAT_ATK], DEFAULT_STAT_STAGE);
    }
}

DOUBLE_BATTLE_TEST("Commander Attacker is kept (Dondozo Left Slot)")
{
    GIVEN {
        ASSUME(GetMoveTarget(MOVE_EARTHQUAKE) == TARGET_FOES_AND_ALLY);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_TATSUGIRI) { Ability(ABILITY_COMMANDER); }
        PLAYER(SPECIES_DONDOZO);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponentRight, MOVE_SCRATCH, target: opponentLeft); }
        TURN { SWITCH(playerLeft, 2); MOVE(opponentLeft, MOVE_EARTHQUAKE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponentRight);
        ABILITY_POPUP(playerRight, ABILITY_COMMANDER);
        MESSAGE("Tatsugiri was swallowed by Dondozo and became Dondozo's commander!");
        MESSAGE("Tatsugiri avoided the attack!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EARTHQUAKE, opponentLeft);
        HP_BAR(playerLeft);
        HP_BAR(opponentRight);
    }
}

DOUBLE_BATTLE_TEST("Commander Attacker is kept (Dondozo Right Slot)")
{
    GIVEN {
        ASSUME(GetMoveTarget(MOVE_EARTHQUAKE) == TARGET_FOES_AND_ALLY);
        PLAYER(SPECIES_TATSUGIRI) { Ability(ABILITY_COMMANDER); }
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_DONDOZO);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponentRight, MOVE_SCRATCH, target: opponentLeft); }
        TURN { SWITCH(playerRight, 2); MOVE(opponentLeft, MOVE_EARTHQUAKE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponentRight);
        ABILITY_POPUP(playerLeft, ABILITY_COMMANDER);
        MESSAGE("Tatsugiri was swallowed by Dondozo and became Dondozo's commander!");
        MESSAGE("Tatsugiri avoided the attack!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EARTHQUAKE, opponentLeft);
        HP_BAR(playerRight);
        HP_BAR(opponentRight);
    }
}

DOUBLE_BATTLE_TEST("Commander Tatsugiri does not attack if Dondozo faints the same turn it's switched in")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_TATSUGIRI) { Ability(ABILITY_COMMANDER); }
        PLAYER(SPECIES_DONDOZO) { HP(1); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {
            SWITCH(playerLeft, 2);
            MOVE(opponentLeft, MOVE_SCRATCH, target: playerLeft);
            MOVE(opponentRight, MOVE_SCRATCH, target: playerRight);
            MOVE(playerRight, MOVE_CELEBRATE);
            SEND_OUT(playerLeft, 0);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponentLeft);
        HP_BAR(playerLeft);
        MESSAGE("Dondozo fainted!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponentRight);
        HP_BAR(playerRight);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, playerRight);
    }
}

DOUBLE_BATTLE_TEST("Commander Tatsugiri does not get hit by Dragon Darts when a commanded Dondozo faints")
{
    GIVEN {
        ASSUME(GetMoveTarget(MOVE_DRAGON_DARTS) == TARGET_SMART);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_DONDOZO) { HP(1); }
        PLAYER(SPECIES_TATSUGIRI) { Ability(ABILITY_COMMANDER); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { SWITCH(playerLeft, 2); MOVE(opponentRight, MOVE_DRAGON_DARTS, target: playerRight); SEND_OUT(playerRight, 0); }
    } SCENE {
        MESSAGE("Tatsugiri was swallowed by Dondozo and became Dondozo's commander!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_DARTS, opponentRight);
        HP_BAR(playerRight);
        MESSAGE("Dondozo fainted!");
        NOT HP_BAR(playerLeft);
    }
}

DOUBLE_BATTLE_TEST("Commander Tatsugiri does not get hit by Dragon Darts when commanding Dondozo")
{
    bool32 targetPlayerRight;
    PARAMETRIZE { targetPlayerRight = TRUE; }
    PARAMETRIZE { targetPlayerRight = FALSE; }
    GIVEN {
        ASSUME(GetMoveTarget(MOVE_DRAGON_DARTS) == TARGET_SMART);
        PLAYER(SPECIES_TATSUGIRI) { Ability(ABILITY_COMMANDER); }
        PLAYER(SPECIES_DONDOZO);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        if (targetPlayerRight == TRUE)
            TURN { MOVE(opponentRight, MOVE_DRAGON_DARTS, target: playerRight); }
        else
            TURN { MOVE(opponentRight, MOVE_DRAGON_DARTS, target: playerLeft); }
    } SCENE {
        MESSAGE("Tatsugiri was swallowed by Dondozo and became Dondozo's commander!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_DARTS, opponentRight);
        HP_BAR(playerRight);
        NOT HP_BAR(playerLeft);
        HP_BAR(playerRight);
        NOT HP_BAR(playerLeft);
    }
}

DOUBLE_BATTLE_TEST("Commander will not activate if Dondozo fainted right before Tatsugiri came in")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_SHED_TAIL) == EFFECT_SHED_TAIL);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_DONDOZO) { HP(1); }
        PLAYER(SPECIES_TATSUGIRI) { Ability(ABILITY_COMMANDER); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponentRight, MOVE_SCRATCH, target: playerRight); MOVE(playerLeft, MOVE_SHED_TAIL); SEND_OUT(playerLeft, 2); SEND_OUT(playerRight, 3); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponentRight);
        HP_BAR(playerRight);
        MESSAGE("Dondozo fainted!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SHED_TAIL, playerLeft);
        NOT ABILITY_POPUP(playerLeft, ABILITY_COMMANDER);
    }
}

DOUBLE_BATTLE_TEST("Commander prevent Dondozo from switch out by Dragon Tail")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_DRAGON_TAIL) == EFFECT_HIT_SWITCH_TARGET);
        PLAYER(SPECIES_DONDOZO);
        PLAYER(SPECIES_TATSUGIRI) { Ability(ABILITY_COMMANDER); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_DRAGON_TAIL, target: playerLeft); }
    } SCENE {
        ABILITY_POPUP(playerRight, ABILITY_COMMANDER);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_TAIL, opponentLeft);
        NOT MESSAGE("Wobbuffet was dragged out!");
    }
}

DOUBLE_BATTLE_TEST("Commander will not activate if partner Dondozo is about to switch out")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_DONDOZO);
        PLAYER(SPECIES_TATSUGIRI) { Ability(ABILITY_COMMANDER); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {
            SWITCH(playerLeft, 2);
            SWITCH(playerRight, 3);
        }
    } SCENE {
        NOT ABILITY_POPUP(playerRight, ABILITY_COMMANDER);
    } THEN {
        EXPECT_EQ(playerLeft->species, SPECIES_TATSUGIRI);
        EXPECT_EQ(playerRight->species, SPECIES_WOBBUFFET);
    }
}

DOUBLE_BATTLE_TEST("Commander will not activate if Tatsugiri is about to switch out")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_TATSUGIRI) { Ability(ABILITY_COMMANDER); }
        PLAYER(SPECIES_DONDOZO);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {
            SWITCH(playerLeft, 2);
            SWITCH(playerRight, 3);
        }
    } SCENE {
        NOT ABILITY_POPUP(playerRight, ABILITY_COMMANDER);
    } THEN {
        EXPECT_EQ(playerLeft->species, SPECIES_DONDOZO);
        EXPECT_EQ(playerRight->species, SPECIES_WOBBUFFET);
    }
}

DOUBLE_BATTLE_TEST("Commander cancels Tatsugiri's pending Mega Evolution")
{
    GIVEN {
        PLAYER(SPECIES_TATSUGIRI) { Ability(ABILITY_COMMANDER); Item(ITEM_TATSUGIRINITE); }
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_DONDOZO);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {
            MOVE(playerLeft, MOVE_CELEBRATE, gimmick: GIMMICK_MEGA);
            SWITCH(playerRight, 2);
        }
    } SCENE {
        ABILITY_POPUP(playerLeft, ABILITY_COMMANDER);
        MESSAGE("Tatsugiri was swallowed by Dondozo and became Dondozo's commander!");
        NOT ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_MEGA_EVOLUTION, playerLeft);
    } THEN {
        EXPECT_EQ(playerLeft->species, SPECIES_TATSUGIRI);
        EXPECT_EQ(playerRight->species, SPECIES_DONDOZO);
    }
}

DOUBLE_BATTLE_TEST("Commander cancels Tatsugiri's pending Z-Move")
{
    GIVEN {
        ASSUME(GetMoveType(MOVE_DRAGON_PULSE) == TYPE_DRAGON);
        PLAYER(SPECIES_TATSUGIRI) { Ability(ABILITY_COMMANDER); Item(ITEM_DRAGONIUM_Z); }
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_DONDOZO);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {
            MOVE(playerLeft, MOVE_DRAGON_PULSE, gimmick: GIMMICK_Z_MOVE, target: opponentLeft);
            SWITCH(playerRight, 2);
        }
    } SCENE {
        ABILITY_POPUP(playerLeft, ABILITY_COMMANDER);
        MESSAGE("Tatsugiri was swallowed by Dondozo and became Dondozo's commander!");
        NONE_OF {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_ZMOVE_ACTIVATE, playerLeft);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_BREAKNECK_BLITZ, playerLeft);
        }
    }
}

DOUBLE_BATTLE_TEST("Commander cancels Tatsugiri's pending Dynamax")
{
    GIVEN {
        PLAYER(SPECIES_TATSUGIRI) { Ability(ABILITY_COMMANDER); HP(100); MaxHP(100); }
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_DONDOZO);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {
            MOVE(playerLeft, MOVE_SCRATCH, gimmick: GIMMICK_DYNAMAX, target: opponentLeft);
            SWITCH(playerRight, 2);
        }
    } SCENE {
        ABILITY_POPUP(playerLeft, ABILITY_COMMANDER);
        MESSAGE("Tatsugiri was swallowed by Dondozo and became Dondozo's commander!");
        NONE_OF {
            MESSAGE("Time to Dynamax!");
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_DYNAMAX_GROWTH, playerLeft);
        }
    }
}

DOUBLE_BATTLE_TEST("Commander cancels Tatsugiri's pending Terastallization")
{
    GIVEN {
        PLAYER(SPECIES_TATSUGIRI) { Ability(ABILITY_COMMANDER); TeraType(TYPE_FIRE); }
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_DONDOZO);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {
            MOVE(playerLeft, MOVE_CELEBRATE, gimmick: GIMMICK_TERA);
            SWITCH(playerRight, 2);
        }
    } SCENE {
        ABILITY_POPUP(playerLeft, ABILITY_COMMANDER);
        MESSAGE("Tatsugiri was swallowed by Dondozo and became Dondozo's commander!");
        NONE_OF {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_TERA_CHARGE, playerLeft);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_TERA_ACTIVATE, playerLeft);
        }
    }
}

DOUBLE_BATTLE_TEST("Commander clears when Dondozo is replaced and Tatsugiri can be hit")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_VOLT_SWITCH) == EFFECT_HIT_ESCAPE);
        PLAYER(SPECIES_DONDOZO) { HP(1); Speed(1); }
        PLAYER(SPECIES_TATSUGIRI) { Ability(ABILITY_COMMANDER); Speed(2); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(3); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(4); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(5); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(6); }
    } WHEN {
        TURN {
            MOVE(opponentLeft, MOVE_SCRATCH, target: playerRight);
            MOVE(opponentRight, MOVE_VOLT_SWITCH, target: playerLeft);
            SEND_OUT(opponentRight, 2);
            SEND_OUT(playerLeft, 2);
        }
        TURN {
            MOVE(opponentLeft, MOVE_SCRATCH, target: playerRight);
        }
    } SCENE {
        ABILITY_POPUP(playerRight, ABILITY_COMMANDER);
        MESSAGE("Tatsugiri was swallowed by Dondozo and became Dondozo's commander!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_VOLT_SWITCH, opponentRight);
        HP_BAR(playerLeft);
        MESSAGE("Dondozo fainted!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponentLeft);
        HP_BAR(playerRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponentLeft);
        HP_BAR(playerRight);
    }
}

DOUBLE_BATTLE_TEST("Commander does not clear semi-invulnerability of non-Tatsugiri partner")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_FLY) == EFFECT_SEMI_INVULNERABLE);
        PLAYER(SPECIES_DONDOZO) { HP(1); Speed(1); }
        PLAYER(SPECIES_TATSUGIRI) { Ability(ABILITY_COMMANDER); HP(1); Status1(STATUS1_POISON); Speed(2); }
        PLAYER(SPECIES_PIDGEOT) { Speed(100); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(90); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(80); }
    } WHEN {
        TURN { SKIP_TURN(playerRight); SEND_OUT(playerRight, 2); }
        TURN {
            MOVE(playerRight, MOVE_FLY, target: opponentLeft);
            MOVE(opponentLeft, MOVE_SCRATCH, target: playerLeft);
            MOVE(opponentRight, MOVE_SCRATCH, target: playerRight);
        }
    } SCENE {
        ABILITY_POPUP(playerRight, ABILITY_COMMANDER);
        MESSAGE("Tatsugiri was swallowed by Dondozo and became Dondozo's commander!");
        HP_BAR(playerRight);
        MESSAGE("Tatsugiri fainted!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FLY, playerRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponentLeft);
        HP_BAR(playerLeft);
        MESSAGE("Dondozo fainted!");
        NOT HP_BAR(playerRight);
    } THEN {
        EXPECT_EQ(playerRight->hp, playerRight->maxHP);
    }
}

DOUBLE_BATTLE_TEST("Commander still blocks forced switch after swallowed Tatsugiri faints")
{
    enum Move move;
    PARAMETRIZE { move = MOVE_DRAGON_TAIL; }
    PARAMETRIZE { move = MOVE_WHIRLWIND; }

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_DRAGON_TAIL) == EFFECT_HIT_SWITCH_TARGET);
        ASSUME(GetMoveEffect(MOVE_WHIRLWIND) == EFFECT_ROAR);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_DONDOZO);
        OPPONENT(SPECIES_TATSUGIRI) { Ability(ABILITY_COMMANDER); HP(1); Status1(STATUS1_POISON); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { SKIP_TURN(opponentRight); SEND_OUT(opponentRight, 2); }
        TURN { MOVE(playerLeft, move, target: opponentLeft); }
    } SCENE {
        ABILITY_POPUP(opponentRight, ABILITY_COMMANDER);
        MESSAGE("The opposing Tatsugiri was swallowed by Dondozo and became Dondozo's commander!");
        HP_BAR(opponentRight);
        MESSAGE("The opposing Tatsugiri fainted!");
        if (move == MOVE_DRAGON_TAIL)
        {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_TAIL, playerLeft);
            NOT MESSAGE("The opposing Dondozo was dragged out!");
        }
        else
        {
            MESSAGE("But it failed!");
        }
    } THEN {
        EXPECT(opponentLeft->species == SPECIES_DONDOZO);
    }
}

DOUBLE_BATTLE_TEST("Red Card is still consumed but cannot force out Dondozo after swallowed Tatsugiri faints")
{
    GIVEN {
        ASSUME(gItemsInfo[ITEM_RED_CARD].holdEffect == HOLD_EFFECT_RED_CARD);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_RED_CARD); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_DONDOZO);
        OPPONENT(SPECIES_TATSUGIRI) { Ability(ABILITY_COMMANDER); HP(1); Status1(STATUS1_POISON); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { SKIP_TURN(opponentRight); SEND_OUT(opponentRight, 2); }
        TURN { MOVE(opponentLeft, MOVE_SCRATCH, target: playerLeft); }
    } SCENE {
        ABILITY_POPUP(opponentRight, ABILITY_COMMANDER);
        MESSAGE("The opposing Tatsugiri was swallowed by Dondozo and became Dondozo's commander!");
        HP_BAR(opponentRight);
        MESSAGE("The opposing Tatsugiri fainted!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponentLeft);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, playerLeft);
    } THEN {
        EXPECT(playerLeft->item == ITEM_NONE);
        EXPECT(opponentLeft->species == SPECIES_DONDOZO);
    }
}

MULTI_BATTLE_TEST("Commander will not activate in a multi battle")
{
    GIVEN {
        PLAYER(SPECIES_TATSUGIRI) { Ability(ABILITY_COMMANDER); }
        PARTNER(SPECIES_DONDOZO);
        OPPONENT_A(SPECIES_TATSUGIRI) { Ability(ABILITY_COMMANDER); }
        OPPONENT_B(SPECIES_DONDOZO);
    } WHEN {
        TURN {}
    } SCENE {
        NONE_OF {
            ABILITY_POPUP(playerLeft, ABILITY_COMMANDER);
            ABILITY_POPUP(opponentLeft, ABILITY_COMMANDER);
        }        
    } THEN {
        EXPECT_EQ(playerRight->statStages[STAT_ATK], DEFAULT_STAT_STAGE);
        EXPECT_EQ(playerRight->statStages[STAT_DEF], DEFAULT_STAT_STAGE);
        EXPECT_EQ(playerRight->statStages[STAT_SPATK], DEFAULT_STAT_STAGE);
        EXPECT_EQ(playerRight->statStages[STAT_SPDEF], DEFAULT_STAT_STAGE);
        EXPECT_EQ(playerRight->statStages[STAT_SPEED], DEFAULT_STAT_STAGE);
        EXPECT_EQ(opponentRight->statStages[STAT_ATK], DEFAULT_STAT_STAGE);
        EXPECT_EQ(opponentRight->statStages[STAT_DEF], DEFAULT_STAT_STAGE);
        EXPECT_EQ(opponentRight->statStages[STAT_SPATK], DEFAULT_STAT_STAGE);
        EXPECT_EQ(opponentRight->statStages[STAT_SPDEF], DEFAULT_STAT_STAGE);
        EXPECT_EQ(opponentRight->statStages[STAT_SPEED], DEFAULT_STAT_STAGE);
    }
}

TWO_VS_ONE_BATTLE_TEST("Commander only activates for the opponent side in a 2v1 battle")
{
    GIVEN {
        PLAYER(SPECIES_TATSUGIRI) { Ability(ABILITY_COMMANDER); }
        PARTNER(SPECIES_DONDOZO);
        OPPONENT(SPECIES_TATSUGIRI) { Ability(ABILITY_COMMANDER); }
        OPPONENT(SPECIES_DONDOZO);
    } WHEN {
        TURN {}
    } SCENE {
        NOT ABILITY_POPUP(playerLeft, ABILITY_COMMANDER);
        ABILITY_POPUP(opponentLeft, ABILITY_COMMANDER);
    } THEN {
        EXPECT_EQ(playerRight->statStages[STAT_ATK], DEFAULT_STAT_STAGE);
        EXPECT_EQ(playerRight->statStages[STAT_DEF], DEFAULT_STAT_STAGE);
        EXPECT_EQ(playerRight->statStages[STAT_SPATK], DEFAULT_STAT_STAGE);
        EXPECT_EQ(playerRight->statStages[STAT_SPDEF], DEFAULT_STAT_STAGE);
        EXPECT_EQ(playerRight->statStages[STAT_SPEED], DEFAULT_STAT_STAGE);
        EXPECT_EQ(opponentRight->statStages[STAT_ATK], DEFAULT_STAT_STAGE + 2);
        EXPECT_EQ(opponentRight->statStages[STAT_DEF], DEFAULT_STAT_STAGE + 2);
        EXPECT_EQ(opponentRight->statStages[STAT_SPATK], DEFAULT_STAT_STAGE + 2);
        EXPECT_EQ(opponentRight->statStages[STAT_SPDEF], DEFAULT_STAT_STAGE + 2);
        EXPECT_EQ(opponentRight->statStages[STAT_SPEED], DEFAULT_STAT_STAGE + 2);
    }
}

ONE_VS_TWO_BATTLE_TEST("Commander only activates for the player side in a 1v2 battle")
{
    GIVEN {
        PLAYER(SPECIES_TATSUGIRI) { Ability(ABILITY_COMMANDER); }
        PLAYER(SPECIES_DONDOZO);
        OPPONENT_A(SPECIES_TATSUGIRI) { Ability(ABILITY_COMMANDER); }
        OPPONENT_B(SPECIES_DONDOZO);
    } WHEN {
        TURN {}
    } SCENE {
        ABILITY_POPUP(playerLeft, ABILITY_COMMANDER);
        NOT ABILITY_POPUP(opponentLeft, ABILITY_COMMANDER);
    } THEN {
        EXPECT_EQ(playerRight->statStages[STAT_ATK], DEFAULT_STAT_STAGE + 2);
        EXPECT_EQ(playerRight->statStages[STAT_DEF], DEFAULT_STAT_STAGE + 2);
        EXPECT_EQ(playerRight->statStages[STAT_SPATK], DEFAULT_STAT_STAGE + 2);
        EXPECT_EQ(playerRight->statStages[STAT_SPDEF], DEFAULT_STAT_STAGE + 2);
        EXPECT_EQ(playerRight->statStages[STAT_SPEED], DEFAULT_STAT_STAGE + 2);
        EXPECT_EQ(opponentRight->statStages[STAT_ATK], DEFAULT_STAT_STAGE);
        EXPECT_EQ(opponentRight->statStages[STAT_DEF], DEFAULT_STAT_STAGE);
        EXPECT_EQ(opponentRight->statStages[STAT_SPATK], DEFAULT_STAT_STAGE);
        EXPECT_EQ(opponentRight->statStages[STAT_SPDEF], DEFAULT_STAT_STAGE);
        EXPECT_EQ(opponentRight->statStages[STAT_SPEED], DEFAULT_STAT_STAGE);
    }
}
