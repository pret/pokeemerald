#include "global.h"
#include "test/battle.h"

// Base Power and STAB Checks

SINGLE_BATTLE_TEST("(TERA) Terastallizing into a different type preserves other STAB boosts", s16 damage1, s16 damage2)
{
    bool32 tera;
    PARAMETRIZE { tera = GIMMICK_NONE; }
    PARAMETRIZE { tera = GIMMICK_TERA; }
    GIVEN {
        PLAYER(SPECIES_BULBASAUR) { TeraType(TYPE_NORMAL); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_VINE_WHIP, gimmick: tera); }
        TURN { MOVE(player, MOVE_SLUDGE_BOMB); }
    } SCENE {
        MESSAGE("Bulbasaur used Vine Whip!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_VINE_WHIP, player);
        HP_BAR(opponent, captureDamage: &results[i].damage1);
        MESSAGE("Bulbasaur used Sludge Bomb!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SLUDGE_BOMB, player);
        HP_BAR(opponent, captureDamage: &results[i].damage2);
    } FINALLY {
        EXPECT_EQ(results[0].damage1, results[1].damage1);
        EXPECT_EQ(results[0].damage2, results[1].damage2);
    }
}

SINGLE_BATTLE_TEST("(TERA) Terastallizing does not affect the power of non-STAB moves", s16 damage)
{
    bool32 tera;
    PARAMETRIZE { tera = GIMMICK_NONE; }
    PARAMETRIZE { tera = GIMMICK_TERA; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { TeraType(TYPE_PSYCHIC); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_HEADBUTT, gimmick: tera); }
    } SCENE {
        MESSAGE("Wobbuffet used Headbutt!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HEADBUTT, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_EQ(results[0].damage, results[1].damage);
    }
}

SINGLE_BATTLE_TEST("(TERA) Terastallizing into a different type gives that type 1.5x STAB", s16 damage)
{
    bool32 tera;
    PARAMETRIZE { tera = GIMMICK_NONE; }
    PARAMETRIZE { tera = GIMMICK_TERA; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { TeraType(TYPE_NORMAL); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_HEADBUTT, gimmick: tera); }
    } SCENE {
        MESSAGE("Wobbuffet used Headbutt!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HEADBUTT, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        // The jump from no STAB to 1.5x STAB is a 1.5x boost.
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.5), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("(TERA) Terastallizing into the same type gives that type 2x STAB", s16 damage)
{
    bool32 tera;
    PARAMETRIZE { tera = GIMMICK_NONE; }
    PARAMETRIZE { tera = GIMMICK_TERA; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { TeraType(TYPE_PSYCHIC); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_PSYCHIC, gimmick: tera); }
    } SCENE {
        MESSAGE("Wobbuffet used Psychic!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PSYCHIC, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        // The jump from 1.5x STAB to 2.0x STAB is a 1.33x boost.
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.33), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("(TERA) Terastallizing boosts moves of the same type to 60 BP", s16 damage)
{
    bool32 tera;
    PARAMETRIZE { tera = GIMMICK_NONE; }
    PARAMETRIZE { tera = GIMMICK_TERA; }
    GIVEN {
        ASSUME(GetMovePower(MOVE_ABSORB) == 20);
        PLAYER(SPECIES_WOBBUFFET) { TeraType(TYPE_GRASS); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_ABSORB, gimmick: tera); }
    } SCENE {
        MESSAGE("Wobbuffet used Absorb!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ABSORB, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        // The jump from 20 BP to 90 BP (60 * 1.5x) is a 4.5x boost.
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(4.5), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("(TERA) Terastallization's 60 BP floor occurs after Technician", s16 damage)
{
    bool32 tera;
    PARAMETRIZE { tera = GIMMICK_NONE; }
    PARAMETRIZE { tera = GIMMICK_TERA; }
    GIVEN {
        ASSUME(GetMovePower(MOVE_MEGA_DRAIN) == 40);
        PLAYER(SPECIES_MR_MIME) { Ability(ABILITY_TECHNICIAN); TeraType(TYPE_GRASS); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_MEGA_DRAIN, gimmick: tera); }
    } SCENE {
        MESSAGE("Mr. Mime used Mega Drain!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MEGA_DRAIN, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        // This should be the same as a normal Tera boost.
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.5), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("(TERA) Terastallization's 60 BP floor occurs after Technician", s16 damage)
{
    bool32 tera;
    PARAMETRIZE { tera = GIMMICK_NONE; }
    PARAMETRIZE { tera = GIMMICK_TERA; }
    GIVEN {
        PLAYER(SPECIES_MR_MIME) { Ability(ABILITY_TECHNICIAN); TeraType(TYPE_PSYCHIC); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_STORED_POWER, gimmick: tera); }
    } SCENE {
        MESSAGE("Mr. Mime used Stored Power!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STORED_POWER, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        // The jump from 45 BP (20 * 1.5x * 1.5x) to 120 BP (60 * 2.0x) is a 2.667x boost.
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(2.667), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("(TERA) Terastallization's 60 BP floor does not apply to multi-hit moves", s16 damage)
{
    bool32 tera;
    PARAMETRIZE { tera = GIMMICK_NONE; }
    PARAMETRIZE { tera = GIMMICK_TERA; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { TeraType(TYPE_NORMAL); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_FURY_SWIPES, gimmick: tera); }
    } SCENE {
        MESSAGE("Wobbuffet used Fury Swipes!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FURY_SWIPES, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.5), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("(TERA) Terastallization's 60 BP floor does not apply to priority moves", s16 damage)
{
    bool32 tera;
    PARAMETRIZE { tera = GIMMICK_NONE; }
    PARAMETRIZE { tera = GIMMICK_TERA; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { TeraType(TYPE_NORMAL); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_QUICK_ATTACK, gimmick: tera); }
    } SCENE {
        MESSAGE("Wobbuffet used Quick Attack!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_QUICK_ATTACK, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.5), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("(TERA) Terastallization's 60 BP floor does not apply to dynamic base power moves", s16 damage)
{
    bool32 tera;
    PARAMETRIZE { tera = GIMMICK_NONE; }
    PARAMETRIZE { tera = GIMMICK_TERA; }
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_WATER_SPOUT) == EFFECT_POWER_BASED_ON_USER_HP);
        PLAYER(SPECIES_WOBBUFFET) { HP(1); TeraType(TYPE_WATER); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_WATER_SPOUT, gimmick: tera); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_WATER_SPOUT, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_EQ(results[0].damage, results[1].damage);
    }
}

// Defensive Type Checks

SINGLE_BATTLE_TEST("(TERA) Terastallization changes type effectiveness", s16 damage)
{
    bool32 tera;
    PARAMETRIZE { tera = GIMMICK_NONE; }
    PARAMETRIZE { tera = GIMMICK_TERA; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { TeraType(TYPE_GRASS); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE, gimmick: tera); MOVE(opponent, MOVE_WATER_GUN); }
    } SCENE {
        MESSAGE("The opposing Wobbuffet used Water Gun!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_WATER_GUN, opponent);
        HP_BAR(player, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(0.5), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("(TERA) Terastallization changes type effectiveness")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { TeraType(TYPE_FLYING); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE, gimmick: GIMMICK_TERA); MOVE(opponent, MOVE_EARTHQUAKE); }
    } SCENE {
        MESSAGE("The opposing Wobbuffet used Earthquake!");
        MESSAGE("It doesn't affect Wobbuffet…");
        NOT { HP_BAR(player); }
    }
}

SINGLE_BATTLE_TEST("(TERA) Terastallization persists across switches")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { TeraType(TYPE_FLYING); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE, gimmick: GIMMICK_TERA); MOVE(opponent, MOVE_EARTHQUAKE); }
        TURN { SWITCH(player, 1); }
        TURN { SWITCH(player, 0); }
        TURN { MOVE(opponent, MOVE_EARTHQUAKE); }
    } SCENE {
        // turn 1
        MESSAGE("The opposing Wobbuffet used Earthquake!");
        MESSAGE("It doesn't affect Wobbuffet…");
        NOT { HP_BAR(player); }
        // turn 4
        MESSAGE("The opposing Wobbuffet used Earthquake!");
        MESSAGE("It doesn't affect Wobbuffet…");
        NOT { HP_BAR(player); }
    }
}

// Other Type Checks

SINGLE_BATTLE_TEST("(TERA) Terastallization changes the effect of Curse")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { TeraType(TYPE_GHOST); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_CURSE, gimmick: GIMMICK_TERA); }
    } SCENE {
        MESSAGE("Wobbuffet used Curse!");
        HP_BAR(player);
        MESSAGE("Wobbuffet cut its own HP and put a curse on the opposing Wobbuffet!");
        NOT { ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player); }
    }
}

SINGLE_BATTLE_TEST("(TERA) Roost does not remove the user's Flying type while Terastallized")
{
    GIVEN {
        PLAYER(SPECIES_ZAPDOS) { HP(1); TeraType(TYPE_FLYING); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_ROOST, gimmick: GIMMICK_TERA); MOVE(opponent, MOVE_ICE_BEAM); }
    } SCENE {
        MESSAGE("Zapdos used Roost!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ROOST, player);
        MESSAGE("The opposing Wobbuffet used Ice Beam!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ICE_BEAM, opponent);
        MESSAGE("It's super effective!");
    }
}

SINGLE_BATTLE_TEST("(TERA) Type-changing moves fail against a Terastallized Pokemon")
{
    enum Move move;
    PARAMETRIZE { move = MOVE_SOAK; }
    PARAMETRIZE { move = MOVE_FORESTS_CURSE; }
    PARAMETRIZE { move = MOVE_TRICK_OR_TREAT; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { TeraType(TYPE_PSYCHIC); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE, gimmick: GIMMICK_TERA); MOVE(opponent, move); }
    } SCENE {
        if (move != MOVE_SOAK)
            NOT { ANIMATION(ANIM_TYPE_MOVE, move, opponent); }
        MESSAGE("But it failed!");
    }
}

SINGLE_BATTLE_TEST("(TERA) Reflect Type fails if used by a Terastallized Pokemon")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { TeraType(TYPE_PSYCHIC); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_REFLECT_TYPE, gimmick: GIMMICK_TERA); }
    } SCENE {
        MESSAGE("Wobbuffet used Reflect Type!");
        MESSAGE("But it failed!");
    }
}

SINGLE_BATTLE_TEST("(TERA) Reflect Type copies a Terastallized Pokemon's Tera Type")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { TeraType(TYPE_GHOST); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_CELEBRATE); MOVE(player, MOVE_CELEBRATE, gimmick: GIMMICK_TERA); }
        TURN { MOVE(opponent, MOVE_REFLECT_TYPE); }
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        // turn 2
        MESSAGE("The opposing Wobbuffet used Reflect Type!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_REFLECT_TYPE, opponent);
        // turn 3
        MESSAGE("Wobbuffet used Scratch!");
        MESSAGE("It doesn't affect the opposing Wobbuffet…");
        NOT { HP_BAR(opponent); }
    }
}

SINGLE_BATTLE_TEST("(TERA) Synchronoise uses a Terastallized Pokemon's Tera Type")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { TeraType(TYPE_GHOST); }
        OPPONENT(SPECIES_WOBBUFFET) { TeraType(TYPE_GHOST); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SYNCHRONOISE); MOVE(player, MOVE_CELEBRATE, gimmick: GIMMICK_TERA); }
        TURN { MOVE(opponent, MOVE_SYNCHRONOISE, gimmick: GIMMICK_TERA); }
    } SCENE {
        // turn 1
        MESSAGE("The opposing Wobbuffet used Synchronoise!");
        MESSAGE("It doesn't affect Wobbuffet…");
        // turn 2
        MESSAGE("The opposing Wobbuffet used Synchronoise!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SYNCHRONOISE, opponent);
    }
}

SINGLE_BATTLE_TEST("(TERA) Revelation Dance uses a Terastallized Pokemon's Tera Type")
{
    GIVEN {
        ASSUME(P_GEN_7_POKEMON);
        PLAYER(SPECIES_ORICORIO) { TeraType(TYPE_NORMAL); }
        OPPONENT(SPECIES_GENGAR);
    } WHEN {
        TURN { MOVE(player, MOVE_REVELATION_DANCE, gimmick: GIMMICK_TERA); }
    } SCENE {
        MESSAGE("Oricorio used Revelation Dance!");
        MESSAGE("It doesn't affect the opposing Gengar…");
        NOT { HP_BAR(opponent); }
    }
}

// This tests that Tera STAB modifiers depend on the user's original types, too.
SINGLE_BATTLE_TEST("(TERA) Double Shock does not remove the user's Electric type while Terastallized, and changes STAB modifier depending on when it is used")
{
    s16 damage[4];
    GIVEN {
        WITH_CONFIG(B_MOVES_THAT_REMOVE_TYPE, GEN_9);
        ASSUME(GetMoveEffect(MOVE_DOUBLE_SHOCK) == EFFECT_FAIL_IF_NOT_ARG_TYPE);
        PLAYER(SPECIES_PICHU) { TeraType(TYPE_ELECTRIC); }
        PLAYER(SPECIES_WOBBUFFET)
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_DOUBLE_SHOCK); MOVE(opponent, MOVE_RECOVER); }
        TURN { MOVE(player, MOVE_DOUBLE_SHOCK, gimmick: GIMMICK_TERA); MOVE(opponent, MOVE_RECOVER); }
        TURN { MOVE(player, MOVE_DOUBLE_SHOCK); MOVE(opponent, MOVE_RECOVER); }
        TURN { SWITCH(player, 1); }
        TURN { SWITCH(player, 0); }
        TURN { MOVE(player, MOVE_DOUBLE_SHOCK); MOVE(opponent, MOVE_RECOVER); }
        TURN { MOVE(player, MOVE_DOUBLE_SHOCK); }
    } SCENE {
        // turn 1 - regular STAB
        MESSAGE("Pichu used Double Shock!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DOUBLE_SHOCK, player);
        HP_BAR(opponent, captureDamage: &damage[0]);
        // turn 2 - lost Electric type, gained back from Tera
        MESSAGE("Pichu used Double Shock!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DOUBLE_SHOCK, player);
        HP_BAR(opponent, captureDamage: &damage[1]);
        // turn 3 - retained Electric type
        MESSAGE("Pichu used Double Shock!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DOUBLE_SHOCK, player);
        // turn 6 - original type reset, regular STAB + Tera boost
        MESSAGE("Pichu used Double Shock!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DOUBLE_SHOCK, player);
        HP_BAR(opponent, captureDamage: &damage[2]);
        // turn 7 - regular STAB + Tera boost stays
        MESSAGE("Pichu used Double Shock!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DOUBLE_SHOCK, player);
        HP_BAR(opponent, captureDamage: &damage[3]);
    } THEN {
        EXPECT_EQ(damage[0], damage[1]);
        EXPECT_MUL_EQ(damage[0], Q_4_12(1.333), damage[2]);
        EXPECT_EQ(damage[2], damage[3]);
    }
}

// Stellar Type checks
SINGLE_BATTLE_TEST("(TERA) Stellar type does not change the user's defensive profile", s16 damage)
{
    bool32 tera;
    PARAMETRIZE { tera = GIMMICK_NONE; }
    PARAMETRIZE { tera = GIMMICK_TERA; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { TeraType(TYPE_STELLAR); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE, gimmick: tera); MOVE(opponent, MOVE_PSYCHIC); }
    } SCENE {
        MESSAGE("The opposing Wobbuffet used Psychic!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PSYCHIC, opponent);
        HP_BAR(player, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_EQ(results[0].damage, results[1].damage);
    }
}

SINGLE_BATTLE_TEST("(TERA) Reflect Type copies a Stellar-type Pokemon's base type")
{
    GIVEN {
        PLAYER(SPECIES_BANETTE) { TeraType(TYPE_STELLAR); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_CELEBRATE); MOVE(player, MOVE_CELEBRATE, gimmick: GIMMICK_TERA); }
        TURN { MOVE(opponent, MOVE_REFLECT_TYPE); }
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        // turn 2
        MESSAGE("The opposing Wobbuffet used Reflect Type!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_REFLECT_TYPE, opponent);
        // turn 3
        MESSAGE("Banette used Scratch!");
        MESSAGE("It doesn't affect the opposing Wobbuffet…");
        NOT { HP_BAR(opponent); }
    }
}

SINGLE_BATTLE_TEST("(TERA) Revelation Dance uses a Stellar-type Pokemon's base type")
{
    GIVEN {
        ASSUME(P_GEN_7_POKEMON);
        PLAYER(SPECIES_ORICORIO_SENSU) { TeraType(TYPE_STELLAR); }
        OPPONENT(SPECIES_GUMSHOOS);
    } WHEN {
        TURN { MOVE(player, MOVE_REVELATION_DANCE, gimmick: GIMMICK_TERA); }
    } SCENE {
        MESSAGE("Oricorio used Revelation Dance!");
        MESSAGE("It doesn't affect the opposing Gumshoos…");
        NOT { HP_BAR(opponent); }
    }
}

SINGLE_BATTLE_TEST("(TERA) Roost does not remove Flying-type ground immunity when Terastallized into the Stellar type")
{
    GIVEN {
        PLAYER(SPECIES_ZAPDOS) { HP(1); TeraType(TYPE_STELLAR); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_ROOST, gimmick: GIMMICK_TERA); MOVE(opponent, MOVE_ICE_BEAM); }
    } SCENE {
        MESSAGE("Zapdos used Roost!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ROOST, player);
        MESSAGE("The opposing Wobbuffet used Ice Beam!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ICE_BEAM, opponent);
        MESSAGE("It's super effective!");
    }
}

SINGLE_BATTLE_TEST("(TERA) Terastallizing into the Stellar-type provides a one-time 2.0x boost to STAB moves")
{
    s16 damage[3];
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { TeraType(TYPE_STELLAR); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_EXTRASENSORY); }
        TURN { MOVE(player, MOVE_EXTRASENSORY, gimmick: GIMMICK_TERA); }
        TURN { MOVE(player, MOVE_EXTRASENSORY); }
    } SCENE {
        // turn 1
        MESSAGE("Wobbuffet used Extrasensory!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EXTRASENSORY, player);
        HP_BAR(opponent, captureDamage: &damage[0]);
        // turn 2
        MESSAGE("Wobbuffet used Extrasensory!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EXTRASENSORY, player);
        HP_BAR(opponent, captureDamage: &damage[1]);
        // turn 3
        MESSAGE("Wobbuffet used Extrasensory!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EXTRASENSORY, player);
        HP_BAR(opponent, captureDamage: &damage[2]);
    } THEN {
        // Extrasensory goes from a 50% boost to a 100% boost for a 1.33x total multiplier
        EXPECT_MUL_EQ(damage[0], UQ_4_12(1.33), damage[1]);
        EXPECT_EQ(damage[0], damage[2]);
    }
}

SINGLE_BATTLE_TEST("(TERA) Terastallizing into the Stellar-type provides a one-time 1.2x boost to non-STAB moves")
{
    s16 damage[3];
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { TeraType(TYPE_STELLAR); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_TAKE_DOWN); }
        TURN { MOVE(player, MOVE_TAKE_DOWN, gimmick: GIMMICK_TERA); }
        TURN { MOVE(player, MOVE_TAKE_DOWN); }
    } SCENE {
        // turn 1
        MESSAGE("Wobbuffet used Take Down!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TAKE_DOWN, player);
        HP_BAR(opponent, captureDamage: &damage[0]);
        // turn 2
        MESSAGE("Wobbuffet used Take Down!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TAKE_DOWN, player);
        HP_BAR(opponent, captureDamage: &damage[1]);
        // turn 3
        MESSAGE("Wobbuffet used Take Down!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TAKE_DOWN, player);
        HP_BAR(opponent, captureDamage: &damage[2]);
    } THEN {
        EXPECT_MUL_EQ(damage[0], UQ_4_12(1.2), damage[1]);
        EXPECT_EQ(damage[0], damage[2]);
    }
}

SINGLE_BATTLE_TEST("(TERA) Terastallizing into the Stellar type boosts all moves up to 60 BP once per type")
{
    s16 damage[4];
    GIVEN {
        ASSUME(GetMovePower(MOVE_MEGA_DRAIN) == 40);
        ASSUME(GetMovePower(MOVE_WATER_GUN) == 40);
        PLAYER(SPECIES_WOBBUFFET) { TeraType(TYPE_STELLAR); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_MEGA_DRAIN); }
        TURN { MOVE(player, MOVE_MEGA_DRAIN, gimmick: GIMMICK_TERA); }
        TURN { MOVE(player, MOVE_MEGA_DRAIN); }
        TURN { MOVE(player, MOVE_WATER_GUN); }
    } SCENE {
        // turn 1
        MESSAGE("Wobbuffet used Mega Drain!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MEGA_DRAIN, player);
        HP_BAR(opponent, captureDamage: &damage[0]);
        // turn 2
        MESSAGE("Wobbuffet used Mega Drain!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MEGA_DRAIN, player);
        HP_BAR(opponent, captureDamage: &damage[1]);
        // turn 3
        MESSAGE("Wobbuffet used Mega Drain!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MEGA_DRAIN, player);
        HP_BAR(opponent, captureDamage: &damage[2]);
        // turn 4
        MESSAGE("Wobbuffet used Water Gun!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_WATER_GUN, player);
        HP_BAR(opponent, captureDamage: &damage[3]);
    } THEN {
        // The jump from 40 BP to 72 BP (60 * 1.2x) is a 1.8x boost.
        EXPECT_MUL_EQ(damage[0], Q_4_12(1.8), damage[1]);
        EXPECT_EQ(damage[0], damage[2]);
        EXPECT_EQ(damage[1], damage[3]);
    }
}

SINGLE_BATTLE_TEST("(TERA) Protean/Libero cannot change the type of a Terastallized Pokemon")
{
    enum Ability ability; enum Species species;
    PARAMETRIZE { ability = ABILITY_PROTEAN; species = SPECIES_GRENINJA; }
    PARAMETRIZE { ability = ABILITY_LIBERO;  species = SPECIES_RABOOT; }
    GIVEN {
        PLAYER(species) { Ability(ability); TeraType(TYPE_GRASS); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_BUBBLE, gimmick: GIMMICK_TERA);
               MOVE(opponent, MOVE_EMBER); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_TERA_ACTIVATE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BUBBLE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EMBER, opponent);
        MESSAGE("It's super effective!");
    }
}

SINGLE_BATTLE_TEST("(TERA) Status moves don't expend Stellar's one-time type boost")
{
    s16 damage[2];
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { TeraType(TYPE_STELLAR); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_GROWL, gimmick: GIMMICK_TERA); }
        TURN { MOVE(player, MOVE_TAKE_DOWN); }
        TURN { MOVE(player, MOVE_TAKE_DOWN); }
    } SCENE {
        // turn 1
        MESSAGE("Wobbuffet used Growl!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GROWL, player);
        // turn 2
        MESSAGE("Wobbuffet used Take Down!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TAKE_DOWN, player);
        HP_BAR(opponent, captureDamage: &damage[0]);
        // turn 3
        MESSAGE("Wobbuffet used Take Down!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TAKE_DOWN, player);
        HP_BAR(opponent, captureDamage: &damage[1]);
    } THEN {
        EXPECT_MUL_EQ(damage[1], UQ_4_12(1.20), damage[0]);
    }
}

SINGLE_BATTLE_TEST("(TERA) Stellar type's one-time boost factors in dynamically-typed moves")
{
    s16 damage[4];
    GIVEN {
        ASSUME(GetMoveType(MOVE_WEATHER_BALL) == TYPE_NORMAL);
        PLAYER(SPECIES_PELIPPER) { Ability(ABILITY_DRIZZLE); TeraType(TYPE_STELLAR); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_WEATHER_BALL, gimmick: GIMMICK_TERA); MOVE(opponent, MOVE_RECOVER); }
        TURN { MOVE(player, MOVE_TAKE_DOWN); MOVE(opponent, MOVE_RECOVER); }
        TURN { MOVE(player, MOVE_TAKE_DOWN); MOVE(opponent, MOVE_RECOVER); }
        TURN { MOVE(player, MOVE_WATER_PULSE); MOVE(opponent, MOVE_RECOVER); }
        TURN { MOVE(player, MOVE_WATER_PULSE); MOVE(opponent, MOVE_RECOVER); }
    } SCENE {
        MESSAGE("Pelipper used Weather Ball!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_WEATHER_BALL, player);
        // turn 2
        MESSAGE("Pelipper used Take Down!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TAKE_DOWN, player);
        HP_BAR(opponent, captureDamage: &damage[0]);
        // turn 3
        MESSAGE("Pelipper used Take Down!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TAKE_DOWN, player);
        HP_BAR(opponent, captureDamage: &damage[1]);
        // turn 4
        MESSAGE("Pelipper used Water Pulse!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_WATER_PULSE, player);
        HP_BAR(opponent, captureDamage: &damage[2]);
        // turn 5
        MESSAGE("Pelipper used Water Pulse!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_WATER_PULSE, player);
        HP_BAR(opponent, captureDamage: &damage[3]);
    } THEN {
        // Take Down should have a Normal type boost applied
        EXPECT_MUL_EQ(damage[1], UQ_4_12(1.20), damage[0]);
        // Water Pulse should not have a Water type boost applied
        EXPECT_EQ(damage[3], damage[2]);
    }
}

SINGLE_BATTLE_TEST("(TERA) Terapagos retains the Stellar type boost at all times")
{
    s16 damage[2];
    enum Move move;
    PARAMETRIZE { move = MOVE_SCRATCH; }
    PARAMETRIZE { move = MOVE_MACH_PUNCH; }
    GIVEN {
        ASSUME(GetMoveType(MOVE_SCRATCH) == TYPE_NORMAL);
        ASSUME(GetMoveType(MOVE_MACH_PUNCH) != TYPE_NORMAL);
        PLAYER(SPECIES_TERAPAGOS);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, move, gimmick: GIMMICK_TERA); }
        TURN { MOVE(player, move); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &damage[0]);
        HP_BAR(opponent, captureDamage: &damage[1]);
    } THEN {
        EXPECT_EQ(damage[0], damage[1]);
    }
}

SINGLE_BATTLE_TEST("(TERA) Terapagos retains its base defensive profile when Terastalizing")
{
    GIVEN {
        PLAYER(SPECIES_TERAPAGOS);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE, gimmick: GIMMICK_TERA); MOVE(opponent, MOVE_BRICK_BREAK); }
    } SCENE {
        MESSAGE("It's super effective!");
    }
}

SINGLE_BATTLE_TEST("(TERA) Illusion breaks if the Pokémon Terastallizes when illusioned as a mon that changes forms by Terastallizing")
{
    enum Species species;
    PARAMETRIZE { species = SPECIES_TERAPAGOS; }
    PARAMETRIZE { species = SPECIES_OGERPON; }
    GIVEN {
        ASSUME(DoesSpeciesHaveFormChangeMethod(species, FORM_CHANGE_BATTLE_TERASTALLIZATION));
        PLAYER(SPECIES_ZOROARK) { TeraType(TYPE_BUG); }
        PLAYER(species);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE, gimmick: GIMMICK_TERA); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_ILLUSION_OFF, player);
    }
}

// Visual test to make sure Zoroark appears as Wobbuffet/Zigzagoon until illusion breaks
SINGLE_BATTLE_TEST("(TERA) Illusion doesn't break upon Terastallizing when illusioned as a mon that doesn't change forms by Terastallizing")
{
    enum Species species;
    PARAMETRIZE { species = SPECIES_WOBBUFFET; }
    PARAMETRIZE { species = SPECIES_ZIGZAGOON; }
    GIVEN {
        ASSUME(!DoesSpeciesHaveFormChangeMethod(species, FORM_CHANGE_BATTLE_TERASTALLIZATION));
        PLAYER(SPECIES_ZOROARK) { TeraType(TYPE_BUG); }
        PLAYER(species);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE, gimmick: GIMMICK_TERA); MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_ILLUSION_OFF, player);
    }
}

SINGLE_BATTLE_TEST("(TERA) Transformed Pokémon can't Terastalize")
{
    GIVEN {
        PLAYER(SPECIES_DITTO) { Moves(MOVE_TRANSFORM, MOVE_CELEBRATE); }
        OPPONENT(SPECIES_TERAPAGOS) { Moves(MOVE_TRANSFORM, MOVE_CELEBRATE); }
    } WHEN {
        TURN { MOVE(player, MOVE_TRANSFORM); }
        TURN { MOVE(player, MOVE_CELEBRATE, gimmick: GIMMICK_TERA); }
    }
}

SINGLE_BATTLE_TEST("(TERA) Pokemon with Tera forms change upon Terastallizing")
{
    enum Species species, target;
    enum Item item;
    PARAMETRIZE { species = SPECIES_OGERPON_TEAL;        target = SPECIES_OGERPON_TEAL_TERA;        item = ITEM_NONE; }
    PARAMETRIZE { species = SPECIES_OGERPON_WELLSPRING;  target = SPECIES_OGERPON_WELLSPRING_TERA;  item = ITEM_WELLSPRING_MASK; }
    PARAMETRIZE { species = SPECIES_OGERPON_HEARTHFLAME; target = SPECIES_OGERPON_HEARTHFLAME_TERA; item = ITEM_HEARTHFLAME_MASK; }
    PARAMETRIZE { species = SPECIES_OGERPON_CORNERSTONE; target = SPECIES_OGERPON_CORNERSTONE_TERA; item = ITEM_CORNERSTONE_MASK; }
    PARAMETRIZE { species = SPECIES_TERAPAGOS_TERASTAL;  target = SPECIES_TERAPAGOS_STELLAR;        item = ITEM_NONE; }
    GIVEN {
        PLAYER(species) { Item(item); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE, gimmick: GIMMICK_TERA); }
    } THEN {
        EXPECT_EQ(player->species, target);
    }
}

SINGLE_BATTLE_TEST("(TERA) All type indicators function correctly")
{
    enum Type type;
    PARAMETRIZE { type = TYPE_NONE; }
    PARAMETRIZE { type = TYPE_NORMAL; }
    PARAMETRIZE { type = TYPE_FIGHTING; }
    PARAMETRIZE { type = TYPE_FLYING; }
    PARAMETRIZE { type = TYPE_POISON; }
    PARAMETRIZE { type = TYPE_GROUND; }
    PARAMETRIZE { type = TYPE_ROCK; }
    PARAMETRIZE { type = TYPE_BUG; }
    PARAMETRIZE { type = TYPE_GHOST; }
    PARAMETRIZE { type = TYPE_STEEL; }
    PARAMETRIZE { type = TYPE_MYSTERY; }
    PARAMETRIZE { type = TYPE_FIRE; }
    PARAMETRIZE { type = TYPE_WATER; }
    PARAMETRIZE { type = TYPE_GRASS; }
    PARAMETRIZE { type = TYPE_ELECTRIC; }
    PARAMETRIZE { type = TYPE_PSYCHIC; }
    PARAMETRIZE { type = TYPE_ICE; }
    PARAMETRIZE { type = TYPE_DRAGON; }
    PARAMETRIZE { type = TYPE_DARK; }
    PARAMETRIZE { type = TYPE_FAIRY; }
    PARAMETRIZE { type = TYPE_STELLAR; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { TeraType(type); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE, gimmick: GIMMICK_TERA); }
    }
}

SINGLE_BATTLE_TEST("(TERA) All type indicators function correctly - Opponent")
{
    enum Type type;
    PARAMETRIZE { type = TYPE_NONE; }
    PARAMETRIZE { type = TYPE_NORMAL; }
    PARAMETRIZE { type = TYPE_FIGHTING; }
    PARAMETRIZE { type = TYPE_FLYING; }
    PARAMETRIZE { type = TYPE_POISON; }
    PARAMETRIZE { type = TYPE_GROUND; }
    PARAMETRIZE { type = TYPE_ROCK; }
    PARAMETRIZE { type = TYPE_BUG; }
    PARAMETRIZE { type = TYPE_GHOST; }
    PARAMETRIZE { type = TYPE_STEEL; }
    PARAMETRIZE { type = TYPE_MYSTERY; }
    PARAMETRIZE { type = TYPE_FIRE; }
    PARAMETRIZE { type = TYPE_WATER; }
    PARAMETRIZE { type = TYPE_GRASS; }
    PARAMETRIZE { type = TYPE_ELECTRIC; }
    PARAMETRIZE { type = TYPE_PSYCHIC; }
    PARAMETRIZE { type = TYPE_ICE; }
    PARAMETRIZE { type = TYPE_DRAGON; }
    PARAMETRIZE { type = TYPE_DARK; }
    PARAMETRIZE { type = TYPE_FAIRY; }
    PARAMETRIZE { type = TYPE_STELLAR; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { TeraType(type); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_CELEBRATE, gimmick: GIMMICK_TERA); }
    }
}

SINGLE_BATTLE_TEST("(TERA) Every battler can use Terastalization - Singles")
{
    struct BattlePokemon *battler = NULL;
    PARAMETRIZE { battler = player; }
    PARAMETRIZE { battler = opponent; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { TeraType(TYPE_NORMAL); }
        OPPONENT(SPECIES_WOBBUFFET) { TeraType(TYPE_NORMAL); }
    } WHEN {
        TURN { MOVE(battler, MOVE_CELEBRATE, gimmick: GIMMICK_TERA); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_TERA_CHARGE, battler);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_TERA_ACTIVATE, battler);
    }
}

DOUBLE_BATTLE_TEST("(TERA) Every battler can use Terastalization - Doubles")
{
    struct BattlePokemon *battler = NULL;
    PARAMETRIZE { battler = playerLeft; }
    PARAMETRIZE { battler = playerRight; }
    PARAMETRIZE { battler = opponentLeft; }
    PARAMETRIZE { battler = opponentRight; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { TeraType(TYPE_NORMAL); }
        PLAYER(SPECIES_WOBBUFFET) { TeraType(TYPE_NORMAL); }
        OPPONENT(SPECIES_WOBBUFFET) { TeraType(TYPE_NORMAL); }
        OPPONENT(SPECIES_WOBBUFFET) { TeraType(TYPE_NORMAL); }
    } WHEN {
        TURN { MOVE(battler, MOVE_CELEBRATE, gimmick: GIMMICK_TERA); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_TERA_CHARGE, battler);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_TERA_ACTIVATE, battler);
    }
}

MULTI_BATTLE_TEST("(TERA) Every battler can use Terastalization - Multi")
{
    struct BattlePokemon *battler = NULL;
    PARAMETRIZE { battler = playerLeft; }
    PARAMETRIZE { battler = playerRight; }
    PARAMETRIZE { battler = opponentLeft; }
    PARAMETRIZE { battler = opponentRight; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { TeraType(TYPE_NORMAL); }
        PARTNER(SPECIES_WOBBUFFET) { TeraType(TYPE_NORMAL); }
        OPPONENT_A(SPECIES_WOBBUFFET) { TeraType(TYPE_NORMAL); }
        OPPONENT_B(SPECIES_WOBBUFFET) { TeraType(TYPE_NORMAL); }
    } WHEN {
        TURN { MOVE(battler, MOVE_CELEBRATE, gimmick: GIMMICK_TERA); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_TERA_CHARGE, battler);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_TERA_ACTIVATE, battler);
    }
}

TWO_VS_ONE_BATTLE_TEST("(TERA) Every battler can use Terastalization - 2v1")
{
    struct BattlePokemon *battler = NULL;
    PARAMETRIZE { battler = playerLeft; }
    PARAMETRIZE { battler = playerRight; }
    PARAMETRIZE { battler = opponentLeft; }
    PARAMETRIZE { battler = opponentRight; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { TeraType(TYPE_NORMAL); }
        PARTNER(SPECIES_WOBBUFFET) { TeraType(TYPE_NORMAL); }
        OPPONENT_A(SPECIES_WOBBUFFET) { TeraType(TYPE_NORMAL); }
        OPPONENT_A(SPECIES_WOBBUFFET) { TeraType(TYPE_NORMAL); }
    } WHEN {
        TURN { MOVE(battler, MOVE_CELEBRATE, gimmick: GIMMICK_TERA); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_TERA_CHARGE, battler);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_TERA_ACTIVATE, battler);
    }
}

ONE_VS_TWO_BATTLE_TEST("(TERA) Every battler can use Terastalization - 1v2")
{
    struct BattlePokemon *battler = NULL;
    PARAMETRIZE { battler = playerLeft; }
    PARAMETRIZE { battler = playerRight; }
    PARAMETRIZE { battler = opponentLeft; }
    PARAMETRIZE { battler = opponentRight; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { TeraType(TYPE_NORMAL); }
        PLAYER(SPECIES_WOBBUFFET) { TeraType(TYPE_NORMAL); }
        OPPONENT_A(SPECIES_WOBBUFFET) { TeraType(TYPE_NORMAL); }
        OPPONENT_B(SPECIES_WOBBUFFET) { TeraType(TYPE_NORMAL); }
    } WHEN {
        TURN { MOVE(battler, MOVE_CELEBRATE, gimmick: GIMMICK_TERA); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_TERA_CHARGE, battler);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_TERA_ACTIVATE, battler);
    }
}
