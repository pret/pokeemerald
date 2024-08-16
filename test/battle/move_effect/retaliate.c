#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gMovesInfo[MOVE_RETALIATE].effect == EFFECT_RETALIATE);
}

SINGLE_BATTLE_TEST("Retaliate doubles in base power the turn after an ally faints")
{
    s16 damage[2];
    GIVEN {
        PLAYER(SPECIES_WYNAUT) { HP(1); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_TACKLE); SEND_OUT(player, 1); }
        TURN { MOVE(player, MOVE_RETALIATE); }
        TURN { MOVE(player, MOVE_RETALIATE); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &damage[0]);
        HP_BAR(opponent, captureDamage: &damage[1]);
    } THEN {
        EXPECT_MUL_EQ(damage[1], Q_4_12(2), damage[0]);
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
        TURN { MOVE(player, MOVE_TACKLE); SEND_OUT(opponent, 1); }
        TURN { MOVE(opponent, MOVE_RETALIATE); }
        TURN { MOVE(opponent, MOVE_RETALIATE); }
    } SCENE {
        HP_BAR(player, captureDamage: &damage[0]);
        HP_BAR(player, captureDamage: &damage[1]);
    } THEN {
        EXPECT_MUL_EQ(damage[1], Q_4_12(2), damage[0]);
    }
}

DOUBLE_BATTLE_TEST("Retaliate works with passive damage")
{
    s16 damage[2];
    u32 move;
    u32 move2 = MOVE_CELEBRATE;
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
        ASSUME(gMovesInfo[MOVE_TOXIC].effect == EFFECT_TOXIC);
        ASSUME(gMovesInfo[MOVE_POISON_POWDER].effect == EFFECT_POISON);
        ASSUME(gMovesInfo[MOVE_WILL_O_WISP].effect == EFFECT_WILL_O_WISP);
        #if B_USE_FROSTBITE == TRUE
        ASSUME(gMovesInfo[MOVE_ICE_BEAM].additionalEffects[0].moveEffect == MOVE_EFFECT_FREEZE_OR_FROSTBITE);
        #endif
        ASSUME(gMovesInfo[MOVE_SANDSTORM].effect == EFFECT_SANDSTORM);
        ASSUME(gMovesInfo[MOVE_HAIL].effect == EFFECT_HAIL);
        ASSUME(gMovesInfo[MOVE_LEECH_SEED].effect == EFFECT_LEECH_SEED);
        ASSUME(gMovesInfo[MOVE_MAGMA_STORM].additionalEffects[0].moveEffect == MOVE_EFFECT_WRAP);
        ASSUME(gMovesInfo[MOVE_FLAME_BURST].additionalEffects[0].moveEffect == MOVE_EFFECT_FLAME_BURST);
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
        EXPECT_MUL_EQ(damage[1], Q_4_12(2), damage[0]);
    }
}

SINGLE_BATTLE_TEST("Retaliate works with Perish Song")
{
    s16 damage[2];
    GIVEN {
        ASSUME(gMovesInfo[MOVE_PERISH_SONG].effect == EFFECT_PERISH_SONG);
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
        EXPECT_MUL_EQ(damage[1], Q_4_12(2), damage[0]);
    }
}

SINGLE_BATTLE_TEST("Retaliate works with self-inflicted fainting")
{
    s16 damage[2];
    GIVEN {
        ASSUME(gMovesInfo[MOVE_HEALING_WISH].effect == EFFECT_HEALING_WISH);
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
        EXPECT_MUL_EQ(damage[1], Q_4_12(2), damage[0]);
    }
}
