#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveType(MOVE_THUNDER_SHOCK) == TYPE_ELECTRIC);
    ASSUME(GetMoveType(MOVE_ICE_BEAM) == TYPE_ICE);
    ASSUME(GetMoveType(MOVE_ROCK_THROW) == TYPE_ROCK);
    ASSUME(GetSpeciesType(SPECIES_PIDGEY, 0) == TYPE_FLYING || GetSpeciesType(SPECIES_PIDGEY, 1) == TYPE_FLYING);
}

DOUBLE_BATTLE_TEST("Strong winds remove Flying-type weaknesses of all battlers")
{
    enum Move move;
    PARAMETRIZE { move = MOVE_THUNDER_SHOCK; }
    PARAMETRIZE { move = MOVE_ICE_BEAM; }
    PARAMETRIZE { move = MOVE_ROCK_THROW; }

    GIVEN {
        PLAYER(SPECIES_RAYQUAZA) { Moves(MOVE_DRAGON_ASCENT, MOVE_CELEBRATE, move); }
        PLAYER(SPECIES_PIDGEY);
        OPPONENT(SPECIES_PIDGEY);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_CELEBRATE, gimmick: GIMMICK_MEGA); }
        TURN {
            MOVE(playerLeft, move, target: opponentLeft);
            MOVE(opponentRight, move, target: playerRight);
        }
    } SCENE {
        ABILITY_POPUP(playerLeft, ABILITY_DELTA_STREAM);
        ANIMATION(ANIM_TYPE_MOVE, move, playerLeft);
        EFFECTIVENESS_SE(opponentLeft, SE_EFFECTIVE);
        HP_BAR(opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, move, opponentRight);
        EFFECTIVENESS_SE(playerRight, SE_EFFECTIVE);
        HP_BAR(playerRight);
    }
}

DOUBLE_BATTLE_TEST("Strong winds remove Flying-type weaknesses of all battlers - Inverse Battle")
{
    enum Move move;
    PARAMETRIZE { move = MOVE_BUG_BITE; }
    PARAMETRIZE { move = MOVE_KARATE_CHOP; }
    PARAMETRIZE { move = MOVE_VINE_WHIP; }
    PARAMETRIZE { move = MOVE_MUD_SLAP; }

    GIVEN {
        FLAG_SET(B_FLAG_INVERSE_BATTLE);
        ASSUME(GetMoveType(MOVE_BUG_BITE) == TYPE_BUG);
        ASSUME(GetMoveType(MOVE_KARATE_CHOP) == TYPE_FIGHTING);
        ASSUME(GetMoveType(MOVE_VINE_WHIP) == TYPE_GRASS);
        ASSUME(GetMoveType(MOVE_MUD_SLAP) == TYPE_GROUND);
        ASSUME(GetSpeciesType(SPECIES_TORNADUS, 0) == TYPE_FLYING);
        ASSUME(GetSpeciesType(SPECIES_TORNADUS, 1) == TYPE_FLYING);
        PLAYER(SPECIES_RAYQUAZA) { Moves(MOVE_DRAGON_ASCENT, MOVE_CELEBRATE, move); }
        PLAYER(SPECIES_TORNADUS);
        OPPONENT(SPECIES_TORNADUS);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_CELEBRATE, gimmick: GIMMICK_MEGA); }
        TURN {
            MOVE(playerLeft, move, target: opponentLeft);
            MOVE(opponentRight, move, target: playerRight);
        }
    } SCENE {
        ABILITY_POPUP(playerLeft, ABILITY_DELTA_STREAM);
        ANIMATION(ANIM_TYPE_MOVE, move, playerLeft);
        EFFECTIVENESS_SE(opponentLeft, SE_EFFECTIVE);
        HP_BAR(opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, move, opponentRight);
        EFFECTIVENESS_SE(playerRight, SE_EFFECTIVE);
        HP_BAR(playerRight);
    }
}

SINGLE_BATTLE_TEST("Strong winds prevent Weakness Policy from activating on Flying-type weaknesses")
{
    GIVEN {
        ASSUME(GetItemHoldEffect(ITEM_WEAKNESS_POLICY) == HOLD_EFFECT_WEAKNESS_POLICY);
        PLAYER(SPECIES_RAYQUAZA) { Moves(MOVE_DRAGON_ASCENT, MOVE_CELEBRATE, MOVE_THUNDER_SHOCK); }
        OPPONENT(SPECIES_PIDGEY) { Item(ITEM_WEAKNESS_POLICY); }
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE, gimmick: GIMMICK_MEGA); }
        TURN { MOVE(player, MOVE_THUNDER_SHOCK); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_DELTA_STREAM);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_THUNDER_SHOCK, player);
        HP_BAR(opponent);
        NOT ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, opponent);
    }
}

SINGLE_BATTLE_TEST("Anticipation still triggers with Strong Winds active")
{
    GIVEN {
        ASSUME(GetSpeciesType(SPECIES_RAYQUAZA_MEGA, 0) == TYPE_DRAGON);
        ASSUME(GetSpeciesType(SPECIES_RAYQUAZA_MEGA, 1) == TYPE_FLYING);
        ASSUME(GetMoveEffect(MOVE_SKILL_SWAP) == EFFECT_SKILL_SWAP);
        PLAYER(SPECIES_RAYQUAZA) { Moves(MOVE_DRAGON_ASCENT, MOVE_CELEBRATE); }
        OPPONENT(SPECIES_EEVEE) { Ability(ABILITY_ANTICIPATION); Moves(MOVE_ROCK_THROW, MOVE_SKILL_SWAP); }
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE, gimmick: GIMMICK_MEGA); MOVE(opponent, MOVE_SKILL_SWAP); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_DELTA_STREAM);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SKILL_SWAP, opponent);
        ABILITY_POPUP(player, ABILITY_ANTICIPATION);
    }
}

SINGLE_BATTLE_TEST("Anticipation still triggers with Strong Winds active - Inverse Battle")
{
    GIVEN {
        FLAG_SET(B_FLAG_INVERSE_BATTLE);
        ASSUME(GetMoveType(MOVE_BUG_BITE) == TYPE_BUG);
        ASSUME(GetSpeciesType(SPECIES_RAYQUAZA_MEGA, 0) == TYPE_DRAGON);
        ASSUME(GetSpeciesType(SPECIES_RAYQUAZA_MEGA, 1) == TYPE_FLYING);
        ASSUME(GetMoveEffect(MOVE_SKILL_SWAP) == EFFECT_SKILL_SWAP);
        PLAYER(SPECIES_RAYQUAZA) { Moves(MOVE_DRAGON_ASCENT, MOVE_CELEBRATE); }
        OPPONENT(SPECIES_EEVEE) { Ability(ABILITY_ANTICIPATION); Moves(MOVE_BUG_BITE, MOVE_SKILL_SWAP); }
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE, gimmick: GIMMICK_MEGA); MOVE(opponent, MOVE_SKILL_SWAP); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_DELTA_STREAM);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SKILL_SWAP, opponent);
        ABILITY_POPUP(player, ABILITY_ANTICIPATION);
    }
}

SINGLE_BATTLE_TEST("Strong winds don't affect Stealth Rock's damage")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_STEALTH_ROCK) == EFFECT_STEALTH_ROCK);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_PIDGEY){ HP(200); MaxHP(200); }
        OPPONENT(SPECIES_RAYQUAZA) { Moves(MOVE_DRAGON_ASCENT, MOVE_CELEBRATE, MOVE_STEALTH_ROCK); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_CELEBRATE, gimmick: GIMMICK_MEGA); }
        TURN { MOVE(opponent, MOVE_STEALTH_ROCK); }
        TURN { SWITCH(player, 1); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_DELTA_STREAM);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STEALTH_ROCK, opponent);
        HP_BAR(player, damage: 50);
    }
}

SINGLE_BATTLE_TEST("Strong winds block weather-setting moves")
{
    enum Move move;
    PARAMETRIZE { move = MOVE_SUNNY_DAY; }
    PARAMETRIZE { move = MOVE_RAIN_DANCE; }
    PARAMETRIZE { move = MOVE_SANDSTORM; }
    PARAMETRIZE { move = MOVE_HAIL; }
    PARAMETRIZE { move = MOVE_SNOWSCAPE; }

    GIVEN {
        ASSUME(GetMoveEffect(move) == EFFECT_WEATHER);
        ASSUME(GetMoveWeatherType(MOVE_SUNNY_DAY) == BATTLE_WEATHER_SUN);
        ASSUME(GetMoveWeatherType(MOVE_RAIN_DANCE) == BATTLE_WEATHER_RAIN);
        ASSUME(GetMoveWeatherType(MOVE_SANDSTORM) == BATTLE_WEATHER_SANDSTORM);
        ASSUME(GetMoveWeatherType(MOVE_HAIL) == BATTLE_WEATHER_HAIL);
        ASSUME(GetMoveWeatherType(MOVE_SNOWSCAPE) == BATTLE_WEATHER_SNOW);
        PLAYER(SPECIES_RAYQUAZA) { Moves(MOVE_DRAGON_ASCENT, MOVE_CELEBRATE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE, gimmick: GIMMICK_MEGA); }
        TURN { MOVE(opponent, move); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_DELTA_STREAM);
        NOT ANIMATION(ANIM_TYPE_MOVE, move, opponent);
    } THEN {
        EXPECT(gBattleWeather & B_WEATHER_STRONG_WINDS);
    }
}

SINGLE_BATTLE_TEST("Strong winds prevent other weather abilities")
{
    enum Ability ability;
    enum Species species;
    PARAMETRIZE { ability = ABILITY_DROUGHT;      species = SPECIES_NINETALES; }
    PARAMETRIZE { ability = ABILITY_DRIZZLE;      species = SPECIES_POLITOED; }
    PARAMETRIZE { ability = ABILITY_SAND_STREAM;  species = SPECIES_HIPPOWDON; }
    PARAMETRIZE { ability = ABILITY_SNOW_WARNING; species = SPECIES_ABOMASNOW; }

    GIVEN {
        PLAYER(SPECIES_RAYQUAZA) { Moves(MOVE_DRAGON_ASCENT, MOVE_CELEBRATE); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(species) { Ability(ability); }
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE, gimmick: GIMMICK_MEGA); }
        TURN { SWITCH(opponent, 1); }
    } SCENE {
        ABILITY_POPUP(opponent, ability);
    } THEN {
        EXPECT(gBattleWeather & B_WEATHER_STRONG_WINDS);
    }
}

SINGLE_BATTLE_TEST("Strong winds can be replaced by Desolate Land")
{
    GIVEN {
        PLAYER(SPECIES_RAYQUAZA) { Moves(MOVE_DRAGON_ASCENT, MOVE_CELEBRATE); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_GROUDON) { Item(ITEM_RED_ORB); }
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE, gimmick: GIMMICK_MEGA); }
        TURN { SWITCH(opponent, 1); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_DESOLATE_LAND);
        MESSAGE("The sunlight turned extremely harsh!");
    } THEN {
        EXPECT(gBattleWeather & B_WEATHER_SUN_PRIMAL);
    }
}

SINGLE_BATTLE_TEST("Strong winds can be replaced by Primordial Sea")
{
    GIVEN {
        PLAYER(SPECIES_RAYQUAZA) { Moves(MOVE_DRAGON_ASCENT, MOVE_CELEBRATE); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_KYOGRE) { Item(ITEM_BLUE_ORB); }
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE, gimmick: GIMMICK_MEGA); }
        TURN { SWITCH(opponent, 1); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_PRIMORDIAL_SEA);
        MESSAGE("A heavy rain began to fall!");
    } THEN {
        EXPECT(gBattleWeather & B_WEATHER_RAIN_PRIMAL);
    }
}

SINGLE_BATTLE_TEST("Strong winds don't reduce Synthesis, Morning Sun or Moonlight recovery")
{
    enum Move move;
    enum BattleMoveEffects effect;
    PARAMETRIZE { move = MOVE_SYNTHESIS;   effect = EFFECT_SYNTHESIS; }
    PARAMETRIZE { move = MOVE_MORNING_SUN; effect = EFFECT_MORNING_SUN; }
    PARAMETRIZE { move = MOVE_MOONLIGHT;   effect = EFFECT_MOONLIGHT; }

    GIVEN {
        ASSUME(GetMoveEffect(move) == effect);
        PLAYER(SPECIES_RAYQUAZA) { HP(1); MaxHP(200); Moves(MOVE_DRAGON_ASCENT, MOVE_CELEBRATE, move); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE, gimmick: GIMMICK_MEGA); }
        TURN { MOVE(player, move); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_DELTA_STREAM);
        HP_BAR(player, damage: -100);
    }
}
