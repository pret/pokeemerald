#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Tera Shell makes all moves against Terapagos not very effective when at full HP")
{
    u16 hp;
    PARAMETRIZE { hp = 100; }
    PARAMETRIZE { hp = 99; }
    GIVEN {
        PLAYER(SPECIES_TERAPAGOS_TERASTAL) { Ability(ABILITY_TERA_SHELL); HP(hp); MaxHP(100);}
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_TACKLE); }
    } SCENE {
        if (hp == 100) {
            MESSAGE("Foe Wobbuffet used Tackle!");
            ABILITY_POPUP(player, ABILITY_TERA_SHELL);
            MESSAGE("Terapagos made its shell gleam! It's distorting type matchups!");
            ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, opponent);
            HP_BAR(player);
            MESSAGE("It's not very effective…");
        }
        else {
            NONE_OF {
                ABILITY_POPUP(player, ABILITY_TERA_SHELL);
                MESSAGE("Terapagos made its shell gleam! It's distorting type matchups!");
                MESSAGE("It's not very effective…");
            }
        }
    }
}

SINGLE_BATTLE_TEST("Tera Shell makes all hits of multi-hit moves against Terapagos not very effective")
{
    s16 firstHit;
    s16 secondHit;
    GIVEN {
        PLAYER(SPECIES_TERAPAGOS_TERASTAL) { Ability(ABILITY_TERA_SHELL); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_DOUBLE_HIT); }
    } SCENE {
        MESSAGE("Foe Wobbuffet used Double Hit!");
        ABILITY_POPUP(player, ABILITY_TERA_SHELL);
        MESSAGE("Terapagos made its shell gleam! It's distorting type matchups!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DOUBLE_HIT, opponent);
        HP_BAR(player, captureDamage: &firstHit);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DOUBLE_HIT, opponent);
        HP_BAR(player, captureDamage: &secondHit);
        MESSAGE("It's not very effective…");
    } THEN {
        EXPECT_EQ(firstHit, secondHit);
    }
}

DOUBLE_BATTLE_TEST("Tera Shell only makes the first hit of a double battle turn not very effective")
{
    s16 firstHit;
    s16 secondHit;
    GIVEN {
        PLAYER(SPECIES_TERAPAGOS_TERASTAL) { Ability(ABILITY_TERA_SHELL); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_TACKLE, target: playerLeft); MOVE(opponentRight, MOVE_TACKLE, target: playerLeft); }
    } SCENE {
        ABILITY_POPUP(playerLeft, ABILITY_TERA_SHELL);
        MESSAGE("Terapagos made its shell gleam! It's distorting type matchups!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, opponentLeft);
        HP_BAR(playerLeft, captureDamage: &firstHit);
        MESSAGE("It's not very effective…");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, opponentRight);
        HP_BAR(playerLeft, captureDamage: &secondHit);
        NOT MESSAGE("It's not very effective…");
    } THEN {
        EXPECT_MUL_EQ(firstHit, Q_4_12(2.0), secondHit);
    }
}

DOUBLE_BATTLE_TEST("Tera Shell only makes the first hit against Terapagos from a multi-target move not very effective")
{
    GIVEN {
        PLAYER(SPECIES_TERAPAGOS_TERASTAL) { Ability(ABILITY_TERA_SHELL); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_BLIZZARD); }
    } SCENE {
        ABILITY_POPUP(playerLeft, ABILITY_TERA_SHELL);
        MESSAGE("Terapagos made its shell gleam! It's distorting type matchups!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BLIZZARD, opponentLeft);
        HP_BAR(playerLeft);
        MESSAGE("It's not very effective…");
        HP_BAR(playerRight);
        NOT MESSAGE("It's not very effective…");
    }
}
