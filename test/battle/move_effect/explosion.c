#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gMovesInfo[MOVE_EXPLOSION].effect == EFFECT_EXPLOSION);
}

SINGLE_BATTLE_TEST("Explosion causes the user to faint")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_EXPLOSION); }
    } SCENE {
        HP_BAR(player, hp: 0);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EXPLOSION, player);
        MESSAGE("Wobbuffet fainted!");
    }
}

SINGLE_BATTLE_TEST("Explosion causes the user & the target to faint")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { HP(1); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_EXPLOSION); }
    } SCENE {
        HP_BAR(player, hp: 0);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EXPLOSION, player);
        HP_BAR(opponent, hp: 0);
        MESSAGE("Foe Wobbuffet fainted!");
        MESSAGE("Wobbuffet fainted!");
    }
}

SINGLE_BATTLE_TEST("Explosion causes the user to faint even if it misses")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_EXPLOSION, hit: FALSE); }
    } SCENE {
        HP_BAR(player, hp: 0);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EXPLOSION, player);
        MESSAGE("Wobbuffet fainted!");
    }
}

SINGLE_BATTLE_TEST("Explosion causes the user to faint even if it has no effect")
{
    GIVEN {
        ASSUME(gMovesInfo[MOVE_EXPLOSION].type == TYPE_NORMAL);
        ASSUME(gSpeciesInfo[SPECIES_GASTLY].types[0] == TYPE_GHOST);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_GASTLY);
    } WHEN {
        TURN { MOVE(player, MOVE_EXPLOSION); }
    } SCENE {
        HP_BAR(player, hp: 0);
        MESSAGE("It doesn't affect Foe Gastly…");
        NOT HP_BAR(opponent);
        MESSAGE("Wobbuffet fainted!");
    }
}

DOUBLE_BATTLE_TEST("Explosion causes everyone to faint in a double battle")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT) { HP(1); }
        OPPONENT(SPECIES_ABRA) { HP(1); }
        OPPONENT(SPECIES_KADABRA) { HP(1); }
        OPPONENT(SPECIES_KADABRA);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_EXPLOSION); }
    } SCENE {
        HP_BAR(playerLeft, hp: 0);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EXPLOSION, playerLeft);
        HP_BAR(opponentLeft, hp: 0);
        MESSAGE("Foe Abra fainted!");
        HP_BAR(playerRight, hp: 0);
        MESSAGE("Wynaut fainted!");
        HP_BAR(opponentRight, hp: 0);
        MESSAGE("Foe Kadabra fainted!");
        MESSAGE("Wobbuffet fainted!");
    }
}

SINGLE_BATTLE_TEST("Explosion is blocked by Ability Damp")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_GOLDUCK) { Ability(ABILITY_DAMP); }
    } WHEN {
        TURN { MOVE(player, MOVE_EXPLOSION); }
    } SCENE {
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_EXPLOSION, player);
            HP_BAR(player, hp: 0);
        }
        ABILITY_POPUP(opponent, ABILITY_DAMP);
        MESSAGE("Foe Golduck's Damp prevents Wobbuffet from using Explosion!");
    }
}

SINGLE_BATTLE_TEST("Explosion does not trigger Destiny Bond")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { HP(1); };
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_DESTINY_BOND); MOVE(opponent, MOVE_EXPLOSION);}
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DESTINY_BOND, player);
        HP_BAR(opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EXPLOSION, opponent);
        HP_BAR(player);
        NOT HP_BAR(opponent);
    }
}
