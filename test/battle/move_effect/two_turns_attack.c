#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_RAZOR_WIND) == EFFECT_TWO_TURNS_ATTACK);
    ASSUME(GetMoveEffect(MOVE_SKULL_BASH) == EFFECT_TWO_TURNS_ATTACK);
    ASSUME_MOVE_EFFECT_STAT_CHANGE(MOVE_SKULL_BASH, self: TRUE, defense: 1);
    ASSUME(GetMoveEffect(MOVE_SKY_ATTACK) == EFFECT_TWO_TURNS_ATTACK);

    // Electro shot - check for rain
    ASSUME(GetTwoTurnMoveWeather(MOVE_ELECTRO_SHOT) == BATTLE_WEATHER_RAIN);
    ASSUME(GetMoveEffect(MOVE_ELECTRO_SHOT) == EFFECT_TWO_TURNS_ATTACK);
    ASSUME_MOVE_EFFECT_STAT_CHANGE(MOVE_ELECTRO_SHOT, self: TRUE, spAtk: 1);
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
        ANIMATION(ANIM_TYPE_MOVE, MOVE_RAZOR_WIND, player);
        HP_BAR(opponent);
    }
}

DOUBLE_BATTLE_TEST("Razor Wind successfully KOs both opponents")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_POWER_HERB); }
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET) { HP(1); }
        OPPONENT(SPECIES_WYNAUT) { HP(1); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_RAZOR_WIND); }
    } SCENE {
        if (B_UPDATED_MOVE_DATA >= GEN_5) {
            NOT MESSAGE("Wobbuffet whipped up a whirlwind!");
            MESSAGE("Wobbuffet used Razor Wind!");
        } else
            ANIMATION(ANIM_TYPE_MOVE, MOVE_RAZOR_WIND, playerLeft);
        if (B_UPDATED_MOVE_DATA < GEN_5)
            MESSAGE("Wobbuffet whipped up a whirlwind!");
        else
            ANIMATION(ANIM_TYPE_MOVE, MOVE_RAZOR_WIND, playerLeft);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, playerLeft);
        MESSAGE("Wobbuffet became fully charged due to its Power Herb!");
        if (B_UPDATED_MOVE_DATA < GEN_5)
            MESSAGE("Wobbuffet used Razor Wind!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_RAZOR_WIND, playerLeft);
        HP_BAR(opponentLeft);
        MESSAGE("The opposing Wobbuffet fainted!");
        MESSAGE("The opposing Wynaut fainted!");
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
    enum Move move1, move2;
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
        // Potential visual bug.
        // The script has the B_WAIT_TIME_LONG waitmessage but it does not wait
        if (move2 == MOVE_SOLAR_BEAM) {
            MESSAGE("Wobbuffet used Solar Beam!");
        } else {
            MESSAGE("Wobbuffet used Solar Blade!");
        }
        MESSAGE("Wobbuffet absorbed light!");

        if (move2 == MOVE_SOLAR_BEAM) {
            if (move1 == MOVE_SPLASH) {
                MESSAGE("Wobbuffet used Solar Beam!");
            }
            ANIMATION(ANIM_TYPE_MOVE, move2, player);
        } else {
            if (move1 == MOVE_SPLASH) {
                MESSAGE("Wobbuffet used Solar Blade!");
            }
            ANIMATION(ANIM_TYPE_MOVE, move2, player);
        }
        HP_BAR(opponent);
    }
}

SINGLE_BATTLE_TEST("Solar Beam and Solar Blade still need a charging turn in Sunlight with Utility Umbrella")
{
    enum Move move;
    PARAMETRIZE { move = MOVE_SOLAR_BEAM; }
    PARAMETRIZE { move = MOVE_SOLAR_BLADE; }
    GIVEN {
        ASSUME(GetItemHoldEffect(ITEM_UTILITY_UMBRELLA) == HOLD_EFFECT_UTILITY_UMBRELLA);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_UTILITY_UMBRELLA); }
        OPPONENT(SPECIES_TORKOAL) { Ability(ABILITY_DROUGHT); }
    } WHEN {
        TURN { MOVE(player, move); MOVE(opponent, MOVE_CELEBRATE); }
        TURN { SKIP_TURN(player); MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
        // Charging turn
        MESSAGE("Wobbuffet absorbed light!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
        // Attack turn
        ANIMATION(ANIM_TYPE_MOVE, move, player);
        HP_BAR(opponent);
    }
}

SINGLE_BATTLE_TEST("Solar Beam's power is halved in Rain", s16 damage)
{
    enum Move move;
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
    enum Move move;
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
    enum Move move;
    PARAMETRIZE { move = MOVE_CELEBRATE; }
    PARAMETRIZE { move = MOVE_SANDSTORM; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_SAFETY_GOGGLES); }
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
    enum Move move;
    PARAMETRIZE { move = MOVE_CELEBRATE; }
    PARAMETRIZE { move = MOVE_SANDSTORM; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_SAFETY_GOGGLES); }
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
    enum Move move;
    PARAMETRIZE { move = MOVE_CELEBRATE; }
    PARAMETRIZE { move = MOVE_HAIL; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_SAFETY_GOGGLES); }
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
    enum Move move;
    PARAMETRIZE { move = MOVE_CELEBRATE; }
    PARAMETRIZE { move = MOVE_HAIL; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_SAFETY_GOGGLES); }
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
    enum Move move;
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
    enum Move move;
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
    } THEN {
        EXPECT_EQ(player->statStages[STAT_SPATK], DEFAULT_STAT_STAGE + 1);
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

SINGLE_BATTLE_TEST("Electro Shot does not need a charging turn in Primal Rain")
{
    GIVEN {
        PLAYER(SPECIES_KYOGRE) { Item(ITEM_BLUE_ORB); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_ELECTRO_SHOT); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ELECTRO_SHOT, player);
        HP_BAR(opponent);
    }
}

SINGLE_BATTLE_TEST("Electro Shot still needs a charging turn in Rain with Utility Umbrella")
{
    GIVEN {
        ASSUME(GetItemHoldEffect(ITEM_UTILITY_UMBRELLA) == HOLD_EFFECT_UTILITY_UMBRELLA);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_UTILITY_UMBRELLA); }
        OPPONENT(SPECIES_POLITOED) { Ability(ABILITY_DRIZZLE); }
    } WHEN {
        TURN { MOVE(player, MOVE_ELECTRO_SHOT); MOVE(opponent, MOVE_CELEBRATE); }
        TURN { SKIP_TURN(player); MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
        // Charging turn
        MESSAGE("Wobbuffet absorbed electricity!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
        // Attack turn
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ELECTRO_SHOT, player);
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

SINGLE_BATTLE_TEST("Two Turn moves do not become one turn moves during weather if they don't have the property")
{
    GIVEN {
        PLAYER(SPECIES_POLITOED) { Ability(ABILITY_DRIZZLE); };
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_RAZOR_WIND); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_RAZOR_WIND, player);
        NOT HP_BAR(opponent);
    }
}
