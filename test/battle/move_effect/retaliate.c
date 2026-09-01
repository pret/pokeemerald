#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_RETALIATE) == EFFECT_RETALIATE);
}

SINGLE_BATTLE_TEST("Retaliate doubles in base power the turn after an ally faints")
{
    s16 damage[2];
    GIVEN {
        PLAYER(SPECIES_WYNAUT) { HP(1); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SCRATCH); SEND_OUT(player, 1); }
        TURN { MOVE(player, MOVE_RETALIATE); }
        TURN { MOVE(player, MOVE_RETALIATE); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &damage[0]);
        HP_BAR(opponent, captureDamage: &damage[1]);
    } THEN {
        EXPECT_MUL_EQ(damage[1], Q_4_12(2.0), damage[0]);
    }
}

SINGLE_BATTLE_TEST("Retaliate doubles in base power the turn after an ally faints (opponent)")
{
    s16 damage[2];
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT) { HP(1); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); SEND_OUT(opponent, 1); }
        TURN { MOVE(opponent, MOVE_RETALIATE); }
        TURN { MOVE(opponent, MOVE_RETALIATE); }
    } SCENE {
        HP_BAR(player, captureDamage: &damage[0]);
        HP_BAR(player, captureDamage: &damage[1]);
    } THEN {
        EXPECT_MUL_EQ(damage[1], Q_4_12(2.0), damage[0]);
    }
}

DOUBLE_BATTLE_TEST("Retaliate works with passive damage")
{
    s16 damage[2];
    enum Move move;
    enum Move move2 = MOVE_CELEBRATE;
    struct BattlePokemon *moveTarget = playerLeft;
    PARAMETRIZE { move = MOVE_TOXIC; moveTarget = playerLeft; }
    PARAMETRIZE { move = MOVE_POISON_POWDER; moveTarget = playerLeft; }
    PARAMETRIZE { move = MOVE_WILL_O_WISP; moveTarget = playerLeft; }
    #if B_USE_FROSTBITE == TRUE
    PARAMETRIZE { move = MOVE_ICE_BEAM; moveTarget = playerLeft; }
    #endif
    PARAMETRIZE { move = MOVE_SANDSTORM; moveTarget = playerLeft; }
    PARAMETRIZE { move = MOVE_HAIL; moveTarget = playerLeft; }
    PARAMETRIZE { move = MOVE_LEECH_SEED; moveTarget = playerLeft; }
    PARAMETRIZE { move = MOVE_MAGMA_STORM; moveTarget = playerLeft; }
    PARAMETRIZE { move = MOVE_FLAME_BURST; moveTarget = playerRight; }
    PARAMETRIZE { move = MOVE_FIRE_PLEDGE; moveTarget = playerRight; move2 = MOVE_GRASS_PLEDGE; }
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_TOXIC) == EFFECT_NON_VOLATILE_STATUS);
        ASSUME(GetMoveNonVolatileStatus(MOVE_TOXIC) == MOVE_EFFECT_TOXIC);
        ASSUME(GetMoveEffect(MOVE_POISON_POWDER) == EFFECT_NON_VOLATILE_STATUS);
        ASSUME(GetMoveNonVolatileStatus(MOVE_POISON_POWDER) == MOVE_EFFECT_POISON);
        ASSUME(GetMoveEffect(MOVE_WILL_O_WISP) == EFFECT_NON_VOLATILE_STATUS);
        ASSUME(GetMoveNonVolatileStatus(MOVE_WILL_O_WISP) == MOVE_EFFECT_BURN);
        #if B_USE_FROSTBITE == TRUE
        ASSUME(GetMoveAdditionalEffectById(MOVE_ICE_BEAM, 0)->moveEffect == MOVE_EFFECT_FREEZE_OR_FROSTBITE);
        #endif

        ASSUME(GetMoveEffect(MOVE_SANDSTORM) == EFFECT_WEATHER);
        ASSUME(GetMoveWeatherType(MOVE_SANDSTORM) == BATTLE_WEATHER_SANDSTORM);
        ASSUME(GetMoveEffect(MOVE_HAIL) == EFFECT_WEATHER);
        ASSUME(GetMoveWeatherType(MOVE_HAIL) == BATTLE_WEATHER_HAIL);
        ASSUME(GetMoveEffect(MOVE_LEECH_SEED) == EFFECT_LEECH_SEED);
        ASSUME(GetMoveAdditionalEffectById(MOVE_MAGMA_STORM, 0)->moveEffect == MOVE_EFFECT_WRAP);
        ASSUME(GetMoveAdditionalEffectById(MOVE_FLAME_BURST, 0)->moveEffect == MOVE_EFFECT_FLAME_BURST);
        PLAYER(SPECIES_WYNAUT) { Ability(ABILITY_SHADOW_TAG); HP(18); }
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_SHADOW_TAG); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_CLEFABLE) { Ability(ABILITY_MAGIC_GUARD); Level(1); }
        OPPONENT(SPECIES_CLEFABLE) { Ability(ABILITY_MAGIC_GUARD); }
    } WHEN {
        TURN { MOVE(opponentRight, move2, target: moveTarget); MOVE(opponentLeft, move, target: moveTarget); MOVE(playerLeft, MOVE_CELEBRATE); SEND_OUT(playerLeft, 2); }
        TURN { MOVE(opponentRight, MOVE_CELEBRATE, target: moveTarget); MOVE(playerLeft, MOVE_RETALIATE, target: opponentRight); }
        TURN { MOVE(opponentRight, MOVE_CELEBRATE, target: moveTarget); MOVE(playerLeft, MOVE_RETALIATE, target: opponentRight); }
    } SCENE {
        if (move != MOVE_FLAME_BURST)
            MESSAGE("Wynaut used Celebrate!");
        HP_BAR(opponentRight, captureDamage: &damage[0]);
        HP_BAR(opponentRight, captureDamage: &damage[1]);
    } THEN {
        EXPECT_MUL_EQ(damage[1], Q_4_12(2.0), damage[0]);
    }
}

SINGLE_BATTLE_TEST("Retaliate works with Perish Song")
{
    s16 damage[2];
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_PERISH_SONG) == EFFECT_PERISH_SONG);
        PLAYER(SPECIES_WYNAUT);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_PERISH_SONG); }
        TURN { MOVE(opponent, MOVE_CELEBRATE); }
        TURN { MOVE(opponent, MOVE_CELEBRATE); }
        TURN { MOVE(opponent, MOVE_CELEBRATE); SEND_OUT(opponent, 1); SEND_OUT(player, 1); }
        TURN { MOVE(player, MOVE_RETALIATE); }
        TURN { MOVE(player, MOVE_RETALIATE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PERISH_SONG, opponent);
        HP_BAR(opponent);
        HP_BAR(player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_RETALIATE, player);
        HP_BAR(opponent, captureDamage: &damage[0]);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_RETALIATE, player);
        HP_BAR(opponent, captureDamage: &damage[1]);
    } THEN {
        EXPECT_MUL_EQ(damage[1], Q_4_12(2.0), damage[0]);
    }
}

SINGLE_BATTLE_TEST("Retaliate works with Perish Song (Gen3 Perish Song)")
{
    s16 damage[2];
    GIVEN {
        WITH_CONFIG(B_CHECK_USER_FAILURE, GEN_3);
        ASSUME(GetMoveEffect(MOVE_PERISH_SONG) == EFFECT_PERISH_SONG);
        PLAYER(SPECIES_WYNAUT);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_KOMMO_O) { Ability(ABILITY_SOUNDPROOF); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_PERISH_SONG); }
        TURN { MOVE(opponent, MOVE_CELEBRATE); }
        TURN { MOVE(opponent, MOVE_CELEBRATE); }
        TURN { MOVE(opponent, MOVE_CELEBRATE); SEND_OUT(player, 1); }
        TURN { MOVE(player, MOVE_RETALIATE); }
        TURN { MOVE(player, MOVE_RETALIATE); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &damage[0]);
        HP_BAR(opponent, captureDamage: &damage[1]);
    } THEN {
        EXPECT_MUL_EQ(damage[1], Q_4_12(2.0), damage[0]);
    }
}
SINGLE_BATTLE_TEST("Retaliate works with self-inflicted fainting")
{
    s16 damage[2];
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_HEALING_WISH) == EFFECT_HEALING_WISH);
        PLAYER(SPECIES_WYNAUT);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_HEALING_WISH); SEND_OUT(player, 1); }
        TURN { MOVE(player, MOVE_RETALIATE); }
        TURN { MOVE(player, MOVE_RETALIATE); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &damage[0]);
        HP_BAR(opponent, captureDamage: &damage[1]);
    } THEN {
        EXPECT_MUL_EQ(damage[1], Q_4_12(2.0), damage[0]);
    }
}

