#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_SHELL_SIDE_ARM) == EFFECT_SHELL_SIDE_ARM);
    ASSUME(GetMoveEffect(MOVE_COUNTER) == EFFECT_REFLECT_DAMAGE);
    ASSUME(GetMoveReflectDamage_DamageCategories(MOVE_COUNTER) == (1u << DAMAGE_CATEGORY_PHYSICAL));
    ASSUME(GetMoveEffect(MOVE_MIRROR_COAT) == EFFECT_REFLECT_DAMAGE);
    ASSUME(GetMoveReflectDamage_DamageCategories(MOVE_MIRROR_COAT) == (1u << DAMAGE_CATEGORY_SPECIAL));
}

SINGLE_BATTLE_TEST("Shell Side Arm can be countered if it is physical")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_SHELL_SIDE_ARM); }
        OPPONENT(SPECIES_REGICE) { Defense(100); SpDefense(200); }
    } WHEN {
        TURN { MOVE(player, MOVE_SHELL_SIDE_ARM); MOVE(opponent, MOVE_COUNTER); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SHELL_SIDE_ARM, player);
        HP_BAR(opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_COUNTER, opponent);
        HP_BAR(player);
    }
}

SINGLE_BATTLE_TEST("Shell Side Arm can be mirror coated if it is special")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_SHELL_SIDE_ARM); }
        OPPONENT(SPECIES_REGIROCK) { Defense(200); SpDefense(100); }
    } WHEN {
        TURN { MOVE(player, MOVE_SHELL_SIDE_ARM); MOVE(opponent, MOVE_MIRROR_COAT); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SHELL_SIDE_ARM, player);
        HP_BAR(opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MIRROR_COAT, opponent);
        HP_BAR(player);
    }
}

DOUBLE_BATTLE_TEST("Shell Side Arm does not change category mid-turn")
{
    GIVEN {
        ASSUME_STAT_CHANGE(MOVE_SCREECH, defense: -2);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_SHUCKLE) { Ability(ABILITY_CONTRARY); Defense(100); SpDefense(120); }
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_SHELL_SIDE_ARM, target: opponentLeft); MOVE(opponentLeft, MOVE_MIRROR_COAT, target: opponentLeft); }
        TURN { MOVE(playerRight, MOVE_SCREECH, target: opponentLeft); MOVE(playerLeft, MOVE_SHELL_SIDE_ARM, target: opponentLeft); MOVE(opponentLeft, MOVE_MIRROR_COAT, target: opponentLeft); }
        TURN { MOVE(playerLeft, MOVE_SHELL_SIDE_ARM, target: opponentLeft); MOVE(opponentLeft, MOVE_MIRROR_COAT, target: opponentLeft); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SHELL_SIDE_ARM, playerLeft);
        HP_BAR(opponentLeft);
        NOT HP_BAR(playerLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCREECH, playerRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SHELL_SIDE_ARM, playerLeft);
        HP_BAR(opponentLeft);
        NOT HP_BAR(playerLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SHELL_SIDE_ARM, playerLeft);
        HP_BAR(opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MIRROR_COAT, opponentLeft);
        HP_BAR(playerLeft);
    }
}

DOUBLE_BATTLE_TEST("Shell Side Arm chooses its category for each battler on the field")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(10); Moves(MOVE_SHELL_SIDE_ARM); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(20); }
        OPPONENT(SPECIES_REGIROCK) { Speed(30); Defense(200); SpDefense(100); }
        OPPONENT(SPECIES_REGICE) { Speed(30); Defense(100); SpDefense(200); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_SHELL_SIDE_ARM, target: opponentRight); MOVE(opponentRight, MOVE_COUNTER); }
        TURN { MOVE(playerLeft, MOVE_SHELL_SIDE_ARM, target: opponentLeft); MOVE(opponentLeft, MOVE_MIRROR_COAT); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SHELL_SIDE_ARM, playerLeft);
        HP_BAR(opponentRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_COUNTER, opponentRight);
        HP_BAR(playerLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SHELL_SIDE_ARM, playerLeft);
        HP_BAR(opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MIRROR_COAT, opponentLeft);
        HP_BAR(playerLeft);
    }
}
