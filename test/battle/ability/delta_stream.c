#include "global.h"
#include "test/battle.h"

// Effects of strong winds are handled in test/battle/weather/strong_winds.c

//TO_DO_BATTLE_TEST("Delta Stream doesn't activate if is sent-out in a rotated-out position (Rotation)")
//TO_DO_BATTLE_TEST("Delta Stream doesn't activate if is rotated-in (Rotation)")
DOUBLE_BATTLE_TEST("Delta Stream doesn't activate if there's already strong winds")
{
    GIVEN {
        PLAYER(SPECIES_RAYQUAZA) { Moves(MOVE_DRAGON_ASCENT, MOVE_CELEBRATE); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_RAYQUAZA) { Moves(MOVE_DRAGON_ASCENT, MOVE_CELEBRATE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {
            MOVE(opponentLeft, MOVE_CELEBRATE, gimmick: GIMMICK_MEGA);
            MOVE(playerLeft, MOVE_CELEBRATE, gimmick: GIMMICK_MEGA);
        }
    } SCENE {
        ABILITY_POPUP(opponentLeft, ABILITY_DELTA_STREAM);
        MESSAGE("Mysterious strong winds are protecting Flying-type Pokémon!");
        NONE_OF {
            ABILITY_POPUP(playerLeft, ABILITY_DELTA_STREAM);
            MESSAGE("Mysterious strong winds are protecting Flying-type Pokémon!");
        }
    }
}

DOUBLE_BATTLE_TEST("Strong winds continue as long as there's a Pokémon with Delta Stream on the field")
{
    GIVEN {
        PLAYER(SPECIES_RAYQUAZA) { HP(1); Speed(5); Moves(MOVE_DRAGON_ASCENT, MOVE_CELEBRATE); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(4); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(3); }
        OPPONENT(SPECIES_RAYQUAZA) { Speed(2); Moves(MOVE_DRAGON_ASCENT, MOVE_CELEBRATE, MOVE_SCRATCH); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(1); }
    } WHEN {
        TURN {
            MOVE(playerLeft, MOVE_CELEBRATE, gimmick: GIMMICK_MEGA);
            MOVE(opponentLeft, MOVE_CELEBRATE, gimmick: GIMMICK_MEGA);
        }
        TURN { MOVE(opponentLeft, MOVE_SCRATCH, target: playerLeft); SEND_OUT(playerLeft, 2); }
    } SCENE {
        ABILITY_POPUP(playerLeft, ABILITY_DELTA_STREAM);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponentLeft);
        HP_BAR(playerLeft);
        NOT MESSAGE("The mysterious strong winds have dissipated!");
    } THEN {
        EXPECT(gBattleWeather & B_WEATHER_STRONG_WINDS);
    }
}

SINGLE_BATTLE_TEST("Delta Stream fails if overworld weather is present (Gen9)")
{
    SetStartingStatus(STARTING_STATUS_WEATHER_SUN);

    GIVEN {
        PLAYER(SPECIES_RAYQUAZA) { Moves(MOVE_DRAGON_ASCENT, MOVE_CELEBRATE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE, gimmick: GIMMICK_MEGA); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_DELTA_STREAM);
        MESSAGE("But it failed!");
    } THEN {
        EXPECT(gBattleWeather & B_WEATHER_SUN);
        ResetStartingStatuses();
    }
}
