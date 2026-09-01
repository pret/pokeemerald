#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_TAUNT) == EFFECT_TAUNT);
}

SINGLE_BATTLE_TEST("Taunt lasts for 2 turns (Gen 3)")
{
    GIVEN {
        WITH_CONFIG(B_TAUNT_TURNS, GEN_3);
        PLAYER(SPECIES_WOBBUFFET) { Speed(2); Moves(MOVE_GROWL, MOVE_TACKLE); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(1); Moves(MOVE_TAUNT, MOVE_CELEBRATE); }
    } WHEN {
        TURN { MOVE(player, MOVE_GROWL); MOVE(opponent, MOVE_TAUNT); }
        TURN { MOVE(player, MOVE_GROWL, allowed: FALSE); MOVE(player, MOVE_TACKLE); MOVE(opponent, MOVE_CELEBRATE); }
        TURN { MOVE(player, MOVE_GROWL); MOVE(opponent, MOVE_CELEBRATE); }
    }
}

// NOTE: AI test is required to validate RNG range without MOVE/FORCED_MOVE invalids; there may be a better approach.
AI_SINGLE_BATTLE_TEST("Taunt lasts for 3-5 turns (Gen 4)")
{
    u32 count, turns;

    PARAMETRIZE { turns = 3; }
    PARAMETRIZE { turns = 4; }
    PARAMETRIZE { turns = 5; }
    PASSES_RANDOMLY(1, 3, RNG_TAUNT_TURNS);
    GIVEN {
        WITH_CONFIG(B_TAUNT_TURNS, GEN_4);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(SPECIES_WOBBUFFET) { Speed(1); Moves(MOVE_TAUNT, MOVE_CELEBRATE); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(2); Moves(MOVE_GROWL, MOVE_TACKLE); }
    } WHEN {
        TURN { MOVE(player, MOVE_TAUNT); }
        for (count = 0; count < turns - 1; ++count)
            TURN { MOVE(player, MOVE_CELEBRATE); }
        TURN { MOVE(player, MOVE_CELEBRATE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TAUNT, player);
        for (count = 0; count < turns - 1; ++count)
        {
            NOT MESSAGE("The opposing Wobbuffet's Taunt wore off!");
            ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
        }
        MESSAGE("The opposing Wobbuffet's Taunt wore off!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
    }
}

SINGLE_BATTLE_TEST("Taunt lasts for 3 turns if target hasn't moved (Gen 5+)")
{
    u32 count;

    GIVEN {
        WITH_CONFIG(B_TAUNT_TURNS, GEN_5);
        PLAYER(SPECIES_WOBBUFFET) { Speed(1); Moves(MOVE_GROWL, MOVE_TACKLE); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(2); Moves(MOVE_TAUNT, MOVE_CELEBRATE); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_TAUNT); MOVE(player, MOVE_GROWL); }
        for (count = 0; count < 2; ++count)
            TURN { MOVE(player, MOVE_GROWL, allowed: FALSE); MOVE(player, MOVE_TACKLE); MOVE(opponent, MOVE_CELEBRATE); }
        TURN { MOVE(player, MOVE_GROWL); MOVE(opponent, MOVE_CELEBRATE); }
    }
}

SINGLE_BATTLE_TEST("Taunt lasts for 4 turns if target already moved (Gen 5+)")
{
    u32 count;

    GIVEN {
        WITH_CONFIG(B_TAUNT_TURNS, GEN_5);
        PLAYER(SPECIES_WOBBUFFET) { Speed(2); Moves(MOVE_GROWL, MOVE_TACKLE); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(1); Moves(MOVE_TAUNT, MOVE_CELEBRATE); }
    } WHEN {
        TURN { MOVE(player, MOVE_GROWL); MOVE(opponent, MOVE_TAUNT); }
        for (count = 0; count < 3; ++count)
            TURN { MOVE(player, MOVE_GROWL, allowed: FALSE); MOVE(player, MOVE_TACKLE); MOVE(opponent, MOVE_CELEBRATE); }
        TURN { MOVE(player, MOVE_GROWL); MOVE(opponent, MOVE_CELEBRATE); }
    }
}
