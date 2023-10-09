#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    gItems[ITEM_METRONOME].holdEffect == HOLD_EFFECT_METRONOME;
}

const uq4_12_t MetronomeMultipliers[] = {
    UQ_4_12(1.0),
    UQ_4_12(1.2),
    UQ_4_12(1.4),
    UQ_4_12(1.6),
    UQ_4_12(1.8),
    UQ_4_12(2.0),
    UQ_4_12(2.0)
};

#define METRONOME_TURNS (ARRAY_COUNT(MetronomeMultipliers))

SINGLE_BATTLE_TEST("Metronome Item gradually boosts power of consecutively used moves by 20%, up to 100%")
{
    s16 damage[METRONOME_TURNS];
    u32 j;
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_METRONOME); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        for (j = 0; j < METRONOME_TURNS; ++j) {
            TURN { MOVE(player, MOVE_TACKLE); }
        }
    } SCENE {
        for (j = 0; j < METRONOME_TURNS; ++j) {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, player);
            HP_BAR(opponent, captureDamage: &damage[j]);
        }
    } THEN {
        for (j = 0; j < METRONOME_TURNS; ++j) {
            EXPECT_MUL_EQ(damage[0], MetronomeMultipliers[j], damage[j]);
        }
    }
}

SINGLE_BATTLE_TEST("Metronome Item's boost is reset if the attacker uses a different move")
{
    s16 damage[2];
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_METRONOME); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_TACKLE); }
        TURN { MOVE(player, MOVE_QUICK_ATTACK); }
        TURN { MOVE(player, MOVE_TACKLE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, player);
        HP_BAR(opponent, captureDamage: &damage[0]);

        ANIMATION(ANIM_TYPE_MOVE, MOVE_QUICK_ATTACK, player);

        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, player);
        HP_BAR(opponent, captureDamage: &damage[1]);
    } THEN {
        EXPECT_EQ(damage[0], damage[1]);
    }
}

SINGLE_BATTLE_TEST("Metronome Item's boost is reset if the move fails")
{
    s16 damage[2];
    KNOWN_FAILING; //https://github.com/rh-hideout/pokeemerald-expansion/issues/3251
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_METRONOME); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_TACKLE); }
        TURN { MOVE(opponent, MOVE_PROTECT); MOVE(player, MOVE_TACKLE); }
        TURN { MOVE(player, MOVE_TACKLE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, player);
        HP_BAR(opponent, captureDamage: &damage[0]);

        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, player);
        HP_BAR(opponent, captureDamage: &damage[1]);
    } THEN {
        EXPECT_EQ(damage[0], damage[1]);
    }
}

SINGLE_BATTLE_TEST("Metronome Item counts called moves instead of the calling move")
{
    s16 damage[2];
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_METRONOME); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_METRONOME, WITH_RNG(RNG_METRONOME, MOVE_TACKLE)); }
        TURN { MOVE(player, MOVE_METRONOME, WITH_RNG(RNG_METRONOME, MOVE_TACKLE)); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, player);
        HP_BAR(opponent, captureDamage: &damage[0]);

        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, player);
        HP_BAR(opponent, captureDamage: &damage[1]);
    } THEN {
        EXPECT_MUL_EQ(damage[0], UQ_4_12(1.2), damage[1]);
    }
}

SINGLE_BATTLE_TEST("Metronome Item counts charging turn of moves for its attacking turn", s16 damage)
{
    u32 item;

    KNOWN_FAILING; // https://github.com/rh-hideout/pokeemerald-expansion/issues/3250
    PARAMETRIZE {item = ITEM_NONE; }
    PARAMETRIZE {item = ITEM_METRONOME; }
    GIVEN {
        ASSUME(gBattleMoves[MOVE_SOLAR_BEAM].effect == EFFECT_SOLAR_BEAM);
        PLAYER(SPECIES_WOBBUFFET) { Item(item); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SOLAR_BEAM); }
        TURN { SKIP_TURN(player); }
    } SCENE {
        MESSAGE("Wobbuffet used Solar Beam!");
        MESSAGE("Wobbuffet took in sunlight!");
        MESSAGE("Foe Wobbuffet used Celebrate!");
        MESSAGE("Congratulations, 1!");
        MESSAGE("Wobbuffet used Solar Beam!");
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, UQ_4_12(1.2), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Metronome Item doesn't increase damage per hit of multi-hit moves")
{
    s16 damage[3];
    GIVEN {
        ASSUME(gBattleMoves[MOVE_FURY_ATTACK].effect == EFFECT_MULTI_HIT);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_METRONOME); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_FURY_ATTACK); }
        TURN { MOVE(player, MOVE_FURY_ATTACK); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FURY_ATTACK, player);
        HP_BAR(opponent, captureDamage: &damage[0]);
        HP_BAR(opponent, captureDamage: &damage[1]);
        MESSAGE("Hit 5 time(s)!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FURY_ATTACK, player);
        HP_BAR(opponent, captureDamage: &damage[2]);
    } THEN {
        EXPECT_MUL_EQ(damage[0], UQ_4_12(1.2), damage[2]); // Got bonus once for the second turn
        EXPECT_EQ(damage[0], damage[1]); // Do not get the bonus while still inside the first turn
    }
}
