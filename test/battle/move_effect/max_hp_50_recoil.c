#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_STEEL_BEAM) == EFFECT_MAX_HP_50_RECOIL);
}

SINGLE_BATTLE_TEST("Steel Beam makes the user lose 1/2 of its Max HP")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { HP(400); MaxHP(400); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_STEEL_BEAM); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STEEL_BEAM, player);
        HP_BAR(player, damage: 200);
        NOT MESSAGE("Wobbuffet fainted!"); // Wobb had more than 1/2 of its HP, so it can't faint.
    }
}

DOUBLE_BATTLE_TEST("Steel Beam makes the user lose 1/2 of its Max HP in a double battle")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { HP(400); MaxHP(400); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_STEEL_BEAM, target:opponentLeft); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STEEL_BEAM, playerLeft);
        HP_BAR(playerLeft, damage: 200);
        NOT MESSAGE("Wobbuffet fainted!"); // Wobb had more than 1/2 of its HP, so it can't faint.
    }
}

SINGLE_BATTLE_TEST("Steel Beam causes the user to faint when below 1/2 of its Max HP")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { HP(200); MaxHP(400); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_STEEL_BEAM); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STEEL_BEAM, player);
        HP_BAR(player, hp: 0);
        MESSAGE("Wobbuffet fainted!");
    }
}

DOUBLE_BATTLE_TEST("Steel Beam causes the user to faint when below 1/2 of its Max HP in a double battle")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { HP(200); MaxHP(400); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_STEEL_BEAM, target:opponentLeft); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STEEL_BEAM, playerLeft);
        HP_BAR(playerLeft, hp: 0);
        MESSAGE("Wobbuffet fainted!");
    }
}

SINGLE_BATTLE_TEST("Steel Beam causes the user & the target to faint when below 1/2 of its Max HP")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { HP(200) ; MaxHP(400); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(1); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_STEEL_BEAM); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STEEL_BEAM, player);
        HP_BAR(opponent, hp: 0);
        HP_BAR(player, hp: 0);
        MESSAGE("Wobbuffet fainted!");
        MESSAGE("The opposing Wobbuffet fainted!");
    }
}

SINGLE_BATTLE_TEST("Steel Beam hp loss is prevented by Magic Guard")
{
    GIVEN {
        PLAYER(SPECIES_CLEFAIRY) { Ability(ABILITY_MAGIC_GUARD); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_STEEL_BEAM); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STEEL_BEAM, player);
        HP_BAR(opponent);
        NOT HP_BAR(player);
    }
}

SINGLE_BATTLE_TEST("Steel Beam makes the user lose HP even if the opposing mon protected")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_PROTECT); MOVE(player, MOVE_STEEL_BEAM); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PROTECT, opponent);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_STEEL_BEAM, player);
        HP_BAR(player);
    }
}

SINGLE_BATTLE_TEST("Steel Beam does not cause the user to lose HP if there is no target")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_MEMENTO); MOVE(player, MOVE_STEEL_BEAM); SEND_OUT(opponent, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MEMENTO, opponent);
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_STEEL_BEAM, player);
            HP_BAR(player);
        }
        MESSAGE("Wobbuffet used Steel Beam!");
        MESSAGE("But it failed!");
        MESSAGE("2 sent out Wobbuffet!");
    }
}

SINGLE_BATTLE_TEST("Steel Beam is not blocked by Damp")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { HP(400); MaxHP(400); }
        OPPONENT(SPECIES_GOLDUCK) { Ability(ABILITY_DAMP); }
    } WHEN {
        TURN { MOVE(player, MOVE_STEEL_BEAM); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STEEL_BEAM, player);
        HP_BAR(player, damage: 200);
        NONE_OF {
            ABILITY_POPUP(opponent, ABILITY_DAMP);
            MESSAGE("The opposing Golduck's Damp prevents Wobbuffet from using Steel Beam!");
        }
    }
}

SINGLE_BATTLE_TEST("Steel Beam inflicts recoil if it hits a Substitute")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { HP(400); MaxHP(400); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SUBSTITUTE); MOVE(player, MOVE_STEEL_BEAM); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SUBSTITUTE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STEEL_BEAM, player);
        SUB_HIT(opponent);
        HP_BAR(player, damage: 200);
    }
}
