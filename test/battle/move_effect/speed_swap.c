#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_SPEED_SWAP) == EFFECT_SPEED_SWAP);
}

SINGLE_BATTLE_TEST("Speed Swap swaps user and target's speed stats")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(6); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(10); }
    }WHEN {
        TURN { MOVE(opponent, MOVE_SCRATCH); MOVE(player, MOVE_SPEED_SWAP); }
        TURN { MOVE(opponent, MOVE_SCRATCH); MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        // Turn 1
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPEED_SWAP, player);
        // Turn 2
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
    } THEN {
        EXPECT_EQ(player->speed, 10);
        EXPECT_EQ(opponent->speed, 6);
    }
}

SINGLE_BATTLE_TEST("Speed Swap doesn't swap user and target's speed modifiers")
{
    enum Species species;
    enum Move move;
    enum Ability ability;
    PARAMETRIZE { species = SPECIES_WOBBUFFET; ability = ABILITY_TELEPATHY;  move = MOVE_ROCK_POLISH; } // x2.0
    PARAMETRIZE { species = SPECIES_PSYDUCK;   ability = ABILITY_SWIFT_SWIM; move = MOVE_RAIN_DANCE;  } // x2.0
    GIVEN {
        ASSUME_STAT_CHANGE(MOVE_ROCK_POLISH, speed: +2);
        ASSUME(GetMoveEffect(MOVE_RAIN_DANCE) == EFFECT_WEATHER);
        ASSUME(GetMoveWeatherType(MOVE_RAIN_DANCE) == BATTLE_WEATHER_RAIN);
        PLAYER(SPECIES_WOBBUFFET) { Speed(8); }
        OPPONENT(species) { Speed(10); Ability(ability); }
    } WHEN {
        TURN { MOVE(opponent, move); MOVE(player, MOVE_SPEED_SWAP); }
        TURN { MOVE(opponent, MOVE_SCRATCH); MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        // Turn 1
        ANIMATION(ANIM_TYPE_MOVE, move, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPEED_SWAP, player);
        // Turn 2
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent); // Opponent is still first
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
    } THEN {
        EXPECT_EQ(player->speed, 10);
        EXPECT_EQ(opponent->speed, 8);
        if (move == MOVE_ROCK_POLISH) {
            EXPECT_EQ(player->statStages[STAT_SPEED], DEFAULT_STAT_STAGE);
            EXPECT_EQ(opponent->statStages[STAT_SPEED], DEFAULT_STAT_STAGE + 2);
        }
    }
}

SINGLE_BATTLE_TEST("Speed Swap doesn't get overwritten upon Mega Evolution (Champions)")
{
    GIVEN {
        WITH_CONFIG(B_MEGA_EVO_SPEED_SWAP, GEN_CHAMPIONS);
        PLAYER(SPECIES_CAMERUPT) { Item(ITEM_CAMERUPTITE); }
        OPPONENT(SPECIES_PHEROMOSA) {};
    } WHEN {
        TURN { MOVE(opponent, MOVE_SPEED_SWAP); MOVE(player, MOVE_CELEBRATE); }
        TURN { MOVE(opponent, MOVE_SCRATCH); MOVE(player, MOVE_SCRATCH, gimmick: GIMMICK_MEGA); }
    } SCENE {
        // Turn 1
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPEED_SWAP, opponent);
        // Turn 2
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
    }
}
