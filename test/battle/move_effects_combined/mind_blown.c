#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_MIND_BLOWN) == EFFECT_MAX_HP_50_RECOIL);
    ASSUME(IsMoveDampBanned(MOVE_MIND_BLOWN));
}

SINGLE_BATTLE_TEST("Mind Blown makes the user lose 1/2 of its Max HP")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { HP(400); MaxHP(400); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_MIND_BLOWN); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MIND_BLOWN, player);
        HP_BAR(player, damage: 200);
        NOT MESSAGE("Wobbuffet fainted!"); // Wobb had more than 1/2 of its HP, so it can't faint.
    }
}

DOUBLE_BATTLE_TEST("Mind Blown makes the user lose 1/2 of its Max HP in a double battle")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { HP(400); MaxHP(400); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_MIND_BLOWN); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MIND_BLOWN, playerLeft);
        HP_BAR(playerLeft, damage: 200);
        NOT MESSAGE("Wobbuffet fainted!"); // Wobb had more than 1/2 of its HP, so it can't faint.
    }
}

SINGLE_BATTLE_TEST("Mind Blown causes the user to faint when below 1/2 of its Max HP")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { HP(200); MaxHP(400); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_MIND_BLOWN); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MIND_BLOWN, player);
        HP_BAR(player, hp: 0);
        MESSAGE("Wobbuffet fainted!");
    }
}

DOUBLE_BATTLE_TEST("Mind Blown causes the user to faint when below 1/2 of its Max HP in a double battle")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { HP(200); MaxHP(400); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_MIND_BLOWN); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MIND_BLOWN, playerLeft);
        HP_BAR(playerLeft, hp: 0);
        MESSAGE("Wobbuffet fainted!");
    }
}

SINGLE_BATTLE_TEST("Mind Blown causes the user & the target to faint when below 1/2 of its Max HP")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { HP(200); MaxHP(400); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(1); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_MIND_BLOWN); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MIND_BLOWN, player);
        HP_BAR(opponent, hp: 0);
        HP_BAR(player, hp: 0);
        MESSAGE("Wobbuffet fainted!");
        MESSAGE("The opposing Wobbuffet fainted!");
    }
}

DOUBLE_BATTLE_TEST("Mind Blown causes everyone to faint in a double battle")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { HP(200); MaxHP(400); }
        PLAYER(SPECIES_WYNAUT) { HP(1); }
        OPPONENT(SPECIES_ABRA) { HP(1); }
        OPPONENT(SPECIES_KADABRA) { HP(1); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_MIND_BLOWN); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MIND_BLOWN, playerLeft);
        HP_BAR(opponentLeft, hp: 0);
        HP_BAR(playerRight, hp: 0);
        HP_BAR(opponentRight, hp: 0);
        HP_BAR(playerLeft, hp: 0);
        MESSAGE("Wobbuffet fainted!");
        MESSAGE("The opposing Abra fainted!");
        MESSAGE("Wynaut fainted!");
        MESSAGE("The opposing Kadabra fainted!");
    }
}

SINGLE_BATTLE_TEST("Mind Blown hp loss is prevented by Magic Guard")
{
    GIVEN {
        PLAYER(SPECIES_CLEFAIRY) { Ability(ABILITY_MAGIC_GUARD); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_MIND_BLOWN); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MIND_BLOWN, player);
        HP_BAR(opponent);
        NOT HP_BAR(player);
    }
}

DOUBLE_BATTLE_TEST("Mind Blown's recoil only happens once, regardless of number of affected targets")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { HP(399); MaxHP(400); }
        PLAYER(SPECIES_WYNAUT) { HP(1); }
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_ABRA) { HP(1); }
        OPPONENT(SPECIES_KADABRA) { HP(1); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_MIND_BLOWN); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MIND_BLOWN, playerLeft);
        HP_BAR(opponentLeft, hp: 0);
        HP_BAR(playerRight, hp: 0);
        HP_BAR(opponentRight, hp: 0);
        MESSAGE("The opposing Abra fainted!");
        MESSAGE("Wynaut fainted!");
        MESSAGE("The opposing Kadabra fainted!");
    } THEN {
        EXPECT_GT(playerLeft->hp, 0);
    }
}

SINGLE_BATTLE_TEST("Mind Blown is blocked by Damp")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { HP(400); MaxHP(400); }
        OPPONENT(SPECIES_GOLDUCK) { Ability(ABILITY_DAMP); }
    } WHEN {
        TURN { MOVE(player, MOVE_MIND_BLOWN); }
    } SCENE {
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_MIND_BLOWN, player);
            HP_BAR(player, damage: 200);
        }
        ABILITY_POPUP(opponent, ABILITY_DAMP);
        MESSAGE("Wobbuffet cannot use Mind Blown!");
    }
}

SINGLE_BATTLE_TEST("Mind Blown makes the user lose HP even if the opposing mon protected")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_PROTECT); MOVE(player, MOVE_MIND_BLOWN); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PROTECT, opponent);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_MIND_BLOWN, player);
        HP_BAR(player);
    }
}

SINGLE_BATTLE_TEST("Mind Blown makes the user lose HP even if it is absorbed by Flash Fire")
{
    GIVEN {
        ASSUME(GetMoveType(MOVE_MIND_BLOWN) == TYPE_FIRE);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_CYNDAQUIL) { Ability(ABILITY_FLASH_FIRE); }
    } WHEN {
        TURN { MOVE(player, MOVE_MIND_BLOWN); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_FLASH_FIRE);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_MIND_BLOWN, player);
        HP_BAR(player);
    }
}

SINGLE_BATTLE_TEST("Mind Blown does not cause the user to lose HP if there is no target")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_MEMENTO); MOVE(player, MOVE_MIND_BLOWN); SEND_OUT(opponent, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MEMENTO, opponent);
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_MIND_BLOWN, player);
            HP_BAR(player);
        }
        MESSAGE("Wobbuffet used Mind Blown!");
        MESSAGE("But it failed!");
        MESSAGE("2 sent out Wobbuffet!");
    }
}
