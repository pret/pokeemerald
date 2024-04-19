#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gMovesInfo[MOVE_TIDY_UP].effect == EFFECT_TIDY_UP);
}

SINGLE_BATTLE_TEST("Tidy Up raises Attack and Speed by one")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_TIDY_UP); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TIDY_UP, player);
        NOT MESSAGE("Tidying up complete!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        MESSAGE("Wobbuffet's Attack rose!");
        MESSAGE("Wobbuffet's Speed rose!");
    } THEN {
        EXPECT_EQ(player->statStages[STAT_ATK], DEFAULT_STAT_STAGE + 1);
        EXPECT_EQ(player->statStages[STAT_SPEED], DEFAULT_STAT_STAGE + 1);
    }
}

SINGLE_BATTLE_TEST("Tidy Up removes hazards and raises Stats")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SPIKES); }
        TURN { MOVE(opponent, MOVE_STEALTH_ROCK); }
        TURN { MOVE(opponent, MOVE_TOXIC_SPIKES); }
        TURN { MOVE(opponent, MOVE_STICKY_WEB); MOVE(player, MOVE_TIDY_UP); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPIKES, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STEALTH_ROCK, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TOXIC_SPIKES, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STICKY_WEB, opponent);
        MESSAGE("Wobbuffet used Tidy Up!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TIDY_UP, player);
        MESSAGE("The spikes disappeared from the ground around your team!");
        MESSAGE("The pointed stones disappeared from around your team!");
        MESSAGE("The poison spikes disappeared from the ground around your team!");
        MESSAGE("The sticky web has disappeared from the ground around your team!");
        MESSAGE("Tidying up complete!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        MESSAGE("Wobbuffet's Attack rose!");
        MESSAGE("Wobbuffet's Speed rose!");
    }
}

SINGLE_BATTLE_TEST("Tidy Up removes Substitute")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SUBSTITUTE); MOVE(player, MOVE_TIDY_UP); }
    } SCENE {
        MESSAGE("Foe Wobbuffet used Substitute!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SUBSTITUTE, opponent);
        MESSAGE("Foe Wobbuffet made a SUBSTITUTE!");
        MESSAGE("Wobbuffet used Tidy Up!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TIDY_UP, player);
        MESSAGE("Foe Wobbuffet's SUBSTITUTE faded!");
        MESSAGE("Tidying up complete!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        MESSAGE("Wobbuffet's Attack rose!");
        MESSAGE("Wobbuffet's Speed rose!");
    }
}

AI_SINGLE_BATTLE_TEST("AI prefers to keep it's substitute over removing hazards if target is slower")
{
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(SPECIES_WOBBUFFET) { Speed(50); Status1(STATUS1_PARALYSIS); Moves(MOVE_SLEEP_POWDER, MOVE_STEALTH_ROCK, MOVE_CELEBRATE); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(100); Moves(MOVE_BITE, MOVE_TACKLE, MOVE_SUBSTITUTE, MOVE_TIDY_UP); }
    } WHEN {
        TURN { MOVE(player, MOVE_STEALTH_ROCK); EXPECT_MOVE(opponent, MOVE_SUBSTITUTE); }
        TURN { EXPECT_MOVE(opponent, MOVE_BITE); }
    }
}

AI_SINGLE_BATTLE_TEST("AI will try to remove hazards if slower then target even with a Substitute because it expects the Sub to be broken")
{
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(SPECIES_WOBBUFFET) { Speed(100); Status1(STATUS1_BURN); Moves(MOVE_SLEEP_POWDER, MOVE_STEALTH_ROCK, MOVE_CELEBRATE); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(50); Moves(MOVE_BITE, MOVE_TACKLE, MOVE_SUBSTITUTE, MOVE_TIDY_UP); }
    } WHEN {
        TURN { MOVE(player, MOVE_STEALTH_ROCK); EXPECT_MOVE(opponent, MOVE_SUBSTITUTE); }
        TURN { EXPECT_MOVE(opponent, MOVE_TIDY_UP); }
    }
}
