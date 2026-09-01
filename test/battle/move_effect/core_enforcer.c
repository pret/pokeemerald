#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(MoveHasAdditionalEffect(MOVE_CORE_ENFORCER, MOVE_EFFECT_CORE_ENFORCER));
    ASSUME(GetMoveType(MOVE_EARTHQUAKE) == TYPE_GROUND);
}

SINGLE_BATTLE_TEST("Core Enforcer suppresses the ability of targets that have already acted")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WEEZING) { Ability(ABILITY_LEVITATE); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_CELEBRATE); MOVE(player, MOVE_CORE_ENFORCER); }
        TURN { MOVE(player, MOVE_EARTHQUAKE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CORE_ENFORCER, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EARTHQUAKE, player);
        HP_BAR(opponent);
    }
}

SINGLE_BATTLE_TEST("Core Enforcer doesn't suppresses the ability of targets that haven't acted")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WEEZING) { Ability(ABILITY_LEVITATE); }
    } WHEN {
        TURN { MOVE(player, MOVE_CORE_ENFORCER); MOVE(opponent, MOVE_CELEBRATE); }
        TURN { MOVE(player, MOVE_EARTHQUAKE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CORE_ENFORCER, player);
        HP_BAR(opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_EARTHQUAKE, player);
            HP_BAR(opponent);
        }
    }
}

SINGLE_BATTLE_TEST("Core Enforcer suppresses the ability of targets that have already acted that are behind Substitutes")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WEEZING) { Ability(ABILITY_LEVITATE); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SUBSTITUTE); MOVE(player, MOVE_CORE_ENFORCER); }
        TURN { MOVE(player, MOVE_EARTHQUAKE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SUBSTITUTE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CORE_ENFORCER, player);
        SUB_HIT(opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EARTHQUAKE, player);
        SUB_HIT(opponent);
    }
}

SINGLE_BATTLE_TEST("Core Enforcer does not suppress the ability of a target that switched in this turn")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WEEZING) { Ability(ABILITY_LEVITATE); }
    } WHEN {
        TURN { SWITCH(opponent, 1); MOVE(player, MOVE_CORE_ENFORCER); }
        TURN { MOVE(player, MOVE_EARTHQUAKE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CORE_ENFORCER, player);
        ABILITY_POPUP(opponent, ABILITY_LEVITATE);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_EARTHQUAKE, player);
    }
}

SINGLE_BATTLE_TEST("Core Enforcer immediately ends Neutralizing Gas and reactivates suppressed abilities")
{
    GIVEN {
        PLAYER(SPECIES_TORKOAL) { Ability(ABILITY_DROUGHT); Speed(1); }
        OPPONENT(SPECIES_WEEZING) { Ability(ABILITY_NEUTRALIZING_GAS); Speed(2);}
    } WHEN {
        TURN { MOVE(player, MOVE_CORE_ENFORCER); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_NEUTRALIZING_GAS);
        MESSAGE("Neutralizing gas filled the area!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CORE_ENFORCER, player);
        MESSAGE("The effects of the neutralizing gas wore off!");
        ABILITY_POPUP(player, ABILITY_DROUGHT);
    }
}

DOUBLE_BATTLE_TEST("Core Enforcer hits both opposing targets")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_CORE_ENFORCER); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CORE_ENFORCER, playerLeft);
        HP_BAR(opponentLeft);
        HP_BAR(opponentRight);
    }
}
