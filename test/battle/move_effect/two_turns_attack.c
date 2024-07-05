#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gMovesInfo[MOVE_RAZOR_WIND].effect == EFFECT_TWO_TURNS_ATTACK);
    ASSUME(gMovesInfo[MOVE_SKULL_BASH].effect == EFFECT_TWO_TURNS_ATTACK);
    ASSUME(MoveHasAdditionalEffectSelf(MOVE_SKULL_BASH, MOVE_EFFECT_DEF_PLUS_1) == TRUE);
    ASSUME(gMovesInfo[MOVE_SKY_ATTACK].effect == EFFECT_TWO_TURNS_ATTACK);

    // Solar Beam - check for sun
    ASSUME(gMovesInfo[MOVE_SOLAR_BEAM].effect == EFFECT_SOLAR_BEAM);
    ASSUME(HIHALF(gMovesInfo[MOVE_SOLAR_BLADE].argument) == B_WEATHER_SUN);
    ASSUME(gMovesInfo[MOVE_SOLAR_BLADE].effect == EFFECT_SOLAR_BEAM);
    ASSUME(HIHALF(gMovesInfo[MOVE_SOLAR_BLADE].argument) == B_WEATHER_SUN);

    // Electro shot - check for rain
    ASSUME(HIHALF(gMovesInfo[MOVE_ELECTRO_SHOT].argument) == B_WEATHER_RAIN);
    ASSUME(gMovesInfo[MOVE_ELECTRO_SHOT].effect == EFFECT_TWO_TURNS_ATTACK);
    ASSUME(MoveHasAdditionalEffectSelf(MOVE_ELECTRO_SHOT, MOVE_EFFECT_SP_ATK_PLUS_1) == TRUE);
}

SINGLE_BATTLE_TEST("Razor Wind needs a charging turn")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_RAZOR_WIND); }
        TURN { SKIP_TURN(player); }
    } SCENE {
        // Charging turn
        if (B_UPDATED_MOVE_DATA >= GEN_5) {
            NOT MESSAGE("Wobbuffet whipped up a whirlwind!");
            MESSAGE("Wobbuffet used Razor Wind!");
        } else {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_RAZOR_WIND, player);
        }
        if (B_UPDATED_MOVE_DATA < GEN_5)
            MESSAGE("Wobbuffet whipped up a whirlwind!");
        else
            ANIMATION(ANIM_TYPE_MOVE, MOVE_RAZOR_WIND, player);
        // Attack turn
        MESSAGE("Wobbuffet used Razor Wind!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_RAZOR_WIND, player);
        HP_BAR(opponent);
    }
}

SINGLE_BATTLE_TEST("Razor Wind doesn't need to charge with Power Herb")
{
    KNOWN_FAILING;
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_POWER_HERB); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_RAZOR_WIND); }
    } SCENE {
        if (B_UPDATED_MOVE_DATA >= GEN_5) {
            NOT MESSAGE("Wobbuffet whipped up a whirlwind!");
            MESSAGE("Wobbuffet used Razor Wind!");
        } else
            ANIMATION(ANIM_TYPE_MOVE, MOVE_RAZOR_WIND, player);
        if (B_UPDATED_MOVE_DATA < GEN_5)
            MESSAGE("Wobbuffet whipped up a whirlwind!");
        else
            ANIMATION(ANIM_TYPE_MOVE, MOVE_RAZOR_WIND, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
        MESSAGE("Wobbuffet became fully charged due to its Power Herb!");
        if (B_UPDATED_MOVE_DATA < GEN_5)
            MESSAGE("Wobbuffet used Razor Wind!");
        // For some reason, this breaks with and only with Razor Wind...
        ANIMATION(ANIM_TYPE_MOVE, MOVE_RAZOR_WIND, player);
        HP_BAR(opponent);
    }
}

SINGLE_BATTLE_TEST("Skull Bash needs a charging turn")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SKULL_BASH); }
        TURN { SKIP_TURN(player); }
    } SCENE {
        // Charging turn
        if (B_UPDATED_MOVE_DATA >= GEN_5) {
            NOT MESSAGE("Wobbuffet lowered its head!");
            MESSAGE("Wobbuffet used Skull Bash!");
        } else
            ANIMATION(ANIM_TYPE_MOVE, MOVE_SKULL_BASH, player);
        if (B_UPDATED_MOVE_DATA < GEN_5)
            MESSAGE("Wobbuffet lowered its head!");
        else
            ANIMATION(ANIM_TYPE_MOVE, MOVE_SKULL_BASH, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        MESSAGE("Wobbuffet's Defense rose!");
        // Attack turn
        MESSAGE("Wobbuffet used Skull Bash!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SKULL_BASH, player);
        HP_BAR(opponent);
    }
}

SINGLE_BATTLE_TEST("Skull Bash doesn't need to charge with Power Herb")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_POWER_HERB); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SKULL_BASH); }
    } SCENE {
        if (B_UPDATED_MOVE_DATA >= GEN_5) {
            NOT MESSAGE("Wobbuffet lowered its head!");
            MESSAGE("Wobbuffet used Skull Bash!");
        } else
            ANIMATION(ANIM_TYPE_MOVE, MOVE_SKULL_BASH, player);
        if (B_UPDATED_MOVE_DATA < GEN_5)
            MESSAGE("Wobbuffet lowered its head!");
        else
            ANIMATION(ANIM_TYPE_MOVE, MOVE_SKULL_BASH, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        MESSAGE("Wobbuffet's Defense rose!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
        MESSAGE("Wobbuffet became fully charged due to its Power Herb!");
        if (B_UPDATED_MOVE_DATA < GEN_5)
            MESSAGE("Wobbuffet used Skull Bash!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SKULL_BASH, player);
        HP_BAR(opponent);
    }
}

SINGLE_BATTLE_TEST("Sky Attack needs a charging turn")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SKY_ATTACK); }
        TURN { SKIP_TURN(player); }
    } SCENE {
        // Charging turn
        if (B_UPDATED_MOVE_DATA >= GEN_5) {
            NONE_OF {
                MESSAGE("Wobbuffet became cloaked in a harsh light!");
                MESSAGE("Wobbuffet is glowing!");
            }
            MESSAGE("Wobbuffet used Sky Attack!");
        } else
            ANIMATION(ANIM_TYPE_MOVE, MOVE_SKY_ATTACK, player);
        if (B_UPDATED_MOVE_DATA < GEN_4)
            MESSAGE("Wobbuffet is glowing!");
        else if (B_UPDATED_MOVE_DATA < GEN_5)
            MESSAGE("Wobbuffet became cloaked in a harsh light!");
        else
            ANIMATION(ANIM_TYPE_MOVE, MOVE_SKY_ATTACK, player);
        // Attack turn
        MESSAGE("Wobbuffet used Sky Attack!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SKY_ATTACK, player);
        HP_BAR(opponent);
    }
}

SINGLE_BATTLE_TEST("Sky Attack doesn't need to charge with Power Herb")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_POWER_HERB); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SKY_ATTACK); }
    } SCENE {
        if (B_UPDATED_MOVE_DATA >= GEN_5) {
            NONE_OF {
                MESSAGE("Wobbuffet became cloaked in a harsh light!");
                MESSAGE("Wobbuffet is glowing!");
            }
            MESSAGE("Wobbuffet used Sky Attack!");
        } else
            ANIMATION(ANIM_TYPE_MOVE, MOVE_SKY_ATTACK, player);
        if (B_UPDATED_MOVE_DATA < GEN_4)
            MESSAGE("Wobbuffet is glowing!");
        else if (B_UPDATED_MOVE_DATA < GEN_5)
            MESSAGE("Wobbuffet became cloaked in a harsh light!");
        else
            ANIMATION(ANIM_TYPE_MOVE, MOVE_SKY_ATTACK, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
        MESSAGE("Wobbuffet became fully charged due to its Power Herb!");
        if (B_UPDATED_MOVE_DATA < GEN_5)
            MESSAGE("Wobbuffet used Sky Attack!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SKY_ATTACK, player);
        HP_BAR(opponent);
    }
}

SINGLE_BATTLE_TEST("Solar Beam and Solar Blade can be used instantly in Sunlight")
{
    u32 move1, move2;
    PARAMETRIZE { move1 = MOVE_SPLASH; move2 = MOVE_SOLAR_BEAM; }
    PARAMETRIZE { move1 = MOVE_SUNNY_DAY; move2 = MOVE_SOLAR_BEAM; }
    PARAMETRIZE { move1 = MOVE_SPLASH; move2 = MOVE_SOLAR_BLADE; }
    PARAMETRIZE { move1 = MOVE_SUNNY_DAY; move2 = MOVE_SOLAR_BLADE; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, move1); MOVE(player, move2); }
        TURN { SKIP_TURN(player); }
    } SCENE {
        if (move1 == MOVE_SUNNY_DAY) {
            NOT MESSAGE("Wobbuffet took in sunlight!");
        } else {
            if (move2 == MOVE_SOLAR_BEAM) {
                if (B_UPDATED_MOVE_DATA >= GEN_5)
                {
                    MESSAGE("Wobbuffet used Solar Beam!");
                    MESSAGE("Wobbuffet took in sunlight!");
                    ANIMATION(ANIM_TYPE_MOVE, move2, player);
                } else {
                    NOT MESSAGE("Wobbuffet used Solar Beam!");
                    ANIMATION(ANIM_TYPE_MOVE, move2, player);
                    MESSAGE("Wobbuffet took in sunlight!");
                }
                MESSAGE("Wobbuffet used Solar Beam!");
            } else {
                if (B_UPDATED_MOVE_DATA >= GEN_5) {
                    MESSAGE("Wobbuffet used Solar Blade!");
                    MESSAGE("Wobbuffet took in sunlight!");
                    ANIMATION(ANIM_TYPE_MOVE, move2, player);
                } else {
                    NOT MESSAGE("Wobbuffet used Solar Blade!");
                    ANIMATION(ANIM_TYPE_MOVE, move2, player);
                    MESSAGE("Wobbuffet took in sunlight!");
                }
                MESSAGE("Wobbuffet used Solar Blade!");
            }
            ANIMATION(ANIM_TYPE_MOVE, move2, player);
            HP_BAR(opponent);
        }
    }
}

SINGLE_BATTLE_TEST("Solar Beam's power is halved in Rain", s16 damage)
{
    u16 move;
    PARAMETRIZE { move = MOVE_CELEBRATE; }
    PARAMETRIZE { move = MOVE_RAIN_DANCE; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, move); MOVE(player, MOVE_SOLAR_BEAM); }
        TURN { SKIP_TURN(player); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(0.5), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Solar Blade's power is halved in Rain", s16 damage)
{
    u16 move;
    PARAMETRIZE { move = MOVE_CELEBRATE; }
    PARAMETRIZE { move = MOVE_RAIN_DANCE; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(opponent, move); MOVE(player, MOVE_SOLAR_BLADE); }
        TURN { SKIP_TURN(player); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(0.5), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Solar Beam's power is halved in a Sandstorm", s16 damage)
{
    u16 move;
    PARAMETRIZE { move = MOVE_CELEBRATE; }
    PARAMETRIZE { move = MOVE_SANDSTORM; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_SAFETY_GOGGLES); };
    } WHEN {
        TURN { MOVE(opponent, move); MOVE(player, MOVE_SOLAR_BEAM); }
        TURN { SKIP_TURN(player); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(0.5), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Solar Blade's power is halved in a Sandstorm", s16 damage)
{
    u16 move;
    PARAMETRIZE { move = MOVE_CELEBRATE; }
    PARAMETRIZE { move = MOVE_SANDSTORM; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_SAFETY_GOGGLES); };
    } WHEN {
        TURN { MOVE(opponent, move); MOVE(player, MOVE_SOLAR_BLADE); }
        TURN { SKIP_TURN(player); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(0.5), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Solar Beam's power is halved in Hail", s16 damage)
{
    u16 move;
    PARAMETRIZE { move = MOVE_CELEBRATE; }
    PARAMETRIZE { move = MOVE_HAIL; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_SAFETY_GOGGLES); };
    } WHEN {
        TURN { MOVE(opponent, move); MOVE(player, MOVE_SOLAR_BEAM); }
        TURN { SKIP_TURN(player); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(0.5), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Solar Blade's power is halved in Hail", s16 damage)
{
    u16 move;
    PARAMETRIZE { move = MOVE_CELEBRATE; }
    PARAMETRIZE { move = MOVE_HAIL; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_SAFETY_GOGGLES); };
    } WHEN {
        TURN { MOVE(opponent, move); MOVE(player, MOVE_SOLAR_BLADE); }
        TURN { SKIP_TURN(player); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(0.5), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Solar Beam's power is halved in Snow", s16 damage)
{
    u16 move;
    PARAMETRIZE { move = MOVE_CELEBRATE; }
    PARAMETRIZE { move = MOVE_SNOWSCAPE; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, move); MOVE(player, MOVE_SOLAR_BEAM); }
        TURN { SKIP_TURN(player); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(0.5), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Solar Blade's power is halved in Snow", s16 damage)
{
    u16 move;
    PARAMETRIZE { move = MOVE_CELEBRATE; }
    PARAMETRIZE { move = MOVE_SNOWSCAPE; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(opponent, move); MOVE(player, MOVE_SOLAR_BLADE); }
        TURN { SKIP_TURN(player); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(0.5), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Electro Shot needs a charging Turn")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_ELECTRO_SHOT); }
        TURN { SKIP_TURN(player); }
    } SCENE {
        // Charging turn
        MESSAGE("Wobbuffet used Electro Shot!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ELECTRO_SHOT, player);
        MESSAGE("Wobbuffet absorbed electricity!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        MESSAGE("Wobbuffet's Sp. Atk rose!");
        // Attack turn
        MESSAGE("Wobbuffet used Electro Shot!");
        HP_BAR(opponent);
    }
}

SINGLE_BATTLE_TEST("Electro Shot doesn't need to charge when it's raining")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_RAIN_DANCE); MOVE(player, MOVE_ELECTRO_SHOT); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_RAIN_DANCE, opponent);
        MESSAGE("Wobbuffet used Electro Shot!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ELECTRO_SHOT, player);
        MESSAGE("Wobbuffet absorbed electricity!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        MESSAGE("Wobbuffet's Sp. Atk rose!");
        NONE_OF {
            MESSAGE("Wobbuffet used Electro Shot!");
        }
        HP_BAR(opponent);
    }
}

SINGLE_BATTLE_TEST("Electro Shot doesn't need to charge with Power Herb")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_POWER_HERB); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_ELECTRO_SHOT); }
    } SCENE {
        MESSAGE("Wobbuffet used Electro Shot!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ELECTRO_SHOT, player);
        MESSAGE("Wobbuffet absorbed electricity!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        MESSAGE("Wobbuffet's Sp. Atk rose!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
        MESSAGE("Wobbuffet became fully charged due to its Power Herb!");
        NONE_OF {
            MESSAGE("Wobbuffet used Electro Shot!");
        }
        HP_BAR(opponent);
    }
}
