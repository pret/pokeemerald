#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gMovesInfo[MOVE_MIND_BLOWN].effect == EFFECT_MIND_BLOWN);
}

SINGLE_BATTLE_TEST("Mind Blown makes the user lose 1/2 of its HP")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { HP(400); MaxHP(400); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_MIND_BLOWN); }
    } SCENE {
        HP_BAR(player, damage: 200);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MIND_BLOWN, player);
        NOT MESSAGE("Wobbuffet fainted!"); // Wobb had more than 1/2 of its HP, so it can't faint.
    }
}

DOUBLE_BATTLE_TEST("Mind Blown makes the user lose 1/2 of its HP in a double battle")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { HP(400); MaxHP(400); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_MIND_BLOWN); }
    } SCENE {
        HP_BAR(playerLeft, damage: 200);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MIND_BLOWN, playerLeft);
        NOT MESSAGE("Wobbuffet fainted!"); // Wobb had more than 1/2 of its HP, so it can't faint.
    }
}

SINGLE_BATTLE_TEST("Mind Blown causes the user to faint when below 1/2 of its HP")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { HP(200); MaxHP(400); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_MIND_BLOWN); }
    } SCENE {
        HP_BAR(player, hp: 0);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MIND_BLOWN, player);
        MESSAGE("Wobbuffet fainted!");
    }
}

DOUBLE_BATTLE_TEST("Mind Blown causes the user to faint when below 1/2 of its HP in a double battle")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { HP(200); MaxHP(400); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_MIND_BLOWN); }
    } SCENE {
        HP_BAR(playerLeft, hp: 0);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MIND_BLOWN, playerLeft);
        MESSAGE("Wobbuffet fainted!");
    }
}

SINGLE_BATTLE_TEST("Mind Blown causes the user & the target to faint when below 1/2 of its HP")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { HP(200) ; MaxHP(400); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(1); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_MIND_BLOWN); }
    } SCENE {
        HP_BAR(player, hp: 0);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MIND_BLOWN, player);
        HP_BAR(opponent, hp: 0);
        MESSAGE("Foe Wobbuffet fainted!");
        MESSAGE("Wobbuffet fainted!");
    }
}

DOUBLE_BATTLE_TEST("Mind Blown causes everyone to faint in a double battle")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { HP(200); MaxHP(400); }
        PLAYER(SPECIES_WYNAUT) { HP(1); }
        OPPONENT(SPECIES_ABRA) { HP(1); }
        OPPONENT(SPECIES_KADABRA) { HP(1); }
        OPPONENT(SPECIES_KADABRA);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_MIND_BLOWN); }
    } SCENE {
        HP_BAR(playerLeft, hp: 0);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MIND_BLOWN, playerLeft);
        HP_BAR(opponentLeft, hp: 0);
        MESSAGE("Foe Abra fainted!");
        HP_BAR(playerRight, hp: 0);
        MESSAGE("Wynaut fainted!");
        HP_BAR(opponentRight, hp: 0);
        MESSAGE("Foe Kadabra fainted!");
        MESSAGE("Wobbuffet fainted!");
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
        NOT HP_BAR(player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MIND_BLOWN, player);
    }
}
