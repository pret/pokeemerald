#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_HEALING_WISH) == EFFECT_HEALING_WISH);
}

SINGLE_BATTLE_TEST("Healing Wish causes the user to faint and heals the replacement's HP and status (singles)")
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
        TURN { MOVE(player, MOVE_HEALING_WISH); SEND_OUT(player, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HEALING_WISH, player);
        HP_BAR(player, hp: 0);
        MESSAGE("Gardevoir fainted!");
        MESSAGE("The healing wish came true for Wynaut!");
        HP_BAR(player, hp: 100);
        STATUS_ICON(player, none: TRUE);
        MESSAGE("Wynaut regained health!");
    } THEN {
        EXPECT_EQ(player->hp, 100);
        EXPECT_EQ(player->status1, 0);
         // PP not healed
        EXPECT_EQ(player->pp[0], 5);
        EXPECT_EQ(player->pp[1], 5);
        EXPECT_EQ(player->pp[2], 5);
        EXPECT_EQ(player->pp[3], 0);
    }
}

DOUBLE_BATTLE_TEST("Healing Wish causes the user to faint and heals the replacement's HP and status (doubles)")
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
        TURN { MOVE(playerLeft, MOVE_HEALING_WISH); SEND_OUT(playerLeft, 2); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HEALING_WISH, playerLeft);
        HP_BAR(playerLeft, hp: 0);
        MESSAGE("Gardevoir fainted!");
        MESSAGE("The healing wish came true for Wynaut!");
        HP_BAR(playerLeft, hp: 100);
        STATUS_ICON(playerLeft, none: TRUE);
        MESSAGE("Wynaut regained health!");
    } THEN {
        EXPECT_EQ(playerLeft->hp, 100);
        EXPECT_EQ(playerLeft->status1, 0);
         // PP not healed
        EXPECT_EQ(playerLeft->pp[0], 5);
        EXPECT_EQ(playerLeft->pp[1], 5);
        EXPECT_EQ(playerLeft->pp[2], 5);
        EXPECT_EQ(playerLeft->pp[3], 0);
    }
}

SINGLE_BATTLE_TEST("Healing Wish effect activates even if the the switched Pokémon can't be healed (Gen4-7)")
{
    GIVEN {
        WITH_CONFIG(B_HEALING_WISH_SWITCH, GEN_7);
        PLAYER(SPECIES_GARDEVOIR) { Speed(300); }
        PLAYER(SPECIES_NINJASK) { Speed(400); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(50); }
    } WHEN {
        TURN { MOVE(player, MOVE_HEALING_WISH); SEND_OUT(player, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HEALING_WISH, player);
        HP_BAR(player, hp: 0);
        MESSAGE("Gardevoir fainted!");
        MESSAGE("The healing wish came true for Ninjask!");
        MESSAGE("Ninjask regained health!");
    }
}

SINGLE_BATTLE_TEST("Healing Wish effect activates only if the switched Pokémon can be healed (Gen8+)")
{
    u32 switchTo;
    PARAMETRIZE { switchTo = 2; }
    PARAMETRIZE { switchTo = 3; }
    PARAMETRIZE { switchTo = 4; }
    GIVEN {
        WITH_CONFIG(B_HEALING_WISH_SWITCH, GEN_8);
        PLAYER(SPECIES_GARDEVOIR) { Speed(300); }
        PLAYER(SPECIES_NINJASK) { Speed(400); }
        PLAYER(SPECIES_WYNAUT) { HP(50); MaxHP(100); Speed(50); }
        PLAYER(SPECIES_WYNAUT) { Status1(STATUS1_PARALYSIS); Speed(50); }
        PLAYER(SPECIES_WYNAUT) { MovesWithPP({MOVE_SCRATCH, 5}); Speed(50); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(50); }
    } WHEN {
        TURN { MOVE(player, MOVE_HEALING_WISH); SEND_OUT(player, 1); }
        TURN { MOVE(player, MOVE_U_TURN); SEND_OUT(player, switchTo); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HEALING_WISH, player);
        HP_BAR(player, hp: 0);
        MESSAGE("Gardevoir fainted!");
        NONE_OF {
            MESSAGE("The healing wish came true for Ninjask!");
            MESSAGE("Ninjask regained health!");
        }
        ANIMATION(ANIM_TYPE_MOVE, MOVE_U_TURN, player);
        if (switchTo == 2) {
            MESSAGE("The healing wish came true for Wynaut!");
            HP_BAR(player, hp: 100);
            MESSAGE("Wynaut regained health!");
        } else if (switchTo == 3) {
            MESSAGE("The healing wish came true for Wynaut!");
            STATUS_ICON(player, none: TRUE);
            MESSAGE("Wynaut regained health!");
        } else {
            NONE_OF {
                MESSAGE("The healing wish came true for Wynaut!");
                MESSAGE("Wynaut regained health!");
            }
        }
    } THEN {
        if (switchTo == 2) {
            EXPECT_EQ(player->hp, 100);
        } else if (switchTo == 3) {
            EXPECT_EQ(player->status1, 0);
        } else if (switchTo == 4) {
            EXPECT_EQ(player->pp[0], 5); // Did NOT heal PP
        }
    }
}
