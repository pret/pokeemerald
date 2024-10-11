#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gMovesInfo[MOVE_DRAGON_DARTS].effect == EFFECT_DRAGON_DARTS);
    ASSUME(gSpeciesInfo[SPECIES_CLEFAIRY].types[0] == TYPE_FAIRY || gSpeciesInfo[SPECIES_CLEFAIRY].types[1] == TYPE_FAIRY);
}

SINGLE_BATTLE_TEST("Dragon Darts strikes twice")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_DRAGON_DARTS); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_DARTS, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_DARTS, player);
        MESSAGE("Hit 2 time(s)!");
    }
}

DOUBLE_BATTLE_TEST("Dragon Darts strikes each opponent once in a double battle")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_DRAGON_DARTS, target: opponentLeft); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_DARTS, playerLeft);
        HP_BAR(opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_DARTS, playerLeft);
        HP_BAR(opponentRight);
        MESSAGE("Hit 2 time(s)!");
    }
}

DOUBLE_BATTLE_TEST("Dragon Darts strikes the ally twice if the target protects")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_PROTECT); MOVE(playerLeft, MOVE_DRAGON_DARTS, target: opponentLeft); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PROTECT, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_DARTS, playerLeft);
        HP_BAR(opponentRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_DARTS, playerLeft);
        HP_BAR(opponentRight);
        MESSAGE("Hit 2 time(s)!");
    }
}

DOUBLE_BATTLE_TEST("Dragon Darts strikes the right ally twice if the target is a fairy type")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_CLEFAIRY);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_DRAGON_DARTS, target: opponentLeft); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_DARTS, playerLeft);
        HP_BAR(opponentRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_DARTS, playerLeft);
        HP_BAR(opponentRight);
        MESSAGE("Hit 2 time(s)!");
    }
}

DOUBLE_BATTLE_TEST("Dragon Darts strikes the left ally twice if the target is a fairy type")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_CLEFAIRY);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_DRAGON_DARTS, target: opponentRight); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_DARTS, playerLeft);
        HP_BAR(opponentRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_DARTS, playerLeft);
        HP_BAR(opponentRight);
        MESSAGE("Hit 2 time(s)!");
    }
}

DOUBLE_BATTLE_TEST("Dragon Darts strikes left ally twice if electrified and right ally has Volt Absorb")
{
    GIVEN {
        ASSUME(gMovesInfo[MOVE_ELECTRIFY].effect == EFFECT_ELECTRIFY);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_LANTURN) { Ability(ABILITY_VOLT_ABSORB); };
    } WHEN {
        TURN { MOVE(opponentRight, MOVE_ELECTRIFY, target: playerLeft); MOVE(playerLeft, MOVE_DRAGON_DARTS, target: opponentRight); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_DARTS, playerLeft);
        HP_BAR(opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_DARTS, playerLeft);
        HP_BAR(opponentLeft);
        MESSAGE("Hit 2 time(s)!");
    }
}

DOUBLE_BATTLE_TEST("Dragon Darts strikes right ally twice if electrified and left ally has Volt Absorb")
{
    GIVEN {
        ASSUME(gMovesInfo[MOVE_ELECTRIFY].effect == EFFECT_ELECTRIFY);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_LANTURN) { Ability(ABILITY_VOLT_ABSORB); };
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponentRight, MOVE_ELECTRIFY, target: playerLeft); MOVE(playerLeft, MOVE_DRAGON_DARTS, target: opponentRight); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_DARTS, playerLeft);
        HP_BAR(opponentRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_DARTS, playerLeft);
        HP_BAR(opponentRight);
        MESSAGE("Hit 2 time(s)!");
    }
}

DOUBLE_BATTLE_TEST("Dragon Darts strikes left ally twice if electrified and right ally has Motor Drive")
{
    GIVEN {
        ASSUME(gMovesInfo[MOVE_ELECTRIFY].effect == EFFECT_ELECTRIFY);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_ELECTIVIRE) { Ability(ABILITY_MOTOR_DRIVE); };
    } WHEN {
        TURN { MOVE(opponentRight, MOVE_ELECTRIFY, target: playerLeft); MOVE(playerLeft, MOVE_DRAGON_DARTS, target: opponentRight); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_DARTS, playerLeft);
        HP_BAR(opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_DARTS, playerLeft);
        HP_BAR(opponentLeft);
        MESSAGE("Hit 2 time(s)!");
    }
}

DOUBLE_BATTLE_TEST("Dragon Darts strikes right ally twice if electrified and left ally has Motor Drive")
{
    GIVEN {
        ASSUME(gMovesInfo[MOVE_ELECTRIFY].effect == EFFECT_ELECTRIFY);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_ELECTIVIRE) { Ability(ABILITY_MOTOR_DRIVE); };
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponentRight, MOVE_ELECTRIFY, target: playerLeft); MOVE(playerLeft, MOVE_DRAGON_DARTS, target: opponentRight); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_DARTS, playerLeft);
        HP_BAR(opponentRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_DARTS, playerLeft);
        HP_BAR(opponentRight);
        MESSAGE("Hit 2 time(s)!");
    }
}


DOUBLE_BATTLE_TEST("Dragon Darts strikes the ally twice if the target is in a semi-invulnerable turn")
{
    GIVEN {
        ASSUME(gMovesInfo[MOVE_FLY].effect == EFFECT_SEMI_INVULNERABLE);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_FLY, target: playerLeft); MOVE(playerLeft, MOVE_DRAGON_DARTS, target: opponentLeft); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FLY, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_DARTS, playerLeft);
        HP_BAR(opponentRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_DARTS, playerLeft);
        HP_BAR(opponentRight);
        MESSAGE("Hit 2 time(s)!");
    }
}

DOUBLE_BATTLE_TEST("Dragon Darts is not effected by Wide Guard")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_WIDE_GUARD); MOVE(playerLeft, MOVE_DRAGON_DARTS, target: opponentLeft); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_WIDE_GUARD, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_DARTS, playerLeft);
        HP_BAR(opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_DARTS, playerLeft);
        HP_BAR(opponentRight);
        MESSAGE("Hit 2 time(s)!");
    }
}

DOUBLE_BATTLE_TEST("Dragon Darts strikes hit the ally if the target fainted")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { HP(1); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerRight, MOVE_SONIC_BOOM, target: opponentLeft); MOVE(playerLeft, MOVE_DRAGON_DARTS, target: opponentLeft); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SONIC_BOOM, playerRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_DARTS, playerLeft);
        HP_BAR(opponentRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_DARTS, playerLeft);
        HP_BAR(opponentRight);
        MESSAGE("Hit 2 time(s)!");
    }
}

DOUBLE_BATTLE_TEST("Dragon Darts strikes left ally twice if one strike misses")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_BRIGHT_POWDER); };
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_DRAGON_DARTS, target: opponentRight, hit: FALSE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_DARTS, playerLeft);
        HP_BAR(opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_DARTS, playerLeft);
        HP_BAR(opponentLeft);
        MESSAGE("Hit 2 time(s)!");
    }
}

DOUBLE_BATTLE_TEST("Dragon Darts strikes right ally twice if one strike misses")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_BRIGHT_POWDER); };
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_DRAGON_DARTS, target: opponentLeft, hit: FALSE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_DARTS, playerLeft);
        HP_BAR(opponentRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_DARTS, playerLeft);
        HP_BAR(opponentRight);
        MESSAGE("Hit 2 time(s)!");
    }
}
