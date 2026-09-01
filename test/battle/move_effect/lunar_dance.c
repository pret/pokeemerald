#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_LUNAR_DANCE) == EFFECT_LUNAR_DANCE);
}

SINGLE_BATTLE_TEST("Lunar Dance causes the user to faint and heals the replacement's HP, PP and status (singles)")
{
    GIVEN {
        WITH_CONFIG(B_HEALING_WISH_SWITCH, GEN_7);
        ASSUME(GetMovePP(MOVE_SCRATCH) == 35);
        ASSUME(GetMovePP(MOVE_WATER_GUN) == 25);
        ASSUME(GetMovePP(MOVE_LEAFAGE) == 40);
        ASSUME(GetMovePP(MOVE_EMBER) == 25);
        PLAYER(SPECIES_GARDEVOIR);
        PLAYER(SPECIES_WYNAUT) { HP(1); MaxHP(100); Status1(STATUS1_POISON);
            MovesWithPP({MOVE_SCRATCH, 5}, {MOVE_WATER_GUN, 5}, {MOVE_LEAFAGE, 5}, {MOVE_EMBER, 0}); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_LUNAR_DANCE); SEND_OUT(player, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_LUNAR_DANCE, player);
        HP_BAR(player, hp: 0);
        MESSAGE("Gardevoir fainted!");
        MESSAGE("Wynaut became cloaked in mystical moonlight!");
        HP_BAR(player, hp: 100);
        STATUS_ICON(player, none: TRUE);
        MESSAGE("Wynaut regained health!");
    } THEN {
        EXPECT_EQ(player->hp, 100);
        EXPECT_EQ(player->status1, 0);
         // PP not healed
        EXPECT_EQ(player->pp[0], 35);
        EXPECT_EQ(player->pp[1], 25);
        EXPECT_EQ(player->pp[2], 40);
        EXPECT_EQ(player->pp[3], 25);
    }
}

DOUBLE_BATTLE_TEST("Lunar Dance causes the user to faint and heals the replacement's HP, PP and status (doubles)")
{
    GIVEN {
        WITH_CONFIG(B_HEALING_WISH_SWITCH, GEN_7);
        ASSUME(GetMovePP(MOVE_SCRATCH) == 35);
        ASSUME(GetMovePP(MOVE_WATER_GUN) == 25);
        ASSUME(GetMovePP(MOVE_LEAFAGE) == 40);
        ASSUME(GetMovePP(MOVE_EMBER) == 25);
        PLAYER(SPECIES_GARDEVOIR) { Speed(300); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(50); }
        PLAYER(SPECIES_WYNAUT) { HP(1); MaxHP(100); Status1(STATUS1_BURN); Speed(50);
            MovesWithPP({MOVE_SCRATCH, 5}, {MOVE_WATER_GUN, 5}, {MOVE_LEAFAGE, 5}, {MOVE_EMBER, 0}); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(50); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(50); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_LUNAR_DANCE); SEND_OUT(playerLeft, 2); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_LUNAR_DANCE, playerLeft);
        HP_BAR(playerLeft, hp: 0);
        MESSAGE("Gardevoir fainted!");
        MESSAGE("Wynaut became cloaked in mystical moonlight!");
        HP_BAR(playerLeft, hp: 100);
        STATUS_ICON(playerLeft, none: TRUE);
        MESSAGE("Wynaut regained health!");
    } THEN {
        EXPECT_EQ(playerLeft->hp, 100);
        EXPECT_EQ(playerLeft->status1, 0);
        EXPECT_EQ(playerLeft->pp[0], 35);
        EXPECT_EQ(playerLeft->pp[1], 25);
        EXPECT_EQ(playerLeft->pp[2], 40);
        EXPECT_EQ(playerLeft->pp[3], 25);
    }
}

SINGLE_BATTLE_TEST("Lunar Dance effect activates even if the the switched Pokémon can't be healed (Gen4-7)")
{
    GIVEN {
        WITH_CONFIG(B_HEALING_WISH_SWITCH, GEN_7);
        PLAYER(SPECIES_GARDEVOIR) { Speed(300); }
        PLAYER(SPECIES_NINJASK) { Speed(400); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(50); }
    } WHEN {
        TURN { MOVE(player, MOVE_LUNAR_DANCE); SEND_OUT(player, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_LUNAR_DANCE, player);
        HP_BAR(player, hp: 0);
        MESSAGE("Gardevoir fainted!");
        MESSAGE("Ninjask became cloaked in mystical moonlight!");
        MESSAGE("Ninjask regained health!");
    }
}

SINGLE_BATTLE_TEST("Lunar Dance effect activates only if the switched Pokémon can be healed (Gen8+)")
{
    u32 switchTo;
    PARAMETRIZE { switchTo = 2; }
    PARAMETRIZE { switchTo = 3; }
    PARAMETRIZE { switchTo = 4; }
    GIVEN {
        ASSUME(GetMovePP(MOVE_SCRATCH) == 35);
        WITH_CONFIG(B_HEALING_WISH_SWITCH, GEN_8);
        PLAYER(SPECIES_GARDEVOIR) { Speed(300); }
        PLAYER(SPECIES_NINJASK) { Speed(400); }
        PLAYER(SPECIES_WYNAUT) { HP(50); MaxHP(100); Speed(50); }
        PLAYER(SPECIES_WYNAUT) { Status1(STATUS1_PARALYSIS); Speed(50); }
        PLAYER(SPECIES_WYNAUT) { MovesWithPP({MOVE_SCRATCH, 5}); Speed(50); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(50); }
    } WHEN {
        TURN { MOVE(player, MOVE_LUNAR_DANCE); SEND_OUT(player, 1); }
        TURN { MOVE(player, MOVE_U_TURN); SEND_OUT(player, switchTo); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_LUNAR_DANCE, player);
        HP_BAR(player, hp: 0);
        MESSAGE("Gardevoir fainted!");
        NONE_OF {
            MESSAGE("Ninjask became cloaked in mystical moonlight!");
            MESSAGE("Ninjask regained health!");
        }
        ANIMATION(ANIM_TYPE_MOVE, MOVE_U_TURN, player);
        MESSAGE("Wynaut became cloaked in mystical moonlight!");
        if (switchTo == 2) {
            HP_BAR(player, hp: 100);
        } else if (switchTo == 3) {
            STATUS_ICON(player, none: TRUE);
        }
        MESSAGE("Wynaut regained health!");
    } THEN {
        if (switchTo == 2) {
            EXPECT_EQ(player->hp, 100);
        } else if (switchTo == 3) {
            EXPECT_EQ(player->status1, 0);
        } else if (switchTo == 4) {
            EXPECT_EQ(player->pp[0], 35);
        }
    }
}
