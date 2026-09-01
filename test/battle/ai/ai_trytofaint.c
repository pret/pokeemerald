#include "global.h"
#include "test/battle.h"
#include "battle_ai_util.h"

AI_SINGLE_BATTLE_TEST("AI prefers priority moves if it's slower and can kill target")
{
    GIVEN {
        ASSUME(GetMovePriority(MOVE_QUICK_ATTACK) == 1);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(SPECIES_WOBBUFFET) { HP(1); Speed(100); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(100); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(1); Moves(MOVE_QUICK_ATTACK, MOVE_STRENGTH); }
    } WHEN {
        TURN { EXPECT_MOVE(opponent, MOVE_QUICK_ATTACK); SEND_OUT(player, 1); }
    } SCENE {
        MESSAGE("Wobbuffet fainted!");
    }
}

AI_SINGLE_BATTLE_TEST("AI will choose a random move if it's faster and can kill target")
{
    GIVEN {
        ASSUME(GetMovePriority(MOVE_QUICK_ATTACK) == 1);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(SPECIES_WOBBUFFET) { HP(1); Speed(1); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(1); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(100); Moves(MOVE_QUICK_ATTACK, MOVE_STRENGTH); }
    } WHEN {
        TURN { EXPECT_MOVES(opponent, MOVE_QUICK_ATTACK, MOVE_STRENGTH); SEND_OUT(player, 1); }
    } SCENE {
        MESSAGE("Wobbuffet fainted!");
    }
}

AI_SINGLE_BATTLE_TEST("AI will choose a priority move if it is slower then the target and will be killed")
{
    GIVEN {
        ASSUME(GetMovePriority(MOVE_QUICK_ATTACK) == 1);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(SPECIES_WOBBUFFET) { Speed(100); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(60); Speed(1); Moves(MOVE_QUICK_ATTACK, MOVE_STRENGTH); }
    } WHEN {
        TURN { MOVE(player, MOVE_STRENGTH); EXPECT_MOVE(opponent, MOVE_STRENGTH); }
        TURN { MOVE(player, MOVE_STRENGTH); EXPECT_MOVE(opponent, MOVE_QUICK_ATTACK); }
    } SCENE {
        MESSAGE("The opposing Wobbuffet fainted!");
    }
}

AI_SINGLE_BATTLE_TEST("AI sees Loaded Dice damage increase from multi hit moves")
{
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(SPECIES_WOBBUFFET) { HP(44); }
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_LOADED_DICE); Moves(MOVE_SEED_BOMB, MOVE_BULLET_SEED); }
    } WHEN {
        TURN { EXPECT_MOVE(opponent, MOVE_BULLET_SEED); }
    } SCENE {
        MESSAGE("Wobbuffet fainted!");
    }
}

AI_SINGLE_BATTLE_TEST("AI sees Parental Bond killing through sturdy")
{
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY);
        PLAYER(SPECIES_MAGNEZONE){ Level(64); Ability(ABILITY_STURDY); Moves(MOVE_TACKLE, MOVE_LIGHT_SCREEN); }
        OPPONENT(SPECIES_KANGASKHAN_MEGA){ Level(64); Moves(MOVE_DRAIN_PUNCH, MOVE_TAUNT); }
    } WHEN {
        TURN {
            MOVE(player, MOVE_TACKLE);
            EXPECT_MOVE(opponent, MOVE_DRAIN_PUNCH); // AI should see drain punch as a kill due to multi hit, outscoring taunt
        }
    }
}

