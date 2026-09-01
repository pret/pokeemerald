#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Overcoat blocks powder and spore moves (Gen6+)")
{
    u32 gen = 0;
    PARAMETRIZE { gen = GEN_5; }
    PARAMETRIZE { gen = GEN_6; }
    GIVEN {
        WITH_CONFIG(B_POWDER_OVERCOAT, gen);
        ASSUME(IsPowderMove(MOVE_STUN_SPORE));
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_PINECO) { Ability(ABILITY_OVERCOAT); }
    } WHEN {
        TURN { MOVE(player, MOVE_STUN_SPORE); }
    } SCENE {
        if (gen == GEN_6) {
            ABILITY_POPUP(opponent, ABILITY_OVERCOAT);
            NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_STUN_SPORE, player);
            MESSAGE("It doesn't affect the opposing Pineco…");
        } else {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_STUN_SPORE, player);
            NONE_OF {
                ABILITY_POPUP(opponent, ABILITY_OVERCOAT);
                MESSAGE("It doesn't affect the opposing Pineco…");
            }
        }
    }
}

DOUBLE_BATTLE_TEST("Overcoat blocks damage from sandstorm")
{
    GIVEN {
        PLAYER(SPECIES_WYNAUT)    { Speed(50); }
        PLAYER(SPECIES_HELIOLISK) { Speed(40); Ability(ABILITY_SAND_VEIL); }
        OPPONENT(SPECIES_PINECO)  { Speed(30); Ability(ABILITY_OVERCOAT); }
        OPPONENT(SPECIES_STARLY)     { Speed(20); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_SANDSTORM); }
    } SCENE {
        MESSAGE("Wynaut used Sandstorm!");
        MESSAGE("The sandstorm is raging.");
        HP_BAR(playerLeft);
        NONE_OF {
            HP_BAR(playerRight);
            HP_BAR(opponentLeft);
        }
        HP_BAR(opponentRight);
    }
}

DOUBLE_BATTLE_TEST("Overcoat blocks damage from hail")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_HAIL) == EFFECT_WEATHER);
        ASSUME(GetMoveWeatherType(MOVE_HAIL) == BATTLE_WEATHER_HAIL);
        PLAYER(SPECIES_WYNAUT)    { Speed(50); Ability(ABILITY_SNOW_CLOAK); }
        PLAYER(SPECIES_SOLOSIS)   { Speed(40); Ability(ABILITY_RUN_AWAY); }
        OPPONENT(SPECIES_PINECO)  { Speed(30); Ability(ABILITY_OVERCOAT); }
        OPPONENT(SPECIES_SNORUNT) { Speed(20); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_HAIL); MOVE(playerRight, MOVE_SKILL_SWAP, target: playerLeft); }
    } SCENE {
        MESSAGE("Wynaut used Hail!");
        MESSAGE("Solosis used Skill Swap!");
        HP_BAR(playerLeft);
        NONE_OF {
            HP_BAR(playerRight);
            HP_BAR(opponentLeft);
            HP_BAR(opponentRight); // ice type
        }
    }
}

SINGLE_BATTLE_TEST("Overcoat blocks Effect Spore's effect (Gen6+)")
{
    u32 config;
    PARAMETRIZE { config = GEN_5; }
    PARAMETRIZE { config = GEN_6; }
    GIVEN {
        WITH_CONFIG(B_POWDER_OVERCOAT, config);
        PLAYER(SPECIES_PINECO) { Ability(ABILITY_OVERCOAT); }
        OPPONENT(SPECIES_SHROOMISH) { Ability(ABILITY_EFFECT_SPORE); }
    } WHEN {
        TURN { MOVE(player, MOVE_TACKLE, WITH_RNG(RNG_EFFECT_SPORE, 1)); }
    } SCENE {
        MESSAGE("Pineco used Tackle!");
        if (config == GEN_6) {
            NOT ABILITY_POPUP(opponent, ABILITY_EFFECT_SPORE);
        }
        else {
            ABILITY_POPUP(opponent, ABILITY_EFFECT_SPORE);
        }
    } THEN {
        if (config == GEN_6)
            EXPECT_EQ(player->status1, 0);
        else
            EXPECT_NE(player->status1, 0);
    }
}
