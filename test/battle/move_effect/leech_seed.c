#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_LEECH_SEED) == EFFECT_LEECH_SEED);
}

SINGLE_BATTLE_TEST("Leech Seed doesn't affect Grass-type Pokémon")
{
    PASSES_RANDOMLY(90, 100, RNG_ACCURACY);
    GIVEN {
        ASSUME(GetSpeciesType(SPECIES_ODDISH, 0) == TYPE_GRASS);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_ODDISH);
    } WHEN {
        TURN { MOVE(player, MOVE_LEECH_SEED); }
    } SCENE {
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_LEECH_SEED, player);
        MESSAGE("It doesn't affect the opposing Oddish…");
    }
}

SINGLE_BATTLE_TEST("Leech Seeded targets lose 1/8 of its max HP every turn and give it to the user")
{
    s16 damage;
    s16 healed;

    GIVEN {
        PLAYER(SPECIES_WYNAUT) { HP(1); }
        OPPONENT(SPECIES_SHELLDER);
    } WHEN {
        TURN { MOVE(player, MOVE_LEECH_SEED); }
        TURN {}
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_LEECH_SEED, player);
        HP_BAR(opponent);
        HP_BAR(player);
        HP_BAR(opponent, captureDamage: &damage);
        HP_BAR(player, captureDamage: &healed);
    } THEN {
        EXPECT_MUL_EQ(damage, Q_4_12(-1), healed);
    }
}

SINGLE_BATTLE_TEST("Leech Seed recovery is prevented by Heal Block")
{
    GIVEN {
        PLAYER(SPECIES_WYNAUT) { HP(1); }
        OPPONENT(SPECIES_SHELLDER);
    } WHEN {
        TURN { MOVE(opponent, MOVE_HEAL_BLOCK); MOVE(player, MOVE_LEECH_SEED); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HEAL_BLOCK, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_LEECH_SEED, player);
        HP_BAR(opponent);
        NOT HP_BAR(player);
    }
}

DOUBLE_BATTLE_TEST("Leech Seed will drain HP based on speed of the drained mon")
{
    GIVEN {
        PLAYER(SPECIES_WYNAUT) { Speed(1); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(2); }
        OPPONENT(SPECIES_WYNAUT) { Speed(3); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(4); }
    } WHEN {
        TURN {
            MOVE(playerLeft, MOVE_LEECH_SEED, target: opponentLeft);
            MOVE(playerRight, MOVE_LEECH_SEED, target: opponentRight);
            MOVE(opponentLeft, MOVE_LEECH_SEED, target: playerLeft);
            MOVE(opponentRight, MOVE_LEECH_SEED, target: playerRight);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_LEECH_SEED, opponentRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_LEECH_SEED, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_LEECH_SEED, playerRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_LEECH_SEED, playerLeft);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_LEECH_SEED_DRAIN, opponentRight);
        HP_BAR(opponentRight);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_LEECH_SEED_DRAIN, opponentLeft);
        HP_BAR(opponentLeft);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_LEECH_SEED_DRAIN, playerRight);
        HP_BAR(playerRight);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_LEECH_SEED_DRAIN, playerLeft);
        HP_BAR(playerLeft);
    }
}

SINGLE_BATTLE_TEST("Leech Seeded recovers health through Substitute")
{
    GIVEN {
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SUBSTITUTE); }
        TURN { MOVE(player, MOVE_LEECH_SEED); }
        TURN {}
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SUBSTITUTE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_LEECH_SEED, player);
        HP_BAR(player);
        HP_BAR(opponent);
        HP_BAR(player);
    }
}

SINGLE_BATTLE_TEST("Leech Seed is blocked by Substitute")
{
    GIVEN {
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SUBSTITUTE); }
        TURN { MOVE(player, MOVE_LEECH_SEED); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SUBSTITUTE, opponent);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_LEECH_SEED, player);
        MESSAGE("But it failed!");
    }
}

SINGLE_BATTLE_TEST("Leech Seed's accuracy is 90%")
{
    PASSES_RANDOMLY(90, 100, RNG_ACCURACY);
    GIVEN {
        ASSUME(GetMoveAccuracy(MOVE_LEECH_SEED) == 90);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_LEECH_SEED); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_LEECH_SEED, player);
    }
}

TO_DO_BATTLE_TEST("Leech Seed doesn't affect already seeded targets")
TO_DO_BATTLE_TEST("Leech Seed's effect is paused until a new battler replaces the original user's position") // Faint, can't be replaced, then revived.
TO_DO_BATTLE_TEST("Leech Seed's effect pause still prevents it from being seeded again")
TO_DO_BATTLE_TEST("Baton Pass passes Leech Seed's effect");
