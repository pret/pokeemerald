#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_TAR_SHOT) == EFFECT_TAR_SHOT);
}

SINGLE_BATTLE_TEST("Tar Shot doubles the effectiveness of Fire-type moves used on the target")
{
    s16 damage[2];
    enum Species species;

    PARAMETRIZE { species = SPECIES_WOBBUFFET; }
    PARAMETRIZE { species = SPECIES_OMASTAR; } // Dual type with double resists

    ASSUME(GetSpeciesType(SPECIES_WOBBUFFET, 0) == TYPE_PSYCHIC);
    ASSUME(GetSpeciesType(SPECIES_WOBBUFFET, 1) == TYPE_PSYCHIC);
    ASSUME(GetSpeciesType(SPECIES_OMASTAR, 0) == TYPE_ROCK);
    ASSUME(GetSpeciesType(SPECIES_OMASTAR, 1) == TYPE_WATER);
    ASSUME(GetMoveType(MOVE_EMBER) == TYPE_FIRE);

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(species);
    } WHEN {
        TURN { MOVE(player, MOVE_EMBER); }
        TURN { MOVE(player, MOVE_TAR_SHOT); }
        TURN { MOVE(player, MOVE_EMBER); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EMBER, player);
        HP_BAR(opponent, captureDamage: &damage[0]);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TAR_SHOT, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EMBER, player);
        HP_BAR(opponent, captureDamage: &damage[1]);
        if (species != SPECIES_OMASTAR)
            MESSAGE("It's super effective!");
        else
            MESSAGE("It's not very effective…");
    } THEN {
        EXPECT_MUL_EQ(damage[0], Q_4_12(2.0), damage[1]);
    }
}

SINGLE_BATTLE_TEST("Tar Shot does not affect Pokemon that are Terastallized")
{
    s16 damage[2];
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { TeraType(TYPE_NORMAL); }
        OPPONENT(SPECIES_WOBBUFFET) ;
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE, gimmick: GIMMICK_TERA); MOVE(opponent, MOVE_EMBER); }
        TURN { MOVE(opponent, MOVE_TAR_SHOT); }
        TURN { MOVE(opponent, MOVE_EMBER); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EMBER, opponent);
        HP_BAR(player, captureDamage: &damage[0]);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TAR_SHOT, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EMBER, opponent);
        HP_BAR(player, captureDamage: &damage[1]);
        NOT MESSAGE("It's super effective!");
    } THEN {
        EXPECT_EQ(damage[0], damage[1]);
    }
}

SINGLE_BATTLE_TEST("Tar Shot does affect Pokemon that Terastallized after Tar Shot status was applied")
{
    s16 damage[2];
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { TeraType(TYPE_NORMAL); }
        OPPONENT(SPECIES_WOBBUFFET) ;
    } WHEN {
        TURN { MOVE(opponent, MOVE_EMBER); }
        TURN { MOVE(opponent, MOVE_TAR_SHOT); }
        TURN { MOVE(player, MOVE_CELEBRATE, gimmick: GIMMICK_TERA); MOVE(opponent, MOVE_EMBER); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EMBER, opponent);
        HP_BAR(player, captureDamage: &damage[0]);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TAR_SHOT, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EMBER, opponent);
        HP_BAR(player, captureDamage: &damage[1]);
        MESSAGE("It's super effective!");
    } THEN {
        EXPECT_MUL_EQ(damage[0], Q_4_12(2.0), damage[1]);
    }
}

