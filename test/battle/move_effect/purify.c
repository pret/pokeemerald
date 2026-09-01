#include "global.h"
#include "test/battle.h"

AI_DOUBLE_BATTLE_TEST("AI uses Purify")
{
    u32 status1;

    PARAMETRIZE { status1 = STATUS1_NONE; }
    PARAMETRIZE { status1 = STATUS1_FREEZE; }

    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_HEADBUTT, MOVE_PURIFY); }
        OPPONENT(SPECIES_WOBBUFFET) { Status1(status1); Moves(MOVE_HEADBUTT); }
    } WHEN {
        if (status1 == STATUS1_NONE)
            TURN { NOT_EXPECT_MOVE(opponentLeft, MOVE_PURIFY); }
        else
            TURN { EXPECT_MOVE(opponentLeft, MOVE_PURIFY, target: opponentRight); }
    }
}

AI_SINGLE_BATTLE_TEST("AI uses Purify to heal an enemy with Guts")
{
    enum Ability ability;

    PARAMETRIZE { ability = ABILITY_GUTS; }
    PARAMETRIZE { ability = ABILITY_BULLETPROOF; }

    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY | AI_FLAG_OMNISCIENT);
        PLAYER(SPECIES_URSALUNA) { Ability(ability); Moves(MOVE_HEADLONG_RUSH, MOVE_CELEBRATE); Status1(STATUS1_BURN); }
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_HEADBUTT, MOVE_PURIFY); }
    } WHEN {
        if (ability == ABILITY_GUTS)
            TURN { EXPECT_MOVE(opponent, MOVE_PURIFY); }
        else
            TURN { NOT_EXPECT_MOVE(opponent, MOVE_PURIFY); }
    }
}

AI_DOUBLE_BATTLE_TEST("AI does not use Purify to heal an ally with Guts")
{
    enum Ability ability;

    PARAMETRIZE { ability = ABILITY_GUTS; }
    PARAMETRIZE { ability = ABILITY_BULLETPROOF; }

    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY | AI_FLAG_OMNISCIENT);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_HEADBUTT, MOVE_PURIFY); }
        OPPONENT(SPECIES_URSALUNA) { Ability(ability); Moves(MOVE_HEADLONG_RUSH); Status1(STATUS1_BURN); }
    } WHEN {
        if (ability == ABILITY_GUTS)
            TURN { NOT_EXPECT_MOVE(opponentLeft, MOVE_PURIFY); }
        else
            TURN { EXPECT_MOVE(opponentLeft, MOVE_PURIFY, target: opponentRight); }
    }
}

SINGLE_BATTLE_TEST("Purify cures the target's status and heals the user")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_PURIFY) == EFFECT_PURIFY);
        PLAYER(SPECIES_WOBBUFFET) { HP(50); MaxHP(100); }
        OPPONENT(SPECIES_WOBBUFFET) { Status1(STATUS1_BURN); }
    } WHEN {
        TURN { MOVE(player, MOVE_PURIFY); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PURIFY, player);
        STATUS_ICON(opponent, none: TRUE);
        HP_BAR(player);
    } THEN {
        EXPECT_EQ(player->hp, player->maxHP);
        EXPECT_EQ(opponent->status1, STATUS1_NONE);
    }
}

SINGLE_BATTLE_TEST("Purify doesn't heal HP if the target has Comatose")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_PURIFY) == EFFECT_PURIFY);
        PLAYER(SPECIES_WOBBUFFET) { HP(50); MaxHP(100); }
        OPPONENT(SPECIES_KOMALA) { Ability(ABILITY_COMATOSE); }
    } WHEN {
        TURN { MOVE(player, MOVE_PURIFY); }
    } SCENE {
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_PURIFY, player);
        MESSAGE("But it failed!");
        NOT HP_BAR(player);
    } THEN {
        EXPECT_EQ(player->hp, 50);
    }
}
