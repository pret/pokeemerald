#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_SOLAR_BEAM) == EFFECT_SOLAR_BEAM);
    ASSUME(GetTwoTurnMoveWeather(MOVE_SOLAR_BEAM) == BATTLE_WEATHER_SUN);
}

SINGLE_BATTLE_TEST("Solar Beam does not need a charging turn if Sun is up")
{
    enum Ability ability;

    PARAMETRIZE { ability = ABILITY_DROUGHT; }
    PARAMETRIZE { ability = ABILITY_WHITE_SMOKE; }

    GIVEN {
        PLAYER(SPECIES_TORKOAL) { Ability(ability); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SOLAR_BEAM); }
        if (ability == ABILITY_WHITE_SMOKE) {
            TURN { SKIP_TURN(player); }
        }
    } SCENE {
        if (ability == ABILITY_WHITE_SMOKE) {
            MESSAGE("Torkoal used Solar Beam!");
            MESSAGE("Torkoal absorbed light!");
            ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
        }
        MESSAGE("Torkoal used Solar Beam!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SOLAR_BEAM, player);
    }
}

SINGLE_BATTLE_TEST("Solar Beam does half damage if Sandstorm is up (Gen3+)", s16 damage)
{
    enum Ability ability;
    u32 config;

    PARAMETRIZE { ability = ABILITY_SAND_FORCE;  config = GEN_2; }
    PARAMETRIZE { ability = ABILITY_SAND_STREAM; config = GEN_2; }
    PARAMETRIZE { ability = ABILITY_SAND_STREAM; config = GEN_3; }

    GIVEN {
        WITH_CONFIG(B_SANDSTORM_SOLAR_BEAM, config);
        PLAYER(SPECIES_HIPPOWDON) { Ability(ability); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SOLAR_BEAM); }
        TURN { SKIP_TURN(player); }
    } SCENE {
        MESSAGE("Hippowdon used Solar Beam!");
        MESSAGE("Hippowdon absorbed light!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
        MESSAGE("Hippowdon used Solar Beam!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SOLAR_BEAM, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(0.5), results[2].damage);
        EXPECT_MUL_EQ(results[1].damage, Q_4_12(0.5), results[2].damage);
    }
}

SINGLE_BATTLE_TEST("Solar Beam does not need a charging turn in Primal Sun")
{
    GIVEN {
        PLAYER(SPECIES_GROUDON) { Item(ITEM_RED_ORB); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SOLAR_BEAM); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SOLAR_BEAM, player);
        HP_BAR(opponent);
    }
}
