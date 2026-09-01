#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Freeze has a 25% chance of being thawed (Gen9-)")
{
    PASSES_RANDOMLY(20, 100, RNG_FROZEN);
    GIVEN {
        WITH_CONFIG(B_FREEZE_TURNS, GEN_9);
        PLAYER(SPECIES_WOBBUFFET) { Status1(STATUS1_FREEZE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); }
    } SCENE {
        STATUS_ICON(player, none: TRUE);
    }
}

SINGLE_BATTLE_TEST("Freeze has a 20% chance of being thawed (Champions)")
{
    PASSES_RANDOMLY(25, 100, RNG_FROZEN);
    GIVEN {
        WITH_CONFIG(B_FREEZE_TURNS, GEN_CHAMPIONS);
        PLAYER(SPECIES_WOBBUFFET) { Status1(STATUS1_FREEZE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); }
    } SCENE {
        STATUS_ICON(player, none: TRUE);
    }
}

SINGLE_BATTLE_TEST("Freeze is thawed by opponent's Fire-type attacks (Gen 3+)")
{
    GIVEN {
        WITH_CONFIG(B_HIT_THAW, GEN_3);
        ASSUME(GetMoveType(MOVE_FIRE_SPIN) == TYPE_FIRE);
        PLAYER(SPECIES_WOBBUFFET) { Status1(STATUS1_FREEZE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_FIRE_SPIN); MOVE(player, MOVE_CELEBRATE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FIRE_SPIN, opponent);
        MESSAGE("Wobbuffet thawed out!");
        STATUS_ICON(player, none: TRUE);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
    }
}

SINGLE_BATTLE_TEST("Freeze is thawed by opponent's Fire-type attacks even if Sheer Force affected (Gen 3+)")
{
    GIVEN {
        WITH_CONFIG(B_HIT_THAW, GEN_3);
        ASSUME(GetMoveType(MOVE_EMBER) == TYPE_FIRE);
        PLAYER(SPECIES_WOBBUFFET) { Status1(STATUS1_FREEZE); }
        OPPONENT(SPECIES_TAUROS) { Ability(ABILITY_SHEER_FORCE); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_EMBER); MOVE(player, MOVE_CELEBRATE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EMBER, opponent);
        MESSAGE("Wobbuffet thawed out!");
        STATUS_ICON(player, none: TRUE);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
    }
}

SINGLE_BATTLE_TEST("Freeze is thawed by opponent's Weather Ball when it becomes Fire-type")
{
    GIVEN {
        ASSUME(GetMoveType(MOVE_WEATHER_BALL) == TYPE_NORMAL);
        ASSUME(GetMoveEffect(MOVE_WEATHER_BALL) == EFFECT_WEATHER_BALL);
        ASSUME(GetMoveEffect(MOVE_SUNNY_DAY) == EFFECT_WEATHER);
        ASSUME(GetMoveWeatherType(MOVE_SUNNY_DAY) == BATTLE_WEATHER_SUN);
        PLAYER(SPECIES_WOBBUFFET) { Status1(STATUS1_FREEZE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SUNNY_DAY); MOVE(player, MOVE_CELEBRATE, WITH_RNG(RNG_FROZEN, FALSE)); }
        TURN { MOVE(opponent, MOVE_WEATHER_BALL); MOVE(player, MOVE_CELEBRATE, WITH_RNG(RNG_FROZEN, FALSE)); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SUNNY_DAY, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_WEATHER_BALL, opponent);
        HP_BAR(player);
        MESSAGE("Wobbuffet thawed out!");
        STATUS_ICON(player, none: TRUE);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
    }
}

SINGLE_BATTLE_TEST("Freeze is thawed by opponent's attack that can burn (Gen 1-2)")
{
    GIVEN {
        WITH_CONFIG(B_HIT_THAW, GEN_2);
        ASSUME(MoveHasAdditionalEffect(MOVE_EMBER, MOVE_EFFECT_BURN));
        PLAYER(SPECIES_WOBBUFFET) { Status1(STATUS1_FREEZE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_EMBER); MOVE(player, MOVE_CELEBRATE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EMBER, opponent);
        MESSAGE("Wobbuffet thawed out!");
        STATUS_ICON(player, none: TRUE);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
    }
}

SINGLE_BATTLE_TEST("Freeze is thawed by opponent's Tri Attack 1/3 of the time (Gen 1-2)")
{
    PASSES_RANDOMLY(1, 3, RNG_RANDOM_FROM_LIST);
    GIVEN {
        WITH_CONFIG(B_HIT_THAW, GEN_2);
        ASSUME(MoveHasAdditionalEffect(MOVE_TRI_ATTACK, MOVE_EFFECT_RANDOM_FROM_LIST));
        PLAYER(SPECIES_WOBBUFFET) { Status1(STATUS1_FREEZE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_TRI_ATTACK); MOVE(player, MOVE_CELEBRATE, WITH_RNG(RNG_FROZEN, FALSE)); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TRI_ATTACK, opponent);
        MESSAGE("Wobbuffet thawed out!");
        STATUS_ICON(player, none: TRUE);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
    }
}

SINGLE_BATTLE_TEST("Freeze is thawed by opponent's attack that can thaw the user (Gen 6+)")
{
    GIVEN {
        WITH_CONFIG(B_HIT_THAW, GEN_6);
        ASSUME(MoveThawsUser(MOVE_SCALD));
        PLAYER(SPECIES_WOBBUFFET) { Status1(STATUS1_FREEZE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SCALD); MOVE(player, MOVE_CELEBRATE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCALD, opponent);
        MESSAGE("Wobbuffet thawed out!");
        STATUS_ICON(player, none: TRUE);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
    }
}

SINGLE_BATTLE_TEST("Freeze isn't thawed by opponent's attack that can thaw the user if Sheer Force affected (Gen 6+)")
{
    GIVEN {
        WITH_CONFIG(B_HIT_THAW, GEN_6);
        ASSUME(MoveThawsUser(MOVE_SCALD));
        ASSUME(MoveIsAffectedBySheerForce(MOVE_SCALD));
        PLAYER(SPECIES_WOBBUFFET) { Status1(STATUS1_FREEZE); }
        OPPONENT(SPECIES_TAUROS) { Ability(ABILITY_SHEER_FORCE); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SCALD); MOVE(player, MOVE_CELEBRATE, WITH_RNG(RNG_FROZEN, FALSE)); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCALD, opponent);
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
            MESSAGE("Wobbuffet thawed out!");
            STATUS_ICON(player, none: TRUE);
        }
    }
}

SINGLE_BATTLE_TEST("Freeze is thawed by opponent's attack that can thaw the user if not Sheer Force affected (Gen 6+)")
{
    GIVEN {
        WITH_CONFIG(B_HIT_THAW, GEN_6);
        ASSUME(MoveThawsUser(MOVE_HYDRO_STEAM));
        ASSUME(!MoveIsAffectedBySheerForce(MOVE_HYDRO_STEAM));
        PLAYER(SPECIES_WOBBUFFET) { Status1(STATUS1_FREEZE); }
        OPPONENT(SPECIES_TAUROS) { Ability(ABILITY_SHEER_FORCE); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_HYDRO_STEAM); MOVE(player, MOVE_CELEBRATE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HYDRO_STEAM, opponent);
        MESSAGE("Wobbuffet thawed out!");
        STATUS_ICON(player, none: TRUE);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
    }
}

SINGLE_BATTLE_TEST("Freeze is thawed by user's Flame Wheel")
{
    GIVEN {
        ASSUME(MoveThawsUser(MOVE_FLAME_WHEEL));
        PLAYER(SPECIES_WOBBUFFET) { Status1(STATUS1_FREEZE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_FLAME_WHEEL); }
    } SCENE {
        MESSAGE("Wobbuffet's Flame Wheel melted the ice!");
        STATUS_ICON(player, none: TRUE);
        MESSAGE("Wobbuffet used Flame Wheel!");
    }
}

SINGLE_BATTLE_TEST("Freeze isn't thawed if opponent is asleep during thawing attack (Gen9-)")
{
    PASSES_RANDOMLY(80, 100, RNG_FROZEN);
    GIVEN {
        WITH_CONFIG(B_FREEZE_TURNS, GEN_9);
        ASSUME(GetMoveType(MOVE_EMBER) == TYPE_FIRE);
        PLAYER(SPECIES_WOBBUFFET) { Status1(STATUS1_FREEZE); }
        OPPONENT(SPECIES_WOBBUFFET) { Status1(STATUS1_SLEEP); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_EMBER); MOVE(player, MOVE_CELEBRATE); }
    } SCENE {
        NONE_OF {
            MESSAGE("The opposing Wobbuffet used Ember!");
            MESSAGE("Wobbuffet thawed out!");
            STATUS_ICON(player, none: TRUE);
        }
    }
}

SINGLE_BATTLE_TEST("Freeze isn't thawed if opponent is asleep during thawing attack (Champions)")
{
    PASSES_RANDOMLY(75, 100, RNG_FROZEN);
    GIVEN {
        WITH_CONFIG(B_FREEZE_TURNS, GEN_CHAMPIONS);
        ASSUME(GetMoveType(MOVE_EMBER) == TYPE_FIRE);
        PLAYER(SPECIES_WOBBUFFET) { Status1(STATUS1_FREEZE); }
        OPPONENT(SPECIES_WOBBUFFET) { Status1(STATUS1_SLEEP); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_EMBER); MOVE(player, MOVE_CELEBRATE); }
    } SCENE {
        NONE_OF {
            MESSAGE("The opposing Wobbuffet used Ember!");
            MESSAGE("Wobbuffet thawed out!");
            STATUS_ICON(player, none: TRUE);
        }
    }
}

SINGLE_BATTLE_TEST("Freeze isn't thawed if opponent is asleep during thawing attack when using Scald (Gen9-)")
{
    PASSES_RANDOMLY(80, 100, RNG_FROZEN);
    GIVEN {
        WITH_CONFIG(B_FREEZE_TURNS, GEN_9);
        PLAYER(SPECIES_WOBBUFFET) { Status1(STATUS1_FREEZE); }
        OPPONENT(SPECIES_WOBBUFFET) { Status1(STATUS1_SLEEP); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SCALD); MOVE(player, MOVE_CELEBRATE); }
    } SCENE {
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_SCALD, opponent);
            MESSAGE("Wobbuffet thawed out!");
            STATUS_ICON(player, none: TRUE);
        }
    }
}

SINGLE_BATTLE_TEST("Freeze isn't thawed if opponent is asleep during thawing attack when using Scald (Champions)")
{
    PASSES_RANDOMLY(75, 100, RNG_FROZEN);
    GIVEN {
        WITH_CONFIG(B_FREEZE_TURNS, GEN_CHAMPIONS);
        PLAYER(SPECIES_WOBBUFFET) { Status1(STATUS1_FREEZE); }
        OPPONENT(SPECIES_WOBBUFFET) { Status1(STATUS1_SLEEP); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SCALD); MOVE(player, MOVE_CELEBRATE); }
    } SCENE {
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_SCALD, opponent);
            MESSAGE("Wobbuffet thawed out!");
            STATUS_ICON(player, none: TRUE);
        }
    }
}

SINGLE_BATTLE_TEST("Freeze has a 25% chance of being thawed (Champions)")
{
    PASSES_RANDOMLY(25, 100, RNG_FROZEN);
    GIVEN {
        WITH_CONFIG(B_FREEZE_TURNS, GEN_CHAMPIONS);
        PLAYER(SPECIES_WOBBUFFET) { Status1(STATUS1_FREEZE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); }
    } SCENE {
        STATUS_ICON(player, none: TRUE);
    }
}

SINGLE_BATTLE_TEST("Freeze has a guaranteed chance of thawing on the third turn (Champions)")
{
    PASSES_RANDOMLY(75, 100, RNG_FROZEN);
    GIVEN {
        WITH_CONFIG(B_FREEZE_TURNS, GEN_CHAMPIONS);
        PLAYER(SPECIES_WOBBUFFET) { Status1(STATUS1_FREEZE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); }
        TURN { MOVE(player, MOVE_CELEBRATE); }
        TURN { MOVE(player, MOVE_CELEBRATE); }
    } SCENE {
        MESSAGE("Wobbuffet is frozen solid!");
        MESSAGE("Wobbuffet is frozen solid!");
        STATUS_ICON(player, none: TRUE);
    }
}

SINGLE_BATTLE_TEST("Freeze timer persists even if the user switches out (Champions)")
{
    PASSES_RANDOMLY(75, 100, RNG_FROZEN);
    GIVEN {
        WITH_CONFIG(B_FREEZE_TURNS, GEN_CHAMPIONS);
        PLAYER(SPECIES_WOBBUFFET) { Status1(STATUS1_FREEZE); }
        PLAYER(SPECIES_WOBBUFFET) {};
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); }
        TURN { SWITCH(player, 1); }
        TURN { SWITCH(player, 0); }
        TURN { MOVE(player, MOVE_CELEBRATE); }
        TURN { MOVE(player, MOVE_CELEBRATE); }
    } SCENE {
        MESSAGE("Wobbuffet is frozen solid!");
        MESSAGE("Wobbuffet is frozen solid!");
        STATUS_ICON(player, none: TRUE);
    }
}
